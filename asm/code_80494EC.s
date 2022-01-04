	#include "asm/constants/gba_constants.inc"
  	#include "asm/macros.inc"

  	.syntax unified

  	.text
  
	thumb_func_start CanTargetAdjacentPokemon
CanTargetAdjacentPokemon:
	push {r4-r6,lr}
	adds r5, r0, 0
	movs r6, 0
_080494F2:
	movs r1, 0x4
	ldrsh r0, [r5, r1]
	ldr r1, _08049538
	lsls r2, r6, 2
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
	ldr r4, [r0, 0x10]
	cmp r4, 0
	beq _0804953C
	adds r0, r4, 0
	bl GetEntityType
	cmp r0, 0
	beq _0804953C
	adds r0, r5, 0
	adds r1, r4, 0
	movs r2, 0
	movs r3, 0x1
	bl CanTarget
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _0804953C
	movs r0, 0x1
	b _08049544
	.align 2, 0
_08049538: .4byte gAdjacentTileOffsets
_0804953C:
	adds r6, 0x1
	cmp r6, 0x7
	ble _080494F2
	movs r0, 0
_08049544:
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end CanTargetAdjacentPokemon

	.align 2, 0