
#include "aj_types.h"
#include "io.h"

char * str = "start core\n";

void test_va(int x, ...) {
    va_list va;

    va_start(va, x);

    int res = va_arg(va, int);

    va_end(va);
}

void kernel_main(void) {
	uart_init();

    uart_putstr(str);

    test_va(0, 1, 2);

    while(1) 
    {
        char c = uart_getc();
        uart_putc(c);
    }

    // can't reach here !
}
