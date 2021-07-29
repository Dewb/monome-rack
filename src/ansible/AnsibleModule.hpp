#include "MonomeModuleBase.hpp"

#pragma once

struct AnsibleModule : MonomeModuleBase
{
    enum ParamIds
    {
        KEY1_PARAM,
        KEY2_PARAM,
        MODE_PARAM,
        NUM_PARAMS
    };

    enum InputIds
    {
        IN1_INPUT,
        IN2_INPUT,
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
        MODE_LIGHT,
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

    AnsibleModule();
    void processInputs() override;
    void processOutputs() override;
};
