.set MULTIBOOT_FLAG_ALIGN, 1<<0
.set MULTIBOOT_FLAG_MEMINFO, 1<<1
.set MULTIBOOT_FLAGS, 0x0
.set MULTIBOOT_MAGIC, 0x1BADB002
.set MULTIBOOT_CHECKSUM, -(MULTIBOOT_MAGIC + MULTIBOOT_FLAGS)


.section .mutliboot
.align 4
.long MULTIBOOT_MAGIC
.long MULTIBOOT_FLAGS
.long MULTIBOOT_CHECKSUM


# aw - allocatable writable @nobits no data here
.section .bootstrap_stack, "aw", @nobits 
stack_bottom:
        .skip 4096
stack_top:



.section .text
.global _start
.type _start, @function
_start:
        movl $stack_top, %esp #setup stack
        mov $0xC0C0C0, %eax
        call kmain # c-code entry point
        cli
        hlt
