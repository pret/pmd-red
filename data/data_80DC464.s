	.section .rodata

@ wigglytuff_shop
        .align 2,0
.string "pksdir0\0"
        .align 2,0

	.global gUnknown_80DC464
gUnknown_80DC464: @ 80DC464
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x03, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00

	.global gUnknown_80DC47C
gUnknown_80DC47C: @ 80DC47C
        .byte 0x00, 0x00
        .byte 0x00, 0x00
        .byte 0x06, 0x00
        .byte 0x00, 0x00
        .byte 0x02, 0x00
        .byte 0x02, 0x00
        .byte 0x11, 0x00
        .byte 0x11, 0x00
        .byte 0x11, 0x00
        .byte 0x00, 0x00
        .byte 0x00, 0x00
        .byte 0x00, 0x00

	.global gUnknown_80DC494
gUnknown_80DC494: @ 80DC494
        .string "Friend Areas\0"
        .align 2,0

	.global gUnknown_80DC4A4
gUnknown_80DC4A4: @ 80DC4A4
        .string "{COLOR_1 RED}%s{END_COLOR_TEXT_1}\0"
        .align 2,0

	.global gUnknown_80DC4AC
gUnknown_80DC4AC: @ 80DC4AC
        .string "{COLOR_1 GREEN}%s{END_COLOR_TEXT_1}\0"
        .align 2,0

@ wigglytuff_shop #2
.string "pksdir0\0"
        .align 2,0

	.global gUnknown_80DC4BC
gUnknown_80DC4BC: @ 80DC4BC
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x03, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00

        .global gUnknown_80DC4D4
gUnknown_80DC4D4: @ 80DC4D4
        .byte 0x01, 0x00, 0x12, 0x00

	.global gUnknown_80DC4D8
gUnknown_80DC4D8: @ 80DC4D8
        .byte 0x00, 0x00
        .byte 0x00, 0x00
        .byte 0x06, 0x00
        .byte 0x00, 0x00
        .byte 0x02, 0x00
        .byte 0x02, 0x00
        .byte 0x1a, 0x00
        .byte 0x11, 0x00
        .byte 0x11, 0x00
        .byte 0x00, 0x00

        .4byte gUnknown_80DC4D4

	.global gUnknown_80DC4F0
gUnknown_80DC4F0: @ 80DC4F0
        .string "Inhabitants (Friends: {COLOR_2 CYAN}Light blue{END_COLOR_TEXT_2})\0"
        .align 2,0

	.global gUnknown_80DC518
gUnknown_80DC518: @ 80DC518
        .string "Inhabitants\0"
        .align 2,0

	.global gUnknown_80DC524
gUnknown_80DC524: @ 80DC524
        .string "{COLOR_2 CYAN}%s{END_COLOR_TEXT_2}\0"
        .align 2,0

@ wigglytuff_shop #3
.string "pksdir0\0"
        .align 2,0

	.global gUnknown_80DC534
gUnknown_80DC534: @ 80DC534
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x03, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00

	.global gUnknown_80DC54C
gUnknown_80DC54C: @ 80DC54C
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x03, 0x00, 0x00, 0x00
        .byte 0x15, 0x00, 0x04, 0x00
        .byte 0x06, 0x00, 0x03, 0x00
        .byte 0x03, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00

	.global gUnknown_80DC564
gUnknown_80DC564: @ 80DC564
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x03, 0x00, 0x00, 0x00
        .byte 0x15, 0x00, 0x0e, 0x00
        .byte 0x06, 0x00, 0x03, 0x00
        .byte 0x03, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00

@ code_8023144
.string "pksdir0\0"
        .align 2,0

	.global gUnknown_80DC584
gUnknown_80DC584: @ 80DC584
        .4byte Yes_80DC5A0
        .byte 0x02, 0x00, 0x00, 0x00
        .4byte No_80DC59C
        .byte 0x03, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x01, 0x00, 0x00, 0x00

        .global No_80DC59C
        No_80DC59C:
        .string "No\0"
        .align 2,0
        .global Yes_80DC5A0
        Yes_80DC5A0:
        .string "Yes\0"
        .align 2,0

	.global gUnknown_80DC5A4
