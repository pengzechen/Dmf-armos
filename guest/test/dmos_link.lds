/* link.ld */
ENTRY(_start)

SECTIONS
{
    /* 设置内核加载地址  */
    . = 0x70200000;  
    /* . = 0x40080000;   */

    .text : {
        *(.text)
    }

    .rodata : {
        *(.rodata)
    }

    .data : {
        *(.data)
    }

    .bss : {
        *(.bss)
    }
}
