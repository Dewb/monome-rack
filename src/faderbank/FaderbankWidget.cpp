#include "FaderbankWidget.hpp"
#include "FaderbankModule.hpp"

extern rack::Plugin* pluginInstance;

using namespace rack;

struct ThemedSvgSlider : app::SvgSlider
{
    std::shared_ptr<window::Svg> lightBackgroundSvg;
    std::shared_ptr<window::Svg> darkBackgroundSvg;

    void setBackgroundSvg(std::shared_ptr<window::Svg> lightBackgroundSvg, std::shared_ptr<window::Svg> darkBackgroundSvg)
    {
        this->lightBackgroundSvg = lightBackgroundSvg;
        this->darkBackgroundSvg = darkBackgroundSvg;
        SvgSlider::setBackgroundSvg(settings::preferDarkPanels ? darkBackgroundSvg : lightBackgroundSvg);
    }

    void step() override
    {
        SvgSlider::setBackgroundSvg(settings::preferDarkPanels ? darkBackgroundSvg : lightBackgroundSvg);
        SvgSlider::step();
    }
};

struct FaderbankSlider : ThemedSvgSlider
{
    FaderbankSlider()
    {
        maxHandlePos = rack::window::mm2px(math::Vec(0.738, 1.8).plus(math::Vec(0, 0)));
        minHandlePos = rack::window::mm2px(math::Vec(0.738, 87.3).plus(math::Vec(0, 0)));
        setBackgroundSvg(
            Svg::load(asset::plugin(pluginInstance, "res/FaderBackground.svg")),
            Svg::load(asset::plugin(pluginInstance, "res/FaderBackground-dark.svg"))
        );
        setHandleSvg(Svg::load(asset::plugin(pluginInstance, "res/FaderHandle.svg")));
        box.grow(math::Vec(3, 1));
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

        // make this the average instead of min
        float radius = (box.size.x + box.size.y) / 3.f;
        float oradius = radius + std::min(radius * 4.f, 15.f);

        nvgBeginPath(args.vg);
        nvgRect(args.vg, c.x - oradius, c.y - oradius, 2 * oradius, 2 * oradius);

        NVGcolor icol = color::mult(color, halo);
        NVGcolor ocol = nvgRGBA(0, 0, 0, 0);
        NVGpaint paint = nvgRadialGradient(args.vg, c.x, c.y, radius, oradius, icol, ocol);
        nvgFillPaint(args.vg, paint);
        nvgFill(args.vg);
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
        addParam(createParam<FaderbankSliderYellow>(Vec(23 + 43 * i, 66), module, i));
    }
}

void FaderbankWidget::appendContextMenu(Menu* menu)
{
}