#ifndef  __VGA_H__
#define  __VGA_H__

#include "vga_colors.h"

#define VGA_MEM_BASE 0xB8000
#define VGA_WIDTH 80
#define VGA_HEIGHT 25
void vga_early_init();
#endif
