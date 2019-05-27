#include "MonomeModuleBaseWidget.hpp"
#include "MonomeModuleBase.hpp"
#include "SerialOscGridConnection.hpp"
#include "VirtualGridConnection.hpp"
#include "VirtualGridModule.hpp"
#include "VirtualGridWidget.hpp"

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

struct UrlItem : rack::ui::MenuItem
{
    std::string url;
    void onAction(const rack::event::Action& e) override
    {
        //std::thread t(rack::systemOpenBrowser, url);
        //t.detach();
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

MonomeModuleBaseWidget::MonomeModuleBaseWidget(MonomeModuleBase* module)
    : ModuleWidget(module)
{
}

void MonomeModuleBaseWidget::appendContextMenu(rack::Menu* menu)
{
    /*
    MonomeModuleBase* m = dynamic_cast<MonomeModuleBase*>(module);
    assert(m);
    
    auto helpItem = new UrlItem();
    helpItem->url = "https://github.com/Dewb/monome-rack/blob/master/README.md";
    helpItem->text = "Help";
    menu->addChild(helpItem);

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
*/
}