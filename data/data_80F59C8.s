#include "constants/status.h"
        .section .rodata

	#.incbin "baserom.gba", 0xF59C4, 0x4
	.global gUnknown_80F59C8
gUnknown_80F59C8: @ 80F59C8
	.incbin "baserom.gba", 0xF59C8, 0x348

	.global gNaturePowerMoveTable
gNaturePowerMoveTable: @ 80F5D10
	.incbin "baserom.gba", 0xF5D10, 0x260

	.global gUnknown_80F5F70
gUnknown_80F5F70: @ 80F5F70
	.incbin "baserom.gba", 0xF5F70, 0x3C

	.global gUnknown_80F5FAC
gUnknown_80F5FAC: @ 80F5FAC
	.incbin "baserom.gba", 0xF5FAC, 0x130

	.global gUnknown_80F60DC
gUnknown_80F60DC: @ 80F60DC
	.incbin "baserom.gba", 0xF60DC, 0x1C

	.global gUnknown_80F60F8
gUnknown_80F60F8: @ 80F60F8
@ replacing .incbin "baserom.gba", 0x000f60f8, 0x8
        .string "banrpal\0"

	.global gUnknown_80F6100
gUnknown_80F6100: @ 80F6100
@ replacing .incbin "baserom.gba", 0x000f6100, 0x8
        .string "banfont\0"

	.global gUnknown_80F6108
gUnknown_80F6108: @ 80F6108
@ replacing .incbin "baserom.gba", 0x000f6108, 0x4
        .byte 0x23, 0x00, 0x00, 0x00

	.global gUnknown_80F610C
gUnknown_80F610C: @ 80F610C
@ replacing .incbin "baserom.gba", 0x000f610c, 0x4
        .byte 0x42, 0x00, 0x00, 0x00

	.global gUnknown_80F6110
gUnknown_80F6110: @ 80F6110
@ replacing .incbin "baserom.gba", 0x000f6110, 0x8
        .string "%s%c%cF\0"

	.global gUnknown_80F6118
gUnknown_80F6118: @ 80F6118
@ replacing .incbin "baserom.gba", 0x000f6118, 0x8
        .string "%s%cF\0"
        .align 2,0

	.global gUnknown_80F6120
gUnknown_80F6120: @ 80F6120
@ replacing .incbin "baserom.gba", 0x000f6120, 0x88
.byte 0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x20, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0x0f, 0x00, 0x00, 0x00, 0xf0, 0x04, 0x00, 0x00, 0x00, 0x1c, 0x00, 0x00, 0x00
.byte 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0xff, 0x08, 0x00, 0x00, 0x00, 0x18, 0x00, 0x00, 0x00, 0xff, 0xff, 0x0f, 0x00, 0x00, 0x00, 0xf0, 0xff, 0x0c, 0x00, 0x00, 0x00, 0x14, 0x00, 0x00, 0x00
.byte 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0x10, 0x00, 0x00, 0x00, 0x10, 0x00, 0x00, 0x00, 0xff, 0x0f, 0x00, 0x00, 0x00, 0xf0, 0xff, 0xff, 0x14, 0x00, 0x00, 0x00, 0x0c, 0x00, 0x00, 0x00
.byte 0xff, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0x18, 0x00, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x0f, 0x00, 0x00, 0x00, 0xf0, 0xff, 0xff, 0xff, 0x1c, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00
.string "pksdir0\0"

	.global gUnknown_80F61A8
gUnknown_80F61A8: @ 80F61A8
@ replacing .incbin "baserom.gba", 0x000f61a8, 0x8
        .string "itempat\0"

	.global gUnknown_80F61B0
gUnknown_80F61B0: @ 80F61B0
@ replacing .incbin "baserom.gba", 0x000f61b0, 0x8
        .string "etcfont\0"

	.global gUnknown_80F61B8
gUnknown_80F61B8: @ 80F61B8
@ replacing .incbin "baserom.gba", 0x000f61b8, 0xc
        .string "etcfonta\0"
        .align 2,0

	.global gUnknown_80F61C4
gUnknown_80F61C4: @ 80F61C4
@ replacing .incbin "baserom.gba", 0x000f61c4, 0x8
        .string "levfont\0"

	.global gUnknown_80F61CC
gUnknown_80F61CC: @ 80F61CC
@ replacing .incbin "baserom.gba", 0x000f61cc, 0x8
        .string "hp5font\0"

	.global gUnknown_80F61D4
gUnknown_80F61D4: @ 80F61D4
@ replacing .incbin "baserom.gba", 0x000f61d4, 0x8
        .string "colvec\0"
        .align 2,0

	.global gUnknown_80F61DC
gUnknown_80F61DC: @ 80F61DC
@ replacing .incbin "baserom.gba", 0x000f61dc, 0x10
        .string "trappat\0"
        .string "pksdir0\0"

	.global gUnknown_80F61EC
gUnknown_80F61EC: @ 80F61EC
@ replacing .incbin "baserom.gba", 0x000f61ec, 0x30
        .byte 0xfc, 0xff, 0xfc, 0xff, 0xf8, 0xff, 0xfc, 0xff, 0xf0, 0xff, 0xfc, 0xff, 0xf0, 0xff, 0xfc, 0xff, 0xf0, 0xff, 0xfc, 0xff, 0xf0, 0xff, 0xfc, 0xff, 0xfc, 0xff, 0xfc, 0xff, 0xf8, 0xff, 0xfc, 0xff
        .byte 0xf0, 0xff, 0xf8, 0xff, 0xf0, 0xff, 0xf8, 0xff, 0xf0, 0xff, 0xf8, 0xff, 0xf0, 0xff, 0xf8, 0xff

	.global gUnknown_80F621C
gUnknown_80F621C: @ 80F621C
@ replacing .incbin "baserom.gba", 0x000f621c, 0x8
        .byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00

	.global gUnknown_80F6224
gUnknown_80F6224: @ 80F6224
@ replacing .incbin "baserom.gba", 0x000f6224, 0x88
        .byte 0x00, 0x02, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x02, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x03, 0x02, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00
        .byte 0x01, 0x00, 0x00, 0x00, 0x23, 0x02, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x23, 0x02, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x23, 0x02, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0x02, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x02, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00
        .byte 0x0a, 0x02, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x2a, 0x02, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x2a, 0x02, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00
        .byte 0x02, 0x00, 0x00, 0x00, 0x2a, 0x02, 0x00, 0x00

	.global gUnknown_80F62AC
gUnknown_80F62AC: @ 80F62AC
@ replacing .incbin "baserom.gba", 0x000f62ac, 0x4
.byte 0x00, 0x00, 0x00, 0x00

	.global gUnknown_80F62B0
gUnknown_80F62B0: @ 80F62B0
@ replacing .incbin "baserom.gba", 0x000f62b0, 0x60
.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x00, 0x0f, 0x00, 0x1a, 0x00, 0x05, 0x00, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00
.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00

	.global gUnknown_80F6310
gUnknown_80F6310: @ 80F6310
@ replacing .incbin "baserom.gba", 0x000f6310, 0x60
.byte 0x00, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x02, 0x00, 0x03, 0x00, 0x06, 0x00, 0x07, 0x00, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00
.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00

	.global gUnknown_80F6370
gUnknown_80F6370: @ 80F6370
@ replacing .incbin "baserom.gba", 0x000f6370, 0x60
.byte 0x00, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x02, 0x00, 0x03, 0x00, 0x06, 0x00, 0x07, 0x00, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00
.byte 0x0a, 0x00, 0x04, 0x00, 0x11, 0x00, 0x02, 0x00, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x02, 0x00, 0x0d, 0x00, 0x1a, 0x00, 0x06, 0x00
.byte 0x06, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00

	.global gUnknown_80F63D0
gUnknown_80F63D0: @ 80F63D0
@ replacing .incbin "baserom.gba", 0x000f63d0, 0x60
.byte 0x00, 0x00, 0x00, 0x00
.byte 0x03, 0x00, 0x00, 0x00
.byte 0x02, 0x00, 0x03, 0x00
.byte 0x1a, 0x00, 0x0e, 0x00
.byte 0x12, 0x00, 0x02, 0x00
.byte 0x00, 0x00, 0x00, 0x00
.byte 0x00, 0x00, 0x00, 0x00
.byte 0x03, 0x00, 0x00, 0x00
.byte 0x00, 0x00, 0x00, 0x00
.byte 0x00, 0x00, 0x00, 0x00
.byte 0x00, 0x00, 0x00, 0x00
.byte 0x00, 0x00, 0x00, 0x00
.byte 0x00, 0x00, 0x00, 0x00
.byte 0x03, 0x00, 0x00, 0x00
.byte 0x00, 0x00, 0x00, 0x00
.byte 0x00, 0x00, 0x00, 0x00
.byte 0x00, 0x00, 0x00, 0x00
.byte 0x00, 0x00, 0x00, 0x00
.byte 0x00, 0x00, 0x00, 0x00
.byte 0x03, 0x00, 0x00, 0x00
.byte 0x00, 0x00, 0x00, 0x00
.byte 0x00, 0x00, 0x00, 0x00
.byte 0x00, 0x00, 0x00, 0x00
.byte 0x00, 0x00, 0x00, 0x00

	.global gUnknown_80F6430
gUnknown_80F6430: @ 80F6430
@ replacing .incbin "baserom.gba", 0x000f6430, 0x48
.byte 0x84, 0x03, 0x00, 0x00
.byte 0x20, 0x03, 0x00, 0x00
.byte 0xbc, 0x02, 0x00, 0x00
.byte 0x58, 0x02, 0x00, 0x00
.byte 0xf4, 0x01, 0x00, 0x00
.byte 0x90, 0x01, 0x00, 0x00
.byte 0x2c, 0x01, 0x00, 0x00
.byte 0xc8, 0x00, 0x00, 0x00
.byte 0x64, 0x00, 0x00, 0x00
.byte 0x5a, 0x00, 0x00, 0x00
.byte 0x50, 0x00, 0x00, 0x00
.byte 0x46, 0x00, 0x00, 0x00
.byte 0x3c, 0x00, 0x00, 0x00
.byte 0x32, 0x00, 0x00, 0x00
.byte 0x28, 0x00, 0x00, 0x00
.byte 0x1e, 0x00, 0x00, 0x00
.byte 0x14, 0x00, 0x00, 0x00
.byte 0x0a, 0x00, 0x00, 0x00

	.global gUnknown_80F6478
gUnknown_80F6478: @ 80F6478
@ replacing .incbin "baserom.gba", 0x000f6478, 0x18
.byte 0x0d, 0x00, 0x00, 0x00
.byte 0x0e, 0x00, 0x00, 0x00
.byte 0x0f, 0x00, 0x00, 0x00
.byte 0x0f, 0x00, 0x00, 0x00
.string "pksdir0\0"

	.global gUnknown_80F6490
gUnknown_80F6490: @ 80F6490
@ replacing .incbin "baserom.gba", 0x000f6490, 0x24
        .byte 0x00, 0x00, 0x00, 0x0
        .byte 0x0f, 0x00, 0x00, 0x00
        .byte 0xff, 0x00, 0x00, 0x00
        .byte 0xff, 0x0f, 0x00, 0x00
        .byte 0xff, 0xff, 0x00, 0x00
        .byte 0xff, 0xff, 0x0f, 0x00
        .byte 0xff, 0xff, 0xff, 0x00
        .byte 0xff, 0xff, 0xff, 0x0f
        .byte 0xff, 0xff, 0xff, 0xff

	.global gUnknown_80F64B4
gUnknown_80F64B4: @ 80F64B4
@ replacing .incbin "baserom.gba", 0x000f64b4, 0x24
        .byte 0x5a, 0x00, 0x00, 0x00
        .byte 0x50, 0x00, 0x00, 0x00
        .byte 0x46, 0x00, 0x00, 0x00
        .byte 0x3c, 0x00, 0x00, 0x00
        .byte 0x32, 0x00, 0x00, 0x00
        .byte 0x28, 0x00, 0x00, 0x00
        .byte 0x1e, 0x00, 0x00, 0x00
        .byte 0x14, 0x00, 0x00, 0x00
        .byte 0x0a, 0x00, 0x00, 0x00

	.global gUnknown_80F64D8
gUnknown_80F64D8: @ 80F64D8
@ replacing .incbin "baserom.gba", 0x000f64d8, 0x24
        .byte 0x91, 0xf2, 0x90, 0xf2, 0x8f, 0xf2, 0x8e, 0xf2, 0x8d, 0xf2, 0x8c, 0xf2, 0x8b, 0xf2, 0x8a, 0xf2, 0x89, 0xf2, 0xc8, 0xf2, 0xc7, 0xf2, 0xc6, 0xf2, 0xc5, 0xf2, 0xc4, 0xf2, 0xc3, 0xf2, 0xc2, 0xf2
        .byte 0xc1, 0xf2, 0xc0, 0xf2

	.global gUnknown_80F64FC
gUnknown_80F64FC: @ 80F64FC
@ replacing .incbin "baserom.gba", 0x000f64fc, 0x24
        .byte 0x84, 0x03, 0x00, 0x00, 0x20, 0x03, 0x00, 0x00, 0xbc, 0x02, 0x00, 0x00, 0x58, 0x02, 0x00, 0x00, 0xf4, 0x01, 0x00, 0x00, 0x90, 0x01, 0x00, 0x00, 0x2c, 0x01, 0x00, 0x00, 0xc8, 0x00, 0x00, 0x00
        .byte 0x64, 0x00, 0x00, 0x00

	.global gUnknown_80F6520
gUnknown_80F6520: @ 80F6520
@ replacing .incbin "baserom.gba", 0x000f6520, 0x24
.byte 0x5a, 0x00, 0x00, 0x00, 0x50, 0x00, 0x00, 0x00, 0x46, 0x00, 0x00, 0x00, 0x3c, 0x00, 0x00, 0x00, 0x32, 0x00, 0x00, 0x00, 0x28, 0x00, 0x00, 0x00, 0x1e, 0x00, 0x00, 0x00, 0x14, 0x00, 0x00, 0x00
.byte 0x0a, 0x00, 0x00, 0x00

	.global gUnknown_80F6544
gUnknown_80F6544: @ 80F6544
@ replacing .incbin "baserom.gba", 0x000f6544, 0x24
        .byte 0x91, 0xf2, 0x90, 0xf2, 0x8f, 0xf2, 0x8e, 0xf2, 0x8d, 0xf2, 0x8c, 0xf2, 0x8b, 0xf2, 0x8a, 0xf2, 0x89, 0xf2, 0xc8, 0xf2, 0xc7, 0xf2, 0xc6, 0xf2, 0xc5, 0xf2, 0xc4, 0xf2, 0xc3, 0xf2, 0xc2, 0xf2
        .byte 0xc1, 0xf2, 0xc0, 0xf2

	.global gUnknown_80F6568
gUnknown_80F6568: @ 80F6568
@ replacing .incbin "baserom.gba", 0x000f6568, 0x88
        .byte 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0x01, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0x01, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0x01, 0x00, 0x00, 0x00, 0xfe, 0xff, 0xff, 0xff
        .byte 0x01, 0x00, 0x00, 0x00, 0xfe, 0xff, 0xff, 0xff, 0x02, 0x00, 0x00, 0x00, 0xfe, 0xff, 0xff, 0xff, 0x02, 0x00, 0x00, 0x00, 0xfe, 0xff, 0xff, 0xff, 0x02, 0x00, 0x00, 0x00, 0xfd, 0xff, 0xff, 0xff
        .byte 0x03, 0x00, 0x00, 0x00, 0xfd, 0xff, 0xff, 0xff, 0x03, 0x00, 0x00, 0x00, 0xfd, 0xff, 0xff, 0xff, 0x04, 0x00, 0x00, 0x00, 0xfc, 0xff, 0xff, 0xff, 0x04, 0x00, 0x00, 0x00, 0xfc, 0xff, 0xff, 0xff
        .byte 0x04, 0x00, 0x00, 0x00, 0xfb, 0xff, 0xff, 0xff, 0x04, 0x00, 0x00, 0x00, 0xfb, 0xff, 0xff, 0xff, 0x04, 0x00, 0x00, 0x00, 0xfb, 0xff, 0xff, 0xff, 0x04, 0x00, 0x00, 0x00, 0xfb, 0xff, 0xff, 0xff
        .byte 0x70, 0x6b, 0x73, 0x64, 0x69, 0x72, 0x30, 0x00

	.global gUnknown_80F65F0
gUnknown_80F65F0: @ 80F65F0
@ replacing .incbin "baserom.gba", 0x000f65f0, 0x14
        .byte 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x07, 0x04, 0x04

	.global gUnknown_80F6604
gUnknown_80F6604: @ 80F6604
@ replacing .incbin "baserom.gba", 0x000f6604, 0x20
        .string "zmappat\0"
        .string "pksdir0\0"
        .string "pksdir0\0"
        .string "pksdir0\0"


        .global gUnknown_80F6624
gUnknown_80F6624: @ 80F6624
	.incbin "baserom.gba", 0xF6624, 0x78

	.global gStatusSpriteMasks_SleepStatus
gStatusSpriteMasks_SleepStatus: @ 80F669C
    .4byte 0                       @ STATUS_NONE
    .4byte STATUS_SPRITE_SLEEP     @ STATUS_SLEEP
    .4byte STATUS_SPRITE_SLEEPLESS @ STATUS_SLEEPLESS
    .4byte STATUS_SPRITE_SLEEP     @ STATUS_NIGHTMARE
    .4byte 0                       @ STATUS_YAWNING
    .4byte STATUS_SPRITE_SLEEP     @ STATUS_NAPPING

	.global gStatusSpriteMasks_NonVolatileStatus
gStatusSpriteMasks_NonVolatileStatus: @ 80F66B4
    .4byte 0                            @ STATUS_NONE
    .4byte STATUS_SPRITE_BURNED         @ STATUS_BURN
    .4byte STATUS_SPRITE_POISONED       @ STATUS_POISONED
    .4byte STATUS_SPRITE_BADLY_POISONED @ STATUS_BADLY_POISONED
    .4byte 0                            @ STATUS_PARALYSIS

	.global gStatusSpriteMasks_ImmobilizeStatus
gStatusSpriteMasks_ImmobilizeStatus: @ 80F66C8
    .4byte 0                    @ STATUS_NONE
    .4byte STATUS_SPRITE_FROZEN @ STATUS_FROZEN
    .4byte 0                    @ STATUS_SHADOW_HOLD
    .4byte 0                    @ STATUS_WRAP
    .4byte 0                    @ STATUS_WRAPPED
    .4byte 0                    @ STATUS_INGRAIN
    .4byte 0                    @ STATUS_PETRIFIED
    .4byte 0                    @ STATUS_CONSTRICTION

	.global gStatusSpriteMasks_VolatileStatus
gStatusSpriteMasks_VolatileStatus: @ 80F66E8
    .4byte 0                      @ STATUS_NONE
    .4byte 0                      @ STATUS_CRINGE
    .4byte STATUS_SPRITE_CONFUSED @ STATUS_CONFUSED
    .4byte 0                      @ STATUS_PAUSED
    .4byte STATUS_SPRITE_COWERING @ STATUS_COWERING
    .4byte STATUS_SPRITE_TAUNTED  @ STATUS_TAUNTED
    .4byte STATUS_SPRITE_ENCORE   @ STATUS_ENCORE
    .4byte 0                      @ STATUS_INFATUATED

	.global gStatusSpriteMasks_ChargingStatus
gStatusSpriteMasks_ChargingStatus: @ 80F6708
    .4byte 0 @ STATUS_NONE
    .4byte 0 @ STATUS_BIDE
    .4byte 0 @ STATUS_SOLARBEAM
    .4byte 0 @ STATUS_SKY_ATTACK
    .4byte 0 @ STATUS_RAZOR_WIND
    .4byte 0 @ STATUS_FOCUS_PUNCH
    .4byte 0 @ STATUS_SKULL_BASH
    .4byte 0 @ STATUS_FLYING
    .4byte 0 @ STATUS_BOUNCING
    .4byte 0 @ STATUS_DIVING
    .4byte 0 @ STATUS_DIGGING
    .4byte 0 @ STATUS_CHARGING
    .4byte 0 @ STATUS_ENRAGED

	.global gStatusSpriteMasks_ProtectionStatus
gStatusSpriteMasks_ProtectionStatus: @ 80F673C
    .4byte 0                           @ STATUS_NONE
    .4byte STATUS_SPRITE_SHIELD_BLUE   @ STATUS_REFLECT
    .4byte STATUS_SPRITE_SHIELD_RED    @ STATUS_SAFEGUARD
    .4byte STATUS_SPRITE_SHIELD_YELLOW @ STATUS_LIGHT_SCREEN
    .4byte STATUS_SPRITE_SHIELD_BLUE   @ STATUS_COUNTER
    .4byte STATUS_SPRITE_SHIELD_YELLOW @ STATUS_MAGIC_COAT
    .4byte 0                           @ STATUS_WISH
    .4byte STATUS_SPRITE_SHIELD_GREEN  @ STATUS_PROTECT
    .4byte STATUS_SPRITE_SHIELD_RED    @ STATUS_MIRROR_COAT
    .4byte STATUS_SPRITE_ENDURE        @ STATUS_ENDURING
    .4byte STATUS_SPRITE_SHIELD_BLUE   @ STATUS_MINI_COUNTER
    .4byte STATUS_SPRITE_SHIELD_GREEN  @ STATUS_MIRROR_MOVE
    .4byte 0                           @ STATUS_CONVERSION2
    .4byte STATUS_SPRITE_SHIELD_GREEN  @ STATUS_VITAL_THROW
    .4byte STATUS_SPRITE_SHIELD_BLUE   @ STATUS_MIST

	.global gStatusSpriteMasks_WaitingStatus
gStatusSpriteMasks_WaitingStatus: @ 80F6778
    .4byte 0                    @ STATUS_NONE
    .4byte STATUS_SPRITE_CURSED @ STATUS_CURSED
    .4byte 0                    @ STATUS_DECOY
    .4byte STATUS_SPRITE_SNATCH @ STATUS_SNATCH

	.global gStatusSpriteMasks_LinkedStatus
gStatusSpriteMasks_LinkedStatus: @ 80F6788
    .4byte 0 @ STATUS_NONE
    .4byte 0 @ STATUS_LEECH_SEED
    .4byte 0 @ STATUS_DESTINY_BOND

	.global gStatusSpriteMasks_MoveStatus
gStatusSpriteMasks_MoveStatus: @ 80F6794
    .4byte 0                          @ STATUS_NONE
    .4byte STATUS_SPRITE_SURE_SHOT    @ STATUS_SURE_SHOT
    .4byte STATUS_SPRITE_WHIFFER      @ STATUS_WHIFFER
    .4byte STATUS_SPRITE_SET_DAMAGE   @ STATUS_SET_DAMAGE
    .4byte STATUS_SPRITE_FOCUS_ENERGY @ STATUS_FOCUS_ENERGY

	.global gStatusSpriteMasks_ItemStatus
gStatusSpriteMasks_ItemStatus: @ 80F67A8
    .4byte 0 @ STATUS_NONE
    .4byte 0 @ STATUS_LONG_TOSS
    .4byte 0 @ STATUS_PIERCE

	.global gStatusSpriteMasks_TransformStatus
gStatusSpriteMasks_TransformStatus: @ 80F67B4
    .4byte 0 @ STATUS_NONE
    .4byte 0 @ STATUS_INVISIBLE
    .4byte 0 @ STATUS_TRANSFORMED
    .4byte 0 @ STATUS_MOBILE

	.global gStatusSpriteMasks_EyesightStatus
gStatusSpriteMasks_EyesightStatus: @ 80F67C4
    .4byte 0                        @ STATUS_NONE
    .4byte STATUS_SPRITE_BLINKER    @ STATUS_BLINKER
    .4byte STATUS_SPRITE_CROSS_EYED @ STATUS_CROSS_EYED
    .4byte STATUS_SPRITE_EYEDROPS   @ STATUS_EYEDROPS

	.global gStatusSpriteMasks_MuzzledStatus
gStatusSpriteMasks_MuzzledStatus: @ 80F67D4
    .4byte 0                     @ STATUS_NONE
    .4byte STATUS_SPRITE_MUZZLED @ STATUS_MUZZLED

	.global gUnknown_80F67DC
gUnknown_80F67DC: @ 80F67DC
        .byte 0xD8, 0x00, 0xD9, 0x00
        .byte 0xD9, 0x00, 0x73, 0x01

	.global gUnknown_80F67E4
gUnknown_80F67E4: @ 80F67E4
        .byte 0xDA, 0x00, 0xDB, 0x00
        .byte 0xDB, 0x00, 0x74, 0x01

	.global gUnknown_80F67EC
gUnknown_80F67EC: @ 80F67EC
	.incbin "baserom.gba", 0xF67EC, 0x20

	.global gUnknown_80F680C
gUnknown_80F680C: @ 80F680C
	.incbin "baserom.gba", 0xF680C, 0x20

	.global gUnknown_80F682C
gUnknown_80F682C: @ 80F682C
	.incbin "baserom.gba", 0xF682C, 0x10

	.global gUnknown_80F683C
gUnknown_80F683C: @ 80F683C
	.incbin "baserom.gba", 0xF683C, 0x14

	.global gUnknown_80F6850
gUnknown_80F6850: @ 80F6850
	.incbin "baserom.gba", 0xF6850, 0x10

	.global gSpeedTurns
gSpeedTurns: @ 80F6860
	.incbin "baserom.gba", 0xF6860, 0x104

	.global gUnknown_80F6964
gUnknown_80F6964: @ 80F6964
	.incbin "baserom.gba", 0xF6964, 0x18

	.global gUnknown_80F697C
gUnknown_80F697C: @ 80F697C
	.incbin "baserom.gba", 0xF697C, 0x14

	.global gUnknown_80F6990
gUnknown_80F6990: @ 80F6990
	.incbin "baserom.gba", 0xF6990, 0xC

	.global gUnknown_80F699C
gUnknown_80F699C: @ 80F699C
	.incbin "baserom.gba", 0xF699C, 0xC

	.global gUnknown_80F69A8
gUnknown_80F69A8: @ 80F69A8
	.incbin "baserom.gba", 0xF69A8, 0x2C

	.global gUnknown_80F69D4
gUnknown_80F69D4: @ 80F69D4
	.incbin "baserom.gba", 0xF69D4, 0x18

	.global gUnknown_80F69EC
gUnknown_80F69EC: @ 80F69EC
	.incbin "baserom.gba", 0xF69EC, 0x18

	.global gUnknown_80F6A04
gUnknown_80F6A04: @ 80F6A04
        .string "b%02dfon\0"
        .align 2,0

	.global gUnknown_80F6A10
gUnknown_80F6A10: @ 80F6A10
        .string "b%02dpal\0"
        .align 2,0

	.global gUnknown_80F6A1C
gUnknown_80F6A1C: @ 80F6A1C
        .string "b%02dcel\0"
        .align 2,0

	.global gUnknown_80F6A28
gUnknown_80F6A28: @ 80F6A28
        .string "b%02dcex\0"
        .align 2,0

	.global gUnknown_80F6A34
gUnknown_80F6A34: @ 80F6A34
        .string "b%02demap0\0"
        .align 2,0

	.global gUnknown_80F6A40
gUnknown_80F6A40: @ 80F6A40
        .string "b%02dcanm\0"

	.global gUnknown_80F6A4A
gUnknown_80F6A4A: @ 80F6A4A
	.incbin "baserom.gba", 0xF6A4A, 0x1BC

	.global gUnknown_80F6C06
gUnknown_80F6C06: @ 80F6C06
	.incbin "baserom.gba", 0xF6C06, 0x11A

	.global gUnknown_80F6D20
gUnknown_80F6D20: @ 80F6D20
	.incbin "baserom.gba", 0xF6D20, 0xAC

	.global gUnknown_80F6DCC
gUnknown_80F6DCC: @ 80F6DCC
        .string "fixedmap\0"

	.global gUnknown_80F6DD5
gUnknown_80F6DD5: @ 80F6DD5
	.incbin "baserom.gba", 0xF6DD5, 0x23

	.global gUnknown_80F6DF8
gUnknown_80F6DF8: @ 80F6DF8
	.incbin "baserom.gba", 0xF6DF8, 0xCF0

	.global gUnknown_80F7AE8
gUnknown_80F7AE8: @ 80F7AE8
        .byte 0x00, 0x00

	.global gUnknown_80F7AEA
gUnknown_80F7AEA: @ 80F7AEA
        .byte 0x0d, 0x03, 0x0d, 0x01, 0x0d, 0x03, 0x0d, 0x01, 0x01, 0x03, 0x01, 0x00, 0x11, 0x00

	.global gUnknown_80F7AF8
gUnknown_80F7AF8: @ 80F7AF8
        .byte 0x3f, 0x3f, 0x00, 0x00

	.global gUnknown_80F7AFC
gUnknown_80F7AFC: @ 80F7AFC
        .string "{COLOR_1 YELLOW}%s{END_COLOR_TEXT_1}\0"
        .align 2,0

	.global gUnknown_80F7B04
gUnknown_80F7B04: @ 80F7B04
        .string "{COLOR_1 YELLOW}"
        .byte 0x87, 0x45
        .string "{END_COLOR_TEXT_1}\0"
        .align 2,0
        .string "pksdir0\0"
        .align 2,0

	.global gActions
gActions: @ 80F7B14
	.4byte gUseDescription
	.4byte gUseText
	.4byte gThrowDescription
	.4byte gThrowText
	.4byte gThrowDescription
	.4byte gThrowText
	.4byte gEquipDescription
	.4byte gEquipText
	.4byte gEatDescription
	.4byte gEatText
	.4byte gIngestDescription
	.4byte gIngestText
	.4byte gPeelDescription
	.4byte gPeelText
	.4byte gUseDescription
	.4byte gUseText
	.4byte gUseDescription
	.4byte gUseText
	.4byte gUseDescription
	.4byte gUseText
	.4byte gUseDescription
	.4byte gUseText
	.4byte gEquipPutOnDescription
	.4byte gEquipText
	.4byte gEquipPutOnDescription
	.4byte gEquipText
	.4byte gUseDescription
	.4byte gUseText
	.4byte gUseDescription
	.4byte gUseText
	.4byte gUseDescription
	.4byte gUseText

	.global gEquipPutOnDescription
