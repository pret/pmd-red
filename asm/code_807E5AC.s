	#include "asm/constants/gba_constants.inc"
  	#include "asm/macros.inc"

  	.syntax unified

  	.text



	thumb_func_start sub_807F19C
sub_807F19C:
	push {r4-r7,lr}
	sub sp, 0x4
	lsls r0, 24
	lsrs r2, r0, 24
	ldr r1, _0807F1EC
	ldr r0, [sp]
	ands r0, r1
	movs r1, 0xBE
	lsls r1, 1
	orrs r0, r1
	ldr r1, _0807F1F0
	ands r0, r1
	str r0, [sp]
	ldr r0, _0807F1F4
	ldr r0, [r0]
	ldr r3, _0807F1F8
	adds r1, r0, r3
	subs r3, 0x8
	adds r0, r3
	ldr r1, [r1]
	ldr r0, [r0]
	subs r4, r1, r0
	cmp r4, 0
	bgt _0807F1CE
	b _0807F31A
_0807F1CE:
	cmp r2, 0
	beq _0807F1E6
	ldr r0, _0807F1FC
	str r4, [r0]
	ldr r0, _0807F200
	ldr r1, [r0]
	mov r0, sp
	movs r2, 0x1
	bl DisplayDungeonYesNoMessage
	cmp r0, 0x1
	beq _0807F204
_0807F1E6:
	movs r0, 0x1
	b _0807F31C
	.align 2, 0
_0807F1EC: .4byte 0xffff0000
_0807F1F0: .4byte 0xff00ffff
_0807F1F4: .4byte gDungeon
_0807F1F8: .4byte 0x00000694
_0807F1FC: .4byte gFormatArgs
_0807F200: .4byte gUnknown_80FE568
_0807F204:
	ldr r0, _0807F224
	ldr r0, [r0]
	movs r1, 0x98
	lsls r1, 2
	adds r0, r1
	ldr r0, [r0]
	cmp r0, r4
	bge _0807F22C
	ldr r0, _0807F228
	ldr r1, [r0]
	mov r0, sp
	movs r2, 0x1
	bl DisplayDungeonMessage
	movs r0, 0x2
	b _0807F31C
	.align 2, 0
_0807F224: .4byte gTeamInventoryRef
_0807F228: .4byte gUnknown_80FE520
_0807F22C:
	movs r0, 0xA6
	lsls r0, 1
	bl PlaySoundEffect
	negs r0, r4
	bl AddToTeamMoney
	movs r6, 0
_0807F23C:
	movs r5, 0
	adds r7, r6, 0x1
_0807F240:
	adds r0, r6, 0
	adds r1, r5, 0
	bl GetTile
	adds r4, r0, 0
	ldrh r1, [r4]
	movs r0, 0x20
	ands r0, r1
	cmp r0, 0
	bne _0807F27E
	ldr r0, [r4, 0x14]
	cmp r0, 0
	beq _0807F27E
	bl GetEntityType
	cmp r0, 0x3
	bne _0807F27E
	ldr r0, [r4, 0x14]
	bl GetItemData
	adds r4, r0, 0
	ldrb r0, [r4, 0x2]
	bl CanSellItem
	lsls r0, 24
	cmp r0, 0
	beq _0807F27E
	ldrb r1, [r4]
	movs r0, 0xFD
	ands r0, r1
	strb r0, [r4]
_0807F27E:
	adds r5, 0x1
	cmp r5, 0x1F
	ble _0807F240
	adds r6, r7, 0
	cmp r6, 0x37
	ble _0807F23C
	movs r5, 0
_0807F28C:
	ldr r0, _0807F324
	lsls r1, r5, 2
	ldr r0, [r0]
	adds r4, r0, r1
	ldrb r1, [r4]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _0807F2B2
	ldrb r0, [r4, 0x2]
	bl CanSellItem
	lsls r0, 24
	cmp r0, 0
	beq _0807F2B2
	ldrb r1, [r4]
	movs r0, 0xFD
	ands r0, r1
	strb r0, [r4]
_0807F2B2:
	adds r5, 0x1
	cmp r5, 0x13
	ble _0807F28C
	movs r5, 0
_0807F2BA:
	ldr r0, _0807F328
	ldr r0, [r0]
	lsls r1, r5, 2
	ldr r2, _0807F32C
	adds r0, r2
	adds r0, r1
	ldr r4, [r0]
	adds r0, r4, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	beq _0807F2F8
	ldr r0, [r4, 0x70]
	adds r4, r0, 0
	adds r4, 0x60
	ldrb r1, [r4]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _0807F2F8
	ldrb r0, [r4, 0x2]
	bl CanSellItem
	lsls r0, 24
	cmp r0, 0
	beq _0807F2F8
	ldrb r1, [r4]
	movs r0, 0xFD
	ands r0, r1
	strb r0, [r4]
