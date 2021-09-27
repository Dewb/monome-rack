#include "SerialOsc.h"
#include "osc/OscOutboundPacketStream.h"
#include <algorithm>
#include <exception>
#include <iostream>

#define OSC_BUFFER_SIZE 1024

SerialOsc::SerialOsc(std::string devicePrefix, int defaultPort, int maxPortsToScan)
    : listenSocket(nullptr)
    , listener(nullptr)
    , devicePrefix(devicePrefix)
    , listenPort(defaultPort)
    , portsToScan(maxPortsToScan < 1 ? 1 : maxPortsToScan)
{
}

SerialOsc::~SerialOsc(void)
{
    if (listenSocket != nullptr)
    {
        stop();
        delete listenSocket;
    }

    for (auto it = devices.begin(); it != devices.end(); ++it)
    {
        delete *it;
    }
}

void SerialOsc::start(Listener* listener)
{
    this->listener = listener;

    if (listener == nullptr || listenSocket != nullptr)
    {
        return;
    }

    for (int i = 0; i < portsToScan; i++)
    {
        int tempPort = listenPort + i;

        try
        {
            listenSocket = new UdpListeningReceiveSocket(
                IpEndpointName(IpEndpointName::ANY_ADDRESS, tempPort),
                this);

            listenPort = tempPort;
            std::cout << "Binding to port " << tempPort << "." << std::endl;
            break;
        }
        catch (std::runtime_error& ex)
        {
            // try next port
            listenSocket = nullptr;
            std::cerr << "Failed to bind to port " << tempPort << ". " << ex.what() << std::endl;
        }
    }

    if (listenSocket != nullptr)
    {
        thread = std::thread(&SerialOsc::runThread, this);

        sendDeviceQueryMessage();
        sendDeviceNotifyMessage();
    }
}

void SerialOsc::stop(void)
{
    if (listenSocket != nullptr)
    {
        listenSocket->AsynchronousBreak();
        thread.join();
        listenSocket = nullptr;
    }
}

void SerialOsc::runThread(void)
{
    if (listenSocket != nullptr)
    {
        listenSocket->Run();
    }
}

void SerialOsc::sendDeviceQueryMessage(void)
{
    UdpTransmitSocket transmitSocket(IpEndpointName(SERIALOSC_ADDRESS, SERIALOSC_PORT));
    char buffer[OSC_BUFFER_SIZE];
    osc::OutboundPacketStream p(buffer, OSC_BUFFER_SIZE);

    p << osc::BeginBundleImmediate
      << osc::BeginMessage("/serialosc/list")
      << SERIALOSC_ADDRESS
      << listenPort
      << osc::EndMessage
      << osc::EndBundle;

    transmitSocket.Send(p.Data(), p.Size());
}

void SerialOsc::sendDeviceNotifyMessage(void)
{
    UdpTransmitSocket transmitSocket(IpEndpointName(SERIALOSC_ADDRESS, SERIALOSC_PORT));
    char buffer[OSC_BUFFER_SIZE];
    osc::OutboundPacketStream p(buffer, OSC_BUFFER_SIZE);

    p << osc::BeginBundleImmediate
      << osc::BeginMessage("/serialosc/notify")
      << SERIALOSC_ADDRESS
      << listenPort
      << osc::EndMessage
      << osc::EndBundle;

    transmitSocket.Send(p.Data(), p.Size());
}

void SerialOsc::sendDeviceInfoMessage(int port)
{
    UdpTransmitSocket transmitSocket(IpEndpointName(SERIALOSC_ADDRESS, port));
    char buffer[OSC_BUFFER_SIZE];
    osc::OutboundPacketStream p(buffer, OSC_BUFFER_SIZE);

    p << osc::BeginBundleImmediate
      << osc::BeginMessage("/sys/info")
      << listenPort
      << osc::EndMessage
      << osc::EndBundle;

    transmitSocket.Send(p.Data(), p.Size());
}

void SerialOsc::sendDevicePortMessage(int port)
{
    UdpTransmitSocket transmitSocket(IpEndpointName(SERIALOSC_ADDRESS, port));
    char buffer[OSC_BUFFER_SIZE];
    osc::OutboundPacketStream p(buffer, OSC_BUFFER_SIZE);

    p << osc::BeginBundleImmediate
      << osc::BeginMessage("/sys/port")
      << listenPort
      << osc::EndMessage
      << osc::EndBundle;

    transmitSocket.Send(p.Data(), p.Size());
}

