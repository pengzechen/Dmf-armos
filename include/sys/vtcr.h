
#ifndef __VTCR_H__
#define __VTCR_H__

#define __AC(X,Y)	(X##Y)
#define _AC(X,Y)	__AC(X,Y)

#define VTCR_T0SZ(x)    ((x)<<0)

#define VTCR_SL0(x)     ((x)<<6)

#define VTCR_RES1       (_AC(1,UL)<<31)

#define VTCR_IRGN0_NC   (_AC(0x0,UL)<<8)
#define VTCR_IRGN0_WBWA (_AC(0x1,UL)<<8)
#define VTCR_IRGN0_WT   (_AC(0x2,UL)<<8)
#define VTCR_IRGN0_WB   (_AC(0x3,UL)<<8)

#define VTCR_ORGN0_NC   (_AC(0x0,UL)<<10)
#define VTCR_ORGN0_WBWA (_AC(0x1,UL)<<10)
#define VTCR_ORGN0_WT   (_AC(0x2,UL)<<10)
#define VTCR_ORGN0_WB   (_AC(0x3,UL)<<10)

#define VTCR_SH0_NS     (_AC(0x0,UL)<<12)
#define VTCR_SH0_OS     (_AC(0x2,UL)<<12)
#define VTCR_SH0_IS     (_AC(0x3,UL)<<12)

#define VTCR_TG0_4K     (_AC(0x0,UL)<<14)
#define VTCR_TG0_64K    (_AC(0x1,UL)<<14)
#define VTCR_TG0_16K    (_AC(0x2,UL)<<14)

static inline void write_vtcr_el2(uint64_t value) {
    __asm__ volatile (
        "msr vtcr_el2, %0"   // 写入VTCR_EL2寄存器
        :
        : "r" (value)        // 输入操作数
        : "memory"           // 通知编译器该指令可能会修改内存
    );
}

#endif  // __VTCR_H__