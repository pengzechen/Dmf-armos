
#ifndef __IO_H__
#define __IO_H__

#include <aj_types.h>
#include <stdarg.h>
#include <barrier.h>

static inline uint32_t readl(const volatile void *addr) {
    return *(const volatile uint32_t *)addr;
}

static inline void writel(uint32_t value, volatile void *addr) {
	wmb();
    *(volatile uint32_t *)addr = value;
}



extern void uart_putstr(const char * str);


#define puts uart_putstr
extern int printf(const char *fmt, ...);
extern int warning(const char *fmt, ...);
extern int error(const char *fmt, ...);
extern int snprintf(char *buf, int size, const char *fmt, ...);
extern int vsnprintf(char *buf, int size, const char *fmt, va_list va);

extern void io_init();

#endif