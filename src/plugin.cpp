#include "grid.hpp"
//#include "teletype.hpp"
#include "earthsea.hpp"
#include "meadowphysics.hpp"
#include "whitewhale.hpp"

Plugin* plugin;

void init(rack::Plugin* p)
{
    plugin = p;
    p->slug = "monome";
#ifdef VERSION
    p->version = TOSTRING(VERSION);
#endif
    p->website = "https://github.com/monome/whitewhale";

    p->addModel(createModel<WhiteWhaleWidget>("monome", "whitewhale", "white whale", SEQUENCER_TAG, CLOCK_TAG, EXTERNAL_TAG));
    p->addModel(createModel<MeadowphysicsWidget>("monome", "meadowphysics", "meadowphysics", SEQUENCER_TAG, CLOCK_TAG, EXTERNAL_TAG));
    p->addModel(createModel<EarthseaWidget>("monome", "earthsea", "earthsea", SEQUENCER_TAG, EXTERNAL_TAG));

    p->addModel(createModel<MonomeGridWidgetTemplate<16, 8, 5>>("monome", "grid128", "virtual grid 128", CONTROLLER_TAG));
    p->addModel(createModel<MonomeGridWidgetTemplate<8, 8, 5>>("monome", "grid64", "virtual grid 64", CONTROLLER_TAG));
    p->addModel(createModel<MonomeGridWidgetTemplate<16, 8, 2>>("monome", "grid128series", "virtual grid 128 mono", CONTROLLER_TAG));
    p->addModel(createModel<MonomeGridWidgetTemplate<8, 8, 1>>("monome", "grid64series", "virtual grid 64 mono", CONTROLLER_TAG));

    //p->addModel(createModel<TeletypeWidget>("monome", "teletype", "teletype", SEQUENCER_TAG, FUNCTION_GENERATOR_TAG, UTILITY_TAG, RANDOM_TAG, EXTERNAL_TAG));
}