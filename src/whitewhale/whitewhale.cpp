#include "whitewhale.hpp"
#include "grid.hpp"
#include "monomewidgets.hpp"

#include "base64.h"
#include <string.h>

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
#define NMI 13

struct WhiteWhale : MonomeModuleBase
{
    enum ParamIds
    {
        CLOCK_PARAM,
        PARAM_PARAM,
        BUTTON_PARAM,
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
        TRIG1_OUTPUT,
        TRIG2_OUTPUT,
        TRIG3_OUTPUT,
        TRIG4_OUTPUT,
        CVA_OUTPUT,
        CVB_OUTPUT,
        NUM_OUTPUTS
    };
    enum LightIds
    {
        CLOCK_LIGHT,
        TRIG1_LIGHT,
        TRIG2_LIGHT,
        TRIG3_LIGHT,
        TRIG4_LIGHT,
        CVA_LIGHT,
        CVB_LIGHT,
        NUM_LIGHTS
    };

    WhiteWhale()
        : MonomeModuleBase(NUM_PARAMS, NUM_INPUTS, NUM_OUTPUTS, NUM_LIGHTS)
    {
        firmware.load("./plugins/monome-rack/build/firmware/whitewhale");
        firmware.init();
    }

    void step() override;

    json_t* toJson() override
    {
        json_t* rootJ = MonomeModuleBase::toJson();

        void* data;
        uint32_t size;

        firmware.readNVRAM(&data, &size);
        json_object_set_new(rootJ, "nvram", json_string(base64_encode((unsigned char*)data, size).c_str()));

        firmware.readVRAM(&data, &size);
        json_object_set_new(rootJ, "vram", json_string(base64_encode((unsigned char*)data, size).c_str()));

        return rootJ;
    }

    void fromJson(json_t* rootJ) override
    {
        MonomeModuleBase::fromJson(rootJ);

        void* data;
        uint32_t size;
        json_t* jd;

        jd = json_object_get(rootJ, "nvram");
        if (jd)
        {
            string decoded = base64_decode(json_string_value(jd));

            firmware.readNVRAM(&data, &size);
            if (size == decoded.length())
            {
                firmware.writeNVRAM((void*)decoded.c_str(), size);
            }
        }

        jd = json_object_get(rootJ, "vram");
        if (jd)
        {
            string decoded = base64_decode(json_string_value(jd));

            firmware.readVRAM(&data, &size);
            if (size == decoded.length())
            {
                firmware.writeVRAM((void*)decoded.c_str(), size);
            }
        }
    }

    void reset() override
    {
    }

    void randomize() override
    {
    }
};

