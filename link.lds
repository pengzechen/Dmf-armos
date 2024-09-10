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
        __guest_bin_start = .;
        *(.data.guest_bin)
        __guest_bin_end = .;
        . = ALIGN((1 << 10));

        __guest_dtb_start = .;
        *(.data.guest_dtb)
        __guest_dtb_end = .;
        . = ALIGN((1 << 10));

        __guest_fs_start = .;
        *(.data.guest_fs)
        __guest_fs_end = .;
        . = ALIGN((1 << 10));

        *(.data)
    }

    . = ALIGN((1<<10));
    __bss_start = .;
    .bss : {
        *(.bss)
    }
    __bss_end = .;

    . = ALIGN((1 << 12));
    ept_L1 = .;
}
