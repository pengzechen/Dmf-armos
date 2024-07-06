

#ifndef __GIC_H__
#define __GIC_H__

#define GIC_NR_PRIVATE_IRQS		32
#define GIC_FIRST_SPI			GIC_NR_PRIVATE_IRQS

/* Distributor registers */
#define GICD_CTLR			0x0000
#define GICD_TYPER			0x0004
#define GICD_IIDR			0x0008
#define GICD_IGROUPR			0x0080
#define GICD_ISENABLER			0x0100
#define GICD_ICENABLER			0x0180
#define GICD_ISPENDR			0x0200
#define GICD_ICPENDR			0x0280
#define GICD_ISACTIVER			0x0300
#define GICD_ICACTIVER			0x0380
#define GICD_IPRIORITYR			0x0400
#define GICD_ITARGETSR			0x0800
#define GICD_ICFGR              0x0c00
#define GICD_SGIR			    0x0f00
#define GICD_ICPIDR2			0x0fe8

#define GICD_TYPER_IRQS(typer)		((((typer) & 0x1f) + 1) * 32)
#define GICD_TYPER_CPU_NUM(typer)	    ((((typer) >> 5) & 0b111) + 1)

#define GICD_INT_EN_SET_SGI		0x0000ffff
#define GICD_INT_DEF_PRI_X4		0xa0a0a0a0


/* CPU interface registers */
#define GICC_CTLR			0x0000
#define GICC_PMR			0x0004
#define GICC_IAR			0x000c
#define GICC_EOIR			0x0010

#define GICC_INT_PRI_THRESHOLD		0xf0
#define GICC_INT_SPURIOUS		    0x3ff



#define GICD_ENABLE			0x1
#define GICC_ENABLE			0x1

#define GICC_IAR_INT_ID_MASK		0x3ff

#include <aj_types.h>

typedef struct gicv2_t {
	void *dist_base;
	void *cpu_base;
	unsigned int irq_nr;
} gicv2_t ;

typedef enum {
	EDGE = 1,
	LEVEL = 0,
} trigger_mode_t;

extern struct gicv2_t _gicv2;

#define gicv2_dist_base()		(_gicv2.dist_base)
#define gicv2_cpu_base()		(_gicv2.cpu_base)

static inline uint32_t readl(const volatile void *addr) {
    return *(const volatile uint32_t *)addr;
}

static inline void writel(uint32_t value, volatile void *addr) {
    *(volatile uint32_t *)addr = value;
}


void gicv2_init();
uint32_t gicv2_read_iar(void);
uint32_t gicv2_iar_irqnr(uint32_t iar);
void gicv2_write_eoir(uint32_t irqstat);
void gicv2_ipi_send_single(int irq, int cpu);
void set_enable(int vector, bool enable);


#endif // __GIC_H__