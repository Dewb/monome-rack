#ifndef __MONOMEDEVICE_H__
#define __MONOMEDEVICE_H__

#include <string>

typedef enum {
    PROTOCOL_40H,
    PROTOCOL_SERIES,
    PROTOCOL_MEXT
} MonomeProtocol;

struct MonomeDevice
{
    std::string id;
    std::string type;
    std::string prefix;
    int port;
    int width;
    int height;
    int rotation;
    MonomeProtocol protocol;
    bool varibright;
};

#endif //__MONOMEDEVICE_H__