        .global gUnknown_80EBA18
gUnknown_80EBA18: @ 80EBA18
	.incbin "baserom.gba", 0xEBA18, 0x6C0C

	.global gPersonalityQuestionPointerTable
gPersonalityQuestionPointerTable: @ 80F2624
	.incbin "baserom.gba", 0xF2624, 0xE0

	.global gUnknown_80F2704
gUnknown_80F2704: @ 80F2704
	.incbin "baserom.gba", 0xF2704, 0x38

	.global gUnknown_80F273C
gUnknown_80F273C: @ 80F273C
	.asciz "Are you a boy or a girl?"
        .align 2,0
        .byte 0x3C, 0x27, 0x0F, 0x08 @ Script to display small box?

	.global gUnknown_80F275C
gUnknown_80F275C: @ 80F275C
	.incbin "baserom.gba", 0xF275C, 0x32

	.global gStarters
gStarters: @ 80F278E
        .byte 0x04, 0x00 @ Charmander (Hardy M)
        .byte 0x19, 0x00 @ Pikachu (Hardy F)
        .byte 0x01, 0x00 @ Bulbasaur (Docile M)
        .byte 0x98, 0x00 @ Chikorita (Docile F)
        .byte 0x42, 0x00 @ Machop (Brave M)
        .byte 0x04, 0x00 @ Charmander (Brave F)
        .byte 0x07, 0x00 @ Squirtle (Jolly M)
        .byte 0x9E, 0x00 @ Totodile (Jolly F)
        .byte 0x19, 0x00 @ Pikachu (Impish M)
        .byte 0x68, 0x00 @ Cubone (Impish F)
        .byte 0x9E, 0x00 @ Totodile (Naive M)
        .byte 0x85, 0x00 @ Eevee (Naive F)
        .byte 0x9B, 0x00 @ Cyndaquil (Timid M)
        .byte 0x1B, 0x01 @ Mudkip (Timid F)
        .byte 0x18, 0x01 @ Torchic (Hasty M)
        .byte 0x45, 0x01 @ Skitty (Hasty F)
        .byte 0x15, 0x01 @ Treecko (Sassy M)
        .byte 0x18, 0x01 @ Torchic (Sassy F)
        .byte 0x1B, 0x01 @ Mudkip (Calm M)
        .byte 0x01, 0x00 @ Bulbasaur (Calm F)
        .byte 0x36, 0x00 @ Psyduck (Relaxed M)
        .byte 0x07, 0x00 @ Squirtle (Relaxed F)
        .byte 0x68, 0x00 @ Cubone (Lonely M)
        .byte 0x36, 0x00 @ Psyduck (Lonely F)
        .byte 0x34, 0x00 @ Meowth (Quirky M)
        .byte 0x15, 0x01 @ Treecko (Quirky F)
        .byte 0x00, 0x00 @ End of table

	.global gUnknown_80F27C4
gUnknown_80F27C4: @ 80F27C4
        .string "\n"
        .string "#+The Pokémon $m0!"
        .byte 0
        .byte 0xC4, 0x27, 0x0F, 0x08 @ Script command to display pokepic of buffer

	.global gUnknown_80F27DC
gUnknown_80F27DC: @ 80F27DC
        .string "#+This is the final step.#W\n"
        .string "#+Who would you like to have as a partner?#P" @ #P -> scroll down
        .string "#+Choose the Pokémon you want\n"
        .asciz "#+as your partner from this group."
        .align 2,0
        .byte 0xDC, 0x27, 0x0F, 0x08 @ Script command to display pokepic of hovered?

	.global gUnknown_80F286C
gUnknown_80F286C: @ 80F286C
	.incbin "baserom.gba", 0xF286C, 0x2C

	.global gUnknown_80F2898
gUnknown_80F2898: @ 80F2898
	.incbin "baserom.gba", 0xF2898, 0x5C

	.global gPersonalityTypeDescriptionTable
gPersonalityTypeDescriptionTable: @ 80F28F4
	.incbin "baserom.gba", 0xF28F4, 0x1950

	.global gUnknown_80F4244
gUnknown_80F4244: @ 80F4244
	.incbin "baserom.gba", 0xF4244, 0x20

	.global gPartners
gPartners: @ 80F4264
        .byte 0x04, 0x00 @ Charmander
        .byte 0x01, 0x00 @ Bulbasaur
        .byte 0x07, 0x00 @ Squirtle
        .byte 0x19, 0x00 @ Pikachu
        .byte 0x98, 0x00 @ Chikorita
        .byte 0x9E, 0x00 @ Totodile
        .byte 0x9B, 0x00 @ Cyndaquil
        .byte 0x18, 0x01 @ Torchic
        .byte 0x15, 0x01 @ Treecko
        .byte 0x1B, 0x01 @ Mudkip
