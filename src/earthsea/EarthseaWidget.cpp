#include "EarthseaModule.hpp"
#include "EarthseaWidget.hpp"
#include "MonomeWidgets.hpp"

using namespace rack;

EarthseaWidget::EarthseaWidget()
{
    EarthseaModule* module = new EarthseaModule();
    setModule(module);
    box.size = Vec(15 * 6, 380);

    {
        auto panel = new SVGPanel();
        panel->setBackground(SVG::load(assetPlugin(plugin, "res/earthsea.svg")));
        panel->box.size = box.size;
        addChild(panel);
    }

    addChild(createScrew<USBAJack>(Vec(10, 338)));

    addParam(createParam<TL1105>(Vec(62, 336), module, EarthseaModule::BUTTON_PARAM, 0.0, 1.0, 0.0));
    addParam(createParam<MonomeKnob>(Vec(12, 30), module, EarthseaModule::CV1_PARAM, 0.0, 1.0, 0.5));
    addParam(createParam<MonomeKnob>(Vec(12, 116), module, EarthseaModule::CV2_PARAM, 0.0, 1.0, 0.5));
    addParam(createParam<MonomeKnob>(Vec(12, 202), module, EarthseaModule::CV3_PARAM, 0.0, 1.0, 0.5));

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

void EarthseaWidget::randomize()
{
}
