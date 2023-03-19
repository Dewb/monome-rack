#include "rack.hpp"

struct HoldableButton : rack::TL1105
{
    bool heldThisGesture;

    HoldableButton() : rack::TL1105()
    {
        heldThisGesture = false;
    }

    void onButton(const rack::widget::Widget::ButtonEvent& e) override
    {
        // Shift from momentary to toggle if we're control-clicked, to enable a "hold" state
        if (momentary &&
            e.action == GLFW_PRESS && e.button == GLFW_MOUSE_BUTTON_LEFT &&
            (e.mods & RACK_MOD_CTRL) == RACK_MOD_CTRL)
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