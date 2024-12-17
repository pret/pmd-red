	.section .rodata

	#include "asm/macros/m4a.inc"
	
.align 2
.string "pksdir0\0"
.string "pksdir0\0"
.string "pksdir0\0"
.string "pksdir0\0"

	#include "../sound/voice_groups.inc"
	#include "../sound/gb_waves.inc"
	#include "../sound/music_player_table.inc"
	#include "../sound/song_table.inc"
	#include "../sound/waves.inc"
