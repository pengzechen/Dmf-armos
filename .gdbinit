

add-symbol-file build/kernel.elf
target remote localhost:1234
add-symbol-file guest/test/build/kernel.elf