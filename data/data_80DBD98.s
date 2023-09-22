	.section .rodata

@ options_menu #1
        .align 2,0
.string "pksdir0\0"
        .align 2,0

	.global gUnknown_80DBFB0
gUnknown_80DBFB0: @ 80DBFB0
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x03, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00

        .global UnkData_80DBFC8
        UnkData_80DBFC8:
        .byte 0x01, 0x00, 0x07, 0x00

	.global gUnknown_80DBFCC
gUnknown_80DBFCC: @ 80DBFCC
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x06, 0x00, 0x00, 0x00
        .byte 0x02, 0x00, 0x02, 0x00
        .byte 0x0A, 0x00, 0x06, 0x00
        .byte 0x06, 0x00, 0x00, 0x00
        .4byte UnkData_80DBFC8

	.global gOthers_MenuOption
gOthers_MenuOption: @ 80DBFE4
        .string "Others\0"
        .align 2,0

	.global gUnknown_80DBFEC
gUnknown_80DBFEC: @ 80DBFEC
        .string "Change settings?\0"
        .align 2,0

	.global gOthers_GameOptions
gOthers_GameOptions: @ 80DC000
        .string "Game Options\0"
        .align 2,0

	.global gOthers_Hints
gOthers_Hints: @ 80DC010
        .string "Hints\0"

@ options_menu #2
        .align 2,0
.string "pksdir0\0"
        .align 2,0

	.global gUnknown_80DC020
gUnknown_80DC020: @ 80DC020
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x03, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00

        .global UnkData_80DC038
UnkData_80DC038:
        .byte 0x01, 0x00, 0x0a, 0x00
	.global gUnknown_80DC03C
gUnknown_80DC03C: @ 80DC03C
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x06, 0x00, 0x00, 0x00
        .byte 0x02, 0x00, 0x02, 0x00
        .byte 0x18, 0x00, 0x10, 0x00
        .byte 0x12, 0x00, 0x00, 0x00
        .4byte UnkData_80DC038

	.global gWindowBGTitle
gWindowBGTitle: @ 80DC054
        .string "Game Options\0"
        .align 2,0

	.global gUnknown_80DC064
gUnknown_80DC064: @ 80DC064
        .string "Windows{UNK_MACRO_3D M3D_80}Blue{UNK_MACRO_3D M3D_120}Red{UNK_MACRO_3D M3D_160}Green\0"
        .align 2,0

	.global gWindowBGBlueString
gWindowBGBlueString: @ 80DC084
        .string "Blue\0"
        .align 2,0

	.global gWindowBGRedString
gWindowBGRedString: @ 80DC08C
        .string "Red\0"
        .align 2,0

	.global gWindowBGGreenString
gWindowBGGreenString: @ 80DC090
        .string "Green\0"