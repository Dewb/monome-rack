#pragma once
#include "rack.hpp"

#define NUM_FADERS 16

struct FaderbankModule : rack::Module
{
    FaderbankModule();
    ~FaderbankModule();

    void process(const ProcessArgs& args) override;

    json_t* dataToJson() override;
    void dataFromJson(json_t* rootJ) override;

protected:
};
