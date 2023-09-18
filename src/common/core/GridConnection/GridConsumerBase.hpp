#pragma once

#include "GridConnection.hpp"
#include "rack.hpp"

struct GridConsumerBase : public IGridConsumer
{
    // IGridConsumer partial implementation; child classes implement gridButtonEvent/encDeltaEvent
    void gridConnected(Grid* grid) override;
    void gridDisconnected(bool ownerChanged) override;
    std::string gridGetCurrentDeviceId() override;
    std::string gridGetLastDeviceId(bool owned) override;
    virtual void setLastDeviceId(std::string id) override;
    Grid* gridGetDevice() override;

    GridConsumerBase();
    virtual ~GridConsumerBase() {};

    void userReacquireGrid();

    void saveGridConnectionToJson(json_t* rootJ);
    void loadGridConnectionFromJson(json_t* rootJ);

    std::string lastConnectedDeviceId;
    std::string currentConnectedDeviceId;
    bool connectionOwned;

protected:
    Grid* gridConnection;
};