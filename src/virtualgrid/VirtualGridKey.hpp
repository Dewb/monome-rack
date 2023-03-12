#include "rack.hpp"
#include "VirtualGridTheme.hpp"

struct VirtualGridKey : rack::app::ParamWidget
{
    uint8_t* ledAddress;
    GridTheme* theme;
    float margin;
    float pushAmount;
    float cornerRadius;

    typedef enum
    {
        OFF,
        PRESSED
    } KeyPressState;

    VirtualGridKey()
    : ledAddress(nullptr)
    , theme(nullptr)
    , margin(0.0)
    , pushAmount(0.0)
    , cornerRadius(0.0)
    , _locked(false)
    {
    }

    VirtualGridWidget* getGrid()
    {
        return dynamic_cast<VirtualGridWidget*>(parent);
    }

    void setKeyAddress(uint8_t* ledByte)
    {
        ledAddress = ledByte;
    }

    void draw(const DrawArgs& args) override
    {
        drawLayer(args, 0);
    }

    void drawLayer(const DrawArgs& args, int layer) override
    {
        auto vg = args.vg;
        uint8_t val = ledAddress != NULL ? *ledAddress : 0;
        auto rect = box.size;
        rect.x -= 2 * margin;
        rect.y -= 2 * margin;
        float x = margin;
        float y = margin;
        float pushed = isPushed(); // sample this once so it's consistent
        float innerCornerRadius = cornerRadius * 4.0 / 4.3;

        NVGcolor color1, color2;
        levelToGradient(
            theme ? *theme : GridTheme::Yellow, 
            val,
            &color1, 
            &color2
        );

        // if (isLocked())
        // {
        //     // draw highlight rect around key
        //     nvgBeginPath(vg);
        //     nvgRoundedRect(vg, 0, pushAmount, rect.x + 2 * margin, rect.y + margin, 5.3);
        //     nvgFillColor(vg, nvgRGB(190, 180, 0));
        //     nvgFill(vg);
        // }

        if (!pushed)
        {
            // highlight top and side edges
            if ((val > 0 && layer == 1) || (val == 0 && layer == 0)) {
                nvgBeginPath(vg);
                nvgRoundedRect(vg, x - 0.3, y - 0.3, rect.x + 0.6, rect.y + 0.3, cornerRadius);
                nvgFillColor(vg, val > 0 ? color1 : nvgRGB(180, 180, 180));
                nvgFill(vg);
            }

            // shadow
            if (layer == 0) {
                nvgBeginPath(vg);
                nvgRoundedRect(vg, x, y + pushAmount, rect.x, rect.y - pushAmount + 1.2, innerCornerRadius);
                nvgFillColor(vg, nvgRGB(160, 160, 160));
                nvgFill(vg);
            }
        } else {
            // highlight top and side edges
            if ((val > 0 && layer == 1) || (val == 0 && layer == 0)) {
                nvgBeginPath(vg);
                nvgRoundedRect(vg, x - 0.3, y - 0.3 + pushAmount, rect.x + 0.6, rect.y - pushAmount + 0.3, cornerRadius);
                nvgFillColor(vg, val > 0 ? color1 : nvgRGB(180, 180, 180));
                nvgFill(vg);
            }
            // shadow
            if (layer == 0) {
                nvgBeginPath(vg);
                nvgRoundedRect(vg, x, y + pushAmount, rect.x, rect.y - pushAmount + 0.8, innerCornerRadius);
                nvgFillColor(vg, nvgRGB(160, 160, 160));
                nvgFill(vg);
            }
        }

        // button vertical face
        if (!pushed) {
            if ((val > 0 && layer == 1) || (val == 0 && layer == 0)) {
                nvgBeginPath(vg);
                nvgRoundedRect(vg, x, y + rect.y - (pushAmount + 10), rect.x, pushAmount + 10, innerCornerRadius);
                nvgFillColor(vg, val > 0 ? color2 : nvgRGB(58, 58, 58));
                nvgFill(vg);
            }
        }

        // button top surface
        if (layer == 1) {
            nvgBeginPath(vg);
            auto paint = nvgBoxGradient(vg, x, y + (pushed ? pushAmount : 0), rect.x, rect.y - pushAmount, rect.x * 0.4, rect.x * 1.2, color1, color2);
            nvgRoundedRect(vg, x, y + (pushed ? pushAmount : 0), rect.x, rect.y - pushAmount, innerCornerRadius);
            if (val > 0)
            {
                nvgFillPaint(vg, paint);
            }
            else
            {
                nvgFillColor(vg, nvgRGB(0, 0, 0));
            }
            nvgFill(vg);
        }

        if (isLocked())
        {
            NVGcolor lockColor = nvgRGB(0, 0, 0);

            if (val < 4)
            {
                levelToGradient(theme ? *theme : GridTheme::Yellow, 14, &lockColor, nullptr);
            }

            // drawLock(args, x, y + rect.y/2, rect.x/2, rect.y/2, lockColor);
            drawDot(args, x + rect.x / 4, y + 3 * rect.y / 4, rect.x / 4 - 1.5 * margin, lockColor);
            // drawPin(args, x + 1.5 * margin, y + rect.y * 0.6, rect.x * 0.4 - 1.5 * margin, rect.y * 0.4 - 1.5 * margin, lockColor);
        }
    }

