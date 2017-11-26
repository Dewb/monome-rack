#include "rack.hpp"

#pragma once
using namespace rack;

template <size_t GRID_X, size_t GRID_Y> struct Grid;

struct MonomeModuleBase;

struct GridConnection
{
    GridConnection(MonomeModuleBase* controlledModule);
    MonomeModuleBase *module;

    virtual ~GridConnection() {}
    virtual void connect() = 0;
    virtual void disconnect() = 0;
    virtual void processInput() = 0;
    virtual void updateQuadrant(int x, int y, uint8_t *leds) = 0;
};

struct RackGridConnection : GridConnection
{
    RackGridConnection(MonomeModuleBase *controlledModule, Grid<16, 8> *gridModule);
    Grid<16,8> *grid;
    
    void connect() override;
    void disconnect() override;
    void processInput() override;
    void updateQuadrant(int x, int y, uint8_t *leds) override;
};

struct SerialOSCGridConnection : GridConnection
{
    void connect() override;
    void disconnect() override;
    void processInput() override;
    void updateQuadrant(int x, int y, uint8_t *leds) override;
};

struct MonomeModuleBase : Module
{
    MonomeModuleBase(int numParams, int numInputs, int numOutputs, int numLights);

    virtual void onGridKeyPressed(uint8_t x, uint8_t y, uint8_t val) = 0;

    ~MonomeModuleBase();
    void setGridConnection(GridConnection *newConnection);

    GridConnection *gridConnection;
};
