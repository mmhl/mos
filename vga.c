#include <stddef.h>
#include <stdint.h>
#include "vga.h"
#include "vga_colors.h"

uint16_t *vga_mem;
static const uint16_t const *vga_base_addr;
void vga_early_init() {
        vga_mem = (uint16_t *)VGA_MEM_BASE;
        vga_base_addr = (uint16_t *)VGA_MEM_BASE;
        uint8_t base_color = VGA_COLOR(VGA_BLACK, VGA_WHITE);
        for(size_t y = 0; y < VGA_HEIGHT; y++) {
                for(size_t x = 0; x < VGA_WIDTH; x++) {
                        uint16_t i = y*VGA_WIDTH+x;
                        vga_mem[i] = ((uint16_t)('d') | base_color << 8);
                }
        }
}
