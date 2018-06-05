#include "MonomeModuleBaseWidget.hpp"

#pragma once

struct MeadowphysicsModule;

struct MeadowphysicsWidget : MonomeModuleBaseWidget
{
    MeadowphysicsWidget(MeadowphysicsModule* module);
    void randomize() override;
};
