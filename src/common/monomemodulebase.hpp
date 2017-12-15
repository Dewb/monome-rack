#include "GridConnection.hpp"
#include "firmwaremanager.hpp"
#include "rack.hpp"
#include "SerialOsc.h"

#pragma once
using namespace rack;


struct MonomeModuleBase : Module, SerialOsc::Listener
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

    ~MonomeModuleBase();
    void setGridConnection(GridConnection* newConnection);
    virtual void readSerialMessages();

    SerialOsc* serialOscDriver;
    GridConnection* gridConnection;
    bool firstStep;
    std::string unresolvedConnectionId;
};

struct MonomeModuleBaseWidget : ModuleWidget
{
    Menu* createContextMenu() override;
};