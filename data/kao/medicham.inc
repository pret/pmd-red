.global gKaoMedicham
gKaoMedicham:
kao_siro sPortraitsMedicham
sMedichamNormalPal:
.incbin "baserom.gba", 0x16B6000, 0x40
sMedichamNormalGfx:
.string "AT4PX"
.incbin "baserom.gba", 0x16B6045, 0x297
sMedichamHappyPal:
.incbin "baserom.gba", 0x16B62DC, 0x40
sMedichamHappyGfx:
.incbin "baserom.gba", 0x16B631C, 0x2A8
sMedichamPainedPal:
.incbin "baserom.gba", 0x16B65C4, 0x40
sMedichamPainedGfx:
.string "AT4PX"
.incbin "baserom.gba", 0x16B6609, 0x2C3
sMedichamAngryPal:
.incbin "baserom.gba", 0x16B68CC, 0x40
sMedichamAngryGfx:
.incbin "baserom.gba", 0x16B690C, 0x290
sMedichamWorriedPal:
.incbin "baserom.gba", 0x16B6B9C, 0x40
sMedichamWorriedGfx:
.incbin "baserom.gba", 0x16B6BDC, 0x290
sMedichamSadPal:
.incbin "baserom.gba", 0x16B6E6C, 0x40
sMedichamSadGfx:
.incbin "baserom.gba", 0x16B6EAC, 0x28C
sMedichamCryingPal:
.incbin "baserom.gba", 0x16B7138, 0x40
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
