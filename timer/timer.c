
#include <timer.h>
#include <gic.h>
#include <aj_types.h>
#include <io.h>

// 每个pe都要配置
void timer_init()
{

    uint64_t frq = read_cntfrq_el0();

    printf("timer frq: %d\n", frq);

    // 设置定时值
    write_cntp_tval_el0(100000);
    // 启用定时器
    write_cntp_ctl_el0(0b1);

    set_enable(30, 1);

    if (get_enable(30))
    {
        printf("timer enabled successfully ...\n");
    }
}

void handle_timer_interrupt(void)
{

    // 重新加载定时器
    // write_cntp_tval_el0(TIMER_FREQUENCY); // 1秒中断一次
}