

#include "sys/sys.h"

.global task_start
.section .text

task_start:

	msr elr_el1, x0

	msr	spsr_el1, xzr
	ldr x0, =SPSR_VALUE_IRQ  
	msr spsr_el1, x0
	isb  

	eret