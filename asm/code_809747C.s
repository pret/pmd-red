	.include "constants/gba_constants.inc"
	.include "asm/macros.inc"

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

	thumb_func_start sub_80975C4
sub_80975C4:
	push {lr}
	lsls r0, 16
	asrs r0, 16
	bl sub_80A2728
	lsls r0, 24
	lsrs r0, 24
	bl GetDungeonName1
	pop {r1}
	bx r1
	thumb_func_end sub_80975C4

	thumb_func_start sub_80975DC
sub_80975DC:
	push {lr}
	lsls r0, 16
	ldr r1, _08097600
	adds r0, r1
	lsrs r0, 16
	cmp r0, 0x1
	bhi _08097610
	movs r2, 0x1
	negs r2, r2
	movs r0, 0x3
	movs r1, 0xE
	bl sub_8001D08
	lsls r0, 24
	cmp r0, 0
	beq _08097608
	ldr r0, _08097604
	b _08097612
	.align 2, 0
_08097600: .4byte 0xffe90000
_08097604: .4byte gMeetNinetalesText
_08097608:
	ldr r0, _0809760C
	b _08097612
	.align 2, 0
_0809760C: .4byte gAvoidCaptureText
_08097610:
	ldr r0, _08097618
_08097612:
	pop {r1}
	bx r1
	.align 2, 0
_08097618: .4byte gFinalScenarioText
	thumb_func_end sub_80975DC

	thumb_func_start sub_809761C
sub_809761C:
	push {r4,lr}
	movs r4, 0
_08097620:
	lsls r0, r4, 16
	asrs r0, 16
	bl sub_809758C
	lsls r0, 24
	cmp r0, 0
	bne _08097632
	movs r0, 0
	b _0809763A
_08097632:
	adds r4, 0x1
	cmp r4, 0x10
	ble _08097620
	movs r0, 0x1
_0809763A:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_809761C

	thumb_func_start sub_8097640
sub_8097640:
	push {lr}
	movs r0, 0
	movs r1, 0x2E
	movs r2, 0x1F
	bl sub_8001784
	cmp r0, 0
	bne _0809766A
	bl sub_809761C
	lsls r0, 24
	cmp r0, 0
	beq _0809766A
	movs r0, 0
	movs r1, 0x2E
	movs r2, 0x1F
	movs r3, 0x1
	bl sub_800199C
	movs r0, 0x1
	b _0809766C
_0809766A:
	movs r0, 0
_0809766C:
	pop {r1}
	bx r1
	thumb_func_end sub_8097640

        .align 2,0

