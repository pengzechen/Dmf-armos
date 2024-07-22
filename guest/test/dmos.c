
#include "gic.h"
#include "io.h"
#include "exception.h"

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
    volatile unsigned int *const MEM_ADDR = (unsigned int *)0x50000000;
    *MEM_ADDR = 0x8888;
}

// main.c
void kernel_main(void)
{
    // 在这里可以添加你的内核代码
    printf("hello world\n");

    exception_init();

    gic_init();

    asm volatile("msr cntp_tval_el0, %0" : : "r"(100000));
    asm volatile("msr cntp_ctl_el0, %0" : : "r"(1));
    gic_enable_int(30, 0);

    enable_interrupts();
}
