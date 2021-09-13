#include "EarthseaModule.hpp"
#include "CommonWidgets.hpp"

EarthseaModule::EarthseaModule()
: LibAVR32Module("earthsea")
{
    config(NUM_PARAMS, NUM_INPUTS, NUM_OUTPUTS, NUM_LIGHTS);

    configParam(BUTTON_PARAM, 0.0, 1.0, 0.0, "Presets");
    configParam(CV1_PARAM, 0.0, 1.0, 0.5, "CV 1");
    configParam(CV2_PARAM, 0.0, 1.0, 0.5, "CV 2");
    configParam(CV3_PARAM, 0.0, 1.0, 0.5, "CV 3");
}

void EarthseaModule::processInputs()
{
    bool frontButton = params[BUTTON_PARAM].getValue() == 0;
    if (frontButton != firmware.getGPIO(NMI))
    {
        firmware.setGPIO(NMI, frontButton);
        firmware.triggerInterrupt(3);
    }

    // Convert knob float parameters to 12-bit ADC values
    firmware.setADC(0, params[CV1_PARAM].getValue() * 0xFFF);
    firmware.setADC(1, params[CV2_PARAM].getValue() * 0xFFF);
    firmware.setADC(2, params[CV3_PARAM].getValue() * 0xFFF);
}

void EarthseaModule::processOutputs()
{

    // Update lights from GPIO
    lights[CV1_LIGHT].value = firmware.getDAC(2) / 65536.0;
    lights[CV2_LIGHT].value = firmware.getDAC(3) / 65536.0;
    lights[CV3_LIGHT].value = firmware.getDAC(0) / 65536.0;
    lights[POS_LIGHT].value = firmware.getDAC(1) / 65536.0;
    lights[EDGE_LIGHT].setBrightness(firmware.getGPIO(B00));

    // Update output jacks from GPIO & DAC
    outputs[CV1_OUTPUT].setVoltage(10.0 * firmware.getDAC(2) / 65536.0);
    outputs[CV2_OUTPUT].setVoltage(10.0 * firmware.getDAC(3) / 65536.0);
    outputs[CV3_OUTPUT].setVoltage(10.0 * firmware.getDAC(0) / 65536.0);
    outputs[POS_OUTPUT].setVoltage(10.0 * firmware.getDAC(1) / 65536.0);
    outputs[EDGE_OUTPUT].setVoltage(firmware.getGPIO(B00) * 8.0);
}
