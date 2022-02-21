	#include "asm/constants/gba_constants.inc"
  	#include "asm/macros.inc"

  	.syntax unified

  	.text

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
	bl GetMapTile_1
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
	bl GetMapTile_1
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
	bl GetMapTile_1
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
	bl GetMapTile_1
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
	bl GetMapTile_1
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
	bl GetMapTile_1
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
	bl GetMapTile_1
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
	bl GetMapTile_1
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

	.align 2, 0