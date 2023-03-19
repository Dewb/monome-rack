#pragma once

#include "GridConnection.hpp"
#include "MonomeDevice.h"

struct SerialOscGrid : Grid
{
    SerialOscGrid(const MonomeDevice* const device);
    MonomeDevice device;

    const MonomeDevice& getDevice() override;
    void updateRow(int x_offset, int y, uint8_t bitfield) override;
    void updateQuadrant(int x, int y, uint8_t* leds) override;
    void updateRing(int n, uint8_t leds[64]) override;
    void clearAll() override;
};