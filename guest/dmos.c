
// 单个字符输出函数
void uart_putchar(char c)
{
    volatile unsigned int *const UART0DR = (unsigned int *)0x9000000;
    *UART0DR = (unsigned int)c;
}

// 字符串输出函数
void uart_putstr(const char *str)
{
    while (*str)
    {
        uart_putchar(*str++);
    }
}

void test_mem_maped()
{
    volatile unsigned int *const MEM_ADDR = (unsigned int *)0x70000000;
    *MEM_ADDR = 0x7777;
}

void test_mem_no_maped()
{
    volatile unsigned int *const MEM_ADDR = (unsigned int *)0x80000000;
    *MEM_ADDR = 0x8888;
}

void test_mem_no_maped2()
{
    volatile unsigned int *const MEM_ADDR = (unsigned int *)0x40140000;
    *MEM_ADDR = 0x8888;
}

// main.c
void kernel_main(void)
{
    // 在这里可以添加你的内核代码
    uart_putstr("hello world\n");

    test_mem_maped();
    test_mem_no_maped();

    uart_putstr("test mem no map 2\n");
    test_mem_no_maped2();
}
