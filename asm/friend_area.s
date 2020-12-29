	.include "constants/gba_constants.inc"
	.include "asm/macros.inc"

	.syntax unified

	.text	

        thumb_func_start sub_8092404
sub_8092404:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	mov r10, r1
	lsls r0, 24
	lsrs r0, 24
	mov r9, r0
	lsls r2, 24
	lsrs r2, 24
	mov r8, r2
	lsls r3, 24
	lsrs r7, r3, 24
	movs r6, 0
	movs r4, 0
	mov r5, r10
_08092426:
	movs r0, 0x58
	adds r1, r4, 0
	muls r1, r0
	ldr r0, _08092494
	ldr r0, [r0]
	adds r2, r1, r0
	ldrb r1, [r2]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _08092472
	ldrb r0, [r2, 0x2]
	cmp r0, 0
	beq _08092448
	mov r0, r8
	cmp r0, 0
	beq _08092472
_08092448:
	movs r1, 0
	ldrb r0, [r2, 0x4]
	cmp r0, 0x41
	bne _08092452
	movs r1, 0x1
_08092452:
	cmp r1, 0
	beq _0809245A
	cmp r7, 0
	beq _08092472
_0809245A:
	adds r0, r4, 0
	bl sub_80923D4
	lsls r0, 24
	lsrs r0, 24
	cmp r0, r9
	bne _08092472
	cmp r6, 0xF
	bgt _08092472
	strh r4, [r5]
	adds r5, 0x2
	adds r6, 0x1
_08092472:
	adds r4, 0x1
	movs r0, 0xCE
	lsls r0, 1
	cmp r4, r0
	ble _08092426
	lsls r0, r6, 1
	add r0, r10
	ldr r2, _08092498
	adds r1, r2, 0
	strh r1, [r0]
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_08092494: .4byte gUnknown_203B45C
_08092498: .4byte 0x0000ffff
	thumb_func_end sub_8092404

	thumb_func_start sub_809249C
sub_809249C:
	push {r4-r7,lr}
	lsls r0, 24
	lsrs r6, r0, 24
	lsls r1, 24
	lsrs r7, r1, 24
	ldr r0, _080924F8
	ldr r0, [r0]
	adds r0, r6
	ldrb r0, [r0]
	cmp r0, 0
	beq _0809251A
	movs r5, 0
_080924B4:
	ldr r2, _080924FC
	movs r0, 0x58
	adds r1, r5, 0
	muls r1, r0
	ldr r0, [r2]
	adds r4, r0, r1
	ldrb r1, [r4]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _08092502
	adds r0, r5, 0
	bl sub_80923D4
	lsls r0, 24
	lsrs r0, 24
	cmp r0, r6
	bne _08092502
	movs r1, 0
	ldrb r0, [r4, 0x4]
	cmp r0, 0x41
	bne _080924E2
	movs r1, 0x1
_080924E2:
	cmp r1, 0
	bne _080924F2
	ldrb r1, [r4, 0x2]
	negs r0, r1
	orrs r0, r1
	lsrs r0, 31
	cmp r0, 0
	beq _08092500
_080924F2:
	movs r7, 0
	b _08092502
	.align 2, 0
_080924F8: .4byte gFriendAreas
_080924FC: .4byte gUnknown_203B45C
_08092500:
	strh r0, [r4]
_08092502:
	adds r5, 0x1
	movs r0, 0xCE
	lsls r0, 1
	cmp r5, r0
	ble _080924B4
	cmp r7, 0
	beq _0809251A
	ldr r0, _08092520
	ldr r0, [r0]
	adds r0, r6
	movs r1, 0
	strb r1, [r0]
_0809251A:
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_08092520: .4byte gFriendAreas
	thumb_func_end sub_809249C

        .align 2,0
