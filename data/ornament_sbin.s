	.section .rodata

	.global gOrnamentFileArchive
gOrnamentFileArchive: @ 9E60000
	.incbin "baserom.gba", 0x1E60000, 0x2665C
