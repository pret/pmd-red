	#include "asm/constants/gba_constants.inc"
  	#include "asm/macros.inc"

  	.syntax unified

  	.text

	thumb_func_start sub_807034C
sub_807034C:
	push {r4,lr}
	adds r4, r1, 0
	lsls r0, 16
	asrs r2, r0, 16
	ldr r0, [r4, 0x10]
	cmp r0, 0
	bne _08070398
	ldrh r1, [r4]
	movs r0, 0x10
	ands r0, r1
	cmp r0, 0
	bne _08070398
	adds r0, r2, 0
	bl GetCrossableTerrain
	lsls r0, 24
	lsrs r2, r0, 24
	ldrh r0, [r4]
	movs r1, 0x3
	ands r1, r0
	cmp r2, 0x1
	beq _08070388
	cmp r2, 0x1
	bgt _08070382
	cmp r2, 0
	beq _0807038C
	b _08070390
_08070382:
	cmp r2, 0x2
	beq _08070394
	b _08070390
_08070388:
	cmp r1, 0x2
	beq _08070390
_0807038C:
	cmp r1, 0x1
	bne _08070398
_08070390:
	movs r0, 0
	b _0807039A
_08070394:
	cmp r1, 0
	bne _08070390
_08070398:
	movs r0, 0x1
_0807039A:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_807034C

	.align 2, 0
