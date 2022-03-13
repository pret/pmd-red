	#include "asm/constants/gba_constants.inc"
  	#include "asm/macros.inc"

  	.syntax unified

  	.text
  
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
