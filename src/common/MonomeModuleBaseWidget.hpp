#include "MonomeModuleBase.hpp"
#include "rack.hpp"

#pragma once

extern rack::Plugin* pluginInstance;

struct MonomeModuleBaseWidget : rack::app::ModuleWidget
{
    MonomeModuleBaseWidget(MonomeModuleBase* module);

    virtual void appendContextMenu(rack::ui::Menu* menu) override;
};