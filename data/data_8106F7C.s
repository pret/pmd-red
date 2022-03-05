        .section .rodata

	.global gUnknown_8106F7C
gUnknown_8106F7C: @ 8106F7C
	.incbin "baserom.gba", 0x106F7C, 0x28

	.global gUnknown_8106FA4
gUnknown_8106FA4: @ 8106FA4
        .string "{COLOR_2}%c%s{END_COLOR_TEXT_2}\0"
