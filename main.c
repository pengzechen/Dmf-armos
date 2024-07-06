
#include "aj_types.h"
#include "io.h"
#include "smp.h"
#include "psci.h"

static inline unsigned int get_current_cpu_id(void) {
    unsigned long mpidr;
    asm volatile ("mrs %0, mpidr_el1" : "=r" (mpidr));
    return (unsigned int)(mpidr & 0xff);
}

extern void second_entry();

void simple_console() {
    while(1) 
    {
        char c = uart_getc();
        uart_putc(c);
    }
}

void main_entry() {
    while(1) {
        for(uint64_t i=0; i<0xffffff; i++);
        printf("get_current_cpu_id: %d\n", get_current_cpu_id());
    }
}

void kernel_main(void) {

	uart_init();

    uart_putstr("start core\n");

    int result = hvc_call(PSCI_0_2_FN64_CPU_ON, 1, (uint64_t)(void*)second_entry, 0x40086000);
    if (result != 0) {
        printf("start core 1 failed!\n");
    }

    main_entry();
    // can't reach here !
}

void second_kernel_main() {

    main_entry();
    // can't reach here !
}