
#include <timer.h>

/*
CNTFRQ_EL0    （频率寄存器）
CNTP_CTL_EL0  （控制寄存器）
CNTP_TVAL_EL0 （定时值寄存器）
CNTPCT_EL0    （计数值寄存器）

ENABLE (bit 0): 启用定时器
0: 禁用定时器
1: 启用定时器
IMASK (bit 1): 中断屏蔽
0: 使能中断
1: 屏蔽中断
ISTATUS (bit 2): 中断状态 (只读)
0: 未触发中断
1: 已触发中断

*/

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
}

void handle_timer_interrupt(void) {


    // 重新加载定时器
    // write_cntp_tval_el0(TIMER_FREQUENCY); // 1秒中断一次

}