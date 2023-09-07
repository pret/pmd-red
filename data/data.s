	.section .rodata

@ code_2
	.string "pksdir0\0"

	.global gUnknown_80B690C
gUnknown_80B690C: @ 80B690C
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x19, 0x00, 0x00, 0x00
        .byte 0x01, 0x00, 0x00, 0x00
        .byte 0x34, 0x00, 0x00, 0x00
        .byte 0x02, 0x00, 0x00, 0x00
        .byte 0x85, 0x00, 0x00, 0x00
        .byte 0x03, 0x00, 0x00, 0x00
        .byte 0x45, 0x01, 0x00, 0x00
        .byte 0x04, 0x00, 0x00, 0x00
        .byte 0x07, 0x00, 0x00, 0x00
        .byte 0x05, 0x00, 0x00, 0x00
        .byte 0x9e, 0x00, 0x00, 0x00
        .byte 0x06, 0x00, 0x00, 0x00
        .byte 0x1b, 0x01, 0x00, 0x00
        .byte 0x07, 0x00, 0x00, 0x00
        .byte 0x36, 0x00, 0x00, 0x00
        .byte 0x08, 0x00, 0x00, 0x00
        .byte 0x04, 0x00, 0x00, 0x00
        .byte 0x09, 0x00, 0x00, 0x00
        .byte 0x18, 0x01, 0x00, 0x00
        .byte 0x0a, 0x00, 0x00, 0x00
        .byte 0x9b, 0x00, 0x00, 0x00
        .byte 0x0b, 0x00, 0x00, 0x00
        .byte 0x68, 0x00, 0x00, 0x00
        .byte 0x0c, 0x00, 0x00, 0x00
        .byte 0x42, 0x00, 0x00, 0x00
        .byte 0x0d, 0x00, 0x00, 0x00
        .byte 0x01, 0x00, 0x00, 0x00
        .byte 0x0e, 0x00, 0x00, 0x00
        .byte 0x98, 0x00, 0x00, 0x00
        .byte 0x0f, 0x00, 0x00, 0x00
        .byte 0x15, 0x01, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00

	.global gUnknown_80B6994
gUnknown_80B6994: @ 80B6994
        .byte 0x01, 0x00, 0x00, 0x00
        .byte 0x07, 0x00, 0x00, 0x00
        .byte 0x01, 0x00, 0x00, 0x00
        .byte 0x9e, 0x00, 0x00, 0x00
        .byte 0x03, 0x00, 0x00, 0x00
        .byte 0x18, 0x01, 0x00, 0x00
        .byte 0x03, 0x00, 0x00, 0x00
        .byte 0x98, 0x00, 0x00, 0x00
        .byte 0x02, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00

	.global gPMDBuildVersion
gPMDBuildVersion: @ 80B69BC
        .string "PKDi ver 1.0 [Apr 28 2006] 16:37:54\0"
        .align 2,0

        .global titlen0_text
        titlen0_text:
        .string "titlen0\0"
        .align 2,0

        .global titlen1_text
        titlen1_text:
        .string "titlen1\0"
        .align 2,0

        .global titlen2_text
        titlen2_text:
        .string "titlen2\0"
        .align 2,0

	.global gLoadScreenBackgroundFileNames
gLoadScreenBackgroundFileNames: @ 80B69F8
        .4byte titlen0_text
        .4byte titlen1_text
        .4byte titlen2_text

        .global titlen0p_text
        titlen0p_text:
        .string "titlen0p\0"
        .align 2,0

        .global titlen1p_text
        titlen1p_text:
        .string "titlen1p\0"
        .align 2,0

        .global titlen2p_text
        titlen2p_text:
        .string "titlen2p\0"
        .align 2,0

	.global gLoadScreenBackgroundPaletteFileNames
gLoadScreenBackgroundPaletteFileNames: @ 80B6A28
        .4byte titlen0p_text
        .4byte titlen1p_text
        .4byte titlen2p_text

gSaveTextQuicksaving:: @ 80B6A34
	.string "{CENTER_ALIGN}Quicksaving your adventure...\n"
	.string "{CENTER_ALIGN}Please don{APOSTROPHE}t turn off the power.\0"
	.align 2, 0

gSaveTextYourAdventureHasBeenSaved:: @ 80B6A7C
	.string "{CENTER_ALIGN}Your adventure has been saved.\0"
	.align 2, 0

gSaveTextYourAdventureHasBeenSavedLong:: @ 80B6AA0
	.string "{CENTER_ALIGN}Your adventure has been saved.\n"
	.string "{CENTER_ALIGN}When you are in a dungeon{COMMA} quicksave\n"
	.string "{CENTER_ALIGN}your progress before ending the game.\0"
	.align 2, 0

gSaveTextTheDataCouldNotBeWritten:: @ 80B6B14
	.string "{CENTER_ALIGN}The data could not be written.\n"
	.string "{CENTER_ALIGN}Please turn off the power and remove\n"
	.string "{CENTER_ALIGN}and reinsert the DS Card.\0"
	.align 2, 0

gSaveTextFailed:: @ 80B6B78
	.string "{CENTER_ALIGN}Save failed.\0"
	.align 2, 0

gSaveTextError:: @ 80B6B88
	.string "{CENTER_ALIGN}Error reading data.\n"
	.string "{CENTER_ALIGN}Please turn off the power and reinsert\n"
	.string "{CENTER_ALIGN}the DS Game Card.\0"
	.align 2, 0

gSaveTextCantResume:: @ 80B6BDC
	.string "{CENTER_ALIGN}Your data was not properly saved{COMMA}\n"
	.string "{CENTER_ALIGN}so your game cannot be resumed\n"
	.string "{CENTER_ALIGN}from your last spot.{EXTRA_MSG}{CENTER_ALIGN}Your last outing is considered a defeat.\n"
	.string "{CENTER_ALIGN}Before shutting down{COMMA} save in your\n"
	.string "{CENTER_ALIGN}team base{COMMA} or quicksave in a dungeon.\0"
	.align 2, 0

gSaveTextMayNotResume:: @ 80B6CB8
	.string "{CENTER_ALIGN}You may not resume your dungeon\n"
	.string "{CENTER_ALIGN}adventure using this saved data.\n"
	.string "{CENTER_ALIGN}Your last outing is considered a defeat.\0"
	.align 2, 0

@ event_flag.c
.string "pksdir0\0"

	.align 2, 0
	.global gUnknown_80B6D30
gUnknown_80B6D30:
    .2byte 5, 7, 0, 0, 1, 0; .4byte gUnknown_80B6D88
    .2byte 5, 7, 2, 0, 1, 0; .4byte gUnknown_80B6D80
    .2byte 5, 7, 4, 0, 1, 0; .4byte gUnknown_80B6D78
    .2byte 5, 7, 6, 0, 1, 0; .4byte gUnknown_80B6D70

gUnknown_80B6D70:
    .string "LOCAL3\0"
    .align 2, 0

gUnknown_80B6D78:
    .string "LOCAL2\0"
    .align 2, 0

gUnknown_80B6D80:
    .string "LOCAL1\0"
    .align 2, 0

gUnknown_80B6D88:
    .string "LOCAL0\0"
    .align 2, 0

	.global gUnknown_80B6D90