gUnknown_80DC5A4: @ 80DC5A4
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x03, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00

	.global gUnknown_80DC5BC
gUnknown_80DC5BC: @ 80DC5BC
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x03, 0x00, 0x00, 0x00
        .byte 0x14, 0x00, 0x04, 0x00
        .byte 0x06, 0x00, 0x03, 0x00
        .byte 0x03, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00

	.global gUnknown_80DC5D4
gUnknown_80DC5D4: @ 80DC5D4
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x03, 0x00, 0x00, 0x00
        .byte 0x14, 0x00, 0x0b, 0x00
        .byte 0x06, 0x00, 0x03, 0x00
        .byte 0x03, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00

	.global gUnknown_80DC5EC
gUnknown_80DC5EC: @ 80DC5EC
        .byte 0x81, 0x48
        .byte 0x81, 0x48
        .byte 0x81, 0x48
        .byte 0x00, 0x00

	.global gUnknown_80DC5F4
gUnknown_80DC5F4: @ 80DC5F4
        .string "It doesn{APOSTROPHE}t appear to be hungry.\0"
        .align 2,0

	.global gUnknown_80DC618
gUnknown_80DC618: @ 80DC618
        .string "{ARG_POKEMON_1} took the Gummi and ate it.\n"
        .string "This Gummi looks like a big favorite!\n"
        .string "{ARG_POKEMON_1}{APOSTROPHE}s IQ went up!\0"
        .align 2,0

	.global gUnknown_80DC674
gUnknown_80DC674: @ 80DC674
        .string "{ARG_POKEMON_1} took the Gummi and ate it.\n"
        .string "This Gummi looks like a favorite!\n"
        .string "{ARG_POKEMON_1}{APOSTROPHE}s IQ went up!\0"
        .align 2,0

	.global gUnknown_80DC6CC
gUnknown_80DC6CC: @ 80DC6CC
        .string "{ARG_POKEMON_1} took the Gummi and ate it.\n"
        .string "It doesn{APOSTROPHE}t seem to dislike this Gummi.\n"
        .string "{ARG_POKEMON_1}{APOSTROPHE}s IQ went up!\0"
        .align 2,0

	.global gUnknown_80DC728
gUnknown_80DC728: @ 80DC728
        .string "{ARG_POKEMON_1} took the Gummi and ate it.\n"
        .string "It appears to be just a little satisfied.\n"
        .string "{ARG_POKEMON_1}{APOSTROPHE}s IQ went up!\0"
        .align 2,0

	.global gUnknown_80DC788
gUnknown_80DC788: @ 80DC788
        .string "{ARG_POKEMON_1}{APOSTROPHE}s IQ helped it learn how to\n"
        .string "use {ARG_MOVE_ITEM_1}!\0"
        .align 2,0

	.global gUnknown_80DC7B4
gUnknown_80DC7B4: @ 80DC7B4
        .string "Yes! {ARG_POKEMON_1} grew explosively!\n"
        .string "Attack{COMMA} Defense{COMMA} and so on rose by 1!\0"
        .align 2,0

	.global gUnknown_80DC7FC
gUnknown_80DC7FC: @ 80DC7FC
        .string "Yes!\n"
        .string "{ARG_POKEMON_1}{APOSTROPHE}s Attack rose by 1!\0"
        .align 2,0

	.global gUnknown_80DC81C
gUnknown_80DC81C: @ 80DC81C
        .string "Yes!\n"
        .string "{ARG_POKEMON_1}{APOSTROPHE}s Special Attack rose by 1!\0"
        .align 2,0

	.global gUnknown_80DC844
gUnknown_80DC844: @ 80DC844
        .string "Yes!\n"
        .string "{ARG_POKEMON_1}{APOSTROPHE}s Defense rose by 1!\0"
        .align 2,0


	.global gUnknown_80DC864
gUnknown_80DC864: @ 80DC864
        .string "Yes!\n"
        .string "{ARG_POKEMON_1}{APOSTROPHE}s Special Defense rose by 1!\0"
        .align 2,0

	.global gUnknown_80DC88C
gUnknown_80DC88C: @ 80DC88C
        .string "You don{APOSTROPHE}t have any Gummis.\0"
        .align 2,0

	.global gUnknown_80DC8AC
