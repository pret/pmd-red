	#include "asm/constants/gba_constants.inc"
	#include "asm/macros.inc"

	.syntax unified

	.text





	thumb_func_start sub_800E49C
sub_800E49C:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0x50
	adds r7, r1, 0
	mov r8, r2
	lsls r0, 24
	lsrs r0, 24
	lsls r3, 24
	lsrs r6, r3, 24
	cmp r6, 0
	beq _0800E4BA
	bl sub_800ECF8
	b _0800E4BE
_0800E4BA:
	bl sub_800ED0C
_0800E4BE:
	lsls r0, 16
	asrs r4, r0, 16
	adds r0, r4, 0
	bl sub_800E700
	adds r5, r0, 0
	str r4, [sp, 0x28]
	movs r1, 0
	str r1, [sp, 0x2C]
	movs r4, 0x1
	negs r4, r4
	str r4, [sp, 0x30]
	ldr r0, [r7]
	str r0, [sp, 0x34]
	str r1, [sp, 0x38]
	str r4, [sp, 0x3C]
	str r1, [sp, 0x40]
	add r1, sp, 0x44
	ldr r0, _0800E508
	ldm r0!, {r2,r3,r7}
	stm r1!, {r2,r3,r7}
	add r1, sp, 0x28
	mov r0, sp
	movs r2, 0x28
	bl memcpy
	ldr r0, [sp, 0x68]
	str r0, [sp, 0x18]
	cmp r6, 0
	beq _0800E50C
	cmp r5, r4
	beq _0800E516
	str r5, [sp, 0x14]
	lsls r0, r5, 2
	add r0, r8
	ldr r0, [r0]
	b _0800E514
	.align 2, 0
_0800E508: .4byte gUnknown_80B9C60
_0800E50C:
	movs r0, 0x3
	str r0, [sp, 0x14]
	mov r1, r8
	ldr r0, [r1, 0xC]
_0800E514:
	str r0, [sp, 0x10]
_0800E516:
	movs r0, 0x4
	mov r1, sp
	bl sub_800E208
	add sp, 0x50
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_800E49C

	thumb_func_start sub_800E52C
sub_800E52C:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x1B0
	adds r7, r0, 0
	ldrh r0, [r7]
	cmp r0, 0x52
	bne _0800E628
	mov r1, sp
	ldr r0, _0800E618
	ldm r0!, {r2-r4}
	stm r1!, {r2-r4}
	ldm r0!, {r2,r3,r5}
	stm r1!, {r2,r3,r5}
	ldm r0!, {r4,r5}
	stm r1!, {r4,r5}
	movs r0, 0
	mov r10, r0
	mov r9, r0
	mov r8, sp
	add r6, sp, 0x20
	adds r4, r6, 0
_0800E55C:
	ldrh r0, [r7]
	bl sub_800ECB8
	movs r1, 0x2
	ldrsh r0, [r0, r1]
	str r0, [r4]
	ldr r0, [r7, 0x10]
	str r0, [r4, 0x4]
	ldr r0, [r7, 0xC]
	str r0, [r4, 0x8]
	ldr r0, [r7, 0x4]
	str r0, [r4, 0xC]
	ldrh r0, [r4, 0xE]
	adds r0, 0x40
	strh r0, [r4, 0xE]
	ldr r0, [r7, 0x8]
	str r0, [r4, 0x10]
	mov r2, r8
	ldrh r0, [r2]
	ldrh r3, [r4, 0x10]
	adds r0, r3
	strh r0, [r4, 0x10]
	ldrh r0, [r4, 0x12]
	subs r0, 0x40
	ldrh r5, [r2, 0x2]
	adds r0, r5
	strh r0, [r4, 0x12]
	movs r1, 0x2
	ldrsh r0, [r7, r1]
	ldrh r1, [r7]
	bl sub_800E750
	str r0, [r4, 0x14]
	ldr r0, _0800E61C
	str r0, [r4, 0x18]
	adds r1, r6, 0
	adds r1, 0x1C
	ldr r0, _0800E620
	ldm r0!, {r2,r3,r5}
	stm r1!, {r2,r3,r5}
	movs r0, 0x1
	adds r1, r6, 0
	bl sub_800E208
	adds r5, r0, 0
	bl sub_800E2C0
	adds r1, r0, 0
	movs r0, 0x1
	negs r0, r0
	cmp r1, r0
	beq _0800E5D4
	ldr r2, _0800E624
	movs r0, 0xD0
	muls r1, r0
	ldr r0, [r2]
	adds r0, r1
	adds r0, 0xCC
	movs r1, 0x6
	strh r1, [r0]
