
#include "sys/sys.h"

.global guest_start

test_guest:
  mov x0, 100
  mrs x0, CurrentEL          // Read current exception level
  lsr x0, x0, #2             // 右移两位
  
  //hvc #0
  b .  // el1


guest_start:

  adrp    x1,:got:test_guest
  ldr     x1,[x1,:got_lo12:test_guest]
  msr elr_el2, x1

  // 只在这个地方设置 spsr_el2 
  msr	spsr_el2, xzr
  ldr x0, =SPSR_VALUE  // EL1h | SPSR_FIQ_MASK | SPSR_IRQ_MASK | SPSR_ABT_MASK
  msr spsr_el2, x0
  isb  

  ldr x0, =0x30C50830  // arceos
  msr sctlr_el1, x0
  isb  

  mov x0, #0x0
  eret