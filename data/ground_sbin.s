	.section .rodata

	.global gGroundFileArchive
gGroundFileArchive: @ 9890000
	.incbin "baserom.gba", 0x1890000, 0x5D0000
