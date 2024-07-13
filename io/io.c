
#include <uart_pl011.h>
#include <spinlock.h>
#include <io.h>

static spinlock_t lock;

void io_init()
{
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

void print_info(const char *info)
{
    // ANSI 转义序列: "\033[32m" 设置绿色前景色, "\033[0m" 重置颜色
    printf("\033[32m%s\033[0m", info);
}