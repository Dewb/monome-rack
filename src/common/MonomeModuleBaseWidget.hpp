#include "rack.hpp"
#include "MonomeModuleBase.hpp"

#pragma once

extern rack::Plugin* plugin;

struct MonomeModuleBaseWidget : rack::ModuleWidget
{
    MonomeModuleBaseWidget(MonomeModuleBase* module);
    rack::Menu* createContextMenu() override;
};