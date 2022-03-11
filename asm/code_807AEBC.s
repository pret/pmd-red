	#include "asm/constants/gba_constants.inc"
  	#include "asm/macros.inc"

  	.syntax unified

  	.text
  
	thumb_func_start CanTakeItem
CanTakeItem:
	push {r4-r6,lr}
	adds r4, r0, 0
	ldr r5, [r4, 0x70]
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	beq _0807AF50
	adds r0, r4, 0
	bl CannotUseItems
	lsls r0, 24
	cmp r0, 0
	bne _0807AF50
	adds r0, r4, 0
	bl GetMapTileForDungeonEntity_2
	adds r6, r0, 0
	ldr r4, [r6, 0x14]
	cmp r4, 0
	beq _0807AF50
	adds r0, r4, 0
	bl GetEntityType
	cmp r0, 0x5
	bhi _0807AF50
	lsls r0, 2
	ldr r1, _0807AEFC
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0807AEFC: .4byte _0807AF00
	.align 2, 0
_0807AF00:
	.4byte _0807AF50
	.4byte _0807AF50
	.4byte _0807AF50
	.4byte _0807AF18
	.4byte _0807AF50
	.4byte _0807AF50
_0807AF18:
	ldrb r0, [r5, 0x7]
	cmp r0, 0
	bne _0807AF50
	adds r0, r5, 0
	adds r0, 0x60
	ldrb r1, [r0]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	bne _0807AF50
	ldrh r1, [r6]
	movs r0, 0x3
	ands r0, r1
	cmp r0, 0
	bne _0807AF3C
	ldrb r0, [r5, 0x6]
	cmp r0, 0
	bne _0807AF50
_0807AF3C:
	adds r0, r4, 0
	bl GetItemData
	ldrb r1, [r0]
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	bne _0807AF50
	movs r0, 0x1
	b _0807AF52
_0807AF50:
	movs r0, 0
_0807AF52:
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end CanTakeItem

	thumb_func_start ChooseTargetPosition
ChooseTargetPosition:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0xC
	mov r8, r0
	ldr r7, [r0, 0x70]
	bl TargetLeader
	lsls r0, 24
	cmp r0, 0
	beq _0807AF74
	b _0807B12C
_0807AF74:
	ldr r0, _0807AF8C
	ldr r1, [r0]
	ldr r2, _0807AF90
	adds r0, r1, r2
	ldrb r0, [r0]
	cmp r0, 0
	beq _0807AF98
	ldr r3, _0807AF94
	adds r6, r1, r3
	movs r4, 0x14
	mov r10, r4
	b _0807AFB4
	.align 2, 0
_0807AF8C: .4byte gDungeonGlobalData
_0807AF90: .4byte 0x000037fc
_0807AF94: .4byte 0x000135cc
_0807AF98:
	ldrb r0, [r7, 0x6]
	cmp r0, 0
	beq _0807AFAC
	ldr r0, _0807AFA8
	adds r6, r1, r0
	movs r1, 0x4
	mov r10, r1
	b _0807AFB4
	.align 2, 0
_0807AFA8: .4byte 0x0001357c
_0807AFAC:
	ldr r2, _0807B01C
	adds r6, r1, r2
	movs r3, 0x10
	mov r10, r3
_0807AFB4:
	mov r0, r8
	bl CanCrossWalls
	lsls r0, 24
	lsrs r0, 24
	str r0, [sp, 0x4]
	movs r4, 0x1
	negs r4, r4
	str r4, [sp]
	ldr r0, _0807B020
	mov r9, r0
	movs r5, 0
	adds r1, r7, 0
	adds r1, 0x78
	str r1, [sp, 0x8]
	cmp r5, r10
	bge _0807B09E
_0807AFD6:
	lsls r0, r5, 2
	adds r0, r6
	ldr r4, [r0]
	adds r0, r4, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	beq _0807B098
	ldr r0, [r4, 0x70]
	adds r1, r0, 0
	adds r1, 0xA4
	ldrb r1, [r1]
	adds r2, r0, 0
	cmp r1, 0
	bne _0807B098
	ldr r0, _0807B024
	ldr r0, [r0]
	ldr r3, _0807B028
	adds r0, r3
	ldrb r0, [r0]
	cmp r0, 0
	beq _0807B02C
	mov r0, r8
	adds r1, r4, 0
	movs r2, 0
	movs r3, 0x1
	bl CanTarget
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _0807B098
	ldr r2, [r4, 0x70]
	b _0807B03C
	.align 2, 0
_0807B01C: .4byte 0x0001358c
_0807B020: .4byte 0x000003e7
_0807B024: .4byte gDungeonGlobalData
_0807B028: .4byte 0x000037fc
_0807B02C:
	ldrb r0, [r7, 0x6]
	cmp r0, 0
	bne _0807B03C
	adds r0, r2, 0
	adds r0, 0xB0
	ldrb r0, [r0]
	cmp r0, 0x6
	beq _0807B098
_0807B03C:
	ldrb r0, [r2, 0x8]
	cmp r0, 0x1
	beq _0807B098
	ldr r0, [sp, 0x4]
	cmp r0, 0
	beq _0807B074
	mov r2, r8
	movs r3, 0x4
	ldrsh r1, [r2, r3]
	movs r2, 0x4
	ldrsh r0, [r4, r2]
	subs r1, r0
	cmp r1, 0
	bge _0807B05A
	negs r1, r1
_0807B05A:
	cmp r1, 0x5
	bgt _0807B074
	mov r3, r8
	movs r0, 0x6
	ldrsh r1, [r3, r0]
	movs r2, 0x6
	ldrsh r0, [r4, r2]
	subs r1, r0
	cmp r1, 0
	bge _0807B070
	negs r1, r1
_0807B070:
	cmp r1, 0x5
	ble _0807B082
