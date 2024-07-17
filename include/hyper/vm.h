
#ifndef __VM_H__
#define __VM_H__

#include <aj_types.h>
#include "vcpu.h"
#include "vgic.h"

typedef struct _vm_t {
    uint32_t id;

    cpu_t *vcpus;
    uint32_t vcpu_num;

    vgic_t *vgic;
} vm_t ;

#endif // __VM_H__