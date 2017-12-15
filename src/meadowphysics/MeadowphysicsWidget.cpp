#include "MeadowphysicsModule.hpp"
#include "MeadowphysicsWidget.hpp"
#include "MonomeWidgets.hpp"

using namespace rack;

MeadowphysicsWidget::MeadowphysicsWidget()
{
    MeadowphysicsModule* module = new MeadowphysicsModule();
    setModule(module);
    box.size = Vec(15 * 6, 380);

    {
        auto panel = new SVGPanel();
        panel->setBackground(SVG::load(assetPlugin(plugin, "res/meadowphysics.svg")));
        panel->box.size = box.size;
        addChild(panel);
    }

    addChild(createScrew<USBAJack>(Vec(10, 338)));

    addParam(createParam<TL1105>(Vec(62, 336), module, MeadowphysicsModule::BUTTON_PARAM, 0.0, 1.0, 0.0));
    addParam(createParam<MonomeKnob>(Vec(12, 230), module, MeadowphysicsModule::CLOCK_PARAM, 0.0, 1.0, 0.5));

    addChild(createLight<MediumLight<YellowLight>>(Vec(2, 72), module, MeadowphysicsModule::TRIG1_LIGHT));
    addChild(createLight<MediumLight<YellowLight>>(Vec(77, 72), module, MeadowphysicsModule::TRIG2_LIGHT));
    addChild(createLight<MediumLight<YellowLight>>(Vec(2, 110), module, MeadowphysicsModule::TRIG3_LIGHT));
    addChild(createLight<MediumLight<YellowLight>>(Vec(77, 110), module, MeadowphysicsModule::TRIG4_LIGHT));
    addChild(createLight<MediumLight<YellowLight>>(Vec(2, 148), module, MeadowphysicsModule::TRIG5_LIGHT));
    addChild(createLight<MediumLight<YellowLight>>(Vec(77, 148), module, MeadowphysicsModule::TRIG6_LIGHT));
    addChild(createLight<MediumLight<YellowLight>>(Vec(2, 186), module, MeadowphysicsModule::TRIG7_LIGHT));
    addChild(createLight<MediumLight<YellowLight>>(Vec(77, 186), module, MeadowphysicsModule::TRIG8_LIGHT));
    addChild(createLight<MediumLight<YellowLight>>(Vec(77, 282), module, MeadowphysicsModule::CLOCK_LIGHT));

    addOutput(createOutput<PJ301MPort>(Vec(13, 54), module, MeadowphysicsModule::TRIG1_OUTPUT));
    addOutput(createOutput<PJ301MPort>(Vec(50, 75), module, MeadowphysicsModule::TRIG2_OUTPUT));
    addOutput(createOutput<PJ301MPort>(Vec(13, 92), module, MeadowphysicsModule::TRIG3_OUTPUT));
    addOutput(createOutput<PJ301MPort>(Vec(50, 111), module, MeadowphysicsModule::TRIG4_OUTPUT));
    addOutput(createOutput<PJ301MPort>(Vec(13, 130), module, MeadowphysicsModule::TRIG5_OUTPUT));
    addOutput(createOutput<PJ301MPort>(Vec(50, 149), module, MeadowphysicsModule::TRIG6_OUTPUT));
    addOutput(createOutput<PJ301MPort>(Vec(13, 168), module, MeadowphysicsModule::TRIG7_OUTPUT));
    addOutput(createOutput<PJ301MPort>(Vec(50, 187), module, MeadowphysicsModule::TRIG8_OUTPUT));
    addInput(createInput<PJ301MPort>(Vec(13, 286), module, MeadowphysicsModule::CLOCK_INPUT));
    addOutput(createOutput<PJ301MPort>(Vec(50, 286), module, MeadowphysicsModule::CLOCK_OUTPUT));
}

void MeadowphysicsWidget::randomize()
{
}
