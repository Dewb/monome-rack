#include "TeletypeScreenWidget.hpp"
#include "TeletypeModule.hpp"

TeletypeScreenWidget::TeletypeScreenWidget(uint8_t* buffer, int x, int y)
    : buffer(buffer)
    , pixel_x(x)
    , pixel_y(y)
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

    // Use Rack's keyName field for internationalization of printable chars on main keyboard; leave other codes alone
    if (e.keyName.length() == 1 && e.keyName[0] >= 'a' && e.keyName[0] <= 'z') // A-Z
    {
        key = (e.keyName[0] - 'a') + 0x4;
    }
    else if (e.keyName.length() == 1 && 
                e.keyName[0] >= '1' && e.keyName[0] <= '9' && 
                !(e.key >= GLFW_KEY_KP_1 && e.key <= GLFW_KEY_KP_9))
    {
        key = (e.keyName[0] - '1') + 0x1e;
    }
    else if (e.keyName == "0" && e.key != GLFW_KEY_KP_0) 
    {
        key = 0x27;
    }
    else if (e.keyName == "." && e.key != GLFW_KEY_KP_DECIMAL) // GLFW_KEY_PERIOD
    {
        key = 0x37;
    }
    else if (e.keyName == "/" && e.key != GLFW_KEY_KP_DIVIDE) // GLFW_KEY_SLASH
    {
        key = 0x38;
    }
    else if (e.keyName == "[") // GLFW_KEY_LEFT_BRACKET
    {
        key = 0x2F;
    }
    else if (e.keyName == "]") // GLFW_KEY_RIGHT_BRACKET
    {
        key = 0x30;
    }
    else if (e.keyName == "-" && e.key != GLFW_KEY_KP_SUBTRACT) // GLFW_KEY_MINUS
    {
        key = 0x2d;
    }
    else if (e.keyName == "=") // GLFW_KEY_EQUAL
    {
        key = 0x2e;
    }
    else if (e.keyName == ";") // GLFW_KEY_SEMICOLON
    {
        key = 0x33;
    }
    else if (e.keyName == "'") // GLFW_KEY_APOSTROPHE
    {
        key = 0x34;
    }
    else if (e.keyName == "\\") // GLFW_KEY_BACKSLASH
    {
        key = 0x31;
    }
    else if (e.keyName == "`") // GLFW_KEY_GRAVE_ACCENT:
    {
        key = 0x35;
    }
    else if (e.keyName == ",") // GLFW_KEY_COMMA
    {
        key = 0x36;
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
            case GLFW_KEY_KP_0:
                key = 0x62;
                break;
            case GLFW_KEY_TAB:
                key = 0x2b;
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

    auto mw = static_cast<ModuleWidget*>(parent);
    if (mw)
    {
        auto tt = static_cast<TeletypeModule*>(mw->module);
        if (tt)
        {
            if (e.action == GLFW_PRESS)
            {
                tt->firmware.hidMessage(key, mod, false, false);
            }
            else if (e.action == GLFW_REPEAT)
            {
                tt->firmware.hidMessage(key, mod, true, false);
            }
            else if (e.action == GLFW_RELEASE)
            {
                tt->firmware.hidMessage(key, mod, false, true);
            }
        }
    }

    e.consume(this);
}

void TeletypeScreenWidget::draw(const DrawArgs& args)
{
    drawLayer(args, 0);
}

void TeletypeScreenWidget::drawLayer(const DrawArgs& args, int layer)
{
    auto vg = args.vg;
    
    int margin = 5;

    float pixel_width = (box.size.x - 2 * margin) / (pixel_x * 1.0);
    float pixel_height = (box.size.y - 2 * margin) / (pixel_y * 1.0);

    if (layer == 0)
    {
        if (this == APP->event->selectedWidget)
        {
            // draw keyboard focus highlight rectangle
            nvgBeginPath(vg);
            nvgRoundedRect(vg, -2, -2, box.size.x + 4, box.size.y + 4, 2.5);
            nvgStrokeColor(vg, nvgRGB(190, 180, 0));
            nvgStrokeWidth(vg, 3.5);
            nvgStroke(vg);
            nvgFillColor(vg, nvgRGB(190, 180, 0));
            nvgFill(vg);
        } else {
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
        }

        // the screen itself
        nvgBeginPath(vg);
        nvgRoundedRect(vg, 0, 0, box.size.x, box.size.y, 2);
        nvgFillColor(vg, nvgRGB(0, 0, 0));
        nvgFill(vg);
    }
    else if (layer == 1)
    {
        // now draw the pixels
        if (buffer)
        {
            uint8_t* ptr = buffer;
            for (int j = 0; j < pixel_y; j++)
            {
                for (int i = 0; i < pixel_x; i++)
                {
                    float x = margin + i * pixel_width;
                    float y = margin + j * pixel_height;

                    drawPixel(vg, x, y, pixel_width, pixel_height, *ptr++);
                }
            }
        }
    }
}

void TeletypeScreenWidget::drawPixel(NVGcontext* vg, float x, float y, float width, float height, int data)
{
    nvgBeginPath(vg);
    nvgRect(vg, x, y, width * 0.96, height * 0.96);
    nvgFillColor(vg, nvgRGB(data ? data * 11 + 79 : 0, data ? data * 11 + 79 : 0, data * 11));
    nvgFill(vg);
}
