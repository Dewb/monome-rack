#include "FaderbankWidget.hpp"
#include "FaderbankModule.hpp"

extern rack::Plugin* pluginInstance;

using namespace rack;

struct FaderbankSlider : app::SvgSlider
{
    FaderbankSlider()
    {
        maxHandlePos = rack::window::mm2px(math::Vec(0.738, 2.8).plus(math::Vec(3.5, 0)));
        minHandlePos = rack::window::mm2px(math::Vec(0.738, 88.3).plus(math::Vec(3.5, 0)));
        setBackgroundSvg(APP->window->loadSvg(rack::asset::plugin(pluginInstance, "res/Fader.svg")));
        setHandleSvg(APP->window->loadSvg(asset::system("res/ComponentLibrary/LEDSliderHandle.svg")));
        box.grow(math::Vec(3, 1));
    }
};

struct FaderbankSliderYellow : LightSlider<FaderbankSlider, LEDSliderLight<YellowLight>>
{
    FaderbankSliderYellow() { }
};


FaderbankWidget::FaderbankWidget(FaderbankModule* module)
{
    setModule(module);

    box.size = Vec(720, 380);

    PanelBorder* pb = new PanelBorder;
    pb->box.size = box.size;
    addChild(pb);

    for (int i = 0; i < NUM_FADERS; i++)
    {
        addOutput(createOutput<ThemedPJ301MPort>(Vec(26 + 43 * i, 26), module, i));
        addParam(createParam<FaderbankSliderYellow>(Vec(23 + 43 * i, 66), module, i));
    }
}

void FaderbankWidget::draw(const DrawArgs& args)
{
    nvgBeginPath(args.vg);
    nvgRect(args.vg, 0.0, 0.0, box.size.x, box.size.y);
    nvgFillColor(args.vg, nvgRGB(0xe6, 0xe6, 0xe6));
    nvgFill(args.vg);
    Widget::draw(args);
}

void FaderbankWidget::appendContextMenu(Menu* menu)
{
}