
#ifndef __MMU_H__
#define __MMU_H__

#define TCR_IPS (0 << 32)
#define TCR_TG1_4K (0b10 << 30)
#define TCR_SH1_INNER (0b11 << 28)
#define TCR_ORGN1_IRGN1_WRITEBACK_WRITEALLOC ((0b01 << 26) | (0b01 << 24))
#define TCR_TG0_4K (0 << 14)
#define TCR_SH0_INNER (0b11 << 12)
#define TCR_ORGN0_IRGN0_WRITEBACK_WRITEALLOC ((0b01 << 10) | (0b01 << 8))

#define TCR_VALUE                                                        \
    (TCR_IPS |                                                           \
     TCR_TG1_4K | TCR_SH1_INNER | TCR_ORGN1_IRGN1_WRITEBACK_WRITEALLOC | \
     TCR_TG0_4K | TCR_SH0_INNER | TCR_ORGN0_IRGN0_WRITEBACK_WRITEALLOC)



/* Memory Attributes 控制这个页表项对应的内存区域的内存类型,缓存策略 */

// 设备内存 禁止聚集(non Gathering) 禁止重排(non re-order) 禁止提前的写入ACK(Early Write Acknowledgement)
#define MA_DEVICE_nGnRnE_Flags  0x0  
#define MA_MEMORY_Flags         0xFF // 普通内存 使用写回写分配 读分配 (最快的形式,各种缓存buff拉满)
#define MA_MEMORY_NoCache_Flags 0x44 // 普通内存 禁止所有缓存策略

// MAIR_ELx 可以放置8种Memory Attributes,但是我们只需要这三种就够了
#define MA_DEVICE_nGnRnE       0
#define MA_MEMORY              1
#define MA_MEMORY_NoCache      2

#define PTE_AIDX_DEVICE_nGnRn     (MA_DEVICE_nGnRnE << 2)
#define PTE_AIDX_MEMORY           (MA_MEMORY << 2)
#define PTE_AIDX_MEMORY_NOCACHE   (MA_MEMORY_NoCache << 2)

// 这个值 我们一会放到MAIR_EL1 寄存器中
#define MAIR_VALUE \
    (MA_DEVICE_nGnRnE_Flags  << (8 * MA_DEVICE_nGnRnE)) |\
    (MA_MEMORY_Flags         << (8 * MA_MEMORY)) |\
    (MA_MEMORY_NoCache_Flags << (8 * MA_MEMORY_NoCache))

// 特权读写 AF置位
#define PTE_AF_USED (1 << 10)
#define PTE_SH      (0b11 << 8) // 对于SMP系统来说,全部设置为Inner-share就可以了
#define PTE_RW      (0 << 7)

#define MM_TYPE_BLOCK  0b01
#define MM_TYPE_TABLE  0b11

// 默认页表项 带缓存的memory,inner share
#define PTE_NORMAL_MEMORY (MM_TYPE_BLOCK | PTE_AIDX_MEMORY | PTE_SH | PTE_AF_USED | PTE_RW )
// 设备内存页表项
#define PTE_DEVICE_MEMORY (MM_TYPE_BLOCK | PTE_AIDX_DEVICE_nGnRn | PTE_AF_USED)



#endif 