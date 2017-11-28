#include "monomemodulebase.hpp"
#include "rack.hpp"

#include <unordered_set>

using namespace rack;

#define GRID_MAX_SIZE 256

struct MonomeGrid : Module
{
    MonomeModuleBase* connectedModule = NULL;
    MonomeDevice device;

    uint8_t ledBuffer[GRID_MAX_SIZE];
    bool pressedState[GRID_MAX_SIZE];

    MonomeGrid(unsigned w, unsigned h);

    void step() override;
    void reset() override;
    void randomize() override;
    json_t* toJson() override;
    void fromJson(json_t* rootJ) override;

    void updateQuadrant(int x, int y, uint8_t* leds);
};

struct MonomeKey;

struct MonomeGridWidget : ModuleWidget
{
    MonomeGridWidget(unsigned w, unsigned h);

    json_t* toJson() override;
    void fromJson(json_t* rootJ) override;
    Menu* createContextMenu() override;
    void onDragEnter(EventDragEnter& e) override;
    void onMouseDown(EventMouseDown& e) override;

    void clearHeldKeys();

protected:
    friend struct MonomeKey;
    bool isDraggingKeys;
    std::unordered_set<MonomeKey*> keysTouchedThisDrag;
};

template <unsigned width, unsigned height>
struct MonomeGridWidgetTemplate : MonomeGridWidget
{
    MonomeGridWidgetTemplate()
        : MonomeGridWidget(width, height)
    {
    }
};
