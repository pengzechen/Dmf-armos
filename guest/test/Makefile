

TOOL_PREFIX=aarch64-linux-musl-

BUILD=build/

CFLAGS= -fno-builtin-vsnprintf -fno-builtin-snprintf -fno-builtin-printf -mgeneral-regs-only

kernel:
	$(TOOL_PREFIX)gcc -g -c  $(CFLAGS) dmos.S -o $(BUILD)dmos.s.o
	$(TOOL_PREFIX)gcc -g -c  $(CFLAGS) dmos.c -o $(BUILD)dmos.o
	$(TOOL_PREFIX)gcc -g -c  $(CFLAGS) gic.c -o $(BUILD)gic.o
	$(TOOL_PREFIX)gcc -g -c  $(CFLAGS) exception.c -o $(BUILD)exception.o
	$(TOOL_PREFIX)gcc -g -c  $(CFLAGS) exception.S -o $(BUILD)exception.s.o
	$(TOOL_PREFIX)gcc -g -c  $(CFLAGS) string.c -o $(BUILD)string.o
	$(TOOL_PREFIX)gcc -g -c  $(CFLAGS) print.c -o $(BUILD)print.o


	$(TOOL_PREFIX)ld -T link.lds -o $(BUILD)kernel.elf $(BUILD)print.o $(BUILD)string.o  $(BUILD)dmos.s.o $(BUILD)dmos.o $(BUILD)gic.o $(BUILD)exception.o $(BUILD)exception.s.o
	
	$(TOOL_PREFIX)objdump -x -d -S $(BUILD)kernel.elf > $(BUILD)dis.txt
	$(TOOL_PREFIX)readelf -a $(BUILD)kernel.elf  > $(BUILD)elf.txt
	
	$(TOOL_PREFIX)objcopy -O binary $(BUILD)kernel.elf $(BUILD)testos.bin

debug:
	qemu-system-aarch64 -m 4G -M virt -cpu cortex-a72 -nographic -kernel $(BUILD)kernel.elf -s -S

run:
	qemu-system-aarch64 -m 4G -M virt -cpu cortex-a72 -nographic -kernel $(BUILD)kernel.elf 


clean:
	rm -f $(BUILD)*.o
	rm -f $(BUILD)*.bin
	rm -f $(BUILD)*.txt
	rm -f $(BUILD)*.elf
