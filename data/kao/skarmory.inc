.global gKaoSkarmory
gKaoSkarmory:
kao_siro sPortraitsSkarmory
sSkarmoryNormalPal:
.incbin "graphics/kao/pal/skarmory_normal.pmdpal"
sSkarmoryNormalGfx:
.string "AT4PX"
.incbin "baserom.gba", 0x16A768D, 0x26B
sSkarmoryPlaceholderPal:
.incbin "graphics/kao/pal/skarmory_placeholder.pmdpal"
sSkarmoryPlaceholderGfx:
.string "AT4PX"
.incbin "baserom.gba", 0x16A793D, 0x127
sPortraitsSkarmory:
kao_portrait sSkarmoryNormalPal, sSkarmoryNormalGfx
kao_portrait sSkarmoryPlaceholderPal, sSkarmoryPlaceholderGfx
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
