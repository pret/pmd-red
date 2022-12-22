	#include "asm/constants/gba_constants.inc"
  	#include "asm/macros.inc"

  	.syntax unified

  	.text

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

	.align 2, 0
