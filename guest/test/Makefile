

TOOL_PREFIX=aarch64-linux-musl-

INCLUDE = -I /home/ajax/rust/usb/first_state/aarch64-linux-musl-cross/aarch64-linux-musl/include

BUILD=build/

CFLAGS= -g -c -O0 -fno-pie -fno-builtin-vsnprintf -fno-builtin-snprintf -fno-builtin-printf -mgeneral-regs-only

kernel:
	$(TOOL_PREFIX)gcc  $(CFLAGS) dmos.S $(INCLUDE) -o $(BUILD)dmos.s.o
	$(TOOL_PREFIX)gcc  $(CFLAGS) dmos.c $(INCLUDE) -o $(BUILD)dmos.o
	$(TOOL_PREFIX)gcc  $(CFLAGS) gic.c $(INCLUDE) -o $(BUILD)gic.o
	$(TOOL_PREFIX)gcc  $(CFLAGS) exception.c $(INCLUDE) -o $(BUILD)exception.o
	$(TOOL_PREFIX)gcc  $(CFLAGS) exception.S $(INCLUDE) -o $(BUILD)exception.s.o
	$(TOOL_PREFIX)gcc  $(CFLAGS) string.c $(INCLUDE) -o $(BUILD)string.o
	$(TOOL_PREFIX)gcc  $(CFLAGS) print.c $(INCLUDE) -o $(BUILD)print.o
	$(TOOL_PREFIX)gcc  $(CFLAGS) spinlock.S $(INCLUDE) -o $(BUILD)spinlock.s.o


	$(TOOL_PREFIX)ld -T link.lds -o $(BUILD)kernel.elf $(BUILD)dmos.s.o $(BUILD)spinlock.s.o $(BUILD)print.o $(BUILD)string.o   $(BUILD)dmos.o $(BUILD)gic.o $(BUILD)exception.o $(BUILD)exception.s.o
	
	$(TOOL_PREFIX)objdump -x -d -S $(BUILD)kernel.elf > $(BUILD)dis.txt
	$(TOOL_PREFIX)readelf -a $(BUILD)kernel.elf  > $(BUILD)elf.txt
	
	$(TOOL_PREFIX)objcopy -O binary $(BUILD)kernel.elf $(BUILD)kernel.bin

debug:
	qemu-system-aarch64 -m 4G -M virt -cpu cortex-a72 -nographic -kernel $(BUILD)kernel.elf -s -S

run:
	qemu-system-aarch64 -m 4G -M virt -cpu cortex-a72 -nographic -kernel $(BUILD)kernel.elf 


clean:
	rm -f $(BUILD)*.o
	rm -f $(BUILD)*.bin
	rm -f $(BUILD)*.txt
	rm -f $(BUILD)*.elf
