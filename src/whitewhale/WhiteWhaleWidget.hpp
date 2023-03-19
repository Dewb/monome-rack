#pragma once

#include "LibAVR32ModuleWidget.hpp"
#include "SifamTPM.hpp"
#include "USBAJack.hpp"
#include "WhiteWhaleModule.hpp"

using namespace rack;

struct WhiteWhaleWidget : LibAVR32ModuleWidget
{
    WhiteWhaleWidget(WhiteWhaleModule* module)
    {
        setModule(module);

        box.size = Vec(15 * 6, 380);

        {
            auto panel = new rack::SvgPanel();
            panel->setBackground(APP->window->loadSvg(rack::asset::plugin(pluginInstance, "res/whitewhale.svg")));
            panel->box.size = box.size;
            addChild(panel);
        }

        // Screws positioned for sliding nuts :)
        addChild(createWidget<ScrewSilver>(Vec(RACK_GRID_WIDTH / 2, 0)));
        addChild(createWidget<ScrewSilver>(Vec(RACK_GRID_WIDTH / 2, RACK_GRID_HEIGHT - RACK_GRID_WIDTH)));

        addParam(createParam<USBAJack>(Vec(7, 333), module, WhiteWhaleModule::USB_PARAM));
        addParam(createParam<TL1105>(Vec(62, 336), module, WhiteWhaleModule::BUTTON_PARAM));
        addParam(createParam<SifamTPN111GrayBlackStripe>(Vec(12, 30), module, WhiteWhaleModule::PARAM_PARAM));
        addParam(createParam<SifamTPN111GrayBlackStripe>(Vec(12, 232), module, WhiteWhaleModule::CLOCK_PARAM));

        addOutput(createOutput<PJ301MPort>(Vec(50, 83), module, WhiteWhaleModule::TR1_OUTPUT));
        addOutput(createOutput<PJ301MPort>(Vec(50, 121), module, WhiteWhaleModule::TR2_OUTPUT));
        addOutput(createOutput<PJ301MPort>(Vec(50, 159), module, WhiteWhaleModule::TR3_OUTPUT));
        addOutput(createOutput<PJ301MPort>(Vec(50, 197), module, WhiteWhaleModule::TR4_OUTPUT));
        addOutput(createOutput<PJ301MPort>(Vec(15, 101), module, WhiteWhaleModule::CVA_OUTPUT));
        addOutput(createOutput<PJ301MPort>(Vec(15, 139), module, WhiteWhaleModule::CVB_OUTPUT));
        addInput(createInput<PJ301MPort>(Vec(13, 286), module, WhiteWhaleModule::CLOCK_INPUT));
        addOutput(createOutput<PJ301MPort>(Vec(50, 286), module, WhiteWhaleModule::CLOCK_OUTPUT));

        addChild(createLight<MediumLight<YellowLight>>(Vec(77, 79), module, WhiteWhaleModule::TR1_LIGHT));
        addChild(createLight<MediumLight<YellowLight>>(Vec(77, 117), module, WhiteWhaleModule::TR2_LIGHT));
        addChild(createLight<MediumLight<YellowLight>>(Vec(77, 155), module, WhiteWhaleModule::TR3_LIGHT));
        addChild(createLight<MediumLight<YellowLight>>(Vec(77, 193), module, WhiteWhaleModule::TR4_LIGHT));
        addChild(createLight<MediumLight<YellowLight>>(Vec(77, 282), module, WhiteWhaleModule::CLOCK_LIGHT));
        addChild(createLight<MediumLight<WhiteLight>>(Vec(3, 117), module, WhiteWhaleModule::CVA_LIGHT));
        addChild(createLight<MediumLight<WhiteLight>>(Vec(3, 155), module, WhiteWhaleModule::CVB_LIGHT));
    }
};
