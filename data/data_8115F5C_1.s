.section .rodata

.align 2




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
