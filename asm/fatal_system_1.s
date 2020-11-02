	.include "constants/gba_constants.inc"
	.include "asm/macros.inc"

	.syntax unified

	.text	

	thumb_func_start Log
Log:
	push {r1-r3}
	add sp, 0xC
	bx lr
	thumb_func_end Log

	thumb_func_start sub_8011BC8
sub_8011BC8:
	push {r2,r3}
	add sp, 0x8
	bx lr
	thumb_func_end sub_8011BC8

	thumb_func_start nullsub_29
nullsub_29:
	bx lr
	thumb_func_end nullsub_29

	thumb_func_start nullsub_30
nullsub_30:
	bx lr
	thumb_func_end nullsub_30

	thumb_func_start nullsub_31
nullsub_31:
	bx lr
	thumb_func_end nullsub_31

	thumb_func_start nullsub_32
nullsub_32:
	bx lr
	thumb_func_end nullsub_32

	thumb_func_start FatalErrorHang
FatalErrorHang:
	push {lr}
	bl Hang
	pop {r0}
	bx r0
	thumb_func_end FatalErrorHang

	thumb_func_start FatalError
FatalError:
	push {r1-r3}
	push {r4,lr}
	sub sp, 0x100
	adds r1, r0, 0
	ldr r4, [sp, 0x108]
	ldr r0, _08011C14
	bl FatalErrorPrintFuncFileLine
	add r2, sp, 0x10C
	mov r0, sp
	adds r1, r4, 0
	bl vsprintf
	ldr r0, _08011C18
	mov r1, sp
	bl FatalErrorFormatMessage
	bl FatalErrorHang
	.align 2, 0
_08011C14: .4byte gFatalText
_08011C18: .4byte gUnknown_80D42D4
	thumb_func_end FatalError

        .align 2,0
