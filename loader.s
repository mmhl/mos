global loader 

extern kmain
MBOOT_MAGIC_NUMBER equ 0x1BADB002
MBOOT_FLAGS equ 0x0
MBOOT_CHECKSUM equ -(MBOOT_MAGIC_NUMBER + MBOOT_FLAGS)

section .text:
        align 4
        dd MBOOT_MAGIC_NUMBER
        dd MBOOT_FLAGS
        dd MBOOT_CHECKSUM
        
loader:
        mov eax, 0xC0C0C0C0
        mov esp, stack_end ; setup stack pointer at the end of stack
        ;call kmain
.loop:
        jmp .loop


section .bss:
        align 16 ; after gcc 4.5 stack must be aligned to 16 bytes
stack_begin:
        resb 4096 ; 4KiB 
stack_end:


