#include "AnsibleModule.hpp"

AnsibleModule::AnsibleModule()
{
    config(NUM_PARAMS, NUM_INPUTS, NUM_OUTPUTS, NUM_LIGHTS);
    configParam(KEY1_PARAM, 0.0, 1.0, 0.0, "Key 1");
    configParam(KEY2_PARAM, 0.0, 1.0, 0.0, "Key 2");
    configParam(MODE_PARAM, 0.0, 1.0, 0.0, "Mode");

    firmware.load("ansible");
    firmware.init();
}

void AnsibleModule::processInputs()
{
    bool cv1Normal = !inputs[IN1_INPUT].isConnected();
    if (cv1Normal != firmware.getGPIO(B09))
    {
        firmware.setGPIO(B09, cv1Normal);
        firmware.triggerInterrupt(1);
    }
    bool cv2Normal = !inputs[IN2_INPUT].isConnected();
    if (cv2Normal != firmware.getGPIO(B10))
    {
        firmware.setGPIO(B10, cv2Normal);
        firmware.triggerInterrupt(2);
    }
    bool key1Button = params[KEY1_PARAM].getValue() == 0;
    if (key1Button != firmware.getGPIO(NMI))
    {
        firmware.setGPIO(NMI, key1Button);
        firmware.triggerInterrupt(3);
    }
    bool key2Button = params[KEY2_PARAM].getValue() == 0;
    if (key2Button != firmware.getGPIO(NMI))
    {
        firmware.setGPIO(NMI, key2Button);
        firmware.triggerInterrupt(0);
    }
}

void AnsibleModule::processOutputs()
{
    // Update lights from GPIO
    lights[MODE_LIGHT].setSmoothBrightness(firmware.getGPIO(B10), 1.f);
    lights[TR1_LIGHT].setSmoothBrightness(firmware.getGPIO(B00), 1.f);
    lights[TR2_LIGHT].setSmoothBrightness(firmware.getGPIO(B01), 1.f);
    lights[TR3_LIGHT].setSmoothBrightness(firmware.getGPIO(B02), 1.f);
    lights[TR4_LIGHT].setSmoothBrightness(firmware.getGPIO(B03), 1.f);
    lights[CV1_LIGHT].setSmoothBrightness(firmware.getGPIO(B04), 1.f);
    lights[CV2_LIGHT].setSmoothBrightness(firmware.getGPIO(B05), 1.f);
    lights[CV3_LIGHT].setSmoothBrightness(firmware.getGPIO(B06), 1.f);
    lights[CV4_LIGHT].setSmoothBrightness(firmware.getGPIO(B07), 1.f);

    // Update output jacks from GPIO & DAC
    outputs[TR1_OUTPUT].setVoltage(firmware.getGPIO(B00) * 8.0);
    outputs[TR2_OUTPUT].setVoltage(firmware.getGPIO(B01) * 8.0);
    outputs[TR3_OUTPUT].setVoltage(firmware.getGPIO(B02) * 8.0);
    outputs[TR4_OUTPUT].setVoltage(firmware.getGPIO(B03) * 8.0);
    outputs[CV1_OUTPUT].setVoltage(10.0 * firmware.getDAC(2) / 65536.0);
    outputs[CV2_OUTPUT].setVoltage(10.0 * firmware.getDAC(3) / 65536.0);
    outputs[CV3_OUTPUT].setVoltage(10.0 * firmware.getDAC(0) / 65536.0);
    outputs[CV4_OUTPUT].setVoltage(10.0 * firmware.getDAC(1) / 65536.0);
}
