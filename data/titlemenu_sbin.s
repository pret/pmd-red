	.section .rodata

	.global gTitleMenuFileArchive
gTitleMenuFileArchive: @ 8380000
	.incbin "baserom.gba", 0x380000, 0x22E74
