#include "rack.hpp"

using namespace rack;

extern Plugin* plugin;

struct WhiteLight : ModuleLightWidget
{
    WhiteLight();
};

struct USBAJack : TransparentWidget
{
    void draw(NVGcontext* vg) override;
};

struct MonomeKnob : RoundKnob
{
    MonomeKnob();
};