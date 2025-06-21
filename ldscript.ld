ENTRY(main)

SECTIONS {
    .text 0x8000000: {
        LONG(0x20020000)
        LONG(main | 1)
        *(.text)
    }
}
