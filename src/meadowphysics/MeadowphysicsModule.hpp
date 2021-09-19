#include "LibAVR32Module.hpp"

#pragma once

struct MeadowphysicsModule : LibAVR32Module
{
    enum ParamIds
    {
        CLOCK_PARAM,
        BUTTON_PARAM,
        NUM_PARAMS
    };

    enum InputIds
    {
        CLOCK_INPUT,
        NUM_INPUTS
    };

    enum OutputIds
    {
        CLOCK_OUTPUT,
        TRIG1_OUTPUT,
        TRIG2_OUTPUT,
        TRIG3_OUTPUT,
        TRIG4_OUTPUT,
        TRIG5_OUTPUT,
        TRIG6_OUTPUT,
        TRIG7_OUTPUT,
        TRIG8_OUTPUT,
        NUM_OUTPUTS
    };

    enum LightIds
    {
        CLOCK_LIGHT,
        TRIG1_LIGHT,
        TRIG2_LIGHT,
        TRIG3_LIGHT,
        TRIG4_LIGHT,
        TRIG5_LIGHT,
        TRIG6_LIGHT,
        TRIG7_LIGHT,
        TRIG8_LIGHT,
        NUM_LIGHTS
    };

    MeadowphysicsModule();
    void processInputs() override;
    void processOutputs() override;
};
