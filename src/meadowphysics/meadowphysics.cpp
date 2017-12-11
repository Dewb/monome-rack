#include "meadowphysics.hpp"
#include "grid.hpp"
#include "monomewidgets.hpp"

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

struct Meadowphysics : MonomeModuleBase
{
    enum ParamIds
    {
        CLOCK_PARAM,
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
        TRIG5_OUTPUT,
        TRIG6_OUTPUT,
        TRIG7_OUTPUT,
        TRIG8_OUTPUT,
        NUM_OUTPUTS
    };
    enum LightIds
    {
        CLOCK_LIGHT,
        TRIG1_LIGHT,
        TRIG2_LIGHT,
        TRIG3_LIGHT,
        TRIG4_LIGHT,
        TRIG5_LIGHT,
        TRIG6_LIGHT,
        TRIG7_LIGHT,
        TRIG8_LIGHT,
        NUM_LIGHTS
    };

    Meadowphysics()
        : MonomeModuleBase(NUM_PARAMS, NUM_INPUTS, NUM_OUTPUTS, NUM_LIGHTS)
    {
        firmware.load("./plugins/monome-rack/build/firmware/meadowphysics");
        firmware.init();
    }

    void step() override;
};

void Meadowphysics::step()
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
    lights[TRIG5_LIGHT].setBrightnessSmooth(firmware.getGPIO(B04));
    lights[TRIG6_LIGHT].setBrightnessSmooth(firmware.getGPIO(B05));
    lights[TRIG7_LIGHT].setBrightnessSmooth(firmware.getGPIO(B06));
    lights[TRIG8_LIGHT].setBrightnessSmooth(firmware.getGPIO(B07));

    // Update output jacks from GPIO & DAC
    outputs[CLOCK_OUTPUT].value = firmware.getGPIO(B10) * 8.0;
    outputs[TRIG1_OUTPUT].value = firmware.getGPIO(B00) * 8.0;
    outputs[TRIG2_OUTPUT].value = firmware.getGPIO(B01) * 8.0;
    outputs[TRIG3_OUTPUT].value = firmware.getGPIO(B02) * 8.0;
    outputs[TRIG4_OUTPUT].value = firmware.getGPIO(B03) * 8.0;
    outputs[TRIG5_OUTPUT].value = firmware.getGPIO(B04) * 8.0;
    outputs[TRIG6_OUTPUT].value = firmware.getGPIO(B05) * 8.0;
    outputs[TRIG7_OUTPUT].value = firmware.getGPIO(B06) * 8.0;
    outputs[TRIG8_OUTPUT].value = firmware.getGPIO(B07) * 8.0;

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

MeadowphysicsWidget::MeadowphysicsWidget()
{
    Meadowphysics* module = new Meadowphysics();
    setModule(module);
    box.size = Vec(15 * 6, 380);

    {
        auto panel = new SVGPanel();
        panel->setBackground(SVG::load(assetPlugin(plugin, "res/meadowphysics.svg")));
        panel->box.size = box.size;
        addChild(panel);
    }

    addChild(createScrew<USBAJack>(Vec(10, 338)));

    addParam(createParam<TL1105>(Vec(62, 336), module, Meadowphysics::BUTTON_PARAM, 0.0, 1.0, 0.0));
    addParam(createParam<MonomeKnob>(Vec(12, 230), module, Meadowphysics::CLOCK_PARAM, 0.0, 1.0, 0.5));

    addChild(createLight<MediumLight<YellowLight>>(Vec(2, 72), module, Meadowphysics::TRIG1_LIGHT));
    addChild(createLight<MediumLight<YellowLight>>(Vec(77, 72), module, Meadowphysics::TRIG2_LIGHT));
    addChild(createLight<MediumLight<YellowLight>>(Vec(2, 110), module, Meadowphysics::TRIG3_LIGHT));
    addChild(createLight<MediumLight<YellowLight>>(Vec(77, 110), module, Meadowphysics::TRIG4_LIGHT));
    addChild(createLight<MediumLight<YellowLight>>(Vec(2, 148), module, Meadowphysics::TRIG5_LIGHT));
    addChild(createLight<MediumLight<YellowLight>>(Vec(77, 148), module, Meadowphysics::TRIG6_LIGHT));
    addChild(createLight<MediumLight<YellowLight>>(Vec(2, 186), module, Meadowphysics::TRIG7_LIGHT));
    addChild(createLight<MediumLight<YellowLight>>(Vec(77, 186), module, Meadowphysics::TRIG8_LIGHT));
    addChild(createLight<MediumLight<YellowLight>>(Vec(77, 282), module, Meadowphysics::CLOCK_LIGHT));

    addOutput(createOutput<PJ301MPort>(Vec(13, 54), module, Meadowphysics::TRIG1_OUTPUT));
    addOutput(createOutput<PJ301MPort>(Vec(50, 75), module, Meadowphysics::TRIG2_OUTPUT));
    addOutput(createOutput<PJ301MPort>(Vec(13, 92), module, Meadowphysics::TRIG3_OUTPUT));
    addOutput(createOutput<PJ301MPort>(Vec(50, 111), module, Meadowphysics::TRIG4_OUTPUT));
    addOutput(createOutput<PJ301MPort>(Vec(13, 130), module, Meadowphysics::TRIG5_OUTPUT));
    addOutput(createOutput<PJ301MPort>(Vec(50, 149), module, Meadowphysics::TRIG6_OUTPUT));
    addOutput(createOutput<PJ301MPort>(Vec(13, 168), module, Meadowphysics::TRIG7_OUTPUT));
    addOutput(createOutput<PJ301MPort>(Vec(50, 187), module, Meadowphysics::TRIG8_OUTPUT));
    addInput(createInput<PJ301MPort>(Vec(13, 286), module, Meadowphysics::CLOCK_INPUT));
    addOutput(createOutput<PJ301MPort>(Vec(50, 286), module, Meadowphysics::CLOCK_OUTPUT));
}

void MeadowphysicsWidget::randomize()
{
    // don't randomize params, just randomize module core
    module->randomize();
}
