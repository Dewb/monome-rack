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

enum ReloadRequest
{
    None = 0,
    ReloadAndRestart,
    HotReload,
};

struct LibAVR32Module : rack::engine::Module, GridConsumer
{
    FirmwareManager firmware;

    LibAVR32Module(std::string firmwareName);
    ~LibAVR32Module();

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
    void requestReloadFirmware(ReloadRequest request) { reloadRequested = request; }

    Grid* gridConnection;
    std::string lastConnectedDeviceId;
    std::string firmwareName;

private:
    void reloadFirmware(bool preserveMemory);

    bool firstStep;
    ReloadRequest reloadRequested;
};
