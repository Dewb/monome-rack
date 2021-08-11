#include <conf_board.h>

typedef enum
{
    FTDI_BUS,
    HID_BUS,
    NUM_BUSES
} serial_bus_t;

void hardware_init();
void hardware_step();

void hardware_triggerInterrupt(int interrupt);

bool hardware_getGPIO(uint32_t pin);
void hardware_setGPIO(uint32_t pin, bool value);

uint16_t hardware_getADC(int channel);
void hardware_setADC(int channel, uint16_t value);

uint16_t hardware_getDAC(int channel);
void hardware_setDAC(int channel, uint16_t value);

void hardware_initSerial();
void hardware_resetSerialIn();
void hardware_resetSerialOut();

void hardware_serialConnectionChange(serial_bus_t bus, uint8_t connected, const char* manufacturer, const char* product, const char* serial);

void hardware_readSerial(serial_bus_t bus, uint8_t** pbuf, uint32_t* pcount);
void hardware_writeSerial(serial_bus_t bus, uint8_t* buf, uint32_t byteCount);

void hardware_readSerial_internal(serial_bus_t bus, uint8_t** pbuf, uint32_t* pcount);
void hardware_writeSerial_internal(serial_bus_t bus, uint8_t* buf, uint32_t byteCount);

void hardware_triggerInterrupt();

void hardware_getScreenBuffer(uint8_t** ptr, uint16_t* width, uint16_t* height);

void hardware_hidConnect();
void hardware_hidDisconnect();
void hardware_hidMessage(uint8_t key, uint8_t mod, bool held, bool release);