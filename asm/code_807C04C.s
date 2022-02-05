	#include "asm/constants/gba_constants.inc"
  	#include "asm/macros.inc"

  	.syntax unified

  	.text

	thumb_func_start FindMoveTarget
FindMoveTarget:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x1C
	str r0, [sp, 0x8]
	adds r6, r1, 0
	mov r10, r2
	movs r0, 0x1
	str r0, [sp, 0x10]
	ldr r4, [r6, 0x70]
	movs r1, 0
	mov r8, r1
	ldr r1, _0807C0C8
	movs r2, 0
	adds r0, r1, 0x7
_0807C06E:
	strb r2, [r0]
	subs r0, 0x1
	cmp r0, r1
	bge _0807C06E
	adds r0, r6, 0
	mov r1, r10
	movs r2, 0x1
	bl GetTargetingFlags
	lsls r0, 16
	asrs r0, 16
	str r0, [sp, 0xC]
	adds r0, r6, 0
	movs r1, 0x8
	bl HasIQSkill
	lsls r0, 24
	lsrs r0, 24
	str r0, [sp, 0x14]
	movs r0, 0
	ldr r2, [sp, 0x8]
	strb r0, [r2]
	adds r0, r4, 0
	adds r0, 0xBC
	ldrb r0, [r0]
	cmp r0, 0x5
	bne _0807C0B0
	mov r0, r10
	bl GetMoveDealsDirectDamage
	lsls r0, 24
	cmp r0, 0
	beq _0807C0C4
_0807C0B0:
	ldr r3, [sp, 0x14]
	cmp r3, 0
	beq _0807C0CC
	adds r0, r6, 0
	mov r1, r10
	bl CanUseWithStatusChecker
	lsls r0, 24
	cmp r0, 0
	bne _0807C0CC
_0807C0C4:
	movs r0, 0x1
	b _0807C48C
	.align 2, 0
_0807C0C8: .4byte gCanAttackInDirection
_0807C0CC:
	movs r0, 0xF0
	ldr r1, [sp, 0xC]
	ands r0, r1
	cmp r0, 0
	beq _0807C0DE
	cmp r0, 0x10
	beq _0807C0DE
	cmp r0, 0x20
	bne _0807C19C
_0807C0DE:
	adds r0, r4, 0
	adds r0, 0xE8
	ldrb r1, [r0]
	cmp r1, 0x1
	bne _0807C128
	subs r0, 0xA2
	ldrb r7, [r0]
	ldr r0, _0807C118
	adds r0, r7, r0
	ldrb r3, [r0]
	cmp r3, 0
	beq _0807C0F8
	b _0807C3F6
_0807C0F8:
	strb r1, [r0]
	ldr r0, _0807C11C
	add r0, r8
	strb r7, [r0]
	ldr r0, _0807C120
	mov r4, r8
	lsls r2, r4, 2
	adds r0, r2, r0
	movs r1, 0x63
	str r1, [r0]
	ldr r0, _0807C124
	adds r2, r0
	str r3, [r2]
	movs r0, 0x1
	add r8, r0
	b _0807C3F6
	.align 2, 0
_0807C118: .4byte gCanAttackInDirection
_0807C11C: .4byte gUnknown_202F388
_0807C120: .4byte gPotentialTargetWeights_2
_0807C124: .4byte gUnknown_202F3B0
_0807C128:
	movs r7, 0
	movs r0, 0xF0
	ldr r1, [sp, 0xC]
	ands r0, r1
	lsls r5, r0, 16
_0807C132:
	movs r2, 0x4
	ldrsh r0, [r6, r2]
	ldr r1, _0807C198
	lsls r2, r7, 2
	adds r2, r1
	movs r3, 0
	ldrsh r1, [r2, r3]
	adds r0, r1
	movs r4, 0x6
	ldrsh r1, [r6, r4]
	movs r3, 0x2
	ldrsh r2, [r2, r3]
	adds r1, r2
	bl GetMapTileAtPosition
	ldr r4, [r0, 0x10]
	cmp r4, 0
	beq _0807C18E
	adds r0, r4, 0
	bl GetEntityType
	cmp r0, 0x1
	bne _0807C18E
	asrs r0, r5, 16
	cmp r0, 0x10
	beq _0807C178
	cmp r0, 0x20
	beq _0807C178
	adds r0, r6, 0
	adds r1, r7, 0
	bl CanAttackInFront
	lsls r0, 24
	cmp r0, 0
	beq _0807C18E
