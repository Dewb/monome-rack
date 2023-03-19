#include "TeletypeScreenWidget.hpp"
#include "TeletypeModule.hpp"
#include "ExampleScreen.hpp"

//#define SAVE_SCREEN_FILENAME "/tmp/ttscreen.txt"
#ifdef SAVE_SCREEN_FILENAME
#include <fstream>
#include <iomanip>
#include <sstream>
#endif

TeletypeScreenWidget::TeletypeScreenWidget(LibAVR32Module* module)
    : module(module)
{
}

void TeletypeScreenWidget::onSelect(const event::Select& e)
{
}

void TeletypeScreenWidget::onDeselect(const event::Deselect& e)
{
}

void TeletypeScreenWidget::onSelectKey(const event::SelectKey& e)
{
    uint8_t key = 0;
    uint8_t mod = 0;

    // GLFW keycodes are "inspired by" but not equal to HID keycodes ><
    if (e.mods & GLFW_MOD_CONTROL)
    {
        mod |= 0x1;
    }
    if (e.mods & GLFW_MOD_SHIFT)
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

    if (e.key >= GLFW_KEY_A && e.key <= GLFW_KEY_Z) // A-Z
    {
        key = (e.key - GLFW_KEY_A) + 0x4;
    }
    else if (e.key >= GLFW_KEY_1 && e.key <= GLFW_KEY_9) // 0 is mapped separately
    {
        key = (e.key - GLFW_KEY_1) + 0x1e;
    }
    else if (e.key >= GLFW_KEY_RIGHT && e.key <= GLFW_KEY_UP)
    {
        key = (e.key - GLFW_KEY_RIGHT) + 0x4f;
    }
    else if (e.key >= GLFW_KEY_F1 && e.key <= GLFW_KEY_F12)
    {
        key = (e.key - GLFW_KEY_F1) + 0x3a;
    }
    else if (e.key >= GLFW_KEY_KP_1 && e.key <= GLFW_KEY_KP_9) // KP_0 is mapped separately
    {
        key = (e.key - GLFW_KEY_KP_1) + 0x59;
    }
    else
    {
        switch (e.key)
        {
            case GLFW_KEY_SPACE:
                key = 0x2c;
                break;
            case GLFW_KEY_ENTER:
                key = 0x28;
                break;
            case GLFW_KEY_BACKSPACE:
                key = 0x2a;
                break;
            case GLFW_KEY_PERIOD:
                key = 0x37;
                break;
            case GLFW_KEY_SLASH:
                key = 0x38;
                break;
            case GLFW_KEY_0:
                key = 0x27;
                break;
            case GLFW_KEY_KP_0:
                key = 0x62;
                break;
            case GLFW_KEY_LEFT_BRACKET:
                key = 0x2f;
                break;
            case GLFW_KEY_RIGHT_BRACKET:
                key = 0x30;
                break;
            case GLFW_KEY_TAB:
                key = 0x2b;
                break;
            case GLFW_KEY_MINUS:
                key = 0x2d;
                break;
            case GLFW_KEY_EQUAL:
                key = 0x2e;
                break;
            case GLFW_KEY_SEMICOLON:
                key = 0x33;
                break;
            case GLFW_KEY_APOSTROPHE:
                key = 0x34;
                break;
            case GLFW_KEY_BACKSLASH:
                key = 0x31;
                break;
            case GLFW_KEY_GRAVE_ACCENT:
                key = 0x35;
                break;
            case GLFW_KEY_COMMA:
                key = 0x36;
                break;
            case GLFW_KEY_ESCAPE:
                key = 0x29;
                break;
            case GLFW_KEY_NUM_LOCK:
                key = 0x53;
                break;
            case GLFW_KEY_CAPS_LOCK:
                key = 0x39;
                break;
            case GLFW_KEY_PRINT_SCREEN:
                key = 0x46;
                break;
            case GLFW_KEY_SCROLL_LOCK:
                key = 0x47;
                break;
            case GLFW_KEY_PAGE_UP:
                key = 0x4b;
                break;
            case GLFW_KEY_PAGE_DOWN:
                key = 0x4e;
                break;
            case GLFW_KEY_HOME:
                key = 0x4a;
                break;
            case GLFW_KEY_END:
                key = 0x4d;
                break;
            case GLFW_KEY_KP_DIVIDE:
                key = 0x54;
                break;
            case GLFW_KEY_KP_MULTIPLY:
                key = 0x55;
                break;
            case GLFW_KEY_KP_SUBTRACT:
                key = 0x56;
                break;
            case GLFW_KEY_KP_ADD:
                key = 0x57;
                break;
            case GLFW_KEY_KP_ENTER:
                key = 0x58;
                break;
            case GLFW_KEY_KP_DECIMAL:
                key = 0x63;
                break;
        }
    }

    if (module)
    {
        if (e.action == GLFW_PRESS)
        {
            module->firmware.hidMessage(key, mod, false, false);
        }
        else if (e.action == GLFW_REPEAT)
        {
            module->firmware.hidMessage(key, mod, true, false);
        }
        else if (e.action == GLFW_RELEASE)
        {
            module->firmware.hidMessage(key, mod, false, true);
        }
    }

    e.consume(this);
}

