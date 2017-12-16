#ifndef __SERIALOSC_H__
#define __SERIALOSC_H__

#include <string>
#include <vector>
#include <thread>
#include "osc/OscPacketListener.h"
#include "ip/UdpSocket.h"
#include "MonomeDevice.h"

#define SERIALOSC_ADDRESS "127.0.0.1"
#define SERIALOSC_PORT 12002

class UdpListeningReceiveSocket;


class SerialOsc
	: protected osc::OscPacketListener
{
public:
	struct Listener
	{
		virtual void deviceFound(const MonomeDevice * const device) {}
		virtual void deviceRemoved(const std::string &id) {}
		virtual void buttonPressMessageReceived(MonomeDevice *device, int x, int y, bool state) = 0;
	};

	typedef std::vector<MonomeDevice*> MonomeDeviceCollection;
	typedef std::vector<MonomeDevice*>::iterator MonomeDeviceCollectionIterator;

public:
	SerialOsc(std::string devicePrefix, int defaultPort, int maxPortsToScan = 1000);
	virtual ~SerialOsc(void);

	void start(Listener *listener);
	void stop(void);

	int getListenPort(void) const { return listenPort; }
	int getDeviceCount(void) const { return devices.size(); }
	const MonomeDeviceCollection& getDevices(void) const { return devices; }

public:
	// Serialosc messages
	void sendDeviceQueryMessage(void);
	void sendDeviceNotifyMessage(void);
	void sendDeviceInfoMessage(int port);
	void sendDevicePortMessage(int port);
	void sendDevicePrefixMessage(int port);

	// Device messages
	void sendDeviceLedCommand(const MonomeDevice * const device, int x, int y, bool state);
	void sendDeviceLedAllCommand(const MonomeDevice * const device, bool state);
	void sendDeviceLedRowCommand(const MonomeDevice* const device, int x_offset, int y, uint8_t stateBits);
	void sendDeviceLedMapCommand(const MonomeDevice* const device, int x, int y, uint8_t* stateMap);
	void sendDeviceLedLevelMapCommand(const MonomeDevice* const device, int x, int y, uint8_t* stateMap);

        // TODO : Add other device outgoing message types (row, map, etc)

protected:
	void runThread(void);
	void ProcessMessage(const osc::ReceivedMessage& m, const IpEndpointName& remoteEndpoint);

protected:
	UdpListeningReceiveSocket *listenSocket;
	Listener *listener;
	MonomeDeviceCollection devices;
	std::string currentDeviceID;
	std::string devicePrefix;
	int listenPort;
	int portsToScan;
	std::thread thread;
};

#endif //_SERIALOSC_H__