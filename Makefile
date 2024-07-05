

TOOL_PREFIX=aarch64-linux-musl-

BUILD_DIR=build

INCLUDE = -I ./include \
	      -I /home/ajax/rust/usb/first_state/aarch64-linux-musl-cross/aarch64-linux-musl/include

n = -nostdlib -nostdinc -fno-stack-protector

CFLAGS = -g -c -O0 -fno-pie  -mgeneral-regs-only \
	 -fno-builtin-vsnprintf -fno-builtin-snprintf -fno-builtin-printf

all: $(BUILD_DIR) $(BUILD_DIR)/kernel.elf

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

#  kernel main
$(BUILD_DIR)/main.o: main.c
	$(TOOL_PREFIX)gcc $(CFLAGS) main.c $(INCLUDE) -o $(BUILD_DIR)/main.o

#  boot 
$(BUILD_DIR)/boot.s.o: boot/boot.S
	$(TOOL_PREFIX)gcc $(CFLAGS) boot/boot.S $(INCLUDE) -o $(BUILD_DIR)/boot.s.o

#  exception
$(BUILD_DIR)/exception.o: exception/exception.c
	$(TOOL_PREFIX)gcc $(CFLAGS) exception/exception.c $(INCLUDE) -o $(BUILD_DIR)/exception.o

$(BUILD_DIR)/exception.s.o: exception/exception.S
	$(TOOL_PREFIX)gcc $(CFLAGS) exception/exception.S $(INCLUDE) -o $(BUILD_DIR)/exception.s.o

#  io
$(BUILD_DIR)/io.o: io/io.c
	$(TOOL_PREFIX)gcc $(CFLAGS) io/io.c $(INCLUDE) -o $(BUILD_DIR)/io.o
$(BUILD_DIR)/printf.o: io/printf.c
	$(TOOL_PREFIX)gcc $(CFLAGS) io/printf.c $(INCLUDE) -o $(BUILD_DIR)/printf.o

#  mem
$(BUILD_DIR)/mmu.s.o: mem/mmu.S
	$(TOOL_PREFIX)gcc $(CFLAGS) mem/mmu.S $(INCLUDE) -o $(BUILD_DIR)/mmu.s.o
$(BUILD_DIR)/page.o: mem/page.c
	$(TOOL_PREFIX)gcc $(CFLAGS) mem/page.c $(INCLUDE) -o $(BUILD_DIR)/page.o
$(BUILD_DIR)/string.o: mem/string.c
	$(TOOL_PREFIX)gcc $(CFLAGS) mem/string.c $(INCLUDE) -o $(BUILD_DIR)/string.o


$(BUILD_DIR)/kernel.elf: $(BUILD_DIR)/main.o $(BUILD_DIR)/boot.s.o $(BUILD_DIR)/exception.s.o $(BUILD_DIR)/exception.o $(BUILD_DIR)/io.o $(BUILD_DIR)/printf.o $(BUILD_DIR)/mmu.s.o $(BUILD_DIR)/page.o $(BUILD_DIR)/string.o 
	$(TOOL_PREFIX)ld -T dmos_link.lds -o $(BUILD_DIR)/kernel.elf \
	$(BUILD_DIR)/boot.s.o \
	$(BUILD_DIR)/main.o \
	$(BUILD_DIR)/exception.s.o \
	$(BUILD_DIR)/exception.o \
	$(BUILD_DIR)/io.o \
	$(BUILD_DIR)/printf.o \
	$(BUILD_DIR)/mmu.s.o \
	$(BUILD_DIR)/page.o \
	$(BUILD_DIR)/string.o 


deasm: $(BUILD_DIR)/kernel.elf
	$(TOOL_PREFIX)objdump -x -d -S $(BUILD_DIR)/kernel.elf > $(BUILD_DIR)/dis.txt
	$(TOOL_PREFIX)readelf -a $(BUILD_DIR)/kernel.elf > $(BUILD_DIR)/elf.txt
	$(TOOL_PREFIX)objcopy -O binary $(BUILD_DIR)/kernel.elf $(BUILD_DIR)/kernel.bin


QEMU_ARGS =

debug: deasm
	qemu-system-aarch64 -M virt -cpu cortex-a72 $(QEMU_ARGS) -nographic -kernel $(BUILD_DIR)/kernel.bin -s -S

run:
	qemu-system-aarch64 -M virt -cpu cortex-a72 $(QEMU_ARGS) -nographic -kernel $(BUILD_DIR)/kernel.bin


clean:
	rm -f build/*.o
	rm -f build/*.bin
	rm -f build/*.txt
	rm -f build/*.elf
