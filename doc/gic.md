
gicd ctrl r

0	Enable Group 0	启用组0（安全组）的中断
1	Enable Group 1	启用组1（非安全组）的中断
2	Enable Group 1_NS	启用组1（非安全组）的非安全状态中断
31	DS	在GICv3中用于区分安全和非安全状态下的行为

gicc ctrl r

0	Enable	启用GIC CPU接口
1	FIQEn	启用FIQ（快速中断）模式
2	ACKCtl	控制中断确认机制
3	SBPR	启用安全中断的优先级分离
31	EOImodeNS	控制非安全状态的结束中断处理模式（GICv3中引入）