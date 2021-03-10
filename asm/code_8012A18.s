	.include "constants/gba_constants.inc"
	.include "asm/macros.inc"

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
	bl PlayMenuSoundEffect
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
	bl PlayMenuSoundEffect
	b _08013094
_08013070:
	movs r0, 0
	bl PlayMenuSoundEffect
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
	bl PlayMenuSoundEffect
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
	bl PlayMenuSoundEffect
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
	bl PlayMenuSoundEffect
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
	bl ResetUnusedInputStruct
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
	bl PlayMenuSoundEffect
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
	bl PlayMenuSoundEffect
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
	bl PlayMenuSoundEffect
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
	bl PlayMenuSoundEffect
	movs r0, 0x2
	b _08013C62
_08013C56:
	movs r0, 0
	bl PlayMenuSoundEffect
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
	bl PlayMenuSoundEffect
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
	bl PlayMenuSoundEffect
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
	bl PlayMenuSoundEffect
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
	bl PlayMenuSoundEffect
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
	bl xxx_call_start_bg_music
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
	bl ResetUnusedInputStruct
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
	bl UnpressButtons
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
_08014768: .4byte gRealInputs
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
_080148E4: .4byte gRealInputs
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
	bl ResetUnusedInputStruct
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
	bl ResetUnusedInputStruct
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
	bl ResetUnusedInputStruct
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
	bl ResetUnusedInputStruct
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
	bl PlayMenuSoundEffect
	b _080155E2
	.align 2, 0
_080155B4: .4byte gUnknown_203B1FC
_080155B8:
	movs r0, 0x2
	bl PlayMenuSoundEffect
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
	bl PlayMenuSoundEffect
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
	bl PlayMenuSoundEffect
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
	bl PlayMenuSoundEffect
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
	bl PlayMenuSoundEffect
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
	bl PlayMenuSoundEffect
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
	bl PlayMenuSoundEffect
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
	bl PlayMenuSoundEffect
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
	bl PlayMenuSoundEffect
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
	bl PlayMenuSoundEffect
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
	bl ReturnIntFromChar2
	bl GetCharacter
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
	bl ReturnIntFromChar2
	bl GetCharacter
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
	bl ResetUnusedInputStruct
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
_08016158: .4byte gAvailablePokemonNames
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
_08016188: .4byte gAvailablePokemonNames
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

	thumb_func_start DisplayPersianDialogueSprite
DisplayPersianDialogueSprite:
	push {r4-r6,lr}
	adds r4, r0, 0
	bl ResetUnusedInputStruct
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
	bl GetMonSpecies
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
	bl GetDialogueSpriteDataPtr
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
	thumb_func_end DisplayPersianDialogueSprite

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
	bl ResetUnusedInputStruct
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
	bl ResetUnusedInputStruct
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
_080165B0: .4byte gFelicityDialogue
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
_08016604: .4byte gFelicityDialogue
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
_0801664C: .4byte gFelicityDialogue
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
_08016664: .4byte gFelicityDialogue
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
_0801669C: .4byte gFelicityDialogue
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
_080166C0: .4byte gFelicityDialogue
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
_080166D8: .4byte gFelicityDialogue
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
_08016704: .4byte gFelicityDialogue
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
_08016730: .4byte gFelicityDialogue
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
_08016748: .4byte gFelicityDialogue
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
_080167C8: .4byte gFelicityDialogue
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
_080167FC: .4byte gFelicityDialogue
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
_08016820: .4byte gFelicityDialogue
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
_08016854: .4byte gFelicityDialogue
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
	bl CreateFelicityBankShopMenu
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
_080168F8: .4byte gFelicityDialogue
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
_08016B80: .4byte gFelicityDeposit
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
_08016BB0: .4byte gFelicityWithdraw
_08016BB4: .4byte gUnknown_203B204
	thumb_func_end sub_8016B48

	thumb_func_start CreateFelicityBankShopMenu