    void drawPin(const DrawArgs& args, float x, float y, float w, float h, NVGcolor& color)
    {
        auto vg = args.vg;

        float d = w / (2 / 1.41421356 + 1);
        float s = w - d;

        nvgBeginPath(vg);
        nvgMoveTo(vg, x, y + w);
        nvgLineTo(vg, x + s, y + d);
        nvgStrokeColor(vg, color);
        nvgStrokeWidth(vg, h * 0.12);
        nvgLineCap(vg, NVG_ROUND);
        nvgStroke(vg);

        nvgBeginPath(vg);
        nvgMoveTo(vg, x, y + d);
        nvgLineTo(vg, x + s, y + w);

        nvgLineTo(vg, x + s, y + 2 * d);
        nvgLineTo(vg, x + w, y + d);
        nvgLineTo(vg, x + s, y);
        nvgLineTo(vg, x + s - d, y + d);
        nvgLineTo(vg, x, y + d);
        nvgFillColor(vg, color);
        nvgLineJoin(vg, NVG_ROUND);
        nvgFill(vg);
    }

    void drawDot(const DrawArgs& args, float cx, float cy, float r, NVGcolor& color)
    {
        auto vg = args.vg;

        nvgBeginPath(vg);
        nvgCircle(vg, cx, cy, r);
        nvgFillColor(vg, color);
        nvgFill(vg);
    }

    void drawLock(const DrawArgs& args, float x, float y, float w, float h, NVGcolor& color)
    {
        auto vg = args.vg;

        float cx = x + w / 2;
        float cy = y + h / 2;
        float bend = y + h / 2.3;
        float r = w / 6.4;

        nvgBeginPath(vg);
        nvgRoundedRect(vg, x + w / 4, cy, w / 2, h / 3, 1.0);
        nvgFillColor(vg, color);
        nvgFill(vg);

        nvgBeginPath(vg);
        nvgMoveTo(vg, cx + r, cy + 2.0);
        nvgLineTo(vg, cx + r, bend);
        nvgArcTo(vg, cx + r, bend - r, cx, bend - r, r);
        nvgArcTo(vg, cx - r, bend - r, cx - r, bend, r);
        nvgLineTo(vg, cx - r, cy + 2.0);
        nvgStrokeColor(vg, color);
        nvgStrokeWidth(vg, h * 0.09);
        nvgStroke(vg);
    }

    rack::engine::ParamQuantity* getSecondaryParamQuantity()
    {
        if (!module)
            return NULL;
        return module->paramQuantities[paramId + 1];
    }

