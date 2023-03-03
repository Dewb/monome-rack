#include "TeletypeSceneIO.hpp"
#include <LibAVR32ModuleWidget.hpp>

struct InternalPresetSubmenu : rack::ui::MenuItem
{
    LibAVR32Module* module;
    SceneOperation operation;

    InternalPresetSubmenu(LibAVR32Module* module, std::string _text, SceneOperation operation);
    rack::ui::Menu* createChildMenu() override;
};