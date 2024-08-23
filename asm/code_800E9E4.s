	#include "asm/constants/gba_constants.inc"
  	#include "asm/macros.inc"

  	.syntax unified

  	.text

	thumb_func_start sub_800EA44
sub_800EA44:
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
	bge _0800EA7C
	adds r3, r0, 0
_0800EA68:
	movs r6, 0
	ldrsh r0, [r1, r6]
	cmp r0, r5
	bne _0800EA74
	ldrb r0, [r1, 0x2]
	b _0800EA7E
_0800EA74:
	adds r2, 0x1
	adds r1, 0xC
	cmp r2, r3
	blt _0800EA68
_0800EA7C:
	ldrb r0, [r4, 0x10]
_0800EA7E:
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end sub_800EA44

	thumb_func_start sub_800EA84
sub_800EA84:
	push {r4,lr}
	sub sp, 0x50
	adds r4, r0, 0
	ldrh r0, [r4]
	bl sub_800ECB8
	movs r1, 0
	ldrsh r0, [r0, r1]
	str r0, [sp, 0x28]
	ldr r0, [r4, 0x10]
	str r0, [sp, 0x2C]
	ldr r0, [r4, 0xC]
	str r0, [sp, 0x30]
	ldr r0, [r4, 0x4]
	str r0, [sp, 0x34]
	ldr r0, [r4, 0x8]
	str r0, [sp, 0x38]
	ldrh r0, [r4]
	bl sub_800ECB8
	movs r2, 0
	ldrsh r0, [r0, r2]
	bl sub_800EBBC
	str r0, [sp, 0x3C]
	ldr r0, _0800EADC
	str r0, [sp, 0x40]
	add r1, sp, 0x44
	ldr r0, _0800EAE0
	ldm r0!, {r2-r4}
	stm r1!, {r2-r4}
	add r1, sp, 0x28
	mov r0, sp
	movs r2, 0x28
	bl memcpy
	movs r0, 0x5
	mov r1, sp
	bl sub_800E208
	add sp, 0x50
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_0800EADC: .4byte 0x0000ffff
_0800EAE0: .4byte gUnknown_80B9C60
	thumb_func_end sub_800EA84

	thumb_func_start sub_800EAE4
sub_800EAE4:
	push {r4,r5,lr}
	adds r4, r1, 0
	adds r5, r2, 0
	bl sub_800E2C0
	adds r1, r0, 0
	movs r3, 0x1
	negs r3, r3
	cmp r1, r3
	beq _0800EB1E
	ldr r2, _0800EB14
	movs r0, 0xD0
	muls r1, r0
	ldr r0, [r2]
	adds r1, r0, r1
	ldr r0, [r4]
	str r0, [r1, 0x18]
	ldr r0, [r1, 0x20]
	cmp r0, r3
	beq _0800EB18
	ldr r0, [r5]
	str r0, [r1, 0x1C]
	b _0800EB1E
	.align 2, 0
_0800EB14: .4byte gUnknown_203B0CC
_0800EB18:
	movs r0, 0
	strh r0, [r1, 0x1C]
	strh r0, [r1, 0x1E]
_0800EB1E:
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_800EAE4

	thumb_func_start sub_800EB24
sub_800EB24:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0x20
	adds r6, r1, 0
	mov r8, r2
	adds r5, r3, 0
	ldr r4, [sp, 0x38]
	bl sub_800E2C0
	adds r1, r0, 0
	movs r0, 0x1
	negs r0, r0
	cmp r1, r0
	beq _0800EBB0
	ldr r2, _0800EB8C
	movs r0, 0xD0
	muls r1, r0
	ldr r0, [r2]
	adds r2, r0, r1
	adds r0, r2, 0
	adds r0, 0xCC
	ldr r0, [r0]
	cmp r0, 0
	bne _0800EB5A
	ldr r0, [r6]
	str r0, [r2, 0x18]
