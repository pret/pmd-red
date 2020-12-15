	.section .rodata

	.string "pksdir0\0"
        .align 2,0

	.global gByteShiftLookup
gByteShiftLookup: @ 80B9BB8
        .4byte 0
        .4byte 8
        .4byte 16
        .4byte 24

        .string "pksdir0\0"
        .string "pksdir0\0"
        .string "PKD ROM USER DATA 000000\0"

	.global gUnknown_80B9BF1
gUnknown_80B9BF1: @ 80B9BF1
        .byte 0x36, 0x27, 0x46, 0x01
        .byte 0xB9, 0x48, 0x00
        .string "pksdir0\0"

	.global gUnknown_80B9C00
gUnknown_80B9C00: @ 80B9C00
	.incbin "baserom.gba", 0xB9C00, 0x60

	.global gUnknown_80B9C60
gUnknown_80B9C60: @ 80B9C60
        .byte 0xFF, 0xFF, 0xFF, 0xFF
        .byte 0xFF, 0xFF, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00

gUnknown_80B9C6C:: @ 80B9C6C
        .string "efob001\0"
        .align 2,0

gUnknown_80B9C74:: @ 80B9C74
        .string "efob000\0"
        .align 2,0

	.global gUnknown_80B9C7C
gUnknown_80B9C7C: @ 80B9C7C
        .byte 0xc0, 0xff, 0x0a, 0x00, 0xb8, 0xff, 0xe4, 0xff, 0xc4, 0xff, 0x32, 0x00, 0xbf, 0xff, 0xc4, 0xff, 0xb0, 0xff, 0x18, 0x00, 0xb0, 0xff, 0x46, 0x00, 0x9c, 0xff, 0x20, 0x00, 0x88, 0xff, 0xd0, 0xff

	.global gUnknown_80B9C9C
gUnknown_80B9C9C: @ 80B9C9C
        .byte 0x01, 0x00, 0x00, 0x00
        .byte 0x01, 0x00, 0x00, 0x00
        .byte 0x01, 0x00, 0x00, 0x00
        .byte 0xff, 0xff, 0xff, 0xff
        .byte 0xff, 0xff, 0xff, 0xff
        .byte 0xff, 0xff, 0xff, 0xff
        .byte 0x01, 0x00, 0x00, 0x00
        .byte 0x01, 0x00, 0x00, 0x00
        .string "pksdir0\0"
        .align 2,0

	.global gUnknown_80B9CC4
gUnknown_80B9CC4: @ 80B9CC4
	.incbin "baserom.gba", 0xB9CC4, 0x3F00

	.global gUnknown_80BDBC4
gUnknown_80BDBC4: @ 80BDBC4
	.incbin "baserom.gba", 0xBDBC4, 0x3C78

	.global gUnknown_80C183C
gUnknown_80C183C: @ 80C183C
	.incbin "baserom.gba", 0xC183C, 0xCB40

	.global gUnknown_80CE37C
gUnknown_80CE37C: @ 80CE37C
	.incbin "baserom.gba", 0xCE37C, 0x3C0

	.global gUnknown_80CE73C
gUnknown_80CE73C: @ 80CE73C
        .byte 0x00, 0x00
        .byte 0x82, 0x01
        .byte 0xb3, 0x01
        .byte 0x84, 0x01
        .byte 0x83, 0x01
        .byte 0x00, 0x00
        .byte 0x00, 0x00
        .byte 0x85, 0x01
        .byte 0x86, 0x01
        .byte 0x87, 0x01
        .byte 0x40, 0x01
        .byte 0x9a, 0x00
        .byte 0x88, 0x01
        .byte 0x00, 0x00
        .byte 0x00, 0x00
        .byte 0xb0, 0x01
        .byte 0x89, 0x01
        .byte 0x00, 0x00
        .byte 0xd2, 0x00
        .byte 0x00, 0x00
        .string "pksdir0\0"
        .string "pksdir0\0"
        .string "pksdir0\0"
        .align 2,0

	.global gUnknown_80CE77C
gUnknown_80CE77C: @ 80CE77C
        .string "efob%03d\0"
        .align 2,0

	.global gUnknown_80CE788
gUnknown_80CE788: @ 80CE788
        .string "efbg%03d\0"
        .align 2,0
        .string "pksdir0\0"

@ Status Conditions Graphics

	.global gUnknown_80CE79C
gUnknown_80CE79C: @ 80CE79C
	.incbin "baserom.gba", 0xCE79C, 0x198

	.global gUnknown_80CE934
gUnknown_80CE934: @ 80CE934
	.incbin "baserom.gba", 0xCE934, 0x4B40

	.global gUnknown_80D3474
gUnknown_80D3474: @ 80D3474
	.incbin "baserom.gba", 0xD3474, 0xF0

        .global gUnknown_80D3564
gUnknown_80D3564: @ 80D3564
        .byte 0,0,0,0
        .string "pksdir0\0"
        .align 2,0

@ Friend Area Data

	.global gFriendAreaLocations
gFriendAreaLocations: @ 80D3570
@ replacing .incbin "baserom.gba", 0x000d3570, 0x94c
        .byte 0xac, 0x3e, 0x0d, 0x08, 0xc5, 0x01, 0x71, 0x00, 0x08, 0x09, 0x0a, 0x27, 0x2f, 0x0b, 0x3f, 0x3f, 0x05, 0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x0c, 0x00, 0x02, 0x00, 0x07, 0x00 @ Mountain Range
        .byte 0xa4, 0x3e, 0x0d, 0x08, 0xcd, 0x01, 0x1c, 0x00, 0x30, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x0a, 0x00, 0x0c, 0x00
        .byte 0x9c, 0x3e, 0x0d, 0x08, 0x61, 0x01, 0x78, 0x00, 0x0d, 0x0e, 0x11, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x1b, 0x00, 0x07, 0x00, 0x00, 0x00, 0x0c, 0x00, 0x0d, 0x00, 0xff, 0xff, 0x09, 0x00, 0xff, 0xff
        .byte 0x8c, 0x3e, 0x0d, 0x08, 0x62, 0x01, 0x2d, 0x01, 0x0f, 0x0c, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x04, 0x00, 0x0e, 0x00, 0x12, 0x00, 0xff, 0xff, 0xff, 0xff
        .byte 0x80, 0x3e, 0x0d, 0x08, 0x94, 0x01, 0x02, 0x01, 0x34, 0x35, 0x28, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0xff, 0xff, 0x11, 0x00, 0xff, 0xff, 0x0b, 0x00, 0x08, 0x00, 0xff, 0xff, 0x0e, 0x00, 0x03, 0x00
        .byte 0x70, 0x3e, 0x0d, 0x08, 0xc7, 0x01, 0x9d, 0x00, 0x12, 0x13, 0x14, 0x15, 0x3f, 0x3f, 0x3f, 0x3f, 0x0b, 0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0xff, 0xff, 0x07, 0x00, 0x08, 0x00
        .byte 0x60, 0x3e, 0x0d, 0x08, 0x08, 0x01, 0x9d, 0x00, 0x16, 0x17, 0x18, 0x19, 0x3f, 0x3f, 0x3f, 0x3f, 0x10, 0x00, 0xff, 0xff, 0x1b, 0x00, 0x09, 0x00, 0x14, 0x00, 0x1a, 0x00, 0xff, 0xff, 0xff, 0xff
        .byte 0x58, 0x3e, 0x0d, 0x08, 0x97, 0x01, 0xa0, 0x00, 0x1a, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x08, 0x00, 0x0b, 0x00, 0x05, 0x00, 0x00, 0x00, 0x0c, 0x00, 0x02, 0x00, 0x1b, 0x00, 0xff, 0xff
        .byte 0x48, 0x3e, 0x0d, 0x08, 0x98, 0x01, 0xcf, 0x00, 0x1b, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x04, 0x00, 0xff, 0xff, 0x0b, 0x00, 0x05, 0x00, 0x07, 0x00, 0x1b, 0x00, 0xff, 0xff, 0x0e, 0x00
        .byte 0x40, 0x3e, 0x0d, 0x08, 0x33, 0x01, 0x79, 0x00, 0x1c, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0xff, 0xff, 0x1b, 0x00, 0x02, 0x00, 0x0d, 0x00, 0x0f, 0x00, 0x14, 0x00, 0xff, 0xff, 0x06, 0x00
        .byte 0x30, 0x3e, 0x0d, 0x08, 0x82, 0x01, 0x1d, 0x00, 0x1d, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0xff, 0xff, 0x0c, 0x00, 0x01, 0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x0f, 0x00, 0x0d, 0x00
        .byte 0x20, 0x3e, 0x0d, 0x08, 0xc6, 0x01, 0xd0, 0x00, 0x1e, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x05, 0x00, 0x07, 0x00, 0x08, 0x00, 0x04, 0x00
        .byte 0x18, 0x3e, 0x0d, 0x08, 0xa2, 0x01, 0x46, 0x00, 0x1f, 0x20, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x07, 0x00, 0x00, 0x00, 0xff, 0xff, 0x01, 0x00, 0xff, 0xff, 0x0a, 0x00, 0x0d, 0x00, 0x02, 0x00
        .byte 0x10, 0x3e, 0x0d, 0x08, 0x60, 0x01, 0x47, 0x00, 0x21, 0x23, 0x24, 0x22, 0x3f, 0x3f, 0x3f, 0x3f, 0x02, 0x00, 0xff, 0xff, 0x0c, 0x00, 0x0a, 0x00, 0xff, 0xff, 0x0f, 0x00, 0x14, 0x00, 0x09, 0x00
        .byte 0x08, 0x3e, 0x0d, 0x08, 0x63, 0x01, 0x04, 0x01, 0x25, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x03, 0x00, 0xff, 0xff, 0x04, 0x00, 0x08, 0x00, 0x1b, 0x00, 0xff, 0xff, 0x12, 0x00, 0xff, 0xff
        .byte 0x00, 0x3e, 0x0d, 0x08, 0x36, 0x01, 0x1c, 0x00, 0x26, 0x29, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x09, 0x00, 0x0d, 0x00, 0x0a, 0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x18, 0x00, 0x14, 0x00
        .byte 0xf8, 0x3d, 0x0d, 0x08, 0x07, 0x01, 0xcb, 0x00, 0x10, 0x2a, 0x32, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0xff, 0xff, 0x12, 0x00, 0xff, 0xff, 0x1b, 0x00, 0x06, 0x00, 0xff, 0xff, 0xff, 0xff, 0x19, 0x00
        .byte 0xf0, 0x3d, 0x0d, 0x08, 0xc4, 0x01, 0x2d, 0x01, 0x2b, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x04, 0x00, 0xff, 0xff, 0xff, 0xff
        .byte 0xe8, 0x3d, 0x0d, 0x08, 0x31, 0x01, 0x05, 0x01, 0x2e, 0x2c, 0x2d, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0xff, 0xff, 0x03, 0x00, 0x0e, 0x00, 0xff, 0xff, 0xff, 0xff, 0x10, 0x00, 0x19, 0x00, 0xff, 0xff
        .byte 0xe4, 0x3d, 0x0d, 0x08, 0x2f, 0x00, 0x15, 0x00, 0x33, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x17, 0x00, 0x1a, 0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff
        .byte 0xd4, 0x3d, 0x0d, 0x08, 0x07, 0x01, 0x47, 0x00, 0x36, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x06, 0x00, 0x09, 0x00, 0x0d, 0x00, 0x0f, 0x00, 0xff, 0xff, 0x18, 0x00, 0xff, 0xff, 0xff, 0xff
        .byte 0xc4, 0x3d, 0x0d, 0x08, 0x5d, 0x00, 0x0c, 0x01, 0x37, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0xff, 0xff, 0xff, 0xff, 0x19, 0x00, 0xff, 0xff, 0xff, 0xff, 0x16, 0x00, 0xff, 0xff, 0xff, 0xff
        .byte 0xb4, 0x3d, 0x0d, 0x08, 0x2d, 0x00, 0xcb, 0x00, 0x38, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0xff, 0xff, 0x15, 0x00, 0xff, 0xff, 0xff, 0xff, 0x17, 0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff
        .byte 0xa4, 0x3d, 0x0d, 0x08, 0x2d, 0x00, 0x70, 0x00, 0x39, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x16, 0x00, 0xff, 0xff, 0xff, 0xff, 0x1a, 0x00, 0x13, 0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff
        .byte 0x94, 0x3d, 0x0d, 0x08, 0xd0, 0x00, 0x16, 0x00, 0x01, 0x03, 0x05, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0xff, 0xff, 0x14, 0x00, 0x0f, 0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x1a, 0x00
        .byte 0x84, 0x3d, 0x0d, 0x08, 0xb2, 0x00, 0x0d, 0x01, 0x02, 0x04, 0x06, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0xff, 0xff, 0xff, 0xff, 0x12, 0x00, 0x10, 0x00, 0xff, 0xff, 0xff, 0xff, 0x15, 0x00, 0xff, 0xff
        .byte 0x7c, 0x3d, 0x0d, 0x08, 0x81, 0x00, 0x42, 0x00, 0x07, 0x31, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0xff, 0xff, 0x06, 0x00, 0xff, 0xff, 0x18, 0x00, 0xff, 0xff, 0x13, 0x00, 0xff, 0xff, 0x17, 0x00 @ Beach
        .byte 0x78, 0x3d, 0x0d, 0x08, 0x63, 0x01, 0xa1, 0x00, 0x00, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x0e, 0x00, 0x08, 0x00, 0x07, 0x00, 0xff, 0xff, 0x02, 0x00, 0x09, 0x00, 0x06, 0x00, 0x10, 0x00 @ Team Name
        .byte 0x70, 0x3d, 0x0d, 0x08, 0x00, 0x00, 0x00, 0x00, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff
        .byte 0x70, 0x3d, 0x0d, 0x08, 0x00, 0x00, 0x00, 0x00, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff
        .byte 0x70, 0x3d, 0x0d, 0x08, 0x00, 0x00, 0x00, 0x00, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff
        .byte 0x70, 0x3d, 0x0d, 0x08, 0x00, 0x00, 0x00, 0x00, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff
        .byte 0x70, 0x3d, 0x0d, 0x08, 0x00, 0x00, 0x00, 0x00, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff
        .byte 0x70, 0x3d, 0x0d, 0x08, 0x00, 0x00, 0x00, 0x00, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff
        .byte 0x70, 0x3d, 0x0d, 0x08, 0x00, 0x00, 0x00, 0x00, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff
        .byte 0x70, 0x3d, 0x0d, 0x08, 0x00, 0x00, 0x00, 0x00, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff
        .byte 0x70, 0x3d, 0x0d, 0x08, 0x00, 0x00, 0x00, 0x00, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff
        .byte 0x70, 0x3d, 0x0d, 0x08, 0x00, 0x00, 0x00, 0x00, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff
        .byte 0x70, 0x3d, 0x0d, 0x08, 0x00, 0x00, 0x00, 0x00, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff
        .byte 0x70, 0x3d, 0x0d, 0x08, 0x00, 0x00, 0x00, 0x00, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff
        .byte 0x70, 0x3d, 0x0d, 0x08, 0x00, 0x00, 0x00, 0x00, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff
        .byte 0x70, 0x3d, 0x0d, 0x08, 0x00, 0x00, 0x00, 0x00, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff
        .byte 0x70, 0x3d, 0x0d, 0x08, 0x00, 0x00, 0x00, 0x00, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff
        .byte 0x70, 0x3d, 0x0d, 0x08, 0x00, 0x00, 0x00, 0x00, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff
        .byte 0x70, 0x3d, 0x0d, 0x08, 0x00, 0x00, 0x00, 0x00, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff
        .byte 0x70, 0x3d, 0x0d, 0x08, 0x00, 0x00, 0x00, 0x00, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff
        .byte 0x70, 0x3d, 0x0d, 0x08, 0x00, 0x00, 0x00, 0x00, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff
        .byte 0x70, 0x3d, 0x0d, 0x08, 0x00, 0x00, 0x00, 0x00, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff
        .byte 0x70, 0x3d, 0x0d, 0x08, 0x00, 0x00, 0x00, 0x00, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff
        .byte 0x70, 0x3d, 0x0d, 0x08, 0x00, 0x00, 0x00, 0x00, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff
        .byte 0x70, 0x3d, 0x0d, 0x08, 0x00, 0x00, 0x00, 0x00, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff
        .byte 0x70, 0x3d, 0x0d, 0x08, 0x00, 0x00, 0x00, 0x00, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff
        .byte 0x70, 0x3d, 0x0d, 0x08, 0x00, 0x00, 0x00, 0x00, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff
        .byte 0x70, 0x3d, 0x0d, 0x08, 0x00, 0x00, 0x00, 0x00, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff
        .byte 0x70, 0x3d, 0x0d, 0x08, 0x00, 0x00, 0x00, 0x00, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff
        .byte 0x70, 0x3d, 0x0d, 0x08, 0x00, 0x00, 0x00, 0x00, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff
        .byte 0x70, 0x3d, 0x0d, 0x08, 0x00, 0x00, 0x00, 0x00, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff
        .byte 0x70, 0x3d, 0x0d, 0x08, 0x00, 0x00, 0x00, 0x00, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff
        .byte 0x70, 0x3d, 0x0d, 0x08, 0x00, 0x00, 0x00, 0x00, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff
        .byte 0x70, 0x3d, 0x0d, 0x08, 0x00, 0x00, 0x00, 0x00, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff
        .byte 0x70, 0x3d, 0x0d, 0x08, 0x00, 0x00, 0x00, 0x00, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff
        .byte 0x70, 0x3d, 0x0d, 0x08, 0x00, 0x00, 0x00, 0x00, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff
        .byte 0x70, 0x3d, 0x0d, 0x08, 0x00, 0x00, 0x00, 0x00, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff
        .byte 0x70, 0x3d, 0x0d, 0x08, 0x00, 0x00, 0x00, 0x00, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff
        @ Start of Friend Area String Pool (80D3D70)
        @ These are what show on the map when going to Friend Areas
        .string "ななし\0"
        .align 2,0
        .string "$t\0" @ Team Name
        .align 2,0
        .string "Beach\0"
        .align 2,0
        .string "Southern Sea\0"
        .align 2,0
        .string "Northern Sea\0"
        .align 2,0
        .string "Western Isles\0"
        .align 2,0
        .string "Southwest Isles\0"
        .align 2,0
        .string "Southern Isles\0"
        .align 2,0
        .string "Northern Isles\0"
        .align 2,0
        .string "Sky\0"
        .align 2,0
        .string "Relics\0"
        .align 2,0
        .string "Desert\0"
        .align 2,0
        .string "Volcano\0"
        .align 2,0
        .string "Ruins\0"
        .align 2,0
        .string "Jungle\0"
        .align 2,0
        .string "Cave\0"
        .align 2,0
        .string "Marsh\0"
        .align 2,0
        .string "Eastern Lakes\0"
        .align 2,0
        .string "Northern Lakes\0"
        .align 2,0
        .string "Pond\0"
        .align 2,0
        .string "Eastern Ponds\0"
        .align 2,0
        .string "River\0"
        .align 2,0
        .string "Western Forest\0"
        .align 2,0
        .string "Eastern Forest\0"
        .align 2,0
        .string "Badlands\0"
        .align 2,0
        .string "South Plains\0"
        .align 2,0
        .string "Plains\0"
        .align 2,0
        .string "Glacier\0"
        .align 2,0
        .string "Mountain Range\0"
        .align 2,0

	.global gUnknown_80D3EBC
gUnknown_80D3EBC: @ 80D3EBC
@ replacing .incbin "baserom.gba", 0x000d3ebc, 0x20
        .byte 0x80, 0x03
        .byte 0x80, 0x04
        .byte 0x80, 0x00
        .byte 0x80, 0x03
        .byte 0x80, 0x0f
        .byte 0x80, 0x00
        .byte 0x80, 0x0c
        .byte 0x80, 0x0f
        .byte 0x80, 0x0b
        .byte 0x80, 0x0c
        .byte 0x80, 0x08
        .byte 0x80, 0x0b
        .byte 0x80, 0x07
        .byte 0x80, 0x08
        .byte 0x80, 0x04
        .byte 0x80, 0x07

	.global gUnknown_80D3EDC
gUnknown_80D3EDC: @ 80D3EDC
        .byte 0xff, 0x00, 0x02, 0x01
        .byte 0x04, 0xff, 0x03, 0xff
        .byte 0x06, 0x07, 0xff, 0xff
        .byte 0x05, 0xff, 0xff, 0xff


	.global gUnknown_80D3EEC
gUnknown_80D3EEC: @ 80D3EEC
        .byte 0xff, 0xff, 0xff, 0x01
        .byte 0xff, 0xff, 0x03, 0xff
        .byte 0xff, 0x07, 0xff, 0xff
        .byte 0x05, 0xff, 0xff, 0xff

	.global gUnknown_80D3EFC
gUnknown_80D3EFC: @ 80D3EFC
        .byte 0x24, 0x74, 0x20, 0x54
        .byte 0x65, 0x61, 0x6d, 0x20
        .byte 0x42, 0x61, 0x73, 0x65
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x70, 0x6b, 0x73, 0x64
        .byte 0x69, 0x72, 0x30, 0x00

	.global gDungeonCoordinates
