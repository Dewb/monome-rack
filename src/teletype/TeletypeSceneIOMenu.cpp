#include "TeletypeSceneIOMenu.hpp"

#include "osdialog.h"
#include "rack.hpp"
#include <iomanip>

#ifdef ARCH_WIN
#define PATH_SEPARATOR '\\'
#else
#define PATH_SEPARATOR '/'
#endif

struct InternalPresetItem : rack::ui::MenuItem
{
    LibAVR32Module* module;
    int preset_num;
    SceneOperation operation;

    InternalPresetItem(LibAVR32Module* module, int preset_num, SceneOperation operation)
        : module(module)
        , preset_num(preset_num)
        , operation(operation)
    {
        if (preset_num == -1)
        {
            text = (operation == Load ? "Import from file" : "Export to file");
        } else {
            text = (operation == Load ? ".txt → " : "") + std::to_string(preset_num) + (operation == Save ? " → .txt" : "");
        }
    }

    void onAction(const rack::event::Action& e) override
    {
        osdialog_filters* filters = osdialog_filters_parse("Teletype Scene Files (*.txt):txt");

        std::stringstream defaultFileName;
        if (preset_num < 0)
        {
            defaultFileName << "tt_active" << (operation == Save ? "_s.txt" : ".txt");
        }
        else
        {
            defaultFileName
                << "tt"
                << std::setw(2) << std::setfill('0') << preset_num
                << (operation == Save ? "s.txt" : ".txt");
        }

        char* path_result = osdialog_file(
            operation == Save ? OSDIALOG_SAVE : OSDIALOG_OPEN,
            NULL,
            defaultFileName.str().c_str(),
            filters);

        osdialog_filters_free(filters);

        if (!path_result)
            return;

        std::string path(path_result);
        std::free(path_result);

        presetImportExportFileOperation(module, operation, preset_num, path);
    }
};

struct InternalPresetClipboardItem : rack::ui::MenuItem
{
    LibAVR32Module* module;
    int preset_num;
    SceneOperation operation;
    bool clearExisting;

    InternalPresetClipboardItem(LibAVR32Module* module, int preset_num, SceneOperation operation, bool clearExisting = true)
        : module(module)
        , preset_num(preset_num)
        , operation(operation)
        , clearExisting(clearExisting)
    {
        text = (operation == Save ?
            "Copy to clipboard" :
            (clearExisting ? "Paste and init new scene from clipboard" : "Paste and merge clipboard into current scene"));
    }

    void onAction(const rack::event::Action& e) override
    {
        presetImportExportClipboardOperation(module, operation, preset_num, clearExisting);
    }
};

struct InternalPresetBulkItem : rack::ui::MenuItem
{
    LibAVR32Module* module;
    SceneOperation operation;
    std::string suffix;

    InternalPresetBulkItem(LibAVR32Module* module, SceneOperation operation, std::string suffix)
        : module(module)
        , operation(operation)
        , suffix(suffix)
    {
        text = operation == Load
            ? ("tt##" + suffix + ".txt → All")
            : ("All → tt##" + suffix + ".txt");
    }

    void onAction(const rack::event::Action& e) override
    {
        char* path_result = osdialog_file(
            OSDIALOG_OPEN_DIR,
            NULL,
            NULL,
            NULL);

        if (!path_result)
            return;

        std::string path(path_result);
        std::free(path_result);

        for (int i = 0; i < 32; i++)
        {
            std::stringstream fileName;
            fileName
                << path
                << PATH_SEPARATOR
                << "tt"
                << std::setfill('0') << std::setw(2) << i
                << suffix
                << ".txt";
            presetImportExportFileOperation(module, operation, i, fileName.str());
        }
    }
};

struct InternalPresetActiveSubmenu : rack::ui::MenuItem
{
    LibAVR32Module* module;
    SceneOperation operation;

    InternalPresetActiveSubmenu(LibAVR32Module* module, SceneOperation operation)
        : module(module)
        , operation(operation)
    {
        text = "Active scene";
        rightText = "▸";
    }

    rack::ui::Menu* createChildMenu() override
    {
        LibAVR32Module* m = dynamic_cast<LibAVR32Module*>(module);
        assert(m);

        auto menu = new rack::ui::Menu();

        menu->addChild(new InternalPresetItem(module, -1, operation));
        menu->addChild(new InternalPresetClipboardItem(module, -1, operation));
        if (operation == Load) {
            menu->addChild(new InternalPresetClipboardItem(module, -1, operation, false));  // paste and merge
        }

        return menu;
    }
};

struct InternalPresetGroupSubmenu : rack::ui::MenuItem
{
    LibAVR32Module* module;
    SceneOperation operation;
    int first;
    int last;

    InternalPresetGroupSubmenu(LibAVR32Module* module, int first, int last, SceneOperation operation)
        : module(module)
        , operation(operation)
        , first(first)
        , last(last)
    {
        text = std::to_string(first) + " - " + std::to_string(last);
        rightText = "▸";
    }

    rack::ui::Menu* createChildMenu() override
    {
        LibAVR32Module* m = dynamic_cast<LibAVR32Module*>(module);
        assert(m);

        auto menu = new rack::ui::Menu();

        for (int i = first; i <= last; i++)
        {
            menu->addChild(new InternalPresetItem(module, i, operation));
        }
        return menu;
    }
};

InternalPresetSubmenu::InternalPresetSubmenu(LibAVR32Module* module, std::string _text, SceneOperation operation)
    : module(module)
    , operation(operation)
{
    text = _text;
    rightText = "▸";
}

rack::ui::Menu* InternalPresetSubmenu::createChildMenu()
{
    LibAVR32Module* m = dynamic_cast<LibAVR32Module*>(module);
    assert(m);

    auto menu = new rack::ui::Menu();

    menu->addChild(new InternalPresetActiveSubmenu(module, operation));

    for (int i = 0; i < 4; i++)
    {
        menu->addChild(new InternalPresetGroupSubmenu(module, i * 8, i * 8 + 7, operation));
    }
    menu->addChild(new InternalPresetBulkItem(module, operation, ""));
    menu->addChild(new InternalPresetBulkItem(module, operation, "s"));
    return menu;
}