_0807C178:
	mov r0, r10
	str r0, [sp]
	ldr r1, [sp, 0x14]
	str r1, [sp, 0x4]
	mov r0, r8
	ldr r1, [sp, 0xC]
	adds r2, r6, 0
	adds r3, r4, 0
	bl WeightMoveIfUsable
	mov r8, r0
_0807C18E:
	adds r7, 0x1
	cmp r7, 0x7
	ble _0807C132
	b _0807C3F6
	.align 2, 0
_0807C198: .4byte gAdjacentTileOffsets
_0807C19C:
	cmp r0, 0x30
	bne _0807C1F0
	movs r5, 0
_0807C1A2:
	ldr r0, _0807C1E8
	ldr r0, [r0]
	lsls r1, r5, 2
	ldr r2, _0807C1EC
	adds r0, r2
	adds r0, r1
	ldr r4, [r0]
	adds r0, r4, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	beq _0807C1E0
	adds r0, r6, 0
	adds r1, r4, 0
	bl CanSee
	lsls r0, 24
	cmp r0, 0
	beq _0807C1E0
	mov r3, r10
	str r3, [sp]
	ldr r0, [sp, 0x14]
	str r0, [sp, 0x4]
	mov r0, r8
	ldr r1, [sp, 0xC]
	adds r2, r6, 0
	adds r3, r4, 0
	bl WeightMoveIfUsable
	mov r8, r0
_0807C1E0:
	adds r5, 0x1
	cmp r5, 0x13
	ble _0807C1A2
	b _0807C3F6
	.align 2, 0
_0807C1E8: .4byte gDungeonGlobalData
_0807C1EC: .4byte 0x000135cc
_0807C1F0:
	cmp r0, 0x40
	bne _0807C2A8
	movs r7, 0
	ldr r1, _0807C2A4
	mov r9, r1
_0807C1FA:
	movs r2, 0x4
	ldrsh r0, [r6, r2]
	mov r3, r9
	movs r4, 0
	ldrsh r1, [r3, r4]
	adds r0, r1
	movs r2, 0x6
	ldrsh r1, [r6, r2]
	movs r4, 0x2
	ldrsh r2, [r3, r4]
	adds r1, r2
	bl GetMapTileAtPosition
	adds r4, r0, 0
	adds r0, r6, 0
	adds r1, r7, 0
	bl CanAttackInFront
	lsls r0, 24
	cmp r0, 0
	beq _0807C296
	ldr r5, [r4, 0x10]
	cmp r5, 0
	beq _0807C250
	adds r0, r5, 0
	bl GetEntityType
	cmp r0, 0x1
	bne _0807C250
	mov r4, r8
	mov r0, r10
	str r0, [sp]
	ldr r1, [sp, 0x14]
	str r1, [sp, 0x4]
	adds r0, r4, 0
	ldr r1, [sp, 0xC]
	adds r2, r6, 0
	adds r3, r5, 0
	bl WeightMoveIfUsable
	mov r8, r0
	cmp r4, r8
	bne _0807C296
_0807C250:
	movs r2, 0x4
	ldrsh r0, [r6, r2]
	mov r3, r9
	movs r4, 0
	ldrsh r1, [r3, r4]
	lsls r1, 1
	adds r0, r1
	movs r2, 0x6
	ldrsh r1, [r6, r2]
	movs r4, 0x2
	ldrsh r2, [r3, r4]
	lsls r2, 1
	adds r1, r2
	bl GetMapTileAtPosition
	adds r4, r0, 0
	ldr r5, [r4, 0x10]
	cmp r5, 0
	beq _0807C296
	adds r0, r5, 0
	bl GetEntityType
	cmp r0, 0x1
	bne _0807C296
	mov r0, r10
	str r0, [sp]
	ldr r1, [sp, 0x14]
	str r1, [sp, 0x4]
	mov r0, r8
	ldr r1, [sp, 0xC]
	adds r2, r6, 0
	adds r3, r5, 0
	bl WeightMoveIfUsable
	mov r8, r0
_0807C296:
	movs r2, 0x4
	add r9, r2
	adds r7, 0x1
	cmp r7, 0x7
	ble _0807C1FA
	b _0807C3F6
	.align 2, 0
