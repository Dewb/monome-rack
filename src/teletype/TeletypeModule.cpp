#include "TeletypeModule.hpp"
#include "scene/TeletypeSceneIO.hpp"
#include "screen/EngineStoppedScreen.hpp"

#include <string.h>

#define TO_Q15(x) ((x) << 15)
#define FROM_Q15(x) ((((x) >> 14) + 1) >> 1)

struct TTParamQuantity : rack::engine::ParamQuantity
{
    std::string getDisplayValueString() override
    {
        float v = getDisplayValue();
        if (std::isnan(v))
            return "NaN";

        // Calculate the same value that the TT firmware will calculate from this voltage.
        // 0-10V 12-bit ADC, shifted left 2 bits (to 0-16380), then scaled to 0-16383 in Q15 fixed-point
        uint16_t rawval = ((uint16_t)(v * 0.1f * 4095.0f) & 0xFFF) << 2;
        return rack::string::f("%d", FROM_Q15(TO_Q15(16383) / 16380 * rawval));
    }

    void setDisplayValue(float dv) override
    {
        // Reverse the above calc to set the float voltage that the ADC will turn into the given value
        uint16_t val = rack::math::clamp((int)floor(dv), 0, 16383);
        uint16_t rawval = FROM_Q15(TO_Q15(16380) / 16383 * val);
        // Add the same 12-bit sampling error correction offset here
        setImmediateValue(rawval * (10.0 / 16380.0) + 0.0007);
    }
};

TeletypeModule::TeletypeModule()
: LibAVR32Module("teletype", "teletype4")
, _iiDevice(this)
, screenBuffer{}
{
    // initialize screen with "engine stopped" message
    memcpy(screenBuffer, engineStoppedScreen, 128 * 40 * sizeof(uint8_t));

    firmware.setScreenBuffer(getScreenBuffer());

    config(NUM_PARAMS, NUM_INPUTS, NUM_OUTPUTS, NUM_LIGHTS);
    configParam<TTParamQuantity>(PARAM_PARAM, 0.0, 10.0, 5.0, "PARAM", "");
    configButton(BUTTON_PARAM, "SCENE");
    configInput(IN_INPUT, "IN");
    configInput(TRIG1_INPUT, "TRIGGER 1");
    configInput(TRIG2_INPUT, "TRIGGER 2");
    configInput(TRIG3_INPUT, "TRIGGER 3");
    configInput(TRIG4_INPUT, "TRIGGER 4");
    configInput(TRIG5_INPUT, "TRIGGER 5");
    configInput(TRIG6_INPUT, "TRIGGER 6");
    configInput(TRIG7_INPUT, "TRIGGER 7");
    configInput(TRIG8_INPUT, "TRIGGER 8");
    configOutput(TR1_OUTPUT, "TR 1");
    configOutput(TR2_OUTPUT, "TR 2");
    configOutput(TR3_OUTPUT, "TR 3");
    configOutput(TR4_OUTPUT, "TR 4");
    configOutput(CV1_OUTPUT, "CV 1");
    configOutput(CV2_OUTPUT, "CV 2");
    configOutput(CV3_OUTPUT, "CV 3");
    configOutput(CV4_OUTPUT, "CV 4");
    configButton(USB_PARAM, "USB Device Port");

    setDeviceConnectionParam(USB_PARAM);
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
    firmware.setADC(0, voltsToAdc(inputs[IN_INPUT].getVoltage()));

    for (int i = 0; i < 8; i++)
    {
        inputTriggers[i].process(
            inputs[TRIG1_INPUT + i].getVoltage(),
            triggerLowThreshold,
            triggerHighThreshold);

        firmware.setGPIO(A00 + i, inputTriggers[i].isHigh());
    }

    // for (const auto& [key, value] : iiBus::FollowerData)
    // {
    //     firmware.iiUpdateFollowerData(key, value.load(std::memory_order_relaxed));
    // }

    // iiCommand msg;
    // while (firmware.iiPopMessage(&msg.address, msg.data, &msg.length))  {
    //     _iiDevice.transmit(msg);
    // }
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
    lights[TR1_LIGHT].setSmoothBrightness(tr1, args.sampleTime);
    lights[TR2_LIGHT].setSmoothBrightness(tr2, args.sampleTime);
    lights[TR3_LIGHT].setSmoothBrightness(tr3, args.sampleTime);
    lights[TR4_LIGHT].setSmoothBrightness(tr4, args.sampleTime);
    lights[CV1_LIGHT].setSmoothBrightness(cv1 / 10.0, args.sampleTime);
    lights[CV2_LIGHT].setSmoothBrightness(cv2 / 10.0, args.sampleTime);
    lights[CV3_LIGHT].setSmoothBrightness(cv3 / 10.0, args.sampleTime);
    lights[CV4_LIGHT].setSmoothBrightness(cv4 / 10.0, args.sampleTime);

    // Update TR outs from GPIO (8V)
    outputs[TR1_OUTPUT].setVoltage(tr1 * 8.0);
    outputs[TR2_OUTPUT].setVoltage(tr2 * 8.0);
    outputs[TR3_OUTPUT].setVoltage(tr3 * 8.0);
    outputs[TR4_OUTPUT].setVoltage(tr4 * 8.0);

    // Update CV outs from DAC
    outputs[CV1_OUTPUT].setVoltage(cv1);
    outputs[CV2_OUTPUT].setVoltage(cv2);
    outputs[CV3_OUTPUT].setVoltage(cv3);
    outputs[CV4_OUTPUT].setVoltage(cv4);
}

json_t* TeletypeModule::dataToJson()
{
    json_t* rootJ = LibAVR32Module::dataToJson();

    json_object_set_new(rootJ, "theme", json_integer(theme));

    return rootJ;
}

void TeletypeModule::dataFromJson(json_t* rootJ)
{
    LibAVR32Module::dataFromJson(rootJ);

    auto json_theme = json_object_get(rootJ, "theme");
    if (json_theme)
    {
        theme = static_cast<GridTheme>(json_integer_value(json_theme));
    }

    // Special json key only in factory presets, not saved in dataToJson
    json_t* jd = json_object_get(rootJ, "loadScript");
    if (jd)
    {
        json_t* scriptDataJson = json_object_get(jd, "data");
        json_t* jsonActive = json_object_get(jd, "active");
        json_t* jsonFlash = json_object_get(jd, "flash");

        bool loadActive = jsonActive && json_is_true(jsonActive);
        bool loadFlash = jsonFlash && json_is_number(jsonFlash);

        if ((loadActive || loadFlash) && scriptDataJson && json_is_string(scriptDataJson))
        {
            std::string script = json_string_value(scriptDataJson);
            reloadFirmware(false);

            if (loadActive)
            {
                TeletypeSceneIO::presetImportString(this, script, 255, true);
            }

            if (loadFlash)
            {
                int num = json_integer_value(jsonFlash);
                if (num >= 0 && num < 32)
                {
                    TeletypeSceneIO::presetImportString(this, script, num, true);
                }
            }

            // send an ESC press/release to open preset description
            firmware.hidMessage(0x29, 0, false, false);
            firmware.hidMessage(0x29, 0, false, true);
        }
    }
}