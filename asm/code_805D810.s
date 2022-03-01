	#include "asm/constants/gba_constants.inc"
  	#include "asm/macros.inc"

  	.syntax unified

  	.text
  
	thumb_func_start HasDisabledMove
HasDisabledMove:
	push {r4-r6,lr}
	adds r4, r0, 0
	movs r3, 0
	movs r6, 0x1
	movs r5, 0x20
	adds r2, r4, 0
_0805D81C:
	ldrb r1, [r2]
	adds r0, r6, 0
	ands r0, r1
	cmp r0, 0
	beq _0805D82E
	adds r0, r5, 0
	ands r0, r1
	cmp r0, 0
	bne _0805D848
_0805D82E:
	adds r2, 0x8
	adds r3, 0x1
	cmp r3, 0x3
	ble _0805D81C
	adds r0, r4, 0
	adds r0, 0x20
	ldrb r1, [r0]
	movs r0, 0x20
	ands r0, r1
	cmp r0, 0
	bne _0805D848
	movs r0, 0
	b _0805D84A
_0805D848:
	movs r0, 0x1
_0805D84A:
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end HasDisabledMove

	thumb_func_start LastMoveOutOfPP
LastMoveOutOfPP:
	push {r4,r5,lr}
	movs r3, 0
	movs r5, 0x1
	adds r2, r0, 0
	movs r4, 0x10
_0805D85A:
	ldrb r1, [r2]
	adds r0, r5, 0
	ands r0, r1
	cmp r0, 0
	beq _0805D876
	adds r0, r4, 0
	ands r0, r1
	cmp r0, 0
	beq _0805D876
	ldrb r0, [r2, 0x4]
	cmp r0, 0
	bne _0805D876
	movs r0, 0x1
	b _0805D880
_0805D876:
	adds r2, 0x8
	adds r3, 0x1
	cmp r3, 0x3
	ble _0805D85A
	movs r0, 0
_0805D880:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end LastMoveOutOfPP

	.align 2, 0