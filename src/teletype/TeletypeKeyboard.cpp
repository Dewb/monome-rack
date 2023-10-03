#include "TeletypeKeyboard.hpp"

#include "osdialog.h"
#include <system.hpp>

using namespace rack;

extern rack::Plugin* pluginInstance;

TeletypeKeyboard::KeycodeMap TeletypeKeyboard::keycodeMap;
bool TeletypeKeyboard::initialized = false;
std::string TeletypeKeyboard::currentLayout = "us-qwerty";

void TeletypeKeyboard::init()
{
    if (!initialized)
    {
        loadMap();
        initialized = true;
    }
}

void TeletypeKeyboard::setCurrentLayout(std::string layoutName)
{
    if (currentLayout != layoutName)
    {
        currentLayout = layoutName;
        initialized = false;
    }
}

const std::string& TeletypeKeyboard::getCurrentLayout()
{
    return currentLayout;
}

void TeletypeKeyboard::loadMap()
{
    auto path = rack::asset::plugin(pluginInstance, "res/keymaps/" + currentLayout + ".json");

    FILE* file = std::fopen(path.c_str(), "r");
    if (!file)
        return;
    DEFER({ std::fclose(file); });

    json_error_t error;
    json_t* rootJ = json_loadf(file, 0, &error);
    if (!rootJ)
    {
        std::string message = rack::string::f(
            "Teletype keymap file %s has invalid JSON at line %d, column %d.\n\nError text: %s",
            path.c_str(),
            error.line,
            error.column,
            error.text
        );
        osdialog_message(OSDIALOG_WARNING, OSDIALOG_OK, message.c_str());
        return;
    }

    DEFER({ json_decref(rootJ); });

    keycodeMap.clear();

    json_t* mapArrayJ = json_object_get(rootJ, "keymap");
    if (mapArrayJ)
    {
        size_t i;
        json_t* mapEntryJ;
        json_array_foreach(mapArrayJ, i, mapEntryJ)
        {
            json_t* inputJ = json_object_get(mapEntryJ, "input");
            json_t* outputJ = json_object_get(mapEntryJ, "output");
            if (inputJ && outputJ)
            {
                int inputCode = stringToGLFWCode(std::string(json_string_value(inputJ)));
                uint8_t outputCode = stringToHIDCode(std::string(json_string_value(outputJ)));
                if (inputCode != GLFW_KEY_UNKNOWN && outputCode != 0)
                {
                    int inputMod = 0;
                    uint8_t outputMod = 0;

                    json_t* inputShift = json_object_get(mapEntryJ, "input_shift");
                    json_t* outputShift = json_object_get(mapEntryJ, "output_shift");

                    if (inputShift && json_boolean_value(inputShift))
                    {
                        inputMod |= GLFW_MOD_SHIFT;
                    }

                    if (outputShift && json_boolean_value(outputShift))
                    {
                        outputMod |= 0x02;
                    }

                    keycodeMap.insert(std::make_pair(std::make_pair(inputCode, inputMod), std::make_pair(outputCode, outputMod)));
                }
            }
        }
    }
}

bool TeletypeKeyboard::process(const rack::event::SelectKey& e, uint8_t* pKey, uint8_t* pMod)
{
    init();

    uint8_t key = 0;
    uint8_t mod = 0;

    bool found = false;
    bool shiftConsumed = false;

    // Look for a mapping with shift explicitly set
    if (e.mods & GLFW_MOD_SHIFT)
    {
        auto result = keycodeMap.find(std::make_pair(e.key, GLFW_MOD_SHIFT));
        if (result != keycodeMap.end())
        {
            key = result->second.first;
            mod = result->second.second;
            found = true;
            shiftConsumed = true;
        }
    }

    // Look for a mapping of the keycode with no modifiers
    if (!found)
    {
        auto result = keycodeMap.find(std::make_pair(e.key, 0));
        if (result != keycodeMap.end())
        {
            key = result->second.first;
            mod = result->second.second;
            found = true;
        }
    }

    if (e.mods & GLFW_MOD_CONTROL)
    {
        mod |= 0x1;
    }
    if ((e.mods & GLFW_MOD_SHIFT) && !shiftConsumed)
    {
        mod |= 0x2;
    }
    if (e.mods & GLFW_MOD_ALT)
    {
        mod |= 0x4;
    }
    if (e.mods & GLFW_MOD_SUPER)
    {
        mod |= 0x8;
    }

    if (found)
    {
        if (pKey)
        {
            *pKey = key;
        }

        if (pMod)
        {
            *pMod = mod;
        }
    }

    return found;
}

