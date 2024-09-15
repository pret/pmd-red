	#include "asm/constants/gba_constants.inc"
	#include "asm/macros.inc"

	.syntax unified

	.text

	thumb_func_start sub_809A8B8
sub_809A8B8:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x8
	lsls r0, 16
	asrs r0, 16
	mov r9, r0
	mov r0, sp
	strh r1, [r0]
	ldr r1, _0809A928
	mov r2, r9
	lsls r0, r2, 3
	add r0, r9
	lsls r0, 2
	ldr r2, _0809A92C
	adds r0, r2
	ldr r1, [r1]
	adds r7, r1, r0
	movs r0, 0x1
	mov r10, r0
	movs r1, 0
	str r1, [sp, 0x4]
	ldr r0, [r7, 0x20]
	cmp r0, 0
	beq _0809A8F6
	bl CloseFile
	ldr r2, [sp, 0x4]
	str r2, [r7, 0x20]
_0809A8F6:
	mov r4, sp
	adds r4, 0x2
	mov r0, sp
	adds r1, r4, 0
	bl sub_80A7DDC
	mov r0, sp
	ldrh r0, [r0]
	subs r0, 0xA
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0x13
	bhi _0809A9D6
	mov r0, sp
	movs r1, 0
	ldrsh r0, [r0, r1]
	bl sub_80A8D54
	adds r5, r0, 0
	cmp r5, 0
	bne _0809A930
	movs r2, 0
	mov r10, r2
	b _0809A9D6
	.align 2, 0
_0809A928: .4byte gUnknown_3001B64
_0809A92C: .4byte 0x0000043c
_0809A930:
	bl sub_808D3BC
	cmp r5, r0
	bne _0809A940
	mov r1, sp
	movs r0, 0x21
	strh r0, [r1]
	b _0809A9D6
_0809A940:
	bl sub_808D3F8
	cmp r5, r0
	bne _0809A950
	mov r1, sp
	movs r0, 0x22
	strh r0, [r1]
	b _0809A9D6
_0809A950:
	ldrb r0, [r5, 0x4]
	subs r0, 0x43
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x3
	bhi _0809A990
	movs r0, 0
	ldrsh r1, [r4, r0]
	ldr r0, _0809A978
	cmp r1, r0
	beq _0809A9D6
	cmp r1, r0
	ble _0809A97C
	adds r0, 0x16
	cmp r1, r0
	bgt _0809A98A
	subs r0, 0x1
	cmp r1, r0
	blt _0809A98A
	b _0809A9D6
	.align 2, 0
_0809A978: .4byte 0x00000183
_0809A97C:
	movs r0, 0x82
	lsls r0, 1
	cmp r1, r0
	beq _0809A9D6
	adds r0, 0x2F
	cmp r1, r0
	beq _0809A9D6
_0809A98A:
	movs r1, 0
	mov r10, r1
	b _0809A9D6
_0809A990:
	movs r2, 0
	ldrsh r1, [r4, r2]
	movs r0, 0x87
	lsls r0, 1
	cmp r1, r0
	bgt _0809A9B0
	subs r0, 0x2
	cmp r1, r0
	bge _0809A9D6
	cmp r1, 0x90
	blt _0809A9D2
	cmp r1, 0x92
	ble _0809A9D6
	cmp r1, 0x96
	beq _0809A9D6
	b _0809A9D2
_0809A9B0:
	movs r0, 0xCF
	lsls r0, 1
	cmp r1, r0
	bgt _0809A9CC
	subs r0, 0x4
	cmp r1, r0
	bge _0809A9D6
	subs r0, 0x87
	cmp r1, r0
	bgt _0809A9D2
	subs r0, 0x1
	cmp r1, r0
	blt _0809A9D2
	b _0809A9D6
_0809A9CC:
	ldr r0, _0809A9F0
	cmp r1, r0
	beq _0809A9D6
_0809A9D2:
	movs r0, 0
	mov r10, r0
_0809A9D6:
	mov r0, sp
	ldrh r0, [r0]
	subs r0, 0x1
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x21
	bhi _0809AA98
	lsls r0, 2
	ldr r1, _0809A9F4
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0809A9F0: .4byte 0x000001a7
_0809A9F4: .4byte _0809A9F8
	.align 2, 0
_0809A9F8:
	.4byte _0809AA80
	.4byte _0809AA80
	.4byte _0809AA98
	.4byte _0809AA98
	.4byte _0809AA98
	.4byte _0809AA80
	.4byte _0809AA80
	.4byte _0809AA98
	.4byte _0809AA98
	.4byte _0809AA98
	.4byte _0809AA98
	.4byte _0809AA98
	.4byte _0809AA98
	.4byte _0809AA98
	.4byte _0809AA98
	.4byte _0809AA98
	.4byte _0809AA98
	.4byte _0809AA98
	.4byte _0809AA98
	.4byte _0809AA98
	.4byte _0809AA98
	.4byte _0809AA98
	.4byte _0809AA98
	.4byte _0809AA98
	.4byte _0809AA98
	.4byte _0809AA98
	.4byte _0809AA98
	.4byte _0809AA98
	.4byte _0809AA98
	.4byte _0809AA98
	.4byte _0809AA98
	.4byte _0809AA98
	.4byte _0809AA80
	.4byte _0809AA80
_0809AA80:
	movs r1, 0
	ldrsh r0, [r4, r1]
	bl sub_80A8CF0
	lsls r0, 24
	cmp r0, 0
	beq _0809AA94
	movs r2, 0x1
	str r2, [sp, 0x4]
	b _0809AA98
_0809AA94:
	movs r0, 0
	mov r10, r0
_0809AA98:
	mov r0, sp
	movs r2, 0
	ldrsh r1, [r0, r2]
	movs r0, 0x1
	negs r0, r0
	cmp r1, r0
	beq _0809AB34
	mov r0, sp
	movs r1, 0
	ldrsh r0, [r0, r1]
	bl sub_80A7AE8
	lsls r0, 16
	asrs r1, r0, 16
	cmp r1, 0
	blt _0809AACE
	mov r0, sp
	ldrh r0, [r0]
	movs r2, 0
	mov r8, r2
	movs r6, 0
	strh r0, [r7]
	adds r0, r1, 0
	bl sub_80A8BFC
	strh r0, [r7, 0x2]
	b _0809AAE6
_0809AACE:
	ldrh r1, [r4]
	movs r2, 0
	ldrsh r0, [r4, r2]
	cmp r0, 0
	beq _0809AB34
	mov r0, sp
	ldrh r0, [r0]
	movs r2, 0
	mov r8, r2
	movs r6, 0
	strh r0, [r7]
	strh r1, [r7, 0x2]
_0809AAE6:
	mov r0, r9
	lsls r4, r0, 2
	add r4, r9
	lsls r4, 4
	ldr r0, _0809AB28
	adds r0, r4, r0
	ldr r5, _0809AB2C
	adds r1, r5, 0
	bl strcpy
	ldr r0, _0809AB30
	adds r4, r0
	adds r0, r4, 0
	adds r1, r5, 0
	bl strcpy
	mov r1, r10
	strb r1, [r7, 0x4]
	mov r2, sp
	ldrb r2, [r2, 0x4]
	strb r2, [r7, 0x5]
	movs r0, 0xFF
	strb r0, [r7, 0x6]
	mov r0, r8
	strb r0, [r7, 0x7]
	str r6, [r7, 0x8]
	str r6, [r7, 0xC]
	str r6, [r7, 0x10]
	str r6, [r7, 0x14]
	strb r0, [r7, 0x1C]
	movs r0, 0x1
	b _0809AB3C
	.align 2, 0
_0809AB28: .4byte gAvailablePokemonNames
_0809AB2C: .4byte gUndefineText
_0809AB30: .4byte gPlayerName
_0809AB34:
	mov r0, r9
	bl sub_809A83C
	movs r0, 0
_0809AB3C:
	add sp, 0x8
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_809A8B8

	thumb_func_start sub_809AB4C
sub_809AB4C:
	push {r4-r6,lr}
	lsls r0, 16
	asrs r5, r0, 16
	lsls r1, 16
	asrs r1, 16
	ldr r2, _0809AB78
	lsls r0, r5, 3
	adds r0, r5
	lsls r0, 2
	ldr r3, _0809AB7C
	adds r0, r3
	ldr r2, [r2]
	adds r6, r2, r0
	adds r0, r5, 0
	bl sub_809A8B8
	lsls r0, 24
	cmp r0, 0
	bne _0809AB80
	movs r0, 0
	b _0809ABA0
	.align 2, 0
_0809AB78: .4byte gUnknown_3001B64
_0809AB7C: .4byte 0x0000043c
_0809AB80:
	lsls r4, r5, 2
	adds r4, r5
	lsls r4, 4
	ldr r0, _0809ABA8
	adds r0, r4, r0
	movs r2, 0x2
	ldrsh r1, [r6, r2]
	bl CopyCyanMonsterNametoBuffer
	ldr r0, _0809ABAC
	adds r4, r0
	ldr r1, _0809ABB0
	adds r0, r4, 0
	bl strcpy
	movs r0, 0x1
_0809ABA0:
	pop {r4-r6}
	pop {r1}
	bx r1
	.align 2, 0
_0809ABA8: .4byte gAvailablePokemonNames
_0809ABAC: .4byte gPlayerName
_0809ABB0: .4byte gSpeechBubbleChar
	thumb_func_end sub_809AB4C

	thumb_func_start sub_809ABB4
sub_809ABB4:
	push {r4-r6,lr}
	lsls r0, 16
	asrs r5, r0, 16
	lsls r1, 16
	asrs r1, 16
	ldr r2, _0809ABE0
	lsls r0, r5, 3
	adds r0, r5
	lsls r0, 2
	ldr r3, _0809ABE4
	adds r0, r3
	ldr r2, [r2]
	adds r6, r2, r0
	adds r0, r5, 0
	bl sub_809A8B8
	lsls r0, 24
	cmp r0, 0
	bne _0809ABE8
	movs r0, 0
	b _0809AC0A
	.align 2, 0
_0809ABE0: .4byte gUnknown_3001B64
_0809ABE4: .4byte 0x0000043c
_0809ABE8:
	lsls r4, r5, 2
	adds r4, r5
	lsls r4, 4
	ldr r5, _0809AC10
	adds r5, r4, r5
	movs r0, 0x2
	ldrsh r1, [r6, r0]
	adds r0, r5, 0
	bl CopyCyanMonsterNametoBuffer
	ldr r0, _0809AC14
	adds r4, r0
	adds r0, r4, 0
	adds r1, r5, 0
	bl strcpy
	movs r0, 0x1
_0809AC0A:
	pop {r4-r6}
	pop {r1}
	bx r1
	.align 2, 0
_0809AC10: .4byte gAvailablePokemonNames
_0809AC14: .4byte gPlayerName
	thumb_func_end sub_809ABB4

	thumb_func_start sub_809AC18
sub_809AC18:
	push {r4-r6,lr}
	lsls r0, 16
	asrs r5, r0, 16
	lsls r1, 16
	asrs r1, 16
	ldr r2, _0809AC44
	lsls r0, r5, 3
	adds r0, r5
	lsls r0, 2
	ldr r3, _0809AC48
	adds r0, r3
	ldr r2, [r2]
	adds r6, r2, r0
	adds r0, r5, 0
	bl sub_809A8B8
	lsls r0, 24
	cmp r0, 0
	bne _0809AC4C
	movs r0, 0
	b _0809AC6E
	.align 2, 0
