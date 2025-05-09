	#include "asm/constants/gba_constants.inc"
	#include "asm/macros.inc"

	.syntax unified

	.text

    thumb_func_start sub_80A59DC
sub_80A59DC:
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	sub sp, 0x58
	ldr r7, _080A5A34
	ldr r0, [r7]
	cmp r0, 0
	bne _080A59F0
	b _080A5E5A
_080A59F0:
	mov r9, sp
	mov r0, sp
	bl sub_809D248
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0
	bne _080A5A04
	str r0, [sp]
	str r0, [sp, 0x4]
_080A5A04:
	ldr r0, _080A5A38
	mov r8, r0
	ldr r3, [r0]
	adds r0, r3, 0
	adds r0, 0xE4
	movs r1, 0
	ldrsh r0, [r0, r1]
	mov r6, r8
	cmp r0, 0xAB
	bne _080A5A1A
	b _080A5BBE
_080A5A1A:
	cmp r0, 0xAB
	bgt _080A5A46
	cmp r0, 0xA3
	bgt _080A5A3C
	cmp r0, 0xA2
	bge _080A5A76
	cmp r0, 0x4
	bne _080A5A2C
	b _080A5D76
_080A5A2C:
	cmp r0, 0xA1
	bne _080A5A32
	b _080A5E28
_080A5A32:
	b _080A5E46
	.align 2, 0
_080A5A34: .4byte gGroundMapDungeon_3001B70
_080A5A38: .4byte gGroundMapAction
_080A5A3C:
	cmp r0, 0xA8
	beq _080A5AF4
	cmp r0, 0xAA
	beq _080A5AF4
	b _080A5E46
_080A5A46:
	cmp r0, 0xB0
	bne _080A5A4C
	b _080A5C76
_080A5A4C:
	cmp r0, 0xB0
	bgt _080A5A5E
	cmp r0, 0xAE
	bne _080A5A56
	b _080A5B58
_080A5A56:
	cmp r0, 0xAF
	bne _080A5A5C
	b _080A5BD8
_080A5A5C:
	b _080A5E46
_080A5A5E:
	cmp r0, 0xDF
	beq _080A5A76
	cmp r0, 0xDF
	bgt _080A5A6E
	cmp r0, 0xBA
	bne _080A5A6C
	b _080A5D18
_080A5A6C:
	b _080A5E46
_080A5A6E:
	cmp r0, 0xE0
	bne _080A5A74
	b _080A5DDA
_080A5A74:
	b _080A5E46
_080A5A76:
	ldr r3, [r6]
	adds r2, r3, 0
	adds r2, 0xF4
	ldr r1, [r2]
	adds r0, r1, 0x2
	str r0, [r2]
	adds r4, r3, 0
	adds r4, 0xFC
	cmp r0, 0
	bge _080A5A8C
	adds r0, r1, 0x5
_080A5A8C:
	asrs r1, r0, 2
	ldr r0, [r4]
	adds r0, r1
	str r0, [r4]
	ldr r0, [r2]
	movs r1, 0x3
	ands r0, r1
	str r0, [r2]
	ldr r5, _080A5AF0
	ldr r0, [r5]
	adds r2, r3, 0
	adds r2, 0xF8
	movs r1, 0
	bl sub_80A4580
	ldr r0, [sp]
	str r0, [sp, 0x8]
	ldr r0, [r6]
	adds r0, 0xFC
	ldr r1, [sp, 0x4]
	ldr r0, [r0]
	adds r1, r0
	add r4, sp, 0x8
	str r1, [r4, 0x4]
	ldr r0, [r5]
	movs r1, 0
	adds r2, r4, 0
	bl sub_80A4580
	ldr r0, [r5]
	movs r1, 0
	adds r2, r4, 0
	bl sub_80A456C
	ldr r0, [sp]
	str r0, [sp, 0x8]
	ldr r0, [r6]
	adds r0, 0xFC
	ldr r1, [sp, 0x4]
	ldr r0, [r0]
	subs r1, r0
	str r1, [r4, 0x4]
	ldr r0, [r5]
	movs r1, 0x1
	adds r2, r4, 0
	bl sub_80A4580
	ldr r0, [r5]
	b _080A5DD0
	.align 2, 0
