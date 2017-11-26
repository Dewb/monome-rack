#include "whitewhale.hpp"
#include "grid.hpp"

Plugin *plugin;

void init(rack::Plugin *p)
{
    plugin = p;
    p->slug = "Monome";
#ifdef VERSION
    p->version = TOSTRING(VERSION);
#endif
    p->website = "https://github.com/monome/whitewhale";

    p->addModel(createModel<WhiteWhaleWidget>("Monome", "WW", "White Whale", SEQUENCER_TAG));
    p->addModel(createModel<Grid128Widget>("Monome", "Grid128", "Grid 128", SEQUENCER_TAG));
}