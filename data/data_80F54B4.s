        .section .rodata

	.global gUnknown_80F54B4
gUnknown_80F54B4: @ 80F54B4
    .4byte 0, 0, 0, 1
    .4byte 0, 1, 1, 2
    .4byte 0, 1, 2, 3
    .4byte 1, 2, 3, 3

	.global gUnknown_80F54F4
gUnknown_80F54F4: @ 80F54F4
	.incbin "baserom.gba", 0xF54F4, 0xA0

	.global gWarpScarfActivationChances
gWarpScarfActivationChances: @ 80F5594
@ replacing .incbin "baserom.gba", 0xF5594, 0x28
	.2byte 0, 6, 12, 30, 50, 70, 90, 110, 130, 150, 170, 190, 210, 230, 250, 270, 290, 310, 999, 0

	.global gUnknown_80F55BC
gUnknown_80F55BC: @ 80F55BC
        .2byte 50, 5, 100, 10, 200, 15, 300, 20, 400, 25, 500, 30, 600, 35, 700, 40, 800, 45, 1000, 45, 10000, 9999, -1, 1

	.global gUnknown_80F55EC
gUnknown_80F55EC: @ 80F55EC
        .2byte  0, 9999, 50, 45, 100, 40, 200, 35, 300, 30, 400, 25, 500, 20, 600, 15, 700, 10, 1000, 5, 10000, 1, -1, 1

