#pragma once
#include "rack.hpp"
#include "iiBus.h"

#define NUM_FADERS 16

struct FaderbankModule : rack::Module
{
    FaderbankModule();
    ~FaderbankModule();

    void process(const ProcessArgs& args) override;

    void processMIDIMessage(const rack::midi::Message& msg);

    json_t* dataToJson() override;
    void dataFromJson(json_t* rootJ) override;

    rack::midi::InputQueue midiInput;
    uint8_t startCC;

    typedef enum
    {
        Fader90mm,
        Fader60mm
    } FaderSize;

    FaderSize faderSize = Fader90mm;

protected:
    iiDevice _iiDevice;
};
