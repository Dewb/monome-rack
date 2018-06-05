#include "EarthseaModule.hpp"
#include "EarthseaWidget.hpp"
#include "MeadowphysicsModule.hpp"
#include "MeadowphysicsWidget.hpp"
#include "VirtualGridModule.hpp"
#include "VirtualGridWidget.hpp"
#include "WhiteWhaleModule.hpp"
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

    Model* modelWhiteWhale = Model::create<WhiteWhaleModule, WhiteWhaleWidget>("monome", "whitewhale", "white whale", SEQUENCER_TAG, CLOCK_TAG, EXTERNAL_TAG);
    Model* modelMeadowphysics = Model::create<MeadowphysicsModule, MeadowphysicsWidget>("monome", "meadowphysics", "meadowphysics", SEQUENCER_TAG, CLOCK_TAG, EXTERNAL_TAG);
    Model* modelEarthsea = Model::create<EarthseaModule, EarthseaWidget>("monome", "earthsea", "earthsea", SEQUENCER_TAG, EXTERNAL_TAG);

    Model* modelGrid128 = Model::create<VirtualGridModuleTemplate<16, 8, 5>, VirtualGridWidgetTemplate<16, 8, 5>>("monome", "grid128", "virtual grid 128", CONTROLLER_TAG);
    Model* modelGrid64 = Model::create<VirtualGridModuleTemplate<8, 8, 5>, VirtualGridWidgetTemplate<8, 8, 5>>("monome", "grid64", "virtual grid 64", CONTROLLER_TAG);
    Model* modelGrid128Series = Model::create<VirtualGridModuleTemplate<16, 8, 2>, VirtualGridWidgetTemplate<16, 8, 2>>("monome", "grid128series", "virtual grid 128 mono", CONTROLLER_TAG);
    Model* modelGrid64Series = Model::create<VirtualGridModuleTemplate<8, 8, 0>, VirtualGridWidgetTemplate<8, 8, 0>>("monome", "grid64series", "virtual grid 64 mono", CONTROLLER_TAG);

    p->addModel(modelWhiteWhale);
    p->addModel(modelMeadowphysics);
    p->addModel(modelEarthsea);

    p->addModel(modelGrid128);
    p->addModel(modelGrid64);
    p->addModel(modelGrid128Series);
    p->addModel(modelGrid64Series);

    //p->addModel(createModel<TeletypeWidget>("monome", "teletype", "teletype", SEQUENCER_TAG, FUNCTION_GENERATOR_TAG, UTILITY_TAG, RANDOM_TAG, EXTERNAL_TAG));
}