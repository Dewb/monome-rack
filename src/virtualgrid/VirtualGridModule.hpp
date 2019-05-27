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

    void process(const ProcessArgs &args) override;

    json_t* dataToJson() override;
    void dataFromJson(json_t* rootJ) override;

    void updateRow(int x_offset, int y, uint8_t bitfield);
    void updateQuadrant(int x_offset, int y_offset, uint8_t* leds);
    void clearAll();
};

template <unsigned width, unsigned height, unsigned modelIndex>
struct VirtualGridModuleTemplate : VirtualGridModule
{
    VirtualGridModuleTemplate()
        : VirtualGridModule(width, height)
    {
    }
};
