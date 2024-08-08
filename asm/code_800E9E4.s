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

	thumb_func_start sub_800ED38
sub_800ED38:
	push {r4,r5,lr}
	adds r5, r0, 0
	ldr r4, _0800ED60
	ldr r0, [r4]
	cmp r0, 0
	bne _0800ED54
	movs r0, 0x4C
	movs r1, 0xB
	bl MemoryAlloc
	str r0, [r4]
	movs r1, 0x4C
	bl MemoryClear8
_0800ED54:
	ldr r0, [r4]
	str r5, [r0]
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_0800ED60: .4byte gUnknown_203B0D0
	thumb_func_end sub_800ED38

	thumb_func_start sub_800ED64
sub_800ED64:
	push {r4,lr}
	ldr r4, _0800ED7C
	ldr r0, [r4]
	cmp r0, 0
	beq _0800ED76
	bl MemoryFree
	movs r0, 0
	str r0, [r4]
_0800ED76:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0800ED7C: .4byte gUnknown_203B0D0
	thumb_func_end sub_800ED64

	thumb_func_start sub_800ED80
sub_800ED80:
	push {r4,lr}
	ldr r2, _0800EDAC
	ldr r1, [r2]
	movs r0, 0
	str r0, [r1]
	adds r4, r2, 0
	movs r3, 0
	movs r2, 0x4
	movs r1, 0x1
_0800ED92:
	ldr r0, [r4]
	adds r0, r2
	str r3, [r0]
	str r3, [r0, 0x4]
	str r3, [r0, 0x8]
	adds r2, 0x24
	subs r1, 0x1
	cmp r1, 0
	bge _0800ED92
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0800EDAC: .4byte gUnknown_203B0D0
	thumb_func_end sub_800ED80

	thumb_func_start sub_800EDB0
sub_800EDB0:
	push {r4,r5,lr}
	adds r4, r0, 0
	movs r3, 0
	ldr r5, _0800EDDC
	movs r2, 0
_0800EDBA:
	ldr r1, [r5]
	adds r0, r1, 0x4
	adds r0, r2
	ldr r0, [r0]
	cmp r0, 0
	bne _0800EDE0
	adds r1, r2
	adds r1, 0x4
	adds r0, r4, 0
	ldm r0!, {r2-r4}
	stm r1!, {r2-r4}
	ldm r0!, {r2-r4}
	stm r1!, {r2-r4}
	ldm r0!, {r2-r4}
	stm r1!, {r2-r4}
	movs r0, 0x1
	b _0800EDEA
	.align 2, 0
_0800EDDC: .4byte gUnknown_203B0D0
_0800EDE0:
	adds r2, 0x24
	adds r3, 0x1
	cmp r3, 0x1
	ble _0800EDBA
	movs r0, 0
_0800EDEA:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_800EDB0

	thumb_func_start sub_800EDF0
sub_800EDF0:
	push {r4,lr}
	sub sp, 0x24
	adds r4, r1, 0
	cmp r0, 0
	beq _0800EE00
	cmp r0, 0x1
	beq _0800EE1A
	b _0800EE44
_0800EE00:
	movs r0, 0x3
	str r0, [sp]
	movs r0, 0xE
	str r0, [sp, 0xC]
	movs r1, 0x1
	negs r1, r1
	str r1, [sp, 0x10]
	movs r0, 0xDC
	lsls r0, 2
	str r0, [sp, 0x18]
	movs r0, 0x1F
	str r0, [sp, 0x1C]
	b _0800EE40
_0800EE1A:
	movs r0, 0x4
	str r0, [sp]
	movs r0, 0xE
	str r0, [sp, 0xC]
	movs r0, 0xF0
	lsls r0, 4
	str r0, [sp, 0x10]
	movs r0, 0x1
	negs r0, r0
	str r0, [sp, 0x18]
	str r0, [sp, 0x1C]
	bl sub_8000728
	movs r2, 0x2
	eors r0, r2
	negs r1, r0
	orrs r1, r0
	asrs r1, 31
	ands r1, r2
_0800EE40:
	str r1, [sp, 0x14]
	str r4, [sp, 0x4]
_0800EE44:
	ldr r0, [r4, 0x4]
	str r0, [sp, 0x8]
	movs r0, 0
	str r0, [sp, 0x20]
	mov r0, sp
	bl sub_800EDB0
	add sp, 0x24
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_800EDF0

	thumb_func_start sub_800EE5C
sub_800EE5C:
	push {r4-r6,lr}
	adds r4, r0, 0
	bl sub_800ECA4
	adds r6, r0, 0
	cmp r4, 0
	beq _0800EEC2
	ldr r2, [r6]
	subs r0, r2, 0x1
	cmp r0, 0x1
	bls _0800EEC2
	ldr r1, [r6, 0x4]
	adds r0, r2, 0
	bl sub_800F1C0
	adds r5, r0, 0
	cmp r5, 0
	beq _0800EEC2
	ldr r0, [r6]
	ldr r1, [r6, 0x4]
	bl sub_800F0F4
	adds r4, r0, 0
	movs r0, 0x1
	negs r0, r0
	cmp r4, r0
	bne _0800EE9A
	adds r0, r5, 0
	bl sub_800F204
	b _0800EEC2
_0800EE9A:
	movs r0, 0x2
	negs r0, r0
	cmp r4, r0
	beq _0800EEB6
	adds r0, r4, 0
	adds r1, r5, 0
	adds r2, r6, 0
	bl sub_800F13C
	adds r0, r4, 0
	adds r1, r5, 0
	bl sub_800EDF0
	b _0800EEBC
