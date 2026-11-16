.global gKaoShiftry
gKaoShiftry:
kao_siro sPortraitsShiftry
sShiftryNormalPal:
.incbin "graphics/kao/pal/shiftry_normal.pmdpal"
sShiftryNormalGfx:
.string "AT4PX"
.incbin "baserom.gba", 0x16B1DA9, 0x2D3
sShiftrySurprisedPal:
.incbin "graphics/kao/pal/shiftry_surprised.pmdpal"
sShiftrySurprisedGfx:
.incbin "baserom.gba", 0x16B20BC, 0x2F4
sShiftryHappyPal:
.incbin "graphics/kao/pal/shiftry_happy.pmdpal"
sShiftryHappyGfx:
.string "AT4PX"
.incbin "baserom.gba", 0x16B23F5, 0x2CB
sShiftryAngryPal:
.incbin "graphics/kao/pal/shiftry_angry.pmdpal"
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
