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

    json_t* dataToJson() override;
    void dataFromJson(json_t* rootJ) override;

    rack::midi::InputQueue midiInput;
    std::map<uint16_t, uint8_t> inputMap;

    typedef enum
    {
        Fader90mm,
        Fader60mm
    } FaderSize;

    FaderSize faderSize = Fader90mm;
};
