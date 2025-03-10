	#include "asm/constants/gba_constants.inc"
	#include "asm/macros.inc"

	.syntax unified

	.text

	thumb_func_start sub_800DD0C
sub_800DD0C:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0x8
	adds r5, r0, 0
	adds r6, r1, 0
	movs r0, 0x58
	adds r0, r5
	mov r8, r0
	ldrh r1, [r0]
	movs r0, 0x80
	lsls r0, 6
	ands r0, r1
	cmp r0, 0
	beq _0800DD2E
	movs r0, 0
	b _0800DD30
_0800DD2E:
	lsrs r0, r1, 15
_0800DD30:
	cmp r0, 0
	bne _0800DD64
	adds r0, r5, 0
	bl sub_800DCA8
	ldr r0, [r5, 0x34]
	cmp r0, 0x3
	bne _0800DD60
	movs r4, 0
	b _0800DD46
_0800DD44:
	adds r4, 0x1
_0800DD46:
	cmp r4, 0x1
	bgt _0800DD60
	adds r0, r4, 0
	bl sub_800F18C
	adds r2, r0, 0
	ldr r1, [r2]
	ldr r0, [r5, 0x38]
	cmp r1, r0
	bne _0800DD44
	ldr r0, [r2, 0x4]
	subs r0, 0x1
	str r0, [r2, 0x4]
_0800DD60:
	movs r0, 0
	b _0800DE28
_0800DD64:
	mov r0, r8
	bl RunAxAnimationFrame
	movs r4, 0
	ldr r0, [r5, 0x8]
	movs r1, 0x7
	ands r0, r1
	cmp r0, 0
	bne _0800DD88
	ldr r0, [r5, 0x14]
	cmp r0, 0x5
	bgt _0800DD84
	cmp r0, 0x3
	blt _0800DD84
	subs r4, 0x3
	b _0800DD8A
_0800DD84:
	adds r4, 0x3
	b _0800DD8A
_0800DD88:
	movs r4, 0x3
_0800DD8A:
	movs r2, 0
	ldr r1, [r5, 0x20]
	movs r0, 0x1
	negs r0, r0
	cmp r1, r0
	beq _0800DD9E
	ldrh r0, [r5, 0x1E]
	lsls r0, 16
	ldrh r2, [r5, 0x1C]
	orrs r2, r0
_0800DD9E:
	lsls r0, r2, 16
	asrs r1, r0, 16
	adds r7, r0, 0
	cmp r1, 0x63
	beq _0800DE26
	asrs r0, r2, 16
	adds r2, r0, 0
	cmp r2, 0x63
	beq _0800DE26
	ldr r3, [r5, 0x24]
	ldr r0, _0800DE34
	cmp r3, r0
	bne _0800DDCA
	movs r1, 0x1A
	ldrsh r0, [r5, r1]
	movs r3, 0x2
	ldrsh r1, [r6, r3]
	subs r0, r1
	lsrs r1, r0, 31
	adds r0, r1
	asrs r0, 1
	adds r3, r0, r4
_0800DDCA:
	movs r4, 0x18
	ldrsh r0, [r5, r4]
	movs r4, 0
	ldrsh r1, [r6, r4]
	subs r0, r1
	asrs r1, r7, 16
	adds r4, r0, r1
	movs r7, 0x1A
	ldrsh r0, [r5, r7]
	movs r7, 0x2
	ldrsh r1, [r6, r7]
	subs r0, r1
	adds r2, r0, r2
	adds r0, r5, 0
	adds r0, 0xCC
	ldrh r0, [r0]
	ldrh r1, [r5, 0x18]
	adds r0, r1
	strh r0, [r5, 0x18]
	adds r0, r5, 0
	adds r0, 0xCE
	ldrh r0, [r0]
	ldrh r7, [r5, 0x1A]
	adds r0, r7
	strh r0, [r5, 0x1A]
	adds r1, r4, 0
	adds r1, 0x3F
	movs r0, 0xB7
	lsls r0, 1
	cmp r1, r0
	bhi _0800DE26
	movs r0, 0x40
	negs r0, r0
	cmp r2, r0
	ble _0800DE26
	cmp r2, 0xDF
	bgt _0800DE26
	ldr r0, [r5, 0x3C]
	str r0, [sp]
	adds r0, r5, 0
	adds r0, 0x28
	str r0, [sp, 0x4]
	mov r0, r8
	adds r1, r4, 0
	bl DoAxFrame_800558C
_0800DE26:
	movs r0, 0x1
_0800DE28:
	add sp, 0x8
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r1}
	bx r1
	.align 2, 0
_0800DE34: .4byte 0x0000ffff
	thumb_func_end sub_800DD0C

	thumb_func_start sub_800DE38
sub_800DE38:
	push {r4,r5,lr}
	adds r5, r0, 0
	adds r0, 0x58
	ldrh r1, [r0]
	movs r0, 0x80
	lsls r0, 6
	ands r0, r1
	cmp r0, 0
	beq _0800DE4E
	movs r0, 0
	b _0800DE50
_0800DE4E:
	lsrs r0, r1, 15
