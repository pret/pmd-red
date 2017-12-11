	.include "constants/gba_constants.inc"
	.include "asm/macros.inc"

	.syntax unified

	.text

	thumb_func_start InitHeap
InitHeap:
	push {lr}
	bl InitHeapInternal
	pop {r0}
	bx r0
	thumb_func_end InitHeap

	thumb_func_start MemoryClear8
MemoryClear8:
	push {lr}
	cmp r1, 0
	ble _08002EAA
	movs r2, 0
_08002EA0:
	subs r1, 0x1
	strb r2, [r0]
	adds r0, 0x1
	cmp r1, 0
	bgt _08002EA0
_08002EAA:
	pop {r0}
	bx r0
	thumb_func_end MemoryClear8

	thumb_func_start MemoryClear16
MemoryClear16:
	push {lr}
	cmp r1, 0
	ble _08002EC2
	movs r2, 0
_08002EB8:
	subs r1, 0x2
	strh r2, [r0]
	adds r0, 0x2
	cmp r1, 0
	bgt _08002EB8
_08002EC2:
	pop {r0}
	bx r0
	thumb_func_end MemoryClear16

	thumb_func_start MemoryClear32
MemoryClear32:
	push {lr}
	bl CpuClear
	pop {r0}
	bx r0
	thumb_func_end MemoryClear32

	thumb_func_start MemoryFill8
MemoryFill8:
	push {lr}
	lsls r1, 24
	lsrs r1, 24
	cmp r2, 0
	ble _08002EE8
_08002EDE:
	subs r2, 0x1
	strb r1, [r0]
	adds r0, 0x1
	cmp r2, 0
	bgt _08002EDE
_08002EE8:
	pop {r0}
	bx r0
	thumb_func_end MemoryFill8

	thumb_func_start MemoryFill16
MemoryFill16:
	push {lr}
	lsls r1, 16
	lsrs r1, 16
	cmp r2, 0
	ble _08002F00
_08002EF6:
	subs r2, 0x2
	strh r1, [r0]
	adds r0, 0x2
	cmp r2, 0
	bgt _08002EF6
_08002F00:
	pop {r0}
	bx r0
	thumb_func_end MemoryFill16

	thumb_func_start MemoryFill32
MemoryFill32:
	push {lr}
	cmp r2, 0
	ble _08002F12
_08002F0A:
	subs r2, 0x4
	stm r0!, {r1}
	cmp r2, 0
	bgt _08002F0A
_08002F12:
	pop {r0}
	bx r0
	thumb_func_end MemoryFill32

	thumb_func_start MemoryCopy8
MemoryCopy8:
	push {lr}
	adds r3, r0, 0
	cmp r2, 0
	ble _08002F2E
_08002F20:
	subs r2, 0x1
	ldrb r0, [r1]
	strb r0, [r3]
	adds r1, 0x1
	adds r3, 0x1
	cmp r2, 0
	bgt _08002F20
_08002F2E:
	pop {r0}
	bx r0
	thumb_func_end MemoryCopy8

	thumb_func_start MemoryCopy16
MemoryCopy16:
	push {lr}
	adds r3, r0, 0
	cmp r2, 0
	ble _08002F4A
_08002F3C:
	subs r2, 0x2
	ldrh r0, [r1]
	strh r0, [r3]
	adds r1, 0x2
	adds r3, 0x2
	cmp r2, 0
	bgt _08002F3C
_08002F4A:
	pop {r0}
	bx r0
	thumb_func_end MemoryCopy16

	thumb_func_start MemoryCopy32
MemoryCopy32:
	push {lr}
	adds r3, r0, 0
	cmp r2, 0
	ble _08002F62
_08002F58:
	subs r2, 0x4
	ldm r1!, {r0}
	stm r3!, {r0}
	cmp r2, 0
	bgt _08002F58
_08002F62:
	pop {r0}
	bx r0
	thumb_func_end MemoryCopy32

	thumb_func_start InitHeapInternal
InitHeapInternal:
	push {lr}
	sub sp, 0x8
	ldr r0, _08002F90
	str r0, [sp]
	movs r0, 0x90
	lsls r0, 10
	str r0, [sp, 0x4]
	ldr r1, _08002F94
	movs r0, 0
	str r0, [r1]
	ldr r0, _08002F98
	ldr r2, _08002F9C
	mov r1, sp
	movs r3, 0x20
	bl DoInitHeap
	add sp, 0x8
	pop {r0}
	bx r0
	.align 2, 0
_08002F90: .4byte gUnknown_20011D0
_08002F94: .4byte gUnknown_2000EA8
_08002F98: .4byte gUnknown_2000EB0
_08002F9C: .4byte gUnknown_2000ED0
	thumb_func_end InitHeapInternal

	thumb_func_start DoInitHeap
DoInitHeap:
	push {r4-r6,lr}
	mov r6, r9
	mov r5, r8
	push {r5,r6}
	ldr r4, [r1, 0x4]
	mov r9, r4
	movs r4, 0x4
	negs r4, r4
	mov r5, r9
	ands r5, r4
	mov r9, r5
	ldr r6, _08002FFC
	ldr r4, _08003000
	mov r8, r4
	ldr r5, [r4]
	lsls r4, r5, 2
	adds r4, r6
	str r0, [r4]
	adds r5, 0x1
	mov r4, r8
	str r5, [r4]
	ldr r5, [r1]
	str r5, [r0, 0x14]
	mov r1, r9
	str r1, [r0, 0x18]
	movs r1, 0x2
	str r1, [r0]
	movs r4, 0
	str r4, [r0, 0x4]
	str r2, [r0, 0x8]
	movs r1, 0x1
	str r1, [r0, 0xC]
	str r3, [r0, 0x10]
	str r4, [r2]
	str r4, [r2, 0x4]
	str r5, [r2, 0xC]
	mov r5, r9
	str r5, [r2, 0x10]
	str r4, [r2, 0x14]
	str r4, [r2, 0x8]
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r6}
	pop {r0}
	bx r0
	.align 2, 0
