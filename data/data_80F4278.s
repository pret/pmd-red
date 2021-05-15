        .section .rodata

	.global gUnknown_80F42C0
gUnknown_80F42C0: @ 80F42C0
	.string "Pokémon\0"
	.string "pksdir0\0"
	.align 2,0

	.global gUnknown_80F42D0
gUnknown_80F42D0: @ 80F42D0
        @ replacing .incbin "baserom.gba", 0x000f42d0, 0x20
        .byte 0x3f, 0x36, 0x37, 0x4e, 0x50, 0x52, 0x38, 0x39, 0x46, 0x30, 0x2b, 0x85, 0x53, 0x54, 0x58, 0x59, 0x34, 0x35, 0x4d, 0x43, 0x48, 0x4a, 0x2d, 0x4b, 0x31, 0x32, 0x21, 0xbe, 0x33, 0x51, 0xbd, 0x57

	.global gUnknown_80F42F0
gUnknown_80F42F0: @ 80F42F0
        @ replacing .incbin "baserom.gba", 0x000f42f0, 0x100
        .byte 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff
        .byte 0xff, 0x1a, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x0a, 0xff, 0x16, 0xff, 0xff, 0x09, 0x18, 0x19, 0x1c, 0x10, 0x11, 0x01, 0x02, 0x06, 0x07, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00
        .byte 0xff, 0xff, 0xff, 0x13, 0xff, 0xff, 0x08, 0xff, 0x14, 0xff, 0x15, 0x17, 0xff, 0x12, 0x03, 0xff, 0x04, 0x1d, 0x05, 0x0c, 0x0d, 0xff, 0xff, 0x1f, 0x0e, 0x0f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff
        .byte 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff
        .byte 0xff, 0xff, 0xff, 0xff, 0xff, 0x0b, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff
        .byte 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x1e, 0x1b, 0xff
        .byte 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff
        .byte 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff

	.global gUnknown_80F43F0
gUnknown_80F43F0: @ 80F43F0
@ replacing .incbin "baserom.gba", 0x000f43f0, 0x36
.byte 0x0d, 0x07, 0x19, 0x0f, 0x04, 0x1d, 0x2a, 0x31, 0x08, 0x13, 0x2d, 0x18, 0x0e, 0x1a, 0x1b, 0x29, 0x01, 0x20, 0x21, 0x22, 0x11, 0x33, 0x26, 0x00, 0x35, 0x0a, 0x2b, 0x1f, 0x12, 0x23, 0x2c, 0x17
.byte 0x27, 0x10, 0x1c, 0x30, 0x0b, 0x02, 0x24, 0x09, 0x32, 0x05, 0x28, 0x34, 0x2e, 0x03, 0x1e, 0x0c, 0x25, 0x14, 0x2f, 0x16, 0x06, 0x15

	.global gUnknown_80F4426
gUnknown_80F4426: @ 80F4426
        @ replacing .incbin "baserom.gba", 0x000f4426, 0x22
        .byte 0x0c, 0x06, 0x13, 0x08, 0x04, 0x0d, 0x0f, 0x09, 0x10, 0x02, 0x14, 0x12, 0x00, 0x15, 0x0b, 0x05, 0x17, 0x03, 0x11, 0x0a, 0x01, 0x0e, 0x16, 0x07, 0x00, 0x00
        .byte 0x70, 0x6b, 0x73, 0x64, 0x69, 0x72, 0x30, 0x00

	.global gUnknown_80F4448
gUnknown_80F4448: @ 80F4448
        @ replacing .incbin "baserom.gba", 0x000f4448, 0x20
        .byte 0x00, 0x00, 0x01, 0x00, 0x01, 0x00, 0x01, 0x00, 0x01, 0x00, 0x00, 0x00, 0x01, 0x00, 0xff, 0xff, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0xff, 0xff, 0x01, 0x00

	.global gUnknown_80F4468
gUnknown_80F4468: @ 80F4468
        @ replacing .incbin "baserom.gba", 0x000f4468, 0x130
        .byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0xff, 0xff, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0x01, 0x00, 0xff, 0xff, 0xff, 0xff, 0x01, 0x00
        .byte 0x01, 0x00, 0x01, 0x00, 0xfe, 0xff, 0xfe, 0xff, 0xff, 0xff, 0xfe, 0xff, 0x00, 0x00, 0xfe, 0xff, 0x01, 0x00, 0xfe, 0xff, 0x02, 0x00, 0xfe, 0xff, 0xfe, 0xff, 0xff, 0xff, 0x02, 0x00, 0xff, 0xff
        .byte 0xfe, 0xff, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0xfe, 0xff, 0x01, 0x00, 0x02, 0x00, 0x01, 0x00, 0xfe, 0xff, 0x02, 0x00, 0xff, 0xff, 0x02, 0x00, 0x00, 0x00, 0x02, 0x00, 0x01, 0x00, 0x02, 0x00
        .byte 0x02, 0x00, 0x02, 0x00, 0x63, 0x00, 0x63, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0x00, 0x00, 0x01, 0x00, 0x01, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff
        .byte 0xff, 0xff, 0x01, 0x00, 0xfe, 0xff, 0x00, 0x00, 0x00, 0x00, 0xfe, 0xff, 0x00, 0x00, 0x02, 0x00, 0x01, 0x00, 0xff, 0xff, 0x01, 0x00, 0x01, 0x00, 0x02, 0x00, 0x00, 0x00, 0xff, 0xff, 0xfe, 0xff
        .byte 0xff, 0xff, 0x02, 0x00, 0xfe, 0xff, 0xff, 0xff, 0xfe, 0xff, 0x01, 0x00, 0xfd, 0xff, 0x00, 0x00, 0x00, 0x00, 0xfd, 0xff, 0x00, 0x00, 0x03, 0x00, 0x01, 0x00, 0xfe, 0xff, 0x01, 0x00, 0x02, 0x00
        .byte 0x02, 0x00, 0xff, 0xff, 0x02, 0x00, 0x01, 0x00, 0x03, 0x00, 0x00, 0x00, 0xff, 0xff, 0xfd, 0xff, 0xff, 0xff, 0x03, 0x00, 0xfe, 0xff, 0xfe, 0xff, 0xfe, 0xff, 0x02, 0x00, 0xfd, 0xff, 0xff, 0xff
        .byte 0xfd, 0xff, 0x01, 0x00, 0x01, 0x00, 0xfd, 0xff, 0x01, 0x00, 0x03, 0x00, 0x02, 0x00, 0xfe, 0xff, 0x02, 0x00, 0x02, 0x00, 0x03, 0x00, 0xff, 0xff, 0x03, 0x00, 0x01, 0x00, 0xfe, 0xff, 0xfd, 0xff
        .byte 0xfe, 0xff, 0x03, 0x00, 0xfd, 0xff, 0xfe, 0xff, 0xfd, 0xff, 0x02, 0x00, 0x02, 0x00, 0xfd, 0xff, 0x02, 0x00, 0x03, 0x00, 0x03, 0x00, 0xfe, 0xff, 0x03, 0x00, 0x02, 0x00, 0xfd, 0xff, 0xfd, 0xff
        .byte 0xfd, 0xff, 0x03, 0x00, 0x03, 0x00, 0xfd, 0xff, 0x03, 0x00, 0x03, 0x00, 0x63, 0x00, 0x63, 0x00

	.global gUnknown_80F4598
gUnknown_80F4598: @ 80F4598
        @ replacing .incbin "baserom.gba", 0x000f4598, 0x72c
        .byte 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x01, 0x00, 0xfe, 0xff, 0x00, 0x00
        .byte 0x00, 0x00, 0xfe, 0xff, 0x00, 0x00, 0x02, 0x00, 0x01, 0x00, 0xff, 0xff, 0x01, 0x00, 0x01, 0x00, 0x02, 0x00, 0x00, 0x00, 0xff, 0xff, 0xfe, 0xff, 0xff, 0xff, 0x02, 0x00, 0xfe, 0xff, 0xff, 0xff
        .byte 0xfe, 0xff, 0x01, 0x00, 0xfd, 0xff, 0x00, 0x00, 0x00, 0x00, 0xfd, 0xff, 0x00, 0x00, 0x03, 0x00, 0x01, 0x00, 0xfe, 0xff, 0x01, 0x00, 0x02, 0x00, 0x02, 0x00, 0xff, 0xff, 0x02, 0x00, 0x01, 0x00
        .byte 0x03, 0x00, 0x00, 0x00, 0xff, 0xff, 0xfd, 0xff, 0xff, 0xff, 0x03, 0x00, 0xfe, 0xff, 0xfe, 0xff, 0xfe, 0xff, 0x02, 0x00, 0xfd, 0xff, 0xff, 0xff, 0xfd, 0xff, 0x01, 0x00, 0x01, 0x00, 0xfd, 0xff
        .byte 0x01, 0x00, 0x03, 0x00, 0x02, 0x00, 0xfe, 0xff, 0x02, 0x00, 0x02, 0x00, 0x03, 0x00, 0xff, 0xff, 0x03, 0x00, 0x01, 0x00, 0xfe, 0xff, 0xfd, 0xff, 0xfe, 0xff, 0x03, 0x00, 0xfd, 0xff, 0xfe, 0xff
        .byte 0xfd, 0xff, 0x02, 0x00, 0x02, 0x00, 0xfd, 0xff, 0x02, 0x00, 0x03, 0x00, 0x03, 0x00, 0xfe, 0xff, 0x03, 0x00, 0x02, 0x00, 0xfd, 0xff, 0xfd, 0xff, 0xfd, 0xff, 0x03, 0x00, 0x03, 0x00, 0xfd, 0xff
        .byte 0x03, 0x00, 0x03, 0x00, 0xfc, 0xff, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0xfc, 0xff, 0x00, 0x00, 0x04, 0x00, 0xfc, 0xff, 0x01, 0x00, 0x04, 0x00, 0x01, 0x00, 0xff, 0xff, 0xfc, 0xff
        .byte 0xff, 0xff, 0x04, 0x00, 0xfc, 0xff, 0xff, 0xff, 0x04, 0x00, 0xff, 0xff, 0x01, 0x00, 0xfc, 0xff, 0x01, 0x00, 0x04, 0x00, 0xfc, 0xff, 0x02, 0x00, 0x04, 0x00, 0x02, 0x00, 0xfe, 0xff, 0xfc, 0xff
        .byte 0xfe, 0xff, 0x04, 0x00, 0xfc, 0xff, 0xfe, 0xff, 0x04, 0x00, 0xfe, 0xff, 0x02, 0x00, 0xfc, 0xff, 0x02, 0x00, 0x04, 0x00, 0xfc, 0xff, 0x03, 0x00, 0x04, 0x00, 0x03, 0x00, 0xfd, 0xff, 0xfc, 0xff
        .byte 0xfd, 0xff, 0x04, 0x00, 0xfc, 0xff, 0xfd, 0xff, 0x04, 0x00, 0xfd, 0xff, 0x03, 0x00, 0xfc, 0xff, 0x03, 0x00, 0x04, 0x00, 0xfc, 0xff, 0x04, 0x00, 0x04, 0x00, 0x04, 0x00, 0xfc, 0xff, 0xfc, 0xff
        .byte 0xfc, 0xff, 0x04, 0x00, 0xfb, 0xff, 0x00, 0x00, 0x05, 0x00, 0x00, 0x00, 0x00, 0x00, 0xfb, 0xff, 0x00, 0x00, 0x05, 0x00, 0xfb, 0xff, 0xff, 0xff, 0x05, 0x00, 0xff, 0xff, 0xff, 0xff, 0xfb, 0xff
        .byte 0xff, 0xff, 0x05, 0x00, 0xfb, 0xff, 0x01, 0x00, 0x05, 0x00, 0x01, 0x00, 0x01, 0x00, 0xfb, 0xff, 0x01, 0x00, 0x05, 0x00, 0xfb, 0xff, 0xfe, 0xff, 0x05, 0x00, 0xfe, 0xff, 0xfe, 0xff, 0xfb, 0xff
        .byte 0xfe, 0xff, 0x05, 0x00, 0xfb, 0xff, 0x02, 0x00, 0x05, 0x00, 0x02, 0x00, 0x02, 0x00, 0xfb, 0xff, 0x02, 0x00, 0x05, 0x00, 0xfb, 0xff, 0xfd, 0xff, 0x05, 0x00, 0xfd, 0xff, 0xfd, 0xff, 0xfb, 0xff
        .byte 0xfd, 0xff, 0x05, 0x00, 0xfb, 0xff, 0x03, 0x00, 0x05, 0x00, 0x03, 0x00, 0x03, 0x00, 0xfb, 0xff, 0x03, 0x00, 0x05, 0x00, 0xfb, 0xff, 0xfc, 0xff, 0x05, 0x00, 0xfc, 0xff, 0xfc, 0xff, 0xfb, 0xff
        .byte 0xfc, 0xff, 0x05, 0x00, 0xfb, 0xff, 0x04, 0x00, 0x05, 0x00, 0x04, 0x00, 0x04, 0x00, 0xfb, 0xff, 0x04, 0x00, 0x05, 0x00, 0xfb, 0xff, 0xfb, 0xff, 0x05, 0x00, 0xfb, 0xff, 0xfb, 0xff, 0xfb, 0xff
        .byte 0xfb, 0xff, 0x05, 0x00, 0x63, 0x00, 0x63, 0x00, 0x00, 0x00, 0xff, 0xff, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0xff, 0xff, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0x01, 0x00, 0xff, 0xff
        .byte 0xff, 0xff, 0x01, 0x00, 0x01, 0x00, 0x01, 0x00, 0xfe, 0xff, 0xfe, 0xff, 0xff, 0xff, 0xfe, 0xff, 0x00, 0x00, 0xfe, 0xff, 0x01, 0x00, 0xfe, 0xff, 0x02, 0x00, 0xfe, 0xff, 0xfe, 0xff, 0xff, 0xff
        .byte 0x02, 0x00, 0xff, 0xff, 0xfe, 0xff, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0xfe, 0xff, 0x01, 0x00, 0x02, 0x00, 0x01, 0x00, 0xfe, 0xff, 0x02, 0x00, 0xff, 0xff, 0x02, 0x00, 0x00, 0x00, 0x02, 0x00
        .byte 0x01, 0x00, 0x02, 0x00, 0x02, 0x00, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x63, 0x00, 0x63, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00
        .byte 0xff, 0xff, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0x01, 0x00, 0xff, 0xff, 0xff, 0xff, 0x01, 0x00, 0x01, 0x00, 0x01, 0x00, 0x63, 0x00, 0x63, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x02, 0x00
        .byte 0x01, 0x00, 0x02, 0x00, 0xff, 0xff, 0x02, 0x00, 0x00, 0x00, 0x03, 0x00, 0x01, 0x00, 0x03, 0x00, 0xff, 0xff, 0x03, 0x00, 0x02, 0x00, 0x03, 0x00, 0xfe, 0xff, 0x03, 0x00, 0x00, 0x00, 0x04, 0x00
        .byte 0x01, 0x00, 0x04, 0x00, 0xff, 0xff, 0x04, 0x00, 0x02, 0x00, 0x04, 0x00, 0xfe, 0xff, 0x04, 0x00, 0x03, 0x00, 0x04, 0x00, 0xfd, 0xff, 0x04, 0x00, 0x00, 0x00, 0x05, 0x00, 0x01, 0x00, 0x05, 0x00
        .byte 0xff, 0xff, 0x05, 0x00, 0x02, 0x00, 0x05, 0x00, 0xfe, 0xff, 0x05, 0x00, 0x03, 0x00, 0x05, 0x00, 0xfd, 0xff, 0x05, 0x00, 0x04, 0x00, 0x05, 0x00, 0xfc, 0xff, 0x05, 0x00, 0x00, 0x00, 0x06, 0x00
        .byte 0x01, 0x00, 0x06, 0x00, 0xff, 0xff, 0x06, 0x00, 0x02, 0x00, 0x06, 0x00, 0xfe, 0xff, 0x06, 0x00, 0x03, 0x00, 0x06, 0x00, 0xfd, 0xff, 0x06, 0x00, 0x04, 0x00, 0x06, 0x00, 0xfc, 0xff, 0x06, 0x00
        .byte 0x05, 0x00, 0x06, 0x00, 0xfb, 0xff, 0x06, 0x00, 0x00, 0x00, 0x07, 0x00, 0x01, 0x00, 0x07, 0x00, 0xff, 0xff, 0x07, 0x00, 0x02, 0x00, 0x07, 0x00, 0xfe, 0xff, 0x07, 0x00, 0x03, 0x00, 0x07, 0x00
        .byte 0xfd, 0xff, 0x07, 0x00, 0x04, 0x00, 0x07, 0x00, 0xfc, 0xff, 0x07, 0x00, 0x05, 0x00, 0x07, 0x00, 0xfb, 0xff, 0x07, 0x00, 0x06, 0x00, 0x07, 0x00, 0xfa, 0xff, 0x07, 0x00, 0x00, 0x00, 0x08, 0x00
        .byte 0x01, 0x00, 0x08, 0x00, 0xff, 0xff, 0x08, 0x00, 0x02, 0x00, 0x08, 0x00, 0xfe, 0xff, 0x08, 0x00, 0x03, 0x00, 0x08, 0x00, 0xfd, 0xff, 0x08, 0x00, 0x04, 0x00, 0x08, 0x00, 0xfc, 0xff, 0x08, 0x00
        .byte 0x05, 0x00, 0x08, 0x00, 0xfb, 0xff, 0x08, 0x00, 0x06, 0x00, 0x08, 0x00, 0xfa, 0xff, 0x08, 0x00, 0x07, 0x00, 0x08, 0x00, 0xf9, 0xff, 0x08, 0x00, 0x00, 0x00, 0x09, 0x00, 0x01, 0x00, 0x09, 0x00
        .byte 0xff, 0xff, 0x09, 0x00, 0x02, 0x00, 0x09, 0x00, 0xfe, 0xff, 0x09, 0x00, 0x03, 0x00, 0x09, 0x00, 0xfd, 0xff, 0x09, 0x00, 0x04, 0x00, 0x09, 0x00, 0xfc, 0xff, 0x09, 0x00, 0x05, 0x00, 0x09, 0x00
        .byte 0xfb, 0xff, 0x09, 0x00, 0x06, 0x00, 0x09, 0x00, 0xfa, 0xff, 0x09, 0x00, 0x07, 0x00, 0x09, 0x00, 0xf9, 0xff, 0x09, 0x00, 0x08, 0x00, 0x09, 0x00, 0xf8, 0xff, 0x09, 0x00, 0x00, 0x00, 0x0a, 0x00
        .byte 0x01, 0x00, 0x0a, 0x00, 0xff, 0xff, 0x0a, 0x00, 0x02, 0x00, 0x0a, 0x00, 0xfe, 0xff, 0x0a, 0x00, 0x03, 0x00, 0x0a, 0x00, 0xfd, 0xff, 0x0a, 0x00, 0x04, 0x00, 0x0a, 0x00, 0xfc, 0xff, 0x0a, 0x00
        .byte 0x05, 0x00, 0x0a, 0x00, 0xfb, 0xff, 0x0a, 0x00, 0x06, 0x00, 0x0a, 0x00, 0xfa, 0xff, 0x0a, 0x00, 0x07, 0x00, 0x0a, 0x00, 0xf9, 0xff, 0x0a, 0x00, 0x08, 0x00, 0x0a, 0x00, 0xf8, 0xff, 0x0a, 0x00
        .byte 0x63, 0x00, 0x63, 0x00, 0x01, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x02, 0x00, 0xff, 0xff, 0x02, 0x00, 0x01, 0x00, 0x03, 0x00, 0x00, 0x00, 0x03, 0x00, 0xff, 0xff, 0x03, 0x00, 0x01, 0x00
        .byte 0x03, 0x00, 0xfe, 0xff, 0x03, 0x00, 0x02, 0x00, 0x04, 0x00, 0x00, 0x00, 0x04, 0x00, 0xff, 0xff, 0x04, 0x00, 0x01, 0x00, 0x04, 0x00, 0xfe, 0xff, 0x04, 0x00, 0x02, 0x00, 0x04, 0x00, 0xfd, 0xff
        .byte 0x04, 0x00, 0x03, 0x00, 0x05, 0x00, 0x00, 0x00, 0x05, 0x00, 0xff, 0xff, 0x05, 0x00, 0x01, 0x00, 0x05, 0x00, 0xfe, 0xff, 0x05, 0x00, 0x02, 0x00, 0x05, 0x00, 0xfd, 0xff, 0x05, 0x00, 0x03, 0x00
        .byte 0x05, 0x00, 0xfc, 0xff, 0x05, 0x00, 0x04, 0x00, 0x06, 0x00, 0x00, 0x00, 0x06, 0x00, 0xff, 0xff, 0x06, 0x00, 0x01, 0x00, 0x06, 0x00, 0xfe, 0xff, 0x06, 0x00, 0x02, 0x00, 0x06, 0x00, 0xfd, 0xff
        .byte 0x06, 0x00, 0x03, 0x00, 0x06, 0x00, 0xfc, 0xff, 0x06, 0x00, 0x04, 0x00, 0x06, 0x00, 0xfb, 0xff, 0x06, 0x00, 0x05, 0x00, 0x07, 0x00, 0x00, 0x00, 0x07, 0x00, 0xff, 0xff, 0x07, 0x00, 0x01, 0x00
        .byte 0x07, 0x00, 0xfe, 0xff, 0x07, 0x00, 0x02, 0x00, 0x07, 0x00, 0xfd, 0xff, 0x07, 0x00, 0x03, 0x00, 0x07, 0x00, 0xfc, 0xff, 0x07, 0x00, 0x04, 0x00, 0x07, 0x00, 0xfb, 0xff, 0x07, 0x00, 0x05, 0x00
        .byte 0x07, 0x00, 0xfa, 0xff, 0x07, 0x00, 0x06, 0x00, 0x08, 0x00, 0x00, 0x00, 0x08, 0x00, 0xff, 0xff, 0x08, 0x00, 0x01, 0x00, 0x08, 0x00, 0xfe, 0xff, 0x08, 0x00, 0x02, 0x00, 0x08, 0x00, 0xfd, 0xff
        .byte 0x08, 0x00, 0x03, 0x00, 0x08, 0x00, 0xfc, 0xff, 0x08, 0x00, 0x04, 0x00, 0x08, 0x00, 0xfb, 0xff, 0x08, 0x00, 0x05, 0x00, 0x08, 0x00, 0xfa, 0xff, 0x08, 0x00, 0x06, 0x00, 0x08, 0x00, 0xf9, 0xff
        .byte 0x08, 0x00, 0x07, 0x00, 0x09, 0x00, 0x00, 0x00, 0x09, 0x00, 0xff, 0xff, 0x09, 0x00, 0x01, 0x00, 0x09, 0x00, 0xfe, 0xff, 0x09, 0x00, 0x02, 0x00, 0x09, 0x00, 0xfd, 0xff, 0x09, 0x00, 0x03, 0x00
        .byte 0x09, 0x00, 0xfc, 0xff, 0x09, 0x00, 0x04, 0x00, 0x09, 0x00, 0xfb, 0xff, 0x09, 0x00, 0x05, 0x00, 0x09, 0x00, 0xfa, 0xff, 0x09, 0x00, 0x06, 0x00, 0x09, 0x00, 0xf9, 0xff, 0x09, 0x00, 0x07, 0x00
        .byte 0x09, 0x00, 0xf8, 0xff, 0x09, 0x00, 0x08, 0x00, 0x0a, 0x00, 0x00, 0x00, 0x0a, 0x00, 0xff, 0xff, 0x0a, 0x00, 0x01, 0x00, 0x0a, 0x00, 0xfe, 0xff, 0x0a, 0x00, 0x02, 0x00, 0x0a, 0x00, 0xfd, 0xff
        .byte 0x0a, 0x00, 0x03, 0x00, 0x0a, 0x00, 0xfc, 0xff, 0x0a, 0x00, 0x04, 0x00, 0x0a, 0x00, 0xfb, 0xff, 0x0a, 0x00, 0x05, 0x00, 0x0a, 0x00, 0xfa, 0xff, 0x0a, 0x00, 0x06, 0x00, 0x0a, 0x00, 0xf9, 0xff
        .byte 0x0a, 0x00, 0x07, 0x00, 0x0a, 0x00, 0xf8, 0xff, 0x0a, 0x00, 0x08, 0x00, 0x0a, 0x00, 0xf7, 0xff, 0x0a, 0x00, 0x09, 0x00, 0x63, 0x00, 0x63, 0x00, 0x01, 0x00, 0x01, 0x00, 0x02, 0x00, 0x02, 0x00
        .byte 0x02, 0x00, 0x01, 0x00, 0x01, 0x00, 0x02, 0x00, 0x03, 0x00, 0x03, 0x00, 0x03, 0x00, 0x02, 0x00, 0x02, 0x00, 0x03, 0x00, 0x03, 0x00, 0x01, 0x00, 0x01, 0x00, 0x03, 0x00, 0x04, 0x00, 0x04, 0x00
        .byte 0x04, 0x00, 0x03, 0x00, 0x03, 0x00, 0x04, 0x00, 0x04, 0x00, 0x02, 0x00, 0x02, 0x00, 0x04, 0x00, 0x04, 0x00, 0x01, 0x00, 0x01, 0x00, 0x04, 0x00, 0x05, 0x00, 0x05, 0x00, 0x05, 0x00, 0x04, 0x00
        .byte 0x04, 0x00, 0x05, 0x00, 0x05, 0x00, 0x03, 0x00, 0x03, 0x00, 0x05, 0x00, 0x05, 0x00, 0x02, 0x00, 0x02, 0x00, 0x05, 0x00, 0x05, 0x00, 0x01, 0x00, 0x01, 0x00, 0x05, 0x00, 0x06, 0x00, 0x06, 0x00
        .byte 0x06, 0x00, 0x05, 0x00, 0x05, 0x00, 0x06, 0x00, 0x06, 0x00, 0x04, 0x00, 0x04, 0x00, 0x06, 0x00, 0x06, 0x00, 0x03, 0x00, 0x03, 0x00, 0x06, 0x00, 0x06, 0x00, 0x02, 0x00, 0x02, 0x00, 0x06, 0x00
        .byte 0x06, 0x00, 0x01, 0x00, 0x01, 0x00, 0x06, 0x00, 0x07, 0x00, 0x07, 0x00, 0x07, 0x00, 0x06, 0x00, 0x06, 0x00, 0x07, 0x00, 0x07, 0x00, 0x05, 0x00, 0x05, 0x00, 0x07, 0x00, 0x07, 0x00, 0x04, 0x00
        .byte 0x04, 0x00, 0x07, 0x00, 0x07, 0x00, 0x03, 0x00, 0x03, 0x00, 0x07, 0x00, 0x07, 0x00, 0x02, 0x00, 0x02, 0x00, 0x07, 0x00, 0x07, 0x00, 0x01, 0x00, 0x01, 0x00, 0x07, 0x00, 0x08, 0x00, 0x08, 0x00
        .byte 0x08, 0x00, 0x07, 0x00, 0x07, 0x00, 0x08, 0x00, 0x08, 0x00, 0x06, 0x00, 0x06, 0x00, 0x08, 0x00, 0x08, 0x00, 0x05, 0x00, 0x05, 0x00, 0x08, 0x00, 0x08, 0x00, 0x04, 0x00, 0x04, 0x00, 0x08, 0x00
        .byte 0x08, 0x00, 0x03, 0x00, 0x03, 0x00, 0x08, 0x00, 0x08, 0x00, 0x02, 0x00, 0x02, 0x00, 0x08, 0x00, 0x08, 0x00, 0x01, 0x00, 0x01, 0x00, 0x08, 0x00, 0x09, 0x00, 0x09, 0x00, 0x09, 0x00, 0x08, 0x00
        .byte 0x08, 0x00, 0x09, 0x00, 0x09, 0x00, 0x07, 0x00, 0x07, 0x00, 0x09, 0x00, 0x09, 0x00, 0x06, 0x00, 0x06, 0x00, 0x09, 0x00, 0x09, 0x00, 0x05, 0x00, 0x05, 0x00, 0x09, 0x00, 0x09, 0x00, 0x04, 0x00
        .byte 0x04, 0x00, 0x09, 0x00, 0x09, 0x00, 0x03, 0x00, 0x03, 0x00, 0x09, 0x00, 0x09, 0x00, 0x02, 0x00, 0x02, 0x00, 0x09, 0x00, 0x09, 0x00, 0x01, 0x00, 0x01, 0x00, 0x09, 0x00, 0x0a, 0x00, 0x0a, 0x00
        .byte 0x0a, 0x00, 0x09, 0x00, 0x09, 0x00, 0x0a, 0x00, 0x0a, 0x00, 0x08, 0x00, 0x08, 0x00, 0x0a, 0x00, 0x0a, 0x00, 0x07, 0x00, 0x07, 0x00, 0x0a, 0x00, 0x0a, 0x00, 0x06, 0x00, 0x06, 0x00, 0x0a, 0x00
        .byte 0x0a, 0x00, 0x05, 0x00, 0x05, 0x00, 0x0a, 0x00, 0x0a, 0x00, 0x04, 0x00, 0x04, 0x00, 0x0a, 0x00, 0x0a, 0x00, 0x03, 0x00, 0x03, 0x00, 0x0a, 0x00, 0x0a, 0x00, 0x02, 0x00, 0x02, 0x00, 0x0a, 0x00
        .byte 0x0a, 0x00, 0x01, 0x00, 0x01, 0x00, 0x0a, 0x00, 0x63, 0x00, 0x63, 0x00

	.global gUnknown_80F4CC4
