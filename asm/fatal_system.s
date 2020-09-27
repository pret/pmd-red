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

	thumb_func_start nullsub_28
nullsub_28:
	bx lr
	thumb_func_end nullsub_28

	thumb_func_start sub_8011BA4
sub_8011BA4:
	movs r0, 0
	bx lr
	thumb_func_end sub_8011BA4

	thumb_func_start sub_8011BA8
sub_8011BA8:
	movs r0, 0
	bx lr
	thumb_func_end sub_8011BA8

	thumb_func_start sub_8011BAC
sub_8011BAC:
	ldr r0, _08011BB0
	bx lr
	.align 2, 0
_08011BB0: .4byte gUnknown_80D4288
	thumb_func_end sub_8011BAC

	thumb_func_start sub_8011BB4
sub_8011BB4:
	push {lr}
	bl Hang
	pop {r0}
	bx r0
	thumb_func_end sub_8011BB4

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
_08011C14: .4byte gUnknown_80D42C0
_08011C18: .4byte gUnknown_80D42D4
	thumb_func_end FatalError

        .align 2,0