_0800DE50:
	cmp r0, 0
	bne _0800DE84
	adds r0, r5, 0
	bl sub_800DCA8
	ldr r0, [r5, 0x34]
	cmp r0, 0x3
	bne _0800DE80
	movs r4, 0
	b _0800DE66
_0800DE64:
	adds r4, 0x1
_0800DE66:
	cmp r4, 0x1
	bgt _0800DE80
	adds r0, r4, 0
	bl sub_800F18C
	adds r2, r0, 0
	ldr r1, [r2]
	ldr r0, [r5, 0x38]
	cmp r1, r0
	bne _0800DE64
	ldr r0, [r2, 0x4]
	subs r0, 0x1
	str r0, [r2, 0x4]
_0800DE80:
	movs r0, 0
	b _0800DE86
_0800DE84:
	movs r0, 0x1
_0800DE86:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_800DE38

	thumb_func_start sub_800DE8C
sub_800DE8C:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0x14
	adds r6, r0, 0
	movs r0, 0x94
	adds r0, r6
	mov r8, r0
	ldr r4, [r0, 0x18]
	cmp r4, 0
	beq _0800DEA4
	b _0800E09C
_0800DEA4:
	ldr r1, [r0, 0x14]
	movs r7, 0x1
	str r7, [sp]
	adds r0, r6, 0
	adds r0, 0xAC
	str r0, [sp, 0x4]
	add r2, sp, 0xC
	str r2, [sp, 0x8]
	mov r0, r8
	movs r2, 0
	movs r3, 0
	bl sub_8009A7C
	lsls r0, 24
	lsrs r5, r0, 24
	cmp r5, 0
	bne _0800DEC8
	b _0800E030
_0800DEC8:
	add r0, sp, 0xC
	movs r1, 0
	ldrsh r0, [r0, r1]
	cmp r0, 0
	beq _0800DEE8
	adds r0, r6, 0
	adds r0, 0xB4
	strb r7, [r0]
	ldr r0, _0800DF0C
	ldr r0, [r0]
	ldr r2, _0800DF10
	adds r1, r0, r2
	str r4, [r1]
	ldr r1, _0800DF14
	adds r0, r1
	str r4, [r0]
_0800DEE8:
	add r0, sp, 0xC
	ldrh r0, [r0, 0x2]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0
	beq _0800DF6C
	cmp r0, 0x63
	bne _0800DF1C
	ldr r0, _0800DF0C
	ldr r0, [r0]
	ldr r1, _0800DF10
	adds r2, r0, r1
	ldr r1, _0800DF18
	str r1, [r2]
	ldr r2, _0800DF14
	adds r0, r2
	str r4, [r0]
	b _0800DF6C
	.align 2, 0
_0800DF0C: .4byte gUnknown_203B0CC
_0800DF10: .4byte 0x00001a08
_0800DF14: .4byte 0x00001a0c
_0800DF18: .4byte 0x00000c1c
_0800DF1C:
	cmp r0, 0
	ble _0800DF50
	ldr r0, _0800DF40
	ldr r4, [r0]
	ldr r0, _0800DF44
	adds r5, r4, r0
	ldr r1, _0800DF48
	adds r4, r1
	add r0, sp, 0xC
	movs r2, 0x2
	ldrsh r1, [r0, r2]
	ldr r0, _0800DF4C
	bl __divsi3
	str r0, [r4]
	str r0, [r5]
	b _0800DF6C
	.align 2, 0
_0800DF40: .4byte gUnknown_203B0CC
_0800DF44: .4byte 0x00001a08
_0800DF48: .4byte 0x00001a0c
_0800DF4C: .4byte 0x00000c1c
_0800DF50:
	ldr r0, _0800DFA4
	ldr r4, [r0]
	ldr r0, _0800DFA8
	adds r1, r4, r0
	ldr r0, _0800DFAC
	str r0, [r1]
	ldr r1, _0800DFB0
	adds r4, r1
	add r1, sp, 0xC
	movs r2, 0x2
	ldrsh r1, [r1, r2]
	bl __divsi3
	str r0, [r4]
_0800DF6C:
	mov r0, r8
	adds r0, 0x20
	ldrb r0, [r0]
	cmp r0, 0
	bne _0800DF78
	b _0800E094
_0800DF78:
	ldr r0, _0800DFA4
	ldr r1, [r0]
	ldr r2, _0800DFB4
	adds r0, r1, r2
	ldr r0, [r0]
	cmp r0, 0
	beq _0800DFB8
	cmp r0, 0x1
	bne _0800DFEA
	adds r0, r6, 0
	adds r0, 0xB8
	ldr r0, [r0]
	ldr r0, [r0, 0x4]
	ldr r1, [r0, 0x10]
	movs r0, 0xE0
	lsls r0, 2
	adds r1, r0
	movs r0, 0xE0
	movs r2, 0x10
	bl sub_809971C
	b _0800DFEA
	.align 2, 0
