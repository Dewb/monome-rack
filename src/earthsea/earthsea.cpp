#include "earthsea.hpp"
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

struct Earthsea : MonomeModuleBase
{
    enum ParamIds
    {
        CV1_PARAM,
        CV2_PARAM,
        CV3_PARAM,
        BUTTON_PARAM,
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

    Earthsea()
        : MonomeModuleBase(NUM_PARAMS, NUM_INPUTS, NUM_OUTPUTS, NUM_LIGHTS)
    {
        firmware.load("./plugins/monome-rack/build/firmware/earthsea");
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

void Earthsea::step()
{
    MonomeModuleBase::step();

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

    // Advance software timers
    firmware.advanceClock(engineGetSampleTime());

    // Pump event loop
    firmware.step();

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

EarthseaWidget::EarthseaWidget()
{
    Earthsea* module = new Earthsea();
    setModule(module);
    box.size = Vec(15 * 6, 380);

    {
        //auto panel = new SVGPanel();
        //panel->setBackground(SVG::load(assetPlugin(plugin, "res/earthsea.svg")));
        auto panel = new LightPanel();
        //panel->backgroundImage = Image::load(assetPlugin(plugin, "res/earthsea.jpg"));
        panel->box.size = box.size;
        addChild(panel);
    }

    addChild(createScrew<ScrewSilver>(Vec(0, 0)));
    addChild(createScrew<ScrewSilver>(Vec(0, 365)));
    addChild(createScrew<USBAJack>(Vec(10, 338)));

    addParam(createParam<TL1105>(Vec(62, 336), module, Earthsea::BUTTON_PARAM, 0.0, 1.0, 0.0));
    addParam(createParam<MonomeKnob>(Vec(12, 30), module, Earthsea::CV1_PARAM, 0.0, 1.0, 0.5));
    addParam(createParam<MonomeKnob>(Vec(12, 116), module, Earthsea::CV2_PARAM, 0.0, 1.0, 0.5));
    addParam(createParam<MonomeKnob>(Vec(12, 202), module, Earthsea::CV3_PARAM, 0.0, 1.0, 0.5));

    addChild(createLight<MediumLight<WhiteLight>>(Vec(77, 78), module, Earthsea::CV1_LIGHT));
    addChild(createLight<MediumLight<WhiteLight>>(Vec(77, 162), module, Earthsea::CV2_LIGHT));
    addChild(createLight<MediumLight<WhiteLight>>(Vec(77, 244), module, Earthsea::CV3_LIGHT));
    addChild(createLight<MediumLight<WhiteLight>>(Vec(77, 282), module, Earthsea::POS_LIGHT));
    addChild(createLight<MediumLight<YellowLight>>(Vec(2, 286), module, Earthsea::EDGE_LIGHT));

    addOutput(createOutput<PJ301MPort>(Vec(50, 82), module, Earthsea::CV1_OUTPUT));
    addOutput(createOutput<PJ301MPort>(Vec(50, 166), module, Earthsea::CV2_OUTPUT));
    addOutput(createOutput<PJ301MPort>(Vec(50, 248), module, Earthsea::CV3_OUTPUT));
    addOutput(createOutput<PJ301MPort>(Vec(50, 286), module, Earthsea::POS_OUTPUT));
    addOutput(createOutput<PJ301MPort>(Vec(13, 268), module, Earthsea::EDGE_OUTPUT));
}

void EarthseaWidget::randomize()
{
    // don't randomize params, just randomize module core
    module->randomize();
}
