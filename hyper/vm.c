
#include "hyper/vgic.h"
#include "hyper_cfg.h"
#include "aj_types.h"

// qemu 准备启动4个核
// 每个核跑两个 vcpu， 共8个vcpu 
// 跑4个vm每个vm使用2个vcpu 或者 跑2个vm每个vm使用4个vcpu

vgic_t _vgic[VM_NUM_MAX];
static uint32_t _vgic_num = 0;
vgic_core_state_t _state[VCPU_NUM_MAX];
static uint32_t _state_num = 0;

