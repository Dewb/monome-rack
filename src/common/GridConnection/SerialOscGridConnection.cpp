#include "SerialOscGridConnection.hpp"
#include "MonomeModuleBase.hpp"
#include "VirtualGridModule.hpp"

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

void SerialOscGridConnection::updateRow(int x_offset, int y, uint8_t bitfield)
{
    module->serialOscDriver->sendDeviceLedRowCommand(device, x_offset, y, bitfield);
}

void SerialOscGridConnection::updateQuadrant(int x, int y, uint8_t* leds)
{
    if (device->protocol == PROTOCOL_40H)
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
            module->serialOscDriver->sendDeviceLedRowCommand(device, 0, i, bits);
        }
    }
    else if (device->protocol == PROTOCOL_SERIES)
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
        module->serialOscDriver->sendDeviceLedMapCommand(device, x, y, map);
    }
    else
    {
        module->serialOscDriver->sendDeviceLedLevelMapCommand(device, x, y, leds);
    }
}

void SerialOscGridConnection::clearAll()
{
    module->serialOscDriver->sendDeviceLedAllCommand(device, false);
}

bool SerialOscGridConnection::operator==(const SerialOscGridConnection& other) const
{
    return (this->device == other.device && this->module == other.module);
}