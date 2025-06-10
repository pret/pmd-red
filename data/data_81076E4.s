.section .rodata




@ START friend_area.c
.string "pksdir0\0"

.global sUnknown_81098A4
sUnknown_81098A4: @ 81098A4
.string "{color GREEN_RAW}%s{reset}\0"
.align 2,0

.global sUnknown_81098AC
sUnknown_81098AC: @ 81098AC
.string "%s{UNK_MACRO_3D}%c{COLOR GREEN_RAW}%s{RESET}\0"
.align 2,0
@ END friend_area.c
@ moves.c
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
.string "{color}%c%s%s{reset}\0"
.align 2,0

.global gUnknown_81098EC
gUnknown_81098EC: @ 81098EC
.string "{color}%c#:%s%s%s#;%c%2d/%2d{reset}\0"
.align 2,0

.global gUnknown_8109908
gUnknown_8109908: @ 8109908
.byte 0x87, 0x41, 0x00, 0x00 @ apparently shows A in memory viewer

.global gUnknown_810990C
gUnknown_810990C: @ 810990C
.byte 0x87, 0x40, 0x00, 0x00 @ apparently shows @ in memory viewer

.global gUnknown_8109910
gUnknown_8109910: @ 8109910
.string "{color}%c%s%s%s{UNK_MACRO_3D}%c%2d/%2d{reset}\0"
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
.string "{POKEMON_0}\0"
.align 2,0
@ ???
.string "pksdir0\0"
.align 2,0
@ ???
.string "pksdir0\0"
.align 2,0
@ ???
.string "pksdir0\0"
.align 2,0

