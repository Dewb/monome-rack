#include "TTExpanderWidget.hpp"
#include "CommonWidgets.hpp"
#include "TTExpanderModule.hpp"

using namespace rack;

extern rack::Plugin* pluginInstance;

TTExpanderWidget::TTExpanderWidget(TTExpanderModule* module)
{
    setModule(module);

    box.size = Vec(15 * 6, 380);

    {
        auto panel = new SvgPanel();
        panel->setBackground(APP->window->loadSvg(rack::asset::plugin(pluginInstance, "res/teletype-expander.svg")));
        panel->box.size = box.size;
        addChild(panel);
    }

    // addChild(createWidget<USBAJack>(Vec(10, 338)));

    // addParam(createParam<TL1105>(Vec(62, 336), module, TTExpanderModule::MODE_PARAM));
    addParam(createParam<TL1105>(Vec(17, 256), module, TTExpanderModule::KEY1_PARAM));
    addParam(createParam<TL1105>(Vec(54, 256), module, TTExpanderModule::KEY2_PARAM));

    addChild(createLight<MediumLight<YellowLight>>(Vec(2, 72), module, TTExpanderModule::TR1_LIGHT));
    addChild(createLight<MediumLight<WhiteLight>>(Vec(77, 72), module, TTExpanderModule::CV1_LIGHT));
    addChild(createLight<MediumLight<YellowLight>>(Vec(2, 110), module, TTExpanderModule::TR2_LIGHT));
    addChild(createLight<MediumLight<WhiteLight>>(Vec(77, 110), module, TTExpanderModule::CV2_LIGHT));
    addChild(createLight<MediumLight<YellowLight>>(Vec(2, 148), module, TTExpanderModule::TR3_LIGHT));
    addChild(createLight<MediumLight<WhiteLight>>(Vec(77, 148), module, TTExpanderModule::CV3_LIGHT));
    addChild(createLight<MediumLight<YellowLight>>(Vec(2, 186), module, TTExpanderModule::TR4_LIGHT));
    addChild(createLight<MediumLight<WhiteLight>>(Vec(77, 186), module, TTExpanderModule::CV4_LIGHT));
    // addChild(createLight<MediumLight<YellowWhiteLight>>(Vec(77, 326), module, TTExpanderModule::MODE_YELLOW_LIGHT));

    addOutput(createOutput<PJ301MPort>(Vec(13, 54), module, TTExpanderModule::TR1_OUTPUT));
    addOutput(createOutput<PJ301MPort>(Vec(50, 75), module, TTExpanderModule::CV1_OUTPUT));
    addOutput(createOutput<PJ301MPort>(Vec(13, 92), module, TTExpanderModule::TR2_OUTPUT));
    addOutput(createOutput<PJ301MPort>(Vec(50, 111), module, TTExpanderModule::CV2_OUTPUT));
    addOutput(createOutput<PJ301MPort>(Vec(13, 130), module, TTExpanderModule::TR3_OUTPUT));
    addOutput(createOutput<PJ301MPort>(Vec(50, 149), module, TTExpanderModule::CV3_OUTPUT));
    addOutput(createOutput<PJ301MPort>(Vec(13, 168), module, TTExpanderModule::TR4_OUTPUT));
    addOutput(createOutput<PJ301MPort>(Vec(50, 187), module, TTExpanderModule::CV4_OUTPUT));

    addInput(createInput<PJ301MPort>(Vec(13, 286), module, TTExpanderModule::IN1_INPUT));
    addInput(createInput<PJ301MPort>(Vec(50, 286), module, TTExpanderModule::IN2_INPUT));
}
