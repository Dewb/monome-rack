#include "monomemodulebase.hpp"
#include "rack.hpp"

using namespace rack;

struct WhiteWhaleWidget : MonomeModuleBaseWidget
{
    WhiteWhaleWidget();
    void randomize() override;
};
