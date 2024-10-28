	#include "asm/constants/gba_constants.inc"
	#include "asm/macros.inc"

	.syntax unified
	.text


	thumb_func_start PrintFormatStringOnWindow
PrintFormatStringOnWindow:
	push {r4-r6,lr}
	mov r6, r8
	push {r6}
	sub sp, 0x1F8
	adds r5, r0, 0
	adds r6, r1, 0
	adds r0, r2, 0
	mov r8, r3
	ldr r4, [sp, 0x20C]
	add r2, sp, 0x1F8
	add r1, sp, 0x4
	movs r3, 0
	bl xxx_format_string
	ldr r1, _08015030
	add r1, sp
	movs r0, 0
	strb r0, [r1]
	str r4, [sp]
	adds r0, r5, 0
	adds r1, r6, 0
	add r2, sp, 0x4
	mov r3, r8
	bl PrintStringOnWindow
	add sp, 0x1F8
	pop {r3}
	mov r8, r3
	pop {r4-r6}
	pop {r0}
	bx r0
	.align 2, 0
_08015030: .4byte 0x000001f7
	thumb_func_end PrintFormatStringOnWindow

	thumb_func_start sub_8015034
sub_8015034:
	push {r4-r6,lr}
	mov r6, r9
	mov r5, r8
	push {r5,r6}
	sub sp, 0x1FC
	adds r6, r0, 0
	mov r8, r1
	adds r0, r2, 0
	mov r9, r3
	ldr r4, [sp, 0x214]
	ldr r5, [sp, 0x218]
	add r2, sp, 0x1FC
	add r1, sp, 0x8
	movs r3, 0
	bl xxx_format_string
	ldr r1, _0801507C
	add r1, sp
	movs r0, 0
	strb r0, [r1]
	str r4, [sp]
	str r5, [sp, 0x4]
	adds r0, r6, 0
	mov r1, r8
	add r2, sp, 0x8
	mov r3, r9
	bl sub_8008F8C
	add sp, 0x1FC
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r6}
	pop {r0}
	bx r0
	.align 2, 0
_0801507C: .4byte 0x000001fb
	thumb_func_end sub_8015034

    .align 2,0
