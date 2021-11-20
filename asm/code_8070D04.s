	.include "constants/gba_constants.inc"
	.include "asm/macros.inc"

	.syntax unified

	.text

	thumb_func_start CannotAttack
CannotAttack:
	push {lr}
	adds r3, r0, 0
	lsls r1, 24
	ldr r2, [r3, 0x70]
	cmp r1, 0
	bne _08070D22
	adds r0, r2, 0
	adds r0, 0xA8
	ldrb r0, [r0]
	cmp r0, 0x2
	beq _08070D22
	cmp r0, 0x4
	beq _08070D22
	cmp r0, 0
	bne _08070D64
_08070D22:
	adds r0, r2, 0
	adds r0, 0xB0
	ldrb r0, [r0]
	cmp r0, 0x1
	beq _08070D64
	cmp r0, 0x3
	beq _08070D64
	cmp r0, 0x4
	beq _08070D64
	cmp r0, 0x6
	beq _08070D64
	adds r0, r2, 0
	adds r0, 0xBC
	ldrb r0, [r0]
	cmp r0, 0x1
	beq _08070D64
	cmp r0, 0x3
	beq _08070D64
	cmp r0, 0x7
	beq _08070D64
	adds r0, r2, 0
	adds r0, 0xAC
	ldrb r0, [r0]
	cmp r0, 0x4
	beq _08070D64
	adds r0, r3, 0
	bl ShouldAvoidEnemies
	lsls r0, 24
	cmp r0, 0
	bne _08070D64
	movs r0, 0
	b _08070D66
_08070D64:
	movs r0, 0x1
_08070D66:
	pop {r1}
	bx r1
	thumb_func_end CannotAttack

	thumb_func_start CannotMoveForward
CannotMoveForward:
	push {r4-r6,lr}
	adds r4, r0, 0
	adds r6, r1, 0
	ldr r0, [r4, 0x70]
	movs r1, 0x2
	ldrsh r0, [r0, r1]
	bl GetCrossableTerrain
	lsls r0, 24
	lsrs r5, r0, 24
	movs r2, 0x4
	ldrsh r0, [r4, r2]
	ldr r1, _08070DD8
	lsls r2, r6, 2
	adds r2, r1
	movs r3, 0
	ldrsh r1, [r2, r3]
	adds r0, r1
	movs r3, 0x6
	ldrsh r1, [r4, r3]
	movs r3, 0x2
	ldrsh r2, [r2, r3]
	adds r1, r2
	bl GetMapTileAtPosition
	adds r2, r0, 0
	ldrh r1, [r2]
	movs r0, 0x10
	ands r0, r1
	cmp r0, 0
	bne _08070E34
	ldr r0, [r2, 0x10]
	cmp r0, 0
	bne _08070E34
	bl IsFixedDungeon
	lsls r0, 24
	cmp r0, 0
	bne _08070E04
	ldr r0, [r4, 0x70]
	adds r0, 0xE4
	ldrb r0, [r0]
	cmp r0, 0x3
	beq _08070DD2
	adds r0, r4, 0
	movs r1, 0x9
	bl HasItem
	lsls r0, 24
	cmp r0, 0
	beq _08070DDC
_08070DD2:
	movs r5, 0x3
	b _08070E04
	.align 2, 0
_08070DD8: .4byte gAdjacentTileOffsets
_08070DDC:
	adds r0, r4, 0
	movs r1, 0xC
	bl HasIQSkill
	lsls r0, 24
	cmp r0, 0
	bne _08070E02
	adds r0, r4, 0
	movs r1, 0xD
	bl HasIQSkill
	lsls r0, 24
	cmp r0, 0
	beq _08070E04
	movs r0, 0x1
	ands r0, r6
	movs r5, 0x3
	cmp r0, 0
	beq _08070E04
_08070E02:
	movs r5, 0x2
_08070E04:
	movs r1, 0x4
	ldrsh r0, [r4, r1]
	movs r2, 0x6
	ldrsh r1, [r4, r2]
	bl GetMapTileAtPosition
	adds r2, r0, 0
	adds r1, r2, 0
	adds r1, 0xA
	adds r1, r5
	ldr r2, _08070E30
	movs r0, 0x7
	ands r0, r6
	adds r0, r2
	ldrb r1, [r1]
	ldrb r0, [r0]
	ands r0, r1
	cmp r0, 0
	beq _08070E34
	movs r0, 0x1
	b _08070E36
	.align 2, 0
_08070E30: .4byte gDirectionBitMasks
_08070E34:
	movs r0, 0
