#include "TeletypeSceneIO.hpp"
#include "LibAVR32Module.hpp"

#include "osdialog.h"
#include <regex>
#include <fstream>

#include "rack.hpp"

void TeletypeSceneIO::presetImportExportFileOperation(LibAVR32Module* module, SceneOperation operation, int preset_num, std::string fileName)
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
        std::ifstream ifs(fileName);
        std::string scene(
            (std::istreambuf_iterator<char>(ifs)),
            (std::istreambuf_iterator<char>())
        );

        TeletypeSceneIO::presetImportString(module, scene, preset_num, true);
    }
}

void TeletypeSceneIO::presetImportExportClipboardOperation(LibAVR32Module* module, SceneOperation operation, int preset_num, bool clearExisting)
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

        TeletypeSceneIO::presetImportString(module, rawclip, preset_num, clearExisting);
    }
}

void TeletypeSceneIO::presetImportString(LibAVR32Module* module, std::string scene, int preset_num, bool clearExisting)
{
    // Remove any linefeeds
    scene.erase(std::remove(scene.begin(), scene.end(), '\r'), scene.end());

    // Tabs in pattern/grid sections may have been turned into spaces. Turn them back
    auto patStart = scene.find("#P");
    auto gridStart = scene.find("#G");
    if (patStart != std::string::npos || gridStart != std::string::npos)
    {
        auto start =
            patStart == std::string::npos
                ? gridStart
                : gridStart == std::string::npos
                    ? patStart
                    : std::min(patStart, gridStart);

        std::regex r(" +");
        std::string tab("\t");
        std::string result = scene.substr(0, start);
        std::regex_replace(std::back_inserter(result), scene.begin() + start, scene.end(), r, tab);
        scene = result;
    }

    // Add a final newline, since a selection in discord/browser probably won't include it
    scene += "\n";

    module->audioThreadActions.push([=]() {
        std::stringstream clip(scene);

        tt_deserializer_t stream {
            .read_char = [](void* user_data)
            { return static_cast<uint16_t>(static_cast<std::stringstream*>(user_data)->get()); },
            .eof = [](void* user_data)
            { return static_cast<std::stringstream*>(user_data)->eof(); },
            .print_dbg = [](const char* c) {},
            .data = (void*)&clip,
        };

        module->firmware.deserializePreset(&stream, preset_num, clearExisting);
    });
}
