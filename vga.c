#include <stddef.h>
#include <stdint.h>
#include "vga.h"
#include "vga_colors.h"
#include "outb.h"

/*
 * TODO: Fix this. This is not a place for cursors and stuff. 
 * Rather place here control CRTC code, and stuff...
 */
uint16_t *vga_mem;
static const uint16_t const *vga_base_addr;

static void vga_cursor_reset() {
        vga_set_cursor(1, 1);
}
void vga_set_cursor(unsigned short row, unsigned short column) {
        unsigned short position = (row*80) + column; // this will surely overflow, FIX IT!

        outb(VGA_COMMAND_PORT, 0x0F); //Set vertical blanking register command
        outb(VGA_DATA_PORT, position & 0xFF);
        outb(VGA_COMMAND_PORT, 0x0E); // Horizontal
        outb(VGA_DATA_PORT, (position >> 8) & 0x0F);
}
void vga_early_init() {
        vga_mem = (uint16_t *)VGA_MEM_BASE;
        vga_base_addr = (uint16_t *)VGA_MEM_BASE;
        uint8_t base_color = VGA_COLOR(VGA_BLACK, VGA_WHITE);
        vga_cursor_reset();
        vga_clear();
        vga_putch_at('H', 0, 0);
        vga_putch_at('E', 0, 1);
        vga_putch_at('L', 0, 2);
        vga_putch_at('L', 0, 3);
        vga_putch_at('O', 0, 4);
}

void vga_clear() {
        uint8_t color = VGA_COLOR(VGA_BLACK, VGA_WHITE);
        for(size_t y = 0; y < VGA_HEIGHT; y++) {
                for(size_t x = 0; x < VGA_WIDTH; x++) {
                        uint16_t i = y*VGA_WIDTH+x;
                        vga_mem[i] = ((uint16_t)(' ') | color << 8) ;
                }
        }
}

void vga_putch_at(unsigned char ch, unsigned short y, unsigned short x) {
        uint16_t *mem = (uint16_t *)(VGA_MEM_BASE);
        mem[VGA_POSITION_OFFSET(y,x)] = (uint16_t)(ch | VGA_COLOR(VGA_BLACK, VGA_WHITE) << 8);
}