_0800DFA4: .4byte gUnknown_203B0CC
_0800DFA8: .4byte 0x00001a08
_0800DFAC: .4byte 0x00000c1c
_0800DFB0: .4byte 0x00001a0c
_0800DFB4: .4byte 0x00001a04
_0800DFB8:
	ldr r2, _0800E010
	adds r0, r1, r2
	ldr r0, [r0]
	movs r1, 0x64
	bl __divsi3
	adds r7, r0, 0
	movs r4, 0
	adds r6, 0xB8
	movs r5, 0xE0
	lsls r5, 2
_0800DFCE:
	adds r0, r4, 0
	adds r0, 0xE0
	ldr r1, [r6]
	ldr r1, [r1, 0x4]
	ldr r1, [r1, 0x10]
	adds r1, r5
	adds r2, r7, 0
	movs r3, 0
	bl SetBGPaletteBufferColorRGB
	adds r5, 0x4
	adds r4, 0x1
	cmp r4, 0xF
	ble _0800DFCE
_0800DFEA:
	ldr r1, _0800E014
	ldr r2, _0800E018
	adds r0, r2, 0
	strh r0, [r1]
	ldr r0, _0800E01C
	ldr r0, [r0]
	ldr r1, _0800E010
	adds r2, r0, r1
	adds r1, 0x4
	adds r0, r1
	ldr r1, [r2]
	ldr r0, [r0]
	adds r1, r0
	str r1, [r2]
	cmp r1, 0
	bge _0800E020
	movs r0, 0
	str r0, [r2]
	b _0800E094
	.align 2, 0
_0800E010: .4byte 0x00001a08
_0800E014: .4byte gUnknown_2026E4E
_0800E018: .4byte 0x00000a0a
_0800E01C: .4byte gUnknown_203B0CC
_0800E020:
	ldr r0, _0800E02C
	cmp r1, r0
	ble _0800E094
	str r0, [r2]
	b _0800E094
	.align 2, 0
_0800E02C: .4byte 0x00000c1c
_0800E030:
	bl sub_8009BE4
	adds r0, r6, 0
	bl sub_800DCA8
	bl sub_8000728
	cmp r0, 0x1
	bne _0800E058
	bl LoadDungeonMapPalette
	movs r0, 0
	movs r1, 0
	bl sub_803EAF0
	movs r0, 0x80
	lsls r0, 8
	movs r1, 0
	bl sub_800CD64
_0800E058:
	ldr r4, _0800E084
	ldr r0, [r4]
	ldr r2, _0800E088
	adds r0, r2
	ldr r0, [r0]
	bl sub_800CDA8
	ldr r1, _0800E08C
	ldr r0, [r4]
	ldr r2, _0800E090
	adds r0, r2
	ldrh r0, [r0]
	strh r0, [r1]
	movs r0, 0x1
	bl sub_800F18C
	str r5, [r0, 0x4]
	movs r1, 0x1
	negs r1, r1
	str r1, [r0]
	movs r0, 0
	b _0800E0A6
	.align 2, 0
_0800E084: .4byte gUnknown_203B0CC
_0800E088: .4byte 0x00001a10
_0800E08C: .4byte gUnknown_2026E4E
_0800E090: .4byte 0x00001a14
_0800E094:
	mov r1, r8
	ldr r0, [r1, 0x14]
	adds r0, 0x1
	str r0, [r1, 0x14]
_0800E09C:
	mov r2, r8
	ldr r0, [r2, 0x18]
	subs r0, 0x1
	str r0, [r2, 0x18]
	movs r0, 0x1
_0800E0A6:
	add sp, 0x14
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_800DE8C

	thumb_func_start sub_800E0B4
sub_800E0B4:
	push {r4-r6,lr}
	sub sp, 0x8
	adds r5, r0, 0
	ldr r0, [r5, 0xC]
	bl sub_800ECA4
	adds r6, r0, 0
	ldr r0, [r6]
	str r0, [r5, 0x34]
	ldr r0, [r6, 0x4]
	str r0, [r5, 0x38]
	ldr r0, [r6, 0x10]
	str r0, [r5, 0x4C]
	ldr r0, [r5, 0x10]
	ldr r1, [r6, 0x14]
	adds r0, r1
	str r0, [r5, 0x50]
	adds r0, r6, 0
	adds r0, 0x21
	ldrb r0, [r0]
	adds r1, r5, 0
	adds r1, 0x55
	strb r0, [r1]
	adds r0, r6, 0
	adds r0, 0x20
	ldrb r1, [r0]
	adds r0, r5, 0
	adds r0, 0x54
	strb r1, [r0]
	adds r0, 0x64
	ldr r0, [r0]
	bl sub_800E2B8
	adds r2, r0, 0
	str r2, [r5, 0x8]
	ldr r3, [r6, 0xC]
	str r3, [r5, 0x40]
	ldr r1, [r5, 0x14]
	movs r0, 0x1
	negs r0, r0
	cmp r1, r0
	beq _0800E114
	movs r0, 0x7
	ands r0, r2
	cmp r0, 0
	bne _0800E114
	adds r0, r3, r1
	str r0, [r5, 0x40]
_0800E114:
	ldr r0, [r5, 0x34]
	cmp r0, 0x3
	beq _0800E12E
	cmp r0, 0x3
	bhi _0800E128
	cmp r0, 0x1
	bcc _0800E184
	movs r0, 0x92
	lsls r0, 2
	b _0800E132
