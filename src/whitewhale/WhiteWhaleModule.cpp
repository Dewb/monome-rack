#include "WhiteWhaleModule.hpp"

WhiteWhaleModule::WhiteWhaleModule()
{
    config(NUM_PARAMS, NUM_INPUTS, NUM_OUTPUTS, NUM_LIGHTS);
    configParam(BUTTON_PARAM, 0.0, 1.0, 0.0, "Presets");
    configParam(PARAM_PARAM, 0.0, 1.0, 0.5, "Param");
    configParam(CLOCK_PARAM, 0.0, 1.0, 0.5, "Clock");

    firmware.load("whitewhale");
    firmware.init();
}

void WhiteWhaleModule::processInputs()
{
    // Convert clock input jack to GPIO signals for normal connection and value
    bool clockNormal = !inputs[CLOCK_INPUT].isConnected();
    if (clockNormal != firmware.getGPIO(B09))
    {
        firmware.setGPIO(B09, clockNormal);
        firmware.triggerInterrupt(1);
    }
    bool externalClock = inputs[CLOCK_INPUT].getVoltage() > 0;
    if (externalClock != firmware.getGPIO(B08))
    {
        firmware.setGPIO(B08, externalClock);
        firmware.triggerInterrupt(2);
    }
    bool frontButton = params[BUTTON_PARAM].getValue() == 0;
    if (frontButton != firmware.getGPIO(NMI))
    {
        firmware.setGPIO(NMI, frontButton);
        firmware.triggerInterrupt(3);
    }

    // Convert knob float parameters to 12-bit ADC values
    firmware.setADC(0, params[CLOCK_PARAM].getValue() * 0xFFF);
    firmware.setADC(1, params[PARAM_PARAM].getValue() * 0xFFF);
}

void WhiteWhaleModule::processOutputs()
{
    // Update lights from GPIO
    lights[CLOCK_LIGHT].setBrightnessSmooth(firmware.getGPIO(B10));
    lights[TRIG1_LIGHT].setBrightnessSmooth(firmware.getGPIO(B00));
    lights[TRIG2_LIGHT].setBrightnessSmooth(firmware.getGPIO(B01));
    lights[TRIG3_LIGHT].setBrightnessSmooth(firmware.getGPIO(B02));
    lights[TRIG4_LIGHT].setBrightnessSmooth(firmware.getGPIO(B03));
    lights[CVA_LIGHT].value = firmware.getDAC(0) / 65536.0;
    lights[CVB_LIGHT].value = firmware.getDAC(1) / 65536.0;

    // Update output jacks from GPIO & DAC
    outputs[CLOCK_OUTPUT].setVoltage(firmware.getGPIO(B10) * 8.0);
    outputs[TRIG1_OUTPUT].setVoltage(firmware.getGPIO(B00) * 8.0);
    outputs[TRIG2_OUTPUT].setVoltage(firmware.getGPIO(B01) * 8.0);
    outputs[TRIG3_OUTPUT].setVoltage(firmware.getGPIO(B02) * 8.0);
    outputs[TRIG4_OUTPUT].setVoltage(firmware.getGPIO(B03) * 8.0);
    outputs[CVA_OUTPUT].setVoltage(10.0 * firmware.getDAC(0) / 65536.0);
    outputs[CVB_OUTPUT].setVoltage(10.0 * firmware.getDAC(1) / 65536.0);
}