_0807B074:
	mov r0, r8
	adds r1, r4, 0
	bl CanSee_2
	lsls r0, 24
	cmp r0, 0
	beq _0807B098
_0807B082:
	adds r1, r4, 0x4
	mov r0, r8
	adds r0, 0x4
	bl GetMaxPositionDifference
	cmp r9, r0
	ble _0807B098
	mov r9, r0
	str r5, [sp]
	cmp r0, 0x1
	ble _0807B09E
_0807B098:
	adds r5, 0x1
	cmp r5, r10
	blt _0807AFD6
_0807B09E:
	ldr r3, [sp]
	cmp r3, 0
	blt _0807B12C
	movs r2, 0
	movs r5, 0x1
	ldr r4, [sp, 0x8]
	strb r5, [r4]
	adds r1, r7, 0
	adds r1, 0x88
	lsls r0, r3, 2
	adds r4, r0, r6
	ldr r0, [r4]
	ldr r0, [r0, 0x4]
	str r0, [r1]
	subs r1, 0x8
	ldr r0, [r4]
	str r0, [r1]
	ldrh r1, [r0, 0x26]
	adds r0, r7, 0
	adds r0, 0x7C
	strh r1, [r0]
	subs r0, 0x2
	strb r5, [r0]
	movs r1, 0x8A
	lsls r1, 1
	adds r0, r7, r1
	str r2, [r0]
	mov r0, r8
	movs r1, 0x8
	bl HasTactic
	lsls r0, 24
	cmp r0, 0
	bne _0807B0E4
	b _0807B2C6
_0807B0E4:
	mov r0, r8
	bl CanSeeTeammate
	lsls r0, 24
	cmp r0, 0
	beq _0807B0F2
	b _0807B2C6
_0807B0F2:
	mov r2, r8
	movs r3, 0x4
	ldrsh r1, [r2, r3]
	ldr r2, [r4]
	movs r4, 0x4
	ldrsh r0, [r2, r4]
	subs r1, r0
	cmp r1, 0
	bge _0807B106
	negs r1, r1
_0807B106:
	cmp r1, 0x1
	ble _0807B10C
	b _0807B2C6
_0807B10C:
	mov r0, r8
	movs r3, 0x6
	ldrsh r1, [r0, r3]
	movs r4, 0x6
	ldrsh r0, [r2, r4]
	subs r0, r1, r0
	cmp r0, 0
	bge _0807B11E
	negs r0, r0
_0807B11E:
	cmp r0, 0x1
	ble _0807B124
	b _0807B2C6
_0807B124:
	adds r0, r7, 0
	adds r0, 0x7B
	strb r5, [r0]
	b _0807B2C6
_0807B12C:
	mov r0, r8
	movs r1, 0x1
	bl HasTactic
	lsls r0, 24
	cmp r0, 0
	bne _0807B17C
	ldrb r5, [r7, 0x6]
	adds r0, r7, 0
	adds r0, 0x78
	str r0, [sp, 0x8]
	cmp r5, 0
	bne _0807B222
	mov r0, r8
	bl GetLeaderEntityIfVisible
	adds r4, r0, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	beq _0807B222
	movs r0, 0x1
	ldr r1, [sp, 0x8]
	strb r0, [r1]
	adds r1, r7, 0
	adds r1, 0x88
	ldr r0, [r4, 0x4]
	str r0, [r1]
	adds r0, r7, 0
	adds r0, 0x80
	str r4, [r0]
	ldrh r1, [r4, 0x26]
	subs r0, 0x4
	strh r1, [r0]
	movs r2, 0x8A
	lsls r2, 1
	adds r0, r7, r2
	str r5, [r0]
	b _0807B2C6
_0807B17C:
	ldrb r0, [r7, 0x7]
	adds r3, r7, 0
	adds r3, 0x78
	str r3, [sp, 0x8]
	cmp r0, 0
	beq _0807B222
	ldr r4, _0807B1BC
	ldr r0, [r4]
	ldr r1, _0807B1C0
	adds r0, r1
	ldrb r0, [r0]
	mov r2, r8
	movs r3, 0x4
	ldrsh r0, [r2, r3]
	movs r3, 0x6
	ldrsh r1, [r2, r3]
	bl GetMapTile_1
	ldrb r1, [r0, 0x9]
	cmp r1, 0xFF
	bne _0807B1C4
	mov r4, r8
	movs r0, 0x4
	ldrsh r1, [r4, r0]
	subs r2, r1, 0x2
	mov r10, r2
	movs r3, 0x6
	ldrsh r0, [r4, r3]
	subs r2, r0, 0x2
	adds r6, r1, 0x2
	adds r0, 0x2
	b _0807B1EC
	.align 2, 0
_0807B1BC: .4byte gDungeonGlobalData
_0807B1C0: .4byte 0x00018209
_0807B1C4:
	lsls r0, r1, 3
	subs r0, r1
	lsls r0, 2
	ldr r1, _0807B26C
	adds r0, r1
	ldr r1, [r4]
	adds r1, r0
	movs r2, 0x2
	ldrsh r0, [r1, r2]
	subs r0, 0x1
	mov r10, r0
	movs r3, 0x4
	ldrsh r0, [r1, r3]
	subs r2, r0, 0x1
	movs r4, 0x6
	ldrsh r0, [r1, r4]
	adds r6, r0, 0x1
	movs r3, 0x8
	ldrsh r0, [r1, r3]
	adds r0, 0x1
_0807B1EC:
	mov r9, r0
	adds r5, r2, 0
	adds r4, r7, 0
	adds r4, 0x78
	str r4, [sp, 0x8]
	cmp r5, r9
	bgt _0807B222
_0807B1FA:
	mov r4, r10
	cmp r4, r6
	bgt _0807B21C
