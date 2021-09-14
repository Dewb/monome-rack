#include "TTExpanderModule.hpp"

TTExpanderModule::TTExpanderModule()
{
    config(NUM_PARAMS, NUM_INPUTS, NUM_OUTPUTS, NUM_LIGHTS);
    configParam(KEY1_PARAM, 0.0, 1.0, 0.0, "Key 1");
    configParam(KEY2_PARAM, 0.0, 1.0, 0.0, "Key 2");
    // configParam(MODE_PARAM, 0.0, 1.0, 0.0, "Mode");
}

void TTExpanderModule::process(const ProcessArgs& args)
{
    float data;

    bool input1 = inputs[IN1_INPUT].getVoltage() > 0;
    bool input2 = inputs[IN2_INPUT].getVoltage() > 0;
    bool key1Button = params[KEY1_PARAM].getValue() == 0;
    bool key2Button = params[KEY2_PARAM].getValue() == 0;
    // bool modeButton = params[MODE_PARAM].getValue() == 0;

    // lights[MODE_YELLOW_LIGHT].setSmoothBrightness(data * 0.7, 1.f);
    // lights[MODE_WHITE_LIGHT].setSmoothBrightness(data * 0.4, 1.f);

    lights[TR1_LIGHT].setSmoothBrightness(data, 0.3f);
    lights[TR2_LIGHT].setSmoothBrightness(data, 0.3f);
    lights[TR3_LIGHT].setSmoothBrightness(data, 0.3f);
    lights[TR4_LIGHT].setSmoothBrightness(data, 0.3f);
    lights[CV1_LIGHT].setSmoothBrightness(10.0 * data / 65536.0, 0.3f);
    lights[CV2_LIGHT].setSmoothBrightness(10.0 * data / 65536.0, 0.3f);
    lights[CV3_LIGHT].setSmoothBrightness(10.0 * data / 65536.0, 0.3f);
    lights[CV4_LIGHT].setSmoothBrightness(10.0 * data / 65536.0, 0.3f);

    outputs[TR1_OUTPUT].setVoltage(data * 8.0);
    outputs[TR2_OUTPUT].setVoltage(data * 8.0);
    outputs[TR3_OUTPUT].setVoltage(data * 8.0);
    outputs[TR4_OUTPUT].setVoltage(data * 8.0);
    outputs[CV1_OUTPUT].setVoltage(10.0 * data / 65536.0);
    outputs[CV2_OUTPUT].setVoltage(10.0 * data / 65536.0);
    outputs[CV3_OUTPUT].setVoltage(10.0 * data / 65536.0);
    outputs[CV4_OUTPUT].setVoltage(10.0 * data / 65536.0);
}
