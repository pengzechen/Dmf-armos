

## GICD_CTLR 0x000 是一个 32 位寄存器，其主要位定义如下：

Bit 0 (EnableGrp0):

启用或禁用组 0 中断。
0：禁用组 0 中断。
1：启用组 0 中断。
Bit 1 (EnableGrp1):

启用或禁用组 1 中断。
0：禁用组 1 中断。
1：启用组 1 中断。
Bit 2 (EnableGrp1A) (可选，依赖于实现):

在一些实现中，GIC 支持安全扩展 (Security Extensions)，此位用于启用组 1A 中断。
0：禁用组 1A 中断。
1：启用组 1A 中断。
Bits [31:3]:

保留，必须写为 0。