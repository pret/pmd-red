.global gKaoJirachi
gKaoJirachi:
kao_siro sPortraitsJirachi
sJirachiNormalPal:
.incbin "graphics/kao/pal/jirachi_normal.pmdpal"
sJirachiNormalGfx:
.incbin "baserom.gba", 0x16BB63C, 0x250
sJirachiHappyPal:
.incbin "graphics/kao/pal/jirachi_happy.pmdpal"
sJirachiHappyGfx:
.incbin "baserom.gba", 0x16BB8CC, 0x280
sPortraitsJirachi:
kao_portrait sJirachiNormalPal, sJirachiNormalGfx
kao_portrait sJirachiHappyPal, sJirachiHappyGfx
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
