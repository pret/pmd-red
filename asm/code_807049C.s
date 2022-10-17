	#include "asm/constants/gba_constants.inc"
  	#include "asm/macros.inc"

  	.syntax unified

  	.text
  
	thumb_func_start sub_807049C
sub_807049C:
	push {r4-r7,lr}
	adds r6, r0, 0
	adds r4, r1, 0
	ldr r7, [r6, 0x70]
	movs r1, 0
	ldrsh r0, [r4, r1]
	movs r2, 0x2
	ldrsh r1, [r4, r2]
	bl GetMapTile_1
	adds r5, r0, 0
	movs r1, 0
	ldrsh r0, [r4, r1]
	cmp r0, 0
	blt _0807055A
	movs r2, 0x2
	ldrsh r1, [r4, r2]
	cmp r1, 0
	blt _0807055A
	cmp r0, 0x37
	bgt _0807055A
	cmp r1, 0x1F
	bgt _0807055A
	ldrh r1, [r5]
	movs r0, 0x10
	ands r0, r1
	cmp r0, 0
	bne _0807055A
	ldr r0, [r5, 0x10]
	cmp r0, 0
	beq _080704E2
	bl GetEntityType
	cmp r0, 0x1
	bne _0807055A
_080704E2:
	bl IsFixedDungeon
	lsls r0, 24
	cmp r0, 0
	bne _08070504
	adds r0, r7, 0
	adds r0, 0xE4
	ldrb r0, [r0]
	cmp r0, 0x3
	beq _08070552
	adds r0, r6, 0
	movs r1, 0x9
	bl HasItem
	lsls r0, 24
	cmp r0, 0
	bne _08070552
_08070504:
	movs r1, 0x2
	ldrsh r0, [r7, r1]
	bl GetCrossableTerrain
	lsls r0, 24
	lsrs r4, r0, 24
	ldrh r0, [r5]
	movs r5, 0x3
	ands r5, r0
	adds r0, r6, 0
	movs r1, 0xC
	bl HasIQSkill
	lsls r0, 24
	cmp r0, 0
	beq _08070526
	movs r4, 0x2
_08070526:
	adds r0, r6, 0
	movs r1, 0xD
	bl HasIQSkill
	lsls r0, 24
	cmp r0, 0
	beq _08070536
	movs r4, 0x3
_08070536:
	cmp r4, 0x1
	beq _0807054A
	cmp r4, 0x1
	bgt _08070544
	cmp r4, 0
	beq _0807054E
	b _08070552
_08070544:
	cmp r4, 0x2
	beq _08070556
	b _08070552
_0807054A:
	cmp r5, 0x2
	beq _08070552
_0807054E:
	cmp r5, 0x1
	bne _0807055A
_08070552:
	movs r0, 0
	b _0807055C
_08070556:
	cmp r5, 0
	bne _08070552
_0807055A:
	movs r0, 0x1
_0807055C:
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_807049C

	thumb_func_start sub_8070564
sub_8070564:
	push {r4-r6,lr}
	adds r4, r1, 0
	ldr r6, [r0, 0x70]
	movs r1, 0
	ldrsh r0, [r4, r1]
	movs r2, 0x2
	ldrsh r1, [r4, r2]
	bl GetMapTile_1
	adds r5, r0, 0
	movs r1, 0
	ldrsh r0, [r4, r1]
	cmp r0, 0
	blt _080705E6
	movs r2, 0x2
	ldrsh r1, [r4, r2]
	cmp r1, 0
	blt _080705E6
	cmp r0, 0x37
	bgt _080705E6
	cmp r1, 0x1F
	bgt _080705E6
	ldrh r1, [r5]
	movs r0, 0x10
	ands r0, r1
	cmp r0, 0
	bne _080705E6
	ldr r0, [r5, 0x10]
	cmp r0, 0
	beq _080705A8
	bl GetEntityType
	cmp r0, 0x1
	bne _080705E6
_080705A8:
	movs r1, 0x2
	ldrsh r0, [r6, r1]
	bl GetCrossableTerrain
	lsls r0, 24
	lsrs r2, r0, 24
	adds r3, r2, 0
	ldrh r0, [r5]
	movs r1, 0x3
	ands r1, r0
	adds r0, r1, 0
	cmp r2, 0x1
	beq _080705DE
	cmp r2, 0x1
	bgt _080705CC
	cmp r2, 0
	beq _080705D8
	b _080705D4
