        .section .rodata

@ code_803B050 #1
        .align 2,0
        .string "pksdir0\0"
    .global gUnknown_80E7F3C
gUnknown_80E7F3C: @ 80E7F3C
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x03, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00

    .global gUnknown_80E7F54
gUnknown_80E7F54: @ 80E7F54
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x06, 0x00, 0x00, 0x00
        .byte 0x02, 0x00, 0x02, 0x00
        .byte 0x18, 0x00, 0x11, 0x00
        .byte 0x11, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00

    .global gUnknown_80E7F6C
gUnknown_80E7F6C: @ 80E7F6C
        .string "Script\0"

@ code_803B050 #2
        .align 2,0
        .string "pksdir0\0"

@ code_803B050 #3
        .align 2,0
        .string "pksdir0\0"

@ code_803B050 #4
        .align 2,0
        .string "pksdir0\0"

@ code_803B050 #5
        .align 2,0
        .string "pksdir0\0"

        .align 2,0
	.global gUnknown_80E7F94
gUnknown_80E7F94: @ 80E7F94
.macro st_80E7F94 a, b, c, e, f, g, h, i, j, k, m, n
    .byte \a, \b, \c
    .align 2, 0
    .4byte \e, \f
    .2byte \g, \h
    .byte \i, \j, \k
    .align 2, 0
    .4byte \m, \n
.endm
    st_80E7F94 5, 1, 4, 0xC2B,  0x123456, 0x19, 0x182, 0x38, 8, 0x3A, sUnknown_80E8088, sUnknown_80E8070
    st_80E7F94 5, 1, 4, 0x112C, 0x123456, 4,    0x115, 0x38, 8, 0x3A, sUnknown_80E8060, sUnknown_80E8048
    st_80E7F94 5, 1, 4, 0x112D, 0x123456, 1,    0x118, 0x38, 8, 0x3A, sUnknown_80E8038, sUnknown_80E8020
    st_80E7F94 5, 1, 0, 0x1B2E, 0x123456, 7,    0x9B,  0x38, 8, 0x3A, 0,                0
    st_80E7F94 5, 1, 0, 0x903,  0x123456, 0x98, 0x9E,  0x38, 8, 0x3A, 0,                0

sUnknown_80E8020: @ 80E8020
    .string "SHOW RESCUE 00\n"
    .string " EVENT02\0"
    .align 2, 0

sUnknown_80E8038: @ 80E8038
    .string "SHOW　TITLE02\0"
    .align 2, 0

sUnknown_80E8048: @ 80E8048
    .string "SHOW RESCUE 00\n"
    .string " EVENT01\0"
    .align 2, 0

sUnknown_80E8060: @ 80E8060
    .string "SHOW　TITLE01\0"
    .align 2, 0

sUnknown_80E8070: @ 80E8070
    .string "SHOW RESCUE 00\n"
    .string " EVENT00\0"
    .align 2, 0

sUnknown_80E8088: @ 80E8088
    .string "SHOW　TITLE00\0"
    .align 2, 0