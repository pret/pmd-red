.global gKaoLombre
gKaoLombre:
kao_siro sPortraitsLombre
sLombreNormalPal:
.incbin "baserom.gba", 0x16B06C4, 0x40
sLombreNormalGfx:
.string "AT4PX"
.incbin "baserom.gba", 0x16B0709, 0x297
sLombreAngryPal:
.incbin "baserom.gba", 0x16B09A0, 0x40
sLombreAngryGfx:
.string "AT4PX"
.incbin "baserom.gba", 0x16B09E5, 0x26B
sLombreOpenMouthPal:
.incbin "baserom.gba", 0x16B0C50, 0x40
sLombreOpenMouthGfx:
.string "AT4PX"
.incbin "baserom.gba", 0x16B0C95, 0x29F
sLombreSadPal:
.incbin "baserom.gba", 0x16B0F34, 0x40
sLombreSadGfx:
.string "AT4PX"
.incbin "baserom.gba", 0x16B0F79, 0x26B
sLombreNormalFlipPal:
.incbin "baserom.gba", 0x16B11E4, 0x40
sLombreNormalFlipGfx:
.incbin "baserom.gba", 0x16B1224, 0x298
sLombreAngryFlipPal:
.incbin "baserom.gba", 0x16B14BC, 0x40
sLombreAngryFlipGfx:
.incbin "baserom.gba", 0x16B14FC, 0x260
sLombreOpenMouthFlipPal:
.incbin "baserom.gba", 0x16B175C, 0x40
sLombreOpenMouthFlipGfx:
.incbin "baserom.gba", 0x16B179C, 0x2A4
sLombreSadFlipPal:
.incbin "baserom.gba", 0x16B1A40, 0x40
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
