#include "LibAVR32Module.hpp"

#pragma once

struct EarthseaModule : LibAVR32Module
{
    enum ParamIds
    {
        CV1_PARAM,
        CV2_PARAM,
        CV3_PARAM,
        BUTTON_PARAM,
        USB_PARAM,
        NUM_PARAMS
    };

    enum InputIds
    {
        NUM_INPUTS
    };

    enum OutputIds
    {
        CV1_OUTPUT,
        CV2_OUTPUT,
        CV3_OUTPUT,
        POS_OUTPUT,
        EDGE_OUTPUT,
        NUM_OUTPUTS
    };

    enum LightIds
    {
        CV1_LIGHT,
        CV2_LIGHT,
        CV3_LIGHT,
        POS_LIGHT,
        EDGE_LIGHT,
        NUM_LIGHTS
    };

    EarthseaModule()
        : LibAVR32Module("earthsea")
    {
        config(NUM_PARAMS, NUM_INPUTS, NUM_OUTPUTS, NUM_LIGHTS);

        configButton(BUTTON_PARAM, "PRESET");
        configParam(CV1_PARAM, 0, 10.0, 5.0, "SHAPE 1", "V");
        configParam(CV2_PARAM, 0, 10.0, 5.0, "SHAPE 2", "V");
        configParam(CV3_PARAM, 0, 10.0, 5.0, "SHAPE 3", "V");
        configOutput(CV1_OUTPUT, "SHAPE 1");
        configOutput(CV2_OUTPUT, "SHAPE 2");
        configOutput(CV3_OUTPUT, "SHAPE 3");
        configOutput(EDGE_OUTPUT, "EDGE");
        configOutput(POS_OUTPUT, "POS");
        configButton(USB_PARAM, "USB Device Port");

        setDeviceConnectionParam(USB_PARAM);
    }

    void processInputs(const ProcessArgs& args) override
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

    void processOutputs(const ProcessArgs& args) override
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
};