#include "EarthseaModule.hpp"
#include "MonomeWidgets.hpp"

EarthseaModule::EarthseaModule()
    : MonomeModuleBase(NUM_PARAMS, NUM_INPUTS, NUM_OUTPUTS, NUM_LIGHTS)
{
    firmware.load("./plugins/monome-rack/build/firmware/earthsea");
    firmware.init();
}

void EarthseaModule::processInputs()
{
    bool frontButton = params[BUTTON_PARAM].value == 0;
    if (frontButton != firmware.getGPIO(NMI))
    {
        firmware.setGPIO(NMI, frontButton);
        firmware.triggerInterrupt(3);
    }

    // Convert knob float parameters to 12-bit ADC values
    firmware.setADC(0, params[CV1_PARAM].value * 0xFFF);
    firmware.setADC(1, params[CV2_PARAM].value * 0xFFF);
    firmware.setADC(2, params[CV3_PARAM].value * 0xFFF);
}

void EarthseaModule::processOutputs()
{

    // Update lights from GPIO
    lights[CV1_LIGHT].value = firmware.getDAC(2) / 65536.0;
    lights[CV2_LIGHT].value = firmware.getDAC(3) / 65536.0;
    lights[CV3_LIGHT].value = firmware.getDAC(0) / 65536.0;
    lights[POS_LIGHT].value = firmware.getDAC(1) / 65536.0;
    lights[EDGE_LIGHT].setBrightnessSmooth(firmware.getGPIO(B00));

    // Update output jacks from GPIO & DAC
    outputs[CV1_OUTPUT].value = 10.0 * firmware.getDAC(2) / 65536.0;
    outputs[CV2_OUTPUT].value = 10.0 * firmware.getDAC(3) / 65536.0;
    outputs[CV3_OUTPUT].value = 10.0 * firmware.getDAC(0) / 65536.0;
    outputs[POS_OUTPUT].value = 10.0 * firmware.getDAC(1) / 65536.0;
    outputs[EDGE_OUTPUT].value = firmware.getGPIO(B00) * 8.0;
}
