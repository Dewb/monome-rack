#pragma once

#include <rack.hpp>

struct Sifam : rack::app::SvgKnob
{
    rack::widget::SvgWidget* bg;
    rack::widget::SvgWidget* fg;
    rack::widget::SvgWidget* indicator;
    rack::widget::TransformWidget* indicatorTransform;

    Sifam()
    {
        minAngle = -0.83 * M_PI;
        maxAngle = 0.83 * M_PI;

        bg = new rack::widget::SvgWidget;
        fb->addChildBelow(bg, tw);

        fg = new rack::widget::SvgWidget;
        fb->addChildAbove(fg, tw);

        indicatorTransform = new rack::widget::TransformWidget;
        indicator = new rack::widget::SvgWidget;
        indicatorTransform->addChild(indicator);
        fb->addChildAbove(indicatorTransform, fg);
    }

    void onChange(const ChangeEvent& e) override
    {
        SvgKnob::onChange(e);
        for (int i = 0; i < 6; i++) 
        {
            indicatorTransform->transform[i] = tw->transform[i];
        }
    }
};

struct SifamTPN111GrayBlackStripe : Sifam
{
    SifamTPN111GrayBlackStripe()
    {
        setSvg(rack::window::Svg::load(rack::asset::plugin(pluginInstance, "res/SifamTPN111.svg")));
        bg->setSvg(rack::window::Svg::load(rack::asset::plugin(pluginInstance, "res/SifamTPN111-bg.svg")));
        fg->setSvg(rack::window::Svg::load(rack::asset::plugin(pluginInstance, "res/SifamTPN111-gray-fg.svg")));
        indicator->setSvg(rack::window::Svg::load(rack::asset::plugin(pluginInstance, "res/SifamTPN111-blackstripe.svg")));
        indicatorTransform->box.size = indicator->box.size;
    }
};