_0807B200:
	adds r0, r4, 0
	adds r1, r5, 0
	bl GetMapTile_2
	ldr r0, [r0, 0x14]
	cmp r0, 0
	beq _0807B216
	bl GetEntityType
	cmp r0, 0x3
	beq _0807B270
_0807B216:
	adds r4, 0x1
	cmp r4, r6
	ble _0807B200
_0807B21C:
	adds r5, 0x1
	cmp r5, r9
	ble _0807B1FA
_0807B222:
	ldr r1, [sp, 0x8]
	ldrb r0, [r1]
	subs r0, 0x1
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bhi _0807B2C0
	adds r3, r7, 0
	adds r3, 0x80
	ldr r1, [r3]
	cmp r1, 0
	beq _0807B2C0
	adds r2, r7, 0
	adds r2, 0x7C
	ldrh r0, [r1, 0x26]
	ldrh r4, [r2]
	cmp r0, r4
	bne _0807B2B4
	ldr r1, [r1, 0x70]
	mov r9, r1
	movs r5, 0
	mov r4, r9
	adds r4, 0x68
_0807B250:
	lsls r6, r5, 2
	mov r0, r8
	adds r1, r4, 0
	bl InSameRoom
	lsls r0, 24
	cmp r0, 0
	bne _0807B294
	adds r4, 0x4
	adds r5, 0x1
	cmp r5, 0x3
	ble _0807B250
	b _0807B2C0
	.align 2, 0
_0807B26C: .4byte 0x000104c4
_0807B270:
	movs r1, 0
	movs r0, 0x7
	ldr r2, [sp, 0x8]
	strb r0, [r2]
	adds r0, r7, 0
	adds r0, 0x88
	strh r4, [r0]
	adds r0, 0x2
	strh r5, [r0]
	subs r0, 0xA
	str r1, [r0]
	subs r0, 0x4
	strh r1, [r0]
	movs r3, 0x8A
	lsls r3, 1
	adds r0, r7, r3
	str r1, [r0]
	b _0807B2C6
_0807B294:
	movs r2, 0
	movs r0, 0x2
	ldr r4, [sp, 0x8]
	strb r0, [r4]
	adds r1, r7, 0
	adds r1, 0x88
	mov r0, r9
	adds r0, 0x68
	adds r0, r6
	ldr r0, [r0]
	str r0, [r1]
	movs r1, 0x8A
	lsls r1, 1
	adds r0, r7, r1
	str r2, [r0]
	b _0807B2C6
_0807B2B4:
	movs r1, 0
	movs r0, 0x6
	ldr r4, [sp, 0x8]
	strb r0, [r4]
	str r1, [r3]
	strh r1, [r2]
_0807B2C0:
	mov r0, r8
	bl Explore
_0807B2C6:
	movs r0, 0x1
	add sp, 0xC
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end ChooseTargetPosition

	thumb_func_start DecideMovement
DecideMovement:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x3C
	mov r9, r0
	lsls r1, 24
	lsrs r7, r1, 24
	ldr r5, [r0, 0x70]
	movs r0, 0xB6
	lsls r0, 1
	adds r1, r5, r0
	adds r4, r5, 0
	adds r4, 0x88
	ldr r0, [r4]
	str r0, [r1]
	mov r2, r9
	ldr r1, [r2, 0x4]
	ldr r0, [r4]
	cmp r1, r0
	beq _0807B348
	mov r6, r9
	adds r6, 0x4
	adds r0, r6, 0
	adds r1, r4, 0
	bl CalculateFacingDir
	mov r8, r0
	adds r0, r5, 0
	adds r0, 0x7A
	ldrb r1, [r0]
	mov r0, r9
	bl ShouldAvoidFirstHit
	lsls r0, 24
	cmp r0, 0
	beq _0807B366
	adds r0, r5, 0
	adds r0, 0x78
	ldrb r0, [r0]
	cmp r0, 0x1
	bne _0807B37C
	adds r0, r6, 0
	adds r1, r4, 0
	bl IsTargetTwoTilesAway
	lsls r0, 24
	cmp r0, 0
	beq _0807B37C
	adds r0, r6, 0
	adds r1, r4, 0
	bl GetMaxPositionDifference
	cmp r0, 0x2
	bne _0807B354
_0807B348:
	adds r0, r5, 0
	adds r0, 0x44
	movs r1, 0x1
	bl SetAction
	b _0807B5CE
_0807B354:
	cmp r0, 0x1
	bgt _0807B37C
	movs r3, 0x4
	add r8, r3
	movs r0, 0x7
	mov r1, r8
	ands r1, r0
	mov r8, r1
	b _0807B37C
_0807B366:
	adds r0, r5, 0
	adds r0, 0x7B
	ldrb r0, [r0]
	cmp r0, 0
	beq _0807B37C
	movs r2, 0x4
	add r8, r2
	movs r0, 0x7
	mov r3, r8
	ands r3, r0
	mov r8, r3
_0807B37C:
	add r4, sp, 0x30
	mov r0, r9
	mov r1, r8
	adds r2, r4, 0
	bl CanMoveForward
	lsls r0, 24
	cmp r0, 0
	beq _0807B3A8
	adds r0, r5, 0
	adds r0, 0x44
	movs r2, 0x2
	ldrsh r1, [r5, r2]
	bl SetWalkAction
	movs r0, 0x7
	mov r3, r8
	ands r3, r0
	adds r0, r5, 0
	adds r0, 0x46
	strb r3, [r0]
	b _0807B5CE
_0807B3A8:
	ldrb r0, [r4]
	cmp r0, 0
	beq _0807B444
	ldrb r0, [r5, 0x6]
	cmp r0, 0
	bne _0807B3E8
	ldr r1, _0807B3E0
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, 0
	bne _0807B3E8
	adds r0, r5, 0
	adds r0, 0x79
	movs r4, 0x1
	strb r4, [r0]
	movs r2, 0xA2
	lsls r2, 1
	adds r0, r5, r2
	strb r4, [r0]
	adds r0, r5, 0
	adds r0, 0x44
	movs r1, 0x1
	bl SetAction
	ldr r3, _0807B3E4
	adds r0, r5, r3
	strb r4, [r0]
	b _0807B5CE
	.align 2, 0
