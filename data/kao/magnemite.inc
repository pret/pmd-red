.global gKaoMagnemite
gKaoMagnemite:
kao_siro sPortraitsMagnemite
sMagnemiteNormalPal:
.incbin "graphics/kao/pal/magnemite_normal.pmdpal"
sMagnemiteNormalGfx:
.incbin "baserom.gba", 0x169671C, 0x2B8
sMagnemiteHappyPal:
.incbin "graphics/kao/pal/magnemite_happy.pmdpal"
sMagnemiteHappyGfx:
.string "AT4PX"
.incbin "baserom.gba", 0x1696A19, 0x2B7
sPortraitsMagnemite:
kao_portrait sMagnemiteNormalPal, sMagnemiteNormalGfx
kao_portrait sMagnemiteHappyPal, sMagnemiteHappyGfx
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
