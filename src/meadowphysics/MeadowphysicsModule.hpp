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
        TR1_OUTPUT,
        TR2_OUTPUT,
        TR3_OUTPUT,
        TR4_OUTPUT,
        TR5_OUTPUT,
        TR6_OUTPUT,
        TR7_OUTPUT,
        TR8_OUTPUT,
        NUM_OUTPUTS
    };

    enum LightIds
    {
        CLOCK_LIGHT,
        TR1_LIGHT,
        TR2_LIGHT,
        TR3_LIGHT,
        TR4_LIGHT,
        TR5_LIGHT,
        TR6_LIGHT,
        TR7_LIGHT,
        TR8_LIGHT,
        NUM_LIGHTS
    };

    MeadowphysicsModule();
    void processInputs(const ProcessArgs& args) override;
    void processOutputs(const ProcessArgs& args) override;
};
