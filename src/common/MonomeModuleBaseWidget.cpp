#include "MonomeModuleBaseWidget.hpp"
#include "MonomeModuleBase.hpp"
#include "SerialOscGridConnection.hpp"
#include "VirtualGridConnection.hpp"
#include "VirtualGridModule.hpp"
#include "VirtualGridWidget.hpp"

using namespace rack;

struct MonomeConnectionItem : rack::ui::MenuItem
{
    MonomeModuleBase* module;
    GridConnection* connection;

    ~MonomeConnectionItem()
    {
        if (connection)
        {
            delete connection;
        }
    }

    void onAction(const rack::event::Action& e) override
    {
        module->setGridConnection(connection);
        connection = NULL;
    }
};

template <typename C>
bool connectionPtrIsEqual(GridConnection* genericPtr, C* specificPtr)
{
    C* castPtr = static_cast<C*>(genericPtr);
    if (castPtr == NULL || specificPtr == NULL)
    {
        return false;
    }
    else
    {
        return *castPtr == *specificPtr;
    }
}

MonomeModuleBaseWidget::MonomeModuleBaseWidget()
{
}

void MonomeModuleBaseWidget::appendContextMenu(rack::Menu* menu)
{

    MonomeModuleBase* m = dynamic_cast<MonomeModuleBase*>(module);
    assert(m);

    menu->addChild(construct<MenuEntry>());
    menu->addChild(construct<MenuLabel>(&MenuLabel::text, "Device Connection"));

    // enumerate detected serialosc devices
    int deviceCount = 0;
    for (MonomeDevice* device : m->serialOscDriver->getDevices())
    {
        auto connection = new SerialOscGridConnection(m, device);
        auto* connectionItem = new MonomeConnectionItem();
        connectionItem->text = device->type + " (" + device->id + ")";
        connectionItem->rightText = connectionPtrIsEqual(m->gridConnection, connection) ? "✔" : "";
        connectionItem->module = m;
        connectionItem->connection = connection;
        menu->addChild(connectionItem);
        deviceCount++;
    }

    // enumerate modules
    for (rack::Widget* w : rack::APP->scene->rack->moduleContainer->children)
    {
        VirtualGridWidget* gridWidget = dynamic_cast<VirtualGridWidget*>(w);
        if (gridWidget)
        {
            auto gridModule = dynamic_cast<VirtualGridModule*>(gridWidget->module);
            auto connection = new VirtualGridConnection(m, gridModule);
            auto* connectionItem = new MonomeConnectionItem();
            connectionItem->text = gridModule->device.type + " (" + gridModule->device.id + ")";
            connectionItem->rightText = false ? "✔" : "";
            connectionItem->module = m;
            connectionItem->connection = connection;
            menu->addChild(connectionItem);
            deviceCount++;
        }
    }

    if (deviceCount == 0)
    {
        menu->addChild(construct<MenuLabel>(&MenuLabel::text, "(no physical or virtual devices found)"));
    }
}