_0807F2F8:
	adds r5, 0x1
	cmp r5, 0x13
	ble _0807F2BA
	ldr r0, _0807F328
	ldr r0, [r0]
	ldr r3, _0807F330
	adds r1, r0, r3
	ldr r2, _0807F334
	adds r0, r2
	ldr r0, [r0]
	str r0, [r1]
	ldr r0, _0807F338
	ldr r1, [r0]
	mov r0, sp
	movs r2, 0x1
	bl DisplayDungeonMessage
_0807F31A:
	movs r0, 0
_0807F31C:
	add sp, 0x4
	pop {r4-r7}
	pop {r1}
	bx r1
	.align 2, 0
_0807F324: .4byte gTeamInventoryRef
_0807F328: .4byte gDungeon
_0807F32C: .4byte 0x000135cc
_0807F330: .4byte 0x00000694
_0807F334: .4byte 0x0000068c
_0807F338: .4byte gUnknown_80FE4D4
	thumb_func_end sub_807F19C

	thumb_func_start sub_807F33C
sub_807F33C:
	push {r4-r7,lr}
	ldr r2, _0807F41C
	ldr r0, [r2]
	ldr r1, _0807F420
	adds r0, r1
	movs r1, 0x1
	strb r1, [r0]
	ldr r0, [r2]
	ldr r2, _0807F424
	adds r0, r2
	strb r1, [r0]
	bl GetLeader
	ldr r1, _0807F428
	ldr r1, [r1]
	bl LogMessageByIdWithPopupCheckUser
	movs r6, 0
_0807F360:
	movs r5, 0
	adds r7, r6, 0x1
_0807F364:
	adds r0, r6, 0
	adds r1, r5, 0
	bl GetTile
	adds r4, r0, 0
	ldr r0, [r4, 0x14]
	cmp r0, 0
	beq _0807F38A
	bl GetEntityType
	cmp r0, 0x3
	bne _0807F38A
	ldr r0, [r4, 0x14]
	bl GetItemData
	ldrb r2, [r0]
	movs r1, 0xFD
	ands r1, r2
	strb r1, [r0]
_0807F38A:
	adds r5, 0x1
	cmp r5, 0x1F
	ble _0807F364
	adds r6, r7, 0
	cmp r6, 0x37
	ble _0807F360
	movs r6, 0
	ldr r4, _0807F42C
	movs r5, 0x1
	movs r3, 0xFD
_0807F39E:
	lsls r1, r6, 2
	ldr r0, [r4]
	adds r2, r0, r1
	ldrb r1, [r2]
	adds r0, r5, 0
	ands r0, r1
	cmp r0, 0
	beq _0807F3B4
	adds r0, r3, 0
	ands r0, r1
	strb r0, [r2]
_0807F3B4:
	adds r6, 0x1
	cmp r6, 0x13
	ble _0807F39E
	movs r6, 0
_0807F3BC:
	ldr r0, _0807F41C
	ldr r0, [r0]
	lsls r1, r6, 2
	ldr r3, _0807F430
	adds r0, r3
	adds r0, r1
	ldr r5, [r0]
	adds r0, r5, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	beq _0807F3F4
	ldr r4, [r5, 0x70]
	movs r0, 0
	strb r0, [r4, 0x8]
	adds r0, r5, 0
	bl CalcSpeedStage
	adds r4, 0x60
	ldrb r1, [r4]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _0807F3F4
	movs r0, 0xFD
	ands r0, r1
	strb r0, [r4]
_0807F3F4:
	adds r6, 0x1
	cmp r6, 0x13
	ble _0807F3BC
	ldr r0, _0807F41C
	ldr r1, [r0]
	ldr r2, _0807F434
	adds r0, r1, r2
	movs r2, 0
	str r2, [r0]
	ldr r3, _0807F438
	adds r0, r1, r3
	str r2, [r0]
	movs r0, 0xD2
	lsls r0, 3
	adds r1, r0
	str r2, [r1]
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_0807F41C: .4byte gDungeon
_0807F420: .4byte 0x0000066e
_0807F424: .4byte 0x0000066f
_0807F428: .4byte gUnknown_80FE4B8
_0807F42C: .4byte gTeamInventoryRef
_0807F430: .4byte 0x000135cc
_0807F434: .4byte 0x00000694
_0807F438: .4byte 0x0000068c
	thumb_func_end sub_807F33C

	thumb_func_start sub_807F43C
