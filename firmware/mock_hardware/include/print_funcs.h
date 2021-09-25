
#include "compiler.h"
#include <interrupt.h>
#include <stdio.h>

extern void init_dbg_rs232(long pba_hz);

static inline void print_dbg(const char* str) { fprintf(stderr, "%s", str); }
static inline void print_dbg_char(int c) { fprintf(stderr, "%d", c); }
static inline void print_dbg_ulong(unsigned long n) { fprintf(stderr, "%ld", n); }
static inline void print_dbg_char_hex(unsigned char n) { fprintf(stderr, "%x", n); }
static inline void print_dbg_short_hex(unsigned short n) { fprintf(stderr, "%d", n); }
static inline void print_dbg_hex(unsigned long n) { fprintf(stderr, "%lx", n); }
