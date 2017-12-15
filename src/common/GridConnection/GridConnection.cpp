#include "GridConnection.hpp"
#include "monomemodulebase.hpp"

GridConnection::GridConnection(MonomeModuleBase* controlledModule, const MonomeDevice* const d)
    : module(controlledModule)
    , device(d)
{
}