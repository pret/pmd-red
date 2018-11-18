	.include "constants/gba_constants.inc"
	.include "asm/macros.inc"

	.syntax unified

	.text
	
	thumb_func_start xxx_memory_attr_related
xxx_memory_attr_related:
	push {lr}
	adds r1, r0, 0
	cmp r1, 0
	bne _0800303C
	movs r0, 0
	b _08003060
_0800303C:
	movs r0, 0x8
	ands r0, r1
	cmp r0, 0
	beq _08003048
	movs r0, 0x4
	b _08003060
_08003048:
	movs r2, 0x7
	ands r2, r1
	movs r0, 0x1
	cmp r2, 0x7
	beq _08003060
	movs r0, 0x2
	cmp r2, 0x1
	beq _08003060
	movs r0, 0x5
	cmp r2, 0x3
	bne _08003060
	movs r0, 0x3
_08003060:
	pop {r1}
	bx r1
	thumb_func_end xxx_memory_attr_related

	thumb_func_start MemorySearchFromFront
MemorySearchFromFront:
	push {r4-r7,lr}
	adds r5, r0, 0
	adds r6, r2, 0
	movs r0, 0x4
	ands r0, r1
	cmp r0, 0
	beq _080030CC
	movs r4, 0
	ldr r3, [r5, 0x8]
	ldr r2, [r5, 0xC]
	cmp r4, r2
	bge _08003104
	ldr r0, [r3, 0x4]
	movs r1, 0x1
	ands r0, r1
	cmp r0, 0
	bne _08003090
	ldr r0, [r3, 0x10]
	cmp r0, r6
	blt _080030AC
	movs r0, 0
	b _08003108
_08003090:
	adds r4, 0x1
	adds r3, 0x18
	cmp r4, r2
	bge _08003104
	ldr r0, [r3, 0x4]
	movs r1, 0x1
	ands r0, r1
	cmp r0, 0
	bne _08003090
	ldr r0, [r3, 0x10]
	cmp r0, r6
	blt _080030AC
_080030A8:
	adds r0, r4, 0
	b _08003108
_080030AC:
	cmp r4, r2
	bge _08003104
	movs r5, 0x1
	adds r1, r2, 0
_080030B4:
	ldr r0, [r3, 0x4]
	ands r0, r5
	cmp r0, 0
	bne _080030C2
	ldr r0, [r3, 0x10]
	cmp r0, r6
	bge _080030A8
_080030C2:
	adds r4, 0x1
	adds r3, 0x18
	cmp r4, r1
	blt _080030B4
	b _08003104
_080030CC:
	movs r7, 0x1
	negs r7, r7
	ldr r1, _08003100
	movs r4, 0
	ldr r3, [r5, 0x8]
	ldr r2, [r5, 0xC]
	cmp r4, r2
	bge _080030FC
	movs r5, 0x1
_080030DE:
	ldr r0, [r3, 0x4]
	ands r0, r5
	cmp r0, 0
	bne _080030F4
	ldr r0, [r3, 0x10]
	cmp r0, r6
	blt _080030F4
	cmp r0, r1
	bge _080030F4
	adds r7, r4, 0
	adds r1, r0, 0
_080030F4:
	adds r4, 0x1
	adds r3, 0x18
	cmp r4, r2
	blt _080030DE
_080030FC:
	adds r0, r7, 0
	b _08003108
	.align 2, 0
_08003100: .4byte 0x00024001
_08003104:
	movs r0, 0x1
	negs r0, r0
_08003108:
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end MemorySearchFromFront

	thumb_func_start MemorySearchFromBack
MemorySearchFromBack:
	push {r4-r7,lr}
	adds r4, r0, 0
	adds r5, r2, 0
	movs r0, 0x4
	ands r0, r1
	cmp r0, 0
	beq _08003168
	ldr r0, [r4, 0xC]
	subs r3, r0, 0x1
	lsls r0, r3, 1
	adds r0, r3
	lsls r0, 3
	ldr r1, [r4, 0x8]
	adds r2, r1, r0
	b _08003132
