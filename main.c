
#include "aj_types.h"
#include "io.h"
#include "smp.h"
#include "psci.h"

char * str = "start core\n";

void test_va(int x, ...) {
    va_list va;
    va_start(va, x);
    int res = va_arg(va, int);
    va_end(va);
}

extern void smc_psci_off();

void kernel_main(void) {
	uart_init();

    uart_putstr(str);

    printf("this is printf func %d\n", 1);

    uint32_t result = smc_call(PSCI_0_2_FN_CPU_OFF, 0, 0, 0);
    if (result != 0) {
        printf("stop core 1 failed!\n");
    }

    result = smc_call(PSCI_0_2_FN_CPU_ON, 3, 0x40080000, 0x40083000);
    if (result != 0) {
        printf("start core 1 failed!\n");
    }

    while(1) 
    {
        char c = uart_getc();
        uart_putc(c);
    }

    // can't reach here !
}
