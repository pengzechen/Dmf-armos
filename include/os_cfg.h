

#ifndef __OS_CFG_H__
#define __OS_CFG_H__


#define UART0_BASE 0x09000000 // PL011 UART 基地址

#define GICD_BASE_ADDR 0x8000000UL    // unsigned 64 位
#define GICC_BASE_ADDR 0x8010000UL
#define GICH_BASE_ADDR 0x8040000UL

#endif // __OS_CFG_H__