gDungeonCoordinates: @ 80D3F14
@ replacing .incbin "baserom.gba", 0x000d3f14, 0x100
@ 2 byte X and 2 byte Y
        .byte 0xac, 0x00, 0xae, 0x00 @ Tiny Woods
        .byte 0xab, 0x00, 0x6f, 0x00
        .byte 0xf2, 0x00, 0x7e, 0x00
        .byte 0xe8, 0x00, 0xb5, 0x00
        .byte 0x07, 0x01, 0x9b, 0x00
        .byte 0x2a, 0x01, 0x9f, 0x00
        .byte 0x2b, 0x01, 0x8e, 0x00
        .byte 0xcb, 0x00, 0xff, 0x00
        .byte 0x81, 0x01, 0xa6, 0x00
        .byte 0x84, 0x01, 0x7e, 0x00
        .byte 0x85, 0x01, 0x6d, 0x00
        .byte 0xa1, 0x01, 0x70, 0x00
        .byte 0xa6, 0x01, 0x65, 0x00
        .byte 0xb0, 0x01, 0x55, 0x00
        .byte 0xb4, 0x01, 0x45, 0x00
        .byte 0xba, 0x01, 0x96, 0x00
        .byte 0xbe, 0x01, 0xa3, 0x00
        .byte 0x6d, 0x01, 0x1b, 0x00
        .byte 0x60, 0x01, 0x0c, 0x00
        .byte 0x85, 0x00, 0xee, 0x00
        .byte 0x81, 0x00, 0x8f, 0x00
        .byte 0x58, 0x01, 0x69, 0x00
        .byte 0xab, 0x01, 0x3e, 0x00
        .byte 0x1b, 0x00, 0xd3, 0x00
        .byte 0xf6, 0x00, 0x3b, 0x01
        .byte 0xbb, 0x01, 0x06, 0x00
        .byte 0x20, 0x00, 0x17, 0x01
        .byte 0x94, 0x01, 0x06, 0x01
        .byte 0xc2, 0x00, 0x3f, 0x00
        .byte 0x9f, 0x00, 0x2e, 0x00
        .byte 0xb9, 0x01, 0x36, 0x01
        .byte 0xe7, 0x00, 0xeb, 0x00
        .byte 0xa9, 0x00, 0x1f, 0x01
        .byte 0xb9, 0x01, 0x11, 0x01
        .byte 0x40, 0x00, 0x57, 0x00
        .byte 0x50, 0x00, 0x36, 0x00
        .byte 0xaf, 0x01, 0xe1, 0x00
        .byte 0x1b, 0x00, 0x5e, 0x00
        .byte 0x62, 0x01, 0x2a, 0x01
        .byte 0x50, 0x01, 0xfd, 0x00
        .byte 0x1f, 0x01, 0xde, 0x00
        .byte 0x3f, 0x00, 0xa3, 0x00
        .byte 0x13, 0x01, 0x6f, 0x00
        .byte 0xca, 0x00, 0xe8, 0x00
        .byte 0x0c, 0x01, 0x2e, 0x01
        .byte 0x50, 0x01, 0x04, 0x01
        .byte 0x6e, 0x00, 0x4f, 0x00
        .byte 0xe1, 0x00, 0x3a, 0x01
        .byte 0xce, 0x00, 0x3a, 0x01
        .byte 0x0b, 0x00, 0x33, 0x01
        .byte 0xd8, 0x01, 0x19, 0x00
        .byte 0xfa, 0x00, 0x08, 0x00
        .byte 0xbb, 0x00, 0xbe, 0x00
        .byte 0xcd, 0x00, 0x6f, 0x00
        .byte 0xda, 0x01, 0x06, 0x00
        .byte 0xb7, 0x00, 0x09, 0x00
        .byte 0x6f, 0x01, 0xd6, 0x00
        .byte 0x16, 0x01, 0x11, 0x01
        .byte 0x44, 0x00, 0x31, 0x01
        .byte 0x0e, 0x01, 0x21, 0x00
        .byte 0x21, 0x00, 0x27, 0x00
        .byte 0xd9, 0x00, 0x08, 0x00
        .byte 0x45, 0x00, 0x18, 0x01
        .byte 0xc0, 0x00, 0xb7, 0x00 @ D63

	.global gUnknown_80D4014
gUnknown_80D4014: @ 80D4014
        .byte 0x50, 0x40, 0x0D, 0x08
        .byte 0x48, 0x40, 0x0D, 0x08
        .byte 0x3C, 0x40, 0x0D, 0x08
        .byte 0x34, 0x40, 0x0D, 0x08
        .byte 0x28, 0x40, 0x0D, 0x08
        .string "wmp2fon1\0"
        .align 2,0
        .string "wmp2pal\0"
        .align 2,0
        .string "wmp2cani\0"
        .align 2,0
        .string "wmp2mcc\0"
        .align 2,0
        .string "wmp2font\0"
        .align 2,0

	.global gUnknown_80D405C
gUnknown_80D405C: @ 80D405C
        .string "ax%03d\0"
        .align 2,0

	.global gUnknown_80D4064
gUnknown_80D4064: @ 80D4064
        .string "wmapspr\0"
        .align 2,0

	.global gUnknown_80D406C
gUnknown_80D406C: @ 80D406C
        .string "palet\0"
        .align 2,0

	.global gUnknown_80D4074
gUnknown_80D4074: @ 80D4074
        .string "#+$m0\0"
        .align 2,0

	.global gUnknown_80D407C
gUnknown_80D407C: @ 80D4074
        .string "Yes\0"
        .align 2,0

	.global gUnknown_80D4080
gUnknown_80D4080: @ 80D4080
        .string "No\0"
        .align 2,0
        .string "pksdir0\0"
        .align 2,0

	.global gUnknown_80D408C
gUnknown_80D408C: @ 80D408C
	.incbin "baserom.gba", 0xD408C, 0x38

	.global gUnknown_80D40C4
gUnknown_80D40C4: @ 80D40C4
        .byte 0x00, 0x00, 0x18, 0x00
        .byte 0x18, 0x00, 0x18, 0x00
        .byte 0x18, 0x00, 0x00, 0x00
        .byte 0x18, 0x00, 0xE8, 0xFF
        .byte 0x00, 0x00, 0xE8, 0xFF
        .byte 0xE8, 0xFF, 0xE8, 0xFF
        .byte 0xE8, 0xFF, 0x00, 0x00
        .byte 0xE8, 0xFF, 0x18, 0x00

	.global gUnknown_80D40E4
gUnknown_80D40E4: @ 80D40E4
        .string "ax%03d\0"
        .align 2,0

	.global gUnknown_80D40EC
gUnknown_80D40EC: @ 80D40EC
        .string "wmapspr\0"
        .align 2,0

	.global gUnknown_80D40F4
gUnknown_80D40F4: @ 80D40F4
        .string "palet\0"
        .align 2,0

	.global gUnknown_80D40FC
gUnknown_80D40FC: @ 80D40FC
        .string "#+%s\0"
        .align 2,0

	.global gUnknown_80D4104
gUnknown_80D4104: @ 80D4104
	.string "Where would you like to go?\0"
        .align 2,0

	.global gUnknown_80D4120
gUnknown_80D4120: @ 80D4120
	.string "$i0\0"
        .align 2,0

	.global gUnknown_80D4124
gUnknown_80D4124: @ 80D4124
	.incbin "baserom.gba", 0xD4124, 0x20

@ Error Handling
	.global gUnknown_80D4144
gUnknown_80D4144: @ 80D4144
        .byte 0x2e, 0x01
        .byte 0x2f, 0x01
        .byte 0x2f, 0x01
        .byte 0x2d, 0x01
        .byte 0x30, 0x01
        .byte 0x32, 0x01
        .byte 0x33, 0x01
        .byte 0x00, 0x00
        .string "pksdir0\0"
        .string "pksdir0\0"
        .byte 0x70, 0x41, 0x0d, 0x08 @ Pointer to none
        .byte 0xff, 0xff, 0xff, 0xff
        .byte 0x70, 0x41, 0x0d, 0x08 @ Pointer to none
        .string "none\0"
        .align 2,0
        .byte 0x84, 0x41, 0x0d, 0x08 @ Pointer to default
        .byte 0xff, 0xff, 0xff, 0xff
        .byte 0x70, 0x41, 0x0d, 0x08 @ Pointer to none
        .string "default\0"

	.global gUnknown_80D418C
gUnknown_80D418C: @ 80D418C
        .string "func = '%s'\n"
        .string "file = '%s'  line = %5d\0"

	.global gNotEntryText
gNotEntryText: @ 80D41B0
        .string "--- not entry ---\0"
        .align 2,0

	.global gUnknown_80D41C4
gUnknown_80D41C4: @ 80D41C4
        .string "%sfunc = '%s'\n"
        .string "file = '%s'  line = %5d\n\0"
        .align 2,0

	.global gUnknown_80D41EC
gUnknown_80D41EC: @ 80D41EC
        .string "func = '%s'\n"
        .string "file = '%s'  line = %5d\n\0"
        .align 2,0
        .string "pksdir0\0"

	.global gUnknown_80D421C
gUnknown_80D421C: @ 80D421C
        .string "  Print  \0"
        .align 2,0
        .string "pksdir0\0"
        .align 2,0
        .string "Performance\0"
        .align 2,0
        .string "Memory Card\0"
        .align 2,0
        .string "Memory\0"
        .align 2,0
        .string "Flag\0"
        .align 2,0
        .string "Se\0"
        .align 2,0
        .string "Bgm\0"
        .align 2,0
        .string "Sound\0"
        .align 2,0
        .string "Dungeon\0"
        .align 2,0
        .string "GroundScript\0"
        .align 2,0
        .string "Ground\0"
        .align 2,0

	.global gNotMountText
gNotMountText: @ 80D4288
        .string "not mount log system\0"
        .align 2,0
        .string "pksdir0\0"
        .string "pksdir0\0"
        .string "pksdir0\0"
        .string "pksdir0\0"

	.global gFatalText
gFatalText: @ 80D42C0
        .string "!!!!! Fatal !!!!!\n\0"
        .align 2,0

	.global gUnknown_80D42D4
gUnknown_80D42D4: @ 80D42D4
	.string "%s\n\0"
        .align 2,0
        .string "pksdir0\0"
        .string "pksdir0\0"
        .string "pksdir0\0"
        .string "pksdir0\0"
        .string "pksdir0\0"
        .string "pksdir0\0"
        .string "pksdir0\0"
        .string "pksdir0\0"
        .string "pksdir0\0"
        .string "POKE_DUNGEON__05\0"
        .align 2,0
        .string "pksdir0\0"
        .string "pksdir0\0"
        .string "pksdir0\0"
        .string "pksdir0\0"

	.global gUnknown_80D4354
gUnknown_80D4354: @ 80D4354
        .string "#+The game data is corrupted.\n"
        .string "#+Your data will be erased.\0"
        .align 2,0
        .string "pksdir0\0"

	.global gUnknown_80D4398
gUnknown_80D4398: @ 80D4398
        .string "#+Saving your adventure...\n"
        .string "#+Please don~27t turn off the power.\0"
        .align 2,0

	.global gUnknown_80D43D8
gUnknown_80D43D8: @ 80D43D8
        .string "#+Writing to GBA Game Pak.\n"
        .string "#+Do not remove the GBA Game Pak.\n"
        .string "#+Please wait with the power on.\0"
        .align 2,0

	.global gUnknown_80D4438
gUnknown_80D4438: @ 80D4438
        .string "#+Save completed!\0"
        .align 2,0

	.global gUnknown_80D444C
gUnknown_80D444C: @ 80D444C
        .string "#+The data could not be written.\n"
        .string "#+Please turn off the power and remove\n"
        .string "#+and reinsert the DS Card.\0"
        .align 2,0

	.global gUnknown_80D44B0
gUnknown_80D44B0: @ 80D44B0
        .string "#+Save failed.\0"
        .align 2,0
        .string "pksdir0\0"

	.global gUnknown_80D44C8
gUnknown_80D44C8: @ 80D44C8
	.incbin "baserom.gba", 0xD44C8, 0xE4

	.global gUnknown_80D45AC
gUnknown_80D45AC: @ 80D45AC
        .string "#+Quicksaving your adventure...\n"
        .string "#+Please don~27t turn off the power.\0"
        .align 2,0

	.global gUnknown_80D45F4
gUnknown_80D45F4: @ 80D45F4
	.incbin "baserom.gba", 0xD45F4, 0x74

	.global gUnknown_80D4668
gUnknown_80D4668: @ 80D4668
	.incbin "baserom.gba", 0xD4668, 0xD4

	.global gUnknown_80D473C
gUnknown_80D473C: @ 80D473C
	.incbin "baserom.gba", 0xD473C, 0x64

	.global gUnknown_80D47A0
gUnknown_80D47A0: @ 80D47A0
        .string "#+Save failed.\0"
        .align 2,0
        .string "pksdir0\0"

	.global gUnknown_80D47B8
gUnknown_80D47B8: @ 80D47B8
        .byte 0x07, 0x00, 0x00, 0x00
        .byte 0x02, 0x00, 0x00, 0x00
        .byte 0x02, 0x00, 0x00, 0x00
        .byte 0x01, 0x00, 0x10, 0x00

	.global gUnknown_80D47C8
gUnknown_80D47C8: @ 80D47C8
	.incbin "baserom.gba", 0xD47C8, 0x60

	.global gUnknown_80D4828
gUnknown_80D4828: @ 80D4828
        .string "#C%c%s\0"
        .align 2,0

	.global gUnknown_80D4830
gUnknown_80D4830: @ 80D4830
	.incbin "baserom.gba", 0xD4830, 0x2C

	.global gUnknown_80D485C
gUnknown_80D485C: @ 80D485C
        .byte 0x78, 0x48, 0x0D, 0x08
        .byte 0x01, 0x00, 0x00, 0x00
        .byte 0x74, 0x48, 0x0D, 0x08
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0xFF, 0xFF, 0xFF, 0xFF
        .string "No\0"
        .align 2,0
        .string "*Yes\0"
        .align 2,0

	.global gUnknown_80D4880
gUnknown_80D4880: @ 80D4880
        .byte 0x9C, 0x48, 0x0D, 0x08 @ Pointer to Yes
        .byte 0x01, 0x00, 0x00, 0x00
        .byte 0x98, 0x48, 0x0D, 0x08 @ Pointer to No
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00 @ End of table
        .byte 0xFF, 0xFF, 0xFF, 0xFF
        .string "*No\0"
        .string "Yes\0"
        .align 2,0

	.global gUnknown_80D48A0
gUnknown_80D48A0: @ 80D48A0
        .byte 0x07, 0x00, 0x00, 0x00
        .byte 0x02, 0x00, 0x00, 0x00
        .byte 0x02, 0x00, 0x00, 0x00

	.global gUnknown_80D48AC
gUnknown_80D48AC: @ 80D48AC
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x03, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00

	.global gUnknown_80D48C4
gUnknown_80D48C4: @ 80D48C4
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x02, 0x00, 0x0f, 0x00
        .byte 0x1a, 0x00, 0x05, 0x00
        .byte 0x07, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00

	.global gUnknown_80D48DC
gUnknown_80D48DC: @ 80D48DC
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x02, 0x00, 0x00, 0x00
        .byte 0x02, 0x00, 0x08, 0x00
        .byte 0x1a, 0x00, 0x05, 0x00
        .byte 0x07, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00

	.global gUnknown_80D48F4
gUnknown_80D48F4: @ 80D48F4
        .byte 0x3A, 0x20, 0x00, 0x00 @ maybe just a colon and space

	.global gUnknown_80D48F8
gUnknown_80D48F8: @ 80D48F8
        .byte 0x3F, 0x3F, 0x3F, 0x3F @ apparently 4 ?'s
        .byte 0x00, 0x00, 0x00, 0x00

	.global gUnknown_80D4900
gUnknown_80D4900: @ 80D4900
        .string "%d\0"
        .align 2,0

	.global gUnknown_80D4904
gUnknown_80D4904: @ 80D4904
        .string "%*d\0"
        .align 2,0

	.global gUnknown_80D4908
gUnknown_80D4908: @ 80D4908
        .string "%0*d\0"
        .align 2,0

	.global gUnknown_80D4910
gUnknown_80D4910: @ 80D4910
        .string "$\0"
        .align 2,0
        .string "pksdir0\0"
        .string "Yes\0"

	.global gUnknown_80D4920
gUnknown_80D4920: @ 80D4920
        .byte 0x1C, 0x49, 0x0D, 0x08 @ Pointer to Yes
        .string "No\0"
        .align 2,0

	.global gUnknown_80D4928
gUnknown_80D4928: @ 80D4928
        .byte 0x24, 0x49, 0x0D, 0x08 @ Pointer to No
        .string "Cancel\0"
        .align 2,0

	.global gUnknown_80D4934
gUnknown_80D4934: @ 80D4934
        .byte 0x2C, 0x49, 0x0D, 0x08 @ Pointer to Cancel
        .string "Trash \0"
        .align 2,0

	.global gUnknown_80D4940
gUnknown_80D4940: @ 80D4940
        .byte 0x38, 0x49, 0x0D, 0x08
        .string "Delete\0"
        .align 2,0

	.global gUnknown_80D494C
gUnknown_80D494C: @ 80D494C
        .byte 0x44, 0x49, 0x0D, 0x08
        .string "Store\0"
        .align 2,0

	.global gUnknown_80D4958
gUnknown_80D4958: @ 80D4958
        .byte 0x50, 0x49, 0x0D, 0x08
        .string "Take\0"
        .align 2,0

	.global gUnknown_80D4964
gUnknown_80D4964: @ 80D4964
        .byte 0x5C, 0x49, 0x0D, 0x08 @ Pointer to Take
        .string "Info\0"
        .align 2,0

	.global gUnknown_80D4970
gUnknown_80D4970: @ 80D4970
        .byte 0x68, 0x49, 0x0D, 0x08 @ Pointer to Info
        .string "Buy\0"
        .align 2,0

	.global gUnknown_80D4978
gUnknown_80D4978: @ 80D4978
        .byte 0x74, 0x49, 0x0D, 0x08 @ Pointer to Buy
        .string "Sell \0"
        .align 2,0

	.global gUnknown_80D4984
gUnknown_80D4984: @ 80D4984
        .byte 0x7C, 0x49, 0x0D, 0x08 @ Pointer to Sell
        .string "Accept\0"
        .align 2,0

	.global gUnknown_80D4990
gUnknown_80D4990: @ 80D4990
        .byte 0x88, 0x49, 0x0D, 0x08 @ Pointer to Accept
        .string "Check\0"
        .align 2,0

	.global gUnknown_80D499C
gUnknown_80D499C: @ 80D499C
        .byte 0x94, 0x49, 0x0D, 0x08 @ Pointer to Check
        .string "Friend\0"
        .align 2,0

	.global gUnknown_80D49A8
gUnknown_80D49A8: @ 80D49A8
        .byte 0xA0, 0x49, 0x0D, 0x08 @ Pointer to Friend
        .string "Exit\0"
        .align 2,0

	.global gUnknown_80D49B4
gUnknown_80D49B4: @ 80D49B4
        .byte 0xAC, 0x49, 0x0D, 0x08 @ Poiner to Exit
        .string "???\0"
        .align 2,0

	.global gUnknown_80D49BC
gUnknown_80D49BC: @ 80D49BC
        .byte 0xB8, 0x49, 0x0D, 0x08 @ Pointer to the question marks above
        .string "Deposit?\0"
        .align 2,0

	.global gUnknown_80D49CC
gUnknown_80D49CC: @ 80D49CC
        .byte 0xC0, 0x49, 0x0D, 0x08 @ Pointer to Deposit
        .string "Withdraw?\0"
        .align 2,0

	.global gUnknown_80D49DC
gUnknown_80D49DC: @ 80D49DC
        .byte 0xD0, 0x49, 0x0D, 0x08 @ Pointer to Withdraw

	.global gUnknown_80D49E0
gUnknown_80D49E0: @ 80D49E0 (Felicity Bank Dialogue)
	.incbin "baserom.gba", 0xD49E0, 0xA24

	.global gUnknown_80D5404
gUnknown_80D5404: @ 80D5404
	.incbin "baserom.gba", 0xD5404, 0xAC4

	.global gUnknown_80D5EC8
gUnknown_80D5EC8: @ 80D5EC8 (Kecleon Wares Dialogue)
	.incbin "baserom.gba", 0xD5EC8, 0x1ADC

	.global gUnknown_80D79A4
gUnknown_80D79A4: @ 80D79A4 (Friend Area Shop)
	.incbin "baserom.gba", 0xD79A4, 0xEE4

	.global gUnknown_80D8888
gUnknown_80D8888: @ 80D8888 (Gulpin Link Shop)
	.incbin "baserom.gba", 0xD8888, 0x1740

	.global gUnknown_80D9FC8
gUnknown_80D9FC8: @ 80D9FC8 (Makuhita Dojo)
	.incbin "baserom.gba", 0xD9FC8, 0xAD0

	.global gUnknown_80DAA98
gUnknown_80DAA98: @ 80DAA98 (Help Menu?)
	.incbin "baserom.gba", 0xDAA98, 0x4D8

	.global gUnknown_80DAF70
gUnknown_80DAF70: @ 80DAF70
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x03, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00

	.global gUnknown_80DAF88
gUnknown_80DAF88: @ 80DAF88
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x03, 0x00, 0x00, 0x00
        .byte 0x02, 0x00, 0x02, 0x00
        .byte 0x1a, 0x00, 0x0c, 0x00
        .byte 0x0c, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00

	.global gUnknown_80DAFA0
gUnknown_80DAFA0: @ 80DAFA0
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x03, 0x00, 0x00, 0x00
        .byte 0x16, 0x00, 0x0f, 0x00
        .byte 0x06, 0x00, 0x03, 0x00
        .byte 0x03, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .string "pksdir0\0"
        .align 2,0

	.global gUnknown_80DAFC0
gUnknown_80DAFC0: @ 80DAFC0
	.incbin "baserom.gba", 0xDAFC0, 0xD8

	.global gUnknown_80DB098
gUnknown_80DB098: @ 80DB098
	.incbin "baserom.gba", 0xDB098, 0x60

	.global gUnknown_80DB0F8
gUnknown_80DB0F8: @ 80DB0F8
	.incbin "baserom.gba", 0xDB0F8, 0x3FC

	.global gUnknown_80DB4F4
gUnknown_80DB4F4: @ 80DB4F4
	.incbin "baserom.gba", 0xDB4F4, 0x44

	.global gUnknown_80DB538
gUnknown_80DB538: @ 80DB538
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x03, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00

	.global gUnknown_80DB550
gUnknown_80DB550: @ 80DB550
        .byte 0x00, 0x00
        .byte 0x00, 0x00
        .byte 0x01, 0x00
        .byte 0x00, 0x00
        .byte 0x01, 0x00
        .byte 0x0a, 0x00
        .byte 0x1c, 0x00
        .byte 0x09, 0x00
        .byte 0x09, 0x00
        .byte 0x00, 0x00
        .byte 0x00, 0x00
        .byte 0x00, 0x00

	.global gUnknown_80DB568
gUnknown_80DB568: @ 80DB568
        .byte 0x00, 0x00
        .byte 0x00, 0x00
        .byte 0x01, 0x00
        .byte 0x00, 0x00
        .byte 0x04, 0x00
        .byte 0x03, 0x00
        .byte 0x16, 0x00
        .byte 0x05, 0x00
        .byte 0x05, 0x00
        .byte 0x00, 0x00
        .byte 0x00, 0x00
        .byte 0x00, 0x00

	.global gUnknown_80DB580
gUnknown_80DB580: @ 80DB580
        .byte 0x00, 0x00
        .byte 0x00, 0x00
        .byte 0x01, 0x00
        .byte 0x00, 0x00
        .byte 0x01, 0x00
        .byte 0x02, 0x00
        .byte 0x1c, 0x00
        .byte 0x07, 0x00
        .byte 0x07, 0x00
        .byte 0x00, 0x00
        .byte 0x00, 0x00
        .byte 0x00, 0x00

	.global gUnknown_80DB598
