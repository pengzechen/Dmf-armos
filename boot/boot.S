#include "mmu.h"

// startup.S
.section .text
.global _start

.extern init_page_table
.extern exception_vector_base

_start:

    // 设置栈指针
    ldr x0, =_stack_top
    mov sp, x0

    mrs x0, CurrentEL          // Read current exception level
    lsr x0, x0, #2             // 右移两位
    cmp x0, #2
    b.eq from_el2_to_el1       // Branch if we are in EL2
    cmp x0, #3
    b.eq from_el3_to_el1       // Branch if we are in EL3

// 此时CPU已经工作在EL1状态

    bl init_page_table
    bl enable_mmu

    // 设置栈指针
    ldr x0, =_stack_top
    mov sp, x0

    adrp    x0, exception_vector_base
    add     x0, x0, :lo12:exception_vector_base
    msr     vbar_el1, x0
    dsb     sy      // 确保所有内存访问完成
    isb             // 确保所有指令都执行完成

    // 调用 C 语言的 main 函数
    bl kernel_main

	b .

from_el3_to_el1:
    b .
from_el2_to_el1:
    b .


// 栈空间
.section .bss
.align 12
.global _stack_top
_stack_bottom:
    .skip 0x2000  // 4KB 的栈空间
_stack_top:

