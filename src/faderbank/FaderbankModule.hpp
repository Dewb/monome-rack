#pragma once
#include "rack.hpp"
#include "iiBus.h"

#define NUM_FADERS 16

struct FaderbankModule : rack::Module
{
    FaderbankModule();
    ~FaderbankModule();

    void process(const ProcessArgs& args) override;

    json_t* dataToJson() override;
    void dataFromJson(json_t* rootJ) override;

protected:
    iiDevice _iiDevice;
};
