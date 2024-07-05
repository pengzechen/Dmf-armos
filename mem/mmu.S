#include "mmu.h"

.global enable_mmu

/* ldr x0, =0x40084000 need change */
enable_mmu:
    // 设置 Translation Table Base Register 0 (TTBR0_EL1)
    ldr x0, =0x40086000
    msr ttbr0_el1, x0
    msr ttbr1_el1, x0
    // 设置 Translation Control Register (TCR_EL1)
    ldr x0, =(TCR_VALUE)
    msr tcr_el1, x0
    // 设置 MAIR_EL1 (Memory Attribute Indirection Register)
    ldr x0, =(MAIR_VALUE)
    msr mair_el1, x0
    

    // 设置 SCTLR_EL1 (System Control Register) 以启用MMU
    mrs x0, sctlr_el1
    orr x0, x0, #(1 << 0) // 设置 SCTLR_EL1.M 位以启用 MMU
    msr sctlr_el1, x0
    
    // 清空TLB
    dsb sy // 确保之前所有内存访问完成
    isb    // 确保所有指令都执行完成

    ret