#include "EarthseaModule.hpp"
#include "EarthseaWidget.hpp"
#include "MeadowphysicsModule.hpp"
#include "MeadowphysicsWidget.hpp"
#include "SerialOscInterface.hpp"
#include "VirtualGridModule.hpp"
#include "VirtualGridWidget.hpp"
#include "WhiteWhaleModule.hpp"
#include "WhiteWhaleWidget.hpp"
#include "Teletype.hpp"

using namespace rack;

Plugin* pluginInstance;

void init(Plugin* p)
{
    pluginInstance = p;

    Model* modelWhiteWhale = createModel<WhiteWhaleModule, WhiteWhaleWidget>("whitewhale");
    Model* modelMeadowphysics = createModel<MeadowphysicsModule, MeadowphysicsWidget>("meadowphysics");
    Model* modelEarthsea = createModel<EarthseaModule, EarthseaWidget>("earthsea");
    Model* modelTeletype = createModel<TeletypeModule, TeletypeWidget>("teletype");

    Model* modelGrid128 = createModel<VirtualGridModuleTemplate<16, 8, 5>, VirtualGridWidgetTemplate<16, 8, 5>>("grid128");
    Model* modelGrid64 = createModel<VirtualGridModuleTemplate<8, 8, 5>, VirtualGridWidgetTemplate<8, 8, 5>>("grid64");

    p->addModel(modelWhiteWhale);
    p->addModel(modelMeadowphysics);
    p->addModel(modelEarthsea);

    p->addModel(modelGrid128);
    p->addModel(modelGrid64);

    // initialize SerialOsc
    SerialOscInterface::get()->driver->getDeviceCount();
}