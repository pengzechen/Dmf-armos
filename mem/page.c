
#include "aj_types.h"
#include <mmu.h>
#include <aj_string.h>
#include <page.h>
#include <os_cfg.h>
#include <barrier.h>

// 定义页表
static uint64_t pt0[512] __attribute__((aligned(4096)));
static uint64_t pt1[512] __attribute__((aligned(4096)));

static bool mmu_enable_flag;

size_t cacheline_bytes;

// 定义一个函数来读取 CWG 字段的值
uint32_t get_cache_line_size()
{

    uint64_t ctr_el0;
    uint32_t cwg;

    // 读取 CTR_EL0 寄存器到 ctr_el0 变量
    asm volatile("mrs %0, ctr_el0" : "=r"(ctr_el0));

    // 提取 CWG 字段的值
    cwg = (ctr_el0 >> 0) & CTR_EL0_CWG_MASK;

    return cwg;
}

void setup_cache(void)
{
    cacheline_bytes = get_cache_line_size();
}

void init_page_table()
{
    setup_cache();
    memset((void *)pt0, 0, sizeof(uint64_t) * 512);
    memset((void *)pt1, 0, sizeof(uint64_t) * 512);

    pt0[0] = (uint64_t)(void *)pt1 + MM_TYPE_TABLE; // 512 G

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