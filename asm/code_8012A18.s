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


	.align 2, 0 @ Don't pad with nop.