gUnknown_80F4CC4: @ 80F4CC4
        @ replacing .incbin "baserom.gba", 0x000f4cc4, 0x40
        .byte 0x10, 0x48, 0x0f, 0x08, 0x01, 0x00, 0x01, 0x00, 0x30, 0x4b, 0x0f, 0x08, 0x01, 0x00, 0x01, 0x00, 0x9c, 0x49, 0x0f, 0x08, 0x01, 0x00, 0x01, 0x00, 0x30, 0x4b, 0x0f, 0x08, 0x01, 0x00, 0xff, 0xff
        .byte 0x10, 0x48, 0x0f, 0x08, 0xff, 0xff, 0xff, 0xff, 0x30, 0x4b, 0x0f, 0x08, 0xff, 0xff, 0xff, 0xff, 0x9c, 0x49, 0x0f, 0x08, 0xff, 0xff, 0xff, 0xff, 0x30, 0x4b, 0x0f, 0x08, 0xff, 0xff, 0x01, 0x00

	.global gUnknown_80F4D04
gUnknown_80F4D04: @ 80F4D04
        @ replacing .incbin "baserom.gba", 0x000f4d04, 0x40
        .byte 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0x02, 0x00, 0x00, 0x00, 0xfe, 0xff, 0xff, 0xff, 0x03, 0x00, 0x00, 0x00, 0xfd, 0xff, 0xff, 0xff, 0x04, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0x01, 0x00, 0x00, 0x00, 0xfe, 0xff, 0xff, 0xff, 0x02, 0x00, 0x00, 0x00, 0xfd, 0xff, 0xff, 0xff, 0x03, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00

	.global gUnknown_80F4D44
gUnknown_80F4D44: @ 80F4D44
        @ replacing .incbin "baserom.gba", 0x000f4d44, 0x20
        .byte 0x00, 0x00, 0x00, 0x01, 0x00, 0x01, 0x00, 0x01, 0x00, 0x01, 0x00, 0x00, 0x00, 0x01, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0xff, 0x00, 0xff, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x01

	.global gUnknown_80F4D64
gUnknown_80F4D64: @ 80F4D64
        @ replacing .incbin "baserom.gba", 0x000f4d64, 0x28
        .byte 0x02, 0x06, 0x04, 0x00, 0x02, 0x00, 0x04, 0x06, 0x04, 0x00, 0x06, 0x02, 0x04, 0x02, 0x06, 0x00, 0x06, 0x02, 0x00, 0x04, 0x06, 0x04, 0x02, 0x00, 0x00, 0x04, 0x02, 0x06, 0x00, 0x06, 0x02, 0x04
        .string "pksdir0\0"
        .align 2,0

	.global gUnknown_80F4D8C
gUnknown_80F4D8C: @ 80F4D8C
        @ replacing .incbin "baserom.gba", 0x000f4d8c, 0x14
        .string "mapparam\0"
        .align 2,0
        .string "pksdir0\0"
        .align 2,0

	.global gUnknown_80F4DA0
gUnknown_80F4DA0: @ 80F4DA0
        @ replacing .incbin "baserom.gba", 0x000f4da0, 0x2
        .byte 0x07, 0x00

	.global gUnknown_80F4DA2
gUnknown_80F4DA2: @ 80F4DA2
        .byte 0x08, 0x00

	.global gUnknown_80F4DA4
gUnknown_80F4DA4: @ 80F4DA4
        .byte 0x0C, 0x00

	.global gUnknown_80F4DA6
gUnknown_80F4DA6: @ 80F4DA6
        .byte 0x0A, 0x00

	.global gUnknown_80F4DA8
gUnknown_80F4DA8: @ 80F4DA8
        .byte 0x04, 0x00

	.global gUnknown_80F4DAA
gUnknown_80F4DAA: @ 80F4DAA
        .byte 0x24, 0x00

	.global gUnknown_80F4DAC
gUnknown_80F4DAC: @ 80F4DAC
        .byte 0x05, 0x00

	.global gUnknown_80F4DAE
gUnknown_80F4DAE: @ 80F4DAE
        .byte 0x28, 0x00

	.global gUnknown_80F4DB0
gUnknown_80F4DB0: @ 80F4DB0
@ replacing .incbin "baserom.gba", 0x000f4db0, 0x2
    .byte 0x28, 0x00

	.global gUnknown_80F4DB2
gUnknown_80F4DB2: @ 80F4DB2
@ replacing .incbin "baserom.gba", 0x000f4db2, 0x2
    .byte 0x46, 0x00

	.global gUnknown_80F4DB4
gUnknown_80F4DB4: @ 80F4DB4
@ replacing .incbin "baserom.gba", 0x000f4db4, 0x2
    .byte 0x1e, 0x00

	.global gUnknown_80F4DB6
gUnknown_80F4DB6: @ 80F4DB6
@ replacing .incbin "baserom.gba", 0x000f4db6, 0x2
    .byte 0x0a, 0x00

	.global gUnknown_80F4DB8
gUnknown_80F4DB8: @ 80F4DB8
@ replacing .incbin "baserom.gba", 0x000f4db8, 0x2
    .byte 0x0a, 0x00

	.global gUnknown_80F4DBA
gUnknown_80F4DBA: @ 80F4DBA
@ replacing .incbin "baserom.gba", 0x000f4dba, 0x2
    .byte 0x0a, 0x00

	.global gUnknown_80F4DBC
gUnknown_80F4DBC: @ 80F4DBC
@ replacing .incbin "baserom.gba", 0x000f4dbc, 0x2
    .byte 0x0a, 0x00

	.global gUnknown_80F4DBE
gUnknown_80F4DBE: @ 80F4DBE
@ replacing .incbin "baserom.gba", 0x000f4dbe, 0x2
    .byte 0x12, 0x00

	.global gUnknown_80F4DC0
gUnknown_80F4DC0: @ 80F4DC0
@ replacing .incbin "baserom.gba", 0x000f4dc0, 0x2
    .byte 0x0a, 0x00

	.global gUnknown_80F4DC2
gUnknown_80F4DC2: @ 80F4DC2
@ replacing .incbin "baserom.gba", 0x000f4dc2, 0x2
    .byte 0x14, 0x00

	.global gUnknown_80F4DC4
gUnknown_80F4DC4: @ 80F4DC4
@ replacing .incbin "baserom.gba", 0x000f4dc4, 0x2
    .byte 0x28, 0x00

	.global gUnknown_80F4DC6
gUnknown_80F4DC6: @ 80F4DC6
@ replacing .incbin "baserom.gba", 0x000f4dc6, 0x2
    .byte 0x0a, 0x00

	.global gUnknown_80F4DC8
gUnknown_80F4DC8: @ 80F4DC8
@ replacing .incbin "baserom.gba", 0x000f4dc8, 0x2
    .byte 0x14, 0x00

	.global gUnknown_80F4DCA
gUnknown_80F4DCA: @ 80F4DCA
@ replacing .incbin "baserom.gba", 0x000f4dca, 0x2
    .byte 0x1e, 0x00

	.global gUnknown_80F4DCC
gUnknown_80F4DCC: @ 80F4DCC
@ replacing .incbin "baserom.gba", 0x000f4dcc, 0x2
    .byte 0x1e, 0x00

	.global gUnknown_80F4DCE
gUnknown_80F4DCE: @ 80F4DCE
@ replacing .incbin "baserom.gba", 0x000f4dce, 0x2
    .byte 0x0a, 0x00

	.global gUnknown_80F4DD0
gUnknown_80F4DD0: @ 80F4DD0
@ replacing .incbin "baserom.gba", 0x000f4dd0, 0x2
    .byte 0x14, 0x00

	.global gUnknown_80F4DD2
gUnknown_80F4DD2: @ 80F4DD2
@ replacing .incbin "baserom.gba", 0x000f4dd2, 0x2
    .byte 0x0a, 0x00

	.global gUnknown_80F4DD4
gUnknown_80F4DD4: @ 80F4DD4
@ replacing .incbin "baserom.gba", 0x000f4dd4, 0x2
    .byte 0x0a, 0x00

	.global gUnknown_80F4DD6
gUnknown_80F4DD6: @ 80F4DD6
@ replacing .incbin "baserom.gba", 0x000f4dd6, 0x2
    .byte 0x0a, 0x00

	.global gUnknown_80F4DD8
gUnknown_80F4DD8: @ 80F4DD8
@ replacing .incbin "baserom.gba", 0x000f4dd8, 0x2
    .byte 0x32, 0x00

	.global gUnknown_80F4DDA
gUnknown_80F4DDA: @ 80F4DDA
@ replacing .incbin "baserom.gba", 0x000f4dda, 0x2
    .byte 0x32, 0x00

	.global gUnknown_80F4DDC
gUnknown_80F4DDC: @ 80F4DDC
@ replacing .incbin "baserom.gba", 0x000f4ddc, 0x4
    .byte 0x32, 0x00
    .byte 0x32, 0x00

	.global gUnknown_80F4DE0
gUnknown_80F4DE0: @ 80F4DE0
@ replacing .incbin "baserom.gba", 0x000f4de0, 0x2
    .byte 0x32, 0x00

	.global gUnknown_80F4DE2
gUnknown_80F4DE2: @ 80F4DE2
@ replacing .incbin "baserom.gba", 0x000f4de2, 0x2
    .byte 0x0a, 0x00

	.global gUnknown_80F4DE4
gUnknown_80F4DE4: @ 80F4DE4
@ replacing .incbin "baserom.gba", 0x000f4de4, 0x2
    .byte 0x0f, 0x00

	.global gUnknown_80F4DE6
gUnknown_80F4DE6: @ 80F4DE6
@ replacing .incbin "baserom.gba", 0x000f4de6, 0x2
    .byte 0x14, 0x00

	.global gUnknown_80F4DE8
gUnknown_80F4DE8: @ 80F4DE8
@ replacing .incbin "baserom.gba", 0x000f4de8, 0x2
    .byte 0x0a, 0x00

	.global gUnknown_80F4DEA
gUnknown_80F4DEA: @ 80F4DEA
@ replacing .incbin "baserom.gba", 0x000f4dea, 0x2
    .byte 0x0a, 0x00

	.global gUnknown_80F4DEC
gUnknown_80F4DEC: @ 80F4DEC
@ replacing .incbin "baserom.gba", 0x000f4dec, 0x2
    .byte 0x0f, 0x00

	.global gUnknown_80F4DEE
gUnknown_80F4DEE: @ 80F4DEE
@ replacing .incbin "baserom.gba", 0x000f4dee, 0x2
    .byte 0x14, 0x00

	.global gUnknown_80F4DF0
gUnknown_80F4DF0: @ 80F4DF0
@ replacing .incbin "baserom.gba", 0x000f4df0, 0x2
    .byte 0x19, 0x00

	.global gUnknown_80F4DF2
gUnknown_80F4DF2: @ 80F4DF2
@ replacing .incbin "baserom.gba", 0x000f4df2, 0x2
    .byte 0x23, 0x00

	.global gUnknown_80F4DF4
gUnknown_80F4DF4: @ 80F4DF4
@ replacing .incbin "baserom.gba", 0x000f4df4, 0x2
    .byte 0x19, 0x00

	.global gUnknown_80F4DF6
gUnknown_80F4DF6: @ 80F4DF6
@ replacing .incbin "baserom.gba", 0x000f4df6, 0x2
    .byte 0x1e, 0x00

	.global gUnknown_80F4DF8
gUnknown_80F4DF8: @ 80F4DF8
@ replacing .incbin "baserom.gba", 0x000f4df8, 0x2
    .byte 0x0a, 0x00

	.global gUnknown_80F4DFA
gUnknown_80F4DFA: @ 80F4DFA
@ replacing .incbin "baserom.gba", 0x000f4dfa, 0x2
    .byte 0x1e, 0x00

	.global gUnknown_80F4DFC
