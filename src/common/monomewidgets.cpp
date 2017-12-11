#include "monomewidgets.hpp"

WhiteLight::WhiteLight()
{
    addBaseColor(COLOR_WHITE);
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
    setSVG(SVG::load(assetPlugin(plugin, "res/MonomeKnob.svg")));
    box.size = Vec(42, 42);
}