.global gKaoDiglett
gKaoDiglett:
kao_siro sPortraitsDiglett
sDiglettNormalPal:
.incbin "graphics/kao/pal/diglett_normal.pmdpal"
sDiglettNormalGfx:
.string "AT4PX"
.incbin "baserom.gba", 0x168CE5D, 0x1FB
sDiglettSurprisedPal:
.incbin "graphics/kao/pal/diglett_surprised.pmdpal"
sDiglettSurprisedGfx:
.string "AT4PX"
.incbin "baserom.gba", 0x168D09D, 0x1F7
sPortraitsDiglett:
kao_portrait sDiglettNormalPal, sDiglettNormalGfx
kao_portrait sDiglettSurprisedPal, sDiglettSurprisedGfx
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