gUnknown_80F4DFC: @ 80F4DFC
@ replacing .incbin "baserom.gba", 0x000f4dfc, 0x2
    .byte 0x14, 0x00

	.global gUnknown_80F4DFE
gUnknown_80F4DFE: @ 80F4DFE
@ replacing .incbin "baserom.gba", 0x000f4dfe, 0x2
    .byte 0x0a, 0x00

	.global gUnknown_80F4E00
gUnknown_80F4E00: @ 80F4E00
@ replacing .incbin "baserom.gba", 0x000f4e00, 0x2
    .byte 0x28, 0x00

	.global gUnknown_80F4E02
gUnknown_80F4E02: @ 80F4E02
@ replacing .incbin "baserom.gba", 0x000f4e02, 0x2
    .byte 0x3c, 0x00

	.global gUnknown_80F4E04
gUnknown_80F4E04: @ 80F4E04
@ replacing .incbin "baserom.gba", 0x000f4e04, 0x2
    .byte 0x3c, 0x00

	.global gUnknown_80F4E06
gUnknown_80F4E06: @ 80F4E06
@ replacing .incbin "baserom.gba", 0x000f4e06, 0x2
    .byte 0x1e, 0x00

	.global gUnknown_80F4E08
gUnknown_80F4E08: @ 80F4E08
@ replacing .incbin "baserom.gba", 0x000f4e08, 0x2
    .byte 0x0a, 0x00

	.global gUnknown_80F4E0A
gUnknown_80F4E0A: @ 80F4E0A
@ replacing .incbin "baserom.gba", 0x000f4e0a, 0x2
    .byte 0x1e, 0x00

	.global gUnknown_80F4E0C
gUnknown_80F4E0C: @ 80F4E0C
@ replacing .incbin "baserom.gba", 0x000f4e0c, 0x2
    .byte 0x32, 0x00

	.global gUnknown_80F4E0E
gUnknown_80F4E0E: @ 80F4E0E
@ replacing .incbin "baserom.gba", 0x000f4e0e, 0x2
    .byte 0x1e, 0x00

	.global gUnknown_80F4E10
gUnknown_80F4E10: @ 80F4E10
@ replacing .incbin "baserom.gba", 0x000f4e10, 0x2
    .byte 0x0c, 0x00

	.global gUnknown_80F4E12
gUnknown_80F4E12: @ 80F4E12
@ replacing .incbin "baserom.gba", 0x000f4e12, 0x2
    .byte 0x0c, 0x00

	.global gUnknown_80F4E14
gUnknown_80F4E14: @ 80F4E14
@ replacing .incbin "baserom.gba", 0x000f4e14, 0x2
    .byte 0x0c, 0x00

	.global gUnknown_80F4E16
gUnknown_80F4E16: @ 80F4E16
@ replacing .incbin "baserom.gba", 0x000f4e16, 0x2
    .byte 0x0c, 0x00

	.global gUnknown_80F4E18
gUnknown_80F4E18: @ 80F4E18
@ replacing .incbin "baserom.gba", 0x000f4e18, 0x2
    .byte 0x0c, 0x00

	.global gUnknown_80F4E1A
gUnknown_80F4E1A: @ 80F4E1A
@ replacing .incbin "baserom.gba", 0x000f4e1a, 0x2
    .byte 0x0c, 0x00

	.global gUnknown_80F4E1C
gUnknown_80F4E1C: @ 80F4E1C
@ replacing .incbin "baserom.gba", 0x000f4e1c, 0x2
    .byte 0x0c, 0x00

	.global gUnknown_80F4E1E
gUnknown_80F4E1E: @ 80F4E1E
@ replacing .incbin "baserom.gba", 0x000f4e1e, 0x2
    .byte 0x0c, 0x00

	.global gUnknown_80F4E20
gUnknown_80F4E20: @ 80F4E20
@ replacing .incbin "baserom.gba", 0x000f4e20, 0x2
    .byte 0x0c, 0x00

	.global gUnknown_80F4E22
gUnknown_80F4E22: @ 80F4E22
@ replacing .incbin "baserom.gba", 0x000f4e22, 0xa
    .byte 0x64, 0x00
    .byte 0x14, 0x00
    .byte 0x1e, 0x00
    .byte 0x28, 0x00
    .byte 0x32, 0x00

	.global gUnknown_80F4E2C
gUnknown_80F4E2C: @ 80F4E2C
@ replacing .incbin "baserom.gba", 0x000f4e2c, 0x4
    .byte 0x03, 0x00
    .byte 0x05, 0x00

	.global gUnknown_80F4E30
gUnknown_80F4E30: @ 80F4E30
@ replacing .incbin "baserom.gba", 0x000f4e30, 0x4
    .byte 0x7f, 0x00
    .byte 0x7f, 0x00

	.global gUnknown_80F4E34
gUnknown_80F4E34: @ 80F4E34
@ replacing .incbin "baserom.gba", 0x000f4e34, 0x4
    .byte 0x7f, 0x00
    .byte 0x7f, 0x00

	.global gUnknown_80F4E38
gUnknown_80F4E38: @ 80F4E38
@ replacing .incbin "baserom.gba", 0x000f4e38, 0x4
    .byte 0x7f, 0x00
    .byte 0x7f, 0x00

	.global gUnknown_80F4E3C
gUnknown_80F4E3C: @ 80F4E3C
@ replacing .incbin "baserom.gba", 0x000f4e3c, 0x4
    .byte 0x01, 0x00
    .byte 0x01, 0x00

	.global gUnknown_80F4E40
gUnknown_80F4E40: @ 80F4E40
@ replacing .incbin "baserom.gba", 0x000f4e40, 0x8
    .byte 0x08, 0x00
    .byte 0x0a, 0x00
    .byte 0x03, 0x00
    .byte 0x04, 0x00

	.global gUnknown_80F4E48
gUnknown_80F4E48: @ 80F4E48
@ replacing .incbin "baserom.gba", 0x000f4e48, 0x4
    .byte 0x06, 0x00
    .byte 0x08, 0x00

	.global gUnknown_80F4E4C
gUnknown_80F4E4C: @ 80F4E4C
@ replacing .incbin "baserom.gba", 0x000f4e4c, 0x4
    .byte 0x06, 0x00
    .byte 0x0c, 0x00

	.global gUnknown_80F4E50
gUnknown_80F4E50: @ 80F4E50
@ replacing .incbin "baserom.gba", 0x000f4e50, 0x4
    .byte 0x01, 0x00
    .byte 0x02, 0x00

	.global gUnknown_80F4E54
gUnknown_80F4E54: @ 80F4E54
@ replacing .incbin "baserom.gba", 0x000f4e54, 0x4
    .byte 0x02, 0x00
    .byte 0x05, 0x00

	.global gUnknown_80F4E58
gUnknown_80F4E58: @ 80F4E58
@ replacing .incbin "baserom.gba", 0x000f4e58, 0x4
    .byte 0x03, 0x00
    .byte 0x06, 0x00

	.global gUnknown_80F4E5C
gUnknown_80F4E5C: @ 80F4E5C
@ replacing .incbin "baserom.gba", 0x000f4e5c, 0x4
    .byte 0x02, 0x00
    .byte 0x05, 0x00

	.global gUnknown_80F4E60
gUnknown_80F4E60: @ 80F4E60
@ replacing .incbin "baserom.gba", 0x000f4e60, 0x10
    .byte 0x0f, 0x00
    .byte 0x1e, 0x00
    .byte 0x02, 0x00
    .byte 0x03, 0x00
    .byte 0x02, 0x00
    .byte 0x06, 0x00
    .byte 0x0a, 0x00
    .byte 0x0a, 0x00

	.global gUnknown_80F4E70
gUnknown_80F4E70: @ 80F4E70
@ replacing .incbin "baserom.gba", 0x000f4e70, 0x4
    .byte 0x01, 0x00
    .byte 0x01, 0x00

	.global gUnknown_80F4E74
gUnknown_80F4E74: @ 80F4E74
@ replacing .incbin "baserom.gba", 0x000f4e74, 0x4
    .byte 0x03, 0x00
    .byte 0x07, 0x00

	.global gUnknown_80F4E78
gUnknown_80F4E78: @ 80F4E78
@ replacing .incbin "baserom.gba", 0x000f4e78, 0x4
.byte 0x04, 0x00
.byte 0x08, 0x00

	.global gUnknown_80F4E7C
gUnknown_80F4E7C: @ 80F4E7C
@ replacing .incbin "baserom.gba", 0x000f4e7c, 0x4
.byte 0x0a, 0x00
.byte 0x0c, 0x00

	.global gUnknown_80F4E80
gUnknown_80F4E80: @ 80F4E80
@ replacing .incbin "baserom.gba", 0x000f4e80, 0x4
.byte 0x0a, 0x00
.byte 0x0c, 0x00

	.global gUnknown_80F4E84
gUnknown_80F4E84: @ 80F4E84
@ replacing .incbin "baserom.gba", 0x000f4e84, 0x4
.byte 0x0a, 0x00
.byte 0x0c, 0x00

	.global gUnknown_80F4E88
gUnknown_80F4E88: @ 80F4E88
@ replacing .incbin "baserom.gba", 0x000f4e88, 0x4
.byte 0x0f, 0x00
.byte 0x14, 0x00

	.global gUnknown_80F4E8C
gUnknown_80F4E8C: @ 80F4E8C
@ replacing .incbin "baserom.gba", 0x000f4e8c, 0x4
.byte 0x0a, 0x00
.byte 0x0e, 0x00

	.global gUnknown_80F4E90
gUnknown_80F4E90: @ 80F4E90
@ replacing .incbin "baserom.gba", 0x000f4e90, 0x4
.byte 0x0a, 0x00
.byte 0x0c, 0x00

	.global gUnknown_80F4E94
gUnknown_80F4E94: @ 80F4E94
@ replacing .incbin "baserom.gba", 0x000f4e94, 0x4
.byte 0x02, 0x00
.byte 0x04, 0x00

	.global gUnknown_80F4E98
gUnknown_80F4E98: @ 80F4E98
@ replacing .incbin "baserom.gba", 0x000f4e98, 0x4
.byte 0x06, 0x00
.byte 0x0c, 0x00

	.global gUnknown_80F4E9C
gUnknown_80F4E9C: @ 80F4E9C
@ replacing .incbin "baserom.gba", 0x000f4e9c, 0x4
.byte 0x03, 0x00
.byte 0x05, 0x00

	.global gUnknown_80F4EA0
gUnknown_80F4EA0: @ 80F4EA0
@ replacing .incbin "baserom.gba", 0x000f4ea0, 0x4
.byte 0x04, 0x00
.byte 0x0a, 0x00

	.global gUnknown_80F4EA4
gUnknown_80F4EA4: @ 80F4EA4
@ replacing .incbin "baserom.gba", 0x000f4ea4, 0x4
.byte 0x03, 0x00
.byte 0x05, 0x00

	.global gUnknown_80F4EA8
gUnknown_80F4EA8: @ 80F4EA8
@ replacing .incbin "baserom.gba", 0x000f4ea8, 0x4
.byte 0x03, 0x00
.byte 0x05, 0x00

	.global gUnknown_80F4EAC
gUnknown_80F4EAC: @ 80F4EAC
@ replacing .incbin "baserom.gba", 0x000f4eac, 0x4
.byte 0x0a, 0x00
.byte 0x0c, 0x00

	.global gUnknown_80F4EB0
gUnknown_80F4EB0: @ 80F4EB0
@ replacing .incbin "baserom.gba", 0x000f4eb0, 0x4
.byte 0x0a, 0x00
.byte 0x0c, 0x00

	.global gUnknown_80F4EB4
gUnknown_80F4EB4: @ 80F4EB4
@ replacing .incbin "baserom.gba", 0x000f4eb4, 0x4
.byte 0x0a, 0x00
.byte 0x0c, 0x00

	.global gUnknown_80F4EB8
gUnknown_80F4EB8: @ 80F4EB8
@ replacing .incbin "baserom.gba", 0x000f4eb8, 0x4
.byte 0x0a, 0x00
.byte 0x0c, 0x00

	.global gUnknown_80F4EBC
gUnknown_80F4EBC: @ 80F4EBC
@ replacing .incbin "baserom.gba", 0x000f4ebc, 0x4
.byte 0x14, 0x00
.byte 0x1e, 0x00

	.global gUnknown_80F4EC0
gUnknown_80F4EC0: @ 80F4EC0
@ replacing .incbin "baserom.gba", 0x000f4ec0, 0x4
.byte 0x7f, 0x00
.byte 0x7f, 0x00

	.global gUnknown_80F4EC4
gUnknown_80F4EC4: @ 80F4EC4
@ replacing .incbin "baserom.gba", 0x000f4ec4, 0x4
.byte 0x02, 0x00
.byte 0x04, 0x00

	.global gUnknown_80F4EC8
gUnknown_80F4EC8: @ 80F4EC8
@ replacing .incbin "baserom.gba", 0x000f4ec8, 0x4
.byte 0x02, 0x00
.byte 0x04, 0x00

	.global gUnknown_80F4ECC
gUnknown_80F4ECC: @ 80F4ECC
@ replacing .incbin "baserom.gba", 0x000f4ecc, 0x4
.byte 0x0a, 0x00
.byte 0x0c, 0x00

	.global gUnknown_80F4ED0
gUnknown_80F4ED0: @ 80F4ED0
@ replacing .incbin "baserom.gba", 0x000f4ed0, 0x4
.byte 0x14, 0x00
.byte 0x32, 0x00

	.global gUnknown_80F4ED4
gUnknown_80F4ED4: @ 80F4ED4
@ replacing .incbin "baserom.gba", 0x000f4ed4, 0x4
.byte 0x02, 0x00
.byte 0x06, 0x00

	.global gUnknown_80F4ED8
gUnknown_80F4ED8: @ 80F4ED8
@ replacing .incbin "baserom.gba", 0x000f4ed8, 0x4
.byte 0x0a, 0x00
.byte 0x0c, 0x00

	.global gUnknown_80F4EDC
gUnknown_80F4EDC: @ 80F4EDC
@ replacing .incbin "baserom.gba", 0x000f4edc, 0x4
.byte 0x01, 0x00
.byte 0x06, 0x00

	.global gUnknown_80F4EE0
gUnknown_80F4EE0: @ 80F4EE0
@ replacing .incbin "baserom.gba", 0x000f4ee0, 0x4
.byte 0x0a, 0x00
.byte 0x0c, 0x00

	.global gUnknown_80F4EE4
gUnknown_80F4EE4: @ 80F4EE4
@ replacing .incbin "baserom.gba", 0x000f4ee4, 0x4
.byte 0x0a, 0x00
.byte 0x14, 0x00

	.global gUnknown_80F4EE8
gUnknown_80F4EE8: @ 80F4EE8
@ replacing .incbin "baserom.gba", 0x000f4ee8, 0x4
.byte 0x0a, 0x00
.byte 0x0c, 0x00

	.global gUnknown_80F4EEC
gUnknown_80F4EEC: @ 80F4EEC
@ replacing .incbin "baserom.gba", 0x000f4eec, 0x4
.byte 0x03, 0x00
.byte 0x03, 0x00

	.global gUnknown_80F4EF0
gUnknown_80F4EF0: @ 80F4EF0
@ replacing .incbin "baserom.gba", 0x000f4ef0, 0x4
.byte 0x0a, 0x00
.byte 0x0a, 0x00

	.global gUnknown_80F4EF4
gUnknown_80F4EF4: @ 80F4EF4
@ replacing .incbin "baserom.gba", 0x000f4ef4, 0x4
.byte 0x0a, 0x00
.byte 0x0a, 0x00

	.global gUnknown_80F4EF8
gUnknown_80F4EF8: @ 80F4EF8
@ replacing .incbin "baserom.gba", 0x000f4ef8, 0x4
.byte 0x03, 0x00
.byte 0x05, 0x00

	.global gUnknown_80F4EFC
gUnknown_80F4EFC: @ 80F4EFC
@ replacing .incbin "baserom.gba", 0x000f4efc, 0x4
.byte 0x7f, 0x00
.byte 0x7f, 0x00

	.global gUnknown_80F4F00
gUnknown_80F4F00: @ 80F4F00
@ replacing .incbin "baserom.gba", 0x000f4f00, 0x4
.byte 0x04, 0x00
.byte 0x06, 0x00

	.global gUnknown_80F4F04
gUnknown_80F4F04: @ 80F4F04
@ replacing .incbin "baserom.gba", 0x000f4f04, 0x4
.byte 0x7f, 0x00
.byte 0x7f, 0x00

	.global gUnknown_80F4F08
gUnknown_80F4F08: @ 80F4F08
@ replacing .incbin "baserom.gba", 0x000f4f08, 0x4
.byte 0x0a, 0x00
.byte 0x0a, 0x00

	.global gUnknown_80F4F0C
gUnknown_80F4F0C: @ 80F4F0C
@ replacing .incbin "baserom.gba", 0x000f4f0c, 0x4
.byte 0x0a, 0x00
.byte 0x0a, 0x00

	.global gUnknown_80F4F10
gUnknown_80F4F10: @ 80F4F10
@ replacing .incbin "baserom.gba", 0x000f4f10, 0x8
.byte 0x7f, 0x00
.byte 0x7f, 0x00
.byte 0x0a, 0x00
.byte 0x0a, 0x00

	.global gUnknown_80F4F18
gUnknown_80F4F18: @ 80F4F18
@ replacing .incbin "baserom.gba", 0x000f4f18, 0x4
.byte 0x02, 0x00
.byte 0x05, 0x00

	.global gUnknown_80F4F1C
gUnknown_80F4F1C: @ 80F4F1C
@ replacing .incbin "baserom.gba", 0x000f4f1c, 0x4
.byte 0x0a, 0x00
.byte 0x0a, 0x00

	.global gUnknown_80F4F20
gUnknown_80F4F20: @ 80F4F20
@ replacing .incbin "baserom.gba", 0x000f4f20, 0x4
.byte 0x0a, 0x00
.byte 0x0a, 0x00

	.global gUnknown_80F4F24
gUnknown_80F4F24: @ 80F4F24
@ replacing .incbin "baserom.gba", 0x000f4f24, 0x4
.byte 0x0f, 0x00
.byte 0x14, 0x00

	.global gUnknown_80F4F28
gUnknown_80F4F28: @ 80F4F28
@ replacing .incbin "baserom.gba", 0x000f4f28, 0x4
.byte 0x02, 0x00
.byte 0x02, 0x00

	.global gUnknown_80F4F2C
gUnknown_80F4F2C: @ 80F4F2C
@ replacing .incbin "baserom.gba", 0x000f4f2c, 0x4
.byte 0x04, 0x00
.byte 0x08, 0x00

	.global gUnknown_80F4F30
gUnknown_80F4F30: @ 80F4F30
@ replacing .incbin "baserom.gba", 0x000f4f30, 0x2
.byte 0xfa, 0x00

	.global gUnknown_80F4F32
gUnknown_80F4F32: @ 80F4F32
@ replacing .incbin "baserom.gba", 0x000f4f32, 0x2
.byte 0x14, 0x00

	.global gUnknown_80F4F34
gUnknown_80F4F34: @ 80F4F34
@ replacing .incbin "baserom.gba", 0x000f4f34, 0x2
.byte 0x0a, 0x00

	.global gUnknown_80F4F36
gUnknown_80F4F36: @ 80F4F36
@ replacing .incbin "baserom.gba", 0x000f4f36, 0x2
.byte 0x02, 0x00

	.global gUnknown_80F4F38
gUnknown_80F4F38: @ 80F4F38
@ replacing .incbin "baserom.gba", 0x000f4f38, 0x2
.byte 0x02, 0x00

	.global gUnknown_80F4F3A
gUnknown_80F4F3A: @ 80F4F3A
@ replacing .incbin "baserom.gba", 0x000f4f3a, 0x2
.byte 0x02, 0x00

	.global gUnknown_80F4F3C
gUnknown_80F4F3C: @ 80F4F3C
@ replacing .incbin "baserom.gba", 0x000f4f3c, 0x2
.byte 0x05, 0x00

	.global gUnknown_80F4F3E
gUnknown_80F4F3E: @ 80F4F3E
@ replacing .incbin "baserom.gba", 0x000f4f3e, 0x2
.byte 0x0a, 0x00

	.global gUnknown_80F4F40
gUnknown_80F4F40: @ 80F4F40
@ replacing .incbin "baserom.gba", 0x000f4f40, 0x2
.byte 0x02, 0x00

	.global gUnknown_80F4F42
