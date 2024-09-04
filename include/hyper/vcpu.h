
#ifndef __VCPU_H__
#define __VCPU_H__

#include "../spinlock.h"
#include "../aj_types.h"
#include "../exception.h"







extern void set_stage2_pgd(unsigned long, unsigned long);

void save_cpu_ctx(trap_frame_t *);

#endif // __VCPU_H__