_0800EB5A:
	ldr r0, [r2]
	cmp r0, 0x6
	beq _0800EB94
	ldr r0, [r2, 0x8]
	movs r1, 0x7
	mov r12, r1
	ands r0, r1
	cmp r0, 0
	bne _0800EB94
	mov r1, sp
	ldr r0, _0800EB90
	ldm r0!, {r3,r6,r7}
	stm r1!, {r3,r6,r7}
	ldm r0!, {r3,r6,r7}
	stm r1!, {r3,r6,r7}
	ldm r0!, {r3,r6}
	stm r1!, {r3,r6}
	mov r7, r12
	ands r4, r7
	lsls r0, r4, 2
	add r0, sp
	ldr r0, [r0]
	adds r0, r5, r0
	b _0800EB96
	.align 2, 0
_0800EB8C: .4byte gUnknown_203B0CC
_0800EB90: .4byte gUnknown_80B9C9C
_0800EB94:
	adds r0, r5, 0x1
_0800EB96:
	str r0, [r2, 0x24]
	ldr r1, [r2, 0x20]
	movs r0, 0x1
	negs r0, r0
	cmp r1, r0
	beq _0800EBAA
	mov r1, r8
	ldr r0, [r1]
	str r0, [r2, 0x1C]
	b _0800EBB0
_0800EBAA:
	movs r0, 0
	strh r0, [r2, 0x1C]
	strh r0, [r2, 0x1E]
_0800EBB0:
	add sp, 0x20
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_800EB24

	thumb_func_start sub_800EBBC
sub_800EBBC:
	push {lr}
	bl sub_800ECA4
	ldr r0, [r0, 0x1C]
	pop {r1}
	bx r1
	thumb_func_end sub_800EBBC

	thumb_func_start sub_800EBC8
sub_800EBC8:
	push {r4,lr}
	sub sp, 0x50
	adds r4, r0, 0
	ldrh r0, [r4]
	bl sub_800ECB8
	movs r1, 0x4
	ldrsh r0, [r0, r1]
	str r0, [sp, 0x28]
	ldr r0, [r4, 0x10]
	str r0, [sp, 0x2C]
	ldr r0, [r4, 0xC]
	str r0, [sp, 0x30]
	ldr r0, [r4, 0x4]
	str r0, [sp, 0x34]
	ldr r0, [r4, 0x8]
	str r0, [sp, 0x38]
	ldrh r0, [r4]
	bl sub_800ECB8
	movs r2, 0x4
	ldrsh r0, [r0, r2]
	bl sub_800EC68
	str r0, [sp, 0x3C]
	ldr r0, _0800EC20
	str r0, [sp, 0x40]
	add r1, sp, 0x44
	ldr r0, _0800EC24
	ldm r0!, {r2-r4}
	stm r1!, {r2-r4}
	add r1, sp, 0x28
	mov r0, sp
	movs r2, 0x28
	bl memcpy
	movs r0, 0x6
	mov r1, sp
	bl sub_800E208
	add sp, 0x50
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_0800EC20: .4byte 0x0000ffff
_0800EC24: .4byte gUnknown_80B9C60
	thumb_func_end sub_800EBC8

	thumb_func_start sub_800EC28
sub_800EC28:
	push {r4,r5,lr}
	adds r4, r1, 0
	adds r5, r2, 0
	bl sub_800E2C0
	adds r1, r0, 0
	movs r3, 0x1
	negs r3, r3
	cmp r1, r3
	beq _0800EC62
	ldr r2, _0800EC58
	movs r0, 0xD0
	muls r1, r0
	ldr r0, [r2]
	adds r1, r0, r1
	ldr r0, [r4]
	str r0, [r1, 0x18]
	ldr r0, [r1, 0x20]
	cmp r0, r3
	beq _0800EC5C
	ldr r0, [r5]
	str r0, [r1, 0x1C]
	b _0800EC62
	.align 2, 0
