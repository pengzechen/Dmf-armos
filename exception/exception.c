
#include <aj_types.h>
#include <io.h>
#include <exception.h>
#include <gic.h>
#include <timer.h>

// 示例使用方式：处理同步异常
void handle_sync_exception(uint64_t *stack_pointer)
{
    trap_frame_t *context = (trap_frame_t *)stack_pointer;

    int el1_esr = read_esr_el1();

    int ec = ((el1_esr >> 26) & 0b111111);

    printf("el1 esr: %x\n", el1_esr);
    printf("ec: %x\n", ec);

    if (ec == 0x17)
    { // smc
        printf("This is smc call handler\n");
        return;
    }

    printf("This is handle_sync_exception: \n");
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

irq_handler_t g_handler_vec[512] = {0};

irq_handler_t *get_g_handler_vec()
{
    return g_handler_vec;
}

void irq_install(int vector, void (*h)(uint64_t *))
{
    g_handler_vec[vector] = h;
}

// 示例使用方式：处理 IRQ 异常
void handle_irq_exception(uint64_t *stack_pointer)
{
    trap_frame_t *context = (trap_frame_t *)stack_pointer;

    uint64_t x1_value = context->r[1];
    uint64_t sp_el0_value = context->usp;

    int iar = gic_read_iar();
    int vector = gic_iar_irqnr(iar);
    gic_write_eoir(iar);

    g_handler_vec[vector]((uint64_t *)context); // arg not use
}

// 示例使用方式：处理无效异常
void invalid_exception(uint64_t *stack_pointer, uint64_t kind, uint64_t source)
{
    trap_frame_t *context = (trap_frame_t *)stack_pointer;

    uint64_t x2_value = context->r[2];

    // 在这里实现处理无效异常的代码
}