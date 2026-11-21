.global gKaoWhiscash
gKaoWhiscash:
kao_siro sPortraitsWhiscash
sWhiscashNormalPal:
.incbin "graphics/kao/pal/whiscash_normal.pmdpal"
sWhiscashNormalGfx:
.incbin "baserom.gba", 0x16B83CC, 0x27C
sWhiscashHappyPal:
.incbin "graphics/kao/pal/whiscash_happy.pmdpal"
sWhiscashHappyGfx:
.string "AT4PX"
.incbin "baserom.gba", 0x16B868D, 0x25B
sPortraitsWhiscash:
kao_portrait sWhiscashNormalPal, sWhiscashNormalGfx
kao_portrait sWhiscashHappyPal, sWhiscashHappyGfx
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
