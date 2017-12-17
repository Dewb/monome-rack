#include "MeadowphysicsModule.hpp"


MeadowphysicsModule::MeadowphysicsModule()
    : MonomeModuleBase(NUM_PARAMS, NUM_INPUTS, NUM_OUTPUTS, NUM_LIGHTS)
{
    firmware.load("./plugins/monome-rack/build/firmware/meadowphysics");
    firmware.init();
}

void MeadowphysicsModule::processInputs()
{
    // Convert clock input jack to GPIO signals for normal connection and value
    bool clockNormal = !inputs[CLOCK_INPUT].active;
    if (clockNormal != firmware.getGPIO(B09))
    {
        firmware.setGPIO(B09, clockNormal);
        firmware.triggerInterrupt(1);
    }
    bool externalClock = inputs[CLOCK_INPUT].value > 0;
    if (externalClock != firmware.getGPIO(B08))
    {
        firmware.setGPIO(B08, externalClock);
        firmware.triggerInterrupt(2);
    }
    bool frontButton = params[BUTTON_PARAM].value == 0;
    if (frontButton != firmware.getGPIO(NMI))
    {
        firmware.setGPIO(NMI, frontButton);
        firmware.triggerInterrupt(3);
    }

    // Convert knob float parameters to 12-bit ADC values
    firmware.setADC(0, params[CLOCK_PARAM].value * 0xFFF);
}

void MeadowphysicsModule::processOutputs()
{
    // Update lights from GPIO
    lights[CLOCK_LIGHT].setBrightnessSmooth(firmware.getGPIO(B10));
    lights[TRIG1_LIGHT].setBrightnessSmooth(firmware.getGPIO(B00));
    lights[TRIG2_LIGHT].setBrightnessSmooth(firmware.getGPIO(B01));
    lights[TRIG3_LIGHT].setBrightnessSmooth(firmware.getGPIO(B02));
    lights[TRIG4_LIGHT].setBrightnessSmooth(firmware.getGPIO(B03));
    lights[TRIG5_LIGHT].setBrightnessSmooth(firmware.getGPIO(B04));
    lights[TRIG6_LIGHT].setBrightnessSmooth(firmware.getGPIO(B05));
    lights[TRIG7_LIGHT].setBrightnessSmooth(firmware.getGPIO(B06));
    lights[TRIG8_LIGHT].setBrightnessSmooth(firmware.getGPIO(B07));

    // Update output jacks from GPIO & DAC
    outputs[CLOCK_OUTPUT].value = firmware.getGPIO(B10) * 8.0;
    outputs[TRIG1_OUTPUT].value = firmware.getGPIO(B00) * 8.0;
    outputs[TRIG2_OUTPUT].value = firmware.getGPIO(B01) * 8.0;
    outputs[TRIG3_OUTPUT].value = firmware.getGPIO(B02) * 8.0;
    outputs[TRIG4_OUTPUT].value = firmware.getGPIO(B03) * 8.0;
    outputs[TRIG5_OUTPUT].value = firmware.getGPIO(B04) * 8.0;
    outputs[TRIG6_OUTPUT].value = firmware.getGPIO(B05) * 8.0;
    outputs[TRIG7_OUTPUT].value = firmware.getGPIO(B06) * 8.0;
    outputs[TRIG8_OUTPUT].value = firmware.getGPIO(B07) * 8.0;
}

