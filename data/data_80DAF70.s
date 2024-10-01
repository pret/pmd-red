	.section .rodata

    .align 2, 0

@ START code_80130A8 #4
.string "pksdir0\0"

	.global gUnknown_80DAFC0
gUnknown_80DAFC0: @ 80DAFC0
    .2byte 3, 0xD
    .2byte 0xF, 0xD
    .2byte 0x1B, 0xD
    .2byte 0x27, 0xD
    .2byte 0x33, 0xD
    .2byte 0x40, 0xF
    .2byte 0x4C, 0xF
    .2byte 0x58, 0xF
    .2byte 0x64, 0xF
    .2byte 0x70, 0xF
    .2byte 0x7C, 0xF
    .2byte 0x88, 0xF
    .2byte 0x94, 0xF
    .2byte 0xA1, 0xD
    .2byte 0xAD, 0xD
    .2byte 0xB9, 0xD
    .2byte 0xC5, 0xD
    .2byte 0xD1, 0xD
    .2byte 3, 0x1A
    .2byte 0xF, 0x1A
    .2byte 0x1B, 0x1A
    .2byte 0x27, 0x1A
    .2byte 0x33, 0x1A
    .2byte 0x40, 0x1C
    .2byte 0x4C, 0x1C
    .2byte 0x58, 0x1C
    .2byte 0x64, 0x1C
    .2byte 0x70, 0x1C
    .2byte 0x7C, 0x1C
    .2byte 0x88, 0x1C
    .2byte 0x94, 0x1C
    .2byte 0xA1, 0x1A
    .2byte 0xAD, 0x1A
    .2byte 0xB9, 0x1A
    .2byte 0xC5, 0x1A
    .2byte 0xD1, 0x1A
    .2byte 3, 0x28
    .2byte 0xF, 0x28
    .2byte 0x1B, 0x28
    .2byte 0x27, 0x28
    .2byte 0x33, 0x28
    .2byte 0x40, 0x2A
    .2byte 0x4C, 0x2A
    .2byte 0x58, 0x2A
    .2byte 0x64, 0x2A
    .2byte 0x70, 0x2A
    .2byte 0x7C, 0x2A
    .2byte 0x88, 0x2A
    .2byte 0x94, 0x2A
    .2byte 0xA1, 0x28
    .2byte 0xAD, 0x28
    .2byte 0xB9, 0x28
    .2byte 0xC5, 0x28
    .2byte 0xD1, 0x28

	.global gUnknown_80DB098
gUnknown_80DB098: @ 80DB098
    .2byte 0x20, 0x12
    .2byte 0x2E, 0x12
    .2byte 0x3C, 0x12
    .2byte 0x4A, 0x12
    .2byte 0x58, 0x14
    .2byte 0x66, 0x14
    .2byte 0x74, 0x14
    .2byte 0x82, 0x14
    .2byte 0x90, 0x12
    .2byte 0x9E, 0x12
    .2byte 0xAC, 0x12
    .2byte 0xBA, 0x12
    .2byte 0x20, 0x24
    .2byte 0x2E, 0x24
    .2byte 0x3C, 0x24
    .2byte 0x4A, 0x24
    .2byte 0x58, 0x26
    .2byte 0x66, 0x26
    .2byte 0x74, 0x26
    .2byte 0x82, 0x26
    .2byte 0x90, 0x24
    .2byte 0x9E, 0x24
    .2byte 0xAC, 0x24
    .2byte 0xBA, 0x24

	.global gUnknown_80DB0F8
gUnknown_80DB0F8: @ 80DB0F8
.macro st_80DB0F8, a, b, c, d, e, f, g, h
    .byte \a, \b, \c, \d, \e, \f, \g
    .align 2, 0
    .4byte \h