gEquipPutOnDescription: @ 80F7B94
	.string "{ARG_POKEMON_0} put on\n"
	.string "the {ARG_MOVE_ITEM_0}.\0"

	.global gPeelText
gPeelText: @ 80F7BA8
	.string "Peel\0"
	.align 2,0

	.global gPeelDescription
gPeelDescription: @ 80F7BB0
	.string "{ARG_POKEMON_0} peeled\n"
	.string "the {ARG_MOVE_ITEM_0}.\0"
	.align 2,0

	.global gIngestText
gIngestText: @ 80F7BC4
	.string "Ingest\0"
	.align 2,0

	.global gIngestDescription
gIngestDescription: @ 80F7BCC
	.string "{ARG_POKEMON_0} swallowed\n"
	.string "the {ARG_MOVE_ITEM_0}.\0"
	.align 2,0

	.global gEatText
gEatText: @ 80F7BE4
	.string "Eat\0"
	.align 2,0

	.global gEatDescription
gEatDescription: @ 80F7BE8
	.string "{ARG_POKEMON_0} ate\n"
	.string "the {ARG_MOVE_ITEM_0}.\0"
	.align 2,0

	.global gEquipText
gEquipText: @ 80F7BFC
	.string "Equip\0"
	.align 2,0

	.global gEquipDescription
gEquipDescription: @ 80F7C04
	.string "{ARG_POKEMON_0} equipped\n"
	.string "the {ARG_MOVE_ITEM_0}.\0"
	.align 2,0

	.global gThrowText
gThrowText: @ 80F7C1C
	.string "Throw\0"
	.align 2,0

	.global gThrowDescription
gThrowDescription: @ 80F7C24
	.string "{ARG_POKEMON_0} threw\n"
	.string "the {ARG_MOVE_ITEM_0}.\0"
	.align 2,0

	.global gUseText
gUseText: @ 80F7C38
	.string "Use\0"
	.align 2,0

	.global gUseDescription
gUseDescription: @ 80F7C3C
	.string "{ARG_POKEMON_0} used\n"
	.string "the {ARG_MOVE_ITEM_0}.\0"
	.align 2,0

	.global gUnknown_80F7C50
gUnknown_80F7C50: @ 80F7C50
	.4byte gMenuQuestionMarks

	.global gUnknown_80F7C54
gUnknown_80F7C54: @ 80F7C54
	.4byte 0x0000000A
	.4byte gMenuWaitText
	.4byte 0x0000000A
	.4byte gMenuMoveText
	.4byte 0x0000000A
	.4byte gMenuMoveText
	.4byte 0x0000000A
	.4byte gMenuWaitText
	.4byte 0x0000000A
	.4byte gMenuWaitText
	.4byte 0x0000000A
	.4byte gMenuNextText
	.4byte 0x0000000A
	.4byte gMenuPrevText
	.4byte 0x0000000A
	.4byte gMenuPlaceText
	.4byte 0x0000000A
	.4byte gMenuGetText
	.4byte 0x0000000A
	.4byte gMenuSwitchText
	.4byte 0x0000000A
	.4byte gThrowText
	.4byte 0x0000000A
	.4byte gMenuInfoText
	.4byte 0x0000005A
	.4byte gMenuXText
	.4byte 0x0000000A
	.4byte gMenuXText
	.4byte 0x0000000A
	.4byte gMenuXText
	.4byte 0x0000000A
	.4byte gMenuXText
	.4byte 0x0000000A
	.4byte gMenuXText
	.4byte 0x0000000A
	.4byte gMenuXText
	.4byte 0x0000000A
	.4byte gMenuTalkText
	.4byte 0x0000000A
	.4byte gUseText
	.4byte 0x0000000A
	.4byte gUseText
	.4byte 0x0000000A
	.4byte gMenuEmpty
	.4byte 0x0000000A
	.4byte gMenuStruggleText
	.4byte 0x0000000A
	.4byte gMenuMoneySymbols
	.4byte 0x000003E7
	.4byte gMenuMovesText
	.4byte 0x0000000A
	.4byte gMenuTacticsText
	.4byte 0x0000000A
	.4byte gMenuSummaryText
	.4byte 0x0000000A
	.4byte gMenuTalkText
	.4byte 0x0000000A
	.4byte gMenuInfoText
	.4byte 0x0000005A
	.4byte gMenuSetText
	.4byte 0x0000000A
	.4byte gMenuSwitchText
	.4byte 0x0000000A
	.4byte gMenuLinkText
	.4byte 0x0000000A
	.4byte gMenuDelinkText
	.4byte 0x0000000A
	.4byte gMenuForgetText
	.4byte 0x0000000A
	.4byte gUseText
	.4byte 0x0000000A
	.4byte gThrowText
	.4byte 0x0000000A
	.4byte gMenuTriggerText
	.4byte 0x0000000A
	.4byte gMenuProceedText
	.4byte 0x0000000A
	.4byte gThrowText
	.4byte 0x00000005
	.4byte gMenuSwitchText
	.4byte 0x0000000A
	.4byte gMenuFarewellText
	.4byte 0x0000000A
	.4byte gMenuCancelText
	.4byte 0x0000000A
	.4byte gMenuQuicksaveText
	.4byte 0x0000000A
	.4byte gUseText
	.4byte 0x0000000A
	.4byte gMenuTalkText
	.4byte 0x0000000A
	.4byte gMenuGiveUpText
	.4byte 0x0000000A
	.4byte gMenuSwitchText
	.4byte 0x0000000A
	.4byte gMenuCheckIQText
	.4byte 0x0000000A
	.4byte gUseText
	.4byte 0x0000000A
	.4byte gUseText
	.4byte 0x0000000A
	.4byte gMenuDeselectText
	.4byte 0x0000000A
	.4byte gMenuFarewellText
	.4byte 0x0000000A
	.4byte gUseText
	.4byte 0x0000000A
	.4byte gMenuGiveText
	.4byte 0x0000000A
	.4byte gMenuTakeText
	.4byte 0x0000000A
	.4byte gUseText
	.4byte 0x0000000A
	.4byte gMenuEmpty
	.4byte 0x0000000A
	.4byte gMenuSwapText
	.4byte 0x0000000A
	.4byte gMenuLeaderText
	.4byte 0x0000000A
	.4byte gMenuSetText
	.4byte 0x0000000A
	.4byte gMenuDeselectText
	.4byte 0x0000000A
	.4byte gMenuSwapText
	.4byte 0x0000000A
	.4byte gMenuPickUpText
	.4byte 0x0000000A
	.4byte gMenuSummaryText
	.4byte 0x0000000A
	.4byte gThrowText
	.4byte 0x00000005

	.global gMenuPickUpText
gMenuPickUpText: @ 80F7E60
	.string "Pick Up\0"
	.align 2,0

	.global gMenuLeaderText
gMenuLeaderText: @ 80F7E68
	.string "Leader\0"
	.align 2,0

	.global gMenuSwapText
gMenuSwapText: @ 80F7E70
	.string "Swap\0"
	.align 2,0

	.global gMenuTakeText
gMenuTakeText: @ 80F7E78
	.string "Take\0"
	.align 2,0

	.global gMenuGiveText
gMenuGiveText: @ 80F7E80
	.string "Give\0"
	.align 2,0

	.global gMenuDeselectText
gMenuDeselectText: @ 80F7E88
	.string "Deselect\0"
	.align 2,0

	.global gMenuCheckIQText
gMenuCheckIQText: @ 80F7E94
	.string "Check IQ\0"
	.align 2,0

	.global gMenuGiveUpText
gMenuGiveUpText: @ 80F7EA0
	.string "Give Up\0"
	.align 2,0

	.global gMenuQuicksaveText
gMenuQuicksaveText: @ 80F7EA8
	.string "Quicksave\0"
	.align 2,0

	.global gMenuCancelText
gMenuCancelText: @ 80F7EB0
	.string "Cancel\0"
	.align 2,0

	.global gMenuFarewellText
gMenuFarewellText: @ 80F7EBC
	.string "Farewell\0"
	.align 2,0

	.global gMenuProceedText
gMenuProceedText: @ 80F7EC8
	.string "Proceed\0"
	.align 2,0

	.global gMenuTriggerText
gMenuTriggerText: @ 80F7ED0
	.string "Trigger\0"
	.align 2,0

	.global gMenuForgetText
gMenuForgetText: @ 80F7ED8
	.string "Forget\0"
	.align 2,0

	.global gMenuDelinkText
gMenuDelinkText: @ 80F7EE0
	.string "Delink\0"
	.align 2,0

	.global gMenuLinkText
gMenuLinkText: @ 80F7EE8
	.string "Link\0"
	.align 2,0

	.global gMenuSetText
gMenuSetText: @ 80F7EF0
	.string "Set\0"
	.align 2,0

	.global gMenuSummaryText
gMenuSummaryText: @ 80F7EF4
	.string "Summary\0"
	.align 2,0

	.global gMenuTacticsText
gMenuTacticsText: @ 80F7EFC
	.string "Tactics\0"
	.align 2,0

	.global gMenuMovesText
gMenuMovesText: @ 80F7F04
	.string "Moves\0"
	.align 2,0

	.global gMenuMoneySymbols
gMenuMoneySymbols: @ 80F7F0C
	.string "$$$$\0"
	.align 2,0

	.global gMenuStruggleText
gMenuStruggleText: @ 80F7F14
	.string "Struggle\0"
	.align 2,0

	.global gMenuEmpty
gMenuEmpty: @ 80F7F20
	.byte 0x00
	.align 2,0

	.global gMenuTalkText
gMenuTalkText: @ 80F7F24
	.string "Talk\0"
	.align 2,0

	.global gMenuXText
gMenuXText: @ 80F7F2C
	.string "X\0"
	.align 2,0

	.global gMenuInfoText
gMenuInfoText: @ 80F7F30
	.string "Info\0"
	.align 2,0

	.global gMenuSwitchText
gMenuSwitchText: @ 80F7F38
	.string "Switch\0"
	.align 2,0

	.global gMenuGetText
gMenuGetText: @ 80F7F40
	.string "Get\0"
	.align 2,0

	.global gMenuPlaceText
gMenuPlaceText: @ 80F7F44
	.string "Place\0"
	.align 2,0

	.global gMenuPrevText
gMenuPrevText: @ 80F7F4C
	.string "Prev.\0"
	.align 2,0

	.global gMenuNextText
gMenuNextText: @ 80F7F54
	.string "Next\0"
	.align 2,0

	.global gMenuMoveText
gMenuMoveText: @ 80F7F5C
	.string "Move\0"
	.align 2,0

	.global gMenuWaitText
gMenuWaitText: @ 80F7F64
	.string "Wait\0"
	.align 2,0

	.global gMenuQuestionMarks
gMenuQuestionMarks: @ 80F7F6C
	.string "???\0"
	.align 2,0

	.global gUnknown_80F7F70
gUnknown_80F7F70: @ 80F7F70
	.4byte gDungeonStairsDescription
	.4byte gWarpZoneDescription
	.4byte gRescueSpotDescription

	.global gRescueSpotDescription
gRescueSpotDescription: @ 80F7F7C
	.string "You reached the rescue spot where your\n"
	.string "friend{APOSTROPHE}s team went down!\n"
	.string "Send an {COLOR_2 RED}A-OK Mail{END_COLOR_TEXT_2} from the Pelipper Post\n"
	.string "Office to let your friend know you{APOSTROPHE}ve\n"
	.string "rescued the defeated team.\0"
	.align 2,0

	.global gWarpZoneDescription
gWarpZoneDescription: @ 80F8030
	.string "The warp zone leading to the next floor.\n"
	.string "If you are on the final floor{COMMA} you will\n"
	.string "escape from the dungeon.\0"
	.align 2,0

	.global gDungeonStairsDescription
gDungeonStairsDescription: @ 80F809C
	.string "Stairs leading to the next floor.\n"
	.string "If you are on the final floor{COMMA} you will\n"
	.string "escape from the dungeon.\0"
	.align 2,0

	.global gUnknown_80F8104
gUnknown_80F8104: @ 80F8104
	.4byte gDungeonStairsText
	.4byte gWarpZoneText
	.4byte gRescueSpotText

	.global gRescueSpotText
gRescueSpotText: @ 80F7F7C
	.string "Rescue Spot\0"
	.align 2,0

	.global gWarpZoneText
gWarpZoneText: @ 80F8030
	.string "Warp Zone\0"
	.align 2,0

	.global gDungeonStairsText
gDungeonStairsText: @ 80F809C
	.string "Stairs\0"
	.align 2,0

	.global gTrapDescriptions
gTrapDescriptions: @ 80F8130
	.incbin "baserom.gba", 0xF8130, 0x838

	.global gUnknown_80F8968
gUnknown_80F8968: @ 80F8968
        .byte 0x5C, 0x89, 0x0F, 0x08
        .string "Decoy\0"
        .align 2,0

	.global gUnknown_80F8974
gUnknown_80F8974: @ 80F8974
	.incbin "baserom.gba", 0xF8974, 0x14

	.global gUnknown_80F8988
gUnknown_80F8988: @ 80F8988
	.incbin "baserom.gba", 0xF8988, 0xC

	.global gUnknown_80F8994
gUnknown_80F8994: @ 80F8994
        .byte 0x8C, 0x89, 0x0F, 0x08

        .global PartnerFainted_80F8998
        PartnerFainted_80F8998:
        .string "Your partner {ARG_POKEMON_0} fainted!\0"
        .align 2,0

	.global gUnknown_80F89B4
gUnknown_80F89B4: @ 80F89B4
        .4byte PartnerFainted_80F8998

        .global ClientFainted_80F89B8
        ClientFainted_80F89B8:
        .string "Your client {ARG_POKEMON_0} fainted!\0"
        .align 2,0

	.global gUnknown_80F89D4
gUnknown_80F89D4: @ 80F89D4
        .4byte ClientFainted_80F89B8

	.global gUnknown_80F89D8
gUnknown_80F89D8: @ 80F89D8
        .4byte ClientFainted_80F89B8

        .global NothingHappened_80F89DC
        NothingHappened_80F89DC:
        .string "But nothing happened!\0"
        .align 2,0

	.global gUnknown_80F89F4
gUnknown_80F89F4: @ 80F89F4
        .4byte NothingHappened_80F89DC

        .global BlownAway_80F89F8
        BlownAway_80F89F8:
        .string "{ARG_POKEMON_0} was blown away!\0"
        .align 2,0

	.global gUnknown_80F8A0C
gUnknown_80F8A0C: @ 80F8A0C
        .4byte BlownAway_80F89F8

        .global NoSetMove_80F8A10
        NoSetMove_80F8A10:
        .string "No move has been set.\0"
        .align 2,0

	.global gUnknown_80F8A28
gUnknown_80F8A28: @ 80F8A28
        .4byte NoSetMove_80F8A10

        .global SetMoveCantUse_80F8A2C
        SetMoveCantUse_80F8A2C:
        .string "The set move can{APOSTROPHE}t be used.\0"
        .align 2,0

	.global gUnknown_80F8A4C
gUnknown_80F8A4C: @ 80F8A4C
        .4byte SetMoveCantUse_80F8A2C

        .global BeingConstricted_80F8A50
        BeingConstricted_80F8A50:
        .string "You{APOSTROPHE}re being constricted!\0"
        .align 2,0

	.global gUnknown_80F8A6C
gUnknown_80F8A6C: @ 80F8A6C
        .4byte BeingConstricted_80F8A50
    
        .global CantMove_80F8A70
        CantMove_80F8A70:
        .string "You can{APOSTROPHE}t move!\0"
        .align 2,0

	.global gUnknown_80F8A84
gUnknown_80F8A84: @ 80F8A84
        .4byte CantMove_80F8A70

        .string "You can{APOSTROPHE}t move while you{APOSTROPHE}re rooted!\0"
        .align 2,0

	.global gUnknown_80F8AB0
gUnknown_80F8AB0: @ 80F8AB0
        .byte 0x88, 0x8A, 0x0F, 0x08
        .string "You can{APOSTROPHE}t move while wrapping a foe!\0"
        .align 2,0

	.global gUnknown_80F8ADC
gUnknown_80F8ADC: @ 80F8ADC
        .byte 0xB4, 0x8A, 0x0F, 0x08
        .string "The foe has you wrapped! You can{APOSTROPHE}t move!\0"
        .align 2,0

	.global gUnknown_80F8B0C
gUnknown_80F8B0C: @ 80F8B0C
        .byte 0xE0, 0x8A, 0x0F, 0x08
        .string "There are no items.\0"

	.global gUnknown_80F8B24
gUnknown_80F8B24: @ 80F8B24
        .byte 0x10, 0x8B, 0x0F, 0x08
        .string "The move {ARG_MOVE_ITEM_0} was set.\0"
        .align 2,0

	.global gUnknown_80F8B40
gUnknown_80F8B40: @ 80F8B40
        .byte 0x28, 0x8B, 0x0F, 0x08
        .string "The move {ARG_MOVE_ITEM_0} was deselected.\0"
        .align 2,0

	.global gUnknown_80F8B64
gUnknown_80F8B64: @ 80F8B64
        .byte 0x44, 0x8B, 0x0F, 0x08
        .4byte gMenuEmpty
        .string "The move {ARG_MOVE_ITEM_0} was delinked.\0"
        .align 2,0

	.global gUnknown_80F8B88
gUnknown_80F8B88: @ 80F8B88
        .byte 0x6C, 0x8B, 0x0F, 0x08
        .string "The linked moves were left unchanged.\0"
        .align 2,0

	.global gUnknown_80F8BB4
gUnknown_80F8BB4: @ 80F8BB4
        .byte 0x8C, 0x8B, 0x0F, 0x08
        .string "It{APOSTROPHE}s all sticky and doesn{APOSTROPHE}t work!\0"
        .align 2,0

	.global gUnknown_80F8BE0
gUnknown_80F8BE0: @ 80F8BE0
	.incbin "baserom.gba", 0xF8BE0, 0x60

	.global gUnknown_80F8C40
gUnknown_80F8C40: @ 80F8C40
        .byte 0x14, 0x8C, 0x0F, 0x08

	.global gUnknown_80F8C44
gUnknown_80F8C44: @ 80F8C44
        .byte 0x14, 0x8C, 0x0F, 0x08

	.global gUnknown_80F8C48
gUnknown_80F8C48: @ 80F8C48
        .byte 0x14, 0x8C, 0x0F, 0x08
        .string "The {ARG_MOVE_ITEM_0} is all sticky!\nIt can{APOSTROPHE}t be equipped.\0"
        .align 2,0

	.global gUnknown_80F8C7C
gUnknown_80F8C7C: @ 80F8C7C
        .byte 0x4C, 0x8C, 0x0F, 0x08
        .string "{ARG_POKEMON_1} took the {ARG_MOVE_ITEM_0}\n"
        .string "and returned the {ARG_MOVE_ITEM_1}.\0"
        .align 2,0

	.global gUnknown_80F8CA8
gUnknown_80F8CA8: @ 80F8CA8
	.incbin "baserom.gba", 0xF8CA8, 0x3C

	.global gUnknown_80F8CE4
gUnknown_80F8CE4: @ 80F8CE4
        .byte 0xAC, 0x8C, 0x0F, 0x08

	.global gUnknown_80F8CE8
gUnknown_80F8CE8: @ 80F8CE8
        .byte 0xAC, 0x8C, 0x0F, 0x08
        .string "Equipped the item {ARG_MOVE_ITEM_0}.\0"
        .align 2,0

	.global gUnknown_80F8D04
gUnknown_80F8D04: @ 80F8D04
        .byte 0xEC, 0x8C, 0x0F, 0x08
        .string "The {ARG_MOVE_ITEM_0} was deselected.\0"

	.global gUnknown_80F8D20
gUnknown_80F8D20: @ 80F8D20
        .byte 0x08, 0x8D, 0x0F, 0x08
        .string "The item {ARG_MOVE_ITEM_0} was given\n"
        .string "to {ARG_POKEMON_1}.\0"
        .align 2,0

	.global gUnknown_80F8D44
gUnknown_80F8D44: @ 80F8D44
        .byte 0x24, 0x8D, 0x0F, 0x08
        .string "The Toolbox is full.\0"
        .align 2,0

	.global gUnknown_80F8D60
gUnknown_80F8D60: @ 80F8D60
	.incbin "baserom.gba", 0xF8D60, 0x1C

	.global gUnknown_80F8D7C
gUnknown_80F8D7C: @ 80F8D7C
	.incbin "baserom.gba", 0xF8D7C, 0x38

	.global gUnknown_80F8DB4
gUnknown_80F8DB4: @ 80F8DB4
	.incbin "baserom.gba", 0xF8DB4, 0x2C

	.global gUnknown_80F8DE0
gUnknown_80F8DE0: @ 80F8DE0
	.incbin "baserom.gba", 0xF8DE0, 0x24

	.global gUnknown_80F8E04
gUnknown_80F8E04: @ 80F8E04
	.incbin "baserom.gba", 0xF8E04, 0x24

	.global gUnknown_80F8E28
gUnknown_80F8E28: @ 80F8E28
	.incbin "baserom.gba", 0xF8E28, 0x4

	.global gUnknown_80F8E2C
gUnknown_80F8E2C: @ 80F8E2C
	.incbin "baserom.gba", 0xF8E2C, 0x28

	.global gUnknown_80F8E54
gUnknown_80F8E54: @ 80F8E54
	.incbin "baserom.gba", 0xF8E54, 0x24

	.global gUnknown_80F8E78
gUnknown_80F8E78: @ 80F8E78
	.incbin "baserom.gba", 0xF8E78, 0x34

	.global gUnknown_80F8EAC
gUnknown_80F8EAC: @ 80F8EAC
	.incbin "baserom.gba", 0xF8EAC, 0x18

	.global gUnknown_80F8EC4
gUnknown_80F8EC4: @ 80F8EC4
	.incbin "baserom.gba", 0xF8EC4, 0x4

	.global gUnknown_80F8EC8
gUnknown_80F8EC8: @ 80F8EC8
	.incbin "baserom.gba", 0xF8EC8, 0x1C

	.global gUnknown_80F8EE4
gUnknown_80F8EE4: @ 80F8EE4
	.incbin "baserom.gba", 0xF8EE4, 0x24

	.global gUnknown_80F8F08
gUnknown_80F8F08: @ 80F8F08
	.incbin "baserom.gba", 0xF8F08, 0x18

	.global gUnknown_80F8F20
gUnknown_80F8F20: @ 80F8F20
	.incbin "baserom.gba", 0xF8F20, 0x18

	.global gUnknown_80F8F38
gUnknown_80F8F38: @ 80F8F38
	.incbin "baserom.gba", 0xF8F38, 0x1C

	.global gUnknown_80F8F54
gUnknown_80F8F54: @ 80F8F54
	.incbin "baserom.gba", 0xF8F54, 0x34

	.global gUnknown_80F8F88
gUnknown_80F8F88: @ 80F8F88
	.incbin "baserom.gba", 0xF8F88, 0x24

	.global gUnknown_80F8FAC
gUnknown_80F8FAC: @ 80F8FAC
	.incbin "baserom.gba", 0xF8FAC, 0x18

	.global gUnknown_80F8FC4
gUnknown_80F8FC4: @ 80F8FC4
	.incbin "baserom.gba", 0xF8FC4, 0x34

	.global gUnknown_80F8FF8
gUnknown_80F8FF8: @ 80F8FF8
	.incbin "baserom.gba", 0xF8FF8, 0x4

	.global gUnknown_80F8FFC
gUnknown_80F8FFC: @ 80F8FFC
	.incbin "baserom.gba", 0xF8FFC, 0x1C

	.global gUnknown_80F9018
gUnknown_80F9018: @ 80F9018
	.incbin "baserom.gba", 0xF9018, 0x38

	.global gUnknown_80F9050
gUnknown_80F9050: @ 80F9050
	.incbin "baserom.gba", 0xF9050, 0x4

	.global gUnknown_80F9054
gUnknown_80F9054: @ 80F9054
	.incbin "baserom.gba", 0xF9054, 0x40

	.global gUnknown_80F9094
gUnknown_80F9094: @ 80F9094
	.incbin "baserom.gba", 0xF9094, 0x34

	.global gUnknown_80F90C8
gUnknown_80F90C8: @ 80F90C8
	.incbin "baserom.gba", 0xF90C8, 0x14

	.global gUnknown_80F90DC
gUnknown_80F90DC: @ 80F90DC
	.incbin "baserom.gba", 0xF90DC, 0x38

	.global gUnknown_80F9114
gUnknown_80F9114: @ 80F9114
	.incbin "baserom.gba", 0xF9114, 0x28

	.global gUnknown_80F913C
gUnknown_80F913C: @ 80F913C
	.incbin "baserom.gba", 0xF913C, 0x14

	.global gUnknown_80F9150
gUnknown_80F9150: @ 80F9150
	.incbin "baserom.gba", 0xF9150, 0x4

	.global gUnknown_80F9154
gUnknown_80F9154: @ 80F9154
	.incbin "baserom.gba", 0xF9154, 0x4

	.global gUnknown_80F9158
gUnknown_80F9158: @ 80F9158
	.incbin "baserom.gba", 0xF9158, 0x1C

	.global gUnknown_80F9174
gUnknown_80F9174: @ 80F9174
	.incbin "baserom.gba", 0xF9174, 0x1C

	.global gUnknown_80F9190
gUnknown_80F9190: @ 80F9190
	.incbin "baserom.gba", 0xF9190, 0x18

	.global gUnknown_80F91A8
gUnknown_80F91A8: @ 80F91A8
	.incbin "baserom.gba", 0xF91A8, 0x20

	.global gUnknown_80F91C8
gUnknown_80F91C8: @ 80F91C8
	.incbin "baserom.gba", 0xF91C8, 0x18

	.global gUnknown_80F91E0
gUnknown_80F91E0: @ 80F91E0
	.incbin "baserom.gba", 0xF91E0, 0xC

	.global gUnknown_80F91EC
gUnknown_80F91EC: @ 80F91EC
	.incbin "baserom.gba", 0xF91EC, 0x4

	.global gTrapNames
gTrapNames: @ 80F91F0
	.incbin "baserom.gba", 0xF91F0, 0x174

	.global gUnknown_80F9364
gUnknown_80F9364: @ 80F9364
	.incbin "baserom.gba", 0xF9364, 0x1C

	.global gUnknown_80F9380
gUnknown_80F9380: @ 80F9380
	.incbin "baserom.gba", 0xF9380, 0x4

	.global gUnknown_80F9384
gUnknown_80F9384: @ 80F9384
	.incbin "baserom.gba", 0xF9384, 0x20

	.global gUnknown_80F93A4
gUnknown_80F93A4: @ 80F93A4
	.incbin "baserom.gba", 0xF93A4, 0x24

	.global gUnknown_80F93C8
gUnknown_80F93C8: @ 80F93C8
	.incbin "baserom.gba", 0xF93C8, 0x20

	.global gUnknown_80F93E8
gUnknown_80F93E8: @ 80F93E8
	.incbin "baserom.gba", 0xF93E8, 0x20

	.global gUnknown_80F9408
gUnknown_80F9408: @ 80F9408
	.incbin "baserom.gba", 0xF9408, 0x1C

	.global gUnknown_80F9424
gUnknown_80F9424: @ 80F9424
	.incbin "baserom.gba", 0xF9424, 0x18

	.global gUnknown_80F943C
gUnknown_80F943C: @ 80F943C
	.incbin "baserom.gba", 0xF943C, 0x20

	.global gUnknown_80F945C
gUnknown_80F945C: @ 80F945C
	.incbin "baserom.gba", 0xF945C, 0x20

	.global gUnknown_80F947C
gUnknown_80F947C: @ 80F947C
	.incbin "baserom.gba", 0xF947C, 0x20

	.global gUnknown_80F949C
gUnknown_80F949C: @ 80F949C
	.incbin "baserom.gba", 0xF949C, 0x28

	.global gUnknown_80F94C4
gUnknown_80F94C4: @ 80F94C4
	.incbin "baserom.gba", 0xF94C4, 0x14

	.global gUnknown_80F94D8
gUnknown_80F94D8: @ 80F94D8
	.incbin "baserom.gba", 0xF94D8, 0x18

	.global gUnknown_80F94F0
gUnknown_80F94F0: @ 80F94F0
	.incbin "baserom.gba", 0xF94F0, 0x20

	.global gUnknown_80F9510
gUnknown_80F9510: @ 80F9510
	.incbin "baserom.gba", 0xF9510, 0x20

	.global gUnknown_80F9530
gUnknown_80F9530: @ 80F9530
	.incbin "baserom.gba", 0xF9530, 0x4

	.global gFrozenMessage
gFrozenMessage: @ 80F9534
	.string "{ARG_POKEMON_0} is frozen solid!\0"
	.align 2, 0

	.global gPtrFrozenMessage
gPtrFrozenMessage: @ 80F954C
	.4byte gFrozenMessage

	.global gWrappedAroundMessage
gWrappedAroundMessage: @ 80F9550
	.string "{ARG_POKEMON_0} has its foe wrapped!\0"
	.align 2, 0

	.global gPtrWrappedAroundMessage
gPtrWrappedAroundMessage: @ 80F956C
	.4byte gWrappedAroundMessage

	.global gWrappedByMessage
gWrappedByMessage: @ 80F9570
	.string "{ARG_POKEMON_0} is wrapped by its foe!\0"
	.align 2, 0

	.global gPtrWrappedByMessage
gPtrWrappedByMessage: @ 80F958C
	.4byte gWrappedByMessage

	.global gPausedMessage
gPausedMessage: @ 80F9590
	.string "{ARG_POKEMON_0} can{APOSTROPHE}t move!\0"
	.align 2, 0

	.global gPtrPausedMessage
gPtrPausedMessage: @ 80F95A4
	.4byte gPausedMessage

	.global gInfatuatedMessage
gInfatuatedMessage: @ 80F95A8
	.string "{ARG_POKEMON_0} is infatuated!\0"
	.align 2, 0

	.global gPtrInfatuatedMessage
gPtrInfatuatedMessage: @ 80F95BC
	.4byte gInfatuatedMessage

	.global gBideMessage
gBideMessage: @ 80F95C0
	.string "{ARG_POKEMON_0} is storing energy!\0"
	.align 2, 0

	.global gPtrBideMessage
gPtrBideMessage: @ 80F95D8
	.4byte gBideMessage

	.global gUnknown_80F95DC
