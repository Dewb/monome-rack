#include "EarthseaModule.hpp"
#include "EarthseaWidget.hpp"
#include "MeadowphysicsModule.hpp"
#include "MeadowphysicsWidget.hpp"
#include "VirtualGridModule.hpp"
#include "VirtualGridWidget.hpp"
#include "WhiteWhaleModule.hpp"
#include "WhiteWhaleWidget.hpp"

using namespace rack;

Plugin* pluginInstance;

void init(Plugin* p)
{
    pluginInstance = p;

    p->website = "https://github.com/Dewb/monome-rack";

    Model* modelWhiteWhale = createModel<WhiteWhaleModule, WhiteWhaleWidget>("whitewhale");
    Model* modelMeadowphysics = createModel<MeadowphysicsModule, MeadowphysicsWidget>("meadowphysics");
    Model* modelEarthsea = createModel<EarthseaModule, EarthseaWidget>("earthsea");

    Model* modelGrid128 = createModel<VirtualGridModuleTemplate<16, 8, 5>, VirtualGridWidgetTemplate<16, 8, 5>>("grid128");
    Model* modelGrid64 = createModel<VirtualGridModuleTemplate<8, 8, 5>, VirtualGridWidgetTemplate<8, 8, 5>>("grid64");
    Model* modelGrid128Series = createModel<VirtualGridModuleTemplate<16, 8, 2>, VirtualGridWidgetTemplate<16, 8, 2>>("grid128series");
    Model* modelGrid64Series = createModel<VirtualGridModuleTemplate<8, 8, 0>, VirtualGridWidgetTemplate<8, 8, 0>>("grid64series");

    p->addModel(modelWhiteWhale);
    p->addModel(modelMeadowphysics);
    p->addModel(modelEarthsea);

    p->addModel(modelGrid128);
    p->addModel(modelGrid64);
    p->addModel(modelGrid128Series);
    p->addModel(modelGrid64Series);

    //p->addModel(createModel<TeletypeWidget>("monome", "teletype", "teletype", SEQUENCER_TAG, FUNCTION_GENERATOR_TAG, UTILITY_TAG, RANDOM_TAG, EXTERNAL_TAG));
}