_0809AC44: .4byte gUnknown_3001B64
_0809AC48: .4byte 0x0000043c
_0809AC4C:
	lsls r4, r5, 2
	adds r4, r5
	lsls r4, 4
	ldr r0, _0809AC74
	adds r0, r4, r0
	movs r2, 0x2
	ldrsh r1, [r6, r2]
	bl CopyCyanMonsterNametoBuffer
	ldr r0, _0809AC78
	adds r4, r0
	movs r3, 0
	ldrsh r1, [r6, r3]
	adds r0, r4, 0
	bl sub_80A8EC0
	movs r0, 0x1
_0809AC6E:
	pop {r4-r6}
	pop {r1}
	bx r1
	.align 2, 0
_0809AC74: .4byte gAvailablePokemonNames
_0809AC78: .4byte gPlayerName
	thumb_func_end sub_809AC18

	thumb_func_start sub_809AC7C
sub_809AC7C:
	push {r4-r6,lr}
	lsls r0, 16
	asrs r0, 16
	lsls r1, 24
	asrs r5, r1, 24
	lsls r2, 24
	lsrs r6, r2, 24
	ldr r2, _0809AD10
	lsls r1, r0, 3
	adds r1, r0
	lsls r1, 2
	ldr r0, _0809AD14
	adds r1, r0
	ldr r0, [r2]
	adds r4, r0, r1
	ldr r0, [r4, 0x20]
	cmp r0, 0
	beq _0809ACA8
	bl CloseFile
	movs r0, 0
	str r0, [r4, 0x20]
_0809ACA8:
	movs r0, 0x2
	ldrsh r1, [r4, r0]
	cmp r1, 0
	bge _0809ACB2
	b _0809ADC0
_0809ACB2:
	movs r0, 0x1
	negs r0, r0
	cmp r5, r0
	bne _0809ACBC
	b _0809ADC0
_0809ACBC:
	cmp r1, 0
	bne _0809ACC2
	b _0809ADC0
_0809ACC2:
	cmp r6, 0x15
	beq _0809ACCE
	movs r0, 0
	strb r6, [r4, 0x7]
	str r0, [r4, 0x8]
	str r0, [r4, 0xC]
_0809ACCE:
	ldr r2, _0809AD18
	ldrb r0, [r4, 0x7]
	lsls r0, 3
	adds r0, r2
	ldr r1, [r4, 0x8]
	ldrh r0, [r0]
	adds r0, r1
	movs r6, 0
	movs r3, 0
	strh r0, [r4, 0x18]
	ldrb r0, [r4, 0x7]
	lsls r0, 3
	adds r0, r2
	ldr r1, [r4, 0xC]
	ldrh r0, [r0, 0x2]
	adds r0, r1
	strh r0, [r4, 0x1A]
	ldrb r0, [r4, 0x7]
	lsls r0, 3
	adds r0, r2
	ldrb r0, [r0, 0x4]
	strb r0, [r4, 0x1D]
	strb r6, [r4, 0x1E]
	movs r0, 0x2
	negs r0, r0
	cmp r5, r0
	bne _0809AD1C
	strb r5, [r4, 0x6]
	str r3, [r4, 0x10]
	str r3, [r4, 0x14]
	strb r6, [r4, 0x1C]
	movs r0, 0
	b _0809ADD2
	.align 2, 0
_0809AD10: .4byte gUnknown_3001B64
_0809AD14: .4byte 0x0000043c
_0809AD18: .4byte gUnknown_8116040
_0809AD1C:
	ldrb r0, [r4, 0x4]
	cmp r0, 0
	beq _0809ADC0
	movs r1, 0x2
	ldrsh r0, [r4, r1]
	bl OpenPokemonDialogueSpriteFile
	str r0, [r4, 0x20]
	cmp r0, 0
	beq _0809ADB6
	strb r5, [r4, 0x6]
	str r0, [r4, 0x10]
	movs r1, 0
	bl GetFileDataPtr
	movs r1, 0
	ldrsh r0, [r4, r1]
	cmp r0, 0x4D
	beq _0809AD62
	cmp r0, 0x4D
	bgt _0809AD4C
	cmp r0, 0x47
	beq _0809AD56
	b _0809ADA8
_0809AD4C:
	cmp r0, 0x53
	beq _0809AD76
	cmp r0, 0x73
	beq _0809AD8A
	b _0809ADA8
_0809AD56:
	movs r0, 0xF
	ands r0, r5
	cmp r0, 0x5
	bgt _0809ADA8
	adds r0, r5, 0x6
	b _0809AD9C
_0809AD62:
	ldrb r0, [r4, 0x1D]
	cmp r0, 0
	beq _0809ADA8
	movs r0, 0xF
	ands r0, r5
	cmp r0, 0x3
	bgt _0809ADA8
	strb r6, [r4, 0x1D]
	adds r0, r5, 0x4
	b _0809AD9C
_0809AD76:
	ldrb r0, [r4, 0x1D]
	cmp r0, 0
	beq _0809ADA8
	movs r0, 0xF
	ands r0, r5
	cmp r0, 0
	bgt _0809ADA8
	strb r6, [r4, 0x1D]
	adds r0, r5, 0x1
	b _0809AD9C
_0809AD8A:
	ldrb r0, [r4, 0x1D]
	cmp r0, 0
	beq _0809ADA8
	movs r0, 0xF
	ands r0, r5
	cmp r0, 0x1
	bgt _0809ADA8
	strb r6, [r4, 0x1D]
	adds r0, r5, 0x2
_0809AD9C:
	lsls r0, 24
	asrs r5, r0, 24
	movs r0, 0x40
	orrs r5, r0
	lsls r0, r5, 24
	asrs r5, r0, 24
_0809ADA8:
	ldr r0, [r4, 0x20]
	ldr r0, [r0, 0x4]
	str r0, [r4, 0x14]
	movs r0, 0xF
	ands r5, r0
	strb r5, [r4, 0x1C]
	b _0809ADBC
_0809ADB6:
	str r0, [r4, 0x10]
	str r0, [r4, 0x14]
	strb r6, [r4, 0x1C]
_0809ADBC:
	movs r0, 0x1
	b _0809ADD2
_0809ADC0:
	movs r0, 0xFF
	strb r0, [r4, 0x6]
	movs r0, 0
	strb r0, [r4, 0x7]
	str r0, [r4, 0x8]
	str r0, [r4, 0xC]
	str r0, [r4, 0x10]
	str r0, [r4, 0x14]
	strb r0, [r4, 0x1C]
_0809ADD2:
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end sub_809AC7C

	thumb_func_start sub_809ADD8
sub_809ADD8:
	push {r4,lr}
	adds r4, r1, 0
	lsls r0, 16
	asrs r0, 16
	ldr r2, _0809AE28
	lsls r1, r0, 3
	adds r1, r0
	lsls r1, 2
	ldr r0, _0809AE2C
	adds r1, r0
	ldr r0, [r2]
	adds r3, r0, r1
	movs r1, 0x2
	ldrsh r0, [r3, r1]
	cmp r0, 0
	blt _0809AE34
	cmp r0, 0
	beq _0809AE34
	ldr r0, [r4]
	ldr r1, [r4, 0x4]
	str r0, [r3, 0x8]
	str r1, [r3, 0xC]
	ldr r2, _0809AE30
	ldrb r0, [r3, 0x7]
	lsls r0, 3
	adds r0, r2
	ldr r1, [r3, 0x8]
	ldrh r0, [r0]
	adds r0, r1
	strh r0, [r3, 0x18]
	ldrb r0, [r3, 0x7]
	lsls r0, 3
	adds r0, r2
	ldr r1, [r3, 0xC]
	ldrh r0, [r0, 0x2]
	adds r0, r1
	strh r0, [r3, 0x1A]
	movs r0, 0x1
	b _0809AE36
	.align 2, 0
_0809AE28: .4byte gUnknown_3001B64
_0809AE2C: .4byte 0x0000043c
_0809AE30: .4byte gUnknown_8116040
_0809AE34:
	movs r0, 0
_0809AE36:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_809ADD8

	thumb_func_start sub_809AE3C
sub_809AE3C:
	push {r4,lr}
	lsls r0, 16
	asrs r2, r0, 16
	cmp r2, 0
	blt _0809AE88
	ldr r1, _0809AE80
	lsls r0, r2, 3
	adds r0, r2
	lsls r0, 2
	ldr r3, _0809AE84
	adds r0, r3
	ldr r1, [r1]
	adds r4, r1, r0
	movs r1, 0x2
	ldrsh r0, [r4, r1]
	cmp r0, 0
	beq _0809AE74
	movs r1, 0x6
	ldrsb r1, [r4, r1]
	movs r0, 0x1
	negs r0, r0
	cmp r1, r0
	bne _0809AE74
	adds r0, r2, 0
	movs r1, 0
	movs r2, 0
	bl sub_809AC7C
_0809AE74:
	ldr r0, [r4, 0x10]
	cmp r0, 0
	beq _0809AE88
	adds r0, r4, 0
	adds r0, 0x10
	b _0809AE8A
	.align 2, 0
_0809AE80: .4byte gUnknown_3001B64
_0809AE84: .4byte 0x0000043c
_0809AE88:
	movs r0, 0
_0809AE8A:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_809AE3C

	thumb_func_start ScriptPrintText
ScriptPrintText:
	push {r4-r6,lr}
	adds r5, r0, 0
	adds r4, r2, 0
	lsls r1, 16
	asrs r6, r1, 16
	cmp r4, 0
	bne _0809AEA4
	bl ScriptPrintNullTextbox
	b _0809AEE0
_0809AEA4:
	ldrb r0, [r4]
	cmp r0, 0
	beq _0809AEDC
	ldr r1, _0809AED0
	lsls r0, r5, 2
	adds r0, r1
	ldr r0, [r0]
	movs r1, 0
	bl xxx_script_textboxes_809A680
	ldr r0, _0809AED4
	ldr r0, [r0]
	adds r0, 0xC
	ldr r2, _0809AED8
	lsls r1, r5, 1
	adds r1, r2
	ldrh r1, [r1]
	adds r2, r6, 0
	adds r3, r4, 0
	bl ScriptPrintText_809B2B8
	b _0809AEE0
	.align 2, 0
_0809AED0: .4byte gUnknown_8116134
_0809AED4: .4byte gUnknown_3001B64
_0809AED8: .4byte gUnknown_8116148
_0809AEDC:
	bl ScriptPrintEmptyTextbox
_0809AEE0:
	lsls r0, 24
	lsrs r0, 24
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end ScriptPrintText

	thumb_func_start sub_809AEEC
sub_809AEEC:
	push {r4,lr}
	adds r4, r0, 0
	cmp r4, 0
	beq _0809AF1C
	ldrb r0, [r4]
	cmp r0, 0
	beq _0809AF1C
	movs r0, 0x2
	movs r1, 0x1
	bl xxx_script_textboxes_809A680
	ldr r0, _0809AF18
	ldr r0, [r0]
	adds r0, 0xC
	movs r2, 0x1
	negs r2, r2
	movs r1, 0xC2
	adds r3, r4, 0
	bl ScriptPrintText_809B2B8
	b _0809AF20
	.align 2, 0
_0809AF18: .4byte gUnknown_3001B64
_0809AF1C:
	bl ScriptPrintNullTextbox
_0809AF20:
	lsls r0, 24
	lsrs r0, 24
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_809AEEC

	thumb_func_start sub_809AF2C
