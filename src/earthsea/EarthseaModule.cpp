#include "EarthseaModule.hpp"
#include "CommonWidgets.hpp"

EarthseaModule::EarthseaModule()
: LibAVR32Module("earthsea")
{
    config(NUM_PARAMS, NUM_INPUTS, NUM_OUTPUTS, NUM_LIGHTS);

    configParam(BUTTON_PARAM, 0.0, 1.0, 0.0, "Presets");
    configParam(CV1_PARAM, 0.0, 10.0, 5.0, "CV 1");
    configParam(CV2_PARAM, 0.0, 10.0, 5.0, "CV 2");
    configParam(CV3_PARAM, 0.0, 10.0, 5.0, "CV 3");
}

void EarthseaModule::processInputs(const ProcessArgs& args)
{
    bool frontButton = params[BUTTON_PARAM].getValue() == 0;
    if (frontButton != firmware.getGPIO(NMI))
    {
        firmware.setGPIO(NMI, frontButton);
        firmware.triggerInterrupt(3);
    }

    // Convert knob float parameters to 12-bit ADC values
    firmware.setADC(0, voltsToAdc(params[CV1_PARAM].getValue()));
    firmware.setADC(1, voltsToAdc(params[CV2_PARAM].getValue()));
    firmware.setADC(2, voltsToAdc(params[CV3_PARAM].getValue()));
}

void EarthseaModule::processOutputs(const ProcessArgs& args)
{
    float cv1 = dacToVolts(firmware.getDAC(2));
    float cv2 = dacToVolts(firmware.getDAC(3));
    float cv3 = dacToVolts(firmware.getDAC(0));
    float pos = dacToVolts(firmware.getDAC(1));
    bool edge = firmware.getGPIO(B00);

    // Update lights from DAC and GPIO
    lights[CV1_LIGHT].setSmoothBrightness(cv1 / 10.0, args.sampleTime);
    lights[CV2_LIGHT].setSmoothBrightness(cv2 / 10.0, args.sampleTime);
    lights[CV3_LIGHT].setSmoothBrightness(cv3 / 10.0, args.sampleTime);
    lights[POS_LIGHT].setSmoothBrightness(pos / 10.0, args.sampleTime);
    lights[EDGE_LIGHT].setSmoothBrightness(edge, args.sampleTime);

    // Update output jacks from GPIO & DAC
    outputs[CV1_OUTPUT].setVoltage(cv1);
    outputs[CV2_OUTPUT].setVoltage(cv2);
    outputs[CV3_OUTPUT].setVoltage(cv3);
    outputs[POS_OUTPUT].setVoltage(pos);
    outputs[EDGE_OUTPUT].setVoltage(edge * 8.0);
}
