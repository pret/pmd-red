	.include "constants/gba_constants.inc"
	.include "asm/macros.inc"

	.syntax unified

	.text

	thumb_func_start sub_8090F58
sub_8090F58:
	push {r4-r6,lr}
	sub sp, 0x2C
	adds r5, r0, 0
	adds r6, r1, 0
	adds r0, r2, 0
	adds r4, r3, 0
	cmp r4, 0
	bne _08090F6C
	adds r0, r5, 0
	b _08090F94
_08090F6C:
	ldr r1, [r4]
	cmp r1, 0x1
	bcc _08090F8A
	cmp r1, 0x2
	bhi _08090F7E
	bl GetStackBuyValue
	adds r1, r0, 0
	b _08090F8C
_08090F7E:
	cmp r1, 0x4
	bhi _08090F8A
	bl GetStackSellValue
	adds r1, r0, 0
	b _08090F8C
_08090F8A:
	movs r1, 0
_08090F8C:
	cmp r1, 0
	bne _08090F9C
	adds r0, r5, 0
	adds r1, r6, 0
_08090F94:
	movs r2, 0x50
	bl strncpy
	b _08090FDE
_08090F9C:
	movs r2, 0x6
	ldrsh r0, [r4, r2]
	cmp r0, 0
	beq _08090FC8
	adds r0, r1, 0
	add r1, sp, 0x4
	movs r2, 0x1
	bl sub_8090FEC
	ldr r1, _08090FC4
	movs r0, 0x6
	ldrsh r3, [r4, r0]
	add r2, sp, 0x4
	str r2, [sp]
	adds r0, r5, 0
	adds r2, r6, 0
	bl ExpandPlaceholdersBuffer
	b _08090FDE
	.align 2, 0
_08090FC4: .4byte gUnknown_8109794
_08090FC8:
	adds r0, r1, 0
	add r1, sp, 0x4
	movs r2, 0
	bl sub_8090FEC
	ldr r1, _08090FE8
	adds r0, r5, 0
	adds r2, r6, 0
	add r3, sp, 0x4
	bl ExpandPlaceholdersBuffer
_08090FDE:
	add sp, 0x2C
	pop {r4-r6}
	pop {r0}
	bx r0
	.align 2, 0
_08090FE8: .4byte gUnknown_81097A4
	thumb_func_end sub_8090F58

	thumb_func_start sub_8090FEC
sub_8090FEC:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	adds r5, r0, 0
	adds r4, r1, 0
	lsls r2, 24
	lsrs r2, 24
	mov r10, r2
	movs r0, 0
	mov r8, r0
	movs r6, 0
	movs r2, 0
	ldr r1, _08091050
	mov r9, r1
	mov r12, r9
_0809100E:
	movs r1, 0
	lsls r3, r2, 2
	ldr r7, _08091054
	adds r0, r3, r7
	ldr r0, [r0]
	adds r7, r2, 0x1
	cmp r5, r0
	blt _0809102C
	ldr r2, _08091054
_08091020:
	adds r0, r3, r2
	ldr r0, [r0]
	subs r5, r0
	adds r1, 0x1
	cmp r5, r0
	bge _08091020
_0809102C:
	cmp r1, 0x9
	ble _08091032
	movs r1, 0x9
_08091032:
	cmp r1, 0
	beq _0809105C
	movs r0, 0x1
	mov r8, r0
	lsls r1, 1
	mov r2, r12
	adds r0, r1, r2
	ldrb r0, [r0]
	strb r0, [r4]
	adds r4, 0x1
	ldr r0, _08091058
	adds r1, r0
	ldrb r0, [r1]
	b _0809106C
	.align 2, 0
_08091050: .4byte gUnknown_81097C4
_08091054: .4byte gUnknown_81097B0
_08091058: .4byte gUnknown_81097C5
_0809105C:
	mov r1, r8
	cmp r1, 0
	beq _08091074
	mov r2, r12
	ldrb r0, [r2]
	strb r0, [r4]
	adds r4, 0x1
	ldrb r0, [r2, 0x1]
_0809106C:
	strb r0, [r4]
	adds r4, 0x1
	adds r6, 0x1
	b _08091080
_08091074:
	mov r0, r10
	cmp r0, 0
	beq _08091080
	movs r0, 0x60
	strb r0, [r4]
	adds r4, 0x1
_08091080:
	adds r2, r7, 0
	cmp r2, 0x4
	ble _0809100E
	lsls r1, r5, 1
	mov r2, r9
	adds r0, r1, r2
	ldrb r0, [r0]
	strb r0, [r4]
	adds r4, 0x1
	mov r0, r9
	adds r0, 0x1
	adds r1, r0
	ldrb r0, [r1]
	strb r0, [r4]
	adds r6, 0x1
	movs r0, 0
	strb r0, [r4, 0x1]
	adds r0, r6, 0
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_8090FEC

        .align 2,0
