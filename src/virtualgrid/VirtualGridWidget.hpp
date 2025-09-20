#include "rack.hpp"

#pragma once

extern rack::Plugin* pluginInstance;

struct VirtualGridKey;
struct VirtualGridModule;

struct VirtualGridWidget : rack::app::ModuleWidget
{
    VirtualGridWidget(VirtualGridModule* module, unsigned w, unsigned h);
    ~VirtualGridWidget();

    void onDragEnter(const DragEnterEvent& e) override;
    void onDragStart(const DragStartEvent& e) override;
    void onDragEnd(const DragEndEvent& e) override;
    void onDragLeave(const DragLeaveEvent& e) override;
    void onHoverKey(const HoverKeyEvent& e) override;
    void onLeave(const LeaveEvent& e) override;
    void appendContextMenu(rack::ui::Menu* menu) override;

    void clearHeldKeys();
    void clearLockedKeys();

protected:
    friend struct VirtualGridKey;
    rack::Vec margins;
    std::string id;
};

template <unsigned width, unsigned height>
struct VirtualGridWidgetTemplate : VirtualGridWidget
{
    VirtualGridWidgetTemplate(VirtualGridModule* module)
        : VirtualGridWidget(module, width, height)
    {
    }
};
