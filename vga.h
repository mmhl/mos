#ifndef  __VGA_H__
#define  __VGA_H__

#include "vga_colors.h"

#define VGA_MEM_BASE 0xB8000
#define VGA_WIDTH 80
#define VGA_HEIGHT 25

#define VGA_COMMAND_PORT 0x3D4
#define VGA_DATA_PORT 0x3D5

#define VGA_POSITION_MEM(y, x) ((VGA_MEM_BASE + ((y*VGA_WIDTH)+x))) /* Calculate address of given y and x parameters */
#define VGA_POSITION_OFFSET(y, x) ((y*VGA_WIDTH)+x)

void vga_early_init();
void vga_clear();
void vga_set_cursor(unsigned short row, unsigned short column);
void vga_putch_at(unsigned char ch, unsigned short y, unsigned short x);


#endif
