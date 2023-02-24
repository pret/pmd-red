	#include "asm/constants/gba_constants.inc"
	#include "asm/macros.inc"

	.syntax unified

	.text

	thumb_func_start sub_8012BC4
sub_8012BC4:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x24
	mov r10, r0
	mov r9, r1
	adds r1, r2, 0
	adds r7, r3, 0
	movs r0, 0
	mov r8, r0
	add r0, sp, 0x4
	adds r2, r7, 0
	bl ConvertToDecimal
	subs r5, r7, 0x1
	cmp r5, 0
	ble _08012C0A
	lsls r0, r5, 2
	mov r1, sp
	adds r1, r0
	adds r1, 0x4
	ldr r0, [r1]
	cmp r0, 0
	bne _08012C0A
	movs r2, 0xFF
_08012BFA:
	str r2, [r1]
	subs r1, 0x4
	subs r5, 0x1
	cmp r5, 0
	ble _08012C0A
	ldr r0, [r1]
	cmp r0, 0
	beq _08012BFA
_08012C0A:
	movs r5, 0
	cmp r5, r7
	bge _08012C50
	ldr r0, [sp, 0x4]
	cmp r0, 0xFF
	beq _08012C50
	add r6, sp, 0x4
_08012C18:
	ldm r6!, {r0}
	adds r0, 0x30
	lsls r0, 24
	lsrs r0, 24
	bl ReturnIntFromChar2
	adds r4, r0, 0
	bl GetCharacter
	movs r1, 0x6
	ldrsh r0, [r0, r1]
	add r8, r0
	mov r2, r10
	mov r1, r8
	subs r0, r2, r1
	ldr r2, [sp, 0x48]
	str r2, [sp]
	mov r1, r9
	adds r2, r4, 0
	ldr r3, [sp, 0x44]
	bl xxx_call_draw_char
	adds r5, 0x1
	cmp r5, r7
	bge _08012C50
	ldr r0, [r6]
	cmp r0, 0xFF
	bne _08012C18
_08012C50:
	add sp, 0x24
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_8012BC4

	thumb_func_start sub_8012C60
sub_8012C60:
	push {r4-r7,lr}
	sub sp, 0x4
	adds r5, r0, 0
	adds r6, r1, 0
	adds r0, r2, 0
	adds r7, r3, 0
	lsls r0, 24
	lsrs r0, 24
	bl ReturnIntFromChar2
	adds r4, r0, 0
	bl GetCharacter
	adds r1, r0, 0
	movs r2, 0x6
	ldrsh r0, [r1, r2]
	cmp r0, 0xB
	bgt _08012C90
	movs r1, 0xC
	subs r1, r0
	lsrs r0, r1, 31
	adds r1, r0
	asrs r0, r1, 1
	b _08012C92
_08012C90:
	movs r0, 0
_08012C92:
	adds r0, r5, r0
	ldr r1, [sp, 0x18]
	str r1, [sp]
	adds r1, r6, 0
	adds r2, r4, 0
	adds r3, r7, 0
	bl xxx_call_draw_char
	add sp, 0x4
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_8012C60

	thumb_func_start sub_8012CAC
sub_8012CAC:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	mov r8, r0
	adds r4, r1, 0
	movs r7, 0
	movs r6, 0
	ldr r0, [r4]
	cmp r0, 0
	beq _08012CE6
	movs r5, 0x80
	lsls r5, 9
_08012CC4:
	adds r0, r5, 0
	movs r1, 0x80
	lsls r1, 9
	adds r5, r1
	asrs r7, r0, 16
	ldr r0, [r4]
	bl sub_8008ED0
	lsls r0, 16
	asrs r0, 16
	cmp r0, r6
	ble _08012CDE
	adds r6, r0, 0
_08012CDE:
	adds r4, 0x8
	ldr r0, [r4]
	cmp r0, 0
	bne _08012CC4
_08012CE6:
	adds r0, r6, 0
	cmp r0, 0
	bge _08012CEE
	adds r0, 0x7
_08012CEE:
	asrs r0, 3
	adds r0, 0x2
	mov r1, r8
	strh r0, [r1, 0xC]
	mov r0, r8
	adds r1, r7, 0
	bl sub_8012D08
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_8012CAC

	thumb_func_start sub_8012D08
sub_8012D08:
	push {r4,lr}
	adds r4, r0, 0
	adds r0, r1, 0
	movs r1, 0xC
	bl sub_80095E4
	lsls r0, 16
	asrs r1, r0, 16
	ldr r0, [r4, 0x4]
	cmp r0, 0x6
	bne _08012D24
	adds r0, r1, 0x2
	lsls r0, 16
	asrs r1, r0, 16
_08012D24:
	lsls r0, r1, 16
	lsrs r0, 16
	strh r0, [r4, 0xE]
	strh r0, [r4, 0x10]
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_8012D08

	thumb_func_start sub_8012D34
sub_8012D34:
	push {r4,lr}
	adds r4, r0, 0
	adds r0, r1, 0
	movs r1, 0x18
	bl sub_8009614
	lsls r0, 16
	asrs r1, r0, 16
	ldr r0, [r4, 0x4]
	cmp r0, 0x6
	bne _08012D50
	adds r0, r1, 0x2
	lsls r0, 16
	asrs r1, r0, 16
_08012D50:
	lsls r0, r1, 16
	lsrs r0, 16
	strh r0, [r4, 0xE]
	strh r0, [r4, 0x10]
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_8012D34

	.align 2, 0 @ Don't pad with nop.