gUnknown_80F95DC: @ 80F95DC
	.incbin "baserom.gba", 0xF95DC, 0x10

	.global gUnknown_80F95EC
gUnknown_80F95EC: @ 80F95EC
	.incbin "baserom.gba", 0xF95EC, 0x14

	.global gUnknown_80F9600
gUnknown_80F9600: @ 80F9600
	.incbin "baserom.gba", 0xF9600, 0x14

	.global gUnknown_80F9614
gUnknown_80F9614: @ 80F9614
	.incbin "baserom.gba", 0xF9614, 0x1C

	.global gUnknown_80F9630
gUnknown_80F9630: @ 80F9630
	.incbin "baserom.gba", 0xF9630, 0x24

	.global gUnknown_80F9654
gUnknown_80F9654: @ 80F9654
	.incbin "baserom.gba", 0xF9654, 0x1C

	.global gUnknown_80F9670
gUnknown_80F9670: @ 80F9670
	.incbin "baserom.gba", 0xF9670, 0x18

	.global gUnknown_80F9688
gUnknown_80F9688: @ 80F9688
	.incbin "baserom.gba", 0xF9688, 0x20

	.global gUnknown_80F96A8
gUnknown_80F96A8: @ 80F96A8
	.incbin "baserom.gba", 0xF96A8, 0x14

	.global gUnknown_80F96BC
gUnknown_80F96BC: @ 80F96BC
	.incbin "baserom.gba", 0xF96BC, 0x30

	.global gUnknown_80F96EC
gUnknown_80F96EC: @ 80F96EC
	.incbin "baserom.gba", 0xF96EC, 0x20

	.global gUnknown_80F970C
gUnknown_80F970C: @ 80F970C
	.incbin "baserom.gba", 0xF970C, 0x1C

	.global gUnknown_80F9728
gUnknown_80F9728: @ 80F9728
	.incbin "baserom.gba", 0xF9728, 0x18

	.global gUnknown_80F9740
gUnknown_80F9740: @ 80F9740
	.incbin "baserom.gba", 0xF9740, 0x20

	.global gUnknown_80F9760
gUnknown_80F9760: @ 80F9760
	.incbin "baserom.gba", 0xF9760, 0x4

	.global gUnknown_80F9764
gUnknown_80F9764: @ 80F9764
	.incbin "baserom.gba", 0xF9764, 0x2F0

	.global gWeatherNames
gWeatherNames: @ 80F9A54
	.incbin "baserom.gba", 0xF9A54, 0x78

	.global gUnknown_80F9ACC
gUnknown_80F9ACC: @ 80F9ACC
	.incbin "baserom.gba", 0xF9ACC, 0x20

	.global gUnknown_80F9AEC
gUnknown_80F9AEC: @ 80F9AEC
	.incbin "baserom.gba", 0xF9AEC, 0x24

	.global gUnknown_80F9B10
gUnknown_80F9B10: @ 80F9B10
	.incbin "baserom.gba", 0xF9B10, 0x24

	.global gUnknown_80F9B34
gUnknown_80F9B34: @ 80F9B34
	.incbin "baserom.gba", 0xF9B34, 0x24

	.global gUnknown_80F9B58
gUnknown_80F9B58: @ 80F9B58
	.incbin "baserom.gba", 0xF9B58, 0x1C

	.global gUnknown_80F9B74
gUnknown_80F9B74: @ 80F9B74
	.incbin "baserom.gba", 0xF9B74, 0x20

	.global gUnknown_80F9B94
gUnknown_80F9B94: @ 80F9B94
	.incbin "baserom.gba", 0xF9B94, 0x1C

	.global gUnknown_80F9BB0
gUnknown_80F9BB0: @ 80F9BB0
	.incbin "baserom.gba", 0xF9BB0, 0x28

	.global gUnknown_80F9BD8
gUnknown_80F9BD8: @ 80F9BD8
	.incbin "baserom.gba", 0xF9BD8, 0x30

	.global gUnknown_80F9C08
gUnknown_80F9C08: @ 80F9C08
	.incbin "baserom.gba", 0xF9C08, 0x24

	.global gUnknown_80F9C2C
gUnknown_80F9C2C: @ 80F9C2C
	.incbin "baserom.gba", 0xF9C2C, 0x20

	.global gUnknown_80F9C4C
gUnknown_80F9C4C: @ 80F9C4C
	.incbin "baserom.gba", 0xF9C4C, 0x24

	.global gUnknown_80F9C70
gUnknown_80F9C70: @ 80F9C70
	.incbin "baserom.gba", 0xF9C70, 0x1C

	.global gUnknown_80F9C8C
gUnknown_80F9C8C: @ 80F9C8C
	.incbin "baserom.gba", 0xF9C8C, 0x30

	.global gUnknown_80F9CBC
gUnknown_80F9CBC: @ 80F9CBC
	.incbin "baserom.gba", 0xF9CBC, 0x4

	.global gUnknown_80F9CC0
gUnknown_80F9CC0: @ 80F9CC0
	.incbin "baserom.gba", 0xF9CC0, 0x2C

	.global gUnknown_80F9CEC
gUnknown_80F9CEC: @ 80F9CEC
	.incbin "baserom.gba", 0xF9CEC, 0x3C

	.global gUnknown_80F9D28
gUnknown_80F9D28: @ 80F9D28
	.incbin "baserom.gba", 0xF9D28, 0x5C

	.global gUnknown_80F9D84
gUnknown_80F9D84: @ 80F9D84
	.incbin "baserom.gba", 0xF9D84, 0x8

	.global gUnknown_80F9D8C
gUnknown_80F9D8C: @ 80F9D8C
	.incbin "baserom.gba", 0xF9D8C, 0x20

	.global gUnknown_80F9DAC
gUnknown_80F9DAC: @ 80F9DAC
	.incbin "baserom.gba", 0xF9DAC, 0x44

	.global gUnknown_80F9DF0
gUnknown_80F9DF0: @ 80F9DF0
	.incbin "baserom.gba", 0xF9DF0, 0x54

	.global gUnknown_80F9E44
gUnknown_80F9E44: @ 80F9E44
	.incbin "baserom.gba", 0xF9E44, 0x20

	.global gUnknown_80F9E64
gUnknown_80F9E64: @ 80F9E64
	.incbin "baserom.gba", 0xF9E64, 0x1C

	.global gUnknown_80F9E80
gUnknown_80F9E80: @ 80F9E80
	.incbin "baserom.gba", 0xF9E80, 0x48

	.global gUnknown_80F9EC8
gUnknown_80F9EC8: @ 80F9EC8
	.incbin "baserom.gba", 0xF9EC8, 0x24

	.global gUnknown_80F9EEC
gUnknown_80F9EEC: @ 80F9EEC
	.incbin "baserom.gba", 0xF9EEC, 0x18

	.global gUnknown_80F9F04
gUnknown_80F9F04: @ 80F9F04
	.incbin "baserom.gba", 0xF9F04, 0x28

	.global gUnknown_80F9F2C
gUnknown_80F9F2C: @ 80F9F2C
	.incbin "baserom.gba", 0xF9F2C, 0x78

	.global gUnknown_80F9FA4
gUnknown_80F9FA4: @ 80F9FA4
	.incbin "baserom.gba", 0xF9FA4, 0x44

	.global gUnknown_80F9FE8
gUnknown_80F9FE8: @ 80F9FE8
	.incbin "baserom.gba", 0xF9FE8, 0x1C

	.global gUnknown_80FA004
gUnknown_80FA004: @ 80FA004
	.incbin "baserom.gba", 0xFA004, 0x2C

	.global gUnknown_80FA030
gUnknown_80FA030: @ 80FA030
	.incbin "baserom.gba", 0xFA030, 0x28

	.global gUnknown_80FA058
gUnknown_80FA058: @ 80FA058
	.incbin "baserom.gba", 0xFA058, 0x38

	.global gUnknown_80FA090
gUnknown_80FA090: @ 80FA090
	.incbin "baserom.gba", 0xFA090, 0x38

	.global gUnknown_80FA0C8
gUnknown_80FA0C8: @ 80FA0C8
	.incbin "baserom.gba", 0xFA0C8, 0x28

	.global gUnknown_80FA0F0
gUnknown_80FA0F0: @ 80FA0F0
	.incbin "baserom.gba", 0xFA0F0, 0x30

	.global gUnknown_80FA120
gUnknown_80FA120: @ 80FA120
	.incbin "baserom.gba", 0xFA120, 0x4

	.global gUnknown_80FA124
gUnknown_80FA124: @ 80FA124
	.incbin "baserom.gba", 0xFA124, 0x13C

	.global gUnknown_80FA260
gUnknown_80FA260: @ 80FA260
	.incbin "baserom.gba", 0xFA260, 0x50

	.global gUnknown_80FA2B0
gUnknown_80FA2B0: @ 80FA2B0
	.incbin "baserom.gba", 0xFA2B0, 0x40

	.global gUnknown_80FA2F0
gUnknown_80FA2F0: @ 80FA2F0
	.incbin "baserom.gba", 0xFA2F0, 0x3C

	.global gUnknown_80FA32C
gUnknown_80FA32C: @ 80FA32C
	.incbin "baserom.gba", 0xFA32C, 0x40

	.global gUnknown_80FA36C
gUnknown_80FA36C: @ 80FA36C
	.incbin "baserom.gba", 0xFA36C, 0x4

	.global gUnknown_80FA370
gUnknown_80FA370: @ 80FA370
	.incbin "baserom.gba", 0xFA370, 0x24

	.global gUnknown_80FA394
gUnknown_80FA394: @ 80FA394
	.incbin "baserom.gba", 0xFA394, 0x24

	.global gUnknown_80FA3B8
gUnknown_80FA3B8: @ 80FA3B8
	.incbin "baserom.gba", 0xFA3B8, 0x50

	.global gUnknown_80FA408
gUnknown_80FA408: @ 80FA408
	.incbin "baserom.gba", 0xFA408, 0x40

	.global gUnknown_80FA448
gUnknown_80FA448: @ 80FA448
	.incbin "baserom.gba", 0xFA448, 0x1C

	.global gUnknown_80FA464
gUnknown_80FA464: @ 80FA464
	.incbin "baserom.gba", 0xFA464, 0x70

	.global gUnknown_80FA4D4
gUnknown_80FA4D4: @ 80FA4D4
	.incbin "baserom.gba", 0xFA4D4, 0x4

	.global gUnknown_80FA4D8
gUnknown_80FA4D8: @ 80FA4D8
	.incbin "baserom.gba", 0xFA4D8, 0x28

	.global gUnknown_80FA500
gUnknown_80FA500: @ 80FA500
	.incbin "baserom.gba", 0xFA500, 0x2C

	.global gUnknown_80FA52C
gUnknown_80FA52C: @ 80FA52C
	.incbin "baserom.gba", 0xFA52C, 0x4

	.global gUnknown_80FA530
gUnknown_80FA530: @ 80FA530
	.incbin "baserom.gba", 0xFA530, 0x1C

	.global gUnknown_80FA54C
gUnknown_80FA54C: @ 80FA54C
	.incbin "baserom.gba", 0xFA54C, 0x34

	.global gUnknown_80FA580
gUnknown_80FA580: @ 80FA580
	.incbin "baserom.gba", 0xFA580, 0x34

	.global gUnknown_80FA5B4
gUnknown_80FA5B4: @ 80FA5B4
	.incbin "baserom.gba", 0xFA5B4, 0x40

	.global gUnknown_80FA5F4
gUnknown_80FA5F4: @ 80FA5F4
        .byte 0xBC, 0xA5, 0x0F, 0x08

        .string "There are no potential recruits.\0"
        .align 2,0

	.global gUnknown_80FA61C
gUnknown_80FA61C: @ 80FA61C
	.incbin "baserom.gba", 0xFA61C, 0x1C

	.global gUnknown_80FA638
gUnknown_80FA638: @ 80FA638
	.incbin "baserom.gba", 0xFA638, 0x20

	.global gUnknown_80FA658
gUnknown_80FA658: @ 80FA658
	.incbin "baserom.gba", 0xFA658, 0x24

	.global gUnknown_80FA67C
gUnknown_80FA67C: @ 80FA67C
	.incbin "baserom.gba", 0xFA67C, 0x20

	.global gUnknown_80FA69C
gUnknown_80FA69C: @ 80FA69C
	.incbin "baserom.gba", 0xFA69C, 0x20

	.global gUnknown_80FA6BC
gUnknown_80FA6BC: @ 80FA6BC
	.incbin "baserom.gba", 0xFA6BC, 0x18

	.global gUnknown_80FA6D4
gUnknown_80FA6D4: @ 80FA6D4
	.incbin "baserom.gba", 0xFA6D4, 0x14

	.global gUnknown_80FA6E8
gUnknown_80FA6E8: @ 80FA6E8
	.incbin "baserom.gba", 0xFA6E8, 0x20

	.global gUnknown_80FA708
gUnknown_80FA708: @ 80FA708
	.incbin "baserom.gba", 0xFA708, 0x4

	.global gUnknown_80FA70C
gUnknown_80FA70C: @ 80FA70C
	.incbin "baserom.gba", 0xFA70C, 0x4

	.global gUnknown_80FA710
gUnknown_80FA710: @ 80FA710
	.incbin "baserom.gba", 0xFA710, 0x24

	.global gUnknown_80FA734
gUnknown_80FA734: @ 80FA734
	.incbin "baserom.gba", 0xFA734, 0x24

	.global gUnknown_80FA758
gUnknown_80FA758: @ 80FA758
	.incbin "baserom.gba", 0xFA758, 0x20

	.global gUnknown_80FA778
gUnknown_80FA778: @ 80FA778
	.incbin "baserom.gba", 0xFA778, 0x24

	.global gUnknown_80FA79C
gUnknown_80FA79C: @ 80FA79C
	.incbin "baserom.gba", 0xFA79C, 0x20

	.global gUnknown_80FA7BC
gUnknown_80FA7BC: @ 80FA7BC
	.incbin "baserom.gba", 0xFA7BC, 0x20

	.global gUnknown_80FA7DC
gUnknown_80FA7DC: @ 80FA7DC
	.incbin "baserom.gba", 0xFA7DC, 0x24

	.global gUnknown_80FA800
gUnknown_80FA800: @ 80FA800
	.incbin "baserom.gba", 0xFA800, 0x1C

	.global gUnknown_80FA81C
gUnknown_80FA81C: @ 80FA81C
	.incbin "baserom.gba", 0xFA81C, 0x4

	.global gUnknown_80FA820
gUnknown_80FA820: @ 80FA820
	.incbin "baserom.gba", 0xFA820, 0x4

	.global gUnknown_80FA824
gUnknown_80FA824: @ 80FA824
	.incbin "baserom.gba", 0xFA824, 0x20

	.global gUnknown_80FA844
gUnknown_80FA844: @ 80FA844
	.incbin "baserom.gba", 0xFA844, 0x24

	.global gUnknown_80FA868
gUnknown_80FA868: @ 80FA868
	.incbin "baserom.gba", 0xFA868, 0x20

	.global gUnknown_80FA888
gUnknown_80FA888: @ 80FA888
	.incbin "baserom.gba", 0xFA888, 0x20

	.global gUnknown_80FA8A8
gUnknown_80FA8A8: @ 80FA8A8
	.incbin "baserom.gba", 0xFA8A8, 0x14

	.global gUnknown_80FA8BC
gUnknown_80FA8BC: @ 80FA8BC
	.incbin "baserom.gba", 0xFA8BC, 0x24

	.global gUnknown_80FA8E0
gUnknown_80FA8E0: @ 80FA8E0
	.incbin "baserom.gba", 0xFA8E0, 0x2C

	.global gUnknown_80FA90C
gUnknown_80FA90C: @ 80FA90C
	.incbin "baserom.gba", 0xFA90C, 0x28

	.global gUnknown_80FA934
gUnknown_80FA934: @ 80FA934
	.incbin "baserom.gba", 0xFA934, 0x28

	.global gUnknown_80FA95C
gUnknown_80FA95C: @ 80FA95C
	.incbin "baserom.gba", 0xFA95C, 0x20

	.global gUnknown_80FA97C
gUnknown_80FA97C: @ 80FA97C
	.incbin "baserom.gba", 0xFA97C, 0x24

	.global gUnknown_80FA9A0
gUnknown_80FA9A0: @ 80FA9A0
	.incbin "baserom.gba", 0xFA9A0, 0x20

	.global gUnknown_80FA9C0
gUnknown_80FA9C0: @ 80FA9C0
	.incbin "baserom.gba", 0xFA9C0, 0x1C

	.global gUnknown_80FA9DC
gUnknown_80FA9DC: @ 80FA9DC
	.incbin "baserom.gba", 0xFA9DC, 0x18

	.global gUnknown_80FA9F4
gUnknown_80FA9F4: @ 80FA9F4
	.incbin "baserom.gba", 0xFA9F4, 0x18

	.global gUnknown_80FAA0C
gUnknown_80FAA0C: @ 80FAA0C
	.incbin "baserom.gba", 0xFAA0C, 0x20

	.global gUnknown_80FAA2C
gUnknown_80FAA2C: @ 80FAA2C
	.incbin "baserom.gba", 0xFAA2C, 0x1C

	.global gUnknown_80FAA48
gUnknown_80FAA48: @ 80FAA48
	.incbin "baserom.gba", 0xFAA48, 0x20

	.global gUnknown_80FAA68
gUnknown_80FAA68: @ 80FAA68
	.incbin "baserom.gba", 0xFAA68, 0x24

	.global gUnknown_80FAA8C
gUnknown_80FAA8C: @ 80FAA8C
	.incbin "baserom.gba", 0xFAA8C, 0x20

	.global gUnknown_80FAAAC
gUnknown_80FAAAC: @ 80FAAAC
	.incbin "baserom.gba", 0xFAAAC, 0x1C

	.global gUnknown_80FAAC8
gUnknown_80FAAC8: @ 80FAAC8
	.incbin "baserom.gba", 0xFAAC8, 0x20

	.global gUnknown_80FAAE8
gUnknown_80FAAE8: @ 80FAAE8
	.incbin "baserom.gba", 0xFAAE8, 0x20

	.global gUnknown_80FAB08
gUnknown_80FAB08: @ 80FAB08
	.incbin "baserom.gba", 0xFAB08, 0x20

	.global gUnknown_80FAB28
gUnknown_80FAB28: @ 80FAB28
	.incbin "baserom.gba", 0xFAB28, 0x18

	.global gUnknown_80FAB40
gUnknown_80FAB40: @ 80FAB40
	.incbin "baserom.gba", 0xFAB40, 0x2C

	.global gUnknown_80FAB6C
gUnknown_80FAB6C: @ 80FAB6C
	.incbin "baserom.gba", 0xFAB6C, 0x24

	.global gUnknown_80FAB90
gUnknown_80FAB90: @ 80FAB90
	.incbin "baserom.gba", 0xFAB90, 0x2C

	.global gUnknown_80FABBC
gUnknown_80FABBC: @ 80FABBC
	.incbin "baserom.gba", 0xFABBC, 0x4

	.global gUnknown_80FABC0
gUnknown_80FABC0: @ 80FABC0
	.incbin "baserom.gba", 0xFABC0, 0x18

	.global gUnknown_80FABD8
gUnknown_80FABD8: @ 80FABD8
	.incbin "baserom.gba", 0xFABD8, 0x20

	.global gUnknown_80FABF8
gUnknown_80FABF8: @ 80FABF8
	.incbin "baserom.gba", 0xFABF8, 0x20

	.global gUnknown_80FAC18
gUnknown_80FAC18: @ 80FAC18
	.incbin "baserom.gba", 0xFAC18, 0x20

	.global gUnknown_80FAC38
gUnknown_80FAC38: @ 80FAC38
	.incbin "baserom.gba", 0xFAC38, 0x1C

	.global gUnknown_80FAC54
gUnknown_80FAC54: @ 80FAC54
	.incbin "baserom.gba", 0xFAC54, 0x20

	.global gUnknown_80FAC74
gUnknown_80FAC74: @ 80FAC74
	.incbin "baserom.gba", 0xFAC74, 0x14

	.global gUnknown_80FAC88
gUnknown_80FAC88: @ 80FAC88
	.incbin "baserom.gba", 0xFAC88, 0x1C

	.global gUnknown_80FACA4
gUnknown_80FACA4: @ 80FACA4
	.incbin "baserom.gba", 0xFACA4, 0x20

	.global gUnknown_80FACC4
gUnknown_80FACC4: @ 80FACC4
	.incbin "baserom.gba", 0xFACC4, 0x20

	.global gUnknown_80FACE4
gUnknown_80FACE4: @ 80FACE4
	.incbin "baserom.gba", 0xFACE4, 0x18

	.global gUnknown_80FACFC
gUnknown_80FACFC: @ 80FACFC
	.incbin "baserom.gba", 0xFACFC, 0x14

	.global gUnknown_80FAD10
gUnknown_80FAD10: @ 80FAD10
	.incbin "baserom.gba", 0xFAD10, 0x1C

	.global gUnknown_80FAD2C
gUnknown_80FAD2C: @ 80FAD2C
	.incbin "baserom.gba", 0xFAD2C, 0x20

	.global gUnknown_80FAD4C
gUnknown_80FAD4C: @ 80FAD4C
	.incbin "baserom.gba", 0xFAD4C, 0x20

	.global gUnknown_80FAD6C
gUnknown_80FAD6C: @ 80FAD6C
	.incbin "baserom.gba", 0xFAD6C, 0x20

	.global gUnknown_80FAD8C
gUnknown_80FAD8C: @ 80FAD8C
	.incbin "baserom.gba", 0xFAD8C, 0x24

	.global gUnknown_80FADB0
gUnknown_80FADB0: @ 80FADB0
	.incbin "baserom.gba", 0xFADB0, 0x28

	.global gUnknown_80FADD8
gUnknown_80FADD8: @ 80FADD8
	.incbin "baserom.gba", 0xFADD8, 0x28

	.global gUnknown_80FAE00
gUnknown_80FAE00: @ 80FAE00
	.incbin "baserom.gba", 0xFAE00, 0x1C

	.global gUnknown_80FAE1C
gUnknown_80FAE1C: @ 80FAE1C
	.incbin "baserom.gba", 0xFAE1C, 0x20

	.global gUnknown_80FAE3C
gUnknown_80FAE3C: @ 80FAE3C
	.incbin "baserom.gba", 0xFAE3C, 0x1C

	.global gUnknown_80FAE58
gUnknown_80FAE58: @ 80FAE58
	.incbin "baserom.gba", 0xFAE58, 0x24

	.global gUnknown_80FAE7C
gUnknown_80FAE7C: @ 80FAE7C
	.incbin "baserom.gba", 0xFAE7C, 0x24

	.global gUnknown_80FAEA0
gUnknown_80FAEA0: @ 80FAEA0
	.incbin "baserom.gba", 0xFAEA0, 0x28

	.global gUnknown_80FAEC8
gUnknown_80FAEC8: @ 80FAEC8
	.incbin "baserom.gba", 0xFAEC8, 0x28

	.global gUnknown_80FAEF0
gUnknown_80FAEF0: @ 80FAEF0
	.incbin "baserom.gba", 0xFAEF0, 0x2C

	.global gUnknown_80FAF1C
gUnknown_80FAF1C: @ 80FAF1C
	.incbin "baserom.gba", 0xFAF1C, 0x20

	.global gUnknown_80FAF3C
gUnknown_80FAF3C: @ 80FAF3C
	.incbin "baserom.gba", 0xFAF3C, 0x20

	.global gUnknown_80FAF5C
gUnknown_80FAF5C: @ 80FAF5C
	.incbin "baserom.gba", 0xFAF5C, 0x30

	.global gUnknown_80FAF8C
gUnknown_80FAF8C: @ 80FAF8C
	.incbin "baserom.gba", 0xFAF8C, 0x20

	.global gUnknown_80FAFAC
gUnknown_80FAFAC: @ 80FAFAC
	.incbin "baserom.gba", 0xFAFAC, 0x24

	.global gUnknown_80FAFD0
gUnknown_80FAFD0: @ 80FAFD0
	.incbin "baserom.gba", 0xFAFD0, 0x20

	.global gUnknown_80FAFF0
gUnknown_80FAFF0: @ 80FAFF0
	.incbin "baserom.gba", 0xFAFF0, 0x14

	.global gUnknown_80FB004
gUnknown_80FB004: @ 80FB004
	.incbin "baserom.gba", 0xFB004, 0x18

	.global gUnknown_80FB01C
gUnknown_80FB01C: @ 80FB01C
	.incbin "baserom.gba", 0xFB01C, 0x2C

	.global gUnknown_80FB048
gUnknown_80FB048: @ 80FB048
	.incbin "baserom.gba", 0xFB048, 0x2C

	.global gUnknown_80FB074
gUnknown_80FB074: @ 80FB074
	.incbin "baserom.gba", 0xFB074, 0x28

	.global gUnknown_80FB09C
gUnknown_80FB09C: @ 80FB09C
	.incbin "baserom.gba", 0xFB09C, 0x28

	.global gUnknown_80FB0C4
gUnknown_80FB0C4: @ 80FB0C4
	.incbin "baserom.gba", 0xFB0C4, 0x1C

	.global gUnknown_80FB0E0
gUnknown_80FB0E0: @ 80FB0E0
	.incbin "baserom.gba", 0xFB0E0, 0x2C

	.global gUnknown_80FB10C
gUnknown_80FB10C: @ 80FB10C
	.incbin "baserom.gba", 0xFB10C, 0x24

	.global gUnknown_80FB130
gUnknown_80FB130: @ 80FB130
	.incbin "baserom.gba", 0xFB130, 0x30

	.global gUnknown_80FB160
gUnknown_80FB160: @ 80FB160
	.incbin "baserom.gba", 0xFB160, 0x1C

	.global gUnknown_80FB17C
gUnknown_80FB17C: @ 80FB17C
	.incbin "baserom.gba", 0xFB17C, 0x2C

	.global gUnknown_80FB1A8
gUnknown_80FB1A8: @ 80FB1A8
	.incbin "baserom.gba", 0xFB1A8, 0x1C

	.global gUnknown_80FB1C4
gUnknown_80FB1C4: @ 80FB1C4
	.incbin "baserom.gba", 0xFB1C4, 0x1C

	.global gUnknown_80FB1E0
gUnknown_80FB1E0: @ 80FB1E0
	.incbin "baserom.gba", 0xFB1E0, 0x24

	.global gUnknown_80FB204
gUnknown_80FB204: @ 80FB204
	.incbin "baserom.gba", 0xFB204, 0x18

	.global gUnknown_80FB21C
gUnknown_80FB21C: @ 80FB21C
	.incbin "baserom.gba", 0xFB21C, 0x24

	.global gUnknown_80FB240
gUnknown_80FB240: @ 80FB240
	.incbin "baserom.gba", 0xFB240, 0x1C

	.global gUnknown_80FB25C
gUnknown_80FB25C: @ 80FB25C
	.incbin "baserom.gba", 0xFB25C, 0x20

	.global gUnknown_80FB27C
gUnknown_80FB27C: @ 80FB27C
	.incbin "baserom.gba", 0xFB27C, 0x30

	.global gUnknown_80FB2AC
gUnknown_80FB2AC: @ 80FB2AC
	.incbin "baserom.gba", 0xFB2AC, 0x20

	.global gUnknown_80FB2CC
gUnknown_80FB2CC: @ 80FB2CC
	.incbin "baserom.gba", 0xFB2CC, 0x14

	.global gUnknown_80FB2E0
gUnknown_80FB2E0: @ 80FB2E0
	.incbin "baserom.gba", 0xFB2E0, 0x20

	.global gUnknown_80FB300
gUnknown_80FB300: @ 80FB300
	.incbin "baserom.gba", 0xFB300, 0x18

	.global gUnknown_80FB318
gUnknown_80FB318: @ 80FB318
	.incbin "baserom.gba", 0xFB318, 0x4

	.global gUnknown_80FB31C
gUnknown_80FB31C: @ 80FB31C
	.incbin "baserom.gba", 0xFB31C, 0x1C

	.global gUnknown_80FB338
gUnknown_80FB338: @ 80FB338
	.incbin "baserom.gba", 0xFB338, 0x24

	.global gUnknown_80FB35C
gUnknown_80FB35C: @ 80FB35C
	.incbin "baserom.gba", 0xFB35C, 0x4

	.global gUnknown_80FB360
gUnknown_80FB360: @ 80FB360
	.incbin "baserom.gba", 0xFB360, 0x20

	.global gUnknown_80FB380
gUnknown_80FB380: @ 80FB380
	.incbin "baserom.gba", 0xFB380, 0x4

	.global gUnknown_80FB384
gUnknown_80FB384: @ 80FB384
	.incbin "baserom.gba", 0xFB384, 0x4

	.global gUnknown_80FB388
gUnknown_80FB388: @ 80FB388
	.incbin "baserom.gba", 0xFB388, 0x1C

	.global gUnknown_80FB3A4
gUnknown_80FB3A4: @ 80FB3A4
	.incbin "baserom.gba", 0xFB3A4, 0x28

	.global gUnknown_80FB3CC
gUnknown_80FB3CC: @ 80FB3CC
	.incbin "baserom.gba", 0xFB3CC, 0x4

	.global gUnknown_80FB3D0
gUnknown_80FB3D0: @ 80FB3D0
	.incbin "baserom.gba", 0xFB3D0, 0x10

	.global gUnknown_80FB3E0
gUnknown_80FB3E0: @ 80FB3E0
	.incbin "baserom.gba", 0xFB3E0, 0x18

	.global gUnknown_80FB3F8
gUnknown_80FB3F8: @ 80FB3F8
	.incbin "baserom.gba", 0xFB3F8, 0x1C

	.global gUnknown_80FB414
gUnknown_80FB414: @ 80FB414
	.incbin "baserom.gba", 0xFB414, 0x4

	.global gUnknown_80FB418
gUnknown_80FB418: @ 80FB418
	.incbin "baserom.gba", 0xFB418, 0x4

	.global gUnknown_80FB41C
gUnknown_80FB41C: @ 80FB41C
	.incbin "baserom.gba", 0xFB41C, 0x20

	.global gUnknown_80FB43C
gUnknown_80FB43C: @ 80FB43C
	.incbin "baserom.gba", 0xFB43C, 0x1C

	.global gUnknown_80FB458
gUnknown_80FB458: @ 80FB458
	.incbin "baserom.gba", 0xFB458, 0x28

	.global gUnknown_80FB480