_0800E128:
	cmp r0, 0x4
	beq _0800E140
	b _0800E184
_0800E12E:
	movs r0, 0xDC
	lsls r0, 2
_0800E132:
	str r0, [r5, 0x48]
	ldr r0, [r6, 0x8]
	str r0, [r5, 0x3C]
	movs r0, 0x1
	negs r0, r0
	str r0, [r5, 0x44]
	b _0800E184
_0800E140:
	movs r0, 0x1
	negs r0, r0
	str r0, [r5, 0x48]
	ldr r0, [r6, 0x8]
	str r0, [r5, 0x3C]
	movs r0, 0xF0
	lsls r0, 4
	str r0, [r5, 0x44]
	ldr r4, _0800E194
	ldr r0, [r4]
	ldr r2, _0800E198
	adds r1, r0, r2
	movs r2, 0
	str r2, [r1]
	ldr r3, _0800E19C
	adds r0, r3
	str r2, [r0]
	bl sub_800CDC8
	ldr r2, [r4]
	ldr r4, _0800E1A0
	adds r1, r2, r4
	str r0, [r1]
	ldr r0, _0800E1A4
	ldrh r0, [r0]
	ldr r1, _0800E1A8
	adds r2, r1
	strh r0, [r2]
	ldrb r0, [r6, 0x18]
	cmp r0, 0
	beq _0800E184
	movs r0, 0x5
	bl sub_800CDA8
_0800E184:
	ldr r0, [r5, 0x34]
	cmp r0, 0x3
	beq _0800E1C2
	cmp r0, 0x3
	bls _0800E1AC
	cmp r0, 0x4
	beq _0800E1E4
	b _0800E200
	.align 2, 0
_0800E194: .4byte gUnknown_203B0CC
_0800E198: .4byte 0x00001a08
_0800E19C: .4byte 0x00001a0c
_0800E1A0: .4byte 0x00001a10
_0800E1A4: .4byte gUnknown_2026E4E
_0800E1A8: .4byte 0x00001a14
_0800E1AC:
	cmp r0, 0x1
	bcc _0800E200
	adds r0, r5, 0
	adds r0, 0x58
	adds r1, r5, 0
	adds r1, 0xB8
	ldr r1, [r1]
	ldr r2, [r5, 0x40]
	movs r3, 0x92
	lsls r3, 2
	b _0800E1D2
_0800E1C2:
	adds r0, r5, 0
	adds r0, 0x58
	adds r1, r5, 0
	adds r1, 0xB8
	ldr r1, [r1]
	ldr r2, [r5, 0x40]
	movs r3, 0xDC
	lsls r3, 2
_0800E1D2:
	movs r4, 0
	str r4, [sp]
	adds r4, r5, 0
	adds r4, 0x55
	ldrb r4, [r4]
	str r4, [sp, 0x4]
	bl AxResInitUnorientedFile
	b _0800E200
_0800E1E4:
	adds r0, r5, 0
	adds r0, 0xB8
	ldr r0, [r0]
	adds r1, r5, 0
	adds r1, 0x94
	ldr r0, [r0, 0x4]
	ldm r0!, {r2-r4}
	stm r1!, {r2-r4}
	ldm r0!, {r2,r3}
	stm r1!, {r2,r3}
	adds r1, r5, 0
	adds r1, 0xB4
	movs r0, 0
	strb r0, [r1]
_0800E200:
	add sp, 0x8
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end sub_800E0B4

	thumb_func_start sub_800E208
sub_800E208:
	push {r4-r7,lr}
	adds r7, r0, 0
	adds r6, r1, 0
	ldr r0, _0800E220
	ldr r4, [r0]
	ldr r0, [r6]
	cmp r0, 0
	bne _0800E224
_0800E218:
	movs r0, 0x1
	negs r0, r0
	b _0800E2B0
	.align 2, 0
_0800E220: .4byte gUnknown_203B0CC
_0800E224:
	movs r1, 0
_0800E226:
	ldr r5, [r4, 0x4]
	movs r0, 0x1
	negs r0, r0
	cmp r5, r0
	bne _0800E2A8
	adds r0, r4, 0
	movs r1, 0xD0
	bl MemoryClear8
	ldr r0, [r6]
	bl sub_800ECA4
	adds r1, r0, 0
	ldr r2, [r1]
	cmp r2, 0x2
	bne _0800E254
	ldr r0, _0800E2A0
	ldr r0, [r0]
	ldr r3, _0800E2A4
	adds r0, r3
	ldr r0, [r0]
	cmp r0, 0x1
	bne _0800E218
_0800E254:
	cmp r2, 0x1
	bne _0800E266
	ldr r0, _0800E2A0
	ldr r0, [r0]
	ldr r3, _0800E2A4
	adds r0, r3
	ldr r0, [r0]
	cmp r0, 0
	bne _0800E218
