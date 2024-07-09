
#ifndef __TASK_H__
#define __TASK_H__

#include <aj_types.h>

#pragma pack(1)
typedef struct  {
    uint64_t x19;
    uint64_t x20;
    uint64_t x21;
    uint64_t x22;
    uint64_t x23;
    uint64_t x24;
    uint64_t x25;
    uint64_t x26;
    uint64_t x27;
    uint64_t x28;
    uint64_t x29; // Stack Frame Pointer
    uint64_t x30; // Link register (the address to return)
    uint64_t tpidr_el0; // "Thread ID" Register
    uint64_t sp_el1;
} context ;
#pragma pack()

#pragma pack(1)
typedef struct
{
    context ctx;
    uint32_t state; // 任务状态 (比如：就绪，运行，阻塞)
    uint32_t id;    // 任务ID
} tcb_t;
#pragma pack()

#define MAX_TASKS 64

#define wfi()       __asm__ volatile("wfi" : : : "memory");

void create_task(void (*task_func)(), void *);
void schedule_init();
void schedule();

void print_current_task();
void move_to_first_task();

#endif // __TASK_H__