gUnknown_80B6D90: @ 80B6D90
        .4byte gUnknown_80B7144
        .byte 0x00, 0x00, 0x00, 0x00
        .4byte gUnknown_80B713C
        .byte 0xff, 0xff, 0xff, 0xff
        .4byte gUnknown_80B7134
        .byte 0xff, 0xff, 0xff, 0xff
        .4byte gUnknown_80B712C
        .byte 0xff, 0xff, 0xff, 0xff
        .4byte gUnknown_80B7124
        .byte 0xff, 0xff, 0xff, 0xff
        .4byte gUnknown_80B711C
        .byte 0xff, 0xff, 0xff, 0xff
        .4byte gUnknown_80B7114
        .byte 0xff, 0xff, 0xff, 0xff
        .4byte gUnknown_80B710C
        .byte 0xff, 0xff, 0xff, 0xff
        .4byte gUnknown_80B7104
        .byte 0xff, 0xff, 0xff, 0xff
        .4byte gUnknown_80B70FC
        .byte 0xff, 0xff, 0xff, 0xff
        .4byte gUnknown_80B70F4
        .byte 0xff, 0xff, 0xff, 0xff
        .4byte gUnknown_80B70EC
        .byte 0xff, 0xff, 0xff, 0xff
        .4byte gUnknown_80B70E4
        .byte 0xff, 0xff, 0xff, 0xff
        .4byte gUnknown_80B70DC
        .byte 0xff, 0xff, 0xff, 0xff
        .4byte gUnknown_80B70D4
        .byte 0xff, 0xff, 0xff, 0xff
        .4byte gUnknown_80B70CC
        .byte 0xff, 0xff, 0xff, 0xff
        .4byte gUnknown_80B70C4
        .byte 0xff, 0xff, 0xff, 0xff
        .4byte gUnknown_80B70BC
        .byte 0xff, 0xff, 0xff, 0xff
        .4byte gUnknown_80B70B4
        .byte 0xff, 0xff, 0xff, 0xff
        .4byte gUnknown_80B70AC
        .byte 0xff, 0xff, 0xff, 0xff
        .4byte gUnknown_80B70A4
        .byte 0xff, 0xff, 0xff, 0xff
        .4byte gUnknown_80B709C
        .byte 0xff, 0xff, 0xff, 0xff
        .4byte gUnknown_80B7094
        .byte 0xff, 0xff, 0xff, 0xff
        .4byte gUnknown_80B708C
        .byte 0xff, 0xff, 0xff, 0xff
        .4byte gUnknown_80B7084
        .byte 0xff, 0xff, 0xff, 0xff
        .4byte gUnknown_80B707C
        .byte 0xff, 0xff, 0xff, 0xff
        .4byte gUnknown_80B7074
        .byte 0xff, 0xff, 0xff, 0xff
        .4byte gUnknown_80B706C
        .byte 0xff, 0xff, 0xff, 0xff
        .4byte gUnknown_80B7064
        .byte 0xff, 0xff, 0xff, 0xff
        .4byte gUnknown_80B705C
        .byte 0x01, 0x00, 0x00, 0x00
        .4byte gUnknown_80B7054
        .byte 0x01, 0x00, 0x00, 0x00
        .4byte gUnknown_80B704C
        .byte 0x01, 0x00, 0x00, 0x00
        .4byte gUnknown_80B7044
        .byte 0x02, 0x00, 0x00, 0x00
        .4byte gUnknown_80B703C
        .byte 0xff, 0xff, 0xff, 0xff
        .4byte gUnknown_80B7034
        .byte 0xff, 0xff, 0xff, 0xff
        .4byte gUnknown_80B702C
        .byte 0x03, 0x00, 0x00, 0x00
        .4byte gUnknown_80B7024
        .byte 0x01, 0x00, 0x00, 0x00
        .4byte gUnknown_80B701C
        .byte 0x03, 0x00, 0x00, 0x00
        .4byte gUnknown_80B7014
        .byte 0x01, 0x00, 0x00, 0x00
        .4byte gUnknown_80B700C
        .byte 0x01, 0x00, 0x00, 0x00
        .4byte gUnknown_80B7004
        .byte 0x01, 0x00, 0x00, 0x00
        .4byte gUnknown_80B6FFC
        .byte 0x01, 0x00, 0x00, 0x00
        .4byte gUnknown_80B6FF4
        .byte 0x01, 0x00, 0x00, 0x00
        .4byte gUnknown_80B6FEC
        .byte 0x02, 0x00, 0x00, 0x00
        .4byte gUnknown_80B6FE4
        .byte 0x01, 0x00, 0x00, 0x00
        .4byte gUnknown_80B6FDC
        .byte 0x03, 0x00, 0x00, 0x00
        .4byte gUnknown_80B6FD4
        .byte 0x01, 0x00, 0x00, 0x00
        .4byte gUnknown_80B6FCC
        .byte 0x01, 0x00, 0x00, 0x00
        .4byte gUnknown_80B6FC4
        .byte 0x03, 0x00, 0x00, 0x00
        .4byte gUnknown_80B6FBC
        .byte 0x01, 0x00, 0x00, 0x00
        .4byte gUnknown_80B6FB4
        .byte 0x03, 0x00, 0x00, 0x00
        .4byte gUnknown_80B6FAC
        .byte 0x01, 0x00, 0x00, 0x00
        .4byte gUnknown_80B6FA4
        .byte 0x03, 0x00, 0x00, 0x00
        .4byte gUnknown_80B6F9C
        .byte 0x01, 0x00, 0x00, 0x00
        .4byte gUnknown_80B6F94
        .byte 0x01, 0x00, 0x00, 0x00
        .4byte gUnknown_80B6F8C
        .byte 0x02, 0x00, 0x00, 0x00
        .4byte gUnknown_80B6F84
        .byte 0xff, 0xff, 0xff, 0xff
        .4byte gUnknown_80B6F78
        .byte 0xff, 0xff, 0xff, 0xff
        .4byte gUnknown_80B6F68
        .byte 0xff, 0xff, 0xff, 0xff

        .global gUnknown_80B6F68
        gUnknown_80B6F68:
        .string "DEBUG GROUND\0"
        .align 2,0
        .global gUnknown_80B6F78
        gUnknown_80B6F78:
        .string "NEXT DAY\0"
        .align 2,0
        .global gUnknown_80B6F84
        gUnknown_80B6F84:
        .string "R00E01A\0"
        .align 2,0
        .global gUnknown_80B6F8C
        gUnknown_80B6F8C:
        .string "S09E01C\0"
        .align 2,0
        .global gUnknown_80B6F94
        gUnknown_80B6F94:
        .string "S09E01B\0"
        .align 2,0
        .global gUnknown_80B6F9C
        gUnknown_80B6F9C:
        .string "S09E01A\0"
        .align 2,0
        .global gUnknown_80B6FA4
        gUnknown_80B6FA4:
        .string "S08E01B\0"
        .align 2,0
        .global gUnknown_80B6FAC
        gUnknown_80B6FAC:
        .string "S08E01A\0"
        .align 2,0
        .global gUnknown_80B6FB4
        gUnknown_80B6FB4:
        .string "S07E01B\0"
        .align 2,0
        .global gUnknown_80B6FBC
        gUnknown_80B6FBC:
        .string "S07E01A\0"
        .align 2,0
        .global gUnknown_80B6FC4
        gUnknown_80B6FC4:
        .string "S06E01C\0"
        .align 2,0
        .global gUnknown_80B6FCC
        gUnknown_80B6FCC:
        .string "S06E01B\0"
        .align 2,0
        .global gUnknown_80B6FD4
        gUnknown_80B6FD4:
        .string "S06E01A\0"
        .align 2,0
        .global gUnknown_80B6FDC
        gUnknown_80B6FDC:
        .string "S05E01B\0"
        .align 2,0
        .global gUnknown_80B6FE4
        gUnknown_80B6FE4:
        .string "S05E01A\0"
        .align 2,0
        .global gUnknown_80B6FEC
        gUnknown_80B6FEC:
        .string "S04E01F\0"
        .align 2,0
        .global gUnknown_80B6FF4
        gUnknown_80B6FF4:
        .string "S04E01E\0"
        .align 2,0
        .global gUnknown_80B6FFC
        gUnknown_80B6FFC:
        .string "S04E01D\0"
        .align 2,0
        .global gUnknown_80B7004
        gUnknown_80B7004:
        .string "S04E01C\0"
        .align 2,0
        .global gUnknown_80B700C
        gUnknown_80B700C:
        .string "S04E01B\0"
        .align 2,0
        .global gUnknown_80B7014
        gUnknown_80B7014:
        .string "S04E01A\0"
        .align 2,0
        .global gUnknown_80B701C
        gUnknown_80B701C:
        .string "S03E01B\0"
        .align 2,0
        .global gUnknown_80B7024
        gUnknown_80B7024:
        .string "S03E01A\0"
        .align 2,0
        .global gUnknown_80B702C
        gUnknown_80B702C:
        .string "S02E02B\0"
        .align 2,0
        .global gUnknown_80B7034
        gUnknown_80B7034:
        .string "S02E02A\0"
        .align 2,0
        .global gUnknown_80B703C
        gUnknown_80B703C:
        .string "S02E01A\0"
        .align 2,0
        .global gUnknown_80B7044
        gUnknown_80B7044:
        .string "S01E02B\0"
        .align 2,0
        .global gUnknown_80B704C
        gUnknown_80B704C:
        .string "S01E02A\0"
        .align 2,0
        .global gUnknown_80B7054
        gUnknown_80B7054:
        .string "S01E01B\0"
        .align 2,0
        .global gUnknown_80B705C
        gUnknown_80B705C:
        .string "S01E01A\0"
        .align 2,0
        .global gUnknown_80B7064
        gUnknown_80B7064:
        .string "S00E01A\0"
        .align 2,0
        .global gUnknown_80B706C
        gUnknown_80B706C:
        .string "M02END\0"
        .align 2,0
        .global gUnknown_80B7074
        gUnknown_80B7074:
        .string "M02E02H\0"
        .align 2,0
        .global gUnknown_80B707C
        gUnknown_80B707C:
        .string "M02E02G\0"
        .align 2,0
        .global gUnknown_80B7084
        gUnknown_80B7084:
        .string "M02E02F\0"
        .align 2,0
        .global gUnknown_80B708C
        gUnknown_80B708C:
        .string "M02E02E\0"
        .align 2,0
        .global gUnknown_80B7094
        gUnknown_80B7094:
        .string "M02E02D\0"
        .align 2,0
        .global gUnknown_80B709C
        gUnknown_80B709C:
        .string "M02E02C\0"
        .align 2,0
        .global gUnknown_80B70A4
        gUnknown_80B70A4:
        .string "M02E02B\0"
        .align 2,0
        .global gUnknown_80B70AC
        gUnknown_80B70AC:
        .string "M02E02A\0"
        .align 2,0
        .global gUnknown_80B70B4
        gUnknown_80B70B4:
        .string "M02E01A\0"
        .align 2,0
        .global gUnknown_80B70BC
        gUnknown_80B70BC:
        .string "M01END\0"
        .align 2,0
        .global gUnknown_80B70C4
        gUnknown_80B70C4:
        .string "M01E10A\0"
        .align 2,0
        .global gUnknown_80B70CC
        gUnknown_80B70CC:
        .string "M01E09A\0"
        .align 2,0
        .global gUnknown_80B70D4
        gUnknown_80B70D4:
        .string "M01E08B\0"
        .align 2,0
        .global gUnknown_80B70DC
        gUnknown_80B70DC:
        .string "M01E08A\0"
        .align 2,0
        .global gUnknown_80B70E4
        gUnknown_80B70E4:
        .string "M01E07B\0"
        .align 2,0
        .global gUnknown_80B70EC
        gUnknown_80B70EC:
        .string "M01E07A\0"
        .align 2,0
        .global gUnknown_80B70F4
        gUnknown_80B70F4:
        .string "M01E06A\0"
        .align 2,0
        .global gUnknown_80B70FC
        gUnknown_80B70FC:
        .string "M01E05B\0"
        .align 2,0
        .global gUnknown_80B7104
        gUnknown_80B7104:
        .string "M01E05A\0"
        .align 2,0
        .global gUnknown_80B710C
        gUnknown_80B710C:
        .string "M01E04B\0"
        .align 2,0
        .global gUnknown_80B7114
        gUnknown_80B7114:
        .string "M01E04A\0"
        .align 2,0
        .global gUnknown_80B711C
        gUnknown_80B711C:
        .string "M01E03A\0"
        .align 2,0
        .global gUnknown_80B7124
        gUnknown_80B7124:
        .string "M01E02B\0"
        .align 2,0
        .global gUnknown_80B712C
        gUnknown_80B712C:
        .string "M01E02A\0"
        .align 2,0
        .global gUnknown_80B7134
        gUnknown_80B7134:
        .string "M01E01A\0"
        .align 2,0
        .global gUnknown_80B713C
        gUnknown_80B713C:
        .string "M00E01A\0"
        .align 2,0

	.global gUnknown_80B7144
gUnknown_80B7144: @ 80B7144
        .string "NONE\0"
        .align 2,0

	.global gUnknown_80B714C
gUnknown_80B714C: @ 80B714C
        .4byte TwoOneText
        .4byte TwoOneText
        .4byte OneTwoSevenText
        .4byte FourText
        .4byte FiveText
        .4byte SixText
        .4byte TwoTwoEightText
        .4byte ThreeText
        .4byte NineText
        .4byte EndText

        .global EndText
        EndText:
        .string "END\0"

        .global NineText
        NineText:
        .string "9\0"
        .align 2,0

        .global ThreeText
        ThreeText:
        .string "3\0"
        .align 2,0

        .global TwoTwoEightText
        TwoTwoEightText:
        .string "2-2 8\0"
        .align 2,0

        .global SixText
        SixText:
        .string "6\0"
        .align 2,0

        .global FiveText
        FiveText:
        .string "5\0"
        .align 2,0

        .global FourText
        FourText:
        .string "4\0"
        .align 2,0

        .global OneTwoSevenText
        OneTwoSevenText:
        .string "1-2 7\0"
        .align 2,0

        .global TwoOneText
        TwoOneText:
        .string "2-1\0"
        .align 2,0

	.global gUnknown_80B71A0
gUnknown_80B71A0: @ 80B71A0
        .4byte CISTART_text
        .4byte CECONTINUE_text
        .4byte CNLAST_text
        .4byte CWEND_text

        .global CWEND_text
        CWEND_text:
        .string "{COLOR_1 RED_2}END{END_COLOR_TEXT_1}\0"
        .align 2,0

        .global CNLAST_text
        CNLAST_text:
        .string "{COLOR_1 YELLOW_5}LAST{END_COLOR_TEXT_1}\0"
        .align 2,0

        .global CECONTINUE_text
        CECONTINUE_text:
        .string "{COLOR_1 GENDER_COLOR}CONTINUE{END_COLOR_TEXT_1}\0"
        .align 2,0

        .global CISTART_text
        CISTART_text:
        .string "{COLOR_1 GREEN_2}START{END_COLOR_TEXT_1}\0"
        .align 2,0

	.global gUnknown_80B71E4
