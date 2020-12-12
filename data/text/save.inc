gUnknown_80B6A34:: @ 80B6A34
	.string "#+Quicksaving your adventure...\n"
	.string "#+Please don~27t turn off the power.\0"
	.align 2, 0

gUnknown_80B6A7C:: @ 80B6A7C
	.string "#+Your adventure has been saved.\0"
	.align 2, 0

gUnknown_80B6AA0:: @ 80B6AA0
	.string "#+Your adventure has been saved.\n"
	.string "#+When you are in a dungeon~2c quicksave\n"
	.string "#+your progress before ending the game.\0"
	.align 2, 0

gUnknown_80B6B14:: @ 80B6B14
	.string "#+The data could not be written.\n"
	.string "#+Please turn off the power and remove\n"
	.string "#+and reinsert the DS Card.\0"
	.align 2, 0

gUnknown_80B6B78:: @ 80B6B78
	.string "#+Save failed.\0"
	.align 2, 0

gUnknown_80B6B88:: @ 80B6B88
	.string "#+Error reading data.\n"
	.string "#+Please turn off the power and reinsert\n"
	.string "#+the DS Game Card.\0"
	.align 2, 0

gUnknown_80B6BDC:: @ 80B6BDC
	.string "#+Your data was not properly saved~2c\n"
	.string "#+so your game cannot be resumed\n"
	.string "#+from your last spot.#P#+Your last outing is considered a defeat.\n"
	.string "#+Before shutting down~2c save in your\n"
	.string "#+team base~2c or quicksave in a dungeon.\0"
	.align 2, 0

gUnknown_80B6CB8:: @ 80B6CB8
	.string "#+You may not resume your dungeon\n"
	.string "#+adventure using this saved data.\n"
	.string "#+Your last outing is considered a defeat.\0"
	.align 2, 0

	.string "pksdir0\0"
	.align 2, 0

	.incbin "baserom.gba", 0xB6D30, 0x60