_08070E36:
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end CannotMoveForward

	thumb_func_start sub_8070E3C
sub_8070E3C:
	push {r4-r7,lr}
	adds r4, r0, 0
	adds r6, r1, 0
	adds r7, r2, 0
	ldr r0, [r4, 0x70]
	movs r1, 0x2
	ldrsh r0, [r0, r1]
	bl GetCrossableTerrain
	lsls r0, 24
	lsrs r5, r0, 24
	movs r2, 0
	ldrsh r0, [r6, r2]
	ldr r1, _08070EB0
	lsls r2, r7, 2
	adds r2, r1
	movs r3, 0
	ldrsh r1, [r2, r3]
	adds r0, r1
	movs r3, 0x2
	ldrsh r1, [r6, r3]
	movs r3, 0x2
	ldrsh r2, [r2, r3]
	adds r1, r2
	bl GetMapTileAtPosition
	adds r2, r0, 0
	ldrh r1, [r2]
	movs r0, 0x10
	ands r0, r1
	cmp r0, 0
	bne _08070F0C
	ldr r0, [r2, 0x10]
	cmp r0, 0
	beq _08070E8A
	bl GetEntityType
	cmp r0, 0x1
	bne _08070F0C
_08070E8A:
	bl IsFixedDungeon
	lsls r0, 24
	cmp r0, 0
	bne _08070EDC
	ldr r0, [r4, 0x70]
	adds r0, 0xE4
	ldrb r0, [r0]
	cmp r0, 0x3
	beq _08070EAC
	adds r0, r4, 0
	movs r1, 0x9
	bl HasItem
	lsls r0, 24
	cmp r0, 0
	beq _08070EB4
_08070EAC:
	movs r5, 0x3
	b _08070EDC
	.align 2, 0
_08070EB0: .4byte gAdjacentTileOffsets
_08070EB4:
	adds r0, r4, 0
	movs r1, 0xC
	bl HasIQSkill
	lsls r0, 24
	cmp r0, 0
	bne _08070EDA
	adds r0, r4, 0
	movs r1, 0xD
	bl HasIQSkill
	lsls r0, 24
	cmp r0, 0
	beq _08070EDC
	movs r0, 0x1
	ands r0, r7
	movs r5, 0x3
	cmp r0, 0
	beq _08070EDC
_08070EDA:
	movs r5, 0x2
_08070EDC:
	movs r1, 0
	ldrsh r0, [r6, r1]
	movs r2, 0x2
	ldrsh r1, [r6, r2]
	bl GetMapTileAtPosition
	adds r2, r0, 0
	adds r1, r2, 0
	adds r1, 0xA
	adds r1, r5
	ldr r2, _08070F08
	movs r0, 0x7
	ands r0, r7
	adds r0, r2
	ldrb r1, [r1]
	ldrb r0, [r0]
	ands r0, r1
	cmp r0, 0
	beq _08070F0C
	movs r0, 0x1
	b _08070F0E
	.align 2, 0
_08070F08: .4byte gUnknown_8106FB5
_08070F0C:
	movs r0, 0
_08070F0E:
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_8070E3C

	thumb_func_start sub_8070F14
sub_8070F14:
	push {r4,r5,lr}
	adds r4, r0, 0
	adds r5, r1, 0
	movs r1, 0x4
	ldrsh r0, [r4, r1]
	ldr r1, _08070F70
	lsls r2, r5, 2
	adds r2, r1
	movs r3, 0
	ldrsh r1, [r2, r3]
	adds r0, r1
	movs r3, 0x6
	ldrsh r1, [r4, r3]
	movs r3, 0x2
	ldrsh r2, [r2, r3]
	adds r1, r2
	bl GetMapTileAtPosition
	adds r2, r0, 0
	ldrh r1, [r2]
	movs r0, 0x10
	ands r0, r1
	cmp r0, 0
	bne _08070F78
	ldr r0, [r2, 0x10]
	cmp r0, 0
	bne _08070F78
	movs r1, 0x4
	ldrsh r0, [r4, r1]
	movs r2, 0x6
	ldrsh r1, [r4, r2]
	bl GetMapTileAtPosition
	adds r2, r0, 0
	ldr r1, _08070F74
	movs r0, 0x7
	ands r0, r5
	adds r0, r1
	ldrb r1, [r2, 0xA]
	ldrb r0, [r0]
	ands r0, r1
	cmp r0, 0
	beq _08070F78
	movs r0, 0x1
	b _08070F7A
	.align 2, 0
