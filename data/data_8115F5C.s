.section .rodata

.global gUnknown_811601C
gUnknown_811601C: @ 811601C
.string "fontsppa\0"
.align 2,0

.global gUnknown_8116028
gUnknown_8116028: @ 8116028
.string "fontpal\0"
.string "pksdir0\0"
.string "pksdir0\0"
.align 2,0

.global gUnknown_8116040
gUnknown_8116040: @ 8116040
.byte 0x02, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0c, 0x00, 0x05, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x17, 0x00, 0x08, 0x00, 0x01, 0x00, 0x00, 0x00
.byte 0x07, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x12, 0x00, 0x08, 0x00, 0x01, 0x00, 0x00, 0x00, 0x0d, 0x00, 0x05, 0x00, 0x01, 0x00, 0x00, 0x00, 0x02, 0x00, 0x08, 0x00, 0x01, 0x00, 0x00, 0x00
.byte 0x17, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0x00, 0x08, 0x00, 0x01, 0x00, 0x00, 0x00, 0x12, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0c, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00
.byte 0x02, 0x00, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x17, 0x00, 0x02, 0x00, 0x01, 0x00, 0x00, 0x00, 0x07, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x12, 0x00, 0x01, 0x00, 0x01, 0x00, 0x00, 0x00
.byte 0x0d, 0x00, 0x01, 0x00, 0x01, 0x00, 0x00, 0x00, 0x02, 0x00, 0x02, 0x00, 0x01, 0x00, 0x00, 0x00, 0x17, 0x00, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0x00, 0x01, 0x00, 0x01, 0x00, 0x00, 0x00
.byte 0x12, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00

.global gUnknown_81160E8
gUnknown_81160E8: @ 81160E8
.4byte Yes_8116104
.byte 0x01, 0x00, 0x00, 0x00
.4byte No_8116100
.byte 0x00, 0x00, 0x00, 0x00
.byte 0x00, 0x00, 0x00, 0x00
.byte 0x00, 0x00, 0x00, 0x00

.global No_8116100
No_8116100: @ 8116100
.string "No\0"
.align 2,0

.global Yes_8116104
Yes_8116104: @ 8116104
.string "*Yes\0"
.align 2,0

.global gUnknown_811610C
gUnknown_811610C: @ 811610C
.4byte Yes_8116128
.byte 0x01, 0x00, 0x00, 0x00
.4byte No_8116124
.byte 0x00, 0x00, 0x00, 0x00
.byte 0x00, 0x00, 0x00, 0x00
.byte 0x00, 0x00, 0x00, 0x00

.global No_8116124
No_8116124: @ 8116124
.string "*No\0"
.align 2,0

.global Yes_8116128
Yes_8116128: @ 8116128
.string "Yes\0"
.align 2,0

.global gUnknown_811612C
gUnknown_811612C: @ 811612C
.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00

.global gUnknown_8116134
gUnknown_8116134: @ 8116134
.byte 0x01, 0x00, 0x00, 0x00
.byte 0x01, 0x00, 0x00, 0x00
.byte 0x01, 0x00, 0x00, 0x00
.byte 0x01, 0x00, 0x00, 0x00
.byte 0x01, 0x00, 0x00, 0x00

.global gUnknown_8116148
gUnknown_8116148: @ 8116148
.byte 0xe2, 0x00
.byte 0xc2, 0x00
.byte 0xc2, 0x01
.byte 0xc2, 0x02
.byte 0x01, 0x00
.byte 0x21, 0x01
.byte 0x01, 0x01
.byte 0x0d, 0x01
.byte 0x05, 0x01
.byte 0x00, 0x00

.global gInvalidityText
gInvalidityText: @ 811615C
.string "{COLOR_1 RED_2}invalidity{END_COLOR_TEXT_1}\0"
.align 2,0

.global gUndefineText
gUndefineText: @ 811616C
.string "{COLOR_1 RED_2}undefine{END_COLOR_TEXT_1}\0"
.align 2,0

.global gSpeechBubbleChar
gSpeechBubbleChar: @ 811617C
.byte 0x87, 0x45, 0x00, 0x00

.global gFormattedSpeechBubble
gFormattedSpeechBubble: @ 8116180
.string "{COLOR_1 YELLOW_5}{SPEECH_BUBBLE}{END_COLOR_TEXT_1}\0"

.global gUnknown_8116188
gUnknown_8116188: @ 8116188
.string "{COLOR_1 YELLOW_5}%s{END_COLOR_TEXT_1}\0"
.align 2,0

.global gUnknown_8116190
gUnknown_8116190: @ 8116190
@ replacing .incbin "baserom.gba", 0x00116190, 0x18
.byte 0x25, 0x73, 0x23, 0x5b, 0x49, 0x5d, 0x23, 0x7e, 0x20, 0x81, 0x40, 0x23, 0x57, 0x0a, 0x23, 0x5b, 0x4f, 0x5d, 0x23, 0x7e, 0x20, 0x81, 0x40, 0x00

.global gUnknown_81161A8
gUnknown_81161A8: @ 81161A8
.4byte 1
.4byte 0
.4byte sub_809C39C
.4byte sub_801D0DC

.global gUnknown_81161B8
gUnknown_81161B8: @ 81161B8
.4byte 1
.4byte 0
.4byte sub_809C3D8
.4byte sub_801D0DC

.global gUnknown_81161C8
gUnknown_81161C8: @ 81161C8
.4byte 1
.4byte 0
.4byte DeleteKangaskhanStorage
.4byte KangaskhanStorageCallback

.global gUnknown_81161D8
gUnknown_81161D8: @ 81161D8
.4byte 1
.4byte sub_8017E1C
.4byte sub_8017EF4
.4byte sub_8017E54

.global gUnknown_81161E8
gUnknown_81161E8: @ 81161E8
.4byte 1
.4byte 0
.4byte DestroyFelicityBank
.4byte FelicityBankCallback

.global gUnknown_81161F8
gUnknown_81161F8: @ 81161F8
.4byte 1
.4byte 0
.4byte DeleteKecleonBros
.4byte KecleonBrosCallback

.global gUnknown_8116208
gUnknown_8116208: @ 8116208
.4byte 1
.4byte 0
.4byte sub_801FD7C
.4byte sub_801FC40

.global gUnknown_8116218
gUnknown_8116218: @ 8116218
.4byte 1
.4byte 0
.4byte CleanWigglytuffShop 
.4byte sub_8021C5C

.global gUnknown_8116228
gUnknown_8116228: @ 8116228
.4byte 1
.4byte sub_8027F88
.4byte sub_809C504
.4byte sub_8028078

.global gUnknown_8116238
gUnknown_8116238: @ 8116238
.4byte 1
.4byte sub_802B2D4
.4byte sub_802B3B8
.4byte sub_802B358

.global gUnknown_8116248
gUnknown_8116248: @ 8116248
.4byte 1
.4byte CreateThankYouMailPelipper
.4byte CleanThankYouMailPelipper
.4byte ThankYouMailPelipperCallback

.global gUnknown_8116258
gUnknown_8116258: @ 8116258
.4byte 1
.4byte 0
.4byte CleanHelperPelipper
.4byte HelperPelipperCallback

.global gUnknown_8116268
gUnknown_8116268: @ 8116268
.4byte 1
.4byte sub_802E864
.4byte sub_809C550
.4byte sub_802E890

.global gUnknown_8116278
gUnknown_8116278: @ 8116278
.4byte 1
.4byte sub_802DFB0
.4byte sub_802E06C
.4byte sub_802DFD8

.global gUnknown_8116288
gUnknown_8116288: @ 8116288
.4byte 1
.4byte 0
.4byte sub_802DC00
.4byte sub_802DBD4

.global gUnknown_8116298
gUnknown_8116298: @ 8116298
.4byte 1
.4byte 0
.4byte MakuhitaDojo_Delete
.4byte HandleMakuhitaDojoState

.global gUnknown_81162A8
gUnknown_81162A8: @ 81162A8
.4byte 1
.4byte 0
.4byte MakuhitaDojo_Delete
.4byte HandleMakuhitaDojoState

.global gUnknown_81162B8
gUnknown_81162B8: @ 81162B8
        .4byte 1
        .4byte 0
        .4byte MakuhitaDojo_Delete
        .4byte HandleMakuhitaDojoState

.global gUnknown_81162C8
gUnknown_81162C8: @ 81162C8
        .4byte 0
        .4byte CreateTestTracker
        .4byte sub_809C464
        .4byte HandleTestTrackerState

.global gUnknown_81162D8
gUnknown_81162D8: @ 81162D8
        .4byte 0
        .4byte sub_8035678
        .4byte sub_809C478
        .4byte sub_80356A0

.global gUnknown_81162E8
gUnknown_81162E8: @ 81162E8
        .4byte 0
        .4byte 0
        .4byte sub_809C4B0
        .4byte sub_803B120

.global gUnknown_81162F8
gUnknown_81162F8: @ 81162F8
        .4byte 1
        .4byte 0
        .4byte sub_809C414
        .4byte sub_8025354

.global gUnknown_8116308
gUnknown_8116308: @ 8116308
        .4byte 0
        .4byte 0
        .4byte 0
        .4byte sub_809CD48

.global gUnknown_8116318
gUnknown_8116318: @ 8116318
        .4byte 1
        .4byte 0
        .4byte sub_801B72C
        .4byte sub_801B6AC

.byte 0x70, 0x6b, 0x73, 0x64, 0x69, 0x72, 0x30, 0x00, 0x00, 0x00, 0x00, 0x00, 0x70, 0x6b, 0x73, 0x64
.byte 0x69, 0x72, 0x30, 0x00

.global gUnknown_811633C
gUnknown_811633C: @ 811633C
.string "{CENTER_ALIGN}{ARG_NICKNAME_0}'s team received\n"
.string "{CENTER_ALIGN}the {ARG_MOVE_ITEM_0} cash reward.\0"
.align 2, 0

.global gUnknown_811636C
gUnknown_811636C: @ 811636C
.string "{CENTER_ALIGN}The team also received\n"
.string "{CENTER_ALIGN}one {ARG_MOVE_ITEM_0}.\0"
.align 2, 0

.global gUnknown_8116390
gUnknown_8116390: @ 8116390
.string "{CENTER_ALIGN}{ARG_NICKNAME_0}'s team received\n"
.string "{CENTER_ALIGN}the reward {ARG_MOVE_ITEM_0}.\0"
.align 2, 0

.global gUnknown_81163BC
gUnknown_81163BC: @ 81163BC
@ replacing .incbin "baserom.gba", 0x1163BC, 0x28
.byte 0x37, 0x00, 0x00, 0x00
.byte 0x42, 0x00, 0x00, 0x00
.byte 0x3f, 0x00, 0x00, 0x00
.byte 0x69, 0x00, 0xf4, 0x01
.byte 0x3a, 0x00, 0x00, 0x00
.byte 0x3f, 0x00, 0x00, 0x00
.byte 0x69, 0x00, 0xf4, 0x01
.byte 0x14, 0x00, 0x00, 0x00
.byte 0x3f, 0x00, 0x00, 0x00
.byte 0x69, 0x00, 0x10, 0x27

.global gUnknown_81163E4
gUnknown_81163E4: @ 81163E4
.string "{COLOR_1 LIGHT_BLUE}%d{END_COLOR_TEXT_1} %s\0"
.align 2,0

.global gUnknown_81163F0
gUnknown_81163F0: @ 81163F0
.string "{CENTER_ALIGN}However, {ARG_NICKNAME_0}'s team\n"
.string "{CENTER_ALIGN}had too much money already...\0"
.align 2,0

.global gUnknown_811642C
gUnknown_811642C: @ 811642C
.string "{CENTER_ALIGN}However, {ARG_NICKNAME_0}'s team\n"
.string "{CENTER_ALIGN}had too many items already...\0"
.align 2,0
.string "pksdir0\0"
.align 2,0
.string "pksdir0\0"
.align 2,0

.global gZeroPos_8116478
gZeroPos_8116478: @ 8116478
.byte 0x00, 0x00, 0x00, 0x00
.byte 0x00, 0x00, 0x00, 0x00
.string "pksdir0\0"
.align 2,0

.global gGroundScriptTriggerCallbacks
gGroundScriptTriggerCallbacks: @ 8116488
.byte 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00

.global gUnknown_81164DC
gUnknown_81164DC: @ 81164DC
.byte 0x00, 0x00, 0x00, 0x00
.byte 0x00, 0x00, 0x00, 0x00

.global gUnknown_81164E4
gUnknown_81164E4: @ 81164E4
.byte 0xf6, 0x00, 0xc5, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.4byte GroundScriptFile_Text
.byte 0xef, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00

.global GroundScriptFile_Text
GroundScriptFile_Text:
.string "../ground/ground_script.c\0"
.align 2,0

.global GroundScript_ExecutePP_Text
GroundScript_ExecutePP_Text:
.string "GroundScript_ExecutePP\0"
.align 2,0

.global gUnknown_8116538
gUnknown_8116538: @ 8116538
.4byte GroundScriptFile_Text
.4byte 0x000002b0
.4byte GroundScript_ExecutePP_Text

.global gUnknown_8116544
gUnknown_8116544: @ 8116544
.string "execute script type error B\0"
.align 2,0

.global gUnknown_8116560
gUnknown_8116560: @ 8116560
.4byte GroundScriptFile_Text
.4byte 0x000002b1
.4byte GroundScript_ExecutePP_Text

.global gUnknown_811656C
gUnknown_811656C: @ 811656C
.string "execute script type error C\0"
.align 2,0

.global gUnknown_8116588
gUnknown_8116588: @ 8116588
.4byte GroundScriptFile_Text
.4byte 0x000002c4
.4byte GroundScript_ExecutePP_Text

.global gUnknown_8116594
gUnknown_8116594: @ 8116594
.string "execute script type error %d\0"
.align 2,0

.global GroundScript_Cancel_Text
GroundScript_Cancel_Text:
.string "GroundScript_Cancel\0"
.align 2,0

.global gUnknown_81165C8
gUnknown_81165C8: @ 81165C8
.4byte GroundScriptFile_Text
.4byte 0x00000335
.4byte GroundScript_Cancel_Text

.global gUnknown_81165D4
gUnknown_81165D4: @ 81165D4
.string "    ground select %3d[%s] %3d\0"
.align 2,0

.global gUnknown_81165F4
gUnknown_81165F4: @ 81165F4
.string "    dungeon select %3d\0"
.align 2,0

.global gUnknown_811660C
gUnknown_811660C: @ 811660C
.string "    dungeon enter check %3d\0"
.align 2,0

.global gUnknown_8116628
gUnknown_8116628: @ 8116628
.string "    map select %3d %3d[%s]\0"
.align 2,0

.global gUnknown_8116644
gUnknown_8116644: @ 8116644
.string "    ground select %3d %3d[%s]\0"
.align 2,0

.global gUnknown_8116664
gUnknown_8116664: @ 8116664
.string "    dungeon select %3d %3d[%s]\0"
.align 2,0

.global gUnknown_8116684
gUnknown_8116684: @ 8116684
.string "    dungeon rescue select %3d\0"
.align 2,0

.global AnalyzeProcess_Text
AnalyzeProcess_Text: @ Text
.string "_AnalyzeProcess\0"
.align 2,0

.global gUnknown_81166B4
gUnknown_81166B4: @ 81166B4
.4byte GroundScriptFile_Text
.4byte 0x0000107e
.4byte AnalyzeProcess_Text

.global gUnknown_81166C0
gUnknown_81166C0: @ 81166C0
.string "switch type error %d\0"
.align 2,0

.global gUnknown_81166D8
gUnknown_81166D8: @ 81166D8
.byte 0x00, 0x00, 0x00, 0x00

.global GroundScript_ExecuteTrigger_Text
GroundScript_ExecuteTrigger_Text:
.string "GroundScript_ExecuteTrigger\0"
.align 2,0

.global gUnknown_81166F8
gUnknown_81166F8: @ 81166F8
.4byte GroundScriptFile_Text
.4byte 0x000011c9
.4byte GroundScript_ExecuteTrigger_Text

.global gUnknown_8116704
gUnknown_8116704: @ 8116704
.4byte GroundScriptFile_Text
.4byte 0x000011ce
.4byte GroundScript_ExecuteTrigger_Text

.global gUnknown_8116710
gUnknown_8116710: @ 8116710
@ replacing .incbin "baserom.gba", 0x00116710, 0x28
.byte 0x98, 0x9d, 0x03, 0x02, 0x51, 0x00, 0x00, 0x00, 0x46, 0x00, 0x00, 0x00, 0x53, 0x00, 0x9a, 0x00, 0xbc, 0x00, 0x00, 0x00, 0x26, 0x00, 0x06, 0x00, 0x01, 0x00, 0x14, 0x00, 0x12, 0x00, 0x14, 0x00
.byte 0x12, 0x00, 0x00, 0x00, 0xd0, 0x11, 0x00, 0x00

.global gUnknown_8116738
gUnknown_8116738: @ 8116738
@ replacing .incbin "baserom.gba", 0x00116738, 0x28
.byte 0x98, 0x9d, 0x03, 0x02, 0x83, 0x01, 0x00, 0x00, 0x43, 0x00, 0x00, 0x00, 0x04, 0x01, 0xe0, 0x00, 0xac, 0x00, 0xbe, 0x00, 0x50, 0x00, 0x14, 0x00, 0x01, 0x00, 0x21, 0x00, 0x20, 0x00, 0x1f, 0x00
.byte 0x20, 0x00, 0x00, 0x00, 0xf8, 0xa7, 0x00, 0x00

.global gUnknown_8116760
gUnknown_8116760: @ 8116760
@ replacing .incbin "baserom.gba", 0x00116760, 0x28
.byte 0x98, 0x9d, 0x03, 0x02, 0x04, 0x01, 0x00, 0x00, 0x44, 0x00, 0x00, 0x00, 0x8a, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x2f, 0x00, 0x05, 0x00, 0x01, 0x00, 0x10, 0x00, 0x14, 0x00, 0x14, 0x00
.byte 0x10, 0x00, 0x00, 0x00, 0x40, 0x06, 0x00, 0x00

.global gUnknown_8116788
gUnknown_8116788: @ 8116788
.byte 0x06, 0x63, 0x00, 0x00

.global gUnknown_811678C
gUnknown_811678C: @ 811678C
.byte 0x0a, 0x63, 0x00, 0x00

.global gUnknown_8116790
gUnknown_8116790: @ 8116790
.byte 0x0c, 0x63, 0x00, 0x00

.global gUnknown_8116794
gUnknown_8116794: @ 8116794
@ replacing .incbin "baserom.gba", 0x00116794, 0x28
.byte 0x98, 0x9d, 0x03, 0x02, 0x99, 0x01, 0x00, 0x00, 0x45, 0x00, 0x00, 0x00, 0x6c, 0x00, 0x2b, 0x00, 0xb9, 0x00, 0x86, 0x00, 0x7d, 0x00, 0x1e, 0x00, 0x01, 0x00, 0x3c, 0x00, 0x3b, 0x00, 0x2a, 0x00
.byte 0x2c, 0x00, 0x00, 0x00, 0xf8, 0x2b, 0x04, 0x00

.global gUnknown_81167BC
gUnknown_81167BC: @ 81167BC
@ replacing .incbin "baserom.gba", 0x001167bc, 0x28
.byte 0x98, 0x9d, 0x03, 0x02, 0x98, 0x01, 0x00, 0x00, 0x45, 0x00, 0x00, 0x00, 0x6c, 0x00, 0xe1, 0x00, 0xb9, 0x00, 0x86, 0x00, 0x78, 0x00, 0x1c, 0x00, 0x01, 0x00, 0x3a, 0x00, 0x39, 0x00, 0x28, 0x00
.byte 0x2b, 0x00, 0x00, 0x00, 0x98, 0xbe, 0x03, 0x00

.global gUnknown_81167E4
gUnknown_81167E4: @ 81167E4
.byte 0x00, 0x00
.byte 0x36, 0x00

.global gUnknown_81167E8
gUnknown_81167E8: @ 81167E8
.byte 0x48, 0x00, 0x00, 0x00

.global gUnknown_81167EC
gUnknown_81167EC: @ 81167EC
.string "{CENTER_ALIGN}The rescue rank went up from\n"
.string "{CENTER_ALIGN}{ARG_MOVE_ITEM_0} to {ARG_MOVE_ITEM_1}!\0"
.align 2,0

.global gUnknown_811681C
gUnknown_811681C: @ 811681C
@ replacing .incbin "baserom.gba", 0x11681C, 0x28
.byte 0x98, 0x9d, 0x03, 0x02, 0x33, 0x01, 0x00, 0x00, 0x48, 0x00, 0x00, 0x00, 0xea, 0x00, 0x38, 0x00
.byte 0xbb, 0x00, 0xd9, 0x00, 0x35, 0x00, 0x05, 0x00, 0x01, 0x00, 0x12, 0x00, 0x12, 0x00, 0x0b, 0x00
.byte 0x0a, 0x00, 0x00, 0x00, 0xf0, 0x0a, 0x00, 0x00

.global gUnknown_8116844
gUnknown_8116844: @ 8116844
.byte 0x00, 0x00, 0x52, 0x00

.global gUnknown_8116848
gUnknown_8116848: @ 8116848
.string "GroundScript unlock %3d\0"
.align 2,0

.global SearchScriptLabelText
SearchScriptLabelText:
.string "_SearchScriptLabel\0"
.align 2,0
.4byte GroundScriptFile_Text
.byte 0xbe, 0x16, 0x00, 0x00
.4byte SearchScriptLabelText
.string "Script label search error %d\0"
.align 2,0
.string "pksdir0\0"
.align 2,0

.global gUnknown_81168A8
gUnknown_81168A8: @ 81168A8
@ replacing .incbin "baserom.gba", 0x1168A8, 0x67C
.byte 0xb2, 0x00, 0xb2, 0x00, 0xb2, 0x00, 0xff, 0xff, 0xff, 0xff, 0x67, 0x01, 0x00, 0x00, 0x00, 0x00
.byte 0x01, 0x01, 0x00, 0x00, 0x09, 0x00, 0x0c, 0x00, 0x0c, 0x00, 0x7f, 0x00, 0x81, 0x00, 0x68, 0x01
.byte 0x01, 0x00, 0x01, 0x00, 0x01, 0x01, 0x00, 0x00, 0x09, 0x00, 0x0c, 0x00, 0x0c, 0x00, 0x88, 0x00
.byte 0x8a, 0x00, 0x69, 0x01, 0x02, 0x00, 0x02, 0x00, 0x01, 0x01, 0x00, 0x00, 0xff, 0xff, 0x0c, 0x00
.byte 0x0c, 0x00, 0xff, 0xff, 0xff, 0xff, 0x69, 0x01, 0x02, 0x00, 0x02, 0x00, 0x01, 0x00, 0x00, 0x00
.byte 0x09, 0x00, 0x0c, 0x00, 0x0c, 0x00, 0x94, 0x00, 0x96, 0x00, 0x6a, 0x01, 0x03, 0x00, 0x03, 0x00
.byte 0x01, 0x01, 0x00, 0x00, 0xff, 0xff, 0x0c, 0x00, 0x0c, 0x00, 0xff, 0xff, 0xff, 0xff, 0x6a, 0x01
.byte 0x03, 0x00, 0x03, 0x00, 0x01, 0x00, 0x00, 0x00, 0x09, 0x00, 0x0c, 0x00, 0x0c, 0x00, 0x9b, 0x00
.byte 0x9d, 0x00, 0x6b, 0x01, 0x04, 0x00, 0x04, 0x00, 0x01, 0x01, 0x00, 0x00, 0x09, 0x00, 0xbd, 0x00
.byte 0x0c, 0x00, 0xa2, 0x00, 0xa4, 0x00, 0x6c, 0x01, 0x05, 0x00, 0x05, 0x00, 0x01, 0x01, 0x00, 0x00
.byte 0xff, 0xff, 0x0c, 0x00, 0xbd, 0x00, 0xff, 0xff, 0xff, 0xff, 0x6c, 0x01, 0x06, 0x00, 0x05, 0x00
.byte 0x01, 0x01, 0x00, 0x00, 0x09, 0x00, 0x0c, 0x00, 0x0c, 0x00, 0xaa, 0x00, 0xac, 0x00, 0x6d, 0x01
.byte 0x07, 0x00, 0x06, 0x00, 0x01, 0x01, 0x00, 0x00, 0xc1, 0x00, 0xc2, 0x00, 0xc1, 0x00, 0xff, 0xff
.byte 0xff, 0xff, 0x6e, 0x01, 0x08, 0x00, 0x07, 0x00, 0x01, 0x01, 0x00, 0x00, 0xc3, 0x00, 0xc4, 0x00
.byte 0xc3, 0x00, 0xff, 0xff, 0xff, 0xff, 0x6f, 0x01, 0x09, 0x00, 0x08, 0x00, 0x01, 0x01, 0x00, 0x00
.byte 0xff, 0xff, 0xff, 0xff, 0xc4, 0x00, 0xff, 0xff, 0xff, 0xff, 0x6f, 0x01, 0x0a, 0x00, 0x08, 0x00
.byte 0x01, 0x01, 0x00, 0x00, 0xc6, 0x00, 0xc7, 0x00, 0xc6, 0x00, 0xff, 0xff, 0xff, 0xff, 0x70, 0x01
.byte 0x0b, 0x00, 0x09, 0x00, 0x01, 0x01, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0xc7, 0x00, 0xff, 0xff
.byte 0xff, 0xff, 0x70, 0x01, 0x0c, 0x00, 0x09, 0x00, 0x01, 0x01, 0x00, 0x00, 0xc9, 0x00, 0xca, 0x00
.byte 0xc9, 0x00, 0xff, 0xff, 0xff, 0xff, 0x71, 0x01, 0x0d, 0x00, 0x0a, 0x00, 0x01, 0x01, 0x00, 0x00
.byte 0xff, 0xff, 0xff, 0xff, 0xca, 0x00, 0xff, 0xff, 0xff, 0xff, 0x71, 0x01, 0x0e, 0x00, 0x0a, 0x00
.byte 0x01, 0x01, 0x00, 0x00, 0x09, 0x00, 0xcd, 0x00, 0x0c, 0x00, 0xde, 0x00, 0xe0, 0x00, 0x72, 0x01
.byte 0x0f, 0x00, 0x0b, 0x00, 0x01, 0x01, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0xcd, 0x00, 0xff, 0xff
.byte 0xff, 0xff, 0x72, 0x01, 0x10, 0x00, 0x0b, 0x00, 0x01, 0x01, 0x00, 0x00, 0x09, 0x00, 0xd0, 0x00
.byte 0x0c, 0x00, 0xe6, 0x00, 0xe8, 0x00, 0x73, 0x01, 0x11, 0x00, 0x0c, 0x00, 0x01, 0x01, 0x00, 0x00
.byte 0xff, 0xff, 0xff, 0xff, 0xd0, 0x00, 0xff, 0xff, 0xff, 0xff, 0x73, 0x01, 0x12, 0x00, 0x0c, 0x00
.byte 0x01, 0x01, 0x00, 0x00, 0x09, 0x00, 0x0c, 0x00, 0x0c, 0x00, 0xff, 0xff, 0xff, 0xff, 0x74, 0x01
.byte 0x00, 0x00, 0x0d, 0x00, 0x01, 0x00, 0x00, 0x00, 0x09, 0x00, 0x0c, 0x00, 0x0c, 0x00, 0xff, 0xff
.byte 0xff, 0xff, 0x75, 0x01, 0x2a, 0x00, 0x0e, 0x00, 0x01, 0x01, 0x00, 0x00, 0x09, 0x00, 0x0c, 0x00
.byte 0x0c, 0x00, 0xff, 0xff, 0xff, 0xff, 0x76, 0x01, 0x35, 0x00, 0x0f, 0x00, 0x01, 0x01, 0x00, 0x00
.byte 0x09, 0x00, 0x0c, 0x00, 0x0c, 0x00, 0xff, 0xff, 0xff, 0xff, 0x77, 0x01, 0x13, 0x00, 0x10, 0x00
.byte 0x01, 0x01, 0x00, 0x00, 0x09, 0x00, 0x0c, 0x00, 0x0c, 0x00, 0xff, 0xff, 0xff, 0xff, 0x78, 0x01
.byte 0x14, 0x00, 0x11, 0x00, 0x01, 0x01, 0x00, 0x00, 0x09, 0x00, 0x0c, 0x00, 0x0c, 0x00, 0xff, 0xff
.byte 0xff, 0xff, 0x79, 0x01, 0x15, 0x00, 0x12, 0x00, 0x01, 0x01, 0x00, 0x00, 0x09, 0x00, 0x0c, 0x00
.byte 0x0c, 0x00, 0xff, 0xff, 0xff, 0xff, 0x7a, 0x01, 0x07, 0x00, 0x13, 0x00, 0x01, 0x01, 0x00, 0x00
.byte 0x09, 0x00, 0x0c, 0x00, 0x0c, 0x00, 0xff, 0xff, 0xff, 0xff, 0x7b, 0x01, 0x22, 0x00, 0x14, 0x00
.byte 0x01, 0x01, 0x00, 0x00, 0x09, 0x00, 0x0c, 0x00, 0x0c, 0x00, 0xff, 0xff, 0xff, 0xff, 0x7c, 0x01
.byte 0x25, 0x00, 0x15, 0x00, 0x01, 0x01, 0x00, 0x00, 0x09, 0x00, 0x0c, 0x00, 0x0c, 0x00, 0xff, 0xff
.byte 0xff, 0xff, 0x7d, 0x01, 0x23, 0x00, 0x16, 0x00, 0x01, 0x01, 0x00, 0x00, 0x09, 0x00, 0x0c, 0x00
.byte 0x0c, 0x00, 0xff, 0xff, 0xff, 0xff, 0x7e, 0x01, 0x3c, 0x00, 0x17, 0x00, 0x01, 0x01, 0x00, 0x00
.byte 0x09, 0x00, 0x0c, 0x00, 0x0c, 0x00, 0xff, 0xff, 0xff, 0xff, 0x7f, 0x01, 0x17, 0x00, 0x18, 0x00
.byte 0x01, 0x01, 0x00, 0x00, 0x09, 0x00, 0x0c, 0x00, 0x0c, 0x00, 0xff, 0xff, 0xff, 0xff, 0x80, 0x01
.byte 0x1d, 0x00, 0x19, 0x00, 0x01, 0x01, 0x00, 0x00, 0x09, 0x00, 0x0c, 0x00, 0x0c, 0x00, 0xff, 0xff
.byte 0xff, 0xff, 0x81, 0x01, 0x1c, 0x00, 0x1a, 0x00, 0x01, 0x01, 0x00, 0x00, 0x09, 0x00, 0x0c, 0x00
.byte 0x0c, 0x00, 0xff, 0xff, 0xff, 0xff, 0x82, 0x01, 0x1b, 0x00, 0x1b, 0x00, 0x01, 0x01, 0x00, 0x00
.byte 0x09, 0x00, 0x0c, 0x00, 0x0c, 0x00, 0xff, 0xff, 0xff, 0xff, 0x83, 0x01, 0x1a, 0x00, 0x1c, 0x00
.byte 0x01, 0x01, 0x00, 0x00, 0xc9, 0x00, 0xca, 0x00, 0xc9, 0x00, 0x5a, 0x01, 0x5a, 0x01, 0x84, 0x01
.byte 0x0d, 0x00, 0x1d, 0x00, 0x01, 0x01, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0xca, 0x00, 0xff, 0xff
.byte 0xff, 0xff, 0x84, 0x01, 0x16, 0x00, 0x1d, 0x00, 0x01, 0x01, 0x00, 0x00, 0x09, 0x00, 0x0c, 0x00
.byte 0x0c, 0x00, 0x5e, 0x01, 0x5e, 0x01, 0x85, 0x01, 0x28, 0x00, 0x1e, 0x00, 0x01, 0x01, 0x00, 0x00
.byte 0x09, 0x00, 0x0c, 0x00, 0x0c, 0x00, 0xff, 0xff, 0xff, 0xff, 0x8c, 0x01, 0x1f, 0x00, 0xff, 0xff
.byte 0x01, 0x01, 0x00, 0x00, 0x09, 0x00, 0x0c, 0x00, 0x0c, 0x00, 0xff, 0xff, 0xff, 0xff, 0x8c, 0x01
.byte 0x20, 0x00, 0xff, 0xff, 0x01, 0x01, 0x00, 0x00, 0x09, 0x00, 0x0c, 0x00, 0x0c, 0x00, 0xff, 0xff
.byte 0xff, 0xff, 0x8c, 0x01, 0x21, 0x00, 0xff, 0xff, 0x01, 0x01, 0x00, 0x00, 0x09, 0x00, 0x0c, 0x00
.byte 0x0c, 0x00, 0xff, 0xff, 0xff, 0xff, 0x8c, 0x01, 0x24, 0x00, 0xff, 0xff, 0x01, 0x01, 0x00, 0x00
.byte 0x09, 0x00, 0x0c, 0x00, 0x0c, 0x00, 0xff, 0xff, 0xff, 0xff, 0x8c, 0x01, 0x26, 0x00, 0xff, 0xff
.byte 0x01, 0x01, 0x00, 0x00, 0x09, 0x00, 0x0c, 0x00, 0x0c, 0x00, 0xff, 0xff, 0xff, 0xff, 0x8c, 0x01
.byte 0x29, 0x00, 0xff, 0xff, 0x01, 0x01, 0x00, 0x00, 0x09, 0x00, 0x0c, 0x00, 0x0c, 0x00, 0xff, 0xff
.byte 0xff, 0xff, 0x8c, 0x01, 0x38, 0x00, 0xff, 0xff, 0x01, 0x01, 0x00, 0x00, 0x09, 0x00, 0x0c, 0x00
.byte 0x0c, 0x00, 0xff, 0xff, 0xff, 0xff, 0x8c, 0x01, 0x39, 0x00, 0xff, 0xff, 0x01, 0x01, 0x00, 0x00
.byte 0x09, 0x00, 0x0c, 0x00, 0x0c, 0x00, 0xff, 0xff, 0xff, 0xff, 0x8c, 0x01, 0x3a, 0x00, 0xff, 0xff
.byte 0x01, 0x01, 0x00, 0x00, 0x09, 0x00, 0x0c, 0x00, 0x0c, 0x00, 0xff, 0xff, 0xff, 0xff, 0x8c, 0x01
.byte 0x3b, 0x00, 0xff, 0xff, 0x01, 0x01, 0x00, 0x00, 0x09, 0x00, 0x0c, 0x00, 0x0c, 0x00, 0xff, 0xff
.byte 0xff, 0xff, 0x86, 0x01, 0x3e, 0x00, 0xff, 0xff, 0x01, 0x01, 0x00, 0x00, 0x09, 0x00, 0x0c, 0x00
.byte 0x0c, 0x00, 0xff, 0xff, 0xff, 0xff, 0x87, 0x01, 0x2b, 0x00, 0xff, 0xff, 0x01, 0x01, 0x00, 0x00
.byte 0x09, 0x00, 0x0c, 0x00, 0x0c, 0x00, 0xff, 0xff, 0xff, 0xff, 0x88, 0x01, 0x2c, 0x00, 0xff, 0xff
.byte 0x01, 0x01, 0x00, 0x00, 0x09, 0x00, 0x0c, 0x00, 0x0c, 0x00, 0xff, 0xff, 0xff, 0xff, 0x89, 0x01
.byte 0x2d, 0x00, 0xff, 0xff, 0x01, 0x01, 0x00, 0x00, 0x09, 0x00, 0x0c, 0x00, 0x0c, 0x00, 0xff, 0xff
.byte 0xff, 0xff, 0x8a, 0x01, 0x2e, 0x00, 0xff, 0xff, 0x01, 0x01, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff
.byte 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x8d, 0x01, 0x4b, 0x00, 0xff, 0xff, 0x01, 0x01, 0x00, 0x00
.byte 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x8d, 0x01, 0x4c, 0x00, 0xff, 0xff
.byte 0x01, 0x01, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x8d, 0x01
.byte 0x4d, 0x00, 0xff, 0xff, 0x01, 0x01, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff
.byte 0xff, 0xff, 0x8d, 0x01, 0x4e, 0x00, 0xff, 0xff, 0x01, 0x01, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff
.byte 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x8d, 0x01, 0x4f, 0x00, 0xff, 0xff, 0x01, 0x01, 0x00, 0x00
.byte 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x8d, 0x01, 0x50, 0x00, 0xff, 0xff
.byte 0x01, 0x01, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x8d, 0x01
.byte 0x51, 0x00, 0xff, 0xff, 0x01, 0x01, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff
.byte 0xff, 0xff, 0x8d, 0x01, 0x52, 0x00, 0xff, 0xff, 0x01, 0x01, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff
.byte 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x8d, 0x01, 0x53, 0x00, 0xff, 0xff, 0x01, 0x01, 0x00, 0x00
.byte 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x8d, 0x01, 0x54, 0x00, 0xff, 0xff
.byte 0x01, 0x01, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x8d, 0x01
.byte 0x55, 0x00, 0xff, 0xff, 0x01, 0x01, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff
.byte 0xff, 0xff, 0x8d, 0x01, 0x56, 0x00, 0xff, 0xff, 0x01, 0x01, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff
.byte 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x8d, 0x01, 0x57, 0x00, 0xff, 0xff, 0x01, 0x01, 0x00, 0x00
.byte 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x8d, 0x01, 0x58, 0x00, 0xff, 0xff
.byte 0x01, 0x01, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x8d, 0x01
.byte 0x59, 0x00, 0xff, 0xff, 0x01, 0x01, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff
.byte 0xff, 0xff, 0x8d, 0x01, 0x5a, 0x00, 0xff, 0xff, 0x01, 0x01, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff
.byte 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x8d, 0x01, 0x5b, 0x00, 0xff, 0xff, 0x01, 0x01, 0x00, 0x00
.byte 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x8d, 0x01, 0x5c, 0x00, 0xff, 0xff
.byte 0x01, 0x01, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x8d, 0x01
.byte 0x5d, 0x00, 0xff, 0xff, 0x01, 0x01, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff
.byte 0xff, 0xff, 0x8d, 0x01, 0x5e, 0x00, 0xff, 0xff, 0x01, 0x01, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff
.byte 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x8d, 0x01, 0x5f, 0x00, 0xff, 0xff, 0x01, 0x01, 0x00, 0x00
.byte 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x8d, 0x01, 0x60, 0x00, 0xff, 0xff
.byte 0x01, 0x01, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x8d, 0x01
.byte 0x61, 0x00, 0xff, 0xff, 0x01, 0x01, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff
.byte 0xff, 0xff, 0x8e, 0x01, 0x2f, 0x00, 0xff, 0xff, 0x01, 0x01, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff
.byte 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x8f, 0x01, 0x30, 0x00, 0xff, 0xff, 0x01, 0x01, 0x00, 0x00
.byte 0xff, 0xff, 0x05, 0x00, 0x05, 0x00, 0xff, 0xff, 0xff, 0xff, 0x8b, 0x01, 0x3f, 0x00, 0xff, 0xff
.byte 0x01, 0x00, 0x00, 0x00, 0xff, 0xff, 0x0c, 0x00, 0x0c, 0x00, 0xff, 0xff, 0xff, 0xff, 0x8c, 0x01
.byte 0x3f, 0x00, 0xff, 0xff, 0x01, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff
.byte 0xff, 0xff, 0x8d, 0x01, 0x3f, 0x00, 0xff, 0xff, 0x01, 0x00, 0x00, 0x00

.global gUnknown_8116F24
gUnknown_8116F24: @ 8116F24
@ replacing .incbin "baserom.gba", 0x116F24, 0x76
.byte 0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0x01, 0x00, 0x02, 0x00, 0x03, 0x00, 0x04, 0x00, 0x05, 0x00
.byte 0x06, 0x00, 0xff, 0xff, 0xff, 0xff, 0x07, 0x00, 0x08, 0x00, 0x09, 0x00, 0x0a, 0x00, 0x0b, 0x00
.byte 0x0c, 0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x0d, 0x00, 0x0e, 0x00, 0xff, 0xff
.byte 0x0f, 0x00, 0xff, 0xff, 0x10, 0x00, 0x11, 0x00, 0xff, 0xff, 0x12, 0x00, 0xff, 0xff, 0x13, 0x00
.byte 0x14, 0x00, 0x15, 0x00, 0x16, 0x00, 0x17, 0x00, 0xff, 0xff, 0x18, 0x00, 0xff, 0xff, 0x19, 0x00
.byte 0x1a, 0x00, 0xff, 0xff, 0x1b, 0x00, 0xff, 0xff, 0x1c, 0x00, 0xff, 0xff, 0x1d, 0x00, 0x1e, 0x00
.byte 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00

.global gUnknown_8116F9A
gUnknown_8116F9A: @ 8116F9A
@ replacing .incbin "baserom.gba", 0x116F9A, 0x66
.byte 0x00, 0x00, 0x01, 0x00, 0x02, 0x00, 0x04, 0x00, 0x06, 0x00, 0x07, 0x00, 0x09, 0x00, 0x0a, 0x00
.byte 0x0b, 0x00, 0x0d, 0x00, 0x0f, 0x00, 0x11, 0x00, 0x13, 0x00, 0x15, 0x00, 0x16, 0x00, 0x17, 0x00
.byte 0x18, 0x00, 0x19, 0x00, 0x1a, 0x00, 0x1b, 0x00, 0x1c, 0x00, 0x1d, 0x00, 0x1e, 0x00, 0x1f, 0x00
.byte 0x20, 0x00, 0x21, 0x00, 0x22, 0x00, 0x23, 0x00, 0x24, 0x00, 0x25, 0x00, 0x27, 0x00, 0x28, 0x00
.byte 0x29, 0x00, 0x2a, 0x00, 0x2b, 0x00, 0x2c, 0x00, 0x2d, 0x00, 0x2e, 0x00, 0x2f, 0x00, 0x30, 0x00
.byte 0x31, 0x00, 0x32, 0x00, 0x33, 0x00, 0x34, 0x00, 0x35, 0x00, 0x36, 0x00, 0x00, 0x00, 0x70, 0x6b
.byte 0x73, 0x64, 0x69, 0x72, 0x30, 0x00

.global gUnknown_8117000
gUnknown_8117000: @ 8117000
@ Dungeon Names.. Segments too (i.e Sky Tower and Sky Tower Mid)
.4byte gUnknown_81172A8
.4byte gUnknown_81172A8
.4byte gUnknown_8117298
.4byte gUnknown_8117288
.4byte gUnknown_8117270
.4byte gUnknown_8117270
.4byte gUnknown_8117260
.4byte gUnknown_8117260
.4byte gUnknown_8117250
.4byte gUnknown_8117240
.4byte gUnknown_8117230
.4byte gUnknown_8117230
.4byte gUnknown_8117228
.4byte gUnknown_811721C
.4byte gUnknown_8117208
.4byte gUnknown_81171FC
.4byte gUnknown_81171EC
.4byte gUnknown_81171DC
.4byte gUnknown_81171D0
.4byte gUnknown_81171C0
.4byte gUnknown_81171B0
.4byte gUnknown_8117198
.4byte gUnknown_811718C
.4byte gUnknown_811717C
.4byte gUnknown_8117170
.4byte gUnknown_8117160
.4byte gUnknown_8117150
.4byte gUnknown_8117140
.4byte gUnknown_8117134
.4byte gUnknown_8117124
.4byte gUnknown_8117114
.4byte gUnknown_8117100
.4byte gUnknown_81170F4
.4byte gUnknown_81170E4
.4byte gUnknown_81170D4
.4byte gUnknown_81170C4
.4byte gUnknown_81170B8
.4byte gUnknown_81170AC
.4byte gUnknown_811709C

.global gUnknown_811709C
gUnknown_811709C: @ 811709C
.string "{COLOR_1 RED_2}invalidity{END_COLOR_TEXT_1}\0"
.align 2,0

.global gUnknown_81170AC
gUnknown_81170AC: @ 81170AC
.string "{COLOR_1 YELLOW_3}scene{END_COLOR_TEXT_1}\0"
.align 2,0

.global gUnknown_81170B8
gUnknown_81170B8: @ 81170B8
.string "New Game\0"
.align 2,0

.global gUnknown_81170C4
gUnknown_81170C4: @ 81170C4
.string "{COLOR_1 YELLOW_3}direction{END_COLOR_TEXT_1}\0"
.align 2,0

.global gUnknown_81170D4
gUnknown_81170D4: @ 81170D4
.string "Western Cave\0"
.align 2,0

.global gUnknown_81170E4
gUnknown_81170E4: @ 81170E4
.string "Sky Tower Mid\0"
.align 2,0

.global gUnknown_81170F4
gUnknown_81170F4: @ 81170F4
.string "Sky Tower\0"
.align 2,0

.global gUnknown_8117100
gUnknown_8117100: @ 8117100
.string "Magma Cavern Mid\0"
.align 2,0

.global gUnknown_8117114
gUnknown_8117114: @ 8117114
.string "Magma Cavern\0"
.align 2,0

.global gUnknown_8117124
gUnknown_8117124: @ 8117124
.string "Mt. Freeze Mid\0"
.align 2,0

.global gUnknown_8117134
gUnknown_8117134: @ 8117134
.string "Mt. Freeze\0"
.align 2,0

.global gUnknown_8117140
gUnknown_8117140: @ 8117140
.string "Frosty Clearing\0"
.align 2,0

.global gUnknown_8117150
gUnknown_8117150: @ 8117150
.string "Frosty Forest\0"
.align 2,0

.global gUnknown_8117160
gUnknown_8117160: @ 8117160
.string "Mt. Blaze Mid\0"
.align 2,0

.global gUnknown_8117170
gUnknown_8117170: @ 8117170
.string "Mt. Blaze\0"
.align 2,0

.global gUnknown_811717C
gUnknown_811717C: @ 811717C
.string "Lapis Cave Exit\0"
.align 2,0

.global gUnknown_811718C
gUnknown_811718C: @ 811718C
.string "Lapis Cave\0"
.align 2,0

.global gUnknown_8117198
gUnknown_8117198: @ 8117198
.string "Hill of the Ancients\0"
.align 2,0

.global gUnknown_81171B0
gUnknown_81171B0: @ 81171B0
.string "Great Canyon\0"
.align 2,0

.global gUnknown_81171C0
gUnknown_81171C0: @ 81171C0
.string "Mt. Thunder Mid\0"
.align 2,0

.global gUnknown_81171D0
gUnknown_81171D0: @ 81171D0
.string "Mt. Thunder\0"
.align 2,0

.global gUnknown_81171DC
gUnknown_81171DC: @ 81171DC
.string "Silent Chasm\0"
.align 2,0

.global gUnknown_81171EC
gUnknown_81171EC: @ 81171EC
.string "Sinister Woods\0"
.align 2,0

.global gUnknown_81171FC
gUnknown_81171FC: @ 81171FC
.string "Mt. Steel\0"
.align 2,0

.global gUnknown_8117208
gUnknown_8117208: @ 8117208
.string "Thunderwave Cave\0"
.align 2,0

.global gUnknown_811721C
gUnknown_811721C: @ 811721C
.string "Tiny Woods\0"
.align 2,0

.global gUnknown_8117228
gUnknown_8117228: @ 8117228
.string "Dungeon\0"
.align 2,0

.global gUnknown_8117230
gUnknown_8117230: @ 8117230
.string "$t Team Base\0"
.align 2,0

.global gUnknown_8117240
gUnknown_8117240: @ 8117240
.string "Friend Areas\0"
.align 2,0

.global gUnknown_8117250
gUnknown_8117250: @ 8117250
.string "Luminous Cave\0"
.align 2,0

.global gUnknown_8117260
gUnknown_8117260: @ 8117260
.string "Makuhita Dojo\0"
.align 2,0

.global gUnknown_8117270
gUnknown_8117270: @ 8117270
.string "Pelipper Post Office\0"
.align 2,0

.global gUnknown_8117288
gUnknown_8117288: @ 8117288
.string "Whiscash Pond\0"
.align 2,0

.global gUnknown_8117298
gUnknown_8117298: @ 8117298
.string "Pokémon Square\0"
.align 2,0

.global gUnknown_81172A8
gUnknown_81172A8: @ 81172A8
.string "Square\0"
.align 2,0
.string "pksdir0\0"
.align 2,0

.global gUnknown_81172B8
gUnknown_81172B8: @ 81172B8
.4byte 0x00
.4byte 0x00

.global GroundBGFile_Text
GroundBGFile_Text: @ Text
.string "../ground/ground_bg.c\0"
.align 2,0

.global UncompressCell_Text
UncompressCell_Text: @ Text
.string "_UncompressCell\0"
.align 2,0

.global gUnknown_81172E8
gUnknown_81172E8: @ 81172E8
.4byte GroundBGFile_Text
.byte 0xA0, 0x04, 0x00, 0x00
.4byte UncompressCell_Text

.global gUnknown_81172F4
gUnknown_81172F4: @ 81172F4
@ replacing .incbin "baserom.gba", 0x1172F4, 0x20
.string "GroundBg cell type　error %d %d\0"
.align 2, 0

.global gUnknown_8117314
gUnknown_8117314: @ 8117314
.byte 0x60, 0x00, 0x00, 0x00
.byte 0x18, 0x00, 0x00, 0x00
.string "pksdir0\0"
.align 2,0

.global gUnknown_8117324
gUnknown_8117324: @ 8117324
@ replacing .incbin "baserom.gba", 0x00117324, 0x18
.byte 0x00, 0x00, 0x0d, 0x00, 0x00, 0x00, 0x80, 0x03, 0xb0, 0x04, 0x01, 0x00, 0x01, 0x00, 0xbc, 0x00, 0x5e, 0x00, 0x00, 0x00
.4byte sub_80A5204

.global gUnknown_811733C
gUnknown_811733C: @ 811733C
@ replacing .incbin "baserom.gba", 0x0011733c, 0x18
.byte 0x00, 0x00, 0x0e, 0x00, 0x00, 0x00, 0x00, 0x04, 0xb0, 0x04, 0x00, 0x00, 0x02, 0x00, 0xbc, 0x00, 0x5e, 0x00, 0x00, 0x00
.4byte sub_80A5204

.global gUnknown_8117354
gUnknown_8117354: @ 8117354
@ replacing .incbin "baserom.gba", 0x00117354, 0x18
.byte 0x00, 0x00, 0x0c, 0x00, 0x00, 0x00, 0x00, 0x02, 0xb0, 0x04, 0x01, 0x00, 0x01, 0x00, 0xbc, 0x00, 0x5e, 0x00, 0x00, 0x00
.4byte sub_80A5204

.global gGroundScriptNullCallbacks
gGroundScriptNullCallbacks: @ 811736C
.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00

.global gUnknown_81173C0
gUnknown_81173C0: @ 81173C0
.byte 0xb3, 0x00, 0x00, 0x00, 0x00, 0x64, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xb5, 0x00, 0x00, 0x00, 0x01, 0x64, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xb7, 0x00, 0x00, 0x00, 0x02, 0x64, 0x00, 0x00
.byte 0x00, 0x00, 0x00, 0x00, 0xb9, 0x00, 0x00, 0x00, 0x03, 0x64, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xbb, 0x00, 0x00, 0x00, 0x04, 0x64, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xbd, 0x00, 0x00, 0x00
.byte 0x05, 0x64, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xbe, 0x00, 0x00, 0x00, 0x06, 0x64, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc4, 0x00, 0x00, 0x00, 0x09, 0x64, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.byte 0xc5, 0x00, 0x00, 0x00, 0x0a, 0x64, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc7, 0x00, 0x00, 0x00, 0x0b, 0x64, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc8, 0x00, 0x00, 0x00, 0x0c, 0x64, 0x00, 0x00
.byte 0x00, 0x00, 0x00, 0x00, 0xca, 0x00, 0x00, 0x00, 0x0d, 0x64, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xcb, 0x00, 0x00, 0x00, 0x0e, 0x64, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xcd, 0x00, 0x00, 0x00
.byte 0x0f, 0x64, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xce, 0x00, 0x00, 0x00, 0x10, 0x64, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xd0, 0x00, 0x00, 0x00, 0x11, 0x64, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.byte 0xd1, 0x00, 0x00, 0x00, 0x12, 0x64, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xd2, 0x00, 0x00, 0x00, 0x13, 0x64, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xd3, 0x00, 0x00, 0x00, 0x14, 0x64, 0x00, 0x00
.byte 0x00, 0x00, 0x00, 0x00, 0xd4, 0x00, 0x00, 0x00, 0x22, 0x64, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xd5, 0x00, 0x00, 0x00, 0x25, 0x64, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xd6, 0x00, 0x00, 0x00
.byte 0x23, 0x64, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xd7, 0x00, 0x00, 0x00, 0x3c, 0x64, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xd8, 0x00, 0x00, 0x00, 0x17, 0x64, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.byte 0xd9, 0x00, 0x00, 0x00, 0x1d, 0x64, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xdb, 0x00, 0x00, 0x00, 0x1a, 0x14, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xde, 0x00, 0x00, 0x00, 0x35, 0x64, 0x00, 0x00
.byte 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0x00, 0x00, 0x00, 0x64, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00

.global GroundMap_FileText
GroundMap_FileText: @ 8117510
.string "../ground/ground_map.c\0"
.align 2,0

.global GroundMap_Reset_Text
GroundMap_Reset_Text: @ Reset
.string "GroundMap_Reset\0"
.align 2,0

.global gUnknown_8117538
gUnknown_8117538: @ 8117538
.4byte GroundMap_FileText
.byte 0xf8, 0x00, 0x00, 0x00
.4byte GroundMap_Reset_Text

.global GroundMap_GetStationScript_Text
GroundMap_GetStationScript_Text: @ GetStationScript
.string "GroundMap_GetStationScript\0"
.align 2,0

.global gUnknown_8117560
gUnknown_8117560: @ 8117560
.4byte GroundMap_FileText
.byte 0x38, 0x01, 0x00, 0x00
.4byte GroundMap_GetStationScript_Text

.global gUnknown_811756C
gUnknown_811756C: @ 811756C
.string "GroundMap ExecuteStation %3d %3d %3d\0"
.align 2,0

.global gUnknown_8117594
gUnknown_8117594: @ 8117594
.string "GroundMap ExecuteEvent %3d %d ==================\0"
.align 2,0

.global GroundMap_ExecuteEventText
GroundMap_ExecuteEventText: @ ExecuteEventText
.string "GroundMap_ExecuteEvent\0"
.align 2,0

.global gUnknown_81175E0
gUnknown_81175E0: @ 81175E0
.4byte GroundMap_FileText
.byte 0x7D, 0x01, 0x00, 0x00
.4byte GroundMap_ExecuteEventText

.global gUnknown_81175EC
gUnknown_81175EC: @ 81175EC
.string "GroundMap ExecuteStation %3d %3d %3d %d ==================\0"
.align 2,0

.global GroundMap_ExecuteStationText
GroundMap_ExecuteStationText: @ ExecuteStationText
.string "GroundMap_ExecuteStation\0"
.align 2,0

.global gUnknown_8117644
gUnknown_8117644: @ 8117644
.4byte GroundMap_FileText
.4byte 0x199
.4byte GroundMap_ExecuteStationText

.global gUnknown_8117650
gUnknown_8117650: @ 8117650
.string "GroundMap ExecuteEnter %3d ==================\0"
.align 2,0

.global GroundMap_ExecuteEnterText
GroundMap_ExecuteEnterText: @ ExecuteEnterText
.string "GroundMap_ExecuteEnter\0"
.align 2,0

.global gUnknown_8117698
gUnknown_8117698: @ 8117698
.4byte GroundMap_FileText
.4byte 0x1B3
.4byte GroundMap_ExecuteEnterText

.global gUnknown_81176A4
gUnknown_81176A4: @ 81176A4
.string "GroundMap Select %3d\0"
.align 2,0

.global GroundMap_SelectText
GroundMap_SelectText: @ SelectText
.string "GroundMap_Select\0"
.align 2,0

.global gUnknown_81176D0
gUnknown_81176D0: @ 81176D0
.4byte GroundMap_FileText
.4byte 0x249
.4byte GroundMap_SelectText

.global gUnknown_81176DC
gUnknown_81176DC: @ 81176DC
.string "select map type error %d %d\0"
.align 2,0

.global gUnknown_81176F8
gUnknown_81176F8: @ 81176F8
.4byte 0
.4byte 0

.global gUnknown_8117700
gUnknown_8117700: @ 8117700
.string "GroundMap SelectDungeon %3d\0"
.align 2,0

.global GroundMap_SelectDungeonText
GroundMap_SelectDungeonText: @ SelectDungeonText
.string "GroundMap_SelectDungeon\0"
.align 2,0

.global gUnknown_8117734
gUnknown_8117734: @ 8117734
.4byte GroundMap_FileText
.4byte 0x2C6
.4byte GroundMap_SelectDungeonText

.global gUnknown_8117740
gUnknown_8117740: @ 8117740
.string "map type error %d\0"
.align 2,0

.global gUnknown_8117754
gUnknown_8117754: @ 8117754
.byte 0x00, 0x00, 0x00, 0x00
.byte 0x00, 0x00, 0x00, 0x00

.global GroundMap_Action_Text
GroundMap_Action_Text: @ Action
.string "GroundMap_Action\0"
.align 2,0

.global gUnknown_8117770
gUnknown_8117770: @ 8117770
.4byte GroundMap_FileText
.byte 0x7f, 0x05, 0x00, 0x00
.4byte GroundMap_Action_Text
.string "pksdir0\0"
.align 2,0

.global gUnknown_8117784
gUnknown_8117784: @ 8117784
.byte 0x0d, 0x00, 0x01, 0x00, 0x80, 0x03, 0x80, 0x00, 0x80, 0x00, 0x00, 0x00, 0x01, 0x00, 0xbc, 0x00, 0x5e, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00

.global gGroundWeatherSelect
gGroundWeatherSelect: @ 811779C
.string "GroundWeather Select %3d %3d\0"
.align 2,0

.global gUnknown_81177BC
gUnknown_81177BC: @ 81177BC
.byte 0x00, 0x00, 0x00, 0x00
.byte 0x00, 0x00, 0x00, 0x00
.string "pksdir0\0"

.global gUnknown_81177CC
gUnknown_81177CC: @ 81177CC
.string "etcfonta\0"
.align 2,0

.global gUnknown_81177D8
gUnknown_81177D8: @ 81177D8
.string "GroundSprite Reset\0"
.align 2,0

.global gUnknown_81177EC
gUnknown_81177EC: @ 81177EC
.string "palet\0"
.align 2,0

.global gUnknown_81177F4
gUnknown_81177F4: @ 81177F4
.string "extend palette %3d[%3d] %04x up %04x\0"
.align 2,0

.global GroundSpriteFile_Text
GroundSpriteFile_Text: @ Text
.string "../ground/ground_sprite.c\0"
.align 2,0

.global GroundSprite_ExtendPaletteAdd_Text
GroundSprite_ExtendPaletteAdd_Text: @ ExtendPaletteAdd
.string "GroundSprite_ExtendPaletteAdd\0"
.align 2,0

.global gUnknown_8117858
gUnknown_8117858: @ 8117858
.4byte GroundSpriteFile_Text
.byte 0xF0, 0x03, 0x00, 0x00
.4byte GroundSprite_ExtendPaletteAdd_Text

.global gUnknown_8117864
gUnknown_8117864: @ 8117864
.string "extend palette buffer error %08x\0"
.align 2,0

.global gUnknown_8117888
gUnknown_8117888: @ 8117888
.4byte GroundSpriteFile_Text
.byte 0xF8, 0x03, 0x00, 0x00
.4byte GroundSprite_ExtendPaletteAdd_Text

.global gUnknown_8117894
gUnknown_8117894: @ 8117894
.string "extend palette %3d[%3d] %04x set %04x %04x\0"
.align 2,0

.global gUnknown_81178C0
gUnknown_81178C0: @ 81178C0
.string "extend palette %3d  delete %04x\0"
.align 2,0

.global gUnknown_81178E0
gUnknown_81178E0: @ 81178E0
.byte 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.string "pksdir0\0"
.align 2,0

.global gUnknown_81178F4
gUnknown_81178F4: @ 81178F4
@ replacing .incbin "baserom.gba", 0x1178F4, 0x1F0
.4byte gUnknown_8117ADC
.4byte gUnknown_8117AD4
.4byte gUnknown_8117ACC
.4byte gUnknown_8117AC4
.4byte gUnknown_8117ABC
.4byte gUnknown_8117AB4
.4byte gUnknown_8117AAC
.4byte gUnknown_8117AA4
.4byte gUnknown_8117A9C
.4byte gUnknown_8117A94
.4byte gUnknown_8117A8C
.4byte gUnknown_8117A84
.4byte gUnknown_8117A7C
.4byte gUnknown_8117A74
.4byte gUnknown_8117A6C
.4byte gUnknown_8117A64
.4byte gUnknown_8117A5C
.4byte gUnknown_8117A50
.4byte gUnknown_8117A44
.4byte gUnknown_8117A38
.4byte gUnknown_8117A2C
.4byte gUnknown_8117A20
.4byte gUnknown_8117A14
.4byte gUnknown_8117A08
.4byte gUnknown_81179FC
.4byte gUnknown_81179F0
.4byte gUnknown_81179E4
.4byte gUnknown_81179D8
.4byte gUnknown_81179CC
.4byte gUnknown_81179C0
.4byte gUnknown_81179B4
.4byte gUnknown_81179A8
.4byte gUnknown_811799C
.4byte gUnknown_8117990
.4byte gUnknown_8117984
.byte 0x00, 0x00, 0x00, 0x00

.global gUnknown_8117984
gUnknown_8117984: @ 8117984
.string "stoneimc\0"
.align 2, 0

.global gUnknown_8117990
gUnknown_8117990: @ 8117990
.string "titlebgc\0"
.align 2, 0

.global gUnknown_811799C
gUnknown_811799C: @ 811799C
.string "titleopc\0"
.align 2, 0

.global gUnknown_81179A8
gUnknown_81179A8: @ 81179A8
.string "flag114c\0"
.align 2, 0

.global gUnknown_81179B4
gUnknown_81179B4: @ 81179B4
.string "flag113c\0"
.align 2, 0

.global gUnknown_81179C0
gUnknown_81179C0: @ 81179C0
.string "flag112c\0"
.align 2, 0

.global gUnknown_81179CC
gUnknown_81179CC: @ 81179CC
.string "flag111c\0"
.align 2, 0

.global gUnknown_81179D8
gUnknown_81179D8: @ 81179D8
.string "flag110c\0"
.align 2, 0

.global gUnknown_81179E4
gUnknown_81179E4: @ 81179E4
.string "flag109c\0"
.align 2, 0

.global gUnknown_81179F0
gUnknown_81179F0: @ 81179F0
.string "flag108c\0"
.align 2, 0

.global gUnknown_81179FC
gUnknown_81179FC: @ 81179FC
.string "flag107c\0"
.align 2, 0

.global gUnknown_8117A08
gUnknown_8117A08: @ 8117A08
.string "flag106c\0"
.align 2, 0

.global gUnknown_8117A14
gUnknown_8117A14: @ 8117A14
.string "flag105c\0"
.align 2, 0

.global gUnknown_8117A20
gUnknown_8117A20: @ 8117A20
.string "flag104c\0"
.align 2, 0

.global gUnknown_8117A2C
gUnknown_8117A2C: @ 8117A2C
.string "flag103c\0"
.align 2, 0

.global gUnknown_8117A38
gUnknown_8117A38: @ 8117A38
.string "flag102c\0"
.align 2, 0

.global gUnknown_8117A44
gUnknown_8117A44: @ 8117A44
.string "flag101c\0"
.align 2, 0

.global gUnknown_8117A50
gUnknown_8117A50: @ 8117A50
.string "flag100c\0"
.align 2, 0

.global gUnknown_8117A5C
gUnknown_8117A5C: @ 8117A5C
.string "flag16c\0"
.align 2, 0

.global gUnknown_8117A64
gUnknown_8117A64: @ 8117A64
.string "flag15c\0"
.align 2, 0

.global gUnknown_8117A6C
gUnknown_8117A6C: @ 8117A6C
.string "flag14c\0"
.align 2, 0

.global gUnknown_8117A74
gUnknown_8117A74: @ 8117A74
.string "flag13c\0"
.align 2, 0

.global gUnknown_8117A7C
gUnknown_8117A7C: @ 8117A7C
.string "flag12c\0"
.align 2, 0

.global gUnknown_8117A84
gUnknown_8117A84: @ 8117A84
.string "flag11c\0"
.align 2, 0

.global gUnknown_8117A8C
gUnknown_8117A8C: @ 8117A8C
.string "flag10c\0"
.align 2, 0

.global gUnknown_8117A94
gUnknown_8117A94: @ 8117A94
.string "flag09c\0"
.align 2, 0

.global gUnknown_8117A9C
gUnknown_8117A9C: @ 8117A9C
.string "flag08c\0"
.align 2, 0

.global gUnknown_8117AA4
gUnknown_8117AA4: @ 8117AA4
.string "flag07c\0"
.align 2, 0

.global gUnknown_8117AAC
gUnknown_8117AAC: @ 8117AAC
.string "flag06c\0"
.align 2, 0

.global gUnknown_8117AB4
gUnknown_8117AB4: @ 8117AB4
.string "flag05c\0"
.align 2, 0

.global gUnknown_8117ABC
gUnknown_8117ABC: @ 8117ABC
.string "flag04c\0"
.align 2, 0

.global gUnknown_8117AC4
gUnknown_8117AC4: @ 8117AC4
.string "flag03c\0"
.align 2, 0

.global gUnknown_8117ACC
gUnknown_8117ACC: @ 8117ACC
.string "flag02c\0"
.align 2, 0

.global gUnknown_8117AD4
gUnknown_8117AD4: @ 8117AD4
.string "flag01c\0"
.align 2, 0

.global gUnknown_8117ADC
gUnknown_8117ADC: @ 8117ADC
.string "flag00c\0"
.align 2, 0

.global gGroundObjectKinds
gGroundObjectKinds: @ 8117AE4
@ replacing .incbin "baserom.gba", 0x117AE4, 0x3A8
.byte 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.byte 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.byte 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.byte 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.byte 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.byte 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.byte 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.byte 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.byte 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.byte 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.byte 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.byte 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.byte 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.byte 0x01, 0x00, 0x00, 0x01
.4byte gUnknown_8117E84
.byte 0x01, 0x00, 0x00, 0x01
.4byte gUnknown_8117E84
.byte 0x01, 0x00, 0x01, 0x01
.4byte gUnknown_8117E7C
.byte 0x01, 0x00, 0x02, 0x01
.4byte gUnknown_8117E74
.byte 0x01, 0x00, 0x03, 0x01
.4byte gUnknown_8117E6C
.byte 0x01, 0x00, 0x04, 0x01
.4byte gUnknown_8117E64
.byte 0x01, 0x00, 0x05, 0x01
.4byte gUnknown_8117E5C
.byte 0x01, 0x00, 0x06, 0x01
.4byte gUnknown_8117E54
.byte 0x01, 0x00, 0x07, 0x01
.4byte gUnknown_8117E4C
.byte 0x01, 0x00, 0x08, 0x01
.4byte gUnknown_8117E44
.byte 0x01, 0x00, 0x09, 0x01
.4byte gUnknown_8117E3C
.byte 0x01, 0x00, 0x0a, 0x01
.4byte gUnknown_8117E34
.byte 0x01, 0x00, 0x0b, 0x01
.4byte gUnknown_8117E2C
.byte 0x01, 0x00, 0x0c, 0x01
.4byte gUnknown_8117E24
.byte 0x01, 0x00, 0x0d, 0x01
.4byte gUnknown_8117E1C
.byte 0x01, 0x00, 0x0e, 0x01
.4byte gUnknown_8117E14
.byte 0x01, 0x00, 0x0f, 0x01
.4byte gUnknown_8117E0C
.byte 0x01, 0x00, 0x10, 0x01
.4byte gUnknown_8117E04
.byte 0x01, 0x00, 0x11, 0x01
.4byte gUnknown_8117DF8
.byte 0x01, 0x00, 0x12, 0x01
.4byte gUnknown_8117DEC
.byte 0x01, 0x00, 0x13, 0x01
.4byte gUnknown_8117DE0
.byte 0x01, 0x00, 0x14, 0x01
.4byte gUnknown_8117DD4
.byte 0x01, 0x00, 0x15, 0x01
.4byte gUnknown_8117DC8
.byte 0x01, 0x00, 0x16, 0x01
.4byte gUnknown_8117DBC
.byte 0x01, 0x00, 0x17, 0x01
.4byte gUnknown_8117DB0
.byte 0x01, 0x00, 0x18, 0x01
.4byte gUnknown_8117DA4
.byte 0x01, 0x00, 0x19, 0x01
.4byte gUnknown_8117D98
.byte 0x01, 0x00, 0x1a, 0x01
.4byte gUnknown_8117D8C
.byte 0x01, 0x00, 0x1b, 0x01
.4byte gUnknown_8117D80
.byte 0x01, 0x00, 0x1c, 0x01
.4byte gUnknown_8117D74
.byte 0x01, 0x00, 0x1d, 0x01
.4byte gUnknown_8117D68
.byte 0x01, 0x00, 0x1e, 0x01
.4byte gUnknown_8117D5C
.byte 0x01, 0x00, 0x1f, 0x01
.4byte gUnknown_8117D50
.byte 0x06, 0x00, 0x20, 0x01
.4byte gUnknown_8117D44
.byte 0x01, 0x00, 0x20, 0x01
.4byte gUnknown_8117D38
.byte 0x04, 0x00, 0x21, 0x01
.4byte gUnknown_8117D2C
.byte 0x01, 0x00, 0x06, 0x00
.4byte gUnknown_8117D24
.byte 0x01, 0x00, 0x06, 0x00
.4byte gUnknown_8117D1C
.byte 0x01, 0x00, 0x05, 0x00
.4byte gUnknown_8117D14
.byte 0x01, 0x00, 0x06, 0x00
.4byte gUnknown_8117D0C
.byte 0x01, 0x00, 0x00, 0x00
.4byte gUnknown_8117D04
.byte 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00

.global gUnknown_8117D04
gUnknown_8117D04: @ 8117D04
.string "item01p\0"
.align 2, 0

.global gUnknown_8117D0C
gUnknown_8117D0C: @ 8117D0C
.string "npc04p\0"
.align 2, 0

.global gUnknown_8117D14
gUnknown_8117D14: @ 8117D14
.string "npc03p\0"
.align 2, 0

.global gUnknown_8117D1C
gUnknown_8117D1C: @ 8117D1C
.string "npc02p\0"
.align 2, 0

.global gUnknown_8117D24
gUnknown_8117D24: @ 8117D24
.string "npc01p\0"
.align 2, 0

.global gUnknown_8117D2C
gUnknown_8117D2C: @ 8117D2C
.string "titlebg1\0"
.align 2, 0

.global gUnknown_8117D38
gUnknown_8117D38: @ 8117D38
.string "titleop2\0"
.align 2, 0

.global gUnknown_8117D44
gUnknown_8117D44: @ 8117D44
.string "titleop1\0"
.align 2, 0

.global gUnknown_8117D50
gUnknown_8117D50: @ 8117D50
.string "flag114p\0"
.align 2, 0

.global gUnknown_8117D5C
gUnknown_8117D5C: @ 8117D5C
.string "flag113p\0"
.align 2, 0

.global gUnknown_8117D68
gUnknown_8117D68: @ 8117D68
.string "flag112p\0"
.align 2, 0

.global gUnknown_8117D74
gUnknown_8117D74: @ 8117D74
.string "flag111p\0"
.align 2, 0

.global gUnknown_8117D80
gUnknown_8117D80: @ 8117D80
.string "flag110p\0"
.align 2, 0

.global gUnknown_8117D8C
gUnknown_8117D8C: @ 8117D8C
.string "flag109p\0"
.align 2, 0

.global gUnknown_8117D98
gUnknown_8117D98: @ 8117D98
.string "flag108p\0"
.align 2, 0

.global gUnknown_8117DA4
gUnknown_8117DA4: @ 8117DA4
.string "flag107p\0"
.align 2, 0

.global gUnknown_8117DB0
gUnknown_8117DB0: @ 8117DB0
.string "flag106p\0"
.align 2, 0

.global gUnknown_8117DBC
gUnknown_8117DBC: @ 8117DBC
.string "flag105p\0"
.align 2, 0

.global gUnknown_8117DC8
gUnknown_8117DC8: @ 8117DC8
.string "flag104p\0"
.align 2, 0

.global gUnknown_8117DD4
gUnknown_8117DD4: @ 8117DD4
.string "flag103p\0"
.align 2, 0

.global gUnknown_8117DE0
gUnknown_8117DE0: @ 8117DE0
.string "flag102p\0"
.align 2, 0

.global gUnknown_8117DEC
gUnknown_8117DEC: @ 8117DEC
.string "flag101p\0"
.align 2, 0

.global gUnknown_8117DF8
gUnknown_8117DF8: @ 8117DF8
.string "flag100p\0"
.align 2, 0

.global gUnknown_8117E04
gUnknown_8117E04: @ 8117E04
.string "flag16p\0"
.align 2, 0

.global gUnknown_8117E0C
gUnknown_8117E0C: @ 8117E0C
.string "flag15p\0"
.align 2, 0

.global gUnknown_8117E14
gUnknown_8117E14: @ 8117E14
.string "flag14p\0"
.align 2, 0

.global gUnknown_8117E1C
gUnknown_8117E1C: @ 8117E1C
.string "flag13p\0"
.align 2, 0

.global gUnknown_8117E24
gUnknown_8117E24: @ 8117E24
.string "flag12p\0"
.align 2, 0

.global gUnknown_8117E2C
gUnknown_8117E2C: @ 8117E2C
.string "flag11p\0"
.align 2, 0

.global gUnknown_8117E34
gUnknown_8117E34: @ 8117E34
.string "flag10p\0"
.align 2, 0

.global gUnknown_8117E3C
gUnknown_8117E3C: @ 8117E3C
.string "flag09p\0"
.align 2, 0

.global gUnknown_8117E44
gUnknown_8117E44: @ 8117E44
.string "flag08p\0"
.align 2, 0

.global gUnknown_8117E4C
gUnknown_8117E4C: @ 8117E4C
.string "flag07p\0"
.align 2, 0

.global gUnknown_8117E54
gUnknown_8117E54: @ 8117E54
.string "flag06p\0"
.align 2, 0

.global gUnknown_8117E5C
gUnknown_8117E5C: @ 8117E5C
.string "flag05p\0"
.align 2, 0

.global gUnknown_8117E64
gUnknown_8117E64: @ 8117E64
.string "flag04p\0"
.align 2, 0

.global gUnknown_8117E6C
gUnknown_8117E6C: @ 8117E6C
.string "flag03p\0"
.align 2, 0

.global gUnknown_8117E74
gUnknown_8117E74: @ 8117E74
.string "flag02p\0"
.align 2, 0

.global gUnknown_8117E7C
gUnknown_8117E7C: @ 8117E7C
.string "flag01p\0"
.align 2, 0

.global gUnknown_8117E84
gUnknown_8117E84: @ 8117E84
.string "flag00p\0"
.align 2, 0

.global gUnknown_8117E8C
gUnknown_8117E8C: @ 8117E8C
@ replacing .incbin "baserom.gba", 0x117E8C, 0x50
.byte 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.byte 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.byte 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.byte 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.byte 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x70, 0x6b, 0x73, 0x64, 0x69, 0x72, 0x30, 0x00

.global gUnknown_8117EDC
gUnknown_8117EDC: @ 8117EDC
.string "ax%03d\0"
.align 2,0
.string "pksdir0\0"
.align 2,0
.string "pksdir0\0"
.align 2,0
.string "pksdir0\0"
.align 2,0

.global gNullGroundScript
gNullGroundScript: @ 8117EFC
.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.string "pksdir0\0"
.align 2,0

.global gGroundLivesCallbacks
gGroundLivesCallbacks: @ 8117F10
.byte 0x01, 0x00, 0x00, 0x00
.4byte CallbackLivesGetIndex
.4byte CallbackLivesGetSize
.4byte CallbackLivesGetHitboxCenter
.4byte CallbackLivesGetPosHeightAndUnk
.4byte CallbackLivesGetDirection
.4byte CallbackLivesGetFlags
.4byte CallbackLivesSetHitboxPos
.4byte CallbackLivesSetPositionBounds
.4byte CallbackLivesMoveReal
.4byte CallbackLivesSetPosHeight
.4byte CallbackLivesSetDirection
.4byte CallbackLivesSetEventIndex
.4byte nullsub_211
.4byte CallbackLivesSetUnk_80AB194
.4byte CallbackLivesSetFlags
.4byte CallbackLivesClearFlags
.4byte CallbackLivesSpriteRelated_80AB238
.4byte CallbackLivesMoveRelative
.4byte CallbackLivesSpriteRelatedCheck_80AB1C0
.4byte CallbackLivesSpriteRelated_80AB1E4

.global gUnknown_8117F64
gUnknown_8117F64: @ 8117F64
@ replacing .incbin "baserom.gba", 0x117F64, 0x6A
.byte 0xff, 0xff, 0x00, 0x08, 0x00, 0x03, 0x00, 0x03, 0x07, 0x08, 0x00, 0x08, 0x05, 0x08, 0x02, 0x03
.byte 0x06, 0x03, 0x0b, 0x08, 0x07, 0x03, 0x06, 0x10, 0x02, 0x10, 0x01, 0x10, 0x08, 0x10, 0x0c, 0x10
.byte 0x09, 0x10, 0x0a, 0x10, 0x03, 0x10, 0x04, 0x10, 0x03, 0x08, 0x04, 0x08, 0x0d, 0x10, 0x0e, 0x10
.byte 0x0f, 0x10, 0x10, 0x10, 0x11, 0x10, 0x12, 0x10, 0x13, 0x10, 0x14, 0x10, 0x0d, 0x08, 0x0e, 0x08
.byte 0x0f, 0x08, 0x10, 0x08, 0x11, 0x08, 0x12, 0x08, 0x13, 0x08, 0x14, 0x08, 0x0d, 0x08, 0x0e, 0x10
.byte 0x0f, 0x10, 0x10, 0x10, 0x11, 0x10, 0x12, 0x08, 0x13, 0x10, 0x14, 0x10, 0x15, 0x10, 0x16, 0x10
.byte 0x17, 0x10, 0x18, 0x08, 0x19, 0x10, 0x1a, 0x08, 0x1b, 0x08

.global gUnknown_8117FCE
gUnknown_8117FCE: @ 8117FCE
@ replacing .incbin "baserom.gba", 0x117FCE, 0x22
.byte 0x19, 0x00, 0x34, 0x00, 0x85, 0x00, 0x45, 0x01, 0x07, 0x00, 0x9e, 0x00, 0x1b, 0x01, 0x36, 0x00
.byte 0x04, 0x00, 0x18, 0x01, 0x9b, 0x00, 0x68, 0x00, 0x42, 0x00, 0x01, 0x00, 0x98, 0x00, 0x15, 0x01
.byte 0x00, 0x00

.global gUnknown_8117FF0
gUnknown_8117FF0: @ 8117FF0
@ replacing .incbin "baserom.gba", 0x117FF0, 0x20
.byte 0x00, 0x06, 0x00, 0x00, 0x41, 0x04, 0x00, 0x00, 0x00, 0x06, 0x00, 0x00, 0x41, 0x04, 0x00, 0x00
.byte 0x00, 0x06, 0x00, 0x00, 0x41, 0x04, 0x00, 0x00, 0x00, 0x06, 0x00, 0x00, 0x41, 0x04, 0x00, 0x00

.global gUnknown_8118010
gUnknown_8118010: @ 8118010
@ replacing .incbin "baserom.gba", 0x118010, 0x20
.byte 0x00, 0x20, 0x00, 0x00, 0xb1, 0x16, 0x00, 0x00, 0x00, 0x20, 0x00, 0x00, 0xb1, 0x16, 0x00, 0x00
.byte 0x00, 0x20, 0x00, 0x00, 0xb1, 0x16, 0x00, 0x00, 0x00, 0x20, 0x00, 0x00, 0xb1, 0x16, 0x00, 0x00

.global gUnknown_8118030
gUnknown_8118030: @ 8118030
@ replacing .incbin "baserom.gba", 0x118030, 0x20
.byte 0x00, 0x08, 0x00, 0x00, 0xac, 0x05, 0x00, 0x00, 0x00, 0x08, 0x00, 0x00, 0xac, 0x05, 0x00, 0x00
.byte 0x00, 0x08, 0x00, 0x00, 0xac, 0x05, 0x00, 0x00, 0x00, 0x08, 0x00, 0x00, 0xac, 0x05, 0x00, 0x00

.global gUnknown_8118050
gUnknown_8118050: @ 8118050
.byte 0x00, 0x14, 0x00, 0x00
.byte 0x00, 0x14, 0x00, 0x00
.byte 0x00, 0x18, 0x00, 0x00

.global GroundLivesFile_Text
GroundLivesFile_Text: @ Text
.string "../ground/ground_lives.c\0"
.align 2,0

.global GroundLives_Select_Text
GroundLives_Text: @ Text
.string "GroundLives_Select\0"
.align 2,0

.global gUnknown_811808C
gUnknown_811808C: @ 811808C
.4byte GroundLivesFile_Text
.byte 0x1E, 0x02, 0x00, 0x00
.4byte GroundLives_Text

.global gUnknown_8118098
gUnknown_8118098: @ 8118098
.string "GroundLives Select %3d  %3d  %3d\0"
.align 2,0

.global gUnknown_81180BC
gUnknown_81180BC: @ 81180BC
.string "GroundLives Cancel %3d  %3d\0"
.align 2,0

.global gUnknown_81180D8
gUnknown_81180D8: @ 81180D8
.string "GroundLives CancelBlank\0"
.align 2,0

.global gUnknown_81180F0
gUnknown_81180F0: @ 81180F0
.byte 0x5F, 0x00
.byte 0x22, 0x00
.byte 0x10, 0x00
.byte 0x13, 0x00
.byte 0x1B, 0x00
.byte 0x29, 0x00

.global gUnknown_81180FC
gUnknown_81180FC: @ 81180FC
@ replacing .incbin "baserom.gba", 0x1180FC, 0x20
.byte 0x19, 0x00, 0x34, 0x00, 0x85, 0x00, 0x45, 0x01, 0x07, 0x00, 0x9e, 0x00, 0x1b, 0x01, 0x36, 0x00
.byte 0x04, 0x00, 0x18, 0x01, 0x9b, 0x00, 0x68, 0x00, 0x42, 0x00, 0x01, 0x00, 0x98, 0x00, 0x15, 0x01

.global gUnknown_811811C
gUnknown_811811C: @ 811811C
.string "GroundLive Add id %3d  kind %3d  type %3d  group %3d  sector %3d\0"
.align 2,0

.global GroundLives_Add_Text
GroundLives_Add_Text: @ Add
.string "GroundLives_Add\0"
.align 2,0

.global gUnknown_8118170
gUnknown_8118170: @ 8118170
.4byte GroundLivesFile_Text
.byte 0x89, 0x05, 0x00, 0x00
.4byte GroundLives_Add_Text

.global gUnknown_811817C
gUnknown_811817C: @ 811817C
.4byte GroundLivesFile_Text
.byte 0xb4, 0x05, 0x00, 0x00
.4byte GroundLives_Add_Text

.global gUnknown_8118188
gUnknown_8118188: @ 8118188
.4byte GroundLivesFile_Text
.byte 0xba, 0x05, 0x00, 0x00
.4byte GroundLives_Add_Text

.global gUnknown_8118194
gUnknown_8118194: @ 8118194
.string "GroundLives Delete id %3d\0"
.align 2,0

.global gUnknown_81181B0
gUnknown_81181B0: @ 81181B0
.string "GroundLives Execute %3d  kind %3d  %p\0"
.align 2,0

.global GroundLives_ExecuteScript_Text
GroundLives_ExecuteScript_Text: @ ExecuteScript
.string "GroundLives_ExecuteScript\0"
.align 2,0

.global gUnknown_81181F4
gUnknown_81181F4: @ 81181F4
.4byte GroundLivesFile_Text
.byte 0xa7, 0x06, 0x00, 0x00
.4byte GroundLives_ExecuteScript_Text

.global ExecutePlayerScript_Text
ExecutePlayerScript_Text: @ Text
.string "_ExecutePlayerScript\0"
.align 2,0

.global gUnknown_8118218
gUnknown_8118218: @ 8118218
.4byte GroundLivesFile_Text
.byte 0xC8, 0x06, 0x00, 0x00
.4byte ExecutePlayerScript_Text

.global ExecutePlayerScriptActionLives_Text
ExecutePlayerScriptActionLives_Text: @ Text
.string "GroundLives_ExecutePlayerScriptActionLives\0"
.align 2,0

.global gUnknown_8118250
gUnknown_8118250: @ 8118250
.4byte GroundLivesFile_Text
.byte 0xF9, 0x06, 0x00, 0x00
.4byte ExecutePlayerScriptActionLives_Text

.global gGroundLives_InvalidityText
gGroundLives_InvalidityText: @ 811825C
.string "{COLOR_1 RED_2}invalidity{END_COLOR_TEXT_1}\0"
.align 2,0

.global GroundLives_ActionText
GroundLives_ActionText: @ ActionText
.string "GroundLives_Action\0"
.align 2,0

.global gUnknown_8118280
gUnknown_8118280: @ 8118280
.4byte GroundLivesFile_Text
.byte 0xA2, 0x11, 0x00, 0x00
.4byte GroundLives_ActionText

.global gUnknown_811828C
gUnknown_811828C: @ 811828C
.4byte GroundLivesFile_Text
.byte 0x0E, 0x12, 0x00, 0x00
.4byte GroundLives_ActionText
.string "pksdir0\0"
.align 2,0

.global gGroundObjectCallbacks
gGroundObjectCallbacks: @ 81182A0
@ replacing .incbin "baserom.gba", 0x1182A0, 0x54
.byte 0x02, 0x00, 0x00, 0x00
.4byte CallbackObjectGetIndex
.4byte CallbackObjectGetSize
.4byte CallbackObjectGetHitboxCenter
.4byte CallbackObjectGetPosHeightAndUnk
.4byte CallbackObjectGetDirection
.4byte CallbackObjectGetFlags
.4byte CallbackObjectSetHitboxPos
.4byte CallbackObjectSetPositionBounds
.4byte CallbackObjectMoveReal
.4byte CallbackObjectSetPosHeight
.4byte CallbackObjectSetDirection
.4byte CallbackObjectSetEventIndex
.byte 0x00, 0x00, 0x00, 0x00
.4byte CallbackObjectSetUnk_80AC998
.4byte CallbackObjectSetFlags
.4byte CallbackObjectClearFlags
.byte 0x00, 0x00, 0x00, 0x00
.4byte CallbackObjectMoveRelative
.4byte CallbackObjectSpriteRelatedCheck_80AC9B8
.4byte CallbackObjectSpriteRelated_80AC9DC

.global gUnknown_81182F4
gUnknown_81182F4: @ 81182F4
.byte 0xF6,  0x0, 0x9F,  0x0, 0x0,  0x0,  0x0,  0x0, 0x0,  0x0,  0x0,  0x0, 0x34, 0x83, 0x11,  0x8, 0xF4,  0x0,  0x0,  0x0, 0x0,  0x0,  0x0,  0x0, 0x0,  0x0,  0x0,  0x0, 0x0,  0x0,  0x0,  0x0, 0xDB,  0x0, 0x78,  0x0, 0x0,  0x0,  0x0,  0x0, 0x0,  0x0,  0x0,  0x0, 0x0,  0x0,  0x0,  0x0, 0xE7,  0x0,  0x0,  0x0, 0x0,  0x0,  0x0,  0x0, 0x0,  0x0,  0x0,  0x0, 0x0,  0x0,  0x0,  0x0

.global GroundObjectFile_Text
GroundObjectFile_Text: @ Text

.global gUnknown_8118334
gUnknown_8118334: @ 8118334
.string "../ground/ground_object.c"
.align 2,0

.global gUnknown_8118350
gUnknown_8118350: @ 8118350
@ replacing .incbin "baserom.gba", 0x118350, 0x50
.byte 0xf6, 0x00, 0xa6, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.4byte gUnknown_8118334
.byte 0x54, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.byte 0xf4, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.byte 0xdb, 0x00, 0x78, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.byte 0xe7, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00

.global gUnknown_81183A0
gUnknown_81183A0: @ 81183A0
.byte 0xFF, 0xFF,  0x0,  0x8, 0x1,  0x8,  0x0, 0x10, 0x1, 0x10,  0x2, 0x10, 0x3, 0x10,  0x0,  0x8, 0x1,  0x8,  0x2,  0x8, 0x3,  0x8,  0x4,  0x8, 0x5,  0x8,  0x6,  0x8, 0x7,  0x8,  0x8,  0x8, 0x9,  0x8,  0xA,  0x8, 0xB,  0x8,  0xC,  0x8, 0xD,  0x8,  0xE,  0x8, 0xF,  0x8,  0x0,  0x0

.global GroundObject_Select_Text
GroundObject_Select_Text: @ Select
.string "GroundObject_Select"
.align 2,0

.global gUnknown_81183E4
gUnknown_81183E4: @ 81183E4
.4byte GroundObjectFile_Text
.4byte 0x126
.4byte GroundObject_Select_Text

.global gUnknown_81183F0
gUnknown_81183F0: @ 81183F0
.string "GroundObject Select %3d  %3d  %3d\0"
.align 2,0

.global gUnknown_8118414
gUnknown_8118414: @ 8118414
.string "GroundObject Cancel %3d\0"
.align 2,0

.global gUnknown_811842C
gUnknown_811842C: @ 811842C
.string "GroundObject CancelBlank\0"
.align 2,0

.global gUnknown_8118448
gUnknown_8118448: @ 8118448
.string "GroundObject Add id %3d  kind %3d[%3d]  type %3d  group %3d  sector %3d\0"
.align 2,0

.global GroundObject_AddText
GroundObject_AddText: @ AddText
.string "GroundObject_Add\0"
.align 2,0

.global gUnknown_81184A4
gUnknown_81184A4: @ 81184A4
.4byte GroundObjectFile_Text
.4byte 0x283
.4byte GroundObject_AddText

.global gUnknown_81184B0
gUnknown_81184B0: @ 81184B0
.string "GroundObject Delete id %3d\0"
.align 2,0

.global gUnknown_81184CC
gUnknown_81184CC: @ 81184CC
.string "GroundObject Execute %3d  \0"
.align 2,0

.global GroundObject_ExecuteScript_Text
GroundObject_ExecuteScript_Text: @ ExecuteScript
.string "GroundObject_ExecuteScript\0"
.align 2,0

.global gUnknown_8118504
gUnknown_8118504: @ 8118504
.4byte GroundObjectFile_Text
.4byte 0x303
.4byte GroundObject_ExecuteScript_Text

.global GroundObject_Action_Text
GroundObject_Action_Text: @ Action
.string "GroundObject_Action\0"
.align 2,0

.global gUnknown_8118524
gUnknown_8118524: @ 8118524
.4byte GroundObjectFile_Text
.4byte 0x60D
.4byte GroundObject_Action_Text

.global gUnknown_8118530
gUnknown_8118530: @ 8118530
.4byte GroundObjectFile_Text
.4byte 0x617
.4byte GroundObject_Action_Text
.string "pksdir0\0"
.align 2,0

.global gGroundEffectCallbacks
gGroundEffectCallbacks: @ 8118544
@ replacing .incbin "baserom.gba", 0x118544, 0xAE
.byte 0x03, 0x00, 0x00, 0x00
.4byte CallbackEffectGetIndex
.4byte CallbackEffectGetSize
.4byte CallbackEffectGetHitboxCenter
.4byte CallbackEffectGetPosHeightAndUnk
.4byte CallbackEffectGetDirection
.4byte CallbackEffectGetFlags
.4byte CallbackEffectSetHitboxPos
.4byte CallbackEffectSetPositionBounds
.4byte CallbackEffectMoveReal
.4byte CallbackEffectSetPosHeight
.4byte CallbackEffectSetDirection
.4byte CallbackEffectSetEventIndex
.byte 0x00, 0x00, 0x00, 0x00
.4byte CallbackEffectSetUnk_80AD670
.4byte CallbackEffectSetFlags
.4byte CallbackEffectClearFlags
.byte 0x00, 0x00, 0x00, 0x00
.4byte CallbackEffectMoveRelative
.4byte CallbackEffectSpriteRelatedCheck_80AD690
.4byte CallbackEffectSpriteRelated_80AD6B4
.byte 0xf6, 0x00, 0x9b, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.4byte gUnknown_81185D8
.byte 0xf4, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.byte 0x00, 0x00, 0x00, 0x00, 0xdb, 0x00, 0x78, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.byte 0x00, 0x00, 0x00, 0x00, 0xe7, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.byte 0x00, 0x00, 0x00, 0x00

.global gUnknown_81185D8
gUnknown_81185D8: @ 81185D8
.string "../ground/ground_effect.c\0"

.global gUnknown_81185F2
gUnknown_81185F2: @ 81185F2
@ replacing .incbin "baserom.gba", 0x1185F2, 0x1E
.byte 0xff, 0xff, 0x00, 0x08, 0x01, 0x08, 0x00, 0x10, 0x00, 0x00

.global gUnknown_81185FC
gUnknown_81185FC: @ 81185FC
.string "GroundEffect_Select\0"
.align 2, 0

.global gUnknown_8118610
gUnknown_8118610: @ 8118610
.4byte gUnknown_81185D8
.4byte 0x106
.4byte gUnknown_81185FC

.global gUnknown_811861C
gUnknown_811861C: @ 811861C
.string "GroundEffect Select %3d  %3d  %3d"
.align 2,0

.global gUnknown_8118640
gUnknown_8118640: @ 8118640
.string "GroundEffect Cancel %3d"
.align 2,0

.global gUnknown_8118658
gUnknown_8118658: @ 8118658
.string "GroundEffect CancelBlank\0"
.align 2,0

.global gUnknown_8118674
gUnknown_8118674: @ 8118674
@ replacing .incbin "baserom.gba", 0x118674, 0x58
.string "GroundEffect Add id %3d  kind %3d  type %3d  group %3d  sector %3d\0"
.align 2, 0

.global gUnknown_81186B8
gUnknown_81186B8: @ 81186B8
.string "GroundEffect_Add\0"
.align 2, 0

.global gUnknown_81186CC
gUnknown_81186CC: @ 81186CC
@ replacing .incbin "baserom.gba", 0x1186CC, 0xC
.4byte gUnknown_81185D8
.byte 0x10, 0x02, 0x00, 0x00
.4byte gUnknown_81186B8

.global gUnknown_81186D8
gUnknown_81186D8: @ 81186D8
.string "GroundEffect Delete id %3d"
.align 2,0

.global gUnknown_81186F4
gUnknown_81186F4: @ 81186F4
.string "GroundEffect Execute %3d  "
.align 2,0

.global GroundEffect_ExecuteScript_Text
GroundEffect_ExecuteScript_Text: @ ExecuteScript
.string "GroundEffect_ExecuteScript"
.align 2,0

.global gUnknown_811872C
gUnknown_811872C: @ 811872C
.4byte gUnknown_81185D8
.4byte 0x290
.4byte GroundEffect_ExecuteScript_Text

.global GroundEffect_Action_Text
GroundEffect_Action_Text: @ Action
.string "GroundEffect_Action\0"
.align 2,0

.global gUnknown_811874C
gUnknown_811874C: @ 811874C
.4byte gUnknown_81185D8
.4byte 0x560
.4byte GroundEffect_Action_Text

.global gUnknown_8118758
gUnknown_8118758: @ 8118758
.4byte gUnknown_81185D8
.4byte 0x56A
.4byte GroundEffect_Action_Text
.string "pksdir0\0"
.align 2,0
@ Ground Link

.global GroundLink_FileText
GroundLink_FileText: @ FileText
.string "../ground/ground_link.c\0"
.align 2,0

.global GroundLink_SelectText
GroundLink_SelectText: @ SelectText
.string "GroundLink_Select\0"
.align 2,0

.global gUnknown_8118798
gUnknown_8118798: @ 8118798
.4byte GroundLink_FileText
.byte 0x4D, 0x00, 0x00, 0x00
.4byte GroundLink_SelectText
.string "pksdir0\0"
@ Ground Event

.global GroundEventFile_Text
GroundEventFile_Text: @ Text
.string "../ground/ground_event.c\0"
.align 2,0

.global GroundEvent_Select_Text
GroundEvent_Select_Text: @ Select
.string "GroundEvent_Select\0"
.align 2,0

.global gUnknown_81187DC
gUnknown_81187DC: @ 81187DC
.4byte GroundEventFile_Text
.4byte 0xA0
.4byte GroundEvent_Select_Text

.global gGroundEventSelectText
gGroundEventSelectText: @ 81187E8
.string "GroundEvent Select %3d  %3d  %3d\0"
.align 2,0

.global gGroundEventCancelText
gGroundEventCancelText: @ 811880C
.string "GroundEvent Cancel %3d  %3d\0"
.align 2,0

.global gGroundEventAddText
gGroundEventAddText: @ 8118828
.string "GroundEvent Add id %3d  kind %3d  group %3d  sector %3d  script %p\0"
.align 2,0

.global gGroundEventDeleteText
gGroundEventDeleteText: @ 811886C
.string "GroundEvent Delete id %3d\0"
.align 2,0
.string "pksdir0\0"
.align 2,0

.global gMapparamText
gMapparamText: @ 8118890
.string "mapparam\0"
.align 2,0

.global gUnknown_811889C
gUnknown_811889C: @ 811889C
.string "b%02dfon\0"
.align 2,0

.global gUnknown_81188A8
gUnknown_81188A8: @ 81188A8
.string "b%02dpal\0"
.align 2,0

.global gUnknown_81188B4
gUnknown_81188B4: @ 81188B4
.string "b%02dcel\0"
.align 2,0

.global gUnknown_81188C0
gUnknown_81188C0: @ 81188C0
.string "b%02dcex\0"
.align 2,0

.global gUnknown_81188CC
gUnknown_81188CC: @ 81188CC
.string "b%02demap%01d\0"
.align 2,0

.global gUnknown_81188DC
gUnknown_81188DC: @ 81188DC
.string "b%02dcanm\0"
.align 2,0
.string "pksdir0\0"
.align 2,0

.global gUnknown_81188F0
gUnknown_81188F0: @ 81188F0
@ replacing .incbin "baserom.gba", 0x001188f0, 0x3204
.4byte gUnknown_811BAE4
.4byte gUnknown_811BADC
.4byte gUnknown_811BAD4
.byte 0x00, 0x00, 0x00, 0x00
.byte 0x00, 0x00, 0x00, 0x00
.byte 0x00, 0x00, 0x00, 0x00
.byte 0x00, 0x00, 0x00, 0x00
.4byte gUnknown_811BACC
.4byte gUnknown_811BAC4
.4byte gUnknown_811BABC
.4byte gUnknown_811BAB4
.byte 0x00, 0x00, 0x00, 0x00
.byte 0x00, 0x00, 0x00, 0x00
.byte 0x00, 0x00, 0x00, 0x00
.4byte gUnknown_811BAAC
.4byte gUnknown_811BAA4
.4byte gUnknown_811BA98
.4byte gUnknown_811BA90
.byte 0x00, 0x00, 0x00, 0x00
.byte 0x00, 0x00, 0x00, 0x00
.byte 0x00, 0x00, 0x00, 0x00
.4byte gUnknown_811BA88
.4byte gUnknown_811BAA4
.4byte gUnknown_811BA7C
.4byte gUnknown_811BA90
.byte 0x00, 0x00, 0x00, 0x00
.byte 0x00, 0x00, 0x00, 0x00
.byte 0x00, 0x00, 0x00, 0x00
.4byte gUnknown_811BA74
.4byte gUnknown_811BA6C
.4byte gUnknown_811BA64
.4byte gUnknown_811BA5C
.byte 0x00, 0x00, 0x00, 0x00
.byte 0x00, 0x00, 0x00, 0x00
.byte 0x00, 0x00, 0x00, 0x00
.4byte gUnknown_811BA54
.4byte gUnknown_811BA4C
.4byte gUnknown_811BA44
.byte 0x00, 0x00, 0x00, 0x00
.byte 0x00, 0x00, 0x00, 0x00
.byte 0x00, 0x00, 0x00, 0x00
.byte 0x00, 0x00, 0x00, 0x00
.4byte gUnknown_811BA3C
.4byte gUnknown_811BA34
.4byte gUnknown_811BA2C
.4byte gUnknown_811BA24
.byte 0x00, 0x00, 0x00, 0x00
.byte 0x00, 0x00, 0x00, 0x00
.byte 0x00, 0x00, 0x00, 0x00
.4byte gUnknown_811BA1C
.4byte gUnknown_811BA14
.4byte gUnknown_811BA0C
.byte 0x00, 0x00, 0x00, 0x00
.byte 0x00, 0x00, 0x00, 0x00
.byte 0x00, 0x00, 0x00, 0x00
.byte 0x00, 0x00, 0x00, 0x00
.4byte gUnknown_811BA04
.4byte gUnknown_811B9FC
.4byte gUnknown_811B9F4
.byte 0x00, 0x00, 0x00, 0x00
.byte 0x00, 0x00, 0x00, 0x00
.byte 0x00, 0x00, 0x00, 0x00
.byte 0x00, 0x00, 0x00, 0x00
.4byte gUnknown_811B9EC
.4byte gUnknown_811B9E0
.4byte gUnknown_811B9D4
.byte 0x00, 0x00, 0x00, 0x00
.byte 0x00, 0x00, 0x00, 0x00
.byte 0x00, 0x00, 0x00, 0x00
.byte 0x00, 0x00, 0x00, 0x00
.4byte gUnknown_811B9CC
.4byte gUnknown_811B9C0
.4byte gUnknown_811B9B4
.4byte gUnknown_811B9A8
.byte 0x00, 0x00, 0x00, 0x00
.byte 0x00, 0x00, 0x00, 0x00
.byte 0x00, 0x00, 0x00, 0x00
.4byte gUnknown_811B9A0
.4byte gUnknown_811B994
.4byte gUnknown_811B988
.4byte gUnknown_811B97C
.byte 0x00, 0x00, 0x00, 0x00
.4byte gUnknown_811B970
.byte 0x00, 0x00, 0x00, 0x00
.4byte gUnknown_811B968
.4byte gUnknown_811B95C
.4byte gUnknown_811B950
.4byte gUnknown_811B944
.byte 0x00, 0x00, 0x00, 0x00
.byte 0x00, 0x00, 0x00, 0x00
.byte 0x00, 0x00, 0x00, 0x00
.4byte gUnknown_811B93C
.4byte gUnknown_811B934
.4byte gUnknown_811B928
.byte 0x00, 0x00, 0x00, 0x00
.byte 0x00, 0x00, 0x00, 0x00
.byte 0x00, 0x00, 0x00, 0x00
.byte 0x00, 0x00, 0x00, 0x00
.4byte gUnknown_811B920
.4byte gUnknown_811B934
.4byte gUnknown_811B914
.byte 0x00, 0x00, 0x00, 0x00
.byte 0x00, 0x00, 0x00, 0x00
.byte 0x00, 0x00, 0x00, 0x00
.byte 0x00, 0x00, 0x00, 0x00
.4byte gUnknown_811B90C
.4byte gUnknown_811B900
.4byte gUnknown_811B8F4
.byte 0x00, 0x00, 0x00, 0x00
.byte 0x00, 0x00, 0x00, 0x00
.byte 0x00, 0x00, 0x00, 0x00
.byte 0x00, 0x00, 0x00, 0x00
.4byte gUnknown_811B8EC
.4byte gUnknown_811B9C0
.4byte gUnknown_811B9B4
.4byte gUnknown_811B9A8
.byte 0x00, 0x00, 0x00, 0x00
.byte 0x00, 0x00, 0x00, 0x00
.byte 0x00, 0x00, 0x00, 0x00
.4byte gUnknown_811B8E4
.4byte gUnknown_811B994
.4byte gUnknown_811B988
.4byte gUnknown_811B97C
.byte 0x00, 0x00, 0x00, 0x00
.4byte gUnknown_811B8D8
.byte 0x00, 0x00, 0x00, 0x00
.4byte gUnknown_811B8D0
.4byte gUnknown_811B8C4
.4byte gUnknown_811B8B8
.4byte gUnknown_811B8AC
.byte 0x00, 0x00, 0x00, 0x00
.byte 0x00, 0x00, 0x00, 0x00
.byte 0x00, 0x00, 0x00, 0x00
.4byte gUnknown_811B8A4
.4byte gUnknown_811B934
.4byte gUnknown_811B928
.byte 0x00, 0x00, 0x00, 0x00
.byte 0x00, 0x00, 0x00, 0x00
.byte 0x00, 0x00, 0x00, 0x00
.byte 0x00, 0x00, 0x00, 0x00
.4byte gUnknown_811B89C
.4byte gUnknown_811B934
.4byte gUnknown_811B914
.byte 0x00, 0x00, 0x00, 0x00
.byte 0x00, 0x00, 0x00, 0x00
.byte 0x00, 0x00, 0x00, 0x00
.byte 0x00, 0x00, 0x00, 0x00
.4byte gUnknown_811B894
.4byte gUnknown_811B900
.4byte gUnknown_811B8F4
.byte 0x00, 0x00, 0x00, 0x00
.byte 0x00, 0x00, 0x00, 0x00
.byte 0x00, 0x00, 0x00, 0x00
.byte 0x00, 0x00, 0x00, 0x00
.4byte gUnknown_811B88C
.4byte gUnknown_811B9C0
.4byte gUnknown_811B9B4
.4byte gUnknown_811B9A8
.byte 0x00, 0x00, 0x00, 0x00
.byte 0x00, 0x00, 0x00, 0x00
.byte 0x00, 0x00, 0x00, 0x00
.4byte gUnknown_811B884
.4byte gUnknown_811B994
.4byte gUnknown_811B988
.4byte gUnknown_811B97C
.byte 0x00, 0x00, 0x00, 0x00
.4byte gUnknown_811B878
.byte 0x00, 0x00, 0x00, 0x00
.4byte gUnknown_811B870
.4byte gUnknown_811B864
.4byte gUnknown_811B858
.4byte gUnknown_811B84C
.byte 0x00, 0x00, 0x00, 0x00
.byte 0x00, 0x00, 0x00, 0x00
.byte 0x00, 0x00, 0x00, 0x00
.4byte gUnknown_811B844
.4byte gUnknown_811B934
.4byte gUnknown_811B928
.byte 0x00, 0x00, 0x00, 0x00
.byte 0x00, 0x00, 0x00, 0x00
.byte 0x00, 0x00, 0x00, 0x00
.byte 0x00, 0x00, 0x00, 0x00
.4byte gUnknown_811B83C
.4byte gUnknown_811B934
.4byte gUnknown_811B914
.byte 0x00, 0x00, 0x00, 0x00
.byte 0x00, 0x00, 0x00, 0x00
.byte 0x00, 0x00, 0x00, 0x00
.byte 0x00, 0x00, 0x00, 0x00
.4byte gUnknown_811B834
.4byte gUnknown_811B900
.4byte gUnknown_811B8F4
.byte 0x00, 0x00, 0x00, 0x00
.byte 0x00, 0x00, 0x00, 0x00
.byte 0x00, 0x00, 0x00, 0x00
.byte 0x00, 0x00, 0x00, 0x00
.4byte gUnknown_811B82C
.4byte gUnknown_811B9C0
.4byte gUnknown_811B9B4
.4byte gUnknown_811B9A8
.byte 0x00, 0x00, 0x00, 0x00
.byte 0x00, 0x00, 0x00, 0x00
.byte 0x00, 0x00, 0x00, 0x00
.4byte gUnknown_811B824
.4byte gUnknown_811B994
.4byte gUnknown_811B988
.4byte gUnknown_811B97C
.byte 0x00, 0x00, 0x00, 0x00
.4byte gUnknown_811B818
.byte 0x00, 0x00, 0x00, 0x00
.4byte gUnknown_811B810
.4byte gUnknown_811B804
.4byte gUnknown_811B7F8
.4byte gUnknown_811B7EC
.byte 0x00, 0x00, 0x00, 0x00
.byte 0x00, 0x00, 0x00, 0x00
.byte 0x00, 0x00, 0x00, 0x00
.4byte gUnknown_811B7E4
.4byte gUnknown_811B934
.4byte gUnknown_811B928
.byte 0x00, 0x00, 0x00, 0x00
.byte 0x00, 0x00, 0x00, 0x00
.byte 0x00, 0x00, 0x00, 0x00
.byte 0x00, 0x00, 0x00, 0x00
.4byte gUnknown_811B7DC
.4byte gUnknown_811B934
.4byte gUnknown_811B914
.byte 0x00, 0x00, 0x00, 0x00
.byte 0x00, 0x00, 0x00, 0x00
.byte 0x00, 0x00, 0x00, 0x00
.byte 0x00, 0x00, 0x00, 0x00
.4byte gUnknown_811B7D4
.4byte gUnknown_811B900
.4byte gUnknown_811B8F4
.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.4byte gUnknown_811B7CC
.4byte gUnknown_811B7C0
.4byte gUnknown_811B7B4
.4byte gUnknown_811B7A8
.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.4byte gUnknown_811B7A0
.4byte gUnknown_811B794
.4byte gUnknown_811B788
.4byte gUnknown_811B77C
.byte 0x00, 0x00, 0x00, 0x00
.4byte gUnknown_811B770
.byte 0x00, 0x00, 0x00, 0x00
.4byte gUnknown_811B768
.4byte gUnknown_811B75C
.4byte gUnknown_811B750
.4byte gUnknown_811B744
.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.4byte gUnknown_811B73C
.4byte gUnknown_811B734
.4byte gUnknown_811B728
.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.4byte gUnknown_811B720
.4byte gUnknown_811B734
.4byte gUnknown_811B714
.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.byte 0x00, 0x00, 0x00, 0x00
.4byte gUnknown_811B70C
.4byte gUnknown_811B700
.4byte gUnknown_811B6F4
.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.4byte gUnknown_811B6EC
.4byte gUnknown_811B7C0
.4byte gUnknown_811B7B4
.4byte gUnknown_811B7A8
.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.4byte gUnknown_811B6E4
.4byte gUnknown_811B794
.4byte gUnknown_811B788
.4byte gUnknown_811B77C
.byte 0x00, 0x00, 0x00, 0x00
.4byte gUnknown_811B6D8
.byte 0x00, 0x00, 0x00, 0x00
.4byte gUnknown_811B6D0
.4byte gUnknown_811B6C4
.4byte gUnknown_811B6B8
.4byte gUnknown_811B6AC
.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.4byte gUnknown_811B6A4
.4byte gUnknown_811B734
.4byte gUnknown_811B728
.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.4byte gUnknown_811B69C
.4byte gUnknown_811B734
.4byte gUnknown_811B714
.byte 0x00, 0x00, 0x00, 0x00
.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.4byte gUnknown_811B694
.4byte gUnknown_811B700
.4byte gUnknown_811B6F4
.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.4byte gUnknown_811B68C
.4byte gUnknown_811B7C0
.4byte gUnknown_811B7B4
.4byte gUnknown_811B7A8
.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.byte 0x00, 0x00, 0x00, 0x00
.4byte gUnknown_811B684
.4byte gUnknown_811B794
.4byte gUnknown_811B788
.4byte gUnknown_811B77C
.byte 0x00, 0x00, 0x00, 0x00
.4byte gUnknown_811B678
.byte 0x00, 0x00, 0x00, 0x00
.4byte gUnknown_811B670
.4byte gUnknown_811B664
.4byte gUnknown_811B658
.4byte gUnknown_811B64C
.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.4byte gUnknown_811B644
.4byte gUnknown_811B734
.4byte gUnknown_811B728
.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.4byte gUnknown_811B63C
.4byte gUnknown_811B734
.4byte gUnknown_811B714
.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.4byte gUnknown_811B634
.4byte gUnknown_811B700
.4byte gUnknown_811B6F4
.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.4byte gUnknown_811B62C
.4byte gUnknown_811B7C0
.4byte gUnknown_811B7B4
.4byte gUnknown_811B7A8
.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.4byte gUnknown_811B624
.4byte gUnknown_811B794
.4byte gUnknown_811B788
.4byte gUnknown_811B77C
.byte 0x00, 0x00, 0x00, 0x00
.4byte gUnknown_811B618
.byte 0x00, 0x00, 0x00, 0x00
.4byte gUnknown_811B610
.4byte gUnknown_811B604
.4byte gUnknown_811B5F8
.4byte gUnknown_811B5EC
.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.byte 0x00, 0x00, 0x00, 0x00
.4byte gUnknown_811B5E4
.4byte gUnknown_811B734
.4byte gUnknown_811B728
.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.4byte gUnknown_811B5DC
.4byte gUnknown_811B734
.4byte gUnknown_811B714
.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.4byte gUnknown_811B5D4
.4byte gUnknown_811B700
.4byte gUnknown_811B6F4
.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.4byte gUnknown_811B5CC
.4byte gUnknown_811B5C0
.4byte gUnknown_811B5B4
.4byte gUnknown_811B5A8
.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.4byte gUnknown_811B5A0
.4byte gUnknown_811B594
.4byte gUnknown_811B588
.4byte gUnknown_811B57C
.byte 0x00, 0x00, 0x00, 0x00
.4byte gUnknown_811B570
.byte 0x00, 0x00, 0x00, 0x00
.4byte gUnknown_811B568
.4byte gUnknown_811B55C
.4byte gUnknown_811B550
.4byte gUnknown_811B544
.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.4byte gUnknown_811B53C
.4byte gUnknown_811B534
.4byte gUnknown_811B528
.4byte gUnknown_811B520
.byte 0x00, 0x00, 0x00, 0x00
.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.4byte gUnknown_811B518
.4byte gUnknown_811B534
.4byte gUnknown_811B50C
.4byte gUnknown_811B520
.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.byte 0x00, 0x00, 0x00, 0x00
.4byte gUnknown_811B504
.4byte gUnknown_811B4F8
.4byte gUnknown_811B4EC
.4byte gUnknown_811B4E0
.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.4byte gUnknown_811B4D8
.4byte gUnknown_811B5C0
.4byte gUnknown_811B5B4
.4byte gUnknown_811B5A8
.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.4byte gUnknown_811B4D0
.4byte gUnknown_811B594
.4byte gUnknown_811B588
.4byte gUnknown_811B57C
.byte 0x00, 0x00, 0x00, 0x00
.4byte gUnknown_811B4C4
.byte 0x00, 0x00, 0x00, 0x00
.4byte gUnknown_811B4BC
.4byte gUnknown_811B4B0
.4byte gUnknown_811B4A4
.4byte gUnknown_811B498
.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.4byte gUnknown_811B490
.4byte gUnknown_811B534
.4byte gUnknown_811B528
.4byte gUnknown_811B520
.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.4byte gUnknown_811B488
.4byte gUnknown_811B534
.4byte gUnknown_811B50C
.4byte gUnknown_811B520
.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.4byte gUnknown_811B480
.4byte gUnknown_811B4F8
.4byte gUnknown_811B4EC
.4byte gUnknown_811B4E0
.byte 0x00, 0x00, 0x00, 0x00
.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.4byte gUnknown_811B478
.4byte gUnknown_811B5C0
.4byte gUnknown_811B5B4
.4byte gUnknown_811B5A8
.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.byte 0x00, 0x00, 0x00, 0x00
.4byte gUnknown_811B470
.4byte gUnknown_811B594
.4byte gUnknown_811B588
.4byte gUnknown_811B57C
.byte 0x00, 0x00, 0x00, 0x00
.4byte gUnknown_811B464
.byte 0x00, 0x00, 0x00, 0x00
.4byte gUnknown_811B45C
.4byte gUnknown_811B450
.4byte gUnknown_811B444
.4byte gUnknown_811B438
.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.4byte gUnknown_811B430
.4byte gUnknown_811B534
.4byte gUnknown_811B528
.4byte gUnknown_811B520
.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.4byte gUnknown_811B428
.4byte gUnknown_811B534
.4byte gUnknown_811B50C
.4byte gUnknown_811B520
.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.4byte gUnknown_811B420
.4byte gUnknown_811B4F8
.4byte gUnknown_811B4EC
.4byte gUnknown_811B4E0
.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.4byte gUnknown_811B418
.4byte gUnknown_811B40C
.4byte gUnknown_811B400
.4byte gUnknown_811B3F4
.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.4byte gUnknown_811B3EC
.4byte gUnknown_811B3E0
.4byte gUnknown_811B3D4
.4byte gUnknown_811B3C8
.byte 0x00, 0x00, 0x00, 0x00
.4byte gUnknown_811B3BC
.byte 0x00, 0x00, 0x00, 0x00
.4byte gUnknown_811B3B4
.4byte gUnknown_811B3A8
.4byte gUnknown_811B39C
.4byte gUnknown_811B390
.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.byte 0x00, 0x00, 0x00, 0x00
.4byte gUnknown_811B388
.4byte gUnknown_811B380
.4byte gUnknown_811B374
.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.4byte gUnknown_811B36C
.4byte gUnknown_811B380
.4byte gUnknown_811B360
.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.4byte gUnknown_811B358
.4byte gUnknown_811B34C
.4byte gUnknown_811B340
.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.4byte gUnknown_811B338
.4byte gUnknown_811B40C
.4byte gUnknown_811B400
.4byte gUnknown_811B3F4
.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.4byte gUnknown_811B330
.4byte gUnknown_811B3E0
.4byte gUnknown_811B3D4
.4byte gUnknown_811B3C8
.byte 0x00, 0x00, 0x00, 0x00
.4byte gUnknown_811B324
.byte 0x00, 0x00, 0x00, 0x00
.4byte gUnknown_811B31C
.4byte gUnknown_811B310
.4byte gUnknown_811B304
.4byte gUnknown_811B2F8
.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.4byte gUnknown_811B2F0
.4byte gUnknown_811B380
.4byte gUnknown_811B374
.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.4byte gUnknown_811B2E8
.4byte gUnknown_811B380
.4byte gUnknown_811B360
.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.byte 0x00, 0x00, 0x00, 0x00
.4byte gUnknown_811B2E0
.4byte gUnknown_811B34C
.4byte gUnknown_811B340
.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.4byte gUnknown_811B2D8
.4byte gUnknown_811B2CC
.4byte gUnknown_811B2C0
.4byte gUnknown_811B2B4
.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.4byte gUnknown_811B2AC
.4byte gUnknown_811B2A0
.4byte gUnknown_811B294
.4byte gUnknown_811B288
.byte 0x00, 0x00, 0x00, 0x00
.4byte gUnknown_811B27C
.byte 0x00, 0x00, 0x00, 0x00
.4byte gUnknown_811B274
.4byte gUnknown_811B268
.4byte gUnknown_811B25C
.4byte gUnknown_811B250
.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.4byte gUnknown_811B248
.4byte gUnknown_811B240
.4byte gUnknown_811B234
.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.4byte gUnknown_811B22C
.4byte gUnknown_811B240
.4byte gUnknown_811B220
.byte 0x00, 0x00, 0x00, 0x00
.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.4byte gUnknown_811B218
.4byte gUnknown_811B20C
.4byte gUnknown_811B200
.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.4byte gUnknown_811B1F8
.4byte gUnknown_811B2CC
.4byte gUnknown_811B2C0
.4byte gUnknown_811B2B4
.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.byte 0x00, 0x00, 0x00, 0x00
.4byte gUnknown_811B1F0
.4byte gUnknown_811B2A0
.4byte gUnknown_811B294
.4byte gUnknown_811B288
.byte 0x00, 0x00, 0x00, 0x00
.4byte gUnknown_811B1E4
.byte 0x00, 0x00, 0x00, 0x00
.4byte gUnknown_811B1DC
.4byte gUnknown_811B1D0
.4byte gUnknown_811B1C4
.4byte gUnknown_811B1B8
.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.4byte gUnknown_811B1B0
.4byte gUnknown_811B240
.4byte gUnknown_811B234
.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.4byte gUnknown_811B1A8
.4byte gUnknown_811B240
.4byte gUnknown_811B220
.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.4byte gUnknown_811B1A0
.4byte gUnknown_811B20C
.4byte gUnknown_811B200
.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.4byte gUnknown_811B198
.4byte gUnknown_811B2CC
.4byte gUnknown_811B2C0
.4byte gUnknown_811B2B4
.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.4byte gUnknown_811B190
.4byte gUnknown_811B2A0
.4byte gUnknown_811B294
.4byte gUnknown_811B288
.byte 0x00, 0x00, 0x00, 0x00
.4byte gUnknown_811B184
.byte 0x00, 0x00, 0x00, 0x00
.4byte gUnknown_811B17C
.4byte gUnknown_811B170
.4byte gUnknown_811B164
.4byte gUnknown_811B158
.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.byte 0x00, 0x00, 0x00, 0x00
.4byte gUnknown_811B150
.4byte gUnknown_811B240
.4byte gUnknown_811B234
.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.4byte gUnknown_811B148
.4byte gUnknown_811B240
.4byte gUnknown_811B220
.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.4byte gUnknown_811B140
.4byte gUnknown_811B20C
.4byte gUnknown_811B200
.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.4byte gUnknown_811B138
.4byte gUnknown_811B130
.4byte gUnknown_811B128
.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.4byte gUnknown_811B120
.4byte gUnknown_811B114
.4byte gUnknown_811B108
.4byte gUnknown_811B0FC
.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.4byte gUnknown_811B0F4
.4byte gUnknown_811B0EC
.4byte gUnknown_811B0E4
.byte 0x00, 0x00, 0x00, 0x00
.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.4byte gUnknown_811B0DC
.4byte gUnknown_811B0D4
.4byte gUnknown_811B0CC
.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.4byte gUnknown_811B0C4
.4byte gUnknown_811B0BC
.4byte gUnknown_811B0B4
.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.byte 0x00, 0x00, 0x00, 0x00
.4byte gUnknown_811B0AC
.4byte gUnknown_811B0A0
.4byte gUnknown_811B094
.4byte gUnknown_811B088
.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.4byte gUnknown_811B080
.4byte gUnknown_811B078
.4byte gUnknown_811B070
.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.4byte gUnknown_811B068
.4byte gUnknown_811B05C
.4byte gUnknown_811B050
.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.4byte gUnknown_811B048
.4byte gUnknown_811B040
.4byte gUnknown_811B038
.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.4byte gUnknown_811B030
.4byte gUnknown_811B024
.4byte gUnknown_811B018
.4byte gUnknown_811B00C
.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.4byte gUnknown_811B004
.4byte gUnknown_811AFFC
.4byte gUnknown_811AFF4
.byte 0x00, 0x00, 0x00, 0x00
.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.4byte gUnknown_811AFEC
.4byte gUnknown_811AFE4
.4byte gUnknown_811AFDC
.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.4byte gUnknown_811AFD4
.4byte gUnknown_811AFCC
.4byte gUnknown_811AFC4
.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.byte 0x00, 0x00, 0x00, 0x00
.4byte gUnknown_811AFBC
.4byte gUnknown_811AFB4
.4byte gUnknown_811AFAC
.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.4byte gUnknown_811AFA4
.4byte gUnknown_811AF9C
.4byte gUnknown_811AF94
.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.4byte gUnknown_811AF8C
.4byte gUnknown_811AF84
.4byte gUnknown_811AF7C
.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.4byte gUnknown_811AF74
.4byte gUnknown_811AF6C
.4byte gUnknown_811AF64
.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.4byte gUnknown_811AF5C
.4byte gUnknown_811AF54
.4byte gUnknown_811AF4C
.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.4byte gUnknown_811AF44
.4byte gUnknown_811AF3C
.4byte gUnknown_811AF34
.byte 0x00, 0x00, 0x00, 0x00
.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.4byte gUnknown_811AF2C
.4byte gUnknown_811AF24
.4byte gUnknown_811AF1C
.4byte gUnknown_811AF14
.byte 0x00, 0x00, 0x00, 0x00
.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.4byte gUnknown_811AF0C
.4byte gUnknown_811AF04
.4byte gUnknown_811AEFC
.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.byte 0x00, 0x00, 0x00, 0x00
.4byte gUnknown_811AEF4
.4byte gUnknown_811AEEC
.4byte gUnknown_811AEE4
.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.4byte gUnknown_811AEDC
.4byte gUnknown_811AED4
.4byte gUnknown_811AECC
.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.4byte gUnknown_811AEC4
.4byte gUnknown_811AEBC
.4byte gUnknown_811AEB4
.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.4byte gUnknown_811AEAC
.4byte gUnknown_811AEA4
.4byte gUnknown_811AE9C
.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.4byte gUnknown_811AE94
.4byte gUnknown_811AE88
.4byte gUnknown_811AE7C
.4byte gUnknown_811AE70
.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.4byte gUnknown_811AE68
.4byte gUnknown_811AE60
.4byte gUnknown_811AE58
.byte 0x00, 0x00, 0x00, 0x00
.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.4byte gUnknown_811AE50
.4byte gUnknown_811AE48
.4byte gUnknown_811AE40
.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.4byte gUnknown_811AE38
.4byte gUnknown_811AE30
.4byte gUnknown_811AE28
.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.byte 0x00, 0x00, 0x00, 0x00
.4byte gUnknown_811AE20
.4byte gUnknown_811AE18
.4byte gUnknown_811AE10
.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.4byte gUnknown_811AE08
.4byte gUnknown_811AE00
.4byte gUnknown_811ADF8
.4byte gUnknown_811ADF0
.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.4byte gUnknown_811ADE8
.4byte gUnknown_811ADE0
.4byte gUnknown_811ADD8
.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.4byte gUnknown_811ADD0
.4byte gUnknown_811ADC8
.4byte gUnknown_811ADC0
.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.4byte gUnknown_811ADB8
.4byte gUnknown_811ADB0
.4byte gUnknown_811ADA8
.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.4byte gUnknown_811ADA0
.4byte gUnknown_811AD98
.4byte gUnknown_811AD90
.byte 0x00, 0x00, 0x00, 0x00
.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.4byte gUnknown_811AD88
.4byte gUnknown_811AD80
.4byte gUnknown_811AD78
.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.4byte gUnknown_811AD70
.4byte gUnknown_811AD68
.4byte gUnknown_811AD60
.4byte gUnknown_811AD58
.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.byte 0x00, 0x00, 0x00, 0x00
.4byte gUnknown_811AD50
.4byte gUnknown_811AD48
.4byte gUnknown_811AD40
.4byte gUnknown_811AD38
.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.4byte gUnknown_811AD30
.4byte gUnknown_811AD28
.4byte gUnknown_811AD20
.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.4byte gUnknown_811AD18
.4byte gUnknown_811AD10
.4byte gUnknown_811AD08
.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.4byte gUnknown_811AD00
.4byte gUnknown_811ACF8
.4byte gUnknown_811ACF0
.byte 0x00, 0x00, 0x00, 0x00
.byte 0x00, 0x00, 0x00, 0x00
.byte 0x00, 0x00, 0x00, 0x00
.byte 0x00, 0x00, 0x00, 0x00
.4byte gUnknown_811ACE8
.4byte gUnknown_811ACE0
.4byte gUnknown_811ACD8
.byte 0x00, 0x00, 0x00, 0x00
.byte 0x00, 0x00, 0x00, 0x00
.byte 0x00, 0x00, 0x00, 0x00
.byte 0x00, 0x00, 0x00, 0x00
.4byte gUnknown_811ACD0
.4byte gUnknown_811ACC8
.4byte gUnknown_811ACC0
.byte 0x00, 0x00, 0x00, 0x00
.byte 0x00, 0x00, 0x00, 0x00
.byte 0x00, 0x00, 0x00, 0x00
.byte 0x00, 0x00, 0x00, 0x00
.4byte gUnknown_811ACB8
.4byte gUnknown_811ACB0
.4byte gUnknown_811ACA8
.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.4byte gUnknown_811ACA0
.4byte gUnknown_811AC98
.4byte gUnknown_811AC90
.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.byte 0x00, 0x00, 0x00, 0x00
.4byte gUnknown_811AC88
.4byte gUnknown_811AC7C
.4byte gUnknown_811AC70
.4byte gUnknown_811AC64
.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.4byte gUnknown_811AC5C
.4byte gUnknown_811AC54
.4byte gUnknown_811AC4C
.4byte gUnknown_811AC44
.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.4byte gUnknown_811AC3C
.4byte gUnknown_811AC34
.4byte gUnknown_811AC2C
.4byte gUnknown_811AC24
.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.4byte gUnknown_811AC1C
.4byte gUnknown_811AC10
.4byte gUnknown_811AC04
.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.4byte gUnknown_811ABFC
.4byte gUnknown_811ABF4
.4byte gUnknown_811ABEC
.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.4byte gUnknown_811ABE4
.4byte gUnknown_811ABDC
.4byte gUnknown_811ABD4
.byte 0x00, 0x00, 0x00, 0x00
.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.4byte gUnknown_811ABCC
.4byte gUnknown_811ABDC
.4byte gUnknown_811ABC4
.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.4byte gUnknown_811ABBC
.4byte gUnknown_811ABB4
.4byte gUnknown_811ABAC
.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.byte 0x00, 0x00, 0x00, 0x00
.4byte gUnknown_811ABA4
.4byte gUnknown_811AB9C
.4byte gUnknown_811AB94
.4byte gUnknown_811AB8C
.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.4byte gUnknown_811AB84
.4byte gUnknown_811AB7C
.4byte gUnknown_811AB74
.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.4byte gUnknown_811AB6C
.4byte gUnknown_811AB64
.4byte gUnknown_811AB5C
.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.4byte gUnknown_811AB54
.4byte gUnknown_811AB4C
.4byte gUnknown_811AB44
.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.4byte gUnknown_811AB3C
.4byte gUnknown_811AB34
.4byte gUnknown_811AB2C
.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.4byte gUnknown_811AB24
.4byte gUnknown_811AB1C
.4byte gUnknown_811AB14
.byte 0x00, 0x00, 0x00, 0x00
.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.4byte gUnknown_811AB0C
.4byte gUnknown_811AB04
.4byte gUnknown_811AAFC
.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.4byte gUnknown_811AAF4
.4byte gUnknown_811AAEC
.4byte gUnknown_811AAE4
.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.byte 0x00, 0x00, 0x00, 0x00
.4byte gUnknown_811AADC
.4byte gUnknown_811AAD4
.4byte gUnknown_811AACC
.4byte gUnknown_811AAC4
.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.4byte gUnknown_811AABC
.4byte gUnknown_811AAB4
.4byte gUnknown_811AAAC
.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.4byte gUnknown_811AAA4
.4byte gUnknown_811AA98
.4byte gUnknown_811AA8C
.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.4byte gUnknown_811AA84
.4byte gUnknown_811AA7C
.4byte gUnknown_811AA74
.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.4byte gUnknown_811AA6C
.4byte gUnknown_811AA64
.4byte gUnknown_811AA5C
.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.4byte gUnknown_811AA54
.4byte gUnknown_811AA64
.4byte gUnknown_811AA5C
.byte 0x00, 0x00, 0x00, 0x00
.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.4byte gUnknown_811AA4C
.4byte gUnknown_811AA44
.4byte gUnknown_811AA3C
.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.4byte gUnknown_811AA34
.4byte gUnknown_811AA2C
.4byte gUnknown_811AA24
.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.byte 0x00, 0x00, 0x00, 0x00
.4byte gUnknown_811AA1C
.4byte gUnknown_811AA14
.4byte gUnknown_811AA0C
.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.4byte gUnknown_811AA04
.4byte gUnknown_811A9FC
.4byte gUnknown_811A9F4
.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.4byte gUnknown_811A9EC
.4byte gUnknown_811A9E4
.4byte gUnknown_811A9DC
.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.4byte gUnknown_811A9D4
.4byte gUnknown_811A9CC
.4byte gUnknown_811A9C4
.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.4byte gUnknown_811A9BC
.4byte gUnknown_811A9B4
.4byte gUnknown_811A9AC
.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.4byte gUnknown_811A9A4
.4byte gUnknown_811A99C
.4byte gUnknown_811A994
.4byte gUnknown_811A98C
.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.4byte gUnknown_811A984
.4byte gUnknown_811A97C
.4byte gUnknown_811A974
.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.4byte gUnknown_811A96C
.4byte gUnknown_811A964
.4byte gUnknown_811A95C
.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.byte 0x00, 0x00, 0x00, 0x00
.4byte gUnknown_811A954
.4byte gUnknown_811A94C
.4byte gUnknown_811A944
.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.4byte gUnknown_811A93C
.4byte gUnknown_811A934
.4byte gUnknown_811A92C
.4byte gUnknown_811A924
.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.4byte gUnknown_811A91C
.4byte gUnknown_811A914
.4byte gUnknown_811A90C
.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.4byte gUnknown_811A904
.4byte gUnknown_811A8FC
.4byte gUnknown_811A8F4
.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.4byte gUnknown_811A8EC
.4byte gUnknown_811A8E4
.4byte gUnknown_811A8DC
.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.4byte gUnknown_811A8D4
.4byte gUnknown_811A8CC
.4byte gUnknown_811A8C4
.byte 0x00, 0x00, 0x00, 0x00
.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.4byte gUnknown_811A8BC
.4byte gUnknown_811A8B4
.4byte gUnknown_811A8AC
.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.4byte gUnknown_811A8A4
.4byte gUnknown_811A89C
.4byte gUnknown_811A894
.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.byte 0x00, 0x00, 0x00, 0x00
.4byte gUnknown_811A88C
.4byte gUnknown_811A884
.4byte gUnknown_811A87C
.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.4byte gUnknown_811A874
.4byte gUnknown_811A86C
.4byte gUnknown_811A864
.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.4byte gUnknown_811A85C
.4byte gUnknown_811A854
.4byte gUnknown_811A84C
.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.4byte gUnknown_811A844
.4byte gUnknown_811A83C
.4byte gUnknown_811A834
.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.4byte gUnknown_811A82C
.4byte gUnknown_811A824
.4byte gUnknown_811A81C
.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.4byte gUnknown_811A814
.4byte gUnknown_811A80C
.4byte gUnknown_811A804
.byte 0x00, 0x00, 0x00, 0x00
.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.4byte gUnknown_811A7FC
.4byte gUnknown_811A7F4
.4byte gUnknown_811A7EC
.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.4byte gUnknown_811A7E4
.4byte gUnknown_811A7DC
.4byte gUnknown_811A7D4
.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.byte 0x00, 0x00, 0x00, 0x00
.4byte gUnknown_811A7CC
.4byte gUnknown_811A7C4
.4byte gUnknown_811A7BC
.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.4byte gUnknown_811A7B4
.4byte gUnknown_811A7AC
.4byte gUnknown_811A7A4
.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.4byte gUnknown_811A79C
.4byte gUnknown_811A99C
.4byte gUnknown_811A994
.4byte gUnknown_811A98C
.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.4byte gUnknown_811A794
.4byte gUnknown_811A78C
.4byte gUnknown_811A784
.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.4byte gUnknown_811A77C
.4byte gUnknown_811A774
.4byte gUnknown_811A76C
.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.4byte gUnknown_811A764
.4byte gUnknown_811A75C
.4byte gUnknown_811A754
.byte 0x00, 0x00, 0x00, 0x00
.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.4byte gUnknown_811A74C
.4byte gUnknown_811A744
.4byte gUnknown_811A73C
.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.4byte gUnknown_811A734
.4byte gUnknown_811A72C
.4byte gUnknown_811A724
.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.byte 0x00, 0x00, 0x00, 0x00
.4byte gUnknown_811A71C
.4byte gUnknown_811A9CC
.4byte gUnknown_811A9C4
.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.4byte gUnknown_811A714
.4byte gUnknown_811A70C
.4byte gUnknown_811A704
.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.4byte gUnknown_811A6FC
.4byte gUnknown_811A6F4
.4byte gUnknown_811A6EC
.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.4byte gUnknown_811A6E4
.4byte gUnknown_811A6DC
.4byte gUnknown_811A6D4
.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.4byte gUnknown_811A6CC
.4byte gUnknown_811A6C4
.4byte gUnknown_811A6BC
.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.4byte gUnknown_811A6B4
.4byte gUnknown_811A6AC
.4byte gUnknown_811A6A4
.byte 0x00, 0x00, 0x00, 0x00
.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.4byte gUnknown_811A69C
.4byte gUnknown_811A694
.4byte gUnknown_811A68C
.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.4byte gUnknown_811A684
.4byte gUnknown_811A67C
.4byte gUnknown_811A674
.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.byte 0x00, 0x00, 0x00, 0x00
.4byte gUnknown_811A66C
.4byte gUnknown_811A664
.4byte gUnknown_811A65C
.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.4byte gUnknown_811A654
.4byte gUnknown_811A64C
.4byte gUnknown_811A644
.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.4byte gUnknown_811A63C
.4byte gUnknown_811A634
.4byte gUnknown_811A62C
.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.4byte gUnknown_811A624
.4byte gUnknown_811A61C
.4byte gUnknown_811A614
.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.4byte gUnknown_811A60C
.4byte gUnknown_811A604
.4byte gUnknown_811A5FC
.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.4byte gUnknown_811A5F4
.4byte gUnknown_811A5EC
.4byte gUnknown_811A5E4
.byte 0x00, 0x00, 0x00, 0x00
.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.4byte gUnknown_811A5DC
.4byte gUnknown_811A5D4
.4byte gUnknown_811A5CC
.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.4byte gUnknown_811A5C4
.4byte gUnknown_811A5BC
.4byte gUnknown_811A5B4
.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.byte 0x00, 0x00, 0x00, 0x00
.4byte gUnknown_811A5AC
.4byte gUnknown_811A5A4
.4byte gUnknown_811A59C
.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.4byte gUnknown_811A594
.4byte gUnknown_811A58C
.4byte gUnknown_811A584
.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.4byte gUnknown_811A57C
.4byte gUnknown_811A574
.4byte gUnknown_811A56C
.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.4byte gUnknown_811A564
.4byte gUnknown_811A55C
.4byte gUnknown_811A554
.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.4byte gUnknown_811A54C
.4byte gUnknown_811A544
.4byte gUnknown_811A53C
.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.4byte gUnknown_811A534
.4byte gUnknown_811A52C
.4byte gUnknown_811A524
.byte 0x00, 0x00, 0x00, 0x00
.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.4byte gUnknown_811A51C
.4byte gUnknown_811A514
.4byte gUnknown_811A50C
.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.4byte gUnknown_811A504
.4byte gUnknown_811A4FC
.4byte gUnknown_811A4F4
.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.byte 0x00, 0x00, 0x00, 0x00
.4byte gUnknown_811A4EC
.4byte gUnknown_811A4E4
.4byte gUnknown_811A4DC
.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.4byte gUnknown_811A4D8
.4byte gUnknown_811AA64
.4byte gUnknown_811AA5C
.byte 0x00, 0x00, 0x00, 0x00
.byte 0x00, 0x00, 0x00, 0x00
.byte 0x00, 0x00, 0x00, 0x00
.byte 0x00, 0x00, 0x00, 0x00
.4byte gUnknown_811A4D4
.4byte gUnknown_811A4CC
.4byte gUnknown_811A4C4
.byte 0x00, 0x00, 0x00, 0x00
.byte 0x00, 0x00, 0x00, 0x00
.byte 0x00, 0x00, 0x00, 0x00
.byte 0x00, 0x00, 0x00, 0x00
.4byte gUnknown_811A4C0
.4byte gUnknown_811A4B8
.4byte gUnknown_811A4B0
.byte 0x00, 0x00, 0x00, 0x00
.byte 0x00, 0x00, 0x00, 0x00
.byte 0x00, 0x00, 0x00, 0x00
.byte 0x00, 0x00, 0x00, 0x00
.4byte gUnknown_811A4AC
.4byte gUnknown_811A4A4
.4byte gUnknown_811A49C
.byte 0x00, 0x00, 0x00, 0x00
.byte 0x00, 0x00, 0x00, 0x00
.byte 0x00, 0x00, 0x00, 0x00
.byte 0x00, 0x00, 0x00, 0x00
.4byte gUnknown_811A498
.4byte gUnknown_811A490
.4byte gUnknown_811A488
.byte 0x00, 0x00, 0x00, 0x00
.byte 0x00, 0x00, 0x00, 0x00
.byte 0x00, 0x00, 0x00, 0x00
.byte 0x00, 0x00, 0x00, 0x00
.4byte gUnknown_811A484
.4byte gUnknown_811A47C
.4byte gUnknown_811A474
.byte 0x00, 0x00, 0x00, 0x00
.byte 0x00, 0x00, 0x00, 0x00
.byte 0x00, 0x00, 0x00, 0x00
.byte 0x00, 0x00, 0x00, 0x00
.4byte gUnknown_811A470
.4byte gUnknown_811A468
.4byte gUnknown_811A460
.byte 0x00, 0x00, 0x00, 0x00
.byte 0x00, 0x00, 0x00, 0x00
.byte 0x00, 0x00, 0x00, 0x00
.byte 0x00, 0x00, 0x00, 0x00
.4byte gUnknown_811A458
.4byte gUnknown_811A450
.4byte gUnknown_811A448
.4byte gUnknown_811A440
.byte 0x00, 0x00, 0x00, 0x00
.byte 0x00, 0x00, 0x00, 0x00
.byte 0x00, 0x00, 0x00, 0x00
.4byte gUnknown_811A438
.4byte gUnknown_811A430
.4byte gUnknown_811A428
.4byte gUnknown_811A420
.byte 0x00, 0x00, 0x00, 0x00
.byte 0x00, 0x00, 0x00, 0x00
.byte 0x00, 0x00, 0x00, 0x00
.4byte gUnknown_811A418
.4byte gUnknown_811A410
.4byte gUnknown_811A408
.4byte gUnknown_811A400
.byte 0x00, 0x00, 0x00, 0x00
.byte 0x00, 0x00, 0x00, 0x00
.byte 0x00, 0x00, 0x00, 0x00
.4byte gUnknown_811A3FC
.4byte gUnknown_811A3F4
.4byte gUnknown_811A3EC
.4byte gUnknown_811A3E4
.byte 0x00, 0x00, 0x00, 0x00
.byte 0x00, 0x00, 0x00, 0x00
.byte 0x00, 0x00, 0x00, 0x00
.4byte gUnknown_811A3E0
.4byte gUnknown_811A3D8
.4byte gUnknown_811A3D0
.byte 0x00, 0x00, 0x00, 0x00
.byte 0x00, 0x00, 0x00, 0x00
.byte 0x00, 0x00, 0x00, 0x00
.byte 0x00, 0x00, 0x00, 0x00
.4byte gUnknown_811A3CC
.4byte gUnknown_811A3C4
.4byte gUnknown_811A3BC
.byte 0x00, 0x00, 0x00, 0x00
.byte 0x00, 0x00, 0x00, 0x00
.byte 0x00, 0x00, 0x00, 0x00
.byte 0x00, 0x00, 0x00, 0x00
@ End of Pointers

.global gUnknown_811A3BC
gUnknown_811A3BC: @ 811A3BC
.string "W06m\0"
.align 2, 0

.global gUnknown_811A3C4
gUnknown_811A3C4: @ 811A3C4
.string "W06c\0"
.align 2, 0

.global gUnknown_811A3CC
gUnknown_811A3CC: @ 811A3CC
.byte 0x57, 0x30, 0x36, 0x00

.global gUnknown_811A3D0
gUnknown_811A3D0: @ 811A3D0
.string "W05m\0"
.align 2, 0

.global gUnknown_811A3D8
gUnknown_811A3D8: @ 811A3D8
.string "W05c\0"
.align 2, 0

.global gUnknown_811A3E0
gUnknown_811A3E0: @ 811A3E0
.byte 0x57, 0x30, 0x35, 0x00

.global gUnknown_811A3E4
gUnknown_811A3E4: @ 811A3E4
.string "W041\0"
.align 2, 0

.global gUnknown_811A3EC
gUnknown_811A3EC: @ 811A3EC
.string "W04m\0"
.align 2, 0

.global gUnknown_811A3F4
gUnknown_811A3F4: @ 811A3F4
.string "W04c\0"
.align 2, 0

.global gUnknown_811A3FC
gUnknown_811A3FC: @ 811A3FC
.byte 0x57, 0x30, 0x34, 0x00

.global gUnknown_811A400
gUnknown_811A400: @ 811A400
.string "W03P031\0"
.align 2, 0

.global gUnknown_811A408
gUnknown_811A408: @ 811A408
.string "W03P03m\0"
.align 2, 0

.global gUnknown_811A410
gUnknown_811A410: @ 811A410
.string "W03P03c\0"
.align 2, 0

.global gUnknown_811A418
gUnknown_811A418: @ 811A418
.string "W03P03\0"
.align 2, 0

.global gUnknown_811A420
gUnknown_811A420: @ 811A420
.string "W03P021\0"
.align 2, 0

.global gUnknown_811A428
gUnknown_811A428: @ 811A428
.string "W03P02m\0"
.align 2, 0

.global gUnknown_811A430
gUnknown_811A430: @ 811A430
.string "W03P02c\0"
.align 2, 0

.global gUnknown_811A438
gUnknown_811A438: @ 811A438
.string "W03P02\0"
.align 2, 0

.global gUnknown_811A440
gUnknown_811A440: @ 811A440
.string "W03P011\0"
.align 2, 0

.global gUnknown_811A448
gUnknown_811A448: @ 811A448
.string "W03P01m\0"
.align 2, 0

.global gUnknown_811A450
gUnknown_811A450: @ 811A450
.string "W03P01c\0"
.align 2, 0

.global gUnknown_811A458
gUnknown_811A458: @ 811A458
.string "W03P01\0"
.align 2, 0

.global gUnknown_811A460
gUnknown_811A460: @ 811A460
.string "W01m\0"
.align 2, 0

.global gUnknown_811A468
gUnknown_811A468: @ 811A468
.string "W01c\0"
.align 2, 0

.global gUnknown_811A470
gUnknown_811A470: @ 811A470
.byte 0x57, 0x30, 0x31, 0x00

.global gUnknown_811A474
gUnknown_811A474: @ 811A474
.string "S06m\0"
.align 2, 0

.global gUnknown_811A47C
gUnknown_811A47C: @ 811A47C
.string "S06c\0"
.align 2, 0

.global gUnknown_811A484
gUnknown_811A484: @ 811A484
.byte 0x53, 0x30, 0x36, 0x00

.global gUnknown_811A488
gUnknown_811A488: @ 811A488
.string "S05m\0"
.align 2, 0

.global gUnknown_811A490
gUnknown_811A490: @ 811A490
.string "S05c\0"
.align 2, 0

.global gUnknown_811A498
gUnknown_811A498: @ 811A498
.byte 0x53, 0x30, 0x35, 0x00

.global gUnknown_811A49C
gUnknown_811A49C: @ 811A49C
.string "S04m\0"
.align 2, 0

.global gUnknown_811A4A4
gUnknown_811A4A4: @ 811A4A4
.string "S04c\0"
.align 2, 0

.global gUnknown_811A4AC
gUnknown_811A4AC: @ 811A4AC
.byte 0x53, 0x30, 0x34, 0x00

.global gUnknown_811A4B0
gUnknown_811A4B0: @ 811A4B0
.string "S03m\0"
.align 2, 0

.global gUnknown_811A4B8
gUnknown_811A4B8: @ 811A4B8
.string "S03c\0"
.align 2, 0

.global gUnknown_811A4C0
gUnknown_811A4C0: @ 811A4C0
.byte 0x53, 0x30, 0x33, 0x00

.global gUnknown_811A4C4
gUnknown_811A4C4: @ 811A4C4
.string "S02m\0"
.align 2, 0

.global gUnknown_811A4CC
gUnknown_811A4CC: @ 811A4CC
.string "S02c\0"
.align 2, 0

.global gUnknown_811A4D4
gUnknown_811A4D4: @ 811A4D4
.byte 0x53, 0x30, 0x32, 0x00

.global gUnknown_811A4D8
gUnknown_811A4D8: @ 811A4D8
.byte 0x53, 0x30, 0x31, 0x00

.global gUnknown_811A4DC
gUnknown_811A4DC: @ 811A4DC
.string "D25P01m\0"
.align 2, 0

.global gUnknown_811A4E4
gUnknown_811A4E4: @ 811A4E4
.string "D25P01c\0"
.align 2, 0

.global gUnknown_811A4EC
gUnknown_811A4EC: @ 811A4EC
.string "D25P01\0"
.align 2, 0

.global gUnknown_811A4F4
gUnknown_811A4F4: @ 811A4F4
.string "D24P02m\0"
.align 2, 0

.global gUnknown_811A4FC
gUnknown_811A4FC: @ 811A4FC
.string "D24P02c\0"
.align 2, 0

.global gUnknown_811A504
gUnknown_811A504: @ 811A504
.string "D24P02\0"
.align 2, 0

.global gUnknown_811A50C
gUnknown_811A50C: @ 811A50C
.string "D24P01m\0"
.align 2, 0

.global gUnknown_811A514
gUnknown_811A514: @ 811A514
.string "D24P01c\0"
.align 2, 0

.global gUnknown_811A51C
gUnknown_811A51C: @ 811A51C
.string "D24P01\0"
.align 2, 0

.global gUnknown_811A524
gUnknown_811A524: @ 811A524
.string "D23P01m\0"
.align 2, 0

.global gUnknown_811A52C
gUnknown_811A52C: @ 811A52C
.string "D23P01c\0"
.align 2, 0

.global gUnknown_811A534
gUnknown_811A534: @ 811A534
.string "D23P01\0"
.align 2, 0

.global gUnknown_811A53C
gUnknown_811A53C: @ 811A53C
.string "D22P01m\0"
.align 2, 0

.global gUnknown_811A544
gUnknown_811A544: @ 811A544
.string "D22P01c\0"
.align 2, 0

.global gUnknown_811A54C
gUnknown_811A54C: @ 811A54C
.string "D22P01\0"
.align 2, 0

.global gUnknown_811A554
gUnknown_811A554: @ 811A554
.string "D21P01m\0"
.align 2, 0

.global gUnknown_811A55C
gUnknown_811A55C: @ 811A55C
.string "D21P01c\0"
.align 2, 0

.global gUnknown_811A564
gUnknown_811A564: @ 811A564
.string "D21P01\0"
.align 2, 0

.global gUnknown_811A56C
gUnknown_811A56C: @ 811A56C
.string "D20P01m\0"
.align 2, 0

.global gUnknown_811A574
gUnknown_811A574: @ 811A574
.string "D20P01c\0"
.align 2, 0

.global gUnknown_811A57C
gUnknown_811A57C: @ 811A57C
.string "D20P01\0"
.align 2, 0

.global gUnknown_811A584
gUnknown_811A584: @ 811A584
.string "D19P01m\0"
.align 2, 0

.global gUnknown_811A58C
gUnknown_811A58C: @ 811A58C
.string "D19P01c\0"
.align 2, 0

.global gUnknown_811A594
gUnknown_811A594: @ 811A594
.string "D19P01\0"
.align 2, 0

.global gUnknown_811A59C
gUnknown_811A59C: @ 811A59C
.string "D18P01m\0"
.align 2, 0

.global gUnknown_811A5A4
gUnknown_811A5A4: @ 811A5A4
.string "D18P01c\0"
.align 2, 0

.global gUnknown_811A5AC
gUnknown_811A5AC: @ 811A5AC
.string "D18P01\0"
.align 2, 0

.global gUnknown_811A5B4
gUnknown_811A5B4: @ 811A5B4
.string "D17P01m\0"
.align 2, 0

.global gUnknown_811A5BC
gUnknown_811A5BC: @ 811A5BC
.string "D17P01c\0"
.align 2, 0

.global gUnknown_811A5C4
gUnknown_811A5C4: @ 811A5C4
.string "D17P01\0"
.align 2, 0

.global gUnknown_811A5CC
gUnknown_811A5CC: @ 811A5CC
.string "D16P01m\0"
.align 2, 0

.global gUnknown_811A5D4
gUnknown_811A5D4: @ 811A5D4
.string "D16P01c\0"
.align 2, 0

.global gUnknown_811A5DC
gUnknown_811A5DC: @ 811A5DC
.string "D16P01\0"
.align 2, 0

.global gUnknown_811A5E4
gUnknown_811A5E4: @ 811A5E4
.string "D15P01m\0"
.align 2, 0

.global gUnknown_811A5EC
gUnknown_811A5EC: @ 811A5EC
.string "D15P01c\0"
.align 2, 0

.global gUnknown_811A5F4
gUnknown_811A5F4: @ 811A5F4
.string "D15P01\0"
.align 2, 0

.global gUnknown_811A5FC
gUnknown_811A5FC: @ 811A5FC
.string "D14P01m\0"
.align 2, 0

.global gUnknown_811A604
gUnknown_811A604: @ 811A604
.string "D14P01c\0"
.align 2, 0

.global gUnknown_811A60C
gUnknown_811A60C: @ 811A60C
.string "D14P01\0"
.align 2, 0

.global gUnknown_811A614
gUnknown_811A614: @ 811A614
.string "D13P03m\0"
.align 2, 0

.global gUnknown_811A61C
gUnknown_811A61C: @ 811A61C
.string "D13P03c\0"
.align 2, 0

.global gUnknown_811A624
gUnknown_811A624: @ 811A624
.string "D13P03\0"
.align 2, 0

.global gUnknown_811A62C
gUnknown_811A62C: @ 811A62C
.string "D13P02m\0"
.align 2, 0

.global gUnknown_811A634
gUnknown_811A634: @ 811A634
.string "D13P02c\0"
.align 2, 0

.global gUnknown_811A63C
gUnknown_811A63C: @ 811A63C
.string "D13P02\0"
.align 2, 0

.global gUnknown_811A644
gUnknown_811A644: @ 811A644
.string "D13P01m\0"
.align 2, 0

.global gUnknown_811A64C
gUnknown_811A64C: @ 811A64C
.string "D13P01c\0"
.align 2, 0

.global gUnknown_811A654
gUnknown_811A654: @ 811A654
.string "D13P01\0"
.align 2, 0

.global gUnknown_811A65C
gUnknown_811A65C: @ 811A65C
.string "D12P04m\0"
.align 2, 0

.global gUnknown_811A664
gUnknown_811A664: @ 811A664
.string "D12P04c\0"
.align 2, 0

.global gUnknown_811A66C
gUnknown_811A66C: @ 811A66C
.string "D12P04\0"
.align 2, 0

.global gUnknown_811A674
gUnknown_811A674: @ 811A674
.string "D12P02m\0"
.align 2, 0

.global gUnknown_811A67C
gUnknown_811A67C: @ 811A67C
.string "D12P02c\0"
.align 2, 0

.global gUnknown_811A684
gUnknown_811A684: @ 811A684
.string "D12P02\0"
.align 2, 0

.global gUnknown_811A68C
gUnknown_811A68C: @ 811A68C
.string "D12P01m\0"
.align 2, 0

.global gUnknown_811A694
gUnknown_811A694: @ 811A694
.string "D12P01c\0"
.align 2, 0

.global gUnknown_811A69C
gUnknown_811A69C: @ 811A69C
.string "D12P01\0"
.align 2, 0

.global gUnknown_811A6A4
gUnknown_811A6A4: @ 811A6A4
.string "D11P03m\0"
.align 2, 0

.global gUnknown_811A6AC
gUnknown_811A6AC: @ 811A6AC
.string "D11P03c\0"
.align 2, 0

.global gUnknown_811A6B4
gUnknown_811A6B4: @ 811A6B4
.string "D11P03\0"
.align 2, 0

.global gUnknown_811A6BC
gUnknown_811A6BC: @ 811A6BC
.string "D11P02m\0"
.align 2, 0

.global gUnknown_811A6C4
gUnknown_811A6C4: @ 811A6C4
.string "D11P02c\0"
.align 2, 0

.global gUnknown_811A6CC
gUnknown_811A6CC: @ 811A6CC
.string "D11P02\0"
.align 2, 0

.global gUnknown_811A6D4
gUnknown_811A6D4: @ 811A6D4
.string "D11P01m\0"
.align 2, 0

.global gUnknown_811A6DC
gUnknown_811A6DC: @ 811A6DC
.string "D11P01c\0"
.align 2, 0

.global gUnknown_811A6E4
gUnknown_811A6E4: @ 811A6E4
.string "D11P01\0"
.align 2, 0

.global gUnknown_811A6EC
gUnknown_811A6EC: @ 811A6EC
.string "D10P03m\0"
.align 2, 0

.global gUnknown_811A6F4
gUnknown_811A6F4: @ 811A6F4
.string "D10P03c\0"
.align 2, 0

.global gUnknown_811A6FC
gUnknown_811A6FC: @ 811A6FC
.string "D10P03\0"
.align 2, 0

.global gUnknown_811A704
gUnknown_811A704: @ 811A704
.string "D10P02m\0"
.align 2, 0

.global gUnknown_811A70C
gUnknown_811A70C: @ 811A70C
.string "D10P02c\0"
.align 2, 0

.global gUnknown_811A714
gUnknown_811A714: @ 811A714
.string "D10P02\0"
.align 2, 0

.global gUnknown_811A71C
gUnknown_811A71C: @ 811A71C
.string "D10P01\0"
.align 2, 0

.global gUnknown_811A724
gUnknown_811A724: @ 811A724
.string "D09P03m\0"
.align 2, 0

.global gUnknown_811A72C
gUnknown_811A72C: @ 811A72C
.string "D09P03c\0"
.align 2, 0

.global gUnknown_811A734
gUnknown_811A734: @ 811A734
.string "D09P03\0"
.align 2, 0

.global gUnknown_811A73C
gUnknown_811A73C: @ 811A73C
.string "D09P02m\0"
.align 2, 0

.global gUnknown_811A744
gUnknown_811A744: @ 811A744
.string "D09P02c\0"
.align 2, 0

.global gUnknown_811A74C
gUnknown_811A74C: @ 811A74C
.string "D09P02\0"
.align 2, 0

.global gUnknown_811A754
gUnknown_811A754: @ 811A754
.string "D09P01m\0"
.align 2, 0

.global gUnknown_811A75C
gUnknown_811A75C: @ 811A75C
.string "D09P01c\0"
.align 2, 0

.global gUnknown_811A764
gUnknown_811A764: @ 811A764
.string "D09P01\0"
.align 2, 0

.global gUnknown_811A76C
gUnknown_811A76C: @ 811A76C
.string "D08P02m\0"
.align 2, 0

.global gUnknown_811A774
gUnknown_811A774: @ 811A774
.string "D08P02c\0"
.align 2, 0

.global gUnknown_811A77C
gUnknown_811A77C: @ 811A77C
.string "D08P02\0"
.align 2, 0

.global gUnknown_811A784
gUnknown_811A784: @ 811A784
.string "D08P01m\0"
.align 2, 0

.global gUnknown_811A78C
gUnknown_811A78C: @ 811A78C
.string "D08P01c\0"
.align 2, 0

.global gUnknown_811A794
gUnknown_811A794: @ 811A794
.string "D08P01\0"
.align 2, 0

.global gUnknown_811A79C
gUnknown_811A79C: @ 811A79C
.string "D07P02\0"
.align 2, 0

.global gUnknown_811A7A4
gUnknown_811A7A4: @ 811A7A4
.string "D07P01m\0"
.align 2, 0

.global gUnknown_811A7AC
gUnknown_811A7AC: @ 811A7AC
.string "D07P01c\0"
.align 2, 0

.global gUnknown_811A7B4
gUnknown_811A7B4: @ 811A7B4
.string "D07P01\0"
.align 2, 0

.global gUnknown_811A7BC
gUnknown_811A7BC: @ 811A7BC
.string "D06P03m\0"
.align 2, 0

.global gUnknown_811A7C4
gUnknown_811A7C4: @ 811A7C4
.string "D06P03c\0"
.align 2, 0

.global gUnknown_811A7CC
gUnknown_811A7CC: @ 811A7CC
.string "D06P03\0"
.align 2, 0

.global gUnknown_811A7D4
gUnknown_811A7D4: @ 811A7D4
.string "D06P02m\0"
.align 2, 0

.global gUnknown_811A7DC
gUnknown_811A7DC: @ 811A7DC
.string "D06P02c\0"
.align 2, 0

.global gUnknown_811A7E4
gUnknown_811A7E4: @ 811A7E4
.string "D06P02\0"
.align 2, 0

.global gUnknown_811A7EC
gUnknown_811A7EC: @ 811A7EC
.string "D06P01m\0"
.align 2, 0

.global gUnknown_811A7F4
gUnknown_811A7F4: @ 811A7F4
.string "D06P01c\0"
.align 2, 0

.global gUnknown_811A7FC
gUnknown_811A7FC: @ 811A7FC
.string "D06P01\0"
.align 2, 0

.global gUnknown_811A804
gUnknown_811A804: @ 811A804
.string "D05P02m\0"
.align 2, 0

.global gUnknown_811A80C
gUnknown_811A80C: @ 811A80C
.string "D05P02c\0"
.align 2, 0

.global gUnknown_811A814
gUnknown_811A814: @ 811A814
.string "D05P02\0"
.align 2, 0

.global gUnknown_811A81C
gUnknown_811A81C: @ 811A81C
.string "D05P01m\0"
.align 2, 0

.global gUnknown_811A824
gUnknown_811A824: @ 811A824
.string "D05P01c\0"
.align 2, 0

.global gUnknown_811A82C
gUnknown_811A82C: @ 811A82C
.string "D05P01\0"
.align 2, 0

.global gUnknown_811A834
gUnknown_811A834: @ 811A834
.string "D04P02m\0"
.align 2, 0

.global gUnknown_811A83C
gUnknown_811A83C: @ 811A83C
.string "D04P02c\0"
.align 2, 0

.global gUnknown_811A844
gUnknown_811A844: @ 811A844
.string "D04P02\0"
.align 2, 0

.global gUnknown_811A84C
gUnknown_811A84C: @ 811A84C
.string "D04P01m\0"
.align 2, 0

.global gUnknown_811A854
gUnknown_811A854: @ 811A854
.string "D04P01c\0"
.align 2, 0

.global gUnknown_811A85C
gUnknown_811A85C: @ 811A85C
.string "D04P01\0"
.align 2, 0

.global gUnknown_811A864
gUnknown_811A864: @ 811A864
.string "D03P02m\0"
.align 2, 0

.global gUnknown_811A86C
gUnknown_811A86C: @ 811A86C
.string "D03P02c\0"
.align 2, 0

.global gUnknown_811A874
gUnknown_811A874: @ 811A874
.string "D03P02\0"
.align 2, 0

.global gUnknown_811A87C
gUnknown_811A87C: @ 811A87C
.string "D03P01m\0"
.align 2, 0

.global gUnknown_811A884
gUnknown_811A884: @ 811A884
.string "D03P01c\0"
.align 2, 0

.global gUnknown_811A88C
gUnknown_811A88C: @ 811A88C
.string "D03P01\0"
.align 2, 0

.global gUnknown_811A894
gUnknown_811A894: @ 811A894
.string "D02P02m\0"
.align 2, 0

.global gUnknown_811A89C
gUnknown_811A89C: @ 811A89C
.string "D02P02c\0"
.align 2, 0

.global gUnknown_811A8A4
gUnknown_811A8A4: @ 811A8A4
.string "D02P02\0"
.align 2, 0

.global gUnknown_811A8AC
gUnknown_811A8AC: @ 811A8AC
.string "D02P01m\0"
.align 2, 0

.global gUnknown_811A8B4
gUnknown_811A8B4: @ 811A8B4
.string "D02P01c\0"
.align 2, 0

.global gUnknown_811A8BC
gUnknown_811A8BC: @ 811A8BC
.string "D02P01\0"
.align 2, 0

.global gUnknown_811A8C4
gUnknown_811A8C4: @ 811A8C4
.string "D01P02m\0"
.align 2, 0

.global gUnknown_811A8CC
gUnknown_811A8CC: @ 811A8CC
.string "D01P02c\0"
.align 2, 0

.global gUnknown_811A8D4
gUnknown_811A8D4: @ 811A8D4
.string "D01P02\0"
.align 2, 0

.global gUnknown_811A8DC
gUnknown_811A8DC: @ 811A8DC
.string "D01P01m\0"
.align 2, 0

.global gUnknown_811A8E4
gUnknown_811A8E4: @ 811A8E4
.string "D01P01c\0"
.align 2, 0

.global gUnknown_811A8EC
gUnknown_811A8EC: @ 811A8EC
.string "D01P01\0"
.align 2, 0

.global gUnknown_811A8F4
gUnknown_811A8F4: @ 811A8F4
.string "A05P03m\0"
.align 2, 0

.global gUnknown_811A8FC
gUnknown_811A8FC: @ 811A8FC
.string "A05P03c\0"
.align 2, 0

.global gUnknown_811A904
gUnknown_811A904: @ 811A904
.string "A05P03\0"
.align 2, 0

.global gUnknown_811A90C
gUnknown_811A90C: @ 811A90C
.string "A05P02m\0"
.align 2, 0

.global gUnknown_811A914
gUnknown_811A914: @ 811A914
.string "A05P02c\0"
.align 2, 0

.global gUnknown_811A91C
gUnknown_811A91C: @ 811A91C
.string "A05P02\0"
.align 2, 0

.global gUnknown_811A924
gUnknown_811A924: @ 811A924
.string "A05P011\0"
.align 2, 0

.global gUnknown_811A92C
gUnknown_811A92C: @ 811A92C
.string "A05P01m\0"
.align 2, 0

.global gUnknown_811A934
gUnknown_811A934: @ 811A934
.string "A05P01c\0"
.align 2, 0

.global gUnknown_811A93C
gUnknown_811A93C: @ 811A93C
.string "A05P01\0"
.align 2, 0

.global gUnknown_811A944
gUnknown_811A944: @ 811A944
.string "A04P04m\0"
.align 2, 0

.global gUnknown_811A94C
gUnknown_811A94C: @ 811A94C
.string "A04P04c\0"
.align 2, 0

.global gUnknown_811A954
gUnknown_811A954: @ 811A954
.string "A04P04\0"
.align 2, 0

.global gUnknown_811A95C
gUnknown_811A95C: @ 811A95C
.string "A04P03m\0"
.align 2, 0

.global gUnknown_811A964
gUnknown_811A964: @ 811A964
.string "A04P03c\0"
.align 2, 0

.global gUnknown_811A96C
gUnknown_811A96C: @ 811A96C
.string "A04P03\0"
.align 2, 0

.global gUnknown_811A974
gUnknown_811A974: @ 811A974
.string "A04P02m\0"
.align 2, 0

.global gUnknown_811A97C
gUnknown_811A97C: @ 811A97C
.string "A04P02c\0"
.align 2, 0

.global gUnknown_811A984
gUnknown_811A984: @ 811A984
.string "A04P02\0"
.align 2, 0

.global gUnknown_811A98C
gUnknown_811A98C: @ 811A98C
.string "A04P011\0"
.align 2, 0

.global gUnknown_811A994
gUnknown_811A994: @ 811A994
.string "A04P01m\0"
.align 2, 0

.global gUnknown_811A99C
gUnknown_811A99C: @ 811A99C
.string "A04P01c\0"
.align 2, 0

.global gUnknown_811A9A4
gUnknown_811A9A4: @ 811A9A4
.string "A04P01\0"
.align 2, 0

.global gUnknown_811A9AC
gUnknown_811A9AC: @ 811A9AC
.string "A03P03m\0"
.align 2, 0

.global gUnknown_811A9B4
gUnknown_811A9B4: @ 811A9B4
.string "A03P03c\0"
.align 2, 0

.global gUnknown_811A9BC
gUnknown_811A9BC: @ 811A9BC
.string "A03P03\0"
.align 2, 0

.global gUnknown_811A9C4
gUnknown_811A9C4: @ 811A9C4
.string "D10P01m\0"
.align 2, 0

.global gUnknown_811A9CC
gUnknown_811A9CC: @ 811A9CC
.string "D10P01c\0"
.align 2, 0

.global gUnknown_811A9D4
gUnknown_811A9D4: @ 811A9D4
.string "A03P02\0"
.align 2, 0

.global gUnknown_811A9DC
gUnknown_811A9DC: @ 811A9DC
.string "A03P01m\0"
.align 2, 0

.global gUnknown_811A9E4
gUnknown_811A9E4: @ 811A9E4
.string "A03P01c\0"
.align 2, 0

.global gUnknown_811A9EC
gUnknown_811A9EC: @ 811A9EC
.string "A03P01\0"
.align 2, 0

.global gUnknown_811A9F4
gUnknown_811A9F4: @ 811A9F4
.string "A02P04m\0"
.align 2, 0

.global gUnknown_811A9FC
gUnknown_811A9FC: @ 811A9FC
.string "A02P04c\0"
.align 2, 0

.global gUnknown_811AA04
gUnknown_811AA04: @ 811AA04
.string "A02P04\0"
.align 2, 0

.global gUnknown_811AA0C
gUnknown_811AA0C: @ 811AA0C
.string "A02P03m\0"
.align 2, 0

.global gUnknown_811AA14
gUnknown_811AA14: @ 811AA14
.string "A02P03c\0"
.align 2, 0

.global gUnknown_811AA1C
gUnknown_811AA1C: @ 811AA1C
.string "A02P03\0"
.align 2, 0

.global gUnknown_811AA24
gUnknown_811AA24: @ 811AA24
.string "A02P02m\0"
.align 2, 0

.global gUnknown_811AA2C
gUnknown_811AA2C: @ 811AA2C
.string "A02P02c\0"
.align 2, 0

.global gUnknown_811AA34
gUnknown_811AA34: @ 811AA34
.string "A02P02\0"
.align 2, 0

.global gUnknown_811AA3C
gUnknown_811AA3C: @ 811AA3C
.string "A02P01m\0"
.align 2, 0

.global gUnknown_811AA44
gUnknown_811AA44: @ 811AA44
.string "A02P01c\0"
.align 2, 0

.global gUnknown_811AA4C
gUnknown_811AA4C: @ 811AA4C
.string "A02P01\0"
.align 2, 0

.global gUnknown_811AA54
gUnknown_811AA54: @ 811AA54
.string "A01P02\0"
.align 2, 0

.global gUnknown_811AA5C
gUnknown_811AA5C: @ 811AA5C
.string "A01P01m\0"
.align 2, 0

.global gUnknown_811AA64
gUnknown_811AA64: @ 811AA64
.string "A01P01c\0"
.align 2, 0

.global gUnknown_811AA6C
gUnknown_811AA6C: @ 811AA6C
.string "A01P01\0"
.align 2, 0

.global gUnknown_811AA74
gUnknown_811AA74: @ 811AA74
.string "H29P04m\0"
.align 2, 0

.global gUnknown_811AA7C
gUnknown_811AA7C: @ 811AA7C
.string "H29P04c\0"
.align 2, 0

.global gUnknown_811AA84
gUnknown_811AA84: @ 811AA84
.string "H29P04\0"
.align 2, 0

.global gUnknown_811AA8C
gUnknown_811AA8C: @ 811AA8C
.string "H29P03Wm\0"
.align 2, 0

.global gUnknown_811AA98
gUnknown_811AA98: @ 811AA98
.string "H29P03Wc\0"
.align 2, 0

.global gUnknown_811AAA4
gUnknown_811AAA4: @ 811AAA4
.string "H29P03W\0"
.align 2, 0

.global gUnknown_811AAAC
gUnknown_811AAAC: @ 811AAAC
.string "H29P03m\0"
.align 2, 0

.global gUnknown_811AAB4
gUnknown_811AAB4: @ 811AAB4
.string "H29P03c\0"
.align 2, 0

.global gUnknown_811AABC
gUnknown_811AABC: @ 811AABC
.string "H29P03\0"
.align 2, 0

.global gUnknown_811AAC4
gUnknown_811AAC4: @ 811AAC4
.string "H29P021\0"
.align 2, 0

.global gUnknown_811AACC
gUnknown_811AACC: @ 811AACC
.string "H29P02m\0"
.align 2, 0

.global gUnknown_811AAD4
gUnknown_811AAD4: @ 811AAD4
.string "H29P02c\0"
.align 2, 0

.global gUnknown_811AADC
gUnknown_811AADC: @ 811AADC
.string "H29P02\0"
.align 2, 0

.global gUnknown_811AAE4
gUnknown_811AAE4: @ 811AAE4
.string "H29P01m\0"
.align 2, 0

.global gUnknown_811AAEC
gUnknown_811AAEC: @ 811AAEC
.string "H29P01c\0"
.align 2, 0

.global gUnknown_811AAF4
gUnknown_811AAF4: @ 811AAF4
.string "H29P01\0"
.align 2, 0

.global gUnknown_811AAFC
gUnknown_811AAFC: @ 811AAFC
.string "H28P02m\0"
.align 2, 0

.global gUnknown_811AB04
gUnknown_811AB04: @ 811AB04
.string "H28P02c\0"
.align 2, 0

.global gUnknown_811AB0C
gUnknown_811AB0C: @ 811AB0C
.string "H28P02\0"
.align 2, 0

.global gUnknown_811AB14
gUnknown_811AB14: @ 811AB14
.string "H28P01m\0"
.align 2, 0

.global gUnknown_811AB1C
gUnknown_811AB1C: @ 811AB1C
.string "H28P01c\0"
.align 2, 0

.global gUnknown_811AB24
gUnknown_811AB24: @ 811AB24
.string "H28P01\0"
.align 2, 0

.global gUnknown_811AB2C
gUnknown_811AB2C: @ 811AB2C
.string "H27P01m\0"
.align 2, 0

.global gUnknown_811AB34
gUnknown_811AB34: @ 811AB34
.string "H27P01c\0"
.align 2, 0

.global gUnknown_811AB3C
gUnknown_811AB3C: @ 811AB3C
.string "H27P01\0"
.align 2, 0

.global gUnknown_811AB44
gUnknown_811AB44: @ 811AB44
.string "H26P01m\0"
.align 2, 0

.global gUnknown_811AB4C
gUnknown_811AB4C: @ 811AB4C
.string "H26P01c\0"
.align 2, 0

.global gUnknown_811AB54
gUnknown_811AB54: @ 811AB54
.string "H26P01\0"
.align 2, 0

.global gUnknown_811AB5C
gUnknown_811AB5C: @ 811AB5C
.string "H25P01m\0"
.align 2, 0

.global gUnknown_811AB64
gUnknown_811AB64: @ 811AB64
.string "H25P01c\0"
.align 2, 0

.global gUnknown_811AB6C
gUnknown_811AB6C: @ 811AB6C
.string "H25P01\0"
.align 2, 0

.global gUnknown_811AB74
gUnknown_811AB74: @ 811AB74
.string "H24P01m\0"
.align 2, 0

.global gUnknown_811AB7C
gUnknown_811AB7C: @ 811AB7C
.string "H24P01c\0"
.align 2, 0

.global gUnknown_811AB84
gUnknown_811AB84: @ 811AB84
.string "H24P01\0"
.align 2, 0

.global gUnknown_811AB8C
gUnknown_811AB8C: @ 811AB8C
.string "H23P011\0"
.align 2, 0

.global gUnknown_811AB94
gUnknown_811AB94: @ 811AB94
.string "H23P01m\0"
.align 2, 0

.global gUnknown_811AB9C
gUnknown_811AB9C: @ 811AB9C
.string "H23P01c\0"
.align 2, 0

.global gUnknown_811ABA4
gUnknown_811ABA4: @ 811ABA4
.string "H23P01\0"
.align 2, 0

.global gUnknown_811ABAC
gUnknown_811ABAC: @ 811ABAC
.string "H22P01m\0"
.align 2, 0

.global gUnknown_811ABB4
gUnknown_811ABB4: @ 811ABB4
.string "H22P01c\0"
.align 2, 0

.global gUnknown_811ABBC
gUnknown_811ABBC: @ 811ABBC
.string "H22P01\0"
.align 2, 0

.global gUnknown_811ABC4
gUnknown_811ABC4: @ 811ABC4
.string "H21P02m\0"
.align 2, 0

.global gUnknown_811ABCC
gUnknown_811ABCC: @ 811ABCC
.string "H21P02\0"
.align 2, 0

.global gUnknown_811ABD4
gUnknown_811ABD4: @ 811ABD4
.string "H21P01m\0"
.align 2, 0

.global gUnknown_811ABDC
gUnknown_811ABDC: @ 811ABDC
.string "H21c\0"
.align 2, 0

.global gUnknown_811ABE4
gUnknown_811ABE4: @ 811ABE4
.string "H21P01\0"
.align 2, 0

.global gUnknown_811ABEC
gUnknown_811ABEC: @ 811ABEC
.string "H20P01m\0"
.align 2, 0

.global gUnknown_811ABF4
gUnknown_811ABF4: @ 811ABF4
.string "H20P01c\0"
.align 2, 0

.global gUnknown_811ABFC
gUnknown_811ABFC: @ 811ABFC
.string "H20P01\0"
.align 2, 0

.global gUnknown_811AC04
gUnknown_811AC04: @ 811AC04
.string "H19P01Wm\0"
.align 2, 0

.global gUnknown_811AC10
gUnknown_811AC10: @ 811AC10
.string "H19P01Wc\0"
.align 2, 0

.global gUnknown_811AC1C
gUnknown_811AC1C: @ 811AC1C
.string "H19P01W\0"
.align 2, 0

.global gUnknown_811AC24
gUnknown_811AC24: @ 811AC24
.string "H19P011\0"
.align 2, 0

.global gUnknown_811AC2C
gUnknown_811AC2C: @ 811AC2C
.string "H19P01m\0"
.align 2, 0

.global gUnknown_811AC34
gUnknown_811AC34: @ 811AC34
.string "H19P01c\0"
.align 2, 0

.global gUnknown_811AC3C
gUnknown_811AC3C: @ 811AC3C
.string "H19P01\0"
.align 2, 0

.global gUnknown_811AC44
gUnknown_811AC44: @ 811AC44
.string "H18P011\0"
.align 2, 0

.global gUnknown_811AC4C
gUnknown_811AC4C: @ 811AC4C
.string "H18P01m\0"
.align 2, 0

.global gUnknown_811AC54
gUnknown_811AC54: @ 811AC54
.string "H18P01c\0"
.align 2, 0

.global gUnknown_811AC5C
gUnknown_811AC5C: @ 811AC5C
.string "H18P01\0"
.align 2, 0

.global gUnknown_811AC64
gUnknown_811AC64: @ 811AC64
.string "H17P01W1\0"
.align 2, 0

.global gUnknown_811AC70
gUnknown_811AC70: @ 811AC70
.string "H17P01Wm\0"
.align 2, 0

.global gUnknown_811AC7C
gUnknown_811AC7C: @ 811AC7C
.string "H17P01Wc\0"
.align 2, 0

.global gUnknown_811AC88
gUnknown_811AC88: @ 811AC88
.string "H17P01W\0"
.align 2, 0

.global gUnknown_811AC90
gUnknown_811AC90: @ 811AC90
.string "H17P01m\0"
.align 2, 0

.global gUnknown_811AC98
gUnknown_811AC98: @ 811AC98
.string "H17P01c\0"
.align 2, 0

.global gUnknown_811ACA0
gUnknown_811ACA0: @ 811ACA0
.string "H17P01\0"
.align 2, 0

.global gUnknown_811ACA8
gUnknown_811ACA8: @ 811ACA8
.string "H16P01m\0"
.align 2, 0

.global gUnknown_811ACB0
gUnknown_811ACB0: @ 811ACB0
.string "H16P01c\0"
.align 2, 0

.global gUnknown_811ACB8
gUnknown_811ACB8: @ 811ACB8
.string "H16P01\0"
.align 2, 0

.global gUnknown_811ACC0
gUnknown_811ACC0: @ 811ACC0
.string "H15P01m\0"
.align 2, 0

.global gUnknown_811ACC8
gUnknown_811ACC8: @ 811ACC8
.string "H15P01c\0"
.align 2, 0

.global gUnknown_811ACD0
gUnknown_811ACD0: @ 811ACD0
.string "H15P01\0"
.align 2, 0

.global gUnknown_811ACD8
gUnknown_811ACD8: @ 811ACD8
.string "H14P01m\0"
.align 2, 0

.global gUnknown_811ACE0
gUnknown_811ACE0: @ 811ACE0
.string "H14P01c\0"
.align 2, 0

.global gUnknown_811ACE8
gUnknown_811ACE8: @ 811ACE8
.string "H14P01\0"
.align 2, 0

.global gUnknown_811ACF0
gUnknown_811ACF0: @ 811ACF0
.string "H13P04m\0"
.align 2, 0

.global gUnknown_811ACF8
gUnknown_811ACF8: @ 811ACF8
.string "H13P04c\0"
.align 2, 0

.global gUnknown_811AD00
gUnknown_811AD00: @ 811AD00
.string "H13P04\0"
.align 2, 0

.global gUnknown_811AD08
gUnknown_811AD08: @ 811AD08
.string "H13P03m\0"
.align 2, 0

.global gUnknown_811AD10
gUnknown_811AD10: @ 811AD10
.string "H13P03c\0"
.align 2, 0

.global gUnknown_811AD18
gUnknown_811AD18: @ 811AD18
.string "H13P03\0"
.align 2, 0

.global gUnknown_811AD20
gUnknown_811AD20: @ 811AD20
.string "H13P02m\0"
.align 2, 0

.global gUnknown_811AD28
gUnknown_811AD28: @ 811AD28
.string "H13P02c\0"
.align 2, 0

.global gUnknown_811AD30
gUnknown_811AD30: @ 811AD30
.string "H13P02\0"
.align 2, 0

.global gUnknown_811AD38
gUnknown_811AD38: @ 811AD38
.string "H13P011\0"
.align 2, 0

.global gUnknown_811AD40
gUnknown_811AD40: @ 811AD40
.string "H13P01m\0"
.align 2, 0

.global gUnknown_811AD48
gUnknown_811AD48: @ 811AD48
.string "H13P01c\0"
.align 2, 0

.global gUnknown_811AD50
gUnknown_811AD50: @ 811AD50
.string "H13P01\0"
.align 2, 0

.global gUnknown_811AD58
gUnknown_811AD58: @ 811AD58
.string "H12P011\0"
.align 2, 0

.global gUnknown_811AD60
gUnknown_811AD60: @ 811AD60
.string "H12P01m\0"
.align 2, 0

.global gUnknown_811AD68
gUnknown_811AD68: @ 811AD68
.string "H12P01c\0"
.align 2, 0

.global gUnknown_811AD70
gUnknown_811AD70: @ 811AD70
.string "H12P01\0"
.align 2, 0

.global gUnknown_811AD78
gUnknown_811AD78: @ 811AD78
.string "H11P01m\0"
.align 2, 0

.global gUnknown_811AD80
gUnknown_811AD80: @ 811AD80
.string "H11P01c\0"
.align 2, 0

.global gUnknown_811AD88
gUnknown_811AD88: @ 811AD88
.string "H11P01\0"
.align 2, 0

.global gUnknown_811AD90
gUnknown_811AD90: @ 811AD90
.string "H10P02m\0"
.align 2, 0

.global gUnknown_811AD98
gUnknown_811AD98: @ 811AD98
.string "H10P02c\0"
.align 2, 0

.global gUnknown_811ADA0
gUnknown_811ADA0: @ 811ADA0
.string "H10P02\0"
.align 2, 0

.global gUnknown_811ADA8
gUnknown_811ADA8: @ 811ADA8
.string "H10P01m\0"
.align 2, 0

.global gUnknown_811ADB0
gUnknown_811ADB0: @ 811ADB0
.string "H10P01c\0"
.align 2, 0

.global gUnknown_811ADB8
gUnknown_811ADB8: @ 811ADB8
.string "H10P01\0"
.align 2, 0

.global gUnknown_811ADC0
gUnknown_811ADC0: @ 811ADC0
.string "H09P02m\0"
.align 2, 0

.global gUnknown_811ADC8
gUnknown_811ADC8: @ 811ADC8
.string "H09P02c\0"
.align 2, 0

.global gUnknown_811ADD0
gUnknown_811ADD0: @ 811ADD0
.string "H09P02\0"
.align 2, 0

.global gUnknown_811ADD8
gUnknown_811ADD8: @ 811ADD8
.string "H09P01m\0"
.align 2, 0

.global gUnknown_811ADE0
gUnknown_811ADE0: @ 811ADE0
.string "H09P01c\0"
.align 2, 0

.global gUnknown_811ADE8
gUnknown_811ADE8: @ 811ADE8
.string "H09P01\0"
.align 2, 0

.global gUnknown_811ADF0
gUnknown_811ADF0: @ 811ADF0
.string "H08P011\0"
.align 2, 0

.global gUnknown_811ADF8
gUnknown_811ADF8: @ 811ADF8
.string "H08P01m\0"
.align 2, 0

.global gUnknown_811AE00
gUnknown_811AE00: @ 811AE00
.string "H08P01c\0"
.align 2, 0

.global gUnknown_811AE08
gUnknown_811AE08: @ 811AE08
.string "H08P01\0"
.align 2, 0

.global gUnknown_811AE10
gUnknown_811AE10: @ 811AE10
.string "H07P08m\0"
.align 2, 0

.global gUnknown_811AE18
gUnknown_811AE18: @ 811AE18
.string "H07P08c\0"
.align 2, 0

.global gUnknown_811AE20
gUnknown_811AE20: @ 811AE20
.string "H07P08\0"
.align 2, 0

.global gUnknown_811AE28
gUnknown_811AE28: @ 811AE28
.string "H07P07m\0"
.align 2, 0

.global gUnknown_811AE30
gUnknown_811AE30: @ 811AE30
.string "H07P07c\0"
.align 2, 0

.global gUnknown_811AE38
gUnknown_811AE38: @ 811AE38
.string "H07P07\0"
.align 2, 0

.global gUnknown_811AE40
gUnknown_811AE40: @ 811AE40
.string "H07P06m\0"
.align 2, 0

.global gUnknown_811AE48
gUnknown_811AE48: @ 811AE48
.string "H07P06c\0"
.align 2, 0

.global gUnknown_811AE50
gUnknown_811AE50: @ 811AE50
.string "H07P06\0"
.align 2, 0

.global gUnknown_811AE58
gUnknown_811AE58: @ 811AE58
.string "H07P05m\0"
.align 2, 0

.global gUnknown_811AE60
gUnknown_811AE60: @ 811AE60
.string "H07P05c\0"
.align 2, 0

.global gUnknown_811AE68
gUnknown_811AE68: @ 811AE68
.string "H07P05\0"
.align 2, 0

.global gUnknown_811AE70
gUnknown_811AE70: @ 811AE70
.string "H07P04W1\0"
.align 2, 0

.global gUnknown_811AE7C
gUnknown_811AE7C: @ 811AE7C
.string "H07P04Wm\0"
.align 2, 0

.global gUnknown_811AE88
gUnknown_811AE88: @ 811AE88
.string "H07P04Wc\0"
.align 2, 0

.global gUnknown_811AE94
gUnknown_811AE94: @ 811AE94
.string "H07P04W\0"
.align 2, 0

.global gUnknown_811AE9C
gUnknown_811AE9C: @ 811AE9C
.string "H07P04m\0"
.align 2, 0

.global gUnknown_811AEA4
gUnknown_811AEA4: @ 811AEA4
.string "H07P04c\0"
.align 2, 0

.global gUnknown_811AEAC
gUnknown_811AEAC: @ 811AEAC
.string "H07P04\0"
.align 2, 0

.global gUnknown_811AEB4
gUnknown_811AEB4: @ 811AEB4
.string "H07P03m\0"
.align 2, 0

.global gUnknown_811AEBC
gUnknown_811AEBC: @ 811AEBC
.string "H07P03c\0"
.align 2, 0

.global gUnknown_811AEC4
gUnknown_811AEC4: @ 811AEC4
.string "H07P03\0"
.align 2, 0

.global gUnknown_811AECC
gUnknown_811AECC: @ 811AECC
.string "H07P02m\0"
.align 2, 0

.global gUnknown_811AED4
gUnknown_811AED4: @ 811AED4
.string "H07P02c\0"
.align 2, 0

.global gUnknown_811AEDC
gUnknown_811AEDC: @ 811AEDC
.string "H07P02\0"
.align 2, 0

.global gUnknown_811AEE4
gUnknown_811AEE4: @ 811AEE4
.string "H07P01m\0"
.align 2, 0

.global gUnknown_811AEEC
gUnknown_811AEEC: @ 811AEEC
.string "H07P01c\0"
.align 2, 0

.global gUnknown_811AEF4
gUnknown_811AEF4: @ 811AEF4
.string "H07P01\0"
.align 2, 0

.global gUnknown_811AEFC
gUnknown_811AEFC: @ 811AEFC
.string "H06P06m\0"
.align 2, 0

.global gUnknown_811AF04
gUnknown_811AF04: @ 811AF04
.string "H06P06c\0"
.align 2, 0

.global gUnknown_811AF0C
gUnknown_811AF0C: @ 811AF0C
.string "H06P06\0"
.align 2, 0

.global gUnknown_811AF14
gUnknown_811AF14: @ 811AF14
.string "H06P051\0"
.align 2, 0

.global gUnknown_811AF1C
gUnknown_811AF1C: @ 811AF1C
.string "H06P05m\0"
.align 2, 0

.global gUnknown_811AF24
gUnknown_811AF24: @ 811AF24
.string "H06P05c\0"
.align 2, 0

.global gUnknown_811AF2C
gUnknown_811AF2C: @ 811AF2C
.string "H06P05\0"
.align 2, 0

.global gUnknown_811AF34
gUnknown_811AF34: @ 811AF34
.string "H06P04m\0"
.align 2, 0

.global gUnknown_811AF3C
gUnknown_811AF3C: @ 811AF3C
.string "H06P04c\0"
.align 2, 0

.global gUnknown_811AF44
gUnknown_811AF44: @ 811AF44
.string "H06P04\0"
.align 2, 0

.global gUnknown_811AF4C
gUnknown_811AF4C: @ 811AF4C
.string "H06P03m\0"
.align 2, 0

.global gUnknown_811AF54
gUnknown_811AF54: @ 811AF54
.string "H06P03c\0"
.align 2, 0

.global gUnknown_811AF5C
gUnknown_811AF5C: @ 811AF5C
.string "H06P03\0"
.align 2, 0

.global gUnknown_811AF64
gUnknown_811AF64: @ 811AF64
.string "H06P02m\0"
.align 2, 0

.global gUnknown_811AF6C
gUnknown_811AF6C: @ 811AF6C
.string "H06P02c\0"
.align 2, 0

.global gUnknown_811AF74
gUnknown_811AF74: @ 811AF74
.string "H06P02\0"
.align 2, 0

.global gUnknown_811AF7C
gUnknown_811AF7C: @ 811AF7C
.string "H06P01m\0"
.align 2, 0

.global gUnknown_811AF84
gUnknown_811AF84: @ 811AF84
.string "H06P01c\0"
.align 2, 0

.global gUnknown_811AF8C
gUnknown_811AF8C: @ 811AF8C
.string "H06P01\0"
.align 2, 0

.global gUnknown_811AF94
gUnknown_811AF94: @ 811AF94
.string "H05P02m\0"
.align 2, 0

.global gUnknown_811AF9C
gUnknown_811AF9C: @ 811AF9C
.string "H05P02c\0"
.align 2, 0

.global gUnknown_811AFA4
gUnknown_811AFA4: @ 811AFA4
.string "H05P02\0"
.align 2, 0

.global gUnknown_811AFAC
gUnknown_811AFAC: @ 811AFAC
.string "H05P01m\0"
.align 2, 0

.global gUnknown_811AFB4
gUnknown_811AFB4: @ 811AFB4
.string "H05P01c\0"
.align 2, 0

.global gUnknown_811AFBC
gUnknown_811AFBC: @ 811AFBC
.string "H05P01\0"
.align 2, 0

.global gUnknown_811AFC4
gUnknown_811AFC4: @ 811AFC4
.string "H04P02m\0"
.align 2, 0

.global gUnknown_811AFCC
gUnknown_811AFCC: @ 811AFCC
.string "H04P02c\0"
.align 2, 0

.global gUnknown_811AFD4
gUnknown_811AFD4: @ 811AFD4
.string "H04P02\0"
.align 2, 0

.global gUnknown_811AFDC
gUnknown_811AFDC: @ 811AFDC
.string "H04P01m\0"
.align 2, 0

.global gUnknown_811AFE4
gUnknown_811AFE4: @ 811AFE4
.string "H04P01c\0"
.align 2, 0

.global gUnknown_811AFEC
gUnknown_811AFEC: @ 811AFEC
.string "H04P01\0"
.align 2, 0

.global gUnknown_811AFF4
gUnknown_811AFF4: @ 811AFF4
.string "H03P01m\0"
.align 2, 0

.global gUnknown_811AFFC
gUnknown_811AFFC: @ 811AFFC
.string "H03P01c\0"
.align 2, 0

.global gUnknown_811B004
gUnknown_811B004: @ 811B004
.string "H03P01\0"
.align 2, 0

.global gUnknown_811B00C
gUnknown_811B00C: @ 811B00C
.string "H02P03W1\0"
.align 2, 0

.global gUnknown_811B018
gUnknown_811B018: @ 811B018
.string "H02P03Wm\0"
.align 2, 0

.global gUnknown_811B024
gUnknown_811B024: @ 811B024
.string "H02P03Wc\0"
.align 2, 0

.global gUnknown_811B030
gUnknown_811B030: @ 811B030
.string "H02P03W\0"
.align 2, 0

.global gUnknown_811B038
gUnknown_811B038: @ 811B038
.string "H02P03m\0"
.align 2, 0

.global gUnknown_811B040
gUnknown_811B040: @ 811B040
.string "H02P03c\0"
.align 2, 0

.global gUnknown_811B048
gUnknown_811B048: @ 811B048
.string "H02P03\0"
.align 2, 0

.global gUnknown_811B050
gUnknown_811B050: @ 811B050
.string "H02P02Wm\0"
.align 2, 0

.global gUnknown_811B05C
gUnknown_811B05C: @ 811B05C
.string "H02P02Wc\0"
.align 2, 0

.global gUnknown_811B068
gUnknown_811B068: @ 811B068
.string "H02P02W\0"
.align 2, 0

.global gUnknown_811B070
gUnknown_811B070: @ 811B070
.string "H02P02m\0"
.align 2, 0

.global gUnknown_811B078
gUnknown_811B078: @ 811B078
.string "H02P02c\0"
.align 2, 0

.global gUnknown_811B080
gUnknown_811B080: @ 811B080
.string "H02P02\0"
.align 2, 0

.global gUnknown_811B088
gUnknown_811B088: @ 811B088
.string "H02P01W1\0"
.align 2, 0

.global gUnknown_811B094
gUnknown_811B094: @ 811B094
.string "H02P01Wm\0"
.align 2, 0

.global gUnknown_811B0A0
gUnknown_811B0A0: @ 811B0A0
.string "H02P01Wc\0"
.align 2, 0

.global gUnknown_811B0AC
gUnknown_811B0AC: @ 811B0AC
.string "H02P01W\0"
.align 2, 0

.global gUnknown_811B0B4
gUnknown_811B0B4: @ 811B0B4
.string "H02P01m\0"
.align 2, 0

.global gUnknown_811B0BC
gUnknown_811B0BC: @ 811B0BC
.string "H02P01c\0"
.align 2, 0

.global gUnknown_811B0C4
gUnknown_811B0C4: @ 811B0C4
.string "H02P01\0"
.align 2, 0

.global gUnknown_811B0CC
gUnknown_811B0CC: @ 811B0CC
.string "H01P03m\0"
.align 2, 0

.global gUnknown_811B0D4
gUnknown_811B0D4: @ 811B0D4
.string "H01P03c\0"
.align 2, 0

.global gUnknown_811B0DC
gUnknown_811B0DC: @ 811B0DC
.string "H01P03\0"
.align 2, 0

.global gUnknown_811B0E4
gUnknown_811B0E4: @ 811B0E4
.string "H01P02m\0"
.align 2, 0

.global gUnknown_811B0EC
gUnknown_811B0EC: @ 811B0EC
.string "H01P02c\0"
.align 2, 0

.global gUnknown_811B0F4
gUnknown_811B0F4: @ 811B0F4
.string "H01P02\0"
.align 2, 0

.global gUnknown_811B0FC
gUnknown_811B0FC: @ 811B0FC
.string "H01P01W1\0"
.align 2, 0

.global gUnknown_811B108
gUnknown_811B108: @ 811B108
.string "H01P01Wm\0"
.align 2, 0

.global gUnknown_811B114
gUnknown_811B114: @ 811B114
.string "H01P01Wc\0"
.align 2, 0

.global gUnknown_811B120
gUnknown_811B120: @ 811B120
.string "H01P01W\0"
.align 2, 0

.global gUnknown_811B128
gUnknown_811B128: @ 811B128
.string "H01P01m\0"
.align 2, 0

.global gUnknown_811B130
gUnknown_811B130: @ 811B130
.string "H01P01c\0"
.align 2, 0

.global gUnknown_811B138
gUnknown_811B138: @ 811B138
.string "H01P01\0"
.align 2, 0

.global gUnknown_811B140
gUnknown_811B140: @ 811B140
.string "B16P02C\0"
.align 2, 0

.global gUnknown_811B148
gUnknown_811B148: @ 811B148
.string "B16P02B\0"
.align 2, 0

.global gUnknown_811B150
gUnknown_811B150: @ 811B150
.string "B16P02A\0"
.align 2, 0

.global gUnknown_811B158
gUnknown_811B158: @ 811B158
.string "B16P01C1\0"
.align 2, 0

.global gUnknown_811B164
gUnknown_811B164: @ 811B164
.string "B16P01Cm\0"
.align 2, 0

.global gUnknown_811B170
gUnknown_811B170: @ 811B170
.string "B16P01Cc\0"
.align 2, 0

.global gUnknown_811B17C
gUnknown_811B17C: @ 811B17C
.string "B16P01C\0"
.align 2, 0

.global gUnknown_811B184
gUnknown_811B184: @ 811B184
.string "B16P01B3\0"
.align 2, 0

.global gUnknown_811B190
gUnknown_811B190: @ 811B190
.string "B16P01B\0"
.align 2, 0

.global gUnknown_811B198
gUnknown_811B198: @ 811B198
.string "B16P01A\0"
.align 2, 0

.global gUnknown_811B1A0
gUnknown_811B1A0: @ 811B1A0
.string "B15P02C\0"
.align 2, 0

.global gUnknown_811B1A8
gUnknown_811B1A8: @ 811B1A8
.string "B15P02B\0"
.align 2, 0

.global gUnknown_811B1B0
gUnknown_811B1B0: @ 811B1B0
.string "B15P02A\0"
.align 2, 0

.global gUnknown_811B1B8
gUnknown_811B1B8: @ 811B1B8
.string "B15P01C1\0"
.align 2, 0

.global gUnknown_811B1C4
gUnknown_811B1C4: @ 811B1C4
.string "B15P01Cm\0"
.align 2, 0

.global gUnknown_811B1D0
gUnknown_811B1D0: @ 811B1D0
.string "B15P01Cc\0"
.align 2, 0

.global gUnknown_811B1DC
gUnknown_811B1DC: @ 811B1DC
.string "B15P01C\0"
.align 2, 0

.global gUnknown_811B1E4
gUnknown_811B1E4: @ 811B1E4
.string "B15P01B3\0"
.align 2, 0

.global gUnknown_811B1F0
gUnknown_811B1F0: @ 811B1F0
.string "B15P01B\0"
.align 2, 0

.global gUnknown_811B1F8
gUnknown_811B1F8: @ 811B1F8
.string "B15P01A\0"
.align 2, 0

.global gUnknown_811B200
gUnknown_811B200: @ 811B200
.string "B14P02Cm\0"
.align 2, 0

.global gUnknown_811B20C
gUnknown_811B20C: @ 811B20C
.string "B14P02Cc\0"
.align 2, 0

.global gUnknown_811B218
gUnknown_811B218: @ 811B218
.string "B14P02C\0"
.align 2, 0

.global gUnknown_811B220
gUnknown_811B220: @ 811B220
.string "B14P02Bm\0"
.align 2, 0

.global gUnknown_811B22C
gUnknown_811B22C: @ 811B22C
.string "B14P02B\0"
.align 2, 0

.global gUnknown_811B234
gUnknown_811B234: @ 811B234
.string "B14P02Am\0"
.align 2, 0

.global gUnknown_811B240
gUnknown_811B240: @ 811B240
.string "B14P02c\0"
.align 2, 0

.global gUnknown_811B248
gUnknown_811B248: @ 811B248
.string "B14P02A\0"
.align 2, 0

.global gUnknown_811B250
gUnknown_811B250: @ 811B250
.string "B14P01C1\0"
.align 2, 0

.global gUnknown_811B25C
gUnknown_811B25C: @ 811B25C
.string "B14P01Cm\0"
.align 2, 0

.global gUnknown_811B268
gUnknown_811B268: @ 811B268
.string "B14P01Cc\0"
.align 2, 0

.global gUnknown_811B274
gUnknown_811B274: @ 811B274
.string "B14P01C\0"
.align 2, 0

.global gUnknown_811B27C
gUnknown_811B27C: @ 811B27C
.string "B14P01B3\0"
.align 2, 0

.global gUnknown_811B288
gUnknown_811B288: @ 811B288
.string "B14P01B1\0"
.align 2, 0

.global gUnknown_811B294
gUnknown_811B294: @ 811B294
.string "B14P01Bm\0"
.align 2, 0

.global gUnknown_811B2A0
gUnknown_811B2A0: @ 811B2A0
.string "B14P01Bc\0"
.align 2, 0

.global gUnknown_811B2AC
gUnknown_811B2AC: @ 811B2AC
.string "B14P01B\0"
.align 2, 0

.global gUnknown_811B2B4
gUnknown_811B2B4: @ 811B2B4
.string "B14P01A1\0"
.align 2, 0

.global gUnknown_811B2C0
gUnknown_811B2C0: @ 811B2C0
.string "B14P01Am\0"
.align 2, 0

.global gUnknown_811B2CC
gUnknown_811B2CC: @ 811B2CC
.string "B14P01Ac\0"
.align 2, 0

.global gUnknown_811B2D8
gUnknown_811B2D8: @ 811B2D8
.string "B14P01A\0"
.align 2, 0

.global gUnknown_811B2E0
gUnknown_811B2E0: @ 811B2E0
.string "B13P02C\0"
.align 2, 0

.global gUnknown_811B2E8
gUnknown_811B2E8: @ 811B2E8
.string "B13P02B\0"
.align 2, 0

.global gUnknown_811B2F0
gUnknown_811B2F0: @ 811B2F0
.string "B13P02A\0"
.align 2, 0

.global gUnknown_811B2F8
gUnknown_811B2F8: @ 811B2F8
.string "B13P01C1\0"
.align 2, 0

.global gUnknown_811B304
gUnknown_811B304: @ 811B304
.string "B13P01Cm\0"
.align 2, 0

.global gUnknown_811B310
gUnknown_811B310: @ 811B310
.string "B13P01Cc\0"
.align 2, 0

.global gUnknown_811B31C
gUnknown_811B31C: @ 811B31C
.string "B13P01C\0"
.align 2, 0

.global gUnknown_811B324
gUnknown_811B324: @ 811B324
.string "B13P01B3\0"
.align 2, 0

.global gUnknown_811B330
gUnknown_811B330: @ 811B330
.string "B13P01B\0"
.align 2, 0

.global gUnknown_811B338
gUnknown_811B338: @ 811B338
.string "B13P01A\0"
.align 2, 0

.global gUnknown_811B340
gUnknown_811B340: @ 811B340
.string "B12P02Cm\0"
.align 2, 0

.global gUnknown_811B34C
gUnknown_811B34C: @ 811B34C
.string "B12P02Cc\0"
.align 2, 0

.global gUnknown_811B358
gUnknown_811B358: @ 811B358
.string "B12P02C\0"
.align 2, 0

.global gUnknown_811B360
gUnknown_811B360: @ 811B360
.string "B12P02Bm\0"
.align 2, 0

.global gUnknown_811B36C
gUnknown_811B36C: @ 811B36C
.string "B12P02B\0"
.align 2, 0

.global gUnknown_811B374
gUnknown_811B374: @ 811B374
.string "B12P02Am\0"
.align 2, 0

.global gUnknown_811B380
gUnknown_811B380: @ 811B380
.string "B12P02c\0"
.align 2, 0

.global gUnknown_811B388
gUnknown_811B388: @ 811B388
.string "B12P02A\0"
.align 2, 0

.global gUnknown_811B390
gUnknown_811B390: @ 811B390
.string "B12P01C1\0"
.align 2, 0

.global gUnknown_811B39C
gUnknown_811B39C: @ 811B39C
.string "B12P01Cm\0"
.align 2, 0

.global gUnknown_811B3A8
gUnknown_811B3A8: @ 811B3A8
.string "B12P01Cc\0"
.align 2, 0

.global gUnknown_811B3B4
gUnknown_811B3B4: @ 811B3B4
.string "B12P01C\0"
.align 2, 0

.global gUnknown_811B3BC
gUnknown_811B3BC: @ 811B3BC
.string "B12P01B3\0"
.align 2, 0

.global gUnknown_811B3C8
gUnknown_811B3C8: @ 811B3C8
.string "B12P01B1\0"
.align 2, 0

.global gUnknown_811B3D4
gUnknown_811B3D4: @ 811B3D4
.string "B12P01Bm\0"
.align 2, 0

.global gUnknown_811B3E0
gUnknown_811B3E0: @ 811B3E0
.string "B12P01Bc\0"
.align 2, 0

.global gUnknown_811B3EC
gUnknown_811B3EC: @ 811B3EC
.string "B12P01B\0"
.align 2, 0

.global gUnknown_811B3F4
gUnknown_811B3F4: @ 811B3F4
.string "B12P01A1\0"
.align 2, 0

.global gUnknown_811B400
gUnknown_811B400: @ 811B400
.string "B12P01Am\0"
.align 2, 0

.global gUnknown_811B40C
gUnknown_811B40C: @ 811B40C
.string "B12P01Ac\0"
.align 2, 0

.global gUnknown_811B418
gUnknown_811B418: @ 811B418
.string "B12P01A\0"
.align 2, 0

.global gUnknown_811B420
gUnknown_811B420: @ 811B420
.string "B11P02C\0"
.align 2, 0

.global gUnknown_811B428
gUnknown_811B428: @ 811B428
.string "B11P02B\0"
.align 2, 0

.global gUnknown_811B430
gUnknown_811B430: @ 811B430
.string "B11P02A\0"
.align 2, 0

.global gUnknown_811B438
gUnknown_811B438: @ 811B438
.string "B11P01C1\0"
.align 2, 0

.global gUnknown_811B444
gUnknown_811B444: @ 811B444
.string "B11P01Cm\0"
.align 2, 0

.global gUnknown_811B450
gUnknown_811B450: @ 811B450
.string "B11P01Cc\0"
.align 2, 0

.global gUnknown_811B45C
gUnknown_811B45C: @ 811B45C
.string "B11P01C\0"
.align 2, 0

.global gUnknown_811B464
gUnknown_811B464: @ 811B464
.string "B11P01B3\0"
.align 2, 0

.global gUnknown_811B470
gUnknown_811B470: @ 811B470
.string "B11P01B\0"
.align 2, 0

.global gUnknown_811B478
gUnknown_811B478: @ 811B478
.string "B11P01A\0"
.align 2, 0

.global gUnknown_811B480
gUnknown_811B480: @ 811B480
.string "B10P02C\0"
.align 2, 0

.global gUnknown_811B488
gUnknown_811B488: @ 811B488
.string "B10P02B\0"
.align 2, 0

.global gUnknown_811B490
gUnknown_811B490: @ 811B490
.string "B10P02A\0"
.align 2, 0

.global gUnknown_811B498
gUnknown_811B498: @ 811B498
.string "B10P01C1\0"
.align 2, 0

.global gUnknown_811B4A4
gUnknown_811B4A4: @ 811B4A4
.string "B10P01Cm\0"
.align 2, 0

.global gUnknown_811B4B0
gUnknown_811B4B0: @ 811B4B0
.string "B10P01Cc\0"
.align 2, 0

.global gUnknown_811B4BC
gUnknown_811B4BC: @ 811B4BC
.string "B10P01C\0"
.align 2, 0

.global gUnknown_811B4C4
gUnknown_811B4C4: @ 811B4C4
.string "B10P01B3\0"
.align 2, 0

.global gUnknown_811B4D0
gUnknown_811B4D0: @ 811B4D0
.string "B10P01B\0"
.align 2, 0

.global gUnknown_811B4D8
gUnknown_811B4D8: @ 811B4D8
.string "B10P01A\0"
.align 2, 0

.global gUnknown_811B4E0
gUnknown_811B4E0: @ 811B4E0
.string "B09P02C1\0"
.align 2, 0

.global gUnknown_811B4EC
gUnknown_811B4EC: @ 811B4EC
.string "B09P02Cm\0"
.align 2, 0

.global gUnknown_811B4F8
gUnknown_811B4F8: @ 811B4F8
.string "B09P02Cc\0"
.align 2, 0

.global gUnknown_811B504
gUnknown_811B504: @ 811B504
.string "B09P02C\0"
.align 2, 0

.global gUnknown_811B50C
gUnknown_811B50C: @ 811B50C
.string "B09P02Bm\0"
.align 2, 0

.global gUnknown_811B518
gUnknown_811B518: @ 811B518
.string "B09P02B\0"
.align 2, 0

.global gUnknown_811B520
gUnknown_811B520: @ 811B520
.string "B09P021\0"
.align 2, 0

.global gUnknown_811B528
gUnknown_811B528: @ 811B528
.string "B09P02Am\0"
.align 2, 0

.global gUnknown_811B534
gUnknown_811B534: @ 811B534
.string "B09P02c\0"
.align 2, 0

.global gUnknown_811B53C
gUnknown_811B53C: @ 811B53C
.string "B09P02A\0"
.align 2, 0

.global gUnknown_811B544
gUnknown_811B544: @ 811B544
.string "B09P01C1\0"
.align 2, 0

.global gUnknown_811B550
gUnknown_811B550: @ 811B550
.string "B09P01Cm\0"
.align 2, 0

.global gUnknown_811B55C
gUnknown_811B55C: @ 811B55C
.string "B09P01Cc\0"
.align 2, 0

.global gUnknown_811B568
gUnknown_811B568: @ 811B568
.string "B09P01C\0"
.align 2, 0

.global gUnknown_811B570
gUnknown_811B570: @ 811B570
.string "B09P01B3\0"
.align 2, 0

.global gUnknown_811B57C
gUnknown_811B57C: @ 811B57C
.string "B09P01B1\0"
.align 2, 0

.global gUnknown_811B588
gUnknown_811B588: @ 811B588
.string "B09P01Bm\0"
.align 2, 0

.global gUnknown_811B594
gUnknown_811B594: @ 811B594
.string "B09P01Bc\0"
.align 2, 0

.global gUnknown_811B5A0
gUnknown_811B5A0: @ 811B5A0
.string "B09P01B\0"
.align 2, 0

.global gUnknown_811B5A8
gUnknown_811B5A8: @ 811B5A8
.string "B09P01A1\0"
.align 2, 0

.global gUnknown_811B5B4
gUnknown_811B5B4: @ 811B5B4
.string "B09P01Am\0"
.align 2, 0

.global gUnknown_811B5C0
gUnknown_811B5C0: @ 811B5C0
.string "B09P01Ac\0"
.align 2, 0

.global gUnknown_811B5CC
gUnknown_811B5CC: @ 811B5CC
.string "B09P01A\0"
.align 2, 0

.global gUnknown_811B5D4
gUnknown_811B5D4: @ 811B5D4
.string "B08P02C\0"
.align 2, 0

.global gUnknown_811B5DC
gUnknown_811B5DC: @ 811B5DC
.string "B08P02B\0"
.align 2, 0

.global gUnknown_811B5E4
gUnknown_811B5E4: @ 811B5E4
.string "B08P02A\0"
.align 2, 0

.global gUnknown_811B5EC
gUnknown_811B5EC: @ 811B5EC
.string "B08P01C1\0"
.align 2, 0

.global gUnknown_811B5F8
gUnknown_811B5F8: @ 811B5F8
.string "B08P01Cm\0"
.align 2, 0

.global gUnknown_811B604
gUnknown_811B604: @ 811B604
.string "B08P01Cc\0"
.align 2, 0

.global gUnknown_811B610
gUnknown_811B610: @ 811B610
.string "B08P01C\0"
.align 2, 0

.global gUnknown_811B618
gUnknown_811B618: @ 811B618
.string "B08P01B3\0"
.align 2, 0

.global gUnknown_811B624
gUnknown_811B624: @ 811B624
.string "B08P01B\0"
.align 2, 0

.global gUnknown_811B62C
gUnknown_811B62C: @ 811B62C
.string "B08P01A\0"
.align 2, 0

.global gUnknown_811B634
gUnknown_811B634: @ 811B634
.string "B07P02C\0"
.align 2, 0

.global gUnknown_811B63C
gUnknown_811B63C: @ 811B63C
.string "B07P02B\0"
.align 2, 0

.global gUnknown_811B644
gUnknown_811B644: @ 811B644
.string "B07P02A\0"
.align 2, 0

.global gUnknown_811B64C
gUnknown_811B64C: @ 811B64C
.string "B07P01C1\0"
.align 2, 0

.global gUnknown_811B658
gUnknown_811B658: @ 811B658
.string "B07P01Cm\0"
.align 2, 0

.global gUnknown_811B664
gUnknown_811B664: @ 811B664
.string "B07P01Cc\0"
.align 2, 0

.global gUnknown_811B670
gUnknown_811B670: @ 811B670
.string "B07P01C\0"
.align 2, 0

.global gUnknown_811B678
gUnknown_811B678: @ 811B678
.string "B07P01B3\0"
.align 2, 0

.global gUnknown_811B684
gUnknown_811B684: @ 811B684
.string "B07P01B\0"
.align 2, 0

.global gUnknown_811B68C
gUnknown_811B68C: @ 811B68C
.string "B07P01A\0"
.align 2, 0

.global gUnknown_811B694
gUnknown_811B694: @ 811B694
.string "B06P02C\0"
.align 2, 0

.global gUnknown_811B69C
gUnknown_811B69C: @ 811B69C
.string "B06P02B\0"
.align 2, 0

.global gUnknown_811B6A4
gUnknown_811B6A4: @ 811B6A4
.string "B06P02A\0"
.align 2, 0

.global gUnknown_811B6AC
gUnknown_811B6AC: @ 811B6AC
.string "B06P01C1\0"
.align 2, 0

.global gUnknown_811B6B8
gUnknown_811B6B8: @ 811B6B8
.string "B06P01Cm\0"
.align 2, 0

.global gUnknown_811B6C4
gUnknown_811B6C4: @ 811B6C4
.string "B06P01Cc\0"
.align 2, 0

.global gUnknown_811B6D0
gUnknown_811B6D0: @ 811B6D0
.string "B06P01C\0"
.align 2, 0

.global gUnknown_811B6D8
gUnknown_811B6D8: @ 811B6D8
.string "B06P01B3\0"
.align 2, 0

.global gUnknown_811B6E4
gUnknown_811B6E4: @ 811B6E4
.string "B06P01B\0"
.align 2, 0

.global gUnknown_811B6EC
gUnknown_811B6EC: @ 811B6EC
.string "B06P01A\0"
.align 2, 0

.global gUnknown_811B6F4
gUnknown_811B6F4: @ 811B6F4
.string "B05P02Cm\0"
.align 2, 0

.global gUnknown_811B700
gUnknown_811B700: @ 811B700
.string "B05P02Cc\0"
.align 2, 0

.global gUnknown_811B70C
gUnknown_811B70C: @ 811B70C
.string "B05P02C\0"
.align 2, 0

.global gUnknown_811B714
gUnknown_811B714: @ 811B714
.string "B05P02Bm\0"
.align 2, 0

.global gUnknown_811B720
gUnknown_811B720: @ 811B720
.string "B05P02B\0"
.align 2, 0

.global gUnknown_811B728
gUnknown_811B728: @ 811B728
.string "B05P02Am\0"
.align 2, 0

.global gUnknown_811B734
gUnknown_811B734: @ 811B734
.string "B05P02c\0"
.align 2, 0

.global gUnknown_811B73C
gUnknown_811B73C: @ 811B73C
.string "B05P02A\0"
.align 2, 0

.global gUnknown_811B744
gUnknown_811B744: @ 811B744
.string "B05P01C1\0"
.align 2, 0

.global gUnknown_811B750
gUnknown_811B750: @ 811B750
.string "B05P01Cm\0"
.align 2, 0

.global gUnknown_811B75C
gUnknown_811B75C: @ 811B75C
.string "B05P01Cc\0"
.align 2, 0

.global gUnknown_811B768
gUnknown_811B768: @ 811B768
.string "B05P01C\0"
.align 2, 0

.global gUnknown_811B770
gUnknown_811B770: @ 811B770
.string "B05P01B3\0"
.align 2, 0

.global gUnknown_811B77C
gUnknown_811B77C: @ 811B77C
.string "B05P01B1\0"
.align 2, 0

.global gUnknown_811B788
gUnknown_811B788: @ 811B788
.string "B05P01Bm\0"
.align 2, 0

.global gUnknown_811B794
gUnknown_811B794: @ 811B794
.string "B05P01Bc\0"
.align 2, 0

.global gUnknown_811B7A0
gUnknown_811B7A0: @ 811B7A0
.string "B05P01B\0"
.align 2, 0

.global gUnknown_811B7A8
gUnknown_811B7A8: @ 811B7A8
.string "B05P01A1\0"
.align 2, 0

.global gUnknown_811B7B4
gUnknown_811B7B4: @ 811B7B4
.string "B05P01Am\0"
.align 2, 0

.global gUnknown_811B7C0
gUnknown_811B7C0: @ 811B7C0
.string "B05P01Ac\0"
.align 2, 0

.global gUnknown_811B7CC
gUnknown_811B7CC: @ 811B7CC
.string "B05P01A\0"
.align 2, 0

.global gUnknown_811B7D4
gUnknown_811B7D4: @ 811B7D4
.string "B04P02C\0"
.align 2, 0

.global gUnknown_811B7DC
gUnknown_811B7DC: @ 811B7DC
.string "B04P02B\0"
.align 2, 0

.global gUnknown_811B7E4
gUnknown_811B7E4: @ 811B7E4
.string "B04P02A\0"
.align 2, 0

.global gUnknown_811B7EC
gUnknown_811B7EC: @ 811B7EC
.string "B04P01C1\0"
.align 2, 0

.global gUnknown_811B7F8
gUnknown_811B7F8: @ 811B7F8
.string "B04P01Cm\0"
.align 2, 0

.global gUnknown_811B804
gUnknown_811B804: @ 811B804
.string "B04P01Cc\0"
.align 2, 0

.global gUnknown_811B810
gUnknown_811B810: @ 811B810
.string "B04P01C\0"
.align 2, 0

.global gUnknown_811B818
gUnknown_811B818: @ 811B818
.string "B04P01B3\0"
.align 2, 0

.global gUnknown_811B824
gUnknown_811B824: @ 811B824
.string "B04P01B\0"
.align 2, 0

.global gUnknown_811B82C
gUnknown_811B82C: @ 811B82C
.string "B04P01A\0"
.align 2, 0

.global gUnknown_811B834
gUnknown_811B834: @ 811B834
.string "B03P02C\0"
.align 2, 0

.global gUnknown_811B83C
gUnknown_811B83C: @ 811B83C
.string "B03P02B\0"
.align 2, 0

.global gUnknown_811B844
gUnknown_811B844: @ 811B844
.string "B03P02A\0"
.align 2, 0

.global gUnknown_811B84C
gUnknown_811B84C: @ 811B84C
.string "B03P01C1\0"
.align 2, 0

.global gUnknown_811B858
gUnknown_811B858: @ 811B858
.string "B03P01Cm\0"
.align 2, 0

.global gUnknown_811B864
gUnknown_811B864: @ 811B864
.string "B03P01Cc\0"
.align 2, 0

.global gUnknown_811B870
gUnknown_811B870: @ 811B870
.string "B03P01C\0"
.align 2, 0

.global gUnknown_811B878
gUnknown_811B878: @ 811B878
.string "B03P01B3\0"
.align 2, 0

.global gUnknown_811B884
gUnknown_811B884: @ 811B884
.string "B03P01B\0"
.align 2, 0

.global gUnknown_811B88C
gUnknown_811B88C: @ 811B88C
.string "B03P01A\0"
.align 2, 0

.global gUnknown_811B894
gUnknown_811B894: @ 811B894
.string "B02P02C\0"
.align 2, 0

.global gUnknown_811B89C
gUnknown_811B89C: @ 811B89C
.string "B02P02B\0"
.align 2, 0

.global gUnknown_811B8A4
gUnknown_811B8A4: @ 811B8A4
.string "B02P02A\0"
.align 2, 0

.global gUnknown_811B8AC
gUnknown_811B8AC: @ 811B8AC
.string "B02P01C1\0"
.align 2, 0

.global gUnknown_811B8B8
gUnknown_811B8B8: @ 811B8B8
.string "B02P01Cm\0"
.align 2, 0

.global gUnknown_811B8C4
gUnknown_811B8C4: @ 811B8C4
.string "B02P01Cc\0"
.align 2, 0

.global gUnknown_811B8D0
gUnknown_811B8D0: @ 811B8D0
.string "B02P01C\0"
.align 2, 0

.global gUnknown_811B8D8
gUnknown_811B8D8: @ 811B8D8
.string "B02P01B3\0"
.align 2, 0

.global gUnknown_811B8E4
gUnknown_811B8E4: @ 811B8E4
.string "B02P01B\0"
.align 2, 0

.global gUnknown_811B8EC
gUnknown_811B8EC: @ 811B8EC
.string "B02P01A\0"
.align 2, 0

.global gUnknown_811B8F4
gUnknown_811B8F4: @ 811B8F4
.string "B01P02Cm\0"
.align 2, 0

.global gUnknown_811B900
gUnknown_811B900: @ 811B900
.string "B01P02Cc\0"
.align 2, 0

.global gUnknown_811B90C
gUnknown_811B90C: @ 811B90C
.string "B01P02C\0"
.align 2, 0

.global gUnknown_811B914
gUnknown_811B914: @ 811B914
.string "B01P02Bm\0"
.align 2, 0

.global gUnknown_811B920
gUnknown_811B920: @ 811B920
.string "B01P02B\0"
.align 2, 0

.global gUnknown_811B928
gUnknown_811B928: @ 811B928
.string "B01P02Am\0"
.align 2, 0

.global gUnknown_811B934
gUnknown_811B934: @ 811B934
.string "B01P02c\0"
.align 2, 0

.global gUnknown_811B93C
gUnknown_811B93C: @ 811B93C
.string "B01P02A\0"
.align 2, 0

.global gUnknown_811B944
gUnknown_811B944: @ 811B944
.string "B01P01C1\0"
.align 2, 0

.global gUnknown_811B950
gUnknown_811B950: @ 811B950
.string "B01P01Cm\0"
.align 2, 0

.global gUnknown_811B95C
gUnknown_811B95C: @ 811B95C
.string "B01P01Cc\0"
.align 2, 0

.global gUnknown_811B968
gUnknown_811B968: @ 811B968
.string "B01P01C\0"
.align 2, 0

.global gUnknown_811B970
gUnknown_811B970: @ 811B970
.string "B01P01B3\0"
.align 2, 0

.global gUnknown_811B97C
gUnknown_811B97C: @ 811B97C
.string "B01P01B1\0"
.align 2, 0

.global gUnknown_811B988
gUnknown_811B988: @ 811B988
.string "B01P01Bm\0"
.align 2, 0

.global gUnknown_811B994
gUnknown_811B994: @ 811B994
.string "B01P01Bc\0"
.align 2, 0

.global gUnknown_811B9A0
gUnknown_811B9A0: @ 811B9A0
.string "B01P01B\0"
.align 2, 0

.global gUnknown_811B9A8
gUnknown_811B9A8: @ 811B9A8
.string "B01P01A1\0"
.align 2, 0

.global gUnknown_811B9B4
gUnknown_811B9B4: @ 811B9B4
.string "B01P01Am\0"
.align 2, 0

.global gUnknown_811B9C0
gUnknown_811B9C0: @ 811B9C0
.string "B01P01Ac\0"
.align 2, 0

.global gUnknown_811B9CC
gUnknown_811B9CC: @ 811B9CC
.string "B01P01A\0"
.align 2, 0

.global gUnknown_811B9D4
gUnknown_811B9D4: @ 811B9D4
.string "T01P07Wm\0"
.align 2, 0

.global gUnknown_811B9E0
gUnknown_811B9E0: @ 811B9E0
.string "T01P07Wc\0"
.align 2, 0

.global gUnknown_811B9EC
gUnknown_811B9EC: @ 811B9EC
.string "T01P07W\0"
.align 2, 0

.global gUnknown_811B9F4
gUnknown_811B9F4: @ 811B9F4
.string "T01P07m\0"
.align 2, 0

.global gUnknown_811B9FC
gUnknown_811B9FC: @ 811B9FC
.string "T01P07c\0"
.align 2, 0

.global gUnknown_811BA04
gUnknown_811BA04: @ 811BA04
.string "T01P07\0"
.align 2, 0

.global gUnknown_811BA0C
gUnknown_811BA0C: @ 811BA0C
.string "T01P06m\0"
.align 2, 0

.global gUnknown_811BA14
gUnknown_811BA14: @ 811BA14
.string "T01P06c\0"
.align 2, 0

.global gUnknown_811BA1C
gUnknown_811BA1C: @ 811BA1C
.string "T01P06\0"
.align 2, 0

.global gUnknown_811BA24
gUnknown_811BA24: @ 811BA24
.string "T01P051\0"
.align 2, 0

.global gUnknown_811BA2C
gUnknown_811BA2C: @ 811BA2C
.string "T01P05m\0"
.align 2, 0

.global gUnknown_811BA34
gUnknown_811BA34: @ 811BA34
.string "T01P05c\0"
.align 2, 0

.global gUnknown_811BA3C
gUnknown_811BA3C: @ 811BA3C
.string "T01P05\0"
.align 2, 0

.global gUnknown_811BA44
gUnknown_811BA44: @ 811BA44
.string "T01P04m\0"
.align 2, 0

.global gUnknown_811BA4C
gUnknown_811BA4C: @ 811BA4C
.string "T01P04c\0"
.align 2, 0

.global gUnknown_811BA54
gUnknown_811BA54: @ 811BA54
.string "T01P04\0"
.align 2, 0

.global gUnknown_811BA5C
gUnknown_811BA5C: @ 811BA5C
.string "T01P031\0"
.align 2, 0

.global gUnknown_811BA64
gUnknown_811BA64: @ 811BA64
.string "T01P03m\0"
.align 2, 0

.global gUnknown_811BA6C
gUnknown_811BA6C: @ 811BA6C
.string "T01P03c\0"
.align 2, 0

.global gUnknown_811BA74
gUnknown_811BA74: @ 811BA74
.string "T01P03\0"
.align 2, 0

.global gUnknown_811BA7C
gUnknown_811BA7C: @ 811BA7C
.string "T01P02Bm\0"
.align 2, 0

.global gUnknown_811BA88
gUnknown_811BA88: @ 811BA88
.string "T01P02B\0"
.align 2, 0

.global gUnknown_811BA90
gUnknown_811BA90: @ 811BA90
.string "T01P021\0"
.align 2, 0

.global gUnknown_811BA98
gUnknown_811BA98: @ 811BA98
.string "T01P02Am\0"
.align 2, 0

.global gUnknown_811BAA4
gUnknown_811BAA4: @ 811BAA4
.string "T01P02c\0"
.align 2, 0

.global gUnknown_811BAAC
gUnknown_811BAAC: @ 811BAAC
.string "T01P02A\0"
.align 2, 0

.global gUnknown_811BAB4
gUnknown_811BAB4: @ 811BAB4
.string "T01P011\0"
.align 2, 0

.global gUnknown_811BABC
gUnknown_811BABC: @ 811BABC
.string "T01P01m\0"
.align 2, 0

.global gUnknown_811BAC4
gUnknown_811BAC4: @ 811BAC4
.string "T01P01c\0"
.align 2, 0

.global gUnknown_811BACC
gUnknown_811BACC: @ 811BACC
.string "T01P01\0"
.align 2, 0

.global gUnknown_811BAD4
gUnknown_811BAD4: @ 811BAD4
.string "T00P01m\0"
.align 2, 0

.global gUnknown_811BADC
gUnknown_811BADC: @ 811BADC
.string "T00P01c\0"
.align 2, 0

.global gUnknown_811BAE4
gUnknown_811BAE4: @ 811BAE4
.byte 0x54, 0x30, 0x30, 0x50, 0x30, 0x31, 0x00, 0x00, 0x70, 0x6b, 0x73, 0x64
.byte 0x69, 0x72, 0x30, 0x00

.global gGroundConversion_811BAF4
gGroundConversion_811BAF4: @ 811BAF4
@ replacing .incbin "baserom.gba", 0x0011baf4, 0x2764
.byte 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x09, 0x00
.4byte gUnknown_811E230
.byte 0x01, 0x00, 0x02, 0x00, 0x01, 0x00, 0x09, 0x00
.4byte gUnknown_811E210
.byte 0x01, 0x00, 0x03, 0x00, 0x02, 0x00, 0x09, 0x00
.4byte gUnknown_811E1F0
.byte 0x01, 0x00, 0x03, 0x00, 0x03, 0x00, 0x09, 0x00
.4byte gUnknown_811E1D0
.byte 0x05, 0x00, 0x04, 0x00, 0x04, 0x00, 0x09, 0x00
.4byte gUnknown_811E1B0
.byte 0x02, 0x00, 0x05, 0x00
.byte 0x05, 0x00, 0xff, 0xff
.4byte gUnknown_811E190
.byte 0x01, 0x00, 0x06, 0x00, 0x06, 0x00, 0x09, 0x00
.4byte gUnknown_811E170
.byte 0x02, 0x00, 0x07, 0x00, 0x07, 0x00, 0xff, 0xff
.4byte gUnknown_811E150
.byte 0x02, 0x00, 0x08, 0x00, 0x08, 0x00, 0x00, 0x00
.4byte gUnknown_811E130
.byte 0x01, 0x00, 0x0a, 0x00, 0x0a, 0x00, 0x09, 0x00
.4byte gUnknown_811E110
.byte 0x01, 0x00, 0x0a, 0x00, 0x0b, 0x00, 0x09, 0x00
.4byte gUnknown_811E0F0
.byte 0x01, 0x00, 0x0a, 0x00, 0x0c, 0x00, 0x09, 0x00
.4byte gUnknown_811E0D0
.byte 0x02, 0x00, 0x0b, 0x00, 0x0d, 0x00, 0xff, 0xff
.4byte gUnknown_811E0B0
.byte 0x02, 0x00, 0x0b, 0x00
.byte 0x0e, 0x00, 0xff, 0xff
.4byte gUnknown_811E090
.byte 0x02, 0x00, 0x0b, 0x00, 0x0f, 0x00, 0xff, 0xff
.4byte gUnknown_811E070
.byte 0x01, 0x00, 0x0a, 0x00, 0x10, 0x00, 0x09, 0x00
.4byte gUnknown_811E050
.byte 0x01, 0x00, 0x0a, 0x00, 0x11, 0x00, 0x09, 0x00
.4byte gUnknown_811E030
.byte 0x01, 0x00, 0x0a, 0x00, 0x12, 0x00, 0x09, 0x00
.4byte gUnknown_811E010
.byte 0x02, 0x00, 0x0b, 0x00, 0x13, 0x00, 0xff, 0xff
.4byte gUnknown_811DFF0
.byte 0x02, 0x00, 0x0b, 0x00, 0x14, 0x00, 0xff, 0xff
.4byte gUnknown_811DFD0
.byte 0x02, 0x00, 0x0b, 0x00, 0x15, 0x00, 0xff, 0xff
.4byte gUnknown_811DFB0
.byte 0x01, 0x00, 0x0a, 0x00
.byte 0x16, 0x00, 0x09, 0x00
.4byte gUnknown_811DF90
.byte 0x01, 0x00, 0x0a, 0x00, 0x17, 0x00, 0x09, 0x00
.4byte gUnknown_811DF70
.byte 0x01, 0x00, 0x0a, 0x00, 0x18, 0x00, 0x09, 0x00
.4byte gUnknown_811DF50
.byte 0x02, 0x00, 0x0b, 0x00, 0x19, 0x00, 0xff, 0xff
.4byte gUnknown_811DF30
.byte 0x02, 0x00, 0x0b, 0x00, 0x1a, 0x00, 0xff, 0xff
.4byte gUnknown_811DF10
.byte 0x02, 0x00, 0x0b, 0x00, 0x1b, 0x00, 0xff, 0xff
.4byte gUnknown_811DEF0
.byte 0x01, 0x00, 0x0a, 0x00, 0x1c, 0x00, 0x09, 0x00
.4byte gUnknown_811DED0
.byte 0x01, 0x00, 0x0a, 0x00, 0x1d, 0x00, 0x09, 0x00
.4byte gUnknown_811DEB0
.byte 0x01, 0x00, 0x0a, 0x00
.byte 0x1e, 0x00, 0x09, 0x00
.4byte gUnknown_811DE90
.byte 0x02, 0x00, 0x0b, 0x00, 0x1f, 0x00, 0xff, 0xff
.4byte gUnknown_811DE70
.byte 0x02, 0x00, 0x0b, 0x00, 0x20, 0x00, 0xff, 0xff
.4byte gUnknown_811DE50
.byte 0x02, 0x00, 0x0b, 0x00, 0x21, 0x00, 0xff, 0xff
.4byte gUnknown_811DE30
.byte 0x01, 0x00, 0x0a, 0x00, 0x22, 0x00, 0x09, 0x00
.4byte gUnknown_811DE10
.byte 0x01, 0x00, 0x0a, 0x00, 0x23, 0x00, 0x09, 0x00
.4byte gUnknown_811DDF0
.byte 0x01, 0x00, 0x0a, 0x00, 0x24, 0x00, 0x09, 0x00
.4byte gUnknown_811DDD0
.byte 0x02, 0x00, 0x0b, 0x00, 0x25, 0x00, 0xff, 0xff
.4byte gUnknown_811DDB0
.byte 0x02, 0x00, 0x0b, 0x00
.byte 0x26, 0x00, 0xff, 0xff
.4byte gUnknown_811DD90
.byte 0x02, 0x00, 0x0b, 0x00, 0x27, 0x00, 0xff, 0xff
.4byte gUnknown_811DD70
.byte 0x01, 0x00, 0x0a, 0x00, 0x28, 0x00, 0x09, 0x00
.4byte gUnknown_811DD50
.byte 0x01, 0x00, 0x0a, 0x00, 0x29, 0x00, 0x09, 0x00
.4byte gUnknown_811DD30
.byte 0x01, 0x00, 0x0a, 0x00, 0x2a, 0x00, 0x09, 0x00
.4byte gUnknown_811DD10
.byte 0x02, 0x00, 0x0b, 0x00, 0x2b, 0x00, 0xff, 0xff
.4byte gUnknown_811DCF0
.byte 0x02, 0x00, 0x0b, 0x00, 0x2c, 0x00, 0xff, 0xff
.4byte gUnknown_811DCD0
.byte 0x02, 0x00, 0x0b, 0x00, 0x2d, 0x00, 0xff, 0xff
.4byte gUnknown_811DCB0
.byte 0x01, 0x00, 0x0a, 0x00
.byte 0x2e, 0x00, 0x09, 0x00
.4byte gUnknown_811DC90
.byte 0x01, 0x00, 0x0a, 0x00, 0x2f, 0x00, 0x09, 0x00
.4byte gUnknown_811DC70
.byte 0x01, 0x00, 0x0a, 0x00, 0x30, 0x00, 0x09, 0x00
.4byte gUnknown_811DC50
.byte 0x02, 0x00, 0x0b, 0x00, 0x31, 0x00, 0xff, 0xff
.4byte gUnknown_811DC30
.byte 0x02, 0x00, 0x0b, 0x00, 0x32, 0x00, 0xff, 0xff
.4byte gUnknown_811DC10
.byte 0x02, 0x00, 0x0b, 0x00, 0x33, 0x00, 0xff, 0xff
.4byte gUnknown_811DBF0
.byte 0x01, 0x00, 0x0a, 0x00, 0x34, 0x00, 0x09, 0x00
.4byte gUnknown_811DBD0
.byte 0x01, 0x00, 0x0a, 0x00, 0x35, 0x00, 0x09, 0x00
.4byte gUnknown_811DBB0
.byte 0x01, 0x00, 0x0a, 0x00
.byte 0x36, 0x00, 0x09, 0x00
.4byte gUnknown_811DB90
.byte 0x02, 0x00, 0x0b, 0x00, 0x37, 0x00, 0xff, 0xff
.4byte gUnknown_811DB70
.byte 0x02, 0x00, 0x0b, 0x00, 0x38, 0x00, 0xff, 0xff
.4byte gUnknown_811DB50
.byte 0x02, 0x00, 0x0b, 0x00, 0x39, 0x00, 0xff, 0xff
.4byte gUnknown_811DB30
.byte 0x01, 0x00, 0x0a, 0x00, 0x3a, 0x00, 0x09, 0x00
.4byte gUnknown_811DB10
.byte 0x01, 0x00, 0x0a, 0x00, 0x3b, 0x00, 0x09, 0x00
.4byte gUnknown_811DAF0
.byte 0x01, 0x00, 0x0a, 0x00, 0x3c, 0x00, 0x09, 0x00
.4byte gUnknown_811DAD0
.byte 0x02, 0x00, 0x0b, 0x00, 0x3d, 0x00, 0xff, 0xff
.4byte gUnknown_811DAB0
.byte 0x02, 0x00, 0x0b, 0x00
.byte 0x3e, 0x00, 0xff, 0xff
.4byte gUnknown_811DA90
.byte 0x02, 0x00, 0x0b, 0x00, 0x3f, 0x00, 0xff, 0xff
.4byte gUnknown_811DA70
.byte 0x01, 0x00, 0x0a, 0x00, 0x40, 0x00, 0x09, 0x00
.4byte gUnknown_811DA50
.byte 0x01, 0x00, 0x0a, 0x00, 0x41, 0x00, 0x09, 0x00
.4byte gUnknown_811DA30
.byte 0x01, 0x00, 0x0a, 0x00, 0x42, 0x00, 0x09, 0x00
.4byte gUnknown_811DA10
.byte 0x02, 0x00, 0x0b, 0x00, 0x43, 0x00, 0xff, 0xff
.4byte gUnknown_811D9F0
.byte 0x02, 0x00, 0x0b, 0x00, 0x44, 0x00, 0xff, 0xff
.4byte gUnknown_811D9D0
.byte 0x02, 0x00, 0x0b, 0x00, 0x45, 0x00, 0xff, 0xff
.4byte gUnknown_811D9B0
.byte 0x01, 0x00, 0x0a, 0x00
.byte 0x46, 0x00, 0x09, 0x00
.4byte gUnknown_811D990
.byte 0x01, 0x00, 0x0a, 0x00, 0x47, 0x00, 0x09, 0x00
.4byte gUnknown_811D970
.byte 0x01, 0x00, 0x0a, 0x00, 0x48, 0x00, 0x09, 0x00
.4byte gUnknown_811D950
.byte 0x02, 0x00, 0x0b, 0x00, 0x49, 0x00, 0xff, 0xff
.4byte gUnknown_811D930
.byte 0x02, 0x00, 0x0b, 0x00, 0x4a, 0x00, 0xff, 0xff
.4byte gUnknown_811D910
.byte 0x02, 0x00, 0x0b, 0x00, 0x4b, 0x00, 0xff, 0xff
.4byte gUnknown_811D8F0
.byte 0x01, 0x00, 0x0a, 0x00, 0x4c, 0x00, 0x09, 0x00
.4byte gUnknown_811D8D0
.byte 0x01, 0x00, 0x0a, 0x00, 0x4d, 0x00, 0x09, 0x00
.4byte gUnknown_811D8B0
.byte 0x01, 0x00, 0x0a, 0x00
.byte 0x4e, 0x00, 0x09, 0x00
.4byte gUnknown_811D890
.byte 0x02, 0x00, 0x0b, 0x00, 0x4f, 0x00, 0xff, 0xff
.4byte gUnknown_811D870
.byte 0x02, 0x00, 0x0b, 0x00, 0x50, 0x00, 0xff, 0xff
.4byte gUnknown_811D850
.byte 0x02, 0x00, 0x0b, 0x00, 0x51, 0x00, 0xff, 0xff
.4byte gUnknown_811D830
.byte 0x01, 0x00, 0x0a, 0x00, 0x52, 0x00, 0x09, 0x00
.4byte gUnknown_811D810
.byte 0x01, 0x00, 0x0a, 0x00, 0x53, 0x00, 0x09, 0x00
.4byte gUnknown_811D7F0
.byte 0x01, 0x00, 0x0a, 0x00, 0x54, 0x00, 0x09, 0x00
.4byte gUnknown_811D7D0
.byte 0x02, 0x00, 0x0b, 0x00, 0x55, 0x00, 0xff, 0xff
.4byte gUnknown_811D7B0
.byte 0x02, 0x00, 0x0b, 0x00
.byte 0x56, 0x00, 0xff, 0xff
.4byte gUnknown_811D790
.byte 0x02, 0x00, 0x0b, 0x00, 0x57, 0x00, 0xff, 0xff
.4byte gUnknown_811D770
.byte 0x01, 0x00, 0x0a, 0x00, 0x58, 0x00, 0x09, 0x00
.4byte gUnknown_811D750
.byte 0x01, 0x00, 0x0a, 0x00, 0x59, 0x00, 0x09, 0x00
.4byte gUnknown_811D730
.byte 0x01, 0x00, 0x0a, 0x00, 0x5a, 0x00, 0x09, 0x00
.4byte gUnknown_811D710
.byte 0x02, 0x00, 0x0b, 0x00, 0x5b, 0x00, 0xff, 0xff
.4byte gUnknown_811D6F0
.byte 0x02, 0x00, 0x0b, 0x00, 0x5c, 0x00, 0xff, 0xff
.4byte gUnknown_811D6D0
.byte 0x02, 0x00, 0x0b, 0x00, 0x5d, 0x00, 0xff, 0xff
.4byte gUnknown_811D6B0
.byte 0x01, 0x00, 0x0a, 0x00
.byte 0x5e, 0x00, 0x09, 0x00
.4byte gUnknown_811D690
.byte 0x01, 0x00, 0x0a, 0x00, 0x5f, 0x00, 0x09, 0x00
.4byte gUnknown_811D670
.byte 0x01, 0x00, 0x0a, 0x00, 0x60, 0x00, 0x09, 0x00
.4byte gUnknown_811D650
.byte 0x02, 0x00, 0x0b, 0x00, 0x61, 0x00, 0xff, 0xff
.4byte gUnknown_811D630
.byte 0x02, 0x00, 0x0b, 0x00, 0x62, 0x00, 0xff, 0xff
.4byte gUnknown_811D610
.byte 0x02, 0x00, 0x0b, 0x00, 0x63, 0x00, 0xff, 0xff
.4byte gUnknown_811D5F0
.byte 0x01, 0x00, 0x0a, 0x00, 0x64, 0x00, 0x09, 0x00
.4byte gUnknown_811D5D0
.byte 0x01, 0x00, 0x0a, 0x00, 0x65, 0x00, 0x09, 0x00
.4byte gUnknown_811D5B0
.byte 0x01, 0x00, 0x0a, 0x00
.byte 0x66, 0x00, 0x09, 0x00
.4byte gUnknown_811D590
.byte 0x02, 0x00, 0x0b, 0x00, 0x67, 0x00, 0xff, 0xff
.4byte gUnknown_811D570
.byte 0x02, 0x00, 0x0b, 0x00, 0x68, 0x00, 0xff, 0xff
.4byte gUnknown_811D550
.byte 0x02, 0x00, 0x0b, 0x00, 0x69, 0x00, 0xff, 0xff
.4byte gUnknown_811D530
.byte 0x01, 0x00, 0x09, 0x00, 0x6a, 0x00, 0x01, 0x00
.4byte gUnknown_811D510
.byte 0x01, 0x00, 0x09, 0x00, 0x6c, 0x00, 0x0e, 0x00
.4byte gUnknown_811D4F0
.byte 0x01, 0x00, 0x09, 0x00, 0x6d, 0x00, 0xff, 0xff
.4byte gUnknown_811D4D0
.byte 0x01, 0x00, 0x09, 0x00, 0x6e, 0x00, 0x02, 0x00
.4byte gUnknown_811D4B0
.byte 0x01, 0x00, 0x09, 0x00
.byte 0x70, 0x00, 0x03, 0x00
.4byte gUnknown_811D490
.byte 0x01, 0x00, 0x09, 0x00, 0x72, 0x00, 0x04, 0x00
.4byte gUnknown_811D470
.byte 0x01, 0x00, 0x09, 0x00, 0x74, 0x00, 0xff, 0xff
.4byte gUnknown_811D450
.byte 0x01, 0x00, 0x09, 0x00, 0x75, 0x00, 0xff, 0xff
.4byte gUnknown_811D430
.byte 0x01, 0x00, 0x09, 0x00, 0x76, 0x00, 0xff, 0xff
.4byte gUnknown_811D410
.byte 0x01, 0x00, 0x09, 0x00, 0x77, 0x00, 0xff, 0xff
.4byte gUnknown_811D3F0
.byte 0x01, 0x00, 0x09, 0x00, 0x78, 0x00, 0xff, 0xff
.4byte gUnknown_811D3D0
.byte 0x01, 0x00, 0x09, 0x00, 0x79, 0x00, 0xff, 0xff
.4byte gUnknown_811D3B0
.byte 0x01, 0x00, 0x09, 0x00
.byte 0x7a, 0x00, 0xff, 0xff
.4byte gUnknown_811D390
.byte 0x01, 0x00, 0x09, 0x00, 0x7b, 0x00, 0xff, 0xff
.4byte gUnknown_811D370
.byte 0x01, 0x00, 0x09, 0x00, 0x7c, 0x00, 0xff, 0xff
.4byte gUnknown_811D350
.byte 0x01, 0x00, 0x09, 0x00, 0x7d, 0x00, 0x0d, 0x00
.4byte gUnknown_811D330
.byte 0x01, 0x00, 0x09, 0x00, 0x7e, 0x00, 0xff, 0xff
.4byte gUnknown_811D310
.byte 0x01, 0x00, 0x09, 0x00, 0x7f, 0x00, 0xff, 0xff
.4byte gUnknown_811D2F0
.byte 0x01, 0x00, 0x09, 0x00, 0x80, 0x00, 0xff, 0xff
.4byte gUnknown_811D2D0
.byte 0x01, 0x00, 0x09, 0x00, 0x81, 0x00, 0xff, 0xff
.4byte gUnknown_811D2B0
.byte 0x01, 0x00, 0x09, 0x00
.byte 0x82, 0x00, 0x05, 0x00
.4byte gUnknown_811D290
.byte 0x01, 0x00, 0x09, 0x00, 0x84, 0x00, 0xff, 0xff
.4byte gUnknown_811D270
.byte 0x01, 0x00, 0x09, 0x00, 0x85, 0x00, 0xff, 0xff
.4byte gUnknown_811D250
.byte 0x01, 0x00, 0x09, 0x00, 0x86, 0x00, 0xff, 0xff
.4byte gUnknown_811D230
.byte 0x01, 0x00, 0x09, 0x00, 0x87, 0x00, 0xff, 0xff
.4byte gUnknown_811D210
.byte 0x01, 0x00, 0x09, 0x00, 0x88, 0x00, 0xff, 0xff
.4byte gUnknown_811D1F0
.byte 0x01, 0x00, 0x09, 0x00, 0x89, 0x00, 0xff, 0xff
.4byte gUnknown_811D1D0
.byte 0x01, 0x00, 0x09, 0x00, 0x8a, 0x00, 0xff, 0xff
.4byte gUnknown_811D1B0
.byte 0x01, 0x00, 0x09, 0x00
.byte 0x8b, 0x00, 0xff, 0xff
.4byte gUnknown_811D190
.byte 0x01, 0x00, 0x09, 0x00, 0x8c, 0x00, 0xff, 0xff
.4byte gUnknown_811D170
.byte 0x01, 0x00, 0x09, 0x00, 0x8d, 0x00, 0xff, 0xff
.4byte gUnknown_811D150
.byte 0x01, 0x00, 0x09, 0x00, 0x8e, 0x00, 0xff, 0xff
.4byte gUnknown_811D130
.byte 0x01, 0x00, 0x09, 0x00, 0x8f, 0x00, 0xff, 0xff
.4byte gUnknown_811D110
.byte 0x01, 0x00, 0x09, 0x00, 0x90, 0x00, 0xff, 0xff
.4byte gUnknown_811D0F0
.byte 0x01, 0x00, 0x09, 0x00, 0x91, 0x00, 0xff, 0xff
.4byte gUnknown_811D0D0
.byte 0x01, 0x00, 0x09, 0x00, 0x92, 0x00, 0xff, 0xff
.4byte gUnknown_811D0B0
.byte 0x01, 0x00, 0x09, 0x00
.byte 0x93, 0x00, 0xff, 0xff
.4byte gUnknown_811D090
.byte 0x01, 0x00, 0x09, 0x00, 0x94, 0x00, 0xff, 0xff
.4byte gUnknown_811D070
.byte 0x01, 0x00, 0x09, 0x00, 0x95, 0x00, 0xff, 0xff
.4byte gUnknown_811D050
.byte 0x01, 0x00, 0x09, 0x00, 0x96, 0x00, 0x06, 0x00
.4byte gUnknown_811D030
.byte 0x01, 0x00, 0x09, 0x00, 0x98, 0x00, 0xff, 0xff
.4byte gUnknown_811D010
.byte 0x01, 0x00, 0x09, 0x00, 0x99, 0x00, 0x07, 0x00
.4byte gUnknown_811CFF0
.byte 0x01, 0x00, 0x09, 0x00, 0x9b, 0x00, 0x0e, 0x00
.4byte gUnknown_811CFD0
.byte 0x01, 0x00, 0x09, 0x00, 0x9c, 0x00, 0xff, 0xff
.4byte gUnknown_811CFB0
.byte 0x01, 0x00, 0x09, 0x00
.byte 0x9d, 0x00, 0xff, 0xff
.4byte gUnknown_811CF90
.byte 0x01, 0x00, 0x09, 0x00, 0x9e, 0x00, 0xff, 0xff
.4byte gUnknown_811CF70
.byte 0x01, 0x00, 0x09, 0x00, 0x9f, 0x00, 0xff, 0xff
.4byte gUnknown_811CF50
.byte 0x01, 0x00, 0x09, 0x00, 0xa0, 0x00, 0x0a, 0x00
.4byte gUnknown_811CF30
.byte 0x01, 0x00, 0x09, 0x00, 0xa1, 0x00, 0x0c, 0x00
.4byte gUnknown_811CF10
.byte 0x01, 0x00, 0x09, 0x00, 0xa2, 0x00, 0x0d, 0x00
.4byte gUnknown_811CEF0
.byte 0x01, 0x00, 0x09, 0x00, 0xa3, 0x00, 0x0e, 0x00
.4byte gUnknown_811CED0
.byte 0x01, 0x00, 0x09, 0x00, 0xa4, 0x00, 0xff, 0xff
.4byte gUnknown_811CEB0
.byte 0x01, 0x00, 0x09, 0x00
.byte 0xa5, 0x00, 0xff, 0xff
.4byte gUnknown_811CE90
.byte 0x01, 0x00, 0x09, 0x00, 0xa6, 0x00, 0xff, 0xff
.4byte gUnknown_811CE70
.byte 0x01, 0x00, 0x09, 0x00, 0xa7, 0x00, 0xff, 0xff
.4byte gUnknown_811CE50
.byte 0x01, 0x00, 0x09, 0x00, 0xa8, 0x00, 0x08, 0x00
.4byte gUnknown_811CE30
.byte 0x05, 0x00, 0x09, 0x00, 0xaa, 0x00, 0xff, 0xff
.4byte gUnknown_811CE10
.byte 0x09, 0x00, 0x23, 0x00, 0xab, 0x00, 0xff, 0xff
.4byte gUnknown_811CDF0
.byte 0x09, 0x00, 0x23, 0x00, 0xac, 0x00, 0xff, 0xff
.4byte gUnknown_811CDD0
.byte 0x01, 0x00, 0x23, 0x00, 0xad, 0x00, 0xff, 0xff
.4byte gUnknown_811CDB0
.byte 0x01, 0x00, 0x23, 0x00
.byte 0xae, 0x00, 0x0d, 0x00
.4byte gUnknown_811CD90
.byte 0x01, 0x00, 0x23, 0x00, 0xaf, 0x00, 0xff, 0xff
.4byte gUnknown_811CD70
.byte 0x01, 0x00, 0x23, 0x00, 0xb0, 0x00, 0xff, 0xff
.4byte gUnknown_811CD50
.byte 0x01, 0x00, 0x23, 0x00, 0xb1, 0x00, 0x0a, 0x00
.4byte gUnknown_811CD30
.byte 0x01, 0x00, 0x23, 0x00, 0xb2, 0x00, 0x0a, 0x00
.4byte gUnknown_811CD10
.byte 0x01, 0x00, 0x23, 0x00, 0xb3, 0x00, 0x0c, 0x00
.4byte gUnknown_811CCF0
.byte 0x01, 0x00, 0x15, 0x00, 0xb4, 0x00, 0xff, 0xff
.4byte gUnknown_811CCD0
.byte 0x01, 0x00, 0x23, 0x00, 0xb5, 0x00, 0xff, 0xff
.4byte gUnknown_811CCB0
.byte 0x09, 0x00, 0x23, 0x00
.byte 0xb6, 0x00, 0xff, 0xff
.4byte gUnknown_811CC90
.byte 0x06, 0x00, 0x23, 0x00, 0xb7, 0x00, 0xff, 0xff
.4byte gUnknown_811CC70
.byte 0x09, 0x00, 0x23, 0x00, 0xb8, 0x00, 0xff, 0xff
.4byte gUnknown_811CC50
.byte 0x04, 0x00, 0x23, 0x00, 0xb9, 0x00, 0xff, 0xff
.4byte gUnknown_811CC30
.byte 0x04, 0x00, 0x23, 0x00, 0xba, 0x00, 0xff, 0xff
.4byte gUnknown_811CC10
.byte 0x01, 0x00, 0x0d, 0x00, 0xbb, 0x00, 0xff, 0xff
.4byte gUnknown_811CBF0
.byte 0x0a, 0x00, 0x0d, 0x00, 0xbc, 0x00, 0xff, 0xff
.4byte gUnknown_811CBD0
.byte 0x01, 0x00, 0x0e, 0x00, 0xbd, 0x00, 0xff, 0xff
.4byte gUnknown_811CBB0
.byte 0x0a, 0x00, 0x0c, 0x00
.byte 0xbe, 0x00, 0xff, 0xff
.4byte gUnknown_811CB90
.byte 0x01, 0x00, 0x0f, 0x00, 0xbf, 0x00, 0xff, 0xff
.4byte gUnknown_811CB70
.byte 0x0b, 0x00, 0x0c, 0x00, 0xc0, 0x00, 0xff, 0xff
.4byte gUnknown_811CB50
.byte 0x01, 0x00, 0x10, 0x00, 0xc1, 0x00, 0xff, 0xff
.4byte gUnknown_811CB30
.byte 0x0b, 0x00, 0x0c, 0x00, 0xc2, 0x00, 0xff, 0xff
.4byte gUnknown_811CB10
.byte 0x06, 0x00, 0x11, 0x00, 0xc3, 0x00, 0xff, 0xff
.4byte gUnknown_811CAF0
.byte 0x0a, 0x00, 0x0c, 0x00, 0xc4, 0x00, 0xff, 0xff
.4byte gUnknown_811CAD0
.byte 0x01, 0x00, 0x12, 0x00, 0xc5, 0x00, 0xff, 0xff
.4byte gUnknown_811CAB0
.byte 0x0a, 0x00, 0x13, 0x00
.byte 0xc6, 0x00, 0xff, 0xff
.4byte gUnknown_811CA90
.byte 0x0b, 0x00, 0x0c, 0x00, 0xc7, 0x00, 0xff, 0xff
.4byte gUnknown_811CA70
.byte 0x01, 0x00, 0x14, 0x00, 0xc8, 0x00, 0xff, 0xff
.4byte gUnknown_811CA50
.byte 0x03, 0x00, 0x15, 0x00, 0xc9, 0x00, 0xff, 0xff
.4byte gUnknown_811CA30
.byte 0x01, 0x00, 0x16, 0x00, 0xca, 0x00, 0x09, 0x00
.4byte gUnknown_811CA10
.byte 0x03, 0x00, 0x17, 0x00, 0xcb, 0x00, 0x09, 0x00
.4byte gUnknown_811C9F0
.byte 0x01, 0x00, 0x18, 0x00, 0xcc, 0x00, 0x0d, 0x00
.4byte gUnknown_811C9D0
.byte 0x0a, 0x00, 0x19, 0x00, 0xcd, 0x00, 0xff, 0xff
.4byte gUnknown_811C9B0
.byte 0x0b, 0x00, 0x0c, 0x00
.byte 0xce, 0x00, 0xff, 0xff
.4byte gUnknown_811C990
.byte 0x01, 0x00, 0x1a, 0x00, 0xcf, 0x00, 0x0a, 0x00
.4byte gUnknown_811C970
.byte 0x0a, 0x00, 0x1b, 0x00, 0xd0, 0x00, 0xff, 0xff
.4byte gUnknown_811C950
.byte 0x0b, 0x00, 0x0c, 0x00, 0xd1, 0x00, 0xff, 0xff
.4byte gUnknown_811C930
.byte 0x01, 0x00, 0x1c, 0x00, 0xd2, 0x00, 0x0a, 0x00
.4byte gUnknown_811C910
.byte 0x0a, 0x00, 0x1d, 0x00, 0xd3, 0x00, 0xff, 0xff
.4byte gUnknown_811C8F0
.byte 0x0b, 0x00, 0x0c, 0x00, 0xd4, 0x00, 0xff, 0xff
.4byte gUnknown_811C8D0
.byte 0x01, 0x00, 0x1e, 0x00, 0xd5, 0x00, 0xff, 0xff
.4byte gUnknown_811C8B0
.byte 0x0a, 0x00, 0x1f, 0x00
.byte 0xd6, 0x00, 0xff, 0xff
.4byte gUnknown_811C890
.byte 0x0b, 0x00, 0x0c, 0x00, 0xd7, 0x00, 0xff, 0xff
.4byte gUnknown_811C870
.byte 0x01, 0x00, 0x20, 0x00, 0xd8, 0x00, 0xff, 0xff
.4byte gUnknown_811C850
.byte 0x0a, 0x00, 0x21, 0x00, 0xd9, 0x00, 0xff, 0xff
.4byte gUnknown_811C830
.byte 0x0b, 0x00, 0x0c, 0x00, 0xda, 0x00, 0xff, 0xff
.4byte gUnknown_811C810
.byte 0x0b, 0x00, 0x0c, 0x00, 0xdb, 0x00, 0xff, 0xff
.4byte gUnknown_811C7F0
.byte 0x0b, 0x00, 0x0c, 0x00, 0xdc, 0x00, 0xff, 0xff
.4byte gUnknown_811C7D0
.byte 0x0a, 0x00, 0x0c, 0x00, 0xdd, 0x00, 0xff, 0xff
.4byte gUnknown_811C7B0
.byte 0x0a, 0x00, 0x0c, 0x00
.byte 0xde, 0x00, 0xff, 0xff
.4byte gUnknown_811C790
.byte 0x0a, 0x00, 0x0c, 0x00, 0xdf, 0x00, 0xff, 0xff
.4byte gUnknown_811C770
.byte 0x0b, 0x00, 0x0c, 0x00, 0xe0, 0x00, 0xff, 0xff
.4byte gUnknown_811C750
.byte 0x0a, 0x00, 0x22, 0x00, 0xe1, 0x00, 0xff, 0xff
.4byte gUnknown_811C730
.byte 0x0b, 0x00, 0x0c, 0x00, 0xe2, 0x00, 0xff, 0xff
.4byte gUnknown_811C710
.byte 0x03, 0x00, 0x0c, 0x00, 0xe3, 0x00, 0xff, 0xff
.4byte gUnknown_811C6F0
.byte 0x0a, 0x00, 0x0c, 0x00, 0xe4, 0x00, 0xff, 0xff
.4byte gUnknown_811C6D0
.byte 0x03, 0x00, 0x0c, 0x00, 0xe5, 0x00, 0xff, 0xff
.4byte gUnknown_811C6B0
.byte 0x01, 0x00, 0x0c, 0x00
.byte 0xe6, 0x00, 0xff, 0xff
.4byte gUnknown_811C690
.byte 0x0a, 0x00, 0x0c, 0x00, 0xe7, 0x00, 0xff, 0xff
.4byte gUnknown_811C670
.byte 0x09, 0x00, 0x25, 0x00, 0xe8, 0x00, 0xff, 0xff
.4byte gUnknown_811C650
.byte 0x09, 0x00, 0x25, 0x00, 0xe9, 0x00, 0xff, 0xff
.4byte gUnknown_811C630
.byte 0x04, 0x00, 0x25, 0x00, 0xea, 0x00, 0xff, 0xff
.4byte gUnknown_811C610
.byte 0x04, 0x00, 0x25, 0x00, 0xeb, 0x00, 0xff, 0xff
.4byte gUnknown_811C5F0
.byte 0x04, 0x00, 0x25, 0x00, 0xec, 0x00, 0xff, 0xff
.4byte gUnknown_811C5D0
.byte 0x04, 0x00, 0x25, 0x00, 0xed, 0x00, 0xff, 0xff
.4byte gUnknown_811C5B0

.global gUnknown_811C5B0
gUnknown_811C5B0: @ 811C5B0
.string "__ground_amd_conversion_00240\0"
.align 2, 0

.global gUnknown_811C5D0
gUnknown_811C5D0: @ 811C5D0
.string "__ground_amd_conversion_00239\0"
.align 2, 0

.global gUnknown_811C5F0
gUnknown_811C5F0: @ 811C5F0
.string "__ground_amd_conversion_00237\0"
.align 2, 0

.global gUnknown_811C610
gUnknown_811C610: @ 811C610
.string "__ground_amd_conversion_00235\0"
.align 2, 0

.global gUnknown_811C630
gUnknown_811C630: @ 811C630
.string "__ground_amd_conversion_00233\0"
.align 2, 0

.global gUnknown_811C650
gUnknown_811C650: @ 811C650
.string "__ground_amd_conversion_00232\0"
.align 2, 0

.global gUnknown_811C670
gUnknown_811C670: @ 811C670
.string "__ground_amd_conversion_00231\0"
.align 2, 0

.global gUnknown_811C690
gUnknown_811C690: @ 811C690
.string "__ground_amd_conversion_00230\0"
.align 2, 0

.global gUnknown_811C6B0
gUnknown_811C6B0: @ 811C6B0
.string "__ground_amd_conversion_00229\0"
.align 2, 0

.global gUnknown_811C6D0
gUnknown_811C6D0: @ 811C6D0
.string "__ground_amd_conversion_00228\0"
.align 2, 0

.global gUnknown_811C6F0
gUnknown_811C6F0: @ 811C6F0
.string "__ground_amd_conversion_00227\0"
.align 2, 0

.global gUnknown_811C710
gUnknown_811C710: @ 811C710
.string "__ground_amd_conversion_00226\0"
.align 2, 0

.global gUnknown_811C730
gUnknown_811C730: @ 811C730
.string "__ground_amd_conversion_00225\0"
.align 2, 0

.global gUnknown_811C750
gUnknown_811C750: @ 811C750
.string "__ground_amd_conversion_00224\0"
.align 2, 0

.global gUnknown_811C770
gUnknown_811C770: @ 811C770
.string "__ground_amd_conversion_00223\0"
.align 2, 0

.global gUnknown_811C790
gUnknown_811C790: @ 811C790
.string "__ground_amd_conversion_00222\0"
.align 2, 0

.global gUnknown_811C7B0
gUnknown_811C7B0: @ 811C7B0
.string "__ground_amd_conversion_00221\0"
.align 2, 0

.global gUnknown_811C7D0
gUnknown_811C7D0: @ 811C7D0
.string "__ground_amd_conversion_00220\0"
.align 2, 0

.global gUnknown_811C7F0
gUnknown_811C7F0: @ 811C7F0
.string "__ground_amd_conversion_00219\0"
.align 2, 0

.global gUnknown_811C810
gUnknown_811C810: @ 811C810
.string "__ground_amd_conversion_00218\0"
.align 2, 0

.global gUnknown_811C830
gUnknown_811C830: @ 811C830
.string "__ground_amd_conversion_00217\0"
.align 2, 0

.global gUnknown_811C850
gUnknown_811C850: @ 811C850
.string "__ground_amd_conversion_00216\0"
.align 2, 0

.global gUnknown_811C870
gUnknown_811C870: @ 811C870
.string "__ground_amd_conversion_00215\0"
.align 2, 0

.global gUnknown_811C890
gUnknown_811C890: @ 811C890
.string "__ground_amd_conversion_00214\0"
.align 2, 0

.global gUnknown_811C8B0
gUnknown_811C8B0: @ 811C8B0
.string "__ground_amd_conversion_00213\0"
.align 2, 0

.global gUnknown_811C8D0
gUnknown_811C8D0: @ 811C8D0
.string "__ground_amd_conversion_00212\0"
.align 2, 0

.global gUnknown_811C8F0
gUnknown_811C8F0: @ 811C8F0
.string "__ground_amd_conversion_00211\0"
.align 2, 0

.global gUnknown_811C910
gUnknown_811C910: @ 811C910
.string "__ground_amd_conversion_00210\0"
.align 2, 0

.global gUnknown_811C930
gUnknown_811C930: @ 811C930
.string "__ground_amd_conversion_00209\0"
.align 2, 0

.global gUnknown_811C950
gUnknown_811C950: @ 811C950
.string "__ground_amd_conversion_00208\0"
.align 2, 0

.global gUnknown_811C970
gUnknown_811C970: @ 811C970
.string "__ground_amd_conversion_00207\0"
.align 2, 0

.global gUnknown_811C990
gUnknown_811C990: @ 811C990
.string "__ground_amd_conversion_00206\0"
.align 2, 0

.global gUnknown_811C9B0
gUnknown_811C9B0: @ 811C9B0
.string "__ground_amd_conversion_00205\0"
.align 2, 0

.global gUnknown_811C9D0
gUnknown_811C9D0: @ 811C9D0
.string "__ground_amd_conversion_00204\0"
.align 2, 0

.global gUnknown_811C9F0
gUnknown_811C9F0: @ 811C9F0
.string "__ground_amd_conversion_00203\0"
.align 2, 0

.global gUnknown_811CA10
gUnknown_811CA10: @ 811CA10
.string "__ground_amd_conversion_00202\0"
.align 2, 0

.global gUnknown_811CA30
gUnknown_811CA30: @ 811CA30
.string "__ground_amd_conversion_00201\0"
.align 2, 0

.global gUnknown_811CA50
gUnknown_811CA50: @ 811CA50
.string "__ground_amd_conversion_00200\0"
.align 2, 0

.global gUnknown_811CA70
gUnknown_811CA70: @ 811CA70
.string "__ground_amd_conversion_00199\0"
.align 2, 0

.global gUnknown_811CA90
gUnknown_811CA90: @ 811CA90
.string "__ground_amd_conversion_00198\0"
.align 2, 0

.global gUnknown_811CAB0
gUnknown_811CAB0: @ 811CAB0
.string "__ground_amd_conversion_00197\0"
.align 2, 0

.global gUnknown_811CAD0
gUnknown_811CAD0: @ 811CAD0
.string "__ground_amd_conversion_00196\0"
.align 2, 0

.global gUnknown_811CAF0
gUnknown_811CAF0: @ 811CAF0
.string "__ground_amd_conversion_00195\0"
.align 2, 0

.global gUnknown_811CB10
gUnknown_811CB10: @ 811CB10
.string "__ground_amd_conversion_00194\0"
.align 2, 0

.global gUnknown_811CB30
gUnknown_811CB30: @ 811CB30
.string "__ground_amd_conversion_00193\0"
.align 2, 0

.global gUnknown_811CB50
gUnknown_811CB50: @ 811CB50
.string "__ground_amd_conversion_00192\0"
.align 2, 0

.global gUnknown_811CB70
gUnknown_811CB70: @ 811CB70
.string "__ground_amd_conversion_00191\0"
.align 2, 0

.global gUnknown_811CB90
gUnknown_811CB90: @ 811CB90
.string "__ground_amd_conversion_00190\0"
.align 2, 0

.global gUnknown_811CBB0
gUnknown_811CBB0: @ 811CBB0
.string "__ground_amd_conversion_00189\0"
.align 2, 0

.global gUnknown_811CBD0
gUnknown_811CBD0: @ 811CBD0
.string "__ground_amd_conversion_00188\0"
.align 2, 0

.global gUnknown_811CBF0
gUnknown_811CBF0: @ 811CBF0
.string "__ground_amd_conversion_00187\0"
.align 2, 0

.global gUnknown_811CC10
gUnknown_811CC10: @ 811CC10
.string "__ground_amd_conversion_00186\0"
.align 2, 0

.global gUnknown_811CC30
gUnknown_811CC30: @ 811CC30
.string "__ground_amd_conversion_00185\0"
.align 2, 0

.global gUnknown_811CC50
gUnknown_811CC50: @ 811CC50
.string "__ground_amd_conversion_00184\0"
.align 2, 0

.global gUnknown_811CC70
gUnknown_811CC70: @ 811CC70
.string "__ground_amd_conversion_00183\0"
.align 2, 0

.global gUnknown_811CC90
gUnknown_811CC90: @ 811CC90
.string "__ground_amd_conversion_00182\0"
.align 2, 0

.global gUnknown_811CCB0
gUnknown_811CCB0: @ 811CCB0
.string "__ground_amd_conversion_00181\0"
.align 2, 0

.global gUnknown_811CCD0
gUnknown_811CCD0: @ 811CCD0
.string "__ground_amd_conversion_00180\0"
.align 2, 0

.global gUnknown_811CCF0
gUnknown_811CCF0: @ 811CCF0
.string "__ground_amd_conversion_00179\0"
.align 2, 0

.global gUnknown_811CD10
gUnknown_811CD10: @ 811CD10
.string "__ground_amd_conversion_00178\0"
.align 2, 0

.global gUnknown_811CD30
gUnknown_811CD30: @ 811CD30
.string "__ground_amd_conversion_00177\0"
.align 2, 0

.global gUnknown_811CD50
gUnknown_811CD50: @ 811CD50
.string "__ground_amd_conversion_00176\0"
.align 2, 0

.global gUnknown_811CD70
gUnknown_811CD70: @ 811CD70
.string "__ground_amd_conversion_00175\0"
.align 2, 0

.global gUnknown_811CD90
gUnknown_811CD90: @ 811CD90
.string "__ground_amd_conversion_00174\0"
.align 2, 0

.global gUnknown_811CDB0
gUnknown_811CDB0: @ 811CDB0
.string "__ground_amd_conversion_00173\0"
.align 2, 0

.global gUnknown_811CDD0
gUnknown_811CDD0: @ 811CDD0
.string "__ground_amd_conversion_00172\0"
.align 2, 0

.global gUnknown_811CDF0
gUnknown_811CDF0: @ 811CDF0
.string "__ground_amd_conversion_00171\0"
.align 2, 0

.global gUnknown_811CE10
gUnknown_811CE10: @ 811CE10
.string "__ground_amd_conversion_00170\0"
.align 2, 0

.global gUnknown_811CE30
gUnknown_811CE30: @ 811CE30
.string "__ground_amd_conversion_00168\0"
.align 2, 0

.global gUnknown_811CE50
gUnknown_811CE50: @ 811CE50
.string "__ground_amd_conversion_00167\0"
.align 2, 0

.global gUnknown_811CE70
gUnknown_811CE70: @ 811CE70
.string "__ground_amd_conversion_00166\0"
.align 2, 0

.global gUnknown_811CE90
gUnknown_811CE90: @ 811CE90
.string "__ground_amd_conversion_00165\0"
.align 2, 0

.global gUnknown_811CEB0
gUnknown_811CEB0: @ 811CEB0
.string "__ground_amd_conversion_00164\0"
.align 2, 0

.global gUnknown_811CED0
gUnknown_811CED0: @ 811CED0
.string "__ground_amd_conversion_00163\0"
.align 2, 0

.global gUnknown_811CEF0
gUnknown_811CEF0: @ 811CEF0
.string "__ground_amd_conversion_00162\0"
.align 2, 0

.global gUnknown_811CF10
gUnknown_811CF10: @ 811CF10
.string "__ground_amd_conversion_00161\0"
.align 2, 0

.global gUnknown_811CF30
gUnknown_811CF30: @ 811CF30
.string "__ground_amd_conversion_00160\0"
.align 2, 0

.global gUnknown_811CF50
gUnknown_811CF50: @ 811CF50
.string "__ground_amd_conversion_00159\0"
.align 2, 0

.global gUnknown_811CF70
gUnknown_811CF70: @ 811CF70
.string "__ground_amd_conversion_00158\0"
.align 2, 0

.global gUnknown_811CF90
gUnknown_811CF90: @ 811CF90
.string "__ground_amd_conversion_00157\0"
.align 2, 0

.global gUnknown_811CFB0
gUnknown_811CFB0: @ 811CFB0
.string "__ground_amd_conversion_00156\0"
.align 2, 0

.global gUnknown_811CFD0
gUnknown_811CFD0: @ 811CFD0
.string "__ground_amd_conversion_00155\0"
.align 2, 0

.global gUnknown_811CFF0
gUnknown_811CFF0: @ 811CFF0
.string "__ground_amd_conversion_00153\0"
.align 2, 0

.global gUnknown_811D010
gUnknown_811D010: @ 811D010
.string "__ground_amd_conversion_00152\0"
.align 2, 0

.global gUnknown_811D030
gUnknown_811D030: @ 811D030
.string "__ground_amd_conversion_00150\0"
.align 2, 0

.global gUnknown_811D050
gUnknown_811D050: @ 811D050
.string "__ground_amd_conversion_00149\0"
.align 2, 0

.global gUnknown_811D070
gUnknown_811D070: @ 811D070
.string "__ground_amd_conversion_00148\0"
.align 2, 0

.global gUnknown_811D090
gUnknown_811D090: @ 811D090
.string "__ground_amd_conversion_00147\0"
.align 2, 0

.global gUnknown_811D0B0
gUnknown_811D0B0: @ 811D0B0
.string "__ground_amd_conversion_00146\0"
.align 2, 0

.global gUnknown_811D0D0
gUnknown_811D0D0: @ 811D0D0
.string "__ground_amd_conversion_00145\0"
.align 2, 0

.global gUnknown_811D0F0
gUnknown_811D0F0: @ 811D0F0
.string "__ground_amd_conversion_00144\0"
.align 2, 0

.global gUnknown_811D110
gUnknown_811D110: @ 811D110
.string "__ground_amd_conversion_00143\0"
.align 2, 0

.global gUnknown_811D130
gUnknown_811D130: @ 811D130
.string "__ground_amd_conversion_00142\0"
.align 2, 0

.global gUnknown_811D150
gUnknown_811D150: @ 811D150
.string "__ground_amd_conversion_00141\0"
.align 2, 0

.global gUnknown_811D170
gUnknown_811D170: @ 811D170
.string "__ground_amd_conversion_00140\0"
.align 2, 0

.global gUnknown_811D190
gUnknown_811D190: @ 811D190
.string "__ground_amd_conversion_00139\0"
.align 2, 0

.global gUnknown_811D1B0
gUnknown_811D1B0: @ 811D1B0
.string "__ground_amd_conversion_00138\0"
.align 2, 0

.global gUnknown_811D1D0
gUnknown_811D1D0: @ 811D1D0
.string "__ground_amd_conversion_00137\0"
.align 2, 0

.global gUnknown_811D1F0
gUnknown_811D1F0: @ 811D1F0
.string "__ground_amd_conversion_00136\0"
.align 2, 0

.global gUnknown_811D210
gUnknown_811D210: @ 811D210
.string "__ground_amd_conversion_00135\0"
.align 2, 0

.global gUnknown_811D230
gUnknown_811D230: @ 811D230
.string "__ground_amd_conversion_00134\0"
.align 2, 0

.global gUnknown_811D250
gUnknown_811D250: @ 811D250
.string "__ground_amd_conversion_00133\0"
.align 2, 0

.global gUnknown_811D270
gUnknown_811D270: @ 811D270
.string "__ground_amd_conversion_00132\0"
.align 2, 0

.global gUnknown_811D290
gUnknown_811D290: @ 811D290
.string "__ground_amd_conversion_00130\0"
.align 2, 0

.global gUnknown_811D2B0
gUnknown_811D2B0: @ 811D2B0
.string "__ground_amd_conversion_00129\0"
.align 2, 0

.global gUnknown_811D2D0
gUnknown_811D2D0: @ 811D2D0
.string "__ground_amd_conversion_00128\0"
.align 2, 0

.global gUnknown_811D2F0
gUnknown_811D2F0: @ 811D2F0
.string "__ground_amd_conversion_00127\0"
.align 2, 0

.global gUnknown_811D310
gUnknown_811D310: @ 811D310
.string "__ground_amd_conversion_00126\0"
.align 2, 0

.global gUnknown_811D330
gUnknown_811D330: @ 811D330
.string "__ground_amd_conversion_00125\0"
.align 2, 0

.global gUnknown_811D350
gUnknown_811D350: @ 811D350
.string "__ground_amd_conversion_00124\0"
.align 2, 0

.global gUnknown_811D370
gUnknown_811D370: @ 811D370
.string "__ground_amd_conversion_00123\0"
.align 2, 0

.global gUnknown_811D390
gUnknown_811D390: @ 811D390
.string "__ground_amd_conversion_00122\0"
.align 2, 0

.global gUnknown_811D3B0
gUnknown_811D3B0: @ 811D3B0
.string "__ground_amd_conversion_00121\0"
.align 2, 0

.global gUnknown_811D3D0
gUnknown_811D3D0: @ 811D3D0
.string "__ground_amd_conversion_00120\0"
.align 2, 0

.global gUnknown_811D3F0
gUnknown_811D3F0: @ 811D3F0
.string "__ground_amd_conversion_00119\0"
.align 2, 0

.global gUnknown_811D410
gUnknown_811D410: @ 811D410
.string "__ground_amd_conversion_00118\0"
.align 2, 0

.global gUnknown_811D430
gUnknown_811D430: @ 811D430
.string "__ground_amd_conversion_00117\0"
.align 2, 0

.global gUnknown_811D450
gUnknown_811D450: @ 811D450
.string "__ground_amd_conversion_00116\0"
.align 2, 0

.global gUnknown_811D470
gUnknown_811D470: @ 811D470
.string "__ground_amd_conversion_00114\0"
.align 2, 0

.global gUnknown_811D490
gUnknown_811D490: @ 811D490
.string "__ground_amd_conversion_00112\0"
.align 2, 0

.global gUnknown_811D4B0
gUnknown_811D4B0: @ 811D4B0
.string "__ground_amd_conversion_00110\0"
.align 2, 0

.global gUnknown_811D4D0
gUnknown_811D4D0: @ 811D4D0
.string "__ground_amd_conversion_00109\0"
.align 2, 0

.global gUnknown_811D4F0
gUnknown_811D4F0: @ 811D4F0
.string "__ground_amd_conversion_00108\0"
.align 2, 0

.global gUnknown_811D510
gUnknown_811D510: @ 811D510
.string "__ground_amd_conversion_00106\0"
.align 2, 0

.global gUnknown_811D530
gUnknown_811D530: @ 811D530
.string "__ground_amd_conversion_00105\0"
.align 2, 0

.global gUnknown_811D550
gUnknown_811D550: @ 811D550
.string "__ground_amd_conversion_00104\0"
.align 2, 0

.global gUnknown_811D570
gUnknown_811D570: @ 811D570
.string "__ground_amd_conversion_00103\0"
.align 2, 0

.global gUnknown_811D590
gUnknown_811D590: @ 811D590
.string "__ground_amd_conversion_00102\0"
.align 2, 0

.global gUnknown_811D5B0
gUnknown_811D5B0: @ 811D5B0
.string "__ground_amd_conversion_00101\0"
.align 2, 0

.global gUnknown_811D5D0
gUnknown_811D5D0: @ 811D5D0
.string "__ground_amd_conversion_00100\0"
.align 2, 0

.global gUnknown_811D5F0
gUnknown_811D5F0: @ 811D5F0
.string "__ground_amd_conversion_00099\0"
.align 2, 0

.global gUnknown_811D610
gUnknown_811D610: @ 811D610
.string "__ground_amd_conversion_00098\0"
.align 2, 0

.global gUnknown_811D630
gUnknown_811D630: @ 811D630
.string "__ground_amd_conversion_00097\0"
.align 2, 0

.global gUnknown_811D650
gUnknown_811D650: @ 811D650
.string "__ground_amd_conversion_00096\0"
.align 2, 0

.global gUnknown_811D670
gUnknown_811D670: @ 811D670
.string "__ground_amd_conversion_00095\0"
.align 2, 0

.global gUnknown_811D690
gUnknown_811D690: @ 811D690
.string "__ground_amd_conversion_00094\0"
.align 2, 0

.global gUnknown_811D6B0
gUnknown_811D6B0: @ 811D6B0
.string "__ground_amd_conversion_00093\0"
.align 2, 0

.global gUnknown_811D6D0
gUnknown_811D6D0: @ 811D6D0
.string "__ground_amd_conversion_00092\0"
.align 2, 0

.global gUnknown_811D6F0
gUnknown_811D6F0: @ 811D6F0
.string "__ground_amd_conversion_00091\0"
.align 2, 0

.global gUnknown_811D710
gUnknown_811D710: @ 811D710
.string "__ground_amd_conversion_00090\0"
.align 2, 0

.global gUnknown_811D730
gUnknown_811D730: @ 811D730
.string "__ground_amd_conversion_00089\0"
.align 2, 0

.global gUnknown_811D750
gUnknown_811D750: @ 811D750
.string "__ground_amd_conversion_00088\0"
.align 2, 0

.global gUnknown_811D770
gUnknown_811D770: @ 811D770
.string "__ground_amd_conversion_00087\0"
.align 2, 0

.global gUnknown_811D790
gUnknown_811D790: @ 811D790
.string "__ground_amd_conversion_00086\0"
.align 2, 0

.global gUnknown_811D7B0
gUnknown_811D7B0: @ 811D7B0
.string "__ground_amd_conversion_00085\0"
.align 2, 0

.global gUnknown_811D7D0
gUnknown_811D7D0: @ 811D7D0
.string "__ground_amd_conversion_00084\0"
.align 2, 0

.global gUnknown_811D7F0
gUnknown_811D7F0: @ 811D7F0
.string "__ground_amd_conversion_00083\0"
.align 2, 0

.global gUnknown_811D810
gUnknown_811D810: @ 811D810
.string "__ground_amd_conversion_00082\0"
.align 2, 0

.global gUnknown_811D830
gUnknown_811D830: @ 811D830
.string "__ground_amd_conversion_00081\0"
.align 2, 0

.global gUnknown_811D850
gUnknown_811D850: @ 811D850
.string "__ground_amd_conversion_00080\0"
.align 2, 0

.global gUnknown_811D870
gUnknown_811D870: @ 811D870
.string "__ground_amd_conversion_00079\0"
.align 2, 0

.global gUnknown_811D890
gUnknown_811D890: @ 811D890
.string "__ground_amd_conversion_00078\0"
.align 2, 0

.global gUnknown_811D8B0
gUnknown_811D8B0: @ 811D8B0
.string "__ground_amd_conversion_00077\0"
.align 2, 0

.global gUnknown_811D8D0
gUnknown_811D8D0: @ 811D8D0
.string "__ground_amd_conversion_00076\0"
.align 2, 0

.global gUnknown_811D8F0
gUnknown_811D8F0: @ 811D8F0
.string "__ground_amd_conversion_00075\0"
.align 2, 0

.global gUnknown_811D910
gUnknown_811D910: @ 811D910
.string "__ground_amd_conversion_00074\0"
.align 2, 0

.global gUnknown_811D930
gUnknown_811D930: @ 811D930
.string "__ground_amd_conversion_00073\0"
.align 2, 0

.global gUnknown_811D950
gUnknown_811D950: @ 811D950
.string "__ground_amd_conversion_00072\0"
.align 2, 0

.global gUnknown_811D970
gUnknown_811D970: @ 811D970
.string "__ground_amd_conversion_00071\0"
.align 2, 0

.global gUnknown_811D990
gUnknown_811D990: @ 811D990
.string "__ground_amd_conversion_00070\0"
.align 2, 0

.global gUnknown_811D9B0
gUnknown_811D9B0: @ 811D9B0
.string "__ground_amd_conversion_00069\0"
.align 2, 0

.global gUnknown_811D9D0
gUnknown_811D9D0: @ 811D9D0
.string "__ground_amd_conversion_00068\0"
.align 2, 0

.global gUnknown_811D9F0
gUnknown_811D9F0: @ 811D9F0
.string "__ground_amd_conversion_00067\0"
.align 2, 0

.global gUnknown_811DA10
gUnknown_811DA10: @ 811DA10
.string "__ground_amd_conversion_00066\0"
.align 2, 0

.global gUnknown_811DA30
gUnknown_811DA30: @ 811DA30
.string "__ground_amd_conversion_00065\0"
.align 2, 0

.global gUnknown_811DA50
gUnknown_811DA50: @ 811DA50
.string "__ground_amd_conversion_00064\0"
.align 2, 0

.global gUnknown_811DA70
gUnknown_811DA70: @ 811DA70
.string "__ground_amd_conversion_00063\0"
.align 2, 0

.global gUnknown_811DA90
gUnknown_811DA90: @ 811DA90
.string "__ground_amd_conversion_00062\0"
.align 2, 0

.global gUnknown_811DAB0
gUnknown_811DAB0: @ 811DAB0
.string "__ground_amd_conversion_00061\0"
.align 2, 0

.global gUnknown_811DAD0
gUnknown_811DAD0: @ 811DAD0
.string "__ground_amd_conversion_00060\0"
.align 2, 0

.global gUnknown_811DAF0
gUnknown_811DAF0: @ 811DAF0
.string "__ground_amd_conversion_00059\0"
.align 2, 0

.global gUnknown_811DB10
gUnknown_811DB10: @ 811DB10
.string "__ground_amd_conversion_00058\0"
.align 2, 0

.global gUnknown_811DB30
gUnknown_811DB30: @ 811DB30
.string "__ground_amd_conversion_00057\0"
.align 2, 0

.global gUnknown_811DB50
gUnknown_811DB50: @ 811DB50
.string "__ground_amd_conversion_00056\0"
.align 2, 0

.global gUnknown_811DB70
gUnknown_811DB70: @ 811DB70
.string "__ground_amd_conversion_00055\0"
.align 2, 0

.global gUnknown_811DB90
gUnknown_811DB90: @ 811DB90
.string "__ground_amd_conversion_00054\0"
.align 2, 0

.global gUnknown_811DBB0
gUnknown_811DBB0: @ 811DBB0
.string "__ground_amd_conversion_00053\0"
.align 2, 0

.global gUnknown_811DBD0
gUnknown_811DBD0: @ 811DBD0
.string "__ground_amd_conversion_00052\0"
.align 2, 0

.global gUnknown_811DBF0
gUnknown_811DBF0: @ 811DBF0
.string "__ground_amd_conversion_00051\0"
.align 2, 0

.global gUnknown_811DC10
gUnknown_811DC10: @ 811DC10
.string "__ground_amd_conversion_00050\0"
.align 2, 0

.global gUnknown_811DC30
gUnknown_811DC30: @ 811DC30
.string "__ground_amd_conversion_00049\0"
.align 2, 0

.global gUnknown_811DC50
gUnknown_811DC50: @ 811DC50
.string "__ground_amd_conversion_00048\0"
.align 2, 0

.global gUnknown_811DC70
gUnknown_811DC70: @ 811DC70
.string "__ground_amd_conversion_00047\0"
.align 2, 0

.global gUnknown_811DC90
gUnknown_811DC90: @ 811DC90
.string "__ground_amd_conversion_00046\0"
.align 2, 0

.global gUnknown_811DCB0
gUnknown_811DCB0: @ 811DCB0
.string "__ground_amd_conversion_00045\0"
.align 2, 0

.global gUnknown_811DCD0
gUnknown_811DCD0: @ 811DCD0
.string "__ground_amd_conversion_00044\0"
.align 2, 0

.global gUnknown_811DCF0
gUnknown_811DCF0: @ 811DCF0
.string "__ground_amd_conversion_00043\0"
.align 2, 0

.global gUnknown_811DD10
gUnknown_811DD10: @ 811DD10
.string "__ground_amd_conversion_00042\0"
.align 2, 0

.global gUnknown_811DD30
gUnknown_811DD30: @ 811DD30
.string "__ground_amd_conversion_00041\0"
.align 2, 0

.global gUnknown_811DD50
gUnknown_811DD50: @ 811DD50
.string "__ground_amd_conversion_00040\0"
.align 2, 0

.global gUnknown_811DD70
gUnknown_811DD70: @ 811DD70
.string "__ground_amd_conversion_00039\0"
.align 2, 0

.global gUnknown_811DD90
gUnknown_811DD90: @ 811DD90
.string "__ground_amd_conversion_00038\0"
.align 2, 0

.global gUnknown_811DDB0
gUnknown_811DDB0: @ 811DDB0
.string "__ground_amd_conversion_00037\0"
.align 2, 0

.global gUnknown_811DDD0
gUnknown_811DDD0: @ 811DDD0
.string "__ground_amd_conversion_00036\0"
.align 2, 0

.global gUnknown_811DDF0
gUnknown_811DDF0: @ 811DDF0
.string "__ground_amd_conversion_00035\0"
.align 2, 0

.global gUnknown_811DE10
gUnknown_811DE10: @ 811DE10
.string "__ground_amd_conversion_00034\0"
.align 2, 0

.global gUnknown_811DE30
gUnknown_811DE30: @ 811DE30
.string "__ground_amd_conversion_00033\0"
.align 2, 0

.global gUnknown_811DE50
gUnknown_811DE50: @ 811DE50
.string "__ground_amd_conversion_00032\0"
.align 2, 0

.global gUnknown_811DE70
gUnknown_811DE70: @ 811DE70
.string "__ground_amd_conversion_00031\0"
.align 2, 0

.global gUnknown_811DE90
gUnknown_811DE90: @ 811DE90
.string "__ground_amd_conversion_00030\0"
.align 2, 0

.global gUnknown_811DEB0
gUnknown_811DEB0: @ 811DEB0
.string "__ground_amd_conversion_00029\0"
.align 2, 0

.global gUnknown_811DED0
gUnknown_811DED0: @ 811DED0
.string "__ground_amd_conversion_00028\0"
.align 2, 0

.global gUnknown_811DEF0
gUnknown_811DEF0: @ 811DEF0
.string "__ground_amd_conversion_00027\0"
.align 2, 0

.global gUnknown_811DF10
gUnknown_811DF10: @ 811DF10
.string "__ground_amd_conversion_00026\0"
.align 2, 0

.global gUnknown_811DF30
gUnknown_811DF30: @ 811DF30
.string "__ground_amd_conversion_00025\0"
.align 2, 0

.global gUnknown_811DF50
gUnknown_811DF50: @ 811DF50
.string "__ground_amd_conversion_00024\0"
.align 2, 0

.global gUnknown_811DF70
gUnknown_811DF70: @ 811DF70
.string "__ground_amd_conversion_00023\0"
.align 2, 0

.global gUnknown_811DF90
gUnknown_811DF90: @ 811DF90
.string "__ground_amd_conversion_00022\0"
.align 2, 0

.global gUnknown_811DFB0
gUnknown_811DFB0: @ 811DFB0
.string "__ground_amd_conversion_00021\0"
.align 2, 0

.global gUnknown_811DFD0
gUnknown_811DFD0: @ 811DFD0
.string "__ground_amd_conversion_00020\0"
.align 2, 0

.global gUnknown_811DFF0
gUnknown_811DFF0: @ 811DFF0
.string "__ground_amd_conversion_00019\0"
.align 2, 0

.global gUnknown_811E010
gUnknown_811E010: @ 811E010
.string "__ground_amd_conversion_00018\0"
.align 2, 0

.global gUnknown_811E030
gUnknown_811E030: @ 811E030
.string "__ground_amd_conversion_00017\0"
.align 2, 0

.global gUnknown_811E050
gUnknown_811E050: @ 811E050
.string "__ground_amd_conversion_00016\0"
.align 2, 0

.global gUnknown_811E070
gUnknown_811E070: @ 811E070
.string "__ground_amd_conversion_00015\0"
.align 2, 0

.global gUnknown_811E090
gUnknown_811E090: @ 811E090
.string "__ground_amd_conversion_00014\0"
.align 2, 0

.global gUnknown_811E0B0
gUnknown_811E0B0: @ 811E0B0
.string "__ground_amd_conversion_00013\0"
.align 2, 0

.global gUnknown_811E0D0
gUnknown_811E0D0: @ 811E0D0
.string "__ground_amd_conversion_00012\0"
.align 2, 0

.global gUnknown_811E0F0
gUnknown_811E0F0: @ 811E0F0
.string "__ground_amd_conversion_00011\0"
.align 2, 0

.global gUnknown_811E110
gUnknown_811E110: @ 811E110
.string "__ground_amd_conversion_00010\0"
.align 2, 0

.global gUnknown_811E130
gUnknown_811E130: @ 811E130
.string "__ground_amd_conversion_00008\0"
.align 2, 0

.global gUnknown_811E150
gUnknown_811E150: @ 811E150
.string "__ground_amd_conversion_00007\0"
.align 2, 0

.global gUnknown_811E170
gUnknown_811E170: @ 811E170
.string "__ground_amd_conversion_00006\0"
.align 2, 0

.global gUnknown_811E190
gUnknown_811E190: @ 811E190
.string "__ground_amd_conversion_00005\0"
.align 2, 0

.global gUnknown_811E1B0
gUnknown_811E1B0: @ 811E1B0
.string "__ground_amd_conversion_00004\0"
.align 2, 0

.global gUnknown_811E1D0
gUnknown_811E1D0: @ 811E1D0
.string "__ground_amd_conversion_00003\0"
.align 2, 0

.global gUnknown_811E1F0
gUnknown_811E1F0: @ 811E1F0
.string "__ground_amd_conversion_00002\0"
.align 2, 0

.global gUnknown_811E210
gUnknown_811E210: @ 811E210
.string "__ground_amd_conversion_00001\0"
.align 2, 0

.global gUnknown_811E230
gUnknown_811E230: @ 811E230
.byte 0x5f, 0x5f, 0x67, 0x72
.byte 0x6f, 0x75, 0x6e, 0x64, 0x5f, 0x61, 0x6d, 0x64, 0x5f, 0x63, 0x6f, 0x6e, 0x76, 0x65, 0x72, 0x73, 0x69, 0x6f, 0x6e, 0x5f, 0x30, 0x30, 0x30, 0x30, 0x30, 0x00, 0x00, 0x00, 0x70, 0x6b, 0x73, 0x64
.byte 0x69, 0x72, 0x30, 0x00
@ Script Data

.global gMapScriptTable
gMapScriptTable: @ 811E258
@ replacing .incbin "baserom.gba", 0x11E258, 0x39C
.4byte gGroundScript_gs0
.4byte gGroundScript_gs1
.4byte gGroundScript_gs2
.4byte gGroundScript_gs2
.4byte gGroundScript_gs4
.4byte gGroundScript_gs5
.4byte gGroundScript_gs6
.4byte gGroundScript_gs7
.4byte gGroundScript_gs8
.4byte gGroundScript_gs9
.4byte gGroundScript_gs9
.4byte gGroundScript_gs9
.4byte gGroundScript_gs12
.4byte gGroundScript_gs12
.4byte gGroundScript_gs12
.4byte gGroundScript_gs9
.4byte gGroundScript_gs9
.4byte gGroundScript_gs9
.4byte gGroundScript_gs12
.4byte gGroundScript_gs12
.4byte gGroundScript_gs12
.4byte gGroundScript_gs9
.4byte gGroundScript_gs9
.4byte gGroundScript_gs9
.4byte gGroundScript_gs12
.4byte gGroundScript_gs12
.4byte gGroundScript_gs12
.4byte gGroundScript_gs9
.4byte gGroundScript_gs9
.4byte gGroundScript_gs9
.4byte gGroundScript_gs12
.4byte gGroundScript_gs12
.4byte gGroundScript_gs12
.4byte gGroundScript_gs9
.4byte gGroundScript_gs9
.4byte gGroundScript_gs9
.4byte gGroundScript_gs12
.4byte gGroundScript_gs12
.4byte gGroundScript_gs12
.4byte gGroundScript_gs9
.4byte gGroundScript_gs9
.4byte gGroundScript_gs9
.4byte gGroundScript_gs12
.4byte gGroundScript_gs12
.4byte gGroundScript_gs12
.4byte gGroundScript_gs9
.4byte gGroundScript_gs9
.4byte gGroundScript_gs9
.4byte gGroundScript_gs12
.4byte gGroundScript_gs12
.4byte gGroundScript_gs12
.4byte gGroundScript_gs9
.4byte gGroundScript_gs9
.4byte gGroundScript_gs9
.4byte gGroundScript_gs12
.4byte gGroundScript_gs12
.4byte gGroundScript_gs12
.4byte gGroundScript_gs9
.4byte gGroundScript_gs9
.4byte gGroundScript_gs9
.4byte gGroundScript_gs12
.4byte gGroundScript_gs12
.4byte gGroundScript_gs12
.4byte gGroundScript_gs9
.4byte gGroundScript_gs9
.4byte gGroundScript_gs9
.4byte gGroundScript_gs12
.4byte gGroundScript_gs12
.4byte gGroundScript_gs12
.4byte gGroundScript_gs9
.4byte gGroundScript_gs9
.4byte gGroundScript_gs9
.4byte gGroundScript_gs12
.4byte gGroundScript_gs12
.4byte gGroundScript_gs12
.4byte gGroundScript_gs9
.4byte gGroundScript_gs9
.4byte gGroundScript_gs9
.4byte gGroundScript_gs12
.4byte gGroundScript_gs12
.4byte gGroundScript_gs12
.4byte gGroundScript_gs9
.4byte gGroundScript_gs9
.4byte gGroundScript_gs9
.4byte gGroundScript_gs12
.4byte gGroundScript_gs12
.4byte gGroundScript_gs12
.4byte gGroundScript_gs9
.4byte gGroundScript_gs9
.4byte gGroundScript_gs9
.4byte gGroundScript_gs12
.4byte gGroundScript_gs12
.4byte gGroundScript_gs12
.4byte gGroundScript_gs9
.4byte gGroundScript_gs9
.4byte gGroundScript_gs9
.4byte gGroundScript_gs12
.4byte gGroundScript_gs12
.4byte gGroundScript_gs12
.4byte gGroundScript_gs9
.4byte gGroundScript_gs9
.4byte gGroundScript_gs9
.4byte gGroundScript_gs12
.4byte gGroundScript_gs12
.4byte gGroundScript_gs12
.4byte gGroundScript_gs105
.4byte gGroundScript_gs106
.4byte gGroundScript_gs107
.4byte gGroundScript_gs108
.4byte gGroundScript_gs109
.4byte gGroundScript_gs110
.4byte gGroundScript_gs111
.4byte gGroundScript_gs112
.4byte gGroundScript_gs113
.4byte gGroundScript_gs114
.4byte gGroundScript_gs115
.4byte gGroundScript_gs116
.4byte gGroundScript_gs117
.4byte gGroundScript_gs118
.4byte gGroundScript_gs119
.4byte gGroundScript_gs120
.4byte gGroundScript_gs121
.4byte gGroundScript_gs122
.4byte gGroundScript_gs123
.4byte gGroundScript_gs124
.4byte gGroundScript_gs125
.4byte gGroundScript_gs126
.4byte gGroundScript_gs127
.4byte gGroundScript_gs128
.4byte gGroundScript_gs129
.4byte gGroundScript_gs130
.4byte gGroundScript_gs131
.4byte gGroundScript_gs132
.4byte gGroundScript_gs133
.4byte gGroundScript_gs134
.4byte gGroundScript_gs135
.4byte gGroundScript_gs136
.4byte gGroundScript_gs137
.4byte gGroundScript_gs138
.4byte gGroundScript_gs139
.4byte gGroundScript_gs140
.4byte gGroundScript_gs141
.4byte gGroundScript_gs142
.4byte gGroundScript_gs143
.4byte gGroundScript_gs144
.4byte gGroundScript_gs145
.4byte gGroundScript_gs146
.4byte gGroundScript_gs147
.4byte gGroundScript_gs148
.4byte gGroundScript_gs149
.4byte gGroundScript_gs150
.4byte gGroundScript_gs151
.4byte gGroundScript_gs152
.4byte gGroundScript_gs153
.4byte gGroundScript_gs154
.4byte gGroundScript_gs155
.4byte gGroundScript_gs156
.4byte gGroundScript_gs157
.4byte gGroundScript_gs158
.4byte gGroundScript_gs159
.4byte gGroundScript_gs160
.4byte gGroundScript_gs161
.4byte gGroundScript_gs162
.4byte gGroundScript_gs163
.4byte gGroundScript_gs164
.4byte gGroundScript_gs165
.4byte gGroundScript_gs166
.4byte gGroundScript_gs167
.4byte gGroundScript_gs168
.4byte gGroundScript_gs169
.4byte gGroundScript_gs170
.4byte gGroundScript_gs171
.4byte gGroundScript_gs172
.4byte gGroundScript_gs173
.4byte gGroundScript_gs174
.4byte gGroundScript_gs175
.4byte gGroundScript_gs176
.4byte gGroundScript_gs177
.4byte gGroundScript_gs178
.4byte gGroundScript_gs179
.4byte gGroundScript_gs180
.4byte gGroundScript_gs181
.4byte gGroundScript_gs182
.4byte gGroundScript_gs183
.4byte gGroundScript_gs184
.4byte gGroundScript_gs185
.4byte gGroundScript_gs186
.4byte gGroundScript_gs187
.4byte gGroundScript_gs188
.4byte gGroundScript_gs189
.4byte gGroundScript_gs190
.4byte gGroundScript_gs191
.4byte gGroundScript_gs192
.4byte gGroundScript_gs193
.4byte gGroundScript_gs194
.4byte gGroundScript_gs195
.4byte gGroundScript_gs196
.4byte gGroundScript_gs197
.4byte gGroundScript_gs198
.4byte gGroundScript_gs199
.4byte gGroundScript_gs200
.4byte gGroundScript_gs201
.4byte gGroundScript_gs202
.4byte gGroundScript_gs203
.4byte gGroundScript_gs204
.4byte gGroundScript_gs205
.4byte gGroundScript_gs206
.4byte gGroundScript_gs207
.4byte gGroundScript_gs208
.4byte gGroundScript_gs209
.4byte gGroundScript_gs210
.4byte gGroundScript_gs211
.4byte gGroundScript_gs212
.4byte gGroundScript_gs213
.4byte gGroundScript_gs214
.4byte gGroundScript_gs215
.4byte gGroundScript_gs216
.4byte gGroundScript_gs217
.4byte gGroundScript_gs218
.4byte gGroundScript_gs219
.4byte gGroundScript_gs220
.4byte gGroundScript_gs221
.4byte gGroundScript_gs222
.4byte gGroundScript_gs223
.4byte gGroundScript_gs224
.4byte gGroundScript_gs225
.4byte gGroundScript_gs226
.4byte gGroundScript_gs227
.4byte gGroundScript_gs228
.string "pksdir0\0"
.align 2, 0

.global gUnknown_811E5F4
gUnknown_811E5F4: @ 811E5F4
@ replacing .incbin "baserom.gba", 0x11E5F4, 0x48
.byte 0x00, 0x00, 0x09, 0x00, 0x00, 0x00, 0x6b, 0x00, 0x00, 0x00, 0x6f, 0x00, 0x00, 0x00, 0x71, 0x00
.byte 0x00, 0x00, 0x73, 0x00, 0x00, 0x00, 0x83, 0x00, 0x00, 0x00, 0x97, 0x00, 0x00, 0x00, 0x9a, 0x00
.byte 0x00, 0x00, 0xa9, 0x00, 0x01, 0x00, 0xee, 0x00, 0x01, 0x00, 0xef, 0x00, 0x01, 0x00, 0xf0, 0x00
.byte 0x01, 0x00, 0xf1, 0x00, 0x01, 0x00, 0xf2, 0x00, 0x01, 0x00, 0xf3, 0x00, 0x01, 0x00, 0xf4, 0x00
.byte 0x70, 0x6b, 0x73, 0x64, 0x69, 0x72, 0x30, 0x00

.global gGroundLivesTypeData_811E63C
gGroundLivesTypeData_811E63C: @ 811E63C
@ replacing .incbin "baserom.gba", 0x11E63C, 0x6E4
.byte 0x01, 0x00, 0x00, 0x00
.4byte gUnknown_811ED14
.byte 0x02, 0x01, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00
.4byte gUnknown_811ED14
.byte 0x02, 0x01, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00
.4byte gUnknown_811ED14
.byte 0x02, 0x01, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00
.4byte gUnknown_811ED14
.byte 0x02, 0x01, 0x00, 0x00
.byte 0x02, 0x00, 0x00, 0x00
.4byte gUnknown_811ED14
.byte 0x02, 0x01, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00
.4byte gUnknown_811ED14
.byte 0x02, 0x01, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00
.4byte gUnknown_811ED14
.byte 0x02, 0x01, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00
.4byte gUnknown_811ED14
.byte 0x02, 0x01, 0x00, 0x00
.byte 0x02, 0x00, 0x00, 0x00
.4byte gUnknown_811ED14
.byte 0x02, 0x01, 0x00, 0x00, 0x02, 0x00, 0x5e, 0x00
.4byte gUnknown_811ED14
.byte 0x02, 0x01, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00
.4byte gUnknown_811ED14
.byte 0x02, 0x01, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00
.4byte gUnknown_811ED14
.byte 0x02, 0x01, 0x00, 0x00
.byte 0x03, 0x00, 0x00, 0x00
.4byte gUnknown_811ED14
.byte 0x02, 0x01, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00
.4byte gUnknown_811ED14
.byte 0x02, 0x01, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00
.4byte gUnknown_811ED14
.byte 0x02, 0x01, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00
.4byte gUnknown_811ED14
.byte 0x02, 0x01, 0x00, 0x00
.byte 0x03, 0x00, 0x00, 0x00
.4byte gUnknown_811ED14
.byte 0x02, 0x01, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00
.4byte gUnknown_811ED14
.byte 0x02, 0x01, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00
.4byte gUnknown_811ED14
.byte 0x02, 0x01, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00
.4byte gUnknown_811ED14
.byte 0x02, 0x01, 0x00, 0x00
.byte 0x03, 0x00, 0x00, 0x00
.4byte gUnknown_811ED14
.byte 0x02, 0x01, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00
.4byte gUnknown_811ED14
.byte 0x02, 0x01, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00
.4byte gUnknown_811ED14
.byte 0x02, 0x01, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00
.4byte gUnknown_811ED14
.byte 0x02, 0x01, 0x00, 0x00
.byte 0x03, 0x00, 0x00, 0x00
.4byte gUnknown_811ED14
.byte 0x02, 0x01, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00
.4byte gUnknown_811ED14
.byte 0x02, 0x01, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00
.4byte gUnknown_811ED14
.byte 0x02, 0x01, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00
.4byte gUnknown_811ED14
.byte 0x02, 0x01, 0x00, 0x00
.byte 0x03, 0x00, 0x00, 0x00
.4byte gUnknown_811ED14
.byte 0x02, 0x01, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00
.4byte gUnknown_811ED14
.byte 0x02, 0x01, 0x00, 0x00, 0x05, 0x00, 0x00, 0x00
.4byte gUnknown_811ED14
.byte 0x02, 0x01, 0x00, 0x00, 0x05, 0x00, 0x00, 0x00
.4byte gUnknown_811ED14
.byte 0x02, 0x01, 0x00, 0x00
.byte 0x05, 0x00, 0x00, 0x00
.4byte gUnknown_811ED14
.byte 0x02, 0x01, 0x00, 0x00, 0x05, 0x00, 0x00, 0x00
.4byte gUnknown_811ED14
.byte 0x02, 0x01, 0x00, 0x00, 0x05, 0x00, 0x00, 0x00
.4byte gUnknown_811ED14
.byte 0x02, 0x01, 0x00, 0x00, 0x05, 0x00, 0x00, 0x00
.4byte gUnknown_811ED14
.byte 0x02, 0x01, 0x00, 0x00
.byte 0x05, 0x00, 0x00, 0x00
.4byte gUnknown_811ED14
.byte 0x02, 0x01, 0x00, 0x00, 0x05, 0x00, 0x08, 0x00
.4byte gUnknown_811ED14
.byte 0x02, 0x01, 0x00, 0x00, 0x05, 0x00, 0x09, 0x00
.4byte gUnknown_811ED14
.byte 0x02, 0x01, 0x00, 0x00, 0x05, 0x00, 0x34, 0x00
.4byte gUnknown_811ED14
.byte 0x02, 0x01, 0x00, 0x00
.byte 0x05, 0x00, 0x6c, 0x00
.4byte gUnknown_811ED14
.byte 0x02, 0x01, 0x00, 0x00, 0x05, 0x00, 0x9d, 0x01
.4byte gUnknown_811ED14
.byte 0x02, 0x01, 0x00, 0x00, 0x05, 0x00, 0x61, 0x00
.4byte gUnknown_811ED14
.byte 0x02, 0x01, 0x00, 0x00, 0x05, 0x00, 0xa4, 0x00
.4byte gUnknown_811ED14
.byte 0x02, 0x01, 0x00, 0x00
.byte 0x05, 0x00, 0x0b, 0x00
.4byte gUnknown_811ED14
.byte 0x02, 0x01, 0x00, 0x00, 0x05, 0x00, 0x9d, 0x01
.4byte gUnknown_811ED14
.byte 0x02, 0x01, 0x00, 0x00, 0x05, 0x00, 0x28, 0x00
.4byte gUnknown_811ED14
.byte 0x02, 0x01, 0x00, 0x00, 0x05, 0x00, 0x30, 0x01
.4byte gUnknown_811ED14
.byte 0x02, 0x01, 0x00, 0x00
.byte 0x05, 0x00, 0x30, 0x01
.4byte gUnknown_811ED14
.byte 0x02, 0x01, 0x00, 0x00, 0x05, 0x00, 0x30, 0x01
.4byte gUnknown_811ED14
.byte 0x02, 0x01, 0x00, 0x00, 0x05, 0x00, 0x30, 0x01
.4byte gUnknown_811ED14
.byte 0x02, 0x01, 0x00, 0x00, 0x05, 0x00, 0xb8, 0x00
.4byte gUnknown_811ED14
.byte 0x02, 0x01, 0x00, 0x00
.byte 0x05, 0x00, 0x00, 0x00
.4byte gUnknown_811ED14
.byte 0x02, 0x01, 0x00, 0x00, 0x05, 0x00, 0x0c, 0x00
.4byte gUnknown_811ED14
.byte 0x02, 0x01, 0x00, 0x00, 0x05, 0x00, 0x0a, 0x00
.4byte gUnknown_811ED14
.byte 0x02, 0x01, 0x00, 0x00, 0x05, 0x00, 0x30, 0x01
.4byte gUnknown_811ED14
.byte 0x02, 0x01, 0x00, 0x00
.byte 0x05, 0x00, 0x30, 0x01
.4byte gUnknown_811ED14
.byte 0x02, 0x01, 0x00, 0x00, 0x05, 0x00, 0x30, 0x01
.4byte gUnknown_811ED14
.byte 0x02, 0x01, 0x00, 0x00, 0x05, 0x00, 0x30, 0x01
.4byte gUnknown_811ED14
.byte 0x02, 0x01, 0x00, 0x00, 0x05, 0x00, 0x30, 0x01
.4byte gUnknown_811ED14
.byte 0x02, 0x01, 0x00, 0x00
.byte 0x05, 0x00, 0x51, 0x00
.4byte gUnknown_811ED14
.byte 0x02, 0x01, 0x00, 0x00, 0x05, 0x00, 0x51, 0x00
.4byte gUnknown_811ED14
.byte 0x02, 0x01, 0x00, 0x00, 0x05, 0x00, 0x51, 0x00
.4byte gUnknown_811ED14
.byte 0x02, 0x01, 0x00, 0x00, 0x05, 0x00, 0x52, 0x00
.4byte gUnknown_811ED14
.byte 0x02, 0x01, 0x00, 0x00
.byte 0x05, 0x00, 0x51, 0x00
.4byte gUnknown_811ED14
.byte 0x02, 0x01, 0x00, 0x00, 0x05, 0x00, 0x51, 0x00
.4byte gUnknown_811ED14
.byte 0x02, 0x01, 0x00, 0x00, 0x05, 0x00, 0x33, 0x00
.4byte gUnknown_811ED14
.byte 0x02, 0x01, 0x00, 0x00, 0x05, 0x00, 0x33, 0x00
.4byte gUnknown_811ED14
.byte 0x02, 0x01, 0x00, 0x00
.byte 0x05, 0x00, 0x32, 0x00
.4byte gUnknown_811ED14
.byte 0x02, 0x01, 0x00, 0x00, 0x05, 0x00, 0xfc, 0x00
.4byte gUnknown_811ED14
.byte 0x02, 0x01, 0x00, 0x00, 0x05, 0x00, 0x7c, 0x01
.4byte gUnknown_811ED14
.byte 0x02, 0x01, 0x00, 0x00, 0x05, 0x00, 0x7c, 0x01
.4byte gUnknown_811ED14
.byte 0x02, 0x01, 0x00, 0x00
.byte 0x05, 0x00, 0x35, 0x00
.4byte gUnknown_811ED14
.byte 0x02, 0x01, 0x00, 0x00, 0x05, 0x00, 0x28, 0x00
.4byte gUnknown_811ED14
.byte 0x02, 0x01, 0x00, 0x00, 0x05, 0x00, 0x55, 0x01
.4byte gUnknown_811ED14
.byte 0x02, 0x01, 0x00, 0x00, 0x05, 0x00, 0x73, 0x00
.4byte gUnknown_811ED14
.byte 0x02, 0x01, 0x00, 0x00
.byte 0x05, 0x00, 0x55, 0x01
.4byte gUnknown_811ED14
.byte 0x02, 0x01, 0x00, 0x00, 0x05, 0x00, 0x28, 0x01
.4byte gUnknown_811ED14
.byte 0x02, 0x01, 0x00, 0x00, 0x05, 0x00, 0xbd, 0x00
.4byte gUnknown_811ED14
.byte 0x02, 0x01, 0x00, 0x00, 0x05, 0x00, 0x45, 0x00
.4byte gUnknown_811ED14
.byte 0x02, 0x01, 0x00, 0x00
.byte 0x05, 0x00, 0xea, 0x00
.4byte gUnknown_811ED14
.byte 0x02, 0x01, 0x00, 0x00, 0x05, 0x00, 0xeb, 0x00
.4byte gUnknown_811ED14
.byte 0x02, 0x01, 0x00, 0x00, 0x05, 0x00, 0x33, 0x01
.4byte gUnknown_811ED14
.byte 0x02, 0x01, 0x00, 0x00, 0x05, 0x00, 0x83, 0x01
.4byte gUnknown_811ED14
.byte 0x02, 0x01, 0x00, 0x00
.byte 0x05, 0x00, 0x41, 0x01
.4byte gUnknown_811ED14
.byte 0x02, 0x01, 0x00, 0x00, 0x05, 0x00, 0x2c, 0x01
.4byte gUnknown_811ED14
.byte 0x02, 0x01, 0x00, 0x00, 0x05, 0x00, 0x2b, 0x01
.4byte gUnknown_811ED14
.byte 0x02, 0x01, 0x00, 0x00, 0x05, 0x00, 0x2b, 0x01
.4byte gUnknown_811ED14
.byte 0x02, 0x01, 0x00, 0x00
.byte 0x05, 0x00, 0x41, 0x00
.4byte gUnknown_811ED14
.byte 0x02, 0x01, 0x00, 0x00, 0x05, 0x00, 0x06, 0x00
.4byte gUnknown_811ED14
.byte 0x02, 0x01, 0x00, 0x00, 0x05, 0x00, 0x11, 0x01
.4byte gUnknown_811ED14
.byte 0x02, 0x01, 0x00, 0x00, 0x05, 0x00, 0x5e, 0x00
.4byte gUnknown_811ED14
.byte 0x02, 0x01, 0x00, 0x00
.byte 0x05, 0x00, 0x17, 0x00
.4byte gUnknown_811ED14
.byte 0x02, 0x01, 0x00, 0x00, 0x05, 0x00, 0x4d, 0x01
.4byte gUnknown_811ED14
.byte 0x02, 0x01, 0x00, 0x00, 0x05, 0x00, 0x0b, 0x00
.4byte gUnknown_811ED14
.byte 0x02, 0x01, 0x00, 0x00, 0x05, 0x00, 0xbd, 0x00
.4byte gUnknown_811ED14
.byte 0x02, 0x01, 0x00, 0x00
.byte 0x05, 0x00, 0x91, 0x00
.4byte gUnknown_811ED14
.byte 0x03, 0x01, 0x00, 0x00, 0x05, 0x00, 0xb2, 0x00
.4byte gUnknown_811ED14
.byte 0x02, 0x01, 0x00, 0x00, 0x05, 0x00, 0x6d, 0x01
.4byte gUnknown_811ED14
.byte 0x02, 0x01, 0x00, 0x00, 0x05, 0x00, 0x26, 0x00
.4byte gUnknown_811ED14
.byte 0x03, 0x01, 0x00, 0x00
.byte 0x05, 0x00, 0xa5, 0x01
.4byte gUnknown_811ED14
.byte 0x02, 0x01, 0x00, 0x00, 0x05, 0x00, 0x92, 0x00
.4byte gUnknown_811ED14
.byte 0x03, 0x01, 0x00, 0x00, 0x05, 0x00, 0x90, 0x00
.4byte gUnknown_811ED14
.byte 0x03, 0x01, 0x00, 0x00, 0x05, 0x00, 0x9b, 0x01
.4byte gUnknown_811ED14
.byte 0x03, 0x01, 0x00, 0x00
.byte 0x05, 0x00, 0x09, 0x00
.4byte gUnknown_811ED14
.byte 0x03, 0x01, 0x00, 0x00, 0x05, 0x00, 0xf9, 0x00
.4byte gUnknown_811ED14
.byte 0x03, 0x01, 0x00, 0x00, 0x05, 0x00, 0x4c, 0x00
.4byte gUnknown_811ED14
.byte 0x03, 0x01, 0x00, 0x00, 0x05, 0x00, 0x09, 0x00
.4byte gUnknown_811ED14
.byte 0x03, 0x01, 0x00, 0x00
.byte 0x05, 0x00, 0xa7, 0x01
.4byte gUnknown_811ED14
.byte 0x03, 0x01, 0x00, 0x00, 0x05, 0x00, 0x84, 0x01
.4byte gUnknown_811ED14
.byte 0x02, 0x01, 0x00, 0x00, 0x05, 0x00, 0xe3, 0x00
.4byte gUnknown_811ED14
.byte 0x02, 0x01, 0x00, 0x00, 0x05, 0x00, 0x38, 0x00
.4byte gUnknown_811ED14
.byte 0x02, 0x01, 0x00, 0x00
.byte 0x05, 0x00, 0x38, 0x00
.4byte gUnknown_811ED14
.byte 0x02, 0x01, 0x00, 0x00, 0x05, 0x00, 0x38, 0x00
.4byte gUnknown_811ED14
.byte 0x02, 0x01, 0x00, 0x00, 0x05, 0x00, 0x38, 0x00
.4byte gUnknown_811ED14
.byte 0x02, 0x01, 0x00, 0x00, 0x05, 0x00, 0x60, 0x01
.4byte gUnknown_811ED14
.byte 0x02, 0x01, 0x00, 0x00
.byte 0x05, 0x00, 0x0d, 0x01
.4byte gUnknown_811ED14
.byte 0x02, 0x01, 0x00, 0x00, 0x05, 0x00, 0x0c, 0x01
.4byte gUnknown_811ED14
.byte 0x02, 0x01, 0x00, 0x00, 0x05, 0x00, 0x0e, 0x01
.4byte gUnknown_811ED14
.byte 0x02, 0x01, 0x00, 0x00, 0x05, 0x00, 0x13, 0x01
.4byte gUnknown_811ED14
.byte 0x02, 0x01, 0x00, 0x00
.byte 0x05, 0x00, 0x96, 0x00
.4byte gUnknown_811ED14
.byte 0x02, 0x01, 0x00, 0x00, 0x05, 0x00, 0x99, 0x01
.4byte gUnknown_811ED14
.byte 0x02, 0x01, 0x00, 0x00, 0x05, 0x00, 0x98, 0x01
.4byte gUnknown_811ED14
.byte 0x02, 0x01, 0x00, 0x00, 0x05, 0x00, 0x9d, 0x01
.4byte gUnknown_811ED14
.byte 0x02, 0x01, 0x00, 0x00
.byte 0x05, 0x00, 0x04, 0x01
.4byte gUnknown_811ED14
.byte 0x02, 0x01, 0x00, 0x00, 0x05, 0x00, 0x04, 0x01
.4byte gUnknown_811ED14
.byte 0x02, 0x01, 0x00, 0x00, 0x05, 0x00, 0x04, 0x01
.4byte gUnknown_811ED14
.byte 0x02, 0x01, 0x00, 0x00, 0x05, 0x00, 0xa4, 0x01
.4byte gUnknown_811ED14
.byte 0x02, 0x01, 0x00, 0x00
.byte 0x05, 0x00, 0x97, 0x00
.4byte gUnknown_811ED14
.byte 0x02, 0x01, 0x00, 0x00, 0x05, 0x00, 0x95, 0x01
.4byte gUnknown_811ED14
.byte 0x02, 0x01, 0x00, 0x00, 0x05, 0x00, 0x96, 0x01
.4byte gUnknown_811ED14
.byte 0x02, 0x01, 0x00, 0x00, 0x05, 0x00, 0x97, 0x01
.4byte gUnknown_811ED14
.byte 0x02, 0x01, 0x00, 0x00
.byte 0x05, 0x00, 0x9a, 0x01
.4byte gUnknown_811ED14
.byte 0x03, 0x01, 0x00, 0x00, 0x05, 0x00, 0x12, 0x01
.4byte gUnknown_811ED14
.byte 0x03, 0x01, 0x00, 0x00, 0x05, 0x00, 0x9e, 0x01
.4byte gUnknown_811ED14
.byte 0x02, 0x01, 0x00, 0x00, 0x05, 0x00, 0x1a, 0x00
.4byte gUnknown_811ED14
.byte 0x02, 0x01, 0x00, 0x00
.byte 0x05, 0x00, 0x2a, 0x00
.4byte gUnknown_811ED14
.byte 0x02, 0x01, 0x00, 0x00, 0x05, 0x00, 0x70, 0x00
.4byte gUnknown_811ED14
.byte 0x02, 0x01, 0x00, 0x00, 0x05, 0x00, 0x7a, 0x00
.4byte gUnknown_811ED14
.byte 0x02, 0x01, 0x00, 0x00, 0x05, 0x00, 0x7b, 0x00
.4byte gUnknown_811ED14
.byte 0x02, 0x01, 0x00, 0x00
.byte 0x05, 0x00, 0x7f, 0x00
.4byte gUnknown_811ED14
.byte 0x02, 0x01, 0x00, 0x00, 0x05, 0x00, 0x9a, 0x00
.4byte gUnknown_811ED14
.byte 0x02, 0x01, 0x00, 0x00, 0x05, 0x00, 0xbe, 0x00
.4byte gUnknown_811ED14
.byte 0x02, 0x01, 0x00, 0x00, 0x05, 0x00, 0x00, 0x01
.4byte gUnknown_811ED14
.byte 0x02, 0x01, 0x00, 0x00
.byte 0x05, 0x00, 0xa6, 0x01
.4byte gUnknown_811ED14
.byte 0x02, 0x01, 0x00, 0x00, 0x05, 0x00, 0xa6, 0x01
.4byte gUnknown_811ED14
.byte 0x02, 0x01, 0x00, 0x00

.global gUnknown_811ED14
gUnknown_811ED14: @ 811ED14
.byte 0x2d, 0x00, 0x00, 0x00, 0x70, 0x6b, 0x73, 0x64
.byte 0x69, 0x72, 0x30, 0x00

.global gGroundObjectTypes
gGroundObjectTypes: @ 811ED20
@ replacing .incbin "baserom.gba", 0x11ED20, 0x118
.byte 0x01, 0x00, 0x01, 0x01, 0x0e, 0x00, 0x01, 0x01, 0x09, 0x00, 0x00, 0x00, 0x05, 0x00, 0x00, 0x00
.byte 0x07, 0x00, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x03, 0x00, 0x03, 0x01, 0x04, 0x00, 0x00, 0x00
.byte 0x04, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00
.byte 0x0a, 0x00, 0x00, 0x00, 0x05, 0x00, 0x00, 0x00, 0x05, 0x00, 0x00, 0x00, 0x05, 0x00, 0x00, 0x00
.byte 0x05, 0x00, 0x03, 0x01, 0x08, 0x00, 0x00, 0x00, 0x05, 0x00, 0x00, 0x00, 0x05, 0x00, 0x00, 0x00
.byte 0x02, 0x00, 0x03, 0x03, 0x02, 0x00, 0x03, 0x04, 0x02, 0x00, 0x03, 0x03, 0x02, 0x00, 0x03, 0x04
.byte 0x02, 0x00, 0x06, 0x04, 0x0b, 0x00, 0x03, 0x01, 0x0b, 0x00, 0x04, 0x03, 0x0b, 0x00, 0x04, 0x03
.byte 0x0b, 0x00, 0x04, 0x03, 0x0b, 0x00, 0x04, 0x03, 0x0b, 0x00, 0x04, 0x03, 0x0b, 0x00, 0x04, 0x03
.byte 0x0b, 0x00, 0x04, 0x03, 0x0b, 0x00, 0x04, 0x03, 0x0b, 0x00, 0x04, 0x03, 0x0b, 0x00, 0x04, 0x03
.byte 0x0b, 0x00, 0x04, 0x03, 0x0b, 0x00, 0x04, 0x03, 0x0b, 0x00, 0x04, 0x03, 0x0b, 0x00, 0x04, 0x03
.byte 0x0b, 0x00, 0x04, 0x03, 0x0b, 0x00, 0x04, 0x03, 0x0b, 0x00, 0x04, 0x03, 0x0b, 0x00, 0x04, 0x03
.byte 0x0b, 0x00, 0x04, 0x03, 0x0b, 0x00, 0x04, 0x03, 0x0b, 0x00, 0x04, 0x03, 0x0b, 0x00, 0x04, 0x03
.byte 0x0b, 0x00, 0x04, 0x03, 0x0b, 0x00, 0x04, 0x03, 0x0b, 0x00, 0x04, 0x03, 0x0b, 0x00, 0x04, 0x03
.byte 0x0b, 0x00, 0x04, 0x03, 0x0b, 0x00, 0x04, 0x03, 0x0b, 0x00, 0x04, 0x03, 0x0b, 0x00, 0x04, 0x03
.byte 0x0b, 0x00, 0x04, 0x03, 0x0b, 0x00, 0x04, 0x03, 0x0b, 0x00, 0x04, 0x03, 0x0e, 0x00, 0x02, 0x01
.byte 0x0e, 0x00, 0x02, 0x01, 0x0a, 0x00, 0x02, 0x01, 0x09, 0x00, 0x02, 0x02, 0x09, 0x00, 0x02, 0x02
.byte 0x09, 0x00, 0x02, 0x02, 0x09, 0x00, 0x02, 0x02, 0x0a, 0x00, 0x02, 0x02, 0x0e, 0x00, 0x02, 0x02
.byte 0x70, 0x6b, 0x73, 0x64, 0x69, 0x72, 0x30, 0x00

.global gGroundEffectTypes
gGroundEffectTypes: @ 811EE38
@ replacing .incbin "baserom.gba", 0x11EE38, 0x103B8
.byte 0x01, 0x00, 0x01, 0x01, 0x01, 0x00, 0x01, 0x01, 0x02, 0x00, 0x01, 0x01, 0x02, 0x00, 0x00, 0x00
.byte 0x02, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x05, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00
.byte 0x03, 0x00, 0x01, 0x01
