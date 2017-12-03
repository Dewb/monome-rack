#include "rack.hpp"

using namespace rack;

struct WhiteLight : ModuleLightWidget
{
    WhiteLight();
};

struct USBAJack : TransparentWidget
{
    void draw(NVGcontext* vg) override;
};