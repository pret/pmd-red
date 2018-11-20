	.section .rodata

	.global gMPlayTable
gMPlayTable: @ 9E8665C
	.incbin "baserom.gba", 0x1E8665C, 0x60

	.global gSongTable
gSongTable: @ 9E866BC
	.incbin "baserom.gba", 0x1E866BC
