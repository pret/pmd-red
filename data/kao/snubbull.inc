.global gKaoSnubbull
gKaoSnubbull:
kao_siro sPortraitsSnubbull
sSnubbullNormalPal:
.incbin "graphics/kao/pal/snubbull_normal.pmdpal"
sSnubbullNormalGfx:
.string "AT4PX"
.incbin "baserom.gba", 0x16A65B5, 0x2B7
sSnubbullHappyPal:
.incbin "graphics/kao/pal/snubbull_happy.pmdpal"
sSnubbullHappyGfx:
.incbin "baserom.gba", 0x16A68AC, 0x2F8
sSnubbullPainedPal:
.incbin "graphics/kao/pal/snubbull_pained.pmdpal"
sSnubbullPainedGfx:
.string "AT4PX"
.incbin "baserom.gba", 0x16A6BE9, 0x2B7
sPortraitsSnubbull:
kao_portrait sSnubbullNormalPal, sSnubbullNormalGfx
kao_portrait sSnubbullHappyPal, sSnubbullHappyGfx
kao_portrait sSnubbullPainedPal, sSnubbullPainedGfx
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