gUnknown_80B71E4: @ 80B71E4
    @ [struct unkEventStruct]
    .2byte 105, 1
    .2byte 106, 2
    .2byte 107, 3
    .2byte 108, 4
    .2byte 109, 5
    .2byte 110, 6
    .2byte 111, 7
    .2byte 112, 8
    .2byte 113, 9
    .2byte 114, 10
    .2byte 115, 11
    .2byte 116, 12
    .2byte 117, 13
    .2byte 118, 14
    .2byte 119, 15
    .2byte 120, 16
    .2byte 121, 17
    .2byte 122, 18
    .2byte 123, 19
    .2byte 124, 20
    .2byte 125, 21
    .2byte 126, 22
    .2byte 127, 23
    .2byte 128, 24
    .2byte 129, 25
    .2byte 130, 26
    .2byte 131, 27
    .2byte 132, 28
    .2byte 133, 29
    .2byte 134, 30
    .2byte 135, 31
    .2byte 136, 32
    .2byte 137, 33
    .2byte 138, 34
    .2byte 139, 35
    .2byte 140, 36
    .2byte 141, 37
    .2byte 142, 38
    .2byte 143, 39
    .2byte 144, 40
    .2byte 145, 41
    .2byte 146, 42
    .2byte 147, 43
    .2byte 148, 44
    .2byte 149, 45
    .2byte 150, 46
    .2byte 151, 47
    .2byte 152, 48
    .2byte 153, 49
    .2byte 154, 50
    .2byte 155, 51
    .2byte 156, 52
    .2byte 157, 53
    .2byte 158, 54
    .2byte 159, 55
    .2byte 160, 56
    .2byte 161, 57
    .2byte -1, 0

	.global gUnknown_80B72CC
gUnknown_80B72CC: @ 80B72CC
        .string "SCENARIO CALC [%3d] %4d %4d -> %4d %4d\0"
        .align 2,0

        .global EventFlagFile_Text
        EventFlagFile_Text:
        .string "../main/event_flag.c\0"
        .align 2,0

        .global FlagCalc_Text
        FlagCalc_Text:
        .string "_FlagCalc\0"
        .align 2,0

	.global gUnknown_80B7318
gUnknown_80B7318: @ 80B7318
        .4byte EventFlagFile_Text
        .byte 0x51, 0x05, 0x00, 0x00
        .4byte FlagCalc_Text

	.global gUnknown_80B7324
gUnknown_80B7324: @ 80B7324
        .string "event flag expansion error %d\0"
        .align 2,0

        .global FlagJudge_Text
        FlagJudge_Text:
        .string "_FlagJudge\0"
        .align 2,0

	.global gUnknown_80B7350
gUnknown_80B7350: @ 80B7350
        .4byte EventFlagFile_Text
        .byte 0x7C, 0x05, 0x00, 0x00
        .4byte FlagJudge_Text

	.global gUnknown_80B735C
gUnknown_80B735C: @ 80B735C
        .string "event flag rule error %d\0"
        .align 2,0

	.global gUnknown_80B7378
gUnknown_80B7378: @ 80B7378
        .string "error number\0"
        .align 2,0

	.global gUnknown_80B7388
gUnknown_80B7388: @ 80B7388
        .string "1-1\0"

@ code.c
.string "pksdir0\0"

	.global gUnknown_80B7394
gUnknown_80B7394: @ 80B7394
    .2byte 6, 2, 0, 0, 1, 29; .4byte gUnknown_80B7DF8
    .2byte 6, 2, 4, 0, 1, 0; .4byte gUnknown_80B7DEC
    .2byte 2, 2, 110, 0, 2, 0; .4byte gUnknown_80B7DDC
    .2byte 2, 2, 112, 0, 2, 0; .4byte gUnknown_80B7DCC
    .2byte 2, 2, 114, 0, 2, 0; .4byte gUnknown_80B7DBC
    .2byte 2, 2, 116, 0, 2, 0; .4byte gUnknown_80B7DAC
    .2byte 2, 2, 118, 0, 2, 0; .4byte gUnknown_80B7D9C
    .2byte 2, 2, 120, 0, 2, 0; .4byte gUnknown_80B7D8C
    .2byte 2, 2, 122, 0, 2, 0; .4byte gUnknown_80B7D7C
    .2byte 2, 2, 124, 0, 2, 0; .4byte gUnknown_80B7D6C
    .2byte 2, 2, 126, 0, 2, 0; .4byte gUnknown_80B7D5C
    .2byte 2, 2, 128, 0, 2, 0; .4byte gUnknown_80B7D4C
    .2byte 2, 2, 130, 0, 2, 0; .4byte gUnknown_80B7D3C
    .2byte 5, 2, 44, 0, 1, 0; .4byte gUnknown_80B7D2C
    .2byte 2, 2, 132, 0, 1, 0; .4byte gUnknown_80B7D18
    .2byte 5, 2, 46, 0, 1, 0; .4byte gUnknown_80B7D08
    .2byte 5, 2, 48, 0, 1, 0; .4byte gUnknown_80B7CFC
    .2byte 5, 2, 50, 0, 1, 0; .4byte gUnknown_80B7CEC
    .2byte 5, 2, 52, 0, 1, 0; .4byte gUnknown_80B7CDC
    .2byte 5, 2, 54, 0, 1, 0; .4byte gUnknown_80B7CCC
    .2byte 5, 2, 56, 0, 1, 0; .4byte gUnknown_80B7CB8
    .2byte 4, 2, 94, 0, 1, 0; .4byte gUnknown_80B7CA0
    .2byte 2, 2, 133, 0, 1, 0; .4byte gUnknown_80B7C90
    .2byte 8, 2, 0, 0, 1, 0; .4byte gUnknown_80B7C84
    .2byte 2, 2, 134, 0, 1, 0; .4byte gUnknown_80B7C78
    .2byte 2, 2, 135, 0, 1, 0; .4byte gUnknown_80B7C6C
    .2byte 2, 2, 136, 0, 1, 0; .4byte gUnknown_80B7C5C
    .2byte 3, 2, 96, 0, 1, 0; .4byte gUnknown_80B7C4C
    .2byte 2, 2, 137, 0, 1, 0; .4byte gUnknown_80B7C40
    .2byte 2, 2, 138, 0, 1, 0; .4byte gUnknown_80B7C30
    .2byte 2, 2, 139, 0, 1, 0; .4byte gUnknown_80B7C20
    .2byte 5, 2, 58, 0, 1, 0; .4byte gUnknown_80B7C10
    .2byte 8, 2, 0, 0, 1, 0; .4byte gUnknown_80B7C04
    .2byte 8, 2, 0, 0, 1, 0; .4byte gUnknown_80B7BF8
    .2byte 8, 2, 0, 0, 1, 0; .4byte gUnknown_80B7BF0
    .2byte 8, 2, 0, 0, 1, 0; .4byte gUnknown_80B7BE4
    .2byte 1, 2, 140, 0, 16, 0; .4byte gUnknown_80B7BD8
    .2byte 3, 2, 97, 0, 1, 0; .4byte gUnknown_80B7BCC
    .2byte 3, 2, 98, 0, 1, 0; .4byte gUnknown_80B7BB8
    .2byte 3, 2, 99, 0, 1, 0; .4byte gUnknown_80B7BAC
    .2byte 3, 2, 100, 0, 1, 0; .4byte gUnknown_80B7BA0
    .2byte 3, 2, 101, 0, 1, 0; .4byte gUnknown_80B7B94
    .2byte 3, 2, 102, 0, 1, 0; .4byte gUnknown_80B7B78
    .2byte 1, 2, 142, 0, 64, 0; .4byte gUnknown_80B7B5C
    .2byte 1, 2, 150, 0, 64, 0; .4byte gUnknown_80B7B40
    .2byte 1, 2, 158, 0, 64, 0; .4byte gUnknown_80B7B20
    .2byte 1, 2, 166, 0, 32, 0; .4byte gUnknown_80B7B08
    .2byte 1, 2, 170, 0, 32, 0; .4byte gUnknown_80B7AF0
    .2byte 1, 2, 174, 0, 96, 0; .4byte gUnknown_80B7ADC
    .2byte 1, 2, 186, 0, 96, 0; .4byte gUnknown_80B7AC8
    .2byte 6, 2, 8, 0, 3, 0; .4byte gUnknown_80B7ABC
    .2byte 6, 2, 20, 0, 3, 0; .4byte gUnknown_80B7AB0
    .2byte 6, 2, 32, 0, 3, 0; .4byte gUnknown_80B7AA0
    .2byte 3, 2, 103, 0, 3, 0; .4byte gUnknown_80B7A8C
    .2byte 5, 5, 60, 0, 1, 0; .4byte gUnknown_80B7A7C
    .2byte 5, 5, 62, 0, 1, 0; .4byte gUnknown_80B7A70
    .2byte 1, 5, 198, 0, 8, 0; .4byte gUnknown_80B7A60
    .2byte 5, 5, 64, 0, 1, 0; .4byte gUnknown_80B7A54
    .2byte 1, 5, 199, 0, 32, 0; .4byte gUnknown_80B7A40
    .2byte 1, 5, 203, 0, 32, 0; .4byte gUnknown_80B7A2C
    .2byte 1, 5, 207, 0, 16, 0; .4byte gUnknown_80B7A18
    .2byte 1, 5, 209, 0, 16, 0; .4byte gUnknown_80B7A04
    .2byte 5, 5, 66, 0, 8, 0; .4byte gUnknown_80B79F8
    .2byte 1, 5, 211, 0, 16, 0; .4byte gUnknown_80B79EC
    .2byte 1, 6, 213, 0, 16, 0; .4byte gUnknown_80B79DC
    .2byte 5, 6, 82, 0, 2, 0; .4byte gUnknown_80B79CC
    .2byte 5, 6, 86, 0, 4, 0; .4byte gUnknown_80B79C0
    .2byte 3, 6, 106, 0, 1, 0; .4byte gUnknown_80B79AC
    .2byte 3, 6, 107, 0, 1, 0; .4byte gUnknown_80B7998
    .2byte 3, 6, 108, 0, 1, 0; .4byte gUnknown_80B7984
    .2byte 3, 6, 109, 0, 1, 0; .4byte gUnknown_80B7970
    .2byte 1, 6, 215, 0, 16, 0; .4byte gUnknown_80B7960
    .2byte 1, 6, 217, 0, 16, 0; .4byte gUnknown_80B7950
    .2byte 1, 6, 219, 0, 16, 0; .4byte gUnknown_80B7940
    .2byte 1, 6, 221, 0, 16, 0; .4byte gUnknown_80B7930
    .2byte 1, 6, 223, 0, 8, 0; .4byte gUnknown_80B791C
    .2byte 1, 6, 224, 0, 8, 0; .4byte gUnknown_80B7908
    .2byte 1, 6, 225, 0, 8, 0; .4byte gUnknown_80B78F4
    .2byte 1, 6, 226, 0, 8, 0; .4byte gUnknown_80B78E0
    .2byte 1, 6, 227, 0, 8, 0; .4byte gUnknown_80B78CC
    .2byte 1, 6, 228, 0, 8, 0; .4byte gUnknown_80B78B8
    .2byte 0, 0, 229, 0, 0, 0; .4byte gUnknown_80B78B4

