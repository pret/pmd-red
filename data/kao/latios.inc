.global gKaoLatios
gKaoLatios:
kao_siro sPortraitsLatios
sLatiosNormalPal:
.incbin "graphics/kao/pal/latios_normal.pmdpal"
sLatiosNormalGfx:
.incbin "baserom.gba", 0x16BA5CC, 0x290
sLatiosHappyPal:
.incbin "graphics/kao/pal/latios_happy.pmdpal"
sLatiosHappyGfx:
.incbin "baserom.gba", 0x16BA89C, 0x29C
sPortraitsLatios:
kao_portrait sLatiosNormalPal, sLatiosNormalGfx
kao_portrait sLatiosHappyPal, sLatiosHappyGfx
kao_portrait 0, 0
kao_portrait 0, 0
kao_portrait 0, 0
kao_portrait 0, 0
kao_portrait 0, 0
kao_portrait 0, 0
kao_portrait 0, 0
kao_portrait 0, 0
kao_portrait 0, 0
kao_portrait 0, 0
kao_portrait 0, 0
