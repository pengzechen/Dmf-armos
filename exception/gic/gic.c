

/*   ============= gic.c ================*/

#include <gic.h>
#include <aj_types.h>
#include <io.h>

struct gicv2_t _gicv2;

void gicv2_test_init()
{
    printf("    gicd enable %s\n", readl((void *)GICD_CTLR) ? "ok" : "error");
    printf("    gicc enable %s\n", readl((void *)GICC_CTLR) ? "ok" : "error");
    printf("    irq numbers: %d\n", _gicv2.irq_nr);
    printf("    cpu num: %d\n", cpu_num());
}

// gicd g0, g1  gicc enable
void gicv2_init()
{
    _gicv2.irq_nr = GICD_TYPER_IRQS(readl((void *)GICD_TYPER));
    if (_gicv2.irq_nr > 1020)
    {
        _gicv2.irq_nr = 1020;
    }

    writel(GICD_CTRL_ENABLE_GROUP0 | GICD_CTRL_ENABLE_GROUP1,
           (void *)GICD_CTLR);

    // 允许所有优先级的中断
    writel(0xff - 7, (void *)GICC_PMR);
    writel(GICC_CTRL_ENABLE, (void *)GICC_CTLR);

    gicv2_test_init();
}

// gicd g0, g1  gicc,  gich enable
void gic_virtual_init()
{
    writel(GICD_CTRL_ENABLE_GROUP0 | GICD_CTRL_ENABLE_GROUP1,
           (void *)GICD_CTLR);

    // 允许所有优先级的中断
    writel(0xff - 7, (void *)GICC_PMR);
    writel(GICC_CTRL_ENABLE, (void *)GICC_CTLR);

    writel(0x01, (void *)GICH_HCR);
    for (int i = 0; i < GIC_NR_PRIVATE_IRQS; i++)
        gic_enable_int(i, 0);
}

// get iar
uint32_t gicv2_read_iar(void)
{
    return readl((void *)GICC_IAR);
}

// iar to vector
uint32_t gicv2_iar_irqnr(uint32_t iar)
{
    return iar & GICC_IAR_INT_ID_MASK;
}

void gicv2_write_eoir(uint32_t irqstat)
{
    writel(irqstat, (void *)GICC_EOIR);
}

void gicv2_ipi_send_single(int irq, int cpu)
{
    // assert(cpu < 8);
    // assert(irq < 16);
    writel(1 << (cpu + 16) | irq, (void *)GICD_SGIR);
}

// The number of implemented CPU interfaces.
uint32_t cpu_num()
{
    return GICD_TYPER_CPU_NUM(readl((void *)GICD_TYPER));
}

// Enables the given interrupt.
void gic_enable_int(int vector, int pri)
{
    int reg = vector >> 5;                     //  vec / 32
    int mask = 1 << (vector & ((1 << 5) - 1)); //  vec % 32
    printf("set enable: reg: %d, mask: 0x%x\n", reg, mask);

    writel(mask, (void *)GICD_ISENABLER(reg));

    int n = vector >> 2;
    int m = vector & ((1 << 2) - 1);
    writel((pri << 3) | (1 << 7), (void *)(GICD_IPRIORITYR(n) + m));
}

// disables the given interrupt.
void gic_disable_int(int vector, int pri)
{
    int reg = vector >> 5;                     //  vec / 32
    int mask = 1 << (vector & ((1 << 5) - 1)); //  vec % 32
    printf("disable: reg: %d, mask: 0x%x\n", reg, mask);

    writel(mask, (void *)GICD_ICENABLER(reg));
}

// check the given interrupt.
int gic_get_enable(int vector)
{
    int reg = vector >> 5;                     //  vec / 32
    int mask = 1 << (vector & ((1 << 5) - 1)); //  vec % 32

    uint32_t val = readl((void *)GICD_ISENABLER(reg));

    printf("get enable: reg: %x, mask: %x, value: %x\n", reg, mask, val);
    return val & mask != 0;
}

void gic_set_isenabler(uint32_t n, uint32_t value)
{
    writel(value, (void*)GICD_ISENABLER(n));
}

void gic_set_ipriority(uint32_t n, uint32_t value)
{
    writel(value, (void*)GICD_IPRIORITYR(n));
}

void gic_set_icenabler(uint32_t n, uint32_t value)
{
    writel(value, (void*)GICD_ICENABLER(n));
}

uint32_t gic_make_virtual_hardware_interrupt(uint32_t vector, uint32_t pintvec, int pri, bool grp1)
{
    uint32_t mask = 0x90000000;
    mask |= ((uint32_t)(pri & 0xf8) << 20) | ((pintvec & 0x1ff) << 10) | (vector & (0x1ff)) | ((uint32_t)grp1 << 30);
    return mask;
}

uint32_t gic_make_virtual_software_interrupt(uint32_t vector, int pri, bool grp1)
{
    uint32_t mask = 0x10000000;
    mask |= ((uint32_t)(pri & 0xf8) << 20) | (vector & (0x1ff)) | ((uint32_t)grp1 << 30);
    return mask;
}

uint32_t gic_make_virtual_software_sgi(uint32_t vector, int cpu_id, int pri, bool grp1)
{
    uint32_t mask = 0x10000000;
    mask |= ((uint32_t)(pri & 0xf8) << 20) | (vector & (0x1ff)) | ((uint32_t)grp1 << 30) | ((uint32_t)cpu_id << 10);
    return mask;
}

uint32_t gic_read_lr(int n)
{
    return readl((void*)GICH_LR(n));
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
    writel(mask, (void*)GICH_LR(n));
}

void gic_set_np_int(void)
{
    writel(readl((void*)GICH_HCR) | (1 << 3), (void*)GICH_HCR);
}

void gic_clear_np_int(void)
{
    writel(readl((void*)GICH_HCR) & ~(1 << 3), (void*)GICH_HCR);
}