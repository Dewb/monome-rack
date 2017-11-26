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


void SerialOSCGridConnection::connect()
{
}

void SerialOSCGridConnection::disconnect()
{
}

void SerialOSCGridConnection::processInput()
{
}

void SerialOSCGridConnection::updateQuadrant(int x, int y, uint8_t *leds)
{
}

MonomeModuleBase::MonomeModuleBase(int numParams, int numInputs, int numOutputs, int numLights)
: Module(numParams, numInputs, numOutputs, numLights)
{
    gridConnection = NULL;
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