_0800312E:
	subs r3, 0x1
	subs r2, 0x18
_08003132:
	cmp r3, 0
	blt _080031A8
	ldr r0, [r2, 0x4]
	movs r1, 0x1
	ands r0, r1
	cmp r0, 0
	bne _0800312E
	ldr r0, [r2, 0x10]
	cmp r0, r5
	blt _0800314A
_08003146:
	adds r0, r3, 0
	b _080031AC
_0800314A:
	cmp r3, 0
	blt _080031A8
	movs r1, 0x1
_08003150:
	ldr r0, [r2, 0x4]
	ands r0, r1
	cmp r0, 0
	bne _0800315E
	ldr r0, [r2, 0x10]
	cmp r0, r5
	bge _08003146
_0800315E:
	subs r3, 0x1
	subs r2, 0x18
	cmp r3, 0
	bge _08003150
	b _080031A8
_08003168:
	movs r7, 0x1
	negs r7, r7
	ldr r6, =0x24001
	ldr r0, [r4, 0xC]
	subs r3, r0, 0x1
	lsls r0, r3, 1
	adds r0, r3
	lsls r0, 3
	ldr r1, [r4, 0x8]
	adds r2, r1, r0
	cmp r3, 0
	blt _080031A0
	movs r1, 0x1
_08003182:
	ldr r0, [r2, 0x4]
	ands r0, r1
	cmp r0, 0
	bne _08003198
	ldr r0, [r2, 0x10]
	cmp r0, r5
	blt _08003198
	cmp r0, r6
	bge _08003198
	adds r7, r3, 0
	adds r6, r0, 0
_08003198:
	subs r3, 0x1
	subs r2, 0x18
	cmp r3, 0
	bge _08003182
_080031A0:
	adds r0, r7, 0
	b _080031AC
	.align 2, 0
	.pool
_080031A8:
	movs r0, 0x1
	negs r0, r0
_080031AC:
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end MemorySearchFromBack

	thumb_func_start _LocateSetFront
_LocateSetFront:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x14
	str r0, [sp, 0x8]
	str r1, [sp, 0xC]
	str r2, [sp]
	str r3, [sp, 0x4]
	adds r0, r3, 0
	adds r0, 0x3
	str r0, [sp, 0x10]
	movs r0, 0x4
	negs r0, r0
	ldr r1, [sp, 0x10]
	ands r1, r0
	str r1, [sp, 0x10]
	ldr r2, [sp, 0xC]
	lsls r2, 1
	mov r12, r2
	ldr r0, [sp, 0xC]
	add r0, r12
	lsls r0, 3
	ldr r5, [sp, 0x8]
	ldr r2, [r5, 0x8]
	adds r4, r2, r0
	ldr r0, [r4, 0x10]
	cmp r0, r1
	ble _08003260
	ldr r3, [r5, 0xC]
	lsls r0, r3, 1
	adds r0, r3
	lsls r0, 3
	adds r1, r2, r0
	mov r9, r12
	mov r10, r2
	mov r12, r3
	ldr r6, [r5, 0x10]
	mov r8, r6
	ldr r7, [sp, 0xC]
	cmp r12, r7
	ble _08003222
_0800320A:
	adds r2, r1, 0
	subs r2, 0x18
	adds r0, r2, 0
	ldm r0!, {r5-r7}
	stm r1!, {r5-r7}
	ldm r0!, {r5-r7}
	stm r1!, {r5-r7}
	subs r3, 0x1
	adds r1, r2, 0
	ldr r0, [sp, 0xC]
	cmp r3, r0
	bgt _0800320A
