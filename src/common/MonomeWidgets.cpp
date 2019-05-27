#include "MonomeWidgets.hpp"

extern rack::Plugin* pluginInstance;

WhiteLight::WhiteLight()
{
    addBaseColor(rack::COLOR_WHITE);
}

void USBAJack::draw(NVGcontext* vg)
{
    nvgBeginPath(vg);
    nvgRect(vg, 0, 0, 38, 14);
    nvgFillColor(vg, nvgRGB(0, 0, 0));
    nvgFill(vg);

    nvgBeginPath(vg);
    nvgRect(vg, 4, 4, 30, 3);
    nvgFillColor(vg, nvgRGB(120, 120, 120));
    nvgFill(vg);
}

MonomeKnob::MonomeKnob()
{
    setSVG(rack::SVG::load(rack::asset::plugin(pluginInstance, "res/MonomeKnob.svg")));
    box.size = rack::Vec(42, 42);
}