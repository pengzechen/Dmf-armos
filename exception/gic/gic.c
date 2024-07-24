

/*   ============= gic.c ================*/

#include <gic.h>
#include <aj_types.h>
#include <io.h>

struct gic_t _gicv2;

void gic_test_init(void)
{
    printf("    gicd enable %s\n", read32((void *)GICD_CTLR) ? "ok" : "error");
    printf("    gicc enable %s\n", read32((void *)GICC_CTLR) ? "ok" : "error");
    printf("    irq numbers: %d\n", _gicv2.irq_nr);
    printf("    cpu num: %d\n", cpu_num());
}

// gicd g0, g1  gicc enable
void gic_init(void)
{
    _gicv2.irq_nr = GICD_TYPER_IRQS(read32((void *)GICD_TYPER));
    if (_gicv2.irq_nr > 1020)
    {
        _gicv2.irq_nr = 1020;
    }

    write32(GICD_CTRL_ENABLE_GROUP0 | GICD_CTRL_ENABLE_GROUP1, (void *)GICD_CTLR);

    // 允许所有优先级的中断
    write32(0xff - 7, (void *)GICC_PMR);
    write32(GICC_CTRL_ENABLE, (void *)GICC_CTLR);

    gic_test_init();
}

void gicc_init()
{
    // 允许所有优先级的中断
    write32(0xff - 7, (void *)GICC_PMR);
    write32(GICC_CTRL_ENABLE, (void *)GICC_CTLR);
}

// gicd g0, g1  gicc,  gich enable
void gic_virtual_init(void)
{
    _gicv2.irq_nr = GICD_TYPER_IRQS(read32((void *)GICD_TYPER));
    if (_gicv2.irq_nr > 1020)
    {
        _gicv2.irq_nr = 1020;
    }

    write32(GICD_CTRL_ENABLE_GROUP0 | GICD_CTRL_ENABLE_GROUP1,
           (void *)GICD_CTLR);

    // 允许所有优先级的中断
    write32(0xff - 7, (void *)GICC_PMR);
    // EOImodeNS, bit [9] Controls the behavior of Non-secure accesses to GICC_EOIR GICC_AEOIR, and GICC_DIR
    write32(GICC_CTRL_ENABLE, (void *)GICC_CTLR);

    // bit [2] 当虚拟中断列表寄存器中没有条目时，会产生中断。
    write32((1 << 0), (void *)GICH_HCR);
    write32((1 << 0), (void*)GICH_VMCR);

    for (int i = 0; i < GIC_NR_PRIVATE_IRQS; i++)
        gic_enable_int(i, 0);

    gic_test_init();

    printf("    gich enable %s\n", read32((void *)GICH_HCR) ? "ok" : "error");
}

// get iar
uint32_t gic_read_iar(void)
{
    return read32((void *)GICC_IAR);
}

// iar to vector
uint32_t gic_iar_irqnr(uint32_t iar)
{
    return iar & GICC_IAR_INT_ID_MASK;
}

void gic_write_eoir(uint32_t irqstat)
{
    write32(irqstat, (void *)GICC_EOIR);
}

void gic_write_dir(uint32_t irqstat)
{
    write32(irqstat, (void *)GICC_DIR);
}


// 发送给特定的核（某个核）
void gic_ipi_send_single(int irq, int cpu)
{
    // assert(cpu < 8);
    // assert(irq < 16);
    write32(1 << (cpu + 16) | irq, (void *)GICD_SGIR);
}

// The number of implemented CPU interfaces.
uint32_t cpu_num(void)
{
    return GICD_TYPER_CPU_NUM(read32((void *)GICD_TYPER));
}

// Enables the given interrupt.
void gic_enable_int(int vector, int pri)
{
    int reg = vector >> 5;                     //  vec / 32
    int mask = 1 << (vector & ((1 << 5) - 1)); //  vec % 32
    printf("set enable: reg: %d, mask: 0x%x\n", reg, mask);

    write32(mask, (void *)GICD_ISENABLER(reg));

    int n = vector >> 2;
    int m = vector & ((1 << 2) - 1);
    write32((pri << 3) | (1 << 7), (void *)(GICD_IPRIORITYR(n) + m));
}

// disables the given interrupt.
void gic_disable_int(int vector, int pri)
{
    int reg = vector >> 5;                     //  vec / 32
    int mask = 1 << (vector & ((1 << 5) - 1)); //  vec % 32
    printf("disable: reg: %d, mask: 0x%x\n", reg, mask);

    write32(mask, (void *)GICD_ICENABLER(reg));
}

// check the given interrupt.
int gic_get_enable(int vector)
{
    int reg = vector >> 5;                     //  vec / 32
    int mask = 1 << (vector & ((1 << 5) - 1)); //  vec % 32

    uint32_t val = read32((void *)GICD_ISENABLER(reg));

    printf("get enable: reg: %x, mask: %x, value: %x\n", reg, mask, val);
    return val & mask != 0;
}

void gic_set_isenabler(uint32_t n, uint32_t value)
{
    write32(value, (void *)GICD_ISENABLER(n));
}

//  0  1  2  3 -   4  5  6  7
//  8  9 10 11 -  12 13 14 15
// 16 17 18 19 -  20 21 22 23 
// 24 25 26 27 -  28 29 30 31
void gic_set_ipriority(uint32_t n, uint32_t value)
{
    write32(value, (void *)GICD_IPRIORITYR(n));
}

void gic_set_icenabler(uint32_t n, uint32_t value)
{
    write32(value, (void *)GICD_ICENABLER(n));
}

uint32_t gic_make_virtual_hardware_interrupt(uint32_t vector, uint32_t pintvec, int pri, bool grp1)
{
    uint32_t mask = 0x90000000;  // grp0 hw pending
    mask |= ((uint32_t)(pri & 0xf8) << 20) | (vector & (0x1ff)) | ((pintvec & 0x1ff) << 10) | ((uint32_t)grp1 << 30);
    return mask;
}

uint32_t gic_make_virtual_software_interrupt(uint32_t vector, int pri, bool grp1)
{
    uint32_t mask = 0x10000000;  // grp0  pending
    mask |= ((uint32_t)(pri & 0xf8) << 20) | (vector & (0x1ff)) | ((uint32_t)grp1 << 30);
    return mask;
}

uint32_t gic_make_virtual_software_sgi(uint32_t vector, int cpu_id, int pri, bool grp1)
{
    uint32_t mask = 0x10000000;  // grp0  pending
    mask |= ((uint32_t)(pri & 0xf8) << 20) | (vector & (0x1ff)) | ((uint32_t)grp1 << 30) | ((uint32_t)cpu_id << 10);
    return mask;
}

uint32_t gic_read_lr(int n)
{
    return read32((void *)GICH_LR(n));
}

int gic_lr_read_pri(uint32_t lr_value)
{
    return (lr_value & (0xf8 << 20)) >> 20;
}

uint32_t gic_lr_read_vid(uint32_t lr_value)
{
    return lr_value & 0x1ff;
}

void gic_write_lr(int n, uint32_t mask)
{
    write32(mask, (void *)GICH_LR(n));
}

void gic_set_np_int(void)
{
    write32(read32((void *)GICH_HCR) | (1 << 3), (void *)GICH_HCR);
}

void gic_clear_np_int(void)
{
    write32(read32((void *)GICH_HCR) & ~(1 << 3), (void *)GICH_HCR);
}