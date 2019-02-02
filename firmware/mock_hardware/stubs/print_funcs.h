
#include <interrupt.h>
#include <stdio.h>

extern void init_dbg_rs232(long pba_hz);

extern void print_dbg(const char* str);
extern void print_dbg_char(int c);
extern void print_dbg_ulong(unsigned long n);
extern void print_dbg_char_hex(unsigned char n);
extern void print_dbg_short_hex(unsigned short n);
extern void print_dbg_hex(unsigned long n);
