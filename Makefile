TOOLCHAIN := $(DEVKITARM)

ifeq ($(CC),)
HOSTCC := gcc
else
HOSTCC := $(CC)
endif

ifeq ($(CXX),)
HOSTCXX := g++
else
HOSTCXX := $(CXX)
endif

ifneq (,$(wildcard $(TOOLCHAIN)/base_tools))
include $(TOOLCHAIN)/base_tools
else
export PATH := $(TOOLCHAIN)/bin:$(PATH)
PREFIX := arm-none-eabi-
OBJCOPY   := $(PREFIX)objcopy
export CC 	 := $(PREFIX)gcc
export AS        := $(PREFIX)as
endif
export CPP       := $(PREFIX)cpp
export LD        := $(PREFIX)ld

ifeq ($(OS),Windows_NT)
EXE := .exe
else
EXE :=
endif


TITLE       := POKE DUNGEON
GAME_CODE   := B24E
MAKER_CODE  := 01
REVISION    := 0

ifeq ($(OS),Windows_NT)
LIB := ../../tools/agbcc/lib/libc.a ../../tools/agbcc/lib/libgcc.a ../../libagbsyscall/libagbsyscall.a
else
LIB := -L ../../tools/agbcc/lib -lc -lgcc -L ../../libagbsyscall -lagbsyscall 
endif


#### Tools ####

SHELL     := /bin/bash -o pipefail
CC1       := tools/agbcc/bin/agbcc
SHA1SUM   := sha1sum -c
GBAGFX    := tools/gbagfx/gbagfx
GBAFIX    := tools/gbafix/gbafix
AIF2PCM   := tools/aif2pcm/aif2pcm
MID2AGB   := tools/mid2agb/mid2agb
PREPROC   := tools/preproc/preproc
SCANINC   := tools/scaninc/scaninc
RAMSCRGEN := tools/ramscrgen/ramscrgen

