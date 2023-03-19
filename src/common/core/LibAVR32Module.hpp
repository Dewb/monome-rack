#include "FirmwareManager.hpp"
#include "GridConnection.hpp"
#include "VirtualGridTheme.hpp"
#include "rack.hpp"
#include <queue>

#pragma once

#define A00 0
#define A01 1
#define A02 2
#define A03 3
#define A04 4
#define A05 5
#define A06 6
#define A07 7
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
#define B11 43
#define NMI 13

struct GridConnection;

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
    void encDeltaEvent(int n, int d) override;
    std::string gridGetLastDeviceId(bool owned) override;

    void userReacquireGrid();
    void userToggleGridConnection(Grid* grid);
    virtual void readSerialMessages();

    void requestReloadFirmware(bool preserveMemory);

    float dacToVolts(uint16_t adc);
    uint16_t voltsToAdc(float volts);

    std::string lastConnectedDeviceId;
    std::string currentConnectedDeviceId;
    bool connectionOwned;

    std::string firmwareName;

    int inputRate;
    int outputRate;

    GridTheme theme;

    virtual uint8_t* getScreenBuffer() { return 0; }

protected:
    void reloadFirmware(bool preserveMemory);
    void toggleGridConnection(Grid* grid);

    Grid* gridConnection;
    int usbParamId;
    void setDeviceConnectionParam(int paramId) { usbParamId = paramId; }
    void processDeviceConnectionParam();

    float dacOffsetVolts;
    float triggerHighThreshold;
    float triggerLowThreshold;

    // Thread-safe for single-producer, single-consumer
    friend struct TeletypeSceneIO;
    typedef std::function<void(void)> Action;
    typedef rack::dsp::RingBuffer<Action, 4> ActionQueue;
    ActionQueue audioThreadActions;
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

