#include "constants/status.h"
.section .rodata
#.incbin "baserom.gba", 0xF59C4, 0x4

.global gUnknown_80F59C8
gUnknown_80F59C8: @ 80F59C8
@ replacing .incbin "baserom.gba", 0xF59C8, 0x348
.byte 0x01, 0x00, 0x00, 0x00
.4byte sub_8057634
.byte 0x03, 0x00, 0x00, 0x00
.4byte YawnMoveAction
.byte 0x05, 0x00, 0x00, 0x00
.4byte NightmareMoveAction
.byte 0x0b, 0x00, 0x00, 0x00
.4byte sub_805783C
.byte 0x11, 0x00, 0x00, 0x00
.4byte EncoreMoveAction
.byte 0x14, 0x00, 0x00, 0x00
.4byte sub_8057974
.byte 0x15, 0x00, 0x00, 0x00
.4byte PainSplitMoveAction
.byte 0x16, 0x00, 0x00, 0x00
.4byte TormentMoveAction
.byte 0x18, 0x00, 0x00, 0x00
.4byte sub_8057BC4
.byte 0x1e, 0x00, 0x00, 0x00
.4byte sub_8057C88
.byte 0x20, 0x00, 0x00, 0x00
.4byte WhirlpoolMoveAction
.byte 0x21, 0x00, 0x00, 0x00
.4byte sub_8057D7C
.byte 0x23, 0x00, 0x00, 0x00
.4byte sub_8057D9C
.byte 0x25, 0x00, 0x00, 0x00
.4byte SmokescreenMoveAction
.byte 0x2d, 0x00, 0x00, 0x00
.4byte sub_8057FCC
.byte 0x2f, 0x00, 0x00, 0x00
.4byte sub_8057FF4
.byte 0x30, 0x00, 0x00, 0x00
.4byte sub_805805C
.byte 0x34, 0x00, 0x00, 0x00
.4byte sub_805816C
.byte 0x39, 0x00, 0x00, 0x00
.4byte sub_8058270
.byte 0x3b, 0x00, 0x00, 0x00
.4byte sub_80582C4
.byte 0x3e, 0x00, 0x00, 0x00
.4byte sub_80583D8
.byte 0x3f, 0x00, 0x00, 0x00
.4byte sub_8058430
.byte 0x40, 0x00, 0x00, 0x00
.4byte sub_8058478
.byte 0x42, 0x00, 0x00, 0x00
.4byte sub_80584C0
.byte 0x43, 0x00, 0x00, 0x00
.4byte sub_8058548
.byte 0x47, 0x00, 0x00, 0x00
.4byte sub_8058580
.byte 0x48, 0x00, 0x00, 0x00
.4byte BrickBreakMoveAction
.byte 0x49, 0x00, 0x00, 0x00
.4byte sub_8058638
.byte 0x4c, 0x00, 0x00, 0x00
.4byte sub_80586DC
.byte 0x4d, 0x00, 0x00, 0x00
.4byte sub_8058770
.byte 0x4e, 0x00, 0x00, 0x00
.4byte sub_80587E8
.byte 0x53, 0x00, 0x00, 0x00
.4byte sub_8058838
.byte 0x55, 0x00, 0x00, 0x00
.4byte sub_8058858
.byte 0x5b, 0x00, 0x00, 0x00
.4byte sub_80588B8
.byte 0x5c, 0x00, 0x00, 0x00
.4byte sub_80588F4
.byte 0x5d, 0x00, 0x00, 0x00
.4byte sub_8058930
.byte 0x60, 0x00, 0x00, 0x00
.4byte sub_8058A18
.byte 0x6a, 0x00, 0x00, 0x00
.4byte sub_8058BF0
.byte 0x74, 0x00, 0x00, 0x00
.4byte sub_8058E5C
.byte 0x78, 0x00, 0x00, 0x00
.4byte sub_8058FBC
.byte 0x83, 0x00, 0x00, 0x00
.4byte sub_80590D4
.byte 0x85, 0x00, 0x00, 0x00
.4byte sub_8059190
.byte 0x87, 0x00, 0x00, 0x00
.4byte sub_80591E4
.byte 0x89, 0x00, 0x00, 0x00
.4byte SkillSwapMoveAction
.byte 0x8b, 0x00, 0x00, 0x00
.4byte sub_8059424
.byte 0x8c, 0x00, 0x00, 0x00
.4byte sub_805946C
.byte 0x8e, 0x00, 0x00, 0x00
.4byte sub_8059528
.byte 0x93, 0x00, 0x00, 0x00
.4byte sub_8059540
.byte 0x95, 0x00, 0x00, 0x00
.4byte sub_80595A0
.byte 0x96, 0x00, 0x00, 0x00
.4byte sub_80595EC
.byte 0x9f, 0x00, 0x00, 0x00
.4byte sub_80598CC
.byte 0xa2, 0x00, 0x00, 0x00
.4byte sub_8059928
.byte 0xa4, 0x00, 0x00, 0x00
.4byte sub_8059988
.byte 0xaa, 0x00, 0x00, 0x00
.4byte sub_8059A2C
.byte 0xab, 0x00, 0x00, 0x00
.4byte sub_8059AA8
.byte 0xac, 0x00, 0x00, 0x00
.4byte sub_8059AB8
.byte 0xb1, 0x00, 0x00, 0x00
.4byte sub_8059AF8
.byte 0xbc, 0x00, 0x00, 0x00
.4byte sub_8059D00
.byte 0xc0, 0x00, 0x00, 0x00
.4byte sub_8059D48
.byte 0xc2, 0x00, 0x00, 0x00
.4byte sub_8059D98
.byte 0xc4, 0x00, 0x00, 0x00
.4byte sub_8059DA4
.byte 0xc5, 0x00, 0x00, 0x00
.4byte sub_8059DB4
.byte 0xc6, 0x00, 0x00, 0x00
.4byte sub_8059DC4
.byte 0xc8, 0x00, 0x00, 0x00
.4byte sub_8059E0C
.byte 0xcf, 0x00, 0x00, 0x00
.4byte TriAttackMoveAction
.byte 0xd1, 0x00, 0x00, 0x00
.4byte sub_805A120
.byte 0xd2, 0x00, 0x00, 0x00
.4byte sub_805A210
.byte 0xd5, 0x00, 0x00, 0x00
.4byte sub_805A258
.byte 0xd6, 0x00, 0x00, 0x00
.4byte sub_805A2A0
.byte 0xdc, 0x00, 0x00, 0x00
.4byte RolePlayMoveAction
.byte 0xe0, 0x00, 0x00, 0x00
.4byte sub_805A3DC
.byte 0xe4, 0x00, 0x00, 0x00
.4byte sub_805A464
.byte 0xed, 0x00, 0x00, 0x00
.4byte CurseMoveAction
.byte 0xee, 0x00, 0x00, 0x00
.4byte sub_805A568
.byte 0xf3, 0x00, 0x00, 0x00
.4byte TickleMoveAction
.byte 0xf6, 0x00, 0x00, 0x00
.4byte sub_805A688
.byte 0xf9, 0x00, 0x00, 0x00
.4byte KnockOffMoveAction
.byte 0x07, 0x01, 0x00, 0x00
.4byte SecretPowerMoveAction
.byte 0x08, 0x01, 0x00, 0x00
.4byte sub_805AC90
.byte 0x0a, 0x01, 0x00, 0x00
.4byte sub_805AD04
.byte 0x0b, 0x01, 0x00, 0x00
.4byte sub_805AD34
.byte 0x0d, 0x01, 0x00, 0x00
.4byte sub_805AD54
.byte 0x10, 0x01, 0x00, 0x00
.4byte sub_805AE3C
.byte 0x13, 0x01, 0x00, 0x00
.4byte sub_805AE74
.byte 0x14, 0x01, 0x00, 0x00
.4byte sub_805AECC
.byte 0x15, 0x01, 0x00, 0x00
.4byte PresentMoveAction
.byte 0x16, 0x01, 0x00, 0x00
.4byte sub_805AFA4
.byte 0x19, 0x01, 0x00, 0x00
.4byte sub_805B028
.byte 0x1b, 0x01, 0x00, 0x00
.4byte sub_805B074
.byte 0x1c, 0x01, 0x00, 0x00
.4byte sub_805B0BC
.byte 0x23, 0x01, 0x00, 0x00
.4byte sub_805B17C
.byte 0x26, 0x01, 0x00, 0x00
.4byte WrapMoveAction
.byte 0x28, 0x01, 0x00, 0x00
.4byte sub_805B264
.byte 0x35, 0x01, 0x00, 0x00
.4byte sub_805B324
.byte 0x39, 0x01, 0x00, 0x00
.4byte DestinyBondMoveAction
.byte 0x3a, 0x01, 0x00, 0x00
.4byte sub_805B388
.byte 0x44, 0x01, 0x00, 0x00
.4byte sub_805B3E0
.byte 0x46, 0x01, 0x00, 0x00
.4byte sub_805B454
.byte 0x47, 0x01, 0x00, 0x00
.4byte MimicMoveAction
.byte 0x48, 0x01, 0x00, 0x00
.4byte sub_805B53C
.byte 0x49, 0x01, 0x00, 0x00
.4byte LeechSeedMoveAction
.byte 0x4b, 0x01, 0x00, 0x00
.4byte sub_805B668
.byte 0x4f, 0x01, 0x00, 0x00
.4byte sub_805B910
.byte 0x55, 0x01, 0x00, 0x00
.4byte sub_805B808
.byte 0xe2, 0x00, 0x00, 0x00
.4byte sub_805A408

.global gNaturePowerMoveTable
gNaturePowerMoveTable: @ 80F5D10
@ replacing .incbin "baserom.gba", 0xF5D10, 0x260
.byte 0xdb, 0x00, 0x00, 0x00
.4byte sub_8055620
.byte 0x7c, 0x00, 0x00, 0x00
.4byte sub_8059050
.byte 0x1e, 0x00, 0x00, 0x00
.4byte sub_8057C88
.byte 0x7f, 0x00, 0x00, 0x00
.4byte sub_80583D8
.byte 0x7f, 0x00, 0x00, 0x00
.4byte sub_80583D8
.byte 0x1e, 0x00, 0x00, 0x00
.4byte sub_8057C88
.byte 0x1e, 0x00, 0x00, 0x00
.4byte sub_8057C88
.byte 0x7f, 0x00, 0x00, 0x00
.4byte sub_80583D8
.byte 0x91, 0x00, 0x00, 0x00
.4byte sub_8055620
.byte 0x1e, 0x00, 0x00, 0x00
.4byte sub_8057C88
.byte 0x7c, 0x00, 0x00, 0x00
.4byte sub_8059050
.byte 0x76, 0x00, 0x00, 0x00
.4byte sub_8055620
.byte 0x91, 0x00, 0x00, 0x00
.4byte sub_8055620
.byte 0x91, 0x00, 0x00, 0x00
.4byte sub_8055620
.byte 0x7c, 0x00, 0x00, 0x00
.4byte sub_8059050
.byte 0x91, 0x00, 0x00, 0x00
.4byte sub_8055620
.byte 0x91, 0x00, 0x00, 0x00
.4byte sub_8055620
.byte 0x7f, 0x00, 0x00, 0x00
.4byte sub_80583D8
.byte 0x7f, 0x00, 0x00, 0x00
.4byte sub_80583D8
.byte 0x7f, 0x00, 0x00, 0x00
.4byte sub_80583D8
.byte 0x7c, 0x00, 0x00, 0x00
.4byte sub_8059050
.byte 0x76, 0x00, 0x00, 0x00
.4byte sub_8055620
.byte 0x1e, 0x00, 0x00, 0x00
.4byte sub_8057C88
.byte 0x91, 0x00, 0x00, 0x00
.4byte sub_8055620
.byte 0x1e, 0x00, 0x00, 0x00
.4byte sub_8057C88
.byte 0x7c, 0x00, 0x00, 0x00
.4byte sub_8059050
.byte 0x7c, 0x00, 0x00, 0x00
.4byte sub_8059050
.byte 0x91, 0x00, 0x00, 0x00
.4byte sub_8055620
.byte 0x1e, 0x00, 0x00, 0x00
.4byte sub_8057C88
.byte 0xfb, 0x00, 0x00, 0x00
.4byte sub_8055620
.byte 0x7f, 0x00, 0x00, 0x00
.4byte sub_80583D8
.byte 0x7f, 0x00, 0x00, 0x00
.4byte sub_80583D8
.byte 0xfb, 0x00, 0x00, 0x00
.4byte sub_8055620
.byte 0xfb, 0x00, 0x00, 0x00
.4byte sub_8055620
.byte 0x1e, 0x00, 0x00, 0x00
.4byte sub_8057C88
.byte 0x91, 0x00, 0x00, 0x00
.4byte sub_8055620
.byte 0x91, 0x00, 0x00, 0x00
.4byte sub_8055620
.byte 0x7f, 0x00, 0x00, 0x00
.4byte sub_80583D8
.byte 0x1e, 0x00, 0x00, 0x00
.4byte sub_8057C88
.byte 0x1e, 0x00, 0x00, 0x00
.4byte sub_8057C88
.byte 0x1e, 0x00, 0x00, 0x00
.4byte sub_8057C88
.byte 0x7c, 0x00, 0x00, 0x00
.4byte sub_8059050
.byte 0x1e, 0x00, 0x00, 0x00
.4byte sub_8057C88
.byte 0x1e, 0x00, 0x00, 0x00
.4byte sub_8057C88
.byte 0x76, 0x00, 0x00, 0x00
.4byte sub_8055620
.byte 0x91, 0x00, 0x00, 0x00
.4byte sub_8055620
.byte 0x1e, 0x00, 0x00, 0x00
.4byte sub_8057C88
.byte 0x1e, 0x00, 0x00, 0x00
.4byte sub_8057C88
.byte 0x1e, 0x00, 0x00, 0x00
.4byte sub_8057C88
.byte 0xdb, 0x00, 0x00, 0x00
.4byte sub_8055620
.byte 0x7c, 0x00, 0x00, 0x00
.4byte sub_8059050
.byte 0x7c, 0x00, 0x00, 0x00
.4byte sub_8059050
.byte 0x76, 0x00, 0x00, 0x00
.4byte sub_8055620
.byte 0xff, 0x00, 0x00, 0x00
.4byte sub_8058580
.byte 0x7f, 0x00, 0x00, 0x00
.4byte sub_80583D8
.byte 0x1e, 0x00, 0x00, 0x00
.4byte sub_8057C88
.byte 0x7c, 0x00, 0x00, 0x00
.4byte sub_8059050
.byte 0x91, 0x00, 0x00, 0x00
.4byte sub_8055620
.byte 0x91, 0x00, 0x00, 0x00
.4byte sub_8055620
.byte 0x1e, 0x00, 0x00, 0x00
.4byte sub_8057C88
.byte 0x7c, 0x00, 0x00, 0x00
.4byte sub_8059050
.byte 0x7f, 0x00, 0x00, 0x00
.4byte sub_80583D8
.byte 0x7c, 0x00, 0x00, 0x00
.4byte sub_8059050
.byte 0x7c, 0x00, 0x00, 0x00
.4byte sub_8059050
.byte 0x1e, 0x00, 0x00, 0x00
.4byte sub_8057C88
.byte 0xfb, 0x00, 0x00, 0x00
.4byte sub_8055620
.byte 0x1e, 0x00, 0x00, 0x00
.4byte sub_8057C88
.byte 0x1e, 0x00, 0x00, 0x00
.4byte sub_8057C88
.byte 0x91, 0x00, 0x00, 0x00
.4byte sub_8055620
.byte 0x91, 0x00, 0x00, 0x00
.4byte sub_8055620
.byte 0x1e, 0x00, 0x00, 0x00
.4byte sub_8057C88
.byte 0x91, 0x00, 0x00, 0x00
.4byte sub_8055620
.byte 0x91, 0x00, 0x00, 0x00
.4byte sub_8055620
.byte 0xdb, 0x00, 0x00, 0x00
.4byte sub_8055620
.byte 0xdb, 0x00, 0x00, 0x00
.4byte sub_8055620
.byte 0x1e, 0x00, 0x00, 0x00
.4byte sub_8055620

.global gUnknown_80F5F70
gUnknown_80F5F70: @ 80F5F70
@ replacing .incbin "baserom.gba", 0xF5F70, 0x3C
.byte 0x0c, 0x00, 0x0c, 0x00, 0x0c, 0x00, 0x0c, 0x00, 0x0c, 0x00, 0x0d, 0x00, 0x0c, 0x00, 0x0c, 0x00
.byte 0x0c, 0x00, 0x0c, 0x00, 0x0c, 0x00, 0x0c, 0x00, 0x0c, 0x00, 0x0c, 0x00, 0x0c, 0x00, 0x0c, 0x00
.byte 0x0d, 0x00, 0x0d, 0x00, 0x0c, 0x00, 0x0c, 0x00, 0x0c, 0x00, 0x0c, 0x00, 0x0c, 0x00, 0x0c, 0x00
.byte 0x0c, 0x00, 0x0c, 0x00, 0x0c, 0x00, 0x0d, 0x00, 0x0c, 0x00, 0x00, 0x00

.global gUnknown_80F5FAC
gUnknown_80F5FAC: @ 80F5FAC
@ replacing .incbin "baserom.gba", 0xF5FAC, 0x130
.byte 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00
.byte 0x00, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00
.byte 0x03, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.byte 0x00, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00
.byte 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00
.byte 0x00, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.byte 0x01, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.byte 0x03, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00
.byte 0x04, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00
.byte 0x01, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00
.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.byte 0x00, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00
.byte 0x02, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00
.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00
.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.byte 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00
.byte 0x01, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00
.byte 0x01, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00

.global gUnknown_80F60DC
gUnknown_80F60DC: @ 80F60DC
@ replacing .incbin "baserom.gba", 0xF60DC, 0x1C
.byte 0x01, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00
.byte 0x04, 0x00, 0x00, 0x00, 0x70, 0x6b, 0x73, 0x64, 0x69, 0x72, 0x30, 0x00

.global gUnknown_80F60F8
gUnknown_80F60F8: @ 80F60F8
@ replacing .incbin "baserom.gba", 0x000f60f8, 0x8
.string "banrpal\0"

.global gUnknown_80F6100
gUnknown_80F6100: @ 80F6100
@ replacing .incbin "baserom.gba", 0x000f6100, 0x8
.string "banfont\0"

.global gUnknown_80F6108
gUnknown_80F6108: @ 80F6108
@ replacing .incbin "baserom.gba", 0x000f6108, 0x4
.byte 0x23, 0x00, 0x00, 0x00

.global gUnknown_80F610C
gUnknown_80F610C: @ 80F610C
@ replacing .incbin "baserom.gba", 0x000f610c, 0x4
.byte 0x42, 0x00, 0x00, 0x00

.global gUnknown_80F6110
gUnknown_80F6110: @ 80F6110
@ replacing .incbin "baserom.gba", 0x000f6110, 0x8
.string "%s%c%cF\0"

.global gUnknown_80F6118
gUnknown_80F6118: @ 80F6118
@ replacing .incbin "baserom.gba", 0x000f6118, 0x8
.string "%s%cF\0"
.align 2,0

.global gUnknown_80F6120
gUnknown_80F6120: @ 80F6120
@ replacing .incbin "baserom.gba", 0x000f6120, 0x88
.byte 0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x20, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0x0f, 0x00, 0x00, 0x00, 0xf0, 0x04, 0x00, 0x00, 0x00, 0x1c, 0x00, 0x00, 0x00
.byte 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0xff, 0x08, 0x00, 0x00, 0x00, 0x18, 0x00, 0x00, 0x00, 0xff, 0xff, 0x0f, 0x00, 0x00, 0x00, 0xf0, 0xff, 0x0c, 0x00, 0x00, 0x00, 0x14, 0x00, 0x00, 0x00
.byte 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0x10, 0x00, 0x00, 0x00, 0x10, 0x00, 0x00, 0x00, 0xff, 0x0f, 0x00, 0x00, 0x00, 0xf0, 0xff, 0xff, 0x14, 0x00, 0x00, 0x00, 0x0c, 0x00, 0x00, 0x00
.byte 0xff, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0x18, 0x00, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x0f, 0x00, 0x00, 0x00, 0xf0, 0xff, 0xff, 0xff, 0x1c, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00
.string "pksdir0\0"

.global gUnknown_80F61A8
gUnknown_80F61A8: @ 80F61A8
@ replacing .incbin "baserom.gba", 0x000f61a8, 0x8
.string "itempat\0"

.global gUnknown_80F61B0
gUnknown_80F61B0: @ 80F61B0
@ replacing .incbin "baserom.gba", 0x000f61b0, 0x8
.string "etcfont\0"

.global gUnknown_80F61B8
gUnknown_80F61B8: @ 80F61B8
@ replacing .incbin "baserom.gba", 0x000f61b8, 0xc
.string "etcfonta\0"
.align 2,0

.global gUnknown_80F61C4
gUnknown_80F61C4: @ 80F61C4
@ replacing .incbin "baserom.gba", 0x000f61c4, 0x8
.string "levfont\0"

.global gUnknown_80F61CC
gUnknown_80F61CC: @ 80F61CC
@ replacing .incbin "baserom.gba", 0x000f61cc, 0x8
.string "hp5font\0"

.global gUnknown_80F61D4
gUnknown_80F61D4: @ 80F61D4
@ replacing .incbin "baserom.gba", 0x000f61d4, 0x8
.string "colvec\0"
.align 2,0

.global gUnknown_80F61DC
gUnknown_80F61DC: @ 80F61DC
@ replacing .incbin "baserom.gba", 0x000f61dc, 0x10
.string "trappat\0"
.string "pksdir0\0"

.global gUnknown_80F61EC
gUnknown_80F61EC: @ 80F61EC
@ replacing .incbin "baserom.gba", 0x000f61ec, 0x30
.byte 0xfc, 0xff, 0xfc, 0xff, 0xf8, 0xff, 0xfc, 0xff, 0xf0, 0xff, 0xfc, 0xff, 0xf0, 0xff, 0xfc, 0xff, 0xf0, 0xff, 0xfc, 0xff, 0xf0, 0xff, 0xfc, 0xff, 0xfc, 0xff, 0xfc, 0xff, 0xf8, 0xff, 0xfc, 0xff
.byte 0xf0, 0xff, 0xf8, 0xff, 0xf0, 0xff, 0xf8, 0xff, 0xf0, 0xff, 0xf8, 0xff, 0xf0, 0xff, 0xf8, 0xff

.global gUnknown_80F621C
gUnknown_80F621C: @ 80F621C
@ replacing .incbin "baserom.gba", 0x000f621c, 0x8
.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00

.global gUnknown_80F6224
gUnknown_80F6224: @ 80F6224
@ replacing .incbin "baserom.gba", 0x000f6224, 0x88
.byte 0x00, 0x02, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x02, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x03, 0x02, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00
.byte 0x01, 0x00, 0x00, 0x00, 0x23, 0x02, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x23, 0x02, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x23, 0x02, 0x00, 0x00
.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0x02, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x02, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00
.byte 0x0a, 0x02, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x2a, 0x02, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x2a, 0x02, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00
.byte 0x02, 0x00, 0x00, 0x00, 0x2a, 0x02, 0x00, 0x00

.global gUnknown_80F62AC
gUnknown_80F62AC: @ 80F62AC
@ replacing .incbin "baserom.gba", 0x000f62ac, 0x4
.byte 0x00, 0x00, 0x00, 0x00

.global gUnknown_80F62B0
gUnknown_80F62B0: @ 80F62B0
@ replacing .incbin "baserom.gba", 0x000f62b0, 0x60
.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x00, 0x0f, 0x00, 0x1a, 0x00, 0x05, 0x00, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00
.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00

.global gUnknown_80F6310
gUnknown_80F6310: @ 80F6310
@ replacing .incbin "baserom.gba", 0x000f6310, 0x60
.byte 0x00, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x02, 0x00, 0x03, 0x00, 0x06, 0x00, 0x07, 0x00, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00
.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00

.global gUnknown_80F6370
gUnknown_80F6370: @ 80F6370
@ replacing .incbin "baserom.gba", 0x000f6370, 0x60
.byte 0x00, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x02, 0x00, 0x03, 0x00, 0x06, 0x00, 0x07, 0x00, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00
.byte 0x0a, 0x00, 0x04, 0x00, 0x11, 0x00, 0x02, 0x00, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x02, 0x00, 0x0d, 0x00, 0x1a, 0x00, 0x06, 0x00
.byte 0x06, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00

.global gUnknown_80F63D0
gUnknown_80F63D0: @ 80F63D0
@ replacing .incbin "baserom.gba", 0x000f63d0, 0x60
.byte 0x00, 0x00, 0x00, 0x00
.byte 0x03, 0x00, 0x00, 0x00
.byte 0x02, 0x00, 0x03, 0x00
.byte 0x1a, 0x00, 0x0e, 0x00
.byte 0x12, 0x00, 0x02, 0x00
.byte 0x00, 0x00, 0x00, 0x00
.byte 0x00, 0x00, 0x00, 0x00
.byte 0x03, 0x00, 0x00, 0x00
.byte 0x00, 0x00, 0x00, 0x00
.byte 0x00, 0x00, 0x00, 0x00
.byte 0x00, 0x00, 0x00, 0x00
.byte 0x00, 0x00, 0x00, 0x00
.byte 0x00, 0x00, 0x00, 0x00
.byte 0x03, 0x00, 0x00, 0x00
.byte 0x00, 0x00, 0x00, 0x00
.byte 0x00, 0x00, 0x00, 0x00
.byte 0x00, 0x00, 0x00, 0x00
.byte 0x00, 0x00, 0x00, 0x00
.byte 0x00, 0x00, 0x00, 0x00
.byte 0x03, 0x00, 0x00, 0x00
.byte 0x00, 0x00, 0x00, 0x00
.byte 0x00, 0x00, 0x00, 0x00
.byte 0x00, 0x00, 0x00, 0x00
.byte 0x00, 0x00, 0x00, 0x00

.global gUnknown_80F6430
gUnknown_80F6430: @ 80F6430
@ replacing .incbin "baserom.gba", 0x000f6430, 0x48
.byte 0x84, 0x03, 0x00, 0x00
.byte 0x20, 0x03, 0x00, 0x00
.byte 0xbc, 0x02, 0x00, 0x00
.byte 0x58, 0x02, 0x00, 0x00
.byte 0xf4, 0x01, 0x00, 0x00
.byte 0x90, 0x01, 0x00, 0x00
.byte 0x2c, 0x01, 0x00, 0x00
.byte 0xc8, 0x00, 0x00, 0x00
.byte 0x64, 0x00, 0x00, 0x00
.byte 0x5a, 0x00, 0x00, 0x00
.byte 0x50, 0x00, 0x00, 0x00
.byte 0x46, 0x00, 0x00, 0x00
.byte 0x3c, 0x00, 0x00, 0x00
.byte 0x32, 0x00, 0x00, 0x00
.byte 0x28, 0x00, 0x00, 0x00
.byte 0x1e, 0x00, 0x00, 0x00
.byte 0x14, 0x00, 0x00, 0x00
.byte 0x0a, 0x00, 0x00, 0x00

.global gUnknown_80F6478
gUnknown_80F6478: @ 80F6478
@ replacing .incbin "baserom.gba", 0x000f6478, 0x18
.byte 0x0d, 0x00, 0x00, 0x00
.byte 0x0e, 0x00, 0x00, 0x00
.byte 0x0f, 0x00, 0x00, 0x00
.byte 0x0f, 0x00, 0x00, 0x00
.string "pksdir0\0"

.global gUnknown_80F6490
gUnknown_80F6490: @ 80F6490
@ replacing .incbin "baserom.gba", 0x000f6490, 0x24
.byte 0x00, 0x00, 0x00, 0x0
.byte 0x0f, 0x00, 0x00, 0x00
.byte 0xff, 0x00, 0x00, 0x00
.byte 0xff, 0x0f, 0x00, 0x00
.byte 0xff, 0xff, 0x00, 0x00
.byte 0xff, 0xff, 0x0f, 0x00
.byte 0xff, 0xff, 0xff, 0x00
.byte 0xff, 0xff, 0xff, 0x0f
.byte 0xff, 0xff, 0xff, 0xff

.global gUnknown_80F64B4
gUnknown_80F64B4: @ 80F64B4
@ replacing .incbin "baserom.gba", 0x000f64b4, 0x24
.byte 0x5a, 0x00, 0x00, 0x00
.byte 0x50, 0x00, 0x00, 0x00
.byte 0x46, 0x00, 0x00, 0x00
.byte 0x3c, 0x00, 0x00, 0x00
.byte 0x32, 0x00, 0x00, 0x00
.byte 0x28, 0x00, 0x00, 0x00
.byte 0x1e, 0x00, 0x00, 0x00
.byte 0x14, 0x00, 0x00, 0x00
.byte 0x0a, 0x00, 0x00, 0x00

.global gUnknown_80F64D8
gUnknown_80F64D8: @ 80F64D8
@ replacing .incbin "baserom.gba", 0x000f64d8, 0x24
.byte 0x91, 0xf2, 0x90, 0xf2, 0x8f, 0xf2, 0x8e, 0xf2, 0x8d, 0xf2, 0x8c, 0xf2, 0x8b, 0xf2, 0x8a, 0xf2, 0x89, 0xf2, 0xc8, 0xf2, 0xc7, 0xf2, 0xc6, 0xf2, 0xc5, 0xf2, 0xc4, 0xf2, 0xc3, 0xf2, 0xc2, 0xf2
.byte 0xc1, 0xf2, 0xc0, 0xf2

.global gUnknown_80F64FC
gUnknown_80F64FC: @ 80F64FC
@ replacing .incbin "baserom.gba", 0x000f64fc, 0x24
.byte 0x84, 0x03, 0x00, 0x00, 0x20, 0x03, 0x00, 0x00, 0xbc, 0x02, 0x00, 0x00, 0x58, 0x02, 0x00, 0x00, 0xf4, 0x01, 0x00, 0x00, 0x90, 0x01, 0x00, 0x00, 0x2c, 0x01, 0x00, 0x00, 0xc8, 0x00, 0x00, 0x00
.byte 0x64, 0x00, 0x00, 0x00

.global gUnknown_80F6520
gUnknown_80F6520: @ 80F6520
@ replacing .incbin "baserom.gba", 0x000f6520, 0x24
.byte 0x5a, 0x00, 0x00, 0x00, 0x50, 0x00, 0x00, 0x00, 0x46, 0x00, 0x00, 0x00, 0x3c, 0x00, 0x00, 0x00, 0x32, 0x00, 0x00, 0x00, 0x28, 0x00, 0x00, 0x00, 0x1e, 0x00, 0x00, 0x00, 0x14, 0x00, 0x00, 0x00
.byte 0x0a, 0x00, 0x00, 0x00

.global gUnknown_80F6544
gUnknown_80F6544: @ 80F6544
@ replacing .incbin "baserom.gba", 0x000f6544, 0x24
.byte 0x91, 0xf2, 0x90, 0xf2, 0x8f, 0xf2, 0x8e, 0xf2, 0x8d, 0xf2, 0x8c, 0xf2, 0x8b, 0xf2, 0x8a, 0xf2, 0x89, 0xf2, 0xc8, 0xf2, 0xc7, 0xf2, 0xc6, 0xf2, 0xc5, 0xf2, 0xc4, 0xf2, 0xc3, 0xf2, 0xc2, 0xf2
.byte 0xc1, 0xf2, 0xc0, 0xf2

.global gUnknown_80F6568
gUnknown_80F6568: @ 80F6568
@ replacing .incbin "baserom.gba", 0x000f6568, 0x88
.byte 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0x01, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0x01, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0x01, 0x00, 0x00, 0x00, 0xfe, 0xff, 0xff, 0xff
.byte 0x01, 0x00, 0x00, 0x00, 0xfe, 0xff, 0xff, 0xff, 0x02, 0x00, 0x00, 0x00, 0xfe, 0xff, 0xff, 0xff, 0x02, 0x00, 0x00, 0x00, 0xfe, 0xff, 0xff, 0xff, 0x02, 0x00, 0x00, 0x00, 0xfd, 0xff, 0xff, 0xff
.byte 0x03, 0x00, 0x00, 0x00, 0xfd, 0xff, 0xff, 0xff, 0x03, 0x00, 0x00, 0x00, 0xfd, 0xff, 0xff, 0xff, 0x04, 0x00, 0x00, 0x00, 0xfc, 0xff, 0xff, 0xff, 0x04, 0x00, 0x00, 0x00, 0xfc, 0xff, 0xff, 0xff
.byte 0x04, 0x00, 0x00, 0x00, 0xfb, 0xff, 0xff, 0xff, 0x04, 0x00, 0x00, 0x00, 0xfb, 0xff, 0xff, 0xff, 0x04, 0x00, 0x00, 0x00, 0xfb, 0xff, 0xff, 0xff, 0x04, 0x00, 0x00, 0x00, 0xfb, 0xff, 0xff, 0xff
.byte 0x70, 0x6b, 0x73, 0x64, 0x69, 0x72, 0x30, 0x00

.global gUnknown_80F65F0
gUnknown_80F65F0: @ 80F65F0
@ replacing .incbin "baserom.gba", 0x000f65f0, 0x14
.byte 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x07, 0x04, 0x04

.global gUnknown_80F6604
gUnknown_80F6604: @ 80F6604
@ replacing .incbin "baserom.gba", 0x000f6604, 0x20
.string "zmappat\0"
.string "pksdir0\0"
.string "pksdir0\0"
.string "pksdir0\0"

.global gUnknown_80F6624
gUnknown_80F6624: @ 80F6624
@ replacing .incbin "baserom.gba", 0xF6624, 0x78
.byte 0x78, 0x01, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x79, 0x01, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00
.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7a, 0x01, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00
.byte 0x7b, 0x01, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x7c, 0x01, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00
.byte 0x7d, 0x01, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x7e, 0x01, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00
.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7f, 0x01, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00
.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.byte 0xb9, 0x01, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0xba, 0x01, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00
.byte 0xbb, 0x01, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00

.global gStatusSpriteMasks_SleepStatus
gStatusSpriteMasks_SleepStatus: @ 80F669C
.4byte 0                       @ STATUS_NONE
.4byte STATUS_SPRITE_SLEEP     @ STATUS_SLEEP
.4byte STATUS_SPRITE_SLEEPLESS @ STATUS_SLEEPLESS
.4byte STATUS_SPRITE_SLEEP     @ STATUS_NIGHTMARE
.4byte 0                       @ STATUS_YAWNING
.4byte STATUS_SPRITE_SLEEP     @ STATUS_NAPPING

.global gStatusSpriteMasks_NonVolatileStatus
gStatusSpriteMasks_NonVolatileStatus: @ 80F66B4
.4byte 0                            @ STATUS_NONE
.4byte STATUS_SPRITE_BURNED         @ STATUS_BURN
.4byte STATUS_SPRITE_POISONED       @ STATUS_POISONED
.4byte STATUS_SPRITE_BADLY_POISONED @ STATUS_BADLY_POISONED
.4byte 0                            @ STATUS_PARALYSIS

.global gStatusSpriteMasks_ImmobilizeStatus
gStatusSpriteMasks_ImmobilizeStatus: @ 80F66C8
.4byte 0                    @ STATUS_NONE
.4byte STATUS_SPRITE_FROZEN @ STATUS_FROZEN
.4byte 0                    @ STATUS_SHADOW_HOLD
.4byte 0                    @ STATUS_WRAP
.4byte 0                    @ STATUS_WRAPPED
.4byte 0                    @ STATUS_INGRAIN
.4byte 0                    @ STATUS_PETRIFIED
.4byte 0                    @ STATUS_CONSTRICTION

.global gStatusSpriteMasks_VolatileStatus
gStatusSpriteMasks_VolatileStatus: @ 80F66E8
.4byte 0                      @ STATUS_NONE
.4byte 0                      @ STATUS_CRINGE
.4byte STATUS_SPRITE_CONFUSED @ STATUS_CONFUSED
.4byte 0                      @ STATUS_PAUSED
.4byte STATUS_SPRITE_COWERING @ STATUS_COWERING
.4byte STATUS_SPRITE_TAUNTED  @ STATUS_TAUNTED
.4byte STATUS_SPRITE_ENCORE   @ STATUS_ENCORE
.4byte 0                      @ STATUS_INFATUATED

.global gStatusSpriteMasks_ChargingStatus
gStatusSpriteMasks_ChargingStatus: @ 80F6708
.4byte 0 @ STATUS_NONE
.4byte 0 @ STATUS_BIDE
.4byte 0 @ STATUS_SOLARBEAM
.4byte 0 @ STATUS_SKY_ATTACK
.4byte 0 @ STATUS_RAZOR_WIND
.4byte 0 @ STATUS_FOCUS_PUNCH
.4byte 0 @ STATUS_SKULL_BASH
.4byte 0 @ STATUS_FLYING
.4byte 0 @ STATUS_BOUNCING
.4byte 0 @ STATUS_DIVING
.4byte 0 @ STATUS_DIGGING
.4byte 0 @ STATUS_CHARGING
.4byte 0 @ STATUS_ENRAGED

.global gStatusSpriteMasks_ProtectionStatus
gStatusSpriteMasks_ProtectionStatus: @ 80F673C
.4byte 0                           @ STATUS_NONE
.4byte STATUS_SPRITE_SHIELD_BLUE   @ STATUS_REFLECT
.4byte STATUS_SPRITE_SHIELD_RED    @ STATUS_SAFEGUARD
.4byte STATUS_SPRITE_SHIELD_YELLOW @ STATUS_LIGHT_SCREEN
.4byte STATUS_SPRITE_SHIELD_BLUE   @ STATUS_COUNTER
.4byte STATUS_SPRITE_SHIELD_YELLOW @ STATUS_MAGIC_COAT
.4byte 0                           @ STATUS_WISH
.4byte STATUS_SPRITE_SHIELD_GREEN  @ STATUS_PROTECT
.4byte STATUS_SPRITE_SHIELD_RED    @ STATUS_MIRROR_COAT
.4byte STATUS_SPRITE_ENDURE        @ STATUS_ENDURING
.4byte STATUS_SPRITE_SHIELD_BLUE   @ STATUS_MINI_COUNTER
.4byte STATUS_SPRITE_SHIELD_GREEN  @ STATUS_MIRROR_MOVE
.4byte 0                           @ STATUS_CONVERSION2
.4byte STATUS_SPRITE_SHIELD_GREEN  @ STATUS_VITAL_THROW
.4byte STATUS_SPRITE_SHIELD_BLUE   @ STATUS_MIST

.global gStatusSpriteMasks_WaitingStatus
gStatusSpriteMasks_WaitingStatus: @ 80F6778
.4byte 0                    @ STATUS_NONE
.4byte STATUS_SPRITE_CURSED @ STATUS_CURSED
.4byte 0                    @ STATUS_DECOY
.4byte STATUS_SPRITE_SNATCH @ STATUS_SNATCH

.global gStatusSpriteMasks_LinkedStatus
gStatusSpriteMasks_LinkedStatus: @ 80F6788
.4byte 0 @ STATUS_NONE
.4byte 0 @ STATUS_LEECH_SEED
.4byte 0 @ STATUS_DESTINY_BOND

.global gStatusSpriteMasks_MoveStatus
gStatusSpriteMasks_MoveStatus: @ 80F6794
.4byte 0                          @ STATUS_NONE
.4byte STATUS_SPRITE_SURE_SHOT    @ STATUS_SURE_SHOT
.4byte STATUS_SPRITE_WHIFFER      @ STATUS_WHIFFER
.4byte STATUS_SPRITE_SET_DAMAGE   @ STATUS_SET_DAMAGE
.4byte STATUS_SPRITE_FOCUS_ENERGY @ STATUS_FOCUS_ENERGY

.global gStatusSpriteMasks_ItemStatus
gStatusSpriteMasks_ItemStatus: @ 80F67A8
.4byte 0 @ STATUS_NONE
.4byte 0 @ STATUS_LONG_TOSS
.4byte 0 @ STATUS_PIERCE

.global gStatusSpriteMasks_TransformStatus
gStatusSpriteMasks_TransformStatus: @ 80F67B4
.4byte 0 @ STATUS_NONE
.4byte 0 @ STATUS_INVISIBLE
.4byte 0 @ STATUS_TRANSFORMED
.4byte 0 @ STATUS_MOBILE

.global gStatusSpriteMasks_EyesightStatus
gStatusSpriteMasks_EyesightStatus: @ 80F67C4
.4byte 0                        @ STATUS_NONE
.4byte STATUS_SPRITE_BLINKER    @ STATUS_BLINKER
.4byte STATUS_SPRITE_CROSS_EYED @ STATUS_CROSS_EYED
.4byte STATUS_SPRITE_EYEDROPS   @ STATUS_EYEDROPS

.global gStatusSpriteMasks_MuzzledStatus
gStatusSpriteMasks_MuzzledStatus: @ 80F67D4
.4byte 0                     @ STATUS_NONE
.4byte STATUS_SPRITE_MUZZLED @ STATUS_MUZZLED

.global gUnknown_80F67DC
gUnknown_80F67DC: @ 80F67DC
@ u16[4]. They are sound effect IDs
.byte 0xD8, 0x00, 0xD9, 0x00
.byte 0xD9, 0x00, 0x73, 0x01

.global gUnknown_80F67E4
gUnknown_80F67E4: @ 80F67E4
@ u16[4]. They are sound effect IDs
.byte 0xDA, 0x00, 0xDB, 0x00
.byte 0xDB, 0x00, 0x74, 0x01

.global gUnknown_80F67EC
gUnknown_80F67EC: @ 80F67EC
@ s32[8]
.byte 0xff, 0xff, 0xff, 0xff, 0x4b, 0x01, 0x00, 0x00, 0xef, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff
.byte 0x10, 0x00, 0x00, 0x00, 0x14, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0xdf, 0x00, 0x00, 0x00

.global gUnknown_80F680C
gUnknown_80F680C: @ 80F680C
@ u32[8]
.byte 0xff, 0xff, 0xff, 0xff, 0x4b, 0x01, 0x00, 0x00, 0xef, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff
.byte 0xb8, 0x01, 0x00, 0x00, 0x14, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0xdf, 0x00, 0x00, 0x00

.global gUnknown_80F682C
gUnknown_80F682C: @ 80F682C
@ u16[8]
.byte 0xe5, 0x03, 0xe5, 0x03, 0xe5, 0x03, 0xa9, 0x01, 0xe5, 0x03, 0xe5, 0x03, 0xaa, 0x01, 0xe5, 0x03

.global gUnknown_80F683C
gUnknown_80F683C: @ 80F683C
@ replacing .incbin "baserom.gba", 0xF683C, 0x14
.byte 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x70, 0x6b, 0x73, 0x64
.byte 0x69, 0x72, 0x30, 0x00

.global gUnknown_80F6850
gUnknown_80F6850: @ 80F6850
@ replacing .incbin "baserom.gba", 0xF6850, 0x10
.byte 0x9e, 0x01, 0xa1, 0x01, 0xa2, 0x01, 0xa3, 0x01, 0x70, 0x6b, 0x73, 0x64, 0x69, 0x72, 0x30, 0x00

.global gSpeedTurns
gSpeedTurns: @ 80F6860
@ replacing .incbin "baserom.gba", 0xF6860, 0x104
.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00
.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x00
.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x00
.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.byte 0x05, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x06, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.byte 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.byte 0x09, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0a, 0x00, 0x00, 0x00, 0x0b, 0x00, 0x00, 0x00, 0x0c, 0x00
.byte 0x00, 0x00, 0x0d, 0x00, 0x00, 0x00, 0x0e, 0x00, 0x00, 0x00, 0x0f, 0x00, 0x00, 0x00, 0x10, 0x00
.byte 0x00, 0x00, 0x11, 0x00, 0x00, 0x00, 0x12, 0x00, 0x00, 0x00, 0x13, 0x00, 0x00, 0x00, 0x14, 0x00
.byte 0x00, 0x00, 0x15, 0x00, 0x00, 0x00, 0x00, 0x00, 0x16, 0x00, 0x17, 0x00, 0x18, 0x00, 0x00, 0x00
.byte 0x19, 0x00, 0x1a, 0x00, 0x1b, 0x00, 0x00, 0x00, 0x1c, 0x00, 0x1d, 0x00, 0x1e, 0x00, 0x00, 0x00
.byte 0x1f, 0x00, 0x20, 0x00, 0x21, 0x00, 0x00, 0x00, 0x22, 0x00, 0x23, 0x00, 0x24, 0x00, 0x00, 0x00
.byte 0x25, 0x00, 0x26, 0x00, 0x27, 0x00, 0x00, 0x00, 0x28, 0x00, 0x29, 0x00, 0x2a, 0x00, 0x2b, 0x00
.byte 0x2c, 0x00, 0x2d, 0x00, 0x2e, 0x00, 0x2f, 0x00, 0x30, 0x00, 0x31, 0x00, 0x32, 0x00, 0x33, 0x00
.byte 0x34, 0x00, 0x35, 0x00, 0x36, 0x00, 0x37, 0x00, 0x38, 0x00, 0x39, 0x00, 0x3a, 0x00, 0x3b, 0x00
.byte 0x3c, 0x00, 0x3d, 0x00, 0x3e, 0x00, 0x3f, 0x00, 0x40, 0x00, 0x00, 0x00, 0x70, 0x6b, 0x73, 0x64
.byte 0x69, 0x72, 0x30, 0x00

.global gUnknown_80F6964
gUnknown_80F6964: @ 80F6964
@ replacing .incbin "baserom.gba", 0xF6964, 0x18
.byte 0x00, 0x00, 0x00, 0x00, 0x0d, 0x00, 0x0e, 0x00, 0x00, 0x00, 0x10, 0x00, 0x00, 0x00, 0x12, 0x00
.byte 0x12, 0x00, 0x31, 0x00, 0x2c, 0x00, 0x12, 0x00

.global gUnknown_80F697C
gUnknown_80F697C: @ 80F697C
.byte 0x58, 0x00, 0x00, 0x00
.string "pksdir0"
.align 2,0
.string "pksdir0"
.align 2,0

.global gUnknown_80F6990
gUnknown_80F6990: @ 80F6990
.byte 0x01, 0x00, 0x00, 0x00
.byte 0x01, 0x00, 0x00, 0x00
.byte 0x01, 0x00, 0x00, 0x00

.global gUnknown_80F699C
gUnknown_80F699C: @ 80F699C
.byte 0x00, 0x00, 0x00, 0x00
.byte 0x00, 0x00, 0x00, 0x00
.byte 0x01, 0x00, 0x00, 0x00

.global gUnknown_80F69A8
gUnknown_80F69A8: @ 80F69A8
@ replacing .incbin "baserom.gba", 0xF69A8, 0x2C
.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x70, 0x6b, 0x73, 0x64
.byte 0x69, 0x72, 0x30, 0x00, 0x70, 0x6b, 0x73, 0x64, 0x69, 0x72, 0x30, 0x00, 0x70, 0x6b, 0x73, 0x64
.byte 0x69, 0x72, 0x30, 0x00, 0x70, 0x6b, 0x73, 0x64, 0x69, 0x72, 0x30, 0x00

.global gUnknown_80F69D4
gUnknown_80F69D4: @ 80F69D4
@ replacing .incbin "baserom.gba", 0xF69D4, 0x18
.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00

.global gUnknown_80F69EC
gUnknown_80F69EC: @ 80F69EC
@ replacing .incbin "baserom.gba", 0xF69EC, 0x18
.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00

.global gUnknown_80F6A04
gUnknown_80F6A04: @ 80F6A04
.string "b%02dfon\0"
.align 2,0

.global gUnknown_80F6A10
gUnknown_80F6A10: @ 80F6A10
.string "b%02dpal\0"
.align 2,0

.global gUnknown_80F6A1C
gUnknown_80F6A1C: @ 80F6A1C
.string "b%02dcel\0"
.align 2,0

.global gUnknown_80F6A28
gUnknown_80F6A28: @ 80F6A28
.string "b%02dcex\0"
.align 2,0

.global gUnknown_80F6A34
gUnknown_80F6A34: @ 80F6A34
.string "b%02demap0\0"
.align 2,0

.global gUnknown_80F6A40
gUnknown_80F6A40: @ 80F6A40
.string "b%02dcanm\0"

.global gUnknown_80F6A4A
gUnknown_80F6A4A: @ 80F6A4A
@ replacing .incbin "baserom.gba", 0xF6A4A, 0x1BC
.byte 0x00, 0x00, 0x01, 0x00, 0x02, 0x00, 0x00, 0x00, 0x01, 0x00, 0x02, 0x00, 0x00, 0x00, 0x01, 0x00
.byte 0x02, 0x00, 0x00, 0x00, 0x01, 0x00, 0x02, 0x00, 0x00, 0x00, 0x01, 0x00, 0x02, 0x00, 0x00, 0x00
.byte 0x01, 0x00, 0x02, 0x00, 0x00, 0x00, 0x01, 0x00, 0x02, 0x00, 0x00, 0x00, 0x01, 0x00, 0x02, 0x00
.byte 0x00, 0x00, 0x01, 0x00, 0x02, 0x00, 0x00, 0x00, 0x01, 0x00, 0x02, 0x00, 0x00, 0x00, 0x01, 0x00
.byte 0x02, 0x00, 0x00, 0x00, 0x01, 0x00, 0x02, 0x00, 0x00, 0x00, 0x01, 0x00, 0x02, 0x00, 0x00, 0x00
.byte 0x01, 0x00, 0x02, 0x00, 0x00, 0x00, 0x01, 0x00, 0x02, 0x00, 0x00, 0x00, 0x01, 0x00, 0x02, 0x00
.byte 0x00, 0x00, 0x01, 0x00, 0x02, 0x00, 0x00, 0x00, 0x01, 0x00, 0x02, 0x00, 0x00, 0x00, 0x01, 0x00
.byte 0x02, 0x00, 0x00, 0x00, 0x01, 0x00, 0x02, 0x00, 0x00, 0x00, 0x01, 0x00, 0x02, 0x00, 0x00, 0x00
.byte 0x01, 0x00, 0x02, 0x00, 0x00, 0x00, 0x01, 0x00, 0x02, 0x00, 0x00, 0x00, 0x01, 0x00, 0x02, 0x00
.byte 0x00, 0x00, 0x01, 0x00, 0x02, 0x00, 0x00, 0x00, 0x01, 0x00, 0x02, 0x00, 0x00, 0x00, 0x01, 0x00
.byte 0x02, 0x00, 0x00, 0x00, 0x01, 0x00, 0x02, 0x00, 0x00, 0x00, 0x01, 0x00, 0x02, 0x00, 0x00, 0x00
.byte 0x01, 0x00, 0x02, 0x00, 0x00, 0x00, 0x01, 0x00, 0x02, 0x00, 0x00, 0x00, 0x01, 0x00, 0x02, 0x00
.byte 0x00, 0x00, 0x01, 0x00, 0x02, 0x00, 0x00, 0x00, 0x01, 0x00, 0x02, 0x00, 0x00, 0x00, 0x01, 0x00
.byte 0x02, 0x00, 0x00, 0x00, 0x01, 0x00, 0x02, 0x00, 0x00, 0x00, 0x01, 0x00, 0x02, 0x00, 0x00, 0x00
.byte 0x01, 0x00, 0x02, 0x00, 0x00, 0x00, 0x01, 0x00, 0x02, 0x00, 0x00, 0x00, 0x01, 0x00, 0x02, 0x00
.byte 0x00, 0x00, 0x01, 0x00, 0x02, 0x00, 0x00, 0x00, 0x01, 0x00, 0x02, 0x00, 0x00, 0x00, 0x01, 0x00
.byte 0x02, 0x00, 0x00, 0x00, 0x01, 0x00, 0x02, 0x00, 0x00, 0x00, 0x01, 0x00, 0x02, 0x00, 0x00, 0x00
.byte 0x01, 0x00, 0x02, 0x00, 0x00, 0x00, 0x01, 0x00, 0x02, 0x00, 0x00, 0x00, 0x01, 0x00, 0x02, 0x00
.byte 0x00, 0x00, 0x01, 0x00, 0x02, 0x00, 0x00, 0x00, 0x01, 0x00, 0x02, 0x00, 0x00, 0x00, 0x01, 0x00
.byte 0x02, 0x00, 0x00, 0x00, 0x01, 0x00, 0x02, 0x00, 0x00, 0x00, 0x01, 0x00, 0x02, 0x00, 0x00, 0x00
.byte 0x01, 0x00, 0x02, 0x00, 0x00, 0x00, 0x01, 0x00, 0x02, 0x00, 0x00, 0x00, 0x01, 0x00, 0x02, 0x00
.byte 0x00, 0x00, 0x01, 0x00, 0x02, 0x00, 0x00, 0x00, 0x01, 0x00, 0x02, 0x00, 0x00, 0x00, 0x01, 0x00
.byte 0x02, 0x00, 0x00, 0x00, 0x01, 0x00, 0x02, 0x00, 0x00, 0x00, 0x01, 0x00, 0x02, 0x00, 0x00, 0x00
.byte 0x01, 0x00, 0x02, 0x00, 0x00, 0x00, 0x01, 0x00, 0x02, 0x00, 0x00, 0x00, 0x01, 0x00, 0x02, 0x00
.byte 0x00, 0x00, 0x01, 0x00, 0x02, 0x00, 0x00, 0x00, 0x01, 0x00, 0x02, 0x00, 0x00, 0x00, 0x01, 0x00
.byte 0x02, 0x00, 0x00, 0x00, 0x01, 0x00, 0x02, 0x00, 0x00, 0x00, 0x01, 0x00, 0x02, 0x00, 0x00, 0x00
.byte 0x01, 0x00, 0x02, 0x00, 0x00, 0x00, 0x01, 0x00, 0x02, 0x00, 0x00, 0x00, 0x01, 0x00, 0x02, 0x00
.byte 0x00, 0x00, 0x01, 0x00, 0x02, 0x00, 0x00, 0x00, 0x01, 0x00, 0x02, 0x00

.global gUnknown_80F6C06
gUnknown_80F6C06: @ 80F6C06
@ replacing .incbin "baserom.gba", 0xF6C06, 0x11A
.byte 0xf7, 0xff, 0xf7, 0xff, 0xf7, 0xff, 0xf6, 0xff, 0xf6, 0xff, 0xf6, 0xff, 0xf8, 0xff, 0xf8, 0xff
.byte 0xf8, 0xff, 0xf9, 0xff, 0xf9, 0xff, 0xf9, 0xff, 0xfa, 0xff, 0xfa, 0xff, 0xfa, 0xff, 0xfb, 0xff
.byte 0xfb, 0xff, 0xfb, 0xff, 0xfc, 0xff, 0xfc, 0xff, 0xfc, 0xff, 0xfd, 0xff, 0xfd, 0xff, 0xfd, 0xff
.byte 0xfe, 0xff, 0xfe, 0xff, 0xfe, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00
.byte 0x00, 0x00, 0x01, 0x00, 0x01, 0x00, 0x01, 0x00, 0x02, 0x00, 0x02, 0x00, 0x02, 0x00, 0x03, 0x00
.byte 0x03, 0x00, 0x03, 0x00, 0x04, 0x00, 0x04, 0x00, 0x04, 0x00, 0x05, 0x00, 0x05, 0x00, 0x05, 0x00
.byte 0x06, 0x00, 0x06, 0x00, 0x06, 0x00, 0x07, 0x00, 0x07, 0x00, 0x07, 0x00, 0x08, 0x00, 0x08, 0x00
.byte 0x08, 0x00, 0x09, 0x00, 0x09, 0x00, 0x09, 0x00, 0x0a, 0x00, 0x0a, 0x00, 0x0a, 0x00, 0x0b, 0x00
.byte 0x0b, 0x00, 0x0b, 0x00, 0x0c, 0x00, 0x0c, 0x00, 0x0c, 0x00, 0x0d, 0x00, 0x0d, 0x00, 0x0d, 0x00
.byte 0x0e, 0x00, 0x0e, 0x00, 0x0e, 0x00, 0x0f, 0x00, 0x0f, 0x00, 0x0f, 0x00, 0x10, 0x00, 0x10, 0x00
.byte 0x10, 0x00, 0x11, 0x00, 0x11, 0x00, 0x11, 0x00, 0x12, 0x00, 0x12, 0x00, 0x12, 0x00, 0x13, 0x00
.byte 0x13, 0x00, 0x13, 0x00, 0x14, 0x00, 0x14, 0x00, 0x14, 0x00, 0x15, 0x00, 0x15, 0x00, 0x15, 0x00
.byte 0x16, 0x00, 0x16, 0x00, 0x16, 0x00, 0x17, 0x00, 0x17, 0x00, 0x17, 0x00, 0x18, 0x00, 0x18, 0x00
.byte 0x18, 0x00, 0x19, 0x00, 0x19, 0x00, 0x19, 0x00, 0x1a, 0x00, 0x1a, 0x00, 0x1a, 0x00, 0x1b, 0x00
.byte 0x1b, 0x00, 0x1b, 0x00, 0x1c, 0x00, 0x1c, 0x00, 0x1c, 0x00, 0x1d, 0x00, 0x1d, 0x00, 0x1d, 0x00
.byte 0x1e, 0x00, 0x1e, 0x00, 0x1e, 0x00, 0x1f, 0x00, 0x1f, 0x00, 0x1f, 0x00, 0x20, 0x00, 0x20, 0x00
.byte 0x20, 0x00, 0x21, 0x00, 0x21, 0x00, 0x21, 0x00, 0x22, 0x00, 0x22, 0x00, 0x22, 0x00, 0x23, 0x00
.byte 0x23, 0x00, 0x23, 0x00, 0x24, 0x00, 0x24, 0x00, 0x24, 0x00

.global gUnknown_80F6D20
gUnknown_80F6D20: @ 80F6D20
@ replacing .incbin "baserom.gba", 0xF6D20, 0xAC
.byte 0x25, 0x00, 0x25, 0x00, 0x25, 0x00, 0x26, 0x00, 0x26, 0x00, 0x26, 0x00, 0x27, 0x00, 0x27, 0x00
.byte 0x27, 0x00, 0x28, 0x00, 0x28, 0x00, 0x28, 0x00, 0x29, 0x00, 0x29, 0x00, 0x29, 0x00, 0x2a, 0x00
.byte 0x2a, 0x00, 0x2a, 0x00, 0x2b, 0x00, 0x2b, 0x00, 0x2b, 0x00, 0x2c, 0x00, 0x2c, 0x00, 0x2c, 0x00
.byte 0x2d, 0x00, 0x2d, 0x00, 0x2d, 0x00, 0x2e, 0x00, 0x2e, 0x00, 0x2e, 0x00, 0x2f, 0x00, 0x2f, 0x00
.byte 0x2f, 0x00, 0x30, 0x00, 0x30, 0x00, 0x30, 0x00, 0x31, 0x00, 0x31, 0x00, 0x31, 0x00, 0x32, 0x00
.byte 0x32, 0x00, 0x32, 0x00, 0x33, 0x00, 0x33, 0x00, 0x33, 0x00, 0x34, 0x00, 0x34, 0x00, 0x34, 0x00
.byte 0x35, 0x00, 0x35, 0x00, 0x35, 0x00, 0x36, 0x00, 0x36, 0x00, 0x36, 0x00, 0x37, 0x00, 0x37, 0x00
.byte 0x37, 0x00, 0x38, 0x00, 0x38, 0x00, 0x38, 0x00, 0x39, 0x00, 0x39, 0x00, 0x39, 0x00, 0x3a, 0x00
.byte 0x3a, 0x00, 0x3a, 0x00, 0x3b, 0x00, 0x3b, 0x00, 0x3b, 0x00, 0x3c, 0x00, 0x3c, 0x00, 0x3c, 0x00
.byte 0x3d, 0x00, 0x3d, 0x00, 0x3d, 0x00, 0x3e, 0x00, 0x3e, 0x00, 0x3e, 0x00, 0x3f, 0x00, 0x3f, 0x00
.byte 0x3f, 0x00, 0x00, 0x00, 0x70, 0x6b, 0x73, 0x64, 0x69, 0x72, 0x30, 0x00

.global gUnknown_80F6DCC
gUnknown_80F6DCC: @ 80F6DCC
.string "fixedmap\0"

.global gUnknown_80F6DD5
gUnknown_80F6DD5: @ 80F6DD5
@ replacing .incbin "baserom.gba", 0xF6DD5, 0x23
.byte 0x01, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00
.byte 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x01, 0x00, 0x00, 0x00, 0x01, 0x00, 0x01, 0x00, 0x00, 0x00
.byte 0x00, 0x00, 0x00

.global gUnknown_80F6DF8
gUnknown_80F6DF8: @ 80F6DF8
@ replacing .incbin "baserom.gba", 0xF6DF8, 0xCF0
.byte 0x01, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00
.byte 0x02, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00
.byte 0x70, 0x6b, 0x73, 0x64, 0x69, 0x72, 0x30, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.byte 0xfc, 0x00, 0x03, 0x14, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.byte 0x32, 0x00, 0x04, 0x14, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.byte 0x5e, 0x00, 0x05, 0x14, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.byte 0x17, 0x00, 0x06, 0x14, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.byte 0x4d, 0x01, 0x07, 0x14, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.byte 0x91, 0x00, 0x08, 0x14, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00
.byte 0x00, 0x00, 0x00, 0x14, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00
.byte 0x00, 0x00, 0x00, 0x14, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00
.byte 0x00, 0x00, 0x00, 0x14, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00
.byte 0x00, 0x00, 0x00, 0x14, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x05, 0x00, 0x00, 0x00
.byte 0x00, 0x00, 0x00, 0x14, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x06, 0x00, 0x00, 0x00
.byte 0x00, 0x00, 0x00, 0x14, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0x00, 0x00, 0x00
.byte 0x00, 0x00, 0x00, 0x14, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00
.byte 0x00, 0x00, 0x00, 0x14, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.byte 0x92, 0x00, 0x09, 0x14, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.byte 0x41, 0x00, 0x0a, 0x14, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.byte 0x11, 0x01, 0x0b, 0x14, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.byte 0x06, 0x00, 0x0c, 0x14, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.byte 0x90, 0x00, 0x0d, 0x14, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.byte 0x9b, 0x01, 0x0e, 0x14, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.byte 0x9c, 0x01, 0x0f, 0x14, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.byte 0x38, 0x00, 0x10, 0x14, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.byte 0x96, 0x00, 0x11, 0x14, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.byte 0x0d, 0x01, 0x12, 0x14, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.byte 0x0c, 0x01, 0x13, 0x14, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.byte 0x0e, 0x01, 0x14, 0x14, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.byte 0x13, 0x01, 0x15, 0x14, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.byte 0x99, 0x01, 0x16, 0x14, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.byte 0x95, 0x01, 0x17, 0x14, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.byte 0x96, 0x01, 0x18, 0x14, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.byte 0x97, 0x01, 0x19, 0x14, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.byte 0x9d, 0x01, 0x1a, 0x14, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.byte 0x12, 0x01, 0x1b, 0x14, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.byte 0x9a, 0x01, 0x1c, 0x14, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.byte 0x9e, 0x01, 0x1d, 0x14, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.byte 0xa1, 0x01, 0x00, 0x14, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.byte 0xa2, 0x01, 0x00, 0x14, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.byte 0xa3, 0x01, 0x00, 0x14, 0x00, 0x00, 0x00, 0x00, 0x37, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.byte 0x00, 0x00, 0x00, 0x14, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.byte 0x00, 0x00, 0x00, 0x14, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.byte 0x18, 0x01, 0x00, 0x14, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.byte 0x02, 0x00, 0x00, 0x14, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.byte 0x1b, 0x01, 0x00, 0x14, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.byte 0x04, 0x01, 0x1f, 0x14, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.byte 0x00, 0x00, 0x00, 0x14, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.byte 0x00, 0x00, 0x00, 0x14, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.byte 0x00, 0x00, 0x00, 0x14, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.byte 0x00, 0x00, 0x00, 0x14, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.byte 0x00, 0x00, 0x00, 0x14, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.byte 0x00, 0x00, 0x00, 0x14, 0x05, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.byte 0x00, 0x00, 0x00, 0x14, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.byte 0x00, 0x00, 0x00, 0x14, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.byte 0x00, 0x00, 0x00, 0x14, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.byte 0x00, 0x00, 0x00, 0x14, 0x00, 0x00, 0x00, 0x00, 0xe1, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.byte 0x00, 0x00, 0x00, 0x14, 0x00, 0x00, 0x00, 0x00, 0xe2, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.byte 0x00, 0x00, 0x00, 0x14, 0x00, 0x00, 0x00, 0x00, 0xe7, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.byte 0x00, 0x00, 0x00, 0x14, 0x00, 0x00, 0x00, 0x00, 0xe6, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.byte 0x00, 0x00, 0x00, 0x14, 0x00, 0x00, 0x00, 0x00, 0x2f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.byte 0x00, 0x00, 0x00, 0x14, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.byte 0x14, 0x01, 0x1e, 0x14, 0x00, 0x00, 0x00, 0x00, 0x2e, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.byte 0x00, 0x00, 0x00, 0x14, 0x00, 0x00, 0x00, 0x00, 0xaf, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.byte 0x00, 0x00, 0x00, 0x14, 0x00, 0x00, 0x00, 0x00, 0xd1, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.byte 0x00, 0x00, 0x00, 0x14, 0x00, 0x00, 0x00, 0x00, 0x30, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.byte 0x00, 0x00, 0x00, 0x14, 0x00, 0x00, 0x00, 0x00, 0x31, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.byte 0x00, 0x00, 0x00, 0x14, 0x00, 0x00, 0x00, 0x00, 0x31, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.byte 0x00, 0x00, 0x00, 0x14, 0x00, 0x00, 0x00, 0x00, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.byte 0x00, 0x00, 0x00, 0x14, 0x00, 0x00, 0x00, 0x00, 0xe3, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.byte 0x00, 0x00, 0x00, 0x14, 0x00, 0x00, 0x00, 0x00, 0xe4, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.byte 0x00, 0x00, 0x00, 0x14, 0x00, 0x00, 0x00, 0x00, 0xe5, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.byte 0x00, 0x00, 0x00, 0x14, 0x00, 0x00, 0x00, 0x00, 0x6d, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.byte 0x00, 0x00, 0x00, 0x14, 0x00, 0x00, 0x00, 0x00, 0x36, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.byte 0x00, 0x00, 0x00, 0x14, 0x00, 0x00, 0x00, 0x00, 0x6e, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.byte 0x00, 0x00, 0x00, 0x14, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.byte 0x20, 0x01, 0x24, 0x14, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.byte 0xa2, 0x00, 0x24, 0x14, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.byte 0x53, 0x00, 0x24, 0x14, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.byte 0x14, 0x00, 0x24, 0x14, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.byte 0x4d, 0x00, 0x24, 0x14, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.byte 0xf3, 0x00, 0x24, 0x14, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.byte 0x09, 0x01, 0x24, 0x14, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.byte 0x3c, 0x00, 0x24, 0x14, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.byte 0x66, 0x00, 0x24, 0x14, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.byte 0xbf, 0x00, 0x24, 0x14, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.byte 0x36, 0x01, 0x24, 0x14, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.byte 0x64, 0x01, 0x24, 0x14, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.byte 0x4e, 0x01, 0x24, 0x14, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.byte 0x64, 0x00, 0x24, 0x14, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.byte 0xf5, 0x00, 0x24, 0x14, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.byte 0xf6, 0x00, 0x24, 0x14, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.byte 0x85, 0x01, 0x24, 0x14, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.byte 0x4c, 0x01, 0x24, 0x14, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.byte 0x05, 0x01, 0x24, 0x14, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.byte 0x6a, 0x00, 0x24, 0x14, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.byte 0x00, 0x01, 0x24, 0x14, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.byte 0x32, 0x00, 0x24, 0x14, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.byte 0x54, 0x00, 0x24, 0x14, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.byte 0x53, 0x00, 0x24, 0x14, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.byte 0x10, 0x00, 0x24, 0x14, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.byte 0xe3, 0x00, 0x24, 0x14, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.byte 0x1d, 0x00, 0x24, 0x14, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.byte 0x20, 0x00, 0x24, 0x14, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.byte 0x7f, 0x00, 0x24, 0x14, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.byte 0x0f, 0x00, 0x24, 0x14, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.byte 0x0d, 0x00, 0x24, 0x14, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.byte 0x10, 0x01, 0x24, 0x14, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.byte 0xb9, 0x00, 0x24, 0x14, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.byte 0x4a, 0x00, 0x24, 0x14, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.byte 0x5c, 0x00, 0x24, 0x14, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.byte 0x8f, 0x01, 0x24, 0x14, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.byte 0x90, 0x01, 0x24, 0x14, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.byte 0x1e, 0x01, 0x24, 0x14, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.byte 0xc6, 0x00, 0x24, 0x14, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.byte 0x49, 0x01, 0x24, 0x14, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.byte 0x92, 0x01, 0x24, 0x14, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.byte 0xf9, 0x00, 0x24, 0x14, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.byte 0x49, 0x00, 0x24, 0x14, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.byte 0x73, 0x01, 0x24, 0x14, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.byte 0x09, 0x00, 0x24, 0x14, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.byte 0xa0, 0x00, 0x24, 0x14, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.byte 0x1d, 0x01, 0x24, 0x14, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.byte 0x4c, 0x00, 0x24, 0x14, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.byte 0x4b, 0x00, 0x24, 0x14, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.byte 0x1b, 0x01, 0x24, 0x14, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.byte 0x2c, 0x01, 0x24, 0x14, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.byte 0x2b, 0x01, 0x24, 0x14, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.byte 0x3c, 0x00, 0x24, 0x14, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.byte 0x3c, 0x00, 0x24, 0x14, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.byte 0x3c, 0x00, 0x24, 0x14, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.byte 0x3c, 0x00, 0x24, 0x14, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x70, 0x6b, 0x73, 0x64, 0x69, 0x72, 0x30, 0x00

.global gUnknown_80F7AE8
gUnknown_80F7AE8: @ 80F7AE8
.byte 0x00, 0x00

.global gUnknown_80F7AEA
gUnknown_80F7AEA: @ 80F7AEA
.byte 0x0d, 0x03, 0x0d, 0x01, 0x0d, 0x03, 0x0d, 0x01, 0x01, 0x03, 0x01, 0x00, 0x11, 0x00

.global gUnknown_80F7AF8
gUnknown_80F7AF8: @ 80F7AF8
.byte 0x3f, 0x3f, 0x00, 0x00

.global gUnknown_80F7AFC
gUnknown_80F7AFC: @ 80F7AFC
.string "{COLOR_1 YELLOW}%s{END_COLOR_TEXT_1}\0"
.align 2,0

.global gUnknown_80F7B04
gUnknown_80F7B04: @ 80F7B04
.string "{COLOR_1 YELLOW}"
.byte 0x87, 0x45
.string "{END_COLOR_TEXT_1}\0"
.align 2,0
.string "pksdir0\0"
.align 2,0

.global gActions
gActions: @ 80F7B14
.4byte gUseDescription
.4byte gUseText
.4byte gThrowDescription
.4byte gThrowText
.4byte gThrowDescription
.4byte gThrowText
.4byte gEquipDescription
.4byte gEquipText
.4byte gEatDescription
.4byte gEatText
.4byte gIngestDescription
.4byte gIngestText
.4byte gPeelDescription
.4byte gPeelText
.4byte gUseDescription
.4byte gUseText
.4byte gUseDescription
.4byte gUseText
.4byte gUseDescription
.4byte gUseText
.4byte gUseDescription
.4byte gUseText
.4byte gEquipPutOnDescription
.4byte gEquipText
.4byte gEquipPutOnDescription
.4byte gEquipText
.4byte gUseDescription
.4byte gUseText
.4byte gUseDescription
.4byte gUseText
.4byte gUseDescription
.4byte gUseText

.global gEquipPutOnDescription
gEquipPutOnDescription: @ 80F7B94
.string "{ARG_POKEMON_0} put on\n"
.string "the {ARG_MOVE_ITEM_0}.\0"

.global gPeelText
gPeelText: @ 80F7BA8
.string "Peel\0"
.align 2,0

.global gPeelDescription
gPeelDescription: @ 80F7BB0
.string "{ARG_POKEMON_0} peeled\n"
.string "the {ARG_MOVE_ITEM_0}.\0"
.align 2,0

.global gIngestText
gIngestText: @ 80F7BC4
.string "Ingest\0"
.align 2,0

.global gIngestDescription
gIngestDescription: @ 80F7BCC
.string "{ARG_POKEMON_0} swallowed\n"
.string "the {ARG_MOVE_ITEM_0}.\0"
.align 2,0

.global gEatText
gEatText: @ 80F7BE4
.string "Eat\0"
.align 2,0

.global gEatDescription
gEatDescription: @ 80F7BE8
.string "{ARG_POKEMON_0} ate\n"
.string "the {ARG_MOVE_ITEM_0}.\0"
.align 2,0

.global gEquipText
gEquipText: @ 80F7BFC
.string "Equip\0"
.align 2,0

.global gEquipDescription
gEquipDescription: @ 80F7C04
.string "{ARG_POKEMON_0} equipped\n"
.string "the {ARG_MOVE_ITEM_0}.\0"
.align 2,0

.global gThrowText
gThrowText: @ 80F7C1C
.string "Throw\0"
.align 2,0

.global gThrowDescription
gThrowDescription: @ 80F7C24
.string "{ARG_POKEMON_0} threw\n"
.string "the {ARG_MOVE_ITEM_0}.\0"
.align 2,0

.global gUseText
gUseText: @ 80F7C38
.string "Use\0"
.align 2,0

.global gUseDescription
gUseDescription: @ 80F7C3C

.global gUnknown_80F7C3C
gUnknown_80F7C3C: @ 80F7C3C
.string "{ARG_POKEMON_0} used\n"
.string "the {ARG_MOVE_ITEM_0}.\0"
.align 2,0

.global gUnknown_80F7C50
gUnknown_80F7C50: @ 80F7C50
.4byte gMenuQuestionMarks

.global gUnknown_80F7C54
gUnknown_80F7C54: @ 80F7C54
.4byte 0x0000000A
.4byte gMenuWaitText
.4byte 0x0000000A
.4byte gMenuMoveText
.4byte 0x0000000A
.4byte gMenuMoveText
.4byte 0x0000000A
.4byte gMenuWaitText
.4byte 0x0000000A
.4byte gMenuWaitText
.4byte 0x0000000A
.4byte gMenuNextText
.4byte 0x0000000A
.4byte gMenuPrevText
.4byte 0x0000000A
.4byte gMenuPlaceText
.4byte 0x0000000A
.4byte gMenuGetText
.4byte 0x0000000A
.4byte gMenuSwitchText
.4byte 0x0000000A
.4byte gThrowText
.4byte 0x0000000A
.4byte gMenuInfoText
.4byte 0x0000005A
.4byte gMenuXText
.4byte 0x0000000A
.4byte gMenuXText
.4byte 0x0000000A
.4byte gMenuXText
.4byte 0x0000000A
.4byte gMenuXText
.4byte 0x0000000A
.4byte gMenuXText
.4byte 0x0000000A
.4byte gMenuXText
.4byte 0x0000000A
.4byte gMenuTalkText
.4byte 0x0000000A
.4byte gUseText
.4byte 0x0000000A
.4byte gUseText
.4byte 0x0000000A
.4byte gMenuEmpty
.4byte 0x0000000A
.4byte gMenuStruggleText
.4byte 0x0000000A
.4byte gMenuMoneySymbols
.4byte 0x000003E7
.4byte gMenuMovesText
.4byte 0x0000000A
.4byte gMenuTacticsText
.4byte 0x0000000A
.4byte gMenuSummaryText
.4byte 0x0000000A
.4byte gMenuTalkText
.4byte 0x0000000A
.4byte gMenuInfoText
.4byte 0x0000005A
.4byte gMenuSetText
.4byte 0x0000000A
.4byte gMenuSwitchText
.4byte 0x0000000A
.4byte gMenuLinkText
.4byte 0x0000000A
.4byte gMenuDelinkText
.4byte 0x0000000A
.4byte gMenuForgetText
.4byte 0x0000000A
.4byte gUseText
.4byte 0x0000000A
.4byte gThrowText
.4byte 0x0000000A
.4byte gMenuTriggerText
.4byte 0x0000000A
.4byte gMenuProceedText
.4byte 0x0000000A
.4byte gThrowText
.4byte 0x00000005
.4byte gMenuSwitchText
.4byte 0x0000000A
.4byte gMenuFarewellText
.4byte 0x0000000A
.4byte gMenuCancelText
.4byte 0x0000000A
.4byte gMenuQuicksaveText
.4byte 0x0000000A
.4byte gUseText
.4byte 0x0000000A
.4byte gMenuTalkText
.4byte 0x0000000A
.4byte gMenuGiveUpText
.4byte 0x0000000A
.4byte gMenuSwitchText
.4byte 0x0000000A
.4byte gMenuCheckIQText
.4byte 0x0000000A
.4byte gUseText
.4byte 0x0000000A
.4byte gUseText
.4byte 0x0000000A
.4byte gMenuDeselectText
.4byte 0x0000000A
.4byte gMenuFarewellText
.4byte 0x0000000A
.4byte gUseText
.4byte 0x0000000A
.4byte gMenuGiveText
.4byte 0x0000000A
.4byte gMenuTakeText
.4byte 0x0000000A
.4byte gUseText
.4byte 0x0000000A
.4byte gMenuEmpty
.4byte 0x0000000A
.4byte gMenuSwapText
.4byte 0x0000000A
.4byte gMenuLeaderText
.4byte 0x0000000A
.4byte gMenuSetText
.4byte 0x0000000A
.4byte gMenuDeselectText
.4byte 0x0000000A
.4byte gMenuSwapText
.4byte 0x0000000A
.4byte gMenuPickUpText
.4byte 0x0000000A
.4byte gMenuSummaryText
.4byte 0x0000000A
.4byte gThrowText
.4byte 0x00000005

.global gMenuPickUpText
gMenuPickUpText: @ 80F7E60
.string "Pick Up\0"
.align 2,0

.global gMenuLeaderText
gMenuLeaderText: @ 80F7E68
.string "Leader\0"
.align 2,0

.global gMenuSwapText
gMenuSwapText: @ 80F7E70
.string "Swap\0"
.align 2,0

.global gMenuTakeText
gMenuTakeText: @ 80F7E78
.string "Take\0"
.align 2,0

.global gMenuGiveText
gMenuGiveText: @ 80F7E80
.string "Give\0"
.align 2,0

.global gMenuDeselectText
gMenuDeselectText: @ 80F7E88
.string "Deselect\0"
.align 2,0

.global gMenuCheckIQText
gMenuCheckIQText: @ 80F7E94
.string "Check IQ\0"
.align 2,0

.global gMenuGiveUpText
gMenuGiveUpText: @ 80F7EA0
.string "Give Up\0"
.align 2,0

.global gMenuQuicksaveText
gMenuQuicksaveText: @ 80F7EA8

.global gUnknown_80F7EA8
gUnknown_80F7EA8: @ 80F7EA8
.string "Quicksave\0"
.align 2,0

.global gMenuCancelText
gMenuCancelText: @ 80F7EB0
.string "Cancel\0"
.align 2,0

.global gMenuFarewellText
gMenuFarewellText: @ 80F7EBC
.string "Farewell\0"
.align 2,0

.global gMenuProceedText
gMenuProceedText: @ 80F7EC8
.string "Proceed\0"
.align 2,0

.global gMenuTriggerText
gMenuTriggerText: @ 80F7ED0
.string "Trigger\0"
.align 2,0

.global gMenuForgetText
gMenuForgetText: @ 80F7ED8
.string "Forget\0"
.align 2,0

.global gMenuDelinkText
gMenuDelinkText: @ 80F7EE0
.string "Delink\0"
.align 2,0

.global gMenuLinkText
gMenuLinkText: @ 80F7EE8
.string "Link\0"
.align 2,0

.global gMenuSetText
gMenuSetText: @ 80F7EF0
.string "Set\0"
.align 2,0

.global gMenuSummaryText
gMenuSummaryText: @ 80F7EF4
.string "Summary\0"
.align 2,0

.global gMenuTacticsText
gMenuTacticsText: @ 80F7EFC
.string "Tactics\0"
.align 2,0

.global gMenuMovesText
gMenuMovesText: @ 80F7F04

.global gUnknown_80F7F04
gUnknown_80F7F04: @ 80F7F04
.string "Moves\0"
.align 2,0

.global gMenuMoneySymbols
gMenuMoneySymbols: @ 80F7F0C
.string "$$$$\0"
.align 2,0

.global gMenuStruggleText
gMenuStruggleText: @ 80F7F14
.string "Struggle\0"
.align 2,0

.global gMenuEmpty
gMenuEmpty: @ 80F7F20

.global gUnknown_80F7F20
gUnknown_80F7F20: @ 80F7F20
.byte 0x00
.align 2,0

.global gMenuTalkText
gMenuTalkText: @ 80F7F24
.string "Talk\0"
.align 2,0

.global gMenuXText
gMenuXText: @ 80F7F2C
.string "X\0"
.align 2,0

.global gMenuInfoText
gMenuInfoText: @ 80F7F30
.string "Info\0"
.align 2,0

.global gMenuSwitchText
gMenuSwitchText: @ 80F7F38
.string "Switch\0"
.align 2,0

.global gMenuGetText
gMenuGetText: @ 80F7F40
.string "Get\0"
.align 2,0

.global gMenuPlaceText
gMenuPlaceText: @ 80F7F44
.string "Place\0"
.align 2,0

.global gMenuPrevText
gMenuPrevText: @ 80F7F4C
.string "Prev.\0"
.align 2,0

.global gMenuNextText
gMenuNextText: @ 80F7F54
.string "Next\0"
.align 2,0

.global gMenuMoveText
gMenuMoveText: @ 80F7F5C
.string "Move\0"
.align 2,0

.global gMenuWaitText
gMenuWaitText: @ 80F7F64
.string "Wait\0"
.align 2,0

.global gMenuQuestionMarks
gMenuQuestionMarks: @ 80F7F6C
.string "???\0"
.align 2,0

.global gUnknown_80F7F70
gUnknown_80F7F70: @ 80F7F70
.4byte gDungeonStairsDescription
.4byte gWarpZoneDescription
.4byte gRescueSpotDescription

.global gRescueSpotDescription
gRescueSpotDescription: @ 80F7F7C
.string "You reached the rescue spot where your\n"
.string "friend's team went down!\n"
.string "Send an {COLOR_2 RED}A-OK Mail{END_COLOR_TEXT_2} from the Pelipper Post\n"
.string "Office to let your friend know you've\n"
.string "rescued the defeated team.\0"
.align 2,0

.global gWarpZoneDescription
gWarpZoneDescription: @ 80F8030
.string "The warp zone leading to the next floor.\n"
.string "If you are on the final floor, you will\n"
.string "escape from the dungeon.\0"
.align 2,0

.global gDungeonStairsDescription
gDungeonStairsDescription: @ 80F809C
.string "Stairs leading to the next floor.\n"
.string "If you are on the final floor, you will\n"
.string "escape from the dungeon.\0"
.align 2,0

.global gUnknown_80F8104
gUnknown_80F8104: @ 80F8104
.4byte gDungeonStairsText
.4byte gWarpZoneText
.4byte gRescueSpotText

.global gRescueSpotText
gRescueSpotText: @ 80F7F7C
.string "Rescue Spot\0"
.align 2,0

.global gWarpZoneText
gWarpZoneText: @ 80F8030

.global gUnknown_80F811C
gUnknown_80F811C: @ 80F811C
.string "Warp Zone\0"
.align 2,0

.global gDungeonStairsText
gDungeonStairsText: @ 80F809C

.global gUnknown_80F8128
gUnknown_80F8128: @ 80F8128
.string "Stairs\0"
.align 2,0

.global gTrapDescriptions
gTrapDescriptions: @ 80F8130
@ replacing .incbin "baserom.gba", 0xF8130, 0x838
.4byte TripTrapDescription
.4byte MudTrapDescription
.4byte StickyTrapDescription
.4byte SludgeTrapDescription
.4byte SweetScentTrapDescription
.4byte PitfallTrapDescription
.4byte WarpTrapDescription
.4byte GustTrapDescription
.4byte ConfuseTrapDescription
.4byte SleepTrapDescription
.4byte SlowTrapDescription
.4byte SealTrapDescription
.4byte PoisonTrapDescription
.4byte SelfdestructTrapDescription
.4byte ExplosionTrapDescription
.4byte PPZeroTrapDescription
.4byte ChestnutTrapDescription
.4byte WonderTileDescription
.4byte PokemonTrapDescription
.4byte SpikeTrapDescription

.global SpikeTrapDescription
SpikeTrapDescription: @ 80F8180
.string "Stepping on this trap inflicts damage.\n"
.string "It can be made using the move {COLOR_2 YELLOW}Spikes{END_COLOR_TEXT_2}.\0"
.align 2, 0

.global PokemonTrapDescription
PokemonTrapDescription: @ 80F81D4
.string "Stepping on this trap transforms all\n"
.string "items in the room into hostile Pokémon.\0"
.align 2, 0

.global WonderTileDescription
WonderTileDescription: @ 80F8224
.string "An odd floor tile seen in many dungeons.\n"
.string "Stepping on it resets the Pokémon's\n"
.string "{COLOR_2 YELLOW}Attack{END_COLOR_TEXT_2}, {COLOR_2 YELLOW}Defense{END_COLOR_TEXT_2}, and so on, if\n"
.string "they are boosted or reduced.\0"
.align 2, 0

.global ChestnutTrapDescription
ChestnutTrapDescription: @ 80F82C0
.string "Stepping on this trap makes a spiky,\n"
.string "unshelled Chestnut drop, inflicting\n"
.string "damage.\0"
.align 2, 0

.global PPZeroTrapDescription
PPZeroTrapDescription: @ 80F8318
.string "Stepping on this trap completely drains\n"
.string "the {COLOR_2 YELLOW}PP{END_COLOR_TEXT_2} of a random move.\0"
.align 2, 0

.global ExplosionTrapDescription
ExplosionTrapDescription: @ 80F8360
.string "Stepping on this trap triggers a\n"
.string "{COLOR_2 CYAN}huge explosion{END_COLOR_TEXT_2}.\n"
.string "Its damage extends to other Pokémon,\n"
.string "items, and walls. It has a bigger\n"
.string "range than a Selfdestruct Trap.\0"
.align 2, 0

.global SelfdestructTrapDescription
SelfdestructTrapDescription: @ 80F8404
.string "Stepping on this trap makes it {COLOR_2 CYAN}explode{END_COLOR_TEXT_2}.\n"
.string "Its damage extends to other Pokémon,\n"
.string "items, and walls around the trap.\0"
.align 2, 0

.global PoisonTrapDescription
PoisonTrapDescription: @ 80F847C
.string "Stepping on this trap looses poison\n"
.string "spikes that leave the Pokémon {COLOR_2 CYAN}poisoned{END_COLOR_TEXT_2}.\0"
.align 2, 0

.global SealTrapDescription
SealTrapDescription: @ 80F84D0
.string "Stepping on this trap disables one\n"
.string "of the Pokémon's moves as long\n"
.string "as it remains on the same floor.\0"
.align 2, 0

.global SlowTrapDescription
SlowTrapDescription: @ 80F8538
.string "Stepping on this trap lowers the\n"
.string "Pokémon's {COLOR_2 YELLOW}Movement Speed{END_COLOR_TEXT_2} by one level.\0"
.align 2, 0

.global SleepTrapDescription
SleepTrapDescription: @ 80F8588
.string "Stepping on this trap releases a sleeping\n"
.string "gas that puts the Pokémon to\n"
.string "{COLOR_2 CYAN}sleep{END_COLOR_TEXT_2}.\0"
.align 2, 0

.global ConfuseTrapDescription
ConfuseTrapDescription: @ 80F85DC
.string "Stepping on this trap spins the Pokémon\n"
.string "around dizzyingly, making it \n"
.string "{COLOR_2 CYAN}confused{END_COLOR_TEXT_2}.\0"
.align 2, 0

.global GustTrapDescription
GustTrapDescription: @ 80F8634
.string "Stepping on this trap triggers a blast\n"
.string "of some sort that sends the Pokémon\n"
.string "flying.\0"
.align 2, 0

.global WarpTrapDescription
WarpTrapDescription: @ 80F8688
.string "Stepping on this trap instantly warps\n"
.string "the Pokémon to another spot on the floor.\0"
.align 2, 0

.global PitfallTrapDescription
PitfallTrapDescription: @ 80F86D8
.string "Stepping on this trap drops the Pokémon\n"
.string "to the next floor, inflicting damage.\n"
.string "If it's not the team leader, the Pokémon\n"
.string "faints. If that happens, even a Reviver\n"
.string "Seed can't help the fainted Pokémon.\0"
.align 2, 0

.global SweetScentTrapDescription
SweetScentTrapDescription: @ 80F87A8
.string "Stepping on this trap releases a sweet\n"
.string "aroma that attracts Pokémon from afar.\0"
.align 2, 0

.global SludgeTrapDescription
SludgeTrapDescription: @ 80F87F8
.string "Stepping on this trap makes it spew\n"
.string "muck that gums up food.\0"
.align 2, 0

.global StickyTrapDescription
StickyTrapDescription: @ 80F8834
.string "Stepping on this trap makes a random\n"
.string "item become sticky and unusable.\0"
.align 2, 0

.global MudTrapDescription
MudTrapDescription: @ 80F887C
.string "Stepping on this trap makes it blow\n"
.string "mud that lowers the Pokémon's {COLOR_2 YELLOW}Attack{END_COLOR_TEXT_2},\n"
.string "{COLOR_2 YELLOW}Defense{END_COLOR_TEXT_2}, {COLOR_2 YELLOW}Special Attack{END_COLOR_TEXT_2}, or\n"
.string "{COLOR_2 YELLOW}Special Defense{END_COLOR_TEXT_2} by one level.\0"
.align 2, 0
@ This trap is unused in the game.

.global TripTrapDescription
TripTrapDescription: @ 80F891C
.string "Stepping on this trap makes the Pokémon\n"
.string "trip and drop an item.\0"
.align 2, 0

.global gUnknown_80F895C
gUnknown_80F895C: @ 80F895C
.string "{COLOR_2 YELLOW}Decoy{END_COLOR_TEXT_2}\0"
.align 2, 0

.global gUnknown_80F8968
gUnknown_80F8968: @ 80F8968
.4byte gUnknown_80F895C

.global gUnknown_80F896C
gUnknown_80F896C: @ 80F896C
.string "Decoy\0"
.align 2,0

.global gUnknown_80F8974
gUnknown_80F8974: @ 80F8974
@ replacing .incbin "baserom.gba", 0xF8974, 0x14
.4byte gUnknown_80F896C

.global gUnknown_80F8978
gUnknown_80F8978: @ 80F8978
.string "{COLOR_2 YELLOW}Pokémon{END_COLOR_TEXT_2}\0"
.align 2, 0

.global gUnknown_80F8988
gUnknown_80F8988: @ 80F8988
@ replacing .incbin "baserom.gba", 0xF8988, 0xC
.4byte gUnknown_80F8978

.global gUnknown_80F898C
gUnknown_80F898C: @ 80F898C
.string "Pokémon\0"
.align 2, 0

.global gUnknown_80F8994
gUnknown_80F8994: @ 80F8994
.4byte gUnknown_80F898C

.global PartnerFainted_80F8998
PartnerFainted_80F8998: @ 80F8998
.string "Your partner {ARG_POKEMON_0} fainted!\0"
.align 2,0

.global gUnknown_80F89B4
gUnknown_80F89B4: @ 80F89B4
.4byte PartnerFainted_80F8998

.global ClientFainted_80F89B8
ClientFainted_80F89B8: @ 80F89B8
.string "Your client {ARG_POKEMON_0} fainted!\0"
.align 2,0

.global gUnknown_80F89D4
gUnknown_80F89D4: @ 80F89D4
.4byte ClientFainted_80F89B8

.global gUnknown_80F89D8
gUnknown_80F89D8: @ 80F89D8
.4byte ClientFainted_80F89B8

.global NothingHappened_80F89DC
NothingHappened_80F89DC: @ 80F89DC

.global gUnknown_80F89DC
gUnknown_80F89DC: @ 80F89DC
.string "But nothing happened!\0"
.align 2,0

.global gUnknown_80F89F4
gUnknown_80F89F4: @ 80F89F4
.4byte NothingHappened_80F89DC

.global BlownAway_80F89F8
BlownAway_80F89F8: @ 80F89F8
.string "{ARG_POKEMON_0} was blown away!\0"
.align 2,0

.global gUnknown_80F8A0C
gUnknown_80F8A0C: @ 80F8A0C
.4byte BlownAway_80F89F8

.global NoToggleSetMove_80F8A10
NoToggleSetMove_80F8A10: @ 80F8A10
.string "No move has been set.\0"
.align 2,0

.global gUnknown_80F8A28
gUnknown_80F8A28: @ 80F8A28
.4byte NoToggleSetMove_80F8A10

.global ToggleSetMoveCantUse_80F8A2C
ToggleSetMoveCantUse_80F8A2C: @ 80F8A2C
.string "The set move can't be used.\0"
.align 2,0

.global gUnknown_80F8A4C
gUnknown_80F8A4C: @ 80F8A4C
.4byte ToggleSetMoveCantUse_80F8A2C

.global BeingConstricted_80F8A50
BeingConstricted_80F8A50: @ 80F8A50
.string "You're being constricted!\0"
.align 2,0

.global gUnknown_80F8A6C
gUnknown_80F8A6C: @ 80F8A6C
.4byte BeingConstricted_80F8A50

.global CantMove_80F8A70
CantMove_80F8A70: @ 80F8A70
.string "You can't move!\0"
.align 2,0

.global gUnknown_80F8A84
gUnknown_80F8A84: @ 80F8A84
.4byte CantMove_80F8A70

.global gUnknown_80F8A88
gUnknown_80F8A88: @ 80F8A88
.string "You can't move while you're rooted!\0"
.align 2,0

.global gUnknown_80F8AB0
gUnknown_80F8AB0: @ 80F8AB0
.4byte gUnknown_80F8A88

.global gUnknown_80F8AB4
gUnknown_80F8AB4: @ 80F8AB4
.string "You can't move while wrapping a foe!\0"
.align 2,0

.global gUnknown_80F8ADC
gUnknown_80F8ADC: @ 80F8ADC
.4byte gUnknown_80F8AB4

.global gUnknown_80F8AE0
gUnknown_80F8AE0: @ 80F8AE0
.string "The foe has you wrapped! You can't move!\0"
.align 2,0

.global gUnknown_80F8B0C
gUnknown_80F8B0C: @ 80F8B0C
.4byte gUnknown_80F8AE0

.global gUnknown_80F8B10
gUnknown_80F8B10: @ 80F8B10
.string "There are no items.\0"

.global gUnknown_80F8B24
gUnknown_80F8B24: @ 80F8B24
.4byte gUnknown_80F8B10

.global gUnknown_80F8B28
gUnknown_80F8B28: @ 80F8B28
.string "The move {ARG_MOVE_ITEM_0} was set.\0"
.align 2,0

.global gUnknown_80F8B40
gUnknown_80F8B40: @ 80F8B40
.4byte gUnknown_80F8B28

.global gUnknown_80F8B44
gUnknown_80F8B44: @ 80F8B44
.string "The move {ARG_MOVE_ITEM_0} was deselected.\0"
.align 2,0

.global gUnknown_80F8B64
gUnknown_80F8B64: @ 80F8B64
.4byte gUnknown_80F8B44
.4byte gMenuEmpty

.global gUnknown_80F8B6C
gUnknown_80F8B6C: @ 80F8B6C
.string "The move {ARG_MOVE_ITEM_0} was delinked.\0"
.align 2,0

.global gUnknown_80F8B88
gUnknown_80F8B88: @ 80F8B88
.4byte gUnknown_80F8B6C

.global gUnknown_80F8B8C
gUnknown_80F8B8C: @ 80F8B8C
.string "The linked moves were left unchanged.\0"
.align 2,0

.global gUnknown_80F8BB4
gUnknown_80F8BB4: @ 80F8BB4
.4byte gUnknown_80F8B8C

.global gUnknown_80F8BB8
gUnknown_80F8BB8: @ 80F8BB8
.string "It's all sticky and doesn't work!\0"
.align 2,0

.global gUnknown_80F8BE0
gUnknown_80F8BE0: @ 80F8BE0
@ replacing .incbin "baserom.gba", 0xF8BE0, 0x60
.4byte gUnknown_80F8BB8

.global gUnknown_80F8BE4
gUnknown_80F8BE4: @ 80F8BE4
.string "The {ARG_MOVE_ITEM_1} is all sticky!\n"
.string "It doesn't work!\0"
.align 2, 0
.4byte gUnknown_80F8BE4

.global gUnknown_80F8C14
gUnknown_80F8C14: @ 80F8C14
.string "The {ARG_MOVE_ITEM_1} is all sticky!\n"
.string "It can't be moved.\0"
.align 2, 0

.global gItemStickyCannotMove1
gItemStickyCannotMove1: @ 80F8C40
.4byte gUnknown_80F8C14

.global gItemStickyCannotMove2
gItemStickyCannotMove2: @ 80F8C44
.4byte gUnknown_80F8C14

.global gItemStickyCannotMove3
gItemStickyCannotMove3: @ 80F8C48
.4byte gUnknown_80F8C14

.global gUnknown_80F8C4C
gUnknown_80F8C4C: @ 80F8C4C
.string "The {ARG_MOVE_ITEM_0} is all sticky!\n"
.string "It can't be equipped.\0"
.align 2,0

.global gItemStickyCannotEquip
gItemStickyCannotEquip: @ 80F8C7C
.4byte gUnknown_80F8C4C

.global gUnknown_80F8C80
gUnknown_80F8C80: @ 80F8C80
.string "{ARG_POKEMON_1} took the {ARG_MOVE_ITEM_0}\n"
.string "and returned the {ARG_MOVE_ITEM_1}.\0"
.align 2,0

.global gMonTookAndReturnedItem
gMonTookAndReturnedItem: @ 80F8CA8
@ replacing .incbin "baserom.gba", 0xF8CA8, 0x3C
.4byte gUnknown_80F8C80

.global gUnknown_80F8CAC
gUnknown_80F8CAC: @ 80F8CAC
.string "The {ARG_MOVE_ITEM_0} was set.\n"
.string "Hold {L_BUTTON} then press {R_BUTTON} to throw one.\0"
.align 2, 0

.global gUnknown_80F8CE4
gUnknown_80F8CE4: @ 80F8CE4
.4byte gUnknown_80F8CAC

.global gUnknown_80F8CE8
gUnknown_80F8CE8: @ 80F8CE8
.4byte gUnknown_80F8CAC

.global gUnknown_80F8CEC
gUnknown_80F8CEC: @ 80F8CEC
.string "Equipped the item {ARG_MOVE_ITEM_0}.\0"
.align 2,0

.global gUnknown_80F8D04
gUnknown_80F8D04: @ 80F8D04
.4byte gUnknown_80F8CEC

.global gUnknown_80F8D08
gUnknown_80F8D08: @ 80F8D08
.string "The {ARG_MOVE_ITEM_0} was deselected.\0"

.global gUnknown_80F8D20
gUnknown_80F8D20: @ 80F8D20
.4byte gUnknown_80F8D08

.global gUnknown_80F8D24
gUnknown_80F8D24: @ 80F8D24
.string "The item {ARG_MOVE_ITEM_0} was given\n"
.string "to {ARG_POKEMON_1}.\0"
.align 2,0

.global gUnknown_80F8D44
gUnknown_80F8D44: @ 80F8D44
.4byte gUnknown_80F8D24

.global gUnknown_80F8D48
gUnknown_80F8D48: @ 80F8D48
.string "The Toolbox is full.\0"
.align 2,0

.global gUnknown_80F8D60
gUnknown_80F8D60: @ 80F8D60
@ replacing .incbin "baserom.gba", 0xF8D60, 0x1C
.4byte gUnknown_80F8D48

.global gUnknown_80F8D64
gUnknown_80F8D64: @ 80F8D64
.string "{ARG_POKEMON_0} returned\n"
.string "the {ARG_MOVE_ITEM_0}.\0"
.align 2, 0

.global gUnknown_80F8D7C
gUnknown_80F8D7C: @ 80F8D7C
@ replacing .incbin "baserom.gba", 0xF8D7C, 0x38
.4byte gUnknown_80F8D64

.global gUnknown_80F8D80
gUnknown_80F8D80: @ 80F8D80
.string "The {ARG_MOVE_ITEM_0} was exchanged for\n"
.string "the {ARG_MOVE_ITEM_1} in the Toolbox.\0"
.align 2, 0

.global gUnknown_80F8DB4
gUnknown_80F8DB4: @ 80F8DB4
@ replacing .incbin "baserom.gba", 0xF8DB4, 0x2C
.4byte gUnknown_80F8D80

.global gUnknown_80F8DB8
gUnknown_80F8DB8: @ 80F8DB8
.string "{ARG_POKEMON_1} used the {ARG_MOVE_ITEM_0}\n"
.string "it was holding!\0"
.align 2, 0
.4byte gUnknown_80F8DB8

.global gUnknown_80F8DE0
gUnknown_80F8DE0: @ 80F8DE0
@ replacing .incbin "baserom.gba", 0xF8DE0, 0x24
.4byte gUnknown_80F7F20

.global gUnknown_80F8DE4
gUnknown_80F8DE4: @ 80F8DE4
.string "It can't be put down here.\0"
.align 2, 0

.global gUnknown_80F8E04
gUnknown_80F8E04: @ 80F8E04
@ replacing .incbin "baserom.gba", 0xF8E04, 0x24
.4byte gUnknown_80F8DE4

.global gUnknown_80F8E08
gUnknown_80F8E08: @ 80F8E08
.string "{ARG_POKEMON_0} put the {ARG_MOVE_ITEM_0}\n"
.string "on the ground.\0"
.align 2, 0

.global gUnknown_80F8E28
gUnknown_80F8E28: @ 80F8E28
@ replacing .incbin "baserom.gba", 0xF8E28, 0x4
.4byte gUnknown_80F8E08

.global gUnknown_80F8E2C
gUnknown_80F8E2C: @ 80F8E2C
@ replacing .incbin "baserom.gba", 0xF8E2C, 0x28
.4byte gUnknown_80F7F20

.global gUnknown_80F8E30
gUnknown_80F8E30: @ 80F8E30
.string "Items can't be exchanged here.\0"
.align 2, 0

.global gNoExchangesHere
gNoExchangesHere: @ 80F8E54
@ replacing .incbin "baserom.gba", 0xF8E54, 0x24
.4byte gUnknown_80F8E30

.global gUnknown_80F8E58
gUnknown_80F8E58: @ 80F8E58
.string "Nothing can be put down here.\0"
.align 2, 0

.global gNothingCanBePutDownHere
gNothingCanBePutDownHere: @ 80F8E78
@ replacing .incbin "baserom.gba", 0xF8E78, 0x34
.4byte gUnknown_80F8E58

.global gUnknown_80F8E7C
gUnknown_80F8E7C: @ 80F8E7C
.string "Exchanged the {ARG_MOVE_ITEM_1} on the\n"
.string "ground with the {ARG_MOVE_ITEM_0}.\0"
.align 2, 0

.global gSwappedGroundItem
gSwappedGroundItem: @ 80F8EAC
@ replacing .incbin "baserom.gba", 0xF8EAC, 0x18
.4byte gUnknown_80F8E7C

.global gUnknown_80F8EB0
gUnknown_80F8EB0: @ 80F8EB0
.string "{ARG_POKEMON_0} threw the {ARG_MOVE_ITEM_0}!\0"
.align 2, 0

.global gMonThrewItem1
gMonThrewItem1: @ 80F8EC4
@ replacing .incbin "baserom.gba", 0xF8EC4, 0x4
.4byte gUnknown_80F8EB0

.global gMonThrewItem2
gMonThrewItem2: @ 80F8EC8
@ replacing .incbin "baserom.gba", 0xF8EC8, 0x1C
.4byte gUnknown_80F8EB0

.global gUnknown_80F8ECC
gUnknown_80F8ECC: @ 80F8ECC
.string "You can't talk now.\0"
.align 2, 0

.global gCannotTalk
gCannotTalk: @ 80F8EE4
@ replacing .incbin "baserom.gba", 0xF8EE4, 0x24
.4byte gUnknown_80F8ECC

.global gUnknown_80F8EE8
gUnknown_80F8EE8: @ 80F8EE8
.string "You can't say farewell now.\0"
.align 2, 0

.global gCannotFarewell
gCannotFarewell: @ 80F8F08
@ replacing .incbin "baserom.gba", 0xF8F08, 0x18
.4byte gUnknown_80F8EE8

.global gUnknown_80F8F0C
gUnknown_80F8F0C: @ 80F8F0C
.string "{ARG_POKEMON_0} is cringing!\0"
.align 2, 0

.global gMonCringing
gMonCringing: @ 80F8F20
@ replacing .incbin "baserom.gba", 0xF8F20, 0x18
.4byte gUnknown_80F8F0C

.global gUnknown_80F8F24
gUnknown_80F8F24: @ 80F8F24
.string "{ARG_POKEMON_0} is paralyzed!\0"
.align 2, 0

.global gMonParalyzed
gMonParalyzed: @ 80F8F38
@ replacing .incbin "baserom.gba", 0xF8F38, 0x1C
.4byte gUnknown_80F8F24

.global gUnknown_80F8F3C
gUnknown_80F8F3C: @ 80F8F3C
.string "{ARG_POKEMON_0} stepped on\n"
.string "the {ARG_MOVE_ITEM_0}.\0"
.align 2, 0

.global gMonSteppedOnItem
gMonSteppedOnItem: @ 80F8F54
@ replacing .incbin "baserom.gba", 0xF8F54, 0x34
.4byte gUnknown_80F8F3C

.global gUnknown_80F8F58
gUnknown_80F8F58: @ 80F8F58
.string "{ARG_POKEMON_0} is terrified.\n"
.string "It didn't pick up the {ARG_MOVE_ITEM_0}.\0"
.align 2, 0

.global gMonTerrifiedCouldntPickUpItem
gMonTerrifiedCouldntPickUpItem: @ 80F8F88
@ replacing .incbin "baserom.gba", 0xF8F88, 0x24
.4byte gUnknown_80F8F58

.global gUnknown_80F8F8C
gUnknown_80F8F8C: @ 80F8F8C
.string "{ARG_POKEMON_0} couldn't pick up\n"
.string "the {ARG_MOVE_ITEM_0}.\0"
.align 2, 0

.global gMonCouldntPickUpItem
gMonCouldntPickUpItem: @ 80F8FAC
@ replacing .incbin "baserom.gba", 0xF8FAC, 0x18
.4byte gUnknown_80F8F8C

.global gUnknown_80F8FB0
gUnknown_80F8FB0: @ 80F8FB0
.string "Picked up the {ARG_MOVE_ITEM_0}.\0"
.align 2, 0

.global gPickedUpItem2
gPickedUpItem2: @ 80F8FC4
@ replacing .incbin "baserom.gba", 0xF8FC4, 0x34
.4byte gUnknown_80F8FB0

.global gUnknown_80F8FC8
gUnknown_80F8FC8: @ 80F8FC8
.string "Picked up the {ARG_MOVE_ITEM_0} and\n"
.string "put it in the Toolbox.\0"
.align 2, 0

.global gPickedUpItemToolbox
gPickedUpItemToolbox: @ 80F8FF8
@ replacing .incbin "baserom.gba", 0xF8FF8, 0x4
.4byte gUnknown_80F8FC8

.global gPickedUpItem
gPickedUpItem: @ 80F8FFC
@ replacing .incbin "baserom.gba", 0xF8FFC, 0x1C
.4byte gUnknown_80F8FB0

.global gUnknown_80F9000
gUnknown_80F9000: @ 80F9000
.string "{ARG_POKEMON_0} picked up\n"
.string "the {ARG_MOVE_ITEM_0}.\0"
.align 2, 0

.global gMonPickedUpItem2
gMonPickedUpItem2: @ 80F9018
@ replacing .incbin "baserom.gba", 0xF9018, 0x38
.4byte gUnknown_80F9000

.global gUnknown_80F901C
gUnknown_80F901C: @ 80F901C
.string "{ARG_POKEMON_0} picked up the\n"
.string "{ARG_MOVE_ITEM_0} and put it in the Toolbox.\0"
.align 2, 0

.global gMonPickedUpItemToolbox
gMonPickedUpItemToolbox: @ 80F9050
@ replacing .incbin "baserom.gba", 0xF9050, 0x4
.4byte gUnknown_80F901C

.global gMonPickedUpItem
gMonPickedUpItem: @ 80F9054
@ replacing .incbin "baserom.gba", 0xF9054, 0x40
.4byte gUnknown_80F9000

.global gUnknown_80F9058
gUnknown_80F9058: @ 80F9058
.string "Say farewell to {ARG_POKEMON_0}?\n"
.string "It will be gone from the team forever.\0"
.align 2, 0

.global gSayFarewellQ
gSayFarewellQ: @ 80F9094
@ replacing .incbin "baserom.gba", 0xF9094, 0x34
.4byte gUnknown_80F9058

.global gUnknown_80F9098
gUnknown_80F9098: @ 80F9098
.string "Send {ARG_POKEMON_0} back?\n"
.string "{ARG_POKEMON_0}'s hold item will be lost.\0"
.align 2, 0

.global gSendMonBackWithItemQ
gSendMonBackWithItemQ: @ 80F90C8
@ replacing .incbin "baserom.gba", 0xF90C8, 0x14
.4byte gUnknown_80F9098

.global gUnknown_80F90CC
gUnknown_80F90CC: @ 80F90CC
.string "Send {ARG_POKEMON_0} back?\0"
.align 2, 0

.global gSendMonBackQ
gSendMonBackQ: @ 80F90DC
@ replacing .incbin "baserom.gba", 0xF90DC, 0x38
.4byte gUnknown_80F90CC

.global gUnknown_80F90E0
gUnknown_80F90E0: @ 80F90E0
.string "Say farewell to {ARG_POKEMON_0} and dismiss\n"
.string "it from the team?\0"
.align 2, 0

.global gUnknown_80F9114
gUnknown_80F9114: @ 80F9114
@ replacing .incbin "baserom.gba", 0xF9114, 0x28
.4byte gUnknown_80F90E0

.global gUnknown_80F9118
gUnknown_80F9118: @ 80F9118
.string "{ARG_POKEMON_0} seemed disappointed and left.\0"
.align 2, 0

.global gUnknown_80F913C
gUnknown_80F913C: @ 80F913C
@ replacing .incbin "baserom.gba", 0xF913C, 0x14
.4byte gUnknown_80F9118

.global gUnknown_80F9140
gUnknown_80F9140: @ 80F9140
.string "{ARG_POKEMON_0} went back.\0"
.align 2, 0

.global gMonWentBack
gMonWentBack: @ 80F9150
@ replacing .incbin "baserom.gba", 0xF9150, 0x4
.4byte gUnknown_80F9140

.global gMonDisappointedAndLeft
gMonDisappointedAndLeft: @ 80F9154
@ replacing .incbin "baserom.gba", 0xF9154, 0x4
.4byte gUnknown_80F9118

.global gUnknown_80F9158
gUnknown_80F9158: @ 80F9158
@ replacing .incbin "baserom.gba", 0xF9158, 0x1C
.4byte gUnknown_80F7C3C

.global gUnknown_80F915C
gUnknown_80F915C: @ 80F915C
.string "$-Belly:{UNK_MACRO_3E M3E_147}{ARG_VALUE_0}/{ARG_VALUE_1}\0"
.align 2, 0

.global gUnknown_80F9174
gUnknown_80F9174: @ 80F9174
@ replacing .incbin "baserom.gba", 0xF9174, 0x1C
.4byte gUnknown_80F915C

.global gUnknown_80F9178
gUnknown_80F9178: @ 80F9178
.string "Money:{UNK_MACRO_3E M3E_147}{ARG_VALUE_0} {POKE}\0"
.align 2, 0

.global gUnknown_80F9190
gUnknown_80F9190: @ 80F9190
@ replacing .incbin "baserom.gba", 0xF9190, 0x18
.4byte gUnknown_80F9178

.global gUnknown_80F9194
gUnknown_80F9194: @ 80F9194
.string "Weather:{UNK_MACRO_3E M3E_159}{ARG_POKEMON_0}\0"
.align 2, 0

.global gUnknown_80F91A8
gUnknown_80F91A8: @ 80F91A8
@ replacing .incbin "baserom.gba", 0xF91A8, 0x20
.4byte gUnknown_80F9194

.global gUnknown_80F91AC
gUnknown_80F91AC: @ 80F91AC
.string "Play:{UNK_MACRO_3E M3E_147}{ARG_VALUE_0}:$V12:$V22\0"
.align 2, 0

.global gUnknown_80F91C8
gUnknown_80F91C8: @ 80F91C8
@ replacing .incbin "baserom.gba", 0xF91C8, 0x18
.4byte gUnknown_80F91AC

.global gUnknown_80F91CC
gUnknown_80F91CC: @ 80F91CC
.string "{ARG_POKEMON_0}{UNK_MACRO_3E M3E_66}$v03/$v13\0"
.align 2, 0

.global gUnknown_80F91E0
gUnknown_80F91E0: @ 80F91E0
@ replacing .incbin "baserom.gba", 0xF91E0, 0xC
.4byte gUnknown_80F91CC

.global gUnknown_80F91E4
gUnknown_80F91E4: @ 80F91E4
.string "Rescue\0"
.align 2, 0

.global gUnknown_80F91EC
gUnknown_80F91EC: @ 80F91EC
@ replacing .incbin "baserom.gba", 0xF91EC, 0x4
.4byte gUnknown_80F91E4

.global gTrapNames
gTrapNames: @ 80F91F0
@ replacing .incbin "baserom.gba", 0xF91F0, 0x174
.4byte gUnknown_80F9344
.4byte gUnknown_80F9338
.4byte gUnknown_80F932C
.4byte gUnknown_80F9320
.4byte gUnknown_80F9314
.4byte gUnknown_80F9304
.4byte gUnknown_80F92F8
.4byte gUnknown_80F92EC
.4byte gUnknown_80F92E0
.4byte gUnknown_80F92D0
.4byte gUnknown_80F92C4
.4byte gUnknown_80F92B8
.4byte gUnknown_80F92AC
.4byte gUnknown_80F9298
.4byte gUnknown_80F9288
.4byte gUnknown_80F9278
.4byte gUnknown_80F9268
.4byte gUnknown_80F925C
.4byte gUnknown_80F924C
.4byte gUnknown_80F9240

.global gUnknown_80F9240
gUnknown_80F9240: @ 80F9240
.string "Spiked Tile\0"
.align 2, 0

.global gUnknown_80F924C
gUnknown_80F924C: @ 80F924C
.string "Pokémon Trap\0"
.align 2, 0

.global gUnknown_80F925C
gUnknown_80F925C: @ 80F925C
.string "Wonder Tile\0"
.align 2, 0

.global gUnknown_80F9268
gUnknown_80F9268: @ 80F9268
.string "Chestnut Trap\0"
.align 2, 0

.global gUnknown_80F9278
gUnknown_80F9278: @ 80F9278
.string "PP-Zero Trap\0"
.align 2, 0

.global gUnknown_80F9288
gUnknown_80F9288: @ 80F9288
.string "Explosion Trap\0"
.align 2, 0

.global gUnknown_80F9298
gUnknown_80F9298: @ 80F9298
.string "Selfdestruct Trap\0"
.align 2, 0

.global gUnknown_80F92AC
gUnknown_80F92AC: @ 80F92AC
.string "Poison Trap\0"
.align 2, 0

.global gUnknown_80F92B8
gUnknown_80F92B8: @ 80F92B8
.string "Seal Trap\0"
.align 2, 0

.global gUnknown_80F92C4
gUnknown_80F92C4: @ 80F92C4
.string "Slow Trap\0"
.align 2, 0

.global gUnknown_80F92D0
gUnknown_80F92D0: @ 80F92D0
.string "Slumber Trap\0"
.align 2, 0

.global gUnknown_80F92E0
gUnknown_80F92E0: @ 80F92E0
.string "Spin Trap\0"
.align 2, 0

.global gUnknown_80F92EC
gUnknown_80F92EC: @ 80F92EC
.string "Gust Trap\0"
.align 2, 0

.global gUnknown_80F92F8
gUnknown_80F92F8: @ 80F92F8
.string "Warp Trap\0"
.align 2, 0

.global gUnknown_80F9304
gUnknown_80F9304: @ 80F9304
.string "Pitfall Trap\0"
.align 2, 0

.global gUnknown_80F9314
gUnknown_80F9314: @ 80F9314
.string "Summon Trap\0"
.align 2, 0

.global gUnknown_80F9320
gUnknown_80F9320: @ 80F9320
.string "Grimy Trap\0"
.align 2, 0

.global gUnknown_80F932C
gUnknown_80F932C: @ 80F932C
.string "Sticky Trap\0"
.align 2, 0

.global gUnknown_80F9338
gUnknown_80F9338: @ 80F9338
.string "Mud Trap\0"
.align 2, 0

.global gUnknown_80F9344
gUnknown_80F9344: @ 80F9344
.string "Trip Trap\0"
.align 2, 0

.global gUnknown_80F9350
gUnknown_80F9350: @ 80F9350
.string "{ARG_POKEMON_1} is unaffected!\0"
.align 2, 0

.global gUnknown_80F9364
gUnknown_80F9364: @ 80F9364
@ replacing .incbin "baserom.gba", 0xF9364, 0x1C
.4byte gUnknown_80F9350

.global gUnknown_80F9368
gUnknown_80F9368: @ 80F9368
.string "The move missed {ARG_POKEMON_1}!\0"
.align 2, 0

.global gUnknown_80F9380
gUnknown_80F9380: @ 80F9380
@ replacing .incbin "baserom.gba", 0xF9380, 0x4
.4byte gUnknown_80F9368

.global gUnknown_80F9384
gUnknown_80F9384: @ 80F9384
@ replacing .incbin "baserom.gba", 0xF9384, 0x20
.4byte gUnknown_80F9368

.global gUnknown_80F9388
gUnknown_80F9388: @ 80F9388
.string "It had no effect on {ARG_POKEMON_1}!\0"
.align 2, 0

.global gUnknown_80F93A4
gUnknown_80F93A4: @ 80F93A4
@ replacing .incbin "baserom.gba", 0xF93A4, 0x24
.4byte gUnknown_80F9388

.global gUnknown_80F93A8
gUnknown_80F93A8: @ 80F93A8
.string "The move {ARG_MOVE_ITEM_0} can't be used!\0"
.align 2, 0

.global gUnknown_80F93C8
gUnknown_80F93C8: @ 80F93C8
@ replacing .incbin "baserom.gba", 0xF93C8, 0x20
.4byte gUnknown_80F93A8

.global gUnknown_80F93CC
gUnknown_80F93CC: @ 80F93CC
.string "The {ARG_MOVE_ITEM_0} fell on the ground.\0"
.align 2, 0

.global gItemFellOnGround
gItemFellOnGround: @ 80F93E8
@ replacing .incbin "baserom.gba", 0xF93E8, 0x20
.4byte gUnknown_80F93CC

.global gUnknown_80F93EC
gUnknown_80F93EC: @ 80F93EC
.string "The {ARG_MOVE_ITEM_0} fell in the water.\0"
.align 2, 0

.global gItemFellInWater
gItemFellInWater: @ 80F9408
@ replacing .incbin "baserom.gba", 0xF9408, 0x1C
.4byte gUnknown_80F93EC

.global gUnknown_80F940C
gUnknown_80F940C: @ 80F940C
.string "The {ARG_MOVE_ITEM_0} became buried.\0"
.align 2, 0

.global gItemBuried
gItemBuried: @ 80F9424
@ replacing .incbin "baserom.gba", 0xF9424, 0x18
.4byte gUnknown_80F940C

.global gUnknown_80F9428
gUnknown_80F9428: @ 80F9428
.string "The {ARG_MOVE_ITEM_0} was lost!\0"
.align 2, 0

.global gItemLost
gItemLost: @ 80F943C
@ replacing .incbin "baserom.gba", 0xF943C, 0x20
.4byte gUnknown_80F9428

.global gUnknown_80F9440
gUnknown_80F9440: @ 80F9440
.string "All the items were lost!\0"
.align 2, 0

.global gAllItemsLost
gAllItemsLost: @ 80F945C
@ replacing .incbin "baserom.gba", 0xF945C, 0x20
.4byte gUnknown_80F9440

.global gUnknown_80F9460
gUnknown_80F9460: @ 80F9460
.string "Several items were lost!\0"
.align 2, 0

.global gSeveralItemsLost
gSeveralItemsLost: @ 80F947C
@ replacing .incbin "baserom.gba", 0xF947C, 0x20
.4byte gUnknown_80F9460

.global gUnknown_80F9480
gUnknown_80F9480: @ 80F9480
.string "The {ARG_MOVE_ITEM_0} fell out of sight!\0"
.align 2, 0

.global gItemFellOutOfSight
gItemFellOutOfSight: @ 80F949C
@ replacing .incbin "baserom.gba", 0xF949C, 0x28
.4byte gUnknown_80F9480

.global gUnknown_80F94A0
gUnknown_80F94A0: @ 80F94A0
.string "The {ARG_MOVE_ITEM_0} went flying\n"
.string "towards {ARG_POKEMON_0}!\0"
.align 2, 0

.global gUnknown_80F94C4
gUnknown_80F94C4: @ 80F94C4
@ replacing .incbin "baserom.gba", 0xF94C4, 0x14
.4byte gUnknown_80F94A0

.global gUnknown_80F94C8
gUnknown_80F94C8: @ 80F94C8
.string "It missed {ARG_POKEMON_0}!\0"
.align 2, 0

.global gUnknown_80F94D8
gUnknown_80F94D8: @ 80F94D8
@ replacing .incbin "baserom.gba", 0xF94D8, 0x18
.4byte gUnknown_80F94C8

.global gUnknown_80F94DC
gUnknown_80F94DC: @ 80F94DC
.string "{ARG_POKEMON_0} dodged the {ARG_MOVE_ITEM_0}!\0"
.align 2, 0

.global gUnknown_80F94F0
gUnknown_80F94F0: @ 80F94F0
@ replacing .incbin "baserom.gba", 0xF94F0, 0x20
.4byte gUnknown_80F94DC

.global gUnknown_80F94F4
gUnknown_80F94F4: @ 80F94F4
.string "The {ARG_MOVE_ITEM_0} bounced off\n"
.string "{ARG_POKEMON_0}!\0"
.align 2, 0

.global gUnknown_80F9510
gUnknown_80F9510: @ 80F9510
@ replacing .incbin "baserom.gba", 0xF9510, 0x20
.4byte gUnknown_80F94F4

.global gUnknown_80F9514
gUnknown_80F9514: @ 80F9514
.string "The {ARG_MOVE_ITEM_0} flew out of sight!\0"
.align 2, 0

.global gUnknown_80F9530
gUnknown_80F9530: @ 80F9530
@ replacing .incbin "baserom.gba", 0xF9530, 0x4
.4byte gUnknown_80F9514

.global gFrozenMessage
gFrozenMessage: @ 80F9534
.string "{ARG_POKEMON_0} is frozen solid!\0"
.align 2, 0

.global gPtrFrozenMessage
gPtrFrozenMessage: @ 80F954C
.4byte gFrozenMessage

.global gWrappedAroundMessage
gWrappedAroundMessage: @ 80F9550
.string "{ARG_POKEMON_0} has its foe wrapped!\0"
.align 2, 0

.global gPtrWrappedAroundMessage
gPtrWrappedAroundMessage: @ 80F956C
.4byte gWrappedAroundMessage

.global gWrappedByMessage
gWrappedByMessage: @ 80F9570
.string "{ARG_POKEMON_0} is wrapped by its foe!\0"
.align 2, 0

.global gPtrWrappedByMessage
gPtrWrappedByMessage: @ 80F958C
.4byte gWrappedByMessage

.global gPausedMessage
gPausedMessage: @ 80F9590
.string "{ARG_POKEMON_0} can't move!\0"
.align 2, 0

.global gPtrPausedMessage
gPtrPausedMessage: @ 80F95A4
.4byte gPausedMessage

.global gInfatuatedMessage
gInfatuatedMessage: @ 80F95A8

.global gUnknown_80F95A8
gUnknown_80F95A8: @ 80F95A8
.string "{ARG_POKEMON_0} is infatuated!\0"
.align 2, 0

.global gPtrInfatuatedMessage
gPtrInfatuatedMessage: @ 80F95BC
.4byte gInfatuatedMessage

.global gBideMessage
gBideMessage: @ 80F95C0
.string "{ARG_POKEMON_0} is storing energy!\0"
.align 2, 0

.global gPtrBideMessage
gPtrBideMessage: @ 80F95D8
.4byte gBideMessage

.global gUnknown_80F95DC
gUnknown_80F95DC: @ 80F95DC
@ replacing .incbin "baserom.gba", 0xF95DC, 0x10

.global gUnknown_80F95DC
gUnknown_80F95DC: @ 80F95DC
.string "{ARG_POKEMON_0} is asleep!\0"
.align 2, 0

.global gUnknown_80F95EC
gUnknown_80F95EC: @ 80F95EC
@ replacing .incbin "baserom.gba", 0xF95EC, 0x14
.4byte gUnknown_80F95DC

.global gUnknown_80F95F0
gUnknown_80F95F0: @ 80F95F0
.string "{ARG_POKEMON_1} is frozen!\0"
.align 2, 0

.global gUnknown_80F9600
gUnknown_80F9600: @ 80F9600
@ replacing .incbin "baserom.gba", 0xF9600, 0x14
.4byte gUnknown_80F95F0

.global gUnknown_80F9604
gUnknown_80F9604: @ 80F9604
.string "A critical hit!\0"
.align 2, 0

.global gUnknown_80F9614
gUnknown_80F9614: @ 80F9614
@ replacing .incbin "baserom.gba", 0xF9614, 0x1C
.4byte gUnknown_80F9604

.global gUnknown_80F9618
gUnknown_80F9618: @ 80F9618
.string "It has little effect...\0"
.align 2, 0

.global gUnknown_80F9630
gUnknown_80F9630: @ 80F9630
@ replacing .incbin "baserom.gba", 0xF9630, 0x24
.4byte gUnknown_80F9618

.global gUnknown_80F9634
gUnknown_80F9634: @ 80F9634
.string "It's not very effective...\0"
.align 2, 0

.global gUnknown_80F9654
gUnknown_80F9654: @ 80F9654
@ replacing .incbin "baserom.gba", 0xF9654, 0x1C
.4byte gUnknown_80F9634

.global gUnknown_80F9658
gUnknown_80F9658: @ 80F9658
.string "It's super effective!\0"
.align 2, 0

.global gUnknown_80F9670
gUnknown_80F9670: @ 80F9670
@ replacing .incbin "baserom.gba", 0xF9670, 0x18
.4byte gUnknown_80F9658

.global gUnknown_80F9674
gUnknown_80F9674: @ 80F9674
.string "{ARG_POKEMON_1} took no damage!\0"
.align 2, 0

.global gUnknown_80F9688
gUnknown_80F9688: @ 80F9688
@ replacing .incbin "baserom.gba", 0xF9688, 0x20
.4byte gUnknown_80F9674

.global gUnknown_80F968C
gUnknown_80F968C: @ 80F968C
.string "{ARG_POKEMON_1} took calamitous damage!\0"
.align 2, 0

.global gUnknown_80F96A8
gUnknown_80F96A8: @ 80F96A8
@ replacing .incbin "baserom.gba", 0xF96A8, 0x14
.4byte gUnknown_80F968C

.global gUnknown_80F96AC
gUnknown_80F96AC: @ 80F96AC
.string "{ARG_POKEMON_0} exploded!\0"
.align 2, 0

.global gUnknown_80F96BC
gUnknown_80F96BC: @ 80F96BC
@ replacing .incbin "baserom.gba", 0xF96BC, 0x30
.4byte gUnknown_80F96AC

.global gUnknown_80F96C0
gUnknown_80F96C0: @ 80F96C0
.string "The damp conditions prevented\n"
.string "an explosion!\0"
.align 2, 0

.global gUnknown_80F96EC
gUnknown_80F96EC: @ 80F96EC
@ replacing .incbin "baserom.gba", 0xF96EC, 0x20
.4byte gUnknown_80F96C0

.global gUnknown_80F96F0
gUnknown_80F96F0: @ 80F96F0
.string "{ARG_POKEMON_0} fell into the pitfall!\0"
.align 2, 0

.global gUnknown_80F970C
gUnknown_80F970C: @ 80F970C
@ replacing .incbin "baserom.gba", 0xF970C, 0x1C
.4byte gUnknown_80F96F0

.global gUnknown_80F9710
gUnknown_80F9710: @ 80F9710
.string "Avoided the pitfall!\0"
.align 2, 0

.global gUnknown_80F9728
gUnknown_80F9728: @ 80F9728
@ replacing .incbin "baserom.gba", 0xF9728, 0x18
.4byte gUnknown_80F9710

.global gUnknown_80F972C
gUnknown_80F972C: @ 80F972C
.string "{ARG_POKEMON_0} is famished.\0"
.align 2, 0

.global gUnknown_80F9740
gUnknown_80F9740: @ 80F9740
@ replacing .incbin "baserom.gba", 0xF9740, 0x20
.4byte gUnknown_80F972C

.global gUnknown_80F9744
gUnknown_80F9744: @ 80F9744
.string "{ARG_POKEMON_0} is already famished.\0"
.align 2, 0

.global gUnknown_80F9760
gUnknown_80F9760: @ 80F9760
@ replacing .incbin "baserom.gba", 0xF9760, 0x4
.4byte gUnknown_80F9744

.global gUnknown_80F9764
gUnknown_80F9764: @ 80F9764
@ replacing .incbin "baserom.gba", 0xF9764, 0x2F0
.4byte gUnknown_80F9A3C
.4byte gUnknown_80F9A18
.4byte gUnknown_80F99F4
.4byte gUnknown_80F99D0
.4byte gUnknown_80F9A3C
.4byte gUnknown_80F99B0
.4byte gUnknown_80F9984
.4byte gUnknown_80F9964
.4byte gUnknown_80F9930
.4byte gUnknown_80F9908
.4byte gUnknown_80F98E0
.4byte gUnknown_80F98B8
.4byte gUnknown_80F9890
.4byte gUnknown_80F9860
.string "\0"
.align 2, 0
.4byte gUnknown_80F9834
.4byte gUnknown_80F9834
.4byte gUnknown_80F9A3C
.4byte gUnknown_80F9804
.4byte gUnknown_80F97DC
.4byte gUnknown_80F97B8

.global gUnknown_80F97B8
gUnknown_80F97B8: @ 80F97B8
.string "The recoil hit {ARG_POKEMON_1} for\n"
.string "{ARG_VALUE_0} damage!\0"
.align 2, 0

.global gUnknown_80F97DC
gUnknown_80F97DC: @ 80F97DC
.string "The move failed!\n"
.string "{ARG_POKEMON_1} took {ARG_VALUE_0} damage!\0"
.align 2, 0

.global gUnknown_80F9804
gUnknown_80F9804: @ 80F9804
.string "The bad weather inflicted {ARG_VALUE_0} damage\n"
.string "on {ARG_POKEMON_1}!\0"
.align 2, 0

.global gUnknown_80F9834
gUnknown_80F9834: @ 80F9834
.string "The Chestnut Trap hit {ARG_POKEMON_1}\n"
.string "for {ARG_VALUE_0} damage!\0"
.align 2, 0

.global gUnknown_80F9860
gUnknown_80F9860: @ 80F9860
.string "{ARG_POKEMON_1} was showered with sludge\n"
.string "for {ARG_VALUE_0} damage!\0"
.align 2, 0

.global gUnknown_80F9890
gUnknown_80F9890: @ 80F9890
.string "{ARG_POKEMON_1} took {ARG_VALUE_0} damage\n"
.string "from Destiny Bond!\0"
.align 2, 0

.global gUnknown_80F98B8
gUnknown_80F98B8: @ 80F98B8
.string "{ARG_POKEMON_1} took {ARG_VALUE_0} damage\n"
.string "from Perish Song!\0"
.align 2, 0

.global gUnknown_80F98E0
gUnknown_80F98E0: @ 80F98E0
.string "{ARG_POKEMON_1} stepped on spikes for\n"
.string "{ARG_VALUE_0} damage!\0"
.align 2, 0

.global gUnknown_80F9908
gUnknown_80F9908: @ 80F9908
.string "{ARG_POKEMON_1} took {ARG_VALUE_0} damage\n"
.string "from Leech Seed!\0"
.align 2, 0

.global gUnknown_80F9930
gUnknown_80F9930: @ 80F9930
.string "{ARG_POKEMON_1} awoke from its nightmare\n"
.string "and took {ARG_VALUE_0} damage!\0"
.align 2, 0

.global gUnknown_80F9964
gUnknown_80F9964: @ 80F9964
.string "{ARG_POKEMON_1} was cursed for\n"
.string "{ARG_VALUE_0} damage!\0"
.align 2, 0

.global gUnknown_80F9984
gUnknown_80F9984: @ 80F9984
.string "{ARG_POKEMON_1} took {ARG_VALUE_0} damage\n"
.string "from the counterattack!\0"
.align 2, 0

.global gUnknown_80F99B0
gUnknown_80F99B0: @ 80F99B0
.string "{ARG_POKEMON_1} was wrapped for\n"
.string "{ARG_VALUE_0} damage!\0"
.align 2, 0

.global gUnknown_80F99D0
gUnknown_80F99D0: @ 80F99D0
.string "{ARG_POKEMON_1} took {ARG_VALUE_0} damage\n"
.string "from poison!\0"
.align 2, 0

.global gUnknown_80F99F4
gUnknown_80F99F4: @ 80F99F4
.string "{ARG_POKEMON_1} was squeezed for\n"
.string "{ARG_VALUE_0} damage!\0"
.align 2, 0

.global gUnknown_80F9A18
gUnknown_80F9A18: @ 80F9A18
.string "{ARG_POKEMON_1}'s burn inflicted\n"
.string "{ARG_VALUE_0} damage!\0"
.align 2, 0

.global gUnknown_80F9A3C
gUnknown_80F9A3C: @ 80F9A3C
.string "{ARG_POKEMON_1} took {ARG_VALUE_0} damage!\0"
.align 2, 0

.global gWeatherNames
gWeatherNames: @ 80F9A54
@ replacing .incbin "baserom.gba", 0xF9A54, 0x78
.4byte gUnknown_80F9AAC
.4byte gUnknown_80F9AA4
.4byte gUnknown_80F9A98
.4byte gUnknown_80F9A90
.4byte gUnknown_80F9A88
.4byte gUnknown_80F9A80
.4byte gUnknown_80F9A7C
.4byte gUnknown_80F9A74

.global gUnknown_80F9A74
gUnknown_80F9A74: @ 80F9A74
.string "Snow\0"
.align 2, 0

.global gUnknown_80F9A7C
gUnknown_80F9A7C: @ 80F9A7C
.string "Fog\0"
.align 2, 0

.global gUnknown_80F9A80
gUnknown_80F9A80: @ 80F9A80
.string "Hail\0"
.align 2, 0

.global gUnknown_80F9A88
gUnknown_80F9A88: @ 80F9A88
.string "Rain\0"
.align 2, 0

.global gUnknown_80F9A90
gUnknown_80F9A90: @ 80F9A90
.string "Cloudy\0"
.align 2, 0

.global gUnknown_80F9A98
gUnknown_80F9A98: @ 80F9A98
.string "Sandstorm\0"
.align 2, 0

.global gUnknown_80F9AA4
gUnknown_80F9AA4: @ 80F9AA4
.string "Sunny\0"
.align 2, 0

.global gUnknown_80F9AAC
gUnknown_80F9AAC: @ 80F9AAC
.string "Clear\0"
.align 2, 0

.global gUnknown_80F9AB4
gUnknown_80F9AB4: @ 80F9AB4
.string "{ARG_POKEMON_0}'s HP went up {ARG_VALUE_0}!\0"
.align 2, 0

.global gUnknown_80F9ACC
gUnknown_80F9ACC: @ 80F9ACC
@ replacing .incbin "baserom.gba", 0xF9ACC, 0x20
.4byte gUnknown_80F9AB4

.global gUnknown_80F9AD0
gUnknown_80F9AD0: @ 80F9AD0
.string "{ARG_POKEMON_0}'s Attack went up {ARG_VALUE_1}!\0"
.align 2, 0

.global gUnknown_80F9AEC
gUnknown_80F9AEC: @ 80F9AEC
@ replacing .incbin "baserom.gba", 0xF9AEC, 0x24
.4byte gUnknown_80F9AD0

.global gUnknown_80F9AF0
gUnknown_80F9AF0: @ 80F9AF0
.string "{ARG_POKEMON_0}'s Defense went up {ARG_VALUE_2}!\0"
.align 2, 0

.global gUnknown_80F9B10
gUnknown_80F9B10: @ 80F9B10
@ replacing .incbin "baserom.gba", 0xF9B10, 0x24
.4byte gUnknown_80F9AF0

.global gUnknown_80F9B14
gUnknown_80F9B14: @ 80F9B14
.string "{ARG_POKEMON_0}'s Sp. Atk. went up {ARG_VALUE_3}!\0"
.align 2, 0

.global gUnknown_80F9B34
gUnknown_80F9B34: @ 80F9B34
@ replacing .incbin "baserom.gba", 0xF9B34, 0x24
.4byte gUnknown_80F9B14

.global gUnknown_80F9B38
gUnknown_80F9B38: @ 80F9B38
.string "{ARG_POKEMON_0}'s Sp. Def. went up $d4!\0"
.align 2, 0

.global gUnknown_80F9B58
gUnknown_80F9B58: @ 80F9B58
@ replacing .incbin "baserom.gba", 0xF9B58, 0x1C
.4byte gUnknown_80F9B38

.global gUnknown_80F9B5C
gUnknown_80F9B5C: @ 80F9B5C
.string "{ARG_POKEMON_0} didn't level up.\0"
.align 2, 0

.global gUnknown_80F9B74
gUnknown_80F9B74: @ 80F9B74
@ replacing .incbin "baserom.gba", 0xF9B74, 0x20
.4byte gUnknown_80F9B5C

.global gUnknown_80F9B78
gUnknown_80F9B78: @ 80F9B78
.string "{ARG_POKEMON_0} didn't level down.\0"
.align 2, 0

.global gUnknown_80F9B94
gUnknown_80F9B94: @ 80F9B94
@ replacing .incbin "baserom.gba", 0xF9B94, 0x1C
.4byte gUnknown_80F9B78

.global gUnknown_80F9B98
gUnknown_80F9B98: @ 80F9B98
.string "{ARG_POKEMON_0} became the leader!\0"
.align 2, 0

.global gUnknown_80F9BB0
gUnknown_80F9BB0: @ 80F9BB0
@ replacing .incbin "baserom.gba", 0xF9BB0, 0x28
.4byte gUnknown_80F9B98

.global gUnknown_80F9BB4
gUnknown_80F9BB4: @ 80F9BB4
.string "The leader couldn't be switched!\0"
.align 2, 0

.global gUnknown_80F9BD8
gUnknown_80F9BD8: @ 80F9BD8
@ replacing .incbin "baserom.gba", 0xF9BD8, 0x30
.4byte gUnknown_80F9BB4

.global gUnknown_80F9BDC
gUnknown_80F9BDC: @ 80F9BDC
.string "You haven't paid for the merchandise yet!\0"
.align 2, 0

.global gUnknown_80F9C08
gUnknown_80F9C08: @ 80F9C08
@ replacing .incbin "baserom.gba", 0xF9C08, 0x24
.4byte gUnknown_80F9BDC

.global gUnknown_80F9C0C
gUnknown_80F9C0C: @ 80F9C0C
.string "A thief can't switch leaders!\0"
.align 2, 0

.global gUnknown_80F9C2C
gUnknown_80F9C2C: @ 80F9C2C
@ replacing .incbin "baserom.gba", 0xF9C2C, 0x20
.4byte gUnknown_80F9C0C

.global gUnknown_80F9C30
gUnknown_80F9C30: @ 80F9C30
.string "...Something's stirring.\0"
.align 2, 0

.global gUnknown_80F9C4C
gUnknown_80F9C4C: @ 80F9C4C
@ replacing .incbin "baserom.gba", 0xF9C4C, 0x24
.4byte gUnknown_80F9C30

.global gUnknown_80F9C50
gUnknown_80F9C50: @ 80F9C50
.string "...Something's approaching.\0"
.align 2, 0

.global gUnknown_80F9C70
gUnknown_80F9C70: @ 80F9C70
@ replacing .incbin "baserom.gba", 0xF9C70, 0x1C
.4byte gUnknown_80F9C50

.global gUnknown_80F9C74
gUnknown_80F9C74: @ 80F9C74
.string "It's getting closer!\0"
.align 2, 0

.global gUnknown_80F9C8C
gUnknown_80F9C8C: @ 80F9C8C
@ replacing .incbin "baserom.gba", 0xF9C8C, 0x30
.4byte gUnknown_80F9C74

.global gUnknown_80F9C90
gUnknown_80F9C90: @ 80F9C90
.string "It's right nearby! It's gusting hard!\0"
.align 2, 0

.global gUnknown_80F9CBC
gUnknown_80F9CBC: @ 80F9CBC
@ replacing .incbin "baserom.gba", 0xF9CBC, 0x4
.4byte gUnknown_80F9C90

.global gUnknown_80F9CC0
gUnknown_80F9CC0: @ 80F9CC0
@ replacing .incbin "baserom.gba", 0xF9CC0, 0x2C
.4byte gUnknown_80F9CD8
.4byte gUnknown_80F9CC8

.global gUnknown_80F9CC8
gUnknown_80F9CC8: @ 80F9CC8
.string "{ARG_POKEMON_1} fainted!\0"
.align 2, 0

.global gUnknown_80F9CD8
gUnknown_80F9CD8: @ 80F9CD8
.string "{ARG_POKEMON_1} was defeated!\0"
.align 2, 0

.global gUnknown_80F9CEC
gUnknown_80F9CEC: @ 80F9CEC
@ replacing .incbin "baserom.gba", 0xF9CEC, 0x3C
.4byte gUnknown_80F9D0C
.4byte gUnknown_80F9CF4

.global gUnknown_80F9CF4
gUnknown_80F9CF4: @ 80F9CF4
.string "Oh, no! {ARG_POKEMON_1} fainted!\0"
.align 2, 0

.global gUnknown_80F9D0C
gUnknown_80F9D0C: @ 80F9D0C
.string "Oh, no! {ARG_POKEMON_1} was defeated!\0"
.align 2, 0

.global gUnknown_80F9D28
gUnknown_80F9D28: @ 80F9D28
@ replacing .incbin "baserom.gba", 0xF9D28, 0x5C
.4byte gUnknown_80F9D58
.4byte gUnknown_80F9D30

.global gUnknown_80F9D30
gUnknown_80F9D30: @ 80F9D30
.string "{ARG_POKEMON_1} fainted!\n"
.string "It left the rescue team!\0"
.align 2, 0

.global gUnknown_80F9D58
gUnknown_80F9D58: @ 80F9D58
.string "{ARG_POKEMON_1} was defeated!\n"
.string "It left the rescue team!\0"
.align 2, 0

.global gUnknown_80F9D84
gUnknown_80F9D84: @ 80F9D84
@ replacing .incbin "baserom.gba", 0xF9D84, 0x8
.4byte gUnknown_80F9D0C
.4byte gUnknown_80F9CF4

.global gUnknown_80F9D8C
gUnknown_80F9D8C: @ 80F9D8C
@ replacing .incbin "baserom.gba", 0xF9D8C, 0x20
.4byte gUnknown_80F9D94
.4byte gUnknown_80F9CF4

.global gUnknown_80F9D94
gUnknown_80F9D94: @ 80F9D94
.string "{ARG_POKEMON_1} went back for now!\0"
.align 2, 0

.global gUnknown_80F9DAC
gUnknown_80F9DAC: @ 80F9DAC
@ replacing .incbin "baserom.gba", 0xF9DAC, 0x44
.4byte gUnknown_80F9DD0
.4byte gUnknown_80F9DB4

.global gUnknown_80F9DB4
gUnknown_80F9DB4: @ 80F9DB4
.string "Your client {ARG_POKEMON_1} fainted!\0"
.align 2, 0

.global gUnknown_80F9DD0
gUnknown_80F9DD0: @ 80F9DD0
.string "Your client {ARG_POKEMON_1} was defeated!\0"
.align 2, 0

.global gUnknown_80F9DF0
gUnknown_80F9DF0: @ 80F9DF0
@ replacing .incbin "baserom.gba", 0xF9DF0, 0x54
.4byte gUnknown_80F9E1C
.4byte gUnknown_80F9DF8

.global gUnknown_80F9DF8
gUnknown_80F9DF8: @ 80F9DF8
.string "{ARG_POKEMON_1} fainted while awaiting\n"
.string "rescue!\0"
.align 2, 0

.global gUnknown_80F9E1C
gUnknown_80F9E1C: @ 80F9E1C
.string "{ARG_POKEMON_1} was defeated while awaiting\n"
.string "rescue!\0"
.align 2, 0

.global gUnknown_80F9E44
gUnknown_80F9E44: @ 80F9E44
@ replacing .incbin "baserom.gba", 0xF9E44, 0x20
.4byte gUnknown_80F9CC8

.global gUnknown_80F9E48
gUnknown_80F9E48: @ 80F9E48
.string "{ARG_POKEMON_0} gained {ARG_VALUE_0} Exp. Points!\0"
.align 2, 0

.global gUnknown_80F9E64
gUnknown_80F9E64: @ 80F9E64
@ replacing .incbin "baserom.gba", 0xF9E64, 0x1C
.4byte gUnknown_80F9E48

.global gUnknown_80F9E68
gUnknown_80F9E68: @ 80F9E68
.string "{ARG_POKEMON_0} grew to Level {ARG_VALUE_0}!\0"
.align 2, 0

.global gUnknown_80F9E80
gUnknown_80F9E80: @ 80F9E80
@ replacing .incbin "baserom.gba", 0xF9E80, 0x48
.4byte gUnknown_80F9E68

.global gUnknown_80F9E84
gUnknown_80F9E84: @ 80F9E84
.string "{ARG_POKEMON_0}'s level remained unchanged.\0"
.align 2, 0
.4byte gUnknown_80F9E84

.global gUnknown_80F9EAC
gUnknown_80F9EAC: @ 80F9EAC
.string "{ARG_POKEMON_0} dropped to Level {ARG_VALUE_0}!\0"
.align 2, 0

.global gUnknown_80F9EC8
gUnknown_80F9EC8: @ 80F9EC8
@ replacing .incbin "baserom.gba", 0xF9EC8, 0x24
.4byte gUnknown_80F9EAC

.global gUnknown_80F9ECC
gUnknown_80F9ECC: @ 80F9ECC
.string "{ARG_POKEMON_0}'s level didn't go down.\0"
.align 2, 0

.global gUnknown_80F9EEC
gUnknown_80F9EEC: @ 80F9EEC
@ replacing .incbin "baserom.gba", 0xF9EEC, 0x18
.4byte gUnknown_80F9ECC

.global gUnknown_80F9EF0
gUnknown_80F9EF0: @ 80F9EF0
.string "{ARG_POKEMON_0} learned {ARG_MOVE_ITEM_0}!\0"
.align 2, 0

.global gUnknown_80F9F04
gUnknown_80F9F04: @ 80F9F04
@ replacing .incbin "baserom.gba", 0xF9F04, 0x28
.4byte gUnknown_80F9EF0

.global gUnknown_80F9F08
gUnknown_80F9F08: @ 80F9F08
.string "{ARG_POKEMON_0} didn't learn the new move.\0"
.align 2, 0

.global gUnknown_80F9F2C
gUnknown_80F9F2C: @ 80F9F2C
@ replacing .incbin "baserom.gba", 0xF9F2C, 0x78
.4byte gUnknown_80F9F08

.global gUnknown_80F9F30
gUnknown_80F9F30: @ 80F9F30
.string "This Pokémon learned a new move,\n"
.string "so it must forget an old one. Moves can\n"
.string "be relearned at the Gulpin Link Shop.\0"
.align 2, 0

.global gUnknown_80F9FA4
gUnknown_80F9FA4: @ 80F9FA4
@ replacing .incbin "baserom.gba", 0xF9FA4, 0x44
.4byte gUnknown_80F9F30

.global gUnknown_80F9FA8
gUnknown_80F9FA8: @ 80F9FA8
.string "Yes! {ARG_POKEMON_0} wants to join the team!\n"
.string "Accept {ARG_POKEMON_0} as a team member?\0"
.align 2, 0

.global gUnknown_80F9FE8
gUnknown_80F9FE8: @ 80F9FE8
@ replacing .incbin "baserom.gba", 0xF9FE8, 0x1C
.4byte gUnknown_80F9FA8
.4byte gUnknown_80F7F20

.global gUnknown_80F9FF0
gUnknown_80F9FF0: @ 80F9FF0
.string "{ARG_POKEMON_0} went away...\0"
.align 2, 0

.global gUnknown_80FA004
gUnknown_80FA004: @ 80FA004
@ replacing .incbin "baserom.gba", 0xFA004, 0x2C
.4byte gUnknown_80F9FF0

.global gUnknown_80FA008
gUnknown_80FA008: @ 80FA008
.string "The Pokémon couldn't join the team...\0"
.align 2, 0

.global gUnknown_80FA030
gUnknown_80FA030: @ 80FA030
@ replacing .incbin "baserom.gba", 0xFA030, 0x28
.4byte gUnknown_80FA008

.global gUnknown_80FA034
gUnknown_80FA034: @ 80FA034
.string "But it couldn't join the team.\0"
.align 2, 0

.global gUnknown_80FA058
gUnknown_80FA058: @ 80FA058
@ replacing .incbin "baserom.gba", 0xFA058, 0x38
.4byte gUnknown_80FA034

.global gUnknown_80FA05C
gUnknown_80FA05C: @ 80FA05C
.string "A new member joined the team!\n"
.string "Give it a nickname?\0"
.align 2, 0

.global gUnknown_80FA090
gUnknown_80FA090: @ 80FA090
@ replacing .incbin "baserom.gba", 0xFA090, 0x38
.4byte gUnknown_80FA05C

.global gUnknown_80FA094
gUnknown_80FA094: @ 80FA094
.string "Please give your new team member\n"
.string "a proper nickname!\0"
.align 2, 0

.global gUnknown_80FA0C8
gUnknown_80FA0C8: @ 80FA0C8
@ replacing .incbin "baserom.gba", 0xFA0C8, 0x28
.4byte gUnknown_80FA094

.global gUnknown_80FA0CC
gUnknown_80FA0CC: @ 80FA0CC
.string "{ARG_POKEMON_0} joined $t to\n"
.string "go on adventures!\0"
.align 2, 0

.global gUnknown_80FA0F0
gUnknown_80FA0F0: @ 80FA0F0
@ replacing .incbin "baserom.gba", 0xFA0F0, 0x30
.4byte gUnknown_80FA0CC

.global gUnknown_80FA0F4
gUnknown_80FA0F4: @ 80FA0F4
.string "{ARG_POKEMON_0} gained access to\n"
.string "the Friend Area {ARG_FRIEND_AREA}.\0"
.align 2, 0

.global gUnknown_80FA120
gUnknown_80FA120: @ 80FA120
@ replacing .incbin "baserom.gba", 0xFA120, 0x4
.4byte gUnknown_80FA0F4

.global gUnknown_80FA124
gUnknown_80FA124: @ 80FA124
@ replacing .incbin "baserom.gba", 0xFA124, 0x13C
.4byte gUnknown_80FA1AC
.4byte gUnknown_80FA18C
.4byte gUnknown_80FA170
.4byte gUnknown_80FA154
.4byte gUnknown_80FA138

.global gUnknown_80FA138
gUnknown_80FA138: @ 80FA138
.string "{ARG_POKEMON_0}'s at quadruple speed!\0"
.align 2, 0

.global gUnknown_80FA154
gUnknown_80FA154: @ 80FA154
.string "{ARG_POKEMON_0}'s at triple speed!\0"
.align 2, 0

.global gUnknown_80FA170
gUnknown_80FA170: @ 80FA170
.string "{ARG_POKEMON_0}'s at double speed!\0"
.align 2, 0

.global gUnknown_80FA18C
gUnknown_80FA18C: @ 80FA18C
.string "{ARG_POKEMON_0} returned to normal speed!\0"
.align 2, 0

.global gUnknown_80FA1AC
gUnknown_80FA1AC: @ 80FA1AC
.string "{ARG_POKEMON_0} was slowed!\0"
.align 2, 0

.global gUnknown_80FA1BC
gUnknown_80FA1BC: @ 80FA1BC
.string "The Rescue Team Badge\n"
.string "shone on {ARG_POKEMON_1}!\n"
.string "{ARG_POKEMON_1} gained a magical power!\n"
.string "{ARG_POKEMON_1}: Thank you!\n"
.string "Please come see me at the Pelipper\n"
.string "Post Office later.\n"
.string "{ARG_POKEMON_1} escaped from the dungeon!\0"
.align 2, 0

.global gUnknown_80FA260
gUnknown_80FA260: @ 80FA260
@ replacing .incbin "baserom.gba", 0xFA260, 0x50
.4byte gUnknown_80FA1BC

.global gUnknown_80FA264
gUnknown_80FA264: @ 80FA264
.string "{ARG_POKEMON_1} happily accepted the item!\n"
.string "\n\n"
.string "{ARG_POKEMON_1}: Thank you!\n"
.string "\n\n"
.string "{ARG_POKEMON_1} left the dungeon!\n"
.string "\n\0"
.align 2, 0

.global gUnknown_80FA2B0
gUnknown_80FA2B0: @ 80FA2B0
@ replacing .incbin "baserom.gba", 0xFA2B0, 0x40
.4byte gUnknown_80FA264

.global gUnknown_80FA2B4
gUnknown_80FA2B4: @ 80FA2B4
.string "Yes! {ARG_POKEMON_1} was found!\n"
.string "Use the Rescue Team Badge to save\n"
.string "{ARG_POKEMON_1}?\0"
.align 2, 0

.global gUnknown_80FA2F0
gUnknown_80FA2F0: @ 80FA2F0
@ replacing .incbin "baserom.gba", 0xFA2F0, 0x3C
.4byte gUnknown_80FA2B4

.global gUnknown_80FA2F4
gUnknown_80FA2F4: @ 80FA2F4
.string "Yes! {ARG_POKEMON_1} was found!\n"
.string "Deliver the requested item to\n"
.string "{ARG_POKEMON_1}?\0"
.align 2, 0

.global gUnknown_80FA32C
gUnknown_80FA32C: @ 80FA32C
@ replacing .incbin "baserom.gba", 0xFA32C, 0x40
.4byte gUnknown_80FA2F4

.global gUnknown_80FA330
gUnknown_80FA330: @ 80FA330
.string "A mission has been completed!\n"
.string "Would you like to leave now?\0"
.align 2, 0

.global gUnknown_80FA36C
gUnknown_80FA36C: @ 80FA36C
@ replacing .incbin "baserom.gba", 0xFA36C, 0x4
.4byte gUnknown_80FA330

.global gUnknown_80FA370
gUnknown_80FA370: @ 80FA370
@ replacing .incbin "baserom.gba", 0xFA370, 0x24
.4byte gUnknown_80FA330

.global gUnknown_80FA374
gUnknown_80FA374: @ 80FA374
.string "Do you really want to leave?\0"
.align 2, 0

.global gUnknown_80FA394
gUnknown_80FA394: @ 80FA394
@ replacing .incbin "baserom.gba", 0xFA394, 0x24
.4byte gUnknown_80FA374

.global gUnknown_80FA398
gUnknown_80FA398: @ 80FA398
.string "Continue with your adventure?\0"
.align 2, 0

.global gUnknown_80FA3B8
gUnknown_80FA3B8: @ 80FA3B8
@ replacing .incbin "baserom.gba", 0xFA3B8, 0x50
.4byte gUnknown_80FA398

.global gUnknown_80FA3BC
gUnknown_80FA3BC: @ 80FA3BC
.string "You're holding a delivery item.\n"
.string "Return to the base without continuing?\0"
.align 2, 0

.global gUnknown_80FA408
gUnknown_80FA408: @ 80FA408
@ replacing .incbin "baserom.gba", 0xFA408, 0x40
.4byte gUnknown_80FA3BC

.global gUnknown_80FA40C
gUnknown_80FA40C: @ 80FA40C
.string "The {ARG_MOVE_ITEM_0} isn't in the Toolbox.\n"
.string "It couldn't be delivered.\0"
.align 2, 0

.global gUnknown_80FA448
gUnknown_80FA448: @ 80FA448
@ replacing .incbin "baserom.gba", 0xFA448, 0x1C
.4byte gUnknown_80FA40C

.global gUnknown_80FA44C
gUnknown_80FA44C: @ 80FA44C
.string "{ARG_POKEMON_1} can't talk now.\0"
.align 2, 0

.global gUnknown_80FA464
gUnknown_80FA464: @ 80FA464
@ replacing .incbin "baserom.gba", 0xFA464, 0x70
.4byte gUnknown_80FA44C

.global gUnknown_80FA468
gUnknown_80FA468: @ 80FA468
.string "Yes! {ARG_POKEMON_2} was successfully\n"
.string "escorted!\n"
.string "{ARG_POKEMON_2} is delighted!\n"
.string "{ARG_POKEMON_2}: Thank you!\n"
.string "\n\n"
.string "{ARG_POKEMON_2}'s twosome left the dungeon!\n"
.string "\n\0"
.align 2, 0

.global gUnknown_80FA4D4
gUnknown_80FA4D4: @ 80FA4D4
@ replacing .incbin "baserom.gba", 0xFA4D4, 0x4
.4byte gUnknown_80FA468

.global gUnknown_80FA4D8
gUnknown_80FA4D8: @ 80FA4D8
@ replacing .incbin "baserom.gba", 0xFA4D8, 0x28
.4byte gUnknown_80FA330

.global gUnknown_80FA4DC
gUnknown_80FA4DC: @ 80FA4DC
.string "{ARG_POKEMON_2} doesn't seem to be around.\0"
.align 2, 0

.global gUnknown_80FA500
gUnknown_80FA500: @ 80FA500
@ replacing .incbin "baserom.gba", 0xFA500, 0x2C
.4byte gUnknown_80FA4DC

.global gUnknown_80FA504
gUnknown_80FA504: @ 80FA504
.string "The mission can no longer be completed!\0"
.align 2, 0

.global gUnknown_80FA52C
gUnknown_80FA52C: @ 80FA52C
@ replacing .incbin "baserom.gba", 0xFA52C, 0x4
.4byte gUnknown_80FA504

.global gUnknown_80FA530
gUnknown_80FA530: @ 80FA530
@ replacing .incbin "baserom.gba", 0xFA530, 0x1C
.4byte gUnknown_80FA44C

.global gUnknown_80FA534
gUnknown_80FA534: @ 80FA534
.string "{ARG_POKEMON_2} can't talk now.\0"
.align 2, 0

.global gUnknown_80FA54C
gUnknown_80FA54C: @ 80FA54C
@ replacing .incbin "baserom.gba", 0xFA54C, 0x34
.4byte gUnknown_80FA534

.global gUnknown_80FA550
gUnknown_80FA550: @ 80FA550
.string "Deoxys was a mirage!\n"
.string "A set of stairs appeared!\0"
.align 2, 0

.global gUnknown_80FA580
gUnknown_80FA580: @ 80FA580
@ replacing .incbin "baserom.gba", 0xFA580, 0x34
.4byte gUnknown_80FA550

.global gUnknown_80FA584
gUnknown_80FA584: @ 80FA584
.string "It's impossible to go down the stairs\n"
.string "now!\0"
.align 2, 0

.global gUnknown_80FA5B4
gUnknown_80FA5B4: @ 80FA5B4
@ replacing .incbin "baserom.gba", 0xFA5B4, 0x40
.4byte gUnknown_80FA584
.4byte gUnknown_80F7F20

.global gUnknown_80FA5BC
gUnknown_80FA5BC: @ 80FA5BC
.string "No Pokémon will join the rescue team\n"
.string "in this dungeon.\0"
.align 2, 0

.global gUnknown_80FA5F4
gUnknown_80FA5F4: @ 80FA5F4
.4byte gUnknown_80FA5BC

.global gUnknown_80FA5F8
gUnknown_80FA5F8: @ 80FA5F8
.string "There are no potential recruits.\0"
.align 2,0

.global gUnknown_80FA61C
gUnknown_80FA61C: @ 80FA61C
@ replacing .incbin "baserom.gba", 0xFA61C, 0x1C
.4byte gUnknown_80FA5F8

.global gUnknown_80FA620
gUnknown_80FA620: @ 80FA620
.string "{ARG_POKEMON_0}'s Reflect faded.\0"
.align 2, 0

.global gUnknown_80FA638
gUnknown_80FA638: @ 80FA638
@ replacing .incbin "baserom.gba", 0xFA638, 0x20
.4byte gUnknown_80FA620

.global gUnknown_80FA63C
gUnknown_80FA63C: @ 80FA63C
.string "{ARG_POKEMON_0}'s Light Screen faded.\0"
.align 2, 0

.global gUnknown_80FA658
gUnknown_80FA658: @ 80FA658
@ replacing .incbin "baserom.gba", 0xFA658, 0x24
.4byte gUnknown_80FA63C

.global gUnknown_80FA65C
gUnknown_80FA65C: @ 80FA65C
.string "{ARG_POKEMON_0}'s Counter effect faded.\0"
.align 2, 0

.global gUnknown_80FA67C
gUnknown_80FA67C: @ 80FA67C
@ replacing .incbin "baserom.gba", 0xFA67C, 0x20
.4byte gUnknown_80FA65C

.global gUnknown_80FA680
gUnknown_80FA680: @ 80FA680
.string "{ARG_POKEMON_0}'s Safeguard faded.\0"
.align 2, 0

.global gUnknown_80FA69C
gUnknown_80FA69C: @ 80FA69C
@ replacing .incbin "baserom.gba", 0xFA69C, 0x20
.4byte gUnknown_80FA680

.global gUnknown_80FA6A0
gUnknown_80FA6A0: @ 80FA6A0
.string "{ARG_POKEMON_0}'s Magic Coat faded.\0"
.align 2, 0

.global gUnknown_80FA6BC
gUnknown_80FA6BC: @ 80FA6BC
@ replacing .incbin "baserom.gba", 0xFA6BC, 0x18
.4byte gUnknown_80FA6A0

.global gUnknown_80FA6C0
gUnknown_80FA6C0: @ 80FA6C0
.string "{ARG_POKEMON_0}'s Wish faded.\0"
.align 2, 0

.global gUnknown_80FA6D4
gUnknown_80FA6D4: @ 80FA6D4
@ replacing .incbin "baserom.gba", 0xFA6D4, 0x14
.4byte gUnknown_80FA6C0

.global gUnknown_80FA6D8
gUnknown_80FA6D8: @ 80FA6D8
.string "{ARG_POKEMON_0} woke up!\0"
.align 2, 0

.global gUnknown_80FA6E8
gUnknown_80FA6E8: @ 80FA6E8
@ replacing .incbin "baserom.gba", 0xFA6E8, 0x20
.4byte gUnknown_80FA6D8

.global gUnknown_80FA6EC
gUnknown_80FA6EC: @ 80FA6EC
.string "{ARG_POKEMON_0} is no longer sleepless!\0"
.align 2, 0

.global gUnknown_80FA708
gUnknown_80FA708: @ 80FA708
@ replacing .incbin "baserom.gba", 0xFA708, 0x4
.4byte gUnknown_80FA6EC

.global gUnknown_80FA70C
gUnknown_80FA70C: @ 80FA70C
@ replacing .incbin "baserom.gba", 0xFA70C, 0x4
.4byte gUnknown_80FA6D8

.global gUnknown_80FA710
gUnknown_80FA710: @ 80FA710
@ replacing .incbin "baserom.gba", 0xFA710, 0x24
.4byte gUnknown_80FA6D8

.global gUnknown_80FA714
gUnknown_80FA714: @ 80FA714
.string "{ARG_POKEMON_0} got over its drowsiness!\0"
.align 2, 0

.global gUnknown_80FA734
gUnknown_80FA734: @ 80FA734
@ replacing .incbin "baserom.gba", 0xFA734, 0x24
.4byte gUnknown_80FA714

.global gUnknown_80FA738
gUnknown_80FA738: @ 80FA738
.string "Water Sport's effect faded.\0"
.align 2, 0

.global gUnknown_80FA758
gUnknown_80FA758: @ 80FA758
@ replacing .incbin "baserom.gba", 0xFA758, 0x20
.4byte gUnknown_80FA738

.global gUnknown_80FA75C
gUnknown_80FA75C: @ 80FA75C
.string "Mud Sport's effect faded.\0"
.align 2, 0

.global gUnknown_80FA778
gUnknown_80FA778: @ 80FA778
@ replacing .incbin "baserom.gba", 0xFA778, 0x24
.4byte gUnknown_80FA75C

.global gUnknown_80FA77C
gUnknown_80FA77C: @ 80FA77C
.string "{ARG_POKEMON_0}'s Leech Seed wore off.\0"
.align 2, 0

.global gUnknown_80FA79C
gUnknown_80FA79C: @ 80FA79C
@ replacing .incbin "baserom.gba", 0xFA79C, 0x20
.4byte gUnknown_80FA77C

.global gUnknown_80FA7A0
gUnknown_80FA7A0: @ 80FA7A0
.string "{ARG_POKEMON_0} is no longer cursed!\0"
.align 2, 0

.global gUnknown_80FA7BC
gUnknown_80FA7BC: @ 80FA7BC
@ replacing .incbin "baserom.gba", 0xFA7BC, 0x20
.4byte gUnknown_80FA7A0

.global gUnknown_80FA7C0
gUnknown_80FA7C0: @ 80FA7C0
.string "{ARG_POKEMON_0}'s Snatch wore off!\0"
.align 2, 0

.global gUnknown_80FA7DC
gUnknown_80FA7DC: @ 80FA7DC
@ replacing .incbin "baserom.gba", 0xFA7DC, 0x24
.4byte gUnknown_80FA7C0

.global gUnknown_80FA7E0
gUnknown_80FA7E0: @ 80FA7E0
.string "{ARG_POKEMON_0} recovered from confusion!\0"
.align 2, 0

.global gUnknown_80FA800
gUnknown_80FA800: @ 80FA800
@ replacing .incbin "baserom.gba", 0xFA800, 0x1C
.4byte gUnknown_80FA7E0

.global gUnknown_80FA804
gUnknown_80FA804: @ 80FA804
.string "{ARG_POKEMON_0} regained mobility!\0"
.align 2, 0

.global gUnknown_80FA81C
gUnknown_80FA81C: @ 80FA81C
@ replacing .incbin "baserom.gba", 0xFA81C, 0x4
.4byte gUnknown_80FA804

.global gUnknown_80FA820
gUnknown_80FA820: @ 80FA820
@ replacing .incbin "baserom.gba", 0xFA820, 0x4
.4byte gUnknown_80FA804

.global gUnknown_80FA824
gUnknown_80FA824: @ 80FA824
@ replacing .incbin "baserom.gba", 0xFA824, 0x20
.4byte gUnknown_80FA804

.global gUnknown_80FA828
gUnknown_80FA828: @ 80FA828
.string "{ARG_POKEMON_0}'s Ingrain wore off!\0"
.align 2, 0

.global gUnknown_80FA844
gUnknown_80FA844: @ 80FA844
@ replacing .incbin "baserom.gba", 0xFA844, 0x24
.4byte gUnknown_80FA828

.global gUnknown_80FA848
gUnknown_80FA848: @ 80FA848
.string "{ARG_POKEMON_0} recovered from paralysis!\0"
.align 2, 0

.global gUnknown_80FA868
gUnknown_80FA868: @ 80FA868
@ replacing .incbin "baserom.gba", 0xFA868, 0x20
.4byte gUnknown_80FA848

.global gUnknown_80FA86C
gUnknown_80FA86C: @ 80FA86C
.string "{ARG_POKEMON_0} recovered from a burn!\0"
.align 2, 0

.global gUnknown_80FA888
gUnknown_80FA888: @ 80FA888
@ replacing .incbin "baserom.gba", 0xFA888, 0x20
.4byte gUnknown_80FA86C

.global gUnknown_80FA88C
gUnknown_80FA88C: @ 80FA88C
.string "{ARG_POKEMON_0} recovered from poison!\0"
.align 2, 0

.global gUnknown_80FA8A8
gUnknown_80FA8A8: @ 80FA8A8
@ replacing .incbin "baserom.gba", 0xFA8A8, 0x14
.4byte gUnknown_80FA88C

.global gUnknown_80FA8AC
gUnknown_80FA8AC: @ 80FA8AC
.string "{ARG_POKEMON_0} thawed out!\0"
.align 2, 0

.global gUnknown_80FA8BC
gUnknown_80FA8BC: @ 80FA8BC
@ replacing .incbin "baserom.gba", 0xFA8BC, 0x24
.4byte gUnknown_80FA8AC

.global gUnknown_80FA8C0
gUnknown_80FA8C0: @ 80FA8C0
.string "{ARG_POKEMON_0} lost its Sure Shot status!\0"
.align 2, 0

.global gUnknown_80FA8E0
gUnknown_80FA8E0: @ 80FA8E0
@ replacing .incbin "baserom.gba", 0xFA8E0, 0x2C
.4byte gUnknown_80FA8C0

.global gUnknown_80FA8E4
gUnknown_80FA8E4: @ 80FA8E4
.string "{ARG_POKEMON_0} recovered from its\n"
.string "Whiffer status!\0"
.align 2, 0

.global gUnknown_80FA90C
gUnknown_80FA90C: @ 80FA90C
@ replacing .incbin "baserom.gba", 0xFA90C, 0x28
.4byte gUnknown_80FA8E4

.global gUnknown_80FA910
gUnknown_80FA910: @ 80FA910
.string "{ARG_POKEMON_0}'s damage returned to normal!\0"
.align 2, 0

.global gUnknown_80FA934
gUnknown_80FA934: @ 80FA934
@ replacing .incbin "baserom.gba", 0xFA934, 0x28
.4byte gUnknown_80FA910

.global gUnknown_80FA938
gUnknown_80FA938: @ 80FA938
.string "{ARG_POKEMON_0} lost its Focus Energy status!\0"
.align 2, 0

.global gUnknown_80FA95C
gUnknown_80FA95C: @ 80FA95C
@ replacing .incbin "baserom.gba", 0xFA95C, 0x20
.4byte gUnknown_80FA938

.global gUnknown_80FA960
gUnknown_80FA960: @ 80FA960
.string "{ARG_POKEMON_0} is no longer cowering!\0"
.align 2, 0

.global gUnknown_80FA97C
gUnknown_80FA97C: @ 80FA97C
@ replacing .incbin "baserom.gba", 0xFA97C, 0x24
.4byte gUnknown_80FA960

.global gUnknown_80FA980
gUnknown_80FA980: @ 80FA980
.string "The decoy Pokémon went away!\0"
.align 2, 0

.global gUnknown_80FA9A0
gUnknown_80FA9A0: @ 80FA9A0
@ replacing .incbin "baserom.gba", 0xFA9A0, 0x20
.4byte gUnknown_80FA980

.global gUnknown_80FA9A4
gUnknown_80FA9A4: @ 80FA9A4
.string "{ARG_POKEMON_0}'s Protect wore off!\0"
.align 2, 0

.global gUnknown_80FA9C0
gUnknown_80FA9C0: @ 80FA9C0
@ replacing .incbin "baserom.gba", 0xFA9C0, 0x1C
.4byte gUnknown_80FA9A4

.global gUnknown_80FA9C4
gUnknown_80FA9C4: @ 80FA9C4
.string "{ARG_POKEMON_0}'s Taunt wore off!\0"
.align 2, 0

.global gUnknown_80FA9DC
gUnknown_80FA9DC: @ 80FA9DC
@ replacing .incbin "baserom.gba", 0xFA9DC, 0x18
.4byte gUnknown_80FA9C4

.global gUnknown_80FA9E0
gUnknown_80FA9E0: @ 80FA9E0
.string "{ARG_POKEMON_0} became visible!\0"
.align 2, 0

.global gUnknown_80FA9F4
gUnknown_80FA9F4: @ 80FA9F4
@ replacing .incbin "baserom.gba", 0xFA9F4, 0x18
.4byte gUnknown_80FA9E0

.global gUnknown_80FA9F8
gUnknown_80FA9F8: @ 80FA9F8
.string "{ARG_POKEMON_0} regained sight!\0"
.align 2, 0

.global gUnknown_80FAA0C
gUnknown_80FAA0C: @ 80FAA0C
@ replacing .incbin "baserom.gba", 0xFAA0C, 0x20
.4byte gUnknown_80FA9F8

.global gUnknown_80FAA10
gUnknown_80FAA10: @ 80FAA10
.string "{ARG_POKEMON_0} can see normally again!\0"
.align 2, 0

.global gUnknown_80FAA2C
gUnknown_80FAA2C: @ 80FAA2C
@ replacing .incbin "baserom.gba", 0xFAA2C, 0x1C
.4byte gUnknown_80FAA10

.global gUnknown_80FAA30
gUnknown_80FAA30: @ 80FAA30
.string "{ARG_POKEMON_0} returned to normal!\0"
.align 2, 0

.global gUnknown_80FAA48
gUnknown_80FAA48: @ 80FAA48
@ replacing .incbin "baserom.gba", 0xFAA48, 0x20
.4byte gUnknown_80FAA30

.global gUnknown_80FAA4C
gUnknown_80FAA4C: @ 80FAA4C
.string "{ARG_POKEMON_0}'s Mirror Coat faded!\0"
.align 2, 0

.global gUnknown_80FAA68
gUnknown_80FAA68: @ 80FAA68
@ replacing .incbin "baserom.gba", 0xFAA68, 0x24
.4byte gUnknown_80FAA4C

.global gUnknown_80FAA6C
gUnknown_80FAA6C: @ 80FAA6C
.string "{ARG_POKEMON_0} gave up on Destiny Bond!\0"
.align 2, 0

.global gUnknown_80FAA8C
gUnknown_80FAA8C: @ 80FAA8C
@ replacing .incbin "baserom.gba", 0xFAA8C, 0x20
.4byte gUnknown_80FAA6C

.global gUnknown_80FAA90
gUnknown_80FAA90: @ 80FAA90
.string "{ARG_POKEMON_0} recovered from Encore!\0"
.align 2, 0

.global gUnknown_80FAAAC
gUnknown_80FAAAC: @ 80FAAAC
@ replacing .incbin "baserom.gba", 0xFAAAC, 0x1C
.4byte gUnknown_80FAA90

.global gMonStoppedEnduringMessage
gMonStoppedEnduringMessage: @ 80FAAB0
.string "{ARG_POKEMON_0} stopped enduring!\0"
.align 2, 0

.global gPtrMonStoppedEnduringMessage
gPtrMonStoppedEnduringMessage: @ 80FAAC8
.4byte gMonStoppedEnduringMessage

.global gMonMirrorMoveFadedMessage
gMonMirrorMoveFadedMessage: @ 80FAACC
.string "{ARG_POKEMON_0}'s Mirror Move faded!\0"
.align 2, 0

.global gPtrMonMirrorMoveFadedMessage
gPtrMonMirrorMoveFadedMessage: @ 80FAAE8
.4byte gMonMirrorMoveFadedMessage

.global gMonConversion2FailedMessage
gMonConversion2FailedMessage: @ 80FAAEC
.string "{ARG_POKEMON_0}'s Conversion 2 faded!\0"
.align 2, 0

.global gPtrMonConversion2FailedMessage
gPtrMonConversion2FailedMessage: @ 80FAB08
.4byte gMonConversion2FailedMessage

.global gMonGaveUpVitalThrowMessage
gMonGaveUpVitalThrowMessage: @ 80FAB0C
.string "{ARG_POKEMON_0} gave up on Vital Throw!\0"
.align 2, 0

.global gPtrMonGaveUpVitalThrowMessage
gPtrMonGaveUpVitalThrowMessage: @ 80FAB28
.4byte gMonGaveUpVitalThrowMessage

.global gUnknown_80FAB2C
gUnknown_80FAB2C: @ 80FAB2C
.string "{ARG_POKEMON_0}'s Mist faded!\0"
.align 2, 0

.global gUnknown_80FAB40
gUnknown_80FAB40: @ 80FAB40
@ replacing .incbin "baserom.gba", 0xFAB40, 0x2C
.4byte gUnknown_80FAB2C

.global gUnknown_80FAB44
gUnknown_80FAB44: @ 80FAB44
.string "{ARG_POKEMON_0}'s appearance returned to\n"
.string "normal!\0"
.align 2, 0

.global gUnknown_80FAB6C
gUnknown_80FAB6C: @ 80FAB6C
@ replacing .incbin "baserom.gba", 0xFAB6C, 0x24
.4byte gUnknown_80FAB44

.global gUnknown_80FAB70
gUnknown_80FAB70: @ 80FAB70
.string "{ARG_POKEMON_0} got over its infatuation!\0"
.align 2, 0

.global gUnknown_80FAB90
gUnknown_80FAB90: @ 80FAB90
@ replacing .incbin "baserom.gba", 0xFAB90, 0x2C
.4byte gUnknown_80FAB70

.global gUnknown_80FAB94
gUnknown_80FAB94: @ 80FAB94
.string "{ARG_POKEMON_0} can't go through walls\n"
.string "anymore!\0"
.align 2, 0

.global gUnknown_80FABBC
gUnknown_80FABBC: @ 80FABBC
@ replacing .incbin "baserom.gba", 0xFABBC, 0x4
.4byte gUnknown_80FAB94

.global gUnknown_80FABC0
gUnknown_80FABC0: @ 80FABC0
@ replacing .incbin "baserom.gba", 0xFABC0, 0x18
.4byte gUnknown_80FAA30

.global gUnknown_80FABC4
gUnknown_80FABC4: @ 80FABC4
.string "{ARG_POKEMON_0}'s rage faded!\0"
.align 2, 0

.global gUnknown_80FABD8
gUnknown_80FABD8: @ 80FABD8
@ replacing .incbin "baserom.gba", 0xFABD8, 0x20
.4byte gUnknown_80FABC4

.global gMonNoLongerPetrifiedMessage
gMonNoLongerPetrifiedMessage: @ 80FABDC
.string "{ARG_POKEMON_0} is no longer petrified!\0"
.align 2, 0

.global gPtrMonNoLongerPetrifiedMessage
gPtrMonNoLongerPetrifiedMessage: @ 80FABF8
.4byte gMonNoLongerPetrifiedMessage

.global gMonNoLongerCringingMessage
gMonNoLongerCringingMessage: @ 80FABFC
.string "{ARG_POKEMON_0} is no longer cringing!\0"
.align 2, 0

.global gPtrMonNoLongerCringingMessage
gPtrMonNoLongerCringingMessage: @ 80FAC18
.4byte gMonNoLongerCringingMessage

.global gUnknown_80FAC1C
gUnknown_80FAC1C: @ 80FAC1C
.string "{ARG_POKEMON_0} is no longer paused!\0"
.align 2, 0

.global gUnknown_80FAC38
gUnknown_80FAC38: @ 80FAC38
@ replacing .incbin "baserom.gba", 0xFAC38, 0x1C
.4byte gUnknown_80FAC1C

.global gUnknown_80FAC3C
gUnknown_80FAC3C: @ 80FAC3C
.string "{ARG_POKEMON_0} readies Razor Wind!\0"
.align 2, 0

.global gUnknown_80FAC54
gUnknown_80FAC54: @ 80FAC54
@ replacing .incbin "baserom.gba", 0xFAC54, 0x20
.4byte gUnknown_80FAC3C

.global gUnknown_80FAC58
gUnknown_80FAC58: @ 80FAC58
.string "{ARG_POKEMON_0} began storing energy!\0"
.align 2, 0

.global gUnknown_80FAC74
gUnknown_80FAC74: @ 80FAC74
@ replacing .incbin "baserom.gba", 0xFAC74, 0x14
.4byte gUnknown_80FAC58

.global gUnknown_80FAC78
gUnknown_80FAC78: @ 80FAC78
.string "{ARG_POKEMON_0} is enraged!\0"
.align 2, 0

.global gUnknown_80FAC88
gUnknown_80FAC88: @ 80FAC88
@ replacing .incbin "baserom.gba", 0xFAC88, 0x1C
.4byte gUnknown_80FAC78

.global gUnknown_80FAC8C
gUnknown_80FAC8C: @ 80FAC8C
.string "{ARG_POKEMON_0} is focusing energy!\0"
.align 2, 0

.global gUnknown_80FACA4
gUnknown_80FACA4: @ 80FACA4
@ replacing .incbin "baserom.gba", 0xFACA4, 0x20
.4byte gUnknown_80FAC8C

.global gUnknown_80FACA8
gUnknown_80FACA8: @ 80FACA8
.string "{ARG_POKEMON_0} is readying Sky Attack!\0"
.align 2, 0

.global gUnknown_80FACC4
gUnknown_80FACC4: @ 80FACC4
@ replacing .incbin "baserom.gba", 0xFACC4, 0x20
.4byte gUnknown_80FACA8

.global gUnknown_80FACC8
gUnknown_80FACC8: @ 80FACC8
.string "{ARG_POKEMON_0} is readying Solarbeam!\0"
.align 2, 0

.global gUnknown_80FACE4
gUnknown_80FACE4: @ 80FACE4
@ replacing .incbin "baserom.gba", 0xFACE4, 0x18
.4byte gUnknown_80FACC8

.global gUnknown_80FACE8
gUnknown_80FACE8: @ 80FACE8
.string "{ARG_POKEMON_0} flew up high!\0"
.align 2, 0

.global gUnknown_80FACFC
gUnknown_80FACFC: @ 80FACFC
@ replacing .incbin "baserom.gba", 0xFACFC, 0x14
.4byte gUnknown_80FACE8

.global gUnknown_80FAD00
gUnknown_80FAD00: @ 80FAD00
.string "{ARG_POKEMON_0} bounced up!\0"
.align 2, 0

.global gUnknown_80FAD10
gUnknown_80FAD10: @ 80FAD10
@ replacing .incbin "baserom.gba", 0xFAD10, 0x1C
.4byte gUnknown_80FAD00

.global gUnknown_80FAD14
gUnknown_80FAD14: @ 80FAD14
.string "{ARG_POKEMON_0} dove underwater!\0"
.align 2, 0

.global gUnknown_80FAD2C
gUnknown_80FAD2C: @ 80FAD2C
@ replacing .incbin "baserom.gba", 0xFAD2C, 0x20
.4byte gUnknown_80FAD14

.global gUnknown_80FAD30
gUnknown_80FAD30: @ 80FAD30
.string "{ARG_POKEMON_0} burrowed underground!\0"
.align 2, 0

.global gUnknown_80FAD4C
gUnknown_80FAD4C: @ 80FAD4C
@ replacing .incbin "baserom.gba", 0xFAD4C, 0x20
.4byte gUnknown_80FAD30

.global gUnknown_80FAD50
gUnknown_80FAD50: @ 80FAD50
.string "{ARG_POKEMON_0} began charging power!\0"
.align 2, 0

.global gUnknown_80FAD6C
gUnknown_80FAD6C: @ 80FAD6C
@ replacing .incbin "baserom.gba", 0xFAD6C, 0x20
.4byte gUnknown_80FAD50

.global gUnknown_80FAD70
gUnknown_80FAD70: @ 80FAD70
.string "Mud Sport came into effect!\0"
.align 2, 0

.global gUnknown_80FAD8C
gUnknown_80FAD8C: @ 80FAD8C
@ replacing .incbin "baserom.gba", 0xFAD8C, 0x24
.4byte gUnknown_80FAD70

.global gUnknown_80FAD90
gUnknown_80FAD90: @ 80FAD90
.string "Water Sport came into effect!\0"
.align 2, 0

.global gUnknown_80FADB0
gUnknown_80FADB0: @ 80FADB0
@ replacing .incbin "baserom.gba", 0xFADB0, 0x28
.4byte gUnknown_80FAD90

.global gUnknown_80FADB4
gUnknown_80FADB4: @ 80FADB4
.string "{ARG_POKEMON_1} used Flash Fire to absorb\n"
.string "fire!\0"
.align 2, 0

.global gUnknown_80FADD8
gUnknown_80FADD8: @ 80FADD8
@ replacing .incbin "baserom.gba", 0xFADD8, 0x28
.4byte gUnknown_80FADB4

.global gUnknown_80FADDC
gUnknown_80FADDC: @ 80FADDC
.string "Fire moves won't become stronger!\0"
.align 2, 0

.global gUnknown_80FAE00
gUnknown_80FAE00: @ 80FAE00
@ replacing .incbin "baserom.gba", 0xFAE00, 0x1C
.4byte gUnknown_80FADDC

.global gUnknown_80FAE04
gUnknown_80FAE04: @ 80FAE04
.string "{ARG_POKEMON_0} began using Wish!\0"
.align 2, 0

.global gUnknown_80FAE1C
gUnknown_80FAE1C: @ 80FAE1C
@ replacing .incbin "baserom.gba", 0xFAE1C, 0x20
.4byte gUnknown_80FAE04

.global gUnknown_80FAE20
gUnknown_80FAE20: @ 80FAE20
.string "{ARG_POKEMON_0} is already using Wish.\0"
.align 2, 0

.global gUnknown_80FAE3C
gUnknown_80FAE3C: @ 80FAE3C
@ replacing .incbin "baserom.gba", 0xFAE3C, 0x1C
.4byte gUnknown_80FAE20

.global gUnknown_80FAE40
gUnknown_80FAE40: @ 80FAE40
.string "{ARG_POKEMON_0} took a leech seed!\0"
.align 2, 0

.global gUnknown_80FAE58
gUnknown_80FAE58: @ 80FAE58
@ replacing .incbin "baserom.gba", 0xFAE58, 0x24
.4byte gUnknown_80FAE40

.global gUnknown_80FAE5C
gUnknown_80FAE5C: @ 80FAE5C
.string "{ARG_POKEMON_0} already has a leech seed!\0"
.align 2, 0

.global gUnknown_80FAE7C
gUnknown_80FAE7C: @ 80FAE7C
@ replacing .incbin "baserom.gba", 0xFAE7C, 0x24
.4byte gUnknown_80FAE5C

.global gUnknown_80FAE80
gUnknown_80FAE80: @ 80FAE80
.string "Item locations became evident!\0"
.align 2, 0

.global gUnknown_80FAEA0
gUnknown_80FAEA0: @ 80FAEA0
@ replacing .incbin "baserom.gba", 0xFAEA0, 0x28
.4byte gUnknown_80FAE80

.global gUnknown_80FAEA4
gUnknown_80FAEA4: @ 80FAEA4
.string "The stair location became clear!\0"
.align 2, 0

.global gUnknown_80FAEC8
gUnknown_80FAEC8: @ 80FAEC8
@ replacing .incbin "baserom.gba", 0xFAEC8, 0x28
.4byte gUnknown_80FAEA4

.global gUnknown_80FAECC
gUnknown_80FAECC: @ 80FAECC
.string "Item locations are already known.\0"
.align 2, 0

.global gUnknown_80FAEF0
gUnknown_80FAEF0: @ 80FAEF0
@ replacing .incbin "baserom.gba", 0xFAEF0, 0x2C
.4byte gUnknown_80FAECC

.global gUnknown_80FAEF4
gUnknown_80FAEF4: @ 80FAEF4
.string "The stair location is already known.\0"
.align 2, 0

.global gUnknown_80FAF1C
gUnknown_80FAF1C: @ 80FAF1C
@ replacing .incbin "baserom.gba", 0xFAF1C, 0x20
.4byte gUnknown_80FAEF4

.global gUnknown_80FAF20
gUnknown_80FAF20: @ 80FAF20
.string "There are no stairs here.\0"
.align 2, 0

.global gUnknown_80FAF3C
gUnknown_80FAF3C: @ 80FAF3C
@ replacing .incbin "baserom.gba", 0xFAF3C, 0x20
.4byte gUnknown_80FAF20

.global gUnknown_80FAF40
gUnknown_80FAF40: @ 80FAF40
.string "{ARG_POKEMON_0} put up its magic coat!\0"
.align 2, 0

.global gUnknown_80FAF5C
gUnknown_80FAF5C: @ 80FAF5C
@ replacing .incbin "baserom.gba", 0xFAF5C, 0x30
.4byte gUnknown_80FAF40

.global gUnknown_80FAF60
gUnknown_80FAF60: @ 80FAF60
.string "{ARG_POKEMON_0} is already cloaked in its\n"
.string "magic coat!\0"
.align 2, 0

.global gUnknown_80FAF8C
gUnknown_80FAF8C: @ 80FAF8C
@ replacing .incbin "baserom.gba", 0xFAF8C, 0x20
.4byte gUnknown_80FAF60

.global gUnknown_80FAF90
gUnknown_80FAF90: @ 80FAF90
.string "{ARG_POKEMON_0} can locate foes now!\0"
.align 2, 0

.global gUnknown_80FAFAC
gUnknown_80FAFAC: @ 80FAFAC
@ replacing .incbin "baserom.gba", 0xFAFAC, 0x24
.4byte gUnknown_80FAF90

.global gUnknown_80FAFB0
gUnknown_80FAFB0: @ 80FAFB0
.string "Foes can already be located!\0"
.align 2, 0

.global gUnknown_80FAFD0
gUnknown_80FAFD0: @ 80FAFD0
@ replacing .incbin "baserom.gba", 0xFAFD0, 0x20
.4byte gUnknown_80FAFB0

.global gUnknown_80FAFD4
gUnknown_80FAFD4: @ 80FAFD4
.string "{ARG_POKEMON_0} readies its Skull Bash!\0"
.align 2, 0

.global gUnknown_80FAFF0
gUnknown_80FAFF0: @ 80FAFF0
@ replacing .incbin "baserom.gba", 0xFAFF0, 0x14
.4byte gUnknown_80FAFD4

.global gUnknown_80FAFF4
gUnknown_80FAFF4: @ 80FAFF4
.string "{ARG_POKEMON_0} was cursed!\0"
.align 2, 0

.global gUnknown_80FB004
gUnknown_80FB004: @ 80FB004
@ replacing .incbin "baserom.gba", 0xFB004, 0x18
.4byte gUnknown_80FAFF4

.global gUnknown_80FB008
gUnknown_80FB008: @ 80FB008
.string "{ARG_POKEMON_0} readied Snatch!\0"
.align 2, 0

.global gUnknown_80FB01C
gUnknown_80FB01C: @ 80FB01C
@ replacing .incbin "baserom.gba", 0xFB01C, 0x2C
.4byte gUnknown_80FB008

.global gUnknown_80FB020
gUnknown_80FB020: @ 80FB020
.string "{ARG_POKEMON_0} gained the protection\n"
.string "of Safeguard!\0"
.align 2, 0

.global gUnknown_80FB048
gUnknown_80FB048: @ 80FB048
@ replacing .incbin "baserom.gba", 0xFB048, 0x2C
.4byte gUnknown_80FB020

.global gUnknown_80FB04C
gUnknown_80FB04C: @ 80FB04C
.string "{ARG_POKEMON_0} is already protected\n"
.string "by Safeguard.\0"
.align 2, 0

.global gUnknown_80FB074
gUnknown_80FB074: @ 80FB074
@ replacing .incbin "baserom.gba", 0xFB074, 0x28
.4byte gUnknown_80FB04C

.global gUnknown_80FB078
gUnknown_80FB078: @ 80FB078
.string "{ARG_POKEMON_0} gained the protection\n"
.string "of Mist!\0"
.align 2, 0

.global gUnknown_80FB09C
gUnknown_80FB09C: @ 80FB09C
@ replacing .incbin "baserom.gba", 0xFB09C, 0x28
.4byte gUnknown_80FB078

.global gUnknown_80FB0A0
gUnknown_80FB0A0: @ 80FB0A0
.string "{ARG_POKEMON_0} is already protected\n"
.string "by Mist.\0"
.align 2, 0

.global gUnknown_80FB0C4
gUnknown_80FB0C4: @ 80FB0C4
@ replacing .incbin "baserom.gba", 0xFB0C4, 0x1C
.4byte gUnknown_80FB0A0

.global gUnknown_80FB0C8
gUnknown_80FB0C8: @ 80FB0C8
.string "{ARG_POKEMON_0} is set to counter!\0"
.align 2, 0

.global gUnknown_80FB0E0
gUnknown_80FB0E0: @ 80FB0E0
@ replacing .incbin "baserom.gba", 0xFB0E0, 0x2C
.4byte gUnknown_80FB0C8

.global gUnknown_80FB0E4
gUnknown_80FB0E4: @ 80FB0E4
.string "{ARG_POKEMON_0} has been waiting to\n"
.string "counterattack!\0"
.align 2, 0

.global gUnknown_80FB10C
gUnknown_80FB10C: @ 80FB10C
@ replacing .incbin "baserom.gba", 0xFB10C, 0x24
.4byte gUnknown_80FB0E4

.global gUnknown_80FB110
gUnknown_80FB110: @ 80FB110
.string "{ARG_POKEMON_0} put up its light screen!\0"
.align 2, 0

.global gUnknown_80FB130
gUnknown_80FB130: @ 80FB130
@ replacing .incbin "baserom.gba", 0xFB130, 0x30
.4byte gUnknown_80FB110

.global gUnknown_80FB134
gUnknown_80FB134: @ 80FB134
.string "{ARG_POKEMON_0} is already protected\n"
.string "by Light Screen.\0"
.align 2, 0

.global gUnknown_80FB160
gUnknown_80FB160: @ 80FB160
@ replacing .incbin "baserom.gba", 0xFB160, 0x1C
.4byte gUnknown_80FB134

.global gUnknown_80FB164
gUnknown_80FB164: @ 80FB164
.string "{ARG_POKEMON_0} put up its reflect!\0"
.align 2, 0

.global gUnknown_80FB17C
gUnknown_80FB17C: @ 80FB17C
@ replacing .incbin "baserom.gba", 0xFB17C, 0x2C
.4byte gUnknown_80FB164

.global gUnknown_80FB180
gUnknown_80FB180: @ 80FB180
.string "{ARG_POKEMON_0} is already protected by\n"
.string "Reflect.\0"
.align 2, 0

.global gUnknown_80FB1A8
gUnknown_80FB1A8: @ 80FB1A8
@ replacing .incbin "baserom.gba", 0xFB1A8, 0x1C
.4byte gUnknown_80FB180

.global gUnknown_80FB1AC
gUnknown_80FB1AC: @ 80FB1AC
.string "{ARG_POKEMON_0} recovered {ARG_VALUE_0} HP!\0"
.align 2, 0

.global gUnknown_80FB1C4
gUnknown_80FB1C4: @ 80FB1C4
@ replacing .incbin "baserom.gba", 0xFB1C4, 0x1C
.4byte gUnknown_80FB1AC

.global gUnknown_80FB1C8
gUnknown_80FB1C8: @ 80FB1C8
.string "{ARG_POKEMON_0} was fully healed!\0"
.align 2, 0

.global gUnknown_80FB1E0
gUnknown_80FB1E0: @ 80FB1E0
@ replacing .incbin "baserom.gba", 0xFB1E0, 0x24
.4byte gUnknown_80FB1C8

.global gUnknown_80FB1E4
gUnknown_80FB1E4: @ 80FB1E4
.string "{ARG_POKEMON_0}'s HP remained unchanged.\0"
.align 2, 0

.global gUnknown_80FB204
gUnknown_80FB204: @ 80FB204
@ replacing .incbin "baserom.gba", 0xFB204, 0x18
.4byte gUnknown_80FB1E4

.global gUnknown_80FB208
gUnknown_80FB208: @ 80FB208
.string "{ARG_POKEMON_0} has full HP.\0"
.align 2, 0

.global gUnknown_80FB21C
gUnknown_80FB21C: @ 80FB21C
@ replacing .incbin "baserom.gba", 0xFB21C, 0x24
.4byte gUnknown_80FB208

.global gUnknown_80FB220
gUnknown_80FB220: @ 80FB220
.string "{ARG_POKEMON_0}'s max. HP rose by {ARG_VALUE_1}.\0"
.align 2, 0

.global gUnknown_80FB240
gUnknown_80FB240: @ 80FB240
@ replacing .incbin "baserom.gba", 0xFB240, 0x1C
.4byte gUnknown_80FB220

.global gUnknown_80FB244
gUnknown_80FB244: @ 80FB244
.string "{ARG_POKEMON_0} became confused!\0"
.align 2, 0

.global gUnknown_80FB25C
gUnknown_80FB25C: @ 80FB25C
@ replacing .incbin "baserom.gba", 0xFB25C, 0x20
.4byte gUnknown_80FB244

.global gUnknown_80FB260
gUnknown_80FB260: @ 80FB260
.string "{ARG_POKEMON_0} is already confused!\0"
.align 2, 0

.global gUnknown_80FB27C
gUnknown_80FB27C: @ 80FB27C
@ replacing .incbin "baserom.gba", 0xFB27C, 0x30
.4byte gUnknown_80FB260

.global gUnknown_80FB280
gUnknown_80FB280: @ 80FB280
.string "{ARG_POKEMON_0} became paralyzed!\n"
.string "It can't attack!\0"
.align 2, 0

.global gUnknown_80FB2AC
gUnknown_80FB2AC: @ 80FB2AC
@ replacing .incbin "baserom.gba", 0xFB2AC, 0x20
.4byte gUnknown_80FB280

.global gUnknown_80FB2B0
gUnknown_80FB2B0: @ 80FB2B0
.string "{ARG_POKEMON_0} is already paralyzed!\0"
.align 2, 0

.global gUnknown_80FB2CC
gUnknown_80FB2CC: @ 80FB2CC
@ replacing .incbin "baserom.gba", 0xFB2CC, 0x14
.4byte gUnknown_80FB2B0

.global gUnknown_80FB2D0
gUnknown_80FB2D0: @ 80FB2D0
.string "{ARG_POKEMON_0} cringed!\0"
.align 2, 0

.global gUnknown_80FB2E0
gUnknown_80FB2E0: @ 80FB2E0
@ replacing .incbin "baserom.gba", 0xFB2E0, 0x20
.4byte gUnknown_80FB2D0

.global gUnknown_80FB2E4
gUnknown_80FB2E4: @ 80FB2E4
.string "{ARG_POKEMON_0} is already cringing!\0"
.align 2, 0

.global gUnknown_80FB300
gUnknown_80FB300: @ 80FB300
@ replacing .incbin "baserom.gba", 0xFB300, 0x18
.4byte gUnknown_80FB2E4

.global gUnknown_80FB304
gUnknown_80FB304: @ 80FB304
.string "{ARG_POKEMON_0} fell asleep!\0"
.align 2, 0

.global gUnknown_80FB318
gUnknown_80FB318: @ 80FB318
@ replacing .incbin "baserom.gba", 0xFB318, 0x4
.4byte gUnknown_80FB304

.global gUnknown_80FB31C
gUnknown_80FB31C: @ 80FB31C
@ replacing .incbin "baserom.gba", 0xFB31C, 0x1C
.4byte gUnknown_80FB304

.global gUnknown_80FB320
gUnknown_80FB320: @ 80FB320
.string "{ARG_POKEMON_0} is already asleep!\0"
.align 2, 0

.global gUnknown_80FB338
gUnknown_80FB338: @ 80FB338
@ replacing .incbin "baserom.gba", 0xFB338, 0x24
.4byte gUnknown_80FB320

.global gUnknown_80FB33C
gUnknown_80FB33C: @ 80FB33C
.string "{ARG_POKEMON_0} is locked in a nightmare!\0"
.align 2, 0

.global gUnknown_80FB35C
gUnknown_80FB35C: @ 80FB35C
@ replacing .incbin "baserom.gba", 0xFB35C, 0x4
.4byte gUnknown_80FB33C

.global gUnknown_80FB360
gUnknown_80FB360: @ 80FB360
@ replacing .incbin "baserom.gba", 0xFB360, 0x20
.4byte gUnknown_80FB320

.global gUnknown_80FB364
gUnknown_80FB364: @ 80FB364
.string "{ARG_POKEMON_0} didn't become drowsy!\0"
.align 2, 0

.global gUnknown_80FB380
gUnknown_80FB380: @ 80FB380
@ replacing .incbin "baserom.gba", 0xFB380, 0x4
.4byte gUnknown_80FB364

.global gUnknown_80FB384
gUnknown_80FB384: @ 80FB384
@ replacing .incbin "baserom.gba", 0xFB384, 0x4
.4byte gUnknown_80FB320

.global gUnknown_80FB388
gUnknown_80FB388: @ 80FB388
@ replacing .incbin "baserom.gba", 0xFB388, 0x1C
.4byte gUnknown_80FB364

.global gUnknown_80FB38C
gUnknown_80FB38C: @ 80FB38C
.string "{ARG_POKEMON_0} had a nightmare!\0"
.align 2, 0

.global gUnknown_80FB3A4
gUnknown_80FB3A4: @ 80FB3A4
@ replacing .incbin "baserom.gba", 0xFB3A4, 0x28
.4byte gUnknown_80FB38C

.global gUnknown_80FB3A8
gUnknown_80FB3A8: @ 80FB3A8
.string "{ARG_POKEMON_0} is already having\n"
.string "a nightmare!\0"
.align 2, 0

.global gUnknown_80FB3CC
gUnknown_80FB3CC: @ 80FB3CC
@ replacing .incbin "baserom.gba", 0xFB3CC, 0x4
.4byte gUnknown_80FB3A8

.global gUnknown_80FB3D0
gUnknown_80FB3D0: @ 80FB3D0
@ replacing .incbin "baserom.gba", 0xFB3D0, 0x10
.4byte gUnknown_80FB364

.global gUnknown_80FB3D4
gUnknown_80FB3D4: @ 80FB3D4
.string "{ARG_POKEMON_0} yawned!\0"
.align 2, 0

.global gUnknown_80FB3E0
gUnknown_80FB3E0: @ 80FB3E0
@ replacing .incbin "baserom.gba", 0xFB3E0, 0x18
.4byte gUnknown_80FB3D4

.global gUnknown_80FB3E4
gUnknown_80FB3E4: @ 80FB3E4
.string "{ARG_POKEMON_0} didn't yawn!\0"
.align 2, 0

.global gUnknown_80FB3F8
gUnknown_80FB3F8: @ 80FB3F8
@ replacing .incbin "baserom.gba", 0xFB3F8, 0x1C
.4byte gUnknown_80FB3E4

.global gUnknown_80FB3FC
gUnknown_80FB3FC: @ 80FB3FC
.string "{ARG_POKEMON_0} is already yawning!\0"
.align 2, 0

.global gUnknown_80FB414
gUnknown_80FB414: @ 80FB414
@ replacing .incbin "baserom.gba", 0xFB414, 0x4
.4byte gUnknown_80FB3FC

.global gUnknown_80FB418
gUnknown_80FB418: @ 80FB418
@ replacing .incbin "baserom.gba", 0xFB418, 0x4
.4byte gUnknown_80FB320

.global gUnknown_80FB41C
gUnknown_80FB41C: @ 80FB41C
@ replacing .incbin "baserom.gba", 0xFB41C, 0x20
.4byte gUnknown_80FA6D8

.global gUnknown_80FB420
gUnknown_80FB420: @ 80FB420
.string "{ARG_POKEMON_0} is already sleepless!\0"
.align 2, 0

.global gUnknown_80FB43C
gUnknown_80FB43C: @ 80FB43C
@ replacing .incbin "baserom.gba", 0xFB43C, 0x1C
.4byte gUnknown_80FB420

.global gUnknown_80FB440
gUnknown_80FB440: @ 80FB440
.string "{ARG_POKEMON_0} became sleepless!\0"
.align 2, 0

.global gUnknown_80FB458
gUnknown_80FB458: @ 80FB458
@ replacing .incbin "baserom.gba", 0xFB458, 0x28
.4byte gUnknown_80FB440

.global gUnknown_80FB45C
gUnknown_80FB45C: @ 80FB45C
.string "{ARG_POKEMON_0} can't move on the next turn!\0"
.align 2, 0

.global gUnknown_80FB480
gUnknown_80FB480: @ 80FB480
@ replacing .incbin "baserom.gba", 0xFB480, 0x30
.4byte gUnknown_80FB45C

.global gUnknown_80FB484
gUnknown_80FB484: @ 80FB484
.string "{ARG_POKEMON_0} already can't move on\n"
.string "the next turn!\0"
.align 2, 0

.global gUnknown_80FB4B0
gUnknown_80FB4B0: @ 80FB4B0
@ replacing .incbin "baserom.gba", 0xFB4B0, 0x24
.4byte gUnknown_80FB484

.global gUnknown_80FB4B4
gUnknown_80FB4B4: @ 80FB4B4
.string "{ARG_POKEMON_0} can't move for a while!\0"
.align 2, 0

.global gUnknown_80FB4D4
gUnknown_80FB4D4: @ 80FB4D4
@ replacing .incbin "baserom.gba", 0xFB4D4, 0x1C
.4byte gUnknown_80FB4B4

.global gUnknown_80FB4D8
gUnknown_80FB4D8: @ 80FB4D8
.string "{ARG_POKEMON_0} is already paused!\0"
.align 2, 0

.global gUnknown_80FB4F0
gUnknown_80FB4F0: @ 80FB4F0
@ replacing .incbin "baserom.gba", 0xFB4F0, 0x1C
.4byte gUnknown_80FB4D8

.global gUnknown_80FB4F4
gUnknown_80FB4F4: @ 80FB4F4
.string "{ARG_POKEMON_0} became infatuated!\0"
.align 2, 0

.global gUnknown_80FB50C
gUnknown_80FB50C: @ 80FB50C
@ replacing .incbin "baserom.gba", 0xFB50C, 0x20
.4byte gUnknown_80FB4F4

.global gUnknown_80FB510
gUnknown_80FB510: @ 80FB510
.string "{ARG_POKEMON_0} is already infatuated!\0"
.align 2, 0

.global gUnknown_80FB52C
gUnknown_80FB52C: @ 80FB52C
@ replacing .incbin "baserom.gba", 0xFB52C, 0x1C
.4byte gUnknown_80FB510

.global gUnknown_80FB530
gUnknown_80FB530: @ 80FB530
.string "{ARG_POKEMON_0} sustained a burn!\0"
.align 2, 0

.global gUnknown_80FB548
gUnknown_80FB548: @ 80FB548
@ replacing .incbin "baserom.gba", 0xFB548, 0x1C
.4byte gUnknown_80FB530

.global gUnknown_80FB54C
gUnknown_80FB54C: @ 80FB54C
.string "{ARG_POKEMON_0} already has a burn!\0"
.align 2, 0

.global gUnknown_80FB564
gUnknown_80FB564: @ 80FB564
@ replacing .incbin "baserom.gba", 0xFB564, 0x1C
.4byte gUnknown_80FB54C

.global gUnknown_80FB568
gUnknown_80FB568: @ 80FB568
.string "But nothing happened.\0"
.align 2, 0

.global gUnknown_80FB580
gUnknown_80FB580: @ 80FB580
@ replacing .incbin "baserom.gba", 0xFB580, 0x18
.4byte gUnknown_80FB568

.global gUnknown_80FB584
gUnknown_80FB584: @ 80FB584
.string "{ARG_POKEMON_0} was poisoned!\0"
.align 2, 0

.global gUnknown_80FB598
gUnknown_80FB598: @ 80FB598
@ replacing .incbin "baserom.gba", 0xFB598, 0x1C
.4byte gUnknown_80FB584

.global gUnknown_80FB59C
gUnknown_80FB59C: @ 80FB59C
.string "{ARG_POKEMON_0} was badly poisoned!\0"
.align 2, 0

.global gUnknown_80FB5B4
gUnknown_80FB5B4: @ 80FB5B4
@ replacing .incbin "baserom.gba", 0xFB5B4, 0x20
.4byte gUnknown_80FB59C

.global gUnknown_80FB5B8
gUnknown_80FB5B8: @ 80FB5B8
.string "{ARG_POKEMON_0} is already poisoned!\0"
.align 2, 0

.global gUnknown_80FB5D4
gUnknown_80FB5D4: @ 80FB5D4
@ replacing .incbin "baserom.gba", 0xFB5D4, 0x24
.4byte gUnknown_80FB5B8

.global gUnknown_80FB5D8
gUnknown_80FB5D8: @ 80FB5D8
.string "{ARG_POKEMON_0} is already badly poisoned!\0"
.align 2, 0

.global gUnknown_80FB5F8
gUnknown_80FB5F8: @ 80FB5F8
@ replacing .incbin "baserom.gba", 0xFB5F8, 0x18
.4byte gUnknown_80FB5D8

.global gUnknown_80FB5FC
gUnknown_80FB5FC: @ 80FB5FC
.string "{ARG_POKEMON_0} became frozen!\0"
.align 2, 0

.global gUnknown_80FB610
gUnknown_80FB610: @ 80FB610
@ replacing .incbin "baserom.gba", 0xFB610, 0x18
.4byte gUnknown_80FB5FC

.global gUnknown_80FB614
gUnknown_80FB614: @ 80FB614
.string "{ARG_POKEMON_0} was squeezed!\0"
.align 2, 0

.global gUnknown_80FB628
gUnknown_80FB628: @ 80FB628
@ replacing .incbin "baserom.gba", 0xFB628, 0x24
.4byte gUnknown_80FB614

.global gUnknown_80FB62C
gUnknown_80FB62C: @ 80FB62C
.string "{ARG_POKEMON_0} is already being squeezed!\0"
.align 2, 0

.global gUnknown_80FB64C
gUnknown_80FB64C: @ 80FB64C
@ replacing .incbin "baserom.gba", 0xFB64C, 0x1C
.4byte gUnknown_80FB62C

.global gUnknown_80FB650
gUnknown_80FB650: @ 80FB650
.string "{ARG_POKEMON_0} became immobilized!\0"
.align 2, 0

.global gUnknown_80FB668
gUnknown_80FB668: @ 80FB668
@ replacing .incbin "baserom.gba", 0xFB668, 0x20
.4byte gUnknown_80FB650

.global gUnknown_80FB66C
gUnknown_80FB66C: @ 80FB66C
.string "{ARG_POKEMON_0} is already immobilized!\0"
.align 2, 0

.global gUnknown_80FB688
gUnknown_80FB688: @ 80FB688
@ replacing .incbin "baserom.gba", 0xFB688, 0x1C
.4byte gUnknown_80FB66C

.global gUnknown_80FB68C
gUnknown_80FB68C: @ 80FB68C
.string "{ARG_POKEMON_0} put down its roots!\0"
.align 2, 0

.global gUnknown_80FB6A4
gUnknown_80FB6A4: @ 80FB6A4
@ replacing .incbin "baserom.gba", 0xFB6A4, 0x1C
.4byte gUnknown_80FB68C

.global gUnknown_80FB6A8
gUnknown_80FB6A8: @ 80FB6A8
.string "{ARG_POKEMON_0} is already rooted!\0"
.align 2, 0

.global gUnknown_80FB6C0
gUnknown_80FB6C0: @ 80FB6C0
@ replacing .incbin "baserom.gba", 0xFB6C0, 0x18
.4byte gUnknown_80FB6A8

.global gUnknown_80FB6C4
gUnknown_80FB6C4: @ 80FB6C4
.string "{ARG_POKEMON_0} became wrapped!\0"
.align 2, 0

.global gUnknown_80FB6D8
gUnknown_80FB6D8: @ 80FB6D8
@ replacing .incbin "baserom.gba", 0xFB6D8, 0x24
.4byte gUnknown_80FB6C4

.global gUnknown_80FB6DC
gUnknown_80FB6DC: @ 80FB6DC
.string "{ARG_POKEMON_0} has a foe wrapped already!\0"
.align 2, 0

.global gUnknown_80FB6FC
gUnknown_80FB6FC: @ 80FB6FC
@ replacing .incbin "baserom.gba", 0xFB6FC, 0x1C
.4byte gUnknown_80FB6DC

.global gUnknown_80FB700
gUnknown_80FB700: @ 80FB700
.string "{ARG_POKEMON_0} is already wrapped!\0"
.align 2, 0

.global gUnknown_80FB718
gUnknown_80FB718: @ 80FB718
@ replacing .incbin "baserom.gba", 0xFB718, 0x24
.4byte gUnknown_80FB700

.global gUnknown_80FB71C
gUnknown_80FB71C: @ 80FB71C
.string "{ARG_POKEMON_0} attained Sure Shot status!\0"
.align 2, 0

.global gUnknown_80FB73C
gUnknown_80FB73C: @ 80FB73C
@ replacing .incbin "baserom.gba", 0xFB73C, 0x28
.4byte gUnknown_80FB71C

.global gUnknown_80FB740
gUnknown_80FB740: @ 80FB740
.string "{ARG_POKEMON_0} already has Sure Shot\n"
.string "status!\0"
.align 2, 0

.global gUnknown_80FB764
gUnknown_80FB764: @ 80FB764
@ replacing .incbin "baserom.gba", 0xFB764, 0x1C
.4byte gUnknown_80FB740

.global gUnknown_80FB768
gUnknown_80FB768: @ 80FB768
.string "{ARG_POKEMON_0} became a whiffer!\0"
.align 2, 0

.global gUnknown_80FB780
gUnknown_80FB780: @ 80FB780
@ replacing .incbin "baserom.gba", 0xFB780, 0x20
.4byte gUnknown_80FB768

.global gUnknown_80FB784
gUnknown_80FB784: @ 80FB784
.string "{ARG_POKEMON_0} is already a whiffer!\0"
.align 2, 0

.global gUnknown_80FB7A0
gUnknown_80FB7A0: @ 80FB7A0
@ replacing .incbin "baserom.gba", 0xFB7A0, 0x1C
.4byte gUnknown_80FB784

.global gUnknown_80FB7A4
gUnknown_80FB7A4: @ 80FB7A4
.string "{ARG_POKEMON_0} became petrified!\0"
.align 2, 0

.global gUnknown_80FB7BC
gUnknown_80FB7BC: @ 80FB7BC
@ replacing .incbin "baserom.gba", 0xFB7BC, 0x20
.4byte gUnknown_80FB7A4

.global gUnknown_80FB7C0
gUnknown_80FB7C0: @ 80FB7C0
.string "{ARG_POKEMON_0} is already petrified!\0"
.align 2, 0

.global gUnknown_80FB7DC
gUnknown_80FB7DC: @ 80FB7DC
@ replacing .incbin "baserom.gba", 0xFB7DC, 0x18
.4byte gUnknown_80FB7C0

.global gUnknown_80FB7E0
gUnknown_80FB7E0: @ 80FB7E0
.string "{ARG_POKEMON_0} was blinded!\0"
.align 2, 0

.global gUnknown_80FB7F4
gUnknown_80FB7F4: @ 80FB7F4
@ replacing .incbin "baserom.gba", 0xFB7F4, 0x1C
.4byte gUnknown_80FB7E0

.global gUnknown_80FB7F8
gUnknown_80FB7F8: @ 80FB7F8
.string "{ARG_POKEMON_0} is already blinded!\0"
.align 2, 0

.global gUnknown_80FB810
gUnknown_80FB810: @ 80FB810
@ replacing .incbin "baserom.gba", 0xFB810, 0x24
.4byte gUnknown_80FB7F8

.global gUnknown_80FB814
gUnknown_80FB814: @ 80FB814
.string "{ARG_POKEMON_0}'s vision turned weird!\0"
.align 2, 0

.global gUnknown_80FB834
gUnknown_80FB834: @ 80FB834
@ replacing .incbin "baserom.gba", 0xFB834, 0x28
.4byte gUnknown_80FB814

.global gUnknown_80FB838
gUnknown_80FB838: @ 80FB838
.string "{ARG_POKEMON_0}'s vision is already weird!\0"
.align 2, 0

.global gUnknown_80FB85C
gUnknown_80FB85C: @ 80FB85C
@ replacing .incbin "baserom.gba", 0xFB85C, 0x24
.4byte gUnknown_80FB838

.global gUnknown_80FB860
gUnknown_80FB860: @ 80FB860
.string "{ARG_POKEMON_0}'s vision was restored!\0"
.align 2, 0

.global gUnknown_80FB880
gUnknown_80FB880: @ 80FB880
@ replacing .incbin "baserom.gba", 0xFB880, 0x1C
.4byte gUnknown_80FB860

.global gUnknown_80FB884
gUnknown_80FB884: @ 80FB884
.string "{ARG_POKEMON_0}'s vision is fine!\0"
.align 2, 0

.global gUnknown_80FB89C
gUnknown_80FB89C: @ 80FB89C
@ replacing .incbin "baserom.gba", 0xFB89C, 0x20
.4byte gUnknown_80FB884

.global gUnknown_80FB8A0
gUnknown_80FB8A0: @ 80FB8A0
.string "{ARG_POKEMON_0}'s damage was fixed!\0"
.align 2, 0

.global gUnknown_80FB8BC
gUnknown_80FB8BC: @ 80FB8BC
@ replacing .incbin "baserom.gba", 0xFB8BC, 0x28
.4byte gUnknown_80FB8A0

.global gUnknown_80FB8C0
gUnknown_80FB8C0: @ 80FB8C0
.string "{ARG_POKEMON_0}'s damage is already fixed!\0"
.align 2, 0

.global gUnknown_80FB8E4
gUnknown_80FB8E4: @ 80FB8E4
@ replacing .incbin "baserom.gba", 0xFB8E4, 0x1C
.4byte gUnknown_80FB8C0

.global gUnknown_80FB8E8
gUnknown_80FB8E8: @ 80FB8E8
.string "{ARG_POKEMON_0} is getting pumped!\0"
.align 2, 0

.global gUnknown_80FB900
gUnknown_80FB900: @ 80FB900
@ replacing .incbin "baserom.gba", 0xFB900, 0x24
.4byte gUnknown_80FB8E8

.global gUnknown_80FB904
gUnknown_80FB904: @ 80FB904
.string "{ARG_POKEMON_0} is already getting pumped!\0"
.align 2, 0

.global gUnknown_80FB924
gUnknown_80FB924: @ 80FB924
@ replacing .incbin "baserom.gba", 0xFB924, 0x1C
.4byte gUnknown_80FB904

.global gUnknown_80FB928
gUnknown_80FB928: @ 80FB928
.string "{ARG_POKEMON_0} cowered in fear!\0"
.align 2, 0

.global gUnknown_80FB940
gUnknown_80FB940: @ 80FB940
@ replacing .incbin "baserom.gba", 0xFB940, 0x20
.4byte gUnknown_80FB928

.global gUnknown_80FB944
gUnknown_80FB944: @ 80FB944
.string "{ARG_POKEMON_0} is already cowering!\0"
.align 2, 0

.global gUnknown_80FB960
gUnknown_80FB960: @ 80FB960
@ replacing .incbin "baserom.gba", 0xFB960, 0x18
.4byte gUnknown_80FB944

.global gUnknown_80FB964
gUnknown_80FB964: @ 80FB964
.string "{ARG_POKEMON_0} became a decoy!\0"
.align 2, 0

.global gUnknown_80FB978
gUnknown_80FB978: @ 80FB978
@ replacing .incbin "baserom.gba", 0xFB978, 0x1C
.4byte gUnknown_80FB964

.global gUnknown_80FB97C
gUnknown_80FB97C: @ 80FB97C
.string "{ARG_POKEMON_0} is already a decoy!\0"
.align 2, 0

.global gUnknown_80FB994
gUnknown_80FB994: @ 80FB994
@ replacing .incbin "baserom.gba", 0xFB994, 0x1C
.4byte gUnknown_80FB97C

.global gUnknown_80FB998
gUnknown_80FB998: @ 80FB998
.string "{ARG_POKEMON_0} protected itself!\0"
.align 2, 0

.global gUnknown_80FB9B0
gUnknown_80FB9B0: @ 80FB9B0
@ replacing .incbin "baserom.gba", 0xFB9B0, 0x28
.4byte gUnknown_80FB998

.global gUnknown_80FB9B4
gUnknown_80FB9B4: @ 80FB9B4
.string "{ARG_POKEMON_0} is already protecting itself!\0"
.align 2, 0

.global gUnknown_80FB9D8
gUnknown_80FB9D8: @ 80FB9D8
@ replacing .incbin "baserom.gba", 0xFB9D8, 0x18
.4byte gUnknown_80FB9B4

.global gUnknown_80FB9DC
gUnknown_80FB9DC: @ 80FB9DC
.string "{ARG_POKEMON_0} was taunted!\0"
.align 2, 0

.global gUnknown_80FB9F0
gUnknown_80FB9F0: @ 80FB9F0
@ replacing .incbin "baserom.gba", 0xFB9F0, 0x24
.4byte gUnknown_80FB9DC

.global gUnknown_80FB9F4
gUnknown_80FB9F4: @ 80FB9F4
.string "{ARG_POKEMON_0} has been taunted already!\0"
.align 2, 0

.global gUnknown_80FBA14
gUnknown_80FBA14: @ 80FBA14
@ replacing .incbin "baserom.gba", 0xFBA14, 0x24
.4byte gUnknown_80FB9F4

.global gUnknown_80FBA18
gUnknown_80FBA18: @ 80FBA18
.string "{ARG_POKEMON_0} stored power {ARG_VALUE_0} time(s)!\0"
.align 2, 0

.global gUnknown_80FBA38
gUnknown_80FBA38: @ 80FBA38
@ replacing .incbin "baserom.gba", 0xFBA38, 0x28
.4byte gUnknown_80FBA18

.global gUnknown_80FBA3C
gUnknown_80FBA3C: @ 80FBA3C
.string "{ARG_POKEMON_0} can't store any more power!\0"
.align 2, 0

.global gUnknown_80FBA60
gUnknown_80FBA60: @ 80FBA60
@ replacing .incbin "baserom.gba", 0xFBA60, 0x20
.4byte gUnknown_80FBA3C

.global gUnknown_80FBA64
gUnknown_80FBA64: @ 80FBA64
.string "{ARG_POKEMON_0} disappeared from view!\0"
.align 2, 0

.global gUnknown_80FBA80
gUnknown_80FBA80: @ 80FBA80
@ replacing .incbin "baserom.gba", 0xFBA80, 0x20
.4byte gUnknown_80FBA64

.global gUnknown_80FBA84
gUnknown_80FBA84: @ 80FBA84
.string "{ARG_POKEMON_0} is invisible already!\0"
.align 2, 0

.global gUnknown_80FBAA0
gUnknown_80FBAA0: @ 80FBAA0
@ replacing .incbin "baserom.gba", 0xFBAA0, 0x20
.4byte gUnknown_80FBA84

.global gUnknown_80FBAA4
gUnknown_80FBAA4: @ 80FBAA4
.string "{ARG_POKEMON_0} put up its mirror coat!\0"
.align 2, 0

.global gUnknown_80FBAC0
gUnknown_80FBAC0: @ 80FBAC0
@ replacing .incbin "baserom.gba", 0xFBAC0, 0x24
.4byte gUnknown_80FBAA4

.global gUnknown_80FBAC4
gUnknown_80FBAC4: @ 80FBAC4
.string "{ARG_POKEMON_0} already has a mirror coat!\0"
.align 2, 0

.global gUnknown_80FBAE4
gUnknown_80FBAE4: @ 80FBAE4
@ replacing .incbin "baserom.gba", 0xFBAE4, 0x20
.4byte gUnknown_80FBAC4

.global gUnknown_80FBAE8
gUnknown_80FBAE8: @ 80FBAE8
.string "{ARG_POKEMON_0} heard the perish song!\0"
.align 2, 0

.global gUnknown_80FBB04
gUnknown_80FBB04: @ 80FBB04
@ replacing .incbin "baserom.gba", 0xFBB04, 0x24
.4byte gUnknown_80FBAE8

.global gUnknown_80FBB08
gUnknown_80FBB08: @ 80FBB08
.string "{ARG_POKEMON_0} already heard that song!\0"
.align 2, 0

.global gUnknown_80FBB28
gUnknown_80FBB28: @ 80FBB28
@ replacing .incbin "baserom.gba", 0xFBB28, 0x24
.4byte gUnknown_80FBB08

.global gUnknown_80FBB2C
gUnknown_80FBB2C: @ 80FBB2C
.string "{ARG_POKEMON_0} readied its Destiny Bond!\0"
.align 2, 0

.global gUnknown_80FBB4C
gUnknown_80FBB4C: @ 80FBB4C
@ replacing .incbin "baserom.gba", 0xFBB4C, 0x2C
.4byte gUnknown_80FBB2C

.global gUnknown_80FBB50
gUnknown_80FBB50: @ 80FBB50
.string "{ARG_POKEMON_0} already has Destiny Bond\n"
.string "readied!\0"
.align 2, 0

.global gUnknown_80FBB78
gUnknown_80FBB78: @ 80FBB78
@ replacing .incbin "baserom.gba", 0xFBB78, 0x1C
.4byte gUnknown_80FBB50

.global gUnknown_80FBB7C
gUnknown_80FBB7C: @ 80FBB7C
.string "{ARG_POKEMON_0} earned an encore!\0"
.align 2, 0

.global gUnknown_80FBB94
gUnknown_80FBB94: @ 80FBB94
@ replacing .incbin "baserom.gba", 0xFBB94, 0x24
.4byte gUnknown_80FBB7C

.global gUnknown_80FBB98
gUnknown_80FBB98: @ 80FBB98
.string "{ARG_POKEMON_0} is already doing encores!\0"
.align 2, 0

.global gUnknown_80FBBB8
gUnknown_80FBBB8: @ 80FBBB8
@ replacing .incbin "baserom.gba", 0xFBBB8, 0x1C
.4byte gUnknown_80FBB98

.global gUnknown_80FBBBC
gUnknown_80FBBBC: @ 80FBBBC
.string "{ARG_POKEMON_0} won't do encores!\0"
.align 2, 0

.global gUnknown_80FBBD4
gUnknown_80FBBD4: @ 80FBBD4
@ replacing .incbin "baserom.gba", 0xFBBD4, 0x1C
.4byte gUnknown_80FBBBC

.global gUnknown_80FBBD8
gUnknown_80FBBD8: @ 80FBBD8
.string "{ARG_POKEMON_0} is set to endure!\0"
.align 2, 0

.global gUnknown_80FBBF0
gUnknown_80FBBF0: @ 80FBBF0
@ replacing .incbin "baserom.gba", 0xFBBF0, 0x24
.4byte gUnknown_80FBBD8

.global gUnknown_80FBBF4
gUnknown_80FBBF4: @ 80FBBF4
.string "{ARG_POKEMON_0} is already set to endure!\0"
.align 2, 0

.global gUnknown_80FBC14
gUnknown_80FBC14: @ 80FBC14
@ replacing .incbin "baserom.gba", 0xFBC14, 0x24
.4byte gUnknown_80FBBF4

.global gUnknown_80FBC18
gUnknown_80FBC18: @ 80FBC18
.string "{ARG_POKEMON_0} readied its Mirror Move!\0"
.align 2, 0

.global gUnknown_80FBC38
gUnknown_80FBC38: @ 80FBC38
@ replacing .incbin "baserom.gba", 0xFBC38, 0x24
.4byte gUnknown_80FBC18

.global gUnknown_80FBC3C
gUnknown_80FBC3C: @ 80FBC3C
.string "{ARG_POKEMON_0} already used Mirror Move!\0"
.align 2, 0

.global gUnknown_80FBC5C
gUnknown_80FBC5C: @ 80FBC5C
@ replacing .incbin "baserom.gba", 0xFBC5C, 0x20
.4byte gUnknown_80FBC3C

.global gUnknown_80FBC60
gUnknown_80FBC60: @ 80FBC60
.string "{ARG_POKEMON_0} has Conversion 2 up!\0"
.align 2, 0

.global gUnknown_80FBC7C
gUnknown_80FBC7C: @ 80FBC7C
@ replacing .incbin "baserom.gba", 0xFBC7C, 0x28
.4byte gUnknown_80FBC60

.global gUnknown_80FBC80
gUnknown_80FBC80: @ 80FBC80
.string "{ARG_POKEMON_0} already has Conversion 2 up!\0"
.align 2, 0

.global gUnknown_80FBCA4
gUnknown_80FBCA4: @ 80FBCA4
@ replacing .incbin "baserom.gba", 0xFBCA4, 0x24
.4byte gUnknown_80FBC80

.global gUnknown_80FBCA8
gUnknown_80FBCA8: @ 80FBCA8
.string "{ARG_POKEMON_0} readied its Vital Throw!\0"
.align 2, 0

.global gUnknown_80FBCC8
gUnknown_80FBCC8: @ 80FBCC8
@ replacing .incbin "baserom.gba", 0xFBCC8, 0x28
.4byte gUnknown_80FBCA8

.global gUnknown_80FBCCC
gUnknown_80FBCCC: @ 80FBCCC
.string "{ARG_POKEMON_0} is already set for\n"
.string "Vital Throw!\0"
.align 2, 0

.global gUnknown_80FBCF0
gUnknown_80FBCF0: @ 80FBCF0
@ replacing .incbin "baserom.gba", 0xFBCF0, 0x28
.4byte gUnknown_80FBCCC

.global gUnknown_80FBCF4
gUnknown_80FBCF4: @ 80FBCF4
.string "{ARG_POKEMON_0}'s stats returned to normal.\0"
.align 2, 0

.global gUnknown_80FBD18
gUnknown_80FBD18: @ 80FBD18
@ replacing .incbin "baserom.gba", 0xFBD18, 0x24
.4byte gUnknown_80FBCF4

.global gUnknown_80FBD1C
gUnknown_80FBD1C: @ 80FBD1C
.string "{ARG_POKEMON_0}'s stats appear unchanged.\0"
.align 2, 0

.global gUnknown_80FBD3C
gUnknown_80FBD3C: @ 80FBD3C
@ replacing .incbin "baserom.gba", 0xFBD3C, 0x1C
.4byte gUnknown_80FBD1C

.global gUnknown_80FBD40
gUnknown_80FBD40: @ 80FBD40
.string "It psyched itself up!\0"
.align 2, 0

.global gUnknown_80FBD58
gUnknown_80FBD58: @ 80FBD58
@ replacing .incbin "baserom.gba", 0xFBD58, 0x20
.4byte gUnknown_80FBD40

.global gUnknown_80FBD5C
gUnknown_80FBD5C: @ 80FBD5C
.string "{ARG_POKEMON_0}'s Belly went down.\0"
.align 2, 0

.global gUnknown_80FBD78
gUnknown_80FBD78: @ 80FBD78
@ replacing .incbin "baserom.gba", 0xFBD78, 0x24
.4byte gUnknown_80FBD5C

.global gUnknown_80FBD7C
gUnknown_80FBD7C: @ 80FBD7C
.string "{ARG_POKEMON_0}'s max. Belly size shrank!\0"
.align 2, 0

.global gUnknown_80FBD9C
gUnknown_80FBD9C: @ 80FBD9C
@ replacing .incbin "baserom.gba", 0xFBD9C, 0x28
.4byte gUnknown_80FBD7C

.global gUnknown_80FBDA0
gUnknown_80FBDA0: @ 80FBDA0
.string "{ARG_POKEMON_0}'s max. Belly size increased!\0"
.align 2, 0

.global gUnknown_80FBDC4
gUnknown_80FBDC4: @ 80FBDC4
@ replacing .incbin "baserom.gba", 0xFBDC4, 0x2C
.4byte gUnknown_80FBDA0

.global gUnknown_80FBDC8
gUnknown_80FBDC8: @ 80FBDC8
.string "{ARG_POKEMON_0}'s Belly won't get any bigger!\0"
.align 2, 0

.global gUnknown_80FBDF0
gUnknown_80FBDF0: @ 80FBDF0
@ replacing .incbin "baserom.gba", 0xFBDF0, 0x24
.4byte gUnknown_80FBDC8

.global gUnknown_80FBDF4
gUnknown_80FBDF4: @ 80FBDF4
.string "{ARG_POKEMON_0}'s Belly didn't change!\0"
.align 2, 0

.global gUnknown_80FBE14
gUnknown_80FBE14: @ 80FBE14
@ replacing .incbin "baserom.gba", 0xFBE14, 0x28
.4byte gUnknown_80FBDF4

.global gUnknown_80FBE18
gUnknown_80FBE18: @ 80FBE18
.string "{ARG_POKEMON_0}'s Belly size didn't change!\0"
.align 2, 0

.global gUnknown_80FBE3C
gUnknown_80FBE3C: @ 80FBE3C
@ replacing .incbin "baserom.gba", 0xFBE3C, 0x4
.4byte gUnknown_80FBE18

.global gUnknown_80FBE40
gUnknown_80FBE40: @ 80FBE40
@ replacing .incbin "baserom.gba", 0xFBE40, 0x24
.4byte gUnknown_80FBDF4

.global gUnknown_80FBE44
gUnknown_80FBE44: @ 80FBE44
.string "{ARG_POKEMON_0}'s Belly filled up full!\0"
.align 2, 0

.global gUnknown_80FBE64
gUnknown_80FBE64: @ 80FBE64
@ replacing .incbin "baserom.gba", 0xFBE64, 0x20
.4byte gUnknown_80FBE44

.global gUnknown_80FBE68
gUnknown_80FBE68: @ 80FBE68
.string "{ARG_POKEMON_0}'s Belly was filled!\0"
.align 2, 0

.global gUnknown_80FBE84
gUnknown_80FBE84: @ 80FBE84
@ replacing .incbin "baserom.gba", 0xFBE84, 0x1C
.4byte gUnknown_80FBE68

.global gUnknown_80FBE88
gUnknown_80FBE88: @ 80FBE88
.string "{ARG_POKEMON_0}'s Belly dropped!\0"
.align 2, 0

.global gUnknown_80FBEA0
gUnknown_80FBEA0: @ 80FBEA0
@ replacing .incbin "baserom.gba", 0xFBEA0, 0x20
.4byte gUnknown_80FBE88

.global gUnknown_80FBEA4
gUnknown_80FBEA4: @ 80FBEA4
.string "{ARG_POKEMON_0} transformed into\n"
.string "{ARG_POKEMON_1}!\0"
.align 2, 0

.global gUnknown_80FBEC0
gUnknown_80FBEC0: @ 80FBEC0
@ replacing .incbin "baserom.gba", 0xFBEC0, 0x24
.4byte gUnknown_80FBEA4

.global gUnknown_80FBEC4
gUnknown_80FBEC4: @ 80FBEC4
.string "{ARG_POKEMON_0}'s transformation failed!\0"
.align 2, 0

.global gUnknown_80FBEE4
gUnknown_80FBEE4: @ 80FBEE4
@ replacing .incbin "baserom.gba", 0xFBEE4, 0x20
.4byte gUnknown_80FBEC4

.global gUnknown_80FBEE8
gUnknown_80FBEE8: @ 80FBEE8
.string "{ARG_POKEMON_0} is already transformed.\0"
.align 2, 0

.global gUnknown_80FBF04
gUnknown_80FBF04: @ 80FBF04
@ replacing .incbin "baserom.gba", 0xFBF04, 0x24
.4byte gUnknown_80FBEE8

.global gUnknown_80FBF08
gUnknown_80FBF08: @ 80FBF08
.string "{ARG_POKEMON_0} can go through walls now!\0"
.align 2, 0

.global gUnknown_80FBF28
gUnknown_80FBF28: @ 80FBF28
@ replacing .incbin "baserom.gba", 0xFBF28, 0x28
.4byte gUnknown_80FBF08

.global gUnknown_80FBF2C
gUnknown_80FBF2C: @ 80FBF2C
.string "{ARG_POKEMON_0} can already go through walls!\0"
.align 2, 0

.global gUnknown_80FBF50
gUnknown_80FBF50: @ 80FBF50
@ replacing .incbin "baserom.gba", 0xFBF50, 0x18
.4byte gUnknown_80FBF2C

.global gUnknown_80FBF54
gUnknown_80FBF54: @ 80FBF54
.string "{ARG_POKEMON_0} became muzzled!\0"
.align 2, 0

.global gUnknown_80FBF68
gUnknown_80FBF68: @ 80FBF68
@ replacing .incbin "baserom.gba", 0xFBF68, 0x1C
.4byte gUnknown_80FBF54

.global gUnknown_80FBF6C
gUnknown_80FBF6C: @ 80FBF6C
.string "{ARG_POKEMON_0} is already muzzled!\0"
.align 2, 0

.global gUnknown_80FBF84
gUnknown_80FBF84: @ 80FBF84
@ replacing .incbin "baserom.gba", 0xFBF84, 0x18
.4byte gUnknown_80FBF6C

.global gUnknown_80FBF88
gUnknown_80FBF88: @ 80FBF88
.string "{ARG_POKEMON_0} was exposed!\0"
.align 2, 0

.global gUnknown_80FBF9C
gUnknown_80FBF9C: @ 80FBF9C
@ replacing .incbin "baserom.gba", 0xFBF9C, 0x1C
.4byte gUnknown_80FBF88

.global gUnknown_80FBFA0
gUnknown_80FBFA0: @ 80FBFA0
.string "{ARG_POKEMON_0} is already exposed!\0"
.align 2, 0

.global gUnknown_80FBFB8
gUnknown_80FBFB8: @ 80FBFB8
@ replacing .incbin "baserom.gba", 0xFBFB8, 0x20
.4byte gUnknown_80FBFA0

.global gUnknown_80FBFBC
gUnknown_80FBFBC: @ 80FBFBC
.string "{ARG_POKEMON_0} isn't a Ghost type!\0"
.align 2, 0

.global gUnknown_80FBFD8
gUnknown_80FBFD8: @ 80FBFD8
@ replacing .incbin "baserom.gba", 0xFBFD8, 0x28
.4byte gUnknown_80FBFBC

.global gUnknown_80FBFDC
gUnknown_80FBFDC: @ 80FBFDC
.string "{ARG_POKEMON_0}'s Evasion returned to normal!\0"
.align 2, 0

.global gUnknown_80FC000
gUnknown_80FC000: @ 80FC000
@ replacing .incbin "baserom.gba", 0xFC000, 0x28
.4byte gUnknown_80FBFDC

.global gUnknown_80FC004
gUnknown_80FC004: @ 80FC004
.string "Item holders are now identified!\0"
.align 2, 0

.global gUnknown_80FC028
gUnknown_80FC028: @ 80FC028
@ replacing .incbin "baserom.gba", 0xFC028, 0x2C
.4byte gUnknown_80FC004

.global gUnknown_80FC02C
gUnknown_80FC02C: @ 80FC02C
.string "It can already identify item holders.\0"
.align 2, 0

.global gUnknown_80FC054
gUnknown_80FC054: @ 80FC054
@ replacing .incbin "baserom.gba", 0xFC054, 0x20
.4byte gUnknown_80FC02C

.global gUnknown_80FC058
gUnknown_80FC058: @ 80FC058
.string "{ARG_POKEMON_0} is already in a rage!\0"
.align 2, 0

.global gUnknown_80FC074
gUnknown_80FC074: @ 80FC074
@ replacing .incbin "baserom.gba", 0xFC074, 0x10
.4byte gUnknown_80FC058

.global gUnknown_80FC078
gUnknown_80FC078: @ 80FC078
.string "Accuracy\0"
.align 2, 0

.global gUnknown_80FC084
gUnknown_80FC084: @ 80FC084
@ replacing .incbin "baserom.gba", 0xFC084, 0xC
.4byte gUnknown_80FC078

.global gUnknown_80FC088
gUnknown_80FC088: @ 80FC088
.string "Evasion\0"
.align 2, 0

.global gUnknown_80FC090
gUnknown_80FC090: @ 80FC090
@ replacing .incbin "baserom.gba", 0xFC090, 0xC
.4byte gUnknown_80FC088

.global gUnknown_80FC094
gUnknown_80FC094: @ 80FC094
.string "Defense\0"
.align 2, 0

.global gUnknown_80FC09C
gUnknown_80FC09C: @ 80FC09C
@ replacing .incbin "baserom.gba", 0xFC09C, 0x10
.4byte gUnknown_80FC094

.global gUnknown_80FC0A0
gUnknown_80FC0A0: @ 80FC0A0
.string "Sp. Def.\0"
.align 2, 0

.global gUnknown_80FC0AC
gUnknown_80FC0AC: @ 80FC0AC
@ replacing .incbin "baserom.gba", 0xFC0AC, 0xC
.4byte gUnknown_80FC0A0

.global gUnknown_80FC0B0
gUnknown_80FC0B0: @ 80FC0B0
.string "Attack\0"
.align 2, 0

.global gUnknown_80FC0B8
gUnknown_80FC0B8: @ 80FC0B8
@ replacing .incbin "baserom.gba", 0xFC0B8, 0x10
.4byte gUnknown_80FC0B0

.global gUnknown_80FC0BC
gUnknown_80FC0BC: @ 80FC0BC
.string "Sp. Atk.\0"
.align 2, 0

.global gUnknown_80FC0C8
gUnknown_80FC0C8: @ 80FC0C8
@ replacing .incbin "baserom.gba", 0xFC0C8, 0xC
.4byte gUnknown_80FC0BC

.global gUnknown_80FC0CC
gUnknown_80FC0CC: @ 80FC0CC
.string "sharply\0"
.align 2, 0

.global gUnknown_80FC0D4
gUnknown_80FC0D4: @ 80FC0D4
@ replacing .incbin "baserom.gba", 0xFC0D4, 0x10
.4byte gUnknown_80FC0CC

.global gUnknown_80FC0D8
gUnknown_80FC0D8: @ 80FC0D8
.string "slightly\0"
.align 2, 0

.global gUnknown_80FC0E4
gUnknown_80FC0E4: @ 80FC0E4
@ replacing .incbin "baserom.gba", 0xFC0E4, 0x18
.4byte gUnknown_80FC0D8

.global gUnknown_80FC0E8
gUnknown_80FC0E8: @ 80FC0E8
.string "{ARG_POKEMON_0}'s {ARG_MOVE_ITEM_0} rose!\0"
.align 2, 0

.global gUnknown_80FC0FC
gUnknown_80FC0FC: @ 80FC0FC
@ replacing .incbin "baserom.gba", 0xFC0FC, 0x18
.4byte gUnknown_80FC0E8

.global gUnknown_80FC100
gUnknown_80FC100: @ 80FC100
.string "{ARG_POKEMON_0}'s {ARG_MOVE_ITEM_0} fell!\0"
.align 2, 0

.global gUnknown_80FC114
gUnknown_80FC114: @ 80FC114
@ replacing .incbin "baserom.gba", 0xFC114, 0x4
.4byte gUnknown_80FC100

.global gUnknown_80FC118
gUnknown_80FC118: @ 80FC118
@ replacing .incbin "baserom.gba", 0xFC118, 0x4
.4byte gUnknown_80FC0E8

.global gUnknown_80FC11C
gUnknown_80FC11C: @ 80FC11C
@ replacing .incbin "baserom.gba", 0xFC11C, 0x1C
.4byte gUnknown_80FC100

.global gUnknown_80FC120
gUnknown_80FC120: @ 80FC120
.string "{ARG_POKEMON_0}'s {ARG_MOVE_ITEM_0} rose\n"
.string "{ARG_MOVE_ITEM_1}!\0"
.align 2, 0

.global gUnknown_80FC138
gUnknown_80FC138: @ 80FC138
@ replacing .incbin "baserom.gba", 0xFC138, 0x4
.4byte gUnknown_80FC120

.global gUnknown_80FC13C
gUnknown_80FC13C: @ 80FC13C
@ replacing .incbin "baserom.gba", 0xFC13C, 0x1C
.4byte gUnknown_80FC120

.global gUnknown_80FC140
gUnknown_80FC140: @ 80FC140
.string "{ARG_POKEMON_0}'s {ARG_MOVE_ITEM_0} fell\n"
.string "{ARG_MOVE_ITEM_1}!\0"
.align 2, 0

.global gUnknown_80FC158
gUnknown_80FC158: @ 80FC158
@ replacing .incbin "baserom.gba", 0xFC158, 0x4
.4byte gUnknown_80FC140

.global gUnknown_80FC15C
gUnknown_80FC15C: @ 80FC15C
@ replacing .incbin "baserom.gba", 0xFC15C, 0x24
.4byte gUnknown_80FC140

.global gUnknown_80FC160
gUnknown_80FC160: @ 80FC160
.string "{ARG_POKEMON_0}'s {ARG_MOVE_ITEM_0} remained\n"
.string "unchanged!\0"
.align 2, 0

.global gUnknown_80FC180
gUnknown_80FC180: @ 80FC180
@ replacing .incbin "baserom.gba", 0xFC180, 0x4
.4byte gUnknown_80FC160

.global gUnknown_80FC184
gUnknown_80FC184: @ 80FC184
@ replacing .incbin "baserom.gba", 0xFC184, 0x20
.4byte gUnknown_80FC160

.global gUnknown_80FC188
gUnknown_80FC188: @ 80FC188
.string "{ARG_POKEMON_0}'s {ARG_MOVE_ITEM_0} fell\n"
.string "slightly!\0"
.align 2, 0

.global gUnknown_80FC1A4
gUnknown_80FC1A4: @ 80FC1A4
@ replacing .incbin "baserom.gba", 0xFC1A4, 0x20
.4byte gUnknown_80FC188

.global gUnknown_80FC1A8
gUnknown_80FC1A8: @ 80FC1A8
.string "{ARG_POKEMON_0}'s {ARG_MOVE_ITEM_0} rose\n"
.string "slightly!\0"
.align 2, 0

.global gUnknown_80FC1C4
gUnknown_80FC1C4: @ 80FC1C4
@ replacing .incbin "baserom.gba", 0xFC1C4, 0x2C
.4byte gUnknown_80FC1A8

.global gUnknown_80FC1C8
gUnknown_80FC1C8: @ 80FC1C8
.string "{ARG_POKEMON_0}'s {ARG_MOVE_ITEM_0} won't\n"
.string "go down any more!\0"
.align 2, 0

.global gUnknown_80FC1F0
gUnknown_80FC1F0: @ 80FC1F0
@ replacing .incbin "baserom.gba", 0xFC1F0, 0x28
.4byte gUnknown_80FC1C8

.global gUnknown_80FC1F4
gUnknown_80FC1F4: @ 80FC1F4
.string "{ARG_POKEMON_0}'s {ARG_MOVE_ITEM_0} won't\n"
.string "go up any more!\0"
.align 2, 0

.global gUnknown_80FC218
gUnknown_80FC218: @ 80FC218
@ replacing .incbin "baserom.gba", 0xFC218, 0x4
.4byte gUnknown_80FC1F4

.global gUnknown_80FC21C
gUnknown_80FC21C: @ 80FC21C
@ replacing .incbin "baserom.gba", 0xFC21C, 0x2C
.4byte gUnknown_80FC1F4

.global gUnknown_80FC220
gUnknown_80FC220: @ 80FC220
.string "{ARG_POKEMON_0}'s {ARG_MOVE_ITEM_0} won't\n"
.string "go down any more.\0"
.align 2, 0

.global gUnknown_80FC248
gUnknown_80FC248: @ 80FC248
@ replacing .incbin "baserom.gba", 0xFC248, 0x28
.4byte gUnknown_80FC220

.global gUnknown_80FC24C
gUnknown_80FC24C: @ 80FC24C
.string "{ARG_POKEMON_0}'s {ARG_MOVE_ITEM_0} won't\n"
.string "go up any more.\0"
.align 2, 0

.global gUnknown_80FC270
gUnknown_80FC270: @ 80FC270
@ replacing .incbin "baserom.gba", 0xFC270, 0x4
.4byte gUnknown_80FC24C

.global gUnknown_80FC274
gUnknown_80FC274: @ 80FC274
@ replacing .incbin "baserom.gba", 0xFC274, 0x24
.4byte gUnknown_80FC220

.global gUnknown_80FC278
gUnknown_80FC278: @ 80FC278
.string "{ARG_POKEMON_0}'s speed didn't change!\0"
.align 2, 0

.global gUnknown_80FC298
gUnknown_80FC298: @ 80FC298
@ replacing .incbin "baserom.gba", 0xFC298, 0x20
.4byte gUnknown_80FC278

.global gUnknown_80FC29C
gUnknown_80FC29C: @ 80FC29C
.string "{ARG_POKEMON_0} can't go any faster!\0"
.align 2, 0

.global gUnknown_80FC2B8
gUnknown_80FC2B8: @ 80FC2B8
@ replacing .incbin "baserom.gba", 0xFC2B8, 0x20
.4byte gUnknown_80FC29C

.global gUnknown_80FC2BC
gUnknown_80FC2BC: @ 80FC2BC
.string "{ARG_POKEMON_0} can't go any slower!\0"
.align 2, 0

.global gUnknown_80FC2D8
gUnknown_80FC2D8: @ 80FC2D8
@ replacing .incbin "baserom.gba", 0xFC2D8, 0x24
.4byte gUnknown_80FC2BC

.global gUnknown_80FC2DC
gUnknown_80FC2DC: @ 80FC2DC
.string "{ARG_POKEMON_0} is protected by Safeguard!\0"
.align 2, 0

.global gUnknown_80FC2FC
gUnknown_80FC2FC: @ 80FC2FC
@ replacing .incbin "baserom.gba", 0xFC2FC, 0x20
.4byte gUnknown_80FC2DC

.global gUnknown_80FC300
gUnknown_80FC300: @ 80FC300
.string "{ARG_POKEMON_0} is protected by Mist!\0"
.align 2, 0

.global gUnknown_80FC31C
gUnknown_80FC31C: @ 80FC31C
@ replacing .incbin "baserom.gba", 0xFC31C, 0x20
.4byte gUnknown_80FC300

.global gUnknown_80FC320
gUnknown_80FC320: @ 80FC320
.string "{ARG_POKEMON_0}'s Attack was boosted.\0"
.align 2, 0

.global gUnknown_80FC33C
gUnknown_80FC33C: @ 80FC33C
@ replacing .incbin "baserom.gba", 0xFC33C, 0x24
.4byte gUnknown_80FC320

.global gUnknown_80FC340
gUnknown_80FC340: @ 80FC340
.string "{ARG_POKEMON_0}'s Attack didn't go up.\0"
.align 2, 0

.global gUnknown_80FC360
gUnknown_80FC360: @ 80FC360
@ replacing .incbin "baserom.gba", 0xFC360, 0x28
.4byte gUnknown_80FC340

.global gUnknown_80FC364
gUnknown_80FC364: @ 80FC364
.string "{ARG_POKEMON_0}'s Special Attack was boosted.\0"
.align 2, 0

.global gUnknown_80FC388
gUnknown_80FC388: @ 80FC388
@ replacing .incbin "baserom.gba", 0xFC388, 0x2C
.4byte gUnknown_80FC364

.global gUnknown_80FC38C
gUnknown_80FC38C: @ 80FC38C
.string "{ARG_POKEMON_0}'s Special Attack didn't go up.\0"
.align 2, 0

.global gUnknown_80FC3B4
gUnknown_80FC3B4: @ 80FC3B4
@ replacing .incbin "baserom.gba", 0xFC3B4, 0x24
.4byte gUnknown_80FC38C

.global gUnknown_80FC3B8
gUnknown_80FC3B8: @ 80FC3B8
.string "{ARG_POKEMON_0}'s Defense was boosted.\0"
.align 2, 0

.global gUnknown_80FC3D8
gUnknown_80FC3D8: @ 80FC3D8
@ replacing .incbin "baserom.gba", 0xFC3D8, 0x24
.4byte gUnknown_80FC3B8

.global gUnknown_80FC3DC
gUnknown_80FC3DC: @ 80FC3DC
.string "{ARG_POKEMON_0}'s Defense didn't go up.\0"
.align 2, 0

.global gUnknown_80FC3FC
gUnknown_80FC3FC: @ 80FC3FC
@ replacing .incbin "baserom.gba", 0xFC3FC, 0x2C
.4byte gUnknown_80FC3DC

.global gUnknown_80FC400
gUnknown_80FC400: @ 80FC400
.string "{ARG_POKEMON_0}'s Special Defense was\n"
.string "boosted.\0"
.align 2, 0

.global gUnknown_80FC428
gUnknown_80FC428: @ 80FC428
@ replacing .incbin "baserom.gba", 0xFC428, 0x2C
.4byte gUnknown_80FC400

.global gUnknown_80FC42C
gUnknown_80FC42C: @ 80FC42C
.string "{ARG_POKEMON_0}'s Special Defense didn't\n"
.string "go up.\0"
.align 2, 0

.global gUnknown_80FC454
gUnknown_80FC454: @ 80FC454
@ replacing .incbin "baserom.gba", 0xFC454, 0xD8
.4byte gUnknown_80FC42C

.global gUnknown_80FC458
gUnknown_80FC458: @ 80FC458
.string "{ARG_POKEMON_0}'s Attack was weakened.\0"
.align 2, 0
.4byte gUnknown_80FC458

.global gUnknown_80FC47C
gUnknown_80FC47C: @ 80FC47C
.string "{ARG_POKEMON_0}'s Attack didn't go down.\0"
.align 2, 0
.4byte gUnknown_80FC47C

.global gUnknown_80FC4A4
gUnknown_80FC4A4: @ 80FC4A4
.string "{ARG_POKEMON_0}'s Special Attack was\n"
.string "weakened.\0"
.align 2, 0
.4byte gUnknown_80FC4A4

.global gUnknown_80FC4D0
gUnknown_80FC4D0: @ 80FC4D0
.string "{ARG_POKEMON_0}'s Special Attack didn't go\n"
.string "down.\0"
.align 2, 0
.4byte gUnknown_80FC4D0

.global gUnknown_80FC500
gUnknown_80FC500: @ 80FC500
.string "The target's Magic Coat bounced it back!\0"
.align 2, 0

.global gUnknown_80FC52C
gUnknown_80FC52C: @ 80FC52C
@ replacing .incbin "baserom.gba", 0xFC52C, 0x2C
.4byte gUnknown_80FC500

.global gUnknown_80FC530
gUnknown_80FC530: @ 80FC530
.string "The target's Mirror Move returned it!\0"
.align 2, 0

.global gUnknown_80FC558
gUnknown_80FC558: @ 80FC558
@ replacing .incbin "baserom.gba", 0xFC558, 0x1C
.4byte gUnknown_80FC530

.global gUnknown_80FC55C
gUnknown_80FC55C: @ 80FC55C
.string "{ARG_POKEMON_1} protected itself!\0"
.align 2, 0

.global gUnknown_80FC574
gUnknown_80FC574: @ 80FC574
@ replacing .incbin "baserom.gba", 0xFC574, 0x10
.4byte gUnknown_80FC55C

.global gUnknown_80FC578
gUnknown_80FC578: @ 80FC578
.string "{ARG_POKEMON_0} warped!\0"
.align 2, 0

.global gUnknown_80FC584
gUnknown_80FC584: @ 80FC584
@ replacing .incbin "baserom.gba", 0xFC584, 0x24
.4byte gUnknown_80FC578

.global gUnknown_80FC588
gUnknown_80FC588: @ 80FC588
.string "A trap can't be laid here.\0"
.align 2, 0

.global gUnknown_80FC5A8
gUnknown_80FC5A8: @ 80FC5A8
@ replacing .incbin "baserom.gba", 0xFC5A8, 0x24
.4byte gUnknown_80FC588

.global gUnknown_80FC5AC
gUnknown_80FC5AC: @ 80FC5AC
.string "{ARG_POKEMON_0} was too hungry to use it!\0"
.align 2, 0

.global gUnknown_80FC5CC
gUnknown_80FC5CC: @ 80FC5CC
@ replacing .incbin "baserom.gba", 0xFC5CC, 0x14
.4byte gUnknown_80FC5AC

.global gUnknown_80FC5D0
gUnknown_80FC5D0: @ 80FC5D0
.string "Weather: {ARG_POKEMON_0}\0"
.align 2, 0

.global gUnknown_80FC5E0
gUnknown_80FC5E0: @ 80FC5E0
@ replacing .incbin "baserom.gba", 0xFC5E0, 0x18
.4byte gUnknown_80FC5D0

.global gUnknown_80FC5E4
gUnknown_80FC5E4: @ 80FC5E4
.string "A trap was laid!\0"
.align 2, 0

.global gUnknown_80FC5F8
gUnknown_80FC5F8: @ 80FC5F8
@ replacing .incbin "baserom.gba", 0xFC5F8, 0x4
.4byte gUnknown_80FC5E4

.global gUnknown_80FC5FC
gUnknown_80FC5FC: @ 80FC5FC
@ replacing .incbin "baserom.gba", 0xFC5FC, 0x18
.4byte gUnknown_80FC588

.global gUnknown_80FC600
gUnknown_80FC600: @ 80FC600
.string "Got {ARG_POKEMON_1}'s item!\0"
.align 2, 0

.global gUnknown_80FC614
gUnknown_80FC614: @ 80FC614
@ replacing .incbin "baserom.gba", 0xFC614, 0x40
.4byte gUnknown_80FC600

.global gUnknown_80FC618
gUnknown_80FC618: @ 80FC618
.string "{ARG_POKEMON_0} has an item already.\n"
.string "It couldn't get another item.\0"
.align 2, 0

.global gUnknown_80FC654
gUnknown_80FC654: @ 80FC654
@ replacing .incbin "baserom.gba", 0xFC654, 0x24
.4byte gUnknown_80FC618

.global gUnknown_80FC658
gUnknown_80FC658: @ 80FC658
.string "{ARG_POKEMON_1} doesn't have anything!\0"
.align 2, 0

.global gUnknown_80FC678
gUnknown_80FC678: @ 80FC678
@ replacing .incbin "baserom.gba", 0xFC678, 0x18
.4byte gUnknown_80FC658

.global gUnknown_80FC67C
gUnknown_80FC67C: @ 80FC67C
.string "The move failed!\0"
.align 2, 0

.global gUnknown_80FC690
gUnknown_80FC690: @ 80FC690
@ replacing .incbin "baserom.gba", 0xFC690, 0x14
.4byte gUnknown_80FC67C

.global gUnknown_80FC694
gUnknown_80FC694: @ 80FC694
.string "The Orb failed!\0"
.align 2, 0

.global gUnknown_80FC6A4
gUnknown_80FC6A4: @ 80FC6A4
@ replacing .incbin "baserom.gba", 0xFC6A4, 0x4
.4byte gUnknown_80FC694

.global gUnknown_80FC6A8
gUnknown_80FC6A8: @ 80FC6A8
@ replacing .incbin "baserom.gba", 0xFC6A8, 0x28
.4byte gUnknown_80F8F24

.global gUnknown_80FC6AC
gUnknown_80FC6AC: @ 80FC6AC
.string "But the move couldn't be used!\0"
.align 2, 0

.global gUnknown_80FC6D0
gUnknown_80FC6D0: @ 80FC6D0
@ replacing .incbin "baserom.gba", 0xFC6D0, 0x2C
.4byte gUnknown_80FC6AC

.global gUnknown_80FC6D4
gUnknown_80FC6D4: @ 80FC6D4
.string "But Orbs are prevented from being used!\0"
.align 2, 0

.global gUnknown_80FC6FC
gUnknown_80FC6FC: @ 80FC6FC
@ replacing .incbin "baserom.gba", 0xFC6FC, 0x14
.4byte gUnknown_80FC6D4

.global gUnknown_80FC700
gUnknown_80FC700: @ 80FC700
.string "{ARG_POKEMON_0} is muzzled!\0"
.align 2, 0

.global gUnknown_80FC710
gUnknown_80FC710: @ 80FC710
@ replacing .incbin "baserom.gba", 0xFC710, 0x4
.4byte gUnknown_80FC700

.global gUnknown_80FC714
gUnknown_80FC714: @ 80FC714
@ replacing .incbin "baserom.gba", 0xFC714, 0x4
.4byte gUnknown_80F8F0C

.global gUnknown_80FC718
gUnknown_80FC718: @ 80FC718
@ replacing .incbin "baserom.gba", 0xFC718, 0x14
.4byte gUnknown_80F95A8

.global gUnknown_80FC71C
gUnknown_80FC71C: @ 80FC71C
.string "{ARG_POKEMON_0} loosed {ARG_MOVE_ITEM_0}!\0"
.align 2, 0

.global gUnknown_80FC72C
gUnknown_80FC72C: @ 80FC72C
@ replacing .incbin "baserom.gba", 0xFC72C, 0x4
.4byte gUnknown_80FC71C

.global gUnknown_80FC730
gUnknown_80FC730: @ 80FC730
@ replacing .incbin "baserom.gba", 0xFC730, 0x4
.4byte gUnknown_80FB568

.global gUnknown_80FC734
gUnknown_80FC734: @ 80FC734
@ replacing .incbin "baserom.gba", 0xFC734, 0x18
.4byte gUnknown_80FB568

.global gUnknown_80FC738
gUnknown_80FC738: @ 80FC738
.string "Nothing happened.\0"
.align 2, 0

.global gUnknown_80FC74C
gUnknown_80FC74C: @ 80FC74C
@ replacing .incbin "baserom.gba", 0xFC74C, 0x24
.4byte gUnknown_80FC738

.global gUnknown_80FC750
gUnknown_80FC750: @ 80FC750
.string "But no power had been stored!\0"
.align 2, 0

.global gUnknown_80FC770
gUnknown_80FC770: @ 80FC770
@ replacing .incbin "baserom.gba", 0xFC770, 0x20
.4byte gUnknown_80FC750

.global gUnknown_80FC774
gUnknown_80FC774: @ 80FC774
.string "{ARG_POKEMON_0} traded items with\n"
.string "{ARG_POKEMON_1}!\0"
.align 2, 0

.global gUnknown_80FC790
gUnknown_80FC790: @ 80FC790
@ replacing .incbin "baserom.gba", 0xFC790, 0x1C
.4byte gUnknown_80FC774

.global gUnknown_80FC794
gUnknown_80FC794: @ 80FC794
.string "The item trade failed!\0"
.align 2, 0

.global gUnknown_80FC7AC
gUnknown_80FC7AC: @ 80FC7AC
@ replacing .incbin "baserom.gba", 0xFC7AC, 0x1C
.4byte gUnknown_80FC794

.global gUnknown_80FC7B0
gUnknown_80FC7B0: @ 80FC7B0
.string "{ARG_POKEMON_0}'s move missed!\0"
.align 2, 0

.global gUnknown_80FC7C8
gUnknown_80FC7C8: @ 80FC7C8
@ replacing .incbin "baserom.gba", 0xFC7C8, 0x24
.4byte gUnknown_80FC7B0

.global gUnknown_80FC7CC
gUnknown_80FC7CC: @ 80FC7CC
.string "{ARG_POKEMON_0} and {ARG_POKEMON_1} shared\n"
.string "their HP!\0"
.align 2, 0

.global gUnknown_80FC7EC
gUnknown_80FC7EC: @ 80FC7EC
@ replacing .incbin "baserom.gba", 0xFC7EC, 0x30
.4byte gUnknown_80FC7CC

.global gUnknown_80FC7F0
gUnknown_80FC7F0: @ 80FC7F0
.string "{ARG_POKEMON_0} copied the target's\n"
.string "special ability!\0"
.align 2, 0

.global gUnknown_80FC81C
gUnknown_80FC81C: @ 80FC81C
@ replacing .incbin "baserom.gba", 0xFC81C, 0x38
.4byte gUnknown_80FC7F0

.global gUnknown_80FC820
gUnknown_80FC820: @ 80FC820
.string "{ARG_POKEMON_0} couldn't copy the target's\n"
.string "Wonder Guard!\0"
.align 2, 0

.global gUnknown_80FC854
gUnknown_80FC854: @ 80FC854
@ replacing .incbin "baserom.gba", 0xFC854, 0x34
.4byte gUnknown_80FC820

.global gUnknown_80FC858
gUnknown_80FC858: @ 80FC858
.string "{ARG_POKEMON_0} swapped special abilities\n"
.string "with the target!\0"
.align 2, 0

.global gUnknown_80FC888
gUnknown_80FC888: @ 80FC888
@ replacing .incbin "baserom.gba", 0xFC888, 0x38
.4byte gUnknown_80FC858

.global gUnknown_80FC88C
gUnknown_80FC88C: @ 80FC88C
.string "{ARG_POKEMON_0} couldn't swap the target's\n"
.string "Wonder Guard!\0"
.align 2, 0

.global gUnknown_80FC8C0
gUnknown_80FC8C0: @ 80FC8C0
@ replacing .incbin "baserom.gba", 0xFC8C0, 0x30
.4byte gUnknown_80FC88C

.global gUnknown_80FC8C4
gUnknown_80FC8C4: @ 80FC8C4
.string "All sticky, gummed-up items were cleaned!\0"
.align 2, 0

.global gUnknown_80FC8F0
gUnknown_80FC8F0: @ 80FC8F0
@ replacing .incbin "baserom.gba", 0xFC8F0, 0x30
.4byte gUnknown_80FC8C4

.global gUnknown_80FC8F4
gUnknown_80FC8F4: @ 80FC8F4
.string "There were no sticky, gummed-up items.\0"
.align 2, 0

.global gUnknown_80FC920
gUnknown_80FC920: @ 80FC920
@ replacing .incbin "baserom.gba", 0xFC920, 0x5C
.4byte gUnknown_80FC8F4

.global gUnknown_80FC924
gUnknown_80FC924: @ 80FC924
.string "The target is a Ground type!\n"
.string "Mud-Slap didn't work!\0"
.align 2, 0
.4byte gUnknown_80FC924

.global gUnknown_80FC960
gUnknown_80FC960: @ 80FC960
.string "There's nowhere to warp!\0"
.align 2, 0

.global gUnknown_80FC97C
gUnknown_80FC97C: @ 80FC97C
@ replacing .incbin "baserom.gba", 0xFC97C, 0x24
.4byte gUnknown_80FC960

.global gUnknown_80FC980
gUnknown_80FC980: @ 80FC980
.string "It's already on the stairs.\0"
.align 2, 0

.global gUnknown_80FC9A0
gUnknown_80FC9A0: @ 80FC9A0
@ replacing .incbin "baserom.gba", 0xFC9A0, 0x20
.4byte gUnknown_80FC980

.global gUnknown_80FC9A4
gUnknown_80FC9A4: @ 80FC9A4
.string "It couldn't make a leap!\0"
.align 2, 0

.global gUnknown_80FC9C0
gUnknown_80FC9C0: @ 80FC9C0
@ replacing .incbin "baserom.gba", 0xFC9C0, 0x28
.4byte gUnknown_80FC9A4

.global gUnknown_80FC9C4
gUnknown_80FC9C4: @ 80FC9C4
.string "It couldn't be knocked flying!\0"
.align 2, 0

.global gUnknown_80FC9E8
gUnknown_80FC9E8: @ 80FC9E8
@ replacing .incbin "baserom.gba", 0xFC9E8, 0x28
.4byte gUnknown_80FC9C4

.global gUnknown_80FC9EC
gUnknown_80FC9EC: @ 80FC9EC
.string "{ARG_POKEMON_0} couldn't be knocked flying!\0"
.align 2, 0

.global gUnknown_80FCA10
gUnknown_80FCA10: @ 80FCA10
@ replacing .incbin "baserom.gba", 0xFCA10, 0x2C
.4byte gUnknown_80FC9EC

.global gUnknown_80FCA14
gUnknown_80FCA14: @ 80FCA14
.string "It had no power stockpiled to spit up!\0"
.align 2, 0

.global gUnknown_80FCA3C
gUnknown_80FCA3C: @ 80FCA3C
@ replacing .incbin "baserom.gba", 0xFCA3C, 0x24
.4byte gUnknown_80FCA14

.global gUnknown_80FCA40
gUnknown_80FCA40: @ 80FCA40
.string "{ARG_POKEMON_0}'s {ARG_MOVE_ITEM_0} didn't\n"
.string "go down!\0"
.align 2, 0

.global gUnknown_80FCA60
gUnknown_80FCA60: @ 80FCA60
@ replacing .incbin "baserom.gba", 0xFCA60, 0x4
.4byte gUnknown_80FCA40

.global gUnknown_80FCA64
gUnknown_80FCA64: @ 80FCA64
@ replacing .incbin "baserom.gba", 0xFCA64, 0x2C
.4byte gUnknown_80FCA40

.global gUnknown_80FCA68
gUnknown_80FCA68: @ 80FCA68
.string "{ARG_POKEMON_1} is sturdy!\n"
.string "It withstood the move!\0"
.align 2, 0

.global gUnknown_80FCA90
gUnknown_80FCA90: @ 80FCA90
@ replacing .incbin "baserom.gba", 0xFCA90, 0x30
.4byte gUnknown_80FCA68

.global gUnknown_80FCA94
gUnknown_80FCA94: @ 80FCA94
.string "{ARG_POKEMON_0} is anchored!\n"
.string "It won't switch places!\0"
.align 2, 0

.global gUnknown_80FCAC0
gUnknown_80FCAC0: @ 80FCAC0
@ replacing .incbin "baserom.gba", 0xFCAC0, 0x28
.4byte gUnknown_80FCA94

.global gUnknown_80FCAC4
gUnknown_80FCAC4: @ 80FCAC4
.string "{ARG_POKEMON_0} is anchored!\n"
.string "It won't warp!\0"
.align 2, 0

.global gUnknown_80FCAE8
gUnknown_80FCAE8: @ 80FCAE8
@ replacing .incbin "baserom.gba", 0xFCAE8, 0x2C
.4byte gUnknown_80FCAC4

.global gUnknown_80FCAEC
gUnknown_80FCAEC: @ 80FCAEC
.string "But it dropped back at the same spot!\0"
.align 2, 0

.global gUnknown_80FCB14
gUnknown_80FCB14: @ 80FCB14
@ replacing .incbin "baserom.gba", 0xFCB14, 0x2C
.4byte gUnknown_80FCAEC

.global gUnknown_80FCB18
gUnknown_80FCB18: @ 80FCB18
.string "{ARG_POKEMON_0} is anchored!\n"
.string "It can't be thrown!\0"
.align 2, 0

.global gUnknown_80FCB40
gUnknown_80FCB40: @ 80FCB40
@ replacing .incbin "baserom.gba", 0xFCB40, 0x30
.4byte gUnknown_80FCB18

.global gUnknown_80FCB44
gUnknown_80FCB44: @ 80FCB44
.string "{ARG_POKEMON_0} couldn't be thrown for\n"
.string "some reason!\0"
.align 2, 0

.global gUnknown_80FCB70
gUnknown_80FCB70: @ 80FCB70
@ replacing .incbin "baserom.gba", 0xFCB70, 0x28
.4byte gUnknown_80FCB44

.global gUnknown_80FCB74
gUnknown_80FCB74: @ 80FCB74
.string "{ARG_POKEMON_0} is anchored!\n"
.string "It can't leap!\0"
.align 2, 0

.global gUnknown_80FCB98
gUnknown_80FCB98: @ 80FCB98
@ replacing .incbin "baserom.gba", 0xFCB98, 0x34
.4byte gUnknown_80FCB74

.global gUnknown_80FCB9C
gUnknown_80FCB9C: @ 80FCB9C
.string "{ARG_POKEMON_0} is anchored!\n"
.string "It can't be knocked flying!\0"
.align 2, 0

.global gUnknown_80FCBCC
gUnknown_80FCBCC: @ 80FCBCC
@ replacing .incbin "baserom.gba", 0xFCBCC, 0x2C
.4byte gUnknown_80FCB9C

.global gUnknown_80FCBD0
gUnknown_80FCBD0: @ 80FCBD0
.string "{ARG_POKEMON_0} is limber!\n"
.string "It can't be paralyzed!\0"
.align 2, 0

.global gUnknown_80FCBF8
gUnknown_80FCBF8: @ 80FCBF8
@ replacing .incbin "baserom.gba", 0xFCBF8, 0x20
.4byte gUnknown_80FCBD0

.global gUnknown_80FCBFC
gUnknown_80FCBFC: @ 80FCBFC
.string "But {ARG_POKEMON_0} didn't cringe!\0"
.align 2, 0

.global gUnknown_80FCC18
gUnknown_80FCC18: @ 80FCC18
@ replacing .incbin "baserom.gba", 0xFCC18, 0x34
.4byte gUnknown_80FCBFC

.global gUnknown_80FCC1C
gUnknown_80FCC1C: @ 80FCC1C
.string "{ARG_POKEMON_0} is oblivious!\n"
.string "It doesn't get infatuated!\0"
.align 2, 0

.global gUnknown_80FCC4C
gUnknown_80FCC4C: @ 80FCC4C
@ replacing .incbin "baserom.gba", 0xFCC4C, 0x30
.4byte gUnknown_80FCC1C

.global gUnknown_80FCC50
gUnknown_80FCC50: @ 80FCC50
.string "{ARG_POKEMON_0} traced the target's\n"
.string "special ability!\0"
.align 2, 0

.global gUnknown_80FCC7C
gUnknown_80FCC7C: @ 80FCC7C
@ replacing .incbin "baserom.gba", 0xFCC7C, 0x30
.4byte gUnknown_80FCC50

.global gUnknown_80FCC80
gUnknown_80FCC80: @ 80FCC80
.string "{ARG_POKEMON_0}'s Color Change made it\n"
.string "the {ARG_MOVE_ITEM_0} type!\0"
.align 2, 0

.global gUnknown_80FCCAC
gUnknown_80FCCAC: @ 80FCCAC
@ replacing .incbin "baserom.gba", 0xFCCAC, 0x38
.4byte gUnknown_80FCC80
.4byte gUnknown_80F7F20

.global gUnknown_80FCCB4
gUnknown_80FCCB4: @ 80FCCB4
.string "But the target's item couldn't be taken!\0"
.align 2, 0

.global gUnknown_80FCCE4
gUnknown_80FCCE4: @ 80FCCE4
@ replacing .incbin "baserom.gba", 0xFCCE4, 0x4
.4byte gUnknown_80FCCB4

.global gUnknown_80FCCE8
gUnknown_80FCCE8: @ 80FCCE8
@ replacing .incbin "baserom.gba", 0xFCCE8, 0x24
.4byte gUnknown_80FCCB4

.global gUnknown_80FCCEC
gUnknown_80FCCEC: @ 80FCCEC
.string "A Lightningrod took the move!\0"
.align 2, 0

.global gUnknown_80FCD0C
gUnknown_80FCD0C: @ 80FCD0C
@ replacing .incbin "baserom.gba", 0xFCD0C, 0x1C
.4byte gUnknown_80FCCEC

.global gUnknown_80FCD10
gUnknown_80FCD10: @ 80FCD10
.string "The move was snatched!\0"
.align 2, 0

.global gUnknown_80FCD28
gUnknown_80FCD28: @ 80FCD28
@ replacing .incbin "baserom.gba", 0xFCD28, 0x2C
.4byte gUnknown_80FCD10

.global gUnknown_80FCD2C
gUnknown_80FCD2C: @ 80FCD2C
.string "{ARG_POKEMON_0}'s Insomnia prevents\n"
.string "drowsiness!\0"
.align 2, 0

.global gUnknown_80FCD54
gUnknown_80FCD54: @ 80FCD54
@ replacing .incbin "baserom.gba", 0xFCD54, 0x4
.4byte gUnknown_80FCD2C

.global gUnknown_80FCD58
gUnknown_80FCD58: @ 80FCD58
@ replacing .incbin "baserom.gba", 0xFCD58, 0x30
.4byte gUnknown_80FCD2C

.global gUnknown_80FCD5C
gUnknown_80FCD5C: @ 80FCD5C
.string "{ARG_POKEMON_0}'s Vital Spirit prevents\n"
.string "drowsiness!\0"
.align 2, 0

.global gUnknown_80FCD88
gUnknown_80FCD88: @ 80FCD88
@ replacing .incbin "baserom.gba", 0xFCD88, 0x2C
.4byte gUnknown_80FCD5C

.global gUnknown_80FCD8C
gUnknown_80FCD8C: @ 80FCD8C
.string "{ARG_POKEMON_0}'s Own Tempo prevents\n"
.string "confusion!\0"
.align 2, 0

.global gUnknown_80FCDB4
gUnknown_80FCDB4: @ 80FCDB4
@ replacing .incbin "baserom.gba", 0xFCDB4, 0x2C
.4byte gUnknown_80FCD8C

.global gUnknown_80FCDB8
gUnknown_80FCDB8: @ 80FCDB8
.string "{ARG_POKEMON_0}'s Magma Armor prevents\n"
.string "freezing!\0"
.align 2, 0

.global gUnknown_80FCDE0
gUnknown_80FCDE0: @ 80FCDE0
@ replacing .incbin "baserom.gba", 0xFCDE0, 0x20
.4byte gUnknown_80FCDB8

.global gUnknown_80FCDE4
gUnknown_80FCDE4: @ 80FCDE4
.string "{ARG_POKEMON_0} is an unfreezable type!\0"
.align 2, 0

.global gUnknown_80FCE00
gUnknown_80FCE00: @ 80FCE00
@ replacing .incbin "baserom.gba", 0xFCE00, 0x34
.4byte gUnknown_80FCDE4

.global gUnknown_80FCE04
gUnknown_80FCE04: @ 80FCE04
.string "The magma's heat prevents {ARG_POKEMON_0}\n"
.string "from freezing!\0"
.align 2, 0

.global gUnknown_80FCE34
gUnknown_80FCE34: @ 80FCE34
@ replacing .incbin "baserom.gba", 0xFCE34, 0x28
.4byte gUnknown_80FCE04

.global gUnknown_80FCE38
gUnknown_80FCE38: @ 80FCE38
.string "{ARG_POKEMON_0}'s Water Veil prevents burns!\0"
.align 2, 0

.global gUnknown_80FCE5C
gUnknown_80FCE5C: @ 80FCE5C
@ replacing .incbin "baserom.gba", 0xFCE5C, 0x28
.4byte gUnknown_80FCE38

.global gUnknown_80FCE60
gUnknown_80FCE60: @ 80FCE60
.string "{ARG_POKEMON_0}'s type doesn't get burns!\0"
.align 2, 0

.global gUnknown_80FCE84
gUnknown_80FCE84: @ 80FCE84
@ replacing .incbin "baserom.gba", 0xFCE84, 0x2C
.4byte gUnknown_80FCE60

.global gUnknown_80FCE88
gUnknown_80FCE88: @ 80FCE88
.string "{ARG_POKEMON_0}'s Immunity prevents\n"
.string "poisoning!\0"
.align 2, 0

.global gUnknown_80FCEB0
gUnknown_80FCEB0: @ 80FCEB0
@ replacing .incbin "baserom.gba", 0xFCEB0, 0x2C
.4byte gUnknown_80FCE88

.global gUnknown_80FCEB4
gUnknown_80FCEB4: @ 80FCEB4
.string "{ARG_POKEMON_0}'s type doesn't get poisoned!\0"
.align 2, 0

.global gUnknown_80FCEDC
gUnknown_80FCEDC: @ 80FCEDC
@ replacing .incbin "baserom.gba", 0xFCEDC, 0x20
.4byte gUnknown_80FCEB4

.global gUnknown_80FCEE0
gUnknown_80FCEE0: @ 80FCEE0
.string "It had no effect on {ARG_POKEMON_0}!\0"
.align 2, 0

.global gUnknown_80FCEFC
gUnknown_80FCEFC: @ 80FCEFC
@ replacing .incbin "baserom.gba", 0xFCEFC, 0x1C
.4byte gUnknown_80FCEE0

.global gUnknown_80FCF00
gUnknown_80FCF00: @ 80FCF00
.string "Yes! {ARG_POKEMON_0} leveled up!\0"
.align 2, 0

.global gUnknown_80FCF18
gUnknown_80FCF18: @ 80FCF18
@ replacing .incbin "baserom.gba", 0xFCF18, 0x20
.4byte gUnknown_80FCF00

.global gUnknown_80FCF1C
gUnknown_80FCF1C: @ 80FCF1C
.string "{ARG_POKEMON_0} uttered its sleep talk!\0"
.align 2, 0

.global gUnknown_80FCF38
gUnknown_80FCF38: @ 80FCF38
@ replacing .incbin "baserom.gba", 0xFCF38, 0x18
.4byte gUnknown_80FCF1C

.global gUnknown_80FCF3C
gUnknown_80FCF3C: @ 80FCF3C
.string "{ARG_POKEMON_0} loosed a snore!\0"
.align 2, 0

.global gUnknown_80FCF50
gUnknown_80FCF50: @ 80FCF50
@ replacing .incbin "baserom.gba", 0xFCF50, 0x24
.4byte gUnknown_80FCF3C

.global gUnknown_80FCF54
gUnknown_80FCF54: @ 80FCF54
.string "The weather remained unchanged!\0"
.align 2, 0

.global gUnknown_80FCF74
gUnknown_80FCF74: @ 80FCF74
@ replacing .incbin "baserom.gba", 0xFCF74, 0x4
.4byte gUnknown_80FCF54

.global gUnknown_80FCF78
gUnknown_80FCF78: @ 80FCF78
@ replacing .incbin "baserom.gba", 0xFCF78, 0x4
.4byte gUnknown_80FCF54

.global gUnknown_80FCF7C
gUnknown_80FCF7C: @ 80FCF7C
@ replacing .incbin "baserom.gba", 0xFCF7C, 0x4
.4byte gUnknown_80FCF54

.global gUnknown_80FCF80
gUnknown_80FCF80: @ 80FCF80
@ replacing .incbin "baserom.gba", 0xFCF80, 0x24
.4byte gUnknown_80FCF54

.global gUnknown_80FCF84
gUnknown_80FCF84: @ 80FCF84
.string "Its power was rebounded back!\0"
.align 2, 0

.global gUnknown_80FCFA4
gUnknown_80FCFA4: @ 80FCFA4
@ replacing .incbin "baserom.gba", 0xFCFA4, 0x18
.4byte gUnknown_80FCF84

.global gUnknown_80FCFA8
gUnknown_80FCFA8: @ 80FCFA8
.string "{ARG_MOVE_ITEM_0} was tormented!\0"
.align 2, 0

.global gUnknown_80FCFBC
gUnknown_80FCFBC: @ 80FCFBC
@ replacing .incbin "baserom.gba", 0xFCFBC, 0x28
.4byte gUnknown_80FCFA8

.global gUnknown_80FCFC0
gUnknown_80FCFC0: @ 80FCFC0
.string "The target couldn't be tormented!\0"
.align 2, 0

.global gUnknown_80FCFE4
gUnknown_80FCFE4: @ 80FCFE4
@ replacing .incbin "baserom.gba", 0xFCFE4, 0x34
.4byte gUnknown_80FCFC0

.global gUnknown_80FCFE8
gUnknown_80FCFE8: @ 80FCFE8
.string "The target's HP can't be halved anymore!\0"
.align 2, 0

.global gUnknown_80FD018
gUnknown_80FD018: @ 80FD018
@ replacing .incbin "baserom.gba", 0xFD018, 0x28
.4byte gUnknown_80FCFE8

.global gUnknown_80FD01C
gUnknown_80FD01C: @ 80FD01C
.string "It became brighter on the floor!\0"
.align 2, 0

.global gUnknown_80FD040
gUnknown_80FD040: @ 80FD040
@ replacing .incbin "baserom.gba", 0xFD040, 0x1C
.4byte gUnknown_80FD01C

.global gUnknown_80FD044
gUnknown_80FD044: @ 80FD044
.string "The floor was drained!\0"
.align 2, 0

.global gUnknown_80FD05C
gUnknown_80FD05C: @ 80FD05C
@ replacing .incbin "baserom.gba", 0xFD05C, 0x4
.4byte gUnknown_80FD044

.global gUnknown_80FD060
gUnknown_80FD060: @ 80FD060
@ replacing .incbin "baserom.gba", 0xFD060, 0x2C
.4byte gUnknown_80FB568

.global gUnknown_80FD064
gUnknown_80FD064: @ 80FD064
.string "There is too much water to be drained!\0"
.align 2, 0

.global gUnknown_80FD08C
gUnknown_80FD08C: @ 80FD08C
@ replacing .incbin "baserom.gba", 0xFD08C, 0x28
.4byte gUnknown_80FD064

.global gUnknown_80FD090
gUnknown_80FD090: @ 80FD090
.string "It filled in the ground in front!\0"
.align 2, 0

.global gUnknown_80FD0B4
gUnknown_80FD0B4: @ 80FD0B4
@ replacing .incbin "baserom.gba", 0xFD0B4, 0x4
.4byte gUnknown_80FD090

.global gUnknown_80FD0B8
gUnknown_80FD0B8: @ 80FD0B8
@ replacing .incbin "baserom.gba", 0xFD0B8, 0x4C
.4byte gUnknown_80FB568

.global gUnknown_80FD0BC
gUnknown_80FD0BC: @ 80FD0BC
.string "The stairs were located!\0"
.align 2, 0
.4byte gUnknown_80FD0BC
.4byte gUnknown_80F7F20
.4byte gUnknown_80F7F20
.4byte gUnknown_80F7F20

.global gUnknown_80FD0E8
gUnknown_80FD0E8: @ 80FD0E8
.string "The barrier was shattered!\0"
.align 2, 0

.global gUnknown_80FD104
gUnknown_80FD104: @ 80FD104
@ replacing .incbin "baserom.gba", 0xFD104, 0x24
.4byte gUnknown_80FD0E8

.global gUnknown_80FD108
gUnknown_80FD108: @ 80FD108
.string "It can only be used on water!\0"
.align 2, 0

.global gUnknown_80FD128
gUnknown_80FD128: @ 80FD128
@ replacing .incbin "baserom.gba", 0xFD128, 0x24
.4byte gUnknown_80FD108

.global gUnknown_80FD12C
gUnknown_80FD12C: @ 80FD12C
.string "It can only be used on land!\0"
.align 2, 0

.global gUnknown_80FD14C
gUnknown_80FD14C: @ 80FD14C
@ replacing .incbin "baserom.gba", 0xFD14C, 0x24
.4byte gUnknown_80FD12C

.global gUnknown_80FD150
gUnknown_80FD150: @ 80FD150
.string "{ARG_POKEMON_1}'s item was swatted down!\0"
.align 2, 0

.global gUnknown_80FD170
gUnknown_80FD170: @ 80FD170
@ replacing .incbin "baserom.gba", 0xFD170, 0x1C
.4byte gUnknown_80FD150

.global gUnknown_80FD174
gUnknown_80FD174: @ 80FD174
.string "The target has no item!\0"
.align 2, 0

.global gUnknown_80FD18C
gUnknown_80FD18C: @ 80FD18C
@ replacing .incbin "baserom.gba", 0xFD18C, 0x24
.4byte gUnknown_80FD174

.global gUnknown_80FD190
gUnknown_80FD190: @ 80FD190
.string "Nearby traps were destroyed!\0"
.align 2, 0

.global gUnknown_80FD1B0
gUnknown_80FD1B0: @ 80FD1B0
@ replacing .incbin "baserom.gba", 0xFD1B0, 0x1C
.4byte gUnknown_80FD190

.global gUnknown_80FD1B4
gUnknown_80FD1B4: @ 80FD1B4
.string "There were no traps.\0"
.align 2, 0

.global gUnknown_80FD1CC
gUnknown_80FD1CC: @ 80FD1CC
@ replacing .incbin "baserom.gba", 0xFD1CC, 0x20
.4byte gUnknown_80FD1B4

.global gUnknown_80FD1D0
gUnknown_80FD1D0: @ 80FD1D0
.string "It can't be used here.\0"
.align 2, 0

.global gUnknown_80FD1EC
gUnknown_80FD1EC: @ 80FD1EC
@ replacing .incbin "baserom.gba", 0xFD1EC, 0x20
.4byte gUnknown_80FD1D0

.global gUnknown_80FD1F0
gUnknown_80FD1F0: @ 80FD1F0
.string "{ARG_POKEMON_1} can throw a long way!\0"
.align 2, 0

.global gUnknown_80FD20C
gUnknown_80FD20C: @ 80FD20C
@ replacing .incbin "baserom.gba", 0xFD20C, 0x20
.4byte gUnknown_80FD1F0

.global gUnknown_80FD210
gUnknown_80FD210: @ 80FD210
.string "{ARG_POKEMON_1} can throw far already!\0"
.align 2, 0

.global gUnknown_80FD22C
gUnknown_80FD22C: @ 80FD22C
@ replacing .incbin "baserom.gba", 0xFD22C, 0x28
.4byte gUnknown_80FD210

.global gUnknown_80FD230
gUnknown_80FD230: @ 80FD230
.string "{ARG_POKEMON_1}'s throws can pierce things!\0"
.align 2, 0

.global gUnknown_80FD254
gUnknown_80FD254: @ 80FD254
@ replacing .incbin "baserom.gba", 0xFD254, 0x28
.4byte gUnknown_80FD230

.global gUnknown_80FD258
gUnknown_80FD258: @ 80FD258
.string "{ARG_POKEMON_1}'s throws can pierce already!\0"
.align 2, 0

.global gUnknown_80FD27C
gUnknown_80FD27C: @ 80FD27C
@ replacing .incbin "baserom.gba", 0xFD27C, 0x18
.4byte gUnknown_80FD258

.global gUnknown_80FD280
gUnknown_80FD280: @ 80FD280
.string "{ARG_POKEMON_1} bears a grudge!\0"
.align 2, 0

.global gUnknown_80FD294
gUnknown_80FD294: @ 80FD294
@ replacing .incbin "baserom.gba", 0xFD294, 0x20
.4byte gUnknown_80FD280

.global gUnknown_80FD298
gUnknown_80FD298: @ 80FD298
.string "{ARG_POKEMON_1} already bears a grudge!\0"
.align 2, 0

.global gUnknown_80FD2B4
gUnknown_80FD2B4: @ 80FD2B4
@ replacing .incbin "baserom.gba", 0xFD2B4, 0x18
.4byte gUnknown_80FD298

.global gUnknown_80FD2B8
gUnknown_80FD2B8: @ 80FD2B8
.string "It's a grudge!\0"
.align 2, 0

.global gUnknown_80FD2CC
gUnknown_80FD2CC: @ 80FD2CC
@ replacing .incbin "baserom.gba", 0xFD2CC, 0x10
.4byte gUnknown_80FD2B8

.global gUnknown_80FD2D0
gUnknown_80FD2D0: @ 80FD2D0
.string "Assist: {ARG_MOVE_ITEM_0}\0"
.align 2, 0

.global gUnknown_80FD2DC
gUnknown_80FD2DC: @ 80FD2DC
@ replacing .incbin "baserom.gba", 0xFD2DC, 0x1C
.4byte gUnknown_80FD2D0

.global gUnknown_80FD2E0
gUnknown_80FD2E0: @ 80FD2E0
.string "All traps were exposed!\0"
.align 2, 0

.global gUnknown_80FD2F8
gUnknown_80FD2F8: @ 80FD2F8
@ replacing .incbin "baserom.gba", 0xFD2F8, 0x28
.4byte gUnknown_80FD2E0

.global gUnknown_80FD2FC
gUnknown_80FD2FC: @ 80FD2FC
.string "There appear to be no hidden traps.\0"
.align 2, 0

.global gUnknown_80FD320
gUnknown_80FD320: @ 80FD320
@ replacing .incbin "baserom.gba", 0xFD320, 0x30
.4byte gUnknown_80FD2FC

.global gUnknown_80FD324
gUnknown_80FD324: @ 80FD324
.string "The last move used by {ARG_POKEMON_1} lost\n"
.string "all its PP!\0"
.align 2, 0

.global gUnknown_80FD350
gUnknown_80FD350: @ 80FD350
@ replacing .incbin "baserom.gba", 0xFD350, 0x20
.4byte gUnknown_80FD324

.global gUnknown_80FD354
gUnknown_80FD354: @ 80FD354
.string "Nothing happened to {ARG_POKEMON_1}.\0"
.align 2, 0

.global gUnknown_80FD370
gUnknown_80FD370: @ 80FD370
@ replacing .incbin "baserom.gba", 0xFD370, 0x30
.4byte gUnknown_80FD354

.global gUnknown_80FD374
gUnknown_80FD374: @ 80FD374
.string "The walls crumbled, making one big room!\0"
.align 2, 0

.global gUnknown_80FD3A0
gUnknown_80FD3A0: @ 80FD3A0
@ replacing .incbin "baserom.gba", 0xFD3A0, 0x28
.4byte gUnknown_80FD374

.global gUnknown_80FD3A4
gUnknown_80FD3A4: @ 80FD3A4
.string "This floor is already one big room!\0"
.align 2, 0

.global gUnknown_80FD3C8
gUnknown_80FD3C8: @ 80FD3C8
@ replacing .incbin "baserom.gba", 0xFD3C8, 0x4
.4byte gUnknown_80FD3A4

.global gUnknown_80FD3CC
gUnknown_80FD3CC: @ 80FD3CC
@ replacing .incbin "baserom.gba", 0xFD3CC, 0x4
.4byte gUnknown_80FD1D0

.global gUnknown_80FD3D0
gUnknown_80FD3D0: @ 80FD3D0
@ replacing .incbin "baserom.gba", 0xFD3D0, 0x20
.4byte gUnknown_80FD1D0

.global gUnknown_80FD3D4
gUnknown_80FD3D4: @ 80FD3D4
.string "It dug the wall in front!\0"
.align 2, 0

.global gUnknown_80FD3F0
gUnknown_80FD3F0: @ 80FD3F0
@ replacing .incbin "baserom.gba", 0xFD3F0, 0x1C
.4byte gUnknown_80FD3D4

.global gUnknown_80FD3F4
gUnknown_80FD3F4: @ 80FD3F4
.string "Can't use that here!\0"
.align 2, 0

.global gUnknown_80FD40C
gUnknown_80FD40C: @ 80FD40C
@ replacing .incbin "baserom.gba", 0xFD40C, 0x24
.4byte gUnknown_80FD3F4

.global gUnknown_80FD410
gUnknown_80FD410: @ 80FD410
.string "Can't use that diagonally!\0"
.align 2, 0

.global gUnknown_80FD430
gUnknown_80FD430: @ 80FD430
@ replacing .incbin "baserom.gba", 0xFD430, 0x4
.4byte gUnknown_80FD410

.global gUnknown_80FD434
gUnknown_80FD434: @ 80FD434
@ replacing .incbin "baserom.gba", 0xFD434, 0x1C
.4byte gUnknown_80FBEA4

.global gUnknown_80FD438
gUnknown_80FD438: @ 80FD438
.string "{ARG_POKEMON_0} can't transform!\0"
.align 2, 0

.global gUnknown_80FD450
gUnknown_80FD450: @ 80FD450
@ replacing .incbin "baserom.gba", 0xFD450, 0x4
.4byte gUnknown_80FD438

.global gUnknown_80FD454
gUnknown_80FD454: @ 80FD454
@ replacing .incbin "baserom.gba", 0xFD454, 0x18
.4byte gUnknown_80FB568

.global gUnknown_80FD458
gUnknown_80FD458: @ 80FD458
.string "{ARG_POKEMON_1} was revived!\0"
.align 2, 0

.global gUnknown_80FD46C
gUnknown_80FD46C: @ 80FD46C
@ replacing .incbin "baserom.gba", 0xFD46C, 0x18
.4byte gUnknown_80FD458

.global gUnknown_80FD470
gUnknown_80FD470: @ 80FD470
.string "{ARG_POKEMON_0} possessed {ARG_POKEMON_1}!\0"
.align 2, 0

.global gUnknown_80FD484
gUnknown_80FD484: @ 80FD484
@ replacing .incbin "baserom.gba", 0xFD484, 0x2C
.4byte gUnknown_80FD470

.global gUnknown_80FD488
gUnknown_80FD488: @ 80FD488
.string "The target's stench is overwhelming!\0"
.align 2, 0

.global gUnknown_80FD4B0
gUnknown_80FD4B0: @ 80FD4B0
@ replacing .incbin "baserom.gba", 0xFD4B0, 0x14
.4byte gUnknown_80FD488

.global gUnknown_80FD4B4
gUnknown_80FD4B4: @ 80FD4B4
.string "{ARG_POKEMON_0} escaped!\0"
.align 2, 0

.global gUnknown_80FD4C4
gUnknown_80FD4C4: @ 80FD4C4
@ replacing .incbin "baserom.gba", 0xFD4C4, 0x18
.4byte gUnknown_80FD4B4

.global gUnknown_80FD4C8
gUnknown_80FD4C8: @ 80FD4C8
.string "{ARG_POKEMON_0} can't escape!\0"
.align 2, 0

.global gUnknown_80FD4DC
gUnknown_80FD4DC: @ 80FD4DC
@ replacing .incbin "baserom.gba", 0xFD4DC, 0x24
.4byte gUnknown_80FD4C8

.global gUnknown_80FD4E0
gUnknown_80FD4E0: @ 80FD4E0
.string "{ARG_POKEMON_0} was protected by its Band!\0"
.align 2, 0

.global gUnknown_80FD500
gUnknown_80FD500: @ 80FD500
@ replacing .incbin "baserom.gba", 0xFD500, 0x24
.4byte gUnknown_80FD4E0

.global gUnknown_80FD504
gUnknown_80FD504: @ 80FD504
.string "{ARG_POKEMON_0} was protected by its Scarf!\0"
.align 2, 0

.global gUnknown_80FD524
gUnknown_80FD524: @ 80FD524
@ replacing .incbin "baserom.gba", 0xFD524, 0x24
.4byte gUnknown_80FD504

.global gUnknown_80FD528
gUnknown_80FD528: @ 80FD528
.string "{ARG_POKEMON_0} was protected by its Scope!\0"
.align 2, 0

.global gUnknown_80FD548
gUnknown_80FD548: @ 80FD548
@ replacing .incbin "baserom.gba", 0xFD548, 0x8
.4byte gUnknown_80FD528
.4byte gUnknown_80FD528

.global gUnknown_80FD550
gUnknown_80FD550: @ 80FD550
@ replacing .incbin "baserom.gba", 0xFD550, 0x24
.4byte gUnknown_80FD4E0

.global gUnknown_80FD554
gUnknown_80FD554: @ 80FD554
.string "{ARG_POKEMON_1} was protected by its Specs!\0"
.align 2, 0

.global gUnknown_80FD574
gUnknown_80FD574: @ 80FD574
@ replacing .incbin "baserom.gba", 0xFD574, 0x4
.4byte gUnknown_80FD554

.global gUnknown_80FD578
gUnknown_80FD578: @ 80FD578
@ replacing .incbin "baserom.gba", 0xFD578, 0x4
.4byte gUnknown_80FD554

.global gUnknown_80FD57C
gUnknown_80FD57C: @ 80FD57C
@ replacing .incbin "baserom.gba", 0xFD57C, 0x18
.4byte gUnknown_80FD554

.global gUnknown_80FD580
gUnknown_80FD580: @ 80FD580
.string "Getting hungry...\0"
.align 2, 0

.global gUnknown_80FD594
gUnknown_80FD594: @ 80FD594
@ replacing .incbin "baserom.gba", 0xFD594, 0x24
.4byte gUnknown_80FD580

.global gUnknown_80FD598
gUnknown_80FD598: @ 80FD598
.string "Getting dizzy from hunger...\0"
.align 2, 0

.global gUnknown_80FD5B8
gUnknown_80FD5B8: @ 80FD5B8
@ replacing .incbin "baserom.gba", 0xFD5B8, 0x24
.4byte gUnknown_80FD598

.global gUnknown_80FD5BC
gUnknown_80FD5BC: @ 80FD5BC
.string "Oh, no! Your Belly's empty!\0"
.align 2, 0

.global gUnknown_80FD5DC
gUnknown_80FD5DC: @ 80FD5DC
@ replacing .incbin "baserom.gba", 0xFD5DC, 0x2C
.4byte gUnknown_80FD5BC

.global gUnknown_80FD5E0
gUnknown_80FD5E0: @ 80FD5E0
.string "Hurry! You've got to eat something!\0"
.align 2, 0

.global gUnknown_80FD608
gUnknown_80FD608: @ 80FD608
@ replacing .incbin "baserom.gba", 0xFD608, 0x20
.4byte gUnknown_80FD5E0

.global gUnknown_80FD60C
gUnknown_80FD60C: @ 80FD60C
.string "You'll faint from hunger!\0"
.align 2, 0

.global gUnknown_80FD628
gUnknown_80FD628: @ 80FD628
@ replacing .incbin "baserom.gba", 0xFD628, 0x1C
.4byte gUnknown_80FD60C

.global gUnknown_80FD62C
gUnknown_80FD62C: @ 80FD62C
.string "Its IQ didn't change.\0"
.align 2, 0

.global gUnknown_80FD644
gUnknown_80FD644: @ 80FD644
@ replacing .incbin "baserom.gba", 0xFD644, 0x4
.4byte gUnknown_80FD62C

.global gUnknown_80FD648
gUnknown_80FD648: @ 80FD648
@ replacing .incbin "baserom.gba", 0xFD648, 0xA0
.4byte gUnknown_80FD6C8
.4byte gUnknown_80FD6A8
.4byte gUnknown_80FD67C
.4byte gUnknown_80FD658

.global gUnknown_80FD658
gUnknown_80FD658: @ 80FD658
.string "It seemed to be somewhat satisfied.\0"
.align 2, 0

.global gUnknown_80FD67C
gUnknown_80FD67C: @ 80FD67C
.string "It doesn't seem to dislike this Gummi.\0"
.align 2, 0

.global gUnknown_80FD6A8
gUnknown_80FD6A8: @ 80FD6A8
.string "It seems to like this Gummi!\0"
.align 2, 0

.global gUnknown_80FD6C8
gUnknown_80FD6C8: @ 80FD6C8
.string "It seems to love this Gummi!\0"
.align 2, 0

.global gUnknown_80FD6E8
gUnknown_80FD6E8: @ 80FD6E8
@ replacing .incbin "baserom.gba", 0xFD6E8, 0xA0
.4byte gUnknown_80FD75C
.4byte gUnknown_80FD740
.4byte gUnknown_80FD728
.4byte gUnknown_80FD710
.4byte gUnknown_80FD6FC

.global gUnknown_80FD6FC
gUnknown_80FD6FC: @ 80FD6FC
.string "IQ didn't change.\0"
.align 2, 0

.global gUnknown_80FD710
gUnknown_80FD710: @ 80FD710
.string "IQ went up slightly!\0"
.align 2, 0

.global gUnknown_80FD728
gUnknown_80FD728: @ 80FD728
.string "IQ went up somewhat!\0"
.align 2, 0

.global gUnknown_80FD740
gUnknown_80FD740: @ 80FD740
.string "IQ went up significantly!\0"
.align 2, 0

.global gUnknown_80FD75C
gUnknown_80FD75C: @ 80FD75C
.string "IQ rose sharply!\0"
.align 2, 0

.global gUnknown_80FD770
gUnknown_80FD770: @ 80FD770
.string "A food item went bad.\0"
.align 2, 0

.global gUnknown_80FD788
gUnknown_80FD788: @ 80FD788
@ replacing .incbin "baserom.gba", 0xFD788, 0x24
.4byte gUnknown_80FD770

.global gUnknown_80FD78C
gUnknown_80FD78C: @ 80FD78C
.string "Several food items went bad.\0"
.align 2, 0

.global gUnknown_80FD7AC
gUnknown_80FD7AC: @ 80FD7AC
@ replacing .incbin "baserom.gba", 0xFD7AC, 0x28
.4byte gUnknown_80FD78C

.global gUnknown_80FD7B0
gUnknown_80FD7B0: @ 80FD7B0
.string "Nothing particularly bad happened.\0"
.align 2, 0

.global gUnknown_80FD7D4
gUnknown_80FD7D4: @ 80FD7D4
@ replacing .incbin "baserom.gba", 0xFD7D4, 0x20
.4byte gUnknown_80FD7B0

.global gUnknown_80FD7D8
gUnknown_80FD7D8: @ 80FD7D8
.string "Stepped on something weird!\0"
.align 2, 0

.global gUnknown_80FD7F4
gUnknown_80FD7F4: @ 80FD7F4
@ replacing .incbin "baserom.gba", 0xFD7F4, 0x4
.4byte gUnknown_80FD7D8

.global gUnknown_80FD7F8
gUnknown_80FD7F8: @ 80FD7F8
@ replacing .incbin "baserom.gba", 0xFD7F8, 0x288
.4byte gUnknown_80FDA48
.4byte gUnknown_80FDA28
.4byte gUnknown_80FDA0C
.4byte gUnknown_80FD9E8
.4byte gUnknown_80FD9BC
.4byte gUnknown_80FD9B4
.4byte gUnknown_80FD9A0
.4byte gUnknown_80FD98C
.4byte gUnknown_80FD974
.4byte gUnknown_80FD95C
.4byte gUnknown_80FD944
.4byte gUnknown_80FD92C
.4byte gUnknown_80FD914
.4byte gUnknown_80FD8F4
.4byte gUnknown_80FD8D4
.4byte gUnknown_80FD8B8
.4byte gUnknown_80FD89C
.4byte gUnknown_80FD880
.4byte gUnknown_80FD864
.4byte gUnknown_80FD848

.global gUnknown_80FD848
gUnknown_80FD848: @ 80FD848
.string "Stepped on a Spiked Tile!\0"
.align 2, 0

.global gUnknown_80FD864
gUnknown_80FD864: @ 80FD864
.string "Stepped on a Pokémon Trap!\0"
.align 2, 0

.global gUnknown_80FD880
gUnknown_80FD880: @ 80FD880
.string "Stepped on a Wonder Tile!\0"
.align 2, 0

.global gUnknown_80FD89C
gUnknown_80FD89C: @ 80FD89C
.string "Stepped on a Chestnut Trap!\0"
.align 2, 0

.global gUnknown_80FD8B8
gUnknown_80FD8B8: @ 80FD8B8
.string "Stepped on a PP-Zero Trap!\0"
.align 2, 0

.global gUnknown_80FD8D4
gUnknown_80FD8D4: @ 80FD8D4
.string "Stepped on an Explosion Trap!\0"
.align 2, 0

.global gUnknown_80FD8F4
gUnknown_80FD8F4: @ 80FD8F4
.string "Stepped on a Selfdestruct Trap!\0"
.align 2, 0

.global gUnknown_80FD914
gUnknown_80FD914: @ 80FD914
.string "Poison spikes shot out!\0"
.align 2, 0

.global gUnknown_80FD92C
gUnknown_80FD92C: @ 80FD92C
.string "Stepped on a Seal Trap!\0"
.align 2, 0

.global gUnknown_80FD944
gUnknown_80FD944: @ 80FD944
.string "Stepped on a Slow Trap!\0"
.align 2, 0

.global gUnknown_80FD95C
gUnknown_80FD95C: @ 80FD95C
.string "Sleeping gas erupted!\0"
.align 2, 0

.global gUnknown_80FD974
gUnknown_80FD974: @ 80FD974
.string "The trap spun around!\0"
.align 2, 0

.global gUnknown_80FD98C
gUnknown_80FD98C: @ 80FD98C
.string "A sudden gust blew!\0"
.align 2, 0

.global gUnknown_80FD9A0
gUnknown_80FD9A0: @ 80FD9A0
.string "Stepped on a {ARG_POKEMON_0}!\0"
.align 2, 0

.global gUnknown_80FD9B4
gUnknown_80FD9B4: @ 80FD9B4
.string "{ARG_POKEMON_0}!\0"
.align 2, 0

.global gUnknown_80FD9BC
gUnknown_80FD9BC: @ 80FD9BC
.string "A sweet, Pokémon-attracting aroma\n"
.string "spread!\0"
.align 2, 0

.global gUnknown_80FD9E8
gUnknown_80FD9E8: @ 80FD9E8
.string "Sludge splashed up from the ground!\0"
.align 2, 0

.global gUnknown_80FDA0C
gUnknown_80FDA0C: @ 80FDA0C
.string "Stepped on a Sticky Trap!\0"
.align 2, 0

.global gUnknown_80FDA28
gUnknown_80FDA28: @ 80FDA28
.string "Mud splashed up from the {ARG_POKEMON_0}!\0"
.align 2, 0

.global gUnknown_80FDA48
gUnknown_80FDA48: @ 80FDA48
.string "There was a {ARG_POKEMON_0} underfoot!\0"
.align 2, 0

.global gUnknown_80FDA64
gUnknown_80FDA64: @ 80FDA64
.string "The move {ARG_MOVE_ITEM_0} lost its PP!\0"
.align 2, 0

.global gUnknown_80FDA80
gUnknown_80FDA80: @ 80FDA80
@ replacing .incbin "baserom.gba", 0xFDA80, 0x20
.4byte gUnknown_80FDA64

.global gUnknown_80FDA84
gUnknown_80FDA84: @ 80FDA84
.string "All PP are already gone!\0"
.align 2, 0

.global gUnknown_80FDAA0
gUnknown_80FDAA0: @ 80FDAA0
@ replacing .incbin "baserom.gba", 0xFDAA0, 0x2C
.4byte gUnknown_80FDA84

.global gUnknown_80FDAA4
gUnknown_80FDAA4: @ 80FDAA4
.string "Unclaimed items turned into Pokémon!\0"
.align 2, 0

.global gUnknown_80FDACC
gUnknown_80FDACC: @ 80FDACC
@ replacing .incbin "baserom.gba", 0xFDACC, 0x18
.4byte gUnknown_80FDAA4

.global gUnknown_80FDAD0
gUnknown_80FDAD0: @ 80FDAD0
.string "Nothing happened!\0"
.align 2, 0

.global gUnknown_80FDAE4
gUnknown_80FDAE4: @ 80FDAE4
@ replacing .incbin "baserom.gba", 0xFDAE4, 0x20
.4byte gUnknown_80FDAD0

.global gUnknown_80FDAE8
gUnknown_80FDAE8: @ 80FDAE8
.string "The move {ARG_MOVE_ITEM_0} was sealed!\0"
.align 2, 0

.global gUnknown_80FDB04
gUnknown_80FDB04: @ 80FDB04
@ replacing .incbin "baserom.gba", 0xFDB04, 0x28
.4byte gUnknown_80FDAE8

.global gUnknown_80FDB08
gUnknown_80FDB08: @ 80FDB08
.string "All the moves are sealed already!\0"
.align 2, 0

.global gUnknown_80FDB2C
gUnknown_80FDB2C: @ 80FDB2C
@ replacing .incbin "baserom.gba", 0xFDB2C, 0x30
.4byte gUnknown_80FDB08

.global gUnknown_80FDB30
gUnknown_80FDB30: @ 80FDB30
.string "Its Scarf stopped the trap from\n"
.string "springing!\0"
.align 2, 0

.global gUnknown_80FDB5C
gUnknown_80FDB5C: @ 80FDB5C
@ replacing .incbin "baserom.gba", 0xFDB5C, 0x20
.4byte gUnknown_80FDB30

.global gUnknown_80FDB60
gUnknown_80FDB60: @ 80FDB60
.string "The trap failed to work!\0"
.align 2, 0

.global gUnknown_80FDB7C
gUnknown_80FDB7C: @ 80FDB7C
@ replacing .incbin "baserom.gba", 0xFDB7C, 0x24
.4byte gUnknown_80FDB60

.global gUnknown_80FDB80
gUnknown_80FDB80: @ 80FDB80
.string "But there is no one in the way!\0"
.align 2, 0

.global gUnknown_80FDBA0
gUnknown_80FDBA0: @ 80FDBA0
@ replacing .incbin "baserom.gba", 0xFDBA0, 0x18
.4byte gUnknown_80FDB80

.global gUnknown_80FDBA4
gUnknown_80FDBA4: @ 80FDBA4
.string "{ARG_POKEMON_0} caught the {ARG_MOVE_ITEM_0}!\0"
.align 2, 0

.global gUnknown_80FDBB8
gUnknown_80FDBB8: @ 80FDBB8
@ replacing .incbin "baserom.gba", 0xFDBB8, 0x18
.4byte gUnknown_80FDBA4

.global gUnknown_80FDBBC
gUnknown_80FDBBC: @ 80FDBBC
.string "{ARG_POKEMON_0} regained PP.\0"
.align 2, 0

.global gUnknown_80FDBD0
gUnknown_80FDBD0: @ 80FDBD0
@ replacing .incbin "baserom.gba", 0xFDBD0, 0x20
.4byte gUnknown_80FDBBC

.global gUnknown_80FDBD4
gUnknown_80FDBD4: @ 80FDBD4
.string "{ARG_POKEMON_0} has full PP already!\0"
.align 2, 0

.global gUnknown_80FDBF0
gUnknown_80FDBF0: @ 80FDBF0
@ replacing .incbin "baserom.gba", 0xFDBF0, 0x28
.4byte gUnknown_80FDBD4

.global gUnknown_80FDBF4
gUnknown_80FDBF4: @ 80FDBF4
.string "The {ARG_MOVE_ITEM_0} became sticky and\n"
.string "unusable!\0"
.align 2, 0

.global gUnknown_80FDC18
gUnknown_80FDC18: @ 80FDC18
@ replacing .incbin "baserom.gba", 0xFDC18, 0x28
.4byte gUnknown_80FDBF4

.global gUnknown_80FDC1C
gUnknown_80FDC1C: @ 80FDC1C
.string "But nothing happened in particular.\0"
.align 2, 0

.global gUnknown_80FDC40
gUnknown_80FDC40: @ 80FDC40
@ replacing .incbin "baserom.gba", 0xFDC40, 0x3C
.4byte gUnknown_80FDC1C

.global gUnknown_80FDC44
gUnknown_80FDC44: @ 80FDC44
.string "The No-Stick Cap prevented items from\n"
.string "getting sticky!\0"
.align 2, 0

.global gUnknown_80FDC7C
gUnknown_80FDC7C: @ 80FDC7C
@ replacing .incbin "baserom.gba", 0xFDC7C, 0x20
.4byte gUnknown_80FDC44

.global gUnknown_80FDC80
gUnknown_80FDC80: @ 80FDC80
.string "The used TM was recharged!\0"
.align 2, 0

.global gUnknown_80FDC9C
gUnknown_80FDC9C: @ 80FDC9C
@ replacing .incbin "baserom.gba", 0xFDC9C, 0x4
.4byte gUnknown_80FDC80

.global gUnknown_80FDCA0
gUnknown_80FDCA0: @ 80FDCA0
@ replacing .incbin "baserom.gba", 0xFDCA0, 0x4
.4byte gUnknown_80FB568

.global gUnknown_80FDCA4
gUnknown_80FDCA4: @ 80FDCA4
@ replacing .incbin "baserom.gba", 0xFDCA4, 0x24
.4byte gUnknown_80FC700

.global gUnknown_80FDCA8
gUnknown_80FDCA8: @ 80FDCA8
.string "{ARG_POKEMON_0} converted to\n"
.string "the {ARG_MOVE_ITEM_0} type!\0"
.align 2, 0

.global gUnknown_80FDCC8
gUnknown_80FDCC8: @ 80FDCC8
@ replacing .incbin "baserom.gba", 0xFDCC8, 0x1C
.4byte gUnknown_80FDCA8

.global gUnknown_80FDCCC
gUnknown_80FDCCC: @ 80FDCCC
.string "{ARG_POKEMON_0} mimicked its foe!\0"
.align 2, 0

.global gUnknown_80FDCE4
gUnknown_80FDCE4: @ 80FDCE4
@ replacing .incbin "baserom.gba", 0xFDCE4, 0x1C
.4byte gUnknown_80FDCCC

.global gUnknown_80FDCE8
gUnknown_80FDCE8: @ 80FDCE8
.string "{ARG_POKEMON_0}'s Mimic failed!\0"
.align 2, 0

.global gUnknown_80FDD00
gUnknown_80FDD00: @ 80FDD00
@ replacing .incbin "baserom.gba", 0xFDD00, 0x20
.4byte gUnknown_80FDCE8

.global gUnknown_80FDD04
gUnknown_80FDD04: @ 80FDD04
.string "The move was passed off!\0"
.align 2, 0

.global gUnknown_80FDD20
gUnknown_80FDD20: @ 80FDD20
@ replacing .incbin "baserom.gba", 0xFDD20, 0x28
.4byte gUnknown_80FDD04

.global gUnknown_80FDD24
gUnknown_80FDD24: @ 80FDD24
.string "There's no one to pass off to!\0"
.align 2, 0

.global gUnknown_80FDD48
gUnknown_80FDD48: @ 80FDD48
@ replacing .incbin "baserom.gba", 0xFDD48, 0x40
.4byte gUnknown_80FDD24

.global gUnknown_80FDD4C
gUnknown_80FDD4C: @ 80FDD4C
.string "A mysterious force prevents moves\n"
.string "from being passed off!\0"
.align 2, 0

.global gUnknown_80FDD88
gUnknown_80FDD88: @ 80FDD88
@ replacing .incbin "baserom.gba", 0xFDD88, 0x20
.4byte gUnknown_80FDD4C

.global gUnknown_80FDD8C
gUnknown_80FDD8C: @ 80FDD8C
.string "The attack was passed off!\0"
.align 2, 0

.global gUnknown_80FDDA8
gUnknown_80FDDA8: @ 80FDDA8
@ replacing .incbin "baserom.gba", 0xFDDA8, 0x4
.4byte gUnknown_80FDD8C

.global gUnknown_80FDDAC
gUnknown_80FDDAC: @ 80FDDAC
@ replacing .incbin "baserom.gba", 0xFDDAC, 0x24
.4byte gUnknown_80FDD24

.global gUnknown_80FDDB0
gUnknown_80FDDB0: @ 80FDDB0
.string "The closed corridor was opened!\0"
.align 2, 0

.global gUnknown_80FDDD0
gUnknown_80FDDD0: @ 80FDDD0
@ replacing .incbin "baserom.gba", 0xFDDD0, 0x20
.4byte gUnknown_80FDDB0

.global gUnknown_80FDDD4
gUnknown_80FDDD4: @ 80FDDD4
.string "It can't be used here!\0"
.align 2, 0

.global gUnknown_80FDDF0
gUnknown_80FDDF0: @ 80FDDF0
@ replacing .incbin "baserom.gba", 0xFDDF0, 0x28
.4byte gUnknown_80FDDD4

.global gUnknown_80FDDF4
gUnknown_80FDDF4: @ 80FDDF4
.string "There is nothing at {ARG_POKEMON_0}'s feet.\0"
.align 2, 0

.global gUnknown_80FDE18
gUnknown_80FDE18: @ 80FDE18
@ replacing .incbin "baserom.gba", 0xFDE18, 0x54
.4byte gUnknown_80FDDF4

.global gUnknown_80FDE1C
gUnknown_80FDE1C: @ 80FDE1C
.string "Your adventure to this point will be saved\n"
.string "in preparation for shutting down.\0"
.align 2, 0

.global gUnknown_80FDE6C
gUnknown_80FDE6C: @ 80FDE6C
@ replacing .incbin "baserom.gba", 0xFDE6C, 0x4C
.4byte gUnknown_80FDE1C

.global gUnknown_80FDE70
gUnknown_80FDE70: @ 80FDE70
.string "Give up on this adventure?\n"
.string "If you do, it will be treated as a defeat.\0"
.align 2, 0

.global gUnknown_80FDEB8
gUnknown_80FDEB8: @ 80FDEB8
@ replacing .incbin "baserom.gba", 0xFDEB8, 0x48
.4byte gUnknown_80FDE70

.global gUnknown_80FDEBC
gUnknown_80FDEBC: @ 80FDEBC
.string "Will the linked moves be forgotten,\n"
.string "including the selected {ARG_MOVE_ITEM_0}?\0"
.align 2, 0

.global gUnknown_80FDF00
gUnknown_80FDF00: @ 80FDF00
@ replacing .incbin "baserom.gba", 0xFDF00, 0x40
.4byte gUnknown_80FDEBC

.global gUnknown_80FDF04
gUnknown_80FDF04: @ 80FDF04
.string "Only four moves may be learned!\n"
.string "Will a move be forgotten?\0"
.align 2, 0

.global gUnknown_80FDF40
gUnknown_80FDF40: @ 80FDF40
@ replacing .incbin "baserom.gba", 0xFDF40, 0x30
.4byte gUnknown_80FDF04

.global gUnknown_80FDF44
gUnknown_80FDF44: @ 80FDF44
.string "The move {ARG_MOVE_ITEM_0} will be\n"
.string "forgotten.\n"
.string "Is that OK?\0"
.align 2, 0

.global gUnknown_80FDF70
gUnknown_80FDF70: @ 80FDF70
@ replacing .incbin "baserom.gba", 0xFDF70, 0x48
.4byte gUnknown_80FDF44

.global gUnknown_80FDF74
gUnknown_80FDF74: @ 80FDF74
.string "The chosen Pokémon will leave the Friend\n"
.string "Area forever.\n"
.string "Is that OK?\0"
.align 2, 0

.global gUnknown_80FDFB8
gUnknown_80FDFB8: @ 80FDFB8
@ replacing .incbin "baserom.gba", 0xFDFB8, 0x30
.4byte gUnknown_80FDF74

.global gUnknown_80FDFBC
gUnknown_80FDFBC: @ 80FDFBC
.string "{R_BUTTON} + {DPAD}: Shift moves\n"
.string "{SELECT_BUTTON}: Switch set moves\0"
.align 2, 0

.global gUnknown_80FDFE8
gUnknown_80FDFE8: @ 80FDFE8
@ replacing .incbin "baserom.gba", 0xFDFE8, 0x20
.4byte gUnknown_80FDFBC

.global gUnknown_80FDFEC
gUnknown_80FDFEC: @ 80FDFEC
.string "{ARG_POKEMON_0} can't talk just now.\0"
.align 2, 0

.global gUnknown_80FE008
gUnknown_80FE008: @ 80FE008
@ replacing .incbin "baserom.gba", 0xFE008, 0x2C
.4byte gUnknown_80FDFEC

.global gUnknown_80FE00C
gUnknown_80FE00C: @ 80FE00C
.string "There are no items that can be trawled!\0"
.align 2, 0

.global gUnknown_80FE034
gUnknown_80FE034: @ 80FE034
@ replacing .incbin "baserom.gba", 0xFE034, 0x2C
.4byte gUnknown_80FE00C

.global gUnknown_80FE038
gUnknown_80FE038: @ 80FE038
.string "All unclaimed items were drawn close!\0"
.align 2, 0

.global gUnknown_80FE060
gUnknown_80FE060: @ 80FE060
@ replacing .incbin "baserom.gba", 0xFE060, 0x4C
.4byte gUnknown_80FE038

.global gUnknown_80FE064
gUnknown_80FE064: @ 80FE064
.string "There is no room on your team to accept\n"
.string "the guest rescue team's {ARG_POKEMON_0}.\0"
.align 2, 0

.global gUnknown_80FE0AC
gUnknown_80FE0AC: @ 80FE0AC
@ replacing .incbin "baserom.gba", 0xFE0AC, 0x48
.4byte gUnknown_80FE064

.global gUnknown_80FE0B0
gUnknown_80FE0B0: @ 80FE0B0
.string "There is no room on your team to fit\n"
.string "the {ARG_POKEMON_0} that needs your help.\0"
.align 2, 0

.global gUnknown_80FE0F4
gUnknown_80FE0F4: @ 80FE0F4
@ replacing .incbin "baserom.gba", 0xFE0F4, 0x4
.4byte gUnknown_80FE0B0

.global gUnknown_80FE0F8
gUnknown_80FE0F8: @ 80FE0F8
@ replacing .incbin "baserom.gba", 0xFE0F8, 0x3C
.4byte gUnknown_80FE0B0

.global gUnknown_80FE0FC
gUnknown_80FE0FC: @ 80FE0FC
.string "The guest rescue team's {ARG_POKEMON_0}\n"
.string "joined your rescue team!\0"
.align 2, 0

.global gUnknown_80FE134
gUnknown_80FE134: @ 80FE134
@ replacing .incbin "baserom.gba", 0xFE134, 0x34
.4byte gUnknown_80FE0FC

.global gUnknown_80FE138
gUnknown_80FE138: @ 80FE138
.string "Your client, {ARG_POKEMON_0}, joined\n"
.string "your rescue team!\0"
.align 2, 0

.global gUnknown_80FE168
gUnknown_80FE168: @ 80FE168
@ replacing .incbin "baserom.gba", 0xFE168, 0x3C
.4byte gUnknown_80FE138

.global gUnknown_80FE16C
gUnknown_80FE16C: @ 80FE16C
.string "The Friend Area {ARG_MOVE_ITEM_0} is\n"
.string "full.\n"
.string "A friend must be released.\0"
.align 2, 0

.global gUnknown_80FE1A4
gUnknown_80FE1A4: @ 80FE1A4
@ replacing .incbin "baserom.gba", 0xFE1A4, 0x68
.4byte gUnknown_80FE16C

.global gUnknown_80FE1A8
gUnknown_80FE1A8: @ 80FE1A8
.string "If you dismiss this Pokémon,\n"
.string "it may never again join your rescue team.\n"
.string "Bid farewell to it anyway?\0"
.align 2, 0

.global gUnknown_80FE20C
gUnknown_80FE20C: @ 80FE20C
@ replacing .incbin "baserom.gba", 0xFE20C, 0x5C
.4byte gUnknown_80FE1A8

.global gUnknown_80FE210
gUnknown_80FE210: @ 80FE210
.string "Would you like to get help using a distress\n"
.string "call or get the password for getting\n"
.string "help?\0"
.align 2, 0

.global gUnknown_80FE268
gUnknown_80FE268: @ 80FE268
@ replacing .incbin "baserom.gba", 0xFE268, 0x24
.4byte gUnknown_80FE210

.global gUnknown_80FE26C
gUnknown_80FE26C: @ 80FE26C
.string "A call for help will be issued.\0"
.align 2, 0

.global gUnknown_80FE28C
gUnknown_80FE28C: @ 80FE28C
@ replacing .incbin "baserom.gba", 0xFE28C, 0x44
.4byte gUnknown_80FE26C

.global gUnknown_80FE290
gUnknown_80FE290: @ 80FE290
.string "Your rescue team is not eligible to\n"
.string "receive any more rescues.\0"
.align 2, 0

.global gUnknown_80FE2D0
gUnknown_80FE2D0: @ 80FE2D0
@ replacing .incbin "baserom.gba", 0xFE2D0, 0x1C
.4byte gUnknown_80FE290

.global gUnknown_80FE2D4
gUnknown_80FE2D4: @ 80FE2D4
.string "{ARG_POKEMON_0} evolved into {ARG_POKEMON_1}!\0"
.align 2, 0

.global gUnknown_80FE2EC
gUnknown_80FE2EC: @ 80FE2EC
@ replacing .incbin "baserom.gba", 0xFE2EC, 0x1C
.4byte gUnknown_80FE2D4

.global gUnknown_80FE2F0
gUnknown_80FE2F0: @ 80FE2F0
.string "It's a monster house!\0"
.align 2, 0

.global gPtrItsaMonsterHouseMessage
gPtrItsaMonsterHouseMessage: @ 80FE308
@ replacing .incbin "baserom.gba", 0xFE308, 0x28
.4byte gUnknown_80FE2F0

.global gUnknown_80FE30C
gUnknown_80FE30C: @ 80FE30C
.string "It became the move {ARG_MOVE_ITEM_0}'s type!\0"
.align 2, 0

.global gUnknown_80FE330
gUnknown_80FE330: @ 80FE330
@ replacing .incbin "baserom.gba", 0xFE330, 0x3C
.4byte gUnknown_80FE30C

.global gUnknown_80FE334
gUnknown_80FE334: @ 80FE334
.string "There were no moves that could be used\n"
.string "for Conversion!\0"
.align 2, 0

.global gUnknown_80FE36C
gUnknown_80FE36C: @ 80FE36C
@ replacing .incbin "baserom.gba", 0xFE36C, 0x20
.4byte gUnknown_80FE334

.global gUnknown_80FE370
gUnknown_80FE370: @ 80FE370
.string "The move {ARG_MOVE_ITEM_0} was sketched!\0"
.align 2, 0

.global gUnknown_80FE38C
gUnknown_80FE38C: @ 80FE38C
@ replacing .incbin "baserom.gba", 0xFE38C, 0x30
.4byte gUnknown_80FE370

.global gUnknown_80FE390
gUnknown_80FE390: @ 80FE390
.string "There were no moves that could be\n"
.string "sketched!\0"
.align 2, 0

.global gUnknown_80FE3BC
gUnknown_80FE3BC: @ 80FE3BC
@ replacing .incbin "baserom.gba", 0xFE3BC, 0x2C
.4byte gUnknown_80FE390

.global gUnknown_80FE3C0
gUnknown_80FE3C0: @ 80FE3C0
.string "{ARG_MOVE_ITEM_0} is all sticky!\n"
.string "It doesn't work!\0"
.align 2, 0

.global gItemStickyDoesntWorkText
gItemStickyDoesntWorkText: @ 80FE3E8
@ replacing .incbin "baserom.gba", 0xFE3E8, 0x24
.4byte gUnknown_80FE3C0

.global gUnknown_80FE3EC
gUnknown_80FE3EC: @ 80FE3EC
.string "{ARG_POKEMON_0} learned the move\n"
.string "{ARG_MOVE_ITEM_0}.\0"
.align 2, 0
.4byte gUnknown_80FE3EC

.global gUnknown_80FE40C
gUnknown_80FE40C: @ 80FE40C
@ replacing .incbin "baserom.gba", 0xFE40C, 0x28
.4byte gUnknown_80FB568

.global gUnknown_80FE410
gUnknown_80FE410: @ 80FE410
.string "Lucky! The move got a lot stronger!\0"
.align 2, 0

.global gUnknown_80FE434
gUnknown_80FE434: @ 80FE434
@ replacing .incbin "baserom.gba", 0xFE434, 0x20
.4byte gUnknown_80FE410

.global gUnknown_80FE438
gUnknown_80FE438: @ 80FE438
.string "The set move got stronger!\0"
.align 2, 0

.global gUnknown_80FE454
gUnknown_80FE454: @ 80FE454
@ replacing .incbin "baserom.gba", 0xFE454, 0x4
.4byte gUnknown_80FE438

.global gUnknown_80FE458
gUnknown_80FE458: @ 80FE458
@ replacing .incbin "baserom.gba", 0xFE458, 0x20
.4byte gUnknown_80FB568

.global gUnknown_80FE45C
gUnknown_80FE45C: @ 80FE45C
.string "{ARG_POKEMON_0} had second thoughts!\0"
.align 2, 0

.global gUnknown_80FE478
gUnknown_80FE478: @ 80FE478
@ replacing .incbin "baserom.gba", 0xFE478, 0x40
.4byte gUnknown_80FE45C

.global gUnknown_80FE47C
gUnknown_80FE47C: @ 80FE47C
.string "Help! Thief! I've been robbed!\n"
.string "Help me catch the thief!\0"
.align 2, 0

.global gUnknown_80FE4B8
gUnknown_80FE4B8: @ 80FE4B8
@ replacing .incbin "baserom.gba", 0xFE4B8, 0x1C
.4byte gUnknown_80FE47C

.global gUnknown_80FE4BC
gUnknown_80FE4BC: @ 80FE4BC
.string "Thank you so very much.\0"
.align 2, 0

.global gUnknown_80FE4D4
gUnknown_80FE4D4: @ 80FE4D4
@ replacing .incbin "baserom.gba", 0xFE4D4, 0x20
.4byte gUnknown_80FE4BC

.global gUnknown_80FE4D8
gUnknown_80FE4D8: @ 80FE4D8
.string "Your patronage is valued.\0"
.align 2, 0

.global gUnknown_80FE4F4
gUnknown_80FE4F4: @ 80FE4F4
@ replacing .incbin "baserom.gba", 0xFE4F4, 0x2C
.4byte gUnknown_80FE4D8

.global gUnknown_80FE4F8
gUnknown_80FE4F8: @ 80FE4F8
.string "You don't seem to have enough money.\0"
.align 2, 0

.global gUnknown_80FE520
gUnknown_80FE520: @ 80FE520
@ replacing .incbin "baserom.gba", 0xFE520, 0x48
.4byte gUnknown_80FE4F8

.global gUnknown_80FE524
gUnknown_80FE524: @ 80FE524
.string "The merchandise you have chosen\n"
.string "costs {ARG_VALUE_0} {POKE}.\n"
.string "Is that acceptable?\0"
.align 2, 0

.global gUnknown_80FE568
gUnknown_80FE568: @ 80FE568
@ replacing .incbin "baserom.gba", 0xFE568, 0x58
.4byte gUnknown_80FE524

.global gUnknown_80FE56C
gUnknown_80FE56C: @ 80FE56C
.string "For the merchandise you have left me,\n"
.string "I shall pay {ARG_VALUE_0} {POKE}.\n"
.string "Is that acceptable?\0"
.align 2, 0

.global gUnknown_80FE5C0
gUnknown_80FE5C0: @ 80FE5C0
@ replacing .incbin "baserom.gba", 0xFE5C0, 0x30
.4byte gUnknown_80FE56C

.global gUnknown_80FE5C4
gUnknown_80FE5C4: @ 80FE5C4
.string "I'm looking forward to serving you again!\0"
.align 2, 0

.global gUnknown_80FE5F0
gUnknown_80FE5F0: @ 80FE5F0
@ replacing .incbin "baserom.gba", 0xFE5F0, 0x4C
.4byte gUnknown_80FE5C4

.global gUnknown_80FE5F4
gUnknown_80FE5F4: @ 80FE5F4
.string "That is very disappointing.\n"
.string "Please return any items\n"
.string "before you leave...\0"
.align 2, 0

.global gUnknown_80FE63C
gUnknown_80FE63C: @ 80FE63C
@ replacing .incbin "baserom.gba", 0xFE63C, 0x20
.4byte gUnknown_80FE5F4

.global gUnknown_80FE640
gUnknown_80FE640: @ 80FE640
.string "I await your next visit.\0"
.align 2, 0

.global gUnknown_80FE65C
gUnknown_80FE65C: @ 80FE65C
@ replacing .incbin "baserom.gba", 0xFE65C, 0x18
.4byte gUnknown_80FE640

.global gUnknown_80FE660
gUnknown_80FE660: @ 80FE660
.string "Ah, welcome〜♪\0"
.align 2, 0

.global gUnknown_80FE674
gUnknown_80FE674: @ 80FE674
@ replacing .incbin "baserom.gba", 0xFE674, 0x1C
.4byte gUnknown_80FE660

.global gUnknown_80FE678
gUnknown_80FE678: @ 80FE678
.string "{ARG_POKEMON_0} was sent flying!\0"
.align 2, 0

.global gUnknown_80FE690
gUnknown_80FE690: @ 80FE690
@ replacing .incbin "baserom.gba", 0xFE690, 0x24
.4byte gUnknown_80FE678

.global gUnknown_80FE694
gUnknown_80FE694: @ 80FE694
.string "But it didn't go anywhere.\0"
.align 2, 0

.global gUnknown_80FE6B4
gUnknown_80FE6B4: @ 80FE6B4
@ replacing .incbin "baserom.gba", 0xFE6B4, 0x20
.4byte gUnknown_80FE694

.global gUnknown_80FE6B8
gUnknown_80FE6B8: @ 80FE6B8
.string "{ARG_POKEMON_0} can't throw items!\0"
.align 2, 0

.global gUnknown_80FE6D4
gUnknown_80FE6D4: @ 80FE6D4
@ replacing .incbin "baserom.gba", 0xFE6D4, 0x14
.4byte gUnknown_80FE6B8

.global gUnknown_80FE6D8
gUnknown_80FE6D8: @ 80FE6D8
.string "The Last Outing\0"
.align 2, 0

.global gUnknown_80FE6E8
gUnknown_80FE6E8: @ 80FE6E8
@ replacing .incbin "baserom.gba", 0xFE6E8, 0xC
.4byte gUnknown_80FE6D8

.global gUnknown_80FE6EC
gUnknown_80FE6EC: @ 80FE6EC
.string "Someone\0"
.align 2, 0

.global gUnknown_80FE6F4
gUnknown_80FE6F4: @ 80FE6F4
@ replacing .incbin "baserom.gba", 0xFE6F4, 0x14
.4byte gUnknown_80FE6EC

.global gUnknown_80FE6F8
gUnknown_80FE6F8: @ 80FE6F8
.string "Tile underfoot\0"
.align 2, 0

.global gUnknown_80FE708
gUnknown_80FE708: @ 80FE708
.4byte gUnknown_80FE6F8

.global gUnknown_80FE70C
gUnknown_80FE70C: @ 80FE70C
.4byte gUnknown_80F8128

.global gUnknown_80FE710
gUnknown_80FE710: @ 80FE710
.string "Rescue Point\0"
.align 2,0

.global gUnknown_80FE720
gUnknown_80FE720: @ 80FE720
.4byte gUnknown_80FE710
@ In Dungeon Game Options Menu

.global gUnknown_80FE724
gUnknown_80FE724: @ 80FE724
.4byte gUnknown_80F811C

.global OptionsDungeonText
OptionsDungeonText:
.string "Dungeon\0"
.align 2,0

.global gOptionsDungeonTextPtr
gOptionsDungeonTextPtr: @ 80FE730
.4byte OptionsDungeonText

.global OptionsOthersText
OptionsOthersText:

.global gUnknown_80FE734
gUnknown_80FE734: @ 80FE734
.string "Others\0"
.align 2,0

.global gOptionsOthersTextPtr
gOptionsOthersTextPtr: @ 80FE73C
.4byte OptionsOthersText

.global OptionsDefaultText
OptionsDefaultText:
.string "Default\0"
.align 2,0

.global gUnknown_80FE748
gUnknown_80FE748: @ 80FE748
.4byte OptionsDefaultText
@ Dungeon Game Options Menu

.global OptionsSpeed
OptionsSpeed:
.string "Speed{UNK_MACRO_3D M3D_80}Slow{UNK_MACRO_3D M3D_136}Fast\0"
.align 2,0

.global gUnknown_80FE764
gUnknown_80FE764: @ 80FE764
.4byte OptionsSpeed

.global OptionsFarOffPals
OptionsFarOffPals:
.string "Far-off pals{UNK_MACRO_3D M3D_80}Self{UNK_MACRO_3D M3D_136}Look\0"
.align 2,0

.global gUnknown_80FE788
gUnknown_80FE788: @ 80FE788
.4byte OptionsFarOffPals

.global OptionsDamageTurn
OptionsDamageTurn:
.string "Damage turn{UNK_MACRO_3D M3D_80}No{UNK_MACRO_3D M3D_136}Yes\0"
.align 2,0

.global gUnknown_80FE7A8
gUnknown_80FE7A8: @ 80FE7A8
.4byte OptionsDamageTurn

.global OptionsGrid
OptionsGrid:
.string "Grids{UNK_MACRO_3D M3D_80}Off{UNK_MACRO_3D M3D_136}On\0"
.align 2,0

.global gUnknown_80FE7C0
gUnknown_80FE7C0: @ 80FE7C0
.4byte OptionsGrid

.global OptionsMap
OptionsMap:
.string "Map{UNK_MACRO_3D M3D_80}Off{UNK_MACRO_3D M3D_120}Clear{UNK_MACRO_3D M3D_160}Shade\0"
.align 2,0

.global gUnknown_80FE7E4
gUnknown_80FE7E4: @ 80FE7E4
.4byte OptionsMap
@ Field Others Menu

.global OptionsWindowColor
OptionsWindowColor:
.string "Windows{UNK_MACRO_3D M3D_80}Blue{UNK_MACRO_3D M3D_120}Red{UNK_MACRO_3D M3D_160}Green\0"
.align 2,0

.global gOptionsWindowColorPtr
gOptionsWindowColorPtr: @ 80FE808
.4byte OptionsWindowColor
.4byte TopScreenMapData
.4byte TopScreenMapData
.4byte TopScreenMapData
.4byte TopScreenMessageLog
.4byte TopScreenMessageLog
.4byte TopScreenMessageLog
.4byte TopScreenMapAndTeam

.global TopScreenMapAndTeam
TopScreenMapAndTeam:
.string "Top screen: Map and team\0"
.align 2,0

.global TopScreenMessageLog
TopScreenMessageLog:
.string "Top screen: Message log\0"
.align 2,0

.global TopScreenMapData
TopScreenMapData:
.string "Top screen: Team data\0"
.align 2,0
.4byte BottomScreenNoMap
.4byte BottomScreenClearMap
.4byte BottomScreenShadedMap
.4byte BottomScreenNoMap
.4byte BottomScreenClearMap
.4byte BottomScreenShadedMap
.4byte BottomScreenNoMap

.global BottomScreenShadedMap
BottomScreenShadedMap:
.string "Bottom screen: Shaded map\0"
.align 2,0

.global BottomScreenClearMap
BottomScreenClearMap:
.string "Bottom screen: Clear map\0"
.align 2,0

.global BottomScreenNoMap
BottomScreenNoMap:
.string "Bottom screen: No map\0"
.align 2,0

.global GameOptionsText
GameOptionsText:

.global gUnknown_80FE8E0
gUnknown_80FE8E0: @ 80FE8E0
.string "Game Options\0"
.align 2,0

.global gGameOptionsTextPtr
gGameOptionsTextPtr: @ 80FE8F0
.4byte GameOptionsText

.global gUnknown_80FE8F4
gUnknown_80FE8F4: @ 80FE8F4
.4byte gUnknown_80F7EA8

.global gUnknown_80FE8F8
gUnknown_80FE8F8: @ 80FE8F8
.4byte gUnknown_80FE734

.global TeamToolboxAText
TeamToolboxAText:
.string "Team Toolbox A"
.align 2,0

.global gTeamToolboxAPtr
gTeamToolboxAPtr: @ 80FE90C
.4byte TeamToolboxAText

.global TeamToolboxBText
TeamToolboxBText:
.string "Team Toolbox B"
.align 2,0

.global gTeamToolboxBPtr
gTeamToolboxBPtr: @ 80FE920
.4byte TeamToolboxBText

.global FieldItemMenuGroundText
FieldItemMenuGroundText:
.string "Ground\0"
.align 2,0

.global gFieldItemMenuGroundTextPtr
gFieldItemMenuGroundTextPtr: @ 80FE92C
.4byte FieldItemMenuGroundText

.global ItemText_80FE930
ItemText_80FE930: @ 80FE930
.string "{ARG_POKEMON_0}'s item\0"
.align 2,0

.global gUnknown_80FE940
gUnknown_80FE940: @ 80FE940
.4byte ItemText_80FE930

.global WhichText
WhichText:
.string "Which?\0"
.align 2,0

.global gWhichTextPtr1
gWhichTextPtr1: @ 80FE94C
.4byte WhichText

.global gWhichTextPtr2
gWhichTextPtr2: @ 80FE950
.4byte WhichText

.global gUnknown_80FE954
gUnknown_80FE954: @ 80FE954
.4byte gMenuTacticsText

.global ItemText_80FE958
ItemText_80FE958: @ 80FE958
.string "{ARG_MOVE_ITEM_0}\0"
.align 2,0

.global gUnknown_80FE95C
gUnknown_80FE95C: @ 80FE95C
.4byte ItemText_80FE958

.global gUnknown_80FE960
gUnknown_80FE960: @ 80FE960
.4byte ItemText_80FE958

.global gUnknown_80FE964
gUnknown_80FE964: @ 80FE964
.4byte ItemText_80FE958

.global PokeMove_80FE968
PokeMove_80FE968: @ 80FE968
.string "{ARG_POKEMON_0}'s moves\0"
.align 2,0

.global gUnknown_80FE978
gUnknown_80FE978: @ 80FE978
.4byte PokeMove_80FE968

.global FieldMenuMovesEntry
FieldMenuMovesEntry:
.byte 0x23, 0x5f, 0x01, 0x2e
.string "Moves\0"
.align 2,0

.global gFieldMenuMovesPtr
gFieldMenuMovesPtr: @ 80FE988
.4byte FieldMenuMovesEntry

.global FieldMenuItemsEntry
FieldMenuItemsEntry:
.byte 0x23, 0x5f, 0x02, 0x2e
.string "Items\0"
.align 2,0

.global gFieldMenuItemsPtr
gFieldMenuItemsPtr: @ 80FE998
.4byte FieldMenuItemsEntry

.global FieldMenuTeamEntry
FieldMenuTeamEntry:
.byte 0x23, 0x5f, 0x03, 0x2e
.string "Team\0"
.align 2,0

.global gFieldMenuTeamPtr
gFieldMenuTeamPtr: @ 80FE9A8
.4byte FieldMenuTeamEntry

.global FieldMenuOthersEntry
FieldMenuOthersEntry:
.byte 0x23, 0x5f, 0x04, 0x2e
.string "Others\0"
.align 2,0

.global gFieldMenuOthersPtr
gFieldMenuOthersPtr: @ 80FE9B8
.4byte FieldMenuOthersEntry

.global FieldMenuGroundEntry
FieldMenuGroundEntry:
.byte 0x23, 0x5f, 0x05, 0x2e
.string "Ground\0"
.align 2,0

.global gFieldMenuGroundPtr
gFieldMenuGroundPtr: @ 80FE9C8
.4byte FieldMenuGroundEntry

.global gUnknown_80FE9CC
gUnknown_80FE9CC: @ 80FE9CC
@ replacing .incbin "baserom.gba", 0xFE9CC, 0x1C
.4byte gUnknown_80FE8E0

.global gUnknown_80FE9D0
gUnknown_80FE9D0: @ 80FE9D0
.string "Quicksave or Give Up\0"
.align 2, 0

.global gUnknown_80FE9E8
gUnknown_80FE9E8: @ 80FE9E8
@ replacing .incbin "baserom.gba", 0xFE9E8, 0x10
.4byte gUnknown_80FE9D0

.global gUnknown_80FE9EC
gUnknown_80FE9EC: @ 80FE9EC
.string "Message log\0"
.align 2, 0

.global gUnknown_80FE9F8
gUnknown_80FE9F8: @ 80FE9F8
@ replacing .incbin "baserom.gba", 0xFE9F8, 0x18
.4byte gUnknown_80FE9EC

.global gUnknown_80FE9FC
gUnknown_80FE9FC: @ 80FE9FC
.string "Mission objectives\0"
.align 2, 0

.global gUnknown_80FEA10
gUnknown_80FEA10: @ 80FEA10
@ replacing .incbin "baserom.gba", 0xFEA10, 0x18
.4byte gUnknown_80FE9FC

.global gUnknown_80FEA14
gUnknown_80FEA14: @ 80FEA14
.string "Recruitment search\0"
.align 2, 0

.global gUnknown_80FEA28
gUnknown_80FEA28: @ 80FEA28
@ replacing .incbin "baserom.gba", 0xFEA28, 0x1C
.4byte gUnknown_80FEA14

.global gUnknown_80FEA2C
gUnknown_80FEA2C: @ 80FEA2C
.string "{COLOR_1 RED}Recruitment search{END_COLOR_TEXT_1}\0"
.align 2, 0

.global gUnknown_80FEA44
gUnknown_80FEA44: @ 80FEA44
@ replacing .incbin "baserom.gba", 0xFEA44, 0xC
.4byte gUnknown_80FEA2C

.global gUnknown_80FEA48
gUnknown_80FEA48: @ 80FEA48
.string "Hints\0"
.align 2, 0

.global gUnknown_80FEA50
gUnknown_80FEA50: @ 80FEA50
@ replacing .incbin "baserom.gba", 0xFEA50, 0x18
.4byte gUnknown_80FEA48

.global gUnknown_80FEA54
gUnknown_80FEA54: @ 80FEA54
.string "Potential recruits\0"
.align 2, 0

.global gUnknown_80FEA68
gUnknown_80FEA68: @ 80FEA68
.4byte gUnknown_80FEA54

.global RecruitedPokemon_80FEA6C
RecruitedPokemon_80FEA6C: @ 80FEA6C
.string "Recruited Pokémon\0"
.align 2,0

.global gUnknown_80FEA80
gUnknown_80FEA80: @ 80FEA80
.4byte RecruitedPokemon_80FEA6C

.global gUnknown_80FEA84
gUnknown_80FEA84: @ 80FEA84
.string "None\0"
.align 2,0

.global gUnknown_80FEA8C
gUnknown_80FEA8C: @ 80FEA8C
@ replacing .incbin "baserom.gba", 0xFEA8C, 0x38
.4byte gUnknown_80FEA84

.global gUnknown_80FEA90
gUnknown_80FEA90: @ 80FEA90
.string "{ARG_POKEMON_0}'s IQ rose!\n"
.string "It learned the IQ skill\n"
.string "“{ARG_MOVE_ITEM_0}”!\0"
.align 2, 0

.global gUnknown_80FEAC4
gUnknown_80FEAC4: @ 80FEAC4
@ replacing .incbin "baserom.gba", 0xFEAC4, 0x24
.4byte gUnknown_80FEA90

.global gUnknown_80FEAC8
gUnknown_80FEAC8: @ 80FEAC8
.string "It appears to be weak here...\0"
.align 2, 0

.global gUnknown_80FEAE8
gUnknown_80FEAE8: @ 80FEAE8
@ replacing .incbin "baserom.gba", 0xFEAE8, 0x20
.4byte gUnknown_80FEAC8

.global gUnknown_80FEAEC
gUnknown_80FEAEC: @ 80FEAEC
.string "{ARG_POKEMON_1} became the {ARG_MOVE_ITEM_0} type.\0"
.align 2, 0

.global gUnknown_80FEB08
gUnknown_80FEB08: @ 80FEB08
@ replacing .incbin "baserom.gba", 0xFEB08, 0x28
.4byte gUnknown_80FEAEC

.global gUnknown_80FEB0C
gUnknown_80FEB0C: @ 80FEB0C
.string "{ARG_POKEMON_1} took Perish Song's effect!\0"
.align 2, 0

.global gUnknown_80FEB30
gUnknown_80FEB30: @ 80FEB30
@ replacing .incbin "baserom.gba", 0xFEB30, 0x30
.4byte gUnknown_80FEB0C

.global gUnknown_80FEB34
gUnknown_80FEB34: @ 80FEB34
.string "It can't lend a helping hand to itself!\0"
.align 2, 0

.global gUnknown_80FEB60
gUnknown_80FEB60: @ 80FEB60
@ replacing .incbin "baserom.gba", 0xFEB60, 0x28
.4byte gUnknown_80FEB34

.global gUnknown_80FEB64
gUnknown_80FEB64: @ 80FEB64
.string "Poor type match! It has no effect!\0"
.align 2, 0

.global gUnknown_80FEB88
gUnknown_80FEB88: @ 80FEB88
@ replacing .incbin "baserom.gba", 0xFEB88, 0x4
.4byte gUnknown_80FEB64

.global gUnknown_80FEB8C
gUnknown_80FEB8C: @ 80FEB8C
@ replacing .incbin "baserom.gba", 0xFEB8C, 0x4
.4byte gUnknown_80FEB64

.global gUnknown_80FEB90
gUnknown_80FEB90: @ 80FEB90
@ replacing .incbin "baserom.gba", 0xFEB90, 0x2C
.4byte gUnknown_80FEB64

.global gUnknown_80FEB94
gUnknown_80FEB94: @ 80FEB94
.string "It avoided a burn by being on water!\0"
.align 2, 0

.global gUnknown_80FEBBC
gUnknown_80FEBBC: @ 80FEBBC
@ replacing .incbin "baserom.gba", 0xFEBBC, 0x20
.4byte gUnknown_80FEB94

.global gUnknown_80FEBC0
gUnknown_80FEBC0: @ 80FEBC0
.string "It couldn't flop around!\0"
.align 2, 0

.global gUnknown_80FEBDC
gUnknown_80FEBDC: @ 80FEBDC
@ replacing .incbin "baserom.gba", 0xFEBDC, 0x1C
.4byte gUnknown_80FEBC0

.global gUnknown_80FEBE0
gUnknown_80FEBE0: @ 80FEBE0
.string "Change the settings?\0"
.align 2, 0

.global gUnknown_80FEBF8
gUnknown_80FEBF8: @ 80FEBF8
@ replacing .incbin "baserom.gba", 0xFEBF8, 0x30
.4byte gUnknown_80FEBE0

.global gUnknown_80FEBFC
gUnknown_80FEBFC: @ 80FEBFC
.string "Reset the options to their default setting?\0"
.align 2, 0

.global gUnknown_80FEC28
gUnknown_80FEC28: @ 80FEC28
@ replacing .incbin "baserom.gba", 0xFEC28, 0x20
.4byte gUnknown_80FEBFC

.global gUnknown_80FEC2C
gUnknown_80FEC2C: @ 80FEC2C
.string "Rescue chances left: {ARG_VALUE_0}\0"
.align 2, 0

.global gUnknown_80FEC48
gUnknown_80FEC48: @ 80FEC48
@ replacing .incbin "baserom.gba", 0xFEC48, 0x34
.4byte gUnknown_80FEC2C

.global gUnknown_80FEC4C
gUnknown_80FEC4C: @ 80FEC4C
.string "This team can't send out for help anymore!\0"
.align 2, 0

.global gUnknown_80FEC7C
gUnknown_80FEC7C: @ 80FEC7C
@ replacing .incbin "baserom.gba", 0xFEC7C, 0x24
.4byte gUnknown_80FEC4C

.global gUnknown_80FEC80
gUnknown_80FEC80: @ 80FEC80
.string "Are you done with the Link Box?\0"
.align 2, 0

.global gUnknown_80FECA0
gUnknown_80FECA0: @ 80FECA0
@ replacing .incbin "baserom.gba", 0xFECA0, 0x1C
.4byte gUnknown_80FEC80

.global gUnknown_80FECA4
gUnknown_80FECA4: @ 80FECA4
.string "{ARG_POKEMON_0} waggled its finger!\0"
.align 2, 0

.global gUnknown_80FECBC
gUnknown_80FECBC: @ 80FECBC
@ replacing .incbin "baserom.gba", 0xFECBC, 0x24
.4byte gUnknown_80FECA4

.global gUnknown_80FECC0
gUnknown_80FECC0: @ 80FECC0
.string "{ARG_POKEMON_0} drew out nature's power!\0"
.align 2, 0

.global gUnknown_80FECE0
gUnknown_80FECE0: @ 80FECE0
@ replacing .incbin "baserom.gba", 0xFECE0, 0x20
.4byte gUnknown_80FECC0

.global gUnknown_80FECE4
gUnknown_80FECE4: @ 80FECE4
.string "Pokémon were drawn close!\0"
.align 2, 0

.global gUnknown_80FED00
gUnknown_80FED00: @ 80FED00
@ replacing .incbin "baserom.gba", 0x000fed00, 0x4
.4byte gUnknown_80FECE4

.global gUnknown_80FED04
gUnknown_80FED04: @ 80FED04
@ replacing .incbin "baserom.gba", 0x000fed04, 0x4
.4byte gUnknown_80F89DC

.global gUnknown_80FED08
gUnknown_80FED08: @ 80FED08
@ replacing .incbin "baserom.gba", 0x000fed08, 0x4
.4byte gUnknown_80F89DC

.global gUnknown_80FED0C
gUnknown_80FED0C: @ 80FED0C
@ replacing .incbin "baserom.gba", 0xFED0C, 0x24
.4byte gUnknown_80F89DC

.global gUnknown_80FED10
gUnknown_80FED10: @ 80FED10
.string "It bounced off the trick tile!\0"
.align 2, 0

.global gUnknown_80FED30
gUnknown_80FED30: @ 80FED30
@ replacing .incbin "baserom.gba", 0xFED30, 0x38
.4byte gUnknown_80FED10

.global gUnknown_80FED34
gUnknown_80FED34: @ 80FED34
.string "{ARG_POKEMON_0} disappeared in the blast!\0"
.align 2, 0
.4byte gUnknown_80FED34

.global gUnknown_80FED58
gUnknown_80FED58: @ 80FED58
.string "{ARG_POKEMON_0} blinked.\0"
.align 2, 0

.global gUnknown_80FED68
gUnknown_80FED68: @ 80FED68
@ replacing .incbin "baserom.gba", 0xFED68, 0x20
.4byte gUnknown_80FED58

.global gUnknown_80FED6C
gUnknown_80FED6C: @ 80FED6C
.string "Overgrow boosted its power!\0"
.align 2, 0

.global gUnknown_80FED88
gUnknown_80FED88: @ 80FED88
@ replacing .incbin "baserom.gba", 0xFED88, 0x20
.4byte gUnknown_80FED6C

.global gUnknown_80FED8C
gUnknown_80FED8C: @ 80FED8C
.string "Torrent boosted its power!\0"
.align 2, 0

.global gUnknown_80FEDA8
gUnknown_80FEDA8: @ 80FEDA8
@ replacing .incbin "baserom.gba", 0xFEDA8, 0x20
.4byte gUnknown_80FED8C

.global gUnknown_80FEDAC
gUnknown_80FEDAC: @ 80FEDAC
.string "Swarm boosted its power!\0"
.align 2, 0

.global gUnknown_80FEDC8
gUnknown_80FEDC8: @ 80FEDC8
@ replacing .incbin "baserom.gba", 0xFEDC8, 0x20
.4byte gUnknown_80FEDAC

.global gUnknown_80FEDCC
gUnknown_80FEDCC: @ 80FEDCC
.string "Blaze boosted its power!\0"
.align 2, 0

.global gUnknown_80FEDE8
gUnknown_80FEDE8: @ 80FEDE8
@ replacing .incbin "baserom.gba", 0xFEDE8, 0x1C
.4byte gUnknown_80FEDCC

.global gUnknown_80FEDEC
gUnknown_80FEDEC: @ 80FEDEC
.string "Guts boosted its power!\0"
.align 2, 0

.global gUnknown_80FEE04
gUnknown_80FEE04: @ 80FEE04
@ replacing .incbin "baserom.gba", 0xFEE04, 0x28
.4byte gUnknown_80FEDEC

.global gUnknown_80FEE08
gUnknown_80FEE08: @ 80FEE08
.string "Its special ability boosted Attack!\0"
.align 2, 0

.global gUnknown_80FEE2C
gUnknown_80FEE2C: @ 80FEE2C
@ replacing .incbin "baserom.gba", 0xFEE2C, 0x28
.4byte gUnknown_80FEE08

.global gUnknown_80FEE30
gUnknown_80FEE30: @ 80FEE30
.string "Marvel Scale boosted its Defense!\0"
.align 2, 0

.global gUnknown_80FEE54
gUnknown_80FEE54: @ 80FEE54
@ replacing .incbin "baserom.gba", 0xFEE54, 0x2C
.4byte gUnknown_80FEE30

.global gUnknown_80FEE58
gUnknown_80FEE58: @ 80FEE58
.string "Its special ability quickened attacks!\0"
.align 2, 0

.global gUnknown_80FEE80
gUnknown_80FEE80: @ 80FEE80
@ replacing .incbin "baserom.gba", 0xFEE80, 0x24
.4byte gUnknown_80FEE58

.global gUnknown_80FEE84
gUnknown_80FEE84: @ 80FEE84
.string "Arena Trap prevents movement!\0"
.align 2, 0

.global gUnknown_80FEEA4
gUnknown_80FEEA4: @ 80FEEA4
@ replacing .incbin "baserom.gba", 0xFEEA4, 0x24
.4byte gUnknown_80FEE84

.global gUnknown_80FEEA8
gUnknown_80FEEA8: @ 80FEEA8
.string "Shadow Tag prevents movement!\0"
.align 2, 0

.global gUnknown_80FEEC8
gUnknown_80FEEC8: @ 80FEEC8
@ replacing .incbin "baserom.gba", 0xFEEC8, 0x24
.4byte gUnknown_80FEEA8

.global gUnknown_80FEECC
gUnknown_80FEECC: @ 80FEECC
.string "Magnet Pull prevents movement!\0"
.align 2, 0

.global gUnknown_80FEEEC
gUnknown_80FEEEC: @ 80FEEEC
@ replacing .incbin "baserom.gba", 0xFEEEC, 0x20
.4byte gUnknown_80FEECC

.global gUnknown_80FEEF0
gUnknown_80FEEF0: @ 80FEEF0
.string "Static caused paralysis!\0"
.align 2, 0

.global gUnknown_80FEF0C
gUnknown_80FEF0C: @ 80FEF0C
@ replacing .incbin "baserom.gba", 0xFEF0C, 0x24
.4byte gUnknown_80FEEF0

.global gUnknown_80FEF10
gUnknown_80FEF10: @ 80FEF10
.string "Effect Spore scattered spores!\0"
.align 2, 0

.global gUnknown_80FEF30
gUnknown_80FEF30: @ 80FEF30
@ replacing .incbin "baserom.gba", 0xFEF30, 0x1C
.4byte gUnknown_80FEF10

.global gUnknown_80FEF34
gUnknown_80FEF34: @ 80FEF34
.string "Poison Point struck!\0"
.align 2, 0

.global gUnknown_80FEF4C
gUnknown_80FEF4C: @ 80FEF4C
@ replacing .incbin "baserom.gba", 0x000fef4c, 0x4
.4byte gUnknown_80FEF34

.global gUnknown_80FEF50
gUnknown_80FEF50: @ 80FEF50
@ replacing .incbin "baserom.gba", 0x000fef50, 0x4
.4byte gUnknown_80FEF10

.global gUnknown_80FEF54
gUnknown_80FEF54: @ 80FEF54
@ replacing .incbin "baserom.gba", 0xFEF54, 0x20
.4byte gUnknown_80FEF10

.global gUnknown_80FEF58
gUnknown_80FEF58: @ 80FEF58
.string "Flame Body caused a burn!\0"
.align 2, 0

.global gUnknown_80FEF74
gUnknown_80FEF74: @ 80FEF74
@ replacing .incbin "baserom.gba", 0xFEF74, 0x24
.4byte gUnknown_80FEF58

.global gUnknown_80FEF78
gUnknown_80FEF78: @ 80FEF78
.string "Cute Charm caused infatuation!\0"
.align 2, 0

.global gUnknown_80FEF98
gUnknown_80FEF98: @ 80FEF98
@ replacing .incbin "baserom.gba", 0xFEF98, 0x38
.4byte gUnknown_80FEF78

.global gUnknown_80FEF9C
gUnknown_80FEF9C: @ 80FEF9C
.string "A horrid stench billowed out!\n"
.string "{ARG_POKEMON_0} became terrified!\0"
.align 2, 0

.global gUnknown_80FEFD0
gUnknown_80FEFD0: @ 80FEFD0
@ replacing .incbin "baserom.gba", 0xFEFD0, 0x24
.4byte gUnknown_80FEF9C

.global gUnknown_80FEFD4
gUnknown_80FEFD4: @ 80FEFD4
.string "Transform can't be used here!\0"
.align 2, 0

.global gUnknown_80FEFF4
gUnknown_80FEFF4: @ 80FEFF4
@ replacing .incbin "baserom.gba", 0xFEFF4, 0x28
.4byte gUnknown_80FEFD4

.global gUnknown_80FEFF8
gUnknown_80FEFF8: @ 80FEFF8
.string "{ARG_POKEMON_0}'s Synchronize took effect!\0"
.align 2, 0

.global gUnknown_80FF01C
gUnknown_80FF01C: @ 80FF01C
@ replacing .incbin "baserom.gba", 0xFF01C, 0x4
.4byte gUnknown_80FEFF8

.global gUnknown_80FF020
gUnknown_80FF020: @ 80FF020
@ replacing .incbin "baserom.gba", 0xFF020, 0x60
.byte 0x00, 0x00, 0x00, 0x00
.4byte gUnknown_80FF028

.global gUnknown_80FF028
gUnknown_80FF028: @ 80FF028
.string "Head for the destination while attacking\n"
.string "foes with {A_BUTTON}.\n"
.string "Try not to let a partner faint!\0"
.align 2, 0

.global gUnknown_80FF080
gUnknown_80FF080: @ 80FF080
@ replacing .incbin "baserom.gba", 0xFF080, 0x58
.byte 0x01, 0x00, 0x00, 0x00
.4byte gUnknown_80FF088

.global gUnknown_80FF088
gUnknown_80FF088: @ 80FF088
.string "Foes won't move until you do.\n"
.string "Open the menu with {B_BUTTON} and\n"
.string "think before you act!\0"
.align 2, 0

.global gUnknown_80FF0D8
gUnknown_80FF0D8: @ 80FF0D8
@ replacing .incbin "baserom.gba", 0xFF0D8, 0x64
.byte 0x02, 0x00, 0x00, 0x00
.4byte gUnknown_80FF0E0

.global gUnknown_80FF0E0
gUnknown_80FF0E0: @ 80FF0E0
.string "Your team regains HP as it moves.\n"
.string "Hold {B_BUTTON} then press {A_BUTTON} to recover\n"
.string "HP quickly on the spot.\0"
.align 2, 0

.global gUnknown_80FF13C
gUnknown_80FF13C: @ 80FF13C
@ replacing .incbin "baserom.gba", 0xFF13C, 0x78
.byte 0x0c, 0x00, 0x00, 0x00
.4byte gUnknown_80FF144

.global gUnknown_80FF144
gUnknown_80FF144: @ 80FF144
.string "Defeat foes using moves instead of\n"
.string "{A_BUTTON} attacks for more Exp. Points.\n"
.string "Choose and set the move you want to use.\0"
.align 2, 0

.global gUnknown_80FF1B4
gUnknown_80FF1B4: @ 80FF1B4
@ replacing .incbin "baserom.gba", 0xFF1B4, 0x78
.byte 0x0d, 0x00, 0x00, 0x00
.4byte gUnknown_80FF1BC

.global gUnknown_80FF1BC
gUnknown_80FF1BC: @ 80FF1BC
.string "Choose a partner with the Team command\n"
.string "and set its tactics and IQ skills.\n"
.string "Cooperation with partners is the key!\0"
.align 2, 0

.global gUnknown_80FF22C
gUnknown_80FF22C: @ 80FF22C
@ replacing .incbin "baserom.gba", 0xFF22C, 0x64
.byte 0x0e, 0x00, 0x00, 0x00
.4byte gUnknown_80FF234

.global gUnknown_80FF234
gUnknown_80FF234: @ 80FF234
.string "Hold {B_BUTTON} then press {DPAD} to speed up\n"
.string "movement. Hold {R_BUTTON} then press {DPAD}\n"
.string "to move only diagonally.\0"
.align 2, 0

.global gUnknown_80FF290
gUnknown_80FF290: @ 80FF290
@ replacing .incbin "baserom.gba", 0xFF290, 0x80
.byte 0x0f, 0x00, 0x00, 0x00
.4byte gUnknown_80FF298

.global gUnknown_80FF298
gUnknown_80FF298: @ 80FF298
.string "Eat an Apple or Gummi when your Belly\n"
.string "goes down. Being famished can cause\n"
.string "fainting, so check your Belly in the menu.\0"
.align 2, 0

.global gUnknown_80FF310
gUnknown_80FF310: @ 80FF310
@ replacing .incbin "baserom.gba", 0xFF310, 0x84
.byte 0x03, 0x00, 0x00, 0x00
.4byte gUnknown_80FF318

.global gUnknown_80FF318
gUnknown_80FF318: @ 80FF318
.string "Eating an Apple or Gummi fills your Belly.\n"
.string "Choose them under Items in the menu\n"
.string "and eat one before your Belly gets empty.\0"
.align 2, 0

.global gUnknown_80FF394
gUnknown_80FF394: @ 80FF394
@ replacing .incbin "baserom.gba", 0xFF394, 0x54
.byte 0x04, 0x00, 0x00, 0x00
.4byte gUnknown_80FF39C

.global gUnknown_80FF39C
gUnknown_80FF39C: @ 80FF39C
.string "An Oran Berry restores HP.\n"
.string "Open the menu with {B_BUTTON} and\n"
.string "select it under Items.\0"
.align 2, 0

.global gUnknown_80FF3E8
gUnknown_80FF3E8: @ 80FF3E8
@ replacing .incbin "baserom.gba", 0xFF3E8, 0x58
.byte 0x05, 0x00, 0x00, 0x00
.4byte gUnknown_80FF3F0

.global gUnknown_80FF3F0
gUnknown_80FF3F0: @ 80FF3F0
.string "A Cheri Berry heals paralysis.\n"
.string "Open the menu with {B_BUTTON} and\n"
.string "select it under Items.\0"
.align 2, 0

.global gUnknown_80FF440
gUnknown_80FF440: @ 80FF440
@ replacing .incbin "baserom.gba", 0xFF440, 0x60
.byte 0x06, 0x00, 0x00, 0x00
.4byte gUnknown_80FF448

.global gUnknown_80FF448
gUnknown_80FF448: @ 80FF448
.string "A Blast Seed flames the foe you\n"
.string "are facing.\n"
.string "Turn to face the foe, then use the item.\0"
.align 2, 0

.global gUnknown_80FF4A0
gUnknown_80FF4A0: @ 80FF4A0
@ replacing .incbin "baserom.gba", 0xFF4A0, 0x78
.byte 0x07, 0x00, 0x00, 0x00
.4byte gUnknown_80FF4A8

.global gUnknown_80FF4A8
gUnknown_80FF4A8: @ 80FF4A8
.string "Gravelerocks can be lobbed at distant foes.\n"
.string "Set them for use under Items.\n"
.string "Hold {L_BUTTON} then press {R_BUTTON} to throw them.\0"
.align 2, 0

.global gUnknown_80FF518
gUnknown_80FF518: @ 80FF518
@ replacing .incbin "baserom.gba", 0xFF518, 0x64
.byte 0x09, 0x00, 0x00, 0x00
.4byte gUnknown_80FF520

.global gUnknown_80FF520
gUnknown_80FF520: @ 80FF520
.string "A Pecha Berry heals any kind of poisoning.\n"
.string "Open the menu with {B_BUTTON} and\n"
.string "select it under Items.\0"
.align 2, 0

.global gUnknown_80FF57C
gUnknown_80FF57C: @ 80FF57C
@ replacing .incbin "baserom.gba", 0xFF57C, 0x6C
.byte 0x0a, 0x00, 0x00, 0x00
.4byte gUnknown_80FF584

.global gUnknown_80FF584
gUnknown_80FF584: @ 80FF584
.string "Throw a Sleep Seed at a foe to put it\n"
.string "to sleep for a little while.\n"
.string "Eating it will put you to sleep!\0"
.align 2, 0

.global gUnknown_80FF5E8
gUnknown_80FF5E8: @ 80FF5E8
@ replacing .incbin "baserom.gba", 0xFF5E8, 0x8C
.byte 0x0b, 0x00, 0x00, 0x00
.4byte gUnknown_80FF5F0

.global gUnknown_80FF5F0
gUnknown_80FF5F0: @ 80FF5F0
.string "{POKE} is the money in this world.\n"
.string "Collect and save it to buy useful\n"
.string "items.\0"
.align 2, 0

.global gUnknown_80FF63C
gUnknown_80FF63C: @ 80FF63C
.string "You're a thief!\n"
.string "You're not recognized as a rescuer!\0"
.align 2, 0

.global gUnknown_80FF674
gUnknown_80FF674: @ 80FF674
@ replacing .incbin "baserom.gba", 0xFF674, 0x4
.4byte gUnknown_80FF63C

.global gUnknown_80FF678
gUnknown_80FF678: @ 80FF678
@ replacing .incbin "baserom.gba", 0xFF678, 0x2C
.4byte gUnknown_80FB568

.global gUnknown_80FF67C
gUnknown_80FF67C: @ 80FF67C
.string "You've reached a destination floor!\0"
.align 2, 0

.global gUnknown_80FF6A4
gUnknown_80FF6A4: @ 80FF6A4
@ replacing .incbin "baserom.gba", 0xFF6A4, 0x54
.4byte gUnknown_80FF67C

.global gUnknown_80FF6A8
gUnknown_80FF6A8: @ 80FF6A8
.string "You've reached a destination floor!\n"
.string "But the Pokémon you seek isn't here...\0"
.align 2, 0

.global gUnknown_80FF6F8
gUnknown_80FF6F8: @ 80FF6F8
@ replacing .incbin "baserom.gba", 0xFF6F8, 0x38
.4byte gUnknown_80FF6A8

.global gUnknown_80FF6FC
gUnknown_80FF6FC: @ 80FF6FC
.string "{ARG_MOVE_ITEM_0} was added to\n"
.string "{ARG_POKEMON_0}'s list of usable tactics.\0"
.align 2, 0

.global gUnknown_80FF730
gUnknown_80FF730: @ 80FF730
@ replacing .incbin "baserom.gba", 0xFF730, 0x3C
.4byte gUnknown_80FF6FC

.global gUnknown_80FF734
gUnknown_80FF734: @ 80FF734
.string "Items can't be thrown when a Pokémon's\n"
.string "terrified!\0"
.align 2, 0

.global gUnknown_80FF76C
gUnknown_80FF76C: @ 80FF76C
@ replacing .incbin "baserom.gba", 0xFF76C, 0x4
.4byte gUnknown_80FF734

.global gUnknown_80FF770
gUnknown_80FF770: @ 80FF770
.4byte gUnknown_80FEA48

.global gUnknown_80FF774
gUnknown_80FF774: @ 80FF774
@ replacing .incbin "baserom.gba", 0xFF774, 0x78
.4byte gUnknown_80FF7E0
.4byte gUnknown_80FF7D4
.4byte gUnknown_80FF7CC
.4byte gUnknown_80F7F04
.4byte gUnknown_80FF7C4
.4byte gUnknown_80FF7B4
.4byte gUnknown_80FF7A4
.4byte gUnknown_80FF794

.global gUnknown_80FF794
gUnknown_80FF794: @ 80FF794
.string "Touch Screen\0"
.align 2, 0

.global gUnknown_80FF7A4
gUnknown_80FF7A4: @ 80FF7A4
.string "Pokémon types\0"
.align 2, 0

.global gUnknown_80FF7B4
gUnknown_80FF7B4: @ 80FF7B4
.string "Linking moves\0"
.align 2, 0

.global gUnknown_80FF7C4
gUnknown_80FF7C4: @ 80FF7C4
.string "Range\0"
.align 2, 0

.global gUnknown_80FF7CC
gUnknown_80FF7CC: @ 80FF7CC
.string "Seeds\0"
.align 2, 0

.global gUnknown_80FF7D4
gUnknown_80FF7D4: @ 80FF7D4
.string "Orientation\0"
.align 2, 0

.global gUnknown_80FF7E0
gUnknown_80FF7E0: @ 80FF7E0
.string "Controls\0"
.align 2, 0

.global gUnknown_80FF7EC
gUnknown_80FF7EC: @ 80FF7EC
@ replacing .incbin "baserom.gba", 0xFF7EC, 0xA1C
.4byte gUnknown_810011C
.4byte gUnknown_8100060
.4byte gUnknown_80FFF60
.4byte gUnknown_80FFE54
.4byte gUnknown_80FFD54
.4byte gUnknown_80FFC60
.4byte gUnknown_80FFB3C
.4byte gUnknown_80FFA78
.4byte gUnknown_80FF9D4
.4byte gUnknown_80FF914
.4byte gUnknown_80FFF60
.4byte gUnknown_80FFE54
.4byte gUnknown_80FFD54
.4byte gUnknown_80FFC60
.4byte gUnknown_80FFB3C
.4byte gUnknown_80FF82C

.global gUnknown_80FF82C
gUnknown_80FF82C: @ 80FF82C
.string "Touch once to attack a foe, walk,\n"
.string "advance text, cancel, or pick up \n"
.string "an item off the ground.\n"
.string "Touch twice to use the set move.\n"
.string "Touch the leader twice to move fast.\n"
.string "Touch and hold to change directions\n"
.string "without taking a step.\0"
.align 2, 0

.global gUnknown_80FF914
gUnknown_80FF914: @ 80FF914
.string "Avoid attacks by moving diagonally.\n"
.string "Keeping {R_BUTTON} pressed, press\n"
.string "{DPAD} to move only diagonally.\n"
.string "It's crucial to change the direction\n"
.string "you're facing without taking a step.\n"
.string "Hold {NDS_Y_BUTTON} to do so.\n\0"
.align 2, 0

.global gUnknown_80FF9D4
gUnknown_80FF9D4: @ 80FF9D4
.string "{L_BUTTON}+{A_BUTTON}: Use set move\n"
.string "{L_BUTTON}+{B_BUTTON}: Display message log\n"
.string "{L_BUTTON}+{R_BUTTON}: Throw set item\n"
.string "{R_BUTTON}+{DPAD}: Move diagonally\n"
.string "{NDS_Y_BUTTON}: Rotate mode\n"
.string "{SELECT_BUTTON}: Floor map\n"
.string "Select item/move + {START_BUTTON}: Description\0"
.align 2, 0

.global gUnknown_80FFA78
gUnknown_80FFA78: @ 80FFA78
.string "Press once: Push a foe to attack.\n"
.string "Touch the floor to move. Advance text.\n"
.string "Cancel.\n"
.string "Press twice: Use the set move.\n"
.string "Press your Pokémon to move fast.\n"
.string "Keep pressed to change directions\n"
.string "without moving.\0"
.align 2, 0

.global gUnknown_80FFB3C
gUnknown_80FFB3C: @ 80FFB3C
.string "There are seventeen types of Pokémon\n"
.string "and moves: Normal, Fire, Water, Grass,\n"
.string "Electric, Ice, Fighting, Poison, Ground,\n"
.string "Flying, Psychic, Bug, Rock, Ghost,\n"
.string "Dragon, Dark, and Steel. All Pokémon\n"
.string "have one or two types that determine\n"
.string "the damage they take and give.\0"
.align 2, 0

.global gUnknown_80FFC60
gUnknown_80FFC60: @ 80FFC60
.string "Moves can be linked at the Gulpin Link\n"
.string "Shop or by using a Link Box.\n"
.string "Two moves can be linked and used\n"
.string "simultaneously.\n"
.string "If they're used even once in defeating\n"
.string "a foe, you will earn more Exp. Points,\n"
.string "but your Belly will go down faster, too.\0"
.align 2, 0

.global gUnknown_80FFD54
gUnknown_80FFD54: @ 80FFD54
.string "All moves have a range of effect.\n"
.string "A move that affects a room, such as\n"
.string "Growl, reaches 2 tiles when in a\n"
.string "corridor. However, if the visibility is\n"
.string "limited to only 1 tile, the move's\n"
.string "range will be likewise restricted.\n"
.string "Check the descriptions of moves!\0"
.align 2, 0

.global gUnknown_80FFE54
gUnknown_80FFE54: @ 80FFE54
.string "Normal-, Steel-, Poison-, Ground-,\n"
.string "Flying-, Bug-, Rock-, Ghost-, and\n"
.string "Fighting-type moves are based on\n"
.string "Attack and Defense. Fire-, Dark-,\n"
.string "Water-, Grass-, Electric-, Ice-,\n"
.string "Psychic-, and Dragon-type moves\n"
.string "are based on Sp. Atk. and Sp. Def.\0"
.align 2, 0

.global gUnknown_80FFF60
gUnknown_80FFF60: @ 80FFF60
.string "Seeds can be thrown.\n"
.string "They are usually for eating, but throw\n"
.string "them at foes to get the same effect.\n"
.string "If you have any Seeds you don't want\n"
.string "to eat, try throwing them at foes.\n"
.string "You can also throw them at partners.\n"
.string "If they hit, their effects will be felt.\0"
.align 2, 0

.global gUnknown_8100060
gUnknown_8100060: @ 8100060
.string "Avoid attacks by moving diagonally.\n"
.string "Keeping {R_BUTTON} pressed, press\n"
.string "{DPAD} to move only diagonally.\n"
.string "It's also crucial to change the direction\n"
.string "you're facing without taking a step.\n"
.string "Just tap {R_BUTTON}!\0"
.align 2, 0

.global gUnknown_810011C
gUnknown_810011C: @ 810011C
.string "{L_BUTTON}+{A_BUTTON}: Use set move\n"
.string "{L_BUTTON}+{B_BUTTON}: Display message log\n"
.string "{L_BUTTON}+{R_BUTTON}: Throw set item\n"
.string "{R_BUTTON}+{DPAD}: Move diagonally\n"
.string "{SELECT_BUTTON}: Floor map\n"
.string "{START_BUTTON}: Rotate mode\n"
.string "Select item/move + {START_BUTTON}: Description\0"
.align 2, 0

.global gUnknown_81001C0
gUnknown_81001C0: @ 81001C0
.string "Switch places with your teammate?\n"
.string "This will cause the teammate to warp.\0"
.align 2, 0

.global gUnknown_8100208
gUnknown_8100208: @ 8100208
.4byte gUnknown_81001C0

.global gMagnitudeMessage
gMagnitudeMessage: @ 810020C
.string "It's Magnitude {ARG_VALUE_0}!\0"
.align 2, 0

.global gPtrMagnitudeMessage
gPtrMagnitudeMessage: @ 8100224
.4byte gMagnitudeMessage

.global gSleepingTargetOnlyMessage
gSleepingTargetOnlyMessage: @ 8100228
.string "It only works on a sleeping target!\0"
.align 2, 0

.global gPtrSleepingTargetOnlyMessage
gPtrSleepingTargetOnlyMessage: @ 810024C
.4byte gSleepingTargetOnlyMessage

.global gFeralFoundItemMessage
gFeralFoundItemMessage: @ 8100250
.string "{ARG_POKEMON_0} found an item somewhere.\0"
.align 2, 0

.global gPtrFeralFoundItemMessage
gPtrFeralFoundItemMessage: @ 8100270
.4byte gFeralFoundItemMessage

.global gSelfHealPreventedHungerMessage
gSelfHealPreventedHungerMessage: @ 8100274
.string "Its self-healing prevented hunger!\0"
.align 2, 0

.global gPtrSelfHealPreventedHungerMessage
gPtrSelfHealPreventedHungerMessage: @ 8100298
.4byte gSelfHealPreventedHungerMessage

.global gUnknown_810029C
gUnknown_810029C: @ 810029C
.string "Rescue challenges left: {ARG_VALUE_0}\0"
.align 2, 0

.global gUnknown_81002B8
gUnknown_81002B8: @ 81002B8
.4byte gUnknown_810029C

.global gFinalChanceMessage
gFinalChanceMessage: @ 81002BC
.string "This is your final chance!\0"
.align 2, 0

.global gPtrFinalChanceMessage
gPtrFinalChanceMessage: @ 81002D8
.4byte gFinalChanceMessage

.global gLinkedMovesComeApartMessage
gLinkedMovesComeApartMessage: @ 81002DC
.string "The linked moves came apart!\0"
.align 2, 0

.global gPtrLinkedMovesComeApartMessage
gPtrLinkedMovesComeApartMessage: @ 81002FC
.4byte gLinkedMovesComeApartMessage

.global gLinkMoveOneUseWarningMessage
gLinkMoveOneUseWarningMessage: @ 8100300
.string "{COLOR_2 YELLOW}The linked moves are almost out of PP!{END_COLOR_TEXT_2}\n"
.string "{COLOR_2 YELLOW}Use them again and they will come apart!{END_COLOR_TEXT_2}\0"
.align 2, 0

.global gPtrLinkMoveOneUseWarningMessage
gPtrLinkMoveOneUseWarningMessage: @ 810035C
.4byte gLinkMoveOneUseWarningMessage

.global gLinkMoveTwoUsesWarningMessage
gLinkMoveTwoUsesWarningMessage: @ 8100360
.string "{COLOR_2 YELLOW}The linked moves are almost out of PP!{END_COLOR_TEXT_2}\n"
.string "{COLOR_2 YELLOW}Use them twice and they will come apart!{END_COLOR_TEXT_2}\0"
.align 2, 0

.global gPtrLinkMoveTwoUsesWarningMessage
gPtrLinkMoveTwoUsesWarningMessage: @ 81003BC
.4byte gLinkMoveTwoUsesWarningMessage

.global gIcePartCrumbledMessage
gIcePartCrumbledMessage: @ 81003C0
.string "The Ice Part crumbled away...\0"
.align 2, 0

.global gPtrIcePartCrumbledMessage
gPtrIcePartCrumbledMessage: @ 81003E0
.4byte gIcePartCrumbledMessage

.global gRockPartCrumbledMessage
gRockPartCrumbledMessage: @ 81003E4
.string "The Rock Part crumbled away...\0"
.align 2, 0

.global gPtrRockPartCrumbledMessage
gPtrRockPartCrumbledMessage: @ 8100404
.4byte gRockPartCrumbledMessage

.global gSteelPartCrumbledMessage
gSteelPartCrumbledMessage: @ 8100408
.string "The Steel Part crumbled away...\0"
.align 2, 0

.global gPtrSteelPartCrumbledMessage
gPtrSteelPartCrumbledMessage: @ 8100428
.4byte gSteelPartCrumbledMessage

.global gWishStoneCrumbledMessage
gWishStoneCrumbledMessage: @ 810042C
.string "The Wish Stone crumbled away...\0"
.align 2, 0

.global gPtrWishStoneCrumbledMessage
gPtrWishStoneCrumbledMessage: @ 810044C
.4byte gWishStoneCrumbledMessage

.global gMusicBoxPlayedCrumbledMessage
gMusicBoxPlayedCrumbledMessage: @ 8100450
.string "The Music Box played a beautiful melody,\n"
.string "then crumbled away...\0"
.align 2, 0

.global gPtrMusicBoxPlayedCrumbledMessage
gPtrMusicBoxPlayedCrumbledMessage: @ 8100494
.4byte gMusicBoxPlayedCrumbledMessage

.global gMysteriousPowerPreventedUseMessage
gMysteriousPowerPreventedUseMessage: @ 8100498
.string "But a mysterious power prevented its use!\0"
.align 2, 0

.global gPtrMysteriousPowerPreventedUseMessage
gPtrMysteriousPowerPreventedUseMessage: @ 81004C4
.4byte gMysteriousPowerPreventedUseMessage

.global gCouldntBeUsedMessage
gCouldntBeUsedMessage: @ 81004C8
.string "But it couldn't be used!\0"
.align 2, 0

.global gPtrCouldntBeUsedMessage
gPtrCouldntBeUsedMessage: @ 81004E4
.4byte gCouldntBeUsedMessage

.global gUnknown_81004E8
gUnknown_81004E8: @ 81004E8
.4byte gUnknown_80FB568

.global gUnknown_81004EC
gUnknown_81004EC: @ 81004EC
.4byte gUnknown_80FB568

.global gUnknown_81004F0
gUnknown_81004F0: @ 81004F0
.4byte gUnknown_80FB568

.global gUnknown_81004F4
gUnknown_81004F4: @ 81004F4
.string "{ARG_POKEMON_1}'s Soundproof suppressed\n"
.string "the sound move!\0"
.align 2, 0

.global gUnknown_8100524
gUnknown_8100524: @ 8100524
.4byte gUnknown_81004F4

.global gUnknown_8100528
gUnknown_8100528: @ 8100528
.string "The attack was barely endured!\0"
.align 2, 0

.global gUnknown_8100548
gUnknown_8100548: @ 8100548
.4byte gUnknown_8100528

.global gUnknown_810054C
gUnknown_810054C: @ 810054C
.string "False Swipe prevented fainting!\0"
.align 2, 0

.global gUnknown_810056C
gUnknown_810056C: @ 810056C
.4byte gUnknown_810054C

.global gUnknown_8100570
gUnknown_8100570: @ 8100570
.string "Perish Song's effect wore off!\0"
.align 2, 0

.global gUnknown_8100594
gUnknown_8100594: @ 8100594
.4byte gUnknown_8100570

.global gExposedWoreOffMessage
gExposedWoreOffMessage: @ 8100598
.string "The Exposed status wore off!\0"
.align 2, 0

.global gPtrExposedWoreOffMessage
gPtrExposedWoreOffMessage: @ 81005B8
.4byte gExposedWoreOffMessage

.global gSealedMoveReleasedMessage
gSealedMoveReleasedMessage: @ 81005BC
.string "The sealed move was released!\0"
.align 2, 0

.global gPtrSealedMoveReleasedMessage
gPtrSealedMoveReleasedMessage: @ 81005DC
.4byte gSealedMoveReleasedMessage

.global gCantLeechSeedSelfMessage
gCantLeechSeedSelfMessage: @ 81005E0
.string "A leech seed can't be planted on the user!\0"
.align 2, 0

.global gPtrCantLeechSeedSelfMessage
gPtrCantLeechSeedSelfMessage: @ 8100610
.4byte gCantLeechSeedSelfMessage

.global gCantLeechSeedMonMessage
gCantLeechSeedMonMessage: @ 8100614
.string "A leech seed couldn't be planted on\n"
.string "{ARG_POKEMON_0}!\0"
.align 2, 0

.global gPtrCantLeechSeedMonMessage
gPtrCantLeechSeedMonMessage: @ 8100640
.4byte gCantLeechSeedMonMessage

.global gMoveInterruptedMessage
gMoveInterruptedMessage: @ 8100644
.string "The move was interrupted!\0"
.align 2, 0

.global gPtrMoveInterruptedMessage
gPtrMoveInterruptedMessage: @ 8100660
.4byte gMoveInterruptedMessage

.global gClientFaintedMessage
gClientFaintedMessage: @ 8100664
.string "Your client Pokémon has fainted!\n"
.string "A rescue call can't be made!\0"
.align 2, 0

.global gPtrClientFaintedMessage
gPtrClientFaintedMessage: @ 81006A4
.4byte gClientFaintedMessage

.global gCantUseInDungeonMessage
gCantUseInDungeonMessage: @ 81006A8
.string "It can't be used in a dungeon!\0"
.align 2, 0

.global gPtrCantUseInDungeonMessage
gPtrCantUseInDungeonMessage: @ 81006CC
.4byte gCantUseInDungeonMessage

.global gForecastPreventsTypeSwitchMessage
gForecastPreventsTypeSwitchMessage: @ 81006D0
.string "Its Forecast prevents type switching!\0"
.align 2, 0

.global gPtrForecastPreventsTypeSwitchMessage
gPtrForecastPreventsTypeSwitchMessage: @ 81006F8
.4byte gForecastPreventsTypeSwitchMessage

.global gForecastPreventsConversion2Message
gForecastPreventsConversion2Message: @ 81006FC
.string "Its Forecast prevents Conversion 2!\0"
.align 2, 0

.global gPtrForecastPreventsConversion2Message
gPtrForecastPreventsConversion2Message: @ 8100720
.4byte gForecastPreventsConversion2Message

.global gStenchWavedOffMessage
gStenchWavedOffMessage: @ 8100724
.string "The stench was waved off!\0"
.align 2, 0

.global gPtrStenchWavedOffMessage
gPtrStenchWavedOffMessage: @ 8100740
.4byte gStenchWavedOffMessage

.global gProtectSavedItMessage
gProtectSavedItMessage: @ 8100744
.string "Its Protect saved it!\0"
.align 2, 0

.global gPtrProtectSavedItMessage
gPtrProtectSavedItMessage: @ 810075C
.4byte gProtectSavedItMessage
.string "pksdir0\0"
.align 2, 0
@ Start of Boss Fight Dialogues?

.global gSkarmoryPreFightDialogue_1
gSkarmoryPreFightDialogue_1: @ 8100768
.byte 0x00, 0x00, 0x0C, 0x02, 0xAA, 0x01, 0x00, 0x00
.4byte gUnknown_8100774

.global gUnknown_8100774
gUnknown_8100774: @ 8100774
.string " Look, {ARG_POKEMON_0}!\n"
.string "{ARG_POKEMON_2}'s over there!\0"
.align 2, 0

.global gSkarmoryPreFightDialogue_2
gSkarmoryPreFightDialogue_2: @ 8100798
.byte 0x00, 0x00, 0x04, 0x02, 0xAA, 0x01, 0x07, 0x00
.4byte gUnknown_81007E8
.byte 0x00, 0x00, 0x04, 0x02, 0xAA, 0x01, 0x00, 0x00
.4byte gUnknown_81007B0

.global gUnknown_81007B0
gUnknown_81007B0: @ 81007B0
.string " Hey! Are you all right?\n"
.string "We've come to rescue you!\0"
.align 2, 0

.global gUnknown_81007E8
gUnknown_81007E8: @ 81007E8
.string " Hey! Are you all right?\n"
.string "We're here to rescue you!\0"
.align 2, 0

.global gSkarmoryPreFightDialogue_3
gSkarmoryPreFightDialogue_3: @ 8100820
.byte 0x00, 0x00, 0x01, 0x0D, 0x32, 0x00, 0x00, 0x00
.4byte gUnknown_810082C

.global gUnknown_810082C
gUnknown_810082C: @ 810082C
.string " ...I...\n"
.string "I'm scared.\0"
.align 2, 0

.global gSkarmoryPreFightDialogue_4
gSkarmoryPreFightDialogue_4: @ 8100844
@ replacing .incbin "baserom.gba", 0x100844, 0x3C
.byte 0x00, 0x00, 0x00, 0x0d, 0xfc, 0x00, 0x00, 0x00
.4byte gUnknown_8100850

.global gUnknown_8100850
gUnknown_8100850: @ 8100850
.string " You!\n"
.string "What do you think you're doing here?!\0"
.align 2, 0

.global gSkarmoryPreFightDialogue_5
gSkarmoryPreFightDialogue_5: @ 8100880
@ replacing .incbin "baserom.gba", 0x100880, 0xA8
.byte 0x00, 0x00, 0x03, 0x02, 0xaa, 0x01, 0x07, 0x00
.4byte gUnknown_81008DC
.byte 0x00, 0x00, 0x03, 0x02
.byte 0xaa, 0x01, 0x00, 0x00
.4byte gUnknown_8100898

.global gUnknown_8100898
gUnknown_8100898: @ 8100898
.string " We're here to rescue\n"
.string "{ARG_POKEMON_2}!{EXTRA_MSG}"
.string " {ARG_POKEMON_3}!\n"
.string "Don't do this! Release {ARG_POKEMON_2}!\0"
.align 2, 0

.global gUnknown_81008DC
gUnknown_81008DC: @ 81008DC
.string " We came to rescue\n"
.string "{ARG_POKEMON_2}!{EXTRA_MSG}"
.string " Hey, {ARG_POKEMON_3}!\n"
.string "Quit doing this, and release {ARG_POKEMON_2}!\0"
.align 2, 0

.global gSkarmoryPreFightDialogue_6
gSkarmoryPreFightDialogue_6: @ 8100928
.byte 0x00, 0x00, 0x00, 0x0D, 0xFC, 0x00, 0x00, 0x00
.4byte gUnknown_8100934

.global gUnknown_8100934
gUnknown_8100934: @ 8100934
.string " How dare you!{WAIT_PRESS}\n"
.string "It's their fault!{EXTRA_MSG}"
.string " I haven't slept in days\n"
.string "because the earthquakes frighten me so!\n"
.string "Every night we had them!{EXTRA_MSG}"
.string " Those earthquakes are\n"
.string "caused by this brat's ilk running wild\n"
.string "underground!\0"
.align 2, 0

.global gSkarmoryPreFightDialogue_7
gSkarmoryPreFightDialogue_7: @ 8100A04
@ replacing .incbin "baserom.gba", 0x100A04, 0x17C
.byte 0x00, 0x00, 0x00, 0x02, 0xaa, 0x01, 0x07, 0x00
.4byte gUnknown_8100AD4
.byte 0x00, 0x00, 0x00, 0x02
.byte 0xaa, 0x01, 0x00, 0x00
.4byte gUnknown_8100A1C

.global gUnknown_8100A1C
gUnknown_8100A1C: @ 8100A1C
.string " That's not true.{EXTRA_MSG}"
.string "Well, it's true there have\n"
.string "been many earthquakes lately, but...{EXTRA_MSG}"
.string " It would take more than\n"
.string "{ARG_POKEMON_2}'s family going wild under\n"
.string "the ground to cause earthquakes.\0"
.align 2, 0

.global gUnknown_8100AD4
gUnknown_8100AD4: @ 8100AD4
.string " Whoa, that's not true.{EXTRA_MSG}"
.string " Sure there've been quakes\n"
.string "galore lately...{EXTRA_MSG}"
.string " But it would take more than\n"
.string "{ARG_POKEMON_2}'s family running wild under\n"
.string "the ground to set off a quake.\0"
.align 2, 0

.global gSkarmoryPreFightDialogue_8
gSkarmoryPreFightDialogue_8: @ 8100B80
@ replacing .incbin "baserom.gba", 0x100B80, 0x40
.byte 0x00, 0x00, 0x00, 0x0d, 0xfc, 0x00, 0x00, 0x00
.4byte gUnknown_8100B8C

.global gUnknown_8100B8C
gUnknown_8100B8C: @ 8100B8C
.string " You be quiet!{EXTRA_MSG}"
.string "We'll fight if you keep that up!\0"
.align 2, 0

.global gSkarmoryPreFightDialogue_9
gSkarmoryPreFightDialogue_9: @ 8100BC0
@ replacing .incbin "baserom.gba", 0x100BC0, 0xD0
.byte 0x00, 0x00, 0x04, 0x02, 0xaa, 0x01, 0x07, 0x00
.4byte gUnknown_8100C34
.byte 0x00, 0x00, 0x04, 0x02
.byte 0xaa, 0x01, 0x00, 0x00
.4byte gUnknown_8100BD8

.global gUnknown_8100BD8
gUnknown_8100BD8: @ 8100BD8
.string " It's no good.\n"
.string "{ARG_POKEMON_3} is too agitated to listen to\n"
.string "reason.{EXTRA_MSG}"
.string " We'll have to fight it out!\0"
.align 2, 0

.global gUnknown_8100C34
gUnknown_8100C34: @ 8100C34
.string " It's useless.\n"
.string "{ARG_POKEMON_3} is too steamed to talk\n"
.string "reasonably.{EXTRA_MSG}"
.string " We're going to have to\n"
.string "fight!\0"
.align 2, 0
@ Skarmory Re-Fight?

.global gSkarmoryReFightDialogue_1
gSkarmoryReFightDialogue_1: @ 8100C90
.byte 0x00, 0x00, 0x00, 0x0D
.byte 0xFC, 0x00, 0x00, 0x00
.4byte _08100C9C

.global _08100C9C
_08100C9C: @ 08100C9C
.string " You again?!\n"
.asciz "Persistent pests!\0"
.align 2,0

.global gSkarmoryReFightDialogue_2
gSkarmoryReFightDialogue_2: @ 8100CBC
@ replacing .incbin "baserom.gba", 0x100CBC, 0x20
.byte 0x00, 0x00, 0x03, 0x02, 0xaa, 0x01, 0x00, 0x00
.4byte gUnknown_8100CC8

.global gUnknown_8100CC8
gUnknown_8100CC8: @ 8100CC8
.string " Let {ARG_POKEMON_2} go!\n"
.string "{ARG_POKEMON_3}!\0"
.align 2, 0

.global gSkarmoryReFightDialogue_3
gSkarmoryReFightDialogue_3: @ 8100CDC
@ replacing .incbin "baserom.gba", 0x100CDC, 0x60
.byte 0x00, 0x00, 0x00, 0x0d, 0xfc, 0x00, 0x00, 0x00
.4byte gUnknown_8100CE8

.global gUnknown_8100CE8
gUnknown_8100CE8: @ 8100CE8
.string " I absolutely refuse!{EXTRA_MSG}"
.string " If you want to complain so\n"
.string "much, I'll give you a fight!\0"
.align 2, 0

.global gUnknown_8100D3C
gUnknown_8100D3C: @ 8100D3C
@ replacing .incbin "baserom.gba", 0x100D3C, 0x74
.byte 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.4byte gUnknown_8100D48

.global gUnknown_8100D48
gUnknown_8100D48: @ 8100D48
.string "{CENTER_ALIGN}There appears to be no one here.{EXTRA_MSG}"
.string "{CENTER_ALIGN}It's impossible to go any farther.{WAIT_PRESS}\n"
.string "{CENTER_ALIGN}It's time to go back.\0"
.align 2, 0

.global gTeamMeaniesPreFightDialogue_1
gTeamMeaniesPreFightDialogue_1: @ 8100DB0
@ replacing .incbin "baserom.gba", 0x100DB0, 0xB4
.byte 0x00, 0x00, 0x00, 0x02, 0xaa, 0x01, 0x07, 0x00
.4byte gUnknown_8100E18
.byte 0x00, 0x00, 0x00, 0x02
.byte 0xaa, 0x01, 0x00, 0x00
.4byte gUnknown_8100DC8

.global gUnknown_8100DC8
gUnknown_8100DC8: @ 8100DC8
.string " Wow, we came quite a ways\n"
.string "into this forest.{EXTRA_MSG}"
.string " I wonder if {ARG_POKEMON_2} is\n"
.string "ahead...\0"
.align 2, 0

.global gUnknown_8100E18
gUnknown_8100E18: @ 8100E18
.string " We've come pretty far\n"
.string "into this forest.{EXTRA_MSG}"
.string " I wonder if {ARG_POKEMON_2} is\n"
.string "ahead...\0"
.align 2, 0

.global gTeamMeaniesPreFightDialogue_2
gTeamMeaniesPreFightDialogue_2: @ 8100E64
@ replacing .incbin "baserom.gba", 0x100E64, 0x24
.byte 0x00, 0x00, 0x00, 0x00, 0xab, 0x01, 0x00, 0x00
.4byte gUnknown_8100E70

.global gUnknown_8100E70
gUnknown_8100E70: @ 8100E70
.string " Hold it right there!\0"
.align 2, 0

.global gTeamMeaniesPreFightDialogue_3
gTeamMeaniesPreFightDialogue_3: @ 8100E88
@ replacing .incbin "baserom.gba", 0x100E88, 0x8C
.byte 0x00, 0x00, 0x00, 0x0d, 0x5e, 0x00, 0x00, 0x00
.4byte gUnknown_8100E94

.global gUnknown_8100E94
gUnknown_8100E94: @ 8100E94
.string " Keke!\n"
.string "You know who's going to get to\n"
.string "{ARG_POKEMON_2} first? We are!{EXTRA_MSG}"
.string " So, for you to go ahead...{WAIT_PRESS}\n"
.string "Well, we can't let that happen.\0"
.align 2, 0

.global gTeamMeaniesPreFightDialogue_4
gTeamMeaniesPreFightDialogue_4: @ 8100F14
@ replacing .incbin "baserom.gba", 0x100F14, 0xF0
.byte 0x00, 0x00, 0x0c, 0x02, 0xaa, 0x01, 0x07, 0x00
.4byte gUnknown_8100FC0
.byte 0x00, 0x00, 0x0c, 0x02
.byte 0xaa, 0x01, 0x01, 0x00
.4byte gUnknown_8100F84
.byte 0x00, 0x00, 0x0c, 0x02, 0xaa, 0x01, 0x00, 0x00
.4byte gUnknown_8100F38

.global gUnknown_8100F38
gUnknown_8100F38: @ 8100F38
.string " Wh-what?!{EXTRA_MSG}"
.string " Now, hold on, {ARG_POKEMON_3}!{WAIT_PRESS}\n"
.string "Why do you always interfere with us?\0"
.align 2, 0

.global gUnknown_8100F84
gUnknown_8100F84: @ 8100F84
.string " Wh-what!{EXTRA_MSG}"
.string " Hey, {ARG_POKEMON_3}!{WAIT_PRESS}\n"
.string "Why do you always mess with us?\0"
.align 2, 0

.global gUnknown_8100FC0
gUnknown_8100FC0: @ 8100FC0
.string " Wh-what...?{EXTRA_MSG}"
.string " Hey, {ARG_POKEMON_3}!{WAIT_PRESS}\n"
.string "Why do you always try to mess with us?\0"
.align 2, 0

.global gTeamMeaniesPreFightDialogue_5
gTeamMeaniesPreFightDialogue_5: @ 8101004
@ replacing .incbin "baserom.gba", 0x101004, 0x4C
.byte 0x00, 0x00, 0x03, 0x0c, 0x4d, 0x01, 0x00, 0x00
.4byte gUnknown_8101010

.global gUnknown_8101010
gUnknown_8101010: @ 8101010
.string " Oh? Didn't we tell you?{WAIT_PRESS}\n"
.string "Our aim is world domination〜♪ \0"
.align 2, 0

.global gTeamMeaniesPreFightDialogue_6
gTeamMeaniesPreFightDialogue_6: @ 8101050
@ replacing .incbin "baserom.gba", 0x101050, 0x80
.byte 0x00, 0x00, 0x02, 0x0d, 0x17, 0x00, 0x00, 0x00
.4byte gUnknown_810105C

.global gUnknown_810105C
gUnknown_810105C: @ 810105C
.string " {ARG_POKEMON_4}'s mama will\n"
.string "give us a generous reward...{EXTRA_MSG}"
.string " And {ARG_POKEMON_4} will join\n"
.string "us too...{WAIT_PRESS}\n"
.string "That brings us closer to our goal.\0"
.align 2, 0

.global gTeamMeaniesPreFightDialogue_7
gTeamMeaniesPreFightDialogue_7: @ 81010D0
@ replacing .incbin "baserom.gba", 0x1010D0, 0x94
.byte 0x00, 0x00, 0x00, 0x0d, 0x5e, 0x00, 0x00, 0x00
.4byte gUnknown_81010DC

.global gUnknown_81010DC
gUnknown_81010DC: @ 81010DC
.string " Keke!\n"
.string "And for that, your lot is in the way!{EXTRA_MSG}"
.string " So sorry to say, but your\n"
.string "party's over right here and now!{EXTRA_MSG}"
.string " Say good-bye, {ARG_POKEMON_1}!\0"
.align 2, 0

.global gTeamMeaniesReFightDialogue_1
gTeamMeaniesReFightDialogue_1: @ 8101164
@ replacing .incbin "baserom.gba", 0x101164, 0xDC
.byte 0x00, 0x00, 0x00, 0x02, 0xaa, 0x01, 0x07, 0x00
.4byte gUnknown_81011E4
.byte 0x00, 0x00, 0x00, 0x02
.byte 0xaa, 0x01, 0x00, 0x00
.4byte gUnknown_810117C

.global gUnknown_810117C
gUnknown_810117C: @ 810117C
.string " This is where the {COLOR_1 CYAN}Meanies{END_COLOR_TEXT_1}\n"
.string "showed up last time.{EXTRA_MSG}"
.string " I wonder if {ARG_POKEMON_3}'s\n"
.string "bunch already found {ARG_POKEMON_2}...\0"
.align 2, 0

.global gUnknown_81011E4
gUnknown_81011E4: @ 81011E4
.string " Last time, this is where\n"
.string "{ARG_POKEMON_3}'s gang appeared.{EXTRA_MSG}"
.string " Did they find {ARG_POKEMON_2}\n"
.string "already, I wonder?\0"
.align 2, 0

.global gTeamMeaniesReFightDialogue_2
gTeamMeaniesReFightDialogue_2: @ 8101240
@ replacing .incbin "baserom.gba", 0x101240, 0xD0
.byte 0x00, 0x00, 0x0c, 0x02, 0xaa, 0x01, 0x07, 0x00
.4byte gUnknown_81012D4
.byte 0x00, 0x00, 0x0c, 0x02
.byte 0xaa, 0x01, 0x01, 0x00
.4byte gUnknown_810129C
.byte 0x00, 0x00, 0x0c, 0x02, 0xaa, 0x01, 0x00, 0x00
.4byte gUnknown_8101264

.global gUnknown_8101264
gUnknown_8101264: @ 8101264
.string " Huh? It's {ARG_POKEMON_3}!{EXTRA_MSG}"
.string " Why is {ARG_POKEMON_3}'s gang\n"
.string "following us?\0"
.align 2, 0

.global gUnknown_810129C
gUnknown_810129C: @ 810129C
.string " Huh? It's {ARG_POKEMON_3}!{EXTRA_MSG}"
.string " Why is the {ARG_POKEMON_3}\n"
.string "gang following us?\0"
.align 2, 0

.global gUnknown_81012D4
gUnknown_81012D4: @ 81012D4
.string " Hah? It's {ARG_POKEMON_3}!{EXTRA_MSG}"
.string " Why is {ARG_POKEMON_3}'s\n"
.string "crew coming after us?\0"
.align 2, 0

.global gTeamMeaniesReFightDialogue_3
gTeamMeaniesReFightDialogue_3: @ 8101310
@ replacing .incbin "baserom.gba", 0x101310, 0x6C
.byte 0x00, 0x00, 0x03, 0x0d, 0x5e, 0x00, 0x00, 0x00
.4byte gUnknown_810131C

.global gUnknown_810131C
gUnknown_810131C: @ 810131C
.string " Y-you be quiet!{EXTRA_MSG}"
.string " Right after we beat you last\n"
.string "time...{EXTRA_MSG}"
.string " We got careless and wiped\n"
.string "out too!\0"
.align 2, 0

.global gTeamMeaniesReFightDialogue_4
gTeamMeaniesReFightDialogue_4: @ 810137C
@ replacing .incbin "baserom.gba", 0x10137C, 0x8C
.byte 0x01, 0x00, 0x03, 0x0d, 0x5e, 0x00, 0x00, 0x00
.4byte gUnknown_8101388

.global gUnknown_8101388
gUnknown_8101388: @ 8101388
.string " Don't you laugh at me!{WAIT_PRESS}\n"
.string "What makes you so high-and-mighty?{EXTRA_MSG}"
.string " Whatever happens, we're\n"
.string "not going to lose to you amateurs!\0"
.align 2, 0

.global gTeamMeaniesReFightDialogue_5
gTeamMeaniesReFightDialogue_5: @ 8101408
@ replacing .incbin "baserom.gba", 0x101408, 0x38
.byte 0x00, 0x00, 0x02, 0x0d, 0x5e, 0x00, 0x00, 0x00
.4byte gUnknown_8101414

.global gUnknown_8101414
gUnknown_8101414: @ 8101414
.string " This is it, {ARG_POKEMON_1}!\n"
.string "You're going down!\0"
.align 2, 0

.global gUnknown_8101440
gUnknown_8101440: @ 8101440
@ replacing .incbin "baserom.gba", 0x101440, 0x70
.byte 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.4byte gUnknown_810144C

.global gUnknown_810144C
gUnknown_810144C: @ 810144C
.string "{CENTER_ALIGN}It's impossible to go any farther...{WAIT_PRESS}\n"
.string "{CENTER_ALIGN}But there is nothing here.{EXTRA_MSG}"
.string "{CENTER_ALIGN}It's time to go back.\0"
.align 2, 0

.global gUnknown_81014B0
gUnknown_81014B0: @ 81014B0
@ replacing .incbin "baserom.gba", 0x1014B0, 0x54
.byte 0x00, 0x00, 0x00, 0x02, 0xaa, 0x01, 0x07, 0x00
.4byte gUnknown_81014E0
.byte 0x00, 0x00, 0x00, 0x02
.byte 0xaa, 0x01, 0x00, 0x00
.4byte gUnknown_81014C8

.global gUnknown_81014C8
gUnknown_81014C8: @ 81014C8
.string " This is the summit...\0"
.align 2, 0

.global gUnknown_81014E0
gUnknown_81014E0: @ 81014E0
.string " This is the mountain's peak...\0"
.align 2, 0

.global gUnknown_8101504
gUnknown_8101504: @ 8101504
@ replacing .incbin "baserom.gba", 0x101504, 0x9C
.byte 0x00, 0x00, 0x03, 0x02, 0xaa, 0x01, 0x07, 0x00
.4byte gUnknown_810155C
.byte 0x00, 0x00, 0x03, 0x02
.byte 0xaa, 0x01, 0x00, 0x00
.4byte gUnknown_810151C

.global gUnknown_810151C
gUnknown_810151C: @ 810151C
.string " Hey! {ARG_POKEMON_3}!\n"
.string "Where are you?!{EXTRA_MSG}"
.string " We came to rescue\n"
.string "{ARG_POKEMON_2}!\n"
.string "Come out!\0"
.align 2, 0

.global gUnknown_810155C
gUnknown_810155C: @ 810155C
.string " Hey! {ARG_POKEMON_3}!\n"
.string "Where are you?!{EXTRA_MSG}"
.string " We came to rescue\n"
.string "{ARG_POKEMON_2}!\n"
.string "Show yourself!\0"
.align 2, 0

.global gUnknown_81015A0
gUnknown_81015A0: @ 81015A0
@ replacing .incbin "baserom.gba", 0x1015A0, 0x34
.byte 0x05, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.4byte gUnknown_81015AC

.global gUnknown_81015AC
gUnknown_81015AC: @ 81015AC
.string "Gyaoooooooooh!\n"
.string "                     \0"
.align 2, 0

.global gUnknown_81015D4
gUnknown_81015D4: @ 81015D4
@ replacing .incbin "baserom.gba", 0x1015D4, 0x14
.byte 0x00, 0x00, 0x0c, 0x02, 0xaa, 0x01, 0x00, 0x00
.4byte gUnknown_81015E0

.global gUnknown_81015E0
gUnknown_81015E0: @ 81015E0
.string " Waah!\0"
.align 2, 0

.global gUnknown_81015E8
gUnknown_81015E8: @ 81015E8
@ replacing .incbin "baserom.gba", 0x1015E8, 0x3C
.byte 0x00, 0x00, 0x00, 0x0d, 0x91, 0x00, 0x00, 0x00
.4byte gUnknown_81015F4

.global gUnknown_81015F4
gUnknown_81015F4: @ 81015F4
.string " I warned you!\n"
.string "I have no mercy for meddlers!\0"
.align 2, 0

.global gUnknown_8101624
gUnknown_8101624: @ 8101624
@ replacing .incbin "baserom.gba", 0x101624, 0x38
.byte 0x00, 0x00, 0x02, 0x02, 0xaa, 0x01, 0x00, 0x00
.4byte gUnknown_8101630

.global gUnknown_8101630
gUnknown_8101630: @ 8101630
.string " Not scared...{WAIT_PRESS}\n"
.string "You don't frighten me!\0"
.align 2, 0

.global gUnknown_810165C
gUnknown_810165C: @ 810165C
@ replacing .incbin "baserom.gba", 0x10165C, 0xF4
.byte 0x00, 0x00, 0x03, 0x02, 0xaa, 0x01, 0x07, 0x00
.4byte gUnknown_8101708
.byte 0x00, 0x00, 0x03, 0x02
.byte 0xaa, 0x01, 0x01, 0x00
.4byte gUnknown_81016CC
.byte 0x00, 0x00, 0x03, 0x02, 0xaa, 0x01, 0x00, 0x00
.4byte gUnknown_8101680

.global gUnknown_8101680
gUnknown_8101680: @ 8101680
.string " Hey, {ARG_POKEMON_3}!\n"
.string "We demand you release {ARG_POKEMON_2}!{EXTRA_MSG}"
.string " We're a Pokémon rescue\n"
.string "team!\0"
.align 2, 0

.global gUnknown_81016CC
gUnknown_81016CC: @ 81016CC
.string " Hey, {ARG_POKEMON_3}!\n"
.string "Release {ARG_POKEMON_2}!{EXTRA_MSG}"
.string " We're a Pokémon rescue\n"
.string "team!\0"
.align 2, 0

.global gUnknown_8101708
gUnknown_8101708: @ 8101708
.string " Hey, {ARG_POKEMON_3}!\n"
.string "Let {ARG_POKEMON_2} go!{EXTRA_MSG}"
.string " A Pokémon rescue team!\n"
.string "That's what we are!\0"
.align 2, 0

.global gUnknown_8101750
gUnknown_8101750: @ 8101750
@ replacing .incbin "baserom.gba", 0x101750, 0x3C
.byte 0x00, 0x00, 0x00, 0x0d, 0x91, 0x00, 0x00, 0x00
.4byte gUnknown_810175C

.global gUnknown_810175C
gUnknown_810175C: @ 810175C
.string " You must be determined,\n"
.string "to utter such words.\0"
.align 2, 0

.global gUnknown_810178C
gUnknown_810178C: @ 810178C
@ replacing .incbin "baserom.gba", 0x10178C, 0x28
.byte 0x00, 0x00, 0x00, 0x0d, 0x91, 0x00, 0x00, 0x00
.4byte gUnknown_8101798

.global gUnknown_8101798
gUnknown_8101798: @ 8101798
.string " Then you shall answer...\0"
.align 2, 0

.global gUnknown_81017B4
gUnknown_81017B4: @ 81017B4
@ replacing .incbin "baserom.gba", 0x1017B4, 0x30
.byte 0x00, 0x00, 0x00, 0x0d, 0x91, 0x00, 0x00, 0x00
.4byte gUnknown_81017C0

.global gUnknown_81017C0
gUnknown_81017C0: @ 81017C0
.string " To my great and righteous\n"
.string "fury!\0"
.align 2, 0

.global gZapdosReFightDialogue_1
gZapdosReFightDialogue_1: @ 81017E4
@ replacing .incbin "baserom.gba", 0x1017E4, 0xB4
.byte 0x00, 0x00, 0x03, 0x02, 0xaa, 0x01, 0x07, 0x00
.4byte gUnknown_8101864
.byte 0x00, 0x00, 0x03, 0x02
.byte 0xaa, 0x01, 0x01, 0x00
.4byte gUnknown_810183C
.byte 0x00, 0x00, 0x03, 0x02, 0xaa, 0x01, 0x00, 0x00
.4byte gUnknown_8101808

.global gUnknown_8101808
gUnknown_8101808: @ 8101808
.string " Hey, {ARG_POKEMON_3}!\n"
.string "We're here again!{EXTRA_MSG}"
.string " Show yourself!\0"
.align 2, 0

.global gUnknown_810183C
gUnknown_810183C: @ 810183C
.string " Hey, {ARG_POKEMON_3}!\n"
.string "We're back!{EXTRA_MSG}"
.string " Come out!\0"
.align 2, 0

.global gUnknown_8101864
gUnknown_8101864: @ 8101864
.string " Hey, {ARG_POKEMON_3}!\n"
.string "Guess who's back?!{EXTRA_MSG}"
.string " Show yourself!\0"
.align 2, 0

.global gZapdosReFightDialogue_2
gZapdosReFightDialogue_2: @ 8101898
@ replacing .incbin "baserom.gba", 0x101898, 0x54
.byte 0x00, 0x00, 0x00, 0x0d, 0x91, 0x00, 0x00, 0x00
.4byte gUnknown_81018A4

.global gUnknown_81018A4
gUnknown_81018A4: @ 81018A4
.string " However often you may\n"
.string "return...\n"
.string "The result will always be the same!\0"
.align 2, 0

.global gZapdosReFightDialogue_3
gZapdosReFightDialogue_3: @ 81018EC
@ replacing .incbin "baserom.gba", 0x1018EC, 0x2C
.byte 0x00, 0x00, 0x00, 0x0d, 0x91, 0x00, 0x00, 0x00
.4byte gUnknown_81018F8

.global gUnknown_81018F8
gUnknown_81018F8: @ 81018F8
.string " You have no hope of\n"
.string "winning!\0"
.align 2, 0

.global gZapdosReFightDialogue_4
gZapdosReFightDialogue_4: @ 8101918
@ replacing .incbin "baserom.gba", 0x101918, 0x24
.byte 0x00, 0x00, 0x00, 0x0d, 0x91, 0x00, 0x00, 0x00
.4byte gUnknown_8101924

.global gUnknown_8101924
gUnknown_8101924: @ 8101924
.string " Prepare yourselves!\0"
.align 2, 0

.global gZapdosPostStoryPreFightDialogue_1
gZapdosPostStoryPreFightDialogue_1: @ 810193C
@ replacing .incbin "baserom.gba", 0x10193C, 0x34
.byte 0x05, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.4byte gUnknown_8101948

.global gUnknown_8101948
gUnknown_8101948: @ 8101948
.string "Gyaoooooooooooh!\n"
.string "                     \0"
.align 2, 0

.global gZapdosPostStoryPreFightDialogue_2
gZapdosPostStoryPreFightDialogue_2: @ 8101970
@ replacing .incbin "baserom.gba", 0x101970, 0x24
.byte 0x00, 0x00, 0x00, 0x0d, 0x91, 0x00, 0x00, 0x00
.4byte gUnknown_810197C

.global gUnknown_810197C
gUnknown_810197C: @ 810197C
.string " So, you're back!\0"
.align 2, 0

.global gZapdosPostStoryPreFightDialogue_3
gZapdosPostStoryPreFightDialogue_3: @ 8101994
@ replacing .incbin "baserom.gba", 0x101994, 0x50
.byte 0x00, 0x00, 0x00, 0x0d, 0x91, 0x00, 0x00, 0x00
.4byte gUnknown_81019A0

.global gUnknown_81019A0
gUnknown_81019A0: @ 81019A0
.string " Since we last met, how\n"
.string "much more have you furthered your team?\0"
.align 2, 0

.global gZapdosPostStoryPreFightDialogue_4
gZapdosPostStoryPreFightDialogue_4: @ 81019E4
@ replacing .incbin "baserom.gba", 0x1019E4, 0x20
.byte 0x00, 0x00, 0x00, 0x0d, 0x91, 0x00, 0x00, 0x00
.4byte gUnknown_81019F0

.global gUnknown_81019F0
gUnknown_81019F0: @ 81019F0
.string " How much stronger?\0"
.align 2, 0

.global gZapdosPostStoryPreFightDialogue_5
gZapdosPostStoryPreFightDialogue_5: @ 8101A04
@ replacing .incbin "baserom.gba", 0x101A04, 0x34
.byte 0x00, 0x00, 0x00, 0x0d, 0x91, 0x00, 0x00, 0x00
.4byte gUnknown_8101A10

.global gUnknown_8101A10
gUnknown_8101A10: @ 8101A10
.string " Your power...{WAIT_PRESS}\n"
.string "Demonstrate it for me!\0"
.align 2, 0

.global gZapdosPostStoryPreFightDialogue_6
gZapdosPostStoryPreFightDialogue_6: @ 8101A38
@ replacing .incbin "baserom.gba", 0x101A38, 0x64
.byte 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.4byte gUnknown_8101A44

.global gUnknown_8101A44
gUnknown_8101A44: @ 8101A44
.string "{CENTER_ALIGN}The mountain's summit...{WAIT_PRESS}\n"
.string "{CENTER_ALIGN}But there is no one here.{EXTRA_MSG}"
.string "{CENTER_ALIGN}It's time to go back.\0"
.align 2, 0

.global gMoltresPreFightDialogue_1
gMoltresPreFightDialogue_1: @ 8101A9C
@ replacing .incbin "baserom.gba", 0x101A9C, 0x38
.byte 0x00, 0x00, 0x00, 0x0d, 0xaa, 0x01, 0x00, 0x00
.4byte gUnknown_8101AA8

.global gUnknown_8101AA8
gUnknown_8101AA8: @ 8101AA8
.string " Is this it?\n"
.string "Is this Mt. Blaze's summit?\0"
.align 2, 0

.global gMoltresPreFightDialogue_2
gMoltresPreFightDialogue_2: @ 8101AD4
@ replacing .incbin "baserom.gba", 0x101AD4, 0x15C
.byte 0x00, 0x00, 0x02, 0x0d, 0xaa, 0x01, 0x07, 0x00
.4byte gUnknown_8101B8C
.byte 0x00, 0x00, 0x02, 0x0d
.byte 0xaa, 0x01, 0x00, 0x00
.4byte gUnknown_8101AEC

.global gUnknown_8101AEC
gUnknown_8101AEC: @ 8101AEC
.string " Wow. This is incredible.{WAIT_PRESS}\n"
.string "I know it's a volcano, but the lava flow\n"
.string "is much higher than normal.{EXTRA_MSG}"
.string " This might also have a link\n"
.string "to the natural calamities...\0"
.align 2, 0

.global gUnknown_8101B8C
gUnknown_8101B8C: @ 8101B8C
.string " This is one incredible place.{WAIT_PRESS}\n"
.string "I know this is a volcano, but the amount\n"
.string "of lava is way more than usual.{EXTRA_MSG}"
.string " This might also be a part of\n"
.string "the natural disasters...\0"
.align 2, 0

.global gMoltresPreFightDialogue_3
gMoltresPreFightDialogue_3: @ 8101C30
@ replacing .incbin "baserom.gba", 0x101C30, 0x8C
.byte 0x00, 0x00, 0x0c, 0x0d, 0xaa, 0x01, 0x07, 0x00
.4byte gUnknown_8101C80
.byte 0x00, 0x00, 0x0c, 0x0d
.byte 0xaa, 0x01, 0x00, 0x00
.4byte gUnknown_8101C48

.global gUnknown_8101C48
gUnknown_8101C48: @ 8101C48
.string " Oogh! It's like a furnace!{WAIT_PRESS}\n"
.string "I'm getting roasted!\0"
.align 2, 0

.global gUnknown_8101C80
gUnknown_8101C80: @ 8101C80
.string " Yowch! It's wicked hot!{WAIT_PRESS}\n"
.string "I feel like I'm burning up.\0"
.align 2, 0

.global gMoltresPreFightDialogue_4
gMoltresPreFightDialogue_4: @ 8101CBC
@ replacing .incbin "baserom.gba", 0x101CBC, 0xD0
.byte 0x00, 0x00, 0x04, 0x12, 0xaa, 0x01, 0x07, 0x00
.4byte gUnknown_8101D34
.byte 0x00, 0x00, 0x04, 0x12
.byte 0xaa, 0x01, 0x00, 0x00
.4byte gUnknown_8101CD4

.global gUnknown_8101CD4
gUnknown_8101CD4: @ 8101CD4
.string " I don't want to spend any\n"
.string "time in a place this dangerous.{EXTRA_MSG}"
.string " Let's get through this quick.\0"
.align 2, 0

.global gUnknown_8101D34
gUnknown_8101D34: @ 8101D34
.string " I don't want to be in a place\n"
.string "this wickedly bad.{EXTRA_MSG}"
.string " Let's get through here quick.\0"
.align 2, 0

.global gMoltresPreFightDialogue_5
gMoltresPreFightDialogue_5: @ 8101D8C
@ replacing .incbin "baserom.gba", 0x101D8C, 0x14
.byte 0x00, 0x00, 0x00, 0x00, 0xab, 0x01, 0x00, 0x00
.4byte gUnknown_8101D98

.global gUnknown_8101D98
gUnknown_8101D98: @ 8101D98
.string " Halt!\0"
.align 2, 0

.global gMoltresPreFightDialogue_6
gMoltresPreFightDialogue_6: @ 8101DA0
@ replacing .incbin "baserom.gba", 0x101DA0, 0x7C
.byte 0x00, 0x00, 0x04, 0x02, 0xaa, 0x01, 0x07, 0x00
.4byte gUnknown_8101DE4
.byte 0x00, 0x00, 0x04, 0x02
.byte 0xaa, 0x01, 0x00, 0x00
.4byte gUnknown_8101DB8

.global gUnknown_8101DB8
gUnknown_8101DB8: @ 8101DB8
.string " Huh, what?!{EXTRA_MSG}"
.string " It suddenly turned dark!\0"
.align 2, 0

.global gUnknown_8101DE4
gUnknown_8101DE4: @ 8101DE4
.string " Wh-what the...?!{EXTRA_MSG}"
.string " Why did it turn dark like\n"
.string "that?!\0"
.align 2, 0

.global gMoltresPreFightDialogue_7
gMoltresPreFightDialogue_7: @ 8101E1C
@ replacing .incbin "baserom.gba", 0x101E1C, 0x90
.byte 0x00, 0x00, 0x00, 0x00, 0xab, 0x01, 0x00, 0x00
.4byte gUnknown_8101E28

.global gUnknown_8101E28
gUnknown_8101E28: @ 8101E28
.string " I can hear the mountain's screams...{EXTRA_MSG}"
.string " It is shrieking in pain...{EXTRA_MSG}"
.string " Someone is causing Mt. Blaze to\n"
.string "writhe in agony!\n"
.string "Is it you?!\0"
.align 2, 0

.global gMoltresPreFightDialogue_8
gMoltresPreFightDialogue_8: @ 8101EAC
@ replacing .incbin "baserom.gba", 0x101EAC, 0x1C4
.byte 0x00, 0x00, 0x0c, 0x02, 0xaa, 0x01, 0x07, 0x00
.4byte gUnknown_8101FD4
.byte 0x00, 0x00, 0x0c, 0x02
.byte 0xaa, 0x01, 0x01, 0x00
.4byte gUnknown_8101F48
.byte 0x00, 0x00, 0x0c, 0x02, 0xaa, 0x01, 0x00, 0x00
.4byte gUnknown_8101ED0

.global gUnknown_8101ED0
gUnknown_8101ED0: @ 8101ED0
.string " Huh?!{WAIT_PRESS}\n"
.string "That's wrong!\n"
.string "We're innocent!{EXTRA_MSG}"
.string " We were just passing\n"
.string "through!{EXTRA_MSG}"
.string " Who are you, anyway?{WAIT_PRESS}\n"
.string "Show yourself!\0"
.align 2, 0

.global gUnknown_8101F48
gUnknown_8101F48: @ 8101F48
.string " Huh?!{WAIT_PRESS}\n"
.string "You've got it wrong!\n"
.string "It's not us!{EXTRA_MSG}"
.string " We just happened to be\n"
.string "passing through here!{EXTRA_MSG}"
.string " Who are you, anyway?{WAIT_PRESS}\n"
.string "Show yourself!\n"
.string " \0"
.align 2, 0

.global gUnknown_8101FD4
gUnknown_8101FD4: @ 8101FD4
.string " Hah?!{WAIT_PRESS}\n"
.string "We don't know what you mean!\n"
.string "We're not doing anything!{EXTRA_MSG}"
.string " We just happened to be\n"
.string "traveling through here!{EXTRA_MSG}"
.string " Who are you, anyway?{WAIT_PRESS}\n"
.string "Come out!\0"
.align 2, 0

.global gMoltresPreFightDialogue_9
gMoltresPreFightDialogue_9: @ 8102070
@ replacing .incbin "baserom.gba", 0x102070, 0x34
.byte 0x05, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.4byte gUnknown_810207C

.global gUnknown_810207C
gUnknown_810207C: @ 810207C
.string "Gyaaaaaaaaaaaa!\n"
.string "                     \0"
.align 2, 0

.global gMoltresPreFightDialogue_10
gMoltresPreFightDialogue_10: @ 81020A4
@ replacing .incbin "baserom.gba", 0x1020A4, 0x30
.byte 0x00, 0x00, 0x00, 0x00, 0xab, 0x01, 0x00, 0x00
.4byte gUnknown_81020B0

.global gUnknown_81020B0
gUnknown_81020B0: @ 81020B0
.string " The mountain's rage is my rage!\0"
.align 2, 0

.global gMoltresPreFightDialogue_11
gMoltresPreFightDialogue_11: @ 81020D4
@ replacing .incbin "baserom.gba", 0x1020D4, 0x34
.byte 0x02, 0x00, 0x00, 0x0d, 0x92, 0x00, 0x00, 0x00
.4byte gUnknown_81020E0

.global gUnknown_81020E0
gUnknown_81020E0: @ 81020E0
.string " I am {ARG_POKEMON_2}!\n"
.string "The warrior of fire am I!\0"
.align 2, 0

.global gMoltresPreFightDialogue_12
gMoltresPreFightDialogue_12: @ 8102108
@ replacing .incbin "baserom.gba", 0x102108, 0x50
.byte 0x00, 0x00, 0x00, 0x0d, 0x92, 0x00, 0x00, 0x00
.4byte gUnknown_8102114

.global gUnknown_8102114
gUnknown_8102114: @ 8102114
.string " There is no forgiving \n"
.string "those who befoul the mountain!\n"
.string "En garde!\0"
.align 2, 0

.global gMoltresReFightDialogue_1
gMoltresReFightDialogue_1: @ 8102158
@ replacing .incbin "baserom.gba", 0x102158, 0x38
.byte 0x00, 0x00, 0x00, 0x0d, 0xaa, 0x01, 0x00, 0x00
.4byte gUnknown_8102164

.global gUnknown_8102164
gUnknown_8102164: @ 8102164
.string " ............{WAIT_PRESS}\n"
.string "Maybe {ARG_POKEMON_2} isn't around...\0"
.align 2, 0

.global gMoltresReFightDialogue_2
gMoltresReFightDialogue_2: @ 8102190
@ replacing .incbin "baserom.gba", 0x102190, 0x70
.byte 0x00, 0x00, 0x01, 0x12, 0xaa, 0x01, 0x07, 0x00
.4byte gUnknown_81021D8
.byte 0x00, 0x00, 0x01, 0x12
.byte 0xaa, 0x01, 0x00, 0x00
.4byte gUnknown_81021A8

.global gUnknown_81021A8
gUnknown_81021A8: @ 81021A8
.string " Let's slip by here while\n"
.string "we have the chance.\0"
.align 2, 0

.global gUnknown_81021D8
gUnknown_81021D8: @ 81021D8
.string " Let's sneak through while\n"
.string "we can.\0"
.align 2, 0

.global gMoltresReFightDialogue_3
gMoltresReFightDialogue_3: @ 8102200
@ replacing .incbin "baserom.gba", 0x102200, 0x54
.byte 0x00, 0x00, 0x00, 0x0d, 0x92, 0x00, 0x00, 0x00
.4byte gUnknown_810220C

.global gUnknown_810220C
gUnknown_810220C: @ 810220C
.string " You again!{EXTRA_MSG}"
.string " There is no forgiving \n"
.string "those who torment the mountain!\0"
.align 2, 0

.global gMoltresReFightDialogue_4
gMoltresReFightDialogue_4: @ 8102254
@ replacing .incbin "baserom.gba", 0x102254, 0xA4
.byte 0x00, 0x00, 0x0c, 0x02, 0xaa, 0x01, 0x07, 0x00
.4byte gUnknown_81022CC
.byte 0x00, 0x00, 0x0c, 0x02
.byte 0xaa, 0x01, 0x01, 0x00
.4byte gUnknown_81022A0
.byte 0x00, 0x00, 0x0c, 0x02, 0xaa, 0x01, 0x00, 0x00
.4byte gUnknown_8102278

.global gUnknown_8102278
gUnknown_8102278: @ 8102278
.string " Won't you listen?!{WAIT_PRESS}\n"
.string "We're only...\0"
.align 2, 0

.global gUnknown_81022A0
gUnknown_81022A0: @ 81022A0
.string " You don't understand!{WAIT_PRESS}\n"
.string "We're only...\0"
.align 2, 0

.global gUnknown_81022CC
gUnknown_81022CC: @ 81022CC
.string " You've got us wrong!{WAIT_PRESS}\n"
.string "We're just...\0"
.align 2, 0

.global gMoltresReFightDialogue_5
gMoltresReFightDialogue_5: @ 81022F8
@ replacing .incbin "baserom.gba", 0x1022F8, 0x34
.byte 0x00, 0x00, 0x00, 0x0d, 0x92, 0x00, 0x00, 0x00
.4byte gUnknown_8102304

.global gUnknown_8102304
gUnknown_8102304: @ 8102304
.string " Your words are\n"
.string "meaningless!\n"
.string "En garde!\0"
.align 2, 0

.global gMoltresPostStoryPreFightDialogue_1
gMoltresPostStoryPreFightDialogue_1: @ 810232C
@ replacing .incbin "baserom.gba", 0x10232C, 0x6C
.byte 0x00, 0x00, 0x00, 0x0d, 0x92, 0x00, 0x00, 0x00
.4byte gUnknown_8102338

.global gUnknown_8102338
gUnknown_8102338: @ 8102338
.string " Halt!{EXTRA_MSG}"
.string " This is Mt. Blaze!{EXTRA_MSG}"
.string " For you to venture to its\n"
.string "peak, there can be but one reason!\0"
.align 2, 0

.global gMoltresPostStoryPreFightDialogue_2
gMoltresPostStoryPreFightDialogue_2: @ 8102398
@ replacing .incbin "baserom.gba", 0x102398, 0x2C
.byte 0x00, 0x00, 0x00, 0x0d, 0x92, 0x00, 0x00, 0x00
.4byte gUnknown_81023A4

.global gUnknown_81023A4
gUnknown_81023A4: @ 81023A4
.string " You've come to challenge\n"
.string "me!\0"
.align 2, 0

.global gMoltresPostStoryPreFightDialogue_3
gMoltresPostStoryPreFightDialogue_3: @ 81023C4
@ replacing .incbin "baserom.gba", 0x1023C4, 0x3C
.byte 0x00, 0x00, 0x00, 0x0d, 0x92, 0x00, 0x00, 0x00
.4byte gUnknown_81023D0

.global gUnknown_81023D0
gUnknown_81023D0: @ 81023D0
.string " So be it!{WAIT_PRESS}\n"
.string "I am the warrior of fire, {ARG_POKEMON_2}!\0"
.align 2, 0

.global gMoltresPostStoryPreFightDialogue_4
gMoltresPostStoryPreFightDialogue_4: @ 8102400
@ replacing .incbin "baserom.gba", 0x102400, 0x54
.byte 0x00, 0x00, 0x00, 0x0d, 0x92, 0x00, 0x00, 0x00
.4byte gUnknown_810240C

.global gUnknown_810240C
gUnknown_810240C: @ 810240C
.string " Have you what it takes to\n"
.string "defeat me when I am holding back nothing?\0"
.align 2, 0

.global gMoltresPostStoryPreFightDialogue_5
gMoltresPostStoryPreFightDialogue_5: @ 8102454
@ replacing .incbin "baserom.gba", 0x102454, 0x24
.byte 0x00, 0x00, 0x00, 0x0d, 0x92, 0x00, 0x00, 0x00
.4byte gUnknown_8102460

.global gUnknown_8102460
gUnknown_8102460: @ 8102460
.string " Show me!\0"
.align 2, 0

.global gUnknown_810246C
gUnknown_810246C: @ 810246C
.byte 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.4byte gUnknown_8101A44

.global gArticunoPreFightDialogue_1
gArticunoPreFightDialogue_1: @ 8102478
@ replacing .incbin "baserom.gba", 0x102478, 0x13C
.byte 0x00, 0x00, 0x00, 0x02, 0xaa, 0x01, 0x07, 0x00
.4byte gUnknown_8102524
.byte 0x00, 0x00, 0x00, 0x02
.byte 0xaa, 0x01, 0x00, 0x00
.4byte gUnknown_8102490

.global gUnknown_8102490
gUnknown_8102490: @ 8102490
.string " We sure have traveled far\n"
.string "into this forest.{EXTRA_MSG}"
.string " I think we'll be out if we\n"
.string "can get through this part.{WAIT_PRESS}\n"
.string "It shouldn't be far. Let's keep going.\0"
.align 2, 0

.global gUnknown_8102524
gUnknown_8102524: @ 8102524
.string " We've come pretty far into\n"
.string "the forest.{EXTRA_MSG}"
.string " I think we'll be out if we\n"
.string "can get through this part.{WAIT_PRESS}\n"
.string "It shouldn't be long. Hang in there.\0"
.align 2, 0

.global gArticunoPreFightDialogue_2
gArticunoPreFightDialogue_2: @ 81025B4
@ replacing .incbin "baserom.gba", 0x1025B4, 0x20
.byte 0x00, 0x00, 0x00, 0x00, 0xab, 0x01, 0x00, 0x00
.4byte gUnknown_81025C0

.global gUnknown_81025C0
gUnknown_81025C0: @ 81025C0
.string " ...............\0"
.align 2, 0

.global gArticunoPreFightDialogue_3
gArticunoPreFightDialogue_3: @ 81025D4
@ replacing .incbin "baserom.gba", 0x1025D4, 0x3C
.byte 0x00, 0x00, 0x04, 0x02, 0xaa, 0x01, 0x00, 0x00
.4byte gUnknown_81025E0

.global gUnknown_81025E0
gUnknown_81025E0: @ 81025E0
.string " ...Huh?{WAIT_PRESS}\n"
.string "{ARG_POKEMON_0}, did you just say something?\0"
.align 2, 0

.global gArticunoPreFightDialogue_4
gArticunoPreFightDialogue_4: @ 8102610
@ replacing .incbin "baserom.gba", 0x102610, 0xB4
.byte 0x00, 0x00, 0x00, 0x02, 0xaa, 0x01, 0x07, 0x00
.4byte gUnknown_8102680
.byte 0x00, 0x00, 0x00, 0x02
.byte 0xaa, 0x01, 0x00, 0x00
.4byte gUnknown_8102628

.global gUnknown_8102628
gUnknown_8102628: @ 8102628
.string " ...I didn't think so...{EXTRA_MSG}"
.string " I thought I heard a voice...{WAIT_PRESS}\n"
.string "I must have imagined it.\0"
.align 2, 0

.global gUnknown_8102680
gUnknown_8102680: @ 8102680
.string " ...I didn't think so.{EXTRA_MSG}"
.string " A voice...?{WAIT_PRESS}\n"
.string "I must've imagined it.\0"
.align 2, 0

.global gArticunoPreFightDialogue_5
gArticunoPreFightDialogue_5: @ 81026C4
@ replacing .incbin "baserom.gba", 0x1026C4, 0x48
.byte 0x00, 0x00, 0x00, 0x00, 0xab, 0x01, 0x00, 0x00
.4byte gUnknown_81026D0

.global gUnknown_81026D0
gUnknown_81026D0: @ 81026D0
.string " ..................{EXTRA_MSG}"
.string " ...Turn back.{EXTRA_MSG}"
.string "You may not pass...\0"
.align 2, 0

.global gArticunoPreFightDialogue_6
gArticunoPreFightDialogue_6: @ 810270C
@ replacing .incbin "baserom.gba", 0x10270C, 0x20
.byte 0x00, 0x00, 0x0c, 0x02, 0xaa, 0x01, 0x00, 0x00
.4byte gUnknown_8102718

.global gUnknown_8102718
gUnknown_8102718: @ 8102718
.string " Who's there?!\0"
.align 2, 0

.global gArticunoPreFightDialogue_7
gArticunoPreFightDialogue_7: @ 810272C
@ replacing .incbin "baserom.gba", 0x10272C, 0x90
.byte 0x00, 0x00, 0x00, 0x00, 0xab, 0x01, 0x00, 0x00
.4byte gUnknown_8102738

.global gUnknown_8102738
gUnknown_8102738: @ 8102738
.string " You are forbidden to pass...{EXTRA_MSG}"
.string " ...If you persist in trying to pass...{EXTRA_MSG}"
.string " Then, so be it...{EXTRA_MSG}"
.string " But only after you have defeated me!\0"
.align 2, 0

.global gArticunoPreFightDialogue_8
gArticunoPreFightDialogue_8: @ 81027BC
@ replacing .incbin "baserom.gba", 0x1027BC, 0x54
.byte 0x00, 0x00, 0x02, 0x02, 0xaa, 0x01, 0x00, 0x00
.4byte gUnknown_81027C8

.global gUnknown_81027C8
gUnknown_81027C8: @ 81027C8
.string " Ow! It's too bright!{EXTRA_MSG}"
.string " The ice around us is\n"
.string "reflecting this light!\0"
.align 2, 0

.global gArticunoPreFightDialogue_9
gArticunoPreFightDialogue_9: @ 8102810
@ replacing .incbin "baserom.gba", 0x102810, 0x30
.byte 0x05, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.4byte gUnknown_810281C

.global gUnknown_810281C
gUnknown_810281C: @ 810281C
.string "Gyaaaaaaaaah!\n"
.string "                     \0"
.align 2, 0

.global gArticunoPreFightDialogue_10
gArticunoPreFightDialogue_10: @ 8102840
.4byte 0x0d000000
.4byte 0x000001ab
.4byte gUnknown_810284C

.global gUnknown_810284C
gUnknown_810284C: @ 810284C

.global gUnknown_810284C
gUnknown_810284C: @ 810284C
.string " I am {ARG_POKEMON_2}!{WAIT_PRESS}\n"
.string "The warder of ice!\0"

.global gArticunoPreFightDialogue_11
gArticunoPreFightDialogue_11: @ 810286C
@ replacing .incbin "baserom.gba", 0x0010286c, 0x4c
.4byte 0x0d000000
.4byte 0x00000090
.4byte gUnknown_8102878

.global gUnknown_8102878
gUnknown_8102878: @ 8102878
.string " Those that enter the forest\n"
.string "I shall destroy with all my might!\0"

.global gArticunoPreFightDialogue_12
gArticunoPreFightDialogue_12: @ 81028B8
.4byte 0x0d000000
.4byte 0x00000090
.4byte gUnknown_81028C4

.global gUnknown_81028C4
gUnknown_81028C4: @ 81028C4
.string " Let us begin!\0"
.align 2, 0

.global gArticunoReFightDialogue_1
gArticunoReFightDialogue_1: @ 81028D4
@ replacing .incbin "baserom.gba", 0x1028D4, 0x44
.byte 0x00, 0x00, 0x00, 0x0d, 0x90, 0x00, 0x00, 0x00
.4byte gUnknown_81028E0

.global gUnknown_81028E0
gUnknown_81028E0: @ 81028E0
.string " You may try all you like.\n"
.string "But you shall never pass!\0"
.align 2, 0

.global gArticunoReFightDialogue_2
gArticunoReFightDialogue_2: @ 8102918
@ replacing .incbin "baserom.gba", 0x102918, 0x30
.byte 0x00, 0x00, 0x00, 0x0d, 0x90, 0x00, 0x00, 0x00
.4byte gUnknown_8102924

.global gUnknown_8102924
gUnknown_8102924: @ 8102924
.string " If you so badly hope to\n"
.string "pass...\0"
.align 2, 0

.global gArticunoReFightDialogue_3
gArticunoReFightDialogue_3: @ 8102948
@ replacing .incbin "baserom.gba", 0x102948, 0x3C
.byte 0x00, 0x00, 0x00, 0x0d, 0x90, 0x00, 0x00, 0x00
.4byte gUnknown_8102954

.global gUnknown_8102954
gUnknown_8102954: @ 8102954
.string " Do so only if you can snatch\n"
.string "victory from me!\0"
.align 2, 0

.global gArticunoPostStoryPreFightDialogue_1
gArticunoPostStoryPreFightDialogue_1: @ 8102984
@ replacing .incbin "baserom.gba", 0x102984, 0x30
.byte 0x05, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.4byte gUnknown_8102990

.global gUnknown_8102990
gUnknown_8102990: @ 8102990
.string "Gyaaaaaah!\n"
.string "                     \0"
.align 2, 0

.global gArticunoPostStoryPreFightDialogue_2
gArticunoPostStoryPreFightDialogue_2: @ 81029B4
@ replacing .incbin "baserom.gba", 0x001029b4, 0x64
.4byte 0x0d000000
.4byte 0x00000090
.4byte gUnknown_81029C0

.global gUnknown_81029C0
gUnknown_81029C0: @ 81029C0
.string " Your arrival in this frozen\n"
.string "forest means only one thing...{EXTRA_MSG}"
.string " You mean to challenge me!\0"

.global gArticunoPostStoryPreFightDialogue_3
gArticunoPostStoryPreFightDialogue_3: @ 8102A18
@ replacing .incbin "baserom.gba", 0x102A18, 0xC
.byte 0x00, 0x00, 0x00, 0x0d, 0x90, 0x00, 0x00, 0x00
.4byte gUnknown_810284C

.global gArticunoPostStoryPreFightDialogue_4
gArticunoPostStoryPreFightDialogue_4: @ 8102A24
@ replacing .incbin "baserom.gba", 0x102A24, 0x50
.byte 0x00, 0x00, 0x00, 0x0d, 0x90, 0x00, 0x00, 0x00
.4byte gUnknown_8102A30

.global gUnknown_8102A30
gUnknown_8102A30: @ 8102A30
.string " Those that enter\n"
.string "the forest...\n"
.string "I shall destroy with all my might!\0"
.align 2, 0

.global gArticunoPostStoryPreFightDialogue_5
gArticunoPostStoryPreFightDialogue_5: @ 8102A74
@ replacing .incbin "baserom.gba", 0x102A74, 0x28
.byte 0x00, 0x00, 0x00, 0x0d, 0x90, 0x00, 0x00, 0x00
.4byte gUnknown_8102A80

.global gUnknown_8102A80
gUnknown_8102A80: @ 8102A80
.string " No matter who it may be!\0"
.align 2, 0

.global gUnknown_8102A9C
gUnknown_8102A9C: @ 8102A9C
@ replacing .incbin "baserom.gba", 0x102A9C, 0x74
.byte 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.4byte gUnknown_8102AA8

.global gUnknown_8102AA8
gUnknown_8102AA8: @ 8102AA8
.string "{CENTER_ALIGN}This is the deepest part of the forest...{WAIT_PRESS}\n"
.string "{CENTER_ALIGN}But there is no one here.{EXTRA_MSG}"
.string "{CENTER_ALIGN}It's time to go back.\0"
.align 2, 0

.global gUnknown_8102B10
gUnknown_8102B10: @ 8102B10
@ replacing .incbin "baserom.gba", 0x102B10, 0xC
.byte 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.4byte gUnknown_8101A44

.global MagmaCavernMidDialogue_1
MagmaCavernMidDialogue_1: @ 8102B1C
@ replacing .incbin "baserom.gba", 0x00102b1c, 0x38
.4byte 0x02040000
.4byte 0x000001aa
.4byte gUnknown_8102B28

.global gUnknown_8102B28
gUnknown_8102B28: @ 8102B28
.string " Let's see...{WAIT_PRESS}\n"
.string "...I wonder where we are?\0"

.global MagmaCavernMidDialogue_2
MagmaCavernMidDialogue_2: @ 8102B54
@ replacing .incbin "baserom.gba", 0x102B54, 0x70
.byte 0x00, 0x00, 0x00, 0x02, 0xaa, 0x01, 0x07, 0x00
.4byte gUnknown_8102BA0
.byte 0x00, 0x00, 0x00, 0x02
.byte 0xaa, 0x01, 0x00, 0x00
.4byte gUnknown_8102B6C

.global gUnknown_8102B6C
gUnknown_8102B6C: @ 8102B6C
.string " I'm certain we've come quite\n"
.string "far already...\0"
.align 2, 0

.global gUnknown_8102BA0
gUnknown_8102BA0: @ 8102BA0
.string " I know we've come pretty\n"
.string "far...\0"
.align 2, 0

.global MagmaCavernMidDialogue_3
MagmaCavernMidDialogue_3: @ 8102BC4
@ replacing .incbin "baserom.gba", 0x102BC4, 0x20
.byte 0x00, 0x00, 0x0c, 0x02, 0xaa, 0x01, 0x00, 0x00
.4byte gUnknown_8102BD0

.global gUnknown_8102BD0
gUnknown_8102BD0: @ 8102BD0
.string " Waaah!\n"
.string "Qu-quake!\0"
.align 2, 0

.global MagmaCavernMidDialogue_4
MagmaCavernMidDialogue_4: @ 8102BE4
@ replacing .incbin "baserom.gba", 0x102BE4, 0x4C
.byte 0x00, 0x00, 0x00, 0x02, 0xaa, 0x01, 0x07, 0x00
.4byte gUnknown_8102C14
.byte 0x00, 0x00, 0x00, 0x02
.byte 0xaa, 0x01, 0x00, 0x00
.4byte gUnknown_8102BFC

.global gUnknown_8102BFC
gUnknown_8102BFC: @ 8102BFC
.string " ...Whew!\n"
.string "It's over.\0"
.align 2, 0

.global gUnknown_8102C14
gUnknown_8102C14: @ 8102C14
.string " ...Whew!\n"
.string "It settled down.\0"
.align 2, 0

.global MagmaCavernMidDialogue_5
MagmaCavernMidDialogue_5: @ 8102C30
@ replacing .incbin "baserom.gba", 0x102C30, 0x24
.byte 0x00, 0x00, 0x0c, 0x02, 0xaa, 0x01, 0x00, 0x00
.4byte gUnknown_8102C3C

.global gUnknown_8102C3C
gUnknown_8102C3C: @ 8102C3C
.string " Hey! {ARG_POKEMON_0}!\n"
.string "Over there!\0"
.align 2, 0

.global MagmaCavernMidDialogue_6
MagmaCavernMidDialogue_6: @ 8102C54
@ replacing .incbin "baserom.gba", 0x102C54, 0x44
.byte 0x00, 0x00, 0x0c, 0x02, 0xaa, 0x01, 0x07, 0x00
.4byte gUnknown_8102C80
.byte 0x00, 0x00, 0x0c, 0x02
.byte 0xaa, 0x01, 0x00, 0x00
.4byte gUnknown_8102C6C

.global gUnknown_8102C6C
gUnknown_8102C6C: @ 8102C6C
.string " Hey!\n"
.string "Are you OK?!\0"
.align 2, 0

.global gUnknown_8102C80
gUnknown_8102C80: @ 8102C80
.string " Hey!\n"
.string "Snap out of it!\0"
.align 2, 0

.global MagmaCavernMidDialogue_7
MagmaCavernMidDialogue_7: @ 8102C98
@ replacing .incbin "baserom.gba", 0x00102c98, 0x18
.4byte 0x0e030000
.4byte 0x00000006
.4byte gUnknown_8102CA4

.global gUnknown_8102CA4
gUnknown_8102CA4: @ 8102CA4
.string " Urrrrgh...\0"

.global MagmaCavernMidDialogue_8
MagmaCavernMidDialogue_8: @ 8102CB0
@ replacing .incbin "baserom.gba", 0x102CB0, 0x48
.byte 0x00, 0x00, 0x05, 0x02, 0xaa, 0x01, 0x07, 0x00
.4byte gUnknown_8102CE0
.byte 0x00, 0x00, 0x05, 0x02
.byte 0xaa, 0x01, 0x00, 0x00
.4byte gUnknown_8102CC8

.global gUnknown_8102CC8
gUnknown_8102CC8: @ 8102CC8
.string " What happened to you?\0"
.align 2, 0

.global gUnknown_8102CE0
gUnknown_8102CE0: @ 8102CE0
.string " What happened here?\0"
.align 2, 0

.global MagmaCavernMidDialogue_9
MagmaCavernMidDialogue_9: @ 8102CF8
@ replacing .incbin "baserom.gba", 0x102CF8, 0x3C
.byte 0x00, 0x00, 0x03, 0x0e, 0x06, 0x00, 0x00, 0x00
.4byte gUnknown_8102D04

.global gUnknown_8102D04
gUnknown_8102D04: @ 8102D04
.string " We challenged...\n"
.string "{ARG_POKEMON_2}...{WAIT_PRESS}\n"
.string "And wiped out...\n\0"
.align 2, 0

.global MagmaCavernMidDialogue_10
MagmaCavernMidDialogue_10: @ 8102D34
@ replacing .incbin "baserom.gba", 0x102D34, 0x18
.byte 0x00, 0x00, 0x0c, 0x02, 0xaa, 0x01, 0x00, 0x00
.4byte gUnknown_8102D40

.global gUnknown_8102D40
gUnknown_8102D40: @ 8102D40
.string " G-{ARG_POKEMON_2}?!\0"
.align 2, 0

.global MagmaCavernMidDialogue_11
MagmaCavernMidDialogue_11: @ 8102D4C
@ replacing .incbin "baserom.gba", 0x102D4C, 0x30
.byte 0x00, 0x00, 0x00, 0x0f, 0x11, 0x01, 0x00, 0x00
.4byte gUnknown_8102D58

.global gUnknown_8102D58
gUnknown_8102D58: @ 8102D58
.string " Grrgh...{WAIT_PRESS}\n"
.string "We... It crushed us...\0"
.align 2, 0

.global MagmaCavernMidDialogue_12
MagmaCavernMidDialogue_12: @ 8102D7C
@ replacing .incbin "baserom.gba", 0x102D7C, 0x80
.byte 0x00, 0x00, 0x0c, 0x02, 0xaa, 0x01, 0x07, 0x00
.4byte gUnknown_8102DCC
.byte 0x00, 0x00, 0x0c, 0x02
.byte 0xaa, 0x01, 0x00, 0x00
.4byte gUnknown_8102D94

.global gUnknown_8102D94
gUnknown_8102D94: @ 8102D94
.string " That's right.{WAIT_PRESS}\n"
.string "What happened to {ARG_POKEMON_3}?\n"
.string "Where is {ARG_POKEMON_3}?\0"
.align 2, 0

.global gUnknown_8102DCC
gUnknown_8102DCC: @ 8102DCC
.string " Wait...{WAIT_PRESS}\n"
.string "What about {ARG_POKEMON_3}?\n"
.string "Where did {ARG_POKEMON_3} go?\0"
.align 2, 0

.global MagmaCavernMidDialogue_13
MagmaCavernMidDialogue_13: @ 8102DFC
@ replacing .incbin "baserom.gba", 0x102DFC, 0x30
.byte 0x00, 0x00, 0x00, 0x0f, 0x11, 0x01, 0x00, 0x00
.4byte gUnknown_8102E08

.global gUnknown_8102E08
gUnknown_8102E08: @ 8102E08
.string " {ARG_POKEMON_3} is...{WAIT_PRESS}\n"
.string "Still battling {ARG_POKEMON_2}...\0"
.align 2, 0

.global MagmaCavernMidDialogue_14
MagmaCavernMidDialogue_14: @ 8102E2C
@ replacing .incbin "baserom.gba", 0x00102e2c, 0x28
.4byte 0x020c0000
.4byte 0x000001aa
.4byte gUnknown_8102E38

.global gUnknown_8102E38
gUnknown_8102E38: @ 8102E38
.string " {ARG_POKEMON_0}!\n"
.string "We've got to hurry!\0"

.global MagmaCavernMidDialogue_15
MagmaCavernMidDialogue_15: @ 8102E54
@ replacing .incbin "baserom.gba", 0x00102e54, 0x1c
.4byte 0x0e030000
.4byte 0x00000006
.4byte gUnknown_8102E60

.global gUnknown_8102E60
gUnknown_8102E60: @ 8102E60
.string " ...Be careful!\0"

.global GroudonPreFightDialogue_1
GroudonPreFightDialogue_1: @ 8102E70
@ replacing .incbin "baserom.gba", 0x102E70, 0x4C
.byte 0x00, 0x00, 0x0c, 0x02, 0xaa, 0x01, 0x07, 0x00
.4byte gUnknown_8102EA4
.byte 0x00, 0x00, 0x0c, 0x02
.byte 0xaa, 0x01, 0x00, 0x00
.4byte gUnknown_8102E88

.global gUnknown_8102E88
gUnknown_8102E88: @ 8102E88
.string " It's {ARG_POKEMON_3}!\n"
.string "Are you OK?!\0"
.align 2, 0

.global gUnknown_8102EA4
gUnknown_8102EA4: @ 8102EA4
.string " Oh! {ARG_POKEMON_3}!\n"
.string "Are you OK?!\0"
.align 2, 0

.global GroudonPreFightDialogue_2
GroudonPreFightDialogue_2: @ 8102EBC
@ replacing .incbin "baserom.gba", 0x102EBC, 0x24
.byte 0x00, 0x00, 0x00, 0x0f, 0x41, 0x00, 0x00, 0x00
.4byte gUnknown_8102EC8

.global gUnknown_8102EC8
gUnknown_8102EC8: @ 8102EC8
.string " Hm!{WAIT_PRESS}\n"
.string "So it's you!\0"
.align 2, 0

.global GroudonPreFightDialogue_3
GroudonPreFightDialogue_3: @ 8102EE0
@ replacing .incbin "baserom.gba", 0x00102ee0, 0x18
.4byte 0x0f000000
.4byte 0x00000041
.4byte gUnknown_8102EEC

.global gUnknown_8102EEC
gUnknown_8102EEC: @ 8102EEC
.string " Stay back!\0"

.global GroudonPreFightDialogue_4
GroudonPreFightDialogue_4: @ 8102EF8
@ replacing .incbin "baserom.gba", 0x102EF8, 0x38
.byte 0x00, 0x00, 0x00, 0x0f, 0x41, 0x00, 0x00, 0x00
.4byte gUnknown_8102F04

.global gUnknown_8102F04
gUnknown_8102F04: @ 8102F04
.string " This opponent...{WAIT_PRESS}\n"
.string "is no laughing matter!\0"
.align 2, 0

.global GroudonPreFightDialogue_5
GroudonPreFightDialogue_5: @ 8102F30
@ replacing .incbin "baserom.gba", 0x102F30, 0x34
.byte 0x05, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.4byte gUnknown_8102F3C

.global gUnknown_8102F3C
gUnknown_8102F3C: @ 8102F3C
.string "Grgaaaaaaaaah!\n"
.string "                     \0"
.align 2, 0

.global GroudonPreFightDialogue_6
GroudonPreFightDialogue_6: @ 8102F64
@ replacing .incbin "baserom.gba", 0x102F64, 0x20
.byte 0x00, 0x00, 0x00, 0x0f, 0x41, 0x00, 0x00, 0x00
.4byte gUnknown_8102F70

.global gUnknown_8102F70
gUnknown_8102F70: @ 8102F70
.string " H-here it comes!\0"
.align 2, 0

.global GroudonPreFightDialogue_7
GroudonPreFightDialogue_7: @ 8102F84
@ replacing .incbin "baserom.gba", 0x102F84, 0x28
.byte 0x00, 0x00, 0x0c, 0x02, 0xaa, 0x01, 0x00, 0x00
.4byte gUnknown_8102F90

.global gUnknown_8102F90
gUnknown_8102F90: @ 8102F90
.string " Coming...?{WAIT_PRESS}\n"
.string "Wh-where?!\0"
.align 2, 0

.global GroudonPreFightDialogue_8
GroudonPreFightDialogue_8: @ 8102FAC
@ replacing .incbin "baserom.gba", 0x00102fac, 0x18
.4byte 0x0f010000
.4byte 0x00000041
.4byte gUnknown_8102FB8

.global gUnknown_8102FB8
gUnknown_8102FB8: @ 8102FB8
.string " Wraaaaaah!\0"

.global GroudonPreFightDialogue_9
GroudonPreFightDialogue_9: @ 8102FC4
@ replacing .incbin "baserom.gba", 0x00102fc4, 0x14
.4byte 0x020c0000
.4byte 0x000001aa
.4byte gUnknown_8102FD0

.global gUnknown_8102FD0
gUnknown_8102FD0: @ 8102FD0
@ The "A-" only makes sense when ARG_POKEMON_3 is "Alakazam" (which it is when this is used). Kinda funny.
.string " A-{ARG_POKEMON_3}!\0"

.global GroudonPreFightDialogue_10
GroudonPreFightDialogue_10: @ 8102FD8
@ replacing .incbin "baserom.gba", 0x102FD8, 0x7C
.byte 0x00, 0x00, 0x0c, 0x02, 0xaa, 0x01, 0x07, 0x00
.4byte gUnknown_8103020
.byte 0x00, 0x00, 0x0c, 0x02
.byte 0xaa, 0x01, 0x00, 0x00
.4byte gUnknown_8102FF0

.global gUnknown_8102FF0
gUnknown_8102FF0: @ 8102FF0
.string " {ARG_POKEMON_3} is gone!{EXTRA_MSG}"
.string " Maybe...{WAIT_PRESS}\n"
.string "Was he defeated?!\0"
.align 2, 0

.global gUnknown_8103020
gUnknown_8103020: @ 8103020
.string " {ARG_POKEMON_3}'s gone!{EXTRA_MSG}"
.string " Was he maybe...{WAIT_PRESS}\n"
.string "knocked out?!\0"
.align 2, 0

.global GroudonPreFightDialogue_11
GroudonPreFightDialogue_11: @ 8103054
@ replacing .incbin "baserom.gba", 0x00103054, 0x84
.byte 0x00, 0x00, 0x02, 0x02, 0xaa, 0x01, 0x07, 0x00
.4byte gUnknown_81030B8
.byte 0x00, 0x00, 0x02, 0x02
.byte 0xaa, 0x01, 0x01, 0x00
.4byte gUnknown_8103098
.byte 0x00, 0x00, 0x02, 0x02, 0xaa, 0x01, 0x00, 0x00
.4byte gUnknown_8103078

.global gUnknown_8103078
gUnknown_8103078: @ 8103078
.string " Ohh...\n"
.string "It's our turn next.\0"
.align 2, 0

.global gUnknown_8103098
gUnknown_8103098: @ 8103098
.string " Urgh...\n"
.string "It's our turn next.\0"
.align 2, 0

.global gUnknown_81030B8
gUnknown_81030B8: @ 81030B8
.string " Darn it!\n"
.string "It's our turn next.\0"
.align 2, 0

.global GroudonPreFightDialogue_12
GroudonPreFightDialogue_12: @ 81030D8
@ replacing .incbin "baserom.gba", 0x1030D8, 0x38
.byte 0x00, 0x00, 0x02, 0x02, 0xaa, 0x01, 0x00, 0x00
.4byte gUnknown_81030E4

.global gUnknown_81030E4
gUnknown_81030E4: @ 81030E4
.string " But I'm not going down\n"
.string "without a fight!\0"
.align 2, 0

.global GroudonPreFightDialogue_13
GroudonPreFightDialogue_13: @ 8103110
@ replacing .incbin "baserom.gba", 0x103110, 0x30
.byte 0x05, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.4byte gUnknown_810311C

.global gUnknown_810311C
gUnknown_810311C: @ 810311C
.string "Grgaaaaaaah!\n"
.string "                     \0"
.align 2, 0

.global GroudonPreFightDialogue_14
GroudonPreFightDialogue_14: @ 8103140
@ replacing .incbin "baserom.gba", 0x103140, 0x48
.byte 0x00, 0x00, 0x03, 0x02, 0xaa, 0x01, 0x07, 0x00
.4byte gUnknown_8103174
.byte 0x00, 0x00, 0x03, 0x02
.byte 0xaa, 0x01, 0x00, 0x00
.4byte gUnknown_8103158

.global gUnknown_8103158
gUnknown_8103158: @ 8103158
.string " {ARG_POKEMON_0}!\n"
.string "Let's do our best!\0"
.align 2, 0

.global gUnknown_8103174
gUnknown_8103174: @ 8103174
.string " {ARG_POKEMON_0}!\n"
.string "Hang tough!\0"
.align 2, 0

.global gGroudonReFightDialogue_1
gGroudonReFightDialogue_1: @ 8103188
@ replacing .incbin "baserom.gba", 0x103188, 0xA0
.byte 0x00, 0x00, 0x02, 0x02, 0xaa, 0x01, 0x07, 0x00
.4byte gUnknown_81031E4
.byte 0x00, 0x00, 0x02, 0x02
.byte 0xaa, 0x01, 0x00, 0x00
.4byte gUnknown_81031A0

.global gUnknown_81031A0
gUnknown_81031A0: @ 81031A0
.string " Here it comes!\n"
.string "{ARG_POKEMON_0}!{EXTRA_MSG}"
.string " Let's make sure we subdue\n"
.string "{ARG_POKEMON_2} this time!\0"
.align 2, 0

.global gUnknown_81031E4
gUnknown_81031E4: @ 81031E4
.string " Here it comes!\n"
.string "{ARG_POKEMON_0}!{EXTRA_MSG}"
.string " We've got to settle\n"
.string "{ARG_POKEMON_2} down this time!\0"
.align 2, 0

.global gGroudonReFightDialogue_2
gGroudonReFightDialogue_2: @ 8103228
@ replacing .incbin "baserom.gba", 0x00103228, 0xe8
.byte 0x00, 0x00, 0x03, 0x02, 0xaa, 0x01, 0x07, 0x00
.4byte gUnknown_81032D8
.byte 0x00, 0x00, 0x03, 0x02
.byte 0xaa, 0x01, 0x01, 0x00
.4byte gUnknown_8103294
.byte 0x00, 0x00, 0x03, 0x02, 0xaa, 0x01, 0x00, 0x00
.4byte gUnknown_810324C

.global gUnknown_810324C
gUnknown_810324C: @ 810324C
.string " Don't be intimidated!{EXTRA_MSG}"
.string " We have to fight it with\n"
.string "all our courage!\0"
.align 2, 0

.global gUnknown_8103294
gUnknown_8103294: @ 8103294
.string " Don't be intimidated!{EXTRA_MSG}"
.string " We need to be brave to\n"
.string "face this thing!\0"
.align 2, 0

.global gUnknown_81032D8
gUnknown_81032D8: @ 81032D8
.string " Don't get psyched out!{EXTRA_MSG}"
.string " Be brave and keep slugging!\0"
.align 2, 0

.global gGroudonReFightDialogue_3
gGroudonReFightDialogue_3: @ 8103310
@ replacing .incbin "baserom.gba", 0x00103310, 0x30
.4byte 0x00000005
.4byte 0x00000000
.4byte gUnknown_810331C

.global gUnknown_810331C
gUnknown_810331C: @ 810331C
.string "Grgaaaaaaaah!\n"
.string "                     \0"

.global gGroudonReFightDialogue_4
gGroudonReFightDialogue_4: @ 8103340
@ replacing .incbin "baserom.gba", 0x00103340, 0x60
.byte 0x00, 0x00, 0x03, 0x02, 0xaa, 0x01, 0x07, 0x00
.4byte gUnknown_8103378
.byte 0x00, 0x00, 0x03, 0x02
.byte 0xaa, 0x01, 0x00, 0x00
.4byte gUnknown_8103358

.global gUnknown_8103358
gUnknown_8103358: @ 8103358
.string " {ARG_POKEMON_0}!\n"
.string "Let's give it our all!\0"
.align 2, 0

.global gUnknown_8103378
gUnknown_8103378: @ 8103378
.string " {ARG_POKEMON_0}!\n"
.string "Let's give it what we've got!\0"
.align 2, 0

.global gGroudonPostStoryPreFightDialogue_1
gGroudonPostStoryPreFightDialogue_1: @ 81033A0
@ replacing .incbin "baserom.gba", 0x1033A0, 0xC
.byte 0x05, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.4byte gUnknown_810311C

.global gGroudonPostStoryPreFightDialogue_2
gGroudonPostStoryPreFightDialogue_2: @ 81033AC
@ replacing .incbin "baserom.gba", 0x1033AC, 0x90
.byte 0x00, 0x00, 0x00, 0x0d, 0x9b, 0x01, 0x00, 0x00
.4byte gUnknown_81033B8

.global gUnknown_81033B8
gUnknown_81033B8: @ 81033B8
.string " Why have you returned?!{WAIT_PRESS}\n"
.string "How dare you disturb me in my sleep?!{EXTRA_MSG}"
.string " I let rage run wild before...{WAIT_PRESS}\n"
.string "But I won't allow that again!\0"
.align 2, 0

.global gGroudonPostStoryPreFightDialogue_3
gGroudonPostStoryPreFightDialogue_3: @ 810343C
@ replacing .incbin "baserom.gba", 0x0010343c, 0x40
.4byte 0x0d000000
.4byte 0x0000019b
.4byte gUnknown_8103448

.global gUnknown_8103448
gUnknown_8103448: @ 8103448
.string " Those that disturb my\n"
.string "sleep...{WAIT_PRESS}\n"
.string "Shall be crushed!\0"

.global gGroudonPostStoryPreFightDialogue_4
gGroudonPostStoryPreFightDialogue_4: @ 810347C
@ replacing .incbin "baserom.gba", 0x10347C, 0xC
.byte 0x00, 0x00, 0x00, 0x0d, 0x9b, 0x01, 0x00, 0x00
.4byte gUnknown_8102A80

.global gUnknown_8103488
gUnknown_8103488: @ 8103488
@ replacing .incbin "baserom.gba", 0x00103488, 0x78
.4byte 0x00000004
.4byte 0x00000000
.4byte gUnknown_8103494

.global gUnknown_8103494
gUnknown_8103494: @ 8103494
.string "{CENTER_ALIGN}This appears to be the deepest level.{EXTRA_MSG}"
.string "{CENTER_ALIGN}It's impossible to go any farther.{WAIT_PRESS}\n"
.string "{CENTER_ALIGN}It's time to go back.\0"

.global gRayquazaPreFightDialogue_1
gRayquazaPreFightDialogue_1: @ 8103500
@ replacing .incbin "baserom.gba", 0x103500, 0x2C
.byte 0x00, 0x00, 0x00, 0x02, 0xaa, 0x01, 0x00, 0x00
.4byte gUnknown_810350C

.global gUnknown_810350C
gUnknown_810350C: @ 810350C
.string " Is this...{WAIT_PRESS}\n"
.string "The top floor?\0"
.align 2, 0

.global gRayquazaPreFightDialogue_2
gRayquazaPreFightDialogue_2: @ 810352C
@ replacing .incbin "baserom.gba", 0x10352C, 0x4C
.byte 0x00, 0x00, 0x00, 0x00, 0xab, 0x01, 0x00, 0x00
.4byte gUnknown_8103538

.global gUnknown_8103538
gUnknown_8103538: @ 8103538
.string " Who goes there?!{WAIT_PRESS}\n"
.string "Who dares to trespass upon my\n"
.string "airspace?!\0"
.align 2, 0

.global gRayquazaPreFightDialogue_3
gRayquazaPreFightDialogue_3: @ 8103578
@ replacing .incbin "baserom.gba", 0x103578, 0x5C
.byte 0x00, 0x00, 0x00, 0x02, 0xaa, 0x01, 0x07, 0x00
.4byte gUnknown_81035B4
.byte 0x00, 0x00, 0x00, 0x02
.byte 0xaa, 0x01, 0x00, 0x00
.4byte gUnknown_8103590

.global gUnknown_8103590
gUnknown_8103590: @ 8103590
.string " That voice...{WAIT_PRESS}\n"
.string "Could it be {ARG_POKEMON_2}?\0"
.align 2, 0

.global gUnknown_81035B4
gUnknown_81035B4: @ 81035B4
.string " That voice...{WAIT_PRESS}\n"
.string "Is that {ARG_POKEMON_2}?\0"
.align 2, 0

.global gRayquazaPreFightDialogue_4
gRayquazaPreFightDialogue_4: @ 81035D4
@ replacing .incbin "baserom.gba", 0x001035d4, 0x44
.4byte 0x0d800000
.4byte 0x0000019c
.4byte gUnknown_81035E0

.global gUnknown_81035E0
gUnknown_81035E0: @ 81035E0
.string " Indeed I am.{WAIT_PRESS}\n"
.string "The sky is my domain.{EXTRA_MSG}"
.string " Depart at once!\0"
.align 2,0

.global gRayquazaPreFightDialogue_5
gRayquazaPreFightDialogue_5: @ 8103618
@ replacing .incbin "baserom.gba", 0x103618, 0x64
.byte 0x00, 0x00, 0x04, 0x02, 0xaa, 0x01, 0x00, 0x00
.4byte gUnknown_8103624

.global gUnknown_8103624
gUnknown_8103624: @ 8103624
.string " But...\n"
.string "We don't have the time to argue.{EXTRA_MSG}"
.string " We came here because we\n"
.string "need your help...\0"
.align 2, 0

.global gRayquazaPreFightDialogue_6
gRayquazaPreFightDialogue_6: @ 810367C
@ replacing .incbin "baserom.gba", 0x0010367c, 0x14
.4byte 0x0d800000
.4byte 0x0000019c
.4byte gUnknown_8103688

.global gUnknown_8103688
gUnknown_8103688: @ 8103688
.string " Never!\0"
.align 2,0

.global gRayquazaPreFightDialogue_7
gRayquazaPreFightDialogue_7: @ 8103690
@ replacing .incbin "baserom.gba", 0x103690, 0x38
.byte 0x05, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.4byte gUnknown_810369C

.global gUnknown_810369C
gUnknown_810369C: @ 810369C
.string "Gyaaaaaaaaaaaaaaah!\n"
.string "                     \0"
.align 2, 0

.global gRayquazaPreFightDialogue_8
gRayquazaPreFightDialogue_8: @ 81036C8
@ replacing .incbin "baserom.gba", 0x1036C8, 0xD8
.byte 0x00, 0x00, 0x00, 0x0d, 0x9c, 0x01, 0x00, 0x00
.4byte gUnknown_81036D4

.global gUnknown_81036D4
gUnknown_81036D4: @ 81036D4
.string " I am a being of the sky,\n"
.string "and you are but denizens of the ground.{EXTRA_MSG}"
.string " To each, there is a world\n"
.string "destined as their own!{EXTRA_MSG}"
.string " For hundreds of millions of\n"
.string "years, never once have I descended to\n"
.string "the ground!\0"
.align 2, 0

.global gRayquazaPreFightDialogue_9
gRayquazaPreFightDialogue_9: @ 81037A0
@ replacing .incbin "baserom.gba", 0x001037a0, 0x34
.4byte 0x0d000000
.4byte 0x0000019c
.4byte gUnknown_81037AC

.global gUnknown_81037AC
gUnknown_81037AC: @ 81037AC
.string " And the opposite shall also\n"
.string "hold true!\0"
.align 2,0

.global gRayquazaPreFightDialogue_10
gRayquazaPreFightDialogue_10: @ 81037D4
@ replacing .incbin "baserom.gba", 0x1037D4, 0x4C
.byte 0x00, 0x00, 0x00, 0x0d, 0x9c, 0x01, 0x00, 0x00
.4byte gUnknown_81037E0

.global gUnknown_81037E0
gUnknown_81037E0: @ 81037E0
.string " Let there be no mercy for\n"
.string "those that defy the laws of nature!\0"
.align 2, 0

.global gRayquazaPreFightDialogue_11
gRayquazaPreFightDialogue_11: @ 8103820
@ replacing .incbin "baserom.gba", 0x103820, 0x24
.byte 0x00, 0x00, 0x00, 0x0d, 0x9c, 0x01, 0x00, 0x00
.4byte gUnknown_810382C

.global gUnknown_810382C
gUnknown_810382C: @ 810382C
.string " Prepare for the end!\0"
.align 2, 0

.global gRayquazaReFightDialogue_1
gRayquazaReFightDialogue_1: @ 8103844
@ replacing .incbin "baserom.gba", 0x103844, 0x30
.byte 0x00, 0x00, 0x00, 0x0d, 0x9c, 0x01, 0x00, 0x00
.4byte gUnknown_8103850

.global gUnknown_8103850
gUnknown_8103850: @ 8103850
.string " You return, but for no\n"
.string "purpose!\0"
.align 2, 0

.global gRayquazaReFightDialogue_2
gRayquazaReFightDialogue_2: @ 8103874
@ replacing .incbin "baserom.gba", 0x00103874, 0x34
.4byte 0x0d000000
.4byte 0x0000019c
.4byte gUnknown_8103880

.global gUnknown_8103880
gUnknown_8103880: @ 8103880
.string " This is no place for the\n"
.string "likes of you!\0"
.align 2,0

.global gRayquazaReFightDialogue_3
gRayquazaReFightDialogue_3: @ 81038A8
@ replacing .incbin "baserom.gba", 0x1038A8, 0x50
.byte 0x00, 0x00, 0x00, 0x0d, 0x9c, 0x01, 0x00, 0x00
.4byte gUnknown_81038B4

.global gUnknown_81038B4
gUnknown_81038B4: @ 81038B4
.string " Let there be no mercy for\n"
.string "those that trespass upon my airspace!\0"
.align 2, 0

.global gRayquazaReFightDialogue_4
gRayquazaReFightDialogue_4: @ 81038F8
@ replacing .incbin "baserom.gba", 0x1038F8, 0xC
.byte 0x00, 0x00, 0x00, 0x0d, 0x9c, 0x01, 0x00, 0x00
.4byte gUnknown_810382C

.global gRayquazaPostStoryPreFightDialogue_1
gRayquazaPostStoryPreFightDialogue_1: @ 8103904
@ replacing .incbin "baserom.gba", 0x103904, 0x34
.byte 0x05, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.4byte gUnknown_8103910

.global gUnknown_8103910
gUnknown_8103910: @ 8103910
.string "Gyaaaaaaaaaaaah!\n"
.string "                     \0"
.align 2, 0

.global gRayquazaPostStoryPreFightDialogue_2
gRayquazaPostStoryPreFightDialogue_2: @ 8103938
@ replacing .incbin "baserom.gba", 0x103938, 0x16C
.byte 0x00, 0x00, 0x00, 0x0d, 0x9c, 0x01, 0x00, 0x00
.4byte gUnknown_8103944

.global gUnknown_8103944
gUnknown_8103944: @ 8103944
.string " So it is you who dares to\n"
.string "trespass upon my airspace!{EXTRA_MSG}"
.string " You scaled the Sky Tower...{EXTRA_MSG}"
.string " Now, you wish to challenge\n"
.string "me to a battle?!{EXTRA_MSG}"
.string " ............{WAIT_PRESS}\n"
.string "In destroying the falling star, I sustained\n"
.string "injuries upon my body and my pride...{EXTRA_MSG}"
.string " To better protect my\n"
.string "domain, I have made myself stronger.{EXTRA_MSG}"
.string " And so that I may draw\n"
.string "out my newly gained power...\0"
.align 2, 0

.global gRayquazaPostStoryPreFightDialogue_3
gRayquazaPostStoryPreFightDialogue_3: @ 8103AA4
@ replacing .incbin "baserom.gba", 0x103AA4, 0x40
.byte 0x00, 0x00, 0x00, 0x0d, 0x9c, 0x01, 0x00, 0x00
.4byte gUnknown_8103AB0

.global gUnknown_8103AB0
gUnknown_8103AB0: @ 8103AB0
.string " I am now...{WAIT_PRESS}\n"
.string "Unleashing every bit of my might!\0"
.align 2, 0

.global gRayquazaPostStoryPreFightDialogue_4
gRayquazaPostStoryPreFightDialogue_4: @ 8103AE4
@ replacing .incbin "baserom.gba", 0x103AE4, 0x4C
.byte 0x00, 0x00, 0x00, 0x0d, 0x9c, 0x01, 0x00, 0x00
.4byte gUnknown_8103AF0

.global gUnknown_8103AF0
gUnknown_8103AF0: @ 8103AF0
.string " My power shall overwhelm...{WAIT_PRESS}\n"
.string "But you dare to stand up to it?\0"
.align 2, 0

.global gRayquazaPostStoryPreFightDialogue_5
gRayquazaPostStoryPreFightDialogue_5: @ 8103B30
@ replacing .incbin "baserom.gba", 0x103B30, 0x28
.byte 0x00, 0x00, 0x00, 0x0d, 0x9c, 0x01, 0x00, 0x00
.4byte gUnknown_8103B3C

.global gUnknown_8103B3C
gUnknown_8103B3C: @ 8103B3C
.string " I commend your courage!\0"
.align 2, 0

.global gRayquazaPostStoryPreFightDialogue_6
gRayquazaPostStoryPreFightDialogue_6: @ 8103B58
@ replacing .incbin "baserom.gba", 0x103B58, 0x80
.byte 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.4byte gUnknown_8103B64

.global gUnknown_8103B64
gUnknown_8103B64: @ 8103B64
.string "{CENTER_ALIGN}This appears to be\n"
.string "{CENTER_ALIGN}the top of the Sky Tower...{EXTRA_MSG}"
.string "{CENTER_ALIGN}It's impossible to go farther.{WAIT_PRESS}\n"
.string "{CENTER_ALIGN}It's time to go back.\0"
.align 2, 0

.global gUnknown_8103BD8
gUnknown_8103BD8: @ 8103BD8
@ replacing .incbin "baserom.gba", 0x103BD8, 0x28
.byte 0x01, 0x00, 0x00, 0x0d, 0x38, 0x00, 0x00, 0x00
.4byte gUnknown_8103BE4

.global gUnknown_8103BE4
gUnknown_8103BE4: @ 8103BE4
.string " Hunh? What is it, you?\0"
.align 2, 0

.global gUnknown_8103C00
gUnknown_8103C00: @ 8103C00
@ replacing .incbin "baserom.gba", 0x103C00, 0x3C
.byte 0x01, 0x00, 0x00, 0x0c, 0x38, 0x00, 0x00, 0x00
.4byte gUnknown_8103C0C

.global gUnknown_8103C0C
gUnknown_8103C0C: @ 8103C0C
.string " We don't like to brag or\n"
.string "nothing, but...\0"
.align 2, 0

.global gUnknown_8103C3C
gUnknown_8103C3C: @ 8103C3C
@ replacing .incbin "baserom.gba", 0x103C3C, 0x38
.byte 0x01, 0x00, 0x00, 0x0d, 0x38, 0x00, 0x00, 0x00
.4byte gUnknown_8103C48

.global gUnknown_8103C48
gUnknown_8103C48: @ 8103C48
.string " We get furious real easy.\n"
.string "You know that?!\0"
.align 2, 0

.global gUnknown_8103C74
gUnknown_8103C74: @ 8103C74
@ replacing .incbin "baserom.gba", 0x103C74, 0x50
.byte 0x01, 0x00, 0x00, 0x0c, 0x38, 0x00, 0x00, 0x00
.4byte gUnknown_8103C80

.global gUnknown_8103C80
gUnknown_8103C80: @ 8103C80
.string " What really irritates us is\n"
.string "when we see some dim-witted face...\0"
.align 2, 0

.global gUnknown_8103CC4
gUnknown_8103CC4: @ 8103CC4
@ replacing .incbin "baserom.gba", 0x103CC4, 0x48
.byte 0x01, 0x00, 0x00, 0x0d, 0x38, 0x00, 0x00, 0x00
.4byte gUnknown_8103CD0

.global gUnknown_8103CD0
gUnknown_8103CD0: @ 8103CD0
.string " ............{WAIT_PRESS}\n"
.string "Wroooooooar!{WAIT_PRESS}\n"
.string "That vacant expression...\0"
.align 2, 0

.global gUnknown_8103D0C
gUnknown_8103D0C: @ 8103D0C
@ replacing .incbin "baserom.gba", 0x103D0C, 0x44
.byte 0x01, 0x00, 0x00, 0x0c, 0x38, 0x00, 0x00, 0x00
.4byte gUnknown_8103D18

.global gUnknown_8103D18
gUnknown_8103D18: @ 8103D18
.string " Gwooooh!\n"
.string "It's ticking me off!{WAIT_PRESS}\n"
.string "I'm seeing red!\0"
.align 2, 0

.global gUnknown_8103D50
gUnknown_8103D50: @ 8103D50
@ replacing .incbin "baserom.gba", 0x103D50, 0x3C
.byte 0x00, 0x00, 0x00, 0x0d, 0x38, 0x00, 0x00, 0x00
.4byte gUnknown_8103D5C

.global gUnknown_8103D5C
gUnknown_8103D5C: @ 8103D5C
.string " Mukkkeeeeeh!\n"
.string "Get 'em! It's frenzy time!\0"
.align 2, 0

.global gUnknown_8103D8C
gUnknown_8103D8C: @ 8103D8C
@ replacing .incbin "baserom.gba", 0x103D8C, 0xC
.byte 0x01, 0x00, 0x00, 0x0d, 0x38, 0x00, 0x00, 0x00
.4byte gUnknown_8103BE4

.global gUnknown_8103D98
gUnknown_8103D98: @ 8103D98
@ replacing .incbin "baserom.gba", 0x103D98, 0x40
.byte 0x01, 0x00, 0x00, 0x0c, 0x38, 0x00, 0x00, 0x00
.4byte gUnknown_8103DA4

.global gUnknown_8103DA4
gUnknown_8103DA4: @ 8103DA4
.string " Are you looking at me...?{WAIT_PRESS}\n"
.string "Are you mocking me?\0"
.align 2, 0

.global gUnknown_8103DD8
gUnknown_8103DD8: @ 8103DD8
@ replacing .incbin "baserom.gba", 0x103DD8, 0x50
.byte 0x01, 0x00, 0x00, 0x0d, 0x38, 0x00, 0x00, 0x00
.4byte gUnknown_8103DE4

.global gUnknown_8103DE4
gUnknown_8103DE4: @ 8103DE4
.string " Gwoooooh!\n"
.string "It's ticking me off!{WAIT_PRESS}\n"
.string "I'm about to blow my fuse!\0"
.align 2, 0

.global gUnknown_8103E28
gUnknown_8103E28: @ 8103E28
@ replacing .incbin "baserom.gba", 0x103E28, 0xC
.byte 0x00, 0x00, 0x00, 0x0c, 0x38, 0x00, 0x00, 0x00
.4byte gUnknown_8103D5C

.global gUnknown_8103E34
gUnknown_8103E34: @ 8103E34
.byte 0x04, 0x00, 0x00, 0x00
.byte 0x00, 0x00, 0x00, 0x00
.4byte gUnknown_8103E40

.global gUnknown_8103E40
gUnknown_8103E40: @ 8103E40

.global gUnknown_8103E40
gUnknown_8103E40: @ 8103E40
.string "{CENTER_ALIGN}There appears to be no one here.{EXTRA_MSG}"
.string "{CENTER_ALIGN}It's impossible to go farther.{WAIT_PRESS}\n"
.string "{CENTER_ALIGN}It's time to go back.\0"
.align 2, 0

.global gMewtwoPreFightDialogue_1
gMewtwoPreFightDialogue_1: @ 8103EA4
@ replacing .incbin "baserom.gba", 0x103EA4, 0x68
.byte 0x00, 0x00, 0x00, 0x00, 0xab, 0x01, 0x00, 0x00
.4byte gUnknown_8103EB0

.global gUnknown_8103EB0
gUnknown_8103EB0: @ 8103EB0
.string " ............{WAIT_PRESS}\n"
.string "Was it you...?{EXTRA_MSG}"
.string " ...Who...disturbed...me...in my...\n"
.string "sleep...?{WAIT_PRESS}\n"
.string "Was it you?\0"
.align 2, 0

.global gMewtwoPreFightDialogue_2
gMewtwoPreFightDialogue_2: @ 8103F0C
@ replacing .incbin "baserom.gba", 0x103F0C, 0x40
.byte 0x03, 0x00, 0x00, 0x0d, 0x96, 0x00, 0x00, 0x00
.4byte gUnknown_8103F18

.global gUnknown_8103F18
gUnknown_8103F18: @ 8103F18
.string " My name is {ARG_POKEMON_2}.{WAIT_PRESS}\n"
.string "I came into being only to fight.\0"
.align 2, 0

.global gMewtwoPreFightDialogue_3
gMewtwoPreFightDialogue_3: @ 8103F4C
@ replacing .incbin "baserom.gba", 0x103F4C, 0x80
.byte 0x00, 0x00, 0x00, 0x0d, 0x96, 0x00, 0x00, 0x00
.4byte gUnknown_8103F58

.global gUnknown_8103F58
gUnknown_8103F58: @ 8103F58
.string " I...{WAIT_PRESS}\n"
.string "have secluded myself here in suspended\n"
.string "animation.{EXTRA_MSG}"
.string " Would you like to know\n"
.string "why?{WAIT_PRESS}\n"
.string "It's quite simple...\0"
.align 2, 0

.global gMewtwoPreFightDialogue_4
gMewtwoPreFightDialogue_4: @ 8103FCC
@ replacing .incbin "baserom.gba", 0x103FCC, 0x3C
.byte 0x00, 0x00, 0x00, 0x0d, 0x96, 0x00, 0x00, 0x00
.4byte gUnknown_8103FD8

.global gUnknown_8103FD8
gUnknown_8103FD8: @ 8103FD8
.string " If anyone--such as you--\n"
.string "were to come along...\0"
.align 2, 0

.global gMewtwoPreFightDialogue_5
gMewtwoPreFightDialogue_5: @ 8104008
@ replacing .incbin "baserom.gba", 0x104008, 0x3C
.byte 0x00, 0x00, 0x00, 0x0d, 0x96, 0x00, 0x00, 0x00
.4byte gUnknown_8104014

.global gUnknown_8104014
gUnknown_8104014: @ 8104014
.string " I could defeat them at full\n"
.string "power!\n"
.string "Come on!\0"
.align 2, 0

.global gMewtwoReFightDialogue_1
gMewtwoReFightDialogue_1: @ 8104044
@ replacing .incbin "baserom.gba", 0x104044, 0xC
.byte 0x00, 0x00, 0x00, 0x00, 0xab, 0x01, 0x00, 0x00
.4byte gUnknown_8103EB0

.global gMewtwoReFightDialogue_2
gMewtwoReFightDialogue_2: @ 8104050
@ replacing .incbin "baserom.gba", 0x104050, 0x7C
.byte 0x00, 0x00, 0x00, 0x0d, 0x96, 0x00, 0x00, 0x00
.4byte gUnknown_810405C

.global gUnknown_810405C
gUnknown_810405C: @ 810405C
.string " I...{WAIT_PRESS}\n"
.string "have secluded myself here in suspended\n"
.string "animation...{EXTRA_MSG}"
.string " Lying in wait...{WAIT_PRESS}\n"
.string "For someone like you to come.\0"
.align 2, 0

.global gMewtwoReFightDialogue_3
gMewtwoReFightDialogue_3: @ 81040CC
@ replacing .incbin "baserom.gba", 0x1040CC, 0x48
.byte 0x00, 0x00, 0x00, 0x0d, 0x96, 0x00, 0x00, 0x00
.4byte gUnknown_81040D8

.global gUnknown_81040D8
gUnknown_81040D8: @ 81040D8
.string " I am {ARG_POKEMON_2}.{WAIT_PRESS}\n"
.string "A Pokémon created only to fight...{WAIT_PRESS}\n"
.string "And...\0"
.align 2, 0

.global gMewtwoReFightDialogue_4
gMewtwoReFightDialogue_4: @ 8104114
@ replacing .incbin "baserom.gba", 0x104114, 0x30
.byte 0x00, 0x00, 0x00, 0x0d, 0x96, 0x00, 0x00, 0x00
.4byte gUnknown_8104120

.global gUnknown_8104120
gUnknown_8104120: @ 8104120
.string " The most powerful Pokémon\n"
.string "of all!\0"
.align 2, 0

.global gMewtwoReFightDialogue_5
gMewtwoReFightDialogue_5: @ 8104144
@ replacing .incbin "baserom.gba", 0x104144, 0xC
.byte 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.4byte gUnknown_8103E40

.global gEnteiPreFightDialogue_1
gEnteiPreFightDialogue_1: @ 8104150
@ replacing .incbin "baserom.gba", 0x104150, 0x5C
.byte 0x00, 0x00, 0x00, 0x00, 0xab, 0x01, 0x00, 0x00
.4byte gUnknown_810415C

.global gUnknown_810415C
gUnknown_810415C: @ 810415C
.string " What compelled you to come?{EXTRA_MSG}"
.string " The likes of you have no business\n"
.string "being here!\0"
.align 2, 0

.global gEnteiPreFightDialogue_2
gEnteiPreFightDialogue_2: @ 81041AC
@ replacing .incbin "baserom.gba", 0x1041AC, 0x4C
.byte 0x02, 0x00, 0x00, 0x0d, 0x0d, 0x01, 0x00, 0x00
.4byte gUnknown_81041B8

.global gUnknown_81041B8
gUnknown_81041B8: @ 81041B8
.string " I am {ARG_POKEMON_2}!{WAIT_PRESS}\n"
.string "I live surrounded by the fiery lava of\n"
.string "volcanoes!\0"
.align 2, 0

.global gEnteiPreFightDialogue_3
gEnteiPreFightDialogue_3: @ 81041F8
@ replacing .incbin "baserom.gba", 0x1041F8, 0x48
.byte 0x00, 0x00, 0x00, 0x0d, 0x0d, 0x01, 0x00, 0x00
.4byte gUnknown_8104204

.global gUnknown_8104204
gUnknown_8104204: @ 8104204
.string " If you refuse to leave...{WAIT_PRESS}\n"
.string "I shall forcefully expel you!\0"
.align 2, 0

.global gEnteiReFightDialogue_1
gEnteiReFightDialogue_1: @ 8104240
@ replacing .incbin "baserom.gba", 0x104240, 0x6C
.byte 0x00, 0x00, 0x00, 0x0d, 0x0d, 0x01, 0x00, 0x00
.4byte gUnknown_810424C

.global gUnknown_810424C
gUnknown_810424C: @ 810424C
.string " Did I not say to never\n"
.string "return?{EXTRA_MSG}"
.string " This is the {COLOR_1 YELLOW_4}Fiery Field{END_COLOR_TEXT_1}!{WAIT_PRESS}\n"
.string "It is no place for your kind!\0"
.align 2, 0

.global gEnteiReFightDialogue_2
gEnteiReFightDialogue_2: @ 81042AC
@ replacing .incbin "baserom.gba", 0x1042AC, 0xC
.byte 0x00, 0x00, 0x00, 0x0d, 0x0d, 0x01, 0x00, 0x00
.4byte gUnknown_81041B8

.global gEnteiReFightDialogue_3
gEnteiReFightDialogue_3: @ 81042B8
@ replacing .incbin "baserom.gba", 0x1042B8, 0x58
.byte 0x00, 0x00, 0x00, 0x0d, 0x0d, 0x01, 0x00, 0x00
.4byte gUnknown_81042C4

.global gUnknown_81042C4
gUnknown_81042C4: @ 81042C4
.string " Since you fail to heed my\n"
.string "words...{WAIT_PRESS}\n"
.string "I've no choice but to defeat you!\0"
.align 2, 0

.global gEnteiPostStoryPreFightDialogue_1
gEnteiPostStoryPreFightDialogue_1: @ 8104310
@ replacing .incbin "baserom.gba", 0x104310, 0x8C
.byte 0x00, 0x00, 0x00, 0x0d, 0x0d, 0x01, 0x00, 0x00
.4byte gUnknown_810431C

.global gUnknown_810431C
gUnknown_810431C: @ 810431C
.string " This is the {COLOR_1 YELLOW_4}Fiery Field{END_COLOR_TEXT_1}!{WAIT_PRESS}\n"
.string "It is no place for your kind!{EXTRA_MSG}"
.string " I am {ARG_POKEMON_2}!{WAIT_PRESS}\n"
.string "I live surrounded by the fiery lava of\n"
.string "volcanoes!\0"
.align 2, 0

.global gEnteiPostStoryPreFightDialogue_2
gEnteiPostStoryPreFightDialogue_2: @ 810439C
@ replacing .incbin "baserom.gba", 0x10439C, 0x24
.byte 0x00, 0x00, 0x00, 0x0d, 0x0d, 0x01, 0x00, 0x00
.4byte gUnknown_81043A8

.global gUnknown_81043A8
gUnknown_81043A8: @ 81043A8
.string " Depart from here...\0"
.align 2, 0

.global gEnteiPostStoryPreFightDialogue_3
gEnteiPostStoryPreFightDialogue_3: @ 81043C0
@ replacing .incbin "baserom.gba", 0x1043C0, 0x1C
.byte 0x00, 0x00, 0x00, 0x0d, 0x0d, 0x01, 0x00, 0x00
.4byte gUnknown_81043CC

.global gUnknown_81043CC
gUnknown_81043CC: @ 81043CC
.string " Immediately!\0"
.align 2, 0

.global gEnteiPostStoryPreFightDialogue_4
gEnteiPostStoryPreFightDialogue_4: @ 81043DC
@ replacing .incbin "baserom.gba", 0x1043DC, 0x74
.byte 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.4byte gUnknown_81043E8

.global gUnknown_81043E8
gUnknown_81043E8: @ 81043E8
.string "{CENTER_ALIGN}The lord of this area isn't here.{EXTRA_MSG}"
.string "{CENTER_ALIGN}It's impossible to go farther.{WAIT_PRESS}\n"
.string "{CENTER_ALIGN}It's time to go back.\0"
.align 2, 0

.global gRaikouPreFightDialogue_1
gRaikouPreFightDialogue_1: @ 8104450
@ replacing .incbin "baserom.gba", 0x104450, 0x64
.byte 0x00, 0x00, 0x00, 0x00, 0xab, 0x01, 0x00, 0x00
.4byte gUnknown_810445C

.global gUnknown_810445C
gUnknown_810445C: @ 810445C
.string " Why...{WAIT_PRESS}\n"
.string "Why have you come...?{EXTRA_MSG}"
.string " This is {COLOR_1 YELLOW_4}Lightning Field{END_COLOR_TEXT_1}.{WAIT_PRESS}\n"
.string "It is my...{WAIT_PRESS}"
.string "domain!\0"
.align 2, 0

.global gRaikouPreFightDialogue_2
gRaikouPreFightDialogue_2: @ 81044B4
@ replacing .incbin "baserom.gba", 0x1044B4, 0x5C
.byte 0x02, 0x00, 0x00, 0x0d, 0x0c, 0x01, 0x00, 0x00
.4byte gUnknown_81044C0

.global gUnknown_81044C0
gUnknown_81044C0: @ 81044C0
.string " I am {ARG_POKEMON_2}!{WAIT_PRESS}\n"
.string "One who races with lightning!{EXTRA_MSG}"
.string " A body like roiling rain\n"
.string "clouds!\0"
.align 2, 0

.global gRaikouPreFightDialogue_3
gRaikouPreFightDialogue_3: @ 8104510
@ replacing .incbin "baserom.gba", 0x104510, 0x2C
.byte 0x00, 0x00, 0x00, 0x0d, 0x0c, 0x01, 0x00, 0x00
.4byte gUnknown_810451C

.global gUnknown_810451C
gUnknown_810451C: @ 810451C
.string " A roar that echoes thunder!\0"
.align 2, 0

.global gRaikouPreFightDialogue_4
gRaikouPreFightDialogue_4: @ 810453C
@ replacing .incbin "baserom.gba", 0x10453C, 0x34
.byte 0x00, 0x00, 0x00, 0x0d, 0x0c, 0x01, 0x00, 0x00
.4byte gUnknown_8104548

.global gUnknown_8104548
gUnknown_8104548: @ 8104548
.string " Many have trespassed upon\n"
.string "my domain...\0"
.align 2, 0

.global gRaikouPreFightDialogue_5
gRaikouPreFightDialogue_5: @ 8104570
@ replacing .incbin "baserom.gba", 0x104570, 0x40
.byte 0x00, 0x00, 0x00, 0x0d, 0x0c, 0x01, 0x00, 0x00
.4byte gUnknown_810457C

.global gUnknown_810457C
gUnknown_810457C: @ 810457C
.string " But what became of them?{WAIT_PRESS}\n"
.string "Let me demonstrate...\0"
.align 2, 0

.global gRaikouPreFightDialogue_6
gRaikouPreFightDialogue_6: @ 81045B0
@ replacing .incbin "baserom.gba", 0x1045B0, 0x48
.byte 0x00, 0x00, 0x00, 0x0d, 0x0c, 0x01, 0x00, 0x00
.4byte gUnknown_81045BC

.global gUnknown_81045BC
gUnknown_81045BC: @ 81045BC
.string " And you, too, shall\n"
.string "experience the pain they suffered!\0"
.align 2, 0

.global gRaikouReFightDialogue_1
gRaikouReFightDialogue_1: @ 81045F8
@ replacing .incbin "baserom.gba", 0x1045F8, 0x7C
.byte 0x00, 0x00, 0x00, 0x0d, 0x0c, 0x01, 0x00, 0x00
.4byte gUnknown_8104604

.global gUnknown_8104604
gUnknown_8104604: @ 8104604
.string " Snicker... You again.{WAIT_PRESS}\n"
.string "You don't give up easily.{EXTRA_MSG}"
.string " If you so wish to taste\n"
.string "defeat again, I shall oblige!\0"
.align 2, 0

.global gRaikouReFightDialogue_2
gRaikouReFightDialogue_2: @ 8104674
@ replacing .incbin "baserom.gba", 0x104674, 0x2C
.byte 0x00, 0x00, 0x00, 0x0d, 0x0c, 0x01, 0x00, 0x00
.4byte gUnknown_8104680

.global gUnknown_8104680
gUnknown_8104680: @ 8104680
.string " With my electric bolts...{WAIT_PRESS}\0"
.align 2, 0

.global gRaikouReFightDialogue_3
gRaikouReFightDialogue_3: @ 81046A0
@ replacing .incbin "baserom.gba", 0x1046A0, 0x2C
.byte 0x00, 0x00, 0x00, 0x0d, 0x0c, 0x01, 0x00, 0x00
.4byte gUnknown_81046AC

.global gUnknown_81046AC
gUnknown_81046AC: @ 81046AC
.string " I will devastate you again!\0"
.align 2, 0

.global gRaikouPostStoryPreFightDialogue_1
gRaikouPostStoryPreFightDialogue_1: @ 81046CC
@ replacing .incbin "baserom.gba", 0x1046CC, 0x78
.byte 0x00, 0x00, 0x00, 0x0d, 0x0c, 0x01, 0x00, 0x00
.4byte gUnknown_81046D8

.global gUnknown_81046D8
gUnknown_81046D8: @ 81046D8
.string " This is {COLOR_1 YELLOW_4}Lightning Field{END_COLOR_TEXT_1}!{WAIT_PRESS}\n"
.string "My domain!{EXTRA_MSG}"
.string " All those who enter...{WAIT_PRESS}\n"
.string "I show no mercy, no matter what!\0"
.align 2, 0

.global gRaikouPostStoryPreFightDialogue_2
gRaikouPostStoryPreFightDialogue_2: @ 8104744
@ replacing .incbin "baserom.gba", 0x104744, 0x28
.byte 0x00, 0x00, 0x00, 0x0d, 0x0c, 0x01, 0x00, 0x00
.4byte gUnknown_8104750

.global gUnknown_8104750
gUnknown_8104750: @ 8104750
.string " With my electric bolts...\0"
.align 2, 0

.global gRaikouPostStoryPreFightDialogue_3
gRaikouPostStoryPreFightDialogue_3: @ 810476C
@ replacing .incbin "baserom.gba", 0x10476C, 0xC
.byte 0x00, 0x00, 0x00, 0x0d, 0x0c, 0x01, 0x00, 0x00
.4byte gUnknown_81046AC

.global gRaikouPostStoryPreFightDialogue_4
gRaikouPostStoryPreFightDialogue_4: @ 8104778
@ replacing .incbin "baserom.gba", 0x104778, 0xC
.byte 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.4byte gUnknown_81043E8

.global gSuicunePreFightDialogue_1
gSuicunePreFightDialogue_1: @ 8104784
@ replacing .incbin "baserom.gba", 0x104784, 0xC
.byte 0x00, 0x00, 0x00, 0x00, 0xab, 0x01, 0x00, 0x00
.4byte gUnknown_8101D98

.global gSuicunePreFightDialogue_2
gSuicunePreFightDialogue_2: @ 8104790
@ replacing .incbin "baserom.gba", 0x104790, 0x20
.byte 0x00, 0x00, 0x00, 0x00, 0xab, 0x01, 0x00, 0x00
.4byte gUnknown_810479C

.global gUnknown_810479C
gUnknown_810479C: @ 810479C
.string " Why are you here?!\0"
.align 2, 0

.global gSuicunePreFightDialogue_3
gSuicunePreFightDialogue_3: @ 81047B0
@ replacing .incbin "baserom.gba", 0x1047B0, 0x9C
.byte 0x00, 0x00, 0x00, 0x00, 0xab, 0x01, 0x00, 0x00
.4byte gUnknown_81047BC

.global gUnknown_81047BC
gUnknown_81047BC: @ 81047BC
.string " Clear and bracing air...{WAIT_PRESS}\n"
.string "Crystalline, pure water...{EXTRA_MSG}"
.string " To stand guard over this beautiful and\n"
.string "untainted land...{WAIT_PRESS}\n"
.string "That is why I am here.\0"
.align 2, 0

.global gSuicunePreFightDialogue_4
gSuicunePreFightDialogue_4: @ 810484C
@ replacing .incbin "baserom.gba", 0x10484C, 0x3C
.byte 0x03, 0x00, 0x00, 0x0d, 0x0e, 0x01, 0x00, 0x00
.4byte gUnknown_8104858

.global gUnknown_8104858
gUnknown_8104858: @ 8104858
.string " I am {ARG_POKEMON_2}!{WAIT_PRESS}\n"
.string "One who runs with the north wind!\0"
.align 2, 0

.global gSuicunePreFightDialogue_5
gSuicunePreFightDialogue_5: @ 8104888
@ replacing .incbin "baserom.gba", 0x104888, 0x40
.byte 0x00, 0x00, 0x00, 0x0d, 0x0e, 0x01, 0x00, 0x00
.4byte gUnknown_8104894

.global gUnknown_8104894
gUnknown_8104894: @ 8104894
.string " Intruders foul the air\n"
.string "with their outside ills.\0"
.align 2, 0

.global gSuicunePreFightDialogue_6
gSuicunePreFightDialogue_6: @ 81048C8
@ replacing .incbin "baserom.gba", 0x1048C8, 0x4C
.byte 0x00, 0x00, 0x00, 0x0d, 0x0e, 0x01, 0x00, 0x00
.4byte gUnknown_81048D4

.global gUnknown_81048D4
gUnknown_81048D4: @ 81048D4
.string " There is but one solution\n"
.string "for invaders: expulsion by force!\0"
.align 2, 0

.global gSuicunePreFightDialogue_7
gSuicunePreFightDialogue_7: @ 8104914
@ replacing .incbin "baserom.gba", 0x104914, 0x1C
.byte 0x00, 0x00, 0x00, 0x0d, 0x0e, 0x01, 0x00, 0x00
.4byte gUnknown_8104920

.global gUnknown_8104920
gUnknown_8104920: @ 8104920
.string " Here I come!\0"
.align 2, 0

.global gSuicuneReFightDialogue_1
gSuicuneReFightDialogue_1: @ 8104930
@ replacing .incbin "baserom.gba", 0x104930, 0x50
.byte 0x00, 0x00, 0x00, 0x0d, 0x0e, 0x01, 0x00, 0x00
.4byte gUnknown_810493C

.global gUnknown_810493C
gUnknown_810493C: @ 810493C
.string " This is no place for you!{EXTRA_MSG}"
.string " Leave immediately!{EXTRA_MSG}"
.string " If you refuse...\0"
.align 2, 0

.global gSuicuneReFightDialogue_2
gSuicuneReFightDialogue_2: @ 8104980
@ replacing .incbin "baserom.gba", 0x104980, 0x18
.byte 0x00, 0x00, 0x00, 0x0d, 0x0e, 0x01, 0x00, 0x00
.4byte gUnknown_810498C

.global gUnknown_810498C
gUnknown_810498C: @ 810498C
.string " I will...\0"
.align 2, 0

.global gSuicuneReFightDialogue_3
gSuicuneReFightDialogue_3: @ 8104998
@ replacing .incbin "baserom.gba", 0x104998, 0x3C
.byte 0x00, 0x00, 0x00, 0x0d, 0x0e, 0x01, 0x00, 0x00
.4byte gUnknown_81049A4

.global gUnknown_81049A4
gUnknown_81049A4: @ 81049A4
.string " With all my furious power...{WAIT_PRESS}\n"
.string "Destroy you!\0"
.align 2, 0

.global gSuicunePostStoryPreFightDialogue_1
gSuicunePostStoryPreFightDialogue_1: @ 81049D4
@ replacing .incbin "baserom.gba", 0x1049D4, 0xAC
.byte 0x00, 0x00, 0x00, 0x0d, 0x0e, 0x01, 0x00, 0x00
.4byte gUnknown_81049E0

.global gUnknown_81049E0
gUnknown_81049E0: @ 81049E0
.string " You mean to challenge me?{EXTRA_MSG}"
.string " I find little satisfaction in\n"
.string "fighting...{WAIT_PRESS}\n"
.string "However!{EXTRA_MSG}"
.string " If you refuse my\n"
.string "demands that you leave...{EXTRA_MSG}"
.string " I will accept your challenge.\0"
.align 2, 0

.global gSuicunePostStoryPreFightDialogue_2
gSuicunePostStoryPreFightDialogue_2: @ 8104A80
@ replacing .incbin "baserom.gba", 0x104A80, 0x1C
.byte 0x00, 0x00, 0x00, 0x0d, 0x0e, 0x01, 0x00, 0x00
.4byte gUnknown_8104A8C

.global gUnknown_8104A8C
gUnknown_8104A8C: @ 8104A8C
.string " Experience it.\0"
.align 2, 0

.global gSuicunePostStoryPreFightDialogue_3
gSuicunePostStoryPreFightDialogue_3: @ 8104A9C
@ replacing .incbin "baserom.gba", 0x104A9C, 0x2C
.byte 0x00, 0x00, 0x00, 0x0d, 0x0e, 0x01, 0x00, 0x00
.4byte gUnknown_8104AA8

.global gUnknown_8104AA8
gUnknown_8104AA8: @ 8104AA8
.string " My true power...{WAIT_PRESS}\n"
.string "Unleashed!\0"
.align 2, 0

.global gSuicunePostStoryPreFightDialogue_4
gSuicunePostStoryPreFightDialogue_4: @ 8104AC8
@ replacing .incbin "baserom.gba", 0x104AC8, 0xC
.byte 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.4byte gUnknown_81043E8

.global gHoOhPreFightDialogue_1
gHoOhPreFightDialogue_1: @ 8104AD4
@ replacing .incbin "baserom.gba", 0x104AD4, 0x118
.byte 0x00, 0x00, 0x00, 0x00, 0xab, 0x01, 0x00, 0x00
.4byte gUnknown_8104AE0

.global gUnknown_8104AE0
gUnknown_8104AE0: @ 8104AE0
.string " Excellent!{EXTRA_MSG}"
.string " You have done well to come this far.{EXTRA_MSG}"
.string " You have overcome countless\n"
.string "challenges...{EXTRA_MSG}"
.string " Fought through many dangerous\n"
.string "situations...{EXTRA_MSG}"
.string " and finally ascended to the very peak\n"
.string "of {COLOR_1 YELLOW_4}Mt. Faraway{END_COLOR_TEXT_1}!{EXTRA_MSG}"
.string " Truly, only the chosen have reached\n"
.string "the summit.{EXTRA_MSG}"
.string " However!\0"
.align 2, 0

.global gHoOhPreFightDialogue_2
gHoOhPreFightDialogue_2: @ 8104BEC
@ replacing .incbin "baserom.gba", 0x104BEC, 0x24
.byte 0x00, 0x00, 0x00, 0x00, 0xab, 0x01, 0x00, 0x00
.4byte gUnknown_8104BF8

.global gUnknown_8104BF8
gUnknown_8104BF8: @ 8104BF8
.string " This is not the end!\0"
.align 2, 0

.global gHoOhPreFightDialogue_3
gHoOhPreFightDialogue_3: @ 8104C10
@ replacing .incbin "baserom.gba", 0x104C10, 0x44
.byte 0x03, 0x00, 0x00, 0x0d, 0x13, 0x01, 0x00, 0x00
.4byte gUnknown_8104C1C

.global gUnknown_8104C1C
gUnknown_8104C1C: @ 8104C1C
.string " I am {ARG_POKEMON_2}!{WAIT_PRESS}\n"
.string "The builder of rainbows across the sky!\0"
.align 2, 0

.global gHoOhPreFightDialogue_4
gHoOhPreFightDialogue_4: @ 8104C54
@ replacing .incbin "baserom.gba", 0x104C54, 0x60
.byte 0x00, 0x00, 0x00, 0x0d, 0x13, 0x01, 0x00, 0x00
.4byte gUnknown_8104C60

.global gUnknown_8104C60
gUnknown_8104C60: @ 8104C60
.string " Only when you overcome\n"
.string "me in battle...{WAIT_PRESS}\n"
.string "That is when this mountain is conquered!\0"
.align 2, 0

.global gHoOhPreFightDialogue_5
gHoOhPreFightDialogue_5: @ 8104CB4
@ replacing .incbin "baserom.gba", 0x104CB4, 0x2C
.byte 0x00, 0x00, 0x00, 0x0d, 0x13, 0x01, 0x00, 0x00
.4byte gUnknown_8104CC0

.global gUnknown_8104CC0
gUnknown_8104CC0: @ 8104CC0
.string " This is the final challenge!\0"
.align 2, 0

.global gHoOhPreFightDialogue_6
gHoOhPreFightDialogue_6: @ 8104CE0
@ replacing .incbin "baserom.gba", 0x104CE0, 0xC
.byte 0x00, 0x00, 0x00, 0x0d, 0x13, 0x01, 0x00, 0x00
.4byte gUnknown_8104920

.global HoOhReFightDialogue_1
HoOhReFightDialogue_1: @ 8104CEC
@ replacing .incbin "baserom.gba", 0x104CEC, 0x74
.byte 0x00, 0x00, 0x00, 0x00, 0xab, 0x01, 0x00, 0x00
.4byte gUnknown_8104CF8

.global gUnknown_8104CF8
gUnknown_8104CF8: @ 8104CF8
.string " Very good!{EXTRA_MSG}"
.string " You have done well to come this far.{EXTRA_MSG}"
.string " Truly, only the chosen have reached\n"
.string "the summit.\0"
.align 2, 0

.global HoOhReFightDialogue_2
HoOhReFightDialogue_2: @ 8104D60
@ replacing .incbin "baserom.gba", 0x104D60, 0x7C
.byte 0x00, 0x00, 0x00, 0x0d, 0x13, 0x01, 0x00, 0x00
.4byte gUnknown_8104D6C

.global gUnknown_8104D6C
gUnknown_8104D6C: @ 8104D6C
.string " Your very arrival is\n"
.string "evidence of a truly powerful warrior!{WAIT_PRESS}\n"
.string "And...{EXTRA_MSG}"
.string " It is also your right to\n"
.string "challenge me!\0"
.align 2, 0

.global HoOhReFightDialogue_3
HoOhReFightDialogue_3: @ 8104DDC
@ replacing .incbin "baserom.gba", 0x104DDC, 0x30
.byte 0x00, 0x00, 0x00, 0x0d, 0x13, 0x01, 0x00, 0x00
.4byte gUnknown_8104DE8

.global gUnknown_8104DE8
gUnknown_8104DE8: @ 8104DE8
.string " Surpass your own\n"
.string "limitations...\0"
.align 2, 0

.global HoOhReFightDialogue_4
HoOhReFightDialogue_4: @ 8104E0C
@ replacing .incbin "baserom.gba", 0x104E0C, 0x48
.byte 0x00, 0x00, 0x00, 0x0d, 0x13, 0x01, 0x00, 0x00
.4byte gUnknown_8104E18

.global gUnknown_8104E18
gUnknown_8104E18: @ 8104E18
.string " And show me your power in\n"
.string "its unbridled entirety!\n"
.string "Come on!\0"
.align 2, 0

.global HoOhReFightDialogue_5
HoOhReFightDialogue_5: @ 8104E54
@ replacing .incbin "baserom.gba", 0x104E54, 0xC
.byte 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.4byte gUnknown_81043E8

.global gLatiosPreFightDialogue_1
gLatiosPreFightDialogue_1: @ 8104E60
@ replacing .incbin "baserom.gba", 0x104E60, 0x9C
.byte 0x02, 0x00, 0x00, 0x0d, 0x99, 0x01, 0x00, 0x00
.4byte gUnknown_8104E6C

.global gUnknown_8104E6C
gUnknown_8104E6C: @ 8104E6C
.string " Oh!{WAIT_PRESS}\n"
.string "Who are you?!{EXTRA_MSG}"
.string " ............{WAIT_PRESS}\n"
.string "I see. You're trying to get your TMs back.{EXTRA_MSG}"
.string " But!{EXTRA_MSG}"
.string " Nobody can stop me!{EXTRA_MSG}"
.string " I'm the Eon Pokémon {ARG_POKEMON_2}!\0"
.align 2, 0

.global gLatiosPreFightDialogue_2
gLatiosPreFightDialogue_2: @ 8104EFC
@ replacing .incbin "baserom.gba", 0x104EFC, 0x34
.byte 0x00, 0x00, 0x00, 0x0d, 0x99, 0x01, 0x00, 0x00
.4byte gUnknown_8104F08

.global gUnknown_8104F08
gUnknown_8104F08: @ 8104F08
.string " If you really want your\n"
.string "TMs back...\0"
.align 2, 0

.global gLatiosPreFightDialogue_3
gLatiosPreFightDialogue_3: @ 8104F30
@ replacing .incbin "baserom.gba", 0x104F30, 0x34
.byte 0x00, 0x00, 0x00, 0x0d, 0x99, 0x01, 0x00, 0x00
.4byte gUnknown_8104F3C

.global gUnknown_8104F3C
gUnknown_8104F3C: @ 8104F3C
.string " You'll have to take them\n"
.string "from me!\0"
.align 2, 0

.global gLatiosReFightDialogue_1
gLatiosReFightDialogue_1: @ 8104F64
@ replacing .incbin "baserom.gba", 0x104F64, 0x64
.byte 0x00, 0x00, 0x00, 0x0d, 0x99, 0x01, 0x00, 0x00
.4byte gUnknown_8104F70

.global gUnknown_8104F70
gUnknown_8104F70: @ 8104F70
.string " You're back?{EXTRA_MSG}"
.string " But!{EXTRA_MSG}"
.string " It doesn't matter how often\n"
.string "you come!{WAIT_PRESS}\n"
.string "Nobody can stop me!\0"
.align 2, 0

.global gUnknown_8104FC8
gUnknown_8104FC8: @ 8104FC8
@ replacing .incbin "baserom.gba", 0x104FC8, 0xC
.byte 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.4byte gUnknown_8100D48

.global gRegirockPreFightDialogue_1
gRegirockPreFightDialogue_1: @ 8104FD4
@ replacing .incbin "baserom.gba", 0x104FD4, 0x54
.byte 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.4byte gUnknown_8104FE0

.global gUnknown_8104FE0
gUnknown_8104FE0: @ 8104FE0
.string "{CENTER_ALIGN}INTRUDER ALERT!{EXTRA_MSG}"
.string "{CENTER_ALIGN}EXTERMINATE!{EXTRA_MSG}"
.string "{CENTER_ALIGN}INTRUDER ALERT!{EXTRA_MSG}"
.string "{CENTER_ALIGN}EXTERMINATE!\0"
.align 2, 0

.global gRegicePreFightDialogue_1
gRegicePreFightDialogue_1: @ 8105028
@ replacing .incbin "baserom.gba", 0x105028, 0xC
.byte 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.4byte gUnknown_8104FE0

.global gRegisteelPreFightDialogue_1
gRegisteelPreFightDialogue_1: @ 8105034
@ replacing .incbin "baserom.gba", 0x105034, 0xC
.byte 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.4byte gUnknown_8104FE0

.global gRegirockPostFightDialogue_1
gRegirockPostFightDialogue_1: @ 8105040
@ replacing .incbin "baserom.gba", 0x105040, 0x74
.byte 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.4byte gUnknown_810504C

.global gUnknown_810504C
gUnknown_810504C: @ 810504C
.string "{CENTER_ALIGN}Something fell from\n"
.string "{CENTER_ALIGN}{COLOR_1 CYAN_3}Regirock{END_COLOR_TEXT_1}'s body.{EXTRA_MSG}"
.string "{CENTER_ALIGN}{COLOR_1 CYAN_3}Regirock{END_COLOR_TEXT_1} was apparently\n"
.string "{CENTER_ALIGN}guarding this item.\0"
.align 2, 0

.global gRegirockPostFightDialogue_2
gRegirockPostFightDialogue_2: @ 81050B4
@ replacing .incbin "baserom.gba", 0x1050B4, 0x58
.byte 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.4byte gUnknown_81050C0

.global gUnknown_81050C0
gUnknown_81050C0: @ 81050C0
.string "{CENTER_ALIGN}{ARG_POKEMON_0} obtained\n"
.string "{CENTER_ALIGN}the {COLOR_1 GREEN_2}Rock Part{END_COLOR_TEXT_1}...{EXTRA_MSG}"
.string "{CENTER_ALIGN}that {COLOR_1 CYAN_3}Regirock{END_COLOR_TEXT_1} was guarding!\0"
.align 2, 0

.global gRegicePostFightDialogue_1
gRegicePostFightDialogue_1: @ 810510C
@ replacing .incbin "baserom.gba", 0x10510C, 0x70
.byte 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.4byte gUnknown_8105118

.global gUnknown_8105118
gUnknown_8105118: @ 8105118
.string "{CENTER_ALIGN}Something fell from\n"
.string "{CENTER_ALIGN}{COLOR_1 CYAN_3}Regice{END_COLOR_TEXT_1}'s body.{EXTRA_MSG}"
.string "{CENTER_ALIGN}{COLOR_1 CYAN_3}Regice{END_COLOR_TEXT_1} was apparently\n"
.string "{CENTER_ALIGN}guarding this item.\0"
.align 2, 0

.global gRegicePostFightDialogue_2
gRegicePostFightDialogue_2: @ 810517C
@ replacing .incbin "baserom.gba", 0x10517C, 0x54
.byte 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.4byte gUnknown_8105188

.global gUnknown_8105188
gUnknown_8105188: @ 8105188
.string "{CENTER_ALIGN}{ARG_POKEMON_0} obtained\n"
.string "{CENTER_ALIGN}the {COLOR_1 GREEN_2}Ice Part{END_COLOR_TEXT_1}...{EXTRA_MSG}"
.string "{CENTER_ALIGN}that {COLOR_1 CYAN_3}Regice{END_COLOR_TEXT_1} was guarding!\0"
.align 2, 0

.global gRegisteelPostFightDialogue_1
gRegisteelPostFightDialogue_1: @ 81051D0
@ replacing .incbin "baserom.gba", 0x1051D0, 0x74
.byte 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.4byte gUnknown_81051DC

.global gUnknown_81051DC
gUnknown_81051DC: @ 81051DC
.string "{CENTER_ALIGN}Something fell from\n"
.string "{CENTER_ALIGN}{COLOR_1 CYAN_3}Registeel{END_COLOR_TEXT_1}'s body.{EXTRA_MSG}"
.string "{CENTER_ALIGN}{COLOR_1 CYAN_3}Registeel{END_COLOR_TEXT_1} was apparently\n"
.string "{CENTER_ALIGN}guarding this item.\0"
.align 2, 0

.global gRegisteelPostFightDialogue_2
gRegisteelPostFightDialogue_2: @ 8105244
@ replacing .incbin "baserom.gba", 0x105244, 0xD8
.byte 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.4byte gUnknown_8105250

.global gUnknown_8105250
gUnknown_8105250: @ 8105250
.string "{CENTER_ALIGN}{ARG_POKEMON_0} obtained\n"
.string "{CENTER_ALIGN}the {COLOR_1 GREEN_2}Steel Part{END_COLOR_TEXT_1}...{EXTRA_MSG}"
.string "{CENTER_ALIGN}that {COLOR_1 CYAN_3}Registeel{END_COLOR_TEXT_1} was guarding!\0"
.align 2, 0

.global gUnknown_81052A0
gUnknown_81052A0: @ 81052A0
.string "{CENTER_ALIGN}That means...{EXTRA_MSG}"
.string "{CENTER_ALIGN}By finding the {COLOR_1 GREEN_2}Rock Part{END_COLOR_TEXT_1},\n"
.string "{CENTER_ALIGN}{COLOR_1 GREEN_2}Ice Part{END_COLOR_TEXT_1}, and {COLOR_1 GREEN_2}Steel Part{END_COLOR_TEXT_1}...{EXTRA_MSG}"
.string "{CENTER_ALIGN}All three parts are yours!\0"
.align 2, 0

.global gUnknown_810531C
gUnknown_810531C: @ 810531C
@ replacing .incbin "baserom.gba", 0x10531C, 0x44
.4byte gUnknown_81052A0

.global gUnknown_8105320
gUnknown_8105320: @ 8105320
.string "{CENTER_ALIGN}Oh? The three parts...{WAIT_PRESS}\n"
.string "{CENTER_ALIGN}They're reacting to each other?\0"
.align 2, 0

.global gUnknown_8105360
gUnknown_8105360: @ 8105360
@ replacing .incbin "baserom.gba", 0x105360, 0x48
.4byte gUnknown_8105320

.global gUnknown_8105364
gUnknown_8105364: @ 8105364
.string "{CENTER_ALIGN}The three parts\n"
.string "{CENTER_ALIGN}fit together...{EXTRA_MSG}"
.string "{CENTER_ALIGN}and became a {COLOR_1 GREEN_2}Music Box{END_COLOR_TEXT_1}!\0"
.align 2, 0

.global gUnknown_81053A8
gUnknown_81053A8: @ 81053A8
@ replacing .incbin "baserom.gba", 0x1053A8, 0x8C
.4byte gUnknown_8105364

.global gUnknown_81053AC
gUnknown_81053AC: @ 81053AC
.string "{CENTER_ALIGN}{ARG_POKEMON_0} obtained\n"
.string "{CENTER_ALIGN}the {COLOR_1 GREEN_2}Music Box{END_COLOR_TEXT_1}!{EXTRA_MSG}"
.string "{CENTER_ALIGN}The {COLOR_1 GREEN_2}Music Box{END_COLOR_TEXT_1} only needs\n"
.string "{CENTER_ALIGN}to be in the Toolbox for it to\n"
.string "{CENTER_ALIGN}attract a special something!\0"
.align 2, 0

.global gUnknown_8105434
gUnknown_8105434: @ 8105434
@ replacing .incbin "baserom.gba", 0x105434, 0x4
.4byte gUnknown_81053AC

.global gJirachiPreFightDialogue_1
gJirachiPreFightDialogue_1: @ 8105438
@ replacing .incbin "baserom.gba", 0x105438, 0x68
.byte 0x00, 0x00, 0x01, 0x0d, 0xab, 0x01, 0x00, 0x00
.4byte gUnknown_8105444

.global gUnknown_8105444
gUnknown_8105444: @ 8105444
.string " ........................{EXTRA_MSG}"
.string " ......Fwaaaaaaaahhh......{EXTRA_MSG}"
.string " I'm still sleepy...\n"
.string "Fnyumnyum...\0"
.align 2, 0

.global gJirachiPreFightDialogue_2
gJirachiPreFightDialogue_2: @ 81054A0
@ replacing .incbin "baserom.gba", 0x1054A0, 0x44
.byte 0x00, 0x00, 0x01, 0x0d, 0xab, 0x01, 0x00, 0x00
.4byte gUnknown_81054AC

.global gUnknown_81054AC
gUnknown_81054AC: @ 81054AC
.string " ...Who is it?{EXTRA_MSG}"
.string " Who is that over there?\n"
.string "Fnyumnyum...\0"
.align 2, 0

.global gJirachiPreFightDialogue_3
gJirachiPreFightDialogue_3: @ 81054E4
@ replacing .incbin "baserom.gba", 0x1054E4, 0x28
.byte 0x02, 0x00, 0x01, 0x0d, 0x9d, 0x01, 0x00, 0x00
.4byte gUnknown_81054F0

.global gUnknown_81054F0
gUnknown_81054F0: @ 81054F0
.string " I'm {ARG_POKEMON_2}.\n"
.string "Who are you?\0"
.align 2, 0

.global gJirachiPreFightDialogue_4
gJirachiPreFightDialogue_4: @ 810550C
@ replacing .incbin "baserom.gba", 0x10550C, 0x40
.byte 0x00, 0x00, 0x01, 0x0d, 0x9d, 0x01, 0x00, 0x00
.4byte gUnknown_8105518

.global gUnknown_8105518
gUnknown_8105518: @ 8105518
.string " ......Fwaaaaahhhh......\n"
.string "I'm still...sleepy...\0"
.align 2, 0

.global gUnknown_810554C
gUnknown_810554C: @ 810554C
@ replacing .incbin "baserom.gba", 0x10554C, 0xC
.byte 0x01, 0x00, 0x01, 0x0d, 0x9d, 0x01, 0x00, 0x00
.4byte gUnknown_8105518

.global gUnknown_8105558
gUnknown_8105558: @ 8105558
@ replacing .incbin "baserom.gba", 0x105558, 0x9C
.byte 0x00, 0x00, 0x01, 0x0d, 0x9d, 0x01, 0x00, 0x00
.4byte gUnknown_8105564

.global gUnknown_8105564
gUnknown_8105564: @ 8105564
.string " ...I think I had a dream,\n"
.string "and I was fighting in it...{WAIT_PRESS}\n"
.string "Did I imagine it?{EXTRA_MSG}"
.string " ...I'm sleepy, so I'm going\n"
.string "back to sleep...\n"
.string "Good night...\0"
.align 2, 0

.global gUnknown_81055F4
gUnknown_81055F4: @ 81055F4
@ replacing .incbin "baserom.gba", 0x1055F4, 0x74
.byte 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.4byte gUnknown_8105600

.global gUnknown_8105600
gUnknown_8105600: @ 8105600
.string "{CENTER_ALIGN}{COLOR_1 CYAN_3}{ARG_POKEMON_2}{END_COLOR_TEXT_1} fell\n"
.string "{CENTER_ALIGN}back into a deep sleep...{EXTRA_MSG}"
.string "{CENTER_ALIGN}Apparently, {COLOR_1 CYAN_3}{ARG_POKEMON_2}{END_COLOR_TEXT_1}\n"
.string "{CENTER_ALIGN}was fighting in its sleep...\0"
.align 2, 0

.global gUnknown_8105668
gUnknown_8105668: @ 8105668
@ replacing .incbin "baserom.gba", 0x105668, 0xC
.byte 0x00, 0x00, 0x01, 0x0d, 0x9d, 0x01, 0x00, 0x00
.4byte gUnknown_8105518

.global gUnknown_8105674
gUnknown_8105674: @ 8105674
@ replacing .incbin "baserom.gba", 0x105674, 0x44
.byte 0x00, 0x00, 0x01, 0x0d, 0x9d, 0x01, 0x00, 0x00
.4byte gUnknown_8105680

.global gUnknown_8105680
gUnknown_8105680: @ 8105680
.string " ...Oh, oh?!\n"
.string "I hear singing...{EXTRA_MSG}"
.string " A song of purity...\0"
.align 2, 0

.global gUnknown_81056B8
gUnknown_81056B8: @ 81056B8
@ replacing .incbin "baserom.gba", 0x1056B8, 0x24
.byte 0x00, 0x00, 0x00, 0x0d, 0x9d, 0x01, 0x00, 0x00
.4byte gUnknown_81056C4

.global gUnknown_81056C4
gUnknown_81056C4: @ 81056C4
.string " Ha!{WAIT_PRESS}\n"
.string "Eyes wide open!\0"
.align 2, 0

.global gUnknown_81056DC
gUnknown_81056DC: @ 81056DC
@ replacing .incbin "baserom.gba", 0x1056DC, 0xBC
.byte 0x00, 0x00, 0x00, 0x0d, 0x9d, 0x01, 0x00, 0x00
.4byte gUnknown_81056E8

.global gUnknown_81056E8
gUnknown_81056E8: @ 81056E8
.string " I don't know why, but I'm\n"
.string "wide awake!{EXTRA_MSG}"
.string " I'm {ARG_POKEMON_2}.{EXTRA_MSG}"
.string " When I awaken, I grant\n"
.string "a wish.\n"
.string "I have to.{EXTRA_MSG}"
.string " Er-hem...{WAIT_PRESS}\n"
.string "Then...{WAIT_PRESS}"
.string " I ask you this.\0"
.align 2, 0

.global gUnknown_8105778
gUnknown_8105778: @ 8105778
.string "{COLOR_1 YELLOW_5}{ARG_POKEMON_2}{END_COLOR_TEXT_1}: What is your \n"
.string "wish?\0"
.align 2, 0

.global gUnknown_8105798
gUnknown_8105798: @ 8105798
@ replacing .incbin "baserom.gba", 0x105798, 0x4
.4byte gUnknown_8105778

.global gUnknown_810579C
gUnknown_810579C: @ 810579C
@ replacing .incbin "baserom.gba", 0x10579C, 0x80
.4byte gUnknown_810580C
.byte 0x01, 0x00, 0x00, 0x00
.4byte gUnknown_81057FC
.byte 0x02, 0x00, 0x00, 0x00
.4byte gUnknown_81057EC
.byte 0x03, 0x00, 0x00, 0x00
.4byte gUnknown_81057DC
.byte 0x04, 0x00, 0x00, 0x00
.4byte gUnknown_81057CC
.byte 0x05, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff

.global gUnknown_81057CC
gUnknown_81057CC: @ 81057CC
.string "Something good!\0"
.align 2, 0

.global gUnknown_81057DC
gUnknown_81057DC: @ 81057DC
.string "More strength.\0"
.align 2, 0

.global gUnknown_81057EC
gUnknown_81057EC: @ 81057EC
.string "A Friend Area.\0"
.align 2, 0

.global gUnknown_81057FC
gUnknown_81057FC: @ 81057FC
.string "Lots of items.\0"
.align 2, 0

.global gUnknown_810580C
gUnknown_810580C: @ 810580C
.string "Lots of money.\0"
.align 2, 0

.global gUnknown_810581C
gUnknown_810581C: @ 810581C
@ replacing .incbin "baserom.gba", 0x10581C, 0x8C
.byte 0x00, 0x00, 0x00, 0x0d, 0x9d, 0x01, 0x00, 0x00
.4byte gUnknown_8105828

.global gUnknown_8105828
gUnknown_8105828: @ 8105828
.string " You want lots of money?{EXTRA_MSG}"
.string " As you wish.{WAIT_PRESS}\n"
.string "I'll gather all the money in the dungeon and\n"
.string "bring it here.{EXTRA_MSG}"
.string " Now...{WAIT_PRESS}\n"
.string "Here goes!\0"
.align 2, 0

.global gUnknown_81058A8
gUnknown_81058A8: @ 81058A8
@ replacing .incbin "baserom.gba", 0x1058A8, 0x1C
.byte 0x00, 0x00, 0x00, 0x0d, 0x9d, 0x01, 0x00, 0x00
.4byte gUnknown_81058B4

.global gUnknown_81058B4
gUnknown_81058B4: @ 81058B4
.string " Nnnnnnnnnn!\0"
.align 2, 0

.global gUnknown_81058C4
gUnknown_81058C4: @ 81058C4
@ replacing .incbin "baserom.gba", 0x1058C4, 0x1C
.byte 0x00, 0x00, 0x00, 0x0d, 0x9d, 0x01, 0x00, 0x00
.4byte gUnknown_81058D0

.global gUnknown_81058D0
gUnknown_81058D0: @ 81058D0
.string " Taaaaaaaah!\0"
.align 2, 0

.global gUnknown_81058E0
gUnknown_81058E0: @ 81058E0
@ replacing .incbin "baserom.gba", 0x1058E0, 0x5C
.byte 0x00, 0x00, 0x00, 0x0d, 0x9d, 0x01, 0x00, 0x00
.4byte gUnknown_81058EC

.global gUnknown_81058EC
gUnknown_81058EC: @ 81058EC
.string " ...Fwaaaaaaaahhh...{EXTRA_MSG}"
.string " Using that power...\n"
.string "Made me sleepy...{WAIT_PRESS}\n"
.string "Good night...\0"
.align 2, 0

.global gUnknown_810593C
gUnknown_810593C: @ 810593C
@ replacing .incbin "baserom.gba", 0x10593C, 0x38
.byte 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.4byte gUnknown_8105948

.global gUnknown_8105948
gUnknown_8105948: @ 8105948
.string "{CENTER_ALIGN}{COLOR_1 CYAN_3}{ARG_POKEMON_2}{END_COLOR_TEXT_1} fell\n"
.string "{CENTER_ALIGN}back into a deep sleep...\0"
.align 2, 0

.global gUnknown_8105974
gUnknown_8105974: @ 8105974
@ replacing .incbin "baserom.gba", 0x105974, 0x94
.byte 0x00, 0x00, 0x00, 0x0d, 0x9d, 0x01, 0x00, 0x00
.4byte gUnknown_8105980

.global gUnknown_8105980
gUnknown_8105980: @ 8105980
.string " You want lots of items?{EXTRA_MSG}"
.string " As you wish.{WAIT_PRESS}\n"
.string "I'll gather all the good items in the dungeon\n"
.string "and bring them here.{EXTRA_MSG}"
.string " Now...{WAIT_PRESS}\n"
.string "Here goes!\0"
.align 2, 0

.global gUnknown_8105A08
gUnknown_8105A08: @ 8105A08
@ replacing .incbin "baserom.gba", 0x105A08, 0xCC
.byte 0x00, 0x00, 0x00, 0x0d, 0x9d, 0x01, 0x00, 0x00
.4byte gUnknown_8105A14

.global gUnknown_8105A14
gUnknown_8105A14: @ 8105A14
.string " You want a Friend Area?{EXTRA_MSG}"
.string " ...But...{WAIT_PRESS}\n"
.string "Don't you already have many Friend\n"
.string "Areas?{EXTRA_MSG}"
.string " I can't grant you that wish,\n"
.string "so can you choose another one?{EXTRA_MSG}"
.string " Er-hem...{WAIT_PRESS}\n"
.string "Then...{WAIT_PRESS}"
.string " I ask you again.\0"
.align 2, 0

.global gUnknown_8105AD4
gUnknown_8105AD4: @ 8105AD4
@ replacing .incbin "baserom.gba", 0x105AD4, 0x4C
.byte 0x00, 0x00, 0x00, 0x0d, 0x9d, 0x01, 0x00, 0x00
.4byte gUnknown_8105AE0

.global gUnknown_8105AE0
gUnknown_8105AE0: @ 8105AE0
.string " You want a Friend Area?{EXTRA_MSG}"
.string " As you wish.{WAIT_PRESS}\n"
.string "Now...{WAIT_PRESS}\n"
.string "Here goes!\0"
.align 2, 0

.global gUnknown_8105B20
gUnknown_8105B20: @ 8105B20
@ replacing .incbin "baserom.gba", 0x105B20, 0x48
.byte 0x00, 0x00, 0x00, 0x0d, 0x9d, 0x01, 0x00, 0x00
.4byte gUnknown_8105B2C

.global gUnknown_8105B2C
gUnknown_8105B2C: @ 8105B2C
.string " I opened a new Friend Area\n"
.string "for you. It's yours to use!\0"
.align 2, 0

.global gUnknown_8105B68
gUnknown_8105B68: @ 8105B68
@ replacing .incbin "baserom.gba", 0x105B68, 0x40
.byte 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.4byte gUnknown_8105B74

.global gUnknown_8105B74
gUnknown_8105B74: @ 8105B74
.string "{CENTER_ALIGN}{COLOR_1 CYAN_3}{ARG_POKEMON_0}{END_COLOR_TEXT_1} obtained\n"
.string "{CENTER_ALIGN}the Friend Area\n"
.string "{CENTER_ALIGN}{COLOR_1 UNK_COLOR_5}{ARG_MOVE_ITEM_0}{END_COLOR_TEXT_1}!\0"
.align 2, 0

.global gUnknown_8105BA8
gUnknown_8105BA8: @ 8105BA8
@ replacing .incbin "baserom.gba", 0x105BA8, 0x4C
.byte 0x00, 0x00, 0x00, 0x0d, 0x9d, 0x01, 0x00, 0x00
.4byte gUnknown_8105BB4

.global gUnknown_8105BB4
gUnknown_8105BB4: @ 8105BB4
.string " You want to be stronger?{EXTRA_MSG}"
.string " As you wish.{WAIT_PRESS}\n"
.string "Now...{WAIT_PRESS}\n"
.string "Here goes!\0"
.align 2, 0

.global gUnknown_8105BF4
gUnknown_8105BF4: @ 8105BF4
@ replacing .incbin "baserom.gba", 0x105BF4, 0x138
.byte 0x00, 0x00, 0x00, 0x0d, 0x9d, 0x01, 0x00, 0x00
.4byte gUnknown_8105C00

.global gUnknown_8105C00
gUnknown_8105C00: @ 8105C00
.string " I gathered up items from\n"
.string "all over the dungeon that may make you \n"
.string "stronger.{EXTRA_MSG}"
.string " But don't use them now.{WAIT_PRESS}\n"
.string "When you leave the {COLOR_1 YELLOW_4}Wish Cave{END_COLOR_TEXT_1}, your\n"
.string "powers go back to their original state.{EXTRA_MSG}"
.string " So, you should only use\n"
.string "those items after you take them back.{EXTRA_MSG}"
.string " I hope you keep working to\n"
.string "become stronger!\0"
.align 2, 0

.global gUnknown_8105D2C
gUnknown_8105D2C: @ 8105D2C
@ replacing .incbin "baserom.gba", 0x105D2C, 0x54
.byte 0x00, 0x00, 0x00, 0x0d, 0x9d, 0x01, 0x00, 0x00
.4byte gUnknown_8105D38

.global gUnknown_8105D38
gUnknown_8105D38: @ 8105D38
.string " Something good?{WAIT_PRESS}\n"
.string "That's not very easy...{EXTRA_MSG}"
.string " But I'll do my best!\0"
.align 2, 0

.global gUnknown_8105D80
gUnknown_8105D80: @ 8105D80
@ replacing .incbin "baserom.gba", 0x105D80, 0x1C
.byte 0x00, 0x00, 0x00, 0x0d, 0x9d, 0x01, 0x00, 0x00
.4byte gUnknown_8105D8C

.global gUnknown_8105D8C
gUnknown_8105D8C: @ 8105D8C
.string " It's done...\0"
.align 2, 0

.global gUnknown_8105D9C
gUnknown_8105D9C: @ 8105D9C
@ replacing .incbin "baserom.gba", 0x105D9C, 0x78
.byte 0x00, 0x00, 0x00, 0x0d, 0x9d, 0x01, 0x00, 0x00
.4byte gUnknown_8105DA8

.global gUnknown_8105DA8
gUnknown_8105DA8: @ 8105DA8
.string " If you can get home safely,\n"
.string "I think there will be something good\n"
.string "waiting for you.{WAIT_PRESS}"
.string " Maybe.{WAIT_PRESS}"
.string " Definitely.\0"
.align 2, 0

.global gJirachiReFightDialogue_1
gJirachiReFightDialogue_1: @ 8105E14
@ replacing .incbin "baserom.gba", 0x105E14, 0x74
.byte 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.4byte gUnknown_8105E20

.global gUnknown_8105E20
gUnknown_8105E20: @ 8105E20
.string "{CENTER_ALIGN}The master of this area isn't here.{EXTRA_MSG}"
.string "{CENTER_ALIGN}It's impossible to go farther.{WAIT_PRESS}\n"
.string "{CENTER_ALIGN}It's time to go back.\0"
.align 2, 0
@ Lugia Fight Dialogue

.global gLugiaPreFightDialogue_1
gLugiaPreFightDialogue_1: @ 8105E88
@ replacing .incbin "baserom.gba", 0x105E88, 0x70
.byte 0x00, 0x00, 0x00, 0x00, 0xab, 0x01, 0x00, 0x00
.4byte gUnknown_8105E94

.global gUnknown_8105E94
gUnknown_8105E94: @ 8105E94
.string " Why...{WAIT_PRESS}\n"
.string "Why have you come here...?{EXTRA_MSG}"
.string " This is...{WAIT_PRESS}"
.string "the {COLOR_1 YELLOW_4}Silver Trench{END_COLOR_TEXT_1}.{WAIT_PRESS}\n"
.string "This is my territory!\0"
.align 2, 0

.global gLugiaPreFightDialogue_2
gLugiaPreFightDialogue_2: @ 8105EF8
@ replacing .incbin "baserom.gba", 0x105EF8, 0x40
.byte 0x02, 0x00, 0x00, 0x0d, 0x12, 0x01, 0x00, 0x00
.4byte gUnknown_8105F04

.global gUnknown_8105F04
gUnknown_8105F04: @ 8105F04
.string " My name is {ARG_POKEMON_2}!{WAIT_PRESS}\n"
.string "I am the guardian of the seas!\0"
.align 2, 0

.global gLugiaPreFightDialogue_3
gLugiaPreFightDialogue_3: @ 8105F38
@ replacing .incbin "baserom.gba", 0x105F38, 0x3C
.byte 0x00, 0x00, 0x00, 0x0d, 0x12, 0x01, 0x00, 0x00
.4byte gUnknown_8105F44

.global gUnknown_8105F44
gUnknown_8105F44: @ 8105F44
.string " To protect this sea,\n"
.string "I have settled here...\0"
.align 2, 0

.global gLugiaPreFightDialogue_4
gLugiaPreFightDialogue_4: @ 8105F74
@ replacing .incbin "baserom.gba", 0x105F74, 0x2C
.byte 0x00, 0x00, 0x00, 0x0d, 0x12, 0x01, 0x00, 0x00
.4byte gUnknown_8105F80

.global gUnknown_8105F80
gUnknown_8105F80: @ 8105F80
.string " If you dare to challenge\n"
.string "me...\0"
.align 2, 0

.global gLugiaPreFightDialogue_5
gLugiaPreFightDialogue_5: @ 8105FA0
@ replacing .incbin "baserom.gba", 0x105FA0, 0x38
.byte 0x00, 0x00, 0x00, 0x0d, 0x12, 0x01, 0x00, 0x00
.4byte gUnknown_8105FAC

.global gUnknown_8105FAC
gUnknown_8105FAC: @ 8105FAC
.string " So be it!\n"
.string "I will rise to your challenge!\0"
.align 2, 0

.global gLugiaPreFightDialogue_6
gLugiaPreFightDialogue_6: @ 8105FD8
@ replacing .incbin "baserom.gba", 0x105FD8, 0x4C
.byte 0x00, 0x00, 0x00, 0x0d, 0x12, 0x01, 0x00, 0x00
.4byte gUnknown_8105FE4

.global gUnknown_8105FE4
gUnknown_8105FE4: @ 8105FE4
.string " Cast aside all thoughts!{WAIT_PRESS}\n"
.string "Unleash every bit of your power!\0"
.align 2, 0

.global gLugiaPreFightDialogue_7
gLugiaPreFightDialogue_7: @ 8106024
@ replacing .incbin "baserom.gba", 0x106024, 0x44
.byte 0x06, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.4byte gUnknown_8106030

.global gUnknown_8106030
gUnknown_8106030: @ 8106030
.string "{CENTER_ALIGN}With your life at stake...{WAIT_PRESS}\n"
.string "{CENTER_ALIGN}Bring it on!{WAIT_PRESS}\n"
.string "{CENTER_ALIGN} {WAIT_PRESS}"
.string "  \0"
.align 2, 0

.global gLugiaPreFightDialogue_8
gLugiaPreFightDialogue_8: @ 8106068
@ replacing .incbin "baserom.gba", 0x106068, 0xC
.byte 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.4byte gUnknown_81043E8
@ Kyogre Fight Dialogue

.global gKyogrePreFightDialogue_1
gKyogrePreFightDialogue_1: @ 8106074
@ replacing .incbin "baserom.gba", 0x106074, 0x48
.byte 0x05, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.4byte gUnknown_8106080

.global gUnknown_8106080
gUnknown_8106080: @ 8106080
.string "Gwoooooooooooh..................\n"
.string "                         \0"
.align 2, 0

.global gKyogrePreFightDialogue_2
gKyogrePreFightDialogue_2: @ 81060BC
@ replacing .incbin "baserom.gba", 0x1060BC, 0x48
.byte 0x00, 0x00, 0x00, 0x00, 0xab, 0x01, 0x00, 0x00
.4byte gUnknown_81060C8

.global gUnknown_81060C8
gUnknown_81060C8: @ 81060C8
.string " ...My power...{WAIT_PRESS}\n"
.string "is bursting...{EXTRA_MSG}"
.string " My infinite...{WAIT_PRESS}\n"
.string "power!\0"
.align 2, 0

.global gKyogrePreFightDialogue_3
gKyogrePreFightDialogue_3: @ 8106104
@ replacing .incbin "baserom.gba", 0x106104, 0x3C
.byte 0x05, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.4byte gUnknown_8106110

.global gUnknown_8106110
gUnknown_8106110: @ 8106110
.string "Gwwwwwoooooooooooh!\n"
.string "                         \0"
.align 2, 0

.global gKyogrePreFightDialogue_4
gKyogrePreFightDialogue_4: @ 8106140
@ replacing .incbin "baserom.gba", 0x106140, 0xD4
.byte 0x00, 0x00, 0x00, 0x00, 0xab, 0x01, 0x00, 0x00
.4byte gUnknown_810614C

.global gUnknown_810614C
gUnknown_810614C: @ 810614C
.string " My duels against {ARG_POKEMON_3} left\n"
.string "us both exhausted...{WAIT_PRESS}\n"
.string "I took to a long and deep sleep...{EXTRA_MSG}"
.string " All the time, I waited.\n"
.string "Waited for my power to recover.{EXTRA_MSG}"
.string " And now!{WAIT_PRESS}\n"
.string "I am on the verge of regaining my power!\0"
.align 2, 0

.global gKyogrePreFightDialogue_5
gKyogrePreFightDialogue_5: @ 8106214
@ replacing .incbin "baserom.gba", 0x106214, 0x30
.byte 0x02, 0x00, 0x00, 0x0d, 0x9a, 0x01, 0x00, 0x00
.4byte gUnknown_8106220

.global gUnknown_8106220
gUnknown_8106220: @ 8106220
.string " I am {ARG_POKEMON_2}!{WAIT_PRESS}\n"
.string "The lord of the sea!\0"
.align 2, 0

.global gKyogrePreFightDialogue_6
gKyogrePreFightDialogue_6: @ 8106244
@ replacing .incbin "baserom.gba", 0x106244, 0x38
.byte 0x00, 0x00, 0x00, 0x0d, 0x9a, 0x01, 0x00, 0x00
.4byte gUnknown_8106250

.global gUnknown_8106250
gUnknown_8106250: @ 8106250
.string " Witness the destructive\n"
.string "force of my waves!\0"
.align 2, 0

.global gKyogrePreFightDialogue_7
gKyogrePreFightDialogue_7: @ 810627C
@ replacing .incbin "baserom.gba", 0x10627C, 0x2C
.byte 0x00, 0x00, 0x00, 0x0d, 0x9a, 0x01, 0x00, 0x00
.4byte gUnknown_8106288

.global gUnknown_8106288
gUnknown_8106288: @ 8106288
.string " Marvel at my awesome\n"
.string "power!\0"
.align 2, 0

.global gKyogrePreFightDialogue_8
gKyogrePreFightDialogue_8: @ 81062A8
@ replacing .incbin "baserom.gba", 0x1062A8, 0xC
.byte 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.4byte gUnknown_81043E8

.global gDeoxysPreFightDialogue_1
gDeoxysPreFightDialogue_1: @ 81062B4
@ replacing .incbin "baserom.gba", 0x1062B4, 0x34
.byte 0x02, 0x00, 0x00, 0x00, 0xab, 0x01, 0x00, 0x00
.4byte gUnknown_81062C0

.global gUnknown_81062C0
gUnknown_81062C0: @ 81062C0
.string " ............{EXTRA_MSG}"
.string " Where...{WAIT_PRESS}\n"
.string "Where am I?\0"
.align 2, 0

.global gDeoxysPreFightDialogue_2
gDeoxysPreFightDialogue_2: @ 81062E8
@ replacing .incbin "baserom.gba", 0x1062E8, 0x80
.byte 0x02, 0x00, 0x00, 0x0d, 0x9e, 0x01, 0x00, 0x00
.4byte gUnknown_81062F4

.global gUnknown_81062F4
gUnknown_81062F4: @ 81062F4
.string " There was a sudden explosion...{WAIT_PRESS}\n"
.string "And I awakened to this...{EXTRA_MSG}"
.string " What is this place?{EXTRA_MSG}"
.string " I am {ARG_POKEMON_2}.{WAIT_PRESS}\n"
.string "I came from space.\0"
.align 2, 0

.global gDeoxysPreFightDialogue_3
gDeoxysPreFightDialogue_3: @ 8106368
@ replacing .incbin "baserom.gba", 0x106368, 0x28
.byte 0x00, 0x00, 0x00, 0x0d, 0x9e, 0x01, 0x00, 0x00
.4byte gUnknown_8106374

.global gUnknown_8106374
gUnknown_8106374: @ 8106374
.string " If you know, tell me.\0"
.align 2, 0

.global gDeoxysPreFightDialogue_4
gDeoxysPreFightDialogue_4: @ 8106390
@ replacing .incbin "baserom.gba", 0x106390, 0x34
.byte 0x00, 0x00, 0x00, 0x0d, 0x9e, 0x01, 0x00, 0x00
.4byte gUnknown_810639C

.global gUnknown_810639C
gUnknown_810639C: @ 810639C
.string " I must know...{WAIT_PRESS}\n"
.string "what happened here!\0"
.align 2, 0

.global gDeoxysPreFightDialogue_5
gDeoxysPreFightDialogue_5: @ 81063C4
.byte 0x04, 0x00, 0x00, 0x00
.byte 0x00, 0x00, 0x00, 0x00
.4byte gUnknown_8103E40
@ Dialogue for Purity Forest

.global gCelebiJoinDialogue_1
gCelebiJoinDialogue_1: @ 81063D0
.byte 0x04, 0x00, 0x00, 0x00
.byte 0x00, 0x00, 0x00, 0x00
.4byte gPurityForestSomeoneThereText

.global gPurityForestSomeoneThereText
gPurityForestSomeoneThereText: @ 81063DC
.string "{CENTER_ALIGN}Oh?{WAIT_PRESS}\n"
.string "{CENTER_ALIGN}There's someone there.\0"
.align 2, 0

.global gCelebiJoinDialogue_2
gCelebiJoinDialogue_2: @ 8106400
.byte 0x04, 0x00, 0x00, 0x00
.byte 0x00, 0x00, 0x00, 0x00
.4byte gPurityForestCelebiIntroText

.global gPurityForestCelebiIntroText
gPurityForestCelebiIntroText: @ 810640C
.string "{CENTER_ALIGN}It's...{WAIT_PRESS}\n"
.string "{CENTER_ALIGN}The Time Travel Pokémon {ARG_POKEMON_2}!\0"
.align 2, 0

.global gCelebiJoinDialogue_3
gCelebiJoinDialogue_3: @ 810643C
.byte 0x04, 0x00, 0x00, 0x00
.byte 0x00, 0x00, 0x00, 0x00
.4byte gPurityForestCelebiWantsToJoinText

.global gPurityForestCelebiWantsToJoinText
gPurityForestCelebiWantsToJoinText: @ 8106448
.string "{CENTER_ALIGN}{ARG_POKEMON_2} wants to join the team.\0"
.align 2, 0

.global gCelebiJoinDialogue_4
gCelebiJoinDialogue_4: @ 8106468
.byte 0x04, 0x00, 0x00, 0x00
.byte 0x00, 0x00, 0x00, 0x00
.4byte gPurityForestCelebiJoinedText

.global gPurityForestCelebiJoinedText
gPurityForestCelebiJoinedText: @ 8106474
.string "{CENTER_ALIGN}{ARG_POKEMON_2} joined the team! \0"
.align 2, 0

.global gCelebiJoinDialogue_5
gCelebiJoinDialogue_5: @ 810648C
.byte 0x04, 0x00, 0x00, 0x00
.byte 0x00, 0x00, 0x00, 0x00
.4byte gPurityForestCelebiVeryHappyText

.global gPurityForestCelebiVeryHappyText
gPurityForestCelebiVeryHappyText: @ 8106498
.string "{CENTER_ALIGN}{ARG_POKEMON_3} appears to\n"
.string "{CENTER_ALIGN}be very happy!\0"
.align 2, 0

.global gCelebiJoinDialogue_6
gCelebiJoinDialogue_6: @ 81064BC
.byte 0x04, 0x00, 0x00, 0x00
.byte 0x00, 0x00, 0x00, 0x00
.4byte gPurityForestCelebiDelightedToJoinText

.global gPurityForestCelebiDelightedToJoinText
gPurityForestCelebiDelightedToJoinText: @ 81064C8
.string "{CENTER_ALIGN}It's delighted to have\n"
.string "{CENTER_ALIGN}joined the rescue team!\0"
.align 2, 0

.global gCelebiJoinDialogue_7
gCelebiJoinDialogue_7: @ 8106500
.byte 0x04, 0x00, 0x00, 0x00
.byte 0x00, 0x00, 0x00, 0x00
.4byte gPurityForestTurnedDownOfferText

.global gPurityForestTurnedDownOfferText
gPurityForestTurnedDownOfferText: @ 810650C
.string "{CENTER_ALIGN}{ARG_POKEMON_0} turned down\n"
.string "{CENTER_ALIGN}the offer to join.\0"
.align 2, 0

.global gCelebiJoinDialogue_8
gCelebiJoinDialogue_8: @ 8106534
.byte 0x04, 0x00, 0x00, 0x00
.byte 0x00, 0x00, 0x00, 0x00
.4byte gPurityForestCelebiDisappointedText

.global gPurityForestCelebiDisappointedText
gPurityForestCelebiDisappointedText: @ 8106540
.string "{CENTER_ALIGN}Celebi is very disappointed.\0"
.align 2, 0

.global gCelebiJoinDialogue_9
gCelebiJoinDialogue_9: @ 8106560
.byte 0x04, 0x00, 0x00, 0x00
.byte 0x00, 0x00, 0x00, 0x00
.4byte gPurityForestCelebiLeftDejectedlyText

.global gPurityForestCelebiLeftDejectedlyText
gPurityForestCelebiLeftDejectedlyText: @ 810656C
.string "{CENTER_ALIGN}{ARG_POKEMON_2} left\n"
.string "{CENTER_ALIGN}dejectedly...\0"
.align 2, 0

.global gPurityForestAllowCelebiToJoinText
gPurityForestAllowCelebiToJoinText: @ 8106588
.string "{CENTER_ALIGN}Allow {ARG_POKEMON_2}\n"
.string "{CENTER_ALIGN}to join the team?\0"
.align 2, 0

.global gPtrPurityForestAllowCelebiToJoinText
gPtrPurityForestAllowCelebiToJoinText: @ 81065A8
.4byte gPurityForestAllowCelebiToJoinText

.global gPurityForestAllowCelebiToJoinPrompt
gPurityForestAllowCelebiToJoinPrompt: @ 81065AC
.4byte gPurityForestAllowCelebiToJoinYesText
.4byte 0x00000001
.4byte gPurityForestAllowCelebiToJoinNoText
.4byte 0x00000002
.4byte 0x00000000
.4byte 0xFFFFFFFF

.global gPurityForestAllowCelebiToJoinNoText
gPurityForestAllowCelebiToJoinNoText: @ 81065C4
.string "No.\0"
.align 2, 0

.global gPurityForestAllowCelebiToJoinYesText
gPurityForestAllowCelebiToJoinYesText: @ 81065C8
.string "Yes.\0"
.align 2, 0

.global gPurityForestRefuseCelebiConfirmText
gPurityForestRefuseCelebiConfirmText: @ 81065D0
.string "{CENTER_ALIGN}Are you sure?{WAIT_PRESS}\n"
.string "{CENTER_ALIGN}You're sure you won't accept it?\0"
.align 2, 0

.global gPtrPurityForestRefuseCelebiConfirmText
gPtrPurityForestRefuseCelebiConfirmText: @ 810660C
.4byte gPurityForestRefuseCelebiConfirmText

.global gPurityForestRefuseCelebiConfirmPrompt
gPurityForestRefuseCelebiConfirmPrompt: @ 8106610
.4byte gPurityForestRefuseCelebiReconsiderText
.4byte 0x00000001
.4byte gPurityForestRefuseCelebiRefuseText
.4byte 0x00000002
.4byte 0x00000000
.4byte 0xFFFFFFFF

.global gPurityForestRefuseCelebiRefuseText
gPurityForestRefuseCelebiRefuseText: @ 8106628
.string "Refuse.\0"
.align 2, 0

.global gPurityForestRefuseCelebiReconsiderText
gPurityForestRefuseCelebiReconsiderText: @ 8106630
.string "Reconsider.\0"
.align 2, 0

.global gCelebiJoinDialogue_10
gCelebiJoinDialogue_10: @ 810663C
@ replacing .incbin "baserom.gba", 0x10663C, 0x20
.byte 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.4byte gUnknown_8103E40

.global gUnknown_8106648
gUnknown_8106648: @ 8106648
.string "{CENTER_ALIGN}...............\0"
.align 2, 0

.global gUnknown_810665C
gUnknown_810665C: @ 810665C
@ replacing .incbin "baserom.gba", 0x10665C, 0x30
.4byte gUnknown_8106648

.global gUnknown_8106660
gUnknown_8106660: @ 8106660
.string "{CENTER_ALIGN}Someone has intruded\n"
.string "{CENTER_ALIGN}upon the forest...\0"
.align 2, 0

.global gUnknown_810668C
gUnknown_810668C: @ 810668C
@ replacing .incbin "baserom.gba", 0x10668C, 0x48
.4byte gUnknown_8106660

.global gUnknown_8106690
gUnknown_8106690: @ 8106690
.string "{CENTER_ALIGN}The enfeebled flow of icy winds...\n"
.string "{CENTER_ALIGN}Is the intrusion to blame?\0"
.align 2, 0

.global gUnknown_81066D4
gUnknown_81066D4: @ 81066D4
@ replacing .incbin "baserom.gba", 0x1066D4, 0x1C
.4byte gUnknown_8106690

.global gUnknown_81066D8
gUnknown_81066D8: @ 81066D8
.string "{CENTER_ALIGN}It must be stopped.\0"
.align 2, 0

.global gUnknown_81066F0
gUnknown_81066F0: @ 81066F0
@ replacing .incbin "baserom.gba", 0x1066F0, 0x2C
.4byte gUnknown_81066D8

.global gUnknown_81066F4
gUnknown_81066F4: @ 81066F4
.string "{CENTER_ALIGN}For it is to protect the forest...\0"
.align 2, 0

.global gUnknown_810671C
gUnknown_810671C: @ 810671C
@ replacing .incbin "baserom.gba", 0x10671C, 0x4
.4byte gUnknown_81066F4

.global gUnknown_8106720
gUnknown_8106720: @ 8106720
@ replacing .incbin "baserom.gba", 0x106720, 0x58
.byte 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.4byte gUnknown_810672C

.global gUnknown_810672C
gUnknown_810672C: @ 810672C
.string "{CENTER_ALIGN}Defeat the opposing team to win!\n"
.string "{CENTER_ALIGN}Be careful--your opponents are tough!\0"
.align 2, 0

.global gMedichamRescueDialogue_1
gMedichamRescueDialogue_1: @ 8106778
@ replacing .incbin "baserom.gba", 0x106778, 0x44
.byte 0x00, 0x00, 0x04, 0x0d, 0x4d, 0x01, 0x00, 0x00
.4byte gUnknown_8106784

.global gUnknown_8106784
gUnknown_8106784: @ 8106784
.string " Oh, my, my...\n"
.string "I can't seem to find a way out...\0"
.align 2, 0

.global gMedichamRescueDialogue_2
gMedichamRescueDialogue_2: @ 81067BC
@ replacing .incbin "baserom.gba", 0x1067BC, 0x24
.byte 0x00, 0x00, 0x04, 0x0d, 0x4d, 0x01, 0x00, 0x00
.4byte gUnknown_81067C8

.global gUnknown_81067C8
gUnknown_81067C8: @ 81067C8
.string " What am I to do...?\0"
.align 2, 0

.global gMedichamRescueDialogue_3
gMedichamRescueDialogue_3: @ 81067E0
@ replacing .incbin "baserom.gba", 0x1067E0, 0x54
.byte 0x00, 0x00, 0x02, 0x0d, 0x4d, 0x01, 0x00, 0x00
.4byte gUnknown_81067EC

.global gUnknown_81067EC
gUnknown_81067EC: @ 81067EC
.string " Oh!\n"
.string "You?!{EXTRA_MSG}"
.string " ............{WAIT_PRESS}\n"
.string "Perhaps...{EXTRA_MSG}"
.string " You have come to rescue\n"
.string "me?\0"
.align 2, 0

.global gMedichamRescueDialogue_4
gMedichamRescueDialogue_4: @ 8106834
@ replacing .incbin "baserom.gba", 0x106834, 0x58
.byte 0x00, 0x00, 0x01, 0x0d, 0x4d, 0x01, 0x00, 0x00
.4byte gUnknown_8106840

.global gUnknown_8106840
gUnknown_8106840: @ 8106840
.string " Yes, yes!\n"
.string "I am so lucky!\0"
.align 2, 0

.global gUnknown_810685C
gUnknown_810685C: @ 810685C
.byte 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.4byte gUnknown_8106868

.global gUnknown_8106868
gUnknown_8106868: @ 8106868
.string "{CENTER_ALIGN}There appears to be no one here.\0"
.align 2, 0

.global gSmeargleRescueDialogue_1
gSmeargleRescueDialogue_1: @ 810688C
@ replacing .incbin "baserom.gba", 0x10688C, 0x44
.byte 0x00, 0x00, 0x00, 0x0d, 0x04, 0x01, 0x00, 0x00
.4byte gUnknown_8106898

.global gUnknown_8106898
gUnknown_8106898: @ 8106898
.string " Ohhh...\n"
.string "I've lost my bearings...{WAIT_PRESS}\n"
.string "Where is this?\0"
.align 2, 0

.global gSmeargleRescueDialogue_2
gSmeargleRescueDialogue_2: @ 81068D0
@ replacing .incbin "baserom.gba", 0x1068D0, 0x48
.byte 0x00, 0x00, 0x00, 0x0d, 0x04, 0x01, 0x00, 0x00
.4byte gUnknown_81068DC

.global gUnknown_81068DC
gUnknown_81068DC: @ 81068DC
.string " I can't get out...\n"
.string "I'm hungry...{WAIT_PRESS}\n"
.string "I'm in trouble...\0"
.align 2, 0

.global gSmeargleRescueDialogue_3
gSmeargleRescueDialogue_3: @ 8106918
@ replacing .incbin "baserom.gba", 0x106918, 0x1C
.byte 0x00, 0x00, 0x00, 0x0d, 0x04, 0x01, 0x00, 0x00
.4byte gUnknown_8106924

.global gUnknown_8106924
gUnknown_8106924: @ 8106924
.string " Oh!\n"
.string "You are?!\0"
.align 2, 0

.global gSmeargleRescueDialogue_4
gSmeargleRescueDialogue_4: @ 8106934
@ replacing .incbin "baserom.gba", 0x106934, 0x48
.byte 0x00, 0x00, 0x00, 0x0d, 0x04, 0x01, 0x00, 0x00
.4byte gUnknown_8106940

.global gUnknown_8106940
gUnknown_8106940: @ 8106940
.string " Did you maybe come to\n"
.string "rescue me?{WAIT_PRESS}\n"
.string "Am I glad to see you!\0"
.align 2, 0

.global gUnknown_810697C
gUnknown_810697C: @ 810697C
.byte 0x04, 0x00, 0x00, 0x00
.byte 0x00, 0x00, 0x00, 0x00
.4byte gUnknown_8103E40
.string "pksdir0\0"
.align 2,0

.global gUnknown_8106990
gUnknown_8106990: @ 8106990
@ replacing .incbin "baserom.gba", 0x106990, 0x2C
.byte 0x01, 0x00, 0x54, 0x00, 0xf0, 0xff, 0x18, 0x00, 0x18, 0x00, 0x00, 0x00, 0x02, 0x00, 0x54, 0x00
.byte 0x6a, 0x00, 0x18, 0x00, 0x18, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.byte 0x00, 0x00, 0x00, 0x00, 0x70, 0x6b, 0x73, 0x64, 0x69, 0x72, 0x30, 0x00

.global gUnknown_81069BC
gUnknown_81069BC: @ 81069BC
@ replacing .incbin "baserom.gba", 0x1069BC, 0x18
.byte 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00
.byte 0x70, 0x6b, 0x73, 0x64, 0x69, 0x72, 0x30, 0x00

.global gUnknown_81069D4
gUnknown_81069D4: @ 81069D4
@ replacing .incbin "baserom.gba", 0x1069D4, 0x20
.byte 0x01, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00