_0807C2A4: .4byte gAdjacentTileOffsets
_0807C2A8:
	cmp r0, 0x50
	beq _0807C2B0
	cmp r0, 0x80
	bne _0807C394
_0807C2B0:
	movs r3, 0x1
	str r3, [sp, 0x18]
	cmp r0, 0x50
	bne _0807C2BC
	movs r4, 0xA
	str r4, [sp, 0x18]
_0807C2BC:
	movs r0, 0
	mov r9, r0
_0807C2C0:
	ldr r0, _0807C37C
	ldr r0, [r0]
	mov r2, r9
	lsls r1, r2, 2
	ldr r3, _0807C380
	adds r0, r3
	adds r0, r1
	ldr r4, [r0]
	adds r0, r4, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	beq _0807C370
	cmp r6, r4
	beq _0807C370
	adds r1, r4, 0x4
	adds r0, r6, 0x4
	bl CalculateFacingDir
	adds r5, r0, 0
	ldr r0, _0807C384
	adds r7, r5, r0
	ldrb r0, [r7]
	cmp r0, 0
	bne _0807C370
	adds r0, r6, 0
	adds r1, r4, 0
	bl CanSee
	lsls r0, 24
	cmp r0, 0
	beq _0807C370
	adds r0, r6, 0
	adds r1, r4, 0
	ldr r2, [sp, 0x18]
	bl IsTargetInLineRange
	lsls r0, 24
	cmp r0, 0
	beq _0807C370
	ldr r0, [sp, 0x14]
	str r0, [sp]
	ldr r0, [sp, 0xC]
	adds r1, r6, 0
	adds r2, r4, 0
	mov r3, r10
	bl CanUseStatusMove
	lsls r0, 24
	cmp r0, 0
	beq _0807C370
	adds r0, r6, 0
	adds r1, r4, 0
	adds r2, r5, 0
	ldr r3, [sp, 0x18]
	bl IsTargetStraightAhead
	lsls r0, 24
	cmp r0, 0
	beq _0807C370
	movs r0, 0x1
	strb r0, [r7]
	ldr r0, _0807C388
	add r0, r8
	strb r5, [r0]
	adds r0, r6, 0
	mov r1, r10
	bl GetMoveTypeForPokemon
	adds r3, r0, 0
	lsls r3, 24
	lsrs r3, 24
	adds r0, r6, 0
	ldr r1, [sp, 0xC]
	adds r2, r4, 0
	bl WeightMove
	ldr r1, _0807C38C
	mov r3, r8
	lsls r2, r3, 2
	adds r1, r2, r1
	str r0, [r1]
	ldr r0, _0807C390
	adds r2, r0
	str r4, [r2]
	movs r4, 0x1
	add r8, r4
_0807C370:
	movs r0, 0x1
	add r9, r0
	mov r1, r9
	cmp r1, 0x13
	ble _0807C2C0
	b _0807C3F6
	.align 2, 0
_0807C37C: .4byte gDungeonGlobalData
_0807C380: .4byte 0x000135cc
_0807C384: .4byte gCanAttackInDirection
_0807C388: .4byte gUnknown_202F388
_0807C38C: .4byte gPotentialTargetWeights_2
_0807C390: .4byte gUnknown_202F3B0
_0807C394:
	cmp r0, 0x60
	bne _0807C3DC
	movs r5, 0
_0807C39A:
	ldr r0, _0807C3D4
	ldr r0, [r0]
	lsls r1, r5, 2
	ldr r2, _0807C3D8
	adds r0, r2
	adds r0, r1
	ldr r4, [r0]
	adds r0, r4, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	beq _0807C3CA
	mov r3, r10
	str r3, [sp]
	ldr r0, [sp, 0x14]
	str r0, [sp, 0x4]
	mov r0, r8
	ldr r1, [sp, 0xC]
	adds r2, r6, 0
	adds r3, r4, 0
	bl WeightMoveIfUsable
	mov r8, r0
_0807C3CA:
	adds r5, 0x1
	cmp r5, 0x13
	ble _0807C39A
	b _0807C3F6
	.align 2, 0
