#include "monomemodulebase.hpp"
#include "rack.hpp"

using namespace rack;

struct TeletypeWidget : MonomeModuleBaseWidget
{
    TeletypeWidget();

    void onKey(EventKey& e) override;
};
