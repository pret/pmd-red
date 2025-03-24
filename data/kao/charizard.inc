.global gKaoCharizard
gKaoCharizard:
kao_siro sPortraitsCharizard
sCharizardNormalPal:
.incbin "baserom.gba", 0x1684940, 0x40
sCharizardNormalGfx:
.string "AT4PX"
.incbin "baserom.gba", 0x1684985, 0x267
sCharizardSurprisedPal:
.incbin "baserom.gba", 0x1684BEC, 0x40
sCharizardSurprisedGfx:
.incbin "baserom.gba", 0x1684C2C, 0x2B4
sCharizardLaughingPal:
.incbin "baserom.gba", 0x1684EE0, 0x40
sCharizardLaughingGfx:
.string "AT4PX"
.incbin "baserom.gba", 0x1684F25, 0x28F
sCharizardPainedPal:
.incbin "baserom.gba", 0x16851B4, 0x40
sCharizardPainedGfx:
.string "AT4PX"
.incbin "baserom.gba", 0x16851F9, 0x2BF
sCharizardSadPal:
.incbin "baserom.gba", 0x16854B8, 0x40
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
