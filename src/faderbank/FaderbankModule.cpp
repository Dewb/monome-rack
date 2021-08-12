#include "FaderbankModule.hpp"

FaderbankModule::FaderbankModule()
{
    config(NUM_FADERS, 0, NUM_FADERS, 0);

    for (unsigned i = 0; i < NUM_FADERS; i++)
    {
        configParam(i, 0.0, 10.0, i/(1.0*NUM_FADERS) * 10.0);
    }
}

FaderbankModule::~FaderbankModule()
{
}

void FaderbankModule::process(const ProcessArgs& args)
{
    for (unsigned i = 0; i < NUM_FADERS; i++)
    {
        outputs[i].setVoltage(params[i].getValue());
    }
}

json_t* FaderbankModule::dataToJson()
{
    json_t* rootJ = json_object();
    return rootJ;
}

void FaderbankModule::dataFromJson(json_t* rootJ)
{
}

