
#include <hyper/vgic.h>
#include <hyper/hyper_cfg.h>
#include <aj_types.h>

// qemu 准备启动4个核
// 每个核跑两个 vcpu， 共8个vcpu
// 跑4个vm每个vm使用2个vcpu 或者 跑2个vm每个vm使用4个vcpu

struct vgic_t _vgic[VM_NUM_MAX];
static uint32_t _vgic_num = 0;
vgic_core_state_t _state[VCPU_NUM_MAX];
static uint32_t _state_num = 0;

#define HV_TIMER_VECTOR 27

void v_timer_handler()
{
    static int flag = 0;
    // struct vgic_t *vgic = get_vgic();
    uint32_t mask = gic_make_virtual_hardware_interrupt(27, 27, 0xf0, 0);
    // 降低权限，host将收不到timer
    gic_set_ipriority(6, 0xf8000000);

    gic_write_lr(0, mask);
}

void test_cntv_handler(uint64_t *sp)
{
    // printf("this is cntv handler\n");
    v_timer_handler();
}

void vm_init()
{
    virtual_gic_register_int(&_vgic[0], 27, 27);

    irq_install(HV_TIMER_VECTOR, test_cntv_handler);
}

struct vgic_t *get_vgic()
{
    return &_vgic[0];
}