#include "rack.hpp"
#include "VirtualGridTheme.hpp"

struct VirtualGridKey : rack::app::ParamWidget
{
    uint8_t* ledAddress;
    int index;
    GridTheme* theme;
    float margin;

    typedef enum
    {
        OFF,
        PRESSED,
        HELD
    } KeyPressState;

    VirtualGridKey()
    : ledAddress(nullptr)
    , theme(nullptr)
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

    void drawLayer(const DrawArgs& args, int layer) override
    {
        if (layer != 1) {
            return;
        }

        auto vg = args.vg;
        uint8_t val = ledAddress != NULL ? *ledAddress : 0;
        auto rect = box.size;
        rect.x -= 2 * margin;
        rect.y -= 2 * margin;
        float x = margin;
        float y = margin;

        NVGcolor color1, color2;
        levelToGradient(
            theme ? *theme : GridTheme::Yellow, 
            val,
            &color1, 
            &color2
        );

        if (getParamQuantity() && getParamQuantity()->getValue() == HELD)
        {
            nvgBeginPath(vg);
            nvgRoundedRect(vg, x - 3, x - 3, rect.x + 6, rect.y + 6, 6);
            nvgFillColor(vg, nvgRGB(180, 180, 0));
            nvgFill(vg);
        }

        nvgBeginPath(vg);
        auto paint = nvgBoxGradient(vg, x, y, rect.x, rect.y, rect.x * 0.4, rect.x * 1.2, color1, color2);
        nvgRoundedRect(vg, x, y, rect.x, rect.y, 4);
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

    void beginPress()
    {
        if (getParamQuantity())
        {
            float value = getParamQuantity()->getValue();

            if ((APP->window->getMods() & RACK_MOD_MASK) == RACK_MOD_CTRL && value != HELD)
            {
                // hold key down
                getParamQuantity()->setValue(HELD);
            }
            else
            {
                getParamQuantity()->setValue(PRESSED);
            }
        }
    }

    void endPress()
    {
        if (getParamQuantity())
        {
            if (getParamQuantity()->getValue() != HELD)
            {
                getParamQuantity()->setValue(OFF);
            }
        }
    }

    void onButton(const rack::event::Button& e) override
    {
        if (e.button != GLFW_MOUSE_BUTTON_LEFT)
        {
            return;
        }
        e.consume(this);

        if (e.action == GLFW_PRESS)
        {
            beginPress();
        }
        else
        {
            endPress();
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
};