_0800E266:
	ldr r1, [r1, 0x4]
	adds r0, r2, 0
	bl sub_800F1C0
	adds r1, r4, 0
	adds r1, 0xB8
	str r0, [r1]
	cmp r0, 0
	beq _0800E218
	str r7, [r4]
	bl sub_800E2F0
	str r0, [r4, 0x4]
	adds r1, r4, 0
	adds r1, 0xC
	adds r0, r6, 0
	ldm r0!, {r2,r3,r5}
	stm r1!, {r2,r3,r5}
	ldm r0!, {r2,r3,r5}
	stm r1!, {r2,r3,r5}
	ldm r0!, {r2,r3,r5}
	stm r1!, {r2,r3,r5}
	ldr r0, [r0]
	str r0, [r1]
	adds r0, r4, 0
	bl sub_800E0B4
	ldr r0, [r4, 0x4]
	b _0800E2B0
	.align 2, 0
_0800E2A0: .4byte gUnknown_203B0CC
_0800E2A4: .4byte 0x00001a04
_0800E2A8:
	adds r1, 0x1
	adds r4, 0xD0
	cmp r1, 0x1F
	ble _0800E226
_0800E2B0:
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_800E208

	thumb_func_start sub_800E2B8
sub_800E2B8:
	ldr r0, [r0, 0x4]
	ldr r0, [r0, 0x8]
	bx lr
	thumb_func_end sub_800E2B8

	thumb_func_start sub_800E2C0
sub_800E2C0:
	push {lr}
	adds r3, r0, 0
	movs r0, 0x1
	negs r0, r0
	cmp r3, r0
	beq _0800E2E8
	ldr r0, _0800E2DC
	ldr r1, [r0]
	movs r2, 0
_0800E2D2:
	ldr r0, [r1, 0x4]
	cmp r0, r3
	bne _0800E2E0
	adds r0, r2, 0
	b _0800E2EC
	.align 2, 0
_0800E2DC: .4byte gUnknown_203B0CC
_0800E2E0:
	adds r2, 0x1
	adds r1, 0xD0
	cmp r2, 0x1F
	ble _0800E2D2
_0800E2E8:
	movs r0, 0x1
	negs r0, r0
_0800E2EC:
	pop {r1}
	bx r1
	thumb_func_end sub_800E2C0

	thumb_func_start sub_800E2F0
sub_800E2F0:
	ldr r0, _0800E304
	ldr r1, [r0]
	movs r0, 0xD0
	lsls r0, 5
	adds r1, r0
	ldr r0, [r1]
	adds r2, r0, 0x1
	str r2, [r1]
	bx lr
	.align 2, 0
_0800E304: .4byte gUnknown_203B0CC
	thumb_func_end sub_800E2F0

	thumb_func_start sub_800E308
sub_800E308:
	push {r4-r7,lr}
	sub sp, 0x50
	adds r4, r0, 0
	adds r7, r1, 0
	ldrh r0, [r4]
	bl sub_800ECB8
	movs r1, 0x6
	ldrsh r0, [r0, r1]
	str r0, [sp, 0x28]
	ldr r0, [r4, 0x10]
	str r0, [sp, 0x2C]
	ldr r0, [r4, 0xC]
	str r0, [sp, 0x30]
	ldr r0, [r4, 0x4]
	str r0, [sp, 0x34]
	ldr r0, [r4, 0x8]
	str r0, [sp, 0x38]
	movs r2, 0x2
	ldrsh r0, [r4, r2]
	ldrh r1, [r4]
	bl sub_800E750
	str r0, [sp, 0x3C]
	ldr r0, _0800E3A0
	str r0, [sp, 0x40]
	add r1, sp, 0x44
	ldr r0, _0800E3A4
	ldm r0!, {r2,r3,r5}
	stm r1!, {r2,r3,r5}
	add r1, sp, 0x28
	mov r0, sp
	movs r2, 0x28
	bl memcpy
	movs r0, 0x2
	mov r1, sp
	bl sub_800E208
	adds r5, r0, 0
	movs r6, 0x1
	negs r6, r6
	cmp r5, r6
	beq _0800E396
	adds r0, r5, 0
	bl sub_800E2C0
	adds r1, r0, 0
	cmp r1, r6
	beq _0800E396
	ldr r2, _0800E3A8
	movs r0, 0xD0
	muls r1, r0
	ldr r0, [r2]
	adds r2, r0, r1
	adds r1, r2, 0
	adds r1, 0xBC
	ldr r0, [r4, 0x4]
	str r0, [r1]
	adds r1, 0x4
	ldr r0, [r7]
	str r0, [r1]
	ldrh r1, [r4, 0x2]
	adds r0, r2, 0
	adds r0, 0xC4
	strh r1, [r0]
	adds r1, r2, 0
	adds r1, 0xC8
	ldr r0, [r2, 0x1C]
	str r0, [r1]
	adds r0, r5, 0
_0800E396:
	add sp, 0x50
	pop {r4-r7}
	pop {r1}
	bx r1
	.align 2, 0
_0800E3A0: .4byte 0x0000ffff
_0800E3A4: .4byte gUnknown_80B9C60
_0800E3A8: .4byte gUnknown_203B0CC
	thumb_func_end sub_800E308

	thumb_func_start sub_800E3AC