gUnknown_80FB480: @ 80FB480
	.incbin "baserom.gba", 0xFB480, 0x30

	.global gUnknown_80FB4B0
gUnknown_80FB4B0: @ 80FB4B0
	.incbin "baserom.gba", 0xFB4B0, 0x24

	.global gUnknown_80FB4D4
gUnknown_80FB4D4: @ 80FB4D4
	.incbin "baserom.gba", 0xFB4D4, 0x1C

	.global gUnknown_80FB4F0
gUnknown_80FB4F0: @ 80FB4F0
	.incbin "baserom.gba", 0xFB4F0, 0x1C

	.global gUnknown_80FB50C
gUnknown_80FB50C: @ 80FB50C
	.incbin "baserom.gba", 0xFB50C, 0x20

	.global gUnknown_80FB52C
gUnknown_80FB52C: @ 80FB52C
	.incbin "baserom.gba", 0xFB52C, 0x1C

	.global gUnknown_80FB548
gUnknown_80FB548: @ 80FB548
	.incbin "baserom.gba", 0xFB548, 0x1C

	.global gUnknown_80FB564
gUnknown_80FB564: @ 80FB564
	.incbin "baserom.gba", 0xFB564, 0x1C

	.global gUnknown_80FB580
gUnknown_80FB580: @ 80FB580
	.incbin "baserom.gba", 0xFB580, 0x18

	.global gUnknown_80FB598
gUnknown_80FB598: @ 80FB598
	.incbin "baserom.gba", 0xFB598, 0x1C

	.global gUnknown_80FB5B4
gUnknown_80FB5B4: @ 80FB5B4
	.incbin "baserom.gba", 0xFB5B4, 0x20

	.global gUnknown_80FB5D4
gUnknown_80FB5D4: @ 80FB5D4
	.incbin "baserom.gba", 0xFB5D4, 0x24

	.global gUnknown_80FB5F8
gUnknown_80FB5F8: @ 80FB5F8
	.incbin "baserom.gba", 0xFB5F8, 0x18

	.global gUnknown_80FB610
gUnknown_80FB610: @ 80FB610
	.incbin "baserom.gba", 0xFB610, 0x18

	.global gUnknown_80FB628
gUnknown_80FB628: @ 80FB628
	.incbin "baserom.gba", 0xFB628, 0x24

	.global gUnknown_80FB64C
gUnknown_80FB64C: @ 80FB64C
	.incbin "baserom.gba", 0xFB64C, 0x1C

	.global gUnknown_80FB668
gUnknown_80FB668: @ 80FB668
	.incbin "baserom.gba", 0xFB668, 0x20

	.global gUnknown_80FB688
gUnknown_80FB688: @ 80FB688
	.incbin "baserom.gba", 0xFB688, 0x1C

	.global gUnknown_80FB6A4
gUnknown_80FB6A4: @ 80FB6A4
	.incbin "baserom.gba", 0xFB6A4, 0x1C

	.global gUnknown_80FB6C0
gUnknown_80FB6C0: @ 80FB6C0
	.incbin "baserom.gba", 0xFB6C0, 0x18

	.global gUnknown_80FB6D8
gUnknown_80FB6D8: @ 80FB6D8
	.incbin "baserom.gba", 0xFB6D8, 0x24

	.global gUnknown_80FB6FC
gUnknown_80FB6FC: @ 80FB6FC
	.incbin "baserom.gba", 0xFB6FC, 0x1C

	.global gUnknown_80FB718
gUnknown_80FB718: @ 80FB718
	.incbin "baserom.gba", 0xFB718, 0x24

	.global gUnknown_80FB73C
gUnknown_80FB73C: @ 80FB73C
	.incbin "baserom.gba", 0xFB73C, 0x28

	.global gUnknown_80FB764
gUnknown_80FB764: @ 80FB764
	.incbin "baserom.gba", 0xFB764, 0x1C

	.global gUnknown_80FB780
gUnknown_80FB780: @ 80FB780
	.incbin "baserom.gba", 0xFB780, 0x20

	.global gUnknown_80FB7A0
gUnknown_80FB7A0: @ 80FB7A0
	.incbin "baserom.gba", 0xFB7A0, 0x1C

	.global gUnknown_80FB7BC
gUnknown_80FB7BC: @ 80FB7BC
	.incbin "baserom.gba", 0xFB7BC, 0x20

	.global gUnknown_80FB7DC
gUnknown_80FB7DC: @ 80FB7DC
	.incbin "baserom.gba", 0xFB7DC, 0x18

	.global gUnknown_80FB7F4
gUnknown_80FB7F4: @ 80FB7F4
	.incbin "baserom.gba", 0xFB7F4, 0x1C

	.global gUnknown_80FB810
gUnknown_80FB810: @ 80FB810
	.incbin "baserom.gba", 0xFB810, 0x24

	.global gUnknown_80FB834
gUnknown_80FB834: @ 80FB834
	.incbin "baserom.gba", 0xFB834, 0x28

	.global gUnknown_80FB85C
gUnknown_80FB85C: @ 80FB85C
	.incbin "baserom.gba", 0xFB85C, 0x24

	.global gUnknown_80FB880
gUnknown_80FB880: @ 80FB880
	.incbin "baserom.gba", 0xFB880, 0x1C

	.global gUnknown_80FB89C
gUnknown_80FB89C: @ 80FB89C
	.incbin "baserom.gba", 0xFB89C, 0x20

	.global gUnknown_80FB8BC
gUnknown_80FB8BC: @ 80FB8BC
	.incbin "baserom.gba", 0xFB8BC, 0x28

	.global gUnknown_80FB8E4
gUnknown_80FB8E4: @ 80FB8E4
	.incbin "baserom.gba", 0xFB8E4, 0x1C

	.global gUnknown_80FB900
gUnknown_80FB900: @ 80FB900
	.incbin "baserom.gba", 0xFB900, 0x24

	.global gUnknown_80FB924
gUnknown_80FB924: @ 80FB924
	.incbin "baserom.gba", 0xFB924, 0x1C

	.global gUnknown_80FB940
gUnknown_80FB940: @ 80FB940
	.incbin "baserom.gba", 0xFB940, 0x20

	.global gUnknown_80FB960
gUnknown_80FB960: @ 80FB960
	.incbin "baserom.gba", 0xFB960, 0x18

	.global gUnknown_80FB978
gUnknown_80FB978: @ 80FB978
	.incbin "baserom.gba", 0xFB978, 0x1C

	.global gUnknown_80FB994
gUnknown_80FB994: @ 80FB994
	.incbin "baserom.gba", 0xFB994, 0x1C

	.global gUnknown_80FB9B0
gUnknown_80FB9B0: @ 80FB9B0
	.incbin "baserom.gba", 0xFB9B0, 0x28

	.global gUnknown_80FB9D8
gUnknown_80FB9D8: @ 80FB9D8
	.incbin "baserom.gba", 0xFB9D8, 0x18

	.global gUnknown_80FB9F0
gUnknown_80FB9F0: @ 80FB9F0
	.incbin "baserom.gba", 0xFB9F0, 0x24

	.global gUnknown_80FBA14
gUnknown_80FBA14: @ 80FBA14
	.incbin "baserom.gba", 0xFBA14, 0x24

	.global gUnknown_80FBA38
gUnknown_80FBA38: @ 80FBA38
	.incbin "baserom.gba", 0xFBA38, 0x28

	.global gUnknown_80FBA60
gUnknown_80FBA60: @ 80FBA60
	.incbin "baserom.gba", 0xFBA60, 0x20

	.global gUnknown_80FBA80
gUnknown_80FBA80: @ 80FBA80
	.incbin "baserom.gba", 0xFBA80, 0x20

	.global gUnknown_80FBAA0
gUnknown_80FBAA0: @ 80FBAA0
	.incbin "baserom.gba", 0xFBAA0, 0x20

	.global gUnknown_80FBAC0
gUnknown_80FBAC0: @ 80FBAC0
	.incbin "baserom.gba", 0xFBAC0, 0x24

	.global gUnknown_80FBAE4
gUnknown_80FBAE4: @ 80FBAE4
	.incbin "baserom.gba", 0xFBAE4, 0x20

	.global gUnknown_80FBB04
gUnknown_80FBB04: @ 80FBB04
	.incbin "baserom.gba", 0xFBB04, 0x24

	.global gUnknown_80FBB28
gUnknown_80FBB28: @ 80FBB28
	.incbin "baserom.gba", 0xFBB28, 0x24

	.global gUnknown_80FBB4C
gUnknown_80FBB4C: @ 80FBB4C
	.incbin "baserom.gba", 0xFBB4C, 0x2C

	.global gUnknown_80FBB78
gUnknown_80FBB78: @ 80FBB78
	.incbin "baserom.gba", 0xFBB78, 0x1C

	.global gUnknown_80FBB94
gUnknown_80FBB94: @ 80FBB94
	.incbin "baserom.gba", 0xFBB94, 0x24

	.global gUnknown_80FBBB8
gUnknown_80FBBB8: @ 80FBBB8
	.incbin "baserom.gba", 0xFBBB8, 0x1C

	.global gUnknown_80FBBD4
gUnknown_80FBBD4: @ 80FBBD4
	.incbin "baserom.gba", 0xFBBD4, 0x1C

	.global gUnknown_80FBBF0
gUnknown_80FBBF0: @ 80FBBF0
	.incbin "baserom.gba", 0xFBBF0, 0x24

	.global gUnknown_80FBC14
gUnknown_80FBC14: @ 80FBC14
	.incbin "baserom.gba", 0xFBC14, 0x24

	.global gUnknown_80FBC38
gUnknown_80FBC38: @ 80FBC38
	.incbin "baserom.gba", 0xFBC38, 0x24

	.global gUnknown_80FBC5C
gUnknown_80FBC5C: @ 80FBC5C
	.incbin "baserom.gba", 0xFBC5C, 0x20

	.global gUnknown_80FBC7C
gUnknown_80FBC7C: @ 80FBC7C
	.incbin "baserom.gba", 0xFBC7C, 0x28

	.global gUnknown_80FBCA4
gUnknown_80FBCA4: @ 80FBCA4
	.incbin "baserom.gba", 0xFBCA4, 0x24

	.global gUnknown_80FBCC8
gUnknown_80FBCC8: @ 80FBCC8
	.incbin "baserom.gba", 0xFBCC8, 0x28

	.global gUnknown_80FBCF0
gUnknown_80FBCF0: @ 80FBCF0
	.incbin "baserom.gba", 0xFBCF0, 0x28

	.global gUnknown_80FBD18
gUnknown_80FBD18: @ 80FBD18
	.incbin "baserom.gba", 0xFBD18, 0x24

	.global gUnknown_80FBD3C
gUnknown_80FBD3C: @ 80FBD3C
	.incbin "baserom.gba", 0xFBD3C, 0x1C

	.global gUnknown_80FBD58
gUnknown_80FBD58: @ 80FBD58
	.incbin "baserom.gba", 0xFBD58, 0x20

	.global gUnknown_80FBD78
gUnknown_80FBD78: @ 80FBD78
	.incbin "baserom.gba", 0xFBD78, 0x24

	.global gUnknown_80FBD9C
gUnknown_80FBD9C: @ 80FBD9C
	.incbin "baserom.gba", 0xFBD9C, 0x28

	.global gUnknown_80FBDC4
gUnknown_80FBDC4: @ 80FBDC4
	.incbin "baserom.gba", 0xFBDC4, 0x2C

	.global gUnknown_80FBDF0
gUnknown_80FBDF0: @ 80FBDF0
	.incbin "baserom.gba", 0xFBDF0, 0x24

	.global gUnknown_80FBE14
gUnknown_80FBE14: @ 80FBE14
	.incbin "baserom.gba", 0xFBE14, 0x28

	.global gUnknown_80FBE3C
gUnknown_80FBE3C: @ 80FBE3C
	.incbin "baserom.gba", 0xFBE3C, 0x4

	.global gUnknown_80FBE40
gUnknown_80FBE40: @ 80FBE40
	.incbin "baserom.gba", 0xFBE40, 0x24

	.global gUnknown_80FBE64
gUnknown_80FBE64: @ 80FBE64
	.incbin "baserom.gba", 0xFBE64, 0x20

	.global gUnknown_80FBE84
gUnknown_80FBE84: @ 80FBE84
	.incbin "baserom.gba", 0xFBE84, 0x1C

	.global gUnknown_80FBEA0
gUnknown_80FBEA0: @ 80FBEA0
	.incbin "baserom.gba", 0xFBEA0, 0x20

	.global gUnknown_80FBEC0
gUnknown_80FBEC0: @ 80FBEC0
	.incbin "baserom.gba", 0xFBEC0, 0x24

	.global gUnknown_80FBEE4
gUnknown_80FBEE4: @ 80FBEE4
	.incbin "baserom.gba", 0xFBEE4, 0x20

	.global gUnknown_80FBF04
gUnknown_80FBF04: @ 80FBF04
	.incbin "baserom.gba", 0xFBF04, 0x24

	.global gUnknown_80FBF28
gUnknown_80FBF28: @ 80FBF28
	.incbin "baserom.gba", 0xFBF28, 0x28

	.global gUnknown_80FBF50
gUnknown_80FBF50: @ 80FBF50
	.incbin "baserom.gba", 0xFBF50, 0x18

	.global gUnknown_80FBF68
gUnknown_80FBF68: @ 80FBF68
	.incbin "baserom.gba", 0xFBF68, 0x1C

	.global gUnknown_80FBF84
gUnknown_80FBF84: @ 80FBF84
	.incbin "baserom.gba", 0xFBF84, 0x18

	.global gUnknown_80FBF9C
gUnknown_80FBF9C: @ 80FBF9C
	.incbin "baserom.gba", 0xFBF9C, 0x1C

	.global gUnknown_80FBFB8
gUnknown_80FBFB8: @ 80FBFB8
	.incbin "baserom.gba", 0xFBFB8, 0x20

	.global gUnknown_80FBFD8
gUnknown_80FBFD8: @ 80FBFD8
	.incbin "baserom.gba", 0xFBFD8, 0x28

	.global gUnknown_80FC000
gUnknown_80FC000: @ 80FC000
	.incbin "baserom.gba", 0xFC000, 0x28

	.global gUnknown_80FC028
gUnknown_80FC028: @ 80FC028
	.incbin "baserom.gba", 0xFC028, 0x2C

	.global gUnknown_80FC054
gUnknown_80FC054: @ 80FC054
	.incbin "baserom.gba", 0xFC054, 0x20

	.global gUnknown_80FC074
gUnknown_80FC074: @ 80FC074
	.incbin "baserom.gba", 0xFC074, 0x10

	.global gUnknown_80FC084
gUnknown_80FC084: @ 80FC084
	.incbin "baserom.gba", 0xFC084, 0xC

	.global gUnknown_80FC090
gUnknown_80FC090: @ 80FC090
	.incbin "baserom.gba", 0xFC090, 0xC

	.global gUnknown_80FC09C
gUnknown_80FC09C: @ 80FC09C
	.incbin "baserom.gba", 0xFC09C, 0x10

	.global gUnknown_80FC0AC
gUnknown_80FC0AC: @ 80FC0AC
	.incbin "baserom.gba", 0xFC0AC, 0xC

	.global gUnknown_80FC0B8
gUnknown_80FC0B8: @ 80FC0B8
	.incbin "baserom.gba", 0xFC0B8, 0x10

	.global gUnknown_80FC0C8
gUnknown_80FC0C8: @ 80FC0C8
	.incbin "baserom.gba", 0xFC0C8, 0xC

	.global gUnknown_80FC0D4
gUnknown_80FC0D4: @ 80FC0D4
	.incbin "baserom.gba", 0xFC0D4, 0x10

	.global gUnknown_80FC0E4
gUnknown_80FC0E4: @ 80FC0E4
	.incbin "baserom.gba", 0xFC0E4, 0x18

	.global gUnknown_80FC0FC
gUnknown_80FC0FC: @ 80FC0FC
	.incbin "baserom.gba", 0xFC0FC, 0x18

	.global gUnknown_80FC114
gUnknown_80FC114: @ 80FC114
	.incbin "baserom.gba", 0xFC114, 0x4

	.global gUnknown_80FC118
gUnknown_80FC118: @ 80FC118
	.incbin "baserom.gba", 0xFC118, 0x4

	.global gUnknown_80FC11C
gUnknown_80FC11C: @ 80FC11C
	.incbin "baserom.gba", 0xFC11C, 0x1C

	.global gUnknown_80FC138
gUnknown_80FC138: @ 80FC138
	.incbin "baserom.gba", 0xFC138, 0x4

	.global gUnknown_80FC13C
gUnknown_80FC13C: @ 80FC13C
	.incbin "baserom.gba", 0xFC13C, 0x1C

	.global gUnknown_80FC158
gUnknown_80FC158: @ 80FC158
	.incbin "baserom.gba", 0xFC158, 0x4

	.global gUnknown_80FC15C
gUnknown_80FC15C: @ 80FC15C
	.incbin "baserom.gba", 0xFC15C, 0x24

	.global gUnknown_80FC180
gUnknown_80FC180: @ 80FC180
	.incbin "baserom.gba", 0xFC180, 0x4

	.global gUnknown_80FC184
gUnknown_80FC184: @ 80FC184
	.incbin "baserom.gba", 0xFC184, 0x20

	.global gUnknown_80FC1A4
gUnknown_80FC1A4: @ 80FC1A4
	.incbin "baserom.gba", 0xFC1A4, 0x20

	.global gUnknown_80FC1C4
gUnknown_80FC1C4: @ 80FC1C4
	.incbin "baserom.gba", 0xFC1C4, 0x2C

	.global gUnknown_80FC1F0
gUnknown_80FC1F0: @ 80FC1F0
	.incbin "baserom.gba", 0xFC1F0, 0x28

	.global gUnknown_80FC218
gUnknown_80FC218: @ 80FC218
	.incbin "baserom.gba", 0xFC218, 0x4

	.global gUnknown_80FC21C
gUnknown_80FC21C: @ 80FC21C
	.incbin "baserom.gba", 0xFC21C, 0x2C

	.global gUnknown_80FC248
gUnknown_80FC248: @ 80FC248
	.incbin "baserom.gba", 0xFC248, 0x28

	.global gUnknown_80FC270
gUnknown_80FC270: @ 80FC270
	.incbin "baserom.gba", 0xFC270, 0x4

	.global gUnknown_80FC274
gUnknown_80FC274: @ 80FC274
	.incbin "baserom.gba", 0xFC274, 0x24

	.global gUnknown_80FC298
gUnknown_80FC298: @ 80FC298
	.incbin "baserom.gba", 0xFC298, 0x20

	.global gUnknown_80FC2B8
gUnknown_80FC2B8: @ 80FC2B8
	.incbin "baserom.gba", 0xFC2B8, 0x20

	.global gUnknown_80FC2D8
gUnknown_80FC2D8: @ 80FC2D8
	.incbin "baserom.gba", 0xFC2D8, 0x24

	.global gUnknown_80FC2FC
gUnknown_80FC2FC: @ 80FC2FC
	.incbin "baserom.gba", 0xFC2FC, 0x20

	.global gUnknown_80FC31C
gUnknown_80FC31C: @ 80FC31C
	.incbin "baserom.gba", 0xFC31C, 0x20

	.global gUnknown_80FC33C
gUnknown_80FC33C: @ 80FC33C
	.incbin "baserom.gba", 0xFC33C, 0x24

	.global gUnknown_80FC360
gUnknown_80FC360: @ 80FC360
	.incbin "baserom.gba", 0xFC360, 0x28

	.global gUnknown_80FC388
gUnknown_80FC388: @ 80FC388
	.incbin "baserom.gba", 0xFC388, 0x2C

	.global gUnknown_80FC3B4
gUnknown_80FC3B4: @ 80FC3B4
	.incbin "baserom.gba", 0xFC3B4, 0x24

	.global gUnknown_80FC3D8
gUnknown_80FC3D8: @ 80FC3D8
	.incbin "baserom.gba", 0xFC3D8, 0x24

	.global gUnknown_80FC3FC
gUnknown_80FC3FC: @ 80FC3FC
	.incbin "baserom.gba", 0xFC3FC, 0x2C

	.global gUnknown_80FC428
gUnknown_80FC428: @ 80FC428
	.incbin "baserom.gba", 0xFC428, 0x2C

	.global gUnknown_80FC454
gUnknown_80FC454: @ 80FC454
	.incbin "baserom.gba", 0xFC454, 0xD8

	.global gUnknown_80FC52C
gUnknown_80FC52C: @ 80FC52C
	.incbin "baserom.gba", 0xFC52C, 0x2C

	.global gUnknown_80FC558
gUnknown_80FC558: @ 80FC558
	.incbin "baserom.gba", 0xFC558, 0x1C

	.global gUnknown_80FC574
gUnknown_80FC574: @ 80FC574
	.incbin "baserom.gba", 0xFC574, 0x10

	.global gUnknown_80FC584
gUnknown_80FC584: @ 80FC584
	.incbin "baserom.gba", 0xFC584, 0x24

	.global gUnknown_80FC5A8
gUnknown_80FC5A8: @ 80FC5A8
	.incbin "baserom.gba", 0xFC5A8, 0x24

	.global gUnknown_80FC5CC
gUnknown_80FC5CC: @ 80FC5CC
	.incbin "baserom.gba", 0xFC5CC, 0x14

	.global gUnknown_80FC5E0
gUnknown_80FC5E0: @ 80FC5E0
	.incbin "baserom.gba", 0xFC5E0, 0x18

	.global gUnknown_80FC5F8
gUnknown_80FC5F8: @ 80FC5F8
	.incbin "baserom.gba", 0xFC5F8, 0x4

	.global gUnknown_80FC5FC
gUnknown_80FC5FC: @ 80FC5FC
	.incbin "baserom.gba", 0xFC5FC, 0x18

	.global gUnknown_80FC614
gUnknown_80FC614: @ 80FC614
	.incbin "baserom.gba", 0xFC614, 0x40

	.global gUnknown_80FC654
gUnknown_80FC654: @ 80FC654
	.incbin "baserom.gba", 0xFC654, 0x24

	.global gUnknown_80FC678
gUnknown_80FC678: @ 80FC678
	.incbin "baserom.gba", 0xFC678, 0x18

	.global gUnknown_80FC690
gUnknown_80FC690: @ 80FC690
	.incbin "baserom.gba", 0xFC690, 0x14

	.global gUnknown_80FC6A4
gUnknown_80FC6A4: @ 80FC6A4
	.incbin "baserom.gba", 0xFC6A4, 0x4

	.global gUnknown_80FC6A8
gUnknown_80FC6A8: @ 80FC6A8
	.incbin "baserom.gba", 0xFC6A8, 0x28

	.global gUnknown_80FC6D0
gUnknown_80FC6D0: @ 80FC6D0
	.incbin "baserom.gba", 0xFC6D0, 0x2C

	.global gUnknown_80FC6FC
gUnknown_80FC6FC: @ 80FC6FC
	.incbin "baserom.gba", 0xFC6FC, 0x14

	.global gUnknown_80FC710
gUnknown_80FC710: @ 80FC710
	.incbin "baserom.gba", 0xFC710, 0x4

	.global gUnknown_80FC714
gUnknown_80FC714: @ 80FC714
	.incbin "baserom.gba", 0xFC714, 0x4

	.global gUnknown_80FC718
gUnknown_80FC718: @ 80FC718
	.incbin "baserom.gba", 0xFC718, 0x14

	.global gUnknown_80FC72C
gUnknown_80FC72C: @ 80FC72C
	.incbin "baserom.gba", 0xFC72C, 0x4

	.global gUnknown_80FC730
gUnknown_80FC730: @ 80FC730
	.incbin "baserom.gba", 0xFC730, 0x4

	.global gUnknown_80FC734
gUnknown_80FC734: @ 80FC734
	.incbin "baserom.gba", 0xFC734, 0x18

	.global gUnknown_80FC74C
gUnknown_80FC74C: @ 80FC74C
	.incbin "baserom.gba", 0xFC74C, 0x24

	.global gUnknown_80FC770
gUnknown_80FC770: @ 80FC770
	.incbin "baserom.gba", 0xFC770, 0x20

	.global gUnknown_80FC790
gUnknown_80FC790: @ 80FC790
	.incbin "baserom.gba", 0xFC790, 0x1C

	.global gUnknown_80FC7AC
gUnknown_80FC7AC: @ 80FC7AC
	.incbin "baserom.gba", 0xFC7AC, 0x1C

	.global gUnknown_80FC7C8
gUnknown_80FC7C8: @ 80FC7C8
	.incbin "baserom.gba", 0xFC7C8, 0x24

	.global gUnknown_80FC7EC
gUnknown_80FC7EC: @ 80FC7EC
	.incbin "baserom.gba", 0xFC7EC, 0x30

	.global gUnknown_80FC81C
gUnknown_80FC81C: @ 80FC81C
	.incbin "baserom.gba", 0xFC81C, 0x38

	.global gUnknown_80FC854
gUnknown_80FC854: @ 80FC854
	.incbin "baserom.gba", 0xFC854, 0x34

	.global gUnknown_80FC888
gUnknown_80FC888: @ 80FC888
	.incbin "baserom.gba", 0xFC888, 0x38

	.global gUnknown_80FC8C0
gUnknown_80FC8C0: @ 80FC8C0
	.incbin "baserom.gba", 0xFC8C0, 0x30

	.global gUnknown_80FC8F0
gUnknown_80FC8F0: @ 80FC8F0
	.incbin "baserom.gba", 0xFC8F0, 0x30

	.global gUnknown_80FC920
gUnknown_80FC920: @ 80FC920
	.incbin "baserom.gba", 0xFC920, 0x5C

	.global gUnknown_80FC97C
gUnknown_80FC97C: @ 80FC97C
	.incbin "baserom.gba", 0xFC97C, 0x24

	.global gUnknown_80FC9A0
gUnknown_80FC9A0: @ 80FC9A0
	.incbin "baserom.gba", 0xFC9A0, 0x20

	.global gUnknown_80FC9C0
gUnknown_80FC9C0: @ 80FC9C0
	.incbin "baserom.gba", 0xFC9C0, 0x28

	.global gUnknown_80FC9E8
gUnknown_80FC9E8: @ 80FC9E8
	.incbin "baserom.gba", 0xFC9E8, 0x28

	.global gUnknown_80FCA10
gUnknown_80FCA10: @ 80FCA10
	.incbin "baserom.gba", 0xFCA10, 0x2C

	.global gUnknown_80FCA3C
gUnknown_80FCA3C: @ 80FCA3C
	.incbin "baserom.gba", 0xFCA3C, 0x24

	.global gUnknown_80FCA60
gUnknown_80FCA60: @ 80FCA60
	.incbin "baserom.gba", 0xFCA60, 0x4

	.global gUnknown_80FCA64
gUnknown_80FCA64: @ 80FCA64
	.incbin "baserom.gba", 0xFCA64, 0x2C

	.global gUnknown_80FCA90
gUnknown_80FCA90: @ 80FCA90
	.incbin "baserom.gba", 0xFCA90, 0x30

	.global gUnknown_80FCAC0
gUnknown_80FCAC0: @ 80FCAC0
	.incbin "baserom.gba", 0xFCAC0, 0x28

	.global gUnknown_80FCAE8
gUnknown_80FCAE8: @ 80FCAE8
	.incbin "baserom.gba", 0xFCAE8, 0x2C

	.global gUnknown_80FCB14
gUnknown_80FCB14: @ 80FCB14
	.incbin "baserom.gba", 0xFCB14, 0x2C

	.global gUnknown_80FCB40
gUnknown_80FCB40: @ 80FCB40
	.incbin "baserom.gba", 0xFCB40, 0x30

	.global gUnknown_80FCB70
gUnknown_80FCB70: @ 80FCB70
	.incbin "baserom.gba", 0xFCB70, 0x28

	.global gUnknown_80FCB98
gUnknown_80FCB98: @ 80FCB98
	.incbin "baserom.gba", 0xFCB98, 0x34

	.global gUnknown_80FCBCC
gUnknown_80FCBCC: @ 80FCBCC
	.incbin "baserom.gba", 0xFCBCC, 0x2C

	.global gUnknown_80FCBF8
gUnknown_80FCBF8: @ 80FCBF8
	.incbin "baserom.gba", 0xFCBF8, 0x20

	.global gUnknown_80FCC18
gUnknown_80FCC18: @ 80FCC18
	.incbin "baserom.gba", 0xFCC18, 0x34

	.global gUnknown_80FCC4C
gUnknown_80FCC4C: @ 80FCC4C
	.incbin "baserom.gba", 0xFCC4C, 0x30

	.global gUnknown_80FCC7C
gUnknown_80FCC7C: @ 80FCC7C
	.incbin "baserom.gba", 0xFCC7C, 0x30

	.global gUnknown_80FCCAC
gUnknown_80FCCAC: @ 80FCCAC
	.incbin "baserom.gba", 0xFCCAC, 0x38

	.global gUnknown_80FCCE4
gUnknown_80FCCE4: @ 80FCCE4
	.incbin "baserom.gba", 0xFCCE4, 0x4

	.global gUnknown_80FCCE8
gUnknown_80FCCE8: @ 80FCCE8
	.incbin "baserom.gba", 0xFCCE8, 0x24

	.global gUnknown_80FCD0C
gUnknown_80FCD0C: @ 80FCD0C
	.incbin "baserom.gba", 0xFCD0C, 0x1C

	.global gUnknown_80FCD28
gUnknown_80FCD28: @ 80FCD28
	.incbin "baserom.gba", 0xFCD28, 0x2C

	.global gUnknown_80FCD54
gUnknown_80FCD54: @ 80FCD54
	.incbin "baserom.gba", 0xFCD54, 0x4

	.global gUnknown_80FCD58
gUnknown_80FCD58: @ 80FCD58
	.incbin "baserom.gba", 0xFCD58, 0x30

	.global gUnknown_80FCD88
gUnknown_80FCD88: @ 80FCD88
	.incbin "baserom.gba", 0xFCD88, 0x2C

	.global gUnknown_80FCDB4
gUnknown_80FCDB4: @ 80FCDB4
	.incbin "baserom.gba", 0xFCDB4, 0x2C

	.global gUnknown_80FCDE0
gUnknown_80FCDE0: @ 80FCDE0
	.incbin "baserom.gba", 0xFCDE0, 0x20

	.global gUnknown_80FCE00
