ENTRY(loader)

. = 0x00100000;

SECTIONS {
        _text_start = .;
        .text ALIGN(0x1000): {
                *(.text)
        }
}