_08070F70: .4byte gAdjacentTileOffsets
_08070F74: .4byte gUnknown_8106FBD
_08070F78:
	movs r0, 0
_08070F7A:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_8070F14

	thumb_func_start sub_8070F80
sub_8070F80:
	push {r4-r6,lr}
	adds r4, r0, 0
	adds r6, r1, 0
	ldr r0, [r4, 0x70]
	movs r1, 0x2
	ldrsh r0, [r0, r1]
	bl GetCrossableTerrain
	lsls r0, 24
	lsrs r5, r0, 24
	movs r2, 0x4
	ldrsh r0, [r4, r2]
	ldr r1, _08070FF4
	lsls r2, r6, 2
	adds r2, r1
	movs r3, 0
	ldrsh r1, [r2, r3]
	adds r0, r1
	movs r3, 0x6
	ldrsh r1, [r4, r3]
	movs r3, 0x2
	ldrsh r2, [r2, r3]
	adds r1, r2
	bl GetMapTileAtPosition
	adds r2, r0, 0
	ldrh r1, [r2]
	movs r0, 0x10
	ands r0, r1
	cmp r0, 0
	bne _08071050
	ldr r0, [r2, 0x10]
	cmp r0, 0
	beq _08070FCC
	bl GetEntityType
	cmp r0, 0x1
	bne _08071050
_08070FCC:
	bl IsFixedDungeon
	lsls r0, 24
	cmp r0, 0
	bne _08071020
	ldr r0, [r4, 0x70]
	adds r0, 0xE4
	ldrb r0, [r0]
	cmp r0, 0x3
	beq _08070FEE
	adds r0, r4, 0
	movs r1, 0x9
	bl HasItem
	lsls r0, 24
	cmp r0, 0
	beq _08070FF8
_08070FEE:
	movs r5, 0x3
	b _08071020
	.align 2, 0
_08070FF4: .4byte gAdjacentTileOffsets
_08070FF8:
	adds r0, r4, 0
	movs r1, 0xC
	bl HasIQSkill
	lsls r0, 24
	cmp r0, 0
	bne _0807101E
	adds r0, r4, 0
	movs r1, 0xD
	bl HasIQSkill
	lsls r0, 24
	cmp r0, 0
	beq _08071020
	movs r0, 0x1
	ands r0, r6
	movs r5, 0x3
	cmp r0, 0
	beq _08071020
_0807101E:
	movs r5, 0x2
_08071020:
	movs r1, 0x4
	ldrsh r0, [r4, r1]
	movs r2, 0x6
	ldrsh r1, [r4, r2]
	bl GetMapTileAtPosition
	adds r2, r0, 0
	adds r1, r2, 0
	adds r1, 0xA
	adds r1, r5
	ldr r2, _0807104C
	movs r0, 0x7
	ands r0, r6
	adds r0, r2
	ldrb r1, [r1]
	ldrb r0, [r0]
	ands r0, r1
	cmp r0, 0
	beq _08071050
	movs r0, 0x1
	b _08071052
	.align 2, 0
_0807104C: .4byte gUnknown_8106FC5
_08071050:
	movs r0, 0
_08071052:
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end sub_8070F80

	thumb_func_start sub_8071058
sub_8071058:
	push {r4-r7,lr}
	adds r5, r0, 0
	adds r7, r1, 0
	ldr r0, [r5, 0x70]
	movs r1, 0x2
	ldrsh r0, [r0, r1]
	bl GetCrossableTerrain
	lsls r0, 24
	lsrs r6, r0, 24
	movs r2, 0x4
	ldrsh r0, [r5, r2]
	ldr r1, _080710D4
	lsls r2, r7, 2
	adds r2, r1
	movs r3, 0
	ldrsh r1, [r2, r3]
	adds r0, r1
	movs r3, 0x6
	ldrsh r1, [r5, r3]
	movs r3, 0x2
	ldrsh r2, [r2, r3]
	adds r1, r2
	bl GetMapTileAtPosition
	adds r4, r0, 0
	ldrh r1, [r4]
	movs r0, 0x10
	ands r0, r1
	cmp r0, 0
	bne _08071130
	ldr r0, [r4, 0x10]
	cmp r0, 0
	beq _080710AE
	bl GetEntityType
	cmp r0, 0x1
	beq _080710AE
	ldr r0, [r4, 0x10]
	ldr r0, [r0, 0x70]
	ldrb r0, [r0, 0x6]
	cmp r0, 0
	bne _08071130
