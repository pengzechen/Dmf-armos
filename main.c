
#include "aj_types.h"
#include "io.h"
#include "log.h"
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

spinlock_t print_lock;

uint64_t stack_test(uint64_t i) {
    uint64_t res = i + 1;
    return res;
}

void task8()
{
    while (1)
    {
        for (uint64_t i = 0; i < 0xf; i++)
        {
            uint64_t tmp = stack_test(i);
            
            if ( tmp != i + 1 ) 
            {
                printf("task 8 stack error: get_current_cpu_id: %d\n", get_current_cpu_id());
                // printf("\nstack error\n");
            }
        }
    }
}

void task7()
{
    while (1)
    {
        for (uint64_t i = 0; i < 0xf; i++)
        {
            uint64_t tmp = stack_test(i);
            
            if ( tmp != i + 1 ) 
            {
                printf("task 7 stack error: get_current_cpu_id: %d\n", get_current_cpu_id());
                // printf("\nstack error\n");
            }
        }
    }
}

void task6()
{
    while (1)
    {
        for (uint64_t i = 0; i < 0xf; i++)
        {
            uint64_t tmp = stack_test(i);
            
            if ( tmp != i + 1 ) 
            {
                printf("task 6 stack error: get_current_cpu_id: %d\n", get_current_cpu_id());
                // printf("\nstack error\n");
            }
        }
    }
}

void task5()
{
    while (1)
    {
        for (uint64_t i = 0; i < 0xf; i++)
        {
            uint64_t tmp = stack_test(i);
            
            if ( tmp != i + 1 ) 
            {
                printf("task 5 stack error: get_current_cpu_id: %d\n", get_current_cpu_id());
                // printf("\nstack error\n");
            }
        }
    }
}

void task4()
{
    while (1)
    {
        for (uint64_t i = 0; i < 0xf; i++)
        {
            uint64_t tmp = stack_test(i);
            
            if ( tmp != i + 1 ) 
            {
                printf("task 4 stack error: get_current_cpu_id: %d\n", get_current_cpu_id());
                // printf("\nstack error\n");
            }
        }
    }
}

void task3()
{
    while (1)
    {
        for (uint64_t i = 0; i < 0xf; i++)
        {
            uint64_t tmp = stack_test(i);
            
            if ( tmp != i + 1 ) 
            {
                printf("task 3 stack error: get_current_cpu_id: %d\n", get_current_cpu_id());
                // printf("\nstack error\n");
            }
        }
    }
}

void task2()
{
    while (1)
    {
        for (uint64_t i = 0; i < 0xf; i++)
        {
            uint64_t tmp = stack_test(i);
            
            if ( tmp != i + 1 ) 
            {
                printf("task 2 stack error: get_current_cpu_id: %d\n", get_current_cpu_id());
                // printf("\nstack error\n");
            }
        }
    }
}

void task1()
{
    while (1)
    {
        for (uint64_t i = 0; i < 0xf; i++)
        {
            uint64_t tmp = stack_test(i);
            
            if ( tmp != i + 1 ) 
            {
                printf("task 1 stack error: get_current_cpu_id: %d\n", get_current_cpu_id());
                // printf("\nstack error\n");
            }
        }
    }
}




char task8_stack[16384] = {0};
char task7_stack[16384] = {0};
char task6_stack[16384] = {0};
char task5_stack[16384] = {0};
char task4_stack[16384] = {0};
char task3_stack[16384] = {0};
char task2_stack[16384] = {0};
char task1_stack[16384] = {0};

int inited_cpu_num = 0;
spinlock_t lock;

extern void task_start(void * entry);
void main_entry()
{
    printf("main entry: get_current_cpu_id: %d\n", get_current_cpu_id());
    if (get_current_cpu_id() == 0)
    {
        schedule_init();
        create_task(task1, task1_stack + 12288);
        create_task(task2, task2_stack + 12288);
        create_task(task3, task3_stack + 12288);
        create_task(task4, task4_stack + 12288);
        create_task(task5, task5_stack + 12288);
        create_task(task6, task6_stack + 12288);
        create_task(task7, task7_stack + 12288);
        print_current_task_list();
        spinlock_init(&print_lock);
    }
    spin_lock(&lock);
    inited_cpu_num ++;
    spin_unlock(&lock);

    while(inited_cpu_num != SMP_NUM)
        wfi();

    // 让每个核都跑idel task
    schedule_init_local();
    enable_interrupts();
    
    // simple_console();
    task_start(idel_task);
}

void kernel_main(void)
{
    print_info("starting primary core 0 ...\n");
    io_early_init();
    gic_init();
    timer_init();
    print_info("core 0 starting is done.\n\n");
    spinlock_init(&lock);
    // io_init();

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
