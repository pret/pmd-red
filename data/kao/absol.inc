.global gKaoAbsol
gKaoAbsol:
kao_siro sPortraitsAbsol
sAbsolNormalPal:
.incbin "baserom.gba", 0x16B9668, 0x40
sAbsolNormalGfx:
.string "AT4PX"
.incbin "baserom.gba", 0x16B96AD, 0x29B
sAbsolHappyPal:
.incbin "baserom.gba", 0x16B9948, 0x40
sAbsolHappyGfx:
.string "AT4PX"
.incbin "baserom.gba", 0x16B998D, 0x287
sPortraitsAbsol:
kao_portrait sAbsolNormalPal, sAbsolNormalGfx
kao_portrait sAbsolHappyPal, sAbsolHappyGfx
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
