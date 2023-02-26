#include "CommonWidgets.hpp"
#include "LibAVR32Module.hpp"

extern rack::Plugin* pluginInstance;

void USBAJack::draw(const DrawArgs& args)
{
    auto vg = args.vg;
    auto m = dynamic_cast<LibAVR32Module*>(module);

    if (m && m->connectionOwned && m->gridConnection)
    {
        float height = 4.75;

        nvgBeginPath(vg);
        nvgRoundedRect(vg, -3, -1, 44, 20, 4.5);
        nvgFillColor(vg, nvgRGB(165, 165, 165));
        nvgFill(vg);

        nvgBeginPath(vg);
        nvgRoundedRect(vg, -3, -height, 44, 20, 3.5);
        nvgFillColor(vg, nvgRGB(200, 200, 200));
        nvgFill(vg);

        nvgBeginPath(vg);
        nvgRoundedRect(vg, -1, -height+1, 40, 18, 3);
        nvgFillPaint(vg, nvgBoxGradient(vg, -1, -height+1, 40, 18, 2, 5, nvgRGB(225, 225, 225), nvgRGB(190, 190, 190)));
        nvgFill(vg);

        auto id = m->gridConnection->getDevice().id;
        auto label = id.substr(0, 9);
        nvgFontSize(vg, 6.0);
        nvgTextAlign(vg, NVG_ALIGN_RIGHT | NVG_ALIGN_BOTTOM);
        nvgFillColor(vg, nvgRGB(250, 250, 250));
        nvgText(vg, 36.2, 12.4, label.c_str(), 0);
        nvgFillColor(vg, nvgRGB(170, 170, 170));
        nvgText(vg, 35.8, 12, label.c_str(), 0);
    }
    else
    {
        nvgBeginPath(vg);
        nvgRoundedRect(vg, 0, 0, 38, 14, 1.5);
        nvgFillColor(vg, nvgRGB(0, 0, 0));
        nvgFill(vg);

        nvgBeginPath(vg);
        nvgRect(vg, 4, 4, 30, 6);
        nvgFillColor(vg, nvgRGB(50, 50, 50));
        nvgFill(vg);

        float p = 30 / 8.5;

        nvgBeginPath(vg);
        nvgRoundedRect(vg, 4 + 1 * p, 5, p, 4, 1.5);
        nvgRoundedRect(vg, 4 + 2.9 * p, 5, p, 3.5, 1.5);
        nvgRoundedRect(vg, 4 + 4.6 * p, 5, p, 3.5, 1.5);
        nvgRoundedRect(vg, 4 + 6.5 * p, 5, p, 4, 1.5);
        nvgFillColor(vg, nvgRGB(77, 75, 0));
        nvgFill(vg);

        nvgBeginPath(vg);
        nvgRect(vg, 4, 4, 30, 3);
        nvgFillColor(vg, nvgRGB(120, 120, 120));
        nvgFill(vg);
    }
}

void USBAJack::onButton(const ButtonEvent& e)
{
    MomentarySwitch<Switch>::onButton(e);
    if (action != nullptr)
    {
        action();
    }
}
