
#include "aj_types.h"
#include "io.h"
#include "smp.h"
#include "psci.h"
#include "gic.h"
#include "timer.h"

static inline unsigned int get_current_cpu_id(void)
{
    unsigned long mpidr;
    asm volatile("mrs %0, mpidr_el1" : "=r"(mpidr));
    return (unsigned int)(mpidr & 0xff);
}

static inline void enable_interrupts(void) {
    asm volatile("msr daifclr, #2" : : : "memory");
}

extern void second_entry();

void simple_console()
{
    while (1)
    {
        char c = uart_getc();
        uart_putc(c);
    }
}

void main_entry()
{
    while (1)
    {
        for (uint64_t i = 0; i < 0xffffff; i++)
            ;
        printf("get_current_cpu_id: %d\n", get_current_cpu_id());
    }
}

void mem_test()
{
    uint32_t mask = 97;
    void *addr = (void *)0x9000000;
    printf("addr: 0x%x\n", addr);
    printf("before value: 0x%x\n", *(const volatile uint32_t *)((addr)));
    *(volatile uint32_t *)addr = mask;
    printf("after  value: 0x%x\n", *(const volatile uint32_t *)((addr)));

    while (1)
        ;
}

void test_types()
{
    printf("sizeof (uint32_t): %d\n", sizeof(uint32_t));
    printf("sizeof (uint64_t): %d\n", sizeof(uint64_t));
    printf("sizeof int: %d\n", sizeof(int));

    printf("sizeof char: %d\n", sizeof(char));
    printf("sizeof short: %d\n", sizeof(short));
    printf("sizeof long: %d\n", sizeof(long));

    printf("sizeof void: %d\n", sizeof(void));
    printf("sizeof void * %d\n", sizeof(void *));

    while (1)
        ;
}

void kernel_main(void)
{
    printf("===== uart  init =====\n");
    uart_init();
    printf("===== gicv2 init =====\n");
    gicv2_init();
    printf("===== timer init =====\n");
    timer_init();

    enable_interrupts();

    printf("starting core 1\n");
    int result = hvc_call(PSCI_0_2_FN64_CPU_ON, 1, (uint64_t)(void*)second_entry, 0x40086000);
    if (result != 0) {
        printf("start core 1 failed!\n");
    }

    // 做一点休眠 保证第二个核 初始化完成
    for(int i=0; i<0xfffff; i++);
    
    gicv2_ipi_send_single(0, 1);

    main_entry();
    // can't reach here !
}

void second_kernel_main()
{
    gicv2_gicc_init();
    enable_interrupts();

    main_entry();
    // can't reach here !
}