sub_800E3AC:
	push {r4-r6,lr}
	adds r4, r1, 0
	adds r6, r2, 0
	bl sub_800E2C0
	adds r1, r0, 0
	movs r0, 0x1
	negs r0, r0
	cmp r1, r0
	beq _0800E43C
	ldr r2, _0800E444
	movs r0, 0xD0
	muls r1, r0
	ldr r0, [r2]
	adds r5, r0, r1
	ldr r0, [r4]
	str r0, [r5, 0x18]
	adds r0, r5, 0
	adds r0, 0xC0
	movs r2, 0
	ldrsh r1, [r0, r2]
	subs r0, 0x4
	movs r3, 0
	ldrsh r0, [r0, r3]
	subs r2, r1, r0
	cmp r2, 0
	bge _0800E3E4
	negs r2, r2
_0800E3E4:
	adds r0, r5, 0
	adds r0, 0xC2
	movs r3, 0
	ldrsh r1, [r0, r3]
	subs r0, 0x4
	movs r3, 0
	ldrsh r0, [r0, r3]
	subs r1, r0
	cmp r1, 0
	bge _0800E3FA
	negs r1, r1
_0800E3FA:
	cmp r1, r2
	bge _0800E400
	adds r1, r2, 0
_0800E400:
	cmp r1, 0
	bge _0800E406
	adds r1, 0x3
_0800E406:
	asrs r4, r1, 2
	subs r1, r4, 0x1
	ldrh r0, [r5, 0x1E]
	adds r0, 0x9
	strh r0, [r5, 0x1E]
	movs r2, 0x1C
	ldrsh r0, [r5, r2]
	muls r0, r1
	strh r0, [r5, 0x1C]
	movs r3, 0x1E
	ldrsh r0, [r5, r3]
	muls r0, r1
	strh r0, [r5, 0x1E]
	movs r1, 0x1C
	ldrsh r0, [r5, r1]
	adds r1, r4, 0
	bl __divsi3
	strh r0, [r5, 0x1C]
	movs r2, 0x1E
	ldrsh r0, [r5, r2]
	adds r1, r4, 0
	bl __divsi3
	subs r0, 0x9
	strh r0, [r5, 0x1E]
	str r6, [r5, 0x24]
_0800E43C:
	pop {r4-r6}
	pop {r0}
	bx r0
	.align 2, 0
_0800E444: .4byte gUnknown_203B0CC
	thumb_func_end sub_800E3AC

	thumb_func_start sub_800E448
sub_800E448:
	push {r4,lr}
	sub sp, 0x50
	adds r4, r1, 0
	lsls r0, 24
	lsrs r0, 24
	bl sub_800ECE4
	lsls r0, 16
	asrs r0, 16
	str r0, [sp, 0x28]
	movs r2, 0
	str r2, [sp, 0x2C]
	movs r1, 0x1
	negs r1, r1
	str r1, [sp, 0x30]
	ldr r0, [r4]
	str r0, [sp, 0x34]
	str r2, [sp, 0x38]
	str r1, [sp, 0x3C]
	ldr r0, _0800E494
	str r0, [sp, 0x40]
	add r1, sp, 0x44
	ldr r0, _0800E498
	ldm r0!, {r2-r4}
	stm r1!, {r2-r4}
	add r1, sp, 0x28
	mov r0, sp
	movs r2, 0x28
	bl memcpy
	movs r0, 0x3
	mov r1, sp
	bl sub_800E208
	add sp, 0x50
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_0800E494: .4byte 0x0000ffff
_0800E498: .4byte gUnknown_80B9C60
	thumb_func_end sub_800E448

	thumb_func_start sub_800E49C
sub_800E49C:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0x50
	adds r7, r1, 0
	mov r8, r2
	lsls r0, 24
	lsrs r0, 24
	lsls r3, 24
	lsrs r6, r3, 24
	cmp r6, 0
	beq _0800E4BA
	bl sub_800ECF8
	b _0800E4BE
_0800E4BA:
	bl sub_800ED0C
_0800E4BE:
	lsls r0, 16
	asrs r4, r0, 16
	adds r0, r4, 0
	bl sub_800E700
	adds r5, r0, 0
	str r4, [sp, 0x28]
	movs r1, 0
	str r1, [sp, 0x2C]
	movs r4, 0x1
	negs r4, r4
	str r4, [sp, 0x30]
	ldr r0, [r7]
	str r0, [sp, 0x34]
	str r1, [sp, 0x38]
	str r4, [sp, 0x3C]
	str r1, [sp, 0x40]
	add r1, sp, 0x44
	ldr r0, _0800E508
	ldm r0!, {r2,r3,r7}
	stm r1!, {r2,r3,r7}
	add r1, sp, 0x28
	mov r0, sp
	movs r2, 0x28
	bl memcpy
	ldr r0, [sp, 0x68]
	str r0, [sp, 0x18]
	cmp r6, 0
	beq _0800E50C
	cmp r5, r4
	beq _0800E516
	str r5, [sp, 0x14]
	lsls r0, r5, 2
	add r0, r8
	ldr r0, [r0]
	b _0800E514
	.align 2, 0
