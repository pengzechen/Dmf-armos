
#include <aj_types.h>
#include <io.h>

#define NUM_REGS 31

typedef struct {
    uint64_t r[NUM_REGS];   // General-purpose registers x0..x30
    uint64_t usp;           // User Stack Pointer (SP_EL0)
    uint64_t elr;           // Exception Link Register (ELR_EL1)
    uint64_t spsr;          // Saved Process Status Register (SPSR_EL1)
} TrapFrame;

// 示例使用方式：处理同步异常
void handle_sync_exception(uint64_t *stack_pointer) {
    TrapFrame *context = (TrapFrame *)stack_pointer;

    uint64_t x0_value = context->r[0];
    uint64_t elr_el1_value = context->elr;

    // 在这里实现处理同步异常的代码
}

// 示例使用方式：处理 IRQ 异常
void handle_irq_exception(uint64_t *stack_pointer) {
    TrapFrame *context = (TrapFrame *)stack_pointer;

    uint64_t x1_value = context->r[1];
    uint64_t sp_el0_value = context->usp;

    // 在这里实现处理 IRQ 异常的代码
}

// 示例使用方式：处理无效异常
void invalid_exception(uint64_t *stack_pointer, uint64_t kind, uint64_t source) {
    TrapFrame *context = (TrapFrame *)stack_pointer;

    uint64_t x2_value = context->r[2];

    // 在这里实现处理无效异常的代码
}