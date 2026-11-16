.global gKaoAlakazam
gKaoAlakazam:
kao_siro sPortraitsAlakazam
sAlakazamNormalPal:
.incbin "graphics/kao/pal/alakazam_normal.pmdpal"
sAlakazamNormalGfx:
.string "AT4PX"
.incbin "baserom.gba", 0x1692E15, 0x2DB
sAlakazamSurprisedPal:
.incbin "graphics/kao/pal/alakazam_surprised.pmdpal"
sAlakazamSurprisedGfx:
.string "AT4PX"
.incbin "baserom.gba", 0x1693135, 0x2F7
sAlakazamHappyPal:
.incbin "graphics/kao/pal/alakazam_happy.pmdpal"
sAlakazamHappyGfx:
.incbin "baserom.gba", 0x169346C, 0x2D8
sPortraitsAlakazam:
kao_portrait sAlakazamNormalPal, sAlakazamNormalGfx
kao_portrait sAlakazamSurprisedPal, sAlakazamSurprisedGfx
kao_portrait sAlakazamHappyPal, sAlakazamHappyGfx
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
