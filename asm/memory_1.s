	#include "asm/constants/gba_constants.inc"
	#include "asm/macros.inc"

	.syntax unified

	.text

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
