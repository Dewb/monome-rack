
#include <stdio.h>
#include <interrupt.h>

inline void init_dbg_rs232(long pba_hz) {}

inline void print_dbg(const char *str) { fprintf(stderr, "%s", str); }
inline void print_dbg_char(int c) { fprintf(stderr, "%d", c); }
inline void print_dbg_ulong(unsigned long n) { fprintf(stderr, "%ld", n); }
inline void print_dbg_char_hex(unsigned char n) { fprintf(stderr, "%x", n); }
inline void print_dbg_short_hex(unsigned short n) { fprintf(stderr, "%d", n); }
inline void print_dbg_hex(unsigned long n) { fprintf(stderr, "%lx", n); }
