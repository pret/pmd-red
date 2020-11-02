	.include "constants/gba_constants.inc"
	.include "asm/macros.inc"

	.syntax unified

	.text

        thumb_func_start FatalErrorPrintFuncFileLine
FatalErrorPrintFuncFileLine:
	push {lr}
	sub sp, 0x100
	adds r2, r0, 0
	cmp r2, 0
	beq _08011B5E
	mov r0, sp
	bl PrintFuncFileLine
	b _08011B66
_08011B5E:
	ldr r2, _08011B6C
	mov r0, sp
	bl PrintFuncFileLine
_08011B66:
	add sp, 0x100
	pop {r0}
	bx r0
	.align 2, 0
_08011B6C: .4byte gUnknown_80D421C
	thumb_func_end FatalErrorPrintFuncFileLine

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
