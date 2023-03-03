#include <string>

struct LibAVR32Module;

typedef enum
{
    Load = 0,
    Save
} SceneOperation;

void presetImportString(LibAVR32Module* module, std::string scene, int preset_num, bool clearExisting);

void presetImportExportFileOperation(LibAVR32Module* module, SceneOperation operation, int preset_num, std::string fileName);
void presetImportExportClipboardOperation(LibAVR32Module* module, SceneOperation operation, int preset_num, bool clearExisting);
