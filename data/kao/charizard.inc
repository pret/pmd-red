.global gKaoCharizard
gKaoCharizard:
kao_siro sPortraitsCharizard
sCharizardNormalPal:
.incbin "graphics/kao/pal/charizard_normal.pmdpal"
sCharizardNormalGfx:
.string "AT4PX"
.incbin "baserom.gba", 0x1684985, 0x267
sCharizardSurprisedPal:
.incbin "graphics/kao/pal/charizard_surprised.pmdpal"
sCharizardSurprisedGfx:
.incbin "baserom.gba", 0x1684C2C, 0x2B4
sCharizardLaughingPal:
.incbin "graphics/kao/pal/charizard_laughing.pmdpal"
sCharizardLaughingGfx:
.string "AT4PX"
.incbin "baserom.gba", 0x1684F25, 0x28F
sCharizardPainedPal:
.incbin "graphics/kao/pal/charizard_pained.pmdpal"
sCharizardPainedGfx:
.string "AT4PX"
.incbin "baserom.gba", 0x16851F9, 0x2BF
sCharizardSadPal:
.incbin "graphics/kao/pal/charizard_sad.pmdpal"
sCharizardSadGfx:
.incbin "baserom.gba", 0x16854F8, 0x288
sPortraitsCharizard:
kao_portrait sCharizardNormalPal, sCharizardNormalGfx
kao_portrait sCharizardSurprisedPal, sCharizardSurprisedGfx
kao_portrait sCharizardLaughingPal, sCharizardLaughingGfx
kao_portrait sCharizardPainedPal, sCharizardPainedGfx
kao_portrait sCharizardSadPal, sCharizardSadGfx
kao_portrait 0, 0
kao_portrait 0, 0
kao_portrait 0, 0
kao_portrait 0, 0
kao_portrait 0, 0
kao_portrait 0, 0
kao_portrait 0, 0
kao_portrait 0, 0