_0800EC58: .4byte gUnknown_203B0CC
_0800EC5C:
	movs r0, 0
	strh r0, [r1, 0x1C]
	strh r0, [r1, 0x1E]
_0800EC62:
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_800EC28

	thumb_func_start sub_800EC68
sub_800EC68:
	push {lr}
	bl sub_800ECA4
	ldr r0, [r0, 0x1C]
	pop {r1}
	bx r1
	thumb_func_end sub_800EC68

	thumb_func_start sub_800EC74
sub_800EC74:
	push {lr}
	movs r0, 0x1
	bl sub_800F19C
	lsls r0, 24
	lsrs r0, 24
	pop {r1}
	bx r1
	thumb_func_end sub_800EC74

	thumb_func_start sub_800EC84
sub_800EC84:
	push {lr}
	lsls r0, 16
	lsrs r0, 16
	bl sub_800ECB8
	ldrb r0, [r0, 0x8]
	pop {r1}
	bx r1
	thumb_func_end sub_800EC84

	thumb_func_start sub_800EC94
sub_800EC94:
	push {lr}
	lsls r0, 16
	lsrs r0, 16
	bl sub_800ECB8
	ldrb r0, [r0, 0x9]
	pop {r1}
	bx r1
	thumb_func_end sub_800EC94

	thumb_func_start sub_800ECA4
sub_800ECA4:
	adds r1, r0, 0
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 2
	ldr r1, _0800ECB4
	adds r0, r1
	bx lr
	.align 2, 0
_0800ECB4: .4byte gUnknown_80B9CC4
	thumb_func_end sub_800ECA4

	thumb_func_start sub_800ECB8
sub_800ECB8:
	adds r1, r0, 0
	lsls r1, 16
	lsrs r1, 16
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 2
	ldr r1, _0800ECCC
	adds r0, r1
	bx lr
	.align 2, 0
_0800ECCC: .4byte gUnknown_80BDBC4
	thumb_func_end sub_800ECB8

	thumb_func_start sub_800ECD0
sub_800ECD0:
	adds r1, r0, 0
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 2
	ldr r1, _0800ECE0
	adds r0, r1
	bx lr
	.align 2, 0
_0800ECE0: .4byte gUnknown_80C183C
	thumb_func_end sub_800ECD0

	thumb_func_start sub_800ECE4
sub_800ECE4:
	lsls r0, 24
	ldr r1, _0800ECF4
	lsrs r0, 23
	adds r0, r1
	movs r1, 0
	ldrsh r0, [r0, r1]
	bx lr
	.align 2, 0
_0800ECF4: .4byte gUnknown_80CE73C
	thumb_func_end sub_800ECE4

	thumb_func_start sub_800ECF8
sub_800ECF8:
	lsls r0, 24
	ldr r1, _0800ED08
	lsrs r0, 22
	adds r0, r1
	movs r1, 0
	ldrsh r0, [r0, r1]
	bx lr
	.align 2, 0
_0800ED08: .4byte gUnknown_80CE37C
	thumb_func_end sub_800ECF8

	thumb_func_start sub_800ED0C
sub_800ED0C:
	lsls r0, 24
	ldr r1, _0800ED1C
	lsrs r0, 22
	adds r0, r1
	movs r1, 0x2
	ldrsh r0, [r0, r1]
	bx lr
	.align 2, 0
_0800ED1C: .4byte gUnknown_80CE37C
	thumb_func_end sub_800ED0C

	thumb_func_start sub_800ED20
sub_800ED20:
	lsls r0, 16
	lsrs r0, 16
	ldr r2, _0800ED34
	lsls r1, r0, 3
	adds r1, r0
	lsls r1, 2
	adds r2, 0xC
	adds r1, r2
	ldr r0, [r1]
	bx lr
	.align 2, 0
_0800ED34: .4byte gUnknown_80BDBC4
	thumb_func_end sub_800ED20

        .align 2,0
