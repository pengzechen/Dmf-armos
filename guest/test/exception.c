
#include "aj_types.h"
#include "exception.h"
#include "gic.h"
#include "io.h"
#include "acfg.h"

irq_handler_t g_handler_vec[512] = {0};

void irq_install(int vector, void (*h)(uint64_t *))
{
    g_handler_vec[vector] = h;
}

void handle_sync_exception(uint64_t *stack_pointer)
{
    trap_frame_t *el1_ctx = (trap_frame_t *)stack_pointer;

    int el1_esr = read_esr_el1();

    int ec = ((el1_esr >> 26) & 0b111111);

    printf("el1 esr: %x\n", el1_esr);
    printf("ec: %x\n", ec);

    printf("This is handle_sync_exception: \n");
    for (int i = 0; i < 31; i++)
    {
        uint64_t value = el1_ctx->r[i];
        printf("General-purpose register: %d, value: %x\n", i, value);
    }

    uint64_t elr_el1_value = el1_ctx->elr;
    uint64_t usp_value = el1_ctx->usp;
    uint64_t spsr_value = el1_ctx->spsr;

    printf("usp: %x, elr: %x, spsr: %x\n", usp_value, elr_el1_value, spsr_value);

    while (1)
        ;
}

void handle_irq_exception(uint64_t *stack_pointer)
{
    trap_frame_t *el1_ctx = (trap_frame_t *)stack_pointer;

    uint64_t x1_value = el1_ctx->r[1];
    uint64_t sp_el0_value = el1_ctx->usp;

    int iar = gic_read_iar();
    int vector = gic_iar_irqnr(iar);
    gic_write_eoir(iar);

    g_handler_vec[vector]((uint64_t *)el1_ctx); // arg not use
}

void invalid_exception(uint64_t *stack_pointer, uint64_t kind, uint64_t source)
{
    trap_frame_t *el1_ctx = (trap_frame_t *)stack_pointer;

    uint64_t x2_value = el1_ctx->r[2];
}

void cntp_handler(uint64_t *)
{
    asm volatile("msr cntp_tval_el0, %0" : : "r"(100000));
    // printf("irq %d\n", TIMER);
}

void exception_init()
{
    irq_install(TIMER, cntp_handler);
}