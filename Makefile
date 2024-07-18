

TOOL_PREFIX=aarch64-linux-musl-

BUILD_DIR=build

INCLUDE = -I ./include \
	      -I /home/ajax/rust/usb/first_state/aarch64-linux-musl-cross/aarch64-linux-musl/include

n = -nostdlib -nostdinc -fno-stack-protector

SMP = 1
HV  = n

CFLAGS = -g -c -O0 -fno-pie  -mgeneral-regs-only \
	 -fno-builtin-vsnprintf -fno-builtin-snprintf -fno-builtin-printf -DSMP_NUM=$(SMP)

QEMU_ARGS = -m 4G -smp $(SMP) -cpu cortex-a72 -nographic 

QEMU_ARGS += -M virt,gic_version=2

# QEMU_ARGS += -M secure=on

ifeq ($(HV),y)
QEMU_ARGS += -M virtualization=on
endif


$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

#  kernel main
$(BUILD_DIR)/main.o: main.c
	$(TOOL_PREFIX)gcc $(CFLAGS) main.c $(INCLUDE) -o $(BUILD_DIR)/main.o

#  kernel smp
$(BUILD_DIR)/smp.o: smp.c
	$(TOOL_PREFIX)gcc $(CFLAGS) smp.c $(INCLUDE) -o $(BUILD_DIR)/smp.o

#  kernel main hyper
$(BUILD_DIR)/main_hyper.o: main_hyper.c
	$(TOOL_PREFIX)gcc $(CFLAGS) main_hyper.c $(INCLUDE) -o $(BUILD_DIR)/main_hyper.o

#  boot 
$(BUILD_DIR)/boot.s.o: boot/boot.S
	$(TOOL_PREFIX)gcc $(CFLAGS) boot/boot.S $(INCLUDE) -o $(BUILD_DIR)/boot.s.o

#  exception
$(BUILD_DIR)/exception.o: exception/exception.c
	$(TOOL_PREFIX)gcc $(CFLAGS) exception/exception.c $(INCLUDE) -o $(BUILD_DIR)/exception.o

$(BUILD_DIR)/exception_el3.o: exception/exception_el3.c
	$(TOOL_PREFIX)gcc $(CFLAGS) exception/exception_el3.c $(INCLUDE) -o $(BUILD_DIR)/exception_el3.o

$(BUILD_DIR)/exception_el2.o: exception/exception_el2.c
	$(TOOL_PREFIX)gcc $(CFLAGS) exception/exception_el2.c $(INCLUDE) -o $(BUILD_DIR)/exception_el2.o

$(BUILD_DIR)/exception.s.o: exception/exception.S
	$(TOOL_PREFIX)gcc $(CFLAGS) exception/exception.S $(INCLUDE) -o $(BUILD_DIR)/exception.s.o

$(BUILD_DIR)/exception_el3.s.o: exception/exception_el3.S
	$(TOOL_PREFIX)gcc $(CFLAGS) exception/exception_el3.S $(INCLUDE) -o $(BUILD_DIR)/exception_el3.s.o

$(BUILD_DIR)/exception_el2.s.o: exception/exception_el2.S
	$(TOOL_PREFIX)gcc $(CFLAGS) exception/exception_el2.S $(INCLUDE) -o $(BUILD_DIR)/exception_el2.s.o

$(BUILD_DIR)/gic.o: exception/gic/gic.c
	$(TOOL_PREFIX)gcc $(CFLAGS) exception/gic/gic.c $(INCLUDE) -o $(BUILD_DIR)/gic.o



#  io
$(BUILD_DIR)/io.o: io/io.c
	$(TOOL_PREFIX)gcc $(CFLAGS) io/io.c $(INCLUDE) -o $(BUILD_DIR)/io.o
$(BUILD_DIR)/printf.o: io/printf.c
	$(TOOL_PREFIX)gcc $(CFLAGS) io/printf.c $(INCLUDE) -o $(BUILD_DIR)/printf.o

$(BUILD_DIR)/uart_pl011.o: io/uart_pl011.c
	$(TOOL_PREFIX)gcc $(CFLAGS) io/uart_pl011.c $(INCLUDE) -o $(BUILD_DIR)/uart_pl011.o

#  mem
$(BUILD_DIR)/mmu.s.o: mem/mmu.S
	$(TOOL_PREFIX)gcc $(CFLAGS) mem/mmu.S $(INCLUDE) -o $(BUILD_DIR)/mmu.s.o
$(BUILD_DIR)/page.o: mem/page.c
	$(TOOL_PREFIX)gcc $(CFLAGS) mem/page.c $(INCLUDE) -o $(BUILD_DIR)/page.o
$(BUILD_DIR)/string.o: mem/string.c
	$(TOOL_PREFIX)gcc $(CFLAGS) mem/string.c $(INCLUDE) -o $(BUILD_DIR)/string.o
$(BUILD_DIR)/ept.o: mem/ept.c
	$(TOOL_PREFIX)gcc $(CFLAGS) mem/ept.c $(INCLUDE) -o $(BUILD_DIR)/ept.o

#  timer
$(BUILD_DIR)/timer.o: timer/timer.c
	$(TOOL_PREFIX)gcc $(CFLAGS) timer/timer.c $(INCLUDE) -o $(BUILD_DIR)/timer.o

