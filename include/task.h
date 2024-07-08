
#ifndef __TASK_H__
#define __TASK_H__

#include <aj_types.h>


#pragma pack(1)
typedef struct {
    uint64_t regs[12]; // 通用寄存器 x19-x30
    uint64_t sp;       // 堆栈指针
    uint64_t null;
    uint64_t lr;       // 链接寄存器 (x30)

    uint32_t state;    // 任务状态 (比如：就绪，运行，阻塞)
    uint32_t id;       // 任务ID
} tcb_t;
#pragma pack()

#define MAX_TASKS 64

void create_task(void (*task_func)(), void*);
void schedule_init();
void schedule();

void print_current_task();

#endif // __TASK_H__