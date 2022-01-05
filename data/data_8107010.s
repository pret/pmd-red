        .section .rodata

        .string "pksdir0\0"
        .string "pksdir0\0"
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
        .string "{COLOR_2 YELLOW_2}%s{END_COLOR_TEXT_2}"
        .align 2,0

	.global gUnknown_8107608
gUnknown_8107608: @ 8107608
        .string "{COLOR_2 CYAN_2}%s{END_COLOR_TEXT_2}"
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
        .string "{COLOR_2}%c%s{END_COLOR_TEXT_2}\0"

	.global gUnknown_8107645
gUnknown_8107645: @ 8107645
        .byte 0x00, 0x01, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00

	.global gUnknown_8107654
gUnknown_8107654: @ 8107654
        .byte 0x9d, 0x01, 0x00, 0x00, 0x0d, 0x00, 0x00, 0x00, 0x0c, 0x01, 0x00, 0x00, 0x0d, 0x00, 0x00, 0x00, 0x41, 0x00, 0x00, 0x00, 0x0e, 0x00, 0x00, 0x00, 0x33, 0x00, 0x00, 0x00, 0x0d, 0x00, 0x00, 0x00
        .byte 0x33, 0x00, 0x00, 0x00, 0x0e, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00

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
        .byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00
        .byte 0x03, 0x00, 0x00, 0x00

	.global gUnknown_81076BC
gUnknown_81076BC: @ 81076BC
        .string "etcfont\0"
        .align 2,0

	.global gUnknown_81076C4
gUnknown_81076C4: @ 81076C4
.byte 0xfc, 0xff, 0xff, 0xff, 0xf8, 0xff, 0xff, 0xff, 0xf0, 0xff, 0xff, 0xff, 0xfc, 0xff, 0xff, 0xff, 0xf8, 0xff, 0xff, 0xff, 0xf0, 0xff, 0xff, 0xff, 0x70, 0x6b, 0x73, 0x64, 0x69, 0x72, 0x30, 0x00

	.global gIQSkillGroups
gIQSkillGroups: @ 81076E4
        .4byte 9999
        .4byte 4
        .4byte 1
        .4byte 2
        .4byte 4
        .4byte 4
        .4byte 6
        .4byte 7
        .4byte 8
        .4byte 9
        .4byte 9
        .4byte 9
        .4byte 10
        .4byte 10
        .4byte 11
        .4byte 11
        .4byte 14
        .4byte 14
        .4byte 14
        .4byte 16
        .4byte 16
        .4byte 9
        .4byte 17
        .4byte 6
        .string "pksdir0\0"
        .string "pksdir0\0"

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
        .string "{ARG_MOVE_ITEM_1}\0"
        .align 2,0

	.global gUnknown_8107788
gUnknown_8107788: @ 8107788
        .byte 0x87, 0x42, 0x00, 0x00

	.global gUnknown_810778C
gUnknown_810778C: @ 810778C
        .byte 0x87, 0x40, 0x00, 0x00

	.global gUnknown_8107790
gUnknown_8107790: @ 8107790
        .string "{ARG_MOVE_ITEM_0}{ARG_MOVE_ITEM_1}\0"
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
@ u16*s
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
        .string "{COLOR_2 YELLOW_4}%s{END_COLOR_TEXT_2}\0"
        .align 2,0

	.global gUnknown_8108F18
gUnknown_8108F18: @ 8108F18
        .string "{COLOR_2 YELLOW_4}%s{END_COLOR_TEXT_2}"
        .byte 0x81, 0x40
        .string "{COLOR_2 CYAN}%d{END_COLOR_TEXT_2}F\0"
        .align 2,0

	.global gUnknown_8108F2C
gUnknown_8108F2C: @ 8108F2C
        .string "{COLOR_2 YELLOW_4}%s{END_COLOR_TEXT_2}"
        .byte 0x81, 0x40
        .string "B{COLOR_2 CYAN}%d{END_COLOR_TEXT_2}F\0"
        .align 2,0

	.global gUnknown_8108F40
gUnknown_8108F40: @ 8108F40
        .byte 0x00, 0x00

	.global gUnknown_8108F42
gUnknown_8108F42: @ 8108F42
        .byte 0x99, 0x00, 0x9c, 0x00, 0x9e, 0x00, 0xdb, 0x00

	.global gUnknown_8108F4A
gUnknown_8108F4A: @ 8108F4A
        .byte 0xe1, 0xe7, 0xe6, 0xe2, 0x00, 0x00

	.global gUnknown_8108F50
