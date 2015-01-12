global loader 
MBOOT_MAGIC_NUMBER equ 0x1BADB002
MBOOT_FLAGS equ 0x0
MBOOT_CHECKSUM equ -(MBOOT_MAGIC_NUMBER + MBOOT_FLAGS)

section .text:
        align 4
        dd MBOOT_MAGIC_NUMBER
        dd MBOOT_FLAGS
        dd MBOOT_CHECKSUM
        
loader:
        mov eax, 0xCAFEBABE
.loop:
        jmp .loop


