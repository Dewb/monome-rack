#include "rack.hpp"
#include <unordered_set>

using namespace rack;

struct MonomeKey;

struct Grid128Widget : ModuleWidget {
    Grid128Widget();

    json_t* toJson() override;
    void fromJson(json_t *rootJ) override;
    Menu *createContextMenu() override;
    void onMouseDown(EventMouseDown &e) override;

    void clearHeldKeys();

protected:
    friend struct MonomeKey;
    std::unordered_set<MonomeKey*> keysTouchedThisDrag;
};


