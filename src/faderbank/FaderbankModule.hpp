#pragma once
#include "rack.hpp"

#include <map>

#define NUM_FADERS 16

struct ControllerRecord
{
    uint8_t highValue;
    uint8_t lowValue;
    uint8_t lastHighValue;
    int64_t lastHighValueFrame;
    int64_t lastLowValueFrame;
    uint8_t ccNum;

    ControllerRecord()
    {
        highValue = 0xFF;
        lowValue = 0xFF;
        lastHighValue = 0;
    }
};

struct FaderbankModule : rack::Module
{
    FaderbankModule();
    ~FaderbankModule();

    void process(const ProcessArgs& args) override;

    void processMIDIMessages(const ProcessArgs& args);
    void resetConfig();
    void updateFaderRanges();

    json_t* dataToJson() override;
    void dataFromJson(json_t* rootJ) override;
    // override fromJson to deserialize data before params
    void fromJson(json_t* rootJ) override;

    std::map<uint16_t, uint8_t> inputMap;

    rack::midi::InputQueue midiInput;
    rack::midi::Output midiOutput;

    typedef enum
    {
        FaderSize90mm,
        FaderSize60mm
    } FaderSize;

    typedef enum
    {
        FaderRange10V,
        FaderRange5V,
        FaderRangeBipolar
    } FaderRange;

    FaderSize faderSize = FaderSize90mm;
    FaderRange faderRange = FaderRange10V;
    bool polyphonicMode = false;
    bool use14bitCCs = false;

protected:
    ControllerRecord records[NUM_FADERS];
};
