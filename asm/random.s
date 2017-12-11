	.include "constants/gba_constants.inc"
	.include "asm/macros.inc"

	.syntax unified

	.text

	thumb_func_start SeedRng
SeedRng:
	push {r4,lr}
	ldr r4, _08006170
	ldrb r2, [r0]
	ldrb r1, [r0, 0x1]
	muls r2, r1
	ldrb r3, [r0, 0x2]
	ldrb r1, [r0, 0x3]
	muls r1, r3
	ldr r3, _08006174
	adds r1, r3
	adds r2, r1
	ldrb r1, [r0, 0x4]
	ldrb r0, [r0, 0x5]
	muls r0, r1
	adds r2, r0
	str r2, [r4]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08006170: .4byte gUnknown_203B07C
_08006174: .4byte 0x0000d305
	thumb_func_end SeedRng

	thumb_func_start Random16
Random16:
	ldr r2, _08006188
	ldr r1, [r2]
	ldr r0, _0800618C
	muls r0, r1
	adds r0, 0x1
	str r0, [r2]
	asrs r0, 16
	bx lr
	.align 2, 0
_08006188: .4byte gUnknown_203B07C
_0800618C: .4byte 0x5d588b65
	thumb_func_end Random16

	thumb_func_start Random
Random:
	push {r4,lr}
	bl Random16
	adds r4, r0, 0
	lsls r4, 16
	asrs r4, 16
	bl Random16
	lsls r0, 16
	asrs r0, 16
	lsls r4, 16
	orrs r4, r0
	adds r0, r4, 0
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end Random

	thumb_func_start RandomCapped
RandomCapped:
	push {r4,lr}
	adds r4, r0, 0
	bl Random
	ldr r1, _080061C8
	ands r0, r1
	muls r0, r4
	asrs r0, 16
	ands r0, r1
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_080061C8: .4byte 0x0000ffff
	thumb_func_end RandomCapped

	thumb_func_start RandomRange
RandomRange:
	push {r4,r5,lr}
	adds r5, r0, 0
	adds r4, r1, 0
	cmp r5, r4
	beq _080061EC
	cmp r5, r4
	blt _080061E4
	subs r0, r5, r4
	bl RandomCapped
	adds r0, r4
	b _080061EC
_080061E4:
	subs r0, r4, r5
	bl RandomCapped
	adds r0, r5
_080061EC:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end RandomRange

	thumb_func_start GetRngState
GetRngState:
	ldr r0, _080061FC
	ldr r0, [r0]
	bx lr
	.align 2, 0
_080061FC: .4byte gUnknown_203B07C
	thumb_func_end GetRngState

	thumb_func_start ReseedRng
ReseedRng:
	push {r4,lr}
	ldr r4, _08006214
	str r0, [r4]
	bl Random
	str r0, [r4]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08006214: .4byte gUnknown_203B07C
	thumb_func_end ReseedRng

	.align 2, 0 @ Don't pad with nop.
