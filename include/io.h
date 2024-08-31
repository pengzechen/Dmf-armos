
#ifndef __IO_H__
#define __IO_H__

#include "aj_types.h"
#include "stdarg.h"
#include "barrier.h"

static inline uint8_t read8(const volatile void *addr) {
    return *(const volatile uint8_t *)addr;
}

static inline void write8(uint8_t value, volatile void *addr) {
    *(volatile uint8_t *)addr = value;
}

static inline uint16_t read16(const volatile void *addr) {
    return *(const volatile uint16_t *)addr;
}

static inline void write16(uint16_t value, volatile void *addr) {
    *(volatile uint16_t *)addr = value;
}


static inline uint32_t read32(const volatile void *addr) {
    return *(const volatile uint32_t *)addr;
}

static inline void write32(uint32_t value, volatile void *addr) {
    *(volatile uint32_t *)addr = value;
}

static inline uint64_t read64(const volatile void *addr) {
    return *(const volatile uint64_t *)addr;
}

static inline void write64(uint64_t value, volatile void *addr) {
    *(volatile uint64_t *)addr = value;
}

void uart_early_init();
void uart_early_putc(char c);
char uart_early_getc();

void uart_advance_init();
char uart_advance_getc(void);
void uart_advance_putc(char c);


void io_early_init();
void io_init();
char getc();
void putc(char c);


/*  printf 函数库  */
extern void uart_putstr(const char * str);
#define puts uart_putstr

extern int printf(const char *fmt, ...);
extern void print_info(const char *info);
extern void print_warn(const char *info);
extern int warning(const char *fmt, ...);
extern int error(const char *fmt, ...);
extern int snprintf(char *buf, int size, const char *fmt, ...);
extern int vsnprintf(char *buf, int size, const char *fmt, va_list va);



#endif