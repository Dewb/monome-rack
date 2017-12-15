#include "VirtualGridConnection.hpp"
#include "monomemodulebase.hpp"
#include "grid.hpp"

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