sub_807F43C:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x10C
	str r0, [sp, 0xEC]
	mov r8, r1
	mov r0, r8
	movs r1, 0xE
	bl AbilityIsActive
	lsls r0, 24
	cmp r0, 0
	beq _0807F470
	ldr r0, _0807F468
	mov r1, r8
	movs r2, 0
	bl SubstitutePlaceholderStringTags
	ldr r0, _0807F46C
	b _0807F694
	.align 2, 0
_0807F468: .4byte gFormatBuffer_Monsters
_0807F46C: .4byte gUnknown_80FCB40
_0807F470:
	ldr r0, [sp, 0xEC]
	cmp r0, r8
	bne _0807F490
	ldr r0, _0807F488
	mov r1, r8
	movs r2, 0
	bl SubstitutePlaceholderStringTags
	ldr r0, _0807F48C
	ldr r2, [r0]
	mov r0, r8
	b _0807F698
	.align 2, 0
_0807F488: .4byte gFormatBuffer_Monsters
_0807F48C: .4byte gUnknown_80FCB70
_0807F490:
	mov r1, r8
	ldr r0, [r1, 0x4]
	add r1, sp, 0xD4
	str r0, [r1]
	movs r2, 0
	str r2, [sp, 0xF0]
_0807F49C:
	movs r3, 0
	mov r9, r3
	movs r7, 0
	mov r4, sp
	adds r4, 0x18
	str r4, [sp, 0x108]
_0807F4A8:
	ldr r0, _0807F504
	ldr r0, [r0]
	lsls r1, r7, 2
	ldr r2, _0807F508
	adds r0, r2
	adds r0, r1
	ldr r4, [r0]
	adds r0, r4, 0
	bl EntityExists
	lsls r0, 24
	adds r3, r7, 0x1
	str r3, [sp, 0x104]
	cmp r0, 0
	bne _0807F4C8
	b _0807F602
_0807F4C8:
	ldr r0, [sp, 0xEC]
	cmp r0, r4
	bne _0807F4D0
	b _0807F602
_0807F4D0:
	cmp r8, r4
	bne _0807F4D6
	b _0807F602
_0807F4D6:
	adds r1, r4, 0
	bl CanSeeTarget
	lsls r0, 24
	cmp r0, 0
	bne _0807F4E4
	b _0807F602
_0807F4E4:
	ldr r1, [sp, 0xF0]
	cmp r1, 0
	bne _0807F50C
	ldr r0, [sp, 0xEC]
	adds r1, r4, 0
	movs r2, 0
	movs r3, 0x1
	bl GetTreatmentBetweenMonsters
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	beq _0807F500
	b _0807F602
_0807F500:
	b _0807F51E
	.align 2, 0
_0807F504: .4byte gDungeon
_0807F508: .4byte 0x000135cc
_0807F50C:
	ldr r0, [sp, 0xEC]
	adds r1, r4, 0
	movs r2, 0
	movs r3, 0x1
	bl GetTreatmentBetweenMonsters
	lsls r0, 24
	cmp r0, 0
	bne _0807F602
_0807F51E:
	ldr r2, [sp, 0xF0]
	cmp r2, 0
	bne _0807F594
	movs r5, 0
	add r6, sp, 0xC8
	adds r3, r7, 0x1
	str r3, [sp, 0x104]
	adds r7, r6, 0
	ldr r0, _0807F588
	mov r10, r0
_0807F532:
	ldr r0, _0807F58C
	lsls r3, r5, 2
	adds r3, r0
	ldrh r0, [r4, 0x4]
	ldrh r1, [r3]
	adds r0, r1
	lsls r0, 16
	lsrs r0, 16
	ldr r1, [r6]
	mov r2, r10
	ands r1, r2
	orrs r1, r0
	str r1, [r7]
	ldrh r2, [r4, 0x6]
	ldrh r3, [r3, 0x2]
	adds r2, r3
	lsls r2, 16
	ldr r0, _0807F590
	ands r1, r0
	orrs r1, r2
	str r1, [r7]
	mov r0, r8
	add r1, sp, 0xC8
	bl sub_80703A0
	lsls r0, 24
	cmp r0, 0
	beq _0807F570
	adds r5, 0x1
	cmp r5, 0x7
	ble _0807F532
_0807F570:
	cmp r5, 0x8
	beq _0807F602
	mov r3, r9
	cmp r3, 0x27
	bgt _0807F602
	ldr r0, [r4, 0x4]
	ldr r4, [sp, 0x108]
	stm r4!, {r0}
	str r4, [sp, 0x108]
	movs r0, 0x1
	add r9, r0
	b _0807F602
	.align 2, 0
