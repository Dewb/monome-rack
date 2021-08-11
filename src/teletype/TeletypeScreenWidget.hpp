#include "rack.hpp"

using namespace rack;

struct TeletypeScreenWidget : OpaqueWidget
{
    uint8_t* buffer;
    int pixel_x;
    int pixel_y;

    TeletypeScreenWidget(uint8_t* buffer, int x, int y);

    void onSelect(const event::Select& e) override;
    void onDeselect(const event::Deselect& e) override;
    void onSelectKey(const event::SelectKey& e) override;
    void draw(NVGcontext* vg) override;

    void drawPixel(NVGcontext* vg, float x, float y, float width, float height, int data);
};