_0807B3E0: .4byte 0x00000145
_0807B3E4: .4byte 0x00000147
_0807B3E8:
	mov r0, r9
	movs r2, 0x4
	ldrsh r1, [r0, r2]
	ldr r2, _0807B434
	mov r3, r8
	lsls r0, r3, 2
	adds r2, r0, r2
	movs r3, 0
	ldrsh r0, [r2, r3]
	adds r1, r0
	adds r0, r5, 0
	adds r0, 0x88
	movs r3, 0
	ldrsh r0, [r0, r3]
	cmp r1, r0
	bne _0807B43C
	mov r1, r9
	movs r3, 0x6
	ldrsh r0, [r1, r3]
	movs r3, 0x2
	ldrsh r1, [r2, r3]
	adds r0, r1
	adds r1, r5, 0
	adds r1, 0x8A
	movs r2, 0
	ldrsh r1, [r1, r2]
	cmp r0, r1
	bne _0807B43C
	adds r0, r5, 0
	adds r0, 0x44
	movs r1, 0x1
	bl SetAction
	ldr r3, _0807B438
	adds r1, r5, r3
	movs r0, 0x1
	strb r0, [r1]
	b _0807B5CE
	.align 2, 0
_0807B434: .4byte gAdjacentTileOffsets
_0807B438: .4byte 0x00000147
_0807B43C:
	adds r1, r5, 0
	adds r1, 0x79
	movs r0, 0x1
	strb r0, [r1]
_0807B444:
	mov r3, sp
	mov r2, sp
	mov r1, sp
	add r0, sp, 0x28
	movs r4, 0x1
	strb r4, [r0]
	add r0, sp, 0x20
	strb r4, [r0]
	strb r4, [r1, 0x18]
	strb r4, [r2, 0x10]
	strb r4, [r3, 0x8]
	ldrb r6, [r5, 0x6]
	cmp r6, 0
	bne _0807B4C8
	mov r0, r8
	ands r0, r4
	cmp r0, 0
	beq _0807B4C8
	mov r1, r9
	movs r2, 0x4
	ldrsh r0, [r1, r2]
	adds r1, r5, 0
	adds r1, 0x88
	movs r3, 0
	ldrsh r1, [r1, r3]
	subs r2, r0, r1
	cmp r2, 0
	bge _0807B47E
	negs r2, r2
_0807B47E:
	mov r0, r9
	movs r3, 0x6
	ldrsh r1, [r0, r3]
	adds r0, r5, 0
	adds r0, 0x8A
	movs r3, 0
	ldrsh r0, [r0, r3]
	subs r1, r0
	cmp r1, 0
	bge _0807B494
	negs r1, r1
_0807B494:
	cmp r2, 0x2
	bgt _0807B4C8
	cmp r1, 0x2
	bgt _0807B4C8
	cmp r2, r1
	beq _0807B4C8
	movs r3, 0x2
	mov r0, r8
	ands r3, r0
	cmp r3, 0
	beq _0807B4BA
	cmp r2, r1
	bge _0807B4B4
	mov r0, sp
	strb r6, [r0, 0x10]
	b _0807B4C8
_0807B4B4:
	mov r0, sp
	strb r6, [r0, 0x8]
	b _0807B4C8
_0807B4BA:
	cmp r2, r1
	bge _0807B4C4
	mov r0, sp
	strb r3, [r0, 0x8]
	b _0807B4C8
_0807B4C4:
	mov r0, sp
	strb r3, [r0, 0x10]
_0807B4C8:
	movs r1, 0x3
	mov r10, r1
	mov r0, r9
	adds r1, r7, 0
	bl ShouldAvoidEnemiesAndShowEffect
	lsls r0, 24
	cmp r0, 0
	bne _0807B4E4
	adds r0, r5, 0
	adds r0, 0x7B
	ldrb r0, [r0]
	cmp r0, 0
	beq _0807B4E8
_0807B4E4:
	movs r2, 0x5
	mov r10, r2
_0807B4E8:
	movs r6, 0x1
	adds r3, r5, 0
	adds r3, 0x44
	str r3, [sp, 0x34]
	cmp r6, r10
	bge _0807B53C
	mov r3, sp
	mov r4, sp
	adds r4, 0xA
	add r7, sp, 0x8
_0807B4FC:
	lsls r0, r6, 3
	add r2, sp, 0x4
	adds r2, r0
	ldr r1, _0807B598
	lsls r0, r6, 2
	adds r0, r1
	ldr r1, [r0]
	add r1, r8
	movs r0, 0x7
	ands r1, r0
	str r1, [r2]
	mov r0, r9
	adds r2, r4, 0
	str r3, [sp, 0x38]
	bl CanMoveForward
	strb r0, [r7, 0x1]
	lsls r0, 24
	ldr r3, [sp, 0x38]
	cmp r0, 0
	bne _0807B532
	ldrb r0, [r4]
	cmp r0, 0
	bne _0807B532
	movs r0, 0x1
	strb r0, [r3, 0x10]
	strb r0, [r3, 0x8]
_0807B532:
	adds r4, 0x8
	adds r7, 0x8
	adds r6, 0x1
	cmp r6, r10
	blt _0807B4FC
_0807B53C:
	movs r6, 0x1
	cmp r6, r10
	bge _0807B56E
	adds r3, r5, 0
	adds r3, 0x79
	add r1, sp, 0x8
	movs r4, 0x8
	movs r7, 0x1