_080710AE:
	bl IsFixedDungeon
	lsls r0, 24
	cmp r0, 0
	bne _08071100
	ldr r0, [r5, 0x70]
	adds r0, 0xE4
	ldrb r0, [r0]
	cmp r0, 0x3
	beq _080710D0
	adds r0, r5, 0
	movs r1, 0x9
	bl HasItem
	lsls r0, 24
	cmp r0, 0
	beq _080710D8
_080710D0:
	movs r6, 0x3
	b _08071100
	.align 2, 0
_080710D4: .4byte gAdjacentTileOffsets
_080710D8:
	adds r0, r5, 0
	movs r1, 0xC
	bl HasIQSkill
	lsls r0, 24
	cmp r0, 0
	bne _080710FE
	adds r0, r5, 0
	movs r1, 0xD
	bl HasIQSkill
	lsls r0, 24
	cmp r0, 0
	beq _08071100
	movs r0, 0x1
	ands r0, r7
	movs r6, 0x3
	cmp r0, 0
	beq _08071100
_080710FE:
	movs r6, 0x2
_08071100:
	movs r1, 0x4
	ldrsh r0, [r5, r1]
	movs r2, 0x6
	ldrsh r1, [r5, r2]
	bl GetMapTileAtPosition
	adds r4, r0, 0
	adds r1, r4, 0
	adds r1, 0xA
	adds r1, r6
	ldr r2, _0807112C
	movs r0, 0x7
	ands r0, r7
	adds r0, r2
	ldrb r1, [r1]
	ldrb r0, [r0]
	ands r0, r1
	cmp r0, 0
	beq _08071130
	movs r0, 0x1
	b _08071132
	.align 2, 0
_0807112C: .4byte gUnknown_8106FCD
_08071130:
	movs r0, 0
_08071132:
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_8071058

	thumb_func_start CanAttackInFront
CanAttackInFront:
	push {r4-r6,lr}
	adds r4, r0, 0
	adds r6, r1, 0
	ldr r0, [r4, 0x70]
	movs r1, 0x2
	ldrsh r0, [r0, r1]
	bl GetCrossableTerrain
	lsls r0, 24
	lsrs r5, r0, 24
	cmp r5, 0x1
	bhi _08071152
	movs r5, 0x2
_08071152:
	movs r2, 0x4
	ldrsh r0, [r4, r2]
	ldr r1, _080711B0
	lsls r2, r6, 2
	adds r2, r1
	movs r3, 0
	ldrsh r1, [r2, r3]
	adds r0, r1
	movs r3, 0x6
	ldrsh r1, [r4, r3]
	movs r3, 0x2
	ldrsh r2, [r2, r3]
	adds r1, r2
	bl GetMapTileAtPosition
	adds r2, r0, 0
	ldrh r1, [r2]
	movs r0, 0x10
	ands r0, r1
	cmp r0, 0
	bne _0807120C
	ldr r0, [r2, 0x10]
	cmp r0, 0
	beq _0807118A
	bl GetEntityType
	cmp r0, 0x1
	bne _0807120C
_0807118A:
	bl IsFixedDungeon
	lsls r0, 24
	cmp r0, 0
	bne _080711DC
	ldr r0, [r4, 0x70]
	adds r0, 0xE4
	ldrb r0, [r0]
	cmp r0, 0x3
	beq _080711AC
	adds r0, r4, 0
	movs r1, 0x9
	bl HasItem
	lsls r0, 24
	cmp r0, 0
	beq _080711B4
_080711AC:
	movs r5, 0x3
	b _080711DC
	.align 2, 0
_080711B0: .4byte gAdjacentTileOffsets
_080711B4:
	adds r0, r4, 0
	movs r1, 0xC
	bl HasIQSkill
	lsls r0, 24
	cmp r0, 0
	bne _080711DA
	adds r0, r4, 0
	movs r1, 0xD
	bl HasIQSkill
	lsls r0, 24
	cmp r0, 0
	beq _080711DC
	movs r0, 0x1
	ands r0, r6
	movs r5, 0x3
	cmp r0, 0
	beq _080711DC
_080711DA:
	movs r5, 0x2
_080711DC:
	movs r1, 0x4
	ldrsh r0, [r4, r1]
	movs r2, 0x6
	ldrsh r1, [r4, r2]
	bl GetMapTileAtPosition
	adds r2, r0, 0
	adds r1, r2, 0
	adds r1, 0xA
	adds r1, r5
	ldr r2, _08071208
	movs r0, 0x7
	ands r0, r6
	adds r0, r2
	ldrb r1, [r1]
	ldrb r0, [r0]
	ands r0, r1
	cmp r0, 0
	beq _0807120C
	movs r0, 0x1
	b _0807120E
	.align 2, 0
