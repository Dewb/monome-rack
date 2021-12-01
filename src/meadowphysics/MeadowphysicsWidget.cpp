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

    // Screws positioned for sliding nuts :)
    addChild(createWidget<ScrewSilver>(Vec(RACK_GRID_WIDTH / 2, 0)));
    addChild(createWidget<ScrewSilver>(Vec(RACK_GRID_WIDTH / 2, RACK_GRID_HEIGHT - RACK_GRID_WIDTH)));
    addChild(createWidget<USBAJack>(Vec(10, 338)));

    addParam(createParam<TL1105>(Vec(62, 336), module, MeadowphysicsModule::BUTTON_PARAM));
    addParam(createParam<SifamTPN111GrayBlackStripe>(Vec(12, 232), module, MeadowphysicsModule::CLOCK_PARAM));

    addOutput(createOutput<PJ301MPort>(Vec(13, 54), module, MeadowphysicsModule::TR1_OUTPUT));
    addOutput(createOutput<PJ301MPort>(Vec(50, 75), module, MeadowphysicsModule::TR2_OUTPUT));
    addOutput(createOutput<PJ301MPort>(Vec(13, 92), module, MeadowphysicsModule::TR3_OUTPUT));
    addOutput(createOutput<PJ301MPort>(Vec(50, 113), module, MeadowphysicsModule::TR4_OUTPUT));
    addOutput(createOutput<PJ301MPort>(Vec(13, 130), module, MeadowphysicsModule::TR5_OUTPUT));
    addOutput(createOutput<PJ301MPort>(Vec(50, 151), module, MeadowphysicsModule::TR6_OUTPUT));
    addOutput(createOutput<PJ301MPort>(Vec(13, 168), module, MeadowphysicsModule::TR7_OUTPUT));
    addOutput(createOutput<PJ301MPort>(Vec(50, 189), module, MeadowphysicsModule::TR8_OUTPUT));
    addInput(createInput<PJ301MPort>(Vec(13, 286), module, MeadowphysicsModule::CLOCK_INPUT));
    addOutput(createOutput<PJ301MPort>(Vec(50, 286), module, MeadowphysicsModule::CLOCK_OUTPUT));

    addChild(createLight<MediumLight<YellowLight>>(Vec(2, 71), module, MeadowphysicsModule::TR1_LIGHT));
    addChild(createLight<MediumLight<YellowLight>>(Vec(77, 71), module, MeadowphysicsModule::TR2_LIGHT));
    addChild(createLight<MediumLight<YellowLight>>(Vec(2, 109), module, MeadowphysicsModule::TR3_LIGHT));
    addChild(createLight<MediumLight<YellowLight>>(Vec(77, 109), module, MeadowphysicsModule::TR4_LIGHT));
    addChild(createLight<MediumLight<YellowLight>>(Vec(2, 147), module, MeadowphysicsModule::TR5_LIGHT));
    addChild(createLight<MediumLight<YellowLight>>(Vec(77, 147), module, MeadowphysicsModule::TR6_LIGHT));
    addChild(createLight<MediumLight<YellowLight>>(Vec(2, 185), module, MeadowphysicsModule::TR7_LIGHT));
    addChild(createLight<MediumLight<YellowLight>>(Vec(77, 185), module, MeadowphysicsModule::TR8_LIGHT));
    addChild(createLight<MediumLight<YellowLight>>(Vec(77, 282), module, MeadowphysicsModule::CLOCK_LIGHT));
}