_0807B54C:
	adds r2, r4, 0
	ldrb r0, [r1, 0x1]
	cmp r0, 0
	beq _0807B55A
	ldrb r0, [r1]
	cmp r0, 0
	bne _0807B5A0
_0807B55A:
	ldrb r0, [r1, 0x2]
	cmp r0, 0
	beq _0807B562
	strb r7, [r3]
_0807B562:
	adds r1, 0x8
	adds r4, r2, 0
	adds r4, 0x8
	adds r6, 0x1
	cmp r6, r10
	blt _0807B54C
_0807B56E:
	ldr r0, [sp, 0x34]
	movs r1, 0x1
	bl SetAction
	ldr r1, _0807B59C
	adds r0, r5, r1
	movs r1, 0
	movs r2, 0x1
	strb r2, [r0]
	ldrb r0, [r5, 0x7]
	cmp r0, 0
	beq _0807B5BC
	adds r0, r5, 0
	adds r0, 0x79
	strb r1, [r0]
	movs r2, 0xA2
	lsls r2, 1
	adds r0, r5, r2
	strb r1, [r0]
	b _0807B5CE
	.align 2, 0
_0807B598: .4byte gFaceDirectionIncrements
_0807B59C: .4byte 0x00000147
_0807B5A0:
	movs r3, 0x2
	ldrsh r1, [r5, r3]
	ldr r0, [sp, 0x34]
	bl SetWalkAction
	add r0, sp, 0x4
	adds r0, r4
	ldr r0, [r0]
	movs r1, 0x7
	ands r0, r1
	adds r1, r5, 0
	adds r1, 0x46
	strb r0, [r1]
	b _0807B5CE
_0807B5BC:
	adds r0, r5, 0
	adds r0, 0x79
	ldrb r0, [r0]
	cmp r0, 0
	beq _0807B5CE
	movs r1, 0xA2
	lsls r1, 1
	adds r0, r5, r1
	strb r2, [r0]
_0807B5CE:
	add sp, 0x3C
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end DecideMovement

	thumb_func_start AvoidEnemies
AvoidEnemies:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x30
	adds r7, r0, 0
	ldr r0, _0807B61C
	str r0, [sp, 0x8]
	ldr r1, [r7, 0x70]
	str r1, [sp, 0x10]
	adds r0, r7, 0
	bl GetEntityRoomIndex
	lsls r0, 24
	lsrs r0, 24
	mov r10, r0
	ldr r0, _0807B620
	ldr r1, [r0]
	ldr r2, _0807B624
	adds r0, r1, r2
	ldrb r0, [r0]
	cmp r0, 0
	beq _0807B62C
	ldr r3, _0807B628
	adds r0, r1, r3
	movs r4, 0x14
	mov r9, r4
	b _0807B64C
	.align 2, 0
_0807B61C: .4byte 0x000f423f
_0807B620: .4byte gDungeonGlobalData
_0807B624: .4byte 0x000037fc
_0807B628: .4byte 0x000135cc
_0807B62C:
	ldr r2, [sp, 0x10]
	ldrb r0, [r2, 0x6]
	cmp r0, 0
	beq _0807B644
	ldr r3, _0807B640
	adds r0, r1, r3
	movs r4, 0x4
	mov r9, r4
	b _0807B64C
	.align 2, 0
_0807B640: .4byte 0x0001357c
_0807B644:
	ldr r2, _0807B790
	adds r0, r1, r2
	movs r3, 0x10
	mov r9, r3
_0807B64C:
	movs r4, 0
	str r4, [sp, 0xC]
	movs r1, 0xFF
	str r1, [sp, 0x4]
	mov r8, r4
	cmp r4, r9
	bge _0807B6D8
	adds r6, r0, 0
_0807B65C:
	ldr r4, [r6]
	adds r0, r4, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	beq _0807B6CE
	adds r0, r7, 0
	adds r1, r4, 0
	bl CanSee
	lsls r0, 24
	cmp r0, 0
	beq _0807B6CE
	ldr r0, _0807B794
	ldr r0, [r0]
	ldr r2, _0807B798
	adds r0, r2
	ldrb r0, [r0]
	cmp r0, 0
	beq _0807B69A
	adds r0, r7, 0
	adds r1, r4, 0
	movs r2, 0
	movs r3, 0x1
	bl CanTarget
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _0807B6CE
_0807B69A:
	adds r1, r4, 0x4
	adds r0, r7, 0x4
	bl GetMaxPositionDifference
	ldr r3, [sp, 0x8]
	cmp r3, r0
	ble _0807B6CE
	str r0, [sp, 0x8]
	str r4, [sp, 0xC]
	adds r0, r4, 0
	bl GetEntityRoomIndex
	lsls r0, 24
	lsrs r0, 24
	str r0, [sp, 0x4]
	ldr r1, [sp, 0x10]
	adds r1, 0x88
	ldr r4, [sp, 0xC]
	ldr r0, [r4, 0x4]
	str r0, [r1]
	ldr r0, [sp, 0x10]
	movs r2, 0xB6
	lsls r2, 1
	adds r1, r0, r2
	ldr r0, [r4, 0x4]
	str r0, [r1]
_0807B6CE:
	adds r6, 0x4
	movs r3, 0x1
	add r8, r3
	cmp r8, r9
	blt _0807B65C
_0807B6D8:
	ldr r0, _0807B79C
	ldr r4, [sp, 0x8]
	cmp r4, r0
	bne _0807B6E2
	b _0807B906
_0807B6E2:
	ldr r0, [sp, 0x10]
	adds r0, 0x88
	str r0, [sp, 0x28]
	ldr r1, [sp, 0x10]
	adds r1, 0x78
	str r1, [sp, 0x24]
	ldr r2, [sp, 0x4]
	cmp r10, r2
	beq _0807B6F6
	b _0807B8E0
