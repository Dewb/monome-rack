#pragma once

#include "rack.hpp"
#include "GridConnection.hpp"
#include "ActionQueue.hpp"

void appendDeviceConnectionMenu(rack::Menu* menu, GridConsumer* consumer, ActionQueue* queue, bool hardwareOnly = false);