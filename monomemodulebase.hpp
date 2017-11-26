#include "rack.hpp"
#include "SerialOsc.h"

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

    inline bool operator==(const RackGridConnection &other) const;
};

struct SerialOscGridConnection : GridConnection
{
    SerialOscGridConnection(MonomeModuleBase *controlledModule, MonomeDevice *device);
    MonomeDevice *grid;

    void connect() override;
    void disconnect() override;
    void processInput() override;
    void updateQuadrant(int x, int y, uint8_t *leds) override;

    inline bool operator==(const SerialOscGridConnection &other) const;
};

struct MonomeModuleBase : Module, SerialOsc::Listener
{
    MonomeModuleBase(int numParams, int numInputs, int numOutputs, int numLights);

    void deviceRemoved(const std::string &id) override;
    void buttonPressMessageReceived(MonomeDevice* device, int x, int y, bool state) override;

    ~MonomeModuleBase();
    void setGridConnection(GridConnection *newConnection);

    SerialOsc* serialOscDriver;
    GridConnection* gridConnection;
};

struct MonomeModuleBaseWidget : ModuleWidget
{
    Menu *createContextMenu() override;
};