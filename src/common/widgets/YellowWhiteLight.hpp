#pragma once

#include "rack.hpp"

struct YellowWhiteLight : rack::componentlibrary::GrayModuleLightWidget
{
    YellowWhiteLight() {
        this->addBaseColor(rack::SCHEME_YELLOW);
        this->addBaseColor(rack::SCHEME_WHITE);
    }
};