	#include "asm/constants/gba_constants.inc"
	#include "asm/macros.inc"

	.syntax unified

	.text

	thumb_func_start SketchMoveAction
SketchMoveAction:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x4
	adds r6, r0, 0
	adds r7, r1, 0
	adds r5, r2, 0
	movs r0, 0
	mov r10, r0
	ldr r1, [r6, 0x70]
	str r1, [sp]
	ldr r0, [r7, 0x70]
	movs r2, 0
	mov r12, r2
	movs r4, 0
	movs r1, 0x8C
	lsls r1, 1
	adds r3, r0, r1
	adds r1, r0, 0
	movs r2, 0x1
	mov r9, r2
	movs r0, 0x10
	mov r8, r0
_08059372:
	ldrb r2, [r3]
	mov r0, r9
	ands r0, r2
	cmp r0, 0
	beq _08059384
	mov r0, r8
	ands r0, r2
	cmp r0, 0
	bne _080593A8
_08059384:
	adds r3, 0x8
	adds r1, 0x8
	adds r4, 0x1
	cmp r4, 0x3
	ble _08059372
	movs r0, 0
	cmp r0, 0
	bne _080593B2
	ldr r0, _080593A4
	ldr r2, [r0]
	adds r0, r6, 0
	adds r1, r7, 0
	bl sub_80522F4
	movs r0, 0
	b _0805940A
	.align 2, 0
_080593A4: .4byte gUnknown_80FE3BC
_080593A8:
	movs r2, 0x8D
	lsls r2, 1
	adds r0, r1, r2
	ldrh r0, [r0]
	mov r12, r0
_080593B2:
	mov r0, r12
	cmp r0, 0
	bne _080593CC
	ldr r0, _080593C8
	ldr r2, [r0]
	adds r0, r6, 0
	adds r1, r7, 0
	bl sub_80522F4
	b _08059408
	.align 2, 0
_080593C8: .4byte gUnknown_80FE3BC
_080593CC:
	adds r0, r5, 0
	mov r1, r12
	bl InitPokemonMove
	ldr r0, _0805941C
	adds r1, r5, 0
	movs r2, 0
	bl sub_80928C0
	ldrb r1, [r5, 0x1]
	movs r0, 0x4
	orrs r0, r1
	movs r1, 0x20
	orrs r0, r1
	strb r0, [r5, 0x1]
	ldr r0, _08059420
	ldr r2, [r0]
	adds r0, r6, 0
	adds r1, r7, 0
	bl sub_80522F4
	ldr r1, [sp]
	adds r1, 0xFB
	ldrb r0, [r1]
	cmp r0, 0
	bne _08059404
	movs r0, 0x1
	strb r0, [r1]
_08059404:
	movs r1, 0x1
	mov r10, r1
_08059408:
	mov r0, r10
_0805940A:
	add sp, 0x4
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	.align 2, 0
_0805941C: .4byte gUnknown_202DE58
_08059420: .4byte gUnknown_80FE38C
	thumb_func_end SketchMoveAction

	.align 2, 0
