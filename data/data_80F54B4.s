        .section .rodata

	.global gUnknown_80F54B4
gUnknown_80F54B4: @ 80F54B4
	.incbin "baserom.gba", 0xF54B4, 0x40

	.global gUnknown_80F54F4
gUnknown_80F54F4: @ 80F54F4
	.incbin "baserom.gba", 0xF54F4, 0xA0

	.global gWarpScarfActivationChances
gWarpScarfActivationChances: @ 80F5594
@ replacing .incbin "baserom.gba", 0xF5594, 0x28
	.2byte 0, 6, 12, 30, 50, 70, 90, 110, 130, 150, 170, 190, 210, 230, 250, 270, 290, 310, 999, 0

	.global gUnknown_80F55BC
gUnknown_80F55BC: @ 80F55BC
	.incbin "baserom.gba", 0xF55BC, 0x30

	.global gUnknown_80F55EC
gUnknown_80F55EC: @ 80F55EC
	.incbin "baserom.gba", 0xF55EC, 0x30
