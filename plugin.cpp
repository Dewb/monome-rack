#include "whitewhale.hpp"
#include "grid.hpp"

Plugin *plugin;

void init(rack::Plugin *p)
{
    plugin = p;
    p->slug = "monome";
#ifdef VERSION
    p->version = TOSTRING(VERSION);
#endif
    p->website = "https://github.com/monome/whitewhale";

    p->addModel(createModel<WhiteWhaleWidget>("monome", "whitewhale", "white whale", SEQUENCER_TAG, CLOCK_TAG, EXTERNAL_TAG));
    //p->addModel(createModel<MonomeGridWidgetTemplate< 8,  8>>("monome", "grid64", "virtual grid 64", CONTROLLER_TAG));
    p->addModel(createModel<MonomeGridWidgetTemplate<16, 8>>("monome", "grid128", "virtual grid 128", CONTROLLER_TAG));
    //p->addModel(createModel<MonomeGridWidgetTemplate<16, 16>>("monome", "grid256", "virtual grid 256", CONTROLLER_TAG));
}