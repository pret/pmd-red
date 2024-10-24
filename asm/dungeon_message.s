	#include "asm/constants/gba_constants.inc"
	#include "asm/macros.inc"

	.syntax unified
	.text

	thumb_func_start sub_8056B34
sub_8056B34:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x4
	adds r7, r0, 0
	adds r6, r1, 0
	mov r8, r2
	adds r1, r3, 0
	ldr r4, [sp, 0x24]
	lsls r4, 24
	lsrs r4, 24
	mov r0, r8
	bl GetMoveAccuracyOrAIChance
	adds r5, r0, 0
	movs r0, 0x64
	bl DungeonRandInt
	str r0, [sp]
	ldr r0, [r7, 0x70]
	mov r9, r0
	ldr r1, [r6, 0x70]
	mov r10, r1
	cmp r4, 0
	beq _08056B70
	cmp r7, r6
	bne _08056B70
	b _08056CD4
_08056B70:
	mov r0, r8
	ldrh r1, [r0, 0x2]
	ldr r0, _08056CC4
	cmp r1, r0
	bne _08056B8A
	adds r0, r7, 0
	movs r1, 0x4
	bl IQSkillIsEnabled
	lsls r0, 24
	cmp r0, 0
	beq _08056B8A
	b _08056CD4
_08056B8A:
	mov r0, r9
	adds r0, 0xDC
	ldrb r0, [r0]
	cmp r0, 0x1
	bne _08056B96
	b _08056CD4
_08056B96:
	cmp r0, 0x2
	bne _08056B9C
	b _08056CBE
_08056B9C:
	cmp r5, 0x64
	ble _08056BA2
	b _08056CD4
_08056BA2:
	adds r0, r6, 0
	movs r1, 0x23
	bl HasHeldItem
	lsls r0, 24
	cmp r0, 0
	beq _08056BB6
	ldr r0, _08056CC8
	ldr r0, [r0]
	subs r5, r0
_08056BB6:
	adds r0, r6, 0
	movs r1, 0x5
	bl IQSkillIsEnabled
	lsls r0, 24
	cmp r0, 0
	beq _08056BCA
	ldr r0, _08056CCC
	ldr r0, [r0]
	subs r5, r0
_08056BCA:
	mov r1, r9
	movs r0, 0x24
	ldrsh r4, [r1, r0]
	adds r0, r7, 0
	movs r1, 0x33
	bl HasAbility
	lsls r0, 24
	cmp r0, 0
	beq _08056BE0
	adds r4, 0x2
_08056BE0:
	mov r1, r8
	ldrh r0, [r1, 0x2]
	cmp r0, 0x40
	bne _08056BFC
	adds r0, r7, 0
	bl GetApparentWeather
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x4
	beq _08056CD4
	cmp r0, 0x1
	bne _08056BFC
	subs r4, 0x2
_08056BFC:
	cmp r4, 0
	bge _08056C02
	movs r4, 0
_08056C02:
	cmp r4, 0x14
	ble _08056C08
	movs r4, 0x14
_08056C08:
	ldr r1, _08056CD0
	lsls r0, r4, 2
	adds r0, r1
	ldr r0, [r0]
	cmp r0, 0
	bge _08056C16
	movs r0, 0
_08056C16:
	movs r1, 0xC8
	lsls r1, 7
	cmp r0, r1
	ble _08056C20
	adds r0, r1, 0
_08056C20:
	muls r5, r0
	adds r0, r5, 0
	cmp r5, 0
	bge _08056C2A
	adds r0, 0xFF
_08056C2A:
	asrs r5, r0, 8
	mov r0, r10
	movs r1, 0x26
	ldrsh r4, [r0, r1]
	adds r0, 0xF5
	ldrb r0, [r0]
	cmp r0, 0
	beq _08056C3C
	movs r4, 0xA
_08056C3C:
	adds r0, r6, 0
	bl GetApparentWeather
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x2
	bne _08056C5A
	adds r0, r6, 0
	movs r1, 0x1D
	bl HasAbility
	lsls r0, 24
	cmp r0, 0
	beq _08056C5A
	adds r4, 0x2
_08056C5A:
	adds r0, r7, 0
	movs r1, 0x30
	bl HasAbility
	lsls r0, 24
	cmp r0, 0
	beq _08056C86
	mov r0, r8
	bl GetMoveType
	lsls r0, 24
	lsrs r0, 24
	bl IsTypePhysical
	movs r1, 0
	lsls r0, 24
	cmp r0, 0
	bne _08056C80
	movs r1, 0x1
