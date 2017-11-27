#ifndef __MONOMEDEVICE_H__
#define __MONOMEDEVICE_H__

#include <string>

struct MonomeDevice
{
	std::string id;
	std::string type;
	std::string prefix;
	int port;
	int width;
	int height;
	int rotation;
};

#endif //__MONOMEDEVICE_H__