_0800EEB6:
	adds r0, r5, 0
	bl sub_800F204
_0800EEBC:
	ldr r0, [r6, 0x4]
	bl sub_800F15C
_0800EEC2:
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end sub_800EE5C

	thumb_func_start sub_800EEC8
sub_800EEC8:
	push {lr}
	lsls r0, 16
	lsrs r0, 16
	bl sub_800ECB8
	movs r1, 0
	ldrsh r0, [r0, r1]
	bl sub_800EE5C
	pop {r0}
	bx r0
	thumb_func_end sub_800EEC8

	thumb_func_start sub_800EEE0
sub_800EEE0:
	push {lr}
	lsls r0, 16
	lsrs r0, 16
	bl sub_800ECB8
	movs r1, 0x4
	ldrsh r0, [r0, r1]
	bl sub_800EE5C
	pop {r0}
	bx r0
	thumb_func_end sub_800EEE0

	thumb_func_start sub_800EEF8
sub_800EEF8:
	push {lr}
	lsls r0, 16
	lsrs r0, 16
	bl sub_800ECB8
	movs r1, 0x2
	ldrsh r0, [r0, r1]
	bl sub_800EE5C
	pop {r0}
	bx r0
	thumb_func_end sub_800EEF8

	thumb_func_start sub_800EF10
sub_800EF10:
	push {lr}
	lsls r0, 16
	lsrs r0, 16
	bl sub_800ECB8
	movs r1, 0x6
	ldrsh r0, [r0, r1]
	bl sub_800EE5C
	pop {r0}
	bx r0
	thumb_func_end sub_800EF10

	thumb_func_start sub_800EF28
sub_800EF28:
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	bl sub_800ECE4
	lsls r0, 16
	asrs r0, 16
	bl sub_800EE5C
	pop {r0}
	bx r0
	thumb_func_end sub_800EF28

	thumb_func_start sub_800EF40
sub_800EF40:
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	lsls r1, 24
	cmp r1, 0
	beq _0800EF52
	bl sub_800ECF8
	b _0800EF56
_0800EF52:
	bl sub_800ED0C
_0800EF56:
	lsls r0, 16
	asrs r0, 16
	bl sub_800EE5C
	pop {r0}
	bx r0
	thumb_func_end sub_800EF40

	thumb_func_start sub_800EF64
sub_800EF64:
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	ldr r0, _0800EF9C
	mov r9, r0
	movs r1, 0x4
	mov r8, r1
	movs r7, 0
	movs r6, 0
	movs r5, 0x1
_0800EF7A:
	mov r0, r9
	ldr r1, [r0]
	adds r0, r1, 0x4
	adds r0, r7
	ldr r0, [r0]
	cmp r0, 0
	beq _0800F01A
	mov r0, r8
	adds r4, r1, r0
	ldr r0, [r4]
	cmp r0, 0x3
	beq _0800EFA0
	cmp r0, 0x3
	bls _0800F018
	cmp r0, 0x4
	beq _0800EFDA
	b _0800F018
	.align 2, 0
_0800EF9C: .4byte gUnknown_203B0D0
_0800EFA0:
	ldr r0, [r4, 0x8]
	ldr r1, [r4, 0x18]
	bl sub_8005674
	mov r1, r9
	ldr r0, [r1]
	ldr r0, [r0]
	cmp r0, 0
	beq _0800EFCA
	cmp r0, 0x1
	bne _0800F00C
	ldr r0, [r4, 0x8]
	ldr r1, [r0, 0x18]
	ldr r0, [r4, 0xC]
	adds r0, 0x10
	lsls r0, 20
	lsrs r0, 16
	movs r2, 0x10
	bl sub_809971C
	b _0800F00C
_0800EFCA:
	ldr r0, [r4, 0xC]
	ldr r1, [r4, 0x8]
	ldr r1, [r1, 0x18]
	ldr r2, [r4, 0x1C]
	ldr r3, [r4, 0x20]
	bl sub_8005770
	b _0800F00C
_0800EFDA:
	bl sub_8000728
	cmp r0, 0x1
	bne _0800F000
	movs r0, 0
	movs r1, 0x1
	bl sub_800CD64
	movs r0, 0
	bl sub_8052210
	movs r0, 0x5
	movs r1, 0
	bl sub_803EAF0
	bl sub_800CB20
	bl xxx_call_update_bg_vram
_0800F000:
	ldr r0, [r4, 0x8]
	ldr r1, [r4, 0xC]
	ldr r2, [r4, 0x10]
	ldr r3, [r4, 0x14]
	bl sub_8009A1C
_0800F00C:
	ldr r0, [r4, 0x4]
	cmp r0, 0
	beq _0800F018
	bl sub_800F204
	str r6, [r4, 0x4]
_0800F018:
	str r6, [r4]
_0800F01A:
	movs r0, 0x24
	add r8, r0
	adds r7, 0x24
	subs r5, 0x1
	cmp r5, 0
	bge _0800EF7A
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_800EF64

	thumb_func_start sub_800F034
sub_800F034:
	push {r4-r6,lr}
	ldr r4, _0800F074
	ldr r0, [r4]
	cmp r0, 0
	bne _0800F04E
	movs r0, 0x10
	movs r1, 0xB
	bl MemoryAlloc
	str r0, [r4]
	movs r1, 0x10
	bl MemoryClear8
_0800F04E:
	movs r3, 0
	adds r6, r4, 0
	movs r5, 0x1
	negs r5, r5
	movs r4, 0
