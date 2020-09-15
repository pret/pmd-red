	.include "constants/gba_constants.inc"
	.include "asm/macros.inc"

	.syntax unified

	.section .rodata

	.space 0x3C

	.text

	thumb_func_start sub_8272760
sub_8272760:
	push {lr}
	adds r1, r0, 0
	ldr r0, _08272770
	bl sub_8272774
	pop {r0}
	bx r0
	.align 2, 0
_08272770: .4byte gUnknown_2027370
	thumb_func_end sub_8272760

	thumb_func_start sub_8272774
sub_8272774:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x10
	lsls r2, r1, 3
	adds r2, r1
	lsls r2, 3
	adds r4, r0, r2
	movs r1, 0x8
	ldrsh r0, [r4, r1]
	cmp r0, 0
	ble _08272860
	ldr r0, [r4, 0xC]
	cmp r0, 0x6
	bne _082727B0
	movs r2, 0x4
	ldrsh r1, [r4, r2]
	ldr r0, [r4, 0x24]
	adds r0, 0x2
	lsls r0, 3
	muls r0, r1
	lsls r0, 2
	ldr r1, [r4, 0x18]
	adds r1, r0
	movs r3, 0x8
	ldrsh r0, [r4, r3]
	subs r2, r0, 0x2
	b _082727B6
_082727B0:
	ldr r1, [r4, 0x18]
	movs r5, 0x8
	ldrsh r2, [r4, r5]
_082727B6:
	ldr r0, [r4, 0x20]
	adds r3, r0, 0
	adds r3, 0x8
	str r3, [sp]
	adds r0, 0x9
	mov r10, r0
	movs r3, 0
	movs r5, 0x4
	ldrsh r0, [r4, r5]
	ldr r5, [r4, 0x28]
	str r5, [sp, 0x8]
	ldr r5, [r4, 0x1C]
	str r5, [sp, 0x4]
	adds r5, r4, 0
	adds r5, 0x44
	str r5, [sp, 0xC]
	cmp r3, r0
	bge _0827284E
	subs r7, r2, 0x1
	mov r9, r3
_082727DE:
	adds r2, r1, 0
	movs r0, 0x20
	adds r0, r2
	mov r12, r0
	adds r3, 0x1
	mov r8, r3
	cmp r7, 0
	ble _08272824
	ldr r1, [sp]
	lsls r6, r1, 2
	adds r3, r7, 0
	mov r0, r10
	lsls r5, r0, 2
_082727F8:
	ldr r0, [r2, 0x8]
	str r0, [r2]
	ldr r0, [r2, 0xC]
	str r0, [r2, 0x4]
	ldr r0, [r2, 0x10]
	str r0, [r2, 0x8]
	ldr r0, [r2, 0x14]
	str r0, [r2, 0xC]
	ldr r0, [r2, 0x18]
	str r0, [r2, 0x10]
	ldr r0, [r2, 0x1C]
	str r0, [r2, 0x14]
	adds r1, r6, r2
	ldr r0, [r1]
	str r0, [r2, 0x18]
	adds r0, r5, r2
	ldr r0, [r0]
	str r0, [r2, 0x1C]
	adds r2, r1, 0
	subs r3, 0x1
	cmp r3, 0
	bne _082727F8
_08272824:
	ldr r0, [r2, 0x8]
	str r0, [r2]
	ldr r0, [r2, 0xC]
	str r0, [r2, 0x4]
	ldr r0, [r2, 0x10]
	str r0, [r2, 0x8]
	ldr r0, [r2, 0x14]
	str r0, [r2, 0xC]
	ldr r0, [r2, 0x18]
	str r0, [r2, 0x10]
	ldr r0, [r2, 0x1C]
	str r0, [r2, 0x14]
	mov r1, r9
	str r1, [r2, 0x18]
	str r1, [r2, 0x1C]
	mov r1, r12
	mov r3, r8
	movs r2, 0x4
	ldrsh r0, [r4, r2]
	cmp r3, r0
	blt _082727DE
