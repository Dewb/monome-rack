#include "rack.hpp"

#pragma once

struct FaderbankModule;

struct FaderbankWidget : rack::app::ModuleWidget
{
    FaderbankWidget(FaderbankModule* module);

    void appendContextMenu(rack::ui::Menu* menu) override;
};