_0800F058:
	ldr r0, [r6]
	lsls r2, r3, 3
	adds r1, r0, r2
	str r5, [r1]
	adds r0, 0x4
	adds r0, r2
	str r4, [r0]
	adds r3, 0x1
	cmp r3, 0x1
	ble _0800F058
	pop {r4-r6}
	pop {r0}
	bx r0
	.align 2, 0
_0800F074: .4byte gUnknown_203B0D4
	thumb_func_end sub_800F034

	thumb_func_start sub_800F078
sub_800F078:
	push {r4,lr}
	ldr r4, _0800F090
	ldr r0, [r4]
	cmp r0, 0
	beq _0800F08A
	bl MemoryFree
	movs r0, 0
	str r0, [r4]
_0800F08A:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0800F090: .4byte gUnknown_203B0D4
	thumb_func_end sub_800F078

	thumb_func_start sub_800F094
sub_800F094:
	push {r4-r6,lr}
	movs r3, 0
	ldr r6, _0800F0BC
	movs r5, 0x1
	negs r5, r5
	movs r4, 0
_0800F0A0:
	ldr r0, [r6]
	lsls r2, r3, 3
	adds r1, r0, r2
	str r5, [r1]
	adds r0, 0x4
	adds r0, r2
	str r4, [r0]
	adds r3, 0x1
	cmp r3, 0x1
	ble _0800F0A0
	pop {r4-r6}
	pop {r0}
	bx r0
	.align 2, 0
_0800F0BC: .4byte gUnknown_203B0D4
	thumb_func_end sub_800F094

	thumb_func_start sub_800F0C0
sub_800F0C0:
	push {lr}
	cmp r0, 0x3
	bne _0800F0D8
	ldr r0, _0800F0D4
	ldr r0, [r0]
	ldr r0, [r0]
	cmp r0, r1
	bne _0800F0EC
	movs r0, 0
	b _0800F0F0
	.align 2, 0
_0800F0D4: .4byte gUnknown_203B0D4
_0800F0D8:
	ldr r0, _0800F0E8
	ldr r0, [r0]
	ldr r0, [r0, 0x8]
	cmp r0, r1
	bne _0800F0EC
	movs r0, 0x1
	b _0800F0F0
	.align 2, 0
_0800F0E8: .4byte gUnknown_203B0D4
_0800F0EC:
	movs r0, 0x3
	negs r0, r0
_0800F0F0:
	pop {r1}
	bx r1
	thumb_func_end sub_800F0C0

	thumb_func_start sub_800F0F4
sub_800F0F4:
	push {lr}
	cmp r0, 0x3
	bne _0800F114
	ldr r0, _0800F110
	ldr r2, [r0]
	ldr r0, [r2]
	cmp r0, r1
	beq _0800F11E
	ldr r0, [r2, 0x4]
	cmp r0, 0
	bne _0800F132
	movs r0, 0
	b _0800F136
	.align 2, 0
_0800F110: .4byte gUnknown_203B0D4
_0800F114:
	ldr r0, _0800F124
	ldr r2, [r0]
	ldr r0, [r2, 0x8]
	cmp r0, r1
	bne _0800F128
_0800F11E:
	movs r0, 0x2
	negs r0, r0
	b _0800F136
	.align 2, 0
_0800F124: .4byte gUnknown_203B0D4
_0800F128:
	ldr r0, [r2, 0xC]
	cmp r0, 0
	bne _0800F132
	movs r0, 0x1
	b _0800F136
_0800F132:
	movs r0, 0x1
	negs r0, r0
_0800F136:
	pop {r1}
	bx r1
	thumb_func_end sub_800F0F4

	thumb_func_start sub_800F13C
sub_800F13C:
	push {lr}
	ldr r1, _0800F158
	ldr r3, [r1]
	lsls r1, r0, 3
	adds r0, r3, 0x4
	adds r0, r1
	ldr r0, [r0]
	cmp r0, 0
	bne _0800F154
	adds r1, r3, r1
	ldr r0, [r2, 0x4]
	str r0, [r1]
_0800F154:
	pop {r0}
	bx r0
	.align 2, 0
_0800F158: .4byte gUnknown_203B0D4
	thumb_func_end sub_800F13C

	thumb_func_start sub_800F15C
sub_800F15C:
	push {r4,r5,lr}
	adds r4, r0, 0
	movs r3, 0
	ldr r5, _0800F17C
_0800F164:
	ldr r1, [r5]
	lsls r2, r3, 3
	adds r0, r1, r2
	ldr r0, [r0]
	cmp r0, r4
	bne _0800F180
	adds r1, 0x4
	adds r1, r2
	ldr r0, [r1]
	adds r0, 0x1
	str r0, [r1]
	b _0800F186
	.align 2, 0
_0800F17C: .4byte gUnknown_203B0D4
_0800F180:
	adds r3, 0x1
	cmp r3, 0x1
	ble _0800F164
_0800F186:
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_800F15C

	thumb_func_start sub_800F18C
sub_800F18C:
	ldr r1, _0800F198
	lsls r0, 3
	ldr r1, [r1]
	adds r1, r0
	adds r0, r1, 0
	bx lr
	.align 2, 0
_0800F198: .4byte gUnknown_203B0D4
	thumb_func_end sub_800F18C

	thumb_func_start sub_800F19C
sub_800F19C:
	push {lr}
	ldr r1, _0800F1B4
	ldr r1, [r1]
	lsls r0, 3
	adds r1, 0x4
	adds r1, r0
	ldr r0, [r1]
	cmp r0, 0
	beq _0800F1B8
	movs r0, 0x1
	b _0800F1BA
	.align 2, 0
_0800F1B4: .4byte gUnknown_203B0D4
_0800F1B8:
	movs r0, 0