int TeletypeKeyboard::stringToGLFWCode(std::string s)
{
    // Defines from glfw3.h
    if (s == "GLFW_KEY_UNKNOWN")
        return GLFW_KEY_UNKNOWN;
    else if (s == "GLFW_KEY_SPACE")
        return GLFW_KEY_SPACE;
    else if (s == "GLFW_KEY_APOSTROPHE")
        return GLFW_KEY_APOSTROPHE;
    else if (s == "GLFW_KEY_COMMA")
        return GLFW_KEY_COMMA;
    else if (s == "GLFW_KEY_MINUS")
        return GLFW_KEY_MINUS;
    else if (s == "GLFW_KEY_PERIOD")
        return GLFW_KEY_PERIOD;
    else if (s == "GLFW_KEY_SLASH")
        return GLFW_KEY_SLASH;
    else if (s == "GLFW_KEY_0")
        return GLFW_KEY_0;
    else if (s == "GLFW_KEY_1")
        return GLFW_KEY_1;
    else if (s == "GLFW_KEY_2")
        return GLFW_KEY_2;
    else if (s == "GLFW_KEY_3")
        return GLFW_KEY_3;
    else if (s == "GLFW_KEY_4")
        return GLFW_KEY_4;
    else if (s == "GLFW_KEY_5")
        return GLFW_KEY_5;
    else if (s == "GLFW_KEY_6")
        return GLFW_KEY_6;
    else if (s == "GLFW_KEY_7")
        return GLFW_KEY_7;
    else if (s == "GLFW_KEY_8")
        return GLFW_KEY_8;
    else if (s == "GLFW_KEY_9")
        return GLFW_KEY_9;
    else if (s == "GLFW_KEY_SEMICOLON")
        return GLFW_KEY_SEMICOLON;
    else if (s == "GLFW_KEY_EQUAL")
        return GLFW_KEY_EQUAL;
    else if (s == "GLFW_KEY_A")
        return GLFW_KEY_A;
    else if (s == "GLFW_KEY_B")
        return GLFW_KEY_B;
    else if (s == "GLFW_KEY_C")
        return GLFW_KEY_C;
    else if (s == "GLFW_KEY_D")
        return GLFW_KEY_D;
    else if (s == "GLFW_KEY_E")
        return GLFW_KEY_E;
    else if (s == "GLFW_KEY_F")
        return GLFW_KEY_F;
    else if (s == "GLFW_KEY_G")
        return GLFW_KEY_G;
    else if (s == "GLFW_KEY_H")
        return GLFW_KEY_H;
    else if (s == "GLFW_KEY_I")
        return GLFW_KEY_I;
    else if (s == "GLFW_KEY_J")
        return GLFW_KEY_J;
    else if (s == "GLFW_KEY_K")
        return GLFW_KEY_K;
    else if (s == "GLFW_KEY_L")
        return GLFW_KEY_L;
    else if (s == "GLFW_KEY_M")
        return GLFW_KEY_M;
    else if (s == "GLFW_KEY_N")
        return GLFW_KEY_N;
    else if (s == "GLFW_KEY_O")
        return GLFW_KEY_O;
    else if (s == "GLFW_KEY_P")
        return GLFW_KEY_P;
    else if (s == "GLFW_KEY_Q")
        return GLFW_KEY_Q;
    else if (s == "GLFW_KEY_R")
        return GLFW_KEY_R;
    else if (s == "GLFW_KEY_S")
        return GLFW_KEY_S;
    else if (s == "GLFW_KEY_T")
        return GLFW_KEY_T;
    else if (s == "GLFW_KEY_U")
        return GLFW_KEY_U;
    else if (s == "GLFW_KEY_V")
        return GLFW_KEY_V;
    else if (s == "GLFW_KEY_W")
        return GLFW_KEY_W;
    else if (s == "GLFW_KEY_X")
        return GLFW_KEY_X;
    else if (s == "GLFW_KEY_Y")
        return GLFW_KEY_Y;
    else if (s == "GLFW_KEY_Z")
        return GLFW_KEY_Z;
    else if (s == "GLFW_KEY_LEFT_BRACKET")
        return GLFW_KEY_LEFT_BRACKET;
    else if (s == "GLFW_KEY_BACKSLASH")
        return GLFW_KEY_BACKSLASH;
    else if (s == "GLFW_KEY_RIGHT_BRACKET")
        return GLFW_KEY_RIGHT_BRACKET;
    else if (s == "GLFW_KEY_GRAVE_ACCENT")
        return GLFW_KEY_GRAVE_ACCENT;
    else if (s == "GLFW_KEY_WORLD_1")
        return GLFW_KEY_WORLD_1;
    else if (s == "GLFW_KEY_WORLD_2")
        return GLFW_KEY_WORLD_2;
    else if (s == "GLFW_KEY_ESCAPE")
        return GLFW_KEY_ESCAPE;
    else if (s == "GLFW_KEY_ENTER")
        return GLFW_KEY_ENTER;
    else if (s == "GLFW_KEY_TAB")
        return GLFW_KEY_TAB;
    else if (s == "GLFW_KEY_BACKSPACE")
        return GLFW_KEY_BACKSPACE;
    else if (s == "GLFW_KEY_INSERT")
        return GLFW_KEY_INSERT;
    else if (s == "GLFW_KEY_DELETE")
        return GLFW_KEY_DELETE;
    else if (s == "GLFW_KEY_RIGHT")
        return GLFW_KEY_RIGHT;
    else if (s == "GLFW_KEY_LEFT")
        return GLFW_KEY_LEFT;
    else if (s == "GLFW_KEY_DOWN")
        return GLFW_KEY_DOWN;
    else if (s == "GLFW_KEY_UP")
        return GLFW_KEY_UP;
    else if (s == "GLFW_KEY_PAGE_UP")
        return GLFW_KEY_PAGE_UP;
    else if (s == "GLFW_KEY_PAGE_DOWN")
        return GLFW_KEY_PAGE_DOWN;
    else if (s == "GLFW_KEY_HOME")
        return GLFW_KEY_HOME;
    else if (s == "GLFW_KEY_END")
        return GLFW_KEY_END;
    else if (s == "GLFW_KEY_CAPS_LOCK")
        return GLFW_KEY_CAPS_LOCK;
    else if (s == "GLFW_KEY_SCROLL_LOCK")
        return GLFW_KEY_SCROLL_LOCK;
    else if (s == "GLFW_KEY_NUM_LOCK")
        return GLFW_KEY_NUM_LOCK;
    else if (s == "GLFW_KEY_PRINT_SCREEN")
        return GLFW_KEY_PRINT_SCREEN;
    else if (s == "GLFW_KEY_PAUSE")
        return GLFW_KEY_PAUSE;
    else if (s == "GLFW_KEY_F1")
        return GLFW_KEY_F1;
    else if (s == "GLFW_KEY_F2")
        return GLFW_KEY_F2;
    else if (s == "GLFW_KEY_F3")
        return GLFW_KEY_F3;
    else if (s == "GLFW_KEY_F4")
        return GLFW_KEY_F4;
    else if (s == "GLFW_KEY_F5")
        return GLFW_KEY_F5;
    else if (s == "GLFW_KEY_F6")
        return GLFW_KEY_F6;
    else if (s == "GLFW_KEY_F7")
        return GLFW_KEY_F7;
    else if (s == "GLFW_KEY_F8")
        return GLFW_KEY_F8;
    else if (s == "GLFW_KEY_F9")
        return GLFW_KEY_F9;
    else if (s == "GLFW_KEY_F10")
        return GLFW_KEY_F10;
    else if (s == "GLFW_KEY_F11")
        return GLFW_KEY_F11;
    else if (s == "GLFW_KEY_F12")
        return GLFW_KEY_F12;
    else if (s == "GLFW_KEY_F13")
        return GLFW_KEY_F13;
    else if (s == "GLFW_KEY_F14")
        return GLFW_KEY_F14;
    else if (s == "GLFW_KEY_F15")
        return GLFW_KEY_F15;
    else if (s == "GLFW_KEY_F16")
        return GLFW_KEY_F16;
    else if (s == "GLFW_KEY_F17")
        return GLFW_KEY_F17;
    else if (s == "GLFW_KEY_F18")
        return GLFW_KEY_F18;
    else if (s == "GLFW_KEY_F19")
        return GLFW_KEY_F19;
    else if (s == "GLFW_KEY_F20")
        return GLFW_KEY_F20;
    else if (s == "GLFW_KEY_F21")
        return GLFW_KEY_F21;
    else if (s == "GLFW_KEY_F22")
        return GLFW_KEY_F22;
    else if (s == "GLFW_KEY_F23")
        return GLFW_KEY_F23;
    else if (s == "GLFW_KEY_F24")
        return GLFW_KEY_F24;
    else if (s == "GLFW_KEY_F25")
        return GLFW_KEY_F25;
    else if (s == "GLFW_KEY_KP_0")
        return GLFW_KEY_KP_0;
    else if (s == "GLFW_KEY_KP_1")
        return GLFW_KEY_KP_1;
    else if (s == "GLFW_KEY_KP_2")
        return GLFW_KEY_KP_2;
    else if (s == "GLFW_KEY_KP_3")
        return GLFW_KEY_KP_3;
    else if (s == "GLFW_KEY_KP_4")
        return GLFW_KEY_KP_4;
    else if (s == "GLFW_KEY_KP_5")
        return GLFW_KEY_KP_5;
    else if (s == "GLFW_KEY_KP_6")
        return GLFW_KEY_KP_6;
    else if (s == "GLFW_KEY_KP_7")
        return GLFW_KEY_KP_7;
    else if (s == "GLFW_KEY_KP_8")
        return GLFW_KEY_KP_8;
    else if (s == "GLFW_KEY_KP_9")
        return GLFW_KEY_KP_9;
    else if (s == "GLFW_KEY_KP_DECIMAL")
        return GLFW_KEY_KP_DECIMAL;
    else if (s == "GLFW_KEY_KP_DIVIDE")
        return GLFW_KEY_KP_DIVIDE;
    else if (s == "GLFW_KEY_KP_MULTIPLY")
        return GLFW_KEY_KP_MULTIPLY;
    else if (s == "GLFW_KEY_KP_SUBTRACT")
        return GLFW_KEY_KP_SUBTRACT;
    else if (s == "GLFW_KEY_KP_ADD")
        return GLFW_KEY_KP_ADD;
    else if (s == "GLFW_KEY_KP_ENTER")
        return GLFW_KEY_KP_ENTER;
    else if (s == "GLFW_KEY_KP_EQUAL")
        return GLFW_KEY_KP_EQUAL;

    return GLFW_KEY_UNKNOWN;
}