_0807C3D4: .4byte gDungeonGlobalData
_0807C3D8: .4byte 0x000135cc
_0807C3DC:
	cmp r0, 0x70
	bne _0807C3F6
	mov r1, r10
	str r1, [sp]
	ldr r2, [sp, 0x14]
	str r2, [sp, 0x4]
	mov r0, r8
	ldr r1, [sp, 0xC]
	adds r2, r6, 0
	adds r3, r6, 0
	bl WeightMoveIfUsable
	mov r8, r0
_0807C3F6:
	mov r3, r8
	cmp r3, 0
	bne _0807C402
	ldr r4, [sp, 0x8]
	strb r3, [r4]
	b _0807C48A
_0807C402:
	movs r4, 0
	movs r3, 0
	mov r0, r8
	cmp r0, 0
	ble _0807C420
	ldr r2, _0807C464
	mov r1, r8
_0807C410:
	ldr r0, [r2]
	cmp r3, r0
	bge _0807C418
	adds r3, r0, 0
_0807C418:
	adds r2, 0x4
	subs r1, 0x1
	cmp r1, 0
	bne _0807C410
_0807C420:
	mov r1, r8
	cmp r1, 0
	ble _0807C43A
	movs r5, 0
	ldr r2, _0807C464
_0807C42A:
	ldr r0, [r2]
	cmp r3, r0
	beq _0807C432
	str r5, [r2]
_0807C432:
	adds r2, 0x4
	subs r1, 0x1
	cmp r1, 0
	bne _0807C42A
_0807C43A:
	str r3, [sp, 0x10]
	mov r2, r8
	cmp r2, 0
	ble _0807C450
	ldr r2, _0807C464
	mov r1, r8
_0807C446:
	ldm r2!, {r0}
	adds r4, r0
	subs r1, 0x1
	cmp r1, 0
	bne _0807C446
_0807C450:
	adds r0, r4, 0
	bl DungeonRandomCapped
	adds r2, r0, 0
	movs r1, 0
	cmp r1, r8
	bge _0807C478
	ldr r3, _0807C464
	b _0807C470
	.align 2, 0
_0807C464: .4byte gPotentialTargetWeights_2
_0807C468:
	adds r3, 0x4
	adds r1, 0x1
	cmp r1, r8
	bge _0807C478
_0807C470:
	ldr r0, [r3]
	subs r2, r0
	cmp r2, 0
	bge _0807C468
_0807C478:
	movs r0, 0x1
	ldr r3, [sp, 0x8]
	strb r0, [r3]
	ldr r0, _0807C49C
	adds r0, r1, r0
	ldrb r0, [r0]
	strb r0, [r3, 0x1]
	movs r0, 0x8
	str r0, [r3, 0x4]
_0807C48A:
	ldr r0, [sp, 0x10]
_0807C48C:
	add sp, 0x1C
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	.align 2, 0
_0807C49C: .4byte gUnknown_202F388
	thumb_func_end FindMoveTarget

	thumb_func_start IsTargetInLineRange
IsTargetInLineRange:
	push {r4-r7,lr}
	adds r4, r0, 0
	adds r5, r1, 0
	movs r0, 0x4
	ldrsh r1, [r4, r0]
	movs r3, 0x4
	ldrsh r0, [r5, r3]
	subs r3, r1, r0
	cmp r3, 0
	bge _0807C4B6
	negs r3, r3
_0807C4B6:
	movs r6, 0x6
	ldrsh r1, [r4, r6]
	movs r7, 0x6
	ldrsh r0, [r5, r7]
	subs r1, r0
	cmp r1, 0
	bge _0807C4C6
	negs r1, r1
_0807C4C6:
	adds r0, r1, 0
	cmp r1, r3
	bge _0807C4CE
	adds r0, r3, 0
_0807C4CE:
	cmp r0, 0xA
	bgt _0807C578
	cmp r0, r2
	bgt _0807C578
	movs r6, 0x1
	negs r6, r6
	cmp r3, r1
	bne _0807C516
	movs r0, 0x4
	ldrsh r1, [r4, r0]
	movs r2, 0x4
	ldrsh r0, [r5, r2]
	ldrh r2, [r4, 0x4]
	ldrh r3, [r5, 0x4]
	cmp r1, r0
	bge _0807C4FE
	movs r6, 0x6
	ldrsh r1, [r4, r6]
	movs r7, 0x6
	ldrsh r0, [r5, r7]
	cmp r1, r0
	blt _0807C574
	cmp r1, r0
	bgt _0807C574