gUnknown_80DB598: @ 80DB598
        .string "#C4OVR#R\0"
        .align 2,0

	.global gUnknown_80DB5A4
gUnknown_80DB5A4: @ 80DB5A4
        .string "#C6INS#R\0"
        .align 2,0

	.global gUnknown_80DB5B0
gUnknown_80DB5B0: @ 80DB5B0
        .byte 0x23, 0x43, 0x25, 0x63, 0x81, 0x59, 0x00, 0x00

	.global gUnknown_80DB5B8
gUnknown_80DB5B8: @ 80DB5B8
        .string "#C%c%s\0"
        .align 2,0

	.global gUnknown_80DB5C0
gUnknown_80DB5C0: @ 80DB5C0
        .string "What is your name?\0"
        .align 2,0

	.global gUnknown_80DB5D4
gUnknown_80DB5D4: @ 80DB5D4
	.incbin "baserom.gba", 0xDB5D4, 0x24

	.global gUnknown_80DB5F8
gUnknown_80DB5F8: @ 80DB5F8
        .string "What is your partner~27s nickname?\0"
        .align 2,0

	.global gUnknown_80DB61C
gUnknown_80DB61C: @ 80DB61C
        .string "What is your team~27s name?\0"
        .align 2,0

	.global gUnknown_80DB638
gUnknown_80DB638: @ 80DB638
        .string "Please enter the password.\0"
        .align 2,0

	.global gUnknown_80DB654
gUnknown_80DB654: @ 80DB654
        .string "#C2%s#R\0"
        .align 2,0

	.global gUnknown_80DB65C
gUnknown_80DB65C: @ 80DB65C
        .string "#C5%s#R\0"
        .align 2,0

	.global gUnknown_80DB664
gUnknown_80DB664: @ 80DB664
        .string "%s\0"
        .align 2,0
        .string "pksdir0\0"
        .align 2,0
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x03, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00

	.global gUnknown_80DB688
gUnknown_80DB688: @ 80DB688
        .string "Is the name #C5$m0#R OK?\0"
        .align 2,0

	.global gUnknown_80DB6A4
gUnknown_80DB6A4: @ 80DB6A4
        .string "This name is too long.\0"
        .align 2,0

	.global gUnknown_80DB6BC
gUnknown_80DB6BC: @ 80DB6BC
        .string "Please enter a name.\0"
        .align 2,0
        .string "pksdir0\0"
        .align 2,0

	.global gUnknown_80DB6DC
gUnknown_80DB6DC: @ 80DB6DC
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x03, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00

	.global gUnknown_80DB6F4
gUnknown_80DB6F4: @ 80DB6F4
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x03, 0x00, 0x00, 0x00
        .byte 0x02, 0x00, 0x03, 0x00
        .byte 0x1a, 0x00, 0x02, 0x00
        .byte 0x02, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00

	.global gUnknown_80DB70C
gUnknown_80DB70C: @ 80DB70C
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x03, 0x00, 0x00, 0x00
        .byte 0x11, 0x00, 0x08, 0x00
        .byte 0x0b, 0x00, 0x04, 0x00
        .byte 0x04, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00

	.global gUnknown_80DB724
gUnknown_80DB724: @ 80DB724
        .string "Money: \0"
        .align 2,0

	.global gUnknown_80DB72C
gUnknown_80DB72C: @ 80DB72C
        .string "Savings: \0"
        .align 2,0

	.global gUnknown_80DB738
gUnknown_80DB738: @ 80DB738
        .string "Money\0"
        .align 2,0
        .string "pksdir0\0"

	.global gUnknown_80DB748
gUnknown_80DB748: @ 80DB748
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x03, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00

	.global gUnknown_80DB760
gUnknown_80DB760: @ 80DB760
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x03, 0x00, 0x00, 0x00
        .byte 0x14, 0x00, 0x04, 0x00
        .byte 0x06, 0x00, 0x03, 0x00
        .byte 0x03, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00

	.global gUnknown_80DB778
gUnknown_80DB778: @ 80DB778
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x03, 0x00, 0x00, 0x00
        .byte 0x14, 0x00, 0x09, 0x00
        .byte 0x06, 0x00, 0x03, 0x00
        .byte 0x03, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00

	.global gUnknown_80DB790
gUnknown_80DB790: @ 80DB790
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x03, 0x00, 0x00, 0x00
        .byte 0x14, 0x00, 0x0e, 0x00
        .byte 0x06, 0x00, 0x04, 0x00
        .byte 0x04, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00

	.global gUnknown_80DB7A8
gUnknown_80DB7A8: @ 80DB7A8
        .string "Number?\0"
        .align 2,0
        .string "pksdir0\0"
        .align 2,0

	.global gUnknown_80DB7B8
gUnknown_80DB7B8: @ 80DB7B8
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x03, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00

	.global gUnknown_80DB7D0
gUnknown_80DB7D0: @ 80DB7D0
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x03, 0x00, 0x00, 0x00
        .byte 0x03, 0x00, 0x03, 0x00
        .byte 0x06, 0x00, 0x03, 0x00
        .byte 0x03, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00

	.global gUnknown_80DB7E8
gUnknown_80DB7E8: @ 80DB7E8
.byte 0x00, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x14, 0x00, 0x04, 0x00, 0x06, 0x00, 0x03, 0x00, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00

	.global gUnknown_80DB800
gUnknown_80DB800: @ 80DB800
.byte 0x00, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x14, 0x00, 0x09, 0x00, 0x06, 0x00, 0x03, 0x00, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00

	.global gUnknown_80DB818
gUnknown_80DB818: @ 80DB818
.byte 0x00, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x14, 0x00, 0x0e, 0x00, 0x06, 0x00, 0x04, 0x00, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00

	.global gUnknown_80DB830
gUnknown_80DB830: @ 80DB830
        .string "Number?\0"
        .align 2,0
        .string "pksdir0\0"
        .align 2,0

	.global gUnknown_80DB840
gUnknown_80DB840: @ 80DB840
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x03, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00

	.global gUnknown_80DB858
gUnknown_80DB858: @ 80DB858
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x03, 0x00, 0x00, 0x00
        .byte 0x14, 0x00, 0x04, 0x00
        .byte 0x06, 0x00, 0x03, 0x00
        .byte 0x03, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00

	.global gUnknown_80DB870
gUnknown_80DB870: @ 80DB870
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x03, 0x00, 0x00, 0x00
        .byte 0x14, 0x00, 0x09, 0x00
        .byte 0x06, 0x00, 0x03, 0x00
        .byte 0x03, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00

	.global gUnknown_80DB888
gUnknown_80DB888: @ 80DB888
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x03, 0x00, 0x00, 0x00
        .byte 0x14, 0x00, 0x0e, 0x00
        .byte 0x06, 0x00, 0x03, 0x00
        .byte 0x03, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00

	.global gUnknown_80DB8A0
gUnknown_80DB8A0: @ 80DB8A0
        .string "Sell All\0"
        .align 2,0
        .string "pksdir0\0"
        .align 2,0

	.global gUnknown_80DB8B4
gUnknown_80DB8B4: @ 80DB8B4
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x03, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00

	.global gUnknown_80DB8CC
gUnknown_80DB8CC: @ 80DB8CC
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x06, 0x00, 0x00, 0x00
        .byte 0x02, 0x00, 0x02, 0x00
        .byte 0x10, 0x00, 0x04, 0x00
        .byte 0x06, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00

	.global gUnknown_80DB8E4
gUnknown_80DB8E4: @ 80DB8E4
        .string "Goods\0"
        .align 2,0

	.global gUnknown_80DB8EC
gUnknown_80DB8EC: @ 80DB8EC
        .string "#C2%s#R\0"
        .string "pksdir0\0"
        .align 2,0

	.global gUnknown_80DB8FC
gUnknown_80DB8FC: @ 80DB8FC
	.incbin "baserom.gba", 0xDB8FC, 0x18

	.global gUnknown_80DB914
gUnknown_80DB914: @ 80DB914
	.incbin "baserom.gba", 0xDB914, 0x18

	.global gUnknown_80DB92C
gUnknown_80DB92C: @ 80DB92C
        .string "Goods\0"
        .align 2,0

	.global gUnknown_80DB934
gUnknown_80DB934: @ 80DB934
        .string "#C2%s#R\0"
        .string "pksdir0\0"
        .align 2,0

	.global gUnknown_80DB944
gUnknown_80DB944: @ 80DB944
	.incbin "baserom.gba", 0xDB944, 0x18

	.global gUnknown_80DB95C
gUnknown_80DB95C: @ 80DB95C
	.incbin "baserom.gba", 0xDB95C, 0x18

	.global gUnknown_80DB974
gUnknown_80DB974: @ 80DB974
        .string "Team Toolbox A\0"
        .align 2,0

	.global gUnknown_80DB984
gUnknown_80DB984: @ 80DB984
        .string "Team Toolbox B\0"
        .align 2,0

	.global gUnknown_80DB994
gUnknown_80DB994: @ 80DB994
	.incbin "baserom.gba", 0xDB994, 0xC

	.global gUnknown_80DB9A0
gUnknown_80DB9A0: @ 80DB9A0
        .string "#C2%s#R\0"
        .align 2,0

	.global gUnknown_80DB9A8
gUnknown_80DB9A8: @ 80DB9A8
        .string "Items\0"
        .align 2,0

	.global gUnknown_80DB9B0
gUnknown_80DB9B0: @ 80DB9B0
        .string "/\0"
        .align 2,0
        .string "pksdir0\0"
        .align 2,0

	.global gUnknown_80DB9BC
gUnknown_80DB9BC: @ 80DB9BC
        .string "#+Who will learn the move\n"
        .string "#+#C5$m7#R?\0"
        .align 2,0

	.global gUnknown_80DB9E4
gUnknown_80DB9E4: @ 80DB9E4
        .string "#+#CM$m8#R learned\n"
        .string "#+the move #C5$m7#R!\0"
        .align 2,0

	.global gUnknown_80DBA0C
gUnknown_80DBA0C: @ 80DBA0C
	.incbin "baserom.gba", 0xDBA0C, 0x40

	.global gUnknown_80DBA4C
gUnknown_80DBA4C: @ 80DBA4C
        .string "$m0\0"
        .string "pksdir0\0"
        .align 2,0

	.global gUnknown_80DBA58
gUnknown_80DBA58: @ 80DBA58
	.incbin "baserom.gba", 0xDBA58, 0x18

	.global gUnknown_80DBA70
gUnknown_80DBA70: @ 80DBA70
	.incbin "baserom.gba", 0xDBA70, 0x18

	.global gUnknown_80DBA88
gUnknown_80DBA88: @ 80DBA88
	.incbin "baserom.gba", 0xDBA88, 0x18

	.global gUnknown_80DBAA0
gUnknown_80DBAA0: @ 80DBAA0
	.incbin "baserom.gba", 0xDBAA0, 0x30

	.global gUnknown_80DBAD0
gUnknown_80DBAD0: @ 80DBAD0
	.incbin "baserom.gba", 0xDBAD0, 0x38

	.global gUnknown_80DBB08
gUnknown_80DBB08: @ 80DBB08
	.incbin "baserom.gba", 0xDBB08, 0x30

	.global gUnknown_80DBB38
gUnknown_80DBB38: @ 80DBB38
	.incbin "baserom.gba", 0xDBB38, 0x64

	.global gUnknown_80DBB9C
gUnknown_80DBB9C: @ 80DBB9C
	.incbin "baserom.gba", 0xDBB9C, 0x8C

	.global gUnknown_80DBC28
gUnknown_80DBC28: @ 80DBC28
	.incbin "baserom.gba", 0xDBC28, 0x38

	.global gUnknown_80DBC60
gUnknown_80DBC60: @ 80DBC60
	.incbin "baserom.gba", 0xDBC60, 0x38

	.global gUnknown_80DBC98
gUnknown_80DBC98: @ 80DBC98
	.incbin "baserom.gba", 0xDBC98, 0x2C

	.global gUnknown_80DBCC4
gUnknown_80DBCC4: @ 80DBCC4
	.incbin "baserom.gba", 0xDBCC4, 0x24

	.global gUnknown_80DBCE8
gUnknown_80DBCE8: @ 80DBCE8
	.incbin "baserom.gba", 0xDBCE8, 0x3C

	.global gUnknown_80DBD24
gUnknown_80DBD24: @ 80DBD24
	.incbin "baserom.gba", 0xDBD24, 0x34

	.global gUnknown_80DBD58
gUnknown_80DBD58: @ 80DBD58
        .string "Trash Toolbox Item\0"
        .align 2,0

	.global gUnknown_80DBD6C
gUnknown_80DBD6C: @ 80DBD6C
        .string "Trash Received Item\0"
        .align 2,0

	.global gUnknown_80DBD80
gUnknown_80DBD80: @ 80DBD80
        .string "Storage\0"
        .align 2,0

	.global gUnknown_80DBD88
gUnknown_80DBD88: @ 80DBD88
        .string "Trash\0"
        .align 2,0
        .string "pksdir0\0"
        .align 2,0

	.global gUnknown_80DBD98
gUnknown_80DBD98: @ 80DBD98
	.incbin "baserom.gba", 0xDBD98, 0x18

	.global gUnknown_80DBDB0
gUnknown_80DBDB0: @ 80DBDB0
	.incbin "baserom.gba", 0xDBDB0, 0x18

	.global gUnknown_80DBDC8
gUnknown_80DBDC8: @ 80DBDC8
        .string "Switch\0"
        .align 2,0
        .string "pksdir0\0"
        .align 2,0

	.global gUnknown_80DBDD8
gUnknown_80DBDD8: @ 80DBDD8
	.incbin "baserom.gba", 0xDBDD8, 0x18

	.global gUnknown_80DBDF0
gUnknown_80DBDF0: @ 80DBDF0
	.incbin "baserom.gba", 0xDBDF0, 0x18

	.global gUnknown_80DBE08
gUnknown_80DBE08: @ 80DBE08
        .string "IQ Skills\0"
        .align 2,0

	.global gUnknown_80DBE14
gUnknown_80DBE14: @ 80DBE14
        .byte 0x87, 0x42, 0x00, 0x00

	.global gUnknown_80DBE18
gUnknown_80DBE18: @ 80DBE18
        .byte 0x87, 0x40, 0x00, 0x00

	.global gUnknown_80DBE1C
gUnknown_80DBE1C: @ 80DBE1C
        .string "$i0$i1\0"
        .align 2,0
        .string "pksdir0\0"
        .align 2,0

	.global gUnknown_80DBE2C
gUnknown_80DBE2C: @ 80DBE2C
        .string "$i0\0"
        .align 2,0

	.global gUnknown_80DBE30
gUnknown_80DBE30: @ 80DBE30
        .string "$m0\0"
        .string "pksdir0\0"
        .align 2,0

	.global gUnknown_80DBE3C
gUnknown_80DBE3C: @ 80DBE3C
	.incbin "baserom.gba", 0xDBE3C, 0x18

	.global gUnknown_80DBE54
gUnknown_80DBE54: @ 80DBE54
	.incbin "baserom.gba", 0xDBE54, 0x18

	.global gUnknown_80DBE6C
gUnknown_80DBE6C: @ 80DBE6C
        .string "Storage\0"
        .string "pksdir0\0"
        .align 2,0

	.global gUnknown_80DBE7C
gUnknown_80DBE7C: @ 80DBE7C
	.incbin "baserom.gba", 0xDBE7C, 0x1C

	.global gUnknown_80DBE98
gUnknown_80DBE98: @ 80DBE98
	.incbin "baserom.gba", 0xDBE98, 0x18

	.global gUnknown_80DBEB0
gUnknown_80DBEB0: @ 80DBEB0
	.incbin "baserom.gba", 0xDBEB0, 0x60

	.global gUnknown_80DBF10
gUnknown_80DBF10: @ 80DBF10
        .string "Items\0"
        .align 2,0

	.global gUnknown_80DBF18
gUnknown_80DBF18: @ 80DBF18
        .string "Team\0"
        .align 2,0

	.global gUnknown_80DBF20
gUnknown_80DBF20: @ 80DBF20
        .string "Job List\0"
        .align 2,0

	.global gUnknown_80DBF2C
gUnknown_80DBF2C: @ 80DBF2C
        .string "Others\0"
        .align 2,0

	.global gUnknown_80DBF34
gUnknown_80DBF34: @ 80DBF34
        .byte 0x81, 0x48
        .byte 0x81, 0x48
        .byte 0x81, 0x48
        .byte 0x00, 0x00

	.global gUnknown_80DBF3C
gUnknown_80DBF3C: @ 80DBF3C
        .string "%s #C5%d#R Pts.\0"
        .align 2,0

	.global gUnknown_80DBF4C
gUnknown_80DBF4C: @ 80DBF4C
	.incbin "baserom.gba", 0xDBF4C, 0x14

	.global gUnknown_80DBF60
gUnknown_80DBF60: @ 80DBF60
        .string "tmrkpat\0"
        .align 2,0
        .string "pksdir0\0"
        .align 2,0

	.global gUnknown_80DBF70
gUnknown_80DBF70: @ 80DBF70
	.incbin "baserom.gba", 0xDBF70, 0x18

	.global gUnknown_80DBF88
gUnknown_80DBF88: @ 80DBF88
	.incbin "baserom.gba", 0xDBF88, 0x18

	.global gUnknown_80DBFA0
gUnknown_80DBFA0: @ 80DBFA0
        .string "Field\0"
        .align 2,0
        .string "pksdir0\0"
        .align 2,0

	.global gUnknown_80DBFB0
gUnknown_80DBFB0: @ 80DBFB0
	.incbin "baserom.gba", 0xDBFB0, 0x1C

	.global gUnknown_80DBFCC
gUnknown_80DBFCC: @ 80DBFCC
	.incbin "baserom.gba", 0xDBFCC, 0x18

	.global gUnknown_80DBFE4
gUnknown_80DBFE4: @ 80DBFE4
        .string "Others\0"
        .align 2,0

	.global gUnknown_80DBFEC
gUnknown_80DBFEC: @ 80DBFEC
        .string "Change settings?\0"
        .align 2,0

	.global gUnknown_80DC000
gUnknown_80DC000: @ 80DC000
        .string "Game Options\0"
        .align 2,0

	.global gUnknown_80DC010
gUnknown_80DC010: @ 80DC010
        .string "Hints\0"
        .align 2,0
        .string "pksdir0\0"
        .align 2,0

	.global gUnknown_80DC020
gUnknown_80DC020: @ 80DC020
	.incbin "baserom.gba", 0xDC020, 0x1C

	.global gUnknown_80DC03C
gUnknown_80DC03C: @ 80DC03C
	.incbin "baserom.gba", 0xDC03C, 0x18

	.global gUnknown_80DC054
gUnknown_80DC054: @ 80DC054
        .string "Game Options\0"
        .align 2,0

@ Window Settings
	.global gUnknown_80DC064
gUnknown_80DC064: @ 80DC064
	.incbin "baserom.gba", 0xDC064, 0x20

	.global gUnknown_80DC084
gUnknown_80DC084: @ 80DC084
        .string "Blue\0"
        .align 2,0

	.global gUnknown_80DC08C
gUnknown_80DC08C: @ 80DC08C
        .string "Red\0"
        .align 2,0

	.global gUnknown_80DC090
gUnknown_80DC090: @ 80DC090
        .string "Green\0"
        .align 2,0
        .string "pksdir0\0"
        .align 2,0

	.global gUnknown_80DC0A0
gUnknown_80DC0A0: @ 80DC0A0
	.incbin "baserom.gba", 0xDC0A0, 0x1C

	.global gUnknown_80DC0BC
gUnknown_80DC0BC: @ 80DC0BC
	.incbin "baserom.gba", 0xDC0BC, 0x18

	.global gUnknown_80DC0D4
gUnknown_80DC0D4: @ 80DC0D4
        .string "Hints\0"
        .align 2,0
        .string "pksdir0\0"
        .align 2,0

	.global gUnknown_80DC0E4
gUnknown_80DC0E4: @ 80DC0E4
	.incbin "baserom.gba", 0xDC0E4, 0x18

	.global gUnknown_80DC0FC
gUnknown_80DC0FC: @ 80DC0FC
	.incbin "baserom.gba", 0xDC0FC, 0x20

	.global gUnknown_80DC11C
gUnknown_80DC11C: @ 80DC11C
	.incbin "baserom.gba", 0xDC11C, 0x18

	.global gUnknown_80DC134
gUnknown_80DC134: @ 80DC134
	.incbin "baserom.gba", 0xDC134, 0x30

	.global gUnknown_80DC164
gUnknown_80DC164: @ 80DC164
        .string "Only four moves may be learned!\n"
        .string "Will a move be forgotten?\0"
        .align 2,0

	.global gUnknown_80DC1A0
gUnknown_80DC1A0: @ 80DC1A0
	.incbin "baserom.gba", 0xDC1A0, 0x5C

	.global gUnknown_80DC1FC
gUnknown_80DC1FC: @ 80DC1FC
	.incbin "baserom.gba", 0xDC1FC, 0x34

	.global gUnknown_80DC230
gUnknown_80DC230: @ 80DC230
        .string "Forget\0"
        .align 2,0
        .string "pksdir0\0"
        .align 2,0

	.global gUnknown_80DC240
gUnknown_80DC240: @ 80DC240
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x03, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x01, 0x00, 0x0f, 0x00

	.global gUnknown_80DC25C
gUnknown_80DC25C: @ 80DC25C
        .byte 0x00, 0x00
        .byte 0x00, 0x00
        .byte 0x06, 0x00
        .byte 0x00, 0x00
        .byte 0x02, 0x00
        .byte 0x02, 0x00
        .byte 0x12, 0x00
        .byte 0x08, 0x00
        .byte 0x08, 0x00
        .byte 0x00, 0x00
        .byte 0x58, 0xc2, 0x0d, 0x08

	.global gUnknown_80DC274
gUnknown_80DC274: @ 80DC274
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x03, 0x00, 0x00, 0x00
        .byte 0x02, 0x00, 0x0f, 0x00
        .byte 0x1a, 0x00, 0x03, 0x00
        .byte 0x03, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00

	.global gUnknown_80DC28C
gUnknown_80DC28C: @ 80DC28C
        .string "Moves: #C6$m0#R \0"
        .align 2,0

	.global gUnknown_80DC2A0