    bool isPushed()
    {
        return
            (getParamQuantity() && getParamQuantity()->getValue() == PRESSED) ||
            (getSecondaryParamQuantity() && getSecondaryParamQuantity()->getValue() == PRESSED);
    }

    bool isLocked()
    {
        return _locked;
    }

    void setLocked(bool b)
    {
        _locked = b;
    }

    void beginPress()
    {
        if (getSecondaryParamQuantity())
        {
            // If shift+ctrl is held and this key is not already locked, lock it
            // If the key is locked, unlock it.
            if (isLocked())
            {
                setLocked(false);
            }
            else if ((APP->window->getMods() & GLFW_MOD_SHIFT) == GLFW_MOD_SHIFT &&
                (APP->window->getMods() & RACK_MOD_CTRL) == RACK_MOD_CTRL)
            {
                setLocked(true);
                getSecondaryParamQuantity()->setImmediateValue(PRESSED);
                return;
            }

            // if we're Ctrl/Mac-clicking an already-held button, release it
            if ((APP->window->getMods() & RACK_MOD_CTRL) == RACK_MOD_CTRL && getSecondaryParamQuantity()->getValue() > 0)
            {
                getSecondaryParamQuantity()->setImmediateValue(OFF);
            }
            else
            {
                getSecondaryParamQuantity()->setImmediateValue(PRESSED);
            }
        }
    }

    void endPress()
    {
        // Ignore mouseup if the key is locked, or when Ctrl is held down
        if (isLocked() || (APP->window->getMods() & RACK_MOD_CTRL) == RACK_MOD_CTRL)
        {
            return;
        }

        if (getSecondaryParamQuantity())
        {
            getSecondaryParamQuantity()->setImmediateValue(OFF);
        }
    }

    void onButton(const rack::event::Button& e) override
    {
        if (e.button == GLFW_MOUSE_BUTTON_LEFT)
        {
            if (e.action == GLFW_PRESS)
            {
                beginPress();
            }
            else
            {
                endPress();
            }
        }
        else if (e.button == GLFW_MOUSE_BUTTON_RIGHT)
        {
            // If this key has not been MIDI mapped, the right-click menu
            // is not useful, so show the module menu
            auto* paramHandle = module
                ? APP->engine->getParamHandle(module->id, paramId)
                : NULL;
            if (!paramHandle)
            {
                return;
            }
        }

        // Repeat logic from ParamWidget::onButton() with minor modifications
        OpaqueWidget::onButton(e);

        // Record touch so MIDI mapping works
        if (e.action == GLFW_PRESS && e.button == GLFW_MOUSE_BUTTON_LEFT && (e.mods & RACK_MOD_MASK) == 0)
        {
            if (module)
            {
                APP->scene->rack->touchedParam = this;
            }
            e.consume(this);
        }

        if (e.action == GLFW_PRESS && e.button == GLFW_MOUSE_BUTTON_RIGHT && (e.mods & RACK_MOD_MASK) == 0)
        {
            destroyTooltip();
            createContextMenu();
            e.consume(NULL); // replaces e.consume(this), which causes key to get pressed on right click for some reason
        }
    }

    void onDragStart(const rack::event::DragStart& e) override
    {
        beginPress();
    }

    void onDragEnd(const rack::event::DragEnd& e) override
    {
        if (e.getTarget() == nullptr || e.getTarget()->parent == this->parent)
        {
            endPress();
        }
    }

    void onDragLeave(const rack::event::DragLeave& e) override
    {
        if (e.origin->parent == this->parent)
        {
            endPress();
        }
    }

    void onDragEnter(const rack::event::DragEnter& e) override
    {
        if (e.origin->parent == this->parent)
        {
            beginPress();
        }
    }

    void onEnter(const EnterEvent& e) override
    {
        // override base class to prevent tooltip creation
    }

protected:
        bool _locked;
};