#pragma once

#include "rack.hpp"
#include <functional>

typedef std::function<void(void)> Action;
typedef rack::dsp::RingBuffer<Action, 4> ActionQueue;