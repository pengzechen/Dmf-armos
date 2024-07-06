#ifndef __ECCEPTION_FRAME_H__
#define __ECCEPTION_FRAME_H__

#define NUM_REGS 31

typedef struct {
    uint64_t r[NUM_REGS];   // General-purpose registers x0..x30
    uint64_t usp;           // User Stack Pointer (SP_EL0)
    uint64_t elr;           // Exception Link Register (ELR_EL3)
    uint64_t spsr;          // Saved Process Status Register (SPSR_EL3)
} TrapFrame;


#endif // __ECCEPTION_FRAME_H__