gUnknown_8108F50: @ 8108F50
        .string "No problem.\0"
        .align 2,0
        .string "pksdir0\0"
        .align 2,0

	.global gUnknown_8108F64
gUnknown_8108F64: @ 8108F64
	.incbin "baserom.gba", 0x108F64, 0x800

	.global gItemParaFileName
gItemParaFileName: @ 8109764
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
        @ replacing .incbin "baserom.gba", 0x0010977c, 0x8
        .string "%d {POKE}\0"

	.global gUnknown_8109784
gUnknown_8109784: @ 8109784
        @ replacing .incbin "baserom.gba", 0x00109784, 0x8
        .byte 0x87, 0x44
        .asciz "%s\0"
        .align 2,0

	.global gUnknown_810978C
gUnknown_810978C: @ 810978C
        @ replacing .incbin "baserom.gba", 0x0010978c, 0x8
        .byte 0x87, 0x41
        .asciz "%s\0"
        .align 2,0

	.global gUnknown_8109794
gUnknown_8109794: @ 8109794
        @ replacing .incbin "baserom.gba", 0x00109794, 0x10
        .byte 0x25, 0x73, 0x23, 0x3d, 0x25, 0x63, 0x23, 0x43, 0x04, 0x25, 0x73, 0x23, 0x52, 0x00, 0x00, 0x00

	.global gUnknown_81097A4
gUnknown_81097A4: @ 81097A4
        @ replacing .incbin "baserom.gba", 0x001097a4, 0xc
        .byte 0x25, 0x73, 0x23, 0x43, 0x04, 0x25, 0x73, 0x23, 0x52, 0x00, 0x00, 0x00

	.global gUnknown_81097B0
gUnknown_81097B0: @ 81097B0
        @ replacing .incbin "baserom.gba", 0x001097b0, 0x14
        .byte 0xa0, 0x86, 0x01, 0x00, 0x10, 0x27, 0x00, 0x00, 0xe8, 0x03, 0x00, 0x00, 0x64, 0x00, 0x00, 0x00, 0x0a, 0x00, 0x00, 0x00

	.global gUnknown_81097C4
gUnknown_81097C4: @ 81097C4
        .byte 0x83

	.global gUnknown_81097C5
gUnknown_81097C5: @ 81097C5
        @ replacing .incbin "baserom.gba", 0x001097c5, 0x1b
        .byte 0x9f, 0x83, 0xa0, 0x83, 0xa1, 0x83, 0xa2, 0x83, 0xa3, 0x83, 0xa4, 0x83, 0xa5, 0x83, 0xa6, 0x83, 0xa7, 0x83, 0xa8, 0x00, 0x00, 0x00, 0x00, 0xc4, 0x97, 0x10, 0x08

	.global gGummiStatBoostLUT
gGummiStatBoostLUT: @ 81097E0
        @ replacing .incbin "baserom.gba", 0x001097e0, 0x8
        .2byte 0x0001
        .2byte 0x0002
        .2byte 0x0004
        .2byte 0x0008

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
        .4byte 50
        .4byte 500
        .4byte 1500
        .4byte 3000
        .4byte 7500
        .4byte 15000
        .4byte 100000000

	.global gTeamNamePlaceholder
gTeamNamePlaceholder: @ 810982C
        .string "Pokémon\0"
        .string "pksdir0\0"

	.global gUnknown_810983C
gUnknown_810983C: @ 810983C
	.incbin "baserom.gba", 0x10983C, 0x68

	.global gUnknown_81098A4
gUnknown_81098A4: @ 81098A4
	.string "{COLOR_2}"
        .byte 0x4
        .string "%s{END_COLOR_TEXT_2}\0"
        .align 2,0

	.global gUnknown_81098AC
gUnknown_81098AC: @ 81098AC
        .string "%s#=%c{COLOR_1}"
        .byte 0x4
        .string "%s{END_COLOR_TEXT_1}\0"
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
        .string "{COLOR_2}%c%s%s{END_COLOR_TEXT_2}\0"
        .align 2,0

	.global gUnknown_81098EC
gUnknown_81098EC: @ 81098EC
        .string "{COLOR_2}%c#:%s%s%s#;%c%2d/%2d{END_COLOR_TEXT_2}\0"
        .align 2,0

	.global gUnknown_8109908
gUnknown_8109908: @ 8109908
        .byte 0x87, 0x41, 0x00, 0x00 @ apparently shows A in memory viewer

	.global gUnknown_810990C
gUnknown_810990C: @ 810990C
        .byte 0x87, 0x40, 0x00, 0x00 @ apparently shows @ in memory viewer

	.global gUnknown_8109910
