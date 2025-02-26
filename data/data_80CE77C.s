    .section .rodata

    .align 2,0

@ code_800F958

	.global gStatusGraphics4bpp
gStatusGraphics4bpp: @ 80CE934
    .incbin "graphics/status/sleepless.4bpp"
    .incbin "graphics/status/burned.4bpp"
    .incbin "graphics/status/poisoned.4bpp"
    .incbin "graphics/status/frozen.4bpp"
    .incbin "graphics/status/confused.4bpp"
    .incbin "graphics/status/whiffer.4bpp"
    .incbin "graphics/status/taunted.4bpp"
    .incbin "graphics/status/lowhp.4bpp"
    .incbin "graphics/status/shield.4bpp"
    .incbin "graphics/status/statdown.4bpp"
    .incbin "graphics/status/sword.4bpp"
    .incbin "graphics/status/blinker.4bpp"
    .incbin "graphics/status/cross_eyed.4bpp"
    .incbin "graphics/status/eyedrops.4bpp"
    .incbin "graphics/status/muzzled.4bpp"
    .incbin "graphics/status/sleep.4bpp"

	.global gStatusSprites
gStatusSprites: @ 80D3474
    @ Status to status image conversion
    @      image, palette
    .4byte 0,  0
    .4byte 1,  0   @ STATUS_SPRITE_SLEEPLESS
    .4byte 2,  0   @ STATUS_SPRITE_BURNED
    .4byte 3,  11  @ STATUS_SPRITE_POISONED
    .4byte 3,  7   @ STATUS_SPRITE_BADLY_POISONED
    .4byte 5,  0   @ STATUS_SPRITE_CONFUSED
    .4byte 6,  0   @ STATUS_SPRITE_COWERING
    .4byte 7,  0   @ STATUS_SPRITE_TAUNTED
    .4byte 8,  0   @ STATUS_SPRITE_ENCORE
    .4byte 9,  0   @ STATUS_SPRITE_SHIELD_BLUE
    .4byte 9,  4   @ STATUS_SPRITE_SHIELD_RED
    .4byte 9,  3   @ STATUS_SPRITE_SHIELD_YELLOW
    .4byte 9,  10  @ STATUS_SPRITE_SHIELD_GREEN
    .4byte 9,  5   @ STATUS_SPRITE_ENDURE
    .4byte 8,  0   @ STATUS_SPRITE_LOWHP
    .4byte 3,  6   @ STATUS_SPRITE_CURSED
    .4byte 8,  3   @ STATUS_SPRITE_SNATCH
    .4byte 11, 0   @ STATUS_SPRITE_SURE_SHOT
    .4byte 6,  10  @ STATUS_SPRITE_WHIFFER
    .4byte 11, 5   @ STATUS_SPRITE_SET_DAMAGE
    .4byte 11, 4   @ STATUS_SPRITE_FOCUS_ENERGY
    .4byte 12, 0   @ STATUS_SPRITE_BLINKER
    .4byte 13, 0   @ STATUS_SPRITE_CROSS_EYED
    .4byte 14, 0   @ STATUS_SPRITE_EYEDROPS
    .4byte 15, 0   @ STATUS_SPRITE_MUZZLED
    .4byte 9,  7   @ STATUS_SPRITE_GRUDGE
    .4byte 14, 4   @ STATUS_SPRITE_EXPOSED
    .4byte 16, 4   @ STATUS_SPRITE_SLEEP
    .4byte 10, 3   @ STATUS_SPRITE_STAT_DOWN
    .4byte 4,  0   @ STATUS_SPRITE_FROZEN

        .global gUnknown_80D3564
gUnknown_80D3564: @ 80D3564
        .byte 0,0,0,0

