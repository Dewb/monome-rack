#include "AnsibleWidget.hpp"
#include "AnsibleModule.hpp"
#include "CommonWidgets.hpp"

using namespace rack;

struct HoldableButton : TL1105
{
    bool heldThisGesture;

    HoldableButton() : TL1105()
    {
        heldThisGesture = false;
    }

    void onButton(const ButtonEvent& e) override
    {
        // Shift from momentary to toggle if we're control-clicked, to enable a "hold" state
        if (momentary &&
            e.action == GLFW_PRESS && e.button == GLFW_MOUSE_BUTTON_LEFT &&
            ((e.mods & RACK_MOD_MASK) == GLFW_MOD_CONTROL || (e.mods & RACK_MOD_MASK) == GLFW_MOD_SUPER))
        {
            momentary = false;
            heldThisGesture = true;
        }
        // don't cancel the hold on the very first release event
        else if (e.action == GLFW_RELEASE && heldThisGesture)
        {
            heldThisGesture = false;
        }
        else
        {
            momentary = true;
            heldThisGesture = false;
        }
        TL1105::onButton(e);
    }

    void draw(const DrawArgs& args) override
    {
        if (!momentary) {
            nvgBeginPath(args.vg);
            nvgCircle(args.vg, box.size.x / 2, box.size.y / 2, box.size.x / 2 + 2);
            nvgStrokeColor(args.vg, nvgRGB(190, 180, 0));
            nvgStrokeWidth(args.vg, 4);
            nvgStroke(args.vg);
        }
        TL1105::draw(args);
    }
};

AnsibleWidget::AnsibleWidget(AnsibleModule* module)
{
    setModule(module);

    box.size = Vec(15 * 6, 380);

    {
        auto panel = new SvgPanel();
        panel->setBackground(APP->window->loadSvg(rack::asset::plugin(pluginInstance, "res/ansible.svg")));
        panel->box.size = box.size;
        addChild(panel);
    }

    addChild(createWidget<USBAJack>(Vec(10, 338)));

    addParam(createParam<TL1105>(Vec(62, 336), module, AnsibleModule::MODE_PARAM));
    addParam(createParam<HoldableButton>(Vec(17, 256), module, AnsibleModule::KEY1_PARAM));
    addParam(createParam<HoldableButton>(Vec(54, 256), module, AnsibleModule::KEY2_PARAM));

    addOutput(createOutput<PJ301MPort>(Vec(13, 54), module, AnsibleModule::TR1_OUTPUT));
    addOutput(createOutput<PJ301MPort>(Vec(50, 75), module, AnsibleModule::CV1_OUTPUT));
    addOutput(createOutput<PJ301MPort>(Vec(13, 92), module, AnsibleModule::TR2_OUTPUT));
    addOutput(createOutput<PJ301MPort>(Vec(50, 111), module, AnsibleModule::CV2_OUTPUT));
    addOutput(createOutput<PJ301MPort>(Vec(13, 130), module, AnsibleModule::TR3_OUTPUT));
    addOutput(createOutput<PJ301MPort>(Vec(50, 149), module, AnsibleModule::CV3_OUTPUT));
    addOutput(createOutput<PJ301MPort>(Vec(13, 168), module, AnsibleModule::TR4_OUTPUT));
    addOutput(createOutput<PJ301MPort>(Vec(50, 187), module, AnsibleModule::CV4_OUTPUT));

    addInput(createInput<PJ301MPort>(Vec(13, 286), module, AnsibleModule::IN1_INPUT));
    addInput(createInput<PJ301MPort>(Vec(50, 286), module, AnsibleModule::IN2_INPUT));

    addChild(createLight<MediumLight<YellowLight>>(Vec(2, 72), module, AnsibleModule::TR1_LIGHT));
    addChild(createLight<MediumLight<WhiteLight>>(Vec(77, 72), module, AnsibleModule::CV1_LIGHT));
    addChild(createLight<MediumLight<YellowLight>>(Vec(2, 110), module, AnsibleModule::TR2_LIGHT));
    addChild(createLight<MediumLight<WhiteLight>>(Vec(77, 110), module, AnsibleModule::CV2_LIGHT));
    addChild(createLight<MediumLight<YellowLight>>(Vec(2, 148), module, AnsibleModule::TR3_LIGHT));
    addChild(createLight<MediumLight<WhiteLight>>(Vec(77, 148), module, AnsibleModule::CV3_LIGHT));
    addChild(createLight<MediumLight<YellowLight>>(Vec(2, 186), module, AnsibleModule::TR4_LIGHT));
    addChild(createLight<MediumLight<WhiteLight>>(Vec(77, 186), module, AnsibleModule::CV4_LIGHT));
    addChild(createLight<MediumLight<YellowWhiteLight>>(Vec(77, 326), module, AnsibleModule::MODE_YELLOW_LIGHT));
}
