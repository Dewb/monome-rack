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
    if (cv1Normal != firmware.getGPIO(B10))
    {
        firmware.setGPIO(B10, cv1Normal);
        firmware.triggerInterrupt(1);
    }
    bool input1 = inputs[IN1_INPUT].getVoltage() > 0;
    if (input1 != firmware.getGPIO(B08))
    {
        firmware.setGPIO(B08, input1);
        firmware.triggerInterrupt(6);
    }
    bool input2 = inputs[IN2_INPUT].getVoltage() > 0;
    if (input2 != firmware.getGPIO(B09))
    {
        firmware.setGPIO(B09, input2);
        firmware.triggerInterrupt(7);
    }
    bool key1Button = params[KEY1_PARAM].getValue() == 0;
    if (key1Button != firmware.getGPIO(B06))
    {
        firmware.setGPIO(B06, key1Button);
        firmware.triggerInterrupt(4);
    }
    bool key2Button = params[KEY2_PARAM].getValue() == 0;
    if (key2Button != firmware.getGPIO(B07))
    {
        firmware.setGPIO(B07, key2Button);
        firmware.triggerInterrupt(5);
    }
    bool modeButton = params[MODE_PARAM].getValue() == 0;
    if (modeButton != firmware.getGPIO(NMI))
    {
        firmware.setGPIO(NMI, modeButton);
        if (modeButton)
        {
            firmware.triggerInterrupt(3);
        }
    }
}

void AnsibleModule::processOutputs()
{
    // Update lights from GPIO (B00/B01 -> single bicolor LED)
    lights[MODE_YELLOW_LIGHT].setSmoothBrightness(firmware.getGPIO(B00) * 0.7, 1.f);
    lights[MODE_WHITE_LIGHT].setSmoothBrightness(firmware.getGPIO(B01) * 0.4, 1.f);

    lights[TR1_LIGHT].setSmoothBrightness(firmware.getGPIO(B02), 0.3f);
    lights[TR2_LIGHT].setSmoothBrightness(firmware.getGPIO(B03), 0.3f);
    lights[TR3_LIGHT].setSmoothBrightness(firmware.getGPIO(B04), 0.3f);
    lights[TR4_LIGHT].setSmoothBrightness(firmware.getGPIO(B05), 0.3f);
    lights[CV1_LIGHT].setSmoothBrightness(10.0 * firmware.getDAC(2) / 65536.0, 0.3f);
    lights[CV2_LIGHT].setSmoothBrightness(10.0 * firmware.getDAC(3) / 65536.0, 0.3f);
    lights[CV3_LIGHT].setSmoothBrightness(10.0 * firmware.getDAC(0) / 65536.0, 0.3f);
    lights[CV4_LIGHT].setSmoothBrightness(10.0 * firmware.getDAC(1) / 65536.0, 0.3f);

    // Update output jacks from GPIO & DAC
    outputs[TR1_OUTPUT].setVoltage(firmware.getGPIO(B02) * 8.0);
    outputs[TR2_OUTPUT].setVoltage(firmware.getGPIO(B03) * 8.0);
    outputs[TR3_OUTPUT].setVoltage(firmware.getGPIO(B04) * 8.0);
    outputs[TR4_OUTPUT].setVoltage(firmware.getGPIO(B05) * 8.0);
    outputs[CV1_OUTPUT].setVoltage(10.0 * firmware.getDAC(2) / 65536.0);
    outputs[CV2_OUTPUT].setVoltage(10.0 * firmware.getDAC(3) / 65536.0);
    outputs[CV3_OUTPUT].setVoltage(10.0 * firmware.getDAC(0) / 65536.0);
    outputs[CV4_OUTPUT].setVoltage(10.0 * firmware.getDAC(1) / 65536.0);
}