sub_809AF2C:
	push {r4,lr}
	adds r4, r0, 0
	cmp r4, 0
	beq _0809AF5C
	ldrb r0, [r4]
	cmp r0, 0
	beq _0809AF5C
	movs r0, 0x2
	movs r1, 0x1
	bl xxx_script_textboxes_809A680
	ldr r0, _0809AF58
	ldr r0, [r0]
	adds r0, 0xC
	movs r2, 0x1
	negs r2, r2
	movs r1, 0xC2
	adds r3, r4, 0
	bl ScriptPrintText_809B2B8
	b _0809AF60
	.align 2, 0
_0809AF58: .4byte gUnknown_3001B64
_0809AF5C:
	bl ScriptPrintNullTextbox
_0809AF60:
	lsls r0, 24
	lsrs r0, 24
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_809AF2C

	thumb_func_start sub_809AF6C
sub_809AF6C:
	push {r4,lr}
	adds r4, r1, 0
	cmp r4, 0
	beq _0809AF9C
	ldrb r0, [r4]
	cmp r0, 0
	beq _0809AF9C
	movs r0, 0x3
	movs r1, 0x1
	bl xxx_script_textboxes_809A680
	ldr r0, _0809AF98
	ldr r0, [r0]
	adds r0, 0xC
	movs r2, 0x1
	negs r2, r2
	movs r1, 0x65
	adds r3, r4, 0
	bl ScriptPrintText_809B2B8
	b _0809AFA0
	.align 2, 0
_0809AF98: .4byte gUnknown_3001B64
_0809AF9C:
	bl ScriptPrintNullTextbox
_0809AFA0:
	lsls r0, 24
	lsrs r0, 24
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_809AF6C

	thumb_func_start sub_809AFAC
sub_809AFAC:
	push {lr}
	movs r1, 0
	ldr r0, _0809AFC4
	ldr r0, [r0]
	ldr r0, [r0]
	cmp r0, 0x4
	bne _0809AFBC
	movs r1, 0x1
_0809AFBC:
	adds r0, r1, 0
	pop {r1}
	bx r1
	.align 2, 0
_0809AFC4: .4byte gUnknown_3001B64
	thumb_func_end sub_809AFAC

	thumb_func_start sub_809AFC8
sub_809AFC8:
	push {r4,r5,lr}
	sub sp, 0x8
	adds r5, r1, 0
	adds r1, r2, 0
	lsls r0, 24
	lsrs r0, 24
	lsls r1, 16
	asrs r1, 16
	ldr r4, _0809AFF8
	negs r2, r0
	orrs r2, r0
	lsrs r2, 31
	str r1, [sp]
	str r3, [sp, 0x4]
	adds r0, r4, 0
	movs r1, 0
	adds r3, r5, 0
	bl sub_809B028
	add sp, 0x8
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_0809AFF8: .4byte gUnknown_81160E8
	thumb_func_end sub_809AFC8

	thumb_func_start sub_809AFFC
sub_809AFFC:
	push {r4,lr}
	sub sp, 0x4
	adds r4, r0, 0
	mov r0, sp
	bl sub_809B18C
	lsls r0, 24
	lsrs r2, r0, 24
	cmp r4, 0
	beq _0809B01C
	movs r1, 0
	ldr r0, [sp]
	cmp r0, 0x1
	bne _0809B01A
	movs r1, 0x1
_0809B01A:
	strb r1, [r4]
_0809B01C:
	adds r0, r2, 0
	add sp, 0x4
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_809AFFC

	thumb_func_start sub_809B028
sub_809B028:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0x14
	mov r8, r0
	adds r7, r2, 0
	adds r6, r3, 0
	ldr r0, [sp, 0x2C]
	lsls r1, 24
	lsrs r5, r1, 24
	lsls r0, 16
	asrs r4, r0, 16
	ldr r1, _0809B084
	lsls r0, r6, 2
	adds r0, r1
	ldr r0, [r0]
	movs r1, 0
	bl xxx_script_textboxes_809A680
	ldr r0, _0809B088
	ldr r1, [r0]
	ldr r0, _0809B08C
	adds r2, r1, r0
	movs r0, 0x1
	str r0, [r2]
	movs r0, 0x83
	lsls r0, 3
	adds r2, r1, r0
	movs r0, 0
	str r0, [r2]
	ldr r2, _0809B090
	adds r0, r1, r2
	mov r2, r8
	str r2, [r0]
	movs r2, 0x84
	lsls r2, 3
	adds r0, r1, r2
	movs r2, 0x2
	str r2, [r0]
	ldr r0, _0809B094
	adds r1, r0
	cmp r5, 0
	beq _0809B098
	str r2, [r1]
	b _0809B09A
	.align 2, 0
_0809B084: .4byte gUnknown_8116134
_0809B088: .4byte gUnknown_3001B64
_0809B08C: .4byte 0x00000414
_0809B090: .4byte 0x0000041c
_0809B094: .4byte 0x00000424
_0809B098:
	str r5, [r1]
_0809B09A:
	ldr r0, _0809B0D4
	ldr r0, [r0]
	movs r1, 0x85
	lsls r1, 3
	adds r2, r0, r1
	movs r1, 0
	str r1, [r2]
	movs r2, 0x86
	lsls r2, 3
	adds r0, r2
	str r7, [r0]
	ldr r0, _0809B0D8
	lsls r2, r6, 1
	adds r0, r2, r0
	ldrh r1, [r0]
	movs r0, 0x80
	lsls r0, 1
	ands r0, r1
	adds r5, r2, 0
	cmp r0, 0
	beq _0809B0F6
	cmp r4, 0
	bge _0809B0E4
	ldr r0, _0809B0DC
	ldr r1, _0809B0E0
	bl strcpy
	b _0809B0F6
	.align 2, 0
_0809B0D4: .4byte gUnknown_3001B64
_0809B0D8: .4byte gUnknown_8116148
_0809B0DC: .4byte gUnknown_202E5D8
_0809B0E0: .4byte gFormattedSpeechBubble
_0809B0E4:
	ldr r0, _0809B134
	ldr r1, _0809B138
	lsls r2, r4, 2
	adds r2, r4
	lsls r2, 4
	ldr r3, _0809B13C
	adds r2, r3
	bl sprintfStatic
_0809B0F6:
	adds r0, r4, 0
	bl sub_809AE3C
	ldr r4, _0809B140
	movs r1, 0
	str r1, [sp]
	movs r3, 0x4
	str r3, [sp, 0x4]
	str r1, [sp, 0x8]
	str r0, [sp, 0xC]
	ldr r0, _0809B144
	adds r0, r5, r0
	ldrh r2, [r0]
	movs r0, 0x80
	lsls r0, 1
	ands r0, r2
	cmp r0, 0
	beq _0809B11C
	movs r1, 0xC
_0809B11C:
	movs r0, 0x80
	lsls r0, 2
	ands r0, r2
	cmp r0, 0
	beq _0809B128
	orrs r1, r3
_0809B128:
	movs r0, 0x20
	ands r0, r2
	cmp r0, 0
	beq _0809B148
	movs r0, 0x21
	b _0809B14A
	.align 2, 0
_0809B134: .4byte gUnknown_202E5D8
_0809B138: .4byte gUnknown_8116188
_0809B13C: .4byte gPlayerName
_0809B140: .4byte sub_809B428
_0809B144: .4byte gUnknown_8116148
_0809B148:
	movs r0, 0x1
_0809B14A:
	orrs r0, r1
	lsls r0, 16
	lsrs r0, 16
	str r0, [sp, 0x10]
	ldr r0, [sp, 0x30]
	adds r1, r4, 0
	adds r2, r7, 0
	mov r3, r8
	bl sub_8014248
	ldr r0, _0809B184
	ldr r0, [r0]
	ldr r1, _0809B188
	adds r0, r1
	ldr r0, [r0]
	movs r1, 0x2
	ands r0, r1
	cmp r0, 0
	beq _0809B176
	movs r0, 0x1
	bl sub_809A6E4
_0809B176:
	add sp, 0x14
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_0809B184: .4byte gUnknown_3001B64
_0809B188: .4byte 0x00000424
	thumb_func_end sub_809B028

	thumb_func_start sub_809B18C
sub_809B18C:
	push {lr}
	adds r1, r0, 0
	ldr r2, _0809B1BC
	cmp r1, 0
	beq _0809B1A2
	ldr r0, [r2]
	movs r3, 0x86
	lsls r3, 3
	adds r0, r3
	ldr r0, [r0]
	str r0, [r1]
_0809B1A2:
	movs r1, 0
	ldr r0, [r2]
	movs r2, 0x84
	lsls r2, 3
	adds r0, r2
	ldr r0, [r0]
	cmp r0, 0x3
	bne _0809B1B4
	movs r1, 0x1
_0809B1B4:
	adds r0, r1, 0
	pop {r1}
	bx r1
	.align 2, 0
_0809B1BC: .4byte gUnknown_3001B64
	thumb_func_end sub_809B18C

	thumb_func_start sub_809B1C0
sub_809B1C0:
	push {lr}
	adds r3, r2, 0
	movs r2, 0
	bl sub_809B1D4
	lsls r0, 24
	lsrs r0, 24
	pop {r1}
	bx r1
	thumb_func_end sub_809B1C0

	thumb_func_start sub_809B1D4
sub_809B1D4:
	push {r4-r7,lr}
	adds r4, r0, 0
	adds r5, r1, 0
	adds r6, r2, 0
	adds r7, r3, 0
	cmp r4, 0xB
	beq _0809B1E8
	cmp r4, 0xC
	beq _0809B1F0
	b _0809B202
_0809B1E8:
	adds r0, r5, 0
	bl sub_8021700
	b _0809B1F8
_0809B1F0:
	bl sub_8001D88
	bl sub_802FCF0
_0809B1F8:
	lsls r0, 24
	cmp r0, 0
	beq _0809B202
	movs r0, 0
	b _0809B24C
_0809B202:
	movs r0, 0x4
	movs r1, 0
	bl xxx_script_textboxes_809A680
	ldr r0, _0809B254
	ldr r1, [r0]
	ldr r2, _0809B258
	adds r0, r1, r2
	str r4, [r0]
	movs r3, 0x83
	lsls r3, 3
	adds r0, r1, r3
	movs r2, 0
	str r2, [r0]
	adds r3, 0x4
	adds r0, r1, r3
	str r2, [r0]
	movs r0, 0x84
	lsls r0, 3
	adds r2, r1, r0
	movs r0, 0x1
	str r0, [r2]
	ldr r2, _0809B25C
	adds r0, r1, r2
	str r5, [r0]
	adds r3, 0xC
	adds r0, r1, r3
	str r6, [r0]
	adds r2, 0x8
	adds r0, r1, r2
	str r7, [r0]
	adds r3, 0x8
	adds r1, r3
	movs r0, 0x1
	negs r0, r0
	str r0, [r1]
	movs r0, 0x1
_0809B24C:
	pop {r4-r7}
	pop {r1}
	bx r1
	.align 2, 0
_0809B254: .4byte gUnknown_3001B64
_0809B258: .4byte 0x00000414
_0809B25C: .4byte 0x00000424
	thumb_func_end sub_809B1D4

	thumb_func_start sub_809B260
sub_809B260:
	push {lr}
	adds r1, r0, 0
	ldr r2, _0809B290
	cmp r1, 0
	beq _0809B276
	ldr r0, [r2]
	movs r3, 0x86
	lsls r3, 3
	adds r0, r3
	ldr r0, [r0]
	str r0, [r1]
