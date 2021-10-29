	.include "constants/gba_constants.inc"
	.include "asm/macros.inc"

	.syntax unified

	.text

	thumb_func_start sub_8071858
sub_8071858:
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
	thumb_func_end sub_8071858

	thumb_func_start sub_8071884
sub_8071884:
	push {lr}
	adds r1, r0, 0
	ldr r0, [r1, 0x70]
	adds r0, 0xE8
	ldrb r0, [r0]
	cmp r0, 0x3
	beq _080718A4
	adds r0, r1, 0
	movs r1, 0x1A
	bl sub_8046CB0
	lsls r0, 24
	cmp r0, 0
	bne _080718A4
	movs r0, 0
	b _080718A6
_080718A4:
	movs r0, 0x1
_080718A6:
	pop {r1}
	bx r1
	thumb_func_end sub_8071884

	.align 2, 0