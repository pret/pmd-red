.global gKaoGardevoir
gKaoGardevoir:
kao_siro sPortraitsGardevoir
sGardevoirNormalPal:
.incbin "graphics/kao/pal/gardevoir_normal.pmdpal"
sGardevoirNormalGfx:
.string "AT4PX"
.incbin "baserom.gba", 0x16B2D79, 0x29F
sGardevoirHappyPal:
.incbin "graphics/kao/pal/gardevoir_happy.pmdpal"
sGardevoirHappyGfx:
.string "AT4PX"
.incbin "baserom.gba", 0x16B305D, 0x293
sGardevoirSadPal:
.incbin "graphics/kao/pal/gardevoir_sad.pmdpal"
sGardevoirSadGfx:
.string "AT4PX"
.incbin "baserom.gba", 0x16B3335, 0x27F
sPortraitsGardevoir:
kao_portrait sGardevoirNormalPal, sGardevoirNormalGfx
kao_portrait sGardevoirHappyPal, sGardevoirHappyGfx
kao_portrait sGardevoirSadPal, sGardevoirSadGfx
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