_0809B276:
	movs r1, 0
	ldr r0, [r2]
	movs r2, 0x84
	lsls r2, 3
	adds r0, r2
	ldr r0, [r0]
	cmp r0, 0x3
	bne _0809B288
	movs r1, 0x1
_0809B288:
	adds r0, r1, 0
	pop {r1}
	bx r1
	.align 2, 0
_0809B290: .4byte gUnknown_3001B64
	thumb_func_end sub_809B260

	thumb_func_start ResetTextbox_809B294
ResetTextbox_809B294:
	push {lr}
	movs r0, 0x3
	bl SetCharacterMask
	ldr r0, _0809B2B4
	ldr r0, [r0]
	adds r0, 0xC
	movs r2, 0x1
	negs r2, r2
	movs r1, 0
	movs r3, 0
	bl ScriptPrintText_809B2B8
	pop {r0}
	bx r0
	.align 2, 0
_0809B2B4: .4byte gUnknown_3001B64
	thumb_func_end ResetTextbox_809B294

	thumb_func_start ScriptPrintText_809B2B8
ScriptPrintText_809B2B8:
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	sub sp, 0x14
	adds r4, r0, 0
	adds r7, r3, 0
	lsls r1, 16
	lsrs r5, r1, 16
	lsls r2, 16
	asrs r6, r2, 16
	strh r5, [r4]
	cmp r7, 0
	bne _0809B2F6
	cmp r5, 0
	bne _0809B2DE
	str r7, [r4, 0x4]
	movs r0, 0
	b _0809B3FC
_0809B2DE:
	movs r0, 0x4
	ands r0, r5
	cmp r0, 0
	bne _0809B2E8
	b _0809B3FA
_0809B2E8:
	bl sub_8014490
	movs r0, 0
	movs r1, 0x1
	bl xxx_script_textboxes_809A680
	b _0809B3FA
_0809B2F6:
	movs r0, 0x1
	str r0, [r4, 0x4]
	adds r0, 0xFF
	ands r0, r5
	cmp r0, 0
	beq _0809B32A
	cmp r6, 0
	bge _0809B318
	ldr r0, _0809B310
	ldr r1, _0809B314
	bl strcpy
	b _0809B32A
	.align 2, 0
_0809B310: .4byte gUnknown_202E5D8
_0809B314: .4byte gFormattedSpeechBubble
_0809B318:
	ldr r0, _0809B3D0
	ldr r1, _0809B3D4
	lsls r2, r6, 2
	adds r2, r6
	lsls r2, 4
	ldr r3, _0809B3D8
	adds r2, r3
	bl sprintfStatic
_0809B32A:
	ldr r0, _0809B3DC
	mov r8, r0
	ldr r0, [r0]
	ldr r0, [r0]
	cmp r0, 0x3
	bne _0809B344
	adds r4, 0x8
	ldr r1, _0809B3E0
	adds r0, r4, 0
	adds r2, r7, 0
	bl sprintfStatic
	adds r7, r4, 0
_0809B344:
	adds r0, r6, 0
	bl sub_809AE3C
	ldr r1, _0809B3E4
	mov r9, r1
	movs r1, 0x1
	negs r1, r1
	mov r12, r1
	movs r2, 0
	str r2, [sp]
	movs r1, 0x3
	str r1, [sp, 0x4]
	str r2, [sp, 0x8]
	str r0, [sp, 0xC]
	movs r6, 0x80
	lsls r6, 1
	adds r0, r5, 0
	ands r0, r6
	movs r1, 0
	cmp r0, 0
	beq _0809B370
	movs r1, 0xC
_0809B370:
	movs r4, 0x80
	lsls r4, 2
	adds r0, r5, 0
	ands r0, r4
	cmp r0, 0
	beq _0809B380
	movs r0, 0x4
	orrs r1, r0
_0809B380:
	mov r0, r8
	ldr r3, [r0]
	ldr r2, [r3]
	cmp r2, 0x3
	bne _0809B38E
	movs r0, 0x10
	orrs r1, r0
_0809B38E:
	cmp r2, 0x2
	bne _0809B396
	movs r0, 0x10
	orrs r1, r0
_0809B396:
	adds r2, r1, 0
	movs r1, 0x20
	adds r0, r5, 0
	ands r0, r1
	cmp r0, 0
	beq _0809B3A4
	orrs r2, r1
_0809B3A4:
	lsrs r1, r5, 6
	movs r0, 0x1
	ands r1, r0
	orrs r1, r2
	movs r0, 0x80
	ands r0, r5
	cmp r0, 0
	beq _0809B3B6
	orrs r1, r6
_0809B3B6:
	movs r0, 0x4
	ands r0, r5
	cmp r0, 0
	beq _0809B3C0
	orrs r1, r4
_0809B3C0:
	ldr r0, [r3, 0x4]
	cmp r0, r12
	beq _0809B3E8
	movs r0, 0x2
	orrs r0, r1
	lsls r0, 16
	b _0809B3EA
	.align 2, 0
_0809B3D0: .4byte gUnknown_202E5D8
_0809B3D4: .4byte gUnknown_8116188
_0809B3D8: .4byte gPlayerName
_0809B3DC: .4byte gUnknown_3001B64
_0809B3E0: .4byte gUnknown_8116190
_0809B3E4: .4byte sub_809B428
_0809B3E8:
	lsls r0, r1, 16
_0809B3EA:
	lsrs r0, 16
	str r0, [sp, 0x10]
	adds r0, r7, 0
	mov r1, r9
	mov r2, r12
	movs r3, 0
	bl sub_8014248
_0809B3FA:
	movs r0, 0x1
_0809B3FC:
	add sp, 0x14
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end ScriptPrintText_809B2B8

	thumb_func_start IsTextboxOpen_809B40C
IsTextboxOpen_809B40C:
	push {lr}
	ldr r0, [r0, 0x4]
	cmp r0, 0
	beq _0809B41C
	cmp r0, 0x3
	bhi _0809B420
	cmp r0, 0x2
	bcc _0809B420
_0809B41C:
	movs r0, 0
	b _0809B422
_0809B420:
	movs r0, 0x1
_0809B422:
	pop {r1}
	bx r1
	thumb_func_end IsTextboxOpen_809B40C

	thumb_func_start sub_809B428
sub_809B428:
	push {r4,r5,lr}
	adds r5, r0, 0
	adds r4, r2, 0
	ldrb r0, [r5, 0x2]
	cmp r0, 0x4F
	beq _0809B44C
	cmp r0, 0x4F
	bgt _0809B43E
	cmp r0, 0x49
	beq _0809B444
	b _0809B46A
_0809B43E:
	cmp r0, 0x57
	beq _0809B454
	b _0809B46A
_0809B444:
	movs r0, 0x1E
	bl sub_8099A34
	b _0809B462
_0809B44C:
	movs r0, 0x1E
	bl sub_8099A48
	b _0809B462
_0809B454:
	bl sub_8099B94
	lsls r0, 24
	cmp r0, 0
	beq _0809B462
	adds r0, r5, 0
	b _0809B46C
_0809B462:
	adds r1, r4, 0
	adds r1, 0x21
	movs r0, 0x1
	strb r0, [r1]
_0809B46A:
	movs r0, 0
_0809B46C:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_809B428

	thumb_func_start sub_809B474
sub_809B474:
	push {r4-r6,lr}
	ldr r0, _0809B498
	ldr r1, [r0]
	ldr r2, [r1]
	adds r6, r0, 0
	cmp r2, 0x3
	bls _0809B56E
	cmp r2, 0x4
	bne _0809B56E
	movs r5, 0x84
	lsls r5, 3
	adds r0, r1, r5
	ldr r0, [r0]
	cmp r0, 0x1
	beq _0809B49C
	cmp r0, 0x2
	beq _0809B508
	b _0809B56E
	.align 2, 0
_0809B498: .4byte gUnknown_3001B64
_0809B49C:
	bl sub_809B648
	lsls r0, 24
	cmp r0, 0
	bne _0809B4B0
	ldr r0, [r6]
	adds r0, r5
	movs r1, 0x3
	str r1, [r0]
	b _0809B4E8
_0809B4B0:
	ldr r0, [r6]
	movs r1, 0x83
	lsls r1, 3
	adds r0, r1
	ldr r4, [r0]
	cmp r4, 0
	beq _0809B4F8
	ldr r0, [r4, 0x4]
	cmp r0, 0
	beq _0809B4F2
	bl ResetTextbox_809B294
	ldr r0, [r4, 0x4]
	bl _call_via_r0
	lsls r0, 24
	cmp r0, 0
	bne _0809B4F2
	ldr r1, [r6]
	movs r3, 0x86
	lsls r3, 3
	adds r2, r1, r3
	movs r0, 0x1
	negs r0, r0
	str r0, [r2]
	adds r1, r5
	movs r0, 0x3
	str r0, [r1]
_0809B4E8:
	movs r0, 0
	movs r1, 0x1
	bl xxx_script_textboxes_809A680
	b _0809B56E
_0809B4F2:
	ldrh r0, [r4]
	bl sub_809A6E4
_0809B4F8:
	ldr r0, _0809B534
	ldr r1, [r0]
	movs r2, 0x84
	lsls r2, 3
	adds r1, r2
	movs r2, 0x2
	str r2, [r1]
	adds r6, r0, 0
_0809B508:
	ldr r0, [r6]
	movs r3, 0x83
	lsls r3, 3
	adds r0, r3
	ldr r4, [r0]
	cmp r4, 0
	beq _0809B54E
	ldr r0, [r4, 0xC]
	bl _call_via_r0
	adds r2, r0, 0
	cmp r2, 0x1
	bls _0809B56E
	ldr r0, [r6]
	movs r3, 0x86
	lsls r3, 3
	adds r1, r0, r3
	cmp r2, 0x2
	bne _0809B538
	movs r0, 0x1
	negs r0, r0
	b _0809B53A
	.align 2, 0
_0809B534: .4byte gUnknown_3001B64
_0809B538:
	movs r0, 0
_0809B53A:
	str r0, [r1]
	ldr r0, [r4, 0x8]
	cmp r0, 0
	beq _0809B546
	bl _call_via_r0
_0809B546:
	ldrh r0, [r4]
	bl sub_809A6F8
	b _0809B558
_0809B54E:
	bl sub_809B648
	lsls r0, 24
	cmp r0, 0
	bne _0809B56E
_0809B558:
	ldr r0, _0809B578
	ldr r0, [r0]
	movs r1, 0x84
	lsls r1, 3
	adds r0, r1
	movs r1, 0x3
	str r1, [r0]
	movs r0, 0
	movs r1, 0x1
	bl xxx_script_textboxes_809A680
_0809B56E:
	bl sub_809B57C
	pop {r4-r6}
	pop {r0}
	bx r0
	.align 2, 0
_0809B578: .4byte gUnknown_3001B64
	thumb_func_end sub_809B474

	thumb_func_start sub_809B57C