.endm
    st_80DB0F8 0,  0,  0,  0,  8,   3,  0, 264
    st_80DB0F8 0,  0,  0,  0,  8,   14, 0, 264
    st_80DB0F8 0,  0,  0,  0,  8,   25, 0, 264
    st_80DB0F8 5,  4,  81, 9,  8,   36, 3, 263
    st_80DB0F8 3,  5,  82, 10, 8,   47, 3, 261
    st_80DB0F8 4,  3,  83, 11, 8,   58, 3, 262
    st_80DB0F8 11, 7,  78, 12, 36,  3,  0, 97
    st_80DB0F8 6,  8,  79, 13, 36,  14, 0, 110
    st_80DB0F8 7,  9,  80, 14, 36,  25, 0, 65
    st_80DB0F8 8,  10, 3,  15, 36,  36, 0, 78
    st_80DB0F8 9,  11, 4,  16, 36,  47, 0, 233
    st_80DB0F8 10, 6,  5,  17, 36,  58, 0, 43
    st_80DB0F8 17, 13, 6,  18, 50,  3,  0, 98
    st_80DB0F8 12, 14, 7,  19, 50,  14, 0, 111
    st_80DB0F8 13, 15, 8,  20, 50,  25, 0, 66
    st_80DB0F8 14, 16, 9,  21, 50,  36, 0, 79
    st_80DB0F8 15, 17, 10, 22, 50,  47, 0, 49
    st_80DB0F8 16, 12, 11, 23, 50,  58, 0, 45
    st_80DB0F8 23, 19, 12, 24, 64,  3,  0, 99
    st_80DB0F8 18, 20, 13, 25, 64,  14, 0, 112
    st_80DB0F8 19, 21, 14, 26, 64,  25, 0, 67
    st_80DB0F8 20, 22, 15, 27, 64,  36, 0, 80
    st_80DB0F8 21, 23, 16, 28, 64,  47, 0, 50
    st_80DB0F8 22, 18, 17, 29, 64,  58, 0, 44
    st_80DB0F8 29, 25, 18, 30, 78,  3,  0, 100
    st_80DB0F8 24, 26, 19, 31, 78,  14, 0, 113
    st_80DB0F8 25, 27, 20, 32, 78,  25, 0, 68
    st_80DB0F8 26, 28, 21, 33, 78,  36, 0, 81
    st_80DB0F8 27, 29, 22, 34, 78,  47, 0, 51
    st_80DB0F8 28, 24, 23, 35, 78,  58, 0, 46
    st_80DB0F8 35, 31, 24, 36, 92,  3,  0, 101
    st_80DB0F8 30, 32, 25, 37, 92,  14, 0, 114
    st_80DB0F8 31, 33, 26, 38, 92,  25, 0, 69
    st_80DB0F8 32, 34, 27, 39, 92,  36, 0, 82
    st_80DB0F8 33, 35, 28, 40, 92,  47, 0, 52
    st_80DB0F8 34, 30, 29, 41, 92,  58, 0, 33
    st_80DB0F8 41, 37, 30, 42, 106, 3,  0, 102
    st_80DB0F8 36, 38, 31, 43, 106, 14, 0, 115
    st_80DB0F8 37, 39, 32, 44, 106, 25, 0, 70
    st_80DB0F8 38, 40, 33, 45, 106, 36, 0, 83
    st_80DB0F8 39, 41, 34, 46, 106, 47, 0, 53
    st_80DB0F8 40, 36, 35, 47, 106, 58, 0, 63
    st_80DB0F8 47, 43, 36, 48, 120, 3,  0, 103
    st_80DB0F8 42, 44, 37, 49, 120, 14, 0, 116
    st_80DB0F8 43, 45, 38, 50, 120, 25, 0, 71
    st_80DB0F8 44, 46, 39, 51, 120, 36, 0, 84
    st_80DB0F8 45, 47, 40, 52, 120, 47, 0, 54
    st_80DB0F8 46, 42, 41, 53, 120, 58, 0, 145
    st_80DB0F8 53, 49, 42, 54, 134, 3,  0, 104
    st_80DB0F8 48, 50, 43, 55, 134, 14, 0, 117
    st_80DB0F8 49, 51, 44, 56, 134, 25, 0, 72
    st_80DB0F8 50, 52, 45, 57, 134, 36, 0, 85
    st_80DB0F8 51, 53, 46, 58, 134, 47, 0, 55
    st_80DB0F8 52, 48, 47, 59, 134, 58, 0, 146
    st_80DB0F8 59, 55, 48, 60, 148, 3,  0, 105
    st_80DB0F8 54, 56, 49, 61, 148, 14, 0, 118
    st_80DB0F8 55, 57, 50, 62, 148, 25, 0, 73
    st_80DB0F8 56, 58, 51, 63, 148, 36, 0, 86
    st_80DB0F8 57, 59, 52, 64, 148, 47, 0, 56
    st_80DB0F8 58, 54, 53, 65, 148, 58, 0, 147
    st_80DB0F8 65, 61, 54, 66, 162, 3,  0, 106
    st_80DB0F8 60, 62, 55, 67, 162, 14, 0, 119
    st_80DB0F8 61, 63, 56, 68, 162, 25, 0, 74
    st_80DB0F8 62, 64, 57, 69, 162, 36, 0, 87
    st_80DB0F8 63, 65, 58, 70, 162, 47, 0, 57
    st_80DB0F8 64, 60, 59, 71, 162, 58, 0, 148
    st_80DB0F8 71, 67, 60, 72, 176, 3,  0, 107
    st_80DB0F8 66, 68, 61, 73, 176, 14, 0, 120
    st_80DB0F8 67, 69, 62, 74, 176, 25, 0, 75
    st_80DB0F8 68, 70, 63, 75, 176, 36, 0, 88
    st_80DB0F8 69, 71, 64, 76, 176, 47, 0, 48
    st_80DB0F8 70, 66, 65, 77, 176, 58, 0, 189
    st_80DB0F8 77, 73, 66, 78, 190, 3,  0, 108
    st_80DB0F8 72, 74, 67, 79, 190, 14, 0, 121
    st_80DB0F8 73, 75, 68, 80, 190, 25, 0, 76
    st_80DB0F8 74, 76, 69, 81, 190, 36, 0, 89
    st_80DB0F8 75, 77, 70, 82, 190, 47, 0, 58
    st_80DB0F8 76, 72, 71, 83, 190, 58, 0, 190
    st_80DB0F8 83, 79, 72, 6,  204, 3,  0, 109
    st_80DB0F8 78, 80, 73, 7,  204, 14, 0, 122
    st_80DB0F8 79, 81, 74, 8,  204, 25, 0, 77
    st_80DB0F8 80, 82, 75, 3,  204, 36, 0, 90
    st_80DB0F8 81, 83, 76, 4,  204, 47, 0, 133
    st_80DB0F8 82, 78, 77, 5,  204, 58, 0, 32
    st_80DB0F8 0,  0,  0,  0,  8,   3,  2, 265

	.global gUnknown_80DB4F4
