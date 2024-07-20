

/*     目前只准备实现 vgic    */

#include <hyper/vgic.h>
#include <aj_types.h>
#include <hyper/vm.h>

// 建立 vint 和 pint 的映射关系
void virtual_gic_register_int(struct vgic_t *vgic, uint32_t pintvec, uint32_t vintvec)
{
    vgic->ptov[pintvec] = vintvec;
    vgic->vtop[vintvec] = pintvec;
    // vgic->use_irq[pintvec/32] |= 1 << (pintvec % 32);
}

void v_timer_handler()
{
    struct vgic_t * vgic = get_vgic();
    uint32_t mask = gic_make_virtual_hardware_interrupt(27, 27, 0, 0);
    // virtual_gic_set_lr(vgic, 0, mask);
    // printf("mask: 0x%x\n", mask);
    gic_write_lr(0, mask);
}