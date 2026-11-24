.global gKaoLombre
gKaoLombre:
kao_siro sPortraitsLombre
sLombreNormalPal:
.incbin "graphics/kao/pal/lombre_normal.pmdpal"
sLombreNormalGfx:
.string "AT4PX"
.incbin "baserom.gba", 0x16B0709, 0x297
sLombreAngryPal:
.incbin "graphics/kao/pal/lombre_angry.pmdpal"
sLombreAngryGfx:
.string "AT4PX"
.incbin "baserom.gba", 0x16B09E5, 0x26B
sLombreOpenMouthPal:
.incbin "graphics/kao/pal/lombre_open_mouth.pmdpal"
sLombreOpenMouthGfx:
.string "AT4PX"
.incbin "baserom.gba", 0x16B0C95, 0x29F
sLombreSadPal:
.incbin "graphics/kao/pal/lombre_sad.pmdpal"
sLombreSadGfx:
.string "AT4PX"
.incbin "baserom.gba", 0x16B0F79, 0x26B
sLombreNormalFlipPal:
.incbin "graphics/kao/pal/lombre_normal_flip.pmdpal"
sLombreNormalFlipGfx:
.incbin "baserom.gba", 0x16B1224, 0x298
sLombreAngryFlipPal:
.incbin "graphics/kao/pal/lombre_angry_flip.pmdpal"
sLombreAngryFlipGfx:
.incbin "baserom.gba", 0x16B14FC, 0x260
sLombreOpenMouthFlipPal:
.incbin "graphics/kao/pal/lombre_open_mouth_flip.pmdpal"
sLombreOpenMouthFlipGfx:
.incbin "baserom.gba", 0x16B179C, 0x2A4
sLombreSadFlipPal:
.incbin "graphics/kao/pal/lombre_sad_flip.pmdpal"
sLombreSadFlipGfx:
.string "AT4PX"
.incbin "baserom.gba", 0x16B1A85, 0x267
sPortraitsLombre:
kao_portrait sLombreNormalPal, sLombreNormalGfx
kao_portrait sLombreAngryPal, sLombreAngryGfx
kao_portrait sLombreOpenMouthPal, sLombreOpenMouthGfx
kao_portrait sLombreSadPal, sLombreSadGfx
kao_portrait sLombreNormalFlipPal, sLombreNormalFlipGfx
kao_portrait sLombreAngryFlipPal, sLombreAngryFlipGfx
kao_portrait sLombreOpenMouthFlipPal, sLombreOpenMouthFlipGfx
kao_portrait sLombreSadFlipPal, sLombreSadFlipGfx
kao_portrait 0, 0
kao_portrait 0, 0
kao_portrait 0, 0
kao_portrait 0, 0
kao_portrait 0, 0
