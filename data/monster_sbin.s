	.section .rodata

	.global gMonsterFileArchive
gMonsterFileArchive: @ 8510000
	.incbin "baserom.gba", 0x510000, 0x1230000
