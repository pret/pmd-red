	#include "asm/constants/gba_constants.inc"
	#include "asm/macros.inc"

	.syntax unified

	.text

	thumb_func_start sub_800543C
sub_800543C:
	push {r4,r5,lr}
	sub sp, 0x8
	ldr r5, [sp, 0x14]
	ldr r4, [sp, 0x18]
	lsls r4, 24
	lsrs r4, 24
	ldr r1, [r1, 0x4]
	str r5, [sp]
	str r4, [sp, 0x4]
	bl sub_800545C
	add sp, 0x8
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_800543C

	thumb_func_start sub_800545C
sub_800545C:
	push {r4-r7,lr}
	adds r4, r0, 0
	adds r6, r1, 0
	adds r7, r2, 0
	adds r5, r3, 0
	ldr r0, [sp, 0x18]
	lsls r0, 24
	movs r2, 0
	movs r3, 0x80
	lsls r3, 8
	strh r3, [r4]
	cmp r0, 0
	beq _08005482
	movs r0, 0x80
	lsls r0, 5
	adds r1, r0, 0
	adds r0, r3, 0
	orrs r0, r1
	strh r0, [r4]
_08005482:
	strh r2, [r4, 0x2]
	ldr r0, [sp, 0x14]
	strh r0, [r4, 0x4]
	strh r2, [r4, 0xC]
	strh r2, [r4, 0xE]
	strh r5, [r4, 0x1C]
	ldr r0, _080054B8
	strh r0, [r4, 0x20]
	movs r0, 0x1
	negs r0, r0
	strh r0, [r4, 0x22]
	str r2, [r4, 0x14]
	str r2, [r4, 0x18]
	strh r2, [r4, 0x6]
	ldr r1, [r6, 0x4]
	lsls r0, r7, 2
	adds r0, r1
	ldr r0, [r0]
	ldr r0, [r0]
	str r0, [r4, 0x28]
	str r0, [r4, 0x2C]
	ldr r0, [r6]
	str r0, [r4, 0x34]
	str r2, [r4, 0x30]
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_080054B8: .4byte 0x0000ffff
	thumb_func_end sub_800545C

	thumb_func_start sub_80054BC
sub_80054BC:
	push {r4,lr}
	adds r4, r0, 0
	ldrh r1, [r4]
	movs r0, 0x80
	lsls r0, 6
	ands r0, r1
	cmp r0, 0
	beq _080054D0
	movs r0, 0
	b _080054D2
_080054D0:
	lsrs r0, r1, 15
_080054D2:
	cmp r0, 0
	beq _08005586
	movs r1, 0x20
	ldrsh r0, [r4, r1]
	ldrh r3, [r4]
	cmp r0, 0
	blt _08005524
	movs r0, 0x80
	lsls r0, 7
	ands r0, r3
	cmp r0, 0
	bne _08005586
	ldrh r2, [r4, 0x6]
	movs r0, 0x6
	ldrsh r1, [r4, r0]
	ldr r0, _0800550C
	cmp r1, r0
	bgt _080054FA
	adds r0, r2, 0x1
	strh r0, [r4, 0x6]
_080054FA:
	ldrh r1, [r4, 0x4]
	movs r2, 0x4
	ldrsh r0, [r4, r2]
	cmp r0, 0
	beq _08005510
	subs r0, r1, 0x1
	strh r0, [r4, 0x4]
	b _08005586
	.align 2, 0
_0800550C: .4byte 0x0000752f
_08005510:
	ldrh r1, [r4, 0x2]
	movs r2, 0x2
	ldrsh r0, [r4, r2]
	cmp r0, 0
	beq _08005524
	subs r0, r1, 0x1
	strh r0, [r4, 0x2]
	lsls r0, 16
	cmp r0, 0
	bgt _08005586
_08005524:
	ldr r0, [r4, 0x2C]
	ldrb r0, [r0]
	cmp r0, 0
	bne _08005550
	movs r0, 0x80
	lsls r0, 5
	ands r0, r3
	cmp r0, 0
	bne _08005542
	movs r1, 0x80
	lsls r1, 6
	adds r0, r1, 0
	orrs r0, r3
	strh r0, [r4]
	b _08005586
_08005542:
	ldr r0, [r4, 0x28]
	str r0, [r4, 0x2C]
	bl Rand32Bit
	movs r1, 0x1
	ands r0, r1
	strh r0, [r4, 0x4]
_08005550:
	ldrh r1, [r4]
	movs r2, 0x80
	lsls r2, 4
	adds r0, r2, 0
	orrs r0, r1
	strh r0, [r4]
	ldr r1, [r4, 0x2C]
	ldrb r0, [r1]
	strh r0, [r4, 0x2]
	ldrh r0, [r1, 0x2]
	strh r0, [r4, 0x20]
	ldrh r0, [r1, 0x4]
	strh r0, [r4, 0xC]
	ldrh r0, [r1, 0x6]
	strh r0, [r4, 0xE]
	ldrh r0, [r1, 0x8]
	strh r0, [r4, 0x10]
	ldrh r0, [r1, 0xA]
	strh r0, [r4, 0x12]
	ldrb r0, [r1, 0x1]
	str r0, [r4, 0x14]
	ldrb r2, [r1, 0x1]
	ldr r0, [r4, 0x18]
	orrs r0, r2
	str r0, [r4, 0x18]
	adds r1, 0xC
	str r1, [r4, 0x2C]
_08005586:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_80054BC

	.align 2, 0 @ Don't pad with nop.
