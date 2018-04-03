#include "MonomeModuleBaseWidget.hpp"

#pragma once

struct EarthseaModule;

struct EarthseaWidget : MonomeModuleBaseWidget
{
    EarthseaWidget(EarthseaModule* module);
    void randomize() override;
};
