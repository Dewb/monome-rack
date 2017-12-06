#include "screen.hpp"


TeletypeScreen::TeletypeScreen(uint8_t* buffer, int x, int y)
    : buffer(buffer)
    , pixel_x(x)
    , pixel_y(y)
{
}

void TeletypeScreen::onMouseDown(EventMouseDown& e) 
{
    e.target = this;
    e.consumed = true;
}

void TeletypeScreen::onFocus(EventFocus& e) 
{
    e.consumed = true;
}

void TeletypeScreen::onKey(EventKey& e) 
{
    e.consumed = true;
    parent->onKey(e);
}

void TeletypeScreen::draw(NVGcontext* vg) 
{
    int margin = 4;

    float pixel_width = (box.size.x - 2 * margin) / (pixel_x * 1.0);
    float pixel_height = (box.size.y - 2 * margin) / (pixel_y * 1.0);

    if (gFocusedWidget == this)
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

void TeletypeScreen::drawPixel(NVGcontext* vg, float x, float y, float width, float height, int data)
{
    nvgBeginPath(vg);
    nvgRect(vg, x, y, width * 0.96, height * 0.96);
    nvgFillColor(vg, nvgRGB(data ? data * 13 + 48 : 0, data ? data * 13 + 48 : 0, 0));
    nvgFill(vg);
}
