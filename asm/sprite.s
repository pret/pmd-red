	#include "asm/constants/gba_constants.inc"
	#include "asm/macros.inc"

	.syntax unified

	.text

	thumb_func_start sub_80052BC
sub_80052BC:
	push {r4-r6,lr}
	adds r3, r0, 0
	ldr r0, [r3, 0x4]
	cmp r0, 0
	beq _080052F2
	ldr r5, _080052F8
	ldr r6, _080052FC
	ldr r4, _08005300
_080052CC:
	ldr r2, [r5]
	cmp r2, r6
	bcs _080052F2
	ldr r0, [r3, 0x4]
	str r0, [r2]
	ldr r0, [r3]
	str r0, [r2, 0x4]
	ldr r1, [r4]
	str r1, [r2, 0x8]
	ldr r0, [r3, 0x4]
	adds r1, r0
	str r1, [r4]
	adds r0, r2, 0
	adds r0, 0xC
	str r0, [r5]
	adds r3, 0x8
	ldr r0, [r3, 0x4]
	cmp r0, 0
	bne _080052CC
_080052F2:
	pop {r4-r6}
	pop {r0}
	bx r0
	.align 2, 0
_080052F8: .4byte gUnknown_203B074
_080052FC: .4byte gCharMemCursor
_08005300: .4byte gCharMemCursor
	thumb_func_end sub_80052BC

	thumb_func_start sub_8005304
sub_8005304:
	push {r4,lr}
	ldr r4, _0800530C
	b _0800532A
	.align 2, 0
_0800530C: .4byte gUnknown_20266B0
_08005310:
	ldr r1, [r4, 0x4]
	cmp r1, 0
	beq _08005320
	ldr r0, [r4, 0x8]
	ldr r2, [r4]
	bl CpuCopy
	b _08005328
_08005320:
	ldr r0, [r4, 0x8]
	ldr r1, [r4]
	bl CpuClear
_08005328:
	adds r4, 0xC
_0800532A:
	ldr r0, _08005338
	ldr r0, [r0]
	cmp r4, r0
	bcc _08005310
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08005338: .4byte gUnknown_203B074
	thumb_func_end sub_8005304

	thumb_func_start sub_800533C
sub_800533C:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	mov r8, r1
	adds r5, r2, 0
	adds r7, r3, 0
	ldr r1, [sp, 0x18]
	lsls r1, 24
	lsrs r6, r1, 24
	movs r2, 0x18
	ldrsh r1, [r5, r2]
	lsls r1, 2
	adds r1, r0
	ldr r4, [r1]
	ldr r1, _08005368
	movs r2, 0x14
	ldrsh r0, [r5, r2]
	lsls r0, 5
	ldr r2, _0800536C
	adds r0, r2
	str r0, [r1]
	b _0800538E
	.align 2, 0
_08005368: .4byte gCharMemCursor
_0800536C: .4byte 0x06010000
_08005370:
	cmp r6, 0
	beq _08005382
	movs r1, 0
	ldrsh r0, [r4, r1]
	cmp r0, 0
	blt _08005382
	lsls r0, 2
	add r0, r8
	ldr r2, [r0]
_08005382:
	adds r0, r4, 0
	adds r1, r5, 0
	adds r3, r7, 0
	bl sub_8004EA8
	adds r4, 0xA
_0800538E:
	movs r2, 0
	ldrh r1, [r4]
	ldr r0, _080053A8
	cmp r1, r0
	bne _08005370
	ldrh r0, [r4, 0x2]
	cmp r0, r1
	bne _08005370
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_080053A8: .4byte 0x0000ffff
	thumb_func_end sub_800533C

	thumb_func_start sub_80053AC
sub_80053AC:
	push {r4-r6,lr}
	sub sp, 0xC
	ldr r5, [sp, 0x1C]
	ldr r6, [sp, 0x20]
	ldr r4, [sp, 0x24]
	lsls r4, 24
	lsrs r4, 24
	ldr r1, [r1, 0x4]
	str r5, [sp]
	str r6, [sp, 0x4]
	str r4, [sp, 0x8]
	bl sub_80053D0
	add sp, 0xC
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end sub_80053AC

	thumb_func_start sub_80053D0
sub_80053D0:
	push {r4-r7,lr}
	adds r4, r0, 0
	adds r5, r1, 0
	adds r6, r2, 0
	adds r7, r3, 0
	ldr r0, [sp, 0x1C]
	lsls r0, 24
	movs r2, 0
	movs r3, 0x80
	lsls r3, 8
	strh r3, [r4]
	cmp r0, 0
	beq _080053F6
	movs r0, 0x80
	lsls r0, 5
	adds r1, r0, 0
	adds r0, r3, 0
	orrs r0, r1
	strh r0, [r4]
_080053F6:
	strh r2, [r4, 0x2]
	ldr r0, [sp, 0x18]
	strh r0, [r4, 0x4]
	strh r2, [r4, 0xC]
	strh r2, [r4, 0xE]
	ldr r0, [sp, 0x14]
	strh r0, [r4, 0x1C]
	ldr r0, _08005438
	strh r0, [r4, 0x20]
	movs r0, 0x1
	negs r0, r0
	strh r0, [r4, 0x22]
	str r2, [r4, 0x14]
	str r2, [r4, 0x18]
	strh r2, [r4, 0x6]
	ldr r1, [r5, 0x4]
	lsls r0, r6, 2
	adds r0, r1
	ldr r1, [r0]
	lsls r0, r7, 2
	adds r0, r1
	ldr r0, [r0]
	str r0, [r4, 0x28]
	str r0, [r4, 0x2C]
	ldr r0, [r5]
	str r0, [r4, 0x34]
	ldr r0, [r5, 0xC]
	str r0, [r4, 0x38]
	ldr r0, [r5, 0x10]
	str r0, [r4, 0x30]
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_08005438: .4byte 0x0000ffff
	thumb_func_end sub_80053D0

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