_080A5AF0: .4byte gGroundMapDungeon_3001B70
_080A5AF4:
	ldr r2, [r6]
	adds r3, r2, 0
	adds r3, 0xF0
	adds r0, r2, 0
	adds r0, 0xE8
	ldr r1, [r3]
	ldr r0, [r0]
	adds r1, r0
	str r1, [r3]
	adds r2, 0xF8
	cmp r1, 0
	bge _080A5B0E
	adds r1, 0x7
_080A5B0E:
	asrs r1, 3
	ldr r0, [r2]
	adds r0, r1
	str r0, [r2]
	ldr r1, [r3]
	adds r0, r1, 0
	cmp r1, 0
	bge _080A5B20
	adds r0, r1, 0x7
_080A5B20:
	asrs r0, 3
	lsls r0, 3
	subs r0, r1, r0
	str r0, [r3]
	ldr r5, _080A5B54
	ldr r0, [r5]
	movs r1, 0
	bl sub_80A4580
	ldr r0, [r6]
	adds r0, 0xF8
	ldr r1, [sp]
	ldr r0, [r0]
	adds r1, r0
	str r1, [sp, 0x10]
	ldr r0, [sp, 0x4]
	add r4, sp, 0x10
	str r0, [r4, 0x4]
	ldr r0, [r5]
	movs r1, 0
	adds r2, r4, 0
	bl sub_80A4580
	ldr r0, [r5]
	movs r1, 0
	b _080A5DD2
	.align 2, 0
_080A5B54: .4byte gGroundMapDungeon_3001B70
_080A5B58:
	adds r4, r3, 0
	adds r4, 0xF0
	adds r0, r3, 0
	adds r0, 0xE8
	ldr r1, [r4]
	ldr r0, [r0]
	adds r1, r0
	str r1, [r4]
	adds r2, r3, 0
	adds r2, 0xF8
	cmp r1, 0
	bge _080A5B72
	adds r1, 0x7
_080A5B72:
	asrs r1, 3
	ldr r0, [r2]
	adds r0, r1
	str r0, [r2]
	ldr r1, [r4]
	adds r0, r1, 0
	cmp r1, 0
	bge _080A5B84
	adds r0, r1, 0x7
_080A5B84:
	asrs r0, 3
	lsls r0, 3
	subs r0, r1, r0
	str r0, [r4]
	ldr r0, [r7]
	movs r1, 0
	bl sub_80A4580
	mov r1, r8
	ldr r0, [r1]
	adds r0, 0xF8
	ldr r1, [sp]
	ldr r0, [r0]
	adds r1, r0
	str r1, [sp, 0x18]
	ldr r0, [sp, 0x4]
	add r4, sp, 0x18
	str r0, [r4, 0x4]
	ldr r0, [r7]
	movs r1, 0
	adds r2, r4, 0
	bl sub_80A4580
	ldr r0, [r7]
	movs r1, 0
	adds r2, r4, 0
	bl sub_80A456C
	b _080A5DCE
_080A5BBE:
	ldr r0, [sp]
	ldr r1, [sp, 0x4]
	str r0, [sp, 0x20]
	str r1, [sp, 0x24]
	ldr r0, [r7]
	add r4, sp, 0x20
	movs r1, 0
	adds r2, r4, 0
	bl sub_80A4580
	ldr r0, [r7]
	movs r1, 0
	b _080A5DD2
_080A5BD8:
	ldr r0, [r7]
	movs r1, 0
	mov r2, sp
	bl sub_80A456C
	mov r0, r8
	ldr r3, [r0]
	adds r4, r3, 0
	adds r4, 0xF0
	adds r1, r3, 0
	adds r1, 0xE8
	ldr r0, [r4]
	ldr r1, [r1]
	adds r0, r1
	str r0, [r4]
	adds r5, r3, 0
	adds r5, 0xF4
	adds r1, r3, 0
	adds r1, 0xEC
	ldr r0, [r5]
	ldr r1, [r1]
	adds r0, r1
	str r0, [r5]
	adds r2, r3, 0
	adds r2, 0xF8
	ldr r1, [r4]
	cmp r1, 0
	bge _080A5C12
	adds r1, 0x7
