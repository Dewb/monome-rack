#include "monomemodulebase.hpp"
#include "grid.hpp"
#include "virtual_gpio.h"


GridConnection::GridConnection(MonomeModuleBase* controlledModule, const MonomeDevice const* d)
: module(controlledModule)
, device(d)
{
}

RackGridConnection::RackGridConnection(MonomeModuleBase* controlledModule, MonomeGrid *gridModule)
: GridConnection(controlledModule, &gridModule->device)
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

SerialOscGridConnection::SerialOscGridConnection(MonomeModuleBase* module, const MonomeDevice* const device)
: GridConnection(module, device)
{
} 

void SerialOscGridConnection::connect()
{
}

void SerialOscGridConnection::disconnect()
{
    module->serialOscDriver->sendDeviceLedAllCommand(device, false);
}

void SerialOscGridConnection::processInput()
{
}

void SerialOscGridConnection::updateQuadrant(int x, int y, uint8_t *leds)
{
    module->serialOscDriver->sendDeviceLedLevelMapCommand(device, x, y, leds);
}

bool SerialOscGridConnection::operator==(const SerialOscGridConnection &other) const
{
    return (this->device == other.device && this->module == other.module);
}

MonomeModuleBase::MonomeModuleBase(int numParams, int numInputs, int numOutputs, int numLights)
: Module(numParams, numInputs, numOutputs, numLights)
{
    gridConnection = NULL;
    serialOscDriver = new SerialOsc("rack", 13000);
    serialOscDriver->start(this);
    firstStep = true;
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
    unresolvedConnectionId = "";

    simulate_monome_connect();
}

void MonomeModuleBase::deviceFound(const MonomeDevice *const device)
{
    if (!gridConnection && device->id == unresolvedConnectionId)
    {
        setGridConnection(new SerialOscGridConnection(this, device));
    }
}

void MonomeModuleBase::deviceRemoved(const std::string &id)
{
    if (gridConnection && gridConnection->device->id == id)
    {
        unresolvedConnectionId = id;
        delete gridConnection;
    }
}

void MonomeModuleBase::buttonPressMessageReceived(MonomeDevice *device, int x, int y, bool state)
{
    simulate_monome_key(x, y, state);
}

void MonomeModuleBase::step()
{
    if (firstStep)
    {
        firstStep = false;

        // Resolve connections from JSON after the entire rack has been deserialized
        if (unresolvedConnectionId != "")
        {
            // enumerate detected serialosc devices
            for (MonomeDevice *device : serialOscDriver->getDevices())
            {
                if (device->id == unresolvedConnectionId)
                {
                    auto connection = new SerialOscGridConnection(this, device);
                    setGridConnection(connection);
                    return;
                }
            }

            // enumerate modules
            for (Widget *w : gRackWidget->moduleContainer->children)
            {
                MonomeGridWidget *gridWidget = dynamic_cast<MonomeGridWidget *>(w);
                if (gridWidget)
                {
                    auto gridModule = dynamic_cast<MonomeGrid *>(gridWidget->module);
                    if (gridModule->device.id == unresolvedConnectionId)
                    {
                        auto connection = new RackGridConnection(this, gridModule);
                        setGridConnection(connection);
                        return;
                    }
                }
            }
        }
    }
}

json_t *MonomeModuleBase::toJson()
{
    std::string deviceId = unresolvedConnectionId;
    if (gridConnection)
    {
        deviceId = gridConnection->device->id;
    }

    json_t *rootJ = json_object();
    json_object_set_new(rootJ, "connectedDeviceId", json_string(deviceId.c_str()));

    return rootJ;
}

void MonomeModuleBase::fromJson(json_t *rootJ)
{
    delete gridConnection;

    json_t *id = json_object_get(rootJ, "connectedDeviceId");
    if (id) 
    {
        unresolvedConnectionId = json_string_value(id);
    }
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

template <typename C>
bool connectionPtrIsEqual(GridConnection * genericPtr, C * specificPtr)
{
    C *castPtr = static_cast<C *>(genericPtr);
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
    menu->addChild(construct<MenuLabel>(&MenuLabel::text, "Device Connection"));

    // enumerate detected serialosc devices
    int deviceCount = 0;
    for (MonomeDevice *device : module->serialOscDriver->getDevices())
    {
        auto connection = new SerialOscGridConnection(module, device);
        auto *connectionItem = new MonomeConnectionItem();
        connectionItem->text = device->type + " (" + device->id + ")";
        connectionItem->rightText = connectionPtrIsEqual(module->gridConnection, connection) ? "✔" : "";
        connectionItem->module = module;
        connectionItem->connection = connection;
        menu->addChild(connectionItem);
        deviceCount++;
    }

    // enumerate modules
    for (Widget *w : gRackWidget->moduleContainer->children)
    {
        MonomeGridWidget *gridWidget = dynamic_cast<MonomeGridWidget *>(w);
        if (gridWidget)
        {
            auto gridModule = dynamic_cast<MonomeGrid*>(gridWidget->module);
            auto connection = new RackGridConnection(module, gridModule);
            auto *connectionItem = new MonomeConnectionItem();
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