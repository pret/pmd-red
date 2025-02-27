    .section .rodata

    .align 2,0

        .asciz "pksdir0"
        .asciz "pksdir0"

	.global gUnknown_80D4144
gUnknown_80D4144: @ 80D4144
        .2byte 302
        .2byte 303
        .2byte 303
        .2byte 301
        .2byte 304
        .2byte 306
        .2byte 307
        .2byte 0

        .string "pksdir0\0"
        .string "pksdir0\0"
        .4byte noneText
        .byte 0xff, 0xff, 0xff, 0xff
        .4byte noneText

        .global noneText
        noneText:
        .string "none\0"
        .align 2,0

        .4byte defaultText
        .byte 0xff, 0xff, 0xff, 0xff
        .4byte noneText

        .global defaultText
        defaultText:
        .string "default\0"