_0800E508: .4byte gUnknown_80B9C60
_0800E50C:
	movs r0, 0x3
	str r0, [sp, 0x14]
	mov r1, r8
	ldr r0, [r1, 0xC]
_0800E514:
	str r0, [sp, 0x10]
_0800E516:
	movs r0, 0x4
	mov r1, sp
	bl sub_800E208
	add sp, 0x50
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_800E49C

	thumb_func_start sub_800E52C
sub_800E52C:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x1B0
	adds r7, r0, 0
	ldrh r0, [r7]
	cmp r0, 0x52
	bne _0800E628
	mov r1, sp
	ldr r0, _0800E618
	ldm r0!, {r2-r4}
	stm r1!, {r2-r4}
	ldm r0!, {r2,r3,r5}
	stm r1!, {r2,r3,r5}
	ldm r0!, {r4,r5}
	stm r1!, {r4,r5}
	movs r0, 0
	mov r10, r0
	mov r9, r0
	mov r8, sp
	add r6, sp, 0x20
	adds r4, r6, 0
_0800E55C:
	ldrh r0, [r7]
	bl sub_800ECB8
	movs r1, 0x2
	ldrsh r0, [r0, r1]
	str r0, [r4]
	ldr r0, [r7, 0x10]
	str r0, [r4, 0x4]
	ldr r0, [r7, 0xC]
	str r0, [r4, 0x8]
	ldr r0, [r7, 0x4]
	str r0, [r4, 0xC]
	ldrh r0, [r4, 0xE]
	adds r0, 0x40
	strh r0, [r4, 0xE]
	ldr r0, [r7, 0x8]
	str r0, [r4, 0x10]
	mov r2, r8
	ldrh r0, [r2]
	ldrh r3, [r4, 0x10]
	adds r0, r3
	strh r0, [r4, 0x10]
	ldrh r0, [r4, 0x12]
	subs r0, 0x40
	ldrh r5, [r2, 0x2]
	adds r0, r5
	strh r0, [r4, 0x12]
	movs r1, 0x2
	ldrsh r0, [r7, r1]
	ldrh r1, [r7]
	bl sub_800E750
	str r0, [r4, 0x14]
	ldr r0, _0800E61C
	str r0, [r4, 0x18]
	adds r1, r6, 0
	adds r1, 0x1C
	ldr r0, _0800E620
	ldm r0!, {r2,r3,r5}
	stm r1!, {r2,r3,r5}
	movs r0, 0x1
	adds r1, r6, 0
	bl sub_800E208
	adds r5, r0, 0
	bl sub_800E2C0
	adds r1, r0, 0
	movs r0, 0x1
	negs r0, r0
	cmp r1, r0
	beq _0800E5D4
	ldr r2, _0800E624
	movs r0, 0xD0
	muls r1, r0
	ldr r0, [r2]
	adds r0, r1
	adds r0, 0xCC
	movs r1, 0x6
	strh r1, [r0]
_0800E5D4:
	mov r0, r9
	cmp r0, 0
	bne _0800E5DC
	mov r10, r5
_0800E5DC:
	movs r1, 0x4
	add r8, r1
	adds r4, 0x28
	adds r6, 0x28
	movs r2, 0x1
	add r9, r2
	mov r3, r9
	cmp r3, 0x7
	ble _0800E55C
	movs r4, 0x6
	mov r9, r4
_0800E5F2:
	ldrh r0, [r7]
	bl sub_800ECB8
	movs r5, 0x2
	ldrsh r0, [r0, r5]
	bl sub_800ECA4
	ldr r0, [r0, 0x4]
	bl sub_800F15C
	movs r0, 0x1
	negs r0, r0
	add r9, r0
	mov r1, r9
	cmp r1, 0
	bge _0800E5F2
	mov r0, r10
	b _0800E67E
	.align 2, 0
_0800E618: .4byte gUnknown_80B9C7C
_0800E61C: .4byte 0x0000ffff
_0800E620: .4byte gUnknown_80B9C60
_0800E624: .4byte gUnknown_203B0CC
_0800E628:
	add r6, sp, 0x160
	add r5, sp, 0x188
	ldrh r0, [r7]
	bl sub_800ECB8
	movs r2, 0x2
	ldrsh r0, [r0, r2]
	str r0, [r5]
	add r1, sp, 0x18C
	ldr r0, [r7, 0x10]
	str r0, [r1]
	add r1, sp, 0x190
	ldr r0, [r7, 0xC]
	str r0, [r1]
	add r1, sp, 0x194
	ldr r0, [r7, 0x4]
	str r0, [r1]
	add r1, sp, 0x198
	ldr r0, [r7, 0x8]
	str r0, [r1]
	add r4, sp, 0x19C
	movs r3, 0x2
	ldrsh r0, [r7, r3]
	ldrh r1, [r7]
	bl sub_800E750
	str r0, [r4]
	add r1, sp, 0x1A0
	ldr r0, _0800E690
	str r0, [r1]
	add r1, sp, 0x1A4
	ldr r0, _0800E694
	ldm r0!, {r2-r4}
	stm r1!, {r2-r4}
	adds r0, r6, 0
	adds r1, r5, 0
	movs r2, 0x28
	bl memcpy
	movs r0, 0x1
	adds r1, r6, 0
	bl sub_800E208
