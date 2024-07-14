

add-symbol-file build/kernel.elf
target remote localhost:1234
b guest_start
c