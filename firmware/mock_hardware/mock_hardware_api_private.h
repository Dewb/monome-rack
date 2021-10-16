// Functions that are only intended to be called internally

extern int hardware_readSerial_internal(uint8_t** pbuf, uint8_t* pcount);
extern int hardware_writeSerial_internal(uint8_t* buf, uint8_t byteCount);

extern void hardware_afterInit();