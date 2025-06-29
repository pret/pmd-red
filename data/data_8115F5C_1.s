.section .rodata

.align 2

@ ground_effect.c

.byte 0xf6, 0x00, 0x9b, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.4byte gUnknown_81185D8
.byte 0xf4, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.byte 0xdb, 0x00, 0x78, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.byte 0xe7, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00

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
