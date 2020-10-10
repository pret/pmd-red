	.include "constants/gba_constants.inc"
	.include "asm/macros.inc"

	.syntax unified

	.text

	thumb_func_start GetKeyPress
GetKeyPress:
	push {lr}
	adds r1, r0, 0
	cmp r1, 0
	beq _08012ADE
	adds r0, 0x29
	ldrb r0, [r0]
	cmp r0, 0
	beq _08012AB4
	movs r0, 0x1
	b _08012AE2
_08012AB4:
	adds r0, r1, 0
	adds r0, 0x2A
	ldrb r0, [r0]
	cmp r0, 0
	beq _08012AC2
	movs r0, 0x2
	b _08012AE2
_08012AC2:
	adds r0, r1, 0
	adds r0, 0x2C
	ldrb r0, [r0]
	cmp r0, 0
	beq _08012AD0
	movs r0, 0x9
	b _08012AE2
_08012AD0:
	adds r0, r1, 0
	adds r0, 0x2B
	ldrb r0, [r0]
	cmp r0, 0
	beq _08012ADE
	movs r0, 0xA
	b _08012AE2
_08012ADE:
	bl sub_8012AE8
_08012AE2:
	pop {r1}
	bx r1
	thumb_func_end GetKeyPress

	thumb_func_start sub_8012AE8
sub_8012AE8:
	push {lr}
	ldr r2, _08012B08
	ldrh r1, [r2]
	movs r3, 0x80
	lsls r3, 1
	adds r0, r3, 0
	ands r0, r1
	cmp r0, 0
	beq _08012B4A
	ldrh r1, [r2, 0x2]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _08012B0C
	movs r0, 0xB
	b _08012BBE
	.align 2, 0
_08012B08: .4byte gUnknown_20255F0
_08012B0C:
	ldrh r1, [r2, 0x4]
	movs r0, 0x40
	ands r0, r1
	cmp r0, 0
	beq _08012B1A
	movs r0, 0xC
	b _08012BBE
_08012B1A:
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	beq _08012B26
	movs r0, 0xD
	b _08012BBE
_08012B26:
	movs r0, 0x20
	ands r0, r1
	cmp r0, 0
	beq _08012B32
	movs r0, 0xE
	b _08012BBE
_08012B32:
	movs r0, 0x10
	ands r0, r1
	cmp r0, 0
	beq _08012B3E
	movs r0, 0xF
	b _08012BBE
_08012B3E:
	adds r0, r3, 0
	ands r0, r1
	cmp r0, 0
	beq _08012BBC
	movs r0, 0x6
	b _08012BBE
_08012B4A:
	ldrh r1, [r2, 0x2]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _08012B58
	movs r0, 0x1
	b _08012BBE
_08012B58:
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	beq _08012B64
	movs r0, 0x2
	b _08012BBE
_08012B64:
	movs r0, 0x4
	ands r0, r1
	cmp r0, 0
	beq _08012B70
	movs r0, 0x3
	b _08012BBE
_08012B70:
	movs r0, 0x8
	ands r0, r1
	cmp r0, 0
	beq _08012B7C
	movs r0, 0x4
	b _08012BBE
_08012B7C:
	ldrh r1, [r2, 0x4]
	movs r0, 0x40
	ands r0, r1
	cmp r0, 0
	beq _08012B8A
	movs r0, 0x7
	b _08012BBE
_08012B8A:
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	beq _08012B96
	movs r0, 0x8
	b _08012BBE
_08012B96:
	movs r0, 0x20
	ands r0, r1
	cmp r0, 0
	beq _08012BA2
	movs r0, 0x9
	b _08012BBE
_08012BA2:
	movs r0, 0x10
	ands r0, r1
	cmp r0, 0
	beq _08012BAE
	movs r0, 0xA
	b _08012BBE
_08012BAE:
	movs r0, 0x80
	lsls r0, 2
	ands r0, r1
	cmp r0, 0
	beq _08012BBC
	movs r0, 0x5
	b _08012BBE
_08012BBC:
	movs r0, 0
_08012BBE:
	pop {r1}
	bx r1
	thumb_func_end sub_8012AE8

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
	bl sub_8092288
	adds r4, r0, 0
	bl sub_8008584
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
	bl sub_8092288
	adds r4, r0, 0
	bl sub_8008584
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
	bl sub_8014FF0
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
	bl sub_800D158
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
	bl sub_8014FF0
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

	thumb_func_start sub_8012FD8
sub_8012FD8:
	push {r4-r7,lr}
	adds r4, r0, 0
	movs r0, 0x2C
	ldrsh r7, [r4, r0]
	adds r6, r4, 0
	adds r6, 0x4C
	ldrb r0, [r6]
	cmp r0, 0
	beq _08013094
	adds r5, r4, 0
	adds r5, 0x14
	adds r0, r5, 0
	bl GetKeyPress
	cmp r0, 0x2
	beq _08013078
	cmp r0, 0x2
	bgt _08013002
	cmp r0, 0x1
	beq _08013028
	b _08013094
_08013002:
	cmp r0, 0x7
	beq _08013012
	cmp r0, 0x8
	bne _08013094
	adds r0, r5, 0
	bl MoveMenuCursorDown
	b _08013018
_08013012:
	adds r0, r5, 0
	bl MoveMenuCursorUp
_08013018:
	movs r1, 0x2C
	ldrsh r0, [r4, r1]
	cmp r7, r0
	beq _08013094
	movs r0, 0x3
	bl sub_80119D4
	b _08013094
_08013028:
	adds r0, r5, 0
	bl sub_80137A8
	adds r2, r0, 0
	lsls r1, r2, 3
	ldr r0, [r4, 0x4]
	adds r0, r1
	ldr r3, [r0, 0x4]
	cmp r3, 0
	blt _08013068
	ldr r1, [r4, 0xC]
	cmp r1, 0
	beq _0801304C
	lsls r0, r2, 1
	adds r0, r1
	ldrh r0, [r0]
	cmp r0, 0x1
	beq _08013068
_0801304C:
	str r3, [r4, 0x48]
	adds r1, r4, 0
	adds r1, 0x4C
	movs r0, 0
	strb r0, [r1]
	strh r0, [r4, 0x38]
	ldr r1, [r4, 0xC]
	cmp r1, 0
	beq _08013070
	lsls r0, r2, 1
	adds r0, r1
	ldrh r0, [r0]
	cmp r0, 0x2
	bne _08013070
_08013068:
	movs r0, 0x2
	bl sub_80119D4
	b _08013094
_08013070:
	movs r0, 0
	bl sub_80119D4
	b _08013094
_08013078:
	movs r1, 0x2E
	ldrsh r0, [r4, r1]
	ldr r1, [r4, 0x4]
	lsls r0, 3
	adds r0, r1
	ldr r0, [r0, 0x4]
	cmp r0, 0
	blt _08013094
	str r0, [r4, 0x48]
	movs r0, 0
	strb r0, [r6]
	movs r0, 0x1
	bl sub_80119D4
_08013094:
	adds r0, r4, 0
	bl sub_8012EBC
	adds r0, r4, 0
	adds r0, 0x4C
	ldrb r0, [r0]
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_8012FD8

	thumb_func_start sub_80130A8
sub_80130A8:
	push {r4-r6,lr}
	adds r4, r0, 0
	adds r6, r4, 0
	adds r6, 0x4C
	ldrb r0, [r6]
	cmp r0, 0
	beq _08013100
	adds r5, r4, 0
	adds r5, 0x14
	adds r0, r5, 0
	bl GetKeyPress
	cmp r0, 0x1
	beq _080130CA
	cmp r0, 0x2
	beq _080130E6
	b _08013100
_080130CA:
	adds r0, r5, 0
	bl sub_80137A8
	lsls r0, 3
	ldr r1, [r4, 0x4]
	adds r1, r0
	ldr r0, [r1, 0x4]
	str r0, [r4, 0x48]
	movs r0, 0
	strb r0, [r6]
	strh r0, [r4, 0x38]
	bl sub_80119D4
	b _08013100
_080130E6:
	movs r1, 0x2E
	ldrsh r0, [r4, r1]
	ldr r1, [r4, 0x4]
	lsls r0, 3
	adds r0, r1
	ldr r0, [r0, 0x4]
	cmp r0, 0
	blt _08013100
	str r0, [r4, 0x48]
	movs r0, 0
	strb r0, [r6]
	bl sub_80119D4
_08013100:
	adds r0, r4, 0
	bl sub_8012EBC
	adds r0, r4, 0
	adds r0, 0x4C
	ldrb r0, [r0]
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end sub_80130A8

	thumb_func_start sub_8013114
sub_8013114:
	push {lr}
	adds r2, r0, 0
	adds r0, 0x4C
	ldrb r0, [r0]
	cmp r0, 0
	beq _08013124
	movs r0, 0x1
	b _0801312E
_08013124:
	cmp r1, 0
	beq _0801312C
	ldr r0, [r2, 0x48]
	str r0, [r1]
_0801312C:
	movs r0, 0
_0801312E:
	pop {r1}
	bx r1
	thumb_func_end sub_8013114

	thumb_func_start sub_8013134
sub_8013134:
	push {r4,lr}
	adds r4, r0, 0
	lsls r0, r2, 3
	adds r0, r2
	lsls r0, 3
	ldr r3, _0801315C
	adds r0, r3
	str r2, [r4]
	movs r2, 0
	strh r2, [r4, 0x18]
	strh r1, [r4, 0x1A]
	strh r1, [r4, 0x1C]
	strh r2, [r4, 0x1E]
	strh r2, [r4, 0x4]
	ldr r0, [r0, 0xC]
	cmp r0, 0x6
	bne _08013160
	movs r0, 0x10
	b _08013162
	.align 2, 0
_0801315C: .4byte gUnknown_2027370
_08013160:
	movs r0, 0x2
_08013162:
	strh r0, [r4, 0x6]
	movs r0, 0
	strh r0, [r4, 0xC]
	strh r0, [r4, 0xE]
	strh r0, [r4, 0x14]
	strh r0, [r4, 0x24]
	adds r0, r4, 0
	adds r0, 0x28
	bl sub_801317C
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_8013134

	thumb_func_start sub_801317C
sub_801317C:
	push {lr}
	movs r1, 0
	strb r1, [r0]
	strb r1, [r0, 0x1]
	strb r1, [r0, 0x2]
	strb r1, [r0, 0x4]
	strb r1, [r0, 0x3]
	ldr r1, _080131A4
	strh r1, [r0, 0x8]
	movs r1, 0x1
	negs r1, r1
	strh r1, [r0, 0xA]
	adds r0, 0x8
	bl nullsub_7
	bl sub_8004914
	pop {r0}
	bx r0
	.align 2, 0
_080131A4: .4byte 0x0000ffff
	thumb_func_end sub_801317C

	thumb_func_start AddMenuCursorSprite
AddMenuCursorSprite:
	push {lr}
	movs r1, 0
	bl AddMenuCursorSprite_
	pop {r0}
	bx r0
	thumb_func_end AddMenuCursorSprite

	thumb_func_start AddMenuCursorSprite_
AddMenuCursorSprite_:
	push {r4-r6,lr}
	sub sp, 0x8
	adds r6, r0, 0
	movs r0, 0
	movs r1, 0
	str r0, [sp]
	str r1, [sp, 0x4]
	movs r1, 0x1A
	ldrsh r0, [r6, r1]
	cmp r0, 0
	bgt _080131CC
	b _080132D6
_080131CC:
	adds r0, r6, 0
	bl UpdateMenuCursorSpriteCoords
	ldrh r1, [r6, 0x24]
	movs r0, 0x8
	ands r0, r1
	cmp r0, 0
	bne _080132D6
	mov r0, sp
	ldrh r0, [r0]
	ldr r1, _080132FC
	ands r1, r0
	ldr r3, _08013300
	ldr r0, [sp]
	ands r0, r3
	orrs r0, r1
	str r0, [sp]
	mov r1, sp
	ldrh r1, [r1]
	adds r2, r3, 0
	ands r2, r0
	orrs r2, r1
	str r2, [sp]
	mov r0, sp
	ldrh r1, [r0]
	ldr r0, _08013304
	ands r0, r1
	adds r1, r3, 0
	ands r1, r2
	orrs r1, r0
	str r1, [sp]
	mov r0, sp
	ldrh r0, [r0]
	adds r2, r3, 0
	ands r2, r1
	orrs r2, r0
	str r2, [sp]
	mov r0, sp
	ldrh r1, [r0]
	ldr r4, _08013308
	adds r0, r4, 0
	ands r0, r1
	adds r1, r3, 0
	ands r1, r2
	orrs r1, r0
	str r1, [sp]
	mov r0, sp
	ldrh r0, [r0]
	adds r2, r3, 0
	ands r2, r1
	orrs r2, r0
	str r2, [sp]
	mov r0, sp
	ldrh r1, [r0]
	ldr r0, _0801330C
	ands r0, r1
	adds r1, r3, 0
	ands r1, r2
	orrs r1, r0
	str r1, [sp]
	mov r0, sp
	ldrh r0, [r0]
	adds r2, r3, 0
	ands r2, r1
	orrs r2, r0
	str r2, [sp]
	mov r0, sp
	ldrh r1, [r0]
	ldr r0, _08013310
	ands r0, r1
	adds r1, r3, 0
	ands r1, r2
	orrs r1, r0
	str r1, [sp]
	mov r0, sp
	ldrh r0, [r0]
	adds r2, r3, 0
	ands r2, r1
	orrs r2, r0
	str r2, [sp]
	mov r0, sp
	ldrh r1, [r0]
	ldr r0, _08013314
	ands r0, r1
	adds r1, r3, 0
	ands r1, r2
	orrs r1, r0
	str r1, [sp]
	mov r0, sp
	ldrh r0, [r0]
	ands r3, r1
	orrs r3, r0
	str r3, [sp]
	mov r3, sp
	movs r2, 0xFD
	lsls r2, 2
	ldrh r1, [r3, 0x4]
	movs r0, 0xFC
	lsls r0, 8
	ands r0, r1
	orrs r0, r2
	ands r0, r4
	movs r5, 0xF
	movs r1, 0xF0
	lsls r1, 8
	ldr r4, _08013318
	ands r0, r4
	orrs r0, r1
	strh r0, [r3, 0x4]
	ldrh r0, [r3, 0x6]
	ldr r1, _0801331C
	ands r1, r0
	ldr r0, _08013320
	ands r1, r0
	movs r2, 0x8
	ldrsh r0, [r6, r2]
	ldr r2, _08013324
	ands r0, r2
	strh r0, [r3, 0x2]
	movs r2, 0xA
	ldrsh r0, [r6, r2]
	adds r0, 0x1
	ands r0, r4
	lsls r0, 4
	ands r1, r5
	orrs r1, r0
	strh r1, [r3, 0x6]
	mov r0, sp
	movs r1, 0xFF
	movs r2, 0
	movs r3, 0
	bl AddSprite
_080132D6:
	adds r0, r6, 0
	bl sub_8013470
	movs r1, 0x14
	ldrsh r0, [r6, r1]
	cmp r0, 0
	beq _080132EC
	adds r0, r6, 0
	adds r0, 0x14
	bl sub_801332C
_080132EC:
	ldrh r0, [r6, 0x24]
	adds r0, 0x1
	strh r0, [r6, 0x24]
	add sp, 0x8
	pop {r4-r6}
	pop {r0}
	bx r0
	.align 2, 0
_080132FC: .4byte 0x0000feff
_08013300: .4byte 0xffff0000
_08013304: .4byte 0x0000fdff
_08013308: .4byte 0x0000f3ff
_0801330C: .4byte 0x0000efff
_08013310: .4byte 0x0000dfff
_08013314: .4byte 0x00003fff
_08013318: .4byte 0x00000fff
_0801331C: .4byte 0x0000fffe
_08013320: .4byte 0x0000fffd
_08013324: .4byte 0x000001ff
	thumb_func_end AddMenuCursorSprite_

	thumb_func_start nullsub_34
nullsub_34:
	bx lr
	thumb_func_end nullsub_34

	thumb_func_start sub_801332C
sub_801332C:
	push {r4-r6,lr}
	sub sp, 0x8
	movs r1, 0
	movs r2, 0
	str r1, [sp]
	str r2, [sp, 0x4]
	mov r1, sp
	ldrh r1, [r1]
	ldr r2, _08013440
	ands r2, r1
	ldr r4, _08013444
	ldr r1, [sp]
	ands r1, r4
	orrs r1, r2
	str r1, [sp]
	mov r2, sp
	ldrh r2, [r2]
	adds r3, r4, 0
	ands r3, r1
	orrs r3, r2
	str r3, [sp]
	mov r1, sp
	ldrh r2, [r1]
	ldr r1, _08013448
	ands r1, r2
	adds r2, r4, 0
	ands r2, r3
	orrs r2, r1
	str r2, [sp]
	mov r1, sp
	ldrh r1, [r1]
	adds r3, r4, 0
	ands r3, r2
	orrs r3, r1
	str r3, [sp]
	movs r5, 0x80
	lsls r5, 3
	mov r1, sp
	ldrh r2, [r1]
	ldr r6, _0801344C
	adds r1, r6, 0
	ands r1, r2
	adds r2, r4, 0
	ands r2, r3
	orrs r2, r1
	str r2, [sp]
	mov r1, sp
	ldrh r1, [r1]
	orrs r5, r1
	adds r3, r4, 0
	ands r3, r2
	orrs r3, r5
	str r3, [sp]
	mov r1, sp
	ldrh r2, [r1]
	ldr r1, _08013450
	ands r1, r2
	adds r2, r4, 0
	ands r2, r3
	orrs r2, r1
	str r2, [sp]
	mov r1, sp
	ldrh r1, [r1]
	adds r3, r4, 0
	ands r3, r2
	orrs r3, r1
	str r3, [sp]
	mov r1, sp
	ldrh r2, [r1]
	ldr r1, _08013454
	ands r1, r2
	adds r2, r4, 0
	ands r2, r3
	orrs r2, r1
	str r2, [sp]
	mov r1, sp
	ldrh r1, [r1]
	adds r3, r4, 0
	ands r3, r2
	orrs r3, r1
	str r3, [sp]
	mov r1, sp
	ldrh r2, [r1]
	ldr r1, _08013458
	ands r1, r2
	adds r2, r4, 0
	ands r2, r3
	orrs r2, r1
	str r2, [sp]
	mov r1, sp
	ldrh r1, [r1]
	ands r4, r2
	orrs r4, r1
	str r4, [sp]
	mov r4, sp
	ldr r3, _0801345C
	ldrh r2, [r4, 0x4]
	movs r1, 0xFC
	lsls r1, 8
	ands r1, r2
	orrs r1, r3
	ands r1, r6
	movs r6, 0xF
	movs r2, 0xF0
	lsls r2, 8
	ldr r5, _08013460
	ands r1, r5
	orrs r1, r2
	strh r1, [r4, 0x4]
	ldrh r1, [r4, 0x6]
	ldr r2, _08013464
	ands r2, r1
	ldr r1, _08013468
	ands r2, r1
	movs r3, 0
	ldrsh r1, [r0, r3]
	ldr r3, _0801346C
	ands r1, r3
	strh r1, [r4, 0x2]
	movs r1, 0x2
	ldrsh r0, [r0, r1]
	adds r0, 0x1
	ands r0, r5
	lsls r0, 4
	ands r2, r6
	orrs r2, r0
	strh r2, [r4, 0x6]
	mov r0, sp
	movs r1, 0xFF
	movs r2, 0
	movs r3, 0
	bl AddSprite
	add sp, 0x8
	pop {r4-r6}
	pop {r0}
	bx r0
	.align 2, 0
_08013440: .4byte 0x0000feff
_08013444: .4byte 0xffff0000
_08013448: .4byte 0x0000fdff
_0801344C: .4byte 0x0000f3ff
_08013450: .4byte 0x0000efff
_08013454: .4byte 0x0000dfff
_08013458: .4byte 0x00003fff
_0801345C: .4byte 0x000003f5
_08013460: .4byte 0x00000fff
_08013464: .4byte 0x0000fffe
_08013468: .4byte 0x0000fffd
_0801346C: .4byte 0x000001ff
	thumb_func_end sub_801332C

	thumb_func_start sub_8013470
sub_8013470:
	push {r4-r6,lr}
	sub sp, 0x8
	adds r6, r0, 0
	movs r0, 0
	movs r1, 0
	str r0, [sp]
	str r1, [sp, 0x4]
	movs r1, 0xC
	ldrsh r0, [r6, r1]
	cmp r0, 0
	bne _08013488
	b _08013624
_08013488:
	movs r2, 0x1E
	ldrsh r0, [r6, r2]
	cmp r0, 0
	beq _08013586
	mov r0, sp
	ldrh r0, [r0]
	ldr r1, _0801362C
	ands r1, r0
	ldr r3, _08013630
	ldr r0, [sp]
	ands r0, r3
	orrs r0, r1
	str r0, [sp]
	mov r1, sp
	ldrh r1, [r1]
	adds r2, r3, 0
	ands r2, r0
	orrs r2, r1
	str r2, [sp]
	mov r0, sp
	ldrh r1, [r0]
	ldr r0, _08013634
	ands r0, r1
	adds r1, r3, 0
	ands r1, r2
	orrs r1, r0
	str r1, [sp]
	mov r0, sp
	ldrh r0, [r0]
	adds r2, r3, 0
	ands r2, r1
	orrs r2, r0
	str r2, [sp]
	mov r0, sp
	ldrh r1, [r0]
	ldr r4, _08013638
	adds r0, r4, 0
	ands r0, r1
	adds r1, r3, 0
	ands r1, r2
	orrs r1, r0
	str r1, [sp]
	mov r0, sp
	ldrh r0, [r0]
	adds r2, r3, 0
	ands r2, r1
	orrs r2, r0
	str r2, [sp]
	mov r0, sp
	ldrh r1, [r0]
	ldr r0, _0801363C
	ands r0, r1
	adds r1, r3, 0
	ands r1, r2
	orrs r1, r0
	str r1, [sp]
	mov r0, sp
	ldrh r0, [r0]
	adds r2, r3, 0
	ands r2, r1
	orrs r2, r0
	str r2, [sp]
	mov r0, sp
	ldrh r1, [r0]
	ldr r0, _08013640
	ands r0, r1
	adds r1, r3, 0
	ands r1, r2
	orrs r1, r0
	str r1, [sp]
	mov r0, sp
	ldrh r0, [r0]
	adds r2, r3, 0
	ands r2, r1
	orrs r2, r0
	str r2, [sp]
	mov r0, sp
	ldrh r1, [r0]
	ldr r0, _08013644
	ands r0, r1
	adds r1, r3, 0
	ands r1, r2
	orrs r1, r0
	str r1, [sp]
	mov r0, sp
	ldrh r0, [r0]
	ands r3, r1
	orrs r3, r0
	str r3, [sp]
	mov r3, sp
	ldr r2, _08013648
	ldrh r1, [r3, 0x4]
	movs r0, 0xFC
	lsls r0, 8
	ands r0, r1
	orrs r0, r2
	ands r0, r4
	movs r5, 0xF
	movs r1, 0xF0
	lsls r1, 8
	ldr r4, _0801364C
	ands r0, r4
	orrs r0, r1
	strh r0, [r3, 0x4]
	ldrh r0, [r3, 0x6]
	ldr r1, _08013650
	ands r1, r0
	ldr r0, _08013654
	ands r1, r0
	movs r2, 0xC
	ldrsh r0, [r6, r2]
	ldr r2, _08013658
	ands r0, r2
	strh r0, [r3, 0x2]
	movs r2, 0xE
	ldrsh r0, [r6, r2]
	ands r0, r4
	lsls r0, 4
	ands r1, r5
	orrs r1, r0
	strh r1, [r3, 0x6]
	mov r0, sp
	movs r1, 0xFF
	movs r2, 0
	movs r3, 0
	bl AddSprite
_08013586:
	movs r1, 0x20
	ldrsh r0, [r6, r1]
	cmp r0, 0
	beq _08013624
	adds r1, r0, 0
	movs r2, 0x1E
	ldrsh r0, [r6, r2]
	adds r0, 0x1
	cmp r1, r0
	beq _08013624
	mov r0, sp
	ldrh r0, [r0]
	ldr r1, _0801362C
	ands r1, r0
	mov r0, sp
	strh r1, [r0]
	strh r1, [r0]
	ldr r0, _08013634
	ands r0, r1
	mov r1, sp
	strh r0, [r1]
	strh r0, [r1]
	ldr r4, _08013638
	ands r0, r4
	strh r0, [r1]
	strh r0, [r1]
	ldr r1, _0801363C
	ands r1, r0
	mov r0, sp
	strh r1, [r0]
	strh r1, [r0]
	ldr r2, _08013640
	ands r2, r1
	strh r2, [r0]
	strh r2, [r0]
	ldr r0, _08013644
	ands r0, r2
	mov r1, sp
	strh r0, [r1]
	strh r0, [r1]
	mov r3, sp
	ldr r2, _0801365C
	ldrh r1, [r3, 0x4]
	movs r0, 0xFC
	lsls r0, 8
	ands r0, r1
	orrs r0, r2
	ands r0, r4
	movs r5, 0xF
	movs r1, 0xF0
	lsls r1, 8
	ldr r4, _0801364C
	ands r0, r4
	orrs r0, r1
	strh r0, [r3, 0x4]
	ldrh r0, [r3, 0x6]
	ldr r1, _08013650
	ands r1, r0
	ldr r0, _08013654
	ands r1, r0
	movs r2, 0xC
	ldrsh r0, [r6, r2]
	adds r0, 0xA
	ldr r2, _08013658
	ands r0, r2
	strh r0, [r3, 0x2]
	movs r2, 0xE
	ldrsh r0, [r6, r2]
	ands r0, r4
	lsls r0, 4
	ands r1, r5
	orrs r1, r0
	strh r1, [r3, 0x6]
	mov r0, sp
	movs r1, 0xFF
	movs r2, 0
	movs r3, 0
	bl AddSprite
_08013624:
	add sp, 0x8
	pop {r4-r6}
	pop {r0}
	bx r0
	.align 2, 0
_0801362C: .4byte 0x0000feff
_08013630: .4byte 0xffff0000
_08013634: .4byte 0x0000fdff
_08013638: .4byte 0x0000f3ff
_0801363C: .4byte 0x0000efff
_08013640: .4byte 0x0000dfff
_08013644: .4byte 0x00003fff
_08013648: .4byte 0x000003f2
_0801364C: .4byte 0x00000fff
_08013650: .4byte 0x0000fffe
_08013654: .4byte 0x0000fffd
_08013658: .4byte 0x000001ff
_0801365C: .4byte 0x000003f3
	thumb_func_end sub_8013470

	thumb_func_start sub_8013660
sub_8013660:
	push {r4,lr}
	adds r4, r0, 0
	movs r1, 0x1A
	ldrsh r0, [r4, r1]
	cmp r0, 0
	ble _0801367A
	adds r0, r4, 0
	bl UpdateMenuCursorSpriteCoords
	adds r0, r4, 0
	adds r0, 0x8
	bl sub_801332C
_0801367A:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_8013660

	thumb_func_start UpdateMenuCursorSpriteCoords
UpdateMenuCursorSpriteCoords:
	push {r4,r5,lr}
	adds r5, r0, 0
	ldr r0, [r5]
	lsls r4, r0, 3
	adds r4, r0
	lsls r4, 3
	ldr r0, _080136B8
	adds r4, r0
	movs r1, 0
	ldrsh r0, [r4, r1]
	lsls r0, 3
	ldrh r2, [r5, 0x4]
	adds r0, r2
	strh r0, [r5, 0x8]
	movs r0, 0x18
	ldrsh r1, [r5, r0]
	adds r0, r5, 0
	bl sub_8013800
	movs r2, 0x2
	ldrsh r1, [r4, r2]
	lsls r1, 3
	adds r1, r0
	strh r1, [r5, 0xA]
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_080136B8: .4byte gUnknown_2027370
	thumb_func_end UpdateMenuCursorSpriteCoords

	thumb_func_start MoveMenuCursorDown
MoveMenuCursorDown:
	push {lr}
	adds r1, r0, 0
	movs r3, 0
	strh r3, [r1, 0x24]
	movs r0, 0x1A
	ldrsh r2, [r1, r0]
	cmp r2, 0
	ble _080136DA
	ldrh r0, [r1, 0x18]
	adds r0, 0x1
	strh r0, [r1, 0x18]
	lsls r0, 16
	asrs r0, 16
	cmp r0, r2
	blt _080136DC
_080136DA:
	strh r3, [r1, 0x18]
_080136DC:
	pop {r0}
	bx r0
	thumb_func_end MoveMenuCursorDown

	thumb_func_start sub_80136E0
sub_80136E0:
	push {r4,r5,lr}
	adds r2, r0, 0
	lsls r1, 24
	lsrs r5, r1, 24
	movs r1, 0
	strh r1, [r2, 0x24]
	ldrh r4, [r2, 0x1A]
	movs r0, 0x1A
	ldrsh r3, [r2, r0]
	cmp r3, 0
	ble _08013708
	ldrh r0, [r2, 0x18]
	adds r0, 0x1
	strh r0, [r2, 0x18]
	lsls r0, 16
	asrs r0, 16
	cmp r0, r3
	blt _08013710
	cmp r5, 0
	beq _0801370C
_08013708:
	strh r1, [r2, 0x18]
	b _08013710
_0801370C:
	subs r0, r4, 0x1
	strh r0, [r2, 0x18]
_08013710:
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_80136E0

	thumb_func_start MoveMenuCursorUp
MoveMenuCursorUp:
	push {r4,lr}
	adds r1, r0, 0
	movs r2, 0
	strh r2, [r1, 0x24]
	ldrh r3, [r1, 0x1A]
	movs r4, 0x1A
	ldrsh r0, [r1, r4]
	cmp r0, 0
	bgt _0801372E
	strh r2, [r1, 0x18]
	b _0801373E
_0801372E:
	ldrh r0, [r1, 0x18]
	subs r0, 0x1
	strh r0, [r1, 0x18]
	lsls r0, 16
	cmp r0, 0
	bge _0801373E
	subs r0, r3, 0x1
	strh r0, [r1, 0x18]
_0801373E:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end MoveMenuCursorUp

	thumb_func_start sub_8013744
sub_8013744:
	push {r4-r6,lr}
	adds r2, r0, 0
	lsls r1, 24
	lsrs r1, 24
	adds r5, r1, 0
	movs r3, 0
	strh r3, [r2, 0x24]
	ldrh r4, [r2, 0x1A]
	movs r6, 0x1A
	ldrsh r0, [r2, r6]
	cmp r0, 0
	bgt _08013760
	strh r3, [r2, 0x18]
	b _08013778
_08013760:
	ldrh r0, [r2, 0x18]
	subs r0, 0x1
	strh r0, [r2, 0x18]
	lsls r0, 16
	cmp r0, 0
	bge _08013778
	cmp r1, 0
	beq _08013776
	subs r0, r4, 0x1
	strh r0, [r2, 0x18]
	b _08013778
_08013776:
	strh r5, [r2, 0x18]
_08013778:
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end sub_8013744

	thumb_func_start sub_8013780
sub_8013780:
	push {lr}
	adds r2, r0, 0
	cmp r1, 0
	bge _0801378E
	movs r0, 0
	strh r0, [r2, 0x18]
	b _080137A0
_0801378E:
	movs r3, 0x1A
	ldrsh r0, [r2, r3]
	cmp r1, r0
	blt _0801379E
	ldrh r0, [r2, 0x1A]
	subs r0, 0x1
	strh r0, [r2, 0x18]
	b _080137A0
_0801379E:
	strh r1, [r2, 0x18]
_080137A0:
	movs r0, 0
	strh r0, [r2, 0x24]
	pop {r0}
	bx r0
	thumb_func_end sub_8013780

	thumb_func_start sub_80137A8
sub_80137A8:
	movs r1, 0x18
	ldrsh r0, [r0, r1]
	bx lr
	thumb_func_end sub_80137A8

	thumb_func_start sub_80137B0
sub_80137B0:
	push {r4,lr}
	adds r4, r0, 0
	cmp r1, 0
	ble _080137BC
	lsls r0, r1, 8
	b _080137E2
_080137BC:
	ldr r3, _080137F4
	ldr r1, [r4]
	lsls r0, r1, 3
	adds r0, r1
	lsls r1, r0, 3
	adds r0, r3, 0
	adds r0, 0xC
	adds r0, r1, r0
	ldr r0, [r0]
	movs r2, 0
	cmp r0, 0x6
	bne _080137D6
	movs r2, 0x10
_080137D6:
	adds r0, r1, r3
	movs r1, 0x6
	ldrsh r0, [r0, r1]
	lsls r0, 3
	subs r0, r2
	lsls r0, 8
_080137E2:
	movs r2, 0x1C
	ldrsh r1, [r4, r2]
	bl __divsi3
	str r0, [r4, 0x10]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080137F4: .4byte gUnknown_2027370
	thumb_func_end sub_80137B0

	thumb_func_start sub_80137F8
sub_80137F8:
	lsls r1, 8
	str r1, [r0, 0x10]
	bx lr
	thumb_func_end sub_80137F8

	thumb_func_start sub_8013800
sub_8013800:
	push {lr}
	movs r3, 0x6
	ldrsh r2, [r0, r3]
	ldr r0, [r0, 0x10]
	muls r0, r1
	cmp r0, 0
	bge _08013810
	adds r0, 0xFF
_08013810:
	asrs r0, 8
	adds r0, r2, r0
	pop {r1}
	bx r1
	thumb_func_end sub_8013800

	thumb_func_start sub_8013818
sub_8013818:
	push {r4,lr}
	adds r4, r0, 0
	str r3, [r4]
	movs r0, 0
	strh r1, [r4, 0x22]
	strh r2, [r4, 0x1C]
	strh r0, [r4, 0x14]
	strh r0, [r4, 0x24]
	strh r0, [r4, 0x18]
	strh r0, [r4, 0x1E]
	adds r0, r4, 0
	adds r0, 0x28
	bl sub_801317C
	adds r0, r4, 0
	bl sub_8013984
	adds r0, r4, 0
	movs r1, 0xC
	bl sub_80137F8
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_8013818

	thumb_func_start sub_8013848
sub_8013848:
	push {r4,lr}
	adds r4, r0, 0
	str r3, [r4]
	movs r0, 0
	strh r1, [r4, 0x22]
	strh r2, [r4, 0x1C]
	strh r0, [r4, 0x14]
	strh r0, [r4, 0x24]
	strh r0, [r4, 0x18]
	strh r0, [r4, 0x1E]
	adds r0, r4, 0
	adds r0, 0x28
	bl sub_801317C
	adds r0, r4, 0
	bl sub_8013984
	adds r0, r4, 0
	movs r1, 0x18
	bl sub_80137F8
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_8013848

	thumb_func_start sub_8013878
sub_8013878:
	push {r4-r6,lr}
	adds r5, r0, 0
	adds r6, r1, 0
	cmp r6, 0
	bge _08013886
	movs r6, 0
	b _08013890
_08013886:
	movs r1, 0x22
	ldrsh r0, [r5, r1]
	cmp r6, r0
	blt _08013890
	subs r6, r0, 0x1
_08013890:
	movs r0, 0x1C
	ldrsh r1, [r5, r0]
	adds r0, r6, 0
	bl __divsi3
	movs r4, 0
	strh r0, [r5, 0x1E]
	movs r0, 0x1C
	ldrsh r1, [r5, r0]
	adds r0, r6, 0
	bl __modsi3
	strh r0, [r5, 0x18]
	strh r4, [r5, 0x24]
	adds r0, r5, 0
	bl sub_8013984
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end sub_8013878

	thumb_func_start sub_80138B8
sub_80138B8:
	push {r4-r7,lr}
	adds r5, r0, 0
	lsls r4, r1, 24
	lsrs r4, 24
	movs r0, 0x1E
	ldrsh r7, [r5, r0]
	movs r1, 0x18
	ldrsh r6, [r5, r1]
	adds r0, r5, 0
	bl AddMenuCursorSprite
	cmp r4, 0
	beq _0801391C
	adds r0, r5, 0
	bl GetKeyPress
	cmp r0, 0x8
	beq _080138F8
	cmp r0, 0x8
	bgt _080138E6
	cmp r0, 0x7
	beq _080138F0
	b _0801391C
_080138E6:
	cmp r0, 0x9
	beq _0801390E
	cmp r0, 0xA
	beq _08013916
	b _0801391C
_080138F0:
	adds r0, r5, 0
	bl MoveMenuCursorUp
	b _080138FE
_080138F8:
	adds r0, r5, 0
	bl MoveMenuCursorDown
_080138FE:
	movs r1, 0x18
	ldrsh r0, [r5, r1]
	cmp r6, r0
	beq _0801391C
	movs r0, 0x3
	bl sub_80119D4
	b _0801391C
_0801390E:
	adds r0, r5, 0
	bl sub_8013A7C
	b _0801391C
_08013916:
	adds r0, r5, 0
	bl sub_8013A54
_0801391C:
	movs r1, 0x1E
	ldrsh r0, [r5, r1]
	cmp r7, r0
	bne _08013928
	movs r0, 0
	b _08013930
_08013928:
	movs r0, 0x4
	bl sub_80119D4
	movs r0, 0x1
_08013930:
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_80138B8

	thumb_func_start sub_8013938
sub_8013938:
	push {r4,r5,lr}
	adds r4, r0, 0
	movs r0, 0x1E
	ldrsh r5, [r4, r0]
	movs r0, 0
	strh r0, [r4, 0x1A]
	strh r0, [r4, 0x14]
	adds r0, r4, 0
	bl AddMenuCursorSprite
	adds r0, r4, 0
	bl GetKeyPress
	cmp r0, 0x9
	beq _0801395C
	cmp r0, 0xA
	beq _08013964
	b _0801396A
_0801395C:
	adds r0, r4, 0
	bl sub_8013A7C
	b _0801396A
_08013964:
	adds r0, r4, 0
	bl sub_8013A54
_0801396A:
	movs r1, 0x1E
	ldrsh r0, [r4, r1]
	cmp r5, r0
	bne _08013976
	movs r0, 0
	b _0801397E
_08013976:
	movs r0, 0x4
	bl sub_80119D4
	movs r0, 0x1
_0801397E:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_8013938

	thumb_func_start sub_8013984
sub_8013984:
	push {r4-r6,lr}
	adds r4, r0, 0
	ldr r1, [r4]
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 3
	ldr r1, _08013A20
	adds r6, r0, r1
	ldrh r1, [r4, 0x1C]
	movs r2, 0x1C
	ldrsh r0, [r4, r2]
	cmp r0, 0
	bne _080139A2
	adds r0, r1, 0x1
	strh r0, [r4, 0x1C]
_080139A2:
	movs r1, 0x22
	ldrsh r0, [r4, r1]
	movs r2, 0x1C
	ldrsh r1, [r4, r2]
	bl __divsi3
	adds r5, r0, 0
	strh r5, [r4, 0x20]
	movs r1, 0x22
	ldrsh r0, [r4, r1]
	movs r2, 0x1C
	ldrsh r1, [r4, r2]
	bl __modsi3
	cmp r0, 0
	beq _080139C6
	adds r0, r5, 0x1
	strh r0, [r4, 0x20]
_080139C6:
	movs r0, 0x1E
	ldrsh r1, [r4, r0]
	movs r2, 0x20
	ldrsh r0, [r4, r2]
	subs r0, 0x1
	ldrh r5, [r4, 0x20]
	cmp r1, r0
	ble _080139DA
	subs r0, r5, 0x1
	strh r0, [r4, 0x1E]
_080139DA:
	movs r0, 0x1E
	ldrsh r1, [r4, r0]
	movs r2, 0x20
	ldrsh r0, [r4, r2]
	subs r0, 0x1
	cmp r1, r0
	bne _080139F8
	movs r1, 0x22
	ldrsh r0, [r4, r1]
	movs r2, 0x1C
	ldrsh r1, [r4, r2]
	bl __modsi3
	cmp r0, 0
	bne _080139FA
_080139F8:
	ldrh r0, [r4, 0x1C]
_080139FA:
	strh r0, [r4, 0x1A]
	movs r0, 0x18
	ldrsh r1, [r4, r0]
	movs r2, 0x1A
	ldrsh r0, [r4, r2]
	subs r0, 0x1
	cmp r1, r0
	ble _08013A10
	ldrh r0, [r4, 0x1A]
	subs r0, 0x1
	strh r0, [r4, 0x18]
_08013A10:
	movs r1, 0
	strh r1, [r4, 0x4]
	ldr r0, [r6, 0xC]
	cmp r0, 0x6
	bne _08013A24
	movs r0, 0x10
	strh r0, [r4, 0x6]
	b _08013A26
	.align 2, 0
_08013A20: .4byte gUnknown_2027370
_08013A24:
	strh r1, [r4, 0x6]
_08013A26:
	lsls r0, r5, 16
	asrs r0, 16
	cmp r0, 0x1
	bgt _08013A32
	movs r0, 0
	b _08013A40
_08013A32:
	movs r1, 0
	ldrsh r0, [r6, r1]
	movs r2, 0x4
	ldrsh r1, [r6, r2]
	adds r0, r1
	subs r0, 0x2
	lsls r0, 3
_08013A40:
	strh r0, [r4, 0xC]
	movs r1, 0x2
	ldrsh r0, [r6, r1]
	adds r0, 0x1
	lsls r0, 3
	subs r0, 0x2
	strh r0, [r4, 0xE]
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end sub_8013984

	thumb_func_start sub_8013A54
sub_8013A54:
	push {lr}
	adds r2, r0, 0
	movs r0, 0x1E
	ldrsh r1, [r2, r0]
	movs r3, 0x20
	ldrsh r0, [r2, r3]
	subs r0, 0x1
	cmp r1, r0
	bge _08013A6C
	ldrh r0, [r2, 0x1E]
	adds r0, 0x1
	b _08013A6E
_08013A6C:
	movs r0, 0
_08013A6E:
	strh r0, [r2, 0x1E]
	adds r0, r2, 0
	bl sub_8013984
	pop {r0}
	bx r0
	thumb_func_end sub_8013A54

	thumb_func_start sub_8013A7C
sub_8013A7C:
	push {lr}
	adds r1, r0, 0
	ldrh r2, [r1, 0x1E]
	movs r3, 0x1E
	ldrsh r0, [r1, r3]
	cmp r0, 0
	bgt _08013A90
	ldrh r0, [r1, 0x20]
	subs r0, 0x1
	b _08013A92
_08013A90:
	subs r0, r2, 0x1
_08013A92:
	strh r0, [r1, 0x1E]
	adds r0, r1, 0
	bl sub_8013984
	pop {r0}
	bx r0
	thumb_func_end sub_8013A7C

	thumb_func_start sub_8013AA0
sub_8013AA0:
	push {r4,r5,lr}
	sub sp, 0x28
	adds r5, r0, 0
	ldrh r1, [r5, 0x28]
	ldr r0, _08013B9C
	ands r0, r1
	ldr r1, _08013BA0
	ands r0, r1
	ldr r4, _08013BA4
	ands r0, r4
	ldr r1, _08013BA8
	ands r0, r1
	ldr r1, _08013BAC
	ands r0, r1
	movs r1, 0x80
	lsls r1, 7
	ldr r3, _08013BB0
	ands r0, r3
	orrs r0, r1
	strh r0, [r5, 0x28]
	movs r1, 0x80
	lsls r1, 6
	ldrh r0, [r5, 0x2A]
	ldr r2, _08013BB4
	ands r2, r0
	orrs r2, r1
	ands r2, r3
	movs r3, 0xFC
	lsls r3, 2
	ldrh r1, [r5, 0x2C]
	movs r0, 0xFC
	lsls r0, 8
	ands r0, r1
	orrs r0, r3
	ands r0, r4
	movs r3, 0xF
	movs r4, 0xF0
	lsls r4, 8
	ldr r1, _08013BB8
	ands r0, r1
	orrs r0, r4
	strh r0, [r5, 0x2C]
	movs r0, 0xFE
	lsls r0, 8
	ands r2, r0
	movs r0, 0xF0
	orrs r2, r0
	strh r2, [r5, 0x2A]
	subs r1, 0xFF
	ldrh r0, [r5, 0x2E]
	ands r3, r0
	movs r0, 0
	orrs r3, r1
	strh r3, [r5, 0x2E]
	adds r1, r5, 0
	adds r1, 0x26
	strb r0, [r1]
	ldr r1, [r5, 0xC]
	ldr r2, [r5, 0x10]
	mov r0, sp
	bl ConvertToDecimal
	ldr r0, [r5, 0x10]
	adds r1, r5, 0
	adds r1, 0x25
	strb r0, [r1]
	ldrb r2, [r1]
	subs r0, r2, 0x1
	lsls r0, 2
	add r0, sp
	ldr r0, [r0]
	cmp r0, 0
	bne _08013B50
	cmp r2, 0x1
	bls _08013B50
	adds r2, r1, 0
_08013B38:
	ldrb r0, [r2]
	subs r0, 0x1
	strb r0, [r2]
	ldrb r1, [r2]
	subs r0, r1, 0x1
	lsls r0, 2
	add r0, sp
	ldr r0, [r0]
	cmp r0, 0
	bne _08013B50
	cmp r1, 0x1
	bhi _08013B38
_08013B50:
	ldr r1, [r5, 0x4]
	str r1, [r5]
	ldr r2, [r5, 0x10]
	mov r0, sp
	bl ConvertToDecimal
	adds r0, r5, 0
	adds r0, 0x25
	ldrb r0, [r0]
	subs r0, 0x1
	adds r1, r5, 0
	adds r1, 0x24
	strb r0, [r1]
	ldrb r2, [r1]
	lsls r0, r2, 2
	add r0, sp
	ldr r0, [r0]
	cmp r0, 0
	bne _08013B92
	cmp r2, 0
	beq _08013B92
	adds r2, r1, 0
_08013B7C:
	ldrb r0, [r2]
	subs r0, 0x1
	strb r0, [r2]
	ldrb r1, [r2]
	lsls r0, r1, 2
	add r0, sp
	ldr r0, [r0]
	cmp r0, 0
	bne _08013B92
	cmp r1, 0
	bne _08013B7C
_08013B92:
	add sp, 0x28
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_08013B9C: .4byte 0x0000feff
_08013BA0: .4byte 0x0000fdff
_08013BA4: .4byte 0x0000f3ff
_08013BA8: .4byte 0x0000efff
_08013BAC: .4byte 0x0000dfff
_08013BB0: .4byte 0x00003fff
_08013BB4: .4byte 0x0000c1ff
_08013BB8: .4byte 0x00000fff
	thumb_func_end sub_8013AA0

	thumb_func_start sub_8013BBC
sub_8013BBC:
	push {r4-r7,lr}
	adds r7, r0, 0
	adds r4, r7, 0
	adds r4, 0x26
	ldrb r0, [r4]
	adds r0, 0x1
	strb r0, [r4]
	adds r0, r7, 0
	bl sub_8013D10
	ldrb r1, [r4]
	movs r0, 0x8
	ands r0, r1
	cmp r0, 0
	beq _08013C26
	movs r2, 0x80
	lsls r2, 6
	ldrh r1, [r7, 0x2A]
	ldr r4, _08013C38
	adds r0, r4, 0
	ands r0, r1
	orrs r0, r2
	strh r0, [r7, 0x2A]
	adds r5, r7, 0
	adds r5, 0x28
	movs r6, 0x80
	lsls r6, 1
	adds r0, r5, 0
	adds r1, r6, 0
	movs r2, 0
	movs r3, 0
	bl AddSprite
	ldrh r0, [r7, 0x2A]
	ands r4, r0
	strh r4, [r7, 0x2A]
	ldrh r1, [r7, 0x2E]
	ldr r0, _08013C3C
	lsrs r1, 4
	adds r1, 0x10
	ands r1, r0
	lsls r1, 4
	ldrh r2, [r7, 0x2E]
	movs r0, 0xF
	ands r0, r2
	orrs r0, r1
	strh r0, [r7, 0x2E]
	adds r0, r5, 0
	adds r1, r6, 0
	movs r2, 0
	movs r3, 0
	bl AddSprite
_08013C26:
	adds r0, r7, 0
	bl sub_8013DD0
	lsls r0, 24
	cmp r0, 0
	beq _08013C40
	movs r0, 0x1
	b _08013C62
	.align 2, 0
_08013C38: .4byte 0x0000c1ff
_08013C3C: .4byte 0x00000fff
_08013C40:
	bl sub_8012AE8
	cmp r0, 0x1
	beq _08013C56
	cmp r0, 0x2
	bne _08013C60
	movs r0, 0x1
	bl sub_80119D4
	movs r0, 0x2
	b _08013C62
_08013C56:
	movs r0, 0
	bl sub_80119D4
	movs r0, 0x3
	b _08013C62
_08013C60:
	movs r0, 0
_08013C62:
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_8013BBC

	thumb_func_start sub_8013C68
sub_8013C68:
	push {r4-r6,lr}
	sub sp, 0x2C
	adds r5, r0, 0
	ldr r1, [r5]
	ldr r2, [r5, 0x10]
	add r0, sp, 0x4
	bl ConvertToDecimal
	ldr r0, [r5, 0x10]
	subs r4, r0, 0x1
	cmp r4, 0
	ble _08013CA0
	lsls r0, r4, 2
	mov r1, sp
	adds r1, r0
	adds r1, 0x4
	ldr r0, [r1]
	cmp r0, 0
	bne _08013CA0
	movs r2, 0xFF
_08013C90:
	str r2, [r1]
	subs r1, 0x4
	subs r4, 0x1
	cmp r4, 0
	ble _08013CA0
	ldr r0, [r1]
	cmp r0, 0
	beq _08013C90
_08013CA0:
	movs r4, 0
	adds r0, r5, 0
	adds r0, 0x25
	adds r6, r0, 0
	b _08013CDA
_08013CAA:
	lsls r0, r4, 2
	add r0, sp
	adds r0, 0x4
	ldr r0, [r0]
	cmp r0, 0xFF
	bne _08013CBA
	movs r3, 0x2A
	b _08013CC0
_08013CBA:
	adds r0, 0x30
	lsls r0, 24
	lsrs r3, r0, 24
_08013CC0:
	adds r4, 0x1
	lsls r1, r4, 1
	adds r1, r4
	lsls r1, 2
	ldr r0, [r5, 0x1C]
	subs r0, r1
	ldr r1, [r5, 0x20]
	ldr r2, [r5, 0x14]
	str r2, [sp]
	adds r2, r3, 0
	movs r3, 0x7
	bl sub_8012C60
_08013CDA:
	ldrb r0, [r6]
	cmp r4, r0
	blt _08013CAA
	movs r4, 0
	b _08013D02
_08013CE4:
	ldr r0, [r5, 0x14]
	adds r4, 0x1
	lsls r2, r4, 1
	adds r2, r4
	lsls r2, 2
	ldr r1, [r5, 0x1C]
	subs r1, r2
	subs r1, 0x1
	ldr r2, [r5, 0x20]
	adds r2, 0xA
	movs r3, 0x5
	str r3, [sp]
	movs r3, 0xB
	bl sub_800792C
_08013D02:
	ldr r0, [r5, 0x10]
	cmp r4, r0
	blt _08013CE4
	add sp, 0x2C
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end sub_8013C68

	thumb_func_start sub_8013D10
sub_8013D10:
	push {r4-r7,lr}
	adds r6, r0, 0
	ldr r0, [r6, 0x14]
	lsls r1, r0, 3
	adds r1, r0
	lsls r1, 3
	ldr r0, _08013D34
	adds r7, r1, r0
	adds r4, r6, 0
	adds r4, 0x24
	ldrb r5, [r4]
	bl sub_8012AE8
	cmp r0, 0x9
	beq _08013D38
	cmp r0, 0xA
	beq _08013D4E
	b _08013D62
	.align 2, 0
_08013D34: .4byte gUnknown_2027370
_08013D38:
	ldrb r1, [r4]
	adds r0, r6, 0
	adds r0, 0x25
	ldrb r0, [r0]
	subs r0, 0x1
	cmp r1, r0
	bge _08013D4A
	adds r0, r1, 0x1
	b _08013D5C
_08013D4A:
	movs r0, 0
	b _08013D60
_08013D4E:
	ldrb r0, [r4]
	cmp r0, 0
	bne _08013D5A
	adds r0, r6, 0
	adds r0, 0x25
	ldrb r0, [r0]
_08013D5A:
	subs r0, 0x1
_08013D5C:
	lsls r0, 24
	lsrs r0, 24
_08013D60:
	adds r5, r0, 0
_08013D62:
	adds r4, r6, 0
	adds r4, 0x24
	ldrb r0, [r4]
	cmp r5, r0
	beq _08013D7C
	strb r5, [r4]
	movs r0, 0x3
	bl sub_80119D4
	adds r1, r6, 0
	adds r1, 0x26
	movs r0, 0x8
	strb r0, [r1]
_08013D7C:
	ldrb r0, [r4]
	adds r0, 0x1
	lsls r1, r0, 1
	adds r1, r0
	lsls r1, 2
	ldr r2, [r6, 0x1C]
	subs r2, r1
	movs r1, 0
	ldrsh r0, [r7, r1]
	lsls r0, 3
	adds r2, r0
	subs r2, 0x3
	ldr r0, _08013DC8
	ands r2, r0
	ldrh r1, [r6, 0x2A]
	movs r0, 0xFE
	lsls r0, 8
	ands r0, r1
	orrs r0, r2
	strh r0, [r6, 0x2A]
	movs r1, 0x2
	ldrsh r0, [r7, r1]
	lsls r0, 3
	ldr r1, [r6, 0x20]
	adds r1, r0
	subs r1, 0x7
	ldr r0, _08013DCC
	ands r1, r0
	lsls r1, 4
	ldrh r2, [r6, 0x2E]
	movs r0, 0xF
	ands r0, r2
	orrs r0, r1
	strh r0, [r6, 0x2E]
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_08013DC8: .4byte 0x000001ff
_08013DCC: .4byte 0x00000fff
	thumb_func_end sub_8013D10

	thumb_func_start sub_8013DD0
sub_8013DD0:
	push {r4,r5,lr}
	adds r4, r0, 0
	bl sub_8012AE8
	cmp r0, 0x7
	beq _08013DE4
	cmp r0, 0x8
	beq _08013E10
	movs r0, 0
	b _08013E4C
_08013DE4:
	ldr r2, [r4]
	ldr r0, [r4, 0xC]
	cmp r2, r0
	beq _08013E18
	ldr r1, _08013E0C
	adds r0, r4, 0
	adds r0, 0x24
	ldrb r0, [r0]
	lsls r0, 2
	adds r0, r1
	ldr r0, [r0]
	adds r5, r2, r0
	movs r0, 0x3
	bl sub_80119D4
	ldr r0, [r4, 0xC]
	cmp r5, r0
	bgt _08013E3E
	b _08013E48
	.align 2, 0
_08013E0C: .4byte gUnknown_80D4830
_08013E10:
	ldr r2, [r4]
	ldr r0, [r4, 0x8]
	cmp r2, r0
	bne _08013E22
_08013E18:
	movs r0, 0x2
	bl sub_80119D4
	movs r0, 0
	b _08013E4C
_08013E22:
	ldr r1, _08013E44
	adds r0, r4, 0
	adds r0, 0x24
	ldrb r0, [r0]
	lsls r0, 2
	adds r0, r1
	ldr r0, [r0]
	subs r5, r2, r0
	movs r0, 0x3
	bl sub_80119D4
	ldr r0, [r4, 0x8]
	cmp r5, r0
	bge _08013E48
_08013E3E:
	str r0, [r4]
	b _08013E4A
	.align 2, 0
_08013E44: .4byte gUnknown_80D4830
_08013E48:
	str r5, [r4]
_08013E4A:
	movs r0, 0x1
_08013E4C:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_8013DD0

	thumb_func_start sub_8013E54
sub_8013E54:
	push {r4-r6,lr}
	sub sp, 0x8
	ldr r6, _08013F60
	movs r0, 0
	movs r1, 0
	str r0, [sp]
	str r1, [sp, 0x4]
	mov r0, sp
	ldrh r0, [r0]
	ldr r1, _08013F64
	ands r1, r0
	ldr r3, _08013F68
	ldr r0, [sp]
	ands r0, r3
	orrs r0, r1
	str r0, [sp]
	mov r1, sp
	ldrh r1, [r1]
	adds r2, r3, 0
	ands r2, r0
	orrs r2, r1
	str r2, [sp]
	mov r0, sp
	ldrh r1, [r0]
	ldr r0, _08013F6C
	ands r0, r1
	adds r1, r3, 0
	ands r1, r2
	orrs r1, r0
	str r1, [sp]
	mov r0, sp
	ldrh r0, [r0]
	adds r2, r3, 0
	ands r2, r1
	orrs r2, r0
	str r2, [sp]
	mov r0, sp
	ldrh r1, [r0]
	ldr r5, _08013F70
	adds r0, r5, 0
	ands r0, r1
	adds r1, r3, 0
	ands r1, r2
	orrs r1, r0
	str r1, [sp]
	mov r0, sp
	ldrh r0, [r0]
	adds r2, r3, 0
	ands r2, r1
	orrs r2, r0
	str r2, [sp]
	mov r0, sp
	ldrh r1, [r0]
	ldr r0, _08013F74
	ands r0, r1
	adds r1, r3, 0
	ands r1, r2
	orrs r1, r0
	str r1, [sp]
	mov r0, sp
	ldrh r0, [r0]
	adds r2, r3, 0
	ands r2, r1
	orrs r2, r0
	str r2, [sp]
	mov r0, sp
	ldrh r1, [r0]
	ldr r0, _08013F78
	ands r0, r1
	adds r1, r3, 0
	ands r1, r2
	orrs r1, r0
	str r1, [sp]
	mov r0, sp
	ldrh r0, [r0]
	adds r2, r3, 0
	ands r2, r1
	orrs r2, r0
	str r2, [sp]
	movs r4, 0x80
	lsls r4, 7
	mov r0, sp
	ldrh r1, [r0]
	ldr r0, _08013F7C
	ands r0, r1
	adds r1, r3, 0
	ands r1, r2
	orrs r1, r0
	str r1, [sp]
	mov r0, sp
	ldrh r0, [r0]
	orrs r4, r0
	ands r3, r1
	orrs r3, r4
	str r3, [sp]
	mov r3, sp
	movs r2, 0xFC
	lsls r2, 2
	ldrh r1, [r3, 0x4]
	movs r0, 0xFC
	lsls r0, 8
	ands r0, r1
	orrs r0, r2
	ands r0, r5
	movs r2, 0xF
	movs r1, 0xF0
	lsls r1, 8
	ldr r4, _08013F80
	ands r0, r4
	orrs r0, r1
	strh r0, [r3, 0x4]
	movs r1, 0x2
	ldrsh r0, [r6, r1]
	lsls r0, 3
	adds r0, 0x80
	ands r0, r4
	lsls r0, 4
	ldrh r1, [r3, 0x6]
	ands r2, r1
	orrs r2, r0
	strh r2, [r3, 0x6]
	movs r0, 0x70
	strh r0, [r3, 0x2]
	movs r1, 0x80
	lsls r1, 1
	mov r0, sp
	movs r2, 0
	movs r3, 0
	bl AddSprite
	add sp, 0x8
	pop {r4-r6}
	pop {r0}
	bx r0
	.align 2, 0
_08013F60: .4byte gUnknown_2027370
_08013F64: .4byte 0x0000feff
_08013F68: .4byte 0xffff0000
_08013F6C: .4byte 0x0000fdff
_08013F70: .4byte 0x0000f3ff
_08013F74: .4byte 0x0000efff
_08013F78: .4byte 0x0000dfff
_08013F7C: .4byte 0x00003fff
_08013F80: .4byte 0x00000fff
	thumb_func_end sub_8013E54

	thumb_func_start sub_8013F84
sub_8013F84:
	push {r4-r6,lr}
	sub sp, 0x8
	ldr r6, _08014090
	movs r0, 0
	movs r1, 0
	str r0, [sp]
	str r1, [sp, 0x4]
	mov r0, sp
	ldrh r0, [r0]
	ldr r1, _08014094
	ands r1, r0
	ldr r3, _08014098
	ldr r0, [sp]
	ands r0, r3
	orrs r0, r1
	str r0, [sp]
	mov r1, sp
	ldrh r1, [r1]
	adds r2, r3, 0
	ands r2, r0
	orrs r2, r1
	str r2, [sp]
	mov r0, sp
	ldrh r1, [r0]
	ldr r0, _0801409C
	ands r0, r1
	adds r1, r3, 0
	ands r1, r2
	orrs r1, r0
	str r1, [sp]
	mov r0, sp
	ldrh r0, [r0]
	adds r2, r3, 0
	ands r2, r1
	orrs r2, r0
	str r2, [sp]
	mov r0, sp
	ldrh r1, [r0]
	ldr r5, _080140A0
	adds r0, r5, 0
	ands r0, r1
	adds r1, r3, 0
	ands r1, r2
	orrs r1, r0
	str r1, [sp]
	mov r0, sp
	ldrh r0, [r0]
	adds r2, r3, 0
	ands r2, r1
	orrs r2, r0
	str r2, [sp]
	mov r0, sp
	ldrh r1, [r0]
	ldr r0, _080140A4
	ands r0, r1
	adds r1, r3, 0
	ands r1, r2
	orrs r1, r0
	str r1, [sp]
	mov r0, sp
	ldrh r0, [r0]
	adds r2, r3, 0
	ands r2, r1
	orrs r2, r0
	str r2, [sp]
	mov r0, sp
	ldrh r1, [r0]
	ldr r0, _080140A8
	ands r0, r1
	adds r1, r3, 0
	ands r1, r2
	orrs r1, r0
	str r1, [sp]
	mov r0, sp
	ldrh r0, [r0]
	adds r2, r3, 0
	ands r2, r1
	orrs r2, r0
	str r2, [sp]
	movs r4, 0x80
	lsls r4, 7
	mov r0, sp
	ldrh r1, [r0]
	ldr r0, _080140AC
	ands r0, r1
	adds r1, r3, 0
	ands r1, r2
	orrs r1, r0
	str r1, [sp]
	mov r0, sp
	ldrh r0, [r0]
	orrs r4, r0
	ands r3, r1
	orrs r3, r4
	str r3, [sp]
	mov r3, sp
	movs r2, 0xFC
	lsls r2, 2
	ldrh r1, [r3, 0x4]
	movs r0, 0xFC
	lsls r0, 8
	ands r0, r1
	orrs r0, r2
	ands r0, r5
	movs r2, 0xF
	movs r1, 0xF0
	lsls r1, 8
	ldr r4, _080140B0
	ands r0, r4
	orrs r0, r1
	strh r0, [r3, 0x4]
	movs r1, 0x2
	ldrsh r0, [r6, r1]
	lsls r0, 3
	adds r0, 0x60
	ands r0, r4
	lsls r0, 4
	ldrh r1, [r3, 0x6]
	ands r2, r1
	orrs r2, r0
	strh r2, [r3, 0x6]
	movs r0, 0x70
	strh r0, [r3, 0x2]
	movs r1, 0x80
	lsls r1, 1
	mov r0, sp
	movs r2, 0
	movs r3, 0
	bl AddSprite
	add sp, 0x8
	pop {r4-r6}
	pop {r0}
	bx r0
	.align 2, 0
_08014090: .4byte gUnknown_2027370
_08014094: .4byte 0x0000feff
_08014098: .4byte 0xffff0000
_0801409C: .4byte 0x0000fdff
_080140A0: .4byte 0x0000f3ff
_080140A4: .4byte 0x0000efff
_080140A8: .4byte 0x0000dfff
_080140AC: .4byte 0x00003fff
_080140B0: .4byte 0x00000fff
	thumb_func_end sub_8013F84

	thumb_func_start sub_80140B4
sub_80140B4:
	push {r4-r7,lr}
	ldr r4, _080140D8
	adds r2, r0, 0
	movs r3, 0x3
_080140BC:
	adds r1, r2, 0
	adds r0, r4, 0
	ldm r0!, {r5-r7}
	stm r1!, {r5-r7}
	ldm r0!, {r5-r7}
	stm r1!, {r5-r7}
	adds r4, 0x18
	adds r2, 0x18
	subs r3, 0x1
	cmp r3, 0
	bge _080140BC
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_080140D8: .4byte gUnknown_80D47C8
	thumb_func_end sub_80140B4

	thumb_func_start sub_80140DC
sub_80140DC:
	push {lr}
	sub sp, 0x4
	ldr r0, _080140F4
	str r0, [sp]
	mov r0, sp
	bl SetSavingIconCoords
	bl sub_8011830
	add sp, 0x4
	pop {r0}
	bx r0
	.align 2, 0
_080140F4: .4byte 0x008000c8
	thumb_func_end sub_80140DC

	thumb_func_start sub_80140F8
sub_80140F8:
	push {lr}
	sub sp, 0x4
	ldr r0, _08014110
	str r0, [sp]
	mov r0, sp
	bl SetSavingIconCoords
	bl sub_8011830
	add sp, 0x4
	pop {r0}
	bx r0
	.align 2, 0
_08014110: .4byte 0x004000bc
	thumb_func_end sub_80140F8

	thumb_func_start sub_8014114
sub_8014114:
	push {lr}
	bl sub_8011854
	movs r0, 0
	bl SetSavingIconCoords
	pop {r0}
	bx r0
	thumb_func_end sub_8014114

	thumb_func_start nullsub_201
nullsub_201:
	bx lr
	thumb_func_end nullsub_201

	thumb_func_start sub_8014128
sub_8014128:
	push {lr}
	bl sub_8012AE8
	cmp r0, 0x2
	beq _08014136
	movs r0, 0x1
	b _08014138
_08014136:
	movs r0, 0
_08014138:
	pop {r1}
	bx r1
	thumb_func_end sub_8014128

	thumb_func_start sub_801413C
sub_801413C:
	movs r0, 0
	bx lr
	thumb_func_end sub_801413C

	thumb_func_start sub_8014140
sub_8014140:
	movs r0, 0
	bx lr
	thumb_func_end sub_8014140

	thumb_func_start sub_8014144
sub_8014144:
	ldr r0, _0801415C
	movs r2, 0
	str r2, [r0]
	ldr r0, _08014160
	movs r1, 0x3C
	str r1, [r0]
	ldr r0, _08014164
	str r1, [r0]
	ldr r0, _08014168
	str r2, [r0]
	bx lr
	.align 2, 0
_0801415C: .4byte gUnknown_202E744
_08014160: .4byte gUnknown_202E738
_08014164: .4byte gUnknown_202E73C
_08014168: .4byte gUnknown_202E740
	thumb_func_end sub_8014144

	thumb_func_start sub_801416C
sub_801416C:
	push {lr}
	adds r2, r0, 0
	adds r3, r1, 0
	movs r0, 0x1
	negs r0, r0
	cmp r2, r0
	bge _0801418C
	ldr r0, _08014184
	str r3, [r0]
	ldr r1, _08014188
	negs r0, r2
	b _08014194
	.align 2, 0
_08014184: .4byte gUnknown_202E738
_08014188: .4byte gUnknown_202E740
_0801418C:
	ldr r0, _080141A8
	str r2, [r0]
	ldr r1, _080141AC
	movs r0, 0
_08014194:
	str r0, [r1]
	ldr r0, _080141B0
	adds r1, r3, 0
	cmp r1, 0
	bge _080141A0
	movs r1, 0
_080141A0:
	str r1, [r0]
	pop {r0}
	bx r0
	.align 2, 0
_080141A8: .4byte gUnknown_202E738
_080141AC: .4byte gUnknown_202E740
_080141B0: .4byte gUnknown_202E73C
	thumb_func_end sub_801416C

	thumb_func_start sub_80141B4
sub_80141B4:
	push {r4-r6,lr}
	sub sp, 0x14
	lsls r3, 16
	lsrs r3, 16
	movs r6, 0x1
	negs r6, r6
	movs r5, 0
	str r5, [sp]
	movs r4, 0x3
	str r4, [sp, 0x4]
	str r5, [sp, 0x8]
	str r2, [sp, 0xC]
	str r3, [sp, 0x10]
	adds r2, r6, 0
	movs r3, 0
	bl sub_8014248
	add sp, 0x14
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end sub_80141B4

	thumb_func_start sub_80141E0
sub_80141E0:
	push {r4-r6,lr}
	sub sp, 0x14
	lsls r6, r2, 16
	movs r2, 0x1
	negs r2, r2
	ldr r3, _08014210
	movs r5, 0
	str r5, [sp]
	movs r4, 0x3
	str r4, [sp, 0x4]
	str r5, [sp, 0x8]
	str r1, [sp, 0xC]
	movs r1, 0xC0
	lsls r1, 18
	orrs r1, r6
	lsrs r1, 16
	str r1, [sp, 0x10]
	movs r1, 0
	bl sub_8014248
	add sp, 0x14
	pop {r4-r6}
	pop {r0}
	bx r0
	.align 2, 0
_08014210: .4byte gUnknown_80D485C
	thumb_func_end sub_80141E0

	thumb_func_start sub_8014214
sub_8014214:
	push {r4-r6,lr}
	sub sp, 0x14
	lsls r6, r2, 16
	movs r2, 0x1
	negs r2, r2
	ldr r3, _08014244
	movs r5, 0
	str r5, [sp]
	movs r4, 0x3
	str r4, [sp, 0x4]
	str r5, [sp, 0x8]
	str r1, [sp, 0xC]
	movs r1, 0xC0
	lsls r1, 18
	orrs r1, r6
	lsrs r1, 16
	str r1, [sp, 0x10]
	movs r1, 0
	bl sub_8014248
	add sp, 0x14
	pop {r4-r6}
	pop {r0}
	bx r0
	.align 2, 0
_08014244: .4byte gUnknown_80D4880
	thumb_func_end sub_8014214

	thumb_func_start sub_8014248
sub_8014248:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x4
	adds r6, r1, 0
	mov r9, r2
	mov r8, r3
	ldr r5, [sp, 0x28]
	ldr r7, [sp, 0x30]
	ldr r1, [sp, 0x34]
	lsls r1, 16
	lsrs r1, 16
	mov r10, r1
	movs r1, 0
	str r1, [sp]
	ldr r4, _080142B8
	ldr r3, _080142BC
	adds r2, r4, r3
	adds r1, r4, 0
	mov r3, r10
	bl xxx_format_string
	ldr r0, _080142C0
	str r4, [r0]
	ldr r0, _080142C4
	str r6, [r0, 0x24]
	ldr r0, _080142C8
	str r5, [r0]
	ldr r0, _080142CC
	mov r4, r8
	str r4, [r0]
	ldr r0, _080142D0
	ldr r5, [sp, 0x24]
	str r5, [r0]
	ldr r0, _080142D4
	mov r6, r9
	str r6, [r0]
	ldr r0, _080142D8
	bl sub_801317C
	movs r0, 0x10
	mov r1, r10
	ands r0, r1
	cmp r0, 0
	beq _080142E4
	ldr r2, _080142DC
	adds r1, r2, 0
	ldr r0, _080142E0
	ldm r0!, {r3-r5}
	stm r1!, {r3-r5}
	ldm r0!, {r3,r4,r6}
	stm r1!, {r3,r4,r6}
	b _080142F2
	.align 2, 0
_080142B8: .4byte gUnknown_202E798
_080142BC: .4byte 0x000003e7
_080142C0: .4byte gUnknown_202E794
_080142C4: .4byte gUnknown_202E748
_080142C8: .4byte gUnknown_202EC10
_080142CC: .4byte gUnknown_202EC14
_080142D0: .4byte gUnknown_202EC18
_080142D4: .4byte gUnknown_202EC1C
_080142D8: .4byte gUnknown_202EC28
_080142DC: .4byte gUnknown_203B198
_080142E0: .4byte gUnknown_80D48DC
_080142E4:
	ldr r2, _08014358
	adds r1, r2, 0
	ldr r0, _0801435C
	ldm r0!, {r3,r5,r6}
	stm r1!, {r3,r5,r6}
	ldm r0!, {r4-r6}
	stm r1!, {r4-r6}
_080142F2:
	adds r4, r2, 0
	movs r0, 0
	strh r0, [r4, 0x24]
	strh r0, [r4, 0x26]
	strh r0, [r4, 0x28]
	movs r0, 0x40
	strb r0, [r4, 0x18]
	cmp r7, 0
	beq _08014368
	ldr r1, [r7, 0x4]
	cmp r1, 0
	beq _08014368
	ldrb r0, [r7, 0xC]
	lsls r0, 3
	adds r1, 0x4
	adds r1, r0
	ldr r0, [r1]
	cmp r0, 0
	beq _08014368
	ldrh r0, [r7, 0x8]
	strh r0, [r4, 0x20]
	ldrh r0, [r7, 0xA]
	strh r0, [r4, 0x22]
	movs r0, 0x5
	strh r0, [r4, 0x24]
	strh r0, [r4, 0x26]
	strh r0, [r4, 0x28]
	movs r4, 0
_0801432A:
	adds r0, r4, 0
	adds r0, 0xE0
	ldr r2, [r7, 0x4]
	ldrb r1, [r7, 0xC]
	lsls r1, 3
	adds r2, r1
	lsls r3, r4, 2
	ldr r1, [r2]
	adds r1, r3
	bl SetBGPaletteBufferColorArray
	adds r4, 0x1
	cmp r4, 0xF
	ble _0801432A
	movs r0, 0x1
	str r0, [sp]
	ldrb r0, [r7, 0xE]
	cmp r0, 0
	beq _08014360
	ldr r1, _08014358
	movs r0, 0x7
	b _08014364
	.align 2, 0
_08014358: .4byte gUnknown_203B198
_0801435C: .4byte gUnknown_80D48C4
_08014360:
	ldr r1, _080143E8
	movs r0, 0x5
_08014364:
	str r0, [r1, 0x1C]
	adds r4, r1, 0
_08014368:
	ldr r2, _080143EC
	adds r1, r4, 0
	adds r1, 0x30
	adds r0, r2, 0
	ldm r0!, {r3,r5,r6}
	stm r1!, {r3,r5,r6}
	ldm r0!, {r3,r5,r6}
	stm r1!, {r3,r5,r6}
	adds r0, r4, 0
	adds r0, 0x48
	ldm r2!, {r1,r3,r5}
	stm r0!, {r1,r3,r5}
	ldm r2!, {r1,r3,r6}
	stm r0!, {r1,r3,r6}
	bl sub_8004914
	adds r0, r4, 0
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	ldr r1, _080143F0
	movs r4, 0
	movs r2, 0
	movs r0, 0x4
	strh r0, [r1]
	strh r0, [r1, 0x2]
	movs r0, 0x70
	strh r0, [r1, 0x8]
	ldr r0, _080143F4
	movs r5, 0x2
	ldrsh r0, [r0, r5]
	lsls r0, 3
	adds r0, 0x22
	strh r0, [r1, 0xA]
	movs r0, 0x7
	str r0, [r1, 0x10]
	str r2, [r1, 0x1C]
	adds r1, 0x20
	strb r4, [r1]
	movs r0, 0x10
	mov r6, r10
	ands r0, r6
	movs r1, 0x3
	cmp r0, 0
	beq _080143C6
	movs r1, 0x8
_080143C6:
	adds r0, r1, 0
	bl sub_80063D8
	ldr r0, _080143F8
	movs r1, 0x1
	str r1, [r0]
	ldr r0, _080143FC
	mov r2, r10
	strh r2, [r0]
	movs r0, 0x20
	mov r3, r10
	ands r0, r3
	cmp r0, 0
	beq _08014404
	ldr r0, _08014400
	strb r1, [r0]
	b _08014408
	.align 2, 0
_080143E8: .4byte gUnknown_203B198
_080143EC: .4byte gUnknown_80D48AC
_080143F0: .4byte gUnknown_202E748
_080143F4: .4byte gUnknown_2027370
_080143F8: .4byte gUnknown_202E744
_080143FC: .4byte gUnknown_202E77C
_08014400: .4byte gUnknown_202E790
_08014404:
	ldr r0, _0801445C
	strb r4, [r0]
_08014408:
	movs r0, 0x80
	lsls r0, 3
	mov r4, r10
	ands r0, r4
	cmp r0, 0
	beq _08014418
	bl sub_8094C14
_08014418:
	ldr r0, _08014460
	movs r1, 0x1
	str r1, [r0]
	ldr r0, _08014464
	str r1, [r0]
	bl sub_80048F8
	ldr r1, _08014468
	movs r0, 0
	strb r0, [r1]
	ldr r1, _0801446C
	movs r0, 0
	str r0, [r1]
	ldr r5, [sp]
	cmp r5, 0
	beq _08014480
	ldr r0, [r7, 0x4]
	ldrb r1, [r7, 0xC]
	lsls r1, 3
	adds r0, 0x4
	adds r0, r1
	ldr r4, [r0]
	movs r0, 0x1
	bl sub_80073B8
	ldrb r0, [r7, 0xD]
	cmp r0, 0
	bne _08014470
	movs r0, 0x1
	adds r1, r4, 0
	movs r2, 0xE
	bl sub_8008274
	b _0801447A
	.align 2, 0
_0801445C: .4byte gUnknown_202E790
_08014460: .4byte gUnknown_202E788
_08014464: .4byte gUnknown_202E78C
_08014468: .4byte gUnknown_202E791
_0801446C: .4byte gUnknown_202E784
_08014470:
	movs r0, 0x1
	adds r1, r4, 0
	movs r2, 0xE
	bl sub_800836C
_0801447A:
	movs r0, 0x1
	bl sub_80073E0
_08014480:
	add sp, 0x4
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_8014248

	thumb_func_start sub_8014490
sub_8014490:
	ldr r0, _0801449C
	movs r1, 0
	str r1, [r0]
	ldr r0, _080144A0
	str r1, [r0]
	bx lr
	.align 2, 0
_0801449C: .4byte gUnknown_202E744
_080144A0: .4byte gUnknown_202EC1C
	thumb_func_end sub_8014490

	thumb_func_start sub_80144A4
sub_80144A4:
	push {lr}
	adds r1, r0, 0
	cmp r1, 0
	beq _080144B2
	ldr r0, _080144BC
	ldr r0, [r0]
	str r0, [r1]
_080144B2:
	ldr r0, _080144C0
	ldr r0, [r0]
	pop {r1}
	bx r1
	.align 2, 0
_080144BC: .4byte gUnknown_202EC1C
_080144C0: .4byte gUnknown_202E744
	thumb_func_end sub_80144A4

	thumb_func_start xxx_draw_string_80144C4
xxx_draw_string_80144C4:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x8
	movs r0, 0x1
	mov r10, r0
	ldr r1, _080144F4
	ldr r0, [r1]
	adds r0, 0x1
	str r0, [r1]
_080144DC:
	ldr r0, _080144F8
	ldr r1, [r0]
	adds r3, r0, 0
	cmp r1, 0xB
	bls _080144E8
	b _08014A6A
_080144E8:
	lsls r0, r1, 2
	ldr r1, _080144FC
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080144F4: .4byte gUnknown_202E784
_080144F8: .4byte gUnknown_202E744
_080144FC: .4byte _08014500
	.align 2, 0
_08014500:
	.4byte _08014A72
	.4byte _08014530
	.4byte _08014708
	.4byte _08014A38
	.4byte _08014A48
	.4byte _08014A60
	.4byte _08014778
	.4byte _080147E2
	.4byte _080147E2
	.4byte _080147E2
	.4byte _080149D8
	.4byte _08014A04
_08014530:
	ldr r0, _08014540
	ldr r6, [r0]
	ldr r0, _08014544
	ldrb r0, [r0]
	cmp r0, 0
	beq _0801457C
	ldr r7, _08014548
	b _08014580
	.align 2, 0
_08014540: .4byte gUnknown_202E794
_08014544: .4byte gUnknown_202E790
_08014548: .4byte 0x0001869f
_0801454C:
	str r2, [r3, 0x1C]
	adds r1, r3, 0
	adds r1, 0x20
	movs r0, 0x1
	strb r0, [r1]
	ldr r1, _0801456C
	movs r0, 0x8
	str r0, [r1]
	ldr r0, _08014570
	strb r2, [r0]
	ldr r1, _08014574
	ldr r0, _08014578
	ldr r0, [r0]
	str r0, [r1]
	b _0801466C
	.align 2, 0
_0801456C: .4byte gUnknown_202E744
_08014570: .4byte gUnknown_202E791
_08014574: .4byte gUnknown_202E780
_08014578: .4byte gUnknown_202E738
_0801457C:
	ldr r0, _08014594
	ldr r7, [r0]
_08014580:
	ldr r1, _08014598
	movs r0, 0
	str r0, [r1, 0x2C]
	bl sub_80073B8
	ldr r1, _0801459C
	mov r8, r1
	ldr r2, _080145A0
	mov r9, r2
	b _08014652
	.align 2, 0
_08014594: .4byte gUnknown_202E788
_08014598: .4byte gUnknown_202E748
_0801459C: .4byte gUnknown_202E744
_080145A0: .4byte gUnknown_202E780
_080145A4:
	adds r0, r4, 0
	adds r0, 0x20
	ldrb r5, [r0]
	cmp r5, 0
	beq _080145EC
	movs r3, 0x2
	ldrsh r0, [r4, r3]
	cmp r0, 0x22
	ble _080145CC
	movs r0, 0x8
	mov r4, r8
	str r0, [r4]
	ldr r0, _080145C8
	ldr r0, [r0]
	mov r1, r9
	str r0, [r1]
	b _080145DA
	.align 2, 0
_080145C8: .4byte gUnknown_202E738
_080145CC:
	movs r0, 0x7
	mov r2, r8
	str r0, [r2]
	ldr r0, _080145E4
	ldr r0, [r0]
	mov r3, r9
	str r0, [r3]
_080145DA:
	ldr r1, _080145E8
	movs r0, 0
	strb r0, [r1]
	b _0801466C
	.align 2, 0
_080145E4: .4byte gUnknown_202E73C
_080145E8: .4byte gUnknown_202E791
_080145EC:
	ldrb r0, [r6]
	cmp r0, 0
	beq _0801466C
	cmp r0, 0xD
	beq _080145FA
	cmp r0, 0xA
	bne _08014608
_080145FA:
	movs r0, 0x4
	strh r0, [r4]
	ldrh r0, [r4, 0x2]
	adds r0, 0xB
	strh r0, [r4, 0x2]
	adds r6, 0x1
	b _08014630
_08014608:
	adds r0, r6, 0
	add r1, sp, 0x4
	bl xxx_get_next_char_from_string
	adds r6, r0, 0
	movs r1, 0
	ldrsh r0, [r4, r1]
	movs r2, 0x2
	ldrsh r1, [r4, r2]
	ldr r2, [sp, 0x4]
	ldr r3, [r4, 0x10]
	str r5, [sp]
	bl xxx_call_draw_char
	ldrh r1, [r4]
	adds r1, r0
	strh r1, [r4]
	ldr r0, _08014694
	ldr r0, [r0]
	str r0, [r4, 0x2C]
_08014630:
	ldr r3, _08014698
	movs r4, 0x2
	ldrsh r0, [r3, r4]
	cmp r0, 0x22
	ble _08014650
	ldr r0, _0801469C
	ldrh r1, [r0]
	movs r0, 0x10
	ands r0, r1
	lsls r0, 16
	lsrs r2, r0, 16
	cmp r2, 0
	bne _0801464C
	b _0801454C
_0801464C:
	movs r0, 0x4
	strh r0, [r3, 0x2]
_08014650:
	subs r7, 0x1
_08014652:
	cmp r7, 0
	ble _0801466C
	ldr r4, _08014698
	adds r0, r6, 0
	adds r1, r4, 0
	bl sub_8009190
	adds r6, r0, 0
	adds r0, r4, 0
	adds r0, 0x21
	ldrb r0, [r0]
	cmp r0, 0
	beq _080145A4
_0801466C:
	movs r0, 0
	bl sub_80073E0
	ldr r4, _080146A0
	str r6, [r4]
	ldr r0, _080146A4
	bl sub_801317C
	ldr r0, [r4]
	ldrb r0, [r0]
	cmp r0, 0
	bne _080146BC
	ldr r0, _080146A8
	ldr r0, [r0]
	cmp r0, 0
	beq _080146B0
	ldr r1, _080146AC
	movs r0, 0x3
	str r0, [r1]
	b _08014A72
	.align 2, 0
_08014694: .4byte gUnknown_202E78C
_08014698: .4byte gUnknown_202E748
_0801469C: .4byte gUnknown_202E77C
_080146A0: .4byte gUnknown_202E794
_080146A4: .4byte gUnknown_202EC28
_080146A8: .4byte gUnknown_202EC14
_080146AC: .4byte gUnknown_202E744
_080146B0:
	ldr r1, _080146B8
	movs r0, 0x6
	str r0, [r1]
	b _08014A72
	.align 2, 0
_080146B8: .4byte gUnknown_202E744
_080146BC:
	ldr r0, _080146E8
	movs r2, 0
	str r2, [r0, 0x30]
	adds r0, 0x20
	ldrb r0, [r0]
	cmp r0, 0
	beq _080146FC
	ldr r1, _080146EC
	ldr r0, [r1]
	cmp r0, 0x1
	beq _080146D4
	b _08014A72
_080146D4:
	movs r0, 0x7
	str r0, [r1]
	ldr r0, _080146F0
	strb r2, [r0]
	ldr r1, _080146F4
	ldr r0, _080146F8
	ldr r0, [r0]
	str r0, [r1]
	b _08014A72
	.align 2, 0
_080146E8: .4byte gUnknown_202E748
_080146EC: .4byte gUnknown_202E744
_080146F0: .4byte gUnknown_202E791
_080146F4: .4byte gUnknown_202E780
_080146F8: .4byte gUnknown_202E738
_080146FC:
	ldr r1, _08014704
	movs r0, 0x2
	b _08014A68
	.align 2, 0
_08014704: .4byte gUnknown_202E744
_08014708:
	ldr r4, _08014760
	ldrh r1, [r4]
	movs r0, 0x4
	ands r0, r1
	cmp r0, 0
	beq _08014718
	bl sub_8011A04
_08014718:
	ldrh r1, [r4]
	movs r0, 0x2
	ands r0, r1
	ldr r2, _08014764
	cmp r0, 0
	bne _08014742
	movs r0, 0x40
	ands r0, r1
	cmp r0, 0
	beq _08014742
	ldr r0, _08014768
	ldrh r1, [r0, 0x2]
	movs r0, 0x3
	ands r0, r1
	cmp r0, 0
	beq _08014742
	ldr r0, _0801476C
	movs r1, 0x1
	strb r1, [r0]
	ldr r0, _08014770
	str r0, [r2, 0x30]
_08014742:
	ldr r1, [r2, 0x30]
	adds r1, 0x1
	str r1, [r2, 0x30]
	ldr r0, [r2, 0x2C]
	cmp r1, r0
	bgt _08014750
	b _08014A72
_08014750:
	ldr r1, _08014774
	movs r0, 0x1
	str r0, [r1]
	adds r1, r2, 0
	adds r1, 0x21
	movs r0, 0
	strb r0, [r1]
	b _08014A6A
	.align 2, 0
_08014760: .4byte gUnknown_202E77C
_08014764: .4byte gUnknown_202E748
_08014768: .4byte gUnknown_20255F0
_0801476C: .4byte gUnknown_202E790
_08014770: .4byte 0x0001869f
_08014774: .4byte gUnknown_202E744
_08014778:
	ldr r0, _080147B4
	ldrh r1, [r0]
	movs r0, 0x80
	lsls r0, 1
	ands r0, r1
	cmp r0, 0
	beq _080147DC
	movs r0, 0x9
	str r0, [r3]
	ldr r1, _080147B8
	movs r0, 0
	strb r0, [r1]
	ldr r0, _080147BC
	ldr r1, [r0]
	cmp r1, 0
	ble _080147C8
	ldr r2, _080147C0
	ldr r0, _080147C4
	ldr r0, [r0]
	subs r0, r1, r0
	str r0, [r2]
	cmp r0, 0
	blt _080147A8
	b _08014A6A
_080147A8:
	movs r0, 0xB
	str r0, [r3]
	movs r0, 0
	str r0, [r2]
	b _08014A6A
	.align 2, 0
_080147B4: .4byte gUnknown_202E77C
_080147B8: .4byte gUnknown_202E791
_080147BC: .4byte gUnknown_202E740
_080147C0: .4byte gUnknown_202E780
_080147C4: .4byte gUnknown_202E784
_080147C8:
	ldr r0, _080147D4
	ldr r1, _080147D8
	ldr r1, [r1]
	str r1, [r0]
	b _08014A6A
	.align 2, 0
_080147D4: .4byte gUnknown_202E780
_080147D8: .4byte gUnknown_202E738
_080147DC:
	movs r0, 0xB
	str r0, [r3]
	b _08014A6A
_080147E2:
	movs r5, 0
	ldr r0, _0801481C
	adds r0, 0x20
	strb r5, [r0]
	ldr r4, _08014820
	adds r0, r4, 0
	movs r1, 0
	bl nullsub_34
	ldr r0, _08014824
	ldrh r1, [r0]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	bne _08014802
	b _0801494C
_08014802:
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	beq _0801482C
	ldr r1, _08014828
	ldr r0, [r1]
	cmp r0, 0
	bgt _08014814
	b _0801494C
_08014814:
	subs r0, 0x1
	str r0, [r1]
	b _08014856
	.align 2, 0
_0801481C: .4byte gUnknown_202E748
_08014820: .4byte gUnknown_202EC28
_08014824: .4byte gUnknown_202E77C
_08014828: .4byte gUnknown_202E780
_0801482C:
	ldr r2, _080148E4
	ldrh r1, [r2, 0x2]
	movs r0, 0x3
	ands r0, r1
	cmp r0, 0
	beq _0801483A
	b _0801494C
_0801483A:
	ldrb r0, [r4, 0x1]
	cmp r0, 0
	beq _08014842
	b _0801494C
_08014842:
	ldrh r1, [r2]
	movs r0, 0xF2
	ands r0, r1
	cmp r0, 0x2
	bne _0801484E
	b _0801494C
_0801484E:
	ldrb r0, [r4, 0x5]
	cmp r0, 0
	beq _08014856
	movs r5, 0x1
_08014856:
	cmp r5, 0
	bne _0801494C
	ldr r1, _080148E8
	ldrb r0, [r1]
	adds r2, r0, 0x1
	strb r2, [r1]
	ldr r0, _080148EC
	ldrh r7, [r0]
	movs r0, 0x2
	ands r0, r7
	cmp r0, 0
	beq _08014870
	b _08014A72
_08014870:
	movs r0, 0x8
	ands r2, r0
	cmp r2, 0
	bne _0801487A
	b _08014A72
_0801487A:
	ldr r3, _080148F0
	ldrh r1, [r3]
	ldr r0, _080148F4
	ands r0, r1
	ldr r1, _080148F8
	ands r0, r1
	ldr r4, _080148FC
	ands r0, r4
	ldr r1, _08014900
	ands r0, r1
	ldr r1, _08014904
	ands r0, r1
	movs r1, 0x80
	lsls r1, 7
	ldr r2, _08014908
	ands r0, r2
	orrs r0, r1
	strh r0, [r3]
	ldrh r0, [r3, 0x2]
	ldr r5, _0801490C
	ands r5, r0
	ands r5, r2
	strh r5, [r3, 0x2]
	movs r2, 0xFC
	lsls r2, 2
	ldrh r1, [r3, 0x4]
	movs r0, 0xFC
	lsls r0, 8
	ands r0, r1
	orrs r0, r2
	ands r0, r4
	movs r6, 0xF
	lsls r1, r6, 12
	ldr r2, _08014910
	ands r0, r2
	movs r4, 0
	mov r8, r4
	orrs r0, r1
	strh r0, [r3, 0x4]
	movs r0, 0x10
	ands r0, r7
	adds r4, r3, 0
	cmp r0, 0
	beq _08014914
	movs r2, 0xF0
	lsls r2, 3
	ldrh r1, [r4, 0x6]
	adds r0, r6, 0
	ands r0, r1
	orrs r0, r2
	strh r0, [r4, 0x6]
	movs r0, 0x70
	b _08014932
	.align 2, 0
_080148E4: .4byte gUnknown_20255F0
_080148E8: .4byte gUnknown_202E791
_080148EC: .4byte gUnknown_202E77C
_080148F0: .4byte gUnknown_202E6E0
_080148F4: .4byte 0x0000feff
_080148F8: .4byte 0x0000fdff
_080148FC: .4byte 0x0000f3ff
_08014900: .4byte 0x0000efff
_08014904: .4byte 0x0000dfff
_08014908: .4byte 0x00003fff
_0801490C: .4byte 0x0000c1ff
_08014910: .4byte 0x00000fff
_08014914:
	ldr r3, _08014944
	movs r0, 0xA
	ldrsh r1, [r3, r0]
	adds r1, 0x1
	ands r1, r2
	lsls r1, 4
	ldrh r2, [r4, 0x6]
	adds r0, r6, 0
	ands r0, r2
	orrs r0, r1
	strh r0, [r4, 0x6]
	movs r1, 0x8
	ldrsh r0, [r3, r1]
	ldr r1, _08014948
	ands r0, r1
_08014932:
	strh r0, [r4, 0x2]
	movs r1, 0x80
	lsls r1, 1
	adds r0, r4, 0
	movs r2, 0
	movs r3, 0
	bl AddSprite
	b _08014A72
	.align 2, 0
_08014944: .4byte gUnknown_202E748
_08014948: .4byte 0x000001ff
_0801494C:
	ldr r0, _08014960
	ldr r0, [r0]
	ldrb r0, [r0]
	cmp r0, 0
	bne _08014968
	ldr r1, _08014964
	movs r0, 0xB
	str r0, [r1]
	b _080149BA
	.align 2, 0
_08014960: .4byte gUnknown_202E794
_08014964: .4byte gUnknown_202E744
_08014968:
	ldr r4, _08014974
	ldr r0, [r4]
	cmp r0, 0x9
	bne _08014978
	movs r0, 0xB
	b _080149B8
	.align 2, 0
_08014974: .4byte gUnknown_202E744
_08014978:
	cmp r0, 0x8
	bne _080149B6
	ldr r2, _080149A0
	movs r1, 0x4
	strh r1, [r2]
	movs r3, 0x2
	ldrsh r0, [r2, r3]
	cmp r0, 0x22
	ble _080149B6
	strh r1, [r2, 0x2]
	ldr r0, _080149A4
	ldrh r1, [r0]
	movs r0, 0x10
	ands r0, r1
	cmp r0, 0
	beq _080149A8
_08014998:
	movs r0, 0
	bl sub_8008C54
	b _080149B6
	.align 2, 0
_080149A0: .4byte gUnknown_202E748
_080149A4: .4byte gUnknown_202E77C
_080149A8:
	ldr r1, [r2, 0x1C]
	cmp r1, 0
	bne _08014998
	movs r0, 0xA
	str r0, [r4]
	str r1, [r2, 0x28]
	b _080149BA
_080149B6:
	movs r0, 0x1
_080149B8:
	str r0, [r4]
_080149BA:
	ldr r1, _080149D0
	movs r0, 0x70
	strh r0, [r1, 0x8]
	ldr r0, _080149D4
	movs r4, 0x2
	ldrsh r0, [r0, r4]
	lsls r0, 3
	adds r0, 0x22
	strh r0, [r1, 0xA]
	b _08014A72
	.align 2, 0
_080149D0: .4byte gUnknown_202E748
_080149D4: .4byte gUnknown_2027370
_080149D8:
	ldr r4, _080149F8
	ldr r0, [r4, 0x28]
	adds r0, 0x1
	str r0, [r4, 0x28]
	ldr r0, _080149FC
	ldr r1, [r0]
	movs r0, 0
	bl _call_via_r1
	ldr r0, [r4, 0x28]
	cmp r0, 0x11
	ble _08014A72
	ldr r1, _08014A00
	movs r0, 0x1
	str r0, [r1]
	b _08014A72
	.align 2, 0
_080149F8: .4byte gUnknown_202E748
_080149FC: .4byte gUnknown_203B088
_08014A00: .4byte gUnknown_202E744
_08014A04:
	ldr r0, _08014A2C
	ldrh r1, [r0]
	movs r0, 0x80
	lsls r0, 2
	ands r0, r1
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0
	beq _08014A34
	bl sub_8004914
	movs r0, 0
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	ldr r1, _08014A30
	movs r0, 0
	str r0, [r1]
	b _08014A72
	.align 2, 0
_08014A2C: .4byte gUnknown_202E77C
_08014A30: .4byte gUnknown_202E744
_08014A34:
	str r0, [r3]
	b _08014A72
_08014A38:
	bl sub_8014A88
	ldr r1, _08014A44
	movs r0, 0x4
	str r0, [r1]
	b _08014A72
	.align 2, 0
_08014A44: .4byte gUnknown_202E744
_08014A48:
	bl sub_8014B94
	lsls r0, 24
	cmp r0, 0
	beq _08014A72
	ldr r1, _08014A5C
	movs r0, 0x5
	str r0, [r1]
	b _08014A72
	.align 2, 0
_08014A5C: .4byte gUnknown_202E744
_08014A60:
	bl nullsub_35
	ldr r1, _08014A84
	movs r0, 0xB
_08014A68:
	str r0, [r1]
_08014A6A:
	mov r0, r10
	cmp r0, 0
	beq _08014A72
	b _080144DC
_08014A72:
	add sp, 0x8
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_08014A84: .4byte gUnknown_202E744
	thumb_func_end xxx_draw_string_80144C4

	thumb_func_start sub_8014A88
sub_8014A88:
	push {r4-r7,lr}
	sub sp, 0x88
	ldr r0, _08014A98
	ldr r4, [r0]
	movs r5, 0
	movs r7, 0
	movs r6, 0
	b _08014ABE
	.align 2, 0
_08014A98: .4byte gUnknown_202EC14
_08014A9C:
	adds r5, 0xC
	ldr r0, [r4]
	add r1, sp, 0x8
	add r2, sp, 0x88
	movs r3, 0
	bl xxx_format_string
	add r0, sp, 0x8
	bl sub_8008ED0
	cmp r7, r0
	bge _08014AB6
	adds r7, r0, 0
_08014AB6:
	adds r4, 0x8
	adds r6, 0x1
	cmp r6, 0x9
	bgt _08014AC4
_08014ABE:
	ldr r0, [r4]
	cmp r0, 0
	bne _08014A9C
_08014AC4:
	adds r0, r5, 0
	cmp r5, 0
	bge _08014ACC
	adds r0, r5, 0x7
_08014ACC:
	asrs r2, r0, 3
	movs r0, 0x7
	ands r5, r0
	cmp r5, 0
	beq _08014AD8
	adds r2, 0x1
_08014AD8:
	ldr r4, _08014B74
	ldr r0, _08014B78
	ldr r0, [r0]
	str r0, [r4, 0x34]
	adds r1, r7, 0
	cmp r1, 0
	bge _08014AE8
	adds r1, 0x7
_08014AE8:
	asrs r1, 3
	adds r1, 0x2
	strh r1, [r4, 0x3C]
	adds r0, r4, 0
	adds r0, 0x40
	strh r2, [r0]
	strh r2, [r4, 0x3E]
	movs r0, 0x1C
	subs r0, r1
	strh r0, [r4, 0x38]
	movs r0, 0xE
	subs r0, r2
	strh r0, [r4, 0x3A]
	movs r0, 0x80
	strb r0, [r4]
	movs r0, 0xC0
	strb r0, [r4, 0x18]
	ldr r5, _08014B7C
	ldr r0, [r5]
	cmp r0, 0
	beq _08014B1E
	adds r1, r4, 0
	adds r1, 0x48
	ldm r0!, {r2,r3,r6}
	stm r1!, {r2,r3,r6}
	ldm r0!, {r2,r3,r6}
	stm r1!, {r2,r3,r6}
_08014B1E:
	bl sub_8004914
	adds r0, r4, 0
	movs r1, 0x1
	movs r2, 0
	bl sub_800641C
	ldr r0, _08014B80
	ldr r1, _08014B84
	ldr r1, [r1]
	ldr r2, _08014B88
	ldr r3, _08014B8C
	ldr r3, [r3]
	ldr r4, _08014B90
	ldr r4, [r4]
	str r4, [sp]
	movs r4, 0x2
	str r4, [sp, 0x4]
	bl sub_8012D60
	ldr r0, [r5]
	cmp r0, 0
	beq _08014B6A
	movs r0, 0x3
	bl sub_80073B8
	ldr r0, [r5]
	ldr r2, [r0, 0x18]
	movs r0, 0
	str r0, [sp]
	movs r0, 0x4
	movs r1, 0x2
	movs r3, 0x3
	bl xxx_call_draw_string
	movs r0, 0x3
	bl sub_80073E0
_08014B6A:
	add sp, 0x88
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_08014B74: .4byte gUnknown_203B198
_08014B78: .4byte gUnknown_202EC10
_08014B7C: .4byte gUnknown_202EC20
_08014B80: .4byte gUnknown_202EBC0
_08014B84: .4byte gUnknown_202EC14
_08014B88: .4byte gUnknown_80D48A0
_08014B8C: .4byte gUnknown_202EC18
_08014B90: .4byte gUnknown_202EC1C
	thumb_func_end sub_8014A88

	thumb_func_start sub_8014B94
sub_8014B94:
	push {r4,lr}
	ldr r4, _08014BA8
	adds r0, r4, 0
	bl sub_8012FD8
	lsls r0, 24
	cmp r0, 0
	beq _08014BAC
	movs r0, 0
	b _08014BB6
	.align 2, 0
_08014BA8: .4byte gUnknown_202EBC0
_08014BAC:
	ldr r1, _08014BBC
	adds r0, r4, 0
	bl sub_8013114
	movs r0, 0x1
_08014BB6:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_08014BBC: .4byte gUnknown_202EC1C
	thumb_func_end sub_8014B94

	thumb_func_start nullsub_35
nullsub_35:
	bx lr
	thumb_func_end nullsub_35

	thumb_func_start xxx_format_string
xxx_format_string:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x40
	adds r5, r0, 0
	str r1, [sp, 0x3C]
	adds r7, r2, 0
	lsls r3, 16
	lsrs r3, 16
	mov r8, r3
	movs r0, 0x1
	mov r10, r0
	mov r9, r0
	subs r7, 0x1
	b _08014F62
_08014BE6:
	movs r1, 0x1
	b _08014C2C
_08014BEA:
	mov r0, r10
	cmp r0, 0
	beq _08014C24
	movs r1, 0
	mov r10, r1
	mov r9, r1
	movs r0, 0x8
	mov r1, r8
	ands r0, r1
	cmp r0, 0
	beq _08014C2E
	ldr r0, _08014C1C
	add r4, sp, 0x3C
	adds r1, r4, 0
	adds r2, r7, 0
	mov r3, r8
	bl sub_8014FA8
	ldr r0, _08014C20
	adds r1, r4, 0
	adds r2, r7, 0
	mov r3, r8
	bl sub_8014FA8
	b _08014C2E
	.align 2, 0
_08014C1C: .4byte gUnknown_202E5D8
_08014C20: .4byte gUnknown_80D48F4
_08014C24:
	mov r0, r9
	cmp r0, 0
	beq _08014C2E
	movs r1, 0
_08014C2C:
	mov r9, r1
_08014C2E:
	cmp r6, 0x23
	bne _08014C5A
	ldrb r3, [r5, 0x1]
	cmp r3, 0x50
	beq _08014C3C
	cmp r3, 0x70
	bne _08014C42
_08014C3C:
	movs r0, 0x1
	mov r10, r0
	mov r9, r0
_08014C42:
	ldr r1, [sp, 0x3C]
	adds r2, r1, 0x1
	cmp r2, r7
	bcs _08014C56
	movs r0, 0x23
	strb r0, [r1]
	str r2, [sp, 0x3C]
	strb r3, [r1, 0x1]
	adds r0, r2, 0x1
	str r0, [sp, 0x3C]
_08014C56:
	adds r5, 0x2
	b _08014F62
_08014C5A:
	cmp r6, 0x24
	beq _08014C60
	b _08014F26
_08014C60:
	movs r4, 0
	adds r5, 0x1
	ldrb r0, [r5]
	subs r0, 0x24
	cmp r0, 0x52
	bls _08014C6E
	b _08014F0E
_08014C6E:
	lsls r0, 2
	ldr r1, _08014C78
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08014C78: .4byte _08014C7C
	.align 2, 0
_08014C7C:
	.4byte _08014F04
	.4byte _08014F0E
	.4byte _08014F0E
	.4byte _08014F0E
	.4byte _08014F0E
	.4byte _08014F0E
	.4byte _08014F0E
	.4byte _08014F0E
	.4byte _08014F0E
	.4byte _08014F0C
	.4byte _08014F0E
	.4byte _08014F0E
	.4byte _08014F0E
	.4byte _08014F0E
	.4byte _08014F0E
	.4byte _08014F0E
	.4byte _08014F0E
	.4byte _08014F0E
	.4byte _08014F0E
	.4byte _08014F0E
	.4byte _08014F0E
	.4byte _08014F0E
	.4byte _08014F0E
	.4byte _08014F0E
	.4byte _08014F0E
	.4byte _08014F0E
	.4byte _08014F0E
	.4byte _08014F0E
	.4byte _08014F0E
	.4byte _08014F0E
	.4byte _08014F0E
	.4byte _08014F0E
	.4byte _08014F0E
	.4byte _08014F0E
	.4byte _08014F0E
	.4byte _08014F0E
	.4byte _08014F0E
	.4byte _08014F0E
	.4byte _08014F0E
	.4byte _08014F0E
	.4byte _08014F0E
	.4byte _08014F0E
	.4byte _08014F0E
	.4byte _08014F0E
	.4byte _08014F0E
	.4byte _08014F0E
	.4byte _08014F0E
	.4byte _08014F0E
	.4byte _08014F0E
	.4byte _08014F0E
	.4byte _08014EC4
	.4byte _08014F0E
	.4byte _08014F0E
	.4byte _08014F0E
	.4byte _08014F0E
	.4byte _08014F0E
	.4byte _08014F0E
	.4byte _08014F0E
	.4byte _08014F0E
	.4byte _08014F0E
	.4byte _08014F0E
	.4byte _08014F0E
	.4byte _08014F0E
	.4byte _08014F0E
	.4byte _08014E60
	.4byte _08014F0E
	.4byte _08014F0E
	.4byte _08014F0E
	.4byte _08014E54
	.4byte _08014DC8
	.4byte _08014F0E
	.4byte _08014F0E
	.4byte _08014F0E
	.4byte _08014DDC
	.4byte _08014E10
	.4byte _08014F0E
	.4byte _08014F0E
	.4byte _08014F0E
	.4byte _08014F0E
	.4byte _08014F0E
	.4byte _08014E24
	.4byte _08014F0E
	.4byte _08014E84
_08014DC8:
	adds r5, 0x1
	ldrb r0, [r5]
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 4
	ldr r0, _08014DD8
	adds r4, r1, r0
	b _08014F0C
	.align 2, 0
_08014DD8: .4byte gUnknown_202CF58
_08014DDC:
	adds r5, 0x1
	ldrb r0, [r5]
	cmp r0, 0x6D
	bne _08014DFC
	bl sub_808D3BC
	adds r1, r0, 0
	ldr r4, _08014DF8
	adds r0, r4, 0
	movs r2, 0
	bl sub_808D9AC
	b _08014F0E
	.align 2, 0
_08014DF8: .4byte gUnknown_202EB80
_08014DFC:
	ldrb r0, [r5]
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 4
	ldr r0, _08014E0C
	adds r4, r1, r0
	b _08014F0C
	.align 2, 0
_08014E0C: .4byte gUnknown_202D098
_08014E10:
	adds r5, 0x1
	ldrb r0, [r5]
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 4
	ldr r0, _08014E20
	adds r4, r1, r0
	b _08014F0C
	.align 2, 0
_08014E20: .4byte gFileCache + 0x110
_08014E24:
	adds r5, 0x1
	movs r0, 0
	bl sub_80023E4
	lsls r0, 24
	cmp r0, 0
	beq _08014E40
	ldr r0, _08014E3C
	bl sub_80920D8
	b _08014E48
	.align 2, 0
_08014E3C: .4byte gTeamName
_08014E40:
	ldr r0, _08014E4C
	ldr r1, _08014E50
	bl strcpy
_08014E48:
	ldr r4, _08014E4C
	b _08014F0E
	.align 2, 0
_08014E4C: .4byte gTeamName
_08014E50: .4byte gUnknown_80D48F8
_08014E54:
	adds r5, 0x1
	ldr r4, _08014E5C
	b _08014F0E
	.align 2, 0
_08014E5C: .4byte gUnknown_202E628
_08014E60:
	adds r5, 0x1
	ldr r1, _08014E7C
	ldr r2, _08014E80
	ldrb r0, [r5]
	subs r0, 0x30
	lsls r0, 2
	adds r0, r2
	adds r5, 0x1
	ldr r2, [r0]
	mov r0, sp
	bl sub_800D158
_08014E78:
	mov r4, sp
	b _08014F0E
	.align 2, 0
_08014E7C: .4byte gUnknown_80D4900
_08014E80: .4byte gUnknown_202DE30
_08014E84:
	adds r5, 0x1
	ldr r1, _08014EBC
	ldrb r0, [r5]
	subs r0, 0x30
	lsls r0, 2
	adds r0, r1
	ldr r3, [r0]
	adds r5, 0x1
	ldr r1, _08014EC0
	ldrb r2, [r5]
	subs r2, 0x30
	adds r5, 0x1
	mov r0, sp
	bl sub_800D158
	mov r0, sp
	ldrb r1, [r0]
	cmp r1, 0
	beq _08014E78
	movs r2, 0x60
_08014EAC:
	cmp r1, 0x20
	bne _08014EB2
	strb r2, [r0]
_08014EB2:
	adds r0, 0x1
	ldrb r1, [r0]
	cmp r1, 0
	bne _08014EAC
	b _08014E78
	.align 2, 0
_08014EBC: .4byte gUnknown_202DE30
_08014EC0: .4byte gUnknown_80D4904
_08014EC4:
	adds r5, 0x1
	ldr r1, _08014EFC
	ldrb r0, [r5]
	subs r0, 0x30
	lsls r0, 2
	adds r0, r1
	ldr r3, [r0]
	adds r5, 0x1
	ldr r1, _08014F00
	ldrb r2, [r5]
	subs r2, 0x30
	adds r5, 0x1
	mov r0, sp
	bl sub_800D158
	mov r0, sp
	ldrb r1, [r0]
	cmp r1, 0
	beq _08014E78
	movs r2, 0x60
_08014EEC:
	cmp r1, 0x20
	bne _08014EF2
	strb r2, [r0]
_08014EF2:
	adds r0, 0x1
	ldrb r1, [r0]
	cmp r1, 0
	bne _08014EEC
	b _08014E78
	.align 2, 0
_08014EFC: .4byte gUnknown_202DE30
_08014F00: .4byte gUnknown_80D4908
_08014F04:
	ldr r4, _08014F08
	b _08014F0E
	.align 2, 0
_08014F08: .4byte gUnknown_80D4910
_08014F0C:
	adds r5, 0x1
_08014F0E:
	cmp r4, 0
	beq _08014F62
	add r1, sp, 0x3C
	adds r0, r4, 0
	adds r2, r7, 0
	mov r3, r8
	bl sub_8014FA8
	lsls r0, 24
	cmp r0, 0
	bne _08014F7E
	b _08014F62
_08014F26:
	adds r0, r6, 0
	adds r0, 0x7F
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x3
	bls _08014F36
	cmp r6, 0x87
	bne _08014F54
_08014F36:
	ldr r0, [sp, 0x3C]
	cmp r0, r7
	bcs _08014F42
	strb r6, [r0]
	adds r0, 0x1
	str r0, [sp, 0x3C]
_08014F42:
	adds r5, 0x1
	ldrb r1, [r5]
	cmp r1, 0
	beq _08014F7E
	ldr r0, [sp, 0x3C]
	cmp r0, r7
	bcs _08014F60
	strb r1, [r0]
	b _08014F5C
_08014F54:
	ldr r0, [sp, 0x3C]
	cmp r0, r7
	bcs _08014F60
	strb r6, [r0]
_08014F5C:
	adds r0, 0x1
	str r0, [sp, 0x3C]
_08014F60:
	adds r5, 0x1
_08014F62:
	ldrb r6, [r5]
	cmp r6, 0
	beq _08014F7E
	cmp r6, 0xD
	beq _08014F72
	cmp r6, 0xA
	beq _08014F72
	b _08014BEA
_08014F72:
	movs r0, 0x80
	mov r1, r8
	ands r0, r1
	cmp r0, 0
	bne _08014F7E
	b _08014BE6
_08014F7E:
	ldr r0, [sp, 0x3C]
	movs r1, 0
	strb r1, [r0]
	ldrb r0, [r5]
	cmp r0, 0xD
	bne _08014F8C
	adds r5, 0x1
_08014F8C:
	ldrb r0, [r5]
	cmp r0, 0xA
	bne _08014F94
	adds r5, 0x1
_08014F94:
	adds r0, r5, 0
	add sp, 0x40
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end xxx_format_string

	thumb_func_start sub_8014FA8
sub_8014FA8:
	push {r4-r6,lr}
	adds r4, r0, 0
	adds r5, r1, 0
	adds r6, r2, 0
	lsls r3, 16
	lsrs r3, 16
	ldr r2, [r5]
	ldrb r1, [r4]
	cmp r1, 0
	beq _08014FE4
	movs r0, 0x80
	ands r0, r3
	lsls r0, 16
	lsrs r3, r0, 16
_08014FC4:
	cmp r3, 0
	beq _08014FD2
	cmp r1, 0xD
	bne _08014FD2
	str r2, [r5]
	movs r0, 0x1
	b _08014FE8
_08014FD2:
	cmp r2, r6
	bcs _08014FDC
	ldrb r0, [r4]
	strb r0, [r2]
	adds r2, 0x1
_08014FDC:
	adds r4, 0x1
	ldrb r1, [r4]
	cmp r1, 0
	bne _08014FC4
_08014FE4:
	str r2, [r5]
	movs r0, 0
_08014FE8:
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end sub_8014FA8

	thumb_func_start sub_8014FF0
sub_8014FF0:
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
	bl xxx_call_draw_string
	add sp, 0x1F8
	pop {r3}
	mov r8, r3
	pop {r4-r6}
	pop {r0}
	bx r0
	.align 2, 0
_08015030: .4byte 0x000001f7
	thumb_func_end sub_8014FF0

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

	thumb_func_start sub_8015080
sub_8015080:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x8
	mov r8, r0
	mov r9, r1
	ldr r4, _08015158
	ldr r0, _0801515C
	movs r1, 0x8
	bl MemoryAlloc
	str r0, [r4]
	movs r1, 0
	str r1, [r0]
	mov r12, r4
	ldr r0, _08015160
	mov r10, r0
	mov r5, r12
	movs r3, 0
	movs r2, 0x3
_080150AC:
	mov r4, r12
	ldr r1, [r4]
	adds r1, r3
	adds r1, 0x54
	mov r0, r10
	ldm r0!, {r4,r6,r7}
	stm r1!, {r4,r6,r7}
	ldm r0!, {r4,r6,r7}
	stm r1!, {r4,r6,r7}
	adds r3, 0x18
	subs r2, 0x1
	cmp r2, 0
	bge _080150AC
	movs r4, 0
	ldr r1, [r5]
	adds r1, 0x54
	ldr r0, _08015164
	ldm r0!, {r2,r6,r7}
	stm r1!, {r2,r6,r7}
	ldm r0!, {r3,r6,r7}
	stm r1!, {r3,r6,r7}
	ldr r1, [r5]
	adds r1, 0x84
	ldr r0, _08015168
	ldm r0!, {r2,r3,r6}
	stm r1!, {r2,r3,r6}
	ldm r0!, {r2,r3,r7}
	stm r1!, {r2,r3,r7}
	ldr r0, [r5]
	adds r0, 0x84
	mov r1, r9
	bl sub_8012CAC
	bl sub_8004914
	ldr r0, [r5]
	adds r0, 0x54
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	movs r0, 0
	bl sub_80073B8
	ldr r2, [r5]
	adds r1, r2, 0
	adds r1, 0xB4
	ldr r6, _0801515C
	adds r2, r6
	mov r0, r8
	movs r3, 0
	bl xxx_format_string
	ldr r2, [r5]
	adds r2, 0xB4
	str r4, [sp]
	movs r0, 0x4
	movs r1, 0x4
	movs r3, 0
	bl xxx_call_draw_string
	movs r0, 0
	bl sub_80073E0
	ldr r0, [r5]
	adds r0, 0x4
	movs r1, 0x1
	negs r1, r1
	str r1, [sp]
	movs r1, 0x2
	str r1, [sp, 0x4]
	mov r1, r9
	movs r2, 0
	movs r3, 0
	bl sub_8012D60
	movs r0, 0x1
	add sp, 0x8
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	.align 2, 0
_08015158: .4byte gUnknown_203B1F8
_0801515C: .4byte 0x000004b4
_08015160: .4byte gUnknown_80DAF70
_08015164: .4byte gUnknown_80DAF88
_08015168: .4byte gUnknown_80DAFA0
	thumb_func_end sub_8015080

	thumb_func_start sub_801516C
sub_801516C:
	push {r4,lr}
	ldr r4, _08015184
	ldr r0, [r4]
	adds r0, 0x4
	bl sub_8012FD8
	lsls r0, 24
	cmp r0, 0
	beq _08015188
	movs r0, 0
	b _08015192
	.align 2, 0
_08015184: .4byte gUnknown_203B1F8
_08015188:
	ldr r1, [r4]
	adds r0, r1, 0x4
	bl sub_8013114
	movs r0, 0x3
_08015192:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_801516C

	thumb_func_start sub_8015198
sub_8015198:
	ldr r0, _080151A0
	ldr r0, [r0]
	ldr r0, [r0]
	bx lr
	.align 2, 0
_080151A0: .4byte gUnknown_203B1F8
	thumb_func_end sub_8015198

	thumb_func_start sub_80151A4
sub_80151A4:
	push {r4,lr}
	ldr r4, _080151BC
	ldr r0, [r4]
	cmp r0, 0
	beq _080151B6
	bl MemoryFree
	movs r0, 0
	str r0, [r4]
_080151B6:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080151BC: .4byte gUnknown_203B1F8
	thumb_func_end sub_80151A4

	thumb_func_start sub_80151C0
sub_80151C0:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	adds r5, r0, 0
	adds r6, r1, 0
	ldr r4, _080151FC
	movs r0, 0xCC
	lsls r0, 1
	movs r1, 0x8
	bl MemoryAlloc
	str r0, [r4]
	str r5, [r0]
	movs r1, 0
	strb r1, [r0, 0x19]
	ldr r0, [r4]
	strb r1, [r0, 0x18]
	ldr r0, [r4]
	strb r1, [r0, 0x4]
	ldr r0, [r4]
	ldr r0, [r0]
	cmp r0, 0x5
	bhi _0801524C
	lsls r0, 2
	ldr r1, _08015200
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080151FC: .4byte gUnknown_203B1FC
_08015200: .4byte _08015204
	.align 2, 0
_08015204:
	.4byte _0801524C
	.4byte _0801524C
	.4byte _0801524C
	.4byte _0801524C
	.4byte _0801521C
	.4byte _08015234
_0801521C:
	ldr r1, _08015230
	ldr r2, [r1]
	movs r0, 0x9
	strb r0, [r2, 0x1A]
	ldr r2, [r1]
	movs r0, 0x1
	strb r0, [r2, 0x4]
	ldr r2, [r1]
	movs r0, 0x36
	b _08015258
	.align 2, 0
_08015230: .4byte gUnknown_203B1FC
_08015234:
	ldr r1, _08015248
	ldr r2, [r1]
	movs r0, 0x9
	strb r0, [r2, 0x1A]
	ldr r2, [r1]
	movs r0, 0x1
	strb r0, [r2, 0x4]
	ldr r2, [r1]
	movs r0, 0x18
	b _08015258
	.align 2, 0
_08015248: .4byte gUnknown_203B1FC
_0801524C:
	ldr r1, _08015374
	ldr r2, [r1]
	movs r0, 0x6
	strb r0, [r2, 0x1A]
	ldr r2, [r1]
	movs r0, 0xA
_08015258:
	strb r0, [r2, 0x1B]
	mov r8, r1
	mov r0, r8
	ldr r2, [r0]
	movs r1, 0x9A
	lsls r1, 1
	adds r0, r2, r1
	str r6, [r0]
	adds r1, r2, 0
	adds r1, 0xF8
	adds r0, r2, 0
	adds r0, 0xFC
	str r0, [r1]
	movs r2, 0
	mov r1, r8
	movs r3, 0
_08015278:
	ldr r0, [r1]
	adds r0, 0xF8
	ldr r0, [r0]
	adds r0, r2
	strb r3, [r0]
	adds r2, 0x1
	cmp r2, 0x35
	ble _08015278
	ldr r5, _08015374
	ldr r2, [r5]
	adds r0, r2, 0
	adds r0, 0xF8
	ldr r0, [r0]
	movs r3, 0x9A
	lsls r3, 1
	adds r1, r2, r3
	ldr r1, [r1]
	ldrb r2, [r2, 0x1B]
	bl MemoryCopy8
	movs r2, 0
	ldr r0, [r5]
	ldrb r3, [r0, 0x1B]
	cmp r2, r3
	bge _080152EA
	adds r1, r0, 0
	adds r1, 0xF8
	ldr r0, [r1]
	ldrb r0, [r0]
	mov r8, r5
	cmp r0, 0
	beq _080152C8
_080152B8:
	adds r2, 0x1
	cmp r2, r3
	bge _080152EA
	ldr r0, [r1]
	adds r0, r2
	ldrb r0, [r0]
	cmp r0, 0
	bne _080152B8
_080152C8:
	mov r4, r8
	ldr r0, [r4]
	ldrb r0, [r0, 0x1B]
	cmp r2, r0
	bge _080152EA
	mov r1, r8
	movs r3, 0
_080152D6:
	ldr r0, [r1]
	adds r0, 0xF8
	ldr r0, [r0]
	adds r0, r2
	strb r3, [r0]
	adds r2, 0x1
	ldr r0, [r1]
	ldrb r0, [r0, 0x1B]
	cmp r2, r0
	blt _080152D6
_080152EA:
	bl sub_8015F44
	ldr r2, _08015374
	ldr r1, [r2]
	strb r0, [r1, 0x1C]
	ldr r1, [r2]
	ldrb r0, [r1, 0x1C]
	ldrb r5, [r1, 0x1B]
	cmp r0, r5
	bne _08015302
	subs r0, 0x1
	strb r0, [r1, 0x1C]
_08015302:
	movs r6, 0x1
	mov r12, r6
	ldr r6, [r2]
	adds r5, r6, 0x6
	ldrh r1, [r6, 0x6]
	ldr r0, _08015378
	ands r0, r1
	ldr r1, _0801537C
	ands r0, r1
	ldr r2, _08015380
	ands r0, r2
	ldr r1, _08015384
	ands r0, r1
	ldr r1, _08015388
	ands r0, r1
	strh r0, [r6, 0x6]
	ldrh r0, [r5, 0x4]
	adds r3, r2, 0
	ands r3, r0
	movs r1, 0xF
	movs r2, 0xF0
	lsls r2, 8
	ldr r0, _0801538C
	ands r3, r0
	orrs r3, r2
	strh r3, [r5, 0x4]
	ldrh r0, [r5, 0x2]
	movs r4, 0xFE
	lsls r4, 8
	ands r4, r0
	movs r0, 0xF0
	orrs r4, r0
	strh r4, [r5, 0x2]
	movs r2, 0xF0
	lsls r2, 4
	ldrh r0, [r5, 0x6]
	ands r1, r0
	movs r7, 0
	orrs r1, r2
	strh r1, [r5, 0x6]
	ldrb r0, [r6, 0x4]
	cmp r0, 0
	beq _0801539C
	ldr r0, _08015390
	ands r4, r0
	ldr r1, _08015394
	movs r0, 0xFC
	lsls r0, 8
	ands r3, r0
	orrs r3, r1
	strh r3, [r5, 0x4]
	ldr r0, _08015398
	ands r4, r0
	strh r4, [r5, 0x2]
	mov r7, r12
	b _080153BE
	.align 2, 0
_08015374: .4byte gUnknown_203B1FC
_08015378: .4byte 0x0000feff
_0801537C: .4byte 0x0000fdff
_08015380: .4byte 0x0000f3ff
_08015384: .4byte 0x0000efff
_08015388: .4byte 0x0000dfff
_0801538C: .4byte 0x00000fff
_08015390: .4byte 0x0000c1ff
_08015394: .4byte 0x000003f6
_08015398: .4byte 0x00003fff
_0801539C:
	movs r1, 0x80
	lsls r1, 6
	ldr r0, _08015468
	ands r4, r0
	orrs r4, r1
	orrs r4, r7
	movs r1, 0xFC
	lsls r1, 2
	movs r0, 0xFC
	lsls r0, 8
	ands r3, r0
	orrs r3, r1
	strh r3, [r5, 0x4]
	ldr r0, _0801546C
	ands r4, r0
	strh r4, [r5, 0x2]
	mov r1, r12
_080153BE:
	movs r2, 0x80
	lsls r2, 7
	ldrh r1, [r6, 0x6]
	ands r0, r1
	orrs r0, r2
	strh r0, [r6, 0x6]
	ldr r5, _08015470
	ldr r1, [r5]
	movs r0, 0x4
	strb r0, [r1, 0x16]
	ldr r4, [r5]
	adds r6, r4, 0
	adds r6, 0xE
	ldrh r1, [r4, 0xE]
	ldr r0, _08015474
	ands r0, r1
	ldr r1, _08015478
	ands r0, r1
	ldr r3, _0801547C
	ands r0, r3
	ldr r1, _08015480
	ands r0, r1
	ldr r1, _08015484
	ands r0, r1
	ldr r1, _0801546C
	ands r0, r1
	strh r0, [r4, 0xE]
	movs r2, 0xFD
	lsls r2, 2
	ldrh r1, [r6, 0x4]
	movs r0, 0xFC
	lsls r0, 8
	ands r0, r1
	orrs r0, r2
	ands r0, r3
	movs r2, 0xF
	movs r3, 0xF0
	lsls r3, 8
	ldr r1, _08015488
	ands r0, r1
	orrs r0, r3
	strh r0, [r6, 0x4]
	movs r0, 0xF0
	strh r0, [r6, 0x2]
	subs r1, 0xFF
	ldrh r0, [r6, 0x6]
	ands r2, r0
	movs r0, 0
	orrs r2, r1
	strh r2, [r6, 0x6]
	strb r0, [r4, 0x17]
	mov r8, r5
	ldr r2, _0801548C
	mov r10, r2
	mov r12, r8
	movs r3, 0x9C
	lsls r3, 1
	mov r9, r3
	ldr r4, _08015490
	movs r3, 0
	movs r2, 0x3
_08015438:
	mov r5, r12
	ldr r1, [r5]
	adds r1, r3
	add r1, r9
	adds r0, r4, 0
	ldm r0!, {r5-r7}
	stm r1!, {r5-r7}
	ldm r0!, {r5-r7}
	stm r1!, {r5-r7}
	adds r3, 0x18
	subs r2, 0x1
	cmp r2, 0
	bge _08015438
	mov r6, r8
	ldr r1, [r6]
	ldrb r0, [r1, 0x4]
	cmp r0, 0
	beq _08015498
	movs r7, 0xA8
	lsls r7, 1
	adds r1, r7
	ldr r0, _08015494
	b _080154A0
	.align 2, 0
_08015468: .4byte 0x0000c1ff
_0801546C: .4byte 0x00003fff
_08015470: .4byte gUnknown_203B1FC
_08015474: .4byte 0x0000feff
_08015478: .4byte 0x0000fdff
_0801547C: .4byte 0x0000f3ff
_08015480: .4byte 0x0000efff
_08015484: .4byte 0x0000dfff
_08015488: .4byte 0x00000fff
_0801548C: .4byte gUnknown_80DB550
_08015490: .4byte gUnknown_80DB538
_08015494: .4byte gUnknown_80DB580
_08015498:
	movs r0, 0xA8
	lsls r0, 1
	adds r1, r0
	ldr r0, _080154EC
_080154A0:
	ldm r0!, {r2-r4}
	stm r1!, {r2-r4}
	ldm r0!, {r5-r7}
	stm r1!, {r5-r7}
	mov r0, r8
	ldr r1, [r0]
	movs r4, 0x9C
	lsls r4, 1
	adds r1, r4
	mov r0, r10
	ldm r0!, {r2,r3,r5}
	stm r1!, {r2,r3,r5}
	ldm r0!, {r2,r6,r7}
	stm r1!, {r2,r6,r7}
	bl sub_8004914
	mov r3, r8
	ldr r0, [r3]
	adds r0, r4
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	movs r0, 0x1
	bl sub_8015A08
	bl sub_8015C1C
	bl sub_8015F84
	movs r0, 0x1
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	.align 2, 0
_080154EC: .4byte gUnknown_80DB568
	thumb_func_end sub_80151C0

	thumb_func_start sub_80154F0
sub_80154F0:
	push {r4,r5,lr}
	ldr r4, _08015558
	ldr r1, [r4]
	ldrb r0, [r1, 0x16]
	adds r0, 0x1
	strb r0, [r1, 0x16]
	bl sub_80157D8
	ldr r2, [r4]
	ldrb r1, [r2, 0x16]
	movs r5, 0x8
	adds r0, r5, 0
	ands r0, r1
	cmp r0, 0
	beq _0801551C
	adds r0, r2, 0x6
	movs r1, 0x80
	lsls r1, 1
	movs r2, 0
	movs r3, 0
	bl AddSprite
_0801551C:
	ldr r1, [r4]
	ldrb r0, [r1, 0x17]
	adds r0, 0x1
	strb r0, [r1, 0x17]
	bl sub_80158BC
	ldr r2, [r4]
	ldrb r1, [r2, 0x17]
	adds r0, r5, 0
	ands r0, r1
	cmp r0, 0
	beq _08015544
	adds r0, r2, 0
	adds r0, 0xE
	movs r1, 0x80
	lsls r1, 1
	movs r2, 0
	movs r3, 0
	bl AddSprite
_08015544:
	bl sub_8012AE8
	subs r0, 0x1
	cmp r0, 0x5
	bhi _080155E2
	lsls r0, 2
	ldr r1, _0801555C
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08015558: .4byte gUnknown_203B1FC
_0801555C: .4byte _08015560
	.align 2, 0
_08015560:
	.4byte _080155C0
	.4byte _080155C6
	.4byte _080155E2
	.4byte _080155D4
	.4byte _08015578
	.4byte _0801558C
_08015578:
	ldr r0, _08015588
	ldr r1, [r0]
	ldrb r0, [r1, 0x1C]
	cmp r0, 0
	beq _080155B8
	subs r0, 0x1
	b _080155A8
	.align 2, 0
_08015588: .4byte gUnknown_203B1FC
_0801558C:
	ldr r5, _080155B4
	ldr r0, [r5]
	ldrb r4, [r0, 0x1C]
	ldrb r0, [r0, 0x1B]
	subs r0, 0x1
	cmp r4, r0
	beq _080155B8
	bl sub_8015F44
	cmp r4, r0
	bge _080155B8
	ldr r1, [r5]
	ldrb r0, [r1, 0x1C]
	adds r0, 0x1
_080155A8:
	strb r0, [r1, 0x1C]
	movs r0, 0x3
	bl sub_80119D4
	b _080155E2
	.align 2, 0
_080155B4: .4byte gUnknown_203B1FC
_080155B8:
	movs r0, 0x2
	bl sub_80119D4
	b _080155E2
_080155C0:
	bl sub_801560C
	b _080155E4
_080155C6:
	bl sub_8015748
	lsls r0, 24
	cmp r0, 0
	beq _080155E2
	movs r0, 0x2
	b _080155E4
_080155D4:
	movs r0, 0x3
	bl sub_80119D4
	ldr r0, _080155EC
	ldr r1, [r0]
	movs r0, 0x5
	strb r0, [r1, 0x1A]
_080155E2:
	movs r0, 0
_080155E4:
	pop {r4,r5}
	pop {r1}
	bx r1
	.align 2, 0
_080155EC: .4byte gUnknown_203B1FC
	thumb_func_end sub_80154F0

	thumb_func_start sub_80155F0
sub_80155F0:
	push {r4,lr}
	ldr r4, _08015608
	ldr r0, [r4]
	cmp r0, 0
	beq _08015602
	bl MemoryFree
	movs r0, 0
	str r0, [r4]
_08015602:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08015608: .4byte gUnknown_203B1FC
	thumb_func_end sub_80155F0

	thumb_func_start sub_801560C
sub_801560C:
	push {r4-r6,lr}
	ldr r3, _08015640
	ldr r4, _08015644
	ldr r5, [r4]
	ldrb r0, [r5, 0x1A]
	lsls r1, r0, 1
	adds r1, r0
	ldrb r2, [r5, 0x19]
	lsls r0, r2, 8
	subs r0, r2
	adds r0, r1
	lsls r0, 2
	adds r3, 0x8
	adds r0, r3
	ldr r6, [r0]
	movs r0, 0x83
	lsls r0, 1
	cmp r6, r0
	beq _0801567A
	cmp r6, r0
	bgt _08015648
	subs r0, 0x1
	cmp r6, r0
	beq _0801566C
	b _080156BC
	.align 2, 0
_08015640: .4byte gUnknown_80DB0F8
_08015644: .4byte gUnknown_203B1FC
_08015648:
	ldr r0, _08015668
	cmp r6, r0
	bne _080156BC
	movs r1, 0
	ldrb r0, [r5, 0x18]
	cmp r0, 0
	bne _08015658
	movs r1, 0x1
_08015658:
	strb r1, [r5, 0x18]
	movs r0, 0x4
	bl sub_80119D4
	movs r0, 0
	bl sub_8015A08
	b _0801573E
	.align 2, 0
_08015668: .4byte 0x00000107
_0801566C:
	bl sub_8015748
	lsls r0, 24
	cmp r0, 0
	beq _0801573E
	movs r0, 0x2
	b _08015740
_0801567A:
	bl sub_8015F44
	cmp r0, 0
	beq _080156D4
	ldr r0, [r4]
	ldrb r0, [r0, 0x4]
	cmp r0, 0
	beq _08015696
	bl sub_8015F44
	ldr r1, [r4]
	ldrb r1, [r1, 0x1B]
	cmp r0, r1
	bne _080156D4
_08015696:
	movs r0, 0
	bl sub_80119D4
	ldr r0, _080156B8
	ldr r2, [r0]
	movs r1, 0x9A
	lsls r1, 1
	adds r0, r2, r1
	ldr r0, [r0]
	adds r1, r2, 0
	adds r1, 0xF8
	ldr r1, [r1]
	ldrb r2, [r2, 0x1B]
	bl MemoryCopy8
	movs r0, 0x3
	b _08015740
	.align 2, 0
_080156B8: .4byte gUnknown_203B1FC
_080156BC:
	ldr r0, [r4]
	ldrb r0, [r0, 0x4]
	cmp r0, 0
	beq _080156DC
	lsls r0, r6, 24
	lsrs r0, 24
	bl sub_803D0F0
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0xFF
	bne _080156DC
_080156D4:
	movs r0, 0x2
	bl sub_80119D4
	b _0801573E
_080156DC:
	ldr r0, _08015728
	ldr r3, [r0]
	ldrb r1, [r3, 0x18]
	adds r4, r0, 0
	cmp r1, 0x1
	bne _0801570A
	ldrb r0, [r3, 0x1B]
	subs r2, r0, 0x2
	ldrb r3, [r3, 0x1C]
	cmp r2, r3
	blt _0801570A
	adds r3, r4, 0
_080156F4:
	ldr r0, [r3]
	adds r0, 0xF8
	ldr r0, [r0]
	adds r0, r2
	ldrb r1, [r0]
	strb r1, [r0, 0x1]
	subs r2, 0x1
	ldr r0, [r3]
	ldrb r0, [r0, 0x1C]
	cmp r2, r0
	bge _080156F4
_0801570A:
	ldr r0, [r4]
	ldrb r1, [r0, 0x1C]
	adds r0, 0xF8
	ldr r0, [r0]
	adds r0, r1
	strb r6, [r0]
	ldr r1, [r4]
	ldrb r2, [r1, 0x1C]
	ldrb r0, [r1, 0x1B]
	subs r0, 0x1
	cmp r2, r0
	bge _0801572C
	adds r0, r2, 0x1
	strb r0, [r1, 0x1C]
	b _08015730
	.align 2, 0
_08015728: .4byte gUnknown_203B1FC
_0801572C:
	movs r0, 0x5
	strb r0, [r1, 0x1A]
_08015730:
	movs r0, 0
	bl sub_80119D4
	bl sub_8015C1C
	bl sub_8015F84
_0801573E:
	movs r0, 0
_08015740:
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end sub_801560C

	thumb_func_start sub_8015748
sub_8015748:
	push {r4,lr}
	ldr r4, _0801576C
	ldr r2, [r4]
	ldrb r1, [r2, 0x1C]
	adds r0, r2, 0
	adds r0, 0xF8
	ldr r0, [r0]
	adds r0, r1
	ldrb r3, [r0]
	cmp r3, 0
	bne _08015790
	cmp r1, 0
	bne _08015770
	movs r0, 0x2
	bl sub_80119D4
	movs r0, 0x1
	b _080157CE
	.align 2, 0
_0801576C: .4byte gUnknown_203B1FC
_08015770:
	subs r0, r1, 0x1
	strb r0, [r2, 0x1C]
	ldr r0, [r4]
	ldrb r1, [r0, 0x1C]
	adds r0, 0xF8
	ldr r0, [r0]
	adds r0, r1
	strb r3, [r0]
	movs r0, 0x1
	bl sub_80119D4
	bl sub_8015C1C
	bl sub_8015F84
	b _080157CC
_08015790:
	bl sub_8015F44
	subs r3, r0, 0x1
	ldr r0, [r4]
	ldrb r2, [r0, 0x1C]
	cmp r2, r3
	bge _080157B0
_0801579E:
	ldr r0, [r4]
	adds r0, 0xF8
	ldr r0, [r0]
	adds r0, r2
	ldrb r1, [r0, 0x1]
	strb r1, [r0]
	adds r2, 0x1
	cmp r2, r3
	blt _0801579E
_080157B0:
	ldr r0, _080157D4
	ldr r0, [r0]
	adds r0, 0xF8
	ldr r0, [r0]
	adds r0, r3
	movs r1, 0
	strb r1, [r0]
	movs r0, 0x1
	bl sub_80119D4
	bl sub_8015C1C
	bl sub_8015F84
_080157CC:
	movs r0, 0
_080157CE:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_080157D4: .4byte gUnknown_203B1FC
	thumb_func_end sub_8015748

	thumb_func_start sub_80157D8
sub_80157D8:
	push {r4,r5,lr}
	ldr r5, _080157EC
	ldr r0, _080157F0
	ldr r0, [r0]
	mov r12, r0
	ldr r0, [r0]
	cmp r0, 0x4
	bne _080157F8
	ldr r3, _080157F4
	b _080157FE
	.align 2, 0
_080157EC: .4byte gUnknown_20273B8
_080157F0: .4byte gUnknown_203B1FC
_080157F4: .4byte gUnknown_80DAFC0
_080157F8:
	cmp r0, 0x5
	bne _0801585C
	ldr r3, _08015850
_080157FE:
	mov r1, r12
	ldrb r0, [r1, 0x1C]
	lsls r0, 2
	adds r0, r3
	movs r2, 0
	ldrsh r1, [r0, r2]
	movs r2, 0
	ldrsh r0, [r5, r2]
	lsls r0, 3
	adds r1, r0
	ldr r0, _08015854
	ands r1, r0
	mov r4, r12
	adds r4, 0x6
	ldrh r2, [r4, 0x2]
	movs r0, 0xFE
	lsls r0, 8
	ands r0, r2
	orrs r0, r1
	strh r0, [r4, 0x2]
	mov r1, r12
	ldrb r0, [r1, 0x1C]
	lsls r0, 2
	adds r0, r3
	movs r2, 0x2
	ldrsh r1, [r0, r2]
	movs r3, 0x2
	ldrsh r0, [r5, r3]
	lsls r0, 3
	adds r1, r0
	adds r1, 0x5
	ldr r0, _08015858
	ands r1, r0
	lsls r1, 4
	ldrh r2, [r4, 0x6]
	movs r0, 0xF
	ands r0, r2
	orrs r0, r1
	strh r0, [r4, 0x6]
	b _080158B0
	.align 2, 0
_08015850: .4byte gUnknown_80DB098
_08015854: .4byte 0x000001ff
_08015858: .4byte 0x00000fff
_0801585C:
	mov r0, r12
	ldrb r1, [r0, 0x1C]
	lsls r1, 1
	mov r2, r12
	adds r2, 0x1E
	adds r2, r1
	adds r0, 0x8A
	adds r0, r1
	movs r3, 0
	ldrsh r1, [r0, r3]
	lsrs r0, r1, 31
	adds r1, r0
	asrs r1, 1
	ldrh r2, [r2]
	adds r1, r2
	movs r2, 0
	ldrsh r0, [r5, r2]
	lsls r0, 3
	adds r0, 0x1E
	adds r1, r0
	lsls r1, 23
	lsrs r1, 23
	mov r3, r12
	adds r3, 0x6
	ldrh r2, [r3, 0x2]
	movs r0, 0xFE
	lsls r0, 8
	ands r0, r2
	orrs r0, r1
	strh r0, [r3, 0x2]
	movs r0, 0x2
	ldrsh r1, [r5, r0]
	lsls r1, 3
	adds r1, 0x22
	ldr r0, _080158B8
	ands r1, r0
	lsls r1, 4
	ldrh r2, [r3, 0x6]
	movs r0, 0xF
	ands r0, r2
	orrs r0, r1
	strh r0, [r3, 0x6]
_080158B0:
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_080158B8: .4byte 0x00000fff
	thumb_func_end sub_80157D8

	thumb_func_start sub_80158BC
sub_80158BC:
	push {r4-r6,lr}
	ldr r6, _080158D4
	bl sub_8012AE8
	cmp r0, 0x8
	beq _08015908
	cmp r0, 0x8
	bgt _080158D8
	cmp r0, 0x7
	beq _080158E2
	b _08015980
	.align 2, 0
_080158D4: .4byte gUnknown_2027370
_080158D8:
	cmp r0, 0x9
	beq _08015930
	cmp r0, 0xA
	beq _08015958
	b _08015980
_080158E2:
	ldr r4, _08015900
	ldr r3, _08015904
	ldr r2, [r3]
	ldrb r0, [r2, 0x1A]
	lsls r1, r0, 1
	adds r1, r0
	ldrb r2, [r2, 0x19]
	lsls r0, r2, 8
	subs r0, r2
	adds r0, r1
	lsls r0, 2
	adds r0, r4
	ldrb r0, [r0]
	adds r5, r3, 0
	b _08015988
	.align 2, 0
_08015900: .4byte gUnknown_80DB0F8
_08015904: .4byte gUnknown_203B1FC
_08015908:
	ldr r4, _08015928
	ldr r3, _0801592C
	ldr r2, [r3]
	ldrb r0, [r2, 0x1A]
	lsls r1, r0, 1
	adds r1, r0
	ldrb r2, [r2, 0x19]
	lsls r0, r2, 8
	subs r0, r2
	adds r0, r1
	lsls r0, 2
	adds r0, r4
	ldrb r0, [r0, 0x1]
	adds r5, r3, 0
	b _08015988
	.align 2, 0
_08015928: .4byte gUnknown_80DB0F8
_0801592C: .4byte gUnknown_203B1FC
_08015930:
	ldr r4, _08015950
	ldr r3, _08015954
	ldr r2, [r3]
	ldrb r0, [r2, 0x1A]
	lsls r1, r0, 1
	adds r1, r0
	ldrb r2, [r2, 0x19]
	lsls r0, r2, 8
	subs r0, r2
	adds r0, r1
	lsls r0, 2
	adds r0, r4
	ldrb r0, [r0, 0x2]
	adds r5, r3, 0
	b _08015988
	.align 2, 0
_08015950: .4byte gUnknown_80DB0F8
_08015954: .4byte gUnknown_203B1FC
_08015958:
	ldr r4, _08015978
	ldr r3, _0801597C
	ldr r2, [r3]
	ldrb r0, [r2, 0x1A]
	lsls r1, r0, 1
	adds r1, r0
	ldrb r2, [r2, 0x19]
	lsls r0, r2, 8
	subs r0, r2
	adds r0, r1
	lsls r0, 2
	adds r0, r4
	ldrb r0, [r0, 0x3]
	adds r5, r3, 0
	b _08015988
	.align 2, 0
_08015978: .4byte gUnknown_80DB0F8
_0801597C: .4byte gUnknown_203B1FC
_08015980:
	ldr r1, _080159F8
	ldr r0, [r1]
	ldrb r0, [r0, 0x1A]
	adds r5, r1, 0
_08015988:
	adds r4, r5, 0
	ldr r1, [r4]
	ldrb r2, [r1, 0x1A]
	cmp r0, r2
	beq _080159A0
	strb r0, [r1, 0x1A]
	movs r0, 0x3
	bl sub_80119D4
	ldr r1, [r4]
	movs r0, 0x8
	strb r0, [r1, 0x17]
_080159A0:
	ldr r3, _080159FC
	ldr r4, [r5]
	ldrb r0, [r4, 0x1A]
	lsls r1, r0, 1
	adds r1, r0
	ldrb r2, [r4, 0x19]
	lsls r0, r2, 8
	subs r0, r2
	adds r0, r1
	lsls r0, 2
	adds r0, r3
	movs r3, 0
	ldrsh r1, [r6, r3]
	lsls r1, 3
	ldrb r2, [r0, 0x4]
	adds r1, r2
	subs r1, 0x5
	movs r3, 0x2
	ldrsh r2, [r6, r3]
	lsls r2, 3
	ldrb r0, [r0, 0x5]
	adds r2, r0
	adds r2, 0x1
	ldr r0, _08015A00
	ands r1, r0
	adds r4, 0xE
	ldrh r3, [r4, 0x2]
	movs r0, 0xFE
	lsls r0, 8
	ands r0, r3
	orrs r0, r1
	strh r0, [r4, 0x2]
	ldr r0, _08015A04
	ands r2, r0
	lsls r2, 4
	ldrh r1, [r4, 0x6]
	movs r0, 0xF
	ands r0, r1
	orrs r0, r2
	strh r0, [r4, 0x6]
	pop {r4-r6}
	pop {r0}
	bx r0
	.align 2, 0
_080159F8: .4byte gUnknown_203B1FC
_080159FC: .4byte gUnknown_80DB0F8
_08015A00: .4byte 0x000001ff
_08015A04: .4byte 0x00000fff
	thumb_func_end sub_80158BC

	thumb_func_start sub_8015A08
sub_8015A08:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x24
	movs r0, 0
	bl sub_8008C54
	movs r0, 0
	bl sub_80073B8
	ldr r3, _08015A68
	ldr r2, _08015A6C
	ldr r0, [r2]
	ldrb r1, [r0, 0x19]
	lsls r0, r1, 8
	subs r0, r1
	lsls r0, 2
	adds r1, r3, 0
	adds r1, 0x8
	adds r0, r1
	ldr r4, [r0]
	ldr r0, _08015A70
	cmp r4, r0
	bne _08015A3E
	b _08015BC0
_08015A3E:
	mov r8, r2
	adds r7, r3, 0
	add r0, sp, 0x14
	mov r10, r0
	movs r6, 0
	mov r9, r6
_08015A4A:
	ldr r0, [r2]
	ldrb r1, [r0, 0x19]
	lsls r0, r1, 8
	subs r0, r1
	lsls r0, 2
	adds r0, r6, r0
	adds r0, r3
	ldrb r0, [r0, 0x6]
	cmp r0, 0x2
	beq _08015AAA
	cmp r0, 0x2
	bgt _08015A74
	cmp r0, 0x1
	beq _08015A7A
	b _08015A82
	.align 2, 0
_08015A68: .4byte gUnknown_80DB0F8
_08015A6C: .4byte gUnknown_203B1FC
_08015A70: .4byte 0x00000109
_08015A74:
	cmp r0, 0x3
	beq _08015A7E
	b _08015A82
_08015A7A:
	movs r5, 0x5
	b _08015AAC
_08015A7E:
	movs r5, 0x7
	b _08015AAC
_08015A82:
	movs r5, 0x7
	mov r1, r8
	ldr r0, [r1]
	ldrb r0, [r0, 0x4]
	cmp r0, 0
	beq _08015AAC
	cmp r4, 0xFF
	bgt _08015AA4
	lsls r0, r4, 24
	lsrs r0, 24
	bl sub_803D0F0
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0xFF
	bne _08015AAC
	b _08015AAA
_08015AA4:
	ldr r0, _08015ADC
	cmp r4, r0
	bgt _08015AAC
_08015AAA:
	movs r5, 0x2
_08015AAC:
	movs r0, 0x84
	lsls r0, 1
	cmp r4, r0
	beq _08015B9E
	subs r0, 0x1
	cmp r4, r0
	bne _08015B04
	mov r2, r8
	ldr r0, [r2]
	ldrb r2, [r0, 0x18]
	cmp r2, 0
	bne _08015AE4
	ldrb r0, [r0, 0x19]
	lsls r1, r0, 8
	subs r1, r0
	lsls r1, 2
	adds r1, r6, r1
	adds r1, r7
	ldrb r0, [r1, 0x4]
	adds r0, 0x3
	ldrb r1, [r1, 0x5]
	str r2, [sp]
	ldr r2, _08015AE0
	b _08015B6A
	.align 2, 0
_08015ADC: .4byte 0x00000101
_08015AE0: .4byte gUnknown_80DB598
_08015AE4:
	ldrb r0, [r0, 0x19]
	lsls r1, r0, 8
	subs r1, r0
	lsls r1, 2
	adds r1, r6, r1
	adds r1, r7
	ldrb r0, [r1, 0x4]
	adds r0, 0x3
	ldrb r1, [r1, 0x5]
	mov r3, r9
	str r3, [sp]
	ldr r2, _08015B00
	b _08015B6A
	.align 2, 0
_08015B00: .4byte gUnknown_80DB5A4
_08015B04:
	cmp r4, 0x20
	bne _08015B34
	add r0, sp, 0x4
	ldr r1, _08015B30
	adds r2, r5, 0
	bl sub_800D158
	mov r1, r8
	ldr r0, [r1]
	ldrb r0, [r0, 0x19]
	lsls r1, r0, 8
	subs r1, r0
	lsls r1, 2
	adds r1, r6, r1
	adds r1, r7
	ldrb r0, [r1, 0x4]
	adds r0, 0x1
	ldrb r1, [r1, 0x5]
	mov r2, r9
	str r2, [sp]
	add r2, sp, 0x4
	b _08015B6A
	.align 2, 0
_08015B30: .4byte gUnknown_80DB5B0
_08015B34:
	cmp r4, 0xFF
	ble _08015B7C
	ldr r1, _08015B74
	movs r0, 0xFF
	ands r4, r0
	lsls r0, r4, 2
	adds r0, r1
	ldr r3, [r0]
	mov r0, r10
	ldr r1, _08015B78
	adds r2, r5, 0
	bl sub_800D158
	mov r3, r8
	ldr r0, [r3]
	ldrb r0, [r0, 0x19]
	lsls r1, r0, 8
	subs r1, r0
	lsls r1, 2
	adds r1, r6, r1
	adds r1, r7
	ldrb r0, [r1, 0x4]
	adds r0, 0x3
	ldrb r1, [r1, 0x5]
	mov r2, r9
	str r2, [sp]
	mov r2, r10
_08015B6A:
	movs r3, 0
	bl xxx_call_draw_string
	b _08015B9E
	.align 2, 0
_08015B74: .4byte gUnknown_80DB4F4
_08015B78: .4byte gUnknown_80DB5B8
_08015B7C:
	mov r3, r8
	ldr r0, [r3]
	ldrb r0, [r0, 0x19]
	lsls r1, r0, 8
	subs r1, r0
	lsls r1, 2
	adds r1, r6, r1
	adds r1, r7
	ldrb r0, [r1, 0x4]
	ldrb r1, [r1, 0x5]
	lsls r2, r4, 24
	lsrs r2, 24
	mov r3, r9
	str r3, [sp]
	adds r3, r5, 0
	bl sub_8012C60
_08015B9E:
	adds r6, 0xC
	ldr r3, _08015C10
	ldr r2, _08015C14
	ldr r0, [r2]
	ldrb r1, [r0, 0x19]
	lsls r0, r1, 8
	subs r0, r1
	lsls r0, 2
	adds r0, r6, r0
	adds r1, r3, 0
	adds r1, 0x8
	adds r0, r1
	ldr r4, [r0]
	ldr r0, _08015C18
	cmp r4, r0
	beq _08015BC0
	b _08015A4A
_08015BC0:
	movs r4, 0xE
	str r4, [sp]
	movs r0, 0
	movs r1, 0
	movs r2, 0
	movs r3, 0xE0
	bl sub_800792C
	str r4, [sp]
	movs r0, 0
	movs r1, 0
	movs r2, 0x47
	movs r3, 0xE0
	bl sub_800792C
	str r4, [sp]
	movs r0, 0
	movs r1, 0
	movs r2, 0
	movs r3, 0x48
	bl sub_8007A78
	str r4, [sp]
	movs r0, 0
	movs r1, 0xDF
	movs r2, 0
	movs r3, 0x48
	bl sub_8007A78
	movs r0, 0
	bl sub_80073E0
	add sp, 0x24
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_08015C10: .4byte gUnknown_80DB0F8
_08015C14: .4byte gUnknown_203B1FC
_08015C18: .4byte 0x00000109
	thumb_func_end sub_8015A08

	thumb_func_start sub_8015C1C
sub_8015C1C:
	push {r4,r5,lr}
	sub sp, 0x54
	movs r0, 0x1
	bl sub_8008C54
	movs r0, 0x1
	bl sub_80073B8
	ldr r0, _08015C74
	ldr r0, [r0]
	ldrb r0, [r0, 0x4]
	cmp r0, 0
	beq _08015C78
	movs r4, 0xE
	str r4, [sp]
	movs r0, 0x1
	movs r1, 0
	movs r2, 0
	movs r3, 0xE0
	bl sub_800792C
	str r4, [sp]
	movs r0, 0x1
	movs r1, 0
	movs r2, 0x37
	movs r3, 0xE0
	bl sub_800792C
	str r4, [sp]
	movs r0, 0x1
	movs r1, 0
	movs r2, 0
	movs r3, 0x38
	bl sub_8007A78
	str r4, [sp]
	movs r0, 0x1
	movs r1, 0xDF
	movs r2, 0
	movs r3, 0x38
	bl sub_8007A78
	b _08015CB2
	.align 2, 0
_08015C74: .4byte gUnknown_203B1FC
_08015C78:
	movs r4, 0xE
	str r4, [sp]
	movs r0, 0x1
	movs r1, 0
	movs r2, 0
	movs r3, 0xB0
	bl sub_800792C
	str r4, [sp]
	movs r0, 0x1
	movs r1, 0
	movs r2, 0x27
	movs r3, 0xB0
	bl sub_800792C
	str r4, [sp]
	movs r0, 0x1
	movs r1, 0
	movs r2, 0
	movs r3, 0x28
	bl sub_8007A78
	str r4, [sp]
	movs r0, 0x1
	movs r1, 0xAF
	movs r2, 0
	movs r3, 0x28
	bl sub_8007A78
_08015CB2:
	ldr r0, _08015CC8
	ldr r0, [r0]
	ldr r0, [r0]
	cmp r0, 0x5
	bhi _08015D50
	lsls r0, 2
	ldr r1, _08015CCC
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08015CC8: .4byte gUnknown_203B1FC
_08015CCC: .4byte _08015CD0
	.align 2, 0
_08015CD0:
	.4byte _08015CE8
	.4byte _08015D18
	.4byte _08015CF8
	.4byte _08015D08
	.4byte _08015D28
	.4byte _08015D40
_08015CE8:
	ldr r2, _08015CF4
	movs r0, 0
	str r0, [sp]
	movs r0, 0x8
	movs r1, 0x5
	b _08015D32
	.align 2, 0
_08015CF4: .4byte gUnknown_80DB5C0
_08015CF8:
	ldr r2, _08015D04
	movs r0, 0
	str r0, [sp]
	movs r0, 0x8
	movs r1, 0x5
	b _08015D32
	.align 2, 0
_08015D04: .4byte gUnknown_80DB5D4
_08015D08:
	ldr r2, _08015D14
	movs r0, 0
	str r0, [sp]
	movs r0, 0x8
	movs r1, 0x5
	b _08015D32
	.align 2, 0
_08015D14: .4byte gUnknown_80DB5F8
_08015D18:
	ldr r2, _08015D24
	movs r0, 0
	str r0, [sp]
	movs r0, 0x8
	movs r1, 0x5
	b _08015D32
	.align 2, 0
_08015D24: .4byte gUnknown_80DB61C
_08015D28:
	ldr r2, _08015D3C
	movs r0, 0
	str r0, [sp]
	movs r0, 0x36
	movs r1, 0x2
_08015D32:
	movs r3, 0x1
	bl xxx_call_draw_string
	b _08015D50
	.align 2, 0
_08015D3C: .4byte gUnknown_80DB638
_08015D40:
	ldr r2, _08015D64
	movs r0, 0
	str r0, [sp]
	movs r0, 0x30
	movs r1, 0x4
	movs r3, 0x1
	bl xxx_call_draw_string
_08015D50:
	ldr r5, _08015D68
	ldr r0, [r5]
	ldr r1, [r0]
	cmp r1, 0x4
	beq _08015D6C
	cmp r1, 0x4
	bcc _08015D88
	cmp r1, 0x5
	beq _08015D7A
	b _08015DFE
	.align 2, 0
_08015D64: .4byte gUnknown_80DB638
_08015D68: .4byte gUnknown_203B1FC
_08015D6C:
	adds r0, 0xF8
	ldr r0, [r0]
	movs r1, 0x1
	movs r2, 0
	bl sub_8015E10
	b _08015DFE
_08015D7A:
	adds r0, 0xF8
	ldr r0, [r0]
	movs r1, 0x1
	movs r2, 0
	bl sub_8015EB4
	b _08015DFE
_08015D88:
	bl sub_8016028
	adds r3, r0, 0
	movs r0, 0x4
	str r0, [sp]
	movs r0, 0x1
	movs r1, 0x26
	movs r2, 0x21
	bl sub_80078A4
	ldr r1, [r5]
	adds r0, r1, 0
	adds r0, 0xF8
	ldr r0, [r0]
	ldrb r1, [r1, 0x1B]
	bl sub_8015FEC
	adds r4, r0, 0
	bl sub_8016028
	cmp r4, r0
	ble _08015DC0
	ldr r1, _08015DBC
	ldr r0, [r5]
	b _08015DD0
	.align 2, 0
_08015DBC: .4byte gUnknown_80DB654
_08015DC0:
	bl sub_8015F44
	ldr r2, [r5]
	ldrb r1, [r2, 0x1B]
	cmp r0, r1
	bne _08015DE0
	ldr r1, _08015DDC
	adds r0, r2, 0
_08015DD0:
	adds r0, 0xF8
	ldr r2, [r0]
	add r0, sp, 0x4
	bl sub_800D158
	b _08015DEE
	.align 2, 0
_08015DDC: .4byte gUnknown_80DB65C
_08015DE0:
	ldr r1, _08015E0C
	adds r0, r2, 0
	adds r0, 0xF8
	ldr r2, [r0]
	add r0, sp, 0x4
	bl sub_800D158
_08015DEE:
	movs r0, 0
	str r0, [sp]
	movs r0, 0x26
	movs r1, 0x16
	add r2, sp, 0x4
	movs r3, 0x1
	bl xxx_call_draw_string
_08015DFE:
	movs r0, 0x1
	bl sub_80073E0
	add sp, 0x54
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_08015E0C: .4byte gUnknown_80DB664
	thumb_func_end sub_8015C1C

	thumb_func_start sub_8015E10
sub_8015E10:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0x4
	mov r8, r0
	adds r7, r1, 0
	lsls r2, 16
	asrs r6, r2, 16
	ldr r5, _08015EB0
	movs r4, 0x35
_08015E24:
	movs r0, 0
	ldrsh r1, [r5, r0]
	movs r0, 0x2
	ldrsh r2, [r5, r0]
	adds r0, r6, 0
	adds r0, 0xB
	adds r2, r0
	movs r0, 0x5
	str r0, [sp]
	adds r0, r7, 0
	movs r3, 0xB
	bl sub_80078A4
	adds r5, 0x4
	subs r4, 0x1
	cmp r4, 0
	bge _08015E24
	movs r4, 0
	mov r1, r8
	ldrb r0, [r1]
	cmp r0, 0
	beq _08015EA4
	mov r5, r8
_08015E52:
	movs r3, 0x7
	cmp r4, 0x4
	ble _08015E7E
	movs r3, 0x6
	cmp r4, 0xC
	ble _08015E7E
	movs r3, 0x7
	cmp r4, 0x11
	ble _08015E7E
	cmp r4, 0x16
	ble _08015E7E
	movs r3, 0x6
	cmp r4, 0x1E
	ble _08015E7E
	movs r3, 0x7
	cmp r4, 0x23
	ble _08015E7E
	cmp r4, 0x28
	ble _08015E7E
	cmp r4, 0x30
	bgt _08015E7E
	movs r3, 0x6
_08015E7E:
	ldr r0, _08015EB0
	lsls r1, r4, 2
	adds r1, r0
	movs r2, 0
	ldrsh r0, [r1, r2]
	movs r2, 0x2
	ldrsh r1, [r1, r2]
	adds r1, r6
	ldrb r2, [r5]
	str r7, [sp]
	bl sub_8012C60
	adds r5, 0x1
	adds r4, 0x1
	cmp r4, 0x35
	bgt _08015EA4
	ldrb r0, [r5]
	cmp r0, 0
	bne _08015E52
_08015EA4:
	add sp, 0x4
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_08015EB0: .4byte gUnknown_80DAFC0
	thumb_func_end sub_8015E10

	thumb_func_start sub_8015EB4
sub_8015EB4:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0x4
	mov r8, r0
	adds r7, r1, 0
	lsls r2, 16
	asrs r6, r2, 16
	ldr r5, _08015F40
	movs r4, 0x17
_08015EC8:
	movs r0, 0
	ldrsh r1, [r5, r0]
	movs r0, 0x2
	ldrsh r2, [r5, r0]
	adds r0, r6, 0
	adds r0, 0xB
	adds r2, r0
	movs r0, 0x5
	str r0, [sp]
	adds r0, r7, 0
	movs r3, 0xC
	bl sub_80078A4
	adds r5, 0x4
	subs r4, 0x1
	cmp r4, 0
	bge _08015EC8
	movs r4, 0
	mov r1, r8
	ldrb r0, [r1]
	cmp r0, 0
	beq _08015F34
	mov r5, r8
_08015EF6:
	movs r3, 0x7
	cmp r4, 0x3
	ble _08015F0E
	movs r3, 0x6
	cmp r4, 0x7
	ble _08015F0E
	movs r3, 0x7
	cmp r4, 0xF
	ble _08015F0E
	cmp r4, 0x13
	bgt _08015F0E
	movs r3, 0x6
_08015F0E:
	ldr r0, _08015F40
	lsls r1, r4, 2
	adds r1, r0
	movs r2, 0
	ldrsh r0, [r1, r2]
	movs r2, 0x2
	ldrsh r1, [r1, r2]
	adds r1, r6
	ldrb r2, [r5]
	str r7, [sp]
	bl sub_8012C60
	adds r5, 0x1
	adds r4, 0x1
	cmp r4, 0x17
	bgt _08015F34
	ldrb r0, [r5]
	cmp r0, 0
	bne _08015EF6
_08015F34:
	add sp, 0x4
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_08015F40: .4byte gUnknown_80DB098
	thumb_func_end sub_8015EB4

	thumb_func_start sub_8015F44
sub_8015F44:
	push {r4,lr}
	movs r2, 0
	ldr r0, _08015F78
	ldr r0, [r0]
	ldrb r4, [r0, 0x1B]
	cmp r2, r4
	bge _08015F7C
	adds r3, r0, 0
	adds r3, 0xF8
	ldr r0, [r3]
	ldrb r0, [r0]
	cmp r0, 0
	beq _08015F7C
	movs r2, 0x1
	movs r1, 0x1
_08015F62:
	cmp r1, r4
	bge _08015F7C
	ldr r0, [r3]
	adds r0, r1
	ldrb r0, [r0]
	cmp r0, 0
	beq _08015F7C
	adds r2, r1, 0x1
	adds r1, r2, 0
	b _08015F62
	.align 2, 0
_08015F78: .4byte gUnknown_203B1FC
_08015F7C:
	adds r0, r2, 0
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_8015F44

	thumb_func_start sub_8015F84
sub_8015F84:
	push {r4-r7,lr}
	movs r6, 0
	movs r5, 0
	ldr r3, _08015FBC
	ldr r0, [r3]
	ldrb r0, [r0, 0x1B]
	cmp r5, r0
	bge _08015FE4
	adds r7, r3, 0
_08015F96:
	ldr r1, [r7]
	lsls r4, r5, 1
	adds r0, r1, 0
	adds r0, 0x1E
	adds r0, r4
	strh r6, [r0]
	adds r0, r1, 0
	adds r0, 0xF8
	ldr r0, [r0]
	adds r2, r0, r5
	ldrb r0, [r2]
	cmp r0, 0
	bne _08015FC0
	adds r0, r1, 0
	adds r0, 0x8A
	adds r0, r4
	movs r1, 0x8
	strh r1, [r0]
	b _08015FE4
	.align 2, 0
_08015FBC: .4byte gUnknown_203B1FC
_08015FC0:
	ldrb r0, [r2]
	bl sub_8092288
	bl sub_8008584
	ldr r3, [r7]
	adds r1, r3, 0
	adds r1, 0x8A
	adds r1, r4
	ldrh r2, [r0, 0x6]
	strh r2, [r1]
	movs r1, 0x6
	ldrsh r0, [r0, r1]
	adds r6, r0
	adds r5, 0x1
	ldrb r3, [r3, 0x1B]
	cmp r5, r3
	blt _08015F96
_08015FE4:
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_8015F84

	thumb_func_start sub_8015FEC
sub_8015FEC:
	push {r4-r7,lr}
	adds r2, r0, 0
	adds r5, r1, 0
	movs r7, 0
	movs r6, 0
	cmp r7, r5
	bge _08016020
	ldrb r0, [r2]
	cmp r0, 0
	beq _08016020
	adds r4, r2, 0
_08016002:
	ldrb r0, [r4]
	bl sub_8092288
	bl sub_8008584
	movs r1, 0x6
	ldrsh r0, [r0, r1]
	adds r7, r0
	adds r4, 0x1
	adds r6, 0x1
	cmp r6, r5
	bge _08016020
	ldrb r0, [r4]
	cmp r0, 0
	bne _08016002
_08016020:
	adds r0, r7, 0
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_8015FEC

	thumb_func_start sub_8016028
sub_8016028:
	movs r0, 0x3C
	bx lr
	thumb_func_end sub_8016028

	thumb_func_start sub_801602C
sub_801602C:
	push {r4-r6,lr}
	adds r6, r0, 0
	adds r5, r1, 0
	bl sub_8004914
	movs r0, 0
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	ldr r4, _08016064
	movs r0, 0x50
	movs r1, 0x8
	bl MemoryAlloc
	adds r1, r0, 0
	str r1, [r4]
	str r6, [r1]
	str r5, [r1, 0x8]
	cmp r6, 0x1
	beq _0801606E
	cmp r6, 0x1
	bcc _08016068
	cmp r6, 0x2
	beq _0801606E
	cmp r6, 0x3
	beq _0801606E
	b _08016070
	.align 2, 0
_08016064: .4byte gUnknown_203B200
_08016068:
	movs r0, 0
	str r0, [r1, 0x4]
	b _08016070
_0801606E:
	str r6, [r1, 0x4]
_08016070:
	movs r0, 0
	bl sub_80160F4
	movs r0, 0x1
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end sub_801602C

	thumb_func_start sub_8016080
sub_8016080:
	push {lr}
	ldr r0, _08016098
	ldr r0, [r0]
	ldr r0, [r0, 0xC]
	cmp r0, 0x4
	bhi _080160D0
	lsls r0, 2
	ldr r1, _0801609C
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08016098: .4byte gUnknown_203B200
_0801609C: .4byte _080160A0
	.align 2, 0
_080160A0:
	.4byte _080160B4
	.4byte _080160BA
	.4byte _080160C0
	.4byte _080160C6
	.4byte _080160CC
_080160B4:
	bl sub_80161F8
	b _080160D0
_080160BA:
	bl sub_8016248
	b _080160D0
_080160C0:
	bl sub_8016280
	b _080160D0
_080160C6:
	bl sub_801629C
	b _080160D0
_080160CC:
	movs r0, 0x3
	b _080160D2
_080160D0:
	movs r0, 0
_080160D2:
	pop {r1}
	bx r1
	thumb_func_end sub_8016080

	thumb_func_start sub_80160D8
sub_80160D8:
	push {r4,lr}
	ldr r4, _080160F0
	ldr r0, [r4]
	cmp r0, 0
	beq _080160EA
	bl MemoryFree
	movs r0, 0
	str r0, [r4]
_080160EA:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080160F0: .4byte gUnknown_203B200
	thumb_func_end sub_80160D8

	thumb_func_start sub_80160F4
sub_80160F4:
	push {lr}
	ldr r1, _08016108
	ldr r1, [r1]
	str r0, [r1, 0xC]
	bl nullsub_36
	bl sub_8016110
	pop {r0}
	bx r0
	.align 2, 0
_08016108: .4byte gUnknown_203B200
	thumb_func_end sub_80160F4

	thumb_func_start nullsub_36
nullsub_36:
	bx lr
	thumb_func_end nullsub_36

	thumb_func_start sub_8016110
sub_8016110:
	push {r4,lr}
	sub sp, 0x14
	ldr r4, _08016128
	ldr r1, [r4]
	ldr r0, [r1, 0xC]
	cmp r0, 0x1
	beq _08016140
	cmp r0, 0x1
	bgt _0801612C
	cmp r0, 0
	beq _08016136
	b _080161B8
	.align 2, 0
_08016128: .4byte gUnknown_203B200
_0801612C:
	cmp r0, 0x2
	beq _08016194
	cmp r0, 0x3
	beq _080161AC
	b _080161B8
_08016136:
	ldr r0, [r1, 0x4]
	ldr r1, [r1, 0x8]
	bl sub_80151C0
	b _080161B8
_08016140:
	bl sub_80161C8
	ldr r1, [r4]
	ldr r0, [r1, 0x4]
	cmp r0, 0x1
	bne _0801615C
	ldr r0, _08016158
	ldr r1, [r1, 0x8]
	movs r2, 0xA
	bl sub_80922B4
	b _08016166
	.align 2, 0
_08016158: .4byte gUnknown_202DF98
_0801615C:
	ldr r0, _08016188
	ldr r1, [r1, 0x8]
	movs r2, 0xA
	bl sub_80922B4
_08016166:
	ldr r0, _0801618C
	ldr r1, _08016190
	ldr r3, [r1]
	adds r3, 0x10
	movs r2, 0
	str r2, [sp]
	movs r1, 0x4
	str r1, [sp, 0x4]
	str r2, [sp, 0x8]
	str r2, [sp, 0xC]
	movs r1, 0x20
	str r1, [sp, 0x10]
	movs r1, 0
	movs r2, 0x3
	bl sub_8014248
	b _080161B8
	.align 2, 0
_08016188: .4byte gUnknown_202DF98
_0801618C: .4byte gUnknown_80DB688
_08016190: .4byte gUnknown_203B200
_08016194:
	ldr r0, _080161A4
	ldr r3, _080161A8
	movs r1, 0
	movs r2, 0
	bl sub_80141B4
	b _080161B8
	.align 2, 0
_080161A4: .4byte gUnknown_80DB6A4
_080161A8: .4byte 0x00000121
_080161AC:
	ldr r0, _080161C0
	ldr r3, _080161C4
	movs r1, 0
	movs r2, 0
	bl sub_80141B4
_080161B8:
	add sp, 0x14
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080161C0: .4byte gUnknown_80DB6BC
_080161C4: .4byte 0x00000121
	thumb_func_end sub_8016110

	thumb_func_start sub_80161C8
sub_80161C8:
	ldr r0, _080161EC
	ldr r1, [r0]
	ldr r0, _080161F0
	ldr r0, [r0]
	str r0, [r1, 0x10]
	movs r0, 0x2
	str r0, [r1, 0x14]
	ldr r0, _080161F4
	ldr r0, [r0]
	str r0, [r1, 0x18]
	movs r0, 0x3
	str r0, [r1, 0x1C]
	movs r0, 0
	str r0, [r1, 0x20]
	movs r0, 0x1
	str r0, [r1, 0x24]
	bx lr
	.align 2, 0
_080161EC: .4byte gUnknown_203B200
_080161F0: .4byte gUnknown_80D4920
_080161F4: .4byte gUnknown_80D4928
	thumb_func_end sub_80161C8

	thumb_func_start sub_80161F8
sub_80161F8:
	push {r4,lr}
	bl sub_80154F0
	cmp r0, 0x3
	bne _08016242
	bl sub_80155F0
	bl sub_80162B8
	lsls r0, 24
	cmp r0, 0
	beq _08016218
	movs r0, 0x3
	bl sub_80160F4
	b _08016242
_08016218:
	ldr r0, _08016238
	ldr r0, [r0]
	ldr r0, [r0, 0x8]
	movs r1, 0xA
	bl sub_8015FEC
	adds r4, r0, 0
	bl sub_8016028
	cmp r4, r0
	ble _0801623C
	movs r0, 0x2
	bl sub_80160F4
	b _08016242
	.align 2, 0
_08016238: .4byte gUnknown_203B200
_0801623C:
	movs r0, 0x1
	bl sub_80160F4
_08016242:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_80161F8

	thumb_func_start sub_8016248
sub_8016248:
	push {lr}
	sub sp, 0x4
	mov r0, sp
	bl sub_80144A4
	cmp r0, 0
	bne _0801627A
	ldr r0, [sp]
	cmp r0, 0x2
	beq _0801626C
	cmp r0, 0x2
	bgt _08016266
	cmp r0, 0x1
	beq _08016274
	b _0801627A
_08016266:
	cmp r0, 0x3
	beq _08016274
	b _0801627A
_0801626C:
	movs r0, 0x4
	bl sub_80160F4
	b _0801627A
_08016274:
	movs r0, 0
	bl sub_80160F4
_0801627A:
	add sp, 0x4
	pop {r0}
	bx r0
	thumb_func_end sub_8016248

	thumb_func_start sub_8016280
sub_8016280:
	push {lr}
	sub sp, 0x4
	mov r0, sp
	bl sub_80144A4
	cmp r0, 0
	bne _08016294
	movs r0, 0
	bl sub_80160F4
_08016294:
	add sp, 0x4
	pop {r0}
	bx r0
	thumb_func_end sub_8016280

	thumb_func_start sub_801629C
sub_801629C:
	push {lr}
	sub sp, 0x4
	mov r0, sp
	bl sub_80144A4
	cmp r0, 0
	bne _080162B0
	movs r0, 0
	bl sub_80160F4
_080162B0:
	add sp, 0x4
	pop {r0}
	bx r0
	thumb_func_end sub_801629C

	thumb_func_start sub_80162B8
sub_80162B8:
	push {lr}
	movs r3, 0xA
	movs r1, 0
	ldr r0, _080162D4
	ldr r0, [r0]
	ldr r2, [r0, 0x8]
_080162C4:
	adds r0, r2, r1
	ldrb r0, [r0]
	cmp r0, 0
	beq _080162DE
	cmp r0, 0x20
	beq _080162D8
	movs r0, 0
	b _080162E0
	.align 2, 0
_080162D4: .4byte gUnknown_203B200
_080162D8:
	adds r1, 0x1
	cmp r1, r3
	blt _080162C4
_080162DE:
	movs r0, 0x1
_080162E0:
	pop {r1}
	bx r1
	thumb_func_end sub_80162B8

	thumb_func_start sub_80162E4
sub_80162E4:
	push {r4-r6,lr}
	adds r4, r0, 0
	bl sub_8004914
	movs r0, 0
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	ldr r5, _0801633C
	movs r0, 0x84
	lsls r0, 1
	movs r1, 0x8
	bl MemoryAlloc
	str r0, [r5]
	movs r6, 0
	str r6, [r0, 0x10]
	str r4, [r0]
	ldr r0, _08016340
	movs r1, 0x35
	bl sub_808D8E0
	ldr r4, _08016344
	adds r0, r4, 0
	movs r1, 0x35
	bl sub_808D8E0
	movs r0, 0x35
	bl sub_808D994
	adds r1, r0, 0
	subs r4, 0x50
	adds r0, r4, 0
	bl strcpy
	ldr r5, [r5]
	ldr r0, [r5]
	cmp r0, 0x1
	bne _08016348
	adds r0, r5, 0
	adds r0, 0xA4
	str r6, [r0]
	b _08016352
	.align 2, 0
_0801633C: .4byte gUnknown_203B204
_08016340: .4byte gUnknown_202E5D8
_08016344: .4byte gUnknown_202E1C8
_08016348:
	adds r1, r5, 0
	adds r1, 0xA4
	adds r0, r5, 0
	adds r0, 0x94
	str r0, [r1]
_08016352:
	movs r0, 0x35
	bl sub_808DDD0
	ldr r2, _0801639C
	ldr r3, [r2]
	adds r1, r3, 0
	adds r1, 0x94
	str r0, [r1]
	adds r1, 0x4
	ldr r0, [r0, 0x4]
	str r0, [r1]
	adds r0, r3, 0
	adds r0, 0xA0
	movs r1, 0
	strb r1, [r0]
	ldr r0, [r2]
	adds r0, 0xA1
	strb r1, [r0]
	ldr r0, [r2]
	adds r0, 0xA2
	strb r1, [r0]
	ldr r1, [r2]
	adds r2, r1, 0
	adds r2, 0x9C
	movs r0, 0x2
	strh r0, [r2]
	adds r1, 0x9E
	movs r0, 0x8
	strh r0, [r1]
	movs r0, 0
	bl sub_8016444
	movs r0, 0x1
	pop {r4-r6}
	pop {r1}
	bx r1
	.align 2, 0
_0801639C: .4byte gUnknown_203B204
	thumb_func_end sub_80162E4

	thumb_func_start sub_80163A0
sub_80163A0:
	push {lr}
	ldr r0, _080163B8
	ldr r0, [r0]
	ldr r0, [r0, 0x4]
	cmp r0, 0xC
	bhi _08016410
	lsls r0, 2
	ldr r1, _080163BC
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080163B8: .4byte gUnknown_203B204
_080163BC: .4byte _080163C0
	.align 2, 0
_080163C0:
	.4byte _08016410
	.4byte _080163F4
	.4byte _080163FA
	.4byte _08016410
	.4byte _08016410
	.4byte _08016410
	.4byte _0801640C
	.4byte _08016410
	.4byte _08016400
	.4byte _08016410
	.4byte _08016410
	.4byte _08016406
	.4byte _08016410
_080163F4:
	bl sub_8016B24
	b _08016414
_080163FA:
	bl sub_80169BC
	b _08016414
_08016400:
	bl sub_8016A18
	b _08016414
_08016406:
	bl sub_8016A8C
	b _08016414
_0801640C:
	movs r0, 0x3
	b _08016416
_08016410:
	bl sub_8016B00
_08016414:
	movs r0, 0
_08016416:
	pop {r1}
	bx r1
	thumb_func_end sub_80163A0

	thumb_func_start sub_801641C
sub_801641C:
	push {r4,lr}
	ldr r4, _08016440
	ldr r0, [r4]
	cmp r0, 0
	beq _08016438
	adds r0, 0x94
	ldr r0, [r0]
	bl CloseFile
	ldr r0, [r4]
	bl MemoryFree
	movs r0, 0
	str r0, [r4]
_08016438:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08016440: .4byte gUnknown_203B204
	thumb_func_end sub_801641C

	thumb_func_start sub_8016444
sub_8016444:
	push {lr}
	ldr r1, _08016458
	ldr r1, [r1]
	str r0, [r1, 0x4]
	bl sub_801645C
	bl sub_801653C
	pop {r0}
	bx r0
	.align 2, 0
_08016458: .4byte gUnknown_203B204
	thumb_func_end sub_8016444

	thumb_func_start sub_801645C
sub_801645C:
	push {r4-r7,lr}
	ldr r4, _0801647C
	ldr r0, [r4]
	adds r0, 0xA8
	bl sub_8006518
	ldr r0, [r4]
	ldr r1, [r0, 0x4]
	cmp r1, 0x8
	beq _080164AC
	cmp r1, 0x8
	bgt _08016480
	cmp r1, 0x2
	beq _08016486
	b _080164F8
	.align 2, 0
_0801647C: .4byte gUnknown_203B204
_08016480:
	cmp r1, 0xB
	beq _080164AC
	b _080164F8
_08016486:
	adds r0, 0xA8
	movs r1, 0x80
	strb r1, [r0]
	ldr r0, [r4]
	adds r0, 0xC0
	strb r1, [r0]
	ldr r0, [r4]
	adds r0, 0xD8
	strb r1, [r0]
	ldr r1, [r4]
	adds r1, 0xF0
	ldr r0, _080164A8
	ldm r0!, {r2,r3,r5}
	stm r1!, {r2,r3,r5}
	ldm r0!, {r2,r6,r7}
	stm r1!, {r2,r6,r7}
	b _080164D8
	.align 2, 0
_080164A8: .4byte gUnknown_80DB6F4
_080164AC:
	ldr r4, _080164EC
	ldr r0, [r4]
	adds r0, 0xA8
	movs r1, 0x80
	strb r1, [r0]
	ldr r0, [r4]
	adds r0, 0xC0
	strb r1, [r0]
	ldr r1, [r4]
	adds r1, 0xF0
	ldr r0, _080164F0
	ldm r0!, {r3,r5,r6}
	stm r1!, {r3,r5,r6}
	ldm r0!, {r2,r3,r7}
	stm r1!, {r2,r3,r7}
	ldr r1, [r4]
	adds r1, 0xD8
	ldr r0, _080164F4
	ldm r0!, {r5-r7}
	stm r1!, {r5-r7}
	ldm r0!, {r2,r3,r5}
	stm r1!, {r2,r3,r5}
_080164D8:
	bl sub_8004914
	ldr r0, [r4]
	adds r0, 0xA8
	movs r1, 0x1
	movs r2, 0
	bl sub_800641C
	b _0801652E
	.align 2, 0
_080164EC: .4byte gUnknown_203B204
_080164F0: .4byte gUnknown_80DB6F4
_080164F4: .4byte gUnknown_80DB70C
_080164F8:
	ldr r6, _08016534
	mov r12, r6
	ldr r4, _08016538
	movs r3, 0
	movs r2, 0x3
_08016502:
	mov r7, r12
	ldr r1, [r7]
	adds r1, r3
	adds r1, 0xA8
	adds r0, r4, 0
	ldm r0!, {r5-r7}
	stm r1!, {r5-r7}
	ldm r0!, {r5-r7}
	stm r1!, {r5-r7}
	adds r3, 0x18
	subs r2, 0x1
	cmp r2, 0
	bge _08016502
	bl sub_8004914
	ldr r0, _08016534
	ldr r0, [r0]
	adds r0, 0xA8
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
_0801652E:
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_08016534: .4byte gUnknown_203B204
_08016538: .4byte gUnknown_80DB6DC
	thumb_func_end sub_801645C

	thumb_func_start sub_801653C
sub_801653C:
	push {r4,r5,lr}
	sub sp, 0x14
	ldr r1, _08016558
	ldr r0, [r1]
	ldr r0, [r0, 0x4]
	adds r2, r1, 0
	cmp r0, 0xC
	bls _0801654E
	b _080168EC
_0801654E:
	lsls r0, 2
	ldr r1, _0801655C
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08016558: .4byte gUnknown_203B204
_0801655C: .4byte _08016560
	.align 2, 0
_08016560:
	.4byte _08016594
	.4byte _080165B4
	.4byte _080168B2
	.4byte _08016650
	.4byte _08016668
	.4byte _080166C4
	.4byte _080168EC
	.4byte _080166DC
	.4byte _0801674C
	.4byte _080167A8
	.4byte _080167CC
	.4byte _0801685C
	.4byte _080168C4
_08016594:
	ldr r2, [r2]
	movs r0, 0x1
	str r0, [r2, 0x8]
	ldr r3, _080165B0
	ldr r1, [r2]
	lsls r0, r1, 4
	subs r0, r1
	lsls r0, 2
	adds r0, r3
	ldr r0, [r0]
	adds r2, 0xA4
	ldr r2, [r2]
	b _08016844
	.align 2, 0
_080165B0: .4byte gUnknown_80D49E0
_080165B4:
	bl sub_8016900
	ldr r0, _080165FC
	ldr r0, [r0]
	mov r12, r0
	movs r0, 0x2
	mov r1, r12
	str r0, [r1, 0x8]
	ldr r0, _08016600
	ldr r0, [r0]
	movs r3, 0x99
	lsls r3, 2
	adds r0, r3
	ldr r4, [r0]
	cmp r4, 0
	bne _08016608
	ldr r2, _08016604
	ldr r1, [r1]
	lsls r0, r1, 4
	subs r0, r1
	lsls r0, 2
	adds r2, 0x4
	adds r0, r2
	ldr r0, [r0]
	mov r5, r12
	ldr r2, [r5, 0x10]
	mov r3, r12
	adds r3, 0x14
	mov r1, r12
	adds r1, 0x54
	str r1, [sp]
	movs r1, 0x4
	str r1, [sp, 0x4]
	str r4, [sp, 0x8]
	b _08016632
	.align 2, 0
_080165FC: .4byte gUnknown_203B204
_08016600: .4byte gUnknown_203B460
_08016604: .4byte gUnknown_80D49E0
_08016608:
	ldr r0, _08016648
	str r4, [r0]
	ldr r2, _0801664C
	mov r0, r12
	ldr r1, [r0]
	lsls r0, r1, 4
	subs r0, r1
	lsls r0, 2
	adds r2, 0x8
	adds r0, r2
	ldr r0, [r0]
	mov r1, r12
	ldr r2, [r1, 0x10]
	mov r3, r12
	adds r3, 0x14
	adds r1, 0x54
	str r1, [sp]
	movs r1, 0x4
	str r1, [sp, 0x4]
	movs r1, 0
	str r1, [sp, 0x8]
_08016632:
	mov r1, r12
	adds r1, 0xA4
	ldr r1, [r1]
	str r1, [sp, 0xC]
	movs r1, 0xC
	str r1, [sp, 0x10]
	movs r1, 0
	bl sub_8014248
	b _080168EC
	.align 2, 0
_08016648: .4byte gUnknown_202DE30
_0801664C: .4byte gUnknown_80D49E0
_08016650:
	ldr r3, [r2]
	movs r0, 0x1
	str r0, [r3, 0x8]
	ldr r2, _08016664
	ldr r1, [r3]
	lsls r0, r1, 4
	subs r0, r1
	lsls r0, 2
	adds r2, 0x38
	b _0801683C
	.align 2, 0
_08016664: .4byte gUnknown_80D49E0
_08016668:
	ldr r3, [r2]
	movs r0, 0x6
	str r0, [r3, 0x8]
	ldr r0, _08016698
	ldr r0, [r0]
	movs r5, 0x99
	lsls r5, 2
	adds r0, r5
	ldr r1, [r0]
	cmp r1, 0
	bne _080166A0
	ldr r2, _0801669C
	ldr r1, [r3]
	lsls r0, r1, 4
	subs r0, r1
	lsls r0, 2
	adds r2, 0x10
	adds r0, r2
	ldr r0, [r0]
	adds r1, r3, 0
	adds r1, 0xA4
	ldr r2, [r1]
	b _08016844
	.align 2, 0
_08016698: .4byte gUnknown_203B460
_0801669C: .4byte gUnknown_80D49E0
_080166A0:
	ldr r0, _080166BC
	str r1, [r0]
	ldr r2, _080166C0
	ldr r1, [r3]
	lsls r0, r1, 4
	subs r0, r1
	lsls r0, 2
	adds r2, 0x14
	adds r0, r2
	ldr r0, [r0]
	adds r1, r3, 0
	adds r1, 0xA4
	ldr r2, [r1]
	b _08016844
	.align 2, 0
_080166BC: .4byte gUnknown_202DE30
_080166C0: .4byte gUnknown_80D49E0
_080166C4:
	ldr r3, [r2]
	movs r0, 0x1
	str r0, [r3, 0x8]
	ldr r2, _080166D8
	ldr r1, [r3]
	lsls r0, r1, 4
	subs r0, r1
	lsls r0, 2
	adds r2, 0xC
	b _0801683C
	.align 2, 0
_080166D8: .4byte gUnknown_80D49E0
_080166DC:
	ldr r0, _08016700
	ldr r1, [r0]
	movs r3, 0x98
	lsls r3, 2
	adds r0, r1, r3
	ldr r0, [r0]
	cmp r0, 0
	bne _08016708
	ldr r3, [r2]
	movs r0, 0x1
	str r0, [r3, 0x8]
	ldr r2, _08016704
	ldr r1, [r3]
	lsls r0, r1, 4
	subs r0, r1
	lsls r0, 2
	adds r2, 0x1C
	b _0801683C
	.align 2, 0
_08016700: .4byte gUnknown_203B460
_08016704: .4byte gUnknown_80D49E0
_08016708:
	movs r5, 0x99
	lsls r5, 2
	adds r0, r1, r5
	ldr r1, [r0]
	ldr r0, _0801672C
	cmp r1, r0
	ble _08016734
	ldr r3, [r2]
	movs r0, 0x1
	str r0, [r3, 0x8]
	ldr r2, _08016730
	ldr r1, [r3]
	lsls r0, r1, 4
	subs r0, r1
	lsls r0, 2
	adds r2, 0x20
	b _0801683C
	.align 2, 0
_0801672C: .4byte 0x0098967e
_08016730: .4byte gUnknown_80D49E0
_08016734:
	ldr r3, [r2]
	movs r0, 0x8
	str r0, [r3, 0x8]
	ldr r2, _08016748
	ldr r1, [r3]
	lsls r0, r1, 4
	subs r0, r1
	lsls r0, 2
	adds r2, 0x18
	b _0801683C
	.align 2, 0
_08016748: .4byte gUnknown_80D49E0
_0801674C:
	ldr r4, [r2]
	ldr r0, _080167A0
	ldr r3, [r0]
	movs r1, 0x99
	lsls r1, 2
	adds r0, r3, r1
	ldr r1, [r0]
	ldr r0, _080167A4
	subs r0, r1
	str r0, [r4, 0x70]
	movs r5, 0x98
	lsls r5, 2
	adds r1, r3, r5
	ldr r1, [r1]
	cmp r0, r1
	ble _0801676E
	str r1, [r4, 0x70]
_0801676E:
	ldr r2, [r2]
	ldr r0, [r2, 0x70]
	str r0, [r2, 0x68]
	movs r0, 0x1
	str r0, [r2, 0x6C]
	movs r0, 0x5
	str r0, [r2, 0x74]
	movs r0, 0x2
	str r0, [r2, 0x78]
	adds r0, r2, 0
	adds r0, 0xD8
	str r0, [r2, 0x7C]
	adds r1, r2, 0
	adds r1, 0x80
	movs r0, 0x50
	str r0, [r1]
	adds r1, 0x4
	movs r0, 0x12
	str r0, [r1]
	adds r0, r2, 0
	adds r0, 0x64
	bl sub_8013AA0
	movs r0, 0x1
	b _080168AE
	.align 2, 0
_080167A0: .4byte gUnknown_203B460
_080167A4: .4byte 0x0098967f
_080167A8:
	ldr r3, [r2]
	movs r0, 0x1
	str r0, [r3, 0x8]
	ldr r1, _080167C4
	ldr r0, [r3, 0xC]
	str r0, [r1]
	ldr r2, _080167C8
	ldr r1, [r3]
	lsls r0, r1, 4
	subs r0, r1
	lsls r0, 2
	adds r2, 0x24
	b _0801683C
	.align 2, 0
_080167C4: .4byte gUnknown_202DE30
_080167C8: .4byte gUnknown_80D49E0
_080167CC:
	ldr r0, _080167F4
	ldr r3, [r0]
	movs r1, 0x98
	lsls r1, 2
	adds r0, r3, r1
	ldr r1, [r0]
	ldr r0, _080167F8
	cmp r1, r0
	ble _08016800
	ldr r3, [r2]
	movs r0, 0x1
	str r0, [r3, 0x8]
	ldr r2, _080167FC
	ldr r1, [r3]
	lsls r0, r1, 4
	subs r0, r1
	lsls r0, 2
	adds r2, 0x30
	b _0801683C
	.align 2, 0
_080167F4: .4byte gUnknown_203B460
_080167F8: .4byte 0x0001869e
_080167FC: .4byte gUnknown_80D49E0
_08016800:
	movs r5, 0x99
	lsls r5, 2
	adds r4, r3, r5
	ldr r0, [r4]
	cmp r0, 0
	bne _08016824
	ldr r3, [r2]
	movs r0, 0x1
	str r0, [r3, 0x8]
	ldr r2, _08016820
	ldr r1, [r3]
	lsls r0, r1, 4
	subs r0, r1
	lsls r0, 2
	adds r2, 0x2C
	b _0801683C
	.align 2, 0
_08016820: .4byte gUnknown_80D49E0
_08016824:
	ldr r3, [r2]
	movs r0, 0xB
	str r0, [r3, 0x8]
	ldr r1, _08016850
	ldr r0, [r4]
	str r0, [r1]
	ldr r2, _08016854
	ldr r1, [r3]
	lsls r0, r1, 4
	subs r0, r1
	lsls r0, 2
	adds r2, 0x28
_0801683C:
	adds r0, r2
	ldr r0, [r0]
	adds r3, 0xA4
	ldr r2, [r3]
_08016844:
	ldr r3, _08016858
	movs r1, 0
	bl sub_80141B4
	b _080168EC
	.align 2, 0
_08016850: .4byte gUnknown_202DE30
_08016854: .4byte gUnknown_80D49E0
_08016858: .4byte 0x0000010d
_0801685C:
	ldr r4, [r2]
	ldr r0, _080168BC
	ldr r3, [r0]
	movs r1, 0x98
	lsls r1, 2
	adds r0, r3, r1
	ldr r1, [r0]
	ldr r0, _080168C0
	subs r0, r1
	str r0, [r4, 0x70]
	movs r5, 0x99
	lsls r5, 2
	adds r1, r3, r5
	ldr r1, [r1]
	cmp r0, r1
	ble _0801687E
	str r1, [r4, 0x70]
_0801687E:
	ldr r2, [r2]
	ldr r0, [r2, 0x70]
	str r0, [r2, 0x68]
	movs r0, 0x1
	str r0, [r2, 0x6C]
	movs r0, 0x5
	str r0, [r2, 0x74]
	movs r0, 0x2
	str r0, [r2, 0x78]
	adds r0, r2, 0
	adds r0, 0xD8
	str r0, [r2, 0x7C]
	adds r1, r2, 0
	adds r1, 0x80
	movs r0, 0x50
	str r0, [r1]
	adds r1, 0x4
	movs r0, 0x12
	str r0, [r1]
	adds r0, r2, 0
	adds r0, 0x64
	bl sub_8013AA0
	movs r0, 0
_080168AE:
	bl sub_8016B48
_080168B2:
	movs r0, 0x3
	bl sub_8016BB8
	b _080168EC
	.align 2, 0
_080168BC: .4byte gUnknown_203B460
_080168C0: .4byte 0x0001869f
_080168C4:
	ldr r3, [r2]
	movs r0, 0x1
	str r0, [r3, 0x8]
	ldr r1, _080168F4
	ldr r0, [r3, 0xC]
	str r0, [r1]
	ldr r2, _080168F8
	ldr r1, [r3]
	lsls r0, r1, 4
	subs r0, r1
	lsls r0, 2
	adds r2, 0x34
	adds r0, r2
	ldr r0, [r0]
	adds r3, 0xA4
	ldr r2, [r3]
	ldr r3, _080168FC
	movs r1, 0
	bl sub_80141B4
_080168EC:
	add sp, 0x14
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_080168F4: .4byte gUnknown_202DE30
_080168F8: .4byte gUnknown_80D49E0
_080168FC: .4byte 0x0000010d
	thumb_func_end sub_801653C

	thumb_func_start sub_8016900
sub_8016900:
	push {r4-r7,lr}
	ldr r4, _08016980
	ldr r0, [r4]
	adds r0, 0x54
	movs r1, 0
	movs r2, 0x10
	bl MemoryFill16
	ldr r3, [r4]
	movs r2, 0
	ldr r0, _08016984
	ldr r0, [r0]
	str r0, [r3, 0x14]
	movs r0, 0x2
	str r0, [r3, 0x18]
	movs r1, 0x1
	ldr r0, _08016988
	ldr r0, [r0]
	str r0, [r3, 0x1C]
	movs r0, 0x3
	str r0, [r3, 0x20]
	ldr r0, _0801698C
	ldr r0, [r0]
	str r0, [r3, 0x24]
	movs r0, 0x4
	str r0, [r3, 0x28]
	ldr r0, _08016990
	ldr r0, [r0]
	str r0, [r3, 0x2C]
	str r1, [r3, 0x30]
	movs r6, 0x4
	str r2, [r3, 0x34]
	str r1, [r3, 0x38]
	movs r5, 0
	mov r12, r3
	adds r3, 0x18
	mov r2, r12
	adds r2, 0x54
_0801694C:
	ldrh r0, [r2]
	cmp r0, 0
	bne _0801695C
	ldr r1, [r3]
	mov r7, r12
	ldr r0, [r7, 0x10]
	cmp r1, r0
	beq _080169B6
_0801695C:
	adds r3, 0x8
	adds r2, 0x2
	adds r5, 0x1
	cmp r5, r6
	blt _0801694C
	movs r5, 0
	cmp r5, r6
	bge _080169B6
	ldr r1, [r4]
	adds r0, r1, 0
	adds r0, 0x54
	ldrh r0, [r0]
	cmp r0, 0
	bne _08016994
	ldr r0, [r1, 0x18]
	str r0, [r1, 0x10]
	b _080169B6
	.align 2, 0
_08016980: .4byte gUnknown_203B204
_08016984: .4byte gUnknown_80D4958
_08016988: .4byte gUnknown_80D4964
_0801698C: .4byte gUnknown_80D4970
_08016990: .4byte gUnknown_80D4934
_08016994:
	adds r5, 0x1
	cmp r5, r6
	bge _080169B6
	ldr r2, [r4]
	lsls r0, r5, 1
	adds r1, r2, 0
	adds r1, 0x54
	adds r1, r0
	ldrh r0, [r1]
	cmp r0, 0
	bne _08016994
	lsls r0, r5, 3
	adds r1, r2, 0
	adds r1, 0x18
	adds r1, r0
	ldr r0, [r1]
	str r0, [r2, 0x10]
_080169B6:
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_8016900

	thumb_func_start sub_80169BC
sub_80169BC:
	push {lr}
	sub sp, 0x4
	mov r0, sp
	bl sub_80144A4
	cmp r0, 0
	bne _08016A10
	ldr r0, _080169E4
	ldr r1, [r0]
	ldr r0, [sp]
	str r0, [r1, 0x10]
	ldr r0, [sp]
	cmp r0, 0x2
	beq _080169F2
	cmp r0, 0x2
	bgt _080169E8
	cmp r0, 0x1
	beq _08016A0A
	b _08016A10
	.align 2, 0
_080169E4: .4byte gUnknown_203B204
_080169E8:
	cmp r0, 0x3
	beq _080169FA
	cmp r0, 0x4
	beq _08016A02
	b _08016A10
_080169F2:
	movs r0, 0x7
	bl sub_8016444
	b _08016A10
_080169FA:
	movs r0, 0xA
	bl sub_8016444
	b _08016A10
_08016A02:
	movs r0, 0x3
	bl sub_8016444
	b _08016A10
_08016A0A:
	movs r0, 0x4
	bl sub_8016444
_08016A10:
	add sp, 0x4
	pop {r0}
	bx r0
	thumb_func_end sub_80169BC

	thumb_func_start sub_8016A18
sub_8016A18:
	push {r4,lr}
	ldr r4, _08016A38
	ldr r0, [r4]
	adds r0, 0x64
	bl sub_8013BBC
	cmp r0, 0x1
	beq _08016A3C
	cmp r0, 0x1
	bcc _08016A86
	cmp r0, 0x2
	beq _08016A80
	cmp r0, 0x3
	beq _08016A44
	b _08016A86
	.align 2, 0
_08016A38: .4byte gUnknown_203B204
_08016A3C:
	movs r0, 0x1
	bl sub_8016B48
	b _08016A86
_08016A44:
	ldr r3, [r4]
	ldr r2, [r3, 0x64]
	str r2, [r3, 0xC]
	ldr r0, _08016A7C
	ldr r0, [r0]
	mov r12, r0
	movs r1, 0x99
	lsls r1, 2
	add r1, r12
	ldr r0, [r1]
	adds r0, r2
	str r0, [r1]
	movs r2, 0x98
	lsls r2, 2
	add r2, r12
	ldr r0, [r2]
	ldr r1, [r3, 0xC]
	subs r0, r1
	str r0, [r2]
	movs r0, 0xA6
	lsls r0, 1
	bl sub_8011988
	movs r0, 0x9
	bl sub_8016444
	b _08016A86
	.align 2, 0
_08016A7C: .4byte gUnknown_203B460
_08016A80:
	movs r0, 0x5
	bl sub_8016444
_08016A86:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_8016A18

	thumb_func_start sub_8016A8C
sub_8016A8C:
	push {r4,lr}
	ldr r4, _08016AAC
	ldr r0, [r4]
	adds r0, 0x64
	bl sub_8013BBC
	cmp r0, 0x1
	beq _08016AB0
	cmp r0, 0x1
	bcc _08016AFA
	cmp r0, 0x2
	beq _08016AF4
	cmp r0, 0x3
	beq _08016AB8
	b _08016AFA
	.align 2, 0
_08016AAC: .4byte gUnknown_203B204
_08016AB0:
	movs r0, 0
	bl sub_8016B48
	b _08016AFA
_08016AB8:
	ldr r3, [r4]
	ldr r2, [r3, 0x64]
	str r2, [r3, 0xC]
	ldr r0, _08016AF0
	ldr r0, [r0]
	mov r12, r0
	movs r1, 0x98
	lsls r1, 2
	add r1, r12
	ldr r0, [r1]
	adds r0, r2
	str r0, [r1]
	movs r2, 0x99
	lsls r2, 2
	add r2, r12
	ldr r0, [r2]
	ldr r1, [r3, 0xC]
	subs r0, r1
	str r0, [r2]
	movs r0, 0xA6
	lsls r0, 1
	bl sub_8011988
	movs r0, 0xC
	bl sub_8016444
	b _08016AFA
	.align 2, 0
_08016AF0: .4byte gUnknown_203B460
_08016AF4:
	movs r0, 0x5
	bl sub_8016444
_08016AFA:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_8016A8C

	thumb_func_start sub_8016B00
sub_8016B00:
	push {lr}
	sub sp, 0x4
	mov r0, sp
	bl sub_80144A4
	cmp r0, 0
	bne _08016B18
	ldr r0, _08016B20
	ldr r0, [r0]
	ldr r0, [r0, 0x8]
	bl sub_8016444
_08016B18:
	add sp, 0x4
	pop {r0}
	bx r0
	.align 2, 0
_08016B20: .4byte gUnknown_203B204
	thumb_func_end sub_8016B00

	thumb_func_start sub_8016B24
sub_8016B24:
	push {lr}
	sub sp, 0x4
	mov r0, sp
	bl sub_80144A4
	cmp r0, 0x4
	bne _08016B3C
	ldr r0, _08016B44
	ldr r0, [r0]
	ldr r0, [r0, 0x8]
	bl sub_8016444
_08016B3C:
	add sp, 0x4
	pop {r0}
	bx r0
	.align 2, 0
_08016B44: .4byte gUnknown_203B204
	thumb_func_end sub_8016B24

	thumb_func_start sub_8016B48
sub_8016B48:
	push {r4,r5,lr}
	sub sp, 0x4
	lsls r0, 24
	lsrs r5, r0, 24
	ldr r4, _08016B7C
	ldr r0, [r4]
	ldr r0, [r0, 0x78]
	bl sub_8008C54
	ldr r0, [r4]
	ldr r0, [r0, 0x78]
	bl sub_80073B8
	cmp r5, 0
	beq _08016B84
	ldr r0, _08016B80
	ldr r2, [r0]
	ldr r0, [r4]
	ldr r3, [r0, 0x78]
	movs r0, 0
	str r0, [sp]
	movs r0, 0xC
	movs r1, 0
	bl xxx_call_draw_string
	b _08016B96
	.align 2, 0
_08016B7C: .4byte gUnknown_203B204
_08016B80: .4byte gUnknown_80D49CC
_08016B84:
	ldr r0, _08016BB0
	ldr r2, [r0]
	ldr r0, [r4]
	ldr r3, [r0, 0x78]
	str r5, [sp]
	movs r0, 0xC
	movs r1, 0
	bl xxx_call_draw_string
_08016B96:
	ldr r4, _08016BB4
	ldr r0, [r4]
	adds r0, 0x64
	bl sub_8013C68
	ldr r0, [r4]
	ldr r0, [r0, 0x78]
	bl sub_80073E0
	add sp, 0x4
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_08016BB0: .4byte gUnknown_80D49DC
_08016BB4: .4byte gUnknown_203B204
	thumb_func_end sub_8016B48

	thumb_func_start sub_8016BB8
sub_8016BB8:
	push {r4-r6,lr}
	mov r6, r8
	push {r6}
	sub sp, 0x8
	adds r4, r0, 0
	bl sub_8008C54
	adds r0, r4, 0
	bl sub_80073B8
	ldr r2, _08016C34
	movs r0, 0
	mov r8, r0
	str r0, [sp]
	movs r0, 0x10
	movs r1, 0x4
	adds r3, r4, 0
	bl xxx_call_draw_string
	ldr r6, _08016C38
	ldr r0, [r6]
	movs r1, 0x98
	lsls r1, 2
	adds r0, r1
	ldr r2, [r0]
	movs r5, 0x5
	str r5, [sp]
	str r4, [sp, 0x4]
	movs r0, 0x60
	movs r1, 0x4
	movs r3, 0x5
	bl sub_8012BC4
	ldr r2, _08016C3C
	mov r0, r8
	str r0, [sp]
	movs r0, 0x70
	movs r1, 0x4
	adds r3, r4, 0
	bl xxx_call_draw_string
	ldr r0, [r6]
	movs r1, 0x99
	lsls r1, 2
	adds r0, r1
	ldr r2, [r0]
	str r5, [sp]
	str r4, [sp, 0x4]
	movs r0, 0xC8
	movs r1, 0x4
	movs r3, 0x7
	bl sub_8012BC4
	adds r0, r4, 0
	bl sub_80073E0
	add sp, 0x8
	pop {r3}
	mov r8, r3
	pop {r4-r6}
	pop {r0}
	bx r0
	.align 2, 0
_08016C34: .4byte gUnknown_80DB724
_08016C38: .4byte gUnknown_203B460
_08016C3C: .4byte gUnknown_80DB72C
	thumb_func_end sub_8016BB8

	thumb_func_start sub_8016C40
sub_8016C40:
	push {r4,lr}
	sub sp, 0x8
	adds r4, r0, 0
	bl sub_8008C54
	adds r0, r4, 0
	bl sub_80073B8
	ldr r2, _08016C8C
	movs r0, 0
	str r0, [sp]
	movs r0, 0x6
	movs r1, 0
	adds r3, r4, 0
	bl xxx_call_draw_string
	ldr r0, _08016C90
	ldr r0, [r0]
	movs r1, 0x98
	lsls r1, 2
	adds r0, r1
	ldr r2, [r0]
	movs r0, 0x5
	str r0, [sp]
	str r4, [sp, 0x4]
	movs r0, 0x2A
	movs r1, 0xC
	movs r3, 0x5
	bl sub_8012BC4
	adds r0, r4, 0
	bl sub_80073E0
	add sp, 0x8
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08016C8C: .4byte gUnknown_80DB738
_08016C90: .4byte gUnknown_203B460
	thumb_func_end sub_8016C40

	thumb_func_start sub_8016C94
sub_8016C94:
	push {r4-r6,lr}
	adds r4, r0, 0
	bl sub_8004914
	movs r0, 0
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	ldr r5, _08016CF0
	movs r0, 0xA6
	lsls r0, 1
	movs r1, 0x8
	bl MemoryAlloc
	str r0, [r5]
	movs r6, 0
	str r6, [r0, 0x18]
	str r6, [r0, 0x1C]
	str r6, [r0, 0x20]
	str r4, [r0]
	ldr r0, _08016CF4
	movs r1, 0x73
	bl sub_808D8E0
	ldr r4, _08016CF8
	adds r0, r4, 0
	movs r1, 0x73
	bl sub_808D8E0
	movs r0, 0x73
	bl sub_808D994
	adds r1, r0, 0
	subs r4, 0x50
	adds r0, r4, 0
	bl strcpy
	ldr r5, [r5]
	ldr r0, [r5]
	cmp r0, 0x1
	bne _08016CFC
	adds r0, r5, 0
	adds r0, 0xE8
	str r6, [r0]
	b _08016D06
	.align 2, 0
_08016CF0: .4byte gUnknown_203B208
_08016CF4: .4byte gUnknown_202E5D8
_08016CF8: .4byte gUnknown_202E1C8
_08016CFC:
	adds r1, r5, 0
	adds r1, 0xE8
	adds r0, r5, 0
	adds r0, 0xD8
	str r0, [r1]
_08016D06:
	movs r0, 0x73
	bl sub_808DDD0
	ldr r2, _08016D50
	ldr r3, [r2]
	adds r1, r3, 0
	adds r1, 0xD8
	str r0, [r1]
	adds r1, 0x4
	ldr r0, [r0, 0x4]
	str r0, [r1]
	adds r0, r3, 0
	adds r0, 0xE4
	movs r1, 0
	strb r1, [r0]
	ldr r0, [r2]
	adds r0, 0xE5
	strb r1, [r0]
	ldr r0, [r2]
	adds r0, 0xE6
	strb r1, [r0]
	ldr r1, [r2]
	adds r2, r1, 0
	adds r2, 0xE0
	movs r0, 0x2
	strh r0, [r2]
	adds r1, 0xE2
	movs r0, 0x8
	strh r0, [r1]
	movs r0, 0
	bl sub_8016E68
	movs r0, 0x1
	pop {r4-r6}
	pop {r1}
	bx r1
	.align 2, 0
_08016D50: .4byte gUnknown_203B208
	thumb_func_end sub_8016C94

	thumb_func_start sub_8016D54
sub_8016D54:
	push {lr}
	ldr r0, _08016D6C
	ldr r0, [r0]
	ldr r0, [r0, 0x4]
	cmp r0, 0x1C
	bhi _08016E34
	lsls r0, 2
	ldr r1, _08016D70
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08016D6C: .4byte gUnknown_203B208
_08016D70: .4byte _08016D74
	.align 2, 0
_08016D74:
	.4byte _08016DE8
	.4byte _08016DE8
	.4byte _08016E34
	.4byte _08016E34
	.4byte _08016E30
	.4byte _08016E34
	.4byte _08016E34
	.4byte _08016E34
	.4byte _08016E34
	.4byte _08016E34
	.4byte _08016E34
	.4byte _08016E34
	.4byte _08016E34
	.4byte _08016DEE
	.4byte _08016DEE
	.4byte _08016DF4
	.4byte _08016DFA
	.4byte _08016E00
	.4byte _08016E06
	.4byte _08016E34
	.4byte _08016E34
	.4byte _08016E34
	.4byte _08016E0C
	.4byte _08016E0C
	.4byte _08016E12
	.4byte _08016E18
	.4byte _08016E1E
	.4byte _08016E24
	.4byte _08016E2A
_08016DE8:
	bl sub_8017828
	b _08016E38
_08016DEE:
	bl sub_8017AF8
	b _08016E38
_08016DF4:
	bl sub_8017C7C
	b _08016E38
_08016DFA:
	bl sub_8017DC0
	b _08016E38
_08016E00:
	bl sub_80178D0
	b _08016E38
_08016E06:
	bl sub_80179A8
	b _08016E38
_08016E0C:
	bl sub_8017B88
	b _08016E38
_08016E12:
	bl sub_8017C28
	b _08016E38
_08016E18:
	bl sub_8017D24
	b _08016E38
_08016E1E:
	bl sub_8017DDC
	b _08016E38
_08016E24:
	bl sub_8017928
	b _08016E38
_08016E2A:
	bl sub_8017A1C
	b _08016E38
_08016E30:
	movs r0, 0x3
	b _08016E3A
_08016E34:
	bl sub_8017DF8
_08016E38:
	movs r0, 0
_08016E3A:
	pop {r1}
	bx r1
	thumb_func_end sub_8016D54

	thumb_func_start sub_8016E40
sub_8016E40:
	push {r4,lr}
	ldr r4, _08016E64
	ldr r0, [r4]
	cmp r0, 0
	beq _08016E5C
	adds r0, 0xD8
	ldr r0, [r0]
	bl CloseFile
	ldr r0, [r4]
	bl MemoryFree
	movs r0, 0
	str r0, [r4]
_08016E5C:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08016E64: .4byte gUnknown_203B208
	thumb_func_end sub_8016E40

	thumb_func_start sub_8016E68
sub_8016E68:
	push {lr}
	ldr r1, _08016E7C
	ldr r1, [r1]
	str r0, [r1, 0x4]
	bl sub_8016E80
	bl sub_8016FF8
	pop {r0}
	bx r0
	.align 2, 0
_08016E7C: .4byte gUnknown_203B208
	thumb_func_end sub_8016E68

	thumb_func_start sub_8016E80
sub_8016E80:
	push {r4-r7,lr}
	ldr r4, _08016EA4
	ldr r0, [r4]
	adds r0, 0xEC
	bl sub_8006518
	ldr r0, [r4]
	ldr r0, [r0, 0x4]
	subs r0, 0xD
	cmp r0, 0xC
	bls _08016E98
	b _08016FB4
_08016E98:
	lsls r0, 2
	ldr r1, _08016EA8
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08016EA4: .4byte gUnknown_203B208
_08016EA8: .4byte _08016EAC
	.align 2, 0
_08016EAC:
	.4byte _08016EE0
	.4byte _08016EE0
	.4byte _08016F94
	.4byte _08016FB4
	.4byte _08016FB4
	.4byte _08016FB4
	.4byte _08016FB4
	.4byte _08016FB4
	.4byte _08016FB4
	.4byte _08016F2C
	.4byte _08016F2C
	.4byte _08016F7C
	.4byte _08016F94
_08016EE0:
	ldr r3, _08016F24
	ldr r1, [r3]
	ldr r2, _08016F28
	adds r1, 0xEC
	adds r0, r2, 0
	ldm r0!, {r4-r6}
	stm r1!, {r4-r6}
	ldm r0!, {r4,r5,r7}
	stm r1!, {r4,r5,r7}
	ldr r1, [r3]
	movs r6, 0x82
	lsls r6, 1
	adds r1, r6
	adds r0, r2, 0
	ldm r0!, {r4,r5,r7}
	stm r1!, {r4,r5,r7}
	ldm r0!, {r4,r6,r7}
	stm r1!, {r4,r6,r7}
	ldr r1, [r3]
	movs r5, 0x8E
	lsls r5, 1
	adds r1, r5
	adds r0, r2, 0
	ldm r0!, {r4,r6,r7}
	stm r1!, {r4,r6,r7}
	ldm r0!, {r5-r7}
	stm r1!, {r5-r7}
	ldr r0, [r3]
	adds r0, 0xEC
	ldm r2!, {r1,r3,r4}
	stm r0!, {r1,r3,r4}
	ldm r2!, {r5-r7}
	stm r0!, {r5-r7}
	b _08016FD8
	.align 2, 0
_08016F24: .4byte gUnknown_203B208
_08016F28: .4byte gUnknown_80DB748
_08016F2C:
	ldr r3, _08016F70
	ldr r1, [r3]
	ldr r2, _08016F74
	adds r1, 0xEC
	adds r0, r2, 0
	ldm r0!, {r4-r6}
	stm r1!, {r4-r6}
	ldm r0!, {r4,r5,r7}
	stm r1!, {r4,r5,r7}
	ldr r1, [r3]
	movs r6, 0x82
	lsls r6, 1
	adds r1, r6
	adds r0, r2, 0
	ldm r0!, {r4,r5,r7}
	stm r1!, {r4,r5,r7}
	ldm r0!, {r4,r6,r7}
	stm r1!, {r4,r6,r7}
	ldr r0, [r3]
	movs r5, 0x8E
	lsls r5, 1
	adds r0, r5
	ldm r2!, {r1,r6,r7}
	stm r0!, {r1,r6,r7}
	ldm r2!, {r4-r6}
	stm r0!, {r4-r6}
	ldr r1, [r3]
	adds r1, 0xEC
	ldr r0, _08016F78
	ldm r0!, {r2,r3,r7}
	stm r1!, {r2,r3,r7}
	ldm r0!, {r4-r6}
	stm r1!, {r4-r6}
	b _08016FD8
	.align 2, 0
_08016F70: .4byte gUnknown_203B208
_08016F74: .4byte gUnknown_80DB748
_08016F78: .4byte gUnknown_80DB778
_08016F7C:
	ldr r0, _08016F8C
	ldr r1, [r0]
	movs r7, 0x82
	lsls r7, 1
	adds r1, r7
	ldr r0, _08016F90
	b _08016FA0
	.align 2, 0
_08016F8C: .4byte gUnknown_203B208
_08016F90: .4byte gUnknown_80DB790
_08016F94:
	ldr r0, _08016FAC
	ldr r1, [r0]
	movs r0, 0x8E
	lsls r0, 1
	adds r1, r0
	ldr r0, _08016FB0
_08016FA0:
	ldm r0!, {r2-r4}
	stm r1!, {r2-r4}
	ldm r0!, {r5-r7}
	stm r1!, {r5-r7}
	b _08016FD8
	.align 2, 0
_08016FAC: .4byte gUnknown_203B208
_08016FB0: .4byte gUnknown_80DB760
_08016FB4:
	ldr r0, _08016FF0
	mov r12, r0
	ldr r4, _08016FF4
	movs r3, 0
	movs r2, 0x3
_08016FBE:
	mov r5, r12
	ldr r1, [r5]
	adds r1, r3
	adds r1, 0xEC
	adds r0, r4, 0
	ldm r0!, {r5-r7}
	stm r1!, {r5-r7}
	ldm r0!, {r5-r7}
	stm r1!, {r5-r7}
	adds r3, 0x18
	subs r2, 0x1
	cmp r2, 0
	bge _08016FBE
_08016FD8:
	bl sub_8004914
	ldr r0, _08016FF0
	ldr r0, [r0]
	adds r0, 0xEC
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_08016FF0: .4byte gUnknown_203B208
_08016FF4: .4byte gUnknown_80DB748
	thumb_func_end sub_8016E80

	thumb_func_start sub_8016FF8
sub_8016FF8:
	push {r4,r5,lr}
	sub sp, 0x14
	ldr r1, _08017014
	ldr r0, [r1]
	ldr r0, [r0, 0x4]
	adds r4, r1, 0
	cmp r0, 0x1D
	bls _0801700A
	b _08017584
_0801700A:
	lsls r0, 2
	ldr r1, _08017018
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08017014: .4byte gUnknown_203B208
_08017018: .4byte _0801701C
	.align 2, 0
_0801701C:
	.4byte _08017094
	.4byte _080170BC
	.4byte _0801710C
	.4byte _0801713C
	.4byte _08017584
	.4byte _0801715C
	.4byte _0801718C
	.4byte _080171BC
	.4byte _080171EC
	.4byte _0801721C
	.4byte _0801724C
	.4byte _0801726C
	.4byte _0801728C
	.4byte _080172AC
	.4byte _080172BA
	.4byte _080172C2
	.4byte _080174A8
	.4byte _080172E4
	.4byte _0801731C
	.4byte _08017344
	.4byte _08017394
	.4byte _080173B4
	.4byte _080173E8
	.4byte _080173F6
	.4byte _08017404
	.4byte _08017474
	.4byte _080174A8
	.4byte _080174B2
	.4byte _080174E8
	.4byte _08017530
_08017094:
	bl sub_80175FC
	ldr r2, _080170B4
	ldr r0, [r2]
	adds r0, 0xE4
	movs r4, 0
	movs r1, 0x1
	strb r1, [r0]
	ldr r3, _080170B8
	ldr r5, [r2]
	ldr r1, [r5]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 4
	adds r0, r3
	b _080170DA
	.align 2, 0
_080170B4: .4byte gUnknown_203B208
_080170B8: .4byte gUnknown_80D5404
_080170BC:
	bl sub_80175FC
	ldr r1, _08017104
	ldr r0, [r1]
	adds r0, 0xE4
	movs r4, 0
	strb r4, [r0]
	ldr r2, _08017108
	ldr r5, [r1]
	ldr r1, [r5]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 4
	adds r2, 0x4
	adds r0, r2
_080170DA:
	ldr r0, [r0]
	ldr r2, [r5, 0x18]
	adds r3, r5, 0
	adds r3, 0x24
	adds r1, r5, 0
	adds r1, 0x4C
	str r1, [sp]
	movs r1, 0x4
	str r1, [sp, 0x4]
	str r4, [sp, 0x8]
	adds r1, r5, 0
	adds r1, 0xE8
	ldr r1, [r1]
	str r1, [sp, 0xC]
	movs r1, 0xC
	str r1, [sp, 0x10]
	movs r1, 0
	bl sub_8014248
	b _08017584
	.align 2, 0
_08017104: .4byte gUnknown_203B208
_08017108: .4byte gUnknown_80D5404
_0801710C:
	ldr r0, [r4]
	movs r1, 0x1
	str r1, [r0, 0x8]
	adds r0, 0xE4
	movs r1, 0
	strb r1, [r0]
	ldr r2, _08017134
	ldr r3, [r4]
	ldr r1, [r3]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 4
	adds r2, 0x4C
	adds r0, r2
	ldr r0, [r0]
	adds r3, 0xE8
	ldr r2, [r3]
	ldr r3, _08017138
	b _080173D8
	.align 2, 0
_08017134: .4byte gUnknown_80D5404
_08017138: .4byte 0x0000010d
_0801713C:
	ldr r0, [r4]
	movs r1, 0x4
	str r1, [r0, 0x8]
	adds r0, 0xE4
	movs r1, 0x1
	strb r1, [r0]
	ldr r2, _08017158
	ldr r3, [r4]
	ldr r1, [r3]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 4
	adds r2, 0x8
	b _080173CE
	.align 2, 0
_08017158: .4byte gUnknown_80D5404
_0801715C:
	ldr r0, [r4]
	movs r1, 0x1
	str r1, [r0, 0x8]
	adds r0, 0xE4
	movs r1, 0
	strb r1, [r0]
	ldr r2, _08017184
	ldr r3, [r4]
	ldr r1, [r3]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 4
	adds r2, 0x34
	adds r0, r2
	ldr r0, [r0]
	adds r3, 0xE8
	ldr r2, [r3]
	ldr r3, _08017188
	b _080173D8
	.align 2, 0
_08017184: .4byte gUnknown_80D5404
_08017188: .4byte 0x0000010d
_0801718C:
	ldr r0, [r4]
	movs r1, 0x1
	str r1, [r0, 0x8]
	adds r0, 0xE4
	movs r1, 0
	strb r1, [r0]
	ldr r2, _080171B4
	ldr r3, [r4]
	ldr r1, [r3]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 4
	adds r2, 0x38
	adds r0, r2
	ldr r0, [r0]
	adds r3, 0xE8
	ldr r2, [r3]
	ldr r3, _080171B8
	b _080173D8
	.align 2, 0
_080171B4: .4byte gUnknown_80D5404
_080171B8: .4byte 0x0000010d
_080171BC:
	ldr r0, [r4]
	movs r1, 0x1
	str r1, [r0, 0x8]
	adds r0, 0xE4
	movs r1, 0
	strb r1, [r0]
	ldr r2, _080171E4
	ldr r3, [r4]
	ldr r1, [r3]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 4
	adds r2, 0x3C
	adds r0, r2
	ldr r0, [r0]
	adds r3, 0xE8
	ldr r2, [r3]
	ldr r3, _080171E8
	b _080173D8
	.align 2, 0
_080171E4: .4byte gUnknown_80D5404
_080171E8: .4byte 0x0000010d
_080171EC:
	ldr r0, [r4]
	movs r1, 0x1
	str r1, [r0, 0x8]
	adds r0, 0xE4
	movs r1, 0
	strb r1, [r0]
	ldr r2, _08017214
	ldr r3, [r4]
	ldr r1, [r3]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 4
	adds r2, 0x48
	adds r0, r2
	ldr r0, [r0]
	adds r3, 0xE8
	ldr r2, [r3]
	ldr r3, _08017218
	b _080173D8
	.align 2, 0
_08017214: .4byte gUnknown_80D5404
_08017218: .4byte 0x0000010d
_0801721C:
	ldr r0, _08017244
	ldr r1, [r4]
	adds r1, 0xC
	movs r2, 0
	bl sub_8090E14
	ldr r0, [r4]
	movs r1, 0xE
	str r1, [r0, 0x8]
	adds r0, 0xE4
	movs r1, 0
	strb r1, [r0]
	ldr r2, _08017248
	ldr r3, [r4]
	ldr r1, [r3]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 4
	adds r2, 0x40
	b _080173CE
	.align 2, 0
_08017244: .4byte gUnknown_202DE58
_08017248: .4byte gUnknown_80D5404
_0801724C:
	ldr r0, [r4]
	movs r1, 0xE
	str r1, [r0, 0x8]
	adds r0, 0xE4
	movs r1, 0
	strb r1, [r0]
	ldr r2, _08017268
	ldr r3, [r4]
	ldr r1, [r3]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 4
	adds r2, 0x44
	b _080173CE
	.align 2, 0
_08017268: .4byte gUnknown_80D5404
_0801726C:
	ldr r0, [r4]
	movs r1, 0xD
	str r1, [r0, 0x8]
	adds r0, 0xE4
	movs r1, 0
	strb r1, [r0]
	ldr r2, _08017288
	ldr r3, [r4]
	ldr r1, [r3]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 4
	adds r2, 0xC
	b _080173CE
	.align 2, 0
_08017288: .4byte gUnknown_80D5404
_0801728C:
	ldr r0, [r4]
	movs r1, 0xE
	str r1, [r0, 0x8]
	adds r0, 0xE4
	movs r1, 0
	strb r1, [r0]
	ldr r2, _080172A8
	ldr r3, [r4]
	ldr r1, [r3]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 4
	adds r2, 0x10
	b _080173CE
	.align 2, 0
_080172A8: .4byte gUnknown_80D5404
_080172AC:
	movs r0, 0x3
	movs r1, 0x3
	movs r2, 0
	movs r3, 0xA
	bl sub_801A5D8
	b _08017584
_080172BA:
	movs r0, 0x1
	bl sub_801A8D0
	b _08017584
_080172C2:
	bl sub_801A9E0
	bl sub_80176B8
	ldr r0, _080172E0
	ldr r2, [r0]
	adds r0, r2, 0
	adds r0, 0x58
	adds r1, r2, 0
	adds r1, 0x24
	adds r3, r2, 0
	adds r3, 0x4C
	ldr r2, [r2, 0x1C]
	b _08017494
	.align 2, 0
_080172E0: .4byte gUnknown_203B208
_080172E4:
	bl sub_80177F8
	ldr r0, _08017310
	ldr r4, _08017314
	ldr r1, [r4]
	adds r1, 0xC
	movs r2, 0
	bl sub_8090E14
	ldr r0, [r4]
	adds r0, 0xE4
	movs r5, 0
	strb r5, [r0]
	ldr r2, _08017318
	ldr r4, [r4]
	ldr r1, [r4]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 4
	adds r2, 0x14
	b _08017504
	.align 2, 0
_08017310: .4byte gUnknown_202DE58
_08017314: .4byte gUnknown_203B208
_08017318: .4byte gUnknown_80D5404
_0801731C:
	bl sub_80177F8
	ldr r1, _0801733C
	ldr r0, [r1]
	adds r0, 0xE4
	movs r5, 0
	strb r5, [r0]
	ldr r2, _08017340
	ldr r4, [r1]
	ldr r1, [r4]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 4
	adds r2, 0x18
	b _08017504
	.align 2, 0
_0801733C: .4byte gUnknown_203B208
_08017340: .4byte gUnknown_80D5404
_08017344:
	bl sub_8090A34
	cmp r0, 0
	bne _0801735C
	bl sub_801A928
	ldr r0, _08017358
	ldr r1, [r0]
	movs r0, 0x1
	b _08017362
	.align 2, 0
_08017358: .4byte gUnknown_203B208
_0801735C:
	ldr r0, _08017388
	ldr r1, [r0]
	movs r0, 0xC
_08017362:
	str r0, [r1, 0x8]
	ldr r3, _08017388
	ldr r0, [r3]
	adds r0, 0xE4
	movs r1, 0x1
	strb r1, [r0]
	ldr r2, _0801738C
	ldr r3, [r3]
	ldr r1, [r3]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 4
	adds r2, 0x1C
	adds r0, r2
	ldr r0, [r0]
	adds r3, 0xE8
	ldr r2, [r3]
	ldr r3, _08017390
	b _080173D8
	.align 2, 0
_08017388: .4byte gUnknown_203B208
_0801738C: .4byte gUnknown_80D5404
_08017390: .4byte 0x0000010d
_08017394:
	ldr r0, [r4]
	movs r1, 0x16
	str r1, [r0, 0x8]
	adds r0, 0xE4
	movs r1, 0
	strb r1, [r0]
	ldr r2, _080173B0
	ldr r3, [r4]
	ldr r1, [r3]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 4
	adds r2, 0x20
	b _080173CE
	.align 2, 0
_080173B0: .4byte gUnknown_80D5404
_080173B4:
	ldr r0, [r4]
	movs r1, 0x17
	str r1, [r0, 0x8]
	adds r0, 0xE4
	movs r1, 0
	strb r1, [r0]
	ldr r2, _080173E0
	ldr r3, [r4]
	ldr r1, [r3]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 4
	adds r2, 0x24
_080173CE:
	adds r0, r2
	ldr r0, [r0]
	adds r3, 0xE8
	ldr r2, [r3]
	ldr r3, _080173E4
_080173D8:
	movs r1, 0
	bl sub_80141B4
	b _08017584
	.align 2, 0
_080173E0: .4byte gUnknown_80D5404
_080173E4: .4byte 0x0000030d
_080173E8:
	movs r0, 0x1
	movs r1, 0x3
	movs r2, 0
	movs r3, 0xA
	bl sub_801C8C4
	b _080173FC
_080173F6:
	movs r0, 0x1
	bl sub_801CB5C
_080173FC:
	movs r0, 0
	bl sub_801AD34
	b _08017584
_08017404:
	ldr r2, [r4]
	adds r1, r2, 0
	adds r1, 0xB8
	movs r0, 0x2
	str r0, [r1]
	subs r1, 0x8
	movs r0, 0x1
	str r0, [r1]
	ldr r0, _08017430
	ldr r1, [r0]
	ldrb r0, [r2, 0xE]
	lsls r0, 1
	adds r1, 0x50
	adds r3, r1, r0
	ldrh r0, [r3]
	cmp r0, 0x63
	bls _08017434
	adds r1, r2, 0
	adds r1, 0xB4
	movs r0, 0x63
	b _0801743A
	.align 2, 0
_08017430: .4byte gUnknown_203B460
_08017434:
	adds r1, r2, 0
	adds r1, 0xB4
	ldrh r0, [r3]
_0801743A:
	str r0, [r1]
	ldr r2, [r4]
	adds r1, r2, 0
	adds r1, 0xAC
	adds r0, r2, 0
	adds r0, 0xB4
	ldr r0, [r0]
	str r0, [r1]
	adds r1, 0x10
	movs r0, 0x1
	str r0, [r1]
	adds r1, 0x4
	movs r3, 0x82
	lsls r3, 1
	adds r0, r2, r3
	str r0, [r1]
	adds r1, 0x4
	movs r0, 0x28
	str r0, [r1]
	adds r1, 0x4
	movs r0, 0x12
	str r0, [r1]
	adds r0, r2, 0
	adds r0, 0xA8
	bl sub_8013AA0
	bl sub_8017598
	b _08017584
_08017474:
	bl sub_801CCD8
	movs r0, 0
	bl sub_801AD34
	bl sub_8017758
	ldr r0, _080174A4
	ldr r2, [r0]
	adds r0, r2, 0
	adds r0, 0x58
	adds r1, r2, 0
	adds r1, 0x24
	adds r3, r2, 0
	adds r3, 0x4C
	ldr r2, [r2, 0x20]
_08017494:
	str r2, [sp]
	movs r2, 0x2
	str r2, [sp, 0x4]
	movs r2, 0
	bl sub_8012D60
	b _08017584
	.align 2, 0
_080174A4: .4byte gUnknown_203B208
_080174A8:
	ldr r0, [r4]
	adds r0, 0xC
	bl sub_801B3C0
	b _08017584
_080174B2:
	bl sub_80177F8
	ldr r0, _080174DC
	ldr r4, _080174E0
	ldr r1, [r4]
	adds r1, 0xC
	movs r2, 0
	bl sub_8090E14
	ldr r0, [r4]
	adds r0, 0xE4
	movs r5, 0
	strb r5, [r0]
	ldr r2, _080174E4
	ldr r4, [r4]
	ldr r1, [r4]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 4
	adds r2, 0x28
	b _08017504
	.align 2, 0
_080174DC: .4byte gUnknown_202DE58
_080174E0: .4byte gUnknown_203B208
_080174E4: .4byte gUnknown_80D5404
_080174E8:
	bl sub_80177F8
	ldr r1, _08017528
	ldr r0, [r1]
	adds r0, 0xE4
	movs r5, 0
	strb r5, [r0]
	ldr r2, _0801752C
	ldr r4, [r1]
	ldr r1, [r4]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 4
	adds r2, 0x2C
_08017504:
	adds r0, r2
	ldr r0, [r0]
	adds r3, r4, 0
	adds r3, 0x24
	str r5, [sp]
	movs r1, 0x4
	str r1, [sp, 0x4]
	str r5, [sp, 0x8]
	adds r4, 0xE8
	ldr r1, [r4]
	str r1, [sp, 0xC]
	movs r1, 0xC
	str r1, [sp, 0x10]
	movs r1, 0
	movs r2, 0x4
	bl sub_8014248
	b _08017584
	.align 2, 0
_08017528: .4byte gUnknown_203B208
_0801752C: .4byte gUnknown_80D5404
_08017530:
	movs r0, 0x1
	bl sub_801CF14
	lsls r0, 24
	cmp r0, 0
	bne _08017544
	bl sub_8090A34
	cmp r0, 0x13
	ble _08017554
_08017544:
	bl sub_801CBB8
	ldr r0, _08017550
	ldr r1, [r0]
	movs r0, 0x1
	b _0801755A
	.align 2, 0
_08017550: .4byte gUnknown_203B208
_08017554:
	ldr r0, _0801758C
	ldr r1, [r0]
	movs r0, 0x15
_0801755A:
	str r0, [r1, 0x8]
	ldr r3, _0801758C
	ldr r0, [r3]
	adds r0, 0xE4
	movs r1, 0x1
	strb r1, [r0]
	ldr r2, _08017590
	ldr r3, [r3]
	ldr r1, [r3]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 4
	adds r2, 0x30
	adds r0, r2
	ldr r0, [r0]
	adds r3, 0xE8
	ldr r2, [r3]
	ldr r3, _08017594
	movs r1, 0
	bl sub_80141B4
_08017584:
	add sp, 0x14
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_0801758C: .4byte gUnknown_203B208
_08017590: .4byte gUnknown_80D5404
_08017594: .4byte 0x0000010d
	thumb_func_end sub_8016FF8

	thumb_func_start sub_8017598
sub_8017598:
	push {r4,lr}
	sub sp, 0x4
	ldr r4, _080175F4
	ldr r0, [r4]
	adds r0, 0xBC
	ldr r0, [r0]
	bl sub_8008C54
	ldr r0, [r4]
	adds r0, 0xBC
	ldr r0, [r0]
	bl sub_80073B8
	ldr r2, _080175F8
	ldr r0, [r4]
	adds r0, 0xBC
	ldr r3, [r0]
	movs r0, 0
	str r0, [sp]
	movs r0, 0x4
	movs r1, 0
	bl xxx_call_draw_string
	ldr r0, [r4]
	adds r0, 0xA8
	bl sub_8013C68
	ldr r0, [r4]
	adds r0, 0xBC
	ldr r0, [r0]
	bl sub_80073E0
	bl sub_801CCD8
	movs r0, 0
	bl sub_801AD34
	ldr r0, [r4]
	adds r0, 0x58
	movs r1, 0
	bl sub_8012EA4
	add sp, 0x4
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080175F4: .4byte gUnknown_203B208
_080175F8: .4byte gUnknown_80DB7A8
	thumb_func_end sub_8017598

	thumb_func_start sub_80175FC
sub_80175FC:
	push {r4-r7,lr}
	ldr r4, _0801767C
	ldr r0, [r4]
	adds r0, 0x4C
	movs r1, 0
	movs r2, 0xA
	bl MemoryFill16
	ldr r3, [r4]
	movs r2, 0
	ldr r0, _08017680
	ldr r0, [r0]
	str r0, [r3, 0x24]
	movs r0, 0x2
	str r0, [r3, 0x28]
	movs r1, 0x1
	ldr r0, _08017684
	ldr r0, [r0]
	str r0, [r3, 0x2C]
	movs r0, 0x3
	str r0, [r3, 0x30]
	ldr r0, _08017688
	ldr r0, [r0]
	str r0, [r3, 0x34]
	movs r0, 0x6
	str r0, [r3, 0x38]
	ldr r0, _0801768C
	ldr r0, [r0]
	str r0, [r3, 0x3C]
	str r1, [r3, 0x40]
	movs r6, 0x4
	str r2, [r3, 0x44]
	str r1, [r3, 0x48]
	movs r5, 0
	mov r12, r3
	adds r3, 0x28
	mov r2, r12
	adds r2, 0x4C
_08017648:
	ldrh r0, [r2]
	cmp r0, 0
	bne _08017658
	ldr r1, [r3]
	mov r7, r12
	ldr r0, [r7, 0x18]
	cmp r1, r0
	beq _080176B2
_08017658:
	adds r3, 0x8
	adds r2, 0x2
	adds r5, 0x1
	cmp r5, r6
	blt _08017648
	movs r5, 0
	cmp r5, r6
	bge _080176B2
	ldr r1, [r4]
	adds r0, r1, 0
	adds r0, 0x4C
	ldrh r0, [r0]
	cmp r0, 0
	bne _08017690
	ldr r0, [r1, 0x28]
	str r0, [r1, 0x18]
	b _080176B2
	.align 2, 0
_0801767C: .4byte gUnknown_203B208
_08017680: .4byte gUnknown_80D4958
_08017684: .4byte gUnknown_80D4964
_08017688: .4byte gUnknown_80D4970
_0801768C: .4byte gUnknown_80D4934
_08017690:
	adds r5, 0x1
	cmp r5, r6
	bge _080176B2
	ldr r2, [r4]
	lsls r0, r5, 1
	adds r1, r2, 0
	adds r1, 0x4C
	adds r1, r0
	ldrh r0, [r1]
	cmp r0, 0
	bne _08017690
	lsls r0, r5, 3
	adds r1, r2, 0
	adds r1, 0x28
	adds r1, r0
	ldr r0, [r1]
	str r0, [r2, 0x18]
_080176B2:
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_80175FC

	thumb_func_start sub_80176B8
sub_80176B8:
	push {r4-r7,lr}
	ldr r4, _08017724
	ldr r0, [r4]
	adds r0, 0x4C
	movs r1, 0
	movs r2, 0xA
	bl MemoryFill16
	ldr r3, [r4]
	movs r2, 0
	ldr r0, _08017728
	ldr r0, [r0]
	str r0, [r3, 0x24]
	movs r0, 0x2
	str r0, [r3, 0x28]
	movs r1, 0x1
	ldr r0, _0801772C
	ldr r0, [r0]
	str r0, [r3, 0x2C]
	movs r0, 0x6
	str r0, [r3, 0x30]
	movs r6, 0x2
	str r2, [r3, 0x34]
	str r1, [r3, 0x38]
	movs r5, 0
	mov r12, r3
	adds r3, 0x28
	mov r2, r12
	adds r2, 0x4C
_080176F2:
	ldrh r0, [r2]
	cmp r0, 0
	bne _08017702
	ldr r1, [r3]
	mov r7, r12
	ldr r0, [r7, 0x1C]
	cmp r1, r0
	beq _08017752
_08017702:
	adds r3, 0x8
	adds r2, 0x2
	adds r5, 0x1
	cmp r5, r6
	blt _080176F2
	movs r5, 0
	cmp r5, r6
	bge _08017752
	ldr r1, [r4]
	adds r0, r1, 0
	adds r0, 0x4C
	ldrh r0, [r0]
	cmp r0, 0
	bne _08017730
	ldr r0, [r1, 0x28]
	str r0, [r1, 0x1C]
	b _08017752
	.align 2, 0
_08017724: .4byte gUnknown_203B208
_08017728: .4byte gUnknown_80D4958
_0801772C: .4byte gUnknown_80D4970
_08017730:
	adds r5, 0x1
	cmp r5, r6
	bge _08017752
	ldr r2, [r4]
	lsls r0, r5, 1
	adds r1, r2, 0
	adds r1, 0x4C
	adds r1, r0
	ldrh r0, [r1]
	cmp r0, 0
	bne _08017730
	lsls r0, r5, 3
	adds r1, r2, 0
	adds r1, 0x28
	adds r1, r0
	ldr r0, [r1]
	str r0, [r2, 0x1C]
_08017752:
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_80176B8

	thumb_func_start sub_8017758
sub_8017758:
	push {r4-r7,lr}
	ldr r4, _080177C4
	ldr r0, [r4]
	adds r0, 0x4C
	movs r1, 0
	movs r2, 0xA
	bl MemoryFill16
	ldr r3, [r4]
	movs r2, 0
	ldr r0, _080177C8
	ldr r0, [r0]
	str r0, [r3, 0x24]
	movs r0, 0x3
	str r0, [r3, 0x28]
	movs r1, 0x1
	ldr r0, _080177CC
	ldr r0, [r0]
	str r0, [r3, 0x2C]
	movs r0, 0x6
	str r0, [r3, 0x30]
	movs r6, 0x2
	str r2, [r3, 0x34]
	str r1, [r3, 0x38]
	movs r5, 0
	mov r12, r3
	adds r3, 0x28
	mov r2, r12
	adds r2, 0x4C
_08017792:
	ldrh r0, [r2]
	cmp r0, 0
	bne _080177A2
	ldr r1, [r3]
	mov r7, r12
	ldr r0, [r7, 0x20]
	cmp r1, r0
	beq _080177F2
_080177A2:
	adds r3, 0x8
	adds r2, 0x2
	adds r5, 0x1
	cmp r5, r6
	blt _08017792
	movs r5, 0
	cmp r5, r6
	bge _080177F2
	ldr r1, [r4]
	adds r0, r1, 0
	adds r0, 0x4C
	ldrh r0, [r0]
	cmp r0, 0
	bne _080177D0
	ldr r0, [r1, 0x28]
	str r0, [r1, 0x20]
	b _080177F2
	.align 2, 0
_080177C4: .4byte gUnknown_203B208
_080177C8: .4byte gUnknown_80D4964
_080177CC: .4byte gUnknown_80D4970
_080177D0:
	adds r5, 0x1
	cmp r5, r6
	bge _080177F2
	ldr r2, [r4]
	lsls r0, r5, 1
	adds r1, r2, 0
	adds r1, 0x4C
	adds r1, r0
	ldrh r0, [r1]
	cmp r0, 0
	bne _080177D0
	lsls r0, r5, 3
	adds r1, r2, 0
	adds r1, 0x28
	adds r1, r0
	ldr r0, [r1]
	str r0, [r2, 0x20]
_080177F2:
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_8017758

	thumb_func_start sub_80177F8
sub_80177F8:
	ldr r0, _0801781C
	ldr r1, [r0]
	movs r3, 0
	ldr r0, _08017820
	ldr r0, [r0]
	str r0, [r1, 0x24]
	movs r0, 0x4
	str r0, [r1, 0x28]
	movs r2, 0x1
	ldr r0, _08017824
	ldr r0, [r0]
	str r0, [r1, 0x2C]
	movs r0, 0x5
	str r0, [r1, 0x30]
	str r3, [r1, 0x34]
	str r2, [r1, 0x38]
	bx lr
	.align 2, 0
_0801781C: .4byte gUnknown_203B208
_08017820: .4byte gUnknown_80D4920
_08017824: .4byte gUnknown_80D4928
	thumb_func_end sub_80177F8

	thumb_func_start sub_8017828
sub_8017828:
	push {lr}
	sub sp, 0x4
	mov r0, sp
	bl sub_80144A4
	cmp r0, 0
	bne _080178C8
	ldr r1, [sp]
	cmp r1, 0x1
	beq _08017842
	ldr r0, _08017854
	ldr r0, [r0]
	str r1, [r0, 0x18]
_08017842:
	ldr r0, [sp]
	cmp r0, 0x2
	beq _08017862
	cmp r0, 0x2
	bgt _08017858
	cmp r0, 0x1
	beq _080178C2
	b _080178C8
	.align 2, 0
_08017854: .4byte gUnknown_203B208
_08017858:
	cmp r0, 0x3
	beq _0801788E
	cmp r0, 0x6
	beq _080178BA
	b _080178C8
_08017862:
	bl sub_8090A34
	cmp r0, 0
	bne _08017872
	movs r0, 0x5
	bl sub_8016E68
	b _080178C8
_08017872:
	movs r0, 0
	bl sub_801CF50
	lsls r0, 24
	cmp r0, 0
	beq _08017886
	movs r0, 0x8
	bl sub_8016E68
	b _080178C8
_08017886:
	movs r0, 0xB
	bl sub_8016E68
	b _080178C8
_0801788E:
	movs r0, 0x1
	bl sub_801CF14
	lsls r0, 24
	cmp r0, 0
	beq _080178A2
	movs r0, 0x7
	bl sub_8016E68
	b _080178C8
_080178A2:
	bl sub_8090A34
	cmp r0, 0x13
	ble _080178B2
	movs r0, 0x6
	bl sub_8016E68
	b _080178C8
_080178B2:
	movs r0, 0x14
	bl sub_8016E68
	b _080178C8
_080178BA:
	movs r0, 0x2
	bl sub_8016E68
	b _080178C8
_080178C2:
	movs r0, 0x3
	bl sub_8016E68
_080178C8:
	add sp, 0x4
	pop {r0}
	bx r0
	thumb_func_end sub_8017828

	thumb_func_start sub_80178D0
sub_80178D0:
	push {r4,lr}
	sub sp, 0x4
	mov r0, sp
	bl sub_80144A4
	cmp r0, 0
	bne _0801791E
	ldr r0, [sp]
	cmp r0, 0x4
	beq _080178F4
	cmp r0, 0x4
	bgt _080178EE
	cmp r0, 0x1
	beq _08017918
	b _0801791E
_080178EE:
	cmp r0, 0x5
	beq _08017918
	b _0801791E
_080178F4:
	ldr r4, _08017914
	ldr r0, [r4]
	adds r0, 0xC
	bl sub_80917B8
	ldr r0, [r4]
	ldr r0, [r0, 0x10]
	bl sub_80911F8
	bl sub_80910B4
	movs r0, 0x13
	bl sub_8016E68
	b _0801791E
	.align 2, 0
_08017914: .4byte gUnknown_203B208
_08017918:
	movs r0, 0xE
	bl sub_8016E68
_0801791E:
	add sp, 0x4
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_80178D0

	thumb_func_start sub_8017928
sub_8017928:
	push {lr}
	sub sp, 0x8
	mov r0, sp
	bl sub_80144A4
	cmp r0, 0
	bne _080179A2
	ldr r0, [sp]
	cmp r0, 0x4
	beq _0801794C
	cmp r0, 0x4
	bgt _08017946
	cmp r0, 0x1
	beq _0801799C
	b _080179A2
_08017946:
	cmp r0, 0x5
	beq _0801799C
	b _080179A2
_0801794C:
	ldr r0, _0801798C
	ldr r1, [r0]
	ldr r0, _08017990
	ldr r3, [r0]
	ldrb r0, [r3, 0xE]
	lsls r0, 1
	adds r1, 0x50
	adds r1, r0
	ldrb r2, [r3, 0xD]
	ldrh r0, [r1]
	subs r0, r2
	strh r0, [r1]
	ldrb r2, [r3, 0xE]
	ldr r1, _08017994
	ldr r0, [sp, 0x4]
	ands r0, r1
	orrs r0, r2
	str r0, [sp, 0x4]
	ldrb r1, [r3, 0xD]
	lsls r1, 8
	ldr r2, _08017998
	ands r0, r2
	orrs r0, r1
	str r0, [sp, 0x4]
	add r0, sp, 0x4
	bl sub_8091274
	movs r0, 0x1D
	bl sub_8016E68
	b _080179A2
	.align 2, 0
_0801798C: .4byte gUnknown_203B460
_08017990: .4byte gUnknown_203B208
_08017994: .4byte 0xffffff00
_08017998: .4byte 0xffff00ff
_0801799C:
	movs r0, 0x17
	bl sub_8016E68
_080179A2:
	add sp, 0x8
	pop {r0}
	bx r0
	thumb_func_end sub_8017928

	thumb_func_start sub_80179A8
sub_80179A8:
	push {r4-r7,lr}
	sub sp, 0x4
	mov r0, sp
	bl sub_80144A4
	cmp r0, 0
	bne _08017A12
	ldr r0, [sp]
	cmp r0, 0x4
	beq _080179CC
	cmp r0, 0x4
	bgt _080179C6
	cmp r0, 0x1
	beq _08017A0C
	b _08017A12
_080179C6:
	cmp r0, 0x5
	beq _08017A0C
	b _08017A12
_080179CC:
	movs r5, 0
	ldr r6, _08017A08
	movs r7, 0
_080179D2:
	adds r0, r5, 0
	bl sub_801AED0
	cmp r0, 0
	beq _080179F2
	lsls r4, r5, 2
	ldr r0, [r6]
	adds r0, r4
	bl sub_80917B8
	ldr r0, [r6]
	adds r0, r4
	strb r7, [r0, 0x2]
	ldr r0, [r6]
	adds r0, r4
	strb r7, [r0]
_080179F2:
	adds r5, 0x1
	cmp r5, 0x13
	ble _080179D2
	bl sub_80910B4
	bl sub_801AE84
	movs r0, 0x13
	bl sub_8016E68
	b _08017A12
	.align 2, 0
_08017A08: .4byte gUnknown_203B460
_08017A0C:
	movs r0, 0xE
	bl sub_8016E68
_08017A12:
	add sp, 0x4
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_80179A8

	thumb_func_start sub_8017A1C
sub_8017A1C:
	push {r4-r6,lr}
	sub sp, 0x8
	mov r0, sp
	bl sub_80144A4
	cmp r0, 0
	bne _08017AEE
	ldr r0, [sp]
	cmp r0, 0x4
	beq _08017A40
	cmp r0, 0x4
	bgt _08017A3A
	cmp r0, 0x1
	beq _08017AE8
	b _08017AEE
_08017A3A:
	cmp r0, 0x5
	beq _08017AE8
	b _08017AEE
_08017A40:
	movs r5, 0
	ldr r6, _08017A88
_08017A44:
	lsls r0, r5, 24
	lsrs r4, r0, 24
	adds r0, r4, 0
	bl sub_801CFE0
	cmp r0, 0
	beq _08017ACE
	ldr r1, _08017A8C
	ldr r0, [sp, 0x4]
	ands r0, r1
	orrs r0, r4
	str r0, [sp, 0x4]
	add r4, sp, 0x4
	ldrb r0, [r4]
	bl sub_8090A60
	lsls r0, 24
	cmp r0, 0
	beq _08017AA2
	ldr r2, _08017A90
	ldr r1, [r2]
	ldrb r0, [r4]
	lsls r0, 1
	adds r1, 0x50
	adds r1, r0
	ldrh r1, [r1]
	cmp r1, 0x63
	bls _08017A94
	ldr r0, [sp, 0x4]
	ands r0, r6
	movs r1, 0xC6
	lsls r1, 7
	b _08017A9C
	.align 2, 0
_08017A88: .4byte 0xffff00ff
_08017A8C: .4byte 0xffffff00
_08017A90: .4byte gUnknown_203B460
_08017A94:
	lsls r1, 24
	lsrs r1, 16
	ldr r0, [sp, 0x4]
	ands r0, r6
_08017A9C:
	orrs r0, r1
	str r0, [sp, 0x4]
	b _08017AB0
_08017AA2:
	ldr r0, [sp, 0x4]
	ands r0, r6
	movs r1, 0x80
	lsls r1, 1
	orrs r0, r1
	str r0, [sp, 0x4]
	ldr r2, _08017AE4
_08017AB0:
	ldr r3, [r2]
	add r0, sp, 0x4
	ldrb r1, [r4]
	lsls r1, 1
	adds r3, 0x50
	adds r3, r1
	ldr r1, [sp, 0x4]
	lsrs r1, 8
	lsls r1, 24
	lsrs r1, 24
	ldrh r2, [r3]
	subs r2, r1
	strh r2, [r3]
	bl sub_8091274
_08017ACE:
	adds r5, 0x1
	cmp r5, 0xEF
	ble _08017A44
	bl sub_80910B4
	bl sub_801CF94
	movs r0, 0x1D
	bl sub_8016E68
	b _08017AEE
	.align 2, 0
_08017AE4: .4byte gUnknown_203B460
_08017AE8:
	movs r0, 0x17
	bl sub_8016E68
_08017AEE:
	add sp, 0x8
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end sub_8017A1C

	thumb_func_start sub_8017AF8
sub_8017AF8:
	push {lr}
	movs r0, 0x1
	bl sub_801A6E8
	cmp r0, 0x3
	beq _08017B14
	cmp r0, 0x3
	bhi _08017B0E
	cmp r0, 0x2
	beq _08017B78
	b _08017B82
_08017B0E:
	cmp r0, 0x4
	beq _08017B50
	b _08017B82
_08017B14:
	bl sub_801AEA8
	cmp r0, 0
	beq _08017B2A
	movs r0, 0
	bl sub_8099690
	movs r0, 0x12
	bl sub_8016E68
	b _08017B82
_08017B2A:
	bl sub_801A8AC
	ldr r1, _08017B48
	ldr r2, [r1]
	str r0, [r2, 0x10]
	ldr r1, _08017B4C
	ldr r1, [r1]
	lsls r0, 2
	adds r1, r0
	ldr r0, [r1]
	str r0, [r2, 0xC]
	movs r0, 0xF
	bl sub_8016E68
	b _08017B82
	.align 2, 0
_08017B48: .4byte gUnknown_203B208
_08017B4C: .4byte gUnknown_203B460
_08017B50:
	bl sub_801A8AC
	ldr r1, _08017B70
	ldr r2, [r1]
	str r0, [r2, 0x10]
	ldr r1, _08017B74
	ldr r1, [r1]
	lsls r0, 2
	adds r1, r0
	ldr r0, [r1]
	str r0, [r2, 0xC]
	movs r0, 0x10
	bl sub_8016E68
	b _08017B82
	.align 2, 0
_08017B70: .4byte gUnknown_203B208
_08017B74: .4byte gUnknown_203B460
_08017B78:
	bl sub_801A928
	movs r0, 0x1
	bl sub_8016E68
_08017B82:
	pop {r0}
	bx r0
	thumb_func_end sub_8017AF8

	thumb_func_start sub_8017B88
sub_8017B88:
	push {r4,lr}
	movs r0, 0x1
	bl sub_801CA08
	cmp r0, 0x2
	beq _08017C10
	cmp r0, 0x2
	bhi _08017B9E
	cmp r0, 0x1
	beq _08017C1C
	b _08017C22
_08017B9E:
	cmp r0, 0x3
	beq _08017BA8
	cmp r0, 0x4
	beq _08017BE4
	b _08017C22
_08017BA8:
	bl sub_801CFB8
	cmp r0, 0
	beq _08017BB8
	movs r0, 0x1C
	bl sub_8016E68
	b _08017C22
_08017BB8:
	bl sub_801CB24
	ldr r4, _08017BE0
	ldr r1, [r4]
	strb r0, [r1, 0x14]
	ldr r1, [r4]
	adds r0, r1, 0
	adds r0, 0xC
	ldrb r1, [r1, 0x14]
	movs r2, 0
	bl sub_8090A8C
	ldr r1, [r4]
	movs r0, 0x1
	strb r0, [r1, 0xD]
	movs r0, 0x19
	bl sub_8016E68
	b _08017C22
	.align 2, 0
_08017BE0: .4byte gUnknown_203B208
_08017BE4:
	bl sub_801CB24
	ldr r4, _08017C0C
	ldr r1, [r4]
	strb r0, [r1, 0x14]
	ldr r1, [r4]
	adds r0, r1, 0
	adds r0, 0xC
	ldrb r1, [r1, 0x14]
	movs r2, 0
	bl sub_8090A8C
	ldr r1, [r4]
	movs r0, 0x1
	strb r0, [r1, 0xD]
	movs r0, 0x1A
	bl sub_8016E68
	b _08017C22
	.align 2, 0
_08017C0C: .4byte gUnknown_203B208
_08017C10:
	bl sub_801CBB8
	movs r0, 0x1
	bl sub_8016E68
	b _08017C22
_08017C1C:
	movs r0, 0
	bl sub_801AD34
_08017C22:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_8017B88

	thumb_func_start sub_8017C28
sub_8017C28:
	push {r4,lr}
	movs r0, 0
	bl sub_801CA08
	ldr r4, _08017C54
	ldr r0, [r4]
	adds r0, 0x58
	bl sub_8012FD8
	ldr r0, [r4]
	adds r0, 0xA8
	bl sub_8013BBC
	cmp r0, 0x1
	beq _08017C58
	cmp r0, 0x1
	bcc _08017C76
	cmp r0, 0x2
	beq _08017C70
	cmp r0, 0x3
	beq _08017C5E
	b _08017C76
	.align 2, 0
_08017C54: .4byte gUnknown_203B208
_08017C58:
	bl sub_8017598
	b _08017C76
_08017C5E:
	ldr r0, [r4]
	adds r1, r0, 0
	adds r1, 0xA8
	ldr r1, [r1]
	strb r1, [r0, 0xD]
	movs r0, 0x1B
	bl sub_8016E68
	b _08017C76
_08017C70:
	movs r0, 0x17
	bl sub_8016E68
_08017C76:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_8017C28

	thumb_func_start sub_8017C7C
sub_8017C7C:
	push {r4,lr}
	sub sp, 0x4
	movs r0, 0
	str r0, [sp]
	bl sub_801A6E8
	ldr r4, _08017CBC
	ldr r0, [r4]
	adds r0, 0x58
	bl sub_8012FD8
	lsls r0, 24
	cmp r0, 0
	bne _08017CAC
	ldr r0, [r4]
	adds r0, 0x58
	mov r1, sp
	bl sub_8013114
	ldr r1, [sp]
	cmp r1, 0x1
	beq _08017CAC
	ldr r0, [r4]
	str r1, [r0, 0x1C]
_08017CAC:
	ldr r0, [sp]
	cmp r0, 0x2
	beq _08017CC6
	cmp r0, 0x2
	bgt _08017CC0
	cmp r0, 0x1
	beq _08017D14
	b _08017D1A
	.align 2, 0
_08017CBC: .4byte gUnknown_203B208
_08017CC0:
	cmp r0, 0x6
	beq _08017D06
	b _08017D1A
_08017CC6:
	movs r0, 0
	bl sub_8099690
	ldr r4, _08017CE4
	ldr r0, [r4]
	ldrb r0, [r0, 0xE]
	bl sub_8091524
	lsls r0, 24
	cmp r0, 0
	bne _08017CE8
	movs r0, 0x9
	bl sub_8016E68
	b _08017D1A
	.align 2, 0
_08017CE4: .4byte gUnknown_203B208
_08017CE8:
	ldr r0, [r4]
	ldr r0, [r0, 0x10]
	bl sub_801ADA0
	lsls r0, 24
	cmp r0, 0
	bne _08017CFE
	movs r0, 0xA
	bl sub_8016E68
	b _08017D1A
_08017CFE:
	movs r0, 0x11
	bl sub_8016E68
	b _08017D1A
_08017D06:
	movs r0, 0
	bl sub_8099690
	movs r0, 0x10
	bl sub_8016E68
	b _08017D1A
_08017D14:
	movs r0, 0xE
	bl sub_8016E68
_08017D1A:
	add sp, 0x4
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_8017C7C

	thumb_func_start sub_8017D24
sub_8017D24:
	push {r4,lr}
	sub sp, 0x4
	movs r0, 0
	str r0, [sp]
	bl sub_801CA08
	ldr r4, _08017D64
	ldr r0, [r4]
	adds r0, 0x58
	bl sub_8012FD8
	lsls r0, 24
	cmp r0, 0
	bne _08017D54
	ldr r0, [r4]
	adds r0, 0x58
	mov r1, sp
	bl sub_8013114
	ldr r1, [sp]
	cmp r1, 0x1
	beq _08017D54
	ldr r0, [r4]
	str r1, [r0, 0x20]
_08017D54:
	ldr r0, [sp]
	cmp r0, 0x3
	beq _08017D6E
	cmp r0, 0x3
	bgt _08017D68
	cmp r0, 0x1
	beq _08017DB0
	b _08017DB6
	.align 2, 0
_08017D64: .4byte gUnknown_203B208
_08017D68:
	cmp r0, 0x6
	beq _08017DA8
	b _08017DB6
_08017D6E:
	bl sub_8090A34
	cmp r0, 0x13
	ble _08017D82
	bl sub_801CBB8
	movs r0, 0x6
	bl sub_8016E68
	b _08017DB6
_08017D82:
	ldr r0, _08017D9C
	ldr r0, [r0]
	ldrb r0, [r0, 0xE]
	bl sub_8090A60
	lsls r0, 24
	cmp r0, 0
	beq _08017DA0
	movs r0, 0x18
	bl sub_8016E68
	b _08017DB6
	.align 2, 0
_08017D9C: .4byte gUnknown_203B208
_08017DA0:
	movs r0, 0x1B
	bl sub_8016E68
	b _08017DB6
_08017DA8:
	movs r0, 0x1A
	bl sub_8016E68
	b _08017DB6
_08017DB0:
	movs r0, 0x17
	bl sub_8016E68
_08017DB6:
	add sp, 0x4
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_8017D24

	thumb_func_start sub_8017DC0
sub_8017DC0:
	push {lr}
	bl sub_801B410
	cmp r0, 0x1
	bls _08017DD8
	cmp r0, 0x3
	bhi _08017DD8
	bl sub_801B450
	movs r0, 0xE
	bl sub_8016E68
_08017DD8:
	pop {r0}
	bx r0
	thumb_func_end sub_8017DC0

	thumb_func_start sub_8017DDC
sub_8017DDC:
	push {lr}
	bl sub_801B410
	cmp r0, 0x1
	bls _08017DF4
	cmp r0, 0x3
	bhi _08017DF4
	bl sub_801B450
	movs r0, 0x17
	bl sub_8016E68
_08017DF4:
	pop {r0}
	bx r0
	thumb_func_end sub_8017DDC

	thumb_func_start sub_8017DF8
sub_8017DF8:
	push {lr}
	sub sp, 0x4
	mov r0, sp
	bl sub_80144A4
	cmp r0, 0
	bne _08017E10
	ldr r0, _08017E18
	ldr r0, [r0]
	ldr r0, [r0, 0x8]
	bl sub_8016E68
_08017E10:
	add sp, 0x4
	pop {r0}
	bx r0
	.align 2, 0
_08017E18: .4byte gUnknown_203B208
	thumb_func_end sub_8017DF8

	thumb_func_start sub_8017E1C
sub_8017E1C:
	push {r4,lr}
	bl sub_8004914
	movs r0, 0
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	ldr r4, _08017E50
	movs r0, 0xA8
	lsls r0, 1
	movs r1, 0x8
	bl MemoryAlloc
	str r0, [r4]
	movs r1, 0
	str r1, [r0, 0x14]
	str r1, [r0, 0x18]
	str r1, [r0, 0x1C]
	movs r0, 0
	bl sub_8017F10
	movs r0, 0x1
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_08017E50: .4byte gUnknown_203B20C
	thumb_func_end sub_8017E1C

	thumb_func_start sub_8017E54
sub_8017E54:
	push {lr}
	ldr r0, _08017E6C
	ldr r0, [r0]
	ldr r0, [r0]
	cmp r0, 0xE
	bhi _08017EEC
	lsls r0, 2
	ldr r1, _08017E70
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08017E6C: .4byte gUnknown_203B20C
_08017E70: .4byte _08017E74
	.align 2, 0
_08017E74:
	.4byte _08017EB0
	.4byte _08017EB8
	.4byte _08017EEC
	.4byte _08017EE8
	.4byte _08017EBE
	.4byte _08017EBE
	.4byte _08017EC4
	.4byte _08017ECA
	.4byte _08017EEC
	.4byte _08017EEC
	.4byte _08017ED0
	.4byte _08017ED0
	.4byte _08017ED6
	.4byte _08017EDC
	.4byte _08017EE2
_08017EB0:
	movs r0, 0x1
	bl sub_8017F10
	b _08017EEC
_08017EB8:
	bl sub_8018588
	b _08017EEC
_08017EBE:
	bl sub_8018620
	b _08017EEC
_08017EC4:
	bl sub_8018904
	b _08017EEC
_08017ECA:
	bl sub_8018AC8
	b _08017EEC
_08017ED0:
	bl sub_80186F8
	b _08017EEC
_08017ED6:
	bl sub_8018854
	b _08017EEC
_08017EDC:
	bl sub_80189C8
	b _08017EEC
_08017EE2:
	bl sub_8018AE4
	b _08017EEC
_08017EE8:
	movs r0, 0x3
	b _08017EEE
_08017EEC:
	movs r0, 0
_08017EEE:
	pop {r1}
	bx r1
	thumb_func_end sub_8017E54

	thumb_func_start sub_8017EF4
sub_8017EF4:
	push {r4,lr}
	ldr r4, _08017F0C
	ldr r0, [r4]
	cmp r0, 0
	beq _08017F06
	bl MemoryFree
	movs r0, 0
	str r0, [r4]
_08017F06:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08017F0C: .4byte gUnknown_203B20C
	thumb_func_end sub_8017EF4

	thumb_func_start sub_8017F10
sub_8017F10:
	push {lr}
	ldr r1, _08017F24
	ldr r1, [r1]
	str r0, [r1]
	bl sub_8017F28
	bl sub_8018100
	pop {r0}
	bx r0
	.align 2, 0
_08017F24: .4byte gUnknown_203B20C
	thumb_func_end sub_8017F10

	thumb_func_start sub_8017F28
sub_8017F28:
	push {r4-r7,lr}
	ldr r4, _08017F48
	ldr r0, [r4]
	adds r0, 0xF0
	bl sub_8006518
	ldr r0, [r4]
	ldr r0, [r0]
	cmp r0, 0xD
	bls _08017F3E
	b _080180BC
_08017F3E:
	lsls r0, 2
	ldr r1, _08017F4C
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08017F48: .4byte gUnknown_203B20C
_08017F4C: .4byte _08017F50
	.align 2, 0
_08017F50:
	.4byte _080180BC
	.4byte _08017F88
	.4byte _080180BC
	.4byte _080180BC
	.4byte _08017FE8
	.4byte _08017FE8
	.4byte _0801809C
	.4byte _080180BC
	.4byte _080180BC
	.4byte _080180BC
	.4byte _08018034
	.4byte _08018034
	.4byte _08018084
	.4byte _0801809C
_08017F88:
	ldr r4, _08017FDC
	ldr r1, [r4]
	ldr r2, _08017FE0
	adds r1, 0xF0
	adds r0, r2, 0
	ldm r0!, {r3,r5,r6}
	stm r1!, {r3,r5,r6}
	ldm r0!, {r3,r5,r7}
	stm r1!, {r3,r5,r7}
	ldr r1, [r4]
	movs r6, 0x84
	lsls r6, 1
	adds r1, r6
	adds r0, r2, 0
	ldm r0!, {r3,r5,r7}
	stm r1!, {r3,r5,r7}
	ldm r0!, {r3,r6,r7}
	stm r1!, {r3,r6,r7}
	ldr r0, [r4]
	adds r0, 0xF0
	ldm r2!, {r5-r7}
	stm r0!, {r5-r7}
	ldm r2!, {r1,r3,r5}
	stm r0!, {r1,r3,r5}
	bl sub_80182E4
	ldr r2, [r4]
	movs r0, 0x90
	lsls r0, 1
	adds r2, r0
	ldr r1, _08017FE4
	ldm r1!, {r3,r6,r7}
	stm r2!, {r3,r6,r7}
	ldm r1!, {r5-r7}
	stm r2!, {r5-r7}
	ldr r1, [r4]
	adds r0, r1, r0
	adds r1, 0x20
	bl sub_8012CAC
	b _080180E0
	.align 2, 0
_08017FDC: .4byte gUnknown_203B20C
_08017FE0: .4byte gUnknown_80DB7B8
_08017FE4: .4byte gUnknown_80DB7D0
_08017FE8:
	ldr r3, _0801802C
	ldr r1, [r3]
	ldr r2, _08018030
	adds r1, 0xF0
	adds r0, r2, 0
	ldm r0!, {r4-r6}
	stm r1!, {r4-r6}
	ldm r0!, {r4,r5,r7}
	stm r1!, {r4,r5,r7}
	ldr r1, [r3]
	movs r6, 0x84
	lsls r6, 1
	adds r1, r6
	adds r0, r2, 0
	ldm r0!, {r4,r5,r7}
	stm r1!, {r4,r5,r7}
	ldm r0!, {r4,r6,r7}
	stm r1!, {r4,r6,r7}
	ldr r1, [r3]
	movs r5, 0x90
	lsls r5, 1
	adds r1, r5
	adds r0, r2, 0
	ldm r0!, {r4,r6,r7}
	stm r1!, {r4,r6,r7}
	ldm r0!, {r5-r7}
	stm r1!, {r5-r7}
	ldr r0, [r3]
	adds r0, 0xF0
	ldm r2!, {r1,r3,r4}
	stm r0!, {r1,r3,r4}
	ldm r2!, {r5-r7}
	stm r0!, {r5-r7}
	b _080180E0
	.align 2, 0
_0801802C: .4byte gUnknown_203B20C
_08018030: .4byte gUnknown_80DB7B8
_08018034:
	ldr r3, _08018078
	ldr r1, [r3]
	ldr r2, _0801807C
	adds r1, 0xF0
	adds r0, r2, 0
	ldm r0!, {r4-r6}
	stm r1!, {r4-r6}
	ldm r0!, {r4,r5,r7}
	stm r1!, {r4,r5,r7}
	ldr r1, [r3]
	movs r6, 0x84
	lsls r6, 1
	adds r1, r6
	adds r0, r2, 0
	ldm r0!, {r4,r5,r7}
	stm r1!, {r4,r5,r7}
	ldm r0!, {r4,r6,r7}
	stm r1!, {r4,r6,r7}
	ldr r0, [r3]
	movs r5, 0x90
	lsls r5, 1
	adds r0, r5
	ldm r2!, {r1,r6,r7}
	stm r0!, {r1,r6,r7}
	ldm r2!, {r4-r6}
	stm r0!, {r4-r6}
	ldr r1, [r3]
	adds r1, 0xF0
	ldr r0, _08018080
	ldm r0!, {r2,r3,r7}
	stm r1!, {r2,r3,r7}
	ldm r0!, {r4-r6}
	stm r1!, {r4-r6}
	b _080180E0
	.align 2, 0
_08018078: .4byte gUnknown_203B20C
_0801807C: .4byte gUnknown_80DB7B8
_08018080: .4byte gUnknown_80DB800
_08018084:
	ldr r0, _08018094
	ldr r1, [r0]
	movs r7, 0x84
	lsls r7, 1
	adds r1, r7
	ldr r0, _08018098
	b _080180A8
	.align 2, 0
_08018094: .4byte gUnknown_203B20C
_08018098: .4byte gUnknown_80DB818
_0801809C:
	ldr r0, _080180B4
	ldr r1, [r0]
	movs r0, 0x90
	lsls r0, 1
	adds r1, r0
	ldr r0, _080180B8
_080180A8:
	ldm r0!, {r2-r4}
	stm r1!, {r2-r4}
	ldm r0!, {r5-r7}
	stm r1!, {r5-r7}
	b _080180E0
	.align 2, 0
_080180B4: .4byte gUnknown_203B20C
_080180B8: .4byte gUnknown_80DB7E8
_080180BC:
	ldr r0, _080180F8
	mov r12, r0
	ldr r4, _080180FC
	movs r3, 0
	movs r2, 0x3
_080180C6:
	mov r5, r12
	ldr r1, [r5]
	adds r1, r3
	adds r1, 0xF0
	adds r0, r4, 0
	ldm r0!, {r5-r7}
	stm r1!, {r5-r7}
	ldm r0!, {r5-r7}
	stm r1!, {r5-r7}
	adds r3, 0x18
	subs r2, 0x1
	cmp r2, 0
	bge _080180C6
_080180E0:
	bl sub_8004914
	ldr r0, _080180F8
	ldr r0, [r0]
	adds r0, 0xF0
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_080180F8: .4byte gUnknown_203B20C
_080180FC: .4byte gUnknown_80DB7B8
	thumb_func_end sub_8017F28

	thumb_func_start sub_8018100
sub_8018100:
	push {r4,lr}
	sub sp, 0x8
	ldr r1, _0801811C
	ldr r0, [r1]
	ldr r0, [r0]
	adds r4, r1, 0
	cmp r0, 0xE
	bls _08018112
	b _08018278
_08018112:
	lsls r0, 2
	ldr r1, _08018120
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0801811C: .4byte gUnknown_203B20C
_08018120: .4byte _08018124
	.align 2, 0
_08018124:
	.4byte _08018278
	.4byte _08018160
	.4byte _08018278
	.4byte _08018278
	.4byte _08018172
	.4byte _08018180
	.4byte _08018188
	.4byte _080181A8
	.4byte _08018278
	.4byte _08018278
	.4byte _080181B2
	.4byte _080181C0
	.4byte _080181CE
	.4byte _0801823C
	.4byte _08018270
_08018160:
	ldr r2, [r4]
	adds r0, r2, 0
	adds r0, 0x70
	adds r1, r2, 0
	adds r1, 0x20
	adds r3, r2, 0
	adds r3, 0x60
	ldr r2, [r2, 0x14]
	b _0801825C
_08018172:
	movs r0, 0x3
	movs r1, 0x3
	movs r2, 0
	movs r3, 0xA
	bl sub_801A5D8
	b _08018278
_08018180:
	movs r0, 0x1
	bl sub_801A8D0
	b _08018278
_08018188:
	bl sub_801A9E0
	bl sub_801841C
	ldr r0, _080181A4
	ldr r2, [r0]
	adds r0, r2, 0
	adds r0, 0x70
	adds r1, r2, 0
	adds r1, 0x20
	adds r3, r2, 0
	adds r3, 0x60
	ldr r2, [r2, 0x18]
	b _0801825C
	.align 2, 0
_080181A4: .4byte gUnknown_203B20C
_080181A8:
	ldr r0, [r4]
	adds r0, 0x8
	bl sub_801B3C0
	b _08018278
_080181B2:
	movs r0, 0x1
	movs r1, 0x3
	movs r2, 0
	movs r3, 0xA
	bl sub_801C8C4
	b _080181C6
_080181C0:
	movs r0, 0x1
	bl sub_801CB5C
_080181C6:
	movs r0, 0
	bl sub_801AD34
	b _08018278
_080181CE:
	ldr r2, [r4]
	adds r1, r2, 0
	adds r1, 0xD0
	movs r0, 0x2
	str r0, [r1]
	subs r1, 0x8
	movs r0, 0x1
	str r0, [r1]
	ldr r0, _080181F8
	ldr r1, [r0]
	ldrb r0, [r2, 0xA]
	lsls r0, 1
	adds r1, 0x50
	adds r3, r1, r0
	ldrh r0, [r3]
	cmp r0, 0x63
	bls _080181FC
	adds r1, r2, 0
	adds r1, 0xCC
	movs r0, 0x63
	b _08018202
	.align 2, 0
_080181F8: .4byte gUnknown_203B460
_080181FC:
	adds r1, r2, 0
	adds r1, 0xCC
	ldrh r0, [r3]
_08018202:
	str r0, [r1]
	ldr r2, [r4]
	adds r1, r2, 0
	adds r1, 0xC4
	adds r0, r2, 0
	adds r0, 0xCC
	ldr r0, [r0]
	str r0, [r1]
	adds r1, 0x10
	movs r0, 0x1
	str r0, [r1]
	adds r1, 0x4
	movs r3, 0x84
	lsls r3, 1
	adds r0, r2, r3
	str r0, [r1]
	adds r1, 0x4
	movs r0, 0x28
	str r0, [r1]
	adds r1, 0x4
	movs r0, 0x12
	str r0, [r1]
	adds r0, r2, 0
	adds r0, 0xC0
	bl sub_8013AA0
	bl sub_8018280
	b _08018278
_0801823C:
	bl sub_801CCD8
	movs r0, 0
	bl sub_801AD34
	bl sub_80184D4
	ldr r0, _0801826C
	ldr r2, [r0]
	adds r0, r2, 0
	adds r0, 0x70
	adds r1, r2, 0
	adds r1, 0x20
	adds r3, r2, 0
	adds r3, 0x60
	ldr r2, [r2, 0x1C]
_0801825C:
	str r2, [sp]
	movs r2, 0x2
	str r2, [sp, 0x4]
	movs r2, 0
	bl sub_8012D60
	b _08018278
	.align 2, 0
_0801826C: .4byte gUnknown_203B20C
_08018270:
	ldr r0, [r4]
	adds r0, 0x8
	bl sub_801B3C0
_08018278:
	add sp, 0x8
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_8018100

	thumb_func_start sub_8018280
sub_8018280:
	push {r4,lr}
	sub sp, 0x4
	ldr r4, _080182DC
	ldr r0, [r4]
	adds r0, 0xD4
	ldr r0, [r0]
	bl sub_8008C54
	ldr r0, [r4]
	adds r0, 0xD4
	ldr r0, [r0]
	bl sub_80073B8
	ldr r2, _080182E0
	ldr r0, [r4]
	adds r0, 0xD4
	ldr r3, [r0]
	movs r0, 0
	str r0, [sp]
	movs r0, 0x4
	movs r1, 0
	bl xxx_call_draw_string
	ldr r0, [r4]
	adds r0, 0xC0
	bl sub_8013C68
	ldr r0, [r4]
	adds r0, 0xD4
	ldr r0, [r0]
	bl sub_80073E0
	bl sub_801CCD8
	movs r0, 0
	bl sub_801AD34
	ldr r0, [r4]
	adds r0, 0x70
	movs r1, 0
	bl sub_8012EA4
	add sp, 0x4
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080182DC: .4byte gUnknown_203B20C
_080182E0: .4byte gUnknown_80DB830
	thumb_func_end sub_8018280

	thumb_func_start sub_80182E4
sub_80182E4:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	movs r0, 0
	mov r8, r0
	ldr r4, _080183DC
	ldr r0, [r4]
	adds r0, 0x60
	movs r1, 0
	movs r2, 0x10
	bl MemoryFill16
	ldr r1, [r4]
	ldr r0, _080183E0
	ldr r0, [r0]
	str r0, [r1, 0x20]
	movs r0, 0x2
	str r0, [r1, 0x24]
	bl sub_8090A34
	cmp r0, 0
	beq _0801831C
	movs r0, 0
	bl sub_801CF50
	lsls r0, 24
	cmp r0, 0
	beq _08018324
_0801831C:
	ldr r0, [r4]
	adds r0, 0x60
	movs r1, 0x1
	strh r1, [r0]
_08018324:
	movs r1, 0x1
	add r8, r1
	ldr r4, _080183DC
	ldr r2, [r4]
	mov r0, r8
	lsls r3, r0, 3
	adds r0, r2, 0
	adds r0, 0x20
	adds r0, r3
	ldr r1, _080183E4
	ldr r1, [r1]
	str r1, [r0]
	adds r2, 0x24
	adds r2, r3
	movs r0, 0x3
	str r0, [r2]
	movs r0, 0x1
	bl sub_801CF14
	lsls r0, 24
	cmp r0, 0
	bne _08018358
	bl sub_8090A34
	cmp r0, 0x13
	ble _08018366
_08018358:
	ldr r0, [r4]
	mov r2, r8
	lsls r1, r2, 1
	adds r0, 0x60
	adds r0, r1
	movs r1, 0x1
	strh r1, [r0]
_08018366:
	movs r0, 0x1
	add r8, r0
	ldr r4, _080183DC
	ldr r7, [r4]
	mov r2, r8
	lsls r1, r2, 3
	adds r2, r7, 0
	adds r2, 0x20
	adds r3, r2, r1
	ldr r0, _080183E8
	ldr r0, [r0]
	str r0, [r3]
	adds r6, r7, 0
	adds r6, 0x24
	adds r1, r6, r1
	movs r3, 0x1
	str r3, [r1]
	add r8, r3
	mov r1, r8
	lsls r0, r1, 3
	adds r2, r0
	movs r1, 0
	str r1, [r2]
	adds r0, r6, r0
	str r3, [r0]
	movs r5, 0
	mov r12, r4
	cmp r5, r8
	bge _080183C0
	adds r4, r7, 0
	adds r2, r4, 0
	adds r2, 0x60
	adds r3, r6, 0
_080183A8:
	ldrh r0, [r2]
	cmp r0, 0
	bne _080183B6
	ldr r1, [r3]
	ldr r0, [r4, 0x14]
	cmp r1, r0
	beq _08018410
_080183B6:
	adds r2, 0x2
	adds r3, 0x8
	adds r5, 0x1
	cmp r5, r8
	blt _080183A8
_080183C0:
	movs r5, 0
	cmp r5, r8
	bge _08018410
	mov r2, r12
	ldr r1, [r2]
	adds r0, r1, 0
	adds r0, 0x60
	ldrh r0, [r0]
	cmp r0, 0
	bne _080183EC
	ldr r0, [r1, 0x24]
	str r0, [r1, 0x14]
	b _08018410
	.align 2, 0
_080183DC: .4byte gUnknown_203B20C
_080183E0: .4byte gUnknown_80D4958
_080183E4: .4byte gUnknown_80D4964
_080183E8: .4byte gUnknown_80D4934
_080183EC:
	adds r5, 0x1
	cmp r5, r8
	bge _08018410
	mov r0, r12
	ldr r2, [r0]
	lsls r0, r5, 1
	adds r1, r2, 0
	adds r1, 0x60
	adds r1, r0
	ldrh r0, [r1]
	cmp r0, 0
	bne _080183EC
	lsls r0, r5, 3
	adds r1, r2, 0
	adds r1, 0x24
	adds r1, r0
	ldr r0, [r1]
	str r0, [r2, 0x14]
_08018410:
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_80182E4

	thumb_func_start sub_801841C
sub_801841C:
	push {r4-r7,lr}
	ldr r4, _080184A0
	ldr r0, [r4]
	adds r0, 0x60
	movs r1, 0
	movs r2, 0x10
	bl MemoryFill16
	ldr r1, [r4]
	ldr r0, _080184A4
	ldr r0, [r0]
	str r0, [r1, 0x20]
	movs r0, 0x2
	str r0, [r1, 0x24]
	ldr r0, [r1, 0xC]
	bl sub_801ADA0
	lsls r0, 24
	cmp r0, 0
	bne _0801844C
	ldr r0, [r4]
	adds r0, 0x60
	movs r1, 0x1
	strh r1, [r0]
_0801844C:
	ldr r2, [r4]
	movs r1, 0x1
	ldr r0, _080184A8
	ldr r0, [r0]
	str r0, [r2, 0x28]
	movs r0, 0x4
	str r0, [r2, 0x2C]
	movs r5, 0x2
	movs r0, 0
	str r0, [r2, 0x30]
	str r1, [r2, 0x34]
	movs r3, 0
	adds r6, r4, 0
	mov r12, r2
	mov r4, r12
	adds r4, 0x60
	adds r2, 0x24
_0801846E:
	ldrh r0, [r4]
	cmp r0, 0
	bne _0801847E
	ldr r1, [r2]
	mov r7, r12
	ldr r0, [r7, 0x18]
	cmp r1, r0
	beq _080184CE
_0801847E:
	adds r4, 0x2
	adds r2, 0x8
	adds r3, 0x1
	cmp r3, r5
	blt _0801846E
	movs r3, 0
	cmp r3, r5
	bge _080184CE
	ldr r1, [r6]
	adds r0, r1, 0
	adds r0, 0x60
	ldrh r0, [r0]
	cmp r0, 0
	bne _080184AC
	ldr r0, [r1, 0x24]
	str r0, [r1, 0x18]
	b _080184CE
	.align 2, 0
_080184A0: .4byte gUnknown_203B20C
_080184A4: .4byte gUnknown_80D4958
_080184A8: .4byte gUnknown_80D4970
_080184AC:
	adds r3, 0x1
	cmp r3, r5
	bge _080184CE
	ldr r2, [r6]
	lsls r0, r3, 1
	adds r1, r2, 0
	adds r1, 0x60
	adds r1, r0
	ldrh r0, [r1]
	cmp r0, 0
	bne _080184AC
	lsls r0, r3, 3
	adds r1, r2, 0
	adds r1, 0x24
	adds r1, r0
	ldr r0, [r1]
	str r0, [r2, 0x18]
_080184CE:
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_801841C

	thumb_func_start sub_80184D4
sub_80184D4:
	push {r4-r7,lr}
	ldr r4, _08018554
	ldr r0, [r4]
	adds r0, 0x60
	movs r1, 0
	movs r2, 0x10
	bl MemoryFill16
	ldr r1, [r4]
	ldr r0, _08018558
	ldr r0, [r0]
	str r0, [r1, 0x20]
	movs r0, 0x3
	str r0, [r1, 0x24]
	bl sub_8090A34
	cmp r0, 0x13
	ble _08018500
	ldr r0, [r4]
	adds r0, 0x60
	movs r1, 0x1
	strh r1, [r0]
_08018500:
	ldr r2, [r4]
	movs r1, 0x1
	ldr r0, _0801855C
	ldr r0, [r0]
	str r0, [r2, 0x28]
	movs r0, 0x4
	str r0, [r2, 0x2C]
	movs r5, 0x2
	movs r0, 0
	str r0, [r2, 0x30]
	str r1, [r2, 0x34]
	movs r3, 0
	adds r6, r4, 0
	mov r12, r2
	mov r4, r12
	adds r4, 0x60
	adds r2, 0x24
_08018522:
	ldrh r0, [r4]
	cmp r0, 0
	bne _08018532
	ldr r1, [r2]
	mov r7, r12
	ldr r0, [r7, 0x1C]
	cmp r1, r0
	beq _08018582
_08018532:
	adds r4, 0x2
	adds r2, 0x8
	adds r3, 0x1
	cmp r3, r5
	blt _08018522
	movs r3, 0
	cmp r3, r5
	bge _08018582
	ldr r1, [r6]
	adds r0, r1, 0
	adds r0, 0x60
	ldrh r0, [r0]
	cmp r0, 0
	bne _08018560
	ldr r0, [r1, 0x24]
	str r0, [r1, 0x1C]
	b _08018582
	.align 2, 0
_08018554: .4byte gUnknown_203B20C
_08018558: .4byte gUnknown_80D4964
_0801855C: .4byte gUnknown_80D4970
_08018560:
	adds r3, 0x1
	cmp r3, r5
	bge _08018582
	ldr r2, [r6]
	lsls r0, r3, 1
	adds r1, r2, 0
	adds r1, 0x60
	adds r1, r0
	ldrh r0, [r1]
	cmp r0, 0
	bne _08018560
	lsls r0, r3, 3
	adds r1, r2, 0
	adds r1, 0x24
	adds r1, r0
	ldr r0, [r1]
	str r0, [r2, 0x1C]
_08018582:
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_80184D4

	thumb_func_start sub_8018588
sub_8018588:
	push {r4,lr}
	sub sp, 0x4
	movs r0, 0
	str r0, [sp]
	ldr r4, _080185C4
	ldr r0, [r4]
	adds r0, 0x70
	bl sub_8012FD8
	lsls r0, 24
	cmp r0, 0
	bne _080185B4
	ldr r0, [r4]
	adds r0, 0x70
	mov r1, sp
	bl sub_8013114
	ldr r1, [sp]
	cmp r1, 0x1
	beq _080185B4
	ldr r0, [r4]
	str r1, [r0, 0x14]
_080185B4:
	ldr r0, [sp]
	cmp r0, 0x2
	beq _080185CE
	cmp r0, 0x2
	bgt _080185C8
	cmp r0, 0x1
	beq _08018610
	b _08018616
	.align 2, 0
_080185C4: .4byte gUnknown_203B20C
_080185C8:
	cmp r0, 0x3
	beq _080185EA
	b _08018616
_080185CE:
	bl sub_8090A34
	cmp r0, 0
	beq _080185F6
	movs r0, 0
	bl sub_801CF50
	lsls r0, 24
	cmp r0, 0
	bne _080185F6
	movs r0, 0x4
	bl sub_8017F10
	b _08018616
_080185EA:
	movs r0, 0x1
	bl sub_801CF14
	lsls r0, 24
	cmp r0, 0
	beq _08018608
_080185F6:
	ldr r0, _08018604
	ldr r0, [r0]
	adds r0, 0x70
	movs r1, 0x1
	bl sub_8012EA4
	b _08018616
	.align 2, 0
_08018604: .4byte gUnknown_203B20C
_08018608:
	movs r0, 0xA
	bl sub_8017F10
	b _08018616
_08018610:
	movs r0, 0x3
	bl sub_8017F10
_08018616:
	add sp, 0x4
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_8018588

	thumb_func_start sub_8018620
sub_8018620:
	push {r4-r7,lr}
	movs r0, 0x1
	bl sub_801A6E8
	cmp r0, 0x3
	beq _0801863C
	cmp r0, 0x3
	bhi _08018636
	cmp r0, 0x2
	beq _080186E8
	b _080186F2
_08018636:
	cmp r0, 0x4
	beq _080186C0
	b _080186F2
_0801863C:
	bl sub_801AEA8
	cmp r0, 0
	beq _08018698
	movs r5, 0
	ldr r6, _0801868C
	movs r7, 0
_0801864A:
	adds r0, r5, 0
	bl sub_801AED0
	cmp r0, 0
	beq _0801866A
	lsls r4, r5, 2
	ldr r0, [r6]
	adds r0, r4
	bl sub_80917B8
	ldr r0, [r6]
	adds r0, r4
	strb r7, [r0, 0x2]
	ldr r0, [r6]
	adds r0, r4
	strb r7, [r0]
_0801866A:
	adds r5, 0x1
	cmp r5, 0x13
	ble _0801864A
	bl sub_80910B4
	bl sub_801AE84
	bl sub_8090A34
	cmp r0, 0
	bne _08018690
	bl sub_801A928
	movs r0, 0x1
	bl sub_8017F10
	b _080186F2
	.align 2, 0
_0801868C: .4byte gUnknown_203B460
_08018690:
	movs r0, 0x5
	bl sub_8017F10
	b _080186F2
_08018698:
	bl sub_801A8AC
	ldr r1, _080186B8
	ldr r2, [r1]
	str r0, [r2, 0xC]
	ldr r1, _080186BC
	ldr r1, [r1]
	lsls r0, 2
	adds r1, r0
	ldr r0, [r1]
	str r0, [r2, 0x8]
	movs r0, 0x6
	bl sub_8017F10
	b _080186F2
	.align 2, 0
_080186B8: .4byte gUnknown_203B20C
_080186BC: .4byte gUnknown_203B460
_080186C0:
	bl sub_801A8AC
	ldr r1, _080186E0
	ldr r2, [r1]
	str r0, [r2, 0xC]
	ldr r1, _080186E4
	ldr r1, [r1]
	lsls r0, 2
	adds r1, r0
	ldr r0, [r1]
	str r0, [r2, 0x8]
	movs r0, 0x7
	bl sub_8017F10
	b _080186F2
	.align 2, 0
_080186E0: .4byte gUnknown_203B20C
_080186E4: .4byte gUnknown_203B460
_080186E8:
	bl sub_801A928
	movs r0, 0x1
	bl sub_8017F10
_080186F2:
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_8018620

	thumb_func_start sub_80186F8
sub_80186F8:
	push {r4-r7,lr}
	sub sp, 0x4
	movs r0, 0x1
	bl sub_801CA08
	cmp r0, 0x2
	bne _08018708
	b _08018838
_08018708:
	cmp r0, 0x2
	bhi _08018714
	cmp r0, 0x1
	bne _08018712
	b _08018844
_08018712:
	b _0801884A
_08018714:
	cmp r0, 0x3
	beq _0801871E
	cmp r0, 0x4
	beq _0801880C
	b _0801884A
_0801871E:
	bl sub_801CFB8
	cmp r0, 0
	beq _080187E0
	movs r6, 0
	mov r5, sp
	ldr r7, _0801876C
_0801872C:
	lsls r0, r6, 24
	lsrs r4, r0, 24
	adds r0, r4, 0
	bl sub_801CFE0
	cmp r0, 0
	beq _080187B2
	ldr r1, _08018770
	ldr r0, [sp]
	ands r0, r1
	orrs r0, r4
	str r0, [sp]
	ldrb r0, [r5]
	bl sub_8090A60
	lsls r0, 24
	cmp r0, 0
	beq _08018786
	ldr r2, _08018774
	ldr r1, [r2]
	ldrb r0, [r5]
	lsls r0, 1
	adds r1, 0x50
	adds r1, r0
	ldrh r1, [r1]
	cmp r1, 0x63
	bls _08018778
	ldr r0, [sp]
	ands r0, r7
	movs r1, 0xC6
	lsls r1, 7
	b _08018780
	.align 2, 0
_0801876C: .4byte 0xffff00ff
_08018770: .4byte 0xffffff00
_08018774: .4byte gUnknown_203B460
_08018778:
	lsls r1, 24
	lsrs r1, 16
	ldr r0, [sp]
	ands r0, r7
_08018780:
	orrs r0, r1
	str r0, [sp]
	b _08018794
_08018786:
	ldr r0, [sp]
	ands r0, r7
	movs r1, 0x80
	lsls r1, 1
	orrs r0, r1
	str r0, [sp]
	ldr r2, _080187DC
_08018794:
	ldr r2, [r2]
	ldrb r0, [r5]
	lsls r0, 1
	adds r2, 0x50
	adds r2, r0
	ldr r0, [sp]
	lsrs r0, 8
	lsls r0, 24
	lsrs r0, 24
	ldrh r1, [r2]
	subs r1, r0
	strh r1, [r2]
	mov r0, sp
	bl sub_8091274
_080187B2:
	adds r6, 0x1
	cmp r6, 0xEF
	ble _0801872C
	bl sub_80910B4
	bl sub_801CF94
	movs r0, 0x1
	bl sub_801CF14
	lsls r0, 24
	cmp r0, 0
	bne _08018838
	bl sub_8090A34
	cmp r0, 0x13
	bgt _08018838
	movs r0, 0xB
	bl sub_8017F10
	b _0801884A
	.align 2, 0
_080187DC: .4byte gUnknown_203B460
_080187E0:
	bl sub_801CB24
	ldr r4, _08018808
	ldr r1, [r4]
	strb r0, [r1, 0x10]
	ldr r1, [r4]
	adds r0, r1, 0
	adds r0, 0x8
	ldrb r1, [r1, 0x10]
	movs r2, 0
	bl sub_8090A8C
	ldr r1, [r4]
	movs r0, 0x1
	strb r0, [r1, 0x9]
	movs r0, 0xD
	bl sub_8017F10
	b _0801884A
	.align 2, 0
_08018808: .4byte gUnknown_203B20C
_0801880C:
	bl sub_801CB24
	ldr r4, _08018834
	ldr r1, [r4]
	strb r0, [r1, 0x10]
	ldr r1, [r4]
	adds r0, r1, 0
	adds r0, 0x8
	ldrb r1, [r1, 0x10]
	movs r2, 0
	bl sub_8090A8C
	ldr r1, [r4]
	movs r0, 0x1
	strb r0, [r1, 0x9]
	movs r0, 0xE
	bl sub_8017F10
	b _0801884A
	.align 2, 0
_08018834: .4byte gUnknown_203B20C
_08018838:
	bl sub_801CBB8
	movs r0, 0x1
	bl sub_8017F10
	b _0801884A
_08018844:
	movs r0, 0
	bl sub_801AD34
_0801884A:
	add sp, 0x4
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_80186F8

	thumb_func_start sub_8018854
sub_8018854:
	push {r4,lr}
	sub sp, 0x4
	movs r0, 0
	bl sub_801CA08
	ldr r4, _080188E0
	ldr r0, [r4]
	adds r0, 0x70
	bl sub_8012FD8
	ldr r0, [r4]
	adds r0, 0xC0
	bl sub_8013BBC
	cmp r0, 0x1
	beq _080188F8
	cmp r0, 0x1
	bcc _080188FC
	cmp r0, 0x2
	beq _080188F0
	cmp r0, 0x3
	bne _080188FC
	ldr r1, [r4]
	adds r0, r1, 0
	adds r0, 0xC0
	ldr r0, [r0]
	strb r0, [r1, 0x9]
	ldr r0, _080188E4
	ldr r1, [r0]
	ldr r3, [r4]
	ldrb r0, [r3, 0xA]
	lsls r0, 1
	adds r1, 0x50
	adds r1, r0
	ldrb r2, [r3, 0x9]
	ldrh r0, [r1]
	subs r0, r2
	strh r0, [r1]
	ldrb r2, [r3, 0xA]
	ldr r1, _080188E8
	ldr r0, [sp]
	ands r0, r1
	orrs r0, r2
	str r0, [sp]
	ldrb r1, [r3, 0x9]
	lsls r1, 8
	ldr r2, _080188EC
	ands r0, r2
	orrs r0, r1
	str r0, [sp]
	mov r0, sp
	bl sub_8091274
	movs r0, 0x1
	bl sub_801CF14
	lsls r0, 24
	cmp r0, 0
	bne _080188D2
	bl sub_8090A34
	cmp r0, 0x13
	ble _080188F0
_080188D2:
	bl sub_801CBB8
	movs r0, 0x1
	bl sub_8017F10
	b _080188FC
	.align 2, 0
_080188E0: .4byte gUnknown_203B20C
_080188E4: .4byte gUnknown_203B460
_080188E8: .4byte 0xffffff00
_080188EC: .4byte 0xffff00ff
_080188F0:
	movs r0, 0xB
	bl sub_8017F10
	b _080188FC
_080188F8:
	bl sub_8018280
_080188FC:
	add sp, 0x4
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_8018854

	thumb_func_start sub_8018904
sub_8018904:
	push {r4,lr}
	sub sp, 0x4
	movs r0, 0
	str r0, [sp]
	bl sub_801A6E8
	ldr r4, _08018944
	ldr r0, [r4]
	adds r0, 0x70
	bl sub_8012FD8
	lsls r0, 24
	cmp r0, 0
	bne _08018934
	ldr r0, [r4]
	adds r0, 0x70
	mov r1, sp
	bl sub_8013114
	ldr r1, [sp]
	cmp r1, 0x1
	beq _08018934
	ldr r0, [r4]
	str r1, [r0, 0x18]
_08018934:
	ldr r0, [sp]
	cmp r0, 0x2
	beq _0801894E
	cmp r0, 0x2
	bgt _08018948
	cmp r0, 0x1
	beq _080189BA
	b _080189C0
	.align 2, 0
_08018944: .4byte gUnknown_203B20C
_08018948:
	cmp r0, 0x4
	beq _080189AC
	b _080189C0
_0801894E:
	ldr r4, _08018978
	ldr r0, [r4]
	ldrb r0, [r0, 0xA]
	bl sub_8091524
	lsls r0, 24
	cmp r0, 0
	beq _0801896C
	ldr r0, [r4]
	ldr r0, [r0, 0xC]
	bl sub_801ADA0
	lsls r0, 24
	cmp r0, 0
	bne _0801897C
_0801896C:
	ldr r0, [r4]
	adds r0, 0x70
	movs r1, 0x1
	bl sub_8012EA4
	b _080189C0
	.align 2, 0
_08018978: .4byte gUnknown_203B20C
_0801897C:
	ldr r0, [r4]
	adds r0, 0x8
	bl sub_80917B8
	ldr r0, [r4]
	ldr r0, [r0, 0xC]
	bl sub_80911F8
	bl sub_80910B4
	bl sub_8090A34
	cmp r0, 0
	bne _080189A4
	bl sub_801A928
	movs r0, 0x1
	bl sub_8017F10
	b _080189C0
_080189A4:
	movs r0, 0x5
	bl sub_8017F10
	b _080189C0
_080189AC:
	movs r0, 0
	bl sub_8099690
	movs r0, 0x7
	bl sub_8017F10
	b _080189C0
_080189BA:
	movs r0, 0x5
	bl sub_8017F10
_080189C0:
	add sp, 0x4
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_8018904

	thumb_func_start sub_80189C8
sub_80189C8:
	push {r4,lr}
	sub sp, 0x8
	movs r0, 0
	str r0, [sp]
	bl sub_801CA08
	ldr r4, _08018A08
	ldr r0, [r4]
	adds r0, 0x70
	bl sub_8012FD8
	lsls r0, 24
	cmp r0, 0
	bne _080189F8
	ldr r0, [r4]
	adds r0, 0x70
	mov r1, sp
	bl sub_8013114
	ldr r1, [sp]
	cmp r1, 0x1
	beq _080189F8
	ldr r0, [r4]
	str r1, [r0, 0x1C]
_080189F8:
	ldr r0, [sp]
	cmp r0, 0x3
	beq _08018A12
	cmp r0, 0x3
	bgt _08018A0C
	cmp r0, 0x1
	beq _08018AB8
	b _08018ABE
	.align 2, 0
_08018A08: .4byte gUnknown_203B20C
_08018A0C:
	cmp r0, 0x4
	beq _08018AB0
	b _08018ABE
_08018A12:
	bl sub_8090A34
	cmp r0, 0x13
	ble _08018A2C
	ldr r0, _08018A28
	ldr r0, [r0]
	adds r0, 0x70
	movs r1, 0x1
	bl sub_8012EA4
	b _08018ABE
	.align 2, 0
_08018A28: .4byte gUnknown_203B20C
_08018A2C:
	ldr r4, _08018A44
	ldr r0, [r4]
	ldrb r0, [r0, 0xA]
	bl sub_8090A60
	lsls r0, 24
	cmp r0, 0
	beq _08018A48
	movs r0, 0xC
	bl sub_8017F10
	b _08018ABE
	.align 2, 0
_08018A44: .4byte gUnknown_203B20C
_08018A48:
	ldr r0, _08018A9C
	ldr r1, [r0]
	ldr r3, [r4]
	ldrb r0, [r3, 0xA]
	lsls r0, 1
	adds r1, 0x50
	adds r1, r0
	ldrb r2, [r3, 0x9]
	ldrh r0, [r1]
	subs r0, r2
	strh r0, [r1]
	ldrb r2, [r3, 0xA]
	ldr r1, _08018AA0
	ldr r0, [sp, 0x4]
	ands r0, r1
	orrs r0, r2
	str r0, [sp, 0x4]
	ldrb r1, [r3, 0x9]
	lsls r1, 8
	ldr r2, _08018AA4
	ands r0, r2
	orrs r0, r1
	str r0, [sp, 0x4]
	add r0, sp, 0x4
	bl sub_8091274
	movs r0, 0x1
	bl sub_801CF14
	lsls r0, 24
	cmp r0, 0
	bne _08018A90
	bl sub_8090A34
	cmp r0, 0x13
	ble _08018AA8
_08018A90:
	bl sub_801CBB8
	movs r0, 0x1
	bl sub_8017F10
	b _08018ABE
	.align 2, 0
_08018A9C: .4byte gUnknown_203B460
_08018AA0: .4byte 0xffffff00
_08018AA4: .4byte 0xffff00ff
_08018AA8:
	movs r0, 0xB
	bl sub_8017F10
	b _08018ABE
_08018AB0:
	movs r0, 0xE
	bl sub_8017F10
	b _08018ABE
_08018AB8:
	movs r0, 0xB
	bl sub_8017F10
_08018ABE:
	add sp, 0x8
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_80189C8

	thumb_func_start sub_8018AC8
sub_8018AC8:
	push {lr}
	bl sub_801B410
	cmp r0, 0x1
	bls _08018AE0
	cmp r0, 0x3
	bhi _08018AE0
	bl sub_801B450
	movs r0, 0x5
	bl sub_8017F10
_08018AE0:
	pop {r0}
	bx r0
	thumb_func_end sub_8018AC8

	thumb_func_start sub_8018AE4
sub_8018AE4:
	push {lr}
	bl sub_801B410
	cmp r0, 0x1
	bls _08018AFC
	cmp r0, 0x3
	bhi _08018AFC
	bl sub_801B450
	movs r0, 0xB
	bl sub_8017F10
_08018AFC:
	pop {r0}
	bx r0
	thumb_func_end sub_8018AE4

	thumb_func_start sub_8018B00
sub_8018B00:
	push {r4,r5,lr}
	adds r4, r0, 0
	ldr r5, _08018B30
	movs r0, 0xA4
	lsls r0, 1
	movs r1, 0x8
	bl MemoryAlloc
	adds r1, r0, 0
	str r1, [r5]
	movs r2, 0
	str r2, [r1, 0x28]
	str r2, [r1, 0x2C]
	str r2, [r1, 0x30]
	str r4, [r1]
	cmp r4, 0x1
	beq _08018B3A
	cmp r4, 0x1
	bcc _08018B34
	cmp r4, 0x2
	beq _08018B44
	cmp r4, 0x3
	beq _08018B80
	b _08018BAE
	.align 2, 0
_08018B30: .4byte gUnknown_203B210
_08018B34:
	movs r0, 0x1
	strb r0, [r1, 0x4]
	b _08018B46
_08018B3A:
	strb r4, [r1, 0x4]
	ldr r0, [r5]
	adds r0, 0xE4
	str r2, [r0]
	b _08018B50
_08018B44:
	strb r2, [r1, 0x4]
_08018B46:
	ldr r0, [r5]
	adds r1, r0, 0
	adds r1, 0xE4
	adds r0, 0xD4
	str r0, [r1]
_08018B50:
	ldr r0, _08018B78
	movs r5, 0xBE
	lsls r5, 1
	adds r1, r5, 0
	bl sub_808D8E0
	ldr r4, _08018B7C
	adds r0, r4, 0
	adds r1, r5, 0
	bl sub_808D8E0
	adds r0, r5, 0
	bl sub_808D994
	adds r1, r0, 0
	subs r4, 0x50
	adds r0, r4, 0
	bl strcpy
	b _08018BAE
	.align 2, 0
_08018B78: .4byte gUnknown_202E5D8
_08018B7C: .4byte gUnknown_202E1C8
_08018B80:
	strb r2, [r1, 0x4]
	ldr r0, [r5]
	adds r0, 0xE4
	str r2, [r0]
	ldr r0, _08018BF8
	movs r5, 0xBE
	lsls r5, 1
	adds r1, r5, 0
	bl sub_808D8E0
	ldr r4, _08018BFC
	adds r0, r4, 0
	adds r1, r5, 0
	bl sub_808D8E0
	adds r0, r5, 0
	bl sub_808D994
	adds r1, r0, 0
	subs r4, 0x50
	adds r0, r4, 0
	bl strcpy
_08018BAE:
	movs r0, 0xBE
	lsls r0, 1
	bl sub_808DDD0
	ldr r2, _08018C00
	ldr r3, [r2]
	adds r1, r3, 0
	adds r1, 0xD4
	str r0, [r1]
	adds r1, 0x4
	ldr r0, [r0, 0x4]
	str r0, [r1]
	adds r0, r3, 0
	adds r0, 0xE0
	movs r1, 0
	strb r1, [r0]
	ldr r0, [r2]
	adds r0, 0xE1
	strb r1, [r0]
	ldr r0, [r2]
	adds r0, 0xE2
	strb r1, [r0]
	ldr r1, [r2]
	adds r2, r1, 0
	adds r2, 0xDC
	movs r0, 0x2
	strh r0, [r2]
	adds r1, 0xDE
	movs r0, 0x8
	strh r0, [r1]
	movs r0, 0
	bl sub_8018D18
	movs r0, 0x1
	pop {r4,r5}
	pop {r1}
	bx r1
	.align 2, 0
_08018BF8: .4byte gUnknown_202E5D8
_08018BFC: .4byte gUnknown_202E1C8
_08018C00: .4byte gUnknown_203B210
	thumb_func_end sub_8018B00

	thumb_func_start sub_8018C04
sub_8018C04:
	push {lr}
	ldr r0, _08018C1C
	ldr r0, [r0]
	ldr r0, [r0, 0x8]
	cmp r0, 0x1F
	bhi _08018CE4
	lsls r0, 2
	ldr r1, _08018C20
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08018C1C: .4byte gUnknown_203B210
_08018C20: .4byte _08018C24
	.align 2, 0
_08018C24:
	.4byte _08018CA4
	.4byte _08018CA4
	.4byte _08018CE4
	.4byte _08018CE4
	.4byte _08018CE0
	.4byte _08018CE4
	.4byte _08018CE4
	.4byte _08018CE4
	.4byte _08018CE4
	.4byte _08018CE4
	.4byte _08018CE4
	.4byte _08018CE4
	.4byte _08018CE4
	.4byte _08018CE4
	.4byte _08018CE4
	.4byte _08018CE4
	.4byte _08018CE4
	.4byte _08018CE4
	.4byte _08018CAA
	.4byte _08018CAA
	.4byte _08018CB6
	.4byte _08018CD4
	.4byte _08018CC2
	.4byte _08018CE4
	.4byte _08018CE4
	.4byte _08018CE4
	.4byte _08018CB0
	.4byte _08018CB0
	.4byte _08018CBC
	.4byte _08018CDA
	.4byte _08018CC8
	.4byte _08018CCE
_08018CA4:
	bl sub_8019730
	b _08018CE8
_08018CAA:
	bl sub_80199CC
	b _08018CE8
_08018CB0:
	bl sub_8019B08
	b _08018CE8
_08018CB6:
	bl sub_8019BBC
	b _08018CE8
_08018CBC:
	bl sub_8019C78
	b _08018CE8
_08018CC2:
	bl sub_8019850
	b _08018CE8
_08018CC8:
	bl sub_80198E8
	b _08018CE8
_08018CCE:
	bl sub_8019944
	b _08018CE8
_08018CD4:
	bl sub_8019D30
	b _08018CE8
_08018CDA:
	bl sub_8019D4C
	b _08018CE8
_08018CE0:
	movs r0, 0x3
	b _08018CEA
_08018CE4:
	bl sub_8019D68
_08018CE8:
	movs r0, 0
_08018CEA:
	pop {r1}
	bx r1
	thumb_func_end sub_8018C04

	thumb_func_start sub_8018CF0
sub_8018CF0:
	push {r4,lr}
	ldr r4, _08018D14
	ldr r0, [r4]
	cmp r0, 0
	beq _08018D0C
	adds r0, 0xD4
	ldr r0, [r0]
	bl CloseFile
	ldr r0, [r4]
	bl MemoryFree
	movs r0, 0
	str r0, [r4]
_08018D0C:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08018D14: .4byte gUnknown_203B210
	thumb_func_end sub_8018CF0

	thumb_func_start sub_8018D18
sub_8018D18:
	push {lr}
	ldr r1, _08018D2C
	ldr r1, [r1]
	str r0, [r1, 0x8]
	bl sub_8018D30
	bl sub_8018E88
	pop {r0}
	bx r0
	.align 2, 0
_08018D2C: .4byte gUnknown_203B210
	thumb_func_end sub_8018D18

	thumb_func_start sub_8018D30
sub_8018D30:
	push {r4-r7,lr}
	ldr r4, _08018D54
	ldr r0, [r4]
	adds r0, 0xE8
	bl sub_8006518
	ldr r0, [r4]
	ldr r0, [r0, 0x8]
	subs r0, 0x12
	cmp r0, 0xA
	bls _08018D48
	b _08018E44
_08018D48:
	lsls r0, 2
	ldr r1, _08018D58
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08018D54: .4byte gUnknown_203B210
_08018D58: .4byte _08018D5C
	.align 2, 0
_08018D5C:
	.4byte _08018D88
	.4byte _08018D88
	.4byte _08018E24
	.4byte _08018E44
	.4byte _08018E44
	.4byte _08018E44
	.4byte _08018E44
	.4byte _08018E44
	.4byte _08018DDC
	.4byte _08018DDC
	.4byte _08018E24
_08018D88:
	ldr r3, _08018DCC
	ldr r1, [r3]
	ldr r2, _08018DD0
	adds r1, 0xE8
	adds r0, r2, 0
	ldm r0!, {r4-r6}
	stm r1!, {r4-r6}
	ldm r0!, {r4,r5,r7}
	stm r1!, {r4,r5,r7}
	ldr r0, [r3]
	movs r6, 0x8C
	lsls r6, 1
	adds r0, r6
	ldm r2!, {r1,r4,r7}
	stm r0!, {r1,r4,r7}
	ldm r2!, {r5-r7}
	stm r0!, {r5-r7}
	ldr r1, [r3]
	adds r1, 0xE8
	ldr r0, _08018DD4
	ldm r0!, {r2,r4,r5}
	stm r1!, {r2,r4,r5}
	ldm r0!, {r2,r6,r7}
	stm r1!, {r2,r6,r7}
	ldr r1, [r3]
	movs r3, 0x80
	lsls r3, 1
	adds r1, r3
	ldr r0, _08018DD8
	ldm r0!, {r4-r6}
	stm r1!, {r4-r6}
	ldm r0!, {r2,r3,r7}
	stm r1!, {r2,r3,r7}
	b _08018E68
	.align 2, 0
_08018DCC: .4byte gUnknown_203B210
_08018DD0: .4byte gUnknown_80DB840
_08018DD4: .4byte gUnknown_80DB870
_08018DD8: .4byte gUnknown_80DB888
_08018DDC:
	ldr r3, _08018E18
	ldr r1, [r3]
	ldr r2, _08018E1C
	adds r1, 0xE8
	adds r0, r2, 0
	ldm r0!, {r4-r6}
	stm r1!, {r4-r6}
	ldm r0!, {r4,r5,r7}
	stm r1!, {r4,r5,r7}
	ldr r1, [r3]
	movs r4, 0x80
	lsls r4, 1
	adds r1, r4
	adds r0, r2, 0
	ldm r0!, {r5-r7}
	stm r1!, {r5-r7}
	ldm r0!, {r5-r7}
	stm r1!, {r5-r7}
	ldr r0, [r3]
	movs r6, 0x8C
	lsls r6, 1
	adds r0, r6
	ldm r2!, {r1,r5,r7}
	stm r0!, {r1,r5,r7}
	ldm r2!, {r1,r6,r7}
	stm r0!, {r1,r6,r7}
	ldr r1, [r3]
	adds r1, r4
	ldr r0, _08018E20
	b _08018E30
	.align 2, 0
_08018E18: .4byte gUnknown_203B210
_08018E1C: .4byte gUnknown_80DB840
_08018E20: .4byte gUnknown_80DB888
_08018E24:
	ldr r0, _08018E3C
	ldr r1, [r0]
	movs r0, 0x8C
	lsls r0, 1
	adds r1, r0
	ldr r0, _08018E40
_08018E30:
	ldm r0!, {r2-r4}
	stm r1!, {r2-r4}
	ldm r0!, {r5-r7}
	stm r1!, {r5-r7}
	b _08018E68
	.align 2, 0
_08018E3C: .4byte gUnknown_203B210
_08018E40: .4byte gUnknown_80DB858
_08018E44:
	ldr r0, _08018E80
	mov r12, r0
	ldr r4, _08018E84
	movs r3, 0
	movs r2, 0x3
_08018E4E:
	mov r5, r12
	ldr r1, [r5]
	adds r1, r3
	adds r1, 0xE8
	adds r0, r4, 0
	ldm r0!, {r5-r7}
	stm r1!, {r5-r7}
	ldm r0!, {r5-r7}
	stm r1!, {r5-r7}
	adds r3, 0x18
	subs r2, 0x1
	cmp r2, 0
	bge _08018E4E
_08018E68:
	bl sub_8004914
	ldr r0, _08018E80
	ldr r0, [r0]
	adds r0, 0xE8
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_08018E80: .4byte gUnknown_203B210
_08018E84: .4byte gUnknown_80DB840
	thumb_func_end sub_8018D30

	thumb_func_start sub_8018E88
sub_8018E88:
	push {r4,lr}
	sub sp, 0x14
	ldr r1, _08018EA4
	ldr r0, [r1]
	ldr r0, [r0, 0x8]
	adds r4, r1, 0
	cmp r0, 0x20
	bls _08018E9A
	b _080194E8
_08018E9A:
	lsls r0, 2
	ldr r1, _08018EA8
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08018EA4: .4byte gUnknown_203B210
_08018EA8: .4byte _08018EAC
	.align 2, 0
_08018EAC:
	.4byte _08018F30
	.4byte _08018F58
	.4byte _08018FA8
	.4byte _08018FD0
	.4byte _080194E8
	.4byte _08018FFC
	.4byte _08019024
	.4byte _0801904C
	.4byte _08019070
	.4byte _08019094
	.4byte _080190B8
	.4byte _080190DC
	.4byte _08019104
	.4byte _0801912C
	.4byte _08019164
	.4byte _0801918C
	.4byte _080191B4
	.4byte _08019294
	.4byte _080191DC
	.4byte _080191FA
	.4byte _08019218
	.4byte _080193F4
	.4byte _08019254
	.4byte _08019314
	.4byte _0801933C
	.4byte _080193FE
	.4byte _08019364
	.4byte _08019372
	.4byte _08019380
	.4byte _080193F4
	.4byte _080193B4
	.4byte _0801946C
	.4byte _080194C0
_08018F30:
	bl sub_8019DAC
	bl sub_80194F8
	movs r0, 0
	bl sub_8019E04
	ldr r2, _08018F50
	ldr r0, _08018F54
	ldr r4, [r0]
	ldr r1, [r4]
	movs r0, 0x5C
	muls r0, r1
	adds r0, r2
	b _08018F76
	.align 2, 0
_08018F50: .4byte gUnknown_80D5EC8
_08018F54: .4byte gUnknown_203B210
_08018F58:
	bl sub_8019DAC
	bl sub_80194F8
	movs r0, 0
	bl sub_8019E04
	ldr r1, _08018FA0
	ldr r0, _08018FA4
	ldr r4, [r0]
	ldr r2, [r4]
	movs r0, 0x5C
	muls r0, r2
	adds r1, 0x4
	adds r0, r1
_08018F76:
	ldr r0, [r0]
	ldr r2, [r4, 0x28]
	adds r3, r4, 0
	adds r3, 0x34
	adds r1, r4, 0
	adds r1, 0x74
	str r1, [sp]
	movs r1, 0x4
	str r1, [sp, 0x4]
	movs r1, 0
	str r1, [sp, 0x8]
	adds r1, r4, 0
	adds r1, 0xE4
	ldr r1, [r1]
	str r1, [sp, 0xC]
	movs r1, 0xC
	str r1, [sp, 0x10]
	movs r1, 0
	bl sub_8014248
	b _080194E8
	.align 2, 0
_08018FA0: .4byte gUnknown_80D5EC8
_08018FA4: .4byte gUnknown_203B210
_08018FA8:
	ldr r1, [r4]
	movs r0, 0x1
	str r0, [r1, 0xC]
	movs r0, 0
	bl sub_8019E04
	ldr r1, _08018FCC
	ldr r2, [r4]
	ldr r3, [r2]
	movs r0, 0x5C
	muls r0, r3
	adds r1, 0x58
	adds r0, r1
	ldr r0, [r0]
	adds r2, 0xE4
	ldr r2, [r2]
	b _08019454
	.align 2, 0
_08018FCC: .4byte gUnknown_80D5EC8
_08018FD0:
	ldr r1, [r4]
	movs r0, 0x4
	str r0, [r1, 0xC]
	movs r0, 0
	bl sub_8019E04
	ldr r1, _08018FF4
	ldr r2, [r4]
	ldr r3, [r2]
	movs r0, 0x5C
	muls r0, r3
	adds r1, 0x8
	adds r0, r1
	ldr r0, [r0]
	adds r2, 0xE4
	ldr r2, [r2]
	ldr r3, _08018FF8
	b _08019456
	.align 2, 0
_08018FF4: .4byte gUnknown_80D5EC8
_08018FF8: .4byte 0x0000030d
_08018FFC:
	ldr r1, [r4]
	movs r0, 0x1
	str r0, [r1, 0xC]
	movs r0, 0
	bl sub_8019E04
	ldr r1, _08019020
	ldr r2, [r4]
	ldr r3, [r2]
	movs r0, 0x5C
	muls r0, r3
	adds r1, 0x30
	adds r0, r1
	ldr r0, [r0]
	adds r2, 0xE4
	ldr r2, [r2]
	b _08019454
	.align 2, 0
_08019020: .4byte gUnknown_80D5EC8
_08019024:
	ldr r1, [r4]
	movs r0, 0x10
	str r0, [r1, 0xC]
	movs r0, 0x1
	bl sub_8019E04
	ldr r1, _08019048
	ldr r2, [r4]
	ldr r3, [r2]
	movs r0, 0x5C
	muls r0, r3
	adds r1, 0x34
	adds r0, r1
	ldr r0, [r0]
	adds r2, 0xE4
	ldr r2, [r2]
	b _08019454
	.align 2, 0
_08019048: .4byte gUnknown_80D5EC8
_0801904C:
	ldr r1, [r4]
	movs r0, 0x1
	str r0, [r1, 0xC]
	bl sub_8019E04
	ldr r1, _0801906C
	ldr r2, [r4]
	ldr r3, [r2]
	movs r0, 0x5C
	muls r0, r3
	adds r1, 0x38
	adds r0, r1
	ldr r0, [r0]
	adds r2, 0xE4
	ldr r2, [r2]
	b _08019454
	.align 2, 0
_0801906C: .4byte gUnknown_80D5EC8
_08019070:
	ldr r1, [r4]
	movs r0, 0x1
	str r0, [r1, 0xC]
	bl sub_8019E04
	ldr r1, _08019090
	ldr r2, [r4]
	ldr r3, [r2]
	movs r0, 0x5C
	muls r0, r3
	adds r1, 0x3C
	adds r0, r1
	ldr r0, [r0]
	adds r2, 0xE4
	ldr r2, [r2]
	b _08019454
	.align 2, 0
_08019090: .4byte gUnknown_80D5EC8
_08019094:
	ldr r1, [r4]
	movs r0, 0x1
	str r0, [r1, 0xC]
	bl sub_8019E04
	ldr r1, _080190B4
	ldr r2, [r4]
	ldr r3, [r2]
	movs r0, 0x5C
	muls r0, r3
	adds r1, 0x40
	adds r0, r1
	ldr r0, [r0]
	adds r2, 0xE4
	ldr r2, [r2]
	b _08019454
	.align 2, 0
_080190B4: .4byte gUnknown_80D5EC8
_080190B8:
	ldr r1, [r4]
	movs r0, 0x1
	str r0, [r1, 0xC]
	bl sub_8019E04
	ldr r1, _080190D8
	ldr r2, [r4]
	ldr r3, [r2]
	movs r0, 0x5C
	muls r0, r3
	adds r1, 0x44
	adds r0, r1
	ldr r0, [r0]
	adds r2, 0xE4
	ldr r2, [r2]
	b _08019454
	.align 2, 0
_080190D8: .4byte gUnknown_80D5EC8
_080190DC:
	ldr r1, [r4]
	movs r0, 0x1
	str r0, [r1, 0xC]
	movs r0, 0
	bl sub_8019E04
	ldr r1, _08019100
	ldr r2, [r4]
	ldr r3, [r2]
	movs r0, 0x5C
	muls r0, r3
	adds r1, 0x48
	adds r0, r1
	ldr r0, [r0]
	adds r2, 0xE4
	ldr r2, [r2]
	b _08019454
	.align 2, 0
_08019100: .4byte gUnknown_80D5EC8
_08019104:
	ldr r1, [r4]
	movs r0, 0x10
	str r0, [r1, 0xC]
	movs r0, 0x1
	bl sub_8019E04
	ldr r1, _08019128
	ldr r2, [r4]
	ldr r3, [r2]
	movs r0, 0x5C
	muls r0, r3
	adds r1, 0x4C
	adds r0, r1
	ldr r0, [r0]
	adds r2, 0xE4
	ldr r2, [r2]
	b _08019454
	.align 2, 0
_08019128: .4byte gUnknown_80D5EC8
_0801912C:
	ldr r0, _0801915C
	ldr r1, [r4]
	adds r1, 0x1C
	movs r2, 0
	bl sub_8090E14
	ldr r1, [r4]
	movs r0, 0x18
	str r0, [r1, 0xC]
	movs r0, 0x1
	bl sub_8019E04
	ldr r1, _08019160
	ldr r2, [r4]
	ldr r3, [r2]
	movs r0, 0x5C
	muls r0, r3
	adds r1, 0x50
	adds r0, r1
	ldr r0, [r0]
	adds r2, 0xE4
	ldr r2, [r2]
	b _08019454
	.align 2, 0
_0801915C: .4byte gUnknown_202DE58
_08019160: .4byte gUnknown_80D5EC8
_08019164:
	ldr r1, [r4]
	movs r0, 0x18
	str r0, [r1, 0xC]
	movs r0, 0x1
	bl sub_8019E04
	ldr r1, _08019188
	ldr r2, [r4]
	ldr r3, [r2]
	movs r0, 0x5C
	muls r0, r3
	adds r1, 0x54
	adds r0, r1
	ldr r0, [r0]
	adds r2, 0xE4
	ldr r2, [r2]
	b _08019454
	.align 2, 0
_08019188: .4byte gUnknown_80D5EC8
_0801918C:
	ldr r1, [r4]
	movs r0, 0x12
	str r0, [r1, 0xC]
	movs r0, 0
	bl sub_8019E04
	ldr r1, _080191B0
	ldr r2, [r4]
	ldr r3, [r2]
	movs r0, 0x5C
	muls r0, r3
	adds r1, 0xC
	adds r0, r1
	ldr r0, [r0]
	adds r2, 0xE4
	ldr r2, [r2]
	b _08019454
	.align 2, 0
_080191B0: .4byte gUnknown_80D5EC8
_080191B4:
	ldr r1, [r4]
	movs r0, 0x13
	str r0, [r1, 0xC]
	movs r0, 0
	bl sub_8019E04
	ldr r1, _080191D8
	ldr r2, [r4]
	ldr r3, [r2]
	movs r0, 0x5C
	muls r0, r3
	adds r1, 0x10
	adds r0, r1
	ldr r0, [r0]
	adds r2, 0xE4
	ldr r2, [r2]
	b _08019454
	.align 2, 0
_080191D8: .4byte gUnknown_80D5EC8
_080191DC:
	ldr r0, [r4]
	ldrb r0, [r0, 0x4]
	cmp r0, 0
	beq _080191EC
	movs r0, 0x3
	bl sub_8019E40
	b _080191F2
_080191EC:
	movs r0, 0x3
	bl sub_801A20C
_080191F2:
	movs r0, 0
	bl sub_801AD34
	b _08019378
_080191FA:
	ldr r0, [r4]
	ldrb r0, [r0, 0x4]
	cmp r0, 0
	beq _0801920A
	movs r0, 0x1
	bl sub_8019FCC
	b _08019210
_0801920A:
	movs r0, 0x1
	bl sub_801A398
_08019210:
	movs r0, 0
	bl sub_801AD34
	b _08019378
_08019218:
	ldr r0, [r4]
	ldrb r0, [r0, 0x4]
	cmp r0, 0
	beq _08019226
	bl sub_801A0D8
	b _0801922A
_08019226:
	bl sub_801A4A4
_0801922A:
	movs r0, 0
	bl sub_801AD34
	movs r0, 0x1
	bl sub_8016C40
	bl sub_80195C0
	ldr r0, _08019250
	ldr r2, [r0]
	adds r0, r2, 0
	adds r0, 0x84
	adds r1, r2, 0
	adds r1, 0x34
	adds r3, r2, 0
	adds r3, 0x74
	ldr r2, [r2, 0x30]
	b _080193A0
	.align 2, 0
_08019250: .4byte gUnknown_203B210
_08019254:
	bl sub_8019700
	ldr r0, _08019284
	ldr r4, _08019288
	ldr r1, [r4]
	adds r1, 0x1C
	movs r2, 0
	bl sub_8090E14
	ldr r1, _0801928C
	ldr r0, [r4]
	ldr r0, [r0, 0x10]
	str r0, [r1]
	movs r0, 0
	bl sub_8019E04
	ldr r1, _08019290
	ldr r4, [r4]
	ldr r2, [r4]
	movs r0, 0x5C
	muls r0, r2
	adds r1, 0x14
	b _0801948C
	.align 2, 0
_08019284: .4byte gUnknown_202DE58
_08019288: .4byte gUnknown_203B210
_0801928C: .4byte gUnknown_202DE30
_08019290: .4byte gUnknown_80D5EC8
_08019294:
	bl sub_8019D8C
	cmp r0, 0
	bne _080192C0
	ldr r0, _080192AC
	ldr r0, [r0]
	ldrb r0, [r0, 0x4]
	cmp r0, 0
	beq _080192B0
	bl sub_801A010
	b _080192B4
	.align 2, 0
_080192AC: .4byte gUnknown_203B210
_080192B0:
	bl sub_801A3DC
_080192B4:
	ldr r0, _080192BC
	ldr r1, [r0]
	movs r0, 0xB
	b _080192F2
	.align 2, 0
_080192BC: .4byte gUnknown_203B210
_080192C0:
	bl sub_8090A34
	cmp r0, 0x13
	ble _080192EC
	ldr r0, _080192D8
	ldr r0, [r0]
	ldrb r0, [r0, 0x4]
	cmp r0, 0
	beq _080192DC
	bl sub_801A010
	b _080192E0
	.align 2, 0
_080192D8: .4byte gUnknown_203B210
_080192DC:
	bl sub_801A3DC
_080192E0:
	ldr r0, _080192E8
	ldr r1, [r0]
	movs r0, 0x1
	b _080192F2
	.align 2, 0
_080192E8: .4byte gUnknown_203B210
_080192EC:
	ldr r0, _0801930C
	ldr r1, [r0]
	movs r0, 0x10
_080192F2:
	str r0, [r1, 0xC]
	movs r0, 0
	bl sub_8019E04
	ldr r2, _08019310
	ldr r0, _0801930C
	ldr r1, [r0]
	ldr r3, [r1]
	movs r0, 0x5C
	muls r0, r3
	adds r2, 0x18
	b _0801944C
	.align 2, 0
_0801930C: .4byte gUnknown_203B210
_08019310: .4byte gUnknown_80D5EC8
_08019314:
	ldr r1, [r4]
	movs r0, 0x1A
	str r0, [r1, 0xC]
	movs r0, 0
	bl sub_8019E04
	ldr r1, _08019338
	ldr r2, [r4]
	ldr r3, [r2]
	movs r0, 0x5C
	muls r0, r3
	adds r1, 0x1C
	adds r0, r1
	ldr r0, [r0]
	adds r2, 0xE4
	ldr r2, [r2]
	b _08019454
	.align 2, 0
_08019338: .4byte gUnknown_80D5EC8
_0801933C:
	ldr r1, [r4]
	movs r0, 0x1B
	str r0, [r1, 0xC]
	movs r0, 0
	bl sub_8019E04
	ldr r1, _08019360
	ldr r2, [r4]
	ldr r3, [r2]
	movs r0, 0x5C
	muls r0, r3
	adds r1, 0x20
	adds r0, r1
	ldr r0, [r0]
	adds r2, 0xE4
	ldr r2, [r2]
	b _08019454
	.align 2, 0
_08019360: .4byte gUnknown_80D5EC8
_08019364:
	movs r0, 0x4
	movs r1, 0x3
	movs r2, 0
	movs r3, 0xA
	bl sub_801A5D8
	b _08019378
_08019372:
	movs r0, 0x1
	bl sub_801A8D0
_08019378:
	movs r0, 0x1
	bl sub_8016C40
	b _080194E8
_08019380:
	bl sub_801A9E0
	movs r0, 0x1
	bl sub_8016C40
	bl sub_8019660
	ldr r0, _080193B0
	ldr r2, [r0]
	adds r0, r2, 0
	adds r0, 0x84
	adds r1, r2, 0
	adds r1, 0x34
	adds r3, r2, 0
	adds r3, 0x74
	ldr r2, [r2, 0x2C]
_080193A0:
	str r2, [sp]
	movs r2, 0x2
	str r2, [sp, 0x4]
	movs r2, 0
	bl sub_8012D60
	b _080194E8
	.align 2, 0
_080193B0: .4byte gUnknown_203B210
_080193B4:
	bl sub_8019700
	ldr r0, _080193E4
	ldr r4, _080193E8
	ldr r1, [r4]
	adds r1, 0x1C
	movs r2, 0
	bl sub_8090E14
	ldr r1, _080193EC
	ldr r0, [r4]
	ldr r0, [r0, 0x10]
	str r0, [r1]
	movs r0, 0
	bl sub_8019E04
	ldr r1, _080193F0
	ldr r4, [r4]
	ldr r2, [r4]
	movs r0, 0x5C
	muls r0, r2
	adds r1, 0x24
	b _0801948C
	.align 2, 0
_080193E4: .4byte gUnknown_202DE58
_080193E8: .4byte gUnknown_203B210
_080193EC: .4byte gUnknown_202DE30
_080193F0: .4byte gUnknown_80D5EC8
_080193F4:
	ldr r0, [r4]
	adds r0, 0x1C
	bl sub_801B3C0
	b _080194E8
_080193FE:
	bl sub_8090A34
	cmp r0, 0
	beq _08019418
	ldr r0, _08019424
	ldr r0, [r0]
	movs r1, 0x98
	lsls r1, 2
	adds r0, r1
	ldr r1, [r0]
	ldr r0, _08019428
	cmp r1, r0
	ble _08019430
_08019418:
	bl sub_801A928
	ldr r0, _0801942C
	ldr r1, [r0]
	movs r0, 0x1
	b _08019436
	.align 2, 0
_08019424: .4byte gUnknown_203B460
_08019428: .4byte 0x0001869e
_0801942C: .4byte gUnknown_203B210
_08019430:
	ldr r0, _08019460
	ldr r1, [r0]
	movs r0, 0x18
_08019436:
	str r0, [r1, 0xC]
	movs r0, 0
	bl sub_8019E04
	ldr r2, _08019464
	ldr r0, _08019460
	ldr r1, [r0]
	ldr r3, [r1]
	movs r0, 0x5C
	muls r0, r3
	adds r2, 0x2C
_0801944C:
	adds r0, r2
	ldr r0, [r0]
	adds r1, 0xE4
	ldr r2, [r1]
_08019454:
	ldr r3, _08019468
_08019456:
	movs r1, 0
	bl sub_80141B4
	b _080194E8
	.align 2, 0
_08019460: .4byte gUnknown_203B210
_08019464: .4byte gUnknown_80D5EC8
_08019468: .4byte 0x0000010d
_0801946C:
	bl sub_8019700
	ldr r1, _080194B4
	ldr r4, _080194B8
	ldr r0, [r4]
	ldr r0, [r0, 0x18]
	str r0, [r1]
	movs r0, 0
	bl sub_8019E04
	ldr r1, _080194BC
	ldr r4, [r4]
	ldr r2, [r4]
	movs r0, 0x5C
	muls r0, r2
	adds r1, 0x28
_0801948C:
	adds r0, r1
	ldr r0, [r0]
	adds r3, r4, 0
	adds r3, 0x34
	movs r2, 0
	str r2, [sp]
	movs r1, 0x4
	str r1, [sp, 0x4]
	str r2, [sp, 0x8]
	adds r4, 0xE4
	ldr r1, [r4]
	str r1, [sp, 0xC]
	movs r1, 0xC
	str r1, [sp, 0x10]
	movs r1, 0
	movs r2, 0x5
	bl sub_8014248
	b _080194E8
	.align 2, 0
_080194B4: .4byte gUnknown_202DE30
_080194B8: .4byte gUnknown_203B210
_080194BC: .4byte gUnknown_80D5EC8
_080194C0:
	ldr r1, [r4]
	movs r0, 0x1
	str r0, [r1, 0xC]
	movs r0, 0
	bl sub_8019E04
	ldr r1, _080194F0
	ldr r2, [r4]
	ldr r3, [r2]
	movs r0, 0x5C
	muls r0, r3
	adds r1, 0x2C
	adds r0, r1
	ldr r0, [r0]
	adds r2, 0xE4
	ldr r2, [r2]
	ldr r3, _080194F4
	movs r1, 0
	bl sub_80141B4
_080194E8:
	add sp, 0x14
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080194F0: .4byte gUnknown_80D5EC8
_080194F4: .4byte 0x0000010d
	thumb_func_end sub_8018E88

	thumb_func_start sub_80194F8
sub_80194F8:
	push {r4-r7,lr}
	ldr r4, _08019580
	ldr r0, [r4]
	adds r0, 0x74
	movs r1, 0
	movs r2, 0x10
	bl MemoryFill16
	ldr r3, [r4]
	movs r2, 0
	ldr r0, _08019584
	ldr r0, [r0]
	str r0, [r3, 0x34]
	movs r0, 0x2
	str r0, [r3, 0x38]
	movs r1, 0x1
	ldr r0, _08019588
	ldr r0, [r0]
	str r0, [r3, 0x3C]
	movs r0, 0x3
	str r0, [r3, 0x40]
	ldr r0, _0801958C
	str r0, [r3, 0x44]
	movs r0, 0x4
	str r0, [r3, 0x48]
	ldr r0, _08019590
	ldr r0, [r0]
	str r0, [r3, 0x4C]
	movs r0, 0x7
	str r0, [r3, 0x50]
	ldr r0, _08019594
	ldr r0, [r0]
	str r0, [r3, 0x54]
	str r1, [r3, 0x58]
	movs r6, 0x5
	str r2, [r3, 0x5C]
	str r1, [r3, 0x60]
	movs r5, 0
	mov r12, r3
	adds r3, 0x38
	mov r2, r12
	adds r2, 0x74
_0801954C:
	ldrh r0, [r2]
	cmp r0, 0
	bne _0801955C
	ldr r1, [r3]
	mov r7, r12
	ldr r0, [r7, 0x28]
	cmp r1, r0
	beq _080195BA
_0801955C:
	adds r3, 0x8
	adds r2, 0x2
	adds r5, 0x1
	cmp r5, r6
	blt _0801954C
	movs r5, 0
	cmp r5, r6
	bge _080195BA
	ldr r1, [r4]
	adds r0, r1, 0
	adds r0, 0x74
	ldrh r0, [r0]
	cmp r0, 0
	bne _08019598
	ldr r0, [r1, 0x38]
	str r0, [r1, 0x28]
	b _080195BA
	.align 2, 0
_08019580: .4byte gUnknown_203B210
_08019584: .4byte gUnknown_80D4978
_08019588: .4byte gUnknown_80D4984
_0801958C: .4byte gUnknown_80DB8A0
_08019590: .4byte gUnknown_80D4970
_08019594: .4byte gUnknown_80D4934
_08019598:
	adds r5, 0x1
	cmp r5, r6
	bge _080195BA
	ldr r2, [r4]
	lsls r0, r5, 1
	adds r1, r2, 0
	adds r1, 0x74
	adds r1, r0
	ldrh r0, [r1]
	cmp r0, 0
	bne _08019598
	lsls r0, r5, 3
	adds r1, r2, 0
	adds r1, 0x38
	adds r1, r0
	ldr r0, [r1]
	str r0, [r2, 0x28]
_080195BA:
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_80194F8

	thumb_func_start sub_80195C0
sub_80195C0:
	push {r4-r7,lr}
	ldr r4, _0801962C
	ldr r0, [r4]
	adds r0, 0x74
	movs r1, 0
	movs r2, 0x10
	bl MemoryFill16
	ldr r3, [r4]
	movs r2, 0
	ldr r0, _08019630
	ldr r0, [r0]
	str r0, [r3, 0x34]
	movs r0, 0x2
	str r0, [r3, 0x38]
	movs r1, 0x1
	ldr r0, _08019634
	ldr r0, [r0]
	str r0, [r3, 0x3C]
	movs r0, 0x7
	str r0, [r3, 0x40]
	movs r6, 0x2
	str r2, [r3, 0x44]
	str r1, [r3, 0x48]
	movs r5, 0
	mov r12, r3
	adds r3, 0x38
	mov r2, r12
	adds r2, 0x74
_080195FA:
	ldrh r0, [r2]
	cmp r0, 0
	bne _0801960A
	ldr r1, [r3]
	mov r7, r12
	ldr r0, [r7, 0x30]
	cmp r1, r0
	beq _0801965A
_0801960A:
	adds r3, 0x8
	adds r2, 0x2
	adds r5, 0x1
	cmp r5, r6
	blt _080195FA
	movs r5, 0
	cmp r5, r6
	bge _0801965A
	ldr r1, [r4]
	adds r0, r1, 0
	adds r0, 0x74
	ldrh r0, [r0]
	cmp r0, 0
	bne _08019638
	ldr r0, [r1, 0x38]
	str r0, [r1, 0x30]
	b _0801965A
	.align 2, 0
_0801962C: .4byte gUnknown_203B210
_08019630: .4byte gUnknown_80D4978
_08019634: .4byte gUnknown_80D4970
_08019638:
	adds r5, 0x1
	cmp r5, r6
	bge _0801965A
	ldr r2, [r4]
	lsls r0, r5, 1
	adds r1, r2, 0
	adds r1, 0x74
	adds r1, r0
	ldrh r0, [r1]
	cmp r0, 0
	bne _08019638
	lsls r0, r5, 3
	adds r1, r2, 0
	adds r1, 0x38
	adds r1, r0
	ldr r0, [r1]
	str r0, [r2, 0x30]
_0801965A:
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_80195C0

	thumb_func_start sub_8019660
sub_8019660:
	push {r4-r7,lr}
	ldr r4, _080196CC
	ldr r0, [r4]
	adds r0, 0x74
	movs r1, 0
	movs r2, 0x10
	bl MemoryFill16
	ldr r3, [r4]
	movs r2, 0
	ldr r0, _080196D0
	ldr r0, [r0]
	str r0, [r3, 0x34]
	movs r0, 0x3
	str r0, [r3, 0x38]
	movs r1, 0x1
	ldr r0, _080196D4
	ldr r0, [r0]
	str r0, [r3, 0x3C]
	movs r0, 0x7
	str r0, [r3, 0x40]
	movs r6, 0x2
	str r2, [r3, 0x44]
	str r1, [r3, 0x48]
	movs r5, 0
	mov r12, r3
	adds r3, 0x38
	mov r2, r12
	adds r2, 0x74
_0801969A:
	ldrh r0, [r2]
	cmp r0, 0
	bne _080196AA
	ldr r1, [r3]
	mov r7, r12
	ldr r0, [r7, 0x2C]
	cmp r1, r0
	beq _080196FA
_080196AA:
	adds r3, 0x8
	adds r2, 0x2
	adds r5, 0x1
	cmp r5, r6
	blt _0801969A
	movs r5, 0
	cmp r5, r6
	bge _080196FA
	ldr r1, [r4]
	adds r0, r1, 0
	adds r0, 0x74
	ldrh r0, [r0]
	cmp r0, 0
	bne _080196D8
	ldr r0, [r1, 0x38]
	str r0, [r1, 0x2C]
	b _080196FA
	.align 2, 0
_080196CC: .4byte gUnknown_203B210
_080196D0: .4byte gUnknown_80D4984
_080196D4: .4byte gUnknown_80D4970
_080196D8:
	adds r5, 0x1
	cmp r5, r6
	bge _080196FA
	ldr r2, [r4]
	lsls r0, r5, 1
	adds r1, r2, 0
	adds r1, 0x74
	adds r1, r0
	ldrh r0, [r1]
	cmp r0, 0
	bne _080196D8
	lsls r0, r5, 3
	adds r1, r2, 0
	adds r1, 0x38
	adds r1, r0
	ldr r0, [r1]
	str r0, [r2, 0x2C]
_080196FA:
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_8019660

	thumb_func_start sub_8019700
sub_8019700:
	ldr r0, _08019724
	ldr r1, [r0]
	movs r3, 0
	ldr r0, _08019728
	ldr r0, [r0]
	str r0, [r1, 0x34]
	movs r0, 0x5
	str r0, [r1, 0x38]
	movs r2, 0x1
	ldr r0, _0801972C
	ldr r0, [r0]
	str r0, [r1, 0x3C]
	movs r0, 0x6
	str r0, [r1, 0x40]
	str r3, [r1, 0x44]
	str r2, [r1, 0x48]
	bx lr
	.align 2, 0
_08019724: .4byte gUnknown_203B210
_08019728: .4byte gUnknown_80D4920
_0801972C: .4byte gUnknown_80D4928
	thumb_func_end sub_8019700

	thumb_func_start sub_8019730
sub_8019730:
	push {lr}
	sub sp, 0x4
	mov r0, sp
	bl sub_80144A4
	cmp r0, 0
	beq _08019740
	b _0801984A
_08019740:
	ldr r1, [sp]
	cmp r1, 0x1
	beq _0801974C
	ldr r0, _08019760
	ldr r0, [r0]
	str r1, [r0, 0x28]
_0801974C:
	ldr r0, [sp]
	subs r0, 0x1
	cmp r0, 0x6
	bls _08019756
	b _0801984A
_08019756:
	lsls r0, 2
	ldr r1, _08019764
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08019760: .4byte gUnknown_203B210
_08019764: .4byte _08019768
	.align 2, 0
_08019768:
	.4byte _08019844
	.4byte _08019784
	.4byte _080197AC
	.4byte _080197E4
	.4byte _0801984A
	.4byte _0801984A
	.4byte _0801983C
_08019784:
	bl sub_8019D8C
	cmp r0, 0
	bne _08019794
	movs r0, 0x5
	bl sub_8018D18
	b _0801984A
_08019794:
	bl sub_8090A34
	cmp r0, 0x13
	ble _080197A4
	movs r0, 0xA
	bl sub_8018D18
	b _0801984A
_080197A4:
	movs r0, 0xF
	bl sub_8018D18
	b _0801984A
_080197AC:
	bl sub_8090A34
	cmp r0, 0
	beq _080197EC
	ldr r0, _080197D8
	ldr r0, [r0]
	ldr r0, [r0, 0x14]
	cmp r0, 0
	beq _080197FE
	ldr r0, _080197DC
	ldr r0, [r0]
	movs r1, 0x98
	lsls r1, 2
	adds r0, r1
	ldr r1, [r0]
	ldr r0, _080197E0
	cmp r1, r0
	bgt _08019822
	movs r0, 0x17
	bl sub_8018D18
	b _0801984A
	.align 2, 0
_080197D8: .4byte gUnknown_203B210
_080197DC: .4byte gUnknown_203B460
_080197E0: .4byte 0x0001869e
_080197E4:
	bl sub_8090A34
	cmp r0, 0
	bne _080197F4
_080197EC:
	movs r0, 0x9
	bl sub_8018D18
	b _0801984A
_080197F4:
	ldr r0, _08019808
	ldr r1, [r0]
	ldr r0, [r1, 0x14]
	cmp r0, 0
	bne _0801980C
_080197FE:
	movs r0, 0x8
	bl sub_8018D18
	b _0801984A
	.align 2, 0
_08019808: .4byte gUnknown_203B210
_0801980C:
	ldr r0, _0801982C
	ldr r0, [r0]
	movs r2, 0x98
	lsls r2, 2
	adds r0, r2
	ldr r1, [r1, 0x18]
	ldr r0, [r0]
	adds r1, r0
	ldr r0, _08019830
	cmp r1, r0
	ble _08019834
_08019822:
	movs r0, 0x7
	bl sub_8018D18
	b _0801984A
	.align 2, 0
_0801982C: .4byte gUnknown_203B460
_08019830: .4byte 0x0001869f
_08019834:
	movs r0, 0x1F
	bl sub_8018D18
	b _0801984A
_0801983C:
	movs r0, 0x2
	bl sub_8018D18
	b _0801984A
_08019844:
	movs r0, 0x3
	bl sub_8018D18
_0801984A:
	add sp, 0x4
	pop {r0}
	bx r0
	thumb_func_end sub_8019730

	thumb_func_start sub_8019850
sub_8019850:
	push {r4,lr}
	sub sp, 0x4
	mov r0, sp
	bl sub_80144A4
	cmp r0, 0
	bne _080198DE
	ldr r0, [sp]
	cmp r0, 0x5
	beq _08019874
	cmp r0, 0x5
	bgt _0801986E
	cmp r0, 0x1
	beq _080198D8
	b _080198DE
_0801986E:
	cmp r0, 0x6
	beq _080198D8
	b _080198DE
_08019874:
	ldr r4, _080198A8
	ldr r0, [r4]
	ldr r0, [r0, 0x10]
	negs r0, r0
	bl sub_80913A0
	ldr r1, [r4]
	ldrb r0, [r1, 0x4]
	cmp r0, 0
	beq _080198AC
	adds r0, r1, 0
	adds r0, 0x20
	ldrb r0, [r0]
	bl sub_809185C
	bl sub_8091274
	ldr r0, [r4]
	adds r0, 0x20
	ldrb r0, [r0]
	bl sub_8091840
	bl sub_8091874
	b _080198C8
	.align 2, 0
_080198A8: .4byte gUnknown_203B210
_080198AC:
	adds r0, r1, 0
	adds r0, 0x21
	ldrb r0, [r0]
	bl sub_8091A90
	bl sub_8091274
	ldr r0, [r4]
	adds r0, 0x21
	ldrb r0, [r0]
	bl sub_8091A74
	bl sub_8091AA8
_080198C8:
	movs r0, 0xA6
	lsls r0, 1
	bl sub_8011988
	movs r0, 0x11
	bl sub_8018D18
	b _080198DE
_080198D8:
	movs r0, 0x10
	bl sub_8018D18
_080198DE:
	add sp, 0x4
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_8019850

	thumb_func_start sub_80198E8
sub_80198E8:
	push {r4,lr}
	sub sp, 0x4
	mov r0, sp
	bl sub_80144A4
	cmp r0, 0
	bne _0801993A
	ldr r0, [sp]
	cmp r0, 0x5
	beq _0801990C
	cmp r0, 0x5
	bgt _08019906
	cmp r0, 0x1
	beq _08019934
	b _0801993A
_08019906:
	cmp r0, 0x6
	beq _08019934
	b _0801993A
_0801990C:
	ldr r4, _08019930
	ldr r0, [r4]
	ldr r0, [r0, 0x10]
	bl sub_80913A0
	ldr r0, [r4]
	ldr r0, [r0, 0x24]
	bl sub_80911F8
	movs r0, 0xA6
	lsls r0, 1
	bl sub_8011988
	movs r0, 0x19
	bl sub_8018D18
	b _0801993A
	.align 2, 0
_08019930: .4byte gUnknown_203B210
_08019934:
	movs r0, 0x18
	bl sub_8018D18
_0801993A:
	add sp, 0x4
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_80198E8

	thumb_func_start sub_8019944
sub_8019944:
	push {r4,r5,lr}
	sub sp, 0x4
	mov r0, sp
	bl sub_80144A4
	cmp r0, 0
	bne _080199C2
	ldr r0, [sp]
	cmp r0, 0x5
	beq _08019968
	cmp r0, 0x5
	bgt _08019962
	cmp r0, 0x1
	beq _080199BC
	b _080199C2
_08019962:
	cmp r0, 0x6
	beq _080199BC
	b _080199C2
_08019968:
	movs r4, 0
	ldr r5, _080199B4
_0801996C:
	lsls r1, r4, 2
	ldr r0, [r5]
	adds r2, r0, r1
	ldrb r1, [r2]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _0801998E
	ldrb r0, [r2, 0x2]
	bl sub_80914E4
	lsls r0, 24
	cmp r0, 0
	beq _0801998E
	adds r0, r4, 0
	bl sub_8091234
_0801998E:
	adds r4, 0x1
	cmp r4, 0x13
	ble _0801996C
	bl sub_80910B4
	ldr r0, _080199B8
	ldr r0, [r0]
	ldr r0, [r0, 0x18]
	bl sub_80913A0
	movs r0, 0xA6
	lsls r0, 1
	bl sub_8011988
	movs r0, 0x20
	bl sub_8018D18
	b _080199C2
	.align 2, 0
_080199B4: .4byte gUnknown_203B460
_080199B8: .4byte gUnknown_203B210
_080199BC:
	movs r0, 0x1
	bl sub_8018D18
_080199C2:
	add sp, 0x4
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_8019944

	thumb_func_start sub_80199CC
sub_80199CC:
	push {r4,r5,lr}
	ldr r0, _080199E0
	ldr r0, [r0]
	ldrb r0, [r0, 0x4]
	cmp r0, 0
	beq _080199E4
	movs r0, 0x1
	bl sub_8019EDC
	b _080199EA
	.align 2, 0
_080199E0: .4byte gUnknown_203B210
_080199E4:
	movs r0, 0x1
	bl sub_801A2A8
_080199EA:
	cmp r0, 0x2
	beq _08019AD4
	cmp r0, 0x2
	bhi _080199FA
	cmp r0, 0x1
	bne _080199F8
	b _08019AF4
_080199F8:
	b _08019B00
_080199FA:
	cmp r0, 0x3
	beq _08019A04
	cmp r0, 0x4
	beq _08019A6C
	b _08019B00
_08019A04:
	ldr r4, _08019A24
	ldr r0, [r4]
	ldrb r0, [r0, 0x4]
	cmp r0, 0
	beq _08019A28
	bl sub_8019FB0
	ldr r1, [r4]
	adds r1, 0x20
	strb r0, [r1]
	ldr r0, [r4]
	adds r0, 0x20
	ldrb r0, [r0]
	bl sub_809185C
	b _08019A3C
	.align 2, 0
_08019A24: .4byte gUnknown_203B210
_08019A28:
	bl sub_801A37C
	ldr r1, [r4]
	adds r1, 0x21
	strb r0, [r1]
	ldr r0, [r4]
	adds r0, 0x21
	ldrb r0, [r0]
	bl sub_8091A90
_08019A3C:
	adds r5, r0, 0
	ldr r4, _08019A68
	ldr r0, [r4]
	adds r0, 0x1C
	ldrb r1, [r5]
	movs r2, 0
	bl sub_8090A8C
	ldr r1, [r4]
	ldrb r0, [r5, 0x1]
	strb r0, [r1, 0x1D]
	ldr r0, [r4]
	adds r0, 0x1C
	bl sub_8090C7C
	ldr r1, [r4]
	str r0, [r1, 0x10]
	movs r0, 0x14
	bl sub_8018D18
	b _08019B00
	.align 2, 0
_08019A68: .4byte gUnknown_203B210
_08019A6C:
	ldr r4, _08019A8C
	ldr r0, [r4]
	ldrb r0, [r0, 0x4]
	cmp r0, 0
	beq _08019A90
	bl sub_8019FB0
	ldr r1, [r4]
	adds r1, 0x20
	strb r0, [r1]
	ldr r0, [r4]
	adds r0, 0x20
	ldrb r0, [r0]
	bl sub_809185C
	b _08019AA4
	.align 2, 0
_08019A8C: .4byte gUnknown_203B210
_08019A90:
	bl sub_801A37C
	ldr r1, [r4]
	adds r1, 0x21
	strb r0, [r1]
	ldr r0, [r4]
	adds r0, 0x21
	ldrb r0, [r0]
	bl sub_8091A90
_08019AA4:
	adds r5, r0, 0
	ldr r4, _08019AD0
	ldr r0, [r4]
	adds r0, 0x1C
	ldrb r1, [r5]
	movs r2, 0
	bl sub_8090A8C
	ldr r1, [r4]
	ldrb r0, [r5, 0x1]
	strb r0, [r1, 0x1D]
	ldr r0, [r4]
	adds r0, 0x1C
	bl sub_8090C7C
	ldr r1, [r4]
	str r0, [r1, 0x10]
	movs r0, 0x15
	bl sub_8018D18
	b _08019B00
	.align 2, 0
_08019AD0: .4byte gUnknown_203B210
_08019AD4:
	ldr r0, _08019AE4
	ldr r0, [r0]
	ldrb r0, [r0, 0x4]
	cmp r0, 0
	beq _08019AE8
	bl sub_801A010
	b _08019AEC
	.align 2, 0
_08019AE4: .4byte gUnknown_203B210
_08019AE8:
	bl sub_801A3DC
_08019AEC:
	movs r0, 0x1
	bl sub_8018D18
	b _08019B00
_08019AF4:
	movs r0, 0
	bl sub_801AD34
	movs r0, 0x1
	bl sub_8016C40
_08019B00:
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_80199CC

	thumb_func_start sub_8019B08
sub_8019B08:
	push {r4,lr}
	movs r0, 0x1
	bl sub_801A6E8
	cmp r0, 0x4
	bhi _08019BB0
	lsls r0, 2
	ldr r1, _08019B20
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08019B20: .4byte _08019B24
	.align 2, 0
_08019B24:
	.4byte _08019BB6
	.4byte _08019BB0
	.4byte _08019BA4
	.4byte _08019B38
	.4byte _08019B6C
_08019B38:
	bl sub_801A8AC
	ldr r4, _08019B64
	ldr r2, [r4]
	str r0, [r2, 0x24]
	ldr r1, _08019B68
	ldr r1, [r1]
	lsls r0, 2
	adds r1, r0
	ldr r0, [r1]
	str r0, [r2, 0x1C]
	adds r2, 0x1C
	adds r0, r2, 0
	bl sub_8090CCC
	ldr r1, [r4]
	str r0, [r1, 0x10]
	movs r0, 0x1C
	bl sub_8018D18
	b _08019BB6
	.align 2, 0
_08019B64: .4byte gUnknown_203B210
_08019B68: .4byte gUnknown_203B460
_08019B6C:
	bl sub_801A8AC
	ldr r4, _08019B9C
	ldr r2, [r4]
	str r0, [r2, 0x24]
	ldr r1, _08019BA0
	ldr r1, [r1]
	lsls r0, 2
	adds r1, r0
	ldr r0, [r1]
	str r0, [r2, 0x1C]
	adds r2, 0x1C
	adds r0, r2, 0
	bl sub_8090CCC
	ldr r1, [r4]
	str r0, [r1, 0x10]
	movs r0, 0
	bl sub_8099690
	movs r0, 0x1D
	bl sub_8018D18
	b _08019BB6
	.align 2, 0
_08019B9C: .4byte gUnknown_203B210
_08019BA0: .4byte gUnknown_203B460
_08019BA4:
	bl sub_801A928
	movs r0, 0x1
	bl sub_8018D18
	b _08019BB6
_08019BB0:
	movs r0, 0x1
	bl sub_8016C40
_08019BB6:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_8019B08

	thumb_func_start sub_8019BBC
sub_8019BBC:
	push {r4,lr}
	sub sp, 0x4
	movs r0, 0
	str r0, [sp]
	ldr r0, _08019BD8
	ldr r0, [r0]
	ldrb r0, [r0, 0x4]
	cmp r0, 0
	beq _08019BDC
	movs r0, 0
	bl sub_8019EDC
	b _08019BE2
	.align 2, 0
_08019BD8: .4byte gUnknown_203B210
_08019BDC:
	movs r0, 0
	bl sub_801A2A8
_08019BE2:
	ldr r4, _08019C18
	ldr r0, [r4]
	adds r0, 0x84
	bl sub_8012FD8
	lsls r0, 24
	cmp r0, 0
	bne _08019C06
	ldr r0, [r4]
	adds r0, 0x84
	mov r1, sp
	bl sub_8013114
	ldr r1, [sp]
	cmp r1, 0x1
	beq _08019C06
	ldr r0, [r4]
	str r1, [r0, 0x30]
_08019C06:
	ldr r0, [sp]
	cmp r0, 0x2
	beq _08019C22
	cmp r0, 0x2
	bgt _08019C1C
	cmp r0, 0x1
	beq _08019C68
	b _08019C6E
	.align 2, 0
_08019C18: .4byte gUnknown_203B210
_08019C1C:
	cmp r0, 0x7
	beq _08019C60
	b _08019C6E
_08019C22:
	ldr r0, _08019C3C
	ldr r0, [r0]
	movs r1, 0x98
	lsls r1, 2
	adds r0, r1
	ldr r1, [r0]
	cmp r1, 0
	bne _08019C40
	movs r0, 0x6
	bl sub_8018D18
	b _08019C6E
	.align 2, 0
_08019C3C: .4byte gUnknown_203B460
_08019C40:
	ldr r0, _08019C54
	ldr r0, [r0]
	ldr r0, [r0, 0x10]
	cmp r0, r1
	ble _08019C58
	movs r0, 0xC
	bl sub_8018D18
	b _08019C6E
	.align 2, 0
_08019C54: .4byte gUnknown_203B210
_08019C58:
	movs r0, 0x16
	bl sub_8018D18
	b _08019C6E
_08019C60:
	movs r0, 0x15
	bl sub_8018D18
	b _08019C6E
_08019C68:
	movs r0, 0x13
	bl sub_8018D18
_08019C6E:
	add sp, 0x4
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_8019BBC

	thumb_func_start sub_8019C78
sub_8019C78:
	push {r4,lr}
	sub sp, 0x4
	movs r0, 0
	str r0, [sp]
	bl sub_801A6E8
	ldr r4, _08019CB8
	ldr r0, [r4]
	adds r0, 0x84
	bl sub_8012FD8
	lsls r0, 24
	cmp r0, 0
	bne _08019CA8
	ldr r0, [r4]
	adds r0, 0x84
	mov r1, sp
	bl sub_8013114
	ldr r1, [sp]
	cmp r1, 0x1
	beq _08019CA8
	ldr r0, [r4]
	str r1, [r0, 0x2C]
_08019CA8:
	ldr r0, [sp]
	cmp r0, 0x3
	beq _08019CC2
	cmp r0, 0x3
	bgt _08019CBC
	cmp r0, 0x1
	beq _08019D22
	b _08019D28
	.align 2, 0
_08019CB8: .4byte gUnknown_203B210
_08019CBC:
	cmp r0, 0x7
	beq _08019D14
	b _08019D28
_08019CC2:
	movs r0, 0
	bl sub_8099690
	ldr r4, _08019CE0
	ldr r0, [r4]
	ldrb r0, [r0, 0x1E]
	bl sub_80914E4
	lsls r0, 24
	cmp r0, 0
	bne _08019CE4
	movs r0, 0xD
	bl sub_8018D18
	b _08019D28
	.align 2, 0
_08019CE0: .4byte gUnknown_203B210
_08019CE4:
	ldr r1, [r4]
	ldr r0, _08019D04
	ldr r0, [r0]
	movs r2, 0x98
	lsls r2, 2
	adds r0, r2
	ldr r1, [r1, 0x10]
	ldr r0, [r0]
	adds r1, r0
	ldr r0, _08019D08
	cmp r1, r0
	ble _08019D0C
	movs r0, 0xE
	bl sub_8018D18
	b _08019D28
	.align 2, 0
_08019D04: .4byte gUnknown_203B460
_08019D08: .4byte 0x0001869f
_08019D0C:
	movs r0, 0x1E
	bl sub_8018D18
	b _08019D28
_08019D14:
	movs r0, 0
	bl sub_8099690
	movs r0, 0x1D
	bl sub_8018D18
	b _08019D28
_08019D22:
	movs r0, 0x1B
	bl sub_8018D18
_08019D28:
	add sp, 0x4
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_8019C78

	thumb_func_start sub_8019D30
sub_8019D30:
	push {lr}
	bl sub_801B410
	cmp r0, 0x1
	bls _08019D48
	cmp r0, 0x3
	bhi _08019D48
	bl sub_801B450
	movs r0, 0x13
	bl sub_8018D18
_08019D48:
	pop {r0}
	bx r0
	thumb_func_end sub_8019D30

	thumb_func_start sub_8019D4C
sub_8019D4C:
	push {lr}
	bl sub_801B410
	cmp r0, 0x1
	bls _08019D64
	cmp r0, 0x3
	bhi _08019D64
	bl sub_801B450
	movs r0, 0x1B
	bl sub_8018D18
_08019D64:
	pop {r0}
	bx r0
	thumb_func_end sub_8019D4C

	thumb_func_start sub_8019D68
sub_8019D68:
	push {lr}
	sub sp, 0x4
	mov r0, sp
	bl sub_80144A4
	cmp r0, 0
	bne _08019D80
	ldr r0, _08019D88
	ldr r0, [r0]
	ldr r0, [r0, 0xC]
	bl sub_8018D18
_08019D80:
	add sp, 0x4
	pop {r0}
	bx r0
	.align 2, 0
_08019D88: .4byte gUnknown_203B210
	thumb_func_end sub_8019D68

	thumb_func_start sub_8019D8C
sub_8019D8C:
	push {lr}
	ldr r0, _08019DA0
	ldr r0, [r0]
	ldrb r0, [r0, 0x4]
	cmp r0, 0
	bne _08019DA4
	bl sub_8091A48
	b _08019DA8
	.align 2, 0
_08019DA0: .4byte gUnknown_203B210
_08019DA4:
	bl sub_8091814
_08019DA8:
	pop {r1}
	bx r1
	thumb_func_end sub_8019D8C

	thumb_func_start sub_8019DAC
sub_8019DAC:
	push {r4,r5,lr}
	ldr r0, _08019DFC
	ldr r1, [r0]
	movs r0, 0
	str r0, [r1, 0x14]
	str r0, [r1, 0x18]
	movs r5, 0
_08019DBA:
	ldr r0, _08019E00
	lsls r1, r5, 2
	ldr r0, [r0]
	adds r4, r0, r1
	ldrb r1, [r4]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _08019DEE
	ldrb r0, [r4, 0x2]
	bl sub_80914E4
	lsls r0, 24
	cmp r0, 0
	beq _08019DEE
	adds r0, r4, 0
	bl sub_8090CCC
	ldr r1, _08019DFC
	ldr r2, [r1]
	ldr r1, [r2, 0x18]
	adds r1, r0
	str r1, [r2, 0x18]
	ldr r0, [r2, 0x14]
	adds r0, 0x1
	str r0, [r2, 0x14]
_08019DEE:
	adds r5, 0x1
	cmp r5, 0x13
	ble _08019DBA
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_08019DFC: .4byte gUnknown_203B210
_08019E00: .4byte gUnknown_203B460
	thumb_func_end sub_8019DAC

	thumb_func_start sub_8019E04
sub_8019E04:
	push {lr}
	adds r2, r0, 0
	ldr r0, _08019E20
	ldr r1, [r0]
	ldrb r0, [r1, 0x4]
	cmp r0, 0
	beq _08019E2A
	cmp r2, 0x1
	bne _08019E24
	adds r0, r1, 0
	adds r0, 0xE0
	strb r2, [r0]
	b _08019E3A
	.align 2, 0
_08019E20: .4byte gUnknown_203B210
_08019E24:
	adds r1, 0xE0
	movs r0, 0
	b _08019E38
_08019E2A:
	cmp r2, 0x1
	bne _08019E34
	adds r1, 0xE0
	movs r0, 0x7
	b _08019E38
_08019E34:
	adds r1, 0xE0
	movs r0, 0x6
_08019E38:
	strb r0, [r1]
_08019E3A:
	pop {r0}
	bx r0
	thumb_func_end sub_8019E04

	thumb_func_start sub_8019E40
sub_8019E40:
	push {r4-r6,lr}
	adds r6, r0, 0
	bl sub_8091814
	cmp r0, 0
	beq _08019ED4
	ldr r5, _08019EC8
	movs r0, 0xA0
	movs r1, 0x8
	bl MemoryAlloc
	str r0, [r5]
	str r6, [r0, 0x34]
	lsls r1, r6, 1
	adds r1, r6
	lsls r1, 3
	adds r1, 0x3C
	adds r1, r0, r1
	str r1, [r0, 0x38]
	adds r0, 0x3C
	bl sub_8006518
	ldr r1, [r5]
	ldr r2, [r1, 0x34]
	lsls r0, r2, 1
	adds r0, r2
	lsls r0, 3
	adds r1, r0
	adds r1, 0x3C
	ldr r0, _08019ECC
	ldm r0!, {r2-r4}
	stm r1!, {r2-r4}
	ldm r0!, {r2-r4}
	stm r1!, {r2-r4}
	ldr r0, [r5]
	ldr r1, [r0, 0x38]
	adds r0, 0x9C
	str r0, [r1, 0x14]
	bl sub_8004914
	ldr r0, [r5]
	adds r0, 0x3C
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	ldr r4, [r5]
	bl sub_8091814
	adds r1, r0, 0
	adds r0, r4, 0
	movs r2, 0xA
	adds r3, r6, 0
	bl sub_8013818
	ldr r0, [r5]
	ldr r1, _08019ED0
	ldrh r1, [r1]
	strh r1, [r0, 0x18]
	bl sub_8013984
	bl sub_801A064
	bl sub_801A0D8
	movs r0, 0x1
	b _08019ED6
	.align 2, 0
_08019EC8: .4byte gUnknown_203B214
_08019ECC: .4byte gUnknown_80DB8CC
_08019ED0: .4byte gUnknown_203B218
_08019ED4:
	movs r0, 0
_08019ED6:
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end sub_8019E40

	thumb_func_start sub_8019EDC
sub_8019EDC:
	push {lr}
	sub sp, 0x4
	lsls r0, 24
	cmp r0, 0
	bne _08019EF8
	ldr r0, _08019EF4
	ldr r0, [r0]
	bl sub_8013660
	movs r0, 0
	b _08019FAA
	.align 2, 0
_08019EF4: .4byte gUnknown_203B214
_08019EF8:
	ldr r0, _08019F10
	ldr r0, [r0]
	bl GetKeyPress
	cmp r0, 0x2
	beq _08019F1A
	cmp r0, 0x2
	bgt _08019F14
	cmp r0, 0x1
	beq _08019F24
	b _08019F88
	.align 2, 0
_08019F10: .4byte gUnknown_203B214
_08019F14:
	cmp r0, 0x4
	beq _08019F7E
	b _08019F88
_08019F1A:
	movs r0, 0x1
	bl sub_80119D4
	movs r0, 0x2
	b _08019FAA
_08019F24:
	bl sub_8019FB0
	lsls r0, 24
	lsrs r0, 24
	bl sub_809185C
	ldrb r2, [r0]
	lsls r2, 16
	ldr r3, _08019F68
	ldr r1, [sp]
	ands r1, r3
	orrs r1, r2
	str r1, [sp]
	ldrb r0, [r0, 0x1]
	lsls r0, 8
	ldr r2, _08019F6C
	ands r1, r2
	orrs r1, r0
	str r1, [sp]
	mov r0, sp
	bl sub_8090C7C
	ldr r1, _08019F70
	ldr r1, [r1]
	movs r2, 0x98
	lsls r2, 2
	adds r1, r2
	ldr r1, [r1]
	cmp r0, r1
	ble _08019F74
	movs r0, 0x2
	bl sub_80119D4
	b _08019F7A
	.align 2, 0
_08019F68: .4byte 0xff00ffff
_08019F6C: .4byte 0xffff00ff
_08019F70: .4byte gUnknown_203B460
_08019F74:
	movs r0, 0
	bl sub_80119D4
_08019F7A:
	movs r0, 0x3
	b _08019FAA
_08019F7E:
	movs r0, 0x4
	bl sub_80119D4
	movs r0, 0x4
	b _08019FAA
_08019F88:
	ldr r0, _08019F9C
	ldr r0, [r0]
	movs r1, 0x1
	bl sub_80138B8
	lsls r0, 24
	cmp r0, 0
	bne _08019FA0
	movs r0, 0
	b _08019FAA
	.align 2, 0
_08019F9C: .4byte gUnknown_203B214
_08019FA0:
	bl sub_801A064
	bl sub_801A0D8
	movs r0, 0x1
_08019FAA:
	add sp, 0x4
	pop {r1}
	bx r1
	thumb_func_end sub_8019EDC

	thumb_func_start sub_8019FB0
sub_8019FB0:
	ldr r0, _08019FC8
	ldr r1, [r0]
	movs r0, 0x1E
	ldrsh r2, [r1, r0]
	movs r3, 0x1C
	ldrsh r0, [r1, r3]
	muls r0, r2
	ldrb r1, [r1, 0x18]
	adds r0, r1
	lsls r0, 24
	lsrs r0, 24
	bx lr
	.align 2, 0
_08019FC8: .4byte gUnknown_203B214
	thumb_func_end sub_8019FB0

	thumb_func_start sub_8019FCC
sub_8019FCC:
	push {r4,r5,lr}
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	bl sub_8004914
	ldr r5, _0801A00C
	ldr r0, [r5]
	adds r0, 0x3C
	movs r1, 0
	movs r2, 0
	bl sub_800641C
	bl sub_8091814
	adds r1, r0, 0
	ldr r0, [r5]
	strh r1, [r0, 0x22]
	bl sub_8013984
	bl sub_801A064
	bl sub_801A0D8
	cmp r4, 0
	beq _0801A006
	ldr r0, [r5]
	bl AddMenuCursorSprite
_0801A006:
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_0801A00C: .4byte gUnknown_203B214
	thumb_func_end sub_8019FCC

	thumb_func_start sub_801A010
sub_801A010:
	push {r4,r5,lr}
	ldr r4, _0801A058
	ldr r2, [r4]
	cmp r2, 0
	beq _0801A050
	ldr r1, _0801A05C
	ldrh r0, [r2, 0x18]
	strh r0, [r1]
	ldr r0, [r2, 0x34]
	lsls r1, r0, 1
	adds r1, r0
	lsls r1, 3
	adds r1, r2, r1
	adds r1, 0x3C
	ldr r0, _0801A060
	ldm r0!, {r2,r3,r5}
	stm r1!, {r2,r3,r5}
	ldm r0!, {r2,r3,r5}
	stm r1!, {r2,r3,r5}
	bl sub_8004914
	ldr r0, [r4]
	adds r0, 0x3C
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	ldr r0, [r4]
	bl MemoryFree
	movs r0, 0
	str r0, [r4]
_0801A050:
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_0801A058: .4byte gUnknown_203B214
_0801A05C: .4byte gUnknown_203B218
_0801A060: .4byte gUnknown_80DB8B4
	thumb_func_end sub_801A010

	thumb_func_start sub_801A064
sub_801A064:
	push {r4,lr}
	ldr r4, _0801A0D4
	ldr r0, [r4]
	ldrh r1, [r0, 0x20]
	adds r0, 0x9C
	movs r2, 0
	strb r1, [r0]
	ldr r0, [r4]
	ldrh r1, [r0, 0x1E]
	adds r0, 0x9D
	strb r1, [r0]
	ldr r0, [r4]
	adds r0, 0x9E
	movs r1, 0xA
	strb r1, [r0]
	ldr r0, [r4]
	adds r0, 0x9F
	strb r2, [r0]
	ldr r0, [r4]
	movs r1, 0x1A
	ldrsh r0, [r0, r1]
	movs r1, 0xC
	bl sub_80095E4
	adds r0, 0x2
	lsls r0, 16
	ldr r2, [r4]
	ldr r3, [r2, 0x34]
	lsls r1, r3, 1
	adds r1, r3
	lsls r1, 3
	adds r1, r2, r1
	adds r1, 0x4A
	asrs r3, r0, 16
	lsrs r0, 16
	strh r0, [r1]
	ldr r1, [r2, 0x34]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 3
	adds r2, r0
	adds r3, 0x2
	adds r2, 0x4C
	strh r3, [r2]
	bl sub_8004914
	ldr r0, [r4]
	adds r0, 0x3C
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0801A0D4: .4byte gUnknown_203B214
	thumb_func_end sub_801A064

	thumb_func_start sub_801A0D8
sub_801A0D8:
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	sub sp, 0xB4
	ldr r4, _0801A1A4
	ldr r0, [r4]
	ldr r0, [r0, 0x34]
	bl sub_8008C54
	ldr r0, [r4]
	ldr r0, [r0, 0x34]
	bl sub_80073B8
	ldr r1, [r4]
	movs r2, 0x1E
	ldrsh r0, [r1, r2]
	lsls r0, 3
	adds r0, 0xA
	ldr r2, _0801A1A8
	ldr r3, [r1, 0x34]
	movs r1, 0
	str r1, [sp]
	bl xxx_call_draw_string
	movs r6, 0
	ldr r0, [r4]
	movs r1, 0x1A
	ldrsh r0, [r0, r1]
	cmp r6, r0
	bge _0801A1EC
	adds r7, r4, 0
	add r4, sp, 0xB0
	mov r9, r6
	add r5, sp, 0x54
	add r2, sp, 0x60
	mov r8, r2
_0801A122:
	ldr r0, [r7]
	movs r2, 0x1E
	ldrsh r1, [r0, r2]
	movs r2, 0x1C
	ldrsh r0, [r0, r2]
	muls r0, r1
	adds r0, r6
	lsls r0, 24
	lsrs r0, 24
	bl sub_809185C
	ldrb r2, [r0]
	lsls r2, 16
	ldr r3, _0801A1AC
	ldr r1, [r4]
	ands r1, r3
	orrs r1, r2
	str r1, [r4]
	ldrb r2, [r0, 0x1]
	lsls r2, 8
	ldr r0, _0801A1B0
	ands r1, r0
	orrs r1, r2
	ldr r0, _0801A1B4
	ands r1, r0
	movs r0, 0x3
	orrs r1, r0
	str r1, [r4]
	movs r1, 0x1
	str r1, [sp, 0x54]
	mov r0, r9
	strb r0, [r5, 0x4]
	movs r0, 0x58
	strh r0, [r5, 0x6]
	strb r1, [r5, 0x8]
	add r0, sp, 0x4
	adds r1, r4, 0
	adds r2, r5, 0
	bl sub_8090E14
	adds r0, r4, 0
	bl sub_8090C7C
	ldr r1, _0801A1B8
	ldr r1, [r1]
	movs r2, 0x98
	lsls r2, 2
	adds r1, r2
	ldr r1, [r1]
	cmp r0, r1
	bgt _0801A1BC
	ldr r0, [r7]
	adds r1, r6, 0
	bl sub_8013800
	adds r1, r0, 0
	ldr r0, [r7]
	ldr r3, [r0, 0x34]
	mov r0, r9
	str r0, [sp]
	movs r0, 0x8
	add r2, sp, 0x4
	bl xxx_call_draw_string
	b _0801A1E0
	.align 2, 0
_0801A1A4: .4byte gUnknown_203B214
_0801A1A8: .4byte gUnknown_80DB8E4
_0801A1AC: .4byte 0xff00ffff
_0801A1B0: .4byte 0xffff00ff
_0801A1B4: .4byte 0xffffff00
_0801A1B8: .4byte gUnknown_203B460
_0801A1BC:
	mov r0, r8
	ldr r1, _0801A204
	add r2, sp, 0x4
	bl sub_800D158
	ldr r0, [r7]
	adds r1, r6, 0
	bl sub_8013800
	adds r1, r0, 0
	ldr r0, [r7]
	ldr r3, [r0, 0x34]
	mov r2, r9
	str r2, [sp]
	movs r0, 0x8
	mov r2, r8
	bl xxx_call_draw_string
_0801A1E0:
	adds r6, 0x1
	ldr r0, [r7]
	movs r1, 0x1A
	ldrsh r0, [r0, r1]
	cmp r6, r0
	blt _0801A122
_0801A1EC:
	ldr r0, _0801A208
	ldr r0, [r0]
	ldr r0, [r0, 0x34]
	bl sub_80073E0
	add sp, 0xB4
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_0801A204: .4byte gUnknown_80DB8EC
_0801A208: .4byte gUnknown_203B214
	thumb_func_end sub_801A0D8

	thumb_func_start sub_801A20C
sub_801A20C:
	push {r4-r6,lr}
	adds r6, r0, 0
	bl sub_8091A48
	cmp r0, 0
	beq _0801A2A0
	ldr r5, _0801A294
	movs r0, 0xA0
	movs r1, 0x8
	bl MemoryAlloc
	str r0, [r5]
	str r6, [r0, 0x34]
	lsls r1, r6, 1
	adds r1, r6
	lsls r1, 3
	adds r1, 0x3C
	adds r1, r0, r1
	str r1, [r0, 0x38]
	adds r0, 0x3C
	bl sub_8006518
	ldr r1, [r5]
	ldr r2, [r1, 0x34]
	lsls r0, r2, 1
	adds r0, r2
	lsls r0, 3
	adds r1, r0
	adds r1, 0x3C
	ldr r0, _0801A298
	ldm r0!, {r2-r4}
	stm r1!, {r2-r4}
	ldm r0!, {r2-r4}
	stm r1!, {r2-r4}
	ldr r0, [r5]
	ldr r1, [r0, 0x38]
	adds r0, 0x9C
	str r0, [r1, 0x14]
	bl sub_8004914
	ldr r0, [r5]
	adds r0, 0x3C
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	ldr r4, [r5]
	bl sub_8091A48
	adds r1, r0, 0
	adds r0, r4, 0
	movs r2, 0xA
	adds r3, r6, 0
	bl sub_8013818
	ldr r0, [r5]
	ldr r1, _0801A29C
	ldrh r1, [r1]
	strh r1, [r0, 0x18]
	bl sub_8013984
	bl sub_801A430
	bl sub_801A4A4
	movs r0, 0x1
	b _0801A2A2
	.align 2, 0
_0801A294: .4byte gUnknown_203B21C
_0801A298: .4byte gUnknown_80DB914
_0801A29C: .4byte gUnknown_203B220
_0801A2A0:
	movs r0, 0
_0801A2A2:
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end sub_801A20C

	thumb_func_start sub_801A2A8
sub_801A2A8:
	push {lr}
	sub sp, 0x4
	lsls r0, 24
	cmp r0, 0
	bne _0801A2C4
	ldr r0, _0801A2C0
	ldr r0, [r0]
	bl sub_8013660
	movs r0, 0
	b _0801A376
	.align 2, 0
_0801A2C0: .4byte gUnknown_203B21C
_0801A2C4:
	ldr r0, _0801A2DC
	ldr r0, [r0]
	bl GetKeyPress
	cmp r0, 0x2
	beq _0801A2E6
	cmp r0, 0x2
	bgt _0801A2E0
	cmp r0, 0x1
	beq _0801A2F0
	b _0801A354
	.align 2, 0
_0801A2DC: .4byte gUnknown_203B21C
_0801A2E0:
	cmp r0, 0x4
	beq _0801A34A
	b _0801A354
_0801A2E6:
	movs r0, 0x1
	bl sub_80119D4
	movs r0, 0x2
	b _0801A376
_0801A2F0:
	bl sub_801A37C
	lsls r0, 24
	lsrs r0, 24
	bl sub_8091A90
	ldrb r2, [r0]
	lsls r2, 16
	ldr r3, _0801A334
	ldr r1, [sp]
	ands r1, r3
	orrs r1, r2
	str r1, [sp]
	ldrb r0, [r0, 0x1]
	lsls r0, 8
	ldr r2, _0801A338
	ands r1, r2
	orrs r1, r0
	str r1, [sp]
	mov r0, sp
	bl sub_8090C7C
	ldr r1, _0801A33C
	ldr r1, [r1]
	movs r2, 0x98
	lsls r2, 2
	adds r1, r2
	ldr r1, [r1]
	cmp r0, r1
	ble _0801A340
	movs r0, 0x2
	bl sub_80119D4
	b _0801A346
	.align 2, 0
_0801A334: .4byte 0xff00ffff
_0801A338: .4byte 0xffff00ff
_0801A33C: .4byte gUnknown_203B460
_0801A340:
	movs r0, 0
	bl sub_80119D4
_0801A346:
	movs r0, 0x3
	b _0801A376
_0801A34A:
	movs r0, 0x4
	bl sub_80119D4
	movs r0, 0x4
	b _0801A376
_0801A354:
	ldr r0, _0801A368
	ldr r0, [r0]
	movs r1, 0x1
	bl sub_80138B8
	lsls r0, 24
	cmp r0, 0
	bne _0801A36C
	movs r0, 0
	b _0801A376
	.align 2, 0
_0801A368: .4byte gUnknown_203B21C
_0801A36C:
	bl sub_801A430
	bl sub_801A4A4
	movs r0, 0x1
_0801A376:
	add sp, 0x4
	pop {r1}
	bx r1
	thumb_func_end sub_801A2A8

	thumb_func_start sub_801A37C
sub_801A37C:
	ldr r0, _0801A394
	ldr r1, [r0]
	movs r0, 0x1E
	ldrsh r2, [r1, r0]
	movs r3, 0x1C
	ldrsh r0, [r1, r3]
	muls r0, r2
	ldrb r1, [r1, 0x18]
	adds r0, r1
	lsls r0, 24
	lsrs r0, 24
	bx lr
	.align 2, 0
_0801A394: .4byte gUnknown_203B21C
	thumb_func_end sub_801A37C

	thumb_func_start sub_801A398
sub_801A398:
	push {r4,r5,lr}
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	bl sub_8004914
	ldr r5, _0801A3D8
	ldr r0, [r5]
	adds r0, 0x3C
	movs r1, 0
	movs r2, 0
	bl sub_800641C
	bl sub_8091A48
	adds r1, r0, 0
	ldr r0, [r5]
	strh r1, [r0, 0x22]
	bl sub_8013984
	bl sub_801A430
	bl sub_801A4A4
	cmp r4, 0
	beq _0801A3D2
	ldr r0, [r5]
	bl AddMenuCursorSprite
_0801A3D2:
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_0801A3D8: .4byte gUnknown_203B21C
	thumb_func_end sub_801A398

	thumb_func_start sub_801A3DC
sub_801A3DC:
	push {r4,r5,lr}
	ldr r4, _0801A424
	ldr r2, [r4]
	cmp r2, 0
	beq _0801A41C
	ldr r1, _0801A428
	ldrh r0, [r2, 0x18]
	strh r0, [r1]
	ldr r0, [r2, 0x34]
	lsls r1, r0, 1
	adds r1, r0
	lsls r1, 3
	adds r1, r2, r1
	adds r1, 0x3C
	ldr r0, _0801A42C
	ldm r0!, {r2,r3,r5}
	stm r1!, {r2,r3,r5}
	ldm r0!, {r2,r3,r5}
	stm r1!, {r2,r3,r5}
	bl sub_8004914
	ldr r0, [r4]
	adds r0, 0x3C
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	ldr r0, [r4]
	bl MemoryFree
	movs r0, 0
	str r0, [r4]
_0801A41C:
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_0801A424: .4byte gUnknown_203B21C
_0801A428: .4byte gUnknown_203B220
_0801A42C: .4byte gUnknown_80DB8FC
	thumb_func_end sub_801A3DC

	thumb_func_start sub_801A430
sub_801A430:
	push {r4,lr}
	ldr r4, _0801A4A0
	ldr r0, [r4]
	ldrh r1, [r0, 0x20]
	adds r0, 0x9C
	movs r2, 0
	strb r1, [r0]
	ldr r0, [r4]
	ldrh r1, [r0, 0x1E]
	adds r0, 0x9D
	strb r1, [r0]
	ldr r0, [r4]
	adds r0, 0x9E
	movs r1, 0xA
	strb r1, [r0]
	ldr r0, [r4]
	adds r0, 0x9F
	strb r2, [r0]
	ldr r0, [r4]
	movs r1, 0x1A
	ldrsh r0, [r0, r1]
	movs r1, 0xC
	bl sub_80095E4
	adds r0, 0x2
	lsls r0, 16
	ldr r2, [r4]
	ldr r3, [r2, 0x34]
	lsls r1, r3, 1
	adds r1, r3
	lsls r1, 3
	adds r1, r2, r1
	adds r1, 0x4A
	asrs r3, r0, 16
	lsrs r0, 16
	strh r0, [r1]
	ldr r1, [r2, 0x34]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 3
	adds r2, r0
	adds r3, 0x2
	adds r2, 0x4C
	strh r3, [r2]
	bl sub_8004914
	ldr r0, [r4]
	adds r0, 0x3C
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0801A4A0: .4byte gUnknown_203B21C
	thumb_func_end sub_801A430

	thumb_func_start sub_801A4A4
sub_801A4A4:
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	sub sp, 0xB4
	ldr r4, _0801A570
	ldr r0, [r4]
	ldr r0, [r0, 0x34]
	bl sub_8008C54
	ldr r0, [r4]
	ldr r0, [r0, 0x34]
	bl sub_80073B8
	ldr r1, [r4]
	movs r2, 0x1E
	ldrsh r0, [r1, r2]
	lsls r0, 3
	adds r0, 0xA
	ldr r2, _0801A574
	ldr r3, [r1, 0x34]
	movs r1, 0
	str r1, [sp]
	bl xxx_call_draw_string
	movs r6, 0
	ldr r0, [r4]
	movs r1, 0x1A
	ldrsh r0, [r0, r1]
	cmp r6, r0
	bge _0801A5B8
	adds r7, r4, 0
	add r4, sp, 0xB0
	mov r9, r6
	add r5, sp, 0x54
	add r2, sp, 0x60
	mov r8, r2
_0801A4EE:
	ldr r0, [r7]
	movs r2, 0x1E
	ldrsh r1, [r0, r2]
	movs r2, 0x1C
	ldrsh r0, [r0, r2]
	muls r0, r1
	adds r0, r6
	lsls r0, 24
	lsrs r0, 24
	bl sub_8091A90
	ldrb r2, [r0]
	lsls r2, 16
	ldr r3, _0801A578
	ldr r1, [r4]
	ands r1, r3
	orrs r1, r2
	str r1, [r4]
	ldrb r2, [r0, 0x1]
	lsls r2, 8
	ldr r0, _0801A57C
	ands r1, r0
	orrs r1, r2
	ldr r0, _0801A580
	ands r1, r0
	movs r0, 0x3
	orrs r1, r0
	str r1, [r4]
	movs r1, 0x1
	str r1, [sp, 0x54]
	mov r0, r9
	strb r0, [r5, 0x4]
	movs r0, 0x58
	strh r0, [r5, 0x6]
	strb r1, [r5, 0x8]
	add r0, sp, 0x4
	adds r1, r4, 0
	adds r2, r5, 0
	bl sub_8090E14
	adds r0, r4, 0
	bl sub_8090C7C
	ldr r1, _0801A584
	ldr r1, [r1]
	movs r2, 0x98
	lsls r2, 2
	adds r1, r2
	ldr r1, [r1]
	cmp r0, r1
	bgt _0801A588
	ldr r0, [r7]
	adds r1, r6, 0
	bl sub_8013800
	adds r1, r0, 0
	ldr r0, [r7]
	ldr r3, [r0, 0x34]
	mov r0, r9
	str r0, [sp]
	movs r0, 0x8
	add r2, sp, 0x4
	bl xxx_call_draw_string
	b _0801A5AC
	.align 2, 0
_0801A570: .4byte gUnknown_203B21C
_0801A574: .4byte gUnknown_80DB92C
_0801A578: .4byte 0xff00ffff
_0801A57C: .4byte 0xffff00ff
_0801A580: .4byte 0xffffff00
_0801A584: .4byte gUnknown_203B460
_0801A588:
	mov r0, r8
	ldr r1, _0801A5D0
	add r2, sp, 0x4
	bl sub_800D158
	ldr r0, [r7]
	adds r1, r6, 0
	bl sub_8013800
	adds r1, r0, 0
	ldr r0, [r7]
	ldr r3, [r0, 0x34]
	mov r2, r9
	str r2, [sp]
	movs r0, 0x8
	mov r2, r8
	bl xxx_call_draw_string
_0801A5AC:
	adds r6, 0x1
	ldr r0, [r7]
	movs r1, 0x1A
	ldrsh r0, [r0, r1]
	cmp r6, r0
	blt _0801A4EE
_0801A5B8:
	ldr r0, _0801A5D4
	ldr r0, [r0]
	ldr r0, [r0, 0x34]
	bl sub_80073E0
	add sp, 0xB4
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_0801A5D0: .4byte gUnknown_80DB934
_0801A5D4: .4byte gUnknown_203B21C
	thumb_func_end sub_801A4A4

	thumb_func_start sub_801A5D8
sub_801A5D8:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	adds r4, r0, 0
	adds r6, r1, 0
	adds r7, r2, 0
	mov r8, r3
	bl sub_8090A34
	cmp r0, 0
	bne _0801A5F2
	movs r0, 0
	b _0801A6CC
_0801A5F2:
	ldr r5, _0801A6D8
	ldr r0, [r5]
	cmp r0, 0
	bne _0801A604
	movs r0, 0xF4
	movs r1, 0x8
	bl MemoryAlloc
	str r0, [r5]
_0801A604:
	ldr r0, [r5]
	str r4, [r0]
	bl sub_80910B4
	bl sub_801AE84
	ldr r0, [r5]
	adds r1, r0, 0
	adds r1, 0x88
	str r6, [r1]
	adds r2, r0, 0
	adds r2, 0x8C
	lsls r1, r6, 1
	adds r1, r6
	lsls r1, 3
	adds r1, 0x90
	adds r1, r0, r1
	str r1, [r2]
	adds r0, 0x90
	bl sub_8006518
	ldr r1, [r5]
	adds r0, r1, 0
	adds r0, 0x88
	ldr r2, [r0]
	lsls r0, r2, 1
	adds r0, r2
	lsls r0, 3
	adds r1, r0
	adds r1, 0x90
	ldr r0, _0801A6DC
	ldm r0!, {r2-r4}
	stm r1!, {r2-r4}
	ldm r0!, {r2-r4}
	stm r1!, {r2-r4}
	ldr r2, [r5]
	adds r0, r2, 0
	adds r0, 0x8C
	ldr r1, [r0]
	adds r0, 0x64
	str r0, [r1, 0x14]
	cmp r7, 0
	beq _0801A66E
	subs r0, 0x68
	ldr r1, [r0]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 3
	adds r1, r2, 0
	adds r1, 0x98
	adds r1, r0
	ldr r0, [r7]
	str r0, [r1]
_0801A66E:
	ldr r0, [r5]
	adds r0, 0x8C
	ldr r0, [r0]
	mov r1, r8
	bl sub_8012D08
	movs r0, 0x1
	bl sub_8099690
	bl sub_8004914
	ldr r0, [r5]
	adds r0, 0x90
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	ldr r4, [r5]
	adds r4, 0x54
	bl sub_8090A34
	adds r1, r0, 0
	adds r0, r4, 0
	mov r2, r8
	adds r3, r6, 0
	bl sub_8013818
	ldr r2, [r5]
	ldr r0, _0801A6E0
	ldrh r1, [r0]
	adds r0, r2, 0
	adds r0, 0x6C
	strh r1, [r0]
	ldr r0, _0801A6E4
	ldrh r0, [r0]
	adds r1, r2, 0
	adds r1, 0x72
	strh r0, [r1]
	adds r0, r2, 0
	adds r0, 0x54
	bl sub_8013984
	bl sub_801A998
	bl sub_801A9E0
	movs r0, 0x1
_0801A6CC:
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r1}
	bx r1
	.align 2, 0
_0801A6D8: .4byte gUnknown_203B224
_0801A6DC: .4byte gUnknown_80DB95C
_0801A6E0: .4byte gUnknown_203B228
_0801A6E4: .4byte gUnknown_203B22A
	thumb_func_end sub_801A5D8

	thumb_func_start sub_801A6E8
sub_801A6E8:
	push {r4,r5,lr}
	sub sp, 0x4
	lsls r0, 24
	cmp r0, 0
	bne _0801A704
	ldr r0, _0801A700
	ldr r0, [r0]
	adds r0, 0x54
	bl sub_8013660
	movs r0, 0
	b _0801A8A2
	.align 2, 0
_0801A700: .4byte gUnknown_203B224
_0801A704:
	ldr r0, _0801A720
	ldr r0, [r0]
	adds r0, 0x54
	bl GetKeyPress
	subs r0, 0x1
	cmp r0, 0x5
	bls _0801A716
	b _0801A87C
_0801A716:
	lsls r0, 2
	ldr r1, _0801A724
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0801A720: .4byte gUnknown_203B224
_0801A724: .4byte _0801A728
	.align 2, 0
_0801A728:
	.4byte _0801A74A
	.4byte _0801A740
	.4byte _0801A864
	.4byte _0801A806
	.4byte _0801A810
	.4byte _0801A810
_0801A740:
	movs r0, 0x1
	bl sub_80119D4
	movs r0, 0x2
	b _0801A8A2
_0801A74A:
	ldr r1, _0801A760
	ldr r0, [r1]
	ldr r0, [r0]
	adds r4, r1, 0
	cmp r0, 0x5
	bhi _0801A802
	lsls r0, 2
	ldr r1, _0801A764
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0801A760: .4byte gUnknown_203B224
_0801A764: .4byte _0801A768
	.align 2, 0
_0801A768:
	.4byte _0801A780
	.4byte _0801A780
	.4byte _0801A780
	.4byte _0801A794
	.4byte _0801A7AC
	.4byte _0801A7FC
_0801A780:
	ldr r4, [r4]
	bl sub_801A8AC
	lsls r0, 2
	adds r4, 0x4
	adds r4, r0
	ldr r0, [r4]
	cmp r0, 0
	bne _0801A7F4
	b _0801A7E2
_0801A794:
	bl sub_801AEA8
	cmp r0, 0
	bne _0801A7E2
	bl sub_801A8AC
	bl sub_801ADA0
	lsls r0, 24
	cmp r0, 0
	bne _0801A7E2
	b _0801A7F4
_0801A7AC:
	ldr r5, _0801A7EC
	ldr r4, [r5]
	bl sub_801A8AC
	lsls r0, 2
	adds r4, r0
	ldr r0, [r4]
	str r0, [sp]
	mov r0, sp
	ldrb r0, [r0, 0x2]
	bl sub_80914E4
	lsls r0, 24
	cmp r0, 0
	beq _0801A7F4
	mov r0, sp
	bl sub_8090CCC
	ldr r1, [r5]
	movs r2, 0x98
	lsls r2, 2
	adds r1, r2
	ldr r1, [r1]
	adds r0, r1
	ldr r1, _0801A7F0
	cmp r0, r1
	bgt _0801A7F4
_0801A7E2:
	movs r0, 0
	bl sub_80119D4
	b _0801A802
	.align 2, 0
_0801A7EC: .4byte gUnknown_203B460
_0801A7F0: .4byte 0x0001869f
_0801A7F4:
	movs r0, 0x2
	bl sub_80119D4
	b _0801A802
_0801A7FC:
	movs r0, 0
	bl sub_80119D4
_0801A802:
	movs r0, 0x3
	b _0801A8A2
_0801A806:
	movs r0, 0x4
	bl sub_80119D4
	movs r0, 0x4
	b _0801A8A2
_0801A810:
	ldr r4, _0801A858
	ldr r0, [r4]
	ldr r0, [r0]
	cmp r0, 0x3
	bne _0801A87C
	bl sub_801A8AC
	adds r1, r0, 0
	ldr r0, [r4]
	lsls r5, r1, 2
	adds r0, 0x4
	adds r0, r5
	ldr r0, [r0]
	cmp r0, 0
	bne _0801A83A
	adds r0, r1, 0
	bl sub_801ADA0
	lsls r0, 24
	cmp r0, 0
	beq _0801A85C
_0801A83A:
	movs r0, 0x6
	bl sub_80119D4
	ldr r0, [r4]
	adds r2, r0, 0x4
	adds r2, r5
	ldr r1, [r2]
	movs r3, 0x1
	eors r1, r3
	str r1, [r2]
	adds r0, 0x54
	movs r1, 0
	bl sub_80138B8
	b _0801A89C
	.align 2, 0
_0801A858: .4byte gUnknown_203B224
_0801A85C:
	movs r0, 0x2
	bl sub_80119D4
	b _0801A87C
_0801A864:
	ldr r0, _0801A894
	ldr r0, [r0]
	ldr r0, [r0]
	cmp r0, 0x2
	beq _0801A87C
	movs r0, 0x5
	bl sub_80119D4
	bl sub_801AEF8
	bl sub_801A9E0
_0801A87C:
	ldr r0, _0801A894
	ldr r0, [r0]
	adds r0, 0x54
	movs r1, 0x1
	bl sub_80138B8
	lsls r0, 24
	cmp r0, 0
	bne _0801A898
	movs r0, 0
	b _0801A8A2
	.align 2, 0
_0801A894: .4byte gUnknown_203B224
_0801A898:
	bl sub_801A998
_0801A89C:
	bl sub_801A9E0
	movs r0, 0x1
_0801A8A2:
	add sp, 0x4
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_801A6E8

	thumb_func_start sub_801A8AC
sub_801A8AC:
	ldr r0, _0801A8CC
	ldr r2, [r0]
	adds r0, r2, 0
	adds r0, 0x72
	movs r3, 0
	ldrsh r1, [r0, r3]
	subs r0, 0x2
	movs r3, 0
	ldrsh r0, [r0, r3]
	muls r0, r1
	adds r1, r2, 0
	adds r1, 0x6C
	movs r2, 0
	ldrsh r1, [r1, r2]
	adds r0, r1
	bx lr
	.align 2, 0
_0801A8CC: .4byte gUnknown_203B224
	thumb_func_end sub_801A8AC

	thumb_func_start sub_801A8D0
sub_801A8D0:
	push {r4,r5,lr}
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	movs r0, 0x1
	bl sub_8099690
	bl sub_8004914
	ldr r5, _0801A924
	ldr r0, [r5]
	adds r0, 0x90
	movs r1, 0
	movs r2, 0
	bl sub_800641C
	bl sub_80910B4
	bl sub_8090A34
	adds r1, r0, 0
	ldr r0, [r5]
	adds r2, r0, 0
	adds r2, 0x76
	strh r1, [r2]
	adds r0, 0x54
	bl sub_8013984
	bl sub_801A998
	bl sub_801A9E0
	cmp r4, 0
	beq _0801A91C
	ldr r0, [r5]
	adds r0, 0x54
	bl AddMenuCursorSprite
_0801A91C:
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_0801A924: .4byte gUnknown_203B224
	thumb_func_end sub_801A8D0

	thumb_func_start sub_801A928
sub_801A928:
	push {r4,r5,lr}
	ldr r4, _0801A988
	ldr r2, [r4]
	cmp r2, 0
	beq _0801A980
	ldr r1, _0801A98C
	adds r0, r2, 0
	adds r0, 0x6C
	ldrh r0, [r0]
	strh r0, [r1]
	ldr r1, _0801A990
	adds r0, r2, 0
	adds r0, 0x72
	ldrh r0, [r0]
	strh r0, [r1]
	adds r0, r2, 0
	adds r0, 0x88
	ldr r0, [r0]
	lsls r1, r0, 1
	adds r1, r0
	lsls r1, 3
	adds r1, r2, r1
	adds r1, 0x90
	ldr r0, _0801A994
	ldm r0!, {r2,r3,r5}
	stm r1!, {r2,r3,r5}
	ldm r0!, {r2,r3,r5}
	stm r1!, {r2,r3,r5}
	movs r0, 0
	bl sub_8099690
	bl sub_8004914
	ldr r0, [r4]
	adds r0, 0x90
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	ldr r0, [r4]
	bl MemoryFree
	movs r0, 0
	str r0, [r4]
_0801A980:
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_0801A988: .4byte gUnknown_203B224
_0801A98C: .4byte gUnknown_203B228
_0801A990: .4byte gUnknown_203B22A
_0801A994: .4byte gUnknown_80DB944
	thumb_func_end sub_801A928

	thumb_func_start sub_801A998
sub_801A998:
	push {r4,lr}
	ldr r4, _0801A9DC
	ldr r0, [r4]
	adds r1, r0, 0
	adds r1, 0x74
	ldrh r1, [r1]
	adds r0, 0xF0
	movs r2, 0
	strb r1, [r0]
	ldr r0, [r4]
	adds r1, r0, 0
	adds r1, 0x72
	ldrh r1, [r1]
	adds r0, 0xF1
	strb r1, [r0]
	ldr r0, [r4]
	adds r0, 0xF2
	movs r1, 0xB
	strb r1, [r0]
	ldr r0, [r4]
	adds r0, 0xF3
	strb r2, [r0]
	bl sub_8004914
	ldr r0, [r4]
	adds r0, 0x90
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0801A9DC: .4byte gUnknown_203B224
	thumb_func_end sub_801A998

	thumb_func_start sub_801A9E0
sub_801A9E0:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0xCC
	ldr r4, _0801AA2C
	ldr r0, [r4]
	adds r0, 0x88
	ldr r0, [r0]
	bl sub_8008C54
	ldr r0, [r4]
	adds r0, 0x88
	ldr r0, [r0]
	bl sub_80073B8
	ldr r4, [r4]
	adds r1, r4, 0
	adds r1, 0x72
	movs r2, 0
	ldrsh r0, [r1, r2]
	lsls r0, 3
	adds r5, r0, 0
	adds r5, 0xA
	movs r3, 0
	ldrsh r1, [r1, r3]
	cmp r1, 0
	bne _0801AA34
	ldr r2, _0801AA30
	adds r0, r4, 0
	adds r0, 0x88
	ldr r3, [r0]
	str r1, [sp]
	adds r0, r5, 0
	movs r1, 0
	bl xxx_call_draw_string
	b _0801AA48
	.align 2, 0
_0801AA2C: .4byte gUnknown_203B224
_0801AA30: .4byte gUnknown_80DB974
_0801AA34:
	ldr r2, _0801AA58
	adds r0, r4, 0
	adds r0, 0x88
	ldr r3, [r0]
	movs r0, 0
	str r0, [sp]
	adds r0, r5, 0
	movs r1, 0
	bl xxx_call_draw_string
_0801AA48:
	movs r7, 0
	ldr r1, _0801AA5C
	ldr r0, [r1]
	adds r0, 0x6E
	movs r4, 0
	ldrsh r0, [r0, r4]
	b _0801AD0A
	.align 2, 0
_0801AA58: .4byte gUnknown_80DB984
_0801AA5C: .4byte gUnknown_203B224
_0801AA60:
	ldr r2, [r1]
	adds r0, r2, 0
	adds r0, 0x72
	movs r3, 0
	ldrsh r1, [r0, r3]
	subs r0, 0x2
	movs r4, 0
	ldrsh r0, [r0, r4]
	muls r0, r1
	adds r0, r7
	mov r8, r0
	ldr r0, _0801AA9C
	ldr r0, [r0]
	mov r3, r8
	lsls r1, r3, 2
	adds r0, r1
	ldr r0, [r0]
	add r1, sp, 0xC8
	str r0, [r1]
	ldr r0, [r2]
	adds r4, r1, 0
	cmp r0, 0x5
	bls _0801AA90
	b _0801ACC4
_0801AA90:
	lsls r0, 2
	ldr r1, _0801AAA0
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0801AA9C: .4byte gUnknown_203B460
_0801AAA0: .4byte _0801AAA4
	.align 2, 0
_0801AAA4:
	.4byte _0801AABC
	.4byte _0801AAE4
	.4byte _0801AAE4
	.4byte _0801AB18
	.4byte _0801AB90
	.4byte _0801AC50
_0801AABC:
	add r0, sp, 0x4
	adds r1, r4, 0
	movs r2, 0
	bl sub_8090E14
	ldr r4, _0801AAE0
	ldr r0, [r4]
	adds r0, 0x54
	adds r1, r7, 0
	bl sub_8013800
	adds r1, r0, 0
	ldr r0, [r4]
	adds r0, 0x88
	ldr r3, [r0]
	movs r0, 0
	str r0, [sp]
	b _0801AC8C
	.align 2, 0
_0801AAE0: .4byte gUnknown_203B224
_0801AAE4:
	add r2, sp, 0x54
	movs r5, 0
	str r5, [sp, 0x54]
	strb r5, [r2, 0x4]
	movs r0, 0x1
	strb r0, [r2, 0x8]
	strb r0, [r4]
	add r1, sp, 0xC8
	add r0, sp, 0x4
	bl sub_8090E14
	ldr r4, _0801AB14
	ldr r0, [r4]
	adds r0, 0x54
	adds r1, r7, 0
	bl sub_8013800
	adds r1, r0, 0
	ldr r0, [r4]
	adds r0, 0x88
	ldr r3, [r0]
	str r5, [sp]
	b _0801AC8C
	.align 2, 0
_0801AB14: .4byte gUnknown_203B224
_0801AB18:
	add r2, sp, 0x60
	movs r6, 0
	str r6, [sp, 0x60]
	strb r6, [r2, 0x4]
	movs r0, 0x1
	strb r0, [r2, 0x8]
	strb r0, [r4]
	add r1, sp, 0xC8
	add r0, sp, 0x4
	bl sub_8090E14
	ldr r5, _0801AB60
	ldr r0, [r5]
	mov r4, r8
	lsls r1, r4, 2
	adds r0, 0x4
	adds r0, r1
	ldr r0, [r0]
	cmp r0, 0
	bne _0801AB4E
	mov r0, r8
	bl sub_801ADA0
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0
	beq _0801AB64
_0801AB4E:
	ldr r0, [r5]
	adds r0, 0x54
	adds r1, r7, 0
	bl sub_8013800
	adds r1, r0, 0
	ldr r0, [r5]
	b _0801AC86
	.align 2, 0
_0801AB60: .4byte gUnknown_203B224
_0801AB64:
	ldr r0, _0801AB88
	add r1, sp, 0x4
	movs r2, 0x50
	bl strncpy
	ldr r0, [r5]
	adds r0, 0x54
	adds r1, r7, 0
	bl sub_8013800
	adds r1, r0, 0
	ldr r2, _0801AB8C
	ldr r0, [r5]
	adds r0, 0x88
	ldr r3, [r0]
	str r4, [sp]
	b _0801AC3C
	.align 2, 0
_0801AB88: .4byte gUnknown_202DE58
_0801AB8C: .4byte gUnknown_80DB994
_0801AB90:
	ldrb r0, [r4, 0x2]
	bl sub_80914E4
	lsls r0, 24
	lsrs r5, r0, 24
	cmp r5, 0
	beq _0801AC10
	add r2, sp, 0x6C
	movs r1, 0x3
	str r1, [sp, 0x6C]
	movs r6, 0
	strb r6, [r2, 0x4]
	movs r0, 0x58
	strh r0, [r2, 0x6]
	movs r0, 0x1
	strb r0, [r2, 0x8]
	strb r1, [r4]
	add r0, sp, 0x4
	adds r1, r4, 0
	bl sub_8090E14
	adds r0, r4, 0
	bl sub_8090CCC
	ldr r1, _0801AC00
	ldr r1, [r1]
	movs r2, 0x98
	lsls r2, 2
	adds r1, r2
	ldr r1, [r1]
	adds r0, r1
	ldr r1, _0801AC04
	cmp r0, r1
	ble _0801AC76
	add r5, sp, 0x78
	ldr r1, _0801AC08
	adds r0, r5, 0
	add r2, sp, 0x4
	bl sub_800D158
	ldr r4, _0801AC0C
	ldr r0, [r4]
	adds r0, 0x54
	adds r1, r7, 0
	bl sub_8013800
	adds r1, r0, 0
	ldr r0, [r4]
	adds r0, 0x88
	ldr r3, [r0]
	str r6, [sp]
	movs r0, 0x8
	adds r2, r5, 0
	bl xxx_call_draw_string
	b _0801ACC4
	.align 2, 0
_0801AC00: .4byte gUnknown_203B460
_0801AC04: .4byte 0x0001869f
_0801AC08: .4byte gUnknown_80DB9A0
_0801AC0C: .4byte gUnknown_203B224
_0801AC10:
	add r0, sp, 0x4
	adds r1, r4, 0
	movs r2, 0
	bl sub_8090E14
	ldr r0, _0801AC44
	add r1, sp, 0x4
	movs r2, 0x50
	bl strncpy
	ldr r4, _0801AC48
	ldr r0, [r4]
	adds r0, 0x54
	adds r1, r7, 0
	bl sub_8013800
	adds r1, r0, 0
	ldr r2, _0801AC4C
	ldr r0, [r4]
	adds r0, 0x88
	ldr r3, [r0]
	str r5, [sp]
_0801AC3C:
	movs r0, 0x8
	bl sub_8014FF0
	b _0801ACC4
	.align 2, 0
_0801AC44: .4byte gUnknown_202DE58
_0801AC48: .4byte gUnknown_203B224
_0801AC4C: .4byte gUnknown_80DB994
_0801AC50:
	add r2, sp, 0x78
	movs r6, 0
	str r6, [sp, 0x78]
	strb r6, [r2, 0x4]
	movs r0, 0x1
	strb r0, [r2, 0x8]
	strb r0, [r4]
	add r4, sp, 0xC8
	add r0, sp, 0x4
	adds r1, r4, 0
	bl sub_8090E14
	ldrb r0, [r4, 0x2]
	bl sub_8091764
	lsls r0, 24
	lsrs r5, r0, 24
	cmp r5, 0
	beq _0801AC9C
_0801AC76:
	ldr r4, _0801AC98
	ldr r0, [r4]
	adds r0, 0x54
	adds r1, r7, 0
	bl sub_8013800
	adds r1, r0, 0
	ldr r0, [r4]
_0801AC86:
	adds r0, 0x88
	ldr r3, [r0]
	str r6, [sp]
_0801AC8C:
	movs r0, 0x8
	add r2, sp, 0x4
	bl xxx_call_draw_string
	b _0801ACC4
	.align 2, 0
_0801AC98: .4byte gUnknown_203B224
_0801AC9C:
	ldr r0, _0801AD28
	add r1, sp, 0x4
	movs r2, 0x50
	bl strncpy
	ldr r4, _0801AD2C
	ldr r0, [r4]
	adds r0, 0x54
	adds r1, r7, 0
	bl sub_8013800
	adds r1, r0, 0
	ldr r2, _0801AD30
	ldr r0, [r4]
	adds r0, 0x88
	ldr r3, [r0]
	str r5, [sp]
	movs r0, 0x8
	bl sub_8014FF0
_0801ACC4:
	mov r0, r8
	bl sub_801AED0
	movs r1, 0x1
	ands r1, r0
	cmp r1, 0
	beq _0801ACFE
	ldr r4, _0801AD2C
	ldr r0, [r4]
	adds r0, 0x54
	adds r1, r7, 0
	bl sub_8013800
	adds r2, r0, 0
	ldr r1, [r4]
	adds r0, r1, 0
	adds r0, 0x88
	ldr r0, [r0]
	adds r1, 0x8C
	ldr r1, [r1]
	movs r4, 0xC
	ldrsh r3, [r1, r4]
	subs r3, 0x2
	lsls r3, 3
	movs r1, 0xA
	str r1, [sp]
	movs r1, 0x8
	bl sub_8007B7C
_0801ACFE:
	adds r7, 0x1
	ldr r1, _0801AD2C
	ldr r0, [r1]
	adds r0, 0x6E
	movs r2, 0
	ldrsh r0, [r0, r2]
_0801AD0A:
	adds r2, r1, 0
	cmp r7, r0
	bge _0801AD12
	b _0801AA60
_0801AD12:
	ldr r0, [r2]
	adds r0, 0x88
	ldr r0, [r0]
	bl sub_80073E0
	add sp, 0xCC
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_0801AD28: .4byte gUnknown_202DE58
_0801AD2C: .4byte gUnknown_203B224
_0801AD30: .4byte gUnknown_80DB994
	thumb_func_end sub_801A9E0

	thumb_func_start sub_801AD34
sub_801AD34:
	push {r4-r6,lr}
	sub sp, 0x8
	adds r4, r0, 0
	bl sub_8008C54
	adds r0, r4, 0
	bl sub_80073B8
	ldr r2, _0801AD98
	movs r6, 0
	str r6, [sp]
	movs r0, 0x6
	movs r1, 0
	adds r3, r4, 0
	bl xxx_call_draw_string
	bl sub_8090A34
	adds r2, r0, 0
	movs r5, 0x7
	str r5, [sp]
	str r4, [sp, 0x4]
	movs r0, 0x12
	movs r1, 0xD
	movs r3, 0x2
	bl sub_8012BC4
	ldr r2, _0801AD9C
	str r6, [sp]
	movs r0, 0x16
	movs r1, 0xD
	adds r3, r4, 0
	bl xxx_call_draw_string
	str r5, [sp]
	str r4, [sp, 0x4]
	movs r0, 0x2B
	movs r1, 0xD
	movs r2, 0x14
	movs r3, 0x2
	bl sub_8012BC4
	adds r0, r4, 0
	bl sub_80073E0
	add sp, 0x8
	pop {r4-r6}
	pop {r0}
	bx r0
	.align 2, 0
_0801AD98: .4byte gUnknown_80DB9A8
_0801AD9C: .4byte gUnknown_80DB9B0
	thumb_func_end sub_801AD34

	thumb_func_start sub_801ADA0
sub_801ADA0:
	push {r4-r6,lr}
	ldr r5, _0801ADEC
	ldr r1, [r5]
	lsls r0, 2
	adds r1, r0
	ldr r6, [r1]
	lsls r4, r6, 8
	lsrs r0, r4, 24
	bl sub_8091524
	lsls r0, 24
	cmp r0, 0
	beq _0801AE12
	lsrs r0, r4, 24
	bl sub_8090A60
	lsls r0, 24
	cmp r0, 0
	beq _0801ADF4
	lsrs r0, r4, 24
	bl sub_801AE24
	ldr r2, [r5]
	lsrs r1, r4, 24
	lsls r1, 1
	adds r2, 0x50
	adds r2, r1
	lsls r0, 16
	lsrs r0, 16
	ldrh r2, [r2]
	adds r0, r2
	lsrs r1, r6, 8
	lsls r1, 24
	lsrs r1, 24
	adds r0, r1
	ldr r1, _0801ADF0
	b _0801AE0E
	.align 2, 0
_0801ADEC: .4byte gUnknown_203B460
_0801ADF0: .4byte 0x000003e7
_0801ADF4:
	lsrs r0, r4, 24
	bl sub_801AE24
	ldr r2, [r5]
	lsrs r1, r4, 24
	lsls r1, 1
	adds r2, 0x50
	adds r2, r1
	lsls r0, 16
	lsrs r0, 16
	ldrh r2, [r2]
	adds r0, r2
	ldr r1, _0801AE18
_0801AE0E:
	cmp r0, r1
	ble _0801AE1C
_0801AE12:
	movs r0, 0
	b _0801AE1E
	.align 2, 0
_0801AE18: .4byte 0x000003e6
_0801AE1C:
	movs r0, 0x1
_0801AE1E:
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end sub_801ADA0

	thumb_func_start sub_801AE24
sub_801AE24:
	push {r4-r7,lr}
	adds r7, r0, 0
	movs r5, 0
	movs r6, 0
	b _0801AE74
_0801AE2E:
	ldr r0, _0801AE64
	ldr r0, [r0]
	lsls r1, r6, 2
	adds r0, 0x4
	adds r0, r1
	ldr r0, [r0]
	cmp r0, 0
	beq _0801AE72
	ldr r0, _0801AE68
	ldr r0, [r0]
	adds r0, r1
	ldr r4, [r0]
	lsls r1, r4, 8
	lsrs r0, r1, 24
	cmp r0, r7
	bne _0801AE72
	bl sub_8090A60
	lsls r0, 24
	cmp r0, 0
	beq _0801AE6C
	lsrs r0, r4, 8
	lsls r0, 24
	lsrs r0, 24
	adds r0, r5, r0
	b _0801AE6E
	.align 2, 0
_0801AE64: .4byte gUnknown_203B224
_0801AE68: .4byte gUnknown_203B460
_0801AE6C:
	adds r0, r5, 0x1
_0801AE6E:
	lsls r0, 16
	lsrs r5, r0, 16
_0801AE72:
	adds r6, 0x1
_0801AE74:
	bl sub_8090A34
	cmp r6, r0
	blt _0801AE2E
	adds r0, r5, 0
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_801AE24

	thumb_func_start sub_801AE84
sub_801AE84:
	push {r4,lr}
	movs r2, 0
	ldr r4, _0801AEA4
	movs r3, 0
_0801AE8C:
	ldr r0, [r4]
	lsls r1, r2, 2
	adds r0, 0x4
	adds r0, r1
	str r3, [r0]
	adds r2, 0x1
	cmp r2, 0x13
	ble _0801AE8C
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0801AEA4: .4byte gUnknown_203B224
	thumb_func_end sub_801AE84

	thumb_func_start sub_801AEA8
sub_801AEA8:
	push {lr}
	movs r3, 0
	ldr r0, _0801AECC
	ldr r0, [r0]
	adds r1, r0, 0x4
	movs r2, 0x13
_0801AEB4:
	ldr r0, [r1]
	cmp r0, 0
	beq _0801AEBC
	adds r3, 0x1
_0801AEBC:
	adds r1, 0x4
	subs r2, 0x1
	cmp r2, 0
	bge _0801AEB4
	adds r0, r3, 0
	pop {r1}
	bx r1
	.align 2, 0
_0801AECC: .4byte gUnknown_203B224
	thumb_func_end sub_801AEA8

	thumb_func_start sub_801AED0
sub_801AED0:
	ldr r1, _0801AEE0
	ldr r1, [r1]
	lsls r0, 2
	adds r1, 0x4
	adds r1, r0
	ldr r0, [r1]
	bx lr
	.align 2, 0
_0801AEE0: .4byte gUnknown_203B224
	thumb_func_end sub_801AED0

	thumb_func_start sub_801AEE4
sub_801AEE4:
	ldr r2, _0801AEF4
	ldr r2, [r2]
	lsls r0, 2
	adds r2, 0x4
	adds r2, r0
	str r1, [r2]
	bx lr
	.align 2, 0
_0801AEF4: .4byte gUnknown_203B224
	thumb_func_end sub_801AEE4

	thumb_func_start sub_801AEF8
sub_801AEF8:
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	sub sp, 0x4
	movs r0, 0
	mov r9, r0
	b _0801AF78
_0801AF08:
	movs r1, 0x1
	add r1, r9
	mov r8, r1
	mov r7, r8
	b _0801AF6E
_0801AF12:
	ldr r2, _0801AF90
	ldr r0, [r2]
	mov r1, r9
	lsls r6, r1, 2
	adds r0, r6
	ldrb r0, [r0, 0x2]
	str r2, [sp]
	bl sub_8090D44
	adds r4, r0, 0
	ldr r2, [sp]
	ldr r0, [r2]
	lsls r5, r7, 2
	adds r0, r5
	ldrb r0, [r0, 0x2]
	bl sub_8090D44
	ldr r2, [sp]
	cmp r4, r0
	bgt _0801AF4C
	cmp r4, r0
	bne _0801AF6C
	ldr r0, [r2]
	adds r1, r0, r6
	adds r0, r5
	ldrb r1, [r1, 0x1]
	ldrb r0, [r0, 0x1]
	cmp r1, r0
	bcs _0801AF6C
_0801AF4C:
	ldr r0, [r2]
	adds r2, r0, r6
	ldr r3, [r2]
	adds r0, r5
	ldr r1, [r0]
	str r1, [r2]
	str r3, [r0]
	ldr r0, _0801AF94
	ldr r0, [r0]
	adds r0, 0x4
	adds r2, r0, r6
	ldr r3, [r2]
	adds r0, r5
	ldr r1, [r0]
	str r1, [r2]
	str r3, [r0]
_0801AF6C:
	adds r7, 0x1
_0801AF6E:
	bl sub_8090A34
	cmp r7, r0
	blt _0801AF12
	mov r9, r8
_0801AF78:
	bl sub_8090A34
	subs r0, 0x1
	cmp r9, r0
	blt _0801AF08
	add sp, 0x4
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_0801AF90: .4byte gUnknown_203B460
_0801AF94: .4byte gUnknown_203B224
	thumb_func_end sub_801AEF8

	thumb_func_start sub_801AF98
sub_801AF98:
	ldr r0, _0801AFA0
	ldr r0, [r0]
	bx lr
	.align 2, 0
_0801AFA0: .4byte gUnknown_203B224
	thumb_func_end sub_801AF98

	thumb_func_start sub_801AFA4
sub_801AFA4:
	push {r4,r5,lr}
	adds r4, r0, 0
	ldr r5, _0801AFEC
	movs r0, 0xA4
	movs r1, 0x8
	bl MemoryAlloc
	str r0, [r5]
	str r4, [r0, 0x4]
	ldr r1, _0801AFF0
	ldr r1, [r1]
	lsls r4, 2
	adds r1, r4
	ldrb r1, [r1, 0x2]
	strb r1, [r0, 0x8]
	ldr r0, [r5]
	ldrb r0, [r0, 0x8]
	bl sub_80913CC
	ldr r1, [r5]
	strh r0, [r1, 0xA]
	ldr r0, _0801AFF4
	ldrh r1, [r1, 0xA]
	bl sub_8092C84
	movs r0, 0
	bl sub_8099690
	bl sub_801B2F4
	cmp r0, 0
	bne _0801AFF8
	movs r0, 0x3
	bl sub_801B064
	b _0801B004
	.align 2, 0
_0801AFEC: .4byte gUnknown_203B22C
_0801AFF0: .4byte gUnknown_203B460
_0801AFF4: .4byte gUnknown_202E1C8
_0801AFF8:
	ldr r1, [r5]
	movs r0, 0x4
	str r0, [r1, 0x60]
	movs r0, 0
	bl sub_801B064
_0801B004:
	movs r0, 0x1
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_801AFA4

	thumb_func_start sub_801B00C
sub_801B00C:
	push {lr}
	ldr r0, _0801B024
	ldr r0, [r0]
	ldr r0, [r0]
	cmp r0, 0x1
	beq _0801B036
	cmp r0, 0x1
	bgt _0801B028
	cmp r0, 0
	beq _0801B030
	b _0801B03C
	.align 2, 0
_0801B024: .4byte gUnknown_203B22C
_0801B028:
	cmp r0, 0x4
	bne _0801B03C
	movs r0, 0x3
	b _0801B042
_0801B030:
	bl sub_801B200
	b _0801B040
_0801B036:
	bl sub_801B2AC
	b _0801B040
_0801B03C:
	bl sub_801B2D8
_0801B040:
	movs r0, 0
_0801B042:
	pop {r1}
	bx r1
	thumb_func_end sub_801B00C

	thumb_func_start sub_801B048
sub_801B048:
	push {r4,lr}
	ldr r4, _0801B060
	ldr r0, [r4]
	cmp r0, 0
	beq _0801B05A
	bl MemoryFree
	movs r0, 0
	str r0, [r4]
_0801B05A:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0801B060: .4byte gUnknown_203B22C
	thumb_func_end sub_801B048

	thumb_func_start sub_801B064
sub_801B064:
	push {lr}
	ldr r1, _0801B078
	ldr r1, [r1]
	str r0, [r1]
	bl nullsub_37
	bl sub_801B080
	pop {r0}
	bx r0
	.align 2, 0
_0801B078: .4byte gUnknown_203B22C
	thumb_func_end sub_801B064

	thumb_func_start nullsub_37
nullsub_37:
	bx lr
	thumb_func_end nullsub_37

	thumb_func_start sub_801B080
sub_801B080:
	push {r4,lr}
	sub sp, 0x14
	ldr r1, _0801B09C
	ldr r0, [r1]
	ldr r0, [r0]
	adds r4, r1, 0
	cmp r0, 0x4
	bhi _0801B168
	lsls r0, 2
	ldr r1, _0801B0A0
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0801B09C: .4byte gUnknown_203B22C
_0801B0A0: .4byte _0801B0A4
	.align 2, 0
_0801B0A4:
	.4byte _0801B0B8
	.4byte _0801B0E8
	.4byte _0801B0FC
	.4byte _0801B15C
	.4byte _0801B168
_0801B0B8:
	bl sub_801B178
	ldr r0, _0801B0E0
	ldr r1, _0801B0E4
	ldr r3, [r1]
	ldr r2, [r3, 0x60]
	adds r3, 0x64
	movs r4, 0
	str r4, [sp]
	movs r1, 0x4
	str r1, [sp, 0x4]
	str r4, [sp, 0x8]
	str r4, [sp, 0xC]
	movs r1, 0x20
	str r1, [sp, 0x10]
	movs r1, 0
	bl sub_8014248
	b _0801B168
	.align 2, 0
_0801B0E0: .4byte gUnknown_80DB9BC
_0801B0E4: .4byte gUnknown_203B22C
_0801B0E8:
	ldr r2, [r4]
	adds r0, r2, 0
	adds r0, 0x58
	movs r3, 0
	ldrsh r1, [r0, r3]
	adds r2, 0xC
	movs r0, 0x2
	bl sub_801E80C
	b _0801B168
_0801B0FC:
	ldr r1, [r4]
	adds r0, r1, 0
	adds r0, 0xC
	ldr r1, [r1, 0x5C]
	adds r1, 0x2C
	bl sub_8094060
	ldr r0, [r4]
	ldrb r0, [r0, 0x8]
	bl sub_80915A0
	lsls r0, 24
	cmp r0, 0
	bne _0801B138
	ldr r3, _0801B150
	ldr r1, [r3]
	ldr r2, [r4]
	ldr r0, [r2, 0x4]
	lsls r0, 2
	adds r1, r0
	ldrb r0, [r2, 0x8]
	subs r0, 0x7D
	strb r0, [r1, 0x1]
	ldr r1, [r3]
	ldr r0, [r4]
	ldr r0, [r0, 0x4]
	lsls r0, 2
	adds r1, r0
	movs r0, 0x7C
	strb r0, [r1, 0x2]
_0801B138:
	movs r0, 0x9C
	lsls r0, 1
	bl sub_8011988
	ldr r0, _0801B154
	ldr r3, _0801B158
	movs r1, 0
	movs r2, 0
	bl sub_80141B4
	b _0801B168
	.align 2, 0
_0801B150: .4byte gUnknown_203B460
_0801B154: .4byte gUnknown_80DB9E4
_0801B158: .4byte 0x00000121
_0801B15C:
	ldr r0, _0801B170
	ldr r3, _0801B174
	movs r1, 0
	movs r2, 0
	bl sub_80141B4
_0801B168:
	add sp, 0x14
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0801B170: .4byte gUnknown_80DBA0C
_0801B174: .4byte 0x00000121
	thumb_func_end sub_801B080

	thumb_func_start sub_801B178
sub_801B178:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	movs r5, 0
	ldr r1, _0801B1F4
	ldr r0, [r1]
	ldr r0, [r0, 0x4C]
	cmp r5, r0
	bge _0801B1D2
	ldr r0, _0801B1F8
	mov r8, r0
	adds r7, r1, 0
	movs r6, 0
_0801B192:
	ldr r4, _0801B1FC
	adds r4, r6, r4
	ldr r0, [r7]
	lsls r1, r5, 1
	adds r0, 0x50
	adds r0, r1
	movs r2, 0
	ldrsh r1, [r0, r2]
	movs r0, 0x58
	muls r0, r1
	mov r2, r8
	ldr r1, [r2]
	adds r1, r0
	adds r0, r4, 0
	bl sub_808DA34
	ldr r2, [r7]
	lsls r1, r5, 3
	adds r0, r2, 0
	adds r0, 0x64
	adds r0, r1
	str r4, [r0]
	adds r0, r2, 0
	adds r0, 0x68
	adds r0, r1
	adds r1, r5, 0x4
	str r1, [r0]
	adds r6, 0x50
	adds r5, 0x1
	ldr r0, [r2, 0x4C]
	cmp r5, r0
	blt _0801B192
_0801B1D2:
	ldr r0, _0801B1F4
	ldr r2, [r0]
	lsls r3, r5, 3
	adds r0, r2, 0
	adds r0, 0x64
	adds r0, r3
	movs r1, 0
	str r1, [r0]
	adds r2, 0x68
	adds r2, r3
	movs r0, 0x1
	str r0, [r2]
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_0801B1F4: .4byte gUnknown_203B22C
_0801B1F8: .4byte gUnknown_203B45C
_0801B1FC: .4byte gUnknown_202DF98
	thumb_func_end sub_801B178

	thumb_func_start sub_801B200
sub_801B200:
	push {r4-r6,lr}
	sub sp, 0x4
	mov r0, sp
	bl sub_80144A4
	cmp r0, 0
	bne _0801B2A4
	ldr r5, _0801B228
	ldr r3, [r5]
	ldr r0, [sp]
	str r0, [r3, 0x60]
	ldr r1, [sp]
	cmp r1, 0
	beq _0801B2A4
	cmp r1, 0x1
	bne _0801B22C
	movs r0, 0x4
	bl sub_801B064
	b _0801B2A4
	.align 2, 0
_0801B228: .4byte gUnknown_203B22C
_0801B22C:
	subs r1, 0x4
	lsls r1, 1
	adds r0, r3, 0
	adds r0, 0x50
	adds r0, r1
	ldrh r0, [r0]
	adds r1, r3, 0
	adds r1, 0x58
	strh r0, [r1]
	ldr r2, _0801B26C
	movs r0, 0
	ldrsh r1, [r1, r0]
	movs r0, 0x58
	muls r0, r1
	ldr r1, [r2]
	adds r1, r0
	str r1, [r3, 0x5C]
	ldr r0, _0801B270
	bl sub_808DA34
	ldr r1, [r5]
	adds r0, r1, 0
	adds r0, 0xC
	ldr r1, [r1, 0x5C]
	adds r1, 0x2C
	bl sub_809401C
	movs r4, 0
	adds r6, r5, 0
	movs r5, 0xC
	b _0801B278
	.align 2, 0
_0801B26C: .4byte gUnknown_203B45C
_0801B270: .4byte gUnknown_202E218
_0801B274:
	adds r5, 0x8
	adds r4, 0x1
_0801B278:
	cmp r4, 0x7
	bgt _0801B292
	ldr r3, [r6]
	adds r2, r3, r5
	ldrb r1, [r2]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	bne _0801B274
	ldrh r1, [r3, 0xA]
	adds r0, r2, 0
	bl sub_8092AD4
_0801B292:
	cmp r4, 0x3
	ble _0801B29E
	movs r0, 0x1
	bl sub_801B064
	b _0801B2A4
_0801B29E:
	movs r0, 0x2
	bl sub_801B064
_0801B2A4:
	add sp, 0x4
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end sub_801B200

	thumb_func_start sub_801B2AC
sub_801B2AC:
	push {lr}
	bl sub_801E8C0
	cmp r0, 0x2
	beq _0801B2CA
	cmp r0, 0x2
	bcc _0801B2D4
	cmp r0, 0x3
	bne _0801B2D4
	bl sub_801E93C
	movs r0, 0x2
	bl sub_801B064
	b _0801B2D4
_0801B2CA:
	bl sub_801E93C
	movs r0, 0
	bl sub_801B064
_0801B2D4:
	pop {r0}
	bx r0
	thumb_func_end sub_801B2AC

	thumb_func_start sub_801B2D8
sub_801B2D8:
	push {lr}
	sub sp, 0x4
	mov r0, sp
	bl sub_80144A4
	cmp r0, 0
	bne _0801B2EC
	movs r0, 0x4
	bl sub_801B064
_0801B2EC:
	add sp, 0x4
	pop {r0}
	bx r0
	thumb_func_end sub_801B2D8

	thumb_func_start sub_801B2F4
sub_801B2F4:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0x10
	mov r0, sp
	bl sub_808D580
	adds r6, r0, 0
	ldr r2, _0801B36C
	ldr r1, [r2]
	movs r0, 0
	str r0, [r1, 0x4C]
	movs r5, 0
	cmp r5, r6
	bge _0801B35A
	ldr r0, _0801B370
	mov r8, r0
	adds r7, r2, 0
	mov r4, sp
_0801B31A:
	ldr r1, [r4]
	movs r0, 0x58
	muls r0, r1
	mov r2, r8
	ldr r1, [r2]
	adds r1, r0
	ldr r0, [r7]
	ldrh r0, [r0, 0xA]
	movs r2, 0x8
	ldrsh r1, [r1, r2]
	bl sub_808E190
	lsls r0, 24
	cmp r0, 0
	beq _0801B352
	ldr r2, [r7]
	ldr r0, [r2, 0x4C]
	lsls r0, 1
	adds r1, r2, 0
	adds r1, 0x50
	adds r1, r0
	ldr r0, [r4]
	strh r0, [r1]
	ldr r0, [r2, 0x4C]
	cmp r0, 0x3
	bgt _0801B35A
	adds r0, 0x1
	str r0, [r2, 0x4C]
_0801B352:
	adds r4, 0x4
	adds r5, 0x1
	cmp r5, r6
	blt _0801B31A
_0801B35A:
	ldr r0, _0801B36C
	ldr r0, [r0]
	ldr r0, [r0, 0x4C]
	add sp, 0x10
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r1}
	bx r1
	.align 2, 0
_0801B36C: .4byte gUnknown_203B22C
_0801B370: .4byte gUnknown_203B45C
	thumb_func_end sub_801B2F4

	thumb_func_start sub_801B374
sub_801B374:
	push {r4-r6,lr}
	lsls r0, 24
	lsrs r0, 24
	ldr r1, _0801B3A8
	ldr r4, [r1]
	bl sub_80913CC
	lsls r0, 16
	lsrs r6, r0, 16
	movs r5, 0
_0801B388:
	ldrh r0, [r4]
	lsrs r0, 1
	movs r1, 0x1
	ands r0, r1
	cmp r0, 0
	beq _0801B3AC
	movs r0, 0x8
	ldrsh r1, [r4, r0]
	adds r0, r6, 0
	bl sub_808E190
	lsls r0, 24
	cmp r0, 0
	beq _0801B3AC
	movs r0, 0
	b _0801B3BA
	.align 2, 0
_0801B3A8: .4byte gUnknown_203B45C
_0801B3AC:
	adds r5, 0x1
	adds r4, 0x58
	movs r0, 0xCE
	lsls r0, 1
	cmp r5, r0
	ble _0801B388
	movs r0, 0x1
_0801B3BA:
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end sub_801B374

	thumb_func_start sub_801B3C0
sub_801B3C0:
	push {r4,r5,lr}
	adds r5, r0, 0
	movs r0, 0x1
	bl ResetSprites
	ldr r4, _0801B40C
	movs r0, 0x94
	movs r1, 0x8
	bl MemoryAlloc
	str r0, [r4]
	ldr r1, [r5]
	str r1, [r0, 0x4]
	adds r0, 0x88
	bl sub_801317C
	ldr r0, [r4]
	movs r1, 0
	str r1, [r0, 0x24]
	adds r0, 0x28
	bl sub_80140B4
	bl sub_8004914
	ldr r0, [r4]
	adds r0, 0x28
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	movs r0, 0
	bl sub_801B46C
	movs r0, 0x1
	pop {r4,r5}
	pop {r1}
	bx r1
	.align 2, 0
_0801B40C: .4byte gUnknown_203B230
	thumb_func_end sub_801B3C0

	thumb_func_start sub_801B410
sub_801B410:
	push {lr}
	ldr r0, _0801B428
	ldr r0, [r0]
	ldr r0, [r0]
	cmp r0, 0x1
	beq _0801B43C
	cmp r0, 0x1
	bgt _0801B42C
	cmp r0, 0
	beq _0801B436
	b _0801B446
	.align 2, 0
_0801B428: .4byte gUnknown_203B230
_0801B42C:
	cmp r0, 0x2
	beq _0801B446
	cmp r0, 0x3
	beq _0801B442
	b _0801B446
_0801B436:
	bl sub_801B51C
	b _0801B44A
_0801B43C:
	bl sub_801B590
	b _0801B44A
_0801B442:
	movs r0, 0x3
	b _0801B44C
_0801B446:
	movs r0, 0x2
	b _0801B44C
_0801B44A:
	movs r0, 0
_0801B44C:
	pop {r1}
	bx r1
	thumb_func_end sub_801B410

	thumb_func_start sub_801B450
sub_801B450:
	push {r4,lr}
	ldr r4, _0801B468
	ldr r0, [r4]
	cmp r0, 0
	beq _0801B462
	bl MemoryFree
	movs r0, 0
	str r0, [r4]
_0801B462:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0801B468: .4byte gUnknown_203B230
	thumb_func_end sub_801B450

	thumb_func_start sub_801B46C
sub_801B46C:
	push {lr}
	ldr r1, _0801B47C
	ldr r1, [r1]
	str r0, [r1]
	bl sub_801B480
	pop {r0}
	bx r0
	.align 2, 0
_0801B47C: .4byte gUnknown_203B230
	thumb_func_end sub_801B46C

	thumb_func_start sub_801B480
sub_801B480:
	push {r4,r5,lr}
	sub sp, 0x4
	ldr r5, _0801B4B0
	ldr r0, [r5]
	ldr r4, [r0]
	cmp r4, 0x1
	beq _0801B4B4
	cmp r4, 0x1
	bgt _0801B50C
	cmp r4, 0
	bne _0801B50C
	ldr r0, [r0, 0x24]
	bl sub_8008C54
	ldr r2, [r5]
	adds r0, r2, 0x4
	ldr r1, [r2, 0x24]
	adds r2, 0x10
	bl sub_80913E0
	ldr r1, [r5]
	str r0, [r1, 0xC]
	str r4, [r1, 0x20]
	b _0801B50C
	.align 2, 0
_0801B4B0: .4byte gUnknown_203B230
_0801B4B4:
	ldr r0, [r0, 0x24]
	bl sub_8008C54
	ldr r0, [r5]
	ldr r0, [r0, 0x24]
	bl sub_80073B8
	ldr r0, [r5]
	ldr r1, [r0, 0x8]
	lsls r1, 2
	adds r0, 0x10
	adds r0, r1
	ldr r1, [r0]
	ldr r0, _0801B514
	ldr r1, [r1]
	bl strcpy
	ldr r2, _0801B518
	ldr r0, [r5]
	ldr r3, [r0, 0x24]
	movs r4, 0
	str r4, [sp]
	movs r0, 0x10
	movs r1, 0
	bl sub_8014FF0
	ldr r3, [r5]
	ldr r1, [r3, 0x8]
	lsls r1, 2
	adds r0, r3, 0
	adds r0, 0x10
	adds r0, r1
	ldr r0, [r0]
	ldr r2, [r0, 0x4]
	ldr r3, [r3, 0x24]
	str r4, [sp]
	movs r0, 0x4
	movs r1, 0x10
	bl sub_8014FF0
	ldr r0, [r5]
	ldr r0, [r0, 0x24]
	bl sub_80073E0
_0801B50C:
	add sp, 0x4
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_0801B514: .4byte gUnknown_202DF98
_0801B518: .4byte gUnknown_80DBA4C
	thumb_func_end sub_801B480

	thumb_func_start sub_801B51C
sub_801B51C:
	push {r4,lr}
	ldr r0, _0801B558
	ldr r2, [r0]
	ldr r1, [r2, 0xC]
	adds r4, r0, 0
	cmp r1, 0
	beq _0801B540
	ldr r0, [r2, 0x20]
	movs r1, 0x8
	ands r0, r1
	cmp r0, 0
	beq _0801B538
	bl sub_8013F84
_0801B538:
	ldr r1, [r4]
	ldr r0, [r1, 0x20]
	adds r0, 0x1
	str r0, [r1, 0x20]
_0801B540:
	ldr r1, [r4]
	adds r0, r1, 0
	adds r0, 0x88
	ldr r1, [r1, 0x24]
	bl sub_8012A64
	cmp r0, 0x1
	beq _0801B55C
	cmp r0, 0x2
	beq _0801B57E
	b _0801B58A
	.align 2, 0
_0801B558: .4byte gUnknown_203B230
_0801B55C:
	movs r0, 0
	bl sub_80119D4
	ldr r1, [r4]
	ldr r0, [r1, 0xC]
	cmp r0, 0
	beq _0801B576
	movs r0, 0
	str r0, [r1, 0x8]
	movs r0, 0x1
	bl sub_801B46C
	b _0801B58A
_0801B576:
	movs r0, 0x3
	bl sub_801B46C
	b _0801B58A
_0801B57E:
	movs r0, 0x1
	bl sub_80119D4
	movs r0, 0x2
	bl sub_801B46C
_0801B58A:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_801B51C

	thumb_func_start sub_801B590
sub_801B590:
	push {r4,lr}
	ldr r0, _0801B5D0
	ldr r3, [r0]
	ldr r1, [r3, 0xC]
	subs r1, 0x1
	ldr r2, [r3, 0x8]
	adds r4, r0, 0
	cmp r2, r1
	bge _0801B5B8
	ldr r0, [r3, 0x20]
	movs r1, 0x8
	ands r0, r1
	cmp r0, 0
	beq _0801B5B0
	bl sub_8013F84
_0801B5B0:
	ldr r1, [r4]
	ldr r0, [r1, 0x20]
	adds r0, 0x1
	str r0, [r1, 0x20]
_0801B5B8:
	ldr r1, [r4]
	adds r0, r1, 0
	adds r0, 0x88
	ldr r1, [r1, 0x24]
	bl sub_8012A64
	cmp r0, 0x1
	beq _0801B5D4
	cmp r0, 0x2
	beq _0801B5F8
	b _0801B604
	.align 2, 0
_0801B5D0: .4byte gUnknown_203B230
_0801B5D4:
	movs r0, 0
	bl sub_80119D4
	ldr r0, [r4]
	ldr r1, [r0, 0x8]
	adds r1, 0x1
	str r1, [r0, 0x8]
	ldr r0, [r0, 0xC]
	cmp r1, r0
	bge _0801B5F0
	movs r0, 0x1
	bl sub_801B46C
	b _0801B604
_0801B5F0:
	movs r0, 0
	bl sub_801B46C
	b _0801B604
_0801B5F8:
	movs r0, 0x1
	bl sub_80119D4
	movs r0, 0x2
	bl sub_801B46C
_0801B604:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_801B590

	thumb_func_start sub_801B60C
sub_801B60C:
	push {r4-r7,lr}
	adds r5, r0, 0
	adds r4, r1, 0
	lsls r4, 24
	lsrs r4, 24
	lsls r2, 24
	lsrs r7, r2, 24
	ldr r6, _0801B650
	movs r0, 0xAA
	lsls r0, 1
	movs r1, 0x8
	bl MemoryAlloc
	str r0, [r6]
	adds r2, r0, 0
	adds r2, 0xC8
	movs r1, 0
	str r1, [r2]
	str r5, [r0]
	strb r4, [r0, 0x12]
	ldr r0, [r6]
	ldrb r0, [r0, 0x12]
	bl sub_8090A60
	lsls r0, 24
	lsrs r1, r0, 24
	cmp r1, 0
	beq _0801B654
	ldr r0, [r6]
	strb r7, [r0, 0x11]
	ldr r0, [r6]
	strb r7, [r0, 0xC]
	b _0801B65E
	.align 2, 0
_0801B650: .4byte gUnknown_203B234
_0801B654:
	ldr r0, [r6]
	strb r1, [r0, 0x11]
	ldr r1, [r6]
	movs r0, 0x1
	strb r0, [r1, 0xC]
_0801B65E:
	ldr r5, _0801B6A0
	ldr r0, [r5]
	movs r1, 0
	movs r2, 0x1
	strb r2, [r0, 0x10]
	ldr r0, [r5]
	str r1, [r0, 0x14]
	strb r1, [r0, 0x18]
	ldr r0, [r5]
	strb r2, [r0, 0x1C]
	ldr r4, _0801B6A4
	bl sub_808D33C
	adds r1, r0, 0
	adds r0, r4, 0
	movs r2, 0x6
	bl sub_808D9AC
	ldr r0, _0801B6A8
	ldr r2, [r5]
	adds r1, r2, 0
	adds r1, 0x10
	adds r2, 0x14
	bl sub_8090E14
	movs r0, 0
	bl sub_801B748
	movs r0, 0x1
	pop {r4-r7}
	pop {r1}
	bx r1
	.align 2, 0
_0801B6A0: .4byte gUnknown_203B234
_0801B6A4: .4byte gUnknown_202DF98
_0801B6A8: .4byte gUnknown_202DE58
	thumb_func_end sub_801B60C

	thumb_func_start sub_801B6AC
sub_801B6AC:
	push {lr}
	ldr r0, _0801B6C4
	ldr r0, [r0]
	ldr r0, [r0, 0x4]
	subs r0, 0x6
	cmp r0, 0xA
	bhi _0801B720
	lsls r0, 2
	ldr r1, _0801B6C8
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0801B6C4: .4byte gUnknown_203B234
_0801B6C8: .4byte _0801B6CC
	.align 2, 0
_0801B6CC:
	.4byte _0801B6FC
	.4byte _0801B702
	.4byte _0801B708
	.4byte _0801B708
	.4byte _0801B70E
	.4byte _0801B714
	.4byte _0801B71A
	.4byte _0801B720
	.4byte _0801B720
	.4byte _0801B720
	.4byte _0801B6F8
_0801B6F8:
	movs r0, 0x3
	b _0801B726
_0801B6FC:
	bl sub_801BC64
	b _0801B724
_0801B702:
	bl sub_801BC94
	b _0801B724
_0801B708:
	bl sub_801BCCC
	b _0801B724
_0801B70E:
	bl sub_801BD80
	b _0801B724
_0801B714:
	bl sub_801BEAC
	b _0801B724
_0801B71A:
	bl sub_801BE30
	b _0801B724
_0801B720:
	bl sub_801BEC8
_0801B724:
	movs r0, 0
_0801B726:
	pop {r1}
	bx r1
	thumb_func_end sub_801B6AC

	thumb_func_start sub_801B72C
sub_801B72C:
	push {r4,lr}
	ldr r4, _0801B744
	ldr r0, [r4]
	cmp r0, 0
	beq _0801B73E
	bl MemoryFree
	movs r0, 0
	str r0, [r4]
_0801B73E:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0801B744: .4byte gUnknown_203B234
	thumb_func_end sub_801B72C

	thumb_func_start sub_801B748
sub_801B748:
	push {lr}
	ldr r1, _0801B75C
	ldr r1, [r1]
	str r0, [r1, 0x4]
	bl sub_801B760
	bl sub_801B874
	pop {r0}
	bx r0
	.align 2, 0
_0801B75C: .4byte gUnknown_203B234
	thumb_func_end sub_801B748

	thumb_func_start sub_801B760
sub_801B760:
	push {r4-r7,lr}
	ldr r0, _0801B77C
	ldr r1, [r0]
	ldr r1, [r1, 0x4]
	subs r1, 0x1
	adds r4, r0, 0
	cmp r1, 0xE
	bls _0801B772
	b _0801B86A
_0801B772:
	lsls r0, r1, 2
	ldr r1, _0801B780
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0801B77C: .4byte gUnknown_203B234
_0801B780: .4byte _0801B784
	.align 2, 0
_0801B784:
	.4byte _0801B7C0
	.4byte _0801B86A
	.4byte _0801B86A
	.4byte _0801B86A
	.4byte _0801B86A
	.4byte _0801B7C0
	.4byte _0801B7C0
	.4byte _0801B7C0
	.4byte _0801B7C0
	.4byte _0801B800
	.4byte _0801B7C0
	.4byte _0801B840
	.4byte _0801B7C0
	.4byte _0801B7C0
	.4byte _0801B7C0
_0801B7C0:
	ldr r4, _0801B7F8
	ldr r0, [r4]
	adds r0, 0xF4
	bl sub_8006518
	mov r12, r4
	ldr r4, _0801B7FC
	movs r3, 0
	movs r2, 0x3
_0801B7D2:
	mov r0, r12
	ldr r1, [r0]
	adds r1, r3
	adds r1, 0xF4
	adds r0, r4, 0
	ldm r0!, {r5-r7}
	stm r1!, {r5-r7}
	ldm r0!, {r5-r7}
	stm r1!, {r5-r7}
	adds r3, 0x18
	subs r2, 0x1
	cmp r2, 0
	bge _0801B7D2
	bl sub_8004914
	ldr r0, _0801B7F8
	ldr r0, [r0]
	b _0801B82E
	.align 2, 0
_0801B7F8: .4byte gUnknown_203B234
_0801B7FC: .4byte gUnknown_80DBA58
_0801B800:
	ldr r0, [r4]
	adds r0, 0xF4
	bl sub_8006518
	bl sub_801BB5C
	ldr r2, [r4]
	movs r0, 0x92
	lsls r0, 1
	adds r2, r0
	ldr r1, _0801B83C
	ldm r1!, {r3,r5,r6}
	stm r2!, {r3,r5,r6}
	ldm r1!, {r3,r5,r7}
	stm r2!, {r3,r5,r7}
	ldr r1, [r4]
	adds r0, r1, r0
	adds r1, 0xCC
	bl sub_8012CAC
	bl sub_8004914
	ldr r0, [r4]
_0801B82E:
	adds r0, 0xF4
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	b _0801B86A
	.align 2, 0
_0801B83C: .4byte gUnknown_80DBA70
_0801B840:
	ldr r0, [r4]
	adds r0, 0xF4
	bl sub_8006518
	ldr r1, [r4]
	movs r6, 0x86
	lsls r6, 1
	adds r1, r6
	ldr r0, _0801B870
	ldm r0!, {r2,r3,r7}
	stm r1!, {r2,r3,r7}
	ldm r0!, {r5-r7}
	stm r1!, {r5-r7}
	bl sub_8004914
	ldr r0, [r4]
	adds r0, 0xF4
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
_0801B86A:
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_0801B870: .4byte gUnknown_80DBA88
	thumb_func_end sub_801B760

	thumb_func_start sub_801B874
sub_801B874:
	push {r4,lr}
	sub sp, 0x14
	ldr r1, _0801B890
	ldr r0, [r1]
	ldr r0, [r0, 0x4]
	adds r4, r1, 0
	cmp r0, 0x10
	bls _0801B886
	b _0801BB0E
_0801B886:
	lsls r0, 2
	ldr r1, _0801B894
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0801B890: .4byte gUnknown_203B234
_0801B894: .4byte _0801B898
	.align 2, 0
_0801B898:
	.4byte _0801B8DC
	.4byte _0801B9BC
	.4byte _0801B9D8
	.4byte _0801B9E0
	.4byte _0801B9F0
	.4byte _0801B9F8
	.4byte _0801BA08
	.4byte _0801BA34
	.4byte _0801BA60
	.4byte _0801BA6E
	.4byte _0801BA76
	.4byte _0801BA94
	.4byte _0801BA9E
	.4byte _0801BAD0
	.4byte _0801BAE0
	.4byte _0801BAFC
	.4byte _0801BB0E
_0801B8DC:
	ldr r1, [r4]
	ldrb r0, [r1, 0x12]
	cmp r0, 0xEA
	bne _0801B8FE
	movs r0, 0x10
	str r0, [r1, 0x8]
	movs r0, 0
	movs r1, 0x47
	movs r2, 0x1
	bl sub_8001784
	cmp r0, 0
	bne _0801B914
	movs r0, 0
	movs r1, 0x47
	movs r2, 0x1
	b _0801B92A
_0801B8FE:
	cmp r0, 0xEB
	bne _0801B938
	movs r0, 0x10
	str r0, [r1, 0x8]
	movs r0, 0
	movs r1, 0x47
	movs r2, 0
	bl sub_8001784
	cmp r0, 0
	beq _0801B924
_0801B914:
	movs r0, 0xFA
	lsls r0, 2
	bl sub_80913A0
	movs r0, 0x4
	bl sub_801B748
	b _0801BB0E
_0801B924:
	movs r0, 0
	movs r1, 0x47
	movs r2, 0
_0801B92A:
	movs r3, 0x1
	bl sub_800199C
	movs r0, 0x3
	bl sub_801B748
	b _0801BB0E
_0801B938:
	bl sub_8090A34
	cmp r0, 0x13
	ble _0801B986
	ldr r0, [r4]
	ldrb r0, [r0, 0x12]
	bl sub_8091524
	lsls r0, 24
	cmp r0, 0
	beq _0801B968
	ldr r0, _0801B970
	ldr r1, [r0]
	ldr r2, [r4]
	ldrb r0, [r2, 0x12]
	lsls r0, 1
	adds r1, 0x50
	adds r3, r1, r0
	ldrh r1, [r3]
	ldrb r0, [r2, 0xC]
	adds r1, r0
	ldr r0, _0801B974
	cmp r1, r0
	ble _0801B978
_0801B968:
	ldr r1, [r4]
	movs r0, 0x6
	b _0801B99C
	.align 2, 0
_0801B970: .4byte gUnknown_203B460
_0801B974: .4byte 0x000003e7
_0801B978:
	strh r1, [r3]
	movs r0, 0xCB
	bl sub_8011988
	ldr r1, [r4]
	movs r0, 0x5
	b _0801B99C
_0801B986:
	ldr r0, [r4]
	adds r0, 0x10
	bl sub_8091290
	bl sub_80910B4
	movs r0, 0xCB
	bl sub_8011988
	ldr r1, [r4]
	movs r0, 0x10
_0801B99C:
	str r0, [r1, 0x8]
	ldr r0, _0801B9B0
	ldr r0, [r0]
	ldr r0, [r0]
	cmp r0, 0x1
	bne _0801B9B4
	movs r0, 0x2
	bl sub_801B748
	b _0801BB0E
	.align 2, 0
_0801B9B0: .4byte gUnknown_203B234
_0801B9B4:
	movs r0, 0x1
	bl sub_801B748
	b _0801BB0E
_0801B9BC:
	movs r0, 0
	bl sub_808D544
	cmp r0, 0x1
	bgt _0801B9D0
	ldr r0, _0801B9CC
	b _0801BAE8
	.align 2, 0
_0801B9CC: .4byte gUnknown_80DBAA0
_0801B9D0:
	ldr r0, _0801B9D4
	b _0801BAE8
	.align 2, 0
_0801B9D4: .4byte gUnknown_80DBAD0
_0801B9D8:
	ldr r0, _0801B9DC
	b _0801BAE8
	.align 2, 0
_0801B9DC: .4byte gUnknown_80DBB08
_0801B9E0:
	movs r0, 0xD4
	bl sub_8011988
	ldr r0, _0801B9EC
	b _0801BAE8
	.align 2, 0
_0801B9EC: .4byte gUnknown_80DBB38
_0801B9F0:
	ldr r0, _0801B9F4
	b _0801BAE8
	.align 2, 0
_0801B9F4: .4byte gUnknown_80DBB9C
_0801B9F8:
	ldr r1, [r4]
	movs r0, 0x10
	str r0, [r1, 0x8]
	ldr r0, _0801BA04
	b _0801BAE8
	.align 2, 0
_0801BA04: .4byte gUnknown_80DBC28
_0801BA08:
	bl sub_801BB20
	ldr r0, _0801BA2C
	ldr r1, _0801BA30
	ldr r3, [r1]
	adds r3, 0xCC
	movs r2, 0
	str r2, [sp]
	movs r1, 0x4
	str r1, [sp, 0x4]
	str r2, [sp, 0x8]
	str r2, [sp, 0xC]
	str r2, [sp, 0x10]
	movs r1, 0
	movs r2, 0x4
	bl sub_8014248
	b _0801BB0E
	.align 2, 0
_0801BA2C: .4byte gUnknown_80DBC60
_0801BA30: .4byte gUnknown_203B234
_0801BA34:
	bl sub_801BC24
	ldr r0, _0801BA58
	ldr r1, _0801BA5C
	ldr r3, [r1]
	adds r3, 0xCC
	movs r2, 0
	str r2, [sp]
	movs r1, 0x4
	str r1, [sp, 0x4]
	str r2, [sp, 0x8]
	str r2, [sp, 0xC]
	str r2, [sp, 0x10]
	movs r1, 0
	movs r2, 0x3
	bl sub_8014248
	b _0801BB0E
	.align 2, 0
_0801BA58: .4byte gUnknown_80DBC98
_0801BA5C: .4byte gUnknown_203B234
_0801BA60:
	movs r0, 0x1
	movs r1, 0x3
	movs r2, 0
	movs r3, 0xA
	bl sub_801A5D8
	b _0801BB0E
_0801BA6E:
	movs r0, 0x1
	bl sub_801A8D0
	b _0801BB0E
_0801BA76:
	bl sub_801A9E0
	ldr r0, _0801BA90
	ldr r2, [r0]
	adds r0, r2, 0
	adds r0, 0x28
	adds r1, r2, 0
	adds r1, 0xCC
	adds r2, 0xC8
	ldr r2, [r2]
	str r2, [sp]
	movs r2, 0x2
	b _0801BAC0
	.align 2, 0
_0801BA90: .4byte gUnknown_203B234
_0801BA94:
	ldr r0, [r4]
	adds r0, 0x20
	bl sub_801B3C0
	b _0801BB0E
_0801BA9E:
	bl sub_801A9E0
	ldr r4, _0801BACC
	ldr r0, [r4]
	adds r0, 0x28
	movs r1, 0
	bl sub_8012EA4
	bl sub_801BC24
	ldr r1, [r4]
	adds r0, r1, 0
	adds r0, 0x78
	adds r1, 0xCC
	movs r2, 0x3
	str r2, [sp]
	movs r2, 0x1
_0801BAC0:
	str r2, [sp, 0x4]
	movs r2, 0
	movs r3, 0
	bl sub_8012D60
	b _0801BB0E
	.align 2, 0
_0801BACC: .4byte gUnknown_203B234
_0801BAD0:
	ldr r1, [r4]
	movs r0, 0x10
	str r0, [r1, 0x8]
	ldr r0, _0801BADC
	b _0801BAE8
	.align 2, 0
_0801BADC: .4byte gUnknown_80DBCC4
_0801BAE0:
	ldr r1, [r4]
	movs r0, 0x10
	str r0, [r1, 0x8]
	ldr r0, _0801BAF4
_0801BAE8:
	ldr r3, _0801BAF8
	movs r1, 0
	movs r2, 0
	bl sub_80141B4
	b _0801BB0E
	.align 2, 0
_0801BAF4: .4byte gUnknown_80DBCE8
_0801BAF8: .4byte 0x00000101
_0801BAFC:
	ldr r1, [r4]
	movs r0, 0x10
	str r0, [r1, 0x8]
	ldr r0, _0801BB18
	ldr r3, _0801BB1C
	movs r1, 0
	movs r2, 0
	bl sub_80141B4
_0801BB0E:
	add sp, 0x14
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0801BB18: .4byte gUnknown_80DBD24
_0801BB1C: .4byte 0x00000101
	thumb_func_end sub_801B874

	thumb_func_start sub_801BB20
sub_801BB20:
	ldr r0, _0801BB50
	ldr r3, [r0]
	movs r2, 0
	adds r1, r3, 0
	adds r1, 0xCC
	ldr r0, _0801BB54
	str r0, [r1]
	adds r1, 0x4
	movs r0, 0x4
	str r0, [r1]
	adds r1, 0x4
	ldr r0, _0801BB58
	str r0, [r1]
	adds r1, 0x4
	movs r0, 0x5
	str r0, [r1]
	adds r0, r3, 0
	adds r0, 0xDC
	str r2, [r0]
	adds r1, 0x8
	movs r0, 0x1
	negs r0, r0
	str r0, [r1]
	bx lr
	.align 2, 0
_0801BB50: .4byte gUnknown_203B234
_0801BB54: .4byte gUnknown_80DBD58
_0801BB58: .4byte gUnknown_80DBD6C
	thumb_func_end sub_801BB20

	thumb_func_start sub_801BB5C
sub_801BB5C:
	push {r4-r7,lr}
	ldr r4, _0801BBEC
	ldr r2, [r4]
	adds r1, r2, 0
	adds r1, 0xCC
	ldr r0, _0801BBF0
	str r0, [r1]
	adds r1, 0x4
	movs r0, 0x6
	str r0, [r1]
	ldr r0, [r2, 0x24]
	bl sub_801ADA0
	lsls r0, 24
	cmp r0, 0
	bne _0801BB86
	ldr r0, [r4]
	adds r0, 0xD0
	movs r1, 0x1
	negs r1, r1
	str r1, [r0]
_0801BB86:
	ldr r0, [r4]
	mov r12, r0
	movs r3, 0x1
	movs r2, 0x8
	mov r1, r12
	adds r1, 0xD4
	ldr r0, _0801BBF4
	str r0, [r1]
	adds r1, 0x4
	movs r0, 0x7
	str r0, [r1]
	adds r1, 0x4
	ldr r0, _0801BBF8
	ldr r0, [r0]
	str r0, [r1]
	mov r0, r12
	adds r0, 0xE0
	str r2, [r0]
	movs r5, 0x3
	adds r1, 0x8
	movs r0, 0
	str r0, [r1]
	mov r0, r12
	adds r0, 0xE8
	str r3, [r0]
	movs r3, 0
	adds r6, r4, 0
	movs r7, 0x1
	negs r7, r7
	mov r4, r12
	adds r4, 0xC8
	subs r1, 0x14
_0801BBC6:
	ldr r2, [r1]
	cmp r2, r7
	beq _0801BBD2
	ldr r0, [r4]
	cmp r2, r0
	beq _0801BC1C
_0801BBD2:
	adds r1, 0x8
	adds r3, 0x1
	cmp r3, r5
	blt _0801BBC6
	movs r3, 0
	cmp r3, r5
	bge _0801BC1C
	ldr r2, [r6]
	adds r0, r2, 0
	adds r0, 0xD0
	ldr r1, [r0]
	b _0801BC0E
	.align 2, 0
_0801BBEC: .4byte gUnknown_203B234
_0801BBF0: .4byte gUnknown_80DBD80
_0801BBF4: .4byte gUnknown_80DBD88
_0801BBF8: .4byte gUnknown_80D4970
_0801BBFC:
	adds r3, 0x1
	cmp r3, r5
	bge _0801BC1C
	ldr r2, [r6]
	lsls r0, r3, 3
	adds r1, r2, 0
	adds r1, 0xD0
	adds r1, r0
	ldr r1, [r1]
_0801BC0E:
	movs r0, 0x1
	negs r0, r0
	cmp r1, r0
	beq _0801BBFC
	adds r0, r2, 0
	adds r0, 0xC8
	str r1, [r0]
_0801BC1C:
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_801BB5C

	thumb_func_start sub_801BC24
sub_801BC24:
	ldr r0, _0801BC58
	ldr r0, [r0]
	mov r12, r0
	movs r3, 0
	mov r1, r12
	adds r1, 0xCC
	ldr r0, _0801BC5C
	ldr r0, [r0]
	str r0, [r1]
	adds r1, 0x4
	movs r0, 0x2
	str r0, [r1]
	movs r2, 0x1
	adds r1, 0x4
	ldr r0, _0801BC60
	ldr r0, [r0]
	str r0, [r1]
	adds r1, 0x4
	movs r0, 0x3
	str r0, [r1]
	mov r0, r12
	adds r0, 0xDC
	str r3, [r0]
	adds r0, 0x4
	str r2, [r0]
	bx lr
	.align 2, 0
_0801BC58: .4byte gUnknown_203B234
_0801BC5C: .4byte gUnknown_80D4920
_0801BC60: .4byte gUnknown_80D4928
	thumb_func_end sub_801BC24

	thumb_func_start sub_801BC64
sub_801BC64:
	push {lr}
	sub sp, 0x4
	mov r0, sp
	bl sub_80144A4
	cmp r0, 0
	bne _0801BC8C
	ldr r0, [sp]
	cmp r0, 0x4
	beq _0801BC7E
	cmp r0, 0x5
	beq _0801BC86
	b _0801BC8C
_0801BC7E:
	movs r0, 0x8
	bl sub_801B748
	b _0801BC8C
_0801BC86:
	movs r0, 0x7
	bl sub_801B748
_0801BC8C:
	add sp, 0x4
	pop {r0}
	bx r0
	thumb_func_end sub_801BC64

	thumb_func_start sub_801BC94
sub_801BC94:
	push {lr}
	sub sp, 0x4
	mov r0, sp
	bl sub_80144A4
	cmp r0, 0
	bne _0801BCC6
	ldr r0, [sp]
	cmp r0, 0x2
	beq _0801BCB8
	cmp r0, 0x2
	bgt _0801BCB2
	cmp r0, 0x1
	beq _0801BCC0
	b _0801BCC6
_0801BCB2:
	cmp r0, 0x3
	beq _0801BCC0
	b _0801BCC6
_0801BCB8:
	movs r0, 0xD
	bl sub_801B748
	b _0801BCC6
_0801BCC0:
	movs r0, 0x6
	bl sub_801B748
_0801BCC6:
	add sp, 0x4
	pop {r0}
	bx r0
	thumb_func_end sub_801BC94

	thumb_func_start sub_801BCCC
sub_801BCCC:
	push {lr}
	movs r0, 0x1
	bl sub_801A6E8
	cmp r0, 0x4
	bhi _0801BD7A
	lsls r0, 2
	ldr r1, _0801BCE4
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0801BCE4: .4byte _0801BCE8
	.align 2, 0
_0801BCE8:
	.4byte _0801BD7A
	.4byte _0801BD7A
	.4byte _0801BD70
	.4byte _0801BCFC
	.4byte _0801BD34
_0801BCFC:
	bl sub_801A8AC
	ldr r1, _0801BD28
	ldr r2, [r1]
	str r0, [r2, 0x24]
	ldr r1, _0801BD2C
	ldr r1, [r1]
	lsls r0, 2
	adds r1, r0
	ldr r0, [r1]
	str r0, [r2, 0x20]
	ldr r0, _0801BD30
	adds r1, r2, 0
	adds r1, 0x20
	adds r2, 0x14
	bl sub_8090E14
	movs r0, 0xA
	bl sub_801B748
	b _0801BD7A
	.align 2, 0
_0801BD28: .4byte gUnknown_203B234
_0801BD2C: .4byte gUnknown_203B460
_0801BD30: .4byte gUnknown_202DEA8
_0801BD34:
	bl sub_801A8AC
	ldr r1, _0801BD64
	ldr r2, [r1]
	str r0, [r2, 0x24]
	ldr r1, _0801BD68
	ldr r1, [r1]
	lsls r0, 2
	adds r1, r0
	ldr r0, [r1]
	str r0, [r2, 0x20]
	ldr r0, _0801BD6C
	adds r1, r2, 0
	adds r1, 0x20
	adds r2, 0x14
	bl sub_8090E14
	movs r0, 0
	bl sub_8099690
	movs r0, 0xB
	bl sub_801B748
	b _0801BD7A
	.align 2, 0
_0801BD64: .4byte gUnknown_203B234
_0801BD68: .4byte gUnknown_203B460
_0801BD6C: .4byte gUnknown_202DEA8
_0801BD70:
	bl sub_801A928
	movs r0, 0x6
	bl sub_801B748
_0801BD7A:
	pop {r0}
	bx r0
	thumb_func_end sub_801BCCC

	thumb_func_start sub_801BD80
sub_801BD80:
	push {r4,lr}
	sub sp, 0x4
	movs r0, 0
	str r0, [sp]
	bl sub_801A6E8
	ldr r4, _0801BDC4
	ldr r0, [r4]
	adds r0, 0x28
	bl sub_8012FD8
	lsls r0, 24
	cmp r0, 0
	bne _0801BDB2
	ldr r0, [r4]
	adds r0, 0x28
	mov r1, sp
	bl sub_8013114
	ldr r1, [sp]
	cmp r1, 0x1
	beq _0801BDB2
	ldr r0, [r4]
	adds r0, 0xC8
	str r1, [r0]
_0801BDB2:
	ldr r0, [sp]
	cmp r0, 0x6
	beq _0801BDD2
	cmp r0, 0x6
	bgt _0801BDC8
	cmp r0, 0x1
	beq _0801BE22
	b _0801BE28
	.align 2, 0
_0801BDC4: .4byte gUnknown_203B234
_0801BDC8:
	cmp r0, 0x7
	beq _0801BE0C
	cmp r0, 0x8
	beq _0801BE14
	b _0801BE28
_0801BDD2:
	ldr r4, _0801BE08
	ldr r0, [r4]
	adds r0, 0x20
	bl sub_80917B8
	ldr r0, [r4]
	ldr r0, [r0, 0x24]
	bl sub_80911F8
	ldr r0, [r4]
	adds r0, 0x10
	bl sub_8091290
	bl sub_80910B4
	movs r0, 0xCB
	bl sub_8011988
	movs r0, 0
	bl sub_8099690
	bl sub_801A928
	movs r0, 0xE
	bl sub_801B748
	b _0801BE28
	.align 2, 0
_0801BE08: .4byte gUnknown_203B234
_0801BE0C:
	movs r0, 0xC
	bl sub_801B748
	b _0801BE28
_0801BE14:
	movs r0, 0
	bl sub_8099690
	movs r0, 0xB
	bl sub_801B748
	b _0801BE28
_0801BE22:
	movs r0, 0x9
	bl sub_801B748
_0801BE28:
	add sp, 0x4
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_801BD80

	thumb_func_start sub_801BE30
sub_801BE30:
	push {r4,lr}
	sub sp, 0x4
	movs r0, 0
	str r0, [sp]
	bl sub_801A6E8
	ldr r4, _0801BE70
	ldr r0, [r4]
	adds r0, 0x28
	bl sub_8012FD8
	ldr r0, [r4]
	adds r0, 0x78
	bl sub_8012FD8
	lsls r0, 24
	cmp r0, 0
	bne _0801BE5E
	ldr r0, [r4]
	adds r0, 0x78
	mov r1, sp
	bl sub_8013114
_0801BE5E:
	ldr r0, [sp]
	cmp r0, 0x2
	beq _0801BE80
	cmp r0, 0x2
	bgt _0801BE74
	cmp r0, 0x1
	beq _0801BE78
	b _0801BEA4
	.align 2, 0
_0801BE70: .4byte gUnknown_203B234
_0801BE74:
	cmp r0, 0x3
	bne _0801BEA4
_0801BE78:
	movs r0, 0x9
	bl sub_801B748
	b _0801BEA4
_0801BE80:
	ldr r0, [r4]
	ldr r0, [r0, 0x24]
	bl sub_80911F8
	ldr r0, [r4]
	adds r0, 0x10
	bl sub_8091290
	bl sub_80910B4
	movs r0, 0xCB
	bl sub_8011988
	bl sub_801A928
	movs r0, 0xF
	bl sub_801B748
_0801BEA4:
	add sp, 0x4
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_801BE30

	thumb_func_start sub_801BEAC
sub_801BEAC:
	push {lr}
	bl sub_801B410
	cmp r0, 0x1
	bls _0801BEC4
	cmp r0, 0x3
	bhi _0801BEC4
	bl sub_801B450
	movs r0, 0x9
	bl sub_801B748
_0801BEC4:
	pop {r0}
	bx r0
	thumb_func_end sub_801BEAC

	thumb_func_start sub_801BEC8
sub_801BEC8:
	push {lr}
	sub sp, 0x4
	mov r0, sp
	bl sub_80144A4
	cmp r0, 0
	bne _0801BEE0
	ldr r0, _0801BEE8
	ldr r0, [r0]
	ldr r0, [r0, 0x8]
	bl sub_801B748
_0801BEE0:
	add sp, 0x4
	pop {r0}
	bx r0
	.align 2, 0
_0801BEE8: .4byte gUnknown_203B234
	thumb_func_end sub_801BEC8

	thumb_func_start sub_801BEEC
sub_801BEEC:
	push {r4-r6,lr}
	lsls r0, 16
	asrs r5, r0, 16
	adds r0, r5, 0
	bl sub_801C5F0
	lsls r0, 24
	lsrs r6, r0, 24
	cmp r6, 0
	bne _0801BF40
	ldr r4, _0801BF38
	movs r0, 0x92
	lsls r0, 1
	movs r1, 0x8
	bl MemoryAlloc
	str r0, [r4]
	str r6, [r0, 0x30]
	strh r5, [r0, 0x4]
	ldr r3, _0801BF3C
	movs r1, 0x58
	adds r2, r5, 0
	muls r2, r1
	ldr r1, [r3]
	adds r1, r2
	str r1, [r0, 0x8]
	adds r0, 0xC
	movs r2, 0x14
	ldrsh r1, [r1, r2]
	bl sub_808EBA8
	ldr r1, [r4]
	str r0, [r1, 0x2C]
	movs r0, 0
	bl sub_801BFB4
	movs r0, 0x1
	b _0801BF42
	.align 2, 0
_0801BF38: .4byte gUnknown_203B238
_0801BF3C: .4byte gUnknown_203B45C
_0801BF40:
	movs r0, 0
_0801BF42:
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end sub_801BEEC

	thumb_func_start sub_801BF48
sub_801BF48:
	push {lr}
	ldr r0, _0801BF60
	ldr r0, [r0]
	ldr r0, [r0]
	cmp r0, 0x4
	bhi _0801BF90
	lsls r0, 2
	ldr r1, _0801BF64
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0801BF60: .4byte gUnknown_203B238
_0801BF64: .4byte _0801BF68
	.align 2, 0
_0801BF68:
	.4byte _0801BF80
	.4byte _0801BF80
	.4byte _0801BF86
	.4byte _0801BF8C
	.4byte _0801BF7C
_0801BF7C:
	movs r0, 0x3
	b _0801BF92
_0801BF80:
	bl sub_801C118
	b _0801BF90
_0801BF86:
	bl sub_801C1A0
	b _0801BF90
_0801BF8C:
	bl sub_801C228
_0801BF90:
	movs r0, 0
_0801BF92:
	pop {r1}
	bx r1
	thumb_func_end sub_801BF48

	thumb_func_start sub_801BF98
sub_801BF98:
	push {r4,lr}
	ldr r4, _0801BFB0
	ldr r0, [r4]
	cmp r0, 0
	beq _0801BFAA
	bl MemoryFree
	movs r0, 0
	str r0, [r4]
_0801BFAA:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0801BFB0: .4byte gUnknown_203B238
	thumb_func_end sub_801BF98

	thumb_func_start sub_801BFB4
sub_801BFB4:
	push {lr}
	ldr r1, _0801BFC8
	ldr r1, [r1]
	str r0, [r1]
	bl sub_801BFCC
	bl sub_801C03C
	pop {r0}
	bx r0
	.align 2, 0
_0801BFC8: .4byte gUnknown_203B238
	thumb_func_end sub_801BFB4

	thumb_func_start sub_801BFCC
sub_801BFCC:
	push {r4-r7,lr}
	ldr r4, _0801BFF0
	ldr r0, [r4]
	adds r0, 0xC4
	bl sub_8006518
	ldr r1, [r4]
	ldr r0, [r1]
	cmp r0, 0x2
	bne _0801BFF8
	adds r1, 0xF4
	ldr r0, _0801BFF4
	ldm r0!, {r2-r4}
	stm r1!, {r2-r4}
	ldm r0!, {r5-r7}
	stm r1!, {r5-r7}
	b _0801C01A
	.align 2, 0
_0801BFF0: .4byte gUnknown_203B238
_0801BFF4: .4byte gUnknown_80DBDB0
_0801BFF8:
	mov r12, r4
	ldr r4, _0801C034
	movs r3, 0
	movs r2, 0x3
_0801C000:
	mov r0, r12
	ldr r1, [r0]
	adds r1, r3
	adds r1, 0xC4
	adds r0, r4, 0
	ldm r0!, {r5-r7}
	stm r1!, {r5-r7}
	ldm r0!, {r5-r7}
	stm r1!, {r5-r7}
	adds r3, 0x18
	subs r2, 0x1
	cmp r2, 0
	bge _0801C000
_0801C01A:
	bl sub_8004914
	ldr r0, _0801C038
	ldr r0, [r0]
	adds r0, 0xC4
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_0801C034: .4byte gUnknown_80DBD98
_0801C038: .4byte gUnknown_203B238
	thumb_func_end sub_801BFCC

	thumb_func_start sub_801C03C
sub_801C03C:
	push {lr}
	sub sp, 0x8
	ldr r1, _0801C058
	ldr r0, [r1]
	ldr r0, [r0]
	adds r2, r1, 0
	cmp r0, 0x4
	bhi _0801C0C2
	lsls r0, 2
	ldr r1, _0801C05C
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0801C058: .4byte gUnknown_203B238
_0801C05C: .4byte _0801C060
	.align 2, 0
_0801C060:
	.4byte _0801C074
	.4byte _0801C084
	.4byte _0801C08C
	.4byte _0801C0B8
	.4byte _0801C0C2
_0801C074:
	ldr r0, [r2]
	movs r1, 0x4
	ldrsh r0, [r0, r1]
	movs r1, 0
	movs r2, 0x8
	bl sub_801C244
	b _0801C0C2
_0801C084:
	movs r0, 0x1
	bl sub_801C3B0
	b _0801C0C2
_0801C08C:
	bl sub_801C4C8
	bl sub_801C0C8
	ldr r0, _0801C0B4
	ldr r2, [r0]
	adds r0, r2, 0
	adds r0, 0x74
	adds r1, r2, 0
	adds r1, 0x34
	ldr r2, [r2, 0x30]
	str r2, [sp]
	movs r2, 0x2
	str r2, [sp, 0x4]
	movs r2, 0
	movs r3, 0
	bl sub_8012D60
	b _0801C0C2
	.align 2, 0
_0801C0B4: .4byte gUnknown_203B238
_0801C0B8:
	ldr r0, [r2]
	adds r0, 0x28
	ldrb r0, [r0]
	bl sub_801C620
_0801C0C2:
	add sp, 0x8
	pop {r0}
	bx r0
	thumb_func_end sub_801C03C

	thumb_func_start sub_801C0C8
sub_801C0C8:
	push {r4,r5,lr}
	ldr r3, _0801C10C
	ldr r1, [r3]
	movs r4, 0
	ldr r0, _0801C110
	str r0, [r1, 0x34]
	movs r0, 0x2
	str r0, [r1, 0x38]
	movs r2, 0x1
	ldr r0, _0801C114
	ldr r0, [r0]
	str r0, [r1, 0x3C]
	movs r0, 0x3
	str r0, [r1, 0x40]
	movs r5, 0x2
	str r4, [r1, 0x44]
	str r2, [r1, 0x48]
	movs r2, 0
	ldr r4, [r1, 0x30]
	adds r1, 0x38
_0801C0F0:
	ldr r0, [r1]
	cmp r0, r4
	beq _0801C104
	adds r1, 0x8
	adds r2, 0x1
	cmp r2, r5
	blt _0801C0F0
	ldr r1, [r3]
	movs r0, 0x2
	str r0, [r1, 0x30]
_0801C104:
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_0801C10C: .4byte gUnknown_203B238
_0801C110: .4byte gUnknown_80DBDC8
_0801C114: .4byte gUnknown_80D4970
	thumb_func_end sub_801C0C8

	thumb_func_start sub_801C118
sub_801C118:
	push {lr}
	movs r0, 0x1
	bl sub_801C308
	cmp r0, 0x4
	bhi _0801C19A
	lsls r0, 2
	ldr r1, _0801C130
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0801C130: .4byte _0801C134
	.align 2, 0
_0801C134:
	.4byte _0801C19A
	.4byte _0801C19A
	.4byte _0801C190
	.4byte _0801C148
	.4byte _0801C16C
_0801C148:
	bl sub_801C390
	ldr r1, _0801C168
	ldr r2, [r1]
	str r0, [r2, 0x24]
	adds r1, r2, 0
	adds r1, 0xC
	adds r1, r0
	ldrb r0, [r1]
	adds r2, 0x28
	strb r0, [r2]
	movs r0, 0x2
	bl sub_801BFB4
	b _0801C19A
	.align 2, 0
_0801C168: .4byte gUnknown_203B238
_0801C16C:
	bl sub_801C390
	ldr r1, _0801C18C
	ldr r2, [r1]
	str r0, [r2, 0x24]
	adds r1, r2, 0
	adds r1, 0xC
	adds r1, r0
	ldrb r0, [r1]
	adds r2, 0x28
	strb r0, [r2]
	movs r0, 0x3
	bl sub_801BFB4
	b _0801C19A
	.align 2, 0
_0801C18C: .4byte gUnknown_203B238
_0801C190:
	bl sub_801C3F8
	movs r0, 0x4
	bl sub_801BFB4
_0801C19A:
	pop {r0}
	bx r0
	thumb_func_end sub_801C118

	thumb_func_start sub_801C1A0
sub_801C1A0:
	push {r4,lr}
	sub sp, 0x4
	movs r0, 0
	str r0, [sp]
	bl sub_801C308
	ldr r4, _0801C1E0
	ldr r0, [r4]
	adds r0, 0x74
	bl sub_8012FD8
	lsls r0, 24
	cmp r0, 0
	bne _0801C1D0
	ldr r0, [r4]
	adds r0, 0x74
	mov r1, sp
	bl sub_8013114
	ldr r1, [sp]
	cmp r1, 0x1
	beq _0801C1D0
	ldr r0, [r4]
	str r1, [r0, 0x30]
_0801C1D0:
	ldr r0, [sp]
	cmp r0, 0x2
	beq _0801C1EA
	cmp r0, 0x2
	bgt _0801C1E4
	cmp r0, 0x1
	beq _0801C218
	b _0801C21E
	.align 2, 0
_0801C1E0: .4byte gUnknown_203B238
_0801C1E4:
	cmp r0, 0x3
	beq _0801C210
	b _0801C21E
_0801C1EA:
	ldr r0, _0801C208
	bl sub_8011988
	ldr r0, _0801C20C
	ldr r1, [r0]
	ldr r0, [r1, 0x8]
	adds r0, 0x20
	adds r1, 0x28
	ldrb r1, [r1]
	bl sub_808EBF4
	movs r0, 0x1
	bl sub_801BFB4
	b _0801C21E
	.align 2, 0
_0801C208: .4byte 0x00000133
_0801C20C: .4byte gUnknown_203B238
_0801C210:
	movs r0, 0x3
	bl sub_801BFB4
	b _0801C21E
_0801C218:
	movs r0, 0x1
	bl sub_801BFB4
_0801C21E:
	add sp, 0x4
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_801C1A0

	thumb_func_start sub_801C228
sub_801C228:
	push {lr}
	bl sub_801C674
	cmp r0, 0x1
	bls _0801C240
	cmp r0, 0x3
	bhi _0801C240
	bl sub_801C6B4
	movs r0, 0x1
	bl sub_801BFB4
_0801C240:
	pop {r0}
	bx r0
	thumb_func_end sub_801C228

	thumb_func_start sub_801C244
sub_801C244:
	push {r4-r7,lr}
	adds r6, r1, 0
	adds r7, r2, 0
	lsls r0, 16
	asrs r0, 16
	adds r4, r0, 0
	bl sub_801C5F0
	lsls r0, 24
	cmp r0, 0
	beq _0801C25E
	movs r0, 0
	b _0801C2F6
_0801C25E:
	ldr r5, _0801C2FC
	ldr r0, [r5]
	cmp r0, 0
	bne _0801C270
	movs r0, 0xC4
	movs r1, 0x8
	bl MemoryAlloc
	str r0, [r5]
_0801C270:
	ldr r0, [r5]
	strh r4, [r0]
	ldr r3, _0801C300
	movs r1, 0x58
	adds r2, r4, 0
	muls r2, r1
	ldr r1, [r3]
	adds r1, r2
	str r1, [r0, 0x4]
	adds r0, 0x8
	movs r2, 0x14
	ldrsh r1, [r1, r2]
	bl sub_808EBA8
	adds r1, r0, 0
	ldr r0, [r5]
	str r1, [r0, 0x20]
	str r6, [r0, 0x58]
	lsls r1, r6, 1
	adds r1, r6
	lsls r1, 3
	adds r1, 0x60
	adds r1, r0, r1
	str r1, [r0, 0x5C]
	adds r0, 0x60
	bl sub_8006518
	ldr r1, [r5]
	ldr r2, [r1, 0x58]
	lsls r0, r2, 1
	adds r0, r2
	lsls r0, 3
	adds r1, r0
	adds r1, 0x60
	ldr r0, _0801C304
	ldm r0!, {r2-r4}
	stm r1!, {r2-r4}
	ldm r0!, {r2-r4}
	stm r1!, {r2-r4}
	ldr r1, [r5]
	ldr r0, [r1, 0x5C]
	adds r1, 0xC0
	str r1, [r0, 0x14]
	adds r1, r7, 0
	bl sub_8012D08
	bl sub_8004914
	ldr r0, [r5]
	adds r0, 0x60
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	ldr r1, [r5]
	adds r0, r1, 0
	adds r0, 0x24
	ldr r1, [r1, 0x20]
	adds r2, r7, 0
	adds r3, r6, 0
	bl sub_8013818
	bl sub_801C440
	bl sub_801C4C8
	movs r0, 0x1
_0801C2F6:
	pop {r4-r7}
	pop {r1}
	bx r1
	.align 2, 0
_0801C2FC: .4byte gUnknown_203B23C
_0801C300: .4byte gUnknown_203B45C
_0801C304: .4byte gUnknown_80DBDF0
	thumb_func_end sub_801C244

	thumb_func_start sub_801C308
sub_801C308:
	push {lr}
	lsls r0, 24
	cmp r0, 0
	bne _0801C324
	ldr r0, _0801C320
	ldr r0, [r0]
	adds r0, 0x24
	bl sub_8013660
	movs r0, 0
	b _0801C38A
	.align 2, 0
_0801C320: .4byte gUnknown_203B23C
_0801C324:
	ldr r0, _0801C33C
	ldr r0, [r0]
	adds r0, 0x24
	bl GetKeyPress
	cmp r0, 0x2
	beq _0801C346
	cmp r0, 0x2
	bgt _0801C340
	cmp r0, 0x1
	beq _0801C350
	b _0801C364
	.align 2, 0
_0801C33C: .4byte gUnknown_203B23C
_0801C340:
	cmp r0, 0x4
	beq _0801C35A
	b _0801C364
_0801C346:
	movs r0, 0x1
	bl sub_80119D4
	movs r0, 0x2
	b _0801C38A
_0801C350:
	movs r0, 0
	bl sub_80119D4
	movs r0, 0x3
	b _0801C38A
_0801C35A:
	movs r0, 0x4
	bl sub_80119D4
	movs r0, 0x4
	b _0801C38A
_0801C364:
	ldr r0, _0801C37C
	ldr r0, [r0]
	adds r0, 0x24
	movs r1, 0x1
	bl sub_80138B8
	lsls r0, 24
	cmp r0, 0
	bne _0801C380
	movs r0, 0
	b _0801C38A
	.align 2, 0
_0801C37C: .4byte gUnknown_203B23C
_0801C380:
	bl sub_801C440
	bl sub_801C4C8
	movs r0, 0x1
_0801C38A:
	pop {r1}
	bx r1
	thumb_func_end sub_801C308

	thumb_func_start sub_801C390
sub_801C390:
	ldr r0, _0801C3AC
	ldr r2, [r0]
	adds r0, r2, 0
	adds r0, 0x42
	movs r3, 0
	ldrsh r1, [r0, r3]
	subs r0, 0x2
	movs r3, 0
	ldrsh r0, [r0, r3]
	muls r0, r1
	movs r3, 0x3C
	ldrsh r1, [r2, r3]
	adds r0, r1
	bx lr
	.align 2, 0
_0801C3AC: .4byte gUnknown_203B23C
	thumb_func_end sub_801C390

	thumb_func_start sub_801C3B0
sub_801C3B0:
	push {r4,r5,lr}
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	bl sub_8004914
	ldr r5, _0801C3F4
	ldr r0, [r5]
	adds r0, 0x60
	movs r1, 0
	movs r2, 0
	bl sub_800641C
	ldr r0, [r5]
	ldr r1, [r0, 0x20]
	adds r2, r0, 0
	adds r2, 0x46
	strh r1, [r2]
	adds r0, 0x24
	bl sub_8013984
	bl sub_801C440
	bl sub_801C4C8
	cmp r4, 0
	beq _0801C3EE
	ldr r0, [r5]
	adds r0, 0x24
	bl AddMenuCursorSprite
_0801C3EE:
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_0801C3F4: .4byte gUnknown_203B23C
	thumb_func_end sub_801C3B0

	thumb_func_start sub_801C3F8
sub_801C3F8:
	push {r4,r5,lr}
	ldr r4, _0801C438
	ldr r2, [r4]
	cmp r2, 0
	beq _0801C432
	ldr r0, [r2, 0x58]
	lsls r1, r0, 1
	adds r1, r0
	lsls r1, 3
	adds r1, r2, r1
	adds r1, 0x60
	ldr r0, _0801C43C
	ldm r0!, {r2,r3,r5}
	stm r1!, {r2,r3,r5}
	ldm r0!, {r2,r3,r5}
	stm r1!, {r2,r3,r5}
	bl sub_8004914
	ldr r0, [r4]
	adds r0, 0x60
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	ldr r0, [r4]
	bl MemoryFree
	movs r0, 0
	str r0, [r4]
_0801C432:
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_0801C438: .4byte gUnknown_203B23C
_0801C43C: .4byte gUnknown_80DBDD8
	thumb_func_end sub_801C3F8

	thumb_func_start sub_801C440
sub_801C440:
	push {r4,lr}
	ldr r4, _0801C4C4
	ldr r0, [r4]
	adds r1, r0, 0
	adds r1, 0x44
	ldrh r1, [r1]
	adds r0, 0xC0
	movs r2, 0
	strb r1, [r0]
	ldr r0, [r4]
	adds r1, r0, 0
	adds r1, 0x42
	ldrh r1, [r1]
	adds r0, 0xC1
	strb r1, [r0]
	ldr r0, [r4]
	adds r0, 0xC2
	movs r1, 0xA
	strb r1, [r0]
	ldr r0, [r4]
	adds r0, 0xC3
	strb r2, [r0]
	bl sub_8004914
	ldr r0, [r4]
	adds r0, 0x60
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	ldr r0, [r4]
	movs r1, 0x3E
	ldrsh r0, [r0, r1]
	movs r1, 0xC
	bl sub_80095E4
	adds r0, 0x2
	ldr r2, [r4]
	ldr r3, [r2, 0x58]
	lsls r1, r3, 1
	adds r1, r3
	lsls r1, 3
	adds r1, r2, r1
	adds r1, 0x6E
	lsls r0, 16
	lsrs r0, 16
	strh r0, [r1]
	ldr r3, [r2, 0x58]
	lsls r1, r3, 1
	adds r1, r3
	lsls r1, 3
	adds r2, r1
	adds r2, 0x70
	strh r0, [r2]
	bl sub_8004914
	ldr r0, [r4]
	adds r0, 0x60
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0801C4C4: .4byte gUnknown_203B23C
	thumb_func_end sub_801C440

	thumb_func_start sub_801C4C8
sub_801C4C8:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0x8
	ldr r6, _0801C594
	ldr r0, [r6]
	ldr r0, [r0, 0x58]
	bl sub_8008C54
	ldr r0, [r6]
	ldr r0, [r0, 0x58]
	bl sub_80073B8
	ldr r0, [r6]
	adds r1, r0, 0
	adds r1, 0x42
	movs r2, 0
	ldrsh r4, [r1, r2]
	lsls r4, 3
	adds r5, r4, 0
	adds r5, 0xA
	ldr r2, _0801C598
	ldr r3, [r0, 0x58]
	movs r0, 0
	str r0, [sp]
	adds r0, r5, 0
	movs r1, 0
	bl xxx_call_draw_string
	adds r4, 0x4
	ldr r1, [r6]
	adds r0, r1, 0
	adds r0, 0xC2
	ldrb r0, [r0]
	lsls r0, 3
	adds r5, r4, r0
	adds r0, r1, 0
	adds r0, 0x42
	movs r3, 0
	ldrsh r2, [r0, r3]
	adds r2, 0x1
	movs r0, 0x7
	str r0, [sp]
	ldr r0, [r1, 0x58]
	str r0, [sp, 0x4]
	adds r0, r5, 0
	movs r1, 0
	movs r3, 0x1
	bl sub_8012BC4
	movs r5, 0
	ldr r0, [r6]
	movs r1, 0x3E
	ldrsh r0, [r0, r1]
	cmp r5, r0
	bge _0801C5CC
	ldr r2, _0801C59C
	mov r8, r2
_0801C53C:
	ldr r2, [r6]
	adds r0, r2, 0
	adds r0, 0x42
	movs r3, 0
	ldrsh r1, [r0, r3]
	subs r0, 0x2
	movs r3, 0
	ldrsh r0, [r0, r3]
	muls r1, r0
	adds r1, r5
	adds r0, r2, 0
	adds r0, 0x8
	adds r0, r1
	ldrb r4, [r0]
	adds r0, r2, 0
	adds r0, 0x24
	adds r1, r5, 0
	bl sub_8013800
	adds r7, r0, 0
	adds r0, r4, 0
	bl sub_808EAB0
	adds r1, r0, 0
	mov r0, r8
	movs r2, 0x50
	bl strncpy
	ldr r0, [r6]
	ldr r0, [r0, 0x4]
	adds r0, 0x20
	movs r1, 0x1
	lsls r1, r4
	bl sub_808ECD0
	lsls r0, 24
	cmp r0, 0
	beq _0801C5A4
	mov r0, r8
	subs r0, 0x50
	ldr r1, _0801C5A0
	bl strcpy
	b _0801C5AE
	.align 2, 0
_0801C594: .4byte gUnknown_203B23C
_0801C598: .4byte gUnknown_80DBE08
_0801C59C: .4byte gUnknown_202DEA8
_0801C5A0: .4byte gUnknown_80DBE14
_0801C5A4:
	mov r0, r8
	subs r0, 0x50
	ldr r1, _0801C5E4
	bl strcpy
_0801C5AE:
	ldr r0, [r6]
	ldr r3, [r0, 0x58]
	movs r0, 0
	str r0, [sp]
	movs r0, 0xC
	adds r1, r7, 0
	ldr r2, _0801C5E8
	bl sub_8014FF0
	adds r5, 0x1
	ldr r0, [r6]
	movs r1, 0x3E
	ldrsh r0, [r0, r1]
	cmp r5, r0
	blt _0801C53C
_0801C5CC:
	ldr r0, _0801C5EC
	ldr r0, [r0]
	ldr r0, [r0, 0x58]
	bl sub_80073E0
	add sp, 0x8
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_0801C5E4: .4byte gUnknown_80DBE18
_0801C5E8: .4byte gUnknown_80DBE1C
_0801C5EC: .4byte gUnknown_203B23C
	thumb_func_end sub_801C4C8

	thumb_func_start sub_801C5F0
sub_801C5F0:
	push {lr}
	sub sp, 0x18
	lsls r0, 16
	asrs r0, 16
	ldr r2, _0801C614
	movs r1, 0x58
	muls r1, r0
	ldr r0, [r2]
	adds r0, r1
	movs r2, 0x14
	ldrsh r1, [r0, r2]
	mov r0, sp
	bl sub_808EBA8
	cmp r0, 0
	beq _0801C618
	movs r0, 0
	b _0801C61A
	.align 2, 0
_0801C614: .4byte gUnknown_203B45C
_0801C618:
	movs r0, 0x1
_0801C61A:
	add sp, 0x18
	pop {r1}
	bx r1
	thumb_func_end sub_801C5F0

	thumb_func_start sub_801C620
sub_801C620:
	push {r4-r6,lr}
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	movs r0, 0x1
	bl ResetSprites
	ldr r5, _0801C670
	movs r0, 0x94
	movs r1, 0x8
	bl MemoryAlloc
	str r0, [r5]
	movs r6, 0
	strb r4, [r0, 0x4]
	ldr r0, [r5]
	adds r0, 0x88
	bl sub_801317C
	ldr r0, [r5]
	str r6, [r0, 0x24]
	adds r0, 0x28
	bl sub_80140B4
	bl sub_8004914
	ldr r0, [r5]
	adds r0, 0x28
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	movs r0, 0
	bl sub_801C6D0
	movs r0, 0x1
	pop {r4-r6}
	pop {r1}
	bx r1
	.align 2, 0
_0801C670: .4byte gUnknown_203B240
	thumb_func_end sub_801C620

	thumb_func_start sub_801C674
sub_801C674:
	push {lr}
	ldr r0, _0801C68C
	ldr r0, [r0]
	ldr r0, [r0]
	cmp r0, 0x1
	beq _0801C6A0
	cmp r0, 0x1
	bgt _0801C690
	cmp r0, 0
	beq _0801C69A
	b _0801C6AA
	.align 2, 0
_0801C68C: .4byte gUnknown_203B240
_0801C690:
	cmp r0, 0x2
	beq _0801C6AA
	cmp r0, 0x3
	beq _0801C6A6
	b _0801C6AA
_0801C69A:
	bl sub_801C7D4
	b _0801C6AE
_0801C6A0:
	bl sub_801C848
	b _0801C6AE
_0801C6A6:
	movs r0, 0x3
	b _0801C6B0
_0801C6AA:
	movs r0, 0x2
	b _0801C6B0
_0801C6AE:
	movs r0, 0
_0801C6B0:
	pop {r1}
	bx r1
	thumb_func_end sub_801C674

	thumb_func_start sub_801C6B4
sub_801C6B4:
	push {r4,lr}
	ldr r4, _0801C6CC
	ldr r0, [r4]
	cmp r0, 0
	beq _0801C6C6
	bl MemoryFree
	movs r0, 0
	str r0, [r4]
_0801C6C6:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0801C6CC: .4byte gUnknown_203B240
	thumb_func_end sub_801C6B4

	thumb_func_start sub_801C6D0
sub_801C6D0:
	push {lr}
	ldr r1, _0801C6E0
	ldr r1, [r1]
	str r0, [r1]
	bl sub_801C6E4
	pop {r0}
	bx r0
	.align 2, 0
_0801C6E0: .4byte gUnknown_203B240
	thumb_func_end sub_801C6D0

	thumb_func_start sub_801C6E4
sub_801C6E4:
	push {r4,r5,lr}
	sub sp, 0x4
	ldr r5, _0801C760
	ldr r0, [r5]
	ldr r4, [r0]
	cmp r4, 0x1
	beq _0801C76C
	cmp r4, 0x1
	bgt _0801C7C4
	cmp r4, 0
	bne _0801C7C4
	ldr r0, [r0, 0x24]
	bl sub_8008C54
	ldr r0, [r5]
	ldr r0, [r0, 0x24]
	bl sub_80073B8
	ldr r0, [r5]
	ldrb r0, [r0, 0x4]
	bl sub_808EAB0
	adds r1, r0, 0
	ldr r0, _0801C764
	bl strcpy
	ldr r2, _0801C768
	str r4, [sp]
	movs r0, 0x10
	movs r1, 0
	movs r3, 0
	bl sub_8014FF0
	ldr r0, [r5]
	ldrb r0, [r0, 0x4]
	bl sub_808EADC
	adds r2, r0, 0
	ldr r0, [r5]
	ldr r3, [r0, 0x24]
	str r4, [sp]
	movs r0, 0x8
	movs r1, 0x10
	bl xxx_call_draw_string
	ldr r0, [r5]
	ldr r0, [r0, 0x24]
	bl sub_80073E0
	ldr r0, [r5]
	ldrb r0, [r0, 0x4]
	bl sub_808EADC
	ldr r1, [r5]
	adds r1, 0x10
	bl sub_8097DF0
	ldr r1, [r5]
	str r0, [r1, 0xC]
	str r4, [r1, 0x20]
	b _0801C7C4
	.align 2, 0
_0801C760: .4byte gUnknown_203B240
_0801C764: .4byte gUnknown_202DE58
_0801C768: .4byte gUnknown_80DBE2C
_0801C76C:
	ldr r0, [r0, 0x24]
	bl sub_8008C54
	ldr r0, [r5]
	ldr r0, [r0, 0x24]
	bl sub_80073B8
	ldr r0, [r5]
	ldr r1, [r0, 0x8]
	lsls r1, 2
	adds r0, 0x10
	adds r0, r1
	ldr r1, [r0]
	ldr r0, _0801C7CC
	ldr r1, [r1]
	bl strcpy
	ldr r2, _0801C7D0
	ldr r0, [r5]
	ldr r3, [r0, 0x24]
	movs r4, 0
	str r4, [sp]
	movs r0, 0x10
	movs r1, 0
	bl sub_8014FF0
	ldr r3, [r5]
	ldr r1, [r3, 0x8]
	lsls r1, 2
	adds r0, r3, 0
	adds r0, 0x10
	adds r0, r1
	ldr r0, [r0]
	ldr r2, [r0, 0x4]
	ldr r3, [r3, 0x24]
	str r4, [sp]
	movs r0, 0x4
	movs r1, 0x10
	bl sub_8014FF0
	ldr r0, [r5]
	ldr r0, [r0, 0x24]
	bl sub_80073E0
_0801C7C4:
	add sp, 0x4
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_0801C7CC: .4byte gUnknown_202DF98
_0801C7D0: .4byte gUnknown_80DBE30
	thumb_func_end sub_801C6E4

	thumb_func_start sub_801C7D4
sub_801C7D4:
	push {r4,lr}
	ldr r0, _0801C810
	ldr r2, [r0]
	ldr r1, [r2, 0xC]
	adds r4, r0, 0
	cmp r1, 0
	beq _0801C7F8
	ldr r0, [r2, 0x20]
	movs r1, 0x8
	ands r0, r1
	cmp r0, 0
	beq _0801C7F0
	bl sub_8013F84
_0801C7F0:
	ldr r1, [r4]
	ldr r0, [r1, 0x20]
	adds r0, 0x1
	str r0, [r1, 0x20]
_0801C7F8:
	ldr r1, [r4]
	adds r0, r1, 0
	adds r0, 0x88
	ldr r1, [r1, 0x24]
	bl sub_8012A64
	cmp r0, 0x1
	beq _0801C814
	cmp r0, 0x2
	beq _0801C836
	b _0801C842
	.align 2, 0
_0801C810: .4byte gUnknown_203B240
_0801C814:
	movs r0, 0
	bl sub_80119D4
	ldr r1, [r4]
	ldr r0, [r1, 0xC]
	cmp r0, 0
	beq _0801C82E
	movs r0, 0
	str r0, [r1, 0x8]
	movs r0, 0x1
	bl sub_801C6D0
	b _0801C842
_0801C82E:
	movs r0, 0x3
	bl sub_801C6D0
	b _0801C842
_0801C836:
	movs r0, 0x1
	bl sub_80119D4
	movs r0, 0x2
	bl sub_801C6D0
_0801C842:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_801C7D4

	thumb_func_start sub_801C848
sub_801C848:
	push {r4,lr}
	ldr r0, _0801C888
	ldr r3, [r0]
	ldr r1, [r3, 0xC]
	subs r1, 0x1
	ldr r2, [r3, 0x8]
	adds r4, r0, 0
	cmp r2, r1
	bge _0801C870
	ldr r0, [r3, 0x20]
	movs r1, 0x8
	ands r0, r1
	cmp r0, 0
	beq _0801C868
	bl sub_8013F84
_0801C868:
	ldr r1, [r4]
	ldr r0, [r1, 0x20]
	adds r0, 0x1
	str r0, [r1, 0x20]
_0801C870:
	ldr r1, [r4]
	adds r0, r1, 0
	adds r0, 0x88
	ldr r1, [r1, 0x24]
	bl sub_8012A64
	cmp r0, 0x1
	beq _0801C88C
	cmp r0, 0x2
	beq _0801C8B0
	b _0801C8BC
	.align 2, 0
_0801C888: .4byte gUnknown_203B240
_0801C88C:
	movs r0, 0
	bl sub_80119D4
	ldr r0, [r4]
	ldr r1, [r0, 0x8]
	adds r1, 0x1
	str r1, [r0, 0x8]
	ldr r0, [r0, 0xC]
	cmp r1, r0
	bge _0801C8A8
	movs r0, 0x1
	bl sub_801C6D0
	b _0801C8BC
_0801C8A8:
	movs r0, 0
	bl sub_801C6D0
	b _0801C8BC
_0801C8B0:
	movs r0, 0x1
	bl sub_80119D4
	movs r0, 0x2
	bl sub_801C6D0
_0801C8BC:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_801C848

	thumb_func_start sub_801C8C4
sub_801C8C4:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	adds r4, r0, 0
	adds r6, r1, 0
	mov r9, r2
	mov r10, r3
	bl sub_801CF14
	lsls r0, 24
	cmp r0, 0
	beq _0801C8E4
	movs r0, 0
	b _0801C9D0
_0801C8E4:
	ldr r5, _0801C9E0
	ldr r0, [r5]
	cmp r0, 0
	bne _0801C8F6
	ldr r0, _0801C9E4
	movs r1, 0x8
	bl MemoryAlloc
	str r0, [r5]
_0801C8F6:
	ldr r0, [r5]
	str r4, [r0]
	bl sub_801CF94
	ldr r0, [r5]
	movs r4, 0x9D
	lsls r4, 3
	adds r1, r0, r4
	str r6, [r1]
	ldr r1, _0801C9E8
	mov r8, r1
	adds r2, r0, r1
	lsls r1, r6, 1
	adds r1, r6
	lsls r1, 3
	movs r7, 0x9E
	lsls r7, 3
	adds r1, r7
	adds r1, r0, r1
	str r1, [r2]
	adds r0, r7
	bl sub_8006518
	ldr r1, [r5]
	adds r4, r1, r4
	ldr r2, [r4]
	lsls r0, r2, 1
	adds r0, r2
	lsls r0, 3
	adds r1, r0
	adds r1, r7
	ldr r0, _0801C9EC
	ldm r0!, {r2-r4}
	stm r1!, {r2-r4}
	ldm r0!, {r2-r4}
	stm r1!, {r2-r4}
	ldr r2, [r5]
	mov r1, r8
	adds r0, r2, r1
	ldr r1, [r0]
	movs r3, 0xAA
	lsls r3, 3
	adds r0, r2, r3
	str r0, [r1, 0x14]
	mov r4, r9
	cmp r4, 0
	beq _0801C96C
	movs r1, 0x9D
	lsls r1, 3
	adds r0, r2, r1
	ldr r1, [r0]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 3
	subs r3, 0x58
	adds r1, r2, r3
	adds r1, r0
	ldr r0, [r4]
	str r0, [r1]
_0801C96C:
	ldr r0, [r5]
	add r0, r8
	ldr r0, [r0]
	mov r1, r10
	bl sub_8012D08
	bl sub_8004914
	ldr r0, [r5]
	adds r0, r7
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	ldr r4, [r5]
	ldr r0, _0801C9F0
	adds r4, r0
	bl sub_801CE58
	adds r1, r0, 0
	adds r0, r4, 0
	mov r2, r10
	adds r3, r6, 0
	bl sub_8013818
	ldr r0, _0801C9F4
	ldr r4, [r5]
	ldr r1, [r0]
	ldr r0, [r4]
	cmp r1, r0
	bne _0801C9C6
	ldr r0, _0801C9F8
	ldrh r1, [r0]
	ldr r2, _0801C9FC
	adds r0, r4, r2
	strh r1, [r0]
	ldr r0, _0801CA00
	ldrh r1, [r0]
	ldr r3, _0801CA04
	adds r0, r4, r3
	strh r1, [r0]
	ldr r1, _0801C9F0
	adds r0, r4, r1
	bl sub_8013984
_0801C9C6:
	bl sub_801CC38
	bl sub_801CCD8
	movs r0, 0x1
_0801C9D0:
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	.align 2, 0
_0801C9E0: .4byte gUnknown_203B244
_0801C9E4: .4byte 0x00000554
_0801C9E8: .4byte 0x000004ec
_0801C9EC: .4byte gUnknown_80DBE54
_0801C9F0: .4byte 0x000004b4
_0801C9F4: .4byte gUnknown_203B248
_0801C9F8: .4byte gUnknown_203B24C
_0801C9FC: .4byte 0x000004cc
_0801CA00: .4byte gUnknown_203B24E
_0801CA04: .4byte 0x000004d2
	thumb_func_end sub_801C8C4

	thumb_func_start sub_801CA08
sub_801CA08:
	push {r4-r6,lr}
	lsls r0, 24
	cmp r0, 0
	bne _0801CA28
	ldr r0, _0801CA20
	ldr r0, [r0]
	ldr r1, _0801CA24
	adds r0, r1
	bl sub_8013660
	movs r0, 0
	b _0801CB1E
	.align 2, 0
_0801CA20: .4byte gUnknown_203B244
_0801CA24: .4byte 0x000004b4
_0801CA28:
	ldr r0, _0801CA44
	ldr r0, [r0]
	ldr r1, _0801CA48
	adds r0, r1
	bl GetKeyPress
	subs r0, 0x1
	cmp r0, 0x5
	bhi _0801CAF2
	lsls r0, 2
	ldr r1, _0801CA4C
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0801CA44: .4byte gUnknown_203B244
_0801CA48: .4byte 0x000004b4
_0801CA4C: .4byte _0801CA50
	.align 2, 0
_0801CA50:
	.4byte _0801CA72
	.4byte _0801CA68
	.4byte _0801CAF2
	.4byte _0801CAE8
	.4byte _0801CA7C
	.4byte _0801CA7C
_0801CA68:
	movs r0, 0x1
	bl sub_80119D4
	movs r0, 0x2
	b _0801CB1E
_0801CA72:
	movs r0, 0
	bl sub_80119D4
	movs r0, 0x3
	b _0801CB1E
_0801CA7C:
	ldr r0, _0801CAD8
	ldr r0, [r0]
	ldr r0, [r0]
	cmp r0, 0x1
	bne _0801CAF2
	bl sub_801CB24
	lsls r0, 24
	lsrs r5, r0, 24
	adds r0, r5, 0
	bl sub_801CFE0
	movs r6, 0
	cmp r0, 0
	bne _0801CAB0
	bl sub_8090A34
	adds r4, r0, 0
	bl sub_801CFB8
	adds r4, r0
	cmp r4, 0x13
	bgt _0801CAAC
	movs r6, 0x1
_0801CAAC:
	cmp r6, 0
	beq _0801CAE0
_0801CAB0:
	movs r0, 0x6
	bl sub_80119D4
	ldr r0, _0801CAD8
	ldr r0, [r0]
	lsls r1, r5, 2
	adds r2, r0, 0
	adds r2, 0xF4
	adds r2, r1
	ldr r1, [r2]
	movs r3, 0x1
	eors r1, r3
	str r1, [r2]
	ldr r1, _0801CADC
	adds r0, r1
	movs r1, 0
	bl sub_80138B8
	b _0801CB18
	.align 2, 0
_0801CAD8: .4byte gUnknown_203B244
_0801CADC: .4byte 0x000004b4
_0801CAE0:
	movs r0, 0x2
	bl sub_80119D4
	b _0801CAF2
_0801CAE8:
	movs r0, 0x4
	bl sub_80119D4
	movs r0, 0x4
	b _0801CB1E
_0801CAF2:
	ldr r0, _0801CB0C
	ldr r0, [r0]
	ldr r1, _0801CB10
	adds r0, r1
	movs r1, 0x1
	bl sub_80138B8
	lsls r0, 24
	cmp r0, 0
	bne _0801CB14
	movs r0, 0
	b _0801CB1E
	.align 2, 0
_0801CB0C: .4byte gUnknown_203B244
_0801CB10: .4byte 0x000004b4
_0801CB14:
	bl sub_801CC38
_0801CB18:
	bl sub_801CCD8
	movs r0, 0x1
_0801CB1E:
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end sub_801CA08

	thumb_func_start sub_801CB24
sub_801CB24:
	ldr r0, _0801CB50
	ldr r0, [r0]
	ldr r2, _0801CB54
	adds r1, r0, r2
	movs r3, 0
	ldrsh r2, [r1, r3]
	movs r3, 0x9A
	lsls r3, 3
	adds r1, r0, r3
	movs r3, 0
	ldrsh r1, [r1, r3]
	muls r2, r1
	ldr r3, _0801CB58
	adds r1, r0, r3
	movs r3, 0
	ldrsh r1, [r1, r3]
	adds r2, r1
	adds r0, 0x4
	adds r0, r2
	ldrb r0, [r0]
	bx lr
	.align 2, 0
_0801CB50: .4byte gUnknown_203B244
_0801CB54: .4byte 0x000004d2
_0801CB58: .4byte 0x000004cc
	thumb_func_end sub_801CB24

	thumb_func_start sub_801CB5C
sub_801CB5C:
	push {r4,r5,lr}
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	bl sub_8004914
	ldr r5, _0801CBAC
	ldr r0, [r5]
	movs r1, 0x9E
	lsls r1, 3
	adds r0, r1
	movs r1, 0
	movs r2, 0
	bl sub_800641C
	bl sub_801CE58
	adds r2, r0, 0
	ldr r0, [r5]
	ldr r3, _0801CBB0
	adds r1, r0, r3
	strh r2, [r1]
	ldr r1, _0801CBB4
	adds r0, r1
	bl sub_8013984
	bl sub_801CC38
	bl sub_801CCD8
	cmp r4, 0
	beq _0801CBA6
	ldr r0, [r5]
	ldr r3, _0801CBB4
	adds r0, r3
	bl AddMenuCursorSprite
_0801CBA6:
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_0801CBAC: .4byte gUnknown_203B244
_0801CBB0: .4byte 0x000004d6
_0801CBB4: .4byte 0x000004b4
	thumb_func_end sub_801CB5C

	thumb_func_start sub_801CBB8
sub_801CBB8:
	push {r4-r6,lr}
	ldr r5, _0801CC1C
	ldr r2, [r5]
	cmp r2, 0
	beq _0801CC16
	ldr r1, _0801CC20
	ldr r0, [r2]
	str r0, [r1]
	ldr r1, _0801CC24
	ldr r3, _0801CC28
	adds r0, r2, r3
	ldrh r0, [r0]
	strh r0, [r1]
	ldr r1, _0801CC2C
	ldr r6, _0801CC30
	adds r0, r2, r6
	ldrh r0, [r0]
	strh r0, [r1]
	movs r1, 0x9D
	lsls r1, 3
	adds r0, r2, r1
	ldr r0, [r0]
	lsls r1, r0, 1
	adds r1, r0
	lsls r1, 3
	adds r1, r2, r1
	movs r4, 0x9E
	lsls r4, 3
	adds r1, r4
	ldr r0, _0801CC34
	ldm r0!, {r2,r3,r6}
	stm r1!, {r2,r3,r6}
	ldm r0!, {r2,r3,r6}
	stm r1!, {r2,r3,r6}
	bl sub_8004914
	ldr r0, [r5]
	adds r0, r4
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	ldr r0, [r5]
	bl MemoryFree
	movs r0, 0
	str r0, [r5]
_0801CC16:
	pop {r4-r6}
	pop {r0}
	bx r0
	.align 2, 0
_0801CC1C: .4byte gUnknown_203B244
_0801CC20: .4byte gUnknown_203B248
_0801CC24: .4byte gUnknown_203B24C
_0801CC28: .4byte 0x000004cc
_0801CC2C: .4byte gUnknown_203B24E
_0801CC30: .4byte 0x000004d2
_0801CC34: .4byte gUnknown_80DBE3C
	thumb_func_end sub_801CBB8

	thumb_func_start sub_801CC38
sub_801CC38:
	push {r4,r5,lr}
	ldr r4, _0801CCC4
	ldr r0, [r4]
	movs r1, 0xAA
	lsls r1, 3
	adds r0, r1
	movs r2, 0
	movs r1, 0x1
	strb r1, [r0]
	ldr r0, [r4]
	ldr r1, _0801CCC8
	adds r0, r1
	strb r2, [r0]
	ldr r0, [r4]
	adds r1, 0x1
	adds r0, r1
	movs r1, 0xC
	strb r1, [r0]
	ldr r0, [r4]
	ldr r1, _0801CCCC
	adds r0, r1
	strb r2, [r0]
	ldr r0, [r4]
	ldr r2, _0801CCD0
	adds r0, r2
	movs r1, 0
	ldrsh r0, [r0, r1]
	movs r1, 0xC
	bl sub_80095E4
	adds r0, 0x2
	lsls r0, 16
	ldr r3, [r4]
	movs r2, 0x9D
	lsls r2, 3
	adds r5, r3, r2
	ldr r2, [r5]
	lsls r1, r2, 1
	adds r1, r2
	lsls r1, 3
	adds r1, r3, r1
	ldr r2, _0801CCD4
	adds r1, r2
	asrs r2, r0, 16
	lsrs r0, 16
	strh r0, [r1]
	ldr r1, [r5]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 3
	adds r3, r0
	adds r2, 0x2
	movs r0, 0xA0
	lsls r0, 3
	adds r3, r0
	strh r2, [r3]
	bl sub_8004914
	ldr r0, [r4]
	movs r1, 0x9E
	lsls r1, 3
	adds r0, r1
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_0801CCC4: .4byte gUnknown_203B244
_0801CCC8: .4byte 0x00000551
_0801CCCC: .4byte 0x00000553
_0801CCD0: .4byte 0x000004ce
_0801CCD4: .4byte 0x000004fe
	thumb_func_end sub_801CC38

	thumb_func_start sub_801CCD8
sub_801CCD8:
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	sub sp, 0x58
	ldr r4, _0801CE38
	ldr r0, [r4]
	movs r5, 0x9D
	lsls r5, 3
	adds r0, r5
	ldr r0, [r0]
	bl sub_8008C54
	ldr r0, [r4]
	adds r0, r5
	ldr r0, [r0]
	bl sub_80073B8
	ldr r2, _0801CE3C
	ldr r0, [r4]
	adds r0, r5
	ldr r3, [r0]
	movs r0, 0
	str r0, [sp]
	movs r0, 0xA
	movs r1, 0
	bl xxx_call_draw_string
	ldr r3, [r4]
	ldr r1, _0801CE40
	adds r0, r3, r1
	ldrb r0, [r0]
	lsls r0, 3
	adds r0, 0x4
	ldr r2, _0801CE44
	adds r1, r3, r2
	movs r6, 0
	ldrsh r2, [r1, r6]
	adds r2, 0x1
	movs r1, 0x7
	str r1, [sp]
	adds r3, r5
	ldr r1, [r3]
	str r1, [sp, 0x4]
	movs r1, 0
	movs r3, 0x2
	bl sub_8012BC4
	movs r7, 0
	ldr r0, [r4]
	ldr r1, _0801CE48
	adds r0, r1
	movs r2, 0
	ldrsh r0, [r0, r2]
	cmp r7, r0
	bge _0801CE1A
	adds r6, r4, 0
	ldr r3, _0801CE4C
	mov r9, r3
	mov r8, r5
_0801CD50:
	ldr r1, [r6]
	ldr r4, _0801CE44
	adds r0, r1, r4
	movs r3, 0
	ldrsh r2, [r0, r3]
	subs r4, 0x2
	adds r0, r1, r4
	movs r3, 0
	ldrsh r0, [r0, r3]
	muls r0, r2
	adds r0, r7
	adds r1, 0x4
	adds r1, r0
	ldrb r5, [r1]
	add r0, sp, 0x8
	adds r1, r5, 0
	movs r2, 0
	bl sub_8090DC4
	ldr r0, [r6]
	add r0, r9
	adds r1, r7, 0
	bl sub_8013800
	adds r1, r0, 0
	ldr r0, [r6]
	add r0, r8
	ldr r3, [r0]
	movs r0, 0
	str r0, [sp]
	movs r0, 0x8
	add r2, sp, 0x8
	bl xxx_call_draw_string
	ldr r0, [r6]
	add r0, r9
	adds r1, r7, 0
	bl sub_8013800
	adds r1, r0, 0
	ldr r4, [r6]
	ldr r2, _0801CE50
	adds r0, r4, r2
	ldr r0, [r0]
	movs r3, 0xC
	ldrsh r0, [r0, r3]
	lsls r0, 3
	subs r0, 0x2
	ldr r2, _0801CE54
	ldr r2, [r2]
	lsls r3, r5, 1
	adds r2, 0x50
	adds r2, r3
	ldrh r2, [r2]
	movs r3, 0x5
	str r3, [sp]
	add r4, r8
	ldr r3, [r4]
	str r3, [sp, 0x4]
	movs r3, 0x3
	bl sub_8012BC4
	adds r0, r5, 0
	bl sub_801CFE0
	movs r1, 0x1
	ands r1, r0
	cmp r1, 0
	beq _0801CE0A
	ldr r0, [r6]
	ldr r4, _0801CE4C
	adds r0, r4
	adds r1, r7, 0
	bl sub_8013800
	adds r2, r0, 0
	ldr r1, [r6]
	movs r3, 0x9D
	lsls r3, 3
	adds r0, r1, r3
	ldr r0, [r0]
	adds r4, 0x38
	adds r1, r4
	ldr r1, [r1]
	movs r4, 0xC
	ldrsh r3, [r1, r4]
	subs r3, 0x1
	lsls r3, 3
	movs r1, 0xA
	str r1, [sp]
	movs r1, 0x8
	bl sub_8007B7C
_0801CE0A:
	adds r7, 0x1
	ldr r0, [r6]
	ldr r1, _0801CE48
	adds r0, r1
	movs r2, 0
	ldrsh r0, [r0, r2]
	cmp r7, r0
	blt _0801CD50
_0801CE1A:
	ldr r0, _0801CE38
	ldr r0, [r0]
	movs r3, 0x9D
	lsls r3, 3
	adds r0, r3
	ldr r0, [r0]
	bl sub_80073E0
	add sp, 0x58
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_0801CE38: .4byte gUnknown_203B244
_0801CE3C: .4byte gUnknown_80DBE6C
_0801CE40: .4byte 0x00000552
_0801CE44: .4byte 0x000004d2
_0801CE48: .4byte 0x000004ce
_0801CE4C: .4byte 0x000004b4
_0801CE50: .4byte 0x000004ec
_0801CE54: .4byte gUnknown_203B460
	thumb_func_end sub_801CCD8

	thumb_func_start sub_801CE58
sub_801CE58:
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	sub sp, 0x4
	movs r3, 0
	movs r6, 0x1
	ldr r4, _0801CF0C
_0801CE68:
	ldr r0, [r4]
	ldr r0, [r0]
	cmp r0, 0x2
	beq _0801CE92
	ldr r0, _0801CF10
	ldr r0, [r0]
	lsls r1, r6, 1
	adds r0, 0x50
	adds r0, r1
	ldrh r0, [r0]
	cmp r0, 0
	beq _0801CE9C
	lsls r0, r6, 24
	lsrs r0, 24
	str r3, [sp]
	bl sub_8091524
	lsls r0, 24
	ldr r3, [sp]
	cmp r0, 0
	beq _0801CE9C
_0801CE92:
	ldr r0, [r4]
	adds r0, 0x4
	adds r0, r3
	strb r6, [r0]
	adds r3, 0x1
_0801CE9C:
	adds r6, 0x1
	cmp r6, 0xEF
	ble _0801CE68
	movs r6, 0
	subs r0, r3, 0x1
	mov r9, r0
	cmp r6, r9
	bge _0801CEFC
_0801CEAC:
	adds r0, r6, 0x1
	mov r8, r0
	mov r5, r8
	cmp r8, r3
	bge _0801CEF6
	ldr r7, _0801CF0C
_0801CEB8:
	ldr r0, [r7]
	adds r0, 0x4
	adds r0, r6
	ldrb r0, [r0]
	str r3, [sp]
	bl sub_8090D44
	adds r4, r0, 0
	ldr r0, [r7]
	adds r0, 0x4
	adds r0, r5
	ldrb r0, [r0]
	bl sub_8090D44
	ldr r3, [sp]
	cmp r4, r0
	ble _0801CEF0
	ldr r0, [r7]
	adds r0, 0x4
	adds r1, r0, r6
	ldrb r2, [r1]
	adds r0, r5
	ldrb r0, [r0]
	strb r0, [r1]
	ldr r0, [r7]
	adds r0, 0x4
	adds r0, r5
	strb r2, [r0]
_0801CEF0:
	adds r5, 0x1
	cmp r5, r3
	blt _0801CEB8
_0801CEF6:
	mov r6, r8
	cmp r6, r9
	blt _0801CEAC
_0801CEFC:
	adds r0, r3, 0
	add sp, 0x4
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r1}
	bx r1
	.align 2, 0
_0801CF0C: .4byte gUnknown_203B244
_0801CF10: .4byte gUnknown_203B460
	thumb_func_end sub_801CE58

	thumb_func_start sub_801CF14
sub_801CF14:
	push {r4,lr}
	cmp r0, 0x2
	bne _0801CF1E
_0801CF1A:
	movs r0, 0
	b _0801CF46
_0801CF1E:
	movs r4, 0x1
_0801CF20:
	ldr r0, _0801CF4C
	ldr r0, [r0]
	lsls r1, r4, 1
	adds r0, 0x50
	adds r0, r1
	ldrh r0, [r0]
	cmp r0, 0
	beq _0801CF3E
	lsls r0, r4, 24
	lsrs r0, 24
	bl sub_8091524
	lsls r0, 24
	cmp r0, 0
	bne _0801CF1A
_0801CF3E:
	adds r4, 0x1
	cmp r4, 0xEF
	ble _0801CF20
	movs r0, 0x1
_0801CF46:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_0801CF4C: .4byte gUnknown_203B460
	thumb_func_end sub_801CF14

	thumb_func_start sub_801CF50
sub_801CF50:
	push {r4,r5,lr}
	cmp r0, 0x2
	bne _0801CF5A
_0801CF56:
	movs r0, 0
	b _0801CF84
_0801CF5A:
	movs r4, 0x1
	ldr r5, _0801CF8C
_0801CF5E:
	lsls r0, r4, 24
	lsrs r0, 24
	bl sub_8091524
	lsls r0, 24
	cmp r0, 0
	beq _0801CF7C
	ldr r0, _0801CF90
	ldr r0, [r0]
	lsls r1, r4, 1
	adds r0, 0x50
	adds r0, r1
	ldrh r0, [r0]
	cmp r0, r5
	bls _0801CF56
_0801CF7C:
	adds r4, 0x1
	cmp r4, 0xEF
	ble _0801CF5E
	movs r0, 0x1
_0801CF84:
	pop {r4,r5}
	pop {r1}
	bx r1
	.align 2, 0
_0801CF8C: .4byte 0x000003e6
_0801CF90: .4byte gUnknown_203B460
	thumb_func_end sub_801CF50

	thumb_func_start sub_801CF94
sub_801CF94:
	push {r4,lr}
	movs r2, 0
	ldr r4, _0801CFB4
	movs r3, 0
_0801CF9C:
	ldr r0, [r4]
	lsls r1, r2, 2
	adds r0, 0xF4
	adds r0, r1
	str r3, [r0]
	adds r2, 0x1
	cmp r2, 0xEF
	ble _0801CF9C
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0801CFB4: .4byte gUnknown_203B244
	thumb_func_end sub_801CF94

	thumb_func_start sub_801CFB8
sub_801CFB8:
	push {lr}
	movs r3, 0
	ldr r0, _0801CFDC
	ldr r0, [r0]
	adds r1, r0, 0
	adds r1, 0xF4
	movs r2, 0xEF
_0801CFC6:
	ldr r0, [r1]
	cmp r0, 0
	beq _0801CFCE
	adds r3, 0x1
_0801CFCE:
	adds r1, 0x4
	subs r2, 0x1
	cmp r2, 0
	bge _0801CFC6
	adds r0, r3, 0
	pop {r1}
	bx r1
	.align 2, 0
_0801CFDC: .4byte gUnknown_203B244
	thumb_func_end sub_801CFB8

	thumb_func_start sub_801CFE0
sub_801CFE0:
	lsls r0, 24
	ldr r1, _0801CFF0
	ldr r1, [r1]
	lsrs r0, 22
	adds r1, 0xF4
	adds r1, r0
	ldr r0, [r1]
	bx lr
	.align 2, 0
_0801CFF0: .4byte gUnknown_203B244
	thumb_func_end sub_801CFE0

	thumb_func_start sub_801CFF4
sub_801CFF4:
	lsls r0, 24
	ldr r2, _0801D004
	ldr r2, [r2]
	lsrs r0, 22
	adds r2, 0xF4
	adds r2, r0
	str r1, [r2]
	bx lr
	.align 2, 0
_0801D004: .4byte gUnknown_203B244
	thumb_func_end sub_801CFF4

	thumb_func_start sub_801D008
sub_801D008:
	ldr r0, _0801D010
	ldr r0, [r0]
	bx lr
	.align 2, 0
_0801D010: .4byte gUnknown_203B244
	thumb_func_end sub_801D008

	thumb_func_start sub_801D014
sub_801D014:
	push {r4,r5,lr}
	adds r5, r0, 0
	bl sub_8004914
	movs r0, 0
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	ldr r4, _0801D054
	movs r0, 0x8C
	lsls r0, 1
	movs r1, 0x8
	bl MemoryAlloc
	adds r2, r0, 0
	str r2, [r4]
	ldr r0, _0801D058
	ldr r0, [r0]
	str r0, [r2, 0x14]
	str r5, [r2]
	cmp r5, 0
	beq _0801D088
	movs r3, 0
	ldr r0, _0801D05C
	ldr r1, [r0]
	adds r4, r0, 0
	cmp r5, r1
	bne _0801D060
	strh r3, [r2, 0x4]
	b _0801D08C
	.align 2, 0
_0801D054: .4byte gUnknown_203B250
_0801D058: .4byte gUnknown_203B254
_0801D05C: .4byte gUnknown_203B45C
_0801D060:
	adds r3, 0x1
	movs r0, 0xCE
	lsls r0, 1
	cmp r3, r0
	bgt _0801D08C
	ldr r0, _0801D084
	ldr r2, [r0]
	lsls r0, r3, 16
	asrs r0, 16
	movs r1, 0x58
	muls r1, r0
	ldr r0, [r4]
	adds r0, r1
	ldr r1, [r2]
	cmp r1, r0
	bne _0801D060
	strh r3, [r2, 0x4]
	b _0801D08C
	.align 2, 0
_0801D084: .4byte gUnknown_203B250
_0801D088:
	ldr r0, _0801D0C4
	strh r0, [r2, 0x4]
_0801D08C:
	bl sub_80A5728
	lsls r0, 16
	asrs r0, 16
	bl sub_8002658
	ldr r4, _0801D0C8
	ldr r1, [r4]
	movs r5, 0
	strb r0, [r1, 0x6]
	ldr r0, [r4]
	strb r5, [r0, 0x8]
	ldr r0, [r4]
	strb r5, [r0, 0x9]
	bl sub_808D33C
	ldr r1, [r4]
	str r0, [r1, 0xC]
	strb r5, [r1, 0x7]
	ldr r0, [r4]
	ldr r0, [r0]
	cmp r0, 0
	beq _0801D0CC
	movs r0, 0x5
	bl sub_801D208
	b _0801D0D2
	.align 2, 0
_0801D0C4: .4byte 0x0000019d
_0801D0C8: .4byte gUnknown_203B250
_0801D0CC:
	movs r0, 0
	bl sub_801D208
_0801D0D2:
	movs r0, 0x1
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_801D014

	thumb_func_start sub_801D0DC
sub_801D0DC:
	push {lr}
	ldr r0, _0801D0F4
	ldr r0, [r0]
	ldr r0, [r0, 0x10]
	cmp r0, 0xC
	bhi _0801D16C
	lsls r0, 2
	ldr r1, _0801D0F8
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0801D0F4: .4byte gUnknown_203B250
_0801D0F8: .4byte _0801D0FC
	.align 2, 0
_0801D0FC:
	.4byte _0801D130
	.4byte _0801D130
	.4byte _0801D16C
	.4byte _0801D136
	.4byte _0801D13C
	.4byte _0801D142
	.4byte _0801D148
	.4byte _0801D148
	.4byte _0801D14E
	.4byte _0801D154
	.4byte _0801D15A
	.4byte _0801D160
	.4byte _0801D166
_0801D130:
	bl sub_801D680
	b _0801D170
_0801D136:
	bl sub_801D760
	b _0801D170
_0801D13C:
	bl sub_801D77C
	b _0801D170
_0801D142:
	bl sub_801D798
	b _0801D170
_0801D148:
	bl sub_801D7CC
	b _0801D170
_0801D14E:
	bl sub_801D808
	b _0801D170
_0801D154:
	bl sub_801D824
	b _0801D170
_0801D15A:
	bl sub_801D840
	b _0801D170
_0801D160:
	bl sub_801D85C
	b _0801D170
_0801D166:
	bl sub_801D878
	b _0801D170
_0801D16C:
	movs r0, 0x3
	b _0801D172
_0801D170:
	movs r0, 0
_0801D172:
	pop {r1}
	bx r1
	thumb_func_end sub_801D0DC

	thumb_func_start sub_801D178
sub_801D178:
	push {r4,lr}
	ldr r0, _0801D188
	ldr r4, [r0]
	ldrb r0, [r4, 0x9]
	cmp r0, 0
	beq _0801D18C
	movs r0, 0x2
	b _0801D1CC
	.align 2, 0
_0801D188: .4byte gUnknown_203B250
_0801D18C:
	ldrb r0, [r4, 0x7]
	cmp r0, 0
	beq _0801D196
	movs r0, 0x3
	b _0801D1CC
_0801D196:
	ldrb r0, [r4, 0x8]
	cmp r0, 0
	beq _0801D1A0
	movs r0, 0x1
	b _0801D1CC
_0801D1A0:
	bl sub_808D33C
	ldr r1, [r4, 0xC]
	cmp r1, r0
	bne _0801D1C6
	movs r0, 0x7
	bl sub_80A7AE8
	lsls r0, 16
	cmp r0, 0
	blt _0801D1CA
	bl sub_808D3F8
	ldrh r0, [r0]
	lsrs r0, 1
	movs r1, 0x1
	ands r0, r1
	cmp r0, 0
	bne _0801D1CA
_0801D1C6:
	movs r0, 0x4
	b _0801D1CC
_0801D1CA:
	movs r0, 0
_0801D1CC:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_801D178

	thumb_func_start sub_801D1D4
sub_801D1D4:
	ldr r0, _0801D1DC
	ldr r0, [r0]
	ldrb r0, [r0, 0x7]
	bx lr
	.align 2, 0
_0801D1DC: .4byte gUnknown_203B250
	thumb_func_end sub_801D1D4

	thumb_func_start sub_801D1E0
sub_801D1E0:
	push {r4,lr}
	ldr r4, _0801D200
	ldr r2, [r4]
	cmp r2, 0
	beq _0801D1FA
	ldr r0, _0801D204
	ldr r1, [r2, 0x14]
	str r1, [r0]
	adds r0, r2, 0
	bl MemoryFree
	movs r0, 0
	str r0, [r4]
_0801D1FA:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0801D200: .4byte gUnknown_203B250
_0801D204: .4byte gUnknown_203B254
	thumb_func_end sub_801D1E0

	thumb_func_start sub_801D208
sub_801D208:
	push {lr}
	ldr r1, _0801D21C
	ldr r1, [r1]
	str r0, [r1, 0x10]
	bl sub_801D220
	bl sub_801D3A8
	pop {r0}
	bx r0
	.align 2, 0
_0801D21C: .4byte gUnknown_203B250
	thumb_func_end sub_801D208

	thumb_func_start sub_801D220
sub_801D220:
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	ldr r4, _0801D248
	ldr r0, [r4]
	adds r0, 0xB8
	bl sub_8006518
	ldr r0, [r4]
	ldr r0, [r0, 0x10]
	cmp r0, 0
	beq _0801D250
	cmp r0, 0x1
	beq _0801D2C0
	movs r2, 0
	adds r7, r4, 0
	ldr r3, _0801D24C
	b _0801D368
	.align 2, 0
_0801D248: .4byte gUnknown_203B250
_0801D24C: .4byte gUnknown_80DBE7C
_0801D250:
	bl sub_801D4C0
	ldr r0, [r4]
	ldr r0, [r0]
	cmp r0, 0
	beq _0801D290
	adds r7, r4, 0
	ldr r0, _0801D288
	mov r9, r0
	mov r12, r7
	ldr r2, _0801D28C
	mov r8, r2
	movs r3, 0
	movs r2, 0x3
_0801D26C:
	mov r4, r12
	ldr r1, [r4]
	adds r1, r3
	adds r1, 0xB8
	mov r0, r8
	ldm r0!, {r4-r6}
	stm r1!, {r4-r6}
	ldm r0!, {r4-r6}
	stm r1!, {r4-r6}
	adds r3, 0x18
	subs r2, 0x1
	cmp r2, 0
	bge _0801D26C
	b _0801D2F6
	.align 2, 0
_0801D288: .4byte gUnknown_80DBE98
_0801D28C: .4byte gUnknown_80DBE7C
_0801D290:
	adds r7, r4, 0
	mov r8, r7
	ldr r6, _0801D2BC
	mov r9, r6
	movs r3, 0
	movs r2, 0x3
_0801D29C:
	mov r0, r8
	ldr r1, [r0]
	adds r1, r3
	adds r1, 0xB8
	mov r0, r9
	ldm r0!, {r4-r6}
	stm r1!, {r4-r6}
	ldm r0!, {r4-r6}
	stm r1!, {r4-r6}
	movs r0, 0x18
	add r9, r0
	adds r3, 0x18
	subs r2, 0x1
	cmp r2, 0
	bge _0801D29C
	b _0801D34E
	.align 2, 0
_0801D2BC: .4byte gUnknown_80DBEB0
_0801D2C0:
	bl sub_801D4C0
	ldr r0, [r4]
	ldr r0, [r0]
	cmp r0, 0
	beq _0801D324
	adds r7, r4, 0
	ldr r2, _0801D31C
	mov r9, r2
	mov r8, r7
	ldr r3, _0801D320
	mov r12, r3
	movs r3, 0
	movs r2, 0x3
_0801D2DC:
	mov r4, r8
	ldr r1, [r4]
	adds r1, r3
	adds r1, 0xB8
	mov r0, r12
	ldm r0!, {r4-r6}
	stm r1!, {r4-r6}
	ldm r0!, {r4-r6}
	stm r1!, {r4-r6}
	adds r3, 0x18
	subs r2, 0x1
	cmp r2, 0
	bge _0801D2DC
_0801D2F6:
	ldr r1, [r7]
	adds r1, 0xB8
	mov r0, r9
	ldm r0!, {r2,r5,r6}
	stm r1!, {r2,r5,r6}
	ldm r0!, {r3-r5}
	stm r1!, {r3-r5}
	ldr r1, [r7]
	adds r0, r1, 0
	adds r0, 0xB8
	adds r1, 0x68
	bl sub_8012CAC
	ldr r0, [r7]
	adds r0, 0xC4
	movs r1, 0x9
	strh r1, [r0]
	b _0801D384
	.align 2, 0
_0801D31C: .4byte gUnknown_80DBE98
_0801D320: .4byte gUnknown_80DBE7C
_0801D324:
	adds r7, r4, 0
	mov r8, r7
	ldr r6, _0801D364
	mov r9, r6
	movs r3, 0
	movs r2, 0x3
_0801D330:
	mov r0, r8
	ldr r1, [r0]
	adds r1, r3
	adds r1, 0xB8
	mov r0, r9
	ldm r0!, {r4-r6}
	stm r1!, {r4-r6}
	ldm r0!, {r4-r6}
	stm r1!, {r4-r6}
	movs r0, 0x18
	add r9, r0
	adds r3, 0x18
	subs r2, 0x1
	cmp r2, 0
	bge _0801D330
_0801D34E:
	ldr r1, [r7]
	adds r0, r1, 0
	adds r0, 0xB8
	adds r1, 0x68
	bl sub_8012CAC
	ldr r0, [r7]
	adds r0, 0xC4
	movs r1, 0x8
	strh r1, [r0]
	b _0801D384
	.align 2, 0
_0801D364: .4byte gUnknown_80DBEB0
_0801D368:
	ldr r0, [r7]
	lsls r1, r2, 1
	adds r1, r2
	lsls r1, 3
	adds r0, r1
	adds r0, 0xB8
	adds r1, r3, 0
	ldm r1!, {r4-r6}
	stm r0!, {r4-r6}
	ldm r1!, {r4-r6}
	stm r0!, {r4-r6}
	adds r2, 0x1
	cmp r2, 0x3
	ble _0801D368
_0801D384:
	bl sub_8004914
	ldr r0, _0801D3A4
	ldr r0, [r0]
	adds r0, 0xB8
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_0801D3A4: .4byte gUnknown_203B250
	thumb_func_end sub_801D220

	thumb_func_start sub_801D3A8
sub_801D3A8:
	push {r4-r6,lr}
	sub sp, 0x8
	ldr r1, _0801D3C4
	ldr r0, [r1]
	ldr r0, [r0, 0x10]
	adds r6, r1, 0
	cmp r0, 0xC
	bls _0801D3BA
	b _0801D4B6
_0801D3BA:
	lsls r0, 2
	ldr r1, _0801D3C8
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0801D3C4: .4byte gUnknown_203B250
_0801D3C8: .4byte _0801D3CC
	.align 2, 0
_0801D3CC:
	.4byte _0801D400
	.4byte _0801D400
	.4byte _0801D4B6
	.4byte _0801D458
	.4byte _0801D462
	.4byte _0801D468
	.4byte _0801D472
	.4byte _0801D47A
	.4byte _0801D482
	.4byte _0801D490
	.4byte _0801D49C
	.4byte _0801D4AA
	.4byte _0801D4B2
_0801D400:
	ldr r0, [r6]
	ldr r5, [r0]
	cmp r5, 0
	beq _0801D438
	ldr r4, _0801D434
	adds r0, r4, 0
	adds r1, r5, 0
	movs r2, 0x7
	bl sub_808D9AC
	ldr r2, [r6]
	str r4, [r2, 0x18]
	adds r0, r2, 0
	adds r0, 0x18
	adds r1, r2, 0
	adds r1, 0x68
	adds r3, r2, 0
	adds r3, 0xA8
	ldr r2, [r2, 0x14]
	str r2, [sp]
	movs r2, 0
	str r2, [sp, 0x4]
	bl sub_8012D60
	b _0801D4B6
	.align 2, 0
_0801D434: .4byte gUnknown_202DF98
_0801D438:
	bl sub_801D894
	ldr r2, [r6]
	adds r0, r2, 0
	adds r0, 0x18
	adds r1, r2, 0
	adds r1, 0x68
	adds r3, r2, 0
	adds r3, 0xA8
	ldr r2, [r2, 0x14]
	str r2, [sp]
	str r5, [sp, 0x4]
	movs r2, 0
	bl sub_8012D60
	b _0801D4B6
_0801D458:
	ldr r0, [r6]
	ldr r0, [r0]
	bl sub_80227B8
	b _0801D4B6
_0801D462:
	bl sub_8027074
	b _0801D4B6
_0801D468:
	ldr r0, [r6]
	ldr r0, [r0]
	bl sub_8025EF4
	b _0801D4B6
_0801D472:
	movs r0, 0
	bl sub_80252F0
	b _0801D4B6
_0801D47A:
	movs r0, 0x1
	bl sub_80252F0
	b _0801D4B6
_0801D482:
	ldr r0, [r6]
	movs r1, 0x4
	ldrsh r0, [r0, r1]
	movs r1, 0x2
	bl sub_8024458
	b _0801D4B6
_0801D490:
	ldr r0, [r6]
	movs r1, 0x4
	ldrsh r0, [r0, r1]
	bl sub_801BEEC
	b _0801D4B6
_0801D49C:
	ldr r0, [r6]
	ldrb r0, [r0, 0x6]
	movs r1, 0x1
	movs r2, 0x2
	bl sub_8021774
	b _0801D4B6
_0801D4AA:
	movs r0, 0
	bl sub_802C860
	b _0801D4B6
_0801D4B2:
	bl sub_801DCC4
_0801D4B6:
	add sp, 0x8
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end sub_801D3A8

	thumb_func_start sub_801D4C0
sub_801D4C0:
	push {r4-r7,lr}
	movs r6, 0
	ldr r4, _0801D554
	ldr r0, [r4]
	adds r0, 0xA8
	movs r1, 0
	movs r2, 0x10
	bl MemoryFill16
	ldr r0, [r4]
	ldrb r0, [r0, 0x6]
	cmp r0, 0
	bne _0801D568
	bl sub_8096E2C
	lsls r0, 24
	cmp r0, 0
	beq _0801D534
	ldr r1, [r4]
	movs r0, 0x2
	str r0, [r1, 0x6C]
	ldr r0, _0801D558
	str r0, [r1, 0x68]
	bl sub_8090A34
	cmp r0, 0
	bne _0801D4FE
	ldr r0, [r4]
	adds r0, 0xA8
	movs r1, 0x1
	strh r1, [r0]
_0801D4FE:
	ldr r1, [r4]
	ldr r0, _0801D55C
	str r0, [r1, 0x70]
	movs r0, 0x4
	str r0, [r1, 0x74]
	movs r6, 0x2
	movs r0, 0x2
	bl sub_80023E4
	lsls r0, 24
	cmp r0, 0
	beq _0801D534
	ldr r1, [r4]
	ldr r0, _0801D560
	str r0, [r1, 0x78]
	movs r0, 0x9
	str r0, [r1, 0x7C]
	bl sub_802C83C
	lsls r0, 24
	cmp r0, 0
	beq _0801D532
	ldr r0, [r4]
	adds r0, 0xAC
	movs r1, 0x1
	strh r1, [r0]
_0801D532:
	movs r6, 0x3
_0801D534:
	ldr r4, _0801D554
	ldr r2, [r4]
	lsls r3, r6, 3
	adds r0, r2, 0
	adds r0, 0x68
	adds r0, r3
	ldr r1, _0801D564
	str r1, [r0]
	adds r2, 0x6C
	adds r2, r3
	movs r0, 0xB
	str r0, [r2]
	adds r6, 0x1
	adds r7, r4, 0
	b _0801D5E6
	.align 2, 0
_0801D554: .4byte gUnknown_203B250
_0801D558: .4byte gUnknown_80DBF10
_0801D55C: .4byte gUnknown_80DBF18
_0801D560: .4byte gUnknown_80DBF20
_0801D564: .4byte gUnknown_80DBF2C
_0801D568:
	ldr r0, _0801D63C
	ldr r1, _0801D640
	bl strcpy
	bl sub_8096E2C
	lsls r0, 24
	cmp r0, 0
	beq _0801D5B6
	ldr r1, [r4]
	ldr r0, _0801D644
	ldr r0, [r0]
	str r0, [r1, 0x68]
	movs r0, 0x5
	str r0, [r1, 0x6C]
	movs r0, 0x4
	bl sub_8024108
	lsls r0, 24
	cmp r0, 0
	beq _0801D59A
	ldr r0, [r4]
	adds r0, 0xA8
	movs r1, 0x1
	strh r1, [r0]
_0801D59A:
	movs r6, 0x1
	ldr r1, [r4]
	movs r0, 0x2
	str r0, [r1, 0x74]
	ldr r0, _0801D648
	str r0, [r1, 0x70]
	bl sub_8090A34
	cmp r0, 0
	bne _0801D5B4
	ldr r0, [r4]
	adds r0, 0xAA
	strh r6, [r0]
_0801D5B4:
	movs r6, 0x2
_0801D5B6:
	ldr r5, _0801D64C
	ldr r1, [r5]
	lsls r2, r6, 3
	adds r3, r1, 0
	adds r3, 0x68
	adds r4, r3, r2
	ldr r0, _0801D650
	ldr r0, [r0]
	str r0, [r4]
	adds r1, 0x6C
	adds r2, r1, r2
	movs r0, 0x8
	str r0, [r2]
	adds r6, 0x1
	lsls r2, r6, 3
	adds r3, r2
	ldr r0, _0801D654
	ldr r0, [r0]
	str r0, [r3]
	adds r1, r2
	movs r0, 0xA
	str r0, [r1]
	adds r6, 0x1
	adds r7, r5, 0
_0801D5E6:
	ldr r4, [r7]
	lsls r2, r6, 3
	adds r0, r4, 0
	adds r0, 0x68
	adds r0, r2
	movs r1, 0
	str r1, [r0]
	adds r1, r4, 0
	adds r1, 0x6C
	adds r2, r1, r2
	movs r0, 0x1
	str r0, [r2]
	movs r3, 0
	cmp r3, r6
	bge _0801D622
	adds r5, r4, 0
	adds r4, 0xA8
	adds r2, r1, 0
_0801D60A:
	ldrh r0, [r4]
	cmp r0, 0
	bne _0801D618
	ldr r1, [r2]
	ldr r0, [r5, 0x14]
	cmp r1, r0
	beq _0801D67A
_0801D618:
	adds r4, 0x2
	adds r2, 0x8
	adds r3, 0x1
	cmp r3, r6
	blt _0801D60A
_0801D622:
	movs r3, 0
	cmp r3, r6
	bge _0801D67A
	ldr r1, [r7]
	adds r0, r1, 0
	adds r0, 0xA8
	ldrh r0, [r0]
	cmp r0, 0
	bne _0801D658
	ldr r0, [r1, 0x6C]
	str r0, [r1, 0x14]
	b _0801D67A
	.align 2, 0
_0801D63C: .4byte gUnknown_202DF98
_0801D640: .4byte gUnknown_80DBF34
_0801D644: .4byte gUnknown_80D49A8
_0801D648: .4byte gUnknown_80DBF10
_0801D64C: .4byte gUnknown_203B250
_0801D650: .4byte gUnknown_80D4970
_0801D654: .4byte gUnknown_80D49B4
_0801D658:
	adds r3, 0x1
	cmp r3, r6
	bge _0801D67A
	ldr r2, [r7]
	lsls r0, r3, 1
	adds r1, r2, 0
	adds r1, 0xA8
	adds r1, r0
	ldrh r0, [r1]
	cmp r0, 0
	bne _0801D658
	lsls r0, r3, 3
	adds r1, r2, 0
	adds r1, 0x6C
	adds r1, r0
	ldr r0, [r1]
	str r0, [r2, 0x14]
_0801D67A:
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_801D4C0

	thumb_func_start sub_801D680
sub_801D680:
	push {r4,lr}
	sub sp, 0x4
	movs r0, 0
	str r0, [sp]
	ldr r4, _0801D6C0
	ldr r0, [r4]
	adds r0, 0x18
	bl sub_8012FD8
	lsls r0, 24
	cmp r0, 0
	bne _0801D6AC
	ldr r0, [r4]
	adds r0, 0x18
	mov r1, sp
	bl sub_8013114
	ldr r1, [sp]
	cmp r1, 0x1
	beq _0801D6AC
	ldr r0, [r4]
	str r1, [r0, 0x14]
_0801D6AC:
	ldr r0, [sp]
	subs r0, 0x1
	cmp r0, 0xA
	bhi _0801D756
	lsls r0, 2
	ldr r1, _0801D6C4
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0801D6C0: .4byte gUnknown_203B250
_0801D6C4: .4byte _0801D6C8
	.align 2, 0
_0801D6C8:
	.4byte _0801D750
	.4byte _0801D6F4
	.4byte _0801D704
	.4byte _0801D6FC
	.4byte _0801D70C
	.4byte _0801D714
	.4byte _0801D71C
	.4byte _0801D724
	.4byte _0801D72C
	.4byte _0801D734
	.4byte _0801D748
_0801D6F4:
	movs r0, 0x3
	bl sub_801D208
	b _0801D756
_0801D6FC:
	movs r0, 0x6
	bl sub_801D208
	b _0801D756
_0801D704:
	movs r0, 0x4
	bl sub_801D208
	b _0801D756
_0801D70C:
	movs r0, 0x7
	bl sub_801D208
	b _0801D756
_0801D714:
	movs r0, 0x8
	bl sub_801D208
	b _0801D756
_0801D71C:
	movs r0, 0x9
	bl sub_801D208
	b _0801D756
_0801D724:
	movs r0, 0xA
	bl sub_801D208
	b _0801D756
_0801D72C:
	movs r0, 0xB
	bl sub_801D208
	b _0801D756
_0801D734:
	ldr r0, _0801D744
	ldr r1, [r0]
	movs r0, 0x1
	strb r0, [r1, 0x9]
	movs r0, 0x2
	bl sub_801D208
	b _0801D756
	.align 2, 0
_0801D744: .4byte gUnknown_203B250
_0801D748:
	movs r0, 0xC
	bl sub_801D208
	b _0801D756
_0801D750:
	movs r0, 0x2
	bl sub_801D208
_0801D756:
	add sp, 0x4
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_801D680

	thumb_func_start sub_801D760
sub_801D760:
	push {lr}
	bl sub_8022860
	cmp r0, 0x1
	bls _0801D778
	cmp r0, 0x3
	bhi _0801D778
	bl sub_8022908
	movs r0, 0x1
	bl sub_801D208
_0801D778:
	pop {r0}
	bx r0
	thumb_func_end sub_801D760

	thumb_func_start sub_801D77C
sub_801D77C:
	push {lr}
	bl sub_80270A4
	cmp r0, 0x1
	bls _0801D794
	cmp r0, 0x3
	bhi _0801D794
	bl sub_8027168
	movs r0, 0x1
	bl sub_801D208
_0801D794:
	pop {r0}
	bx r0
	thumb_func_end sub_801D77C

	thumb_func_start sub_801D798
sub_801D798:
	push {lr}
	bl sub_8025F68
	cmp r0, 0x1
	bls _0801D7C2
	cmp r0, 0x3
	bhi _0801D7C2
	bl sub_802604C
	lsls r0, 24
	cmp r0, 0
	beq _0801D7B8
	ldr r0, _0801D7C8
	ldr r1, [r0]
	ldrb r0, [r1, 0x6]
	strb r0, [r1, 0x7]
_0801D7B8:
	bl sub_8026058
	movs r0, 0x2
	bl sub_801D208
_0801D7C2:
	pop {r0}
	bx r0
	.align 2, 0
_0801D7C8: .4byte gUnknown_203B250
	thumb_func_end sub_801D798

	thumb_func_start sub_801D7CC
sub_801D7CC:
	push {r4,lr}
	bl sub_8025354
	cmp r0, 0x1
	bls _0801D802
	cmp r0, 0x3
	bhi _0801D802
	bl sub_802540C
	ldr r4, _0801D7F8
	ldr r1, [r4]
	strb r0, [r1, 0x7]
	bl sub_8025418
	ldr r0, [r4]
	ldrb r0, [r0, 0x7]
	cmp r0, 0
	beq _0801D7FC
	movs r0, 0x2
	bl sub_801D208
	b _0801D802
	.align 2, 0
_0801D7F8: .4byte gUnknown_203B250
_0801D7FC:
	movs r0, 0x1
	bl sub_801D208
_0801D802:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_801D7CC

	thumb_func_start sub_801D808
sub_801D808:
	push {lr}
	bl sub_80244E4
	cmp r0, 0x1
	bls _0801D820
	cmp r0, 0x3
	bhi _0801D820
	bl sub_802453C
	movs r0, 0x1
	bl sub_801D208
_0801D820:
	pop {r0}
	bx r0
	thumb_func_end sub_801D808

	thumb_func_start sub_801D824
sub_801D824:
	push {lr}
	bl sub_801BF48
	cmp r0, 0x1
	bls _0801D83C
	cmp r0, 0x3
	bhi _0801D83C
	bl sub_801BF98
	movs r0, 0x1
	bl sub_801D208
_0801D83C:
	pop {r0}
	bx r0
	thumb_func_end sub_801D824

	thumb_func_start sub_801D840
sub_801D840:
	push {lr}
	bl sub_80217EC
	cmp r0, 0x1
	bls _0801D858
	cmp r0, 0x3
	bhi _0801D858
	bl sub_8021830
	movs r0, 0x1
	bl sub_801D208
_0801D858:
	pop {r0}
	bx r0
	thumb_func_end sub_801D840

	thumb_func_start sub_801D85C
sub_801D85C:
	push {lr}
	bl sub_802C898
	cmp r0, 0x1
	bls _0801D874
	cmp r0, 0x3
	bhi _0801D874
	bl sub_802C8F4
	movs r0, 0x1
	bl sub_801D208
_0801D874:
	pop {r0}
	bx r0
	thumb_func_end sub_801D85C

	thumb_func_start sub_801D878
sub_801D878:
	push {lr}
	bl sub_801DCE8
	cmp r0, 0x1
	bls _0801D890
	cmp r0, 0x3
	bhi _0801D890
	bl sub_801DD50
	movs r0, 0x1
	bl sub_801D208
_0801D890:
	pop {r0}
	bx r0
	thumb_func_end sub_801D878

	thumb_func_start sub_801D894
sub_801D894:
	push {r4-r6,lr}
	sub sp, 0x68
	ldr r0, _0801D8A8
	ldr r1, [r0]
	ldrb r0, [r1, 0x6]
	cmp r0, 0
	bne _0801D8AC
	bl sub_8098FB4
	b _0801D8B2
	.align 2, 0
_0801D8A8: .4byte gUnknown_203B250
_0801D8AC:
	ldrb r0, [r1, 0x6]
	bl sub_8092524
_0801D8B2:
	add r2, sp, 0x68
	add r1, sp, 0x4
	movs r3, 0
	bl xxx_format_string
	add r0, sp, 0x4
	bl sub_8008ED0
	movs r4, 0x80
	subs r4, r0
	lsrs r0, r4, 31
	adds r4, r0
	asrs r4, 1
	movs r0, 0x1
	bl sub_8008C54
	movs r0, 0x1
	bl sub_80073B8
	movs r6, 0
	str r6, [sp]
	adds r0, r4, 0
	movs r1, 0x4
	add r2, sp, 0x4
	movs r3, 0x1
	bl xxx_call_draw_string
	movs r0, 0x1
	bl sub_80073E0
	movs r0, 0x2
	bl sub_8008C54
	movs r0, 0x2
	bl sub_80073B8
	movs r0, 0x2
	movs r1, 0x8
	movs r2, 0x6
	bl sub_801D970
	ldr r5, _0801D964
	bl sub_8092178
	lsls r0, 24
	lsrs r0, 24
	bl sub_80921A8
	adds r4, r0, 0
	bl sub_8092110
	adds r3, r0, 0
	add r0, sp, 0x4
	adds r1, r5, 0
	adds r2, r4, 0
	bl sub_800D158
	str r6, [sp]
	movs r0, 0x20
	movs r1, 0x4
	add r2, sp, 0x4
	movs r3, 0x2
	bl xxx_call_draw_string
	ldr r1, _0801D968
	ldr r0, _0801D96C
	ldr r0, [r0]
	movs r2, 0x98
	lsls r2, 2
	adds r0, r2
	ldr r2, [r0]
	add r0, sp, 0x4
	bl sub_800D158
	str r6, [sp]
	movs r0, 0x20
	movs r1, 0x12
	add r2, sp, 0x4
	movs r3, 0x2
	bl xxx_call_draw_string
	movs r0, 0x2
	bl sub_80073E0
	add sp, 0x68
	pop {r4-r6}
	pop {r0}
	bx r0
	.align 2, 0
_0801D964: .4byte gUnknown_80DBF3C
_0801D968: .4byte gUnknown_80DBF4C
_0801D96C: .4byte gUnknown_203B460
	thumb_func_end sub_801D894

	thumb_func_start sub_801D970
sub_801D970:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0xC
	mov r8, r0
	mov r9, r1
	mov r10, r2
	ldr r0, _0801D9DC
	ldr r1, _0801D9E0
	bl OpenFileAndGetFileDataPtr
	adds r7, r0, 0
	ldr r0, [r7, 0x4]
	ldr r6, [r0]
	ldr r5, [r0, 0x4]
	movs r4, 0
_0801D994:
	adds r0, r4, 0
	adds r0, 0xE0
	adds r1, r5, 0
	bl SetBGPaletteBufferColorArray
	adds r5, 0x4
	adds r4, 0x1
	cmp r4, 0xF
	ble _0801D994
	bl sub_8092178
	lsls r0, 24
	lsrs r0, 17
	adds r6, r0
	movs r0, 0x10
	str r0, [sp]
	str r6, [sp, 0x4]
	movs r0, 0xE
	str r0, [sp, 0x8]
	mov r0, r8
	mov r1, r9
	mov r2, r10
	movs r3, 0x10
	bl sub_8007E20
	adds r0, r7, 0
	bl CloseFile
	add sp, 0xC
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_0801D9DC: .4byte gUnknown_80DBF60
_0801D9E0: .4byte gUnknown_8380000
	thumb_func_end sub_801D970

	thumb_func_start sub_801D9E4
sub_801D9E4:
	push {r4,r5,lr}
	ldr r4, _0801DA50
	movs r0, 0xA0
	movs r1, 0x8
	bl MemoryAlloc
	str r0, [r4]
	movs r1, 0x3
	str r1, [r0, 0x34]
	adds r1, r0, 0
	adds r1, 0x84
	str r1, [r0, 0x38]
	adds r0, 0x3C
	bl sub_8006518
	ldr r1, [r4]
	ldr r2, [r1, 0x34]
	lsls r0, r2, 1
	adds r0, r2
	lsls r0, 3
	adds r1, r0
	adds r1, 0x3C
	ldr r0, _0801DA54
	ldm r0!, {r2,r3,r5}
	stm r1!, {r2,r3,r5}
	ldm r0!, {r2,r3,r5}
	stm r1!, {r2,r3,r5}
	ldr r0, [r4]
	ldr r1, [r0, 0x38]
	adds r0, 0x9C
	str r0, [r1, 0x14]
	bl sub_8004914
	ldr r0, [r4]
	adds r0, 0x3C
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	ldr r0, [r4]
	ldr r3, [r0, 0x34]
	movs r1, 0xE5
	movs r2, 0xA
	bl sub_8013818
	bl sub_801DB54
	bl sub_801DBD4
	movs r0, 0x1
	pop {r4,r5}
	pop {r1}
	bx r1
	.align 2, 0
_0801DA50: .4byte gUnknown_203B258
_0801DA54: .4byte gUnknown_80DBF88
	thumb_func_end sub_801D9E4

	thumb_func_start sub_801DA58
sub_801DA58:
	push {lr}
	adds r1, r0, 0
	lsls r1, 16
	asrs r1, 16
	ldr r0, _0801DA74
	ldr r0, [r0]
	bl sub_8013878
	bl sub_801DB54
	bl sub_801DBD4
	pop {r0}
	bx r0
	.align 2, 0
_0801DA74: .4byte gUnknown_203B258
	thumb_func_end sub_801DA58

	thumb_func_start sub_801DA78
sub_801DA78:
	push {r4,lr}
	ldr r4, _0801DA94
	ldr r0, [r4]
	bl GetKeyPress
	cmp r0, 0x1
	beq _0801DA98
	cmp r0, 0x2
	bne _0801DA9C
	movs r0, 0x1
	bl sub_80119D4
	movs r0, 0x2
	b _0801DAB8
	.align 2, 0
_0801DA94: .4byte gUnknown_203B258
_0801DA98:
	movs r0, 0x3
	b _0801DAB8
_0801DA9C:
	ldr r0, [r4]
	movs r1, 0x1
	bl sub_80138B8
	lsls r0, 24
	cmp r0, 0
	bne _0801DAAE
	movs r0, 0
	b _0801DAB8
_0801DAAE:
	bl sub_801DB54
	bl sub_801DBD4
	movs r0, 0x1
_0801DAB8:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_801DA78

	thumb_func_start sub_801DAC0
sub_801DAC0:
	ldr r0, _0801DAD8
	ldr r1, [r0]
	ldrh r2, [r1, 0x1E]
	ldrh r0, [r1, 0x1C]
	adds r3, r0, 0
	muls r3, r2
	adds r0, r3, 0
	ldrh r1, [r1, 0x18]
	adds r0, r1
	lsls r0, 16
	asrs r0, 16
	bx lr
	.align 2, 0
_0801DAD8: .4byte gUnknown_203B258
	thumb_func_end sub_801DAC0

	thumb_func_start sub_801DADC
sub_801DADC:
	push {r4,r5,lr}
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	ldr r5, _0801DB08
	ldr r0, [r5]
	movs r1, 0xE5
	strh r1, [r0, 0x22]
	bl sub_8013984
	bl sub_801DB54
	bl sub_801DBD4
	cmp r4, 0
	beq _0801DB02
	ldr r0, [r5]
	bl AddMenuCursorSprite
_0801DB02:
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_0801DB08: .4byte gUnknown_203B258
	thumb_func_end sub_801DADC

	thumb_func_start sub_801DB0C
sub_801DB0C:
	push {r4,r5,lr}
	ldr r4, _0801DB4C
	ldr r2, [r4]
	cmp r2, 0
	beq _0801DB46
	ldr r0, [r2, 0x34]
	lsls r1, r0, 1
	adds r1, r0
	lsls r1, 3
	adds r1, r2, r1
	adds r1, 0x3C
	ldr r0, _0801DB50
	ldm r0!, {r2,r3,r5}
	stm r1!, {r2,r3,r5}
	ldm r0!, {r2,r3,r5}
	stm r1!, {r2,r3,r5}
	bl sub_8004914
	ldr r0, [r4]
	adds r0, 0x3C
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	ldr r0, [r4]
	bl MemoryFree
	movs r0, 0
	str r0, [r4]
_0801DB46:
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_0801DB4C: .4byte gUnknown_203B258
_0801DB50: .4byte gUnknown_80DBF70
	thumb_func_end sub_801DB0C

	thumb_func_start sub_801DB54
sub_801DB54:
	push {r4,lr}
	ldr r4, _0801DBD0
	ldr r0, [r4]
	adds r0, 0x9C
	movs r2, 0
	movs r1, 0x1
	strb r1, [r0]
	ldr r0, [r4]
	adds r0, 0x9D
	strb r2, [r0]
	ldr r0, [r4]
	adds r0, 0x9E
	movs r1, 0x8
	strb r1, [r0]
	ldr r0, [r4]
	adds r0, 0x9F
	strb r2, [r0]
	bl sub_8004914
	ldr r0, [r4]
	adds r0, 0x3C
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	ldr r0, [r4]
	movs r1, 0x1A
	ldrsh r0, [r0, r1]
	movs r1, 0xC
	bl sub_80095E4
	adds r0, 0x2
	lsls r0, 16
	ldr r2, [r4]
	ldr r3, [r2, 0x34]
	lsls r1, r3, 1
	adds r1, r3
	lsls r1, 3
	adds r1, r2, r1
	adds r1, 0x4A
	asrs r3, r0, 16
	lsrs r0, 16
	strh r0, [r1]
	ldr r1, [r2, 0x34]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 3
	adds r2, r0
	adds r3, 0x2
	adds r2, 0x4C
	strh r3, [r2]
	bl sub_8004914
	ldr r0, [r4]
	adds r0, 0x3C
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0801DBD0: .4byte gUnknown_203B258
	thumb_func_end sub_801DB54

	thumb_func_start sub_801DBD4
sub_801DBD4:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0x8
	ldr r5, _0801DCB4
	ldr r0, [r5]
	ldr r0, [r0, 0x34]
	bl sub_8008C54
	ldr r0, [r5]
	ldr r0, [r0, 0x34]
	bl sub_80073B8
	ldr r2, _0801DCB8
	ldr r0, [r5]
	ldr r3, [r0, 0x34]
	movs r0, 0
	str r0, [sp]
	movs r0, 0xA
	movs r1, 0
	bl xxx_call_draw_string
	ldr r1, [r5]
	adds r0, r1, 0
	adds r0, 0x9E
	ldrb r4, [r0]
	lsls r4, 3
	subs r4, 0x2
	movs r0, 0x1E
	ldrsh r2, [r1, r0]
	adds r2, 0x1
	movs r0, 0x7
	str r0, [sp]
	ldr r0, [r1, 0x34]
	str r0, [sp, 0x4]
	adds r0, r4, 0
	movs r1, 0
	movs r3, 0x2
	bl sub_8012BC4
	movs r6, 0
	ldr r0, [r5]
	movs r1, 0x1A
	ldrsh r0, [r0, r1]
	cmp r6, r0
	bge _0801DC9C
	adds r7, r5, 0
	mov r8, r6
_0801DC34:
	ldr r0, [r7]
	ldrh r2, [r0, 0x1E]
	ldrh r1, [r0, 0x1C]
	adds r3, r2, 0
	muls r3, r1
	adds r1, r3, 0
	adds r1, r6
	lsls r1, 16
	asrs r1, 16
	lsls r5, r1, 1
	adds r5, r1
	lsls r5, 2
	ldr r1, _0801DCBC
	adds r5, r1
	movs r2, 0x4
	ldrsh r1, [r5, r2]
	lsls r4, r1, 3
	subs r4, r1
	lsls r4, 2
	ldr r1, _0801DCC0
	adds r4, r1
	adds r1, r6, 0
	bl sub_8013800
	adds r1, r0, 0
	ldr r2, [r4]
	ldr r0, [r7]
	ldr r3, [r0, 0x34]
	mov r0, r8
	str r0, [sp]
	movs r0, 0x8
	bl xxx_call_draw_string
	ldr r0, [r7]
	adds r1, r6, 0
	bl sub_8013800
	adds r1, r0, 0
	ldr r2, [r5, 0x8]
	ldr r0, [r7]
	ldr r3, [r0, 0x34]
	mov r0, r8
	str r0, [sp]
	movs r0, 0x3E
	bl xxx_call_draw_string
	adds r6, 0x1
	ldr r0, [r7]
	movs r1, 0x1A
	ldrsh r0, [r0, r1]
	cmp r6, r0
	blt _0801DC34
_0801DC9C:
	ldr r0, _0801DCB4
	ldr r0, [r0]
	ldr r0, [r0, 0x34]
	bl sub_80073E0
	add sp, 0x8
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_0801DCB4: .4byte gUnknown_203B258
_0801DCB8: .4byte gUnknown_80DBFA0
_0801DCBC: .4byte gUnknown_811BAF4
_0801DCC0: .4byte gUnknown_81188F0
	thumb_func_end sub_801DBD4

	thumb_func_start sub_801DCC4
sub_801DCC4:
	push {r4,lr}
	ldr r4, _0801DCE4
	movs r0, 0x8E
	lsls r0, 1
	movs r1, 0x8
	bl MemoryAlloc
	str r0, [r4]
	movs r0, 0
	bl sub_801DD6C
	movs r0, 0x1
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_0801DCE4: .4byte gUnknown_203B25C
	thumb_func_end sub_801DCC4

	thumb_func_start sub_801DCE8
sub_801DCE8:
	push {lr}
	ldr r0, _0801DD00
	ldr r0, [r0]
	ldr r0, [r0]
	cmp r0, 0x7
	bhi _0801DD48
	lsls r0, 2
	ldr r1, _0801DD04
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0801DD00: .4byte gUnknown_203B25C
_0801DD04: .4byte _0801DD08
	.align 2, 0
_0801DD08:
	.4byte _0801DD2C
	.4byte _0801DD2C
	.4byte _0801DD28
	.4byte _0801DD32
	.4byte _0801DD32
	.4byte _0801DD38
	.4byte _0801DD3E
	.4byte _0801DD44
_0801DD28:
	movs r0, 0x3
	b _0801DD4A
_0801DD2C:
	bl sub_801E028
	b _0801DD48
_0801DD32:
	bl sub_801E088
	b _0801DD48
_0801DD38:
	bl sub_801E0E0
	b _0801DD48
_0801DD3E:
	bl sub_801E0FC
	b _0801DD48
_0801DD44:
	bl sub_801E138
_0801DD48:
	movs r0, 0
_0801DD4A:
	pop {r1}
	bx r1
	thumb_func_end sub_801DCE8

	thumb_func_start sub_801DD50
sub_801DD50:
	push {r4,lr}
	ldr r4, _0801DD68
	ldr r0, [r4]
	cmp r0, 0
	beq _0801DD62
	bl MemoryFree
	movs r0, 0
	str r0, [r4]
_0801DD62:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0801DD68: .4byte gUnknown_203B25C
	thumb_func_end sub_801DD50

	thumb_func_start sub_801DD6C
sub_801DD6C:
	push {lr}
	ldr r1, _0801DD80
	ldr r1, [r1]
	str r0, [r1]
	bl sub_801DD84
	bl sub_801DED0
	pop {r0}
	bx r0
	.align 2, 0
_0801DD80: .4byte gUnknown_203B25C
	thumb_func_end sub_801DD6C

	thumb_func_start sub_801DD84
sub_801DD84:
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	ldr r4, _0801DDAC
	ldr r0, [r4]
	adds r0, 0xBC
	bl sub_8006518
	ldr r0, [r4]
	ldr r0, [r0]
	cmp r0, 0
	beq _0801DDB4
	cmp r0, 0x1
	beq _0801DE38
	movs r3, 0
	adds r7, r4, 0
	ldr r2, _0801DDB0
	b _0801DE90
	.align 2, 0
_0801DDAC: .4byte gUnknown_203B25C
_0801DDB0: .4byte gUnknown_80DBFB0
_0801DDB4:
	bl sub_801DFA4
	movs r3, 0
	ldr r1, [r4]
	adds r0, r1, 0
	adds r0, 0xAC
	ldrh r0, [r0]
	cmp r0, 0
	bne _0801DDCE
	ldr r0, [r1, 0x70]
	str r0, [r1, 0x18]
	adds r7, r4, 0
	b _0801DDF2
_0801DDCE:
	adds r3, 0x1
	ldr r7, _0801DE2C
	cmp r3, 0x7
	bgt _0801DDF2
	ldr r2, [r7]
	lsls r0, r3, 1
	adds r1, r2, 0
	adds r1, 0xAC
	adds r1, r0
	ldrh r0, [r1]
	cmp r0, 0
	bne _0801DDCE
	lsls r0, r3, 3
	adds r1, r2, 0
	adds r1, 0x70
	adds r1, r0
	ldr r0, [r1]
	str r0, [r2, 0x18]
_0801DDF2:
	ldr r0, _0801DE30
	mov r9, r0
	ldr r2, _0801DE2C
	mov r12, r2
	ldr r3, _0801DE34
	mov r8, r3
	movs r2, 0
	movs r3, 0x3
_0801DE02:
	mov r4, r12
	ldr r1, [r4]
	adds r1, r2
	adds r1, 0xBC
	mov r0, r8
	ldm r0!, {r4-r6}
	stm r1!, {r4-r6}
	ldm r0!, {r4-r6}
	stm r1!, {r4-r6}
	adds r2, 0x18
	subs r3, 0x1
	cmp r3, 0
	bge _0801DE02
	ldr r1, [r7]
	adds r1, 0xBC
	mov r0, r9
	ldm r0!, {r2,r5,r6}
	stm r1!, {r2,r5,r6}
	ldm r0!, {r3-r5}
	stm r1!, {r3-r5}
	b _0801DE70
	.align 2, 0
_0801DE2C: .4byte gUnknown_203B25C
_0801DE30: .4byte gUnknown_80DBFCC
_0801DE34: .4byte gUnknown_80DBFB0
_0801DE38:
	bl sub_801DFA4
	mov r8, r4
	ldr r6, _0801DE88
	mov r12, r6
	mov r7, r8
	movs r2, 0
	movs r3, 0x3
_0801DE48:
	mov r0, r8
	ldr r1, [r0]
	adds r1, r2
	adds r1, 0xBC
	mov r0, r12
	ldm r0!, {r4-r6}
	stm r1!, {r4-r6}
	ldm r0!, {r4-r6}
	stm r1!, {r4-r6}
	adds r2, 0x18
	subs r3, 0x1
	cmp r3, 0
	bge _0801DE48
	ldr r1, [r7]
	adds r1, 0xBC
	ldr r0, _0801DE8C
	ldm r0!, {r2-r4}
	stm r1!, {r2-r4}
	ldm r0!, {r2,r5,r6}
	stm r1!, {r2,r5,r6}
_0801DE70:
	ldr r1, [r7]
	adds r0, r1, 0
	adds r0, 0xBC
	adds r1, 0x6C
	bl sub_8012CAC
	ldr r0, [r7]
	adds r0, 0xC8
	movs r1, 0xA
	strh r1, [r0]
	b _0801DEAC
	.align 2, 0
_0801DE88: .4byte gUnknown_80DBFB0
_0801DE8C: .4byte gUnknown_80DBFCC
_0801DE90:
	ldr r0, [r7]
	lsls r1, r3, 1
	adds r1, r3
	lsls r1, 3
	adds r0, r1
	adds r0, 0xBC
	adds r1, r2, 0
	ldm r1!, {r4-r6}
	stm r0!, {r4-r6}
	ldm r1!, {r4-r6}
	stm r0!, {r4-r6}
	adds r3, 0x1
	cmp r3, 0x3
	ble _0801DE90
_0801DEAC:
	bl sub_8004914
	ldr r0, _0801DECC
	ldr r0, [r0]
	adds r0, 0xBC
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_0801DECC: .4byte gUnknown_203B25C
	thumb_func_end sub_801DD84

	thumb_func_start sub_801DED0
sub_801DED0:
	push {r4,r5,lr}
	sub sp, 0x14
	ldr r1, _0801DEEC
	ldr r0, [r1]
	ldr r0, [r0]
	adds r3, r1, 0
	cmp r0, 0x7
	bhi _0801DF94
	lsls r0, 2
	ldr r1, _0801DEF0
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0801DEEC: .4byte gUnknown_203B25C
_0801DEF0: .4byte _0801DEF4
	.align 2, 0
_0801DEF4:
	.4byte _0801DF14
	.4byte _0801DF14
	.4byte _0801DF94
	.4byte _0801DF38
	.4byte _0801DF40
	.4byte _0801DF48
	.4byte _0801DF52
	.4byte _0801DF70
_0801DF14:
	ldr r2, [r3]
	ldr r0, _0801DF34
	str r0, [r2, 0x1C]
	adds r0, r2, 0
	adds r0, 0x1C
	adds r1, r2, 0
	adds r1, 0x6C
	adds r3, r2, 0
	adds r3, 0xAC
	ldr r2, [r2, 0x18]
	str r2, [sp]
	movs r2, 0
	str r2, [sp, 0x4]
	bl sub_8012D60
	b _0801DF94
	.align 2, 0
_0801DF34: .4byte gUnknown_80DBFE4
_0801DF38:
	movs r0, 0
	bl sub_801E3F0
	b _0801DF94
_0801DF40:
	movs r0, 0x1
	bl sub_801E510
	b _0801DF94
_0801DF48:
	ldr r0, [r3]
	ldr r0, [r0, 0x4]
	bl sub_801E658
	b _0801DF94
_0801DF52:
	ldr r1, [r3]
	ldr r0, _0801DF6C
	adds r1, 0x8
	ldr r0, [r0]
	ldm r0!, {r2,r4,r5}
	stm r1!, {r2,r4,r5}
	ldr r0, [r0]
	str r0, [r1]
	ldr r0, [r3]
	adds r0, 0x8
	bl sub_801E198
	b _0801DF94
	.align 2, 0
_0801DF6C: .4byte gUnknown_203B46C
_0801DF70:
	bl sub_801DFE4
	ldr r0, _0801DF9C
	ldr r1, _0801DFA0
	ldr r3, [r1]
	adds r3, 0x6C
	movs r2, 0
	str r2, [sp]
	movs r1, 0x4
	str r1, [sp, 0x4]
	str r2, [sp, 0x8]
	str r2, [sp, 0xC]
	movs r1, 0x20
	str r1, [sp, 0x10]
	movs r1, 0
	movs r2, 0x4
	bl sub_8014248
_0801DF94:
	add sp, 0x14
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_0801DF9C: .4byte gUnknown_80DBFEC
_0801DFA0: .4byte gUnknown_203B25C
	thumb_func_end sub_801DED0

	thumb_func_start sub_801DFA4
sub_801DFA4:
	push {r4,lr}
	ldr r4, _0801DFD8
	ldr r0, [r4]
	adds r0, 0xAC
	movs r1, 0
	movs r2, 0x10
	bl MemoryFill16
	ldr r0, [r4]
	movs r3, 0
	ldr r1, _0801DFDC
	str r1, [r0, 0x6C]
	movs r1, 0x3
	str r1, [r0, 0x70]
	movs r2, 0x1
	ldr r1, _0801DFE0
	str r1, [r0, 0x74]
	movs r1, 0x2
	str r1, [r0, 0x78]
	str r3, [r0, 0x7C]
	adds r0, 0x80
	str r2, [r0]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0801DFD8: .4byte gUnknown_203B25C
_0801DFDC: .4byte gUnknown_80DC000
_0801DFE0: .4byte gUnknown_80DC010
	thumb_func_end sub_801DFA4

	thumb_func_start sub_801DFE4
sub_801DFE4:
	push {r4,lr}
	ldr r4, _0801E01C
	ldr r0, [r4]
	adds r0, 0xAC
	movs r1, 0
	movs r2, 0x10
	bl MemoryFill16
	ldr r1, [r4]
	movs r3, 0
	ldr r0, _0801E020
	ldr r0, [r0]
	str r0, [r1, 0x6C]
	movs r0, 0x4
	str r0, [r1, 0x70]
	movs r2, 0x1
	ldr r0, _0801E024
	ldr r0, [r0]
	str r0, [r1, 0x74]
	movs r0, 0x5
	str r0, [r1, 0x78]
	str r3, [r1, 0x7C]
	adds r1, 0x80
	str r2, [r1]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0801E01C: .4byte gUnknown_203B25C
_0801E020: .4byte gUnknown_80D4920
_0801E024: .4byte gUnknown_80D4928
	thumb_func_end sub_801DFE4

	thumb_func_start sub_801E028
sub_801E028:
	push {r4,lr}
	sub sp, 0x4
	movs r0, 0
	str r0, [sp]
	ldr r4, _0801E060
	ldr r0, [r4]
	adds r0, 0x1C
	bl sub_8012FD8
	lsls r0, 24
	cmp r0, 0
	bne _0801E050
	ldr r0, [r4]
	adds r0, 0x1C
	mov r1, sp
	bl sub_8013114
	ldr r1, [r4]
	ldr r0, [sp]
	str r0, [r1, 0x18]
_0801E050:
	ldr r0, [sp]
	cmp r0, 0x2
	beq _0801E06A
	cmp r0, 0x2
	bgt _0801E064
	cmp r0, 0x1
	beq _0801E07A
	b _0801E080
	.align 2, 0
_0801E060: .4byte gUnknown_203B25C
_0801E064:
	cmp r0, 0x3
	beq _0801E072
	b _0801E080
_0801E06A:
	movs r0, 0x3
	bl sub_801DD6C
	b _0801E080
_0801E072:
	movs r0, 0x6
	bl sub_801DD6C
	b _0801E080
_0801E07A:
	movs r0, 0x2
	bl sub_801DD6C
_0801E080:
	add sp, 0x4
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_801E028

	thumb_func_start sub_801E088
sub_801E088:
	push {lr}
	movs r0, 0x1
	bl sub_801E474
	cmp r0, 0x4
	bhi _0801E0DA
	lsls r0, 2
	ldr r1, _0801E0A0
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0801E0A0: .4byte _0801E0A4
	.align 2, 0
_0801E0A4:
	.4byte _0801E0DA
	.4byte _0801E0DA
	.4byte _0801E0D0
	.4byte _0801E0B8
	.4byte _0801E0B8
_0801E0B8:
	bl sub_801E4F4
	ldr r1, _0801E0CC
	ldr r1, [r1]
	str r0, [r1, 0x4]
	movs r0, 0x5
	bl sub_801DD6C
	b _0801E0DA
	.align 2, 0
_0801E0CC: .4byte gUnknown_203B25C
_0801E0D0:
	bl sub_801E54C
	movs r0, 0x1
	bl sub_801DD6C
_0801E0DA:
	pop {r0}
	bx r0
	thumb_func_end sub_801E088

	thumb_func_start sub_801E0E0
sub_801E0E0:
	push {lr}
	bl sub_801E6CC
	cmp r0, 0x1
	bls _0801E0F8
	cmp r0, 0x3
	bhi _0801E0F8
	bl sub_801E724
	movs r0, 0x4
	bl sub_801DD6C
_0801E0F8:
	pop {r0}
	bx r0
	thumb_func_end sub_801E0E0

	thumb_func_start sub_801E0FC
sub_801E0FC:
	push {lr}
	bl sub_801E218
	cmp r0, 0x1
	bls _0801E132
	cmp r0, 0x3
	bhi _0801E132
	bl sub_801E2C4
	ldr r0, _0801E128
	ldr r0, [r0]
	adds r0, 0x8
	bl sub_80949DC
	lsls r0, 24
	cmp r0, 0
	beq _0801E12C
	movs r0, 0x1
	bl sub_801DD6C
	b _0801E132
	.align 2, 0
_0801E128: .4byte gUnknown_203B25C
_0801E12C:
	movs r0, 0x7
	bl sub_801DD6C
_0801E132:
	pop {r0}
	bx r0
	thumb_func_end sub_801E0FC

	thumb_func_start sub_801E138
sub_801E138:
	push {r4,lr}
	sub sp, 0x4
	mov r0, sp
	bl sub_80144A4
	cmp r0, 0
	bne _0801E18E
	ldr r0, [sp]
	cmp r0, 0x4
	beq _0801E15C
	cmp r0, 0x4
	bgt _0801E156
	cmp r0, 0x1
	beq _0801E188
	b _0801E18E
_0801E156:
	cmp r0, 0x5
	beq _0801E188
	b _0801E18E
_0801E15C:
	ldr r1, _0801E180
	ldr r0, _0801E184
	ldr r0, [r0]
	ldr r1, [r1]
	adds r0, 0x8
	ldm r0!, {r2-r4}
	stm r1!, {r2-r4}
	ldr r0, [r0]
	str r0, [r1]
	bl sub_8094C14
	movs r0, 0
	bl sub_8099690
	movs r0, 0x1
	bl sub_801DD6C
	b _0801E18E
	.align 2, 0
_0801E180: .4byte gUnknown_203B46C
_0801E184: .4byte gUnknown_203B25C
_0801E188:
	movs r0, 0x1
	bl sub_801DD6C
_0801E18E:
	add sp, 0x4
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_801E138

	thumb_func_start sub_801E198
sub_801E198:
	push {r4,r5,lr}
	adds r5, r0, 0
	ldr r4, _0801E210
	movs r0, 0xAC
	movs r1, 0x8
	bl MemoryAlloc
	str r0, [r4]
	stm r0!, {r5}
	bl sub_801317C
	ldr r1, [r4]
	movs r0, 0
	str r0, [r1, 0x44]
	adds r0, r1, 0
	adds r0, 0x4C
	str r0, [r1, 0x48]
	bl sub_8006518
	ldr r1, [r4]
	ldr r2, [r1, 0x44]
	lsls r0, r2, 1
	adds r0, r2
	lsls r0, 3
	adds r1, r0
	adds r1, 0x4C
	ldr r0, _0801E214
	ldm r0!, {r2,r3,r5}
	stm r1!, {r2,r3,r5}
	ldm r0!, {r2,r3,r5}
	stm r1!, {r2,r3,r5}
	ldr r0, [r4]
	ldr r0, [r0, 0x48]
	movs r1, 0x1
	bl sub_8012D08
	bl sub_8004914
	ldr r0, [r4]
	adds r0, 0x4C
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	ldr r1, [r4]
	adds r0, r1, 0
	adds r0, 0x10
	ldr r3, [r1, 0x44]
	movs r1, 0x1
	movs r2, 0x1
	bl sub_8013818
	bl nullsub_38
	bl sub_801E310
	movs r0, 0x1
	pop {r4,r5}
	pop {r1}
	bx r1
	.align 2, 0
_0801E210: .4byte gUnknown_203B260
_0801E214: .4byte gUnknown_80DC03C
	thumb_func_end sub_801E198

	thumb_func_start sub_801E218
sub_801E218:
	push {r4,lr}
	movs r4, 0
	bl sub_8012AE8
	cmp r0, 0x2
	beq _0801E238
	cmp r0, 0x2
	bgt _0801E22E
	cmp r0, 0x1
	beq _0801E242
	b _0801E294
_0801E22E:
	cmp r0, 0x9
	beq _0801E24C
	cmp r0, 0xA
	beq _0801E26C
	b _0801E294
_0801E238:
	movs r0, 0x1
	bl sub_80119D4
	movs r0, 0x2
	b _0801E2BE
_0801E242:
	movs r0, 0
	bl sub_80119D4
	movs r0, 0x3
	b _0801E2BE
_0801E24C:
	ldr r0, _0801E264
	ldr r1, [r0]
	movs r2, 0x28
	ldrsh r0, [r1, r2]
	cmp r0, 0
	bne _0801E294
	ldr r1, [r1]
	ldrb r0, [r1, 0x8]
	cmp r0, 0
	bne _0801E268
	movs r0, 0x2
	b _0801E28A
	.align 2, 0
_0801E264: .4byte gUnknown_203B260
_0801E268:
	subs r0, 0x1
	b _0801E28A
_0801E26C:
	ldr r0, _0801E284
	ldr r1, [r0]
	movs r2, 0x28
	ldrsh r0, [r1, r2]
	cmp r0, 0
	bne _0801E294
	ldr r1, [r1]
	ldrb r0, [r1, 0x8]
	cmp r0, 0x1
	bls _0801E288
	strb r4, [r1, 0x8]
	b _0801E28C
	.align 2, 0
_0801E284: .4byte gUnknown_203B260
_0801E288:
	adds r0, 0x1
_0801E28A:
	strb r0, [r1, 0x8]
_0801E28C:
	movs r0, 0x3
	bl sub_80119D4
	movs r4, 0x1
_0801E294:
	ldr r0, _0801E2B8
	ldr r0, [r0]
	adds r0, 0x10
	movs r1, 0x1
	bl sub_80138B8
	lsls r0, 24
	cmp r0, 0
	bne _0801E2AA
	cmp r4, 0x1
	bne _0801E2BC
_0801E2AA:
	bl nullsub_38
	bl sub_801E310
	movs r0, 0x1
	b _0801E2BE
	.align 2, 0
_0801E2B8: .4byte gUnknown_203B260
_0801E2BC:
	movs r0, 0
_0801E2BE:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_801E218

	thumb_func_start sub_801E2C4
sub_801E2C4:
	push {r4,r5,lr}
	ldr r4, _0801E304
	ldr r2, [r4]
	cmp r2, 0
	beq _0801E2FE
	ldr r0, [r2, 0x44]
	lsls r1, r0, 1
	adds r1, r0
	lsls r1, 3
	adds r1, r2, r1
	adds r1, 0x4C
	ldr r0, _0801E308
	ldm r0!, {r2,r3,r5}
	stm r1!, {r2,r3,r5}
	ldm r0!, {r2,r3,r5}
	stm r1!, {r2,r3,r5}
	bl sub_8004914
	ldr r0, [r4]
	adds r0, 0x4C
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	ldr r0, [r4]
	bl MemoryFree
	movs r0, 0
	str r0, [r4]
_0801E2FE:
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_0801E304: .4byte gUnknown_203B260
_0801E308: .4byte gUnknown_80DC020
	thumb_func_end sub_801E2C4

	thumb_func_start nullsub_38
nullsub_38:
	bx lr
	thumb_func_end nullsub_38

	thumb_func_start sub_801E310
sub_801E310:
	push {r4-r6,lr}
	sub sp, 0x4
	ldr r5, _0801E368
	ldr r0, [r5]
	ldr r0, [r0, 0x44]
	bl sub_8008C54
	ldr r0, [r5]
	ldr r0, [r0, 0x44]
	bl sub_80073B8
	ldr r2, _0801E36C
	ldr r0, [r5]
	ldr r3, [r0, 0x44]
	movs r4, 0
	str r4, [sp]
	movs r0, 0x10
	movs r1, 0
	bl xxx_call_draw_string
	ldr r0, [r5]
	adds r0, 0x10
	movs r1, 0
	bl sub_8013800
	adds r6, r0, 0
	ldr r2, _0801E370
	ldr r0, [r5]
	ldr r3, [r0, 0x44]
	str r4, [sp]
	movs r0, 0x8
	adds r1, r6, 0
	bl xxx_call_draw_string
	ldr r0, [r5]
	ldr r0, [r0]
	ldrb r0, [r0, 0x8]
	cmp r0, 0x1
	beq _0801E384
	cmp r0, 0x1
	bgt _0801E374
	cmp r0, 0
	beq _0801E37A
	b _0801E3D6
	.align 2, 0
_0801E368: .4byte gUnknown_203B260
_0801E36C: .4byte gUnknown_80DC054
_0801E370: .4byte gUnknown_80DC064
_0801E374:
	cmp r0, 0x2
	beq _0801E3B0
	b _0801E3D6
_0801E37A:
	ldr r0, _0801E380
	b _0801E386
	.align 2, 0
_0801E380: .4byte gUnknown_80DC084
_0801E384:
	ldr r0, _0801E3AC
_0801E386:
	bl sub_8008ED0
	adds r4, r0, 0
	ldr r1, [r5]
	ldr r0, [r1, 0x44]
	ldr r1, [r1]
	ldrb r2, [r1, 0x8]
	lsls r1, r2, 2
	adds r1, r2
	lsls r1, 3
	adds r1, 0x50
	adds r2, r6, 0
	adds r2, 0xA
	movs r3, 0x7
	str r3, [sp]
	adds r3, r4, 0
	bl sub_80078A4
	b _0801E3D6
	.align 2, 0
_0801E3AC: .4byte gUnknown_80DC08C
_0801E3B0:
	ldr r0, _0801E3E8
	bl sub_8008ED0
	adds r4, r0, 0
	ldr r1, [r5]
	ldr r0, [r1, 0x44]
	ldr r1, [r1]
	ldrb r2, [r1, 0x8]
	lsls r1, r2, 2
	adds r1, r2
	lsls r1, 3
	adds r1, 0x50
	adds r2, r6, 0
	adds r2, 0xA
	movs r3, 0x7
	str r3, [sp]
	adds r3, r4, 0
	bl sub_80078A4
_0801E3D6:
	ldr r0, _0801E3EC
	ldr r0, [r0]
	ldr r0, [r0, 0x44]
	bl sub_80073E0
	add sp, 0x4
	pop {r4-r6}
	pop {r0}
	bx r0
	.align 2, 0
_0801E3E8: .4byte gUnknown_80DC090
_0801E3EC: .4byte gUnknown_203B260
	thumb_func_end sub_801E310

	thumb_func_start sub_801E3F0
sub_801E3F0:
	push {r4-r6,lr}
	adds r5, r0, 0
	ldr r4, _0801E46C
	ldr r0, [r4]
	cmp r0, 0
	bne _0801E406
	movs r0, 0x9C
	movs r1, 0x8
	bl MemoryAlloc
	str r0, [r4]
_0801E406:
	ldr r0, [r4]
	str r5, [r0, 0x34]
	lsls r1, r5, 1
	adds r1, r5
	lsls r1, 3
	adds r1, 0x3C
	adds r1, r0, r1
	str r1, [r0, 0x38]
	adds r0, 0x3C
	bl sub_8006518
	ldr r1, [r4]
	ldr r2, [r1, 0x34]
	lsls r0, r2, 1
	adds r0, r2
	lsls r0, 3
	adds r1, r0
	adds r1, 0x3C
	ldr r0, _0801E470
	ldm r0!, {r2,r3,r6}
	stm r1!, {r2,r3,r6}
	ldm r0!, {r2,r3,r6}
	stm r1!, {r2,r3,r6}
	ldr r0, [r4]
	ldr r0, [r0, 0x38]
	movs r1, 0xA
	bl sub_8012D08
	bl sub_8004914
	ldr r0, [r4]
	adds r0, 0x3C
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	ldr r0, [r4]
	movs r1, 0x5
	movs r2, 0xA
	adds r3, r5, 0
	bl sub_8013818
	bl sub_801E594
	bl sub_801E5E8
	movs r0, 0x1
	pop {r4-r6}
	pop {r1}
	bx r1
	.align 2, 0
_0801E46C: .4byte gUnknown_203B264
_0801E470: .4byte gUnknown_80DC0BC
	thumb_func_end sub_801E3F0

	thumb_func_start sub_801E474
sub_801E474:
	push {lr}
	lsls r0, 24
	cmp r0, 0
	bne _0801E48C
	ldr r0, _0801E488
	ldr r0, [r0]
	bl sub_8013660
	movs r0, 0
	b _0801E4EE
	.align 2, 0
_0801E488: .4byte gUnknown_203B264
_0801E48C:
	ldr r0, _0801E4A4
	ldr r0, [r0]
	bl GetKeyPress
	cmp r0, 0x2
	beq _0801E4AE
	cmp r0, 0x2
	bgt _0801E4A8
	cmp r0, 0x1
	beq _0801E4B8
	b _0801E4CC
	.align 2, 0
_0801E4A4: .4byte gUnknown_203B264
_0801E4A8:
	cmp r0, 0x4
	beq _0801E4C2
	b _0801E4CC
_0801E4AE:
	movs r0, 0x1
	bl sub_80119D4
	movs r0, 0x2
	b _0801E4EE
_0801E4B8:
	movs r0, 0
	bl sub_80119D4
	movs r0, 0x3
	b _0801E4EE
_0801E4C2:
	movs r0, 0x4
	bl sub_80119D4
	movs r0, 0x4
	b _0801E4EE
_0801E4CC:
	ldr r0, _0801E4E0
	ldr r0, [r0]
	movs r1, 0x1
	bl sub_80138B8
	lsls r0, 24
	cmp r0, 0
	bne _0801E4E4
	movs r0, 0
	b _0801E4EE
	.align 2, 0
_0801E4E0: .4byte gUnknown_203B264
_0801E4E4:
	bl sub_801E594
	bl sub_801E5E8
	movs r0, 0x1
_0801E4EE:
	pop {r1}
	bx r1
	thumb_func_end sub_801E474

	thumb_func_start sub_801E4F4
sub_801E4F4:
	ldr r0, _0801E50C
	ldr r1, [r0]
	movs r0, 0x1E
	ldrsh r2, [r1, r0]
	movs r3, 0x1C
	ldrsh r0, [r1, r3]
	muls r0, r2
	movs r2, 0x18
	ldrsh r1, [r1, r2]
	adds r0, r1
	bx lr
	.align 2, 0
_0801E50C: .4byte gUnknown_203B264
	thumb_func_end sub_801E4F4

	thumb_func_start sub_801E510
sub_801E510:
	push {r4,r5,lr}
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	bl sub_8004914
	ldr r5, _0801E548
	ldr r0, [r5]
	adds r0, 0x3C
	movs r1, 0
	movs r2, 0
	bl sub_800641C
	ldr r0, [r5]
	bl sub_8013984
	bl sub_801E594
	bl sub_801E5E8
	cmp r4, 0
	beq _0801E542
	ldr r0, [r5]
	bl AddMenuCursorSprite
_0801E542:
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_0801E548: .4byte gUnknown_203B264
	thumb_func_end sub_801E510

	thumb_func_start sub_801E54C
sub_801E54C:
	push {r4,r5,lr}
	ldr r4, _0801E58C
	ldr r2, [r4]
	cmp r2, 0
	beq _0801E586
	ldr r0, [r2, 0x34]
	lsls r1, r0, 1
	adds r1, r0
	lsls r1, 3
	adds r1, r2, r1
	adds r1, 0x3C
	ldr r0, _0801E590
	ldm r0!, {r2,r3,r5}
	stm r1!, {r2,r3,r5}
	ldm r0!, {r2,r3,r5}
	stm r1!, {r2,r3,r5}
	bl sub_8004914
	ldr r0, [r4]
	adds r0, 0x3C
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	ldr r0, [r4]
	bl MemoryFree
	movs r0, 0
	str r0, [r4]
_0801E586:
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_0801E58C: .4byte gUnknown_203B264
_0801E590: .4byte gUnknown_80DC0A0
	thumb_func_end sub_801E54C

	thumb_func_start sub_801E594
sub_801E594:
	push {r4,lr}
	ldr r4, _0801E5E4
	ldr r0, [r4]
	movs r1, 0x1A
	ldrsh r0, [r0, r1]
	movs r1, 0xC
	bl sub_80095E4
	adds r0, 0x2
	lsls r0, 16
	ldr r2, [r4]
	ldr r3, [r2, 0x34]
	lsls r1, r3, 1
	adds r1, r3
	lsls r1, 3
	adds r1, r2, r1
	adds r1, 0x4A
	asrs r3, r0, 16
	lsrs r0, 16
	strh r0, [r1]
	ldr r1, [r2, 0x34]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 3
	adds r2, r0
	adds r3, 0x2
	adds r2, 0x4C
	strh r3, [r2]
	bl sub_8004914
	ldr r0, [r4]
	adds r0, 0x3C
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0801E5E4: .4byte gUnknown_203B264
	thumb_func_end sub_801E594

	thumb_func_start sub_801E5E8
sub_801E5E8:
	push {r4-r6,lr}
	sub sp, 0x4
	ldr r4, _0801E64C
	ldr r0, [r4]
	ldr r0, [r0, 0x34]
	bl sub_8008C54
	ldr r0, [r4]
	ldr r0, [r0, 0x34]
	bl sub_80073B8
	ldr r2, _0801E650
	ldr r0, [r4]
	ldr r3, [r0, 0x34]
	movs r0, 0
	str r0, [sp]
	movs r0, 0x10
	movs r1, 0
	bl xxx_call_draw_string
	movs r5, 0
	adds r6, r4, 0
	ldr r4, _0801E654
_0801E616:
	ldr r0, [r6]
	adds r1, r5, 0
	bl sub_8013800
	adds r1, r0, 0
	ldr r2, [r4]
	ldr r0, [r6]
	ldr r3, [r0, 0x34]
	movs r0, 0
	str r0, [sp]
	movs r0, 0xA
	bl xxx_call_draw_string
	adds r4, 0x8
	adds r5, 0x1
	cmp r5, 0x4
	ble _0801E616
	ldr r0, _0801E64C
	ldr r0, [r0]
	ldr r0, [r0, 0x34]
	bl sub_80073E0
	add sp, 0x4
	pop {r4-r6}
	pop {r0}
	bx r0
	.align 2, 0
_0801E64C: .4byte gUnknown_203B264
_0801E650: .4byte gUnknown_80DC0D4
_0801E654: .4byte gUnknown_80DAA98
	thumb_func_end sub_801E5E8

	thumb_func_start sub_801E658
sub_801E658:
	push {r4-r6,lr}
	adds r5, r0, 0
	ldr r4, _0801E6C4
	movs r0, 0xA0
	movs r1, 0x8
	bl MemoryAlloc
	str r0, [r4]
	movs r1, 0
	str r1, [r0, 0x34]
	adds r1, r0, 0
	adds r1, 0x3C
	str r1, [r0, 0x38]
	adds r0, r1, 0
	bl sub_8006518
	ldr r1, [r4]
	ldr r2, [r1, 0x34]
	lsls r0, r2, 1
	adds r0, r2
	lsls r0, 3
	adds r1, r0
	adds r1, 0x3C
	ldr r0, _0801E6C8
	ldm r0!, {r2,r3,r6}
	stm r1!, {r2,r3,r6}
	ldm r0!, {r2,r3,r6}
	stm r1!, {r2,r3,r6}
	ldr r0, [r4]
	ldr r1, [r0, 0x38]
	adds r0, 0x9C
	str r0, [r1, 0x14]
	bl sub_8004914
	ldr r0, [r4]
	adds r0, 0x3C
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	ldr r0, [r4]
	ldr r3, [r0, 0x34]
	movs r1, 0x5
	movs r2, 0x1
	bl sub_8013818
	ldr r0, [r4]
	strh r5, [r0, 0x1E]
	bl sub_801E714
	movs r0, 0x1
	pop {r4-r6}
	pop {r1}
	bx r1
	.align 2, 0
_0801E6C4: .4byte gUnknown_203B268
_0801E6C8: .4byte gUnknown_80DC0FC
	thumb_func_end sub_801E658

	thumb_func_start sub_801E6CC
sub_801E6CC:
	push {r4,lr}
	ldr r4, _0801E6E8
	ldr r0, [r4]
	bl GetKeyPress
	cmp r0, 0x1
	beq _0801E6EC
	cmp r0, 0x2
	bne _0801E6F6
	movs r0, 0x1
	bl sub_80119D4
	movs r0, 0x2
	b _0801E70C
	.align 2, 0
_0801E6E8: .4byte gUnknown_203B268
_0801E6EC:
	movs r0, 0
	bl sub_80119D4
	movs r0, 0x3
	b _0801E70C
_0801E6F6:
	ldr r0, [r4]
	bl sub_8013938
	lsls r0, 24
	cmp r0, 0
	bne _0801E706
	movs r0, 0
	b _0801E70C
_0801E706:
	bl sub_801E714
	movs r0, 0x1
_0801E70C:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_801E6CC

	thumb_func_start sub_801E714
sub_801E714:
	push {lr}
	bl sub_801E76C
	bl sub_801E7AC
	pop {r0}
	bx r0
	thumb_func_end sub_801E714

	thumb_func_start sub_801E724
sub_801E724:
	push {r4,r5,lr}
	ldr r4, _0801E764
	ldr r2, [r4]
	cmp r2, 0
	beq _0801E75E
	ldr r0, [r2, 0x34]
	lsls r1, r0, 1
	adds r1, r0
	lsls r1, 3
	adds r1, r2, r1
	adds r1, 0x3C
	ldr r0, _0801E768
	ldm r0!, {r2,r3,r5}
	stm r1!, {r2,r3,r5}
	ldm r0!, {r2,r3,r5}
	stm r1!, {r2,r3,r5}
	bl sub_8004914
	ldr r0, [r4]
	adds r0, 0x3C
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	ldr r0, [r4]
	bl MemoryFree
	movs r0, 0
	str r0, [r4]
_0801E75E:
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_0801E764: .4byte gUnknown_203B268
_0801E768: .4byte gUnknown_80DC0E4
	thumb_func_end sub_801E724

	thumb_func_start sub_801E76C
sub_801E76C:
	push {r4,lr}
	ldr r4, _0801E7A8
	ldr r0, [r4]
	ldrh r1, [r0, 0x20]
	adds r0, 0x9C
	movs r2, 0
	strb r1, [r0]
	ldr r0, [r4]
	ldrh r1, [r0, 0x1E]
	adds r0, 0x9D
	strb r1, [r0]
	ldr r0, [r4]
	adds r0, 0x9E
	movs r1, 0xF
	strb r1, [r0]
	ldr r0, [r4]
	adds r0, 0x9F
	strb r2, [r0]
	bl sub_8004914
	ldr r0, [r4]
	adds r0, 0x3C
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0801E7A8: .4byte gUnknown_203B268
	thumb_func_end sub_801E76C

	thumb_func_start sub_801E7AC
sub_801E7AC:
	push {r4-r6,lr}
	sub sp, 0x4
	ldr r5, _0801E804
	ldr r0, [r5]
	ldr r0, [r0, 0x34]
	bl sub_80073B8
	ldr r3, [r5]
	movs r0, 0x1E
	ldrsh r1, [r3, r0]
	lsls r1, 3
	adds r0, r1, 0
	adds r0, 0x10
	ldr r4, _0801E808
	adds r1, r4
	ldr r2, [r1]
	ldr r3, [r3, 0x34]
	movs r6, 0
	str r6, [sp]
	movs r1, 0
	bl xxx_call_draw_string
	ldr r1, [r5]
	movs r2, 0x1E
	ldrsh r0, [r1, r2]
	lsls r0, 3
	adds r4, 0x4
	adds r0, r4
	ldr r2, [r0]
	ldr r3, [r1, 0x34]
	str r6, [sp]
	movs r0, 0xA
	movs r1, 0x14
	bl xxx_call_draw_string
	ldr r0, [r5]
	ldr r0, [r0, 0x34]
	bl sub_80073E0
	add sp, 0x4
	pop {r4-r6}
	pop {r0}
	bx r0
	.align 2, 0
_0801E804: .4byte gUnknown_203B268
_0801E808: .4byte gUnknown_80DAA98
	thumb_func_end sub_801E7AC

	thumb_func_start sub_801E80C
sub_801E80C:
	push {r4-r6,lr}
	mov r6, r8
	push {r6}
	mov r8, r0
	adds r4, r1, 0
	adds r6, r2, 0
	lsls r4, 16
	asrs r4, 16
	ldr r5, _0801E84C
	movs r0, 0xC6
	lsls r0, 1
	movs r1, 0x8
	bl MemoryAlloc
	adds r2, r0, 0
	str r2, [r5]
	mov r0, r8
	str r0, [r2]
	strh r4, [r2, 0xC]
	str r6, [r2, 0x10]
	ldrh r0, [r6, 0x22]
	strh r0, [r2, 0x1C]
	mov r1, r8
	cmp r1, 0
	bne _0801E850
	movs r3, 0x94
	lsls r3, 1
	adds r1, r2, r3
	movs r4, 0x8C
	lsls r4, 1
	adds r0, r2, r4
	b _0801E858
	.align 2, 0
_0801E84C: .4byte gUnknown_203B26C
_0801E850:
	movs r0, 0x94
	lsls r0, 1
	adds r1, r2, r0
	movs r0, 0
_0801E858:
	str r0, [r1]
	ldr r0, _0801E8B4
	bl sub_808DDD0
	ldr r2, _0801E8B8
	ldr r3, [r2]
	movs r4, 0x8C
	lsls r4, 1
	adds r1, r3, r4
	str r0, [r1]
	adds r4, 0x4
	adds r1, r3, r4
	ldr r0, [r0, 0x4]
	str r0, [r1]
	movs r1, 0x92
	lsls r1, 1
	adds r0, r3, r1
	movs r1, 0
	strb r1, [r0]
	ldr r0, [r2]
	ldr r3, _0801E8BC
	adds r0, r3
	strb r1, [r0]
	ldr r0, [r2]
	adds r4, 0xA
	adds r0, r4
	strb r1, [r0]
	ldr r2, [r2]
	movs r0, 0x90
	lsls r0, 1
	adds r1, r2, r0
	movs r0, 0x2
	strh r0, [r1]
	subs r3, 0x3
	adds r1, r2, r3
	movs r0, 0x8
	strh r0, [r1]
	movs r0, 0
	bl sub_801E968
	movs r0, 0x1
	pop {r3}
	mov r8, r3
	pop {r4-r6}
	pop {r1}
	bx r1
	.align 2, 0
_0801E8B4: .4byte 0x00000155
_0801E8B8: .4byte gUnknown_203B26C
_0801E8BC: .4byte 0x00000125
	thumb_func_end sub_801E80C

	thumb_func_start sub_801E8C0
sub_801E8C0:
	push {lr}
	ldr r0, _0801E8D8
	ldr r0, [r0]
	ldr r0, [r0, 0x4]
	cmp r0, 0x6
	bhi _0801E928
	lsls r0, 2
	ldr r1, _0801E8DC
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0801E8D8: .4byte gUnknown_203B26C
_0801E8DC: .4byte _0801E8E0
	.align 2, 0
_0801E8E0:
	.4byte _0801E8FC
	.4byte _0801E8FC
	.4byte _0801E902
	.4byte _0801E908
	.4byte _0801E90E
	.4byte _0801E91C
	.4byte _0801E924
_0801E8FC:
	bl sub_801ECBC
	b _0801E928
_0801E902:
	bl sub_801ED28
	b _0801E928
_0801E908:
	bl sub_801EDA4
	b _0801E928
_0801E90E:
	bl sub_801EDC0
	ldr r0, _0801E920
	ldr r0, [r0]
	ldr r0, [r0, 0x4]
	cmp r0, 0x5
	bne _0801E928
_0801E91C:
	movs r0, 0x3
	b _0801E92A
	.align 2, 0
_0801E920: .4byte gUnknown_203B26C
_0801E924:
	movs r0, 0x2
	b _0801E92A
_0801E928:
	movs r0, 0
_0801E92A:
	pop {r1}
	bx r1
	thumb_func_end sub_801E8C0

	thumb_func_start sub_801E930
sub_801E930:
	ldr r0, _0801E938
	ldr r0, [r0]
	ldrb r0, [r0, 0xE]
	bx lr
	.align 2, 0
_0801E938: .4byte gUnknown_203B26C
	thumb_func_end sub_801E930

	thumb_func_start sub_801E93C
sub_801E93C:
	push {r4,lr}
	ldr r4, _0801E964
	ldr r0, [r4]
	cmp r0, 0
	beq _0801E95C
	movs r1, 0x8C
	lsls r1, 1
	adds r0, r1
	ldr r0, [r0]
	bl CloseFile
	ldr r0, [r4]
	bl MemoryFree
	movs r0, 0
	str r0, [r4]
_0801E95C:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0801E964: .4byte gUnknown_203B26C
	thumb_func_end sub_801E93C

	thumb_func_start sub_801E968
sub_801E968:
	push {lr}
	ldr r1, _0801E97C
	ldr r1, [r1]
	str r0, [r1, 0x4]
	bl sub_801E980
	bl sub_801EA28
	pop {r0}
	bx r0
	.align 2, 0
_0801E97C: .4byte gUnknown_203B26C
	thumb_func_end sub_801E968

	thumb_func_start sub_801E980
sub_801E980:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	ldr r4, _0801E9D0
	ldr r0, [r4]
	movs r5, 0x96
	lsls r5, 1
	adds r0, r5
	bl sub_8006518
	ldr r0, [r4]
	ldr r0, [r0, 0x4]
	cmp r0, 0x2
	bne _0801E9DC
	bl sub_801EBC4
	ldr r1, [r4]
	movs r0, 0xA2
	lsls r0, 1
	adds r1, r0
	ldr r0, _0801E9D4
	ldm r0!, {r2,r3,r5}
	stm r1!, {r2,r3,r5}
	ldm r0!, {r2,r6,r7}
	stm r1!, {r2,r6,r7}
	ldr r2, [r4]
	movs r0, 0xAE
	lsls r0, 1
	adds r2, r0
	ldr r1, _0801E9D8
	ldm r1!, {r3,r5,r6}
	stm r2!, {r3,r5,r6}
	ldm r1!, {r3,r5,r7}
	stm r2!, {r3,r5,r7}
	ldr r1, [r4]
	adds r0, r1, r0
	adds r1, 0x28
	bl sub_8012CAC
	b _0801EA00
	.align 2, 0
_0801E9D0: .4byte gUnknown_203B26C
_0801E9D4: .4byte gUnknown_80DC11C
_0801E9D8: .4byte gUnknown_80DC134
_0801E9DC:
	mov r12, r4
	mov r8, r5
	ldr r4, _0801EA20
	movs r2, 0
	movs r3, 0x3
_0801E9E6:
	mov r6, r12
	ldr r1, [r6]
	adds r1, r2
	add r1, r8
	adds r0, r4, 0
	ldm r0!, {r5-r7}
	stm r1!, {r5-r7}
	ldm r0!, {r5-r7}
	stm r1!, {r5-r7}
	adds r2, 0x18
	subs r3, 0x1
	cmp r3, 0
	bge _0801E9E6
_0801EA00:
	bl sub_8004914
	ldr r0, _0801EA24
	ldr r0, [r0]
	movs r7, 0x96
	lsls r7, 1
	adds r0, r7
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_0801EA20: .4byte gUnknown_80DC11C
_0801EA24: .4byte gUnknown_203B26C
	thumb_func_end sub_801E980

	thumb_func_start sub_801EA28
sub_801EA28:
	push {r4,r5,lr}
	sub sp, 0x14
	ldr r1, _0801EA44
	ldr r0, [r1]
	ldr r0, [r0, 0x4]
	adds r4, r1, 0
	cmp r0, 0x4
	bls _0801EA3A
	b _0801EBB8
_0801EA3A:
	lsls r0, 2
	ldr r1, _0801EA48
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0801EA44: .4byte gUnknown_203B26C
_0801EA48: .4byte _0801EA4C
	.align 2, 0
_0801EA4C:
	.4byte _0801EA60
	.4byte _0801EA80
	.4byte _0801EA8A
	.4byte _0801EAB4
	.4byte _0801EACA
_0801EA60:
	ldr r0, [r4]
	movs r2, 0xC
	ldrsh r1, [r0, r2]
	ldr r2, [r0, 0x10]
	ldr r0, _0801EA7C
	str r0, [sp]
	movs r0, 0
	str r0, [sp, 0x4]
	movs r0, 0x2
	movs r3, 0
	bl sub_801EE10
	b _0801EBB8
	.align 2, 0
_0801EA7C: .4byte gUnknown_80DC164
_0801EA80:
	movs r0, 0x1
	movs r1, 0
	bl sub_801F1B0
	b _0801EBB8
_0801EA8A:
	movs r0, 0
	bl sub_801F280
	ldr r0, _0801EAB0
	ldr r2, [r0]
	adds r0, r2, 0
	adds r0, 0x78
	adds r1, r2, 0
	adds r1, 0x28
	adds r3, r2, 0
	adds r3, 0x68
	ldr r2, [r2, 0x24]
	str r2, [sp]
	movs r2, 0x2
	str r2, [sp, 0x4]
	movs r2, 0
	bl sub_8012D60
	b _0801EBB8
	.align 2, 0
_0801EAB0: .4byte gUnknown_203B26C
_0801EAB4:
	ldr r2, [r4]
	ldr r0, [r2, 0x20]
	ldr r1, [r2, 0x10]
	adds r2, 0x14
	bl sub_8093560
	ldr r0, [r4]
	adds r0, 0x14
	bl sub_801F808
	b _0801EBB8
_0801EACA:
	bl sub_801EC7C
	ldr r4, _0801EAF8
	ldr r5, _0801EAFC
	ldr r0, [r5]
	ldrh r1, [r0, 0x1C]
	adds r0, r4, 0
	bl sub_8092C84
	adds r4, 0x50
	ldr r0, [r5]
	ldrh r1, [r0, 0x1E]
	adds r0, r4, 0
	bl sub_8092C84
	ldr r2, [r5]
	ldr r3, [r2]
	cmp r3, 0x1
	bls _0801EB00
	cmp r3, 0x2
	beq _0801EB68
	b _0801EBB8
	.align 2, 0
_0801EAF8: .4byte gUnknown_202DF98
_0801EAFC: .4byte gUnknown_203B26C
_0801EB00:
	ldrb r4, [r2, 0xE]
	cmp r4, 0
	beq _0801EB38
	ldr r1, _0801EB34
	movs r0, 0x64
	muls r0, r3
	adds r1, 0x30
	adds r0, r1
	ldr r0, [r0]
	adds r3, r2, 0
	adds r3, 0x28
	adds r1, r2, 0
	adds r1, 0x68
	str r1, [sp]
	movs r1, 0x4
	str r1, [sp, 0x4]
	movs r1, 0
	str r1, [sp, 0x8]
	movs r4, 0x94
	lsls r4, 1
	adds r1, r2, r4
	ldr r1, [r1]
	str r1, [sp, 0xC]
	movs r1, 0xC
	b _0801EB86
	.align 2, 0
_0801EB34: .4byte gUnknown_80D8888
_0801EB38:
	ldr r1, _0801EB64
	movs r0, 0x64
	muls r0, r3
	adds r1, 0x2C
	adds r0, r1
	ldr r0, [r0]
	adds r3, r2, 0
	adds r3, 0x28
	adds r1, r2, 0
	adds r1, 0x68
	str r1, [sp]
	movs r1, 0x4
	str r1, [sp, 0x4]
	str r4, [sp, 0x8]
	movs r4, 0x94
	lsls r4, 1
	adds r1, r2, r4
	ldr r1, [r1]
	str r1, [sp, 0xC]
	movs r1, 0xC
	b _0801EB86
	.align 2, 0
_0801EB64: .4byte gUnknown_80D8888
_0801EB68:
	ldrb r4, [r2, 0xE]
	cmp r4, 0
	beq _0801EB98
	ldr r0, _0801EB94
	adds r3, r2, 0
	adds r3, 0x28
	adds r1, r2, 0
	adds r1, 0x68
	str r1, [sp]
	movs r1, 0x4
	str r1, [sp, 0x4]
	movs r1, 0
	str r1, [sp, 0x8]
	str r1, [sp, 0xC]
	movs r1, 0x20
_0801EB86:
	str r1, [sp, 0x10]
	movs r1, 0
	movs r2, 0x5
	bl sub_8014248
	b _0801EBB8
	.align 2, 0
_0801EB94: .4byte gUnknown_80DC1A0
_0801EB98:
	ldr r0, _0801EBC0
	adds r3, r2, 0
	adds r3, 0x28
	adds r1, r2, 0
	adds r1, 0x68
	str r1, [sp]
	movs r1, 0x4
	str r1, [sp, 0x4]
	str r4, [sp, 0x8]
	str r4, [sp, 0xC]
	movs r1, 0x20
	str r1, [sp, 0x10]
	movs r1, 0
	movs r2, 0x5
	bl sub_8014248
_0801EBB8:
	add sp, 0x14
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_0801EBC0: .4byte gUnknown_80DC1FC
	thumb_func_end sub_801EA28

	thumb_func_start sub_801EBC4
sub_801EBC4:
	push {r4,r5,lr}
	movs r5, 0
	ldr r4, _0801EC48
	ldr r0, [r4]
	adds r0, 0x68
	movs r1, 0
	movs r2, 0x10
	bl MemoryFill16
	ldr r1, [r4]
	ldr r0, _0801EC4C
	str r0, [r1, 0x28]
	movs r0, 0x2
	str r0, [r1, 0x2C]
	ldrh r0, [r1, 0x1E]
	ldr r1, [r1, 0x10]
	bl sub_80933A0
	lsls r0, 24
	cmp r0, 0
	beq _0801EBF6
	ldr r0, [r4]
	ldr r0, [r0, 0x20]
	cmp r0, 0x3
	ble _0801EBFE
_0801EBF6:
	ldr r0, [r4]
	adds r0, 0x68
	movs r1, 0x1
	strh r1, [r0]
_0801EBFE:
	adds r5, 0x1
	ldr r4, _0801EC48
	ldr r0, [r4]
	mov r12, r0
	lsls r1, r5, 3
	mov r3, r12
	adds r3, 0x28
	adds r2, r3, r1
	ldr r0, _0801EC50
	ldr r0, [r0]
	str r0, [r2]
	mov r2, r12
	adds r2, 0x2C
	adds r1, r2, r1
	movs r0, 0x3
	str r0, [r1]
	adds r5, 0x1
	lsls r1, r5, 3
	adds r3, r1
	movs r0, 0
	str r0, [r3]
	adds r2, r1
	movs r0, 0x1
	str r0, [r2]
	movs r3, 0
	cmp r3, r5
	bge _0801EC76
	mov r0, r12
	adds r0, 0x68
	ldrh r0, [r0]
	cmp r0, 0
	bne _0801EC54
	mov r1, r12
	ldr r0, [r1, 0x2C]
	str r0, [r1, 0x24]
	b _0801EC76
	.align 2, 0
_0801EC48: .4byte gUnknown_203B26C
_0801EC4C: .4byte gUnknown_80DC230
_0801EC50: .4byte gUnknown_80D4970
_0801EC54:
	adds r3, 0x1
	cmp r3, r5
	bge _0801EC76
	ldr r2, [r4]
	lsls r0, r3, 1
	adds r1, r2, 0
	adds r1, 0x68
	adds r1, r0
	ldrh r0, [r1]
	cmp r0, 0
	bne _0801EC54
	lsls r0, r3, 3
	adds r1, r2, 0
	adds r1, 0x2C
	adds r1, r0
	ldr r0, [r1]
	str r0, [r2, 0x24]
_0801EC76:
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_801EBC4

	thumb_func_start sub_801EC7C
sub_801EC7C:
	push {r4,lr}
	ldr r4, _0801ECB0
	ldr r0, [r4]
	adds r0, 0x68
	movs r1, 0
	movs r2, 0x10
	bl MemoryFill16
	ldr r1, [r4]
	movs r3, 0
	ldr r0, _0801ECB4
	ldr r0, [r0]
	str r0, [r1, 0x28]
	movs r0, 0x4
	str r0, [r1, 0x2C]
	movs r2, 0x1
	ldr r0, _0801ECB8
	ldr r0, [r0]
	str r0, [r1, 0x30]
	movs r0, 0x5
	str r0, [r1, 0x34]
	str r3, [r1, 0x38]
	str r2, [r1, 0x3C]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0801ECB0: .4byte gUnknown_203B26C
_0801ECB4: .4byte gUnknown_80D4920
_0801ECB8: .4byte gUnknown_80D4928
	thumb_func_end sub_801EC7C

	thumb_func_start sub_801ECBC
sub_801ECBC:
	push {lr}
	movs r0, 0x1
	bl sub_801EF38
	cmp r0, 0x3
	beq _0801ECD8
	cmp r0, 0x3
	bhi _0801ECD2
	cmp r0, 0x2
	beq _0801ED18
	b _0801ED22
_0801ECD2:
	cmp r0, 0x4
	beq _0801ECF8
	b _0801ED22
_0801ECD8:
	bl sub_801F194
	ldr r1, _0801ECF4
	ldr r2, [r1]
	str r0, [r2, 0x20]
	ldr r1, [r2, 0x10]
	lsls r0, 3
	adds r1, r0
	ldrh r0, [r1, 0x2]
	strh r0, [r2, 0x1E]
	movs r0, 0x2
	bl sub_801E968
	b _0801ED22
	.align 2, 0
_0801ECF4: .4byte gUnknown_203B26C
_0801ECF8:
	bl sub_801F194
	ldr r1, _0801ED14
	ldr r2, [r1]
	str r0, [r2, 0x20]
	ldr r1, [r2, 0x10]
	lsls r0, 3
	adds r1, r0
	ldrh r0, [r1, 0x2]
	strh r0, [r2, 0x1E]
	movs r0, 0x3
	bl sub_801E968
	b _0801ED22
	.align 2, 0
_0801ED14: .4byte gUnknown_203B26C
_0801ED18:
	bl sub_801F214
	movs r0, 0x6
	bl sub_801E968
_0801ED22:
	pop {r0}
	bx r0
	thumb_func_end sub_801ECBC

	thumb_func_start sub_801ED28
sub_801ED28:
	push {r4,lr}
	sub sp, 0x4
	movs r0, 0
	str r0, [sp]
	bl sub_801EF38
	ldr r4, _0801ED60
	ldr r0, [r4]
	adds r0, 0x78
	bl sub_8012FD8
	lsls r0, 24
	cmp r0, 0
	bne _0801ED4E
	ldr r0, [r4]
	adds r0, 0x78
	mov r1, sp
	bl sub_8013114
_0801ED4E:
	ldr r0, [sp]
	cmp r0, 0x2
	beq _0801ED74
	cmp r0, 0x2
	bgt _0801ED64
	cmp r0, 0x1
	beq _0801ED6C
	b _0801ED9A
	.align 2, 0
_0801ED60: .4byte gUnknown_203B26C
_0801ED64:
	cmp r0, 0x3
	beq _0801ED94
	cmp r0, 0x5
	bne _0801ED9A
_0801ED6C:
	movs r0, 0x1
	bl sub_801E968
	b _0801ED9A
_0801ED74:
	ldr r0, _0801ED90
	bl sub_8011988
	ldr r1, [r4]
	ldr r0, [r1, 0x20]
	ldr r1, [r1, 0x10]
	bl sub_80934B0
	ldr r1, [r4]
	strb r0, [r1, 0xE]
	movs r0, 0x4
	bl sub_801E968
	b _0801ED9A
	.align 2, 0
_0801ED90: .4byte 0x00000133
_0801ED94:
	movs r0, 0x3
	bl sub_801E968
_0801ED9A:
	add sp, 0x4
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_801ED28

	thumb_func_start sub_801EDA4
sub_801EDA4:
	push {lr}
	bl sub_801F890
	cmp r0, 0x1
	bls _0801EDBC
	cmp r0, 0x3
	bhi _0801EDBC
	bl sub_801F8D0
	movs r0, 0x1
	bl sub_801E968
_0801EDBC:
	pop {r0}
	bx r0
	thumb_func_end sub_801EDA4

	thumb_func_start sub_801EDC0
sub_801EDC0:
	push {r4,lr}
	sub sp, 0x4
	mov r0, sp
	bl sub_80144A4
	cmp r0, 0
	bne _0801EE06
	ldr r0, [sp]
	cmp r0, 0x4
	beq _0801EDE4
	cmp r0, 0x4
	bgt _0801EDDE
	cmp r0, 0x1
	beq _0801EE00
	b _0801EE06
_0801EDDE:
	cmp r0, 0x5
	beq _0801EE00
	b _0801EE06
_0801EDE4:
	bl sub_801F214
	ldr r4, _0801EDFC
	ldr r1, [r4]
	ldr r0, [r1, 0x10]
	ldr r1, [r1, 0x20]
	bl sub_8093CF8
	ldr r1, [r4]
	movs r0, 0x5
	str r0, [r1, 0x4]
	b _0801EE06
	.align 2, 0
_0801EDFC: .4byte gUnknown_203B26C
_0801EE00:
	movs r0, 0x1
	bl sub_801E968
_0801EE06:
	add sp, 0x4
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_801EDC0

	thumb_func_start sub_801EE10
sub_801EE10:
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	adds r6, r0, 0
	mov r9, r2
	adds r4, r3, 0
	ldr r0, [sp, 0x20]
	mov r8, r0
	lsls r1, 16
	asrs r7, r1, 16
	lsls r4, 24
	lsrs r4, 24
	ldr r5, _0801EF28
	movs r0, 0xBC
	movs r1, 0x8
	bl MemoryAlloc
	str r0, [r5]
	movs r2, 0
	strb r4, [r0, 0x4]
	ldr r0, [r5]
	movs r1, 0x1
	strb r1, [r0, 0x5]
	ldr r0, [r5]
	strb r1, [r0, 0x6]
	ldr r0, [r5]
	strb r1, [r0, 0x7]
	ldr r0, [r5]
	str r6, [r0]
	cmp r6, 0x1
	bls _0801EE5E
	cmp r6, 0x3
	bhi _0801EE5E
	strb r2, [r0, 0x5]
	ldr r0, [r5]
	strb r2, [r0, 0x6]
	ldr r0, [r5]
	strb r2, [r0, 0x7]
_0801EE5E:
	ldr r4, _0801EF28
	ldr r3, [r4]
	ldr r2, _0801EF2C
	movs r0, 0x58
	adds r1, r7, 0
	muls r1, r0
	ldr r0, [r2]
	adds r0, r1
	str r0, [r3, 0x8]
	ldrb r0, [r0, 0x2]
	strb r0, [r3, 0xC]
	ldr r0, [r4]
	mov r1, r9
	str r1, [r0, 0x10]
	adds r0, 0xB8
	ldr r1, [sp, 0x1C]
	str r1, [r0]
	bl sub_801F3F8
	adds r5, r0, 0
	adds r6, r5, 0
	cmp r5, 0x4
	bge _0801EE8E
	movs r6, 0x4
_0801EE8E:
	ldr r0, [r4]
	adds r0, 0x58
	bl sub_8006518
	ldr r1, [r4]
	mov r2, r8
	str r2, [r1, 0x50]
	lsls r0, r2, 1
	add r0, r8
	lsls r0, 3
	adds r1, r0
	adds r1, 0x58
	ldr r0, _0801EF30
	ldm r0!, {r2,r3,r7}
	stm r1!, {r2,r3,r7}
	ldm r0!, {r2,r3,r7}
	stm r1!, {r2,r3,r7}
	ldr r0, [r4]
	adds r0, 0xB8
	ldr r0, [r0]
	cmp r0, 0
	beq _0801EED8
	mov r0, r8
	bl sub_8006544
	ldr r1, [r4]
	str r0, [r1, 0x54]
	lsls r2, r0, 1
	adds r2, r0
	lsls r2, 3
	adds r1, r2
	adds r1, 0x58
	ldr r0, _0801EF34
	ldm r0!, {r2,r3,r7}
	stm r1!, {r2,r3,r7}
	ldm r0!, {r2,r3,r7}
	stm r1!, {r2,r3,r7}
_0801EED8:
	ldr r0, [r4]
	ldr r2, [r0, 0x50]
	lsls r1, r2, 1
	adds r1, r2
	lsls r1, 3
	adds r1, 0x58
	adds r0, r1
	adds r1, r6, 0
	bl sub_8012D08
	bl sub_8004914
	ldr r0, [r4]
	adds r0, 0x58
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	ldr r0, [r4]
	adds r0, 0x1C
	adds r1, r5, 0
	adds r2, r5, 0
	mov r3, r8
	bl sub_8013818
	ldr r0, [r4]
	adds r0, 0x1C
	movs r1, 0
	bl sub_8013780
	movs r0, 0x1
	bl sub_801F280
	movs r0, 0x1
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r1}
	bx r1
	.align 2, 0
_0801EF28: .4byte gUnknown_203B270
_0801EF2C: .4byte gUnknown_203B45C
_0801EF30: .4byte gUnknown_80DC25C
_0801EF34: .4byte gUnknown_80DC274
	thumb_func_end sub_801EE10

	thumb_func_start sub_801EF38
sub_801EF38:
	push {r4-r7,lr}
	lsls r0, 24
	movs r7, 0
	cmp r0, 0
	bne _0801EF54
	ldr r0, _0801EF50
	ldr r0, [r0]
	adds r0, 0x1C
	bl sub_8013660
	b _0801F18C
	.align 2, 0
_0801EF50: .4byte gUnknown_203B270
_0801EF54:
	ldr r0, _0801EF70
	ldr r0, [r0]
	adds r0, 0x1C
	bl GetKeyPress
	subs r0, 0x1
	cmp r0, 0xC
	bls _0801EF66
	b _0801F12E
_0801EF66:
	lsls r0, 2
	ldr r1, _0801EF74
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0801EF70: .4byte gUnknown_203B270
_0801EF74: .4byte _0801EF78
	.align 2, 0
_0801EF78:
	.4byte _0801EFB6
	.4byte _0801EFAC
	.4byte _0801F0E4
	.4byte _0801EFC0
	.4byte _0801F12E
	.4byte _0801F12E
	.4byte _0801EFE4
	.4byte _0801EFCA
	.4byte _0801F12E
	.4byte _0801F12E
	.4byte _0801F074
	.4byte _0801F04C
	.4byte _0801F018
_0801EFAC:
	movs r0, 0x1
	bl sub_80119D4
	movs r0, 0x2
	b _0801F18E
_0801EFB6:
	movs r0, 0
	bl sub_80119D4
	movs r0, 0x3
	b _0801F18E
_0801EFC0:
	movs r0, 0x4
	bl sub_80119D4
	movs r0, 0x4
	b _0801F18E
_0801EFCA:
	ldr r5, _0801EFE0
	ldr r0, [r5]
	movs r1, 0x34
	ldrsh r6, [r0, r1]
	adds r4, r0, 0
	adds r4, 0x1C
	ldr r0, [r0, 0x10]
	adds r1, r6, 0
	bl sub_8092E54
	b _0801EFF8
	.align 2, 0
_0801EFE0: .4byte gUnknown_203B270
_0801EFE4:
	ldr r5, _0801F014
	ldr r0, [r5]
	movs r1, 0x34
	ldrsh r6, [r0, r1]
	adds r4, r0, 0
	adds r4, 0x1C
	ldr r0, [r0, 0x10]
	adds r1, r6, 0
	bl sub_8092EEC
_0801EFF8:
	adds r1, r0, 0
	adds r0, r4, 0
	bl sub_8013780
	ldr r0, [r5]
	movs r2, 0x34
	ldrsh r0, [r0, r2]
	cmp r6, r0
	bne _0801F00C
	b _0801F12E
_0801F00C:
	movs r0, 0x3
	bl sub_80119D4
	b _0801F12E
	.align 2, 0
_0801F014: .4byte gUnknown_203B270
_0801F018:
	ldr r0, _0801F048
	ldr r2, [r0]
	ldrb r1, [r2, 0x5]
	adds r5, r0, 0
	cmp r1, 0
	bne _0801F026
	b _0801F12E
_0801F026:
	movs r0, 0x34
	ldrsh r4, [r2, r0]
	ldr r0, [r2, 0x10]
	adds r1, r4, 0
	bl sub_809309C
_0801F032:
	ldr r1, [r5]
	strh r0, [r1, 0x34]
	lsls r0, 16
	asrs r0, 16
	cmp r4, r0
	beq _0801F06C
	movs r0, 0x3
	bl sub_80119D4
	b _0801F182
	.align 2, 0
_0801F048: .4byte gUnknown_203B270
_0801F04C:
	ldr r0, _0801F068
	ldr r2, [r0]
	ldrb r1, [r2, 0x5]
	adds r5, r0, 0
	cmp r1, 0
	beq _0801F12E
	movs r1, 0x34
	ldrsh r4, [r2, r1]
	ldr r0, [r2, 0x10]
	adds r1, r4, 0
	bl sub_809324C
	b _0801F032
	.align 2, 0
_0801F068: .4byte gUnknown_203B270
_0801F06C:
	movs r0, 0x2
	bl sub_80119D4
	b _0801F182
_0801F074:
	ldr r0, _0801F0C8
	ldr r2, [r0]
	ldrb r1, [r2, 0x6]
	adds r5, r0, 0
	cmp r1, 0
	beq _0801F12E
	ldr r0, _0801F0CC
	ldr r0, [r0]
	movs r1, 0x98
	lsls r1, 2
	adds r0, r1
	ldr r0, [r0]
	cmp r0, 0x95
	ble _0801F0D0
	movs r1, 0x34
	ldrsh r0, [r2, r1]
	ldr r1, [r2, 0x10]
	bl sub_8093318
	lsls r0, 24
	cmp r0, 0
	beq _0801F0D0
	ldr r1, [r5]
	movs r2, 0x34
	ldrsh r0, [r1, r2]
	ldr r1, [r1, 0x10]
	bl sub_8093400
	movs r0, 0x6
	bl sub_80119D4
	movs r7, 0x1
	ldr r1, [r5]
	ldrb r0, [r1, 0x4]
	cmp r0, 0
	bne _0801F12E
	strb r7, [r1, 0x4]
	movs r0, 0xA6
	lsls r0, 1
	bl sub_8011988
	b _0801F12E
	.align 2, 0
_0801F0C8: .4byte gUnknown_203B270
_0801F0CC: .4byte gUnknown_203B460
_0801F0D0:
	ldr r0, _0801F0E0
	ldr r1, [r0]
	movs r2, 0x34
	ldrsh r0, [r1, r2]
	ldr r1, [r1, 0x10]
	bl sub_8093468
	b _0801F0FE
	.align 2, 0
_0801F0E0: .4byte gUnknown_203B270
_0801F0E4:
	ldr r0, _0801F10C
	ldr r1, [r0]
	ldrb r0, [r1, 0x7]
	cmp r0, 0
	beq _0801F12E
	ldrb r0, [r1, 0xC]
	cmp r0, 0
	beq _0801F110
	movs r2, 0x34
	ldrsh r0, [r1, r2]
	ldr r1, [r1, 0x10]
	bl sub_80934DC
_0801F0FE:
	lsls r0, 24
	cmp r0, 0
	bne _0801F120
	movs r0, 0x2
	bl sub_80119D4
	b _0801F12E
	.align 2, 0
_0801F10C: .4byte gUnknown_203B270
_0801F110:
	movs r2, 0x34
	ldrsh r0, [r1, r2]
	ldr r1, [r1, 0x10]
	bl sub_8093544
	lsls r0, 24
	cmp r0, 0
	beq _0801F128
_0801F120:
	movs r0, 0x6
	bl sub_80119D4
	b _0801F182
_0801F128:
	movs r0, 0x2
	bl sub_80119D4
_0801F12E:
	cmp r7, 0
	bne _0801F182
	movs r3, 0
	ldr r5, _0801F160
	movs r4, 0x1
_0801F138:
	ldr r2, [r5]
	lsls r0, r3, 3
	ldr r1, [r2, 0x10]
	adds r1, r0
	ldrb r1, [r1]
	adds r0, r4, 0
	ands r0, r1
	cmp r0, 0
	beq _0801F16C
	movs r0, 0x2
	ands r0, r1
	lsls r0, 24
	lsrs r1, r0, 24
	cmp r1, 0
	beq _0801F164
	adds r0, r2, 0
	adds r0, 0x14
	adds r0, r3
	strb r4, [r0]
	b _0801F16C
	.align 2, 0
_0801F160: .4byte gUnknown_203B270
_0801F164:
	adds r0, r2, 0
	adds r0, 0x14
	adds r0, r3
	strb r1, [r0]
_0801F16C:
	adds r3, 0x1
	cmp r3, 0x7
	ble _0801F138
	ldr r1, [r5]
	adds r0, r1, 0
	adds r0, 0x1C
	adds r1, 0x14
	bl AddMenuCursorSprite_
	cmp r7, 0
	beq _0801F18C
_0801F182:
	movs r0, 0x1
	bl sub_801F280
	movs r0, 0x1
	b _0801F18E
_0801F18C:
	movs r0, 0
_0801F18E:
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_801EF38

	thumb_func_start sub_801F194
sub_801F194:
	ldr r0, _0801F1A0
	ldr r0, [r0]
	movs r1, 0x34
	ldrsh r0, [r0, r1]
	bx lr
	.align 2, 0
_0801F1A0: .4byte gUnknown_203B270
	thumb_func_end sub_801F194

	thumb_func_start sub_801F1A4
sub_801F1A4:
	ldr r0, _0801F1AC
	ldr r0, [r0]
	ldrb r0, [r0, 0x4]
	bx lr
	.align 2, 0
_0801F1AC: .4byte gUnknown_203B270
	thumb_func_end sub_801F1A4

	thumb_func_start sub_801F1B0
sub_801F1B0:
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r5, r0, 24
	lsls r1, 24
	lsrs r1, 24
	ldr r4, _0801F210
	ldr r2, [r4]
	ldrb r0, [r2, 0x4]
	cmp r0, 0
	bne _0801F1C6
	strb r1, [r2, 0x4]
_0801F1C6:
	bl sub_8004914
	ldr r0, [r4]
	adds r0, 0x58
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	bl sub_801F3F8
	adds r1, r0, 0
	ldr r0, [r4]
	strh r1, [r0, 0x3E]
	adds r0, 0x1C
	bl sub_8013984
	ldr r1, [r4]
	ldr r0, [r1, 0x10]
	movs r2, 0x34
	ldrsh r1, [r1, r2]
	bl sub_8092F4C
	ldr r1, [r4]
	strh r0, [r1, 0x34]
	movs r0, 0x1
	bl sub_801F280
	cmp r5, 0
	beq _0801F208
	ldr r0, [r4]
	adds r0, 0x1C
	bl AddMenuCursorSprite
_0801F208:
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_0801F210: .4byte gUnknown_203B270
	thumb_func_end sub_801F1B0

	thumb_func_start sub_801F214
sub_801F214:
	push {r4-r6,lr}
	ldr r4, _0801F278
	ldr r2, [r4]
	cmp r2, 0
	beq _0801F272
	ldr r0, [r2, 0x50]
	lsls r1, r0, 1
	adds r1, r0
	lsls r1, 3
	adds r1, r2, r1
	ldr r3, _0801F27C
	adds r1, 0x58
	adds r0, r3, 0
	ldm r0!, {r2,r5,r6}
	stm r1!, {r2,r5,r6}
	ldm r0!, {r2,r5,r6}
	stm r1!, {r2,r5,r6}
	ldr r2, [r4]
	adds r0, r2, 0
	adds r0, 0xB8
	ldr r0, [r0]
	cmp r0, 0
	beq _0801F258
	ldr r0, [r2, 0x54]
	lsls r1, r0, 1
	adds r1, r0
	lsls r1, 3
	adds r1, r2, r1
	adds r1, 0x58
	adds r0, r3, 0
	ldm r0!, {r2,r3,r5}
	stm r1!, {r2,r3,r5}
	ldm r0!, {r2,r3,r6}
	stm r1!, {r2,r3,r6}
_0801F258:
	bl sub_8004914
	ldr r0, [r4]
	adds r0, 0x58
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	ldr r0, [r4]
	bl MemoryFree
	movs r0, 0
	str r0, [r4]
_0801F272:
	pop {r4-r6}
	pop {r0}
	bx r0
	.align 2, 0
_0801F278: .4byte gUnknown_203B270
_0801F27C: .4byte gUnknown_80DC240
	thumb_func_end sub_801F214

	thumb_func_start sub_801F280
sub_801F280:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x28
	lsls r0, 24
	lsrs r0, 24
	mov r10, r0
	ldr r4, _0801F30C
	ldr r0, [r4]
	ldr r0, [r0, 0x50]
	bl sub_8008C54
	ldr r0, [r4]
	ldr r0, [r0, 0x50]
	bl sub_80073B8
	ldr r0, [r4]
	ldr r1, [r0, 0x8]
	adds r1, 0x4C
	add r0, sp, 0x4
	movs r2, 0xA
	bl sub_80922B4
	ldr r0, _0801F310
	add r1, sp, 0x4
	bl strcpy
	ldr r2, _0801F314
	ldr r0, [r4]
	ldr r3, [r0, 0x50]
	movs r0, 0
	str r0, [sp]
	movs r0, 0xC
	movs r1, 0
	bl sub_8014FF0
	movs r7, 0
	ldr r0, [r4]
	movs r1, 0x36
	ldrsh r0, [r0, r1]
	cmp r7, r0
	bge _0801F394
	add r5, sp, 0x18
	mov r8, r4
	movs r0, 0x1
	mov r9, r0
_0801F2E0:
	adds r0, r5, 0
	movs r1, 0
	movs r2, 0xC
	bl memset
	movs r0, 0x6A
	str r0, [r5, 0x4]
	mov r1, r8
	ldr r2, [r1]
	lsls r1, r7, 3
	ldr r0, [r2, 0x10]
	adds r4, r0, r1
	ldrb r1, [r4]
	mov r0, r9
	ands r0, r1
	cmp r0, 0
	beq _0801F386
	ldrb r0, [r2, 0xC]
	cmp r0, 0
	beq _0801F318
	movs r0, 0x2
	b _0801F31A
	.align 2, 0
_0801F30C: .4byte gUnknown_203B270
_0801F310: .4byte gUnknown_202DF98
_0801F314: .4byte gUnknown_80DC28C
_0801F318:
	movs r0, 0x4
_0801F31A:
	str r0, [sp, 0x18]
	mov r1, r8
	ldr r0, [r1]
	ldrb r0, [r0, 0x6]
	cmp r0, 0
	beq _0801F328
	mov r0, r9
_0801F328:
	strb r0, [r5, 0x9]
	cmp r7, 0x3
	ble _0801F332
	mov r1, r9
	strb r1, [r5, 0x8]
_0801F332:
	ldr r0, _0801F3EC
	adds r1, r4, 0
	adds r2, r5, 0
	bl sub_80928A0
	ldr r2, _0801F3F0
	ldr r0, [r2]
	adds r0, 0x1C
	adds r1, r7, 0
	str r2, [sp, 0x24]
	bl sub_8013800
	adds r6, r0, 0
	ldrb r1, [r4]
	movs r0, 0x2
	ands r0, r1
	movs r4, 0xD
	ldr r2, [sp, 0x24]
	cmp r0, 0
	bne _0801F372
	movs r4, 0x8
	cmp r7, 0
	beq _0801F372
	ldr r0, [r2]
	ldr r0, [r0, 0x50]
	subs r2, r6, 0x2
	movs r1, 0x7
	str r1, [sp]
	movs r1, 0xC
	movs r3, 0x78
	bl sub_800792C
_0801F372:
	mov r1, r8
	ldr r0, [r1]
	ldr r3, [r0, 0x50]
	movs r0, 0
	str r0, [sp]
	adds r0, r4, 0
	adds r1, r6, 0
	ldr r2, _0801F3F4
	bl sub_8014FF0
_0801F386:
	adds r7, 0x1
	mov r1, r8
	ldr r0, [r1]
	movs r1, 0x36
	ldrsh r0, [r0, r1]
	cmp r7, r0
	blt _0801F2E0
_0801F394:
	ldr r4, _0801F3F0
	ldr r0, [r4]
	ldr r0, [r0, 0x50]
	bl sub_80073E0
	ldr r1, [r4]
	adds r0, r1, 0
	adds r0, 0xB8
	ldr r0, [r0]
	cmp r0, 0
	beq _0801F3DC
	mov r0, r10
	cmp r0, 0
	beq _0801F3DC
	ldr r0, [r1, 0x54]
	bl sub_8008C54
	ldr r0, [r4]
	ldr r0, [r0, 0x54]
	bl sub_80073B8
	ldr r1, [r4]
	adds r0, r1, 0
	adds r0, 0xB8
	ldr r2, [r0]
	ldr r3, [r1, 0x54]
	movs r0, 0
	str r0, [sp]
	movs r0, 0x8
	movs r1, 0
	bl sub_8014FF0
	ldr r0, [r4]
	ldr r0, [r0, 0x54]
	bl sub_80073E0
_0801F3DC:
	add sp, 0x28
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_0801F3EC: .4byte gUnknown_202DE58
_0801F3F0: .4byte gUnknown_203B270
_0801F3F4: .4byte gUnknown_80DC2A0
	thumb_func_end sub_801F280

	thumb_func_start sub_801F3F8
sub_801F3F8:
	push {r4,r5,lr}
	movs r4, 0
	ldr r0, _0801F424
	ldr r0, [r0]
	movs r5, 0x1
	ldr r2, [r0, 0x10]
	movs r3, 0x7
_0801F406:
	ldrb r1, [r2]
	adds r0, r5, 0
	ands r0, r1
	cmp r0, 0
	beq _0801F412
	adds r4, 0x1
_0801F412:
	adds r2, 0x8
	subs r3, 0x1
	cmp r3, 0
	bge _0801F406
	adds r0, r4, 0
	pop {r4,r5}
	pop {r1}
	bx r1
	.align 2, 0
_0801F424: .4byte gUnknown_203B270
	thumb_func_end sub_801F3F8

	thumb_func_start sub_801F428
sub_801F428:
	push {r4-r6,lr}
	mov r6, r9
	mov r5, r8
	push {r5,r6}
	adds r4, r0, 0
	mov r9, r1
	lsls r4, 16
	asrs r4, 16
	ldr r5, _0801F50C
	movs r0, 0xFA
	lsls r0, 2
	movs r1, 0x8
	bl MemoryAlloc
	str r0, [r5]
	ldr r3, _0801F510
	movs r1, 0x58
	adds r2, r4, 0
	muls r2, r1
	ldr r1, [r3]
	adds r1, r2
	str r1, [r0]
	adds r1, r0, 0
	adds r1, 0x8
	str r1, [r0, 0x4]
	movs r4, 0xDF
	lsls r4, 2
	adds r1, r0, r4
	mov r2, r9
	str r2, [r1]
	movs r6, 0xE0
	lsls r6, 2
	adds r2, r0, r6
	mov r3, r9
	lsls r1, r3, 1
	add r1, r9
	lsls r1, 3
	movs r3, 0xE1
	lsls r3, 2
	mov r8, r3
	add r1, r8
	adds r1, r0, r1
	str r1, [r2]
	add r0, r8
	bl sub_8006518
	ldr r1, [r5]
	adds r4, r1, r4
	ldr r2, [r4]
	lsls r0, r2, 1
	adds r0, r2
	lsls r0, 3
	adds r1, r0
	add r1, r8
	ldr r0, _0801F514
	ldm r0!, {r2-r4}
	stm r1!, {r2-r4}
	ldm r0!, {r2-r4}
	stm r1!, {r2-r4}
	ldr r1, [r5]
	adds r6, r1, r6
	ldr r0, [r6]
	movs r4, 0xF9
	lsls r4, 2
	adds r1, r4
	str r1, [r0, 0x14]
	movs r2, 0
	movs r0, 0x1
	strb r0, [r1]
	ldr r0, [r5]
	ldr r1, _0801F518
	adds r0, r1
	strb r2, [r0]
	ldr r0, [r5]
	ldr r3, _0801F51C
	adds r0, r3
	movs r1, 0xC
	strb r1, [r0]
	ldr r0, [r5]
	adds r4, 0x3
	adds r0, r4
	strb r2, [r0]
	bl sub_8004914
	ldr r0, [r5]
	add r0, r8
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	ldr r4, [r5]
	movs r0, 0xD2
	lsls r0, 2
	adds r4, r0
	bl sub_801F7E4
	adds r1, r0, 0
	adds r0, r4, 0
	movs r2, 0x4
	mov r3, r9
	bl sub_8013818
	bl sub_801F690
	bl sub_801F700
	movs r0, 0x1
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r6}
	pop {r1}
	bx r1
	.align 2, 0
_0801F50C: .4byte gUnknown_203B274
_0801F510: .4byte gUnknown_203B45C
_0801F514: .4byte gUnknown_80DC2C4
_0801F518: .4byte 0x000003e5
_0801F51C: .4byte 0x000003e6
	thumb_func_end sub_801F428

	thumb_func_start sub_801F520
sub_801F520:
	push {lr}
	lsls r0, 24
	cmp r0, 0
	bne _0801F540
	ldr r0, _0801F53C
	ldr r0, [r0]
	movs r1, 0xD2
	lsls r1, 2
	adds r0, r1
	bl sub_8013660
	movs r0, 0
	b _0801F5AE
	.align 2, 0
_0801F53C: .4byte gUnknown_203B274
_0801F540:
	ldr r0, _0801F55C
	ldr r0, [r0]
	movs r1, 0xD2
	lsls r1, 2
	adds r0, r1
	bl GetKeyPress
	cmp r0, 0x2
	beq _0801F566
	cmp r0, 0x2
	bgt _0801F560
	cmp r0, 0x1
	beq _0801F570
	b _0801F584
	.align 2, 0
_0801F55C: .4byte gUnknown_203B274
_0801F560:
	cmp r0, 0x4
	beq _0801F57A
	b _0801F584
_0801F566:
	movs r0, 0x1
	bl sub_80119D4
	movs r0, 0x2
	b _0801F5AE
_0801F570:
	movs r0, 0
	bl sub_80119D4
	movs r0, 0x3
	b _0801F5AE
_0801F57A:
	movs r0, 0x4
	bl sub_80119D4
	movs r0, 0x4
	b _0801F5AE
_0801F584:
	ldr r0, _0801F5A0
	ldr r0, [r0]
	movs r1, 0xD2
	lsls r1, 2
	adds r0, r1
	movs r1, 0x1
	bl sub_80138B8
	lsls r0, 24
	cmp r0, 0
	bne _0801F5A4
	movs r0, 0
	b _0801F5AE
	.align 2, 0
_0801F5A0: .4byte gUnknown_203B274
_0801F5A4:
	bl sub_801F690
	bl sub_801F700
	movs r0, 0x1
_0801F5AE:
	pop {r1}
	bx r1
	thumb_func_end sub_801F520

	thumb_func_start sub_801F5B4
sub_801F5B4:
	push {r4,lr}
	ldr r0, _0801F5E8
	ldr r1, [r0]
	ldr r2, [r1, 0x4]
	ldr r3, _0801F5EC
	adds r0, r1, r3
	movs r4, 0
	ldrsh r3, [r0, r4]
	movs r4, 0xD9
	lsls r4, 2
	adds r0, r1, r4
	movs r4, 0
	ldrsh r0, [r0, r4]
	muls r0, r3
	movs r3, 0xD8
	lsls r3, 2
	adds r1, r3
	movs r4, 0
	ldrsh r1, [r1, r4]
	adds r0, r1
	lsls r0, 1
	adds r2, r0
	ldrh r0, [r2]
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_0801F5E8: .4byte gUnknown_203B274
_0801F5EC: .4byte 0x00000366
	thumb_func_end sub_801F5B4

	thumb_func_start sub_801F5F0
sub_801F5F0:
	push {r4,r5,lr}
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	bl sub_8004914
	ldr r5, _0801F638
	ldr r0, [r5]
	movs r1, 0xE1
	lsls r1, 2
	adds r0, r1
	movs r1, 0
	movs r2, 0
	bl sub_800641C
	ldr r0, [r5]
	movs r1, 0xD2
	lsls r1, 2
	adds r0, r1
	bl sub_8013984
	bl sub_801F690
	bl sub_801F700
	cmp r4, 0
	beq _0801F632
	ldr r0, [r5]
	movs r1, 0xD2
	lsls r1, 2
	adds r0, r1
	bl AddMenuCursorSprite
_0801F632:
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_0801F638: .4byte gUnknown_203B274
	thumb_func_end sub_801F5F0

	thumb_func_start sub_801F63C
sub_801F63C:
	push {r4-r6,lr}
	ldr r5, _0801F688
	ldr r2, [r5]
	cmp r2, 0
	beq _0801F680
	movs r1, 0xDF
	lsls r1, 2
	adds r0, r2, r1
	ldr r0, [r0]
	lsls r1, r0, 1
	adds r1, r0
	lsls r1, 3
	adds r1, r2, r1
	movs r4, 0xE1
	lsls r4, 2
	adds r1, r4
	ldr r0, _0801F68C
	ldm r0!, {r2,r3,r6}
	stm r1!, {r2,r3,r6}
	ldm r0!, {r2,r3,r6}
	stm r1!, {r2,r3,r6}
	bl sub_8004914
	ldr r0, [r5]
	adds r0, r4
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	ldr r0, [r5]
	bl MemoryFree
	movs r0, 0
	str r0, [r5]
_0801F680:
	pop {r4-r6}
	pop {r0}
	bx r0
	.align 2, 0
_0801F688: .4byte gUnknown_203B274
_0801F68C: .4byte gUnknown_80DC2AC
	thumb_func_end sub_801F63C

	thumb_func_start sub_801F690
sub_801F690:
	push {r4,r5,lr}
	ldr r5, _0801F6F4
	ldr r0, [r5]
	ldr r1, _0801F6F8
	adds r0, r1
	movs r2, 0
	ldrsh r0, [r0, r2]
	movs r1, 0xC
	bl sub_80095E4
	adds r0, 0x2
	lsls r0, 16
	ldr r3, [r5]
	movs r1, 0xDF
	lsls r1, 2
	adds r4, r3, r1
	ldr r2, [r4]
	lsls r1, r2, 1
	adds r1, r2
	lsls r1, 3
	adds r1, r3, r1
	ldr r2, _0801F6FC
	adds r1, r2
	asrs r2, r0, 16
	lsrs r0, 16
	strh r0, [r1]
	ldr r1, [r4]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 3
	adds r3, r0
	adds r2, 0x2
	movs r0, 0xE5
	lsls r0, 2
	adds r3, r0
	strh r2, [r3]
	bl sub_8004914
	ldr r0, [r5]
	movs r1, 0xE1
	lsls r1, 2
	adds r0, r1
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_0801F6F4: .4byte gUnknown_203B274
_0801F6F8: .4byte 0x00000362
_0801F6FC: .4byte 0x00000392
	thumb_func_end sub_801F690

	thumb_func_start sub_801F700
sub_801F700:
	push {r4-r7,lr}
	sub sp, 0xB4
	ldr r6, _0801F7D4
	ldr r0, [r6]
	movs r4, 0xDF
	lsls r4, 2
	adds r0, r4
	ldr r0, [r0]
	bl sub_8008C54
	ldr r0, [r6]
	adds r0, r4
	ldr r0, [r0]
	bl sub_80073B8
	add r5, sp, 0x34
	ldr r1, _0801F7D8
	ldr r0, [r6]
	ldr r3, _0801F7DC
	adds r2, r0, r3
	movs r7, 0
	ldrsh r2, [r2, r7]
	adds r2, 0x1
	adds r3, 0x2
	adds r0, r3
	movs r7, 0
	ldrsh r3, [r0, r7]
	adds r0, r5, 0
	bl sub_800D158
	ldr r0, [r6]
	adds r0, r4
	ldr r3, [r0]
	movs r0, 0
	str r0, [sp]
	movs r0, 0x10
	movs r1, 0
	adds r2, r5, 0
	bl xxx_call_draw_string
	movs r4, 0
	ldr r0, [r6]
	ldr r1, _0801F7E0
	adds r0, r1
	movs r2, 0
	ldrsh r0, [r0, r2]
	cmp r4, r0
	bge _0801F7BC
	adds r5, r6, 0
_0801F762:
	ldr r1, [r5]
	ldr r2, [r1, 0x4]
	ldr r3, _0801F7DC
	adds r0, r1, r3
	movs r6, 0
	ldrsh r3, [r0, r6]
	movs r7, 0xD9
	lsls r7, 2
	adds r1, r7
	movs r6, 0
	ldrsh r0, [r1, r6]
	muls r0, r3
	adds r0, r4
	lsls r0, 1
	adds r2, r0
	ldrh r1, [r2]
	add r0, sp, 0x4
	bl sub_8092C84
	ldr r0, [r5]
	subs r7, 0x1C
	adds r0, r7
	adds r1, r4, 0
	bl sub_8013800
	adds r1, r0, 0
	ldr r0, [r5]
	movs r2, 0xDF
	lsls r2, 2
	adds r0, r2
	ldr r3, [r0]
	movs r0, 0
	str r0, [sp]
	movs r0, 0x8
	add r2, sp, 0x4
	bl xxx_call_draw_string
	adds r4, 0x1
	ldr r0, [r5]
	ldr r3, _0801F7E0
	adds r0, r3
	movs r6, 0
	ldrsh r0, [r0, r6]
	cmp r4, r0
	blt _0801F762
_0801F7BC:
	ldr r0, _0801F7D4
	ldr r0, [r0]
	movs r7, 0xDF
	lsls r7, 2
	adds r0, r7
	ldr r0, [r0]
	bl sub_80073E0
	add sp, 0xB4
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_0801F7D4: .4byte gUnknown_203B274
_0801F7D8: .4byte gUnknown_80DC2DC
_0801F7DC: .4byte 0x00000366
_0801F7E0: .4byte 0x00000362
	thumb_func_end sub_801F700

	thumb_func_start sub_801F7E4
sub_801F7E4:
	push {r4,lr}
	ldr r4, _0801F804
	ldr r1, [r4]
	ldr r0, [r1, 0x4]
	ldr r1, [r1]
	bl sub_808E218
	ldr r0, [r4]
	ldr r0, [r0, 0x4]
	movs r1, 0xCF
	lsls r1, 2
	adds r0, r1
	ldr r0, [r0]
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_0801F804: .4byte gUnknown_203B274
	thumb_func_end sub_801F7E4

	thumb_func_start sub_801F808
sub_801F808:
	push {r4,r5,lr}
	adds r4, r0, 0
	movs r0, 0x1
	bl ResetSprites
	ldr r5, _0801F88C
	movs r0, 0xD4
	movs r1, 0x8
	bl MemoryAlloc
	str r0, [r5]
	movs r1, 0
	str r1, [r0, 0x5C]
	adds r1, r0, 0
	adds r1, 0x64
	str r1, [r0, 0x60]
	adds r0, r1, 0
	bl sub_80140B4
	bl sub_8004914
	ldr r0, [r5]
	adds r0, 0x64
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	ldr r0, [r5]
	str r4, [r0, 0x4]
	movs r2, 0x4
	ldrh r0, [r4, 0x6]
	cmp r0, 0
	bne _0801F862
	adds r3, r5, 0
_0801F84C:
	subs r2, 0x1
	cmp r2, 0x1
	ble _0801F862
	ldr r0, [r3]
	ldr r1, [r0, 0x4]
	lsls r0, r2, 1
	adds r0, r1
	subs r0, 0x2
	ldrh r0, [r0]
	cmp r0, 0
	beq _0801F84C
_0801F862:
	ldr r4, _0801F88C
	ldr r1, [r4]
	adds r0, r1, 0
	adds r0, 0x28
	ldr r3, [r1, 0x5C]
	adds r1, r2, 0
	movs r2, 0x1
	bl sub_8013818
	ldr r0, [r4]
	adds r0, 0xC8
	bl sub_801317C
	movs r0, 0
	bl sub_801F918
	movs r0, 0x1
	pop {r4,r5}
	pop {r1}
	bx r1
	.align 2, 0
_0801F88C: .4byte gUnknown_203B278
	thumb_func_end sub_801F808

	thumb_func_start sub_801F890
sub_801F890:
	push {lr}
	ldr r0, _0801F8A8
	ldr r0, [r0]
	ldr r0, [r0]
	cmp r0, 0x1
	beq _0801F8BC
	cmp r0, 0x1
	bgt _0801F8AC
	cmp r0, 0
	beq _0801F8B6
	b _0801F8C6
	.align 2, 0
_0801F8A8: .4byte gUnknown_203B278
_0801F8AC:
	cmp r0, 0x2
	beq _0801F8C6
	cmp r0, 0x3
	beq _0801F8C2
	b _0801F8C6
_0801F8B6:
	bl sub_801FA58
	b _0801F8CA
_0801F8BC:
	bl sub_801FAD4
	b _0801F8CA
_0801F8C2:
	movs r0, 0x3
	b _0801F8CC
_0801F8C6:
	movs r0, 0x2
	b _0801F8CC
_0801F8CA:
	movs r0, 0
_0801F8CC:
	pop {r1}
	bx r1
	thumb_func_end sub_801F890

	thumb_func_start sub_801F8D0
sub_801F8D0:
	push {r4,r5,lr}
	ldr r4, _0801F910
	ldr r2, [r4]
	cmp r2, 0
	beq _0801F90A
	ldr r0, [r2, 0x5C]
	lsls r1, r0, 1
	adds r1, r0
	lsls r1, 3
	adds r1, r2, r1
	adds r1, 0x64
	ldr r0, _0801F914
	ldm r0!, {r2,r3,r5}
	stm r1!, {r2,r3,r5}
	ldm r0!, {r2,r3,r5}
	stm r1!, {r2,r3,r5}
	bl sub_8004914
	ldr r0, [r4]
	adds r0, 0x64
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	ldr r0, [r4]
	bl MemoryFree
	movs r0, 0
	str r0, [r4]
_0801F90A:
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_0801F910: .4byte gUnknown_203B278
_0801F914: .4byte gUnknown_80DC2F8
	thumb_func_end sub_801F8D0

	thumb_func_start sub_801F918
sub_801F918:
	push {lr}
	ldr r1, _0801F92C
	ldr r1, [r1]
	str r0, [r1]
	bl sub_801F930
	bl sub_801F9A4
	pop {r0}
	bx r0
	.align 2, 0
_0801F92C: .4byte gUnknown_203B278
	thumb_func_end sub_801F918

	thumb_func_start sub_801F930
sub_801F930:
	push {r4,lr}
	ldr r4, _0801F94C
	ldr r0, [r4]
	adds r0, 0x64
	bl sub_80140B4
	ldr r2, [r4]
	ldr r3, [r2]
	cmp r3, 0
	beq _0801F950
	cmp r3, 0x1
	beq _0801F98C
	b _0801F99C
	.align 2, 0
_0801F94C: .4byte gUnknown_203B278
_0801F950:
	ldr r0, [r2, 0x60]
	adds r1, r2, 0
	adds r1, 0xC4
	str r1, [r0, 0x14]
	adds r0, r2, 0
	adds r0, 0x48
	ldrh r0, [r0]
	strb r0, [r1]
	ldr r0, [r4]
	adds r1, r0, 0
	adds r1, 0x46
	ldrh r1, [r1]
	adds r0, 0xC5
	strb r1, [r0]
	ldr r0, [r4]
	adds r0, 0xC6
	movs r1, 0x10
	strb r1, [r0]
	ldr r0, [r4]
	adds r0, 0xC7
	strb r3, [r0]
	bl sub_8004914
	ldr r0, [r4]
	adds r0, 0x64
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	b _0801F99C
_0801F98C:
	bl sub_8004914
	ldr r0, [r4]
	adds r0, 0x64
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
_0801F99C:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_801F930

	thumb_func_start sub_801F9A4
sub_801F9A4:
	push {r4,r5,lr}
	sub sp, 0x4
	ldr r5, _0801F9EC
	ldr r0, [r5]
	ldr r4, [r0]
	cmp r4, 0x1
	beq _0801F9F0
	cmp r4, 0x1
	bgt _0801FA48
	cmp r4, 0
	bne _0801FA48
	ldr r0, [r0, 0x5C]
	bl sub_8008C54
	ldr r3, [r5]
	adds r2, r3, 0
	adds r2, 0x46
	movs r1, 0
	ldrsh r0, [r2, r1]
	ldr r1, [r3, 0x4]
	lsls r0, 1
	adds r0, r1
	ldrh r0, [r0]
	strh r0, [r3, 0x8]
	movs r1, 0
	ldrsh r0, [r2, r1]
	ldrh r1, [r3, 0x8]
	ldr r2, [r3, 0x5C]
	adds r3, 0x14
	bl sub_8093D9C
	ldr r1, [r5]
	str r0, [r1, 0x10]
	str r4, [r1, 0x24]
	b _0801FA48
	.align 2, 0
_0801F9EC: .4byte gUnknown_203B278
_0801F9F0:
	ldr r0, [r0, 0x5C]
	bl sub_8008C54
	ldr r0, [r5]
	ldr r0, [r0, 0x5C]
	bl sub_80073B8
	ldr r0, [r5]
	ldr r1, [r0, 0xC]
	lsls r1, 2
	adds r0, 0x14
	adds r0, r1
	ldr r1, [r0]
	ldr r0, _0801FA50
	ldr r1, [r1]
	bl strcpy
	ldr r2, _0801FA54
	ldr r0, [r5]
	ldr r3, [r0, 0x5C]
	movs r4, 0
	str r4, [sp]
	movs r0, 0x10
	movs r1, 0
	bl sub_8014FF0
	ldr r3, [r5]
	ldr r1, [r3, 0xC]
	lsls r1, 2
	adds r0, r3, 0
	adds r0, 0x14
	adds r0, r1
	ldr r0, [r0]
	ldr r2, [r0, 0x4]
	ldr r3, [r3, 0x5C]
	str r4, [sp]
	movs r0, 0x4
	movs r1, 0x10
	bl sub_8014FF0
	ldr r0, [r5]
	ldr r0, [r0, 0x5C]
	bl sub_80073E0
_0801FA48:
	add sp, 0x4
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_0801FA50: .4byte gUnknown_202DF98
_0801FA54: .4byte gUnknown_80DC310
	thumb_func_end sub_801F9A4

	thumb_func_start sub_801FA58
sub_801FA58:
	push {r4,lr}
	ldr r0, _0801FAA4
	ldr r2, [r0]
	ldr r1, [r2, 0x10]
	adds r4, r0, 0
	cmp r1, 0
	beq _0801FA7C
	ldr r0, [r2, 0x24]
	movs r1, 0x8
	ands r0, r1
	cmp r0, 0
	beq _0801FA74
	bl sub_8013F84
_0801FA74:
	ldr r1, [r4]
	ldr r0, [r1, 0x24]
	adds r0, 0x1
	str r0, [r1, 0x24]
_0801FA7C:
	ldr r1, [r4]
	adds r0, r1, 0
	adds r0, 0xC8
	ldr r1, [r1, 0x5C]
	bl sub_8012A64
	cmp r0, 0x1
	beq _0801FAA8
	cmp r0, 0x2
	beq _0801FAC2
	ldr r0, [r4]
	adds r0, 0x28
	bl sub_8013938
	lsls r0, 24
	cmp r0, 0
	beq _0801FACE
	movs r0, 0
	b _0801FACA
	.align 2, 0
_0801FAA4: .4byte gUnknown_203B278
_0801FAA8:
	movs r0, 0
	bl sub_80119D4
	ldr r1, [r4]
	ldr r0, [r1, 0x10]
	cmp r0, 0
	beq _0801FABE
	movs r0, 0
	str r0, [r1, 0xC]
	movs r0, 0x1
	b _0801FACA
_0801FABE:
	movs r0, 0x3
	b _0801FACA
_0801FAC2:
	movs r0, 0x1
	bl sub_80119D4
	movs r0, 0x2
_0801FACA:
	bl sub_801F918
_0801FACE:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_801FA58

	thumb_func_start sub_801FAD4
sub_801FAD4:
	push {r4,lr}
	ldr r0, _0801FB14
	ldr r3, [r0]
	ldr r1, [r3, 0x10]
	subs r1, 0x1
	ldr r2, [r3, 0xC]
	adds r4, r0, 0
	cmp r2, r1
	bge _0801FAFC
	ldr r0, [r3, 0x24]
	movs r1, 0x8
	ands r0, r1
	cmp r0, 0
	beq _0801FAF4
	bl sub_8013F84
_0801FAF4:
	ldr r1, [r4]
	ldr r0, [r1, 0x24]
	adds r0, 0x1
	str r0, [r1, 0x24]
_0801FAFC:
	ldr r1, [r4]
	adds r0, r1, 0
	adds r0, 0xC8
	ldr r1, [r1, 0x5C]
	bl sub_8012A64
	cmp r0, 0x1
	beq _0801FB18
	cmp r0, 0x2
	beq _0801FB3C
	b _0801FB48
	.align 2, 0
_0801FB14: .4byte gUnknown_203B278
_0801FB18:
	movs r0, 0
	bl sub_80119D4
	ldr r0, [r4]
	ldr r1, [r0, 0xC]
	adds r1, 0x1
	str r1, [r0, 0xC]
	ldr r0, [r0, 0x10]
	cmp r1, r0
	bge _0801FB34
	movs r0, 0x1
	bl sub_801F918
	b _0801FB48
_0801FB34:
	movs r0, 0
	bl sub_801F918
	b _0801FB48
_0801FB3C:
	movs r0, 0x1
	bl sub_80119D4
	movs r0, 0x2
	bl sub_801F918
_0801FB48:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_801FAD4

	thumb_func_start sub_801FB50
sub_801FB50:
	push {r4-r7,lr}
	adds r4, r0, 0
	bl sub_8004914
	movs r0, 0
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	ldr r6, _0801FBC0
	movs r0, 0xF0
	lsls r0, 1
	movs r1, 0x8
	bl MemoryAlloc
	str r0, [r6]
	movs r7, 0
	str r7, [r0, 0x70]
	str r7, [r0, 0x74]
	str r7, [r0, 0x78]
	str r4, [r0]
	strb r7, [r0, 0x15]
	ldr r0, _0801FBC4
	ldr r4, _0801FBC8
	adds r1, r4, 0
	bl sub_808D8E0
	ldr r5, _0801FBCC
	adds r0, r5, 0
	adds r1, r4, 0
	bl sub_808D8E0
	adds r0, r4, 0
	bl sub_808D994
	adds r1, r0, 0
	adds r0, r5, 0
	subs r0, 0x50
	bl strcpy
	subs r5, 0xF0
	bl sub_808D33C
	adds r1, r0, 0
	adds r0, r5, 0
	bl sub_808DA34
	ldr r2, [r6]
	ldr r0, [r2]
	cmp r0, 0x1
	bne _0801FBD0
	movs r1, 0xBE
	lsls r1, 1
	adds r0, r2, r1
	str r7, [r0]
	b _0801FBDE
	.align 2, 0
_0801FBC0: .4byte gUnknown_203B27C
_0801FBC4: .4byte gUnknown_202E5D8
_0801FBC8: .4byte 0x00000155
_0801FBCC: .4byte gUnknown_202E1C8
_0801FBD0:
	movs r3, 0xBE
	lsls r3, 1
	adds r1, r2, r3
	movs r4, 0xB6
	lsls r4, 1
	adds r0, r2, r4
	str r0, [r1]
_0801FBDE:
	ldr r0, _0801FC34
	bl sub_808DDD0
	ldr r2, _0801FC38
	ldr r3, [r2]
	movs r4, 0xB6
	lsls r4, 1
	adds r1, r3, r4
	str r0, [r1]
	adds r4, 0x4
	adds r1, r3, r4
	ldr r0, [r0, 0x4]
	str r0, [r1]
	movs r1, 0xBC
	lsls r1, 1
	adds r0, r3, r1
	movs r1, 0
	strb r1, [r0]
	ldr r0, [r2]
	ldr r3, _0801FC3C
	adds r0, r3
	strb r1, [r0]
	ldr r0, [r2]
	adds r4, 0xA
	adds r0, r4
	strb r1, [r0]
	ldr r2, [r2]
	movs r0, 0xBA
	lsls r0, 1
	adds r1, r2, r0
	movs r0, 0x2
	strh r0, [r1]
	subs r3, 0x3
	adds r1, r2, r3
	movs r0, 0x8
	strh r0, [r1]
	movs r0, 0
	bl sub_801FDA8
	movs r0, 0x1
	pop {r4-r7}
	pop {r1}
	bx r1
	.align 2, 0
_0801FC34: .4byte 0x00000155
_0801FC38: .4byte gUnknown_203B27C
_0801FC3C: .4byte 0x00000179
	thumb_func_end sub_801FB50

	thumb_func_start sub_801FC40
sub_801FC40:
	push {lr}
	ldr r1, _0801FC5C
	ldr r0, [r1]
	ldr r0, [r0, 0x4]
	adds r2, r1, 0
	cmp r0, 0x22
	bls _0801FC50
	b _0801FD70
_0801FC50:
	lsls r0, 2
	ldr r1, _0801FC60
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0801FC5C: .4byte gUnknown_203B27C
_0801FC60: .4byte _0801FC64
	.align 2, 0
_0801FC64:
	.4byte _0801FCF0
	.4byte _0801FCF0
	.4byte _0801FCF6
	.4byte _0801FD70
	.4byte _0801FD70
	.4byte _0801FD70
	.4byte _0801FD70
	.4byte _0801FCFC
	.4byte _0801FD02
	.4byte _0801FD70
	.4byte _0801FD70
	.4byte _0801FD70
	.4byte _0801FD70
	.4byte _0801FD50
	.4byte _0801FD70
	.4byte _0801FD08
	.4byte _0801FD08
	.4byte _0801FD0E
	.4byte _0801FD14
	.4byte _0801FD1A
	.4byte _0801FD70
	.4byte _0801FD20
	.4byte _0801FD20
	.4byte _0801FD26
	.4byte _0801FD2C
	.4byte _0801FD70
	.4byte _0801FD70
	.4byte _0801FD70
	.4byte _0801FD70
	.4byte _0801FD32
	.4byte _0801FD38
	.4byte _0801FD38
	.4byte _0801FD3E
	.4byte _0801FD44
	.4byte _0801FD4A
_0801FCF0:
	bl sub_8021154
	b _0801FD74
_0801FCF6:
	bl sub_80209AC
	b _0801FD74
_0801FCFC:
	bl sub_80209FC
	b _0801FD74
_0801FD02:
	bl sub_8020A34
	b _0801FD74
_0801FD08:
	bl sub_8020A80
	b _0801FD74
_0801FD0E:
	bl sub_8020B38
	b _0801FD74
_0801FD14:
	bl sub_8020C2C
	b _0801FD74
_0801FD1A:
	bl sub_8020C48
	b _0801FD74
_0801FD20:
	bl sub_8020C64
	b _0801FD74
_0801FD26:
	bl sub_8020CC0
	b _0801FD74
_0801FD2C:
	bl sub_8020D74
	b _0801FD74
_0801FD32:
	bl sub_8020D90
	b _0801FD74
_0801FD38:
	bl sub_8020DCC
	b _0801FD74
_0801FD3E:
	bl sub_8020EB4
	b _0801FD74
_0801FD44:
	bl sub_80210C8
	b _0801FD74
_0801FD4A:
	bl sub_80210E4
	b _0801FD74
_0801FD50:
	ldr r0, [r2]
	ldrb r0, [r0, 0x15]
	cmp r0, 0x1
	bne _0801FD68
	ldr r0, _0801FD6C
	ldr r1, [r0]
	movs r0, 0x98
	lsls r0, 2
	adds r1, r0
	ldr r0, [r1]
	subs r0, 0x96
	str r0, [r1]
_0801FD68:
	movs r0, 0x3
	b _0801FD76
	.align 2, 0
_0801FD6C: .4byte gUnknown_203B460
_0801FD70:
	bl sub_8021130
_0801FD74:
	movs r0, 0
_0801FD76:
	pop {r1}
	bx r1
	thumb_func_end sub_801FC40

	thumb_func_start sub_801FD7C
sub_801FD7C:
	push {r4,lr}
	ldr r4, _0801FDA4
	ldr r0, [r4]
	cmp r0, 0
	beq _0801FD9C
	movs r1, 0xB6
	lsls r1, 1
	adds r0, r1
	ldr r0, [r0]
	bl CloseFile
	ldr r0, [r4]
	bl MemoryFree
	movs r0, 0
	str r0, [r4]
_0801FD9C:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0801FDA4: .4byte gUnknown_203B27C
	thumb_func_end sub_801FD7C

	thumb_func_start sub_801FDA8
sub_801FDA8:
	push {lr}
	ldr r1, _0801FDBC
	ldr r1, [r1]
	str r0, [r1, 0x4]
	bl sub_801FDC0
	bl sub_801FF28
	pop {r0}
	bx r0
	.align 2, 0
_0801FDBC: .4byte gUnknown_203B27C
	thumb_func_end sub_801FDA8

	thumb_func_start sub_801FDC0
sub_801FDC0:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	ldr r4, _0801FDE8
	ldr r0, [r4]
	movs r5, 0xC0
	lsls r5, 1
	adds r0, r5
	bl sub_8006518
	ldr r0, [r4]
	ldr r1, [r0, 0x4]
	cmp r1, 0x11
	beq _0801FE38
	cmp r1, 0x11
	bgt _0801FDEC
	cmp r1, 0x2
	beq _0801FDF6
	b _0801FED4
	.align 2, 0
_0801FDE8: .4byte gUnknown_203B27C
_0801FDEC:
	cmp r1, 0x17
	beq _0801FE6C
	cmp r1, 0x20
	beq _0801FE88
	b _0801FED4
_0801FDF6:
	adds r0, r5
	movs r1, 0x80
	strb r1, [r0]
	ldr r0, [r4]
	movs r2, 0xCC
	lsls r2, 1
	adds r0, r2
	strb r1, [r0]
	ldr r0, [r4]
	movs r3, 0xD8
	lsls r3, 1
	adds r0, r3
	strb r1, [r0]
	ldr r1, [r4]
	movs r6, 0xE4
	lsls r6, 1
	adds r1, r6
	ldr r0, _0801FE34
	ldm r0!, {r2,r3,r7}
	stm r1!, {r2,r3,r7}
	ldm r0!, {r2,r6,r7}
	stm r1!, {r2,r6,r7}
	bl sub_8004914
	ldr r0, [r4]
	adds r0, r5
	movs r1, 0x1
	movs r2, 0
	bl sub_800641C
	b _0801FF14
	.align 2, 0
_0801FE34: .4byte gUnknown_80DC37C
_0801FE38:
	bl sub_80205D0
	ldr r2, [r4]
	movs r0, 0xD8
	lsls r0, 1
	adds r2, r0
	ldr r1, _0801FE68
	ldm r1!, {r3,r5,r6}
	stm r2!, {r3,r5,r6}
	ldm r1!, {r3,r5,r7}
	stm r2!, {r3,r5,r7}
	ldr r1, [r4]
	adds r0, r1, r0
	adds r1, 0x7C
	bl sub_8012CAC
	bl sub_8004914
	ldr r0, [r4]
	movs r6, 0xC0
	lsls r6, 1
	adds r0, r6
	b _0801FEC2
	.align 2, 0
_0801FE68: .4byte gUnknown_80DC334
_0801FE6C:
	bl sub_802069C
	ldr r2, [r4]
	movs r0, 0xD8
	lsls r0, 1
	adds r2, r0
	ldr r1, _0801FE84
	ldm r1!, {r3,r6,r7}
	stm r2!, {r3,r6,r7}
	ldm r1!, {r3,r6,r7}
	stm r2!, {r3,r6,r7}
	b _0801FEB0
	.align 2, 0
_0801FE84: .4byte gUnknown_80DC334
_0801FE88:
	bl sub_802074C
	ldr r1, [r4]
	movs r7, 0xCC
	lsls r7, 1
	adds r1, r7
	ldr r0, _0801FECC
	ldm r0!, {r2,r3,r6}
	stm r1!, {r2,r3,r6}
	ldm r0!, {r2,r3,r7}
	stm r1!, {r2,r3,r7}
	ldr r2, [r4]
	movs r0, 0xD8
	lsls r0, 1
	adds r2, r0
	ldr r1, _0801FED0
	ldm r1!, {r3,r6,r7}
	stm r2!, {r3,r6,r7}
	ldm r1!, {r3,r6,r7}
	stm r2!, {r3,r6,r7}
_0801FEB0:
	ldr r1, [r4]
	adds r0, r1, r0
	adds r1, 0x7C
	bl sub_8012CAC
	bl sub_8004914
	ldr r0, [r4]
	adds r0, r5
_0801FEC2:
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	b _0801FF14
	.align 2, 0
_0801FECC: .4byte gUnknown_80DC31C
_0801FED0: .4byte gUnknown_80DC34C
_0801FED4:
	ldr r5, _0801FF20
	mov r12, r5
	movs r6, 0xC0
	lsls r6, 1
	mov r8, r6
	ldr r4, _0801FF24
	movs r3, 0
	movs r2, 0x3
_0801FEE4:
	mov r7, r12
	ldr r1, [r7]
	adds r1, r3
	add r1, r8
	adds r0, r4, 0
	ldm r0!, {r5-r7}
	stm r1!, {r5-r7}
	ldm r0!, {r5-r7}
	stm r1!, {r5-r7}
	adds r3, 0x18
	subs r2, 0x1
	cmp r2, 0
	bge _0801FEE4
	bl sub_8004914
	ldr r0, _0801FF20
	ldr r0, [r0]
	movs r1, 0xC0
	lsls r1, 1
	adds r0, r1
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
_0801FF14:
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_0801FF20: .4byte gUnknown_203B27C
_0801FF24: .4byte gUnknown_80DC31C
	thumb_func_end sub_801FDC0

	thumb_func_start sub_801FF28
sub_801FF28:
	push {r4,r5,lr}
	sub sp, 0x14
	ldr r1, _0801FF44
	ldr r0, [r1]
	ldr r0, [r0, 0x4]
	adds r5, r1, 0
	cmp r0, 0x23
	bls _0801FF3A
	b _08020562
_0801FF3A:
	lsls r0, 2
	ldr r1, _0801FF48
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0801FF44: .4byte gUnknown_203B27C
_0801FF48: .4byte _0801FF4C
	.align 2, 0
_0801FF4C:
	.4byte _0801FFDC
	.4byte _08020018
	.4byte _08020064
	.4byte _0802006C
	.4byte _08020090
	.4byte _080200B4
	.4byte _080200D8
	.4byte _080200FC
	.4byte _08020144
	.4byte _0802018C
	.4byte _080201B0
	.4byte _080201D4
	.4byte _080201F8
	.4byte _08020562
	.4byte _0802021C
	.4byte _08020240
	.4byte _0802024E
	.4byte _08020256
	.4byte _08020274
	.4byte _08020282
	.4byte _0802028E
	.4byte _080202B0
	.4byte _080202BE
	.4byte _080202C6
	.4byte _080202E4
	.4byte _08020304
	.4byte _08020344
	.4byte _080203B0
	.4byte _080203D4
	.4byte _0802038C
	.4byte _080203F8
	.4byte _08020428
	.4byte _08020434
	.4byte _08020460
	.4byte _08020478
	.4byte _08020500
_0801FFDC:
	ldr r0, [r5]
	movs r4, 0x2
	str r4, [r0, 0x6C]
	bl sub_8020574
	ldr r5, [r5]
	str r4, [r5, 0x8]
	ldr r2, _08020014
	ldr r1, [r5]
	movs r0, 0x64
	muls r0, r1
	adds r0, r2
	ldr r0, [r0]
	ldr r2, [r5, 0x6C]
	adds r3, r5, 0
	adds r3, 0x7C
	adds r1, r5, 0
	adds r1, 0xBC
	str r1, [sp]
	movs r1, 0x4
	str r1, [sp, 0x4]
	movs r1, 0
	str r1, [sp, 0x8]
	movs r4, 0xBE
	lsls r4, 1
	adds r1, r5, r4
	b _0802004C
	.align 2, 0
_08020014: .4byte gUnknown_80D8888
_08020018:
	bl sub_8020574
	ldr r0, _0802005C
	ldr r4, [r0]
	movs r0, 0x2
	str r0, [r4, 0x8]
	ldr r1, _08020060
	ldr r2, [r4]
	movs r0, 0x64
	muls r0, r2
	adds r1, 0x4
	adds r0, r1
	ldr r0, [r0]
	ldr r2, [r4, 0x6C]
	adds r3, r4, 0
	adds r3, 0x7C
	adds r1, r4, 0
	adds r1, 0xBC
	str r1, [sp]
	movs r1, 0x4
	str r1, [sp, 0x4]
	movs r1, 0
	str r1, [sp, 0x8]
	movs r5, 0xBE
	lsls r5, 1
	adds r1, r4, r5
_0802004C:
	ldr r1, [r1]
	str r1, [sp, 0xC]
	movs r1, 0xC
	str r1, [sp, 0x10]
	movs r1, 0
	bl sub_8014248
	b _08020562
	.align 2, 0
_0802005C: .4byte gUnknown_203B27C
_08020060: .4byte gUnknown_80D8888
_08020064:
	movs r0, 0x3
	bl sub_8016C40
	b _08020562
_0802006C:
	ldr r2, [r5]
	movs r0, 0x1F
	str r0, [r2, 0x8]
	ldr r1, _0802008C
	ldr r3, [r2]
	movs r0, 0x64
	muls r0, r3
	adds r1, 0x8
	adds r0, r1
	ldr r0, [r0]
	movs r1, 0xBE
	lsls r1, 1
	adds r2, r1
	ldr r2, [r2]
	b _0802052C
	.align 2, 0
_0802008C: .4byte gUnknown_80D8888
_08020090:
	ldr r2, [r5]
	movs r0, 0x1F
	str r0, [r2, 0x8]
	ldr r1, _080200B0
	ldr r3, [r2]
	movs r0, 0x64
	muls r0, r3
	adds r1, 0xC
	adds r0, r1
	ldr r0, [r0]
	movs r4, 0xBE
	lsls r4, 1
	adds r2, r4
	ldr r2, [r2]
	b _0802052C
	.align 2, 0
_080200B0: .4byte gUnknown_80D8888
_080200B4:
	ldr r2, [r5]
	movs r0, 0x1F
	str r0, [r2, 0x8]
	ldr r1, _080200D4
	ldr r3, [r2]
	movs r0, 0x64
	muls r0, r3
	adds r1, 0x10
	adds r0, r1
	ldr r0, [r0]
	movs r5, 0xBE
	lsls r5, 1
	adds r2, r5
	ldr r2, [r2]
	b _0802052C
	.align 2, 0
_080200D4: .4byte gUnknown_80D8888
_080200D8:
	ldr r2, [r5]
	movs r0, 0x1F
	str r0, [r2, 0x8]
	ldr r1, _080200F8
	ldr r3, [r2]
	movs r0, 0x64
	muls r0, r3
	adds r1, 0x14
	adds r0, r1
	ldr r0, [r0]
	movs r1, 0xBE
	lsls r1, 1
	adds r2, r1
	ldr r2, [r2]
	b _0802052C
	.align 2, 0
_080200F8: .4byte gUnknown_80D8888
_080200FC:
	bl sub_8020900
	ldr r1, _0802013C
	ldr r0, _08020140
	ldr r4, [r0]
	ldr r2, [r4]
	movs r0, 0x64
	muls r0, r2
	adds r1, 0x18
	adds r0, r1
	ldr r0, [r0]
	adds r3, r4, 0
	adds r3, 0x7C
	adds r1, r4, 0
	adds r1, 0xBC
	str r1, [sp]
	movs r1, 0x4
	str r1, [sp, 0x4]
	movs r1, 0
	str r1, [sp, 0x8]
	movs r2, 0xBE
	lsls r2, 1
	adds r1, r4, r2
	ldr r1, [r1]
	str r1, [sp, 0xC]
	movs r1, 0xC
	str r1, [sp, 0x10]
	movs r1, 0
	movs r2, 0x10
	bl sub_8014248
	b _08020562
	.align 2, 0
_0802013C: .4byte gUnknown_80D8888
_08020140: .4byte gUnknown_203B27C
_08020144:
	bl sub_8020950
	ldr r1, _08020184
	ldr r0, _08020188
	ldr r4, [r0]
	ldr r2, [r4]
	movs r0, 0x64
	muls r0, r2
	adds r1, 0x54
	adds r0, r1
	ldr r0, [r0]
	adds r3, r4, 0
	adds r3, 0x7C
	adds r1, r4, 0
	adds r1, 0xBC
	str r1, [sp]
	movs r1, 0x4
	str r1, [sp, 0x4]
	movs r1, 0
	str r1, [sp, 0x8]
	movs r5, 0xBE
	lsls r5, 1
	adds r1, r4, r5
	ldr r1, [r1]
	str r1, [sp, 0xC]
	movs r1, 0xC
	str r1, [sp, 0x10]
	movs r1, 0
	movs r2, 0xD
	bl sub_8014248
	b _08020562
	.align 2, 0
_08020184: .4byte gUnknown_80D8888
_08020188: .4byte gUnknown_203B27C
_0802018C:
	ldr r2, [r5]
	movs r0, 0x1
	str r0, [r2, 0x8]
	ldr r1, _080201AC
	ldr r3, [r2]
	movs r0, 0x64
	muls r0, r3
	adds r1, 0x58
	adds r0, r1
	ldr r0, [r0]
	movs r1, 0xBE
	lsls r1, 1
	adds r2, r1
	ldr r2, [r2]
	b _0802052C
	.align 2, 0
_080201AC: .4byte gUnknown_80D8888
_080201B0:
	ldr r2, [r5]
	movs r0, 0x1
	str r0, [r2, 0x8]
	ldr r1, _080201D0
	ldr r3, [r2]
	movs r0, 0x64
	muls r0, r3
	adds r1, 0x5C
	adds r0, r1
	ldr r0, [r0]
	movs r4, 0xBE
	lsls r4, 1
	adds r2, r4
	ldr r2, [r2]
	b _0802052C
	.align 2, 0
_080201D0: .4byte gUnknown_80D8888
_080201D4:
	ldr r2, [r5]
	movs r0, 0x1
	str r0, [r2, 0x8]
	ldr r1, _080201F4
	ldr r3, [r2]
	movs r0, 0x64
	muls r0, r3
	adds r1, 0x60
	adds r0, r1
	ldr r0, [r0]
	movs r5, 0xBE
	lsls r5, 1
	adds r2, r5
	ldr r2, [r2]
	b _0802052C
	.align 2, 0
_080201F4: .4byte gUnknown_80D8888
_080201F8:
	ldr r2, [r5]
	movs r0, 0xD
	str r0, [r2, 0x8]
	ldr r1, _08020218
	ldr r3, [r2]
	movs r0, 0x64
	muls r0, r3
	adds r1, 0x1C
	adds r0, r1
	ldr r0, [r0]
	movs r1, 0xBE
	lsls r1, 1
	adds r2, r1
	ldr r2, [r2]
	b _0802052C
	.align 2, 0
_08020218: .4byte gUnknown_80D8888
_0802021C:
	ldr r2, [r5]
	movs r0, 0xF
	str r0, [r2, 0x8]
	ldr r1, _0802023C
	ldr r3, [r2]
	movs r0, 0x64
	muls r0, r3
	adds r1, 0x20
	adds r0, r1
	ldr r0, [r0]
	movs r4, 0xBE
	lsls r4, 1
	adds r2, r4
	ldr r2, [r2]
	b _0802052C
	.align 2, 0
_0802023C: .4byte gUnknown_80D8888
_08020240:
	movs r0, 0x2
	movs r1, 0
	movs r2, 0
	movs r3, 0xA
	bl sub_8023868
	b _08020562
_0802024E:
	movs r0, 0x1
	bl sub_8023B7C
	b _08020562
_08020256:
	bl sub_8023DA4
	ldr r0, _08020270
	ldr r2, [r0]
	adds r0, r2, 0
	adds r0, 0xCC
	adds r1, r2, 0
	adds r1, 0x7C
	adds r3, r2, 0
	adds r3, 0xBC
	ldr r2, [r2, 0x70]
	b _0802044C
	.align 2, 0
_08020270: .4byte gUnknown_203B27C
_08020274:
	ldr r0, [r5]
	movs r5, 0xC
	ldrsh r0, [r0, r5]
	movs r1, 0x2
	bl sub_8024458
	b _08020562
_08020282:
	ldr r0, [r5]
	movs r1, 0xC
	ldrsh r0, [r0, r1]
	bl sub_801BEEC
	b _08020562
_0802028E:
	ldr r2, [r5]
	movs r0, 0x15
	str r0, [r2, 0x8]
	ldr r1, _080202AC
	ldr r3, [r2]
	movs r0, 0x64
	muls r0, r3
	adds r1, 0x24
	adds r0, r1
	ldr r0, [r0]
	movs r4, 0xBE
	lsls r4, 1
	adds r2, r4
	ldr r2, [r2]
	b _0802052C
	.align 2, 0
_080202AC: .4byte gUnknown_80D8888
_080202B0:
	ldr r0, [r5]
	movs r5, 0xC
	ldrsh r0, [r0, r5]
	movs r1, 0
	bl sub_801F428
	b _08020562
_080202BE:
	movs r0, 0x1
	bl sub_801F5F0
	b _08020562
_080202C6:
	bl sub_801F700
	ldr r0, _080202E0
	ldr r2, [r0]
	adds r0, r2, 0
	adds r0, 0xCC
	adds r1, r2, 0
	adds r1, 0x7C
	adds r3, r2, 0
	adds r3, 0xBC
	ldr r2, [r2, 0x74]
	b _0802044C
	.align 2, 0
_080202E0: .4byte gUnknown_203B27C
_080202E4:
	ldr r0, [r5]
	ldrh r1, [r0, 0x1C]
	adds r0, 0x64
	strh r1, [r0]
	movs r2, 0x1
	adds r4, r5, 0
	movs r3, 0
_080202F2:
	ldr r0, [r4]
	lsls r1, r2, 1
	adds r0, 0x64
	adds r0, r1
	strh r3, [r0]
	adds r2, 0x1
	cmp r2, 0x3
	ble _080202F2
	b _0802046E
_08020304:
	ldr r1, [r5]
	adds r0, r1, 0
	adds r0, 0x24
	ldr r1, [r1, 0x10]
	adds r1, 0x2C
	bl sub_8094060
	ldr r1, [r5]
	movs r0, 0x10
	str r0, [r1, 0x8]
	ldr r0, _0802033C
	ldrh r1, [r1, 0x1E]
	bl sub_8092C84
	ldr r1, _08020340
	ldr r2, [r5]
	ldr r3, [r2]
	movs r0, 0x64
	muls r0, r3
	adds r1, 0x28
	adds r0, r1
	ldr r0, [r0]
	movs r1, 0xBE
	lsls r1, 1
	adds r2, r1
	ldr r2, [r2]
	b _0802052C
	.align 2, 0
_0802033C: .4byte gUnknown_202DF98
_08020340: .4byte gUnknown_80D8888
_08020344:
	ldr r1, [r5]
	adds r0, r1, 0
	adds r0, 0x24
	ldr r1, [r1, 0x10]
	adds r1, 0x2C
	bl sub_8094060
	ldr r3, [r5]
	movs r0, 0x10
	str r0, [r3, 0x8]
	ldrb r0, [r3, 0x14]
	cmp r0, 0
	beq _08020370
	ldr r1, _0802036C
	ldr r2, [r3]
	movs r0, 0x64
	muls r0, r2
	adds r1, 0x38
	b _08020520
	.align 2, 0
_0802036C: .4byte gUnknown_80D8888
_08020370:
	ldr r1, _08020388
	ldr r2, [r3]
	movs r0, 0x64
	muls r0, r2
	adds r1, 0x34
	adds r0, r1
	ldr r0, [r0]
	movs r4, 0xBE
	lsls r4, 1
	adds r1, r3, r4
	b _0802052A
	.align 2, 0
_08020388: .4byte gUnknown_80D8888
_0802038C:
	ldr r2, [r5]
	ldr r0, [r2]
	cmp r0, 0
	bne _080203A2
	movs r5, 0xC
	ldrsh r1, [r2, r5]
	adds r2, 0x24
	movs r0, 0
	bl sub_801E80C
	b _08020562
_080203A2:
	movs r0, 0xC
	ldrsh r1, [r2, r0]
	adds r2, 0x24
	movs r0, 0x1
	bl sub_801E80C
	b _08020562
_080203B0:
	ldr r2, [r5]
	movs r0, 0x10
	str r0, [r2, 0x8]
	ldr r1, _080203D0
	ldr r3, [r2]
	movs r0, 0x64
	muls r0, r3
	adds r1, 0x3C
	adds r0, r1
	ldr r0, [r0]
	movs r1, 0xBE
	lsls r1, 1
	adds r2, r1
	ldr r2, [r2]
	b _0802052C
	.align 2, 0
_080203D0: .4byte gUnknown_80D8888
_080203D4:
	ldr r2, [r5]
	movs r0, 0x10
	str r0, [r2, 0x8]
	ldr r1, _080203F4
	ldr r3, [r2]
	movs r0, 0x64
	muls r0, r3
	adds r1, 0x40
	adds r0, r1
	ldr r0, [r0]
	movs r4, 0xBE
	lsls r4, 1
	adds r2, r4
	ldr r2, [r2]
	b _0802052C
	.align 2, 0
_080203F4: .4byte gUnknown_80D8888
_080203F8:
	ldr r1, [r5]
	adds r0, r1, 0
	adds r0, 0x24
	ldr r1, [r1, 0x10]
	adds r1, 0x2C
	bl sub_809401C
	ldr r0, [r5]
	movs r5, 0xC
	ldrsh r1, [r0, r5]
	adds r2, r0, 0
	adds r2, 0x24
	ldrb r3, [r0, 0x15]
	ldr r0, _08020424
	str r0, [sp]
	movs r0, 0
	str r0, [sp, 0x4]
	movs r0, 0x1
	bl sub_801EE10
	b _08020562
	.align 2, 0
_08020424: .4byte gUnknown_80DC394
_08020428:
	ldr r0, [r5]
	ldrb r1, [r0, 0x15]
	movs r0, 0x1
	bl sub_801F1B0
	b _08020562
_08020434:
	movs r0, 0
	bl sub_801F280
	ldr r0, _0802045C
	ldr r2, [r0]
	adds r0, r2, 0
	adds r0, 0xCC
	adds r1, r2, 0
	adds r1, 0x7C
	adds r3, r2, 0
	adds r3, 0xBC
	ldr r2, [r2, 0x78]
_0802044C:
	str r2, [sp]
	movs r2, 0x2
	str r2, [sp, 0x4]
	movs r2, 0
	bl sub_8012D60
	b _08020562
	.align 2, 0
_0802045C: .4byte gUnknown_203B27C
_08020460:
	ldr r2, [r5]
	ldr r0, [r2, 0x18]
	adds r1, r2, 0
	adds r1, 0x24
	adds r2, 0x64
	bl sub_8093560
_0802046E:
	ldr r0, [r5]
	adds r0, 0x64
	bl sub_801F808
	b _08020562
_08020478:
	bl sub_80208B0
	ldr r0, _080204B8
	ldr r4, _080204BC
	ldr r1, [r4]
	ldrh r1, [r1, 0x20]
	bl sub_8092C84
	ldr r4, [r4]
	ldrb r5, [r4, 0x14]
	cmp r5, 0
	beq _080204C4
	ldr r1, _080204C0
	ldr r2, [r4]
	movs r0, 0x64
	muls r0, r2
	adds r1, 0x48
	adds r0, r1
	ldr r0, [r0]
	adds r3, r4, 0
	adds r3, 0x7C
	adds r1, r4, 0
	adds r1, 0xBC
	str r1, [sp]
	movs r1, 0x4
	str r1, [sp, 0x4]
	movs r1, 0
	str r1, [sp, 0x8]
	movs r2, 0xBE
	lsls r2, 1
	adds r1, r4, r2
	b _080204E8
	.align 2, 0
_080204B8: .4byte gUnknown_202DFE8
_080204BC: .4byte gUnknown_203B27C
_080204C0: .4byte gUnknown_80D8888
_080204C4:
	ldr r1, _080204FC
	ldr r2, [r4]
	movs r0, 0x64
	muls r0, r2
	adds r1, 0x44
	adds r0, r1
	ldr r0, [r0]
	adds r3, r4, 0
	adds r3, 0x7C
	adds r1, r4, 0
	adds r1, 0xBC
	str r1, [sp]
	movs r1, 0x4
	str r1, [sp, 0x4]
	str r5, [sp, 0x8]
	movs r5, 0xBE
	lsls r5, 1
	adds r1, r4, r5
_080204E8:
	ldr r1, [r1]
	str r1, [sp, 0xC]
	movs r1, 0xC
	str r1, [sp, 0x10]
	movs r1, 0
	movs r2, 0x11
	bl sub_8014248
	b _08020562
	.align 2, 0
_080204FC: .4byte gUnknown_80D8888
_08020500:
	ldr r1, [r5]
	movs r0, 0x1F
	str r0, [r1, 0x8]
	ldr r0, _08020538
	ldrh r1, [r1, 0x20]
	bl sub_8092C84
	ldr r3, [r5]
	ldrb r0, [r3, 0x14]
	cmp r0, 0
	beq _08020544
	ldr r1, _0802053C
	ldr r2, [r3]
	movs r0, 0x64
	muls r0, r2
	adds r1, 0x50
_08020520:
	adds r0, r1
	ldr r0, [r0]
	movs r2, 0xBE
	lsls r2, 1
	adds r1, r3, r2
_0802052A:
	ldr r2, [r1]
_0802052C:
	ldr r3, _08020540
	movs r1, 0
	bl sub_80141B4
	b _08020562
	.align 2, 0
_08020538: .4byte gUnknown_202DFE8
_0802053C: .4byte gUnknown_80D8888
_08020540: .4byte 0x0000010d
_08020544:
	ldr r1, _0802056C
	ldr r2, [r3]
	movs r0, 0x64
	muls r0, r2
	adds r1, 0x4C
	adds r0, r1
	ldr r0, [r0]
	movs r4, 0xBE
	lsls r4, 1
	adds r1, r3, r4
	ldr r2, [r1]
	ldr r3, _08020570
	movs r1, 0
	bl sub_80141B4
_08020562:
	add sp, 0x14
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_0802056C: .4byte gUnknown_80D8888
_08020570: .4byte 0x0000010d
	thumb_func_end sub_801FF28

	thumb_func_start sub_8020574
sub_8020574:
	push {r4,lr}
	ldr r4, _080205C0
	ldr r0, [r4]
	adds r0, 0xBC
	movs r1, 0
	movs r2, 0x10
	bl MemoryFill16
	ldr r4, [r4]
	movs r3, 0
	ldr r0, _080205C4
	str r0, [r4, 0x7C]
	adds r1, r4, 0
	adds r1, 0x80
	movs r0, 0x2
	str r0, [r1]
	movs r2, 0x1
	adds r1, 0x4
	ldr r0, _080205C8
	str r0, [r1]
	adds r1, 0x4
	movs r0, 0xB
	str r0, [r1]
	adds r1, 0x4
	ldr r0, _080205CC
	ldr r0, [r0]
	str r0, [r1]
	adds r0, r4, 0
	adds r0, 0x90
	str r2, [r0]
	adds r0, 0x4
	str r3, [r0]
	adds r0, 0x4
	str r2, [r0]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080205C0: .4byte gUnknown_203B27C
_080205C4: .4byte gUnknown_80DC3C4
_080205C8: .4byte gUnknown_80DC3CC
_080205CC: .4byte gUnknown_80D4934
	thumb_func_end sub_8020574

	thumb_func_start sub_80205D0
sub_80205D0:
	push {r4-r7,lr}
	ldr r4, _08020660
	ldr r0, [r4]
	adds r0, 0xBC
	movs r1, 0
	movs r2, 0x10
	bl MemoryFill16
	ldr r0, [r4]
	mov r12, r0
	movs r5, 0
	ldr r0, _08020664
	mov r1, r12
	str r0, [r1, 0x7C]
	mov r2, r12
	adds r2, 0x80
	movs r0, 0x4
	str r0, [r2]
	movs r3, 0x1
	adds r1, 0x84
	ldr r0, _08020668
	str r0, [r1]
	adds r1, 0x4
	movs r0, 0xB
	str r0, [r1]
	adds r1, 0x4
	ldr r0, _0802066C
	str r0, [r1]
	adds r1, 0x4
	movs r0, 0xC
	str r0, [r1]
	movs r6, 0x3
	adds r1, 0x4
	ldr r0, _08020670
	str r0, [r1]
	mov r0, r12
	adds r0, 0x98
	str r6, [r0]
	movs r6, 0x4
	adds r0, 0x4
	str r5, [r0]
	adds r0, 0x4
	str r3, [r0]
	mov r3, r12
	adds r3, 0xBC
_0802062A:
	ldrh r0, [r3]
	cmp r0, 0
	bne _0802063A
	ldr r1, [r2]
	mov r7, r12
	ldr r0, [r7, 0x70]
	cmp r1, r0
	beq _08020696
_0802063A:
	adds r2, 0x8
	adds r3, 0x2
	adds r5, 0x1
	cmp r5, r6
	blt _0802062A
	movs r5, 0
	cmp r5, r6
	bge _08020696
	ldr r1, [r4]
	adds r0, r1, 0
	adds r0, 0xBC
	ldrh r0, [r0]
	cmp r0, 0
	bne _08020674
	adds r0, r1, 0
	adds r0, 0x80
	ldr r0, [r0]
	str r0, [r1, 0x70]
	b _08020696
	.align 2, 0
_08020660: .4byte gUnknown_203B27C
_08020664: .4byte gUnknown_80DC3D8
_08020668: .4byte gUnknown_80DC3E0
_0802066C: .4byte gUnknown_80DC3E8
_08020670: .4byte gUnknown_80DC3F4
_08020674:
	adds r5, 0x1
	cmp r5, r6
	bge _08020696
	ldr r2, [r4]
	lsls r0, r5, 1
	adds r1, r2, 0
	adds r1, 0xBC
	adds r1, r0
	ldrh r0, [r1]
	cmp r0, 0
	bne _08020674
	lsls r0, r5, 3
	adds r1, r2, 0
	adds r1, 0x80
	adds r1, r0
	ldr r0, [r1]
	str r0, [r2, 0x70]
_08020696:
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_80205D0

	thumb_func_start sub_802069C
sub_802069C:
	push {r4-r7,lr}
	ldr r4, _08020718
	ldr r0, [r4]
	adds r0, 0xBC
	movs r1, 0
	movs r2, 0x10
	bl MemoryFill16
	ldr r0, [r4]
	mov r12, r0
	movs r5, 0
	ldr r0, _0802071C
	mov r1, r12
	str r0, [r1, 0x7C]
	mov r3, r12
	adds r3, 0x80
	movs r0, 0x3
	str r0, [r3]
	movs r2, 0x1
	adds r1, 0x84
	ldr r0, _08020720
	ldr r0, [r0]
	str r0, [r1]
	adds r1, 0x4
	movs r0, 0xB
	str r0, [r1]
	movs r6, 0x2
	mov r0, r12
	adds r0, 0x8C
	str r5, [r0]
	adds r0, 0x4
	str r2, [r0]
	mov r2, r12
	adds r2, 0xBC
_080206E0:
	ldrh r0, [r2]
	cmp r0, 0
	bne _080206F0
	ldr r1, [r3]
	mov r7, r12
	ldr r0, [r7, 0x74]
	cmp r1, r0
	beq _08020746
_080206F0:
	adds r3, 0x8
	adds r2, 0x2
	adds r5, 0x1
	cmp r5, r6
	blt _080206E0
	movs r5, 0
	cmp r5, r6
	bge _08020746
	ldr r1, [r4]
	adds r0, r1, 0
	adds r0, 0xBC
	ldrh r0, [r0]
	cmp r0, 0
	bne _08020724
	adds r0, r1, 0
	adds r0, 0x80
	ldr r0, [r0]
	str r0, [r1, 0x74]
	b _08020746
	.align 2, 0
_08020718: .4byte gUnknown_203B27C
_0802071C: .4byte gUnknown_80DC3F4
_08020720: .4byte gUnknown_80D4970
_08020724:
	adds r5, 0x1
	cmp r5, r6
	bge _08020746
	ldr r2, [r4]
	lsls r0, r5, 1
	adds r1, r2, 0
	adds r1, 0xBC
	adds r1, r0
	ldrh r0, [r1]
	cmp r0, 0
	bne _08020724
	lsls r0, r5, 3
	adds r1, r2, 0
	adds r1, 0x80
	adds r1, r0
	ldr r0, [r1]
	str r0, [r2, 0x74]
_08020746:
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_802069C

	thumb_func_start sub_802074C
sub_802074C:
	push {r4-r7,lr}
	movs r7, 0
	ldr r4, _08020780
	ldr r0, [r4]
	adds r0, 0xBC
	movs r1, 0
	movs r2, 0x10
	bl MemoryFill16
	ldr r1, [r4]
	ldrb r0, [r1, 0x16]
	cmp r0, 0
	beq _0802079C
	ldr r0, [r1, 0x18]
	adds r1, 0x24
	bl sub_80932E0
	lsls r0, 24
	cmp r0, 0
	beq _08020788
	ldr r0, [r4]
	ldr r1, _08020784
	str r1, [r0, 0x7C]
	adds r0, 0x80
	movs r1, 0x6
	b _08020792
	.align 2, 0
_08020780: .4byte gUnknown_203B27C
_08020784: .4byte gUnknown_80DC400
_08020788:
	ldr r0, [r4]
	ldr r1, _08020798
	str r1, [r0, 0x7C]
	adds r0, 0x80
	movs r1, 0x5
_08020792:
	str r1, [r0]
	mov r12, r4
	b _080207CA
	.align 2, 0
_08020798: .4byte gUnknown_80DC40C
_0802079C:
	ldr r0, [r1, 0x18]
	adds r1, 0x24
	bl sub_80932FC
	lsls r0, 24
	cmp r0, 0
	beq _080207B4
	ldr r1, [r4]
	ldr r0, _080207B0
	b _080207B8
	.align 2, 0
_080207B0: .4byte gUnknown_80DC400
_080207B4:
	ldr r1, [r4]
	ldr r0, _0802086C
_080207B8:
	str r0, [r1, 0x7C]
	ldr r2, _08020870
	ldr r0, [r2]
	lsls r1, r7, 3
	adds r0, 0x80
	adds r0, r1
	movs r1, 0x7
	str r1, [r0]
	mov r12, r2
_080207CA:
	adds r7, 0x1
	mov r0, r12
	ldr r4, [r0]
	lsls r1, r7, 3
	adds r3, r4, 0
	adds r3, 0x7C
	adds r2, r3, r1
	ldr r0, _08020874
	str r0, [r2]
	adds r6, r4, 0
	adds r6, 0x80
	adds r1, r6, r1
	movs r0, 0x8
	str r0, [r1]
	adds r7, 0x1
	lsls r1, r7, 3
	adds r2, r3, r1
	ldr r0, _08020878
	str r0, [r2]
	adds r1, r6, r1
	movs r0, 0x9
	str r0, [r1]
	adds r7, 0x1
	lsls r1, r7, 3
	adds r2, r3, r1
	ldr r0, _0802087C
	str r0, [r2]
	adds r1, r6, r1
	movs r0, 0xA
	str r0, [r1]
	adds r7, 0x1
	lsls r1, r7, 3
	adds r2, r3, r1
	ldr r0, _08020880
	ldr r0, [r0]
	str r0, [r2]
	adds r1, r6, r1
	movs r0, 0xB
	str r0, [r1]
	adds r7, 0x1
	lsls r1, r7, 3
	adds r3, r1
	movs r0, 0
	str r0, [r3]
	adds r1, r6, r1
	movs r0, 0x1
	str r0, [r1]
	movs r3, 0
	cmp r3, r7
	bge _0802084C
	adds r5, r4, 0
	adds r4, 0xBC
	adds r2, r6, 0
_08020834:
	ldrh r0, [r4]
	cmp r0, 0
	bne _08020842
	ldr r1, [r2]
	ldr r0, [r5, 0x78]
	cmp r1, r0
	beq _080208A8
_08020842:
	adds r4, 0x2
	adds r2, 0x8
	adds r3, 0x1
	cmp r3, r7
	blt _08020834
_0802084C:
	movs r3, 0
	cmp r3, r7
	bge _080208A8
	mov r0, r12
	ldr r1, [r0]
	adds r0, r1, 0
	adds r0, 0xBC
	ldrh r0, [r0]
	cmp r0, 0
	bne _08020884
	adds r0, r1, 0
	adds r0, 0x80
	ldr r0, [r0]
	str r0, [r1, 0x78]
	b _080208A8
	.align 2, 0
_0802086C: .4byte gUnknown_80DC40C
_08020870: .4byte gUnknown_203B27C
_08020874: .4byte gUnknown_80DC410
_08020878: .4byte gUnknown_80DC418
_0802087C: .4byte gUnknown_80DC420
_08020880: .4byte gUnknown_80D4970
_08020884:
	adds r3, 0x1
	cmp r3, r7
	bge _080208A8
	mov r0, r12
	ldr r2, [r0]
	lsls r0, r3, 1
	adds r1, r2, 0
	adds r1, 0xBC
	adds r1, r0
	ldrh r0, [r1]
	cmp r0, 0
	bne _08020884
	lsls r0, r3, 3
	adds r1, r2, 0
	adds r1, 0x80
	adds r1, r0
	ldr r0, [r1]
	str r0, [r2, 0x78]
_080208A8:
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_802074C

	thumb_func_start sub_80208B0
sub_80208B0:
	push {r4,lr}
	ldr r4, _080208F4
	ldr r0, [r4]
	adds r0, 0xBC
	movs r1, 0
	movs r2, 0x10
	bl MemoryFill16
	ldr r4, [r4]
	movs r3, 0
	ldr r0, _080208F8
	ldr r0, [r0]
	str r0, [r4, 0x7C]
	adds r1, r4, 0
	adds r1, 0x80
	movs r0, 0x10
	str r0, [r1]
	movs r2, 0x1
	adds r1, 0x4
	ldr r0, _080208FC
	ldr r0, [r0]
	str r0, [r1]
	adds r1, 0x4
	movs r0, 0x11
	str r0, [r1]
	adds r0, r4, 0
	adds r0, 0x8C
	str r3, [r0]
	adds r0, 0x4
	str r2, [r0]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080208F4: .4byte gUnknown_203B27C
_080208F8: .4byte gUnknown_80D4920
_080208FC: .4byte gUnknown_80D4928
	thumb_func_end sub_80208B0

	thumb_func_start sub_8020900
sub_8020900:
	push {r4,lr}
	ldr r4, _08020944
	ldr r0, [r4]
	adds r0, 0xBC
	movs r1, 0
	movs r2, 0x10
	bl MemoryFill16
	ldr r3, [r4]
	movs r2, 0
	ldr r0, _08020948
	ldr r0, [r0]
	str r0, [r3, 0x7C]
	adds r1, r3, 0
	adds r1, 0x80
	movs r0, 0x10
	str r0, [r1]
	adds r1, 0x4
	ldr r0, _0802094C
	ldr r0, [r0]
	str r0, [r1]
	adds r1, 0x4
	movs r0, 0x11
	str r0, [r1]
	adds r0, r3, 0
	adds r0, 0x8C
	str r2, [r0]
	adds r1, 0x8
	movs r0, 0x1
	negs r0, r0
	str r0, [r1]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08020944: .4byte gUnknown_203B27C
_08020948: .4byte gUnknown_80D4920
_0802094C: .4byte gUnknown_80D4928
	thumb_func_end sub_8020900

	thumb_func_start sub_8020950
sub_8020950:
	push {r4,lr}
	ldr r4, _0802099C
	ldr r0, [r4]
	adds r0, 0xBC
	movs r1, 0
	movs r2, 0x10
	bl MemoryFill16
	ldr r4, [r4]
	movs r3, 0
	ldr r0, _080209A0
	str r0, [r4, 0x7C]
	adds r1, r4, 0
	adds r1, 0x80
	movs r0, 0xD
	str r0, [r1]
	movs r2, 0x1
	adds r1, 0x4
	ldr r0, _080209A4
	str r0, [r1]
	adds r1, 0x4
	movs r0, 0xE
	str r0, [r1]
	adds r1, 0x4
	ldr r0, _080209A8
	str r0, [r1]
	adds r1, 0x4
	movs r0, 0xF
	str r0, [r1]
	adds r0, r4, 0
	adds r0, 0x94
	str r3, [r0]
	adds r0, 0x4
	str r2, [r0]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0802099C: .4byte gUnknown_203B27C
_080209A0: .4byte gUnknown_80DC428
_080209A4: .4byte gUnknown_80DC438
_080209A8: .4byte gUnknown_80DC448
	thumb_func_end sub_8020950

	thumb_func_start sub_80209AC
sub_80209AC:
	push {lr}
	sub sp, 0x4
	mov r0, sp
	bl sub_80144A4
	cmp r0, 0
	bne _080209F4
	ldr r0, _080209D4
	ldr r1, [r0]
	ldr r0, [sp]
	str r0, [r1, 0x6C]
	ldr r0, [sp]
	cmp r0, 0x2
	beq _080209DE
	cmp r0, 0x2
	bgt _080209D8
	cmp r0, 0x1
	beq _080209EE
	b _080209F4
	.align 2, 0
_080209D4: .4byte gUnknown_203B27C
_080209D8:
	cmp r0, 0xB
	beq _080209E6
	b _080209F4
_080209DE:
	movs r0, 0xE
	bl sub_801FDA8
	b _080209F4
_080209E6:
	movs r0, 0x8
	bl sub_801FDA8
	b _080209F4
_080209EE:
	movs r0, 0xC
	bl sub_801FDA8
_080209F4:
	add sp, 0x4
	pop {r0}
	bx r0
	thumb_func_end sub_80209AC

	thumb_func_start sub_80209FC
sub_80209FC:
	push {lr}
	sub sp, 0x4
	mov r0, sp
	bl sub_80144A4
	cmp r0, 0
	bne _08020A2E
	ldr r0, [sp]
	cmp r0, 0x10
	beq _08020A20
	cmp r0, 0x10
	bgt _08020A1A
	cmp r0, 0x1
	beq _08020A28
	b _08020A2E
_08020A1A:
	cmp r0, 0x11
	beq _08020A28
	b _08020A2E
_08020A20:
	movs r0, 0xE
	bl sub_801FDA8
	b _08020A2E
_08020A28:
	movs r0, 0xC
	bl sub_801FDA8
_08020A2E:
	add sp, 0x4
	pop {r0}
	bx r0
	thumb_func_end sub_80209FC

	thumb_func_start sub_8020A34
sub_8020A34:
	push {lr}
	sub sp, 0x4
	mov r0, sp
	bl sub_80144A4
	cmp r0, 0
	bne _08020A7A
	ldr r0, [sp]
	cmp r0, 0xD
	beq _08020A5C
	cmp r0, 0xD
	bgt _08020A52
	cmp r0, 0x1
	beq _08020A74
	b _08020A7A
_08020A52:
	cmp r0, 0xE
	beq _08020A64
	cmp r0, 0xF
	beq _08020A6C
	b _08020A7A
_08020A5C:
	movs r0, 0x9
	bl sub_801FDA8
	b _08020A7A
_08020A64:
	movs r0, 0xA
	bl sub_801FDA8
	b _08020A7A
_08020A6C:
	movs r0, 0xB
	bl sub_801FDA8
	b _08020A7A
_08020A74:
	movs r0, 0x1
	bl sub_801FDA8
_08020A7A:
	add sp, 0x4
	pop {r0}
	bx r0
	thumb_func_end sub_8020A34

	thumb_func_start sub_8020A80
sub_8020A80:
	push {r4,lr}
	movs r0, 0x1
	bl sub_8023A94
	cmp r0, 0x4
	bhi _08020B32
	lsls r0, 2
	ldr r1, _08020A98
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08020A98: .4byte _08020A9C
	.align 2, 0
_08020A9C:
	.4byte _08020B32
	.4byte _08020B32
	.4byte _08020B28
	.4byte _08020AB0
	.4byte _08020AEC
_08020AB0:
	bl sub_8023B44
	ldr r4, _08020AE0
	ldr r1, [r4]
	strh r0, [r1, 0xC]
	ldr r3, _08020AE4
	movs r0, 0xC
	ldrsh r2, [r1, r0]
	movs r0, 0x58
	muls r2, r0
	ldr r0, [r3]
	adds r0, r2
	str r0, [r1, 0x10]
	ldrb r0, [r0, 0x2]
	strb r0, [r1, 0x16]
	ldr r0, _08020AE8
	ldr r1, [r4]
	ldr r1, [r1, 0x10]
	bl sub_808DA34
	movs r0, 0x11
	bl sub_801FDA8
	b _08020B32
	.align 2, 0
_08020AE0: .4byte gUnknown_203B27C
_08020AE4: .4byte gUnknown_203B45C
_08020AE8: .4byte gUnknown_202E128
_08020AEC:
	bl sub_8023B44
	ldr r4, _08020B1C
	ldr r1, [r4]
	strh r0, [r1, 0xC]
	ldr r3, _08020B20
	movs r0, 0xC
	ldrsh r2, [r1, r0]
	movs r0, 0x58
	muls r2, r0
	ldr r0, [r3]
	adds r0, r2
	str r0, [r1, 0x10]
	ldrb r0, [r0, 0x2]
	strb r0, [r1, 0x16]
	ldr r0, _08020B24
	ldr r1, [r4]
	ldr r1, [r1, 0x10]
	bl sub_808DA34
	movs r0, 0x12
	bl sub_801FDA8
	b _08020B32
	.align 2, 0
_08020B1C: .4byte gUnknown_203B27C
_08020B20: .4byte gUnknown_203B45C
_08020B24: .4byte gUnknown_202E128
_08020B28:
	bl sub_8023C60
	movs r0, 0x7
	bl sub_801FDA8
_08020B32:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_8020A80

	thumb_func_start sub_8020B38
sub_8020B38:
	push {r4,lr}
	sub sp, 0x4
	movs r0, 0
	str r0, [sp]
	bl sub_8023A94
	ldr r4, _08020B7C
	ldr r0, [r4]
	adds r0, 0xCC
	bl sub_8012FD8
	lsls r0, 24
	cmp r0, 0
	bne _08020B68
	ldr r0, [r4]
	adds r0, 0xCC
	mov r1, sp
	bl sub_8013114
	ldr r1, [sp]
	cmp r1, 0x1
	beq _08020B68
	ldr r0, [r4]
	str r1, [r0, 0x70]
_08020B68:
	ldr r0, [sp]
	subs r0, 0x1
	cmp r0, 0x10
	bhi _08020C24
	lsls r0, 2
	ldr r1, _08020B80
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08020B7C: .4byte gUnknown_203B27C
_08020B80: .4byte _08020B84
	.align 2, 0
_08020B84:
	.4byte _08020BC8
	.4byte _08020C24
	.4byte _08020BD0
	.4byte _08020C0E
	.4byte _08020C24
	.4byte _08020C24
	.4byte _08020C24
	.4byte _08020C24
	.4byte _08020C24
	.4byte _08020C24
	.4byte _08020C16
	.4byte _08020C1E
	.4byte _08020C24
	.4byte _08020C24
	.4byte _08020C24
	.4byte _08020C24
	.4byte _08020BC8
_08020BC8:
	movs r0, 0x10
	bl sub_801FDA8
	b _08020C24
_08020BD0:
	ldr r0, _08020BF0
	ldr r0, [r0]
	ldr r0, [r0, 0x10]
	movs r1, 0x8
	ldrsh r0, [r0, r1]
	bl sub_808E858
	lsls r0, 16
	movs r1, 0xCF
	lsls r1, 17
	cmp r0, r1
	bne _08020BF4
	movs r0, 0x1C
	bl sub_801FDA8
	b _08020C24
	.align 2, 0
_08020BF0: .4byte gUnknown_203B27C
_08020BF4:
	bl sub_8021178
	lsls r0, 24
	cmp r0, 0
	beq _08020C06
	movs r0, 0x1B
	bl sub_801FDA8
	b _08020C24
_08020C06:
	movs r0, 0x14
	bl sub_801FDA8
	b _08020C24
_08020C0E:
	movs r0, 0x1E
	bl sub_801FDA8
	b _08020C24
_08020C16:
	movs r0, 0x12
	bl sub_801FDA8
	b _08020C24
_08020C1E:
	movs r0, 0x13
	bl sub_801FDA8
_08020C24:
	add sp, 0x4
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_8020B38

	thumb_func_start sub_8020C2C
sub_8020C2C:
	push {lr}
	bl sub_80244E4
	cmp r0, 0x1
	bls _08020C44
	cmp r0, 0x3
	bhi _08020C44
	bl sub_802453C
	movs r0, 0x10
	bl sub_801FDA8
_08020C44:
	pop {r0}
	bx r0
	thumb_func_end sub_8020C2C

	thumb_func_start sub_8020C48
sub_8020C48:
	push {lr}
	bl sub_801BF48
	cmp r0, 0x1
	bls _08020C60
	cmp r0, 0x3
	bhi _08020C60
	bl sub_801BF98
	movs r0, 0x10
	bl sub_801FDA8
_08020C60:
	pop {r0}
	bx r0
	thumb_func_end sub_8020C48

	thumb_func_start sub_8020C64
sub_8020C64:
	push {lr}
	movs r0, 0x1
	bl sub_801F520
	cmp r0, 0x3
	beq _08020C80
	cmp r0, 0x3
	bhi _08020C7A
	cmp r0, 0x2
	beq _08020CB0
	b _08020CBA
_08020C7A:
	cmp r0, 0x4
	beq _08020C98
	b _08020CBA
_08020C80:
	bl sub_801F5B4
	ldr r1, _08020C94
	ldr r1, [r1]
	strh r0, [r1, 0x1C]
	strh r0, [r1, 0x1E]
	movs r0, 0x17
	bl sub_801FDA8
	b _08020CBA
	.align 2, 0
_08020C94: .4byte gUnknown_203B27C
_08020C98:
	bl sub_801F5B4
	ldr r1, _08020CAC
	ldr r1, [r1]
	strh r0, [r1, 0x1C]
	strh r0, [r1, 0x1E]
	movs r0, 0x18
	bl sub_801FDA8
	b _08020CBA
	.align 2, 0
_08020CAC: .4byte gUnknown_203B27C
_08020CB0:
	bl sub_801F63C
	movs r0, 0x10
	bl sub_801FDA8
_08020CBA:
	pop {r0}
	bx r0
	thumb_func_end sub_8020C64

	thumb_func_start sub_8020CC0
sub_8020CC0:
	push {r4-r6,lr}
	sub sp, 0x4
	movs r0, 0
	str r0, [sp]
	bl sub_801F520
	ldr r4, _08020D00
	ldr r0, [r4]
	adds r0, 0xCC
	bl sub_8012FD8
	lsls r0, 24
	cmp r0, 0
	bne _08020CF0
	ldr r0, [r4]
	adds r0, 0xCC
	mov r1, sp
	bl sub_8013114
	ldr r1, [sp]
	cmp r1, 0x1
	beq _08020CF0
	ldr r0, [r4]
	str r1, [r0, 0x74]
_08020CF0:
	ldr r0, [sp]
	cmp r0, 0x3
	beq _08020D14
	cmp r0, 0x3
	bgt _08020D04
	cmp r0, 0x1
	beq _08020D0C
	b _08020D6C
	.align 2, 0
_08020D00: .4byte gUnknown_203B27C
_08020D04:
	cmp r0, 0xB
	beq _08020D66
	cmp r0, 0x11
	bne _08020D6C
_08020D0C:
	movs r0, 0x16
	bl sub_801FDA8
	b _08020D6C
_08020D14:
	bl sub_801F63C
	ldr r4, _08020D30
	ldr r1, [r4]
	adds r0, r1, 0
	adds r0, 0x24
	ldr r1, [r1, 0x10]
	adds r1, 0x2C
	bl sub_809401C
	movs r5, 0
	adds r6, r4, 0
	movs r4, 0x24
	b _08020D38
	.align 2, 0
_08020D30: .4byte gUnknown_203B27C
_08020D34:
	adds r4, 0x8
	adds r5, 0x1
_08020D38:
	cmp r5, 0x7
	bgt _08020D52
	ldr r3, [r6]
	adds r2, r3, r4
	ldrb r1, [r2]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	bne _08020D34
	ldrh r1, [r3, 0x1E]
	adds r0, r2, 0
	bl sub_8092AD4
_08020D52:
	cmp r5, 0x3
	ble _08020D5E
	movs r0, 0x1D
	bl sub_801FDA8
	b _08020D6C
_08020D5E:
	movs r0, 0x19
	bl sub_801FDA8
	b _08020D6C
_08020D66:
	movs r0, 0x18
	bl sub_801FDA8
_08020D6C:
	add sp, 0x4
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end sub_8020CC0

	thumb_func_start sub_8020D74
sub_8020D74:
	push {lr}
	bl sub_801F890
	cmp r0, 0x1
	bls _08020D8C
	cmp r0, 0x3
	bhi _08020D8C
	bl sub_801F8D0
	movs r0, 0x16
	bl sub_801FDA8
_08020D8C:
	pop {r0}
	bx r0
	thumb_func_end sub_8020D74

	thumb_func_start sub_8020D90
sub_8020D90:
	push {lr}
	bl sub_801E8C0
	cmp r0, 0x2
	beq _08020DBC
	cmp r0, 0x2
	bcc _08020DC6
	cmp r0, 0x3
	bne _08020DC6
	bl sub_801E930
	ldr r1, _08020DB8
	ldr r1, [r1]
	strb r0, [r1, 0x14]
	bl sub_801E93C
	movs r0, 0x1A
	bl sub_801FDA8
	b _08020DC6
	.align 2, 0
_08020DB8: .4byte gUnknown_203B27C
_08020DBC:
	bl sub_801E93C
	movs r0, 0x10
	bl sub_801FDA8
_08020DC6:
	pop {r0}
	bx r0
	thumb_func_end sub_8020D90

	thumb_func_start sub_8020DCC
sub_8020DCC:
	push {lr}
	movs r0, 0x1
	bl sub_801EF38
	cmp r0, 0x4
	bhi _08020EAA
	lsls r0, 2
	ldr r1, _08020DE4
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08020DE4: .4byte _08020DE8
	.align 2, 0
_08020DE8:
	.4byte _08020EAA
	.4byte _08020E98
	.4byte _08020E64
	.4byte _08020DFC
	.4byte _08020E30
_08020DFC:
	bl sub_801F1A4
	lsls r0, 24
	cmp r0, 0
	beq _08020E0E
	ldr r0, _08020E2C
	ldr r1, [r0]
	movs r0, 0x1
	strb r0, [r1, 0x15]
_08020E0E:
	bl sub_801F194
	ldr r1, _08020E2C
	ldr r2, [r1]
	str r0, [r2, 0x18]
	lsls r0, 3
	adds r0, r2, r0
	ldrh r1, [r0, 0x26]
	strh r1, [r2, 0x1C]
	ldrh r0, [r0, 0x26]
	strh r0, [r2, 0x20]
	movs r0, 0x20
	bl sub_801FDA8
	b _08020EAA
	.align 2, 0
_08020E2C: .4byte gUnknown_203B27C
_08020E30:
	bl sub_801F1A4
	lsls r0, 24
	cmp r0, 0
	beq _08020E42
	ldr r0, _08020E60
	ldr r1, [r0]
	movs r0, 0x1
	strb r0, [r1, 0x15]
_08020E42:
	bl sub_801F194
	ldr r1, _08020E60
	ldr r2, [r1]
	str r0, [r2, 0x18]
	lsls r0, 3
	adds r0, r2, r0
	ldrh r1, [r0, 0x26]
	strh r1, [r2, 0x1C]
	ldrh r0, [r0, 0x26]
	strh r0, [r2, 0x20]
	movs r0, 0x21
	bl sub_801FDA8
	b _08020EAA
	.align 2, 0
_08020E60: .4byte gUnknown_203B27C
_08020E64:
	bl sub_801F1A4
	lsls r0, 24
	cmp r0, 0
	beq _08020E76
	ldr r0, _08020E94
	ldr r1, [r0]
	movs r0, 0x1
	strb r0, [r1, 0x15]
_08020E76:
	bl sub_801F214
	ldr r0, _08020E94
	ldr r1, [r0]
	adds r0, r1, 0
	adds r0, 0x24
	ldr r1, [r1, 0x10]
	adds r1, 0x2C
	bl sub_8094060
	movs r0, 0x10
	bl sub_801FDA8
	b _08020EAA
	.align 2, 0
_08020E94: .4byte gUnknown_203B27C
_08020E98:
	bl sub_801F1A4
	lsls r0, 24
	cmp r0, 0
	beq _08020EAA
	ldr r0, _08020EB0
	ldr r1, [r0]
	movs r0, 0x1
	strb r0, [r1, 0x15]
_08020EAA:
	pop {r0}
	bx r0
	.align 2, 0
_08020EB0: .4byte gUnknown_203B27C
	thumb_func_end sub_8020DCC

	thumb_func_start sub_8020EB4
sub_8020EB4:
	push {r4,lr}
	sub sp, 0x4
	movs r0, 0
	str r0, [sp]
	bl sub_801EF38
	ldr r4, _08020EF8
	ldr r0, [r4]
	adds r0, 0xCC
	bl sub_8012FD8
	lsls r0, 24
	cmp r0, 0
	bne _08020EE4
	ldr r0, [r4]
	adds r0, 0xCC
	mov r1, sp
	bl sub_8013114
	ldr r1, [sp]
	cmp r1, 0x1
	beq _08020EE4
	ldr r0, [r4]
	str r1, [r0, 0x78]
_08020EE4:
	ldr r0, [sp]
	subs r0, 0x1
	cmp r0, 0x10
	bls _08020EEE
	b _080210BE
_08020EEE:
	lsls r0, 2
	ldr r1, _08020EFC
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08020EF8: .4byte gUnknown_203B27C
_08020EFC: .4byte _08020F00
	.align 2, 0
_08020F00:
	.4byte _08021068
	.4byte _080210BE
	.4byte _080210BE
	.4byte _080210BE
	.4byte _08020F44
	.4byte _08020F70
	.4byte _08020F8C
	.4byte _08020FB8
	.4byte _08021034
	.4byte _08021074
	.4byte _080210B8
	.4byte _080210BE
	.4byte _080210BE
	.4byte _080210BE
	.4byte _080210BE
	.4byte _080210BE
	.4byte _08021068
_08020F44:
	ldr r0, _08020F60
	ldr r1, [r0]
	ldr r0, [r1, 0x18]
	adds r1, 0x24
	bl sub_80934DC
	lsls r0, 24
	cmp r0, 0
	beq _08020F68
	ldr r0, _08020F64
	bl sub_8011988
	b _08021068
	.align 2, 0
_08020F60: .4byte gUnknown_203B27C
_08020F64: .4byte 0x00000133
_08020F68:
	movs r0, 0x2
	bl sub_80119D4
	b _08021068
_08020F70:
	ldr r0, _08020F84
	bl sub_8011988
	ldr r0, _08020F88
	ldr r1, [r0]
	ldr r0, [r1, 0x18]
	adds r1, 0x24
	bl sub_809352C
	b _08021068
	.align 2, 0
_08020F84: .4byte 0x00000133
_08020F88: .4byte gUnknown_203B27C
_08020F8C:
	ldr r0, _08020FA8
	ldr r1, [r0]
	ldr r0, [r1, 0x18]
	adds r1, 0x24
	bl sub_8093544
	lsls r0, 24
	cmp r0, 0
	beq _08020FB0
	ldr r0, _08020FAC
	bl sub_8011988
	b _08021068
	.align 2, 0
_08020FA8: .4byte gUnknown_203B27C
_08020FAC: .4byte 0x00000133
_08020FB0:
	movs r0, 0x2
	bl sub_80119D4
	b _08021068
_08020FB8:
	ldr r0, _08020FD8
	ldr r0, [r0]
	movs r1, 0x98
	lsls r1, 2
	adds r0, r1
	ldr r0, [r0]
	cmp r0, 0x95
	bgt _08020FDC
	movs r0, 0x2
	bl sub_80119D4
	movs r0, 0x3
	bl sub_801FDA8
	b _080210BE
	.align 2, 0
_08020FD8: .4byte gUnknown_203B460
_08020FDC:
	ldr r4, _08020FFC
	ldr r1, [r4]
	ldr r0, [r1, 0x18]
	adds r1, 0x24
	bl sub_8093318
	lsls r0, 24
	cmp r0, 0
	bne _08021000
	movs r0, 0x2
	bl sub_80119D4
	movs r0, 0x4
	bl sub_801FDA8
	b _080210BE
	.align 2, 0
_08020FFC: .4byte gUnknown_203B27C
_08021000:
	ldr r1, [r4]
	ldrb r0, [r1, 0x15]
	cmp r0, 0
	bne _08021016
	movs r0, 0x1
	strb r0, [r1, 0x15]
	movs r0, 0xA6
	lsls r0, 1
	bl sub_8011988
	b _0802101C
_08021016:
	ldr r0, _0802102C
	bl sub_8011988
_0802101C:
	ldr r0, _08021030
	ldr r1, [r0]
	ldr r0, [r1, 0x18]
	adds r1, 0x24
	bl sub_8093400
	b _08021068
	.align 2, 0
_0802102C: .4byte 0x00000133
_08021030: .4byte gUnknown_203B27C
_08021034:
	ldr r4, _08021054
	ldr r1, [r4]
	ldr r0, [r1, 0x18]
	adds r1, 0x24
	bl sub_809333C
	lsls r0, 24
	cmp r0, 0
	bne _08021058
	movs r0, 0x2
	bl sub_80119D4
	movs r0, 0x5
	bl sub_801FDA8
	b _080210BE
	.align 2, 0
_08021054: .4byte gUnknown_203B27C
_08021058:
	ldr r0, _08021070
	bl sub_8011988
	ldr r1, [r4]
	ldr r0, [r1, 0x18]
	adds r1, 0x24
	bl sub_8093468
_08021068:
	movs r0, 0x1F
	bl sub_801FDA8
	b _080210BE
	.align 2, 0
_08021070: .4byte 0x00000133
_08021074:
	ldr r4, _08021094
	ldr r1, [r4]
	ldr r0, [r1, 0x18]
	adds r1, 0x24
	bl sub_80933A0
	lsls r0, 24
	cmp r0, 0
	bne _08021098
	movs r0, 0x2
	bl sub_80119D4
	movs r0, 0x6
	bl sub_801FDA8
	b _080210BE
	.align 2, 0
_08021094: .4byte gUnknown_203B27C
_08021098:
	ldr r0, _080210B4
	bl sub_8011988
	ldr r1, [r4]
	ldr r0, [r1, 0x18]
	adds r1, 0x24
	bl sub_80934B0
	ldr r1, [r4]
	strb r0, [r1, 0x14]
	movs r0, 0x22
	bl sub_801FDA8
	b _080210BE
	.align 2, 0
_080210B4: .4byte 0x00000133
_080210B8:
	movs r0, 0x21
	bl sub_801FDA8
_080210BE:
	add sp, 0x4
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_8020EB4

	thumb_func_start sub_80210C8
sub_80210C8:
	push {lr}
	bl sub_801F890
	cmp r0, 0x1
	bls _080210E0
	cmp r0, 0x3
	bhi _080210E0
	bl sub_801F8D0
	movs r0, 0x1F
	bl sub_801FDA8
_080210E0:
	pop {r0}
	bx r0
	thumb_func_end sub_80210C8

	thumb_func_start sub_80210E4
sub_80210E4:
	push {lr}
	sub sp, 0x4
	mov r0, sp
	bl sub_80144A4
	cmp r0, 0
	bne _0802112A
	ldr r0, [sp]
	cmp r0, 0x10
	beq _08021108
	cmp r0, 0x10
	bgt _08021102
	cmp r0, 0x1
	beq _08021124
	b _0802112A
_08021102:
	cmp r0, 0x11
	beq _08021124
	b _0802112A
_08021108:
	ldr r0, _08021120
	ldr r1, [r0]
	adds r0, r1, 0
	adds r0, 0x24
	ldr r1, [r1, 0x18]
	bl sub_8093CF8
	movs r0, 0x23
	bl sub_801FDA8
	b _0802112A
	.align 2, 0
_08021120: .4byte gUnknown_203B27C
_08021124:
	movs r0, 0x1F
	bl sub_801FDA8
_0802112A:
	add sp, 0x4
	pop {r0}
	bx r0
	thumb_func_end sub_80210E4

	thumb_func_start sub_8021130
sub_8021130:
	push {lr}
	sub sp, 0x4
	mov r0, sp
	bl sub_80144A4
	cmp r0, 0
	bne _08021148
	ldr r0, _08021150
	ldr r0, [r0]
	ldr r0, [r0, 0x8]
	bl sub_801FDA8
_08021148:
	add sp, 0x4
	pop {r0}
	bx r0
	.align 2, 0
_08021150: .4byte gUnknown_203B27C
	thumb_func_end sub_8021130

	thumb_func_start sub_8021154
sub_8021154:
	push {lr}
	sub sp, 0x4
	mov r0, sp
	bl sub_80144A4
	cmp r0, 0x4
	bne _0802116C
	ldr r0, _08021174
	ldr r0, [r0]
	ldr r0, [r0, 0x8]
	bl sub_801FDA8
_0802116C:
	add sp, 0x4
	pop {r0}
	bx r0
	.align 2, 0
_08021174: .4byte gUnknown_203B27C
	thumb_func_end sub_8021154

	thumb_func_start sub_8021178
sub_8021178:
	push {lr}
	mov r12, r4
	ldr r4, _08021198
	add sp, r4
	mov r4, r12
	ldr r0, _0802119C
	ldr r0, [r0]
	ldr r1, [r0, 0x10]
	mov r0, sp
	bl sub_808E218
	cmp r0, 0
	beq _080211A0
	movs r0, 0
	b _080211A2
	.align 2, 0
_08021198: .4byte 0xfffffcc0
_0802119C: .4byte gUnknown_203B27C
_080211A0:
	movs r0, 0x1
_080211A2:
	movs r3, 0xD0
	lsls r3, 2
	add sp, r3
	pop {r1}
	bx r1
	thumb_func_end sub_8021178

	thumb_func_start sub_80211AC
sub_80211AC:
	push {r4-r6,lr}
	adds r4, r0, 0
	adds r6, r1, 0
	bl sub_8021700
	lsls r0, 24
	cmp r0, 0
	beq _080211C0
	movs r0, 0
	b _08021258
_080211C0:
	ldr r5, _08021260
	movs r0, 0xE0
	movs r1, 0x8
	bl MemoryAlloc
	str r0, [r5]
	str r4, [r0, 0x3C]
	str r6, [r0, 0x74]
	lsls r1, r6, 1
	adds r1, r6
	lsls r1, 3
	adds r1, 0x7C
	adds r1, r0, r1
	str r1, [r0, 0x78]
	adds r0, 0x7C
	bl sub_8006518
	ldr r1, [r5]
	ldr r2, [r1, 0x74]
	lsls r0, r2, 1
	adds r0, r2
	lsls r0, 3
	adds r1, r0
	adds r1, 0x7C
	ldr r0, _08021264
	ldm r0!, {r2-r4}
	stm r1!, {r2-r4}
	ldm r0!, {r2-r4}
	stm r1!, {r2-r4}
	ldr r0, [r5]
	ldr r1, [r0, 0x78]
	adds r0, 0xDC
	str r0, [r1, 0x14]
	bl sub_8004914
	ldr r0, [r5]
	adds r0, 0x7C
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	ldr r4, [r5]
	adds r4, 0x40
	bl sub_8021664
	adds r1, r0, 0
	adds r0, r4, 0
	movs r2, 0xA
	adds r3, r6, 0
	bl sub_8013818
	ldr r0, _08021268
	ldr r2, [r5]
	ldr r1, [r0]
	ldr r0, [r2, 0x3C]
	cmp r1, r0
	bne _0802124E
	ldr r0, _0802126C
	ldrh r1, [r0]
	adds r0, r2, 0
	adds r0, 0x58
	strh r1, [r0]
	ldr r0, _08021270
	ldrh r0, [r0]
	adds r1, r2, 0
	adds r1, 0x5E
	strh r0, [r1]
	adds r0, r2, 0
	adds r0, 0x40
	bl sub_8013984
_0802124E:
	bl sub_8021410
	bl sub_8021494
	movs r0, 0x1
_08021258:
	pop {r4-r6}
	pop {r1}
	bx r1
	.align 2, 0
_08021260: .4byte gUnknown_203B280
_08021264: .4byte gUnknown_80DC47C
_08021268: .4byte gUnknown_203B284
_0802126C: .4byte gUnknown_203B288
_08021270: .4byte gUnknown_203B28A
	thumb_func_end sub_80211AC

	thumb_func_start sub_8021274
sub_8021274:
	push {r4,lr}
	lsls r0, 24
	cmp r0, 0
	bne _08021290
	ldr r0, _0802128C
	ldr r0, [r0]
	adds r0, 0x40
	bl sub_8013660
	movs r0, 0
	b _08021326
	.align 2, 0
_0802128C: .4byte gUnknown_203B280
_08021290:
	ldr r4, _080212A8
	ldr r0, [r4]
	adds r0, 0x40
	bl GetKeyPress
	cmp r0, 0x2
	beq _080212B2
	cmp r0, 0x2
	bgt _080212AC
	cmp r0, 0x1
	beq _080212BC
	b _08021300
	.align 2, 0
_080212A8: .4byte gUnknown_203B280
_080212AC:
	cmp r0, 0x4
	beq _080212F6
	b _08021300
_080212B2:
	movs r0, 0x1
	bl sub_80119D4
	movs r0, 0x2
	b _08021326
_080212BC:
	ldr r0, [r4]
	ldr r0, [r0, 0x3C]
	cmp r0, 0x2
	bne _080212EC
	bl sub_802132C
	lsls r0, 24
	lsrs r0, 24
	bl sub_8092544
	ldr r1, _080212E8
	ldr r1, [r1]
	movs r2, 0x98
	lsls r2, 2
	adds r1, r2
	ldr r1, [r1]
	cmp r0, r1
	ble _080212EC
	movs r0, 0x2
	bl sub_80119D4
	b _080212F2
	.align 2, 0
_080212E8: .4byte gUnknown_203B460
_080212EC:
	movs r0, 0
	bl sub_80119D4
_080212F2:
	movs r0, 0x3
	b _08021326
_080212F6:
	movs r0, 0x4
	bl sub_80119D4
	movs r0, 0x4
	b _08021326
_08021300:
	ldr r0, _08021318
	ldr r0, [r0]
	adds r0, 0x40
	movs r1, 0x1
	bl sub_80138B8
	lsls r0, 24
	cmp r0, 0
	bne _0802131C
	movs r0, 0
	b _08021326
	.align 2, 0
_08021318: .4byte gUnknown_203B280
_0802131C:
	bl sub_8021410
	bl sub_8021494
	movs r0, 0x1
_08021326:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_8021274

	thumb_func_start sub_802132C
sub_802132C:
	ldr r0, _08021350
	ldr r2, [r0]
	adds r0, r2, 0
	adds r0, 0x5E
	movs r3, 0
	ldrsh r1, [r0, r3]
	subs r0, 0x2
	movs r3, 0
	ldrsh r0, [r0, r3]
	muls r0, r1
	adds r1, r2, 0
	adds r1, 0x58
	movs r3, 0
	ldrsh r1, [r1, r3]
	adds r0, r1
	adds r0, r2, r0
	ldrb r0, [r0]
	bx lr
	.align 2, 0
_08021350: .4byte gUnknown_203B280
	thumb_func_end sub_802132C

	thumb_func_start sub_8021354
sub_8021354:
	push {r4,r5,lr}
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	bl sub_8004914
	ldr r5, _0802139C
	ldr r0, [r5]
	adds r0, 0x7C
	movs r1, 0
	movs r2, 0
	bl sub_800641C
	bl sub_8021664
	adds r1, r0, 0
	ldr r0, [r5]
	adds r2, r0, 0
	adds r2, 0x62
	strh r1, [r2]
	adds r0, 0x40
	bl sub_8013984
	bl sub_8021410
	bl sub_8021494
	cmp r4, 0
	beq _08021396
	ldr r0, [r5]
	adds r0, 0x40
	bl AddMenuCursorSprite
_08021396:
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_0802139C: .4byte gUnknown_203B280
	thumb_func_end sub_8021354

	thumb_func_start sub_80213A0
sub_80213A0:
	push {r4,r5,lr}
	ldr r4, _080213FC
	ldr r2, [r4]
	cmp r2, 0
	beq _080213F4
	ldr r1, _08021400
	ldr r0, [r2, 0x3C]
	str r0, [r1]
	ldr r1, _08021404
	adds r0, r2, 0
	adds r0, 0x58
	ldrh r0, [r0]
	strh r0, [r1]
	ldr r1, _08021408
	adds r0, r2, 0
	adds r0, 0x5E
	ldrh r0, [r0]
	strh r0, [r1]
	ldr r0, [r2, 0x74]
	lsls r1, r0, 1
	adds r1, r0
	lsls r1, 3
	adds r1, r2, r1
	adds r1, 0x7C
	ldr r0, _0802140C
	ldm r0!, {r2,r3,r5}
	stm r1!, {r2,r3,r5}
	ldm r0!, {r2,r3,r5}
	stm r1!, {r2,r3,r5}
	bl sub_8004914
	ldr r0, [r4]
	adds r0, 0x7C
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	ldr r0, [r4]
	bl MemoryFree
	movs r0, 0
	str r0, [r4]
_080213F4:
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_080213FC: .4byte gUnknown_203B280
_08021400: .4byte gUnknown_203B284
_08021404: .4byte gUnknown_203B288
_08021408: .4byte gUnknown_203B28A
_0802140C: .4byte gUnknown_80DC464
	thumb_func_end sub_80213A0

	thumb_func_start sub_8021410
sub_8021410:
	push {r4,lr}
	ldr r4, _08021490
	ldr r0, [r4]
	adds r0, 0xDC
	movs r2, 0
	movs r1, 0x1
	strb r1, [r0]
	ldr r0, [r4]
	adds r0, 0xDD
	strb r2, [r0]
	ldr r0, [r4]
	adds r0, 0xDE
	movs r1, 0xC
	strb r1, [r0]
	ldr r0, [r4]
	adds r0, 0xDF
	strb r2, [r0]
	bl sub_8004914
	ldr r0, [r4]
	adds r0, 0x7C
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	ldr r0, [r4]
	adds r0, 0x5A
	movs r1, 0
	ldrsh r0, [r0, r1]
	movs r1, 0xC
	bl sub_80095E4
	adds r0, 0x2
	lsls r0, 16
	ldr r2, [r4]
	ldr r3, [r2, 0x74]
	lsls r1, r3, 1
	adds r1, r3
	lsls r1, 3
	adds r1, r2, r1
	adds r1, 0x8A
	asrs r3, r0, 16
	lsrs r0, 16
	strh r0, [r1]
	ldr r1, [r2, 0x74]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 3
	adds r2, r0
	adds r3, 0x2
	adds r2, 0x8C
	strh r3, [r2]
	bl sub_8004914
	ldr r0, [r4]
	adds r0, 0x7C
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08021490: .4byte gUnknown_203B280
	thumb_func_end sub_8021410

	thumb_func_start sub_8021494
sub_8021494:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0xA8
	ldr r4, _08021568
	ldr r0, [r4]
	ldr r0, [r0, 0x74]
	bl sub_8008C54
	ldr r0, [r4]
	ldr r0, [r0, 0x74]
	bl sub_80073B8
	ldr r2, _0802156C
	ldr r0, [r4]
	ldr r3, [r0, 0x74]
	movs r0, 0
	str r0, [sp]
	movs r0, 0xA
	movs r1, 0
	bl xxx_call_draw_string
	ldr r3, [r4]
	adds r0, r3, 0
	adds r0, 0xDE
	ldrb r0, [r0]
	lsls r0, 3
	adds r0, 0x4
	adds r1, r3, 0
	adds r1, 0x5E
	movs r5, 0
	ldrsh r2, [r1, r5]
	adds r2, 0x1
	movs r1, 0x7
	str r1, [sp]
	ldr r1, [r3, 0x74]
	str r1, [sp, 0x4]
	movs r1, 0
	movs r3, 0x1
	bl sub_8012BC4
	movs r0, 0
	mov r9, r0
	ldr r0, [r4]
	adds r0, 0x5A
	movs r1, 0
	ldrsh r0, [r0, r1]
	cmp r9, r0
	blt _080214FC
	b _08021646
_080214FC:
	mov r8, r4
	add r2, sp, 0x58
	mov r10, r2
_08021502:
	mov r3, r8
	ldr r2, [r3]
	adds r0, r2, 0
	adds r0, 0x5E
	movs r5, 0
	ldrsh r1, [r0, r5]
	subs r0, 0x2
	movs r3, 0
	ldrsh r0, [r0, r3]
	muls r0, r1
	add r0, r9
	adds r0, r2, r0
	ldrb r5, [r0]
	adds r7, r5, 0
	ldr r6, [r2, 0x3C]
	cmp r6, 0x2
	bne _0802159C
	add r0, sp, 0x8
	adds r1, r5, 0
	movs r2, 0x1
	bl sub_8092578
	adds r0, r5, 0
	bl sub_8092544
	ldr r1, _08021570
	ldr r1, [r1]
	movs r5, 0x98
	lsls r5, 2
	adds r1, r5
	ldr r1, [r1]
	cmp r0, r1
	bgt _08021574
	mov r1, r8
	ldr r0, [r1]
	adds r0, 0x40
	mov r1, r9
	bl sub_8013800
	adds r1, r0, 0
	mov r2, r8
	ldr r0, [r2]
	ldr r3, [r0, 0x74]
	movs r0, 0
	str r0, [sp]
	movs r0, 0x8
	add r2, sp, 0x8
	bl xxx_call_draw_string
	b _08021632
	.align 2, 0
_08021568: .4byte gUnknown_203B280
_0802156C: .4byte gUnknown_80DC494
_08021570: .4byte gUnknown_203B460
_08021574:
	mov r0, r10
	ldr r1, _08021598
	add r2, sp, 0x8
	bl sub_800D158
	mov r3, r8
	ldr r0, [r3]
	adds r0, 0x40
	mov r1, r9
	bl sub_8013800
	adds r1, r0, 0
	mov r5, r8
	ldr r0, [r5]
	ldr r3, [r0, 0x74]
	movs r0, 0
	str r0, [sp]
	b _080215FE
	.align 2, 0
_08021598: .4byte gUnknown_80DC4A4
_0802159C:
	cmp r6, 0
	bne _0802160C
	ldr r0, _080215D4
	ldr r0, [r0]
	adds r0, r5
	ldrb r0, [r0]
	cmp r0, 0x1
	bne _080215D8
	adds r0, r2, 0
	adds r0, 0x40
	mov r1, r9
	bl sub_8013800
	adds r4, r0, 0
	adds r0, r5, 0
	bl sub_8092524
	adds r2, r0, 0
	mov r1, r8
	ldr r0, [r1]
	ldr r3, [r0, 0x74]
	str r6, [sp]
	movs r0, 0x8
	adds r1, r4, 0
	bl xxx_call_draw_string
	b _08021632
	.align 2, 0
_080215D4: .4byte gUnknown_203B468
_080215D8:
	adds r0, r5, 0
	bl sub_8092524
	adds r2, r0, 0
	mov r0, r10
	ldr r1, _08021608
	bl sub_800D158
	mov r2, r8
	ldr r0, [r2]
	adds r0, 0x40
	mov r1, r9
	bl sub_8013800
	adds r1, r0, 0
	mov r3, r8
	ldr r0, [r3]
	ldr r3, [r0, 0x74]
	str r6, [sp]
_080215FE:
	movs r0, 0x8
	mov r2, r10
	bl xxx_call_draw_string
	b _08021632
	.align 2, 0
_08021608: .4byte gUnknown_80DC4AC
_0802160C:
	adds r0, r2, 0
	adds r0, 0x40
	mov r1, r9
	bl sub_8013800
	adds r4, r0, 0
	adds r0, r7, 0
	bl sub_8092524
	adds r2, r0, 0
	mov r5, r8
	ldr r0, [r5]
	ldr r3, [r0, 0x74]
	movs r0, 0
	str r0, [sp]
	movs r0, 0x8
	adds r1, r4, 0
	bl xxx_call_draw_string
_08021632:
	movs r0, 0x1
	add r9, r0
	mov r1, r8
	ldr r0, [r1]
	adds r0, 0x5A
	movs r2, 0
	ldrsh r0, [r0, r2]
	cmp r9, r0
	bge _08021646
	b _08021502
_08021646:
	ldr r0, _08021660
	ldr r0, [r0]
	ldr r0, [r0, 0x74]
	bl sub_80073E0
	add sp, 0xA8
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_08021660: .4byte gUnknown_203B280
	thumb_func_end sub_8021494

	thumb_func_start sub_8021664
sub_8021664:
	push {r4-r6,lr}
	movs r5, 0
	ldr r1, _0802167C
	ldr r0, [r1]
	ldr r0, [r0, 0x3C]
	cmp r0, 0x1
	beq _08021692
	cmp r0, 0x1
	bcc _08021680
	cmp r0, 0x2
	beq _080216B4
	b _080216F2
	.align 2, 0
_0802167C: .4byte gUnknown_203B280
_08021680:
	movs r4, 0x1
_08021682:
	ldr r0, [r1]
	adds r0, r5
	strb r4, [r0]
	adds r5, 0x1
	adds r4, 0x1
	cmp r4, 0x39
	ble _08021682
	b _080216F2
_08021692:
	movs r4, 0x1
	ldr r2, _080216B0
_08021696:
	ldr r0, [r2]
	adds r0, r4
	ldrb r0, [r0]
	cmp r0, 0
	beq _080216A8
	ldr r0, [r1]
	adds r0, r5
	strb r4, [r0]
	adds r5, 0x1
_080216A8:
	adds r4, 0x1
	cmp r4, 0x39
	ble _08021696
	b _080216F2
	.align 2, 0
_080216B0: .4byte gUnknown_203B468
_080216B4:
	movs r4, 0x1
	adds r6, r1, 0
_080216B8:
	ldr r0, _080216FC
	ldr r0, [r0]
	adds r0, r4
	ldrb r0, [r0]
	cmp r0, 0
	bne _080216EC
	lsls r0, r4, 24
	lsrs r0, 24
	bl sub_8092534
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0
	beq _080216E4
	cmp r0, 0x1
	bne _080216EC
	movs r0, 0x6
	bl sub_80023E4
	lsls r0, 24
	cmp r0, 0
	beq _080216EC
_080216E4:
	ldr r0, [r6]
	adds r0, r5
	strb r4, [r0]
	adds r5, 0x1
_080216EC:
	adds r4, 0x1
	cmp r4, 0x39
	ble _080216B8
_080216F2:
	adds r0, r5, 0
	pop {r4-r6}
	pop {r1}
	bx r1
	.align 2, 0
_080216FC: .4byte gUnknown_203B468
	thumb_func_end sub_8021664

	thumb_func_start sub_8021700
sub_8021700:
	push {r4,lr}
	cmp r0, 0x1
	beq _08021710
	cmp r0, 0x1
	bcc _08021754
	cmp r0, 0x2
	beq _0802172C
	b _0802176A
_08021710:
	movs r4, 0x1
	ldr r0, _08021728
	ldr r1, [r0]
_08021716:
	adds r0, r1, r4
	ldrb r0, [r0]
	cmp r0, 0
	bne _08021754
	adds r4, 0x1
	cmp r4, 0x39
	ble _08021716
	b _0802176A
	.align 2, 0
_08021728: .4byte gUnknown_203B468
_0802172C:
	movs r4, 0x1
_0802172E:
	ldr r0, _08021750
	ldr r0, [r0]
	adds r0, r4
	ldrb r0, [r0]
	cmp r0, 0
	bne _08021764
	lsls r0, r4, 24
	lsrs r0, 24
	bl sub_8092534
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0
	beq _08021754
	cmp r0, 0x1
	beq _08021758
	b _08021764
	.align 2, 0
_08021750: .4byte gUnknown_203B468
_08021754:
	movs r0, 0
	b _0802176C
_08021758:
	movs r0, 0x6
	bl sub_80023E4
	lsls r0, 24
	cmp r0, 0
	bne _08021754
_08021764:
	adds r4, 0x1
	cmp r4, 0x39
	ble _0802172E
_0802176A:
	movs r0, 0x1
_0802176C:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_8021700

	thumb_func_start sub_8021774
sub_8021774:
	push {r4-r6,lr}
	mov r6, r8
	push {r6}
	adds r4, r0, 0
	adds r5, r1, 0
	mov r8, r2
	lsls r4, 24
	lsrs r4, 24
	lsls r5, 24
	lsrs r5, 24
	ldr r6, _080217E4
	movs r0, 0xE0
	movs r1, 0x8
	bl MemoryAlloc
	str r0, [r6]
	strb r4, [r0, 0xC]
	ldr r0, [r6]
	strb r5, [r0, 0xD]
	ldr r0, [r6]
	bl sub_801317C
	bl sub_8021A60
	ldr r0, [r6]
	mov r1, r8
	str r1, [r0, 0x74]
	lsls r1, 1
	add r1, r8
	lsls r1, 3
	adds r1, 0x7C
	adds r1, r0, r1
	str r1, [r0, 0x78]
	adds r0, 0x7C
	bl sub_8006518
	ldr r1, [r6]
	ldr r2, [r1, 0x74]
	lsls r0, r2, 1
	adds r0, r2
	lsls r0, 3
	adds r1, r0
	adds r1, 0x7C
	ldr r0, _080217E8
	ldm r0!, {r2-r4}
	stm r1!, {r2-r4}
	ldm r0!, {r2-r4}
	stm r1!, {r2-r4}
	bl sub_8021820
	movs r0, 0x1
	pop {r3}
	mov r8, r3
	pop {r4-r6}
	pop {r1}
	bx r1
	.align 2, 0
_080217E4: .4byte gUnknown_203B28C
_080217E8: .4byte gUnknown_80DC4D8
	thumb_func_end sub_8021774

	thumb_func_start sub_80217EC
sub_80217EC:
	push {lr}
	ldr r0, _0802180C
	ldr r0, [r0]
	ldr r1, [r0, 0x74]
	bl sub_8012A64
	cmp r0, 0x1
	beq _08021810
	cmp r0, 0x2
	bne _0802181A
	movs r0, 0x1
	bl sub_80119D4
	movs r0, 0x2
	b _0802181C
	.align 2, 0
_0802180C: .4byte gUnknown_203B28C
_08021810:
	movs r0, 0
	bl sub_80119D4
	movs r0, 0x3
	b _0802181C
_0802181A:
	movs r0, 0
_0802181C:
	pop {r1}
	bx r1
	thumb_func_end sub_80217EC

	thumb_func_start sub_8021820
sub_8021820:
	push {lr}
	bl sub_8021878
	bl sub_8021894
	pop {r0}
	bx r0
	thumb_func_end sub_8021820

	thumb_func_start sub_8021830
sub_8021830:
	push {r4,r5,lr}
	ldr r4, _08021870
	ldr r2, [r4]
	cmp r2, 0
	beq _0802186A
	ldr r0, [r2, 0x74]
	lsls r1, r0, 1
	adds r1, r0
	lsls r1, 3
	adds r1, r2, r1
	adds r1, 0x7C
	ldr r0, _08021874
	ldm r0!, {r2,r3,r5}
	stm r1!, {r2,r3,r5}
	ldm r0!, {r2,r3,r5}
	stm r1!, {r2,r3,r5}
	bl sub_8004914
	ldr r0, [r4]
	adds r0, 0x7C
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	ldr r0, [r4]
	bl MemoryFree
	movs r0, 0
	str r0, [r4]
_0802186A:
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_08021870: .4byte gUnknown_203B28C
_08021874: .4byte gUnknown_80DC4BC
	thumb_func_end sub_8021830

	thumb_func_start sub_8021878
sub_8021878:
	push {lr}
	bl sub_8004914
	ldr r0, _08021890
	ldr r0, [r0]
	adds r0, 0x7C
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	pop {r0}
	bx r0
	.align 2, 0
_08021890: .4byte gUnknown_203B28C
	thumb_func_end sub_8021878

	thumb_func_start sub_8021894
sub_8021894:
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	sub sp, 0x168
	ldr r4, _080218F8
	ldr r0, [r4]
	ldr r0, [r0, 0x74]
	bl sub_80073B8
	ldr r0, [r4]
	ldrb r1, [r0, 0xC]
	add r0, sp, 0x4
	movs r2, 0
	bl sub_8092578
	ldr r0, [r4]
	ldr r3, [r0, 0x74]
	movs r5, 0
	str r5, [sp]
	movs r0, 0x14
	movs r1, 0
	add r2, sp, 0x4
	bl xxx_call_draw_string
	ldr r0, [r4]
	ldrb r0, [r0, 0xC]
	bl sub_80925DC
	adds r2, r0, 0
	ldr r0, [r4]
	ldr r3, [r0, 0x74]
	str r5, [sp]
	movs r0, 0xA
	movs r1, 0x14
	bl xxx_call_draw_string
	ldr r4, [r4]
	ldrb r0, [r4, 0xD]
	cmp r0, 0
	beq _08021900
	ldr r2, _080218FC
	ldr r3, [r4, 0x74]
	str r5, [sp]
	movs r0, 0x20
	movs r1, 0x3C
	bl xxx_call_draw_string
	b _0802190E
	.align 2, 0
_080218F8: .4byte gUnknown_203B28C
_080218FC: .4byte gUnknown_80DC4F0
_08021900:
	ldr r2, _0802193C
	ldr r3, [r4, 0x74]
	str r0, [sp]
	movs r0, 0x20
	movs r1, 0x3C
	bl xxx_call_draw_string
_0802190E:
	ldr r4, _08021940
	ldr r0, [r4]
	ldr r0, [r0, 0x74]
	movs r5, 0x4
	str r5, [sp]
	movs r1, 0x4
	movs r2, 0x40
	movs r3, 0x14
	bl sub_800792C
	ldr r4, [r4]
	ldrb r0, [r4, 0xD]
	cmp r0, 0
	beq _08021944
	ldr r0, [r4, 0x74]
	str r5, [sp]
	movs r1, 0xB8
	movs r2, 0x40
	movs r3, 0x14
	bl sub_800792C
	b _08021952
	.align 2, 0
_0802193C: .4byte gUnknown_80DC518
_08021940: .4byte gUnknown_203B28C
_08021944:
	ldr r0, [r4, 0x74]
	str r5, [sp]
	movs r1, 0x5E
	movs r2, 0x40
	movs r3, 0x6E
	bl sub_800792C
_08021952:
	ldr r5, _080219E8
	ldr r0, [r5]
	ldr r0, [r0, 0x74]
	movs r4, 0x4
	str r4, [sp]
	movs r1, 0x4
	movs r2, 0x82
	movs r3, 0xC8
	bl sub_800792C
	ldr r0, [r5]
	ldr r0, [r0, 0x74]
	str r4, [sp]
	movs r1, 0x3
	movs r2, 0x40
	movs r3, 0x43
	bl sub_8007A78
	ldr r0, [r5]
	ldr r0, [r0, 0x74]
	str r4, [sp]
	movs r1, 0xCC
	movs r2, 0x40
	movs r3, 0x43
	bl sub_8007A78
	movs r6, 0
	ldr r0, [r5]
	ldr r0, [r0, 0x70]
	cmp r6, r0
	bge _08021A40
	add r7, sp, 0x104
	mov r8, r5
	mov r9, r6
_08021996:
	adds r0, r6, 0
	movs r1, 0x3
	bl __modsi3
	lsls r1, r0, 6
	subs r1, r0
	adds r5, r1, 0x7
	adds r0, r6, 0
	movs r1, 0x3
	bl __divsi3
	lsls r1, r0, 1
	adds r1, r0
	lsls r1, 2
	adds r4, r1, 0
	adds r4, 0x47
	mov r1, r8
	ldr r0, [r1]
	lsls r1, r6, 1
	adds r0, 0xE
	adds r0, r1
	movs r2, 0
	ldrsh r1, [r0, r2]
	adds r0, r7, 0
	bl sub_808D930
	mov r0, r8
	ldr r3, [r0]
	lsls r1, r6, 2
	adds r0, r3, 0
	adds r0, 0x30
	adds r0, r1
	ldr r0, [r0]
	cmp r0, 0x1
	beq _08021A04
	cmp r0, 0x1
	bcc _080219EC
	cmp r0, 0x2
	beq _08021A16
	b _08021A34
	.align 2, 0
_080219E8: .4byte gUnknown_203B28C
_080219EC:
	ldr r0, _08021A00
	ldr r2, [r0]
	ldr r3, [r3, 0x74]
	mov r1, r9
	str r1, [sp]
	adds r0, r5, 0
	adds r1, r4, 0
	bl xxx_call_draw_string
	b _08021A34
	.align 2, 0
_08021A00: .4byte gUnknown_80D49BC
_08021A04:
	ldr r3, [r3, 0x74]
	mov r2, r9
	str r2, [sp]
	adds r0, r5, 0
	adds r1, r4, 0
	adds r2, r7, 0
	bl xxx_call_draw_string
	b _08021A34
_08021A16:
	add r0, sp, 0x4
	ldr r1, _08021A58
	adds r2, r7, 0
	bl sub_800D158
	mov r1, r8
	ldr r0, [r1]
	ldr r3, [r0, 0x74]
	mov r2, r9
	str r2, [sp]
	adds r0, r5, 0
	adds r1, r4, 0
	add r2, sp, 0x4
	bl xxx_call_draw_string
_08021A34:
	adds r6, 0x1
	mov r1, r8
	ldr r0, [r1]
	ldr r0, [r0, 0x70]
	cmp r6, r0
	blt _08021996
_08021A40:
	ldr r0, _08021A5C
	ldr r0, [r0]
	ldr r0, [r0, 0x74]
	bl sub_80073E0
	add sp, 0x168
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_08021A58: .4byte gUnknown_80DC524
_08021A5C: .4byte gUnknown_203B28C
	thumb_func_end sub_8021894

	thumb_func_start sub_8021A60
sub_8021A60:
	push {r4-r7,lr}
	ldr r2, _08021B4C
	ldr r1, [r2]
	movs r0, 0
	str r0, [r1, 0x70]
	movs r6, 0
	adds r4, r2, 0
	movs r3, 0
_08021A70:
	ldr r1, [r4]
	lsls r2, r6, 1
	adds r0, r1, 0
	adds r0, 0xE
	adds r0, r2
	strh r3, [r0]
	lsls r0, r6, 2
	adds r1, 0x30
	adds r1, r0
	str r3, [r1]
	adds r6, 0x1
	cmp r6, 0xF
	ble _08021A70
	movs r6, 0
	ldr r7, _08021B4C
_08021A8E:
	lsls r0, r6, 16
	asrs r5, r0, 16
	ldr r4, [r7]
	adds r0, r5, 0
	bl GetFriendArea
	ldrb r1, [r4, 0xC]
	lsls r0, 24
	lsrs r0, 24
	cmp r1, r0
	bne _08021AC4
	adds r0, r5, 0
	bl sub_808E858
	lsls r0, 16
	asrs r0, 16
	cmp r5, r0
	bne _08021AC4
	ldr r3, [r7]
	ldr r1, [r3, 0x70]
	lsls r2, r1, 1
	adds r0, r3, 0
	adds r0, 0xE
	adds r0, r2
	strh r5, [r0]
	adds r1, 0x1
	str r1, [r3, 0x70]
_08021AC4:
	adds r6, 0x1
	ldr r0, _08021B50
	cmp r6, r0
	ble _08021A8E
	movs r6, 0
_08021ACE:
	lsls r0, r6, 16
	asrs r4, r0, 16
	adds r0, r4, 0
	bl sub_8098134
	lsls r0, 24
	cmp r0, 0
	beq _08021AFC
	adds r0, r4, 0
	bl sub_8021B58
	adds r2, r0, 0
	movs r0, 0x1
	negs r0, r0
	cmp r2, r0
	beq _08021AFC
	ldr r0, _08021B4C
	ldr r1, [r0]
	lsls r0, r2, 2
	adds r1, 0x30
	adds r1, r0
	movs r0, 0x1
	str r0, [r1]
_08021AFC:
	adds r6, 0x1
	ldr r0, _08021B50
	cmp r6, r0
	ble _08021ACE
	movs r6, 0
	ldr r4, _08021B54
_08021B08:
	movs r0, 0x58
	adds r1, r6, 0
	muls r1, r0
	ldr r0, [r4]
	adds r2, r0, r1
	ldrb r1, [r2]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _08021B3C
	movs r1, 0x8
	ldrsh r0, [r2, r1]
	bl sub_8021B58
	adds r2, r0, 0
	movs r0, 0x1
	negs r0, r0
	cmp r2, r0
	beq _08021B3C
	ldr r0, _08021B4C
	ldr r1, [r0]
	lsls r0, r2, 2
	adds r1, 0x30
	adds r1, r0
	movs r0, 0x2
	str r0, [r1]
_08021B3C:
	adds r6, 0x1
	movs r0, 0xCE
	lsls r0, 1
	cmp r6, r0
	ble _08021B08
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_08021B4C: .4byte gUnknown_203B28C
_08021B50: .4byte 0x000001a7
_08021B54: .4byte gUnknown_203B45C
	thumb_func_end sub_8021A60

	thumb_func_start sub_8021B58
sub_8021B58:
	push {r4,r5,lr}
	lsls r0, 16
	asrs r0, 16
	bl sub_808E858
	lsls r0, 16
	asrs r4, r0, 16
	movs r2, 0
	ldr r0, _08021B84
	ldr r0, [r0]
	ldr r1, [r0, 0x70]
	cmp r2, r1
	bge _08021B90
	adds r3, r1, 0
	adds r1, r0, 0
	adds r1, 0xE
_08021B78:
	movs r5, 0
	ldrsh r0, [r1, r5]
	cmp r4, r0
	bne _08021B88
	adds r0, r2, 0
	b _08021B94
	.align 2, 0
_08021B84: .4byte gUnknown_203B28C
_08021B88:
	adds r1, 0x2
	adds r2, 0x1
	cmp r2, r3
	blt _08021B78
_08021B90:
	movs r0, 0x1
	negs r0, r0
_08021B94:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_8021B58

	thumb_func_start sub_8021B9C
sub_8021B9C:
	push {r4-r6,lr}
	adds r4, r0, 0
	bl sub_8004914
	movs r0, 0
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	ldr r5, _08021BF8
	movs r0, 0x9C
	lsls r0, 1
	movs r1, 0x8
	bl MemoryAlloc
	str r0, [r5]
	movs r6, 0
	str r6, [r0, 0x14]
	str r6, [r0, 0x18]
	str r4, [r0]
	ldr r0, _08021BFC
	movs r1, 0x28
	bl sub_808D8E0
	ldr r4, _08021C00
	adds r0, r4, 0
	movs r1, 0x28
	bl sub_808D8E0
	movs r0, 0x28
	bl sub_808D994
	adds r1, r0, 0
	subs r4, 0x50
	adds r0, r4, 0
	bl strcpy
	ldr r5, [r5]
	ldr r0, [r5]
	cmp r0, 0x1
	bne _08021C04
	adds r0, r5, 0
	adds r0, 0xCC
	str r6, [r0]
	b _08021C0E
	.align 2, 0
_08021BF8: .4byte gUnknown_203B290
_08021BFC: .4byte gUnknown_202E5D8
_08021C00: .4byte gUnknown_202E1C8
_08021C04:
	adds r1, r5, 0
	adds r1, 0xCC
	adds r0, r5, 0
	adds r0, 0xBC
	str r0, [r1]
_08021C0E:
	movs r0, 0x28
	bl sub_808DDD0
	ldr r2, _08021C58
	ldr r3, [r2]
	adds r1, r3, 0
	adds r1, 0xBC
	str r0, [r1]
	adds r1, 0x4
	ldr r0, [r0, 0x4]
	str r0, [r1]
	adds r0, r3, 0
	adds r0, 0xC8
	movs r1, 0
	strb r1, [r0]
	ldr r0, [r2]
	adds r0, 0xC9
	strb r1, [r0]
	ldr r0, [r2]
	adds r0, 0xCA
	strb r1, [r0]
	ldr r1, [r2]
	adds r2, r1, 0
	adds r2, 0xC4
	movs r0, 0x2
	strh r0, [r2]
	adds r1, 0xC6
	movs r0, 0x8
	strh r0, [r1]
	movs r0, 0
	bl sub_8021D44
	movs r0, 0x1
	pop {r4-r6}
	pop {r1}
	bx r1
	.align 2, 0
_08021C58: .4byte gUnknown_203B290
	thumb_func_end sub_8021B9C

	thumb_func_start sub_8021C5C
sub_8021C5C:
	push {lr}
	ldr r0, _08021C74
	ldr r0, [r0]
	ldr r0, [r0, 0x4]
	cmp r0, 0x17
	bhi _08021D10
	lsls r0, 2
	ldr r1, _08021C78
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08021C74: .4byte gUnknown_203B290
_08021C78: .4byte _08021C7C
	.align 2, 0
_08021C7C:
	.4byte _08021CDC
	.4byte _08021CDC
	.4byte _08021D10
	.4byte _08021D10
	.4byte _08021D0C
	.4byte _08021D10
	.4byte _08021D10
	.4byte _08021D10
	.4byte _08021D10
	.4byte _08021CE2
	.4byte _08021CE2
	.4byte _08021CE8
	.4byte _08021D10
	.4byte _08021CF4
	.4byte _08021CFA
	.4byte _08021D10
	.4byte _08021D00
	.4byte _08021CEE
	.4byte _08021D10
	.4byte _08021D10
	.4byte _08021D10
	.4byte _08021D10
	.4byte _08021D06
	.4byte _08021D06
_08021CDC:
	bl sub_8022460
	b _08021D14
_08021CE2:
	bl sub_8022538
	b _08021D14
_08021CE8:
	bl sub_80225C8
	b _08021D14
_08021CEE:
	bl sub_80224D4
	b _08021D14
_08021CF4:
	bl sub_80226F0
	b _08021D14
_08021CFA:
	bl sub_8022790
	b _08021D14
_08021D00:
	bl sub_8022668
	b _08021D14
_08021D06:
	bl sub_8022684
	b _08021D14
_08021D0C:
	movs r0, 0x3
	b _08021D16
_08021D10:
	bl sub_80226CC
_08021D14:
	movs r0, 0
_08021D16:
	pop {r1}
	bx r1
	thumb_func_end sub_8021C5C

	thumb_func_start sub_8021D1C
sub_8021D1C:
	push {r4,lr}
	ldr r4, _08021D40
	ldr r0, [r4]
	cmp r0, 0
	beq _08021D38
	adds r0, 0xBC
	ldr r0, [r0]
	bl CloseFile
	ldr r0, [r4]
	bl MemoryFree
	movs r0, 0
	str r0, [r4]
_08021D38:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08021D40: .4byte gUnknown_203B290
	thumb_func_end sub_8021D1C

	thumb_func_start sub_8021D44
sub_8021D44:
	push {lr}
	ldr r1, _08021D58
	ldr r1, [r1]
	str r0, [r1, 0x4]
	bl sub_8021D5C
	bl sub_8021E0C
	pop {r0}
	bx r0
	.align 2, 0
_08021D58: .4byte gUnknown_203B290
	thumb_func_end sub_8021D44

	thumb_func_start sub_8021D5C
sub_8021D5C:
	push {r4-r7,lr}
	ldr r4, _08021D7C
	ldr r0, [r4]
	adds r0, 0xD0
	bl sub_8006518
	ldr r1, [r4]
	ldr r0, [r1, 0x4]
	cmp r0, 0x9
	blt _08021DC8
	cmp r0, 0xA
	ble _08021D80
	cmp r0, 0xB
	beq _08021DB0
	b _08021DC8
	.align 2, 0
_08021D7C: .4byte gUnknown_203B290
_08021D80:
	ldr r2, _08021DA8
	adds r1, 0xD0
	adds r0, r2, 0
	ldm r0!, {r3,r5,r6}
	stm r1!, {r3,r5,r6}
	ldm r0!, {r3,r5,r7}
	stm r1!, {r3,r5,r7}
	ldr r0, [r4]
	movs r6, 0x80
	lsls r6, 1
	adds r0, r6
	ldm r2!, {r1,r3,r7}
	stm r0!, {r1,r3,r7}
	ldm r2!, {r5-r7}
	stm r0!, {r5-r7}
	ldr r1, [r4]
	adds r1, 0xE8
	ldr r0, _08021DAC
	b _08021DB8
	.align 2, 0
_08021DA8: .4byte gUnknown_80DC534
_08021DAC: .4byte gUnknown_80DC564
_08021DB0:
	movs r0, 0x80
	lsls r0, 1
	adds r1, r0
	ldr r0, _08021DC4
_08021DB8:
	ldm r0!, {r2-r4}
	stm r1!, {r2-r4}
	ldm r0!, {r5-r7}
	stm r1!, {r5-r7}
	b _08021DEC
	.align 2, 0
_08021DC4: .4byte gUnknown_80DC54C
_08021DC8:
	ldr r0, _08021E04
	mov r12, r0
	ldr r4, _08021E08
	movs r3, 0
	movs r2, 0x3
_08021DD2:
	mov r5, r12
	ldr r1, [r5]
	adds r1, r3
	adds r1, 0xD0
	adds r0, r4, 0
	ldm r0!, {r5-r7}
	stm r1!, {r5-r7}
	ldm r0!, {r5-r7}
	stm r1!, {r5-r7}
	adds r3, 0x18
	subs r2, 0x1
	cmp r2, 0
	bge _08021DD2
_08021DEC:
	bl sub_8004914
	ldr r0, _08021E04
	ldr r0, [r0]
	adds r0, 0xD0
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_08021E04: .4byte gUnknown_203B290
_08021E08: .4byte gUnknown_80DC534
	thumb_func_end sub_8021D5C

	thumb_func_start sub_8021E0C
sub_8021E0C:
	push {r4,lr}
	sub sp, 0x20
	ldr r1, _08021E28
	ldr r0, [r1]
	ldr r0, [r0, 0x4]
	adds r4, r1, 0
	cmp r0, 0x1C
	bls _08021E1E
	b _080222B6
_08021E1E:
	lsls r0, 2
	ldr r1, _08021E2C
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08021E28: .4byte gUnknown_203B290
_08021E2C: .4byte _08021E30
	.align 2, 0
_08021E30:
	.4byte _08021EA4
	.4byte _08021EC0
	.4byte _08021F38
	.4byte _08021F50
	.4byte _080222B6
	.4byte _08021F78
	.4byte _08021F90
	.4byte _08021F08
	.4byte _08021F20
	.4byte _08021FD8
	.4byte _08021FE2
	.4byte _08021FF0
	.4byte _0802208E
	.4byte _080220B8
	.4byte _080220D8
	.4byte _080220EA
	.4byte _08022080
	.4byte _08022024
	.4byte _08021FA8
	.4byte _08021FC0
	.4byte _08022138
	.4byte _08022150
	.4byte _08022168
	.4byte _08022176
	.4byte _0802217E
	.4byte _08022238
	.4byte _08022250
	.4byte _08022268
	.4byte _08022294
_08021EA4:
	bl sub_80222C8
	ldr r2, _08021EB8
	ldr r0, _08021EBC
	ldr r4, [r0]
	ldr r1, [r4]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 4
	b _08021ED4
	.align 2, 0
_08021EB8: .4byte gUnknown_80D79A4
_08021EBC: .4byte gUnknown_203B290
_08021EC0:
	bl sub_80222C8
	ldr r2, _08021F00
	ldr r0, _08021F04
	ldr r4, [r0]
	ldr r1, [r4]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 4
	adds r2, 0x4
_08021ED4:
	adds r0, r2
	ldr r0, [r0]
	ldr r2, [r4, 0x14]
	adds r3, r4, 0
	adds r3, 0x1C
	adds r1, r4, 0
	adds r1, 0x5C
	str r1, [sp]
	movs r1, 0x4
	str r1, [sp, 0x4]
	movs r1, 0
	str r1, [sp, 0x8]
	adds r1, r4, 0
	adds r1, 0xCC
	ldr r1, [r1]
	str r1, [sp, 0xC]
	movs r1, 0xC
	str r1, [sp, 0x10]
	movs r1, 0
	bl sub_8014248
	b _080222B6
	.align 2, 0
_08021F00: .4byte gUnknown_80D79A4
_08021F04: .4byte gUnknown_203B290
_08021F08:
	ldr r3, [r4]
	movs r0, 0x9
	str r0, [r3, 0x8]
	ldr r2, _08021F1C
	ldr r1, [r3]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 4
	adds r2, 0xC
	b _0802227A
	.align 2, 0
_08021F1C: .4byte gUnknown_80D79A4
_08021F20:
	ldr r3, [r4]
	movs r0, 0xA
	str r0, [r3, 0x8]
	ldr r2, _08021F34
	ldr r1, [r3]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 4
	adds r2, 0x10
	b _0802227A
	.align 2, 0
_08021F34: .4byte gUnknown_80D79A4
_08021F38:
	ldr r3, [r4]
	movs r0, 0x1
	str r0, [r3, 0x8]
	ldr r2, _08021F4C
	ldr r1, [r3]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 4
	adds r2, 0x4C
	b _0802227A
	.align 2, 0
_08021F4C: .4byte gUnknown_80D79A4
_08021F50:
	ldr r3, [r4]
	movs r0, 0x4
	str r0, [r3, 0x8]
	ldr r2, _08021F70
	ldr r1, [r3]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 4
	adds r2, 0x8
	adds r0, r2
	ldr r0, [r0]
	adds r3, 0xCC
	ldr r2, [r3]
	ldr r3, _08021F74
	b _08022284
	.align 2, 0
_08021F70: .4byte gUnknown_80D79A4
_08021F74: .4byte 0x0000030d
_08021F78:
	ldr r3, [r4]
	movs r0, 0x3
	str r0, [r3, 0x8]
	ldr r2, _08021F8C
	ldr r1, [r3]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 4
	adds r2, 0x20
	b _0802227A
	.align 2, 0
_08021F8C: .4byte gUnknown_80D79A4
_08021F90:
	ldr r3, [r4]
	movs r0, 0xA
	str r0, [r3, 0x8]
	ldr r2, _08021FA4
	ldr r1, [r3]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 4
	adds r2, 0x24
	b _0802227A
	.align 2, 0
_08021FA4: .4byte gUnknown_80D79A4
_08021FA8:
	ldr r3, [r4]
	movs r0, 0x3
	str r0, [r3, 0x8]
	ldr r2, _08021FBC
	ldr r1, [r3]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 4
	adds r2, 0x28
	b _0802227A
	.align 2, 0
_08021FBC: .4byte gUnknown_80D79A4
_08021FC0:
	ldr r3, [r4]
	movs r0, 0xA
	str r0, [r3, 0x8]
	ldr r2, _08021FD4
	ldr r1, [r3]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 4
	adds r2, 0x2C
	b _0802227A
	.align 2, 0
_08021FD4: .4byte gUnknown_80D79A4
_08021FD8:
	movs r0, 0x2
	movs r1, 0x3
	bl sub_80211AC
	b _08021FE8
_08021FE2:
	movs r0, 0x1
	bl sub_8021354
_08021FE8:
	movs r0, 0x1
	bl sub_8016C40
	b _080222B6
_08021FF0:
	bl sub_8021494
	movs r0, 0x1
	bl sub_8016C40
	bl sub_8022380
	ldr r0, _08022020
	ldr r2, [r0]
	adds r0, r2, 0
	adds r0, 0x6C
	adds r1, r2, 0
	adds r1, 0x1C
	adds r3, r2, 0
	adds r3, 0x5C
	ldr r2, [r2, 0x18]
	str r2, [sp]
	movs r2, 0x2
	str r2, [sp, 0x4]
	movs r2, 0
	bl sub_8012D60
	b _080222B6
	.align 2, 0
_08022020: .4byte gUnknown_203B290
_08022024:
	bl sub_8022420
	ldr r0, _08022070
	ldr r4, _08022074
	ldr r1, [r4]
	ldrb r1, [r1, 0x10]
	movs r2, 0
	bl sub_8092578
	ldr r1, _08022078
	ldr r4, [r4]
	ldr r0, [r4, 0xC]
	str r0, [r1]
	ldr r2, _0802207C
	ldr r1, [r4]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 4
	adds r2, 0x14
	adds r0, r2
	ldr r0, [r0]
	adds r3, r4, 0
	adds r3, 0x1C
	movs r2, 0
	str r2, [sp]
	movs r1, 0x4
	str r1, [sp, 0x4]
	str r2, [sp, 0x8]
	adds r4, 0xCC
	ldr r1, [r4]
	str r1, [sp, 0xC]
	movs r1, 0xC
	str r1, [sp, 0x10]
	movs r1, 0
	movs r2, 0x5
	bl sub_8014248
	b _080222B6
	.align 2, 0
_08022070: .4byte gUnknown_202E628
_08022074: .4byte gUnknown_203B290
_08022078: .4byte gUnknown_202DE30
_0802207C: .4byte gUnknown_80D79A4
_08022080:
	ldr r0, [r4]
	ldrb r0, [r0, 0x10]
	movs r1, 0
	movs r2, 0x2
	bl sub_8021774
	b _080222B6
_0802208E:
	ldr r1, [r4]
	movs r0, 0xD
	str r0, [r1, 0x8]
	ldr r0, _080220B0
	ldrb r1, [r1, 0x10]
	movs r2, 0
	bl sub_8092578
	ldr r2, _080220B4
	ldr r3, [r4]
	ldr r1, [r3]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 4
	adds r2, 0x18
	b _0802227A
	.align 2, 0
_080220B0: .4byte gUnknown_202E628
_080220B4: .4byte gUnknown_80D79A4
_080220B8:
	ldr r1, [r4]
	movs r0, 0xE
	str r0, [r1, 0x8]
	ldr r0, _080220D4
	bl sub_8011988
	ldr r0, [r4]
	movs r1, 0x98
	lsls r1, 1
	adds r0, r1
	movs r1, 0x1
	str r1, [r0]
	b _080222B6
	.align 2, 0
_080220D4: .4byte 0x0000025b
_080220D8:
	ldr r0, [r4]
	movs r1, 0xF
	str r1, [r0, 0x8]
	movs r1, 0x9A
	lsls r1, 1
	adds r0, r1
	movs r1, 0x1E
	str r1, [r0]
	b _080222B6
_080220EA:
	movs r0, 0x2
	bl sub_8021700
	lsls r0, 24
	cmp r0, 0
	beq _08022108
	bl sub_80213A0
	ldr r0, _08022104
	ldr r1, [r0]
	movs r0, 0x12
	b _0802210E
	.align 2, 0
_08022104: .4byte gUnknown_203B290
_08022108:
	ldr r0, _08022130
	ldr r1, [r0]
	movs r0, 0x8
_0802210E:
	str r0, [r1, 0x8]
	movs r0, 0xCE
	bl sub_8011988
	ldr r3, _08022134
	ldr r0, _08022130
	ldr r2, [r0]
	ldr r1, [r2]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 4
	adds r3, 0x1C
	adds r0, r3
	ldr r0, [r0]
	adds r2, 0xCC
	ldr r2, [r2]
	b _08022282
	.align 2, 0
_08022130: .4byte gUnknown_203B290
_08022134: .4byte gUnknown_80D79A4
_08022138:
	ldr r3, [r4]
	movs r0, 0x16
	str r0, [r3, 0x8]
	ldr r2, _0802214C
	ldr r1, [r3]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 4
	adds r2, 0x30
	b _0802227A
	.align 2, 0
_0802214C: .4byte gUnknown_80D79A4
_08022150:
	ldr r3, [r4]
	movs r0, 0x17
	str r0, [r3, 0x8]
	ldr r2, _08022164
	ldr r1, [r3]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 4
	adds r2, 0x34
	b _0802227A
	.align 2, 0
_08022164: .4byte gUnknown_80D79A4
_08022168:
	movs r0, 0
	movs r1, 0x3
	movs r2, 0
	movs r3, 0xA
	bl sub_8023144
	b _080222B6
_08022176:
	movs r0, 0x1
	bl sub_8023354
	b _080222B6
_0802217E:
	ldr r4, _080221A0
	ldr r0, [r4]
	ldrb r0, [r0, 0x10]
	add r1, sp, 0x14
	movs r2, 0
	movs r3, 0
	bl sub_8092638
	add r0, sp, 0x14
	ldrb r0, [r0, 0x4]
	cmp r0, 0
	beq _080221A4
	ldr r1, [r4]
	movs r0, 0x19
	str r0, [r1, 0x8]
	b _080221FA
	.align 2, 0
_080221A0: .4byte gUnknown_203B290
_080221A4:
	ldr r0, [r4]
	ldrb r0, [r0, 0x10]
	bl sub_8092534
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x2
	beq _080221E0
	cmp r0, 0x2
	bgt _080221BE
	cmp r0, 0x1
	beq _080221C4
	b _080221F0
_080221BE:
	cmp r0, 0x3
	beq _080221E8
	b _080221F0
_080221C4:
	movs r0, 0x6
	bl sub_80023E4
	lsls r0, 24
	cmp r0, 0
	beq _080221D8
	ldr r1, [r4]
	movs r0, 0x15
	str r0, [r1, 0x8]
	b _080221FA
_080221D8:
	ldr r1, [r4]
	movs r0, 0x1A
	str r0, [r1, 0x8]
	b _080221FA
_080221E0:
	ldr r1, [r4]
	movs r0, 0x1B
	str r0, [r1, 0x8]
	b _080221FA
_080221E8:
	ldr r1, [r4]
	movs r0, 0x1C
	str r0, [r1, 0x8]
	b _080221FA
_080221F0:
	ldr r2, _08022228
	ldr r1, [r2]
	movs r0, 0x15
	str r0, [r1, 0x8]
	adds r4, r2, 0
_080221FA:
	ldr r0, [r4]
	movs r1, 0x12
	ldrsh r0, [r0, r1]
	bl sub_808D994
	adds r1, r0, 0
	ldr r0, _0802222C
	bl strcpy
	ldr r0, _08022230
	ldr r1, [r4]
	ldrb r1, [r1, 0x10]
	movs r2, 0
	bl sub_8092578
	ldr r2, _08022234
	ldr r3, [r4]
	ldr r1, [r3]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 4
	adds r2, 0x38
	b _0802227A
	.align 2, 0
_08022228: .4byte gUnknown_203B290
_0802222C: .4byte gUnknown_202DF98
_08022230: .4byte gUnknown_202E628
_08022234: .4byte gUnknown_80D79A4
_08022238:
	ldr r3, [r4]
	movs r0, 0x15
	str r0, [r3, 0x8]
	ldr r2, _0802224C
	ldr r1, [r3]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 4
	adds r2, 0x3C
	b _0802227A
	.align 2, 0
_0802224C: .4byte gUnknown_80D79A4
_08022250:
	ldr r3, [r4]
	movs r0, 0x15
	str r0, [r3, 0x8]
	ldr r2, _08022264
	ldr r1, [r3]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 4
	adds r2, 0x40
	b _0802227A
	.align 2, 0
_08022264: .4byte gUnknown_80D79A4
_08022268:
	ldr r3, [r4]
	movs r0, 0x15
	str r0, [r3, 0x8]
	ldr r2, _0802228C
	ldr r1, [r3]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 4
	adds r2, 0x44
_0802227A:
	adds r0, r2
	ldr r0, [r0]
	adds r3, 0xCC
	ldr r2, [r3]
_08022282:
	ldr r3, _08022290
_08022284:
	movs r1, 0
	bl sub_80141B4
	b _080222B6
	.align 2, 0
_0802228C: .4byte gUnknown_80D79A4
_08022290: .4byte 0x0000010d
_08022294:
	ldr r3, [r4]
	movs r0, 0x15
	str r0, [r3, 0x8]
	ldr r2, _080222C0
	ldr r1, [r3]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 4
	adds r2, 0x48
	adds r0, r2
	ldr r0, [r0]
	adds r3, 0xCC
	ldr r2, [r3]
	ldr r3, _080222C4
	movs r1, 0
	bl sub_80141B4
_080222B6:
	add sp, 0x20
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080222C0: .4byte gUnknown_80D79A4
_080222C4: .4byte 0x0000010d
	thumb_func_end sub_8021E0C

	thumb_func_start sub_80222C8
sub_80222C8:
	push {r4-r7,lr}
	ldr r4, _08022344
	ldr r0, [r4]
	adds r0, 0x5C
	movs r1, 0
	movs r2, 0x10
	bl MemoryFill16
	ldr r1, [r4]
	movs r5, 0
	ldr r0, _08022348
	ldr r0, [r0]
	str r0, [r1, 0x1C]
	adds r3, r1, 0
	adds r3, 0x20
	movs r0, 0x2
	str r0, [r1, 0x20]
	movs r2, 0x1
	ldr r0, _0802234C
	ldr r0, [r0]
	str r0, [r1, 0x24]
	movs r0, 0x3
	str r0, [r1, 0x28]
	ldr r0, _08022350
	ldr r0, [r0]
	str r0, [r1, 0x2C]
	movs r0, 0x4
	str r0, [r1, 0x30]
	ldr r0, _08022354
	ldr r0, [r0]
	str r0, [r1, 0x34]
	str r2, [r1, 0x38]
	movs r7, 0x4
	str r5, [r1, 0x3C]
	str r2, [r3, 0x20]
	adds r6, r1, 0
	adds r2, r6, 0
	adds r2, 0x5C
_08022314:
	ldrh r0, [r2]
	cmp r0, 0
	bne _08022322
	ldr r1, [r3]
	ldr r0, [r6, 0x14]
	cmp r1, r0
	beq _0802237A
_08022322:
	adds r3, 0x8
	adds r2, 0x2
	adds r5, 0x1
	cmp r5, r7
	blt _08022314
	movs r5, 0
	cmp r5, r7
	bge _0802237A
	ldr r1, [r4]
	adds r0, r1, 0
	adds r0, 0x5C
	ldrh r0, [r0]
	cmp r0, 0
	bne _08022358
	ldr r0, [r1, 0x20]
	str r0, [r1, 0x14]
	b _0802237A
	.align 2, 0
_08022344: .4byte gUnknown_203B290
_08022348: .4byte gUnknown_80D4978
_0802234C: .4byte gUnknown_80D499C
_08022350: .4byte gUnknown_80D4970
_08022354: .4byte gUnknown_80D4934
_08022358:
	adds r5, 0x1
	cmp r5, r7
	bge _0802237A
	ldr r2, [r4]
	lsls r0, r5, 1
	adds r1, r2, 0
	adds r1, 0x5C
	adds r1, r0
	ldrh r0, [r1]
	cmp r0, 0
	bne _08022358
	lsls r0, r5, 3
	adds r1, r2, 0
	adds r1, 0x20
	adds r1, r0
	ldr r0, [r1]
	str r0, [r2, 0x14]
_0802237A:
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_80222C8

	thumb_func_start sub_8022380
sub_8022380:
	push {r4-r7,lr}
	ldr r4, _080223EC
	ldr r0, [r4]
	adds r0, 0x5C
	movs r1, 0
	movs r2, 0x10
	bl MemoryFill16
	ldr r3, [r4]
	movs r2, 0
	ldr r0, _080223F0
	ldr r0, [r0]
	str r0, [r3, 0x1C]
	movs r0, 0x2
	str r0, [r3, 0x20]
	movs r1, 0x1
	ldr r0, _080223F4
	ldr r0, [r0]
	str r0, [r3, 0x24]
	movs r0, 0x4
	str r0, [r3, 0x28]
	movs r6, 0x2
	str r2, [r3, 0x2C]
	str r1, [r3, 0x30]
	movs r5, 0
	mov r12, r3
	adds r3, 0x20
	mov r2, r12
	adds r2, 0x5C
_080223BA:
	ldrh r0, [r2]
	cmp r0, 0
	bne _080223CA
	ldr r1, [r3]
	mov r7, r12
	ldr r0, [r7, 0x18]
	cmp r1, r0
	beq _0802241A
_080223CA:
	adds r3, 0x8
	adds r2, 0x2
	adds r5, 0x1
	cmp r5, r6
	blt _080223BA
	movs r5, 0
	cmp r5, r6
	bge _0802241A
	ldr r1, [r4]
	adds r0, r1, 0
	adds r0, 0x5C
	ldrh r0, [r0]
	cmp r0, 0
	bne _080223F8
	ldr r0, [r1, 0x20]
	str r0, [r1, 0x18]
	b _0802241A
	.align 2, 0
_080223EC: .4byte gUnknown_203B290
_080223F0: .4byte gUnknown_80D4978
_080223F4: .4byte gUnknown_80D4970
_080223F8:
	adds r5, 0x1
	cmp r5, r6
	bge _0802241A
	ldr r2, [r4]
	lsls r0, r5, 1
	adds r1, r2, 0
	adds r1, 0x5C
	adds r1, r0
	ldrh r0, [r1]
	cmp r0, 0
	bne _080223F8
	lsls r0, r5, 3
	adds r1, r2, 0
	adds r1, 0x20
	adds r1, r0
	ldr r0, [r1]
	str r0, [r2, 0x18]
_0802241A:
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_8022380

	thumb_func_start sub_8022420
sub_8022420:
	push {r4,lr}
	ldr r4, _08022454
	ldr r0, [r4]
	adds r0, 0x5C
	movs r1, 0
	movs r2, 0x10
	bl MemoryFill16
	ldr r1, [r4]
	movs r3, 0
	ldr r0, _08022458
	ldr r0, [r0]
	str r0, [r1, 0x1C]
	movs r0, 0x5
	str r0, [r1, 0x20]
	movs r2, 0x1
	ldr r0, _0802245C
	ldr r0, [r0]
	str r0, [r1, 0x24]
	movs r0, 0x6
	str r0, [r1, 0x28]
	str r3, [r1, 0x2C]
	str r2, [r1, 0x30]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08022454: .4byte gUnknown_203B290
_08022458: .4byte gUnknown_80D4920
_0802245C: .4byte gUnknown_80D4928
	thumb_func_end sub_8022420

	thumb_func_start sub_8022460
sub_8022460:
	push {lr}
	sub sp, 0x4
	mov r0, sp
	bl sub_80144A4
	cmp r0, 0
	bne _080224CC
	ldr r1, [sp]
	cmp r1, 0x1
	beq _0802247A
	ldr r0, _0802248C
	ldr r0, [r0]
	str r1, [r0, 0x14]
_0802247A:
	ldr r0, [sp]
	cmp r0, 0x2
	beq _0802249A
	cmp r0, 0x2
	bgt _08022490
	cmp r0, 0x1
	beq _080224C6
	b _080224CC
	.align 2, 0
_0802248C: .4byte gUnknown_203B290
_08022490:
	cmp r0, 0x3
	beq _080224B6
	cmp r0, 0x4
	beq _080224BE
	b _080224CC
_0802249A:
	movs r0, 0x2
	bl sub_8021700
	lsls r0, 24
	cmp r0, 0
	beq _080224AE
	movs r0, 0x5
	bl sub_8021D44
	b _080224CC
_080224AE:
	movs r0, 0x7
	bl sub_8021D44
	b _080224CC
_080224B6:
	movs r0, 0x14
	bl sub_8021D44
	b _080224CC
_080224BE:
	movs r0, 0x2
	bl sub_8021D44
	b _080224CC
_080224C6:
	movs r0, 0x3
	bl sub_8021D44
_080224CC:
	add sp, 0x4
	pop {r0}
	bx r0
	thumb_func_end sub_8022460

	thumb_func_start sub_80224D4
sub_80224D4:
	push {lr}
	sub sp, 0x4
	mov r0, sp
	bl sub_80144A4
	cmp r0, 0
	bne _08022532
	ldr r0, [sp]
	cmp r0, 0x5
	beq _080224F8
	cmp r0, 0x5
	bgt _080224F2
	cmp r0, 0x1
	beq _0802252C
	b _08022532
_080224F2:
	cmp r0, 0x6
	beq _0802252C
	b _08022532
_080224F8:
	ldr r0, _08022524
	ldr r2, [r0]
	movs r0, 0x98
	lsls r0, 2
	adds r2, r0
	ldr r0, _08022528
	ldr r3, [r0]
	ldr r0, [r2]
	ldr r1, [r3, 0xC]
	subs r0, r1
	str r0, [r2]
	ldrb r0, [r3, 0x10]
	bl sub_80925EC
	movs r0, 0xA6
	lsls r0, 1
	bl sub_8011988
	movs r0, 0xC
	bl sub_8021D44
	b _08022532
	.align 2, 0
_08022524: .4byte gUnknown_203B460
_08022528: .4byte gUnknown_203B290
_0802252C:
	movs r0, 0xA
	bl sub_8021D44
_08022532:
	add sp, 0x4
	pop {r0}
	bx r0
	thumb_func_end sub_80224D4

	thumb_func_start sub_8022538
sub_8022538:
	push {r4,lr}
	movs r0, 0x1
	bl sub_8021274
	cmp r0, 0x4
	bhi _080225BC
	lsls r0, 2
	ldr r1, _08022550
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08022550: .4byte _08022554
	.align 2, 0
_08022554:
	.4byte _080225C2
	.4byte _080225BC
	.4byte _080225B0
	.4byte _08022568
	.4byte _0802258C
_08022568:
	bl sub_802132C
	ldr r4, _08022588
	ldr r1, [r4]
	strb r0, [r1, 0x10]
	ldr r0, [r4]
	ldrb r0, [r0, 0x10]
	bl sub_8092544
	ldr r1, [r4]
	str r0, [r1, 0xC]
	movs r0, 0xB
	bl sub_8021D44
	b _080225C2
	.align 2, 0
_08022588: .4byte gUnknown_203B290
_0802258C:
	bl sub_802132C
	ldr r4, _080225AC
	ldr r1, [r4]
	strb r0, [r1, 0x10]
	ldr r0, [r4]
	ldrb r0, [r0, 0x10]
	bl sub_8092544
	ldr r1, [r4]
	str r0, [r1, 0xC]
	movs r0, 0x10
	bl sub_8021D44
	b _080225C2
	.align 2, 0
_080225AC: .4byte gUnknown_203B290
_080225B0:
	bl sub_80213A0
	movs r0, 0x1
	bl sub_8021D44
	b _080225C2
_080225BC:
	movs r0, 0x1
	bl sub_8016C40
_080225C2:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_8022538

	thumb_func_start sub_80225C8
sub_80225C8:
	push {r4,lr}
	sub sp, 0x4
	movs r0, 0
	str r0, [sp]
	bl sub_8021274
	ldr r4, _08022608
	ldr r0, [r4]
	adds r0, 0x6C
	bl sub_8012FD8
	lsls r0, 24
	cmp r0, 0
	bne _080225F8
	ldr r0, [r4]
	adds r0, 0x6C
	mov r1, sp
	bl sub_8013114
	ldr r1, [sp]
	cmp r1, 0x1
	beq _080225F8
	ldr r0, [r4]
	str r1, [r0, 0x18]
_080225F8:
	ldr r0, [sp]
	cmp r0, 0x2
	beq _08022612
	cmp r0, 0x2
	bgt _0802260C
	cmp r0, 0x1
	beq _08022658
	b _0802265E
	.align 2, 0
_08022608: .4byte gUnknown_203B290
_0802260C:
	cmp r0, 0x4
	beq _08022650
	b _0802265E
_08022612:
	ldr r0, _0802262C
	ldr r0, [r0]
	movs r1, 0x98
	lsls r1, 2
	adds r0, r1
	ldr r1, [r0]
	cmp r1, 0
	bne _08022630
	movs r0, 0x6
	bl sub_8021D44
	b _0802265E
	.align 2, 0
_0802262C: .4byte gUnknown_203B460
_08022630:
	ldr r0, _08022644
	ldr r0, [r0]
	ldr r0, [r0, 0xC]
	cmp r0, r1
	ble _08022648
	movs r0, 0x13
	bl sub_8021D44
	b _0802265E
	.align 2, 0
_08022644: .4byte gUnknown_203B290
_08022648:
	movs r0, 0x11
	bl sub_8021D44
	b _0802265E
_08022650:
	movs r0, 0x10
	bl sub_8021D44
	b _0802265E
_08022658:
	movs r0, 0xA
	bl sub_8021D44
_0802265E:
	add sp, 0x4
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_80225C8

	thumb_func_start sub_8022668
sub_8022668:
	push {lr}
	bl sub_80217EC
	cmp r0, 0x1
	bls _08022680
	cmp r0, 0x3
	bhi _08022680
	bl sub_8021830
	movs r0, 0xA
	bl sub_8021D44
_08022680:
	pop {r0}
	bx r0
	thumb_func_end sub_8022668

	thumb_func_start sub_8022684
sub_8022684:
	push {r4,lr}
	movs r0, 0x1
	bl sub_8023278
	cmp r0, 0x2
	beq _080226BC
	cmp r0, 0x2
	bcc _080226C6
	cmp r0, 0x3
	bne _080226C6
	bl sub_802331C
	ldr r4, _080226B8
	ldr r1, [r4]
	strh r0, [r1, 0x12]
	movs r2, 0x12
	ldrsh r0, [r1, r2]
	bl GetFriendArea
	ldr r1, [r4]
	strb r0, [r1, 0x10]
	movs r0, 0x18
	bl sub_8021D44
	b _080226C6
	.align 2, 0
_080226B8: .4byte gUnknown_203B290
_080226BC:
	bl sub_80233A0
	movs r0, 0x1
	bl sub_8021D44
_080226C6:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_8022684

	thumb_func_start sub_80226CC
sub_80226CC:
	push {lr}
	sub sp, 0x4
	mov r0, sp
	bl sub_80144A4
	cmp r0, 0
	bne _080226E4
	ldr r0, _080226EC
	ldr r0, [r0]
	ldr r0, [r0, 0x8]
	bl sub_8021D44
_080226E4:
	add sp, 0x4
	pop {r0}
	bx r0
	.align 2, 0
_080226EC: .4byte gUnknown_203B290
	thumb_func_end sub_80226CC

	thumb_func_start sub_80226F0
sub_80226F0:
	push {r4,lr}
	sub sp, 0x4
	mov r1, sp
	movs r2, 0
	movs r0, 0x80
	strb r0, [r1]
	strb r0, [r1, 0x1]
	movs r0, 0x10
	strb r0, [r1, 0x2]
	strb r2, [r1, 0x3]
	bl sub_8099B94
	lsls r0, 24
	cmp r0, 0
	bne _08022782
	ldr r0, _08022728
	ldr r0, [r0]
	movs r1, 0x98
	lsls r1, 1
	adds r0, r1
	ldr r0, [r0]
	cmp r0, 0x4
	bhi _0802275C
	lsls r0, 2
	ldr r1, _0802272C
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08022728: .4byte gUnknown_203B290
_0802272C: .4byte _08022730
	.align 2, 0
_08022730:
	.4byte _0802275C
	.4byte _08022744
	.4byte _08022750
	.4byte _08022744
	.4byte _08022750
_08022744:
	movs r0, 0x5
	movs r1, 0x2
	ldr r2, [sp]
	bl sub_8099AFC
	b _08022772
_08022750:
	movs r0, 0x5
	movs r1, 0x2
	ldr r2, [sp]
	bl sub_8099A5C
	b _08022772
_0802275C:
	ldr r4, _0802278C
	ldr r0, [r4]
	ldr r0, [r0, 0x8]
	bl sub_8021D44
	ldr r0, [r4]
	movs r1, 0x98
	lsls r1, 1
	adds r0, r1
	movs r1, 0
	str r1, [r0]
_08022772:
	ldr r0, _0802278C
	ldr r1, [r0]
	movs r0, 0x98
	lsls r0, 1
	adds r1, r0
	ldr r0, [r1]
	adds r0, 0x1
	str r0, [r1]
_08022782:
	add sp, 0x4
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0802278C: .4byte gUnknown_203B290
	thumb_func_end sub_80226F0

	thumb_func_start sub_8022790
sub_8022790:
	push {lr}
	ldr r0, _080227A8
	ldr r2, [r0]
	movs r0, 0x9A
	lsls r0, 1
	adds r1, r2, r0
	ldr r0, [r1]
	cmp r0, 0
	beq _080227AC
	subs r0, 0x1
	str r0, [r1]
	b _080227B2
	.align 2, 0
_080227A8: .4byte gUnknown_203B290
_080227AC:
	ldr r0, [r2, 0x8]
	bl sub_8021D44
_080227B2:
	pop {r0}
	bx r0
	thumb_func_end sub_8022790

	thumb_func_start sub_80227B8
sub_80227B8:
	push {r4,r5,lr}
	adds r5, r0, 0
	bl sub_8004914
	movs r0, 0
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	ldr r4, _08022810
	movs r0, 0xD4
	lsls r0, 1
	movs r1, 0x8
	bl MemoryAlloc
	str r0, [r4]
	adds r2, r0, 0
	adds r2, 0xF4
	movs r1, 0
	str r1, [r2]
	str r5, [r0, 0x48]
	cmp r5, 0
	beq _08022820
	ldr r4, _08022814
	adds r0, r4, 0
	adds r1, r5, 0
	movs r2, 0x7
	bl sub_808D9AC
	adds r4, 0x50
	adds r0, r4, 0
	adds r1, r5, 0
	movs r2, 0x6
	bl sub_808D9AC
	bl sub_809177C
	lsls r0, 24
	cmp r0, 0
	beq _08022818
	movs r0, 0
	bl sub_8022924
	b _08022856
	.align 2, 0
_08022810: .4byte gUnknown_203B294
_08022814: .4byte gUnknown_202DF98
_08022818:
	movs r0, 0x11
	bl sub_8022924
	b _08022856
_08022820:
	ldr r4, _08022848
	ldr r5, _0802284C
	adds r0, r4, 0
	adds r1, r5, 0
	bl strcpy
	adds r4, 0x50
	adds r0, r4, 0
	adds r1, r5, 0
	bl strcpy
	bl sub_8090A34
	cmp r0, 0
	bne _08022850
	movs r0, 0x12
	bl sub_8022924
	b _08022856
	.align 2, 0
_08022848: .4byte gUnknown_202DF98
_0802284C: .4byte gUnknown_80DC5EC
_08022850:
	movs r0, 0
	bl sub_8022924
_08022856:
	movs r0, 0x1
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_80227B8

	thumb_func_start sub_8022860
sub_8022860:
	push {lr}
	ldr r0, _08022878
	ldr r0, [r0]
	ldr r0, [r0]
	cmp r0, 0x16
	bhi _080228FE
	lsls r0, 2
	ldr r1, _0802287C
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08022878: .4byte gUnknown_203B294
_0802287C: .4byte _08022880
	.align 2, 0
_08022880:
	.4byte _080228DC
	.4byte _080228DC
	.4byte _080228E2
	.4byte _080228E8
	.4byte _080228EE
	.4byte _080228FE
	.4byte _080228FE
	.4byte _080228FE
	.4byte _080228FE
	.4byte _080228FE
	.4byte _080228FE
	.4byte _080228FE
	.4byte _080228FE
	.4byte _080228FE
	.4byte _080228FE
	.4byte _080228FE
	.4byte _080228FE
	.4byte _080228FE
	.4byte _080228FE
	.4byte _080228FE
	.4byte _080228FE
	.4byte _080228F4
	.4byte _080228FA
_080228DC:
	bl sub_8022E78
	b _08022902
_080228E2:
	bl sub_8022EF4
	b _08022902
_080228E8:
	bl sub_8023068
	b _08022902
_080228EE:
	bl sub_80230E8
	b _08022902
_080228F4:
	bl sub_8023104
	b _08022902
_080228FA:
	movs r0, 0x3
	b _08022904
_080228FE:
	bl sub_8023120
_08022902:
	movs r0, 0
_08022904:
	pop {r1}
	bx r1
	thumb_func_end sub_8022860

	thumb_func_start sub_8022908
sub_8022908:
	push {r4,lr}
	ldr r4, _08022920
	ldr r0, [r4]
	cmp r0, 0
	beq _0802291A
	bl MemoryFree
	movs r0, 0
	str r0, [r4]
_0802291A:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08022920: .4byte gUnknown_203B294
	thumb_func_end sub_8022908

	thumb_func_start sub_8022924
sub_8022924:
	push {lr}
	ldr r1, _08022938
	ldr r1, [r1]
	str r0, [r1]
	bl sub_802293C
	bl sub_8022A10
	pop {r0}
	bx r0
	.align 2, 0
_08022938: .4byte gUnknown_203B294
	thumb_func_end sub_8022924

	thumb_func_start sub_802293C
sub_802293C:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	ldr r4, _08022964
	ldr r0, [r4]
	movs r1, 0xA4
	lsls r1, 1
	adds r0, r1
	bl sub_8006518
	ldr r1, [r4]
	ldr r0, [r1]
	cmp r0, 0x3
	beq _080229A4
	cmp r0, 0x3
	bgt _08022968
	cmp r0, 0x2
	beq _08022972
	b _080229BC
	.align 2, 0
_08022964: .4byte gUnknown_203B294
_08022968:
	cmp r0, 0x10
	bgt _080229BC
	cmp r0, 0xA
	blt _080229BC
	b _080229E6
_08022972:
	bl sub_8022D2C
	ldr r2, [r4]
	movs r0, 0xBC
	lsls r0, 1
	adds r2, r0
	ldr r1, _080229A0
	ldm r1!, {r3,r5,r6}
	stm r2!, {r3,r5,r6}
	ldm r1!, {r3,r5,r7}
	stm r2!, {r3,r5,r7}
	ldr r1, [r4]
	adds r0, r1, r0
	adds r1, 0xF8
	bl sub_8012CAC
	ldr r0, [r4]
	movs r6, 0xC2
	lsls r6, 1
	adds r0, r6
	movs r1, 0x6
	strh r1, [r0]
	b _080229E6
	.align 2, 0
_080229A0: .4byte gUnknown_80DC5BC
_080229A4:
	movs r7, 0xB0
	lsls r7, 1
	adds r1, r7
	ldr r0, _080229B8
	ldm r0!, {r2-r4}
	stm r1!, {r2-r4}
	ldm r0!, {r5-r7}
	stm r1!, {r5-r7}
	b _080229E6
	.align 2, 0
_080229B8: .4byte gUnknown_80DC5D4
_080229BC:
	ldr r0, _08022A08
	mov r12, r0
	movs r1, 0xA4
	lsls r1, 1
	mov r8, r1
	ldr r4, _08022A0C
	movs r3, 0
	movs r2, 0x3
_080229CC:
	mov r5, r12
	ldr r1, [r5]
	adds r1, r3
	add r1, r8
	adds r0, r4, 0
	ldm r0!, {r5-r7}
	stm r1!, {r5-r7}
	ldm r0!, {r5-r7}
	stm r1!, {r5-r7}
	adds r3, 0x18
	subs r2, 0x1
	cmp r2, 0
	bge _080229CC
_080229E6:
	bl sub_8004914
	ldr r0, _08022A08
	ldr r0, [r0]
	movs r6, 0xA4
	lsls r6, 1
	adds r0, r6
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_08022A08: .4byte gUnknown_203B294
_08022A0C: .4byte gUnknown_80DC5A4
	thumb_func_end sub_802293C

	thumb_func_start sub_8022A10
sub_8022A10:
	push {r4-r7,lr}
	sub sp, 0x8
	ldr r1, _08022A2C
	ldr r0, [r1]
	ldr r0, [r0]
	adds r4, r1, 0
	cmp r0, 0x16
	bls _08022A22
	b _08022D1E
_08022A22:
	lsls r0, 2
	ldr r1, _08022A30
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08022A2C: .4byte gUnknown_203B294
_08022A30: .4byte _08022A34
	.align 2, 0
_08022A34:
	.4byte _08022A90
	.4byte _08022AAA
	.4byte _08022AB2
	.4byte _08022AE0
	.4byte _08022B10
	.4byte _08022B1A
	.4byte _08022B24
	.4byte _08022B34
	.4byte _08022B44
	.4byte _08022B54
	.4byte _08022B64
	.4byte _08022C28
	.4byte _08022CA0
	.4byte _08022CA8
	.4byte _08022CB0
	.4byte _08022CB8
	.4byte _08022CC0
	.4byte _08022CC8
	.4byte _08022CD8
	.4byte _08022CE8
	.4byte _08022CF8
	.4byte _08022D14
	.4byte _08022D1E
_08022A90:
	ldr r0, [r4]
	ldr r0, [r0, 0x48]
	cmp r0, 0
	beq _08022A9C
	movs r0, 0x5
	b _08022A9E
_08022A9C:
	movs r0, 0x1
_08022A9E:
	movs r1, 0x3
	movs r2, 0
	movs r3, 0xA
	bl sub_801A5D8
	b _08022D22
_08022AAA:
	movs r0, 0x1
	bl sub_801A8D0
	b _08022D22
_08022AB2:
	bl sub_801A9E0
	ldr r0, _08022ADC
	ldr r2, [r0]
	adds r0, r2, 0
	adds r0, 0x54
	adds r1, r2, 0
	adds r1, 0xF8
	movs r4, 0x9C
	lsls r4, 1
	adds r3, r2, r4
	adds r2, 0xF4
	ldr r2, [r2]
	str r2, [sp]
	movs r2, 0x2
	str r2, [sp, 0x4]
	movs r2, 0
	bl sub_8012D60
	b _08022D22
	.align 2, 0
_08022ADC: .4byte gUnknown_203B294
_08022AE0:
	bl sub_801A9E0
	ldr r4, _08022B08
	ldr r0, [r4]
	adds r0, 0x54
	movs r1, 0
	bl sub_8012EA4
	ldr r0, [r4]
	adds r0, 0xA4
	ldr r1, _08022B0C
	movs r2, 0x3
	str r2, [sp]
	movs r2, 0x1
	str r2, [sp, 0x4]
	movs r2, 0
	movs r3, 0
	bl sub_8012D60
	b _08022D22
	.align 2, 0
_08022B08: .4byte gUnknown_203B294
_08022B0C: .4byte gUnknown_80DC584
_08022B10:
	ldr r0, [r4]
	adds r0, 0x50
	bl sub_801B3C0
	b _08022D22
_08022B1A:
	ldr r0, _08022B20
	b _08022D00
	.align 2, 0
_08022B20: .4byte gUnknown_80DC5F4
_08022B24:
	ldr r0, _08022B2C
	ldr r3, _08022B30
	b _08022D02
	.align 2, 0
_08022B2C: .4byte gUnknown_80DC618
_08022B30: .4byte 0x00000101
_08022B34:
	ldr r0, _08022B3C
	ldr r3, _08022B40
	b _08022D02
	.align 2, 0
_08022B3C: .4byte gUnknown_80DC674
_08022B40: .4byte 0x00000101
_08022B44:
	ldr r0, _08022B4C
	ldr r3, _08022B50
	b _08022D02
	.align 2, 0
_08022B4C: .4byte gUnknown_80DC6CC
_08022B50: .4byte 0x00000101
_08022B54:
	ldr r0, _08022B5C
	ldr r3, _08022B60
	b _08022D02
	.align 2, 0
_08022B5C: .4byte gUnknown_80DC728
_08022B60: .4byte 0x00000101
_08022B64:
	ldr r7, _08022B68
	b _08022B78
	.align 2, 0
_08022B68: .4byte gUnknown_203B294
_08022B6C:
	ldr r1, [r4]
	ldr r0, [r1, 0x40]
	adds r0, 0x1
	str r0, [r1, 0x40]
	cmp r0, 0x17
	bgt _08022C10
_08022B78:
	movs r5, 0
	movs r6, 0
	movs r3, 0
	ldr r2, [r4]
	ldr r0, [r2, 0x38]
	cmp r5, r0
	bge _08022BA4
	ldrb r1, [r2, 0x8]
	b _08022B9C
_08022B8A:
	adds r3, 0x1
	ldr r2, [r4]
	ldr r0, [r2, 0x38]
	cmp r3, r0
	bge _08022BA4
	adds r0, r2, 0
	adds r0, 0x8
	adds r0, r3
	ldrb r1, [r0]
_08022B9C:
	ldr r0, [r2, 0x40]
	cmp r1, r0
	bne _08022B8A
	movs r5, 0x1
_08022BA4:
	movs r3, 0
	ldr r2, [r4]
	ldr r0, [r2, 0x3C]
	cmp r3, r0
	bge _08022BCE
	adds r0, r2, 0
	adds r0, 0x20
	b _08022BC4
_08022BB4:
	adds r3, 0x1
	ldr r2, [r4]
	ldr r0, [r2, 0x3C]
	cmp r3, r0
	bge _08022BCE
	adds r0, r2, 0
	adds r0, 0x20
	adds r0, r3
_08022BC4:
	ldrb r1, [r0]
	ldr r0, [r2, 0x40]
	cmp r1, r0
	bne _08022BB4
	movs r6, 0x1
_08022BCE:
	cmp r5, r6
	beq _08022B6C
	ldr r1, [r7]
	movs r0, 0xA
	str r0, [r1, 0x4]
	ldr r0, [r1, 0x40]
	lsls r0, 24
	lsrs r0, 24
	bl sub_808EAB0
	adds r1, r0, 0
	ldr r0, _08022C18
	bl strcpy
	movs r0, 0xCB
	bl sub_8011988
	ldr r0, _08022C1C
	movs r1, 0
	movs r2, 0
	ldr r3, _08022C20
	bl sub_80141B4
	ldr r1, [r7]
	ldr r0, [r1, 0x40]
	adds r0, 0x1
	str r0, [r1, 0x40]
	ldr r0, _08022C24
	ldr r0, [r0]
	ldr r0, [r0, 0x40]
	cmp r0, 0x17
	bgt _08022C10
	b _08022D22
_08022C10:
	movs r0, 0xB
	bl sub_8022924
	b _08022D22
	.align 2, 0
_08022C18: .4byte gUnknown_202DEA8
_08022C1C: .4byte gUnknown_80DC788
_08022C20: .4byte 0x00000101
_08022C24: .4byte gUnknown_203B294
_08022C28:
	ldr r1, [r4]
	movs r0, 0x16
	str r0, [r1, 0x4]
	bl nullsub_104
	ldr r0, [r4]
	adds r0, 0x46
	ldrh r0, [r0]
	cmp r0, 0x8
	bhi _08022C98
	lsls r0, 2
	ldr r1, _08022C48
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08022C48: .4byte _08022C4C
	.align 2, 0
_08022C4C:
	.4byte _08022C70
	.4byte _08022C78
	.4byte _08022C80
	.4byte _08022C98
	.4byte _08022C88
	.4byte _08022C98
	.4byte _08022C98
	.4byte _08022C98
	.4byte _08022C90
_08022C70:
	movs r0, 0x16
	bl sub_8022924
	b _08022D22
_08022C78:
	movs r0, 0xD
	bl sub_8022924
	b _08022D22
_08022C80:
	movs r0, 0xE
	bl sub_8022924
	b _08022D22
_08022C88:
	movs r0, 0xF
	bl sub_8022924
	b _08022D22
_08022C90:
	movs r0, 0x10
	bl sub_8022924
	b _08022D22
_08022C98:
	movs r0, 0xC
	bl sub_8022924
	b _08022D22
_08022CA0:
	ldr r0, _08022CA4
	b _08022D00
	.align 2, 0
_08022CA4: .4byte gUnknown_80DC7B4
_08022CA8:
	ldr r0, _08022CAC
	b _08022D00
	.align 2, 0
_08022CAC: .4byte gUnknown_80DC7FC
_08022CB0:
	ldr r0, _08022CB4
	b _08022D00
	.align 2, 0
_08022CB4: .4byte gUnknown_80DC81C
_08022CB8:
	ldr r0, _08022CBC
	b _08022D00
	.align 2, 0
_08022CBC: .4byte gUnknown_80DC844
_08022CC0:
	ldr r0, _08022CC4
	b _08022D00
	.align 2, 0
_08022CC4: .4byte gUnknown_80DC864
_08022CC8:
	ldr r1, [r4]
	movs r0, 0x16
	str r0, [r1, 0x4]
	ldr r0, _08022CD4
	b _08022D00
	.align 2, 0
_08022CD4: .4byte gUnknown_80DC88C
_08022CD8:
	ldr r1, [r4]
	movs r0, 0x16
	str r0, [r1, 0x4]
	ldr r0, _08022CE4
	b _08022D00
	.align 2, 0
_08022CE4: .4byte gUnknown_80DC8AC
_08022CE8:
	ldr r1, [r4]
	movs r0, 0x16
	str r0, [r1, 0x4]
	ldr r0, _08022CF4
	b _08022D00
	.align 2, 0
_08022CF4: .4byte gUnknown_80DC8C8
_08022CF8:
	ldr r1, [r4]
	movs r0, 0x16
	str r0, [r1, 0x4]
	ldr r0, _08022D0C
_08022D00:
	ldr r3, _08022D10
_08022D02:
	movs r1, 0
	movs r2, 0
	bl sub_80141B4
	b _08022D22
	.align 2, 0
_08022D0C: .4byte gUnknown_80DC8DC
_08022D10: .4byte 0x00000301
_08022D14:
	ldr r0, [r4]
	ldr r0, [r0, 0x4C]
	bl sub_801AFA4
	b _08022D22
_08022D1E:
	bl sub_801A928
_08022D22:
	add sp, 0x8
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_8022A10

	thumb_func_start sub_8022D2C
sub_8022D2C:
	push {r4-r7,lr}
	movs r6, 0
	ldr r4, _08022D78
	ldr r0, [r4]
	movs r1, 0x9C
	lsls r1, 1
	adds r0, r1
	movs r1, 0
	movs r2, 0x10
	bl MemoryFill16
	ldr r2, [r4]
	ldr r0, [r2, 0x48]
	cmp r0, 0
	beq _08022D80
	adds r1, r2, 0
	adds r1, 0xF8
	ldr r0, _08022D7C
	str r0, [r1]
	adds r1, 0x4
	movs r0, 0x5
	str r0, [r1]
	adds r0, r2, 0
	adds r0, 0x52
	ldrb r0, [r0]
	bl sub_8091764
	lsls r0, 24
	cmp r0, 0
	bne _08022D74
	ldr r0, [r4]
	movs r2, 0x9C
	lsls r2, 1
	adds r0, r2
	movs r1, 0x1
	strh r1, [r0]
_08022D74:
	movs r6, 0x1
	b _08022DBE
	.align 2, 0
_08022D78: .4byte gUnknown_203B294
_08022D7C: .4byte gUnknown_80DC8F0
_08022D80:
	adds r0, r2, 0
	adds r0, 0x52
	ldrb r0, [r0]
	bl sub_8090BD0
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x5
	bne _08022DA4
	ldr r1, [r4]
	adds r2, r1, 0
	adds r2, 0xF8
	ldr r0, _08022E38
	str r0, [r2]
	adds r1, 0xFC
	movs r0, 0x6
	str r0, [r1]
	movs r6, 0x1
_08022DA4:
	ldr r2, [r4]
	lsls r3, r6, 3
	adds r0, r2, 0
	adds r0, 0xF8
	adds r0, r3
	ldr r1, _08022E3C
	ldr r1, [r1]
	str r1, [r0]
	adds r2, 0xFC
	adds r2, r3
	movs r0, 0x4
	str r0, [r2]
	adds r6, 0x1
_08022DBE:
	ldr r4, _08022E40
	ldr r0, [r4]
	mov r12, r0
	lsls r1, r6, 3
	mov r2, r12
	adds r2, 0xF8
	adds r3, r2, r1
	ldr r0, _08022E44
	ldr r0, [r0]
	str r0, [r3]
	mov r3, r12
	adds r3, 0xFC
	adds r1, r3, r1
	movs r0, 0x7
	str r0, [r1]
	adds r6, 0x1
	lsls r1, r6, 3
	adds r2, r1
	movs r0, 0
	str r0, [r2]
	adds r1, r3, r1
	movs r0, 0x1
	str r0, [r1]
	movs r5, 0
	adds r7, r4, 0
	cmp r5, r6
	bge _08022E16
	mov r4, r12
	adds r4, 0xF4
	movs r2, 0x9C
	lsls r2, 1
	add r2, r12
_08022DFE:
	ldrh r0, [r2]
	cmp r0, 0
	bne _08022E0C
	ldr r1, [r3]
	ldr r0, [r4]
	cmp r1, r0
	beq _08022E70
_08022E0C:
	adds r2, 0x2
	adds r3, 0x8
	adds r5, 0x1
	cmp r5, r6
	blt _08022DFE
_08022E16:
	movs r5, 0
	cmp r5, r6
	bge _08022E70
	ldr r1, [r7]
	movs r2, 0x9C
	lsls r2, 1
	adds r0, r1, r2
	ldrh r0, [r0]
	cmp r0, 0
	bne _08022E48
	adds r0, r1, 0
	adds r0, 0xF4
	adds r1, 0xFC
	ldr r1, [r1]
	str r1, [r0]
	b _08022E70
	.align 2, 0
_08022E38: .4byte gUnknown_80DC8F8
_08022E3C: .4byte gUnknown_80D4940
_08022E40: .4byte gUnknown_203B294
_08022E44: .4byte gUnknown_80D4970
_08022E48:
	adds r5, 0x1
	cmp r5, r6
	bge _08022E70
	ldr r3, [r7]
	lsls r0, r5, 1
	movs r2, 0x9C
	lsls r2, 1
	adds r1, r3, r2
	adds r1, r0
	ldrh r0, [r1]
	cmp r0, 0
	bne _08022E48
	adds r2, r3, 0
	adds r2, 0xF4
	lsls r1, r5, 3
	adds r0, r3, 0
	adds r0, 0xFC
	adds r0, r1
	ldr r0, [r0]
	str r0, [r2]
_08022E70:
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_8022D2C

	thumb_func_start sub_8022E78
sub_8022E78:
	push {lr}
	movs r0, 0x1
	bl sub_801A6E8
	cmp r0, 0x3
	beq _08022E94
	cmp r0, 0x3
	bhi _08022E8E
	cmp r0, 0x2
	beq _08022EE8
	b _08022EEE
_08022E8E:
	cmp r0, 0x4
	beq _08022EBC
	b _08022EEE
_08022E94:
	bl sub_801A8AC
	ldr r1, _08022EB4
	ldr r2, [r1]
	str r0, [r2, 0x4C]
	ldr r1, _08022EB8
	ldr r1, [r1]
	lsls r0, 2
	adds r1, r0
	ldr r0, [r1]
	str r0, [r2, 0x50]
	movs r0, 0x2
	bl sub_8022924
	b _08022EEE
	.align 2, 0
_08022EB4: .4byte gUnknown_203B294
_08022EB8: .4byte gUnknown_203B460
_08022EBC:
	bl sub_801A8AC
	ldr r1, _08022EE0
	ldr r2, [r1]
	str r0, [r2, 0x4C]
	ldr r1, _08022EE4
	ldr r1, [r1]
	lsls r0, 2
	adds r1, r0
	ldr r0, [r1]
	str r0, [r2, 0x50]
	movs r0, 0
	bl sub_8099690
	movs r0, 0x4
	bl sub_8022924
	b _08022EEE
	.align 2, 0
_08022EE0: .4byte gUnknown_203B294
_08022EE4: .4byte gUnknown_203B460
_08022EE8:
	movs r0, 0x16
	bl sub_8022924
_08022EEE:
	pop {r0}
	bx r0
	thumb_func_end sub_8022E78

	thumb_func_start sub_8022EF4
sub_8022EF4:
	push {r4,r5,lr}
	sub sp, 0x4
	movs r0, 0
	str r0, [sp]
	bl sub_801A6E8
	ldr r4, _08022F3C
	ldr r0, [r4]
	adds r0, 0x54
	bl sub_8012FD8
	lsls r0, 24
	cmp r0, 0
	bne _08022F26
	ldr r0, [r4]
	adds r0, 0x54
	mov r1, sp
	bl sub_8013114
	ldr r1, [sp]
	cmp r1, 0x1
	beq _08022F26
	ldr r0, [r4]
	adds r0, 0xF4
	str r1, [r0]
_08022F26:
	ldr r0, [sp]
	subs r0, 0x1
	cmp r0, 0x6
	bls _08022F30
	b _08023060
_08022F30:
	lsls r0, 2
	ldr r1, _08022F40
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08022F3C: .4byte gUnknown_203B294
_08022F40: .4byte _08022F44
	.align 2, 0
_08022F44:
	.4byte _08022F60
	.4byte _08023060
	.4byte _08023060
	.4byte _0802304C
	.4byte _08022F68
	.4byte _08023044
	.4byte _08023054
_08022F60:
	movs r0, 0x1
	bl sub_8022924
	b _08023060
_08022F68:
	ldr r4, _08022FEC
	ldr r1, [r4]
	adds r0, r1, 0
	adds r0, 0x8
	ldr r1, [r1, 0x48]
	movs r2, 0x14
	ldrsh r1, [r1, r2]
	bl sub_808EBA8
	ldr r3, [r4]
	str r0, [r3, 0x38]
	ldr r0, [r3, 0x48]
	adds r1, r3, 0
	adds r1, 0x52
	ldrb r1, [r1]
	adds r3, 0x44
	movs r2, 0
	bl sub_80915F4
	ldr r1, [r4]
	adds r0, r1, 0
	adds r0, 0x20
	ldr r1, [r1, 0x48]
	movs r2, 0x14
	ldrsh r1, [r1, r2]
	bl sub_808EBA8
	ldr r1, [r4]
	str r0, [r1, 0x3C]
	movs r0, 0x1
	str r0, [r1, 0x40]
	adds r0, r1, 0
	adds r0, 0x44
	movs r2, 0
	ldrsh r5, [r0, r2]
	ldr r0, _08022FF0
	ldr r3, _08022FF4
	ldr r2, [r1, 0x4C]
	lsls r2, 2
	ldr r1, [r3]
	adds r1, r2
	movs r2, 0
	bl sub_8090E14
	movs r0, 0x1
	negs r0, r0
	cmp r5, r0
	beq _08022FD0
	ldr r0, [r4]
	ldr r0, [r0, 0x4C]
	bl sub_80911F8
_08022FD0:
	movs r0, 0
	bl sub_8099690
	ldr r1, [r4]
	movs r0, 0xA
	str r0, [r1, 0x4]
	adds r0, r5, 0x1
	cmp r0, 0x4
	bhi _08023030
	lsls r0, 2
	ldr r1, _08022FF8
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08022FEC: .4byte gUnknown_203B294
_08022FF0: .4byte gUnknown_202DE58
_08022FF4: .4byte gUnknown_203B460
_08022FF8: .4byte _08022FFC
	.align 2, 0
_08022FFC:
	.4byte _08023030
	.4byte _08023010
	.4byte _08023018
	.4byte _08023020
	.4byte _08023028
_08023010:
	movs r0, 0x6
	bl sub_8022924
	b _08023060
_08023018:
	movs r0, 0x7
	bl sub_8022924
	b _08023060
_08023020:
	movs r0, 0x8
	bl sub_8022924
	b _08023060
_08023028:
	movs r0, 0x9
	bl sub_8022924
	b _08023060
_08023030:
	ldr r0, _08023040
	ldr r1, [r0]
	movs r0, 0x16
	str r0, [r1, 0x4]
	movs r0, 0x5
	bl sub_8022924
	b _08023060
	.align 2, 0
_08023040: .4byte gUnknown_203B294
_08023044:
	movs r0, 0x15
	bl sub_8022924
	b _08023060
_0802304C:
	movs r0, 0x3
	bl sub_8022924
	b _08023060
_08023054:
	movs r0, 0
	bl sub_8099690
	movs r0, 0x4
	bl sub_8022924
_08023060:
	add sp, 0x4
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_8022EF4

	thumb_func_start sub_8023068
sub_8023068:
	push {r4,lr}
	sub sp, 0x4
	movs r0, 0
	str r0, [sp]
	bl sub_801A6E8
	ldr r4, _080230A8
	ldr r0, [r4]
	adds r0, 0x54
	bl sub_8012FD8
	ldr r0, [r4]
	adds r0, 0xA4
	bl sub_8012FD8
	lsls r0, 24
	cmp r0, 0
	bne _08023096
	ldr r0, [r4]
	adds r0, 0xA4
	mov r1, sp
	bl sub_8013114
_08023096:
	ldr r0, [sp]
	cmp r0, 0x2
	beq _080230B8
	cmp r0, 0x2
	bgt _080230AC
	cmp r0, 0x1
	beq _080230B0
	b _080230E0
	.align 2, 0
_080230A8: .4byte gUnknown_203B294
_080230AC:
	cmp r0, 0x3
	bne _080230E0
_080230B0:
	movs r0, 0x1
	bl sub_8022924
	b _080230E0
_080230B8:
	ldr r0, [r4]
	ldr r0, [r0, 0x4C]
	bl sub_80911F8
	bl sub_8090A34
	cmp r0, 0
	bne _080230DA
	movs r0, 0
	bl sub_8099690
	bl sub_801A928
	movs r0, 0x14
	bl sub_8022924
	b _080230E0
_080230DA:
	movs r0, 0x1
	bl sub_8022924
_080230E0:
	add sp, 0x4
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_8023068

	thumb_func_start sub_80230E8
sub_80230E8:
	push {lr}
	bl sub_801B410
	cmp r0, 0x1
	bls _08023100
	cmp r0, 0x3
	bhi _08023100
	bl sub_801B450
	movs r0, 0x1
	bl sub_8022924
_08023100:
	pop {r0}
	bx r0
	thumb_func_end sub_80230E8

	thumb_func_start sub_8023104
sub_8023104:
	push {lr}
	bl sub_801B00C
	cmp r0, 0x1
	bls _0802311C
	cmp r0, 0x3
	bhi _0802311C
	bl sub_801B048
	movs r0, 0x1
	bl sub_8022924
_0802311C:
	pop {r0}
	bx r0
	thumb_func_end sub_8023104

	thumb_func_start sub_8023120
sub_8023120:
	push {lr}
	sub sp, 0x4
	mov r0, sp
	bl sub_80144A4
	cmp r0, 0
	bne _08023138
	ldr r0, _08023140
	ldr r0, [r0]
	ldr r0, [r0, 0x4]
	bl sub_8022924
_08023138:
	add sp, 0x4
	pop {r0}
	bx r0
	.align 2, 0
_08023140: .4byte gUnknown_203B294
	thumb_func_end sub_8023120

	thumb_func_start sub_8023144
sub_8023144:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	adds r7, r1, 0
	mov r9, r2
	mov r10, r3
	lsls r0, 24
	lsrs r0, 24
	adds r4, r0, 0
	bl sub_8023704
	lsls r0, 24
	cmp r0, 0
	beq _08023168
	movs r0, 0
	b _08023252
_08023168:
	ldr r6, _08023260
	ldr r0, [r6]
	cmp r0, 0
	bne _0802317C
	movs r0, 0xFF
	lsls r0, 2
	movs r1, 0x8
	bl MemoryAlloc
	str r0, [r6]
_0802317C:
	ldr r0, [r6]
	strb r4, [r0]
	ldr r0, [r6]
	ldr r1, _08023264
	ldr r1, [r1]
	str r1, [r0, 0x4]
	movs r4, 0xE4
	lsls r4, 2
	adds r1, r0, r4
	str r7, [r1]
	movs r1, 0xE5
	lsls r1, 2
	mov r8, r1
	adds r2, r0, r1
	lsls r1, r7, 1
	adds r1, r7
	lsls r1, 3
	movs r5, 0xE6
	lsls r5, 2
	adds r1, r5
	adds r1, r0, r1
	str r1, [r2]
	adds r0, r5
	bl sub_8006518
	ldr r1, [r6]
	adds r4, r1, r4
	ldr r2, [r4]
	lsls r0, r2, 1
	adds r0, r2
	lsls r0, 3
	adds r1, r0
	adds r1, r5
	ldr r0, _08023268
	ldm r0!, {r2-r4}
	stm r1!, {r2-r4}
	ldm r0!, {r2-r4}
	stm r1!, {r2-r4}
	ldr r2, [r6]
	mov r1, r8
	adds r0, r2, r1
	ldr r1, [r0]
	movs r3, 0xFE
	lsls r3, 2
	adds r0, r2, r3
	str r0, [r1, 0x14]
	mov r4, r9
	cmp r4, 0
	beq _080231F6
	movs r1, 0xE4
	lsls r1, 2
	adds r0, r2, r1
	ldr r1, [r0]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 3
	subs r3, 0x58
	adds r1, r2, r3
	adds r1, r0
	ldr r0, [r4]
	str r0, [r1]
_080231F6:
	ldr r0, [r6]
	add r0, r8
	ldr r0, [r0]
	mov r1, r10
	bl sub_8012D08
	bl sub_8004914
	ldr r0, [r6]
	adds r0, r5
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	ldr r4, [r6]
	movs r5, 0xD7
	lsls r5, 2
	adds r4, r5
	bl sub_80236A4
	adds r1, r0, 0
	adds r0, r4, 0
	mov r2, r10
	adds r3, r7, 0
	bl sub_8013818
	ldr r0, [r6]
	ldr r1, _0802326C
	ldrh r2, [r1]
	movs r4, 0xDD
	lsls r4, 2
	adds r1, r0, r4
	strh r2, [r1]
	ldr r1, _08023270
	ldrh r2, [r1]
	ldr r3, _08023274
	adds r1, r0, r3
	strh r2, [r1]
	adds r0, r5
	bl sub_8013984
	bl sub_8023420
	bl sub_80234BC
	movs r0, 0x1
_08023252:
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	.align 2, 0
_08023260: .4byte gUnknown_3001B5C
_08023264: .4byte gUnknown_203B298
_08023268: .4byte gUnknown_80DC91C
_0802326C: .4byte gUnknown_203B29C
_08023270: .4byte gUnknown_203B29E
_08023274: .4byte 0x0000037a
	thumb_func_end sub_8023144

	thumb_func_start sub_8023278
sub_8023278:
	push {r4,lr}
	lsls r0, 24
	cmp r0, 0
	bne _08023298
	ldr r0, _08023294
	ldr r0, [r0]
	movs r1, 0xD7
	lsls r1, 2
	adds r0, r1
	bl sub_8013660
	movs r0, 0
	b _08023316
	.align 2, 0
_08023294: .4byte gUnknown_3001B5C
_08023298:
	ldr r4, _080232B4
	ldr r0, [r4]
	movs r1, 0xD7
	lsls r1, 2
	adds r0, r1
	bl GetKeyPress
	cmp r0, 0x2
	beq _080232BE
	cmp r0, 0x2
	bgt _080232B8
	cmp r0, 0x1
	beq _080232C8
	b _080232EC
	.align 2, 0
_080232B4: .4byte gUnknown_3001B5C
_080232B8:
	cmp r0, 0x3
	beq _080232D2
	b _080232EC
_080232BE:
	movs r0, 0x1
	bl sub_80119D4
	movs r0, 0x2
	b _08023316
_080232C8:
	movs r0, 0
	bl sub_80119D4
	movs r0, 0x3
	b _08023316
_080232D2:
	movs r0, 0x5
	bl sub_80119D4
	ldr r0, [r4]
	ldr r1, [r0, 0x4]
	movs r2, 0x1
	cmp r1, 0x1
	bhi _080232E4
	adds r2, r1, 0x1
_080232E4:
	str r2, [r0, 0x4]
	bl sub_80236A4
	b _0802330C
_080232EC:
	ldr r0, _08023308
	ldr r0, [r0]
	movs r1, 0xD7
	lsls r1, 2
	adds r0, r1
	movs r1, 0x1
	bl sub_80138B8
	lsls r0, 24
	cmp r0, 0
	bne _0802330C
	movs r0, 0
	b _08023316
	.align 2, 0
_08023308: .4byte gUnknown_3001B5C
_0802330C:
	bl sub_8023420
	bl sub_80234BC
	movs r0, 0x1
_08023316:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_8023278

	thumb_func_start sub_802331C
sub_802331C:
	ldr r0, _0802334C
	ldr r0, [r0]
	ldr r2, _08023350
	adds r1, r0, r2
	movs r3, 0
	ldrsh r2, [r1, r3]
	movs r3, 0xDE
	lsls r3, 2
	adds r1, r0, r3
	movs r3, 0
	ldrsh r1, [r1, r3]
	muls r1, r2
	movs r3, 0xDD
	lsls r3, 2
	adds r2, r0, r3
	movs r3, 0
	ldrsh r2, [r2, r3]
	adds r1, r2
	lsls r1, 1
	adds r0, 0xC
	adds r0, r1
	movs r1, 0
	ldrsh r0, [r0, r1]
	bx lr
	.align 2, 0
_0802334C: .4byte gUnknown_3001B5C
_08023350: .4byte 0x0000037a
	thumb_func_end sub_802331C

	thumb_func_start sub_8023354
sub_8023354:
	push {r4,r5,lr}
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	bl sub_8004914
	ldr r5, _0802339C
	ldr r0, [r5]
	movs r1, 0xE6
	lsls r1, 2
	adds r0, r1
	movs r1, 0
	movs r2, 0
	bl sub_800641C
	ldr r0, [r5]
	movs r1, 0xD7
	lsls r1, 2
	adds r0, r1
	bl sub_8013984
	bl sub_8023420
	bl sub_80234BC
	cmp r4, 0
	beq _08023396
	ldr r0, [r5]
	movs r1, 0xD7
	lsls r1, 2
	adds r0, r1
	bl AddMenuCursorSprite
_08023396:
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_0802339C: .4byte gUnknown_3001B5C
	thumb_func_end sub_8023354

	thumb_func_start sub_80233A0
sub_80233A0:
	push {r4-r6,lr}
	ldr r5, _08023408
	ldr r2, [r5]
	cmp r2, 0
	beq _08023400
	ldr r1, _0802340C
	ldr r0, [r2, 0x4]
	str r0, [r1]
	ldr r1, _08023410
	movs r3, 0xDD
	lsls r3, 2
	adds r0, r2, r3
	ldrh r0, [r0]
	strh r0, [r1]
	ldr r1, _08023414
	ldr r6, _08023418
	adds r0, r2, r6
	ldrh r0, [r0]
	strh r0, [r1]
	movs r1, 0xE4
	lsls r1, 2
	adds r0, r2, r1
	ldr r0, [r0]
	lsls r1, r0, 1
	adds r1, r0
	lsls r1, 3
	adds r1, r2, r1
	movs r4, 0xE6
	lsls r4, 2
	adds r1, r4
	ldr r0, _0802341C
	ldm r0!, {r2,r3,r6}
	stm r1!, {r2,r3,r6}
	ldm r0!, {r2,r3,r6}
	stm r1!, {r2,r3,r6}
	bl sub_8004914
	ldr r0, [r5]
	adds r0, r4
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	ldr r0, [r5]
	bl MemoryFree
	movs r0, 0
	str r0, [r5]
_08023400:
	pop {r4-r6}
	pop {r0}
	bx r0
	.align 2, 0
_08023408: .4byte gUnknown_3001B5C
_0802340C: .4byte gUnknown_203B298
_08023410: .4byte gUnknown_203B29C
_08023414: .4byte gUnknown_203B29E
_08023418: .4byte 0x0000037a
_0802341C: .4byte gUnknown_80DC904
	thumb_func_end sub_80233A0

	thumb_func_start sub_8023420
sub_8023420:
	push {r4,r5,lr}
	ldr r4, _080234A8
	ldr r0, [r4]
	movs r1, 0xFE
	lsls r1, 2
	adds r0, r1
	movs r2, 0
	movs r1, 0x1
	strb r1, [r0]
	ldr r0, [r4]
	ldr r1, _080234AC
	adds r0, r1
	strb r2, [r0]
	ldr r0, [r4]
	adds r1, 0x1
	adds r0, r1
	movs r1, 0xC
	strb r1, [r0]
	ldr r0, [r4]
	ldr r1, _080234B0
	adds r0, r1
	strb r2, [r0]
	ldr r0, [r4]
	ldr r2, _080234B4
	adds r0, r2
	movs r1, 0
	ldrsh r0, [r0, r1]
	movs r1, 0xC
	bl sub_80095E4
	adds r0, 0x2
	ldr r3, [r4]
	movs r2, 0xE4
	lsls r2, 2
	adds r5, r3, r2
	ldr r2, [r5]
	lsls r1, r2, 1
	adds r1, r2
	lsls r1, 3
	adds r1, r3, r1
	ldr r2, _080234B8
	adds r1, r2
	lsls r0, 16
	lsrs r0, 16
	strh r0, [r1]
	ldr r2, [r5]
	lsls r1, r2, 1
	adds r1, r2
	lsls r1, 3
	adds r3, r1
	movs r1, 0xEA
	lsls r1, 2
	adds r3, r1
	strh r0, [r3]
	bl sub_8004914
	ldr r0, [r4]
	movs r2, 0xE6
	lsls r2, 2
	adds r0, r2
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_080234A8: .4byte gUnknown_3001B5C
_080234AC: .4byte 0x000003f9
_080234B0: .4byte 0x000003fb
_080234B4: .4byte 0x00000376
_080234B8: .4byte 0x000003a6
	thumb_func_end sub_8023420

	thumb_func_start sub_80234BC
sub_80234BC:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x178
	ldr r5, _0802368C
	ldr r0, [r5]
	movs r4, 0xE4
	lsls r4, 2
	adds r0, r4
	ldr r0, [r0]
	bl sub_8008C54
	ldr r0, [r5]
	adds r0, r4
	ldr r0, [r0]
	bl sub_80073B8
	ldr r2, _08023690
	ldr r0, [r5]
	adds r0, r4
	ldr r3, [r0]
	movs r0, 0
	str r0, [sp]
	movs r0, 0xA
	movs r1, 0
	bl xxx_call_draw_string
	ldr r3, [r5]
	ldr r1, _08023694
	adds r0, r3, r1
	ldrb r0, [r0]
	lsls r0, 3
	adds r0, 0x4
	ldr r2, _08023698
	adds r1, r3, r2
	movs r6, 0
	ldrsh r2, [r1, r6]
	adds r2, 0x1
	movs r1, 0x7
	str r1, [sp]
	adds r3, r4
	ldr r1, [r3]
	str r1, [sp, 0x4]
	movs r1, 0
	movs r3, 0x2
	bl sub_8012BC4
	movs r0, 0
	mov r10, r0
	ldr r0, [r5]
	ldr r1, _0802369C
	adds r0, r1
	movs r2, 0
	ldrsh r0, [r0, r2]
	cmp r10, r0
	blt _08023532
	b _0802366C
_08023532:
	ldr r3, _0802368C
	ldr r0, [r3]
	movs r6, 0xD7
	lsls r6, 2
	adds r0, r6
	mov r1, r10
	bl sub_8013800
	mov r8, r0
	ldr r0, _0802368C
	ldr r1, [r0]
	ldr r2, _08023698
	adds r0, r1, r2
	movs r3, 0
	ldrsh r2, [r0, r3]
	adds r6, 0x1C
	adds r0, r1, r6
	movs r3, 0
	ldrsh r0, [r0, r3]
	muls r0, r2
	add r0, r10
	lsls r0, 1
	adds r1, 0xC
	adds r1, r0
	movs r6, 0
	ldrsh r5, [r1, r6]
	adds r0, r5, 0
	bl GetFriendArea
	lsls r0, 24
	lsrs r0, 24
	add r4, sp, 0x16C
	adds r1, r4, 0
	movs r2, 0
	movs r3, 0
	bl sub_8092638
	movs r7, 0x7
	ldrb r0, [r4, 0x4]
	cmp r0, 0
	beq _08023594
	adds r0, r5, 0
	bl sub_808E734
	lsls r0, 24
	movs r7, 0x4
	cmp r0, 0
	beq _08023594
	movs r7, 0x5
_08023594:
	adds r0, r5, 0
	movs r1, 0
	bl sub_808DCA0
	lsls r0, 16
	asrs r4, r0, 16
	adds r0, r4, 0
	movs r1, 0xA
	bl __modsi3
	adds r2, r0, 0
	adds r2, 0x30
	lsls r2, 24
	lsrs r2, 24
	ldr r6, _0802368C
	ldr r0, [r6]
	movs r1, 0xE4
	lsls r1, 2
	mov r9, r1
	add r0, r9
	ldr r0, [r0]
	str r0, [sp]
	movs r0, 0x14
	mov r1, r8
	adds r3, r7, 0
	bl sub_8012C60
	cmp r4, 0x9
	ble _08023628
	adds r0, r4, 0
	movs r1, 0xA
	bl __divsi3
	adds r4, r0, 0
	movs r1, 0xA
	bl __modsi3
	adds r2, r0, 0
	adds r2, 0x30
	lsls r2, 24
	lsrs r2, 24
	ldr r0, [r6]
	movs r3, 0xE4
	lsls r3, 2
	adds r0, r3
	ldr r0, [r0]
	str r0, [sp]
	movs r0, 0xD
	mov r1, r8
	adds r3, r7, 0
	bl sub_8012C60
	cmp r4, 0x9
	ble _08023628
	adds r0, r4, 0
	movs r1, 0xA
	bl __divsi3
	movs r1, 0xA
	bl __modsi3
	adds r2, r0, 0
	adds r2, 0x30
	lsls r2, 24
	lsrs r2, 24
	ldr r0, [r6]
	add r0, r9
	ldr r0, [r0]
	str r0, [sp]
	movs r0, 0x6
	mov r1, r8
	adds r3, r7, 0
	bl sub_8012C60
_08023628:
	add r4, sp, 0x108
	adds r0, r4, 0
	adds r1, r5, 0
	bl sub_808D930
	add r0, sp, 0x8
	ldr r1, _080236A0
	adds r2, r7, 0
	adds r3, r4, 0
	bl sub_800D158
	ldr r6, _0802368C
	ldr r0, [r6]
	movs r1, 0xE4
	lsls r1, 2
	adds r0, r1
	ldr r3, [r0]
	movs r0, 0
	str r0, [sp]
	movs r0, 0x24
	mov r1, r8
	add r2, sp, 0x8
	bl xxx_call_draw_string
	movs r2, 0x1
	add r10, r2
	ldr r0, [r6]
	ldr r3, _0802369C
	adds r0, r3
	movs r6, 0
	ldrsh r0, [r0, r6]
	cmp r10, r0
	bge _0802366C
	b _08023532
_0802366C:
	ldr r0, _0802368C
	ldr r0, [r0]
	movs r1, 0xE4
	lsls r1, 2
	adds r0, r1
	ldr r0, [r0]
	bl sub_80073E0
	add sp, 0x178
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_0802368C: .4byte gUnknown_3001B5C
_08023690: .4byte gUnknown_80DC934
_08023694: .4byte 0x000003fa
_08023698: .4byte 0x0000037a
_0802369C: .4byte 0x00000376
_080236A0: .4byte gUnknown_80DC93C
	thumb_func_end sub_80234BC

	thumb_func_start sub_80236A4
sub_80236A4:
	push {r4,r5,lr}
	ldr r0, _080236FC
	ldr r1, [r0]
	movs r0, 0
	str r0, [r1, 0x8]
	movs r5, 0
_080236B0:
	lsls r0, r5, 16
	asrs r4, r0, 16
	adds r0, r4, 0
	bl sub_8098134
	lsls r0, 24
	cmp r0, 0
	beq _080236E2
	adds r0, r4, 0
	bl sub_808E858
	lsls r0, 16
	asrs r0, 16
	cmp r4, r0
	bne _080236E2
	ldr r0, _080236FC
	ldr r3, [r0]
	ldr r1, [r3, 0x8]
	lsls r2, r1, 1
	adds r0, r3, 0
	adds r0, 0xC
	adds r0, r2
	strh r5, [r0]
	adds r1, 0x1
	str r1, [r3, 0x8]
_080236E2:
	adds r5, 0x1
	ldr r0, _08023700
	cmp r5, r0
	ble _080236B0
	bl sub_8023730
	ldr r0, _080236FC
	ldr r0, [r0]
	ldr r0, [r0, 0x8]
	pop {r4,r5}
	pop {r1}
	bx r1
	.align 2, 0
_080236FC: .4byte gUnknown_3001B5C
_08023700: .4byte 0x000001a7
	thumb_func_end sub_80236A4

	thumb_func_start sub_8023704
sub_8023704:
	push {r4,lr}
	movs r4, 0
_08023708:
	lsls r0, r4, 16
	asrs r0, 16
	bl sub_8098134
	lsls r0, 24
	cmp r0, 0
	beq _0802371A
	movs r0, 0
	b _08023724
_0802371A:
	adds r4, 0x1
	ldr r0, _0802372C
	cmp r4, r0
	ble _08023708
	movs r0, 0x1
_08023724:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_0802372C: .4byte 0x000001a7
	thumb_func_end sub_8023704

	thumb_func_start sub_8023730
sub_8023730:
	push {lr}
	ldr r0, _08023744
	ldr r0, [r0]
	ldr r0, [r0, 0x4]
	cmp r0, 0x1
	beq _08023748
	cmp r0, 0x2
	beq _0802374E
	b _08023752
	.align 2, 0
_08023744: .4byte gUnknown_3001B5C
_08023748:
	bl sub_8023758
	b _08023752
_0802374E:
	bl sub_80237E0
_08023752:
	pop {r0}
	bx r0
	thumb_func_end sub_8023730

	thumb_func_start sub_8023758
sub_8023758:
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	sub sp, 0x4
	ldr r3, _080237DC
	ldr r2, [r3]
	ldr r1, [r2, 0x8]
	lsls r0, r1, 1
	adds r0, 0xA
	adds r2, r0
	mov r9, r2
	movs r2, 0
	subs r1, 0x1
	cmp r2, r1
	bge _080237CC
_08023778:
	mov r5, r9
	ldr r0, [r3]
	ldr r0, [r0, 0x8]
	subs r7, r0, 0x1
	adds r0, r2, 0x1
	mov r8, r0
	cmp r7, r2
	ble _080237BE
_08023788:
	subs r6, r5, 0x2
	movs r1, 0
	ldrsh r0, [r6, r1]
	movs r1, 0x1
	str r2, [sp]
	bl sub_808DCDC
	adds r4, r0, 0
	movs r1, 0
	ldrsh r0, [r5, r1]
	movs r1, 0x1
	bl sub_808DCDC
	lsls r4, 16
	lsls r0, 16
	ldr r2, [sp]
	cmp r4, r0
	ble _080237B6
	movs r0, 0
	ldrsh r1, [r5, r0]
	ldrh r0, [r6]
	strh r0, [r5]
	strh r1, [r6]
_080237B6:
	adds r5, r6, 0
	subs r7, 0x1
	cmp r7, r2
	bgt _08023788
_080237BE:
	mov r2, r8
	ldr r3, _080237DC
	ldr r0, [r3]
	ldr r0, [r0, 0x8]
	subs r0, 0x1
	cmp r2, r0
	blt _08023778
_080237CC:
	add sp, 0x4
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_080237DC: .4byte gUnknown_3001B5C
	thumb_func_end sub_8023758

	thumb_func_start sub_80237E0
sub_80237E0:
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	sub sp, 0x4
	ldr r3, _08023864
	ldr r2, [r3]
	ldr r1, [r2, 0x8]
	lsls r0, r1, 1
	adds r0, 0xA
	adds r2, r0
	mov r9, r2
	movs r2, 0
	subs r1, 0x1
	cmp r2, r1
	bge _08023854
_08023800:
	mov r5, r9
	ldr r0, [r3]
	ldr r0, [r0, 0x8]
	subs r7, r0, 0x1
	adds r0, r2, 0x1
	mov r8, r0
	cmp r7, r2
	ble _08023846
_08023810:
	subs r6, r5, 0x2
	movs r1, 0
	ldrsh r0, [r6, r1]
	movs r1, 0
	str r2, [sp]
	bl sub_808DCDC
	adds r4, r0, 0
	movs r1, 0
	ldrsh r0, [r5, r1]
	movs r1, 0
	bl sub_808DCDC
	lsls r4, 16
	lsls r0, 16
	ldr r2, [sp]
	cmp r4, r0
	ble _0802383E
	movs r0, 0
	ldrsh r1, [r5, r0]
	ldrh r0, [r6]
	strh r0, [r5]
	strh r1, [r6]
_0802383E:
	adds r5, r6, 0
	subs r7, 0x1
	cmp r7, r2
	bgt _08023810
_08023846:
	mov r2, r8
	ldr r3, _08023864
	ldr r0, [r3]
	ldr r0, [r0, 0x8]
	subs r0, 0x1
	cmp r2, r0
	blt _08023800
_08023854:
	add sp, 0x4
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_08023864: .4byte gUnknown_3001B5C
	thumb_func_end sub_80237E0

	thumb_func_start sub_8023868
sub_8023868:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	adds r5, r0, 0
	mov r8, r1
	mov r9, r2
	mov r10, r3
	bl sub_8024108
	lsls r0, 24
	cmp r0, 0
	beq _08023888
	movs r0, 0
	b _08023A6E
_08023888:
	ldr r4, _080238AC
	ldr r0, [r4]
	cmp r0, 0
	bne _0802389C
	movs r0, 0xFE
	lsls r0, 2
	movs r1, 0x8
	bl MemoryAlloc
	str r0, [r4]
_0802389C:
	ldr r1, [r4]
	str r5, [r1]
	ldr r0, _080238B0
	ldr r0, [r0]
	cmp r0, r5
	beq _080238B4
	movs r0, 0x1
	b _080238B8
	.align 2, 0
_080238AC: .4byte gUnknown_3001B60
_080238B0: .4byte gUnknown_203B2A0
_080238B4:
	ldr r0, _080238E4
	ldr r0, [r0]
_080238B8:
	str r0, [r1, 0x4]
	ldr r2, _080238E8
	ldr r0, [r2]
	movs r1, 0
	strb r1, [r0, 0x14]
	ldr r0, [r2]
	strb r1, [r0, 0x15]
	ldr r0, [r2]
	strb r1, [r0, 0x16]
	ldr r0, [r2]
	strb r1, [r0, 0x17]
	ldr r0, [r2]
	strb r1, [r0, 0x18]
	ldr r0, [r2]
	ldr r0, [r0]
	cmp r0, 0x4
	bhi _08023980
	lsls r0, 2
	ldr r1, _080238EC
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080238E4: .4byte gUnknown_203B2A4
_080238E8: .4byte gUnknown_3001B60
_080238EC: .4byte _080238F0
	.align 2, 0
_080238F0:
	.4byte _08023958
	.4byte _08023904
	.4byte _08023914
	.4byte _08023924
	.4byte _0802393C
_08023904:
	ldr r0, _08023910
	ldr r1, [r0]
	movs r0, 0x1
	strb r0, [r1, 0x18]
	b _08023958
	.align 2, 0
_08023910: .4byte gUnknown_3001B60
_08023914:
	ldr r0, _08023920
	ldr r1, [r0]
	movs r0, 0x1
	strb r0, [r1, 0x14]
	b _08023958
	.align 2, 0
_08023920: .4byte gUnknown_3001B60
_08023924:
	ldr r2, _08023938
	ldr r0, [r2]
	movs r1, 0x1
	strb r1, [r0, 0x17]
	ldr r0, [r2]
	strb r1, [r0, 0x15]
	ldr r0, [r2]
	strb r1, [r0, 0x16]
	b _08023958
	.align 2, 0
_08023938: .4byte gUnknown_3001B60
_0802393C:
	ldr r5, _0802397C
	ldr r0, [r5]
	movs r4, 0x1
	strb r4, [r0, 0x18]
	ldr r0, [r5]
	strb r4, [r0, 0x15]
	movs r0, 0x9
	bl sub_80023E4
	lsls r0, 24
	cmp r0, 0
	bne _08023958
	ldr r0, [r5]
	strb r4, [r0, 0x16]
_08023958:
	ldr r4, _0802397C
	ldr r0, [r4]
	ldr r0, [r0]
	cmp r0, 0x4
	bne _08023980
	bl sub_80A5728
	lsls r0, 16
	asrs r0, 16
	bl sub_8002658
	ldr r1, [r4]
	movs r2, 0xD5
	lsls r2, 2
	adds r1, r2
	strb r0, [r1]
	b _0802398E
	.align 2, 0
_0802397C: .4byte gUnknown_3001B60
_08023980:
	ldr r0, _08023A7C
	ldr r0, [r0]
	movs r3, 0xD5
	lsls r3, 2
	adds r0, r3
	movs r1, 0
	strb r1, [r0]
_0802398E:
	ldr r5, _08023A7C
	ldr r0, [r5]
	movs r4, 0xE3
	lsls r4, 2
	adds r1, r0, r4
	mov r2, r8
	str r2, [r1]
	movs r7, 0xE4
	lsls r7, 2
	adds r2, r0, r7
	mov r3, r8
	lsls r1, r3, 1
	add r1, r8
	lsls r1, 3
	movs r6, 0xE5
	lsls r6, 2
	adds r1, r6
	adds r1, r0, r1
	str r1, [r2]
	adds r0, r6
	bl sub_8006518
	ldr r1, [r5]
	adds r4, r1, r4
	ldr r2, [r4]
	lsls r0, r2, 1
	adds r0, r2
	lsls r0, 3
	adds r1, r0
	adds r1, r6
	ldr r0, _08023A80
	ldm r0!, {r2-r4}
	stm r1!, {r2-r4}
	ldm r0!, {r2-r4}
	stm r1!, {r2-r4}
	ldr r2, [r5]
	adds r0, r2, r7
	ldr r1, [r0]
	movs r4, 0xFD
	lsls r4, 2
	adds r0, r2, r4
	str r0, [r1, 0x14]
	mov r0, r9
	cmp r0, 0
	beq _08023A04
	movs r1, 0xE3
	lsls r1, 2
	adds r0, r2, r1
	ldr r1, [r0]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 3
	movs r3, 0xE7
	lsls r3, 2
	adds r1, r2, r3
	adds r1, r0
	mov r4, r9
	ldr r0, [r4]
	str r0, [r1]
_08023A04:
	ldr r0, [r5]
	adds r0, r7
	ldr r0, [r0]
	mov r1, r10
	bl sub_8012D08
	bl sub_8004914
	ldr r0, [r5]
	adds r0, r6
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	ldr r4, [r5]
	movs r0, 0xD6
	lsls r0, 2
	adds r4, r0
	bl sub_8023F8C
	adds r1, r0, 0
	adds r0, r4, 0
	mov r2, r10
	mov r3, r8
	bl sub_8013818
	ldr r0, _08023A84
	ldr r4, [r5]
	ldr r1, [r0]
	ldr r0, [r4]
	cmp r1, r0
	bne _08023A64
	ldr r0, _08023A88
	ldrh r1, [r0]
	movs r2, 0xDC
	lsls r2, 2
	adds r0, r4, r2
	strh r1, [r0]
	ldr r0, _08023A8C
	ldrh r1, [r0]
	ldr r3, _08023A90
	adds r0, r4, r3
	strh r1, [r0]
	movs r1, 0xD6
	lsls r1, 2
	adds r0, r4, r1
	bl sub_8013984
_08023A64:
	bl sub_8023CF4
	bl sub_8023DA4
	movs r0, 0x1
_08023A6E:
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	.align 2, 0
_08023A7C: .4byte gUnknown_3001B60
_08023A80: .4byte gUnknown_80DC968
_08023A84: .4byte gUnknown_203B2A0
_08023A88: .4byte gUnknown_203B2A8
_08023A8C: .4byte gUnknown_203B2AA
_08023A90: .4byte 0x00000376
	thumb_func_end sub_8023868

	thumb_func_start sub_8023A94
sub_8023A94:
	push {r4,lr}
	lsls r0, 24
	cmp r0, 0
	bne _08023AB4
	ldr r0, _08023AB0
	ldr r0, [r0]
	movs r1, 0xD6
	lsls r1, 2
	adds r0, r1
	bl sub_8013660
	movs r0, 0
	b _08023B3E
	.align 2, 0
_08023AB0: .4byte gUnknown_3001B60
_08023AB4:
	ldr r4, _08023AD0
	ldr r0, [r4]
	movs r1, 0xD6
	lsls r1, 2
	adds r0, r1
	bl GetKeyPress
	cmp r0, 0x2
	beq _08023ADE
	cmp r0, 0x2
	bgt _08023AD4
	cmp r0, 0x1
	beq _08023AF2
	b _08023B16
	.align 2, 0
_08023AD0: .4byte gUnknown_3001B60
_08023AD4:
	cmp r0, 0x3
	beq _08023AFC
	cmp r0, 0x4
	beq _08023AE8
	b _08023B16
_08023ADE:
	movs r0, 0x1
	bl sub_80119D4
	movs r0, 0x2
	b _08023B3E
_08023AE8:
	movs r0, 0x4
	bl sub_80119D4
	movs r0, 0x4
	b _08023B3E
_08023AF2:
	movs r0, 0
	bl sub_80119D4
	movs r0, 0x3
	b _08023B3E
_08023AFC:
	movs r0, 0x5
	bl sub_80119D4
	ldr r0, [r4]
	ldr r1, [r0, 0x4]
	movs r2, 0x1
	cmp r1, 0x2
	bhi _08023B0E
	adds r2, r1, 0x1
_08023B0E:
	str r2, [r0, 0x4]
	bl sub_8023F8C
	b _08023B34
_08023B16:
	ldr r0, _08023B30
	ldr r0, [r0]
	movs r1, 0xD6
	lsls r1, 2
	adds r0, r1
	movs r1, 0x1
	bl sub_80138B8
	lsls r0, 24
	cmp r0, 0
	bne _08023B34
	movs r0, 0
	b _08023B3E
	.align 2, 0
_08023B30: .4byte gUnknown_3001B60
_08023B34:
	bl sub_8023CF4
	bl sub_8023DA4
	movs r0, 0x1
_08023B3E:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_8023A94

	thumb_func_start sub_8023B44
sub_8023B44:
	ldr r0, _08023B74
	ldr r0, [r0]
	ldr r2, _08023B78
	adds r1, r0, r2
	movs r3, 0
	ldrsh r2, [r1, r3]
	movs r3, 0xDD
	lsls r3, 2
	adds r1, r0, r3
	movs r3, 0
	ldrsh r1, [r1, r3]
	muls r1, r2
	movs r3, 0xDC
	lsls r3, 2
	adds r2, r0, r3
	movs r3, 0
	ldrsh r2, [r2, r3]
	adds r1, r2
	lsls r1, 1
	adds r0, 0x1A
	adds r0, r1
	movs r1, 0
	ldrsh r0, [r0, r1]
	bx lr
	.align 2, 0
_08023B74: .4byte gUnknown_3001B60
_08023B78: .4byte 0x00000376
	thumb_func_end sub_8023B44

	thumb_func_start sub_8023B7C
sub_8023B7C:
	push {r4,r5,lr}
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	bl sub_8004914
	ldr r5, _08023BD0
	ldr r0, [r5]
	movs r1, 0xE5
	lsls r1, 2
	adds r0, r1
	movs r1, 0
	movs r2, 0
	bl sub_800641C
	bl sub_8023BD8
	adds r2, r0, 0
	ldr r0, [r5]
	ldr r3, _08023BD4
	adds r1, r0, r3
	strh r2, [r1]
	movs r1, 0xD6
	lsls r1, 2
	adds r0, r1
	bl sub_8013984
	bl sub_8023CF4
	bl sub_8023DA4
	cmp r4, 0
	beq _08023BCA
	ldr r0, [r5]
	movs r3, 0xD6
	lsls r3, 2
	adds r0, r3
	bl AddMenuCursorSprite
_08023BCA:
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_08023BD0: .4byte gUnknown_3001B60
_08023BD4: .4byte 0x0000037a
	thumb_func_end sub_8023B7C

	thumb_func_start sub_8023BD8
sub_8023BD8:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	movs r3, 0
	ldr r1, _08023C58
	ldr r0, [r1]
	ldr r0, [r0, 0x8]
	adds r7, r1, 0
	cmp r3, r0
	bge _08023C4A
	ldr r0, _08023C5C
	mov r8, r0
	mov r12, r7
_08023BF2:
	ldr r2, [r1]
	lsls r4, r3, 1
	adds r0, r2, 0
	adds r0, 0x1A
	adds r0, r4
	movs r5, 0
	ldrsh r1, [r0, r5]
	movs r0, 0x58
	muls r0, r1
	mov r5, r8
	ldr r1, [r5]
	adds r0, r1
	ldrb r1, [r0]
	movs r0, 0x1
	ands r0, r1
	adds r6, r3, 0x1
	cmp r0, 0
	bne _08023C3E
	ldr r0, [r2, 0x8]
	subs r0, 0x1
	str r0, [r2, 0x8]
	cmp r3, r0
	bge _08023C3E
	mov r5, r12
	adds r4, 0x2
_08023C24:
	ldr r2, [r5]
	lsls r1, r3, 1
	adds r0, r2, 0
	adds r0, 0x1A
	adds r1, r0, r1
	adds r0, r4
	ldrh r0, [r0]
	strh r0, [r1]
	adds r4, 0x2
	adds r3, 0x1
	ldr r0, [r2, 0x8]
	cmp r3, r0
	blt _08023C24
_08023C3E:
	adds r3, r6, 0
	adds r1, r7, 0
	ldr r0, [r7]
	ldr r0, [r0, 0x8]
	cmp r3, r0
	blt _08023BF2
_08023C4A:
	ldr r0, [r7]
	ldr r0, [r0, 0x8]
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r1}
	bx r1
	.align 2, 0
_08023C58: .4byte gUnknown_3001B60
_08023C5C: .4byte gUnknown_203B45C
	thumb_func_end sub_8023BD8

	thumb_func_start sub_8023C60
sub_8023C60:
	push {r4-r6,lr}
	ldr r5, _08023CCC
	ldr r2, [r5]
	cmp r2, 0
	beq _08023CC6
	ldr r1, _08023CD0
	ldr r0, [r2]
	str r0, [r1]
	ldr r1, _08023CD4
	ldr r0, [r2, 0x4]
	str r0, [r1]
	ldr r1, _08023CD8
	movs r3, 0xDC
	lsls r3, 2
	adds r0, r2, r3
	ldrh r0, [r0]
	strh r0, [r1]
	ldr r1, _08023CDC
	ldr r6, _08023CE0
	adds r0, r2, r6
	ldrh r0, [r0]
	strh r0, [r1]
	movs r1, 0xE3
	lsls r1, 2
	adds r0, r2, r1
	ldr r0, [r0]
	lsls r1, r0, 1
	adds r1, r0
	lsls r1, 3
	adds r1, r2, r1
	movs r4, 0xE5
	lsls r4, 2
	adds r1, r4
	ldr r0, _08023CE4
	ldm r0!, {r2,r3,r6}
	stm r1!, {r2,r3,r6}
	ldm r0!, {r2,r3,r6}
	stm r1!, {r2,r3,r6}
	bl sub_8004914
	ldr r0, [r5]
	adds r0, r4
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	ldr r0, [r5]
	bl MemoryFree
	movs r0, 0
	str r0, [r5]
_08023CC6:
	pop {r4-r6}
	pop {r0}
	bx r0
	.align 2, 0
_08023CCC: .4byte gUnknown_3001B60
_08023CD0: .4byte gUnknown_203B2A0
_08023CD4: .4byte gUnknown_203B2A4
_08023CD8: .4byte gUnknown_203B2A8
_08023CDC: .4byte gUnknown_203B2AA
_08023CE0: .4byte 0x00000376
_08023CE4: .4byte gUnknown_80DC950
	thumb_func_end sub_8023C60

	thumb_func_start sub_8023CE8
sub_8023CE8:
	ldr r0, _08023CF0
	ldr r0, [r0]
	bx lr
	.align 2, 0
_08023CF0: .4byte gUnknown_3001B60
	thumb_func_end sub_8023CE8

	thumb_func_start sub_8023CF4
sub_8023CF4:
	push {r4,r5,lr}
	ldr r2, _08023D28
	ldr r0, [r2]
	movs r1, 0xFD
	lsls r1, 2
	adds r0, r1
	movs r3, 0
	movs r1, 0x1
	strb r1, [r0]
	ldr r0, [r2]
	ldr r1, _08023D2C
	adds r0, r1
	strb r3, [r0]
	ldr r0, [r2]
	adds r1, 0x2
	adds r0, r1
	strb r3, [r0]
	ldr r1, [r2]
	ldr r0, [r1]
	adds r5, r2, 0
	cmp r0, 0x2
	bne _08023D34
	ldr r0, _08023D30
	adds r1, r0
	b _08023D38
	.align 2, 0
_08023D28: .4byte gUnknown_3001B60
_08023D2C: .4byte 0x000003f5
_08023D30: .4byte 0x000003f6
_08023D34:
	ldr r2, _08023D98
	adds r1, r2
_08023D38:
	movs r0, 0xC
	strb r0, [r1]
	ldr r0, [r5]
	ldr r1, _08023D9C
	adds r0, r1
	movs r2, 0
	ldrsh r0, [r0, r2]
	movs r1, 0xC
	bl sub_80095E4
	adds r0, 0x2
	ldr r3, [r5]
	movs r1, 0xE3
	lsls r1, 2
	adds r4, r3, r1
	ldr r2, [r4]
	lsls r1, r2, 1
	adds r1, r2
	lsls r1, 3
	adds r1, r3, r1
	ldr r2, _08023DA0
	adds r1, r2
	lsls r0, 16
	lsrs r0, 16
	strh r0, [r1]
	ldr r2, [r4]
	lsls r1, r2, 1
	adds r1, r2
	lsls r1, 3
	adds r3, r1
	movs r1, 0xE9
	lsls r1, 2
	adds r3, r1
	strh r0, [r3]
	bl sub_8004914
	ldr r0, [r5]
	movs r2, 0xE5
	lsls r2, 2
	adds r0, r2
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_08023D98: .4byte 0x000003f6
_08023D9C: .4byte 0x00000372
_08023DA0: .4byte 0x000003a2
	thumb_func_end sub_8023CF4

	thumb_func_start sub_8023DA4
sub_8023DA4:
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	sub sp, 0x58
	ldr r4, _08023DD8
	ldr r0, [r4]
	movs r5, 0xE3
	lsls r5, 2
	adds r0, r5
	ldr r0, [r0]
	bl sub_8008C54
	ldr r0, [r4]
	adds r0, r5
	ldr r0, [r0]
	bl sub_80073B8
	ldr r0, [r4]
	ldr r1, [r0]
	cmp r1, 0x2
	beq _08023DE0
	cmp r1, 0x4
	beq _08023E00
	ldr r2, _08023DDC
	b _08023E02
	.align 2, 0
_08023DD8: .4byte gUnknown_3001B60
_08023DDC: .4byte gUnknown_80DC988
_08023DE0:
	add r0, sp, 0x8
	bl sub_80920D8
	ldr r0, [r4]
	movs r1, 0xE3
	lsls r1, 2
	adds r0, r1
	ldr r3, [r0]
	movs r0, 0
	str r0, [sp]
	movs r0, 0xA
	movs r1, 0
	add r2, sp, 0x8
	bl xxx_call_draw_string
	b _08023E3C
_08023E00:
	ldr r2, _08023EBC
_08023E02:
	adds r0, r5
	ldr r3, [r0]
	movs r0, 0
	str r0, [sp]
	movs r0, 0xA
	movs r1, 0
	bl xxx_call_draw_string
	ldr r1, [r4]
	ldr r2, _08023EC0
	adds r0, r1, r2
	ldrb r0, [r0]
	lsls r0, 3
	adds r3, r0, 0x4
	ldr r4, _08023EC4
	adds r0, r1, r4
	movs r4, 0
	ldrsh r2, [r0, r4]
	adds r2, 0x1
	movs r0, 0x7
	str r0, [sp]
	adds r1, r5
	ldr r0, [r1]
	str r0, [sp, 0x4]
	adds r0, r3, 0
	movs r1, 0
	movs r3, 0x2
	bl sub_8012BC4
_08023E3C:
	movs r7, 0
	ldr r1, _08023EC8
	ldr r0, [r1]
	ldr r2, _08023ECC
	adds r0, r2
	movs r4, 0
	ldrsh r0, [r0, r4]
	cmp r7, r0
	blt _08023E50
	b _08023F62
_08023E50:
	mov r8, r1
	add r0, sp, 0x30
	mov r9, r0
_08023E56:
	ldr r3, [r1]
	ldr r1, _08023EC4
	adds r0, r3, r1
	movs r2, 0
	ldrsh r1, [r0, r2]
	movs r4, 0xDD
	lsls r4, 2
	adds r0, r3, r4
	movs r2, 0
	ldrsh r0, [r0, r2]
	muls r1, r0
	adds r1, r7
	lsls r1, 1
	adds r0, r3, 0
	adds r0, 0x1A
	adds r0, r1
	movs r4, 0
	ldrsh r5, [r0, r4]
	ldr r2, _08023ED0
	movs r0, 0x58
	adds r1, r5, 0
	muls r1, r0
	ldr r0, [r2]
	adds r4, r0, r1
	movs r6, 0x7
	ldrh r0, [r4]
	lsrs r0, 1
	movs r1, 0x1
	ands r0, r1
	cmp r0, 0
	beq _08023ED4
	movs r0, 0
	ldrb r1, [r4, 0x4]
	cmp r1, 0x41
	bne _08023E9E
	movs r0, 0x1
_08023E9E:
	cmp r0, 0
	beq _08023EA4
	movs r6, 0x6
_08023EA4:
	movs r0, 0
	cmp r1, 0x40
	bne _08023EAC
	movs r0, 0x1
_08023EAC:
	cmp r0, 0
	beq _08023EB2
	movs r6, 0x6
_08023EB2:
	ldrb r0, [r4, 0x2]
	cmp r0, 0
	beq _08023EEA
	movs r6, 0x5
	b _08023EEA
	.align 2, 0
_08023EBC: .4byte gUnknown_80DC980
_08023EC0: .4byte 0x000003f6
_08023EC4: .4byte 0x00000376
_08023EC8: .4byte gUnknown_3001B60
_08023ECC: .4byte 0x00000372
_08023ED0: .4byte gUnknown_203B45C
_08023ED4:
	ldrb r0, [r3, 0x18]
	cmp r0, 0
	beq _08023EEA
	adds r0, r5, 0
	bl sub_808D750
	lsls r0, 24
	movs r6, 0x2
	cmp r0, 0
	beq _08023EEA
	movs r6, 0x4
_08023EEA:
	mov r0, r8
	ldr r1, [r0]
	ldr r0, [r1]
	cmp r0, 0x4
	bne _08023F02
	movs r2, 0xD5
	lsls r2, 2
	adds r0, r1, r2
	ldrb r1, [r0]
	adds r0, r4, 0
	bl sub_8024184
_08023F02:
	adds r1, r4, 0
	adds r1, 0x4C
	mov r0, r9
	movs r2, 0xA
	bl sub_80922B4
	movs r0, 0x8
	ldrsh r1, [r4, r0]
	add r0, sp, 0x44
	bl sub_808D930
	add r0, sp, 0x8
	ldr r1, _08023F80
	adds r2, r6, 0
	mov r3, r9
	bl sub_800D158
	mov r1, r8
	ldr r0, [r1]
	movs r2, 0xD6
	lsls r2, 2
	adds r0, r2
	adds r1, r7, 0
	bl sub_8013800
	adds r1, r0, 0
	mov r4, r8
	ldr r0, [r4]
	movs r2, 0xE3
	lsls r2, 2
	adds r0, r2
	ldr r3, [r0]
	movs r0, 0
	str r0, [sp]
	movs r0, 0x8
	add r2, sp, 0x8
	bl xxx_call_draw_string
	adds r7, 0x1
	mov r1, r8
	ldr r0, [r4]
	ldr r4, _08023F84
	adds r0, r4
	movs r2, 0
	ldrsh r0, [r0, r2]
	cmp r7, r0
	bge _08023F62
	b _08023E56
_08023F62:
	ldr r0, _08023F88
	ldr r0, [r0]
	movs r4, 0xE3
	lsls r4, 2
	adds r0, r4
	ldr r0, [r0]
	bl sub_80073E0
	add sp, 0x58
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_08023F80: .4byte gUnknown_80DC998
_08023F84: .4byte 0x00000372
_08023F88: .4byte gUnknown_3001B60
	thumb_func_end sub_8023DA4

	thumb_func_start sub_8023F8C
sub_8023F8C:
	push {r4-r7,lr}
	ldr r2, _08023FD0
	ldr r1, [r2]
	movs r0, 0
	str r0, [r1, 0x8]
	ldrb r0, [r1, 0x15]
	adds r6, r2, 0
	cmp r0, 0
	bne _08023FE2
	movs r4, 0
	ldr r2, _08023FD4
_08023FA2:
	movs r0, 0x58
	adds r1, r4, 0
	muls r1, r0
	ldr r0, [r2]
	adds r1, r0, r1
	ldrb r0, [r1, 0x2]
	cmp r0, 0
	beq _08023FD8
	ldrb r1, [r1]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _08023FD8
	ldr r3, [r6]
	ldr r1, [r3, 0x8]
	lsls r2, r1, 1
	adds r0, r3, 0
	adds r0, 0x1A
	adds r0, r2
	strh r4, [r0]
	adds r1, 0x1
	str r1, [r3, 0x8]
	b _08023FE2
	.align 2, 0
_08023FD0: .4byte gUnknown_3001B60
_08023FD4: .4byte gUnknown_203B45C
_08023FD8:
	adds r4, 0x1
	movs r0, 0xCE
	lsls r0, 1
	cmp r4, r0
	ble _08023FA2
_08023FE2:
	ldr r0, [r6]
	ldrb r0, [r0, 0x16]
	cmp r0, 0
	bne _08024042
	movs r4, 0
	ldr r3, _08024034
_08023FEE:
	movs r0, 0x58
	adds r1, r4, 0
	muls r1, r0
	ldr r0, [r3]
	adds r1, r0, r1
	movs r2, 0
	ldrb r0, [r1, 0x4]
	cmp r0, 0x41
	bne _08024002
	movs r2, 0x1
_08024002:
	cmp r2, 0
	beq _08024038
	ldrb r0, [r1, 0x2]
	cmp r0, 0
	bne _08024038
	ldrh r1, [r1]
	lsrs r0, r1, 1
	movs r2, 0x1
	ands r0, r2
	cmp r0, 0
	beq _08024038
	adds r0, r2, 0
	ands r0, r1
	cmp r0, 0
	beq _08024038
	ldr r3, [r6]
	ldr r1, [r3, 0x8]
	lsls r2, r1, 1
	adds r0, r3, 0
	adds r0, 0x1A
	adds r0, r2
	strh r4, [r0]
	adds r1, 0x1
	str r1, [r3, 0x8]
	b _08024042
	.align 2, 0
_08024034: .4byte gUnknown_203B45C
_08024038:
	adds r4, 0x1
	movs r0, 0xCE
	lsls r0, 1
	cmp r4, r0
	ble _08023FEE
_08024042:
	ldr r0, [r6]
	ldr r1, [r0, 0x8]
	str r1, [r0, 0xC]
	ldrb r0, [r0, 0x17]
	cmp r0, 0
	bne _080240A4
	movs r4, 0
	ldr r7, _08024100
	movs r5, 0x1
_08024054:
	movs r0, 0x58
	adds r1, r4, 0
	muls r1, r0
	ldr r0, [r7]
	adds r1, r0, r1
	ldrh r2, [r1]
	lsrs r0, r2, 1
	ands r0, r5
	cmp r0, 0
	beq _0802409A
	adds r0, r5, 0
	ands r0, r2
	cmp r0, 0
	beq _0802409A
	ldrb r0, [r1, 0x2]
	cmp r0, 0
	bne _0802409A
	movs r2, 0
	ldrb r0, [r1, 0x4]
	cmp r0, 0x41
	bne _08024080
	movs r2, 0x1
_08024080:
	cmp r2, 0
	bne _0802409A
	ldr r3, [r6]
	ldr r1, [r3, 0x8]
	lsls r2, r1, 1
	adds r0, r3, 0
	adds r0, 0x1A
	adds r0, r2
	strh r4, [r0]
	adds r1, 0x1
	str r1, [r3, 0x8]
	cmp r1, 0x3
	bgt _080240A4
_0802409A:
	adds r4, 0x1
	movs r0, 0xCE
	lsls r0, 1
	cmp r4, r0
	ble _08024054
_080240A4:
	ldr r0, [r6]
	ldr r1, [r0, 0x8]
	str r1, [r0, 0x10]
	ldrb r0, [r0, 0x14]
	cmp r0, 0
	bne _080240EE
	movs r4, 0
	ldr r7, _08024100
	movs r5, 0x1
_080240B6:
	movs r0, 0x58
	adds r1, r4, 0
	muls r1, r0
	ldr r0, [r7]
	adds r1, r0, r1
	ldrh r1, [r1]
	adds r0, r5, 0
	ands r0, r1
	cmp r0, 0
	beq _080240E4
	lsrs r0, r1, 1
	ands r0, r5
	cmp r0, 0
	bne _080240E4
	ldr r3, [r6]
	ldr r1, [r3, 0x8]
	lsls r2, r1, 1
	adds r0, r3, 0
	adds r0, 0x1A
	adds r0, r2
	strh r4, [r0]
	adds r1, 0x1
	str r1, [r3, 0x8]
_080240E4:
	adds r4, 0x1
	movs r0, 0xCE
	lsls r0, 1
	cmp r4, r0
	ble _080240B6
_080240EE:
	bl sub_80241A8
	ldr r0, _08024104
	ldr r0, [r0]
	ldr r0, [r0, 0x8]
	pop {r4-r7}
	pop {r1}
	bx r1
	.align 2, 0
_08024100: .4byte gUnknown_203B45C
_08024104: .4byte gUnknown_3001B60
	thumb_func_end sub_8023F8C

	thumb_func_start sub_8024108
sub_8024108:
	push {r4-r7,lr}
	adds r5, r0, 0
	movs r7, 0
	movs r6, 0x1
_08024110:
	ldr r2, _08024134
	movs r0, 0x58
	adds r1, r7, 0
	muls r1, r0
	ldr r0, [r2]
	adds r4, r0, r1
	ldrh r1, [r4]
	adds r0, r6, 0
	ands r0, r1
	cmp r0, 0
	beq _08024172
	cmp r5, 0x2
	bne _08024138
	lsrs r0, r1, 1
	ands r0, r6
	cmp r0, 0
	beq _08024172
	b _0802416E
	.align 2, 0
_08024134: .4byte gUnknown_203B45C
_08024138:
	cmp r5, 0x3
	bne _08024140
	lsrs r0, r1, 1
	b _08024168
_08024140:
	cmp r5, 0x4
	bne _0802416E
	ldrb r0, [r4, 0x2]
	cmp r0, 0
	bne _08024172
	movs r0, 0x9
	bl sub_80023E4
	lsls r0, 24
	cmp r0, 0
	bne _0802416E
	movs r1, 0
	ldrb r0, [r4, 0x4]
	cmp r0, 0x41
	bne _08024160
	movs r1, 0x1
_08024160:
	cmp r1, 0
	beq _0802416E
	ldrh r0, [r4]
	lsrs r0, 1
_08024168:
	ands r0, r6
	cmp r0, 0
	bne _08024172
_0802416E:
	movs r0, 0
	b _0802417E
_08024172:
	adds r7, 0x1
	movs r0, 0xCE
	lsls r0, 1
	cmp r7, r0
	ble _08024110
	movs r0, 0x1
_0802417E:
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_8024108

	thumb_func_start sub_8024184
sub_8024184:
	push {r4,lr}
	lsls r4, r1, 24
	lsrs r4, 24
	movs r1, 0x8
	ldrsh r0, [r0, r1]
	bl GetFriendArea
	lsls r0, 24
	lsrs r0, 24
	cmp r4, r0
	beq _0802419E
	movs r0, 0
	b _080241A0
_0802419E:
	movs r0, 0x1
_080241A0:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_8024184

	thumb_func_start sub_80241A8
sub_80241A8:
	push {r4,lr}
	ldr r4, _080241C0
	ldr r1, [r4]
	ldr r0, [r1, 0x4]
	cmp r0, 0x2
	beq _080241CA
	cmp r0, 0x2
	bhi _080241C4
	cmp r0, 0x1
	beq _08024206
	b _08024222
	.align 2, 0
_080241C0: .4byte gUnknown_3001B60
_080241C4:
	cmp r0, 0x3
	beq _080241E8
	b _08024222
_080241CA:
	ldr r0, [r1, 0xC]
	ldr r1, [r1, 0x10]
	cmp r0, r1
	beq _080241D6
	bl sub_80242D0
_080241D6:
	ldr r0, [r4]
	ldr r2, [r0, 0x10]
	ldr r1, [r0, 0x8]
	cmp r2, r1
	beq _08024222
	adds r0, r2, 0
	bl sub_80242D0
	b _08024222
_080241E8:
	ldr r0, [r1, 0xC]
	ldr r1, [r1, 0x10]
	cmp r0, r1
	beq _080241F4
	bl sub_802437C
_080241F4:
	ldr r0, [r4]
	ldr r2, [r0, 0x10]
	ldr r1, [r0, 0x8]
	cmp r2, r1
	beq _08024222
	adds r0, r2, 0
	bl sub_802437C
	b _08024222
_08024206:
	ldr r0, [r1, 0xC]
	ldr r1, [r1, 0x10]
	cmp r0, r1
	beq _08024212
	bl sub_8024228
_08024212:
	ldr r0, [r4]
	ldr r2, [r0, 0x10]
	ldr r1, [r0, 0x8]
	cmp r2, r1
	beq _08024222
	adds r0, r2, 0
	bl sub_8024228
_08024222:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_80241A8

	thumb_func_start sub_8024228
sub_8024228:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0xC
	ldr r3, _080242C8
	lsls r2, r1, 1
	adds r2, 0x18
	ldr r3, [r3]
	adds r3, r2
	str r3, [sp]
	adds r2, r0, 0
	subs r1, 0x1
	cmp r2, r1
	bge _080242B8
	str r1, [sp, 0x4]
_0802424A:
	ldr r5, [sp]
	adds r7, r1, 0
	adds r0, r2, 0x1
	mov r10, r0
	cmp r7, r2
	ble _080242B0
	ldr r3, _080242CC
	mov r9, r3
	movs r0, 0x58
	mov r8, r0
_0802425E:
	mov r3, r9
	ldr r1, [r3]
	subs r6, r5, 0x2
	movs r3, 0
	ldrsh r0, [r6, r3]
	mov r3, r8
	muls r3, r0
	adds r0, r3, 0
	adds r1, r0
	movs r3, 0x8
	ldrsh r0, [r1, r3]
	str r2, [sp, 0x8]
	bl sub_808DCFC
	adds r4, r0, 0
	mov r0, r9
	ldr r1, [r0]
	movs r3, 0
	ldrsh r0, [r5, r3]
	mov r3, r8
	muls r3, r0
	adds r0, r3, 0
	adds r1, r0
	movs r3, 0x8
	ldrsh r0, [r1, r3]
	bl sub_808DCFC
	lsls r4, 16
	lsls r0, 16
	ldr r2, [sp, 0x8]
	cmp r4, r0
	ble _080242A8
	movs r0, 0
	ldrsh r1, [r5, r0]
	ldrh r0, [r6]
	strh r0, [r5]
	strh r1, [r6]
_080242A8:
	adds r5, r6, 0
	subs r7, 0x1
	cmp r7, r2
	bgt _0802425E
_080242B0:
	mov r2, r10
	ldr r1, [sp, 0x4]
	cmp r2, r1
	blt _0802424A
_080242B8:
	add sp, 0xC
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_080242C8: .4byte gUnknown_3001B60
_080242CC: .4byte gUnknown_203B45C
	thumb_func_end sub_8024228

	thumb_func_start sub_80242D0
sub_80242D0:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0xC
	ldr r3, _08024374
	lsls r2, r1, 1
	adds r2, 0x18
	ldr r3, [r3]
	adds r3, r2
	str r3, [sp]
	adds r2, r0, 0
	subs r1, 0x1
	cmp r2, r1
	bge _08024364
	str r1, [sp, 0x4]
_080242F2:
	ldr r5, [sp]
	adds r7, r1, 0
	adds r0, r2, 0x1
	mov r10, r0
	cmp r7, r2
	ble _0802435C
	ldr r3, _08024378
	mov r9, r3
	movs r0, 0x58
	mov r8, r0
_08024306:
	mov r3, r9
	ldr r1, [r3]
	subs r6, r5, 0x2
	movs r3, 0
	ldrsh r0, [r6, r3]
	mov r3, r8
	muls r3, r0
	adds r0, r3, 0
	adds r1, r0
	movs r3, 0x8
	ldrsh r0, [r1, r3]
	movs r1, 0
	str r2, [sp, 0x8]
	bl sub_808DCDC
	adds r4, r0, 0
	mov r0, r9
	ldr r1, [r0]
	movs r3, 0
	ldrsh r0, [r5, r3]
	mov r3, r8
	muls r3, r0
	adds r0, r3, 0
	adds r1, r0
	movs r3, 0x8
	ldrsh r0, [r1, r3]
	movs r1, 0
	bl sub_808DCDC
	lsls r4, 16
	lsls r0, 16
	ldr r2, [sp, 0x8]
	cmp r4, r0
	ble _08024354
	movs r0, 0
	ldrsh r1, [r5, r0]
	ldrh r0, [r6]
	strh r0, [r5]
	strh r1, [r6]
_08024354:
	adds r5, r6, 0
	subs r7, 0x1
	cmp r7, r2
	bgt _08024306
_0802435C:
	mov r2, r10
	ldr r1, [sp, 0x4]
	cmp r2, r1
	blt _080242F2
_08024364:
	add sp, 0xC
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_08024374: .4byte gUnknown_3001B60
_08024378: .4byte gUnknown_203B45C
	thumb_func_end sub_80242D0

	thumb_func_start sub_802437C
sub_802437C:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	ldr r3, _080243E4
	lsls r2, r1, 1
	adds r2, 0x18
	ldr r3, [r3]
	adds r3, r2
	mov r10, r3
	adds r7, r0, 0
	subs r1, 0x1
	cmp r7, r1
	bge _080243D6
	mov r9, r1
_0802439C:
	mov r4, r10
	adds r6, r1, 0
	adds r0, r7, 0x1
	mov r8, r0
	cmp r6, r7
	ble _080243CE
_080243A8:
	subs r5, r4, 0x2
	movs r1, 0
	ldrsh r0, [r5, r1]
	movs r2, 0
	ldrsh r1, [r4, r2]
	bl sub_808D864
	lsls r0, 24
	cmp r0, 0
	beq _080243C6
	movs r0, 0
	ldrsh r1, [r4, r0]
	ldrh r0, [r5]
	strh r0, [r4]
	strh r1, [r5]
_080243C6:
	adds r4, r5, 0
	subs r6, 0x1
	cmp r6, r7
	bgt _080243A8
_080243CE:
	mov r7, r8
	mov r1, r9
	cmp r7, r1
	blt _0802439C
_080243D6:
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_080243E4: .4byte gUnknown_3001B60
	thumb_func_end sub_802437C

	thumb_func_start sub_80243E8
sub_80243E8:
	push {r4,r5,lr}
	sub sp, 0x3C
	ldr r3, _08024448
	ldr r0, _0802444C
	ldr r0, [r0]
	ldr r2, _08024450
	adds r1, r0, r2
	movs r4, 0
	ldrsh r2, [r1, r4]
	movs r4, 0xDD
	lsls r4, 2
	adds r1, r0, r4
	movs r4, 0
	ldrsh r1, [r1, r4]
	muls r1, r2
	movs r4, 0xDC
	lsls r4, 2
	adds r2, r0, r4
	movs r4, 0
	ldrsh r2, [r2, r4]
	adds r1, r2
	lsls r1, 1
	adds r0, 0x1A
	adds r0, r1
	movs r2, 0
	ldrsh r1, [r0, r2]
	movs r0, 0x58
	muls r0, r1
	ldr r4, [r3]
	adds r4, r0
	add r5, sp, 0x28
	adds r1, r4, 0
	adds r1, 0x4C
	adds r0, r5, 0
	movs r2, 0xA
	bl sub_80922B4
	ldr r1, _08024454
	mov r0, sp
	adds r2, r5, 0
	bl sub_800D158
	adds r0, r4, 0
	add sp, 0x3C
	pop {r4,r5}
	pop {r1}
	bx r1
	.align 2, 0
_08024448: .4byte gUnknown_203B45C
_0802444C: .4byte gUnknown_3001B60
_08024450: .4byte 0x00000376
_08024454: .4byte gUnknown_80DC9A4
	thumb_func_end sub_80243E8

	thumb_func_start sub_8024458
sub_8024458:
	push {r4-r6,lr}
	adds r4, r0, 0
	adds r5, r1, 0
	lsls r4, 16
	asrs r4, 16
	ldr r6, _080244DC
	movs r0, 0xA6
	lsls r0, 1
	movs r1, 0x8
	bl MemoryAlloc
	str r0, [r6]
	adds r1, r0, 0
	adds r1, 0x48
	strh r4, [r1]
	adds r1, 0x98
	str r5, [r1]
	adds r2, r0, 0
	adds r2, 0xE4
	lsls r1, r5, 1
	adds r1, r5
	lsls r1, 3
	adds r1, 0xE8
	adds r1, r0, r1
	str r1, [r2]
	adds r0, 0xE8
	bl sub_8006518
	ldr r1, [r6]
	adds r0, r1, 0
	adds r0, 0xE0
	ldr r2, [r0]
	lsls r0, r2, 1
	adds r0, r2
	lsls r0, 3
	adds r1, r0
	adds r1, 0xE8
	ldr r0, _080244E0
	ldm r0!, {r2-r4}
	stm r1!, {r2-r4}
	ldm r0!, {r2-r4}
	stm r1!, {r2-r4}
	ldr r2, [r6]
	adds r0, r2, 0
	adds r0, 0xE4
	ldr r1, [r0]
	movs r3, 0xA4
	lsls r3, 1
	adds r0, r2, r3
	str r0, [r1, 0x14]
	movs r4, 0xA5
	lsls r4, 1
	adds r1, r2, r4
	movs r0, 0xA
	strb r0, [r1]
	bl sub_8024604
	bl sub_802452C
	ldr r0, [r6]
	bl sub_8013984
	movs r0, 0x1
	pop {r4-r6}
	pop {r1}
	bx r1
	.align 2, 0
_080244DC: .4byte gUnknown_203B2AC
_080244E0: .4byte gUnknown_80DC9C8
	thumb_func_end sub_8024458

	thumb_func_start sub_80244E4
sub_80244E4:
	push {r4,lr}
	ldr r4, _08024500
	ldr r0, [r4]
	bl GetKeyPress
	cmp r0, 0x1
	beq _08024504
	cmp r0, 0x2
	bne _0802450E
	movs r0, 0x1
	bl sub_80119D4
	movs r0, 0x2
	b _08024524
	.align 2, 0
_08024500: .4byte gUnknown_203B2AC
_08024504:
	movs r0, 0
	bl sub_80119D4
	movs r0, 0x3
	b _08024524
_0802450E:
	ldr r0, [r4]
	bl sub_8013938
	lsls r0, 24
	cmp r0, 0
	bne _0802451E
	movs r0, 0
	b _08024524
_0802451E:
	bl sub_802452C
	movs r0, 0x1
_08024524:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_80244E4

	thumb_func_start sub_802452C
sub_802452C:
	push {lr}
	bl sub_8024588
	bl sub_80245D0
	pop {r0}
	bx r0
	thumb_func_end sub_802452C

	thumb_func_start sub_802453C
sub_802453C:
	push {r4,r5,lr}
	ldr r4, _08024580
	ldr r2, [r4]
	cmp r2, 0
	beq _0802457A
	adds r0, r2, 0
	adds r0, 0xE0
	ldr r0, [r0]
	lsls r1, r0, 1
	adds r1, r0
	lsls r1, 3
	adds r1, r2, r1
	adds r1, 0xE8
	ldr r0, _08024584
	ldm r0!, {r2,r3,r5}
	stm r1!, {r2,r3,r5}
	ldm r0!, {r2,r3,r5}
	stm r1!, {r2,r3,r5}
	bl sub_8004914
	ldr r0, [r4]
	adds r0, 0xE8
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	ldr r0, [r4]
	bl MemoryFree
	movs r0, 0
	str r0, [r4]
_0802457A:
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_08024580: .4byte gUnknown_203B2AC
_08024584: .4byte gUnknown_80DC9B0
	thumb_func_end sub_802453C

	thumb_func_start sub_8024588
sub_8024588:
	push {r4,lr}
	ldr r4, _080245C4
	ldr r0, [r4]
	ldrh r1, [r0, 0x20]
	movs r2, 0xA4
	lsls r2, 1
	adds r0, r2
	movs r2, 0
	strb r1, [r0]
	ldr r0, [r4]
	ldrh r1, [r0, 0x1E]
	ldr r3, _080245C8
	adds r0, r3
	strb r1, [r0]
	ldr r0, [r4]
	ldr r1, _080245CC
	adds r0, r1
	strb r2, [r0]
	bl sub_8004914
	ldr r0, [r4]
	adds r0, 0xE8
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080245C4: .4byte gUnknown_203B2AC
_080245C8: .4byte 0x00000149
_080245CC: .4byte 0x0000014b
	thumb_func_end sub_8024588

	thumb_func_start sub_80245D0
sub_80245D0:
	push {r4,lr}
	sub sp, 0x4
	ldr r0, _08024600
	ldr r4, [r0]
	movs r0, 0x1E
	ldrsh r1, [r4, r0]
	lsls r2, r1, 2
	adds r0, r4, 0
	adds r0, 0x34
	adds r0, r2
	ldr r0, [r0]
	adds r2, r4, 0
	adds r2, 0x4C
	adds r3, r4, 0
	adds r3, 0xB0
	adds r4, 0xE0
	ldr r4, [r4]
	str r4, [sp]
	bl sub_808F844
	add sp, 0x4
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08024600: .4byte gUnknown_203B2AC
	thumb_func_end sub_80245D0

	thumb_func_start sub_8024604
sub_8024604:
	push {r4,r5,lr}
	ldr r4, _08024654
	ldr r0, [r4]
	movs r1, 0x2
	str r1, [r0, 0x34]
	movs r1, 0x3
	str r1, [r0, 0x38]
	movs r1, 0x5
	str r1, [r0, 0x3C]
	adds r1, r0, 0
	adds r1, 0xE0
	ldr r3, [r1]
	movs r1, 0x3
	movs r2, 0x1
	bl sub_8013818
	ldr r0, [r4]
	adds r5, r0, 0
	adds r5, 0x4C
	ldr r2, _08024658
	adds r0, 0x48
	movs r3, 0
	ldrsh r1, [r0, r3]
	movs r0, 0x58
	muls r0, r1
	ldr r4, [r2]
	adds r4, r0
	movs r0, 0x7
	bl sub_80023E4
	adds r2, r0, 0
	lsls r2, 24
	lsrs r2, 24
	adds r0, r5, 0
	adds r1, r4, 0
	bl sub_808FF20
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_08024654: .4byte gUnknown_203B2AC
_08024658: .4byte gUnknown_203B45C
	thumb_func_end sub_8024604

	thumb_func_start sub_802465C
sub_802465C:
	push {r4,r5,lr}
	bl sub_8004914
	movs r0, 0
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	ldr r5, _080246E8
	movs r0, 0xBA
	lsls r0, 1
	movs r1, 0x8
	bl MemoryAlloc
	str r0, [r5]
	movs r4, 0
	str r4, [r0, 0x28]
	str r4, [r0, 0x2C]
	str r4, [r0, 0x30]
	bl sub_808D33C
	ldr r1, [r5]
	str r0, [r1, 0xC]
	bl sub_808D824
	ldr r1, [r5]
	strb r0, [r1, 0x10]
	ldr r0, [r5]
	strb r4, [r0]
	ldr r0, _080246EC
	bl sub_808DDD0
	ldr r2, [r5]
	movs r3, 0x82
	lsls r3, 1
	adds r1, r2, r3
	str r0, [r1]
	adds r3, 0x4
	adds r1, r2, r3
	ldr r0, [r0, 0x4]
	str r0, [r1]
	movs r1, 0x88
	lsls r1, 1
	adds r0, r2, r1
	strb r4, [r0]
	ldr r0, [r5]
	adds r3, 0x9
	adds r0, r3
	strb r4, [r0]
	ldr r0, [r5]
	adds r1, 0x2
	adds r0, r1
	strb r4, [r0]
	ldr r2, [r5]
	subs r3, 0x5
	adds r1, r2, r3
	movs r0, 0x2
	strh r0, [r1]
	movs r0, 0x87
	lsls r0, 1
	adds r1, r2, r0
	movs r0, 0x8
	strh r0, [r1]
	movs r0, 0
	bl sub_80247EC
	movs r0, 0x1
	pop {r4,r5}
	pop {r1}
	bx r1
	.align 2, 0
_080246E8: .4byte gUnknown_203B2B0
_080246EC: .4byte 0x00000155
	thumb_func_end sub_802465C

	thumb_func_start sub_80246F0
sub_80246F0:
	push {lr}
	ldr r0, _08024708
	ldr r0, [r0]
	ldr r0, [r0, 0x20]
	cmp r0, 0x15
	bhi _080247A8
	lsls r0, 2
	ldr r1, _0802470C
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08024708: .4byte gUnknown_203B2B0
_0802470C: .4byte _08024710
	.align 2, 0
_08024710:
	.4byte _08024768
	.4byte _08024768
	.4byte _080247A8
	.4byte _080247A8
	.4byte _080247A4
	.4byte _0802476E
	.4byte _08024774
	.4byte _08024774
	.4byte _0802477A
	.4byte _08024780
	.4byte _08024786
	.4byte _0802478C
	.4byte _0802478C
	.4byte _08024792
	.4byte _08024798
	.4byte _080247A8
	.4byte _080247A8
	.4byte _080247A8
	.4byte _080247A8
	.4byte _080247A8
	.4byte _080247A8
	.4byte _0802479E
_08024768:
	bl sub_8024E9C
	b _080247AC
_0802476E:
	bl sub_8024F00
	b _080247AC
_08024774:
	bl sub_8024FD4
	b _080247AC
_0802477A:
	bl sub_80250EC
	b _080247AC
_08024780:
	bl sub_80251CC
	b _080247AC
_08024786:
	bl sub_8024F70
	b _080247AC
_0802478C:
	bl sub_8025058
	b _080247AC
_08024792:
	bl sub_802515C
	b _080247AC
_08024798:
	bl sub_80251E8
	b _080247AC
_0802479E:
	bl sub_8025204
	b _080247AC
_080247A4:
	movs r0, 0x3
	b _080247AE
_080247A8:
	bl sub_8025230
_080247AC:
	movs r0, 0
_080247AE:
	pop {r1}
	bx r1
	thumb_func_end sub_80246F0

	thumb_func_start sub_80247B4
sub_80247B4:
	ldr r0, _080247BC
	ldr r0, [r0]
	ldrb r0, [r0]
	bx lr
	.align 2, 0
_080247BC: .4byte gUnknown_203B2B0
	thumb_func_end sub_80247B4

	thumb_func_start sub_80247C0
sub_80247C0:
	push {r4,lr}
	ldr r4, _080247E8
	ldr r0, [r4]
	cmp r0, 0
	beq _080247E0
	movs r1, 0x82
	lsls r1, 1
	adds r0, r1
	ldr r0, [r0]
	bl CloseFile
	ldr r0, [r4]
	bl MemoryFree
	movs r0, 0
	str r0, [r4]
_080247E0:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080247E8: .4byte gUnknown_203B2B0
	thumb_func_end sub_80247C0

	thumb_func_start sub_80247EC
sub_80247EC:
	push {lr}
	ldr r1, _08024800
	ldr r1, [r1]
	str r0, [r1, 0x20]
	bl sub_8024804
	bl sub_80248FC
	pop {r0}
	bx r0
	.align 2, 0
_08024800: .4byte gUnknown_203B2B0
	thumb_func_end sub_80247EC

	thumb_func_start sub_8024804
sub_8024804:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	ldr r4, _0802482C
	ldr r0, [r4]
	movs r1, 0x8A
	lsls r1, 1
	adds r0, r1
	bl sub_8006518
	ldr r0, [r4]
	ldr r0, [r0, 0x20]
	subs r0, 0x8
	cmp r0, 0x14
	bhi _080248A8
	lsls r0, 2
	ldr r1, _08024830
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0802482C: .4byte gUnknown_203B2B0
_08024830: .4byte _08024834
	.align 2, 0
_08024834:
	.4byte _08024888
	.4byte _080248A8
	.4byte _080248A8
	.4byte _080248A8
	.4byte _080248A8
	.4byte _08024888
	.4byte _080248A8
	.4byte _080248A8
	.4byte _080248A8
	.4byte _080248D2
	.4byte _080248D2
	.4byte _080248D2
	.4byte _080248A8
	.4byte _080248A8
	.4byte _080248D2
	.4byte _080248D2
	.4byte _080248D2
	.4byte _080248D2
	.4byte _080248D2
	.4byte _080248D2
	.4byte _080248D2
_08024888:
	ldr r0, _080248A0
	ldr r1, [r0]
	movs r2, 0xA2
	lsls r2, 1
	adds r1, r2
	ldr r0, _080248A4
	ldm r0!, {r3-r5}
	stm r1!, {r3-r5}
	ldm r0!, {r2,r6,r7}
	stm r1!, {r2,r6,r7}
	b _080248D2
	.align 2, 0
_080248A0: .4byte gUnknown_203B2B0
_080248A4: .4byte gUnknown_80DCA00
_080248A8:
	ldr r3, _080248F4
	mov r12, r3
	movs r4, 0x8A
	lsls r4, 1
	mov r8, r4
	ldr r4, _080248F8
	movs r3, 0
	movs r2, 0x3
_080248B8:
	mov r5, r12
	ldr r1, [r5]
	adds r1, r3
	add r1, r8
	adds r0, r4, 0
	ldm r0!, {r5-r7}
	stm r1!, {r5-r7}
	ldm r0!, {r5-r7}
	stm r1!, {r5-r7}
	adds r3, 0x18
	subs r2, 0x1
	cmp r2, 0
	bge _080248B8
_080248D2:
	bl sub_8004914
	ldr r0, _080248F4
	ldr r0, [r0]
	movs r6, 0x8A
	lsls r6, 1
	adds r0, r6
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_080248F4: .4byte gUnknown_203B2B0
_080248F8: .4byte gUnknown_80DC9E8
	thumb_func_end sub_8024804

	thumb_func_start sub_80248FC
sub_80248FC:
	push {r4,r5,lr}
	sub sp, 0x14
	ldr r1, _08024918
	ldr r0, [r1]
	ldr r0, [r0, 0x20]
	adds r5, r1, 0
	cmp r0, 0x1D
	bls _0802490E
	b _08024CF4
_0802490E:
	lsls r0, 2
	ldr r1, _0802491C
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08024918: .4byte gUnknown_203B2B0
_0802491C: .4byte _08024920
	.align 2, 0
_08024920:
	.4byte _08024998
	.4byte _080249D0
	.4byte _080249E8
	.4byte _080249F8
	.4byte _08024CF4
	.4byte _08024A14
	.4byte _08024A20
	.4byte _08024A2E
	.4byte _08024A94
	.4byte _08024AC0
	.4byte _08024A36
	.4byte _08024A68
	.4byte _08024A76
	.4byte _08024A94
	.4byte _08024AC0
	.4byte _08024ACA
	.4byte _08024AD8
	.4byte _08024AE8
	.4byte _08024B4C
	.4byte _08024B74
	.4byte _08024C9C
	.4byte _08024CC8
	.4byte _08024C1C
	.4byte _08024C2C
	.4byte _08024C3C
	.4byte _08024C4C
	.4byte _08024C5C
	.4byte _08024C6C
	.4byte _08024C7C
	.4byte _08024C8C
_08024998:
	bl sub_80252B8
	lsls r0, 24
	cmp r0, 0
	beq _080249B0
	ldr r0, _080249AC
	ldr r1, [r0]
	movs r0, 0x3
	b _080249B6
	.align 2, 0
_080249AC: .4byte gUnknown_203B2B0
_080249B0:
	ldr r0, _080249C8
	ldr r1, [r0]
	movs r0, 0x1
_080249B6:
	str r0, [r1, 0x28]
	bl sub_8024CFC
	ldr r0, _080249CC
	ldr r1, _080249C8
	ldr r1, [r1]
	ldr r2, [r1, 0x28]
	b _08024A42
	.align 2, 0
_080249C8: .4byte gUnknown_203B2B0
_080249CC: .4byte gUnknown_80DCA34
_080249D0:
	bl sub_8024CFC
	ldr r0, _080249E0
	ldr r1, _080249E4
	ldr r1, [r1]
	ldr r2, [r1, 0x28]
	b _08024A42
	.align 2, 0
_080249E0: .4byte gUnknown_80DCAB8
_080249E4: .4byte gUnknown_203B2B0
_080249E8:
	ldr r1, [r5]
	movs r0, 0x1
	str r0, [r1, 0x24]
	ldr r0, _080249F4
	b _08024CAE
	.align 2, 0
_080249F4: .4byte gUnknown_80DCAD0
_080249F8:
	ldr r1, [r5]
	movs r0, 0x4
	str r0, [r1, 0x24]
	movs r0, 0x8
	movs r1, 0x3C
	bl sub_8011900
	ldr r0, _08024A0C
	ldr r3, _08024A10
	b _08024CB0
	.align 2, 0
_08024A0C: .4byte gUnknown_80DCD5C
_08024A10: .4byte 0x00000305
_08024A14:
	bl sub_8024D48
	ldr r0, _08024A1C
	b _08024A3C
	.align 2, 0
_08024A1C: .4byte gUnknown_80DCD90
_08024A20:
	movs r0, 0x2
	movs r1, 0x3
	movs r2, 0
	movs r3, 0xA
	bl sub_801A5D8
	b _08024CF4
_08024A2E:
	movs r0, 0x1
	bl sub_801A8D0
	b _08024CF4
_08024A36:
	bl sub_8024DBC
	ldr r0, _08024A60
_08024A3C:
	ldr r1, _08024A64
	ldr r1, [r1]
	ldr r2, [r1, 0x2C]
_08024A42:
	adds r3, r1, 0
	adds r3, 0x34
	adds r1, 0x74
	str r1, [sp]
	movs r1, 0x4
	str r1, [sp, 0x4]
	movs r1, 0
	str r1, [sp, 0x8]
	str r1, [sp, 0xC]
	movs r1, 0x5
	str r1, [sp, 0x10]
	movs r1, 0
	bl sub_8014248
	b _08024CF4
	.align 2, 0
_08024A60: .4byte gUnknown_80DCDB8
_08024A64: .4byte gUnknown_203B2B0
_08024A68:
	movs r0, 0x2
	movs r1, 0x3
	movs r2, 0
	movs r3, 0xA
	bl sub_801A5D8
	b _08024A7C
_08024A76:
	movs r0, 0x1
	bl sub_801A8D0
_08024A7C:
	ldr r0, _08024A90
	ldr r0, [r0]
	ldr r0, [r0, 0x14]
	movs r1, 0x1
	bl sub_801AEE4
	bl sub_801A9E0
	b _08024CF4
	.align 2, 0
_08024A90: .4byte gUnknown_203B2B0
_08024A94:
	bl sub_801A9E0
	bl sub_8024E30
	ldr r0, _08024ABC
	ldr r2, [r0]
	adds r0, r2, 0
	adds r0, 0x84
	adds r1, r2, 0
	adds r1, 0x34
	adds r3, r2, 0
	adds r3, 0x74
	ldr r2, [r2, 0x30]
	str r2, [sp]
	movs r2, 0x2
	str r2, [sp, 0x4]
	movs r2, 0
	bl sub_8012D60
	b _08024CF4
	.align 2, 0
_08024ABC: .4byte gUnknown_203B2B0
_08024AC0:
	ldr r0, [r5]
	adds r0, 0x1C
	bl sub_801B3C0
	b _08024CF4
_08024ACA:
	ldr r1, [r5]
	movs r0, 0x5
	str r0, [r1, 0x24]
	ldr r0, _08024AD4
	b _08024CAE
	.align 2, 0
_08024AD4: .4byte gUnknown_80DCDDC
_08024AD8:
	ldr r1, [r5]
	movs r0, 0xA
	str r0, [r1, 0x24]
	ldr r0, _08024AE4
	b _08024CAE
	.align 2, 0
_08024AE4: .4byte gUnknown_80DCE18
_08024AE8:
	bl sub_8025254
	ldr r0, _08024B00
	ldr r1, [r0]
	ldrh r2, [r1, 0x8]
	movs r0, 0x1
	ands r0, r2
	cmp r0, 0
	beq _08024B04
	movs r0, 0x12
	b _08024B3A
	.align 2, 0
_08024B00: .4byte gUnknown_203B2B0
_08024B04:
	lsls r0, r2, 16
	lsrs r0, 16
	cmp r0, 0x4
	bne _08024B10
	movs r0, 0x18
	b _08024B3A
_08024B10:
	cmp r0, 0x2
	bne _08024B18
	movs r0, 0x17
	b _08024B3A
_08024B18:
	cmp r0, 0x10
	bne _08024B20
	movs r0, 0x1B
	b _08024B3A
_08024B20:
	cmp r0, 0x20
	bne _08024B28
	movs r0, 0x19
	b _08024B3A
_08024B28:
	cmp r0, 0x40
	bne _08024B30
	movs r0, 0x1A
	b _08024B3A
_08024B30:
	cmp r0, 0x8
	bne _08024B38
	movs r0, 0x1C
	b _08024B3A
_08024B38:
	movs r0, 0x1D
_08024B3A:
	str r0, [r1, 0x24]
	movs r0, 0x3C
	bl sub_8011930
	ldr r0, _08024B48
	b _08024CAE
	.align 2, 0
_08024B48: .4byte gUnknown_80DCE38
_08024B4C:
	ldr r0, _08024B68
	ldr r1, [r5]
	ldr r1, [r1, 0xC]
	movs r2, 0x5
	bl sub_808D9AC
	ldr r0, _08024B6C
	bl sub_8011988
	ldr r1, [r5]
	movs r0, 0x13
	str r0, [r1, 0x24]
	ldr r0, _08024B70
	b _08024CAE
	.align 2, 0
_08024B68: .4byte gPlayerName
_08024B6C: .4byte 0x000001ff
_08024B70: .4byte gUnknown_80DCE68
_08024B74:
	ldr r0, [r5]
	ldr r0, [r0, 0xC]
	movs r1, 0x8
	ldrsh r0, [r0, r1]
	bl sub_808D994
	adds r1, r0, 0
	ldr r4, _08024C10
	adds r0, r4, 0
	bl strcpy
	ldr r0, [r5]
	movs r2, 0xA
	ldrsh r0, [r0, r2]
	bl sub_808D994
	adds r1, r0, 0
	adds r4, 0x50
	adds r0, r4, 0
	bl strcpy
	ldr r1, [r5]
	movs r0, 0x1
	strb r0, [r1]
	bl sub_80977D0
	ldr r1, [r5]
	ldr r0, [r1, 0xC]
	movs r2, 0xA
	ldrsh r1, [r1, r2]
	bl sub_808F734
	bl nullsub_104
	bl sub_808D33C
	ldr r1, [r5]
	str r0, [r1, 0xC]
	ldr r0, [r1, 0x14]
	cmp r0, 0x14
	beq _08024BCA
	bl sub_8091234
_08024BCA:
	ldr r0, [r5]
	ldr r0, [r0, 0x18]
	cmp r0, 0x14
	beq _08024BD6
	bl sub_8091234
_08024BD6:
	bl sub_80910B4
	ldr r0, _08024C14
	bl sub_801199C
	movs r0, 0xD2
	bl sub_8011988
	ldr r1, [r5]
	ldrb r0, [r1, 0x10]
	cmp r0, 0
	beq _08024C06
	ldr r0, [r1, 0xC]
	adds r4, r0, 0
	adds r4, 0x4C
	movs r1, 0x8
	ldrsh r0, [r0, r1]
	bl sub_808D994
	adds r1, r0, 0
	adds r0, r4, 0
	movs r2, 0xA
	bl sub_8092310
_08024C06:
	ldr r1, [r5]
	movs r0, 0x3
	str r0, [r1, 0x24]
	ldr r0, _08024C18
	b _08024CAE
	.align 2, 0
_08024C10: .4byte gUnknown_202DF98
_08024C14: .4byte 0x000001ff
_08024C18: .4byte gUnknown_80DCEB0
_08024C1C:
	ldr r1, [r5]
	movs r0, 0x3
	str r0, [r1, 0x24]
	ldr r0, _08024C28
	b _08024CAE
	.align 2, 0
_08024C28: .4byte gUnknown_80DCEDC
_08024C2C:
	ldr r1, [r5]
	movs r0, 0x3
	str r0, [r1, 0x24]
	ldr r0, _08024C38
	b _08024CAE
	.align 2, 0
_08024C38: .4byte gUnknown_80DCF44
_08024C3C:
	ldr r1, [r5]
	movs r0, 0x3
	str r0, [r1, 0x24]
	ldr r0, _08024C48
	b _08024CAE
	.align 2, 0
_08024C48: .4byte gUnknown_80DCF88
_08024C4C:
	ldr r1, [r5]
	movs r0, 0x3
	str r0, [r1, 0x24]
	ldr r0, _08024C58
	b _08024CAE
	.align 2, 0
_08024C58: .4byte gUnknown_80DCFAC
_08024C5C:
	ldr r1, [r5]
	movs r0, 0x3
	str r0, [r1, 0x24]
	ldr r0, _08024C68
	b _08024CAE
	.align 2, 0
_08024C68: .4byte gUnknown_80DCFF4
_08024C6C:
	ldr r1, [r5]
	movs r0, 0x3
	str r0, [r1, 0x24]
	ldr r0, _08024C78
	b _08024CAE
	.align 2, 0
_08024C78: .4byte gUnknown_80DD054
_08024C7C:
	ldr r1, [r5]
	movs r0, 0x3
	str r0, [r1, 0x24]
	ldr r0, _08024C88
	b _08024CAE
	.align 2, 0
_08024C88: .4byte gUnknown_80DD098
_08024C8C:
	ldr r1, [r5]
	movs r0, 0x3
	str r0, [r1, 0x24]
	ldr r0, _08024C98
	b _08024CAE
	.align 2, 0
_08024C98: .4byte gUnknown_80DD0E0
_08024C9C:
	movs r0, 0x8
	movs r1, 0x3C
	bl sub_8011900
	ldr r0, _08024CBC
	ldr r1, [r0]
	movs r0, 0x15
	str r0, [r1, 0x24]
	ldr r0, _08024CC0
_08024CAE:
	ldr r3, _08024CC4
_08024CB0:
	movs r1, 0
	movs r2, 0
	bl sub_80141B4
	b _08024CF4
	.align 2, 0
_08024CBC: .4byte gUnknown_203B2B0
_08024CC0: .4byte gUnknown_80DD104
_08024CC4: .4byte 0x00000105
_08024CC8:
	ldr r1, [r5]
	ldrb r0, [r1, 0x10]
	cmp r0, 0
	beq _08024CE8
	ldr r0, [r1, 0xC]
	adds r4, r0, 0
	adds r4, 0x4C
	movs r2, 0x8
	ldrsh r0, [r0, r2]
	bl sub_808D994
	adds r1, r0, 0
	adds r0, r4, 0
	movs r2, 0xA
	bl sub_8092310
_08024CE8:
	ldr r0, [r5]
	ldr r1, [r0, 0xC]
	adds r1, 0x4C
	movs r0, 0
	bl sub_801602C
_08024CF4:
	add sp, 0x14
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_80248FC

	thumb_func_start sub_8024CFC
sub_8024CFC:
	push {r4,lr}
	ldr r4, _08024D38
	ldr r0, [r4]
	adds r0, 0x74
	movs r1, 0
	movs r2, 0x10
	bl MemoryFill16
	ldr r1, [r4]
	movs r3, 0
	ldr r0, _08024D3C
	str r0, [r1, 0x34]
	movs r0, 0x3
	str r0, [r1, 0x38]
	movs r2, 0x1
	ldr r0, _08024D40
	ldr r0, [r0]
	str r0, [r1, 0x3C]
	movs r0, 0x2
	str r0, [r1, 0x40]
	ldr r0, _08024D44
	ldr r0, [r0]
	str r0, [r1, 0x44]
	str r2, [r1, 0x48]
	str r3, [r1, 0x4C]
	str r2, [r1, 0x50]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08024D38: .4byte gUnknown_203B2B0
_08024D3C: .4byte gUnknown_80DCA18
_08024D40: .4byte gUnknown_80D4970
_08024D44: .4byte gUnknown_80D4934
	thumb_func_end sub_8024CFC

	thumb_func_start sub_8024D48
sub_8024D48:
	push {r4-r7,lr}
	ldr r4, _08024DAC
	ldr r0, [r4]
	adds r0, 0x74
	movs r1, 0
	movs r2, 0x10
	bl MemoryFill16
	ldr r3, [r4]
	movs r2, 0
	ldr r0, _08024DB0
	str r0, [r3, 0x34]
	movs r0, 0x4
	str r0, [r3, 0x38]
	movs r1, 0x1
	ldr r0, _08024DB4
	str r0, [r3, 0x3C]
	movs r0, 0x5
	str r0, [r3, 0x40]
	ldr r0, _08024DB8
	ldr r0, [r0]
	str r0, [r3, 0x44]
	str r1, [r3, 0x48]
	movs r6, 0x3
	str r2, [r3, 0x4C]
	str r1, [r3, 0x50]
	movs r5, 0
	mov r12, r3
	adds r3, 0x38
	mov r2, r12
	adds r2, 0x74
_08024D86:
	ldrh r0, [r2]
	cmp r0, 0
	bne _08024D96
	ldr r1, [r3]
	mov r7, r12
	ldr r0, [r7, 0x2C]
	cmp r1, r0
	beq _08024DA6
_08024D96:
	adds r3, 0x8
	adds r2, 0x2
	adds r5, 0x1
	cmp r5, r6
	blt _08024D86
	ldr r1, [r4]
	movs r0, 0x4
	str r0, [r1, 0x2C]
_08024DA6:
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_08024DAC: .4byte gUnknown_203B2B0
_08024DB0: .4byte gUnknown_80DCA24
_08024DB4: .4byte gUnknown_80DCA2C
_08024DB8: .4byte gUnknown_80D4934
	thumb_func_end sub_8024D48

	thumb_func_start sub_8024DBC
sub_8024DBC:
	push {r4-r7,lr}
	ldr r4, _08024E20
	ldr r0, [r4]
	adds r0, 0x74
	movs r1, 0
	movs r2, 0x10
	bl MemoryFill16
	ldr r3, [r4]
	movs r2, 0
	ldr r0, _08024E24
	str r0, [r3, 0x34]
	movs r0, 0x4
	str r0, [r3, 0x38]
	movs r1, 0x1
	ldr r0, _08024E28
	str r0, [r3, 0x3C]
	movs r0, 0x5
	str r0, [r3, 0x40]
	ldr r0, _08024E2C
	ldr r0, [r0]
	str r0, [r3, 0x44]
	str r1, [r3, 0x48]
	movs r6, 0x3
	str r2, [r3, 0x4C]
	str r1, [r3, 0x50]
	movs r5, 0
	mov r12, r3
	adds r3, 0x38
	mov r2, r12
	adds r2, 0x74
_08024DFA:
	ldrh r0, [r2]
	cmp r0, 0
	bne _08024E0A
	ldr r1, [r3]
	mov r7, r12
	ldr r0, [r7, 0x2C]
	cmp r1, r0
	beq _08024E1A
_08024E0A:
	adds r3, 0x8
	adds r2, 0x2
	adds r5, 0x1
	cmp r5, r6
	blt _08024DFA
	ldr r1, [r4]
	movs r0, 0x4
	str r0, [r1, 0x2C]
_08024E1A:
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_08024E20: .4byte gUnknown_203B2B0
_08024E24: .4byte gUnknown_80DCA24
_08024E28: .4byte gUnknown_80DCA2C
_08024E2C: .4byte gUnknown_80D4934
	thumb_func_end sub_8024DBC

	thumb_func_start sub_8024E30
sub_8024E30:
	push {r4-r7,lr}
	ldr r4, _08024E90
	ldr r0, [r4]
	adds r0, 0x74
	movs r1, 0
	movs r2, 0x10
	bl MemoryFill16
	ldr r3, [r4]
	movs r2, 0
	ldr r0, _08024E94
	str r0, [r3, 0x34]
	movs r0, 0x5
	str r0, [r3, 0x38]
	movs r1, 0x1
	ldr r0, _08024E98
	ldr r0, [r0]
	str r0, [r3, 0x3C]
	movs r0, 0x2
	str r0, [r3, 0x40]
	movs r6, 0x2
	str r2, [r3, 0x44]
	str r1, [r3, 0x48]
	movs r5, 0
	mov r12, r3
	adds r3, 0x38
	mov r2, r12
	adds r2, 0x74
_08024E68:
	ldrh r0, [r2]
	cmp r0, 0
	bne _08024E78
	ldr r1, [r3]
	mov r7, r12
	ldr r0, [r7, 0x30]
	cmp r1, r0
	beq _08024E88
_08024E78:
	adds r3, 0x8
	adds r2, 0x2
	adds r5, 0x1
	cmp r5, r6
	blt _08024E68
	ldr r1, [r4]
	movs r0, 0x5
	str r0, [r1, 0x30]
_08024E88:
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_08024E90: .4byte gUnknown_203B2B0
_08024E94: .4byte gUnknown_80DCA2C
_08024E98: .4byte gUnknown_80D4970
	thumb_func_end sub_8024E30

	thumb_func_start sub_8024E9C
sub_8024E9C:
	push {lr}
	sub sp, 0x4
	mov r0, sp
	bl sub_80144A4
	cmp r0, 0
	bne _08024EF8
	ldr r1, [sp]
	cmp r1, 0x1
	beq _08024EB6
	ldr r0, _08024EC8
	ldr r0, [r0]
	str r1, [r0, 0x28]
_08024EB6:
	ldr r0, [sp]
	cmp r0, 0x2
	beq _08024EEA
	cmp r0, 0x2
	bgt _08024ECC
	cmp r0, 0x1
	beq _08024EF2
	b _08024EF8
	.align 2, 0
_08024EC8: .4byte gUnknown_203B2B0
_08024ECC:
	cmp r0, 0x3
	bne _08024EF8
	bl sub_80252B8
	lsls r0, 24
	cmp r0, 0
	beq _08024EE2
	movs r0, 0x5
	bl sub_80247EC
	b _08024EF8
_08024EE2:
	movs r0, 0x16
	bl sub_80247EC
	b _08024EF8
_08024EEA:
	movs r0, 0x2
	bl sub_80247EC
	b _08024EF8
_08024EF2:
	movs r0, 0x3
	bl sub_80247EC
_08024EF8:
	add sp, 0x4
	pop {r0}
	bx r0
	thumb_func_end sub_8024E9C

	thumb_func_start sub_8024F00
sub_8024F00:
	push {lr}
	sub sp, 0x4
	mov r0, sp
	bl sub_80144A4
	cmp r0, 0
	bne _08024F6A
	ldr r1, [sp]
	cmp r1, 0x1
	beq _08024F1A
	ldr r0, _08024F2C
	ldr r0, [r0]
	str r1, [r0, 0x2C]
_08024F1A:
	ldr r0, [sp]
	cmp r0, 0x4
	beq _08024F36
	cmp r0, 0x4
	bgt _08024F30
	cmp r0, 0x1
	beq _08024F64
	b _08024F6A
	.align 2, 0
_08024F2C: .4byte gUnknown_203B2B0
_08024F30:
	cmp r0, 0x5
	beq _08024F4C
	b _08024F6A
_08024F36:
	ldr r0, _08024F48
	ldr r1, [r0]
	movs r0, 0x14
	str r0, [r1, 0x14]
	str r0, [r1, 0x18]
	movs r0, 0x11
	bl sub_80247EC
	b _08024F6A
	.align 2, 0
_08024F48: .4byte gUnknown_203B2B0
_08024F4C:
	bl sub_8090A34
	cmp r0, 0
	bne _08024F5C
	movs r0, 0xF
	bl sub_80247EC
	b _08024F6A
_08024F5C:
	movs r0, 0x6
	bl sub_80247EC
	b _08024F6A
_08024F64:
	movs r0, 0x1
	bl sub_80247EC
_08024F6A:
	add sp, 0x4
	pop {r0}
	bx r0
	thumb_func_end sub_8024F00

	thumb_func_start sub_8024F70
sub_8024F70:
	push {lr}
	sub sp, 0x4
	mov r0, sp
	bl sub_80144A4
	cmp r0, 0
	bne _08024FCC
	ldr r1, [sp]
	cmp r1, 0x1
	beq _08024F8A
	ldr r0, _08024F9C
	ldr r0, [r0]
	str r1, [r0, 0x2C]
_08024F8A:
	ldr r0, [sp]
	cmp r0, 0x4
	beq _08024FA6
	cmp r0, 0x4
	bgt _08024FA0
	cmp r0, 0x1
	beq _08024FC6
	b _08024FCC
	.align 2, 0
_08024F9C: .4byte gUnknown_203B2B0
_08024FA0:
	cmp r0, 0x5
	beq _08024FAE
	b _08024FCC
_08024FA6:
	movs r0, 0x11
	bl sub_80247EC
	b _08024FCC
_08024FAE:
	bl sub_8090A34
	cmp r0, 0x1
	bgt _08024FBE
	movs r0, 0x10
	bl sub_80247EC
	b _08024FCC
_08024FBE:
	movs r0, 0xB
	bl sub_80247EC
	b _08024FCC
_08024FC6:
	movs r0, 0x1
	bl sub_80247EC
_08024FCC:
	add sp, 0x4
	pop {r0}
	bx r0
	thumb_func_end sub_8024F70

	thumb_func_start sub_8024FD4
sub_8024FD4:
	push {lr}
	movs r0, 0x1
	bl sub_801A6E8
	cmp r0, 0x3
	beq _08024FF0
	cmp r0, 0x3
	bhi _08024FEA
	cmp r0, 0x2
	beq _08025048
	b _08025052
_08024FEA:
	cmp r0, 0x4
	beq _0802501C
	b _08025052
_08024FF0:
	bl sub_801A8AC
	ldr r1, _08025014
	ldr r2, [r1]
	str r0, [r2, 0x14]
	movs r1, 0x14
	str r1, [r2, 0x18]
	ldr r1, _08025018
	ldr r1, [r1]
	lsls r0, 2
	adds r1, r0
	ldr r0, [r1]
	str r0, [r2, 0x1C]
	movs r0, 0x8
	bl sub_80247EC
	b _08025052
	.align 2, 0
_08025014: .4byte gUnknown_203B2B0
_08025018: .4byte gUnknown_203B460
_0802501C:
	bl sub_801A8AC
	ldr r1, _08025040
	ldr r2, [r1]
	ldr r1, _08025044
	ldr r1, [r1]
	lsls r0, 2
	adds r1, r0
	ldr r0, [r1]
	str r0, [r2, 0x1C]
	movs r0, 0
	bl sub_8099690
	movs r0, 0x9
	bl sub_80247EC
	b _08025052
	.align 2, 0
_08025040: .4byte gUnknown_203B2B0
_08025044: .4byte gUnknown_203B460
_08025048:
	bl sub_801A928
	movs r0, 0x5
	bl sub_80247EC
_08025052:
	pop {r0}
	bx r0
	thumb_func_end sub_8024FD4

	thumb_func_start sub_8025058
sub_8025058:
	push {r4,r5,lr}
	movs r0, 0x1
	bl sub_801A6E8
	cmp r0, 0x3
	beq _08025074
	cmp r0, 0x3
	bhi _0802506E
	cmp r0, 0x2
	beq _080250DC
	b _080250E6
_0802506E:
	cmp r0, 0x4
	beq _080250B0
	b _080250E6
_08025074:
	ldr r5, _080250A0
	ldr r4, [r5]
	bl sub_801A8AC
	ldr r1, [r4, 0x14]
	cmp r1, r0
	beq _080250A8
	bl sub_801A8AC
	ldr r2, [r5]
	str r0, [r2, 0x18]
	ldr r1, _080250A4
	ldr r1, [r1]
	lsls r0, 2
	adds r1, r0
	ldr r0, [r1]
	str r0, [r2, 0x1C]
	movs r0, 0xD
	bl sub_80247EC
	b _080250E6
	.align 2, 0
_080250A0: .4byte gUnknown_203B2B0
_080250A4: .4byte gUnknown_203B460
_080250A8:
	movs r0, 0x2
	bl sub_80119D4
	b _080250E6
_080250B0:
	bl sub_801A8AC
	ldr r1, _080250D4
	ldr r2, [r1]
	ldr r1, _080250D8
	ldr r1, [r1]
	lsls r0, 2
	adds r1, r0
	ldr r0, [r1]
	str r0, [r2, 0x1C]
	movs r0, 0
	bl sub_8099690
	movs r0, 0xE
	bl sub_80247EC
	b _080250E6
	.align 2, 0
_080250D4: .4byte gUnknown_203B2B0
_080250D8: .4byte gUnknown_203B460
_080250DC:
	bl sub_801A928
	movs r0, 0xA
	bl sub_80247EC
_080250E6:
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_8025058

	thumb_func_start sub_80250EC
sub_80250EC:
	push {r4,lr}
	sub sp, 0x4
	movs r0, 0
	str r0, [sp]
	bl sub_801A6E8
	ldr r4, _0802512C
	ldr r0, [r4]
	adds r0, 0x84
	bl sub_8012FD8
	lsls r0, 24
	cmp r0, 0
	bne _0802511C
	ldr r0, [r4]
	adds r0, 0x84
	mov r1, sp
	bl sub_8013114
	ldr r1, [sp]
	cmp r1, 0x1
	beq _0802511C
	ldr r0, [r4]
	str r1, [r0, 0x30]
_0802511C:
	ldr r0, [sp]
	cmp r0, 0x2
	beq _08025140
	cmp r0, 0x2
	bgt _08025130
	cmp r0, 0x1
	beq _0802514E
	b _08025154
	.align 2, 0
_0802512C: .4byte gUnknown_203B2B0
_08025130:
	cmp r0, 0x5
	bne _08025154
	bl sub_801A928
	movs r0, 0xA
	bl sub_80247EC
	b _08025154
_08025140:
	movs r0, 0
	bl sub_8099690
	movs r0, 0x9
	bl sub_80247EC
	b _08025154
_0802514E:
	movs r0, 0x7
	bl sub_80247EC
_08025154:
	add sp, 0x4
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_80250EC

	thumb_func_start sub_802515C
sub_802515C:
	push {r4,lr}
	sub sp, 0x4
	movs r0, 0
	str r0, [sp]
	bl sub_801A6E8
	ldr r4, _0802519C
	ldr r0, [r4]
	adds r0, 0x84
	bl sub_8012FD8
	lsls r0, 24
	cmp r0, 0
	bne _0802518C
	ldr r0, [r4]
	adds r0, 0x84
	mov r1, sp
	bl sub_8013114
	ldr r1, [sp]
	cmp r1, 0x1
	beq _0802518C
	ldr r0, [r4]
	str r1, [r0, 0x30]
_0802518C:
	ldr r0, [sp]
	cmp r0, 0x2
	beq _080251B0
	cmp r0, 0x2
	bgt _080251A0
	cmp r0, 0x1
	beq _080251BE
	b _080251C4
	.align 2, 0
_0802519C: .4byte gUnknown_203B2B0
_080251A0:
	cmp r0, 0x5
	bne _080251C4
	bl sub_801A928
	movs r0, 0x11
	bl sub_80247EC
	b _080251C4
_080251B0:
	movs r0, 0
	bl sub_8099690
	movs r0, 0xE
	bl sub_80247EC
	b _080251C4
_080251BE:
	movs r0, 0xC
	bl sub_80247EC
_080251C4:
	add sp, 0x4
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_802515C

	thumb_func_start sub_80251CC
sub_80251CC:
	push {lr}
	bl sub_801B410
	cmp r0, 0x1
	bls _080251E4
	cmp r0, 0x3
	bhi _080251E4
	bl sub_801B450
	movs r0, 0x7
	bl sub_80247EC
_080251E4:
	pop {r0}
	bx r0
	thumb_func_end sub_80251CC

	thumb_func_start sub_80251E8
sub_80251E8:
	push {lr}
	bl sub_801B410
	cmp r0, 0x1
	bls _08025200
	cmp r0, 0x3
	bhi _08025200
	bl sub_801B450
	movs r0, 0xC
	bl sub_80247EC
_08025200:
	pop {r0}
	bx r0
	thumb_func_end sub_80251E8

	thumb_func_start sub_8025204
sub_8025204:
	push {r4,lr}
	bl sub_8016080
	cmp r0, 0x3
	bne _08025226
	bl sub_80160D8
	ldr r4, _0802522C
	ldr r0, [r4]
	ldr r0, [r0, 0xC]
	bl sub_808D824
	ldr r1, [r4]
	strb r0, [r1, 0x10]
	movs r0, 0x3
	bl sub_80247EC
_08025226:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0802522C: .4byte gUnknown_203B2B0
	thumb_func_end sub_8025204

	thumb_func_start sub_8025230
sub_8025230:
	push {lr}
	sub sp, 0x4
	mov r0, sp
	bl sub_80144A4
	cmp r0, 0
	bne _08025248
	ldr r0, _08025250
	ldr r0, [r0]
	ldr r0, [r0, 0x24]
	bl sub_80247EC
_08025248:
	add sp, 0x4
	pop {r0}
	bx r0
	.align 2, 0
_08025250: .4byte gUnknown_203B2B0
	thumb_func_end sub_8025230

	thumb_func_start sub_8025254
sub_8025254:
	push {lr}
	ldr r0, _08025268
	ldr r2, [r0]
	ldr r1, [r2, 0x14]
	adds r3, r0, 0
	cmp r1, 0x14
	bne _0802526C
	movs r0, 0
	b _08025276
	.align 2, 0
_08025268: .4byte gUnknown_203B2B0
_0802526C:
	ldr r0, _08025284
	ldr r0, [r0]
	lsls r1, 2
	adds r0, r1
	ldrb r0, [r0, 0x2]
_08025276:
	strb r0, [r2, 0x4]
	ldr r2, [r3]
	ldr r1, [r2, 0x18]
	cmp r1, 0x14
	bne _08025288
	movs r0, 0
	b _08025292
	.align 2, 0
_08025284: .4byte gUnknown_203B460
_08025288:
	ldr r0, _080252B0
	ldr r0, [r0]
	lsls r1, 2
	adds r0, r1
	ldrb r0, [r0, 0x2]
_08025292:
	strb r0, [r2, 0x5]
	movs r0, 0xFF
	bl RandomCapped
	ldr r2, _080252B4
	ldr r1, [r2]
	strb r0, [r1, 0x6]
	ldr r1, [r2]
	ldr r0, [r1, 0xC]
	adds r1, 0x4
	movs r2, 0x1
	bl sub_808F468
	pop {r0}
	bx r0
	.align 2, 0
_080252B0: .4byte gUnknown_203B460
_080252B4: .4byte gUnknown_203B2B0
	thumb_func_end sub_8025254

	thumb_func_start sub_80252B8
sub_80252B8:
	push {r4,lr}
	ldr r0, _080252E0
	ldr r1, [r0]
	movs r3, 0
	movs r4, 0x1
	ldr r2, _080252E4
_080252C4:
	ldrh r0, [r1]
	lsrs r0, 1
	ands r0, r4
	cmp r0, 0
	beq _080252D0
	adds r3, 0x1
_080252D0:
	subs r2, 0x1
	adds r1, 0x58
	cmp r2, 0
	bne _080252C4
	cmp r3, 0x1
	beq _080252E8
	movs r0, 0
	b _080252EA
	.align 2, 0
_080252E0: .4byte gUnknown_203B45C
_080252E4: .4byte 0x0000019d
_080252E8:
	movs r0, 0x1
_080252EA:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_80252B8

	thumb_func_start sub_80252F0
sub_80252F0:
	push {r4-r6,lr}
	adds r6, r0, 0
	cmp r6, 0x2
	bne _08025308
	movs r0, 0x4
	bl sub_8024108
	lsls r0, 24
	cmp r0, 0
	beq _08025308
	movs r0, 0
	b _0802534C
_08025308:
	ldr r4, _08025340
	movs r0, 0xBC
	lsls r0, 1
	movs r1, 0x8
	bl MemoryAlloc
	str r0, [r4]
	movs r5, 0
	str r5, [r0, 0x70]
	str r6, [r0]
	bl sub_80A5728
	lsls r0, 16
	asrs r0, 16
	bl sub_8002658
	ldr r1, [r4]
	strb r0, [r1, 0xC]
	ldr r0, [r4]
	strb r5, [r0, 0xD]
	ldr r0, [r4]
	ldr r0, [r0]
	cmp r0, 0x2
	bne _08025344
	movs r0, 0
	bl sub_8025434
	b _0802534A
	.align 2, 0
_08025340: .4byte gUnknown_203B2B4
_08025344:
	movs r0, 0x1
	bl sub_8025434
_0802534A:
	movs r0, 0x1
_0802534C:
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end sub_80252F0

	thumb_func_start sub_8025354
sub_8025354:
	push {lr}
	ldr r0, _0802536C
	ldr r0, [r0]
	ldr r0, [r0, 0x4]
	subs r0, 0x1
	cmp r0, 0x12
	bhi _08025400
	lsls r0, 2
	ldr r1, _08025370
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0802536C: .4byte gUnknown_203B2B4
_08025370: .4byte _08025374
	.align 2, 0
_08025374:
	.4byte _080253C4
	.4byte _080253C4
	.4byte _080253CA
	.4byte _080253D0
	.4byte _080253D6
	.4byte _08025400
	.4byte _08025400
	.4byte _08025400
	.4byte _08025400
	.4byte _08025400
	.4byte _080253DC
	.4byte _080253DC
	.4byte _080253E2
	.4byte _080253E8
	.4byte _080253EE
	.4byte _080253EE
	.4byte _080253F4
	.4byte _080253FA
	.4byte _080253C0
_080253C0:
	movs r0, 0x3
	b _08025406
_080253C4:
	bl sub_80259F0
	b _08025404
_080253CA:
	bl sub_8025A84
	b _08025404
_080253D0:
	bl sub_8025BCC
	b _08025404
_080253D6:
	bl sub_8025BE8
	b _08025404
_080253DC:
	bl sub_8025C04
	b _08025404
_080253E2:
	bl sub_8025CB4
	b _08025404
_080253E8:
	bl sub_8025D90
	b _08025404
_080253EE:
	bl sub_8025DAC
	b _08025404
_080253F4:
	bl sub_8025E08
	b _08025404
_080253FA:
	bl sub_8025E24
	b _08025404
_08025400:
	bl sub_8025E44
_08025404:
	movs r0, 0
_08025406:
	pop {r1}
	bx r1
	thumb_func_end sub_8025354

	thumb_func_start sub_802540C
sub_802540C:
	ldr r0, _08025414
	ldr r0, [r0]
	ldrb r0, [r0, 0xD]
	bx lr
	.align 2, 0
_08025414: .4byte gUnknown_203B2B4
	thumb_func_end sub_802540C

	thumb_func_start sub_8025418
sub_8025418:
	push {r4,lr}
	ldr r4, _08025430
	ldr r0, [r4]
	cmp r0, 0
	beq _0802542A
	bl MemoryFree
	movs r0, 0
	str r0, [r4]
_0802542A:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08025430: .4byte gUnknown_203B2B4
	thumb_func_end sub_8025418

	thumb_func_start sub_8025434
sub_8025434:
	push {lr}
	ldr r1, _08025448
	ldr r1, [r1]
	str r0, [r1, 0x4]
	bl sub_802544C
	bl sub_8025518
	pop {r0}
	bx r0
	.align 2, 0
_08025448: .4byte gUnknown_203B2B4
	thumb_func_end sub_8025434

	thumb_func_start sub_802544C
sub_802544C:
	push {r4-r7,lr}
	ldr r4, _08025470
	ldr r0, [r4]
	movs r1, 0x8C
	lsls r1, 1
	adds r0, r1
	bl sub_8006518
	ldr r1, [r4]
	ldr r0, [r1, 0x4]
	cmp r0, 0x3
	beq _08025478
	cmp r0, 0xD
	beq _080254B0
	movs r2, 0
	ldr r3, _08025474
	b _080254D8
	.align 2, 0
_08025470: .4byte gUnknown_203B2B4
_08025474: .4byte gUnknown_80DD148
_08025478:
	ldr r0, [r1]
	cmp r0, 0
	bne _0802548E
	movs r2, 0xB0
	lsls r2, 1
	adds r1, r2
	ldr r0, _080254A8
	ldm r0!, {r3,r5,r6}
	stm r1!, {r3,r5,r6}
	ldm r0!, {r2,r3,r7}
	stm r1!, {r2,r3,r7}
_0802548E:
	bl sub_8025728
	ldr r2, [r4]
	movs r0, 0xA4
	lsls r0, 1
	adds r2, r0
	ldr r1, _080254AC
	ldm r1!, {r5-r7}
	stm r2!, {r5-r7}
	ldm r1!, {r3,r5,r6}
	stm r2!, {r3,r5,r6}
	b _080254C6
	.align 2, 0
_080254A8: .4byte gUnknown_80DD190
_080254AC: .4byte gUnknown_80DD160
_080254B0:
	bl sub_802591C
	ldr r2, [r4]
	movs r0, 0xA4
	lsls r0, 1
	adds r2, r0
	ldr r1, _080254D4
	ldm r1!, {r3,r5,r7}
	stm r2!, {r3,r5,r7}
	ldm r1!, {r3,r6,r7}
	stm r2!, {r3,r6,r7}
_080254C6:
	ldr r1, [r4]
	adds r0, r1, r0
	adds r1, 0xC8
	bl sub_8012CAC
	b _080254F8
	.align 2, 0
_080254D4: .4byte gUnknown_80DD178
_080254D8:
	ldr r0, [r4]
	lsls r1, r2, 1
	adds r1, r2
	lsls r1, 3
	adds r0, r1
	movs r5, 0x8C
	lsls r5, 1
	adds r0, r5
	adds r1, r3, 0
	ldm r1!, {r5-r7}
	stm r0!, {r5-r7}
	ldm r1!, {r5-r7}
	stm r0!, {r5-r7}
	adds r2, 0x1
	cmp r2, 0x3
	ble _080254D8
_080254F8:
	bl sub_8004914
	ldr r0, _08025514
	ldr r0, [r0]
	movs r6, 0x8C
	lsls r6, 1
	adds r0, r6
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_08025514: .4byte gUnknown_203B2B4
	thumb_func_end sub_802544C

	thumb_func_start sub_8025518
sub_8025518:
	push {r4,r5,lr}
	sub sp, 0xC
	ldr r1, _08025534
	ldr r0, [r1]
	ldr r0, [r0, 0x4]
	adds r5, r1, 0
	cmp r0, 0x13
	bls _0802552A
	b _08025720
_0802552A:
	lsls r0, 2
	ldr r1, _08025538
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08025534: .4byte gUnknown_203B2B4
_08025538: .4byte _0802553C
	.align 2, 0
_0802553C:
	.4byte _0802558C
	.4byte _080255A0
	.4byte _080255BA
	.4byte _080255C2
	.4byte _0802560C
	.4byte _0802561A
	.4byte _08025720
	.4byte _080256A8
	.4byte _0802567A
	.4byte _08025688
	.4byte _08025698
	.4byte _08025626
	.4byte _08025634
	.4byte _0802563C
	.4byte _08025668
	.4byte _080256CC
	.4byte _080256F2
	.4byte _080256FC
	.4byte _08025714
	.4byte _08025720
_0802558C:
	ldr r1, [r5]
	movs r0, 0x1
	str r0, [r1, 0x8]
	ldr r0, _08025598
	ldr r3, _0802559C
	b _080256B8
	.align 2, 0
_08025598: .4byte gUnknown_80DD1A8
_0802559C: .4byte 0x00000301
_080255A0:
	movs r1, 0x4
	ldr r0, [r5]
	ldr r0, [r0]
	cmp r0, 0
	bne _080255AC
	movs r1, 0x2
_080255AC:
	adds r0, r1, 0
	movs r1, 0
	movs r2, 0
	movs r3, 0xA
	bl sub_8023868
	b _08025720
_080255BA:
	movs r0, 0x1
	bl sub_8023B7C
	b _08025720
_080255C2:
	ldr r1, [r5]
	ldr r0, [r1]
	cmp r0, 0
	bne _080255D2
	adds r1, 0x18
	movs r0, 0x3
	bl sub_8025E68
_080255D2:
	bl sub_8023DA4
	ldr r4, _08025608
	ldr r0, [r5]
	ldr r1, [r0, 0x1C]
	adds r0, r4, 0
	movs r2, 0x7
	bl sub_808D9AC
	adds r4, 0x50
	ldr r0, [r5]
	ldr r1, [r0, 0x1C]
	adds r0, r4, 0
	movs r2, 0x6
	bl sub_808D9AC
	ldr r2, [r5]
	adds r0, r2, 0
	adds r0, 0x78
	adds r1, r2, 0
	adds r1, 0xC8
	movs r4, 0x84
	lsls r4, 1
	adds r3, r2, r4
	ldr r2, [r2, 0x70]
	b _08025654
	.align 2, 0
_08025608: .4byte gUnknown_202DF98
_0802560C:
	ldr r0, [r5]
	movs r1, 0xE
	ldrsh r0, [r0, r1]
	movs r1, 0x2
	bl sub_8024458
	b _08025720
_0802561A:
	ldr r0, [r5]
	movs r4, 0xE
	ldrsh r0, [r0, r4]
	bl sub_801BEEC
	b _08025720
_08025626:
	movs r0, 0x1
	movs r1, 0
	movs r2, 0
	movs r3, 0xA
	bl sub_801A5D8
	b _08025720
_08025634:
	movs r0, 0x1
	bl sub_801A8D0
	b _08025720
_0802563C:
	bl sub_801A9E0
	ldr r0, _08025664
	ldr r2, [r0]
	adds r0, r2, 0
	adds r0, 0x78
	adds r1, r2, 0
	adds r1, 0xC8
	movs r4, 0x84
	lsls r4, 1
	adds r3, r2, r4
	ldr r2, [r2, 0x74]
_08025654:
	str r2, [sp]
	movs r2, 0x2
	str r2, [sp, 0x4]
	movs r2, 0
	bl sub_8012D60
	b _08025720
	.align 2, 0
_08025664: .4byte gUnknown_203B2B4
_08025668:
	ldr r1, [r5]
	adds r1, 0x14
	add r0, sp, 0x8
	bl sub_8090B64
	add r0, sp, 0x8
	bl sub_801B3C0
	b _08025720
_0802567A:
	ldr r1, [r5]
	movs r0, 0x2
	str r0, [r1, 0x8]
	ldr r0, _08025684
	b _080256B6
	.align 2, 0
_08025684: .4byte gUnknown_80DD1C8
_08025688:
	ldr r1, [r5]
	movs r0, 0x2
	str r0, [r1, 0x8]
	ldr r0, _08025694
	b _080256B6
	.align 2, 0
_08025694: .4byte gUnknown_80DD1EC
_08025698:
	ldr r1, [r5]
	movs r0, 0x2
	str r0, [r1, 0x8]
	ldr r0, _080256A4
	b _080256B6
	.align 2, 0
_080256A4: .4byte gUnknown_80DD240
_080256A8:
	ldr r1, [r5]
	movs r0, 0x1
	str r0, [r1, 0x8]
	movs r0, 0xCF
	bl sub_8011988
	ldr r0, _080256C4
_080256B6:
	ldr r3, _080256C8
_080256B8:
	movs r1, 0
	movs r2, 0
	bl sub_80141B4
	b _08025720
	.align 2, 0
_080256C4: .4byte gUnknown_80DD270
_080256C8: .4byte 0x00000101
_080256CC:
	ldr r1, [r5]
	adds r0, r1, 0
	adds r0, 0x28
	ldr r1, [r1, 0x1C]
	adds r1, 0x2C
	bl sub_809401C
	ldr r2, [r5]
	movs r0, 0xE
	ldrsh r1, [r2, r0]
	adds r2, 0x28
	movs r0, 0
	str r0, [sp]
	str r0, [sp, 0x4]
	movs r0, 0x3
	movs r3, 0
	bl sub_801EE10
	b _08025720
_080256F2:
	movs r0, 0x1
	movs r1, 0
	bl sub_801F1B0
	b _08025720
_080256FC:
	ldr r2, [r5]
	ldr r0, [r2, 0x20]
	adds r1, r2, 0
	adds r1, 0x28
	adds r2, 0x68
	bl sub_8093560
	ldr r0, [r5]
	adds r0, 0x68
	bl sub_801F808
	b _08025720
_08025714:
	ldr r0, [r5]
	ldr r1, [r0, 0x1C]
	adds r1, 0x4C
	movs r0, 0x2
	bl sub_801602C
_08025720:
	add sp, 0xC
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_8025518

	thumb_func_start sub_8025728
sub_8025728:
	push {r4-r7,lr}
	ldr r3, _080257CC
	ldr r5, _080257D0
	ldr r0, [r5]
	movs r1, 0xE
	ldrsh r2, [r0, r1]
	movs r1, 0x58
	muls r2, r1
	ldr r1, [r3]
	adds r7, r1, r2
	movs r2, 0x84
	lsls r2, 1
	adds r0, r2
	movs r1, 0
	movs r2, 0x10
	bl MemoryFill16
	ldr r4, [r5]
	ldr r0, [r4]
	cmp r0, 0
	bne _080257E0
	adds r1, r4, 0
	adds r1, 0xC8
	ldr r0, _080257D4
	str r0, [r1]
	adds r1, 0x4
	movs r0, 0xA
	str r0, [r1]
	bl sub_8090A34
	cmp r0, 0
	bne _08025774
	ldr r0, [r5]
	movs r4, 0x84
	lsls r4, 1
	adds r0, r4
	movs r1, 0x1
	strh r1, [r0]
_08025774:
	movs r6, 0x1
	ldr r1, [r5]
	adds r2, r1, 0
	adds r2, 0xD0
	ldr r0, _080257D8
	str r0, [r2]
	adds r1, 0xD4
	movs r0, 0xB
	str r0, [r1]
	bl sub_8090A34
	cmp r0, 0x13
	bgt _08025796
	ldr r0, [r5]
	ldrb r0, [r0, 0x18]
	cmp r0, 0
	bne _080257A0
_08025796:
	ldr r0, [r5]
	movs r1, 0x85
	lsls r1, 1
	adds r0, r1
	strh r6, [r0]
_080257A0:
	adds r6, 0x1
	adds r0, r7, 0
	bl sub_8025EC4
	lsls r0, 24
	cmp r0, 0
	beq _08025810
	ldr r0, _080257D0
	ldr r2, [r0]
	lsls r3, r6, 3
	adds r0, r2, 0
	adds r0, 0xC8
	adds r0, r3
	ldr r1, _080257DC
	str r1, [r0]
	adds r2, 0xCC
	adds r2, r3
	movs r0, 0x9
	str r0, [r2]
	adds r6, 0x1
	b _08025810
	.align 2, 0
_080257CC: .4byte gUnknown_203B45C
_080257D0: .4byte gUnknown_203B2B4
_080257D4: .4byte gUnknown_80DD2B0
_080257D8: .4byte gUnknown_80DD2B8
_080257DC: .4byte gUnknown_80DD2C0
_080257E0:
	adds r1, r4, 0
	adds r1, 0xC8
	ldr r0, _080258D4
	str r0, [r1]
	adds r1, 0x4
	movs r0, 0x7
	str r0, [r1]
	ldr r0, [r4, 0x1C]
	movs r2, 0x8
	ldrsh r0, [r0, r2]
	bl GetFriendArea
	ldrb r1, [r4, 0xC]
	lsls r0, 24
	lsrs r0, 24
	cmp r1, r0
	bne _0802580E
	ldr r0, [r5]
	movs r4, 0x84
	lsls r4, 1
	adds r0, r4
	movs r1, 0x1
	strh r1, [r0]
_0802580E:
	movs r6, 0x1
_08025810:
	movs r0, 0x8
	ldrsh r1, [r7, r0]
	ldr r0, _080258D8
	cmp r1, r0
	bne _08025840
	adds r0, r7, 0
	bl sub_808D824
	lsls r0, 24
	cmp r0, 0
	beq _08025840
	ldr r0, _080258DC
	ldr r2, [r0]
	lsls r3, r6, 3
	adds r0, r2, 0
	adds r0, 0xC8
	adds r0, r3
	ldr r1, _080258E0
	str r1, [r0]
	adds r2, 0xCC
	adds r2, r3
	movs r0, 0x8
	str r0, [r2]
	adds r6, 0x1
_08025840:
	ldr r4, _080258DC
	ldr r5, [r4]
	lsls r1, r6, 3
	adds r3, r5, 0
	adds r3, 0xC8
	adds r2, r3, r1
	ldr r0, _080258E4
	str r0, [r2]
	adds r7, r5, 0
	adds r7, 0xCC
	adds r1, r7, r1
	movs r0, 0x4
	str r0, [r1]
	adds r6, 0x1
	lsls r1, r6, 3
	adds r2, r3, r1
	ldr r0, _080258E8
	str r0, [r2]
	adds r1, r7, r1
	movs r0, 0x6
	str r0, [r1]
	adds r6, 0x1
	lsls r1, r6, 3
	adds r2, r3, r1
	ldr r0, _080258EC
	str r0, [r2]
	adds r1, r7, r1
	movs r0, 0x5
	str r0, [r1]
	adds r6, 0x1
	lsls r1, r6, 3
	adds r3, r1
	movs r0, 0
	str r0, [r3]
	adds r1, r7, r1
	movs r0, 0x1
	str r0, [r1]
	movs r3, 0
	mov r12, r4
	cmp r3, r6
	bge _080258B2
	movs r1, 0x84
	lsls r1, 1
	adds r4, r5, r1
	adds r2, r7, 0
_0802589A:
	ldrh r0, [r4]
	cmp r0, 0
	bne _080258A8
	ldr r1, [r2]
	ldr r0, [r5, 0x70]
	cmp r1, r0
	beq _08025916
_080258A8:
	adds r4, 0x2
	adds r2, 0x8
	adds r3, 0x1
	cmp r3, r6
	blt _0802589A
_080258B2:
	movs r3, 0
	cmp r3, r6
	bge _08025916
	mov r2, r12
	ldr r1, [r2]
	movs r4, 0x84
	lsls r4, 1
	adds r0, r1, r4
	ldrh r0, [r0]
	cmp r0, 0
	bne _080258F0
	adds r0, r1, 0
	adds r0, 0xCC
	ldr r0, [r0]
	str r0, [r1, 0x70]
	b _08025916
	.align 2, 0
_080258D4: .4byte gUnknown_80DD2CC
_080258D8: .4byte 0x0000013d
_080258DC: .4byte gUnknown_203B2B4
_080258E0: .4byte gUnknown_80DD2D4
_080258E4: .4byte gUnknown_80DD2DC
_080258E8: .4byte gUnknown_80DD2E4
_080258EC: .4byte gUnknown_80DD2EC
_080258F0:
	adds r3, 0x1
	cmp r3, r6
	bge _08025916
	mov r0, r12
	ldr r2, [r0]
	lsls r0, r3, 1
	movs r4, 0x84
	lsls r4, 1
	adds r1, r2, r4
	adds r1, r0
	ldrh r0, [r1]
	cmp r0, 0
	bne _080258F0
	lsls r0, r3, 3
	adds r1, r2, 0
	adds r1, 0xCC
	adds r1, r0
	ldr r0, [r1]
	str r0, [r2, 0x70]
_08025916:
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_8025728

	thumb_func_start sub_802591C
sub_802591C:
	push {r4-r7,lr}
	ldr r5, _080259B8
	ldr r0, [r5]
	movs r7, 0x84
	lsls r7, 1
	adds r0, r7
	movs r1, 0
	movs r2, 0x10
	bl MemoryFill16
	ldr r1, [r5]
	adds r2, r1, 0
	adds r2, 0xC8
	ldr r0, _080259BC
	str r0, [r2]
	adds r1, 0xCC
	movs r0, 0xA
	str r0, [r1]
	bl sub_8090A34
	cmp r0, 0
	bne _08025952
	ldr r0, [r5]
	adds r1, r7, 0
	adds r0, r1
	movs r1, 0x1
	strh r1, [r0]
_08025952:
	ldr r4, [r5]
	movs r2, 0x1
	adds r1, r4, 0
	adds r1, 0xD0
	ldr r0, _080259C0
	ldr r0, [r0]
	str r0, [r1]
	adds r1, 0x4
	movs r0, 0x4
	str r0, [r1]
	movs r6, 0x2
	adds r1, 0x4
	movs r0, 0
	str r0, [r1]
	adds r0, r4, 0
	adds r0, 0xDC
	str r2, [r0]
	movs r3, 0
	mov r12, r4
	adds r4, r7
	mov r2, r12
	adds r2, 0xCC
_0802597E:
	ldrh r0, [r4]
	cmp r0, 0
	bne _0802598E
	ldr r1, [r2]
	mov r7, r12
	ldr r0, [r7, 0x74]
	cmp r1, r0
	beq _080259E8
_0802598E:
	adds r4, 0x2
	adds r2, 0x8
	adds r3, 0x1
	cmp r3, r6
	blt _0802597E
	movs r3, 0
	cmp r3, r6
	bge _080259E8
	ldr r1, [r5]
	movs r2, 0x84
	lsls r2, 1
	adds r0, r1, r2
	ldrh r0, [r0]
	cmp r0, 0
	bne _080259C4
	adds r0, r1, 0
	adds r0, 0xCC
	ldr r0, [r0]
	str r0, [r1, 0x74]
	b _080259E8
	.align 2, 0
_080259B8: .4byte gUnknown_203B2B4
_080259BC: .4byte gUnknown_80DD2B0
_080259C0: .4byte gUnknown_80D4970
_080259C4:
	adds r3, 0x1
	cmp r3, r6
	bge _080259E8
	ldr r2, [r5]
	lsls r0, r3, 1
	movs r4, 0x84
	lsls r4, 1
	adds r1, r2, r4
	adds r1, r0
	ldrh r0, [r1]
	cmp r0, 0
	bne _080259C4
	lsls r0, r3, 3
	adds r1, r2, 0
	adds r1, 0xCC
	adds r1, r0
	ldr r0, [r1]
	str r0, [r2, 0x74]
_080259E8:
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_802591C

	thumb_func_start sub_80259F0
sub_80259F0:
	push {lr}
	movs r0, 0x1
	bl sub_8023A94
	cmp r0, 0x3
	beq _08025A0C
	cmp r0, 0x3
	bhi _08025A06
	cmp r0, 0x2
	beq _08025A74
	b _08025A7E
_08025A06:
	cmp r0, 0x4
	beq _08025A40
	b _08025A7E
_08025A0C:
	bl sub_8023B44
	ldr r1, _08025A38
	ldr r1, [r1]
	strh r0, [r1, 0xE]
	ldr r3, _08025A3C
	movs r0, 0xE
	ldrsh r2, [r1, r0]
	movs r0, 0x58
	muls r2, r0
	ldr r0, [r3]
	adds r0, r2
	str r0, [r1, 0x1C]
	movs r2, 0xE
	ldrsh r0, [r1, r2]
	adds r1, 0x18
	bl sub_808D7DC
	movs r0, 0x3
	bl sub_8025434
	b _08025A7E
	.align 2, 0
_08025A38: .4byte gUnknown_203B2B4
_08025A3C: .4byte gUnknown_203B45C
_08025A40:
	bl sub_8023B44
	ldr r1, _08025A6C
	ldr r1, [r1]
	strh r0, [r1, 0xE]
	ldr r3, _08025A70
	movs r0, 0xE
	ldrsh r2, [r1, r0]
	movs r0, 0x58
	muls r2, r0
	ldr r0, [r3]
	adds r0, r2
	str r0, [r1, 0x1C]
	movs r2, 0xE
	ldrsh r0, [r1, r2]
	adds r1, 0x18
	bl sub_808D7DC
	movs r0, 0x4
	bl sub_8025434
	b _08025A7E
	.align 2, 0
_08025A6C: .4byte gUnknown_203B2B4
_08025A70: .4byte gUnknown_203B45C
_08025A74:
	bl sub_8023C60
	movs r0, 0x13
	bl sub_8025434
_08025A7E:
	pop {r0}
	bx r0
	thumb_func_end sub_80259F0

	thumb_func_start sub_8025A84
sub_8025A84:
	push {r4,lr}
	sub sp, 0x4
	movs r0, 0
	str r0, [sp]
	bl sub_8023A94
	ldr r4, _08025AC8
	ldr r0, [r4]
	adds r0, 0x78
	bl sub_8012FD8
	lsls r0, 24
	cmp r0, 0
	bne _08025AB4
	ldr r0, [r4]
	adds r0, 0x78
	mov r1, sp
	bl sub_8013114
	ldr r1, [sp]
	cmp r1, 0x1
	beq _08025AB4
	ldr r0, [r4]
	str r1, [r0, 0x70]
_08025AB4:
	ldr r0, [sp]
	subs r0, 0x1
	cmp r0, 0xA
	bls _08025ABE
	b _08025BC2
_08025ABE:
	lsls r0, 2
	ldr r1, _08025ACC
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08025AC8: .4byte gUnknown_203B2B4
_08025ACC: .4byte _08025AD0
	.align 2, 0
_08025AD0:
	.4byte _08025BBC
	.4byte _08025BC2
	.4byte _08025BC2
	.4byte _08025BAC
	.4byte _08025BB4
	.4byte _08025B9C
	.4byte _08025AFC
	.4byte _08025BA4
	.4byte _08025B70
	.4byte _08025B20
	.4byte _08025B28
_08025AFC:
	ldr r4, _08025B1C
	ldr r0, [r4]
	ldr r0, [r0, 0x1C]
	movs r1, 0x8
	ldrsh r0, [r0, r1]
	bl GetFriendArea
	ldr r1, [r4]
	strb r0, [r1, 0xD]
	bl sub_8023C60
	movs r0, 0x13
	bl sub_8025434
	b _08025BC2
	.align 2, 0
_08025B1C: .4byte gUnknown_203B2B4
_08025B20:
	movs r0, 0xB
	bl sub_8025434
	b _08025BC2
_08025B28:
	ldr r0, _08025B68
	bl sub_8011988
	ldr r4, _08025B6C
	ldr r1, [r4]
	ldrb r0, [r1, 0x18]
	cmp r0, 0
	beq _08025B40
	adds r0, r1, 0
	adds r0, 0x18
	bl sub_8091274
_08025B40:
	bl sub_80910B4
	ldr r0, [r4]
	movs r1, 0
	strb r1, [r0, 0x18]
	ldr r0, [r4]
	strb r1, [r0, 0x19]
	ldr r1, [r4]
	movs r2, 0xE
	ldrsh r0, [r1, r2]
	adds r1, 0x18
	bl sub_808D800
	bl nullsub_104
	movs r0, 0xA
	bl sub_8025434
	b _08025BC2
	.align 2, 0
_08025B68: .4byte 0x0000014d
_08025B6C: .4byte gUnknown_203B2B4
_08025B70:
	ldr r0, _08025B94
	ldr r0, [r0]
	ldr r2, [r0, 0x1C]
	ldrh r1, [r2]
	ldr r0, _08025B98
	ands r0, r1
	strh r0, [r2]
	bl nullsub_104
	bl sub_808ED00
	bl sub_8023C60
	movs r0, 0x7
	bl sub_8025434
	b _08025BC2
	.align 2, 0
_08025B94: .4byte gUnknown_203B2B4
_08025B98: .4byte 0x0000fffd
_08025B9C:
	movs r0, 0xF
	bl sub_8025434
	b _08025BC2
_08025BA4:
	movs r0, 0x12
	bl sub_8025434
	b _08025BC2
_08025BAC:
	movs r0, 0x4
	bl sub_8025434
	b _08025BC2
_08025BB4:
	movs r0, 0x5
	bl sub_8025434
	b _08025BC2
_08025BBC:
	movs r0, 0x2
	bl sub_8025434
_08025BC2:
	add sp, 0x4
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_8025A84

	thumb_func_start sub_8025BCC
sub_8025BCC:
	push {lr}
	bl sub_80244E4
	cmp r0, 0x1
	bls _08025BE4
	cmp r0, 0x3
	bhi _08025BE4
	bl sub_802453C
	movs r0, 0x2
	bl sub_8025434
_08025BE4:
	pop {r0}
	bx r0
	thumb_func_end sub_8025BCC

	thumb_func_start sub_8025BE8
sub_8025BE8:
	push {lr}
	bl sub_801BF48
	cmp r0, 0x1
	bls _08025C00
	cmp r0, 0x3
	bhi _08025C00
	bl sub_801BF98
	movs r0, 0x2
	bl sub_8025434
_08025C00:
	pop {r0}
	bx r0
	thumb_func_end sub_8025BE8

	thumb_func_start sub_8025C04
sub_8025C04:
	push {r4,lr}
	movs r0, 0x1
	bl sub_801A6E8
	cmp r0, 0x4
	bhi _08025CAE
	lsls r0, 2
	ldr r1, _08025C1C
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08025C1C: .4byte _08025C20
	.align 2, 0
_08025C20:
	.4byte _08025CAE
	.4byte _08025CAE
	.4byte _08025CA4
	.4byte _08025C34
	.4byte _08025C68
_08025C34:
	bl sub_801A8AC
	ldr r4, _08025C60
	ldr r2, [r4]
	str r0, [r2, 0x10]
	ldr r3, _08025C64
	ldr r1, [r3]
	lsls r0, 2
	adds r1, r0
	ldrb r0, [r1, 0x2]
	strb r0, [r2, 0x14]
	ldr r2, [r4]
	ldr r1, [r3]
	ldr r0, [r2, 0x10]
	lsls r0, 2
	adds r1, r0
	ldrb r0, [r1, 0x1]
	strb r0, [r2, 0x15]
	movs r0, 0xD
	bl sub_8025434
	b _08025CAE
	.align 2, 0
_08025C60: .4byte gUnknown_203B2B4
_08025C64: .4byte gUnknown_203B460
_08025C68:
	bl sub_801A8AC
	ldr r4, _08025C9C
	ldr r2, [r4]
	str r0, [r2, 0x10]
	ldr r3, _08025CA0
	ldr r1, [r3]
	lsls r0, 2
	adds r1, r0
	ldrb r0, [r1, 0x2]
	strb r0, [r2, 0x14]
	ldr r2, [r4]
	ldr r1, [r3]
	ldr r0, [r2, 0x10]
	lsls r0, 2
	adds r1, r0
	ldrb r0, [r1, 0x1]
	strb r0, [r2, 0x15]
	movs r0, 0
	bl sub_8099690
	movs r0, 0xE
	bl sub_8025434
	b _08025CAE
	.align 2, 0
_08025C9C: .4byte gUnknown_203B2B4
_08025CA0: .4byte gUnknown_203B460
_08025CA4:
	bl sub_801A928
	movs r0, 0x2
	bl sub_8025434
_08025CAE:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_8025C04

	thumb_func_start sub_8025CB4
sub_8025CB4:
	push {r4-r6,lr}
	sub sp, 0x14
	movs r0, 0
	str r0, [sp, 0xC]
	bl sub_801A6E8
	ldr r4, _08025CF4
	ldr r0, [r4]
	adds r0, 0x78
	bl sub_8012FD8
	lsls r0, 24
	cmp r0, 0
	bne _08025CE4
	ldr r0, [r4]
	adds r0, 0x78
	add r1, sp, 0xC
	bl sub_8013114
	ldr r1, [sp, 0xC]
	cmp r1, 0x1
	beq _08025CE4
	ldr r0, [r4]
	str r1, [r0, 0x74]
_08025CE4:
	ldr r0, [sp, 0xC]
	cmp r0, 0x4
	beq _08025D74
	cmp r0, 0x4
	bgt _08025CF8
	cmp r0, 0x1
	beq _08025D82
	b _08025D88
	.align 2, 0
_08025CF4: .4byte gUnknown_203B2B4
_08025CF8:
	cmp r0, 0xA
	bne _08025D88
	movs r6, 0x8
	ldr r0, _08025D68
	bl sub_8011988
	ldr r5, _08025D6C
	ldr r0, [r5]
	ldr r0, [r0, 0x10]
	bl sub_80911F8
	bl sub_80910B4
	ldr r1, [r5]
	ldrb r0, [r1, 0x18]
	cmp r0, 0
	beq _08025D24
	adds r0, r1, 0
	adds r0, 0x18
	bl sub_8091274
	movs r6, 0x9
_08025D24:
	add r4, sp, 0x10
	ldr r1, [r5]
	adds r1, 0x14
	adds r0, r4, 0
	bl sub_8090B64
	movs r1, 0
	str r1, [sp]
	mov r0, sp
	strb r1, [r0, 0x4]
	mov r1, sp
	movs r0, 0x1
	strb r0, [r1, 0x8]
	strb r0, [r4]
	ldr r0, _08025D70
	adds r1, r4, 0
	mov r2, sp
	bl sub_8090E14
	ldr r1, [r5]
	movs r2, 0xE
	ldrsh r0, [r1, r2]
	adds r1, 0x14
	bl sub_808D800
	bl sub_801A928
	bl nullsub_104
	adds r0, r6, 0
	bl sub_8025434
	b _08025D88
	.align 2, 0
_08025D68: .4byte 0x0000014d
_08025D6C: .4byte gUnknown_203B2B4
_08025D70: .4byte gUnknown_202DEA8
_08025D74:
	movs r0, 0
	bl sub_8099690
	movs r0, 0xE
	bl sub_8025434
	b _08025D88
_08025D82:
	movs r0, 0xC
	bl sub_8025434
_08025D88:
	add sp, 0x14
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end sub_8025CB4

	thumb_func_start sub_8025D90
sub_8025D90:
	push {lr}
	bl sub_801B410
	cmp r0, 0x1
	bls _08025DA8
	cmp r0, 0x3
	bhi _08025DA8
	bl sub_801B450
	movs r0, 0xC
	bl sub_8025434
_08025DA8:
	pop {r0}
	bx r0
	thumb_func_end sub_8025D90

	thumb_func_start sub_8025DAC
sub_8025DAC:
	push {lr}
	movs r0, 0x1
	bl sub_801EF38
	cmp r0, 0x3
	beq _08025DC6
	cmp r0, 0x3
	bhi _08025DC2
	cmp r0, 0x2
	beq _08025DE4
	b _08025DFE
_08025DC2:
	cmp r0, 0x4
	bne _08025DFE
_08025DC6:
	bl sub_801F194
	ldr r1, _08025DE0
	ldr r1, [r1]
	str r0, [r1, 0x20]
	lsls r0, 3
	adds r0, r1, r0
	ldrh r0, [r0, 0x2A]
	strh r0, [r1, 0x24]
	movs r0, 0x11
	bl sub_8025434
	b _08025DFE
	.align 2, 0
_08025DE0: .4byte gUnknown_203B2B4
_08025DE4:
	bl sub_801F214
	ldr r0, _08025E04
	ldr r1, [r0]
	adds r0, r1, 0
	adds r0, 0x28
	ldr r1, [r1, 0x1C]
	adds r1, 0x2C
	bl sub_8094060
	movs r0, 0x2
	bl sub_8025434
_08025DFE:
	pop {r0}
	bx r0
	.align 2, 0
_08025E04: .4byte gUnknown_203B2B4
	thumb_func_end sub_8025DAC

	thumb_func_start sub_8025E08
sub_8025E08:
	push {lr}
	bl sub_801F890
	cmp r0, 0x1
	bls _08025E20
	cmp r0, 0x3
	bhi _08025E20
	bl sub_801F8D0
	movs r0, 0x10
	bl sub_8025434
_08025E20:
	pop {r0}
	bx r0
	thumb_func_end sub_8025E08

	thumb_func_start sub_8025E24
sub_8025E24:
	push {lr}
	bl sub_8016080
	cmp r0, 0x3
	bhi _08025E40
	cmp r0, 0x2
	bcc _08025E40
	bl sub_80160D8
	bl nullsub_104
	movs r0, 0x2
	bl sub_8025434
_08025E40:
	pop {r0}
	bx r0
	thumb_func_end sub_8025E24

	thumb_func_start sub_8025E44
sub_8025E44:
	push {lr}
	sub sp, 0x4
	mov r0, sp
	bl sub_80144A4
	cmp r0, 0
	bne _08025E5C
	ldr r0, _08025E64
	ldr r0, [r0]
	ldr r0, [r0, 0x8]
	bl sub_8025434
_08025E5C:
	add sp, 0x4
	pop {r0}
	bx r0
	.align 2, 0
_08025E64: .4byte gUnknown_203B2B4
	thumb_func_end sub_8025E44

	thumb_func_start sub_8025E68
sub_8025E68:
	push {r4-r6,lr}
	sub sp, 0x14
	adds r6, r0, 0
	adds r5, r1, 0
	bl sub_8008C54
	adds r0, r6, 0
	bl sub_80073B8
	add r4, sp, 0x10
	adds r0, r4, 0
	adds r1, r5, 0
	bl sub_8090B64
	movs r5, 0
	str r5, [sp, 0x4]
	add r0, sp, 0x4
	strb r5, [r0, 0x4]
	adds r1, r0, 0
	movs r0, 0x1
	strb r0, [r1, 0x8]
	strb r0, [r4]
	ldr r0, _08025EBC
	adds r1, r4, 0
	add r2, sp, 0x4
	bl sub_8090E14
	ldr r2, _08025EC0
	str r5, [sp]
	movs r0, 0x4
	movs r1, 0x3
	adds r3, r6, 0
	bl sub_8014FF0
	adds r0, r6, 0
	bl sub_80073E0
	add sp, 0x14
	pop {r4-r6}
	pop {r0}
	bx r0
	.align 2, 0
_08025EBC: .4byte gUnknown_202DE58
_08025EC0: .4byte gUnknown_80DD2F8
	thumb_func_end sub_8025E68

	thumb_func_start sub_8025EC4
sub_8025EC4:
	push {lr}
	adds r1, r0, 0
	ldrb r0, [r1, 0x2]
	cmp r0, 0
	bne _08025EE8
	movs r2, 0
	ldrb r0, [r1, 0x4]
	cmp r0, 0x41
	bne _08025ED8
	movs r2, 0x1
_08025ED8:
	cmp r2, 0
	beq _08025EEC
	movs r0, 0x8
	bl sub_80023E4
	lsls r0, 24
	cmp r0, 0
	bne _08025EEC
_08025EE8:
	movs r0, 0
	b _08025EEE
_08025EEC:
	movs r0, 0x1
_08025EEE:
	pop {r1}
	bx r1
	thumb_func_end sub_8025EC4

	thumb_func_start sub_8025EF4
sub_8025EF4:
	push {r4-r6,lr}
	adds r4, r0, 0
	ldr r6, _08025F1C
	movs r0, 0xA0
	lsls r0, 2
	movs r1, 0x8
	bl MemoryAlloc
	adds r1, r0, 0
	str r1, [r6]
	str r4, [r1, 0x18]
	movs r5, 0
	ldr r0, _08025F20
	ldr r0, [r0]
	cmp r4, r0
	bne _08025F24
	strh r5, [r1, 0xA]
	adds r4, r6, 0
	b _08025F48
	.align 2, 0
_08025F1C: .4byte gUnknown_203B2B8
_08025F20: .4byte gUnknown_203B45C
_08025F24:
	adds r5, 0x1
	movs r0, 0xCE
	lsls r0, 1
	ldr r4, _08025F60
	cmp r5, r0
	bgt _08025F48
	ldr r3, [r4]
	ldr r2, _08025F64
	lsls r0, r5, 16
	asrs r0, 16
	movs r1, 0x58
	muls r1, r0
	ldr r0, [r2]
	adds r0, r1
	ldr r1, [r3, 0x18]
	cmp r1, r0
	bne _08025F24
	strh r5, [r3, 0xA]
_08025F48:
	ldr r1, [r4]
	movs r0, 0
	str r0, [r1, 0x70]
	str r0, [r1, 0x74]
	str r0, [r1, 0x78]
	strb r0, [r1, 0x8]
	bl sub_8026074
	movs r0, 0x1
	pop {r4-r6}
	pop {r1}
	bx r1
	.align 2, 0
_08025F60: .4byte gUnknown_203B2B8
_08025F64: .4byte gUnknown_203B45C
	thumb_func_end sub_8025EF4

	thumb_func_start sub_8025F68
sub_8025F68:
	push {lr}
	ldr r0, _08025F80
	ldr r0, [r0]
	ldr r0, [r0]
	cmp r0, 0x19
	bhi _0802603A
	lsls r0, 2
	ldr r1, _08025F84
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08025F80: .4byte gUnknown_203B2B8
_08025F84: .4byte _08025F88
	.align 2, 0
_08025F88:
	.4byte _08025FF0
	.4byte _08025FF8
	.4byte _08025FF8
	.4byte _08025FFE
	.4byte _08026004
	.4byte _0802603A
	.4byte _0802603A
	.4byte _0802603A
	.4byte _0802603A
	.4byte _0802603A
	.4byte _0802603A
	.4byte _0802603A
	.4byte _0802600A
	.4byte _08026010
	.4byte _08026016
	.4byte _0802603A
	.4byte _0802603A
	.4byte _0802603A
	.4byte _0802601C
	.4byte _0802601C
	.4byte _08026022
	.4byte _08026028
	.4byte _0802602E
	.4byte _0802602E
	.4byte _08026034
	.4byte _08026040
_08025FF0:
	movs r0, 0x1
	bl sub_8026074
	b _08026044
_08025FF8:
	bl sub_80268CC
	b _08026044
_08025FFE:
	bl sub_8026A78
	b _08026044
_08026004:
	bl sub_8026A94
	b _08026044
_0802600A:
	bl sub_8026AB0
	b _08026044
_08026010:
	bl sub_8026B10
	b _08026044
_08026016:
	bl sub_8026B48
	b _08026044
_0802601C:
	bl sub_8026B64
	b _08026044
_08026022:
	bl sub_8026C14
	b _08026044
_08026028:
	bl sub_8026CF0
	b _08026044
_0802602E:
	bl sub_8026D0C
	b _08026044
_08026034:
	bl sub_8026D6C
	b _08026044
_0802603A:
	bl sub_8026D88
	b _08026044
_08026040:
	movs r0, 0x3
	b _08026046
_08026044:
	movs r0, 0
_08026046:
	pop {r1}
	bx r1
	thumb_func_end sub_8025F68

	thumb_func_start sub_802604C
sub_802604C:
	ldr r0, _08026054
	ldr r0, [r0]
	ldrb r0, [r0, 0x8]
	bx lr
	.align 2, 0
_08026054: .4byte gUnknown_203B2B8
	thumb_func_end sub_802604C

	thumb_func_start sub_8026058
sub_8026058:
	push {r4,lr}
	ldr r4, _08026070
	ldr r0, [r4]
	cmp r0, 0
	beq _0802606A
	bl MemoryFree
	movs r0, 0
	str r0, [r4]
_0802606A:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08026070: .4byte gUnknown_203B2B8
	thumb_func_end sub_8026058

	thumb_func_start sub_8026074
sub_8026074:
	push {lr}
	ldr r1, _08026088
	ldr r1, [r1]
	str r0, [r1]
	bl sub_802608C
	bl sub_80261D0
	pop {r0}
	bx r0
	.align 2, 0
_08026088: .4byte gUnknown_203B2B8
	thumb_func_end sub_8026074

	thumb_func_start sub_802608C
sub_802608C:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	ldr r4, _080260B8
	ldr r0, [r4]
	movs r5, 0x88
	lsls r5, 2
	adds r0, r5
	bl sub_8006518
	ldr r0, [r4]
	ldr r0, [r0]
	cmp r0, 0x1
	blt _08026178
	cmp r0, 0x2
	ble _080260BC
	cmp r0, 0x14
	beq _0802614C
	b _08026178
	.align 2, 0
_080260B8: .4byte gUnknown_203B2B8
_080260BC:
	ldr r0, _0802613C
	mov r12, r0
	ldr r1, _08026140
	mov r8, r1
	mov r9, r4
	mov r10, r5
	movs r3, 0
	movs r2, 0x3
_080260CC:
	mov r5, r9
	ldr r1, [r5]
	adds r1, r3
	add r1, r10
	ldr r0, _08026144
	ldm r0!, {r5-r7}
	stm r1!, {r5-r7}
	ldm r0!, {r5-r7}
	stm r1!, {r5-r7}
	adds r3, 0x18
	subs r2, 0x1
	cmp r2, 0
	bge _080260CC
	ldr r1, [r4]
	movs r6, 0x88
	lsls r6, 2
	adds r1, r6
	mov r0, r12
	ldm r0!, {r2,r3,r7}
	stm r1!, {r2,r3,r7}
	ldm r0!, {r5-r7}
	stm r1!, {r5-r7}
	ldr r1, [r4]
	movs r0, 0x9A
	lsls r0, 2
	adds r1, r0
	mov r0, r8
	ldm r0!, {r2,r3,r5}
	stm r1!, {r2,r3,r5}
	ldm r0!, {r2,r6,r7}
	stm r1!, {r2,r6,r7}
	bl sub_80264CC
	ldr r2, [r4]
	movs r0, 0x94
	lsls r0, 2
	adds r2, r0
	ldr r1, _08026148
	ldm r1!, {r3,r5,r6}
	stm r2!, {r3,r5,r6}
	ldm r1!, {r3,r5,r7}
	stm r2!, {r3,r5,r7}
	ldr r1, [r4]
	adds r0, r1, r0
	movs r6, 0xB6
	lsls r6, 1
	adds r1, r6
	bl sub_8012CAC
	ldr r0, [r4]
	movs r7, 0x97
	lsls r7, 2
	adds r0, r7
	movs r1, 0x9
	strh r1, [r0]
	b _080261A2
	.align 2, 0
_0802613C: .4byte gUnknown_80DD358
_08026140: .4byte gUnknown_80DD370
_08026144: .4byte gUnknown_80DD310
_08026148: .4byte gUnknown_80DD328
_0802614C:
	bl sub_802678C
	ldr r2, [r4]
	movs r0, 0x94
	lsls r0, 2
	adds r2, r0
	ldr r1, _08026174
	ldm r1!, {r3,r5,r6}
	stm r2!, {r3,r5,r6}
	ldm r1!, {r3,r5,r7}
	stm r2!, {r3,r5,r7}
	ldr r1, [r4]
	adds r0, r1, r0
	movs r6, 0xB6
	lsls r6, 1
	adds r1, r6
	bl sub_8012CAC
	b _080261A2
	.align 2, 0
_08026174: .4byte gUnknown_80DD340
_08026178:
	ldr r7, _080261C8
	mov r8, r7
	movs r0, 0x88
	lsls r0, 2
	mov r9, r0
	ldr r4, _080261CC
	movs r3, 0
	movs r2, 0x3
_08026188:
	mov r5, r8
	ldr r1, [r5]
	adds r1, r3
	add r1, r9
	adds r0, r4, 0
	ldm r0!, {r5-r7}
	stm r1!, {r5-r7}
	ldm r0!, {r5-r7}
	stm r1!, {r5-r7}
	adds r3, 0x18
	subs r2, 0x1
	cmp r2, 0
	bge _08026188
_080261A2:
	bl sub_8004914
	ldr r0, _080261C8
	ldr r0, [r0]
	movs r6, 0x88
	lsls r6, 2
	adds r0, r6
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_080261C8: .4byte gUnknown_203B2B8
_080261CC: .4byte gUnknown_80DD310
	thumb_func_end sub_802608C

	thumb_func_start sub_80261D0
sub_80261D0:
	push {r4,r5,lr}
	sub sp, 0x18
	ldr r1, _080261EC
	ldr r0, [r1]
	ldr r0, [r0]
	adds r4, r1, 0
	cmp r0, 0x19
	bls _080261E2
	b _080264BA
_080261E2:
	lsls r0, 2
	ldr r1, _080261F0
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080261EC: .4byte gUnknown_203B2B8
_080261F0: .4byte _080261F4
	.align 2, 0
_080261F4:
	.4byte _080264BA
	.4byte _0802625C
	.4byte _080262A8
	.4byte _080262EC
	.4byte _080262FA
	.4byte _080263F8
	.4byte _0802640C
	.4byte _08026420
	.4byte _08026434
	.4byte _08026448
	.4byte _0802648A
	.4byte _080264A8
	.4byte _08026392
	.4byte _080263AC
	.4byte _08026306
	.4byte _08026464
	.4byte _08026474
	.4byte _08026484
	.4byte _08026310
	.4byte _0802631E
	.4byte _08026326
	.4byte _08026350
	.4byte _08026362
	.4byte _08026388
	.4byte _080263E0
	.4byte _080264BA
_0802625C:
	movs r0, 0x3
	bl sub_8026E08
	ldr r5, _080262A0
	ldr r1, [r5]
	adds r1, 0x14
	movs r0, 0
	bl sub_8026DAC
	ldr r4, _080262A4
	ldr r0, [r5]
	ldr r1, [r0, 0x18]
	adds r0, r4, 0
	movs r2, 0x7
	bl sub_808D9AC
	adds r4, 0x50
	ldr r0, [r5]
	ldr r1, [r0, 0x18]
	adds r0, r4, 0
	movs r2, 0x6
	bl sub_808D9AC
	ldr r2, [r5]
	adds r0, r2, 0
	adds r0, 0x7C
	movs r3, 0xB6
	lsls r3, 1
	adds r1, r2, r3
	movs r4, 0x83
	lsls r4, 2
	adds r3, r2, r4
	ldr r2, [r2, 0x70]
	b _0802633E
	.align 2, 0
_080262A0: .4byte gUnknown_203B2B8
_080262A4: .4byte gUnknown_202DF98
_080262A8:
	movs r0, 0x3
	bl sub_8026E08
	ldr r5, _080262E4
	ldr r1, [r5]
	adds r1, 0x14
	movs r0, 0
	bl sub_8026DAC
	ldr r4, _080262E8
	ldr r0, [r5]
	ldr r1, [r0, 0x18]
	adds r0, r4, 0
	movs r2, 0x7
	bl sub_808D9AC
	adds r4, 0x50
	ldr r0, [r5]
	ldr r1, [r0, 0x18]
	adds r0, r4, 0
	movs r2, 0x6
	bl sub_808D9AC
	ldr r0, [r5]
	adds r0, 0x7C
	movs r1, 0x1
	bl sub_8012EA4
	b _080264BA
	.align 2, 0
_080262E4: .4byte gUnknown_203B2B8
_080262E8: .4byte gUnknown_202DF98
_080262EC:
	ldr r0, [r4]
	movs r1, 0xA
	ldrsh r0, [r0, r1]
	movs r1, 0x2
	bl sub_8024458
	b _080264BA
_080262FA:
	ldr r0, [r4]
	movs r3, 0xA
	ldrsh r0, [r0, r3]
	bl sub_801BEEC
	b _080264BA
_08026306:
	ldr r0, [r4]
	ldr r0, [r0, 0x18]
	bl sub_80227B8
	b _080264BA
_08026310:
	movs r0, 0x1
	movs r1, 0
	movs r2, 0
	movs r3, 0xA
	bl sub_801A5D8
	b _080264BA
_0802631E:
	movs r0, 0x1
	bl sub_801A8D0
	b _080264BA
_08026326:
	bl sub_801A9E0
	ldr r0, _0802634C
	ldr r2, [r0]
	adds r0, r2, 0
	adds r0, 0xCC
	movs r4, 0xB6
	lsls r4, 1
	adds r1, r2, r4
	adds r4, 0xA0
	adds r3, r2, r4
	ldr r2, [r2, 0x74]
_0802633E:
	str r2, [sp]
	movs r2, 0x2
	str r2, [sp, 0x4]
	movs r2, 0
	bl sub_8012D60
	b _080264BA
	.align 2, 0
_0802634C: .4byte gUnknown_203B2B8
_08026350:
	ldr r1, [r4]
	adds r1, 0x10
	add r0, sp, 0x14
	bl sub_8090B64
	add r0, sp, 0x14
	bl sub_801B3C0
	b _080264BA
_08026362:
	ldr r1, [r4]
	adds r0, r1, 0
	adds r0, 0x28
	ldr r1, [r1, 0x18]
	adds r1, 0x2C
	bl sub_809401C
	ldr r2, [r4]
	movs r0, 0xA
	ldrsh r1, [r2, r0]
	adds r2, 0x28
	movs r0, 0
	str r0, [sp]
	str r0, [sp, 0x4]
	movs r0, 0x3
	movs r3, 0
	bl sub_801EE10
	b _080264BA
_08026388:
	movs r0, 0x1
	movs r1, 0
	bl sub_801F1B0
	b _080264BA
_08026392:
	bl sub_8026878
	ldr r0, _080263A4
	ldr r1, _080263A8
	ldr r3, [r1]
	movs r1, 0xDE
	lsls r1, 1
	adds r3, r1
	b _080263BC
	.align 2, 0
_080263A4: .4byte gUnknown_80DD388
_080263A8: .4byte gUnknown_203B2B8
_080263AC:
	bl sub_8026878
	ldr r0, _080263D8
	ldr r1, _080263DC
	ldr r3, [r1]
	movs r4, 0xDE
	lsls r4, 1
	adds r3, r4
_080263BC:
	movs r2, 0
	str r2, [sp]
	movs r1, 0x4
	str r1, [sp, 0x4]
	str r2, [sp, 0x8]
	str r2, [sp, 0xC]
	adds r1, 0xFD
	str r1, [sp, 0x10]
	movs r1, 0
	movs r2, 0x3
	bl sub_8014248
	b _080264BA
	.align 2, 0
_080263D8: .4byte gUnknown_80DD420
_080263DC: .4byte gUnknown_203B2B8
_080263E0:
	ldr r2, [r4]
	ldr r0, [r2, 0x20]
	adds r1, r2, 0
	adds r1, 0x28
	adds r2, 0x68
	bl sub_8093560
	ldr r0, [r4]
	adds r0, 0x68
	bl sub_801F808
	b _080264BA
_080263F8:
	ldr r1, [r4]
	movs r0, 0x19
	str r0, [r1, 0x4]
	movs r0, 0xCF
	bl sub_8011988
	ldr r0, _08026408
	b _08026492
	.align 2, 0
_08026408: .4byte gUnknown_80DD4C4
_0802640C:
	ldr r1, [r4]
	movs r0, 0x19
	str r0, [r1, 0x4]
	movs r0, 0xCF
	bl sub_8011988
	ldr r0, _0802641C
	b _08026492
	.align 2, 0
_0802641C: .4byte gUnknown_80DD4F4
_08026420:
	ldr r1, [r4]
	movs r0, 0x19
	str r0, [r1, 0x4]
	movs r0, 0xCC
	bl sub_8011988
	ldr r0, _08026430
	b _08026492
	.align 2, 0
_08026430: .4byte gUnknown_80DD534
_08026434:
	ldr r1, [r4]
	movs r0, 0x9
	str r0, [r1, 0x4]
	movs r0, 0xCA
	bl sub_8011988
	ldr r0, _08026444
	b _08026492
	.align 2, 0
_08026444: .4byte gUnknown_80DD564
_08026448:
	bl sub_8026FA4
	ldr r4, _08026460
	ldr r0, [r4]
	ldr r0, [r0, 0x18]
	bl sub_808D31C
	ldr r1, [r4]
	movs r0, 0x1
	strb r0, [r1, 0x8]
	b _080264BA
	.align 2, 0
_08026460: .4byte gUnknown_203B2B8
_08026464:
	ldr r1, [r4]
	movs r0, 0x2
	str r0, [r1, 0x4]
	ldr r0, _08026470
	b _08026492
	.align 2, 0
_08026470: .4byte gUnknown_80DD594
_08026474:
	ldr r1, [r4]
	movs r0, 0x2
	str r0, [r1, 0x4]
	ldr r0, _08026480
	b _08026492
	.align 2, 0
_08026480: .4byte gUnknown_80DD5B8
_08026484:
	ldr r1, [r4]
	movs r0, 0x2
	b _0802648E
_0802648A:
	ldr r1, [r4]
	movs r0, 0x19
_0802648E:
	str r0, [r1, 0x4]
	ldr r0, _080264A0
_08026492:
	ldr r3, _080264A4
	movs r1, 0
	movs r2, 0
	bl sub_80141B4
	b _080264BA
	.align 2, 0
_080264A0: .4byte gUnknown_80DD60C
_080264A4: .4byte 0x00000101
_080264A8:
	ldr r1, [r4]
	movs r0, 0x19
	str r0, [r1, 0x4]
	ldr r0, _080264C4
	ldr r3, _080264C8
	movs r1, 0
	movs r2, 0
	bl sub_80141B4
_080264BA:
	add sp, 0x18
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_080264C4: .4byte gUnknown_80DD63C
_080264C8: .4byte 0x00000101
	thumb_func_end sub_80261D0

	thumb_func_start sub_80264CC
sub_80264CC:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	ldr r3, _08026574
	ldr r4, _08026578
	ldr r0, [r4]
	movs r1, 0xA
	ldrsh r2, [r0, r1]
	movs r1, 0x58
	muls r2, r1
	ldr r1, [r3]
	adds r1, r2
	mov r8, r1
	movs r2, 0x83
	lsls r2, 2
	adds r0, r2
	movs r1, 0
	movs r2, 0x14
	bl MemoryFill16
	ldr r1, [r4]
	ldr r0, [r1, 0x18]
	ldrb r0, [r0, 0x2]
	strb r0, [r1, 0x1C]
	ldr r1, [r4]
	movs r3, 0xA
	ldrsh r0, [r1, r3]
	adds r1, 0x14
	bl sub_808D7DC
	mov r1, r8
	ldrh r0, [r1]
	lsrs r0, 1
	movs r5, 0x1
	ands r0, r5
	cmp r0, 0
	beq _08026584
	ldr r2, [r4]
	movs r3, 0xB6
	lsls r3, 1
	adds r1, r2, r3
	ldr r0, _0802657C
	str r0, [r1]
	movs r0, 0xB8
	lsls r0, 1
	adds r1, r2, r0
	movs r0, 0x7
	str r0, [r1]
	mov r0, r8
	bl sub_8026E88
	lsls r0, 24
	cmp r0, 0
	bne _08026542
	ldr r0, [r4]
	movs r1, 0x83
	lsls r1, 2
	adds r0, r1
	strh r5, [r0]
_08026542:
	movs r6, 0x1
	movs r0, 0x8
	bl sub_80023E4
	lsls r0, 24
	cmp r0, 0
	beq _080265B4
	mov r2, r8
	ldrb r0, [r2, 0x2]
	cmp r0, 0
	bne _080265B4
	ldr r3, [r4]
	movs r2, 0x8
	movs r4, 0xBA
	lsls r4, 1
	adds r1, r3, r4
	ldr r0, _08026580
	str r0, [r1]
	movs r1, 0xBC
	lsls r1, 1
	adds r0, r3, r1
	str r2, [r0]
	movs r6, 0x2
	b _080265B4
	.align 2, 0
_08026574: .4byte gUnknown_203B45C
_08026578: .4byte gUnknown_203B2B8
_0802657C: .4byte gUnknown_80DD664
_08026580: .4byte gUnknown_80DD670
_08026584:
	ldr r2, [r4]
	movs r3, 0xB6
	lsls r3, 1
	adds r1, r2, r3
	ldr r0, _08026734
	str r0, [r1]
	movs r0, 0xB8
	lsls r0, 1
	adds r1, r2, r0
	movs r0, 0x6
	str r0, [r1]
	movs r1, 0xA
	ldrsh r0, [r2, r1]
	bl sub_808D750
	lsls r0, 24
	cmp r0, 0
	bne _080265B2
	ldr r0, [r4]
	movs r2, 0x83
	lsls r2, 2
	adds r0, r2
	strh r5, [r0]
_080265B2:
	movs r6, 0x1
_080265B4:
	ldr r4, _08026738
	ldr r2, [r4]
	lsls r3, r6, 3
	movs r7, 0xB6
	lsls r7, 1
	adds r0, r2, r7
	adds r0, r3
	ldr r1, _0802673C
	str r1, [r0]
	movs r5, 0xB8
	lsls r5, 1
	adds r2, r5
	adds r2, r3
	movs r0, 0xA
	str r0, [r2]
	bl sub_809177C
	lsls r0, 24
	cmp r0, 0
	bne _080265EC
	ldr r0, [r4]
	lsls r1, r6, 1
	movs r3, 0x83
	lsls r3, 2
	adds r0, r3
	adds r0, r1
	movs r1, 0x1
	strh r1, [r0]
_080265EC:
	adds r6, 0x1
	ldr r2, [r4]
	lsls r3, r6, 3
	adds r0, r2, r7
	adds r0, r3
	ldr r1, _08026740
	str r1, [r0]
	adds r2, r5
	adds r2, r3
	movs r0, 0xB
	str r0, [r2]
	bl sub_8090A34
	cmp r0, 0
	bne _0802661A
	ldr r0, [r4]
	lsls r1, r6, 1
	movs r2, 0x83
	lsls r2, 2
	adds r0, r2
	adds r0, r1
	movs r1, 0x1
	strh r1, [r0]
_0802661A:
	adds r6, 0x1
	ldr r2, [r4]
	lsls r3, r6, 3
	adds r0, r2, r7
	adds r0, r3
	ldr r1, _08026744
	str r1, [r0]
	adds r2, r5
	adds r2, r3
	movs r0, 0xC
	str r0, [r2]
	bl sub_8090A34
	cmp r0, 0x13
	bgt _08026640
	ldr r0, [r4]
	ldrb r0, [r0, 0x14]
	cmp r0, 0
	bne _08026650
_08026640:
	ldr r0, [r4]
	lsls r1, r6, 1
	movs r3, 0x83
	lsls r3, 2
	adds r0, r3
	adds r0, r1
	movs r1, 0x1
	strh r1, [r0]
_08026650:
	adds r6, 0x1
	mov r4, r8
	ldrh r0, [r4]
	lsrs r0, 1
	movs r5, 0x1
	ands r0, r5
	cmp r0, 0
	bne _0802669A
	ldr r4, _08026738
	ldr r3, [r4]
	lsls r2, r6, 3
	movs r1, 0xB6
	lsls r1, 1
	adds r0, r3, r1
	adds r0, r2
	ldr r1, _08026748
	str r1, [r0]
	movs r1, 0xB8
	lsls r1, 1
	adds r0, r3, r1
	adds r0, r2
	movs r1, 0x9
	str r1, [r0]
	mov r0, r8
	bl sub_8026EB8
	lsls r0, 24
	cmp r0, 0
	bne _08026698
	ldr r0, [r4]
	lsls r1, r6, 1
	movs r2, 0x83
	lsls r2, 2
	adds r0, r2
	adds r0, r1
	strh r5, [r0]
_08026698:
	adds r6, 0x1
_0802669A:
	ldr r4, _08026738
	ldr r5, [r4]
	lsls r1, r6, 3
	movs r0, 0xB6
	lsls r0, 1
	adds r3, r5, r0
	adds r2, r3, r1
	ldr r0, _0802674C
	str r0, [r2]
	movs r2, 0xB8
	lsls r2, 1
	adds r7, r5, r2
	adds r1, r7, r1
	movs r0, 0x4
	str r0, [r1]
	adds r6, 0x1
	lsls r1, r6, 3
	adds r2, r3, r1
	ldr r0, _08026750
	str r0, [r2]
	adds r1, r7, r1
	movs r0, 0xD
	str r0, [r1]
	adds r6, 0x1
	lsls r1, r6, 3
	adds r2, r3, r1
	ldr r0, _08026754
	str r0, [r2]
	adds r1, r7, r1
	movs r0, 0x5
	str r0, [r1]
	adds r6, 0x1
	lsls r1, r6, 3
	adds r3, r1
	movs r0, 0
	str r0, [r3]
	adds r1, r7, r1
	movs r0, 0x1
	str r0, [r1]
	movs r3, 0
	mov r12, r4
	cmp r3, r6
	bge _08026710
	adds r4, r7, 0
	movs r0, 0x83
	lsls r0, 2
	adds r2, r5, r0
_080266F8:
	ldrh r0, [r2]
	cmp r0, 0
	bne _08026706
	ldr r1, [r4]
	ldr r0, [r5, 0x70]
	cmp r1, r0
	beq _08026780
_08026706:
	adds r4, 0x8
	adds r2, 0x2
	adds r3, 0x1
	cmp r3, r6
	blt _080266F8
_08026710:
	movs r3, 0
	cmp r3, r6
	bge _08026780
	mov r2, r12
	ldr r1, [r2]
	movs r4, 0x83
	lsls r4, 2
	adds r0, r1, r4
	ldrh r0, [r0]
	cmp r0, 0
	bne _08026758
	movs r2, 0xB8
	lsls r2, 1
	adds r0, r1, r2
	ldr r0, [r0]
	str r0, [r1, 0x70]
	b _08026780
	.align 2, 0
_08026734: .4byte gUnknown_80DD67C
_08026738: .4byte gUnknown_203B2B8
_0802673C: .4byte gUnknown_80DD688
_08026740: .4byte gUnknown_80DD694
_08026744: .4byte gUnknown_80DD69C
_08026748: .4byte gUnknown_80DD6A4
_0802674C: .4byte gUnknown_80DD6B4
_08026750: .4byte gUnknown_80DD6BC
_08026754: .4byte gUnknown_80DD6C4
_08026758:
	adds r3, 0x1
	cmp r3, r6
	bge _08026780
	mov r4, r12
	ldr r2, [r4]
	lsls r0, r3, 1
	movs r4, 0x83
	lsls r4, 2
	adds r1, r2, r4
	adds r1, r0
	ldrh r0, [r1]
	cmp r0, 0
	bne _08026758
	lsls r0, r3, 3
	movs r3, 0xB8
	lsls r3, 1
	adds r1, r2, r3
	adds r1, r0
	ldr r0, [r1]
	str r0, [r2, 0x70]
_08026780:
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_80264CC

	thumb_func_start sub_802678C
sub_802678C:
	push {r4-r7,lr}
	ldr r5, _08026840
	ldr r0, [r5]
	movs r7, 0x83
	lsls r7, 2
	adds r0, r7
	movs r1, 0
	movs r2, 0x14
	bl MemoryFill16
	ldr r2, [r5]
	movs r0, 0xB6
	lsls r0, 1
	adds r1, r2, r0
	ldr r0, _08026844
	str r0, [r1]
	movs r3, 0xB8
	lsls r3, 1
	adds r1, r2, r3
	movs r0, 0xB
	str r0, [r1]
	bl sub_8090A34
	cmp r0, 0
	bne _080267C8
	ldr r0, [r5]
	adds r4, r7, 0
	adds r0, r4
	movs r1, 0x1
	strh r1, [r0]
_080267C8:
	ldr r4, [r5]
	movs r2, 0x1
	movs r0, 0xBA
	lsls r0, 1
	adds r1, r4, r0
	ldr r0, _08026848
	ldr r0, [r0]
	str r0, [r1]
	movs r3, 0xBC
	lsls r3, 1
	adds r1, r4, r3
	movs r0, 0x4
	str r0, [r1]
	movs r6, 0x2
	movs r0, 0xBE
	lsls r0, 1
	adds r1, r4, r0
	movs r0, 0
	str r0, [r1]
	movs r1, 0xC0
	lsls r1, 1
	adds r0, r4, r1
	str r2, [r0]
	movs r3, 0
	mov r12, r4
	movs r4, 0xB8
	lsls r4, 1
	add r4, r12
	mov r0, r12
	adds r2, r0, r7
_08026804:
	ldrh r0, [r2]
	cmp r0, 0
	bne _08026814
	ldr r1, [r4]
	mov r7, r12
	ldr r0, [r7, 0x74]
	cmp r1, r0
	beq _08026872
_08026814:
	adds r4, 0x8
	adds r2, 0x2
	adds r3, 0x1
	cmp r3, r6
	blt _08026804
	movs r3, 0
	cmp r3, r6
	bge _08026872
	ldr r1, [r5]
	movs r2, 0x83
	lsls r2, 2
	adds r0, r1, r2
	ldrh r0, [r0]
	cmp r0, 0
	bne _0802684C
	movs r3, 0xB8
	lsls r3, 1
	adds r0, r1, r3
	ldr r0, [r0]
	str r0, [r1, 0x74]
	b _08026872
	.align 2, 0
_08026840: .4byte gUnknown_203B2B8
_08026844: .4byte gUnknown_80DD694
_08026848: .4byte gUnknown_80D4970
_0802684C:
	adds r3, 0x1
	cmp r3, r6
	bge _08026872
	ldr r2, [r5]
	lsls r0, r3, 1
	movs r4, 0x83
	lsls r4, 2
	adds r1, r2, r4
	adds r1, r0
	ldrh r0, [r1]
	cmp r0, 0
	bne _0802684C
	lsls r0, r3, 3
	movs r7, 0xB8
	lsls r7, 1
	adds r1, r2, r7
	adds r1, r0
	ldr r0, [r1]
	str r0, [r2, 0x74]
_08026872:
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_802678C

	thumb_func_start sub_8026878
sub_8026878:
	ldr r0, _080268C0
	ldr r0, [r0]
	mov r12, r0
	movs r3, 0
	movs r1, 0xDE
	lsls r1, 1
	add r1, r12
	ldr r0, _080268C4
	ldr r0, [r0]
	str r0, [r1]
	movs r1, 0xE0
	lsls r1, 1
	add r1, r12
	movs r0, 0x2
	str r0, [r1]
	movs r2, 0x1
	movs r1, 0xE2
	lsls r1, 1
	add r1, r12
	ldr r0, _080268C8
	ldr r0, [r0]
	str r0, [r1]
	movs r1, 0xE4
	lsls r1, 1
	add r1, r12
	movs r0, 0x3
	str r0, [r1]
	movs r0, 0xE6
	lsls r0, 1
	add r0, r12
	str r3, [r0]
	movs r0, 0xE8
	lsls r0, 1
	add r0, r12
	str r2, [r0]
	bx lr
	.align 2, 0
_080268C0: .4byte gUnknown_203B2B8
_080268C4: .4byte gUnknown_80D4920
_080268C8: .4byte gUnknown_80D4928
	thumb_func_end sub_8026878

	thumb_func_start sub_80268CC
sub_80268CC:
	push {r4,lr}
	sub sp, 0x4
	movs r0, 0
	str r0, [sp]
	ldr r4, _0802690C
	ldr r0, [r4]
	adds r0, 0x7C
	bl sub_8012FD8
	lsls r0, 24
	cmp r0, 0
	bne _080268F8
	ldr r0, [r4]
	adds r0, 0x7C
	mov r1, sp
	bl sub_8013114
	ldr r1, [sp]
	cmp r1, 0x1
	beq _080268F8
	ldr r0, [r4]
	str r1, [r0, 0x70]
_080268F8:
	ldr r0, [sp]
	subs r0, 0x1
	cmp r0, 0xC
	bls _08026902
	b _08026A6E
_08026902:
	lsls r0, 2
	ldr r1, _08026910
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0802690C: .4byte gUnknown_203B2B8
_08026910: .4byte _08026914
	.align 2, 0
_08026914:
	.4byte _08026A68
	.4byte _08026A6E
	.4byte _08026A6E
	.4byte _08026A58
	.4byte _08026A60
	.4byte _08026948
	.4byte _0802698C
	.4byte _080269B4
	.4byte _080269F0
	.4byte _08026A00
	.4byte _08026A08
	.4byte _08026A10
	.4byte _080269F8
_08026948:
	ldr r4, _08026984
	ldr r0, [r4]
	movs r1, 0xA
	ldrsh r0, [r0, r1]
	bl sub_808D750
	lsls r0, 24
	cmp r0, 0
	beq _08026976
	ldr r0, [r4]
	movs r2, 0xA
	ldrsh r1, [r0, r2]
	movs r0, 0x58
	muls r1, r0
	ldr r0, _08026988
	ldr r0, [r0]
	adds r1, r0
	ldrh r2, [r1]
	movs r0, 0x2
	orrs r0, r2
	strh r0, [r1]
	bl nullsub_104
_08026976:
	bl sub_808ED00
	movs r0, 0x5
	bl sub_8026074
	b _08026A6E
	.align 2, 0
_08026984: .4byte gUnknown_203B2B8
_08026988: .4byte gUnknown_203B45C
_0802698C:
	ldr r0, _080269AC
	ldr r0, [r0]
	ldr r2, [r0, 0x18]
	ldrh r1, [r2]
	ldr r0, _080269B0
	ands r0, r1
	strh r0, [r2]
	bl nullsub_104
	bl sub_808ED00
	movs r0, 0x6
	bl sub_8026074
	b _08026A6E
	.align 2, 0
_080269AC: .4byte gUnknown_203B2B8
_080269B0: .4byte 0x0000fffd
_080269B4:
	ldr r2, _080269E8
	ldr r0, _080269EC
	ldr r0, [r0]
	movs r3, 0xA
	ldrsh r1, [r0, r3]
	movs r0, 0x58
	muls r1, r0
	ldr r0, [r2]
	adds r4, r0, r1
	bl sub_808D33C
	ldrb r1, [r4, 0x2]
	cmp r1, 0
	bne _080269DA
	strb r1, [r0, 0x2]
	movs r0, 0x1
	strb r0, [r4, 0x2]
	bl nullsub_104
_080269DA:
	bl sub_808ED00
	movs r0, 0x7
	bl sub_8026074
	b _08026A6E
	.align 2, 0
_080269E8: .4byte gUnknown_203B45C
_080269EC: .4byte gUnknown_203B2B8
_080269F0:
	movs r0, 0xC
	bl sub_8026074
	b _08026A6E
_080269F8:
	movs r0, 0x16
	bl sub_8026074
	b _08026A6E
_08026A00:
	movs r0, 0xE
	bl sub_8026074
	b _08026A6E
_08026A08:
	movs r0, 0x12
	bl sub_8026074
	b _08026A6E
_08026A10:
	ldr r0, _08026A50
	bl sub_8011988
	ldr r4, _08026A54
	ldr r1, [r4]
	ldrb r0, [r1, 0x14]
	cmp r0, 0
	beq _08026A28
	adds r0, r1, 0
	adds r0, 0x14
	bl sub_8091274
_08026A28:
	bl sub_80910B4
	ldr r0, [r4]
	movs r1, 0
	strb r1, [r0, 0x14]
	ldr r0, [r4]
	strb r1, [r0, 0x15]
	ldr r1, [r4]
	movs r2, 0xA
	ldrsh r0, [r1, r2]
	adds r1, 0x14
	bl sub_808D800
	bl nullsub_104
	movs r0, 0x11
	bl sub_8026074
	b _08026A6E
	.align 2, 0
_08026A50: .4byte 0x0000014d
_08026A54: .4byte gUnknown_203B2B8
_08026A58:
	movs r0, 0x3
	bl sub_8026074
	b _08026A6E
_08026A60:
	movs r0, 0x4
	bl sub_8026074
	b _08026A6E
_08026A68:
	movs r0, 0x19
	bl sub_8026074
_08026A6E:
	add sp, 0x4
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_80268CC

	thumb_func_start sub_8026A78
sub_8026A78:
	push {lr}
	bl sub_80244E4
	cmp r0, 0x1
	bls _08026A90
	cmp r0, 0x3
	bhi _08026A90
	bl sub_802453C
	movs r0, 0x2
	bl sub_8026074
_08026A90:
	pop {r0}
	bx r0
	thumb_func_end sub_8026A78

	thumb_func_start sub_8026A94
sub_8026A94:
	push {lr}
	bl sub_801BF48
	cmp r0, 0x1
	bls _08026AAC
	cmp r0, 0x3
	bhi _08026AAC
	bl sub_801BF98
	movs r0, 0x2
	bl sub_8026074
_08026AAC:
	pop {r0}
	bx r0
	thumb_func_end sub_8026A94

	thumb_func_start sub_8026AB0
sub_8026AB0:
	push {lr}
	sub sp, 0x4
	mov r0, sp
	bl sub_80144A4
	cmp r0, 0
	bne _08026B08
	ldr r0, [sp]
	cmp r0, 0x2
	beq _08026ADA
	cmp r0, 0x2
	bgt _08026ACE
	cmp r0, 0x1
	beq _08026AD2
	b _08026B08
_08026ACE:
	cmp r0, 0x3
	bne _08026B08
_08026AD2:
	movs r0, 0x2
	bl sub_8026074
	b _08026B08
_08026ADA:
	ldr r0, _08026AF0
	ldr r0, [r0]
	ldr r0, [r0, 0x18]
	ldrb r0, [r0, 0x4]
	subs r0, 0x44
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bhi _08026AF4
	movs r0, 0x1
	b _08026AF6
	.align 2, 0
_08026AF0: .4byte gUnknown_203B2B8
_08026AF4:
	movs r0, 0
_08026AF6:
	cmp r0, 0
	beq _08026B02
	movs r0, 0xD
	bl sub_8026074
	b _08026B08
_08026B02:
	movs r0, 0x8
	bl sub_8026074
_08026B08:
	add sp, 0x4
	pop {r0}
	bx r0
	thumb_func_end sub_8026AB0

	thumb_func_start sub_8026B10
sub_8026B10:
	push {lr}
	sub sp, 0x4
	mov r0, sp
	bl sub_80144A4
	cmp r0, 0
	bne _08026B40
	ldr r0, [sp]
	cmp r0, 0x2
	beq _08026B3A
	cmp r0, 0x2
	bgt _08026B2E
	cmp r0, 0x1
	beq _08026B32
	b _08026B40
_08026B2E:
	cmp r0, 0x3
	bne _08026B40
_08026B32:
	movs r0, 0x2
	bl sub_8026074
	b _08026B40
_08026B3A:
	movs r0, 0x8
	bl sub_8026074
_08026B40:
	add sp, 0x4
	pop {r0}
	bx r0
	thumb_func_end sub_8026B10

	thumb_func_start sub_8026B48
sub_8026B48:
	push {lr}
	bl sub_8022860
	cmp r0, 0x1
	bls _08026B60
	cmp r0, 0x3
	bhi _08026B60
	bl sub_8022908
	movs r0, 0x2
	bl sub_8026074
_08026B60:
	pop {r0}
	bx r0
	thumb_func_end sub_8026B48

	thumb_func_start sub_8026B64
sub_8026B64:
	push {r4,lr}
	movs r0, 0x1
	bl sub_801A6E8
	cmp r0, 0x4
	bhi _08026C0E
	lsls r0, 2
	ldr r1, _08026B7C
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08026B7C: .4byte _08026B80
	.align 2, 0
_08026B80:
	.4byte _08026C0E
	.4byte _08026C0E
	.4byte _08026C04
	.4byte _08026B94
	.4byte _08026BC8
_08026B94:
	bl sub_801A8AC
	ldr r4, _08026BC0
	ldr r2, [r4]
	str r0, [r2, 0xC]
	ldr r3, _08026BC4
	ldr r1, [r3]
	lsls r0, 2
	adds r1, r0
	ldrb r0, [r1, 0x2]
	strb r0, [r2, 0x10]
	ldr r2, [r4]
	ldr r1, [r3]
	ldr r0, [r2, 0xC]
	lsls r0, 2
	adds r1, r0
	ldrb r0, [r1, 0x1]
	strb r0, [r2, 0x11]
	movs r0, 0x14
	bl sub_8026074
	b _08026C0E
	.align 2, 0
_08026BC0: .4byte gUnknown_203B2B8
_08026BC4: .4byte gUnknown_203B460
_08026BC8:
	bl sub_801A8AC
	ldr r4, _08026BFC
	ldr r2, [r4]
	str r0, [r2, 0xC]
	ldr r3, _08026C00
	ldr r1, [r3]
	lsls r0, 2
	adds r1, r0
	ldrb r0, [r1, 0x2]
	strb r0, [r2, 0x10]
	ldr r2, [r4]
	ldr r1, [r3]
	ldr r0, [r2, 0xC]
	lsls r0, 2
	adds r1, r0
	ldrb r0, [r1, 0x1]
	strb r0, [r2, 0x11]
	movs r0, 0
	bl sub_8099690
	movs r0, 0x15
	bl sub_8026074
	b _08026C0E
	.align 2, 0
_08026BFC: .4byte gUnknown_203B2B8
_08026C00: .4byte gUnknown_203B460
_08026C04:
	bl sub_801A928
	movs r0, 0x2
	bl sub_8026074
_08026C0E:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_8026B64

	thumb_func_start sub_8026C14
sub_8026C14:
	push {r4-r6,lr}
	sub sp, 0x14
	movs r0, 0
	str r0, [sp, 0xC]
	bl sub_801A6E8
	ldr r4, _08026C54
	ldr r0, [r4]
	adds r0, 0xCC
	bl sub_8012FD8
	lsls r0, 24
	cmp r0, 0
	bne _08026C44
	ldr r0, [r4]
	adds r0, 0xCC
	add r1, sp, 0xC
	bl sub_8013114
	ldr r1, [sp, 0xC]
	cmp r1, 0x1
	beq _08026C44
	ldr r0, [r4]
	str r1, [r0, 0x74]
_08026C44:
	ldr r0, [sp, 0xC]
	cmp r0, 0x4
	beq _08026CD4
	cmp r0, 0x4
	bgt _08026C58
	cmp r0, 0x1
	beq _08026CE2
	b _08026CE8
	.align 2, 0
_08026C54: .4byte gUnknown_203B2B8
_08026C58:
	cmp r0, 0xB
	bne _08026CE8
	movs r6, 0xF
	ldr r0, _08026CC8
	bl sub_8011988
	ldr r5, _08026CCC
	ldr r0, [r5]
	ldr r0, [r0, 0xC]
	bl sub_80911F8
	bl sub_80910B4
	ldr r1, [r5]
	ldrb r0, [r1, 0x14]
	cmp r0, 0
	beq _08026C84
	adds r0, r1, 0
	adds r0, 0x14
	bl sub_8091274
	movs r6, 0x10
_08026C84:
	add r4, sp, 0x10
	ldr r1, [r5]
	adds r1, 0x10
	adds r0, r4, 0
	bl sub_8090B64
	movs r1, 0
	str r1, [sp]
	mov r0, sp
	strb r1, [r0, 0x4]
	mov r1, sp
	movs r0, 0x1
	strb r0, [r1, 0x8]
	strb r0, [r4]
	ldr r0, _08026CD0
	adds r1, r4, 0
	mov r2, sp
	bl sub_8090E14
	ldr r1, [r5]
	movs r2, 0xA
	ldrsh r0, [r1, r2]
	adds r1, 0x10
	bl sub_808D800
	bl sub_801A928
	bl nullsub_104
	adds r0, r6, 0
	bl sub_8026074
	b _08026CE8
	.align 2, 0
_08026CC8: .4byte 0x0000014d
_08026CCC: .4byte gUnknown_203B2B8
_08026CD0: .4byte gUnknown_202DEA8
_08026CD4:
	movs r0, 0
	bl sub_8099690
	movs r0, 0x15
	bl sub_8026074
	b _08026CE8
_08026CE2:
	movs r0, 0x13
	bl sub_8026074
_08026CE8:
	add sp, 0x14
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end sub_8026C14

	thumb_func_start sub_8026CF0
sub_8026CF0:
	push {lr}
	bl sub_801B410
	cmp r0, 0x1
	bls _08026D08
	cmp r0, 0x3
	bhi _08026D08
	bl sub_801B450
	movs r0, 0x13
	bl sub_8026074
_08026D08:
	pop {r0}
	bx r0
	thumb_func_end sub_8026CF0

	thumb_func_start sub_8026D0C
sub_8026D0C:
	push {lr}
	movs r0, 0x1
	bl sub_801EF38
	cmp r0, 0x4
	bhi _08026D66
	lsls r0, 2
	ldr r1, _08026D24
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08026D24: .4byte _08026D28
	.align 2, 0
_08026D28:
	.4byte _08026D66
	.4byte _08026D66
	.4byte _08026D5C
	.4byte _08026D3C
	.4byte _08026D3C
_08026D3C:
	bl sub_801F194
	ldr r1, _08026D58
	ldr r1, [r1]
	str r0, [r1, 0x20]
	lsls r0, 3
	adds r0, r1, r0
	ldrh r0, [r0, 0x2A]
	strh r0, [r1, 0x24]
	movs r0, 0x18
	bl sub_8026074
	b _08026D66
	.align 2, 0
_08026D58: .4byte gUnknown_203B2B8
_08026D5C:
	bl sub_801F214
	movs r0, 0x2
	bl sub_8026074
_08026D66:
	pop {r0}
	bx r0
	thumb_func_end sub_8026D0C

	thumb_func_start sub_8026D6C
sub_8026D6C:
	push {lr}
	bl sub_801F890
	cmp r0, 0x1
	bls _08026D84
	cmp r0, 0x3
	bhi _08026D84
	bl sub_801F8D0
	movs r0, 0x17
	bl sub_8026074
_08026D84:
	pop {r0}
	bx r0
	thumb_func_end sub_8026D6C

	thumb_func_start sub_8026D88
sub_8026D88:
	push {lr}
	sub sp, 0x4
	mov r0, sp
	bl sub_80144A4
	cmp r0, 0
	bne _08026DA0
	ldr r0, _08026DA8
	ldr r0, [r0]
	ldr r0, [r0, 0x4]
	bl sub_8026074
_08026DA0:
	add sp, 0x4
	pop {r0}
	bx r0
	.align 2, 0
_08026DA8: .4byte gUnknown_203B2B8
	thumb_func_end sub_8026D88

	thumb_func_start sub_8026DAC
sub_8026DAC:
	push {r4-r6,lr}
	sub sp, 0x14
	adds r6, r0, 0
	adds r5, r1, 0
	bl sub_8008C54
	adds r0, r6, 0
	bl sub_80073B8
	add r4, sp, 0x10
	adds r0, r4, 0
	adds r1, r5, 0
	bl sub_8090B64
	movs r5, 0
	str r5, [sp, 0x4]
	add r0, sp, 0x4
	strb r5, [r0, 0x4]
	adds r1, r0, 0
	movs r0, 0x1
	strb r0, [r1, 0x8]
	strb r0, [r4]
	ldr r0, _08026E00
	adds r1, r4, 0
	add r2, sp, 0x4
	bl sub_8090E14
	ldr r2, _08026E04
	str r5, [sp]
	movs r0, 0x4
	movs r1, 0x3
	adds r3, r6, 0
	bl sub_8014FF0
	adds r0, r6, 0
	bl sub_80073E0
	add sp, 0x14
	pop {r4-r6}
	pop {r0}
	bx r0
	.align 2, 0
_08026E00: .4byte gUnknown_202DE58
_08026E04: .4byte gUnknown_80DD6D0
	thumb_func_end sub_8026DAC

	thumb_func_start sub_8026E08
sub_8026E08:
	push {r4-r6,lr}
	sub sp, 0x40
	adds r5, r0, 0
	bl sub_8008C54
	adds r0, r5, 0
	bl sub_80073B8
	ldr r6, _08026E78
	ldr r4, _08026E7C
	ldr r0, [r4]
	ldr r1, [r0, 0x18]
	adds r1, 0x4C
	adds r0, r6, 0
	movs r2, 0xA
	bl sub_80922B4
	add r0, sp, 0x2C
	ldr r1, [r4]
	ldr r1, [r1, 0x18]
	movs r2, 0x8
	ldrsh r1, [r1, r2]
	bl sub_808D930
	ldr r1, _08026E80
	add r0, sp, 0x4
	adds r2, r6, 0
	bl sub_800D158
	add r0, sp, 0x4
	bl sub_8008ED0
	adds r1, r0, 0
	ldr r0, _08026E84
	movs r2, 0xC
	ldrsh r0, [r0, r2]
	lsls r0, 3
	subs r0, r1
	lsrs r1, r0, 31
	adds r0, r1
	asrs r0, 1
	movs r1, 0
	str r1, [sp]
	movs r1, 0x3
	add r2, sp, 0x4
	adds r3, r5, 0
	bl xxx_call_draw_string
	adds r0, r5, 0
	bl sub_80073E0
	add sp, 0x40
	pop {r4-r6}
	pop {r0}
	bx r0
	.align 2, 0
_08026E78: .4byte gUnknown_202DF98
_08026E7C: .4byte gUnknown_203B2B8
_08026E80: .4byte gUnknown_80DD6E0
_08026E84: .4byte gUnknown_80DD370
	thumb_func_end sub_8026E08

	thumb_func_start sub_8026E88
sub_8026E88:
	push {lr}
	adds r1, r0, 0
	ldrb r0, [r1, 0x2]
	cmp r0, 0
	bne _08026EAC
	movs r2, 0
	ldrb r0, [r1, 0x4]
	cmp r0, 0x41
	bne _08026E9C
	movs r2, 0x1
_08026E9C:
	cmp r2, 0
	beq _08026EB0
	movs r0, 0x8
	bl sub_80023E4
	lsls r0, 24
	cmp r0, 0
	bne _08026EB0
_08026EAC:
	movs r0, 0
	b _08026EB2
_08026EB0:
	movs r0, 0x1
_08026EB2:
	pop {r1}
	bx r1
	thumb_func_end sub_8026E88

	thumb_func_start sub_8026EB8
sub_8026EB8:
	push {r4,lr}
	adds r4, r0, 0
	bl sub_808D3BC
	cmp r0, r4
	beq _08026EFA
	bl sub_808D3F8
	cmp r0, r4
	beq _08026EFA
	ldrb r0, [r4, 0x2]
	cmp r0, 0
	bne _08026EFA
	movs r1, 0
	ldrb r0, [r4, 0x4]
	cmp r0, 0x41
	bne _08026EDC
	movs r1, 0x1
_08026EDC:
	cmp r1, 0
	beq _08026EEC
	movs r0, 0x8
	bl sub_80023E4
	lsls r0, 24
	cmp r0, 0
	beq _08026EFA
_08026EEC:
	adds r0, r4, 0
	bl sub_8026F04
	cmp r0, 0x3
	beq _08026EFA
	movs r0, 0x1
	b _08026EFC
_08026EFA:
	movs r0, 0
_08026EFC:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_8026EB8

	thumb_func_start sub_8026F04
sub_8026F04:
	push {r4,lr}
	adds r4, r0, 0
	adds r0, 0x28
	ldrb r0, [r0]
	cmp r0, 0
	bne _08026F14
	movs r0, 0
	b _08026F32
_08026F14:
	bl sub_8090A34
	cmp r0, 0x13
	bgt _08026F20
	movs r0, 0x1
	b _08026F32
_08026F20:
	adds r0, r4, 0
	bl sub_8026F38
	lsls r0, 24
	cmp r0, 0
	bne _08026F30
	movs r0, 0x3
	b _08026F32
_08026F30:
	movs r0, 0x2
_08026F32:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_8026F04

	thumb_func_start sub_8026F38
sub_8026F38:
	push {r4,r5,lr}
	adds r5, r0, 0
	adds r4, r5, 0
	adds r4, 0x28
	ldrb r0, [r4]
	bl sub_8091524
	lsls r0, 24
	cmp r0, 0
	beq _08026F74
	ldrb r0, [r4]
	bl sub_8090A60
	lsls r0, 24
	cmp r0, 0
	beq _08026F80
	ldr r0, _08026F78
	ldr r1, [r0]
	ldrb r0, [r4]
	lsls r0, 1
	adds r1, 0x50
	adds r1, r0
	ldrh r1, [r1]
	adds r0, r5, 0
	adds r0, 0x29
	ldrb r0, [r0]
	adds r1, r0
	ldr r0, _08026F7C
	cmp r1, r0
	ble _08026F94
_08026F74:
	movs r0, 0
	b _08026F96
	.align 2, 0
_08026F78: .4byte gUnknown_203B460
_08026F7C: .4byte 0x000003e7
_08026F80:
	ldr r0, _08026F9C
	ldr r1, [r0]
	ldrb r0, [r4]
	lsls r0, 1
	adds r1, 0x50
	adds r1, r0
	ldrh r1, [r1]
	ldr r0, _08026FA0
	cmp r1, r0
	bhi _08026F74
_08026F94:
	movs r0, 0x1
_08026F96:
	pop {r4,r5}
	pop {r1}
	bx r1
	.align 2, 0
_08026F9C: .4byte gUnknown_203B460
_08026FA0: .4byte 0x000003e6
	thumb_func_end sub_8026F38

	thumb_func_start sub_8026FA4
sub_8026FA4:
	push {r4,lr}
	ldr r4, _08026FC0
	ldr r0, [r4]
	ldr r0, [r0, 0x18]
	bl sub_8026F04
	cmp r0, 0x1
	beq _08026FC4
	cmp r0, 0x1
	bcc _08027068
	cmp r0, 0x2
	beq _08026FF8
	b _08027068
	.align 2, 0
_08026FC0: .4byte gUnknown_203B2B8
_08026FC4:
	ldr r0, _08026FF4
	bl sub_8011988
	ldr r0, [r4]
	adds r0, 0x14
	bl sub_8091274
	bl sub_80910B4
	ldr r0, [r4]
	movs r1, 0
	strb r1, [r0, 0x14]
	ldr r0, [r4]
	strb r1, [r0, 0x15]
	ldr r1, [r4]
	movs r2, 0xA
	ldrsh r0, [r1, r2]
	adds r1, 0x14
	bl sub_808D800
	movs r0, 0xA
	bl sub_8026074
	b _0802706E
	.align 2, 0
_08026FF4: .4byte 0x0000014d
_08026FF8:
	ldr r0, _08027024
	bl sub_8011988
	ldr r0, [r4]
	ldrb r0, [r0, 0x14]
	bl sub_8090A60
	lsls r0, 24
	cmp r0, 0
	beq _0802702C
	ldr r0, _08027028
	ldr r1, [r0]
	ldr r2, [r4]
	ldrb r0, [r2, 0x14]
	lsls r0, 1
	adds r1, 0x50
	adds r1, r0
	ldrh r0, [r1]
	ldrb r2, [r2, 0x15]
	adds r0, r2
	b _0802703E
	.align 2, 0
_08027024: .4byte 0x0000014d
_08027028: .4byte gUnknown_203B460
_0802702C:
	ldr r0, _08027060
	ldr r1, [r0]
	ldr r0, [r4]
	ldrb r0, [r0, 0x14]
	lsls r0, 1
	adds r1, 0x50
	adds r1, r0
	ldrh r0, [r1]
	adds r0, 0x1
_0802703E:
	strh r0, [r1]
	ldr r1, _08027064
	ldr r0, [r1]
	movs r2, 0
	strb r2, [r0, 0x14]
	ldr r0, [r1]
	strb r2, [r0, 0x15]
	ldr r1, [r1]
	movs r2, 0xA
	ldrsh r0, [r1, r2]
	adds r1, 0x14
	bl sub_808D800
	movs r0, 0xB
	bl sub_8026074
	b _0802706E
	.align 2, 0
_08027060: .4byte gUnknown_203B460
_08027064: .4byte gUnknown_203B2B8
_08027068:
	movs r0, 0x19
	bl sub_8026074
_0802706E:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_8026FA4

	thumb_func_start sub_8027074
sub_8027074:
	push {r4,lr}
	movs r0, 0
	bl ResetSprites
	ldr r4, _080270A0
	movs r0, 0xF0
	lsls r0, 1
	movs r1, 0x8
	bl MemoryAlloc
	str r0, [r4]
	movs r1, 0
	str r1, [r0, 0x70]
	str r1, [r0, 0x74]
	str r1, [r0, 0x78]
	movs r0, 0
	bl sub_8027184
	movs r0, 0x1
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_080270A0: .4byte gUnknown_203B2BC
	thumb_func_end sub_8027074

	thumb_func_start sub_80270A4
sub_80270A4:
	push {lr}
	ldr r0, _080270BC
	ldr r0, [r0]
	ldr r0, [r0]
	cmp r0, 0x11
	bhi _08027156
	lsls r0, 2
	ldr r1, _080270C0
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080270BC: .4byte gUnknown_203B2BC
_080270C0: .4byte _080270C4
	.align 2, 0
_080270C4:
	.4byte _0802710C
	.4byte _08027114
	.4byte _08027114
	.4byte _0802711A
	.4byte _08027120
	.4byte _08027126
	.4byte _08027156
	.4byte _08027156
	.4byte _0802712C
	.4byte _08027132
	.4byte _08027138
	.4byte _08027138
	.4byte _0802713E
	.4byte _08027144
	.4byte _0802714A
	.4byte _0802714A
	.4byte _08027150
	.4byte _0802715C
_0802710C:
	movs r0, 0x1
	bl sub_8027184
	b _08027160
_08027114:
	bl sub_80277FC
	b _08027160
_0802711A:
	bl sub_80278B4
	b _08027160
_08027120:
	bl sub_8027A40
	b _08027160
_08027126:
	bl sub_8027A5C
	b _08027160
_0802712C:
	bl sub_8027A78
	b _08027160
_08027132:
	bl sub_8027AE4
	b _08027160
_08027138:
	bl sub_8027B28
	b _08027160
_0802713E:
	bl sub_8027BD8
	b _08027160
_08027144:
	bl sub_8027C84
	b _08027160
_0802714A:
	bl sub_8027CA0
	b _08027160
_08027150:
	bl sub_8027D00
	b _08027160
_08027156:
	bl sub_8027D1C
	b _08027160
_0802715C:
	movs r0, 0x3
	b _08027162
_08027160:
	movs r0, 0
_08027162:
	pop {r1}
	bx r1
	thumb_func_end sub_80270A4

	thumb_func_start sub_8027168
sub_8027168:
	push {r4,lr}
	ldr r4, _08027180
	ldr r0, [r4]
	cmp r0, 0
	beq _0802717A
	bl MemoryFree
	movs r0, 0
	str r0, [r4]
_0802717A:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08027180: .4byte gUnknown_203B2BC
	thumb_func_end sub_8027168

	thumb_func_start sub_8027184
sub_8027184:
	push {lr}
	ldr r1, _08027198
	ldr r1, [r1]
	str r0, [r1]
	bl sub_802719C
	bl sub_8027274
	pop {r0}
	bx r0
	.align 2, 0
_08027198: .4byte gUnknown_203B2BC
	thumb_func_end sub_8027184

	thumb_func_start sub_802719C
sub_802719C:
	push {r4-r7,lr}
	ldr r4, _080271C0
	ldr r0, [r4]
	movs r1, 0xC0
	lsls r1, 1
	adds r0, r1
	bl sub_8006518
	ldr r1, [r4]
	ldr r0, [r1]
	cmp r0, 0x3
	beq _080271C8
	cmp r0, 0xC
	beq _08027208
	movs r2, 0
	ldr r3, _080271C4
	b _08027234
	.align 2, 0
_080271C0: .4byte gUnknown_203B2BC
_080271C4: .4byte gUnknown_80DD6EC
_080271C8:
	movs r2, 0xE4
	lsls r2, 1
	adds r1, r2
	ldr r0, _08027200
	ldm r0!, {r3,r5,r6}
	stm r1!, {r3,r5,r6}
	ldm r0!, {r2,r3,r7}
	stm r1!, {r2,r3,r7}
	bl sub_802745C
	ldr r2, [r4]
	movs r0, 0xD8
	lsls r0, 1
	adds r2, r0
	ldr r1, _08027204
	ldm r1!, {r5-r7}
	stm r2!, {r5-r7}
	ldm r1!, {r3,r5,r6}
	stm r2!, {r3,r5,r6}
	ldr r1, [r4]
	adds r0, r1, r0
	movs r7, 0x8E
	lsls r7, 1
	adds r1, r7
	bl sub_8012CAC
	b _08027254
	.align 2, 0
_08027200: .4byte gUnknown_80DD74C
_08027204: .4byte gUnknown_80DD704
_08027208:
	bl sub_80276A8
	ldr r2, [r4]
	movs r0, 0xD8
	lsls r0, 1
	adds r2, r0
	ldr r1, _08027230
	ldm r1!, {r3,r5,r6}
	stm r2!, {r3,r5,r6}
	ldm r1!, {r3,r5,r7}
	stm r2!, {r3,r5,r7}
	ldr r1, [r4]
	adds r0, r1, r0
	movs r6, 0x8E
	lsls r6, 1
	adds r1, r6
	bl sub_8012CAC
	b _08027254
	.align 2, 0
_08027230: .4byte gUnknown_80DD71C
_08027234:
	ldr r0, [r4]
	lsls r1, r2, 1
	adds r1, r2
	lsls r1, 3
	adds r0, r1
	movs r7, 0xC0
	lsls r7, 1
	adds r0, r7
	adds r1, r3, 0
	ldm r1!, {r5-r7}
	stm r0!, {r5-r7}
	ldm r1!, {r5-r7}
	stm r0!, {r5-r7}
	adds r2, 0x1
	cmp r2, 0x3
	ble _08027234
_08027254:
	bl sub_8004914
	ldr r0, _08027270
	ldr r0, [r0]
	movs r1, 0xC0
	lsls r1, 1
	adds r0, r1
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_08027270: .4byte gUnknown_203B2BC
	thumb_func_end sub_802719C

	thumb_func_start sub_8027274
sub_8027274:
	push {r4,lr}
	sub sp, 0x18
	ldr r1, _08027290
	ldr r0, [r1]
	ldr r0, [r0]
	adds r4, r1, 0
	cmp r0, 0x11
	bls _08027286
	b _0802744A
_08027286:
	lsls r0, 2
	ldr r1, _08027294
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08027290: .4byte gUnknown_203B2BC
_08027294: .4byte _08027298
	.align 2, 0
_08027298:
	.4byte _0802744A
	.4byte _080272E0
	.4byte _080272EE
	.4byte _080272F6
	.4byte _0802731A
	.4byte _08027328
	.4byte _0802741C
	.4byte _08027438
	.4byte _080273B6
	.4byte _080273D0
	.4byte _08027334
	.4byte _08027342
	.4byte _0802734A
	.4byte _08027374
	.4byte _08027386
	.4byte _080273AC
	.4byte _08027404
	.4byte _0802744A
_080272E0:
	movs r0, 0x1
	movs r1, 0
	movs r2, 0
	movs r3, 0x7
	bl sub_8023868
	b _0802744A
_080272EE:
	movs r0, 0x1
	bl sub_8023B7C
	b _0802744A
_080272F6:
	ldr r1, [r4]
	adds r1, 0x14
	movs r0, 0x3
	bl sub_8027D40
	bl sub_8023DA4
	ldr r2, [r4]
	adds r0, r2, 0
	adds r0, 0x7C
	movs r3, 0x8E
	lsls r3, 1
	adds r1, r2, r3
	movs r4, 0xB6
	lsls r4, 1
	adds r3, r2, r4
	ldr r2, [r2, 0x70]
	b _08027362
_0802731A:
	ldr r0, [r4]
	movs r1, 0x8
	ldrsh r0, [r0, r1]
	movs r1, 0x2
	bl sub_8024458
	b _0802744A
_08027328:
	ldr r0, [r4]
	movs r3, 0x8
	ldrsh r0, [r0, r3]
	bl sub_801BEEC
	b _0802744A
_08027334:
	movs r0, 0x1
	movs r1, 0
	movs r2, 0
	movs r3, 0xA
	bl sub_801A5D8
	b _0802744A
_08027342:
	movs r0, 0x1
	bl sub_801A8D0
	b _0802744A
_0802734A:
	bl sub_801A9E0
	ldr r0, _08027370
	ldr r2, [r0]
	adds r0, r2, 0
	adds r0, 0x7C
	movs r4, 0x8E
	lsls r4, 1
	adds r1, r2, r4
	adds r4, 0x50
	adds r3, r2, r4
	ldr r2, [r2, 0x74]
_08027362:
	str r2, [sp]
	movs r2, 0x2
	str r2, [sp, 0x4]
	movs r2, 0
	bl sub_8012D60
	b _0802744A
	.align 2, 0
_08027370: .4byte gUnknown_203B2BC
_08027374:
	ldr r1, [r4]
	adds r1, 0x10
	add r0, sp, 0x14
	bl sub_8090B64
	add r0, sp, 0x14
	bl sub_801B3C0
	b _0802744A
_08027386:
	ldr r1, [r4]
	adds r0, r1, 0
	adds r0, 0x28
	ldr r1, [r1, 0x18]
	adds r1, 0x2C
	bl sub_809401C
	ldr r2, [r4]
	movs r0, 0x8
	ldrsh r1, [r2, r0]
	adds r2, 0x28
	movs r0, 0
	str r0, [sp]
	str r0, [sp, 0x4]
	movs r0, 0x3
	movs r3, 0
	bl sub_801EE10
	b _0802744A
_080273AC:
	movs r0, 0x1
	movs r1, 0
	bl sub_801F1B0
	b _0802744A
_080273B6:
	bl sub_8027794
	ldr r0, _080273C8
	ldr r1, _080273CC
	ldr r3, [r1]
	movs r1, 0x8E
	lsls r1, 1
	adds r3, r1
	b _080273E0
	.align 2, 0
_080273C8: .4byte gUnknown_80DD764
_080273CC: .4byte gUnknown_203B2BC
_080273D0:
	bl sub_8027794
	ldr r0, _080273FC
	ldr r1, _08027400
	ldr r3, [r1]
	movs r4, 0x8E
	lsls r4, 1
	adds r3, r4
_080273E0:
	movs r2, 0
	str r2, [sp]
	movs r1, 0x4
	str r1, [sp, 0x4]
	str r2, [sp, 0x8]
	str r2, [sp, 0xC]
	adds r1, 0xFD
	str r1, [sp, 0x10]
	movs r1, 0
	movs r2, 0x3
	bl sub_8014248
	b _0802744A
	.align 2, 0
_080273FC: .4byte gUnknown_80DD7FC
_08027400: .4byte gUnknown_203B2BC
_08027404:
	ldr r2, [r4]
	ldr r0, [r2, 0x20]
	adds r1, r2, 0
	adds r1, 0x28
	adds r2, 0x68
	bl sub_8093560
	ldr r0, [r4]
	adds r0, 0x68
	bl sub_801F808
	b _0802744A
_0802741C:
	ldr r1, [r4]
	movs r0, 0x2
	str r0, [r1, 0x4]
	ldr r0, _08027430
	ldr r3, _08027434
	movs r1, 0
	movs r2, 0
	bl sub_80141B4
	b _0802744A
	.align 2, 0
_08027430: .4byte gUnknown_80DD8A0
_08027434: .4byte 0x00000101
_08027438:
	ldr r1, [r4]
	movs r0, 0x2
	str r0, [r1, 0x4]
	ldr r0, _08027454
	ldr r3, _08027458
	movs r1, 0
	movs r2, 0
	bl sub_80141B4
_0802744A:
	add sp, 0x18
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08027454: .4byte gUnknown_80DD8D0
_08027458: .4byte 0x00000101
	thumb_func_end sub_8027274

	thumb_func_start sub_802745C
sub_802745C:
	push {r4-r7,lr}
	ldr r3, _080274E4
	ldr r4, _080274E8
	ldr r0, [r4]
	movs r1, 0x8
	ldrsh r2, [r0, r1]
	movs r1, 0x58
	muls r2, r1
	ldr r1, [r3]
	adds r5, r1, r2
	movs r2, 0xB6
	lsls r2, 1
	adds r0, r2
	movs r1, 0
	movs r2, 0x14
	bl MemoryFill16
	ldrh r0, [r5]
	lsrs r0, 1
	movs r6, 0x1
	ands r0, r6
	cmp r0, 0
	beq _080274F4
	ldr r2, [r4]
	movs r3, 0x8E
	lsls r3, 1
	adds r1, r2, r3
	ldr r0, _080274EC
	str r0, [r1]
	movs r0, 0x90
	lsls r0, 1
	adds r1, r2, r0
	movs r0, 0x7
	str r0, [r1]
	adds r0, r5, 0
	bl sub_8027D9C
	lsls r0, 24
	cmp r0, 0
	bne _080274B6
	ldr r0, [r4]
	movs r1, 0xB6
	lsls r1, 1
	adds r0, r1
	strh r6, [r0]
_080274B6:
	movs r7, 0x1
	movs r0, 0x8
	bl sub_80023E4
	lsls r0, 24
	cmp r0, 0
	beq _08027552
	ldrb r0, [r5, 0x2]
	cmp r0, 0
	bne _08027552
	ldr r3, [r4]
	movs r2, 0x8
	movs r4, 0x92
	lsls r4, 1
	adds r1, r3, r4
	ldr r0, _080274F0
	str r0, [r1]
	movs r1, 0x94
	lsls r1, 1
	adds r0, r3, r1
	str r2, [r0]
	b _08027550
	.align 2, 0
_080274E4: .4byte gUnknown_203B45C
_080274E8: .4byte gUnknown_203B2BC
_080274EC: .4byte gUnknown_80DD8F8
_080274F0: .4byte gUnknown_80DD904
_080274F4:
	ldr r2, [r4]
	movs r3, 0x8E
	lsls r3, 1
	adds r1, r2, r3
	ldr r0, _08027658
	str r0, [r1]
	movs r0, 0x90
	lsls r0, 1
	adds r1, r2, r0
	movs r0, 0x6
	str r0, [r1]
	movs r1, 0x8
	ldrsh r0, [r2, r1]
	bl sub_808D750
	lsls r0, 24
	cmp r0, 0
	bne _08027522
	ldr r0, [r4]
	movs r2, 0xB6
	lsls r2, 1
	adds r0, r2
	strh r6, [r0]
_08027522:
	movs r7, 0x1
	ldr r2, [r4]
	movs r3, 0x92
	lsls r3, 1
	adds r1, r2, r3
	ldr r0, _0802765C
	str r0, [r1]
	movs r0, 0x94
	lsls r0, 1
	adds r1, r2, r0
	movs r0, 0x9
	str r0, [r1]
	adds r0, r5, 0
	bl sub_8027DCC
	lsls r0, 24
	cmp r0, 0
	bne _08027550
	ldr r0, [r4]
	movs r1, 0xB7
	lsls r1, 1
	adds r0, r1
	strh r7, [r0]
_08027550:
	movs r7, 0x2
_08027552:
	ldr r4, _08027660
	ldr r2, [r4]
	lsls r3, r7, 3
	movs r6, 0x8E
	lsls r6, 1
	adds r0, r2, r6
	adds r0, r3
	ldr r1, _08027664
	str r1, [r0]
	movs r5, 0x90
	lsls r5, 1
	adds r2, r5
	adds r2, r3
	movs r0, 0xA
	str r0, [r2]
	bl sub_8090A34
	cmp r0, 0
	bne _08027588
	ldr r0, [r4]
	lsls r1, r7, 1
	movs r2, 0xB6
	lsls r2, 1
	adds r0, r2
	adds r0, r1
	movs r1, 0x1
	strh r1, [r0]
_08027588:
	adds r7, 0x1
	ldr r2, [r4]
	lsls r3, r7, 3
	adds r0, r2, r6
	adds r0, r3
	ldr r1, _08027668
	str r1, [r0]
	adds r2, r5
	adds r2, r3
	movs r0, 0xB
	str r0, [r2]
	bl sub_8090A34
	cmp r0, 0x13
	bgt _080275AE
	ldr r0, [r4]
	ldrb r0, [r0, 0x14]
	cmp r0, 0
	bne _080275BE
_080275AE:
	ldr r0, [r4]
	lsls r1, r7, 1
	movs r3, 0xB6
	lsls r3, 1
	adds r0, r3
	adds r0, r1
	movs r1, 0x1
	strh r1, [r0]
_080275BE:
	adds r7, 0x1
	ldr r4, _08027660
	ldr r5, [r4]
	lsls r1, r7, 3
	movs r0, 0x8E
	lsls r0, 1
	adds r3, r5, r0
	adds r2, r3, r1
	ldr r0, _0802766C
	str r0, [r2]
	movs r2, 0x90
	lsls r2, 1
	adds r6, r5, r2
	adds r1, r6, r1
	movs r0, 0x4
	str r0, [r1]
	adds r7, 0x1
	lsls r1, r7, 3
	adds r2, r3, r1
	ldr r0, _08027670
	str r0, [r2]
	adds r1, r6, r1
	movs r0, 0xC
	str r0, [r1]
	adds r7, 0x1
	lsls r1, r7, 3
	adds r2, r3, r1
	ldr r0, _08027674
	str r0, [r2]
	adds r1, r6, r1
	movs r0, 0x5
	str r0, [r1]
	adds r7, 0x1
	lsls r1, r7, 3
	adds r3, r1
	movs r0, 0
	str r0, [r3]
	adds r1, r6, r1
	movs r0, 0x1
	str r0, [r1]
	movs r3, 0
	mov r12, r4
	cmp r3, r7
	bge _08027636
	adds r4, r6, 0
	movs r0, 0xB6
	lsls r0, 1
	adds r2, r5, r0
_0802761E:
	ldrh r0, [r2]
	cmp r0, 0
	bne _0802762C
	ldr r1, [r4]
	ldr r0, [r5, 0x70]
	cmp r1, r0
	beq _080276A0
_0802762C:
	adds r4, 0x8
	adds r2, 0x2
	adds r3, 0x1
	cmp r3, r7
	blt _0802761E
_08027636:
	movs r3, 0
	cmp r3, r7
	bge _080276A0
	mov r2, r12
	ldr r1, [r2]
	movs r4, 0xB6
	lsls r4, 1
	adds r0, r1, r4
	ldrh r0, [r0]
	cmp r0, 0
	bne _08027678
	movs r2, 0x90
	lsls r2, 1
	adds r0, r1, r2
	ldr r0, [r0]
	str r0, [r1, 0x70]
	b _080276A0
	.align 2, 0
_08027658: .4byte gUnknown_80DD910
_0802765C: .4byte gUnknown_80DD91C
_08027660: .4byte gUnknown_203B2BC
_08027664: .4byte gUnknown_80DD92C
_08027668: .4byte gUnknown_80DD934
_0802766C: .4byte gUnknown_80DD93C
_08027670: .4byte gUnknown_80DD944
_08027674: .4byte gUnknown_80DD94C
_08027678:
	adds r3, 0x1
	cmp r3, r7
	bge _080276A0
	mov r4, r12
	ldr r2, [r4]
	lsls r0, r3, 1
	movs r4, 0xB6
	lsls r4, 1
	adds r1, r2, r4
	adds r1, r0
	ldrh r0, [r1]
	cmp r0, 0
	bne _08027678
	lsls r0, r3, 3
	movs r3, 0x90
	lsls r3, 1
	adds r1, r2, r3
	adds r1, r0
	ldr r0, [r1]
	str r0, [r2, 0x70]
_080276A0:
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_802745C

	thumb_func_start sub_80276A8
sub_80276A8:
	push {r4-r7,lr}
	ldr r5, _0802775C
	ldr r0, [r5]
	movs r7, 0xB6
	lsls r7, 1
	adds r0, r7
	movs r1, 0
	movs r2, 0x14
	bl MemoryFill16
	ldr r2, [r5]
	movs r0, 0x8E
	lsls r0, 1
	adds r1, r2, r0
	ldr r0, _08027760
	str r0, [r1]
	movs r3, 0x90
	lsls r3, 1
	adds r1, r2, r3
	movs r0, 0xA
	str r0, [r1]
	bl sub_8090A34
	cmp r0, 0
	bne _080276E4
	ldr r0, [r5]
	adds r4, r7, 0
	adds r0, r4
	movs r1, 0x1
	strh r1, [r0]
_080276E4:
	ldr r4, [r5]
	movs r2, 0x1
	movs r0, 0x92
	lsls r0, 1
	adds r1, r4, r0
	ldr r0, _08027764
	ldr r0, [r0]
	str r0, [r1]
	movs r3, 0x94
	lsls r3, 1
	adds r1, r4, r3
	movs r0, 0x4
	str r0, [r1]
	movs r6, 0x2
	movs r0, 0x96
	lsls r0, 1
	adds r1, r4, r0
	movs r0, 0
	str r0, [r1]
	movs r1, 0x98
	lsls r1, 1
	adds r0, r4, r1
	str r2, [r0]
	movs r3, 0
	mov r12, r4
	movs r4, 0x90
	lsls r4, 1
	add r4, r12
	mov r0, r12
	adds r2, r0, r7
_08027720:
	ldrh r0, [r2]
	cmp r0, 0
	bne _08027730
	ldr r1, [r4]
	mov r7, r12
	ldr r0, [r7, 0x74]
	cmp r1, r0
	beq _0802778E
_08027730:
	adds r4, 0x8
	adds r2, 0x2
	adds r3, 0x1
	cmp r3, r6
	blt _08027720
	movs r3, 0
	cmp r3, r6
	bge _0802778E
	ldr r1, [r5]
	movs r2, 0xB6
	lsls r2, 1
	adds r0, r1, r2
	ldrh r0, [r0]
	cmp r0, 0
	bne _08027768
	movs r3, 0x90
	lsls r3, 1
	adds r0, r1, r3
	ldr r0, [r0]
	str r0, [r1, 0x74]
	b _0802778E
	.align 2, 0
_0802775C: .4byte gUnknown_203B2BC
_08027760: .4byte gUnknown_80DD92C
_08027764: .4byte gUnknown_80D4970
_08027768:
	adds r3, 0x1
	cmp r3, r6
	bge _0802778E
	ldr r2, [r5]
	lsls r0, r3, 1
	movs r4, 0xB6
	lsls r4, 1
	adds r1, r2, r4
	adds r1, r0
	ldrh r0, [r1]
	cmp r0, 0
	bne _08027768
	lsls r0, r3, 3
	movs r7, 0x90
	lsls r7, 1
	adds r1, r2, r7
	adds r1, r0
	ldr r0, [r1]
	str r0, [r2, 0x74]
_0802778E:
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_80276A8

	thumb_func_start sub_8027794
sub_8027794:
	push {r4,lr}
	ldr r4, _080277F0
	ldr r0, [r4]
	movs r1, 0xB6
	lsls r1, 1
	adds r0, r1
	movs r1, 0
	movs r2, 0x14
	bl MemoryFill16
	ldr r4, [r4]
	movs r3, 0
	movs r0, 0x8E
	lsls r0, 1
	adds r1, r4, r0
	ldr r0, _080277F4
	ldr r0, [r0]
	str r0, [r1]
	movs r0, 0x90
	lsls r0, 1
	adds r1, r4, r0
	movs r0, 0x2
	str r0, [r1]
	movs r2, 0x1
	movs r0, 0x92
	lsls r0, 1
	adds r1, r4, r0
	ldr r0, _080277F8
	ldr r0, [r0]
	str r0, [r1]
	movs r0, 0x94
	lsls r0, 1
	adds r1, r4, r0
	movs r0, 0x3
	str r0, [r1]
	movs r1, 0x96
	lsls r1, 1
	adds r0, r4, r1
	str r3, [r0]
	adds r1, 0x4
	adds r0, r4, r1
	str r2, [r0]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080277F0: .4byte gUnknown_203B2BC
_080277F4: .4byte gUnknown_80D4920
_080277F8: .4byte gUnknown_80D4928
	thumb_func_end sub_8027794

	thumb_func_start sub_80277FC
sub_80277FC:
	push {r4,lr}
	movs r0, 0x1
	bl sub_8023A94
	cmp r0, 0x4
	bhi _080278AE
	lsls r0, 2
	ldr r1, _08027814
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08027814: .4byte _08027818
	.align 2, 0
_08027818:
	.4byte _080278AE
	.4byte _080278AE
	.4byte _080278A4
	.4byte _0802782C
	.4byte _08027868
_0802782C:
	bl sub_8023B44
	ldr r4, _08027860
	ldr r1, [r4]
	strh r0, [r1, 0x8]
	ldr r3, _08027864
	movs r0, 0x8
	ldrsh r2, [r1, r0]
	movs r0, 0x58
	muls r2, r0
	ldr r0, [r3]
	adds r0, r2
	str r0, [r1, 0x18]
	ldrb r0, [r0, 0x2]
	strb r0, [r1, 0x1C]
	ldr r1, [r4]
	movs r2, 0x8
	ldrsh r0, [r1, r2]
	adds r1, 0x14
	bl sub_808D7DC
	movs r0, 0x3
	bl sub_8027184
	b _080278AE
	.align 2, 0
_08027860: .4byte gUnknown_203B2BC
_08027864: .4byte gUnknown_203B45C
_08027868:
	bl sub_8023B44
	ldr r4, _0802789C
	ldr r1, [r4]
	strh r0, [r1, 0x8]
	ldr r3, _080278A0
	movs r0, 0x8
	ldrsh r2, [r1, r0]
	movs r0, 0x58
	muls r2, r0
	ldr r0, [r3]
	adds r0, r2
	str r0, [r1, 0x18]
	ldrb r0, [r0, 0x2]
	strb r0, [r1, 0x1C]
	ldr r1, [r4]
	movs r2, 0x8
	ldrsh r0, [r1, r2]
	adds r1, 0x14
	bl sub_808D7DC
	movs r0, 0x4
	bl sub_8027184
	b _080278AE
	.align 2, 0
_0802789C: .4byte gUnknown_203B2BC
_080278A0: .4byte gUnknown_203B45C
_080278A4:
	bl sub_8023C60
	movs r0, 0x11
	bl sub_8027184
_080278AE:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_80277FC

	thumb_func_start sub_80278B4
sub_80278B4:
	push {r4,lr}
	sub sp, 0x4
	movs r0, 0
	str r0, [sp]
	bl sub_8023A94
	ldr r4, _080278F8
	ldr r0, [r4]
	adds r0, 0x7C
	bl sub_8012FD8
	lsls r0, 24
	cmp r0, 0
	bne _080278E4
	ldr r0, [r4]
	adds r0, 0x7C
	mov r1, sp
	bl sub_8013114
	ldr r1, [sp]
	cmp r1, 0x1
	beq _080278E4
	ldr r0, [r4]
	str r1, [r0, 0x70]
_080278E4:
	ldr r0, [sp]
	subs r0, 0x1
	cmp r0, 0xB
	bls _080278EE
	b _08027A36
_080278EE:
	lsls r0, 2
	ldr r1, _080278FC
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080278F8: .4byte gUnknown_203B2BC
_080278FC: .4byte _08027900
	.align 2, 0
_08027900:
	.4byte _08027A30
	.4byte _08027A36
	.4byte _08027A36
	.4byte _08027A20
	.4byte _08027A28
	.4byte _08027930
	.4byte _0802796C
	.4byte _0802798C
	.4byte _080279C0
	.4byte _080279D0
	.4byte _080279D8
	.4byte _080279C8
_08027930:
	ldr r4, _08027964
	ldr r0, [r4]
	movs r1, 0x8
	ldrsh r0, [r0, r1]
	bl sub_808D750
	lsls r0, 24
	cmp r0, 0
	beq _0802795E
	ldr r0, [r4]
	movs r2, 0x8
	ldrsh r1, [r0, r2]
	movs r0, 0x58
	muls r1, r0
	ldr r0, _08027968
	ldr r0, [r0]
	adds r1, r0
	ldrh r2, [r1]
	movs r0, 0x2
	orrs r0, r2
	strh r0, [r1]
	bl nullsub_104
_0802795E:
	bl sub_808ED00
	b _08027A0E
	.align 2, 0
_08027964: .4byte gUnknown_203B2BC
_08027968: .4byte gUnknown_203B45C
_0802796C:
	ldr r0, _08027984
	ldr r0, [r0]
	ldr r2, [r0, 0x18]
	ldrh r1, [r2]
	ldr r0, _08027988
	ands r0, r1
	strh r0, [r2]
	bl nullsub_104
	bl sub_808ED00
	b _08027A0E
	.align 2, 0
_08027984: .4byte gUnknown_203B2BC
_08027988: .4byte 0x0000fffd
_0802798C:
	ldr r2, _080279B8
	ldr r0, _080279BC
	ldr r0, [r0]
	movs r3, 0x8
	ldrsh r1, [r0, r3]
	movs r0, 0x58
	muls r1, r0
	ldr r0, [r2]
	adds r4, r0, r1
	bl sub_808D33C
	ldrb r1, [r4, 0x2]
	cmp r1, 0
	bne _080279B2
	strb r1, [r0, 0x2]
	movs r0, 0x1
	strb r0, [r4, 0x2]
	bl nullsub_104
_080279B2:
	bl sub_808ED00
	b _08027A0E
	.align 2, 0
_080279B8: .4byte gUnknown_203B45C
_080279BC: .4byte gUnknown_203B2BC
_080279C0:
	movs r0, 0x8
	bl sub_8027184
	b _08027A36
_080279C8:
	movs r0, 0xE
	bl sub_8027184
	b _08027A36
_080279D0:
	movs r0, 0xA
	bl sub_8027184
	b _08027A36
_080279D8:
	ldr r0, _08027A18
	bl sub_8011988
	ldr r4, _08027A1C
	ldr r1, [r4]
	ldrb r0, [r1, 0x14]
	cmp r0, 0
	beq _080279F0
	adds r0, r1, 0
	adds r0, 0x14
	bl sub_8091274
_080279F0:
	bl sub_80910B4
	ldr r0, [r4]
	movs r1, 0
	strb r1, [r0, 0x14]
	ldr r0, [r4]
	strb r1, [r0, 0x15]
	ldr r1, [r4]
	movs r2, 0x8
	ldrsh r0, [r1, r2]
	adds r1, 0x14
	bl sub_808D800
	bl nullsub_104
_08027A0E:
	movs r0, 0x2
	bl sub_8027184
	b _08027A36
	.align 2, 0
_08027A18: .4byte 0x0000014d
_08027A1C: .4byte gUnknown_203B2BC
_08027A20:
	movs r0, 0x4
	bl sub_8027184
	b _08027A36
_08027A28:
	movs r0, 0x5
	bl sub_8027184
	b _08027A36
_08027A30:
	movs r0, 0x2
	bl sub_8027184
_08027A36:
	add sp, 0x4
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_80278B4

	thumb_func_start sub_8027A40
sub_8027A40:
	push {lr}
	bl sub_80244E4
	cmp r0, 0x1
	bls _08027A58
	cmp r0, 0x3
	bhi _08027A58
	bl sub_802453C
	movs r0, 0x2
	bl sub_8027184
_08027A58:
	pop {r0}
	bx r0
	thumb_func_end sub_8027A40

	thumb_func_start sub_8027A5C
sub_8027A5C:
	push {lr}
	bl sub_801BF48
	cmp r0, 0x1
	bls _08027A74
	cmp r0, 0x3
	bhi _08027A74
	bl sub_801BF98
	movs r0, 0x2
	bl sub_8027184
_08027A74:
	pop {r0}
	bx r0
	thumb_func_end sub_8027A5C

	thumb_func_start sub_8027A78
sub_8027A78:
	push {lr}
	sub sp, 0x4
	mov r0, sp
	bl sub_80144A4
	cmp r0, 0
	bne _08027AD8
	ldr r0, [sp]
	cmp r0, 0x2
	beq _08027AA2
	cmp r0, 0x2
	bgt _08027A96
	cmp r0, 0x1
	beq _08027A9A
	b _08027AD8
_08027A96:
	cmp r0, 0x3
	bne _08027AD8
_08027A9A:
	movs r0, 0x2
	bl sub_8027184
	b _08027AD8
_08027AA2:
	ldr r0, _08027AB8
	ldr r0, [r0]
	ldr r0, [r0, 0x18]
	ldrb r0, [r0, 0x4]
	subs r0, 0x44
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bhi _08027ABC
	movs r0, 0x1
	b _08027ABE
	.align 2, 0
_08027AB8: .4byte gUnknown_203B2BC
_08027ABC:
	movs r0, 0
_08027ABE:
	cmp r0, 0
	beq _08027ACA
	movs r0, 0x9
	bl sub_8027184
	b _08027AD8
_08027ACA:
	bl sub_8027EB8
	ldr r0, _08027AE0
	ldr r0, [r0]
	ldr r0, [r0, 0x18]
	bl sub_808D31C
_08027AD8:
	add sp, 0x4
	pop {r0}
	bx r0
	.align 2, 0
_08027AE0: .4byte gUnknown_203B2BC
	thumb_func_end sub_8027A78

	thumb_func_start sub_8027AE4
sub_8027AE4:
	push {lr}
	sub sp, 0x4
	mov r0, sp
	bl sub_80144A4
	cmp r0, 0
	bne _08027B1C
	ldr r0, [sp]
	cmp r0, 0x2
	beq _08027B0E
	cmp r0, 0x2
	bgt _08027B02
	cmp r0, 0x1
	beq _08027B06
	b _08027B1C
_08027B02:
	cmp r0, 0x3
	bne _08027B1C
_08027B06:
	movs r0, 0x2
	bl sub_8027184
	b _08027B1C
_08027B0E:
	bl sub_8027EB8
	ldr r0, _08027B24
	ldr r0, [r0]
	ldr r0, [r0, 0x18]
	bl sub_808D31C
_08027B1C:
	add sp, 0x4
	pop {r0}
	bx r0
	.align 2, 0
_08027B24: .4byte gUnknown_203B2BC
	thumb_func_end sub_8027AE4

	thumb_func_start sub_8027B28
sub_8027B28:
	push {r4,lr}
	movs r0, 0x1
	bl sub_801A6E8
	cmp r0, 0x4
	bhi _08027BD2
	lsls r0, 2
	ldr r1, _08027B40
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08027B40: .4byte _08027B44
	.align 2, 0
_08027B44:
	.4byte _08027BD2
	.4byte _08027BD2
	.4byte _08027BC8
	.4byte _08027B58
	.4byte _08027B8C
_08027B58:
	bl sub_801A8AC
	ldr r4, _08027B84
	ldr r2, [r4]
	str r0, [r2, 0xC]
	ldr r3, _08027B88
	ldr r1, [r3]
	lsls r0, 2
	adds r1, r0
	ldrb r0, [r1, 0x2]
	strb r0, [r2, 0x10]
	ldr r2, [r4]
	ldr r1, [r3]
	ldr r0, [r2, 0xC]
	lsls r0, 2
	adds r1, r0
	ldrb r0, [r1, 0x1]
	strb r0, [r2, 0x11]
	movs r0, 0xC
	bl sub_8027184
	b _08027BD2
	.align 2, 0
_08027B84: .4byte gUnknown_203B2BC
_08027B88: .4byte gUnknown_203B460
_08027B8C:
	bl sub_801A8AC
	ldr r4, _08027BC0
	ldr r2, [r4]
	str r0, [r2, 0xC]
	ldr r3, _08027BC4
	ldr r1, [r3]
	lsls r0, 2
	adds r1, r0
	ldrb r0, [r1, 0x2]
	strb r0, [r2, 0x10]
	ldr r2, [r4]
	ldr r1, [r3]
	ldr r0, [r2, 0xC]
	lsls r0, 2
	adds r1, r0
	ldrb r0, [r1, 0x1]
	strb r0, [r2, 0x11]
	movs r0, 0
	bl sub_8099690
	movs r0, 0xD
	bl sub_8027184
	b _08027BD2
	.align 2, 0
_08027BC0: .4byte gUnknown_203B2BC
_08027BC4: .4byte gUnknown_203B460
_08027BC8:
	bl sub_801A928
	movs r0, 0x2
	bl sub_8027184
_08027BD2:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_8027B28

	thumb_func_start sub_8027BD8
sub_8027BD8:
	push {r4,lr}
	sub sp, 0x4
	movs r0, 0
	str r0, [sp]
	bl sub_801A6E8
	ldr r4, _08027C18
	ldr r0, [r4]
	adds r0, 0x7C
	bl sub_8012FD8
	lsls r0, 24
	cmp r0, 0
	bne _08027C08
	ldr r0, [r4]
	adds r0, 0x7C
	mov r1, sp
	bl sub_8013114
	ldr r1, [sp]
	cmp r1, 0x1
	beq _08027C08
	ldr r0, [r4]
	str r1, [r0, 0x74]
_08027C08:
	ldr r0, [sp]
	cmp r0, 0x4
	beq _08027C68
	cmp r0, 0x4
	bgt _08027C1C
	cmp r0, 0x1
	beq _08027C76
	b _08027C7C
	.align 2, 0
_08027C18: .4byte gUnknown_203B2BC
_08027C1C:
	cmp r0, 0xA
	bne _08027C7C
	ldr r0, _08027C60
	bl sub_8011988
	ldr r4, _08027C64
	ldr r0, [r4]
	ldr r0, [r0, 0xC]
	bl sub_80911F8
	bl sub_80910B4
	ldr r1, [r4]
	ldrb r0, [r1, 0x14]
	cmp r0, 0
	beq _08027C44
	adds r0, r1, 0
	adds r0, 0x14
	bl sub_8091274
_08027C44:
	ldr r1, [r4]
	movs r2, 0x8
	ldrsh r0, [r1, r2]
	adds r1, 0x10
	bl sub_808D800
	bl sub_801A928
	bl nullsub_104
	movs r0, 0x2
	bl sub_8027184
	b _08027C7C
	.align 2, 0
_08027C60: .4byte 0x0000014d
_08027C64: .4byte gUnknown_203B2BC
_08027C68:
	movs r0, 0
	bl sub_8099690
	movs r0, 0xD
	bl sub_8027184
	b _08027C7C
_08027C76:
	movs r0, 0xB
	bl sub_8027184
_08027C7C:
	add sp, 0x4
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_8027BD8

	.align 2, 0 @ Don't pad with nop.