gUnknown_80F4F42: @ 80F4F42
@ replacing .incbin "baserom.gba", 0x000f4f42, 0x4
.byte 0x14, 0x00
.byte 0x5f, 0x00

	.global gUnknown_80F4F46
gUnknown_80F4F46: @ 80F4F46
@ replacing .incbin "baserom.gba", 0x000f4f46, 0x2
.byte 0x0c, 0x00

	.global gUnknown_80F4F48
gUnknown_80F4F48: @ 80F4F48
@ replacing .incbin "baserom.gba", 0x000f4f48, 0x4
.byte 0x00, 0x02
.byte 0x00, 0x00

	.global gUnknown_80F4F4C
gUnknown_80F4F4C: @ 80F4F4C
@ replacing .incbin "baserom.gba", 0x000f4f4c, 0x4
.byte 0x00, 0x02
.byte 0x00, 0x00

	.global gUnknown_80F4F50
gUnknown_80F4F50: @ 80F4F50
@ replacing .incbin "baserom.gba", 0x000f4f50, 0x4
.byte 0x00, 0x02
.byte 0x00, 0x00

	.global gUnknown_80F4F54
gUnknown_80F4F54: @ 80F4F54
@ replacing .incbin "baserom.gba", 0x000f4f54, 0x4
.byte 0x00, 0x02
.byte 0x00, 0x00

	.global gUnknown_80F4F58
gUnknown_80F4F58: @ 80F4F58
@ replacing .incbin "baserom.gba", 0x000f4f58, 0x4
.byte 0x00, 0x02
.byte 0x00, 0x00

	.global gUnknown_80F4F5C
gUnknown_80F4F5C: @ 80F4F5C
@ replacing .incbin "baserom.gba", 0x000f4f5c, 0x4
.byte 0x00, 0x02
.byte 0x00, 0x00

	.global gUnknown_80F4F60
gUnknown_80F4F60: @ 80F4F60
@ replacing .incbin "baserom.gba", 0x000f4f60, 0x4
.byte 0x00, 0x02
.byte 0x00, 0x00

	.global gUnknown_80F4F64
gUnknown_80F4F64: @ 80F4F64
@ replacing .incbin "baserom.gba", 0x000f4f64, 0x4
.byte 0x00, 0x02
.byte 0x00, 0x00

	.global gUnknown_80F4F68
gUnknown_80F4F68: @ 80F4F68
@ replacing .incbin "baserom.gba", 0x000f4f68, 0x4
.byte 0x00, 0x02
.byte 0x00, 0x00

	.global gUnknown_80F4F6C
gUnknown_80F4F6C: @ 80F4F6C
@ replacing .incbin "baserom.gba", 0x000f4f6c, 0x4
.byte 0x00, 0x02
.byte 0x00, 0x00

	.global gUnknown_80F4F70
gUnknown_80F4F70: @ 80F4F70
@ replacing .incbin "baserom.gba", 0x000f4f70, 0x2
.byte 0x05, 0x00

	.global gUnknown_80F4F72
gUnknown_80F4F72: @ 80F4F72
@ replacing .incbin "baserom.gba", 0x000f4f72, 0x2
.byte 0x04, 0x00

	.global gUnknown_80F4F74
gUnknown_80F4F74: @ 80F4F74
@ replacing .incbin "baserom.gba", 0x000f4f74, 0x2
.byte 0x05, 0x00

	.global gUnknown_80F4F76
gUnknown_80F4F76: @ 80F4F76
@ replacing .incbin "baserom.gba", 0x000f4f76, 0x2
.byte 0x06, 0x00

	.global gUnknown_80F4F78
gUnknown_80F4F78: @ 80F4F78
@ replacing .incbin "baserom.gba", 0x000f4f78, 0x2
.byte 0x08, 0x00

	.global gUnknown_80F4F7A
gUnknown_80F4F7A: @ 80F4F7A
@ replacing .incbin "baserom.gba", 0x000f4f7a, 0x2
.byte 0xe7, 0x03

	.global gUnknown_80F4F7C
gUnknown_80F4F7C: @ 80F4F7C
@ replacing .incbin "baserom.gba", 0x000f4f7c, 0x2
.byte 0x37, 0x00

	.global gUnknown_80F4F7E
gUnknown_80F4F7E: @ 80F4F7E
@ replacing .incbin "baserom.gba", 0x000f4f7e, 0x2
.byte 0x41, 0x00

	.global gUnknown_80F4F80
gUnknown_80F4F80: @ 80F4F80
@ replacing .incbin "baserom.gba", 0x000f4f80, 0x2
.byte 0x23, 0x00

	.global gUnknown_80F4F82
gUnknown_80F4F82: @ 80F4F82
@ replacing .incbin "baserom.gba", 0x000f4f82, 0x2
.byte 0x05, 0x00

	.global gUnknown_80F4F84
gUnknown_80F4F84: @ 80F4F84
@ replacing .incbin "baserom.gba", 0x000f4f84, 0x2
.byte 0x14, 0x00

	.global gUnknown_80F4F86
gUnknown_80F4F86: @ 80F4F86
@ replacing .incbin "baserom.gba", 0x000f4f86, 0x4
.byte 0x0a, 0x00
.byte 0x0f, 0x00

	.global gUnknown_80F4F8A
gUnknown_80F4F8A: @ 80F4F8A
@ replacing .incbin "baserom.gba", 0x000f4f8a, 0x2
.byte 0x05, 0x00

	.global gUnknown_80F4F8C
gUnknown_80F4F8C: @ 80F4F8C
@ replacing .incbin "baserom.gba", 0x000f4f8c, 0x2
.byte 0x23, 0x00

	.global gUnknown_80F4F8E
gUnknown_80F4F8E: @ 80F4F8E
@ replacing .incbin "baserom.gba", 0x000f4f8e, 0x2
.byte 0x05, 0x00

	.global gUnknown_80F4F90
gUnknown_80F4F90: @ 80F4F90
@ replacing .incbin "baserom.gba", 0x000f4f90, 0x2
.byte 0x05, 0x00

	.global gUnknown_80F4F92
gUnknown_80F4F92: @ 80F4F92
@ replacing .incbin "baserom.gba", 0x000f4f92, 0x2
.byte 0x0a, 0x00

	.global gUnknown_80F4F94
gUnknown_80F4F94: @ 80F4F94
@ replacing .incbin "baserom.gba", 0x000f4f94, 0xe
    .byte 0x05, 0x00
    .byte 0x0a, 0x00
    .byte 0x0f, 0x00
    .byte 0x19, 0x00
    .byte 0x1e, 0x00
    .byte 0x23, 0x00
    .byte 0x28, 0x00

	.global gUnknown_80F4FA2
gUnknown_80F4FA2: @ 80F4FA2
@ replacing .incbin "baserom.gba", 0x000f4fa2, 0x2
.byte 0x5a, 0x00

	.global gUnknown_80F4FA4
gUnknown_80F4FA4: @ 80F4FA4
@ replacing .incbin "baserom.gba", 0x000f4fa4, 0x2
    .byte 0x14, 0x00

	.global gUnknown_80F4FA6
gUnknown_80F4FA6: @ 80F4FA6
@ replacing .incbin "baserom.gba", 0x000f4fa6, 0x2
    .byte 0x2d, 0x00

	.global gUnknown_80F4FA8
gUnknown_80F4FA8: @ 80F4FA8
@ replacing .incbin "baserom.gba", 0x000f4fa8, 0x2
    .byte 0x0f, 0x00

	.global gUnknown_80F4FAA
gUnknown_80F4FAA: @ 80F4FAA
@ replacing .incbin "baserom.gba", 0x000f4faa, 0x2
    .byte 0x1e, 0x00

	.global gUnknown_80F4FAC
gUnknown_80F4FAC: @ 80F4FAC
@ replacing .incbin "baserom.gba", 0x000f4fac, 0x2
    .byte 0x01, 0x00

	.global gUnknown_80F4FAE
gUnknown_80F4FAE: @ 80F4FAE
@ replacing .incbin "baserom.gba", 0x000f4fae, 0x4
    .byte 0x02, 0x00
    .byte 0x19, 0x00

	.global gUnknown_80F4FB2
gUnknown_80F4FB2: @ 80F4FB2
@ replacing .incbin "baserom.gba", 0x000f4fb2, 0x2
    .byte 0x0a, 0x00

	.global gUnknown_80F4FB4
gUnknown_80F4FB4: @ 80F4FB4
@ replacing .incbin "baserom.gba", 0x000f4fb4, 0x2
    .byte 0x0a, 0x00

	.global gUnknown_80F4FB6
gUnknown_80F4FB6: @ 80F4FB6
@ replacing .incbin "baserom.gba", 0x000f4fb6, 0x2
    .byte 0x64, 0x00

	.global gUnknown_80F4FB8
gUnknown_80F4FB8: @ 80F4FB8
@ replacing .incbin "baserom.gba", 0x000f4fb8, 0x2
    .byte 0x00, 0x00

	.global gUnknown_80F4FBA
gUnknown_80F4FBA: @ 80F4FBA
@ replacing .incbin "baserom.gba", 0x000f4fba, 0x2
    .byte 0x64, 0x00

	.global gUnknown_80F4FBC
gUnknown_80F4FBC: @ 80F4FBC
@ replacing .incbin "baserom.gba", 0x000f4fbc, 0x2
    .byte 0x02, 0x00

	.global gUnknown_80F4FBE
gUnknown_80F4FBE: @ 80F4FBE
@ replacing .incbin "baserom.gba", 0x000f4fbe, 0x2
    .byte 0x03, 0x00

	.global gUnknown_80F4FC0
gUnknown_80F4FC0: @ 80F4FC0
@ replacing .incbin "baserom.gba", 0x000f4fc0, 0x2
    .byte 0x24, 0xff

	.global gUnknown_80F4FC2
gUnknown_80F4FC2: @ 80F4FC2
@ replacing .incbin "baserom.gba", 0x000f4fc2, 0x2
    .byte 0x6a, 0xff

	.global gUnknown_80F4FC4
gUnknown_80F4FC4: @ 80F4FC4
@ replacing .incbin "baserom.gba", 0x000f4fc4, 0x2
    .byte 0x9c, 0xff

	.global gUnknown_80F4FC6
gUnknown_80F4FC6: @ 80F4FC6
@ replacing .incbin "baserom.gba", 0x000f4fc6, 0x2
    .byte 0x0a, 0x00

	.global gUnknown_80F4FC8
gUnknown_80F4FC8: @ 80F4FC8
	.incbin "baserom.gba", 0xF4FC8, 0x3C

	.global gUnknown_80F5004
gUnknown_80F5004: @ 80F5004
	.incbin "baserom.gba", 0xF5004, 0x2

	.global gUnknown_80F5006
gUnknown_80F5006: @ 80F5006
	.incbin "baserom.gba", 0xF5006, 0x2

	.global gUnknown_80F5008
gUnknown_80F5008: @ 80F5008
	.incbin "baserom.gba", 0xF5008, 0x2

	.global gUnknown_80F500A
gUnknown_80F500A: @ 80F500A
	.incbin "baserom.gba", 0xF500A, 0x10

	.global gUnknown_80F501A
gUnknown_80F501A: @ 80F501A
	.incbin "baserom.gba", 0xF501A, 0x10

	.global gUnknown_80F502A
gUnknown_80F502A: @ 80F502A
	.incbin "baserom.gba", 0xF502A, 0x10

	.global gUnknown_80F503A
gUnknown_80F503A: @ 80F503A
	.incbin "baserom.gba", 0xF503A, 0x2

	.global gUnknown_80F503C
gUnknown_80F503C: @ 80F503C
	.incbin "baserom.gba", 0xF503C, 0x2

	.global gUnknown_80F503E
gUnknown_80F503E: @ 80F503E
	.incbin "baserom.gba", 0xF503E, 0x2

	.global gUnknown_80F5040
gUnknown_80F5040: @ 80F5040
	.incbin "baserom.gba", 0xF5040, 0x2

	.global gUnknown_80F5042
gUnknown_80F5042: @ 80F5042
	.incbin "baserom.gba", 0xF5042, 0x2

	.global gUnknown_80F5044
gUnknown_80F5044: @ 80F5044
	.incbin "baserom.gba", 0xF5044, 0x2

	.global gUnknown_80F5046
gUnknown_80F5046: @ 80F5046
	.incbin "baserom.gba", 0xF5046, 0x2

	.global gUnknown_80F5048
gUnknown_80F5048: @ 80F5048
	.incbin "baserom.gba", 0xF5048, 0x4

	.global gUnknown_80F504C
gUnknown_80F504C: @ 80F504C
	.incbin "baserom.gba", 0xF504C, 0x54

	.global gUnknown_80F50A0
gUnknown_80F50A0: @ 80F50A0
	.incbin "baserom.gba", 0xF50A0, 0x54

	.global gUnknown_80F50F4
gUnknown_80F50F4: @ 80F50F4
	.incbin "baserom.gba", 0xF50F4, 0xA8

	.global gUnknown_80F519C
gUnknown_80F519C: @ 80F519C
	.incbin "baserom.gba", 0xF519C, 0x4

	.global gUnknown_80F51A0
gUnknown_80F51A0: @ 80F51A0
	.incbin "baserom.gba", 0xF51A0, 0x4

	.global gUnknown_80F51A4
gUnknown_80F51A4: @ 80F51A4
	.incbin "baserom.gba", 0xF51A4, 0x10

	.global gUnknown_80F51B4
gUnknown_80F51B4: @ 80F51B4
	.incbin "baserom.gba", 0xF51B4, 0x10

	.global gUnknown_80F51C4
gUnknown_80F51C4: @ 80F51C4
	.incbin "baserom.gba", 0xF51C4, 0x10

	.global gUnknown_80F51D4
gUnknown_80F51D4: @ 80F51D4
	.incbin "baserom.gba", 0xF51D4, 0x10

	.global gUnknown_80F51E4
gUnknown_80F51E4: @ 80F51E4
	.incbin "baserom.gba", 0xF51E4, 0x8

	.global gUnknown_80F51EC
gUnknown_80F51EC: @ 80F51EC
	.incbin "baserom.gba", 0xF51EC, 0x20

	.global gUnknown_80F520C
gUnknown_80F520C: @ 80F520C
	.incbin "baserom.gba", 0xF520C, 0x20

	.global gUnknown_80F522C
gUnknown_80F522C: @ 80F522C
	.incbin "baserom.gba", 0xF522C, 0x288

	.global gUnknown_80F54B4
gUnknown_80F54B4: @ 80F54B4
	.incbin "baserom.gba", 0xF54B4, 0x40

	.global gUnknown_80F54F4
gUnknown_80F54F4: @ 80F54F4
	.incbin "baserom.gba", 0xF54F4, 0xA0

	.global gUnknown_80F5594
gUnknown_80F5594: @ 80F5594
	.incbin "baserom.gba", 0xF5594, 0x28

	.global gUnknown_80F55BC
gUnknown_80F55BC: @ 80F55BC
	.incbin "baserom.gba", 0xF55BC, 0x30

	.global gUnknown_80F55EC
gUnknown_80F55EC: @ 80F55EC
	.incbin "baserom.gba", 0xF55EC, 0x30

	.global gUnknown_80F561C
gUnknown_80F561C: @ 80F561C
	.incbin "baserom.gba", 0xF561C, 0x4C

	.global gUnknown_80F5668
gUnknown_80F5668: @ 80F5668
	.incbin "baserom.gba", 0xF5668, 0x98

	.global gUnknown_80F5700
gUnknown_80F5700: @ 80F5700
	.incbin "baserom.gba", 0xF5700, 0xCA

	.global gUnknown_80F57CA
gUnknown_80F57CA: @ 80F57CA
	.incbin "baserom.gba", 0xF57CA, 0x2

	.global gUnknown_80F57CC
gUnknown_80F57CC: @ 80F57CC
	.incbin "baserom.gba", 0xF57CC, 0x2

	.global gUnknown_80F57CE
gUnknown_80F57CE: @ 80F57CE
	.incbin "baserom.gba", 0xF57CE, 0x2

	.global gUnknown_80F57D0
gUnknown_80F57D0: @ 80F57D0
	.incbin "baserom.gba", 0xF57D0, 0x2

	.global gUnknown_80F57D2
gUnknown_80F57D2: @ 80F57D2
	.incbin "baserom.gba", 0xF57D2, 0x2

	.global gUnknown_80F57D4
gUnknown_80F57D4: @ 80F57D4
	.incbin "baserom.gba", 0xF57D4, 0x120

	.global gUnknown_80F58F4
gUnknown_80F58F4: @ 80F58F4
	.incbin "baserom.gba", 0xF58F4, 0x84

	.global gUnknown_80F5978
gUnknown_80F5978: @ 80F5978
	.incbin "baserom.gba", 0xF5978, 0x4C

	.global gUnknown_80F59C4
gUnknown_80F59C4: @ 80F59C4
	.incbin "baserom.gba", 0xF59C4, 0x4

	.global gUnknown_80F59C8
gUnknown_80F59C8: @ 80F59C8
	.incbin "baserom.gba", 0xF59C8, 0x348

	.global gUnknown_80F5D10
gUnknown_80F5D10: @ 80F5D10
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

	.global gUnknown_80F669C
gUnknown_80F669C: @ 80F669C
	.incbin "baserom.gba", 0xF669C, 0x18

	.global gUnknown_80F66B4
gUnknown_80F66B4: @ 80F66B4
	.incbin "baserom.gba", 0xF66B4, 0x14

	.global gUnknown_80F66C8
gUnknown_80F66C8: @ 80F66C8
	.incbin "baserom.gba", 0xF66C8, 0x20

	.global gUnknown_80F66E8
gUnknown_80F66E8: @ 80F66E8
	.incbin "baserom.gba", 0xF66E8, 0x20

	.global gUnknown_80F6708
gUnknown_80F6708: @ 80F6708
	.incbin "baserom.gba", 0xF6708, 0x34

	.global gUnknown_80F673C
gUnknown_80F673C: @ 80F673C
	.incbin "baserom.gba", 0xF673C, 0x3C

	.global gUnknown_80F6778
gUnknown_80F6778: @ 80F6778
	.incbin "baserom.gba", 0xF6778, 0x10

	.global gUnknown_80F6788
gUnknown_80F6788: @ 80F6788
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00

	.global gUnknown_80F6794
gUnknown_80F6794: @ 80F6794
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x01, 0x00
        .byte 0x00, 0x00, 0x02, 0x00
        .byte 0x00, 0x00, 0x04, 0x00
        .byte 0x00, 0x00, 0x08, 0x00

	.global gUnknown_80F67A8
gUnknown_80F67A8: @ 80F67A8
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00

	.global gUnknown_80F67B4
gUnknown_80F67B4: @ 80F67B4
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00

	.global gUnknown_80F67C4
gUnknown_80F67C4: @ 80F67C4
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x10, 0x00
        .byte 0x00, 0x00, 0x20, 0x00
        .byte 0x00, 0x00, 0x40, 0x00

	.global gUnknown_80F67D4
gUnknown_80F67D4: @ 80F67D4
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x80, 0x00

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

	.global gUnknown_80F6860
gUnknown_80F6860: @ 80F6860
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
	.incbin "baserom.gba", 0xF7AE8, 0x2

	.global gUnknown_80F7AEA
gUnknown_80F7AEA: @ 80F7AEA
	.incbin "baserom.gba", 0xF7AEA, 0xE

	.global gUnknown_80F7AF8
gUnknown_80F7AF8: @ 80F7AF8
	.incbin "baserom.gba", 0xF7AF8, 0x4

	.global gUnknown_80F7AFC
gUnknown_80F7AFC: @ 80F7AFC
        .string "#C6%s#R\0"
        .align 2,0

	.global gUnknown_80F7B04
gUnknown_80F7B04: @ 80F7B04
        .string "#C6"
        .byte 0x87, 0x45
        .string "#R\0"
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
	.string "$m0 put on\n"
	.string "the $i0.\0"

	.global gPeelText
gPeelText: @ 80F7BA8
	.string "Peel\0"
	.align 2,0

	.global gPeelDescription
gPeelDescription: @ 80F7BB0
	.string "$m0 peeled\n"
	.string "the $i0.\0"
	.align 2,0

	.global gIngestText
gIngestText: @ 80F7BC4
	.string "Ingest\0"
	.align 2,0

	.global gIngestDescription
gIngestDescription: @ 80F7BCC
	.string "$m0 swallowed\n"
	.string "the $i0.\0"
	.align 2,0

	.global gEatText
gEatText: @ 80F7BE4
	.string "Eat\0"
	.align 2,0

	.global gEatDescription
gEatDescription: @ 80F7BE8
	.string "$m0 ate\n"
	.string "the $i0.\0"
	.align 2,0

	.global gEquipText
