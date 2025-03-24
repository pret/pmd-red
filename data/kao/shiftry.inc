.global gKaoShiftry
gKaoShiftry:
kao_siro sPortraitsShiftry
sShiftryNormalPal:
.incbin "baserom.gba", 0x16B1D64, 0x40
sShiftryNormalGfx:
.string "AT4PX"
.incbin "baserom.gba", 0x16B1DA9, 0x2D3
sShiftrySurprisedPal:
.incbin "baserom.gba", 0x16B207C, 0x40
sShiftrySurprisedGfx:
.incbin "baserom.gba", 0x16B20BC, 0x2F4
sShiftryHappyPal:
.incbin "baserom.gba", 0x16B23B0, 0x40
sShiftryHappyGfx:
.string "AT4PX"
.incbin "baserom.gba", 0x16B23F5, 0x2CB
sShiftryAngryPal:
.incbin "baserom.gba", 0x16B26C0, 0x40
sShiftryAngryGfx:
.string "AT4PX"
.incbin "baserom.gba", 0x16B2705, 0x2DB
sPortraitsShiftry:
kao_portrait sShiftryNormalPal, sShiftryNormalGfx
kao_portrait sShiftrySurprisedPal, sShiftrySurprisedGfx
kao_portrait sShiftryHappyPal, sShiftryHappyGfx
kao_portrait sShiftryAngryPal, sShiftryAngryGfx
kao_portrait 0, 0
kao_portrait 0, 0
kao_portrait 0, 0
kao_portrait 0, 0
kao_portrait 0, 0
kao_portrait 0, 0
kao_portrait 0, 0
kao_portrait 0, 0
kao_portrait 0, 0
