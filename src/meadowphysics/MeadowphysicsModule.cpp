#include "MeadowphysicsModule.hpp"
#include "Clock12BitParam.hpp"

MeadowphysicsModule::MeadowphysicsModule()
: LibAVR32Module("meadowphysics")
{
    config(NUM_PARAMS, NUM_INPUTS, NUM_OUTPUTS, NUM_LIGHTS);
    configButton(BUTTON_PARAM, "PRESET");
    configParam<Clock12BitParam<1, CLOCK_INPUT>>(CLOCK_PARAM, 0.0, 10.0, 5.0, "CLOCK", "ms");
    configInput(CLOCK_INPUT, "CLOCK");
    configOutput(CLOCK_OUTPUT, "CLOCK");
    configOutput(TR1_OUTPUT, "TR 1");
    configOutput(TR2_OUTPUT, "TR 2");
    configOutput(TR3_OUTPUT, "TR 3");
    configOutput(TR4_OUTPUT, "TR 4");
    configOutput(TR5_OUTPUT, "TR 5");
    configOutput(TR6_OUTPUT, "TR 6");
    configOutput(TR7_OUTPUT, "TR 7");
    configOutput(TR8_OUTPUT, "TR 8");
    configButton(USB_PARAM, "USB Device Port");

    setDeviceConnectionParam(USB_PARAM);
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

    clockTrigger.process(inputs[CLOCK_INPUT].getVoltage(), triggerLowThreshold, triggerHighThreshold);
    bool externalClock = clockTrigger.isHigh();
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
    lights[TR1_LIGHT].setSmoothBrightness(firmware.getGPIO(B00), args.sampleTime);
    lights[TR2_LIGHT].setSmoothBrightness(firmware.getGPIO(B01), args.sampleTime);
    lights[TR3_LIGHT].setSmoothBrightness(firmware.getGPIO(B02), args.sampleTime);
    lights[TR4_LIGHT].setSmoothBrightness(firmware.getGPIO(B03), args.sampleTime);
    lights[TR5_LIGHT].setSmoothBrightness(firmware.getGPIO(B04), args.sampleTime);
    lights[TR6_LIGHT].setSmoothBrightness(firmware.getGPIO(B05), args.sampleTime);
    lights[TR7_LIGHT].setSmoothBrightness(firmware.getGPIO(B06), args.sampleTime);
    lights[TR8_LIGHT].setSmoothBrightness(firmware.getGPIO(B07), args.sampleTime);

    // Update output jacks from GPIO
    outputs[CLOCK_OUTPUT].setVoltage(firmware.getGPIO(B10) * 8.0);
    outputs[TR1_OUTPUT].setVoltage(firmware.getGPIO(B00) * 8.0);
    outputs[TR2_OUTPUT].setVoltage(firmware.getGPIO(B01) * 8.0);
    outputs[TR3_OUTPUT].setVoltage(firmware.getGPIO(B02) * 8.0);
    outputs[TR4_OUTPUT].setVoltage(firmware.getGPIO(B03) * 8.0);
    outputs[TR5_OUTPUT].setVoltage(firmware.getGPIO(B04) * 8.0);
    outputs[TR6_OUTPUT].setVoltage(firmware.getGPIO(B05) * 8.0);
    outputs[TR7_OUTPUT].setVoltage(firmware.getGPIO(B06) * 8.0);
    outputs[TR8_OUTPUT].setVoltage(firmware.getGPIO(B07) * 8.0);
}
