.global gKaoEkans
gKaoEkans:
kao_siro sPortraitsEkans
sEkansNormalPal:
.incbin "graphics/kao/pal/ekans_normal.pmdpal"
sEkansNormalGfx:
.string "AT4PX"
.incbin "baserom.gba", 0x1689B1D, 0x23B
sEkansSurprisedPal:
.incbin "graphics/kao/pal/ekans_surprised.pmdpal"
sEkansSurprisedGfx:
.string "AT4PX"
.incbin "baserom.gba", 0x1689D9D, 0x2A3
sEkansHappyPal:
.incbin "graphics/kao/pal/ekans_happy.pmdpal"
sEkansHappyGfx:
.string "AT4PX"
.incbin "baserom.gba", 0x168A085, 0x24F
sPortraitsEkans:
kao_portrait sEkansNormalPal, sEkansNormalGfx
kao_portrait sEkansSurprisedPal, sEkansSurprisedGfx
kao_portrait sEkansHappyPal, sEkansHappyGfx
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