gUnknown_80DC2A0: @ 80DC2A0
        .string "$i0\0"
        .align 2,0
        .string "pksdir0\0"
        .align 2,0

	.global gUnknown_80DC2AC
gUnknown_80DC2AC: @ 80DC2AC
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x03, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00

	.global gUnknown_80DC2C4
gUnknown_80DC2C4: @ 80DC2C4
        .byte 0x00, 0x00
        .byte 0x00, 0x00
        .byte 0x06, 0x00
        .byte 0x00, 0x00
        .byte 0x02, 0x00
        .byte 0x02, 0x00
        .byte 0x0f, 0x00
        .byte 0x04, 0x00
        .byte 0x06, 0x00
        .byte 0x00, 0x00
        .byte 0x00, 0x00
        .byte 0x00, 0x00

	.global gUnknown_80DC2DC
gUnknown_80DC2DC: @ 80DC2DC
        .string "Moves Page: %d/%d \0"
        .align 2,0
        .string "pksdir0\0"
        .align 2,0

	.global gUnknown_80DC2F8
gUnknown_80DC2F8: @ 80DC2F8
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x03, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00

	.global gUnknown_80DC310
gUnknown_80DC310: @ 80DC310
        .string "$m0\0"
        .align 2,0
        .string "pksdir0\0"
        .align 2,0

	.global gUnknown_80DC31C
gUnknown_80DC31C: @ 80DC31C
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x03, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00

	.global gUnknown_80DC334
gUnknown_80DC334: @ 80DC334
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x03, 0x00, 0x00, 0x00
        .byte 0x13, 0x00, 0x04, 0x00
        .byte 0x08, 0x00, 0x03, 0x00
        .byte 0x03, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00

	.global gUnknown_80DC34C
gUnknown_80DC34C: @ 80DC34C
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x03, 0x00, 0x00, 0x00
        .byte 0x16, 0x00, 0x04, 0x00
        .byte 0x06, 0x00, 0x03, 0x00
        .byte 0x03, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x03, 0x00, 0x00, 0x00
        .byte 0x16, 0x00, 0x0e, 0x00
        .byte 0x06, 0x00, 0x03, 0x00
        .byte 0x03, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00

	.global gUnknown_80DC37C
gUnknown_80DC37C: @ 80DC37C
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x03, 0x00, 0x00, 0x00
        .byte 0x16, 0x00, 0x03, 0x00
        .byte 0x06, 0x00, 0x03, 0x00
        .byte 0x03, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00

	.global gUnknown_80DC394
gUnknown_80DC394: @ 80DC394
        .string "{R_BUTTON}+{DPAD}: Shift moves\n"
        .string "{R_BUTTON}+{A_BUTTON}: Switch link  {SELECT_BUTTON} Set\0"

	.global gUnknown_80DC3C4
gUnknown_80DC3C4: @ 80DC3C4
        .string "Proceed\0"
        .align 2,0

	.global gUnknown_80DC3CC
gUnknown_80DC3CC: @ 80DC3CC
        .string "#C6Info#R \0"
        .align 2,0

	.global gUnknown_80DC3D8
gUnknown_80DC3D8: @ 80DC3D8
        .string "Moves\0"
        .align 2,0

	.global gUnknown_80DC3E0
gUnknown_80DC3E0: @ 80DC3E0
        .string "Summary\0"
        .align 2,0

	.global gUnknown_80DC3E8
gUnknown_80DC3E8: @ 80DC3E8
        .string "Check IQ\0"
        .align 2,0

	.global gUnknown_80DC3F4
gUnknown_80DC3F4: @ 80DC3F4
        .string "Remember\0"
        .align 2,0

	.global gUnknown_80DC400
gUnknown_80DC400: @ 80DC400
        .string "Deselect\0"
        .align 2,0

	.global gUnknown_80DC40C
gUnknown_80DC40C: @ 80DC40C
        .string "Set\0"
        .align 2,0

	.global gUnknown_80DC410
gUnknown_80DC410: @ 80DC410
        .string "Link\0"
        .align 2,0

	.global gUnknown_80DC418
gUnknown_80DC418: @ 80DC418
        .string "Delink\0"
        .align 2,0

	.global gUnknown_80DC420
gUnknown_80DC420: @ 80DC420
        .string "Forget\0"
        .align 2,0

	.global gUnknown_80DC428
gUnknown_80DC428: @ 80DC428
        .string "Setting moves\0"
        .align 2,0

	.global gUnknown_80DC438
gUnknown_80DC438: @ 80DC438
        .string "Linking moves\0"
        .align 2,0

	.global gUnknown_80DC448
gUnknown_80DC448: @ 80DC448
        .string "Remembering moves\0"
        .align 2,0
        .string "pksdir0\0"
        .align 2,0

	.global gUnknown_80DC464
gUnknown_80DC464: @ 80DC464
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x03, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00

	.global gUnknown_80DC47C
gUnknown_80DC47C: @ 80DC47C
        .byte 0x00, 0x00
        .byte 0x00, 0x00
        .byte 0x06, 0x00
        .byte 0x00, 0x00
        .byte 0x02, 0x00
        .byte 0x02, 0x00
        .byte 0x11, 0x00
        .byte 0x11, 0x00
        .byte 0x11, 0x00
        .byte 0x00, 0x00
        .byte 0x00, 0x00
        .byte 0x00, 0x00

	.global gUnknown_80DC494
gUnknown_80DC494: @ 80DC494
        .string "Friend Areas\0"
        .align 2,0

	.global gUnknown_80DC4A4
gUnknown_80DC4A4: @ 80DC4A4
        .string "#C2%s#R\0"
        .align 2,0

	.global gUnknown_80DC4AC
gUnknown_80DC4AC: @ 80DC4AC
        .string "#C4%s#R\0"
        .align 2,0
        .string "pksdir0\0"
        .align 2,0

	.global gUnknown_80DC4BC
gUnknown_80DC4BC: @ 80DC4BC
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x03, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x01, 0x00, 0x12, 0x00

	.global gUnknown_80DC4D8
gUnknown_80DC4D8: @ 80DC4D8
        .byte 0x00, 0x00
        .byte 0x00, 0x00
        .byte 0x06, 0x00
        .byte 0x00, 0x00
        .byte 0x02, 0x00
        .byte 0x02, 0x00
        .byte 0x1a, 0x00
        .byte 0x11, 0x00
        .byte 0x11, 0x00
        .byte 0x00, 0x00
        .byte 0xd4, 0xc4, 0x0d, 0x08

	.global gUnknown_80DC4F0
gUnknown_80DC4F0: @ 80DC4F0
        .string "Inhabitants (Friends: #c5Light blue#r)\0"
        .align 2,0

	.global gUnknown_80DC518
gUnknown_80DC518: @ 80DC518
        .string "Inhabitants\0"
        .align 2,0

	.global gUnknown_80DC524
gUnknown_80DC524: @ 80DC524
        .string "#c5%s#r\0"
        .align 2,0
        .string "pksdir0\0"
        .align 2,0

	.global gUnknown_80DC534
gUnknown_80DC534: @ 80DC534
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x03, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00

	.global gUnknown_80DC54C
gUnknown_80DC54C: @ 80DC54C
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x03, 0x00, 0x00, 0x00
        .byte 0x15, 0x00, 0x04, 0x00
        .byte 0x06, 0x00, 0x03, 0x00
        .byte 0x03, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00

	.global gUnknown_80DC564
gUnknown_80DC564: @ 80DC564
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x03, 0x00, 0x00, 0x00
        .byte 0x15, 0x00, 0x0e, 0x00
        .byte 0x06, 0x00, 0x03, 0x00
        .byte 0x03, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .string "pksdir0\0"
        .align 2,0

	.global gUnknown_80DC584
gUnknown_80DC584: @ 80DC584
        .byte 0xa0, 0xc5, 0x0d, 0x08
        .byte 0x02, 0x00, 0x00, 0x00
        .byte 0x9c, 0xc5, 0x0d, 0x08
        .byte 0x03, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x01, 0x00, 0x00, 0x00
        .byte 0x4e, 0x6f, 0x00, 0x00
        .byte 0x59, 0x65, 0x73, 0x00

	.global gUnknown_80DC5A4
gUnknown_80DC5A4: @ 80DC5A4
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x03, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00

	.global gUnknown_80DC5BC
gUnknown_80DC5BC: @ 80DC5BC
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x03, 0x00, 0x00, 0x00
        .byte 0x14, 0x00, 0x04, 0x00
        .byte 0x06, 0x00, 0x03, 0x00
        .byte 0x03, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00

	.global gUnknown_80DC5D4
gUnknown_80DC5D4: @ 80DC5D4
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x03, 0x00, 0x00, 0x00
        .byte 0x14, 0x00, 0x0b, 0x00
        .byte 0x06, 0x00, 0x03, 0x00
        .byte 0x03, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00

	.global gUnknown_80DC5EC
gUnknown_80DC5EC: @ 80DC5EC
        .byte 0x81, 0x48
        .byte 0x81, 0x48
        .byte 0x81, 0x48
        .byte 0x00, 0x00

	.global gUnknown_80DC5F4
gUnknown_80DC5F4: @ 80DC5F4
        .string "It doesn~27t appear to be hungry.\0"
        .align 2,0

	.global gUnknown_80DC618
gUnknown_80DC618: @ 80DC618
	.incbin "baserom.gba", 0xDC618, 0x5C

	.global gUnknown_80DC674
gUnknown_80DC674: @ 80DC674
	.incbin "baserom.gba", 0xDC674, 0x58

	.global gUnknown_80DC6CC
gUnknown_80DC6CC: @ 80DC6CC
	.incbin "baserom.gba", 0xDC6CC, 0x5C

	.global gUnknown_80DC728
gUnknown_80DC728: @ 80DC728
	.incbin "baserom.gba", 0xDC728, 0x60

	.global gUnknown_80DC788
gUnknown_80DC788: @ 80DC788
	.incbin "baserom.gba", 0xDC788, 0x2C

	.global gUnknown_80DC7B4
gUnknown_80DC7B4: @ 80DC7B4
	.incbin "baserom.gba", 0xDC7B4, 0x48

	.global gUnknown_80DC7FC
gUnknown_80DC7FC: @ 80DC7FC
@ replacing .incbin "baserom.gba", 0x000dc7fc, 0x20
        .string "Yes!\n"
        .string "$m1~27s Attack rose by 1!\0"
        .align 2,0

	.global gUnknown_80DC81C
gUnknown_80DC81C: @ 80DC81C
@ replacing .incbin "baserom.gba", 0x000dc81c, 0x28
        .string "Yes!\n"
        .string "$m1~27s Special Attack rose by 1!\0"
        .align 2,0

	.global gUnknown_80DC844
gUnknown_80DC844: @ 80DC844
@ replacing .incbin "baserom.gba", 0x000dc844, 0x20
        .string "Yes!\n"
        .string "$m1~27s Defense rose by 1!\0"
        .align 2,0


	.global gUnknown_80DC864
gUnknown_80DC864: @ 80DC864
@ replacing .incbin "baserom.gba", 0x000dc864, 0x28
        .string "Yes!\n"
        .string "$m1~27s Special Defense rose by 1!\0"
        .align 2,0

	.global gUnknown_80DC88C
gUnknown_80DC88C: @ 80DC88C
@ replacing .incbin "baserom.gba", 0x000dc88c, 0x20
        .string "You don~27t have any Gummis.\0"
        .align 2,0

	.global gUnknown_80DC8AC
gUnknown_80DC8AC: @ 80DC8AC
@ replacing .incbin "baserom.gba", 0x000dc8ac, 0x1c
        .string "You don~27t have an item.\0"
        .align 2,0

	.global gUnknown_80DC8C8
gUnknown_80DC8C8: @ 80DC8C8
@ replacing .incbin "baserom.gba", 0x000dc8c8, 0x14
        .string "The Gummi is gone!\0"
        .align 2,0

	.global gUnknown_80DC8DC
gUnknown_80DC8DC: @ 80DC8DC
        .string "The item is gone!\0"
        .align 2,0

	.global gUnknown_80DC8F0
gUnknown_80DC8F0: @ 80DC8F0
        .string "Give\0"
        .align 2,0

	.global gUnknown_80DC8F8
gUnknown_80DC8F8: @ 80DC8F8
@ replacing .incbin "baserom.gba", 0x000dc8f8, 0xc
        .string "Use\0"
        .align 2,0
        .string "pksdir0\0"
        .align 2,0

	.global gUnknown_80DC904
gUnknown_80DC904: @ 80DC904
@ replacing .incbin "baserom.gba", 0x000dc904, 0x18
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x03, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00

	.global gUnknown_80DC91C
gUnknown_80DC91C: @ 80DC91C
@ replacing .incbin "baserom.gba", 0x000dc91c, 0x18
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x06, 0x00, 0x00, 0x00
        .byte 0x02, 0x00, 0x02, 0x00
        .byte 0x0f, 0x00, 0x0e, 0x00
        .byte 0x0e, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00

	.global gUnknown_80DC934
gUnknown_80DC934: @ 80DC934
@ replacing .incbin "baserom.gba", 0x000dc934, 0x8
.byte 0x50, 0x6f, 0x6b, 0xe9, 0x6d, 0x6f, 0x6e, 0x00

	.global gUnknown_80DC93C
gUnknown_80DC93C: @ 80DC93C
@ replacing .incbin "baserom.gba", 0x000dc93c, 0x14
        .string "#c%c%s#r\0"
        .align 2,0
        .string "pksdir0\0"
        .align 2,0

	.global gUnknown_80DC950
gUnknown_80DC950: @ 80DC950
@ replacing .incbin "baserom.gba", 0x000dc950, 0x18
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x03, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00

	.global gUnknown_80DC968
gUnknown_80DC968: @ 80DC968
@ replacing .incbin "baserom.gba", 0x000dc968, 0x18
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x06, 0x00, 0x00, 0x00
        .byte 0x02, 0x00, 0x02, 0x00
        .byte 0x0f, 0x00, 0x0e, 0x00
        .byte 0x0e, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00

	.global gUnknown_80DC980
gUnknown_80DC980: @ 80DC980
@ replacing .incbin "baserom.gba", 0x000dc980, 0x8
        .string "Friends\0"

	.global gUnknown_80DC988
gUnknown_80DC988: @ 80DC988
@ replacing .incbin "baserom.gba", 0x000dc988, 0x10
.byte 0x50, 0x6f, 0x6b, 0xe9, 0x6d, 0x6f, 0x6e, 0x20, 0x46, 0x72, 0x69, 0x65, 0x6e, 0x64, 0x73, 0x00

	.global gUnknown_80DC998
gUnknown_80DC998: @ 80DC998
@ replacing .incbin "baserom.gba", 0x000dc998, 0xc
.byte 0x23, 0x63, 0x25, 0x63, 0x25, 0x73, 0x23, 0x72, 0x00, 0x00, 0x00, 0x00

	.global gUnknown_80DC9A4
gUnknown_80DC9A4: @ 80DC9A4
@ replacing .incbin "baserom.gba", 0x000dc9a4, 0xc
        .byte 0x25, 0x73, 0x00, 0x00
        .byte 0x70, 0x6b, 0x73, 0x64, 0x69, 0x72, 0x30, 0x00

	.global gUnknown_80DC9B0
gUnknown_80DC9B0: @ 80DC9B0
@ replacing .incbin "baserom.gba", 0x000dc9b0, 0x18
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x03, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00

	.global gUnknown_80DC9C8
gUnknown_80DC9C8: @ 80DC9C8
@ replacing .incbin "baserom.gba", 0x000dc9c8, 0x20
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x06, 0x00, 0x00, 0x00
        .byte 0x02, 0x00, 0x02, 0x00
        .byte 0x12, 0x00, 0x0e, 0x00
        .byte 0x12, 0x00, 0x02, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
.byte 0x70, 0x6b, 0x73, 0x64, 0x69, 0x72, 0x30, 0x00

	.global gUnknown_80DC9E8
gUnknown_80DC9E8: @ 80DC9E8
@ replacing .incbin "baserom.gba", 0x000dc9e8, 0x18
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x03, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00

	.global gUnknown_80DCA00
gUnknown_80DCA00: @ 80DCA00
@ replacing .incbin "baserom.gba", 0x000dca00, 0x18
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x03, 0x00, 0x00, 0x00
        .byte 0x14, 0x00, 0x04, 0x00
        .byte 0x06, 0x00, 0x03, 0x00
        .byte 0x03, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00

	.global gUnknown_80DCA18
gUnknown_80DCA18: @ 80DCA18
        .string "Evolve\0"
        .align 2,0
        .4byte gUnknown_80DCA18

	.global gUnknown_80DCA24
gUnknown_80DCA24: @ 80DCA24
        .string "No\0"
        .align 2,0
        .4byte gUnknown_80DCA24

	.global gUnknown_80DCA2C
gUnknown_80DCA2C: @ 80DCA2C
@ replacing .incbin "baserom.gba", 0x000dca2c, 0x8
        .string "Yes\0"
        .align 2,0
        .4byte gUnknown_80DCA2C

	.include "data/text/luminous_cave.inc"

        .include "data/friend_area.inc"

	.include "data/text/party_menu.inc"

	.global gUnknown_80DD6EC
gUnknown_80DD6EC: @ 80DD6EC
        .byte 0x00, 0x00, 0x00, 0x00

        .byte 0x03, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00

        .byte 0x00, 0x00, 0x00, 0x00

	.global gUnknown_80DD704
gUnknown_80DD704: @ 80DD704
        .byte 0x00, 0x00, 0x00, 0x00

        .byte 0x03, 0x00, 0x00, 0x00
        .byte 0x13, 0x00, 0x04, 0x00
        .byte 0x09, 0x00, 0x03, 0x00
        .byte 0x03, 0x00, 0x00, 0x00

        .byte 0x00, 0x00, 0x00, 0x00

	.global gUnknown_80DD71C
gUnknown_80DD71C: @ 80DD71C
	.incbin "baserom.gba", 0xDD71C, 0x30

	.global gUnknown_80DD74C
gUnknown_80DD74C: @ 80DD74C
        .byte 0x00, 0x00, 0x00, 0x00

        .byte 0x03, 0x00, 0x00, 0x00
        .byte 0x02, 0x00, 0x11, 0x00
        .byte 0x1A, 0x00, 0x02, 0x00
        .byte 0x02, 0x00, 0x00, 0x00

        .byte 0x00, 0x00, 0x00, 0x00

	.global gUnknown_80DD764
gUnknown_80DD764: @ 80DD764
        .string "You have chosen to say farewell\n"
        .string "to this Pokémon.#P"
        .string "The Pokémon will leave its Friend Area.\n"
        .string "It will no longer be available for\n"
        .string "adventures. Is that OK?\0"
        .align 2,0

	.global gUnknown_80DD7FC
gUnknown_80DD7FC: @ 80DD7FC
	.incbin "baserom.gba", 0xDD7FC, 0xA4

	.global gUnknown_80DD8A0
gUnknown_80DD8A0: @ 80DD8A0
        .string "#+The #C4$i0#R was\n"
        .string "#+returned to the Toolbox.\0"
        .align 2,0

	.global gUnknown_80DD8D0
gUnknown_80DD8D0: @ 80DD8D0
	.incbin "baserom.gba", 0xDD8D0, 0x28

	.global gUnknown_80DD8F8
gUnknown_80DD8F8: @ 80DD8F8
        .string "Stand By\0"
        .align 2,0

	.global gUnknown_80DD904
gUnknown_80DD904: @ 80DD904
        .string "Make Leader\0"

	.global gUnknown_80DD910
gUnknown_80DD910: @ 80DD910
        .string "Join Team\0"
        .align 2,0

	.global gUnknown_80DD91C
gUnknown_80DD91C: @ 80DD91C
        .string "Say Farewell\0"
        .align 2,0

	.global gUnknown_80DD92C
gUnknown_80DD92C: @ 80DD92C
        .string "Give\0"
        .align 2,0

	.global gUnknown_80DD934
gUnknown_80DD934: @ 80DD934
        .string "Take\0"
        .align 2,0

	.global gUnknown_80DD93C
gUnknown_80DD93C: @ 80DD93C
        .string "Summary\0"
        .align 2,0

	.global gUnknown_80DD944
gUnknown_80DD944: @ 80DD944
        .string "Moves\0"
        .align 2,0

	.global gUnknown_80DD94C
gUnknown_80DD94C: @ 80DD94C
        .string "Check IQ\0"
        .align 2,0

	.global gUnknown_80DD958
gUnknown_80DD958: @ 80DD958
        .string "Item: #C4$i0#R \0"
        .string "pksdir0\0"

	.global gUnknown_80DD970
gUnknown_80DD970: @ 80DD970
@ replacing .incbin "baserom.gba", 0x000dd970, 0x7c
        .4byte gWonderMailReceiveSOSMail
        .byte 0x00, 0x00, 0x00, 0x00
        .4byte gWonderMailLeaveForRescue
        .byte 0x01, 0x00, 0x00, 0x00
        .4byte gWonderMailSendAOKMail
        .byte 0x02, 0x00, 0x00, 0x00
        .4byte gWonderMailDeleteMail
        .byte 0x03, 0x00, 0x00, 0x00
        .4byte gWonderMailCancel
        .byte 0x0a, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x0a, 0x00, 0x00, 0x00

        .global gWonderMailCancel @ 80DD9A0
        gWonderMailCancel:
        .string "Cancel\0"
        .align 2,0

        .global gWonderMailDeleteMail @ 80DD9A8
        gWonderMailDeleteMail:
        .string "Delete Mail\0"
        .align 2,0

        .global gWonderMailSendAOKMail @ 80DD9B4
        gWonderMailSendAOKMail:
        .string "Send A-OK Mail\0"
        .align 2,0

        .global gWonderMailLeaveForResuce @ 80DD9C4
        gWonderMailLeaveForRescue:
        .string "Leave for Rescue\0"
        .align 2,0

        .global gWonderMailReceiveSOSMail @ 80DD9D8
        gWonderMailReceiveSOSMail:
        .string "Receive SOS Mail\0"
        .align 2,0

	.global gUnknown_80DD9EC
gUnknown_80DD9EC: @ 80DD9EC
@ replacing .incbin "baserom.gba", 0x000dd9ec, 0x5c
        .4byte gWonderMailDeleteSOSMail
        .byte 0x05, 0x00, 0x00, 0x00
        .4byte gWonderMailDeleteAOKMail
        .byte 0x06, 0x00, 0x00, 0x00
        .4byte gWonderMailDeleteAllMail
        .byte 0x07, 0x00, 0x00, 0x00
        .4byte gWonderMailCancel
        .byte 0x0a, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x0a, 0x00, 0x00, 0x00

        .global gWonderMailDeleteAllMail @ 80DDA14
        gWonderMailDeleteAllMail:
        .string "Delete All Mail\0"
        .align 2,0

        .global gWonderMailDeleteAOKMail @ 80DDA24
        gWonderMailDeleteAOKMail:
        .string "Delete A-OK Mail\0"
        .align 2,0

        .global gWonderMailDeleteSOSMail @ 80DDA38
        gWonderMailDeleteSOSMail:
        .string "Delete SOS Mail\0"
        .align 2,0

	.global gUnknown_80DDA48
