ENTRY(Start)

gNumMusicPlayers = 8;
gMaxLines = 0;

MEMORY
{
    EWRAM (rwx) : ORIGIN = 0x2000000, LENGTH = 256K
    IWRAM (rwx) : ORIGIN = 0x3000000, LENGTH = 32K
    ROM    (rx) : ORIGIN = 0x8000000, LENGTH = 32M
}

SECTIONS {

	ewram 0x2000000 (NOLOAD) :

    ALIGN(4)
    {
        ewram_start = .;

        data/sound_data.o(.bss);
        *(ewram_data*);
        *(ewram_lib*);

		ewram_end = .;
    } > EWRAM

    iwram 0x3000000 (NOLOAD) :
    ALIGN(4)
    {
        iwram_start = .;
        *(iwram_data*);
		iwram_end = .;
    } > IWRAM

    /* BEGIN ROM DATA */
    . = 0x8000000;

    .text :
    ALIGN(4)
    {
        asm/crt0.o(.text);
        src/code_80001DC.o(.text);
        src/main_loops.o(.text);
        src/*.o(.text*);
        asm/*.o(.text*);
        *libagbsyscall.a:*.o(.text*);
        *libgcc.a:*.o(.text*);
        *libc.a:*.o(.text*);
        *libnosys.a:*.o(.text*);
    }  > ROM =0

    .rodata :
    ALIGN(4)
    {
        src/*.o(.rodata*);
        data/*.o(.rodata*);
		. = ALIGN(4);
    } > ROM =0

	ewram_init :
    ALIGN(4)
    {
        ewram_init_start = .;

		*(ewram_init*);

		ewram_init_end = .;
    } > EWRAM AT>ROM

	EWRAM_INIT_ROM_START = LOADADDR(ewram_init);

	iwram_init :
	ALIGN(4)
	{
		iwram_init_start = .;

        *(iwram_init*);

		iwram_init_end = .;
    } > IWRAM AT>ROM

	IWRAM_INIT_ROM_START = LOADADDR(iwram_init);

	iwram_lib (NOLOAD) :
    ALIGN(4)
    {
		end = .; /* This is needed for the libc.a function _sbrk */
		. = 0x2090;
        gUnknown_3004000 = .; /* Used by sub_80001E0 */
    } > IWRAM

    sound_data :
    ALIGN(4)
    {
        sound/songs/*.o(.rodata);
    } > ROM =0

    /* DWARF 2 sections */
    .debug_aranges  0 : { *(.debug_aranges) }
    .debug_pubnames 0 : { *(.debug_pubnames) }
    .debug_info     0 : { *(.debug_info) }
    .debug_abbrev   0 : { *(.debug_abbrev) }
    .debug_line     0 : { *(.debug_line) }
    .debug_frame    0 : { *(.debug_frame) }
    .debug_str      0 : { *(.debug_str) }
    .debug_loc      0 : { *(.debug_loc) }
    .debug_macinfo  0 : { *(.debug_macinfo) }

    /* Discard everything not specifically mentioned above. */
    /DISCARD/ :
    {
        *(*);
    }
}
