#include "WhiteWhaleModule.hpp"

WhiteWhaleModule::WhiteWhaleModule()
: LibAVR32Module("whitewhale")
{
    config(NUM_PARAMS, NUM_INPUTS, NUM_OUTPUTS, NUM_LIGHTS);
    configParam(BUTTON_PARAM, 0.0, 1.0, 0.0, "Presets");
    configParam(PARAM_PARAM, 0.0, 10.0, 5.0, "Param");
    configParam(CLOCK_PARAM, 0.0, 10.0, 5.0, "Clock");
}

void WhiteWhaleModule::processInputs(const ProcessArgs& args)
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
    firmware.setADC(0, voltsToAdc(params[CLOCK_PARAM].getValue()));
    firmware.setADC(1, voltsToAdc(params[PARAM_PARAM].getValue()));
}

void WhiteWhaleModule::processOutputs(const ProcessArgs& args)
{
    float cv1 = dacToVolts(firmware.getDAC(0));
    float cv2 = dacToVolts(firmware.getDAC(1));
    bool clock = firmware.getGPIO(B10);
    bool tr1 = firmware.getGPIO(B00);
    bool tr2 = firmware.getGPIO(B01);
    bool tr3 = firmware.getGPIO(B02);
    bool tr4 = firmware.getGPIO(B03);

    // Update lights from GPIO
    lights[CLOCK_LIGHT].setSmoothBrightness(clock, args.sampleTime);
    lights[TRIG1_LIGHT].setSmoothBrightness(tr1, args.sampleTime);
    lights[TRIG2_LIGHT].setSmoothBrightness(tr2, args.sampleTime);
    lights[TRIG3_LIGHT].setSmoothBrightness(tr3, args.sampleTime);
    lights[TRIG4_LIGHT].setSmoothBrightness(tr4, args.sampleTime);
    lights[CVA_LIGHT].setSmoothBrightness(cv1 / 10.0, args.sampleTime);
    lights[CVB_LIGHT].setSmoothBrightness(cv2 / 10.0, args.sampleTime);

    // Update output jacks from GPIO & DAC
    outputs[CLOCK_OUTPUT].setVoltage(clock * 8.0);
    outputs[TRIG1_OUTPUT].setVoltage(tr1 * 8.0);
    outputs[TRIG2_OUTPUT].setVoltage(tr2 * 8.0);
    outputs[TRIG3_OUTPUT].setVoltage(tr3 * 8.0);
    outputs[TRIG4_OUTPUT].setVoltage(tr4 * 8.0);
    outputs[CVA_OUTPUT].setVoltage(cv1);
    outputs[CVB_OUTPUT].setVoltage(cv2);
}
