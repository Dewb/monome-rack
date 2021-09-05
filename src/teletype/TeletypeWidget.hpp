#include "MonomeModuleBaseWidget.hpp"

#pragma once

struct TeletypeModule;

struct TeletypeWidget : MonomeModuleBaseWidget
{
    TeletypeWidget(TeletypeModule* module);
    
    virtual void appendContextMenu(rack::ui::Menu* menu) override;
};