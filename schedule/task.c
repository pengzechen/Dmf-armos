#include <task.h>
#include <io.h>
#include <gic.h>
#include <hyper/vcpu.h>
#include <aj_string.h>
#include <sys/sys.h>
#include <spinlock.h>
#include <thread.h>
#include <hyper/vm.h>

tcb_t task_list[MAX_TASKS];

// 目前只有首核会添加一个任务，所以task_count不需要锁
uint32_t task_count = 0;

// 任务时间片
#define TASK_SLICE 20

static spinlock_t lock;
static spinlock_t print_lock;

// 分配一个任务，返回一个任务的指针
// 返回值为 NULL 表示没有分配成功
tcb_t *allocate_task()
{
    if (task_count >= MAX_TASKS)
        return NULL;

    tcb_t *task = &task_list[task_count];
    task->id = task_count;
    task->state = WAITING;
    // task->cpu = &vcpu[task_count];
    task->counter = TASK_SLICE;
    task_count++;

    return task;
}

void create_task(void (*task_func)(), void *stack_top)
{
    tcb_t *task = allocate_task();
    if (task == NULL)
    {
        print_warn("no task to allocate\n");
        return;
    }
    task->ctx.elr = (uint64_t)task_func; // elr_el1
    task->ctx.spsr = SPSR_VALUE_IRQ;     // spsr_el1
    task->ctx.usp = (uint64_t)stack_top;
}

vcpu_t *create_vcpu(void (*vcpu_entry)(), uint8_t vm_id)
{
    tcb_t *task = allocate_task();
    if (task == NULL)
    {
        print_warn("no task to allocate\n");
        return NULL;
    }
    task->ctx.elr = (uint64_t)vcpu_entry; // elr_el2
    task->ctx.spsr = SPSR_VALUE;          // spsr_el2
    task->ctx.r[0] = (0x70000000);

    vm_sys_reg[vm_id].spsr_el1 = 0x30C50830;
    task->vm_id = vm_id;

    return (vcpu_t *)task;
}

void schedule_init()
{
    spinlock_init(&lock);
    spinlock_init(&print_lock);
    // current_task = &task_list[0];
}

void schedule_init_local()
{
    spin_lock(&print_lock);
    struct thread_info *info = current_thread_info();
    info->current_thread = &task_list[info->cpu];
    printf("core %d current task %d\n", info->cpu, ((tcb_t *)info->current_thread)->id);
    task_list[info->cpu].state = RUNNING;
    spin_unlock(&print_lock);
}

void print_current_task_list()
{
    for (int i = 0; i < task_count; i++)
    {
        tcb_t *task = &task_list[i];
        // printf("id: %x, sp: 0x%x, lr: 0x%x\n", task->id, task->ctx.x29, task->ctx.x30);
        printf("id: %x, elr: 0x%x\n", task->id, task->ctx.elr);
    }
    // printf("current task id: %d\n", current_task->id);
    printf("\n");
}

extern void switch_context(tcb_t *, tcb_t *);
static void switch_context_el(tcb_t *old, tcb_t *new, uint64_t *sp);

void _schedule(uint64_t *sp)
{
    if (task_count <= 1)
        return;

    struct thread_info *info = current_thread_info();
    tcb_t *curr = (tcb_t *)info->current_thread;

    // 找到下一个就绪的任务
    // 这里多个核不能同时计算
    uint32_t next_task_id;
    spin_lock(&lock);
    next_task_id = (curr->id + 1) % task_count;
    for (int i = 2;; i++)
    {
        // 跳过非就绪状态的任务
        if (task_list[next_task_id].state == RUNNING)
            next_task_id = (curr->id + i) % task_count;
        else
        {
            task_list[curr->id].state = WAITING;
            task_list[next_task_id].state = RUNNING;
            info->current_thread = &task_list[next_task_id];
            break;
        }
    }
    spin_unlock(&lock);

    tcb_t *next_task = &task_list[next_task_id];
    tcb_t *prev_task = curr;
    // printf("core %d switch prev_task %d to next_task %d\n", current_thread_info()->cpu, prev_task->id, next_task->id);

    if (sp == NULL)
        switch_context(prev_task, next_task);
    else
        switch_context_el(prev_task, next_task, sp);
}

void schedule(void)
{
    tcb_t *curr = (tcb_t *)current_thread_info()->current_thread;
    curr->counter = 0;
    _schedule(NULL);
}

void timer_tick_schedule(uint64_t *sp)
{
    struct thread_info *info = current_thread_info();
    tcb_t *curr = (tcb_t *)info->current_thread;
    --curr->counter;

    if (curr->counter > 0)
        return;

    curr->counter = TASK_SLICE;
    _schedule(sp);
}

void save_cpu_ctx(trap_frame_t *sp)
{
    tcb_t *curr = (tcb_t *)current_thread_info()->current_thread;
    memcpy(&curr->ctx, sp, sizeof(trap_frame_t));
    curr->pctx = sp;
}

extern int get_el();
// 这个函数会直接改变 trap frame 里面的内容
void switch_context_el(tcb_t *old, tcb_t *new, uint64_t *sp)
{
    // if (get_el() == 1) {
    //     switch_context(old, new);
    //     return;
    // }
    memcpy(&old->ctx, sp, sizeof(trap_frame_t)); // 保存上下文到vpu dev 中
    memcpy(sp, &new->ctx, sizeof(trap_frame_t)); // 恢复下一个任务的cpu ctx
}
