.global gKaoLatias
gKaoLatias:
kao_siro sPortraitsLatias
sLatiasNormalPal:
.incbin "baserom.gba", 0x16BA000, 0x40
sLatiasNormalGfx:
.string "AT4PX"
.incbin "baserom.gba", 0x16BA045, 0x24B
sLatiasHappyPal:
.incbin "baserom.gba", 0x16BA290, 0x40
sLatiasHappyGfx:
.string "AT4PX"
.incbin "baserom.gba", 0x16BA2D5, 0x23F
sPortraitsLatias:
kao_portrait sLatiasNormalPal, sLatiasNormalGfx
kao_portrait sLatiasHappyPal, sLatiasHappyGfx
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