_0807C4FE:
	lsls r1, r2, 16
	lsls r0, r3, 16
	movs r6, 0x7
	cmp r1, r0
	ble _0807C570
	movs r0, 0x6
	ldrsh r1, [r4, r0]
	movs r2, 0x6
	ldrsh r0, [r5, r2]
	cmp r1, r0
	ble _0807C570
	b _0807C574
_0807C516:
	movs r3, 0x4
	ldrsh r1, [r4, r3]
	movs r7, 0x4
	ldrsh r0, [r5, r7]
	ldrh r2, [r4, 0x4]
	ldrh r3, [r5, 0x4]
	cmp r1, r0
	bne _0807C532
	movs r0, 0x6
	ldrsh r1, [r4, r0]
	movs r7, 0x6
	ldrsh r0, [r5, r7]
	cmp r1, r0
	blt _0807C574
_0807C532:
	lsls r1, r2, 16
	lsls r0, r3, 16
	cmp r1, r0
	bge _0807C546
	movs r0, 0x6
	ldrsh r1, [r4, r0]
	movs r7, 0x6
	ldrsh r0, [r5, r7]
	cmp r1, r0
	beq _0807C574
_0807C546:
	lsls r1, r2, 16
	lsls r0, r3, 16
	cmp r1, r0
	bne _0807C55A
	movs r0, 0x6
	ldrsh r1, [r4, r0]
	movs r7, 0x6
	ldrsh r0, [r5, r7]
	cmp r1, r0
	bgt _0807C574
_0807C55A:
	lsls r1, r2, 16
	lsls r0, r3, 16
	cmp r1, r0
	ble _0807C570
	movs r0, 0x6
	ldrsh r1, [r4, r0]
	movs r2, 0x6
	ldrsh r0, [r5, r2]
	cmp r1, r0
	bne _0807C570
	movs r6, 0x6
_0807C570:
	cmp r6, 0
	blt _0807C578
_0807C574:
	movs r0, 0x1
	b _0807C57A
_0807C578:
	movs r0, 0
_0807C57A:
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end IsTargetInLineRange

	thumb_func_start WeightMoveIfUsable
WeightMoveIfUsable:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x4
	adds r6, r0, 0
	adds r5, r2, 0
	adds r7, r3, 0
	ldr r0, [sp, 0x28]
	lsls r1, 16
	asrs r1, 16
	mov r9, r1
	lsls r0, 24
	lsrs r0, 24
	mov r10, r0
	ldr r2, [r5, 0x70]
	ldr r1, [r5, 0x4]
	ldr r0, [r7, 0x4]
	cmp r1, r0
	beq _0807C5BC
	movs r0, 0xF0
	mov r1, r9
	ands r0, r1
	cmp r0, 0x30
	beq _0807C5BC
	cmp r0, 0x60
	beq _0807C5BC
	cmp r0, 0x70
	bne _0807C5C4
_0807C5BC:
	adds r0, r2, 0
	adds r0, 0x46
	ldrb r4, [r0]
	b _0807C5CE
_0807C5C4:
	adds r0, r5, 0x4
	adds r1, r7, 0x4
	bl CalculateFacingDir
	adds r4, r0, 0
_0807C5CE:
	ldr r0, _0807C638
	adds r0, r4
	mov r8, r0
	ldrb r0, [r0]
	cmp r0, 0
	bne _0807C624
	mov r0, r10
	str r0, [sp]
	mov r0, r9
	adds r1, r5, 0
	adds r2, r7, 0
	ldr r3, [sp, 0x24]
	bl CanUseStatusMove
	lsls r0, 24
	cmp r0, 0
	beq _0807C624
	movs r0, 0x1
	mov r1, r8
	strb r0, [r1]
	ldr r0, _0807C63C
	adds r0, r6, r0
	strb r4, [r0]
	adds r0, r5, 0
	ldr r1, [sp, 0x24]
	bl GetMoveTypeForPokemon
	adds r3, r0, 0
	lsls r3, 24
	lsrs r3, 24
	adds r0, r5, 0
	mov r1, r9
	adds r2, r7, 0
	bl WeightMove
	ldr r1, _0807C640
	lsls r2, r6, 2
	adds r1, r2, r1
	str r0, [r1]
	ldr r0, _0807C644
	adds r2, r0
	str r7, [r2]
	adds r6, 0x1
