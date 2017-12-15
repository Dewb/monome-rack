#include "GridConnection.hpp"

#pragma once

struct VirtualGridModule;

struct VirtualGridConnection : GridConnection
{
    VirtualGridConnection(MonomeModuleBase* controlledModule, VirtualGridModule* gridModule);
    VirtualGridModule* grid;

    void connect() override;
    void disconnect() override;
    void processInput() override;
    void updateQuadrant(int x, int y, uint8_t* leds) override;
    void clearAll() override;

    bool operator==(const VirtualGridConnection& other) const;
};