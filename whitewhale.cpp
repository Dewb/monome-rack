#include "whitewhale.hpp"
#include "grid.hpp"

#include "virtual_gpio.h"

// hardware interface points
extern "C" int main(void);
extern "C" void check_events(void);

// Plugin definition

Plugin *plugin;

void init(rack::Plugin *p) {
    plugin = p;
    p->slug = "Monome";
#ifdef VERSION
    p->version = TOSTRING(VERSION);
#endif
    p->website = "https://github.com/monome/whitewhale";

    p->addModel(createModel<WhiteWhaleWidget>("Monome", "WW", "White Whale", SEQUENCER_TAG));
    p->addModel(createModel<Grid128Widget>("Monome", "Grid128", "Grid 128", SEQUENCER_TAG));
}

struct WhiteLight : ModuleLightWidget {
    WhiteLight() {
        addBaseColor(COLOR_WHITE);
    }
};

struct WhiteWhale : Module {

    enum ParamIds {
        CLOCK_PARAM,
        PARAM_PARAM,
        NUM_PARAMS
    };
    enum InputIds {
        CLOCK_INPUT,
        NUM_INPUTS
    };
    enum OutputIds {
        CLOCK_OUTPUT,
        TRIG1_OUTPUT,
        TRIG2_OUTPUT,
        TRIG3_OUTPUT,
        TRIG4_OUTPUT,
        CVA_OUTPUT,
        CVB_OUTPUT,
        NUM_OUTPUTS
    };
    enum LightIds {
        CLOCK_LIGHT,
        TRIG1_LIGHT,
        TRIG2_LIGHT,
        TRIG3_LIGHT,
        TRIG4_LIGHT,
        CVA_LIGHT,
        CVB_LIGHT,
        NUM_LIGHTS
    };

    WhiteWhale() : Module(NUM_PARAMS, NUM_INPUTS, NUM_OUTPUTS, NUM_LIGHTS) {
        main();
    }

    void step() override;

    json_t *toJson() override {
        json_t *rootJ = json_object();
        return rootJ;
    }

    void fromJson(json_t *rootJ) override {
    }

    void reset() override {
    }

    void randomize() override {
    }
};


void WhiteWhale::step() {

    // Convert clock input jack to GPIO signals for normal connection and value
    bool clockNormal = !inputs[CLOCK_INPUT].active;
    if (clockNormal != vgpio_get(B09))
    {
        vgpio_set(B09, clockNormal);
        simulate_clock_normal_interrupt();
    }
    bool externalClock = inputs[CLOCK_INPUT].value > 0;
    if (externalClock != vgpio_get(B08))
    {
        vgpio_set(B08, externalClock);
        simulate_external_clock_interrupt();
    }

    // Convert knob float parameters to 12-bit ADC values
    vadc_set(0, params[CLOCK_PARAM].value * 0xFFF);
    vadc_set(1, params[PARAM_PARAM].value * 0xFFF);

    // Advance software timers
    simulate_timer_interrupt(engineGetSampleTime());

    // Pump event loop
    check_events();

    // Update lights from GPIO
    lights[CLOCK_LIGHT].setBrightnessSmooth(vgpio_get(B10));
    lights[TRIG1_LIGHT].setBrightnessSmooth(vgpio_get(B00));
    lights[TRIG2_LIGHT].setBrightnessSmooth(vgpio_get(B01));
    lights[TRIG3_LIGHT].setBrightnessSmooth(vgpio_get(B02));
    lights[TRIG4_LIGHT].setBrightnessSmooth(vgpio_get(B03));
    lights[CVA_LIGHT].value = vdac_get(0)/65536.0;
    lights[CVB_LIGHT].value = vdac_get(1)/65536.0;
    
    // Update output jacks from GPIO & DAC
    outputs[CLOCK_OUTPUT].value = vgpio_get(B10) * 8.0;
    outputs[TRIG1_OUTPUT].value = vgpio_get(B00) * 8.0;
    outputs[TRIG2_OUTPUT].value = vgpio_get(B01) * 8.0;
    outputs[TRIG3_OUTPUT].value = vgpio_get(B02) * 8.0;
    outputs[TRIG4_OUTPUT].value = vgpio_get(B03) * 8.0;
    outputs[CVA_OUTPUT].value = 10.0 * vdac_get(0) / 65536.0;
    outputs[CVB_OUTPUT].value = 10.0 * vdac_get(1) / 65536.0;

}


WhiteWhaleWidget::WhiteWhaleWidget() {
    WhiteWhale *module = new WhiteWhale();
    setModule(module);
    box.size = Vec(15*6, 380);

    {
        //auto panel = new SVGPanel();
        auto panel = new LightPanel();
        panel->box.size = box.size;
        //panel->setBackground(SVG::load(assetPlugin(plugin, "res/whitewhale.svg")));
        addChild(panel);
    }

    addChild(createScrew<ScrewSilver>(Vec(0, 0)));
    addChild(createScrew<ScrewSilver>(Vec(0, 365)));

    addParam(createParam<RoundSmallBlackKnob>(Vec(12, 30), module, WhiteWhale::PARAM_PARAM, 0.0, 1.0, 0.5));
    addParam(createParam<RoundSmallBlackKnob>(Vec(12, 250), module, WhiteWhale::CLOCK_PARAM, 0.0, 1.0, 0.5));

    addChild(createLight<MediumLight<YellowLight>>(Vec(83-4.59, 286), module, WhiteWhale::CLOCK_LIGHT));
    addChild(createLight<MediumLight<YellowLight>>(Vec(83-4.59, 84), module, WhiteWhale::TRIG1_LIGHT));
    addChild(createLight<MediumLight<YellowLight>>(Vec(83-4.59, 122), module, WhiteWhale::TRIG2_LIGHT));
    addChild(createLight<MediumLight<YellowLight>>(Vec(83-4.59, 160), module, WhiteWhale::TRIG3_LIGHT));
    addChild(createLight<MediumLight<YellowLight>>(Vec(83-4.59, 198), module, WhiteWhale::TRIG4_LIGHT));
    addChild(createLight<MediumLight<WhiteLight>>(Vec(5-1.59, 122), module, WhiteWhale::CVA_LIGHT));
    addChild(createLight<MediumLight<WhiteLight>>(Vec(5-1.59, 160), module, WhiteWhale::CVB_LIGHT));

    addInput(createInput<PJ301MPort>(Vec(24-8.15, 298-3.15), module, WhiteWhale::CLOCK_INPUT));
    addOutput(createOutput<PJ301MPort>(Vec(62-8.15, 298-3.15), module, WhiteWhale::CLOCK_OUTPUT));
    addOutput(createOutput<PJ301MPort>(Vec(62-8.15, 95-6.15), module, WhiteWhale::TRIG1_OUTPUT));
    addOutput(createOutput<PJ301MPort>(Vec(62-8.15, 133-6.15), module, WhiteWhale::TRIG2_OUTPUT));
    addOutput(createOutput<PJ301MPort>(Vec(62-8.15, 171-6.15), module, WhiteWhale::TRIG3_OUTPUT));
    addOutput(createOutput<PJ301MPort>(Vec(62-8.15, 209-6.15), module, WhiteWhale::TRIG4_OUTPUT));
    addOutput(createOutput<PJ301MPort>(Vec(24-8.15, 110-4.15), module, WhiteWhale::CVA_OUTPUT));
    addOutput(createOutput<PJ301MPort>(Vec(24-8.15, 148-4.15), module, WhiteWhale::CVB_OUTPUT));
}
