#include "FaderbankWidget.hpp"
#include "FaderbankModule.hpp"

extern rack::Plugin* pluginInstance;

using namespace rack;

struct ThemedSvgSlider : app::SvgSlider
{
    std::vector<std::shared_ptr<window::Svg>> lightThemedBackgrounds;
    std::vector<std::shared_ptr<window::Svg>> darkThemedBackgrounds;

    unsigned int *theme = 0;

    void updateGraphics()
    {
        int t = theme == nullptr ? 0 : *theme;
        SvgSlider::setBackgroundSvg(
            settings::preferDarkPanels ?
                darkThemedBackgrounds[t % darkThemedBackgrounds.size()] :
                lightThemedBackgrounds[t % lightThemedBackgrounds.size()]
        );
    }

    void step() override
    {
        updateGraphics();
        SvgSlider::step();
    }
};

struct FaderbankSlider : ThemedSvgSlider
{
    FaderbankSlider()
    {
        lightThemedBackgrounds.push_back(Svg::load(asset::plugin(pluginInstance, "res/FaderBackground90mm.svg")));
        lightThemedBackgrounds.push_back(Svg::load(asset::plugin(pluginInstance, "res/FaderBackground60mm.svg")));
        darkThemedBackgrounds.push_back(Svg::load(asset::plugin(pluginInstance, "res/FaderBackground90mm-dark.svg")));
        darkThemedBackgrounds.push_back(Svg::load(asset::plugin(pluginInstance, "res/FaderBackground60mm-dark.svg")));

        setHandleSvg(Svg::load(asset::plugin(pluginInstance, "res/FaderHandle.svg")));
        updateGraphics();

        maxHandlePos = rack::window::mm2px(math::Vec(0.738, 1.8));
        minHandlePos = rack::window::mm2px(math::Vec(0.738, 87.3));

        box.grow(math::Vec(3, 1));
    }

    void step() override
    {
        minHandlePos = rack::window::mm2px(math::Vec(0.738, (theme == nullptr || *theme == 0) ? 87.3 : 59.8));
        ThemedSvgSlider::step();
    }
};

struct WideYellowLight : YellowLight
{
    // custom draw function to make glow look better on a
    // rectangular light that is much wider than it is tall
    void drawHalo(const DrawArgs& args) override
    {
        if (args.fb)
            return;

        const float halo = settings::haloBrightness;
        if (halo == 0.f)
            return;

        if (color.r == 0.f && color.g == 0.f && color.b == 0.f)
            return;

        math::Vec c = box.size.div(2);

        float xoradius = c.x + std::min(c.x * 1.55f, 15.f);
        float yoradius = c.y + std::min(c.y * 1.85f, 15.f);

        nvgBeginPath(args.vg);
        nvgRect(args.vg, c.x - xoradius, c.y - yoradius, 2 * xoradius, 3 * yoradius);

        NVGcolor icol = color::mult(color, halo);
        NVGcolor ocol = nvgRGBA(0, 0, 0, 0);
        nvgSave(args.vg);
        nvgScale(args.vg, 1.0f, 1.85f * c.y / c.x);
        NVGpaint paint = nvgRadialGradient(args.vg, c.x, c.y, c.x * 0.46, xoradius * 0.8, icol, ocol);
        nvgFillPaint(args.vg, paint);
        nvgFill(args.vg);
        nvgRestore(args.vg);
    }
};

template <typename TBase>
struct FaderbankSliderLight : RectangleLight<TSvgLight<TBase>>
{
    FaderbankSliderLight()
    {
        this->setSvg(Svg::load(asset::plugin(pluginInstance, "res/FaderSliderLight.svg")));
    }
};

struct FaderbankSliderYellow : LightSlider<FaderbankSlider, FaderbankSliderLight<WideYellowLight>>
{
    FaderbankSliderYellow()
    {
        getLight()->box.size.x = getLight()->box.size.x * 6;
        getLight()->box.size.y = getLight()->box.size.y * 0.4;
    }
};


FaderbankWidget::FaderbankWidget(FaderbankModule* module)
{
    setModule(module);

    box.size = Vec(720, 380);

    {
        auto panel = new ThemedSvgPanel();
        panel->setBackground(
            APP->window->loadSvg(rack::asset::plugin(pluginInstance, "res/grid.svg")),
            APP->window->loadSvg(rack::asset::plugin(pluginInstance, "res/grid-dark.svg")));
        panel->box.size = box.size;
        addChild(panel);
    }

    for (int i = 0; i < NUM_FADERS; i++)
    {
        addOutput(createOutput<ThemedPJ301MPort>(Vec(26 + 43 * i, 26), module, i));
        auto slider = createParam<FaderbankSliderYellow>(Vec(23 + 43 * i, 66), module, i);
        if (module != nullptr)
        {
            slider->theme = (unsigned int*)&module->faderSize;
        }
        else
        {
            // set the handles on a diagonal in the library
            slider->handle->box.pos = slider->minHandlePos.crossfade(slider->maxHandlePos, i/(NUM_FADERS * 1.0));
        }
        addParam(slider);
    }
}

void FaderbankWidget::appendContextMenu(Menu* menu)
{
    auto fb = dynamic_cast<FaderbankModule*>(module);
    if (!fb)
    {
        return;
    }

    menu->addChild(new MenuSeparator());

    menu->addChild(createIndexSubmenuItem("Fader size", { "90mm", "60mm" },
        [=]() {
            return fb->faderSize;
        },
        [=](int index) {
            fb->faderSize = static_cast<FaderbankModule::FaderSize>(index);
            // update all the slider handle positions
            for (widget::Widget* child : children)
            {
                child->step();
                ChangeEvent eChange;
                child->onChange(eChange);
            }
        }
    ));

    menu->addChild(createSubmenuItem("MIDI connection", fb->midiInput.getDeviceName(fb->midiInput.getDeviceId()),
        [=](Menu* childMenu)
        {
            appendMidiMenu(childMenu, &fb->midiInput);
            // remove channel selection
            auto last = childMenu->children.back();
            childMenu->removeChild(last);
            delete last;
        }));

    menu->addChild(createMenuItem("Autodetect 16n configuration", "",
        [=]()
        {
            fb->resetConfig();

            // Send a sysex message to request device channel/CC config.
            midi::Message msg;
            msg.setSize(6);
            msg.bytes = { 0xF0, 0x7d, 0x00, 0x00, 0x1F, 0xF7 };

            midi::Output output;
            output.setDriverId(fb->midiInput.getDriverId());
            output.setDeviceId(fb->midiInput.getDeviceId());
            output.sendMessage(msg);
        }));
}