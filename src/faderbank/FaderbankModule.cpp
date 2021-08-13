#include "FaderbankModule.hpp"

#define FADERBANK_II_MAX_VALUE 16383

FaderbankModule::FaderbankModule()
{
    config(NUM_FADERS, 0, NUM_FADERS, 0);

    for (unsigned i = 0; i < NUM_FADERS; i++)
    {
        configParam(i, 0.0, 10.0, i/(1.0*NUM_FADERS) * 10.0);
    }

    _iiDevice.setAddress(0x34);
}

FaderbankModule::~FaderbankModule()
{
}

void FaderbankModule::process(const ProcessArgs& args)
{
    for (unsigned i = 0; i < NUM_FADERS; i++)
    {
        outputs[i].setVoltage(params[i].getValue());
        
        float iiValue = params[i].getValue() / 10.0 * FADERBANK_II_MAX_VALUE;
        _iiDevice.updateFollowerData(i, static_cast<uint16_t>(iiValue));
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

