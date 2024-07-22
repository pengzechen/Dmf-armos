

/*   ============= gic.c ================*/

#include "gic.h"
#include "aj_types.h"
#include "io.h"

struct gic_t _gicv2;

void gic_test_init(void)
{
    // printf("    gicd enable %s\n", read32((void *)GICD_CTLR) ? "ok" : "error");
    // printf("    gicc enable %s\n", read32((void *)GICC_CTLR) ? "ok" : "error");
    // printf("    irq numbers: %d\n", _gicv2.irq_nr);
    // printf("    cpu num: %d\n", cpu_num());
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
    // printf("set enable: reg: %d, mask: 0x%x\n", reg, mask);

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
    // printf("disable: reg: %d, mask: 0x%x\n", reg, mask);

    write32(mask, (void *)GICD_ICENABLER(reg));
}

// check the given interrupt.
int gic_get_enable(int vector)
{
    int reg = vector >> 5;                     //  vec / 32
    int mask = 1 << (vector & ((1 << 5) - 1)); //  vec % 32

    uint32_t val = read32((void *)GICD_ISENABLER(reg));

    // printf("get enable: reg: %x, mask: %x, value: %x\n", reg, mask, val);
    return val & mask != 0;
}

void gic_set_isenabler(uint32_t n, uint32_t value)
{
    write32(value, (void *)GICD_ISENABLER(n));
}

void gic_set_ipriority(uint32_t n, uint32_t value)
{
    write32(value, (void *)GICD_IPRIORITYR(n));
}

void gic_set_icenabler(uint32_t n, uint32_t value)
{
    write32(value, (void *)GICD_ICENABLER(n));
}