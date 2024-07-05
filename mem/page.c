
#include "aj_types.h"
#include <mmu.h>

// 定义页表
static uint64_t pt0[512] __attribute__((aligned(4096)));
static uint64_t pt1[512] __attribute__((aligned(4096)));

void init_page_table() {
    // 清空页表
    for (int i = 0; i < 512; ++i) {
        pt0[i] = 0;
    }
    for (int i = 0; i < 512; ++i) {
        pt1[i] = 0;
    }

    pt0[0] = (uint64_t)pt1 + MM_TYPE_TABLE;    // 512 G

    pt1[0] = (0          + PTE_DEVICE_MEMORY);  // 0x0000_0000 0x4000_0000
    pt1[1] = (0x40000000 + PTE_NORMAL_MEMORY);  // 0x4000_0000 0x8000_0000
}

extern void init_mmu(uint64_t*);

void enable_mmu() {
    init_mmu((uint64_t*)(void*)pt0);
}