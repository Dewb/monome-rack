#include "rack.hpp"

#pragma once

using namespace rack;

struct USBAJack : TransparentWidget
{
    void draw(const DrawArgs& args) override;
};

struct YellowWhiteLight : rack::componentlibrary::GrayModuleLightWidget
{
    YellowWhiteLight() {
        this->addBaseColor(SCHEME_YELLOW);
        this->addBaseColor(SCHEME_WHITE);
    }
};