#include "LibAVR32ModuleWidget.hpp"
#include "LibAVR32Module.hpp"
#include "VirtualGridModule.hpp"
#include "VirtualGridWidget.hpp"
#include "SerialOscInterface.hpp"
#include "Screenshot.hpp"

using namespace rack;

struct ConnectGridItem : rack::ui::MenuItem
{
    LibAVR32Module* module;
    Grid* grid;

    void onAction(const rack::event::Action& e) override
    {
        module->userToggleGridConnection(grid);
    }
};

struct ReloadFirmwareItem : rack::ui::MenuItem
{
    LibAVR32Module* module;
    bool preserveMemory;

    void onAction(const rack::event::Action& e) override
    {
        if (module) {
            module->requestReloadFirmware(preserveMemory);
        }
    }
};

struct ioRateItem : rack::ui::MenuItem
{
    int* target = nullptr;
    int defaultValue = 0;

    ui::Menu* createChildMenu() override
    {
        ui::Menu* menu = new ui::Menu;

        std::string names[] = { "1x", "/2", "/4", "/8", "/16" };
        std::string right[] = { "(audio rate)", "", "", "", "(lowest CPU)" };

        for (int i = 0; i < 5; i++)
        {
            int value = 1 << i;
            menu->addChild(createCheckMenuItem(
                names[i],
                (value == defaultValue) ? "(default)" : right[i],
                [=]()
                { return *target == value; },
                [=]()
                { *target = value; }));
        }

        return menu;
    }
};

struct FirmwareSubmenuItem : MenuItem
{
    LibAVR32Module* module;
    LibAVR32ModuleWidget* widget;

    Menu* createChildMenu() override
    {
        LibAVR32Module* m = dynamic_cast<LibAVR32Module*>(module);
        assert(m);

        Menu* menu = new Menu;

        char versionbuf[512];
        module->firmware.getVersion(versionbuf);
        menu->addChild(construct<MenuLabel>(&MenuLabel::text, module->firmwareName));
        menu->addChild(construct<MenuLabel>(&MenuLabel::text, versionbuf));

        menu->addChild(construct<ioRateItem>(
            &MenuItem::text, "Input rate", &MenuItem::rightText, RIGHT_ARROW,
            &ioRateItem::defaultValue, 2, &ioRateItem::target, &m->inputRate));

        menu->addChild(construct<ioRateItem>(
            &MenuItem::text, "Output rate", &MenuItem::rightText, RIGHT_ARROW,
            &ioRateItem::defaultValue, 4, &ioRateItem::target, &m->outputRate));

        menu->addChild(new MenuSeparator());

        menu->addChild(createMenuItem("Save PNG screenshot", "", [this]()
            { screenshotModulePNG(widget, widget->model->slug + "-screenshot.png"); }));

        menu->addChild(new MenuSeparator());

        auto reloadItem = new ReloadFirmwareItem();
        reloadItem->text = "Reload & Restart";
        reloadItem->module = m;
        reloadItem->preserveMemory = false;
        menu->addChild(reloadItem);

        auto hotReloadItem = new ReloadFirmwareItem();
        hotReloadItem->text = "Hot Reload";
        hotReloadItem->module = m;
        hotReloadItem->preserveMemory = true;
        menu->addChild(hotReloadItem);

        return menu;
    }
};

LibAVR32ModuleWidget::LibAVR32ModuleWidget()
{
}

void LibAVR32ModuleWidget::appendContextMenu(rack::Menu* menu)
{
    LibAVR32Module* m = dynamic_cast<LibAVR32Module*>(module);
    assert(m);

    menu->addChild(new MenuSeparator());

    auto firmwareMenu = new FirmwareSubmenuItem();
    firmwareMenu->text = "Firmware Tools";
    firmwareMenu->module = m;
    firmwareMenu->widget = this;
    firmwareMenu->rightText = "▸";
    menu->addChild(firmwareMenu);

    menu->addChild(new MenuSeparator());
    appendConnectionMenu(menu);
}

void LibAVR32ModuleWidget::appendConnectionMenu(rack::Menu* menu)
{
    LibAVR32Module* m = dynamic_cast<LibAVR32Module*>(module);
    assert(m);

    menu->addChild(construct<MenuLabel>(&MenuLabel::text, "Device Connection"));

    if (SerialOscInterface::get()->isServiceDetected())
    {
        menu->addChild(
            construct<MenuLabel>(
                &MenuLabel::text,
                "serialosc version " + SerialOscInterface::get()->getServiceVersion()));
    }
    else
    {
        menu->addChild(
            createMenuItem("└ serialosc service not detected, click here to install", "",
                [=]()
                {
                    system::openBrowser("https://monome.org/docs/serialosc/setup/");
                }));
    }

    // enumerate registered grid devices
    int deviceCount = 0;
    bool preferredDeviceFound = false;
    for (Grid* grid : GridConnectionManager::get().getGrids())
    {
        auto connectItem = new ConnectGridItem();
        connectItem->text = "└ " + grid->getDevice().type + " (" + grid->getDevice().id + ") ";

        auto rightText = "";
        if (m->currentConnectedDeviceId == grid->getDevice().id)
        {
            rightText = "✔";
            preferredDeviceFound = true;
        }
        else if (m->currentConnectedDeviceId == "" && m->gridGetLastDeviceId(false) == grid->getDevice().id)
        {
            rightText = "⋯";
            preferredDeviceFound = true;
        }

        connectItem->rightText = rightText;
        connectItem->module = m;
        connectItem->grid = grid;
        menu->addChild(connectItem);
        deviceCount++;
    }

    if (deviceCount == 0)
    {
        menu->addChild(construct<MenuLabel>(&MenuLabel::text, "  (no physical or virtual devices found)"));
    }

    if (m->currentConnectedDeviceId == "" && m->gridGetLastDeviceId(false) != "")
    {
        if (preferredDeviceFound)
        {
            menu->addChild(createMenuItem("Reacquire grid", "", [=]() { m->userReacquireGrid(); }));
        }
        else
        {
            menu->addChild(construct<MenuLabel>(&MenuLabel::text, "Can't reacquire grid (" + m->gridGetLastDeviceId(false) + " not found)"));
        }
    }

}
