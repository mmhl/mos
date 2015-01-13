#ifndef __OUTB_H__
#define __OUTB_H__
static inline void outb(unsigned short port, unsigned short data) {
        __asm__ volatile ( "outb %0, %1" : : "a"(data), "Nd"(port) );
}
#endif

