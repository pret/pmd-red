AS      := $(DEVKITARM)/bin/arm-none-eabi-as
ASFLAGS := -mcpu=arm7tdmi

CC1             := ../tools/agbcc/bin/agbcc
override CFLAGS += -O2 -fhex-asm

CPP      := cpp
CPPFLAGS := -I ../tools/agbcc/include -I libc/include -iquote libm/common -D__thumb__ -D__GNUC__ -nostdinc -undef

AR      := ar
ARFLAGS := "-rc"

OBJCOPY := $(DEVKITARM)/bin/arm-none-eabi-objcopy

LIBC_OBJS := \
		libc/string/memcpy.o \
		libc/string/memset.o \
		libc/stdio/sprintf.o \
		libc/string/strcat.o \
		libc/string/strcmp.o \
		libc/string/strcpy.o \
		libc/string/strlen.o \
		libc/string/strncpy.o \
		libc/stdio/vfprintf.o \
		libc/stdio/vsprintf.o \
		libc/stdio/wsetup.o \
		libc/stdlib/dtoa.o \
		libc/stdio/fflush.o \
		libc/stdio/findfp.o \
		libc/stdio/fvwrite.o \
		libc/stdio/fwalk.o \
		libc/locale/locale.o \
		libc/stdio/makebuf.o \
		libc/stdlib/mbtowc_r.o \
		libc/string/memchr.o \
		libc/string/memmove.o \
		libc/stdlib/mlock.o \
		libc/stdlib/mprec.o \
		libc/reent/sbrkr.o \
		libc/stdio/stdio.o \
		libc/sys/arm/syscalls.o \
		libc/reent/writer.o \
		libc/reent/closer.o \
		libc/errno/errno.o \
		libc/reent/fstatr.o \
		libc/stdlib/abort.o \
		libc/sys/arm/libcfunc.o \
		libc/reent/lseekr.o \
		libc/reent/readr.o \
		libc/reent/impure.o

MALLOCR_OBJS := \
		libc/stdlib/mallocr_MALLOC.o \
		libc/stdlib/mallocr_CALLOC.o \
		libc/stdlib/mallocr_FREE.o \

LIBM_OBJS := \
		libm/math/s_isinf.o \
		libm/math/s_isnan.o

all: libc.a libm.a

clean: tidy

tidy:
	rm -f libc.a libc.m
	rm -f $(LIBC_OBJS:%.o=%.i) $(LIBM_OBJS:%.o=%.i) $(MALLOCR_OBJS:%.o=%.i)
	rm -f $(LIBC_OBJS:%.o=%.s) $(LIBM_OBJS:%.o=%.s) $(MALLOCR_OBJS:%.o=%.s)
	rm -f $(LIBC_OBJS) $(LIBM_OBJS) $(MALLOCR_OBJS)

libc/stdlib/mallocr_%.o: CPPFLAGS += -DINTERNAL_NEWLIB -DDEFINE_%

$(LIBC_OBJS) $(LIBM_OBJS): %.o : %.c
	@$(CPP) $(CPPFLAGS) $< -o $*.i
	@$(CC1) $(CFLAGS) $*.i -o $*.s
	@printf ".text\n\t.align\t2, 0\n" >> $*.s
	$(AS) $(ASFLAGS) -o $@ $*.s

$(MALLOCR_OBJS): CPPFLAGS += -DINTERNAL_NEWLIB -DDEFINE_$(@:libc/stdlib/mallocr_%.o=%)
$(MALLOCR_OBJS): libc/stdlib/mallocr.c
	@$(CPP) $(CPPFLAGS) $< -o $*.i
	@$(CC1) $(CFLAGS) $*.i -o $*.s
	@printf ".text\n\t.align\t2, 0\n" >> $*.s
	$(AS) $(ASFLAGS) -o $@ $*.s

libc.a: $(LIBC_OBJS) $(MALLOCR_OBJS)
	$(AR) $(ARFLAGS) $@ $^

libm.a: $(LIBM_OBJS)
	$(AR) $(ARFLAGS) $@ $^