_08003222:
	mov r2, r12
	adds r2, 0x1
	ldr r1, [sp, 0x8]
	str r2, [r1, 0xC]
	cmp r2, r8
	ble _08003240
	ldr r0, =gUnknown_80B7EB8
	ldr r1, =gUnknown_80B7EC4
	mov r3, r8
	bl FatalError
	.align 2, 0
	.pool
_08003240:
	ldr r0, [sp, 0xC]
	add r0, r9
	lsls r0, 3
	adds r0, 0x18
	mov r2, r10
	adds r1, r2, r0
	ldr r0, [r1, 0xC]
	ldr r5, [sp, 0x10]
	adds r0, r5
	str r0, [r1, 0xC]
	ldr r0, [r1, 0x10]
	subs r0, r5
	str r0, [r1, 0x10]
	str r5, [r4, 0x10]
	ldr r6, [sp, 0x4]
	str r6, [r4, 0x14]
_08003260:
	ldr r0, [sp]
	bl xxx_memory_attr_related
	str r0, [r4]
	ldr r7, [sp]
	str r7, [r4, 0x4]
	ldr r0, [sp, 0x34]
	str r0, [r4, 0x8]
	adds r0, r4, 0
	add sp, 0x14
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end _LocateSetFront

	thumb_func_start _LocateSetBack
_LocateSetBack:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x14
	str r0, [sp, 0x8]
	str r1, [sp, 0xC]
	str r2, [sp]
	str r3, [sp, 0x4]
	adds r0, r3, 0
	adds r0, 0x3
	str r0, [sp, 0x10]
	movs r0, 0x4
	negs r0, r0
	ldr r1, [sp, 0x10]
	ands r1, r0
	str r1, [sp, 0x10]
	ldr r2, [sp, 0xC]
	lsls r0, r2, 1
	adds r0, r2
	lsls r0, 3
	ldr r5, [sp, 0x8]
	ldr r1, [r5, 0x8]
	adds r4, r1, r0
	ldr r0, [r4, 0x10]
	ldr r6, [sp, 0x10]
	cmp r0, r6
	ble _08003328
	ldr r3, [r5, 0xC]
	lsls r0, r3, 1
	adds r0, r3
	lsls r0, 3
	adds r1, r0
	mov r12, r3
	ldr r7, [r5, 0x10]
	mov r8, r7
	ldr r0, [r4, 0xC]
	mov r9, r0
	movs r2, 0x18
	adds r2, r4
	mov r10, r2
	ldr r5, [sp, 0xC]
	cmp r12, r5
	ble _080032F6
_080032DE:
	adds r2, r1, 0
	subs r2, 0x18
	adds r0, r2, 0
	ldm r0!, {r5-r7}
	stm r1!, {r5-r7}
	ldm r0!, {r5-r7}
	stm r1!, {r5-r7}
	subs r3, 0x1
	adds r1, r2, 0
	ldr r6, [sp, 0xC]
	cmp r3, r6
	bgt _080032DE
_080032F6:
	mov r2, r12
	adds r2, 0x1
	ldr r7, [sp, 0x8]
	str r2, [r7, 0xC]
	cmp r2, r8
	ble _08003314
	ldr r0, =gUnknown_80B7EFC
	ldr r1, =gUnknown_80B7EC4
	mov r3, r8
	bl FatalError
	.align 2, 0
	.pool
_08003314:
	ldr r0, [r4, 0x10]
	ldr r1, [sp, 0x10]
	subs r0, r1
	str r0, [r4, 0x10]
	add r0, r9
	mov r4, r10
	str r0, [r4, 0xC]
	str r1, [r4, 0x10]
	ldr r2, [sp, 0x4]
	str r2, [r4, 0x14]
_08003328:
	ldr r0, [sp]
	bl xxx_memory_attr_related
	str r0, [r4]
	ldr r5, [sp]
	str r5, [r4, 0x4]
	ldr r0, [sp, 0x34]
	str r0, [r4, 0x8]
	adds r0, r4, 0
	add sp, 0x14
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end _LocateSetBack

	thumb_func_start _LocateSet
