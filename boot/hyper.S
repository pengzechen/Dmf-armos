
#include "sys/sys.h"

.global guest_start

test_guest:
  mov x0, 100
  b .

guest_start:

  adrp    x1,:got:test_guest
  ldr     x1,[x1,:got_lo12:test_guest]
  msr elr_el2, x1

  mrs x0, spsr_el2
  orr x0, x0, #SPSR_FIQ_MASK 
  orr x0, x0, #SPSR_IRQ_MASK
  msr spsr_el2, x0

  mov x0, #0x0

  // msr daifset, #2

  eret