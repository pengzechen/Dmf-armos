
#include <timer.h>
#include <gic.h>
#include <aj_types.h>

// 每个pe都要配置
void timer_init()
{

    uint64_t frq = read_cntfrq_el0();

    // 设置定时值
    write_cntp_tval_el0(0);
    // 启用定时器
    write_cntp_ctl_el0(0b1);

    set_enable(33, true);

    if (get_enable(33))
    {
        printf("timer enabled successfully ...\n");
    }
}

void handle_timer_interrupt(void)
{

    // 重新加载定时器
    // write_cntp_tval_el0(TIMER_FREQUENCY); // 1秒中断一次
}