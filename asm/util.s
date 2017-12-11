	.include "constants/gba_constants.inc"
	.include "asm/macros.inc"

	.syntax unified

	.text

	thumb_func_start ReverseString
ReverseString:
	push {r4,r5,lr}
	adds r3, r0, 0
	subs r4, r1, 0x1
	adds r2, r3, r4
	movs r5, 0
	cmp r5, r4
	bge _08004566
_08004552:
	ldrb r1, [r3]
	ldrb r0, [r2]
	strb r0, [r3]
	adds r3, 0x1
	strb r1, [r2]
	subs r2, 0x1
	adds r5, 0x1
	subs r4, 0x1
	cmp r5, r4
	blt _08004552
_08004566:
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end ReverseString

	thumb_func_start ConvertToDecimal
ConvertToDecimal:
	push {r4-r7,lr}
	adds r4, r1, 0
	cmp r4, 0
	ble _08004578
	movs r7, 0x1
	b _0800457E
_08004578:
	negs r4, r4
	movs r7, 0x1
	negs r7, r7
_0800457E:
	cmp r2, 0
	ble _080045A0
	adds r6, r0, 0
	adds r5, r2, 0
_08004586:
	adds r0, r4, 0
	movs r1, 0xA
	bl __modsi3
	stm r6!, {r0}
	adds r0, r4, 0
	movs r1, 0xA
	bl __divsi3
	adds r4, r0, 0
	subs r5, 0x1
	cmp r5, 0
	bne _08004586
_080045A0:
	adds r0, r7, 0
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end ConvertToDecimal

	thumb_func_start ConvertFromDecimal
ConvertFromDecimal:
	push {r4,r5,lr}
	adds r4, r0, 0
	adds r5, r1, 0
	ldm r4!, {r1}
	movs r3, 0xA
	cmp r2, 0x1
	ble _080045CA
	subs r2, 0x1
_080045B8:
	ldm r4!, {r0}
	muls r0, r3
	adds r1, r0
	subs r2, 0x1
	lsls r0, r3, 2
	adds r0, r3
	lsls r3, r0, 1
	cmp r2, 0
	bne _080045B8
_080045CA:
	adds r0, r1, 0
	cmp r5, 0
	bge _080045D2
	negs r0, r0
_080045D2:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end ConvertFromDecimal

	thumb_func_start ConvertFromBCD
ConvertFromBCD:
	push {r4,lr}
	adds r1, r0, 0
	movs r2, 0x1
	movs r3, 0
	cmp r1, 0
	ble _080045FA
	movs r4, 0xF
_080045E6:
	adds r0, r1, 0
	ands r0, r4
	muls r0, r2
	adds r3, r0
	lsls r0, r2, 2
	adds r0, r2
	lsls r2, r0, 1
	asrs r1, 4
	cmp r1, 0
	bgt _080045E6
_080045FA:
	adds r0, r3, 0
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end ConvertFromBCD

	thumb_func_start ConvertToBCD
ConvertToBCD:
	push {r4-r6,lr}
	adds r4, r0, 0
	movs r5, 0
	movs r6, 0
	cmp r4, 0
	ble _0800462C
_08004610:
	adds r0, r4, 0
	movs r1, 0xA
	bl __modsi3
	lsls r0, r5
	adds r6, r0
	adds r5, 0x4
	adds r0, r4, 0
	movs r1, 0xA
	bl __divsi3
	adds r4, r0, 0
	cmp r4, 0
	bgt _08004610
_0800462C:
	adds r0, r6, 0
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end ConvertToBCD

	.align 2, 0 @ Don't pad with nop.
