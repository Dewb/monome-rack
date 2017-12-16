#include "GridConnection.hpp"

#pragma once

struct SerialOscGridConnection : GridConnection
{
    SerialOscGridConnection(MonomeModuleBase* controlledModule, const MonomeDevice* const device);

    void connect() override;
    void disconnect() override;
    void processInput() override;
    void updateRow(int x_offset, int y, uint8_t bitfield) override;
    void updateQuadrant(int x, int y, uint8_t* leds) override;
    void clearAll() override;

    bool operator==(const SerialOscGridConnection& other) const;
};