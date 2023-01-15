#include "rack.hpp"
#include "VirtualGridTheme.hpp"

struct VirtualGridKey : rack::app::ParamWidget
{
    uint8_t* ledAddress;
    GridTheme* theme;
    float margin;

    typedef enum
    {
        OFF,
        PRESSED
    } KeyPressState;

    VirtualGridKey()
    : ledAddress(nullptr)
    , theme(nullptr)
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
        float pushAmount = 2.6;
        float pushed = isPushed(); // sample this once so it's consistent

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
                nvgRoundedRect(vg, x - 0.3, y - 0.3, rect.x + 0.6, rect.y + 0.3, 4.3);
                nvgFillColor(vg, val > 0 ? color1 : nvgRGB(180, 180, 180));
                nvgFill(vg);
            }

            // shadow
            if (layer == 0) {
                nvgBeginPath(vg);
                nvgRoundedRect(vg, x, y + pushAmount, rect.x, rect.y - pushAmount + 1.2, 4);
                nvgFillColor(vg, nvgRGB(160, 160, 160));
                nvgFill(vg);
            }
        } else {
            // highlight top and side edges
            if ((val > 0 && layer == 1) || (val == 0 && layer == 0)) {
                nvgBeginPath(vg);
                nvgRoundedRect(vg, x - 0.3, y - 0.3 + pushAmount, rect.x + 0.6, rect.y - pushAmount + 0.3, 4.3);
                nvgFillColor(vg, val > 0 ? color1 : nvgRGB(180, 180, 180));
                nvgFill(vg);
            }
            // shadow
            if (layer == 0) {
                nvgBeginPath(vg);
                nvgRoundedRect(vg, x, y + pushAmount, rect.x, rect.y - pushAmount + 0.8, 4);
                nvgFillColor(vg, nvgRGB(160, 160, 160));
                nvgFill(vg);
            }
        }

        // button vertical face
        if (!pushed) {
            if ((val > 0 && layer == 1) || (val == 0 && layer == 0)) {
                nvgBeginPath(vg);
                nvgRoundedRect(vg, x, y + rect.y - (pushAmount + 10), rect.x, pushAmount + 10, 4);
                nvgFillColor(vg, val > 0 ? color2 : nvgRGB(58, 58, 58));
                nvgFill(vg);
            }
        }

        // button top surface
        if (layer == 1) {
            nvgBeginPath(vg);
            auto paint = nvgBoxGradient(vg, x, y + (pushed ? pushAmount : 0), rect.x, rect.y - pushAmount, rect.x * 0.4, rect.x * 1.2, color1, color2);
            nvgRoundedRect(vg, x, y + (pushed ? pushAmount : 0), rect.x, rect.y - pushAmount, 4);
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
            NVGcolor lightLockColor, darkLockColor;

            levelToGradient(theme ? *theme : GridTheme::Yellow, 14, &lightLockColor, nullptr);
            darkLockColor = nvgRGB(0, 0, 0);

            nvgBeginPath(vg);
            nvgRoundedRect(vg, x + rect.x / 4, y + rect.y / 2, rect.x / 2, rect.y / 3, 1.0);
            nvgFillColor(vg, val > 3 ? darkLockColor : lightLockColor);
            nvgFill(vg);

            nvgBeginPath(vg);
            nvgShapeAntiAlias(vg, 1);
            nvgArc(vg, x + rect.x / 2, y + rect.y / 2.3, rect.x / 6.4, 0, 3.14159, NVG_CCW);
            nvgLineTo(vg, x + rect.x / 2 - rect.x / 6.4, y + rect.y / 2);
            nvgMoveTo(vg, x + rect.x / 2 + rect.x / 6.4, y + rect.y / 2.3);
            nvgLineTo(vg, x + rect.x / 2 + rect.x / 6.4, y + rect.y / 2);
            nvgStrokeColor(vg, val > 3 ? darkLockColor : lightLockColor);
            nvgStrokeWidth(vg, 3.5);
            nvgStroke(vg);
        }
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
                getSecondaryParamQuantity()->setValue(PRESSED);
                return;
            }

            // if we're Ctrl/Mac-clicking an already-held button, release it
            if ((APP->window->getMods() & RACK_MOD_CTRL) == RACK_MOD_CTRL && getSecondaryParamQuantity()->getValue() > 0)
            {
                getSecondaryParamQuantity()->setValue(OFF);
            }
            else
            {
                getSecondaryParamQuantity()->setValue(PRESSED);
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
            getSecondaryParamQuantity()->setValue(OFF);
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