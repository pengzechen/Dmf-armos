

/*   ============= gic.c ================*/

#include <gic.h>
#include <aj_types.h>
#include <io.h>

struct gicv2_t _gicv2;

void gicv2_enable_defaults(void);

void gicv2_init()
{
    _gicv2.dist_base = (void *)0x8000000;
    _gicv2.cpu_base = (void *)0x8010000;

    gicv2_enable_defaults();
}

void gicv2_enable_defaults(void)
{
    void *dist = gicv2_dist_base();
    void *cpu_base = gicv2_cpu_base();
    unsigned int i;

    _gicv2.irq_nr = GICD_TYPER_IRQS(readl(dist + GICD_TYPER));
    if (_gicv2.irq_nr > 1020)
        _gicv2.irq_nr = 1020;

    for (i = 0; i < _gicv2.irq_nr; i += 4)
        writel(GICD_INT_DEF_PRI_X4, dist + GICD_IPRIORITYR + i);

    writel(GICD_INT_EN_SET_SGI, dist + GICD_ISENABLER + 0);
    writel(GICD_ENABLE, dist + GICD_CTLR);

    writel(GICC_INT_PRI_THRESHOLD, cpu_base + GICC_PMR);
    writel(GICC_ENABLE, cpu_base + GICC_CTLR);
}

void gicv2_enable_defaults_second()
{
    void *cpu_base = gicv2_cpu_base();
    writel(GICC_INT_PRI_THRESHOLD, cpu_base + GICC_PMR);
    writel(GICC_ENABLE, cpu_base + GICC_CTLR);
}

uint32_t gicv2_read_iar(void)
{
    return readl(gicv2_cpu_base() + GICC_IAR);
}

uint32_t gicv2_iar_irqnr(uint32_t iar)
{
    return iar & GICC_IAR_INT_ID_MASK;
}

void gicv2_write_eoir(uint32_t irqstat)
{
    writel(irqstat, gicv2_cpu_base() + GICC_EOIR);
}

void gicv2_ipi_send_single(int irq, int cpu)
{
    // assert(cpu < 8);
    // assert(irq < 16);
    writel(1 << (cpu + 16) | irq, gicv2_dist_base() + GICD_SGIR);
}

// The number of implemented CPU interfaces.
uint32_t cpu_num()
{
    return GICD_TYPER_CPU_NUM(readl(gicv2_dist_base() + GICD_TYPER));
}

// Configures the trigger mode for the given interrupt.
void configure_interrupt(int vector, trigger_mode_t tg)
{
    // Only configurable for SPI interrupts
    if (vector >= _gicv2.irq_nr || vector < 32)
    {
        return;
    }

    // type is encoded with two bits, MSB of the two determine type
    // 16 irqs encoded per ICFGR register
    int reg_idx = vector >> 4;
    int bit_shift = ((vector & 0xf) << 1) + 1;
    int reg_val = readl((gicv2_dist_base() + GICD_ICFGR + reg_idx * sizeof(int)));
    if (tg == EDGE)
    {
        reg_val |= 1 << bit_shift;
    }
    else
    {
        reg_val &= !(1 << bit_shift);
    }
    writel(reg_val, (gicv2_dist_base() + GICD_ICFGR + reg_idx * sizeof(int)));
}

// Enables or disables the given interrupt.
void set_enable(int vector, bool enable)
{
    if (vector >= _gicv2.irq_nr)
    {
        return;
    }
    int reg = vector / 32;
    int mask = 1 << (vector % 32);

    void *addr = gicv2_dist_base() + GICD_ISENABLER + reg * sizeof(uint32_t);
    printf("set enable: reg: %x, mask: %x, addr: %x\n", reg, mask, addr);

    if (enable)
    {
        printf("value: %x\n", *(const volatile uint32_t *)((addr)));
        writel(mask, (addr));
        printf("value: %x\n", *(const volatile uint32_t *)((addr)));
    }
    else
    {
        writel(mask, (gicv2_dist_base() + GICD_ICENABLER + reg * sizeof(int)));
    }
}

// Enables or disables the given interrupt.
bool get_enable(int vector)
{
    int reg = vector / 32;
    int mask = 1 << (vector % 32);
    printf("set enable: reg: %x, mask: %x\n", reg, mask);
    return readl((gicv2_dist_base() + GICD_ISENABLER + reg * sizeof(int))) & mask != 0;
}