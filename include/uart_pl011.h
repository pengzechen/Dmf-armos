

#ifndef __PL011_H__
#define __PL011_H__

#include <aj_types.h>

#include <os_cfg.h>

#define UART0_DR   (*(volatile uint32_t *)(UART0_BASE + 0x00)) // 数据寄存器
#define UART0_FR   (*(volatile uint32_t *)(UART0_BASE + 0x18)) // 标志寄存器
#define UART0_IBRD (*(volatile uint32_t *)(UART0_BASE + 0x24)) // 整数波特率除数寄存器
#define UART0_FBRD (*(volatile uint32_t *)(UART0_BASE + 0x28)) // 小数波特率除数寄存器
#define UART0_LCRH (*(volatile uint32_t *)(UART0_BASE + 0x2C)) // 线路控制寄存器
#define UART0_CR   (*(volatile uint32_t *)(UART0_BASE + 0x30)) // 控制寄存器
#define UART0_IMSC (*(volatile uint32_t *)(UART0_BASE + 0x38)) // 中断掩码集/清除寄存器


extern void uart_init();
extern char uart_getc();
extern void uart_putc(char);

#endif // __PL011_H__