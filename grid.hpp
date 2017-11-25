#include "rack.hpp"
#include <unordered_set>

using namespace rack;

////////////////////
// module widgets
////////////////////

struct MonomePad;

struct Grid128Widget : ModuleWidget {
    Grid128Widget();
    json_t* toJson() override;
    void fromJson(json_t *rootJ) override;
protected:
    friend struct MonomePad;
    std::unordered_set<MonomePad*> padsTouchedThisDrag;
};


