

#include <io.h>
#include <gic.h>
#include <timer.h>
#include <mmu.h>
#include <sys/vtcr.h>
#include <ept.h>
#include <page.h>
#include <task.h>

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
    print_info("    Initialize vtcr...\n");
    uint64_t vtcr_val = VTCR_VS|VTCR_PS|
                        VTCR_TG0_4K|VTCR_SH0_IS|VTCR_ORGN0_WBWA|VTCR_IRGN0_WBWA;
    
    vtcr_val |= VTCR_T0SZ(64 - 40); /* 40 bit IPA */
    vtcr_val |= VTCR_SL0(0x1);   /* P2M starts at first level */
    

    printf("vtcr val: 0x%x\n", vtcr_val);
    write_vtcr_el2(vtcr_val);
}

static void guest_trap_init(void)
{   
    print_info("    Initialize trap...\n");
    unsigned long hcr;
    hcr = read_hcr_el2();
    // WRITE_SYSREG(hcr | HCR_TGE, HCR_EL2);
    // hcr = READ_SYSREG(HCR_EL2);
    printf("HCR : 0x%x\n",hcr);
    isb();
}

extern void test_guest();
extern void test_guest2();
extern void guest_start();

extern size_t cacheline_bytes;

void hyper_main()
{   

    io_init();
    gic_virtual_init();
    timer_init();

    printf("io, gic, timer, init ok...\n\n");

    // 准备启动 guest ... 
    vtcr_init();
    guest_ept_init();
    guest_trap_init();

    printf("\nHello Hyper:\nthere's some hyper tests: \n");
    printf("scrlr_el2: 0x%x\n", read_sctlr_el2());
    printf("hcr_el2: 0x%x\n", read_hcr_el2());
    printf("read_vttbr_el2: 0x%x\n", read_vttbr_el2());
    printf("cacheline_bytes: %d\n", cacheline_bytes);
    printf("\n");

    lpae_t * avr_entry = get_ept_entry((uint64_t)MMIO_ARREA);
    avr_entry->p2m.read = 0;
    avr_entry->p2m.write = 1;
    apply_ept(avr_entry);
    *(uint64_t*)0x50000000 = 0x1234;

    craete_vm(test_guest);
    craete_vm(test_guest2);
    schedule_init();          // 设置当前 task 为 task0（test_guest）
    print_current_task_list();

    guest_start();
    
    while (1)
        ;
}