gUnknown_80B78B4:
    .string "SUM\0"

gUnknown_80B78B8:
    .string "EVENT_M02E01A_2N\0"
    .align 2, 0

gUnknown_80B78CC:
    .string "EVENT_M01E10A_5N\0"
    .align 2, 0

gUnknown_80B78E0:
    .string "EVENT_M01E10A_3N\0"
    .align 2, 0

gUnknown_80B78F4:
    .string "EVENT_M01E10A_1N\0"
    .align 2, 0

gUnknown_80B7908:
    .string "EVENT_M01E09A_8N\0"
    .align 2, 0

gUnknown_80B791C:
    .string "EVENT_M01E09A_2N\0"
    .align 2, 0

gUnknown_80B7930:
    .string "EVENT_T01P03\0"
    .align 2, 0

gUnknown_80B7940:
    .string "EVENT_T01P02\0"
    .align 2, 0

gUnknown_80B7950:
    .string "EVENT_T01P01\0"
    .align 2, 0

gUnknown_80B7960:
    .string "EVENT_B01P01\0"
    .align 2, 0

gUnknown_80B7970:
    .string "EVENT_ORNAMENT_04\0"
    .align 2, 0

gUnknown_80B7984:
    .string "EVENT_ORNAMENT_03\0"
    .align 2, 0

gUnknown_80B7998:
    .string "EVENT_ORNAMENT_02\0"
    .align 2, 0

gUnknown_80B79AC:
    .string "EVENT_ORNAMENT_01\0"
    .align 2, 0

gUnknown_80B79C0:
    .string "EVENT_GONBE\0"
    .align 2, 0

gUnknown_80B79CC:
    .string "EVENT_S08E01\0"
    .align 2, 0

gUnknown_80B79DC:
    .string "EVENT_S07E01\0"
    .align 2, 0

gUnknown_80B79EC:
    .string "INN_TEMP\0"
    .align 2, 0

gUnknown_80B79F8:
    .string "SHOP_TEMP\0"
    .align 2, 0

gUnknown_80B7A04:
    .string "DELIVER_ITEM_TEMP\0"
    .align 2, 0

gUnknown_80B7A18:
    .string "DELIVER_ITEM_STATIC\0"
    .align 2, 0

gUnknown_80B7A2C:
    .string "STATION_ITEM_TEMP\0"
    .align 2, 0

gUnknown_80B7A40:
    .string "STATION_ITEM_STATIC\0"
    .align 2, 0

gUnknown_80B7A54:
    .string "EVENT_LOCAL\0"
    .align 2, 0

gUnknown_80B7A60:
    .string "MAP_LOCAL_DOOR\0"
    .align 2, 0

gUnknown_80B7A70:
    .string "MAP_LOCAL\0"
    .align 2, 0

gUnknown_80B7A7C:
    .string "GROUND_LOCAL\0"
    .align 2, 0

gUnknown_80B7A8C:
    .string "POSITION_DIRECTION\0"
    .align 2, 0

gUnknown_80B7AA0:
    .string "POSITION_HEIGHT\0"
    .align 2, 0

gUnknown_80B7AB0:
    .string "POSITION_Y\0"
    .align 2, 0

gUnknown_80B7ABC:
    .string "POSITION_X\0"
    .align 2, 0

gUnknown_80B7AC8:
    .string "DUNGEON_CLEAR_LIST\0"
    .align 2, 0

gUnknown_80B7ADC:
    .string "DUNGEON_ENTER_LIST\0"
    .align 2, 0

gUnknown_80B7AF0:
    .string "TRAINING_PRESENT_LIST\0"
    .align 2, 0

gUnknown_80B7B08:
    .string "TRAINING_CONQUEST_LIST\0"
    .align 2, 0

gUnknown_80B7B20:
    .string "RESCUE_SCENARIO_CONQUEST_LIST\0"
    .align 2, 0

gUnknown_80B7B40:
    .string "RESCUE_SCENARIO_JOB_LIST\0"
    .align 2, 0

gUnknown_80B7B5C:
    .string "RESCUE_SCENARIO_ORDER_LIST\0"
    .align 2, 0

gUnknown_80B7B78:
    .string "FLAG_KIND_CHANGE_REQUEST\0"
    .align 2, 0

gUnknown_80B7B94:
    .string "FLAG_KIND\0"
    .align 2, 0

gUnknown_80B7BA0:
    .string "BASE_LEVEL\0"
    .align 2, 0

gUnknown_80B7BAC:
    .string "BASE_KIND\0"
    .align 2, 0

gUnknown_80B7BB8:
    .string "PARTNER_TALK_KIND\0"
    .align 2, 0

gUnknown_80B7BCC:
    .string "WARP_LOCK\0"
    .align 2, 0

gUnknown_80B7BD8:
    .string "WARP_LIST\0"
    .align 2, 0

gUnknown_80B7BE4:
    .string "BANK_GOLD\0"
    .align 2, 0

gUnknown_80B7BF0:
    .string "GOLD\0"
    .align 2, 0

gUnknown_80B7BF8:
    .string "UNIT_SUM\0"
    .align 2, 0

gUnknown_80B7C04:
    .string "FRIEND_SUM\0"
    .align 2, 0

gUnknown_80B7C10:
    .string "NEW_FRIEND_KIND\0"
    .align 2, 0

gUnknown_80B7C20:
    .string "PARTNER2_KIND\0"
    .align 2, 0

gUnknown_80B7C30:
    .string "PARTNER1_KIND\0"
    .align 2, 0

gUnknown_80B7C40:
    .string "PLAYER_KIND\0"
    .align 2, 0

gUnknown_80B7C4C:
    .string "WEATHER_KIND\0"
    .align 2, 0

gUnknown_80B7C5C:
    .string "CONDITION_KIND\0"
    .align 2, 0

gUnknown_80B7C6C:
    .string "CLEAR_COUNT\0"
    .align 2, 0

gUnknown_80B7C78:
    .string "START_MODE\0"
    .align 2, 0

gUnknown_80B7C84:
    .string "SCRIPT_MODE\0"
    .align 2, 0

gUnknown_80B7C90:
    .string "DUNGEON_RESULT\0"
    .align 2, 0

gUnknown_80B7CA0:
    .string "DUNGEON_ENTER_FREQUENCY\0"
    .align 2, 0

gUnknown_80B7CB8:
    .string "DUNGEON_ENTER_INDEX\0"
    .align 2, 0

gUnknown_80B7CCC:
    .string "DUNGEON_ENTER\0"
    .align 2, 0

gUnknown_80B7CDC:
    .string "DUNGEON_SELECT\0"
    .align 2, 0

gUnknown_80B7CEC:
    .string "GROUND_PLACE\0"
    .align 2, 0

gUnknown_80B7CFC:
    .string "GROUND_MAP\0"
    .align 2, 0

gUnknown_80B7D08:
    .string "GROUND_GETOUT\0"
    .align 2, 0

gUnknown_80B7D18:
    .string "GROUND_ENTER_LINK\0"
    .align 2, 0

gUnknown_80B7D2C:
    .string "GROUND_ENTER\0"
    .align 2, 0

gUnknown_80B7D3C:
    .string "SCENARIO_SUB9\0"
    .align 2, 0

gUnknown_80B7D4C:
    .string "SCENARIO_SUB8\0"
    .align 2, 0

gUnknown_80B7D5C:
    .string "SCENARIO_SUB7\0"
    .align 2, 0

gUnknown_80B7D6C:
    .string "SCENARIO_SUB6\0"
    .align 2, 0

gUnknown_80B7D7C:
    .string "SCENARIO_SUB5\0"
    .align 2, 0

gUnknown_80B7D8C:
    .string "SCENARIO_SUB4\0"
    .align 2, 0

gUnknown_80B7D9C:
    .string "SCENARIO_SUB3\0"
    .align 2, 0

gUnknown_80B7DAC:
    .string "SCENARIO_SUB2\0"
    .align 2, 0

gUnknown_80B7DBC:
    .string "SCENARIO_SUB1\0"
    .align 2, 0

gUnknown_80B7DCC:
    .string "SCENARIO_MAIN\0"
    .align 2, 0

gUnknown_80B7DDC:
    .string "SCENARIO_SELECT\0"
    .align 2, 0

gUnknown_80B7DEC:
    .string "CONDITION\0"
    .align 2, 0

gUnknown_80B7DF8:
    .string "VERSION\0"
    .align 2, 0

@ ???
.string "pksdir0\0"

@ ???
.string "pksdir0\0"
    .fill 28, 1, 0

@ code_8002774.s
.string "pksdir0\0"
    .fill 8, 1, 0

	.global gUnknown_80B7E3C
gUnknown_80B7E3C: @ 80B7E3C
    .4byte 0, 1, 1, 1, 1, 0, 1, -1, 0, -1, -1, -1, -1, 0, -1, 1

@ ???
.string "pksdir0\0"

@ memory.s
.string "pksdir0\0"

gUnknown_80B7E8C:
    .string "../system/memory_locate.c\0"
    .align 2, 0

gUnknown_80B7EA8:
    .string "_LocateSetFront\0"
    .align 2, 0

	.global gUnknown_80B7EB8
gUnknown_80B7EB8: @ 80B7EB8
    .4byte gUnknown_80B7E8C, 581, gUnknown_80B7EA8

    .global gUnknown_80B7EC4
gUnknown_80B7EC4: @ 80B7EC4
    .string "Memory Locate sprit max over [%3d/%3d]\0"
    .align 2,0

LocateSetBackText:
    .string "_LocateSetBack\0"
    .align 2,0

	.global gUnknown_80B7EFC
gUnknown_80B7EFC: @ 80B7EFC
    .4byte gUnknown_80B7E8C, 673, LocateSetBackText

LocateSetText:
    .string "_LocateSet\0"
    .align 2,0

	.global gUnknown_80B7F14
gUnknown_80B7F14: @ 80B7F14
    .4byte gUnknown_80B7E8C, 812, LocateSetText

    .global gLocateSetErrorMessage
gLocateSetErrorMessage: @ 80B7F20
    .string "Memroy LocateSet [%p] buffer %8x size can't locate\n"
    .string "    atb %02x grp %3d \0"
    .align 2,0

MemoryLocate_LocalCreateText:
    .string "MemoryLocate_LocalCreate\0"
    .align 2,0

	.global gUnknown_80B7F88
gUnknown_80B7F88: @ 80B7F88
    .4byte gUnknown_80B7E8C, 1109, MemoryLocate_LocalCreateText

	.global gLocalCreateErrorMessage
gLocalCreateErrorMessage: @ 80B7F94
        .string "Memroy LocalCreate buffer %08x size can't locate\0" @ Spelling error is intentional
        .align 2,0

@ code_80035F0
.string "pksdir0\0"

@ other_random
.string "pksdir0\0"

@ util
.string "pksdir0\0"

@ bg_palette_buffer
.string "pksdir0\0"

@ input
.string "pksdir0\0"

