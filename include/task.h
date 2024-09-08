
#ifndef __TASK_H__
#define __TASK_H__

#include "aj_types.h"

#include "hyper/vcpu.h"
#include "list.h"

#pragma pack(1)
typedef struct
{   
    cpu_ctx_t     ctx;     // 保存上下文
	cpu_ctx_t     *pctx;   // 指向trap的栈，可以修改restore的数据
    enum {
        RUNNING = 0,
        READY = 1,
    } state; 
    list_node_t ready_node;
    list_node_t running_node;
    
    uint32_t counter;
    uint32_t priority;
    uint32_t id;    // 任务ID
    uint32_t vm_id; // 属于哪个vm
    
} tcb_t;
#pragma pack()

typedef tcb_t vcpu_t;

#define MAX_TASKS 64
#define TASK_RUNNING 0
#define TASK_ZOMBIE  1

#define wfi()       __asm__ volatile("wfi" : : : "memory")



void schedule();
void timer_tick_schedule(uint64_t *);
void print_current_task_list();

tcb_t *create_task(void (*task_func)(), void *stack_top);
vcpu_t * create_vcpu(void (*task_func)(), uint8_t);
void schedule_init();
void schedule_init_local();
#endif // __TASK_H__