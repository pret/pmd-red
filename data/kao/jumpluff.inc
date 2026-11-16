.global gKaoJumpluff
gKaoJumpluff:
kao_siro sPortraitsJumpluff
sJumpluffNormalPal:
.incbin "graphics/kao/pal/jumpluff_normal.pmdpal"
sJumpluffNormalGfx:
.string "AT4PX"
.incbin "baserom.gba", 0x16A59DD, 0x283
sJumpluffHappyPal:
.incbin "graphics/kao/pal/jumpluff_happy.pmdpal"
sJumpluffHappyGfx:
.string "AT4PX"
.incbin "baserom.gba", 0x16A5CA5, 0x283
sPortraitsJumpluff:
kao_portrait sJumpluffNormalPal, sJumpluffNormalGfx
kao_portrait sJumpluffHappyPal, sJumpluffHappyGfx
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