_0827284E:
	ldr r3, [sp, 0x8]
	str r3, [r4, 0x30]
	ldr r5, [sp, 0x4]
	str r5, [r4, 0x34]
	ldr r0, [r4, 0x2C]
	str r0, [r4, 0x38]
	movs r0, 0x1
	ldr r1, [sp, 0xC]
	strb r0, [r1]
_08272860:
	add sp, 0x10
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_8272774

	thumb_func_start sub_8272870
sub_8272870:
	push {lr}
	adds r1, r0, 0
	ldr r0, _08272880
	bl sub_8272884
	pop {r0}
	bx r0
	.align 2, 0
_08272880: .4byte gUnknown_2027370
	thumb_func_end sub_8272870

	thumb_func_start sub_8272884
sub_8272884:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0xC
	lsls r2, r1, 3
	adds r2, r1
	lsls r2, 3
	adds r5, r0, r2
	movs r1, 0x8
	ldrsh r0, [r5, r1]
	cmp r0, 0
	ble _08272994
	ldr r0, [r5, 0xC]
	cmp r0, 0x6
	bne _082728B0
	movs r2, 0x8
	ldrsh r0, [r5, r2]
	subs r0, 0x2
	mov r9, r0
	b _082728B6
_082728B0:
	movs r0, 0x8
	ldrsh r3, [r5, r0]
	mov r9, r3
_082728B6:
	movs r1, 0x8
	ldrsh r0, [r5, r1]
	subs r0, 0x1
	movs r3, 0x4
	ldrsh r2, [r5, r3]
	muls r0, r2
	lsls r0, 5
	ldr r1, [r5, 0x18]
	adds r1, r0
	ldr r0, [r5, 0x20]
	adds r0, 0x8
	mov r10, r0
	movs r4, 0
	ldr r0, [r5, 0x28]
	str r0, [sp]
	ldr r3, [r5, 0x1C]
	str r3, [sp, 0x8]
	adds r0, r5, 0
	adds r0, 0x44
	str r0, [sp, 0x4]
	cmp r4, r2
	bge _08272982
	mov r12, r4
	movs r2, 0x1
	negs r2, r2
	add r2, r9
	mov r8, r2
_082728EC:
	adds r2, r1, 0
	mov r3, r9
	cmp r3, 0x1
	bgt _0827291A
	ldr r0, [r1, 0x14]
	str r0, [r1, 0x1C]
	ldr r0, [r1, 0x10]
	str r0, [r1, 0x18]
	ldr r0, [r1, 0xC]
	str r0, [r1, 0x14]
	ldr r0, [r1, 0x8]
	str r0, [r1, 0x10]
	ldr r0, [r1, 0x4]
	str r0, [r1, 0xC]
	ldr r0, [r1]
	str r0, [r1, 0x8]
	mov r0, r12
	str r0, [r1, 0x4]
	str r0, [r1]
	adds r7, r1, 0
	adds r7, 0x20
	adds r6, r4, 0x1
	b _08272976
_0827291A:
	mov r3, r10
	lsls r0, r3, 2
	subs r3, r1, r0
	adds r7, r1, 0
	adds r7, 0x20
	adds r6, r4, 0x1
	mov r1, r8
	cmp r1, 0
	ble _08272958
	adds r4, r0, 0
_0827292E:
	ldr r0, [r2, 0x14]
	str r0, [r2, 0x1C]
	ldr r0, [r2, 0x10]
	str r0, [r2, 0x18]
	ldr r0, [r2, 0xC]
	str r0, [r2, 0x14]
	ldr r0, [r2, 0x8]
	str r0, [r2, 0x10]
	ldr r0, [r2, 0x4]
	str r0, [r2, 0xC]
	ldr r0, [r2]
	str r0, [r2, 0x8]
	ldr r0, [r3, 0x1C]
	str r0, [r2, 0x4]
	ldr r0, [r3, 0x18]
	str r0, [r2]
	subs r2, r4
	subs r3, r4
	subs r1, 0x1
	cmp r1, 0
	bne _0827292E