void WhiteWhale::step()
{
    MonomeModuleBase::step();

    // Convert clock input jack to GPIO signals for normal connection and value
    bool clockNormal = !inputs[CLOCK_INPUT].active;
    if (clockNormal != firmware.getGPIO(B09))
    {
        firmware.setGPIO(B09, clockNormal);
        firmware.triggerInterrupt(1);
    }
    bool externalClock = inputs[CLOCK_INPUT].value > 0;
    if (externalClock != firmware.getGPIO(B08))
    {
        firmware.setGPIO(B08, externalClock);
        firmware.triggerInterrupt(2);
    }
    bool frontButton = params[BUTTON_PARAM].value == 0;
    if (frontButton != firmware.getGPIO(NMI))
    {
        firmware.setGPIO(NMI, frontButton);
        firmware.triggerInterrupt(3);
    }

    // Convert knob float parameters to 12-bit ADC values
    firmware.setADC(0, params[CLOCK_PARAM].value * 0xFFF);
    firmware.setADC(1, params[PARAM_PARAM].value * 0xFFF);

    // Advance software timers
    firmware.advanceClock(engineGetSampleTime());

    // Pump event loop
    firmware.step();

    // Update lights from GPIO
    lights[CLOCK_LIGHT].setBrightnessSmooth(firmware.getGPIO(B10));
    lights[TRIG1_LIGHT].setBrightnessSmooth(firmware.getGPIO(B00));
    lights[TRIG2_LIGHT].setBrightnessSmooth(firmware.getGPIO(B01));
    lights[TRIG3_LIGHT].setBrightnessSmooth(firmware.getGPIO(B02));
    lights[TRIG4_LIGHT].setBrightnessSmooth(firmware.getGPIO(B03));
    lights[CVA_LIGHT].value = firmware.getDAC(0) / 65536.0;
    lights[CVB_LIGHT].value = firmware.getDAC(1) / 65536.0;

    // Update output jacks from GPIO & DAC
    outputs[CLOCK_OUTPUT].value = firmware.getGPIO(B10) * 8.0;
    outputs[TRIG1_OUTPUT].value = firmware.getGPIO(B00) * 8.0;
    outputs[TRIG2_OUTPUT].value = firmware.getGPIO(B01) * 8.0;
    outputs[TRIG3_OUTPUT].value = firmware.getGPIO(B02) * 8.0;
    outputs[TRIG4_OUTPUT].value = firmware.getGPIO(B03) * 8.0;
    outputs[CVA_OUTPUT].value = 10.0 * firmware.getDAC(0) / 65536.0;
    outputs[CVB_OUTPUT].value = 10.0 * firmware.getDAC(1) / 65536.0;

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

WhiteWhaleWidget::WhiteWhaleWidget()
{
    WhiteWhale* module = new WhiteWhale();
    setModule(module);
    box.size = Vec(15 * 6, 380);

    {
        auto panel = new LightPanel();
        panel->box.size = box.size;
        addChild(panel);
    }

    addChild(createScrew<ScrewSilver>(Vec(0, 0)));
    addChild(createScrew<ScrewSilver>(Vec(0, 365)));
    addChild(createScrew<USBAJack>(Vec(10, 337)));

    addParam(createParam<RoundSmallBlackKnob>(Vec(12, 30), module, WhiteWhale::PARAM_PARAM, 0.0, 1.0, 0.5));
    addParam(createParam<RoundSmallBlackKnob>(Vec(12, 250), module, WhiteWhale::CLOCK_PARAM, 0.0, 1.0, 0.5));

    addParam(createParam<TL1105>(Vec(62, 337), module, WhiteWhale::BUTTON_PARAM, 0.0, 1.0, 0.0));

    addChild(createLight<MediumLight<YellowLight>>(Vec(77, 286), module, WhiteWhale::CLOCK_LIGHT));
    addChild(createLight<MediumLight<YellowLight>>(Vec(77, 84), module, WhiteWhale::TRIG1_LIGHT));
    addChild(createLight<MediumLight<YellowLight>>(Vec(77, 122), module, WhiteWhale::TRIG2_LIGHT));
    addChild(createLight<MediumLight<YellowLight>>(Vec(77, 160), module, WhiteWhale::TRIG3_LIGHT));
    addChild(createLight<MediumLight<YellowLight>>(Vec(77, 198), module, WhiteWhale::TRIG4_LIGHT));
    addChild(createLight<MediumLight<WhiteLight>>(Vec(3.4, 122), module, WhiteWhale::CVA_LIGHT));
    addChild(createLight<MediumLight<WhiteLight>>(Vec(3.4, 160), module, WhiteWhale::CVB_LIGHT));

    addInput(createInput<PJ301MPort>(Vec(14.4, 298 - 3.15), module, WhiteWhale::CLOCK_INPUT));
    addOutput(createOutput<PJ301MPort>(Vec(52.4, 298 - 3.15), module, WhiteWhale::CLOCK_OUTPUT));
    addOutput(createOutput<PJ301MPort>(Vec(52.4, 95 - 6.15), module, WhiteWhale::TRIG1_OUTPUT));
    addOutput(createOutput<PJ301MPort>(Vec(52.4, 133 - 6.15), module, WhiteWhale::TRIG2_OUTPUT));
    addOutput(createOutput<PJ301MPort>(Vec(52.4, 171 - 6.15), module, WhiteWhale::TRIG3_OUTPUT));
    addOutput(createOutput<PJ301MPort>(Vec(52.4, 209 - 6.15), module, WhiteWhale::TRIG4_OUTPUT));
    addOutput(createOutput<PJ301MPort>(Vec(15.85, 110 - 4.15), module, WhiteWhale::CVA_OUTPUT));
    addOutput(createOutput<PJ301MPort>(Vec(15.85, 148 - 4.15), module, WhiteWhale::CVB_OUTPUT));
}

void WhiteWhaleWidget::randomize()
{
    // don't randomize params, just randomize module core
    module->randomize();
}
