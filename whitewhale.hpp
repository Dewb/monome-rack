#include "rack.hpp"

using namespace rack;


extern Plugin *plugin;

////////////////////
// module widgets
////////////////////

struct WhiteWhaleWidget : ModuleWidget {
    WhiteWhaleWidget();
    void randomize() override;
};


