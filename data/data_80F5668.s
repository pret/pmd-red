        .section .rodata

	.global gDungeonMusic
gDungeonMusic: @ 80F5668
	.incbin "baserom.gba", 0xF5668, 0x98

	.global gUnknown_80F5700
gUnknown_80F5700: @ 80F5700
	.incbin "baserom.gba", 0xF5700, 0xCA

	.global gUnknown_80F57CA
gUnknown_80F57CA: @ 80F57CA
@ replacing .incbin "baserom.gba", 0x000f57ca, 0x2
        .byte 0x0a, 0x00

	.global gUnknown_80F57CC
gUnknown_80F57CC: @ 80F57CC
@ replacing .incbin "baserom.gba", 0x000f57cc, 0x2
        .byte 0x14, 0x00

	.global gUnknown_80F57CE
gUnknown_80F57CE: @ 80F57CE
@ replacing .incbin "baserom.gba", 0x000f57ce, 0x2
        .byte 0x14, 0x00

	.global gUnknown_80F57D0
gUnknown_80F57D0: @ 80F57D0
@ replacing .incbin "baserom.gba", 0x000f57d0, 0x2
        .byte 0x14, 0x00

	.global gUnknown_80F57D2
gUnknown_80F57D2: @ 80F57D2
@ replacing .incbin "baserom.gba", 0x000f57d2, 0x2
        .byte 0x0a, 0x00

	.global gUnknown_80F57D4
gUnknown_80F57D4: @ 80F57D4
	.incbin "baserom.gba", 0xF57D4, 0x120

	.global gUnknown_80F58F4
gUnknown_80F58F4: @ 80F58F4
	.incbin "baserom.gba", 0xF58F4, 0x84

	.global gUnknown_80F5978
gUnknown_80F5978: @ 80F5978
	.incbin "baserom.gba", 0xF5978, 0x4C
