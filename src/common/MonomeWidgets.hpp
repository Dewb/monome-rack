#include "rack.hpp"

#pragma once

struct WhiteLight : rack::GrayModuleLightWidget
{
    WhiteLight();
};

struct USBAJack : rack::TransparentWidget
{
    void draw(const DrawArgs& args) override;
};

struct MonomeKnob : rack::RoundKnob
{
    MonomeKnob();
};