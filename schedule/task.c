#include <task.h>
#include <io.h>
#include <gic.h>
#include <hyper/vcpu.h>
#include <aj_string.h>
#include <sys/sys.h>
#include <spinlock.h>
#include <thread.h>

tcb_t task_list[MAX_TASKS];
tcb_t *current_task = (tcb_t *)0;

// 目前只有首核会添加一个任务，所以task_count不需要锁
uint32_t task_count = 0;

static spinlock_t lock;

void create_task(void (*task_func)(), void *stack_top)
{
    if (task_count >= MAX_TASKS)
        return;

    tcb_t *task = &task_list[task_count];
    task->id = task_count;
    task->state = 1;
    task->cpu = &vcpu[task_count];

    task->cpu->ctx.elr = (uint64_t)task_func; // elr_el1
    task->cpu->ctx.spsr = SPSR_VALUE_IRQ;     // spsr_el1
    task->cpu->ctx.usp = (uint64_t)stack_top;

    task->counter = 20;
    task_count++;
}

void craete_vm(void (*task_func)())
{
    if (task_count >= MAX_TASKS)
        return;

    tcb_t *task = &task_list[task_count];
    task->id = task_count;
    task->state = 1;
    task->cpu = &vcpu[task_count];

    task->cpu->ctx.elr = (uint64_t)task_func; // elr_el2
    task->cpu->ctx.spsr = SPSR_VALUE;         // spsr_el2
    // task->cpu->sys_reg.spsr_el1 = 0x30C50830;

    task->counter = 20;
    task_count++;
}

void schedule_init()
{
    spinlock_init(&lock);
    current_task = &task_list[0];
}

void print_current_task_list()
{
    for (int i = 0; i < task_count; i++)
    {
        tcb_t *task = &task_list[i];
        // printf("id: %x, sp: 0x%x, lr: 0x%x\n", task->id, task->ctx.x29, task->ctx.x30);
        printf("id: %x, elr: 0x%x\n", task->id, task->cpu->ctx.elr);
    }
    printf("current task id: %d\n", current_task->id);
    printf("\n");
}

extern void switch_context(tcb_t *, tcb_t *);
static void switch_context_el(tcb_t *old, tcb_t *new, uint64_t *sp);

void _schedule(uint64_t *sp)
{
    if (task_count == 0)
        return;

    // 找到下一个就绪的任务
    uint32_t next_task_id = (current_task->id + 1) % task_count;

    // while (task_list[next_task_id].state != 1)
    // { // 跳过非就绪状态的任务
    //     next_task_id = (next_task_id + 1) % task_count;
    // }

    tcb_t *next_task = &task_list[next_task_id];

    if (current_task != next_task)
    {
        tcb_t *prev_task = current_task;
        current_task = next_task;
        // printf("prev_task %d switch to next_task %d\n", prev_task->id, next_task->id);
        // enable_interrupts();
        if (sp == NULL)
            switch_context(prev_task, next_task);
        else
            switch_context_el(prev_task, next_task, sp);
    }
}

void schedule(void)
{
    current_task->counter = 0;
    _schedule(NULL);
}

void timer_tick_schedule(uint64_t *sp)
{
    --current_task->counter;

    if (current_task->counter > 0)
        return;

    current_task->counter = 20;
    // disable_interrupts();
    _schedule(sp);
    // enable_interrupts();
}

//  vm 相关

extern void restore_sysregs(cpu_sysregs_t *);
extern void save_sysregs(cpu_sysregs_t *);

void vm_in()
{
    restore_sysregs(&current_task->cpu->sys_reg);
}

void vm_out()
{
    save_sysregs(&current_task->cpu->sys_reg);
}

void save_cpu_ctx(trap_frame_t *sp)
{
    memcpy(&current_task->cpu->ctx, sp, sizeof(trap_frame_t));
    current_task->cpu->pctx = sp;
}

extern int get_el();
// 这个函数会直接改变 trap frame 里面的内容
void switch_context_el(tcb_t *old, tcb_t *new, uint64_t *sp)
{
    // if (get_el() == 1) {
    //     switch_context(old, new);
    //     return;
    // }
    memcpy(&old->cpu->ctx, sp, sizeof(trap_frame_t)); // 保存上下文到vpu dev 中
    memcpy(sp, &new->cpu->ctx, sizeof(trap_frame_t)); // 恢复下一个任务的cpu ctx
}
