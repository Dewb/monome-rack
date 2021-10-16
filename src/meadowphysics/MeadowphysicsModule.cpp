#include "MeadowphysicsModule.hpp"

MeadowphysicsModule::MeadowphysicsModule()
: LibAVR32Module("meadowphysics")
{
    config(NUM_PARAMS, NUM_INPUTS, NUM_OUTPUTS, NUM_LIGHTS);
    configParam(BUTTON_PARAM, 0.0, 1.0, 0.0, "Presets");
    configParam(CLOCK_PARAM, 0.0, 10.0, 5.0, "Clock");
}

void MeadowphysicsModule::processInputs(const ProcessArgs& args)
{
    // Convert clock input jack to GPIO signals for normal connection and value
    bool clockNormal = !inputs[CLOCK_INPUT].isConnected();
    if (clockNormal != firmware.getGPIO(B09))
    {
        firmware.setGPIO(B09, clockNormal);
        firmware.triggerInterrupt(1);
    }
    bool externalClock = isTriggered(CLOCK_INPUT);
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
}

void MeadowphysicsModule::processOutputs(const ProcessArgs& args)
{
    // Update lights from GPIO
    lights[CLOCK_LIGHT].setSmoothBrightness(firmware.getGPIO(B10), args.sampleTime);
    lights[TRIG1_LIGHT].setSmoothBrightness(firmware.getGPIO(B00), args.sampleTime);
    lights[TRIG2_LIGHT].setSmoothBrightness(firmware.getGPIO(B01), args.sampleTime);
    lights[TRIG3_LIGHT].setSmoothBrightness(firmware.getGPIO(B02), args.sampleTime);
    lights[TRIG4_LIGHT].setSmoothBrightness(firmware.getGPIO(B03), args.sampleTime);
    lights[TRIG5_LIGHT].setSmoothBrightness(firmware.getGPIO(B04), args.sampleTime);
    lights[TRIG6_LIGHT].setSmoothBrightness(firmware.getGPIO(B05), args.sampleTime);
    lights[TRIG7_LIGHT].setSmoothBrightness(firmware.getGPIO(B06), args.sampleTime);
    lights[TRIG8_LIGHT].setSmoothBrightness(firmware.getGPIO(B07), args.sampleTime);

    // Update output jacks from GPIO
    outputs[CLOCK_OUTPUT].setVoltage(firmware.getGPIO(B10) * 8.0);
    outputs[TRIG1_OUTPUT].setVoltage(firmware.getGPIO(B00) * 8.0);
    outputs[TRIG2_OUTPUT].setVoltage(firmware.getGPIO(B01) * 8.0);
    outputs[TRIG3_OUTPUT].setVoltage(firmware.getGPIO(B02) * 8.0);
    outputs[TRIG4_OUTPUT].setVoltage(firmware.getGPIO(B03) * 8.0);
    outputs[TRIG5_OUTPUT].setVoltage(firmware.getGPIO(B04) * 8.0);
    outputs[TRIG6_OUTPUT].setVoltage(firmware.getGPIO(B05) * 8.0);
    outputs[TRIG7_OUTPUT].setVoltage(firmware.getGPIO(B06) * 8.0);
    outputs[TRIG8_OUTPUT].setVoltage(firmware.getGPIO(B07) * 8.0);
}
