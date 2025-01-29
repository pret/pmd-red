	#include "asm/constants/gba_constants.inc"
	#include "asm/macros.inc"

	.syntax unified

	.text

	thumb_func_start sub_804225C
sub_804225C:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0x4
	mov r8, r0
	adds r5, r1, 0
	lsls r2, 24
	lsrs r4, r2, 24
	adds r7, r4, 0
	cmp r4, 0x11
	bne _08042274
	b _08042384
_08042274:
	adds r0, r5, 0
	bl sub_803F428
	lsls r0, 24
	cmp r0, 0
	bne _08042282
	b _08042384
_08042282:
	adds r0, r4, 0
	bl sub_800EF28
	bl sub_800EF64
	movs r0, 0x4
	movs r1, 0x42
	bl sub_803E708
	movs r0, 0
	ldrsh r1, [r5, r0]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 11
	movs r1, 0xC0
	lsls r1, 4
	adds r0, r1
	cmp r0, 0
	bge _080422AA
	adds r0, 0xFF
_080422AA:
	lsls r0, 8
	lsrs r0, 16
	ldr r1, _080422FC
	ldr r2, [sp]
	ands r2, r1
	orrs r2, r0
	str r2, [sp]
	movs r0, 0x2
	ldrsh r1, [r5, r0]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 11
	movs r1, 0x80
	lsls r1, 5
	adds r0, r1
	cmp r0, 0
	bge _080422CE
	adds r0, 0xFF
_080422CE:
	lsls r0, 8
	lsrs r0, 16
	lsls r0, 16
	ldr r1, _08042300
	ands r2, r1
	orrs r2, r0
	str r2, [sp]
	adds r0, r4, 0
	mov r1, sp
	bl sub_800E448
	adds r6, r0, 0
	cmp r4, 0x4
	bne _08042308
	ldr r1, _08042304
	movs r0, 0
	bl sub_80421C0
	movs r0, 0x28
	movs r1, 0x33
	bl sub_803E708
	b _08042360
	.align 2, 0
_080422FC: .4byte 0xffff0000
_08042300: .4byte 0x0000ffff
_08042304: .4byte 0x00000193
_08042308:
	cmp r7, 0x8
	bne _08042358
	mov r0, r8
	ldr r7, [r0, 0x70]
	adds r0, r7, 0
	adds r0, 0x46
	ldrb r4, [r0]
	movs r5, 0
	b _0804231C
_0804231A:
	adds r5, 0x2
_0804231C:
	ldr r0, _08042354
	cmp r5, r0
	bgt _08042346
	subs r4, 0x1
	movs r0, 0x7
	ands r4, r0
	mov r0, r8
	movs r1, 0
	adds r2, r4, 0
	bl sub_806CDD4
	movs r0, 0x2
	movs r1, 0x33
	bl sub_803E708
	adds r0, r6, 0
	bl sub_800E9A8
	lsls r0, 24
	cmp r0, 0
	bne _0804231A
_08042346:
	movs r0, 0x7
	ands r4, r0
	adds r0, r7, 0
	adds r0, 0x46
	strb r4, [r0]
	b _08042360
	.align 2, 0
_08042354: .4byte 0x000003e7
_08042358:
	movs r0, 0x28
	movs r1, 0x33
	bl sub_803E708
_08042360:
	movs r5, 0
	ldr r4, _08042368
	b _0804236E
	.align 2, 0
_08042368: .4byte 0x000003e7
_0804236C:
	adds r5, 0x1
_0804236E:
	cmp r5, r4
	bgt _08042384
	movs r0, 0x42
	bl sub_803E46C
	adds r0, r6, 0
	bl sub_800E9A8
	lsls r0, 24
	cmp r0, 0
	bne _0804236C
_08042384:
	add sp, 0x4
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_804225C

	thumb_func_start sub_8042390
sub_8042390:
	push {r4-r6,lr}
	sub sp, 0x18
	adds r5, r0, 0
	adds r4, r1, 0
	bl sub_8042768
	lsls r0, 24
	cmp r0, 0
	beq _08042454
	ldrb r1, [r4]
	movs r0, 0x8
	ands r0, r1
	movs r6, 0
	cmp r0, 0
	bne _080423B0
	ldrb r6, [r4, 0x2]
_080423B0:
	adds r0, r6, 0
	movs r1, 0
	bl sub_800EF40
	bl sub_800EF64
	movs r0, 0x4
	movs r1, 0x42
	bl sub_803E708
	ldr r0, [r5, 0xC]
	cmp r0, 0
	bge _080423CC
	adds r0, 0xFF
