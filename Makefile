TARGET=i686-elf
CC= $(TARGET)-gcc
AS= $(TARGET)-as
CFLAGS= -ffreestanding -nostdlib -lgcc -std=c11
OUTPUT= kernel.elf
LINKER_SCRIPT=linker.ld

all: kernel.elf

kernel.elf: kmain.o loader.o vga.o
	$(CC) -T $(LINKER_SCRIPT) $^ -o $@ $(CFLAGS)
%.o: %.c
	$(CC) -c $? -o $@ $(CFLAGS)
%.o: %.s
	$(AS) $? -o $@

.PHONY : clean
clean:
	rm -Rf kernel.elf *.o
