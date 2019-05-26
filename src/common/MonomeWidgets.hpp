#include "rack0.hpp"

#pragma once

struct WhiteLight : rack::GrayModuleLightWidget
{
    WhiteLight();
};

struct USBAJack : rack::TransparentWidget
{
    void draw(NVGcontext* vg) override;
};

struct MonomeKnob : rack::RoundKnob
{
    MonomeKnob();
};