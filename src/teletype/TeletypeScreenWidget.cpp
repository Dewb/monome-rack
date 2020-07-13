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

    // GLFW keycodes are "inspired by" but not equal to HID keycodes
    if (e.action == GLFW_PRESS || e.action == GLFW_REPEAT)
    {
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
        else if (e.key >= GLFW_KEY_1 && e.key <= GLFW_KEY_9)
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
            }
        }
    }

    uint8_t msg[8] = { mod, 0, key, 0, 0, 0, 0, 0 };

    auto mw = static_cast<ModuleWidget*>(parent);
    if (mw)
    {
        auto tt = static_cast<TeletypeModule*>(mw->module);
        if (tt)
        {
            tt->firmware.hidMessage(msg, 8);
        }
    }

    e.consume(this);
}

void TeletypeScreenWidget::draw(NVGcontext* vg)
{
    int margin = 4;

    float pixel_width = (box.size.x - 2 * margin) / (pixel_x * 1.0);
    float pixel_height = (box.size.y - 2 * margin) / (pixel_y * 1.0);

    if (this == APP->event->selectedWidget)
    {
        nvgBeginPath(vg);
        nvgRoundedRect(vg, -3, -3, box.size.x + 6, box.size.y + 6, 2);
        nvgStrokeColor(vg, nvgRGB(190, 180, 0));
        nvgStrokeWidth(vg, 3);
        nvgStroke(vg);
    }

    nvgBeginPath(vg);
    nvgRect(vg, 0, 0, box.size.x, box.size.y);
    nvgFillColor(vg, nvgRGB(0, 0, 0));
    nvgFill(vg);

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

void TeletypeScreenWidget::drawPixel(NVGcontext* vg, float x, float y, float width, float height, int data)
{
    nvgBeginPath(vg);
    nvgRect(vg, x, y, width * 0.96, height * 0.96);
    nvgFillColor(vg, nvgRGB(data ? data * 13 + 48 : 0, data ? data * 13 + 48 : 0, 0));
    nvgFill(vg);
}
