#include <rack.hpp>

#pragma once

struct TTExpanderModule;

struct TTExpanderWidget : rack::ModuleWidget
{
    TTExpanderWidget(TTExpanderModule* module);
};
