.global gKaoMankey
gKaoMankey:
kao_siro sPortraitsMankey
sMankeyNormalPal:
.incbin "graphics/kao/pal/mankey_normal.pmdpal"
sMankeyNormalGfx:
.incbin "baserom.gba", 0x169275C, 0x2CC
sMankeyAngryPal:
.incbin "graphics/kao/pal/mankey_angry.pmdpal"
sMankeyAngryGfx:
.string "AT4PX"
.incbin "baserom.gba", 0x1692A6D, 0x2EB
sPortraitsMankey:
kao_portrait sMankeyNormalPal, sMankeyNormalGfx
kao_portrait sMankeyAngryPal, sMankeyAngryGfx
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