_0800F1BA:
	pop {r1}
	bx r1
	thumb_func_end sub_800F19C

	thumb_func_start sub_800F1C0
sub_800F1C0:
	push {lr}
	sub sp, 0x8
	adds r2, r1, 0
	cmp r0, 0x1
	bcc _0800F1EC
	cmp r0, 0x3
	bls _0800F1D4
	cmp r0, 0x4
	beq _0800F1E4
	b _0800F1EC
_0800F1D4:
	ldr r1, _0800F1E0
	mov r0, sp
	bl sprintf
	b _0800F1EC
	.align 2, 0
_0800F1E0: .4byte gUnknown_80CE77C
_0800F1E4:
	ldr r1, _0800F1FC
	mov r0, sp
	bl sprintf
_0800F1EC:
	ldr r1, _0800F200
	mov r0, sp
	bl Call_OpenFileAndGetFileDataPtr
	add sp, 0x8
	pop {r1}
	bx r1
	.align 2, 0
_0800F1FC: .4byte gUnknown_80CE788
_0800F200: .4byte gEffectFileArchive
	thumb_func_end sub_800F1C0

	thumb_func_start sub_800F204
sub_800F204:
	push {lr}
	bl CloseFile
	pop {r0}
	bx r0
	thumb_func_end sub_800F204

	thumb_func_start GetDungeonPokemonSprite
    @ DungeonPokemonSprite *GetDungeonPokemonSprite(int id)
GetDungeonPokemonSprite:
	push {r4,lr}
	adds r4, r0, 0
	movs r3, 0
	ldr r0, _0800F230
	ldr r0, [r0]
	adds r1, r0, 0x4
	adds r2, r0, 0
	adds r2, 0x8
_0800F220:
	ldrb r0, [r1]
	cmp r0, 0
	beq _0800F234
	ldr r0, [r2]
	cmp r0, r4
	bne _0800F234
	adds r0, r1, 0
	b _0800F240
	.align 2, 0
_0800F230: .4byte gDungeonPokemonSprites
_0800F234:
	adds r1, 0x40
	adds r2, 0x40
	adds r3, 0x1
	cmp r3, 0x15
	ble _0800F220
	movs r0, 0
_0800F240:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end GetDungeonPokemonSprite

	thumb_func_start NewDungeonPokemonSprite
    @ DungeonPokemonSprite *NewDungeonPokemonSprite(void)
NewDungeonPokemonSprite:
	push {lr}
	movs r2, 0
	ldr r0, _0800F25C
	ldr r0, [r0]
	adds r1, r0, 0x4
_0800F252:
	ldrb r0, [r1]
	cmp r0, 0
	bne _0800F260
	adds r0, r1, 0
	b _0800F26A
	.align 2, 0
_0800F25C: .4byte gDungeonPokemonSprites
_0800F260:
	adds r1, 0x40
	adds r2, 0x1
	cmp r2, 0x15
	ble _0800F252
	movs r0, 0
_0800F26A:
	pop {r1}
	bx r1
	thumb_func_end NewDungeonPokemonSprite

	thumb_func_start GetNextStatusSymbol
    @ u32 GetNextStatusSymbol(?, int select)
    @ The "select" parameter exists to differentiate between the two kinds of
    @ status symbols that can appear at the same time.
    @ Only frozen falls under select = 1, every other symbol falls under select = 0
GetNextStatusSymbol:
	push {r4-r6,lr}
	adds r2, r0, 0
	lsls r0, r1, 3
	adds r0, 0x28
	adds r3, r2, r0
	movs r5, 0x80
	lsls r5, 21
	cmp r1, 0
	bne _0800F284
	movs r5, 0x1
_0800F284:
	movs r6, 0x80
	lsls r6, 21
	cmp r1, 0
	bne _0800F290
	movs r6, 0x80
	lsls r6, 20
_0800F290:
	movs r4, 0x1
	cmp r1, 0
	bne _0800F298
	movs r4, 0x1C
_0800F298:
	ldr r0, [r2, 0xC]
	cmp r0, 0
	bne _0800F2A4
	b _0800F2CC
_0800F2A0:
	adds r0, r1, 0
	b _0800F2CE
_0800F2A4:
	ldr r2, [r3]
	adds r1, r5, 0
	cmp r2, 0
	beq _0800F2AE
	adds r1, r2, 0
_0800F2AE:
	movs r2, 0
	cmp r2, r4
	bge _0800F2CC
	adds r3, r0, 0
_0800F2B6:
	lsls r1, 1
	cmp r1, r6
	bls _0800F2BE
	adds r1, r5, 0
_0800F2BE:
	adds r0, r3, 0
	ands r0, r1
	cmp r0, 0
	bne _0800F2A0
	adds r2, 0x1
	cmp r2, r4
	blt _0800F2B6
_0800F2CC:
	movs r0, 0
_0800F2CE:
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end GetNextStatusSymbol

	thumb_func_start StatusSymbolBitToIndex
StatusSymbolBitToIndex:
	push {lr}
	movs r1, 0
	cmp r0, 0
	beq _0800F2E4
_0800F2DC:
	lsrs r0, 1
	adds r1, 0x1
	cmp r0, 0
	bne _0800F2DC
_0800F2E4:
	adds r0, r1, 0
	pop {r1}
	bx r1
	thumb_func_end StatusSymbolBitToIndex

	thumb_func_start sub_800F2EC
sub_800F2EC:
	push {r4-r7,lr}
	sub sp, 0xC
	adds r5, r0, 0
	adds r6, r1, 0
	adds r7, r2, 0
	lsls r0, r6, 3
	adds r0, 0x28
	adds r4, r5, r0
	ldr r0, [r5, 0xC]
	cmp r0, 0
	bne _0800F306
	str r0, [r4]
	b _0800F35C
