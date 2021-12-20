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
    void onReset() override;

    // MonomeModuleBase virtual methods
    virtual void processInputs(const ProcessArgs& args) = 0;
    virtual void processOutputs(const ProcessArgs& args) = 0;

    // GridConsumer methods
    void gridConnected(Grid* grid) override;
    void gridDisconnected(bool ownerChanged) override;
    void gridButtonEvent(int x, int y, bool state) override;
    std::string gridGetLastDeviceId() override;

    virtual void readSerialMessages();
    void requestReloadFirmware(ReloadRequest request) { reloadRequested = request; }

    float dacToVolts(uint16_t adc);
    uint16_t voltsToAdc(float volts);
    bool isTriggered(float value);

    Grid* gridConnection;
    std::string lastConnectedDeviceId;
    std::string firmwareName;

    int inputRate;
    int outputRate;

    std::mutex processMutex;
    std::mutex firmwareMutex;

    bool firstStep;

protected:
    void reloadFirmware(bool preserveMemory);

    ReloadRequest reloadRequested;

    float dacOffsetVolts;
    float triggerThresholdVolts;
};

inline float LibAVR32Module::dacToVolts(uint16_t dac)
{
    // 12 bits of information left aligned in a 16-bit word, add a small offset to get the 12-bit data closer to true
    return (10.0 * dac / (0xFFFF * 1.0)) + dacOffsetVolts;
}

inline uint16_t LibAVR32Module::voltsToAdc(float volts)
{
    // Scale to 12-bit ADC, right-aligned in 16-bit word
    return (uint16_t)(rack::math::clamp(volts, 0.0, 10.0) * 0.1 * 0xFFF);
}

inline bool LibAVR32Module::isTriggered(float value)
{
    return value > triggerThresholdVolts;
}