_08272958:
	ldr r0, [r2, 0x14]
	str r0, [r2, 0x1C]
	ldr r0, [r2, 0x10]
	str r0, [r2, 0x18]
	ldr r0, [r2, 0xC]
	str r0, [r2, 0x14]
	ldr r0, [r2, 0x8]
	str r0, [r2, 0x10]
	ldr r0, [r2, 0x4]
	str r0, [r2, 0xC]
	ldr r0, [r2]
	str r0, [r2, 0x8]
	mov r3, r12
	str r3, [r2, 0x4]
	str r3, [r2]
_08272976:
	adds r1, r7, 0
	adds r4, r6, 0
	movs r2, 0x4
	ldrsh r0, [r5, r2]
	cmp r4, r0
	blt _082728EC
_08272982:
	ldr r3, [sp]
	str r3, [r5, 0x30]
	ldr r0, [sp, 0x8]
	str r0, [r5, 0x34]
	ldr r0, [r5, 0x2C]
	str r0, [r5, 0x38]
	movs r0, 0x1
	ldr r1, [sp, 0x4]
	strb r0, [r1]
_08272994:
	add sp, 0xC
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_8272884

	thumb_func_start sub_82729A4
sub_82729A4:
	push {lr}
	adds r1, r0, 0
	ldr r0, _082729B4
	bl sub_82729B8
	pop {r0}
	bx r0
	.align 2, 0
_082729B4: .4byte gUnknown_2027370
	thumb_func_end sub_82729A4

	thumb_func_start sub_82729B8
sub_82729B8:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	lsls r2, r1, 3
	adds r2, r1
	lsls r2, 3
	adds r4, r0, r2
	ldr r2, [r4, 0x18]
	ldr r0, [r4, 0x20]
	adds r1, r0, 0
	adds r1, 0x8
	adds r5, r0, 0
	adds r5, 0x9
	movs r3, 0
	movs r6, 0x4
	ldrsh r0, [r4, r6]
	cmp r3, r0
	bge _08272A5A
	lsls r1, 2
	mov r8, r1
	lsls r6, r5, 2
	movs r5, 0
_082729E4:
	ldr r0, [r2, 0x14]
	str r0, [r2, 0xC]
	ldr r0, [r2, 0x18]
	str r0, [r2, 0x10]
	ldr r0, [r2, 0x1C]
	str r0, [r2, 0x14]
	mov r0, r8
	adds r1, r0, r2
	ldr r0, [r1]
	str r0, [r2, 0x18]
	adds r0, r6, r2
	ldr r0, [r0]
	str r0, [r2, 0x1C]
	adds r7, r2, 0
	adds r7, 0x20
	adds r3, 0x1
	mov r12, r3
	movs r3, 0x4
_08272A08:
	ldr r0, [r1, 0x8]
	str r0, [r1]
	ldr r0, [r1, 0xC]
	str r0, [r1, 0x4]
	ldr r0, [r1, 0x10]
	str r0, [r1, 0x8]
	ldr r0, [r1, 0x14]
	str r0, [r1, 0xC]
	ldr r0, [r1, 0x18]
	str r0, [r1, 0x10]
	ldr r0, [r1, 0x1C]
	str r0, [r1, 0x14]
	mov r0, r8
	adds r2, r0, r1
	ldr r0, [r2]
	str r0, [r1, 0x18]
	adds r0, r6, r1
	ldr r0, [r0]
	str r0, [r1, 0x1C]
	adds r1, r2, 0
	subs r3, 0x1
	cmp r3, 0
	bge _08272A08
	ldr r0, [r2, 0x8]
	str r0, [r2]
	ldr r0, [r2, 0xC]
	str r0, [r2, 0x4]
	ldr r0, [r2, 0x10]
	str r0, [r2, 0x8]
	ldr r0, [r2, 0x14]
	str r0, [r2, 0xC]
	str r5, [r2, 0x10]
	str r5, [r2, 0x14]
	str r5, [r2, 0x18]
	str r5, [r2, 0x1C]
	adds r2, r7, 0
	mov r3, r12
	movs r1, 0x4
	ldrsh r0, [r4, r1]
	cmp r3, r0
	blt _082729E4
