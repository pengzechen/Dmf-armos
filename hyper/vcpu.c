
#include <io.h>
#include <hyper/vcpu.h>

cpu_t vcpu;

void print_vcpu(void)
{
  int reg;
  spin_lock(&vcpu.lock);
  for(reg = 0 ; reg < 31 ; reg++)
  {
    printf("R%d : %x\n",vcpu.ctx.r[reg]);
  }
  printf("SPSR : %x\n", vcpu.ctx.spsr);
  printf("LR : %x\n", vcpu.ctx.elr);
  spin_unlock(&vcpu.lock);
}

extern void restore_sysregs(cpu_sysregs_t *);
extern void save_sysregs(cpu_sysregs_t *);

void vm_in() {
    restore_sysregs(&vcpu.sys_reg);
}

void vm_out() {
    save_sysregs(&vcpu.sys_reg);
}