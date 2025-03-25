.global gKaoDiglett
gKaoDiglett:
kao_siro sPortraitsDiglett
sDiglettNormalPal:
.incbin "baserom.gba", 0x168CE18, 0x40
sDiglettNormalGfx:
.string "AT4PX"
.incbin "baserom.gba", 0x168CE5D, 0x1FB
sDiglettSurprisedPal:
.incbin "baserom.gba", 0x168D058, 0x40
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