gUnknown_80FCE00: @ 80FCE00
	.incbin "baserom.gba", 0xFCE00, 0x34

	.global gUnknown_80FCE34
gUnknown_80FCE34: @ 80FCE34
	.incbin "baserom.gba", 0xFCE34, 0x28

	.global gUnknown_80FCE5C
gUnknown_80FCE5C: @ 80FCE5C
	.incbin "baserom.gba", 0xFCE5C, 0x28

	.global gUnknown_80FCE84
gUnknown_80FCE84: @ 80FCE84
	.incbin "baserom.gba", 0xFCE84, 0x2C

	.global gUnknown_80FCEB0
gUnknown_80FCEB0: @ 80FCEB0
	.incbin "baserom.gba", 0xFCEB0, 0x2C

	.global gUnknown_80FCEDC
gUnknown_80FCEDC: @ 80FCEDC
	.incbin "baserom.gba", 0xFCEDC, 0x20

	.global gUnknown_80FCEFC
gUnknown_80FCEFC: @ 80FCEFC
	.incbin "baserom.gba", 0xFCEFC, 0x1C

	.global gUnknown_80FCF18
gUnknown_80FCF18: @ 80FCF18
	.incbin "baserom.gba", 0xFCF18, 0x20

	.global gUnknown_80FCF38
gUnknown_80FCF38: @ 80FCF38
	.incbin "baserom.gba", 0xFCF38, 0x18

	.global gUnknown_80FCF50
gUnknown_80FCF50: @ 80FCF50
	.incbin "baserom.gba", 0xFCF50, 0x24

	.global gUnknown_80FCF74
gUnknown_80FCF74: @ 80FCF74
	.incbin "baserom.gba", 0xFCF74, 0x4

	.global gUnknown_80FCF78
gUnknown_80FCF78: @ 80FCF78
	.incbin "baserom.gba", 0xFCF78, 0x4

	.global gUnknown_80FCF7C
gUnknown_80FCF7C: @ 80FCF7C
	.incbin "baserom.gba", 0xFCF7C, 0x4

	.global gUnknown_80FCF80
gUnknown_80FCF80: @ 80FCF80
	.incbin "baserom.gba", 0xFCF80, 0x24

	.global gUnknown_80FCFA4
gUnknown_80FCFA4: @ 80FCFA4
	.incbin "baserom.gba", 0xFCFA4, 0x18

	.global gUnknown_80FCFBC
gUnknown_80FCFBC: @ 80FCFBC
	.incbin "baserom.gba", 0xFCFBC, 0x28

	.global gUnknown_80FCFE4
gUnknown_80FCFE4: @ 80FCFE4
	.incbin "baserom.gba", 0xFCFE4, 0x34

	.global gUnknown_80FD018
gUnknown_80FD018: @ 80FD018
	.incbin "baserom.gba", 0xFD018, 0x28

	.global gUnknown_80FD040
gUnknown_80FD040: @ 80FD040
	.incbin "baserom.gba", 0xFD040, 0x1C

	.global gUnknown_80FD05C
gUnknown_80FD05C: @ 80FD05C
	.incbin "baserom.gba", 0xFD05C, 0x4

	.global gUnknown_80FD060
gUnknown_80FD060: @ 80FD060
	.incbin "baserom.gba", 0xFD060, 0x2C

	.global gUnknown_80FD08C
gUnknown_80FD08C: @ 80FD08C
	.incbin "baserom.gba", 0xFD08C, 0x28

	.global gUnknown_80FD0B4
gUnknown_80FD0B4: @ 80FD0B4
	.incbin "baserom.gba", 0xFD0B4, 0x4

	.global gUnknown_80FD0B8
gUnknown_80FD0B8: @ 80FD0B8
	.incbin "baserom.gba", 0xFD0B8, 0x4C

	.global gUnknown_80FD104
gUnknown_80FD104: @ 80FD104
	.incbin "baserom.gba", 0xFD104, 0x24

	.global gUnknown_80FD128
gUnknown_80FD128: @ 80FD128
	.incbin "baserom.gba", 0xFD128, 0x24

	.global gUnknown_80FD14C
gUnknown_80FD14C: @ 80FD14C
	.incbin "baserom.gba", 0xFD14C, 0x24

	.global gUnknown_80FD170
gUnknown_80FD170: @ 80FD170
	.incbin "baserom.gba", 0xFD170, 0x1C

	.global gUnknown_80FD18C
gUnknown_80FD18C: @ 80FD18C
	.incbin "baserom.gba", 0xFD18C, 0x24

	.global gUnknown_80FD1B0
gUnknown_80FD1B0: @ 80FD1B0
	.incbin "baserom.gba", 0xFD1B0, 0x1C

	.global gUnknown_80FD1CC
gUnknown_80FD1CC: @ 80FD1CC
	.incbin "baserom.gba", 0xFD1CC, 0x20

	.global gUnknown_80FD1EC
gUnknown_80FD1EC: @ 80FD1EC
	.incbin "baserom.gba", 0xFD1EC, 0x20

	.global gUnknown_80FD20C
gUnknown_80FD20C: @ 80FD20C
	.incbin "baserom.gba", 0xFD20C, 0x20

	.global gUnknown_80FD22C
gUnknown_80FD22C: @ 80FD22C
	.incbin "baserom.gba", 0xFD22C, 0x28

	.global gUnknown_80FD254
gUnknown_80FD254: @ 80FD254
	.incbin "baserom.gba", 0xFD254, 0x28

	.global gUnknown_80FD27C
gUnknown_80FD27C: @ 80FD27C
	.incbin "baserom.gba", 0xFD27C, 0x18

	.global gUnknown_80FD294
gUnknown_80FD294: @ 80FD294
	.incbin "baserom.gba", 0xFD294, 0x20

	.global gUnknown_80FD2B4
gUnknown_80FD2B4: @ 80FD2B4
	.incbin "baserom.gba", 0xFD2B4, 0x18

	.global gUnknown_80FD2CC
gUnknown_80FD2CC: @ 80FD2CC
	.incbin "baserom.gba", 0xFD2CC, 0x10

	.global gUnknown_80FD2DC
gUnknown_80FD2DC: @ 80FD2DC
	.incbin "baserom.gba", 0xFD2DC, 0x1C

	.global gUnknown_80FD2F8
gUnknown_80FD2F8: @ 80FD2F8
	.incbin "baserom.gba", 0xFD2F8, 0x28

	.global gUnknown_80FD320
gUnknown_80FD320: @ 80FD320
	.incbin "baserom.gba", 0xFD320, 0x30

	.global gUnknown_80FD350
gUnknown_80FD350: @ 80FD350
	.incbin "baserom.gba", 0xFD350, 0x20

	.global gUnknown_80FD370
gUnknown_80FD370: @ 80FD370
	.incbin "baserom.gba", 0xFD370, 0x30

	.global gUnknown_80FD3A0
gUnknown_80FD3A0: @ 80FD3A0
	.incbin "baserom.gba", 0xFD3A0, 0x28

	.global gUnknown_80FD3C8
gUnknown_80FD3C8: @ 80FD3C8
	.incbin "baserom.gba", 0xFD3C8, 0x4

	.global gUnknown_80FD3CC
gUnknown_80FD3CC: @ 80FD3CC
	.incbin "baserom.gba", 0xFD3CC, 0x4

	.global gUnknown_80FD3D0
gUnknown_80FD3D0: @ 80FD3D0
	.incbin "baserom.gba", 0xFD3D0, 0x20

	.global gUnknown_80FD3F0
gUnknown_80FD3F0: @ 80FD3F0
	.incbin "baserom.gba", 0xFD3F0, 0x1C

	.global gUnknown_80FD40C
gUnknown_80FD40C: @ 80FD40C
	.incbin "baserom.gba", 0xFD40C, 0x24

	.global gUnknown_80FD430
gUnknown_80FD430: @ 80FD430
	.incbin "baserom.gba", 0xFD430, 0x4

	.global gUnknown_80FD434
gUnknown_80FD434: @ 80FD434
	.incbin "baserom.gba", 0xFD434, 0x1C

	.global gUnknown_80FD450
gUnknown_80FD450: @ 80FD450
	.incbin "baserom.gba", 0xFD450, 0x4

	.global gUnknown_80FD454
gUnknown_80FD454: @ 80FD454
	.incbin "baserom.gba", 0xFD454, 0x18

	.global gUnknown_80FD46C
gUnknown_80FD46C: @ 80FD46C
	.incbin "baserom.gba", 0xFD46C, 0x18

	.global gUnknown_80FD484
gUnknown_80FD484: @ 80FD484
	.incbin "baserom.gba", 0xFD484, 0x2C

	.global gUnknown_80FD4B0
gUnknown_80FD4B0: @ 80FD4B0
	.incbin "baserom.gba", 0xFD4B0, 0x14

	.global gUnknown_80FD4C4
gUnknown_80FD4C4: @ 80FD4C4
	.incbin "baserom.gba", 0xFD4C4, 0x18

	.global gUnknown_80FD4DC
gUnknown_80FD4DC: @ 80FD4DC
	.incbin "baserom.gba", 0xFD4DC, 0x24

	.global gUnknown_80FD500
gUnknown_80FD500: @ 80FD500
	.incbin "baserom.gba", 0xFD500, 0x24

	.global gUnknown_80FD524
gUnknown_80FD524: @ 80FD524
	.incbin "baserom.gba", 0xFD524, 0x24

	.global gUnknown_80FD548
gUnknown_80FD548: @ 80FD548
	.incbin "baserom.gba", 0xFD548, 0x8

	.global gUnknown_80FD550
gUnknown_80FD550: @ 80FD550
	.incbin "baserom.gba", 0xFD550, 0x24

	.global gUnknown_80FD574
gUnknown_80FD574: @ 80FD574
	.incbin "baserom.gba", 0xFD574, 0x4

	.global gUnknown_80FD578
gUnknown_80FD578: @ 80FD578
	.incbin "baserom.gba", 0xFD578, 0x4

	.global gUnknown_80FD57C
gUnknown_80FD57C: @ 80FD57C
	.incbin "baserom.gba", 0xFD57C, 0x18

	.global gUnknown_80FD594
gUnknown_80FD594: @ 80FD594
	.incbin "baserom.gba", 0xFD594, 0x24

	.global gUnknown_80FD5B8
gUnknown_80FD5B8: @ 80FD5B8
	.incbin "baserom.gba", 0xFD5B8, 0x24

	.global gUnknown_80FD5DC
gUnknown_80FD5DC: @ 80FD5DC
	.incbin "baserom.gba", 0xFD5DC, 0x2C

	.global gUnknown_80FD608
gUnknown_80FD608: @ 80FD608
	.incbin "baserom.gba", 0xFD608, 0x20

	.global gUnknown_80FD628
gUnknown_80FD628: @ 80FD628
	.incbin "baserom.gba", 0xFD628, 0x1C

	.global gUnknown_80FD644
gUnknown_80FD644: @ 80FD644
	.incbin "baserom.gba", 0xFD644, 0x4

	.global gUnknown_80FD648
gUnknown_80FD648: @ 80FD648
	.incbin "baserom.gba", 0xFD648, 0xA0

	.global gUnknown_80FD6E8
gUnknown_80FD6E8: @ 80FD6E8
	.incbin "baserom.gba", 0xFD6E8, 0xA0

	.global gUnknown_80FD788
gUnknown_80FD788: @ 80FD788
	.incbin "baserom.gba", 0xFD788, 0x24

	.global gUnknown_80FD7AC
gUnknown_80FD7AC: @ 80FD7AC
	.incbin "baserom.gba", 0xFD7AC, 0x28

	.global gUnknown_80FD7D4
gUnknown_80FD7D4: @ 80FD7D4
	.incbin "baserom.gba", 0xFD7D4, 0x20

	.global gUnknown_80FD7F4
gUnknown_80FD7F4: @ 80FD7F4
	.incbin "baserom.gba", 0xFD7F4, 0x4

	.global gUnknown_80FD7F8
gUnknown_80FD7F8: @ 80FD7F8
	.incbin "baserom.gba", 0xFD7F8, 0x288

	.global gUnknown_80FDA80
gUnknown_80FDA80: @ 80FDA80
	.incbin "baserom.gba", 0xFDA80, 0x20

	.global gUnknown_80FDAA0
gUnknown_80FDAA0: @ 80FDAA0
	.incbin "baserom.gba", 0xFDAA0, 0x2C

	.global gUnknown_80FDACC
gUnknown_80FDACC: @ 80FDACC
	.incbin "baserom.gba", 0xFDACC, 0x18

	.global gUnknown_80FDAE4
gUnknown_80FDAE4: @ 80FDAE4
	.incbin "baserom.gba", 0xFDAE4, 0x20

	.global gUnknown_80FDB04
gUnknown_80FDB04: @ 80FDB04
	.incbin "baserom.gba", 0xFDB04, 0x28

	.global gUnknown_80FDB2C
gUnknown_80FDB2C: @ 80FDB2C
	.incbin "baserom.gba", 0xFDB2C, 0x30

	.global gUnknown_80FDB5C
gUnknown_80FDB5C: @ 80FDB5C
	.incbin "baserom.gba", 0xFDB5C, 0x20

	.global gUnknown_80FDB7C
gUnknown_80FDB7C: @ 80FDB7C
	.incbin "baserom.gba", 0xFDB7C, 0x24

	.global gUnknown_80FDBA0
gUnknown_80FDBA0: @ 80FDBA0
	.incbin "baserom.gba", 0xFDBA0, 0x18

	.global gUnknown_80FDBB8
gUnknown_80FDBB8: @ 80FDBB8
	.incbin "baserom.gba", 0xFDBB8, 0x18

	.global gUnknown_80FDBD0
gUnknown_80FDBD0: @ 80FDBD0
	.incbin "baserom.gba", 0xFDBD0, 0x20

	.global gUnknown_80FDBF0
gUnknown_80FDBF0: @ 80FDBF0
	.incbin "baserom.gba", 0xFDBF0, 0x28

	.global gUnknown_80FDC18
gUnknown_80FDC18: @ 80FDC18
	.incbin "baserom.gba", 0xFDC18, 0x28

	.global gUnknown_80FDC40
gUnknown_80FDC40: @ 80FDC40
	.incbin "baserom.gba", 0xFDC40, 0x3C

	.global gUnknown_80FDC7C
gUnknown_80FDC7C: @ 80FDC7C
	.incbin "baserom.gba", 0xFDC7C, 0x20

	.global gUnknown_80FDC9C
gUnknown_80FDC9C: @ 80FDC9C
	.incbin "baserom.gba", 0xFDC9C, 0x4

	.global gUnknown_80FDCA0
gUnknown_80FDCA0: @ 80FDCA0
	.incbin "baserom.gba", 0xFDCA0, 0x4

	.global gUnknown_80FDCA4
gUnknown_80FDCA4: @ 80FDCA4
	.incbin "baserom.gba", 0xFDCA4, 0x24

	.global gUnknown_80FDCC8
gUnknown_80FDCC8: @ 80FDCC8
	.incbin "baserom.gba", 0xFDCC8, 0x1C

	.global gUnknown_80FDCE4
gUnknown_80FDCE4: @ 80FDCE4
	.incbin "baserom.gba", 0xFDCE4, 0x1C

	.global gUnknown_80FDD00
gUnknown_80FDD00: @ 80FDD00
	.incbin "baserom.gba", 0xFDD00, 0x20

	.global gUnknown_80FDD20
gUnknown_80FDD20: @ 80FDD20
	.incbin "baserom.gba", 0xFDD20, 0x28

	.global gUnknown_80FDD48
gUnknown_80FDD48: @ 80FDD48
	.incbin "baserom.gba", 0xFDD48, 0x40

	.global gUnknown_80FDD88
gUnknown_80FDD88: @ 80FDD88
	.incbin "baserom.gba", 0xFDD88, 0x20

	.global gUnknown_80FDDA8
gUnknown_80FDDA8: @ 80FDDA8
	.incbin "baserom.gba", 0xFDDA8, 0x4

	.global gUnknown_80FDDAC
gUnknown_80FDDAC: @ 80FDDAC
	.incbin "baserom.gba", 0xFDDAC, 0x24

	.global gUnknown_80FDDD0
gUnknown_80FDDD0: @ 80FDDD0
	.incbin "baserom.gba", 0xFDDD0, 0x20

	.global gUnknown_80FDDF0
gUnknown_80FDDF0: @ 80FDDF0
	.incbin "baserom.gba", 0xFDDF0, 0x28

	.global gUnknown_80FDE18
gUnknown_80FDE18: @ 80FDE18
	.incbin "baserom.gba", 0xFDE18, 0x54

	.global gUnknown_80FDE6C
gUnknown_80FDE6C: @ 80FDE6C
	.incbin "baserom.gba", 0xFDE6C, 0x4C

	.global gUnknown_80FDEB8
gUnknown_80FDEB8: @ 80FDEB8
	.incbin "baserom.gba", 0xFDEB8, 0x48

	.global gUnknown_80FDF00
gUnknown_80FDF00: @ 80FDF00
	.incbin "baserom.gba", 0xFDF00, 0x40

	.global gUnknown_80FDF40
gUnknown_80FDF40: @ 80FDF40
	.incbin "baserom.gba", 0xFDF40, 0x30

	.global gUnknown_80FDF70
gUnknown_80FDF70: @ 80FDF70
	.incbin "baserom.gba", 0xFDF70, 0x48

	.global gUnknown_80FDFB8
gUnknown_80FDFB8: @ 80FDFB8
	.incbin "baserom.gba", 0xFDFB8, 0x30

	.global gUnknown_80FDFE8
gUnknown_80FDFE8: @ 80FDFE8
	.incbin "baserom.gba", 0xFDFE8, 0x20

	.global gUnknown_80FE008
gUnknown_80FE008: @ 80FE008
	.incbin "baserom.gba", 0xFE008, 0x2C

	.global gUnknown_80FE034
gUnknown_80FE034: @ 80FE034
	.incbin "baserom.gba", 0xFE034, 0x2C

	.global gUnknown_80FE060
gUnknown_80FE060: @ 80FE060
	.incbin "baserom.gba", 0xFE060, 0x4C

	.global gUnknown_80FE0AC
gUnknown_80FE0AC: @ 80FE0AC
	.incbin "baserom.gba", 0xFE0AC, 0x48

	.global gUnknown_80FE0F4
gUnknown_80FE0F4: @ 80FE0F4
	.incbin "baserom.gba", 0xFE0F4, 0x4

	.global gUnknown_80FE0F8
gUnknown_80FE0F8: @ 80FE0F8
	.incbin "baserom.gba", 0xFE0F8, 0x3C

	.global gUnknown_80FE134
gUnknown_80FE134: @ 80FE134
	.incbin "baserom.gba", 0xFE134, 0x34

	.global gUnknown_80FE168
gUnknown_80FE168: @ 80FE168
	.incbin "baserom.gba", 0xFE168, 0x3C

	.global gUnknown_80FE1A4
gUnknown_80FE1A4: @ 80FE1A4
	.incbin "baserom.gba", 0xFE1A4, 0x68

	.global gUnknown_80FE20C
gUnknown_80FE20C: @ 80FE20C
	.incbin "baserom.gba", 0xFE20C, 0x5C

	.global gUnknown_80FE268
gUnknown_80FE268: @ 80FE268
	.incbin "baserom.gba", 0xFE268, 0x24

	.global gUnknown_80FE28C
gUnknown_80FE28C: @ 80FE28C
	.incbin "baserom.gba", 0xFE28C, 0x44

	.global gUnknown_80FE2D0
gUnknown_80FE2D0: @ 80FE2D0
	.incbin "baserom.gba", 0xFE2D0, 0x1C

	.global gUnknown_80FE2EC
gUnknown_80FE2EC: @ 80FE2EC
	.incbin "baserom.gba", 0xFE2EC, 0x1C

	.global gPtrItsaMonsterHouseMessage
gPtrItsaMonsterHouseMessage: @ 80FE308
	.incbin "baserom.gba", 0xFE308, 0x28

	.global gUnknown_80FE330
gUnknown_80FE330: @ 80FE330
	.incbin "baserom.gba", 0xFE330, 0x3C

	.global gUnknown_80FE36C
gUnknown_80FE36C: @ 80FE36C
	.incbin "baserom.gba", 0xFE36C, 0x20

	.global gUnknown_80FE38C
gUnknown_80FE38C: @ 80FE38C
	.incbin "baserom.gba", 0xFE38C, 0x30

	.global gUnknown_80FE3BC
gUnknown_80FE3BC: @ 80FE3BC
	.incbin "baserom.gba", 0xFE3BC, 0x2C

	.global gUnknown_80FE3E8
gUnknown_80FE3E8: @ 80FE3E8
	.incbin "baserom.gba", 0xFE3E8, 0x24

	.global gUnknown_80FE40C
gUnknown_80FE40C: @ 80FE40C
	.incbin "baserom.gba", 0xFE40C, 0x28

	.global gUnknown_80FE434
gUnknown_80FE434: @ 80FE434
	.incbin "baserom.gba", 0xFE434, 0x20

	.global gUnknown_80FE454
gUnknown_80FE454: @ 80FE454
	.incbin "baserom.gba", 0xFE454, 0x4

	.global gUnknown_80FE458
gUnknown_80FE458: @ 80FE458
	.incbin "baserom.gba", 0xFE458, 0x20

	.global gUnknown_80FE478
gUnknown_80FE478: @ 80FE478
	.incbin "baserom.gba", 0xFE478, 0x40

	.global gUnknown_80FE4B8
gUnknown_80FE4B8: @ 80FE4B8
	.incbin "baserom.gba", 0xFE4B8, 0x1C

	.global gUnknown_80FE4D4
gUnknown_80FE4D4: @ 80FE4D4
	.incbin "baserom.gba", 0xFE4D4, 0x20

	.global gUnknown_80FE4F4
gUnknown_80FE4F4: @ 80FE4F4
	.incbin "baserom.gba", 0xFE4F4, 0x2C

	.global gUnknown_80FE520
gUnknown_80FE520: @ 80FE520
	.incbin "baserom.gba", 0xFE520, 0x48

	.global gUnknown_80FE568
gUnknown_80FE568: @ 80FE568
	.incbin "baserom.gba", 0xFE568, 0x58

	.global gUnknown_80FE5C0
gUnknown_80FE5C0: @ 80FE5C0
	.incbin "baserom.gba", 0xFE5C0, 0x30

	.global gUnknown_80FE5F0
gUnknown_80FE5F0: @ 80FE5F0
	.incbin "baserom.gba", 0xFE5F0, 0x4C

	.global gUnknown_80FE63C
gUnknown_80FE63C: @ 80FE63C
	.incbin "baserom.gba", 0xFE63C, 0x20

	.global gUnknown_80FE65C
gUnknown_80FE65C: @ 80FE65C
	.incbin "baserom.gba", 0xFE65C, 0x18

	.global gUnknown_80FE674
gUnknown_80FE674: @ 80FE674
	.incbin "baserom.gba", 0xFE674, 0x1C

	.global gUnknown_80FE690
gUnknown_80FE690: @ 80FE690
	.incbin "baserom.gba", 0xFE690, 0x24

	.global gUnknown_80FE6B4
gUnknown_80FE6B4: @ 80FE6B4
	.incbin "baserom.gba", 0xFE6B4, 0x20

	.global gUnknown_80FE6D4
gUnknown_80FE6D4: @ 80FE6D4
	.incbin "baserom.gba", 0xFE6D4, 0x14

	.global gUnknown_80FE6E8
gUnknown_80FE6E8: @ 80FE6E8
	.incbin "baserom.gba", 0xFE6E8, 0xC

	.global gUnknown_80FE6F4
gUnknown_80FE6F4: @ 80FE6F4
	.incbin "baserom.gba", 0xFE6F4, 0x14

	.global gUnknown_80FE708
gUnknown_80FE708: @ 80FE708
        .byte 0xF8, 0xE6, 0x0F, 0x08

	.global gUnknown_80FE70C
gUnknown_80FE70C: @ 80FE70C
        .byte 0x28, 0x81, 0x0F, 0x08

        .string "Rescue Point\0"
        .align 2,0

	.global gUnknown_80FE720
gUnknown_80FE720: @ 80FE720
        .byte 0x10, 0xE7, 0x0F, 0x08

@ In Dungeon Game Options Menu

	.global gUnknown_80FE724
gUnknown_80FE724: @ 80FE724
        .byte 0x1C, 0x81, 0x0F, 0x08

        .global OptionsDungeonText
        OptionsDungeonText:
        .string "Dungeon\0"
        .align 2,0

	.global gOptionsDungeonTextPtr
gOptionsDungeonTextPtr: @ 80FE730
        .4byte OptionsDungeonText

        .global OptionsOthersText
        OptionsOthersText:
        .string "Others\0"
        .align 2,0

	.global gOptionsOthersTextPtr
gOptionsOthersTextPtr: @ 80FE73C
        .4byte OptionsOthersText

        .global OptionsDefaultText
        OptionsDefaultText:
        .string "Default\0"
        .align 2,0

	.global gUnknown_80FE748
gUnknown_80FE748: @ 80FE748
        .4byte OptionsDefaultText

@ Dungeon Game Options Menu

        .global OptionsSpeed
        OptionsSpeed:
        .string "Speed#=P.Slow#="
        .byte 0x88
        .string ".Fast\0"
        .align 2,0

	.global gUnknown_80FE764
gUnknown_80FE764: @ 80FE764
        .4byte OptionsSpeed

        .global OptionsFarOffPals
        OptionsFarOffPals:
        .string "Far-off pals#="
        .string "P.Self#="
        .byte 0x88
        .string ".Look\0"
        .align 2,0

	.global gUnknown_80FE788
gUnknown_80FE788: @ 80FE788
        .4byte OptionsFarOffPals

        .global OptionsDamageTurn
        OptionsDamageTurn:
        .string "Damage turn#=P."
        .string "No#="
        .byte 0x88
        .string ".Yes\0"
        .align 2,0

	.global gUnknown_80FE7A8
gUnknown_80FE7A8: @ 80FE7A8
        .4byte OptionsDamageTurn

        .global OptionsGrid
        OptionsGrid:
        .string "Grids#=P."
        .string "Off#="
        .byte 0x88
        .string ".On\0"
        .align 2,0

	.global gUnknown_80FE7C0
gUnknown_80FE7C0: @ 80FE7C0
        .4byte OptionsGrid

        .global OptionsMap
        OptionsMap:
        .string "Map#=P."
        .string "Off#=x."
        .string "Clear#="
        .byte 0xa0
        .string ".Shade\0"
        .align 2,0

	.global gUnknown_80FE7E4
gUnknown_80FE7E4: @ 80FE7E4
        .4byte OptionsMap

@ Field Others Menu

        .global OptionsWindowColor
        OptionsWindowColor:
        .string "Windows#=P."
        .string "Blue#=x."
        .string "Red#="
        .byte 0xa0
        .string ".Green\0"
        .align 2,0

	.global gOptionsWindowColorPtr
gOptionsWindowColorPtr: @ 80FE808
        .4byte OptionsWindowColor


        .4byte TopScreenMapData
        .4byte TopScreenMapData
        .4byte TopScreenMapData

        .4byte TopScreenMessageLog
        .4byte TopScreenMessageLog
        .4byte TopScreenMessageLog

        .4byte TopScreenMapAndTeam

        .global TopScreenMapAndTeam
        TopScreenMapAndTeam:
        .string "Top screen: Map and team\0"
        .align 2,0

        .global TopScreenMessageLog
        TopScreenMessageLog:
        .string "Top screen: Message log\0"
        .align 2,0

        .global TopScreenMapData
        TopScreenMapData:
        .string "Top screen: Team data\0"
        .align 2,0

        .4byte BottomScreenNoMap
        .4byte BottomScreenClearMap
        .4byte BottomScreenShadedMap
        .4byte BottomScreenNoMap
        .4byte BottomScreenClearMap
        .4byte BottomScreenShadedMap
        .4byte BottomScreenNoMap

        .global BottomScreenShadedMap
        BottomScreenShadedMap:
        .string "Bottom screen: Shaded map\0"
        .align 2,0

        .global BottomScreenClearMap
        BottomScreenClearMap:
        .string "Bottom screen: Clear map\0"
        .align 2,0

        .global BottomScreenNoMap
        BottomScreenNoMap:
        .string "Bottom screen: No map\0"
        .align 2,0

        .global GameOptionsText
        GameOptionsText:
        .string "Game Options\0"
        .align 2,0

	.global gGameOptionsTextPtr
gGameOptionsTextPtr: @ 80FE8F0
        .4byte GameOptionsText

	.global gUnknown_80FE8F4
gUnknown_80FE8F4: @ 80FE8F4
        .byte 0xa8, 0x7e, 0x0f, 0x08

	.global gUnknown_80FE8F8
gUnknown_80FE8F8: @ 80FE8F8
        .byte 0x34, 0xe7, 0x0f, 0x08

        .global TeamToolboxAText
        TeamToolboxAText:
        .string "Team Toolbox A"
        .align 2,0

	.global gTeamToolboxAPtr
gTeamToolboxAPtr: @ 80FE90C
        .4byte TeamToolboxAText

        .global TeamToolboxBText
        TeamToolboxBText:
        .string "Team Toolbox B"
        .align 2,0

	.global gTeamToolboxBPtr
gTeamToolboxBPtr: @ 80FE920
        .4byte TeamToolboxBText

        .global FieldItemMenuGroundText
        FieldItemMenuGroundText:
        .string "Ground\0"
        .align 2,0

	.global gFieldItemMenuGroundTextPtr
gFieldItemMenuGroundTextPtr: @ 80FE92C
        .4byte FieldItemMenuGroundText

        .global ItemText_80FE930
        ItemText_80FE930:
        .string "{ARG_POKEMON_0}{APOSTROPHE}s item\0"
        .align 2,0

	.global gUnknown_80FE940
gUnknown_80FE940: @ 80FE940
        .4byte ItemText_80FE930

        .global WhichText
        WhichText:
        .string "Which?\0"
        .align 2,0

	.global gWhichTextPtr1
gWhichTextPtr1: @ 80FE94C
        .4byte WhichText

	.global gWhichTextPtr2
gWhichTextPtr2: @ 80FE950
        .4byte WhichText

	.global gUnknown_80FE954