_08056C80:
	cmp r1, 0
	bne _08056C86
	adds r4, 0x2
_08056C86:
	cmp r4, 0
	bge _08056C8C
	movs r4, 0
_08056C8C:
	cmp r4, 0x14
	ble _08056C92
	movs r4, 0x14
_08056C92:
	ldr r0, _08056CD0
	lsls r1, r4, 2
	adds r0, 0x54
	adds r1, r0
	ldr r0, [r1]
	cmp r0, 0
	bge _08056CA2
	movs r0, 0
_08056CA2:
	movs r1, 0xC8
	lsls r1, 7
	cmp r0, r1
	ble _08056CAC
	adds r0, r1, 0
_08056CAC:
	muls r5, r0
	adds r0, r5, 0
	cmp r5, 0
	bge _08056CB6
	adds r0, 0xFF
_08056CB6:
	asrs r5, r0, 8
	ldr r0, [sp]
	cmp r0, r5
	blt _08056CD4
_08056CBE:
	movs r0, 0
	b _08056CD6
	.align 2, 0
_08056CC4: .4byte 0x00000163
_08056CC8: .4byte gUnknown_80F519C
_08056CCC: .4byte gUnknown_80F51A0
_08056CD0: .4byte gUnknown_80F50F4
_08056CD4:
	movs r0, 0x1
_08056CD6:
	add sp, 0x4
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_8056B34

	thumb_func_start sub_8056CE8
sub_8056CE8:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x18
	str r0, [sp, 0x10]
	adds r5, r1, 0
	mov r8, r2
	movs r0, 0
	mov r9, r0
	movs r3, 0
	ldr r1, [r5, 0x70]
	adds r0, r1, 0
	adds r0, 0xBC
	ldrb r2, [r0]
	cmp r2, 0x2
	beq _08056D18
	adds r0, 0x2C
	ldrb r0, [r0]
	cmp r0, 0x1
	beq _08056D18
	cmp r2, 0x4
	bne _08056D1A
_08056D18:
	movs r3, 0x1
_08056D1A:
	mov r10, r3
	movs r1, 0
	ldr r0, [r5, 0x70]
	adds r0, 0xBC
	ldrb r0, [r0]
	cmp r0, 0x2
	beq _08056D2C
	cmp r0, 0x4
	bne _08056D2E
_08056D2C:
	movs r1, 0x1
_08056D2E:
	str r1, [sp, 0x14]
	adds r0, r5, 0
	movs r1, 0x7
	bl IQSkillIsEnabled
	lsls r0, 24
	cmp r0, 0
	beq _08056D44
	movs r1, 0
	str r1, [sp, 0x14]
	mov r10, r1
_08056D44:
	adds r0, r5, 0
	mov r1, r8
	movs r2, 0
	bl GetMoveTargetAndRangeForPokemon
	lsls r0, 16
	asrs r7, r0, 16
	movs r0, 0xF
	ands r0, r7
	cmp r0, 0x4
	bne _08056D86
	adds r0, r5, 0
	mov r1, r8
	bl MoveMatchesChargingStatus
	lsls r0, 24
	lsrs r4, r0, 24
	mov r2, r8
	ldrh r0, [r2, 0x2]
	cmp r0, 0x97
	bne _08056D7E
	adds r0, r5, 0
	bl GetApparentWeather
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _08056D7E
	movs r4, 0x1
_08056D7E:
	movs r7, 0x73
	cmp r4, 0
	beq _08056D86
	movs r7, 0
_08056D86:
	movs r1, 0xF0
	ands r1, r7
	cmp r1, 0
	bne _08056DA6
	adds r0, r5, 0
	bl sub_80696A8
	cmp r0, 0
	bne _08056D9A
	b _08056F64
_08056D9A:
	str r0, [sp]
	mov r0, r8
	str r0, [sp, 0x4]
	mov r1, r10
	str r1, [sp, 0x8]
	b _08056F56
_08056DA6:
	cmp r1, 0x10
	beq _08056DAE
	cmp r1, 0x20
	bne _08056E34
_08056DAE:
	ldr r0, [r5, 0x70]
	cmp r1, 0x20
	bne _08056DBC
	adds r0, 0x46
	ldrb r4, [r0]
	movs r0, 0x8
	b _08056DCA
_08056DBC:
	adds r0, 0x46
	ldrb r0, [r0]
	subs r4, r0, 0x1
	movs r0, 0x3
	cmp r0, 0
	bne _08056DCA
	b _08056F64
_08056DCA:
	adds r6, r0, 0
