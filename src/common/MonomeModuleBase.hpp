#include "FirmwareManager.hpp"
#include "GridConnection.hpp"
#include "rack.hpp"

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

struct MonomeModuleBase : rack::engine::Module, GridConsumer
{
    FirmwareManager firmware;

    MonomeModuleBase();
    ~MonomeModuleBase();

    // Rack module methods
    void process(const ProcessArgs& args) override;
    json_t* dataToJson() override;
    void dataFromJson(json_t* rootJ) override;

    // MonomeModuleBase virtual methods
    virtual void processInputs() = 0;
    virtual void processOutputs() = 0;

    // GridConsumer methods
    void gridConnected(Grid* grid) override;
    void gridDisconnected() override;
    void gridButtonEvent(int x, int y, bool state) override;
    std::string gridGetLastDeviceId() override;

    virtual void readSerialMessages();

    Grid* gridConnection;
    std::string lastConnectedDeviceId;

private:
    bool firstStep;
};
