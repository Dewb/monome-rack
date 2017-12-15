#include "rack.hpp"

#pragma once

extern rack::Plugin* plugin;

struct MonomeModuleBaseWidget : rack::ModuleWidget
{
    MonomeModuleBaseWidget();
    rack::Menu* createContextMenu() override;
};