sub_809B57C:
	push {r4,r5,lr}
	sub sp, 0x8
	bl xxx_draw_string_80144C4
	ldr r5, _0809B5C8
	ldr r0, [r5]
	ldr r1, [r0]
	cmp r1, 0x3
	bhi _0809B5E4
	cmp r1, 0x1
	bcc _0809B5E4
	movs r4, 0x84
	lsls r4, 3
	adds r0, r4
	ldr r0, [r0]
	cmp r0, 0
	beq _0809B5CC
	cmp r0, 0x3
	beq _0809B5CC
	mov r0, sp
	bl sub_80144A4
	cmp r0, 0
	bne _0809B5E4
	ldr r1, [sp]
	movs r0, 0x1
	bl GroundScriptLock
	ldr r1, [r5]
	adds r2, r1, r4
	movs r0, 0x3
	str r0, [r2]
	movs r0, 0x86
	lsls r0, 3
	adds r1, r0
	ldr r0, [sp]
	str r0, [r1]
	b _0809B5E4
	.align 2, 0
_0809B5C8: .4byte gUnknown_3001B64
_0809B5CC:
	add r0, sp, 0x4
	bl sub_80144A4
	adds r4, r0, 0
	cmp r4, 0
	bne _0809B5E4
	movs r0, 0
	bl GroundScriptLockJumpZero
	ldr r0, _0809B5FC
	ldr r0, [r0]
	str r4, [r0]
_0809B5E4:
	ldr r0, _0809B5FC
	ldr r0, [r0]
	ldr r1, _0809B600
	adds r0, r1
	ldr r0, [r0]
	cmp r0, 0
	bge _0809B604
	movs r0, 0
	movs r1, 0
	bl sub_8005838
	b _0809B60C
	.align 2, 0
_0809B5FC: .4byte gUnknown_3001B64
_0809B600: .4byte 0x00000434
_0809B604:
	movs r0, 0
	movs r1, 0x5
	bl sub_8005838
_0809B60C:
	add sp, 0x8
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_809B57C

	thumb_func_start sub_809B614
sub_809B614:
	push {lr}
	bl sub_80060EC
	ldr r0, _0809B62C
	ldr r2, _0809B630
	ldrh r1, [r2]
	strh r1, [r0]
	ldr r0, _0809B634
	ands r0, r1
	strh r0, [r2]
	pop {r0}
	bx r0
	.align 2, 0
_0809B62C: .4byte gUnknown_20399DE
_0809B630: .4byte gUnknown_20399DC
_0809B634: .4byte 0x0000fffd
	thumb_func_end sub_809B614

	thumb_func_start sub_809B638
sub_809B638:
	push {lr}
	bl xxx_call_update_bg_vram
	pop {r0}
	bx r0
	thumb_func_end sub_809B638

	thumb_func_start nullsub_210
nullsub_210:
	bx lr
	thumb_func_end nullsub_210

	thumb_func_start sub_809B648
sub_809B648:
	push {r4-r6,lr}
	sub sp, 0x24
	ldr r0, _0809B66C
	ldr r1, [r0]
	ldr r2, _0809B670
	adds r1, r2
	ldr r1, [r1]
	subs r1, 0x2
	adds r6, r0, 0
	cmp r1, 0x2C
	bls _0809B662
	bl _0809C392
_0809B662:
	lsls r0, r1, 2
	ldr r1, _0809B674
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0809B66C: .4byte gUnknown_3001B64
_0809B670: .4byte 0x00000414
_0809B674: .4byte _0809B678
	.align 2, 0
_0809B678:
	.4byte _0809B72C
	.4byte _0809B772
	.4byte _0809B7AC
	.4byte _0809B834
	.4byte _0809B89C
	.4byte _0809B8FC
	.4byte _0809B91C
	.4byte _0809B944
	.4byte _0809B9D2
	.4byte _0809BA2A
	.4byte _0809BAA8
	.4byte _0809BB66
	.4byte _0809BBDA
	.4byte _0809BBDA
	.4byte _0809BC26
	.4byte _0809BC68
	.4byte _0809C1B4
	.4byte _0809BC78
	.4byte _0809C1C2
	.4byte _0809C1C2
	.4byte _0809C1C8
	.4byte _0809BCBC
	.4byte _0809BCBC
	.4byte _0809BD1C
	.4byte _0809BD64
	.4byte _0809BDE8
	.4byte _0809BE30
	.4byte _0809BE40
	.4byte _0809BE50
	.4byte _0809BE60
	.4byte _0809BE9C
	.4byte _0809BEB8
	.4byte _0809BED4
	.4byte _0809BF70
	.4byte _0809BFFC
	.4byte _0809C072
	.4byte _0809C0B8
	.4byte _0809C0FC
	.4byte _0809C148
	.4byte _0809C158
	.4byte _0809C168
	.4byte _0809C204
	.4byte _0809C238
	.4byte _0809C280
	.4byte _0809C32A
_0809B72C:
	ldr r2, [r6]
	movs r3, 0x84
	lsls r3, 3
	adds r0, r2, r3
	ldr r0, [r0]
	cmp r0, 0x1
	beq _0809B780
	ldr r0, _0809B754
	ldrh r0, [r0, 0x2]
	movs r1, 0x3
	ands r0, r1
	cmp r0, 0
	beq _0809B758
	movs r0, 0x86
	lsls r0, 3
	adds r1, r2, r0
	movs r0, 0x1
	str r0, [r1]
	bl _0809C392
	.align 2, 0
_0809B754: .4byte gRealInputs
_0809B758:
	bl sub_8094D14
	lsls r0, 24
	cmp r0, 0
	beq _0809B784
	ldr r0, [r6]
	movs r1, 0x86
	lsls r1, 3
	adds r0, r1
	movs r1, 0x2
	str r1, [r0]
	bl _0809C392
_0809B772:
	ldr r0, [r6]
	movs r2, 0x84
	lsls r2, 3
	adds r0, r2
	ldr r0, [r0]
	cmp r0, 0x1
	bne _0809B78A
_0809B780:
	bl ResetTextbox_809B294
_0809B784:
	movs r0, 0x1
	bl _0809C394
_0809B78A:
	ldr r0, _0809B7A8
	ldrh r1, [r0]
	ldrh r0, [r0, 0x2]
	movs r2, 0x2
	ands r0, r2
	cmp r0, 0
	beq _0809B79C
	bl _0809C392
_0809B79C:
	ands r1, r2
	cmp r1, 0
	bne _0809B784
	bl _0809C392
	.align 2, 0
_0809B7A8: .4byte gRealInputs
_0809B7AC:
	ldr r0, [r6]
	movs r3, 0x84
	lsls r3, 3
	adds r0, r3
	ldr r0, [r0]
	cmp r0, 0x1
	bne _0809B7F4
	bl ResetTextbox_809B294
	ldr r1, [r6]
	ldr r2, _0809B7D8
	adds r0, r1, r2
	ldr r0, [r0]
	cmp r0, 0
	bne _0809B7E0
	ldr r3, _0809B7DC
	adds r0, r1, r3
	ldr r1, [r0]
	movs r0, 0
	bl CreateConfirmNameMenu
	b _0809B784
	.align 2, 0
_0809B7D8: .4byte 0x00000424
_0809B7DC: .4byte 0x0000042c
_0809B7E0:
	ldr r2, _0809B7F0
	adds r0, r1, r2
	ldr r1, [r0]
	movs r0, 0x2
	bl CreateConfirmNameMenu
	b _0809B784
	.align 2, 0
_0809B7F0: .4byte 0x0000042c
_0809B7F4:
	bl sub_8016080
	cmp r0, 0x3
	bne _0809B80C
	bl CleanConfirmNameMenu
	ldr r0, [r6]
	movs r3, 0x86
	lsls r3, 3
	adds r0, r3
	bl _0809C1BC
_0809B80C:
	cmp r0, 0x2
	bne _0809B784
	ldr r0, [r6]
	ldr r1, _0809B830
	adds r0, r1
	ldr r0, [r0]
	cmp r0, 0
	beq _0809B784
	bl CleanConfirmNameMenu
	ldr r0, [r6]
	movs r2, 0x86
	lsls r2, 3
	adds r0, r2
_0809B828:
	movs r1, 0
	str r1, [r0]
	bl _0809C392
	.align 2, 0
_0809B830: .4byte 0x00000424
_0809B834:
	ldr r0, [r6]
	movs r3, 0x84
	lsls r3, 3
	adds r0, r3
	ldr r0, [r0]
	cmp r0, 0x1
	bne _0809B85C
	bl ResetTextbox_809B294
	ldr r0, [r6]
	ldr r1, _0809B858
	adds r0, r1
	ldr r1, [r0]
	movs r0, 0x1
	bl CreateConfirmNameMenu
	b _0809B784
	.align 2, 0
_0809B858: .4byte 0x0000042c
_0809B85C:
	bl sub_8016080
	cmp r0, 0x3
	bne _0809B874
	bl CleanConfirmNameMenu
	ldr r0, [r6]
	movs r2, 0x86
	lsls r2, 3
	adds r0, r2
	bl _0809C1BC
_0809B874:
	cmp r0, 0x2
	beq _0809B87A
	b _0809B784
_0809B87A:
	ldr r0, [r6]
	ldr r3, _0809B898
	adds r0, r3
	ldr r0, [r0]
	cmp r0, 0
	bne _0809B888
	b _0809B784
_0809B888:
	bl CleanConfirmNameMenu
	ldr r0, [r6]
	movs r1, 0x86
	lsls r1, 3
	adds r0, r1
	b _0809B828
	.align 2, 0
_0809B898: .4byte 0x00000424
_0809B89C:
	ldr r0, [r6]
	movs r2, 0x84
	lsls r2, 3
	adds r0, r2
	ldr r0, [r0]
	cmp r0, 0x1
	bne _0809B8C4
	bl ResetTextbox_809B294
	ldr r0, [r6]
	ldr r3, _0809B8C0
	adds r0, r3
	ldr r1, [r0]
	movs r0, 0x4
	bl sub_80151C0
	b _0809B784
	.align 2, 0
_0809B8C0: .4byte 0x0000042c
_0809B8C4:
	bl sub_80154F0
	cmp r0, 0x3
	bne _0809B8D4
	bl sub_80155F0
	bl _0809C1B4
_0809B8D4:
	cmp r0, 0x2
	beq _0809B8DA
	b _0809B784
_0809B8DA:
	ldr r0, [r6]
	ldr r2, _0809B8F8
	adds r0, r2
	ldr r0, [r0]
	cmp r0, 0
	bne _0809B8E8
	b _0809B784
_0809B8E8:
	bl sub_80155F0
	ldr r0, [r6]
	movs r3, 0x86
	lsls r3, 3
	adds r0, r3
	b _0809B828
	.align 2, 0
_0809B8F8: .4byte 0x00000424
_0809B8FC:
	ldr r0, [r6]
	ldr r1, _0809B914
	adds r0, r1
	ldr r0, [r0]
	bl sub_801D014
	ldr r0, [r6]
	movs r2, 0x83
	lsls r2, 3
	adds r0, r2
	ldr r1, _0809B918
	b _0809B932
	.align 2, 0
_0809B914: .4byte 0x0000042c
_0809B918: .4byte gUnknown_81161A8
_0809B91C:
	ldr r0, [r6]
	ldr r3, _0809B93C
	adds r0, r3
	ldr r0, [r0]
	bl sub_801D014
	ldr r0, [r6]
	movs r1, 0x83
	lsls r1, 3
	adds r0, r1
	ldr r1, _0809B940
_0809B932:
	str r1, [r0]
	movs r0, 0x4
	bl PlayMenuSoundEffect
	b _0809B784
	.align 2, 0