gUnknown_80DDA48: @ 80DDA48
@ Menu that shows up when you enter an incorrect Wonder Mail Password
@ replacing .incbin "baserom.gba", 0x000dda48, 0x1c
        .4byte gWonderMailYes
        .byte 0x08, 0x00, 0x00, 0x00
        .4byte gWonderMailCancel
        .byte 0x0a, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x0a, 0x00, 0x00, 0x00

        .global gWonderMailYes @ (80DDA60)
        gWonderMailYes:
        .string "Yes\0"
        .align 2,0

	.global gUnknown_80DDA64
gUnknown_80DDA64: @ 80DDA64
@ replacing .incbin "baserom.gba", 0x000dda64, 0x1c
        .4byte gWonderMailYes
        .byte 0x08, 0x00, 0x00, 0x00
        .4byte gWonderMailNo
        .byte 0x09, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x0a, 0x00, 0x00, 0x00

        .global gWonderMailNo @ (80DDA7C)
        gWonderMailNo:
        .string "No\0"
        .align 2,0

	.global gUnknown_80DDA80
gUnknown_80DDA80: @ 80DDA80
@ replacing .incbin "baserom.gba", 0x000dda80, 0x20
        .4byte gWonderMailYes
        .byte 0x08, 0x00, 0x00, 0x00
        .4byte gWonderMailNo
        .byte 0x09, 0x00, 0x00, 0x00
        .4byte gWonderMailCancel
        .byte 0x0a, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x0a, 0x00, 0x00, 0x00

	.global gUnknown_80DDAA0
gUnknown_80DDAA0: @ 80DDAA0
	.incbin "baserom.gba", 0xDDAA0, 0x2C

	.global gUnknown_80DDACC
gUnknown_80DDACC: @ 80DDACC
	.incbin "baserom.gba", 0xDDACC, 0x18

	.global gUnknown_80DDAE4
gUnknown_80DDAE4: @ 80DDAE4
	.incbin "baserom.gba", 0xDDAE4, 0x18

	.global gUnknown_80DDAFC
gUnknown_80DDAFC: @ 80DDAFC
	.incbin "baserom.gba", 0xDDAFC, 0x28

	.global gUnknown_80DDB24
gUnknown_80DDB24: @ 80DDB24
	.incbin "baserom.gba", 0xDDB24, 0x3C

	.global gUnknown_80DDB60
gUnknown_80DDB60: @ 80DDB60
	.incbin "baserom.gba", 0xDDB60, 0x48

	.include "data/text/wonder_mail_1.inc"

	.global gUnknown_80DED44
gUnknown_80DED44: @ 80DED44
        @ replacing .incbin "baserom.gba", 0x000ded44, 0x4
        .byte 0x01, 0x00, 0x00, 0x00

	.global gUnknown_80DED48
gUnknown_80DED48: @ 80DED48
        @ replacing .incbin "baserom.gba", 0x000ded48, 0x18
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x03, 0x00, 0x00, 0x00
        .byte 0x15, 0x00, 0x04, 0x00
        .byte 0x06, 0x00, 0x05, 0x00
        .byte 0x05, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00

	.global gUnknown_80DED60
gUnknown_80DED60: @ 80DED60
        @ replacing .incbin "baserom.gba", 0x000ded60, 0x18
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x03, 0x00, 0x00, 0x00
        .byte 0x16, 0x00, 0x07, 0x00
        .byte 0x06, 0x00, 0x05, 0x00
        .byte 0x05, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00

	.global gUnknown_80DED78
gUnknown_80DED78: @ 80DED78
        @ replacing .incbin "baserom.gba", 0x000ded78, 0x40
        .byte 0x98, 0xed, 0x0d, 0x08 @ Pointer to Confirm
        .byte 0x0b, 0x00, 0x00, 0x00
        .byte 0x90, 0xed, 0x0d, 0x08 @ Pointer to Info
        .byte 0x0c, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .string "Info\0"
        .align 2,0
        .string "Confirm\0"
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x03, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00

	.global gUnknown_80DEDB8
gUnknown_80DEDB8: @ 80DEDB8
        @ replacing .incbin "baserom.gba", 0x000dedb8, 0x50
        .byte 0xf4, 0xed, 0x0d, 0x08 @ Pointer to Send Thank-You
        .byte 0x01, 0x00, 0x00, 0x00
        .byte 0xe0, 0xed, 0x0d, 0x08 @ Pointer to Get Thank-You
        .byte 0x02, 0x00, 0x00, 0x00
        .byte 0xd8, 0xed, 0x0d, 0x08 @ Pointer to Cancel
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .string "Cancel\0"
        .align 2,0
        .string "Get Thank-You Mail\0"
        .align 2,0
        .string "Send Thank-You Mail\0"
        .align 2,0

	.global gUnknown_80DEE08
gUnknown_80DEE08: @ 80DEE08
        @ Thank You Mail Pelipper Menu
        @ replacing .incbin "baserom.gba", 0x000dee08, 0x3c
        .byte 0x34, 0xee, 0x0d, 0x08 @ Pointer to Game Link cable
        .byte 0x03, 0x00, 0x00, 0x00
        .byte 0x28, 0xee, 0x0d, 0x08 @ Pointer to Password
        .byte 0x05, 0x00, 0x00, 0x00
        .byte 0xd8, 0xed, 0x0d, 0x08 @ Pointer to Cancel
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .string "Password\0"
        .align 2,0
        .string "Game Link cable\0"
        .align 2,0

	.global gUnknown_80DEE44
gUnknown_80DEE44: @ 80DEE44
        @ Game Link Cable Thank-You Mail Menu
        @ replacing .incbin "baserom.gba", 0x000dee44, 0x1c
        .byte 0x5c, 0xee, 0x0d, 0x08 @ Pointer to Yes
        .byte 0x07, 0x00, 0x00, 0x00
        .byte 0xd8, 0xed, 0x0d, 0x08 @ Pointer to Cancel
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .string "Yes\0"
        .align 2,0

	.global gUnknown_80DEE60
gUnknown_80DEE60: @ 80DEE60
        @ replacing .incbin "baserom.gba", 0x000dee60, 0x1c
        .byte 0x5c, 0xee, 0x0d, 0x08 @ Pointer to Yes
        .byte 0x07, 0x00, 0x00, 0x00
        .byte 0x78, 0xee, 0x0d, 0x08 @ Pointer to No
        .byte 0x08, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .string "No\0"
        .align 2,0

	.global gUnknown_80DEE7C
gUnknown_80DEE7C: @ 80DEE7C
        @ replacing .incbin "baserom.gba", 0x000dee7c, 0x40
        .byte 0xb0, 0xee, 0x0d, 0x08 @ Pointer to Send Item
        .byte 0x09, 0x00, 0x00, 0x00
        .byte 0x9c, 0xee, 0x0d, 0x08 @ Pointer to Don't Send Item
        .byte 0x0a, 0x00, 0x00, 0x00
        .byte 0xd8, 0xed, 0x0d, 0x08 @ Pointer to Cancel
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .string "Don~27t Send Item\0"
        .align 2,0
        .string "Send Item\0"
        .align 2,0

	.global gUnknown_80DEEBC
gUnknown_80DEEBC: @ 80DEEBC
        @ replacing .incbin "baserom.gba", 0x000deebc, 0x28
        .byte 0xd4, 0xee, 0x0d, 0x08 @ Pointer to Send w/o Item
        .byte 0x0a, 0x00, 0x00, 0x00
        .byte 0xd8, 0xed, 0x0d, 0x08 @ Pointer to Cancel
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .string "Send w/o Item\0"
        .align 2,0

	.global gUnknown_80DEEE4
gUnknown_80DEEE4: @ 80DEEE4
        @ replacing .incbin "baserom.gba", 0x000deee4, 0x20
        .byte 0x5c, 0xee, 0x0d, 0x08 @ Pointer to Yes
        .byte 0x07, 0x00, 0x00, 0x00
        .byte 0x78, 0xee, 0x0d, 0x08 @ Pointer to No
        .byte 0x08, 0x00, 0x00, 0x00
        .byte 0xd8, 0xed, 0x0d, 0x08 @ Pointer to Cancel
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00


	.include "data/text/wonder_mail_2.inc"

	.global gUnknown_80DFBD0
gUnknown_80DFBD0: @ 80DFBD0
        .byte 0x00, 0x00, 0x00, 0x00

        .byte 0x03, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00

        .byte 0x00, 0x00, 0x00, 0x00


	.global gUnknown_80DFBE8
gUnknown_80DFBE8: @ 80DFBE8
@ replacing .incbin "baserom.gba", 0x000dfbe8, 0x4
        .byte 0x01, 0x00, 0x0c, 0x00

	.global gUnknown_80DFBEC
gUnknown_80DFBEC: @ 80DFBEC
@ replacing .incbin "baserom.gba", 0x000dfbec, 0x18
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x06, 0x00, 0x00, 0x00
        .byte 0x02, 0x00, 0x02, 0x00
        .byte 0x18, 0x00, 0x0e, 0x00
        .byte 0x0e, 0x00, 0x00, 0x00
        .byte 0xe8, 0xfb, 0x0d, 0x08


	.global gUnknown_80DFC04
gUnknown_80DFC04: @ 80DFC04
        .string "News List\0"
        .align 2,0
        .string "pksdir0\0"

	.global gUnknown_80DFC18
gUnknown_80DFC18: @ 80DFC18
        .byte 0x00, 0x00, 0x00, 0x00

        .byte 0x03, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00

        .byte 0x00, 0x00, 0x00, 0x00

        .byte 0x01, 0x00, 0x16, 0x00

	.global gUnknown_80DFC34
gUnknown_80DFC34: @ 80DFC34
        .byte 0x00, 0x00, 0x00, 0x00

        .byte 0x06, 0x00, 0x00, 0x00
        .byte 0x02, 0x00, 0x02, 0x00
        .byte 0x1A, 0x00, 0x10, 0x00
        .byte 0x10, 0x00, 0x00, 0x00

        .byte 0x30, 0xFC, 0x0D, 0x08

	.global gUnknown_80DFC4C
gUnknown_80DFC4C: @ 80DFC4C
        .string "She\0"

	.global gUnknown_80DFC50
gUnknown_80DFC50: @ 80DFC50
        .string "He\0"
        .align 2,0
        .string "pksdir0\0"

	.global gUnknown_80DFC5C
gUnknown_80DFC5C: @ 80DFC5C
@ replacing .incbin "baserom.gba", 0x000dfc5c, 0x18
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x03, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00

	.global gUnknown_80DFC74
gUnknown_80DFC74: @ 80DFC74
@ replacing .incbin "baserom.gba", 0x000dfc74, 0x18
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x06, 0x00, 0x00, 0x00
        .byte 0x02, 0x00, 0x02, 0x00
        .byte 0x18, 0x00, 0x0e, 0x00
        .byte 0x0e, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00

	.global gUnknown_80DFC8C
gUnknown_80DFC8C: @ 80DFC8C
        .string "Mailbox\0"
        .string "pksdir0\0"

	.global gUnknown_80DFC9C
gUnknown_80DFC9C: @ 80DFC9C
@ replacing .incbin "baserom.gba", 0x000dfc9c, 0x18
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x03, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00

	.global gUnknown_80DFCB4
gUnknown_80DFCB4: @ 80DFCB4
@ replacing .incbin "baserom.gba", 0x000dfcb4, 0x18
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x06, 0x00, 0x00, 0x00
        .byte 0x02, 0x00, 0x02, 0x00
        .byte 0x18, 0x00, 0x0e, 0x00
        .byte 0x0e, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00

	.global gUnknown_80DFCCC
gUnknown_80DFCCC: @ 80DFCCC
        .string "Bulletin Board\0"
        .align 2,0
        .string "pksdir0\0"

	.global gUnknown_80DFCE4
gUnknown_80DFCE4: @ 80DFCE4
@ replacing .incbin "baserom.gba", 0x000dfce4, 0x18
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x03, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00

	.global gUnknown_80DFCFC
gUnknown_80DFCFC: @ 80DFCFC
@ replacing .incbin "baserom.gba", 0x000dfcfc, 0x18
        .byte 0x00, 0x00
        .byte 0x00, 0x00
        .byte 0x06, 0x00
        .byte 0x00, 0x00
        .byte 0x02, 0x00
        .byte 0x02, 0x00
        .byte 0x18, 0x00
        .byte 0x0e, 0x00
        .byte 0x0e, 0x00
        .byte 0x00, 0x00
        .byte 0x00, 0x00
        .byte 0x00, 0x00

	.global gUnknown_80DFD14
gUnknown_80DFD14: @ 80DFD14
        .string "Job List\0"
        .align 2,0
        .string "pksdir0\0"

	.global gUnknown_80DFD28
gUnknown_80DFD28: @ 80DFD28
@ replacing .incbin "baserom.gba", 0x000dfd28, 0x18
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x03, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00

	.global gUnknown_80DFD40
gUnknown_80DFD40: @ 80DFD40
@ replacing .incbin "baserom.gba", 0x000dfd40, 0x18
        .byte 0x00, 0x00
        .byte 0x00, 0x00
        .byte 0x04, 0x00
        .byte 0x00, 0x00
        .byte 0x15, 0x00
        .byte 0x06, 0x00
        .byte 0x07, 0x00
        .byte 0x03, 0x00
        .byte 0x03, 0x00
        .byte 0x00, 0x00
        .byte 0x00, 0x00
        .byte 0x00, 0x00

	.global gUnknown_80DFD58
gUnknown_80DFD58: @ 80DFD58
@ replacing .incbin "baserom.gba", 0x000dfd58, 0x18
        .byte 0x00, 0x00
        .byte 0x00, 0x00
        .byte 0x04, 0x00
        .byte 0x00, 0x00
        .byte 0x15, 0x00
        .byte 0x0f, 0x00
        .byte 0x06, 0x00
        .byte 0x03, 0x00
        .byte 0x03, 0x00
        .byte 0x00, 0x00
        .byte 0x00, 0x00
        .byte 0x00, 0x00

	.global gUnknown_80DFD70
gUnknown_80DFD70: @ 80DFD70
        .string "Take Job\0"
        .align 2,0

	.global gUnknown_80DFD7C
gUnknown_80DFD7C: @ 80DFD7C
        .string "Suspend\0"
        .string "pksdir0\0"

	.global gUnknown_80DFD8C
gUnknown_80DFD8C: @ 80DFD8C
@ replacing .incbin "baserom.gba", 0x000dfd8c, 0x18
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x03, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00

	.global gUnknown_80DFDA4
gUnknown_80DFDA4: @ 80DFDA4
@ replacing .incbin "baserom.gba", 0x000dfda4, 0x18
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x06, 0x00, 0x00, 0x00
        .byte 0x02, 0x00, 0x02, 0x0
        .byte 0x18, 0x00, 0x0e, 0x00
        .byte 0x0e, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00

	.global gUnknown_80DFDBC
gUnknown_80DFDBC: @ 80DFDBC
	.string "RESCUE EVENT\0"
        .align 2,0
        .string "pksdir0\0"

	.global gUnknown_80DFDD4
gUnknown_80DFDD4: @ 80DFDD4
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x03, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x03, 0x00, 0x00, 0x00
        .byte 0x03, 0x00, 0x03, 0x00
        .byte 0x07, 0x00, 0x03, 0x00
        .byte 0x03, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00

	.global gUnknown_80DFE04
gUnknown_80DFE04: @ 80DFE04
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x03, 0x00, 0x00, 0x00
        .byte 0x15, 0x00, 0x06, 0x00
        .byte 0x07, 0x00, 0x03, 0x00
        .byte 0x03, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00

	.global gUnknown_80DFE1C
gUnknown_80DFE1C: @ 80DFE1C
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x03, 0x00, 0x00, 0x00
        .byte 0x15, 0x00, 0x0f, 0x00
        .byte 0x07, 0x00, 0x03, 0x00
        .byte 0x03, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x03, 0x00, 0x00, 0x00
        .byte 0x15, 0x00, 0x0f, 0x00
        .byte 0x06, 0x00, 0x03, 0x00
        .byte 0x03, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00

	.include "data/text/wonder_mail_3.inc"

	.global gUnknown_80E016C
gUnknown_80E016C: @ 80E016C
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x03, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00

	.include "data/text/wonder_mail_complete.inc"

	.global gUnknown_80E0248
gUnknown_80E0248: @ 80E0248
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x03, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x01, 0x00, 0x12, 0x00

	.global gUnknown_80E0264
gUnknown_80E0264: @ 80E0264
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x06, 0x00, 0x00, 0x00
        .byte 0x02, 0x00, 0x02, 0x00
        .byte 0x1a, 0x00, 0x10, 0x00
        .byte 0x10, 0x00, 0x00, 0x00
        .byte 0x60, 0x02, 0x0e, 0x08
        .byte 0x70, 0x6b, 0x73, 0x64
        .byte 0x69, 0x72, 0x30, 0x00

	.global gUnknown_80E0284
gUnknown_80E0284: @ 80E0284
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x03, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00

	.global gUnknown_80E029C
gUnknown_80E029C: @ 80E029C
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x03, 0x00, 0x00, 0x00
        .byte 0x03, 0x00, 0x03, 0x00
        .byte 0x07, 0x00, 0x03, 0x00
        .byte 0x03, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00

	.global gUnknown_80E02B4
gUnknown_80E02B4: @ 80E02B4
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x04, 0x00, 0x00, 0x00
        .byte 0x15, 0x00, 0x06, 0x00
        .byte 0x07, 0x00, 0x03, 0x00
        .byte 0x03, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00

	.global gUnknown_80E02CC
gUnknown_80E02CC: @ 80E02CC
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x04, 0x00, 0x00, 0x00
        .byte 0x15, 0x00, 0x0f, 0x00
        .byte 0x06, 0x00, 0x03, 0x00
        .byte 0x03, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00

	.global gUnknown_80E02E4
gUnknown_80E02E4: @ 80E02E4
        .string "Check Mail\0"
        .align 2,0

	.global gUnknown_80E02F0
gUnknown_80E02F0: @ 80E02F0
        .string "Job List\0"
        .align 2,0

	.global gUnknown_80E02FC
gUnknown_80E02FC: @ 80E02FC
        .string "PKMN News\0"
        .align 2,0

	.global gUnknown_80E0308
gUnknown_80E0308: @ 80E0308
        .string "Store\0"
        .align 2,0

	.global gUnknown_80E0310
gUnknown_80E0310: @ 80E0310
        .string "Read\0"
        .align 2,0

	.global gUnknown_80E0318
gUnknown_80E0318: @ 80E0318
        .string "Accepted\0"
        .align 2,0

	.global gUnknown_80E0324
gUnknown_80E0324: @ 80E0324
        .byte 0x2f, 0x00, 0x00, 0x00
        .string "pksdir0\0"

	.global gUnknown_80E0330
gUnknown_80E0330: @ 80E0330
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x03, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00

	.global gUnknown_80E0348
gUnknown_80E0348: @ 80E0348
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x03, 0x00, 0x00, 0x00
        .byte 0x03, 0x00, 0x03, 0x00
        .byte 0x07, 0x00, 0x03, 0x00
        .byte 0x03, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00

	.global gUnknown_80E0360
gUnknown_80E0360: @ 80E0360
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x04, 0x00, 0x00, 0x00
        .byte 0x15, 0x00, 0x06, 0x00
        .byte 0x07, 0x00, 0x03, 0x00
        .byte 0x03, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00

	.global gUnknown_80E0378
gUnknown_80E0378: @ 80E0378
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x04, 0x00, 0x00, 0x00
        .byte 0x15, 0x00, 0x0f, 0x00
        .byte 0x06, 0x00, 0x03, 0x00
        .byte 0x03, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00

	.global gUnknown_80E0390
gUnknown_80E0390: @ 80E0390
        .string "Bulletin Board\0"
        .align 2,0

	.global gUnknown_80E03A0
gUnknown_80E03A0: @ 80E03A0
        .string "Job List\0"
        .align 2,0

	.global gUnknown_80E03AC
gUnknown_80E03AC: @ 80E03AC
        .string "Accepted\0"
        .align 2,0

	.global gUnknown_80E03B8
gUnknown_80E03B8: @ 80E03B8
        .string "/\0"
        .align 2,0
        .string "pksdir0\0"

	.global gUnknown_80E03C4
gUnknown_80E03C4: @ 80E03C4
	.incbin "baserom.gba", 0xE03C4, 0x30

	.global gUnknown_80E03F4
gUnknown_80E03F4: @ 80E03F4
	.incbin "baserom.gba", 0xE03F4, 0x18

	.global gUnknown_80E040C
gUnknown_80E040C: @ 80E040C
        .string "Send\0"
        .align 2,0
        .string "pksdir0\0"

	.global gUnknown_80E041C
gUnknown_80E041C: @ 80E041C
	.incbin "baserom.gba", 0xE041C, 0x18

	.global gUnknown_80E0434
gUnknown_80E0434: @ 80E0434
	.incbin "baserom.gba", 0xE0434, 0x28

	.global gUnknown_80E045C
gUnknown_80E045C: @ 80E045C
	.incbin "baserom.gba", 0xE045C, 0x28

	.global gUnknown_80E0484
gUnknown_80E0484: @ 80E0484
	.incbin "baserom.gba", 0xE0484, 0x30

	.global gUnknown_80E04B4
gUnknown_80E04B4: @ 80E04B4
	.incbin "baserom.gba", 0xE04B4, 0x40

	.global gUnknown_80E04F4
gUnknown_80E04F4: @ 80E04F4
	.incbin "baserom.gba", 0xE04F4, 0xCC

	.global gUnknown_80E05C0
gUnknown_80E05C0: @ 80E05C0
	.incbin "baserom.gba", 0xE05C0, 0x3C

	.global gUnknown_80E05FC
gUnknown_80E05FC: @ 80E05FC
	.incbin "baserom.gba", 0xE05FC, 0x44

	.global gUnknown_80E0640
gUnknown_80E0640: @ 80E0640
	.incbin "baserom.gba", 0xE0640, 0x30

	.global gUnknown_80E0670
