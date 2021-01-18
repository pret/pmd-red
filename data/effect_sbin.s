	.section .rodata

	.global gEffectFileArchive
gEffectFileArchive: @ 9740000
	.incbin "baserom.gba", 0x1740000, 0x150000
