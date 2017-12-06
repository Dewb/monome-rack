#include "teletype.hpp"
#include "firmwaremanager.hpp"
#include "grid.hpp"
#include "monomewidgets.hpp"

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

struct Teletype : MonomeModuleBase
{
    FirmwareManager firmware;

    enum ParamIds
    {
        PARAM_PARAM,
        BUTTON_PARAM,
        NUM_PARAMS
    };
    enum InputIds
    {
        TRIG1_INPUT,
        TRIG2_INPUT,
        TRIG3_INPUT,
        TRIG4_INPUT,
        TRIG5_INPUT,
        TRIG6_INPUT,
        TRIG7_INPUT,
        TRIG8_INPUT,
        CV_INPUT,
        NUM_INPUTS
    };
    enum OutputIds
    {
        TRIGA_OUTPUT,
        TRIGB_OUTPUT,
        TRIGC_OUTPUT,
        TRIGD_OUTPUT,
        CV1_OUTPUT,
        CV2_OUTPUT,
        CV3_OUTPUT,
        CV4_OUTPUT,
        NUM_OUTPUTS
    };
    enum LightIds
    {
        TRIGA_LIGHT,
        TRIGB_LIGHT,
        TRIGC_LIGHT,
        TRIGD_LIGHT,
        CV1_LIGHT,
        CV2_LIGHT,
        CV3_LIGHT,
        CV4_LIGHT,
        NUM_LIGHTS
    };

    Teletype()
        : MonomeModuleBase(NUM_PARAMS, NUM_INPUTS, NUM_OUTPUTS, NUM_LIGHTS)
    {
    }

    void step() override;

    json_t* toJson() override
    {
        json_t* rootJ = MonomeModuleBase::toJson();
        //json_object_set_new(rootJ, "current", json_string(base64_encode((unsigned char*)&w, sizeof(whale_set)).c_str()));
        //json_object_set_new(rootJ, "flash", json_string(base64_encode((unsigned char*)&flashy, sizeof(nvram_data_t)).c_str()));
        return rootJ;
    }

    void fromJson(json_t* rootJ) override
    {
        MonomeModuleBase::fromJson(rootJ);
        //memcpy((void*)&w, base64_decode(json_string_value(json_object_get(rootJ, "current"))).c_str(), sizeof(whale_set));
        //memcpy((void*)&flashy, base64_decode(json_string_value(json_object_get(rootJ, "flash"))).c_str(), sizeof(nvram_data_t));
    }
};

void Teletype::step()
{
    MonomeModuleBase::step();

    bool frontButton = params[BUTTON_PARAM].value == 0;
    if (frontButton != firmware.getGPIO(NMI))
    {
        firmware.setGPIO(NMI, frontButton);
        firmware.triggerInterrupt(2);
    }

    // Convert knob float parameters to 12-bit ADC values
    firmware.setADC(0, params[PARAM_PARAM].value * 0xFFF);

    firmware.setGPIO(A00, inputs[TRIG1_INPUT].value);
    firmware.setGPIO(A01, inputs[TRIG2_INPUT].value);
    firmware.setGPIO(A02, inputs[TRIG3_INPUT].value);
    firmware.setGPIO(A03, inputs[TRIG4_INPUT].value);
    firmware.setGPIO(A04, inputs[TRIG5_INPUT].value);
    firmware.setGPIO(A05, inputs[TRIG6_INPUT].value);
    firmware.setGPIO(A06, inputs[TRIG7_INPUT].value);
    firmware.setGPIO(A07, inputs[TRIG8_INPUT].value);

    // Advance software timers
    firmware.advanceClock(engineGetSampleTime());

    // Pump event loop
    //check_events();

    // Update lights from GPIO
    lights[TRIGA_LIGHT].setBrightnessSmooth(firmware.getGPIO(B08));
    lights[TRIGB_LIGHT].setBrightnessSmooth(firmware.getGPIO(B09));
    lights[TRIGC_LIGHT].setBrightnessSmooth(firmware.getGPIO(B10));
    lights[TRIGD_LIGHT].setBrightnessSmooth(firmware.getGPIO(B11));
    lights[CV1_LIGHT].value = firmware.getDAC(0) / 65536.0;
    lights[CV2_LIGHT].value = firmware.getDAC(1) / 65536.0;
    lights[CV3_LIGHT].value = firmware.getDAC(0) / 65536.0;
    lights[CV4_LIGHT].value = firmware.getDAC(1) / 65536.0;

    // Update output jacks from GPIO & DAC
    outputs[TRIGA_OUTPUT].value = firmware.getGPIO(B08) * 8.0;
    outputs[TRIGB_OUTPUT].value = firmware.getGPIO(B09) * 8.0;
    outputs[TRIGC_OUTPUT].value = firmware.getGPIO(B10) * 8.0;
    outputs[TRIGD_OUTPUT].value = firmware.getGPIO(B11) * 8.0;
    outputs[CV1_OUTPUT].value = 10.0 * firmware.getDAC(0) / 65536.0;
    outputs[CV2_OUTPUT].value = 10.0 * firmware.getDAC(1) / 65536.0;
    outputs[CV3_OUTPUT].value = 10.0 * firmware.getDAC(0) / 65536.0;
    outputs[CV4_OUTPUT].value = 10.0 * firmware.getDAC(1) / 65536.0;

    // Update LEDs on connected grid
    if (gridConnection)
    {
        uint8_t* msg = firmware.readSerial(0);
        while (msg)
        {
            if (msg[0] == 0x1A)
            {
                // Grid quadrant update
                uint8_t x = msg[1];
                uint8_t y = msg[2];
                uint8_t leds[64];
                for (int i = 0; i < 32; i++)
                {
                    leds[2 * i + 0] = msg[3 + i] >> 4;
                    leds[2 * i + 1] = msg[3 + i] & 0xF;
                }

                // connection could be lost mid-update, re-check
                if (gridConnection)
                {
                    gridConnection->updateQuadrant(x, y, leds);
                }
            }
            msg = firmware.readSerial(0);
        }
    }
}