_080423CC:
	lsls r0, 8
	lsrs r0, 16
	ldr r1, _08042428
	ldr r2, [sp, 0x14]
	ands r2, r1
	orrs r2, r0
	str r2, [sp, 0x14]
	ldr r0, [r5, 0x10]
	cmp r0, 0
	bge _080423E2
	adds r0, 0xFF
_080423E2:
	lsls r0, 8
	lsrs r0, 16
	lsls r0, 16
	ldr r4, _0804242C
	ands r4, r2
	orrs r4, r0
	str r4, [sp, 0x14]
	asrs r4, 16
	ldr r0, _08042430
	ldr r0, [r0]
	ldr r1, _08042434
	adds r0, r1
	movs r1, 0
	ldrsh r0, [r0, r1]
	subs r4, r0
	lsrs r0, r4, 31
	adds r4, r0
	asrs r4, 1
	adds r4, 0x1
	adds r1, r5, 0
	adds r1, 0x28
	add r0, sp, 0x4
	bl sub_8005700
	add r1, sp, 0x14
	str r4, [sp]
	adds r0, r6, 0
	add r2, sp, 0x4
	movs r3, 0
	bl sub_800E49C
	adds r5, r0, 0
	movs r4, 0
	ldr r6, _08042438
	b _0804243E
	.align 2, 0
_08042428: .4byte 0xffff0000
_0804242C: .4byte 0x0000ffff
_08042430: .4byte gDungeon
_08042434: .4byte 0x000181f2
_08042438: .4byte 0x000003e7
_0804243C:
	adds r4, 0x1
_0804243E:
	cmp r4, r6
	bgt _08042454
	movs r0, 0x42
	bl sub_803E46C
	adds r0, r5, 0
	bl sub_800E9A8
	lsls r0, 24
	cmp r0, 0
	bne _0804243C
_08042454:
	add sp, 0x18
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end sub_8042390

	thumb_func_start sub_804245C
sub_804245C:
	push {r4-r6,lr}
	sub sp, 0x18
	adds r5, r0, 0
	adds r4, r1, 0
	bl sub_8042768
	lsls r0, 24
	cmp r0, 0
	beq _08042518
	ldrb r1, [r4]
	movs r0, 0x8
	ands r0, r1
	movs r6, 0
	cmp r0, 0
	bne _0804247C
	ldrb r6, [r4, 0x2]
_0804247C:
	bl sub_800EF64
	movs r0, 0x4
	movs r1, 0x42
	bl sub_803E708
	ldr r0, [r5, 0xC]
	cmp r0, 0
	bge _08042490
	adds r0, 0xFF
_08042490:
	lsls r0, 8
	lsrs r0, 16
	ldr r1, _080424EC
	ldr r2, [sp, 0x14]
	ands r2, r1
	orrs r2, r0
	str r2, [sp, 0x14]
	ldr r0, [r5, 0x10]
	cmp r0, 0
	bge _080424A6
	adds r0, 0xFF
_080424A6:
	lsls r0, 8
	lsrs r0, 16
	lsls r0, 16
	ldr r4, _080424F0
	ands r4, r2
	orrs r4, r0
	str r4, [sp, 0x14]
	asrs r4, 16
	ldr r0, _080424F4
	ldr r0, [r0]
	ldr r1, _080424F8
	adds r0, r1
	movs r1, 0
	ldrsh r0, [r0, r1]
	subs r4, r0
	lsrs r0, r4, 31
	adds r4, r0
	asrs r4, 1
	adds r4, 0x1
	adds r1, r5, 0
	adds r1, 0x28
	add r0, sp, 0x4
	bl sub_8005700
	add r1, sp, 0x14
	str r4, [sp]
	adds r0, r6, 0
	add r2, sp, 0x4
	movs r3, 0x1
	bl sub_800E49C
	adds r5, r0, 0
	movs r4, 0
	ldr r6, _080424FC
	b _08042502
	.align 2, 0
_080424EC: .4byte 0xffff0000
_080424F0: .4byte 0x0000ffff
_080424F4: .4byte gDungeon
_080424F8: .4byte 0x000181f2
_080424FC: .4byte 0x000003e7
_08042500:
	adds r4, 0x1
_08042502:
	cmp r4, r6
	bgt _08042518
	movs r0, 0x42
	bl sub_803E46C
	adds r0, r5, 0
	bl sub_800E9A8
	lsls r0, 24
	cmp r0, 0
	bne _08042500
_08042518:
	add sp, 0x18
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end sub_804245C

        .align 2,0
