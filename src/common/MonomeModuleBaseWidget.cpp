#include "MonomeModuleBaseWidget.hpp"
#include "MonomeModuleBase.hpp"
#include "VirtualGridModule.hpp"
#include "VirtualGridWidget.hpp"

using namespace rack;

struct ConnectGridItem : rack::ui::MenuItem
{
    MonomeModuleBase* module;
    Grid* grid;

    void onAction(const rack::event::Action& e) override
    {
        if (module->gridConnection == grid)
        {
            GridConnectionManager::get()->disconnect(module);
        }
        else
        {
            GridConnectionManager::get()->connect(grid, module);
        }
    }
};

MonomeModuleBaseWidget::MonomeModuleBaseWidget()
{
}

void MonomeModuleBaseWidget::appendContextMenu(rack::Menu* menu)
{

    MonomeModuleBase* m = dynamic_cast<MonomeModuleBase*>(module);
    assert(m);

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