@ code_8004AA0
.string "pksdir0\0"

@ sprite
.string "pksdir0\0"

@ code_800558C.c
.string "pksdir0\0"

	.global gUnknown_80B8008
gUnknown_80B8008: @ 80B8008
    .2byte 16, 12, 9, 7, 6, 5, 4, 3, 2, 2, 1, 1, 1, 0, 0, 0, 0

	.global gUnknown_80B802A
gUnknown_80B802A: @ 80B802A
    .2byte 0x0100
    .2byte 0x0100
    .2byte 0x0100
    .2byte 0x0100
    .2byte 0x0100
    .2byte 0x0100
    .2byte 0x0100
    .2byte 0x0100
    .2byte 0x0100
    .2byte 0x0100
    .2byte 0x0100
    .2byte 0x0100
    .2byte 0x0100
    .2byte 0x0100
    .2byte 0x0100
    .2byte 0x0100
    .2byte 0x0100
    .2byte 0x0100
    .2byte 0x0100
    .2byte 0x0100
    .2byte 0x0100
    .2byte 0x0100
    .2byte 0x0100
    .2byte 0x0100
    .2byte 0x0100
    .2byte 0x0100
    .2byte 0x0100
    .2byte 0x0100
    .2byte 0x0100
    .2byte 0x0100
    .2byte 0x0100
    .2byte 0x0100
    .2byte 0x0100
    .2byte 0x0100
    .2byte 0x0100
    .2byte 0x0100
    .2byte 0x0100
    .2byte 0x0100
    .2byte 0x0100
    .2byte 0x0100
    .2byte 0x0100
    .2byte 0x0100
    .2byte 0x0100
    .2byte 0x0100
    .2byte 0x0100
    .2byte 0x0100
    .2byte 0x0100
    .2byte 0x0100
    .2byte 0x846C
    .2byte 0x8967
    .2byte 0x8C64
    .2byte 0x8E62
    .2byte 0x9060
    .2byte 0x915F
    .2byte 0x935D
    .2byte 0x945C
    .2byte 0x955B
    .2byte 0x965A
    .2byte 0x965A
    .2byte 0x9759
    .2byte 0x9858
    .2byte 0x9858
    .2byte 0x9957
    .2byte 0x9957
    .2byte 0x9A56
    .2byte 0x9A56
    .2byte 0x9A56
    .2byte 0x9B55
    .2byte 0x9B55
    .2byte 0x9B55
    .2byte 0x9B55
    .2byte 0x9B55
    .2byte 0x9C55
    .2byte 0x9C54
    .2byte 0x9C54
    .2byte 0x9C54
    .2byte 0x9C54
    .2byte 0x9C54
    .2byte 0x9C54
    .2byte 0x9C54
    .2byte 0x9C54
    .2byte 0x9C54
    .2byte 0x9C54
    .2byte 0x9C54
    .2byte 0x9C54
    .2byte 0x9C54
    .2byte 0x9C54
    .2byte 0x9C54
    .2byte 0x9C54
    .2byte 0x9C54
    .2byte 0x9C54
    .2byte 0x9C54
    .2byte 0x9C54
    .2byte 0x9C54
    .2byte 0x9C54
    .2byte 0x9C54
    .2byte 0x9B55
    .2byte 0x9B55
    .2byte 0x9B55
    .2byte 0x9B55
    .2byte 0x9B55
    .2byte 0x9A56
    .2byte 0x9A56
    .2byte 0x9A56
    .2byte 0x9957
    .2byte 0x9957
    .2byte 0x9858
    .2byte 0x9858
    .2byte 0x9759
    .2byte 0x965A
    .2byte 0x965A
    .2byte 0x955B
    .2byte 0x945C
    .2byte 0x935D
    .2byte 0x915F
    .2byte 0x9060
    .2byte 0x8E62
    .2byte 0x8C64
    .2byte 0x8967
    .2byte 0x846C
    .2byte 0x0100
    .2byte 0x0100
    .2byte 0x0100
    .2byte 0x0100
    .2byte 0x0100
    .2byte 0x0100
    .2byte 0x0100
    .2byte 0x0100
    .2byte 0x0100
    .2byte 0x0100
    .2byte 0x0100
    .2byte 0x0100
    .2byte 0x0100
    .2byte 0x0100
    .2byte 0x0100
    .2byte 0x0100
    .2byte 0x0100
    .2byte 0x0100
    .2byte 0x0100
    .2byte 0x0100
    .2byte 0x0100
    .2byte 0x0100
    .2byte 0x0100
    .2byte 0x0100
    .2byte 0x0100
    .2byte 0x0100
    .2byte 0x0100
    .2byte 0x0100
    .2byte 0x0100
    .2byte 0x0100
    .2byte 0x0100
    .2byte 0x0100
    .2byte 0x0100
    .2byte 0x0100
    .2byte 0x0100
    .2byte 0x0100
    .2byte 0x0100
    .2byte 0x0100
    .2byte 0x0100
    .2byte 0x0100

	.global gUnknown_80B816A
gUnknown_80B816A: @ 80B816A
    .2byte 0x0100
    .2byte 0x0100
    .2byte 0x0100
    .2byte 0x0100
    .2byte 0x0100
    .2byte 0x0100
    .2byte 0x0100
    .2byte 0x0100
    .2byte 0x0100
    .2byte 0x0100
    .2byte 0x0100
    .2byte 0x0100
    .2byte 0x0100
    .2byte 0x0100
    .2byte 0x0100
    .2byte 0x0100
    .2byte 0x0100
    .2byte 0x0100
    .2byte 0x0100
    .2byte 0x0100
    .2byte 0x0100
    .2byte 0x0100
    .2byte 0x0100
    .2byte 0x0100
    .2byte 0x8071
    .2byte 0x866B
    .2byte 0x8A67
    .2byte 0x8D64
    .2byte 0x8F62
    .2byte 0x9160
    .2byte 0x935E
    .2byte 0x955C
    .2byte 0x975A
    .2byte 0x9958
    .2byte 0x9A57
    .2byte 0x9B56
    .2byte 0x9D54
    .2byte 0x9E53
    .2byte 0xA051
    .2byte 0xA051
    .2byte 0xA150
    .2byte 0xA24F
    .2byte 0xA44D
    .2byte 0xA54C
    .2byte 0xA54C
    .2byte 0xA64B
    .2byte 0xA74A
    .2byte 0xA849
    .2byte 0xA948
    .2byte 0xA948
    .2byte 0xAA47
    .2byte 0xAA47
    .2byte 0xAB46
    .2byte 0xAC45
    .2byte 0xAC45
    .2byte 0xAD44
    .2byte 0xAD44
    .2byte 0xAE43
    .2byte 0xAE43
    .2byte 0xAF42
    .2byte 0xAF42
    .2byte 0xB041
    .2byte 0xB041
    .2byte 0xB140
    .2byte 0xB140
    .2byte 0xB140
    .2byte 0xB23F
    .2byte 0xB23F
    .2byte 0xB23F
    .2byte 0xB23F
    .2byte 0xB33E
    .2byte 0xB33E
    .2byte 0xB33E
    .2byte 0xB33E
    .2byte 0xB33E
    .2byte 0xB33E
    .2byte 0xB43D
    .2byte 0xB43D
    .2byte 0xB43D
    .2byte 0xB43D
    .2byte 0xB43D
    .2byte 0xB43D
    .2byte 0xB43D
    .2byte 0xB43D
    .2byte 0xB43D
    .2byte 0xB43D
    .2byte 0xB43D
    .2byte 0xB43D
    .2byte 0xB43D
    .2byte 0xB43D
    .2byte 0xB43D
    .2byte 0xB43D
    .2byte 0xB33E
    .2byte 0xB33E
    .2byte 0xB33E
    .2byte 0xB33E
    .2byte 0xB33E
    .2byte 0xB33E
    .2byte 0xB23F
    .2byte 0xB23F
    .2byte 0xB23F
    .2byte 0xB23F
    .2byte 0xB140
    .2byte 0xB140
    .2byte 0xB140
    .2byte 0xB041
    .2byte 0xB041
    .2byte 0xAF42
    .2byte 0xAF42
    .2byte 0xAE43
    .2byte 0xAE43
    .2byte 0xAD44
    .2byte 0xAD44
    .2byte 0xAC45
    .2byte 0xAC45
    .2byte 0xAB46
    .2byte 0xAA47
    .2byte 0xAA47
    .2byte 0xA948
    .2byte 0xA948
    .2byte 0xA849
    .2byte 0xA74A
    .2byte 0xA64B
    .2byte 0xA54C
    .2byte 0xA54C
    .2byte 0xA44D
    .2byte 0xA24F
    .2byte 0xA150
    .2byte 0xA051
    .2byte 0xA051
    .2byte 0x9E53
    .2byte 0x9D54
    .2byte 0x9B56
    .2byte 0x9A57
    .2byte 0x9958
    .2byte 0x975A
    .2byte 0x955C
    .2byte 0x935E
    .2byte 0x9160
    .2byte 0x8F62
    .2byte 0x8D64
    .2byte 0x8A67
    .2byte 0x866B
    .2byte 0x8071
    .2byte 0x0100
    .2byte 0x0100
    .2byte 0x0100
    .2byte 0x0100
    .2byte 0x0100
    .2byte 0x0100
    .2byte 0x0100
    .2byte 0x0100
    .2byte 0x0100
    .2byte 0x0100
    .2byte 0x0100
    .2byte 0x0100
    .2byte 0x0100
    .2byte 0x0100
    .2byte 0x0100
    .2byte 0x0100

	.global gUnknown_80B82AA