_08056DCC:
	movs r0, 0x7
	ands r4, r0
	ldr r0, _08056E28
	lsls r3, r4, 2
	adds r3, r0
	ldrh r0, [r3]
	ldrh r2, [r5, 0x4]
	adds r0, r2
	lsls r0, 16
	lsrs r0, 16
	ldr r2, _08056E2C
	ldr r1, [sp, 0xC]
	ands r1, r2
	orrs r1, r0
	str r1, [sp, 0xC]
	ldrh r2, [r3, 0x2]
	ldrh r0, [r5, 0x6]
	adds r2, r0
	lsls r2, 16
	ldr r0, _08056E30
	ands r1, r0
	orrs r1, r2
	str r1, [sp, 0xC]
	add r0, sp, 0xC
	bl sub_804AD0C
	cmp r0, 0
	beq _08056E1C
	str r0, [sp]
	mov r1, r8
	str r1, [sp, 0x4]
	mov r2, r10
	str r2, [sp, 0x8]
	mov r0, r9
	ldr r1, [sp, 0x10]
	adds r2, r7, 0
	adds r3, r5, 0
	bl sub_8056F80
	mov r9, r0
_08056E1C:
	subs r6, 0x1
	adds r4, 0x1
	cmp r6, 0
	bne _08056DCC
	b _08056F64
	.align 2, 0
_08056E28: .4byte gAdjacentTileOffsets
_08056E2C: .4byte 0xffff0000
_08056E30: .4byte 0x0000ffff
_08056E34:
	cmp r1, 0x30
	bne _08056E9C
	movs r6, 0
_08056E3A:
	ldr r0, _08056E74
	ldr r0, [r0]
	lsls r1, r6, 2
	ldr r2, _08056E78
	adds r0, r2
	adds r0, r1
	ldr r4, [r0]
	adds r0, r4, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	beq _08056E94
	adds r0, r5, 0
	adds r1, r4, 0
	bl sub_8045A70
	lsls r0, 24
	cmp r0, 0
	beq _08056E94
	cmp r4, r5
	bne _08056E7C
	str r5, [sp]
	mov r0, r8
	str r0, [sp, 0x4]
	ldr r1, [sp, 0x14]
	str r1, [sp, 0x8]
	b _08056E86
	.align 2, 0
_08056E74: .4byte gDungeon
_08056E78: .4byte 0x000135cc
_08056E7C:
	str r4, [sp]
	mov r2, r8
	str r2, [sp, 0x4]
	mov r0, r10
	str r0, [sp, 0x8]
_08056E86:
	mov r0, r9
	ldr r1, [sp, 0x10]
	adds r2, r7, 0
	adds r3, r5, 0
	bl sub_8056F80
	mov r9, r0
_08056E94:
	adds r6, 0x1
	cmp r6, 0x13
	ble _08056E3A
	b _08056F64
_08056E9C:
	cmp r1, 0x40
	bne _08056EEA
	movs r4, 0
	adds r0, r5, 0
	bl sub_80696FC
	cmp r0, 0
	beq _08056ED0
	mov r4, r9
	str r0, [sp]
	mov r1, r8
	str r1, [sp, 0x4]
	mov r2, r10
	str r2, [sp, 0x8]
	adds r0, r4, 0
	ldr r1, [sp, 0x10]
	adds r2, r7, 0
	adds r3, r5, 0
	bl sub_8056F80
	mov r9, r0
	mov r1, r9
	eors r1, r4
	negs r0, r1
	orrs r0, r1
	lsrs r4, r0, 31
_08056ED0:
	cmp r4, 0
	bne _08056F64
	adds r0, r5, 0
	bl sub_806977C
	cmp r0, 0
	beq _08056F64
	str r0, [sp]
	mov r0, r8
	str r0, [sp, 0x4]
	mov r1, r10
	str r1, [sp, 0x8]
	b _08056F56
_08056EEA:
	cmp r1, 0x50
	beq _08056F64
	cmp r1, 0x80
	bne _08056F00
	adds r0, r5, 0
	bl sub_80696FC
	cmp r0, 0
	beq _08056F64
	str r0, [sp]
	b _08056F4E
_08056F00:
	cmp r1, 0x60
	bne _08056F48
	movs r6, 0
