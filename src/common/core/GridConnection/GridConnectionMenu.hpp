#pragma once

#include "rack.hpp"
#include "GridConnection.hpp"
#include "ActionQueue.hpp"

void appendDeviceConnectionMenu(rack::Menu* menu, IGridConsumer* consumer, ActionQueue* queue, bool hardwareOnly = false);