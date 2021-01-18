	.include "constants/gba_constants.inc"
	.include "asm/macros.inc"

	.syntax unified

	.text	

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
