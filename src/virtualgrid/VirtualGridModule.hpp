#include "SerialOsc.h"
#include "rack.hpp"

#pragma once

#define GRID_MAX_SIZE 256

struct MonomeModuleBase;

struct VirtualGridModule : rack::Module
{
    MonomeModuleBase* connectedModule = NULL;
    MonomeDevice device;

    uint8_t ledBuffer[GRID_MAX_SIZE];
    bool pressedState[GRID_MAX_SIZE];

    VirtualGridModule(unsigned w, unsigned h);

    void step() override;

    json_t* toJson() override;
    void fromJson(json_t* rootJ) override;

    void updateRow(int x_offset, int y, uint8_t bitfield);
    void updateQuadrant(int x_offset, int y_offset, uint8_t* leds);
    void clearAll();
};
