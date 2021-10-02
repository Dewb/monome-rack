#include "TeletypeSceneIO.hpp"

#include "osdialog.h"
#include "rack.hpp"
#include <iomanip>
#include <regex>

#ifdef ARCH_WIN
#define PATH_SEPARATOR '\\'
#else
#define PATH_SEPARATOR '/'
#endif

void presetImportExportFileOperation(LibAVR32Module* module, Operation operation, int preset_num, std::string fileName)
{
    if (!module)
    {
        return;
    }

    if (operation == Save)
    {
        FILE* file = std::fopen(fileName.c_str(), "w+");
        if (!file)
        {
            std::string message = rack::string::f("Couldn't write to %s. Error: %d", fileName.c_str(), errno);
            osdialog_message(OSDIALOG_WARNING, OSDIALOG_OK, message.c_str());
            return;
        }
        DEFER({
            std::fclose(file);
        });

        tt_serializer_t stream {
            .write_buffer = [](void* user_data, uint8_t* buffer, uint16_t size)
            { std::fwrite(buffer, 1, size, static_cast<FILE*>(user_data)); },
            .write_char = [](void* user_data, uint8_t c)
            { std::fputc(c, static_cast<FILE*>(user_data)); },
            .print_dbg = [](const char* c) {},
            .data = (void*)file,
        };

        module->firmware.serializePreset(&stream, preset_num);
    }
    else
    {
        FILE* file = std::fopen(fileName.c_str(), "r");
        if (!file)
        {
            std::string message("Couldn't read from file.");
            osdialog_message(OSDIALOG_WARNING, OSDIALOG_OK, message.c_str());
            return;
        }
        DEFER({
            std::fclose(file);
        });

        tt_deserializer_t stream {
            .read_char = [](void* user_data)
            { return static_cast<uint16_t>(std::fgetc(static_cast<FILE*>(user_data))); },
            .eof = [](void* user_data)
            { return std::feof(static_cast<FILE*>(user_data)) != 0; },
            .print_dbg = [](const char* c) {},
            .data = (void*)file,
        };

        module->firmware.deserializePreset(&stream, preset_num);
    }
}

void presetImportExportClipboardOperation(LibAVR32Module* module, Operation operation, int preset_num)
{
    if (!module)
    {
        return;
    }

    if (operation == Save)
    {
        std::stringstream clip;

        tt_serializer_t stream {
            .write_buffer = [](void* user_data, uint8_t* buffer, uint16_t size)
            { *static_cast<std::stringstream*>(user_data) << std::string(buffer, buffer + size); },
            .write_char = [](void* user_data, uint8_t c)
            { *static_cast<std::stringstream*>(user_data) << c; },
            .print_dbg = [](const char* c) {},
            .data = (void*)&clip,
        };

        module->firmware.serializePreset(&stream, preset_num);

        glfwSetClipboardString(APP->window->win, clip.str().c_str());
    }
    else
    {
        std::string rawclip(glfwGetClipboardString(APP->window->win));

        // Remove any linefeeds
        rawclip.erase(std::remove(rawclip.begin(), rawclip.end(), '\r'), rawclip.end());
        
        // Tabs in pattern/grid sections may have been turned into spaces. Turn them back
        auto patStart = rawclip.find("#P");
        auto gridStart = rawclip.find("#G");
        if (patStart != std::string::npos || gridStart != std::string::npos) {
            auto start = patStart == std::string::npos ?
                            gridStart :
                            gridStart == std::string::npos ?
                                patStart :
                                std::min(patStart, gridStart);
            std::regex r(" +");
            std::string tab("\t");
            std::string result = rawclip.substr(0, start);
            std::regex_replace(std::back_inserter(result), rawclip.begin() + start, rawclip.end(), r, tab);
            rawclip = result;
        }

        // Add a final newline, since a selection in discord/browser probably won't include it
        rawclip += "\n";

        std::stringstream clip(rawclip);

        tt_deserializer_t stream {
            .read_char = [](void* user_data)
            { return static_cast<uint16_t>(static_cast<std::stringstream*>(user_data)->get()); },
            .eof = [](void* user_data)
            { return static_cast<std::stringstream*>(user_data)->eof(); },
            .print_dbg = [](const char* c) {},
            .data = (void*)&clip,
        };

        module->firmware.deserializePreset(&stream, preset_num);
    }
}

struct InternalPresetItem : rack::ui::MenuItem
{
    LibAVR32Module* module;
    int preset_num;
    Operation operation;

    InternalPresetItem(LibAVR32Module* module, int preset_num, Operation operation)
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
    Operation operation;

    InternalPresetClipboardItem(LibAVR32Module* module, int preset_num, Operation operation)
        : module(module)
        , preset_num(preset_num)
        , operation(operation)
    {
        text = (operation == Load ? "Paste from clipboard" : "Copy to clipboard");
    }

    void onAction(const rack::event::Action& e) override
    {
        presetImportExportClipboardOperation(module, operation, preset_num);
    }
};

struct InternalPresetBulkItem : rack::ui::MenuItem
{
    LibAVR32Module* module;
    Operation operation;
    std::string suffix;

    InternalPresetBulkItem(LibAVR32Module* module, Operation operation, std::string suffix)
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
    Operation operation;

    InternalPresetActiveSubmenu(LibAVR32Module* module, Operation operation)
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

        return menu;
    }
};

struct InternalPresetGroupSubmenu : rack::ui::MenuItem
{
    LibAVR32Module* module;
    Operation operation;
    int first;
    int last;

    InternalPresetGroupSubmenu(LibAVR32Module* module, int first, int last, Operation operation)
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

InternalPresetSubmenu::InternalPresetSubmenu(LibAVR32Module* module, std::string _text, Operation operation)
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
