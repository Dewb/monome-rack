#include "FirmwareManager.hpp"
#include "SerialOsc.h"
#include "rack0.hpp"

#pragma once

#define B00 32
#define B01 33
#define B02 34
#define B03 35
#define B04 36
#define B05 37
#define B06 38
#define B07 39
#define B08 40
#define B09 41
#define B10 42
#define NMI 13

struct GridConnection;

struct MonomeModuleBase : rack::Module, SerialOsc::Listener
{
    FirmwareManager firmware;

    MonomeModuleBase(int numParams, int numInputs, int numOutputs, int numLights);

    // SerialOsc::Listener methods
    void deviceFound(const MonomeDevice* const device) override;
    void deviceRemoved(const std::string& id) override;
    void buttonPressMessageReceived(MonomeDevice* device, int x, int y, bool state) override;

    // Rack module methods
    void step() override;
    json_t* toJson() override;
    void fromJson(json_t* rootJ) override;

    // MonomeModuleBase virtual methods
    virtual void processInputs() = 0;
    virtual void processOutputs() = 0;

    ~MonomeModuleBase();
    void setGridConnection(GridConnection* newConnection);
    void resolveSavedGridConnection();
    virtual void readSerialMessages();

    SerialOsc* serialOscDriver;
    GridConnection* gridConnection;
    bool firstStep;
    std::string unresolvedConnectionId;
};