gUnknown_8109910: @ 8109910
        .string "{COLOR_2}%c%s%s%s#=%c%2d/%2d{END_COLOR_TEXT_2}\0"
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
        .string "{ARG_POKEMON_0}\0"
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
        .string "{COLOR_1 YELLOW_3}Scenario try dummy{END_COLOR_TEXT_1}\0"
        .align 2,0

	.global gUnknown_8109CC0
gUnknown_8109CC0: @ 8109CC0
        .string "{COLOR_1 RED_2}???{END_COLOR_TEXT_1}\0"
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

	.global gInvalidItemIDs
gInvalidItemIDs: @ 810A35B (item related)
        @ replacing .incbin "baserom.gba", 0x0010a35b, 0x10
        .byte 0xed, 0xee, 0xef, 0xb1, 0xe9, 0x24, 0xd8, 0xd2, 0xb0, 0xdc, 0x32, 0x33, 0x34, 0xc2, 0xec, 0xf0

	.global gTacticsTargetLeader
gTacticsTargetLeader: @ 810A36B
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

	.global gReqTacticLvls
gReqTacticLvls: @ 810A378
        @ replacing .incbin "baserom.gba", 0x0010a378, 0x18
        .2byte 1
        .2byte 25
        .2byte 1
        .2byte 1
        .2byte 999
        .2byte 999
        .2byte 35
        .2byte 40
        .2byte 20
        .2byte 15
        .2byte 10
        .2byte 999

	.global gReqIQSkillPts
gReqIQSkillPts: @ 810A390
        .byte 0x0f, 0x27, 0x00, 0x00
        .byte 0x69, 0x00, 0x00, 0x00
        .byte 0x01, 0x00, 0x00, 0x00
        .byte 0x01, 0x00, 0x00, 0x00
        .byte 0xf4, 0x01, 0x00, 0x00
        .byte 0x64, 0x00, 0x00, 0x00
        .byte 0x02, 0x00, 0x00, 0x00
        .byte 0x28, 0x00, 0x00, 0x00
        .byte 0x19, 0x00, 0x00, 0x00
        .byte 0xc8, 0x00, 0x00, 0x00
        .byte 0x0a, 0x00, 0x00, 0x00
        .byte 0x7d, 0x00, 0x00, 0x00
        .byte 0x90, 0x01, 0x00, 0x00
        .byte 0xde, 0x03, 0x00, 0x00
        .byte 0x8c, 0x00, 0x00, 0x00
        .byte 0x20, 0x03, 0x00, 0x00
        .byte 0xfa, 0x00, 0x00, 0x00
        .byte 0xa0, 0x00, 0x00, 0x00
        .byte 0x46, 0x00, 0x00, 0x00
        .byte 0x58, 0x02, 0x00, 0x00
        .byte 0x2c, 0x01, 0x00, 0x00
        .byte 0x01, 0x00, 0x00, 0x00
        .byte 0x01, 0x00, 0x00, 0x00
        .byte 0x01, 0x00, 0x00, 0x00

	.global gUnknown_810A3F0
gUnknown_810A3F0: @ 810A3F0 (money related according to PMDe
				  @ LUT for money item stack size -> money amount

        .4byte   4,     6,    10,    14,    22,    26,    34,    38,    46,    58
        .4byte  62,    74,    82,    86,    94,   106,   118,   122,   134,   142
        .4byte 146,   158,   166,   178,   194,   202,   206,   214,   218,   226
        .4byte 254,   262,   274,   278,   298,   302,   314,   326,   334,   346
        .4byte 358,   362,   382,   386,   394,   398,   422,   446,   454,   458
        .4byte 466,   478,   482,   502,   514,   526,   538,   542,   554,   562
        .4byte 566,   586,   614,   622,   626,   634,   662,   674,   694,   698
        .4byte 706,   718,   734,   746,   758,   768,   778,   794,   802,   818
        .4byte 838,   842,   862,   866,   878,   886,   898,   914,   922,   926
        .4byte 934,   958,   974,   982,   998,  1000,  1100,  1300,  1500, 20000

	.global gTypeGummiIQBoost
gTypeGummiIQBoost: @ 810A580
	// s16[0x12][NUMBER_OF_GUMMIS = 18]
	// relates [type][gummi tyep] -> iq boost amount
	.incbin "baserom.gba", 0x10A580, 0x288

	.global gUnknown_810A808
gUnknown_810A808: @ 810A808
	.incbin "baserom.gba", 0x10A808, 0x288