_0807F588: .4byte 0xffff0000
_0807F58C: .4byte gAdjacentTileOffsets
_0807F590: .4byte 0x0000ffff
_0807F594:
	movs r5, 0
	add r6, sp, 0xCC
	adds r1, r7, 0x1
	str r1, [sp, 0x104]
	adds r7, r6, 0
	mov r2, r9
	lsls r0, r2, 2
	add r0, sp
	adds r0, 0x18
	mov r10, r0
_0807F5A8:
	ldr r0, _0807F630
	lsls r3, r5, 2
	adds r3, r0
	ldrh r0, [r4, 0x4]
	ldrh r1, [r3]
	adds r0, r1
	lsls r0, 16
	lsrs r0, 16
	ldr r2, _0807F634
	ldr r1, [r6]
	ands r1, r2
	orrs r1, r0
	str r1, [r7]
	ldrh r2, [r4, 0x6]
	ldrh r3, [r3, 0x2]
	adds r2, r3
	lsls r2, 16
	ldr r0, _0807F638
	ands r1, r0
	orrs r1, r2
	str r1, [r7]
	mov r0, r8
	add r1, sp, 0xCC
	bl sub_80703A0
	lsls r0, 24
	cmp r0, 0
	bne _0807F5FC
	mov r2, r9
	cmp r2, 0x27
	bgt _0807F5FC
	ldr r0, [r6]
	mov r3, r10
	adds r3, 0x4
	mov r10, r3
	subs r3, 0x4
	stm r3!, {r0}
	ldr r0, [sp, 0x108]
	adds r0, 0x4
	str r0, [sp, 0x108]
	movs r1, 0x1
	add r9, r1
_0807F5FC:
	adds r5, 0x1
	cmp r5, 0x7
	ble _0807F5A8
_0807F602:
	ldr r7, [sp, 0x104]
	cmp r7, 0x13
	bgt _0807F60A
	b _0807F4A8
_0807F60A:
	mov r2, r9
	cmp r2, 0
	bne _0807F63C
	ldr r3, [sp, 0xF0]
	adds r3, 0x1
	str r3, [sp, 0xF0]
	cmp r3, 0x1
	bgt _0807F61C
	b _0807F49C
_0807F61C:
	ldr r0, [sp, 0xEC]
	adds r0, 0x4
	add r4, sp, 0xB8
	adds r1, r4, 0
	bl sub_80833E8
	movs r7, 0
	add r5, sp, 0xD0
	adds r6, r5, 0
	b _0807F654
	.align 2, 0
_0807F630: .4byte gAdjacentTileOffsets
_0807F634: .4byte 0xffff0000
_0807F638: .4byte 0x0000ffff
_0807F63C:
	mov r0, r9
	bl DungeonRandInt
	lsls r0, 2
	add r0, sp
	adds r0, 0x18
	ldr r0, [r0]
	str r0, [sp, 0xD4]
	b _0807F6A8
_0807F64E:
	ldr r0, [r5]
	str r0, [sp, 0xD4]
	b _0807F68E
_0807F654:
	ldr r0, [r4]
	ldr r1, [r4, 0x8]
	bl DungeonRandRange
	lsls r0, 16
	lsrs r0, 16
	ldr r2, _0807F6A0
	ldr r1, [r5]
	ands r1, r2
	orrs r1, r0
	str r1, [r6]
	ldr r0, [r4, 0x4]
	ldr r1, [r4, 0xC]
	bl DungeonRandRange
	lsls r0, 16
	ldrh r1, [r6]
	orrs r1, r0
	str r1, [r6]
	mov r0, r8
	add r1, sp, 0xD0
	bl sub_80703A0
	lsls r0, 24
	cmp r0, 0
	beq _0807F64E
	adds r7, 0x1
	cmp r7, 0x63
	ble _0807F654
_0807F68E:
	cmp r7, 0x64
	bne _0807F6A8
	ldr r0, _0807F6A4
_0807F694:
	ldr r2, [r0]
	ldr r0, [sp, 0xEC]
_0807F698:
	mov r1, r8
	bl TryDisplayDungeonLoggableMessage3
	b _0807F99C
	.align 2, 0
_0807F6A0: .4byte 0xffff0000
_0807F6A4: .4byte gUnknown_80FE6B4
_0807F6A8:
	ldr r0, _0807F860
	mov r1, r8
	movs r2, 0
	bl SubstitutePlaceholderStringTags
	ldr r0, _0807F864
	ldr r2, [r0]
	ldr r0, [sp, 0xEC]
	mov r1, r8
	bl TryDisplayDungeonLoggableMessage3
	mov r0, r8
	bl sub_8045888
	lsls r0, 24
	cmp r0, 0
	beq _0807F6D0
	ldr r0, _0807F868
	bl PlaySoundEffect