_0809B93C: .4byte 0x0000042c
_0809B940: .4byte gUnknown_81161B8
_0809B944:
	bl ResetTextbox_809B294
	ldr r4, _0809B984
	ldr r0, [r4]
	movs r2, 0x84
	lsls r2, 3
	adds r0, r2
	ldr r0, [r0]
	cmp r0, 0x1
	bne _0809B998
	bl ResetTextbox_809B294
	ldr r0, [r4]
	ldr r3, _0809B988
	adds r0, r3
	ldr r0, [r0]
	ldr r1, _0809B98C
	bl sub_8015080
	lsls r0, 24
	cmp r0, 0
	bne _0809B990
	ldr r0, [r4]
_0809B972:
	movs r1, 0x86
	lsls r1, 3
	adds r0, r1
_0809B978:
	movs r1, 0x1
	negs r1, r1
	str r1, [r0]
	bl _0809C392
	.align 2, 0
_0809B984: .4byte gUnknown_3001B64
_0809B988: .4byte 0x0000042c
_0809B98C: .4byte gUnknown_811610C
_0809B990:
	movs r0, 0x4
	bl PlayMenuSoundEffect
	b _0809B784
_0809B998:
	bl sub_801516C
	cmp r0, 0x2
	beq _0809B9BC
	cmp r0, 0x3
	beq _0809B9A6
	b _0809B784
_0809B9A6:
	bl sub_8015198
	ldr r1, [r4]
	movs r2, 0x86
	lsls r2, 3
	adds r1, r2
	str r0, [r1]
	bl sub_80151A4
	bl _0809C392
_0809B9BC:
	ldr r0, [r4]
	movs r3, 0x86
	lsls r3, 3
	adds r0, r3
	movs r1, 0x1
	negs r1, r1
	str r1, [r0]
	bl sub_80151A4
	bl _0809C392
_0809B9D2:
	bl ResetTextbox_809B294
	ldr r4, _0809BA08
	ldr r0, [r4]
	movs r1, 0x84
	lsls r1, 3
	adds r0, r1
	ldr r0, [r0]
	cmp r0, 0x1
	bne _0809BA1C
	bl ResetTextbox_809B294
	ldr r0, [r4]
	ldr r2, _0809BA0C
	adds r0, r2
	ldr r0, [r0]
	ldr r1, _0809BA10
	bl sub_8015080
	lsls r0, 24
	cmp r0, 0
	bne _0809BA14
	ldr r0, [r4]
	movs r3, 0x86
	lsls r3, 3
	adds r0, r3
	b _0809B978
	.align 2, 0
_0809BA08: .4byte gUnknown_3001B64
_0809BA0C: .4byte 0x0000042c
_0809BA10: .4byte gUnknown_811612C
_0809BA14:
	movs r0, 0x4
	bl PlayMenuSoundEffect
	b _0809B784
_0809BA1C:
	bl sub_801516C
	cmp r0, 0x2
	beq _0809B9BC
	cmp r0, 0x3
	beq _0809B9A6
	b _0809B784
_0809BA2A:
	ldr r0, [r6]
	movs r1, 0x84
	lsls r1, 3
	adds r0, r1
	ldr r0, [r0]
	cmp r0, 0x1
	bne _0809BA68
	bl ResetTextbox_809B294
	ldr r0, [r6]
	ldr r2, _0809BA5C
	adds r0, r2
	ldr r0, [r0]
	movs r1, 0x3
	bl sub_80211AC
	lsls r0, 24
	cmp r0, 0
	bne _0809BA60
	ldr r0, [r6]
	movs r3, 0x86
	lsls r3, 3
	adds r0, r3
	b _0809B978
	.align 2, 0
_0809BA5C: .4byte 0x00000424
_0809BA60:
	movs r0, 0x4
	bl PlayMenuSoundEffect
	b _0809B784
_0809BA68:
	movs r0, 0x1
	bl sub_8021274
	cmp r0, 0x2
	beq _0809BA92
	cmp r0, 0x3
	beq _0809BA78
	b _0809B784
_0809BA78:
	bl sub_802132C
	ldr r1, [r6]
	movs r2, 0x86
	lsls r2, 3
	adds r1, r2
	lsls r0, 24
	lsrs r0, 24
	str r0, [r1]
	bl sub_80213A0
	bl _0809C392
_0809BA92:
	ldr r0, [r6]
	movs r3, 0x86
	lsls r3, 3
	adds r0, r3
	movs r1, 0x1
	negs r1, r1
	str r1, [r0]
	bl sub_80213A0
	bl _0809C392
_0809BAA8:
	ldr r0, [r6]
	movs r1, 0x84
	lsls r1, 3
	adds r0, r1
	ldr r0, [r0]
	cmp r0, 0x1
	bne _0809BB10
	movs r0, 0
	movs r1, 0x12
	bl GetScriptVarValue
	lsls r0, 16
	asrs r0, 16
	bl sub_80A2654
	lsls r0, 16
	asrs r4, r0, 16
	bl ResetTextbox_809B294
	movs r0, 0x3
	movs r1, 0
	movs r2, 0xA
	movs r3, 0x1
	bl sub_802F73C
	lsls r0, 24
	cmp r0, 0
	bne _0809BAEA
	ldr r0, [r6]
	movs r2, 0x86
	lsls r2, 3
	adds r0, r2
	b _0809B978
_0809BAEA:
	movs r5, 0x1
	negs r5, r5
	cmp r4, r5
	beq _0809BB08
	adds r0, r4, 0
	bl sub_802F848
	lsls r0, 24
	cmp r0, 0
	bne _0809BB08
	movs r0, 0
	movs r1, 0x12
	adds r2, r5, 0
	bl SetScriptVarValue
_0809BB08:
	movs r0, 0x4
	bl PlayMenuSoundEffect
	b _0809B784
_0809BB10:
	movs r0, 0x1
	bl sub_802F8A0
	cmp r0, 0x2
	beq _0809BB50
	cmp r0, 0x3
	beq _0809BB20
	b _0809B784
_0809BB20:
	bl sub_802F90C
	adds r4, r0, 0
	lsls r4, 16
	asrs r4, 16
	adds r0, r4, 0
	bl sub_80A26B8
	adds r2, r0, 0
	lsls r2, 16
	asrs r2, 16
	movs r0, 0
	movs r1, 0x12
	bl SetScriptVarValue
	ldr r0, [r6]
	movs r3, 0x86
	lsls r3, 3
	adds r0, r3
	str r4, [r0]
	bl sub_802F974
	bl _0809C392
_0809BB50:
	ldr r0, [r6]
	movs r1, 0x86
	lsls r1, 3
	adds r0, r1
	movs r1, 0x1
	negs r1, r1
	str r1, [r0]
	bl sub_802F974
	bl _0809C392
_0809BB66:
	ldr r0, [r6]
	movs r2, 0x84
	lsls r2, 3
	adds r0, r2
	ldr r0, [r0]
	cmp r0, 0x1
	bne _0809BB9A
	bl ResetTextbox_809B294
	movs r0, 0x3
	movs r1, 0
	movs r2, 0xA
	bl sub_80302E8
	lsls r0, 24
	cmp r0, 0
	bne _0809BB92
	ldr r0, [r6]
	movs r3, 0x86
	lsls r3, 3
	adds r0, r3
	b _0809B978
_0809BB92:
	movs r0, 0x4
	bl PlayMenuSoundEffect
	b _0809B784
_0809BB9A:
	movs r0, 0x1
	bl sub_80303AC
	cmp r0, 0x2
	beq _0809BBC4
	cmp r0, 0x3
	beq _0809BBAA
	b _0809B784
_0809BBAA:
	bl sub_8030418
	ldr r1, [r6]
	movs r2, 0x86
	lsls r2, 3
	adds r1, r2
	lsls r0, 16
	asrs r0, 16
	str r0, [r1]
	bl sub_8030480
	bl _0809C392
_0809BBC4:
	ldr r0, [r6]
	movs r3, 0x86
	lsls r3, 3
	adds r0, r3
	movs r1, 0x1
	negs r1, r1
	str r1, [r0]
	bl sub_8030480
	bl _0809C392
_0809BBDA:
	ldr r0, [r6]
	movs r1, 0x84
	lsls r1, 3
	adds r0, r1
	ldr r0, [r0]
	cmp r0, 0x1
	bne _0809BC14
	bl ResetTextbox_809B294
	ldr r0, [r6]
	ldr r2, _0809BC10
	adds r0, r2
	ldr r0, [r0]
	cmp r0, 0xE
	bne _0809BC02
	movs r0, 0
	movs r1, 0x18
	movs r2, 0x1
	bl SetScriptVarValue
_0809BC02:
	movs r0, 0x1
	bl sub_8011C28
	movs r0, 0
	bl PrepareSavePakWrite
	b _0809B784
	.align 2, 0
_0809BC10: .4byte 0x00000414
_0809BC14:
	bl WriteSavePak
	lsls r0, 24
	cmp r0, 0
	beq _0809BC20
	b _0809B784
_0809BC20:
	bl FinishWriteSavePak
	b _0809C392
_0809BC26:
	movs r0, 0x4
	bl sub_80023E4
	lsls r0, 24
	lsrs r0, 24
	negs r4, r0
	orrs r4, r0
	lsrs r4, 31
	bl ResetTextbox_809B294
	adds r0, r4, 0
	bl CreateKangaskhanStorage
	lsls r0, 24
	cmp r0, 0
	beq _0809BC5C
	ldr r0, _0809BC54
	ldr r0, [r0]
	movs r3, 0x83
	lsls r3, 3
	adds r0, r3
	ldr r1, _0809BC58
	b _0809C266
	.align 2, 0
_0809BC54: .4byte gUnknown_3001B64
_0809BC58: .4byte gUnknown_81161C8
_0809BC5C:
	ldr r0, _0809BC64
	ldr r0, [r0]
	b _0809B972
	.align 2, 0
_0809BC64: .4byte gUnknown_3001B64
_0809BC68:
	ldr r0, [r6]
	movs r2, 0x83
	lsls r2, 3
	adds r0, r2
	ldr r1, _0809BC74
	b _0809C266
	.align 2, 0
_0809BC74: .4byte gUnknown_81161D8
_0809BC78:
	movs r0, 0x4
	bl sub_80023E4
	lsls r0, 24
	lsrs r0, 24
	negs r4, r0
	orrs r4, r0
	lsrs r4, 31
	bl ResetTextbox_809B294
	adds r0, r4, 0
	bl CreateFelicityBank
	lsls r0, 24
	cmp r0, 0
	beq _0809BCB0
	ldr r0, _0809BCA8
	ldr r0, [r0]
	movs r3, 0x83
	lsls r3, 3
	adds r0, r3
	ldr r1, _0809BCAC
	b _0809C266
	.align 2, 0
_0809BCA8: .4byte gUnknown_3001B64
_0809BCAC: .4byte gUnknown_81161E8
_0809BCB0:
	ldr r0, _0809BCB8
	ldr r0, [r0]
	b _0809B972
	.align 2, 0
_0809BCB8: .4byte gUnknown_3001B64
_0809BCBC:
	movs r0, 0x4
	bl sub_80023E4
	lsls r0, 24
	lsrs r4, r0, 24
	bl ResetTextbox_809B294
	ldr r0, _0809BCE0
	ldr r0, [r0]
	ldr r2, _0809BCE4
	adds r0, r2
	ldr r0, [r0]
	cmp r0, 0x17
	bne _0809BCE8
	negs r0, r4
	orrs r0, r4
	lsrs r0, 31
	b _0809BCF0
	.align 2, 0
