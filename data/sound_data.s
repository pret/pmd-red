	.section .rodata

	.include "include/macros/m4a.inc"

	.include "sound/music_player_table.inc"
	.include "sound/song_table.inc"

	.incbin "baserom.gba", 0x1E8841C
