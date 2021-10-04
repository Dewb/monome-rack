#include "CommonWidgets.hpp"

extern rack::Plugin* pluginInstance;

void USBAJack::draw(const DrawArgs& args)
{
    auto vg = args.vg;
    nvgBeginPath(vg);
    nvgRoundedRect(vg, 0, 0, 38, 14, 1.5);
    nvgFillColor(vg, nvgRGB(0, 0, 0));
    nvgFill(vg);

    nvgBeginPath(vg);
    nvgRect(vg, 4, 4, 30, 3);
    nvgFillColor(vg, nvgRGB(120, 120, 120));
    nvgFill(vg);
}
