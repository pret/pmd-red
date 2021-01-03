	.include "constants/gba_constants.inc"
	.include "asm/macros.inc"

	.syntax unified

	.text	

	thumb_func_start SetBGOBJEnableFlags
SetBGOBJEnableFlags:
	push {r4,lr}
	movs r3, 0x80
	lsls r3, 19
	ldrh r1, [r3]
	ldr r2, _0800CDA4
	ands r2, r1
	lsls r0, 8
	movs r4, 0xF8
	lsls r4, 5
	adds r1, r4, 0
	bics r1, r0
	orrs r2, r1
	strh r2, [r3]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0800CDA4: .4byte 0x0000e0ff
	thumb_func_end SetBGOBJEnableFlags

        .align 2,0
