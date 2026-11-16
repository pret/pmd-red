.global gKaoWobbuffet
gKaoWobbuffet:
kao_siro sPortraitsWobbuffet
sWobbuffetNormalPal:
.incbin "graphics/kao/pal/wobbuffet_normal.pmdpal"
sWobbuffetNormalGfx:
.string "AT4PX"
.incbin "baserom.gba", 0x16A5FE5, 0x223
sWobbuffetHappyPal:
.incbin "graphics/kao/pal/wobbuffet_happy.pmdpal"
sWobbuffetHappyGfx:
.string "AT4PX"
.incbin "baserom.gba", 0x16A624D, 0x2A3
sPortraitsWobbuffet:
kao_portrait sWobbuffetNormalPal, sWobbuffetNormalGfx
kao_portrait sWobbuffetHappyPal, sWobbuffetHappyGfx
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
