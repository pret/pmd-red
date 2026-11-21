.global gKaoKangaskhan
gKaoKangaskhan:
kao_siro sPortraitsKangaskhan
sKangaskhanNormalPal:
.incbin "graphics/kao/pal/kangaskhan_normal.pmdpal"
sKangaskhanNormalGfx:
.string "AT4PX"
.incbin "baserom.gba", 0x169AB05, 0x2AF
sKangaskhanHappyPal:
.incbin "graphics/kao/pal/kangaskhan_happy.pmdpal"
sKangaskhanHappyGfx:
.string "AT4PX"
.incbin "baserom.gba", 0x169ADF9, 0x2A3
sPortraitsKangaskhan:
kao_portrait sKangaskhanNormalPal, sKangaskhanNormalGfx
kao_portrait sKangaskhanHappyPal, sKangaskhanHappyGfx
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