gUnknown_80DC8AC: @ 80DC8AC
        .string "You don{APOSTROPHE}t have an item.\0"
        .align 2,0

	.global gUnknown_80DC8C8
gUnknown_80DC8C8: @ 80DC8C8
        .string "The Gummi is gone!\0"
        .align 2,0

	.global gUnknown_80DC8DC
gUnknown_80DC8DC: @ 80DC8DC
        .string "The item is gone!\0"
        .align 2,0

	.global gUnknown_80DC8F0
gUnknown_80DC8F0: @ 80DC8F0
        .string "Give\0"
        .align 2,0

	.global gUnknown_80DC8F8
gUnknown_80DC8F8: @ 80DC8F8
        .string "Use\0"
        .align 2,0

@ code_8023144 #2
.string "pksdir0\0"
        .align 2,0

	.global gUnknown_80DC904
gUnknown_80DC904: @ 80DC904
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x03, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00

	.global gUnknown_80DC91C
gUnknown_80DC91C: @ 80DC91C
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x06, 0x00, 0x00, 0x00
        .byte 0x02, 0x00, 0x02, 0x00
        .byte 0x0f, 0x00, 0x0e, 0x00
        .byte 0x0e, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00

	.global gUnknown_80DC934
gUnknown_80DC934: @ 80DC934
        .string "Pokémon\0"
        .align 2,0

	.global gUnknown_80DC93C
gUnknown_80DC93C: @ 80DC93C
        .string "{COLOR_2}%c%s{END_COLOR_TEXT_2}\0"
        .align 2,0

@ code_801EE10_1
.string "pksdir0\0"
        .align 2,0

	.global gUnknown_80DC950
gUnknown_80DC950: @ 80DC950
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x03, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00

	.global gUnknown_80DC968
gUnknown_80DC968: @ 80DC968
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x06, 0x00, 0x00, 0x00
        .byte 0x02, 0x00, 0x02, 0x00
        .byte 0x0f, 0x00, 0x0e, 0x00
        .byte 0x0e, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00

	.global gUnknown_80DC980
gUnknown_80DC980: @ 80DC980
        .string "Friends\0"

	.global gUnknown_80DC988
gUnknown_80DC988: @ 80DC988
        .string "Pokémon Friends\0"

	.global gUnknown_80DC998
gUnknown_80DC998: @ 80DC998
        .string "{COLOR_2}%c%s{END_COLOR_TEXT_2}\0"
        .align 2,0

	.global gUnknown_80DC9A4
gUnknown_80DC9A4: @ 80DC9A4
        .string "%s\0"
        .align 2,0

@ code_801EE10_1 #2
.string "pksdir0\0"
        .align 2,0

	.global gUnknown_80DC9B0
gUnknown_80DC9B0: @ 80DC9B0
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x03, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00

	.global gUnknown_80DC9C8
gUnknown_80DC9C8: @ 80DC9C8
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x06, 0x00, 0x00, 0x00
        .byte 0x02, 0x00, 0x02, 0x00
        .byte 0x12, 0x00, 0x0e, 0x00
        .byte 0x12, 0x00, 0x02, 0x00
        .byte 0x00, 0x00, 0x00, 0x00

@ luminous_cave
.string "pksdir0\0"
        .align 2,0

	.global gUnknown_80DC9E8
gUnknown_80DC9E8: @ 80DC9E8
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x03, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00

	.global gUnknown_80DCA00
gUnknown_80DCA00: @ 80DCA00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x03, 0x00, 0x00, 0x00
        .byte 0x14, 0x00, 0x04, 0x00
        .byte 0x06, 0x00, 0x03, 0x00
        .byte 0x03, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00

	.global gUnknown_80DCA18
gUnknown_80DCA18: @ 80DCA18
        .string "Evolve\0"
        .align 2,0
        .4byte gUnknown_80DCA18

	.global gUnknown_80DCA24
gUnknown_80DCA24: @ 80DCA24
        .string "No\0"
        .align 2,0
        .4byte gUnknown_80DCA24

	.global gUnknown_80DCA2C
gUnknown_80DCA2C: @ 80DCA2C
        .string "Yes\0"
        .align 2,0
        .4byte gUnknown_80DCA2C