_0807F6D0:
	movs r4, 0
	str r4, [sp, 0x100]
	mov r1, r8
	ldr r0, [r1, 0x70]
	adds r0, 0x46
	ldrb r0, [r0]
	mov r9, r0
	add r2, sp, 0xD4
	movs r3, 0
	ldrsh r1, [r2, r3]
	mov r4, r8
	movs r3, 0x4
	ldrsh r0, [r4, r3]
	subs r3, r1, r0
	movs r4, 0x2
	ldrsh r1, [r2, r4]
	mov r2, r8
	movs r4, 0x6
	ldrsh r0, [r2, r4]
	subs r1, r0
	cmp r1, r3
	bge _0807F6FE
	adds r1, r3, 0
_0807F6FE:
	lsls r6, r1, 4
	cmp r6, 0x50
	ble _0807F706
	movs r6, 0x50
_0807F706:
	cmp r6, 0x9
	bgt _0807F70C
	movs r6, 0xA
_0807F70C:
	mov r1, r8
	adds r1, 0x4
	add r0, sp, 0xD4
	bl GetDirectionTowardsPosition
	adds r5, r0, 0
	add r2, sp, 0xD4
	movs r1, 0
	ldrsh r0, [r2, r1]
	lsls r4, r0, 1
	adds r4, r0
	lsls r4, 11
	movs r3, 0xC0
	lsls r3, 4
	adds r4, r3
	ldr r0, _0807F86C
	lsls r5, 2
	adds r5, r0
	movs r1, 0
	ldrsh r0, [r5, r1]
	lsls r0, 8
	movs r1, 0x3
	bl __divsi3
	adds r4, r0
	str r4, [sp, 0xF4]
	movs r3, 0xD6
	add r3, sp
	movs r2, 0
	ldrsh r0, [r3, r2]
	lsls r4, r0, 1
	adds r4, r0
	lsls r4, 11
	movs r0, 0x80
	lsls r0, 5
	adds r4, r0
	movs r1, 0x2
	ldrsh r0, [r5, r1]
	lsls r0, 8
	movs r1, 0x3
	bl __divsi3
	adds r4, r0
	str r4, [sp, 0xF8]
	mov r2, r8
	ldr r5, [r2, 0xC]
	ldr r3, [sp, 0xF4]
	subs r0, r3, r5
	adds r1, r6, 0
	bl __divsi3
	str r0, [sp, 0xFC]
	mov r0, r8
	ldr r4, [r0, 0x10]
	ldr r1, [sp, 0xF8]
	subs r0, r1, r4
	adds r1, r6, 0
	bl __divsi3
	mov r10, r0
	add r0, sp, 0xD8
	str r5, [r0]
	str r4, [r0, 0x4]
	movs r7, 0
	adds r5, r0, 0
	cmp r7, r6
	bge _0807F7FC
	adds r4, r5, 0
_0807F794:
	ldr r0, [r5]
	ldr r2, [sp, 0xFC]
	adds r0, r2, r0
	str r0, [r4]
	ldr r0, [r4, 0x4]
	add r0, r10
	str r0, [r4, 0x4]
	mov r0, r8
	adds r1, r4, 0
	bl sub_804535C
	mov r0, r8
	bl sub_8045888
	lsls r0, 24
	cmp r0, 0
	beq _0807F7E6
	ldr r0, [sp, 0x100]
	bl sin_4096
	lsls r0, 5
	mov r3, r8
	str r0, [r3, 0x1C]
	movs r0, 0x3B
	bl sub_803E46C
	movs r0, 0x3
	ands r0, r7
	cmp r0, 0
	bne _0807F7E6
	movs r0, 0x7
	mov r1, r9
	ands r1, r0
	mov r9, r1
	mov r0, r8
	movs r1, 0x6
	mov r2, r9
	bl sub_806CDD4
	movs r2, 0x1
	add r9, r2
_0807F7E6:
	movs r0, 0x80
	lsls r0, 4
	adds r1, r6, 0
	bl __divsi3
	ldr r3, [sp, 0x100]
	adds r3, r0
	str r3, [sp, 0x100]
	adds r7, 0x1
	cmp r7, r6
	blt _0807F794
