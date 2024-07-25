
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


void simple_console()
{
    while (1)
    {
        char c = getc();
        if(c == '\r') {
            putc('\r');
            putc('\n');
        }
        putc(c);
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

int inited_cpu_num = 0;
spinlock_t lock;

void main_entry()
{
    printf("main entry: get_current_cpu_id: %d\n", get_current_cpu_id());
    if (get_current_cpu_id() == 0)
    {
        create_task(task1, task1_stack + 3800);
        create_task(task2, task2_stack + 3800);
        create_task(task3, task3_stack + 3800);
        create_task(task4, task4_stack + 3800);
        schedule_init();
        print_current_task_list();
    }
    spin_lock(&lock);
    inited_cpu_num ++;
    spin_unlock(&lock);

    while(inited_cpu_num != SMP_NUM)
        wfi();

    // if (get_current_cpu_id() == 0)
        // enable_interrupts();
    // if (get_current_cpu_id() == 1)
        // enable_interrupts();
    
    simple_console();

    while (1)
        ;
}

void kernel_main(void)
{
    print_info("starting primary core 0 ...\n");
    io_early_init();
    gic_init();
    timer_init();
    print_info("core 0 starting is done.\n\n");
    spinlock_init(&lock);
    io_init();

    start_secondary_cpus();

    main_entry();
    // can't reach here !
}

void second_kernel_main()
{
    print_info("starting core");
    printf(" %d ", get_current_cpu_id());
    print_info("...\n");

    // 第二个核要初始化 gicc
    gicc_init();
    // 输出当前 gic 初始化情况
    gic_test_init();
    // 第二个核要初始化 timer
    timer_init_second();

    print_info("core");
    printf(" %d ", get_current_cpu_id());
    print_info("starting is done.\n\n");

    main_entry();
    // can't reach here !
}