TOOLDIRS := $(filter-out tools/agbcc tools/binutils,$(wildcard tools/*))
TOOLBASE = $(TOOLDIRS:tools/%=%)
TOOLS = $(foreach tool,$(TOOLBASE),tools/$(tool)/$(tool)$(EXE))


ASFLAGS         := -mcpu=arm7tdmi

override CC1FLAGS += -mthumb-interwork -Wimplicit -Wparentheses -Wunused -Werror -O2 -fhex-asm
CPPFLAGS        := -I tools/agbcc/include -iquote include -nostdinc -undef

#### Files ####

BUILD_NAME = red

ROM := pmd_$(BUILD_NAME).gba
MAP := $(ROM:%.gba=%.map)

BUILD_DIR := build/pmd_$(BUILD_NAME)

C_SOURCES   := $(wildcard src/*.c)
ASM_SOURCES := $(wildcard asm/*.s data/*.s)

C_OBJECTS    := $(addprefix $(BUILD_DIR)/, $(C_SOURCES:%.c=%.o))
ASM_OBJECTS  := $(addprefix $(BUILD_DIR)/, $(ASM_SOURCES:%.s=%.o))
ALL_OBJECTS := $(C_OBJECTS) $(ASM_OBJECTS)

SUBDIRS := $(sort $(dir $(ALL_OBJECTS)))


LD_SCRIPT := $(BUILD_DIR)/ld_script.ld

# Special configurations required for lib files
$(BUILD_DIR)/src/agb_flash.o   : CC1FLAGS := -O -mthumb-interwork
$(BUILD_DIR)/src/agb_flash_1m.o: CC1FLAGS := -O -mthumb-interwork
$(BUILD_DIR)/src/agb_flash_mx.o: CC1FLAGS := -O -mthumb-interwork

$(BUILD_DIR)/src/m4a.o: CC1 := tools/agbcc/bin/old_agbcc

#### Main Rules ####

# Disable dependency scanning when NODEP is used for quick building
# TODO enable when NODEP is fixed
#ifeq ($(NODEP),)
#$(BUILD_DIR)/src/%.o:  C_DEP = $(shell $(SCANINC) -I include src/$(*F).c)
#$(BUILD_DIR)/asm/%.o:  ASM_DEP = $(shell $(SCANINC) asm/$(*F).s)
#$(BUILD_DIR)/data/%.o: ASM_DEP = $(shell $(SCANINC) data/$(*F).s)
#endif

ALL_BUILDS := red

# Available targets
.PHONY: all clean tidy libagbsyscall tools clean-tools $(TOOLDIRS)

MAKEFLAGS += --no-print-directory
# Secondary expansion is required for dependency variables in object rules.
.SECONDEXPANSION:
# Clear the default suffixes
.SUFFIXES:
# Don't delete intermediate files
.SECONDARY:
# Delete files that weren't built properly
.DELETE_ON_ERROR:

.PRECIOUS: %.1bpp %.4bpp %.8bpp %.gbapal %.lz %.rl %.pcm %.bin


# Create build subdirectories

$(shell mkdir -p $(SUBDIRS))

all: $(ROM)

tools: $(TOOLDIRS)

$(TOOLDIRS):
	@$(MAKE) -C $@ CC=$(HOSTCC) CXX=$(HOSTCXX)


compare: all
	@$(SHA1SUM) $(BUILD_NAME).sha1

clean: tidy clean-tools
	$(RM) $(ALL_OBJECTS)

clean-tools:
	@$(foreach tooldir,$(TOOLDIRS),$(MAKE) clean -C $(tooldir);)

tidy:
	$(RM) $(ALL_BUILDS:%=pmd_%{.gba,.elf,.map})
	$(RM) -r build
	@$(MAKE) clean -C libagbsyscall

$(ROM): %.gba: %.elf tools
	$(OBJCOPY) -O binary --gap-fill 0xFF --pad-to 0xA000000 $< $@
	$(GBAFIX) $@ -p -t"$(TITLE)" -c$(GAME_CODE) -m$(MAKER_CODE) -r$(REVISION) --silent

%.elf: $(LD_SCRIPT) $(ALL_OBJECTS) $(LIBC) libagbsyscall
	cd $(BUILD_DIR) && $(LD) -T ld_script.ld -Map ../../$(MAP) -o ../../$@ $(LIB)

$(LD_SCRIPT): ld_script.txt $(BUILD_DIR)/sym_ewram.ld $(BUILD_DIR)/sym_ewram2.ld $(BUILD_DIR)/sym_iwram.ld
	cd $(BUILD_DIR) && sed -e "s#tools/#../../tools/#g" ../../ld_script.txt >ld_script.ld
$(BUILD_DIR)/sym_%.ld: sym_%.txt
	$(CPP) -P $(CPPFLAGS) $< | sed -e "s#tools/#../../tools/#g" > $@

$(C_OBJECTS): $(BUILD_DIR)/%.o: %.c $$(C_DEP)
	@$(CPP) $(CPPFLAGS) $< -o $(BUILD_DIR)/$*.i
	@$(CC1) $(CC1FLAGS) $(BUILD_DIR)/$*.i -o $(BUILD_DIR)/$*.s
	@printf ".text\n\t.align\t2, 0\n" >> $(BUILD_DIR)/$*.s
	$(AS) $(ASFLAGS) -o $@ $(BUILD_DIR)/$*.s

$(BUILD_DIR)/data/%.o: data/%.s $$(ASM_DEP)
	$(PREPROC) $< charmap.txt | $(CPP) -I include | $(AS) $(ASFLAGS) -o $@

$(BUILD_DIR)/%.o: %.s $$(ASM_DEP)
	$(AS) $(ASFLAGS) $< -o $@

libagbsyscall:
	@$(MAKE) -C libagbsyscall TOOLCHAIN=$(TOOLCHAIN)
