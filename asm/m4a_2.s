	.include "asm/macros.inc"
	.include "constants/gba_constants.inc"
	.include "constants/m4a_constants.inc"

	.syntax unified

	.text

	thumb_func_start CgbModVol
CgbModVol:
	push {r4,lr}
	adds r1, r0, 0
	ldrb r0, [r1, 0x2]
	lsls r2, r0, 24
	lsrs r4, r2, 24
	ldrb r3, [r1, 0x3]
	lsls r0, r3, 24
	lsrs r3, r0, 24
	cmp r4, r3
	bcc _080AFA94
	lsrs r0, r2, 25
	cmp r0, r3
	bcc _080AFAA0
	movs r0, 0xF
	strb r0, [r1, 0x1B]
	b _080AFAAE
_080AFA94:
	lsrs r0, 25
	cmp r0, r4
	bcc _080AFAA0
	movs r0, 0xF0
	strb r0, [r1, 0x1B]
	b _080AFAAE
_080AFAA0:
	movs r0, 0xFF
	strb r0, [r1, 0x1B]
	ldrb r2, [r1, 0x3]
	ldrb r3, [r1, 0x2]
	adds r0, r2, r3
	lsrs r0, 4
	b _080AFABE
_080AFAAE:
	ldrb r2, [r1, 0x3]
	ldrb r3, [r1, 0x2]
	adds r0, r2, r3
	lsrs r0, 4
	strb r0, [r1, 0xA]
	cmp r0, 0xF
	bls _080AFAC0
	movs r0, 0xF
_080AFABE:
	strb r0, [r1, 0xA]
_080AFAC0:
	ldrb r2, [r1, 0x6]
	ldrb r3, [r1, 0xA]
	adds r0, r2, 0
	muls r0, r3
	adds r0, 0xF
	asrs r0, 4
	strb r0, [r1, 0x19]
	ldrb r0, [r1, 0x1C]
	ldrb r2, [r1, 0x1B]
	ands r0, r2
	strb r0, [r1, 0x1B]
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end CgbModVol

	.align 2, 0 @ Don't pad with nop.
