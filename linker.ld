ENTRY(loader)

. = 0x00100000;

SECTIONS {
        _text_start = .;
        .text : {
                *(.text)
        }
        . = ALIGN(4096);

        _rodata_start = .;
        .rodata : {
                *.(text)
        }
        . = ALIGN(4096);

        _data_start = .;
        .data : {
                *(.data)
        }
        . = ALIGN(4096);

        _bss_start = .;
        .bss : {
                *(.bss)
        }
        . = ALIGN(4096);
}