_0800F306:
	ldr r0, [r4]
	cmp r0, 0
	bne _0800F30E
	str r0, [r4, 0x4]
_0800F30E:
	ldr r0, [r4, 0x4]
	cmp r0, 0
	bgt _0800F32A
	adds r0, r5, 0
	adds r1, r6, 0
	bl GetNextStatusSymbol
	adds r1, r0, 0
	ldr r0, [r4]
	cmp r0, r1
	beq _0800F326
	str r1, [r4]
_0800F326:
	movs r0, 0x3C
	b _0800F32C
_0800F32A:
	subs r0, 0x1
_0800F32C:
	str r0, [r4, 0x4]
	ldrb r0, [r5, 0x10]
	cmp r0, 0
	beq _0800F35C
	ldr r0, [r4]
	cmp r0, 0
	beq _0800F35C
	bl StatusSymbolBitToIndex
	adds r1, r0, 0
	movs r2, 0x8
	ldrsh r0, [r5, r2]
	adds r2, r5, 0
	adds r2, 0x14
	lsls r3, r6, 2
	adds r3, 0x18
	adds r3, r5, r3
	str r7, [sp]
	ldrb r4, [r5, 0x11]
	str r4, [sp, 0x4]
	ldr r4, [r5, 0x4]
	str r4, [sp, 0x8]
	bl DrawStatusSprite
_0800F35C:
	add sp, 0xC
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_800F2EC

	thumb_func_start DrawStatusSprite
    @ void DrawStatusSprite(?, int status, Position *pos, Position *pos_offset, Position *pos_screen, ?)
DrawStatusSprite:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0x8
	mov r12, r2
	ldr r0, [sp, 0x20]
	mov r8, r0
	ldr r4, [sp, 0x24]
	ldr r0, _0800F410
	lsls r1, 3
	adds r2, r1, r0
	ldr r0, [r2]
	ldr r1, [r2, 0x4]
	str r0, [sp]
	str r1, [sp, 0x4]
	lsls r2, r0, 1
	ldr r1, [sp]
	adds r2, r1
	lsls r2, 3
	ldr r0, _0800F414
	adds r2, r0
	ldr r0, [r2, 0x8]
	ldr r6, _0800F418
	adds r7, r0, r6
	movs r0, 0x3
	ands r4, r0
	lsls r4, 10
	ldr r5, _0800F41C
	ldrh r1, [r5, 0x4]
	ldr r0, _0800F420
	ands r0, r1
	orrs r0, r4
	strh r0, [r5, 0x4]
	mov r0, r12
	movs r4, 0
	ldrsh r1, [r0, r4]
	ldr r0, [r2]
	lsls r0, 2
	subs r1, r0
	mov r6, r8
	movs r4, 0
	ldrsh r0, [r6, r4]
	subs r1, r0
	movs r6, 0
	ldrsh r0, [r3, r6]
	adds r4, r1, r0
	mov r0, r12
	movs r6, 0x2
	ldrsh r1, [r0, r6]
	ldr r0, [r2, 0x4]
	lsls r0, 2
	subs r1, r0
	mov r2, r8
	movs r6, 0x2
	ldrsh r0, [r2, r6]
	subs r1, r0
	movs r2, 0x2
	ldrsh r0, [r3, r2]
	adds r3, r1, r0
	adds r6, r3, 0
	subs r6, 0x10
	movs r0, 0x20
	negs r0, r0
	cmp r4, r0
	bge _0800F3E8
	b _0800F5E4
_0800F3E8:
	cmp r3, r0
	bge _0800F3EE
	b _0800F5E4
_0800F3EE:
	cmp r4, 0xEF
	ble _0800F3F4
	b _0800F5E4
_0800F3F4:
	cmp r3, 0x9F
	ble _0800F3FA
	b _0800F5E4
_0800F3FA:
	ldr r0, [sp]
	subs r0, 0x1
	cmp r0, 0xF
	bls _0800F404
	b _0800F5A6
_0800F404:
	lsls r0, 2
	ldr r1, _0800F424
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0800F410: .4byte gStatusSprites
_0800F414: .4byte gStatusGraphics
_0800F418: .4byte 0x0000032b
_0800F41C: .4byte gUnknown_203B0DC
_0800F420: .4byte 0x0000f3ff
_0800F424: .4byte _0800F428
	.align 2, 0
_0800F428:
	.4byte _0800F468
	.4byte _0800F4CC
	.4byte _0800F4CC
	.4byte _0800F574
	.4byte _0800F538
	.4byte _0800F4CC
	.4byte _0800F4CC
	.4byte _0800F498
	.4byte _0800F4CC
	.4byte _0800F4CC
	.4byte _0800F4CC
	.4byte _0800F468
	.4byte _0800F4CC
	.4byte _0800F468
	.4byte _0800F4CC
	.4byte _0800F500
_0800F468:
	ldrh r2, [r5]
	ldr r1, _0800F48C
	adds r0, r1, 0
	ands r0, r2
	strh r0, [r5]
	ldrh r0, [r5, 0x2]
	ands r1, r0
	ldr r0, _0800F490
	ands r4, r0
	movs r0, 0xFE
	lsls r0, 8
	ands r1, r0
	orrs r1, r4
	strh r1, [r5, 0x2]
	ldr r1, _0800F494
	ands r1, r6
	b _0800F59A
	.align 2, 0
