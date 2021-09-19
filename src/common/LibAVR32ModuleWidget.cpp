#include "LibAVR32ModuleWidget.hpp"
#include "LibAVR32Module.hpp"
#include "VirtualGridModule.hpp"
#include "VirtualGridWidget.hpp"

using namespace rack;

struct ConnectGridItem : rack::ui::MenuItem
{
    LibAVR32Module* module;
    Grid* grid;

    void onAction(const rack::event::Action& e) override
    {
        if (module && module->gridConnection == grid)
        {
            GridConnectionManager::get()->disconnect(module);
        }
        else
        {
            GridConnectionManager::get()->connect(grid, module);
        }
    }
};

struct ReloadFirmwareItem : rack::ui::MenuItem
{
    LibAVR32Module* module;
    ReloadRequest requestType;

    void onAction(const rack::event::Action& e) override
    {
        if (module) {
            module->requestReloadFirmware(requestType);
        }
    }
};

struct FirmwareSubmenuItem : MenuItem
{
    LibAVR32Module* module;

    Menu* createChildMenu() override
    {
        LibAVR32Module* m = dynamic_cast<LibAVR32Module*>(module);
        assert(m);

        Menu* menu = new Menu;

        menu->addChild(construct<MenuLabel>(&MenuLabel::text, module->firmwareName));
        menu->addChild(construct<MenuLabel>(&MenuLabel::text, "todo: branch"));
        menu->addChild(construct<MenuLabel>(&MenuLabel::text, "todo: commit hash"));

        auto reloadItem = new ReloadFirmwareItem();
        reloadItem->text = "Reload & Restart";
        reloadItem->module = m;
        reloadItem->requestType = ReloadRequest::ReloadAndRestart;
        menu->addChild(reloadItem);

        auto hotReloadItem = new ReloadFirmwareItem();
        hotReloadItem->text = "Hot Reload";
        hotReloadItem->module = m;
        hotReloadItem->requestType = ReloadRequest::HotReload;
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

    auto firmwareMenu = new FirmwareSubmenuItem();
    firmwareMenu->text = "Firmware";
    firmwareMenu->module = m;
    firmwareMenu->rightText = "▸";
    menu->addChild(firmwareMenu);

    menu->addChild(construct<MenuEntry>());
    menu->addChild(construct<MenuLabel>(&MenuLabel::text, "Device Connection"));

    // enumerate registered grid devices
    int deviceCount = 0;
    for (Grid* grid : GridConnectionManager::get()->getGrids())
    {
        auto connectItem = new ConnectGridItem();
        connectItem->text = grid->getDevice().type + " (" + grid->getDevice().id + ")";
        connectItem->rightText = (m->gridConnection && m->gridConnection->getDevice().id == grid->getDevice().id) ? "✔" : "";
        connectItem->module = m;
        connectItem->grid = grid;
        menu->addChild(connectItem);
        deviceCount++;
    }

    if (deviceCount == 0)
    {
        menu->addChild(construct<MenuLabel>(&MenuLabel::text, "(no physical or virtual devices found)"));
    }
}