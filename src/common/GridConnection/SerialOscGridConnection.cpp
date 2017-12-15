#include "MonomeModuleBase.hpp"
#include "SerialOscGridConnection.hpp"
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