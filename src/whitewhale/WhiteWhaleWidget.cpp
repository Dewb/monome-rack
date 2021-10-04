#include "WhiteWhaleWidget.hpp"
#include "CommonWidgets.hpp"
#include "SifamTPM.hpp"
#include "WhiteWhaleModule.hpp"

using namespace rack;

WhiteWhaleWidget::WhiteWhaleWidget(WhiteWhaleModule* module)
{
    setModule(module);

    box.size = Vec(15 * 6, 380);

    {
        auto panel = new rack::SvgPanel();
        panel->setBackground(APP->window->loadSvg(rack::asset::plugin(pluginInstance, "res/whitewhale.svg")));
        panel->box.size = box.size;
        addChild(panel);
    }

    addChild(createWidget<USBAJack>(Vec(10, 338)));

    addParam(createParam<TL1105>(Vec(62, 336), module, WhiteWhaleModule::BUTTON_PARAM));
    addParam(createParam<SifamTPN111GrayBlackStripe>(Vec(12, 30), module, WhiteWhaleModule::PARAM_PARAM));
    addParam(createParam<SifamTPN111GrayBlackStripe>(Vec(12, 232), module, WhiteWhaleModule::CLOCK_PARAM));

    addOutput(createOutput<PJ301MPort>(Vec(50, 82), module, WhiteWhaleModule::TR1_OUTPUT));
    addOutput(createOutput<PJ301MPort>(Vec(50, 120), module, WhiteWhaleModule::TR2_OUTPUT));
    addOutput(createOutput<PJ301MPort>(Vec(50, 158), module, WhiteWhaleModule::TR3_OUTPUT));
    addOutput(createOutput<PJ301MPort>(Vec(50, 196), module, WhiteWhaleModule::TR4_OUTPUT));
    addOutput(createOutput<PJ301MPort>(Vec(13, 100), module, WhiteWhaleModule::CVA_OUTPUT));
    addOutput(createOutput<PJ301MPort>(Vec(13, 138), module, WhiteWhaleModule::CVB_OUTPUT));
    addInput(createInput<PJ301MPort>(Vec(13, 286), module, WhiteWhaleModule::CLOCK_INPUT));
    addOutput(createOutput<PJ301MPort>(Vec(50, 286), module, WhiteWhaleModule::CLOCK_OUTPUT));

    addChild(createLight<MediumLight<YellowLight>>(Vec(77, 80), module, WhiteWhaleModule::TR1_LIGHT));
    addChild(createLight<MediumLight<YellowLight>>(Vec(77, 118), module, WhiteWhaleModule::TR2_LIGHT));
    addChild(createLight<MediumLight<YellowLight>>(Vec(77, 156), module, WhiteWhaleModule::TR3_LIGHT));
    addChild(createLight<MediumLight<YellowLight>>(Vec(77, 194), module, WhiteWhaleModule::TR4_LIGHT));
    addChild(createLight<MediumLight<YellowLight>>(Vec(77, 282), module, WhiteWhaleModule::CLOCK_LIGHT));
    addChild(createLight<MediumLight<WhiteLight>>(Vec(2, 118), module, WhiteWhaleModule::CVA_LIGHT));
    addChild(createLight<MediumLight<WhiteLight>>(Vec(2, 156), module, WhiteWhaleModule::CVB_LIGHT));
}
