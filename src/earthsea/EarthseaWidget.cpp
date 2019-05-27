#include "EarthseaWidget.hpp"
#include "EarthseaModule.hpp"
#include "MonomeWidgets.hpp"

using namespace rack;

EarthseaWidget::EarthseaWidget(EarthseaModule* module)
    : MonomeModuleBaseWidget(module)
{
    box.size = Vec(15 * 6, 380);

    {
        auto panel = new SVGPanel();
        panel->setBackground(APP->window->loadSvg(rack::asset::plugin(pluginInstance, "res/earthsea.svg")));
        panel->box.size = box.size;
        addChild(panel);
    }

    addChild(createWidget<USBAJack>(Vec(10, 338)));

    addParam(createParam<TL1105>(Vec(62, 336), module, EarthseaModule::BUTTON_PARAM));
    addParam(createParam<MonomeKnob>(Vec(14, 32), module, EarthseaModule::CV1_PARAM));
    addParam(createParam<MonomeKnob>(Vec(14, 118), module, EarthseaModule::CV2_PARAM));
    addParam(createParam<MonomeKnob>(Vec(14, 204), module, EarthseaModule::CV3_PARAM));

    addChild(createLight<MediumLight<WhiteLight>>(Vec(77, 78), module, EarthseaModule::CV1_LIGHT));
    addChild(createLight<MediumLight<WhiteLight>>(Vec(77, 162), module, EarthseaModule::CV2_LIGHT));
    addChild(createLight<MediumLight<WhiteLight>>(Vec(77, 244), module, EarthseaModule::CV3_LIGHT));
    addChild(createLight<MediumLight<WhiteLight>>(Vec(77, 282), module, EarthseaModule::POS_LIGHT));
    addChild(createLight<MediumLight<YellowLight>>(Vec(2, 286), module, EarthseaModule::EDGE_LIGHT));

    addOutput(createOutput<PJ301MPort>(Vec(50, 82), module, EarthseaModule::CV1_OUTPUT));
    addOutput(createOutput<PJ301MPort>(Vec(50, 166), module, EarthseaModule::CV2_OUTPUT));
    addOutput(createOutput<PJ301MPort>(Vec(50, 248), module, EarthseaModule::CV3_OUTPUT));
    addOutput(createOutput<PJ301MPort>(Vec(50, 286), module, EarthseaModule::POS_OUTPUT));
    addOutput(createOutput<PJ301MPort>(Vec(13, 268), module, EarthseaModule::EDGE_OUTPUT));
}
