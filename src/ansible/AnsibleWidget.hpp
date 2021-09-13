#include "LibAVR32ModuleWidget.hpp"

#pragma once

struct AnsibleModule;

struct AnsibleWidget : LibAVR32ModuleWidget
{
    AnsibleWidget(AnsibleModule* module);
};
