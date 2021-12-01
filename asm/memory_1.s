	.include "constants/gba_constants.inc"
	.include "asm/macros.inc"

	.syntax unified

	.text

	thumb_func_start DoCreateSubHeap
DoCreateSubHeap:
	push {r4,lr}
	sub sp, 0x8
	adds r2, r1, 0
	ldr r4, [r0]
	adds r1, r4, 0
	adds r1, 0x1C
	str r1, [sp]
	ldr r0, [r0, 0x4]
	subs r0, 0x1C
	str r0, [sp, 0x4]
	adds r0, r4, 0
	mov r1, sp
	bl InitSubHeap
	adds r0, r4, 0
	add sp, 0x8
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end DoCreateSubHeap

	thumb_func_start xxx_unused_memory_free
xxx_unused_memory_free:
	push {r4-r7,lr}
	adds r4, r0, 0
	cmp r4, 0
	beq _08003504
	movs r1, 0
	ldr r0, [r4, 0xC]
	cmp r0, 0x1
	bne _080034A2
	ldr r0, [r4, 0x8]
	ldr r0, [r0, 0x4]
	cmp r0, 0
	bne _080034A2
	movs r1, 0x1
_080034A2:
	cmp r1, 0
	beq _08003504
	movs r0, 0
	mov r12, r0
	movs r3, 0
	ldr r6, =gHeapCount
	ldr r0, [r6]
	cmp r12, r0
	bge _080034F2
	ldr r5, =gHeapDescriptorList
	adds r1, r6, 0
	adds r7, r5, 0
	movs r2, 0
_080034BC:
	adds r0, r2, r5
	ldr r0, [r0]
	cmp r0, r4
	bne _080034E8
	ldr r0, [r1]
	subs r0, 0x1
	str r0, [r1]
	cmp r3, r0
	bge _080034F8
	ldr r1, =gHeapCount
	adds r2, r7
_080034D2:
	ldr r0, [r2, 0x4]
	stm r2!, {r0}
	adds r3, 0x1
	ldr r0, [r1]
	cmp r3, r0
	blt _080034D2
	b _080034F8
	.align 2, 0
	.pool 
_080034E8:
	adds r2, 0x4
	adds r3, 0x1
	ldr r0, [r6]
	cmp r3, r0
	blt _080034BC
_080034F2:
	mov r0, r12
	cmp r0, 0
	beq _08003504
_080034F8:
	ldr r0, [r4, 0x4]
	cmp r0, 0
	beq _08003504
	adds r1, r4, 0
	bl DoFree
_08003504:
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end xxx_unused_memory_free

	thumb_func_start DoAlloc
DoAlloc:
	push {lr}
	movs r3, 0x80
	lsls r3, 1
	orrs r3, r2
	adds r2, r3, 0
	bl _LocateSet
	pop {r1}
	bx r1
	thumb_func_end DoAlloc

	thumb_func_start DoFree
DoFree:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	adds r4, r0, 0
	cmp r4, 0
	bne _0800352E
	ldr r4, =gMainHeapDescriptor
_0800352E:
	cmp r1, 0
	beq _080035E4
	movs r0, 0
	mov r8, r0
	ldr r3, [r4, 0x8]
	mov r12, r3
	ldr r3, [r4, 0xC]
	cmp r8, r3
	bge _080035E4
	movs r2, 0
_08003542:
	mov r5, r12
	ldr r0, [r5, 0xC]
	cmp r0, r1
	bne _080035D8
	str r2, [r5]
	str r2, [r5, 0x4]
	str r2, [r5, 0x14]
	str r2, [r5, 0x8]
	ldr r0, [r4, 0xC]
	subs r0, 0x1
	cmp r8, r0
	bge _08003592
	mov r2, r12
	adds r2, 0x18
	ldr r0, [r2, 0x4]
	cmp r0, 0
	bne _08003592
	ldr r0, [r5, 0x10]
	ldr r1, [r2, 0x10]
	adds r0, r1
	str r0, [r5, 0x10]
	ldr r0, [r4, 0xC]
	subs r0, 0x1
	str r0, [r4, 0xC]
	mov r3, r8
	adds r3, 0x1
	cmp r3, r0
	bge _08003592
_0800357A:
	adds r0, r2, 0
	adds r1, r2, 0
	adds r1, 0x18
	ldm r1!, {r5-r7}
	stm r0!, {r5-r7}
	ldm r1!, {r5-r7}
	stm r0!, {r5-r7}
	adds r3, 0x1
	adds r2, 0x18
	ldr r0, [r4, 0xC]
	cmp r3, r0
	blt _0800357A
_08003592:
	mov r6, r8
	cmp r6, 0
	ble _080035E4
	mov r2, r12
	subs r2, 0x18
	ldr r0, [r2, 0x4]
	cmp r0, 0
	bne _080035E4
	ldr r0, [r2, 0x10]
	mov r7, r12
	ldr r1, [r7, 0x10]
	adds r0, r1
	str r0, [r2, 0x10]
	ldr r0, [r4, 0xC]
	subs r0, 0x1
	str r0, [r4, 0xC]
	mov r2, r12
	mov r3, r8
	cmp r3, r0
	bge _080035E4
_080035BA:
	adds r0, r2, 0
	adds r1, r2, 0
	adds r1, 0x18
	ldm r1!, {r5-r7}
	stm r0!, {r5-r7}
	ldm r1!, {r5-r7}
	stm r0!, {r5-r7}
	adds r3, 0x1
	adds r2, 0x18
	ldr r0, [r4, 0xC]
	cmp r3, r0
	blt _080035BA
	b _080035E4
	.align 2, 0
	.pool
_080035D8:
	movs r0, 0x1
	add r8, r0
	movs r5, 0x18
	add r12, r5
	cmp r8, r3
	blt _08003542
_080035E4:
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end DoFree

        .align 2,0
