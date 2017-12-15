#include "MonomeModuleBase.hpp"
#include "MonomeModuleBaseWidget.hpp"
#include "SerialOscGridConnection.hpp"
#include "VirtualGridConnection.hpp"
#include "VirtualGridWidget.hpp"
#include "VirtualGridModule.hpp"

using namespace rack;

struct MonomeConnectionItem : rack::MenuItem
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

    void onAction(rack::EventAction& e) override
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

Menu* MonomeModuleBaseWidget::createContextMenu()
{
    rack::Menu* menu = ModuleWidget::createContextMenu();

    auto module = static_cast<MonomeModuleBase*>(this->module);

    menu->addChild(construct<MenuEntry>());
    menu->addChild(construct<MenuLabel>(&MenuLabel::text, "Device Connection"));

    // enumerate detected serialosc devices
    int deviceCount = 0;
    for (MonomeDevice* device : module->serialOscDriver->getDevices())
    {
        auto connection = new SerialOscGridConnection(module, device);
        auto* connectionItem = new MonomeConnectionItem();
        connectionItem->text = device->type + " (" + device->id + ")";
        connectionItem->rightText = connectionPtrIsEqual(module->gridConnection, connection) ? "✔" : "";
        connectionItem->module = module;
        connectionItem->connection = connection;
        menu->addChild(connectionItem);
        deviceCount++;
    }

    // enumerate modules
    for (rack::Widget* w : rack::gRackWidget->moduleContainer->children)
    {
        VirtualGridWidget* gridWidget = dynamic_cast<VirtualGridWidget*>(w);
        if (gridWidget)
        {
            auto gridModule = dynamic_cast<VirtualGridModule*>(gridWidget->module);
            auto connection = new VirtualGridConnection(module, gridModule);
            auto* connectionItem = new MonomeConnectionItem();
            connectionItem->text = gridModule->device.type + " (" + gridModule->device.id + ")";
            connectionItem->rightText = connectionPtrIsEqual(module->gridConnection, connection) ? "✔" : "";
            connectionItem->module = module;
            connectionItem->connection = connection;
            menu->addChild(connectionItem);
            deviceCount++;
        }
    }

    if (deviceCount == 0)
    {
        menu->addChild(construct<MenuLabel>(&MenuLabel::text, "(no physical or virtual devices found)"));
    }

    return menu;
}