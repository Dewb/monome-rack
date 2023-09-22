#pragma once

#include "rack.hpp"

#include <cstdint>
#include <unordered_map>
#include <atomic>

struct LibAVR32Module;

// Notes on the work-in-progress implementation of II (monome ecosystem i2c):
//
// An i2c module cannot wait for a response to messages. Even if the Rack engine is
// using multiple threads, a leader and follower may be executing on the same thread.
//
// Since the leader will block waiting on a request for data from a follower, we need to
// have the data ready in advance. Therefore the bus must continuously maintain a data
// structure accessible to the leader with all data the leader could possibly request.

struct IIBus
{
    IIBus(LibAVR32Module* leader);
    bool isFollower(rack::Module* module);

    void step();

protected:
    LibAVR32Module* leader;
};
