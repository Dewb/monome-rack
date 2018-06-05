#include "MonomeModuleBaseWidget.hpp"

#pragma once

struct WhiteWhaleModule;

struct WhiteWhaleWidget : MonomeModuleBaseWidget
{
    WhiteWhaleWidget(WhiteWhaleModule* module);
    void randomize() override;
};
