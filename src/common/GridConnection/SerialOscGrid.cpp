#include "SerialOscGrid.hpp"
#include "MonomeModuleBase.hpp"
#include "SerialOsc.h"

struct SerialOscInterface : public SerialOsc::Listener
{
    SerialOscInterface()
    {
        driver = new SerialOsc("rack", 13000);
        driver->start(this);
    }

    ~SerialOscInterface()
    {
        driver->stop();
        delete driver;
    }

    // SerialOsc::Listener methods
    void deviceFound(const MonomeDevice* const device) override
    {
        GridConnectionManager::get()->registerGrid(new SerialOscGrid(device));
    }

    void deviceRemoved(const std::string& id) override
    {
        GridConnectionManager::get()->deregisterGrid(id, true);
    }
    void buttonPressMessageReceived(MonomeDevice* device, int x, int y, bool state) override
    {
        GridConnectionManager::get()->dispatchButtonMessage(device, x, y, state);
    }

    SerialOsc* driver;
};

SerialOscInterface gSerialOscInterface;

SerialOscGrid::SerialOscGrid(const MonomeDevice* const _device)
    : device(*_device)
{
}

const MonomeDevice& SerialOscGrid::getDevice()
{
    return device;
}

void SerialOscGrid::updateRow(int x_offset, int y, uint8_t bitfield)
{
    gSerialOscInterface.driver->sendDeviceLedRowCommand(&device, x_offset, y, bitfield);
}

void SerialOscGrid::updateQuadrant(int x, int y, uint8_t* leds)
{
    if (device.protocol == PROTOCOL_40H)
    {
        uint8_t* p = leds;
        for (int i = 0; i < 8; i++)
        {
            uint8_t bits = 0;
            for (int j = 0; j < 8; j++)
            {
                if (*p++)
                {
                    bits |= 1 << j;
                }
            }
            gSerialOscInterface.driver->sendDeviceLedRowCommand(&device, 0, i, bits);
        }
    }
    else if (device.protocol == PROTOCOL_SERIES)
    {
        uint8_t* p = leds;
        uint8_t map[8] = { 0, 0, 0, 0, 0, 0, 0, 0 };
        for (int i = 0; i < 8; i++)
        {
            for (int j = 0; j < 8; j++)
            {
                if (*p++)
                {
                    map[i] |= 1 << j;
                }
            }
        }
        gSerialOscInterface.driver->sendDeviceLedMapCommand(&device, x, y, map);
    }
    else
    {
        gSerialOscInterface.driver->sendDeviceLedLevelMapCommand(&device, x, y, leds);
    }
}

void SerialOscGrid::clearAll()
{
    gSerialOscInterface.driver->sendDeviceLedAllCommand(&device, false);
}
