#include "MeadowphysicsWidget.hpp"
#include "CommonWidgets.hpp"
#include "MeadowphysicsModule.hpp"
#include "SifamTPM.hpp"

using namespace rack;

MeadowphysicsWidget::MeadowphysicsWidget(MeadowphysicsModule* module)
{
    setModule(module);

    box.size = Vec(15 * 6, 380);

    {
        auto panel = new SvgPanel();
        panel->setBackground(APP->window->loadSvg(rack::asset::plugin(pluginInstance, "res/meadowphysics.svg")));
        panel->box.size = box.size;
        addChild(panel);
    }

    addChild(createWidget<USBAJack>(Vec(10, 338)));

    addParam(createParam<TL1105>(Vec(62, 336), module, MeadowphysicsModule::BUTTON_PARAM));
    addParam(createParam<SifamTPN111GrayBlackStripe>(Vec(12, 232), module, MeadowphysicsModule::CLOCK_PARAM));

    addOutput(createOutput<PJ301MPort>(Vec(13, 54), module, MeadowphysicsModule::TR1_OUTPUT));
    addOutput(createOutput<PJ301MPort>(Vec(50, 75), module, MeadowphysicsModule::TR2_OUTPUT));
    addOutput(createOutput<PJ301MPort>(Vec(13, 92), module, MeadowphysicsModule::TR3_OUTPUT));
    addOutput(createOutput<PJ301MPort>(Vec(50, 111), module, MeadowphysicsModule::TR4_OUTPUT));
    addOutput(createOutput<PJ301MPort>(Vec(13, 130), module, MeadowphysicsModule::TR5_OUTPUT));
    addOutput(createOutput<PJ301MPort>(Vec(50, 149), module, MeadowphysicsModule::TR6_OUTPUT));
    addOutput(createOutput<PJ301MPort>(Vec(13, 168), module, MeadowphysicsModule::TR7_OUTPUT));
    addOutput(createOutput<PJ301MPort>(Vec(50, 187), module, MeadowphysicsModule::TR8_OUTPUT));
    addInput(createInput<PJ301MPort>(Vec(13, 286), module, MeadowphysicsModule::CLOCK_INPUT));
    addOutput(createOutput<PJ301MPort>(Vec(50, 286), module, MeadowphysicsModule::CLOCK_OUTPUT));

    addChild(createLight<MediumLight<YellowLight>>(Vec(2, 72), module, MeadowphysicsModule::TR1_LIGHT));
    addChild(createLight<MediumLight<YellowLight>>(Vec(77, 72), module, MeadowphysicsModule::TR2_LIGHT));
    addChild(createLight<MediumLight<YellowLight>>(Vec(2, 110), module, MeadowphysicsModule::TR3_LIGHT));
    addChild(createLight<MediumLight<YellowLight>>(Vec(77, 110), module, MeadowphysicsModule::TR4_LIGHT));
    addChild(createLight<MediumLight<YellowLight>>(Vec(2, 148), module, MeadowphysicsModule::TR5_LIGHT));
    addChild(createLight<MediumLight<YellowLight>>(Vec(77, 148), module, MeadowphysicsModule::TR6_LIGHT));
    addChild(createLight<MediumLight<YellowLight>>(Vec(2, 186), module, MeadowphysicsModule::TR7_LIGHT));
    addChild(createLight<MediumLight<YellowLight>>(Vec(77, 186), module, MeadowphysicsModule::TR8_LIGHT));
    addChild(createLight<MediumLight<YellowLight>>(Vec(77, 282), module, MeadowphysicsModule::CLOCK_LIGHT));
}