_0809BCE0: .4byte gUnknown_3001B64
_0809BCE4: .4byte 0x00000414
_0809BCE8:
	movs r0, 0x2
	cmp r4, 0
	beq _0809BCF0
	movs r0, 0x3
_0809BCF0:
	bl CreateKecleonBros
	lsls r0, 24
	cmp r0, 0
	beq _0809BD10
	ldr r0, _0809BD08
	ldr r0, [r0]
	movs r3, 0x83
	lsls r3, 3
	adds r0, r3
	ldr r1, _0809BD0C
	b _0809C266
	.align 2, 0
_0809BD08: .4byte gUnknown_3001B64
_0809BD0C: .4byte gUnknown_81161F8
_0809BD10:
	ldr r0, _0809BD18
	ldr r0, [r0]
	b _0809B972
	.align 2, 0
_0809BD18: .4byte gUnknown_3001B64
_0809BD1C:
	movs r0, 0x4
	bl sub_80023E4
	lsls r0, 24
	lsrs r0, 24
	negs r4, r0
	orrs r4, r0
	lsrs r4, 31
	bl ResetTextbox_809B294
	adds r0, r4, 0
	bl sub_801FB50
	lsls r0, 24
	cmp r0, 0
	beq _0809BD54
	ldr r0, _0809BD4C
	ldr r0, [r0]
	movs r2, 0x83
	lsls r2, 3
	adds r0, r2
	ldr r1, _0809BD50
	b _0809C266
	.align 2, 0
_0809BD4C: .4byte gUnknown_3001B64
_0809BD50: .4byte gUnknown_8116208
_0809BD54:
	ldr r0, _0809BD60
	ldr r0, [r0]
	movs r3, 0x86
	lsls r3, 3
	adds r0, r3
	b _0809B978
	.align 2, 0
_0809BD60: .4byte gUnknown_3001B64
_0809BD64:
	ldr r0, [r6]
	movs r1, 0x84
	lsls r1, 3
	adds r0, r1
	ldr r0, [r0]
	cmp r0, 0x1
	bne _0809BD84
	bl ResetTextbox_809B294
	movs r0, 0
	movs r1, 0x39
	bl ClearScriptVarArray
	bl sub_802465C
	b _0809B784
_0809BD84:
	bl sub_80246F0
	adds r4, r0, 0
	movs r0, 0
	movs r1, 0x39
	bl GetScriptVarValue
	cmp r0, 0
	bne _0809BDB2
	bl HasEvolutionCompleted
	lsls r0, 24
	cmp r0, 0
	beq _0809BDB2
	movs r0, 0
	movs r1, 0x39
	movs r2, 0x1
	bl SetScriptVarValue
	movs r0, 0x46
	movs r1, 0
	bl GroundMap_ExecuteEvent
_0809BDB2:
	cmp r4, 0x3
	bne _0809BDCC
	bl CleanLuminousCave
	ldr r0, _0809BDC8
	ldr r0, [r0]
	movs r2, 0x86
	lsls r2, 3
	adds r0, r2
	b _0809C1BC
	.align 2, 0
_0809BDC8: .4byte gUnknown_3001B64
_0809BDCC:
	cmp r4, 0x2
	beq _0809BDD2
	b _0809B784
_0809BDD2:
	bl CleanLuminousCave
	ldr r0, _0809BDE4
	ldr r0, [r0]
	movs r3, 0x86
	lsls r3, 3
	adds r0, r3
	b _0809B828
	.align 2, 0
_0809BDE4: .4byte gUnknown_3001B64
_0809BDE8:
	movs r0, 0x4
	bl sub_80023E4
	lsls r0, 24
	lsrs r0, 24
	negs r4, r0
	orrs r4, r0
	lsrs r4, 31
	bl ResetTextbox_809B294
	adds r0, r4, 0
	bl CreateWigglytuffShop
	lsls r0, 24
	cmp r0, 0
	beq _0809BE20
	ldr r0, _0809BE18
	ldr r0, [r0]
	movs r1, 0x83
	lsls r1, 3
	adds r0, r1
	ldr r1, _0809BE1C
	b _0809C266
	.align 2, 0
_0809BE18: .4byte gUnknown_3001B64
_0809BE1C: .4byte gUnknown_8116218
_0809BE20:
	ldr r0, _0809BE2C
	ldr r0, [r0]
	movs r2, 0x86
	lsls r2, 3
	adds r0, r2
	b _0809B978
	.align 2, 0
_0809BE2C: .4byte gUnknown_3001B64
_0809BE30:
	ldr r0, [r6]
	movs r3, 0x83
	lsls r3, 3
	adds r0, r3
	ldr r1, _0809BE3C
	b _0809C266
	.align 2, 0
_0809BE3C: .4byte gUnknown_8116228
_0809BE40:
	ldr r0, [r6]
	movs r1, 0x83
	lsls r1, 3
	adds r0, r1
	ldr r1, _0809BE4C
	b _0809C266
	.align 2, 0
_0809BE4C: .4byte gUnknown_8116238
_0809BE50:
	ldr r0, [r6]
	movs r2, 0x83
	lsls r2, 3
	adds r0, r2
	ldr r1, _0809BE5C
	b _0809C266
	.align 2, 0
_0809BE5C: .4byte gUnknown_8116248
_0809BE60:
	bl ResetTextbox_809B294
	movs r0, 0x98
	lsls r0, 1
	bl CreateHelperPelipperMenu
	lsls r0, 24
	cmp r0, 0
	bne _0809BE84
	ldr r0, _0809BE80
	ldr r0, [r0]
	movs r3, 0x86
	lsls r3, 3
	adds r0, r3
	b _0809B978
	.align 2, 0
_0809BE80: .4byte gUnknown_3001B64
_0809BE84:
	ldr r0, _0809BE94
	ldr r0, [r0]
	movs r1, 0x83
	lsls r1, 3
	adds r0, r1
	ldr r1, _0809BE98
	b _0809C266
	.align 2, 0
_0809BE94: .4byte gUnknown_3001B64
_0809BE98: .4byte gUnknown_8116258
_0809BE9C:
	movs r0, 0x4
	bl PlayMenuSoundEffect
	ldr r0, _0809BEB0
	ldr r0, [r0]
	movs r2, 0x83
	lsls r2, 3
	adds r0, r2
	ldr r1, _0809BEB4
	b _0809C266
	.align 2, 0
_0809BEB0: .4byte gUnknown_3001B64
_0809BEB4: .4byte gUnknown_8116268
_0809BEB8:
	movs r0, 0x4
	bl PlayMenuSoundEffect
	ldr r0, _0809BECC
	ldr r0, [r0]
	movs r3, 0x83
	lsls r3, 3
	adds r0, r3
	ldr r1, _0809BED0
	b _0809C266
	.align 2, 0
_0809BECC: .4byte gUnknown_3001B64
_0809BED0: .4byte gUnknown_8116278
_0809BED4:
	mov r0, sp
	bl sub_8099328
	lsls r0, 24
	cmp r0, 0
	beq _0809BF4E
	add r1, sp, 0x4
	add r2, sp, 0x8
	movs r0, 0x2
	bl GetScriptVarScenario
	ldr r0, [sp, 0x8]
	cmp r0, 0x7
	bgt _0809BF4E
	add r4, sp, 0xC
_0809BEF2:
	lsls r1, r0, 24
	lsrs r1, 24
	mov r0, sp
	ldrb r2, [r0]
	adds r0, r4, 0
	bl sub_8096AF8
	ldrb r0, [r4]
	cmp r0, 0
	beq _0809BF44
	ldr r1, [sp, 0x4]
	ldr r2, [sp, 0x8]
	movs r0, 0x2
	bl ScenarioCalc
	ldr r0, _0809BF40
	ldr r0, [r0]
	movs r1, 0x86
	lsls r1, 3
	adds r2, r0, r1
	ldrh r1, [r4, 0x2]
	lsls r1, 16
	asrs r1, 16
	negs r0, r1
	orrs r0, r1
	lsrs r1, r0, 31
	movs r3, 0x4
	ldrsh r0, [r4, r3]
	cmp r0, 0
	beq _0809BF30
	adds r1, 0x2
_0809BF30:
	str r1, [r2]
	cmp r1, 0
	beq _0809BF38
	b _0809C392
_0809BF38:
	movs r0, 0x3
	str r0, [r2]
	b _0809C392
	.align 2, 0
_0809BF40: .4byte gUnknown_3001B64
_0809BF44:
	ldr r0, [sp, 0x8]
	adds r0, 0x1
	str r0, [sp, 0x8]
	cmp r0, 0x7
	ble _0809BEF2
_0809BF4E:
	ldr r0, _0809BF6C
	ldr r0, [r0]
	movs r1, 0x86
	lsls r1, 3
	adds r0, r1
	movs r1, 0
	str r1, [r0]
	bl sub_8096BD0
	movs r0, 0x2
	movs r1, 0
	movs r2, 0
	bl ScenarioCalc
	b _0809C392
	.align 2, 0
_0809BF6C: .4byte gUnknown_3001B64
_0809BF70:
	mov r5, sp
	adds r5, 0x1
	adds r0, r5, 0
	bl sub_8099328
	lsls r0, 24
	cmp r0, 0
	bne _0809BF82
	b _0809C392
_0809BF82:
	add r1, sp, 0x14
	add r2, sp, 0x18
	movs r0, 0x2
	bl GetScriptVarScenario
	add r4, sp, 0x1C
	ldr r1, [sp, 0x18]
	lsls r1, 24
	lsrs r1, 24
	ldrb r2, [r5]
	adds r0, r4, 0
	bl sub_8096AF8
	ldrb r0, [r4]
	cmp r0, 0
	bne _0809BFA4
	b _0809C392
_0809BFA4:
	ldr r0, [sp, 0x18]
	lsls r0, 24
	lsrs r0, 24
	ldrb r1, [r5]
	bl sub_802DB28
	lsls r0, 24
	cmp r0, 0
	bne _0809BFB8
	b _0809C392
_0809BFB8:
	movs r0, 0
	movs r1, 0x19
	bl GetScriptVarValue
	cmp r0, 0x63
	bgt _0809BFCE
	adds r2, r0, 0x1
	movs r0, 0
	movs r1, 0x19
	bl SetScriptVarValue
_0809BFCE:
	movs r0, 0
	movs r1, 0x39
	movs r2, 0x1
	bl SetScriptVarValue
	ldr r1, [sp, 0x14]
	ldr r2, [sp, 0x18]
	adds r2, 0x1
	movs r0, 0x2
	bl ScenarioCalc
	ldr r0, _0809BFF4
	ldr r0, [r0]
	movs r2, 0x83
	lsls r2, 3
	adds r0, r2
	ldr r1, _0809BFF8
	b _0809C266
	.align 2, 0
_0809BFF4: .4byte gUnknown_3001B64
_0809BFF8: .4byte gUnknown_8116288
_0809BFFC:
	ldr r0, [r6]
	movs r3, 0x84
	lsls r3, 3
	adds r0, r3
	ldr r0, [r0]
	cmp r0, 0x1
	bne _0809C036
	movs r0, 0x4
	bl sub_80023E4
	lsls r0, 24
	lsrs r0, 24
	negs r4, r0
	orrs r4, r0
	asrs r4, 31
	movs r0, 0x4
	ands r4, r0
	bl ResetTextbox_809B294
	adds r0, r4, 0
	bl MakuhitaDojo_New
	lsls r0, 24
	cmp r0, 0
	beq _0809C032
	bl _0809B784