gUnknown_80FE954: @ 80FE954
        .4byte gMenuTacticsText

        .global ItemText_80FE958
        ItemText_80FE958:
        .string "{ARG_MOVE_ITEM_0}\0"
        .align 2,0

	.global gUnknown_80FE95C
gUnknown_80FE95C: @ 80FE95C
        .4byte ItemText_80FE958

	.global gUnknown_80FE960
gUnknown_80FE960: @ 80FE960
        .4byte ItemText_80FE958

	.global gUnknown_80FE964
gUnknown_80FE964: @ 80FE964
        .4byte ItemText_80FE958

        .global PokeMove_80FE968
        PokeMove_80FE968:
        .string "{ARG_POKEMON_0}{APOSTROPHE}s moves\0"
        .align 2,0

	.global gUnknown_80FE978
gUnknown_80FE978: @ 80FE978
        .4byte PokeMove_80FE968

        .global FieldMenuMovesEntry
        FieldMenuMovesEntry:
        .byte 0x23, 0x5f, 0x01, 0x2e
        .string "Moves\0"
        .align 2,0

	.global gFieldMenuMovesPtr
gFieldMenuMovesPtr: @ 80FE988
        .4byte FieldMenuMovesEntry

        .global FieldMenuItemsEntry
        FieldMenuItemsEntry:
        .byte 0x23, 0x5f, 0x02, 0x2e
        .string "Items\0"
        .align 2,0

	.global gFieldMenuItemsPtr
gFieldMenuItemsPtr: @ 80FE998
        .4byte FieldMenuItemsEntry

        .global FieldMenuTeamEntry
        FieldMenuTeamEntry:
        .byte 0x23, 0x5f, 0x03, 0x2e
        .string "Team\0"
        .align 2,0

	.global gFieldMenuTeamPtr
gFieldMenuTeamPtr: @ 80FE9A8
        .4byte FieldMenuTeamEntry

        .global FieldMenuOthersEntry
        FieldMenuOthersEntry:
        .byte 0x23, 0x5f, 0x04, 0x2e
        .string "Others\0"
        .align 2,0

	.global gFieldMenuOthersPtr
gFieldMenuOthersPtr: @ 80FE9B8
        .4byte FieldMenuOthersEntry

        .global FieldMenuGroundEntry
        FieldMenuGroundEntry:
        .byte 0x23, 0x5f, 0x05, 0x2e
        .string "Ground\0"
        .align 2,0

	.global gFieldMenuGroundPtr
gFieldMenuGroundPtr: @ 80FE9C8
        .4byte FieldMenuGroundEntry

	.global gUnknown_80FE9CC
gUnknown_80FE9CC: @ 80FE9CC
	.incbin "baserom.gba", 0xFE9CC, 0x1C

	.global gUnknown_80FE9E8
gUnknown_80FE9E8: @ 80FE9E8
	.incbin "baserom.gba", 0xFE9E8, 0x10

	.global gUnknown_80FE9F8
gUnknown_80FE9F8: @ 80FE9F8
	.incbin "baserom.gba", 0xFE9F8, 0x18

	.global gUnknown_80FEA10
gUnknown_80FEA10: @ 80FEA10
	.incbin "baserom.gba", 0xFEA10, 0x18

	.global gUnknown_80FEA28
gUnknown_80FEA28: @ 80FEA28
	.incbin "baserom.gba", 0xFEA28, 0x1C

	.global gUnknown_80FEA44
gUnknown_80FEA44: @ 80FEA44
	.incbin "baserom.gba", 0xFEA44, 0xC

	.global gUnknown_80FEA50
gUnknown_80FEA50: @ 80FEA50
	.incbin "baserom.gba", 0xFEA50, 0x18

	.global gUnknown_80FEA68
gUnknown_80FEA68: @ 80FEA68
        .byte 0x54, 0xEA, 0x0F, 0x08

        .global RecruitedPokemon_80FEA6C
        RecruitedPokemon_80FEA6C:
        .string "Recruited Pokémon\0"
        .align 2,0

	.global gUnknown_80FEA80
gUnknown_80FEA80: @ 80FEA80
        .4byte RecruitedPokemon_80FEA6C

        .string "None\0"
        .align 2,0

	.global gUnknown_80FEA8C
gUnknown_80FEA8C: @ 80FEA8C
	.incbin "baserom.gba", 0xFEA8C, 0x38

	.global gUnknown_80FEAC4
gUnknown_80FEAC4: @ 80FEAC4
	.incbin "baserom.gba", 0xFEAC4, 0x24

	.global gUnknown_80FEAE8
gUnknown_80FEAE8: @ 80FEAE8
	.incbin "baserom.gba", 0xFEAE8, 0x20

	.global gUnknown_80FEB08
gUnknown_80FEB08: @ 80FEB08
	.incbin "baserom.gba", 0xFEB08, 0x28

	.global gUnknown_80FEB30
gUnknown_80FEB30: @ 80FEB30
	.incbin "baserom.gba", 0xFEB30, 0x30

	.global gUnknown_80FEB60
gUnknown_80FEB60: @ 80FEB60
	.incbin "baserom.gba", 0xFEB60, 0x28

	.global gUnknown_80FEB88
gUnknown_80FEB88: @ 80FEB88
	.incbin "baserom.gba", 0xFEB88, 0x4

	.global gUnknown_80FEB8C
gUnknown_80FEB8C: @ 80FEB8C
	.incbin "baserom.gba", 0xFEB8C, 0x4

	.global gUnknown_80FEB90
gUnknown_80FEB90: @ 80FEB90
	.incbin "baserom.gba", 0xFEB90, 0x2C

	.global gUnknown_80FEBBC
gUnknown_80FEBBC: @ 80FEBBC
	.incbin "baserom.gba", 0xFEBBC, 0x20

	.global gUnknown_80FEBDC
gUnknown_80FEBDC: @ 80FEBDC
	.incbin "baserom.gba", 0xFEBDC, 0x1C

	.global gUnknown_80FEBF8
gUnknown_80FEBF8: @ 80FEBF8
	.incbin "baserom.gba", 0xFEBF8, 0x30

	.global gUnknown_80FEC28
gUnknown_80FEC28: @ 80FEC28
	.incbin "baserom.gba", 0xFEC28, 0x20

	.global gUnknown_80FEC48
gUnknown_80FEC48: @ 80FEC48
	.incbin "baserom.gba", 0xFEC48, 0x34

	.global gUnknown_80FEC7C
gUnknown_80FEC7C: @ 80FEC7C
	.incbin "baserom.gba", 0xFEC7C, 0x24

	.global gUnknown_80FECA0
gUnknown_80FECA0: @ 80FECA0
	.incbin "baserom.gba", 0xFECA0, 0x1C

	.global gUnknown_80FECBC
gUnknown_80FECBC: @ 80FECBC
	.incbin "baserom.gba", 0xFECBC, 0x24

	.global gUnknown_80FECE0
gUnknown_80FECE0: @ 80FECE0
	.incbin "baserom.gba", 0xFECE0, 0x20

	.global gUnknown_80FED00
gUnknown_80FED00: @ 80FED00
        @ replacing .incbin "baserom.gba", 0x000fed00, 0x4
        .4byte 0x80fece4

	.global gUnknown_80FED04
gUnknown_80FED04: @ 80FED04
        @ replacing .incbin "baserom.gba", 0x000fed04, 0x4
        .4byte 0x80f89dc

	.global gUnknown_80FED08
gUnknown_80FED08: @ 80FED08
        @ replacing .incbin "baserom.gba", 0x000fed08, 0x4
        .4byte 0x80f89dc


	.global gUnknown_80FED0C
gUnknown_80FED0C: @ 80FED0C
	.incbin "baserom.gba", 0xFED0C, 0x24

	.global gUnknown_80FED30
gUnknown_80FED30: @ 80FED30
	.incbin "baserom.gba", 0xFED30, 0x38

	.global gUnknown_80FED68
gUnknown_80FED68: @ 80FED68
	.incbin "baserom.gba", 0xFED68, 0x20

	.global gUnknown_80FED88
gUnknown_80FED88: @ 80FED88
	.incbin "baserom.gba", 0xFED88, 0x20

	.global gUnknown_80FEDA8
gUnknown_80FEDA8: @ 80FEDA8
	.incbin "baserom.gba", 0xFEDA8, 0x20

	.global gUnknown_80FEDC8
gUnknown_80FEDC8: @ 80FEDC8
	.incbin "baserom.gba", 0xFEDC8, 0x20

	.global gUnknown_80FEDE8
gUnknown_80FEDE8: @ 80FEDE8
	.incbin "baserom.gba", 0xFEDE8, 0x1C

	.global gUnknown_80FEE04
gUnknown_80FEE04: @ 80FEE04
	.incbin "baserom.gba", 0xFEE04, 0x28

	.global gUnknown_80FEE2C
gUnknown_80FEE2C: @ 80FEE2C
	.incbin "baserom.gba", 0xFEE2C, 0x28

	.global gUnknown_80FEE54
gUnknown_80FEE54: @ 80FEE54
	.incbin "baserom.gba", 0xFEE54, 0x2C

	.global gUnknown_80FEE80
gUnknown_80FEE80: @ 80FEE80
	.incbin "baserom.gba", 0xFEE80, 0x24

	.global gUnknown_80FEEA4
gUnknown_80FEEA4: @ 80FEEA4
	.incbin "baserom.gba", 0xFEEA4, 0x24

	.global gUnknown_80FEEC8
gUnknown_80FEEC8: @ 80FEEC8
	.incbin "baserom.gba", 0xFEEC8, 0x24

	.global gUnknown_80FEEEC
gUnknown_80FEEEC: @ 80FEEEC
	.incbin "baserom.gba", 0xFEEEC, 0x20

	.global gUnknown_80FEF0C
gUnknown_80FEF0C: @ 80FEF0C
	.incbin "baserom.gba", 0xFEF0C, 0x24

	.global gUnknown_80FEF30
gUnknown_80FEF30: @ 80FEF30
	.incbin "baserom.gba", 0xFEF30, 0x1C

	.global gUnknown_80FEF4C
gUnknown_80FEF4C: @ 80FEF4C
        @ replacing .incbin "baserom.gba", 0x000fef4c, 0x4
        .4byte 0x80fef34

	.global gUnknown_80FEF50
gUnknown_80FEF50: @ 80FEF50
        @ replacing .incbin "baserom.gba", 0x000fef50, 0x4
        .4byte 0x80fef10

	.global gUnknown_80FEF54
gUnknown_80FEF54: @ 80FEF54
	.incbin "baserom.gba", 0xFEF54, 0x20

	.global gUnknown_80FEF74
gUnknown_80FEF74: @ 80FEF74
	.incbin "baserom.gba", 0xFEF74, 0x24

	.global gUnknown_80FEF98
gUnknown_80FEF98: @ 80FEF98
	.incbin "baserom.gba", 0xFEF98, 0x38

	.global gUnknown_80FEFD0
gUnknown_80FEFD0: @ 80FEFD0
	.incbin "baserom.gba", 0xFEFD0, 0x24

	.global gUnknown_80FEFF4
gUnknown_80FEFF4: @ 80FEFF4
	.incbin "baserom.gba", 0xFEFF4, 0x28

	.global gUnknown_80FF01C
gUnknown_80FF01C: @ 80FF01C
	.incbin "baserom.gba", 0xFF01C, 0x4

	.global gUnknown_80FF020
gUnknown_80FF020: @ 80FF020
	.incbin "baserom.gba", 0xFF020, 0x60

	.global gUnknown_80FF080
gUnknown_80FF080: @ 80FF080
	.incbin "baserom.gba", 0xFF080, 0x58

	.global gUnknown_80FF0D8
gUnknown_80FF0D8: @ 80FF0D8
	.incbin "baserom.gba", 0xFF0D8, 0x64

	.global gUnknown_80FF13C
gUnknown_80FF13C: @ 80FF13C
	.incbin "baserom.gba", 0xFF13C, 0x78

	.global gUnknown_80FF1B4
gUnknown_80FF1B4: @ 80FF1B4
	.incbin "baserom.gba", 0xFF1B4, 0x78

	.global gUnknown_80FF22C
gUnknown_80FF22C: @ 80FF22C
	.incbin "baserom.gba", 0xFF22C, 0x64

	.global gUnknown_80FF290
gUnknown_80FF290: @ 80FF290
	.incbin "baserom.gba", 0xFF290, 0x80

	.global gUnknown_80FF310
gUnknown_80FF310: @ 80FF310
	.incbin "baserom.gba", 0xFF310, 0x84

	.global gUnknown_80FF394
gUnknown_80FF394: @ 80FF394
	.incbin "baserom.gba", 0xFF394, 0x54

	.global gUnknown_80FF3E8
gUnknown_80FF3E8: @ 80FF3E8
	.incbin "baserom.gba", 0xFF3E8, 0x58

	.global gUnknown_80FF440
gUnknown_80FF440: @ 80FF440
	.incbin "baserom.gba", 0xFF440, 0x60

	.global gUnknown_80FF4A0
gUnknown_80FF4A0: @ 80FF4A0
	.incbin "baserom.gba", 0xFF4A0, 0x78

	.global gUnknown_80FF518
gUnknown_80FF518: @ 80FF518
	.incbin "baserom.gba", 0xFF518, 0x64

	.global gUnknown_80FF57C
gUnknown_80FF57C: @ 80FF57C
	.incbin "baserom.gba", 0xFF57C, 0x6C

	.global gUnknown_80FF5E8
gUnknown_80FF5E8: @ 80FF5E8
	.incbin "baserom.gba", 0xFF5E8, 0x8C

	.global gUnknown_80FF674
gUnknown_80FF674: @ 80FF674
	.incbin "baserom.gba", 0xFF674, 0x4

	.global gUnknown_80FF678
gUnknown_80FF678: @ 80FF678
	.incbin "baserom.gba", 0xFF678, 0x2C

	.global gUnknown_80FF6A4
gUnknown_80FF6A4: @ 80FF6A4
	.incbin "baserom.gba", 0xFF6A4, 0x54

	.global gUnknown_80FF6F8
gUnknown_80FF6F8: @ 80FF6F8
	.incbin "baserom.gba", 0xFF6F8, 0x38

	.global gUnknown_80FF730
gUnknown_80FF730: @ 80FF730
	.incbin "baserom.gba", 0xFF730, 0x3C

	.global gUnknown_80FF76C
gUnknown_80FF76C: @ 80FF76C
	.incbin "baserom.gba", 0xFF76C, 0x4

	.global gUnknown_80FF770
gUnknown_80FF770: @ 80FF770
        .byte 0x48, 0xEA, 0x0F, 0x08

	.global gUnknown_80FF774
gUnknown_80FF774: @ 80FF774
	.incbin "baserom.gba", 0xFF774, 0x78

	.global gUnknown_80FF7EC
gUnknown_80FF7EC: @ 80FF7EC
	.incbin "baserom.gba", 0xFF7EC, 0xA1C

	.global gUnknown_8100208
gUnknown_8100208: @ 8100208
	.4byte 0x81001C0

	.global gMagnitudeMessage
gMagnitudeMessage: @ 810020C
	.string "It{APOSTROPHE}s Magnitude $d0!\0"
	.align 2, 0

	.global gPtrMagnitudeMessage
gPtrMagnitudeMessage: @ 8100224
	.4byte gMagnitudeMessage

	.global gSleepingTargetOnlyMessage
gSleepingTargetOnlyMessage: @ 8100228
	.string "It only works on a sleeping target!\0"
	.align 2, 0

	.global gPtrSleepingTargetOnlyMessage
gPtrSleepingTargetOnlyMessage: @ 810024C
	.4byte gSleepingTargetOnlyMessage

	.global gFeralFoundItemMessage
gFeralFoundItemMessage: @ 8100250
	.string "{ARG_POKEMON_0} found an item somewhere.\0"
	.align 2, 0

	.global gPtrFeralFoundItemMessage
gPtrFeralFoundItemMessage: @ 8100270
	.4byte gFeralFoundItemMessage

	.global gSelfHealPreventedHungerMessage
gSelfHealPreventedHungerMessage: @ 8100274
	.string "Its self-healing prevented hunger!\0"
	.align 2, 0

	.global gPtrSelfHealPreventedHungerMessage
gPtrSelfHealPreventedHungerMessage: @ 8100298
	.4byte gSelfHealPreventedHungerMessage

	.global gUnknown_810029C
gUnknown_810029C: @ 810029C
	.string "Rescue challenges left: $d0\0"
	.align 2, 0

	.global gUnknown_81002B8
gUnknown_81002B8: @ 81002B8
	.4byte gUnknown_810029C

	.global gFinalChanceMessage
gFinalChanceMessage: @ 81002BC
	.string "This is your final chance!\0"
	.align 2, 0

	.global gPtrFinalChanceMessage
gPtrFinalChanceMessage: @ 81002D8
	.4byte gFinalChanceMessage

	.global gLinkedMovesComeApartMessage
gLinkedMovesComeApartMessage: @ 81002DC
	.string "The linked moves came apart!\0"
	.align 2, 0

	.global gPtrLinkedMovesComeApartMessage
gPtrLinkedMovesComeApartMessage: @ 81002FC
	.4byte gLinkedMovesComeApartMessage

	.global gLinkMoveOneUseWarningMessage
gLinkMoveOneUseWarningMessage: @ 8100300
	.string "{COLOR_2 YELLOW}The linked moves are almost out of PP!{END_COLOR_TEXT_2}\n"
	.string "{COLOR_2 YELLOW}Use them again and they will come apart!{END_COLOR_TEXT_2}\0"
	.align 2, 0

	.global gPtrLinkMoveOneUseWarningMessage
gPtrLinkMoveOneUseWarningMessage: @ 810035C
	.4byte gLinkMoveOneUseWarningMessage

	.global gLinkMoveTwoUsesWarningMessage
gLinkMoveTwoUsesWarningMessage: @ 8100360
	.string "{COLOR_2 YELLOW}The linked moves are almost out of PP!{END_COLOR_TEXT_2}\n"
	.string "{COLOR_2 YELLOW}Use them twice and they will come apart!{END_COLOR_TEXT_2}\0"
	.align 2, 0

	.global gPtrLinkMoveTwoUsesWarningMessage
gPtrLinkMoveTwoUsesWarningMessage: @ 81003BC
	.4byte gLinkMoveTwoUsesWarningMessage

	.global gIcePartCrumbledMessage
gIcePartCrumbledMessage: @ 81003C0
	.string "The Ice Part crumbled away...\0"
	.align 2, 0

	.global gPtrIcePartCrumbledMessage
gPtrIcePartCrumbledMessage: @ 81003E0
	.4byte gIcePartCrumbledMessage

	.global gRockPartCrumbledMessage
gRockPartCrumbledMessage: @ 81003E4
	.string "The Rock Part crumbled away...\0"
	.align 2, 0

	.global gPtrRockPartCrumbledMessage
gPtrRockPartCrumbledMessage: @ 8100404
	.4byte gRockPartCrumbledMessage

	.global gSteelPartCrumbledMessage
gSteelPartCrumbledMessage: @ 8100408
	.string "The Steel Part crumbled away...\0"
	.align 2, 0

	.global gPtrSteelPartCrumbledMessage
gPtrSteelPartCrumbledMessage: @ 8100428
	.4byte gSteelPartCrumbledMessage

	.global gWishStoneCrumbledMessage
gWishStoneCrumbledMessage: @ 810042C
	.string "The Wish Stone crumbled away...\0"
	.align 2, 0

	.global gPtrWishStoneCrumbledMessage
gPtrWishStoneCrumbledMessage: @ 810044C
	.4byte gWishStoneCrumbledMessage

	.global gMusicBoxPlayedCrumbledMessage
gMusicBoxPlayedCrumbledMessage: @ 8100450
	.string "The Music Box played a beautiful melody{COMMA}\n"
	.string "then crumbled away...\0"
	.align 2, 0

	.global gPtrMusicBoxPlayedCrumbledMessage
gPtrMusicBoxPlayedCrumbledMessage: @ 8100494
	.4byte gMusicBoxPlayedCrumbledMessage

	.global gMysteriousPowerPreventedUseMessage
gMysteriousPowerPreventedUseMessage: @ 8100498
	.string "But a mysterious power prevented its use!\0"
	.align 2, 0

	.global gPtrMysteriousPowerPreventedUseMessage
gPtrMysteriousPowerPreventedUseMessage: @ 81004C4
	.4byte gMysteriousPowerPreventedUseMessage

	.global gCouldntBeUsedMessage
gCouldntBeUsedMessage: @ 81004C8
	.string "But it couldn{APOSTROPHE}t be used!\0"
	.align 2, 0

	.global gPtrCouldntBeUsedMessage
gPtrCouldntBeUsedMessage: @ 81004E4
	.4byte gCouldntBeUsedMessage

	.global gUnknown_81004E8
gUnknown_81004E8: @ 81004E8
	.4byte 0x80FB568

	.global gUnknown_81004EC
gUnknown_81004EC: @ 81004EC
	.4byte 0x80FB568

	.global gUnknown_81004F0
gUnknown_81004F0: @ 81004F0
	.4byte 0x80FB568

	.global gUnknown_81004F4
gUnknown_81004F4: @ 81004F4
	.string "{ARG_POKEMON_1}{APOSTROPHE}s Soundproof suppressed\n"
	.string "the sound move!\0"
	.align 2, 0

	.global gUnknown_8100524
gUnknown_8100524: @ 8100524
	.4byte gUnknown_81004F4

	.global gUnknown_8100528
gUnknown_8100528: @ 8100528
	.string "The attack was barely endured!\0"
	.align 2, 0

	.global gUnknown_8100548
gUnknown_8100548: @ 8100548
	.4byte gUnknown_8100528

	.global gUnknown_810054C
gUnknown_810054C: @ 810054C
	.string "False Swipe prevented fainting!\0"
	.align 2, 0

	.global gUnknown_810056C
gUnknown_810056C: @ 810056C
	.4byte gUnknown_810054C

	.global gUnknown_8100570
gUnknown_8100570: @ 8100570
	.string "Perish Song{APOSTROPHE}s effect wore off!\0"
	.align 2, 0

	.global gUnknown_8100594
gUnknown_8100594: @ 8100594
	.4byte gUnknown_8100570

	.global gExposedWoreOffMessage
gExposedWoreOffMessage: @ 8100598
	.string "The Exposed status wore off!\0"
	.align 2, 0

	.global gPtrExposedWoreOffMessage
gPtrExposedWoreOffMessage: @ 81005B8
	.4byte gExposedWoreOffMessage

	.global gSealedMoveReleasedMessage
gSealedMoveReleasedMessage: @ 81005BC
	.string "The sealed move was released!\0"
	.align 2, 0

	.global gPtrSealedMoveReleasedMessage
gPtrSealedMoveReleasedMessage: @ 81005DC
	.4byte gSealedMoveReleasedMessage

	.global gCantLeechSeedSelfMessage
gCantLeechSeedSelfMessage: @ 81005E0
	.string "A leech seed can{APOSTROPHE}t be planted on the user!\0"
	.align 2, 0

	.global gPtrCantLeechSeedSelfMessage
gPtrCantLeechSeedSelfMessage: @ 8100610
	.4byte gCantLeechSeedSelfMessage

	.global gCantLeechSeedMonMessage
gCantLeechSeedMonMessage: @ 8100614
	.string "A leech seed couldn{APOSTROPHE}t be planted on\n"
	.string "{ARG_POKEMON_0}!\0"
	.align 2, 0

	.global gPtrCantLeechSeedMonMessage
gPtrCantLeechSeedMonMessage: @ 8100640
	.4byte gCantLeechSeedMonMessage

	.global gMoveInterruptedMessage
gMoveInterruptedMessage: @ 8100644
	.string "The move was interrupted!\0"
	.align 2, 0

	.global gPtrMoveInterruptedMessage
gPtrMoveInterruptedMessage: @ 8100660
	.4byte gMoveInterruptedMessage

	.global gClientFaintedMessage
gClientFaintedMessage: @ 8100664
	.string "Your client Pokémon has fainted!\n"
	.string "A rescue call can{APOSTROPHE}t be made!\0"
	.align 2, 0

	.global gPtrClientFaintedMessage
gPtrClientFaintedMessage: @ 81006A4
	.4byte gClientFaintedMessage

	.global gCantUseInDungeonMessage
gCantUseInDungeonMessage: @ 81006A8
	.string "It can{APOSTROPHE}t be used in a dungeon!\0"
	.align 2, 0

	.global gPtrCantUseInDungeonMessage
gPtrCantUseInDungeonMessage: @ 81006CC
	.4byte gCantUseInDungeonMessage

	.global gForecastPreventsTypeSwitchMessage
gForecastPreventsTypeSwitchMessage: @ 81006D0
	.string "Its Forecast prevents type switching!\0"
	.align 2, 0

	.global gPtrForecastPreventsTypeSwitchMessage
gPtrForecastPreventsTypeSwitchMessage: @ 81006F8
	.4byte gForecastPreventsTypeSwitchMessage

	.global gForecastPreventsConversion2Message
gForecastPreventsConversion2Message: @ 81006FC
	.string "Its Forecast prevents Conversion 2!\0"
	.align 2, 0

	.global gPtrForecastPreventsConversion2Message
gPtrForecastPreventsConversion2Message: @ 8100720
	.4byte gForecastPreventsConversion2Message

	.global gStenchWavedOffMessage
gStenchWavedOffMessage: @ 8100724
	.string "The stench was waved off!\0"
	.align 2, 0

	.global gPtrStenchWavedOffMessage
gPtrStenchWavedOffMessage: @ 8100740
	.4byte gStenchWavedOffMessage

	.global gProtectSavedItMessage
gProtectSavedItMessage: @ 8100744
	.string "Its Protect saved it!\0"
	.align 2, 0

	.global gPtrProtectSavedItMessage
gPtrProtectSavedItMessage: @ 810075C
	.4byte gProtectSavedItMessage

	.string "pksdir0\0"
	.align 2, 0

@ Start of Boss Fight Dialogues?

	.global gSkarmoryPreFightDialogue_1
gSkarmoryPreFightDialogue_1: @ 8100768
	.byte 0x00, 0x00, 0x0C, 0x02, 0xAA, 0x01, 0x00, 0x00
	.4byte gUnknown_8100774

	.global gUnknown_8100774
gUnknown_8100774: @ 8100774
	.string " Look{COMMA} {ARG_POKEMON_0}!\n"
	.string "{ARG_POKEMON_2}{APOSTROPHE}s over there!\0"
	.align 2, 0

	.global gSkarmoryPreFightDialogue_2
gSkarmoryPreFightDialogue_2: @ 8100798
	.byte 0x00, 0x00, 0x04, 0x02, 0xAA, 0x01, 0x07, 0x00
	.4byte gUnknown_81007E8
	.byte 0x00, 0x00, 0x04, 0x02, 0xAA, 0x01, 0x00, 0x00
	.4byte gUnknown_81007B0

	.global gUnknown_81007B0
gUnknown_81007B0: @ 81007B0
	.string " Hey! Are you all right?\n"
	.string "We{APOSTROPHE}ve come to rescue you!\0"
	.align 2, 0

	.global gUnknown_81007E8
gUnknown_81007E8: @ 81007E8
	.string " Hey! Are you all right?\n"
	.string "We{APOSTROPHE}re here to rescue you!\0"
	.align 2, 0

	.global gSkarmoryPreFightDialogue_3
gSkarmoryPreFightDialogue_3: @ 8100820
	.byte 0x00, 0x00, 0x01, 0x0D, 0x32, 0x00, 0x00, 0x00
	.4byte gUnknown_810082C

	.global gUnknown_810082C
gUnknown_810082C: @ 810082C
	.string " ...I...\n"
	.string "I{APOSTROPHE}m scared.\0"
	.align 2, 0

	.global gSkarmoryPreFightDialogue_4
gSkarmoryPreFightDialogue_4: @ 8100844
	.incbin "baserom.gba", 0x100844, 0x3C

	.global gSkarmoryPreFightDialogue_5
gSkarmoryPreFightDialogue_5: @ 8100880
	.incbin "baserom.gba", 0x100880, 0xA8

	.global gSkarmoryPreFightDialogue_6
gSkarmoryPreFightDialogue_6: @ 8100928
	.byte 0x00, 0x00, 0x00, 0x0D, 0xFC, 0x00, 0x00, 0x00
	.4byte gUnknown_8100934

	.global gUnknown_8100934
gUnknown_8100934: @ 8100934
	.string " How dare you!{WAIT_PRESS}\n"
	.string "It{APOSTROPHE}s their fault!{EXTRA_MSG}"
	.string " I haven{APOSTROPHE}t slept in days\n"
	.string "because the earthquakes frighten me so!\n"
	.string "Every night we had them!{EXTRA_MSG}"
	.string " Those earthquakes are\n"
	.string "caused by this brat{APOSTROPHE}s ilk running wild\n"
	.string "underground!\0"
	.align 2, 0

	.global gSkarmoryPreFightDialogue_7
gSkarmoryPreFightDialogue_7: @ 8100A04
	.incbin "baserom.gba", 0x100A04, 0x17C

	.global gSkarmoryPreFightDialogue_8
gSkarmoryPreFightDialogue_8: @ 8100B80
	.incbin "baserom.gba", 0x100B80, 0x40

	.global gSkarmoryPreFightDialogue_9
gSkarmoryPreFightDialogue_9: @ 8100BC0
	.incbin "baserom.gba", 0x100BC0, 0xD0

@ Skarmory Re-Fight?

	.global gSkarmoryReFightDialogue_1
gSkarmoryReFightDialogue_1: @ 8100C90
        .byte 0x00, 0x00, 0x00, 0x0D
        .byte 0xFC, 0x00, 0x00, 0x00
        .4byte _08100C9C

        .global _08100C9C
        _08100C9C:
        .string " You again?!\n"
        .asciz "Persistent pests!\0"
        .align 2,0

	.global gSkarmoryReFightDialogue_2
gSkarmoryReFightDialogue_2: @ 8100CBC
	.incbin "baserom.gba", 0x100CBC, 0x20

	.global gSkarmoryReFightDialogue_3
gSkarmoryReFightDialogue_3: @ 8100CDC
	.incbin "baserom.gba", 0x100CDC, 0x60

	.global gUnknown_8100D3C
gUnknown_8100D3C: @ 8100D3C
	.incbin "baserom.gba", 0x100D3C, 0x74

	.global gTeamMeaniesPreFightDialogue_1
