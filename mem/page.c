
#include "aj_types.h"
#include <mmu.h>
#include <aj_string.h>

// 定义页表
static uint64_t pt0[512] __attribute__((aligned(4096))) = {-1};
static uint64_t pt1[512] __attribute__((aligned(4096))) = {-1};

static bool mmu_enable_flag = -1;

void init_page_table()
{
    memset((void*)pt0, 0, sizeof(uint64_t)*512);
    memset((void*)pt1, 0, sizeof(uint64_t)*512);

    pt0[0] = (uint64_t)(void*)pt1 + MM_TYPE_TABLE; // 512 G

    pt1[0] = (0x00000000 | PTE_DEVICE_MEMORY); // 0x0000_0000 0x4000_0000
    pt1[1] = (0x40000000 | PTE_NORMAL_MEMORY); // 0x4000_0000 0x8000_0000
}

extern void init_mmu(uint64_t);
extern void init_mmu_el2(uint64_t);

void enable_mmu()
{
    init_mmu((uint64_t)(void *)pt0);
}

void enable_mmu_el2()
{
    init_mmu_el2((uint64_t)(void *)pt0);
}