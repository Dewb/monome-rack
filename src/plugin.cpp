#include "EarthseaWidget.hpp"
#include "MeadowphysicsWidget.hpp"
#include "VirtualGridWidget.hpp"
#include "WhiteWhaleWidget.hpp"

using namespace rack;

Plugin* plugin;

void init(Plugin* p)
{
    plugin = p;
    p->slug = "monome";
#ifdef VERSION
    p->version = TOSTRING(VERSION);
#endif
    p->website = "https://github.com/Dewb/monome-rack";

    p->addModel(createModel<WhiteWhaleWidget>("monome", "whitewhale", "white whale", SEQUENCER_TAG, CLOCK_TAG, EXTERNAL_TAG));
    p->addModel(createModel<MeadowphysicsWidget>("monome", "meadowphysics", "meadowphysics", SEQUENCER_TAG, CLOCK_TAG, EXTERNAL_TAG));
    p->addModel(createModel<EarthseaWidget>("monome", "earthsea", "earthsea", SEQUENCER_TAG, EXTERNAL_TAG));

    p->addModel(createModel<VirtualGridWidgetTemplate<16, 8, 5>>("monome", "grid128", "virtual grid 128", CONTROLLER_TAG));
    p->addModel(createModel<VirtualGridWidgetTemplate<8, 8, 5>>("monome", "grid64", "virtual grid 64", CONTROLLER_TAG));
    p->addModel(createModel<VirtualGridWidgetTemplate<16, 8, 2>>("monome", "grid128series", "virtual grid 128 mono", CONTROLLER_TAG));
    p->addModel(createModel<VirtualGridWidgetTemplate<8, 8, 0>>("monome", "grid64series", "virtual grid 64 mono", CONTROLLER_TAG));

    //p->addModel(createModel<TeletypeWidget>("monome", "teletype", "teletype", SEQUENCER_TAG, FUNCTION_GENERATOR_TAG, UTILITY_TAG, RANDOM_TAG, EXTERNAL_TAG));
}