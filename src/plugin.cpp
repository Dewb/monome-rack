#include "AnsibleModule.hpp"
#include "AnsibleWidget.hpp"
#include "EarthseaModule.hpp"
#include "EarthseaWidget.hpp"
#include "FaderbankModule.hpp"
#include "FaderbankWidget.hpp"
#include "MeadowphysicsModule.hpp"
#include "MeadowphysicsWidget.hpp"
#include "SerialOscInterface.hpp"
#include "TeletypeModule.hpp"
#include "TeletypeWidget.hpp"
#include "VirtualGridModule.hpp"
#include "VirtualGridWidget.hpp"
#include "WhiteWhaleModule.hpp"
#include "WhiteWhaleWidget.hpp"
#include "TeletypeKeyboard.hpp"

using namespace rack;

Plugin* pluginInstance;
Model* modelFaderbank;

void init(Plugin* p)
{
    pluginInstance = p;

    Model* modelWhiteWhale = createModel<WhiteWhaleModule, WhiteWhaleWidget>("whitewhale");
    Model* modelMeadowphysics = createModel<MeadowphysicsModule, MeadowphysicsWidget>("meadowphysics");
    Model* modelEarthsea = createModel<EarthseaModule, EarthseaWidget>("earthsea");

    Model* modelTeletype = createModel<TeletypeModule, TeletypeWidget>("teletype");
    Model* modelAnsible = createModel<AnsibleModule, AnsibleWidget>("ansible");

    Model* modelGrid128 = createModel<VirtualGridModuleTemplate<16, 8>, VirtualGridWidgetTemplate<16, 8>>("grid128");
    Model* modelGrid64 = createModel<VirtualGridModuleTemplate<8, 8>, VirtualGridWidgetTemplate<8, 8>>("grid64");
    Model* modelGrid256 = createModel<VirtualGridModuleTemplate<16, 16>, VirtualGridWidgetTemplate<16, 16>>("grid256");

    modelFaderbank = createModel<FaderbankModule, FaderbankWidget>("faderbank");

    p->addModel(modelWhiteWhale);
    p->addModel(modelMeadowphysics);
    p->addModel(modelEarthsea);
    
    p->addModel(modelTeletype);
    p->addModel(modelAnsible);

    p->addModel(modelGrid128);
    p->addModel(modelGrid64);
    p->addModel(modelGrid256);

    p->addModel(modelFaderbank);

    initThemes();
}

json_t* settingsToJson()
{
    json_t* rootJ = json_object();
    json_object_set_new(rootJ, "keyboardLayout", json_string(TeletypeKeyboard::getCurrentLayout().c_str()));
    return rootJ;
}

void settingsFromJson(json_t* rootJ)
{
    json_t* themeJ = json_object_get(rootJ, "keyboardLayout");
    if (themeJ)
        TeletypeKeyboard::setCurrentLayout(json_string_value(themeJ));
}