gUnknown_80E0670: @ 80E0670
	.incbin "baserom.gba", 0xE0670, 0x38

	.global gUnknown_80E06A8
gUnknown_80E06A8: @ 80E06A8
	.incbin "baserom.gba", 0xE06A8, 0x54

	.global gUnknown_80E06FC
gUnknown_80E06FC: @ 80E06FC
	.incbin "baserom.gba", 0xE06FC, 0x18

	.global gUnknown_80E0714
gUnknown_80E0714: @ 80E0714
	.incbin "baserom.gba", 0xE0714, 0x18

	.global gUnknown_80E072C
gUnknown_80E072C: @ 80E072C
	.incbin "baserom.gba", 0xE072C, 0x18

	.global gUnknown_80E0744
gUnknown_80E0744: @ 80E0744
        .string "Dungeons\0"
        .align 2,0

	.global gUnknown_80E0750
gUnknown_80E0750: @ 80E0750
        .byte 0x83, 0xC2, 0x00, 0x00

	.global gUnknown_80E0754
gUnknown_80E0754: @ 80E0754
        .byte 0x83, 0xC0, 0x00, 0x00
        .string "pksdir0\0"

	.global gUnknown_80E0760
gUnknown_80E0760: @ 80E0760
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x03, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00

	.global gUnknown_80E0778
gUnknown_80E0778: @ 80E0778
	.incbin "baserom.gba", 0xE0778, 0x60

	.global gUnknown_80E07D8
gUnknown_80E07D8: @ 80E07D8
	.incbin "baserom.gba", 0xE07D8, 0x14

	.global gUnknown_80E07EC
gUnknown_80E07EC: @ 80E07EC
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x03, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00

	.global gUnknown_80E0804
gUnknown_80E0804: @ 80E0804
	.incbin "baserom.gba", 0xE0804, 0x18

	.global gUnknown_80E081C
gUnknown_80E081C: @ 80E081C
        .string "Courses\0"
        .align 2,0

	.global gUnknown_80E0824
gUnknown_80E0824: @ 80E0824
	.incbin "baserom.gba", 0xE0824, 0x4

	.global gUnknown_80E0828
gUnknown_80E0828: @ 80E0828
	.incbin "baserom.gba", 0xE0828, 0x14

	.global gUnknown_80E083C
gUnknown_80E083C: @ 80E083C
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x03, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00

	.global gUnknown_80E0854
gUnknown_80E0854: @ 80E0854
	.incbin "baserom.gba", 0xE0854, 0x18

	.global gUnknown_80E086C
gUnknown_80E086C: @ 80E086C
	.incbin "baserom.gba", 0xE086C, 0x94

	.global gUnknown_80E0900
gUnknown_80E0900: @ 80E0900
	.incbin "baserom.gba", 0xE0900, 0x1C

	.global gUnknown_80E091C
gUnknown_80E091C: @ 80E091C
	.incbin "baserom.gba", 0xE091C, 0x18

	.global gUnknown_80E0934
gUnknown_80E0934: @ 80E0934
        .string "ID:\0"

	.global gUnknown_80E0938
gUnknown_80E0938: @ 80E0938
        .string "%-4d\0"
        .align 2,0
        .string "pksdir0\0"

	.global gUnknown_80E0948
gUnknown_80E0948: @ 80E0948
	.incbin "baserom.gba", 0xE0948, 0x20

	.global gUnknown_80E0968
gUnknown_80E0968: @ 80E0968
	.incbin "baserom.gba", 0xE0968, 0x28

	.global gUnknown_80E0990
gUnknown_80E0990: @ 80E0990
	.incbin "baserom.gba", 0xE0990, 0x18

	.global gUnknown_80E09A8
gUnknown_80E09A8: @ 80E09A8
	.incbin "baserom.gba", 0xE09A8, 0x18

	.global gUnknown_80E09C0
gUnknown_80E09C0: @ 80E09C0
	.incbin "baserom.gba", 0xE09C0, 0x18

	.global gUnknown_80E09D8
gUnknown_80E09D8: @ 80E09D8
	.incbin "baserom.gba", 0xE09D8, 0x34

	.global gUnknown_80E0A0C
gUnknown_80E0A0C: @ 80E0A0C
	.incbin "baserom.gba", 0xE0A0C, 0x3C

	.global gUnknown_80E0A48
gUnknown_80E0A48: @ 80E0A48
        @ Pelipper help menu (one not at the counter on the right)
	.incbin "baserom.gba", 0xE0A48, 0x74

	.global gUnknown_80E0ABC
gUnknown_80E0ABC: @ 80E0ABC
        @ Friend Rescue menu from help menu
        @ replacing .incbin "baserom.gba", 0x000e0abc, 0x80
        .byte 0x28, 0x0b, 0x0e, 0x08 @ Friend Rescue Info
        .byte 0x06, 0x00, 0x00, 0x00
        .byte 0x18, 0x0b, 0x0e, 0x08 @ Go rescue
        .byte 0x07, 0x00, 0x00, 0x00
        .byte 0x08, 0x0b, 0x0e, 0x08 @ Get help
        .byte 0x08, 0x00, 0x00, 0x00
        .byte 0xf4, 0x0a, 0x0e, 0x08 @ Deleting Mail Info
        .byte 0x09, 0x00, 0x00, 0x00
        .byte 0xec, 0x0a, 0x0e, 0x08 @ Exit
        .byte 0x05, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x05, 0x00, 0x00, 0x00
        .string "Exit\0"
        .align 2,0
        .string "Deleting Mail Info\0"
        .align 2,0
        .string "#C6Get help#R \0"
        .align 2,0
        .string "#C6Go rescue#R \0"
        .align 2,0
        .string "Friend Rescue Info\0"
        .align 2,0

	.global gUnknown_80E0B3C
gUnknown_80E0B3C: @ 80E0B3C
        @ Go Resuce menu from Peilipper help menu
        @ replacing .incbin "baserom.gba", 0x000e0b3c, 0x98
        .byte 0xc0, 0x0b, 0x0e, 0x08 @ Rescue Procedures
        .byte 0x0a, 0x00, 0x00, 0x00
        .byte 0xac, 0x0b, 0x0e, 0x08 @ Recieve SOS Mail
        .byte 0x0b, 0x00, 0x00, 0x00
        .byte 0x98, 0x0b, 0x0e, 0x08 @ Leave for Rescue
        .byte 0x0c, 0x00, 0x00, 0x00
        .byte 0x88, 0x0b, 0x0e, 0x08 @ Send A-OK Mail
        .byte 0x0d, 0x00, 0x00, 0x00
        .byte 0x74, 0x0b, 0x0e, 0x08 @ Get Thank You Mail
        .byte 0x0e, 0x00, 0x00, 0x00
        .byte 0xec, 0x0a, 0x0e, 0x08 @ Exit
        .byte 0x05, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x05, 0x00, 0x00, 0x00
        .string "Get Thank-You Mail\0"
        .align 2,0
        .string "Send A-OK Mail\0"
        .align 2,0
        .string "Leave for Rescue\0"
        .align 2,0
        .string "Receive SOS Mail\0"
        .align 2,0
        .string "Rescue Procedures\0"
        .align 2,0

	.global gUnknown_80E0BD4
gUnknown_80E0BD4: @ 80E0BD4
        @ Get help menu from Pelipper help menu
        @ replacing .incbin "baserom.gba", 0x000e0bd4, 0x78
        .byte 0x3c, 0x0c, 0x0e, 0x08 @ Getting Help
        .byte 0x0f, 0x00, 0x00, 0x00
        .byte 0x2c, 0x0c, 0x0e, 0x08 @ Send SOS Mail
        .byte 0x10, 0x00, 0x00, 0x00
        .byte 0x18, 0x0c, 0x0e, 0x08 @ Receive A-OK Mail
        .byte 0x11, 0x00, 0x00, 0x00
        .byte 0x04, 0x0c, 0x0e, 0x08 @ Send Thank-You Mail
        .byte 0x12, 0x00, 0x00, 0x00
        .byte 0xec, 0x0a, 0x0e, 0x08 @ Exit
        .byte 0x05, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x05, 0x00, 0x00, 0x00
        .string "Send Thank-You Mail\0"
        .align 2,0
        .string "Receive A-OK Mail\0"
        .align 2,0
        .string "Send SOS Mail\0"
        .align 2,0
        .string "Getting Help\0"
        .align 2,0


	.include "data/text/wonder_mail_4.inc"

	.global gUnknown_80E1EFC
gUnknown_80E1EFC: @ 80E1EFC
	.incbin "baserom.gba", 0xE1EFC, 0x1C

	.global gUnknown_80E1F18
gUnknown_80E1F18: @ 80E1F18
	.incbin "baserom.gba", 0xE1F18, 0x18

	.global gUnknown_80E1F30
gUnknown_80E1F30: @ 80E1F30
        .string "Objectives\0"
        .align 2,0

	.global gUnknown_80E1F3C
gUnknown_80E1F3C: @ 80E1F3C
        .string "%dF\0"

	.global gUnknown_80E1F40
gUnknown_80E1F40: @ 80E1F40
        .string "  Rescue #C6%s#R\0"
        .align 2,0

	.global gUnknown_80E1F54
gUnknown_80E1F54: @ 80E1F54
        .string "Just go!\0"
        .align 2,0

	.global gUnknown_80E1F60
gUnknown_80E1F60: @ 80E1F60
        .string "  Bring #C4%s#R\0"
        .align 2,0

	.global gUnknown_80E1F70
gUnknown_80E1F70: @ 80E1F70
        .string "  Find #C4%s#R\0"
        .align 2,0

	.global gUnknown_80E1F80
gUnknown_80E1F80: @ 80E1F80
        .string "  Escort to #C6%s#R\0"
        .align 2,0

	.global gUnknown_80E1F94
gUnknown_80E1F94: @ 80E1F94
        .string "#CW???#R\0"
        .align 2,0
        .string "pksdir0\0"

	.global gUnknown_80E1FA8
gUnknown_80E1FA8: @ 80E1FA8
	.incbin "baserom.gba", 0xE1FA8, 0x1C

	.global gUnknown_80E1FC4
gUnknown_80E1FC4: @ 80E1FC4
	.incbin "baserom.gba", 0xE1FC4, 0x18

	.global gUnknown_80E1FDC
gUnknown_80E1FDC: @ 80E1FDC
	.incbin "baserom.gba", 0xE1FDC, 0x14

	.global gUnknown_80E1FF0
gUnknown_80E1FF0: @ 80E1FF0
	.incbin "baserom.gba", 0xE1FF0, 0x18

	.global gUnknown_80E2008
gUnknown_80E2008: @ 80E2008
	.incbin "baserom.gba", 0xE2008, 0x18

	.global gUnknown_80E2020
gUnknown_80E2020: @ 80E2020
        .string "Adventure Log\0"
        .align 2,0

	.global gUnknown_80E2030
gUnknown_80E2030: @ 80E2030
        @ Probably some sort of placeholder
        .string "~95~95~95~95~95~95~95~95~95~95~95~95~95~95~95 \0"
        .align 2,0
        .string "pksdir0\0"

	.global gUnknown_80E2068
gUnknown_80E2068: @ 80E2068
	.incbin "baserom.gba", 0xE2068, 0x50

	.global gUnknown_80E20B8
gUnknown_80E20B8: @ 80E20B8
	.incbin "baserom.gba", 0xE20B8, 0x28

	.global gUnknown_80E20E0
gUnknown_80E20E0: @ 80E20E0
	.incbin "baserom.gba", 0xE20E0, 0x28

	.global gUnknown_80E2108
gUnknown_80E2108: @ 80E2108
	.incbin "baserom.gba", 0xE2108, 0x28

	.global gUnknown_80E2130
gUnknown_80E2130: @ 80E2130
        @ Friend Resuce Pelipper Menu
	.incbin "baserom.gba", 0xE2130, 0x60

	.global gUnknown_80E2190
gUnknown_80E2190: @ 80E2190
	.incbin "baserom.gba", 0xE2190, 0x28

	.global gUnknown_80E21B8
gUnknown_80E21B8: @ 80E21B8
	.incbin "baserom.gba", 0xE21B8, 0x60

	.global gUnknown_80E2218
gUnknown_80E2218: @ 80E2218
	.incbin "baserom.gba", 0xE2218, 0x28

	.global gUnknown_80E2240
gUnknown_80E2240: @ 80E2240
	.incbin "baserom.gba", 0xE2240, 0x28

	.global gUnknown_80E2268
gUnknown_80E2268: @ 80E2268
	.incbin "baserom.gba", 0xE2268, 0x28

	.global gUnknown_80E2290
gUnknown_80E2290: @ 80E2290
	.incbin "baserom.gba", 0xE2290, 0x24

	.global gUnknown_80E22B4
gUnknown_80E22B4: @ 80E22B4
	.incbin "baserom.gba", 0xE22B4, 0x1C

	.global gUnknown_80E22D0
gUnknown_80E22D0: @ 80E22D0
	.incbin "baserom.gba", 0xE22D0, 0x20

	.global gUnknown_80E22F0
gUnknown_80E22F0: @ 80E22F0
	.incbin "baserom.gba", 0xE22F0, 0x2C

	.global gUnknown_80E231C
gUnknown_80E231C: @ 80E231C
	.incbin "baserom.gba", 0xE231C, 0x18

	.global gUnknown_80E2334
gUnknown_80E2334: @ 80E2334
	.incbin "baserom.gba", 0xE2334, 0x18

	.global gUnknown_80E234C
gUnknown_80E234C: @ 80E234C
	.incbin "baserom.gba", 0xE234C, 0x20

	.global gUnknown_80E236C
gUnknown_80E236C: @ 80E236C
	.incbin "baserom.gba", 0xE236C, 0x3C

	.global gUnknown_80E23A8
gUnknown_80E23A8: @ 80E23A8
	.incbin "baserom.gba", 0xE23A8, 0x48

	.global gUnknown_80E23F0
gUnknown_80E23F0: @ 80E23F0
	.incbin "baserom.gba", 0xE23F0, 0x18

	.global gUnknown_80E2408
gUnknown_80E2408: @ 80E2408
	.incbin "baserom.gba", 0xE2408, 0x38

	.global gUnknown_80E2440
gUnknown_80E2440: @ 80E2440
	.incbin "baserom.gba", 0xE2440, 0x18

	.global gUnknown_80E2458
gUnknown_80E2458: @ 80E2458
	.incbin "baserom.gba", 0xE2458, 0x18

	.global gUnknown_80E2470
gUnknown_80E2470: @ 80E2470
	.incbin "baserom.gba", 0xE2470, 0x40

	.global gUnknown_80E24B0
gUnknown_80E24B0: @ 80E24B0
	.incbin "baserom.gba", 0xE24B0, 0x28

	.global gUnknown_80E24D8
gUnknown_80E24D8: @ 80E24D8
	.incbin "baserom.gba", 0xE24D8, 0x20

	.global gUnknown_80E24F8
gUnknown_80E24F8: @ 80E24F8
	.incbin "baserom.gba", 0xE24F8, 0x5C

	.global gUnknown_80E2554
gUnknown_80E2554: @ 80E2554
	.incbin "baserom.gba", 0xE2554, 0x60

	.global gUnknown_80E25B4
gUnknown_80E25B4: @ 80E25B4
	.incbin "baserom.gba", 0xE25B4, 0x40

	.global gUnknown_80E25F4
gUnknown_80E25F4: @ 80E25F4
        .string "What would you like to do?\0"
        .align 2,0

	.global gUnknown_80E2610
gUnknown_80E2610: @ 80E2610
	.incbin "baserom.gba", 0xE2610, 0x30

	.global gUnknown_80E2640
gUnknown_80E2640: @ 80E2640
	.incbin "baserom.gba", 0xE2640, 0x40

	.global gUnknown_80E2680
gUnknown_80E2680: @ 80E2680
	.incbin "baserom.gba", 0xE2680, 0x30

	.global gUnknown_80E26B0
gUnknown_80E26B0: @ 80E26B0
	.incbin "baserom.gba", 0xE26B0, 0x40

	.global gUnknown_80E26F0
gUnknown_80E26F0: @ 80E26F0
	.incbin "baserom.gba", 0xE26F0, 0x38

	.global gUnknown_80E2728
gUnknown_80E2728: @ 80E2728
	.incbin "baserom.gba", 0xE2728, 0x44

	.global gUnknown_80E276C
gUnknown_80E276C: @ 80E276C
	.incbin "baserom.gba", 0xE276C, 0x38

	.global gUnknown_80E27A4
gUnknown_80E27A4: @ 80E27A4
	.incbin "baserom.gba", 0xE27A4, 0x70

	.global gUnknown_80E2814
gUnknown_80E2814: @ 80E2814
	.incbin "baserom.gba", 0xE2814, 0x2C

	.global gUnknown_80E2840
gUnknown_80E2840: @ 80E2840
	.incbin "baserom.gba", 0xE2840, 0x34

	.global gUnknown_80E2874
gUnknown_80E2874: @ 80E2874
	.incbin "baserom.gba", 0xE2874, 0x24

	.global gUnknown_80E2898
gUnknown_80E2898: @ 80E2898
	.incbin "baserom.gba", 0xE2898, 0x40

	.global gUnknown_80E28D8
gUnknown_80E28D8: @ 80E28D8
	.incbin "baserom.gba", 0xE28D8, 0x2C

	.global gUnknown_80E2904
gUnknown_80E2904: @ 80E2904
	.incbin "baserom.gba", 0xE2904, 0x68

	.global gUnknown_80E296C
gUnknown_80E296C: @ 80E296C
	.incbin "baserom.gba", 0xE296C, 0x34

	.global gUnknown_80E29A0
gUnknown_80E29A0: @ 80E29A0
	.incbin "baserom.gba", 0xE29A0, 0x30

	.global gUnknown_80E29D0
gUnknown_80E29D0: @ 80E29D0
	.incbin "baserom.gba", 0xE29D0, 0x3C

	.global gUnknown_80E2A0C
gUnknown_80E2A0C: @ 80E2A0C
	.incbin "baserom.gba", 0xE2A0C, 0x10

	.global gUnknown_80E2A1C
gUnknown_80E2A1C: @ 80E2A1C
	.incbin "baserom.gba", 0xE2A1C, 0x40

	.global gUnknown_80E2A5C
gUnknown_80E2A5C: @ 80E2A5C
	.incbin "baserom.gba", 0xE2A5C, 0x24

	.global gUnknown_80E2A80
gUnknown_80E2A80: @ 80E2A80
	.incbin "baserom.gba", 0xE2A80, 0x28

	.global gUnknown_80E2AA8
gUnknown_80E2AA8: @ 80E2AA8
	.incbin "baserom.gba", 0xE2AA8, 0x3C

	.global gUnknown_80E2AE4
gUnknown_80E2AE4: @ 80E2AE4
	.incbin "baserom.gba", 0xE2AE4, 0x70

	.global gUnknown_80E2B54
gUnknown_80E2B54: @ 80E2B54
	.incbin "baserom.gba", 0xE2B54, 0x3C

	.global gUnknown_80E2B90
gUnknown_80E2B90: @ 80E2B90
	.incbin "baserom.gba", 0xE2B90, 0x50

	.global gUnknown_80E2BE0
gUnknown_80E2BE0: @ 80E2BE0
	.incbin "baserom.gba", 0xE2BE0, 0x68

	.global gUnknown_80E2C48
gUnknown_80E2C48: @ 80E2C48
	.incbin "baserom.gba", 0xE2C48, 0x4C

	.global gUnknown_80E2C94
gUnknown_80E2C94: @ 80E2C94
	.incbin "baserom.gba", 0xE2C94, 0x40

	.global gUnknown_80E2CD4
gUnknown_80E2CD4: @ 80E2CD4
	.incbin "baserom.gba", 0xE2CD4, 0x14

	.global gUnknown_80E2CE8
gUnknown_80E2CE8: @ 80E2CE8
	.incbin "baserom.gba", 0xE2CE8, 0x48

	.global gUnknown_80E2D30
gUnknown_80E2D30: @ 80E2D30
	.incbin "baserom.gba", 0xE2D30, 0x30

	.global gUnknown_80E2D60
gUnknown_80E2D60: @ 80E2D60
	.incbin "baserom.gba", 0xE2D60, 0x1C

	.global gUnknown_80E2D7C
gUnknown_80E2D7C: @ 80E2D7C
	.incbin "baserom.gba", 0xE2D7C, 0x54

	.global gUnknown_80E2DD0
gUnknown_80E2DD0: @ 80E2DD0
	.incbin "baserom.gba", 0xE2DD0, 0x50

	.global gUnknown_80E2E20
gUnknown_80E2E20: @ 80E2E20
	.incbin "baserom.gba", 0xE2E20, 0x34

	.global gUnknown_80E2E54
gUnknown_80E2E54: @ 80E2E54
	.incbin "baserom.gba", 0xE2E54, 0x60

	.global gUnknown_80E2EB4
gUnknown_80E2EB4: @ 80E2EB4
	.incbin "baserom.gba", 0xE2EB4, 0x60

	.global gUnknown_80E2F14
gUnknown_80E2F14: @ 80E2F14
	.incbin "baserom.gba", 0xE2F14, 0x30

	.global gUnknown_80E2F44
gUnknown_80E2F44: @ 80E2F44
	.incbin "baserom.gba", 0xE2F44, 0x34

	.global gUnknown_80E2F78
gUnknown_80E2F78: @ 80E2F78
	.incbin "baserom.gba", 0xE2F78, 0x28

	.global gUnknown_80E2FA0
gUnknown_80E2FA0: @ 80E2FA0
	.incbin "baserom.gba", 0xE2FA0, 0x4C

	.global gUnknown_80E2FEC
gUnknown_80E2FEC: @ 80E2FEC
	.incbin "baserom.gba", 0xE2FEC, 0x44

	.global gUnknown_80E3030
gUnknown_80E3030: @ 80E3030
	.incbin "baserom.gba", 0xE3030, 0x48

	.global gUnknown_80E3078
gUnknown_80E3078: @ 80E3078
	.incbin "baserom.gba", 0xE3078, 0x2C

	.global gUnknown_80E30A4
gUnknown_80E30A4: @ 80E30A4
	.incbin "baserom.gba", 0xE30A4, 0x2C

	.global gUnknown_80E30D0
gUnknown_80E30D0: @ 80E30D0
	.incbin "baserom.gba", 0xE30D0, 0x4C

	.global gUnknown_80E311C
gUnknown_80E311C: @ 80E311C
	.incbin "baserom.gba", 0xE311C, 0x30

	.global gUnknown_80E314C
gUnknown_80E314C: @ 80E314C
	.incbin "baserom.gba", 0xE314C, 0x30

	.global gUnknown_80E317C
