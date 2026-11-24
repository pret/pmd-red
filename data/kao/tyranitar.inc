.global gKaoTyranitar
gKaoTyranitar:
kao_siro sPortraitsTyranitar
sTyranitarNormalPal:
.incbin "graphics/kao/pal/tyranitar_normal.pmdpal"
sTyranitarNormalGfx:
.string "AT4PX"
.incbin "baserom.gba", 0x16A895D, 0x263
sTyranitarSurprisedPal:
.incbin "graphics/kao/pal/tyranitar_surprised.pmdpal"
sTyranitarSurprisedGfx:
.string "AT4PX"
.incbin "baserom.gba", 0x16A8C05, 0x2C7
sPortraitsTyranitar:
kao_portrait sTyranitarNormalPal, sTyranitarNormalGfx
kao_portrait sTyranitarSurprisedPal, sTyranitarSurprisedGfx
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
