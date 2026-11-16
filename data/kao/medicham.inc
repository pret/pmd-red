.global gKaoMedicham
gKaoMedicham:
kao_siro sPortraitsMedicham
sMedichamNormalPal:
.incbin "graphics/kao/pal/medicham_normal.pmdpal"
sMedichamNormalGfx:
.string "AT4PX"
.incbin "baserom.gba", 0x16B6045, 0x297
sMedichamHappyPal:
.incbin "graphics/kao/pal/medicham_happy.pmdpal"
sMedichamHappyGfx:
.incbin "baserom.gba", 0x16B631C, 0x2A8
sMedichamPainedPal:
.incbin "graphics/kao/pal/medicham_pained.pmdpal"
sMedichamPainedGfx:
.string "AT4PX"
.incbin "baserom.gba", 0x16B6609, 0x2C3
sMedichamAngryPal:
.incbin "graphics/kao/pal/medicham_angry.pmdpal"
sMedichamAngryGfx:
.incbin "baserom.gba", 0x16B690C, 0x290
sMedichamWorriedPal:
.incbin "graphics/kao/pal/medicham_worried.pmdpal"
sMedichamWorriedGfx:
.incbin "baserom.gba", 0x16B6BDC, 0x290
sMedichamSadPal:
.incbin "graphics/kao/pal/medicham_sad.pmdpal"
sMedichamSadGfx:
.incbin "baserom.gba", 0x16B6EAC, 0x28C
sMedichamCryingPal:
.incbin "graphics/kao/pal/medicham_crying.pmdpal"
sMedichamCryingGfx:
.incbin "baserom.gba", 0x16B7178, 0x284
sPortraitsMedicham:
kao_portrait sMedichamNormalPal, sMedichamNormalGfx
kao_portrait sMedichamHappyPal, sMedichamHappyGfx
kao_portrait sMedichamPainedPal, sMedichamPainedGfx
kao_portrait sMedichamAngryPal, sMedichamAngryGfx
kao_portrait sMedichamWorriedPal, sMedichamWorriedGfx
kao_portrait sMedichamSadPal, sMedichamSadGfx
kao_portrait sMedichamCryingPal, sMedichamCryingGfx
kao_portrait 0, 0
kao_portrait 0, 0
kao_portrait 0, 0
kao_portrait 0, 0
kao_portrait 0, 0
kao_portrait 0, 0