gTeamMeaniesPreFightDialogue_1: @ 8100DB0
	.incbin "baserom.gba", 0x100DB0, 0xB4

	.global gTeamMeaniesPreFightDialogue_2
gTeamMeaniesPreFightDialogue_2: @ 8100E64
	.incbin "baserom.gba", 0x100E64, 0x24

	.global gTeamMeaniesPreFightDialogue_3
gTeamMeaniesPreFightDialogue_3: @ 8100E88
	.incbin "baserom.gba", 0x100E88, 0x8C

	.global gTeamMeaniesPreFightDialogue_4
gTeamMeaniesPreFightDialogue_4: @ 8100F14
	.incbin "baserom.gba", 0x100F14, 0xF0

	.global gTeamMeaniesPreFightDialogue_5
gTeamMeaniesPreFightDialogue_5: @ 8101004
	.incbin "baserom.gba", 0x101004, 0x4C

	.global gTeamMeaniesPreFightDialogue_6
gTeamMeaniesPreFightDialogue_6: @ 8101050
	.incbin "baserom.gba", 0x101050, 0x80

	.global gTeamMeaniesPreFightDialogue_7
gTeamMeaniesPreFightDialogue_7: @ 81010D0
	.incbin "baserom.gba", 0x1010D0, 0x94

	.global gTeamMeaniesReFightDialogue_1
gTeamMeaniesReFightDialogue_1: @ 8101164
	.incbin "baserom.gba", 0x101164, 0xDC

	.global gTeamMeaniesReFightDialogue_2
gTeamMeaniesReFightDialogue_2: @ 8101240
	.incbin "baserom.gba", 0x101240, 0xD0

	.global gTeamMeaniesReFightDialogue_3
gTeamMeaniesReFightDialogue_3: @ 8101310
	.incbin "baserom.gba", 0x101310, 0x6C

	.global gTeamMeaniesReFightDialogue_4
gTeamMeaniesReFightDialogue_4: @ 810137C
	.incbin "baserom.gba", 0x10137C, 0x8C

	.global gTeamMeaniesReFightDialogue_5
gTeamMeaniesReFightDialogue_5: @ 8101408
	.incbin "baserom.gba", 0x101408, 0x38

	.global gUnknown_8101440
gUnknown_8101440: @ 8101440
	.incbin "baserom.gba", 0x101440, 0x70

	.global gUnknown_81014B0
gUnknown_81014B0: @ 81014B0
	.incbin "baserom.gba", 0x1014B0, 0x54

	.global gUnknown_8101504
gUnknown_8101504: @ 8101504
	.incbin "baserom.gba", 0x101504, 0x9C

	.global gUnknown_81015A0
gUnknown_81015A0: @ 81015A0
	.incbin "baserom.gba", 0x1015A0, 0x34

	.global gUnknown_81015D4
gUnknown_81015D4: @ 81015D4
	.incbin "baserom.gba", 0x1015D4, 0x14

	.global gUnknown_81015E8
gUnknown_81015E8: @ 81015E8
	.incbin "baserom.gba", 0x1015E8, 0x3C

	.global gUnknown_8101624
gUnknown_8101624: @ 8101624
	.incbin "baserom.gba", 0x101624, 0x38

	.global gUnknown_810165C
gUnknown_810165C: @ 810165C
	.incbin "baserom.gba", 0x10165C, 0xF4

	.global gUnknown_8101750
gUnknown_8101750: @ 8101750
	.incbin "baserom.gba", 0x101750, 0x3C

	.global gUnknown_810178C
gUnknown_810178C: @ 810178C
	.incbin "baserom.gba", 0x10178C, 0x28

	.global gUnknown_81017B4
gUnknown_81017B4: @ 81017B4
	.incbin "baserom.gba", 0x1017B4, 0x30

	.global gZapdosReFightDialogue_1
gZapdosReFightDialogue_1: @ 81017E4
	.incbin "baserom.gba", 0x1017E4, 0xB4

	.global gZapdosReFightDialogue_2
gZapdosReFightDialogue_2: @ 8101898
	.incbin "baserom.gba", 0x101898, 0x54

	.global gZapdosReFightDialogue_3
gZapdosReFightDialogue_3: @ 81018EC
	.incbin "baserom.gba", 0x1018EC, 0x2C

	.global gZapdosReFightDialogue_4
gZapdosReFightDialogue_4: @ 8101918
	.incbin "baserom.gba", 0x101918, 0x24

	.global gZapdosPostStoryPreFightDialogue_1
gZapdosPostStoryPreFightDialogue_1: @ 810193C
	.incbin "baserom.gba", 0x10193C, 0x34

	.global gZapdosPostStoryPreFightDialogue_2
gZapdosPostStoryPreFightDialogue_2: @ 8101970
	.incbin "baserom.gba", 0x101970, 0x24

	.global gZapdosPostStoryPreFightDialogue_3
gZapdosPostStoryPreFightDialogue_3: @ 8101994
	.incbin "baserom.gba", 0x101994, 0x50

	.global gZapdosPostStoryPreFightDialogue_4
gZapdosPostStoryPreFightDialogue_4: @ 81019E4
	.incbin "baserom.gba", 0x1019E4, 0x20

	.global gZapdosPostStoryPreFightDialogue_5
gZapdosPostStoryPreFightDialogue_5: @ 8101A04
	.incbin "baserom.gba", 0x101A04, 0x34

	.global gZapdosPostStoryPreFightDialogue_6
gZapdosPostStoryPreFightDialogue_6: @ 8101A38
	.incbin "baserom.gba", 0x101A38, 0x64

	.global gMoltresPreFightDialogue_1
gMoltresPreFightDialogue_1: @ 8101A9C
	.incbin "baserom.gba", 0x101A9C, 0x38

	.global gMoltresPreFightDialogue_2
gMoltresPreFightDialogue_2: @ 8101AD4
	.incbin "baserom.gba", 0x101AD4, 0x15C

	.global gMoltresPreFightDialogue_3
gMoltresPreFightDialogue_3: @ 8101C30
	.incbin "baserom.gba", 0x101C30, 0x8C

	.global gMoltresPreFightDialogue_4
gMoltresPreFightDialogue_4: @ 8101CBC
	.incbin "baserom.gba", 0x101CBC, 0xD0

	.global gMoltresPreFightDialogue_5
gMoltresPreFightDialogue_5: @ 8101D8C
	.incbin "baserom.gba", 0x101D8C, 0x14

	.global gMoltresPreFightDialogue_6
gMoltresPreFightDialogue_6: @ 8101DA0
	.incbin "baserom.gba", 0x101DA0, 0x7C

	.global gMoltresPreFightDialogue_7
gMoltresPreFightDialogue_7: @ 8101E1C
	.incbin "baserom.gba", 0x101E1C, 0x90

	.global gMoltresPreFightDialogue_8
gMoltresPreFightDialogue_8: @ 8101EAC
	.incbin "baserom.gba", 0x101EAC, 0x1C4

	.global gMoltresPreFightDialogue_9
gMoltresPreFightDialogue_9: @ 8102070
	.incbin "baserom.gba", 0x102070, 0x34

	.global gMoltresPreFightDialogue_10
gMoltresPreFightDialogue_10: @ 81020A4
	.incbin "baserom.gba", 0x1020A4, 0x30

	.global gMoltresPreFightDialogue_11
gMoltresPreFightDialogue_11: @ 81020D4
	.incbin "baserom.gba", 0x1020D4, 0x34

	.global gMoltresPreFightDialogue_12
gMoltresPreFightDialogue_12: @ 8102108
	.incbin "baserom.gba", 0x102108, 0x50

	.global gMoltresReFightDialogue_1
gMoltresReFightDialogue_1: @ 8102158
	.incbin "baserom.gba", 0x102158, 0x38

	.global gMoltresReFightDialogue_2
gMoltresReFightDialogue_2: @ 8102190
	.incbin "baserom.gba", 0x102190, 0x70

	.global gMoltresReFightDialogue_3
gMoltresReFightDialogue_3: @ 8102200
	.incbin "baserom.gba", 0x102200, 0x54

	.global gMoltresReFightDialogue_4
gMoltresReFightDialogue_4: @ 8102254
	.incbin "baserom.gba", 0x102254, 0xA4

	.global gMoltresReFightDialogue_5
gMoltresReFightDialogue_5: @ 81022F8
	.incbin "baserom.gba", 0x1022F8, 0x34

	.global gMoltresPostStoryPreFightDialogue_1
gMoltresPostStoryPreFightDialogue_1: @ 810232C
	.incbin "baserom.gba", 0x10232C, 0x6C

	.global gMoltresPostStoryPreFightDialogue_2
gMoltresPostStoryPreFightDialogue_2: @ 8102398
	.incbin "baserom.gba", 0x102398, 0x2C

	.global gMoltresPostStoryPreFightDialogue_3
gMoltresPostStoryPreFightDialogue_3: @ 81023C4
	.incbin "baserom.gba", 0x1023C4, 0x3C

	.global gMoltresPostStoryPreFightDialogue_4
gMoltresPostStoryPreFightDialogue_4: @ 8102400
	.incbin "baserom.gba", 0x102400, 0x54

	.global gMoltresPostStoryPreFightDialogue_5
gMoltresPostStoryPreFightDialogue_5: @ 8102454
	.incbin "baserom.gba", 0x102454, 0x24

	.global gArticunoPreFightDialogue_1
gArticunoPreFightDialogue_1: @ 8102478
	.incbin "baserom.gba", 0x102478, 0x13C

	.global gArticunoPreFightDialogue_2
gArticunoPreFightDialogue_2: @ 81025B4
	.incbin "baserom.gba", 0x1025B4, 0x20

	.global gArticunoPreFightDialogue_3
gArticunoPreFightDialogue_3: @ 81025D4
	.incbin "baserom.gba", 0x1025D4, 0x3C

	.global gArticunoPreFightDialogue_4
gArticunoPreFightDialogue_4: @ 8102610
	.incbin "baserom.gba", 0x102610, 0xB4

	.global gArticunoPreFightDialogue_5
gArticunoPreFightDialogue_5: @ 81026C4
	.incbin "baserom.gba", 0x1026C4, 0x48

	.global gArticunoPreFightDialogue_6
gArticunoPreFightDialogue_6: @ 810270C
	.incbin "baserom.gba", 0x10270C, 0x20

	.global gArticunoPreFightDialogue_7
gArticunoPreFightDialogue_7: @ 810272C
	.incbin "baserom.gba", 0x10272C, 0x90

	.global gArticunoPreFightDialogue_8
gArticunoPreFightDialogue_8: @ 81027BC
	.incbin "baserom.gba", 0x1027BC, 0x54

	.global gArticunoPreFightDialogue_9
gArticunoPreFightDialogue_9: @ 8102810
	.incbin "baserom.gba", 0x102810, 0x30

	.global gArticunoPreFightDialogue_10
gArticunoPreFightDialogue_10: @ 8102840
        .4byte 0x0d000000
        .4byte 0x000001ab
        .4byte gUnknown_810284C

	.global gUnknown_810284C
        gUnknown_810284C:
        .string " I am {ARG_POKEMON_2}!{WAIT_PRESS}\n"
        .string "The warder of ice!\0"

	.global gArticunoPreFightDialogue_11
gArticunoPreFightDialogue_11: @ 810286C
@ replacing .incbin "baserom.gba", 0x0010286c, 0x4c
        .4byte 0x0d000000
        .4byte 0x00000090
        .4byte gUnknown_8102878

	.global gUnknown_8102878
        gUnknown_8102878:
        .string " Those that enter the forest\n"
        .string "I shall destroy with all my might!\0"

	.global gArticunoPreFightDialogue_12
gArticunoPreFightDialogue_12: @ 81028B8
        .4byte 0x0d000000
        .4byte 0x00000090
        .4byte gUnknown_81028C4

	.global gUnknown_81028C4
        gUnknown_81028C4:
        .string " Let us begin!\0\0"

	.global gArticunoReFightDialogue_1
gArticunoReFightDialogue_1: @ 81028D4
	.incbin "baserom.gba", 0x1028D4, 0x44

	.global gArticunoReFightDialogue_2
gArticunoReFightDialogue_2: @ 8102918
	.incbin "baserom.gba", 0x102918, 0x30

	.global gArticunoReFightDialogue_3
gArticunoReFightDialogue_3: @ 8102948
	.incbin "baserom.gba", 0x102948, 0x3C

	.global gArticunoPostStoryPreFightDialogue_1
gArticunoPostStoryPreFightDialogue_1: @ 8102984
	.incbin "baserom.gba", 0x102984, 0x30

	.global gArticunoPostStoryPreFightDialogue_2
gArticunoPostStoryPreFightDialogue_2: @ 81029B4
@ replacing .incbin "baserom.gba", 0x001029b4, 0x64
        .4byte 0x0d000000
        .4byte 0x00000090
        .4byte gUnknown_81029C0

	.global gUnknown_81029C0
        gUnknown_81029C0:
        .string " Your arrival in this frozen\n"
        .string "forest means only one thing...{EXTRA_MSG} You mean to challenge me!\0"

	.global gArticunoPostStoryPreFightDialogue_3
gArticunoPostStoryPreFightDialogue_3: @ 8102A18
	.incbin "baserom.gba", 0x102A18, 0xC

	.global gArticunoPostStoryPreFightDialogue_4
gArticunoPostStoryPreFightDialogue_4: @ 8102A24
	.incbin "baserom.gba", 0x102A24, 0x50

	.global gArticunoPostStoryPreFightDialogue_5
gArticunoPostStoryPreFightDialogue_5: @ 8102A74
	.incbin "baserom.gba", 0x102A74, 0x28

	.global gUnknown_8102A9C
gUnknown_8102A9C: @ 8102A9C
	.incbin "baserom.gba", 0x102A9C, 0x74

	.global gUnknown_8102B10
gUnknown_8102B10: @ 8102B10
	.incbin "baserom.gba", 0x102B10, 0xC

	.global MagmaCavernMidDialogue_1
MagmaCavernMidDialogue_1: @ 8102B1C
@ replacing .incbin "baserom.gba", 0x00102b1c, 0x38
        .4byte 0x02040000
        .4byte 0x000001aa
        .4byte gUnknown_8102B28

	.global gUnknown_8102B28
        gUnknown_8102B28:
        .string " Let{APOSTROPHE}s see...{WAIT_PRESS}\n"
        .string "...I wonder where we are?\0"

	.global MagmaCavernMidDialogue_2
MagmaCavernMidDialogue_2: @ 8102B54
	.incbin "baserom.gba", 0x102B54, 0x70

	.global MagmaCavernMidDialogue_3
MagmaCavernMidDialogue_3: @ 8102BC4
	.incbin "baserom.gba", 0x102BC4, 0x20

	.global MagmaCavernMidDialogue_4
MagmaCavernMidDialogue_4: @ 8102BE4
	.incbin "baserom.gba", 0x102BE4, 0x4C

	.global MagmaCavernMidDialogue_5
MagmaCavernMidDialogue_5: @ 8102C30
	.incbin "baserom.gba", 0x102C30, 0x24

	.global MagmaCavernMidDialogue_6
MagmaCavernMidDialogue_6: @ 8102C54
	.incbin "baserom.gba", 0x102C54, 0x44

	.global MagmaCavernMidDialogue_7
MagmaCavernMidDialogue_7: @ 8102C98
@ replacing .incbin "baserom.gba", 0x00102c98, 0x18
        .4byte 0x0e030000
        .4byte 0x00000006
        .4byte gUnknown_8102CA4

	.global gUnknown_8102CA4
        gUnknown_8102CA4:
        .string " Urrrrgh...\0"

	.global MagmaCavernMidDialogue_8
MagmaCavernMidDialogue_8: @ 8102CB0
	.incbin "baserom.gba", 0x102CB0, 0x48

	.global MagmaCavernMidDialogue_9
MagmaCavernMidDialogue_9: @ 8102CF8
	.incbin "baserom.gba", 0x102CF8, 0x3C

	.global MagmaCavernMidDialogue_10
MagmaCavernMidDialogue_10: @ 8102D34
	.incbin "baserom.gba", 0x102D34, 0x18

	.global MagmaCavernMidDialogue_11
MagmaCavernMidDialogue_11: @ 8102D4C
	.incbin "baserom.gba", 0x102D4C, 0x30

	.global MagmaCavernMidDialogue_12
MagmaCavernMidDialogue_12: @ 8102D7C
	.incbin "baserom.gba", 0x102D7C, 0x80

	.global MagmaCavernMidDialogue_13
MagmaCavernMidDialogue_13: @ 8102DFC
	.incbin "baserom.gba", 0x102DFC, 0x30

	.global MagmaCavernMidDialogue_14
MagmaCavernMidDialogue_14: @ 8102E2C
@ replacing .incbin "baserom.gba", 0x00102e2c, 0x28
        .4byte 0x020c0000
        .4byte 0x000001aa
        .4byte gUnknown_8102E38

	.global gUnknown_8102E38
        gUnknown_8102E38:
        .string " {ARG_POKEMON_0}!\n"
        .string "We{APOSTROPHE}ve got to hurry!\0"

	.global MagmaCavernMidDialogue_15
MagmaCavernMidDialogue_15: @ 8102E54
@ replacing .incbin "baserom.gba", 0x00102e54, 0x1c
        .4byte 0x0e030000
        .4byte 0x00000006
        .4byte gUnknown_8102E60

	.global gUnknown_8102E60
        gUnknown_8102E60:
        .string " ...Be careful!\0"

	.global GroudonPreFightDialogue_1
GroudonPreFightDialogue_1: @ 8102E70
	.incbin "baserom.gba", 0x102E70, 0x4C

	.global GroudonPreFightDialogue_2
GroudonPreFightDialogue_2: @ 8102EBC
	.incbin "baserom.gba", 0x102EBC, 0x24

	.global GroudonPreFightDialogue_3
GroudonPreFightDialogue_3: @ 8102EE0
@ replacing .incbin "baserom.gba", 0x00102ee0, 0x18
        .4byte 0x0f000000
        .4byte 0x00000041
        .4byte gUnknown_8102EEC

	.global gUnknown_8102EEC
        gUnknown_8102EEC:
        .string " Stay back!\0"

	.global GroudonPreFightDialogue_4
GroudonPreFightDialogue_4: @ 8102EF8
	.incbin "baserom.gba", 0x102EF8, 0x38

	.global GroudonPreFightDialogue_5
GroudonPreFightDialogue_5: @ 8102F30
	.incbin "baserom.gba", 0x102F30, 0x34

	.global GroudonPreFightDialogue_6
GroudonPreFightDialogue_6: @ 8102F64
	.incbin "baserom.gba", 0x102F64, 0x20

	.global GroudonPreFightDialogue_7
GroudonPreFightDialogue_7: @ 8102F84
	.incbin "baserom.gba", 0x102F84, 0x28

	.global GroudonPreFightDialogue_8
GroudonPreFightDialogue_8: @ 8102FAC
@ replacing .incbin "baserom.gba", 0x00102fac, 0x18
        .4byte 0x0f010000
        .4byte 0x00000041
        .4byte gUnknown_8102FB8

	.global gUnknown_8102FB8
        gUnknown_8102FB8:
        .string " Wraaaaaah!\0"

	.global GroudonPreFightDialogue_9
GroudonPreFightDialogue_9: @ 8102FC4
        @ replacing .incbin "baserom.gba", 0x00102fc4, 0x14
        .4byte 0x020c0000
        .4byte 0x000001aa
        .4byte gUnknown_8102FD0

	.global gUnknown_8102FD0
        gUnknown_8102FD0:
        .string " A-$m3!\0"

	.global GroudonPreFightDialogue_10
GroudonPreFightDialogue_10: @ 8102FD8
	.incbin "baserom.gba", 0x102FD8, 0x7C

	.global GroudonPreFightDialogue_11
GroudonPreFightDialogue_11: @ 8103054
        .incbin "baserom.gba", 0x00103054, 0x84

	.global GroudonPreFightDialogue_12
GroudonPreFightDialogue_12: @ 81030D8
	.incbin "baserom.gba", 0x1030D8, 0x38

	.global GroudonPreFightDialogue_13
GroudonPreFightDialogue_13: @ 8103110
	.incbin "baserom.gba", 0x103110, 0x30

	.global GroudonPreFightDialogue_14
GroudonPreFightDialogue_14: @ 8103140
	.incbin "baserom.gba", 0x103140, 0x48

	.global gGroudonReFightDialogue_1
gGroudonReFightDialogue_1: @ 8103188
	.incbin "baserom.gba", 0x103188, 0xA0

	.global gGroudonReFightDialogue_2
gGroudonReFightDialogue_2: @ 8103228
        .incbin "baserom.gba", 0x00103228, 0xe8

	.global gGroudonReFightDialogue_3
gGroudonReFightDialogue_3: @ 8103310
@ replacing .incbin "baserom.gba", 0x00103310, 0x30
        .4byte 0x00000005
        .4byte 0x00000000
        .4byte gUnknown_810331C

	.global gUnknown_810331C 
        gUnknown_810331C:
        .string "Grgaaaaaaaah!\n"
        .string "                     \0"

	.global gGroudonReFightDialogue_4
gGroudonReFightDialogue_4: @ 8103340
        .incbin "baserom.gba", 0x00103340, 0x60

	.global gGroudonPostStoryPreFightDialogue_1
gGroudonPostStoryPreFightDialogue_1: @ 81033A0
	.incbin "baserom.gba", 0x1033A0, 0xC

	.global gGroudonPostStoryPreFightDialogue_2
gGroudonPostStoryPreFightDialogue_2: @ 81033AC
	.incbin "baserom.gba", 0x1033AC, 0x90

	.global gGroudonPostStoryPreFightDialogue_3
gGroudonPostStoryPreFightDialogue_3: @ 810343C
@ replacing .incbin "baserom.gba", 0x0010343c, 0x40
        .4byte 0x0d000000
        .4byte 0x0000019b
        .4byte gUnknown_8103448

	.global gUnknown_8103448
        gUnknown_8103448:
        .string " Those that disturb my\n"
        .string "sleep...{WAIT_PRESS}\n"
        .string "Shall be crushed!\0"

	.global gGroudonPostStoryPreFightDialogue_4
gGroudonPostStoryPreFightDialogue_4: @ 810347C
	.incbin "baserom.gba", 0x10347C, 0xC

	.global gUnknown_8103488
gUnknown_8103488: @ 8103488
        @ replacing .incbin "baserom.gba", 0x00103488, 0x78
        .4byte 0x00000004
        .4byte 0x00000000
        .4byte gUnknown_8103494

	.global gUnknown_8103494
        gUnknown_8103494:
        .string "{CENTER_ALIGN}This appears to be the deepest level.{EXTRA_MSG}"
        .string "{CENTER_ALIGN}It{APOSTROPHE}s impossible to go any farther.{WAIT_PRESS}\n"
        .string "{CENTER_ALIGN}It{APOSTROPHE}s time to go back.\0"

	.global gRayquazaPreFightDialogue_1
gRayquazaPreFightDialogue_1: @ 8103500
	.incbin "baserom.gba", 0x103500, 0x2C

	.global gRayquazaPreFightDialogue_2
gRayquazaPreFightDialogue_2: @ 810352C
	.incbin "baserom.gba", 0x10352C, 0x4C

	.global gRayquazaPreFightDialogue_3
gRayquazaPreFightDialogue_3: @ 8103578
	.incbin "baserom.gba", 0x103578, 0x5C

	.global gRayquazaPreFightDialogue_4
gRayquazaPreFightDialogue_4: @ 81035D4
        @ replacing .incbin "baserom.gba", 0x001035d4, 0x44
        .4byte 0x0d800000
        .4byte 0x0000019c
        .4byte gUnknown_81035E0

	.global gUnknown_81035E0
        gUnknown_81035E0:
        .string " Indeed I am.{WAIT_PRESS}\n"
        .string "The sky is my domain.{EXTRA_MSG} Depart at once!\0"
        .align 2,0

	.global gRayquazaPreFightDialogue_5
gRayquazaPreFightDialogue_5: @ 8103618
	.incbin "baserom.gba", 0x103618, 0x64

	.global gRayquazaPreFightDialogue_6
gRayquazaPreFightDialogue_6: @ 810367C
@ replacing .incbin "baserom.gba", 0x0010367c, 0x14
        .4byte 0x0d800000
        .4byte 0x0000019c
        .4byte gUnknown_8103688

	.global gUnknown_8103688
        gUnknown_8103688:
        .string " Never!\0"
        .align 2,0

	.global gRayquazaPreFightDialogue_7
gRayquazaPreFightDialogue_7: @ 8103690
	.incbin "baserom.gba", 0x103690, 0x38

	.global gRayquazaPreFightDialogue_8
gRayquazaPreFightDialogue_8: @ 81036C8
	.incbin "baserom.gba", 0x1036C8, 0xD8

	.global gRayquazaPreFightDialogue_9
gRayquazaPreFightDialogue_9: @ 81037A0
@ replacing .incbin "baserom.gba", 0x001037a0, 0x34
        .4byte 0x0d000000
        .4byte 0x0000019c
        .4byte gUnknown_81037AC

	.global gUnknown_81037AC
        gUnknown_81037AC:
        .string " And the opposite shall also\n"
        .string "hold true!\0"
        .align 2,0

	.global gRayquazaPreFightDialogue_10
gRayquazaPreFightDialogue_10: @ 81037D4
	.incbin "baserom.gba", 0x1037D4, 0x4C

	.global gRayquazaPreFightDialogue_11
gRayquazaPreFightDialogue_11: @ 8103820
	.incbin "baserom.gba", 0x103820, 0x24

	.global gRayquazaReFightDialogue_1
gRayquazaReFightDialogue_1: @ 8103844
	.incbin "baserom.gba", 0x103844, 0x30

	.global gRayquazaReFightDialogue_2
gRayquazaReFightDialogue_2: @ 8103874
@ replacing .incbin "baserom.gba", 0x00103874, 0x34
        .4byte 0x0d000000
        .4byte 0x0000019c
        .4byte gUnknown_8103880

	.global gUnknown_8103880
        gUnknown_8103880:
        .string " This is no place for the\n"
        .string "likes of you!\0"
        .align 2,0

	.global gRayquazaReFightDialogue_3
gRayquazaReFightDialogue_3: @ 81038A8
	.incbin "baserom.gba", 0x1038A8, 0x50

	.global gRayquazaReFightDialogue_4
gRayquazaReFightDialogue_4: @ 81038F8
	.incbin "baserom.gba", 0x1038F8, 0xC

	.global gRayquazaPostStoryPreFightDialogue_1
gRayquazaPostStoryPreFightDialogue_1: @ 8103904
	.incbin "baserom.gba", 0x103904, 0x34

	.global gRayquazaPostStoryPreFightDialogue_2
gRayquazaPostStoryPreFightDialogue_2: @ 8103938
	.incbin "baserom.gba", 0x103938, 0x16C

	.global gRayquazaPostStoryPreFightDialogue_3
gRayquazaPostStoryPreFightDialogue_3: @ 8103AA4
	.incbin "baserom.gba", 0x103AA4, 0x40

	.global gRayquazaPostStoryPreFightDialogue_4
gRayquazaPostStoryPreFightDialogue_4: @ 8103AE4
	.incbin "baserom.gba", 0x103AE4, 0x4C

	.global gRayquazaPostStoryPreFightDialogue_5
gRayquazaPostStoryPreFightDialogue_5: @ 8103B30
	.incbin "baserom.gba", 0x103B30, 0x28

	.global gRayquazaPostStoryPreFightDialogue_6
gRayquazaPostStoryPreFightDialogue_6: @ 8103B58
	.incbin "baserom.gba", 0x103B58, 0x80

	.global gUnknown_8103BD8
gUnknown_8103BD8: @ 8103BD8
	.incbin "baserom.gba", 0x103BD8, 0x28

	.global gUnknown_8103C00
gUnknown_8103C00: @ 8103C00
	.incbin "baserom.gba", 0x103C00, 0x3C

	.global gUnknown_8103C3C
gUnknown_8103C3C: @ 8103C3C
	.incbin "baserom.gba", 0x103C3C, 0x38

	.global gUnknown_8103C74
gUnknown_8103C74: @ 8103C74
	.incbin "baserom.gba", 0x103C74, 0x50

	.global gUnknown_8103CC4
gUnknown_8103CC4: @ 8103CC4
	.incbin "baserom.gba", 0x103CC4, 0x48

	.global gUnknown_8103D0C
gUnknown_8103D0C: @ 8103D0C
	.incbin "baserom.gba", 0x103D0C, 0x44

	.global gUnknown_8103D50
gUnknown_8103D50: @ 8103D50
	.incbin "baserom.gba", 0x103D50, 0x3C

	.global gUnknown_8103D8C
gUnknown_8103D8C: @ 8103D8C
	.incbin "baserom.gba", 0x103D8C, 0xC

	.global gUnknown_8103D98
gUnknown_8103D98: @ 8103D98
	.incbin "baserom.gba", 0x103D98, 0x40

	.global gUnknown_8103DD8
gUnknown_8103DD8: @ 8103DD8
	.incbin "baserom.gba", 0x103DD8, 0x50

	.global gUnknown_8103E28
gUnknown_8103E28: @ 8103E28
	.incbin "baserom.gba", 0x103E28, 0xC

	.global gUnknown_8103E34
gUnknown_8103E34: @ 8103E34
	.byte 0x04, 0x00, 0x00, 0x00
	.byte 0x00, 0x00, 0x00, 0x00
	.4byte gUnknown_8103E40

	.global gUnknown_8103E40
gUnknown_8103E40: @ 8103E40
	.string "{CENTER_ALIGN}There appears to be no one here.{EXTRA_MSG}"
	.string "{CENTER_ALIGN}It{APOSTROPHE}s impossible to go farther.{WAIT_PRESS}\n"
	.string "{CENTER_ALIGN}It{APOSTROPHE}s time to go back.\0"
	.align 2, 0

	.global gMewtwoPreFightDialogue_1
gMewtwoPreFightDialogue_1: @ 8103EA4
	.incbin "baserom.gba", 0x103EA4, 0x68

	.global gMewtwoPreFightDialogue_2
gMewtwoPreFightDialogue_2: @ 8103F0C
	.incbin "baserom.gba", 0x103F0C, 0x40

	.global gMewtwoPreFightDialogue_3
gMewtwoPreFightDialogue_3: @ 8103F4C
	.incbin "baserom.gba", 0x103F4C, 0x80

	.global gMewtwoPreFightDialogue_4
