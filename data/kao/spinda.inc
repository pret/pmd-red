.global gKaoSpinda
gKaoSpinda:
kao_siro sPortraitsSpinda
sSpindaNormalPal:
.incbin "baserom.gba", 0x16B7744, 0x40
sSpindaNormalGfx:
.string "AT4PX"
.incbin "baserom.gba", 0x16B7789, 0x2D3
sSpindaSadPal:
.incbin "baserom.gba", 0x16B7A5C, 0x40
sSpindaSadGfx:
.incbin "baserom.gba", 0x16B7A9C, 0x288
sSpindaNormalFlipPal:
.incbin "baserom.gba", 0x16B7D24, 0x40
sSpindaNormalFlipGfx:
.string "AT4PX"
.incbin "baserom.gba", 0x16B7D69, 0x2DB
sSpindaSadFlipPal:
.incbin "baserom.gba", 0x16B8044, 0x40
sSpindaSadFlipGfx:
.string "AT4PX"
.incbin "baserom.gba", 0x16B8089, 0x28B
sPortraitsSpinda:
kao_portrait sSpindaNormalPal, sSpindaNormalGfx
kao_portrait sSpindaSadPal, sSpindaSadGfx
kao_portrait sSpindaNormalFlipPal, sSpindaNormalFlipGfx
kao_portrait sSpindaSadFlipPal, sSpindaSadFlipGfx
kao_portrait 0, 0
kao_portrait 0, 0
kao_portrait 0, 0
kao_portrait 0, 0
kao_portrait 0, 0
kao_portrait 0, 0
kao_portrait 0, 0
kao_portrait 0, 0
kao_portrait 0, 0
