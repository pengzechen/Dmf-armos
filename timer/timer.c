
#include <timer.h>
#include <gic.h>
#include <aj_types.h>
#include <io.h>
#include <exception.h>
#include <thread.h>
#include <task.h>

static uint64_t test_num = 0;

#define TIMER_VECTOR 30

void handle_timer_interrupt(int)
{
    // 设置定时值
    write_cntp_tval_el0(100000);
    // if (test_num++ % 1 == 0) {
    // printf("core: %d, handle irq exception\n", get_current_cpu_id());
    // printf("get daif: %x\n", get_daif());
    schedule();

    // printf("schedule ok...\n");
    // }
}

void timer_init_second()
{
    uint64_t frq = read_cntfrq_el0();

    printf("timer frq: %d\n", frq);

    // 设置定时值
    write_cntp_tval_el0(100000);
    // 启用定时器
    write_cntp_ctl_el0(0b1);
}

// 每个pe都要配置
void timer_init()
{

    uint64_t frq = read_cntfrq_el0();

    printf("timer frq: %d\n", frq);

    // 设置定时值
    write_cntp_tval_el0(100000);
    // 启用定时器
    write_cntp_ctl_el0(0b1);

    set_enable(TIMER_VECTOR, 1);

    if (get_enable(TIMER_VECTOR))
    {
        printf("timer enabled successfully ...\n");
    }

    irq_install(TIMER_VECTOR, handle_timer_interrupt);
}
