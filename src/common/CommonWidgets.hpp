#include "rack.hpp"

#pragma once

using namespace rack;

struct USBAJack : Switch
{
    USBAJack();

    void draw(const DrawArgs& args) override;
    void appendContextMenu(ui::Menu* menu) override;
};

struct YellowWhiteLight : rack::componentlibrary::GrayModuleLightWidget
{
    YellowWhiteLight() {
        this->addBaseColor(SCHEME_YELLOW);
        this->addBaseColor(SCHEME_WHITE);
    }
};