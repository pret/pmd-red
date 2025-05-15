.section .rodata

.align 2



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
.string "{COLOR RED_W}invalidity{RESET}\0"
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
