	.section .rodata

	.string "pksdir0\0"

	.global gBaseKindTable
gBaseKindTable: @ 80B690C
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x19, 0x00, 0x00, 0x00
        .byte 0x01, 0x00, 0x00, 0x00
        .byte 0x34, 0x00, 0x00, 0x00
        .byte 0x02, 0x00, 0x00, 0x00
        .byte 0x85, 0x00, 0x00, 0x00
        .byte 0x03, 0x00, 0x00, 0x00
        .byte 0x45, 0x01, 0x00, 0x00
        .byte 0x04, 0x00, 0x00, 0x00
        .byte 0x07, 0x00, 0x00, 0x00
        .byte 0x05, 0x00, 0x00, 0x00
        .byte 0x9e, 0x00, 0x00, 0x00
        .byte 0x06, 0x00, 0x00, 0x00
        .byte 0x1b, 0x01, 0x00, 0x00
        .byte 0x07, 0x00, 0x00, 0x00
        .byte 0x36, 0x00, 0x00, 0x00
        .byte 0x08, 0x00, 0x00, 0x00
        .byte 0x04, 0x00, 0x00, 0x00
        .byte 0x09, 0x00, 0x00, 0x00
        .byte 0x18, 0x01, 0x00, 0x00
        .byte 0x0a, 0x00, 0x00, 0x00
        .byte 0x9b, 0x00, 0x00, 0x00
        .byte 0x0b, 0x00, 0x00, 0x00
        .byte 0x68, 0x00, 0x00, 0x00
        .byte 0x0c, 0x00, 0x00, 0x00
        .byte 0x42, 0x00, 0x00, 0x00
        .byte 0x0d, 0x00, 0x00, 0x00
        .byte 0x01, 0x00, 0x00, 0x00
        .byte 0x0e, 0x00, 0x00, 0x00
        .byte 0x98, 0x00, 0x00, 0x00
        .byte 0x0f, 0x00, 0x00, 0x00
        .byte 0x15, 0x01, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00

	.global gTalkKindTable
gTalkKindTable: @ 80B6994
        .byte 0x01, 0x00, 0x00, 0x00
        .byte 0x07, 0x00, 0x00, 0x00
        .byte 0x01, 0x00, 0x00, 0x00
        .byte 0x9e, 0x00, 0x00, 0x00
        .byte 0x03, 0x00, 0x00, 0x00
        .byte 0x18, 0x01, 0x00, 0x00
        .byte 0x03, 0x00, 0x00, 0x00
        .byte 0x98, 0x00, 0x00, 0x00
        .byte 0x02, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00

	.global gPMDBuildVersion
gPMDBuildVersion: @ 80B69BC
        .string "PKDi ver 1.0 [Apr 28 2006] 16:37:54\0"
        .align 2,0

        .global titlen0_text
        titlen0_text:
        .string "titlen0\0"
        .align 2,0

        .global titlen1_text
        titlen1_text:
        .string "titlen1\0"
        .align 2,0

        .global titlen2_text
        titlen2_text:
        .string "titlen2\0"
        .align 2,0

	.global gLoadScreenBackgroundFileNames
gLoadScreenBackgroundFileNames: @ 80B69F8
        .4byte titlen0_text
        .4byte titlen1_text
        .4byte titlen2_text

        .global titlen0p_text
        titlen0p_text:
        .string "titlen0p\0"
        .align 2,0

        .global titlen1p_text
        titlen1p_text:
        .string "titlen1p\0"
        .align 2,0

        .global titlen2p_text
        titlen2p_text:
        .string "titlen2p\0"
        .align 2,0

	.global gLoadScreenBackgroundPaletteFileNames
gLoadScreenBackgroundPaletteFileNames: @ 80B6A28
        .4byte titlen0p_text
        .4byte titlen1p_text
        .4byte titlen2p_text

gSaveTextQuicksaving:: @ 80B6A34
	.string "{CENTER_ALIGN}Quicksaving your adventure...\n"
	.string "{CENTER_ALIGN}Please don't turn off the power.\0"
	.align 2, 0

gSaveTextYourAdventureHasBeenSaved:: @ 80B6A7C
	.string "{CENTER_ALIGN}Your adventure has been saved.\0"
	.align 2, 0

gSaveTextYourAdventureHasBeenSavedLong:: @ 80B6AA0
	.string "{CENTER_ALIGN}Your adventure has been saved.\n"
	.string "{CENTER_ALIGN}When you are in a dungeon, quicksave\n"
	.string "{CENTER_ALIGN}your progress before ending the game.\0"
	.align 2, 0

gSaveTextTheDataCouldNotBeWritten:: @ 80B6B14
	.string "{CENTER_ALIGN}The data could not be written.\n"
	.string "{CENTER_ALIGN}Please turn off the power and remove\n"
	.string "{CENTER_ALIGN}and reinsert the DS Card.\0"
	.align 2, 0

gSaveTextFailed:: @ 80B6B78
	.string "{CENTER_ALIGN}Save failed.\0"
	.align 2, 0

gSaveTextError:: @ 80B6B88
	.string "{CENTER_ALIGN}Error reading data.\n"
	.string "{CENTER_ALIGN}Please turn off the power and reinsert\n"
	.string "{CENTER_ALIGN}the DS Game Card.\0"
	.align 2, 0

gSaveTextCantResume:: @ 80B6BDC
	.string "{CENTER_ALIGN}Your data was not properly saved,\n"
	.string "{CENTER_ALIGN}so your game cannot be resumed\n"
	.string "{CENTER_ALIGN}from your last spot.{EXTRA_MSG}{CENTER_ALIGN}Your last outing is considered a defeat.\n"
	.string "{CENTER_ALIGN}Before shutting down, save in your\n"
	.string "{CENTER_ALIGN}team base, or quicksave in a dungeon.\0"
	.align 2, 0

gSaveTextMayNotResume:: @ 80B6CB8
	.string "{CENTER_ALIGN}You may not resume your dungeon\n"
	.string "{CENTER_ALIGN}adventure using this saved data.\n"
	.string "{CENTER_ALIGN}Your last outing is considered a defeat.\0"