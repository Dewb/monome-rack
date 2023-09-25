#pragma once
#include "rack.hpp"

#include <map>

#define NUM_FADERS 16

struct FaderbankModule : rack::Module
{
    FaderbankModule();
    ~FaderbankModule();

    void process(const ProcessArgs& args) override;

    void processMIDIMessage(const rack::midi::Message& msg);
    void resetConfig();
    void updateFaderRanges();

    json_t* dataToJson() override;
    void dataFromJson(json_t* rootJ) override;

    rack::midi::InputQueue midiInput;
    std::map<uint16_t, uint8_t> inputMap;

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
};
