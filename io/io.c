
#include <uart_pl011.h>
#include <spinlock.h>

static spinlock_t lock;

void io_init() {
    spinlock_init(&lock);
    uart_init();
}

void uart_putstr(const char *str)
{
    spin_lock(&lock);
    while (*str)
    {
        uart_putc(*str++);
    }
    spin_unlock(&lock);
}