#pragma once

#include "LibAVR32Module.hpp"
#include "Clock12BitParam.hpp"

struct WhiteWhaleModule : LibAVR32Module
{
    enum ParamIds
    {
        CLOCK_PARAM,
        PARAM_PARAM,
        BUTTON_PARAM,
        USB_PARAM,
        NUM_PARAMS
    };

    enum InputIds
    {
        CLOCK_INPUT,
        NUM_INPUTS
    };

    enum OutputIds
    {
        CLOCK_OUTPUT,
        TR1_OUTPUT,
        TR2_OUTPUT,
        TR3_OUTPUT,
        TR4_OUTPUT,
        CVA_OUTPUT,
        CVB_OUTPUT,
        NUM_OUTPUTS
    };

    enum LightIds
    {
        CLOCK_LIGHT,
        TR1_LIGHT,
        TR2_LIGHT,
        TR3_LIGHT,
        TR4_LIGHT,
        CVA_LIGHT,
        CVB_LIGHT,
        NUM_LIGHTS
    };

    rack::dsp::SchmittTrigger clockTrigger;

    WhiteWhaleModule()
        : LibAVR32Module("whitewhale")
    {
        config(NUM_PARAMS, NUM_INPUTS, NUM_OUTPUTS, NUM_LIGHTS);
        configButton(BUTTON_PARAM, "PRESET");
        configParam(PARAM_PARAM, 0.0, 10.0, 5.0, "PARAM");
        configParam<Clock12BitParam<2>>(CLOCK_PARAM, 0.0, 10.0, 5.0, "CLOCK", "ms");
        configInput(CLOCK_INPUT, "CLOCK");
        configOutput(CLOCK_OUTPUT, "CLOCK");
        configOutput(TR1_OUTPUT, "TR 1");
        configOutput(TR2_OUTPUT, "TR 2");
        configOutput(TR3_OUTPUT, "TR 3");
        configOutput(TR4_OUTPUT, "TR 4");
        configOutput(CVA_OUTPUT, "CV A");
        configOutput(CVB_OUTPUT, "CV B");
        configButton(USB_PARAM, "USB Device Port");

        setDeviceConnectionParam(USB_PARAM);
    }

    void processInputs(const ProcessArgs& args)
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
        firmware.setADC(1, voltsToAdc(params[PARAM_PARAM].getValue()));
    }

    void processOutputs(const ProcessArgs& args)
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
        lights[TR1_LIGHT].setSmoothBrightness(tr1, args.sampleTime);
        lights[TR2_LIGHT].setSmoothBrightness(tr2, args.sampleTime);
        lights[TR3_LIGHT].setSmoothBrightness(tr3, args.sampleTime);
        lights[TR4_LIGHT].setSmoothBrightness(tr4, args.sampleTime);
        lights[CVA_LIGHT].setSmoothBrightness(cv1 / 10.0, args.sampleTime);
        lights[CVB_LIGHT].setSmoothBrightness(cv2 / 10.0, args.sampleTime);

        // Update output jacks from GPIO & DAC
        outputs[CLOCK_OUTPUT].setVoltage(clock * 8.0);
        outputs[TR1_OUTPUT].setVoltage(tr1 * 8.0);
        outputs[TR2_OUTPUT].setVoltage(tr2 * 8.0);
        outputs[TR3_OUTPUT].setVoltage(tr3 * 8.0);
        outputs[TR4_OUTPUT].setVoltage(tr4 * 8.0);
        outputs[CVA_OUTPUT].setVoltage(cv1);
        outputs[CVB_OUTPUT].setVoltage(cv2);
    }
};