

#ifndef __TIMER_H__
#define  __TIMER_H__

#include <aj_types.h>

static inline uint64_t read_cntfrq_el0(void) {
    uint64_t val;
    asm volatile("mrs %0, cntfrq_el0" : "=r"(val));
    return val;
}

static inline void write_cntfrq_el0(uint64_t val) {
    asm volatile("msr cntfrq_el0, %0" : : "r"(val));
}

static inline void write_cntp_tval_el0(uint64_t val) {
    asm volatile("msr cntp_tval_el0, %0" : : "r"(val));
}

static inline void write_cntp_ctl_el0(uint64_t val) {
    asm volatile("msr cntp_ctl_el0, %0" : : "r"(val));
}

static inline uint64_t read_cntpct_el0(void) {
    uint64_t val;
    asm volatile("mrs %0, cntpct_el0" : "=r"(val));
    return val;
}


void timer_init();


#endif // __TIMER_H__