

#ifndef __OS_CFG_H__
#define __OS_CFG_H__

#ifndef SMP_NUM
#define SMP_NUM   1
#endif

#define UART0_BASE 0x09000000 // PL011 UART 基地址

#define GICD_BASE_ADDR 0x8000000UL    // unsigned 64 位
#define GICC_BASE_ADDR 0x8010000UL
#define GICH_BASE_ADDR 0x8040000UL

#define PAGE_SIZE  (4096)

#define RAM_START   ((unsigned long long)0x40000000)
#define RAM_END     (RAM_START + 0x40000000)

#define MMIO_ARREA  0x50000000

#endif // __OS_CFG_H__