#include "monomewidgets.hpp"

WhiteLight::WhiteLight()
{
    addBaseColor(COLOR_WHITE);
}

void USBAJack::draw(NVGcontext* vg)
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
