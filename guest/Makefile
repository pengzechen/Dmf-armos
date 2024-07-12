

TOOL_PREFIX=aarch64-linux-musl-

kernel:
	$(TOOL_PREFIX)gcc -g -c dmos.S -o dmos.s.o
	$(TOOL_PREFIX)gcc -g -c dmos.c -o dmos.o
	$(TOOL_PREFIX)ld -T dmos_link.lds -o kernel.elf dmos.s.o dmos.o
	
	$(TOOL_PREFIX)objdump -x -d -S kernel.elf > dis.txt
	$(TOOL_PREFIX)readelf -a kernel.elf  > elf.txt
	
	$(TOOL_PREFIX)objcopy -O binary kernel.elf testos.bin

run:
	qemu-system-aarch64 -M virt -cpu cortex-a72 -nographic -kernel kernel.elf -s -S


clean:
	rm -f *.o
	rm -f *.bin
	rm -f *.txt
	rm -f *.elf
