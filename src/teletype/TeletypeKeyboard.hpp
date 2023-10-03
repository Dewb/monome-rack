#pragma once
#include "rack.hpp"
#include <stdint.h>



struct TeletypeKeyboard
{
    static void init();
    static void setCurrentLayout(std::string layoutName);
    static const std::string& getCurrentLayout();
    static bool process(const rack::event::SelectKey& e, uint8_t* pkey, uint8_t* pmod);

    static int stringToGLFWCode(std::string s);
    static uint8_t stringToHIDCode(std::string s);

protected:
    static void loadMap();
    typedef std::map<std::pair<int, int>, std::pair<uint8_t, uint8_t>> KeycodeMap;
    static KeycodeMap keycodeMap;
    static bool initialized;
    static std::string currentLayout;
};