_0809C032:
	ldr r0, [r6]
	b _0809B972
_0809C036:
	bl HandleMakuhitaDojoState
	cmp r0, 0x2
	beq _0809C05E
	cmp r0, 0x3
	beq _0809C046
	bl _0809B784
_0809C046:
	bl sub_802FED0
	ldr r1, [r6]
	movs r2, 0x86
	lsls r2, 3
	adds r1, r2
	lsls r0, 16
	asrs r0, 16
	str r0, [r1]
	bl MakuhitaDojo_Delete
	b _0809C392
_0809C05E:
	ldr r0, [r6]
	movs r3, 0x86
	lsls r3, 3
	adds r0, r3
	movs r1, 0x1
	negs r1, r1
	str r1, [r0]
	bl MakuhitaDojo_Delete
	b _0809C392
_0809C072:
	movs r4, 0x1
	movs r0, 0x4
	bl sub_80023E4
	lsls r0, 24
	cmp r0, 0
	beq _0809C082
	movs r4, 0x5
_0809C082:
	bl ResetTextbox_809B294
	adds r0, r4, 0
	bl MakuhitaDojo_New
	lsls r0, 24
	cmp r0, 0
	beq _0809C0A8
	ldr r0, _0809C0A0
	ldr r0, [r0]
	movs r1, 0x83
	lsls r1, 3
	adds r0, r1
	ldr r1, _0809C0A4
	b _0809C266
	.align 2, 0
_0809C0A0: .4byte gUnknown_3001B64
_0809C0A4: .4byte gUnknown_8116298
_0809C0A8:
	ldr r0, _0809C0B4
	ldr r0, [r0]
	movs r2, 0x86
	lsls r2, 3
	adds r0, r2
	b _0809B978
	.align 2, 0
_0809C0B4: .4byte gUnknown_3001B64
_0809C0B8:
	movs r4, 0x2
	movs r0, 0x4
	bl sub_80023E4
	lsls r0, 24
	cmp r0, 0
	beq _0809C0C8
	movs r4, 0x6
_0809C0C8:
	bl ResetTextbox_809B294
	adds r0, r4, 0
	bl MakuhitaDojo_New
	lsls r0, 24
	cmp r0, 0
	beq _0809C0F0
	ldr r0, _0809C0E8
	ldr r0, [r0]
	movs r3, 0x83
	lsls r3, 3
	adds r0, r3
	ldr r1, _0809C0EC
	b _0809C266
	.align 2, 0
_0809C0E8: .4byte gUnknown_3001B64
_0809C0EC: .4byte gUnknown_81162A8
_0809C0F0:
	ldr r0, _0809C0F8
	ldr r0, [r0]
	b _0809B972
	.align 2, 0
_0809C0F8: .4byte gUnknown_3001B64
_0809C0FC:
	movs r4, 0x3
	movs r0, 0x4
	bl sub_80023E4
	lsls r0, 24
	cmp r0, 0
	beq _0809C10C
	movs r4, 0x7
_0809C10C:
	bl ResetTextbox_809B294
	adds r0, r4, 0
	bl MakuhitaDojo_New
	lsls r0, 24
	cmp r0, 0
	beq _0809C134
	ldr r0, _0809C12C
	ldr r0, [r0]
	movs r2, 0x83
	lsls r2, 3
	adds r0, r2
	ldr r1, _0809C130
	b _0809C266
	.align 2, 0
_0809C12C: .4byte gUnknown_3001B64
_0809C130: .4byte gUnknown_81162B8
_0809C134:
	ldr r0, _0809C144
	ldr r0, [r0]
	movs r3, 0x86
	lsls r3, 3
	adds r0, r3
	bl _0809B978
	.align 2, 0
_0809C144: .4byte gUnknown_3001B64
_0809C148:
	ldr r0, [r6]
	movs r1, 0x83
	lsls r1, 3
	adds r0, r1
	ldr r1, _0809C154
	b _0809C266
	.align 2, 0
_0809C154: .4byte gUnknown_81162C8
_0809C158:
	ldr r0, [r6]
	movs r2, 0x83
	lsls r2, 3
	adds r0, r2
	ldr r1, _0809C164
	b _0809C266
	.align 2, 0
_0809C164: .4byte gUnknown_81162D8
_0809C168:
	bl ResetTextbox_809B294
	bl sub_803B050
	lsls r0, 24
	cmp r0, 0
	beq _0809C1A0
	ldr r4, _0809C194
	ldr r0, [r4]
	ldr r3, _0809C198
	adds r0, r3
	movs r1, 0
	ldrsh r0, [r0, r1]
	bl sub_803B100
	ldr r0, [r4]
	movs r2, 0x83
	lsls r2, 3
	adds r0, r2
	ldr r1, _0809C19C
	b _0809C266
	.align 2, 0
_0809C194: .4byte gUnknown_3001B64
_0809C198: .4byte 0x000005a4
_0809C19C: .4byte gUnknown_81162E8
_0809C1A0:
	ldr r0, _0809C1B0
	ldr r0, [r0]
	movs r3, 0x86
	lsls r3, 3
	adds r0, r3
	bl _0809B978
	.align 2, 0
_0809C1B0: .4byte gUnknown_3001B64
_0809C1B4:
	ldr r0, [r6]
	movs r1, 0x86
	lsls r1, 3
	adds r0, r1
_0809C1BC:
	movs r1, 0x1
	str r1, [r0]
	b _0809C392
_0809C1C2:
	bl ResetTextbox_809B294
	b _0809C392
_0809C1C8:
	movs r0, 0x2
	bl CreateFriendListMenu 
	lsls r0, 24
	cmp r0, 0
	beq _0809C1EC
	ldr r0, _0809C1E4
	ldr r0, [r0]
	movs r2, 0x83
	lsls r2, 3
	adds r0, r2
	ldr r1, _0809C1E8
	b _0809C266
	.align 2, 0
_0809C1E4: .4byte gUnknown_3001B64
_0809C1E8: .4byte gUnknown_81162F8
_0809C1EC:
	ldr r0, _0809C200
	ldr r0, [r0]
	movs r3, 0x86
	lsls r3, 3
	adds r0, r3
	movs r1, 0x2
	negs r1, r1
	str r1, [r0]
	b _0809C392
	.align 2, 0
_0809C200: .4byte gUnknown_3001B64
_0809C204:
	ldr r1, [r6]
	ldr r2, _0809C230
	adds r0, r1, r2
	ldr r0, [r0]
	movs r3, 0x85
	lsls r3, 3
	adds r1, r3
	ldr r1, [r1]
	bl sub_809CCDC
	ldr r1, [r6]
	movs r3, 0x86
	lsls r3, 3
	adds r2, r1, r3
	str r0, [r2]
	movs r0, 0x83
	lsls r0, 3
	adds r1, r0
	ldr r0, _0809C234
	str r0, [r1]
	bl _0809B784
	.align 2, 0
_0809C230: .4byte 0x00000424
_0809C234: .4byte gUnknown_8116308
_0809C238:
	ldr r0, [r6]
	movs r2, 0x85
	lsls r2, 3
	adds r1, r0, r2
	ldr r5, [r1]
	ldr r3, _0809C26C
	adds r0, r3
	ldrb r4, [r0]
	bl ResetTextbox_809B294
	adds r0, r5, 0
	adds r1, r4, 0
	movs r2, 0x1
	bl sub_801B60C
	lsls r0, 24
	cmp r0, 0
	beq _0809C274
	ldr r0, [r6]
	movs r1, 0x83
	lsls r1, 3
	adds r0, r1
	ldr r1, _0809C270
_0809C266:
	str r1, [r0]
	bl _0809B784
	.align 2, 0
_0809C26C: .4byte 0x00000424
_0809C270: .4byte gUnknown_8116318
_0809C274:
	ldr r0, [r6]
	movs r2, 0x86
	lsls r2, 3
	adds r0, r2
	bl _0809B978
_0809C280:
	ldr r0, [r6]
	movs r3, 0x84
	lsls r3, 3
	adds r0, r3
	ldr r0, [r0]
	cmp r0, 0x1
	bne _0809C2B8
	bl ResetTextbox_809B294
	movs r0, 0
	movs r1, 0x1
	movs r2, 0x1
	bl xxx_call_save_unk_text_struct_800641C
	movs r0, 0
	movs r1, 0
	movs r2, 0
	movs r3, 0xA
	bl sub_801A5D8
	lsls r0, 24
	cmp r0, 0
	beq _0809C2B2
	bl _0809B784
_0809C2B2:
	ldr r0, [r6]
	bl _0809B972
_0809C2B8:
	movs r0, 0x1
	bl sub_801A6E8
	cmp r0, 0x2
	beq _0809C320
	cmp r0, 0x3
	beq _0809C2CA
	bl _0809B784
_0809C2CA:
	bl sub_801A8AC
	adds r5, r0, 0
	ldr r0, _0809C304
	ldr r0, [r0]
	lsls r1, r5, 2
	adds r0, r1
	ldrb r4, [r0, 0x2]
	adds r0, r4, 0
	bl IsEdibleItem
	lsls r0, 24
	cmp r0, 0
	beq _0809C30C
	ldr r0, _0809C308
	adds r1, r4, 0
	movs r2, 0
	bl BufferItemName
	adds r0, r5, 0
	bl ShiftItemsDownFrom
	ldr r0, [r6]
	movs r2, 0x86
	lsls r2, 3
	adds r0, r2
	movs r1, 0x1
	b _0809C318
	.align 2, 0
_0809C304: .4byte gTeamInventoryRef
_0809C308: .4byte gFormatItems
_0809C30C:
	ldr r0, [r6]
	movs r3, 0x86
	lsls r3, 3
	adds r0, r3
_0809C314:
	movs r1, 0x1
	negs r1, r1
_0809C318:
	str r1, [r0]
	bl sub_801A928
	b _0809C392
_0809C320:
	ldr r0, [r6]
	movs r1, 0x86
	lsls r1, 3
	adds r0, r1
	b _0809C314
_0809C32A:
	adds r4, r6, 0
	ldr r0, [r4]
	movs r2, 0x84
	lsls r2, 3
	adds r0, r2
	ldr r0, [r0]
	cmp r0, 0x1
	bne _0809C36C
	bl ResetTextbox_809B294
	ldr r1, [r4]
	ldr r3, _0809C368
	adds r0, r1, r3
	ldr r0, [r0]
	movs r2, 0x85
	lsls r2, 3
	adds r1, r2
	ldr r1, [r1]
	bl DrawCredits
	lsls r0, 24
	cmp r0, 0
	beq _0809C35C
	bl _0809B784
_0809C35C:
	ldr r0, [r4]
	movs r3, 0x86
	lsls r3, 3
	adds r0, r3
	bl _0809B978
	.align 2, 0
_0809C368: .4byte 0x00000424
_0809C36C:
	bl sub_8035574
	cmp r0, 0x3
	bls _0809C378
	bl _0809B784
_0809C378:
	cmp r0, 0x2
	bcs _0809C380
	bl _0809B784
_0809C380:
	ldr r0, [r6]
	movs r1, 0x86
	lsls r1, 3
	adds r0, r1
	movs r1, 0x1
	negs r1, r1
	str r1, [r0]
	bl sub_803565C
_0809C392:
	movs r0, 0
_0809C394:
	add sp, 0x24
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end sub_809B648

    .align 2,0
