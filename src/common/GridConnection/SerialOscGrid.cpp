#include "SerialOscGrid.hpp"
#include "SerialOscInterface.hpp"

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
    SerialOscInterface::get()->driver->sendDeviceLedRowCommand(&device, x_offset, y, bitfield);
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
            SerialOscInterface::get()->driver->sendDeviceLedRowCommand(&device, 0, i, bits);
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
        SerialOscInterface::get()->driver->sendDeviceLedMapCommand(&device, x, y, map);
    }
    else
    {
        SerialOscInterface::get()->driver->sendDeviceLedLevelMapCommand(&device, x, y, leds);
    }
}

void SerialOscGrid::updateRing(int n, uint8_t leds[64])
{
    SerialOscInterface::get()->driver->sendDeviceRingMapCommand(&device, n, leds);
}

void SerialOscGrid::clearAll()
{
    SerialOscInterface::get()->driver->sendDeviceLedAllCommand(&device, false);
}