_0800F48C: .4byte 0x00003fff
_0800F490: .4byte 0x000001ff
_0800F494: .4byte 0x00000fff
_0800F498:
	movs r3, 0x80
	lsls r3, 8
	ldrh r2, [r5]
	ldr r1, _0800F4C0
	adds r0, r1, 0
	ands r0, r2
	orrs r0, r3
	strh r0, [r5]
	ldrh r0, [r5, 0x2]
	ands r1, r0
	ldr r0, _0800F4C4
	ands r4, r0
	movs r0, 0xFE
	lsls r0, 8
	ands r1, r0
	orrs r1, r4
	strh r1, [r5, 0x2]
	ldr r1, _0800F4C8
	ands r1, r6
	b _0800F59A
	.align 2, 0
_0800F4C0: .4byte 0x00003fff
_0800F4C4: .4byte 0x000001ff
_0800F4C8: .4byte 0x00000fff
_0800F4CC:
	ldrh r2, [r5]
	ldr r1, _0800F4F4
	adds r0, r1, 0
	ands r0, r2
	strh r0, [r5]
	movs r2, 0x80
	lsls r2, 7
	ldrh r0, [r5, 0x2]
	ands r1, r0
	orrs r1, r2
	ldr r0, _0800F4F8
	ands r4, r0
	movs r0, 0xFE
	lsls r0, 8
	ands r1, r0
	orrs r1, r4
	strh r1, [r5, 0x2]
	ldr r1, _0800F4FC
	ands r1, r6
	b _0800F59A
	.align 2, 0
_0800F4F4: .4byte 0x00003fff
_0800F4F8: .4byte 0x000001ff
_0800F4FC: .4byte 0x00000fff
_0800F500:
	ldrh r2, [r5]
	ldr r1, _0800F52C
	adds r0, r1, 0
	ands r0, r2
	strh r0, [r5]
	movs r2, 0x80
	lsls r2, 7
	ldrh r0, [r5, 0x2]
	ands r1, r0
	orrs r1, r2
	adds r2, r4, 0
	adds r2, 0x8
	ldr r0, _0800F530
	ands r2, r0
	movs r0, 0xFE
	lsls r0, 8
	ands r1, r0
	orrs r1, r2
	strh r1, [r5, 0x2]
	ldr r1, _0800F534
	ands r1, r6
	b _0800F59A
	.align 2, 0
_0800F52C: .4byte 0x00003fff
_0800F530: .4byte 0x000001ff
_0800F534: .4byte 0x00000fff
_0800F538:
	movs r3, 0x80
	lsls r3, 7
	ldrh r2, [r5]
	ldr r1, _0800F568
	adds r0, r1, 0
	ands r0, r2
	orrs r0, r3
	strh r0, [r5]
	movs r2, 0x80
	lsls r2, 8
	ldrh r0, [r5, 0x2]
	ands r1, r0
	orrs r1, r2
	ldr r0, _0800F56C
	ands r4, r0
	movs r0, 0xFE
	lsls r0, 8
	ands r1, r0
	orrs r1, r4
	strh r1, [r5, 0x2]
	ldr r1, _0800F570
	ands r1, r6
	b _0800F59A
	.align 2, 0
_0800F568: .4byte 0x00003fff
_0800F56C: .4byte 0x000001ff
_0800F570: .4byte 0x00000fff
_0800F574:
	ldrh r2, [r5]
	ldr r1, _0800F5F0
	adds r0, r1, 0
	ands r0, r2
	strh r0, [r5]
	movs r2, 0x80
	lsls r2, 8
	ldrh r0, [r5, 0x2]
	ands r1, r0
	orrs r1, r2
	ldr r0, _0800F5F4
	ands r4, r0
	movs r0, 0xFE
	lsls r0, 8
	ands r1, r0
	orrs r1, r4
	strh r1, [r5, 0x2]
	ldr r1, _0800F5F8
	ands r1, r3
_0800F59A:
	lsls r1, 4
	ldrh r2, [r5, 0x6]
	movs r0, 0xF
	ands r0, r2
	orrs r0, r1
	strh r0, [r5, 0x6]
_0800F5A6:
	ldr r0, _0800F5FC
	ands r7, r0
	ldrh r1, [r5, 0x4]
	movs r0, 0xFC
	lsls r0, 8
	ands r0, r1
	orrs r0, r7
	movs r1, 0xF
	ldr r3, [sp, 0x4]
	ands r1, r3
	lsls r1, 12
	ldr r2, _0800F5F8
	ands r0, r2
	orrs r0, r1
	strh r0, [r5, 0x4]
	mov r4, r12
	movs r6, 0x2
	ldrsh r1, [r4, r6]
	mov r2, r8
	movs r3, 0x2
	ldrsh r0, [r2, r3]
	subs r1, r0
	lsrs r0, r1, 31
	adds r1, r0
	asrs r1, 1
	adds r1, 0x1
	adds r0, r5, 0
	movs r2, 0
	movs r3, 0
	bl AddSprite
_0800F5E4:
	add sp, 0x8
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_0800F5F0: .4byte 0x00003fff
_0800F5F4: .4byte 0x000001ff
_0800F5F8: .4byte 0x00000fff
_0800F5FC: .4byte 0x000003ff
	thumb_func_end DrawStatusSprite

	thumb_func_start LoadStatusGraphics
LoadStatusGraphics:
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	lsls r1, 24
	lsrs r1, 24
	mov r9, r1
	lsls r1, r0, 1
	adds r1, r0
	lsls r1, 3
	ldr r0, _0800F660
	adds r1, r0
	ldr r7, [r1, 0x14]
	ldr r3, [r1, 0x10]
	ldr r2, [r1]
	ldr r0, [r1, 0x4]
	muls r0, r2
	lsls r4, r0, 5
	mov r8, r4
	ldr r0, [r1, 0x8]
	ldr r1, _0800F664
	adds r0, r1
	lsls r5, r0, 5
	adds r6, r5, 0
	ldr r0, _0800F668
	ldr r0, [r0]
	ldr r0, [r0]
	cmp r0, 0
	bge _0800F63C
	adds r0, 0x3