_0800E67E:
	add sp, 0x1B0
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	.align 2, 0
_0800E690: .4byte 0x0000ffff
_0800E694: .4byte gUnknown_80B9C60
	thumb_func_end sub_800E52C

	thumb_func_start sub_800E698
sub_800E698:
	push {r4,r5,lr}
	adds r4, r1, 0
	adds r5, r2, 0
	bl sub_800E2C0
	adds r1, r0, 0
	movs r3, 0x1
	negs r3, r3
	cmp r1, r3
	beq _0800E6D2
	ldr r2, _0800E6C8
	movs r0, 0xD0
	muls r1, r0
	ldr r0, [r2]
	adds r1, r0, r1
	ldr r0, [r4]
	str r0, [r1, 0x18]
	ldr r0, [r1, 0x20]
	cmp r0, r3
	beq _0800E6CC
	ldr r0, [r5]
	str r0, [r1, 0x1C]
	b _0800E6D2
	.align 2, 0
_0800E6C8: .4byte gUnknown_203B0CC
_0800E6CC:
	movs r0, 0
	strh r0, [r1, 0x1C]
	strh r0, [r1, 0x1E]
_0800E6D2:
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_800E698

	thumb_func_start sub_800E6D8
sub_800E6D8:
	push {lr}
	bl sub_800E2C0
	adds r1, r0, 0
	movs r0, 0x1
	negs r0, r0
	cmp r1, r0
	bne _0800E6EC
	adds r0, r1, 0
	b _0800E6F8
_0800E6EC:
	ldr r2, _0800E6FC
	movs r0, 0xD0
	muls r1, r0
	ldr r0, [r2]
	adds r0, r1
	ldr r0, [r0, 0x20]
_0800E6F8:
	pop {r1}
	bx r1
	.align 2, 0
_0800E6FC: .4byte gUnknown_203B0CC
	thumb_func_end sub_800E6D8

	thumb_func_start sub_800E700
sub_800E700:
	push {lr}
	lsls r0, 16
	asrs r0, 16
	bl sub_800E900
	pop {r1}
	bx r1
	thumb_func_end sub_800E700

	thumb_func_start sub_800E710
sub_800E710:
	push {r4-r6,lr}
	lsls r0, 16
	asrs r5, r0, 16
	lsls r1, 16
	lsrs r1, 16
	adds r0, r1, 0
	bl sub_800ECB8
	adds r4, r0, 0
	ldr r0, [r4, 0x20]
	bl sub_800ECD0
	adds r1, r0, 0
	movs r2, 0
	ldr r0, [r4, 0x1C]
	cmp r2, r0
	bge _0800E748
	adds r3, r0, 0
_0800E734:
	movs r6, 0
	ldrsh r0, [r1, r6]
	cmp r0, r5
	bne _0800E740
	ldr r0, [r1, 0x4]
	b _0800E74A
_0800E740:
	adds r2, 0x1
	adds r1, 0xC
	cmp r2, r3
	blt _0800E734
_0800E748:
	ldr r0, [r4, 0x14]
_0800E74A:
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end sub_800E710

	thumb_func_start sub_800E750
sub_800E750:
	push {r4-r6,lr}
	lsls r0, 16
	asrs r5, r0, 16
	lsls r1, 16
	lsrs r1, 16
	adds r0, r1, 0
	bl sub_800ECB8
	adds r4, r0, 0
	ldr r0, [r4, 0x20]
	bl sub_800ECD0
	adds r1, r0, 0
	movs r2, 0
	ldr r0, [r4, 0x1C]
	cmp r2, r0
	bge _0800E788
	adds r3, r0, 0
_0800E774:
	movs r6, 0
	ldrsh r0, [r1, r6]
	cmp r0, r5
	bne _0800E780
	ldr r0, [r1, 0x4]
	b _0800E78A
_0800E780:
	adds r2, 0x1
	adds r1, 0xC
	cmp r2, r3
	blt _0800E774
_0800E788:
	ldr r0, [r4, 0x14]
_0800E78A:
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end sub_800E750

	thumb_func_start sub_800E790
sub_800E790:
	push {r4-r6,lr}
	lsls r0, 16
	asrs r5, r0, 16
	lsls r1, 16
	lsrs r1, 16
	adds r0, r1, 0
	bl sub_800ECB8
	adds r4, r0, 0
	ldr r0, [r4, 0x20]
	bl sub_800ECD0
	adds r1, r0, 0
	movs r2, 0
	ldr r0, [r4, 0x1C]
	cmp r2, r0
	bge _0800E7C8
	adds r3, r0, 0
_0800E7B4:
	movs r6, 0
	ldrsh r0, [r1, r6]
	cmp r0, r5
	bne _0800E7C0
	ldr r0, [r1, 0x8]
	b _0800E7CA
_0800E7C0:
	adds r2, 0x1
	adds r1, 0xC
	cmp r2, r3
	blt _0800E7B4
_0800E7C8:
	ldr r0, [r4, 0x18]
_0800E7CA:
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end sub_800E790

        .align 2,0
