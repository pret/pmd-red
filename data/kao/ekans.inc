.global gKaoEkans
gKaoEkans:
kao_siro sPortraitsEkans
sEkansNormalPal:
.incbin "baserom.gba", 0x1689AD8, 0x40
sEkansNormalGfx:
.string "AT4PX"
.incbin "baserom.gba", 0x1689B1D, 0x23B
sEkansSurprisedPal:
.incbin "baserom.gba", 0x1689D58, 0x40
sEkansSurprisedGfx:
.string "AT4PX"
.incbin "baserom.gba", 0x1689D9D, 0x2A3
sEkansHappyPal:
.incbin "baserom.gba", 0x168A040, 0x40
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
