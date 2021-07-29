#include "MonomeModuleBaseWidget.hpp"

#pragma once

struct AnsibleModule;

struct AnsibleWidget : MonomeModuleBaseWidget
{
    AnsibleWidget(AnsibleModule* module);
};
