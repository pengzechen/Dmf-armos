// https://developer.arm.com/documentation/ddi0595/2021-03/AArch64-Registers/

#ifndef __SYS_H__
#define __SYS_H__

#define SCTLR_EE	       (0 << 25)
#define SCTLR_I_CACHE_DISABLED (0 << 12)
#define SCTLR_D_CACHE_DISABLED (0 << 2)
#define SCTLR_MMU_DISABLED     (0 << 0)
#define SCTLR_MMU_ENABLED      (1 << 0)

#define SCTLR_VALUE_MMU_DISABLED                                      \
	(SCTLR_EE | SCTLR_I_CACHE_DISABLED | SCTLR_D_CACHE_DISABLED | \
	 SCTLR_MMU_DISABLED)



/*   ==============  HCR_EL2 ================ */
// https://developer.arm.com/documentation/ddi0595/2020-12/AArch64-Registers/HCR-EL2--Hypervisor-Configuration-Register?lang=en


// trap related
#define HCR_TACR (1 << 21)
#define HCR_TSC  (1 << 19)
#define HCR_TID3 (1 << 18)
#define HCR_TID2 (1 << 17)
#define HCR_TID1 (1 << 16)
#define HCR_TWE	 (1 << 14)
#define HCR_TWI	 (1 << 13)
// others
#define HCR_E2H	 (0 << 34)
#define HCR_RW	 (1 << 31)
#define HCR_TGE	 (0 << 27)
#define HCR_AMO	 (1 << 5) // routing to EL2
#define HCR_IMO	 (1 << 4) // routing to EL2
#define HCR_FMO	 (1 << 3) // routing to EL2
#define HCR_SWIO (1 << 1)
#define HCR_VM	 (1 << 0) // stage 2 translation enable

#define HCR_VALUE_NO_ROUTE                                                 \
	(HCR_TACR | HCR_TID3 | HCR_TID1 | HCR_TWE | HCR_TWI |       \
	 HCR_E2H | HCR_RW | HCR_TGE | HCR_SWIO | HCR_VM)

#define HCR_VALUE_ROUTE                                                    \
	(HCR_TACR | HCR_TSC | HCR_TWE |    \
	 HCR_E2H | HCR_RW | HCR_TGE | HCR_AMO | HCR_IMO | HCR_FMO | HCR_SWIO | HCR_VM)

#define HCR_VALUE HCR_VALUE_ROUTE
// #define HCR_VALUE HCR_VALUE_NO_ROUTE

/* =====================   SPSR_EL2 ======================= */
/*
0b0000	EL0t.
0b0100	EL1t.
0b0101	EL1h.
0b1000	EL2t.
0b1001	EL2h.
*/

#define SPSR_MASK_ALL    (7 << 6)
#define SPSR_FIQ_MASK    (1 << 6)        /* Fast Interrupt mask */
#define SPSR_IRQ_MASK    (1 << 7)        /* Interrupt mask */
#define SPSR_ABT_MASK    (1 << 8)        /* Asynchronous Abort mask */


#define SPSR_INIT SPSR_MASK_ALL    // 关闭所有中断

#define SPSR_VALUE (SPSR_MASK_ALL | 0b0101 )
#define SPSR_VALUE_IRQ (SPSR_FIQ_MASK | SPSR_ABT_MASK | 0b0101 )


#define PSM_USR (0x10)
#define PSM_FIQ (0x11)
#define PSM_IRQ (0x12)
#define PSM_SVC (0x13)
#define PSM_MON (0x16)
#define PSM_ABT (0x17)
#define PSM_HYP (0x1a)
#define PSM_UND (0x1b)
#define PSM_SYS (0x1f)



#endif // __SYS_H__