_0807F7FC:
	ldr r4, [sp, 0xF4]
	str r4, [r5]
	add r1, sp, 0xD8
	ldr r0, [sp, 0xF8]
	str r0, [r1, 0x4]
	movs r0, 0
	mov r2, r8
	str r0, [r2, 0x1C]
	mov r0, r8
	bl sub_804535C
	movs r0, 0x3B
	bl sub_803E46C
	mov r3, r8
	ldr r0, [r3, 0x70]
	movs r1, 0x7
	mov r4, r9
	ands r4, r1
	adds r0, 0x46
	strb r4, [r0]
	add r2, sp, 0xD4
	movs r1, 0
	ldrsh r0, [r2, r1]
	adds r4, r2, 0
	movs r3, 0x2
	ldrsh r1, [r4, r3]
	bl GetTile
	ldr r6, [r0, 0x10]
	adds r0, r6, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	bne _0807F876
	add r2, sp, 0xD4
	movs r0, 0
	ldrsh r1, [r2, r0]
	movs r3, 0x2
	ldrsh r2, [r4, r3]
	mov r0, r8
	movs r3, 0x1
	bl sub_80694C0
	mov r0, r8
	bl sub_807F9BC
	b _0807F99C
	.align 2, 0
_0807F860: .4byte gFormatBuffer_Monsters
_0807F864: .4byte gUnknown_80FE690
_0807F868: .4byte 0x000001a3
_0807F86C: .4byte gAdjacentTileOffsets
_0807F870:
	ldr r0, [r7]
	str r0, [sp, 0xD4]
	b _0807F8BE
_0807F876:
	movs r5, 0
	add r4, sp, 0xE0
	adds r7, r4, 0
_0807F87C:
	ldr r0, _0807F8D0
	lsls r3, r5, 2
	adds r3, r0
	add r1, sp, 0xD4
	ldrh r0, [r1]
	ldrh r2, [r3]
	adds r0, r2
	lsls r0, 16
	lsrs r0, 16
	ldr r2, _0807F8D4
	ldr r1, [r7]
	ands r1, r2
	orrs r1, r0
	str r1, [r4]
	add r0, sp, 0xD4
	ldrh r2, [r0, 0x2]
	ldrh r3, [r3, 0x2]
	adds r2, r3
	lsls r2, 16
	ldr r0, _0807F8D8
	ands r1, r0
	orrs r1, r2
	str r1, [r4]
	mov r0, r8
	add r1, sp, 0xE0
	bl sub_80703A0
	lsls r0, 24
	cmp r0, 0
	beq _0807F870
	adds r5, 0x1
	cmp r5, 0x7
	ble _0807F87C
_0807F8BE:
	cmp r5, 0x8
	bne _0807F8DC
	ldr r0, [sp, 0xEC]
	mov r1, r8
	movs r2, 0
	movs r3, 0
	bl WarpTarget
	b _0807F8FA
	.align 2, 0
_0807F8D0: .4byte gAdjacentTileOffsets
_0807F8D4: .4byte 0xffff0000
_0807F8D8: .4byte 0x0000ffff
_0807F8DC:
	mov r0, r8
	add r1, sp, 0xD4
	bl sub_807D068
	add r0, sp, 0xD4
	movs r3, 0
	ldrsh r1, [r0, r3]
	movs r0, 0xD6
	add r0, sp
	movs r4, 0
	ldrsh r2, [r0, r4]
	mov r0, r8
	movs r3, 0x1
	bl sub_80694C0
_0807F8FA:
	adds r0, r6, 0
	bl GetEntityType
	cmp r0, 0x1
	bne _0807F954
	add r4, sp, 0xE4
	ldr r1, _0807F9AC
	adds r0, r4, 0
	bl InitPokemonMove
	adds r0, r6, 0
	adds r1, r4, 0
	bl sub_80571F0
	lsls r0, 24
	lsrs r1, r0, 24
	cmp r1, 0
	bne _0807F93C
	ldr r0, _0807F9B0
	movs r3, 0
	ldrsh r2, [r0, r3]
	str r1, [sp]
	str r1, [sp, 0x4]
	ldr r0, _0807F9B4
	str r0, [sp, 0x8]
	str r1, [sp, 0xC]
	str r1, [sp, 0x10]
	str r1, [sp, 0x14]
	ldr r0, [sp, 0xEC]
	adds r1, r6, 0
	movs r3, 0
	bl sub_806F370
_0807F93C:
	adds r0, r6, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	beq _0807F954
	ldr r0, [r6, 0x70]
	adds r0, 0x46
	ldrb r1, [r0]
	adds r0, r6, 0
	bl sub_806CE68
_0807F954:
	ldr r0, _0807F9B0
	movs r4, 0
	ldrsh r2, [r0, r4]
	movs r1, 0
	str r1, [sp]
	str r1, [sp, 0x4]
	ldr r0, _0807F9B8
	str r0, [sp, 0x8]
	str r1, [sp, 0xC]
	str r1, [sp, 0x10]
	str r1, [sp, 0x14]
	ldr r0, [sp, 0xEC]
	mov r1, r8
	movs r3, 0
	bl sub_806F370
	mov r0, r8
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	beq _0807F98E
	mov r1, r8
	ldr r0, [r1, 0x70]
	adds r0, 0x46
	ldrb r1, [r0]
	mov r0, r8
	bl sub_806CE68
