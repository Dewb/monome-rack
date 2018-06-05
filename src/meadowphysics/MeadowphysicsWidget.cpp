#include "MeadowphysicsModule.hpp"
#include "MeadowphysicsWidget.hpp"
#include "MonomeWidgets.hpp"

using namespace rack;

MeadowphysicsWidget::MeadowphysicsWidget(MeadowphysicsModule* module)
: MonomeModuleBaseWidget(module)
{
    box.size = Vec(15 * 6, 380);

    {
        auto panel = new SVGPanel();
        panel->setBackground(SVG::load(assetPlugin(plugin, "res/meadowphysics.svg")));
        panel->box.size = box.size;
        addChild(panel);
    }

    addChild(Widget::create<USBAJack>(Vec(10, 338)));

    addParam(ParamWidget::create<TL1105>(Vec(62, 336), module, MeadowphysicsModule::BUTTON_PARAM, 0.0, 1.0, 0.0));
    addParam(ParamWidget::create<MonomeKnob>(Vec(12, 232), module, MeadowphysicsModule::CLOCK_PARAM, 0.0, 1.0, 0.5));

    addChild(ModuleLightWidget::create<MediumLight<YellowLight>>(Vec(2, 72), module, MeadowphysicsModule::TRIG1_LIGHT));
    addChild(ModuleLightWidget::create<MediumLight<YellowLight>>(Vec(77, 72), module, MeadowphysicsModule::TRIG2_LIGHT));
    addChild(ModuleLightWidget::create<MediumLight<YellowLight>>(Vec(2, 110), module, MeadowphysicsModule::TRIG3_LIGHT));
    addChild(ModuleLightWidget::create<MediumLight<YellowLight>>(Vec(77, 110), module, MeadowphysicsModule::TRIG4_LIGHT));
    addChild(ModuleLightWidget::create<MediumLight<YellowLight>>(Vec(2, 148), module, MeadowphysicsModule::TRIG5_LIGHT));
    addChild(ModuleLightWidget::create<MediumLight<YellowLight>>(Vec(77, 148), module, MeadowphysicsModule::TRIG6_LIGHT));
    addChild(ModuleLightWidget::create<MediumLight<YellowLight>>(Vec(2, 186), module, MeadowphysicsModule::TRIG7_LIGHT));
    addChild(ModuleLightWidget::create<MediumLight<YellowLight>>(Vec(77, 186), module, MeadowphysicsModule::TRIG8_LIGHT));
    addChild(ModuleLightWidget::create<MediumLight<YellowLight>>(Vec(77, 282), module, MeadowphysicsModule::CLOCK_LIGHT));

    addOutput(Port::create<PJ301MPort>(Vec(13, 54), Port::OUTPUT, module, MeadowphysicsModule::TRIG1_OUTPUT));
    addOutput(Port::create<PJ301MPort>(Vec(50, 75), Port::OUTPUT, module, MeadowphysicsModule::TRIG2_OUTPUT));
    addOutput(Port::create<PJ301MPort>(Vec(13, 92), Port::OUTPUT, module, MeadowphysicsModule::TRIG3_OUTPUT));
    addOutput(Port::create<PJ301MPort>(Vec(50, 111), Port::OUTPUT, module, MeadowphysicsModule::TRIG4_OUTPUT));
    addOutput(Port::create<PJ301MPort>(Vec(13, 130), Port::OUTPUT, module, MeadowphysicsModule::TRIG5_OUTPUT));
    addOutput(Port::create<PJ301MPort>(Vec(50, 149), Port::OUTPUT, module, MeadowphysicsModule::TRIG6_OUTPUT));
    addOutput(Port::create<PJ301MPort>(Vec(13, 168), Port::OUTPUT, module, MeadowphysicsModule::TRIG7_OUTPUT));
    addOutput(Port::create<PJ301MPort>(Vec(50, 187), Port::OUTPUT, module, MeadowphysicsModule::TRIG8_OUTPUT));
    addInput(Port::create<PJ301MPort>(Vec(13, 286), Port::INPUT, module, MeadowphysicsModule::CLOCK_INPUT));
    addOutput(Port::create<PJ301MPort>(Vec(50, 286), Port::OUTPUT, module, MeadowphysicsModule::CLOCK_OUTPUT));
}

void MeadowphysicsWidget::randomize()
{
}
