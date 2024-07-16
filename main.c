
#include "aj_types.h"
#include "io.h"
#include "smp.h"
#include "psci.h"
#include "gic.h"
#include "timer.h"
#include "thread.h"
#include "task.h"
#include "spinlock.h"
#include "uart_pl011.h"

extern void second_entry();

void simple_console()
{
    while (1)
    {
        char c = uart_getc();
        uart_putc(c);
    }
}

void test_mem()
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

void task4()
{
    while (1)
    {
        for (uint64_t i = 0; i < 0xfffff; i++)
            ;
        // uart_putc('4');
        // uart_putc('\n');
        printf("task 4: get_current_cpu_id: %d\n", get_current_cpu_id());
    }
}

void task3()
{
    while (1)
    {
        for (uint64_t i = 0; i < 0xfffff; i++)
            ;
        // uart_putc('3');
        // uart_putc('\n');
        printf("task 3: get_current_cpu_id: %d\n", get_current_cpu_id());
    }
}

void task2()
{
    while (1)
    {
        for (uint64_t i = 0; i < 0xfffff; i++)
            ;
        // uart_putc('2');
        // uart_putc('\n');
        printf("task 2: get_current_cpu_id: %d\n", get_current_cpu_id());
    }
}

void task1()
{
    while (1)
    {
        for (uint64_t i = 0; i < 0xfffff; i++)
            ;
        // uart_putc('1');
        // uart_putc('\n');
        printf("task 1: get_current_cpu_id: %d\n", get_current_cpu_id());
    }
}

char task4_stack[4096] = {0};
char task3_stack[4096] = {0};
char task2_stack[4096] = {0};
char task1_stack[4096] = {0};

void main_entry()
{
    // schedule_init();
    create_task(task1, task1_stack + 3800);
    create_task(task2, task2_stack + 3800);
    create_task(task3, task3_stack + 3800);
    create_task(task4, task4_stack + 3800);
    print_current_task_list();

    enable_interrupts();
    // move_to_first_task();

    while (1)
        ;
}

void kernel_main(void)
{
    printf("===== uart  init =====\n");
    io_init();
    printf("===== gicv2 init =====\n");
    gic_init();
    printf("===== timer init =====\n");
    timer_init();
    /*
        printf("\n");
        printf("starting core 1\n");
        int result = hvc_call(PSCI_0_2_FN64_CPU_ON, 1, (uint64_t)(void *)second_entry, 0x40090000);
        if (result != 0)
        {
            printf("start core 1 failed!\n");
        }

    // 做一点休眠 保证第二个核 初始化完成
    for (int j = 0; j < 5; j++)
        for (int i = 0; i < 0xfffff; i++)
            ;
    */

    // while (1)
    //     ;

    main_entry();
    // can't reach here !
}

void second_kernel_main()
{

    gic_test_init();

    // gicv2_init();
    timer_init_second();
    // timer_init();
    // enable_interrupts();

    main_entry();
    // can't reach here !
}
