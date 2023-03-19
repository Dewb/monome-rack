#pragma once

#include <string>
#include "rack.hpp"

#define SCREENSHOT_SVG 0

#if SCREENSHOT_SVG
void screenshotModuleSVG(rack::app::ModuleWidget* moduleWidget, std::string svgPath);
#endif

void screenshotModulePNG(rack::app::ModuleWidget* moduleWidget, std::string pngPath);