_LocateSet:
	push {r4-r7,lr}
	sub sp, 0x8
	adds r5, r0, 0
	adds r7, r1, 0
	adds r6, r2, 0
	cmp r5, 0
	bne _0800335C
	ldr r5, =gMainHeapDescriptor
_0800335C:
	asrs r4, r6, 8
	movs r0, 0x1
	orrs r4, r0
	movs r0, 0xFF
	ands r6, r0
	movs r0, 0x2
	ands r0, r4
	cmp r0, 0
	beq _08003394
	adds r0, r5, 0
	adds r1, r4, 0
	adds r2, r7, 0
	bl MemorySearchFromFront
	adds r1, r0, 0
	cmp r1, 0
	blt _080033B4
	str r6, [sp]
	adds r0, r5, 0
	adds r2, r4, 0
	adds r3, r7, 0
	bl _LocateSetFront
	ldr r0, [r0, 0xC]
	b _080033CC
	.align 2, 0
	.pool
_08003394:
	adds r0, r5, 0
	adds r1, r4, 0
	adds r2, r7, 0
	bl MemorySearchFromBack
	adds r1, r0, 0
	cmp r1, 0
	blt _080033B4
	str r6, [sp]
	adds r0, r5, 0
	adds r2, r4, 0
	adds r3, r7, 0
	bl _LocateSetBack
	ldr r0, [r0, 0xC]
	b _080033CC
_080033B4:
	ldr r0, =gUnknown_80B7F14
	ldr r1, =gUnknown_80B7F20
	str r4, [sp]
	str r6, [sp, 0x4]
	adds r2, r5, 0
	adds r3, r7, 0
	bl FatalError
	.align 2, 0
	.pool
_080033CC:
	add sp, 0x8
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end _LocateSet

	thumb_func_start MemoryAlloc
MemoryAlloc:
	push {lr}
	adds r3, r0, 0
	adds r2, r1, 0
	ldr r0, =gMainHeapDescriptor
	adds r1, r3, 0
	bl DoAlloc
	pop {r1}
	bx r1
	.align 2, 0
	.pool
	thumb_func_end MemoryAlloc

	thumb_func_start MemoryFree
MemoryFree:
	push {lr}
	adds r1, r0, 0
	ldr r0, =gMainHeapDescriptor
	bl DoFree
	pop {r0}
	bx r0
	.align 2, 0
	.pool
	thumb_func_end MemoryFree

	thumb_func_start MemoryLocate_LocalCreate
MemoryLocate_LocalCreate:
	push {r4-r7,lr}
	sub sp, 0xC
	adds r4, r0, 0
	adds r5, r1, 0
	adds r7, r2, 0
	adds r6, r3, 0
	cmp r4, 0
	bne _08003412
	ldr r4, =gMainHeapDescriptor
_08003412:
	adds r0, r4, 0
	movs r1, 0x9
	adds r2, r5, 0
	bl MemorySearchFromBack
	adds r1, r0, 0
	cmp r1, 0
	bge _08003438
	ldr r0, =gUnknown_80B7F88
	ldr r1, =gUnknown_80B7F94
	adds r2, r5, 0
	bl FatalError
	.align 2, 0
	.pool
_08003438:
	str r6, [sp]
	adds r0, r4, 0
	movs r2, 0x9
	adds r3, r5, 0
	bl _LocateSetBack
	ldr r1, [r0, 0xC]
	str r1, [sp, 0x4]
	ldr r0, [r0, 0x10]
	str r0, [sp, 0x8]
	add r0, sp, 0x4
	adds r1, r7, 0
	bl DoCreateSubHeap
	str r4, [r0, 0x4]
	add sp, 0xC
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end MemoryLocate_LocalCreate

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

	.align 2, 0 @ Don't pad with nop.