gEquipText: @ 80F7BFC
	.string "Equip\0"
	.align 2,0

	.global gEquipDescription
gEquipDescription: @ 80F7C04
	.string "$m0 equipped\n"
	.string "the $i0.\0"
	.align 2,0

	.global gThrowText
gThrowText: @ 80F7C1C
	.string "Throw\0"
	.align 2,0

	.global gThrowDescription
gThrowDescription: @ 80F7C24
	.string "$m0 threw\n"
	.string "the $i0.\0"
	.align 2,0

	.global gUseText
gUseText: @ 80F7C38
	.string "Use\0"
	.align 2,0

	.global gUseDescription
gUseDescription: @ 80F7C3C
	.string "$m0 used\n"
	.string "the $i0.\0"
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
	.string "friend~27s team went down!\n"
	.string "Send an #c2A-OK Mail#r from the Pelipper Post\n"
	.string "Office to let your friend know you~27ve\n"
	.string "rescued the defeated team.\0"
	.align 2,0

	.global gWarpZoneDescription
gWarpZoneDescription: @ 80F8030
	.string "The warp zone leading to the next floor.\n"
	.string "If you are on the final floor~2c you will\n"
	.string "escape from the dungeon.\0"
	.align 2,0

	.global gDungeonStairsDescription
gDungeonStairsDescription: @ 80F809C
	.string "Stairs leading to the next floor.\n"
	.string "If you are on the final floor~2c you will\n"
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
        .string "Your partner $m0 fainted!\0"
        .align 2,0

	.global gUnknown_80F89B4
gUnknown_80F89B4: @ 80F89B4
        .byte 0x98, 0x89, 0x0F, 0x08
        .string "Your client $m0 fainted!\0"
        .align 2,0

	.global gUnknown_80F89D4
gUnknown_80F89D4: @ 80F89D4
        .byte 0xB8, 0x89, 0x0F, 0x08

	.global gUnknown_80F89D8
gUnknown_80F89D8: @ 80F89D8
        .byte 0xB8, 0x89, 0x0F, 0x08
        .string "But nothing happened!\0"
        .align 2,0

	.global gUnknown_80F89F4
gUnknown_80F89F4: @ 80F89F4
        .byte 0xDC, 0x89, 0x0F, 0x08
        .string "$m0 was blown away!\0"
        .align 2,0

	.global gUnknown_80F8A0C
gUnknown_80F8A0C: @ 80F8A0C
        .byte 0xF8, 0x89, 0x0F, 0x08
        .string "No move has been set.\0"
        .align 2,0

	.global gUnknown_80F8A28
gUnknown_80F8A28: @ 80F8A28
        .byte 0x10, 0x8A, 0x0F, 0x08
        .string "The set move can~27t be used.\0"
        .align 2,0

	.global gUnknown_80F8A4C
gUnknown_80F8A4C: @ 80F8A4C
        .byte 0x2C, 0x8A, 0x0F, 0x08
        .string "You~27re being constricted!\0"
        .align 2,0

	.global gUnknown_80F8A6C
gUnknown_80F8A6C: @ 80F8A6C
        .byte 0x50, 0x8A, 0x0F, 0x08
        .string "You can~27t move!\0"
        .align 2,0

	.global gUnknown_80F8A84
gUnknown_80F8A84: @ 80F8A84
        .byte 0x70, 0x8A, 0x0F, 0x08
        .string "You can~27t move while you~27re rooted!\0"
        .align 2,0

	.global gUnknown_80F8AB0
gUnknown_80F8AB0: @ 80F8AB0
        .byte 0x88, 0x8A, 0x0F, 0x08
        .string "You can~27t move while wrapping a foe!\0"
        .align 2,0

	.global gUnknown_80F8ADC
gUnknown_80F8ADC: @ 80F8ADC
        .byte 0xB4, 0x8A, 0x0F, 0x08
        .string "The foe has you wrapped! You can~27t move!\0"
        .align 2,0

	.global gUnknown_80F8B0C
gUnknown_80F8B0C: @ 80F8B0C
        .byte 0xE0, 0x8A, 0x0F, 0x08
        .string "There are no items.\0"

	.global gUnknown_80F8B24
gUnknown_80F8B24: @ 80F8B24
        .byte 0x10, 0x8B, 0x0F, 0x08
        .string "The move $i0 was set.\0"
        .align 2,0

	.global gUnknown_80F8B40
gUnknown_80F8B40: @ 80F8B40
        .byte 0x28, 0x8B, 0x0F, 0x08
        .string "The move $i0 was deselected.\0"
        .align 2,0

	.global gUnknown_80F8B64
gUnknown_80F8B64: @ 80F8B64
        .byte 0x44, 0x8B, 0x0F, 0x08
        .byte 0x20, 0x7F, 0x0F, 0x08
        .string "The move $i0 was delinked.\0"
        .align 2,0

	.global gUnknown_80F8B88
gUnknown_80F8B88: @ 80F8B88
        .byte 0x6C, 0x8B, 0x0F, 0x08
        .string "The linked moves were left unchanged.\0"
        .align 2,0

	.global gUnknown_80F8BB4
gUnknown_80F8BB4: @ 80F8BB4
        .byte 0x8C, 0x8B, 0x0F, 0x08
        .string "It~27s all sticky and doesn~27t work!\0"
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
        .string "The $i0 is all sticky!\nIt can~27t be equipped.\0"
        .align 2,0

	.global gUnknown_80F8C7C
gUnknown_80F8C7C: @ 80F8C7C
        .byte 0x4C, 0x8C, 0x0F, 0x08
        .string "$m1 took the $i0\n"
        .string "and returned the $i1.\0"
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
        .string "Equipped the item $i0.\0"
        .align 2,0

	.global gUnknown_80F8D04
gUnknown_80F8D04: @ 80F8D04
        .byte 0xEC, 0x8C, 0x0F, 0x08
        .string "The $i0 was deselected.\0"

	.global gUnknown_80F8D20
gUnknown_80F8D20: @ 80F8D20
        .byte 0x08, 0x8D, 0x0F, 0x08
        .string "The item $i0 was given\n"
        .string "to $m1.\0"
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

	.global gUnknown_80F91F0
gUnknown_80F91F0: @ 80F91F0
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
	.incbin "baserom.gba", 0xF9530, 0x1C

	.global gUnknown_80F954C
gUnknown_80F954C: @ 80F954C
	.incbin "baserom.gba", 0xF954C, 0x20

	.global gUnknown_80F956C
gUnknown_80F956C: @ 80F956C
	.incbin "baserom.gba", 0xF956C, 0x20

	.global gUnknown_80F958C
gUnknown_80F958C: @ 80F958C
	.incbin "baserom.gba", 0xF958C, 0x18

	.global gUnknown_80F95A4
gUnknown_80F95A4: @ 80F95A4
	.incbin "baserom.gba", 0xF95A4, 0x18

	.global gUnknown_80F95BC
gUnknown_80F95BC: @ 80F95BC
	.incbin "baserom.gba", 0xF95BC, 0x1C

	.global gUnknown_80F95D8
gUnknown_80F95D8: @ 80F95D8
	.incbin "baserom.gba", 0xF95D8, 0x14

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

	.global gUnknown_80F9A54
gUnknown_80F9A54: @ 80F9A54
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

	.global gUnknown_80FE308
gUnknown_80FE308: @ 80FE308
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

        .string "$m0~27s item\0"
        .align 2,0

	.global gUnknown_80FE940
gUnknown_80FE940: @ 80FE940
        .byte 0x30, 0xe9, 0x0f, 0x08

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
        .byte 0xfc, 0x7e, 0x0f, 0x08

        .string "$i0\0"
        .align 2,0

	.global gUnknown_80FE95C
gUnknown_80FE95C: @ 80FE95C
        .byte 0x58, 0xe9, 0x0f, 0x08

	.global gUnknown_80FE960
gUnknown_80FE960: @ 80FE960
        .byte 0x58, 0xe9, 0x0f, 0x08

	.global gUnknown_80FE964
gUnknown_80FE964: @ 80FE964
        .byte 0x58, 0xe9, 0x0f, 0x08

        .string "$m0~27s moves\0"
        .align 2,0

	.global gUnknown_80FE978
gUnknown_80FE978: @ 80FE978
        .byte 0x68, 0xe9, 0x0f, 0x08

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

        .string "Recruited Pokémon\0"
        .align 2,0

	.global gUnknown_80FEA80
gUnknown_80FEA80: @ 80FEA80
        .byte 0x6C, 0xEA, 0x0F, 0x08

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
	.string "It~27s Magnitude $d0!\0"
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
	.string "$m0 found an item somewhere.\0"
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
	.string "#c6The linked moves are almost out of PP!#r\n"
	.string "#c6Use them again and they will come apart!#r\0"
	.align 2, 0

	.global gPtrLinkMoveOneUseWarningMessage
gPtrLinkMoveOneUseWarningMessage: @ 810035C
	.4byte gLinkMoveOneUseWarningMessage

	.global gLinkMoveTwoUsesWarningMessage
gLinkMoveTwoUsesWarningMessage: @ 8100360
	.string "#c6The linked moves are almost out of PP!#r\n"
	.string "#c6Use them twice and they will come apart!#r\0"
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
	.string "The Music Box played a beautiful melody~2c\n"
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
	.string "But it couldn~27t be used!\0"
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
	.string "$m1~27s Soundproof suppressed\n"
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
	.string "Perish Song~27s effect wore off!\0"
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
	.string "A leech seed can~27t be planted on the user!\0"
	.align 2, 0

	.global gPtrCantLeechSeedSelfMessage
gPtrCantLeechSeedSelfMessage: @ 8100610
	.4byte gCantLeechSeedSelfMessage

	.global gCantLeechSeedMonMessage
gCantLeechSeedMonMessage: @ 8100614
	.string "A leech seed couldn~27t be planted on\n"
	.string "$m0!\0"
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
	.string "A rescue call can~27t be made!\0"
	.align 2, 0

	.global gPtrClientFaintedMessage
gPtrClientFaintedMessage: @ 81006A4
	.4byte gClientFaintedMessage

	.global gCantUseInDungeonMessage
gCantUseInDungeonMessage: @ 81006A8
	.string "It can~27t be used in a dungeon!\0"
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

	.global gUnknown_8100768
gUnknown_8100768: @ 8100768
	.byte 0x00, 0x00, 0x0C, 0x02, 0xAA, 0x01, 0x00, 0x00
	.4byte gUnknown_8100774

	.global gUnknown_8100774
gUnknown_8100774: @ 8100774
	.string " Look~2c $m0!\n"
	.string "$m2~27s over there!\0"
	.align 2, 0

	.global gUnknown_8100798
gUnknown_8100798: @ 8100798
	.byte 0x00, 0x00, 0x04, 0x02, 0xAA, 0x01, 0x07, 0x00
	.4byte gUnknown_81007E8
	.byte 0x00, 0x00, 0x04, 0x02, 0xAA, 0x01, 0x00, 0x00
	.4byte gUnknown_81007B0

	.global gUnknown_81007B0
gUnknown_81007B0: @ 81007B0
	.string " Hey! Are you all right?\n"
	.string "We~27ve come to rescue you!\0"
	.align 2, 0

	.global gUnknown_81007E8
gUnknown_81007E8: @ 81007E8
	.string " Hey! Are you all right?\n"
	.string "We~27re here to rescue you!\0"
	.align 2, 0

	.global gUnknown_8100820
gUnknown_8100820: @ 8100820
	.byte 0x00, 0x00, 0x01, 0x0D, 0x32, 0x00, 0x00, 0x00
	.4byte gUnknown_810082C

	.global gUnknown_810082C
gUnknown_810082C: @ 810082C
	.string " ...I...\n"
	.string "I~27m scared.\0"
	.align 2, 0

	.global gUnknown_8100844
gUnknown_8100844: @ 8100844
	.incbin "baserom.gba", 0x100844, 0x3C

	.global gUnknown_8100880
gUnknown_8100880: @ 8100880
	.incbin "baserom.gba", 0x100880, 0xA8

	.global gUnknown_8100928
gUnknown_8100928: @ 8100928
	.byte 0x00, 0x00, 0x00, 0x0D, 0xFC, 0x00, 0x00, 0x00
	.4byte gUnknown_8100934

	.global gUnknown_8100934
gUnknown_8100934: @ 8100934
	.string " How dare you!#W\n"
	.string "It~27s their fault!#P"
	.string " I haven~27t slept in days\n"
	.string "because the earthquakes frighten me so!\n"
	.string "Every night we had them!#P"
	.string " Those earthquakes are\n"
	.string "caused by this brat~27s ilk running wild\n"
	.string "underground!\0"
	.align 2, 0

	.global gUnknown_8100A04
gUnknown_8100A04: @ 8100A04
	.incbin "baserom.gba", 0x100A04, 0x17C

	.global gUnknown_8100B80
gUnknown_8100B80: @ 8100B80
	.incbin "baserom.gba", 0x100B80, 0x40

	.global gUnknown_8100BC0
gUnknown_8100BC0: @ 8100BC0
	.incbin "baserom.gba", 0x100BC0, 0xD0

@ Skarmony Re-Fight?

	.global gUnknown_8100C90
gUnknown_8100C90: @ 8100C90
        .byte 0x00, 0x00, 0x00, 0x0D
        .byte 0xFC, 0x00, 0x00, 0x00
        .4byte _08100C9C
    
        .global _08100C9C
        _08100C9C:
        .string " You again?!\n"
        .asciz "Persistent pests!\0"
        .align 2,0

	.global gUnknown_8100CBC
gUnknown_8100CBC: @ 8100CBC
	.incbin "baserom.gba", 0x100CBC, 0x20

	.global gUnknown_8100CDC
gUnknown_8100CDC: @ 8100CDC
	.incbin "baserom.gba", 0x100CDC, 0x60

	.global gUnknown_8100D3C
gUnknown_8100D3C: @ 8100D3C
	.incbin "baserom.gba", 0x100D3C, 0x74

	.global gUnknown_8100DB0
gUnknown_8100DB0: @ 8100DB0
	.incbin "baserom.gba", 0x100DB0, 0xB4

	.global gUnknown_8100E64
gUnknown_8100E64: @ 8100E64
	.incbin "baserom.gba", 0x100E64, 0x24

	.global gUnknown_8100E88
gUnknown_8100E88: @ 8100E88
	.incbin "baserom.gba", 0x100E88, 0x8C

	.global gUnknown_8100F14
gUnknown_8100F14: @ 8100F14
	.incbin "baserom.gba", 0x100F14, 0xF0

	.global gUnknown_8101004
gUnknown_8101004: @ 8101004
	.incbin "baserom.gba", 0x101004, 0x4C

	.global gUnknown_8101050
gUnknown_8101050: @ 8101050
	.incbin "baserom.gba", 0x101050, 0x80

	.global gUnknown_81010D0
gUnknown_81010D0: @ 81010D0
	.incbin "baserom.gba", 0x1010D0, 0x94

	.global gUnknown_8101164
gUnknown_8101164: @ 8101164
	.incbin "baserom.gba", 0x101164, 0xDC

	.global gUnknown_8101240
gUnknown_8101240: @ 8101240
	.incbin "baserom.gba", 0x101240, 0xD0

	.global gUnknown_8101310
gUnknown_8101310: @ 8101310
	.incbin "baserom.gba", 0x101310, 0x6C

	.global gUnknown_810137C
gUnknown_810137C: @ 810137C
	.incbin "baserom.gba", 0x10137C, 0x8C

	.global gUnknown_8101408
gUnknown_8101408: @ 8101408
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

	.global gUnknown_81017E4
gUnknown_81017E4: @ 81017E4
	.incbin "baserom.gba", 0x1017E4, 0xB4

	.global gUnknown_8101898
gUnknown_8101898: @ 8101898
	.incbin "baserom.gba", 0x101898, 0x54

	.global gUnknown_81018EC
gUnknown_81018EC: @ 81018EC
	.incbin "baserom.gba", 0x1018EC, 0x2C

	.global gUnknown_8101918
gUnknown_8101918: @ 8101918
	.incbin "baserom.gba", 0x101918, 0x24

	.global gUnknown_810193C
gUnknown_810193C: @ 810193C
	.incbin "baserom.gba", 0x10193C, 0x34

	.global gUnknown_8101970
gUnknown_8101970: @ 8101970
	.incbin "baserom.gba", 0x101970, 0x24

	.global gUnknown_8101994
gUnknown_8101994: @ 8101994
	.incbin "baserom.gba", 0x101994, 0x50

	.global gUnknown_81019E4
gUnknown_81019E4: @ 81019E4
	.incbin "baserom.gba", 0x1019E4, 0x20

	.global gUnknown_8101A04
gUnknown_8101A04: @ 8101A04
	.incbin "baserom.gba", 0x101A04, 0x34

	.global gUnknown_8101A38
gUnknown_8101A38: @ 8101A38
	.incbin "baserom.gba", 0x101A38, 0x64

	.global gUnknown_8101A9C
gUnknown_8101A9C: @ 8101A9C
	.incbin "baserom.gba", 0x101A9C, 0x38

	.global gUnknown_8101AD4
gUnknown_8101AD4: @ 8101AD4
	.incbin "baserom.gba", 0x101AD4, 0x15C

	.global gUnknown_8101C30
gUnknown_8101C30: @ 8101C30
	.incbin "baserom.gba", 0x101C30, 0x8C

	.global gUnknown_8101CBC
gUnknown_8101CBC: @ 8101CBC
	.incbin "baserom.gba", 0x101CBC, 0xD0

	.global gUnknown_8101D8C
gUnknown_8101D8C: @ 8101D8C
	.incbin "baserom.gba", 0x101D8C, 0x14

	.global gUnknown_8101DA0
gUnknown_8101DA0: @ 8101DA0
	.incbin "baserom.gba", 0x101DA0, 0x7C

	.global gUnknown_8101E1C
gUnknown_8101E1C: @ 8101E1C
	.incbin "baserom.gba", 0x101E1C, 0x90

	.global gUnknown_8101EAC
gUnknown_8101EAC: @ 8101EAC
	.incbin "baserom.gba", 0x101EAC, 0x1C4

	.global gUnknown_8102070
gUnknown_8102070: @ 8102070
	.incbin "baserom.gba", 0x102070, 0x34

	.global gUnknown_81020A4
gUnknown_81020A4: @ 81020A4
	.incbin "baserom.gba", 0x1020A4, 0x30

	.global gUnknown_81020D4
gUnknown_81020D4: @ 81020D4
	.incbin "baserom.gba", 0x1020D4, 0x34

	.global gUnknown_8102108
gUnknown_8102108: @ 8102108
	.incbin "baserom.gba", 0x102108, 0x50

	.global gUnknown_8102158
gUnknown_8102158: @ 8102158
	.incbin "baserom.gba", 0x102158, 0x38

	.global gUnknown_8102190
gUnknown_8102190: @ 8102190
	.incbin "baserom.gba", 0x102190, 0x70

	.global gUnknown_8102200
gUnknown_8102200: @ 8102200
	.incbin "baserom.gba", 0x102200, 0x54

	.global gUnknown_8102254
gUnknown_8102254: @ 8102254
	.incbin "baserom.gba", 0x102254, 0xA4

	.global gUnknown_81022F8
gUnknown_81022F8: @ 81022F8
	.incbin "baserom.gba", 0x1022F8, 0x34

	.global gUnknown_810232C
gUnknown_810232C: @ 810232C
	.incbin "baserom.gba", 0x10232C, 0x6C

	.global gUnknown_8102398
gUnknown_8102398: @ 8102398
	.incbin "baserom.gba", 0x102398, 0x2C

	.global gUnknown_81023C4
gUnknown_81023C4: @ 81023C4
	.incbin "baserom.gba", 0x1023C4, 0x3C

	.global gUnknown_8102400
gUnknown_8102400: @ 8102400
	.incbin "baserom.gba", 0x102400, 0x54

	.global gUnknown_8102454
gUnknown_8102454: @ 8102454
	.incbin "baserom.gba", 0x102454, 0x24

	.global gUnknown_8102478
gUnknown_8102478: @ 8102478
	.incbin "baserom.gba", 0x102478, 0x13C

	.global gUnknown_81025B4
gUnknown_81025B4: @ 81025B4
	.incbin "baserom.gba", 0x1025B4, 0x20

	.global gUnknown_81025D4
gUnknown_81025D4: @ 81025D4
	.incbin "baserom.gba", 0x1025D4, 0x3C

	.global gUnknown_8102610
gUnknown_8102610: @ 8102610
	.incbin "baserom.gba", 0x102610, 0xB4

	.global gUnknown_81026C4
gUnknown_81026C4: @ 81026C4
	.incbin "baserom.gba", 0x1026C4, 0x48

	.global gUnknown_810270C
