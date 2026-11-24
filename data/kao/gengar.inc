.global gKaoGengar
gKaoGengar:
kao_siro sPortraitsGengar
sGengarNormalPal:
.incbin "graphics/kao/pal/gengar_normal.pmdpal"
sGengarNormalGfx:
.string "AT4PX"
.incbin "baserom.gba", 0x1696D8D, 0x2C3
sGengarHappyPal:
.incbin "graphics/kao/pal/gengar_happy.pmdpal"
sGengarHappyGfx:
.string "AT4PX"
.incbin "baserom.gba", 0x1697095, 0x2A3
sGengarAngryPal:
.incbin "graphics/kao/pal/gengar_angry.pmdpal"
sGengarAngryGfx:
.string "AT4PX"
.incbin "baserom.gba", 0x169737D, 0x2BF
sGengarWorriedPal:
.incbin "graphics/kao/pal/gengar_worried.pmdpal"
sGengarWorriedGfx:
.incbin "baserom.gba", 0x169767C, 0x29C
sGengarDejectedPal:
.incbin "graphics/kao/pal/gengar_dejected.pmdpal"
sGengarDejectedGfx:
.incbin "baserom.gba", 0x1697958, 0x2A4
sGengarSadPal:
.incbin "graphics/kao/pal/gengar_sad.pmdpal"
sGengarSadGfx:
.incbin "baserom.gba", 0x1697C3C, 0x2B4
sGengarSurprisedPal:
.incbin "graphics/kao/pal/gengar_surprised.pmdpal"
sGengarSurprisedGfx:
.string "AT4PX"
.incbin "baserom.gba", 0x1697F35, 0x2C7
sPortraitsGengar:
kao_portrait sGengarNormalPal, sGengarNormalGfx
kao_portrait sGengarHappyPal, sGengarHappyGfx
kao_portrait sGengarAngryPal, sGengarAngryGfx
kao_portrait sGengarWorriedPal, sGengarWorriedGfx
kao_portrait sGengarDejectedPal, sGengarDejectedGfx
kao_portrait sGengarSadPal, sGengarSadGfx
kao_portrait sGengarSurprisedPal, sGengarSurprisedGfx
kao_portrait 0, 0
kao_portrait 0, 0
kao_portrait 0, 0
kao_portrait 0, 0
kao_portrait 0, 0
kao_portrait 0, 0