uint8_t TeletypeKeyboard::stringToHIDCode(std::string s)
{
    // HID #defines from Atmel ASF usb_protocol_hid.h
    if (s == "HID_A")
        return 0x04;
    else if (s == "HID_B")
        return 0x05;
    else if (s == "HID_C")
        return 0x06;
    else if (s == "HID_D")
        return 0x07;
    else if (s == "HID_E")
        return 0x08;
    else if (s == "HID_F")
        return 0x09;
    else if (s == "HID_G")
        return 0x0A;
    else if (s == "HID_H")
        return 0x0B;
    else if (s == "HID_I")
        return 0x0C;
    else if (s == "HID_J")
        return 0x0D;
    else if (s == "HID_K")
        return 0x0E;
    else if (s == "HID_L")
        return 0x0F;
    else if (s == "HID_M")
        return 0x10;
    else if (s == "HID_N")
        return 0x11;
    else if (s == "HID_O")
        return 0x12;
    else if (s == "HID_P")
        return 0x13;
    else if (s == "HID_Q")
        return 0x14;
    else if (s == "HID_R")
        return 0x15;
    else if (s == "HID_S")
        return 0x16;
    else if (s == "HID_T")
        return 0x17;
    else if (s == "HID_U")
        return 0x18;
    else if (s == "HID_V")
        return 0x19;
    else if (s == "HID_W")
        return 0x1A;
    else if (s == "HID_X")
        return 0x1B;
    else if (s == "HID_Y")
        return 0x1C;
    else if (s == "HID_Z")
        return 0x1D;
    else if (s == "HID_1")
        return 30;
    else if (s == "HID_2")
        return 31;
    else if (s == "HID_3")
        return 32;
    else if (s == "HID_4")
        return 33;
    else if (s == "HID_5")
        return 34;
    else if (s == "HID_6")
        return 35;
    else if (s == "HID_7")
        return 36;
    else if (s == "HID_8")
        return 37;
    else if (s == "HID_9")
        return 38;
    else if (s == "HID_0")
        return 39;
    else if (s == "HID_ENTER")
        return 40;
    else if (s == "HID_ESCAPE")
        return 41;
    else if (s == "HID_BACKSPACE")
        return 42;
    else if (s == "HID_TAB")
        return 43;
    else if (s == "HID_SPACEBAR")
        return 44;
    else if (s == "HID_UNDERSCORE")
        return 45;
    else if (s == "HID_PLUS")
        return 46;
    else if (s == "HID_OPEN_BRACKET")
        return 47;
    else if (s == "HID_CLOSE_BRACKET")
        return 48;
    else if (s == "HID_BACKSLASH")
        return 49;
    else if (s == "HID_ASH")
        return 50;
    else if (s == "HID_COLON")
        return 51;
    else if (s == "HID_QUOTE")
        return 52;
    else if (s == "HID_TILDE")
        return 53;
    else if (s == "HID_COMMA")
        return 54;
    else if (s == "HID_DOT")
        return 55;
    else if (s == "HID_SLASH")
        return 56;
    else if (s == "HID_CAPS_LOCK")
        return 57;
    else if (s == "HID_F1")
        return 58;
    else if (s == "HID_F2")
        return 59;
    else if (s == "HID_F3")
        return 60;
    else if (s == "HID_F4")
        return 61;
    else if (s == "HID_F5")
        return 62;
    else if (s == "HID_F6")
        return 63;
    else if (s == "HID_F7")
        return 64;
    else if (s == "HID_F8")
        return 65;
    else if (s == "HID_F9")
        return 66;
    else if (s == "HID_F10")
        return 67;
    else if (s == "HID_F11")
        return 68;
    else if (s == "HID_F12")
        return 69;
    else if (s == "HID_PRINTSCREEN")
        return 70;
    else if (s == "HID_SCROLL_LOCK")
        return 71;
    else if (s == "HID_PAUSE")
        return 72;
    else if (s == "HID_INSERT")
        return 73;
    else if (s == "HID_HOME")
        return 74;
    else if (s == "HID_PAGEUP")
        return 75;
    else if (s == "HID_DELETE")
        return 76;
    else if (s == "HID_END")
        return 77;
    else if (s == "HID_PAGEDOWN")
        return 78;
    else if (s == "HID_RIGHT")
        return 79;
    else if (s == "HID_LEFT")
        return 80;
    else if (s == "HID_DOWN")
        return 81;
    else if (s == "HID_UP")
        return 82;
    else if (s == "HID_KEYPAD_NUM_LOCK")
        return 83;
    else if (s == "HID_KEYPAD_DIVIDE")
        return 84;
    else if (s == "HID_KEYPAD_AT")
        return 85;
    else if (s == "HID_KEYPAD_MULTIPLY")
        return 85;
    else if (s == "HID_KEYPAD_MINUS")
        return 86;
    else if (s == "HID_KEYPAD_PLUS")
        return 87;
    else if (s == "HID_KEYPAD_ENTER")
        return 88;
    else if (s == "HID_KEYPAD_1")
        return 89;
    else if (s == "HID_KEYPAD_2")
        return 90;
    else if (s == "HID_KEYPAD_3")
        return 91;
    else if (s == "HID_KEYPAD_4")
        return 92;
    else if (s == "HID_KEYPAD_5")
        return 93;
    else if (s == "HID_KEYPAD_6")
        return 94;
    else if (s == "HID_KEYPAD_7")
        return 95;
    else if (s == "HID_KEYPAD_8")
        return 96;
    else if (s == "HID_KEYPAD_9")
        return 97;
    else if (s == "HID_KEYPAD_0")
        return 98;
    else if (s == "HID_KEYPAD_DECIMAL") // not in usb_protocol_hid.h or used in TT code, but previously supported
        return 99;

    return 0;
}