gUnknown_810270C: @ 810270C
	.incbin "baserom.gba", 0x10270C, 0x20

	.global gUnknown_810272C
gUnknown_810272C: @ 810272C
	.incbin "baserom.gba", 0x10272C, 0x90

	.global gUnknown_81027BC
gUnknown_81027BC: @ 81027BC
	.incbin "baserom.gba", 0x1027BC, 0x54

	.global gUnknown_8102810
gUnknown_8102810: @ 8102810
	.incbin "baserom.gba", 0x102810, 0x30

	.global gUnknown_8102840
gUnknown_8102840: @ 8102840
	.incbin "baserom.gba", 0x102840, 0x2C

	.global gUnknown_810286C
gUnknown_810286C: @ 810286C
	.incbin "baserom.gba", 0x10286C, 0x4C

	.global gUnknown_81028B8
gUnknown_81028B8: @ 81028B8
	.incbin "baserom.gba", 0x1028B8, 0x1C

	.global gUnknown_81028D4
gUnknown_81028D4: @ 81028D4
	.incbin "baserom.gba", 0x1028D4, 0x44

	.global gUnknown_8102918
gUnknown_8102918: @ 8102918
	.incbin "baserom.gba", 0x102918, 0x30

	.global gUnknown_8102948
gUnknown_8102948: @ 8102948
	.incbin "baserom.gba", 0x102948, 0x3C

	.global gUnknown_8102984
gUnknown_8102984: @ 8102984
	.incbin "baserom.gba", 0x102984, 0x30

	.global gUnknown_81029B4
gUnknown_81029B4: @ 81029B4
	.incbin "baserom.gba", 0x1029B4, 0x64

	.global gUnknown_8102A18
gUnknown_8102A18: @ 8102A18
	.incbin "baserom.gba", 0x102A18, 0xC

	.global gUnknown_8102A24
gUnknown_8102A24: @ 8102A24
	.incbin "baserom.gba", 0x102A24, 0x50

	.global gUnknown_8102A74
gUnknown_8102A74: @ 8102A74
	.incbin "baserom.gba", 0x102A74, 0x28

	.global gUnknown_8102A9C
gUnknown_8102A9C: @ 8102A9C
	.incbin "baserom.gba", 0x102A9C, 0x74

	.global gUnknown_8102B10
gUnknown_8102B10: @ 8102B10
	.incbin "baserom.gba", 0x102B10, 0xC

	.global gUnknown_8102B1C
gUnknown_8102B1C: @ 8102B1C
	.incbin "baserom.gba", 0x102B1C, 0x38

	.global gUnknown_8102B54
gUnknown_8102B54: @ 8102B54
	.incbin "baserom.gba", 0x102B54, 0x70

	.global gUnknown_8102BC4
gUnknown_8102BC4: @ 8102BC4
	.incbin "baserom.gba", 0x102BC4, 0x20

	.global gUnknown_8102BE4
gUnknown_8102BE4: @ 8102BE4
	.incbin "baserom.gba", 0x102BE4, 0x4C

	.global gUnknown_8102C30
gUnknown_8102C30: @ 8102C30
	.incbin "baserom.gba", 0x102C30, 0x24

	.global gUnknown_8102C54
gUnknown_8102C54: @ 8102C54
	.incbin "baserom.gba", 0x102C54, 0x44

	.global gUnknown_8102C98
gUnknown_8102C98: @ 8102C98
	.incbin "baserom.gba", 0x102C98, 0x18

	.global gUnknown_8102CB0
gUnknown_8102CB0: @ 8102CB0
	.incbin "baserom.gba", 0x102CB0, 0x48

	.global gUnknown_8102CF8
gUnknown_8102CF8: @ 8102CF8
	.incbin "baserom.gba", 0x102CF8, 0x3C

	.global gUnknown_8102D34
gUnknown_8102D34: @ 8102D34
	.incbin "baserom.gba", 0x102D34, 0x18

	.global gUnknown_8102D4C
gUnknown_8102D4C: @ 8102D4C
	.incbin "baserom.gba", 0x102D4C, 0x30

	.global gUnknown_8102D7C
gUnknown_8102D7C: @ 8102D7C
	.incbin "baserom.gba", 0x102D7C, 0x80

	.global gUnknown_8102DFC
gUnknown_8102DFC: @ 8102DFC
	.incbin "baserom.gba", 0x102DFC, 0x30

	.global gUnknown_8102E2C
gUnknown_8102E2C: @ 8102E2C
	.incbin "baserom.gba", 0x102E2C, 0x28

	.global gUnknown_8102E54
gUnknown_8102E54: @ 8102E54
	.incbin "baserom.gba", 0x102E54, 0x1C

	.global gUnknown_8102E70
gUnknown_8102E70: @ 8102E70
	.incbin "baserom.gba", 0x102E70, 0x4C

	.global gUnknown_8102EBC
gUnknown_8102EBC: @ 8102EBC
	.incbin "baserom.gba", 0x102EBC, 0x24

	.global gUnknown_8102EE0
gUnknown_8102EE0: @ 8102EE0
	.incbin "baserom.gba", 0x102EE0, 0x18

	.global gUnknown_8102EF8
gUnknown_8102EF8: @ 8102EF8
	.incbin "baserom.gba", 0x102EF8, 0x38

	.global gUnknown_8102F30
gUnknown_8102F30: @ 8102F30
	.incbin "baserom.gba", 0x102F30, 0x34

	.global gUnknown_8102F64
gUnknown_8102F64: @ 8102F64
	.incbin "baserom.gba", 0x102F64, 0x20

	.global gUnknown_8102F84
gUnknown_8102F84: @ 8102F84
	.incbin "baserom.gba", 0x102F84, 0x28

	.global gUnknown_8102FAC
gUnknown_8102FAC: @ 8102FAC
	.incbin "baserom.gba", 0x102FAC, 0x18

	.global gUnknown_8102FC4
gUnknown_8102FC4: @ 8102FC4
	.incbin "baserom.gba", 0x102FC4, 0x14

	.global gUnknown_8102FD8
gUnknown_8102FD8: @ 8102FD8
	.incbin "baserom.gba", 0x102FD8, 0x7C

	.global gUnknown_8103054
gUnknown_8103054: @ 8103054
	.incbin "baserom.gba", 0x103054, 0x84

	.global gUnknown_81030D8
gUnknown_81030D8: @ 81030D8
	.incbin "baserom.gba", 0x1030D8, 0x38

	.global gUnknown_8103110
gUnknown_8103110: @ 8103110
	.incbin "baserom.gba", 0x103110, 0x30

	.global gUnknown_8103140
gUnknown_8103140: @ 8103140
	.incbin "baserom.gba", 0x103140, 0x48

	.global gUnknown_8103188
gUnknown_8103188: @ 8103188
	.incbin "baserom.gba", 0x103188, 0xA0

	.global gUnknown_8103228
gUnknown_8103228: @ 8103228
	.incbin "baserom.gba", 0x103228, 0xE8

	.global gUnknown_8103310
gUnknown_8103310: @ 8103310
	.incbin "baserom.gba", 0x103310, 0x30

	.global gUnknown_8103340
gUnknown_8103340: @ 8103340
	.incbin "baserom.gba", 0x103340, 0x60

	.global gUnknown_81033A0
gUnknown_81033A0: @ 81033A0
	.incbin "baserom.gba", 0x1033A0, 0xC

	.global gUnknown_81033AC
gUnknown_81033AC: @ 81033AC
	.incbin "baserom.gba", 0x1033AC, 0x90

	.global gUnknown_810343C
gUnknown_810343C: @ 810343C
	.incbin "baserom.gba", 0x10343C, 0x40

	.global gUnknown_810347C
gUnknown_810347C: @ 810347C
	.incbin "baserom.gba", 0x10347C, 0xC

	.global gUnknown_8103488
gUnknown_8103488: @ 8103488
	.incbin "baserom.gba", 0x103488, 0x78

	.global gUnknown_8103500
gUnknown_8103500: @ 8103500
	.incbin "baserom.gba", 0x103500, 0x2C

	.global gUnknown_810352C
gUnknown_810352C: @ 810352C
	.incbin "baserom.gba", 0x10352C, 0x4C

	.global gUnknown_8103578
gUnknown_8103578: @ 8103578
	.incbin "baserom.gba", 0x103578, 0x5C

	.global gUnknown_81035D4
gUnknown_81035D4: @ 81035D4
	.incbin "baserom.gba", 0x1035D4, 0x44

	.global gUnknown_8103618
gUnknown_8103618: @ 8103618
	.incbin "baserom.gba", 0x103618, 0x64

	.global gUnknown_810367C
gUnknown_810367C: @ 810367C
	.incbin "baserom.gba", 0x10367C, 0x14

	.global gUnknown_8103690
gUnknown_8103690: @ 8103690
	.incbin "baserom.gba", 0x103690, 0x38

	.global gUnknown_81036C8
gUnknown_81036C8: @ 81036C8
	.incbin "baserom.gba", 0x1036C8, 0xD8

	.global gUnknown_81037A0
gUnknown_81037A0: @ 81037A0
	.incbin "baserom.gba", 0x1037A0, 0x34

	.global gUnknown_81037D4
gUnknown_81037D4: @ 81037D4
	.incbin "baserom.gba", 0x1037D4, 0x4C

	.global gUnknown_8103820
gUnknown_8103820: @ 8103820
	.incbin "baserom.gba", 0x103820, 0x24

	.global gUnknown_8103844
gUnknown_8103844: @ 8103844
	.incbin "baserom.gba", 0x103844, 0x30

	.global gUnknown_8103874
gUnknown_8103874: @ 8103874
	.incbin "baserom.gba", 0x103874, 0x34

	.global gUnknown_81038A8
gUnknown_81038A8: @ 81038A8
	.incbin "baserom.gba", 0x1038A8, 0x50

	.global gUnknown_81038F8
gUnknown_81038F8: @ 81038F8
	.incbin "baserom.gba", 0x1038F8, 0xC

	.global gUnknown_8103904
gUnknown_8103904: @ 8103904
	.incbin "baserom.gba", 0x103904, 0x34

	.global gUnknown_8103938
gUnknown_8103938: @ 8103938
	.incbin "baserom.gba", 0x103938, 0x16C

	.global gUnknown_8103AA4
gUnknown_8103AA4: @ 8103AA4
	.incbin "baserom.gba", 0x103AA4, 0x40

	.global gUnknown_8103AE4
gUnknown_8103AE4: @ 8103AE4
	.incbin "baserom.gba", 0x103AE4, 0x4C

	.global gUnknown_8103B30
gUnknown_8103B30: @ 8103B30
	.incbin "baserom.gba", 0x103B30, 0x28

	.global gUnknown_8103B58
gUnknown_8103B58: @ 8103B58
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
	.string "#+There appears to be no one here.#P"
	.string "#+It~27s impossible to go farther.#W\n"
	.string "#+It~27s time to go back.\0"
	.align 2, 0

	.global gUnknown_8103EA4
gUnknown_8103EA4: @ 8103EA4
	.incbin "baserom.gba", 0x103EA4, 0x68

	.global gUnknown_8103F0C
gUnknown_8103F0C: @ 8103F0C
	.incbin "baserom.gba", 0x103F0C, 0x40

	.global gUnknown_8103F4C
gUnknown_8103F4C: @ 8103F4C
	.incbin "baserom.gba", 0x103F4C, 0x80

	.global gUnknown_8103FCC
gUnknown_8103FCC: @ 8103FCC
	.incbin "baserom.gba", 0x103FCC, 0x3C

	.global gUnknown_8104008
gUnknown_8104008: @ 8104008
	.incbin "baserom.gba", 0x104008, 0x3C

	.global gUnknown_8104044
gUnknown_8104044: @ 8104044
	.incbin "baserom.gba", 0x104044, 0xC

	.global gUnknown_8104050
gUnknown_8104050: @ 8104050
	.incbin "baserom.gba", 0x104050, 0x7C

	.global gUnknown_81040CC
gUnknown_81040CC: @ 81040CC
	.incbin "baserom.gba", 0x1040CC, 0x48

	.global gUnknown_8104114
gUnknown_8104114: @ 8104114
	.incbin "baserom.gba", 0x104114, 0x30

	.global gUnknown_8104144
gUnknown_8104144: @ 8104144
	.incbin "baserom.gba", 0x104144, 0xC

	.global gUnknown_8104150
gUnknown_8104150: @ 8104150
	.incbin "baserom.gba", 0x104150, 0x5C

	.global gUnknown_81041AC
gUnknown_81041AC: @ 81041AC
	.incbin "baserom.gba", 0x1041AC, 0x4C

	.global gUnknown_81041F8
gUnknown_81041F8: @ 81041F8
	.incbin "baserom.gba", 0x1041F8, 0x48

	.global gUnknown_8104240
gUnknown_8104240: @ 8104240
	.incbin "baserom.gba", 0x104240, 0x6C

	.global gUnknown_81042AC
gUnknown_81042AC: @ 81042AC
	.incbin "baserom.gba", 0x1042AC, 0xC

	.global gUnknown_81042B8
gUnknown_81042B8: @ 81042B8
	.incbin "baserom.gba", 0x1042B8, 0x58

	.global gUnknown_8104310
gUnknown_8104310: @ 8104310
	.incbin "baserom.gba", 0x104310, 0x8C

	.global gUnknown_810439C
gUnknown_810439C: @ 810439C
	.incbin "baserom.gba", 0x10439C, 0x24

	.global gUnknown_81043C0
gUnknown_81043C0: @ 81043C0
	.incbin "baserom.gba", 0x1043C0, 0x1C

	.global gUnknown_81043DC
gUnknown_81043DC: @ 81043DC
	.incbin "baserom.gba", 0x1043DC, 0x74

	.global gUnknown_8104450
gUnknown_8104450: @ 8104450
	.incbin "baserom.gba", 0x104450, 0x64

	.global gUnknown_81044B4
gUnknown_81044B4: @ 81044B4
	.incbin "baserom.gba", 0x1044B4, 0x5C

	.global gUnknown_8104510
gUnknown_8104510: @ 8104510
	.incbin "baserom.gba", 0x104510, 0x2C

	.global gUnknown_810453C
gUnknown_810453C: @ 810453C
	.incbin "baserom.gba", 0x10453C, 0x34

	.global gUnknown_8104570
gUnknown_8104570: @ 8104570
	.incbin "baserom.gba", 0x104570, 0x40

	.global gUnknown_81045B0
gUnknown_81045B0: @ 81045B0
	.incbin "baserom.gba", 0x1045B0, 0x48

	.global gUnknown_81045F8
gUnknown_81045F8: @ 81045F8
	.incbin "baserom.gba", 0x1045F8, 0x7C

	.global gUnknown_8104674
gUnknown_8104674: @ 8104674
	.incbin "baserom.gba", 0x104674, 0x2C

	.global gUnknown_81046A0
gUnknown_81046A0: @ 81046A0
	.incbin "baserom.gba", 0x1046A0, 0x2C

	.global gUnknown_81046CC
gUnknown_81046CC: @ 81046CC
	.incbin "baserom.gba", 0x1046CC, 0x78

	.global gUnknown_8104744
gUnknown_8104744: @ 8104744
	.incbin "baserom.gba", 0x104744, 0x28

	.global gUnknown_810476C
gUnknown_810476C: @ 810476C
	.incbin "baserom.gba", 0x10476C, 0xC

	.global gUnknown_8104778
gUnknown_8104778: @ 8104778
	.incbin "baserom.gba", 0x104778, 0xC

	.global gUnknown_8104784
gUnknown_8104784: @ 8104784
	.incbin "baserom.gba", 0x104784, 0xC

	.global gUnknown_8104790
gUnknown_8104790: @ 8104790
	.incbin "baserom.gba", 0x104790, 0x20

	.global gUnknown_81047B0
gUnknown_81047B0: @ 81047B0
	.incbin "baserom.gba", 0x1047B0, 0x9C

	.global gUnknown_810484C
gUnknown_810484C: @ 810484C
	.incbin "baserom.gba", 0x10484C, 0x3C

	.global gUnknown_8104888
gUnknown_8104888: @ 8104888
	.incbin "baserom.gba", 0x104888, 0x40

	.global gUnknown_81048C8
gUnknown_81048C8: @ 81048C8
	.incbin "baserom.gba", 0x1048C8, 0x4C

	.global gUnknown_8104914
gUnknown_8104914: @ 8104914
	.incbin "baserom.gba", 0x104914, 0x1C

	.global gUnknown_8104930
gUnknown_8104930: @ 8104930
	.incbin "baserom.gba", 0x104930, 0x50

	.global gUnknown_8104980
gUnknown_8104980: @ 8104980
	.incbin "baserom.gba", 0x104980, 0x18

	.global gUnknown_8104998
gUnknown_8104998: @ 8104998
	.incbin "baserom.gba", 0x104998, 0x3C

	.global gUnknown_81049D4
gUnknown_81049D4: @ 81049D4
	.incbin "baserom.gba", 0x1049D4, 0xAC

	.global gUnknown_8104A80
gUnknown_8104A80: @ 8104A80
	.incbin "baserom.gba", 0x104A80, 0x1C

	.global gUnknown_8104A9C
gUnknown_8104A9C: @ 8104A9C
	.incbin "baserom.gba", 0x104A9C, 0x2C

	.global gUnknown_8104AC8
gUnknown_8104AC8: @ 8104AC8
	.incbin "baserom.gba", 0x104AC8, 0xC

	.global gUnknown_8104AD4
gUnknown_8104AD4: @ 8104AD4
	.incbin "baserom.gba", 0x104AD4, 0x118

	.global gUnknown_8104BEC
gUnknown_8104BEC: @ 8104BEC
	.incbin "baserom.gba", 0x104BEC, 0x24

	.global gUnknown_8104C10
gUnknown_8104C10: @ 8104C10
	.incbin "baserom.gba", 0x104C10, 0x44

	.global gUnknown_8104C54
gUnknown_8104C54: @ 8104C54
	.incbin "baserom.gba", 0x104C54, 0x60

	.global gUnknown_8104CB4
gUnknown_8104CB4: @ 8104CB4
	.incbin "baserom.gba", 0x104CB4, 0x2C

	.global gUnknown_8104CE0
gUnknown_8104CE0: @ 8104CE0
	.incbin "baserom.gba", 0x104CE0, 0xC

	.global gUnknown_8104CEC
gUnknown_8104CEC: @ 8104CEC
	.incbin "baserom.gba", 0x104CEC, 0x74

	.global gUnknown_8104D60
gUnknown_8104D60: @ 8104D60
	.incbin "baserom.gba", 0x104D60, 0x7C

	.global gUnknown_8104DDC
gUnknown_8104DDC: @ 8104DDC
	.incbin "baserom.gba", 0x104DDC, 0x30

	.global gUnknown_8104E0C
gUnknown_8104E0C: @ 8104E0C
	.incbin "baserom.gba", 0x104E0C, 0x48

	.global gUnknown_8104E54
gUnknown_8104E54: @ 8104E54
	.incbin "baserom.gba", 0x104E54, 0xC

	.global gUnknown_8104E60
gUnknown_8104E60: @ 8104E60
	.incbin "baserom.gba", 0x104E60, 0x9C

	.global gUnknown_8104EFC
gUnknown_8104EFC: @ 8104EFC
	.incbin "baserom.gba", 0x104EFC, 0x34

	.global gUnknown_8104F30
gUnknown_8104F30: @ 8104F30
	.incbin "baserom.gba", 0x104F30, 0x34

	.global gUnknown_8104F64
gUnknown_8104F64: @ 8104F64
	.incbin "baserom.gba", 0x104F64, 0x64

	.global gUnknown_8104FC8
gUnknown_8104FC8: @ 8104FC8
	.incbin "baserom.gba", 0x104FC8, 0xC

	.global gUnknown_8104FD4
gUnknown_8104FD4: @ 8104FD4
	.incbin "baserom.gba", 0x104FD4, 0x54

	.global gUnknown_8105028
gUnknown_8105028: @ 8105028
	.incbin "baserom.gba", 0x105028, 0xC

	.global gUnknown_8105034
gUnknown_8105034: @ 8105034
	.incbin "baserom.gba", 0x105034, 0xC

	.global gUnknown_8105040
gUnknown_8105040: @ 8105040
	.incbin "baserom.gba", 0x105040, 0x74

	.global gUnknown_81050B4
gUnknown_81050B4: @ 81050B4
	.incbin "baserom.gba", 0x1050B4, 0x58

	.global gUnknown_810510C
gUnknown_810510C: @ 810510C
	.incbin "baserom.gba", 0x10510C, 0x70

	.global gUnknown_810517C
gUnknown_810517C: @ 810517C
	.incbin "baserom.gba", 0x10517C, 0x54

	.global gUnknown_81051D0
