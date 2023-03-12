#include <string>

struct LibAVR32Module;

typedef enum
{
    Load = 0,
    Save
} SceneOperation;

struct TeletypeSceneIO
{
    static void presetImportString(LibAVR32Module* module, std::string scene, int preset_num, bool clearExisting);

    static void presetImportExportFileOperation(LibAVR32Module* module, SceneOperation operation, int preset_num, std::string fileName);
    static void presetImportExportClipboardOperation(LibAVR32Module* module, SceneOperation operation, int preset_num, bool clearExisting);
};