_08002FFC: .4byte gUnknown_2000E88
_08003000: .4byte gUnknown_2000EA8
	thumb_func_end DoInitHeap

	thumb_func_start InitSubHeap
InitSubHeap:
	push {r4,r5,lr}
	sub sp, 0x8
	adds r3, r2, 0
	lsls r4, r3, 1
	adds r4, r3
	movs r2, 0x4
	negs r2, r2
	lsls r4, 3
	ldr r5, [r1, 0x4]
	subs r5, r4
	ands r5, r2
	ldr r2, [r1]
	adds r4, r2, r4
	str r4, [sp]
	str r5, [sp, 0x4]
	mov r1, sp
	bl DoInitHeap
	add sp, 0x8
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end InitSubHeap

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
	ldr r6, _080031A4
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
_080031A4: .4byte 0x00024001
_080031A8:
	movs r0, 0x1
	negs r0, r0
_080031AC:
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end MemorySearchFromBack

	thumb_func_start MemorySplitFront
MemorySplitFront:
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
	ldr r0, _08003238
	ldr r1, _0800323C
	mov r3, r8
	bl FatalError
	.align 2, 0
_08003238: .4byte gUnknown_80B7EB8
_0800323C: .4byte gUnknown_80B7EC4
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
	thumb_func_end MemorySplitFront

	thumb_func_start MemorySplitBack
MemorySplitBack:
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
	ldr r0, _0800330C
	ldr r1, _08003310
	mov r3, r8
	bl FatalError
	.align 2, 0
_0800330C: .4byte gUnknown_80B7EFC
_08003310: .4byte gUnknown_80B7EC4
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
	thumb_func_end MemorySplitBack

	thumb_func_start MemoryLocateSet
MemoryLocateSet:
	push {r4-r7,lr}
	sub sp, 0x8
	adds r5, r0, 0
	adds r7, r1, 0
	adds r6, r2, 0
	cmp r5, 0
	bne _0800335C
	ldr r5, _08003390
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
	bl MemorySplitFront
	ldr r0, [r0, 0xC]
	b _080033CC
	.align 2, 0
_08003390: .4byte gUnknown_2000EB0
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
	bl MemorySplitBack
	ldr r0, [r0, 0xC]
	b _080033CC
_080033B4:
	ldr r0, _080033C4
	ldr r1, _080033C8
	str r4, [sp]
	str r6, [sp, 0x4]
	adds r2, r5, 0
	adds r3, r7, 0
	bl FatalError
	.align 2, 0
_080033C4: .4byte gUnknown_80B7F14
_080033C8: .4byte gUnknown_80B7F20
_080033CC:
	add sp, 0x8
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end MemoryLocateSet

	thumb_func_start MemoryAlloc
MemoryAlloc:
	push {lr}
	adds r3, r0, 0
	adds r2, r1, 0
	ldr r0, _080033E8
	adds r1, r3, 0
	bl DoAlloc
	pop {r1}
	bx r1
	.align 2, 0
_080033E8: .4byte gUnknown_2000EB0
	thumb_func_end MemoryAlloc

	thumb_func_start MemoryFree
MemoryFree:
	push {lr}
	adds r1, r0, 0
	ldr r0, _080033FC
	bl DoFree
	pop {r0}
	bx r0
	.align 2, 0
_080033FC: .4byte gUnknown_2000EB0
	thumb_func_end MemoryFree

	thumb_func_start CreateSubHeap
CreateSubHeap:
	push {r4-r7,lr}
	sub sp, 0xC
	adds r4, r0, 0
	adds r5, r1, 0
	adds r7, r2, 0
	adds r6, r3, 0
	cmp r4, 0
	bne _08003412
	ldr r4, _0800342C
_08003412:
	adds r0, r4, 0
	movs r1, 0x9
	adds r2, r5, 0
	bl MemorySearchFromBack
	adds r1, r0, 0
	cmp r1, 0
	bge _08003438
	ldr r0, _08003430
	ldr r1, _08003434
	adds r2, r5, 0
	bl FatalError
	.align 2, 0
_0800342C: .4byte gUnknown_2000EB0
_08003430: .4byte gUnknown_80B7F88
_08003434: .4byte gUnknown_80B7F94
_08003438:
	str r6, [sp]
	adds r0, r4, 0
	movs r2, 0x9
	adds r3, r5, 0
	bl MemorySplitBack
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
	thumb_func_end CreateSubHeap

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
	ldr r6, _080034E0
	ldr r0, [r6]
	cmp r12, r0
	bge _080034F2
	ldr r5, _080034E4
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
	ldr r1, _080034E0
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
_080034E0: .4byte gUnknown_2000EA8
_080034E4: .4byte gUnknown_2000E88
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
	bl MemoryLocateSet
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
	ldr r4, _080035D4
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
_080035D4: .4byte gUnknown_2000EB0
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
