#include "LibAVR32Module.hpp"
#include "rack.hpp"

#pragma once

extern rack::Plugin* pluginInstance;

struct LibAVR32ModuleWidget : rack::app::ModuleWidget
{
    LibAVR32ModuleWidget();

    virtual void appendContextMenu(rack::ui::Menu* menu) override;
    void appendConnectionMenu(rack::Menu* menu);
};