_080705CC:
	cmp r3, 0x3
	bgt _080705D4
	cmp r1, 0
	beq _080705E6
_080705D4:
	movs r0, 0
	b _080705E8
_080705D8:
	cmp r1, 0x1
	bne _080705E6
	b _080705D4
_080705DE:
	cmp r1, 0x2
	beq _080705D4
	cmp r0, 0x1
	beq _080705D4
_080705E6:
	movs r0, 0x1
_080705E8:
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end sub_8070564

	thumb_func_start sub_80705F0
sub_80705F0:
	push {r4-r7,lr}
	adds r6, r0, 0
	adds r4, r1, 0
	ldr r7, [r6, 0x70]
	movs r1, 0
	ldrsh r0, [r4, r1]
	movs r2, 0x2
	ldrsh r1, [r4, r2]
	bl GetMapTile_1
	adds r5, r0, 0
	movs r1, 0
	ldrsh r0, [r4, r1]
	cmp r0, 0
	blt _0807069A
	movs r2, 0x2
	ldrsh r1, [r4, r2]
	cmp r1, 0
	blt _0807069A
	cmp r0, 0x37
	bgt _0807069A
	cmp r1, 0x1F
	bgt _0807069A
	ldrh r1, [r5]
	movs r0, 0x10
	ands r0, r1
	cmp r0, 0
	bne _0807069A
	ldr r0, [r5, 0x10]
	cmp r0, 0
	beq _08070636
	bl GetEntityType
	cmp r0, 0x1
	bne _0807069A
_08070636:
	bl IsFixedDungeon
	lsls r0, 24
	cmp r0, 0
	bne _08070658
	adds r0, r7, 0
	adds r0, 0xE4
	ldrb r0, [r0]
	cmp r0, 0x3
	beq _08070696
	adds r0, r6, 0
	movs r1, 0x9
	bl HasItem
	lsls r0, 24
	cmp r0, 0
	bne _08070696
_08070658:
	movs r1, 0x2
	ldrsh r0, [r7, r1]
	bl GetCrossableTerrain
	lsls r0, 24
	lsrs r4, r0, 24
	ldrh r0, [r5]
	movs r5, 0x3
	ands r5, r0
	adds r0, r6, 0
	movs r1, 0xC
	bl HasIQSkill
	lsls r0, 24
	cmp r0, 0
	beq _0807067A
	movs r4, 0x2
_0807067A:
	adds r0, r6, 0
	movs r1, 0xD
	bl HasIQSkill
	lsls r0, 24
	cmp r0, 0
	beq _0807068A
	movs r4, 0x3
_0807068A:
	cmp r4, 0
	blt _08070696
	cmp r4, 0x2
	bgt _08070696
	cmp r5, 0
	beq _0807069A
_08070696:
	movs r0, 0
	b _0807069C
_0807069A:
	movs r0, 0x1
_0807069C:
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_80705F0

	thumb_func_start sub_80706A4
sub_80706A4:
	push {r4-r7,lr}
	adds r7, r0, 0
	adds r4, r1, 0
	ldr r6, [r7, 0x70]
	movs r1, 0
	ldrsh r0, [r4, r1]
	movs r2, 0x2
	ldrsh r1, [r4, r2]
	bl GetMapTile_1
	adds r5, r0, 0
	movs r1, 0
	ldrsh r0, [r4, r1]
	cmp r0, 0
	blt _0807076A
	movs r2, 0x2
	ldrsh r1, [r4, r2]
	cmp r1, 0
	blt _0807076A
	cmp r0, 0x37
	bgt _0807076A
	cmp r1, 0x1F
	bgt _0807076A
	ldrh r1, [r5]
	movs r0, 0x10
	ands r0, r1
	cmp r0, 0
	bne _0807076A
	ldr r0, [r5, 0x10]
	cmp r0, 0
	beq _080706F2
	bl GetEntityType
	cmp r0, 0x1
	bne _0807076A
	ldr r0, [r5, 0x10]
	ldr r0, [r0, 0x70]
	cmp r0, r6
	bne _0807076A
