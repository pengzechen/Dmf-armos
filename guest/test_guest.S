

.global test_guest

.align 12
test_guest:
	mov x0, 100
	mrs x0, CurrentEL
	lsr x0, x0, #2

	mov x0, #0
	mov x1, #1
	mov x2, #2
	mov x3, #3
	mov x4, #4
	mov x5, #5
	mov x6, #0x17
	mov x7, #7
	mov x8, #8
	mov x9, #9
	mov x10, #10

	msr sctlr_el1, x0
	mrs	x3, ctr_el0

	//mov x10, #10
	//hvc #0

	ldr x0, =0x50000000
	ldr x6, [x0]
	ldr x0, =0x50000004
	ldr x6, [x0]
	ldr x0, =0x50000040
	ldr x6, [x0]
	ldr x0, =0x50000400
	ldr x6, [x0]
	ldr x0, =0x50000fff
	ldr x6, [x0]
	
	ldr x0, =0x50010000
	ldr x6, [x0]

	b .  // el1