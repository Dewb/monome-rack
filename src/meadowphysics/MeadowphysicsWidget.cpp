#include "MeadowphysicsWidget.hpp"
#include "MeadowphysicsModule.hpp"
#include "MonomeWidgets.hpp"

using namespace rack;

MeadowphysicsWidget::MeadowphysicsWidget(MeadowphysicsModule* module)
    : MonomeModuleBaseWidget(module)
{
    box.size = Vec(15 * 6, 380);

    {
        auto panel = new SVGPanel();
        panel->setBackground(SVG::load(rack::asset::plugin(pluginInstance, "res/meadowphysics.svg")));
        panel->box.size = box.size;
        addChild(panel);
    }

    addChild(createWidget<USBAJack>(Vec(10, 338)));

    addParam(createParam<TL1105>(Vec(62, 336), module, MeadowphysicsModule::BUTTON_PARAM, 0.0, 1.0, 0.0));
    addParam(createParam<MonomeKnob>(Vec(12, 232), module, MeadowphysicsModule::CLOCK_PARAM, 0.0, 1.0, 0.5));

    addChild(createLight<MediumLight<YellowLight>>(Vec(2, 72), module, MeadowphysicsModule::TRIG1_LIGHT));
    addChild(createLight<MediumLight<YellowLight>>(Vec(77, 72), module, MeadowphysicsModule::TRIG2_LIGHT));
    addChild(createLight<MediumLight<YellowLight>>(Vec(2, 110), module, MeadowphysicsModule::TRIG3_LIGHT));
    addChild(createLight<MediumLight<YellowLight>>(Vec(77, 110), module, MeadowphysicsModule::TRIG4_LIGHT));
    addChild(createLight<MediumLight<YellowLight>>(Vec(2, 148), module, MeadowphysicsModule::TRIG5_LIGHT));
    addChild(createLight<MediumLight<YellowLight>>(Vec(77, 148), module, MeadowphysicsModule::TRIG6_LIGHT));
    addChild(createLight<MediumLight<YellowLight>>(Vec(2, 186), module, MeadowphysicsModule::TRIG7_LIGHT));
    addChild(createLight<MediumLight<YellowLight>>(Vec(77, 186), module, MeadowphysicsModule::TRIG8_LIGHT));
    addChild(createLight<MediumLight<YellowLight>>(Vec(77, 282), module, MeadowphysicsModule::CLOCK_LIGHT));

    addOutput(createPort<PJ301MPort>(Vec(13, 54), PortWidget::OUTPUT, module, MeadowphysicsModule::TRIG1_OUTPUT));
    addOutput(createPort<PJ301MPort>(Vec(50, 75), PortWidget::OUTPUT, module, MeadowphysicsModule::TRIG2_OUTPUT));
    addOutput(createPort<PJ301MPort>(Vec(13, 92), PortWidget::OUTPUT, module, MeadowphysicsModule::TRIG3_OUTPUT));
    addOutput(createPort<PJ301MPort>(Vec(50, 111), PortWidget::OUTPUT, module, MeadowphysicsModule::TRIG4_OUTPUT));
    addOutput(createPort<PJ301MPort>(Vec(13, 130), PortWidget::OUTPUT, module, MeadowphysicsModule::TRIG5_OUTPUT));
    addOutput(createPort<PJ301MPort>(Vec(50, 149), PortWidget::OUTPUT, module, MeadowphysicsModule::TRIG6_OUTPUT));
    addOutput(createPort<PJ301MPort>(Vec(13, 168), PortWidget::OUTPUT, module, MeadowphysicsModule::TRIG7_OUTPUT));
    addOutput(createPort<PJ301MPort>(Vec(50, 187), PortWidget::OUTPUT, module, MeadowphysicsModule::TRIG8_OUTPUT));
    addInput(createPort<PJ301MPort>(Vec(13, 286), PortWidget::INPUT, module, MeadowphysicsModule::CLOCK_INPUT));
    addOutput(createPort<PJ301MPort>(Vec(50, 286), PortWidget::OUTPUT, module, MeadowphysicsModule::CLOCK_OUTPUT));
}
