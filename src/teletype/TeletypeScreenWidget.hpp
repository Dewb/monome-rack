#include "rack.hpp"

using namespace rack;

struct TeletypeScreenWidget : OpaqueWidget
{
    uint8_t* buffer;
    int pixel_x;
    int pixel_y;

    TeletypeScreenWidget(uint8_t* buffer, int x, int y);

    virtual void onSelect(const event::Select& e) override;
    virtual void onDeselect(const event::Deselect& e) override;
    virtual void onSelectKey(const event::SelectKey& e) override;
    virtual void draw(NVGcontext* vg) override;

    void drawPixel(NVGcontext* vg, float x, float y, float width, float height, int data);
};