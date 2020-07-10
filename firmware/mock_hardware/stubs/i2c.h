
typedef void (*process_ii_t)(uint8_t *d, uint8_t l);
volatile process_ii_t process_ii;

extern int i2c_master_tx(uint8_t addr, uint8_t* data, uint8_t l);
extern int i2c_master_rx(uint8_t addr, uint8_t* data, uint8_t l);