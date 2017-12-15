#include "VirtualGridConnection.hpp"
#include "MonomeModuleBase.hpp"
#include "VirtualGridModule.hpp"

VirtualGridConnection::VirtualGridConnection(MonomeModuleBase* controlledModule, VirtualGridModule* gridModule)
    : GridConnection(controlledModule, &gridModule->device)
{
    grid = gridModule;
}

void VirtualGridConnection::connect()
{
    grid->connectedModule = module;
}

void VirtualGridConnection::disconnect()
{
    grid->connectedModule = NULL;
}

void VirtualGridConnection::processInput()
{
}

void VirtualGridConnection::updateQuadrant(int x, int y, uint8_t* leds)
{
    grid->updateQuadrant(x, y, leds);
}

void VirtualGridConnection::clearAll()
{
    grid->clearAll();
}

bool VirtualGridConnection::operator==(const VirtualGridConnection& other) const
{
    return (this->grid == other.grid && this->module == other.module);
}