void SerialOsc::sendDevicePrefixMessage(int port)
{
    std::string prefix = devicePrefix;

    if (prefix.find("/") == 0)
    {
        prefix = prefix.substr(1);
    }

    UdpTransmitSocket transmitSocket(IpEndpointName(SERIALOSC_ADDRESS, port));
    char buffer[OSC_BUFFER_SIZE];
    osc::OutboundPacketStream p(buffer, OSC_BUFFER_SIZE);

    p << osc::BeginBundleImmediate
      << osc::BeginMessage("/sys/prefix")
      << prefix.c_str()
      << osc::EndMessage
      << osc::EndBundle;

    transmitSocket.Send(p.Data(), p.Size());
}

void SerialOsc::sendDeviceLedCommand(const MonomeDevice* const device, int x, int y, bool state)
{
    UdpTransmitSocket transmitSocket(IpEndpointName(SERIALOSC_ADDRESS, device->port));
    char buffer[OSC_BUFFER_SIZE];
    osc::OutboundPacketStream p(buffer, OSC_BUFFER_SIZE);
    std::string address = (device->prefix + "/grid/led/set");

    p << osc::BeginBundleImmediate
      << osc::BeginMessage(address.c_str())
      << x
      << y
      << (state ? 1 : 0)
      << osc::EndMessage
      << osc::EndBundle;

    transmitSocket.Send(p.Data(), p.Size());
}

void SerialOsc::sendDeviceLedAllCommand(const MonomeDevice* const device, bool state)
{
    UdpTransmitSocket transmitSocket(IpEndpointName(SERIALOSC_ADDRESS, device->port));
    char buffer[OSC_BUFFER_SIZE];
    osc::OutboundPacketStream p(buffer, OSC_BUFFER_SIZE);
    std::string address = (device->prefix + "/grid/led/all");

    p << osc::BeginBundleImmediate
      << osc::BeginMessage(address.c_str())
      << (state ? 1 : 0)
      << osc::EndMessage
      << osc::EndBundle;

    transmitSocket.Send(p.Data(), p.Size());
}

void SerialOsc::sendDeviceLedRowCommand(const MonomeDevice* const device, int x_offset, int y, uint8_t stateBits)
{
    UdpTransmitSocket transmitSocket(IpEndpointName(SERIALOSC_ADDRESS, device->port));
    char buffer[OSC_BUFFER_SIZE];
    osc::OutboundPacketStream p(buffer, OSC_BUFFER_SIZE);
    std::string address = (device->prefix + "/grid/led/row");

    p << osc::BeginBundleImmediate
      << osc::BeginMessage(address.c_str())
      << x_offset
      << y
      << stateBits
      << osc::EndMessage
      << osc::EndBundle;

    transmitSocket.Send(p.Data(), p.Size());
}

void SerialOsc::sendDeviceLedMapCommand(const MonomeDevice* const device, int x, int y, uint8_t* stateMap)
{
    UdpTransmitSocket transmitSocket(IpEndpointName(SERIALOSC_ADDRESS, device->port));
    char buffer[OSC_BUFFER_SIZE];
    osc::OutboundPacketStream p(buffer, OSC_BUFFER_SIZE);
    std::string address = (device->prefix + "/grid/led/map");

    p << osc::BeginBundleImmediate
      << osc::BeginMessage(address.c_str())
      << x
      << y;

    for (int i = 0; i < 8; i++)
    {
        p << stateMap[i];
    }

    p << osc::EndMessage
      << osc::EndBundle;

    transmitSocket.Send(p.Data(), p.Size());
}

void SerialOsc::sendDeviceLedLevelMapCommand(const MonomeDevice* const device, int x, int y, uint8_t* stateMap)
{
    UdpTransmitSocket transmitSocket(IpEndpointName(SERIALOSC_ADDRESS, device->port));
    char buffer[OSC_BUFFER_SIZE];
    osc::OutboundPacketStream p(buffer, OSC_BUFFER_SIZE);
    std::string address = (device->prefix + "/grid/led/level/map");

    p << osc::BeginBundleImmediate
      << osc::BeginMessage(address.c_str())
      << x
      << y;

    for (int i = 0; i < 64; i++)
    {
        p << stateMap[i];
    }

    p << osc::EndMessage
      << osc::EndBundle;

    transmitSocket.Send(p.Data(), p.Size());
}

