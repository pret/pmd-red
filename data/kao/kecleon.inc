.global gKaoKecleon
gKaoKecleon:
kao_siro sPortraitsKecleon
sKecleonNormalPal:
.incbin "graphics/kao/pal/kecleon_normal.pmdpal"
sKecleonNormalGfx:
.string "AT4PX"
.incbin "baserom.gba", 0x16B89A5, 0x2DF
sKecleon1Pal:
.incbin "graphics/kao/pal/kecleon1.pmdpal"
sKecleon1Gfx:
.string "AT4PX"
.incbin "baserom.gba", 0x16B8CC9, 0x2E3
sKecleon2Pal:
.incbin "graphics/kao/pal/kecleon2.pmdpal"
sKecleon2Gfx:
.incbin "baserom.gba", 0x16B8FEC, 0x2DC
sKecleon3Pal:
.incbin "graphics/kao/pal/kecleon3.pmdpal"
sKecleon3Gfx:
.incbin "baserom.gba", 0x16B9308, 0x2E8
sPortraitsKecleon:
kao_portrait sKecleonNormalPal, sKecleonNormalGfx
kao_portrait sKecleon1Pal, sKecleon1Gfx
kao_portrait 0, 0
kao_portrait 0, 0
kao_portrait 0, 0
kao_portrait 0, 0
kao_portrait sKecleon2Pal, sKecleon2Gfx
kao_portrait sKecleon3Pal, sKecleon3Gfx
kao_portrait 0, 0
kao_portrait 0, 0
kao_portrait 0, 0
kao_portrait 0, 0
kao_portrait 0, 0
