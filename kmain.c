#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include "vga.h"
#include "vga_colors.h"

#define TERM_BASE 0xB8000
#define VGA_WIDTH 80
#define VGA_HEIGHT 25

size_t term_row;
size_t term_col;
uint16_t *term_buf;

// GRUB dropped us to protected mode 
void kmain() {
    vga_early_init();
    while(1) {

    }
}