_0800E5D4:
	mov r0, r9
	cmp r0, 0
	bne _0800E5DC
	mov r10, r5
_0800E5DC:
	movs r1, 0x4
	add r8, r1
	adds r4, 0x28
	adds r6, 0x28
	movs r2, 0x1
	add r9, r2
	mov r3, r9
	cmp r3, 0x7
	ble _0800E55C
	movs r4, 0x6
	mov r9, r4
_0800E5F2:
	ldrh r0, [r7]
	bl sub_800ECB8
	movs r5, 0x2
	ldrsh r0, [r0, r5]
	bl sub_800ECA4
	ldr r0, [r0, 0x4]
	bl sub_800F15C
	movs r0, 0x1
	negs r0, r0
	add r9, r0
	mov r1, r9
	cmp r1, 0
	bge _0800E5F2
	mov r0, r10
	b _0800E67E
	.align 2, 0
_0800E618: .4byte gUnknown_80B9C7C
_0800E61C: .4byte 0x0000ffff
_0800E620: .4byte gUnknown_80B9C60
_0800E624: .4byte gUnknown_203B0CC
_0800E628:
	add r6, sp, 0x160
	add r5, sp, 0x188
	ldrh r0, [r7]
	bl sub_800ECB8
	movs r2, 0x2
	ldrsh r0, [r0, r2]
	str r0, [r5]
	add r1, sp, 0x18C
	ldr r0, [r7, 0x10]
	str r0, [r1]
	add r1, sp, 0x190
	ldr r0, [r7, 0xC]
	str r0, [r1]
	add r1, sp, 0x194
	ldr r0, [r7, 0x4]
	str r0, [r1]
	add r1, sp, 0x198
	ldr r0, [r7, 0x8]
	str r0, [r1]
	add r4, sp, 0x19C
	movs r3, 0x2
	ldrsh r0, [r7, r3]
	ldrh r1, [r7]
	bl sub_800E750
	str r0, [r4]
	add r1, sp, 0x1A0
	ldr r0, _0800E690
	str r0, [r1]
	add r1, sp, 0x1A4
	ldr r0, _0800E694
	ldm r0!, {r2-r4}
	stm r1!, {r2-r4}
	adds r0, r6, 0
	adds r1, r5, 0
	movs r2, 0x28
	bl memcpy
	movs r0, 0x1
	adds r1, r6, 0
	bl sub_800E208
_0800E67E:
	add sp, 0x1B0
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	.align 2, 0
_0800E690: .4byte 0x0000ffff
_0800E694: .4byte gUnknown_80B9C60
	thumb_func_end sub_800E52C

	thumb_func_start sub_800E698
sub_800E698:
	push {r4,r5,lr}
	adds r4, r1, 0
	adds r5, r2, 0
	bl sub_800E2C0
	adds r1, r0, 0
	movs r3, 0x1
	negs r3, r3
	cmp r1, r3
	beq _0800E6D2
	ldr r2, _0800E6C8
	movs r0, 0xD0
	muls r1, r0
	ldr r0, [r2]
	adds r1, r0, r1
	ldr r0, [r4]
	str r0, [r1, 0x18]
	ldr r0, [r1, 0x20]
	cmp r0, r3
	beq _0800E6CC
	ldr r0, [r5]
	str r0, [r1, 0x1C]
	b _0800E6D2
	.align 2, 0
