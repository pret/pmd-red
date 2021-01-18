	.include "constants/gba_constants.inc"
	.include "asm/macros.inc"

	.syntax unified

	.text	

        @ Unused
	thumb_func_start PrintMessageWithFuncFileLine
PrintMessageWithFuncFileLine:
	push {r2,r3}
	push {r4,r5,lr}
	sub sp, 0x4
	adds r4, r0, 0
	adds r5, r1, 0
	ldr r1, [sp, 0x10]
	add r2, sp, 0x14
	bl vsprintf
	adds r0, r4, 0
	bl strlen
	adds r4, r0
	ldr r1, _08011AFC
	ldr r2, [r5, 0x8]
	ldr r3, [r5]
	ldr r0, [r5, 0x4]
	str r0, [sp]
	adds r0, r4, 0
	bl sprintf
	add sp, 0x4
	pop {r4,r5}
	pop {r3}
	add sp, 0x8
	bx r3
	.align 2, 0
_08011AFC: .4byte gFuncFileLineString2
	thumb_func_end PrintMessageWithFuncFileLine

        .align 2,0 @ Don't pad with nop