gUnknown_80DB4F4: @ 80DB4F4
    .4byte sUnknown_80DB534
    .4byte sUnknown_80DB530
    .4byte sUnknown_80DB528
    .4byte sUnknown_80DB520
    .4byte sUnknown_80DB518
    .4byte sUnknown_80DB514
    .4byte sUnknown_80DB510

sUnknown_80DB510:
    .string "END\0"
    .align 2, 0

sUnknown_80DB514:
    .string "DEL\0"
    .align 2, 0

sUnknown_80DB518:
    .string "ＡＢＣ\0"
    .align 2, 0

sUnknown_80DB520:
    .string "カナ\0"
    .align 2, 0

sUnknown_80DB528:
    .string "かな\0"
    .align 2, 0

sUnknown_80DB530:
    .string "゜\0"
    .align 2, 0

sUnknown_80DB534:
    .string "゛\0"
    .align 2, 0

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
        .string "{COLOR_1 GREEN}OVR{END_COLOR_TEXT_1}\0"
        .align 2,0

	.global gUnknown_80DB5A4
gUnknown_80DB5A4: @ 80DB5A4
        .string "{COLOR_1 YELLOW}INS{END_COLOR_TEXT_1}\0"
        .align 2,0

	.global gUnknown_80DB5B0
gUnknown_80DB5B0: @ 80DB5B0
        .string "{COLOR_1}%c"
        .byte 0x81, 0x59
        .align 2,0

	.global gUnknown_80DB5B8
gUnknown_80DB5B8: @ 80DB5B8
        .string "{COLOR_1}%c%s\0"
        .align 2,0

	.global gUnknown_80DB5C0
gUnknown_80DB5C0: @ 80DB5C0
        .string "What is your name?\0"
        .align 2,0

	.global gUnknown_80DB5D4
gUnknown_80DB5D4: @ 80DB5D4
        .string "What is this Pokémon's nickname?\0"
        .align 2,0

	.global gUnknown_80DB5F8
gUnknown_80DB5F8: @ 80DB5F8
        .string "What is your partner's nickname?\0"
        .align 2,0

	.global gUnknown_80DB61C
gUnknown_80DB61C: @ 80DB61C
        .string "What is your team's name?\0"
        .align 2,0

	.global gUnknown_80DB638
gUnknown_80DB638: @ 80DB638
        .string "Please enter the password.\0"
        .align 2,0

	.global gUnknown_80DB654
gUnknown_80DB654: @ 80DB654
        .string "{COLOR_1 RED}%s{END_COLOR_TEXT_1}\0"
        .align 2,0

	.global gUnknown_80DB65C
gUnknown_80DB65C: @ 80DB65C
        .string "{COLOR_1 CYAN}%s{END_COLOR_TEXT_1}\0"
        .align 2,0

	.global gUnknown_80DB664
gUnknown_80DB664: @ 80DB664
        .string "%s\0"
        .align 2,0

@ END code_80130A8 #4
