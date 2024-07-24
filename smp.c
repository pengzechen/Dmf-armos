
#include <smp.h>
#include "psci.h"
#include "os_cfg.h"
#include "io.h"
#include "thread.h"

struct thread_info threads[SMP_NUM] ;


extern void second_entry();
extern void _stack_top_second();

void start_secondary_cpus()
{
    threads[0].cpu = 0;
    threads[0].current_thread = NULL;

    for (int i = 1; i < SMP_NUM; i++)
    {
        printf("\n");
        int result = hvc_call(PSCI_0_2_FN64_CPU_ON, i, (uint64_t)(void *)second_entry,
                              (uint64_t)(_stack_top_second - 2000 * (i - 1)));
        if (result != 0)
        {
            printf("smc_call failed!\n");
        }

        threads[i].cpu = i;
        threads[i].current_thread = NULL;

        // 做一点休眠 保证第二个核 初始化完成
        for (int j = 0; j < 10; j++)
            for (int i = 0; i < 0xfffff; i++)
                ;
    }
}