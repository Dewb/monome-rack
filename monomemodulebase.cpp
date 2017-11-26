#include "monomemodulebase.hpp"
#include "grid.hpp"
#include "virtual_gpio.h"


GridConnection::GridConnection(MonomeModuleBase* controlledModule)
{
    module = controlledModule;
}

RackGridConnection::RackGridConnection(MonomeModuleBase* controlledModule, Grid<16, 8> *gridModule)
: GridConnection(controlledModule)
{
    grid = gridModule;
}

void RackGridConnection::connect()
{
    grid->connectedModule = module;
}

void RackGridConnection::disconnect()
{
    grid->connectedModule = NULL;
}

void RackGridConnection::processInput()
{
}

void RackGridConnection::updateQuadrant(int x, int y, uint8_t *leds)
{
    grid->updateQuadrant(x, y, leds);
}

bool RackGridConnection::operator==(const RackGridConnection &other) const
{
    return (this->grid == other.grid && this->module == other.module);
}

SerialOscGridConnection::SerialOscGridConnection(MonomeModuleBase *controlledModule, MonomeDevice *device)
: GridConnection(controlledModule)
{
    grid = device;
}

void SerialOscGridConnection::connect()
{
}

void SerialOscGridConnection::disconnect()
{
    module->serialOscDriver->sendDeviceLedAllCommand(grid, false);
}

void SerialOscGridConnection::processInput()
{
}

void SerialOscGridConnection::updateQuadrant(int x, int y, uint8_t *leds)
{
    module->serialOscDriver->sendDeviceLedLevelMapCommand(grid, x, y, leds);
}

bool SerialOscGridConnection::operator==(const SerialOscGridConnection &other) const
{
    return (this->grid == other.grid && this->module == other.module);
}

MonomeModuleBase::MonomeModuleBase(int numParams, int numInputs, int numOutputs, int numLights)
: Module(numParams, numInputs, numOutputs, numLights)
{
    gridConnection = NULL;
    serialOscDriver = new SerialOsc("rack", 13000);
    serialOscDriver->start(this);
}

MonomeModuleBase::~MonomeModuleBase()
{
    delete gridConnection;
}

void MonomeModuleBase::setGridConnection(GridConnection *newConnection)
{
    if (gridConnection)
    {
        gridConnection->disconnect();
        delete gridConnection;
    }

    gridConnection = newConnection;
    gridConnection->connect();

    simulate_monome_connect();
}

void MonomeModuleBase::deviceRemoved(const std::string &id)
{

}

void MonomeModuleBase::buttonPressMessageReceived(MonomeDevice *device, int x, int y, bool state)
{
    simulate_monome_key(x, y, state);
}

struct MonomeConnectionItem : MenuItem
{
    MonomeModuleBase *module;
    GridConnection *connection;

    ~MonomeConnectionItem()
    {
        if (connection)
        {
            delete connection;
        }
    }

    void onAction(EventAction &e) override
    {
        module->setGridConnection(connection);
        connection = NULL;
    }
};

template<typename C>
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


Menu *MonomeModuleBaseWidget::createContextMenu()
{
    Menu *menu = ModuleWidget::createContextMenu();

    auto module = static_cast<MonomeModuleBase *>(this->module);

    menu->addChild(construct<MenuEntry>());
    menu->addChild(construct<MenuLabel>(&MenuLabel::text, "Physical Grids"));

    int physicalGridCount = 0;
    for (MonomeDevice *device : module->serialOscDriver->getDevices())
    {   
        auto connection = new SerialOscGridConnection(module, device);
        auto *connectionItem = new MonomeConnectionItem();
        connectionItem->text = device->id;
        connectionItem->rightText = connectionPtrIsEqual(module->gridConnection, connection) ? "✔" : "";
        connectionItem->module = module;
        connectionItem->connection = connection;
        menu->addChild(connectionItem);
        physicalGridCount++;
    }

    if (physicalGridCount == 0)
    {
        menu->addChild(construct<MenuLabel>(&MenuLabel::text, "(no devices connected)"));
    }

    menu->addChild(construct<MenuLabel>(&MenuLabel::text, "Virtual Grids"));

    // enumerate modules
    int virtualGridCount = 0;
    for (Widget *w : gRackWidget->moduleContainer->children)
    {
        Grid128Widget *gridWidget = dynamic_cast<Grid128Widget *>(w);
        if (gridWidget)
        {
            auto connection = new RackGridConnection(module, dynamic_cast<Grid<16, 8> *>(gridWidget->module));
            auto *connectionItem = new MonomeConnectionItem();
            connectionItem->text = "    Virtual Grid " + std::to_string(virtualGridCount);
            connectionItem->rightText = connectionPtrIsEqual(module->gridConnection, connection) ? "✔" : "";
            connectionItem->module = module;
            connectionItem->connection = connection;
            menu->addChild(connectionItem);
            virtualGridCount++;
        }
    }

    if (virtualGridCount == 0)
    {
        menu->addChild(construct<MenuLabel>(&MenuLabel::text, "(no virtual grids in rack)"));
    }

    return menu;
}