_0807C624:
	adds r0, r6, 0
	add sp, 0x4
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	.align 2, 0
_0807C638: .4byte gCanAttackInDirection
_0807C63C: .4byte gUnknown_202F388
_0807C640: .4byte gPotentialTargetWeights_2
_0807C644: .4byte gUnknown_202F3B0
	thumb_func_end WeightMoveIfUsable

	thumb_func_start CanUseStatusMove
CanUseStatusMove:
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	adds r5, r1, 0
	adds r4, r2, 0
	mov r8, r3
	ldr r1, [sp, 0x1C]
	lsls r0, 16
	asrs r6, r0, 16
	lsls r1, 24
	lsrs r1, 24
	mov r9, r1
	movs r7, 0
	movs r0, 0xF
	ands r0, r6
	adds r1, r0, 0
	cmp r1, 0
	bne _0807C686
	adds r0, r5, 0
	adds r1, r4, 0
	movs r2, 0
	movs r3, 0x1
	bl CanTarget
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _0807C6E0
	movs r7, 0x1
	b _0807C6E4
_0807C686:
	cmp r1, 0x1
	beq _0807C6BE
	cmp r1, 0x2
	bne _0807C692
	ldr r1, [r4, 0x70]
	b _0807C69C
_0807C692:
	cmp r1, 0x5
	bne _0807C6B6
	ldr r1, [r4, 0x70]
	cmp r5, r4
	beq _0807C6B2
_0807C69C:
	movs r7, 0x1
	ldrb r0, [r1, 0x8]
	cmp r0, 0x1
	beq _0807C6B2
	adds r0, r1, 0
	adds r0, 0xA4
	ldrb r0, [r0]
	cmp r0, 0x4
	beq _0807C6B2
	cmp r0, 0x1
	bne _0807C6E0
_0807C6B2:
	movs r0, 0
	b _0807C7A0
_0807C6B6:
	cmp r1, 0x6
	bne _0807C6D4
	cmp r5, r4
	beq _0807C6B2
_0807C6BE:
	adds r0, r5, 0
	adds r1, r4, 0
	movs r2, 0
	movs r3, 0x1
	bl CanTarget
	lsls r0, 24
	cmp r0, 0
	bne _0807C6E0
	movs r7, 0x1
	b _0807C6E4
_0807C6D4:
	subs r0, 0x3
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0x1
	bhi _0807C6E0
	movs r7, 0x1
_0807C6E0:
	cmp r7, 0
	beq _0807C79E
_0807C6E4:
	mov r0, r9
	cmp r0, 0
	beq _0807C77C
	adds r0, r5, 0
	adds r1, r4, 0
	mov r2, r8
	bl CanUseWithStatusChecker_2
	lsls r0, 24
	cmp r0, 0
	beq _0807C6B2
	movs r1, 0xF0
	lsls r1, 4
	ands r1, r6
	movs r0, 0x80
	lsls r0, 1
	cmp r1, r0
	beq _0807C78A
	movs r0, 0x80
	lsls r0, 2
	cmp r1, r0
	beq _0807C76E
	movs r0, 0xC0
	lsls r0, 2
	cmp r1, r0
	bne _0807C720
	adds r0, r4, 0
	bl HasNegativeStatus
	b _0807C774
_0807C720:
	movs r0, 0x80
	lsls r0, 3
	cmp r1, r0
	bne _0807C730
	adds r0, r4, 0
	bl IsSleeping
	b _0807C774
_0807C730:
	movs r0, 0xC0
	lsls r0, 3
	cmp r1, r0
	bne _0807C75A
	ldr r1, [r4, 0x70]
	adds r0, r1, 0
	adds r0, 0x5C
	ldrb r0, [r0]
	cmp r0, 0xE
	beq _0807C74E
	adds r0, r1, 0
	adds r0, 0x5D
	ldrb r0, [r0]
	cmp r0, 0xE
	bne _0807C6B2
_0807C74E:
	adds r0, r1, 0
	adds r0, 0xF5
	ldrb r0, [r0]
	cmp r0, 0
	beq _0807C79E
	b _0807C6B2
_0807C75A:
	movs r0, 0xA0
	lsls r0, 3
	cmp r1, r0
	bne _0807C79E
	adds r0, r4, 0
	bl HasNegativeStatus
	lsls r0, 24
	cmp r0, 0
	bne _0807C79E
