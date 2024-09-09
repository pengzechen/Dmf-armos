
#include <uart_pl011.h>
#include <spinlock.h>
#include <io.h>

static spinlock_t dr_lock;

void uart_early_init()
{
    // 禁用 UART
    UART0_CR = 0x0;
    spinlock_init(&dr_lock);

    // 设置波特率，例如 115200
    // 波特率计算公式：
    // 整数部分 = UARTCLK / (16 * 波特率)
    // 小数部分 = 整数部分的小数部分 * 64 + 0.5
    // 假设 UARTCLK 为 24MHz
    uint32_t uartclk = 24000000;
    uint32_t baudrate = 115200;
    uint32_t ibrd = uartclk / (16 * baudrate);
    uint32_t fbrd = (uartclk % (16 * baudrate)) * 4 / baudrate;

    UART0_IBRD = ibrd;
    UART0_FBRD = fbrd;

    // 配置线路控制寄存器: 8 bits, no parity, one stop bit
    UART0_LCRH = (1 << 5) | (1 << 6);

    // 启用 UART，TX 和 RX
    UART0_CR = (1 << 0) | (1 << 8) | (1 << 9);
}

void uart_early_putc(char c)
{
    
    // 等待发送 FIFO 不为满
    while (UART0_FR & (1 << 5))
        ;
    spin_lock(&dr_lock);
    UART0_DR = c;
    spin_unlock(&dr_lock);
}

char uart_early_getc()
{
    // 等待接收 FIFO 不为空
    while (UART0_FR & (1 << 4))
        ;
    return (char)UART0_DR;
}
