#include "SerialOsc.h"
#include "rack.hpp"

#pragma once
using namespace rack;

struct MonomeGrid;
struct MonomeModuleBase;

struct GridConnection
{
    GridConnection(MonomeModuleBase* controlledModule, const MonomeDevice* const device);
    MonomeModuleBase* module;
    const MonomeDevice* const device;

    virtual ~GridConnection() {}
    virtual void connect() = 0;
    virtual void disconnect() = 0;
    virtual void processInput() = 0;
    virtual void updateQuadrant(int x, int y, uint8_t* leds) = 0;
};

struct RackGridConnection : GridConnection
{
    RackGridConnection(MonomeModuleBase* controlledModule, MonomeGrid* gridModule);
    MonomeGrid* grid;

    void connect() override;
    void disconnect() override;
    void processInput() override;
    void updateQuadrant(int x, int y, uint8_t* leds) override;

    inline bool operator==(const RackGridConnection& other) const;
};

struct SerialOscGridConnection : GridConnection
{
    SerialOscGridConnection(MonomeModuleBase* controlledModule, const MonomeDevice* const device);

    void connect() override;
    void disconnect() override;
    void processInput() override;
    void updateQuadrant(int x, int y, uint8_t* leds) override;

    inline bool operator==(const SerialOscGridConnection& other) const;
};

struct MonomeModuleBase : Module, SerialOsc::Listener
{
    MonomeModuleBase(int numParams, int numInputs, int numOutputs, int numLights);

    // SerialOsc::Listener methods
    void deviceFound(const MonomeDevice* const device) override;
    void deviceRemoved(const std::string& id) override;
    void buttonPressMessageReceived(MonomeDevice* device, int x, int y, bool state) override;

    // Rack module methods
    void step() override;
    json_t* toJson() override;
    void fromJson(json_t* rootJ) override;

    ~MonomeModuleBase();
    void setGridConnection(GridConnection* newConnection);

    SerialOsc* serialOscDriver;
    GridConnection* gridConnection;
    bool firstStep;
    std::string unresolvedConnectionId;
};

struct MonomeModuleBaseWidget : ModuleWidget
{
    Menu* createContextMenu() override;
};