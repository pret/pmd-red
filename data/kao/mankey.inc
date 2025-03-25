.global gKaoMankey
gKaoMankey:
kao_siro sPortraitsMankey
sMankeyNormalPal:
.incbin "baserom.gba", 0x169271C, 0x40
sMankeyNormalGfx:
.incbin "baserom.gba", 0x169275C, 0x2CC
sMankeyAngryPal:
.incbin "baserom.gba", 0x1692A28, 0x40
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
