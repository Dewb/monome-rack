#include "TeletypeWidget.hpp"
#include "MonomeWidgets.hpp"
#include "TeletypeModule.hpp"
#include "TeletypeScreenWidget.hpp"

TeletypeWidget::TeletypeWidget(TeletypeModule* module)
{
    setModule(module);

    box.size = Vec(15 * 18, 380);

    {
        auto panel = new SvgPanel();
        panel->setBackground(APP->window->loadSvg(rack::asset::plugin(pluginInstance, "res/teletype.svg")));
        panel->box.size = box.size;
        addChild(panel);
    }
    /*
    addChild(createScrew<ScrewSilver>(Vec(15, 0)));
    addChild(createScrew<ScrewSilver>(Vec(15, 365)));
    addChild(createScrew<ScrewSilver>(Vec(239, 0)));
    addChild(createScrew<ScrewSilver>(Vec(239, 365)));
*/
    addChild(createWidget<USBAJack>(Vec(10, 337)));
    addParam(createParam<TL1105>(Vec(62, 337), module, TeletypeModule::BUTTON_PARAM));

    /*
    addChild(createScrew<ScrewSilver>(Vec(11, 312)));
    addChild(createScrew<ScrewSilver>(Vec(244, 312)));
*/

    uint8_t* ptr = nullptr;
    uint16_t width = 0, height = 0;
    if (module)
    {
        module->firmware.getScreenBuffer(&ptr, &width, &height);
    }

    auto screen = new TeletypeScreenWidget(ptr, width, height);
    screen->box.pos = Vec(31, 202);
    screen->box.size = Vec(208, 108);
    addChild(screen);

    addParam(createParam<MonomeKnob>(Vec(213, 46), module, TeletypeModule::PARAM_PARAM));

    addChild(createLight<MediumLight<YellowLight>>(Vec(118, 112), module, TeletypeModule::TRIGA_LIGHT));
    addChild(createLight<MediumLight<YellowLight>>(Vec(158, 112), module, TeletypeModule::TRIGB_LIGHT));
    addChild(createLight<MediumLight<YellowLight>>(Vec(198, 112), module, TeletypeModule::TRIGC_LIGHT));
    addChild(createLight<MediumLight<YellowLight>>(Vec(238, 112), module, TeletypeModule::TRIGD_LIGHT));
    addChild(createLight<MediumLight<WhiteLight>>(Vec(138, 152), module, TeletypeModule::CV1_LIGHT));
    addChild(createLight<MediumLight<WhiteLight>>(Vec(178, 152), module, TeletypeModule::CV2_LIGHT));
    addChild(createLight<MediumLight<WhiteLight>>(Vec(218, 152), module, TeletypeModule::CV3_LIGHT));
    addChild(createLight<MediumLight<WhiteLight>>(Vec(258, 152), module, TeletypeModule::CV4_LIGHT));

    addInput(createInput<PJ301MPort>(Vec(10, 36), module, TeletypeModule::TRIG1_INPUT));
    addInput(createInput<PJ301MPort>(Vec(50, 36), module, TeletypeModule::TRIG2_INPUT));
    addInput(createInput<PJ301MPort>(Vec(90, 36), module, TeletypeModule::TRIG3_INPUT));
    addInput(createInput<PJ301MPort>(Vec(130, 36), module, TeletypeModule::TRIG4_INPUT));
    addInput(createInput<PJ301MPort>(Vec(30, 76), module, TeletypeModule::TRIG5_INPUT));
    addInput(createInput<PJ301MPort>(Vec(70, 76), module, TeletypeModule::TRIG6_INPUT));
    addInput(createInput<PJ301MPort>(Vec(110, 76), module, TeletypeModule::TRIG7_INPUT));
    addInput(createInput<PJ301MPort>(Vec(150, 76), module, TeletypeModule::TRIG8_INPUT));

    addInput(createInput<PJ301MPort>(Vec(170, 36), module, TeletypeModule::CV_INPUT));

    addOutput(createOutput<PJ301MPort>(Vec(90, 116), module, TeletypeModule::TRIGA_OUTPUT));
    addOutput(createOutput<PJ301MPort>(Vec(130, 116), module, TeletypeModule::TRIGB_OUTPUT));
    addOutput(createOutput<PJ301MPort>(Vec(170, 116), module, TeletypeModule::TRIGC_OUTPUT));
    addOutput(createOutput<PJ301MPort>(Vec(210, 116), module, TeletypeModule::TRIGD_OUTPUT));
    addOutput(createOutput<PJ301MPort>(Vec(110, 156), module, TeletypeModule::CV1_OUTPUT));
    addOutput(createOutput<PJ301MPort>(Vec(150, 156), module, TeletypeModule::CV2_OUTPUT));
    addOutput(createOutput<PJ301MPort>(Vec(190, 156), module, TeletypeModule::CV3_OUTPUT));
    addOutput(createOutput<PJ301MPort>(Vec(230, 156), module, TeletypeModule::CV4_OUTPUT));
}