_08056F06:
	ldr r0, _08056F40
	ldr r0, [r0]
	lsls r1, r6, 2
	ldr r2, _08056F44
	adds r0, r2
	adds r0, r1
	ldr r4, [r0]
	adds r0, r4, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	beq _08056F38
	str r4, [sp]
	mov r0, r8
	str r0, [sp, 0x4]
	mov r1, r10
	str r1, [sp, 0x8]
	mov r0, r9
	ldr r1, [sp, 0x10]
	adds r2, r7, 0
	adds r3, r5, 0
	bl sub_8056F80
	mov r9, r0
_08056F38:
	adds r6, 0x1
	cmp r6, 0x13
	ble _08056F06
	b _08056F64
	.align 2, 0
_08056F40: .4byte gDungeon
_08056F44: .4byte 0x000135cc
_08056F48:
	cmp r1, 0x70
	bne _08056F64
	str r5, [sp]
_08056F4E:
	mov r2, r8
	str r2, [sp, 0x4]
	mov r0, r10
	str r0, [sp, 0x8]
_08056F56:
	mov r0, r9
	ldr r1, [sp, 0x10]
	adds r2, r7, 0
	adds r3, r5, 0
	bl sub_8056F80
	mov r9, r0
_08056F64:
	mov r1, r9
	lsls r0, r1, 2
	ldr r2, [sp, 0x10]
	adds r0, r2
	movs r1, 0
	str r1, [r0]
	add sp, 0x18
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_8056CE8

	thumb_func_start sub_8056F80
sub_8056F80:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	adds r5, r0, 0
	mov r8, r1
	adds r4, r3, 0
	ldr r7, [sp, 0x18]
	ldr r0, [sp, 0x20]
	lsls r2, 16
	asrs r2, 16
	lsls r0, 24
	lsrs r0, 24
	mov r12, r0
	movs r6, 0
	ldr r1, [r7, 0x70]
	ldr r3, [sp, 0x1C]
	ldrh r0, [r3, 0x2]
	cmp r0, 0xFC
	bne _08056FAA
	cmp r4, r7
	beq _08057060
_08056FAA:
	ldrb r0, [r1, 0x8]
	cmp r0, 0x1
	beq _08057060
	adds r0, r1, 0
	adds r0, 0xA4
	ldrb r0, [r0]
	cmp r0, 0x4
	beq _08057060
	cmp r0, 0x1
	beq _08057060
	mov r0, r12
	cmp r0, 0
	bne _0805702C
	movs r0, 0xF
	ands r0, r2
	cmp r0, 0
	beq _08056FD0
	cmp r0, 0x4
	bne _08056FE6
_08056FD0:
	adds r0, r4, 0
	adds r1, r7, 0
	movs r2, 0x1
	movs r3, 0
	bl GetTreatmentBetweenMonsters
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _0805702E
	b _0805702C
_08056FE6:
	cmp r0, 0x1
	bne _08056FFE
	adds r0, r4, 0
	adds r1, r7, 0
	movs r2, 0x1
	movs r3, 0
	bl GetTreatmentBetweenMonsters
	lsls r0, 24
	cmp r0, 0
	bne _0805702E
	b _0805702C
_08056FFE:
	cmp r0, 0x2
	beq _0805702C
	cmp r0, 0x5
	bne _0805700C
	cmp r4, r7
	beq _0805702E
	b _0805702C
_0805700C:
	cmp r0, 0x6
	bne _08057028
	adds r0, r4, 0
	adds r1, r7, 0
	movs r2, 0x1
	movs r3, 0
	bl GetTreatmentBetweenMonsters
	lsls r0, 24
	cmp r0, 0
	bne _0805702E
	cmp r4, r7
	beq _0805702E
	b _0805702C
_08057028:
	cmp r0, 0x3
	bne _0805702E
_0805702C:
	movs r6, 0x1
_0805702E:
	adds r0, r7, 0
	ldr r1, [sp, 0x1C]
	bl sub_80571F0
	lsls r0, 24
	cmp r0, 0
	beq _0805703E
	movs r6, 0
_0805703E:
	cmp r6, 0
	beq _08057060
	cmp r5, 0x3F
	bgt _08057060
	lsls r0, r5, 2
	add r0, r8
	str r7, [r0]
	ldr r0, [r7, 0x70]
	ldrb r0, [r0, 0x6]
	cmp r0, 0
	bne _0805705E
	ldr r1, _0805706C
	ldr r0, [r1]
	cmp r0, 0
	bne _0805705E
	str r7, [r1]
_0805705E:
	adds r5, 0x1
_08057060:
	adds r0, r5, 0
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r1}
	bx r1
	.align 2, 0
_0805706C: .4byte gUnknown_203B438
	thumb_func_end sub_8056F80

	.align 2, 0
