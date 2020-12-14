	.include "constants/gba_constants.inc"
	.include "asm/macros.inc"

	.syntax unified

	.text

	thumb_func_start sub_800B294
sub_800B294:
	push {lr}
	adds r1, r0, 0
	ldrb r0, [r1]
	cmp r0, 0x41
	bne _0800B2CC
	ldrb r0, [r1, 0x1]
	adds r2, r0, 0
	cmp r2, 0x54
	bne _0800B2B2
	ldrb r0, [r1, 0x2]
	cmp r0, 0x34
	bne _0800B2B2
	ldrb r0, [r1, 0x3]
	cmp r0, 0x50
	beq _0800B2C8
_0800B2B2:
	ldrb r0, [r1]
	cmp r0, 0x41
	bne _0800B2CC
	cmp r2, 0x54
	bne _0800B2CC
	ldrb r0, [r1, 0x2]
	cmp r0, 0x33
	bne _0800B2CC
	ldrb r0, [r1, 0x3]
	cmp r0, 0x50
	bne _0800B2CC
_0800B2C8:
	movs r0, 0x1
	b _0800B2CE
_0800B2CC:
	movs r0, 0
_0800B2CE:
	pop {r1}
	bx r1
	thumb_func_end sub_800B294

	thumb_func_start sub_800B2D4
sub_800B2D4:
	push {r4-r6,lr}
	adds r6, r0, 0
	adds r5, r1, 0
	adds r4, r2, 0
	movs r2, 0
	cmp r2, r4
	bge _0800B324
_0800B2E2:
	adds r0, r6, r2
	ldrb r1, [r0]
	adds r0, r5, r2
	ldrb r3, [r0]
	adds r0, r1, 0
	subs r0, 0x41
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x19
	bhi _0800B2FE
	adds r0, r1, 0
	adds r0, 0x20
	lsls r0, 24
	lsrs r1, r0, 24
_0800B2FE:
	adds r0, r3, 0
	subs r0, 0x41
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x19
	bhi _0800B312
	adds r0, r3, 0
	adds r0, 0x20
	lsls r0, 24
	lsrs r3, r0, 24
_0800B312:
	cmp r1, r3
	beq _0800B31A
	movs r0, 0x1
	b _0800B326
_0800B31A:
	cmp r1, 0
	beq _0800B324
	adds r2, 0x1
	cmp r2, r4
	blt _0800B2E2
_0800B324:
	movs r0, 0
_0800B326:
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end sub_800B2D4

	.align 2, 0 @ Don't pad with nop.
