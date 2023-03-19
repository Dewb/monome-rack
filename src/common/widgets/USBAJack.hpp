#pragma once

#include "rack.hpp"
#include "LibAVR32Module.hpp"


struct USBAJack : rack::Switch
{
    USBAJack()
    {
        box.size = rack::Vec(44, 23.75);
    }

    void draw(const DrawArgs& args) override
    {
        auto vg = args.vg;
        auto m = dynamic_cast<LibAVR32Module*>(module);

        float w = box.size.x;
        float h = box.size.y;
        float z = 4.75;

        rack::engine::ParamQuantity* pq = getParamQuantity();
        if (pq && pq->getValue() >= 1.0)
        {
            // draw shadow
            nvgBeginPath(vg);
            nvgRoundedRect(vg, 0, z - 1, w, h - z + 1, 4.5);
            nvgFillColor(vg, nvgRGB(165, 165, 165));
            nvgFill(vg);

            // draw face
            nvgBeginPath(vg);
            nvgRoundedRect(vg, 0, 0, w, h - z + 1, 3.5);
            nvgFillColor(vg, nvgRGB(200, 200, 200));
            nvgFill(vg);

            // draw 3D highlight
            nvgBeginPath(vg);
            nvgRoundedRect(vg, 2, 1, w - 4, h - z - 1, 3);
            nvgFillPaint(vg, nvgBoxGradient(vg, 2, 1, w - 4, 18, 2, 5, nvgRGB(225, 225, 225), nvgRGB(190, 190, 190)));
            nvgFill(vg);

            // draw embossed text label
            std::string label = m->currentConnectedDeviceId.substr(0, 11);
            nvgFontSize(vg, 6.0);
            nvgTextAlign(vg, NVG_ALIGN_RIGHT | NVG_ALIGN_BOTTOM);
            nvgFillColor(vg, nvgRGB(250, 250, 250));
            nvgText(vg, w - 4.1, z + 12.4, label.c_str(), 0);
            nvgFillColor(vg, nvgRGB(150, 150, 150));
            nvgText(vg, w - 4.5, z + 12, label.c_str(), 0);
        }
        else
        {
            // draw port background
            nvgBeginPath(vg);
            nvgRoundedRect(vg, 3, z, w - 6, h - z - 5, 1.5);
            nvgFillColor(vg, nvgRGB(0, 0, 0));
            nvgFill(vg);

            // draw connector base
            nvgBeginPath(vg);
            nvgRect(vg, 7, 4 + z, w - 14, 6);
            nvgFillColor(vg, nvgRGB(50, 50, 50));
            nvgFill(vg);

            // draw contacts
            float p = (w - 14) / 8.5;
            nvgBeginPath(vg);
            nvgRoundedRect(vg, 7 + 1 * p, z + 5, p, 4, 1.5);
            nvgRoundedRect(vg, 7 + 2.9 * p, z + 5, p, 3.5, 1.5);
            nvgRoundedRect(vg, 7 + 4.6 * p, z + 5, p, 3.5, 1.5);
            nvgRoundedRect(vg, 7 + 6.5 * p, z + 5, p, 4, 1.5);
            nvgFillColor(vg, nvgRGB(77, 75, 0));
            nvgFill(vg);

            // draw connector prong
            nvgBeginPath(vg);
            nvgRect(vg, 7, 4 + z, 30, 3);
            nvgFillColor(vg, nvgRGB(120, 120, 120));
            nvgFill(vg);
        }
    }

    void appendContextMenu(rack::ui::Menu* menu) override
    {
        auto mw = dynamic_cast<LibAVR32ModuleWidget*>(parent);
        if (mw)
        {
            menu->addChild(new rack::MenuSeparator());
            mw->appendConnectionMenu(menu);
        }
    }
};
