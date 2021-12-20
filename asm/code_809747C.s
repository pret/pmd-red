	#include "asm/constants/gba_constants.inc"
	#include "asm/macros.inc"

	.syntax unified

	.text
	

	thumb_func_start sub_8097504
sub_8097504:
	push {lr}
	lsls r0, 16
	asrs r0, 16
	adds r1, r0, 0
	cmp r0, 0x10
	bgt _08097568
	cmp r0, 0xE
	bhi _08097580
	lsls r0, 2
	ldr r1, _08097520
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08097520: .4byte _08097524
	.align 2, 0
_08097524:
	.4byte _08097564
	.4byte _08097564
	.4byte _08097560
	.4byte _08097580
	.4byte _08097580
	.4byte _08097564
	.4byte _08097580
	.4byte _08097564
	.4byte _08097580
	.4byte _08097564
	.4byte _08097560
	.4byte _08097560
	.4byte _08097560
	.4byte _08097574
	.4byte _08097564
_08097560:
	movs r0, 0xE
	b _08097576
_08097564:
	movs r0, 0xF
	b _08097576
_08097568:
	cmp r1, 0x16
	bgt _08097584
	cmp r1, 0x16
	beq _08097584
	cmp r1, 0x15
	beq _08097584
_08097574:
	movs r0, 0x6
_08097576:
	bl sub_80023E4
	lsls r0, 24
	cmp r0, 0
	beq _08097584
_08097580:
	movs r0, 0x1
	b _08097586
_08097584:
	movs r0, 0
_08097586:
	pop {r1}
	bx r1
	thumb_func_end sub_8097504

	thumb_func_start sub_809758C
sub_809758C:
	push {lr}
	adds r2, r0, 0
	lsls r2, 16
	lsrs r2, 16
	movs r0, 0
	movs r1, 0x2E
	bl sub_8001784
	cmp r0, 0
	beq _080975A2
	movs r0, 0x1
_080975A2:
	pop {r1}
	bx r1
	thumb_func_end sub_809758C

	thumb_func_start sub_80975A8
sub_80975A8:
	push {lr}
	adds r2, r0, 0
	adds r3, r1, 0
	lsls r3, 24
	lsrs r3, 24
	lsls r2, 16
	lsrs r2, 16
	movs r0, 0
	movs r1, 0x2E
	bl sub_800199C
	pop {r0}
	bx r0
	thumb_func_end sub_80975A8

        .align 2,0

