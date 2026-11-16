.global gKaoSpinda
gKaoSpinda:
kao_siro sPortraitsSpinda
sSpindaNormalPal:
.incbin "graphics/kao/pal/spinda_normal.pmdpal"
sSpindaNormalGfx:
.string "AT4PX"
.incbin "baserom.gba", 0x16B7789, 0x2D3
sSpindaSadPal:
.incbin "graphics/kao/pal/spinda_sad.pmdpal"
sSpindaSadGfx:
.incbin "baserom.gba", 0x16B7A9C, 0x288
sSpindaNormalFlipPal:
.incbin "graphics/kao/pal/spinda_normal_flip.pmdpal"
sSpindaNormalFlipGfx:
.string "AT4PX"
.incbin "baserom.gba", 0x16B7D69, 0x2DB
sSpindaSadFlipPal:
.incbin "graphics/kao/pal/spinda_sad_flip.pmdpal"
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
