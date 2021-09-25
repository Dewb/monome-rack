#include <LibAVR32ModuleWidget.hpp>

typedef enum
{
    Load = 0,
    Save
} Operation;

struct InternalPresetSubmenu : rack::ui::MenuItem
{
    LibAVR32Module* module;
    Operation operation;

    InternalPresetSubmenu(LibAVR32Module* module, std::string _text, Operation operation);
    rack::ui::Menu* createChildMenu() override;
};