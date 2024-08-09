

#ifndef __OS_CFG_H__
#define __OS_CFG_H__

#ifndef SMP_NUM
#define SMP_NUM   1
#endif

#define UART0_BASE 0x09000000 // PL011 UART 基地址

#define GICD_BASE_ADDR 0x8000000UL    // unsigned 64 位
#define GICC_BASE_ADDR 0x8010000UL
#define GICH_BASE_ADDR 0x8030000UL
#define GICV_BASE_ADDR 0x8040000UL

#define PAGE_SIZE  (4096)
#define STACK_SIZE  (1 << 14)   // 16 K

#define RAM_START   ((unsigned long long)0x40000000)
#define RAM_END     (RAM_START + 0x40000000)

#define MMIO_ARREA          0x50000000
#define GUEST_KERNEL_START  0x70200000UL
#define GUEST_DTB_START     0x70000000UL

#define MMIO_AREA_GICD  0x8000000UL
#define MMIO_AREA_GICC  0x8010000UL

#endif // __OS_CFG_H__