_080A5C12:
	asrs r1, 3
	ldr r0, [r2]
	adds r0, r1
	str r0, [r2]
	adds r3, 0xFC
	ldr r1, [r5]
	cmp r1, 0
	bge _080A5C24
	adds r1, 0x7
_080A5C24:
	asrs r1, 3
	ldr r0, [r3]
	adds r0, r1
	str r0, [r3]
	ldr r1, [r4]
	adds r0, r1, 0
	cmp r1, 0
	bge _080A5C36
	adds r0, r1, 0x7
_080A5C36:
	asrs r0, 3
	lsls r0, 3
	subs r0, r1, r0
	str r0, [r4]
	ldr r1, [r5]
	adds r0, r1, 0
	cmp r1, 0
	bge _080A5C48
	adds r0, r1, 0x7
_080A5C48:
	asrs r0, 3
	lsls r0, 3
	subs r0, r1, r0
	str r0, [r5]
	ldr r0, [r7]
	movs r1, 0
	bl sub_80A4580
	mov r1, r8
	ldr r2, [r1]
	adds r1, r2, 0
	adds r1, 0xF8
	ldr r0, [sp]
	ldr r1, [r1]
	adds r0, r1
	str r0, [sp, 0x28]
	adds r2, 0xFC
	mov r1, r9
	ldr r0, [r1, 0x4]
	ldr r1, [r2]
	adds r0, r1
	add r4, sp, 0x28
	b _080A5DC2
_080A5C76:
	adds r4, r3, 0
	adds r4, 0xF0
	adds r1, r3, 0
	adds r1, 0xE8
	ldr r0, [r4]
	ldr r1, [r1]
	adds r0, r1
	str r0, [r4]
	adds r5, r3, 0
	adds r5, 0xF4
	adds r1, r3, 0
	adds r1, 0xEC
	ldr r0, [r5]
	ldr r1, [r1]
	adds r0, r1
	str r0, [r5]
	adds r6, r3, 0
	adds r6, 0xF8
	ldr r1, [r4]
	cmp r1, 0
	bge _080A5CA2
	adds r1, 0x7
_080A5CA2:
	asrs r1, 3
	ldr r0, [r6]
	adds r0, r1
	str r0, [r6]
	adds r2, r3, 0
	adds r2, 0xFC
	ldr r1, [r5]
	cmp r1, 0
	bge _080A5CB6
	adds r1, 0x7
_080A5CB6:
	asrs r1, 3
	ldr r0, [r2]
	adds r0, r1
	str r0, [r2]
	ldr r1, [r4]
	adds r0, r1, 0
	cmp r1, 0
	bge _080A5CC8
	adds r0, r1, 0x7
_080A5CC8:
	asrs r0, 3
	lsls r0, 3
	subs r0, r1, r0
	str r0, [r4]
	ldr r1, [r5]
	adds r0, r1, 0
	cmp r1, 0
	bge _080A5CDA
	adds r0, r1, 0x7
_080A5CDA:
	asrs r0, 3
	lsls r0, 3
	subs r0, r1, r0
	str r0, [r5]
	ldr r0, [r7]
	movs r1, 0
	adds r2, r6, 0
	bl sub_80A4580
	mov r0, r8
	ldr r2, [r0]
	adds r1, r2, 0
	adds r1, 0xF8
	ldr r0, [sp]
	ldr r1, [r1]
	adds r0, r1
	str r0, [sp, 0x30]
	adds r2, 0xFC
	ldr r0, [sp, 0x4]
	ldr r1, [r2]
	adds r0, r1
	add r4, sp, 0x30
	str r0, [r4, 0x4]
	ldr r0, [r7]
	movs r1, 0
	adds r2, r4, 0
	bl sub_80A4580
	ldr r0, [r7]
	movs r1, 0
	b _080A5DD2
_080A5D18:
	ldr r0, [r7]
	movs r1, 0x1
	mov r2, sp
	bl sub_80A456C
	mov r0, r8
	ldr r1, [r0]
	adds r3, r1, 0
	adds r3, 0xF0
	ldr r4, [r3]
	adds r0, r4, 0x1
	str r0, [r3]
	adds r2, r1, 0
	adds r2, 0xF8
	cmp r0, 0
	bge _080A5D3A
	adds r0, r4, 0x4
