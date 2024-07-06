#include "mmu.h"

// startup.S
.section .text
.global _start

.extern init_page_table
.extern enable_mmu
.extern exception_vector_base

_start:

    // 设置栈指针
    ldr x0, =_stack_top_el3
    mov sp, x0


    mrs x0, CurrentEL          // Read current exception level
    lsr x0, x0, #2             // 右移两位
    
    cmp x0, #3
    b.eq from_el3_to_el1       // Branch if we are in EL3

    cmp x0, #2
    b.eq from_el2_to_el1       // Branch if we are in EL2

    b   .
/*
    -M virt,secure=on  设置secure=on后启动为el3等级
*/


// 此时CPU已经工作在EL1状态
el1_entry_point:
    // 查看当前异常等级
    mrs x0, CurrentEL          // Read current exception level
    lsr x0, x0, #2             // 右移两位

    // 设置栈指针
    ldr x0, =_stack_top
    mov sp, x0

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

/*
    mov x0, 0x6666
    mov x1, 0x2
    smc #0
    hvc #0
*/

    mov x0, #1
    mov x1, #2
    sub sp, sp, 2 * 8
    str	x0, [sp, #0]
    str	x1, [sp, #8]
    add sp, sp, 2 * 8

    // 调用 C 语言的 main 函数
    bl kernel_main

	b .




from_el2_to_el1:
    b .


from_el3_to_el1:
    // 设置 SCR_EL3 寄存器
    mrs x0, scr_el3
    orr x0, x0, #(1 << 0)     // 设置 NS 位为 1，进入非安全世界
    orr x0, x0, #(1 << 10)    // 设置 HCE 位为 1，允许 HVC 指令
    bic x0, x0, #(1 << 7)     // 清除 SMD 位，使能 SMC 指令
    msr scr_el3, x0

    // 设置 HCD 位为 1，允许 HVC 指令
    mrs x0, hcr_el2           // 读取 HCR_EL2 寄存器
    orr x0, x0, #(1 << 29)    // 设置 HCD 位 (位29) 为 1
    msr hcr_el2, x0           // 写回 HCR_EL2 寄存器

    adrp    x0, exception_vector_base_el3
    add     x0, x0, :lo12:exception_vector_base_el3
    msr     vbar_el3, x0
    dsb     sy      // 确保所有内存访问完成
    isb             // 确保所有指令都执行完成


    // 设置 SPSR_EL3 寄存器
    // 将目标处理器状态设置为 EL1h 模式
    mov x0,     #(0b0101 << 0)   // 设置 M[4:0] 为 0b0101，即 EL1h 模式
    orr x0, x0, #(0b1111 << 6)   // 设置 DAIF[3:0] 为 0b1111，禁用所有中断
    msr spsr_el3, x0

    // 设置 ELR_EL3 寄存器
    // 设置返回地址为 EL1 的入口点
    ldr x0, =el1_entry_point
    msr elr_el3, x0

    // 设置 SP_EL1 寄存器
    // 设置 EL1 的堆栈指针
    ldr x0, =_stack_top
    msr sp_el1, x0

    // 使用 ERET 指令返回到 EL1
    eret


// 栈空间
.section .bss
.align 12
.global _stack_top
_stack_bottom:
    .skip 0x2000  // 4KB 的栈空间
_stack_top:

.align 12
_stack_bottom_el3:
    .skip 0x2000  // 4KB 的栈空间
_stack_top_el3: