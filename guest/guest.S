
#include "sys/sys.h"

.global guest_start
.section .text

guest_start:

	// adrp    x1,:got:test_guest
	// ldr     x1,[x1,:got_lo12:test_guest]
	// msr elr_el2, x1

	msr elr_el2, x0

	// 只在这个地方设置 spsr_el2 
	msr	spsr_el2, xzr
	ldr x0, =SPSR_VALUE  // EL1h | SPSR_FIQ_MASK | SPSR_IRQ_MASK | SPSR_ABT_MASK
	msr spsr_el2, x0
	isb  

	ldr x0, =0x30C50830  // arceos
	msr sctlr_el1, x0
	isb  

	eret


.section .data.guest_bin
	// .incbin "../guest/testos/build/kernel.bin"
	.incbin "../guest/linux/linux.bin"

.section .data.guest_dtb
  	.incbin "../guest/linux/linux.dtb"

.section .data.guest_fs
  	.incbin "../guest/linux/initrd.gz"