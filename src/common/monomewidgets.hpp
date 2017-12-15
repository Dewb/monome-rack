#include "rack.hpp"

#pragma once

struct WhiteLight : rack::ModuleLightWidget
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