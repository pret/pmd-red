	.include "constants/gba_constants.inc"
	.include "asm/macros.inc"

	.syntax unified

	.text

	thumb_func_start FatalErrorFormatMessage
FatalErrorFormatMessage:
	push {r0-r3}
	push {lr}
	sub sp, 0x100
	ldr r1, [sp, 0x104]
	add r2, sp, 0x108
	mov r0, sp
	bl vsprintf
	add sp, 0x100
	pop {r3}
	add sp, 0x10
	bx r3
	thumb_func_end FatalErrorFormatMessage

	thumb_func_start sub_8011B88
sub_8011B88:
	push {r0-r3}
	push {lr}
	sub sp, 0x100
	ldr r1, [sp, 0x104]
	add r2, sp, 0x108
	mov r0, sp
	bl vsprintf
	add sp, 0x100
	pop {r3}
	add sp, 0x10
	bx r3
	thumb_func_end sub_8011B88

        .align 2,0