_080A5D3A:
	asrs r1, r0, 2
	ldr r0, [r2]
	adds r0, r1
	str r0, [r2]
	ldr r0, [r3]
	movs r1, 0x3
	ands r0, r1
	str r0, [r3]
	ldr r0, [r7]
	movs r1, 0x1
	bl sub_80A4580
	mov r1, r8
	ldr r0, [r1]
	adds r0, 0xF8
	ldr r1, [sp]
	ldr r0, [r0]
	adds r1, r0
	str r1, [sp, 0x38]
	ldr r0, [sp, 0x4]
	add r4, sp, 0x38
	str r0, [r4, 0x4]
	ldr r0, [r7]
	movs r1, 0
	adds r2, r4, 0
	bl sub_80A4580
	ldr r0, [r7]
	movs r1, 0
	b _080A5DD2
_080A5D76:
	ldr r0, [r7]
	movs r1, 0
	mov r2, sp
	bl sub_80A456C
	mov r0, r8
	ldr r1, [r0]
	adds r3, r1, 0
	adds r3, 0xF0
	ldr r4, [r3]
	adds r0, r4, 0x1
	str r0, [r3]
	adds r2, r1, 0
	adds r2, 0xF8
	cmp r0, 0
	bge _080A5D98
	adds r0, 0x7
_080A5D98:
	asrs r1, r0, 3
	ldr r0, [r2]
	adds r0, r1
	str r0, [r2]
	ldr r0, [r3]
	movs r1, 0x7
	ands r0, r1
	str r0, [r3]
	ldr r0, [r7]
	movs r1, 0x1
	bl sub_80A4580
	mov r1, r8
	ldr r0, [r1]
	adds r0, 0xF8
	ldr r1, [sp]
	ldr r0, [r0]
	adds r1, r0
	str r1, [sp, 0x40]
	ldr r0, [sp, 0x4]
	add r4, sp, 0x40
_080A5DC2:
	str r0, [r4, 0x4]
	ldr r0, [r7]
	movs r1, 0x1
	adds r2, r4, 0
	bl sub_80A4580
_080A5DCE:
	ldr r0, [r7]
_080A5DD0:
	movs r1, 0x1
_080A5DD2:
	adds r2, r4, 0
	bl sub_80A456C
	b _080A5E52
_080A5DDA:
	ldr r0, [r7]
	movs r1, 0
	mov r2, sp
	bl sub_80A456C
	mov r0, r8
	ldr r1, [r0]
	adds r3, r1, 0
	adds r3, 0xF0
	ldr r4, [r3]
	adds r0, r4, 0x1
	str r0, [r3]
	adds r2, r1, 0
	adds r2, 0xF8
	cmp r0, 0
	bge _080A5DFC
	adds r0, 0x7
_080A5DFC:
	asrs r1, r0, 3
	ldr r0, [r2]
	adds r0, r1
	str r0, [r2]
	ldr r0, [r3]
	movs r1, 0x7
	ands r0, r1
	str r0, [r3]
	ldr r0, [r7]
	movs r1, 0x1
	bl sub_80A4580
	mov r1, r8
	ldr r0, [r1]
	adds r0, 0xF8
	ldr r0, [r0]
	str r0, [sp, 0x48]
	ldr r0, [sp, 0x4]
	add r2, sp, 0x48
	str r0, [r2, 0x4]
	ldr r0, [r7]
	b _080A5E3E
_080A5E28:
	ldr r0, [r7]
	movs r1, 0
	mov r2, sp
	bl sub_80A456C
	movs r0, 0
	movs r1, 0
	str r0, [sp, 0x50]
	str r1, [sp, 0x54]
	ldr r0, [r7]
	add r2, sp, 0x50
_080A5E3E:
	movs r1, 0x1
	bl sub_80A456C
	b _080A5E52
_080A5E46:
	ldr r0, _080A5E6C
	ldr r0, [r0]
	movs r1, 0
	mov r2, sp
	bl sub_80A456C
_080A5E52:
	ldr r0, _080A5E6C
	ldr r0, [r0]
	bl sub_80A4764
_080A5E5A:
	bl sub_80A60D8
	add sp, 0x58
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_080A5E6C: .4byte gGroundMapDungeon_3001B70
	thumb_func_end sub_80A59DC

    .align 2,0
