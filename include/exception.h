#ifndef __ECCEPTION_H__
#define __ECCEPTION_H__

#define NUM_REGS 31

#include <aj_types.h>

typedef struct
{
    uint64_t r[NUM_REGS]; // General-purpose registers x0..x30
    uint64_t usp;         // User Stack Pointer (SP_EL0)
    uint64_t elr;         // Exception Link Register (ELR_EL3)
    uint64_t spsr;        // Saved Process Status Register (SPSR_EL3)
} trap_frame_t;

static inline uint32_t read_esr_el1(void)
{
    uint32_t esr;

    // 使用内联汇编读取 ESR_EL1 寄存器
    __asm__ volatile("mrs %0, esr_el1" : "=r"(esr));

    return esr;
}

static inline uint32_t read_esr_el3(void)
{
    uint32_t esr;

    // 使用内联汇编读取 ESR_EL1 寄存器
    __asm__ volatile("mrs %0, esr_el3" : "=r"(esr));

    return esr;
}

typedef void ( * irq_handler_t)(int) ;


void irq_install(int vector, void (*h)(int));

#endif // __ECCEPTION_FRAME_H__