_0807F98E:
	movs r0, 0x1E
	movs r1, 0x3B
	bl sub_803E708
	mov r0, r8
	bl sub_807F9BC
_0807F99C:
	add sp, 0x10C
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_0807F9AC: .4byte 0x00000163
_0807F9B0: .4byte gHurlOrbDmgValue
_0807F9B4: .4byte 0x0000021a
_0807F9B8: .4byte 0x00000219
	thumb_func_end sub_807F43C

	thumb_func_start sub_807F9BC
sub_807F9BC:
	push {r4,lr}
	adds r4, r0, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	beq _0807FA0A
	ldr r0, [r4, 0x70]
	ldrb r0, [r0, 0x7]
	cmp r0, 0
	beq _0807F9F4
	ldr r2, _0807FA10
	ldr r1, [r2]
	movs r0, 0
	strb r0, [r1, 0x1]
	ldr r0, [r2]
	movs r1, 0xB8
	lsls r1, 3
	adds r0, r1
	movs r1, 0x1
	negs r1, r1
	str r1, [r0]
	adds r0, r4, 0x4
	bl sub_804AC20
	movs r0, 0
	bl sub_807EC28
_0807F9F4:
	adds r0, r4, 0
	bl sub_806A5B8
	ldr r0, _0807FA10
	ldr r0, [r0]
	ldr r1, _0807FA14
	adds r0, r1
	ldrb r1, [r0]
	adds r0, r4, 0
	bl sub_8075900
_0807FA0A:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0807FA10: .4byte gDungeon
_0807FA14: .4byte 0x00003a08
	thumb_func_end sub_807F9BC

	thumb_func_start sub_807FA18
sub_807FA18:
	push {r4-r7,lr}
	sub sp, 0x4
	movs r6, 0
_0807FA1E:
	movs r5, 0
	adds r7, r6, 0x1
_0807FA22:
	adds r0, r5, 0
	adds r1, r6, 0
	bl GetTileMut
	adds r4, r0, 0
	ldrh r1, [r4, 0x4]
	movs r0, 0x4
	ands r0, r1
	cmp r0, 0
	beq _0807FA88
	lsls r0, r5, 16
	lsls r1, r6, 16
	lsrs r0, 16
	orrs r0, r1
	str r0, [sp]
	ldrh r1, [r4, 0x4]
	movs r0, 0x40
	ands r0, r1
	cmp r0, 0
	beq _0807FA4E
	movs r0, 0x6
	b _0807FA56
_0807FA4E:
	bl sub_803D6FC
	lsls r0, 24
	lsrs r0, 24
_0807FA56:
	cmp r0, 0x11
	bne _0807FA72
	movs r0, 0x11
	mov r1, sp
	movs r2, 0x2
	bl SpawnTrap
	cmp r0, 0
	beq _0807FA88
	str r0, [r4, 0x14]
	adds r1, r0, 0
	adds r1, 0x20
	movs r0, 0x1
	b _0807FA86
_0807FA72:
	mov r1, sp
	movs r2, 0
	bl SpawnTrap
	cmp r0, 0
	beq _0807FA88
	str r0, [r4, 0x14]
	adds r1, r0, 0
	adds r1, 0x20
	movs r0, 0
_0807FA86:
	strb r0, [r1]
_0807FA88:
	adds r5, 0x1
	cmp r5, 0x37
	ble _0807FA22
	adds r6, r7, 0
	cmp r6, 0x1F
	ble _0807FA1E
	add sp, 0x4
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_807FA18

	thumb_func_start sub_807FA9C
sub_807FA9C:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x8
	ldr r2, _0807FAC4
	ldr r0, [r2]
	ldr r3, _0807FAC8
	adds r1, r0, r3
	ldrb r1, [r1]
	str r1, [sp]
	ldr r1, _0807FACC
	adds r0, r1
	movs r3, 0
	ldrsh r0, [r0, r3]
	subs r1, r0, 0x5
	mov r8, r1
	b _0807FBFE
	.align 2, 0
_0807FAC4: .4byte gDungeon
_0807FAC8: .4byte 0x0001820f
_0807FACC: .4byte 0x000181ea
_0807FAD0:
	ldr r0, [r2]
	ldr r2, _0807FC18
	adds r0, r2
	movs r3, 0
	ldrsh r0, [r0, r3]
	subs r5, r0, 0x6
	adds r0, 0x6
	mov r1, r8
	adds r1, 0x1
	str r1, [sp, 0x4]
	cmp r5, r0
	blt _0807FAEA
	b _0807FBEE
