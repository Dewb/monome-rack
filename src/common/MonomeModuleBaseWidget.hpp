#include "MonomeModuleBase.hpp"
#include "rack.hpp"

#pragma once

extern rack::Plugin* pluginInstance;

struct MonomeModuleBaseWidget : rack::app::ModuleWidget
{
    MonomeModuleBaseWidget();

    virtual void appendContextMenu(rack::ui::Menu* menu) override;
};