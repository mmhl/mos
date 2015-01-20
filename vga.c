#include <stddef.h>
#include <stdint.h>
#include "vga.h"
#include "vga_colors.h"
#include "outb.h"

static struct fb_char *framebuffer; /*This is framebuffer, it points directly at VGA base address */
static char banner[6] = "Hello\0";
/*
 * TODO: Fix this. This is not a place for cursors and stuff. 
 * Rather place here control CRTC code, and stuff...
 */
uint16_t *vga_mem;
static const uint16_t const *vga_base_addr;

static void vga_cursor_reset() {
        vga_set_cursor(0, 0);
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
		framebuffer = (struct fb_char *)VGA_MEM_BASE;
        vga_cursor_reset();
        vga_clear();
}

void vga_clear() {
        uint8_t color = VGA_COLOR(VGA_BLACK, VGA_WHITE);
        for(size_t y = 0; y < VGA_HEIGHT; y++) {
                for(size_t x = 0; x < VGA_WIDTH; x++) {
						vga_putch_at(' ', y , x);
                }
        }
}

void vga_putch_at(unsigned char ch, unsigned short y, unsigned short x) {
	struct fb_char chr;
	chr.ch = (uint8_t)ch;
	chr.attr = VGA_COLOR(VGA_WHITE, VGA_BLACK);
	framebuffer[y*VGA_WIDTH+x] = chr;
}

void vga_puts(const char *str, int len, unsigned short y, unsigned short x) {
	int i = 0;
	for(i = 0; i < len ; i++)
		vga_putch_at(str[i], y, x++);
}
