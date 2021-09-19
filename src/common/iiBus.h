#pragma once

#include "rack.hpp"

#include <cstdint>
#include <unordered_map>
#include <atomic>

#define MAX_II_DATA_BYTES 8

// i2c devices cannot wait on each other. Even if the Rack engine is using multiple threads,
// a leader and follower may be executing on the same thread. 
// Since the leader will block waiting on a request for data from a follower, we need to 
// have the data ready in advance. Therefore all followers must continuously update a data
// structure accessible to the leader with all data the leader could possible request. 

// cheapo concurrent data structure for time-travelling follower data
typedef std::unordered_map<uint16_t, std::atomic<uint16_t>> iiFollowerData_t;

struct iiBus {
    static void Initialize();
    static iiFollowerData_t FollowerData;
};

// TODO: send commands from follower over Rack expander bus
struct iiCommand
{
    // 7-bit I2C address
    uint8_t address;
    uint8_t data[MAX_II_DATA_BYTES];
    uint8_t length;
};

struct iiDevice
{
    iiDevice(rack::Module* module);

    void setAddress(uint8_t address);
    void updateFollowerData(uint8_t id, uint16_t data);
    void transmit(const iiCommand& msg);

protected:
    rack::Module* _module;
    uint8_t _address; 
};