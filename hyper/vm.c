
#include <hyper/vgic.h>
#include "hyper/hyper_cfg.h"
#include "aj_types.h"

// qemu 准备启动4个核
// 每个核跑两个 vcpu， 共8个vcpu
// 跑4个vm每个vm使用2个vcpu 或者 跑2个vm每个vm使用4个vcpu

struct vgic_t _vgic[VM_NUM_MAX];
static uint32_t _vgic_num = 0;
vgic_core_state_t _state[VCPU_NUM_MAX];
static uint32_t _state_num = 0;

void vm_init()
{
    virtual_gic_register_int(&_vgic[0], 27, 27);
}

struct vgic_t *get_vgic()
{
    return &_vgic[0];
}