_0807B6F6:
	mov r3, r10
	cmp r3, 0xFF
	bne _0807B6FE
	b _0807B8E0
_0807B6FE:
	movs r4, 0x4
	ldrsh r0, [r7, r4]
	movs r2, 0x6
	ldrsh r1, [r7, r2]
	bl GetMapTile_1
	ldrh r1, [r0]
	movs r0, 0x8
	ands r0, r1
	cmp r0, 0
	beq _0807B7B2
	ldrh r0, [r7, 0x6]
	lsls r0, 16
	ldrh r5, [r7, 0x4]
	orrs r5, r0
	movs r4, 0
_0807B71E:
	ldr r1, _0807B7A0
	lsls r0, r4, 2
	adds r0, r1
	ldrh r1, [r0]
	ldrh r3, [r7, 0x4]
	adds r1, r3
	lsls r1, 16
	ldrh r0, [r0, 0x2]
	ldrh r2, [r7, 0x6]
	adds r0, r2
	lsls r0, 16
	lsrs r5, r1, 16
	orrs r5, r0
	lsls r0, r5, 16
	asrs r0, 16
	asrs r1, r5, 16
	bl GetMapTile_1
	ldrb r0, [r0, 0x9]
	cmp r0, r10
	beq _0807B758
	adds r0, r7, 0
	adds r1, r4, 0
	mov r2, sp
	bl CanMoveForward
	lsls r0, 24
	cmp r0, 0
	bne _0807B75E
_0807B758:
	adds r4, 0x1
	cmp r4, 0x7
	ble _0807B71E
_0807B75E:
	cmp r4, 0x8
	bne _0807B7A4
	movs r0, 0x8
	bl DungeonRandomCapped
	adds r4, r0, 0
	movs r0, 0x6
	ldr r3, [sp, 0x24]
	strb r0, [r3]
	ldr r0, _0807B7A0
	lsls r1, r4, 2
	adds r1, r0
	ldrh r0, [r1]
	ldrh r4, [r7, 0x4]
	adds r0, r4
	ldr r2, [sp, 0x28]
	strh r0, [r2]
	ldrh r0, [r1, 0x2]
	ldrh r7, [r7, 0x6]
	adds r0, r7
	ldr r1, [sp, 0x10]
	adds r1, 0x8A
	strh r0, [r1]
	movs r0, 0x1
	b _0807B910
	.align 2, 0
_0807B790: .4byte 0x0001358c
_0807B794: .4byte gDungeonGlobalData
_0807B798: .4byte 0x000037fc
_0807B79C: .4byte 0x000f423f
_0807B7A0: .4byte gAdjacentTileOffsets
_0807B7A4:
	movs r0, 0x5
	ldr r3, [sp, 0x24]
	strb r0, [r3]
	ldr r4, [sp, 0x28]
	str r5, [r4]
	movs r0, 0x1
	b _0807B910
_0807B7B2:
	ldr r0, _0807B8D0
	mov r2, r10
	lsls r1, r2, 7
	ldr r3, _0807B8D4
	adds r1, r3
	ldr r0, [r0]
	adds r1, r0, r1
	str r1, [sp, 0x18]
	lsls r1, r2, 1
	ldr r4, _0807B8D8
	adds r0, r4
	adds r0, r1
	movs r2, 0
	ldrsh r1, [r0, r2]
	str r1, [sp, 0x14]
	ldr r3, _0807B8DC
	str r3, [sp, 0x20]
	movs r4, 0
	str r4, [sp, 0x1C]
	ldr r0, [sp, 0xC]
	movs r1, 0x4
	ldrsh r3, [r0, r1]
	movs r2, 0x4
	ldrsh r0, [r7, r2]
	subs r2, r3, r0
	cmp r2, 0
	bge _0807B7EA
	negs r2, r2
_0807B7EA:
	ldr r4, [sp, 0xC]
	movs r0, 0x6
	ldrsh r1, [r4, r0]
	movs r4, 0x6
	ldrsh r0, [r7, r4]
	subs r1, r0
	mov r8, r1
	cmp r1, 0
	bge _0807B802
	mov r0, r8
	negs r0, r0
	mov r8, r0
_0807B802:
	cmp r8, r2
	bge _0807B808
	mov r8, r2
_0807B808:
	movs r1, 0
	mov r9, r1
	ldr r2, [sp, 0x10]
	adds r2, 0x8A
	str r2, [sp, 0x2C]
	ldr r4, [sp, 0x1C]
	ldr r0, [sp, 0x14]
	cmp r4, r0
	bge _0807B8AA
	mov r10, r3
	ldr r6, [sp, 0x18]
_0807B81E:
	movs r1, 0
	ldrsh r3, [r6, r1]
	mov r2, r10
	subs r0, r2, r3
	cmp r0, 0
	bge _0807B82C
	negs r0, r0
_0807B82C:
	ldr r4, [sp, 0xC]
	movs r1, 0x6
	ldrsh r4, [r4, r1]
	mov r12, r4
	movs r4, 0x2
	ldrsh r2, [r6, r4]
	mov r4, r12
	subs r1, r4, r2
	cmp r1, 0
	bge _0807B842
	negs r1, r1
_0807B842:
	cmp r1, r0
	bge _0807B848
	adds r1, r0, 0
_0807B848:
	movs r0, 0x4
	ldrsh r4, [r7, r0]
	subs r0, r3, r4
	movs r3, 0x6
	ldrsh r5, [r7, r3]
	subs r3, r2, r5
	movs r2, 0x1
	negs r2, r2
	cmp r0, r2
	bge _0807B85E
	adds r0, r2, 0
_0807B85E:
	cmp r3, r2
	bge _0807B864
	adds r3, r2, 0
_0807B864:
	cmp r0, 0x1
	ble _0807B86A
	movs r0, 0x1
