        .include "constants/gba_constants.inc"
	.include "asm/macros.inc"

	.syntax unified

	.text	

	thumb_func_start PromptNewQuestion
PromptNewQuestion:
	push {lr}
	sub sp, 0x14
	ldr r1, _0803CC38
	ldr r0, _0803CC3C
	ldr r0, [r0]
	ldr r0, [r0, 0x3C]
	lsls r0, 2
	adds r0, r1
	ldr r1, [r0]
	ldr r0, [r1]
	ldr r3, [r1, 0x4]
	movs r2, 0
	str r2, [sp]
	movs r1, 0x3
	str r1, [sp, 0x4]
	str r2, [sp, 0x8]
	str r2, [sp, 0xC]
	adds r1, 0xFE
	str r1, [sp, 0x10]
	movs r1, 0
	bl sub_8014248
	add sp, 0x14
	pop {r0}
	bx r0
	.align 2, 0
_0803CC38: .4byte gPersonalityQuestionPointerTable
_0803CC3C: .4byte gUnknown_203B400
	thumb_func_end PromptNewQuestion

        .align 2,0
