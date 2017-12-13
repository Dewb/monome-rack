#include "whitewhale.hpp"
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

    readSerialMessages();
}

WhiteWhaleWidget::WhiteWhaleWidget()
{
    WhiteWhale* module = new WhiteWhale();
    setModule(module);
    box.size = Vec(15 * 6, 380);

    {
        auto panel = new SVGPanel();
        panel->setBackground(SVG::load(assetPlugin(plugin, "res/whitewhale.svg")));
        panel->box.size = box.size;
        addChild(panel);
    }

    addChild(createScrew<USBAJack>(Vec(10, 338)));

    addParam(createParam<TL1105>(Vec(62, 336), module, WhiteWhale::BUTTON_PARAM, 0.0, 1.0, 0.0));
    addParam(createParam<MonomeKnob>(Vec(12, 30), module, WhiteWhale::PARAM_PARAM, 0.0, 1.0, 0.5));
    addParam(createParam<MonomeKnob>(Vec(12, 230), module, WhiteWhale::CLOCK_PARAM, 0.0, 1.0, 0.5));

    addChild(createLight<MediumLight<YellowLight>>(Vec(77, 80), module, WhiteWhale::TRIG1_LIGHT));
    addChild(createLight<MediumLight<YellowLight>>(Vec(77, 118), module, WhiteWhale::TRIG2_LIGHT));
    addChild(createLight<MediumLight<YellowLight>>(Vec(77, 156), module, WhiteWhale::TRIG3_LIGHT));
    addChild(createLight<MediumLight<YellowLight>>(Vec(77, 194), module, WhiteWhale::TRIG4_LIGHT));
    addChild(createLight<MediumLight<YellowLight>>(Vec(77, 282), module, WhiteWhale::CLOCK_LIGHT));
    addChild(createLight<MediumLight<WhiteLight>>(Vec(2, 118), module, WhiteWhale::CVA_LIGHT));
    addChild(createLight<MediumLight<WhiteLight>>(Vec(2, 156), module, WhiteWhale::CVB_LIGHT));

    addOutput(createOutput<PJ301MPort>(Vec(50, 82), module, WhiteWhale::TRIG1_OUTPUT));
    addOutput(createOutput<PJ301MPort>(Vec(50, 120), module, WhiteWhale::TRIG2_OUTPUT));
    addOutput(createOutput<PJ301MPort>(Vec(50, 158), module, WhiteWhale::TRIG3_OUTPUT));
    addOutput(createOutput<PJ301MPort>(Vec(50, 196), module, WhiteWhale::TRIG4_OUTPUT));
    addOutput(createOutput<PJ301MPort>(Vec(13, 100), module, WhiteWhale::CVA_OUTPUT));
    addOutput(createOutput<PJ301MPort>(Vec(13, 138), module, WhiteWhale::CVB_OUTPUT));
    addInput(createInput<PJ301MPort>(Vec(13, 286), module, WhiteWhale::CLOCK_INPUT));
    addOutput(createOutput<PJ301MPort>(Vec(50, 286), module, WhiteWhale::CLOCK_OUTPUT));
}

void WhiteWhaleWidget::randomize()
{
    // don't randomize params, just randomize module core
    module->randomize();
}