gMewtwoPreFightDialogue_4: @ 8103FCC
	.incbin "baserom.gba", 0x103FCC, 0x3C

	.global gMewtwoPreFightDialogue_5
gMewtwoPreFightDialogue_5: @ 8104008
	.incbin "baserom.gba", 0x104008, 0x3C

	.global gMewtwoReFightDialogue_1
gMewtwoReFightDialogue_1: @ 8104044
	.incbin "baserom.gba", 0x104044, 0xC

	.global gMewtwoReFightDialogue_2
gMewtwoReFightDialogue_2: @ 8104050
	.incbin "baserom.gba", 0x104050, 0x7C

	.global gMewtwoReFightDialogue_3
gMewtwoReFightDialogue_3: @ 81040CC
	.incbin "baserom.gba", 0x1040CC, 0x48

	.global gMewtwoReFightDialogue_4
gMewtwoReFightDialogue_4: @ 8104114
	.incbin "baserom.gba", 0x104114, 0x30

	.global gMewtwoReFightDialogue_5
gMewtwoReFightDialogue_5: @ 8104144
	.incbin "baserom.gba", 0x104144, 0xC

	.global gEnteiPreFightDialogue_1
gEnteiPreFightDialogue_1: @ 8104150
	.incbin "baserom.gba", 0x104150, 0x5C

	.global gEnteiPreFightDialogue_2
gEnteiPreFightDialogue_2: @ 81041AC
	.incbin "baserom.gba", 0x1041AC, 0x4C

	.global gEnteiPreFightDialogue_3
gEnteiPreFightDialogue_3: @ 81041F8
	.incbin "baserom.gba", 0x1041F8, 0x48

	.global gEnteiReFightDialogue_1
gEnteiReFightDialogue_1: @ 8104240
	.incbin "baserom.gba", 0x104240, 0x6C

	.global gEnteiReFightDialogue_2
gEnteiReFightDialogue_2: @ 81042AC
	.incbin "baserom.gba", 0x1042AC, 0xC

	.global gEnteiReFightDialogue_3
gEnteiReFightDialogue_3: @ 81042B8
	.incbin "baserom.gba", 0x1042B8, 0x58

	.global gEnteiPostStoryPreFightDialogue_1
gEnteiPostStoryPreFightDialogue_1: @ 8104310
	.incbin "baserom.gba", 0x104310, 0x8C

	.global gEnteiPostStoryPreFightDialogue_2
gEnteiPostStoryPreFightDialogue_2: @ 810439C
	.incbin "baserom.gba", 0x10439C, 0x24

	.global gEnteiPostStoryPreFightDialogue_3
gEnteiPostStoryPreFightDialogue_3: @ 81043C0
	.incbin "baserom.gba", 0x1043C0, 0x1C

	.global gEnteiPostStoryPreFightDialogue_4
gEnteiPostStoryPreFightDialogue_4: @ 81043DC
	.incbin "baserom.gba", 0x1043DC, 0x74

	.global gRaikouPreFightDialogue_1
gRaikouPreFightDialogue_1: @ 8104450
	.incbin "baserom.gba", 0x104450, 0x64

	.global gRaikouPreFightDialogue_2
gRaikouPreFightDialogue_2: @ 81044B4
	.incbin "baserom.gba", 0x1044B4, 0x5C

	.global gRaikouPreFightDialogue_3
gRaikouPreFightDialogue_3: @ 8104510
	.incbin "baserom.gba", 0x104510, 0x2C

	.global gRaikouPreFightDialogue_4
gRaikouPreFightDialogue_4: @ 810453C
	.incbin "baserom.gba", 0x10453C, 0x34

	.global gRaikouPreFightDialogue_5
gRaikouPreFightDialogue_5: @ 8104570
	.incbin "baserom.gba", 0x104570, 0x40

	.global gRaikouPreFightDialogue_6
gRaikouPreFightDialogue_6: @ 81045B0
	.incbin "baserom.gba", 0x1045B0, 0x48

	.global gRaikouReFightDialogue_1
gRaikouReFightDialogue_1: @ 81045F8
	.incbin "baserom.gba", 0x1045F8, 0x7C

	.global gRaikouReFightDialogue_2
gRaikouReFightDialogue_2: @ 8104674
	.incbin "baserom.gba", 0x104674, 0x2C

	.global gRaikouReFightDialogue_3
gRaikouReFightDialogue_3: @ 81046A0
	.incbin "baserom.gba", 0x1046A0, 0x2C

	.global gRaikouPostStoryPreFightDialogue_1
gRaikouPostStoryPreFightDialogue_1: @ 81046CC
	.incbin "baserom.gba", 0x1046CC, 0x78

	.global gRaikouPostStoryPreFightDialogue_2
gRaikouPostStoryPreFightDialogue_2: @ 8104744
	.incbin "baserom.gba", 0x104744, 0x28

	.global gRaikouPostStoryPreFightDialogue_3
gRaikouPostStoryPreFightDialogue_3: @ 810476C
	.incbin "baserom.gba", 0x10476C, 0xC

	.global gRaikouPostStoryPreFightDialogue_4
gRaikouPostStoryPreFightDialogue_4: @ 8104778
	.incbin "baserom.gba", 0x104778, 0xC

	.global gSuicunePreFightDialogue_1
gSuicunePreFightDialogue_1: @ 8104784
	.incbin "baserom.gba", 0x104784, 0xC

	.global gSuicunePreFightDialogue_2
gSuicunePreFightDialogue_2: @ 8104790
	.incbin "baserom.gba", 0x104790, 0x20

	.global gSuicunePreFightDialogue_3
gSuicunePreFightDialogue_3: @ 81047B0
	.incbin "baserom.gba", 0x1047B0, 0x9C

	.global gSuicunePreFightDialogue_4
gSuicunePreFightDialogue_4: @ 810484C
	.incbin "baserom.gba", 0x10484C, 0x3C

	.global gSuicunePreFightDialogue_5
gSuicunePreFightDialogue_5: @ 8104888
	.incbin "baserom.gba", 0x104888, 0x40

	.global gSuicunePreFightDialogue_6
gSuicunePreFightDialogue_6: @ 81048C8
	.incbin "baserom.gba", 0x1048C8, 0x4C

	.global gSuicunePreFightDialogue_7
gSuicunePreFightDialogue_7: @ 8104914
	.incbin "baserom.gba", 0x104914, 0x1C

	.global gSuicuneReFightDialogue_1
gSuicuneReFightDialogue_1: @ 8104930
	.incbin "baserom.gba", 0x104930, 0x50

	.global gSuicuneReFightDialogue_2
gSuicuneReFightDialogue_2: @ 8104980
	.incbin "baserom.gba", 0x104980, 0x18

	.global gSuicuneReFightDialogue_3
gSuicuneReFightDialogue_3: @ 8104998
	.incbin "baserom.gba", 0x104998, 0x3C

	.global gSuicunePostStoryPreFightDialogue_1
gSuicunePostStoryPreFightDialogue_1: @ 81049D4
	.incbin "baserom.gba", 0x1049D4, 0xAC

	.global gSuicunePostStoryPreFightDialogue_2
gSuicunePostStoryPreFightDialogue_2: @ 8104A80
	.incbin "baserom.gba", 0x104A80, 0x1C

	.global gSuicunePostStoryPreFightDialogue_3
gSuicunePostStoryPreFightDialogue_3: @ 8104A9C
	.incbin "baserom.gba", 0x104A9C, 0x2C

	.global gSuicunePostStoryPreFightDialogue_4
gSuicunePostStoryPreFightDialogue_4: @ 8104AC8
	.incbin "baserom.gba", 0x104AC8, 0xC

	.global gHoOhPreFightDialogue_1
gHoOhPreFightDialogue_1: @ 8104AD4
	.incbin "baserom.gba", 0x104AD4, 0x118

	.global gHoOhPreFightDialogue_2
gHoOhPreFightDialogue_2: @ 8104BEC
	.incbin "baserom.gba", 0x104BEC, 0x24

	.global gHoOhPreFightDialogue_3
gHoOhPreFightDialogue_3: @ 8104C10
	.incbin "baserom.gba", 0x104C10, 0x44

	.global gHoOhPreFightDialogue_4
gHoOhPreFightDialogue_4: @ 8104C54
	.incbin "baserom.gba", 0x104C54, 0x60

	.global gHoOhPreFightDialogue_5
gHoOhPreFightDialogue_5: @ 8104CB4
	.incbin "baserom.gba", 0x104CB4, 0x2C

	.global gHoOhPreFightDialogue_6
gHoOhPreFightDialogue_6: @ 8104CE0
	.incbin "baserom.gba", 0x104CE0, 0xC

	.global HoOhReFightDialogue_1
HoOhReFightDialogue_1: @ 8104CEC
	.incbin "baserom.gba", 0x104CEC, 0x74

	.global HoOhReFightDialogue_2
HoOhReFightDialogue_2: @ 8104D60
	.incbin "baserom.gba", 0x104D60, 0x7C

	.global HoOhReFightDialogue_3
HoOhReFightDialogue_3: @ 8104DDC
	.incbin "baserom.gba", 0x104DDC, 0x30

	.global HoOhReFightDialogue_4
HoOhReFightDialogue_4: @ 8104E0C
	.incbin "baserom.gba", 0x104E0C, 0x48

	.global HoOhReFightDialogue_5
HoOhReFightDialogue_5: @ 8104E54
	.incbin "baserom.gba", 0x104E54, 0xC

	.global gLatiosPreFightDialogue_1
gLatiosPreFightDialogue_1: @ 8104E60
	.incbin "baserom.gba", 0x104E60, 0x9C

	.global gLatiosPreFightDialogue_2
gLatiosPreFightDialogue_2: @ 8104EFC
	.incbin "baserom.gba", 0x104EFC, 0x34

	.global gLatiosPreFightDialogue_3
gLatiosPreFightDialogue_3: @ 8104F30
	.incbin "baserom.gba", 0x104F30, 0x34

	.global gLatiosReFightDialogue_1
gLatiosReFightDialogue_1: @ 8104F64
	.incbin "baserom.gba", 0x104F64, 0x64

	.global gUnknown_8104FC8
gUnknown_8104FC8: @ 8104FC8
	.incbin "baserom.gba", 0x104FC8, 0xC

	.global gRegirockPreFightDialogue_1
gRegirockPreFightDialogue_1: @ 8104FD4
	.incbin "baserom.gba", 0x104FD4, 0x54

	.global gRegicePreFightDialogue_1
gRegicePreFightDialogue_1: @ 8105028
	.incbin "baserom.gba", 0x105028, 0xC

	.global gRegisteelPreFightDialogue_1
gRegisteelPreFightDialogue_1: @ 8105034
	.incbin "baserom.gba", 0x105034, 0xC

	.global gRegirockPostFightDialogue_1
gRegirockPostFightDialogue_1: @ 8105040
	.incbin "baserom.gba", 0x105040, 0x74

	.global gRegirockPostFightDialogue_2
gRegirockPostFightDialogue_2: @ 81050B4
	.incbin "baserom.gba", 0x1050B4, 0x58

	.global gRegicePostFightDialogue_1
gRegicePostFightDialogue_1: @ 810510C
	.incbin "baserom.gba", 0x10510C, 0x70

	.global gRegicePostFightDialogue_2
gRegicePostFightDialogue_2: @ 810517C
	.incbin "baserom.gba", 0x10517C, 0x54

	.global gRegisteelPostFightDialogue_1
gRegisteelPostFightDialogue_1: @ 81051D0
	.incbin "baserom.gba", 0x1051D0, 0x74

	.global gRegisteelPostFightDialogue_2
gRegisteelPostFightDialogue_2: @ 8105244
	.incbin "baserom.gba", 0x105244, 0xD8

	.global gUnknown_810531C
gUnknown_810531C: @ 810531C
	.incbin "baserom.gba", 0x10531C, 0x44

	.global gUnknown_8105360
gUnknown_8105360: @ 8105360
	.incbin "baserom.gba", 0x105360, 0x48

	.global gUnknown_81053A8
gUnknown_81053A8: @ 81053A8
	.incbin "baserom.gba", 0x1053A8, 0x8C

	.global gUnknown_8105434
gUnknown_8105434: @ 8105434
	.incbin "baserom.gba", 0x105434, 0x4

	.global gJirachiPreFightDialogue_1
gJirachiPreFightDialogue_1: @ 8105438
	.incbin "baserom.gba", 0x105438, 0x68

	.global gJirachiPreFightDialogue_2
gJirachiPreFightDialogue_2: @ 81054A0
	.incbin "baserom.gba", 0x1054A0, 0x44

	.global gJirachiPreFightDialogue_3
gJirachiPreFightDialogue_3: @ 81054E4
	.incbin "baserom.gba", 0x1054E4, 0x28

	.global gJirachiPreFightDialogue_4
gJirachiPreFightDialogue_4: @ 810550C
	.incbin "baserom.gba", 0x10550C, 0x40

	.global gUnknown_810554C
gUnknown_810554C: @ 810554C
	.incbin "baserom.gba", 0x10554C, 0xC

	.global gUnknown_8105558
gUnknown_8105558: @ 8105558
	.incbin "baserom.gba", 0x105558, 0x9C

	.global gUnknown_81055F4
gUnknown_81055F4: @ 81055F4
	.incbin "baserom.gba", 0x1055F4, 0x74

	.global gUnknown_8105668
gUnknown_8105668: @ 8105668
	.incbin "baserom.gba", 0x105668, 0xC

	.global gUnknown_8105674
gUnknown_8105674: @ 8105674
	.incbin "baserom.gba", 0x105674, 0x44

	.global gUnknown_81056B8
gUnknown_81056B8: @ 81056B8
	.incbin "baserom.gba", 0x1056B8, 0x24

	.global gUnknown_81056DC
gUnknown_81056DC: @ 81056DC
	.incbin "baserom.gba", 0x1056DC, 0xBC

	.global gUnknown_8105798
gUnknown_8105798: @ 8105798
	.incbin "baserom.gba", 0x105798, 0x4

	.global gUnknown_810579C
gUnknown_810579C: @ 810579C
	.incbin "baserom.gba", 0x10579C, 0x80

	.global gUnknown_810581C
gUnknown_810581C: @ 810581C
	.incbin "baserom.gba", 0x10581C, 0x8C

	.global gUnknown_81058A8
gUnknown_81058A8: @ 81058A8
	.incbin "baserom.gba", 0x1058A8, 0x1C

	.global gUnknown_81058C4
gUnknown_81058C4: @ 81058C4
	.incbin "baserom.gba", 0x1058C4, 0x1C

	.global gUnknown_81058E0
gUnknown_81058E0: @ 81058E0
	.incbin "baserom.gba", 0x1058E0, 0x5C

	.global gUnknown_810593C
gUnknown_810593C: @ 810593C
	.incbin "baserom.gba", 0x10593C, 0x38

	.global gUnknown_8105974
gUnknown_8105974: @ 8105974
	.incbin "baserom.gba", 0x105974, 0x94

	.global gUnknown_8105A08
gUnknown_8105A08: @ 8105A08
	.incbin "baserom.gba", 0x105A08, 0xCC

	.global gUnknown_8105AD4
gUnknown_8105AD4: @ 8105AD4
	.incbin "baserom.gba", 0x105AD4, 0x4C

	.global gUnknown_8105B20
gUnknown_8105B20: @ 8105B20
	.incbin "baserom.gba", 0x105B20, 0x48

	.global gUnknown_8105B68
gUnknown_8105B68: @ 8105B68
	.incbin "baserom.gba", 0x105B68, 0x40

	.global gUnknown_8105BA8
gUnknown_8105BA8: @ 8105BA8
	.incbin "baserom.gba", 0x105BA8, 0x4C

	.global gUnknown_8105BF4
gUnknown_8105BF4: @ 8105BF4
	.incbin "baserom.gba", 0x105BF4, 0x138

	.global gUnknown_8105D2C
gUnknown_8105D2C: @ 8105D2C
	.incbin "baserom.gba", 0x105D2C, 0x54

	.global gUnknown_8105D80
gUnknown_8105D80: @ 8105D80
	.incbin "baserom.gba", 0x105D80, 0x1C

	.global gUnknown_8105D9C
gUnknown_8105D9C: @ 8105D9C
	.incbin "baserom.gba", 0x105D9C, 0x78

	.global gJirachiReFightDialogue_1
gJirachiReFightDialogue_1: @ 8105E14
	.incbin "baserom.gba", 0x105E14, 0x74

@ Lugia Fight Dialogue

	.global gLugiaPreFightDialogue_1
gLugiaPreFightDialogue_1: @ 8105E88
	.incbin "baserom.gba", 0x105E88, 0x70

	.global gLugiaPreFightDialogue_2
gLugiaPreFightDialogue_2: @ 8105EF8
	.incbin "baserom.gba", 0x105EF8, 0x40

	.global gLugiaPreFightDialogue_3
gLugiaPreFightDialogue_3: @ 8105F38
	.incbin "baserom.gba", 0x105F38, 0x3C

	.global gLugiaPreFightDialogue_4
gLugiaPreFightDialogue_4: @ 8105F74
	.incbin "baserom.gba", 0x105F74, 0x2C

	.global gLugiaPreFightDialogue_5
gLugiaPreFightDialogue_5: @ 8105FA0
	.incbin "baserom.gba", 0x105FA0, 0x38

	.global gLugiaPreFightDialogue_6
gLugiaPreFightDialogue_6: @ 8105FD8
	.incbin "baserom.gba", 0x105FD8, 0x4C

	.global gLugiaPreFightDialogue_7
gLugiaPreFightDialogue_7: @ 8106024
	.incbin "baserom.gba", 0x106024, 0x44

	.global gLugiaPreFightDialogue_8
gLugiaPreFightDialogue_8: @ 8106068
	.incbin "baserom.gba", 0x106068, 0xC

@ Kyogre Fight Dialogue

	.global gKyogrePreFightDialogue_1
gKyogrePreFightDialogue_1: @ 8106074
	.incbin "baserom.gba", 0x106074, 0x48

	.global gKyogrePreFightDialogue_2
gKyogrePreFightDialogue_2: @ 81060BC
	.incbin "baserom.gba", 0x1060BC, 0x48

	.global gKyogrePreFightDialogue_3
gKyogrePreFightDialogue_3: @ 8106104
	.incbin "baserom.gba", 0x106104, 0x3C

	.global gKyogrePreFightDialogue_4
gKyogrePreFightDialogue_4: @ 8106140
	.incbin "baserom.gba", 0x106140, 0xD4

	.global gKyogrePreFightDialogue_5
gKyogrePreFightDialogue_5: @ 8106214
	.incbin "baserom.gba", 0x106214, 0x30

	.global gKyogrePreFightDialogue_6
gKyogrePreFightDialogue_6: @ 8106244
	.incbin "baserom.gba", 0x106244, 0x38

	.global gKyogrePreFightDialogue_7
gKyogrePreFightDialogue_7: @ 810627C
	.incbin "baserom.gba", 0x10627C, 0x2C

	.global gKyogrePreFightDialogue_8
gKyogrePreFightDialogue_8: @ 81062A8
	.incbin "baserom.gba", 0x1062A8, 0xC

	.global gDeoxysPreFightDialogue_1
gDeoxysPreFightDialogue_1: @ 81062B4
	.incbin "baserom.gba", 0x1062B4, 0x34

	.global gDeoxysPreFightDialogue_2
gDeoxysPreFightDialogue_2: @ 81062E8
	.incbin "baserom.gba", 0x1062E8, 0x80

	.global gDeoxysPreFightDialogue_3
gDeoxysPreFightDialogue_3: @ 8106368
	.incbin "baserom.gba", 0x106368, 0x28

	.global gDeoxysPreFightDialogue_4
gDeoxysPreFightDialogue_4: @ 8106390
	.incbin "baserom.gba", 0x106390, 0x34

	.global gDeoxysPreFightDialogue_5
gDeoxysPreFightDialogue_5: @ 81063C4
	.byte 0x04, 0x00, 0x00, 0x00
	.byte 0x00, 0x00, 0x00, 0x00
	.4byte gUnknown_8103E40

@ Dialogue for Purity Forest

	.global gCelebiJoinDialogue_1
gCelebiJoinDialogue_1: @ 81063D0
	.byte 0x04, 0x00, 0x00, 0x00
	.byte 0x00, 0x00, 0x00, 0x00
	.4byte gPurityForestSomeoneThereText

	.global gPurityForestSomeoneThereText
gPurityForestSomeoneThereText: @ 81063DC
	.string "{CENTER_ALIGN}Oh?{WAIT_PRESS}\n"
	.string "{CENTER_ALIGN}There{APOSTROPHE}s someone there.\0"
	.align 2, 0

	.global gCelebiJoinDialogue_2
gCelebiJoinDialogue_2: @ 8106400
	.byte 0x04, 0x00, 0x00, 0x00
	.byte 0x00, 0x00, 0x00, 0x00
	.4byte gPurityForestCelebiIntroText

	.global gPurityForestCelebiIntroText
gPurityForestCelebiIntroText: @ 810640C
	.string "{CENTER_ALIGN}It{APOSTROPHE}s...{WAIT_PRESS}\n"
	.string "{CENTER_ALIGN}The Time Travel Pokémon {ARG_POKEMON_2}!\0"
	.align 2, 0

	.global gCelebiJoinDialogue_3
gCelebiJoinDialogue_3: @ 810643C
	.byte 0x04, 0x00, 0x00, 0x00
	.byte 0x00, 0x00, 0x00, 0x00
	.4byte gPurityForestCelebiWantsToJoinText

	.global gPurityForestCelebiWantsToJoinText
gPurityForestCelebiWantsToJoinText: @ 8106448
	.string "{CENTER_ALIGN}{ARG_POKEMON_2} wants to join the team.\0"
	.align 2, 0

	.global gCelebiJoinDialogue_4
gCelebiJoinDialogue_4: @ 8106468
	.byte 0x04, 0x00, 0x00, 0x00
	.byte 0x00, 0x00, 0x00, 0x00
	.4byte gPurityForestCelebiJoinedText

	.global gPurityForestCelebiJoinedText
gPurityForestCelebiJoinedText: @ 8106474
	.string "{CENTER_ALIGN}{ARG_POKEMON_2} joined the team! \0"
	.align 2, 0

	.global gCelebiJoinDialogue_5
gCelebiJoinDialogue_5: @ 810648C
	.byte 0x04, 0x00, 0x00, 0x00
	.byte 0x00, 0x00, 0x00, 0x00
	.4byte gPurityForestCelebiVeryHappyText

	.global gPurityForestCelebiVeryHappyText
gPurityForestCelebiVeryHappyText: @ 8106498
	.string "{CENTER_ALIGN}{ARG_POKEMON_3} appears to\n"
	.string "{CENTER_ALIGN}be very happy!\0"
	.align 2, 0

	.global gCelebiJoinDialogue_6
gCelebiJoinDialogue_6: @ 81064BC
	.byte 0x04, 0x00, 0x00, 0x00
	.byte 0x00, 0x00, 0x00, 0x00
	.4byte gPurityForestCelebiDelightedToJoinText

	.global gPurityForestCelebiDelightedToJoinText
gPurityForestCelebiDelightedToJoinText: @ 81064C8
	.string "{CENTER_ALIGN}It{APOSTROPHE}s delighted to have\n"
	.string "{CENTER_ALIGN}joined the rescue team!\0"
	.align 2, 0

	.global gCelebiJoinDialogue_7
gCelebiJoinDialogue_7: @ 8106500
	.byte 0x04, 0x00, 0x00, 0x00
	.byte 0x00, 0x00, 0x00, 0x00
	.4byte gPurityForestTurnedDownOfferText

	.global gPurityForestTurnedDownOfferText
gPurityForestTurnedDownOfferText: @ 810650C
	.string "{CENTER_ALIGN}{ARG_POKEMON_0} turned down\n"
	.string "{CENTER_ALIGN}the offer to join.\0"
	.align 2, 0

	.global gCelebiJoinDialogue_8
gCelebiJoinDialogue_8: @ 8106534
	.byte 0x04, 0x00, 0x00, 0x00
	.byte 0x00, 0x00, 0x00, 0x00
	.4byte gPurityForestCelebiDisappointedText

	.global gPurityForestCelebiDisappointedText
gPurityForestCelebiDisappointedText: @ 8106540
	.string "{CENTER_ALIGN}Celebi is very disappointed.\0"
	.align 2, 0

	.global gCelebiJoinDialogue_9
gCelebiJoinDialogue_9: @ 8106560
	.byte 0x04, 0x00, 0x00, 0x00
	.byte 0x00, 0x00, 0x00, 0x00
	.4byte gPurityForestCelebiLeftDejectedlyText

	.global gPurityForestCelebiLeftDejectedlyText
gPurityForestCelebiLeftDejectedlyText: @ 810656C
	.string "{CENTER_ALIGN}{ARG_POKEMON_2} left\n"
	.string "{CENTER_ALIGN}dejectedly...\0"
	.align 2, 0

	.global gPurityForestAllowCelebiToJoinText
gPurityForestAllowCelebiToJoinText: @ 8106588
	.string "{CENTER_ALIGN}Allow {ARG_POKEMON_2}\n"
	.string "{CENTER_ALIGN}to join the team?\0"
	.align 2, 0

	.global gPtrPurityForestAllowCelebiToJoinText
gPtrPurityForestAllowCelebiToJoinText: @ 81065A8
	.4byte gPurityForestAllowCelebiToJoinText

	.global gPurityForestAllowCelebiToJoinPrompt
gPurityForestAllowCelebiToJoinPrompt: @ 81065AC
	.4byte gPurityForestAllowCelebiToJoinYesText
	.4byte 0x00000001
	.4byte gPurityForestAllowCelebiToJoinNoText
	.4byte 0x00000002
	.4byte 0x00000000
	.4byte 0xFFFFFFFF

	.global gPurityForestAllowCelebiToJoinNoText
gPurityForestAllowCelebiToJoinNoText: @ 81065C4
	.string "No.\0"
	.align 2, 0

	.global gPurityForestAllowCelebiToJoinYesText
gPurityForestAllowCelebiToJoinYesText: @ 81065C8
	.string "Yes.\0"
	.align 2, 0

	.global gPurityForestRefuseCelebiConfirmText
gPurityForestRefuseCelebiConfirmText: @ 81065D0
	.string "{CENTER_ALIGN}Are you sure?{WAIT_PRESS}\n"
	.string "{CENTER_ALIGN}You{APOSTROPHE}re sure you won{APOSTROPHE}t accept it?\0"
	.align 2, 0

	.global gPtrPurityForestRefuseCelebiConfirmText
gPtrPurityForestRefuseCelebiConfirmText: @ 810660C
	.4byte gPurityForestRefuseCelebiConfirmText

	.global gPurityForestRefuseCelebiConfirmPrompt
gPurityForestRefuseCelebiConfirmPrompt: @ 8106610
	.4byte gPurityForestRefuseCelebiReconsiderText
	.4byte 0x00000001
	.4byte gPurityForestRefuseCelebiRefuseText
	.4byte 0x00000002
	.4byte 0x00000000
	.4byte 0xFFFFFFFF

	.global gPurityForestRefuseCelebiRefuseText
gPurityForestRefuseCelebiRefuseText: @ 8106628
	.string "Refuse.\0"
	.align 2, 0

	.global gPurityForestRefuseCelebiReconsiderText
gPurityForestRefuseCelebiReconsiderText: @ 8106630
	.string "Reconsider.\0"
	.align 2, 0

	.global gCelebiJoinDialogue_10
gCelebiJoinDialogue_10: @ 810663C
	.incbin "baserom.gba", 0x10663C, 0x20

	.global gUnknown_810665C
gUnknown_810665C: @ 810665C
	.incbin "baserom.gba", 0x10665C, 0x30

	.global gUnknown_810668C
gUnknown_810668C: @ 810668C
	.incbin "baserom.gba", 0x10668C, 0x48

	.global gUnknown_81066D4
gUnknown_81066D4: @ 81066D4
	.incbin "baserom.gba", 0x1066D4, 0x1C

	.global gUnknown_81066F0
gUnknown_81066F0: @ 81066F0
	.incbin "baserom.gba", 0x1066F0, 0x2C

	.global gUnknown_810671C
gUnknown_810671C: @ 810671C
	.incbin "baserom.gba", 0x10671C, 0x4

	.global gUnknown_8106720
gUnknown_8106720: @ 8106720
	.incbin "baserom.gba", 0x106720, 0x58

	.global gMedichamRescueDialogue_1
gMedichamRescueDialogue_1: @ 8106778
	.incbin "baserom.gba", 0x106778, 0x44

	.global gMedichamRescueDialogue_2
gMedichamRescueDialogue_2: @ 81067BC
	.incbin "baserom.gba", 0x1067BC, 0x24

	.global gMedichamRescueDialogue_3
gMedichamRescueDialogue_3: @ 81067E0
	.incbin "baserom.gba", 0x1067E0, 0x54

	.global gMedichamRescueDialogue_4
gMedichamRescueDialogue_4: @ 8106834
	.incbin "baserom.gba", 0x106834, 0x58

	.global gSmeargleRescueDialogue_1
gSmeargleRescueDialogue_1: @ 810688C
	.incbin "baserom.gba", 0x10688C, 0x44

	.global gSmeargleRescueDialogue_2
gSmeargleRescueDialogue_2: @ 81068D0
	.incbin "baserom.gba", 0x1068D0, 0x48

	.global gSmeargleRescueDialogue_3
gSmeargleRescueDialogue_3: @ 8106918
	.incbin "baserom.gba", 0x106918, 0x1C

	.global gSmeargleRescueDialogue_4
gSmeargleRescueDialogue_4: @ 8106934
	.incbin "baserom.gba", 0x106934, 0x48

	.global gUnknown_810697C
gUnknown_810697C: @ 810697C
        .byte 0x04, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .4byte gUnknown_8103E40
        .string "pksdir0\0"
        .align 2,0

	.global gUnknown_8106990
gUnknown_8106990: @ 8106990
	.incbin "baserom.gba", 0x106990, 0x2C

	.global gUnknown_81069BC
gUnknown_81069BC: @ 81069BC
	.incbin "baserom.gba", 0x1069BC, 0x18

	.global gUnknown_81069D4
gUnknown_81069D4: @ 81069D4
	.incbin "baserom.gba", 0x1069D4, 0x20
