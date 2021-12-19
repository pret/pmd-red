	#include "asm/constants/gba_constants.inc"
	#include "asm/macros.inc"

	.syntax unified

	.text

        thumb_func_start CalculateFacingDir
CalculateFacingDir:
	push {r4,lr}
	movs r2, 0
	ldrsh r3, [r1, r2]
	movs r4, 0
	ldrsh r2, [r0, r4]
	subs r2, r3, r2
	movs r3, 0x2
	ldrsh r1, [r1, r3]
	movs r4, 0x2
	ldrsh r0, [r0, r4]
	subs r1, r0
	cmp r2, 0
	bne _080983FA
	cmp r1, 0
	bne _080983FA
	movs r0, 0
	b _08098428
_080983FA:
	cmp r2, 0
	ble _08098400
	movs r2, 0x1
_08098400:
	cmp r1, 0
	ble _08098406
	movs r1, 0x1
_08098406:
	movs r0, 0x1
	negs r0, r0
	cmp r2, r0
	bgt _08098410
	adds r2, r0, 0
_08098410:
	cmp r1, r0
	bgt _08098416
	adds r1, r0, 0
_08098416:
	ldr r3, _08098430
	adds r2, 0x1
	adds r1, 0x1
	lsls r0, r1, 1
	adds r0, r1
	adds r0, r2
	lsls r0, 2
	adds r0, r3
	ldr r0, [r0]
_08098428:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_08098430: .4byte gUnknown_8115E94
	thumb_func_end CalculateFacingDir

        .align 2,0
