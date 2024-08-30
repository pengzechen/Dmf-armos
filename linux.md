rm -f build/*.o
rm -f build/*.bin
rm -f build/*.txt
rm -f build/*.elf
aarch64-linux-musl-gcc -g -c -O0 -fno-pie  -mgeneral-regs-only -fno-builtin-getc -fno-builtin-putc -fno-builtin-vsnprintf -fno-builtin-snprintf -fno-builtin-printf -DSMP_NUM=1 main.c -I ./include -I /home/ajax/rust/usb/first_state/aarch64-linux-musl-cross/aarch64-linux-musl/include -o build/main.o
aarch64-linux-musl-gcc -g -c -O0 -fno-pie  -mgeneral-regs-only -fno-builtin-getc -fno-builtin-putc -fno-builtin-vsnprintf -fno-builtin-snprintf -fno-builtin-printf -DSMP_NUM=1 smp.c -I ./include -I /home/ajax/rust/usb/first_state/aarch64-linux-musl-cross/aarch64-linux-musl/include -o build/smp.o
aarch64-linux-musl-gcc -g -c -O0 -fno-pie  -mgeneral-regs-only -fno-builtin-getc -fno-builtin-putc -fno-builtin-vsnprintf -fno-builtin-snprintf -fno-builtin-printf -DSMP_NUM=1 main_hyper.c -I ./include -I /home/ajax/rust/usb/first_state/aarch64-linux-musl-cross/aarch64-linux-musl/include -o build/main_hyper.o
aarch64-linux-musl-gcc -g -c -O0 -fno-pie  -mgeneral-regs-only -fno-builtin-getc -fno-builtin-putc -fno-builtin-vsnprintf -fno-builtin-snprintf -fno-builtin-printf -DSMP_NUM=1 boot/boot.S -I ./include -I /home/ajax/rust/usb/first_state/aarch64-linux-musl-cross/aarch64-linux-musl/include -o build/boot.s.o
aarch64-linux-musl-gcc -g -c -O0 -fno-pie  -mgeneral-regs-only -fno-builtin-getc -fno-builtin-putc -fno-builtin-vsnprintf -fno-builtin-snprintf -fno-builtin-printf -DSMP_NUM=1 hyper/hyper.S -I ./include -I /home/ajax/rust/usb/first_state/aarch64-linux-musl-cross/aarch64-linux-musl/include -o build/hyper.s.o
aarch64-linux-musl-gcc -g -c -O0 -fno-pie  -mgeneral-regs-only -fno-builtin-getc -fno-builtin-putc -fno-builtin-vsnprintf -fno-builtin-snprintf -fno-builtin-printf -DSMP_NUM=1 exception/exception.S -I ./include -I /home/ajax/rust/usb/first_state/aarch64-linux-musl-cross/aarch64-linux-musl/include -o build/exception.s.o
aarch64-linux-musl-gcc -g -c -O0 -fno-pie  -mgeneral-regs-only -fno-builtin-getc -fno-builtin-putc -fno-builtin-vsnprintf -fno-builtin-snprintf -fno-builtin-printf -DSMP_NUM=1 exception/exception.c -I ./include -I /home/ajax/rust/usb/first_state/aarch64-linux-musl-cross/aarch64-linux-musl/include -o build/exception.o
aarch64-linux-musl-gcc -g -c -O0 -fno-pie  -mgeneral-regs-only -fno-builtin-getc -fno-builtin-putc -fno-builtin-vsnprintf -fno-builtin-snprintf -fno-builtin-printf -DSMP_NUM=1 io/io.c -I ./include -I /home/ajax/rust/usb/first_state/aarch64-linux-musl-cross/aarch64-linux-musl/include -o build/io.o
aarch64-linux-musl-gcc -g -c -O0 -fno-pie  -mgeneral-regs-only -fno-builtin-getc -fno-builtin-putc -fno-builtin-vsnprintf -fno-builtin-snprintf -fno-builtin-printf -DSMP_NUM=1 io/uart_pl011.c -I ./include -I /home/ajax/rust/usb/first_state/aarch64-linux-musl-cross/aarch64-linux-musl/include -o build/uart_pl011.o  
aarch64-linux-musl-gcc -g -c -O0 -fno-pie  -mgeneral-regs-only -fno-builtin-getc -fno-builtin-putc -fno-builtin-vsnprintf -fno-builtin-snprintf -fno-builtin-printf -DSMP_NUM=1 io/uart_pl011_early.c -I ./include -I /home/ajax/rust/usb/first_state/aarch64-linux-musl-cross/aarch64-linux-musl/include -o build/uart_pl011_early.o
aarch64-linux-musl-gcc -g -c -O0 -fno-pie  -mgeneral-regs-only -fno-builtin-getc -fno-builtin-putc -fno-builtin-vsnprintf -fno-builtin-snprintf -fno-builtin-printf -DSMP_NUM=1 io/printf.c -I ./include -I /home/ajax/rust/usb/first_state/aarch64-linux-musl-cross/aarch64-linux-musl/include -o build/printf.o
aarch64-linux-musl-gcc -g -c -O0 -fno-pie  -mgeneral-regs-only -fno-builtin-getc -fno-builtin-putc -fno-builtin-vsnprintf -fno-builtin-snprintf -fno-builtin-printf -DSMP_NUM=1 mem/mmu.S -I ./include -I /home/ajax/rust/usb/first_state/aarch64-linux-musl-cross/aarch64-linux-musl/include -o build/mmu.s.o
aarch64-linux-musl-gcc -g -c -O0 -fno-pie  -mgeneral-regs-only -fno-builtin-getc -fno-builtin-putc -fno-builtin-vsnprintf -fno-builtin-snprintf -fno-builtin-printf -DSMP_NUM=1 mem/page.c -I ./include -I /home/ajax/rust/usb/first_state/aarch64-linux-musl-cross/aarch64-linux-musl/include -o build/page.o
aarch64-linux-musl-gcc -g -c -O0 -fno-pie  -mgeneral-regs-only -fno-builtin-getc -fno-builtin-putc -fno-builtin-vsnprintf -fno-builtin-snprintf -fno-builtin-printf -DSMP_NUM=1 mem/ept.c -I ./include -I /home/ajax/rust/usb/first_state/aarch64-linux-musl-cross/aarch64-linux-musl/include -o build/ept.o
aarch64-linux-musl-gcc -g -c -O0 -fno-pie  -mgeneral-regs-only -fno-builtin-getc -fno-builtin-putc -fno-builtin-vsnprintf -fno-builtin-snprintf -fno-builtin-printf -DSMP_NUM=1 mem/string.c -I ./include -I /home/ajax/rust/usb/first_state/aarch64-linux-musl-cross/aarch64-linux-musl/include -o build/string.o
aarch64-linux-musl-gcc -g -c -O0 -fno-pie  -mgeneral-regs-only -fno-builtin-getc -fno-builtin-putc -fno-builtin-vsnprintf -fno-builtin-snprintf -fno-builtin-printf -DSMP_NUM=1 exception/exception_el3.S -I ./include -I /home/ajax/rust/usb/first_state/aarch64-linux-musl-cross/aarch64-linux-musl/include -o build/exception_el3.s.o
aarch64-linux-musl-gcc -g -c -O0 -fno-pie  -mgeneral-regs-only -fno-builtin-getc -fno-builtin-putc -fno-builtin-vsnprintf -fno-builtin-snprintf -fno-builtin-printf -DSMP_NUM=1 exception/exception_el3.c -I ./include -I /home/ajax/rust/usb/first_state/aarch64-linux-musl-cross/aarch64-linux-musl/include -o build/exception_el3.o
aarch64-linux-musl-gcc -g -c -O0 -fno-pie  -mgeneral-regs-only -fno-builtin-getc -fno-builtin-putc -fno-builtin-vsnprintf -fno-builtin-snprintf -fno-builtin-printf -DSMP_NUM=1 exception/exception_el2.c -I ./include -I /home/ajax/rust/usb/first_state/aarch64-linux-musl-cross/aarch64-linux-musl/include -o build/exception_el2.o
aarch64-linux-musl-gcc -g -c -O0 -fno-pie  -mgeneral-regs-only -fno-builtin-getc -fno-builtin-putc -fno-builtin-vsnprintf -fno-builtin-snprintf -fno-builtin-printf -DSMP_NUM=1 exception/exception_el2.S -I ./include -I /home/ajax/rust/usb/first_state/aarch64-linux-musl-cross/aarch64-linux-musl/include -o build/exception_el2.s.o
aarch64-linux-musl-gcc -g -c -O0 -fno-pie  -mgeneral-regs-only -fno-builtin-getc -fno-builtin-putc -fno-builtin-vsnprintf -fno-builtin-snprintf -fno-builtin-printf -DSMP_NUM=1 exception/gic/gic.c -I ./include -I /home/ajax/rust/usb/first_state/aarch64-linux-musl-cross/aarch64-linux-musl/include -o build/gic.o
aarch64-linux-musl-gcc -g -c -O0 -fno-pie  -mgeneral-regs-only -fno-builtin-getc -fno-builtin-putc -fno-builtin-vsnprintf -fno-builtin-snprintf -fno-builtin-printf -DSMP_NUM=1 timer/timer.c -I ./include -I /home/ajax/rust/usb/first_state/aarch64-linux-musl-cross/aarch64-linux-musl/include -o build/timer.o
aarch64-linux-musl-gcc -g -c -O0 -fno-pie  -mgeneral-regs-only -fno-builtin-getc -fno-builtin-putc -fno-builtin-vsnprintf -fno-builtin-snprintf -fno-builtin-printf -DSMP_NUM=1 schedule/task.c -I ./include -I /home/ajax/rust/usb/first_state/aarch64-linux-musl-cross/aarch64-linux-musl/include -o build/task.o
aarch64-linux-musl-gcc -g -c -O0 -fno-pie  -mgeneral-regs-only -fno-builtin-getc -fno-builtin-putc -fno-builtin-vsnprintf -fno-builtin-snprintf -fno-builtin-printf -DSMP_NUM=1 schedule/context.S -I ./include -I /home/ajax/rust/usb/first_state/aarch64-linux-musl-cross/aarch64-linux-musl/include -o build/context.s.o
aarch64-linux-musl-gcc -g -c -O0 -fno-pie  -mgeneral-regs-only -fno-builtin-getc -fno-builtin-putc -fno-builtin-vsnprintf -fno-builtin-snprintf -fno-builtin-printf -DSMP_NUM=1 spinlock/spinlock.S -I ./include -I /home/ajax/rust/usb/first_state/aarch64-linux-musl-cross/aarch64-linux-musl/include -o build/spinlock.s.o
aarch64-linux-musl-gcc -g -c -O0 -fno-pie  -mgeneral-regs-only -fno-builtin-getc -fno-builtin-putc -fno-builtin-vsnprintf -fno-builtin-snprintf -fno-builtin-printf -DSMP_NUM=1 hyper/vcpu.c -I ./include -I /home/ajax/rust/usb/first_state/aarch64-linux-musl-cross/aarch64-linux-musl/include -o build/vcpu.o
aarch64-linux-musl-gcc -g -c -O0 -fno-pie  -mgeneral-regs-only -fno-builtin-getc -fno-builtin-putc -fno-builtin-vsnprintf -fno-builtin-snprintf -fno-builtin-printf -DSMP_NUM=1 hyper/hyper_ctx.S -I ./include -I /home/ajax/rust/usb/first_state/aarch64-linux-musl-cross/aarch64-linux-musl/include -o build/hyper_ctx.s.o
aarch64-linux-musl-gcc -g -c -O0 -fno-pie  -mgeneral-regs-only -fno-builtin-getc -fno-builtin-putc -fno-builtin-vsnprintf -fno-builtin-snprintf -fno-builtin-printf -DSMP_NUM=1 hyper/vgic.c -I ./include -I /home/ajax/rust/usb/first_state/aarch64-linux-musl-cross/aarch64-linux-musl/include -o build/vgic.o
aarch64-linux-musl-gcc -g -c -O0 -fno-pie  -mgeneral-regs-only -fno-builtin-getc -fno-builtin-putc -fno-builtin-vsnprintf -fno-builtin-snprintf -fno-builtin-printf -DSMP_NUM=1 hyper/vm.c -I ./include -I /home/ajax/rust/usb/first_state/aarch64-linux-musl-cross/aarch64-linux-musl/include -o build/vm.o
hyper/vm.c: In function ‘fake_console’:
hyper/vm.c:34:5: warning: implicit declaration of function ‘printf’ [-Wimplicit-function-declaration]
   34 |     printf("irq 33");
      |     ^~~~~~
hyper/vm.c:4:1: note: ‘printf’ is defined in header ‘<stdio.h>’; did you forget to ‘#include <stdio.h>’?
    3 | #include <hyper/hyper_cfg.h>
  +++ |+#include <stdio.h>
    4 | #include <aj_types.h>
aarch64-linux-musl-ld -T link.lds -o build/kernel.elf \
build/boot.s.o                  \
build/hyper.s.o          \
build/main.o                    \
build/smp.o              \
build/main_hyper.o              \
build/exception.s.o             \
build/exception_el3.s.o  \
build/exception.o               \
build/exception_el3.o   \
build/exception_el2.o    \
build/exception_el2.s.o  \
build/gic.o                             \
build/io.o                              \
build/uart_pl011.o       \
build/uart_pl011_early.o \
build/printf.o                  \
build/mmu.s.o                   \
build/page.o                    \
build/ept.o              \
build/string.o                  \
build/timer.o                   \
build/task.o                    \
build/context.s.o               \
build/spinlock.s.o       \
build/vcpu.o             \
build/vgic.o             \
build/vm.o               \
build/hyper_ctx.s.o
qemu-system-aarch64 -m 4G -smp 1 -cpu cortex-a72 -nographic  -M virt,gic_version=2 -M virtualization=on -kernel build/kernel.elf
set enable: reg: 0, mask: 0x1
set enable: reg: 0, mask: 0x2
set enable: reg: 0, mask: 0x4
set enable: reg: 0, mask: 0x8
set enable: reg: 0, mask: 0x10
set enable: reg: 0, mask: 0x20
set enable: reg: 0, mask: 0x40
set enable: reg: 0, mask: 0x80
set enable: reg: 0, mask: 0x100
set enable: reg: 0, mask: 0x200
set enable: reg: 0, mask: 0x400
set enable: reg: 0, mask: 0x800
set enable: reg: 0, mask: 0x1000
set enable: reg: 0, mask: 0x2000
set enable: reg: 0, mask: 0x4000
set enable: reg: 0, mask: 0x8000
set enable: reg: 0, mask: 0x10000
set enable: reg: 0, mask: 0x20000
set enable: reg: 0, mask: 0x40000
set enable: reg: 0, mask: 0x80000
set enable: reg: 0, mask: 0x100000
set enable: reg: 0, mask: 0x200000
set enable: reg: 0, mask: 0x400000
set enable: reg: 0, mask: 0x800000
set enable: reg: 0, mask: 0x1000000
set enable: reg: 0, mask: 0x2000000
set enable: reg: 0, mask: 0x4000000
set enable: reg: 0, mask: 0x8000000
set enable: reg: 0, mask: 0x10000000
set enable: reg: 0, mask: 0x20000000
set enable: reg: 0, mask: 0x40000000
set enable: reg: 0, mask: 0x80000000
    gicd enable ok
    gicc enable ok
    irq numbers: 288
    cpu num: 1
    gich enable ok
timer frq: 62500000
set enable: reg: 0, mask: 0x40000000
get enable: reg: 0, mask: 40000000, value: ffffffff
timer enabled successfully ...
io, gic, timer, init ok...

    Initialize vtcr...
vtcr val: 0x1355c
Initialize EPT...
EPT root address : 0x4265c000
ept_L2_root : 0x4265d000
ept_L3_root : 0x42665000
LPAE_L1_SIZE : 8
LPAE_L2_SIZE : 4096
LPAE_L3_SIZE : 2097152
    Initialize trap...
HCR : 0x8028403b
Copy guest dtb from 42567800 to 70000000 (7651 bytes): 0xedfe0dd0 / 0x38000000
Copy end : 0xedfe0dd0 / 0x38000000
Copy guest kernel image from 4008a400 to 70200000 (38654464 bytes): 0xfa405a4d / 0x0
Copy end : 0xfa405a4d / 0x0
Copy guest fs from 42569800 to 78000000 (736355 bytes): 0x88b1f / 0x9cbc0302
Copy end : 0x88b1f / 0x9cbc0302

Hello Hyper:
there's some hyper tests: 
scrlr_el2: 0x1
hcr_el2: 0x8028403b
read_vttbr_el2: 0x4265c000
cacheline_bytes: 4

core 0 current task 0
id: 0, elr: 0x40080178
id: 1, elr: 0x70200000

        el2 esr: 5e000000, ec: 17
            This is smc call handler
        el2 esr: 5e000000, ec: 17
            This is smc call handler
        el2 esr: 5e000000, ec: 17
            This is smc call handler
        el2 esr: 5e000000, ec: 17
            This is smc call handler
        el2 esr: 5e000000, ec: 17
            This is smc call handler
        el2 esr: 5e000000, ec: 17
            This is smc call handler
        el2 esr: 5e000000, ec: 17
            This is smc call handler
        el2 esr: 5e000000, ec: 17
            This is smc call handler
        el2 esr: 5e000000, ec: 17
            This is smc call handler
        el2 esr: 5e000000, ec: 17
            This is smc call handler
        el2 esr: 9382000f, ec: 24
      >>> gicd emu read GICD_TYPER
        el2 esr: 939f004f, ec: 24
      <<< gicd emu write GICD_CTLR
        el2 esr: 9380000f, ec: 24
        el2 esr: 9384004f, ec: 24
      <<< gicd emu write GICD_ITARGETSR(i)
        el2 esr: 9384004f, ec: 24
      <<< gicd emu write GICD_ITARGETSR(i)
        el2 esr: 9384004f, ec: 24
      <<< gicd emu write GICD_ITARGETSR(i)
        el2 esr: 9384004f, ec: 24
      <<< gicd emu write GICD_ITARGETSR(i)
        el2 esr: 9384004f, ec: 24
      <<< gicd emu write GICD_ITARGETSR(i)
        el2 esr: 9384004f, ec: 24
      <<< gicd emu write GICD_ITARGETSR(i)
        el2 esr: 9384004f, ec: 24
      <<< gicd emu write GICD_ITARGETSR(i)
        el2 esr: 9384004f, ec: 24
      <<< gicd emu write GICD_ITARGETSR(i)
        el2 esr: 9384004f, ec: 24
      <<< gicd emu write GICD_ITARGETSR(i)
        el2 esr: 9384004f, ec: 24
      <<< gicd emu write GICD_ITARGETSR(i)
        el2 esr: 9384004f, ec: 24
      <<< gicd emu write GICD_ITARGETSR(i)
        el2 esr: 9384004f, ec: 24
      <<< gicd emu write GICD_ITARGETSR(i)
        el2 esr: 9384004f, ec: 24
      <<< gicd emu write GICD_ITARGETSR(i)
        el2 esr: 9384004f, ec: 24
      <<< gicd emu write GICD_ITARGETSR(i)
        el2 esr: 9384004f, ec: 24
      <<< gicd emu write GICD_ITARGETSR(i)
        el2 esr: 9384004f, ec: 24
      <<< gicd emu write GICD_ITARGETSR(i)
        el2 esr: 9384004f, ec: 24
      <<< gicd emu write GICD_ITARGETSR(i)
        el2 esr: 9384004f, ec: 24
      <<< gicd emu write GICD_ITARGETSR(i)
        el2 esr: 9384004f, ec: 24
      <<< gicd emu write GICD_ITARGETSR(i)
        el2 esr: 9384004f, ec: 24
      <<< gicd emu write GICD_ITARGETSR(i)
        el2 esr: 9384004f, ec: 24
      <<< gicd emu write GICD_ITARGETSR(i)
        el2 esr: 9384004f, ec: 24
      <<< gicd emu write GICD_ITARGETSR(i)
        el2 esr: 9384004f, ec: 24
      <<< gicd emu write GICD_ITARGETSR(i)
        el2 esr: 9384004f, ec: 24
      <<< gicd emu write GICD_ITARGETSR(i)
        el2 esr: 9384004f, ec: 24
      <<< gicd emu write GICD_ITARGETSR(i)
        el2 esr: 9384004f, ec: 24
      <<< gicd emu write GICD_ITARGETSR(i)
        el2 esr: 9384004f, ec: 24
      <<< gicd emu write GICD_ITARGETSR(i)
        el2 esr: 9384004f, ec: 24
      <<< gicd emu write GICD_ITARGETSR(i)
        el2 esr: 9384004f, ec: 24
      <<< gicd emu write GICD_ITARGETSR(i)
        el2 esr: 9384004f, ec: 24
      <<< gicd emu write GICD_ITARGETSR(i)
        el2 esr: 9384004f, ec: 24
      <<< gicd emu write GICD_ITARGETSR(i)
        el2 esr: 9384004f, ec: 24
      <<< gicd emu write GICD_ITARGETSR(i)
        el2 esr: 939f004f, ec: 24
      <<< gicd emu write GICD_ICFGR(i)
        el2 esr: 939f004f, ec: 24
      <<< gicd emu write GICD_ICFGR(i)
        el2 esr: 939f004f, ec: 24
      <<< gicd emu write GICD_ICFGR(i)
        el2 esr: 939f004f, ec: 24
      <<< gicd emu write GICD_ICFGR(i)
        el2 esr: 939f004f, ec: 24
      <<< gicd emu write GICD_ICFGR(i)
        el2 esr: 939f004f, ec: 24
      <<< gicd emu write GICD_ICFGR(i)
        el2 esr: 939f004f, ec: 24
      <<< gicd emu write GICD_ICFGR(i)
        el2 esr: 939f004f, ec: 24
      <<< gicd emu write GICD_ICFGR(i)
        el2 esr: 9385004f, ec: 24
      <<< gicd emu write GICD_IPRIORITYR(spi)
        el2 esr: 9385004f, ec: 24
      <<< gicd emu write GICD_IPRIORITYR(spi)
        el2 esr: 9385004f, ec: 24
      <<< gicd emu write GICD_IPRIORITYR(spi)
        el2 esr: 9385004f, ec: 24
      <<< gicd emu write GICD_IPRIORITYR(spi)
        el2 esr: 9385004f, ec: 24
      <<< gicd emu write GICD_IPRIORITYR(spi)
        el2 esr: 9385004f, ec: 24
      <<< gicd emu write GICD_IPRIORITYR(spi)
        el2 esr: 9385004f, ec: 24
      <<< gicd emu write GICD_IPRIORITYR(spi)
        el2 esr: 9385004f, ec: 24
      <<< gicd emu write GICD_IPRIORITYR(spi)
        el2 esr: 9385004f, ec: 24
      <<< gicd emu write GICD_IPRIORITYR(spi)
        el2 esr: 9385004f, ec: 24
      <<< gicd emu write GICD_IPRIORITYR(spi)
        el2 esr: 9385004f, ec: 24
      <<< gicd emu write GICD_IPRIORITYR(spi)
        el2 esr: 9385004f, ec: 24
      <<< gicd emu write GICD_IPRIORITYR(spi)
        el2 esr: 9385004f, ec: 24
      <<< gicd emu write GICD_IPRIORITYR(spi)
        el2 esr: 9385004f, ec: 24
      <<< gicd emu write GICD_IPRIORITYR(spi)
        el2 esr: 9385004f, ec: 24
      <<< gicd emu write GICD_IPRIORITYR(spi)
        el2 esr: 9385004f, ec: 24
      <<< gicd emu write GICD_IPRIORITYR(spi)
        el2 esr: 9385004f, ec: 24
      <<< gicd emu write GICD_IPRIORITYR(spi)
        el2 esr: 9385004f, ec: 24
      <<< gicd emu write GICD_IPRIORITYR(spi)
        el2 esr: 9385004f, ec: 24
      <<< gicd emu write GICD_IPRIORITYR(spi)
        el2 esr: 9385004f, ec: 24
      <<< gicd emu write GICD_IPRIORITYR(spi)
        el2 esr: 9385004f, ec: 24
      <<< gicd emu write GICD_IPRIORITYR(spi)
        el2 esr: 9385004f, ec: 24
      <<< gicd emu write GICD_IPRIORITYR(spi)
        el2 esr: 9385004f, ec: 24
      <<< gicd emu write GICD_IPRIORITYR(spi)
        el2 esr: 9385004f, ec: 24
      <<< gicd emu write GICD_IPRIORITYR(spi)
        el2 esr: 9385004f, ec: 24
      <<< gicd emu write GICD_IPRIORITYR(spi)
        el2 esr: 9385004f, ec: 24
      <<< gicd emu write GICD_IPRIORITYR(spi)
        el2 esr: 9385004f, ec: 24
      <<< gicd emu write GICD_IPRIORITYR(spi)
        el2 esr: 9385004f, ec: 24
      <<< gicd emu write GICD_IPRIORITYR(spi)
        el2 esr: 9385004f, ec: 24
      <<< gicd emu write GICD_IPRIORITYR(spi)
        el2 esr: 9385004f, ec: 24
      <<< gicd emu write GICD_IPRIORITYR(spi)
        el2 esr: 9385004f, ec: 24
      <<< gicd emu write GICD_IPRIORITYR(spi)
        el2 esr: 9385004f, ec: 24
      <<< gicd emu write GICD_IPRIORITYR(spi)
        el2 esr: 9386004f, ec: 24
      <<< gicd emu write GICD_ICPENDER(i)
        el2 esr: 9386004f, ec: 24
      <<< gicd emu write GICD_ICENABLER(i)
        el2 esr: 9386004f, ec: 24
      <<< gicd emu write GICD_ICPENDER(i)
        el2 esr: 9386004f, ec: 24
      <<< gicd emu write GICD_ICENABLER(i)
        el2 esr: 9386004f, ec: 24
      <<< gicd emu write GICD_ICPENDER(i)
        el2 esr: 9386004f, ec: 24
      <<< gicd emu write GICD_ICENABLER(i)
        el2 esr: 9386004f, ec: 24
      <<< gicd emu write GICD_ICPENDER(i)
        el2 esr: 9386004f, ec: 24
      <<< gicd emu write GICD_ICENABLER(i)
        el2 esr: 9380004f, ec: 24
      <<< gicd emu write GICD_CTLR
        el2 esr: 9380000f, ec: 24
        el2 esr: 9386004f, ec: 24
      <<< gicd emu write GICD_ICPENDER(i)
        el2 esr: 9386004f, ec: 24
      <<< gicd emu write GICD_ICENABLER(0)
        el2 esr: 9386004f, ec: 24
      <<< gicd emu write GICD_IPRIORITYR(sgi-ppi)
        el2 esr: 9386004f, ec: 24
      <<< gicd emu write GICD_IPRIORITYR(sgi-ppi)
        el2 esr: 9386004f, ec: 24
      <<< gicd emu write GICD_IPRIORITYR(sgi-ppi)
        el2 esr: 9386004f, ec: 24
      <<< gicd emu write GICD_IPRIORITYR(sgi-ppi)
        el2 esr: 9386004f, ec: 24
      <<< gicd emu write GICD_IPRIORITYR(sgi-ppi)
        el2 esr: 9386004f, ec: 24
      <<< gicd emu write GICD_IPRIORITYR(sgi-ppi)
        el2 esr: 9386004f, ec: 24
      <<< gicd emu write GICD_IPRIORITYR(sgi-ppi)
        el2 esr: 9386004f, ec: 24
      <<< gicd emu write GICD_IPRIORITYR(sgi-ppi)
        el2 esr: 9381004f, ec: 24
gpa: 8000100, r: 1, len: 4, int id: 0
set enable: reg: 0, mask: 0x1
      <<< gicd emu write GICD_ISENABLER(0)
        el2 esr: 9381004f, ec: 24
gpa: 8000100, r: 2, len: 4, int id: 1
set enable: reg: 0, mask: 0x2
      <<< gicd emu write GICD_ISENABLER(0)
        el2 esr: 9381004f, ec: 24
gpa: 8000100, r: 4, len: 4, int id: 2
set enable: reg: 0, mask: 0x4
      <<< gicd emu write GICD_ISENABLER(0)
        el2 esr: 9381004f, ec: 24
gpa: 8000100, r: 8, len: 4, int id: 3
set enable: reg: 0, mask: 0x8
      <<< gicd emu write GICD_ISENABLER(0)
        el2 esr: 9381004f, ec: 24
gpa: 8000100, r: 10, len: 4, int id: 4
set enable: reg: 0, mask: 0x10
      <<< gicd emu write GICD_ISENABLER(0)
        el2 esr: 9381004f, ec: 24
gpa: 8000100, r: 20, len: 4, int id: 5
set enable: reg: 0, mask: 0x20
      <<< gicd emu write GICD_ISENABLER(0)
        el2 esr: 9381004f, ec: 24
gpa: 8000100, r: 40, len: 4, int id: 6
set enable: reg: 0, mask: 0x40
      <<< gicd emu write GICD_ISENABLER(0)
        el2 esr: 9380000f, ec: 24
        el2 esr: 9380000f, ec: 24
        el2 esr: 9381004f, ec: 24
gpa: 8000100, r: 8000000, len: 4, int id: 27
set enable: reg: 0, mask: 0x8000000
      <<< gicd emu write GICD_ISENABLER(0)
        el2 esr: 5e000000, ec: 17
            This is smc call handler
        el2 esr: 5e000000, ec: 17
            This is smc call handler
        el2 esr: 5e000000, ec: 17
            This is smc call handler
[    0.000000] Booting Linux on physical CPU 0x0000000000 [0x410fd083]
[    0.000000] Linux version 6.2.15 (ajax@ajax-X99) (aarch64-linux-musl-gcc (GCC) 11.2.1 20211120, GNU ld (GNU Binutils) 2.37) #6 SMP PREEMPT Fri Aug 30 22:06:21 CST 2024
[    0.000000] random: crng init done
[    0.000000] Machine model: linux,dummy-virt
[    0.000000] efi: UEFI not found.
[    0.000000] NUMA: No NUMA configuration found
[    0.000000] NUMA: Faking a node at [mem 0x0000000070000000-0x000000007bffffff]
[    0.000000] NUMA: NODE_DATA [mem 0x7bfe3a00-0x7bfe5fff]
[    0.000000] Zone ranges:
[    0.000000]   DMA      [mem 0x0000000070000000-0x000000007bffffff]
[    0.000000]   DMA32    empty
[    0.000000]   Normal   empty
[    0.000000] Movable zone start for each node
[    0.000000] Early memory node ranges
[    0.000000]   node   0: [mem 0x0000000070000000-0x000000007bffffff]
[    0.000000] Initmem setup node 0 [mem 0x0000000070000000-0x000000007bffffff]
[    0.000000] On node 0, zone DMA: 16384 pages in unavailable ranges
[    0.000000] cma: Reserved 32 MiB at 0x0000000079a00000
[    0.000000] psci: probing for conduit method from DT.
[    0.000000] psci: PSCIv33792.0 detected in firmware.
[    0.000000] psci: Using standard PSCI v0.2 function IDs
[    0.000000] psci: MIGRATE_INFO_TYPE returned unknown type (-2080374778)
[    0.000000] psci: SMC Calling Convention v32768.0
[    0.000000] percpu: Embedded 21 pages/cpu s45672 r8192 d32152 u86016
[    0.000000] Detected PIPT I-cache on CPU0
[    0.000000] CPU features: detected: Spectre-v2
[    0.000000] CPU features: detected: Spectre-v4
[    0.000000] CPU features: detected: Spectre-BHB
[    0.000000] CPU features: detected: ARM erratum 1742098
[    0.000000] CPU features: detected: ARM errata 1165522, 1319367, or 1530923
[    0.000000] alternatives: applying boot alternatives
[    0.000000] Fallback order for Node 0: 0 
[    0.000000] Built 1 zonelists, mobility grouping on.  Total pages: 48384
[    0.000000] Policy zone: DMA
[    0.000000] Kernel command line: root=/dev/vda rootfstype=ext4 rw console=ttyAMA0 rodata=off
[    0.000000] Dentry cache hash table entries: 32768 (order: 6, 262144 bytes, linear)
[    0.000000] Inode-cache hash table entries: 16384 (order: 5, 131072 bytes, linear)
[    0.000000] mem auto-init: stack:off, heap alloc:off, heap free:off
[    0.000000] Memory: 113360K/196608K available (16256K kernel code, 3892K rwdata, 9532K rodata, 7936K init, 608K bss, 50480K reserved, 32768K cma-reserved)
[    0.000000] SLUB: HWalign=64, Order=0-3, MinObjects=0, CPUs=1, Nodes=1
[    0.000000] rcu: Preemptible hierarchical RCU implementation.
[    0.000000] rcu:     RCU event tracing is enabled.
[    0.000000] rcu:     RCU restricting CPUs from NR_CPUS=256 to nr_cpu_ids=1.
[    0.000000]  Trampoline variant of Tasks RCU enabled.
[    0.000000]  Tracing variant of Tasks RCU enabled.
[    0.000000] rcu: RCU calculated value of scheduler-enlistment delay is 25 jiffies.
[    0.000000] rcu: Adjusting geometry for rcu_fanout_leaf=16, nr_cpu_ids=1
[    0.000000] NR_IRQS: 64, nr_irqs: 64, preallocated irqs: 0
[    0.000000] Root IRQ handler: gic_handle_irq
[    0.000000] GICv2m: range[mem 0x08020000-0x08020fff], SPI[80:143]
[    0.000000] rcu: srcu_init: Setting srcu_struct sizes based on contention.
[    0.000000] arch_timer: cp15 timer(s) running at 62.50MHz (virt).
[    0.000000] clocksource: arch_sys_counter: mask: 0x1ffffffffffffff max_cycles: 0x1cd42e208c, max_idle_ns: 881590405314 ns
[    0.000095] sched_clock: 57 bits at 63MHz, resolution 16ns, wraps every 4398046511096ns
[    0.007329] Console: colour dummy device 80x25
[    0.009997] Calibrating delay loop (skipped), value calculated using timer frequency.. 125.00 BogoMIPS (lpj=250000)
[    0.010169] pid_max: default: 32768 minimum: 301
[    0.011621] LSM: initializing lsm=capability,integrity
[    0.014618] Mount-cache hash table entries: 512 (order: 0, 4096 bytes, linear)
[    0.014699] Mountpoint-cache hash table entries: 512 (order: 0, 4096 bytes, linear)
[    0.083443] cacheinfo: Unable to detect cache hierarchy for CPU 0
[    0.127104] cblist_init_generic: Setting adjustable number of callback queues.
[    0.127267] cblist_init_generic: Setting shift to 0 and lim to 1.
[    0.128014] cblist_init_generic: Setting shift to 0 and lim to 1.
[    0.130612] rcu: Hierarchical SRCU implementation.
[    0.130674] rcu:     Max phase no-delay instances is 1000.
[    0.136068] EFI services will not be available.
[    0.137024] smp: Bringing up secondary CPUs ...
[    0.137222] smp: Brought up 1 node, 1 CPU
[    0.137281] SMP: Total of 1 processors activated.
[    0.137416] CPU features: detected: 32-bit EL0 Support
[    0.137453] CPU features: detected: 32-bit EL1 Support
[    0.137529] CPU features: detected: CRC32 instructions
[    0.141199] CPU: All CPU(s) started at EL1
[    0.141447] alternatives: applying system-wide alternatives
[    0.193674] devtmpfs: initialized
[    0.210547] clocksource: jiffies: mask: 0xffffffff max_cycles: 0xffffffff, max_idle_ns: 7645041785100000 ns
[    0.210907] futex hash table entries: 256 (order: 2, 16384 bytes, linear)
[    0.216348] pinctrl core: initialized pinctrl subsystem
[    0.264750] DMI not present or invalid.
[    0.274687] NET: Registered PF_NETLINK/PF_ROUTE protocol family
[    0.287926] DMA: preallocated 128 KiB GFP_KERNEL pool for atomic allocations
[    0.288678] DMA: preallocated 128 KiB GFP_KERNEL|GFP_DMA pool for atomic allocations
[    0.288949] DMA: preallocated 128 KiB GFP_KERNEL|GFP_DMA32 pool for atomic allocations
[    0.289294] audit: initializing netlink subsys (disabled)
[    0.333936] thermal_sys: Registered thermal governor 'step_wise'
[    0.333995] thermal_sys: Registered thermal governor 'power_allocator'
[    0.335072] audit: type=2000 audit(0.000:1): state=initialized audit_enabled=0 res=1
[    0.335497] cpuidle: using governor menu
[    0.337337] hw-breakpoint: found 6 breakpoint and 4 watchpoint registers.
[    0.338115] ASID allocator initialised with 65536 entries
[    0.347659] Serial: AMBA PL011 UART driver
[    0.478394] 9000000.pl011: ttyAMA0 at MMIO 0x9000000 (irq = 13, base_baud = 0) is a PL011 rev1
[    0.479750] printk: console [ttyAMA0] enabled
[    0.554527] HugeTLB: registered 1.00 GiB page size, pre-allocated 0 pages
[    0.554834] HugeTLB: 0 KiB vmemmap can be freed for a 1.00 GiB page
[    0.555247] HugeTLB: registered 32.0 MiB page size, pre-allocated 0 pages
[    0.555526] HugeTLB: 0 KiB vmemmap can be freed for a 32.0 MiB page
[    0.555757] HugeTLB: registered 2.00 MiB page size, pre-allocated 0 pages
[    0.555983] HugeTLB: 0 KiB vmemmap can be freed for a 2.00 MiB page
[    0.556200] HugeTLB: registered 64.0 KiB page size, pre-allocated 0 pages
[    0.556452] HugeTLB: 0 KiB vmemmap can be freed for a 64.0 KiB page
[    0.603464] ACPI: Interpreter disabled.
[    0.613251] iommu: Default domain type: Translated 
[    0.613621] iommu: DMA domain TLB invalidation policy: strict mode 
[    0.615983] SCSI subsystem initialized
[    0.619323] usbcore: registered new interface driver usbfs
[    0.619828] usbcore: registered new interface driver hub
[    0.620181] usbcore: registered new device driver usb
[    0.623934] pps_core: LinuxPPS API ver. 1 registered
[    0.624145] pps_core: Software ver. 5.3.6 - Copyright 2005-2007 Rodolfo Giometti <giometti@linux.it>
[    0.624665] PTP clock support registered
[    0.625860] EDAC MC: Ver: 3.0.0
[    0.635001] FPGA manager framework
[    0.670400] Advanced Linux Sound Architecture Driver Initialized.
[    0.683223] vgaarb: loaded
[    0.687503] clocksource: Switched to clocksource arch_sys_counter
[    0.689615] VFS: Disk quotas dquot_6.6.0
[    0.689930] VFS: Dquot-cache hash table entries: 512 (order 0, 4096 bytes)
[    0.692260] pnp: PnP ACPI: disabled
[    0.755481] NET: Registered PF_INET protocol family
[    0.758031] IP idents hash table entries: 4096 (order: 3, 32768 bytes, linear)
[    0.763398] tcp_listen_portaddr_hash hash table entries: 256 (order: 0, 4096 bytes, linear)
[    0.764128] Table-perturb hash table entries: 65536 (order: 6, 262144 bytes, linear)
[    0.764640] TCP established hash table entries: 2048 (order: 2, 16384 bytes, linear)
[    0.765129] TCP bind hash table entries: 2048 (order: 4, 65536 bytes, linear)
[    0.765587] TCP: Hash tables configured (established 2048 bind 2048)
[    0.767259] UDP hash table entries: 256 (order: 1, 8192 bytes, linear)
[    0.767993] UDP-Lite hash table entries: 256 (order: 1, 8192 bytes, linear)
[    0.769986] NET: Registered PF_UNIX/PF_LOCAL protocol family
[    0.808881] RPC: Registered named UNIX socket transport module.
[    0.809160] RPC: Registered udp transport module.
[    0.809356] RPC: Registered tcp transport module.
[    0.809524] RPC: Registered tcp NFSv4.1 backchannel transport module.
[    0.809875] PCI: CLS 0 bytes, default 64
[    0.816243] Unpacking initramfs...
[    1.165760] Freeing initrd memory: 7384K
        el2 esr: 9380000f, ec: 24
        el2 esr: 9380000f, ec: 24
        el2 esr: 9381004f, ec: 24
gpa: 8000100, r: 800000, len: 4, int id: 23
set enable: reg: 0, mask: 0x800000
      <<< gicd emu write GICD_ISENABLER(0)
[    1.172239] hw perfevents: enabled with armv8_pmuv3 PMU driver, 5 counters available
[    1.173503] kvm [1]: HYP mode not available
[    1.179512] Initialise system trusted keyrings
[    1.182240] workingset: timestamp_bits=42 max_order=16 bucket_order=0
[    1.219575] squashfs: version 4.0 (2009/01/31) Phillip Lougher
[    1.222870] NFS: Registering the id_resolver key type
[    1.223629] Key type id_resolver registered
[    1.223862] Key type id_legacy registered
[    1.224690] nfs4filelayout_init: NFSv4 File Layout Driver Registering...
[    1.225040] nfs4flexfilelayout_init: NFSv4 Flexfile Layout Driver Registering...
[    1.226673] 9p: Installing v9fs 9p2000 file system support
[    1.294125] Key type asymmetric registered
[    1.294398] Asymmetric key parser 'x509' registered
[    1.295053] Block layer SCSI generic (bsg) driver version 0.4 loaded (major 245)
[    1.295470] io scheduler mq-deadline registered
[    1.295896] io scheduler kyber registered
        el2 esr: 9380000f, ec: 24
      >>> gicd emu read GICD_ICFGR(i)
        el2 esr: 9381004f, ec: 24
gpa: 8000104, r: 80, len: 4, int id: 39
set enable: reg: 1, mask: 0x80
      <<< gicd emu write GICD_ISENABLER(i)
        el2 esr: 9300004f, ec: 24
      <<< gicd emu write GICD_ITARGETSR(i)
[    1.374917] pl061_gpio 9030000.pl061: PL061 GPIO chip registered
[    1.386054] pci-host-generic 4010000000.pcie: host bridge /pcie@10000000 ranges:
[    1.387253] pci-host-generic 4010000000.pcie:       IO 0x003eff0000..0x003effffff -> 0x0000000000
[    1.422332] pci-host-generic 4010000000.pcie:      MEM 0x0010000000..0x003efeffff -> 0x0010000000
[    1.422754] pci-host-generic 4010000000.pcie:      MEM 0x8000000000..0xffffffffff -> 0x8000000000
[    1.423776] pci-host-generic 4010000000.pcie: Memory resource size exceeds max for 32 bits
[    1.424783] pci-host-generic 4010000000.pcie: ECAM at [mem 0x4010000000-0x401fffffff] for [bus 00-ff]
[    1.427098] pci-host-generic 4010000000.pcie: PCI host bridge to bus 0000:00
[    1.427682] pci_bus 0000:00: root bus resource [bus 00-ff]
[    1.427943] pci_bus 0000:00: root bus resource [io  0x0000-0xffff]
[    1.428235] pci_bus 0000:00: root bus resource [mem 0x10000000-0x3efeffff]
[    1.428491] pci_bus 0000:00: root bus resource [mem 0x8000000000-0xffffffffff]
        el2 esr: 93810004, ec: 24
emu gicd error
        el2 esr: 93810004, ec: 24
emu gicd error
        el2 esr: 93000004, ec: 24
emu gicd error
        el2 esr: 93400004, ec: 24
emu gicd error
        el2 esr: 93810004, ec: 24
emu gicd error
        el2 esr: 93400004, ec: 24
emu gicd error
[    1.432472] pci 0000:00:01.0: [8000:0000] type 0e class 0x000080
        el2 esr: 93400004, ec: 24
emu gicd error
        el2 esr: 93440044, ec: 24
emu gicd error
        el2 esr: 93400004, ec: 24
emu gicd error
        el2 esr: 93440044, ec: 24
emu gicd error
[    1.434040] pci 0000:00:01.0: unknown header type 0e, ignoring device
        el2 esr: 93810004, ec: 24
emu gicd error
        el2 esr: 93000004, ec: 24
emu gicd error
        el2 esr: 93400004, ec: 24
emu gicd error
        el2 esr: 93810004, ec: 24
emu gicd error
        el2 esr: 93400004, ec: 24
emu gicd error
[    1.435821] pci 0000:00:02.0: [0000:0001] type 0e class 0x000100
        el2 esr: 93400004, ec: 24
emu gicd error
        el2 esr: 93440044, ec: 24
emu gicd error
        el2 esr: 93400004, ec: 24
emu gicd error
        el2 esr: 93440044, ec: 24
emu gicd error
[    1.437022] pci 0000:00:02.0: unknown header type 0e, ignoring device
        el2 esr: 93810004, ec: 24
emu gicd error
        el2 esr: 93000004, ec: 24
emu gicd error
        el2 esr: 93400004, ec: 24
emu gicd error
        el2 esr: 93810004, ec: 24
emu gicd error
        el2 esr: 93400004, ec: 24
emu gicd error
[    1.438705] pci 0000:00:03.0: [8000:0001] type 0e class 0x000180
        el2 esr: 93400004, ec: 24
emu gicd error
        el2 esr: 93440044, ec: 24
emu gicd error
        el2 esr: 93400004, ec: 24
emu gicd error
        el2 esr: 93440044, ec: 24
emu gicd error
[    1.439937] pci 0000:00:03.0: unknown header type 0e, ignoring device
        el2 esr: 93810004, ec: 24
emu gicd error
        el2 esr: 93000004, ec: 24
emu gicd error
        el2 esr: 93400004, ec: 24
emu gicd error
        el2 esr: 93810004, ec: 24
emu gicd error
        el2 esr: 93400004, ec: 24
emu gicd error
[    1.441539] pci 0000:00:04.0: [0000:0002] type 0e class 0x000200
        el2 esr: 93400004, ec: 24
emu gicd error
        el2 esr: 93440044, ec: 24
emu gicd error
        el2 esr: 93400004, ec: 24
emu gicd error
        el2 esr: 93440044, ec: 24
emu gicd error
[    1.442665] pci 0000:00:04.0: unknown header type 0e, ignoring device
        el2 esr: 93810004, ec: 24
emu gicd error
        el2 esr: 93000004, ec: 24
emu gicd error
        el2 esr: 93400004, ec: 24
emu gicd error
        el2 esr: 93810004, ec: 24
emu gicd error
        el2 esr: 93400004, ec: 24
emu gicd error
[    1.444270] pci 0000:00:05.0: [8000:0002] type 0e class 0x000280
        el2 esr: 93400004, ec: 24
emu gicd error
        el2 esr: 93440044, ec: 24
emu gicd error
        el2 esr: 93400004, ec: 24
emu gicd error
        el2 esr: 93440044, ec: 24
emu gicd error
[    1.445527] pci 0000:00:05.0: unknown header type 0e, ignoring device
        el2 esr: 93810004, ec: 24
emu gicd error
        el2 esr: 93000004, ec: 24
emu gicd error
        el2 esr: 93400004, ec: 24
emu gicd error
        el2 esr: 93810004, ec: 24
emu gicd error
        el2 esr: 93400004, ec: 24
emu gicd error
[    1.447101] pci 0000:00:06.0: [0000:0003] type 0e class 0x000300
        el2 esr: 93400004, ec: 24
emu gicd error
        el2 esr: 93440044, ec: 24
emu gicd error
        el2 esr: 93400004, ec: 24
emu gicd error
        el2 esr: 93440044, ec: 24
emu gicd error
[    1.448336] pci 0000:00:06.0: unknown header type 0e, ignoring device
        el2 esr: 93810004, ec: 24
emu gicd error
        el2 esr: 93000004, ec: 24
emu gicd error
        el2 esr: 93400004, ec: 24
emu gicd error
        el2 esr: 93810004, ec: 24
emu gicd error
        el2 esr: 93400004, ec: 24
emu gicd error
[    1.449935] pci 0000:00:07.0: [8000:0003] type 0e class 0x000380
        el2 esr: 93400004, ec: 24
emu gicd error
        el2 esr: 93440044, ec: 24
emu gicd error
        el2 esr: 93400004, ec: 24
emu gicd error
        el2 esr: 93440044, ec: 24
emu gicd error
[    1.451202] pci 0000:00:07.0: unknown header type 0e, ignoring device
        el2 esr: 93810004, ec: 24
emu gicd error
        el2 esr: 93000004, ec: 24
emu gicd error
        el2 esr: 93400004, ec: 24
emu gicd error
        el2 esr: 93810004, ec: 24
emu gicd error
        el2 esr: 93400004, ec: 24
emu gicd error
[    1.452844] pci 0000:00:08.0: [0000:0004] type 0e class 0x000400
        el2 esr: 93400004, ec: 24
emu gicd error
        el2 esr: 93440044, ec: 24
emu gicd error
        el2 esr: 93400004, ec: 24
emu gicd error
        el2 esr: 93440044, ec: 24
emu gicd error
[    1.454057] pci 0000:00:08.0: unknown header type 0e, ignoring device
        el2 esr: 93810004, ec: 24
emu gicd error
        el2 esr: 93000004, ec: 24
emu gicd error
        el2 esr: 93400004, ec: 24
emu gicd error
        el2 esr: 93810004, ec: 24
emu gicd error
        el2 esr: 93400004, ec: 24
emu gicd error
[    1.455729] pci 0000:00:09.0: [8000:0004] type 0e class 0x000480
        el2 esr: 93400004, ec: 24
emu gicd error
        el2 esr: 93440044, ec: 24
emu gicd error
        el2 esr: 93400004, ec: 24
emu gicd error
        el2 esr: 93440044, ec: 24
emu gicd error
[    1.457091] pci 0000:00:09.0: unknown header type 0e, ignoring device
        el2 esr: 93810004, ec: 24
emu gicd error
        el2 esr: 93000004, ec: 24
emu gicd error
        el2 esr: 93400004, ec: 24
emu gicd error
        el2 esr: 93810004, ec: 24
emu gicd error
        el2 esr: 93400004, ec: 24
emu gicd error
[    1.492760] pci 0000:00:0a.0: [0000:0005] type 0e class 0x000500
        el2 esr: 93400004, ec: 24
emu gicd error
        el2 esr: 93440044, ec: 24
emu gicd error
        el2 esr: 93400004, ec: 24
emu gicd error
        el2 esr: 93440044, ec: 24
emu gicd error
[    1.493996] pci 0000:00:0a.0: unknown header type 0e, ignoring device
        el2 esr: 93810004, ec: 24
emu gicd error
        el2 esr: 93000004, ec: 24
emu gicd error
        el2 esr: 93400004, ec: 24
emu gicd error
        el2 esr: 93810004, ec: 24
emu gicd error
        el2 esr: 93400004, ec: 24
emu gicd error
[    1.495589] pci 0000:00:0b.0: [8000:0005] type 0e class 0x000580
        el2 esr: 93400004, ec: 24
emu gicd error
        el2 esr: 93440044, ec: 24
emu gicd error
        el2 esr: 93400004, ec: 24
emu gicd error
        el2 esr: 93440044, ec: 24
emu gicd error
[    1.496818] pci 0000:00:0b.0: unknown header type 0e, ignoring device
        el2 esr: 93810004, ec: 24
emu gicd error
        el2 esr: 93000004, ec: 24
emu gicd error
        el2 esr: 93400004, ec: 24
emu gicd error
        el2 esr: 93810004, ec: 24
emu gicd error
        el2 esr: 93400004, ec: 24
emu gicd error
[    1.498409] pci 0000:00:0c.0: [0000:0006] type 0e class 0x000600
        el2 esr: 93400004, ec: 24
emu gicd error
        el2 esr: 93440044, ec: 24
emu gicd error
        el2 esr: 93400004, ec: 24
emu gicd error
        el2 esr: 93440044, ec: 24
emu gicd error
[    1.499558] pci 0000:00:0c.0: unknown header type 0e, ignoring device
        el2 esr: 93810004, ec: 24
emu gicd error
        el2 esr: 93000004, ec: 24
emu gicd error
        el2 esr: 93400004, ec: 24
emu gicd error
        el2 esr: 93810004, ec: 24
emu gicd error
        el2 esr: 93400004, ec: 24
emu gicd error
[    1.501156] pci 0000:00:0d.0: [8000:0006] type 0e class 0x000680
        el2 esr: 93400004, ec: 24
emu gicd error
        el2 esr: 93440044, ec: 24
emu gicd error
        el2 esr: 93400004, ec: 24
emu gicd error
        el2 esr: 93440044, ec: 24
emu gicd error
[    1.502342] pci 0000:00:0d.0: unknown header type 0e, ignoring device
        el2 esr: 93810004, ec: 24
emu gicd error
        el2 esr: 93000004, ec: 24
emu gicd error
        el2 esr: 93400004, ec: 24
emu gicd error
        el2 esr: 93810004, ec: 24
emu gicd error
        el2 esr: 93400004, ec: 24
emu gicd error
[    1.503972] pci 0000:00:0e.0: [0000:0007] type 0e class 0x000700
        el2 esr: 93400004, ec: 24
emu gicd error
        el2 esr: 93440044, ec: 24
emu gicd error
        el2 esr: 93400004, ec: 24
emu gicd error
        el2 esr: 93440044, ec: 24
emu gicd error
[    1.505091] pci 0000:00:0e.0: unknown header type 0e, ignoring device
        el2 esr: 93810004, ec: 24
emu gicd error
        el2 esr: 93000004, ec: 24
emu gicd error
        el2 esr: 93400004, ec: 24
emu gicd error
        el2 esr: 93810004, ec: 24
emu gicd error
        el2 esr: 93400004, ec: 24
emu gicd error
[    1.506769] pci 0000:00:0f.0: [8000:0007] type 0e class 0x000780
        el2 esr: 93400004, ec: 24
emu gicd error
        el2 esr: 93440044, ec: 24
emu gicd error
        el2 esr: 93400004, ec: 24
emu gicd error
        el2 esr: 93440044, ec: 24
emu gicd error
[    1.507928] pci 0000:00:0f.0: unknown header type 0e, ignoring device
        el2 esr: 93810004, ec: 24
emu gicd error
        el2 esr: 93000004, ec: 24
emu gicd error
        el2 esr: 93400004, ec: 24
emu gicd error
        el2 esr: 93810004, ec: 24
emu gicd error
        el2 esr: 93400004, ec: 24
emu gicd error
[    1.509559] pci 0000:00:10.0: [0000:0008] type 0e class 0x000800
        el2 esr: 93400004, ec: 24
emu gicd error
        el2 esr: 93440044, ec: 24
emu gicd error
        el2 esr: 93400004, ec: 24
emu gicd error
        el2 esr: 93440044, ec: 24
emu gicd error
[    1.510789] pci 0000:00:10.0: unknown header type 0e, ignoring device
        el2 esr: 93810004, ec: 24
emu gicd error
        el2 esr: 93000004, ec: 24
emu gicd error
        el2 esr: 93400004, ec: 24
emu gicd error
        el2 esr: 93810004, ec: 24
emu gicd error
        el2 esr: 93400004, ec: 24
emu gicd error
[    1.512281] pci 0000:00:11.0: [8000:0008] type 0e class 0x000880
        el2 esr: 93400004, ec: 24
emu gicd error
        el2 esr: 93440044, ec: 24
emu gicd error
        el2 esr: 93400004, ec: 24
emu gicd error
        el2 esr: 93440044, ec: 24
emu gicd error
[    1.513584] pci 0000:00:11.0: unknown header type 0e, ignoring device
        el2 esr: 93810004, ec: 24
emu gicd error
        el2 esr: 93000004, ec: 24
emu gicd error
        el2 esr: 93400004, ec: 24
emu gicd error
        el2 esr: 93810004, ec: 24
emu gicd error
        el2 esr: 93400004, ec: 24
emu gicd error
[    1.515236] pci 0000:00:12.0: [0000:0009] type 0e class 0x000900
        el2 esr: 93400004, ec: 24
emu gicd error
        el2 esr: 93440044, ec: 24
emu gicd error
        el2 esr: 93400004, ec: 24
emu gicd error
        el2 esr: 93440044, ec: 24
emu gicd error
[    1.516493] pci 0000:00:12.0: unknown header type 0e, ignoring device
        el2 esr: 93810004, ec: 24
emu gicd error
        el2 esr: 93000004, ec: 24
emu gicd error
        el2 esr: 93400004, ec: 24
emu gicd error
        el2 esr: 93810004, ec: 24
emu gicd error
        el2 esr: 93400004, ec: 24
emu gicd error
[    1.518094] pci 0000:00:13.0: [8000:0009] type 0e class 0x000980
        el2 esr: 93400004, ec: 24
emu gicd error
        el2 esr: 93440044, ec: 24
emu gicd error
        el2 esr: 93400004, ec: 24
emu gicd error
        el2 esr: 93440044, ec: 24
emu gicd error
[    1.519219] pci 0000:00:13.0: unknown header type 0e, ignoring device
        el2 esr: 93810004, ec: 24
emu gicd error
        el2 esr: 93000004, ec: 24
emu gicd error
        el2 esr: 93400004, ec: 24
emu gicd error
        el2 esr: 93810004, ec: 24
emu gicd error
        el2 esr: 93400004, ec: 24
emu gicd error
[    1.520895] pci 0000:00:14.0: [0000:000a] type 0e class 0x000a00
        el2 esr: 93400004, ec: 24
emu gicd error
        el2 esr: 93440044, ec: 24
emu gicd error
        el2 esr: 93400004, ec: 24
emu gicd error
        el2 esr: 93440044, ec: 24
emu gicd error
[    1.522130] pci 0000:00:14.0: unknown header type 0e, ignoring device
        el2 esr: 93810004, ec: 24
emu gicd error
        el2 esr: 93000004, ec: 24
emu gicd error
        el2 esr: 93400004, ec: 24
emu gicd error
        el2 esr: 93810004, ec: 24
emu gicd error
        el2 esr: 93400004, ec: 24
emu gicd error
[    1.523792] pci 0000:00:15.0: [8000:000a] type 0e class 0x000a80
        el2 esr: 93400004, ec: 24
emu gicd error
        el2 esr: 93440044, ec: 24
emu gicd error
        el2 esr: 93400004, ec: 24
emu gicd error
        el2 esr: 93440044, ec: 24
emu gicd error
[    1.525030] pci 0000:00:15.0: unknown header type 0e, ignoring device
        el2 esr: 93810004, ec: 24
emu gicd error
        el2 esr: 93000004, ec: 24
emu gicd error
        el2 esr: 93400004, ec: 24
emu gicd error
        el2 esr: 93810004, ec: 24
emu gicd error
        el2 esr: 93400004, ec: 24
emu gicd error
[    1.526545] pci 0000:00:16.0: [0000:000b] type 0e class 0x000b00
        el2 esr: 93400004, ec: 24
emu gicd error
        el2 esr: 93440044, ec: 24
emu gicd error
        el2 esr: 93400004, ec: 24
emu gicd error
        el2 esr: 93440044, ec: 24
emu gicd error
[    1.561841] pci 0000:00:16.0: unknown header type 0e, ignoring device
        el2 esr: 93810004, ec: 24
emu gicd error
        el2 esr: 93000004, ec: 24
emu gicd error
        el2 esr: 93400004, ec: 24
emu gicd error
        el2 esr: 93810004, ec: 24
emu gicd error
        el2 esr: 93400004, ec: 24
emu gicd error
[    1.563474] pci 0000:00:17.0: [8000:000b] type 0e class 0x000b80
        el2 esr: 93400004, ec: 24
emu gicd error
        el2 esr: 93440044, ec: 24
emu gicd error
        el2 esr: 93400004, ec: 24
emu gicd error
        el2 esr: 93440044, ec: 24
emu gicd error
[    1.564762] pci 0000:00:17.0: unknown header type 0e, ignoring device
        el2 esr: 93810004, ec: 24
emu gicd error
        el2 esr: 93000004, ec: 24
emu gicd error
        el2 esr: 93400004, ec: 24
emu gicd error
        el2 esr: 93810004, ec: 24
emu gicd error
        el2 esr: 93400004, ec: 24
emu gicd error
[    1.566367] pci 0000:00:18.0: [0000:000c] type 0e class 0x000c00
        el2 esr: 93400004, ec: 24
emu gicd error
        el2 esr: 93440044, ec: 24
emu gicd error
        el2 esr: 93400004, ec: 24
emu gicd error
        el2 esr: 93440044, ec: 24
emu gicd error
[    1.567558] pci 0000:00:18.0: unknown header type 0e, ignoring device
        el2 esr: 93810004, ec: 24
emu gicd error
        el2 esr: 93000004, ec: 24
emu gicd error
        el2 esr: 93400004, ec: 24
emu gicd error
        el2 esr: 93810004, ec: 24
emu gicd error
        el2 esr: 93400004, ec: 24
emu gicd error
[    1.569175] pci 0000:00:19.0: [8000:000c] type 0e class 0x000c80
        el2 esr: 93400004, ec: 24
emu gicd error
        el2 esr: 93440044, ec: 24
emu gicd error
        el2 esr: 93400004, ec: 24
emu gicd error
        el2 esr: 93440044, ec: 24
emu gicd error
[    1.570415] pci 0000:00:19.0: unknown header type 0e, ignoring device
        el2 esr: 93810004, ec: 24
emu gicd error
        el2 esr: 93000004, ec: 24
emu gicd error
        el2 esr: 93400004, ec: 24
emu gicd error
        el2 esr: 93810004, ec: 24
emu gicd error
        el2 esr: 93400004, ec: 24
emu gicd error
[    1.572028] pci 0000:00:1a.0: [0000:000d] type 0e class 0x000d00
        el2 esr: 93400004, ec: 24
emu gicd error
        el2 esr: 93440044, ec: 24
emu gicd error
        el2 esr: 93400004, ec: 24
emu gicd error
        el2 esr: 93440044, ec: 24
emu gicd error
[    1.573168] pci 0000:00:1a.0: unknown header type 0e, ignoring device
        el2 esr: 93810004, ec: 24
emu gicd error
        el2 esr: 93000004, ec: 24
emu gicd error
        el2 esr: 93400004, ec: 24
emu gicd error
        el2 esr: 93810004, ec: 24
emu gicd error
        el2 esr: 93400004, ec: 24
emu gicd error
[    1.574859] pci 0000:00:1b.0: [8000:000d] type 0e class 0x000d80
        el2 esr: 93400004, ec: 24
emu gicd error
        el2 esr: 93440044, ec: 24
emu gicd error
        el2 esr: 93400004, ec: 24
emu gicd error
        el2 esr: 93440044, ec: 24
emu gicd error
[    1.576052] pci 0000:00:1b.0: unknown header type 0e, ignoring device
        el2 esr: 93810004, ec: 24
emu gicd error
        el2 esr: 93000004, ec: 24
emu gicd error
        el2 esr: 93400004, ec: 24
emu gicd error
        el2 esr: 93810004, ec: 24
emu gicd error
        el2 esr: 93400004, ec: 24
emu gicd error
[    1.577744] pci 0000:00:1c.0: [0000:000e] type 0e class 0x000e00
        el2 esr: 93400004, ec: 24
emu gicd error
        el2 esr: 93440044, ec: 24
emu gicd error
        el2 esr: 93400004, ec: 24
emu gicd error
        el2 esr: 93440044, ec: 24
emu gicd error
[    1.578965] pci 0000:00:1c.0: unknown header type 0e, ignoring device
        el2 esr: 93810004, ec: 24
emu gicd error
        el2 esr: 93000004, ec: 24
emu gicd error
        el2 esr: 93400004, ec: 24
emu gicd error
        el2 esr: 93810004, ec: 24
emu gicd error
        el2 esr: 93400004, ec: 24
emu gicd error
[    1.580497] pci 0000:00:1d.0: [8000:000e] type 0e class 0x000e80
        el2 esr: 93400004, ec: 24
emu gicd error
        el2 esr: 93440044, ec: 24
emu gicd error
        el2 esr: 93400004, ec: 24
emu gicd error
        el2 esr: 93440044, ec: 24
emu gicd error
[    1.581772] pci 0000:00:1d.0: unknown header type 0e, ignoring device
        el2 esr: 93810004, ec: 24
emu gicd error
        el2 esr: 93000004, ec: 24
emu gicd error
        el2 esr: 93400004, ec: 24
emu gicd error
        el2 esr: 93810004, ec: 24
emu gicd error
        el2 esr: 93400004, ec: 24
emu gicd error
[    1.583428] pci 0000:00:1e.0: [0000:000f] type 0e class 0x000f00
        el2 esr: 93400004, ec: 24
emu gicd error
        el2 esr: 93440044, ec: 24
emu gicd error
        el2 esr: 93400004, ec: 24
emu gicd error
        el2 esr: 93440044, ec: 24
emu gicd error
[    1.584662] pci 0000:00:1e.0: unknown header type 0e, ignoring device
        el2 esr: 93810004, ec: 24
emu gicd error
        el2 esr: 93000004, ec: 24
emu gicd error
        el2 esr: 93400004, ec: 24
emu gicd error
        el2 esr: 93810004, ec: 24
emu gicd error
        el2 esr: 93400004, ec: 24
emu gicd error
[    1.586259] pci 0000:00:1f.0: [8000:000f] type 0e class 0x000f80
        el2 esr: 93400004, ec: 24
emu gicd error
        el2 esr: 93440044, ec: 24
emu gicd error
        el2 esr: 93400004, ec: 24
emu gicd error
        el2 esr: 93440044, ec: 24
emu gicd error
[    1.587460] pci 0000:00:1f.0: unknown header type 0e, ignoring device
[    1.633223] EINJ: ACPI disabled.
[    1.839727] Serial: 8250/16550 driver, 4 ports, IRQ sharing enabled
[    1.853388] SuperH (H)SCI(F) driver initialized
[    1.855981] msm_serial: driver initialized
[    1.864419] cacheinfo: Unable to detect cache hierarchy for CPU 0
[    1.925669] loop: module loaded
[    1.930212] megasas: 07.719.03.00-rc1
[    1.975371] physmap-flash 0.flash: physmap platform flash device: [mem 0x00000000-0x03ffffff]
[    1.977469] 0.flash: Found 2 x16 devices at 0x0 in 32-bit bank. Manufacturer ID 0x000000 Chip ID 0x000000
[    1.978393] Intel/Sharp Extended Query Table at 0x0031
[    1.979676] Using buffer write method
[    1.980718] physmap-flash 0.flash: physmap platform flash device: [mem 0x04000000-0x07ffffff]
[    1.981672] 0.flash: Found 2 x16 devices at 0x0 in 32-bit bank. Manufacturer ID 0x000000 Chip ID 0x000000
[    1.982273] Intel/Sharp Extended Query Table at 0x0031
[    1.983074] Using buffer write method
[    1.983434] Concatenating MTD devices:
[    1.983605] (0): "0.flash"
[    1.983830] (1): "0.flash"
[    1.983999] into device "0.flash"
[    2.139863] tun: Universal TUN/TAP device driver, 1.6
[    2.144175] thunder_xcv, ver 1.0
[    2.144522] thunder_bgx, ver 1.0
[    2.178882] nicpf, ver 1.0
[    2.185041] hns3: Hisilicon Ethernet Network Driver for Hip08 Family - version
[    2.185308] hns3: Copyright (c) 2017 Huawei Corporation.
[    2.186190] hclge is initializing
[    2.186562] e1000: Intel(R) PRO/1000 Network Driver
[    2.186775] e1000: Copyright (c) 1999-2006 Intel Corporation.
[    2.187148] e1000e: Intel(R) PRO/1000 Network Driver
[    2.187474] e1000e: Copyright(c) 1999 - 2015 Intel Corporation.
[    2.188027] igb: Intel(R) Gigabit Ethernet Network Driver
[    2.188251] igb: Copyright (c) 2007-2014 Intel Corporation.
[    2.188606] igbvf: Intel(R) Gigabit Virtual Function Network Driver
[    2.188839] igbvf: Copyright (c) 2009 - 2012 Intel Corporation.
[    2.190796] sky2: driver version 1.30
[    2.197176] VFIO - User Level meta-driver version: 0.3
[    2.211751] usbcore: registered new interface driver usb-storage
[    2.262378] rtc-pl031 9010000.pl031: registered as rtc0
[    2.263344] rtc-pl031 9010000.pl031: setting system clock to 2024-08-30T15:34:02 UTC (1725032042)
        el2 esr: 9380000f, ec: 24
      >>> gicd emu read GICD_ICFGR(i)
        el2 esr: 9381004f, ec: 24
gpa: 8000104, r: 4, len: 4, int id: 34
set enable: reg: 1, mask: 0x4
      <<< gicd emu write GICD_ISENABLER(i)
        el2 esr: 9300004f, ec: 24
      <<< gicd emu write GICD_ITARGETSR(i)
[    2.269354] i2c_dev: i2c /dev entries driver
[    2.329188] ghes_edac: GHES probing device list is empty
[    2.339077] sdhci: Secure Digital Host Controller Interface driver
[    2.339532] sdhci: Copyright(c) Pierre Ossman
[    2.343390] Synopsys Designware Multimedia Card Interface Driver
[    2.348281] sdhci-pltfm: SDHCI platform and OF driver helper
[    2.390981] ledtrig-cpu: registered to indicate activity on CPUs
        el2 esr: 5e000000, ec: 17
            This is smc call handler
[    2.396738] SMCCC: SOC_ID: ARCH_FEATURES(ARCH_SOC_ID) returned error: 80000001
[    2.401575] usbcore: registered new interface driver usbhid
[    2.401881] usbhid: USB HID core driver
[    2.468714] NET: Registered PF_PACKET protocol family
[    2.470161] 9pnet: Installing 9P2000 support
[    2.470905] Key type dns_resolver registered
[    2.534891] registered taskstats version 1
[    2.536197] Loading compiled-in X.509 certificates
[    2.597803] input: gpio-keys as /devices/platform/gpio-keys/input/input0
[    2.605484] ALSA device list:
[    2.605739]   No soundcards found.
        el2 esr: 9380000f, ec: 24
      >>> gicd emu read GICD_ICFGR(i)
        el2 esr: 9381004f, ec: 24
gpa: 8000104, r: 2, len: 4, int id: 33
set enable: reg: 1, mask: 0x2
      <<< gicd emu write GICD_ISENABLER(i)
        el2 esr: 9300004f, ec: 24
      <<< gicd emu write GICD_ITARGETSR(i)
[    2.610996] uart-pl011 9000000.pl011: no DMA platform data
[    2.735143] Freeing unused kernel memory: 7936K
[    2.735520] Kernel memory protection disabled.
[    2.736052] Run /init as init process
Loading, please wait...
/bin/sh: can't access tty; job control turned off
~ #