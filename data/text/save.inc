gSaveTextQuicksaving:: @ 80B6A34
	.string "#+Quicksaving your adventure...\n"
	.string "#+Please don{APOSTROPHE}t turn off the power.\0"
	.align 2, 0

gSaveTextYourAdventureHasBeenSaved:: @ 80B6A7C
	.string "#+Your adventure has been saved.\0"
	.align 2, 0

gSaveTextYourAdventureHasBeenSavedLong:: @ 80B6AA0
	.string "#+Your adventure has been saved.\n"
	.string "#+When you are in a dungeon{COMMA} quicksave\n"
	.string "#+your progress before ending the game.\0"
	.align 2, 0

gSaveTextTheDataCouldNotBeWritten:: @ 80B6B14
	.string "#+The data could not be written.\n"
	.string "#+Please turn off the power and remove\n"
	.string "#+and reinsert the DS Card.\0"
	.align 2, 0

gSaveTextFailed:: @ 80B6B78
	.string "#+Save failed.\0"
	.align 2, 0

gSaveTextError:: @ 80B6B88
	.string "#+Error reading data.\n"
	.string "#+Please turn off the power and reinsert\n"
	.string "#+the DS Game Card.\0"
	.align 2, 0

gSaveTextCantResume:: @ 80B6BDC
	.string "#+Your data was not properly saved{COMMA}\n"
	.string "#+so your game cannot be resumed\n"
	.string "#+from your last spot.#P#+Your last outing is considered a defeat.\n"
	.string "#+Before shutting down{COMMA} save in your\n"
	.string "#+team base{COMMA} or quicksave in a dungeon.\0"
	.align 2, 0

gSaveTextMayNotResume:: @ 80B6CB8
	.string "#+You may not resume your dungeon\n"
	.string "#+adventure using this saved data.\n"
	.string "#+Your last outing is considered a defeat.\0"
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