gUnknown_80B82AA: @ 80B82AA
    .2byte 0x0100
    .2byte 0x0100
    .2byte 0x0100
    .2byte 0x9392
    .2byte 0x0100
    .2byte 0x0100
    .2byte 0x0100
    .2byte 0x0100
    .2byte 0x0100
    .2byte 0x0100
    .2byte 0x0100
    .2byte 0x0100
    .2byte 0x0100
    .2byte 0x0100
    .2byte 0x0100
    .2byte 0x0100
    .2byte 0x0100
    .2byte 0x0100
    .2byte 0x0100
    .2byte 0x0100
    .2byte 0x0100
    .2byte 0x0100
    .2byte 0x0100
    .2byte 0x0100
    .2byte 0x0100
    .2byte 0x0100
    .2byte 0x0100
    .2byte 0x0100
    .2byte 0x0100
    .2byte 0x0100
    .2byte 0x0100
    .2byte 0x0100
    .2byte 0x0100
    .2byte 0x0100
    .2byte 0x0100
    .2byte 0x0100
    .2byte 0x0100
    .2byte 0x0100
    .2byte 0x0100
    .2byte 0x0100
    .2byte 0x0100
    .2byte 0x0100
    .2byte 0x0100
    .2byte 0x0100
    .2byte 0x0100
    .2byte 0x0100
    .2byte 0x0100
    .2byte 0x0100
    .2byte 0x0100
    .2byte 0x0100
    .2byte 0x0100
    .2byte 0x0100
    .2byte 0x0100
    .2byte 0x0100
    .2byte 0x0100
    .2byte 0x0100
    .2byte 0x0100
    .2byte 0x0100
    .2byte 0x0100
    .2byte 0x0100
    .2byte 0x0100
    .2byte 0x0100
    .2byte 0x0100
    .2byte 0x0100
    .2byte 0x0100
    .2byte 0x0100
    .2byte 0x0100
    .2byte 0x0100
    .2byte 0x0100
    .2byte 0x0100
    .2byte 0x0100
    .2byte 0x0100
    .2byte 0x0100
    .2byte 0x0100
    .2byte 0x0100
    .2byte 0x0100
    .2byte 0x0100
    .2byte 0x0100
    .2byte 0x0100
    .2byte 0x0100
    .2byte 0x0100
    .2byte 0x0100
    .2byte 0x0100
    .2byte 0x0100
    .2byte 0x0100
    .2byte 0x0100
    .2byte 0x0100
    .2byte 0x0100
    .2byte 0x0100
    .2byte 0x0100
    .2byte 0x0100
    .2byte 0x0100
    .2byte 0x0100
    .2byte 0x0100
    .2byte 0x0100
    .2byte 0x0100
    .2byte 0x0100
    .2byte 0x0100
    .2byte 0x0100
    .2byte 0x0100
    .2byte 0x0100
    .2byte 0x0100
    .2byte 0x0100
    .2byte 0x0100
    .2byte 0x0100
    .2byte 0x0100
    .2byte 0x0100
    .2byte 0x0100
    .2byte 0x0100
    .2byte 0x0100
    .2byte 0x0100
    .2byte 0x0100
    .2byte 0x0100
    .2byte 0x0100
    .2byte 0x0100
    .2byte 0x0100
    .2byte 0x0100
    .2byte 0x0100
    .2byte 0x0100
    .2byte 0x0100
    .2byte 0x0100
    .2byte 0x0100
    .2byte 0x0100
    .2byte 0x0100
    .2byte 0x0100
    .2byte 0x0100
    .2byte 0x0100
    .2byte 0x0100
    .2byte 0x0100
    .2byte 0x0100
    .2byte 0x0100
    .2byte 0x0100
    .2byte 0x0100
    .2byte 0x0100
    .2byte 0x0100
    .2byte 0x0100
    .2byte 0x0100
    .2byte 0x0100
    .2byte 0x0100
    .2byte 0x0100
    .2byte 0x0100
    .2byte 0x0100
    .2byte 0x0100
    .2byte 0x0100
    .2byte 0x0100
    .2byte 0x0100
    .2byte 0x0100
    .2byte 0x0100
    .2byte 0x0100
    .2byte 0x0100
    .2byte 0x0100
    .2byte 0x0100
    .2byte 0x0100
    .2byte 0x0100
    .2byte 0x0100
    .2byte 0x0100
    .2byte 0x0100
    .2byte 0x0100
    .2byte 0x0100
    .2byte 0x0100

	.global gUnknown_80B83EA
gUnknown_80B83EA: @ 80B83EA
    .2byte 0x0000
    .2byte 0x0000
    .2byte 0x0000
    .2byte 0x0000
    .2byte 0x0000
    .2byte 0x0000
    .2byte 0x0000
    .2byte 0x0000
    .2byte 0x0000
    .2byte 0x0000
    .2byte 0x0000
    .2byte 0x0000
    .2byte 0x0000
    .2byte 0x0000
    .2byte 0x0000
    .2byte 0x0000
    .2byte 0x0000
    .2byte 0x0000
    .2byte 0x0000
    .2byte 0x0000
    .2byte 0x0000
    .2byte 0x0000
    .2byte 0x0000
    .2byte 0x0000
    .2byte 0x0000
    .2byte 0x0000
    .2byte 0x0000
    .2byte 0x0000
    .2byte 0x0000
    .2byte 0x0000
    .2byte 0x0000
    .2byte 0x0000
    .2byte 0x0000
    .2byte 0x0000
    .2byte 0x0000
    .2byte 0x0000
    .2byte 0x0000
    .2byte 0x0000
    .2byte 0x0000
    .2byte 0x0000
    .2byte 0x0000
    .2byte 0x0000
    .2byte 0x0000
    .2byte 0x0000
    .2byte 0x0000
    .2byte 0x0000
    .2byte 0x0000
    .2byte 0x0000
    .2byte 0x0000
    .2byte 0x0000
    .2byte 0x0000
    .2byte 0x0000
    .2byte 0x0000
    .2byte 0x0000
    .2byte 0x0000
    .2byte 0x0000
    .2byte 0x0000
    .2byte 0x0000
    .2byte 0x0000
    .2byte 0x0000
    .2byte 0x0000
    .2byte 0x0000
    .2byte 0x0000
    .2byte 0x0000
    .2byte 0x0000
    .2byte 0x0000
    .2byte 0x0000
    .2byte 0x0000
    .2byte 0x0000
    .2byte 0x0000
    .2byte 0x0000
    .2byte 0x0000
    .2byte 0x0000
    .2byte 0x0000
    .2byte 0x0000
    .2byte 0x0000
    .2byte 0x0000
    .2byte 0x0000
    .2byte 0x0000
    .2byte 0x0000
    .2byte 0x0000
    .2byte 0x0000
    .2byte 0x0000
    .2byte 0x0000
    .2byte 0x0000
    .2byte 0x0000
    .2byte 0x0000
    .2byte 0x0000
    .2byte 0x0000
    .2byte 0x0000
    .2byte 0x0000
    .2byte 0x0000
    .2byte 0x0000
    .2byte 0x0000
    .2byte 0x0000
    .2byte 0x0000
    .2byte 0x0000
    .2byte 0x0000
    .2byte 0x0000
    .2byte 0x0000
    .2byte 0x0000
    .2byte 0x0000
    .2byte 0x0000
    .2byte 0x0000
    .2byte 0x0000
    .2byte 0x0000
    .2byte 0x0000
    .2byte 0x0000
    .2byte 0x0000
    .2byte 0x0000
    .2byte 0x0000
    .2byte 0x0000
    .2byte 0x0000
    .2byte 0x0000
    .2byte 0x0000
    .2byte 0x0000
    .2byte 0x0000
    .2byte 0x0000
    .2byte 0x0000
    .2byte 0x0000
    .2byte 0x0000
    .2byte 0x0000
    .2byte 0x0000
    .2byte 0x0000
    .2byte 0x0000
    .2byte 0x0000
    .2byte 0x0000
    .2byte 0x0000
    .2byte 0x0000
    .2byte 0x0000
    .2byte 0x0000
    .2byte 0x0000
    .2byte 0x0000
    .2byte 0x0000
    .2byte 0x0000
    .2byte 0x0000
    .2byte 0x0000
    .2byte 0x0000
    .2byte 0x0000
    .2byte 0x0000
    .2byte 0x0000
    .2byte 0x0000
    .2byte 0x0000
    .2byte 0x0000
    .2byte 0x0000
    .2byte 0x0000
    .2byte 0x0000
    .2byte 0x0000
    .2byte 0x0000
    .2byte 0x0000
    .2byte 0x0000
    .2byte 0x0000
    .2byte 0x0000
    .2byte 0x0000
    .2byte 0x0000
    .2byte 0x0000
    .2byte 0x0000
    .2byte 0x0000
    .2byte 0x0000
    .2byte 0x0000

    .align 2, 0

@ ???
.string "pksdir0\0"

@ text2.c
.string "pksdir0\0"

	.global gUnknown_80B853C
gUnknown_80B853C: @ 80B853C
    .4byte 0x66666666
    .4byte 0x00000000
    .4byte 0x11111111
    .4byte 0x22222222
    .4byte 0x33333333
    .4byte 0x44444444
    .4byte 0x55555555
    .4byte 0x66666666
    .4byte 0x77777777
    .4byte 0x88888888
    .4byte 0x99999999
    .4byte 0xAAAAAAAA
    .4byte 0xBBBBBBBB
    .4byte 0xCCCCCCCC
    .4byte 0xDDDDDDDD
    .4byte 0xEEEEEEEE

	.global gUnknown_80B857C
gUnknown_80B857C: @ 80B857C
    @ Type: UnkTextStruct2[4]
    .4byte 0, 3, 0, 0, 0, 0
    .4byte 0, 3, 0, 0, 0, 0
    .4byte 0, 3, 0, 0, 0, 0
    .4byte 0, 3, 0, 0, 0, 0

	.global gUnknown_80B85DC
gUnknown_80B85DC: @ 80B85DC
    @ Type: unkShiftData[8]
    .4byte 0xFFFFFFFF, 0x00000000, 0x00, 0x20
    .4byte 0x0FFFFFFF, 0xF0000000, 0x04, 0x1C
    .4byte 0x00FFFFFF, 0xFF000000, 0x08, 0x18
    .4byte 0x000FFFFF, 0xFFF00000, 0x0C, 0x14
    .4byte 0x0000FFFF, 0xFFFF0000, 0x10, 0x10
    .4byte 0x00000FFF, 0xFFFFF000, 0x14, 0x0C
    .4byte 0x000000FF, 0xFFFFFF00, 0x18, 0x08
    .4byte 0x0000000F, 0xFFFFFFF0, 0x1C, 0x04

    .global gUnknown_80B865C
gUnknown_80B865C:
    .byte 0xff, 0xff, 0xff, 0xff, 0xff, 0x00
    .byte 0xff, 0xff, 0xff, 0xff, 0xff, 0x00
    .byte 0xff, 0xff, 0xff, 0xff, 0xff, 0x00
    .byte 0xff, 0xff, 0xff, 0xff, 0xff, 0x00
    .byte 0xff, 0xff, 0xff, 0xff, 0xff, 0x00
    .byte 0xff, 0xff, 0xff, 0xff, 0xff, 0x00
    .byte 0xff, 0xff, 0xff, 0xff, 0xff, 0x00
    .byte 0xff, 0xff, 0xff, 0xff, 0xff, 0x00
    .byte 0xff, 0xff, 0xff, 0xff, 0xff, 0x00
    .byte 0xff, 0xff, 0xff, 0xff, 0xff, 0x00
    .byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
    .byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00

	.global gUnknown_80B86A4
gUnknown_80B86A4: @ 80B86A4
    @ Fallback character with bitmap?
    .4byte gUnknown_80B865C
    .4byte 0x781A1, 10, 8

	.global gUnknown_80B86B4
gUnknown_80B86B4: @ 80B86B4
    .incbin "graphics/warning.4bpp"

	.global gKanjiA_file_string
gKanjiA_file_string: @ 80B87B4
        .string "kanji_a\0"
        .align 2,0

	.global gKanjiB_file_string
gKanjiB_file_string: @ 80B87BC
        .string "kanji_b\0"
        .align 2,0

	.global gUnknown_80B87C4
gUnknown_80B87C4: @ 80B87C4
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00

	.global gUnknown_80B87E4
gUnknown_80B87E4: @ 80B87E4
        .byte 0x88, 0x88, 0x88, 0x88
        .byte 0x88, 0x88, 0x88, 0x88
        .byte 0x88, 0x88, 0x88, 0x88
        .byte 0x88, 0x88, 0x88, 0x88
        .byte 0x88, 0x88, 0x88, 0x88
        .byte 0x88, 0x88, 0x88, 0x88
        .byte 0x88, 0x88, 0x88, 0x88
        .byte 0x88, 0x88, 0x88, 0x88

	.global gUnknown_80B8804