CreateFelicityBankShopMenu:
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
_08016C34: .4byte gFelicityMoney
_08016C38: .4byte gUnknown_203B460
_08016C3C: .4byte gFelicitySavings
	thumb_func_end CreateFelicityBankShopMenu

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

	thumb_func_start DisplayKangaskhanDialogueSprite
DisplayKangaskhanDialogueSprite:
	push {r4-r6,lr}
	adds r4, r0, 0
	bl ResetUnusedInputStruct
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
	bl GetMonSpecies
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
	bl GetDialogueSpriteDataPtr
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
	thumb_func_end DisplayKangaskhanDialogueSprite

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
	bl ResetUnusedInputStruct
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
	bl ResetUnusedInputStruct
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
	bl ResetUnusedInputStruct
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

	thumb_func_start DisplayKeckleonDialogueSprite
DisplayKeckleonDialogueSprite:
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
	bl GetMonSpecies
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
	bl GetMonSpecies
	adds r1, r0, 0
	subs r4, 0x50
	adds r0, r4, 0
	bl strcpy
_08018BAE:
	movs r0, 0xBE
	lsls r0, 1
	bl GetDialogueSpriteDataPtr
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
	thumb_func_end DisplayKeckleonDialogueSprite

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
	bl ResetUnusedInputStruct
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
_08018F50: .4byte gKecleonShopDialogue
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
_08018FA0: .4byte gKecleonShopDialogue
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
_08018FCC: .4byte gKecleonShopDialogue
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
_08018FF4: .4byte gKecleonShopDialogue
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
_08019020: .4byte gKecleonShopDialogue
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
_08019048: .4byte gKecleonShopDialogue
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
_0801906C: .4byte gKecleonShopDialogue
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
_08019090: .4byte gKecleonShopDialogue
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
_080190B4: .4byte gKecleonShopDialogue
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
_080190D8: .4byte gKecleonShopDialogue
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
_08019100: .4byte gKecleonShopDialogue
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
_08019128: .4byte gKecleonShopDialogue
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
_08019160: .4byte gKecleonShopDialogue
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
_08019188: .4byte gKecleonShopDialogue
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
_080191B0: .4byte gKecleonShopDialogue
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
_080191D8: .4byte gKecleonShopDialogue
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
_08019290: .4byte gKecleonShopDialogue
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
_08019310: .4byte gKecleonShopDialogue
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
_08019338: .4byte gKecleonShopDialogue
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
_08019360: .4byte gKecleonShopDialogue
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
_080193F0: .4byte gKecleonShopDialogue
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
_08019464: .4byte gKecleonShopDialogue
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
_080194BC: .4byte gKecleonShopDialogue
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
_080194F0: .4byte gKecleonShopDialogue
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
	bl ResetUnusedInputStruct
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
	bl PlayMenuSoundEffect
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
	bl PlayMenuSoundEffect
	b _08019F7A
	.align 2, 0
_08019F68: .4byte 0xff00ffff
_08019F6C: .4byte 0xffff00ff
_08019F70: .4byte gUnknown_203B460
_08019F74:
	movs r0, 0
	bl PlayMenuSoundEffect
_08019F7A:
	movs r0, 0x3
	b _08019FAA
_08019F7E:
	movs r0, 0x4
	bl PlayMenuSoundEffect
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
	bl ResetUnusedInputStruct
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
	bl ResetUnusedInputStruct
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
	bl ResetUnusedInputStruct
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
	bl ResetUnusedInputStruct
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
	bl PlayMenuSoundEffect
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
	bl PlayMenuSoundEffect
	b _0801A346
	.align 2, 0
_0801A334: .4byte 0xff00ffff
_0801A338: .4byte 0xffff00ff
_0801A33C: .4byte gUnknown_203B460
_0801A340:
	movs r0, 0
	bl PlayMenuSoundEffect
_0801A346:
	movs r0, 0x3
	b _0801A376
_0801A34A:
	movs r0, 0x4
	bl PlayMenuSoundEffect
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
	bl ResetUnusedInputStruct
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
	bl ResetUnusedInputStruct
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
	bl ResetUnusedInputStruct
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
	bl ResetUnusedInputStruct
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
	bl PlayMenuSoundEffect
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
	bl PlayMenuSoundEffect
	b _0801A802
	.align 2, 0
