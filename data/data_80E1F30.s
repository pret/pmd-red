        .section .rodata

        .global gUnknown_80E1F30
gUnknown_80E1F30: @ 80E1F30
        .string "Objectives\0"
        .align 2,0

	.global gUnknown_80E1F3C
gUnknown_80E1F3C: @ 80E1F3C
        .string "%dF\0"

	.global gUnknown_80E1F40
gUnknown_80E1F40: @ 80E1F40
        .string "  Rescue {COLOR_1 YELLOW}%s{END_COLOR_TEXT_1}\0"
        .align 2,0

	.global gUnknown_80E1F54
gUnknown_80E1F54: @ 80E1F54
        .string "Just go!\0"
        .align 2,0

	.global gUnknown_80E1F60
gUnknown_80E1F60: @ 80E1F60
        .string "  Bring {COLOR_1 GREEN}%s{END_COLOR_TEXT_1}\0"
        .align 2,0

	.global gUnknown_80E1F70
gUnknown_80E1F70: @ 80E1F70
        .string "  Find {COLOR_1 GREEN}%s{END_COLOR_TEXT_1}\0"
        .align 2,0

	.global gUnknown_80E1F80
gUnknown_80E1F80: @ 80E1F80
        .string "  Escort to {COLOR_1 YELLOW}%s{END_COLOR_TEXT_1}\0"
        .align 2,0

	.global gUnknown_80E1F94
gUnknown_80E1F94: @ 80E1F94
        .string "#CW???{END_COLOR_TEXT_1}\0"
        .align 2,0
        .string "pksdir0\0"

	.global gUnknown_80E1FA8
gUnknown_80E1FA8: @ 80E1FA8
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x03, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00

        .global gUnkData_80E1FC0
        gUnkData_80E1FC0:
        .byte 0x01, 0x00, 0x0A, 0x00

	.global gUnknown_80E1FC4
gUnknown_80E1FC4: @ 80E1FC4
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x06, 0x00, 0x00, 0x00
        .byte 0x02, 0x00, 0x02, 0x00
        .byte 0x1a, 0x00, 0x0a, 0x00
        .byte 0x0a, 0x00, 0x00, 0x00

        .4byte gUnkData_80E1FC0

	.global gUnknown_80E1FDC
gUnknown_80E1FDC: @ 80E1FDC
        .string "Password\0"
        .align 2,0
        .string "pksdir0\0"
        .align 2,0
