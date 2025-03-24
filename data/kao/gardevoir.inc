.global gKaoGardevoir
gKaoGardevoir:
kao_siro sPortraitsGardevoir
sGardevoirNormalPal:
.incbin "baserom.gba", 0x16B2D34, 0x40
sGardevoirNormalGfx:
.string "AT4PX"
.incbin "baserom.gba", 0x16B2D79, 0x29F
sGardevoirHappyPal:
.incbin "baserom.gba", 0x16B3018, 0x40
sGardevoirHappyGfx:
.string "AT4PX"
.incbin "baserom.gba", 0x16B305D, 0x293
sGardevoirSadPal:
.incbin "baserom.gba", 0x16B32F0, 0x40
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
