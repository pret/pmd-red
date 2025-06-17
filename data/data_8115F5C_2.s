.section .rodata


.align 2,0



.byte 0x70, 0x6b, 0x73, 0x64, 0x69, 0x72, 0x30, 0x00, 0x00, 0x00, 0x00, 0x00, 0x70, 0x6b, 0x73, 0x64
.byte 0x69, 0x72, 0x30, 0x00

.global gUnknown_811633C
gUnknown_811633C: @ 811633C
.string "{CENTER_ALIGN}{NAME_0}'s team received\n"
.string "{CENTER_ALIGN}the {MOVE_ITEM_0} cash reward.\0"
.align 2, 0

.global gUnknown_811636C
gUnknown_811636C: @ 811636C
.string "{CENTER_ALIGN}The team also received\n"
.string "{CENTER_ALIGN}one {MOVE_ITEM_0}.\0"
.align 2, 0

.global gUnknown_8116390
gUnknown_8116390: @ 8116390
.string "{CENTER_ALIGN}{NAME_0}'s team received\n"
.string "{CENTER_ALIGN}the reward {MOVE_ITEM_0}.\0"
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
.string "{COLOR CYAN_G}%d{RESET} %s\0"
.align 2,0

.global gUnknown_81163F0
gUnknown_81163F0: @ 81163F0
.string "{CENTER_ALIGN}However, {NAME_0}'s team\n"
.string "{CENTER_ALIGN}had too much money already...\0"
.align 2,0

.global gUnknown_811642C
gUnknown_811642C: @ 811642C
.string "{CENTER_ALIGN}However, {NAME_0}'s team\n"
.string "{CENTER_ALIGN}had too many items already...\0"
.align 2,0

