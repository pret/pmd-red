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

	thumb_func_start sub_8012D60
sub_8012D60:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	adds r4, r0, 0
	adds r5, r3, 0
	ldr r7, [sp, 0x20]
	movs r3, 0
	movs r6, 0x1
	negs r6, r6
	mov r12, r3
	ldr r0, [sp, 0x24]
	str r0, [r4, 0x10]
	str r1, [r4, 0x4]
	str r2, [r4, 0x8]
	cmp r2, 0
	bne _08012D88
	ldr r0, _08012E00
	str r0, [r4, 0x8]
_08012D88:
	str r5, [r4, 0xC]
	ldr r0, [r1]
	adds r5, r4, 0
	adds r5, 0x14
	movs r2, 0x4C
	adds r2, r4
	mov r8, r2
	movs r2, 0x4D
	adds r2, r4
	mov r9, r2
	movs r2, 0x4E
	adds r2, r4
	mov r10, r2
	cmp r0, 0
	beq _08012DC6
_08012DA6:
	cmp r7, 0
	blt _08012DB2
	ldr r0, [r1, 0x4]
	cmp r7, r0
	bne _08012DB2
	adds r6, r3, 0
_08012DB2:
	ldr r0, [r1]
	ldrb r0, [r0]
	cmp r0, 0x2A
	bne _08012DBC
	mov r12, r3
_08012DBC:
	adds r1, 0x8
	adds r3, 0x1
	ldr r0, [r1]
	cmp r0, 0
	bne _08012DA6
_08012DC6:
	cmp r6, 0
	bge _08012DCC
	mov r6, r12
_08012DCC:
	adds r0, r5, 0
	adds r1, r3, 0
	ldr r2, [sp, 0x24]
	bl sub_8013134
	strh r6, [r4, 0x2C]
	adds r0, r5, 0
	movs r1, 0
	bl sub_80137B0
	movs r0, 0x1
	mov r1, r8
	strb r0, [r1]
	mov r2, r9
	strb r0, [r2]
	mov r1, r10
	strb r0, [r1]
	subs r0, 0x2
	str r0, [r4, 0x48]
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_08012E00: .4byte gUnknown_80D47B8
	thumb_func_end sub_8012D60

	thumb_func_start sub_8012E04
sub_8012E04:
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	adds r5, r0, 0
	adds r7, r1, 0
	mov r8, r2
	mov r9, r3
	ldr r3, [sp, 0x1C]
	movs r1, 0
	movs r6, 0x1
	negs r6, r6
	movs r4, 0
	ldr r0, [r7]
	cmp r0, 0
	beq _08012E46
	adds r2, r7, 0
_08012E26:
	cmp r3, 0
	blt _08012E32
	ldr r0, [r2, 0x4]
	cmp r3, r0
	bne _08012E32
	adds r6, r1, 0
_08012E32:
	ldr r0, [r2]
	ldrb r0, [r0]
	cmp r0, 0x2A
	bne _08012E3C
	adds r4, r1, 0
_08012E3C:
	adds r2, 0x8
	adds r1, 0x1
	ldr r0, [r2]
	cmp r0, 0
	bne _08012E26
_08012E46:
	cmp r6, 0
	bge _08012E4C
	adds r6, r4, 0
_08012E4C:
	adds r4, r5, 0
	adds r4, 0x14
	adds r0, r4, 0
	ldr r2, [sp, 0x20]
	bl sub_8013134
	strh r6, [r5, 0x2C]
	adds r0, r4, 0
	movs r1, 0
	bl sub_80137B0
	ldr r0, [sp, 0x20]
	str r0, [r5, 0x10]
	mov r0, r8
	str r0, [r5, 0x8]
	cmp r0, 0
	bne _08012E72
	ldr r0, _08012EA0
	str r0, [r5, 0x8]
_08012E72:
	mov r0, r9
	str r0, [r5, 0xC]
	str r7, [r5, 0x4]
	adds r1, r5, 0
	adds r1, 0x4E
	movs r0, 0
	strb r0, [r1]
	adds r0, r5, 0
	adds r0, 0x4C
	movs r1, 0x1
	strb r1, [r0]
	adds r0, 0x1
	strb r1, [r0]
	movs r0, 0x1
	negs r0, r0
	str r0, [r5, 0x48]
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_08012EA0: .4byte gUnknown_80D47B8
	thumb_func_end sub_8012E04

	thumb_func_start sub_8012EA4
