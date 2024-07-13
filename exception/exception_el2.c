
#include <aj_types.h>
#include <io.h>
#include <exception.h>
#include <gic.h>

// 示例使用方式：处理同步异常
void handle_sync_exception_el2(uint64_t *stack_pointer)
{
    trap_frame_t *context = (trap_frame_t *)stack_pointer;

    int el2_esr = read_esr_el2();

    int ec = ((el2_esr >> 26) & 0b111111);

    printf("        el2 esr: %x\n", el2_esr);
    printf("        ec: %x\n", ec);

    if (ec == 0x16)
    { // hvc
        printf("            This is hvc call handler\n");
        return;
    }
    else if (ec == 0x17)
    { // smc
        printf("            This is smc call handler\n");
        return;
    }
    else if (ec == 0x24)
    { // data abort
        printf("            This is data abort handler\n");
        return;
    }

    for (int i = 0; i < 31; i++)
    {
        uint64_t value = context->r[i];
        printf("General-purpose register: %d, value: %x\n", i, value);
    }

    uint64_t elr_el1_value = context->elr;
    uint64_t usp_value = context->usp;
    uint64_t spsr_value = context->spsr;

    printf("usp: %x, elr: %x, spsr: %x\n", usp_value, elr_el1_value, spsr_value);

    while (1)
        ;
}

// 示例使用方式：处理 IRQ 异常
void handle_irq_exception_el2(uint64_t *stack_pointer)
{
    trap_frame_t *context = (trap_frame_t *)stack_pointer;

    uint64_t x1_value = context->r[1];
    uint64_t sp_el0_value = context->usp;

    int iar = gic_read_iar();
    int vector = gic_iar_irqnr(iar);
    gic_write_eoir(iar);

    printf("\nthis is handle irq el2\n");

    get_g_handler_vec()[vector](0); // arg not use
}

// 示例使用方式：处理无效异常
void invalid_exception_el2(uint64_t *stack_pointer, uint64_t kind, uint64_t source)
{

    trap_frame_t *context = (trap_frame_t *)stack_pointer;

    uint64_t x2_value = context->r[2];

    printf("invalid_exception_el2\n");

    int el2_esr = read_esr_el2();

    int ec = ((el2_esr >> 26) & 0b111111);

    printf("        el2 esr: %x\n", el2_esr);
    printf("        ec: %x\n", ec);

    for (int i = 0; i < 31; i++)
    {
        uint64_t value = context->r[i];
        printf("General-purpose register: %d, value: %x\n", i, value);
    }

    uint64_t elr_el1_value = context->elr;
    uint64_t usp_value = context->usp;
    uint64_t spsr_value = context->spsr;

    printf("usp: %x, elr: %x, spsr: %x\n", usp_value, elr_el1_value, spsr_value);


    while(1)
        ;
}

// 调用 handle_irq_exception_el2
void current_spxel_irq(uint64_t *stack_pointer)
{
    printf("irq stay in same el\n");
    handle_irq_exception_el2(stack_pointer);
}