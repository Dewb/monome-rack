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
: LibAVR32Module("teletype")
, _iiDevice(this)
{
    config(NUM_PARAMS, NUM_INPUTS, NUM_OUTPUTS, NUM_LIGHTS);
    configParam(BUTTON_PARAM, 0.0, 1.0, 0.0, "Presets");
    configParam(PARAM_PARAM, 0.0, 10.0, 5.0, "Param");
}

void TeletypeModule::processInputs(const ProcessArgs& args)
{
    bool frontButton = params[BUTTON_PARAM].getValue() == 0;
    if (frontButton != firmware.getGPIO(NMI))
    {
        firmware.setGPIO(NMI, frontButton);
        firmware.triggerInterrupt(3);
    }

    // Convert knob float parameters to 12-bit ADC values
    firmware.setADC(1, voltsToAdc(params[PARAM_PARAM].getValue()));
    firmware.setADC(0, voltsToAdc(inputs[CV_INPUT].getVoltage()));

    firmware.setGPIO(A00, isTriggered(inputs[TRIG1_INPUT].getVoltage()));
    firmware.setGPIO(A01, isTriggered(inputs[TRIG2_INPUT].getVoltage()));
    firmware.setGPIO(A02, isTriggered(inputs[TRIG3_INPUT].getVoltage()));
    firmware.setGPIO(A03, isTriggered(inputs[TRIG4_INPUT].getVoltage()));
    firmware.setGPIO(A04, isTriggered(inputs[TRIG5_INPUT].getVoltage()));
    firmware.setGPIO(A05, isTriggered(inputs[TRIG6_INPUT].getVoltage()));
    firmware.setGPIO(A06, isTriggered(inputs[TRIG7_INPUT].getVoltage()));
    firmware.setGPIO(A07, isTriggered(inputs[TRIG8_INPUT].getVoltage()));

    for (const auto & [ key, value ] : iiBus::FollowerData)
    {
        firmware.iiUpdateFollowerData(key, value.load(std::memory_order_relaxed));
    }

    iiCommand msg;
    while (firmware.iiPopMessage(&msg.address, msg.data, &msg.length))  {
        _iiDevice.transmit(msg);
    }
}

void TeletypeModule::processOutputs(const ProcessArgs& args)
{
    float cv1 = dacToVolts(firmware.getDAC(2));
    float cv2 = dacToVolts(firmware.getDAC(3));
    float cv3 = dacToVolts(firmware.getDAC(0));
    float cv4 = dacToVolts(firmware.getDAC(1));

    bool tr1 = firmware.getGPIO(B08);
    bool tr2 = firmware.getGPIO(B09);
    bool tr3 = firmware.getGPIO(B10);
    bool tr4 = firmware.getGPIO(B11);

    // Update lights
    lights[TRIGA_LIGHT].setSmoothBrightness(tr1, args.sampleTime);
    lights[TRIGB_LIGHT].setSmoothBrightness(tr2, args.sampleTime);
    lights[TRIGC_LIGHT].setSmoothBrightness(tr3, args.sampleTime);
    lights[TRIGD_LIGHT].setSmoothBrightness(tr4, args.sampleTime);
    lights[CV1_LIGHT].setSmoothBrightness(cv1 / 10.0, args.sampleTime);
    lights[CV2_LIGHT].setSmoothBrightness(cv2 / 10.0, args.sampleTime);
    lights[CV3_LIGHT].setSmoothBrightness(cv3 / 10.0, args.sampleTime);
    lights[CV4_LIGHT].setSmoothBrightness(cv4 / 10.0, args.sampleTime);

    // Update TR outs from GPIO (8V)
    outputs[TRIGA_OUTPUT].setVoltage(tr1 * 8.0);
    outputs[TRIGB_OUTPUT].setVoltage(tr2 * 8.0);
    outputs[TRIGC_OUTPUT].setVoltage(tr3 * 8.0);
    outputs[TRIGD_OUTPUT].setVoltage(tr4 * 8.0);

    // Update CV outs from DAC
    outputs[CV1_OUTPUT].setVoltage(cv1);
    outputs[CV2_OUTPUT].setVoltage(cv2);
    outputs[CV3_OUTPUT].setVoltage(cv3);
    outputs[CV4_OUTPUT].setVoltage(cv4);

    firmware.copyScreenBuffer(screenBuffer);
}
