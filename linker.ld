OUTPUT_FORMAT("elf32-i386")
OUTPUT_ARCH(i386)
ENTRY(_start)

. = 0x00100000;

SECTIONS {
    _text_start = .;
    .text BLOCK(4K) : ALIGN(4K) {
        *(.multiboot)
        *(.text)
        *(.rodata)
    }
    .data BLOCK(4K) : ALIGN(4K) {
	    *(.data)
    }
    .bss BLOCK(4K) : ALIGN(4K) {
        *(.bss)
		*(.bootstrap_stack)
	}
}