_0800F63C:
	asrs r0, 2
	adds r1, r3, 0
	bl __modsi3
	muls r0, r4
	ldr r1, _0800F66C
	adds r0, r1
	adds r1, r7, r0
	mov r2, r9
	cmp r2, 0
	beq _0800F674
	ldr r2, _0800F670
	adds r0, r5, r2
	adds r2, r4, 0
	bl sub_80098BC
	b _0800F67E
	.align 2, 0
_0800F660: .4byte gStatusGraphics
_0800F664: .4byte 0x0000032b
_0800F668: .4byte gDungeonPokemonSprites
_0800F66C: .4byte gStatusGraphics4bpp
_0800F670: .4byte 0x06010000
_0800F674:
	ldr r2, _0800F68C
	adds r0, r6, r2
	mov r2, r8
	bl CpuCopy
_0800F67E:
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_0800F68C: .4byte 0x06010000
	thumb_func_end LoadStatusGraphics

	thumb_func_start InitDungeonPokemonSprites
InitDungeonPokemonSprites:
	push {r4,r5,lr}
	ldr r5, _0800F738
	ldr r0, [r5]
	cmp r0, 0
	bne _0800F6AC
	ldr r4, _0800F73C
	adds r0, r4, 0
	movs r1, 0xC
	bl MemoryAlloc
	str r0, [r5]
	adds r1, r4, 0
	bl MemoryClear8
_0800F6AC:
	ldr r1, [r5]
	movs r0, 0
	str r0, [r1]
	movs r0, 0x1
	movs r1, 0
	bl LoadStatusGraphics
	movs r0, 0x2
	movs r1, 0
	bl LoadStatusGraphics
	movs r0, 0x3
	movs r1, 0
	bl LoadStatusGraphics
	movs r0, 0x4
	movs r1, 0
	bl LoadStatusGraphics
	movs r0, 0x5
	movs r1, 0
	bl LoadStatusGraphics
	movs r0, 0x6
	movs r1, 0
	bl LoadStatusGraphics
	movs r0, 0x7
	movs r1, 0
	bl LoadStatusGraphics
	movs r0, 0x8
	movs r1, 0
	bl LoadStatusGraphics
	movs r0, 0x9
	movs r1, 0
	bl LoadStatusGraphics
	movs r0, 0xA
	movs r1, 0
	bl LoadStatusGraphics
	movs r0, 0xB
	movs r1, 0
	bl LoadStatusGraphics
	movs r0, 0xC
	movs r1, 0
	bl LoadStatusGraphics
	movs r0, 0xD
	movs r1, 0
	bl LoadStatusGraphics
	movs r0, 0xE
	movs r1, 0
	bl LoadStatusGraphics
	movs r0, 0xF
	movs r1, 0
	bl LoadStatusGraphics
	movs r0, 0x10
	movs r1, 0
	bl LoadStatusGraphics
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_0800F738: .4byte gDungeonPokemonSprites
_0800F73C: .4byte 0x00000584
	thumb_func_end InitDungeonPokemonSprites

	thumb_func_start FreeDungeonPokemonSprites
FreeDungeonPokemonSprites:
	push {r4,lr}
	ldr r4, _0800F758
	ldr r0, [r4]
	cmp r0, 0
	beq _0800F752
	bl MemoryFree
	movs r0, 0
	str r0, [r4]
_0800F752:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0800F758: .4byte gDungeonPokemonSprites
	thumb_func_end FreeDungeonPokemonSprites

	thumb_func_start UpdateDungeonPokemonSprite
    @ void UpdateDungeonPokemonSprite(int id, short species, int status, char visible)
UpdateDungeonPokemonSprite:
	push {r4-r7,lr}
	adds r4, r0, 0
	adds r7, r2, 0
	lsls r1, 16
	asrs r5, r1, 16
	lsls r3, 24
	lsrs r6, r3, 24
	ldr r0, _0800F790
	ldr r0, [r0]
	cmp r0, 0
	beq _0800F788
	adds r0, r4, 0
	bl GetDungeonPokemonSprite
	cmp r0, 0
	beq _0800F788
	movs r1, 0
	strh r5, [r0, 0x8]
	str r7, [r0, 0xC]
	strb r6, [r0, 0x10]
	adds r0, 0x38
	strb r1, [r0]
_0800F788:
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_0800F790: .4byte gDungeonPokemonSprites
	thumb_func_end UpdateDungeonPokemonSprite

	thumb_func_start sub_800F794
sub_800F794:
	push {r4-r6,lr}
	adds r1, r0, 0
	adds r4, r2, 0
	adds r5, r3, 0
	ldr r6, [sp, 0x10]
	ldr r0, _0800F7CC
	ldr r0, [r0]
	cmp r0, 0
	beq _0800F7C6
	adds r0, r1, 0
	bl GetDungeonPokemonSprite
	adds r2, r0, 0
	cmp r2, 0
	beq _0800F7C6
	adds r1, r2, 0
	adds r1, 0x38
	movs r0, 0x1
	strb r0, [r1]
	strh r4, [r2, 0x3C]
	strh r5, [r2, 0x3E]
	ldr r0, [r6]
	str r0, [r2, 0x20]
	ldr r0, [r6, 0xC]
	str r0, [r2, 0x24]
