#include "rack.hpp"

#pragma once

using namespace rack;

struct USBAJack : MomentarySwitch<Switch>
{
    USBAJack();

    void draw(const DrawArgs& args) override;
    void onButton(const ButtonEvent& e) override;
    void appendContextMenu(ui::Menu* menu) override;

    std::function<void(void)> action;
};

struct YellowWhiteLight : rack::componentlibrary::GrayModuleLightWidget
{
    YellowWhiteLight() {
        this->addBaseColor(SCHEME_YELLOW);
        this->addBaseColor(SCHEME_WHITE);
    }
};