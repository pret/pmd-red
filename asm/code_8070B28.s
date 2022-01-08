	#include "asm/constants/gba_constants.inc"
  	#include "asm/macros.inc"

  	.syntax unified

  	.text
  
	thumb_func_start IsSleeping
IsSleeping:
	push {lr}
	ldr r0, [r0, 0x70]
	adds r0, 0xA8
	ldrb r0, [r0]
	cmp r0, 0x1
	beq _08070B40
	cmp r0, 0x5
	beq _08070B40
	cmp r0, 0x3
	beq _08070B40
	movs r0, 0
	b _08070B42
_08070B40:
	movs r0, 0x1
_08070B42:
	pop {r1}
	bx r1
	thumb_func_end IsSleeping

	thumb_func_start HasQuarterHPOrLess
HasQuarterHPOrLess:
	push {lr}
	ldr r0, [r0, 0x70]
	adds r1, r0, 0
	movs r2, 0x10
	ldrsh r0, [r1, r2]
	cmp r0, 0
	bge _08070B58
	adds r0, 0x3
_08070B58:
	movs r2, 0xE
	ldrsh r1, [r1, r2]
	asrs r0, 2
	cmp r1, r0
	ble _08070B66
	movs r0, 0
	b _08070B68
_08070B66:
	movs r0, 0x1
_08070B68:
	pop {r1}
	bx r1
	thumb_func_end HasQuarterHPOrLess

	.align 2, 0
