// startup.S
.section .text
.global _start

_start:

    // 读取 SCTLR 寄存器
    mrs x1, SCTLR_EL1
    // 禁用对齐检查（清除 A 位）
    bic x1, x1, #0x2
    // 写回 SCTLR 寄存器
    msr SCTLR_EL1, x1

    // 设置栈指针
    ldr x0, =_stack_top
    mov sp, x0

    // 调用 C 语言的 main 函数
    bl kernel_main

    // 死循环，防止返回
1:  b 1b

// 栈空间
.section .bss
.align 12
.global _stack_top
_stack_top:
    .skip 0x2000  // 4KB 的栈空间