_0807B86A:
	cmp r3, 0x1
	ble _0807B870
	movs r3, 0x1
_0807B870:
	adds r0, r4, r0
	mov r4, r10
	subs r2, r4, r0
	cmp r2, 0
	bge _0807B87C
	negs r2, r2
_0807B87C:
	adds r0, r5, r3
	mov r3, r12
	subs r0, r3, r0
	cmp r0, 0
	bge _0807B888
	negs r0, r0
_0807B888:
	cmp r0, r2
	bge _0807B88E
	adds r0, r2, 0
_0807B88E:
	cmp r0, r8
	blt _0807B89E
	ldr r4, [sp, 0x20]
	cmp r4, r1
	bge _0807B89E
	mov r0, r9
	str r0, [sp, 0x1C]
	str r1, [sp, 0x20]
_0807B89E:
	adds r6, 0x4
	movs r1, 0x1
	add r9, r1
	ldr r2, [sp, 0x14]
	cmp r9, r2
	blt _0807B81E
_0807B8AA:
	ldr r3, [sp, 0x20]
	cmp r3, 0
	blt _0807B8E0
	movs r0, 0x5
	ldr r4, [sp, 0x24]
	strb r0, [r4]
	ldr r1, [sp, 0x1C]
	lsls r0, r1, 2
	ldr r2, [sp, 0x18]
	adds r0, r2
	ldrh r1, [r0]
	ldr r3, [sp, 0x28]
	strh r1, [r3]
	ldrh r0, [r0, 0x2]
	ldr r4, [sp, 0x2C]
	strh r0, [r4]
	movs r0, 0x1
	b _0807B910
	.align 2, 0
_0807B8D0: .4byte gDungeonGlobalData
_0807B8D4: .4byte 0x00010884
_0807B8D8: .4byte 0x00010844
_0807B8DC: .4byte 0xfff0bdc1
_0807B8E0:
	movs r0, 0x5
	ldr r1, [sp, 0x24]
	strb r0, [r1]
	ldr r2, [sp, 0xC]
	ldrh r1, [r2, 0x4]
	ldrh r0, [r7, 0x4]
	subs r1, r0
	subs r0, r1
	ldr r3, [sp, 0x28]
	strh r0, [r3]
	ldrh r0, [r2, 0x6]
	ldrh r1, [r7, 0x6]
	subs r0, r1
	subs r1, r0
	ldr r0, [sp, 0x10]
	adds r0, 0x8A
	strh r1, [r0]
	movs r0, 0x1
	b _0807B910
_0807B906:
	adds r0, r7, 0
	bl Explore
	lsls r0, 24
	lsrs r0, 24
_0807B910:
	add sp, 0x30
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end AvoidEnemies

	thumb_func_start Explore
Explore:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x10
	adds r6, r0, 0
	ldr r7, [r6, 0x70]
	bl GetEntityRoomIndex
	lsls r0, 24
	lsrs r3, r0, 24
	cmp r3, 0xFF
	bne _0807B9DC
	movs r0, 0
	str r0, [sp, 0x4]
	adds r4, r7, 0
	adds r4, 0x46
	ldrb r0, [r4]
	adds r0, 0x4
	mov r8, r0
	movs r0, 0x7
	mov r1, r8
	ands r1, r0
	mov r8, r1
	adds r0, r6, 0
	bl IsAtJunction
	lsls r0, 24
	mov r9, r4
	cmp r0, 0
	beq _0807B96C
	movs r0, 0x8
	bl DungeonRandomCapped
	strb r0, [r4]
	movs r2, 0x1
	str r2, [sp, 0x4]
_0807B96C:
	movs r3, 0
	movs r4, 0x78
	adds r4, r7
	mov r10, r4
	adds r0, r7, 0
	adds r0, 0x88
	str r0, [sp, 0x8]
	adds r7, 0x8A
	ldr r5, _0807B9D4
_0807B97E:
	mov r1, r9
	ldrb r0, [r1]
	ldr r1, [r5]
	adds r4, r0, r1
	movs r0, 0x7
	ands r4, r0
	ldr r2, [sp, 0x4]
	cmp r2, 0
	beq _0807B994
	cmp r4, r8
	beq _0807B9AA
_0807B994:
	adds r0, r6, 0
	adds r1, r4, 0
	mov r2, sp
	str r3, [sp, 0xC]
	bl CanMoveForward
	lsls r0, 24
	ldr r3, [sp, 0xC]
	cmp r0, 0
	beq _0807B9AA
	b _0807BB42
_0807B9AA:
	adds r5, 0x4
	adds r3, 0x1
	cmp r3, 0x7
	ble _0807B97E
	movs r0, 0x8
	bl DungeonRandomCapped
	movs r1, 0x6
	mov r3, r10
	strb r1, [r3]
	ldr r1, _0807B9D8
	lsls r0, 2
	adds r0, r1
	ldrh r1, [r0]
	ldrh r4, [r6, 0x4]
	adds r1, r4
	ldr r2, [sp, 0x8]
	strh r1, [r2]
	ldrh r0, [r0, 0x2]
	b _0807BB5A
	.align 2, 0
_0807B9D4: .4byte gFaceDirectionIncrements
_0807B9D8: .4byte gAdjacentTileOffsets
_0807B9DC:
	ldr r0, _0807BA30
	ldr r2, [r0]
	lsls r1, r3, 1
	ldr r4, _0807BA34
	adds r0, r2, r4
	adds r0, r1
	movs r4, 0
	ldrsh r1, [r0, r4]
	mov r8, r1
	lsls r0, r3, 7
	ldr r1, _0807BA38
	adds r0, r1
	adds r2, r0
	mov r9, r2
	movs r2, 0x8A
	lsls r2, 1
	adds r0, r7, r2
	ldr r0, [r0]
	cmp r0, 0
	beq _0807BA40
	movs r0, 0x8
	bl DungeonRandomCapped
	adds r2, r7, 0
	adds r2, 0x78
	movs r1, 0x6
	strb r1, [r2]
	ldr r1, _0807BA3C
	lsls r0, 2
	adds r0, r1
	ldrh r1, [r0]
	ldrh r3, [r6, 0x4]
	adds r1, r3
	adds r2, 0x10
	strh r1, [r2]
	ldrh r0, [r0, 0x2]
	ldrh r6, [r6, 0x6]
	adds r0, r6
	adds r1, r7, 0
	adds r1, 0x8A
	strh r0, [r1]
	b _0807BB60
	.align 2, 0
