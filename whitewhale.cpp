#include "whitewhale.hpp"
#include "grid.hpp"


#include "mock_hardware.h"
#include "base64.h"
#include "types.h"
#include <string.h>

// hardware interface points
extern "C" int main(void);
extern "C" void check_events(void);

// memory state to save
typedef enum {
    mTrig, mMap, mSeries
} edit_modes;

typedef enum {
    mForward=0, mReverse, mDrunk, mRandom, mPing, mPingRep
} step_modes;

typedef enum {
    mPingFwd = 1,
    mPingRev = -1
} ping_direction;

typedef struct {
    u8 loop_start, loop_end, loop_len, loop_dir;
    u16 step_choice;
    u8 cv_mode[2];
    u8 tr_mode;
    step_modes step_mode;
    ping_direction ping_dir;
    u8 steps[16];
    u8 step_probs[16];
    u16 cv_values[16];
    u16 cv_steps[2][16];
    u16 cv_curves[2][16];
    u8 cv_probs[2][16];
} whale_pattern;

typedef struct {
    whale_pattern wp[16];
    u16 series_list[64];
    u8 series_start, series_end;
    u8 tr_mute[4];
    u8 cv_mute[2];
} whale_set;

typedef const struct {
    u8 fresh;
    edit_modes edit_mode;
    u8 preset_select;
    u8 glyph[8][8];
    whale_set w[8];
} nvram_data_t;

extern whale_set w;
extern nvram_data_t flashy;


struct WhiteWhale : MonomeModuleBase {

    enum ParamIds {
        CLOCK_PARAM,
        PARAM_PARAM,
        BUTTON_PARAM,
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

    WhiteWhale() : MonomeModuleBase(NUM_PARAMS, NUM_INPUTS, NUM_OUTPUTS, NUM_LIGHTS) {
        main();
    }

    void step() override;

    json_t *toJson() override {
        json_t *rootJ = MonomeModuleBase::toJson();
        json_object_set_new(rootJ, "current", json_string(base64_encode((unsigned char*)&w, sizeof(whale_set)).c_str()));
        json_object_set_new(rootJ, "flash", json_string(base64_encode((unsigned char*)&flashy, sizeof(nvram_data_t)).c_str()));
        return rootJ;
    }

    void fromJson(json_t *rootJ) override {
        MonomeModuleBase::fromJson(rootJ);
        memcpy((void*)&w, base64_decode(json_string_value(json_object_get(rootJ, "current"))).c_str(), sizeof(whale_set));
        memcpy((void*)&flashy, base64_decode(json_string_value(json_object_get(rootJ, "flash"))).c_str(), sizeof(nvram_data_t));
    }

    void reset() override {
    }

    void randomize() override {
    }
};


void WhiteWhale::step() {

    MonomeModuleBase::step();

    vserial_reset();

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
    bool frontButton = params[BUTTON_PARAM].value == 0;
    if (frontButton != vgpio_get(NMI))
    {
        vgpio_set(NMI, frontButton);
        simulate_front_button_interrupt();
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

    // Update LEDs on connected grid
    if (gridConnection)
    {
        uint8_t* msg = vserial_read();
        while (msg)
        {
            if (msg[0] == 0x1A)
            {
                // Grid quadrant update
                uint8_t x = msg[1];
                uint8_t y = msg[2];
                uint8_t leds[64];
                for(int i=0; i<32; i++)
                {
                    leds[2*i+0] = msg[3+i] >> 4;
                    leds[2*i+1] = msg[3+i] & 0xF;
                }

                // connection could be lost mid-update, re-check
                if (gridConnection)
                {
                    gridConnection->updateQuadrant(x, y, leds);
                }
            }
            msg = vserial_read();
        }
    }
}


struct WhiteLight : ModuleLightWidget
{
    WhiteLight()
    {
        addBaseColor(COLOR_WHITE);
    }
};

struct USBAJack : TransparentWidget
{
    void draw(NVGcontext *vg) override
    {
        nvgBeginPath(vg);
        nvgRect(vg, 0, 0, 40, 16);
        nvgFillColor(vg, nvgRGB(0, 0, 0));
        nvgFill(vg);

        nvgBeginPath(vg);
        nvgRect(vg, 4, 4, 32, 4);
        nvgFillColor(vg, nvgRGB(120, 120, 120));
        nvgFill(vg);
    }
};

WhiteWhaleWidget::WhiteWhaleWidget() {
    WhiteWhale *module = new WhiteWhale();
    setModule(module);
    box.size = Vec(15*6, 380);

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

    addInput(createInput<PJ301MPort>(Vec(14.4, 298-3.15), module, WhiteWhale::CLOCK_INPUT));
    addOutput(createOutput<PJ301MPort>(Vec(52.4, 298-3.15), module, WhiteWhale::CLOCK_OUTPUT));
    addOutput(createOutput<PJ301MPort>(Vec(52.4, 95-6.15), module, WhiteWhale::TRIG1_OUTPUT));
    addOutput(createOutput<PJ301MPort>(Vec(52.4, 133-6.15), module, WhiteWhale::TRIG2_OUTPUT));
    addOutput(createOutput<PJ301MPort>(Vec(52.4, 171-6.15), module, WhiteWhale::TRIG3_OUTPUT));
    addOutput(createOutput<PJ301MPort>(Vec(52.4, 209-6.15), module, WhiteWhale::TRIG4_OUTPUT));
    addOutput(createOutput<PJ301MPort>(Vec(15.85, 110-4.15), module, WhiteWhale::CVA_OUTPUT));
    addOutput(createOutput<PJ301MPort>(Vec(15.85, 148-4.15), module, WhiteWhale::CVB_OUTPUT));
}

void WhiteWhaleWidget::randomize()
{
    // don't randomize params, just randomize module core
    module->randomize();
}

