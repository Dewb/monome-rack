#include "TeletypeWidget.hpp"
#include "CommonWidgets.hpp"
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
    
    // addChild(createScrew<ScrewSilver>(Vec(15, 0)));
    // addChild(createScrew<ScrewSilver>(Vec(15, 365)));
    // addChild(createScrew<ScrewSilver>(Vec(239, 0)));
    // addChild(createScrew<ScrewSilver>(Vec(239, 365)));

    addChild(createWidget<USBAJack>(Vec(10, 337)));
    addParam(createParam<TL1105>(Vec(62, 337), module, TeletypeModule::BUTTON_PARAM));

    // addChild(createScrew<ScrewSilver>(Vec(11, 312)));
    // addChild(createScrew<ScrewSilver>(Vec(244, 312)));

    auto screen = new TeletypeScreenWidget(module ? module->screenBuffer : nullptr, 128, 64);
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
    addInput(createInput<PJ301MPort>(Vec(50, 36), module, TeletypeModule::TRIG3_INPUT));
    addInput(createInput<PJ301MPort>(Vec(90, 36), module, TeletypeModule::TRIG5_INPUT));
    addInput(createInput<PJ301MPort>(Vec(130, 36), module, TeletypeModule::TRIG7_INPUT));
    addInput(createInput<PJ301MPort>(Vec(30, 76), module, TeletypeModule::TRIG2_INPUT));
    addInput(createInput<PJ301MPort>(Vec(70, 76), module, TeletypeModule::TRIG4_INPUT));
    addInput(createInput<PJ301MPort>(Vec(110, 76), module, TeletypeModule::TRIG6_INPUT));
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

struct TeletypeKeystrokeItem : rack::ui::MenuItem
{
    TeletypeModule* module;
    uint8_t key;
    uint8_t mod;

    TeletypeKeystrokeItem(TeletypeModule* module, uint8_t key, uint8_t mod, std::string _text, std::string _rightText = "")
    : module(module), key(key), mod(mod)
    {
        text = _text;
        rightText = _rightText;
    }

    void onAction(const rack::event::Action& e) override
    {
        module->firmware.hidMessage(key, mod, false, false);
        module->firmware.hidMessage(key, mod, false, true);
    }
};

void TeletypeWidget::appendContextMenu(rack::Menu* menu)
{
    LibAVR32ModuleWidget::appendContextMenu(menu);

    TeletypeModule* m = dynamic_cast<TeletypeModule*>(module);
    assert(m);

    menu->addChild(construct<MenuEntry>());
    menu->addChild(construct<MenuLabel>(&MenuLabel::text, "Shortcuts"));

    menu->addChild(new TeletypeKeystrokeItem(m, 0x45, 0, "LIVE mode", "F12"));
    menu->addChild(new TeletypeKeystrokeItem(m, 0x3a, 4, "EDIT mode", "Alt+F1"));
    menu->addChild(new TeletypeKeystrokeItem(m, 0x44, 0, "TRACKER mode", "F11"));
    menu->addChild(new TeletypeKeystrokeItem(m, 0x2b, 0, "Cycle LIVE/EDIT/TRACKER", "Tab"));
    menu->addChild(new TeletypeKeystrokeItem(m, 0x29, 0, "SCENE READ mode", "Esc"));
    menu->addChild(new TeletypeKeystrokeItem(m, 0x29, 4, "SCENE WRITE mode", "Alt+Esc"));
    //menu->addChild(new TeletypeKeystrokeItem(m, 0x0a, 4, "GRID visualizer mode", "Alt+G"));
    //menu->addChild(new TeletypeKeystrokeItem(m, 0x35, 0, "Toggle system variables display", "~"));
    menu->addChild(new TeletypeKeystrokeItem(m, 0x2f, 0, "Previous script/page/value/scene", "["));
    menu->addChild(new TeletypeKeystrokeItem(m, 0x30, 0, "Next script/page/value/scene", "]"));
    menu->addChild(new TeletypeKeystrokeItem(m, 0x0b, 4, "HELP mode", "Alt+H"));
}