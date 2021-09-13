#include "LibAVR32ModuleWidget.hpp"

#pragma once

struct TeletypeModule;

struct TeletypeWidget : LibAVR32ModuleWidget
{
    TeletypeWidget(TeletypeModule* module);

    virtual void appendContextMenu(rack::ui::Menu* menu) override;
};