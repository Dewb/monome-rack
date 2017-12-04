#include <conf_board.h>

void hardware_init();
void hardware_step();

void hardware_triggerInterrupt(int interrupt);

int hardware_getGPIO(uint32_t pin);
void hardware_setGPIO(uint32_t pin, int value);

uint16_t hardware_getADC(int channel);
void hardware_setADC(int channel, uint16_t value);

uint16_t hardware_getDAC(int channel);
void hardware_setDAC(int channel, uint16_t value);

void hardware_initSerial();
void hardware_resetSerial();
uint8_t* hardware_readSerial(int bus);
void hardware_writeSerial(int bus, uint8_t* buf, uint32_t byteCount);

uint8_t* hardware_readSerial_internal(int bus);
void hardware_writeSerial_internal(int bus, uint8_t* buf, uint32_t byteCount);

void hardware_triggerInterrupt();

void hardware_readFlash(void** ptr, uint32_t* size);
void hardware_writeFlash(const void* ptr, uint32_t size);

void hardware_readVolatile(void** ptr, uint32_t* size);
void hardware_writeVolatile(const void* ptr, uint32_t size);
