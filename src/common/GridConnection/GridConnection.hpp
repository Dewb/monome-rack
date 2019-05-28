#pragma once

#include "MonomeDevice.h"
#include <map>
#include <set>
#include <stdint.h>

struct Grid
{
    virtual ~Grid();
    virtual const MonomeDevice& getDevice() = 0;
    virtual void updateRow(int x_offset, int y, uint8_t bitfield) = 0;
    virtual void updateQuadrant(int x, int y, uint8_t* leds) = 0;
    virtual void clearAll() = 0;
};

struct GridConsumer
{
    virtual void gridConnected(Grid* grid) = 0;
    virtual void gridDisconnected() = 0;
    virtual std::string gridGetLastDeviceId() = 0;
    virtual void gridButtonEvent(int x, int y, bool state) = 0;
};

struct GridConnectionManager
{
    void registerGrid(Grid* grid);
    void registerGridConsumer(GridConsumer* consumer);
    void deregisterGrid(std::string id, bool deleteGrid = false);
    void deregisterGridConsumer(GridConsumer* consumer);

    void connect(Grid* grid, GridConsumer* consumer);
    bool isConnected(GridConsumer* consumer);
    void disconnect(Grid* grid);
    void disconnect(GridConsumer* consumer);

    void dispatchButtonMessage(MonomeDevice* device, int x, int y, bool state);

    const std::set<Grid*>& getGrids();

    static GridConnectionManager* get();

private:
    GridConnectionManager();
    static GridConnectionManager* instance;

    std::set<GridConsumer*> consumers;
    std::set<Grid*> grids;
    std::map<std::string, GridConsumer*> idToConsumerMap;
    std::map<GridConsumer*, Grid*> consumerToGridMap;
};