void SerialOsc::ProcessMessage(const osc::ReceivedMessage& m, const IpEndpointName& remoteEndpoint)
{
    std::string address = m.AddressPattern();
    auto iter = m.ArgumentsBegin();

    try
    {
        if (address == "/serialosc/device" || address == "/serialosc/add")
        {
            std::string id = (iter++)->AsString();
            std::string type = (iter++)->AsString();
            int port = (iter++)->AsInt32();
            MonomeDevice* device = nullptr;

            auto deviceIterator = std::find_if(devices.begin(), devices.end(), [id](const MonomeDevice* x) { return x->id == id; });

            if (deviceIterator == devices.end())
            {
                device = new MonomeDevice;
                devices.push_back(device);

                if (address == "/serialosc/add")
                {
                    sendDeviceNotifyMessage();
                }
            }
            else
            {
                device = *deviceIterator;
            }

            device->id = id;
            const char* idstr = device->id.c_str();

            if (strncmp(idstr, "m40h", 4) == 0 || strncmp(idstr, "a40h", 4) == 0)
            {
                device->protocol = PROTOCOL_40H;
                device->varibright = false;
            }
            else if (strncmp(idstr, "m64-", 4) == 0 || strncmp(idstr, "m128-", 5) == 0 || strncmp(idstr, "m256-", 5) == 0)
            {
                device->protocol = PROTOCOL_SERIES;
                device->varibright = false;
            }
            else
            {
                device->protocol = PROTOCOL_MEXT;
                device->varibright = true;
            }

            device->type = type;
            device->port = port;
            device->prefix = devicePrefix;

            if (device->prefix.find("/") != 0)
            {
                device->prefix = "/" + device->prefix;
            }

            // wait until after size message recieved -MD
            // listener->deviceFound(device);
            sendDeviceInfoMessage(device->port);

            sendDevicePrefixMessage(port);
            sendDevicePortMessage(port);
        }
        else if (address == "/serialosc/remove")
        {
            std::string id = (iter++)->AsString();

            auto deviceIterator = std::find_if(devices.begin(), devices.end(), [id](const MonomeDevice* x) { return x->id == id; });

            if (deviceIterator != devices.end())
            {
                std::remove(devices.begin(), devices.end(), *deviceIterator);
                delete *deviceIterator;

                listener->deviceRemoved(id);

                sendDeviceNotifyMessage();
            }
        }
        else if (address == "/sys/id")
        {
            currentDeviceID = (iter++)->AsString();
        }
        else if (address == "/sys/size")
        {
            auto deviceIterator = std::find_if(devices.begin(), devices.end(), [=](const MonomeDevice* x) { return x->id == currentDeviceID; });

            if (deviceIterator != devices.end())
            {
                auto device = *deviceIterator;
                device->width = (iter++)->AsInt32();
                device->height = (iter++)->AsInt32();

                // wait to notify listeners here, after size is known -MD
                listener->deviceFound(device);
            }
        }
        else if (address == "/sys/rotation")
        {
            auto deviceIterator = std::find_if(devices.begin(), devices.end(), [=](const MonomeDevice* x) { return x->id == currentDeviceID; });

            if (deviceIterator != devices.end())
            {
                auto device = *deviceIterator;
                device->rotation = (iter++)->AsInt32();
            }
        }
        else if (address == ("/" + devicePrefix + "/grid/key"))
        {
            auto deviceIterator = std::find_if(devices.begin(), devices.end(), [=](const MonomeDevice* x) { return x->port == remoteEndpoint.port; });

            int x = (iter++)->AsInt32();
            int y = (iter++)->AsInt32();
            bool state = (iter++)->AsInt32() > 0;

            listener->buttonPressMessageReceived(*deviceIterator, x, y, state);
        }
        // TODO : Handle other incoming device commands
    }
    catch (osc::WrongArgumentTypeException& exc)
    {
        printf("WrongArgumentTypeException: %s", exc.what());
    }
}