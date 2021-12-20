	#include "asm/constants/gba_constants.inc"
	#include "asm/macros.inc"

	.syntax unified

	.text

	thumb_func_start sub_808411C
sub_808411C:
	push {r4,r5,lr}
	adds r5, r0, 0
	adds r4, r1, 0
	cmp r5, r4
	beq _0808413C
	cmp r5, r4
	blt _08084134
	subs r0, r5, r4
	bl DungeonRandomCapped
	adds r0, r4
	b _0808413C
_08084134:
	subs r0, r4, r5
	bl DungeonRandomCapped
	adds r0, r5
_0808413C:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_808411C

	.align 2, 0