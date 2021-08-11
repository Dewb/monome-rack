#include "TeletypeModule.hpp"

#include <string.h>

#define A00 0
#define A01 1
#define A02 2
#define A03 3
#define A04 4
#define A05 5
#define A06 6
#define A07 7
#define B00 32
#define B01 33
#define B02 34
#define B03 35
#define B04 36
#define B05 37
#define B06 38
#define B07 39
#define B08 40
#define B09 41
#define B10 42
#define B11 43
#define NMI 13

TeletypeModule::TeletypeModule()
{
    config(NUM_PARAMS, NUM_INPUTS, NUM_OUTPUTS, NUM_LIGHTS);
    configParam(BUTTON_PARAM, 0.0, 1.0, 0.0, "Presets");
    configParam(PARAM_PARAM, 0.0, 1.0, 0.5, "Param");

    firmware.load("teletype");
    firmware.init();
}

void TeletypeModule::processInputs()
{
    bool frontButton = params[BUTTON_PARAM].getValue() == 0;
    if (frontButton != firmware.getGPIO(NMI))
    {
        firmware.setGPIO(NMI, frontButton);
        firmware.triggerInterrupt(3);
    }

    // Convert knob float parameters to 12-bit ADC values
    firmware.setADC(1, params[PARAM_PARAM].getValue() * 0xFFF);

    firmware.setADC(0, (uint16_t)((math::rescale(math::clamp(inputs[CV_INPUT].getVoltage(), 0.0, 10.0), 0.0, 10.0, 0, 1.0) * 0xFFF)));

    firmware.setGPIO(A00, inputs[TRIG1_INPUT].getVoltage() > 0);
    firmware.setGPIO(A01, inputs[TRIG2_INPUT].getVoltage() > 0);
    firmware.setGPIO(A02, inputs[TRIG3_INPUT].getVoltage() > 0);
    firmware.setGPIO(A03, inputs[TRIG4_INPUT].getVoltage() > 0);
    firmware.setGPIO(A04, inputs[TRIG5_INPUT].getVoltage() > 0);
    firmware.setGPIO(A05, inputs[TRIG6_INPUT].getVoltage() > 0);
    firmware.setGPIO(A06, inputs[TRIG7_INPUT].getVoltage() > 0);
    firmware.setGPIO(A07, inputs[TRIG8_INPUT].getVoltage() > 0);
}

void TeletypeModule::processOutputs()
{
    // Update lights from GPIO
    lights[TRIGA_LIGHT].setBrightness(firmware.getGPIO(B08));
    lights[TRIGB_LIGHT].setBrightness(firmware.getGPIO(B09));
    lights[TRIGC_LIGHT].setBrightness(firmware.getGPIO(B10));
    lights[TRIGD_LIGHT].setBrightness(firmware.getGPIO(B11));
    lights[CV1_LIGHT].value = firmware.getDAC(2) / 65536.0;
    lights[CV2_LIGHT].value = firmware.getDAC(3) / 65536.0;
    lights[CV3_LIGHT].value = firmware.getDAC(0) / 65536.0;
    lights[CV4_LIGHT].value = firmware.getDAC(1) / 65536.0;

    // Update output jacks from GPIO & DAC
    outputs[TRIGA_OUTPUT].value = firmware.getGPIO(B08) * 8.0;
    outputs[TRIGB_OUTPUT].value = firmware.getGPIO(B09) * 8.0;
    outputs[TRIGC_OUTPUT].value = firmware.getGPIO(B10) * 8.0;
    outputs[TRIGD_OUTPUT].value = firmware.getGPIO(B11) * 8.0;
    outputs[CV1_OUTPUT].value = 10.0 * firmware.getDAC(2) / 65536.0;
    outputs[CV2_OUTPUT].value = 10.0 * firmware.getDAC(3) / 65536.0;
    outputs[CV3_OUTPUT].value = 10.0 * firmware.getDAC(0) / 65536.0;
    outputs[CV4_OUTPUT].value = 10.0 * firmware.getDAC(1) / 65536.0;
}
