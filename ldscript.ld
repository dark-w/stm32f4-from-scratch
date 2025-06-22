ENTRY(reset_handler)

MEMORY {
    rom (rx) : ORIGIN = 0x08000000, LENGTH = 1024k
    ram (rwx) : ORIGIN = 0x20000000, LENGTH = 128k
}

SECTIONS {
    .text : {
        LONG(0x20020000)
        LONG(reset_handler | 1)
        *(.text)
    } > rom

    .rodata : {
        *(.rodata)
    } > rom

    _data_lma = LOADADDR(.data);

    .data : {
        _data_start = .;
        *(.data)
        _data_end = .;
    } > ram AT > rom

    _bss_lma = LOADADDR(.bss);

    .bss : {
        _bss_start = .;
        *(.bss)
        _bss_end = .;
    } > ram AT > rom
}
