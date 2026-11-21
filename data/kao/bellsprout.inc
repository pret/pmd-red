.global gKaoBellsprout
gKaoBellsprout:
kao_siro sPortraitsBellsprout
sBellsproutNormalPal:
.incbin "graphics/kao/pal/bellsprout_normal.pmdpal"
sBellsproutNormalGfx:
.string "AT4PX"
.incbin "baserom.gba", 0x1695E09, 0x26B
sBellsproutWorriedPal:
.incbin "graphics/kao/pal/bellsprout_worried.pmdpal"
sBellsproutWorriedGfx:
.string "AT4PX"
.incbin "baserom.gba", 0x16960B9, 0x243
sPortraitsBellsprout:
kao_portrait sBellsproutNormalPal, sBellsproutNormalGfx
kao_portrait sBellsproutWorriedPal, sBellsproutWorriedGfx
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
