

#include <io.h>
#include <gic.h>
#include <timer.h>
#include <sys/vtcr.h>

static inline uint64_t read_sctlr_el2() {
    uint64_t value;
    asm volatile (
        "mrs %0, sctlr_el2"
        : "=r" (value)
    );
    return value;
}

static inline uint64_t read_hcr_el2() {
    uint64_t value;
    asm volatile (
        "mrs %0, hcr_el2"
        : "=r" (value)
    );
    return value;
}

static inline uint64_t read_vttbr_el2() {
    uint64_t value;
    asm volatile (
        "mrs %0, vttbr_el2"
        : "=r" (value)
    );
    return value;
}

void vtcr_init(void)
{
    uint64_t vtcr_val = VTCR_RES1|VTCR_SH0_IS|VTCR_ORGN0_WBWA|VTCR_IRGN0_WBWA;
    vtcr_val |= VTCR_T0SZ(0x18); /* 40 bit IPA */
    vtcr_val |= VTCR_SL0(0x1);   /* P2M starts at first level */
    printf("vtcr val: 0x%x\n", vtcr_val);
    write_vtcr_el2(vtcr_val);
}

static void guest_trap_init(void)
{
    unsigned long hcr;
    hcr = read_hcr_el2();
    // WRITE_SYSREG(hcr | HCR_TGE, HCR_EL2);
    // hcr = READ_SYSREG(HCR_EL2);
    printf("HCR : 0x%x\n",hcr);
    isb();
}

extern void guest_start();

void hyper_main()
{   

    io_init();
    gic_virtual_init();
    timer_init();

    printf("Hello Hyper, there's some hyper tests: \n");
    printf("scrlr_el2: 0x%x\n", read_sctlr_el2());
    printf("hcr_el2: 0x%x\n", read_hcr_el2());
    printf("read_vttbr_el2: 0x%x\n", read_vttbr_el2());

    // 准备启动 guest ... 
    vtcr_init();
    guest_trap_init();

    guest_start();
    
    while (1)
        ;
}