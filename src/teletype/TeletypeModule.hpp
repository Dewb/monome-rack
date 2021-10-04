#include "LibAVR32Module.hpp"
#include "iiBus.h"

#include "rack.hpp"


struct TeletypeModule : LibAVR32Module
{
    enum ParamIds
    {
        PARAM_PARAM,
        BUTTON_PARAM,
        NUM_PARAMS
    };
    enum InputIds
    {
        TRIG1_INPUT,
        TRIG2_INPUT,
        TRIG3_INPUT,
        TRIG4_INPUT,
        TRIG5_INPUT,
        TRIG6_INPUT,
        TRIG7_INPUT,
        TRIG8_INPUT,
        IN_INPUT,
        NUM_INPUTS
    };
    enum OutputIds
    {
        TR1_OUTPUT,
        TR2_OUTPUT,
        TR3_OUTPUT,
        TR4_OUTPUT,
        CV1_OUTPUT,
        CV2_OUTPUT,
        CV3_OUTPUT,
        CV4_OUTPUT,
        NUM_OUTPUTS
    };
    enum LightIds
    {
        TR1_LIGHT,
        TR2_LIGHT,
        TR3_LIGHT,
        TR4_LIGHT,
        CV1_LIGHT,
        CV2_LIGHT,
        CV3_LIGHT,
        CV4_LIGHT,
        NUM_LIGHTS
    };

    TeletypeModule();
    void processInputs(const ProcessArgs& args) override;
    void processOutputs(const ProcessArgs& args) override;

    uint8_t screenBuffer[128 * 64];

protected:
    iiDevice _iiDevice;
};
