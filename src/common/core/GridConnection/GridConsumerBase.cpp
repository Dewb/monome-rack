#include "GridConsumerBase.hpp"

GridConsumerBase::GridConsumerBase()
    : lastConnectedDeviceId("")
    , currentConnectedDeviceId("")
    , gridConnection(nullptr)
{

}

void GridConsumerBase::gridConnected(Grid* newConnection)
{
    gridConnection = newConnection;
    if (gridConnection)
    {
        std::string id = gridConnection->getDevice().id;
        lastConnectedDeviceId = id;
        currentConnectedDeviceId = id;
        connectionOwned = true;
    }
}

void GridConsumerBase::gridDisconnected(bool ownerChanged)
{
    gridConnection = nullptr;
    currentConnectedDeviceId = "";
    
    if (ownerChanged)
    {
        connectionOwned = false;
    }
}

std::string GridConsumerBase::gridGetCurrentDeviceId()
{
    return currentConnectedDeviceId;
}

std::string GridConsumerBase::gridGetLastDeviceId(bool owned)
{
    if (owned && !connectionOwned)
    {
        return "";
    }

    return lastConnectedDeviceId;
}

void GridConsumerBase::setLastDeviceId(std::string id)
{
    lastConnectedDeviceId = id;
}

Grid* GridConsumerBase::gridGetDevice()
{
    return gridConnection;
}

void GridConsumerBase::userReacquireGrid()
{
    if (lastConnectedDeviceId != "" && gridConnection == nullptr)
    {
        for (Grid* grid : GridConnectionManager::get().getGrids())
        {
            if (gridGetLastDeviceId(false) == grid->getDevice().id)
            {
                GridConnectionManager::get().connect(grid, this);
                return;
            }
        }
    }
}

void GridConsumerBase::saveGridConnectionToJson(json_t* rootJ)
{
    std::string deviceId = lastConnectedDeviceId;
    if (gridConnection)
    {
        deviceId = gridConnection->getDevice().id;
    }
    json_object_set_new(rootJ, "connectedDeviceId", json_string(deviceId.c_str()));
    json_object_set_new(rootJ, "connectionOwned", json_boolean(connectionOwned));
}

void GridConsumerBase::loadGridConnectionFromJson(json_t* rootJ)
{
    json_t* id = json_object_get(rootJ, "connectedDeviceId");
    if (id)
    {
        lastConnectedDeviceId = json_string_value(id);
    }

    json_t* owned = json_object_get(rootJ, "connectionOwned");
    if (owned)
    {
        connectionOwned = json_boolean_value(owned);
    }
}