gUnknown_80E317C: @ 80E317C
	.incbin "baserom.gba", 0xE317C, 0x20

	.global gUnknown_80E319C
gUnknown_80E319C: @ 80E319C
	.incbin "baserom.gba", 0xE319C, 0x3C

	.global gUnknown_80E31D8
gUnknown_80E31D8: @ 80E31D8
	.incbin "baserom.gba", 0xE31D8, 0x24

	.global gUnknown_80E31FC
gUnknown_80E31FC: @ 80E31FC
	.incbin "baserom.gba", 0xE31FC, 0x24

	.global gUnknown_80E3220
gUnknown_80E3220: @ 80E3220
	.incbin "baserom.gba", 0xE3220, 0x28

	.global gUnknown_80E3248
gUnknown_80E3248: @ 80E3248
	.incbin "baserom.gba", 0xE3248, 0x40

	.global gUnknown_80E3288
gUnknown_80E3288: @ 80E3288
	.incbin "baserom.gba", 0xE3288, 0x3C

	.global gUnknown_80E32C4
gUnknown_80E32C4: @ 80E32C4
	.incbin "baserom.gba", 0xE32C4, 0x58

	.global gUnknown_80E331C
gUnknown_80E331C: @ 80E331C
	.incbin "baserom.gba", 0xE331C, 0x5C

	.global gUnknown_80E3378
gUnknown_80E3378: @ 80E3378
	.incbin "baserom.gba", 0xE3378, 0x24

	.global gUnknown_80E339C
gUnknown_80E339C: @ 80E339C
	.incbin "baserom.gba", 0xE339C, 0x3C

	.global gUnknown_80E33D8
gUnknown_80E33D8: @ 80E33D8
	.incbin "baserom.gba", 0xE33D8, 0x58

	.global gUnknown_80E3430
gUnknown_80E3430: @ 80E3430
	.incbin "baserom.gba", 0xE3430, 0x80

	.global gUnknown_80E34B0
gUnknown_80E34B0: @ 80E34B0
	.incbin "baserom.gba", 0xE34B0, 0x40

	.global gUnknown_80E34F0
gUnknown_80E34F0: @ 80E34F0
	.incbin "baserom.gba", 0xE34F0, 0x3C

	.global gUnknown_80E352C
gUnknown_80E352C: @ 80E352C
	.incbin "baserom.gba", 0xE352C, 0x30

	.global gUnknown_80E355C
gUnknown_80E355C: @ 80E355C
	.incbin "baserom.gba", 0xE355C, 0x50

	.global gUnknown_80E35AC
gUnknown_80E35AC: @ 80E35AC
	.incbin "baserom.gba", 0xE35AC, 0x3C

	.global gUnknown_80E35E8
gUnknown_80E35E8: @ 80E35E8
	.incbin "baserom.gba", 0xE35E8, 0x24

	.global gUnknown_80E360C
gUnknown_80E360C: @ 80E360C
	.incbin "baserom.gba", 0xE360C, 0x38

	.global gUnknown_80E3644
gUnknown_80E3644: @ 80E3644
	.incbin "baserom.gba", 0xE3644, 0x38

	.global gUnknown_80E367C
gUnknown_80E367C: @ 80E367C
	.incbin "baserom.gba", 0xE367C, 0x14

	.global gUnknown_80E3690
gUnknown_80E3690: @ 80E3690
	.incbin "baserom.gba", 0xE3690, 0x188

	.global gUnknown_80E3818
gUnknown_80E3818: @ 80E3818
	.incbin "baserom.gba", 0xE3818, 0x180

	.global gUnknown_80E3998
gUnknown_80E3998: @ 80E3998
	.incbin "baserom.gba", 0xE3998, 0x184

	.global gUnknown_80E3B1C
gUnknown_80E3B1C: @ 80E3B1C
	.incbin "baserom.gba", 0xE3B1C, 0xDC

	.global gUnknown_80E3BF8
gUnknown_80E3BF8: @ 80E3BF8
	.incbin "baserom.gba", 0xE3BF8, 0x1EC

	.global gUnknown_80E3DE4
gUnknown_80E3DE4: @ 80E3DE4
	.incbin "baserom.gba", 0xE3DE4, 0xB4

	.global gUnknown_80E3E98
gUnknown_80E3E98: @ 80E3E98
	.incbin "baserom.gba", 0xE3E98, 0x17C

	.global gUnknown_80E4014
gUnknown_80E4014: @ 80E4014
	.incbin "baserom.gba", 0xE4014, 0x11C

	.global gUnknown_80E4130
gUnknown_80E4130: @ 80E4130
	.incbin "baserom.gba", 0xE4130, 0xAC

	.global gUnknown_80E41DC
gUnknown_80E41DC: @ 80E41DC
	.incbin "baserom.gba", 0xE41DC, 0x138

	.global gUnknown_80E4314
gUnknown_80E4314: @ 80E4314
	.incbin "baserom.gba", 0xE4314, 0x16C

	.global gUnknown_80E4480
gUnknown_80E4480: @ 80E4480
	.incbin "baserom.gba", 0xE4480, 0x24

	.global gUnknown_80E44A4
gUnknown_80E44A4: @ 80E44A4
	.incbin "baserom.gba", 0xE44A4, 0x5C

	.global gUnknown_80E4500
gUnknown_80E4500: @ 80E4500
	.incbin "baserom.gba", 0xE4500, 0x50

	.global gUnknown_80E4550
gUnknown_80E4550: @ 80E4550
	.incbin "baserom.gba", 0xE4550, 0x64

	.global gUnknown_80E45B4
gUnknown_80E45B4: @ 80E45B4
	.incbin "baserom.gba", 0xE45B4, 0x58

	.global gUnknown_80E460C
gUnknown_80E460C: @ 80E460C
	.incbin "baserom.gba", 0xE460C, 0x44

	.global gUnknown_80E4650
gUnknown_80E4650: @ 80E4650
	.incbin "baserom.gba", 0xE4650, 0x3C

	.global gUnknown_80E468C
gUnknown_80E468C: @ 80E468C
	.incbin "baserom.gba", 0xE468C, 0x3C

	.global gUnknown_80E46C8
gUnknown_80E46C8: @ 80E46C8
	.incbin "baserom.gba", 0xE46C8, 0x3C

	.global gUnknown_80E4704
gUnknown_80E4704: @ 80E4704
	.incbin "baserom.gba", 0xE4704, 0x40

	.global gUnknown_80E4744
gUnknown_80E4744: @ 80E4744
	.incbin "baserom.gba", 0xE4744, 0x44

	.global gUnknown_80E4788
gUnknown_80E4788: @ 80E4788
	.incbin "baserom.gba", 0xE4788, 0x50

	.global gUnknown_80E47D8
gUnknown_80E47D8: @ 80E47D8
	.incbin "baserom.gba", 0xE47D8, 0x54

	.global gUnknown_80E482C
gUnknown_80E482C: @ 80E482C
	.incbin "baserom.gba", 0xE482C, 0x7C

	.global gUnknown_80E48A8
gUnknown_80E48A8: @ 80E48A8
	.incbin "baserom.gba", 0xE48A8, 0x40

	.global gUnknown_80E48E8
gUnknown_80E48E8: @ 80E48E8
	.incbin "baserom.gba", 0xE48E8, 0x40

	.global gUnknown_80E4928
gUnknown_80E4928: @ 80E4928
	.incbin "baserom.gba", 0xE4928, 0x3C

	.global gUnknown_80E4964
gUnknown_80E4964: @ 80E4964
	.incbin "baserom.gba", 0xE4964, 0x38

	.global gUnknown_80E499C
gUnknown_80E499C: @ 80E499C
	.incbin "baserom.gba", 0xE499C, 0x28

	.global gUnknown_80E49C4
gUnknown_80E49C4: @ 80E49C4
	.incbin "baserom.gba", 0xE49C4, 0x4C

	.global gUnknown_80E4A10
gUnknown_80E4A10: @ 80E4A10
	.incbin "baserom.gba", 0xE4A10, 0x18

	.global gUnknown_80E4A28
gUnknown_80E4A28: @ 80E4A28
	.incbin "baserom.gba", 0xE4A28, 0x18

	.global gCreditsTable
gCreditsTable: @ 80E4A40
	.incbin "baserom.gba", 0xE4A40, 0xEDC

	.global gUnknown_80E591C
gUnknown_80E591C: @ 80E591C
	.incbin "baserom.gba", 0xE591C, 0x74

	.global gUnknown_80E5990
gUnknown_80E5990: @ 80E5990
	.incbin "baserom.gba", 0xE5990, 0x18

	.global gUnknown_80E59A8
gUnknown_80E59A8: @ 80E59A8
	.incbin "baserom.gba", 0xE59A8, 0x20

	.global gUnknown_80E59C8
gUnknown_80E59C8: @ 80E59C8
	.incbin "baserom.gba", 0xE59C8, 0x18

	.global gUnknown_80E59E0
gUnknown_80E59E0: @ 80E59E0
	.incbin "baserom.gba", 0xE59E0, 0x18

	.global gUnknown_80E59F8
gUnknown_80E59F8: @ 80E59F8
	.incbin "baserom.gba", 0xE59F8, 0x68

	.global gUnknown_80E5A60
gUnknown_80E5A60: @ 80E5A60
	.incbin "baserom.gba", 0xE5A60, 0x18

	.global gUnknown_80E5A78
gUnknown_80E5A78: @ 80E5A78
	.incbin "baserom.gba", 0xE5A78, 0x18

	.global gUnknown_80E5A90
gUnknown_80E5A90: @ 80E5A90
	.incbin "baserom.gba", 0xE5A90, 0x6C

	.global gUnknown_80E5AFC
gUnknown_80E5AFC: @ 80E5AFC
	.incbin "baserom.gba", 0xE5AFC, 0x38

	.global gUnknown_80E5B34
gUnknown_80E5B34: @ 80E5B34
	.incbin "baserom.gba", 0xE5B34, 0x18

	.global gUnknown_80E5B4C
gUnknown_80E5B4C: @ 80E5B4C
	.incbin "baserom.gba", 0xE5B4C, 0x40

	.global gUnknown_80E5B8C
gUnknown_80E5B8C: @ 80E5B8C
	.incbin "baserom.gba", 0xE5B8C, 0x38

	.global gUnknown_80E5BC4
gUnknown_80E5BC4: @ 80E5BC4
	.incbin "baserom.gba", 0xE5BC4, 0x18

	.global gUnknown_80E5BDC
gUnknown_80E5BDC: @ 80E5BDC
	.incbin "baserom.gba", 0xE5BDC, 0x3C

	.global gUnknown_80E5C18
gUnknown_80E5C18: @ 80E5C18
	.incbin "baserom.gba", 0xE5C18, 0x9C

	.global gUnknown_80E5CB4
gUnknown_80E5CB4: @ 80E5CB4
	.incbin "baserom.gba", 0xE5CB4, 0x18

	.global gUnknown_80E5CCC
gUnknown_80E5CCC: @ 80E5CCC
	.incbin "baserom.gba", 0xE5CCC, 0x40

	.global gUnknown_80E5D0C
gUnknown_80E5D0C: @ 80E5D0C
	.incbin "baserom.gba", 0xE5D0C, 0x3C

	.global gUnknown_80E5D48
gUnknown_80E5D48: @ 80E5D48
	.incbin "baserom.gba", 0xE5D48, 0x58

	.global gUnknown_80E5DA0
gUnknown_80E5DA0: @ 80E5DA0
	.incbin "baserom.gba", 0xE5DA0, 0x50

	.global gUnknown_80E5DF0
gUnknown_80E5DF0: @ 80E5DF0
	.incbin "baserom.gba", 0xE5DF0, 0x6C

	.global gUnknown_80E5E5C
gUnknown_80E5E5C: @ 80E5E5C
	.incbin "baserom.gba", 0xE5E5C, 0x60

	.global gUnknown_80E5EBC
gUnknown_80E5EBC: @ 80E5EBC
	.incbin "baserom.gba", 0xE5EBC, 0x60

	.global gUnknown_80E5F1C
gUnknown_80E5F1C: @ 80E5F1C
	.incbin "baserom.gba", 0xE5F1C, 0x64

	.global gUnknown_80E5F80
gUnknown_80E5F80: @ 80E5F80
	.incbin "baserom.gba", 0xE5F80, 0x4C

	.global gUnknown_80E5FCC
gUnknown_80E5FCC: @ 80E5FCC
	.incbin "baserom.gba", 0xE5FCC, 0x64

	.global gUnknown_80E6030
gUnknown_80E6030: @ 80E6030
	.incbin "baserom.gba", 0xE6030, 0x70

	.global gUnknown_80E60A0
gUnknown_80E60A0: @ 80E60A0
	.incbin "baserom.gba", 0xE60A0, 0x34

	.global gUnknown_80E60D4
gUnknown_80E60D4: @ 80E60D4
	.incbin "baserom.gba", 0xE60D4, 0x18

	.global gUnknown_80E60EC
gUnknown_80E60EC: @ 80E60EC
	.incbin "baserom.gba", 0xE60EC, 0x18

	.global gUnknown_80E6104
gUnknown_80E6104: @ 80E6104
	.incbin "baserom.gba", 0xE6104, 0x50

	.global gUnknown_80E6154
gUnknown_80E6154: @ 80E6154
	.incbin "baserom.gba", 0xE6154, 0x20

	.global gUnknown_80E6174
gUnknown_80E6174: @ 80E6174
	.incbin "baserom.gba", 0xE6174, 0x18

	.global gUnknown_80E618C
gUnknown_80E618C: @ 80E618C
	.incbin "baserom.gba", 0xE618C, 0x18

	.global gUnknown_80E61A4
gUnknown_80E61A4: @ 80E61A4
	.incbin "baserom.gba", 0xE61A4, 0x1C

	.global gUnknown_80E61C0
gUnknown_80E61C0: @ 80E61C0
	.incbin "baserom.gba", 0xE61C0, 0x24

	.global gUnknown_80E61E4
gUnknown_80E61E4: @ 80E61E4
	.incbin "baserom.gba", 0xE61E4, 0x30

	.global gUnknown_80E6214
gUnknown_80E6214: @ 80E6214
	.incbin "baserom.gba", 0xE6214, 0x54

	.global gUnknown_80E6268
gUnknown_80E6268: @ 80E6268
	.incbin "baserom.gba", 0xE6268, 0x5C

	.global gUnknown_80E62C4
gUnknown_80E62C4: @ 80E62C4
	.incbin "baserom.gba", 0xE62C4, 0x50

	.global gUnknown_80E6314
gUnknown_80E6314: @ 80E6314
	.incbin "baserom.gba", 0xE6314, 0x44

	.global gUnknown_80E6358
gUnknown_80E6358: @ 80E6358
	.incbin "baserom.gba", 0xE6358, 0x20

	.global gUnknown_80E6378
gUnknown_80E6378: @ 80E6378
	.incbin "baserom.gba", 0xE6378, 0x24

	.global gUnknown_80E639C
gUnknown_80E639C: @ 80E639C
	.incbin "baserom.gba", 0xE639C, 0x5C

	.global gUnknown_80E63F8
gUnknown_80E63F8: @ 80E63F8
	.incbin "baserom.gba", 0xE63F8, 0x50

	.global gUnknown_80E6448
gUnknown_80E6448: @ 80E6448
	.incbin "baserom.gba", 0xE6448, 0x64

	.global gUnknown_80E64AC
gUnknown_80E64AC: @ 80E64AC
	.incbin "baserom.gba", 0xE64AC, 0x7C

	.global gUnknown_80E6528
gUnknown_80E6528: @ 80E6528
	.incbin "baserom.gba", 0xE6528, 0x14

	.global gUnknown_80E653C
gUnknown_80E653C: @ 80E653C
	.incbin "baserom.gba", 0xE653C, 0x18

	.global gUnknown_80E6554
gUnknown_80E6554: @ 80E6554
	.incbin "baserom.gba", 0xE6554, 0x18

	.global gUnknown_80E656C
gUnknown_80E656C: @ 80E656C
	.incbin "baserom.gba", 0xE656C, 0x6C

	.global gUnknown_80E65D8
gUnknown_80E65D8: @ 80E65D8
	.incbin "baserom.gba", 0xE65D8, 0x44

	.global gUnknown_80E661C
gUnknown_80E661C: @ 80E661C
	.incbin "baserom.gba", 0xE661C, 0x40

	.global gUnknown_80E665C
gUnknown_80E665C: @ 80E665C
	.incbin "baserom.gba", 0xE665C, 0x20

	.global gUnknown_80E667C
gUnknown_80E667C: @ 80E667C
	.incbin "baserom.gba", 0xE667C, 0x40

	.global gUnknown_80E66BC
gUnknown_80E66BC: @ 80E66BC
	.incbin "baserom.gba", 0xE66BC, 0x18

	.global gUnknown_80E66D4
gUnknown_80E66D4: @ 80E66D4
	.incbin "baserom.gba", 0xE66D4, 0x74

	.global gUnknown_80E6748
gUnknown_80E6748: @ 80E6748
	.incbin "baserom.gba", 0xE6748, 0x18

	.global gUnknown_80E6760
gUnknown_80E6760: @ 80E6760
	.incbin "baserom.gba", 0xE6760, 0x74

	.global gUnknown_80E67D4
gUnknown_80E67D4: @ 80E67D4
	.incbin "baserom.gba", 0xE67D4, 0x18

	.global gUnknown_80E67EC
gUnknown_80E67EC: @ 80E67EC
	.incbin "baserom.gba", 0xE67EC, 0xB0

	.global gUnknown_80E689C
gUnknown_80E689C: @ 80E689C
	.incbin "baserom.gba", 0xE689C, 0x18

	.global gUnknown_80E68B4
gUnknown_80E68B4: @ 80E68B4
	.incbin "baserom.gba", 0xE68B4, 0x84

	.global gUnknown_80E6938
gUnknown_80E6938: @ 80E6938
	.incbin "baserom.gba", 0xE6938, 0x18

	.global gUnknown_80E6950
gUnknown_80E6950: @ 80E6950
	.incbin "baserom.gba", 0xE6950, 0x60

	.global gUnknown_80E69B0
gUnknown_80E69B0: @ 80E69B0
	.incbin "baserom.gba", 0xE69B0, 0x18

	.global gUnknown_80E69C8
gUnknown_80E69C8: @ 80E69C8
	.incbin "baserom.gba", 0xE69C8, 0x48

	.global gUnknown_80E6A10
gUnknown_80E6A10: @ 80E6A10
	.incbin "baserom.gba", 0xE6A10, 0x18

	.global gUnknown_80E6A28
gUnknown_80E6A28: @ 80E6A28
	.incbin "baserom.gba", 0xE6A28, 0x4C

	.global gUnknown_80E6A74
gUnknown_80E6A74: @ 80E6A74
	.incbin "baserom.gba", 0xE6A74, 0x18

	.global gUnknown_80E6A8C
gUnknown_80E6A8C: @ 80E6A8C
	.incbin "baserom.gba", 0xE6A8C, 0xEC

	.global gUnknown_80E6B78
gUnknown_80E6B78: @ 80E6B78
	.incbin "baserom.gba", 0xE6B78, 0x18

	.global gUnknown_80E6B90
gUnknown_80E6B90: @ 80E6B90
	.incbin "baserom.gba", 0xE6B90, 0x64

	.global gUnknown_80E6BF4
gUnknown_80E6BF4: @ 80E6BF4
	.incbin "baserom.gba", 0xE6BF4, 0x18

	.global gUnknown_80E6C0C
gUnknown_80E6C0C: @ 80E6C0C
	.incbin "baserom.gba", 0xE6C0C, 0x44

	.global gUnknown_80E6C50
gUnknown_80E6C50: @ 80E6C50
	.incbin "baserom.gba", 0xE6C50, 0x18

	.global gUnknown_80E6C68
gUnknown_80E6C68: @ 80E6C68
	.incbin "baserom.gba", 0xE6C68, 0x68

	.global gUnknown_80E6CD0
gUnknown_80E6CD0: @ 80E6CD0
	.incbin "baserom.gba", 0xE6CD0, 0x18

	.global gUnknown_80E6CE8
gUnknown_80E6CE8: @ 80E6CE8
	.incbin "baserom.gba", 0xE6CE8, 0x6C

	.global gUnknown_80E6D54
gUnknown_80E6D54: @ 80E6D54
	.incbin "baserom.gba", 0xE6D54, 0x18

	.global gUnknown_80E6D6C
gUnknown_80E6D6C: @ 80E6D6C
	.incbin "baserom.gba", 0xE6D6C, 0x70

	.global gUnknown_80E6DDC
gUnknown_80E6DDC: @ 80E6DDC
	.incbin "baserom.gba", 0xE6DDC, 0x18

	.global gUnknown_80E6DF4
gUnknown_80E6DF4: @ 80E6DF4
	.incbin "baserom.gba", 0xE6DF4, 0x5C

        .include "data/text/chunsoft.inc"

	.global gUnknown_80E6E7C
gUnknown_80E6E7C: @ 80E6E7C
	.incbin "baserom.gba", 0xE6E7C, 0x18

	.global gUnknown_80E6E94
gUnknown_80E6E94: @ 80E6E94
	.incbin "baserom.gba", 0xE6E94, 0x18

	.global gUnknown_80E6EAC
gUnknown_80E6EAC: @ 80E6EAC
	.incbin "baserom.gba", 0xE6EAC, 0x74

	.global gUnknown_80E6F20
gUnknown_80E6F20: @ 80E6F20
	.incbin "baserom.gba", 0xE6F20, 0x18

	.global gUnknown_80E6F38
gUnknown_80E6F38: @ 80E6F38
	.incbin "baserom.gba", 0xE6F38, 0x18

	.global gUnknown_80E6F50
gUnknown_80E6F50: @ 80E6F50
	.incbin "baserom.gba", 0xE6F50, 0x6C

	.global gUnknown_80E6FBC
gUnknown_80E6FBC: @ 80E6FBC
	.incbin "baserom.gba", 0xE6FBC, 0x60

	.global gUnknown_80E701C
gUnknown_80E701C: @ 80E701C
	.incbin "baserom.gba", 0xE701C, 0x74

	.global gUnknown_80E7090
gUnknown_80E7090: @ 80E7090
	.incbin "baserom.gba", 0xE7090, 0x3C

	.global gUnknown_80E70CC
gUnknown_80E70CC: @ 80E70CC
	.incbin "baserom.gba", 0xE70CC, 0x48

	.global gUnknown_80E7114
gUnknown_80E7114: @ 80E7114
	.incbin "baserom.gba", 0xE7114, 0x64

	.global gUnknown_80E7178
