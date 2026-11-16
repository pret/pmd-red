.global gKaoAbsol
gKaoAbsol:
kao_siro sPortraitsAbsol
sAbsolNormalPal:
.incbin "graphics/kao/pal/absol_normal.pmdpal"
sAbsolNormalGfx:
.string "AT4PX"
.incbin "baserom.gba", 0x16B96AD, 0x29B
sAbsolHappyPal:
.incbin "graphics/kao/pal/absol_happy.pmdpal"
sAbsolHappyGfx:
.string "AT4PX"
.incbin "baserom.gba", 0x16B998D, 0x287
sPortraitsAbsol:
kao_portrait sAbsolNormalPal, sAbsolNormalGfx
kao_portrait sAbsolHappyPal, sAbsolHappyGfx
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
