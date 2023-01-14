	#include "asm/constants/gba_constants.inc"
	#include "asm/macros.inc"

	.syntax unified

	.text

	thumb_func_start sub_8095B28
sub_8095B28:
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	ldr r4, _08095B44
	add sp, r4
	adds r4, r0, 0
	bl sub_8095CE0
	lsls r0, 24
	cmp r0, 0
	bne _08095B48
	movs r0, 0
	b _08095CCC
	.align 2, 0
_08095B44: .4byte 0xfffffcb0
_08095B48:
	movs r0, 0x5
	strb r0, [r4]
	movs r0, 0x8
	bl RandInt
	ldr r1, _08095BC8
	adds r0, r1
	ldrb r0, [r0]
	strb r0, [r4, 0x1]
	cmp r0, 0x2
	bne _08095B6C
	bl GetRescueTeamRank
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0
	bne _08095B6C
	strb r0, [r4, 0x1]
_08095B6C:
	movs r0, 0
	strb r0, [r4, 0x2]
	bl Rand32Bit
	ldr r1, _08095BCC
	ands r1, r0
	str r1, [r4, 0x8]
	movs r7, 0
	movs r5, 0x1
	adds r0, r4, 0x4
	mov r8, r0
	movs r1, 0x12
	adds r1, r4
	mov r9, r1
	mov r6, sp
_08095B8A:
	lsls r0, r5, 16
	asrs r0, 16
	bl sub_803C110
	lsls r0, 24
	cmp r0, 0
	beq _08095B9E
	strh r5, [r6]
	adds r6, 0x2
	adds r7, 0x1
_08095B9E:
	adds r5, 0x1
	ldr r0, _08095BD0
	cmp r5, r0
	ble _08095B8A
	cmp r7, 0
	beq _08095BD4
	adds r0, r7, 0
	bl RandInt
	lsls r0, 1
	add r0, sp
	ldrh r0, [r0]
	strh r0, [r4, 0xC]
	adds r0, r7, 0
	bl RandInt
	lsls r0, 1
	add r0, sp
	ldrh r0, [r0]
	b _08095BDC
	.align 2, 0
_08095BC8: .4byte gUnknown_8109984
_08095BCC: .4byte 0x00ffffff
_08095BD0: .4byte 0x000001a7
_08095BD4:
	movs r0, 0x10
	strh r0, [r4, 0xC]
	movs r0, 0x91
	lsls r0, 1
_08095BDC:
	strh r0, [r4, 0xE]
	ldrb r0, [r4, 0x1]
	subs r0, 0x1
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bls _08095BEE
	ldrh r0, [r4, 0xC]
	strh r0, [r4, 0xE]
_08095BEE:
	ldrb r0, [r4, 0x4]
	bl sub_8095F28
	strb r0, [r4, 0x10]
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0
	bne _08095C10
	strb r0, [r4, 0x1]
	ldrh r0, [r4, 0xC]
	strh r0, [r4, 0xE]
	adds r2, r4, 0
	adds r2, 0x10
	mov r0, r8
	movs r1, 0
	bl sub_803C37C
_08095C10:
	ldrb r0, [r4, 0x4]
	bl GetMaxItemCount
	adds r1, r0, 0
	cmp r1, 0
	bne _08095C28
	ldrb r0, [r4, 0x1]
	cmp r0, 0x4
	bne _08095C28
	strb r1, [r4, 0x1]
	ldrh r0, [r4, 0xC]
	strh r0, [r4, 0xE]
_08095C28:
	ldrb r1, [r4, 0x1]
	mov r0, r8
	mov r2, r9
	bl sub_803C37C
	ldrb r0, [r4, 0x10]
	ldrb r1, [r4, 0x12]
	cmp r0, r1
	beq _08095C28
	movs r0, 0
	strb r0, [r4, 0x13]
	ldrb r0, [r4, 0x1]
	cmp r0, 0x2
	beq _08095C90
	cmp r0, 0x2
	bgt _08095C4E
	cmp r0, 0x1
	beq _08095C6C
	b _08095CCA
_08095C4E:
	cmp r0, 0x4
	bgt _08095CCA
	bl Rand32Bit
	adds r1, r0, 0
	movs r0, 0xE0
	lsls r0, 3
	ands r1, r0
	movs r0, 0xC0
	lsls r0, 2
	cmp r1, r0
	beq _08095CC4
	cmp r1, r0
	bgt _08095CB4
	b _08095CAA
_08095C6C:
	bl Rand32Bit
	adds r1, r0, 0
	movs r0, 0x70
	ands r1, r0
	cmp r1, 0x10
	beq _08095C80
	cmp r1, 0x30
	beq _08095C88
	b _08095CCA
_08095C80:
	adds r0, r4, 0
	bl sub_803C3E0
	b _08095CCA
_08095C88:
	adds r0, r4, 0
	bl sub_803C45C
	b _08095CCA
