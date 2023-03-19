#include "TeletypeWidget.hpp"
#include "SifamTPM.hpp"
#include "TeletypeModule.hpp"
#include "USBAJack.hpp"
#include "scene/TeletypeSceneIOMenu.hpp"
#include "screen/TeletypeScreenWidget.hpp"

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

    addChild(createWidget<ScrewSilver>(Vec(RACK_GRID_WIDTH, 0)));
    addChild(createWidget<ScrewSilver>(Vec(box.size.x - 2 * RACK_GRID_WIDTH, 0)));
    addChild(createWidget<ScrewSilver>(Vec(RACK_GRID_WIDTH, RACK_GRID_HEIGHT - RACK_GRID_WIDTH)));
    addChild(createWidget<ScrewSilver>(Vec(box.size.x - 2 * RACK_GRID_WIDTH, RACK_GRID_HEIGHT - RACK_GRID_WIDTH)));

    addParam(createParam<USBAJack>(Vec(7, 333), module, TeletypeModule::USB_PARAM));
    addParam(createParam<TL1105>(Vec(62, 337), module, TeletypeModule::BUTTON_PARAM));

    // addChild(createScrew<ScrewSilver>(Vec(11, 312)));
    // addChild(createScrew<ScrewSilver>(Vec(244, 312)));

    screen = new TeletypeScreenWidget(module);
    screen->box.pos = Vec(30, 200);
    screen->box.size = Vec(210, 112);
    addChild(screen);

    addParam(createParam<SifamTPN111GrayBlackStripe>(Vec(211, 47.5), module, TeletypeModule::PARAM_PARAM));

    addInput(createInput<PJ301MPort>(Vec(11, 38.5), module, TeletypeModule::TRIG1_INPUT));
    addInput(createInput<PJ301MPort>(Vec(50.5, 38.5), module, TeletypeModule::TRIG3_INPUT));
    addInput(createInput<PJ301MPort>(Vec(90, 38.5), module, TeletypeModule::TRIG5_INPUT));
    addInput(createInput<PJ301MPort>(Vec(130, 38.5), module, TeletypeModule::TRIG7_INPUT));
    addInput(createInput<PJ301MPort>(Vec(30, 77.5), module, TeletypeModule::TRIG2_INPUT));
    addInput(createInput<PJ301MPort>(Vec(69.5, 77.5), module, TeletypeModule::TRIG4_INPUT));
    addInput(createInput<PJ301MPort>(Vec(109, 77.5), module, TeletypeModule::TRIG6_INPUT));
    addInput(createInput<PJ301MPort>(Vec(148.5, 77.5), module, TeletypeModule::TRIG8_INPUT));

    addInput(createInput<PJ301MPort>(Vec(169, 38.5), module, TeletypeModule::IN_INPUT));

    addOutput(createOutput<PJ301MPort>(Vec(90, 117.5), module, TeletypeModule::TR1_OUTPUT));
    addOutput(createOutput<PJ301MPort>(Vec(129.5, 117.5), module, TeletypeModule::TR2_OUTPUT));
    addOutput(createOutput<PJ301MPort>(Vec(169, 117.5), module, TeletypeModule::TR3_OUTPUT));
    addOutput(createOutput<PJ301MPort>(Vec(208.5, 117.5), module, TeletypeModule::TR4_OUTPUT));
    addOutput(createOutput<PJ301MPort>(Vec(109, 157.5), module, TeletypeModule::CV1_OUTPUT));
    addOutput(createOutput<PJ301MPort>(Vec(148.5, 157.5), module, TeletypeModule::CV2_OUTPUT));
    addOutput(createOutput<PJ301MPort>(Vec(188, 157.5), module, TeletypeModule::CV3_OUTPUT));
    addOutput(createOutput<PJ301MPort>(Vec(227.5, 157.5), module, TeletypeModule::CV4_OUTPUT));

    addChild(createLight<MediumLight<YellowLight>>(Vec(117, 112), module, TeletypeModule::TR1_LIGHT));
    addChild(createLight<MediumLight<YellowLight>>(Vec(156.5, 112), module, TeletypeModule::TR2_LIGHT));
    addChild(createLight<MediumLight<YellowLight>>(Vec(196, 112), module, TeletypeModule::TR3_LIGHT));
    addChild(createLight<MediumLight<YellowLight>>(Vec(235.5, 112), module, TeletypeModule::TR4_LIGHT));
    addChild(createLight<MediumLight<WhiteLight>>(Vec(136, 152), module, TeletypeModule::CV1_LIGHT));
    addChild(createLight<MediumLight<WhiteLight>>(Vec(175.5, 152), module, TeletypeModule::CV2_LIGHT));
    addChild(createLight<MediumLight<WhiteLight>>(Vec(215, 152), module, TeletypeModule::CV3_LIGHT));
    addChild(createLight<MediumLight<WhiteLight>>(Vec(254.5, 152), module, TeletypeModule::CV4_LIGHT));
}

