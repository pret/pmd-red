	#include "asm/constants/gba_constants.inc"
	#include "asm/macros.inc"

	.syntax unified

	.text

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
