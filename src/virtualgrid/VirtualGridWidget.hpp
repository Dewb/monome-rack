#include "rack.hpp"
#include <unordered_set>

#pragma once

typedef enum {
    MonoRed,
    VariYellow
} GridTheme;

struct MonomeKey;


struct VirtualGridWidget : rack::ModuleWidget
{
    VirtualGridWidget(unsigned w, unsigned h, unsigned model);

    json_t* toJson() override;
    void fromJson(json_t* rootJ) override;
    rack::Menu* createContextMenu() override;
    void onDragEnter(rack::EventDragEnter& e) override;
    void onMouseDown(rack::EventMouseDown& e) override;
    void randomize() override;

    void clearHeldKeys();

protected:
    friend struct MonomeKey;
    bool isDraggingKeys;
    std::unordered_set<MonomeKey*> keysTouchedThisDrag;

    rack::Vec margins;
    GridTheme theme;
};

template <unsigned width, unsigned height, unsigned modelIndex>
struct VirtualGridWidgetTemplate : VirtualGridWidget
{
    VirtualGridWidgetTemplate()
        : VirtualGridWidget(width, height, modelIndex)
    {
    }
};