_0807C76E:
	adds r0, r4, 0
	bl HasQuarterHPOrLess
_0807C774:
	lsls r0, 24
	cmp r0, 0
	bne _0807C79E
	b _0807C6B2
_0807C77C:
	movs r0, 0xF0
	lsls r0, 4
	ands r0, r6
	movs r1, 0x80
	lsls r1, 1
	cmp r0, r1
	bne _0807C79E
_0807C78A:
	mov r0, r8
	movs r1, 0x2
	bl GetMoveAccuracy
	adds r4, r0, 0
	movs r0, 0x64
	bl DungeonRandomCapped
	cmp r0, r4
	bge _0807C6B2
_0807C79E:
	adds r0, r7, 0
_0807C7A0:
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end CanUseStatusMove

	thumb_func_start WeightMove
WeightMove:
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	adds r5, r0, 0
	mov r8, r2
	lsls r1, 16
	asrs r1, 16
	lsls r3, 24
	lsrs r3, 24
	mov r9, r3
	movs r6, 0x1
	ldr r4, [r2, 0x70]
	adds r7, r4, 0
	ldrb r0, [r4, 0x6]
	cmp r0, 0
	beq _0807C7D6
	movs r0, 0xF
	ands r0, r1
	cmp r0, 0
	beq _0807C7DA
_0807C7D6:
	movs r0, 0x1
	b _0807C848
_0807C7DA:
	adds r0, r5, 0
	movs r1, 0x9
	bl HasIQSkill
	lsls r0, 24
	cmp r0, 0
	beq _0807C804
	ldr r0, _0807C7FC
	ldr r0, [r0]
	movs r2, 0x2
	ldrsh r1, [r4, r2]
	ldr r2, _0807C800
	adds r0, r2
	adds r0, r1
	ldrb r6, [r0]
	b _0807C846
	.align 2, 0
_0807C7FC: .4byte gDungeonGlobalData
_0807C800: .4byte 0x0000363c
_0807C804:
	adds r0, r5, 0
	movs r1, 0xA
	bl HasIQSkill
	lsls r0, 24
	cmp r0, 0
	beq _0807C828
	ldrb r1, [r7, 0xE]
	movs r2, 0xC
	negs r2, r2
	adds r0, r2, 0
	subs r0, r1
	lsls r0, 24
	lsrs r6, r0, 24
	cmp r6, 0
	bne _0807C846
	movs r6, 0x1
	b _0807C846
_0807C828:
	adds r0, r5, 0
	movs r1, 0xB
	bl HasIQSkill
	lsls r0, 24
	cmp r0, 0
	beq _0807C846
	adds r0, r5, 0
	mov r1, r8
	mov r2, r9
	bl WeightWeakTypePicker
	adds r0, 0x1
	lsls r0, 24
	lsrs r6, r0, 24
_0807C846:
	adds r0, r6, 0
_0807C848:
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end WeightMove

	thumb_func_start TargetRegularAttack
TargetRegularAttack:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x50
	adds r7, r0, 0
	str r1, [sp, 0x40]
	lsls r2, 24
	lsrs r2, 24
	str r2, [sp, 0x44]
	ldr r0, [r7, 0x70]
	movs r1, 0
	mov r8, r1
	adds r1, r0, 0
	adds r1, 0x46
	ldrb r6, [r1]
	adds r0, 0xE8
	ldrb r0, [r0]
	movs r3, 0x8
	mov r10, r3
	cmp r0, 0x1
	bne _0807C886
	movs r0, 0x1
	mov r10, r0
_0807C886:
	movs r4, 0
	adds r0, r7, 0
	movs r1, 0x9
	bl HasIQSkill
	lsls r0, 24
	cmp r0, 0
	bne _0807C8A4
	adds r0, r7, 0
	movs r1, 0xA
	bl HasIQSkill
	lsls r0, 24
	cmp r0, 0
	beq _0807C8A6
_0807C8A4:
	movs r4, 0x1
_0807C8A6:
	str r4, [sp, 0x48]
	adds r0, r7, 0
	movs r1, 0x8
	bl HasIQSkill
	lsls r0, 24
	lsrs r0, 24
	str r0, [sp, 0x4C]
	movs r1, 0
	mov r9, r1
	cmp r9, r10
	bge _0807C952