void TeletypeScreenWidget::draw(const DrawArgs& args)
{
    drawFrame(args.vg);
}

void TeletypeScreenWidget::drawLayer(const DrawArgs& args, int layer)
{
    if (layer == 1)
    {
        if (this == APP->event->selectedWidget)
        {
            drawFocusRectangle(args.vg);
        }
        drawPixels(args.vg);
    }
}

void TeletypeScreenWidget::drawFrame(NVGcontext* vg)
{
    // draw skeumorphic shadow around screen
    float t = 0.95;
    float r = 2.75;
    nvgBeginPath(vg);
    nvgRoundedRect(vg, box.size.x - t, -t, 2 * t, box.size.y + t, r);
    nvgFillColor(vg, nvgRGB(250, 250, 240));
    nvgFill(vg);

    nvgBeginPath(vg);
    nvgRoundedRect(vg, -t, -t, box.size.x + 2 * t, 2 * t, r);
    nvgRoundedRect(vg, -t, -t, 2 * t, box.size.y + t, r);
    nvgFillColor(vg, nvgRGB(140, 140, 130));
    nvgFill(vg);

    nvgBeginPath(vg);
    nvgRoundedRect(vg, -t, box.size.y - t, box.size.x + 2 * t, 2 * t, r);
    nvgFillColor(vg, nvgRGB(250, 250, 240));
    nvgFill(vg);

    // draw the empty screen
    nvgBeginPath(vg);
    nvgRoundedRect(vg, 0, 0, box.size.x, box.size.y, 2);
    nvgFillColor(vg, nvgRGB(0, 0, 0));
    nvgFill(vg);
}

void TeletypeScreenWidget::drawFocusRectangle(NVGcontext* vg)
{
    // draw keyboard focus highlight rectangle
    NVGcolor color;
    levelToGradient(module->theme, 14, &color, nullptr);
    nvgBeginPath(vg);
    nvgRoundedRect(vg, -2, -2, box.size.x + 4, box.size.y + 4, 2.5);
    nvgStrokeColor(vg, color);
    nvgStrokeWidth(vg, 3.5);
    nvgStroke(vg);
    nvgFillColor(vg, color);
    nvgFill(vg);

    // redraw empty screen
    nvgBeginPath(vg);
    nvgRoundedRect(vg, 0, 0, box.size.x, box.size.y, 2);
    nvgFillColor(vg, nvgRGB(0, 0, 0));
    nvgFill(vg);
}

void TeletypeScreenWidget::drawPixels(NVGcontext* vg)
{
    uint8_t* buffer = module ? module->getScreenBuffer() : exampleScreen;
    GridTheme theme = module ? module->theme : GridTheme::Yellow;
    uint16_t pixel_x = 128;
    uint16_t pixel_y = 64;

    if (buffer == NULL || pixel_x == 0 || pixel_y == 0)
    {
       return;
    }

#ifdef SAVE_SCREEN_FILENAME
    std::ofstream ss(SAVE_SCREEN_FILENAME);
    ss << "unsigned char exampleScreen[128 * 64] = {\n" << std::hex;
    for (int i = 0; i < 128 * 64; i++)
    {
       ss << "0x" << static_cast<uint16_t>(buffer[i]) << ", ";
    }
    ss << "\n};\n";
#endif

    int margin = 5;
    float pixel_width = (box.size.x - 2 * margin) / (pixel_x * 1.0);
    float pixel_height = (box.size.y - 2 * margin) / (pixel_y * 1.0);

    for (int j = 0; j < pixel_y; j++)
    {
        for (int i = 0; i < pixel_x; i++)
        {
            float x = margin + i * pixel_width;
            float y = margin + j * pixel_height;

            uint8_t d = *buffer++;
            if (d > 0)
            {
                drawPixel(vg, theme, x, y, pixel_width, pixel_height, d);
            }
        }
    }
}

void TeletypeScreenWidget::drawPixel(NVGcontext* vg, GridTheme theme, float x, float y, float width, float height, int data)
{
    nvgBeginPath(vg);
    nvgRect(vg, x, y, width * 0.92, height * 0.92);
    NVGcolor color;
    levelToGradient(theme, data, &color, nullptr);
    nvgFillColor(vg, color);
    nvgFill(vg);
}
