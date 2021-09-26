#include "rack.hpp"
#include <unordered_set>

#pragma once

typedef enum
{
    MonoRed,
    VariYellow
} GridTheme;

struct MonomeKey;
struct VirtualGridModule;

struct VirtualGridWidget : rack::app::ModuleWidget
{
    VirtualGridWidget(VirtualGridModule* module, unsigned w, unsigned h, unsigned model);

    void draw(const DrawArgs& args) override;
    void onDragEnter(const rack::event::DragEnter& e) override;
    void onDragStart(const rack::event::DragStart& e) override;

    void clearHeldKeys();
    void appendContextMenu(rack::ui::Menu* menu) override;

protected:
    friend struct MonomeKey;

    rack::Vec margins;
    GridTheme theme;
};

template <unsigned width, unsigned height, unsigned modelIndex>
struct VirtualGridWidgetTemplate : VirtualGridWidget
{
    VirtualGridWidgetTemplate(VirtualGridModule* module)
        : VirtualGridWidget(module, width, height, modelIndex)
    {
    }
};
