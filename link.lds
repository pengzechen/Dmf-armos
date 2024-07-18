/* link.ld */
ENTRY(_start)

SECTIONS
{
    /* 设置内核加载地址  */
    /* . = 0x70200000;   */
    . = 0x40080000;  

    .text : {
        *(.text)
    }

    .rodata : {
        *(.rodata)
    }

    .data : {
        . = ALIGN((1 << 10));
        __guset_bin_start = .;
        *(.data.guset_bin)
        *(.data)
        __guset_bin_end = .;
        . = ALIGN((1 << 10));
    }

    .bss : {
        *(.bss)
    }

    . = ALIGN((1 << 14));
    ept_L1 = .;
}