_0807BA30: .4byte gDungeonGlobalData
_0807BA34: .4byte 0x00010844
_0807BA38: .4byte 0x00010884
_0807BA3C: .4byte gAdjacentTileOffsets
_0807BA40:
	adds r0, r7, 0
	adds r0, 0x78
	ldrb r1, [r0]
	mov r10, r0
	cmp r1, 0x4
	beq _0807BAA2
	mov r4, r8
	cmp r4, 0
	bne _0807BA84
	movs r0, 0x8
	bl DungeonRandomCapped
	adds r4, r0, 0
	movs r0, 0x6
	mov r1, r10
	strb r0, [r1]
	ldr r0, _0807BA80
	lsls r2, r4, 2
	adds r2, r0
	ldrh r0, [r2]
	ldrh r3, [r6, 0x4]
	adds r0, r3
	adds r1, r7, 0
	adds r1, 0x88
	strh r0, [r1]
	ldrh r0, [r2, 0x2]
	ldrh r6, [r6, 0x6]
	adds r0, r6
	adds r1, 0x2
	strh r0, [r1]
	b _0807BB60
	.align 2, 0
_0807BA80: .4byte gAdjacentTileOffsets
_0807BA84:
	movs r5, 0
_0807BA86:
	mov r0, r8
	bl DungeonRandomCapped
	adds r4, r0, 0
	ldr r0, [r6, 0x4]
	lsls r1, r4, 2
	mov r4, r9
	adds r2, r1, r4
	ldr r1, [r2]
	cmp r0, r1
	bne _0807BB18
	adds r5, 0x1
	cmp r5, 0x9
	ble _0807BA86
_0807BAA2:
	movs r1, 0x4
	ldrsh r0, [r6, r1]
	movs r2, 0x6
	ldrsh r1, [r6, r2]
	bl GetMapTile_1
	ldrh r1, [r0]
	movs r0, 0x8
	ands r0, r1
	cmp r0, 0
	beq _0807BB60
	movs r0, 0x8
	bl DungeonRandomCapped
	adds r4, r0, 0
	movs r3, 0
	mov r9, r3
_0807BAC4:
	movs r0, 0x7
	ands r4, r0
	movs r0, 0x4
	ldrsh r2, [r6, r0]
	ldr r0, _0807BB14
	lsls r1, r4, 2
	adds r1, r0
	movs r3, 0
	ldrsh r0, [r1, r3]
	adds r2, r0
	mov r8, r2
	movs r0, 0x6
	ldrsh r2, [r6, r0]
	movs r3, 0x2
	ldrsh r0, [r1, r3]
	adds r5, r2, r0
	mov r0, r8
	adds r1, r5, 0
	bl GetMapTile_1
	ldrb r0, [r0, 0x9]
	cmp r0, 0xFF
	bne _0807BB04
	adds r0, r6, 0
	adds r1, r4, 0
	mov r2, sp
	adds r2, 0x1
	bl CanMoveForward
	lsls r0, 24
	cmp r0, 0
	bne _0807BB2E
_0807BB04:
	movs r0, 0x1
	add r9, r0
	adds r4, 0x1
	mov r1, r9
	cmp r1, 0x7
	ble _0807BAC4
	b _0807BB60
	.align 2, 0
_0807BB14: .4byte gAdjacentTileOffsets
_0807BB18:
	movs r0, 0x4
	mov r3, r10
	strb r0, [r3]
	ldrh r1, [r2]
	adds r0, r7, 0
	adds r0, 0x88
	strh r1, [r0]
	ldrh r1, [r2, 0x2]
	adds r0, 0x2
	strh r1, [r0]
	b _0807BB60
_0807BB2E:
	movs r0, 0x3
	mov r4, r10
	strb r0, [r4]
	adds r0, r7, 0
	adds r0, 0x88
	mov r1, r8
	strh r1, [r0]
	adds r0, 0x2
	strh r5, [r0]
	b _0807BB60
_0807BB42:
	movs r0, 0x3
	mov r2, r10
	strb r0, [r2]
	ldr r0, _0807BB74
	lsls r1, r4, 2
	adds r1, r0
	ldrh r0, [r1]
	ldrh r3, [r6, 0x4]
	adds r0, r3
	ldr r4, [sp, 0x8]
	strh r0, [r4]
	ldrh r0, [r1, 0x2]
_0807BB5A:
	ldrh r6, [r6, 0x6]
	adds r0, r6
	strh r0, [r7]
_0807BB60:
	movs r0, 0x1
	add sp, 0x10
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	.align 2, 0
_0807BB74: .4byte gAdjacentTileOffsets
	thumb_func_end Explore

	thumb_func_start sub_807BB78
sub_807BB78:
	ldr r3, [r0, 0x70]
	adds r1, r3, 0
	adds r1, 0x78
	movs r2, 0
	strb r2, [r1]
	adds r1, 0x10
	ldr r0, [r0, 0x4]
	str r0, [r1]
	adds r0, r3, 0
	adds r0, 0x80
	str r2, [r0]
	subs r0, 0x4
	strh r2, [r0]
	bx lr
	thumb_func_end sub_807BB78

	.align 2, 0