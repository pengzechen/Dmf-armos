#include <task.h>
#include <io.h>
#include <gic.h>
#include <hyper/vcpu.h>
#include <aj_string.h>

tcb_t task_list[MAX_TASKS];
tcb_t *current_task = (tcb_t *)0;
uint32_t task_count = 0;
static char idel_task_stack[4096] = {0};
static uint64_t idel_num = 0;
static void idel_task()
{
    while (1)
        wfi();
}

void create_task(void (*task_func)(), void *stack_top)
{
    if (task_count >= MAX_TASKS)
        return;

    tcb_t *task = &task_list[task_count];
    task->id = task_count;
    task->state = 0;
    task->ctx.x30 = (uint64_t)task_func;
    task->ctx.x29 = (uint64_t)(stack_top - 2048); // 分配一个4KB的堆栈并初始化堆栈指针
    task->ctx.sp_el1 = (uint64_t)stack_top;       // 分配一个4KB的堆栈并初始化堆栈指针
    task->counter = 20;

    task_count++;
}

void print_current_task_list()
{
    for (int i = 0; i < task_count; i++)
    {
        tcb_t *task = &task_list[i];
        printf("id: %x, sp: 0x%x, lr: 0x%x\n", task->id, task->ctx.x29, task->ctx.x30);
    }
}

// 创建一个 idel task, task0
void schedule_init()
{
    create_task(idel_task, idel_task_stack + 4096);
}

void move_to_first_task()
{
    current_task = task_list; // 当前运行的是 idel task

    void *entry = idel_task;
    __asm__ __volatile__("mov x30, %0\n"
                         "ret\n"
                         :            // out put
                         : "r"(entry) // in  put
                         : "x30");
}

extern void switch_context(tcb_t *, tcb_t *);

void _schedule()
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
        switch_context(prev_task, next_task);
    }
}

void schedule(void)
{
    current_task->counter = 0;
    _schedule();
}

void timer_tick()
{
    --current_task->counter;

    if (current_task->counter > 0)
        return;

    current_task->counter = 20;
    _schedule();
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

void vm_task_init()
{
    current_task->cpu = &vcpu;
}

void switch_context_el(tcb_t *old, tcb_t *new)
{
}
