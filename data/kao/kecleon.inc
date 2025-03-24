.global gKaoKecleon
gKaoKecleon:
kao_siro sPortraitsKecleon
sKecleonNormalPal:
.incbin "baserom.gba", 0x16B8960, 0x40
sKecleonNormalGfx:
.string "AT4PX"
.incbin "baserom.gba", 0x16B89A5, 0x2DF
sKecleon1Pal:
.incbin "baserom.gba", 0x16B8C84, 0x40
sKecleon1Gfx:
.string "AT4PX"
.incbin "baserom.gba", 0x16B8CC9, 0x2E3
gUnknown_96B8FAC:
.incbin "baserom.gba", 0x16B8FAC, 0x40
gUnknown_96B8FEC:
.incbin "baserom.gba", 0x16B8FEC, 0x2DC
gUnknown_96B92C8:
.incbin "baserom.gba", 0x16B92C8, 0x40
gUnknown_96B9308:
.incbin "baserom.gba", 0x16B9308, 0x2E8
sPortraitsKecleon:
kao_portrait sKecleonNormalPal, sKecleonNormalGfx
kao_portrait sKecleon1Pal, sKecleon1Gfx
kao_portrait 0, 0
kao_portrait 0, 0
kao_portrait 0, 0
kao_portrait 0, 0
kao_portrait gUnknown_96B8FAC, gUnknown_96B8FEC
kao_portrait gUnknown_96B92C8, gUnknown_96B9308
kao_portrait 0, 0
kao_portrait 0, 0
kao_portrait 0, 0
kao_portrait 0, 0
kao_portrait 0, 0
