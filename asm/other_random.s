	.include "constants/gba_constants.inc"
	.include "asm/macros.inc"

	.syntax unified

	.text

	thumb_func_start OtherRandom
OtherRandom:
	ldr r1, _08004514
	ldrh r2, [r1]
	movs r0, 0x6D
	muls r0, r2
	ldr r2, _08004518
	adds r0, r2
	strh r0, [r1]
	ldrh r0, [r1]
	bx lr
	.align 2, 0
_08004514: .4byte gUnknown_203B070
_08004518: .4byte 0x000003fd
	thumb_func_end OtherRandom

	thumb_func_start OtherRandomCapped
OtherRandomCapped:
	push {r4,lr}
	adds r4, r0, 0
	bl OtherRandom
	muls r0, r4
	asrs r0, 16
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end OtherRandomCapped

	thumb_func_start OtherRandomRange
OtherRandomRange:
	push {r4,lr}
	adds r4, r0, 0
	subs r0, r1, r4
	bl OtherRandomCapped
	adds r0, r4
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end OtherRandomRange

	.align 2, 0 @ Don't pad with nop.
