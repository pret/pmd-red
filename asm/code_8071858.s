	.include "constants/gba_constants.inc"
	.include "asm/macros.inc"

	.syntax unified

	.text

	thumb_func_start HasType
HasType:
	push {lr}
	lsls r1, 24
	lsrs r1, 24
	adds r3, r1, 0
	ldr r0, [r0, 0x70]
	adds r2, r0, 0
	cmp r1, 0
	beq _0807187A
	adds r0, 0x5C
	ldrb r0, [r0]
	cmp r0, r1
	beq _0807187E
	adds r0, r2, 0
	adds r0, 0x5D
	ldrb r0, [r0]
	cmp r0, r3
	beq _0807187E
_0807187A:
	movs r0, 0
	b _08071880
_0807187E:
	movs r0, 0x1
_08071880:
	pop {r1}
	bx r1
	thumb_func_end HasType

	.align 2, 0
