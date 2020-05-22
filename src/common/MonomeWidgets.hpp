#include "rack.hpp"

#pragma once

using namespace rack;

struct USBAJack : TransparentWidget
{
    void draw(const DrawArgs& args) override;
};

struct MonomeKnob : rack::componentlibrary::RoundKnob
{
    MonomeKnob();
};