_0807FAEA:
	ldr r7, _0807FC1C
	ldr r2, _0807FC20
	mov r10, r2
	lsls r0, r5, 1
	adds r0, r5
	lsls r0, 3
	mov r9, r0
_0807FAF8:
	movs r6, 0
	adds r0, r5, 0
	mov r1, r8
	bl GetTile
	adds r4, r0, 0
	ldr r0, [r4, 0x14]
	cmp r0, 0
	beq _0807FB24
	bl GetEntityType
	cmp r0, 0x2
	bne _0807FB24
	ldr r0, [r4, 0x14]
	adds r0, 0x20
	ldrb r0, [r0]
	cmp r0, 0
	bne _0807FB22
	ldr r3, [sp]
	cmp r3, 0
	beq _0807FB24
_0807FB22:
	movs r6, 0x1
_0807FB24:
	ldrh r0, [r4]
	movs r2, 0x80
	lsls r2, 2
	adds r1, r2, 0
	ands r0, r1
	cmp r0, 0
	beq _0807FB34
	movs r6, 0x1
_0807FB34:
	cmp r6, 0
	beq _0807FBD6
	ldr r0, _0807FC24
	ldr r1, [r0]
	ldr r3, _0807FC28
	adds r0, r1, r3
	movs r2, 0
	ldrsh r0, [r0, r2]
	mov r2, r9
	subs r3, r2, r0
	mov r2, r8
	lsls r0, r2, 1
	add r0, r8
	lsls r0, 3
	ldr r2, _0807FC2C
	adds r1, r2
	movs r2, 0
	ldrsh r1, [r1, r2]
	subs r2, r0, r1
	movs r0, 0x20
	negs r0, r0
	cmp r3, r0
	blt _0807FBD6
	cmp r2, r0
	blt _0807FBD6
	movs r0, 0x88
	lsls r0, 1
	cmp r3, r0
	bgt _0807FBD6
	cmp r2, 0xC0
	bgt _0807FBD6
	ldrh r1, [r7]
	mov r0, r10
	ands r0, r1
	strh r0, [r7]
	ldr r1, _0807FC30
	ands r1, r2
	lsls r1, 4
	ldrh r2, [r7, 0x6]
	movs r0, 0xF
	ands r0, r2
	orrs r0, r1
	strh r0, [r7, 0x6]
	ldr r0, _0807FC34
	ands r3, r0
	ldrh r0, [r7, 0x2]
	movs r2, 0xFE
	lsls r2, 8
	adds r1, r2, 0
	ands r0, r1
	orrs r0, r3
	strh r0, [r7, 0x2]
	ldrh r1, [r7, 0x4]
	mov r0, r10
	ands r0, r1
	movs r3, 0xC0
	lsls r3, 4
	orrs r0, r3
	movs r1, 0
	orrs r0, r1
	movs r1, 0xA0
	lsls r1, 8
	ldr r2, _0807FC30
	ands r0, r2
	orrs r0, r1
	movs r3, 0
	orrs r0, r3
	movs r2, 0xFE
	lsls r2, 1
	movs r3, 0xFC
	lsls r3, 8
	adds r1, r3, 0
	ands r0, r1
	orrs r0, r2
	strh r0, [r7, 0x4]
	adds r0, r7, 0
	movs r1, 0
	movs r2, 0
	movs r3, 0
	bl AddSprite
_0807FBD6:
	movs r0, 0x18
	add r9, r0
	adds r5, 0x1
	ldr r0, _0807FC24
	ldr r0, [r0]
	ldr r1, _0807FC18
	adds r0, r1
	movs r2, 0
	ldrsh r0, [r0, r2]
	adds r0, 0x6
	cmp r5, r0
	blt _0807FAF8
_0807FBEE:
	ldr r3, [sp, 0x4]
	mov r8, r3
	ldr r2, _0807FC24
	ldr r0, [r2]
	ldr r1, _0807FC38
	adds r0, r1
	movs r3, 0
	ldrsh r0, [r0, r3]
_0807FBFE:
	adds r0, 0x5
	cmp r8, r0
	bge _0807FC06
	b _0807FAD0
_0807FC06:
	add sp, 0x8
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_0807FC18: .4byte 0x000181e8
_0807FC1C: .4byte gUnknown_202EDC0
_0807FC20: .4byte 0x0000f3ff
_0807FC24: .4byte gDungeon
_0807FC28: .4byte 0x000181f0
_0807FC2C: .4byte 0x000181f2
_0807FC30: .4byte 0x00000fff
_0807FC34: .4byte 0x000001ff
_0807FC38: .4byte 0x000181ea
	thumb_func_end sub_807FA9C

	.align 2, 0
