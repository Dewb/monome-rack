#include "rack.hpp"

#pragma once

using namespace rack;

struct WhiteLight : rack::componentlibrary::GrayModuleLightWidget
{
    WhiteLight();
};

struct USBAJack : TransparentWidget
{
    void draw(const DrawArgs& args) override;
};

struct MonomeKnob : rack::componentlibrary::RoundKnob
{
    MonomeKnob();
};