_080706F2:
	bl IsFixedDungeon
	lsls r0, 24
	cmp r0, 0
	bne _08070714
	adds r0, r6, 0
	adds r0, 0xE4
	ldrb r0, [r0]
	cmp r0, 0x3
	beq _08070762
	adds r0, r7, 0
	movs r1, 0x9
	bl HasItem
	lsls r0, 24
	cmp r0, 0
	bne _08070762
_08070714:
	movs r1, 0x2
	ldrsh r0, [r6, r1]
	bl GetCrossableTerrain
	lsls r0, 24
	lsrs r4, r0, 24
	ldrh r0, [r5]
	movs r5, 0x3
	ands r5, r0
	adds r0, r7, 0
	movs r1, 0xC
	bl HasIQSkill
	lsls r0, 24
	cmp r0, 0
	beq _08070736
	movs r4, 0x2
_08070736:
	adds r0, r7, 0
	movs r1, 0xD
	bl HasIQSkill
	lsls r0, 24
	cmp r0, 0
	beq _08070746
	movs r4, 0x3
_08070746:
	cmp r4, 0x1
	beq _0807075A
	cmp r4, 0x1
	bgt _08070754
	cmp r4, 0
	beq _0807075E
	b _08070762
_08070754:
	cmp r4, 0x2
	beq _08070766
	b _08070762
_0807075A:
	cmp r5, 0x2
	beq _08070762
_0807075E:
	cmp r5, 0x1
	bne _0807076A
_08070762:
	movs r0, 0
	b _0807076C
_08070766:
	cmp r5, 0
	bne _08070762
_0807076A:
	movs r0, 0x1
_0807076C:
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_80706A4

	thumb_func_start GetMovementSpeed
GetMovementSpeed:
	push {r4-r6,lr}
	adds r6, r0, 0
	ldr r5, [r6, 0x70]
	movs r4, 0
	movs r0, 0x84
	lsls r0, 1
	adds r1, r5, r0
	movs r2, 0x4
_08070784:
	ldrb r0, [r1, 0x5]
	cmp r0, 0
	beq _0807078C
	subs r4, 0x1
_0807078C:
	ldrb r0, [r1]
	cmp r0, 0
	beq _08070794
	adds r4, 0x1
_08070794:
	adds r1, 0x1
	subs r2, 0x1
	cmp r2, 0
	bge _08070784
	adds r0, r5, 0
	adds r0, 0xAC
	ldrb r0, [r0]
	cmp r0, 0x4
	bne _080707A8
	subs r4, 0x1
_080707A8:
	movs r1, 0x2
	ldrsh r0, [r5, r1]
	bl GetMoveSpeed
	adds r4, r0
	adds r0, r6, 0
	movs r1, 0x6
	bl HasType
	lsls r0, 24
	cmp r0, 0
	beq _080707D0
	adds r0, r6, 0
	bl GetWeather
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x7
	bne _080707D0
	adds r4, 0x1
_080707D0:
	movs r0, 0x4
	ldrsh r1, [r5, r0]
	ldr r0, _0807081C
	cmp r1, r0
	bne _080707DC
	adds r4, 0x1
_080707DC:
	movs r0, 0x2
	ldrsh r1, [r5, r0]
	movs r0, 0xBE
	lsls r0, 1
	cmp r1, r0
	bne _080707FE
	ldrb r0, [r5, 0x6]
	cmp r0, 0
	beq _080707FE
	ldr r0, _08070820
	ldr r0, [r0]
	ldr r1, _08070824
	adds r0, r1
	ldrb r0, [r0]
	cmp r0, 0
	beq _080707FE
	adds r4, 0x1
_080707FE:
	cmp r4, 0
	bge _08070804
	movs r4, 0
_08070804:
	cmp r4, 0x4
	ble _0807080A
	movs r4, 0x4
_0807080A:
	movs r1, 0x82
	lsls r1, 1
	adds r0, r5, r1
	str r4, [r0]
	adds r0, r4, 0
	pop {r4-r6}
	pop {r1}
	bx r1
	.align 2, 0
_0807081C: .4byte 0x000001a3
_08070820: .4byte gDungeonGlobalData
_08070824: .4byte 0x0000066e
	thumb_func_end GetMovementSpeed

	.align 2, 0