gUnknown_81051D0: @ 81051D0
	.incbin "baserom.gba", 0x1051D0, 0x74

	.global gUnknown_8105244
gUnknown_8105244: @ 8105244
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

	.global gUnknown_8105438
gUnknown_8105438: @ 8105438
	.incbin "baserom.gba", 0x105438, 0x68

	.global gUnknown_81054A0
gUnknown_81054A0: @ 81054A0
	.incbin "baserom.gba", 0x1054A0, 0x44

	.global gUnknown_81054E4
gUnknown_81054E4: @ 81054E4
	.incbin "baserom.gba", 0x1054E4, 0x28

	.global gUnknown_810550C
gUnknown_810550C: @ 810550C
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

	.global gUnknown_8105E14
gUnknown_8105E14: @ 8105E14
	.incbin "baserom.gba", 0x105E14, 0x74

@ Lugia Fight Dialogue

	.global gUnknown_8105E88
gUnknown_8105E88: @ 8105E88
	.incbin "baserom.gba", 0x105E88, 0x70

	.global gUnknown_8105EF8
gUnknown_8105EF8: @ 8105EF8
	.incbin "baserom.gba", 0x105EF8, 0x40

	.global gUnknown_8105F38
gUnknown_8105F38: @ 8105F38
	.incbin "baserom.gba", 0x105F38, 0x3C

	.global gUnknown_8105F74
gUnknown_8105F74: @ 8105F74
	.incbin "baserom.gba", 0x105F74, 0x2C

	.global gUnknown_8105FA0
gUnknown_8105FA0: @ 8105FA0
	.incbin "baserom.gba", 0x105FA0, 0x38

	.global gUnknown_8105FD8
gUnknown_8105FD8: @ 8105FD8
	.incbin "baserom.gba", 0x105FD8, 0x4C

	.global gUnknown_8106024
gUnknown_8106024: @ 8106024
	.incbin "baserom.gba", 0x106024, 0x44

@ Kyogre Fight Dialogue

	.global gUnknown_8106068
gUnknown_8106068: @ 8106068
	.incbin "baserom.gba", 0x106068, 0xC

	.global gUnknown_8106074
gUnknown_8106074: @ 8106074
	.incbin "baserom.gba", 0x106074, 0x48

	.global gUnknown_81060BC
gUnknown_81060BC: @ 81060BC
	.incbin "baserom.gba", 0x1060BC, 0x48

	.global gUnknown_8106104
gUnknown_8106104: @ 8106104
	.incbin "baserom.gba", 0x106104, 0x3C

	.global gUnknown_8106140
gUnknown_8106140: @ 8106140
	.incbin "baserom.gba", 0x106140, 0xD4

	.global gUnknown_8106214
gUnknown_8106214: @ 8106214
	.incbin "baserom.gba", 0x106214, 0x30

	.global gUnknown_8106244
gUnknown_8106244: @ 8106244
	.incbin "baserom.gba", 0x106244, 0x38

	.global gUnknown_810627C
gUnknown_810627C: @ 810627C
	.incbin "baserom.gba", 0x10627C, 0x2C

	.global gUnknown_81062A8
gUnknown_81062A8: @ 81062A8
	.incbin "baserom.gba", 0x1062A8, 0xC

	.global gUnknown_81062B4
gUnknown_81062B4: @ 81062B4
	.incbin "baserom.gba", 0x1062B4, 0x34

	.global gUnknown_81062E8
gUnknown_81062E8: @ 81062E8
	.incbin "baserom.gba", 0x1062E8, 0x80

	.global gUnknown_8106368
gUnknown_8106368: @ 8106368
	.incbin "baserom.gba", 0x106368, 0x28

	.global gUnknown_8106390
gUnknown_8106390: @ 8106390
	.incbin "baserom.gba", 0x106390, 0x34

	.global gUnknown_81063C4
gUnknown_81063C4: @ 81063C4
	.byte 0x04, 0x00, 0x00, 0x00
	.byte 0x00, 0x00, 0x00, 0x00
	.4byte gUnknown_8103E40

@ Dialogue for Purity Forest

	.global gUnknown_81063D0
gUnknown_81063D0: @ 81063D0
	.byte 0x04, 0x00, 0x00, 0x00
	.byte 0x00, 0x00, 0x00, 0x00
	.4byte gPurityForestSomeoneThereText

	.global gPurityForestSomeoneThereText
gPurityForestSomeoneThereText: @ 81063DC
	.string "#+Oh?#W\n"
	.string "#+There~27s someone there.\0"
	.align 2, 0

	.global gUnknown_8106400
gUnknown_8106400: @ 8106400
	.byte 0x04, 0x00, 0x00, 0x00
	.byte 0x00, 0x00, 0x00, 0x00
	.4byte gPurityForestCelebiIntroText

	.global gPurityForestCelebiIntroText
gPurityForestCelebiIntroText: @ 810640C
	.string "#+It~27s...#W\n"
	.string "#+The Time Travel Pokémon $m2!\0"
	.align 2, 0

	.global gUnknown_810643C
gUnknown_810643C: @ 810643C
	.byte 0x04, 0x00, 0x00, 0x00
	.byte 0x00, 0x00, 0x00, 0x00
	.4byte gPurityForestCelebiWantsToJoinText

	.global gPurityForestCelebiWantsToJoinText
gPurityForestCelebiWantsToJoinText: @ 8106448
	.string "#+$m2 wants to join the team.\0"
	.align 2, 0

	.global gUnknown_8106468
gUnknown_8106468: @ 8106468
	.byte 0x04, 0x00, 0x00, 0x00
	.byte 0x00, 0x00, 0x00, 0x00
	.4byte gPurityForestCelebiJoinedText

	.global gPurityForestCelebiJoinedText
gPurityForestCelebiJoinedText: @ 8106474
	.string "#+$m2 joined the team! \0"
	.align 2, 0

	.global gUnknown_810648C
gUnknown_810648C: @ 810648C
	.byte 0x04, 0x00, 0x00, 0x00
	.byte 0x00, 0x00, 0x00, 0x00
	.4byte gPurityForestCelebiVeryHappyText

	.global gPurityForestCelebiVeryHappyText
gPurityForestCelebiVeryHappyText: @ 8106498
	.string "#+$m3 appears to\n"
	.string "#+be very happy!\0"
	.align 2, 0

	.global gUnknown_81064BC
gUnknown_81064BC: @ 81064BC
	.byte 0x04, 0x00, 0x00, 0x00
	.byte 0x00, 0x00, 0x00, 0x00
	.4byte gPurityForestCelebiDelightedToJoinText

	.global gPurityForestCelebiDelightedToJoinText
gPurityForestCelebiDelightedToJoinText: @ 81064C8
	.string "#+It~27s delighted to have\n"
	.string "#+joined the rescue team!\0"
	.align 2, 0

	.global gUnknown_8106500
gUnknown_8106500: @ 8106500
	.byte 0x04, 0x00, 0x00, 0x00
	.byte 0x00, 0x00, 0x00, 0x00
	.4byte gPurityForestTurnedDownOfferText

	.global gPurityForestTurnedDownOfferText
gPurityForestTurnedDownOfferText: @ 810650C
	.string "#+$m0 turned down\n"
	.string "#+the offer to join.\0"
	.align 2, 0

	.global gUnknown_8106534
gUnknown_8106534: @ 8106534
	.byte 0x04, 0x00, 0x00, 0x00
	.byte 0x00, 0x00, 0x00, 0x00
	.4byte gPurityForestCelebiDisappointedText

	.global gPurityForestCelebiDisappointedText
gPurityForestCelebiDisappointedText: @ 8106540
	.string "#+Celebi is very disappointed.\0"
	.align 2, 0

	.global gUnknown_8106560
gUnknown_8106560: @ 8106560
	.byte 0x04, 0x00, 0x00, 0x00
	.byte 0x00, 0x00, 0x00, 0x00
	.4byte gPurityForestCelebiLeftDejectedlyText

	.global gPurityForestCelebiLeftDejectedlyText
gPurityForestCelebiLeftDejectedlyText: @ 810656C
	.string "#+$m2 left\n"
	.string "#+dejectedly...\0"
	.align 2, 0

	.global gPurityForestAllowCelebiToJoinText
gPurityForestAllowCelebiToJoinText: @ 8106588
	.string "#+Allow $m2\n"
	.string "#+to join the team?\0"
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
	.string "#+Are you sure?#W\n"
	.string "#+You~27re sure you won~27t accept it?\0"
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

	.global gUnknown_810663C
gUnknown_810663C: @ 810663C
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

	.global gUnknown_8106778
gUnknown_8106778: @ 8106778
	.incbin "baserom.gba", 0x106778, 0x44

	.global gUnknown_81067BC
gUnknown_81067BC: @ 81067BC
	.incbin "baserom.gba", 0x1067BC, 0x24

	.global gUnknown_81067E0
gUnknown_81067E0: @ 81067E0
	.incbin "baserom.gba", 0x1067E0, 0x54

	.global gUnknown_8106834
gUnknown_8106834: @ 8106834
	.incbin "baserom.gba", 0x106834, 0x58

	.global gUnknown_810688C
gUnknown_810688C: @ 810688C
	.incbin "baserom.gba", 0x10688C, 0x44

	.global gUnknown_81068D0
gUnknown_81068D0: @ 81068D0
	.incbin "baserom.gba", 0x1068D0, 0x48

	.global gUnknown_8106918
gUnknown_8106918: @ 8106918
	.incbin "baserom.gba", 0x106918, 0x1C

	.global gUnknown_8106934
gUnknown_8106934: @ 8106934
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

	.global gUnknown_81069F4
gUnknown_81069F4: @ 81069F4
	.incbin "baserom.gba", 0x1069F4, 0x28

	.global gUnknown_8106A1C
gUnknown_8106A1C: @ 8106A1C
	.incbin "baserom.gba", 0x106A1C, 0x30

	.global gUnknown_8106A4C
gUnknown_8106A4C: @ 8106A4C
	.incbin "baserom.gba", 0x106A4C, 0x4

	.global gUnknown_8106A50
gUnknown_8106A50: @ 8106A50
	.incbin "baserom.gba", 0x106A50, 0x4

	.global gUnknown_8106A54
gUnknown_8106A54: @ 8106A54
	.incbin "baserom.gba", 0x106A54, 0x38

	.global gUnknown_8106A8C
gUnknown_8106A8C: @ 8106A8C
	.incbin "baserom.gba", 0x106A8C, 0x3C

	.global gUnknown_8106AC8
gUnknown_8106AC8: @ 8106AC8
	.incbin "baserom.gba", 0x106AC8, 0x20

	.global gUnknown_8106AE8
gUnknown_8106AE8: @ 8106AE8
	.incbin "baserom.gba", 0x106AE8, 0x4

	.global gUnknown_8106AEC
gUnknown_8106AEC: @ 8106AEC
	.incbin "baserom.gba", 0x106AEC, 0x64

	.global gUnknown_8106B50
gUnknown_8106B50: @ 8106B50
        .string "#C%c%s\0"
        .align 2,0
        .string "pksdir0\0"
        .align 2,0

	.global gUnknown_8106B60
gUnknown_8106B60: @ 8106B60
	.incbin "baserom.gba", 0x106B60, 0xC

	.global gUnknown_8106B6C
gUnknown_8106B6C: @ 8106B6C
	.incbin "baserom.gba", 0x106B6C, 0x20

	.global gUnknown_8106B8C
gUnknown_8106B8C: @ 8106B8C
	.incbin "baserom.gba", 0x106B8C, 0x24

	.global gUnknown_8106BB0
gUnknown_8106BB0: @ 8106BB0
        .string "$t\0"
        .align 2,0

@ Red Heart Symbols
	.global gUnknown_8106BB4
gUnknown_8106BB4: @ 8106BB4
        .byte 0x87, 0x46, 0x00, 0x00

	.global gUnknown_8106BB8
gUnknown_8106BB8: @ 8106BB8
        .byte 0x87, 0x47, 0x00, 0x00

	.global gUnknown_8106BBC
gUnknown_8106BBC: @ 8106BBC
        .byte 0x87, 0x48, 0x00, 0x00

	.global gUnknown_8106BC0
gUnknown_8106BC0: @ 8106BC0
        .byte 0x87, 0x49, 0x00, 0x00

@ Yellow Heart Symbols
	.global gUnknown_8106BC4
gUnknown_8106BC4: @ 8106BC4
        .byte 0x87, 0x4A, 0x00, 0x00

	.global gUnknown_8106BC8
gUnknown_8106BC8: @ 8106BC8
        .byte 0x87, 0x4B, 0x00, 0x00

	.global gUnknown_8106BCC
gUnknown_8106BCC: @ 8106BCC
        .byte 0x87, 0x4C, 0x00, 0x00

	.global gUnknown_8106BD0
gUnknown_8106BD0: @ 8106BD0
        .byte 0x87, 0x4D, 0x00, 0x00

	.global gUnknown_8106BD4
gUnknown_8106BD4: @ 8106BD4
	.incbin "baserom.gba", 0x106BD4, 0xC

	.global gUnknown_8106BE0
gUnknown_8106BE0: @ 8106BE0
	.incbin "baserom.gba", 0x106BE0, 0xC

	.global gUnknown_8106BEC
gUnknown_8106BEC: @ 8106BEC
	.incbin "baserom.gba", 0x106BEC, 0x8

	.global gUnknown_8106BF4
gUnknown_8106BF4: @ 8106BF4
	.incbin "baserom.gba", 0x106BF4, 0xC

	.global gUnknown_8106C00
gUnknown_8106C00: @ 8106C00
	.incbin "baserom.gba", 0x106C00, 0x18

	.global gUnknown_8106C18
gUnknown_8106C18: @ 8106C18
	.incbin "baserom.gba", 0x106C18, 0x18

	.global gUnknown_8106C30
gUnknown_8106C30: @ 8106C30
	.incbin "baserom.gba", 0x106C30, 0x60

	.global gUnknown_8106C90
gUnknown_8106C90: @ 8106C90
        .string "????\0"
        .align 2,0

	.global gUnknown_8106C98
gUnknown_8106C98: @ 8106C98
        .string "$i0\0"
        .align 2,0

	.global gUnknown_8106C9C
gUnknown_8106C9C: @ 8106C9C
        .string "None\0"
        .align 2,0
        .string "pksdir0\0"
        .align 2,0

	.global gUnknown_8106CAC
gUnknown_8106CAC: @ 8106CAC
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x03, 0x00, 0x00, 0x00
        .byte 0x02, 0x00, 0x0E, 0x00
        .byte 0x1A, 0x00, 0x03, 0x00
        .byte 0x03, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00

	.global gUnknown_8106CC4
gUnknown_8106CC4: @ 8106CC4
        .string "$i0\0"
        .align 2,0

	.global gUnknown_8106CC8
gUnknown_8106CC8: @ 8106CC8
        .byte 0x01, 0x00, 0x10, 0x00

	.global gUnknown_8106CCC
gUnknown_8106CCC: @ 8106CCC
        .string "$m0\0"
        .align 2,0
        .string "pksdir0\0"
        .align 2,0
        .string "pksdir0\0"
        .align 2,0
        .string "pksdir0\0"
        .align 2,0

	.global gUnknown_8106CE8
gUnknown_8106CE8: @ 8106CE8
        .byte 0x10, 0x00, 0x00, 0x00
        .byte 0x19, 0x00, 0x00, 0x00
        .byte 0x1b, 0x00, 0x00, 0x00

	.global gUnknown_8106CF4
gUnknown_8106CF4: @ 8106CF4
        .byte 0x13, 0x00, 0x00, 0x00
        .byte 0x11, 0x00, 0x00, 0x00
        .byte 0x19, 0x00, 0x00, 0x00
        .string "pksdir0\0"
        .align 2,0

	.global gUnknown_8106D08
gUnknown_8106D08: @ 8106D08
	.incbin "baserom.gba", 0x106D08, 0x60

	.global gUnknown_8106D68
gUnknown_8106D68: @ 8106D68
	.incbin "baserom.gba", 0x106D68, 0x24

	.global gUnknown_8106D8C
gUnknown_8106D8C: @ 8106D8C
        .string "#c%d$m0\0"
        .align 2,0
        .string "pksdir0\0"
        .align 2,0
        .string "pksdir0\0"
        .align 2,0

	.global gUnknown_8106DA4
gUnknown_8106DA4: @ 8106DA4
	.incbin "baserom.gba", 0x106DA4, 0x24

	.global gUnknown_8106DC8
gUnknown_8106DC8: @ 8106DC8
	.incbin "baserom.gba", 0x106DC8, 0x60

	.global gUnknown_8106E28
gUnknown_8106E28: @ 8106E28
        .string "$m0\0"
        .align 2,0

	.global gUnknown_8106E2C
gUnknown_8106E2C: @ 8106E2C
        .byte 0x87, 0x42, 0x00, 0x00

	.global gUnknown_8106E30
gUnknown_8106E30: @ 8106E30
        .byte 0x87, 0x40, 0x00, 0x00

	.global gUnknown_8106E34
gUnknown_8106E34: @ 8106E34
        .string "$i0#c5$v02:$m0#r\0"
        .align 2,0

	.global gUnknown_8106E48
gUnknown_8106E48: @ 8106E48
        .string "$i0#c6$v02:$m0#r\0"
        .align 2,0

	.global gUnknown_8106E5C
gUnknown_8106E5C: @ 8106E5C
        .string "Press {B_BUTTON}\n"
        .string "if OK.\0"
        .align 2,0

	.global gUnknown_8106E6C
gUnknown_8106E6C: @ 8106E6C
        .string "Say bye to\n"
        .string "$d0 more\0"
        .align 2,0

	.global gUnknown_8106E80
gUnknown_8106E80: @ 8106E80
        .byte 0x02, 0x00, 0x00, 0x00
        .byte 0x03, 0x00, 0x00, 0x00
        .byte 0x04, 0x00, 0x00, 0x00
        .byte 0x05, 0x00, 0x00, 0x00
        .string "pksdir0\0"
        .align 2,0

	.global gUnknown_8106E98
gUnknown_8106E98: @ 8106E98
        .string "palet\0"
        .align 2,0

	.global gUnknown_8106EA0
gUnknown_8106EA0: @ 8106EA0
        .string "ax%03d\0"
        .align 2,0

	.global gUnknown_8106EA8
gUnknown_8106EA8: @ 8106EA8
        .string "talkp%d\0"
        .align 2,0

	.global gUnknown_8106EB0
gUnknown_8106EB0: @ 8106EB0
        .string "talk%d\0"
        .align 2,0
        .string "pksdir0\0"
        .align 2,0
        .string "pksdir0\0"
        .align 2,0

	.global gUnknown_8106EC8
gUnknown_8106EC8: @ 8106EC8
	.incbin "baserom.gba", 0x106EC8, 0x27

	.global gUnknown_8106EEF
gUnknown_8106EEF: @ 8106EEF
	.incbin "baserom.gba", 0x106EEF, 0xD

	.global gUnknown_8106EFC
gUnknown_8106EFC: @ 8106EFC
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00

	.global gUnknown_8106F04
gUnknown_8106F04: @ 8106F04
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x01, 0x00

	.global gUnknown_8106F0C
gUnknown_8106F0C: @ 8106F0C
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x02, 0x00

	.global gUnknown_8106F14
gUnknown_8106F14: @ 8106F14
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x80, 0x01, 0x00

	.global gUnknown_8106F1C
gUnknown_8106F1C: @ 8106F1C
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x80, 0x00, 0x00

	.global gUnknown_8106F24
gUnknown_8106F24: @ 8106F24
	.incbin "baserom.gba", 0x106F24, 0x30

	.global gUnknown_8106F54
gUnknown_8106F54: @ 8106F54
        .byte 0x3C, 0x6F, 0x10, 0x08
        .byte 0x44, 0x6F, 0x10, 0x08
        .4byte gUnknown_8106F04
        .byte 0x4C, 0x6F, 0x10, 0x08

	.global gUnknown_8106F64
gUnknown_8106F64: @ 8106F64
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0xC0, 0x00, 0x00

	.global gUnknown_8106F6C
gUnknown_8106F6C: @ 8106F6C
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x01, 0x00, 0x00, 0x00
        .byte 0x02, 0x00, 0x00, 0x00
        .byte 0x04, 0x00, 0x00, 0x00

	.global gUnknown_8106F7C
gUnknown_8106F7C: @ 8106F7C
	.incbin "baserom.gba", 0x106F7C, 0x28

	.global gUnknown_8106FA4
gUnknown_8106FA4: @ 8106FA4
@ replacing .incbin "baserom.gba", 0x00106fa4, 0x9
        .byte 0x23, 0x63, 0x25, 0x63, 0x25, 0x73, 0x23, 0x72, 0x00

	.global gUnknown_8106FAD
