.global gKaoWhiscash
gKaoWhiscash:
kao_siro sPortraitsWhiscash
sWhiscashNormalPal:
.incbin "baserom.gba", 0x16B838C, 0x40
sWhiscashNormalGfx:
.incbin "baserom.gba", 0x16B83CC, 0x27C
sWhiscashHappyPal:
.incbin "baserom.gba", 0x16B8648, 0x40
sWhiscashHappyGfx:
.string "AT4PX"
.incbin "baserom.gba", 0x16B868D, 0x25B
sPortraitsWhiscash:
kao_portrait sWhiscashNormalPal, sWhiscashNormalGfx
kao_portrait sWhiscashHappyPal, sWhiscashHappyGfx
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