_08095C90:
	bl Rand32Bit
	movs r1, 0xC0
	lsls r1, 6
	ands r1, r0
	movs r0, 0x80
	lsls r0, 5
	cmp r1, r0
	bne _08095CCA
	adds r0, r4, 0
	bl sub_803C4F0
	b _08095CCA
_08095CAA:
	movs r0, 0x80
	lsls r0, 1
	cmp r1, r0
	beq _08095CBC
	b _08095CCA
_08095CB4:
	movs r0, 0xC0
	lsls r0, 3
	cmp r1, r0
	bne _08095CCA
_08095CBC:
	adds r0, r4, 0
	bl sub_803C580
	b _08095CCA
_08095CC4:
	adds r0, r4, 0
	bl sub_803C610
_08095CCA:
	movs r0, 0x1
_08095CCC:
	movs r3, 0xD4
	lsls r3, 2
	add sp, r3
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_8095B28

	thumb_func_start sub_8095CE0
sub_8095CE0:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x60
	str r0, [sp, 0x44]
	mov r0, sp
	bl sub_80A29B0
	str r0, [sp, 0x4C]
	cmp r0, 0
	bne _08095D0C
	mov r0, sp
	add r1, sp, 0x4C
	ldrb r1, [r1]
	strb r1, [r0]
	mov r1, sp
	movs r0, 0x1
	strb r0, [r1, 0x1]
	movs r2, 0x2
	str r2, [sp, 0x4C]
_08095D0C:
	ldr r0, [sp, 0x4C]
	bl RandInt
	mov r9, r0
	str r0, [sp, 0x48]
	mov r1, sp
	adds r1, 0x40
	str r1, [sp, 0x5C]
_08095D1C:
	mov r0, sp
	add r0, r9
	ldrb r7, [r0]
	adds r0, r7, 0
	bl GetDungeonFloorCount
	str r0, [sp, 0x58]
	lsrs r0, 31
	ldr r2, [sp, 0x58]
	adds r0, r2, r0
	asrs r0, 1
	str r0, [sp, 0x54]
	adds r1, r2, 0
	bl RandRange
	adds r4, r0, 0
	str r4, [sp, 0x50]
_08095D3E:
	movs r0, 0x1
	mov r8, r0
	ldr r1, _08095DF4
	ldr r0, [sp, 0x40]
	ands r0, r1
	orrs r0, r7
	lsls r2, r4, 24
	lsrs r2, 16
	ldr r1, _08095DF8
	ands r0, r1
	orrs r0, r2
	str r0, [sp, 0x40]
	ldr r0, [sp, 0x5C]
	bl sub_809017C
	lsls r0, 24
	cmp r0, 0
	beq _08095D66
	movs r1, 0
	mov r8, r1
_08095D66:
	ldr r2, _08095DFC
	mov r10, r2
	movs r6, 0
	movs r5, 0x3
_08095D6E:
	mov r1, r10
	ldr r0, [r1]
	adds r0, r6
	adds r1, r7, 0
	adds r2, r4, 0
	movs r3, 0x1
	bl sub_8095E38
	lsls r0, 24
	cmp r0, 0
	beq _08095D88
	movs r2, 0
	mov r8, r2
_08095D88:
	adds r6, 0x14
	subs r5, 0x1
	cmp r5, 0
	bge _08095D6E
	ldr r0, _08095DFC
	mov r10, r0
	movs r6, 0x50
	movs r5, 0x7
_08095D98:
	mov r1, r10
	ldr r0, [r1]
	adds r0, r6
	adds r1, r7, 0
	adds r2, r4, 0
	movs r3, 0x1
	bl sub_8095E38
	lsls r0, 24
	cmp r0, 0
	beq _08095DB2
	movs r2, 0
	mov r8, r2
_08095DB2:
	adds r6, 0x14
	subs r5, 0x1
	cmp r5, 0
	bge _08095D98
	ldr r0, _08095DFC
	mov r10, r0
	movs r6, 0xF0
	movs r5, 0x7
_08095DC2:
	mov r1, r10
	ldr r0, [r1]
	adds r0, r6
	adds r1, r7, 0
	adds r2, r4, 0
	movs r3, 0x1
	bl sub_8095E38
	lsls r0, 24
	cmp r0, 0
	beq _08095DDC
	movs r2, 0
	mov r8, r2
_08095DDC:
	adds r6, 0x14
	subs r5, 0x1
	cmp r5, 0
	bge _08095DC2
	mov r0, r8
	cmp r0, 0
	beq _08095E00
	ldr r1, [sp, 0x44]
	strb r7, [r1, 0x4]
	strb r4, [r1, 0x5]
	movs r0, 0x1
	b _08095E28
	.align 2, 0
_08095DF4: .4byte 0xffffff00
_08095DF8: .4byte 0xffff00ff
_08095DFC: .4byte gUnknown_203B490
_08095E00:
	adds r4, 0x1
	ldr r2, [sp, 0x58]
	cmp r4, r2
	blt _08095E0A
	ldr r4, [sp, 0x54]
