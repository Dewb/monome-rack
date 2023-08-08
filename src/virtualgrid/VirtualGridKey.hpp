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

        NVGcolor edgeColor = !rack::settings::preferDarkPanels ? nvgRGB(180, 180, 180) : nvgRGB(96, 96, 94);
        NVGcolor shadowColor = !rack::settings::preferDarkPanels ? nvgRGB(140, 140, 140) : nvgRGB(60, 60, 50);
        NVGcolor faceColor = !rack::settings::preferDarkPanels ? nvgRGB(58, 58, 58) : nvgRGB(20, 20, 10);

        if (!pushed)
        {
            // highlight top and side edges
            if ((val > 0 && layer == 1) || (val == 0 && layer == 0)) {
                nvgBeginPath(vg);
                nvgRoundedRect(vg, x - 0.3, y - 0.3, rect.x + 0.6, rect.y + 0.3, cornerRadius);
                nvgFillColor(vg, val > 0 ? color1 : edgeColor);
                nvgFill(vg);
            }

            // shadow
            if (layer == 0) {
                nvgBeginPath(vg);
                nvgRoundedRect(vg, x, y + pushAmount, rect.x, rect.y - pushAmount + 1.2, innerCornerRadius);
                nvgFillColor(vg, shadowColor);
                nvgFill(vg);
            }
        } else {
            // highlight top and side edges
            if ((val > 0 && layer == 1) || (val == 0 && layer == 0)) {
                nvgBeginPath(vg);
                nvgRoundedRect(vg, x - 0.3, y - 0.3 + pushAmount, rect.x + 0.6, rect.y - pushAmount + 0.3, cornerRadius);
                nvgFillColor(vg, val > 0 ? color1 : edgeColor);
                nvgFill(vg);
            }
            // shadow
            if (layer == 0) {
                nvgBeginPath(vg);
                nvgRoundedRect(vg, x, y + pushAmount, rect.x, rect.y - pushAmount + 0.8, innerCornerRadius);
                nvgFillColor(vg, shadowColor);
                nvgFill(vg);
            }
        }

        // button vertical face
        if (!pushed) {
            if ((val > 0 && layer == 1) || (val == 0 && layer == 0)) {
                nvgBeginPath(vg);
                nvgRoundedRect(vg, x, y + rect.y - (pushAmount + 10), rect.x, pushAmount + 10, innerCornerRadius);
                nvgFillColor(vg, val > 0 ? color2 : faceColor);
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

            drawDot(args, x + rect.x / 4, y + 3 * rect.y / 4, rect.x / 4 - 1.5 * margin, lockColor);
        }
    }

    void drawDot(const DrawArgs& args, float cx, float cy, float r, NVGcolor& color)
    {
        auto vg = args.vg;

        nvgBeginPath(vg);
        nvgCircle(vg, cx, cy, r);
        nvgFillColor(vg, color);
        nvgFill(vg);
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