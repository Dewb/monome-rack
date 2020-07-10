#include "rack.hpp"

using namespace rack;

struct TeletypeScreen : OpaqueWidget
{
    uint8_t* buffer;
    int pixel_x;
    int pixel_y;

    TeletypeScreen(uint8_t* buffer, int x, int y);

    void onMouseDown(EventMouseDown& e) override;
    void onFocus(EventFocus& e) override;
    void onKey(EventKey& e) override;
    void draw(NVGcontext* vg) override;

    void drawPixel(NVGcontext* vg, float x, float y, float width, float height, int data);
};