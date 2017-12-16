#include <stdint.h>

#pragma once

struct MonomeModuleBase;
struct MonomeDevice;

struct GridConnection
{
    GridConnection(MonomeModuleBase* controlledModule, const MonomeDevice* const device);
    MonomeModuleBase* module;
    const MonomeDevice* const device;

    virtual ~GridConnection() {}
    virtual void connect() = 0;
    virtual void disconnect() = 0;
    virtual void processInput() = 0;
    virtual void updateRow(int x_offset, int y, uint8_t bitfield) = 0;
    virtual void updateQuadrant(int x, int y, uint8_t* leds) = 0;
    virtual void clearAll() = 0;
};

