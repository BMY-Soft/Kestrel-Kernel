ARCH = x86

AS = as --32
ifeq ($(CC),cc)
CC = gcc -m32
endif
ifndef $(ECHO)
ECHO = ../tools/echo
endif
LD = ld -melf_i386
#OBJCOPY = objcopy --only-section=.text
OBJCOPY = objcopy -R .note -R .comment -R .note.gnu.build-id
#OBJCOPY = objcopy

CFLAGS = -I../include --include ../version.h -DSUPPORT_GRAPHICS=1 -DSUPPORT_GFX=1 -Os -fno-stack-protector -fno-builtin -nostdinc -Wall -Wunused -Wshadow -Wpointer-arith -falign-jumps=1 -falign-loops=1 -falign-functions=1 -Wundef
LDFLAGS = -N -Ttext 8200 --build-id=none
LIBS = -L../3part-lib -lmstr

OBJS = \
	asm.o \
	char-io.o \
	common.o \
	console.o \
	graphics.o \
	io.o \
	kestrel.o \
	panic.o \
	string.o \
	time.o \
	shell/command_table.o \
	shell/common.o \
	shell/interactive.o \
	shell/script.o

first:	kernel.com kernel-size.h

kernel-size.h:	kernel.com
	set dummy `ls -l $^` ; $(ECHO) "#define KERNEL_SIZE $$6" > $@

kernel.com:	kernel
	$(OBJCOPY) -O binary $^ $@
	$(ECHO) -ne "\0260\002\032\0316" >> $@

kernel:	$(OBJS) shell/commands/commands.a
	$(LD) $(LDFLAGS) $^ -o $@ $(LIBS)

asm.o:	asm.s
	$(AS) $^ -o $@

asm.s:	arch/$(ARCH)/asm.S
	$(CC) -E -I. $(CFLAGS) $^ -o $@

shell/commands/commands.a:	shell/commands/Makefile
	make -C shell/commands commands.a

clean:
	rm -f asm.s $(OBJS) kernel kernel.com kernel-size.h
	make -C shell/commands distclean