struct TeletypeKeystrokeItem : rack::ui::MenuItem
{
    TeletypeModule* module;
    rack::widget::Widget* screen;
    uint8_t key;
    uint8_t mod;

    TeletypeKeystrokeItem(TeletypeModule* module, rack::widget::Widget* screen, uint8_t key, uint8_t mod, std::string _text, std::string _rightText = "")
        : module(module)
        , screen(screen)
        , key(key)
        , mod(mod)
    {
        text = _text;
        rightText = _rightText;
    }

    void onAction(const rack::event::Action& e) override
    {
        if (module)
        {
            module->firmware.hidMessage(key, mod, false, false);
            module->firmware.hidMessage(key, mod, false, true);

            if (screen) {
                APP->event->setSelectedWidget(screen);
            }
        }
    }
};

void TeletypeWidget::appendContextMenu(rack::Menu* menu)
{
    LibAVR32ModuleWidget::appendContextMenu(menu);

    TeletypeModule* m = dynamic_cast<TeletypeModule*>(module);
    assert(m);

    menu->addChild(new MenuSeparator());

    menu->addChild(createIndexPtrSubmenuItem("Theme", { "Red", "Orange", "Yellow", "White" }, &m->theme));

    menu->addChild(new MenuSeparator());

    menu->addChild(new InternalPresetSubmenu(m, "Import scenes", Load));
    menu->addChild(new InternalPresetSubmenu(m, "Export scenes", Save));

    menu->addChild(new MenuSeparator());

    menu->addChild(construct<MenuLabel>(&MenuLabel::text, "Shortcuts"));

    menu->addChild(new TeletypeKeystrokeItem(m, screen, 0x45, 0, "LIVE mode", "F12"));
    menu->addChild(new TeletypeKeystrokeItem(m, screen, 0x3a, 4, "EDIT mode", "Alt+F1"));
    menu->addChild(new TeletypeKeystrokeItem(m, screen, 0x44, 0, "TRACKER mode", "F11"));
    menu->addChild(new TeletypeKeystrokeItem(m, screen, 0x2b, 0, "Cycle LIVE/EDIT/TRACKER", "Tab"));
    menu->addChild(new TeletypeKeystrokeItem(m, screen, 0x29, 0, "SCENE READ mode", "Esc"));
    menu->addChild(new TeletypeKeystrokeItem(m, screen, 0x29, 4, "SCENE WRITE mode", "Alt+Esc"));
    //menu->addChild(new TeletypeKeystrokeItem(m, screen, 0x0a, 4, "GRID visualizer mode", "Alt+G"));
    //menu->addChild(new TeletypeKeystrokeItem(m, screen, 0x35, 0, "Toggle system variables display", "~"));
    menu->addChild(new TeletypeKeystrokeItem(m, screen, 0x2f, 0, "Previous script/page/value/scene", "["));
    menu->addChild(new TeletypeKeystrokeItem(m, screen, 0x30, 0, "Next script/page/value/scene", "]"));
    menu->addChild(new TeletypeKeystrokeItem(m, screen, 0x0b, 4, "HELP mode", "Alt+H"));
}