_0801A7EC: .4byte gUnknown_203B460
_0801A7F0: .4byte 0x0001869f
_0801A7F4:
	movs r0, 0x2
	bl PlayMenuSoundEffect
	b _0801A802
_0801A7FC:
	movs r0, 0
	bl PlayMenuSoundEffect
_0801A802:
	movs r0, 0x3
	b _0801A8A2
_0801A806:
	movs r0, 0x4
	bl PlayMenuSoundEffect
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
	bl PlayMenuSoundEffect
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
	bl PlayMenuSoundEffect
	b _0801A87C
_0801A864:
	ldr r0, _0801A894
	ldr r0, [r0]
	ldr r0, [r0]
	cmp r0, 0x2
	beq _0801A87C
	movs r0, 0x5
	bl PlayMenuSoundEffect
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
	bl ResetUnusedInputStruct
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
	bl ResetUnusedInputStruct
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
	bl ResetUnusedInputStruct
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
_0801AA30: .4byte gTeamToolboxA
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
_0801AA58: .4byte gTeamToolboxB
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
	bl DisplayGulpinDialogueSprite
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
_0801B1FC: .4byte gAvailablePokemonNames
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
	bl ResetUnusedInputStruct
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
_0801B514: .4byte gAvailablePokemonNames
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
	bl PlayMenuSoundEffect
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
	bl PlayMenuSoundEffect
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
	bl PlayMenuSoundEffect
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
	bl PlayMenuSoundEffect
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
_0801B6A4: .4byte gAvailablePokemonNames
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
	bl ResetUnusedInputStruct
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
	bl ResetUnusedInputStruct
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
	bl ResetUnusedInputStruct
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
_0801BB54: .4byte gKangaskhanTrashToolboxItem
_0801BB58: .4byte gKangaskhanTrashReceivedItem
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
_0801BBF0: .4byte gKangaskhanStorage
_0801BBF4: .4byte gKangaskhanTrash
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
	bl ResetUnusedInputStruct
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
	bl ResetUnusedInputStruct
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
	bl PlayMenuSoundEffect
	movs r0, 0x2
	b _0801C38A
_0801C350:
	movs r0, 0
	bl PlayMenuSoundEffect
	movs r0, 0x3
	b _0801C38A
_0801C35A:
	movs r0, 0x4
	bl PlayMenuSoundEffect
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
	bl ResetUnusedInputStruct
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
	bl ResetUnusedInputStruct
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
	bl ResetUnusedInputStruct
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
	bl ResetUnusedInputStruct
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
	bl ResetUnusedInputStruct
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
_0801C7CC: .4byte gAvailablePokemonNames
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
	bl PlayMenuSoundEffect
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
	bl PlayMenuSoundEffect
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
	bl PlayMenuSoundEffect
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
	bl PlayMenuSoundEffect
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
	bl ResetUnusedInputStruct
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
	bl PlayMenuSoundEffect
	movs r0, 0x2
	b _0801CB1E
_0801CA72:
	movs r0, 0
	bl PlayMenuSoundEffect
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
	bl PlayMenuSoundEffect
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
	bl PlayMenuSoundEffect
	b _0801CAF2
_0801CAE8:
	movs r0, 0x4
	bl PlayMenuSoundEffect
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
	bl ResetUnusedInputStruct
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
	bl ResetUnusedInputStruct
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
	bl ResetUnusedInputStruct
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
	bl ResetUnusedInputStruct
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
	bl ResetUnusedInputStruct
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
_0801D434: .4byte gAvailablePokemonNames
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
_0801D558: .4byte gMenuItems
_0801D55C: .4byte gMenuTeam
_0801D560: .4byte gMenuJobList
_0801D564: .4byte gMenuOthers
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
_0801D63C: .4byte gAvailablePokemonNames
_0801D640: .4byte gUnknown_80DBF34
_0801D644: .4byte gUnknown_80D49A8
_0801D648: .4byte gMenuItems
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

	.align 2, 0 @ Don't pad with nop.
