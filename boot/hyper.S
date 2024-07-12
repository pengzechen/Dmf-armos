
#include "sys/spsr.h"

.global guest_start

test_guest:

    b .

guest_start:

  adrp    x1,:got:test_guest
  ldr     x1,[x1,:got_lo12:test_guest]
  msr elr_el2, x1

  ldr x0, =SPSR_INIT
  msr spsr_el2, x0

  mov x0, #0x0

  eret