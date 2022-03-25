	#include "asm/constants/gba_constants.inc"
	#include "asm/macros.inc"

	.syntax unified

	.text

	thumb_func_start sub_809017C
sub_809017C:
	push {r4-r6,lr}
	sub sp, 0x4
	adds r1, r0, 0
	mov r0, sp
	bl sub_80901D8
	movs r5, 0
	ldr r2, _080901AC
	ldrb r0, [r2]
	cmp r0, 0x3F
	beq _080901C6
	mov r3, sp
	ldrb r6, [r3]
	movs r4, 0
	adds r1, r2, 0
_0809019A:
	ldrb r0, [r1]
	cmp r6, r0
	bne _080901B0
	ldrb r0, [r3, 0x1]
	ldrb r2, [r1, 0x1]
	cmp r0, r2
	bne _080901B0
	movs r0, 0x1
	b _080901C8
	.align 2, 0
_080901AC: .4byte gUnknown_8107828
_080901B0:
	adds r4, 0x4
	adds r1, 0x4
	adds r5, 0x1
	ldr r0, _080901D0
	cmp r5, r0
	bgt _080901C6
	ldr r2, _080901D4
	adds r0, r4, r2
	ldrb r0, [r0]
	cmp r0, 0x3F
	bne _0809019A
_080901C6:
	movs r0, 0
_080901C8:
	add sp, 0x4
	pop {r4-r6}
	pop {r1}
	bx r1
	.align 2, 0
_080901D0: .4byte 0x000003e6
_080901D4: .4byte gUnknown_8107828
	thumb_func_end sub_809017C

	.align 2, 0 @ Don't pad with nop.