_08095E0A:
	ldr r0, [sp, 0x50]
	cmp r4, r0
	bne _08095D3E
	movs r1, 0x1
	add r9, r1
	ldr r2, [sp, 0x4C]
	cmp r9, r2
	bne _08095E1E
	movs r0, 0
	mov r9, r0
_08095E1E:
	ldr r1, [sp, 0x48]
	cmp r9, r1
	beq _08095E26
	b _08095D1C
_08095E26:
	movs r0, 0
_08095E28:
	add sp, 0x60
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_8095CE0

	thumb_func_start sub_8095E38
sub_8095E38:
	push {r4,lr}
	adds r4, r0, 0
	lsls r1, 24
	lsrs r1, 24
	lsls r3, 24
	lsrs r3, 24
	ldrb r0, [r4]
	cmp r0, 0
	beq _08095E6E
	ldrb r0, [r4, 0x1]
	cmp r0, 0x2
	bne _08095E5E
	cmp r3, 0x1
	bne _08095E5E
	ldrb r0, [r4, 0x4]
	cmp r0, r1
	bne _08095E6E
	movs r0, 0x1
	b _08095E70
_08095E5E:
	ldrb r0, [r4, 0x4]
	cmp r0, r1
	bne _08095E6E
	ldrb r0, [r4, 0x5]
	cmp r0, r2
	bne _08095E6E
	movs r0, 0x1
	b _08095E70
_08095E6E:
	movs r0, 0
_08095E70:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_8095E38

	thumb_func_start sub_8095E78
sub_8095E78:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0x3C
	movs r6, 0
	movs r5, 0x1
_08095E84:
	ldr r0, _08095F04
	ldr r0, [r0]
	adds r0, r5
	ldrb r0, [r0]
	adds r1, r5, 0x1
	mov r8, r1
	cmp r0, 0
	bne _08095EF6
	lsls r0, r5, 24
	lsrs r0, 24
	bl GetFriendAreaUnlockCondition
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x2
	bne _08095EF6
	movs r4, 0
	ldr r0, _08095F08
	ldr r1, [r0]
	movs r3, 0x3
_08095EAC:
	ldrb r0, [r1]
	cmp r0, 0
	beq _08095EBA
	ldrb r0, [r1, 0x11]
	cmp r0, 0x9
	bne _08095EBA
	movs r4, 0x1
_08095EBA:
	adds r1, 0x14
	subs r3, 0x1
	cmp r3, 0
	bge _08095EAC
	ldr r0, _08095F08
	ldr r0, [r0]
	adds r2, r0, 0
	adds r2, 0xF0
	adds r1, r0, 0
	movs r3, 0x7
_08095ECE:
	ldrb r0, [r2]
	cmp r0, 0
	beq _08095EE0
	ldr r7, _08095F0C
	adds r0, r1, r7
	ldrb r0, [r0]
	cmp r0, 0x9
	bne _08095EE0
	movs r4, 0x1
_08095EE0:
	adds r2, 0x14
	adds r1, 0x14
	subs r3, 0x1
	cmp r3, 0
	bge _08095ECE
	cmp r4, 0
	bne _08095EF6
	mov r1, sp
	adds r0, r1, r6
	strb r5, [r0]
	adds r6, 0x1
_08095EF6:
	mov r5, r8
	cmp r5, 0x39
	ble _08095E84
	cmp r6, 0
	bne _08095F10
	movs r0, 0
	b _08095F1A
	.align 2, 0
_08095F04: .4byte gFriendAreas
_08095F08: .4byte gUnknown_203B490
_08095F0C: .4byte 0x00000101
_08095F10:
	adds r0, r6, 0
	bl RandInt
	add r0, sp
	ldrb r0, [r0]
_08095F1A:
	add sp, 0x3C
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_8095E78

	thumb_func_start sub_8095F28
sub_8095F28:
	push {r4-r7,lr}
	sub sp, 0xF0
	lsls r0, 24
	lsrs r7, r0, 24
	movs r6, 0
	movs r5, 0x1
_08095F34:
	lsls r4, r5, 24
	cmp r7, 0x63
	beq _08095F48
	lsrs r1, r4, 24
	adds r0, r7, 0
	bl xxx_bit_lut_lookup_8091E50
	lsls r0, 24
	cmp r0, 0
	beq _08095F6A
_08095F48:
	lsrs r4, 24
	adds r0, r4, 0
	bl IsThrowableItem
	lsls r0, 24
	cmp r0, 0
	bne _08095F6A
	adds r0, r4, 0
	bl IsNotMoneyOrUsedTMItem
	lsls r0, 24
	cmp r0, 0
	beq _08095F6A
	mov r1, sp
	adds r0, r1, r6
	strb r5, [r0]
	adds r6, 0x1
_08095F6A:
	adds r5, 0x1
	cmp r5, 0xEF
	ble _08095F34
	cmp r6, 0
	beq _08095F80
	adds r0, r6, 0
	bl RandInt
	add r0, sp
	ldrb r0, [r0]
	b _08095F82
_08095F80:
	movs r0, 0
_08095F82:
	add sp, 0xF0
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_8095F28


        .align 2,0
