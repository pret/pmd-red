	.section .rodata

	.incbin "baserom.gba", 0x300000, 0x500

	.global gUnknown_8300500
gUnknown_8300500: @ 8300500
	.incbin "baserom.gba", 0x300500, 0x7FB00

	.global gUnknown_8380000
gUnknown_8380000: @ 8380000
	.incbin "baserom.gba", 0x380000, 0x30000

	.global gUnknown_83B0000
gUnknown_83B0000: @ 83B0000
	.incbin "baserom.gba", 0x3B0000, 0x160000

	.global gUnknown_8510000
gUnknown_8510000: @ 8510000
	.incbin "baserom.gba", 0x510000
