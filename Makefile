OBJECTS = loader.o kmain.o
CC = gcc
CFLAGS = -m32 -nostdlib -nostdinc -fno-builtin -fno-stack-protector \
	 -nostartfiles -nodefaultlibs -Wall -Wextra -Werror -c 
LINKER_SCRIPT= linker.ld
LDFLAGS = -T $(LINKER_SCRIPT) -melf_i386
AS = nasm
ASFLAGS = -f elf


all: kernel

kernel: $(OBJECTS)
	@echo Linking  $(OBJECTS)
	ld $(LDFLAGS) $(OBJECTS) -o kernel.elf

iso: kernel.elf
	mv -v kernel.elf out/boot/kernel.elf
	genisoimage -R \
		    -b boot/grub/stage2_eltorito \
		    -no-emul-boot \
		    -boot-load-size 4 \
		    -A mOS \
		    -input-charset utf8 \
		    -quiet \
		    -boot-info-table \
		    -o bochs/mos.iso \
		    out



%.o: %.c
	@echo Compiling...
	$(CC) $(CFLAGS) $< -o $@
%.o: %.s
	@echo Assembling...
	$(AS) $(ASFLAGS) $< -o $@

clean:
	rm -rf *.o out/boot/kernel.elf bochs/mos.iso