gUnknown_80B8804: @ 80B8804
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x01, 0x00, 0x00, 0x00
        .byte 0x02, 0x00, 0x00, 0x00
        .byte 0x03, 0x00, 0x00, 0x00

	.global gUnknown_80B8814
gUnknown_80B8814: @ 80B8814
        .byte 0x01, 0x00, 0x00, 0x00
        .byte 0x02, 0x00, 0x00, 0x00
        .byte 0x03, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00

	.global gUnknown_80B8824
gUnknown_80B8824: @ 80B8824
        @ Type: unkStruct_80B8824
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x0f, 0x00, 0x00, 0x00
        .byte 0xff, 0x00, 0x00, 0x00
        .byte 0xff, 0x0f, 0x00, 0x00
        .byte 0xff, 0xff, 0x00, 0x00
        .byte 0xff, 0xff, 0x0f, 0x00
        .byte 0xff, 0xff, 0xff, 0x00
        .byte 0xff, 0xff, 0xff, 0x0f
        .byte 0xff, 0xff, 0xff, 0xff

	.global gUnknown_80B8848
gUnknown_80B8848: @ 80B8848
        @ Type: unkStruct_80B8848
        .byte 0x0F, 0x00, 0x00, 0x00
        .byte 0xF0, 0x00, 0x00, 0x00
        .byte 0x00, 0x0F, 0x00, 0x00
        .byte 0x00, 0xF0, 0x00, 0x00
        .byte 0x00, 0x00, 0x0F, 0x00
        .byte 0x00, 0x00, 0xF0, 0x00
        .byte 0x00, 0x00, 0x00, 0x0F
        .byte 0x00, 0x00, 0x00, 0xF0

	.global gUnknown_80B8868
gUnknown_80B8868: @ 80B8868
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x0f, 0x00, 0x00, 0x00
        .byte 0xff, 0x00, 0x00, 0x00
        .byte 0xff, 0x0f, 0x00, 0x00
        .byte 0xff, 0xff, 0x00, 0x00
        .byte 0xff, 0xff, 0x0f, 0x00
        .byte 0xff, 0xff, 0xff, 0x00
        .byte 0xff, 0xff, 0xff, 0x0f
        .byte 0xff, 0xff, 0xff, 0xff
        .byte 0xf0, 0xff, 0xff, 0xff
        .byte 0x00, 0xff, 0xff, 0xff
        .byte 0x00, 0xf0, 0xff, 0xff
        .byte 0x00, 0x00, 0xff, 0xff
        .byte 0x00, 0x00, 0xf0, 0xff
        .byte 0x00, 0x00, 0x00, 0xff
        .byte 0x00, 0x00, 0x00, 0xf0

@ text.s
.string "pksdir0\0"
        .align 2,0

	.global gUnknown_80B88B0
gUnknown_80B88B0: @ 80B88B0
        .string "font\0"
        .align 2,0

	.global gUnknown_80B88B8
gUnknown_80B88B8: @ 80B88B8
        .string "fontsp\0"
        .align 2,0

	.global gUnknown_80B88C0
gUnknown_80B88C0: @ 80B88C0
        .string "fontsppa\0"
        .align 2,0

	.global gUnknown_80B88CC
gUnknown_80B88CC: @ 80B88CC
        .string "fontpal\0"
        .align 2,0

@ ???
.string "pksdir0\0"

@ code_8009804.s
.string "pksdir0\0"

	.global gFastMod3Lookup
gFastMod3Lookup: @ 80B88E4
x = 0
.rept 0x100
    .byte x % 3
x = x + 1
.endr

    .global gFastDiv3Lookup
gFastDiv3Lookup: @ 80B89E4
x = 0
.rept 0x100
    .byte x / 3
x = x + 1
.endr

	.global gUnknown_80B8AE4
gUnknown_80B8AE4: @ 80B8AE4
    .2byte 0, 0, 0, 1, 1, 1, 2, 2
    .2byte 3, 3, 3, 4, 4, 5, 5, 5
    .2byte 6, 6, 7, 7, 7, 8, 8, 9
    .2byte 9, 9, 10, 10, 10, 11, 11, 12
    .2byte 12, 12, 13, 13, 14, 14, 14, 15
    .2byte 15, 16, 16, 16, 17, 17, 18, 18
    .2byte 18, 19, 19, 20, 20, 20, 21, 21
    .2byte 21, 22, 22, 23, 23, 23, 24, 24
    .2byte 25, 25, 25, 26, 26, 27, 27, 27
    .2byte 28, 28, 28, 29, 29, 30, 30, 30
    .2byte 31, 31, 32, 32, 32, 33, 33, 34
    .2byte 34, 34, 35, 35, 36, 36, 36, 37
    .2byte 37, 37, 38, 38, 39, 39, 39, 40
    .2byte 40, 41, 41, 41, 42, 42, 42, 43
    .2byte 43, 44, 44, 44, 45, 45, 46, 46
    .2byte 46, 47, 47, 48, 48, 48, 49, 49
    .2byte 49, 50, 50, 51, 51, 51, 52, 52
    .2byte 53, 53, 53, 54, 54, 54, 55, 55
    .2byte 56, 56, 56, 57, 57, 58, 58, 58
    .2byte 59, 59, 59, 60, 60, 61, 61, 61
    .2byte 62, 62, 62, 63, 63, 64, 64, 64
    .2byte 65, 65, 66, 66, 66, 67, 67, 67
    .2byte 68, 68, 69, 69, 69, 70, 70, 70
    .2byte 71, 71, 72, 72, 72, 73, 73, 73
    .2byte 74, 74, 75, 75, 75, 76, 76, 76
    .2byte 77, 77, 78, 78, 78, 79, 79, 79
    .2byte 80, 80, 81, 81, 81, 82, 82, 82
    .2byte 83, 83, 84, 84, 84, 85, 85, 85
    .2byte 86, 86, 86, 87, 87, 88, 88, 88
    .2byte 89, 89, 89, 90, 90, 91, 91, 91
    .2byte 92, 92, 92, 93, 93, 93, 94, 94
    .2byte 95, 95, 95, 96, 96, 96, 97, 97
    .2byte 97, 98, 98, 99, 99, 99, 100, 100
    .2byte 100, 101, 101, 101, 102, 102, 103, 103
    .2byte 103, 104, 104, 104, 105, 105, 105, 106
    .2byte 106, 106, 107, 107, 108, 108, 108, 109
    .2byte 109, 109, 110, 110, 110, 111, 111, 111
    .2byte 112, 112, 112, 113, 113, 114, 114, 114
    .2byte 115, 115, 115, 116, 116, 116, 117, 117
    .2byte 117, 118, 118, 118, 119, 119, 119, 120
    .2byte 120, 121, 121, 121, 122, 122, 122, 123
    .2byte 123, 123, 124, 124, 124, 125, 125, 125
    .2byte 126, 126, 126, 127, 127, 127, 128, 128
    .2byte 128, 129, 129, 129, 130, 130, 130, 131
    .2byte 131, 131, 132, 132, 132, 133, 133, 133
    .2byte 134, 134, 134, 135, 135, 135, 136, 136
    .2byte 136, 137, 137, 137, 138, 138, 138, 139
    .2byte 139, 139, 140, 140, 140, 141, 141, 141
    .2byte 142, 142, 142, 143, 143, 143, 144, 144
    .2byte 144, 145, 145, 145, 146, 146, 146, 147
    .2byte 147, 147, 148, 148, 148, 149, 149, 149
    .2byte 149, 150, 150, 150, 151, 151, 151, 152
    .2byte 152, 152, 153, 153, 153, 154, 154, 154
    .2byte 155, 155, 155, 155, 156, 156, 156, 157
    .2byte 157, 157, 158, 158, 158, 159, 159, 159
    .2byte 159, 160, 160, 160, 161, 161, 161, 162
    .2byte 162, 162, 163, 163, 163, 163, 164, 164
    .2byte 164, 165, 165, 165, 166, 166, 166, 166
    .2byte 167, 167, 167, 168, 168, 168, 168, 169
    .2byte 169, 169, 170, 170, 170, 171, 171, 171
    .2byte 171, 172, 172, 172, 173, 173, 173, 173
    .2byte 174, 174, 174, 175, 175, 175, 175, 176
    .2byte 176, 176, 177, 177, 177, 177, 178, 178
    .2byte 178, 179, 179, 179, 179, 180, 180, 180
    .2byte 181, 181, 181, 181, 182, 182, 182, 182
    .2byte 183, 183, 183, 184, 184, 184, 184, 185
    .2byte 185, 185, 185, 186, 186, 186, 187, 187
    .2byte 187, 187, 188, 188, 188, 188, 189, 189
    .2byte 189, 189, 190, 190, 190, 190, 191, 191
    .2byte 191, 192, 192, 192, 192, 193, 193, 193
    .2byte 193, 194, 194, 194, 194, 195, 195, 195
    .2byte 195, 196, 196, 196, 196, 197, 197, 197
    .2byte 197, 198, 198, 198, 198, 199, 199, 199
    .2byte 199, 200, 200, 200, 200, 201, 201, 201
    .2byte 201, 202, 202, 202, 202, 203, 203, 203
    .2byte 203, 203, 204, 204, 204, 204, 205, 205
    .2byte 205, 205, 206, 206, 206, 206, 207, 207
    .2byte 207, 207, 207, 208, 208, 208, 208, 209
    .2byte 209, 209, 209, 209, 210, 210, 210, 210
    .2byte 211, 211, 211, 211, 211, 212, 212, 212
    .2byte 212, 213, 213, 213, 213, 213, 214, 214
    .2byte 214, 214, 215, 215, 215, 215, 215, 216
    .2byte 216, 216, 216, 216, 217, 217, 217, 217
    .2byte 217, 218, 218, 218, 218, 218, 219, 219
    .2byte 219, 219, 219, 220, 220, 220, 220, 220
    .2byte 221, 221, 221, 221, 221, 222, 222, 222
    .2byte 222, 222, 223, 223, 223, 223, 223, 224
    .2byte 224, 224, 224, 224, 225, 225, 225, 225
    .2byte 225, 225, 226, 226, 226, 226, 226, 227
    .2byte 227, 227, 227, 227, 227, 228, 228, 228
    .2byte 228, 228, 229, 229, 229, 229, 229, 229
    .2byte 230, 230, 230, 230, 230, 230, 231, 231
    .2byte 231, 231, 231, 231, 232, 232, 232, 232
    .2byte 232, 232, 233, 233, 233, 233, 233, 233
    .2byte 234, 234, 234, 234, 234, 234, 234, 235
    .2byte 235, 235, 235, 235, 235, 236, 236, 236
    .2byte 236, 236, 236, 236, 237, 237, 237, 237
    .2byte 237, 237, 237, 238, 238, 238, 238, 238
    .2byte 238, 238, 239, 239, 239, 239, 239, 239
    .2byte 239, 240, 240, 240, 240, 240, 240, 240
    .2byte 241, 241, 241, 241, 241, 241, 241, 241
    .2byte 242, 242, 242, 242, 242, 242, 242, 242
    .2byte 243, 243, 243, 243, 243, 243, 243, 243
    .2byte 244, 244, 244, 244, 244, 244, 244, 244
    .2byte 244, 245, 245, 245, 245, 245, 245, 245
    .2byte 245, 245, 246, 246, 246, 246, 246, 246
    .2byte 246, 246, 246, 247, 247, 247, 247, 247
    .2byte 247, 247, 247, 247, 247, 248, 248, 248
    .2byte 248, 248, 248, 248, 248, 248, 248, 248
    .2byte 249, 249, 249, 249, 249, 249, 249, 249
    .2byte 249, 249, 249, 250, 250, 250, 250, 250
    .2byte 250, 250, 250, 250, 250, 250, 250, 251
    .2byte 251, 251, 251, 251, 251, 251, 251, 251
    .2byte 251, 251, 251, 251, 251, 252, 252, 252
    .2byte 252, 252, 252, 252, 252, 252, 252, 252
    .2byte 252, 252, 252, 252, 252, 253, 253, 253
    .2byte 253, 253, 253, 253, 253, 253, 253, 253
    .2byte 253, 253, 253, 253, 253, 253, 253, 254
    .2byte 254, 254, 254, 254, 254, 254, 254, 254
    .2byte 254, 254, 254, 254, 254, 254, 254, 254
    .2byte 254, 254, 254, 254, 254, 254, 254, 255
    .2byte 255, 255, 255, 255, 255, 255, 255, 255
    .2byte 255, 255, 255, 255, 255, 255, 255, 255
    .2byte 255, 255, 255, 255, 255, 255, 255, 255
    .2byte 255, 255, 255, 255, 255, 255, 255, 255
    .2byte 255, 255, 255, 255, 255, 255, 255, 255
    .2byte 255, 255, 255, 255, 255, 255, 255, 255
    .2byte 255, 255, 255, 255, 255, 255, 255, 255

	.global gUnknown_80B92E4