sub_8012EA4:
	push {lr}
	adds r2, r0, 0
	adds r2, 0x4C
	strb r1, [r2]
	adds r2, 0x1
	movs r1, 0x1
	strb r1, [r2]
	bl sub_8012EBC
	pop {r0}
	bx r0
	thumb_func_end sub_8012EA4

	thumb_func_start sub_8012EBC
sub_8012EBC:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x164
	adds r5, r0, 0
	movs r0, 0x4D
	adds r0, r5
	mov r8, r0
	ldrb r0, [r0]
	cmp r0, 0
	beq _08012F9E
	ldr r0, [r5, 0x10]
	bl sub_80073B8
	ldr r2, [r5, 0x10]
	lsls r0, r2, 3
	adds r0, r2
	lsls r0, 3
	ldr r1, _08012F54
	adds r0, r1
	ldr r0, [r0, 0xC]
	cmp r0, 0x6
	bne _08012F24
	lsls r0, r2, 1
	adds r0, r2
	lsls r0, 3
	mov r4, sp
	adds r4, r0
	adds r4, 0x4
	add r0, sp, 0x4
	bl sub_8006518
	ldr r0, [r5]
	bl sub_8008ED0
	adds r1, r0, 0
	ldr r0, [r4, 0x14]
	ldrb r0, [r0, 0x2]
	lsls r0, 3
	subs r0, r1
	lsrs r1, r0, 31
	adds r0, r1
	asrs r0, 1
	adds r0, 0x8
	ldr r2, [r5]
	ldr r3, [r5, 0x10]
	movs r1, 0
	str r1, [sp]
	bl xxx_format_and_draw
_08012F24:
	ldr r7, [r5, 0x8]
	ldr r4, [r5, 0x4]
	ldr r6, [r5, 0xC]
	movs r1, 0
	mov r9, r1
	ldr r0, [r4]
	mov r10, r8
	cmp r0, 0
	beq _08012F92
	add r0, sp, 0x64
	mov r8, r0
_08012F3A:
	ldr r3, [r4]
	ldrb r0, [r3]
	cmp r0, 0x2A
	bne _08012F44
	adds r3, 0x1
_08012F44:
	cmp r6, 0
	beq _08012F58
	ldrh r0, [r6]
	lsls r0, 2
	adds r0, r7
	ldr r2, [r0]
	adds r6, 0x2
	b _08012F64
	.align 2, 0
_08012F54: .4byte gUnknown_2027370
_08012F58:
	ldr r0, [r4, 0x4]
	cmp r0, 0
	bge _08012F62
	ldr r2, [r7, 0x4]
	b _08012F64
_08012F62:
	ldr r2, [r7]
_08012F64:
	mov r0, r8
	ldr r1, _08012FBC
	bl sprintfStatic
	adds r0, r5, 0
	adds r0, 0x14
	mov r1, r9
	bl sub_8013800
	adds r1, r0, 0
	ldr r3, [r5, 0x10]
	movs r0, 0
	str r0, [sp]
	movs r0, 0x8
	mov r2, r8
	bl xxx_format_and_draw
	adds r4, 0x8
	movs r1, 0x1
	add r9, r1
	ldr r0, [r4]
	cmp r0, 0
	bne _08012F3A
_08012F92:
	ldr r0, [r5, 0x10]
	bl sub_80073E0
	movs r0, 0
	mov r1, r10
	strb r0, [r1]
_08012F9E:
	adds r0, r5, 0
	adds r0, 0x4E
	ldrb r0, [r0]
	cmp r0, 0
	beq _08012FC8
	adds r0, r5, 0
	adds r0, 0x4C
	ldrb r0, [r0]
	cmp r0, 0
	beq _08012FC0
	adds r0, r5, 0
	adds r0, 0x14
	bl AddMenuCursorSprite
	b _08012FC8
	.align 2, 0
_08012FBC: .4byte gUnknown_80D4828
_08012FC0:
	adds r0, r5, 0
	adds r0, 0x14
	bl sub_8013660
_08012FC8:
	add sp, 0x164
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_8012EBC

	.align 2, 0 @ Don't pad with nop.
