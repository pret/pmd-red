gSaveTextQuicksaving:: @ 80B6A34
	.string "{CENTER_ALIGN}Quicksaving your adventure...\n"
	.string "{CENTER_ALIGN}Please don{APOSTROPHE}t turn off the power.\0"
	.align 2, 0

gSaveTextYourAdventureHasBeenSaved:: @ 80B6A7C
	.string "{CENTER_ALIGN}Your adventure has been saved.\0"
	.align 2, 0

gSaveTextYourAdventureHasBeenSavedLong:: @ 80B6AA0
	.string "{CENTER_ALIGN}Your adventure has been saved.\n"
	.string "{CENTER_ALIGN}When you are in a dungeon{COMMA} quicksave\n"
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
	.string "{CENTER_ALIGN}Your data was not properly saved{COMMA}\n"
	.string "{CENTER_ALIGN}so your game cannot be resumed\n"
	.string "{CENTER_ALIGN}from your last spot.{EXTRA_MSG}{CENTER_ALIGN}Your last outing is considered a defeat.\n"
	.string "{CENTER_ALIGN}Before shutting down{COMMA} save in your\n"
	.string "{CENTER_ALIGN}team base{COMMA} or quicksave in a dungeon.\0"
	.align 2, 0

gSaveTextMayNotResume:: @ 80B6CB8
	.string "{CENTER_ALIGN}You may not resume your dungeon\n"
	.string "{CENTER_ALIGN}adventure using this saved data.\n"
	.string "{CENTER_ALIGN}Your last outing is considered a defeat.\0"
	.align 2, 0

	.string "pksdir0\0"
	.align 2, 0

	.global gUnknown_80B6D30
gUnknown_80B6D30:
    .2byte 5, 7, 0, 0, 1, 0; .4byte gUnknown_80B6D88
    .2byte 5, 7, 2, 0, 1, 0; .4byte gUnknown_80B6D80
    .2byte 5, 7, 4, 0, 1, 0; .4byte gUnknown_80B6D78
    .2byte 5, 7, 6, 0, 1, 0; .4byte gUnknown_80B6D70

gUnknown_80B6D70:
    .string "LOCAL3\0"
    .align 2, 0

gUnknown_80B6D78:
    .string "LOCAL2\0"
    .align 2, 0

gUnknown_80B6D80:
    .string "LOCAL1\0"
    .align 2, 0

gUnknown_80B6D88:
    .string "LOCAL0\0"
    .align 2, 0