_08071208: .4byte gDirectionBitMasks_2
_0807120C:
	movs r0, 0
_0807120E:
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end CanAttackInFront

	thumb_func_start CanMoveForward
CanMoveForward:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	adds r4, r0, 0
	adds r7, r1, 0
	mov r8, r2
	ldr r0, [r4, 0x70]
	movs r1, 0x2
	ldrsh r0, [r0, r1]
	bl GetCrossableTerrain
	lsls r0, 24
	lsrs r6, r0, 24
	movs r0, 0
	mov r2, r8
	strb r0, [r2]
	movs r3, 0x4
	ldrsh r0, [r4, r3]
	ldr r1, _0807130C
	lsls r2, r7, 2
	adds r2, r1
	movs r3, 0
	ldrsh r1, [r2, r3]
	adds r0, r1
	movs r3, 0x6
	ldrsh r1, [r4, r3]
	movs r3, 0x2
	ldrsh r2, [r2, r3]
	adds r1, r2
	bl GetMapTileAtPosition
	adds r5, r0, 0
	ldrh r1, [r5]
	movs r0, 0x10
	ands r0, r1
	cmp r0, 0
	beq _08071260
	b _0807137E
_08071260:
	movs r0, 0x40
	ands r0, r1
	cmp r0, 0
	beq _08071286
	ldr r0, _08071310
	ldr r0, [r0]
	ldr r1, _08071314
	adds r0, r1
	ldrb r0, [r0]
	cmp r0, 0
	bne _08071286
	adds r0, r4, 0
	movs r1, 0xF
	bl HasIQSkill
	lsls r0, 24
	cmp r0, 0
	beq _08071286
	b _0807137E
_08071286:
	ldr r0, [r5, 0x14]
	cmp r0, 0
	beq _080712B8
	adds r0, r4, 0
	movs r1, 0xE
	bl HasIQSkill
	lsls r0, 24
	cmp r0, 0
	beq _080712B8
	ldr r0, [r5, 0x14]
	bl GetEntityType
	cmp r0, 0x2
	bne _080712B8
	ldr r0, [r5, 0x14]
	adds r0, 0x20
	ldrb r0, [r0]
	cmp r0, 0
	bne _0807137E
	ldr r0, [r4, 0x70]
	adds r0, 0xE8
	ldrb r0, [r0]
	cmp r0, 0x3
	beq _0807137E
_080712B8:
	ldrh r1, [r5]
	movs r0, 0x3
	ands r0, r1
	cmp r0, 0x2
	bne _080712E6
	ldr r1, _08071318
	ldr r0, _08071310
	ldr r0, [r0]
	ldr r2, _0807131C
	adds r0, r2
	movs r3, 0
	ldrsh r0, [r0, r3]
	adds r0, r1
	ldrb r0, [r0]
	cmp r0, 0x1
	bne _080712E6
	adds r0, r4, 0
	movs r1, 0x14
	bl HasIQSkill
	lsls r0, 24
	cmp r0, 0
	bne _0807137E
_080712E6:
	bl IsFixedDungeon
	lsls r0, 24
	cmp r0, 0
	bne _08071348
	ldr r0, [r4, 0x70]
	adds r0, 0xE4
	ldrb r0, [r0]
	cmp r0, 0x3
	beq _08071308
	adds r0, r4, 0
	movs r1, 0x9
	bl HasItem
	lsls r0, 24
	cmp r0, 0
	beq _08071320
_08071308:
	movs r6, 0x3
	b _08071348
	.align 2, 0
_0807130C: .4byte gAdjacentTileOffsets
_08071310: .4byte gDungeonGlobalData
_08071314: .4byte 0x00000671
_08071318: .4byte gDungeonWaterType
_0807131C: .4byte 0x00003a0e
_08071320:
	adds r0, r4, 0
	movs r1, 0xC
	bl HasIQSkill
	lsls r0, 24
	cmp r0, 0
	bne _08071346
	adds r0, r4, 0
	movs r1, 0xD
	bl HasIQSkill
	lsls r0, 24
	cmp r0, 0
	beq _08071348
	movs r0, 0x1
	ands r0, r7
	movs r6, 0x3
	cmp r0, 0
	beq _08071348