gUnknown_8106FAD: @ 8106FAD
@ replacing .incbin "baserom.gba", 0x00106fad, 0x8
        .byte 0x01, 0x02, 0x04, 0x08, 0x10, 0x20, 0x40, 0x80

	.global gUnknown_8106FB5
gUnknown_8106FB5: @ 8106FB5
@ replacing .incbin "baserom.gba", 0x00106fb5, 0x8
        .byte 0x01, 0x02, 0x04, 0x08, 0x10, 0x20, 0x40, 0x80

	.global gUnknown_8106FBD
gUnknown_8106FBD: @ 8106FBD
@ replacing .incbin "baserom.gba", 0x00106fbd, 0x8
        .byte 0x01, 0x02, 0x04, 0x08, 0x10, 0x20, 0x40, 0x80

	.global gUnknown_8106FC5
gUnknown_8106FC5: @ 8106FC5
@ replacing .incbin "baserom.gba", 0x00106fc5, 0x8
        .byte 0x01, 0x02, 0x04, 0x08, 0x10, 0x20, 0x40, 0x80

	.global gUnknown_8106FCD
gUnknown_8106FCD: @ 8106FCD
@ replacing .incbin "baserom.gba", 0x00106fcd, 0x8
        .byte 0x01, 0x02, 0x04, 0x08, 0x10, 0x20, 0x40, 0x80

	.global gUnknown_8106FD5
gUnknown_8106FD5: @ 8106FD5
@ replacing .incbin "baserom.gba", 0x00106fd5, 0x8
        .byte 0x01, 0x02, 0x04, 0x08, 0x10, 0x20, 0x40, 0x80

	.global gUnknown_8106FDD
gUnknown_8106FDD: @ 8106FDD
@ replacing .incbin "baserom.gba", 0x00106fdd, 0x8
        .byte 0x01, 0x02, 0x04, 0x08, 0x10, 0x20, 0x40, 0x80	

        .global gUnknown_8106FE5
gUnknown_8106FE5: @ 8106FE5
	.incbin "baserom.gba", 0x106FE5, 0x2B

	.global gUnknown_8107010
gUnknown_8107010: @ 8107010
	.incbin "baserom.gba", 0x107010, 0x8

	.global gUnknown_8107018
gUnknown_8107018: @ 8107018
	.incbin "baserom.gba", 0x107018, 0x160

	.global gUnknown_8107178
gUnknown_8107178: @ 8107178
	.incbin "baserom.gba", 0x107178, 0x5C

	.global gUnknown_81071D4
gUnknown_81071D4: @ 81071D4
	.incbin "baserom.gba", 0x1071D4, 0xC

	.global gUnknown_81071E0
gUnknown_81071E0: @ 81071E0
	.incbin "baserom.gba", 0x1071E0, 0x44

	.global gUnknown_8107224
gUnknown_8107224: @ 8107224
	.incbin "baserom.gba", 0x107224, 0x10

	.global gUnknown_8107234
gUnknown_8107234: @ 8107234
	.incbin "baserom.gba", 0x107234, 0xE0

	.global gUnknown_8107314
gUnknown_8107314: @ 8107314
	.incbin "baserom.gba", 0x107314, 0x44

	.global gUnknown_8107358
gUnknown_8107358: @ 8107358
	.incbin "baserom.gba", 0x107358, 0x1C

	.global gUnknown_8107374
gUnknown_8107374: @ 8107374
	.incbin "baserom.gba", 0x107374, 0xC

	.global gUnknown_8107380
gUnknown_8107380: @ 8107380
	.incbin "baserom.gba", 0x107380, 0x1C

	.global gUnknown_810739C
gUnknown_810739C: @ 810739C
	.incbin "baserom.gba", 0x10739C, 0x38

	.global gUnknown_81073D4
gUnknown_81073D4: @ 81073D4
	.incbin "baserom.gba", 0x1073D4, 0x38

	.global gUnknown_810740C
gUnknown_810740C: @ 810740C
	.incbin "baserom.gba", 0x10740C, 0x40

	.global gUnknown_810744C
gUnknown_810744C: @ 810744C
	.incbin "baserom.gba", 0x10744C, 0x18

	.global gUnknown_8107464
gUnknown_8107464: @ 8107464
	.incbin "baserom.gba", 0x107464, 0x98

	.global gUnknown_81074FC
gUnknown_81074FC: @ 81074FC
	.incbin "baserom.gba", 0x1074FC, 0x48

	.global gUnknown_8107544
gUnknown_8107544: @ 8107544
	.incbin "baserom.gba", 0x107544, 0xB0

	.global gUnknown_81075F4
gUnknown_81075F4: @ 81075F4
        .string "monspara\0"
        .align 2,0

	.global gUnknown_8107600
gUnknown_8107600: @ 8107600
        .string "#c"
        .byte 0x06
        .string "%s#r"
        .align 2,0

	.global gUnknown_8107608
gUnknown_8107608: @ 8107608
        .string "#c"
        .byte 0x05
        .string "%s#r"
        .align 2,0

	.global gUnownLetters
gUnownLetters: @ 8107610
        .string "ABCDEFGHIJKLMNOPQRSTUVWXYZ!?\0"
        .align 2,0

	.global gUnknown_8107630
gUnknown_8107630: @ 8107630
        .string "%s%c\0"
        .align 2,0

	.global gUnknown_8107638
gUnknown_8107638: @ 8107638
        .string "%s\0"
        .align 2,0

	.global gUnknown_810763C
gUnknown_810763C: @ 810763C
        .string "#c%c%s#r\0"

	.global gUnknown_8107645
gUnknown_8107645: @ 8107645
	.incbin "baserom.gba", 0x107645, 0xF

	.global gUnknown_8107654
gUnknown_8107654: @ 8107654
	.incbin "baserom.gba", 0x107654, 0x30

	.global gUnknown_8107684
gUnknown_8107684: @ 8107684
        .string "kao%03d\0"
        .align 2,0

	.global gUnknown_810768C
gUnknown_810768C: @ 810768C
        .string "lvmp%03d\0"
        .align 2,0

	.global gUnknown_8107698
gUnknown_8107698: @ 8107698
	.incbin "baserom.gba", 0x107698, 0x24

	.global gUnknown_81076BC
gUnknown_81076BC: @ 81076BC
        .string "etcfont\0"
        .align 2,0

	.global gUnknown_81076C4
gUnknown_81076C4: @ 81076C4
	.incbin "baserom.gba", 0x1076C4, 0x20

	.global gUnknown_81076E4
gUnknown_81076E4: @ 81076E4
	.incbin "baserom.gba", 0x1076E4, 0x70

	.global gUnknown_8107754
gUnknown_8107754: @ 8107754
        .string "Stats\0"
        .align 2,0

	.global gUnknown_810775C
gUnknown_810775C: @ 810775C
        .string "Features\0"
        .align 2,0

	.global gUnknown_8107768
gUnknown_8107768: @ 8107768
        .string "Type:\0"
        .align 2,0

	.global gUnknown_8107770
gUnknown_8107770: @ 8107770
        .string "Special Abilities:\0"
        .align 2,0

	.global gUnknown_8107784
gUnknown_8107784: @ 8107784
        .string "$i1\0"
        .align 2,0

	.global gUnknown_8107788
gUnknown_8107788: @ 8107788
        .byte 0x87, 0x42, 0x00, 0x00

	.global gUnknown_810778C
gUnknown_810778C: @ 810778C
        .byte 0x87, 0x40, 0x00, 0x00

	.global gUnknown_8107790
gUnknown_8107790: @ 8107790
        .string "$i0$i1\0"
        .align 2,0

	.global gUnknown_8107798
gUnknown_8107798: @ 8107798
        .string "Info\0"
        .align 2,0
        .string "pksdir0\0"
        .align 2,0

	.global gUnknown_81077A8
gUnknown_81077A8: @ 81077A8
	.incbin "baserom.gba", 0x1077A8, 0x40

	.global gUnknown_81077E8
gUnknown_81077E8: @ 81077E8
	.incbin "baserom.gba", 0x1077E8, 0x40

	.global gUnknown_8107828
gUnknown_8107828: @ 8107828
	.incbin "baserom.gba", 0x107828, 0x85C

	.global gUnknown_8108084
gUnknown_8108084: @ 8108084
	.incbin "baserom.gba", 0x108084, 0xDD4

	.global gUnknown_8108E58
gUnknown_8108E58: @ 8108E58
@ replacing .incbin "baserom.gba", 0x00108e58, 0x68
        .4byte 0x8108184
        .4byte 0x810819c
        .4byte 0x81081ea
        .4byte 0x8108274
        .4byte 0x8108302
        .4byte 0x810838e
        .4byte 0x8108432
        .4byte 0x81084d6
        .4byte 0x810857e
        .4byte 0x810862c
        .4byte 0x81086c8
        .4byte 0x8108766
        .4byte 0x8108804
        .4byte 0x81088a2
        .4byte 0x810893e
        .4byte 0x81089da
        .4byte 0x8108a10
        .4byte 0x8108a6e
        .4byte 0x8108ab4
        .4byte 0x8108b16
        .4byte 0x8108b5c
        .4byte 0x8108bc0
        .4byte 0x8108c12
        .4byte 0x8108c92
        .4byte 0x8108d18
        .4byte 0x8108e36

	.global gUnknown_8108EC0
gUnknown_8108EC0: @ 8108EC0
	.incbin "baserom.gba", 0x108EC0, 0x50

	.global gUnknown_8108F10
gUnknown_8108F10: @ 8108F10
        .asciz "#cD%s#r"
        .align 2,0

	.global gUnknown_8108F18
gUnknown_8108F18: @ 8108F18
        .string "#cD%s#r"
        .byte 0x81, 0x40
        .asciz "#c5%d#rF"
        .align 2,0

	.global gUnknown_8108F2C
gUnknown_8108F2C: @ 8108F2C
        .string "#cD%s#r"
        .byte 0x81, 0x40
        .asciz "B#c5%d#rF"
        .align 2,0

	.global gUnknown_8108F40
gUnknown_8108F40: @ 8108F40
        .byte 0x00, 0x00

	.global gUnknown_8108F42
gUnknown_8108F42: @ 8108F42
	.incbin "baserom.gba", 0x108F42, 0x8

	.global gUnknown_8108F4A
gUnknown_8108F4A: @ 8108F4A
	.incbin "baserom.gba", 0x108F4A, 0x6

	.global gUnknown_8108F50
gUnknown_8108F50: @ 8108F50
        .string "No problem.\0"
        .align 2,0
        .string "pksdir0\0"
        .align 2,0

	.global gUnknown_8108F64
gUnknown_8108F64: @ 8108F64
	.incbin "baserom.gba", 0x108F64, 0x800

	.global gUnknown_8109764
gUnknown_8109764: @ 8109764
        .string "itempara\0"
        .align 2,0

	.global gUnknown_8109770
gUnknown_8109770: @ 8109770
        .string "%s %d\0"
        .align 2,0

	.global gUnknown_8109778
gUnknown_8109778: @ 8109778
        .string "%s\0"
        .align 2,0

	.global gUnknown_810977C
gUnknown_810977C: @ 810977C
	.incbin "baserom.gba", 0x10977C, 0x8

	.global gUnknown_8109784
gUnknown_8109784: @ 8109784
	.incbin "baserom.gba", 0x109784, 0x8

	.global gUnknown_810978C
gUnknown_810978C: @ 810978C
	.incbin "baserom.gba", 0x10978C, 0x8

	.global gUnknown_8109794
gUnknown_8109794: @ 8109794
	.incbin "baserom.gba", 0x109794, 0x10

	.global gUnknown_81097A4
gUnknown_81097A4: @ 81097A4
	.incbin "baserom.gba", 0x1097A4, 0xC

	.global gUnknown_81097B0
gUnknown_81097B0: @ 81097B0
	.incbin "baserom.gba", 0x1097B0, 0x14

	.global gUnknown_81097C4
gUnknown_81097C4: @ 81097C4
        .byte 0x83

	.global gUnknown_81097C5
gUnknown_81097C5: @ 81097C5
        @ replacing .incbin "baserom.gba", 0x001097c5, 0x1b
        .byte 0x9f, 0x83, 0xa0, 0x83, 0xa1, 0x83, 0xa2, 0x83, 0xa3, 0x83, 0xa4, 0x83, 0xa5, 0x83, 0xa6, 0x83, 0xa7, 0x83, 0xa8, 0x00, 0x00, 0x00, 0x00, 0xc4, 0x97, 0x10, 0x08

	.global gUnknown_81097E0
gUnknown_81097E0: @ 81097E0
        @ replacing .incbin "baserom.gba", 0x001097e0, 0x8
        .byte 0x01, 0x00
        .byte 0x02, 0x00
        .byte 0x04, 0x00
        .byte 0x08, 0x00

	.global gUnknown_81097E8
gUnknown_81097E8: @ 81097E8
        @ replacing .incbin "baserom.gba", 0x001097e8, 0x10
        .byte 0x10, 0x00, 0x00, 0x00
        .byte 0x12, 0x00, 0x00, 0x00
        .byte 0x14, 0x00, 0x00, 0x00
        .byte 0x16, 0x00, 0x00, 0x00

	.global gUnknown_81097F8
gUnknown_81097F8: @ 81097F8
        @ replacing .incbin "baserom.gba", 0x001097f8, 0x18
        .byte 0x11, 0x00, 0x00, 0x00
        .byte 0x13, 0x00, 0x00, 0x00
        .byte 0x15, 0x00, 0x00, 0x00
        .byte 0x17, 0x00, 0x00, 0x00
        .string "pksdir0\0"


	.global gRescueRankMaxPoints
gRescueRankMaxPoints: @ 8109810
        @ replacing .incbin "baserom.gba", 0x00109810, 0x1c
        .4byte 50
        .4byte 500
        .4byte 1500
        .4byte 3000
        .4byte 7500
        .4byte 15000
        .4byte 100000000

	.global gTeamNamePlaceholder
gTeamNamePlaceholder: @ 810982C
        @ replacing .incbin "baserom.gba", 0x0010982c, 0x10
        .byte 0x50, 0x6f, 0x6b, 0xe9, 0x6d, 0x6f, 0x6e, 0x00
        .string "pksdir0\0"

	.global gUnknown_810983C
gUnknown_810983C: @ 810983C
	.incbin "baserom.gba", 0x10983C, 0x68

	.global gUnknown_81098A4
gUnknown_81098A4: @ 81098A4
	.string "#c"
        .byte 0x4
        .string "%s#r\0"
        .align 2,0

	.global gUnknown_81098AC
gUnknown_81098AC: @ 81098AC
        .string "%s#=%c#C"
        .byte 0x4
        .string "%s#R\0"
        .align 2,0
        .string "pksdir0"
        .align 2,0

	.global gUnknown_81098C4
gUnknown_81098C4: @ 81098C4
        .byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00

	.global gUnknown_81098D0
gUnknown_81098D0: @ 81098D0
        .string "wazapara\0"
        .align 2,0

	.global gUnknown_81098DC
gUnknown_81098DC: @ 81098DC
        .string "%+d\0"

	.global gUnknown_81098E0
gUnknown_81098E0: @ 81098E0
        .string "#c%c%s%s#r\0"
        .align 2,0

	.global gUnknown_81098EC
gUnknown_81098EC: @ 81098EC
        .string "#c%c#:%s%s%s#;%c%2d/%2d#r\0"
        .align 2,0

	.global gUnknown_8109908
gUnknown_8109908: @ 8109908
        .byte 0x87, 0x41, 0x00, 0x00 @ apparently shows A in memory viewer 

	.global gUnknown_810990C
gUnknown_810990C: @ 810990C
        .byte 0x87, 0x40, 0x00, 0x00 @ apparently shows @ in memory viewer 

	.global gUnknown_8109910
gUnknown_8109910: @ 8109910
        .string "#c%c%s%s%s#=%c%2d/%2d#r\0"
        .align 2,0

	.global gUnknown_8109928
gUnknown_8109928: @ 8109928
        .byte 0x87, 0x42, 0x00 @ apparently shows B in memory viewer

	.global gUnknown_810992B
gUnknown_810992B: @ 810992B
        .byte 0x00

	.global gUnknown_810992C
gUnknown_810992C: @ 810992C
        .string "%s\0"
        .align 2,0

	.global gUnknown_8109930
gUnknown_8109930: @ 8109930
        .string "$m0\0"
        .align 2,0
        .string "pksdir0\0"
        .align 2,0
        .string "pksdir0\0"
        .align 2,0
        .string "pksdir0\0"
        .align 2,0
        .string "pksdir0\0"
        .align 2,0

	.global gUnknown_8109954
gUnknown_8109954: @ 8109954
        .byte 0x20, 0x48, 0x68, 0x00
        .byte 0x80, 0x38, 0x20, 0x00
        .byte 0x28, 0x80, 0x48, 0x00
        .byte 0x28, 0x80, 0x48, 0x00
        .string "pksdir0\0"
        .align 2,0
        .string "pksdir0\0"
        .align 2,0
        .string "pksdir0\0"
        .align 2,0
        .string "pksdir0\0"
        .align 2,0

	.global gUnknown_8109984
gUnknown_8109984: @ 8109984
        .byte 0x00, 0x01, 0x02, 0x03, 0x04, 0x02, 0x01, 0x00
        .string "pksdir0\0"
        .align 2,0

	.global gStoryMissionText
gStoryMissionText: @ 8109994
	.incbin "baserom.gba", 0x109994, 0x314

	.global gDummyScenarioText
gDummyScenarioText: @ 8109CA8
        .string "#CCScenario try dummy#R\0"
        .align 2,0

	.global gUnknown_8109CC0
gUnknown_8109CC0: @ 8109CC0
        .string "#CW???#R\0"
        .align 2,0
        .string "pksdir0\0"

	.global gMeetNinetalesText
gMeetNinetalesText: @ 8109CD4
        .string "Meet Ninetales.\0"
        .align 2,0

	.global gAvoidCaptureText
gAvoidCaptureText: @ 8109CE4
        .string "Avoid capture.\0"
        .align 2,0

	.global gFinalScenarioText
gFinalScenarioText: @ 8109CF4
	.incbin "baserom.gba", 0x109CF4, 0x3C

	.global gDungeons
gDungeons: @ 8109D30
	.incbin "baserom.gba", 0x109D30, 0x620

	.global gUnknown_810A350
gUnknown_810A350: @ 810A350
        @ replacing .incbin "baserom.gba", 0x0010a350, 0xb
        .byte 0x18, 0x19, 0x1e, 0x27, 0x31, 0x32, 0x33, 0x36, 0x37, 0x3d, 0x3f

	.global gUnknown_810A35B
gUnknown_810A35B: @ 810A35B
        @ replacing .incbin "baserom.gba", 0x0010a35b, 0x10
        .byte 0xed, 0xee, 0xef, 0xb1, 0xe9, 0x24, 0xd8, 0xd2, 0xb0, 0xdc, 0x32, 0x33, 0x34, 0xc2, 0xec, 0xf0

	.global gUnknown_810A36B
gUnknown_810A36B: @ 810A36B
        @ replacing .incbin "baserom.gba", 0x0010a36b, 0xd
        .byte 0x01
        .byte 0x00
        .byte 0x00
        .byte 0x00
        .byte 0x01
        .byte 0x01
        .byte 0x01
        .byte 0x01
        .byte 0x01
        .byte 0x00
        .byte 0x01
        .byte 0x00
        .byte 0x00

	.global gUnknown_810A378
gUnknown_810A378: @ 810A378
        @ replacing .incbin "baserom.gba", 0x0010a378, 0x18
        .byte 0x01, 0x00
        .byte 0x19, 0x00
        .byte 0x01, 0x00
        .byte 0x01, 0x00
        .byte 0xe7, 0x03
        .byte 0xe7, 0x03
        .byte 0x23, 0x00
        .byte 0x28, 0x00
        .byte 0x14, 0x00
        .byte 0x0f, 0x00
        .byte 0x0a, 0x00
        .byte 0xe7, 0x03

	.global gUnknown_810A390
gUnknown_810A390: @ 810A390
	.incbin "baserom.gba", 0x10A390, 0x60

	.global gUnknown_810A3F0
gUnknown_810A3F0: @ 810A3F0 (money related according to PMDe)
	.incbin "baserom.gba", 0x10A3F0, 0x190

	.global gUnknown_810A580
gUnknown_810A580: @ 810A580
	.incbin "baserom.gba", 0x10A580, 0x288

	.global gUnknown_810A808
gUnknown_810A808: @ 810A808
	.incbin "baserom.gba", 0x10A808, 0x288
