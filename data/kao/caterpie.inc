.global gKaoCaterpie
gKaoCaterpie:
kao_siro sPortraitsCaterpie
sCaterpieNormalPal:
.incbin "baserom.gba", 0x1688AB8, 0x40
sCaterpieNormalGfx:
.string "AT4PX"
.incbin "baserom.gba", 0x1688AFD, 0x29B
sCaterpieInspiredPal:
.incbin "graphics/kao/pal/caterpie_inspired.pmdpal"
sCaterpieInspiredGfx:
.string "AT4PX"
.incbin "baserom.gba", 0x1688DDD, 0x2AF
sCaterpieSadPal:
.incbin "graphics/kao/pal/caterpie_sad.pmdpal"
sCaterpieSadGfx:
.incbin "baserom.gba", 0x16890CC, 0x298
sPortraitsCaterpie:
kao_portrait sCaterpieNormalPal, sCaterpieNormalGfx
kao_portrait sCaterpieInspiredPal, sCaterpieInspiredGfx
kao_portrait sCaterpieSadPal, sCaterpieSadGfx
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