_08071346:
	movs r6, 0x2
_08071348:
	movs r1, 0x4
	ldrsh r0, [r4, r1]
	movs r2, 0x6
	ldrsh r1, [r4, r2]
	bl GetMapTileAtPosition
	adds r0, 0xA
	adds r0, r6
	ldr r2, _08071374
	movs r1, 0x7
	ands r1, r7
	adds r1, r2
	ldrb r2, [r0]
	ldrb r0, [r1]
	ands r0, r2
	cmp r0, 0
	beq _0807137E
	ldr r0, [r5, 0x10]
	cmp r0, 0
	bne _08071378
	movs r0, 0x1
	b _08071380
	.align 2, 0
_08071374: .4byte gDirectionBitMasks_3
_08071378:
	movs r0, 0x1
	mov r3, r8
	strb r0, [r3]
_0807137E:
	movs r0, 0
_08071380:
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end CanMoveForward

	thumb_func_start IsAtJunction
IsAtJunction:
	push {r4,r5,lr}
	adds r4, r0, 0
	ldr r0, [r4, 0x70]
	movs r1, 0x2
	ldrsh r0, [r0, r1]
	bl GetCrossableTerrain
	lsls r0, 24
	lsrs r5, r0, 24
	bl IsFixedDungeon
	lsls r0, 24
	cmp r0, 0
	bne _080713E2
	ldr r0, [r4, 0x70]
	adds r0, 0xE4
	ldrb r0, [r0]
	cmp r0, 0x3
	beq _080713E0
	adds r0, r4, 0
	movs r1, 0x9
	bl HasItem
	lsls r0, 24
	cmp r0, 0
	bne _080713E0
	adds r0, r4, 0
	movs r1, 0xC
	bl HasIQSkill
	lsls r0, 24
	cmp r0, 0
	beq _080713D2
	movs r5, 0x2
	b _080713E2
_080713D2:
	adds r0, r4, 0
	movs r1, 0xD
	bl HasIQSkill
	lsls r0, 24
	cmp r0, 0
	beq _080713E2
_080713E0:
	movs r5, 0x3
_080713E2:
	cmp r5, 0x3
	bne _08071408
	ldr r4, [r4, 0x70]
	movs r0, 0x64
	bl DungeonRandomCapped
	movs r1, 0xFD
	lsls r1, 1
	adds r2, r4, r1
	ldrh r1, [r2]
	adds r1, r0
	strh r1, [r2]
	lsls r1, 16
	asrs r1, 16
	cmp r1, 0xC7
	ble _08071458
	movs r0, 0
	strh r0, [r2]
	b _08071468
_08071408:
	ldr r1, _0807145C
	ldr r0, _08071460
	ldr r0, [r0]
	ldr r2, _08071464
	adds r0, r2
	movs r2, 0
	ldrsh r0, [r0, r2]
	adds r0, r1
	ldrb r0, [r0]
	cmp r0, 0x1
	bne _08071432
	cmp r5, 0x1
	bne _08071432
	adds r0, r4, 0
	movs r1, 0x14
	bl HasIQSkill
	lsls r0, 24
	cmp r0, 0
	beq _08071432
	movs r5, 0
_08071432:
	movs r1, 0x4
	ldrsh r0, [r4, r1]
	movs r2, 0x6
	ldrsh r1, [r4, r2]
	bl GetMapTileAtPosition
	adds r0, 0xA
	adds r0, r5
	ldrb r0, [r0]
	cmp r0, 0x54
	beq _08071468
	cmp r0, 0x51
	beq _08071468
	cmp r0, 0x45
	beq _08071468
	cmp r0, 0x15
	beq _08071468
	cmp r0, 0x55
	beq _08071468
_08071458:
	movs r0, 0
	b _0807146A
	.align 2, 0
_0807145C: .4byte gDungeonWaterType
_08071460: .4byte gDungeonGlobalData
_08071464: .4byte 0x00003a0e
_08071468:
	movs r0, 0x1
_0807146A:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end IsAtJunction

	thumb_func_start ShouldAvoidFirstHit
ShouldAvoidFirstHit:
	push {r4,lr}
	lsls r1, 24
	lsrs r4, r1, 24
	movs r1, 0x3
	bl HasTactic
	lsls r0, 24
	cmp r0, 0
	beq _0807148A
	cmp r4, 0
	beq _0807148A
	movs r0, 0x1
	b _0807148C
_0807148A:
	movs r0, 0
_0807148C:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end ShouldAvoidFirstHit

	.align 2, 0
