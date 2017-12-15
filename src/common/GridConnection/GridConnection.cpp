#include "GridConnection.hpp"
#include "MonomeModuleBase.hpp"

GridConnection::GridConnection(MonomeModuleBase* controlledModule, const MonomeDevice* const d)
    : module(controlledModule)
    , device(d)
{
}