#  schedule
$(BUILD_DIR)/task.o: schedule/task.c
	$(TOOL_PREFIX)gcc $(CFLAGS) schedule/task.c $(INCLUDE) -o $(BUILD_DIR)/task.o

$(BUILD_DIR)/context.s.o: schedule/context.S
	$(TOOL_PREFIX)gcc $(CFLAGS) schedule/context.S $(INCLUDE) -o $(BUILD_DIR)/context.s.o

#  spinlock 
$(BUILD_DIR)/spinlock.s.o: spinlock/spinlock.S
	$(TOOL_PREFIX)gcc $(CFLAGS) spinlock/spinlock.S $(INCLUDE) -o $(BUILD_DIR)/spinlock.s.o


#  hyper 
$(BUILD_DIR)/vcpu.o: hyper/vcpu.c
	$(TOOL_PREFIX)gcc $(CFLAGS) hyper/vcpu.c $(INCLUDE) -o $(BUILD_DIR)/vcpu.o
$(BUILD_DIR)/hyper_ctx.s.o: hyper/hyper_ctx.S
	$(TOOL_PREFIX)gcc $(CFLAGS) hyper/hyper_ctx.S $(INCLUDE) -o $(BUILD_DIR)/hyper_ctx.s.o
$(BUILD_DIR)/hyper.s.o: hyper/hyper.S
	$(TOOL_PREFIX)gcc $(CFLAGS) hyper/hyper.S $(INCLUDE) -o $(BUILD_DIR)/hyper.s.o

$(BUILD_DIR)/kernel.elf: $(BUILD_DIR) $(BUILD_DIR)/main.o $(BUILD_DIR)/smp.o $(BUILD_DIR)/main_hyper.o $(BUILD_DIR)/boot.s.o $(BUILD_DIR)/hyper.s.o $(BUILD_DIR)/exception.s.o $(BUILD_DIR)/exception.o $(BUILD_DIR)/io.o $(BUILD_DIR)/uart_pl011.o $(BUILD_DIR)/printf.o $(BUILD_DIR)/mmu.s.o $(BUILD_DIR)/page.o $(BUILD_DIR)/ept.o $(BUILD_DIR)/string.o $(BUILD_DIR)/exception_el3.s.o $(BUILD_DIR)/exception_el3.o $(BUILD_DIR)/exception_el2.o $(BUILD_DIR)/exception_el2.s.o $(BUILD_DIR)/gic.o $(BUILD_DIR)/timer.o $(BUILD_DIR)/task.o $(BUILD_DIR)/context.s.o $(BUILD_DIR)/spinlock.s.o $(BUILD_DIR)/vcpu.o $(BUILD_DIR)/hyper_ctx.s.o
	$(TOOL_PREFIX)ld -T link.lds -o $(BUILD_DIR)/kernel.elf \
	$(BUILD_DIR)/boot.s.o 			\
	$(BUILD_DIR)/hyper.s.o          \
	$(BUILD_DIR)/main.o 			\
	$(BUILD_DIR)/smp.o              \
	$(BUILD_DIR)/main_hyper.o 		\
	$(BUILD_DIR)/exception.s.o 		\
	$(BUILD_DIR)/exception_el3.s.o  \
	$(BUILD_DIR)/exception.o 		\
	$(BUILD_DIR)/exception_el3.o 	\
	$(BUILD_DIR)/exception_el2.o    \
	$(BUILD_DIR)/exception_el2.s.o  \
	$(BUILD_DIR)/gic.o 				\
	$(BUILD_DIR)/io.o 				\
	$(BUILD_DIR)/uart_pl011.o       \
	$(BUILD_DIR)/printf.o 			\
	$(BUILD_DIR)/mmu.s.o 			\
	$(BUILD_DIR)/page.o 			\
	$(BUILD_DIR)/ept.o              \
	$(BUILD_DIR)/string.o 			\
	$(BUILD_DIR)/timer.o  			\
	$(BUILD_DIR)/task.o 			\
	$(BUILD_DIR)/context.s.o 		\
	$(BUILD_DIR)/spinlock.s.o       \
	$(BUILD_DIR)/vcpu.o             \
	$(BUILD_DIR)/hyper_ctx.s.o



# makefile 命令

deasm:
	$(TOOL_PREFIX)objdump -x -d -S $(BUILD_DIR)/kernel.elf > $(BUILD_DIR)/dis.txt
	$(TOOL_PREFIX)readelf -a $(BUILD_DIR)/kernel.elf > $(BUILD_DIR)/elf.txt
	$(TOOL_PREFIX)objcopy -O binary $(BUILD_DIR)/kernel.elf $(BUILD_DIR)/kernel.bin

debug: $(BUILD_DIR)/kernel.elf deasm
	qemu-system-aarch64 $(QEMU_ARGS) -kernel $(BUILD_DIR)/kernel.elf -s -S

gdb:
	gdb-multiarch

run: $(BUILD_DIR)/kernel.elf
	qemu-system-aarch64 $(QEMU_ARGS) -kernel $(BUILD_DIR)/kernel.elf


clean:
	rm -f build/*.o
	rm -f build/*.bin
	rm -f build/*.txt
	rm -f build/*.elf
