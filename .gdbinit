

add-symbol-file build/kernel.elf
target remote localhost:1234
add-symbol-file guest/nimbos/kernel/target/aarch64/debug/nimbos