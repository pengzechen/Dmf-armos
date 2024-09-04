
#include <hyper/vgic.h>
#include <hyper/hyper_cfg.h>
#include <aj_types.h>
#include <gic.h>
#include <thread.h>
#include <task.h>
#include <io.h>

// qemu 准备启动4个核
// 每个核跑两个 vcpu， 共8个vcpu
// 跑4个vm每个vm使用2个vcpu 或者 跑2个vm每个vm使用4个vcpu

static uint32_t _vgic_num = 0;
vgicc_state_t _state[VCPU_NUM_MAX];
static uint32_t _state_num = 0;

vm_sysregs_t vm_sys_reg[VM_NUM_MAX];

struct vm_t vm_list[VM_NUM_MAX];
static uint8_t _vm_index = 0;

#define HV_TIMER_VECTOR 27
#define PL011_INT 33

void v_timer_handler()
{
    // printf("v_timer_handler\n");
    vgic_inject(HV_TIMER_VECTOR);
}

void fake_console()
{
    // printf("fake console\n");
    vgic_inject(PL011_INT);
}

void interrupt_init(uint32_t index)
{
    virtual_gic_register_int(get_vgic(index), HV_TIMER_VECTOR, HV_TIMER_VECTOR);

    virtual_gic_register_int(get_vgic(index), PL011_INT, PL011_INT);

    irq_install(HV_TIMER_VECTOR, v_timer_handler);

    irq_install(PL011_INT, fake_console);
}

void vm_init(vcpu_t * vcpus[], uint32_t vcpu_num)
{
    // 设置vm中各个vcpu的指针指向创建的vcpu 
    for (uint32_t i = 0; i < vcpu_num; i++)
    {
        vm_list[_vm_index].vcpus[i] = vcpus[i];
    }
    vm_list[_vm_index].id = _vm_index;
    vm_list[_vm_index].vcpu_num = vcpu_num;
    vm_list[_vm_index].vgic = allocate_vgic(_vm_index);
    

    interrupt_init(_vm_index);

    printf("vm: %d (with: %d vcpu) init ok\n", _vm_index, vcpu_num);

    _vm_index++;
}

//  vm 相关

extern void restore_sysregs(vm_sysregs_t *);
extern void save_sysregs(vm_sysregs_t *);

void vm_in()
{
    struct thread_info *info = current_thread_info();
    tcb_t *curr = (tcb_t *)info->current_thread;
    restore_sysregs(&vm_sys_reg[curr->vm_id]);
}

void vm_out()
{
    struct thread_info *info = current_thread_info();
    tcb_t *curr = (tcb_t *)info->current_thread;
    save_sysregs(&vm_sys_reg[curr->vm_id]);
}