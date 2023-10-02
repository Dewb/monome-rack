#include "TeletypeScreenWidget.hpp"
#include "TeletypeModule.hpp"
#include "TeletypeKeyboard.hpp"
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
    if (module)
    {
        TeletypeKeyboard::init();
    }
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

    if (TeletypeKeyboard::process(e, &key, &mod))
    {
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
    NVGcolor hiColor = !settings::preferDarkPanels ? nvgRGB(250, 250, 250) : nvgRGB(96, 96, 94);
    NVGcolor loColor = !settings::preferDarkPanels ? nvgRGB(140, 140, 130) : nvgRGB(20, 20, 5);

    // draw skeumorphic shadow around screen
    float t = 0.95;
    float r = 2.75;
    nvgBeginPath(vg);
    nvgRoundedRect(vg, box.size.x - t, -t, 2 * t, box.size.y + t, r);
    nvgFillColor(vg, hiColor);
    nvgFill(vg);

    nvgBeginPath(vg);
    nvgRoundedRect(vg, -t, -t, box.size.x + 2 * t, 2 * t, r);
    nvgRoundedRect(vg, -t, -t, 2 * t, box.size.y + t, r);
    nvgFillColor(vg, loColor);
    nvgFill(vg);

    nvgBeginPath(vg);
    nvgRoundedRect(vg, -t, box.size.y - t, box.size.x + 2 * t, 2 * t, r);
    nvgFillColor(vg, hiColor);
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