gUnknown_80B92E4: @ 80B92E4
    .4byte 0, 0, 0, 0, 0, 0, 0, 1
    .4byte 1, 1, 1, 1, 1, 2, 2, 2
    .4byte 2, 2, 2, 3, 3, 3, 3, 3
    .4byte 3, 3, 4, 4, 4, 4, 4, 4
    .4byte 5, 5, 5, 5, 5, 5, 6, 6
    .4byte 6, 6, 6, 6, 6, 7, 7, 7
    .4byte 7, 7, 7, 8, 8, 8, 8, 8
    .4byte 8, 8, 9, 9, 9, 9, 9, 9
    .4byte 9, 10, 10, 10, 10, 10, 10, 11
    .4byte 11, 11, 11, 11, 11, 11, 12, 12
    .4byte 12, 12, 12, 12, 12, 13, 13, 13
    .4byte 13, 13, 13, 13, 14, 14, 14, 14
    .4byte 14, 14, 14, 15, 15, 15, 15, 15
    .4byte 15, 15, 15, 16, 16, 16, 16, 16
    .4byte 16, 16, 17, 17, 17, 17, 17, 17
    .4byte 17, 17, 18, 18, 18, 18, 18, 18
    .4byte 18, 19, 19, 19, 19, 19, 19, 19
    .4byte 19, 20, 20, 20, 20, 20, 20, 20
    .4byte 20, 20, 21, 21, 21, 21, 21, 21
    .4byte 21, 21, 22, 22, 22, 22, 22, 22
    .4byte 22, 22, 22, 23, 23, 23, 23, 23
    .4byte 23, 23, 23, 23, 24, 24, 24, 24
    .4byte 24, 24, 24, 24, 24, 25, 25, 25
    .4byte 25, 25, 25, 25, 25, 25, 26, 26
    .4byte 26, 26, 26, 26, 26, 26, 26, 26
    .4byte 27, 27, 27, 27, 27, 27, 27, 27
    .4byte 27, 27, 27, 28, 28, 28, 28, 28
    .4byte 28, 28, 28, 28, 28, 29, 29, 29
    .4byte 29, 29, 29, 29, 29, 29, 29, 29
    .4byte 29, 30, 30, 30, 30, 30, 30, 30
    .4byte 30, 30, 30, 30, 31, 31, 31, 31
    .4byte 31, 31, 31, 31, 31, 31, 31, 31

	.global gUnknown_80B96E4
gUnknown_80B96E4: @ 80B96E4
@ It's an array..
    .4byte 0
    .4byte 0
    .4byte 45426
    .4byte 71998
    .4byte 90852
    .4byte 105476
    .4byte 117424
    .4byte 127527
    .4byte 136278
    .4byte 143997
    .4byte 150902
    .4byte 157148
    .4byte 162850
    .4byte 168096
    .4byte 172953
    .4byte 177474
    .4byte 181704
    .4byte 185677
    .4byte 189423
    .4byte 192966
    .4byte 196328
    .4byte 199525
    .4byte 202574
    .4byte 205487
    .4byte 208276
    .4byte 210952
    .4byte 213522
    .4byte 215995
    .4byte 218379
    .4byte 220679
    .4byte 222900
    .4byte 225049
    .4byte 227130
    .4byte 229147
    .4byte 231103
    .4byte 233003
    .4byte 234849
    .4byte 236645
    .4byte 238392
    .4byte 240095
    .4byte 241754
    .4byte 243372
    .4byte 244951
    .4byte 246494
    .4byte 248000
    .4byte 249473
    .4byte 250913
    .4byte 252323
    .4byte 253703
    .4byte 255054
    .4byte 256378
    .4byte 257676
    .4byte 258948
    .4byte 260197
    .4byte 261422
    .4byte 262624
    .4byte 263805
    .4byte 264965
    .4byte 266105
    .4byte 267225
    .4byte 268326
    .4byte 269410
    .4byte 270475
    .4byte 271524
    .4byte 272556
    .4byte 273572
    .4byte 274573
    .4byte 275558
    .4byte 276529
    .4byte 277486
    .4byte 278429
    .4byte 279358
    .4byte 280275
    .4byte 281179
    .4byte 282071
    .4byte 282950
    .4byte 283818
    .4byte 284675
    .4byte 285521
    .4byte 286356
    .4byte 287180
    .4byte 287994
    .4byte 288798
    .4byte 289593
    .4byte 290378
    .4byte 291153
    .4byte 291920
    .4byte 292677
    .4byte 293426
    .4byte 294167
    .4byte 294899
    .4byte 295623
    .4byte 296339
    .4byte 297048
    .4byte 297749
    .4byte 298442
    .4byte 299129
    .4byte 299808
    .4byte 300480
    .4byte 301145
    .4byte 301804
    .4byte 302456
    .4byte 303102
    .4byte 303741
    .4byte 304374
    .4byte 305001
    .4byte 305623
    .4byte 306238
    .4byte 306848
    .4byte 307452
    .4byte 308050
    .4byte 308643
    .4byte 309231
    .4byte 309814
    .4byte 310391
    .4byte 310963
    .4byte 311531
    .4byte 312093
    .4byte 312651
    .4byte 313204
    .4byte 313753
    .4byte 314296
    .4byte 314836
    .4byte 315371
    .4byte 315901
    .4byte 316428
    .4byte 316950
    .4byte 317468
    .4byte 317982
    .4byte 318492
    .4byte 318998
    .4byte 319500
    .4byte 319999
    .4byte 320493
    .4byte 320984
    .4byte 321472
    .4byte 321955
    .4byte 322435
    .4byte 322912
    .4byte 323385
    .4byte 323855
    .4byte 324321
    .4byte 324785
    .4byte 325244
    .4byte 325701
    .4byte 326155
    .4byte 326605
    .4byte 327052
    .4byte 327497
    .4byte 327938
    .4byte 328376
    .4byte 328812
    .4byte 329245
    .4byte 329674
    .4byte 330101
    .4byte 330525
    .4byte 330947
    .4byte 331366
    .4byte 331782
    .4byte 332195
    .4byte 332606
    .4byte 333014
    .4byte 333420
    .4byte 333824
    .4byte 334224
    .4byte 334623
    .4byte 335019
    .4byte 335412
    .4byte 335804
    .4byte 336193
    .4byte 336579
    .4byte 336964
    .4byte 337346
    .4byte 337726
    .4byte 338103
    .4byte 338479
    .4byte 338852
    .4byte 339224
    .4byte 339593
    .4byte 339960
    .4byte 340325
    .4byte 340688
    .4byte 341049
    .4byte 341408
    .4byte 341766
    .4byte 342121
    .4byte 342474
    .4byte 342825
    .4byte 343175
    .4byte 343523
    .4byte 343868
    .4byte 344212
    .4byte 344555
    .4byte 344895
    .4byte 345234
    .4byte 345571
    .4byte 345906
    .4byte 346240
    .4byte 346571
    .4byte 346902
    .4byte 347230
    .4byte 347557
    .4byte 347882
    .4byte 348206
    .4byte 348528
    .4byte 348848
    .4byte 349167
    .4byte 349485
    .4byte 349800
    .4byte 350115
    .4byte 350428
    .4byte 350739
    .4byte 351049
    .4byte 351357
    .4byte 351664
    .4byte 351970
    .4byte 352274
    .4byte 352576
    .4byte 352878
    .4byte 353178
    .4byte 353476
    .4byte 353773
    .4byte 354069
    .4byte 354364
    .4byte 354657
    .4byte 354949
    .4byte 355240
    .4byte 355529
    .4byte 355817
    .4byte 356104
    .4byte 356389
    .4byte 356674
    .4byte 356957
    .4byte 357239
    .4byte 357519
    .4byte 357799
    .4byte 358077
    .4byte 358354
    .4byte 358630
    .4byte 358905
    .4byte 359179
    .4byte 359451
    .4byte 359723
    .4byte 359993
    .4byte 360262
    .4byte 360530
    .4byte 360797
    .4byte 361063
    .4byte 361328
    .4byte 361591
    .4byte 361854
    .4byte 362116
    .4byte 362376
    .4byte 362636
    .4byte 362894
    .4byte 363152
    .4byte 363408
    .4byte 363664
    .4byte 363918
    .4byte 364172
    .4byte 364424
    .4byte 364676
    .4byte 364927
    .4byte 365176
    .4byte 365425
    .4byte 365673
    .4byte 365920
    .4byte 366165
    .4byte 366410
    .4byte 366655
    .4byte 366898
    .4byte 367140
    .4byte 367381
    .4byte 367622
    .4byte 367861
    .4byte 368100
    .4byte 368338
    .4byte 368575
    .4byte 368811
    .4byte 369047
    .4byte 369281
    .4byte 369515
    .4byte 369748
    .4byte 369980
    .4byte 370211
    .4byte 370441
    .4byte 370671
    .4byte 370899
    .4byte 371127
    .4byte 371354
    .4byte 371581
    .4byte 371806
    .4byte 372031
    .4byte 372255
    .4byte 372479
    .4byte 372701
    .4byte 372923
    .4byte 373144
    .4byte 373364
    .4byte 373584
