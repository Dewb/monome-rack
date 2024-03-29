#pragma once

#include "MonomeDevice.h"
#include <map>
#include <set>
#include <stdint.h>

struct SerialOscInterface;

struct Grid
{
    virtual ~Grid() {}
    virtual const MonomeDevice& getDevice() = 0;
    virtual void updateRow(int x_offset, int y, uint8_t bitfield) = 0;
    virtual void updateQuadrant(int x, int y, uint8_t* leds) = 0;
    virtual void updateRing(int n, uint8_t leds[64]) = 0;
    virtual void clearAll() = 0;
    virtual bool isHardware() = 0;
};

struct IGridConsumer
{
    virtual ~IGridConsumer() {}
    virtual void gridConnected(Grid* grid) = 0;
    virtual void gridDisconnected(bool ownerChanged) = 0;
    virtual std::string gridGetCurrentDeviceId() = 0;
    virtual std::string gridGetLastDeviceId(bool owned) = 0;
    virtual void setLastDeviceId(std::string id) = 0;
    virtual void gridButtonEvent(int x, int y, bool state) = 0;
    virtual void encDeltaEvent(int n, int d) = 0;
    virtual Grid* gridGetDevice() = 0;
};

struct GridConnectionManager final
{
    // Only call these from the UI thread
    void registerGrid(Grid* grid);
    void registerGridConsumer(IGridConsumer* consumer);
    void deregisterGrid(std::string id, bool deleteGrid = false);
    void deregisterGridConsumer(IGridConsumer* consumer);

    void connect(Grid* grid, IGridConsumer* consumer);
    bool isConnected(IGridConsumer* consumer);
    bool isConnected(std::string id);
    void disconnect(Grid* grid, bool ownerChanged = false);
    void disconnect(IGridConsumer* consumer, bool ownerChanged = false);
    void toggleConnection(Grid* grid, IGridConsumer* consumer);

    void dispatchButtonMessage(MonomeDevice* device, int x, int y, bool state);
    void dispatchEncDeltaMessage(MonomeDevice* device, int n, int d);
    const std::set<Grid*>& getGrids();

    static GridConnectionManager& get();

private:
    GridConnectionManager() = default;
    ~GridConnectionManager() = default;
    GridConnectionManager(const GridConnectionManager&) = delete;
    GridConnectionManager& operator=(const GridConnectionManager&) = delete;
    GridConnectionManager(GridConnectionManager&&) = delete;
    GridConnectionManager&& operator=(const GridConnectionManager&&) = delete;

    std::set<IGridConsumer*> consumers;
    std::set<Grid*> grids;
    std::map<std::string, IGridConsumer*> idToConsumerMap;
    std::map<IGridConsumer*, Grid*> consumerToGridMap;
};