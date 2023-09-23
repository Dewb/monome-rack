#include "LibAVR32ModuleWidget.hpp"
#include "LibAVR32Module.hpp"
#include "GridConnectionMenu.hpp"
#include "VirtualGridModule.hpp"
#include "VirtualGridWidget.hpp"
#include "SerialOscInterface.hpp"
#include "Screenshot.hpp"

#include <ghc/filesystem.hpp>

namespace fs = ghc::filesystem;

using namespace rack;


struct ReloadFirmwareItem : rack::ui::MenuItem
{
    LibAVR32Module* module;
    bool preserveVRAM;
    bool preserveNVRAM;

    void onAction(const rack::event::Action& e) override
    {
        if (module) {
            module->requestReloadFirmware(preserveVRAM, preserveNVRAM);
        }
    }
};

struct SwitchFirmwareItem : rack::ui::MenuItem
{
    LibAVR32Module* module;

    ui::Menu* createChildMenu() override
    {
        // duplicate filenames that may be left in res folder by prior versions
        std::vector<std::string> ignoreList = {"teletype", "ansible 2", "earthsea 2", "meadowphysics 2", "teletype 2", "whitewhale 2"};
        std::vector<std::string> fwNames = {};

        const fs::path fwPath{rack::asset::plugin(pluginInstance, "res/firmware")};
        for (auto const& file : fs::directory_iterator{fwPath})
        {
            auto name = file.path().stem().string();
            auto extension = file.path().extension().string();
            if (extension == module->firmware.getLibExtension() &&
                name.substr(0, module->firmwarePrefix.size()) == module->firmwarePrefix &&
                std::find(std::begin(ignoreList), std::end(ignoreList), name) == std::end(ignoreList))
            {
                fwNames.push_back(name);
            }
        }

        bool currentMissing = false;
        if (std::find(std::begin(fwNames), std::end(fwNames), module->firmwareName) == std::end(fwNames))
        {
            fwNames.push_back(module->firmwareName);
            currentMissing = true;
        }

        ui::Menu* menu = new ui::Menu;

        for (auto const& name : fwNames)
        {
            menu->addChild(createCheckMenuItem(
                name,
                (currentMissing && (module->firmwareName == name)) ? "(missing)" : "",
                [=]()
                { return module->firmwareName == name; },
                [=]()
                { module->requestReloadFirmware(false, false, name); }
            ));
        }

        return menu;
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

        menu->addChild(construct<SwitchFirmwareItem>(
            &MenuItem::text, "Switch Firmware", &MenuItem::rightText, RIGHT_ARROW,
            &SwitchFirmwareItem::module, m
        ));

        auto hotReloadItem = new ReloadFirmwareItem();
        hotReloadItem->text = "Hot Reload";
        hotReloadItem->module = m;
        hotReloadItem->preserveVRAM = true;
        hotReloadItem->preserveNVRAM = true;
        menu->addChild(hotReloadItem);

        auto reloadItem = new ReloadFirmwareItem();
        reloadItem->text = "Reload & Restart";
        reloadItem->module = m;
        reloadItem->preserveVRAM = false;
        reloadItem->preserveNVRAM = true;
        menu->addChild(reloadItem);

        auto clearItem = new ReloadFirmwareItem();
        clearItem->text = "Clear NVRAM";
        clearItem->module = m;
        clearItem->preserveVRAM = true;
        clearItem->preserveNVRAM = false;
        menu->addChild(clearItem);

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
    appendDeviceConnectionMenu(menu, m, &m->audioThreadActions);
}
