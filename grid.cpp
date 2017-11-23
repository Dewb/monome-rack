#include "grid.hpp"
#include "virtual_gpio.h"

// cheat for now by accessing the module's LED buffer directly
extern uint8_t monomeLedBuffer[256];


template<size_t GRID_X, size_t GRID_Y>
struct Grid : Module {

	enum ParamIds {
		NUM_PARAMS
	};
	enum InputIds {
		NUM_INPUTS
	};
	enum OutputIds {
		NUM_OUTPUTS
	};
	enum LightIds {
		NUM_LIGHTS = GRID_X * GRID_Y
	};
    const int X = GRID_X;
    const int Y = GRID_Y;

	Grid() : Module(NUM_PARAMS, NUM_INPUTS, NUM_OUTPUTS, NUM_LIGHTS) 
    {
        simulate_monome_connect();
	}

    void step() override {

    }

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


struct MonomePad : Button {

    Vec position;
    uint8_t* ledAddress;

	MonomePad(Vec pos, uint8_t* ledByte) 
    {
		position = pos;
        ledAddress = ledByte;
	}

    void draw(NVGcontext *vg) override
    {
        NVGcolor color1 = nvgRGB(*ledAddress * 14 + 32, *ledAddress * 14 + 32, *ledAddress * 8 + 32);
        NVGcolor color2 = nvgRGBA(*ledAddress * 12, *ledAddress * 10, *ledAddress * 12, 128);

        nvgBeginPath(vg);
        auto paint = nvgBoxGradient(vg, position.x, position.y, box.size.x, box.size.y, 5, 10, color1, color2);
        nvgRoundedRect(vg, position.x, position.y, box.size.x, box.size.y, 4);
        nvgFillPaint(vg, paint);
        nvgFill(vg);
    }
};


Grid128Widget::Grid128Widget() {

	auto *module = new Grid<16, 8>();
	setModule(module);
	box.size = Vec(15*48, 380);

	{
		//auto panel = new SVGPanel();
		auto panel = new LightPanel();
		panel->box.size = box.size;
		//panel->setBackground(SVG::load(assetPlugin(plugin, "res/whitewhale.svg")));
		addChild(panel);
	}

    Vec margins(20, 20);
    int spacing = 9;

    int max_width = (box.size.x - margins.x * 2 - (module->X - 1) * spacing) / module->X;
    int max_height = (box.size.y - margins.y * 2 - (module->Y - 1) * spacing) / module->Y;
    int button_size = max_width > max_height ? max_width : max_height;

    for(int i = 0; i < module->X; i++) 
    {
        for(int j = 0; j < module->Y; j++)
        {
            int x = margins.x + i * (button_size + spacing);
            int y = margins.y + j * (button_size + spacing);
            int n = i * module->Y + j;

            auto pad = new MonomePad(Vec(x, y), monomeLedBuffer + (i | (j << 4)));
            pad->box.size = Vec(button_size, button_size);
            addChild(pad);
        }
    }
}
