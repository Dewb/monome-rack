#include "MonomeModuleBase.hpp"

#pragma once

struct EarthseaModule : MonomeModuleBase
{
    enum ParamIds
    {
        CV1_PARAM,
        CV2_PARAM,
        CV3_PARAM,
        BUTTON_PARAM,
        NUM_PARAMS
    };

    enum InputIds
    {
        NUM_INPUTS
    };

    enum OutputIds
    {
        CV1_OUTPUT,
        CV2_OUTPUT,
        CV3_OUTPUT,
        POS_OUTPUT,
        EDGE_OUTPUT,
        NUM_OUTPUTS
    };

    enum LightIds
    {
        CV1_LIGHT,
        CV2_LIGHT,
        CV3_LIGHT,
        POS_LIGHT,
        EDGE_LIGHT,
        NUM_LIGHTS
    };

    EarthseaModule();
    void step() override;
};