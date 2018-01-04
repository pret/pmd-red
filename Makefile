AS      := $(DEVKITARM)/bin/arm-none-eabi-as
ASFLAGS := -mcpu=arm7tdmi

CC1             := tools/agbcc/bin/agbcc
override CFLAGS += -mthumb-interwork -Wimplicit -Wparentheses -Wunused -Werror -O2 -fhex-asm

CPP      := $(DEVKITARM)/bin/arm-none-eabi-cpp
CPPFLAGS := -I tools/agbcc/include -iquote include -nostdinc -undef

LD      := $(DEVKITARM)/bin/arm-none-eabi-ld

OBJCOPY := $(DEVKITARM)/bin/arm-none-eabi-objcopy

LIBGCC := tools/agbcc/lib/libgcc.a
LIBC := tools/agbcc/lib/libc.a

MD5 := md5sum -c

GFX := tools/gbagfx/gbagfx
AIF := tools/aif2pcm/aif2pcm
MID := tools/mid2agb/mid2agb
SCANINC := tools/scaninc/scaninc
PREPROC := tools/preproc/preproc
RAMSCRGEN := tools/ramscrgen/ramscrgen

# Clear the default suffixes.
.SUFFIXES:

# Secondary expansion is required for dependency variables in object rules.
.SECONDEXPANSION:

.PRECIOUS: %.1bpp %.4bpp %.8bpp %.gbapal %.lz %.rl %.pcm %.bin

.PHONY: all clean tidy

C_SRCS := $(wildcard src/*.c)
C_OBJS := $(C_SRCS:%.c=%.o)

ASM_SRCS := $(wildcard asm/*.s)
ASM_OBJS := $(ASM_SRCS:%.s=%.o)

DATA_ASM_SRCS := $(wildcard data/*.s)
DATA_ASM_OBJS := $(DATA_ASM_SRCS:%.s=%.o)

OBJS := $(C_OBJS) $(ASM_OBJS) $(DATA_ASM_OBJS)

all: pmd_red.gba

# For contributors to make sure a change didn't affect the contents of the ROM.

compare: all
	@$(MD5) rom.md5

clean: tidy

tidy:
	rm -f pmd_red.gba pmd_red.elf pmd_red.map
	rm -f $(ASM_OBJS)
	rm -f $(DATA_ASM_OBJS)
	rm -f $(C_OBJS)
	rm -f $(ASM_OBJS)
	rm -f $(DATA_ASM_OBJS)
	rm -f $(C_SRCS:%.c=%.i)
	rm -f $(C_SRCS:%.c=%.s)
	rm -f *.ld

src/agb_flash.o: CFLAGS := -O -mthumb-interwork
src/agb_flash_1m.o: CFLAGS := -O -mthumb-interwork
src/agb_flash_mx.o: CFLAGS := -O -mthumb-interwork

$(C_OBJS): %.o : %.c
	@$(CPP) $(CPPFLAGS) $< -o $*.i
	@$(CC1) $(CFLAGS) $*.i -o $*.s
	@printf ".text\n\t.align\t2, 0\n" >> $*.s
	$(AS) $(ASFLAGS) -o $@ $*.s

$(ASM_OBJS): %.o: %.s
	$(AS) $(ASFLAGS) -o $@ $<

$(DATA_ASM_OBJS): %.o: %.s
	$(AS) $(ASFLAGS) -o $@ $<

sym_ewram.ld: sym_ewram.txt
	$(RAMSCRGEN) ewram_data sym_ewram.txt ENGLISH >$@

sym_ewram2.ld: sym_ewram2.txt
	$(RAMSCRGEN) ewram_data sym_ewram2.txt ENGLISH >$@

sym_iwram.ld: sym_iwram.txt
	$(RAMSCRGEN) iwram_data sym_iwram.txt ENGLISH >$@

ld_script.ld: ld_script.txt sym_ewram.ld sym_ewram2.ld sym_iwram.ld
	sed -f ld_script.sed ld_script.txt >ld_script.ld

pmd_red.elf: ld_script.ld $(OBJS) $(LIBC)
	$(LD) -T ld_script.ld -Map pmd_red.map -o $@ $(OBJS) $(LIBC) $(LIBGCC)

pmd_red.gba: pmd_red.elf
	$(OBJCOPY) -O binary --gap-fill 0xFF --pad-to 0xA000000 $< $@
