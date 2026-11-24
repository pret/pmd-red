.global gKaoBlastoise
gKaoBlastoise:
kao_siro sPortraitsBlastoise
sBlastoiseNormalPal:
.incbin "graphics/kao/pal/blastoise_normal.pmdpal"
sBlastoiseNormalGfx:
.string "AT4PX"
.incbin "baserom.gba", 0x1687ECD, 0x2AB
sBlastoiseSurprisedPal:
.incbin "graphics/kao/pal/blastoise_surprised.pmdpal"
sBlastoiseSurprisedGfx:
.string "AT4PX"
.incbin "baserom.gba", 0x16881BD, 0x2A3
sBlastoiseAngryPal:
.incbin "graphics/kao/pal/blastoise_angry.pmdpal"
sBlastoiseAngryGfx:
.string "AT4PX"
.incbin "baserom.gba", 0x16884A5, 0x2B3
sBlastoisePainedPal:
.incbin "graphics/kao/pal/blastoise_pained.pmdpal"
sBlastoisePainedGfx:
.string "AT4PX"
.incbin "baserom.gba", 0x168879D, 0x2A3
sPortraitsBlastoise:
kao_portrait sBlastoiseNormalPal, sBlastoiseNormalGfx
kao_portrait sBlastoiseSurprisedPal, sBlastoiseSurprisedGfx
kao_portrait sBlastoiseAngryPal, sBlastoiseAngryGfx
kao_portrait sBlastoisePainedPal, sBlastoisePainedGfx
kao_portrait 0, 0
kao_portrait 0, 0
kao_portrait 0, 0
kao_portrait 0, 0
kao_portrait 0, 0
kao_portrait 0, 0
kao_portrait 0, 0
kao_portrait 0, 0
kao_portrait 0, 0