_0800F7C6:
	pop {r4-r6}
	pop {r0}
	bx r0
	.align 2, 0
_0800F7CC: .4byte gDungeonPokemonSprites
	thumb_func_end sub_800F794

	thumb_func_start sub_800F7D0
sub_800F7D0:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	mov r8, r0
	ldr r0, _0800F800
	ldr r0, [r0]
	cmp r0, 0
	beq _0800F8C0
	ldr r1, [r0]
	adds r0, r1, 0
	cmp r1, 0
	bge _0800F7EA
	adds r0, r1, 0x3
_0800F7EA:
	asrs r0, 2
	lsls r0, 2
	subs r0, r1, r0
	cmp r0, 0x1
	beq _0800F82A
	cmp r0, 0x1
	bgt _0800F804
	cmp r0, 0
	beq _0800F80E
	b _0800F888
	.align 2, 0
_0800F800: .4byte gDungeonPokemonSprites
_0800F804:
	cmp r0, 0x2
	beq _0800F846
	cmp r0, 0x3
	beq _0800F868
	b _0800F888
_0800F80E:
	movs r0, 0x1
	movs r1, 0x1
	bl LoadStatusGraphics
	movs r0, 0x2
	movs r1, 0x1
	bl LoadStatusGraphics
	movs r0, 0x3
	movs r1, 0x1
	bl LoadStatusGraphics
	movs r0, 0x4
	b _0800F860
_0800F82A:
	movs r0, 0x5
	movs r1, 0x1
	bl LoadStatusGraphics
	movs r0, 0x6
	movs r1, 0x1
	bl LoadStatusGraphics
	movs r0, 0x7
	movs r1, 0x1
	bl LoadStatusGraphics
	movs r0, 0x8
	b _0800F860
_0800F846:
	movs r0, 0x9
	movs r1, 0x1
	bl LoadStatusGraphics
	movs r0, 0xA
	movs r1, 0x1
	bl LoadStatusGraphics
	movs r0, 0xB
	movs r1, 0x1
	bl LoadStatusGraphics
	movs r0, 0xC
_0800F860:
	movs r1, 0x1
	bl LoadStatusGraphics
	b _0800F888
_0800F868:
	movs r0, 0xD
	movs r1, 0x1
	bl LoadStatusGraphics
	movs r0, 0xE
	movs r1, 0x1
	bl LoadStatusGraphics
	movs r0, 0xF
	movs r1, 0x1
	bl LoadStatusGraphics
	movs r0, 0x10
	movs r1, 0x1
	bl LoadStatusGraphics
_0800F888:
	movs r5, 0
	movs r6, 0x4
_0800F88C:
	ldr r7, _0800F8CC
	ldr r4, [r7]
	lsls r0, r5, 6
	adds r0, r4, r0
	ldrb r0, [r0, 0x4]
	cmp r0, 0
	beq _0800F8B0
	adds r4, r6
	adds r0, r4, 0
	movs r1, 0
	mov r2, r8
	bl sub_800F2EC
	adds r0, r4, 0
	movs r1, 0x1
	mov r2, r8
	bl sub_800F2EC
_0800F8B0:
	adds r6, 0x40
	adds r5, 0x1
	cmp r5, 0x15
	ble _0800F88C
	ldr r1, [r7]
	ldr r0, [r1]
	adds r0, 0x1
	str r0, [r1]
_0800F8C0:
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_0800F8CC: .4byte gDungeonPokemonSprites
	thumb_func_end sub_800F7D0

	thumb_func_start AddPokemonDungeonSprite
    @ void AddPokemonDungeonSprite(int id, short species, Position *pos, ?)
AddPokemonDungeonSprite:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	adds r5, r0, 0
	adds r7, r2, 0
	mov r8, r3
	lsls r1, 16
	asrs r6, r1, 16
	ldr r0, _0800F92C
	ldr r0, [r0]
	cmp r0, 0
	beq _0800F920
	adds r0, r5, 0
	bl GetDungeonPokemonSprite
	adds r4, r0, 0
	cmp r4, 0
	bne _0800F920
	bl NewDungeonPokemonSprite
	adds r1, r0, 0
	cmp r1, 0
	beq _0800F920
	movs r0, 0x1
	strb r0, [r1]
	str r5, [r1, 0x4]
	strh r6, [r1, 0x8]
	str r4, [r1, 0xC]
	ldr r0, [r7]
	str r0, [r1, 0x14]
	mov r0, r8
	strb r0, [r1, 0x11]
	ldr r0, _0800F930
	ldr r0, [r0]
	str r0, [r1, 0x1C]
	str r0, [r1, 0x18]
	str r4, [r1, 0x28]
	str r4, [r1, 0x2C]
	str r4, [r1, 0x30]
	str r4, [r1, 0x34]
_0800F920:
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_0800F92C: .4byte gDungeonPokemonSprites
_0800F930: .4byte gUnknown_80D3564
	thumb_func_end AddPokemonDungeonSprite

	thumb_func_start DeletePokemonDungeonSprite
    @ void DeletePokemonDungeonSprite(int id)
DeletePokemonDungeonSprite:
	push {lr}
	adds r1, r0, 0
	ldr r0, _0800F954
	ldr r0, [r0]
	cmp r0, 0
	beq _0800F950
	adds r0, r1, 0
	bl GetDungeonPokemonSprite
	cmp r0, 0
	beq _0800F950
	movs r1, 0x40
	bl MemoryClear8
_0800F950:
	pop {r0}
	bx r0
	.align 2, 0
_0800F954: .4byte gDungeonPokemonSprites
	thumb_func_end DeletePokemonDungeonSprite

        .align 2,0
