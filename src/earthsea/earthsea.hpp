#include "monomemodulebase.hpp"
#include "rack.hpp"

using namespace rack;

struct EarthseaWidget : MonomeModuleBaseWidget
{
    EarthseaWidget();
    void randomize() override;
};