gUnknown_80E7178: @ 80E7178
	.incbin "baserom.gba", 0xE7178, 0x6C

	.global gUnknown_80E71E4
gUnknown_80E71E4: @ 80E71E4
	.incbin "baserom.gba", 0xE71E4, 0x18

	.global gUnknown_80E71FC
gUnknown_80E71FC: @ 80E71FC
	.incbin "baserom.gba", 0xE71FC, 0x18

	.global gUnknown_80E7214
gUnknown_80E7214: @ 80E7214
	.incbin "baserom.gba", 0xE7214, 0x64

	.global gUnknown_80E7278
gUnknown_80E7278: @ 80E7278
	.incbin "baserom.gba", 0xE7278, 0x18

	.global gUnknown_80E7290
gUnknown_80E7290: @ 80E7290
	.incbin "baserom.gba", 0xE7290, 0x5C

	.global gUnknown_80E72EC
gUnknown_80E72EC: @ 80E72EC
	.incbin "baserom.gba", 0xE72EC, 0x18

	.global gUnknown_80E7304
gUnknown_80E7304: @ 80E7304
	.incbin "baserom.gba", 0xE7304, 0x40

	.global gUnknown_80E7344
gUnknown_80E7344: @ 80E7344
	.incbin "baserom.gba", 0xE7344, 0x18

	.global gUnknown_80E735C
gUnknown_80E735C: @ 80E735C
	.incbin "baserom.gba", 0xE735C, 0x50

	.global gUnknown_80E73AC
gUnknown_80E73AC: @ 80E73AC
	.incbin "baserom.gba", 0xE73AC, 0x18

	.global gUnknown_80E73C4
gUnknown_80E73C4: @ 80E73C4
	.incbin "baserom.gba", 0xE73C4, 0x44

	.global gUnknown_80E7408
gUnknown_80E7408: @ 80E7408
	.incbin "baserom.gba", 0xE7408, 0x18

	.global gUnknown_80E7420
gUnknown_80E7420: @ 80E7420
	.incbin "baserom.gba", 0xE7420, 0x48

	.global gUnknown_80E7468
gUnknown_80E7468: @ 80E7468
	.incbin "baserom.gba", 0xE7468, 0x18

	.global gUnknown_80E7480
gUnknown_80E7480: @ 80E7480
	.incbin "baserom.gba", 0xE7480, 0x48

	.global gUnknown_80E74C8
gUnknown_80E74C8: @ 80E74C8
	.incbin "baserom.gba", 0xE74C8, 0x18

	.global gUnknown_80E74E0
gUnknown_80E74E0: @ 80E74E0
	.incbin "baserom.gba", 0xE74E0, 0x4C

	.global gUnknown_80E752C
gUnknown_80E752C: @ 80E752C
	.incbin "baserom.gba", 0xE752C, 0x18

	.global gUnknown_80E7544
gUnknown_80E7544: @ 80E7544
	.incbin "baserom.gba", 0xE7544, 0x44

	.global gUnknown_80E7588
gUnknown_80E7588: @ 80E7588
	.incbin "baserom.gba", 0xE7588, 0x18

	.global gUnknown_80E75A0
gUnknown_80E75A0: @ 80E75A0
	.incbin "baserom.gba", 0xE75A0, 0x58

	.global gUnknown_80E75F8
gUnknown_80E75F8: @ 80E75F8
	.incbin "baserom.gba", 0xE75F8, 0x18

	.global gUnknown_80E7610
gUnknown_80E7610: @ 80E7610
	.incbin "baserom.gba", 0xE7610, 0x1C

	.global gUnknown_80E762C
gUnknown_80E762C: @ 80E762C
	.incbin "baserom.gba", 0xE762C, 0x18

	.global gUnknown_80E7644
gUnknown_80E7644: @ 80E7644
	.incbin "baserom.gba", 0xE7644, 0x40

	.global gUnknown_80E7684
gUnknown_80E7684: @ 80E7684
	.incbin "baserom.gba", 0xE7684, 0x34

	.global gUnknown_80E76B8
gUnknown_80E76B8: @ 80E76B8
	.incbin "baserom.gba", 0xE76B8, 0x30

	.global gUnknown_80E76E8
gUnknown_80E76E8: @ 80E76E8
	.incbin "baserom.gba", 0xE76E8, 0x48

	.global gUnknown_80E7730
gUnknown_80E7730: @ 80E7730
	.incbin "baserom.gba", 0xE7730, 0x54

	.global gUnknown_80E7784
gUnknown_80E7784: @ 80E7784
	.incbin "baserom.gba", 0xE7784, 0x18

	.global gUnknown_80E779C
gUnknown_80E779C: @ 80E779C
	.incbin "baserom.gba", 0xE779C, 0x20

	.global gUnknown_80E77BC
gUnknown_80E77BC: @ 80E77BC
	.incbin "baserom.gba", 0xE77BC, 0x8

	.global gUnknown_80E77C4
gUnknown_80E77C4: @ 80E77C4
	.incbin "baserom.gba", 0xE77C4, 0x8

	.global gUnknown_80E77CC
gUnknown_80E77CC: @ 80E77CC
	.incbin "baserom.gba", 0xE77CC, 0xC

	.global gUnknown_80E77D8
gUnknown_80E77D8: @ 80E77D8
	.incbin "baserom.gba", 0xE77D8, 0xC

	.global gUnknown_80E77E4
gUnknown_80E77E4: @ 80E77E4
	.incbin "baserom.gba", 0xE77E4, 0xC

	.global gUnknown_80E77F0
gUnknown_80E77F0: @ 80E77F0
	.incbin "baserom.gba", 0xE77F0, 0x8

	.global gUnknown_80E77F8
gUnknown_80E77F8: @ 80E77F8
	.incbin "baserom.gba", 0xE77F8, 0xC

	.global gUnknown_80E7804
gUnknown_80E7804: @ 80E7804
	.incbin "baserom.gba", 0xE7804, 0x4

	.global gUnknown_80E7808
gUnknown_80E7808: @ 80E7808
	.incbin "baserom.gba", 0xE7808, 0x4

	.global gUnknown_80E780C
gUnknown_80E780C: @ 80E780C
	.incbin "baserom.gba", 0xE780C, 0x18

	.global gUnknown_80E7824
gUnknown_80E7824: @ 80E7824
	.incbin "baserom.gba", 0xE7824, 0x14

	.global gUnknown_80E7838
gUnknown_80E7838: @ 80E7838
	.incbin "baserom.gba", 0xE7838, 0x10

	.global gUnknown_80E7848
gUnknown_80E7848: @ 80E7848
	.incbin "baserom.gba", 0xE7848, 0x4

	.global gUnknown_80E784C
gUnknown_80E784C: @ 80E784C
	.incbin "baserom.gba", 0xE784C, 0x8

	.global gUnknown_80E7854
gUnknown_80E7854: @ 80E7854
	.incbin "baserom.gba", 0xE7854, 0x8

	.global gUnknown_80E785C
gUnknown_80E785C: @ 80E785C
	.incbin "baserom.gba", 0xE785C, 0x10

	.global gUnknown_80E786C
gUnknown_80E786C: @ 80E786C
	.incbin "baserom.gba", 0xE786C, 0x28

	.global gUnknown_80E7894
gUnknown_80E7894: @ 80E7894
	.incbin "baserom.gba", 0xE7894, 0x44

	.global gUnknown_80E78D8
gUnknown_80E78D8: @ 80E78D8
	.incbin "baserom.gba", 0xE78D8, 0x20

	.global gUnknown_80E78F8
gUnknown_80E78F8: @ 80E78F8
	.incbin "baserom.gba", 0xE78F8, 0x1C

	.global gUnknown_80E7914
gUnknown_80E7914: @ 80E7914
	.incbin "baserom.gba", 0xE7914, 0x24

	.global gUnknown_80E7938
gUnknown_80E7938: @ 80E7938
	.incbin "baserom.gba", 0xE7938, 0x5C

	.global gUnknown_80E7994
gUnknown_80E7994: @ 80E7994
	.incbin "baserom.gba", 0xE7994, 0x50

	.global gUnknown_80E79E4
gUnknown_80E79E4: @ 80E79E4
	.incbin "baserom.gba", 0xE79E4, 0x64

	.global gUnknown_80E7A48
gUnknown_80E7A48: @ 80E7A48
	.incbin "baserom.gba", 0xE7A48, 0x7C

	.global gUnknown_80E7AC4
gUnknown_80E7AC4: @ 80E7AC4
	.incbin "baserom.gba", 0xE7AC4, 0x1C

	.global gUnknown_80E7AE0
gUnknown_80E7AE0: @ 80E7AE0
	.incbin "baserom.gba", 0xE7AE0, 0x34

	.global gUnknown_80E7B14
gUnknown_80E7B14: @ 80E7B14
	.incbin "baserom.gba", 0xE7B14, 0x34

	.global gUnknown_80E7B48
gUnknown_80E7B48: @ 80E7B48
	.incbin "baserom.gba", 0xE7B48, 0x20

	.global gUnknown_80E7B68
gUnknown_80E7B68: @ 80E7B68
	.incbin "baserom.gba", 0xE7B68, 0x20

	.global gUnknown_80E7B88
gUnknown_80E7B88: @ 80E7B88
	.incbin "baserom.gba", 0xE7B88, 0x40

	.global gUnknown_80E7BC8
gUnknown_80E7BC8: @ 80E7BC8
	.incbin "baserom.gba", 0xE7BC8, 0x24

	.global gUnknown_80E7BEC
gUnknown_80E7BEC: @ 80E7BEC
	.incbin "baserom.gba", 0xE7BEC, 0x5C

	.global gUnknown_80E7C48
gUnknown_80E7C48: @ 80E7C48
	.incbin "baserom.gba", 0xE7C48, 0x50

	.global gUnknown_80E7C98
gUnknown_80E7C98: @ 80E7C98
	.incbin "baserom.gba", 0xE7C98, 0x2C

	.global gUnknown_80E7CC4
gUnknown_80E7CC4: @ 80E7CC4
	.incbin "baserom.gba", 0xE7CC4, 0x7C

	.global gUnknown_80E7D40
gUnknown_80E7D40: @ 80E7D40
	.incbin "baserom.gba", 0xE7D40, 0x18

	.global gUnknown_80E7D58
gUnknown_80E7D58: @ 80E7D58
	.incbin "baserom.gba", 0xE7D58, 0x18

	.global gUnknown_80E7D70
gUnknown_80E7D70: @ 80E7D70
	.incbin "baserom.gba", 0xE7D70, 0xC4

	.global gUnknown_80E7E34
gUnknown_80E7E34: @ 80E7E34
	.incbin "baserom.gba", 0xE7E34, 0x18

	.global gUnknown_80E7E4C
gUnknown_80E7E4C: @ 80E7E4C
	.incbin "baserom.gba", 0xE7E4C, 0x18

	.global gUnknown_80E7E64
gUnknown_80E7E64: @ 80E7E64
	.incbin "baserom.gba", 0xE7E64, 0x18

	.global gUnknown_80E7E7C
gUnknown_80E7E7C: @ 80E7E7C
        .string "Number?\0"
        .align 2,0
        .string "pksdir0\0"
        .align 2,0

	.global gUnknown_80E7E8C
gUnknown_80E7E8C: @ 80E7E8C
	.incbin "baserom.gba", 0xE7E8C, 0x18

	.global gUnknown_80E7EA4
gUnknown_80E7EA4: @ 80E7EA4
	.incbin "baserom.gba", 0xE7EA4, 0x18

	.global gUnknown_80E7EBC
gUnknown_80E7EBC: @ 80E7EBC
        .string "CLOSE\0"
        .align 2,0

	.global gUnknown_80E7EC4
gUnknown_80E7EC4: @ 80E7EC4
        .string "OPEN\0"
        .align 2,0
        .string "pksdir0\0"
        .align 2,0

	.global gUnknown_80E7ED4
gUnknown_80E7ED4: @ 80E7ED4
	.incbin "baserom.gba", 0xE7ED4, 0x18

	.global gUnknown_80E7EEC
gUnknown_80E7EEC: @ 80E7EEC
	.incbin "baserom.gba", 0xE7EEC, 0x18

	.global gUnknown_80E7F04
gUnknown_80E7F04: @ 80E7F04
	.incbin "baserom.gba", 0xE7F04, 0x18

	.global gUnknown_80E7F1C
gUnknown_80E7F1C: @ 80E7F1C
        .string "Number?\0"
        .align 2,0

	.global gUnknown_80E7F24
gUnknown_80E7F24: @ 80E7F24
        .string "LEVEL\0"
        .align 2,0

	.global gUnknown_80E7F2C
gUnknown_80E7F2C: @ 80E7F2C
        .string "Name\0"
        .align 2,0
        .string "pksdir0\0"
        .align 2,0

	.global gUnknown_80E7F3C
gUnknown_80E7F3C: @ 80E7F3C
	.incbin "baserom.gba", 0xE7F3C, 0x18

	.global gUnknown_80E7F54
gUnknown_80E7F54: @ 80E7F54
	.incbin "baserom.gba", 0xE7F54, 0x18

	.global gUnknown_80E7F6C
gUnknown_80E7F6C: @ 80E7F6C
        .string "Script\0"
        .align 2,0
        .string "pksdir0\0"
        .align 2,0
        .string "pksdir0\0"
        .align 2,0
        .string "pksdir0\0"
        .align 2,0
        .string "pksdir0\0"
        .align 2,0

	.global gUnknown_80E7F94
gUnknown_80E7F94: @ 80E7F94
	.incbin "baserom.gba", 0xE7F94, 0x10C

	.global gUnknown_80E80A0
gUnknown_80E80A0: @ 80E80A0
	.incbin "baserom.gba", 0xE80A0, 0x40

	.global gUnknown_80E80E0
gUnknown_80E80E0: @ 80E80E0
	.incbin "baserom.gba", 0xE80E0, 0x46

	.global gUnknown_80E8126
gUnknown_80E8126: @ 80E8126
	.incbin "baserom.gba", 0xE8126, 0x42

	.global gUnknown_80E8168
gUnknown_80E8168: @ 80E8168
	.incbin "baserom.gba", 0xE8168, 0x18

	.global gUnknown_80E8180
gUnknown_80E8180: @ 80E8180
	.incbin "baserom.gba", 0xE8180, 0x54

	.global gUnknown_80E81D4
gUnknown_80E81D4: @ 80E81D4
	.incbin "baserom.gba", 0xE81D4, 0x608

	.global gMankeyMission
gMankeyMission: @ 80E87DC
        .string "Punish bad #C6Mankey#R!\0"
        .align 2,0

	.global gSmeargleMission
gSmeargleMission: @ 80E87F4
        .string "#C6Smeargle#R~27s desperate plea!\0"
        .align 2,0

	.global gMedichamMission
gMedichamMission: @ 80E8818
        .string "#C6Medicham#R: Help me!\0"
        .align 2,0

	.global gUnknown_80E8830
gUnknown_80E8830: @ 80E8830
        .string "Deliver one #C4%s#R.\0"
        .align 2,0

	.global gUnknown_80E8848
gUnknown_80E8848: @ 80E8848
        .string "One #C4%s#R wanted!\0"
        .align 2,0

	.global gUnknown_80E885C
gUnknown_80E885C: @ 80E885C
        .string "Save my child!\0"
        .align 2,0

	.global gUnknown_80E886C
gUnknown_80E886C: @ 80E886C
        .string "Escort me to my love!\0"
        .align 2,0

	.global gUnknown_80E8884
gUnknown_80E8884: @ 80E8884
        .string "Near %s\0"
        .align 2,0

	.global gUnknown_80E888C
gUnknown_80E888C: @ 80E888C
        .string "Rescue Description\0"
        .align 2,0

	.global gUnknown_80E88A0
gUnknown_80E88A0: @ 80E88A0
        .string "Please punish bad #C6Mankey#R~27s gang.\0"
        .align 2,0

	.global gUnknown_80E88C8
gUnknown_80E88C8: @ 80E88C8
	.incbin "baserom.gba", 0xE88C8, 0x58

	.global gUnknown_80E8920
gUnknown_80E8920: @ 80E8920
	.incbin "baserom.gba", 0xE8920, 0x48

	.global gUnknown_80E8968
gUnknown_80E8968: @ 80E8968
        .string "With the item #C4%s#R~2c I can\n"
        .string "evolve! I~27m yearning to evolve! Help!\0"
        .align 2,0

	.global gUnknown_80E89B0
gUnknown_80E89B0: @ 80E89B0
        .string "The #C4%s#R! What I love to eat\n"
        .string "and can~27t live without! Please get one!\0"
        .align 2,0

	.global gUnknown_80E89FC
gUnknown_80E89FC: @ 80E89FC
        .string "This is a rescue through communication.\n"
        .string "Get a friend to help you!\0"
        .align 2,0

	.global gUnknown_80E8A40
gUnknown_80E8A40: @ 80E8A40
        .string "This is a rescue through communication.\n"
        .string "Rescue a friend!\0"
        .align 2,0

	.global gUnknown_80E8A7C
gUnknown_80E8A7C: @ 80E8A7C
        .string "This is a rescue through communication.\n"
        .string "Send your thanks to your friend!\0"
        .align 2,0

	.global gUnknown_80E8AC8
gUnknown_80E8AC8: @ 80E8AC8
        .string "Client:\0"
        .align 2,0

	.global gUnknown_80E8AD0
gUnknown_80E8AD0: @ 80E8AD0
	.incbin "baserom.gba", 0xE8AD0, 0x10

	.global gUnknown_80E8AE0
gUnknown_80E8AE0: @ 80E8AE0
        .string "Objective:\0"
        .align 2,0

	.global gUnknown_80E8AEC
gUnknown_80E8AEC: @ 80E8AEC
        .string "Friend Rescue\0"
        .align 2,0

	.global gUnknown_80E8AFC
gUnknown_80E8AFC: @ 80E8AFC
        .string "Deliver #C4%s#R.\0"
        .align 2,0

	.global gUnknown_80E8B10
gUnknown_80E8B10: @ 80E8B10
        .string "Find #C4%s#R.\0"
        .align 2,0

	.global gUnknown_80E8B20
gUnknown_80E8B20: @ 80E8B20
        .string "Help me.\0"
        .align 2,0

	.global gUnknown_80E8B2C
gUnknown_80E8B2C: @ 80E8B2C
        .string "Escort to #C6%s#R.\0"
        .align 2,0

	.global gUnknown_80E8B40
gUnknown_80E8B40: @ 80E8B40
        .string "Find #C6%s#R.\0"
        .align 2,0

	.global gSpecialMissionText
gSpecialMissionText: @ 80E8B50
        .string "Special mission\0"
        .align 2,0

	.global gPlaceText
gPlaceText: @ 80E8B60
        .string "Place:\0"
        .align 2,0

	.global gDifficultyText
gDifficultyText: @ 80E8B68
        .string "Difficulty:\0"
        .align 2,0

	.global gRewardText
gRewardText: @ 80E8B74
        .string "Reward:\0"
        .align 2,0

	.global gUnknown_80E8B7C
gUnknown_80E8B7C: @ 80E8B7C
        .string "Wonder Mail:\0"
        .align 2,0
        .string "pksdir0\0"
        .align 2,0

	.global gUnknown_80E8B94
gUnknown_80E8B94: @ 80E8B94
	.incbin "baserom.gba", 0xE8B94, 0x38

	.global gUnknown_80E8BCC
gUnknown_80E8BCC: @ 80E8BCC
        .byte 0xC8, 0x8B, 0x0E, 0x08
        .byte 0xF0, 0x8B, 0x0E, 0x08 @ Pointer to Suspend
        .byte 0xE4, 0x8B, 0x0E, 0x08 @ Pointer to Take Job
        .byte 0xDC, 0x8B, 0x0E, 0x08 @ Pointer to Done
        .string "Done\0"
        .align 2,0
        .string "Take Job\0"
        .align 2,0
        .string "Suspend\0"
        .align 2,0

	.global gUnknown_80E8BF8
gUnknown_80E8BF8: @ 80E8BF8
	.incbin "baserom.gba", 0xE8BF8, 0x50

	.global gUnknown_80E8C48
gUnknown_80E8C48: @ 80E8C48
	.incbin "baserom.gba", 0xE8C48, 0x50

	.global gUnknown_80E8C98
gUnknown_80E8C98: @ 80E8C98
	.incbin "baserom.gba", 0xE8C98, 0x14C

	.global gUnknown_80E8DE4
gUnknown_80E8DE4: @ 80E8DE4
	.incbin "baserom.gba", 0xE8DE4, 0x1CC

	.global gUnknown_80E8FB0
gUnknown_80E8FB0: @ 80E8FB0
	.incbin "baserom.gba", 0xE8FB0, 0x15C

	.global gUnknown_80E910C
gUnknown_80E910C: @ 80E910C
	.incbin "baserom.gba", 0xE910C, 0xC8

	.global gUnknown_80E91D4
gUnknown_80E91D4: @ 80E91D4
	.incbin "baserom.gba", 0xE91D4, 0x64C

	.global gUnknown_80E9820
gUnknown_80E9820: @ 80E9820
	.incbin "baserom.gba", 0xE9820, 0x100

	.global gUnknown_80E9920
gUnknown_80E9920: @ 80E9920
	.incbin "baserom.gba", 0xE9920, 0x66C

	.global gUnknown_80E9F8C
gUnknown_80E9F8C: @ 80E9F8C
	.incbin "baserom.gba", 0xE9F8C, 0xED0

	.global gUnknown_80EAE5C
gUnknown_80EAE5C: @ 80EAE5C
	.incbin "baserom.gba", 0xEAE5C, 0x5C

	.global gUnknown_80EAEB8
gUnknown_80EAEB8: @ 80EAEB8
	.incbin "baserom.gba", 0xEAEB8, 0x2E0

	.global gUnknown_80EB198
gUnknown_80EB198: @ 80EB198
	.incbin "baserom.gba", 0xEB198, 0x88

	.global gUnknown_80EB220
gUnknown_80EB220: @ 80EB220
	.incbin "baserom.gba", 0xEB220, 0xD0

	.global gUnknown_80EB2F0
gUnknown_80EB2F0: @ 80EB2F0
	.incbin "baserom.gba", 0xEB2F0, 0x108

	.global gUnknown_80EB3F8
gUnknown_80EB3F8: @ 80EB3F8
	.incbin "baserom.gba", 0xEB3F8, 0x334

	.global gUnknown_80EB72C
gUnknown_80EB72C: @ 80EB72C
	.incbin "baserom.gba", 0xEB72C, 0x2EC