struct TeletypeScreen : OpaqueWidget
{
    void draw(NVGcontext* vg) override
    {
        nvgBeginPath(vg);
        nvgRect(vg, 0, 0, 208, 107);
        nvgFillColor(vg, nvgRGB(0, 0, 0));
        nvgFill(vg);
    }
};

TeletypeWidget::TeletypeWidget()
{
    Teletype* module = new Teletype();
    setModule(module);
    box.size = Vec(15 * 18, 380);

    {
        auto panel = new LightPanel();
        panel->box.size = box.size;
        addChild(panel);
    }

    addChild(createScrew<ScrewSilver>(Vec(15, 0)));
    addChild(createScrew<ScrewSilver>(Vec(15, 365)));
    addChild(createScrew<ScrewSilver>(Vec(239, 0)));
    addChild(createScrew<ScrewSilver>(Vec(239, 365)));

    addChild(createScrew<USBAJack>(Vec(10, 337)));
    addParam(createParam<TL1105>(Vec(62, 337), module, Teletype::BUTTON_PARAM, 0.0, 1.0, 0.0));

    addChild(createScrew<ScrewSilver>(Vec(11, 312)));
    addChild(createScrew<ScrewSilver>(Vec(244, 312)));

    addChild(createScrew<TeletypeScreen>(Vec(31, 202)));

    addParam(createParam<RoundSmallBlackKnob>(Vec(220, 56), module, Teletype::PARAM_PARAM, 0.0, 1.0, 0.5));

    addChild(createLight<MediumLight<YellowLight>>(Vec(118, 112), module, Teletype::TRIGA_LIGHT));
    addChild(createLight<MediumLight<YellowLight>>(Vec(158, 112), module, Teletype::TRIGB_LIGHT));
    addChild(createLight<MediumLight<YellowLight>>(Vec(198, 112), module, Teletype::TRIGC_LIGHT));
    addChild(createLight<MediumLight<YellowLight>>(Vec(238, 112), module, Teletype::TRIGD_LIGHT));
    addChild(createLight<MediumLight<WhiteLight>>(Vec(138, 152), module, Teletype::CV1_LIGHT));
    addChild(createLight<MediumLight<WhiteLight>>(Vec(178, 152), module, Teletype::CV2_LIGHT));
    addChild(createLight<MediumLight<WhiteLight>>(Vec(218, 152), module, Teletype::CV3_LIGHT));
    addChild(createLight<MediumLight<WhiteLight>>(Vec(258, 152), module, Teletype::CV4_LIGHT));

    addInput(createInput<PJ301MPort>(Vec(170, 36), module, Teletype::CV_INPUT));
    addInput(createInput<PJ301MPort>(Vec(10, 36), module, Teletype::TRIG1_INPUT));
    addInput(createInput<PJ301MPort>(Vec(50, 36), module, Teletype::TRIG2_INPUT));
    addInput(createInput<PJ301MPort>(Vec(90, 36), module, Teletype::TRIG3_INPUT));
    addInput(createInput<PJ301MPort>(Vec(130, 36), module, Teletype::TRIG4_INPUT));
    addInput(createInput<PJ301MPort>(Vec(30, 76), module, Teletype::TRIG5_INPUT));
    addInput(createInput<PJ301MPort>(Vec(70, 76), module, Teletype::TRIG6_INPUT));
    addInput(createInput<PJ301MPort>(Vec(110, 76), module, Teletype::TRIG7_INPUT));
    addInput(createInput<PJ301MPort>(Vec(150, 76), module, Teletype::TRIG8_INPUT));
    addOutput(createOutput<PJ301MPort>(Vec(90, 116), module, Teletype::TRIGA_OUTPUT));
    addOutput(createOutput<PJ301MPort>(Vec(130, 116), module, Teletype::TRIGB_OUTPUT));
    addOutput(createOutput<PJ301MPort>(Vec(170, 116), module, Teletype::TRIGC_OUTPUT));
    addOutput(createOutput<PJ301MPort>(Vec(210, 116), module, Teletype::TRIGD_OUTPUT));
    addOutput(createOutput<PJ301MPort>(Vec(110, 156), module, Teletype::CV1_OUTPUT));
    addOutput(createOutput<PJ301MPort>(Vec(150, 156), module, Teletype::CV2_OUTPUT));
    addOutput(createOutput<PJ301MPort>(Vec(190, 156), module, Teletype::CV3_OUTPUT));
    addOutput(createOutput<PJ301MPort>(Vec(230, 156), module, Teletype::CV4_OUTPUT));
}
