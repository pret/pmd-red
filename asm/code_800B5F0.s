	#include "asm/constants/gba_constants.inc"
	#include "asm/macros.inc"

	.syntax unified

	.text

	thumb_func_start sub_800B720
sub_800B720:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x14
	str r1, [sp]
	lsls r0, 16
	asrs r0, 16
	str r0, [sp, 0xC]
	bl DisableInterrupts
	lsls r0, 24
	lsrs r0, 24
	str r0, [sp, 0x4]
	ldr r0, _0800B780
	mov r8, r0
	ldr r1, _0800B784
	mov r10, r1
	ldr r2, _0800B788
	mov r9, r2
	ldr r5, _0800B78C
	mov r12, r5
_0800B74E:
	movs r7, 0
	str r7, [sp, 0x10]
	movs r4, 0
	ldr r3, _0800B784
	mov r1, r8
	movs r2, 0
	ldrsh r0, [r1, r2]
	ldr r6, _0800B78C
	ldr r5, [sp, 0xC]
	lsls r5, 16
	str r5, [sp, 0x8]
	cmp r4, r0
	bge _0800B7BA
	movs r7, 0
	ldrsh r1, [r3, r7]
	ldrh r2, [r6]
	movs r5, 0
	ldrsh r0, [r6, r5]
	cmp r1, r0
	bne _0800B790
	adds r0, r2, 0x1
	mov r7, r9
	ands r0, r7
	strh r0, [r6]
	b _0800B74E
	.align 2, 0
_0800B780: .4byte gUnknown_203B0AA
_0800B784: .4byte gUnknown_202D608
_0800B788: .4byte 0x00007fff
_0800B78C: .4byte gUnknown_203B0A8
_0800B790:
	adds r4, 0x1
	adds r3, 0x8
	mov r1, r8
	movs r2, 0
	ldrsh r0, [r1, r2]
	cmp r4, r0
	bge _0800B7BA
	movs r5, 0
	ldrsh r1, [r3, r5]
	mov r7, r12
	ldrh r2, [r7]
	movs r5, 0
	ldrsh r0, [r7, r5]
	cmp r1, r0
	bne _0800B790
	adds r0, r2, 0x1
	mov r7, r9
	ands r0, r7
	strh r0, [r6]
	movs r0, 0x1
	str r0, [sp, 0x10]
_0800B7BA:
	ldr r1, [sp, 0x10]
	cmp r1, 0
	bne _0800B74E
	movs r4, 0
	mov r3, r10
	ldr r2, _0800B84C
	movs r5, 0
	ldrsh r1, [r2, r5]
	cmp r4, r1
	bge _0800B7EA
	movs r7, 0x2
	ldrsh r0, [r3, r7]
	ldr r2, [sp, 0xC]
	cmp r0, r2
	bgt _0800B7EA
_0800B7D8:
	adds r4, 0x1
	adds r3, 0x8
	cmp r4, r1
	bge _0800B7EA
	movs r5, 0x2
	ldrsh r0, [r3, r5]
	ldr r7, [sp, 0xC]
	cmp r0, r7
	ble _0800B7D8
_0800B7EA:
	ldr r1, _0800B84C
	movs r2, 0
	ldrsh r0, [r1, r2]
	subs r2, r0, 0x1
	lsls r0, r2, 3
	mov r5, r10
	adds r3, r0, r5
	lsls r5, r4, 3
	cmp r2, r4
	blt _0800B80E
_0800B7FE:
	ldr r0, [r3]
	ldr r1, [r3, 0x4]
	str r0, [r3, 0x8]
	str r1, [r3, 0xC]
	subs r2, 0x1
	subs r3, 0x8
	cmp r2, r4
	bge _0800B7FE
_0800B80E:
	ldr r7, _0800B84C
	ldrh r0, [r7]
	adds r0, 0x1
	strh r0, [r7]
	mov r0, r10
	adds r1, r5, r0
	ldrh r0, [r6]
	strh r0, [r1]
	ldr r2, [sp, 0x8]
	lsrs r0, r2, 16
	strh r0, [r1, 0x2]
	mov r0, r10
	adds r0, 0x4
	adds r0, r5, r0
	ldr r5, [sp]
	str r5, [r0]
	ldr r7, [sp, 0x4]
	cmp r7, 0
	beq _0800B838
	bl EnableInterrupts
_0800B838:
	movs r1, 0
	ldrsh r0, [r6, r1]
	add sp, 0x14
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	.align 2, 0
_0800B84C: .4byte gUnknown_203B0AA
	thumb_func_end sub_800B720

	thumb_func_start sub_800B850
sub_800B850:
	push {r4-r7,lr}
	lsls r0, 16
	asrs r6, r0, 16
	bl DisableInterrupts
	lsls r0, 24
	lsrs r5, r0, 24
	movs r2, 0
	ldr r4, _0800B8A0
	ldr r3, _0800B8A4
	movs r1, 0
	ldrsh r0, [r3, r1]
	cmp r2, r0
	bge _0800B8B4
	adds r1, r3, 0
_0800B86E:
	movs r7, 0
	ldrsh r0, [r4, r7]
	cmp r0, r6
	bne _0800B8A8
	ldrh r0, [r1]
	subs r0, 0x1
	strh r0, [r1]
	movs r3, 0
	ldrsh r0, [r1, r3]
	cmp r2, r0
	bge _0800B896
	ldr r3, _0800B8A4
_0800B886:
	ldr r0, [r4, 0x8]
	ldr r1, [r4, 0xC]
	stm r4!, {r0,r1}
	adds r2, 0x1
	movs r7, 0
	ldrsh r0, [r3, r7]
	cmp r2, r0
	blt _0800B886
_0800B896:
	cmp r5, 0
	beq _0800B8BC
	bl EnableInterrupts
	b _0800B8BC
	.align 2, 0
_0800B8A0: .4byte gUnknown_202D608
_0800B8A4: .4byte gUnknown_203B0AA
_0800B8A8:
	adds r2, 0x1
	adds r4, 0x8
	movs r7, 0
	ldrsh r0, [r3, r7]
	cmp r2, r0
	blt _0800B86E
_0800B8B4:
	cmp r5, 0
	beq _0800B8BC
	bl EnableInterrupts
_0800B8BC:
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_800B850

	.align 2, 0 @ Don't pad with nop.
