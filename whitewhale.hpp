#include "rack.hpp"

using namespace rack;

struct WhiteWhaleWidget : ModuleWidget {
    WhiteWhaleWidget();
    void randomize() override;
    Menu* createContextMenu() override;
};