_0807C8BE:
	movs r0, 0x7
	ands r6, r0
	movs r3, 0x4
	ldrsh r0, [r7, r3]
	ldr r1, _0807C95C
	lsls r2, r6, 2
	adds r2, r1
	movs r3, 0
	ldrsh r1, [r2, r3]
	adds r0, r1
	movs r3, 0x6
	ldrsh r1, [r7, r3]
	movs r3, 0x2
	ldrsh r2, [r2, r3]
	adds r1, r2
	bl GetMapTileAtPosition
	ldr r5, [r0, 0x10]
	cmp r5, 0
	beq _0807C948
	adds r0, r5, 0
	bl GetEntityType
	cmp r0, 0x1
	bne _0807C948
	adds r0, r7, 0
	adds r1, r6, 0
	bl CanAttackInFront
	lsls r0, 24
	cmp r0, 0
	beq _0807C948
	adds r0, r7, 0
	adds r1, r5, 0
	movs r2, 0
	ldr r3, [sp, 0x44]
	bl CanTarget
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _0807C948
	ldr r0, [sp, 0x4C]
	cmp r0, 0
	beq _0807C922
	ldr r0, [r5, 0x70]
	adds r0, 0xB0
	ldrb r0, [r0]
	cmp r0, 0x1
	beq _0807C948
_0807C922:
	mov r1, r8
	lsls r4, r1, 2
	mov r3, sp
	adds r0, r3, r4
	str r6, [r0]
	adds r0, r7, 0
	movs r1, 0
	adds r2, r5, 0
	movs r3, 0
	bl WeightMove
	add r1, sp, 0x20
	adds r1, r4
	str r0, [r1]
	ldr r0, [sp, 0x48]
	cmp r0, 0
	beq _0807C960
	movs r1, 0x1
	add r8, r1
_0807C948:
	movs r3, 0x1
	add r9, r3
	adds r6, 0x1
	cmp r9, r10
	blt _0807C8BE
_0807C952:
	mov r0, r8
	cmp r0, 0
	bne _0807C966
	movs r0, 0
	b _0807C9E8
	.align 2, 0
_0807C95C: .4byte gAdjacentTileOffsets
_0807C960:
	ldr r1, [sp, 0x40]
	str r6, [r1]
	b _0807C9E6
_0807C966:
	movs r4, 0
	movs r3, 0
	mov r0, r8
	cmp r0, 0
	ble _0807C984
	add r1, sp, 0x20
	mov r2, r8
_0807C974:
	ldr r0, [r1]
	cmp r3, r0
	bge _0807C97C
	adds r3, r0, 0
_0807C97C:
	adds r1, 0x4
	subs r2, 0x1
	cmp r2, 0
	bne _0807C974
_0807C984:
	mov r1, r8
	cmp r1, 0
	ble _0807C9A0
	movs r5, 0
	add r1, sp, 0x20
	mov r2, r8
_0807C990:
	ldr r0, [r1]
	cmp r3, r0
	beq _0807C998
	str r5, [r1]
_0807C998:
	adds r1, 0x4
	subs r2, 0x1
	cmp r2, 0
	bne _0807C990
_0807C9A0:
	mov r3, r8
	cmp r3, 0
	ble _0807C9B4
	add r1, sp, 0x20
	mov r2, r8
_0807C9AA:
	ldm r1!, {r0}
	adds r4, r0
	subs r2, 0x1
	cmp r2, 0
	bne _0807C9AA
_0807C9B4:
	adds r0, r4, 0
	bl DungeonRandomCapped
	adds r1, r0, 0
	movs r2, 0
	cmp r2, r8
	bge _0807C9DC
	ldr r0, [sp, 0x20]
	subs r1, r0
	cmp r1, 0
	blt _0807C9DC
	add r3, sp, 0x20
_0807C9CC:
	adds r3, 0x4
	adds r2, 0x1
	cmp r2, r8
	bge _0807C9DC
	ldr r0, [r3]
	subs r1, r0
	cmp r1, 0
	bge _0807C9CC
_0807C9DC:
	lsls r0, r2, 2
	add r0, sp
	ldr r0, [r0]
	ldr r1, [sp, 0x40]
	str r0, [r1]
_0807C9E6:
	movs r0, 0x1
_0807C9E8:
	add sp, 0x50
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end TargetRegularAttack

	.align 2, 0