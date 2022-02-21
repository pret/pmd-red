	#include "asm/constants/gba_constants.inc"
  	#include "asm/macros.inc"

  	.syntax unified

  	.text
  
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
	bl GetMapTile_1
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
	bl GetMapTile_1
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
	bl GetMapTile_1
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

	.align 2, 0