_0800E6C8: .4byte gUnknown_203B0CC
_0800E6CC:
	movs r0, 0
	strh r0, [r1, 0x1C]
	strh r0, [r1, 0x1E]
_0800E6D2:
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_800E698

	thumb_func_start sub_800E6D8
sub_800E6D8:
	push {lr}
	bl sub_800E2C0
	adds r1, r0, 0
	movs r0, 0x1
	negs r0, r0
	cmp r1, r0
	bne _0800E6EC
	adds r0, r1, 0
	b _0800E6F8
_0800E6EC:
	ldr r2, _0800E6FC
	movs r0, 0xD0
	muls r1, r0
	ldr r0, [r2]
	adds r0, r1
	ldr r0, [r0, 0x20]
_0800E6F8:
	pop {r1}
	bx r1
	.align 2, 0
_0800E6FC: .4byte gUnknown_203B0CC
	thumb_func_end sub_800E6D8

	thumb_func_start sub_800E700
sub_800E700:
	push {lr}
	lsls r0, 16
	asrs r0, 16
	bl sub_800E900
	pop {r1}
	bx r1
	thumb_func_end sub_800E700

	thumb_func_start sub_800E710
sub_800E710:
	push {r4-r6,lr}
	lsls r0, 16
	asrs r5, r0, 16
	lsls r1, 16
	lsrs r1, 16
	adds r0, r1, 0
	bl sub_800ECB8
	adds r4, r0, 0
	ldr r0, [r4, 0x20]
	bl sub_800ECD0
	adds r1, r0, 0
	movs r2, 0
	ldr r0, [r4, 0x1C]
	cmp r2, r0
	bge _0800E748
	adds r3, r0, 0
_0800E734:
	movs r6, 0
	ldrsh r0, [r1, r6]
	cmp r0, r5
	bne _0800E740
	ldr r0, [r1, 0x4]
	b _0800E74A
_0800E740:
	adds r2, 0x1
	adds r1, 0xC
	cmp r2, r3
	blt _0800E734
_0800E748:
	ldr r0, [r4, 0x14]
_0800E74A:
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end sub_800E710

	thumb_func_start sub_800E750
sub_800E750:
	push {r4-r6,lr}
	lsls r0, 16
	asrs r5, r0, 16
	lsls r1, 16
	lsrs r1, 16
	adds r0, r1, 0
	bl sub_800ECB8
	adds r4, r0, 0
	ldr r0, [r4, 0x20]
	bl sub_800ECD0
	adds r1, r0, 0
	movs r2, 0
	ldr r0, [r4, 0x1C]
	cmp r2, r0
	bge _0800E788
	adds r3, r0, 0
_0800E774:
	movs r6, 0
	ldrsh r0, [r1, r6]
	cmp r0, r5
	bne _0800E780
	ldr r0, [r1, 0x4]
	b _0800E78A
_0800E780:
	adds r2, 0x1
	adds r1, 0xC
	cmp r2, r3
	blt _0800E774
_0800E788:
	ldr r0, [r4, 0x14]
_0800E78A:
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end sub_800E750

	thumb_func_start sub_800E790
sub_800E790:
	push {r4-r6,lr}
	lsls r0, 16
	asrs r5, r0, 16
	lsls r1, 16
	lsrs r1, 16
	adds r0, r1, 0
	bl sub_800ECB8
	adds r4, r0, 0
	ldr r0, [r4, 0x20]
	bl sub_800ECD0
	adds r1, r0, 0
	movs r2, 0
	ldr r0, [r4, 0x1C]
	cmp r2, r0
	bge _0800E7C8
	adds r3, r0, 0
_0800E7B4:
	movs r6, 0
	ldrsh r0, [r1, r6]
	cmp r0, r5
	bne _0800E7C0
	ldr r0, [r1, 0x8]
	b _0800E7CA
_0800E7C0:
	adds r2, 0x1
	adds r1, 0xC
	cmp r2, r3
	blt _0800E7B4
_0800E7C8:
	ldr r0, [r4, 0x18]
_0800E7CA:
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end sub_800E790

        .align 2,0
