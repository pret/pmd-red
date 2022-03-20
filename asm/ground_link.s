	#include "asm/constants/gba_constants.inc"
	#include "asm/macros.inc"

	.syntax unified

	.text

	thumb_func_start sub_80AD8B4
sub_80AD8B4:
	push {r4,lr}
	adds r4, r1, 0
	lsls r0, 16
	ldr r1, _080AD910
	asrs r0, 13
	ldr r1, [r1]
	adds r2, r1, r0
	ldrb r1, [r2, 0x2]
	movs r0, 0x4
	ands r0, r1
	cmp r0, 0
	bne _080AD8E4
	ldrb r0, [r2]
	lsls r3, r0, 11
	str r3, [r4]
	ldrb r1, [r2, 0x2]
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	beq _080AD8E4
	movs r1, 0x80
	lsls r1, 3
	adds r0, r3, r1
	str r0, [r4]
_080AD8E4:
	ldrb r1, [r2, 0x3]
	movs r0, 0x4
	ands r0, r1
	cmp r0, 0
	bne _080AD906
	ldrb r0, [r2, 0x1]
	lsls r3, r0, 11
	str r3, [r4, 0x4]
	ldrb r1, [r2, 0x3]
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	beq _080AD906
	movs r1, 0x80
	lsls r1, 3
	adds r0, r3, r1
	str r0, [r4, 0x4]
_080AD906:
	ldrb r0, [r2, 0x6]
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_080AD910: .4byte gUnknown_203B4B8
	thumb_func_end sub_80AD8B4

	thumb_func_start sub_80AD914
sub_80AD914:
	push {r4,r5,lr}
	adds r4, r1, 0
	adds r5, r2, 0
	lsls r0, 16
	ldr r1, _080AD98C
	asrs r0, 13
	ldr r1, [r1]
	adds r2, r1, r0
	ldr r0, [r3]
	ldr r1, [r3, 0x4]
	str r0, [r4]
	str r1, [r4, 0x4]
	ldrb r1, [r2, 0x2]
	movs r0, 0x4
	ands r0, r1
	cmp r0, 0
	bne _080AD94E
	ldrb r0, [r2]
	lsls r3, r0, 11
	str r3, [r4]
	ldrb r1, [r2, 0x2]
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	beq _080AD94E
	movs r1, 0x80
	lsls r1, 3
	adds r0, r3, r1
	str r0, [r4]
_080AD94E:
	ldrb r1, [r2, 0x3]
	movs r0, 0x4
	ands r0, r1
	cmp r0, 0
	bne _080AD970
	ldrb r0, [r2, 0x1]
	lsls r3, r0, 11
	str r3, [r4, 0x4]
	ldrb r1, [r2, 0x3]
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	beq _080AD970
	movs r1, 0x80
	lsls r1, 3
	adds r0, r3, r1
	str r0, [r4, 0x4]
_080AD970:
	ldrb r1, [r2, 0x4]
	lsls r1, 11
	ldr r0, [r4]
	adds r0, r1
	str r0, [r5]
	ldrb r1, [r2, 0x5]
	lsls r1, 11
	ldr r0, [r4, 0x4]
	adds r0, r1
	str r0, [r5, 0x4]
	ldrb r0, [r2, 0x6]
	pop {r4,r5}
	pop {r1}
	bx r1
	.align 2, 0
_080AD98C: .4byte gUnknown_203B4B8
	thumb_func_end sub_80AD914

        .align 2,0