_08272A5A:
	ldr r0, [r4, 0x28]
	str r0, [r4, 0x30]
	ldr r0, [r4, 0x1C]
	str r0, [r4, 0x34]
	ldr r0, [r4, 0x2C]
	str r0, [r4, 0x38]
	adds r1, r4, 0
	adds r1, 0x44
	movs r0, 0x1
	strb r0, [r1]
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_82729B8

	thumb_func_start sub_8272A78
sub_8272A78:
	push {lr}
	adds r1, r0, 0
	ldr r0, _08272A88
	bl sub_8272A8C
	pop {r0}
	bx r0
	.align 2, 0
_08272A88: .4byte gUnknown_2027370
	thumb_func_end sub_8272A78

	thumb_func_start sub_8272A8C
sub_8272A8C:
	push {r4-r7,lr}
	lsls r2, r1, 3
	adds r2, r1
	lsls r2, 3
	adds r4, r0, r2
	ldr r2, [r4, 0x18]
	ldr r0, [r4, 0x20]
	adds r1, r0, 0
	adds r1, 0x8
	movs r3, 0
	movs r5, 0x4
	ldrsh r0, [r4, r5]
	cmp r3, r0
	bge _08272B20
	mov r12, r3
	lsls r5, r1, 2
_08272AAC:
	mov r0, r12
	str r0, [r2, 0xC]
	ldr r0, [r2, 0x14]
	str r0, [r2, 0x10]
	ldr r0, [r2, 0x18]
	str r0, [r2, 0x14]
	ldr r0, [r2, 0x1C]
	str r0, [r2, 0x18]
	adds r1, r5, r2
	ldr r0, [r1]
	str r0, [r2, 0x1C]
	adds r6, r2, 0
	adds r6, 0x20
	adds r7, r3, 0x1
	movs r3, 0x4
_08272ACA:
	ldr r0, [r1, 0x4]
	str r0, [r1]
	ldr r0, [r1, 0x8]
	str r0, [r1, 0x4]
	ldr r0, [r1, 0xC]
	str r0, [r1, 0x8]
	ldr r0, [r1, 0x10]
	str r0, [r1, 0xC]
	ldr r0, [r1, 0x14]
	str r0, [r1, 0x10]
	ldr r0, [r1, 0x18]
	str r0, [r1, 0x14]
	ldr r0, [r1, 0x1C]
	str r0, [r1, 0x18]
	adds r2, r5, r1
	ldr r0, [r2]
	str r0, [r1, 0x1C]
	adds r1, r2, 0
	subs r3, 0x1
	cmp r3, 0
	bge _08272ACA
	ldr r0, [r2, 0x4]
	str r0, [r2]
	ldr r0, [r2, 0x8]
	str r0, [r2, 0x4]
	ldr r0, [r2, 0xC]
	str r0, [r2, 0x8]
	ldr r0, [r2, 0x10]
	str r0, [r2, 0xC]
	ldr r0, [r2, 0x14]
	str r0, [r2, 0x10]
	ldr r0, [r2, 0x18]
	str r0, [r2, 0x14]
	ldr r0, [r2, 0x1C]
	str r0, [r2, 0x18]
	mov r1, r12
	str r1, [r2, 0x1C]
	adds r2, r6, 0
	adds r3, r7, 0
	movs r1, 0x4
	ldrsh r0, [r4, r1]
	cmp r3, r0
	blt _08272AAC
_08272B20:
	ldr r0, [r4, 0x28]
	str r0, [r4, 0x30]
	ldr r0, [r4, 0x1C]
	str r0, [r4, 0x34]
	ldr r0, [r4, 0x2C]
	str r0, [r4, 0x38]
	adds r1, r4, 0
	adds r1, 0x44
	movs r0, 0x1
	strb r0, [r1]
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_8272A8C

	.align 2, 0 @ Don't pad with nop.
