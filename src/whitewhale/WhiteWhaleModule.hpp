#include "LibAVR32Module.hpp"

#pragma once

struct WhiteWhaleModule : LibAVR32Module
{
    enum ParamIds
    {
        CLOCK_PARAM,
        PARAM_PARAM,
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
        CVA_OUTPUT,
        CVB_OUTPUT,
        NUM_OUTPUTS
    };

    enum LightIds
    {
        CLOCK_LIGHT,
        TR1_LIGHT,
        TR2_LIGHT,
        TR3_LIGHT,
        TR4_LIGHT,
        CVA_LIGHT,
        CVB_LIGHT,
        NUM_LIGHTS
    };

    WhiteWhaleModule();
    void processInputs(const ProcessArgs& args) override;
    void processOutputs(const ProcessArgs& args) override;
};