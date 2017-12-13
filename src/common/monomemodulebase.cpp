#include "monomemodulebase.hpp"
#include "base64.h"
#include "grid.hpp"

GridConnection::GridConnection(MonomeModuleBase* controlledModule, const MonomeDevice* const d)
    : module(controlledModule)
    , device(d)
{
}

RackGridConnection::RackGridConnection(MonomeModuleBase* controlledModule, MonomeGrid* gridModule)
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

void RackGridConnection::updateQuadrant(int x, int y, uint8_t* leds)
{
    grid->updateQuadrant(x, y, leds);
}

void RackGridConnection::clearAll()
{
    grid->clearAll();
}

bool RackGridConnection::operator==(const RackGridConnection& other) const
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

void SerialOscGridConnection::updateQuadrant(int x, int y, uint8_t* leds)
{
    module->serialOscDriver->sendDeviceLedLevelMapCommand(device, x, y, leds);
}

void SerialOscGridConnection::clearAll()
{
    module->serialOscDriver->sendDeviceLedAllCommand(device, false);
}

bool SerialOscGridConnection::operator==(const SerialOscGridConnection& other) const
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

void MonomeModuleBase::setGridConnection(GridConnection* newConnection)
{
    if (gridConnection)
    {
        gridConnection->clearAll();
        gridConnection->disconnect();
        delete gridConnection;
    }

    gridConnection = newConnection;

    if (gridConnection)
    {
        gridConnection->connect();
        unresolvedConnectionId = "";

        string id = gridConnection->device->id;
        string wide_id;
        for (int i = 0; i < id.length(); i++)
        {
            if (i == 1 && id[1] == 'v')
                i++;

            wide_id.append(id, i, 1);
            wide_id.append(" ");
        }

        firmware.serialConnectionChange(FTDI_BUS, 1, "m o n o m e", "p r o d u c t", wide_id.c_str());

        uint8_t buf[6] = { 0, 1, 0, 0, 0, 0 };
        buf[2] = (gridConnection->device->width * gridConnection->device->height) / 64;
        firmware.writeSerial(FTDI_BUS, buf, 6);
        uint8_t buf2[2] = { 0, 0 };
        firmware.writeSerial(FTDI_BUS, buf2, 2);
    }
    else
    {
        firmware.serialConnectionChange(FTDI_BUS, 0, NULL, NULL, NULL);
    }
}

void MonomeModuleBase::deviceFound(const MonomeDevice* const device)
{
    if (!gridConnection && device->id == unresolvedConnectionId)
    {
        setGridConnection(new SerialOscGridConnection(this, device));
    }
}

void MonomeModuleBase::deviceRemoved(const std::string& id)
{
    if (gridConnection && gridConnection->device->id == id)
    {
        unresolvedConnectionId = id;
        delete gridConnection;
    }
}

void MonomeModuleBase::buttonPressMessageReceived(MonomeDevice* device, int x, int y, bool state)
{
    uint8_t msg[4] = { 0xF0, 0, 0, 0 };
    msg[1] = (uint8_t)x;
    msg[2] = (uint8_t)y;
    msg[3] = state ? 1 : 0;
    firmware.writeSerial(FTDI_BUS, msg, 4);
}

void MonomeModuleBase::readSerialMessages()
{
    uint8_t* msg;
    uint32_t count;
    firmware.readSerial(FTDI_BUS, &msg, &count);
    while (msg)
    {
        if (msg[0] == 0x1A && count >= 35)
        {
            // mext protocol quadrant update
            uint8_t x = msg[1];
            uint8_t y = msg[2];
            uint8_t leds[64];
            for (int i = 0; i < 32; i++)
            {
                leds[2 * i + 0] = msg[3 + i] >> 4;
                leds[2 * i + 1] = msg[3 + i] & 0xF;
            }

            if (gridConnection)
            {
                gridConnection->updateQuadrant(x, y, leds);
            }
        }
        else if ((msg[0] & 0x80) == 0x80 && count >= 9)
        {
            // series protocol quadrant update
            int x = (msg[0] & 0x1) * 8;
            int y = (msg[0] & 0x2) * 8;
            uint8_t leds[64];
            for (int j = 0; j < 8; j++)
            {
                for (int i = 0; i < 8; i++)
                {
                    leds[i + 8 * j] = (msg[1 + j] & (0x1 << i)) ? 15 : 0;
                }
            }

            if (gridConnection)
            {
                gridConnection->updateQuadrant(x, y, leds);
            }
        }
        else if (msg[0] == 0x01)
        {
            // device info request
            // ignore, we stuffed the response in the message queue in advance
        }
        firmware.readSerial(FTDI_BUS, &msg, &count);
    }
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
            for (MonomeDevice* device : serialOscDriver->getDevices())
            {
                if (device->id == unresolvedConnectionId)
                {
                    auto connection = new SerialOscGridConnection(this, device);
                    setGridConnection(connection);
                    return;
                }
            }

            // enumerate modules
            for (Widget* w : gRackWidget->moduleContainer->children)
            {
                MonomeGridWidget* gridWidget = dynamic_cast<MonomeGridWidget*>(w);
                if (gridWidget)
                {
                    auto gridModule = dynamic_cast<MonomeGrid*>(gridWidget->module);
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

json_t* MonomeModuleBase::toJson()
{
    std::string deviceId = unresolvedConnectionId;
    if (gridConnection)
    {
        deviceId = gridConnection->device->id;
    }

    json_t* rootJ = json_object();
    json_object_set_new(rootJ, "connectedDeviceId", json_string(deviceId.c_str()));

    void* data;
    uint32_t size;

    firmware.readNVRAM(&data, &size);
    json_object_set_new(rootJ, "nvram", json_string(base64_encode((unsigned char*)data, size).c_str()));

    firmware.readVRAM(&data, &size);
    json_object_set_new(rootJ, "vram", json_string(base64_encode((unsigned char*)data, size).c_str()));

    return rootJ;
}

void MonomeModuleBase::fromJson(json_t* rootJ)
{
    delete gridConnection;

    json_t* id = json_object_get(rootJ, "connectedDeviceId");
    if (id)
    {
        unresolvedConnectionId = json_string_value(id);
    }

    void* data;
    uint32_t size;
    json_t* jd;

    jd = json_object_get(rootJ, "nvram");
    if (jd)
    {
        string decoded = base64_decode(json_string_value(jd));

        firmware.readNVRAM(&data, &size);
        if (size == decoded.length())
        {
            firmware.writeNVRAM((void*)decoded.c_str(), size);
        }
    }

    jd = json_object_get(rootJ, "vram");
    if (jd)
    {
        string decoded = base64_decode(json_string_value(jd));

        firmware.readVRAM(&data, &size);
        if (size == decoded.length())
        {
            firmware.writeVRAM((void*)decoded.c_str(), size);
        }
    }
}

struct MonomeConnectionItem : MenuItem
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

    void onAction(EventAction& e) override
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

Menu* MonomeModuleBaseWidget::createContextMenu()
{
    Menu* menu = ModuleWidget::createContextMenu();

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
    for (Widget* w : gRackWidget->moduleContainer->children)
    {
        MonomeGridWidget* gridWidget = dynamic_cast<MonomeGridWidget*>(w);
        if (gridWidget)
        {
            auto gridModule = dynamic_cast<MonomeGrid*>(gridWidget->module);
            auto connection = new RackGridConnection(module, gridModule);
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