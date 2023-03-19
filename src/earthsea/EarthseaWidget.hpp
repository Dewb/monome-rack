#pragma once

#include "EarthseaModule.hpp"
#include "LibAVR32ModuleWidget.hpp"
#include "SifamTPM.hpp"
#include "USBAJack.hpp"

using namespace rack;

struct EarthseaWidget : LibAVR32ModuleWidget
{
    EarthseaWidget(EarthseaModule* module)
    {
        setModule(module);

        box.size = Vec(15 * 6, 380);

        {
            auto panel = new SvgPanel();
            panel->setBackground(APP->window->loadSvg(rack::asset::plugin(pluginInstance, "res/earthsea.svg")));
            panel->box.size = box.size;
            addChild(panel);
        }

        // Screws positioned for sliding nuts :)
        addChild(createWidget<ScrewSilver>(Vec(RACK_GRID_WIDTH / 2, 0)));
        addChild(createWidget<ScrewSilver>(Vec(RACK_GRID_WIDTH / 2, RACK_GRID_HEIGHT - RACK_GRID_WIDTH)));

        addParam(createParam<USBAJack>(Vec(7, 333), module, EarthseaModule::USB_PARAM));
        addParam(createParam<TL1105>(Vec(62, 336), module, EarthseaModule::BUTTON_PARAM));
        addParam(createParam<SifamTPN111GrayBlackStripe>(Vec(12.5, 30), module, EarthseaModule::CV1_PARAM));
        addParam(createParam<SifamTPN111GrayBlackStripe>(Vec(12.5, 116), module, EarthseaModule::CV2_PARAM));
        addParam(createParam<SifamTPN111GrayBlackStripe>(Vec(12.5, 202), module, EarthseaModule::CV3_PARAM));

        addOutput(createOutput<PJ301MPort>(Vec(50, 82), module, EarthseaModule::CV1_OUTPUT));
        addOutput(createOutput<PJ301MPort>(Vec(50, 166), module, EarthseaModule::CV2_OUTPUT));
        addOutput(createOutput<PJ301MPort>(Vec(50, 248), module, EarthseaModule::CV3_OUTPUT));
        addOutput(createOutput<PJ301MPort>(Vec(50, 286), module, EarthseaModule::POS_OUTPUT));
        addOutput(createOutput<PJ301MPort>(Vec(15, 265), module, EarthseaModule::EDGE_OUTPUT));

        addChild(createLight<MediumLight<WhiteLight>>(Vec(77, 78), module, EarthseaModule::CV1_LIGHT));
        addChild(createLight<MediumLight<WhiteLight>>(Vec(77, 162), module, EarthseaModule::CV2_LIGHT));
        addChild(createLight<MediumLight<WhiteLight>>(Vec(77, 244), module, EarthseaModule::CV3_LIGHT));
        addChild(createLight<MediumLight<WhiteLight>>(Vec(77, 282), module, EarthseaModule::POS_LIGHT));
        addChild(createLight<MediumLight<YellowLight>>(Vec(2, 282), module, EarthseaModule::EDGE_LIGHT));
    }
};
