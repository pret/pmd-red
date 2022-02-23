	#include "asm/constants/gba_constants.inc"
  	#include "asm/macros.inc"

  	.syntax unified

  	.text

	thumb_func_start IsTargetInLineRange
IsTargetInLineRange:
	push {r4-r7,lr}
	adds r4, r0, 0
	adds r5, r1, 0
	movs r0, 0x4
	ldrsh r1, [r4, r0]
	movs r3, 0x4
	ldrsh r0, [r5, r3]
	subs r3, r1, r0
	cmp r3, 0
	bge _0807C4B6
	negs r3, r3
_0807C4B6:
	movs r6, 0x6
	ldrsh r1, [r4, r6]
	movs r7, 0x6
	ldrsh r0, [r5, r7]
	subs r1, r0
	cmp r1, 0
	bge _0807C4C6
	negs r1, r1
_0807C4C6:
	adds r0, r1, 0
	cmp r1, r3
	bge _0807C4CE
	adds r0, r3, 0
_0807C4CE:
	cmp r0, 0xA
	bgt _0807C578
	cmp r0, r2
	bgt _0807C578
	movs r6, 0x1
	negs r6, r6
	cmp r3, r1
	bne _0807C516
	movs r0, 0x4
	ldrsh r1, [r4, r0]
	movs r2, 0x4
	ldrsh r0, [r5, r2]
	ldrh r2, [r4, 0x4]
	ldrh r3, [r5, 0x4]
	cmp r1, r0
	bge _0807C4FE
	movs r6, 0x6
	ldrsh r1, [r4, r6]
	movs r7, 0x6
	ldrsh r0, [r5, r7]
	cmp r1, r0
	blt _0807C574
	cmp r1, r0
	bgt _0807C574
_0807C4FE:
	lsls r1, r2, 16
	lsls r0, r3, 16
	movs r6, 0x7
	cmp r1, r0
	ble _0807C570
	movs r0, 0x6
	ldrsh r1, [r4, r0]
	movs r2, 0x6
	ldrsh r0, [r5, r2]
	cmp r1, r0
	ble _0807C570
	b _0807C574
_0807C516:
	movs r3, 0x4
	ldrsh r1, [r4, r3]
	movs r7, 0x4
	ldrsh r0, [r5, r7]
	ldrh r2, [r4, 0x4]
	ldrh r3, [r5, 0x4]
	cmp r1, r0
	bne _0807C532
	movs r0, 0x6
	ldrsh r1, [r4, r0]
	movs r7, 0x6
	ldrsh r0, [r5, r7]
	cmp r1, r0
	blt _0807C574
_0807C532:
	lsls r1, r2, 16
	lsls r0, r3, 16
	cmp r1, r0
	bge _0807C546
	movs r0, 0x6
	ldrsh r1, [r4, r0]
	movs r7, 0x6
	ldrsh r0, [r5, r7]
	cmp r1, r0
	beq _0807C574
_0807C546:
	lsls r1, r2, 16
	lsls r0, r3, 16
	cmp r1, r0
	bne _0807C55A
	movs r0, 0x6
	ldrsh r1, [r4, r0]
	movs r7, 0x6
	ldrsh r0, [r5, r7]
	cmp r1, r0
	bgt _0807C574
_0807C55A:
	lsls r1, r2, 16
	lsls r0, r3, 16
	cmp r1, r0
	ble _0807C570
	movs r0, 0x6
	ldrsh r1, [r4, r0]
	movs r2, 0x6
	ldrsh r0, [r5, r2]
	cmp r1, r0
	bne _0807C570
	movs r6, 0x6
_0807C570:
	cmp r6, 0
	blt _0807C578
_0807C574:
	movs r0, 0x1
	b _0807C57A
_0807C578:
	movs r0, 0
_0807C57A:
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end IsTargetInLineRange

	.align 2, 0