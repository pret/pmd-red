	#include "asm/constants/gba_constants.inc"
  	#include "asm/macros.inc"

  	.syntax unified

  	.text

	thumb_func_start sub_806A338
sub_806A338:
	push {r4-r6,lr}
	movs r5, 0
	ldr r6, _0806A378
_0806A33E:
	ldr r0, [r6]
	lsls r1, r5, 2
	ldr r2, _0806A37C
	adds r0, r2
	adds r0, r1
	ldr r4, [r0]
	adds r0, r4, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	beq _0806A384
	ldr r0, [r4, 0x70]
	adds r0, 0xC8
	ldrb r0, [r0]
	cmp r0, 0x3
	bne _0806A384
	ldr r1, [r6]
	ldr r2, _0806A380
	adds r0, r1, r2
	str r4, [r0]
	ldr r0, [r4, 0x70]
	adds r2, 0xC
	adds r1, r2
	adds r0, 0x98
	ldr r0, [r0]
	str r0, [r1]
	b _0806A38A
	.align 2, 0
_0806A378: .4byte gDungeon
_0806A37C: .4byte 0x000135cc
_0806A380: .4byte 0x00017b30
_0806A384:
	adds r5, 0x1
	cmp r5, 0x13
	ble _0806A33E
_0806A38A:
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end sub_806A338

	thumb_func_start sub_806A390
sub_806A390:
	push {r4-r7,lr}
	ldr r0, [r0, 0x70]
	movs r7, 0
	movs r1, 0x8C
	lsls r1, 1
	adds r4, r0, r1
	adds r5, r4, 0
	movs r6, 0x3
_0806A3A0:
	ldrb r1, [r4]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _0806A3C2
	ldrb r1, [r4, 0x1]
	movs r0, 0xF7
	ands r0, r1
	movs r1, 0xEF
	ands r0, r1
	movs r1, 0x4
	orrs r0, r1
	strb r0, [r4, 0x1]
	adds r0, r5, 0
	bl GetMoveBasePP
	strb r0, [r4, 0x4]
_0806A3C2:
	adds r4, 0x8
	adds r5, 0x8
	subs r6, 0x1
	cmp r6, 0
	bge _0806A3A0
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_806A390

	thumb_func_start sub_806A3D4
sub_806A3D4:
	push {r4-r7,lr}
	sub sp, 0xC
	adds r7, r0, 0
	adds r6, r2, 0
	lsls r1, 16
	asrs r5, r1, 16
	lsls r3, 24
	cmp r3, 0
	beq _0806A404
	ldr r4, _0806A400
	adds r0, r5, 0
	movs r1, 0xA
	bl __divsi3
	adds r2, r0, 0
	lsls r2, 16
	asrs r2, 16
	mov r0, sp
	adds r1, r4, 0
	bl sprintf
	b _0806A41C
	.align 2, 0
_0806A400: .4byte gUnknown_8106EA8
_0806A404:
	ldr r4, _0806A450
	adds r0, r5, 0
	movs r1, 0xA
	bl __divsi3
	adds r2, r0, 0
	lsls r2, 16
	asrs r2, 16
	mov r0, sp
	adds r1, r4, 0
	bl sprintf
_0806A41C:
	ldr r1, _0806A454
	mov r0, sp
	bl OpenFileAndGetFileDataPtr
	adds r4, r0, 0
	adds r0, r5, 0
	movs r1, 0xA
	bl __modsi3
	lsls r0, 16
	ldr r1, [r4, 0x4]
	asrs r0, 12
	adds r0, r1
	lsls r1, r6, 2
	adds r0, r1
	ldr r1, [r0]
	adds r0, r7, 0
	bl strcpy
	adds r0, r4, 0
	bl CloseFile
	add sp, 0xC
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_0806A450: .4byte gUnknown_8106EB0
_0806A454: .4byte gDungeonFileArchive
	thumb_func_end sub_806A3D4

	thumb_func_start sub_806A458
sub_806A458:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	adds r6, r0, 0
	movs r0, 0
	mov r9, r0
	ldr r0, [r6, 0x70]
	ldrb r0, [r0, 0x6]
	mov r10, r0
	adds r0, r6, 0
	bl sub_80696A8
	cmp r0, 0
	bne _0806A47C
	movs r0, 0
	b _0806A4CC
_0806A47C:
	movs r7, 0x1
	negs r7, r7
_0806A480:
	movs r5, 0x1
	negs r5, r5
	adds r1, r7, 0x1
	mov r8, r1
_0806A488:
	movs r2, 0x4
	ldrsh r0, [r6, r2]
	adds r0, r5
	movs r2, 0x6
	ldrsh r1, [r6, r2]
	adds r1, r7
	bl GetTileSafe
	adds r4, r0, 0
	ldr r0, [r4, 0x10]
	cmp r0, 0
	beq _0806A4B6
	bl GetEntityType
	cmp r0, 0x1
	bne _0806A4B6
	ldr r0, [r4, 0x10]
	ldr r0, [r0, 0x70]
	ldrb r0, [r0, 0x6]
	cmp r0, r10
	beq _0806A4B6
	movs r0, 0x1
	add r9, r0
_0806A4B6:
	adds r5, 0x1
	cmp r5, 0x1
	ble _0806A488
	mov r7, r8
	cmp r7, 0x1
	ble _0806A480
	movs r0, 0
	mov r1, r9
	cmp r1, 0x1
	ble _0806A4CC
	movs r0, 0x1
_0806A4CC:
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_806A458

	thumb_func_start sub_806A4DC
sub_806A4DC:
	push {r4,lr}
	sub sp, 0x64
	adds r4, r0, 0
	ldr r1, _0806A530
	ldr r0, [sp, 0x60]
	ands r0, r1
	ldr r1, _0806A534
	ands r0, r1
	movs r1, 0x80
	lsls r1, 1
	orrs r0, r1
	str r0, [sp, 0x60]
	movs r0, 0x2
	ldrsh r1, [r4, r0]
	add r0, sp, 0x60
	str r0, [sp]
	movs r0, 0
	str r0, [sp, 0x4]
	add r0, sp, 0x8
	movs r2, 0
	movs r3, 0
	bl sub_808CFD0
	add r1, sp, 0x8
	ldrh r0, [r4, 0x2]
	strh r0, [r1, 0x8]
	ldrb r0, [r4, 0x9]
	strb r0, [r1, 0x3]
	ldrh r0, [r4, 0xC]
	strh r0, [r1, 0x14]
	ldrb r0, [r4, 0x14]
	strb r0, [r1, 0x18]
	ldrb r0, [r4, 0x16]
	strb r0, [r1, 0x1A]
	adds r0, r1, 0
	bl sub_808F700
	add sp, 0x64
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_0806A530: .4byte 0xffffff00
_0806A534: .4byte 0xffff00ff
	thumb_func_end sub_806A4DC

	thumb_func_start sub_806A538
sub_806A538:
	push {lr}
	lsls r0, 16
	asrs r1, r0, 16
	adds r2, r1, 0
	ldr r0, _0806A554
	cmp r1, r0
	beq _0806A550
	ldr r0, _0806A558
	cmp r1, r0
	beq _0806A550
	cmp r2, 0
	bge _0806A55C
_0806A550:
	movs r0, 0x1
	b _0806A55E
	.align 2, 0
_0806A554: .4byte 0x000055aa
_0806A558: .4byte 0x00005aa5
_0806A55C:
	movs r0, 0
_0806A55E:
	pop {r1}
	bx r1
	thumb_func_end sub_806A538

	thumb_func_start sub_806A564
sub_806A564:
	push {lr}
	lsls r0, 16
	asrs r1, r0, 16
	ldr r0, _0806A57C
	cmp r1, r0
	beq _0806A584
	ldr r0, _0806A580
	cmp r1, r0
	beq _0806A584
	movs r0, 0
	b _0806A586
	.align 2, 0
_0806A57C: .4byte 0x000055aa
_0806A580: .4byte 0x00005aa5
_0806A584:
	movs r0, 0x1
_0806A586:
	pop {r1}
	bx r1
	thumb_func_end sub_806A564

	thumb_func_start sub_806A58C
sub_806A58C:
	push {lr}
	lsls r0, 16
	movs r1, 0xCE
	lsls r1, 17
	cmp r0, r1
	bls _0806A59C
	movs r0, 0
	b _0806A59E
_0806A59C:
	movs r0, 0x1
_0806A59E:
	pop {r1}
	bx r1
	thumb_func_end sub_806A58C

	thumb_func_start sub_806A5A4
sub_806A5A4:
	push {lr}
	lsls r0, 16
	cmp r0, 0
	blt _0806A5B0
	movs r0, 0
	b _0806A5B2
_0806A5B0:
	movs r0, 0x1
_0806A5B2:
	pop {r1}
	bx r1
	thumb_func_end sub_806A5A4

	thumb_func_start sub_806A5B8
sub_806A5B8:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0x4
	adds r6, r0, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	bne _0806A5CE
	b _0806A6D2
_0806A5CE:
	adds r0, r6, 0
	bl GetTileAtEntitySafe
	ldrh r0, [r0]
	movs r1, 0x3
	ands r1, r0
	cmp r1, 0x2
	bne _0806A664
	ldr r4, [r6, 0x70]
	ldr r1, _0806A640
	ldr r0, _0806A644
	ldr r0, [r0]
	ldr r2, _0806A648
	adds r0, r2
	movs r2, 0
	ldrsh r0, [r0, r2]
	adds r0, r1
	ldrb r0, [r0]
	cmp r0, 0x1
	bne _0806A650
	adds r0, r4, 0
	adds r0, 0xB0
	ldrb r0, [r0]
	cmp r0, 0x1
	bne _0806A608
	adds r0, r6, 0
	adds r1, r6, 0
	bl SendImmobilizeEndMessage
_0806A608:
	movs r1, 0x2
	ldrsh r0, [r4, r1]
	bl GetMovementType
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x4
	beq _0806A6D2
	movs r2, 0x2
	ldrsh r1, [r4, r2]
	ldr r0, _0806A64C
	cmp r1, r0
	beq _0806A6D2
	cmp r1, 0x92
	beq _0806A6D2
	adds r0, r4, 0
	adds r0, 0xAC
	ldrb r0, [r0]
	cmp r0, 0x1
	beq _0806A6D2
	adds r0, r6, 0
	adds r1, r6, 0
	movs r2, 0x1
	movs r3, 0
	bl BurnedStatusTarget
	b _0806A6D2
	.align 2, 0
_0806A640: .4byte gDungeonWaterType
_0806A644: .4byte gDungeon
_0806A648: .4byte 0x00003a0e
_0806A64C: .4byte 0x00000113
_0806A650:
	adds r0, r4, 0
	adds r0, 0xAC
	ldrb r0, [r0]
	cmp r0, 0x1
	bne _0806A6D2
	adds r0, r6, 0
	adds r1, r6, 0
	bl SendNonVolatileEndMessage
	b _0806A6D2
_0806A664:
	cmp r1, 0
	bne _0806A6D2
	ldr r7, [r6, 0x70]
	ldrb r0, [r7, 0x7]
	cmp r0, 0
	beq _0806A6D2
	movs r0, 0x9E
	lsls r0, 1
	adds r4, r7, r0
	ldr r5, [r4]
	mov r0, sp
	adds r1, r5, 0
	movs r2, 0x5
	bl FixedPoint_Subtract
	ldr r0, [sp]
	str r0, [r4]
	movs r1, 0
	mov r8, r1
	adds r0, r5, 0
	bl FixedPointToInt
	cmp r0, 0x13
	ble _0806A6A4
	ldr r0, [r4]
	bl FixedPointToInt
	cmp r0, 0x13
	bgt _0806A6A4
	ldr r0, _0806A6E0
	ldr r0, [r0]
	mov r8, r0
_0806A6A4:
	adds r0, r5, 0
	bl FixedPointToInt
	cmp r0, 0x9
	ble _0806A6C4
	movs r2, 0x9E
	lsls r2, 1
	adds r0, r7, r2
	ldr r0, [r0]
	bl FixedPointToInt
	cmp r0, 0x9
	bgt _0806A6C4
	ldr r0, _0806A6E4
	ldr r0, [r0]
	mov r8, r0
_0806A6C4:
	mov r0, r8
	cmp r0, 0
	beq _0806A6D2
	adds r0, r6, 0
	mov r1, r8
	bl SendMessage
_0806A6D2:
	add sp, 0x4
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_0806A6E0: .4byte gUnknown_80FD594
_0806A6E4: .4byte gUnknown_80FD5B8
	thumb_func_end sub_806A5B8

	thumb_func_start sub_806A6E8
sub_806A6E8:
	push {r4-r7,lr}
	sub sp, 0xC
	adds r7, r0, 0
	ldr r6, [r7, 0x70]
	adds r0, r6, 0
	adds r0, 0x64
	adds r1, r6, 0
	adds r1, 0x62
	ldrb r2, [r0]
	ldrb r1, [r1]
	cmp r2, r1
	beq _0806A77A
	ldrb r0, [r6, 0x7]
	cmp r0, 0
	bne _0806A764
	cmp r1, 0xA
	beq _0806A70E
	cmp r1, 0x2B
	bne _0806A72E
_0806A70E:
	movs r0, 0x9E
	lsls r0, 1
	adds r5, r6, r0
	ldr r4, [r5]
	mov r0, sp
	movs r1, 0xA
	bl IntToFixedPoint
	ldr r2, [sp]
	add r0, sp, 0x4
	adds r1, r4, 0
	bl FixedPoint_Subtract
	ldr r0, [sp, 0x4]
	str r0, [r5]
	b _0806A744
_0806A72E:
	cmp r1, 0x1B
	bne _0806A744
	add r0, sp, 0x8
	movs r1, 0
	bl IntToFixedPoint
	movs r0, 0x9E
	lsls r0, 1
	adds r1, r6, r0
	ldr r0, [sp, 0x8]
	str r0, [r1]
_0806A744:
	ldr r0, _0806A75C
	ldr r0, [r0]
	ldr r1, _0806A760
	adds r0, r1
	ldrb r0, [r0]
	cmp r0, 0
	beq _0806A776
	adds r0, r7, 0
	bl EntityUpdateStatusSprites
	b _0806A776
	.align 2, 0
_0806A75C: .4byte gDungeon
_0806A760: .4byte 0x00000676
_0806A764:
	cmp r1, 0x11
	beq _0806A76C
	cmp r2, 0x11
	bne _0806A776
_0806A76C:
	movs r0, 0x1
	bl sub_803F580
	bl sub_8040A84
_0806A776:
	bl sub_807AA30
_0806A77A:
	adds r0, r6, 0
	adds r0, 0x60
	ldrb r0, [r0]
	movs r1, 0x1
	ands r1, r0
	cmp r1, 0
	beq _0806A792
	adds r0, r6, 0
	adds r0, 0x62
	ldrb r1, [r0]
	adds r0, 0x2
	b _0806A796
_0806A792:
	adds r0, r6, 0
	adds r0, 0x64
_0806A796:
	strb r1, [r0]
	add sp, 0xC
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_806A6E8

	thumb_func_start sub_806A7A0
sub_806A7A0:
	push {r4,r5,lr}
	movs r5, 0
_0806A7A4:
	ldr r0, _0806A7E0
	ldr r0, [r0]
	lsls r1, r5, 2
	ldr r2, _0806A7E4
	adds r0, r2
	adds r0, r1
	ldr r4, [r0]
	adds r0, r4, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	beq _0806A7D2
	ldr r2, [r4, 0x70]
	movs r1, 0xC
	ldrsh r0, [r2, r1]
	cmp r0, 0x1
	ble _0806A7D2
	adds r1, r0, 0
	subs r1, 0x1
	adds r0, r2, 0
	bl sub_806A7E8
_0806A7D2:
	adds r5, 0x1
	cmp r5, 0x3
	ble _0806A7A4
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_0806A7E0: .4byte gDungeon
_0806A7E4: .4byte 0x0001357c
	thumb_func_end sub_806A7A0

	thumb_func_start sub_806A7E8
sub_806A7E8:
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	sub sp, 0x30
	adds r5, r0, 0
	mov r0, sp
	bl GetNumAvailableIQSkills
	mov r9, r0
	add r4, sp, 0x18
	movs r0, 0xC
	ldrsh r1, [r5, r0]
	adds r0, r4, 0
	bl GetNumAvailableIQSkills
	adds r6, r0, 0
	ldr r0, _0806A828
	adds r1, r5, 0
	movs r2, 0
	bl SetMessageArgument_2
	movs r2, 0x1
	mov r8, r4
_0806A818:
	movs r3, 0
	movs r5, 0
	movs r1, 0
	adds r4, r2, 0x1
	cmp r3, r9
	bge _0806A83E
	mov r0, sp
	b _0806A836
	.align 2, 0
_0806A828: .4byte gAvailablePokemonNames
_0806A82C:
	adds r1, 0x1
	cmp r1, r9
	bge _0806A83E
	mov r7, sp
	adds r0, r7, r1
_0806A836:
	ldrb r0, [r0]
	cmp r0, r2
	bne _0806A82C
	movs r3, 0x1
_0806A83E:
	movs r1, 0
	cmp r1, r6
	bge _0806A85C
	mov r7, r8
	ldrb r0, [r7]
	b _0806A856
_0806A84A:
	adds r1, 0x1
	cmp r1, r6
	bge _0806A85C
	mov r7, r8
	adds r0, r7, r1
	ldrb r0, [r0]
_0806A856:
	cmp r0, r2
	bne _0806A84A
	movs r5, 0x1
_0806A85C:
	cmp r3, r5
	beq _0806A87A
	lsls r0, r2, 24
	lsrs r0, 24
	bl GetIQSkillName
	adds r1, r0, 0
	ldr r0, _0806A890
	bl strcpy
	ldr r0, _0806A894
	ldr r1, [r0]
	movs r0, 0
	bl sub_805239C
_0806A87A:
	adds r2, r4, 0
	cmp r2, 0x17
	ble _0806A818
	add sp, 0x30
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_0806A890: .4byte gFormatItems
_0806A894: .4byte gUnknown_80FEAC4
	thumb_func_end sub_806A7E8

	thumb_func_start sub_806A898
sub_806A898:
	push {r4-r7,lr}
	adds r4, r0, 0
	lsls r1, 24
	lsrs r7, r1, 24
	lsls r2, 24
	lsrs r1, r2, 24
	ldr r5, [r4, 0x70]
	ldrb r0, [r5, 0x7]
	cmp r0, 0
	beq _0806A8C2
	ldrh r1, [r4, 0x4]
	movs r2, 0xB6
	lsls r2, 1
	adds r0, r5, r2
	strh r1, [r0]
	ldrh r0, [r4, 0x6]
	adds r0, 0x1
	adds r2, 0x2
	adds r1, r5, r2
	strh r0, [r1]
	b _0806A8C8
_0806A8C2:
	adds r0, r4, 0
	bl MoveIfPossible
_0806A8C8:
	movs r0, 0xB6
	lsls r0, 1
	adds r6, r5, r0
	ldr r0, [r6]
	cmp r0, 0
	beq _0806A90E
	adds r0, r4, 0
	movs r1, 0x1
	bl CheckVariousStatuses2
	lsls r0, 24
	cmp r0, 0
	beq _0806A8EE
	adds r0, r4, 0
	bl CheckVariousStatuses
	lsls r0, 24
	cmp r0, 0
	bne _0806A90E
_0806A8EE:
	adds r0, r4, 0x4
	adds r1, r6, 0
	bl GetDirectionTowardsPosition
	adds r2, r0, 0
	movs r1, 0x7
	ands r0, r1
	adds r1, r5, 0
	adds r1, 0x46
	strb r0, [r1]
	cmp r7, 0
	beq _0806A90E
	adds r0, r4, 0
	adds r1, r2, 0
	bl sub_806CE68
_0806A90E:
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_806A898

	thumb_func_start sub_806A914
sub_806A914:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	lsls r0, 24
	lsrs r0, 24
	mov r8, r0
	lsls r1, 24
	lsrs r7, r1, 24
	lsls r2, 24
	lsrs r6, r2, 24
	movs r5, 0
_0806A92A:
	ldr r0, _0806A96C
	ldr r0, [r0]
	lsls r1, r5, 2
	ldr r2, _0806A970
	adds r0, r2
	adds r0, r1
	ldr r4, [r0]
	adds r0, r4, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	beq _0806A95C
	ldr r0, [r4, 0x70]
	cmp r7, 0
	beq _0806A952
	adds r0, 0xA4
	ldrb r0, [r0]
	cmp r0, 0x1
	bne _0806A95C
_0806A952:
	adds r0, r4, 0
	mov r1, r8
	adds r2, r6, 0
	bl sub_806A898
_0806A95C:
	adds r5, 0x1
	cmp r5, 0x13
	ble _0806A92A
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_0806A96C: .4byte gDungeon
_0806A970: .4byte 0x000135cc
	thumb_func_end sub_806A914

	thumb_func_start sub_806A974
sub_806A974:
	push {r4,r5,lr}
	movs r5, 0
_0806A978:
	ldr r0, _0806A9AC
	ldr r0, [r0]
	lsls r1, r5, 2
	ldr r2, _0806A9B0
	adds r0, r2
	adds r0, r1
	ldr r4, [r0]
	adds r0, r4, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	beq _0806A99E
	ldr r0, [r4, 0x70]
	adds r0, 0x46
	ldrb r1, [r0]
	adds r0, r4, 0
	bl sub_806CE68
_0806A99E:
	adds r5, 0x1
	cmp r5, 0x13
	ble _0806A978
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_0806A9AC: .4byte gDungeon
_0806A9B0: .4byte 0x000135cc
	thumb_func_end sub_806A974

	thumb_func_start sub_806A9B4
sub_806A9B4:
	push {r4,r5,lr}
	adds r4, r0, 0
	adds r5, r1, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	beq _0806AA02
	ldr r0, [r4, 0x70]
	movs r1, 0x8C
	lsls r1, 1
	adds r0, r1
	adds r1, r5, 0
	bl sub_80935B8
	cmp r0, 0
	bne _0806A9E0
	ldr r0, _0806A9DC
	b _0806A9E6
	.align 2, 0
_0806A9DC: .4byte gPtrLinkedMovesComeApartMessage
_0806A9E0:
	cmp r0, 0x1
	bne _0806A9F4
	ldr r0, _0806A9F0
_0806A9E6:
	ldr r1, [r0]
	adds r0, r4, 0
	bl SendMessage
	b _0806AA02
	.align 2, 0
_0806A9F0: .4byte gPtrLinkMoveOneUseWarningMessage
_0806A9F4:
	cmp r0, 0x2
	bne _0806AA02
	ldr r0, _0806AA08
	ldr r1, [r0]
	adds r0, r4, 0
	bl SendMessage
_0806AA02:
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_0806AA08: .4byte gPtrLinkMoveTwoUsesWarningMessage
	thumb_func_end sub_806A9B4

	thumb_func_start sub_806AA0C
sub_806AA0C:
	push {r4,r5,lr}
	lsls r0, 16
	asrs r4, r0, 16
	lsls r1, 24
	lsrs r5, r1, 24
	adds r0, r4, 0
	bl IsExclusivePokemonUnlocked
	lsls r0, 24
	cmp r0, 0
	beq _0806AA56
	ldr r0, _0806AA5C
	ldr r0, [r0]
	ldr r1, _0806AA60
	adds r0, r1
	ldrb r0, [r0]
	cmp r0, 0
	beq _0806AA40
	adds r0, r4, 0
	bl GetBaseSpecies
	lsls r0, 16
	movs r1, 0xCF
	lsls r1, 17
	cmp r0, r1
	beq _0806AA56
_0806AA40:
	cmp r4, 0x97
	bne _0806AA68
	ldr r0, _0806AA5C
	ldr r0, [r0]
	ldr r1, _0806AA64
	adds r0, r1
	ldrb r0, [r0]
	cmp r0, 0
	bne _0806AA56
	cmp r5, 0
	bne _0806AA68
_0806AA56:
	movs r0, 0
	b _0806AA6A
	.align 2, 0
_0806AA5C: .4byte gDungeon
_0806AA60: .4byte 0x000037fd
_0806AA64: .4byte 0x000037ff
_0806AA68:
	movs r0, 0x1
_0806AA6A:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_806AA0C

	thumb_func_start sub_806AA70
sub_806AA70:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	movs r7, 0
	ldr r0, _0806AAB4
	mov r8, r0
_0806AA7C:
	mov r1, r8
	ldr r0, [r1]
	lsls r1, r7, 2
	ldr r2, _0806AAB8
	adds r0, r2
	adds r0, r1
	ldr r4, [r0]
	adds r0, r4, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	beq _0806AB12
	ldr r0, [r4, 0x70]
	ldrb r2, [r0, 0xA]
	ldrb r0, [r0, 0x7]
	cmp r0, 0
	beq _0806AAC4
	mov r1, r8
	ldr r0, [r1]
	ldrb r0, [r0, 0x11]
	cmp r0, 0x1
	bne _0806AABC
	adds r0, r4, 0
	bl sub_8042B20
	b _0806AB0A
	.align 2, 0
_0806AAB4: .4byte gDungeon
_0806AAB8: .4byte 0x0001357c
_0806AABC:
	adds r0, r4, 0
	bl sub_8042B0C
	b _0806AB0A
_0806AAC4:
	cmp r2, 0
	blt _0806AB12
	movs r6, 0
	ldr r1, _0806AB24
	movs r0, 0x64
	muls r0, r2
	ldr r2, _0806AB28
	adds r0, r2
	ldr r1, [r1]
	adds r5, r1, r0
	mov r1, r8
	ldr r0, [r1]
	ldrb r0, [r0, 0x11]
	cmp r0, 0
	bne _0806AB04
	movs r2, 0xA
	ldrsh r0, [r5, r2]
	bl sub_806A564
	lsls r0, 24
	cmp r0, 0
	bne _0806AB04
	movs r1, 0xA
	ldrsh r0, [r5, r1]
	bl sub_806A58C
	lsls r0, 24
	cmp r0, 0
	beq _0806AB00
	movs r6, 0x1
_0806AB00:
	cmp r6, 0
	beq _0806AB12
_0806AB04:
	adds r0, r4, 0
	bl sub_8042B0C
_0806AB0A:
	adds r1, r4, 0
	adds r1, 0x20
	movs r0, 0
	strb r0, [r1]
_0806AB12:
	adds r7, 0x1
	cmp r7, 0x3
	ble _0806AA7C
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_0806AB24: .4byte gRecruitedPokemonRef
_0806AB28: .4byte 0x00008df8
	thumb_func_end sub_806AA70

	thumb_func_start sub_806AB2C
sub_806AB2C:
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	movs r4, 0
	ldr r0, _0806ABA4
	mov r9, r0
_0806AB3A:
	mov r1, r9
	ldr r0, [r1]
	lsls r1, r4, 2
	ldr r2, _0806ABA8
	adds r0, r2
	adds r0, r1
	ldr r7, [r0]
	adds r0, r7, 0
	bl EntityExists
	lsls r0, 24
	adds r4, 0x1
	mov r8, r4
	cmp r0, 0
	beq _0806AB92
	ldr r5, [r7, 0x70]
	movs r6, 0
_0806AB5C:
	mov r1, r9
	ldr r0, [r1]
	lsls r1, r6, 2
	ldr r2, _0806ABA8
	adds r0, r2
	adds r0, r1
	ldr r4, [r0]
	adds r0, r4, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	beq _0806AB8C
	cmp r7, r4
	beq _0806AB8C
	adds r0, r5, 0
	adds r0, 0x7C
	ldrh r0, [r0]
	ldrh r1, [r4, 0x26]
	cmp r0, r1
	bne _0806AB8C
	adds r0, r5, 0
	adds r0, 0x80
	str r4, [r0]
_0806AB8C:
	adds r6, 0x1
	cmp r6, 0x13
	ble _0806AB5C
_0806AB92:
	mov r4, r8
	cmp r4, 0x13
	ble _0806AB3A
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_0806ABA4: .4byte gDungeon
_0806ABA8: .4byte 0x000135cc
	thumb_func_end sub_806AB2C

	thumb_func_start sub_806ABAC
sub_806ABAC:
	push {r4-r6,lr}
	adds r6, r0, 0
	adds r4, r1, 0
	ldr r5, [r4, 0x70]
	adds r0, r4, 0
	movs r1, 0x16
	bl HasAbility
	lsls r0, 24
	cmp r0, 0
	beq _0806ABD4
	adds r0, r5, 0
	adds r0, 0xAC
	ldrb r0, [r0]
	cmp r0, 0x4
	bne _0806ABD4
	adds r0, r6, 0
	adds r1, r4, 0
	bl SendNonVolatileEndMessage
_0806ABD4:
	adds r0, r4, 0
	movs r1, 0x40
	bl HasAbility
	lsls r0, 24
	cmp r0, 0
	beq _0806ABF4
	adds r0, r5, 0
	adds r0, 0xBC
	ldrb r0, [r0]
	cmp r0, 0x2
	bne _0806ABF4
	adds r0, r6, 0
	adds r1, r4, 0
	bl SendVolatileEndMessage
_0806ABF4:
	adds r0, r4, 0
	movs r1, 0x42
	bl HasAbility
	lsls r0, 24
	cmp r0, 0
	beq _0806AC14
	adds r0, r5, 0
	adds r0, 0xAC
	ldrb r0, [r0]
	cmp r0, 0x1
	bne _0806AC14
	adds r0, r6, 0
	adds r1, r4, 0
	bl SendNonVolatileEndMessage
_0806AC14:
	adds r0, r4, 0
	movs r1, 0x29
	bl HasAbility
	lsls r0, 24
	cmp r0, 0
	beq _0806AC34
	adds r0, r5, 0
	adds r0, 0xBC
	ldrb r0, [r0]
	cmp r0, 0x7
	bne _0806AC34
	adds r0, r6, 0
	adds r1, r4, 0
	bl SendVolatileEndMessage
_0806AC34:
	adds r0, r4, 0
	movs r1, 0x36
	bl HasAbility
	lsls r0, 24
	cmp r0, 0
	bne _0806AC50
	adds r0, r4, 0
	movs r1, 0x49
	bl HasAbility
	lsls r0, 24
	cmp r0, 0
	beq _0806AC72
_0806AC50:
	adds r0, r4, 0
	bl IsSleeping
	lsls r0, 24
	cmp r0, 0
	bne _0806AC66
	adds r0, r5, 0
	adds r0, 0xA8
	ldrb r0, [r0]
	cmp r0, 0x4
	bne _0806AC72
_0806AC66:
	adds r0, r6, 0
	adds r1, r4, 0
	movs r2, 0
	movs r3, 0x1
	bl SendSleepEndMessage
_0806AC72:
	adds r0, r4, 0
	movs r1, 0x41
	bl HasAbility
	lsls r0, 24
	cmp r0, 0
	beq _0806AC92
	adds r0, r5, 0
	adds r0, 0xB0
	ldrb r0, [r0]
	cmp r0, 0x1
	bne _0806AC92
	adds r0, r6, 0
	adds r1, r4, 0
	bl SendImmobilizeEndMessage
_0806AC92:
	adds r0, r4, 0
	movs r1, 0x45
	bl HasAbility
	lsls r0, 24
	cmp r0, 0
	beq _0806ACB8
	adds r0, r5, 0
	adds r0, 0xAC
	ldrb r0, [r0]
	subs r0, 0x2
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bhi _0806ACB8
	adds r0, r6, 0
	adds r1, r4, 0
	bl SendNonVolatileEndMessage
_0806ACB8:
	adds r0, r4, 0
	movs r1, 0x25
	bl HasAbility
	lsls r0, 24
	cmp r0, 0
	beq _0806ACE0
	adds r1, r5, 0
	adds r1, 0xF6
	movs r0, 0
	strb r0, [r1]
	adds r0, r5, 0
	adds r0, 0xC4
	ldrb r0, [r0]
	cmp r0, 0xC
	bne _0806ACE0
	adds r0, r6, 0
	adds r1, r4, 0
	bl SendProtectionEndMessage
_0806ACE0:
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end sub_806ABAC

	thumb_func_start sub_806ACE8
sub_806ACE8:
	push {r4,r5,lr}
	adds r4, r1, 0
	ldr r0, [r0, 0x70]
	mov r12, r0
	movs r5, 0xEF
	movs r2, 0x8C
	lsls r2, 1
	add r2, r12
	movs r3, 0x3
_0806ACFA:
	ldrb r1, [r2]
	adds r0, r5, 0
	ands r0, r1
	strb r0, [r2]
	adds r2, 0x8
	subs r3, 0x1
	cmp r3, 0
	bge _0806ACFA
	movs r2, 0x9C
	lsls r2, 1
	add r2, r12
	ldrb r0, [r2]
	movs r3, 0xEF
	ands r3, r0
	movs r5, 0
	strb r3, [r2]
	ldrh r1, [r4, 0x2]
	movs r0, 0xB0
	lsls r0, 1
	cmp r1, r0
	bne _0806AD2E
	movs r1, 0x10
	adds r0, r3, 0
	orrs r0, r1
	strb r0, [r2]
	b _0806AD36
_0806AD2E:
	ldrb r0, [r4]
	movs r1, 0x10
	orrs r0, r1
	strb r0, [r4]
_0806AD36:
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_806ACE8

	thumb_func_start sub_806AD3C
sub_806AD3C:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	ldr r4, _0806AE1C
	add sp, r4
	ldr r0, _0806AE20
	ldr r0, [r0]
	ldr r1, _0806AE24
	adds r4, r0, r1
	mov r0, sp
	movs r1, 0
	bl sub_803D808
	str r0, [sp, 0x200]
	movs r7, 0
	cmp r7, r0
	bge _0806ADEC
	mov r6, sp
	adds r7, r0, 0
_0806AD66:
	adds r0, r6, 0
	bl ExtractSpeciesIndex
	strh r0, [r4]
	adds r0, r6, 0
	bl ExtractLevel
	strh r0, [r4, 0x2]
	adds r0, r4, 0x4
	movs r2, 0
	ldrsh r1, [r4, r2]
	movs r3, 0x2
	ldrsh r2, [r4, r3]
	bl sub_8072AC8
	ldrh r0, [r4, 0x4]
	cmp r0, 0
	bne _0806AD90
	movs r0, 0xB8
	lsls r0, 1
	strh r0, [r4, 0x4]
_0806AD90:
	movs r1, 0
	ldrsh r0, [r4, r1]
	movs r2, 0x2
	ldrsh r1, [r4, r2]
	bl sub_806C444
	strh r0, [r4, 0xC]
	movs r5, 0
	movs r3, 0xE
	adds r3, r4
	mov r9, r3
	movs r0, 0x10
	adds r0, r4
	mov r8, r0
	movs r1, 0x14
	adds r1, r4
	mov r10, r1
_0806ADB2:
	movs r2, 0
	ldrsh r0, [r4, r2]
	movs r3, 0x2
	ldrsh r1, [r4, r3]
	adds r2, r5, 0
	bl sub_806C488
	mov r2, r9
	adds r1, r2, r5
	strb r0, [r1]
	movs r3, 0
	ldrsh r0, [r4, r3]
	movs r2, 0x2
	ldrsh r1, [r4, r2]
	adds r2, r5, 0
	bl sub_806C4D4
	mov r3, r8
	adds r1, r3, r5
	strb r0, [r1]
	adds r5, 0x1
	cmp r5, 0x1
	ble _0806ADB2
	mov r4, r10
	adds r6, 0x8
	subs r7, 0x1
	cmp r7, 0
	bne _0806AD66
	ldr r7, [sp, 0x200]
_0806ADEC:
	cmp r7, 0x3F
	bgt _0806ADFC
	movs r0, 0
_0806ADF2:
	strh r0, [r4]
	adds r4, 0x14
	adds r7, 0x1
	cmp r7, 0x3F
	ble _0806ADF2
_0806ADFC:
	movs r7, 0
	ldr r4, _0806AE28
	ldr r3, _0806AE20
	ldr r2, _0806AE2C
	movs r1, 0
_0806AE06:
	ldr r0, [r3]
	adds r0, r2
	adds r0, r7
	strb r1, [r0]
	adds r7, 0x1
	cmp r7, r4
	ble _0806AE06
	movs r0, 0x1
	mov r10, r0
	movs r7, 0
	b _0806AE94
	.align 2, 0
_0806AE1C: .4byte 0xfffffdfc
_0806AE20: .4byte gDungeon
_0806AE24: .4byte 0x00002f3c
_0806AE28: .4byte 0x000001a7
_0806AE2C: .4byte 0x0000363c
_0806AE30:
	movs r2, 0x1
	negs r2, r2
	mov r8, r2
	mov r9, r8
	ldr r3, [sp, 0x200]
	cmp r3, 0
	ble _0806AE7A
	mov r5, sp
	adds r6, r3, 0
_0806AE42:
	adds r0, r5, 0
	bl ExtractSpeciesIndex
	lsls r0, 16
	asrs r4, r0, 16
	ldr r1, _0806AECC
	ldr r0, [r1]
	ldr r2, _0806AED0
	adds r0, r2
	adds r0, r4
	ldrb r0, [r0]
	cmp r0, 0
	bne _0806AE72
	adds r0, r5, 0
	bl ExtractLevel
	adds r1, r0, 0
	adds r0, r4, 0
	bl CalculateEXPGain
	cmp r9, r0
	bge _0806AE72
	mov r9, r0
	mov r8, r4
_0806AE72:
	adds r5, 0x8
	subs r6, 0x1
	cmp r6, 0
	bne _0806AE42
_0806AE7A:
	mov r3, r8
	cmp r3, 0
	blt _0806AE9A
	ldr r1, _0806AECC
	ldr r0, [r1]
	ldr r2, _0806AED0
	adds r0, r2
	add r0, r8
	mov r3, r10
	strb r3, [r0]
	movs r0, 0x2
	add r10, r0
	adds r7, 0x1
_0806AE94:
	ldr r1, [sp, 0x200]
	cmp r7, r1
	blt _0806AE30
_0806AE9A:
	movs r7, 0
	ldr r5, _0806AECC
	ldr r4, _0806AED0
	movs r3, 0x1
	ldr r2, _0806AED4
_0806AEA4:
	ldr r0, [r5]
	adds r0, r4
	adds r1, r0, r7
	ldrb r0, [r1]
	cmp r0, 0
	bne _0806AEB2
	strb r3, [r1]
_0806AEB2:
	adds r7, 0x1
	cmp r7, r2
	ble _0806AEA4
	movs r3, 0x81
	lsls r3, 2
	add sp, r3
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_0806AECC: .4byte gDungeon
_0806AED0: .4byte 0x0000363c
_0806AED4: .4byte 0x000001a7
	thumb_func_end sub_806AD3C

	thumb_func_start sub_806AED8
sub_806AED8:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x18
	mov r10, r0
	str r1, [sp, 0x8]
	str r2, [sp, 0xC]
	str r3, [sp, 0x10]
	ldr r0, [sp, 0x38]
	ldr r1, [sp, 0x3C]
	mov r8, r1
	lsls r0, 16
	asrs r7, r0, 16
	ldr r1, _0806AF04
	ldr r0, [r1]
	ldr r4, _0806AF08
	adds r6, r0, r4
	movs r3, 0
	b _0806AF7A
	.align 2, 0
_0806AF04: .4byte gDungeon
_0806AF08: .4byte 0x00002f3c
_0806AF0C:
	lsls r0, r2, 16
	asrs r0, 16
	cmp r0, r7
	bne _0806AF6E
	movs r2, 0x2
	ldrsh r0, [r6, r2]
	cmp r0, r8
	bne _0806AF6E
	movs r5, 0xE
	adds r5, r6
	mov r8, r5
	movs r0, 0x10
	adds r0, r6
	mov r9, r0
	mov r1, r10
	adds r1, 0x20
	str r1, [sp, 0x14]
	adds r5, r6, 0x4
	mov r4, r10
	movs r7, 0x3
_0806AF34:
	ldrh r1, [r5]
	adds r0, r4, 0
	bl sub_8092AA8
	adds r5, 0x2
	adds r4, 0x8
	subs r7, 0x1
	cmp r7, 0
	bge _0806AF34
	ldrh r0, [r6, 0xC]
	ldr r2, [sp, 0x8]
	strh r0, [r2]
	movs r5, 0
	mov r3, r8
	mov r2, r9
_0806AF52:
	ldr r0, [sp, 0xC]
	adds r1, r0, r5
	adds r0, r3, r5
	ldrb r0, [r0]
	strb r0, [r1]
	ldr r0, [sp, 0x10]
	adds r1, r0, r5
	adds r0, r2, r5
	ldrb r0, [r0]
	strb r0, [r1]
	adds r5, 0x1
	cmp r5, 0x1
	ble _0806AF52
	b _0806B084
_0806AF6E:
	adds r4, 0x14
	adds r3, 0x1
	cmp r3, 0x3F
	bgt _0806AF84
	ldr r0, [r1]
	adds r6, r0, r4
_0806AF7A:
	ldrh r2, [r6]
	movs r5, 0
	ldrsh r0, [r6, r5]
	cmp r0, 0
	bne _0806AF0C
_0806AF84:
	cmp r3, 0x40
	bne _0806AFE6
	mov r0, sp
	adds r1, r7, 0
	mov r2, r8
	bl sub_8072AC8
	mov r0, r10
	adds r0, 0x20
	str r0, [sp, 0x14]
	mov r5, sp
	mov r4, r10
	movs r6, 0x3
_0806AF9E:
	ldrh r1, [r5]
	adds r0, r4, 0
	bl sub_8092AA8
	adds r5, 0x2
	adds r4, 0x8
	subs r6, 0x1
	cmp r6, 0
	bge _0806AF9E
	adds r0, r7, 0
	mov r1, r8
	bl sub_806C444
	ldr r1, [sp, 0x8]
	strh r0, [r1]
	movs r5, 0
_0806AFBE:
	adds r0, r7, 0
	mov r1, r8
	adds r2, r5, 0
	bl sub_806C488
	ldr r2, [sp, 0xC]
	adds r1, r2, r5
	strb r0, [r1]
	adds r0, r7, 0
	mov r1, r8
	adds r2, r5, 0
	bl sub_806C4D4
	ldr r2, [sp, 0x10]
	adds r1, r2, r5
	strb r0, [r1]
	adds r5, 0x1
	cmp r5, 0x1
	ble _0806AFBE
	b _0806B084
_0806AFE6:
	strh r7, [r6]
	mov r5, r8
	strh r5, [r6, 0x2]
	adds r4, r6, 0x4
	adds r0, r4, 0
	adds r1, r7, 0
	mov r2, r8
	bl sub_8072AC8
	movs r1, 0
	ldrsh r0, [r6, r1]
	movs r2, 0x2
	ldrsh r1, [r6, r2]
	bl sub_806C444
	strh r0, [r6, 0xC]
	movs r5, 0
	movs r0, 0xE
	adds r0, r6
	mov r8, r0
	movs r1, 0x10
	adds r1, r6
	mov r9, r1
	mov r2, r10
	adds r2, 0x20
	str r2, [sp, 0x14]
_0806B01A:
	movs r1, 0
	ldrsh r0, [r6, r1]
	movs r2, 0x2
	ldrsh r1, [r6, r2]
	adds r2, r5, 0
	bl sub_806C488
	mov r2, r8
	adds r1, r2, r5
	strb r0, [r1]
	movs r1, 0
	ldrsh r0, [r6, r1]
	movs r2, 0x2
	ldrsh r1, [r6, r2]
	adds r2, r5, 0
	bl sub_806C4D4
	mov r2, r9
	adds r1, r2, r5
	strb r0, [r1]
	adds r5, 0x1
	cmp r5, 0x1
	ble _0806B01A
	mov r5, r10
	movs r7, 0x3
_0806B04C:
	ldrh r1, [r4]
	adds r0, r5, 0
	bl sub_8092AA8
	adds r4, 0x2
	adds r5, 0x8
	subs r7, 0x1
	cmp r7, 0
	bge _0806B04C
	ldrh r0, [r6, 0xC]
	ldr r5, [sp, 0x8]
	strh r0, [r5]
	movs r5, 0
	mov r3, r8
	mov r2, r9
_0806B06A:
	ldr r0, [sp, 0xC]
	adds r1, r0, r5
	adds r0, r3, r5
	ldrb r0, [r0]
	strb r0, [r1]
	ldr r0, [sp, 0x10]
	adds r1, r0, r5
	adds r0, r2, r5
	ldrb r0, [r0]
	strb r0, [r1]
	adds r5, 0x1
	cmp r5, 0x1
	ble _0806B06A
_0806B084:
	movs r0, 0
	ldr r1, [sp, 0x14]
	strb r0, [r1]
	add sp, 0x18
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_806AED8

	thumb_func_start sub_806B09C
sub_806B09C:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x4
	mov r8, r0
	lsls r1, 24
	lsrs r1, 24
	str r1, [sp]
	movs r7, 0
	movs r2, 0
	mov r6, r8
	adds r6, 0x2
	mov r9, r8
_0806B0BA:
	movs r0, 0x64
	muls r0, r2
	ldr r1, _0806B0E4
	adds r0, r1
	ldr r3, _0806B0E8
	ldr r1, [r3]
	adds r5, r1, r0
	ldrh r1, [r5]
	movs r0, 0x1
	ands r0, r1
	adds r2, 0x1
	mov r10, r2
	cmp r0, 0
	beq _0806B124
	lsrs r0, r1, 1
	movs r1, 0x1
	ands r0, r1
	cmp r0, 0
	beq _0806B124
	movs r4, 0
	b _0806B0EE
	.align 2, 0
_0806B0E4: .4byte 0x00008df8
_0806B0E8: .4byte gRecruitedPokemonRef
_0806B0EC:
	adds r4, 0x1
_0806B0EE:
	cmp r4, r7
	bge _0806B106
	lsls r0, r4, 3
	add r0, r8
	bl ExtractSpeciesIndex
	lsls r0, 16
	asrs r0, 16
	movs r2, 0xE
	ldrsh r1, [r5, r2]
	cmp r0, r1
	bne _0806B0EC
_0806B106:
	cmp r4, r7
	bne _0806B124
	movs r3, 0xE
	ldrsh r2, [r5, r3]
	mov r0, r9
	movs r1, 0
	bl sub_808E9D8
	movs r0, 0
	strh r0, [r6]
	strh r0, [r6, 0x2]
	adds r6, 0x8
	movs r0, 0x8
	add r9, r0
	adds r7, 0x1
_0806B124:
	mov r2, r10
	cmp r2, 0x3
	ble _0806B0BA
	mov r0, r8
	adds r1, r7, 0
	bl sub_803D808
	adds r7, r0, 0
	ldr r1, [sp]
	cmp r1, 0
	beq _0806B150
	lsls r4, r7, 3
	add r4, r8
	ldr r2, _0806B164
	adds r0, r4, 0
	movs r1, 0x1
	bl sub_808E9D8
	movs r0, 0
	strh r0, [r4, 0x2]
	strh r0, [r4, 0x4]
	adds r7, 0x1
_0806B150:
	adds r0, r7, 0
	add sp, 0x4
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	.align 2, 0
_0806B164: .4byte 0x000001a5
	thumb_func_end sub_806B09C

	thumb_func_start sub_806B168
sub_806B168:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x3C
	ldr r0, _0806B324
	ldr r1, [r0]
	ldr r2, _0806B328
	adds r0, r1, r2
	movs r3, 0
	ldrsh r0, [r0, r3]
	ldr r4, _0806B32C
	adds r1, r4
	movs r2, 0
	ldrsh r1, [r1, r2]
	bl GetTile
	ldrb r0, [r0, 0x9]
	str r0, [sp, 0x2C]
	movs r3, 0
	mov r4, sp
	adds r4, 0x1C
	str r4, [sp, 0x30]
	ldr r2, _0806B330
	ldr r1, _0806B334
_0806B19C:
	ldr r0, [r2]
	adds r0, r1
	strh r3, [r0, 0xC]
	adds r1, 0x64
	adds r3, 0x1
	cmp r3, 0x3
	ble _0806B19C
	movs r4, 0
	movs r3, 0
	ldr r0, _0806B324
	mov r8, r0
	ldr r0, _0806B330
	ldr r7, [r0]
	movs r5, 0x1
	add r6, sp, 0xC
_0806B1BA:
	movs r0, 0x64
	muls r0, r3
	ldr r1, _0806B334
	adds r0, r1
	adds r2, r7, r0
	ldrh r1, [r2]
	adds r0, r5, 0
	ands r0, r1
	cmp r0, 0
	beq _0806B1DA
	lsrs r0, r1, 1
	ands r0, r5
	cmp r0, 0
	beq _0806B1DA
	stm r6!, {r2}
	adds r4, 0x1
_0806B1DA:
	adds r3, 0x1
	cmp r3, 0x3
	ble _0806B1BA
	cmp r4, 0x3
	bgt _0806B1F4
	movs r1, 0
	lsls r0, r4, 2
	add r0, sp
	adds r0, 0xC
_0806B1EC:
	stm r0!, {r1}
	adds r4, 0x1
	cmp r4, 0x3
	ble _0806B1EC
_0806B1F4:
	movs r4, 0
	movs r6, 0
	add r2, sp, 0xC
	ldr r5, [sp, 0x30]
	movs r3, 0x3
_0806B1FE:
	ldr r1, [r2]
	cmp r1, 0
	beq _0806B210
	ldrb r0, [r1, 0x2]
	cmp r0, 0
	beq _0806B210
	str r6, [r2]
	stm r5!, {r1}
	adds r4, 0x1
_0806B210:
	adds r2, 0x4
	subs r3, 0x1
	cmp r3, 0
	bge _0806B1FE
	mov r2, r8
	ldr r0, [r2]
	ldr r3, _0806B338
	adds r0, r3
	ldrb r0, [r0]
	cmp r0, 0
	bne _0806B24C
	movs r6, 0
	add r2, sp, 0xC
	lsls r0, r4, 2
	ldr r1, [sp, 0x30]
	adds r5, r0, r1
	movs r3, 0x3
_0806B232:
	ldr r1, [r2]
	cmp r1, 0
	beq _0806B244
	ldrb r0, [r1, 0x4]
	cmp r0, 0x41
	bne _0806B244
	str r6, [r2]
	stm r5!, {r1}
	adds r4, 0x1
_0806B244:
	adds r2, 0x4
	subs r3, 0x1
	cmp r3, 0
	bge _0806B232
_0806B24C:
	movs r5, 0
	add r2, sp, 0xC
	lsls r0, r4, 2
	ldr r3, [sp, 0x30]
	adds r0, r3
	movs r3, 0x3
_0806B258:
	ldr r1, [r2]
	cmp r1, 0
	beq _0806B264
	str r5, [r2]
	stm r0!, {r1}
	adds r4, 0x1
_0806B264:
	adds r2, 0x4
	subs r3, 0x1
	cmp r3, 0
	bge _0806B258
	cmp r4, 0x3
	bgt _0806B280
	movs r1, 0
	lsls r0, r4, 2
	ldr r2, [sp, 0x30]
	adds r0, r2
_0806B278:
	stm r0!, {r1}
	adds r4, 0x1
	cmp r4, 0x3
	ble _0806B278
_0806B280:
	movs r3, 0
_0806B282:
	lsls r0, r3, 2
	ldr r4, [sp, 0x30]
	adds r0, r4, r0
	ldr r0, [r0]
	mov r8, r0
	adds r0, r3, 0x1
	str r0, [sp, 0x34]
	mov r1, r8
	cmp r1, 0
	bne _0806B298
	b _0806B3E8
_0806B298:
	movs r2, 0xE
	ldrsh r1, [r1, r2]
	ldr r0, _0806B33C
	cmp r1, r0
	beq _0806B2AE
	adds r0, 0x2
	cmp r1, r0
	beq _0806B2AE
	subs r0, 0x1
	cmp r1, r0
	bne _0806B2B6
_0806B2AE:
	movs r0, 0xBC
	lsls r0, 1
	mov r4, r8
	strh r0, [r4, 0xE]
_0806B2B6:
	ldr r0, _0806B340
	ldr r2, [r0]
	movs r1, 0
	ldrsh r0, [r0, r1]
	adds r3, 0x1
	str r3, [sp, 0x34]
	ldr r3, _0806B340
	cmp r0, 0x63
	beq _0806B350
	ldr r4, _0806B324
	mov r9, r4
	ldr r0, _0806B328
	mov r10, r0
	adds r5, r3, 0
_0806B2D2:
	lsls r0, r2, 16
	asrs r7, r0, 16
	mov r4, r9
	ldr r1, [r4]
	mov r4, r10
	adds r0, r1, r4
	movs r4, 0
	ldrsh r0, [r0, r4]
	adds r0, r7, r0
	asrs r6, r2, 16
	ldr r2, _0806B32C
	adds r1, r2
	movs r4, 0
	ldrsh r1, [r1, r4]
	adds r1, r6, r1
	str r3, [sp, 0x38]
	bl GetTile
	adds r1, r0, 0
	ldrb r0, [r1, 0x9]
	ldr r3, [sp, 0x38]
	ldr r2, [sp, 0x2C]
	cmp r0, r2
	bne _0806B344
	mov r4, r8
	movs r2, 0xE
	ldrsh r0, [r4, r2]
	bl sub_807034C
	lsls r0, 24
	lsrs r4, r0, 24
	ldr r3, [sp, 0x38]
	cmp r4, 0
	bne _0806B344
	mov r3, r8
	movs r1, 0xE
	ldrsh r0, [r3, r1]
	mov r3, r9
	ldr r2, [r3]
	mov r3, r10
	b _0806B3A8
	.align 2, 0
_0806B324: .4byte gDungeon
_0806B328: .4byte 0x0000e218
_0806B32C: .4byte 0x0000e21a
_0806B330: .4byte gRecruitedPokemonRef
_0806B334: .4byte 0x00008df8
_0806B338: .4byte 0x0000065c
_0806B33C: .4byte 0x00000179
_0806B340: .4byte gUnknown_80F4598
_0806B344:
	adds r5, 0x4
	ldr r2, [r5]
	movs r4, 0
	ldrsh r0, [r5, r4]
	cmp r0, 0x63
	bne _0806B2D2
_0806B350:
	movs r0, 0
	cmp r0, 0
	bne _0806B3E8
	ldr r2, [r3]
	movs r1, 0
	ldrsh r0, [r3, r1]
	cmp r0, 0x63
	beq _0806B3E8
	ldr r3, _0806B3CC
	mov r9, r3
	ldr r5, _0806B3D0
_0806B366:
	lsls r0, r2, 16
	asrs r7, r0, 16
	mov r4, r9
	ldr r1, [r4]
	ldr r3, _0806B3D4
	adds r0, r1, r3
	movs r4, 0
	ldrsh r0, [r0, r4]
	adds r0, r7, r0
	asrs r6, r2, 16
	ldr r2, _0806B3D8
	adds r1, r2
	movs r3, 0
	ldrsh r1, [r1, r3]
	adds r1, r6, r1
	bl GetTile
	adds r1, r0, 0
	mov r4, r8
	movs r2, 0xE
	ldrsh r0, [r4, r2]
	bl sub_807034C
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0
	bne _0806B3DC
	mov r3, r8
	movs r1, 0xE
	ldrsh r0, [r3, r1]
	mov r3, r9
	ldr r2, [r3]
	ldr r3, _0806B3D4
_0806B3A8:
	adds r1, r2, r3
	movs r3, 0
	ldrsh r1, [r1, r3]
	adds r1, r7, r1
	ldr r3, _0806B3D8
	adds r2, r3
	movs r3, 0
	ldrsh r2, [r2, r3]
	adds r2, r6, r2
	str r4, [sp]
	movs r3, 0x1
	str r3, [sp, 0x4]
	str r4, [sp, 0x8]
	mov r3, r8
	bl sub_806B8CC
	b _0806B3E8
	.align 2, 0
_0806B3CC: .4byte gDungeon
_0806B3D0: .4byte gUnknown_80F4598
_0806B3D4: .4byte 0x0000e218
_0806B3D8: .4byte 0x0000e21a
_0806B3DC:
	adds r5, 0x4
	ldr r2, [r5]
	movs r4, 0
	ldrsh r0, [r5, r4]
	cmp r0, 0x63
	bne _0806B366
_0806B3E8:
	ldr r3, [sp, 0x34]
	cmp r3, 0x3
	bgt _0806B3F0
	b _0806B282
_0806B3F0:
	bl sub_806B678
	add sp, 0x3C
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_806B168

	thumb_func_start sub_806B404
sub_806B404:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x30
	movs r5, 0
	movs r2, 0
	ldr r0, _0806B480
	mov r9, r0
	ldr r0, _0806B484
	ldr r7, [r0]
	movs r6, 0x1
	ldr r1, _0806B488
	mov r8, r1
_0806B422:
	movs r0, 0x64
	muls r0, r2
	ldr r3, _0806B48C
	adds r0, r3
	adds r3, r7, r0
	ldrh r1, [r3]
	adds r0, r6, 0
	ands r0, r1
	cmp r0, 0
	beq _0806B446
	lsrs r0, r1, 1
	ands r0, r6
	cmp r0, 0
	beq _0806B446
	movs r1, 0xA
	ldrsh r0, [r3, r1]
	cmp r0, r8
	beq _0806B490
_0806B446:
	adds r2, 0x1
	cmp r2, 0x3
	ble _0806B422
_0806B44C:
	cmp r5, 0x3
	bgt _0806B460
	movs r1, 0
	lsls r0, r5, 2
	add r0, sp
	adds r0, 0xC
_0806B458:
	stm r0!, {r1}
	adds r5, 0x1
	cmp r5, 0x3
	ble _0806B458
_0806B460:
	movs r0, 0
	mov r2, r9
	str r0, [r2]
	bl GetLeader
	adds r5, r0, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	beq _0806B49C
	ldrh r0, [r5, 0x6]
	lsls r0, 16
	ldrh r4, [r5, 0x4]
	b _0806B4AE
	.align 2, 0
_0806B480: .4byte gLeaderPointer
_0806B484: .4byte gRecruitedPokemonRef
_0806B488: .4byte 0x000055aa
_0806B48C: .4byte 0x00008df8
_0806B490:
	lsls r0, r5, 2
	add r0, sp
	adds r0, 0xC
	str r3, [r0]
	adds r5, 0x1
	b _0806B44C
_0806B49C:
	ldr r0, _0806B560
	ldr r0, [r0]
	ldr r3, _0806B564
	adds r1, r0, r3
	ldr r2, _0806B568
	adds r0, r2
	ldrh r0, [r0]
	lsls r0, 16
	ldrh r4, [r1]
_0806B4AE:
	orrs r4, r0
	lsls r5, r4, 16
	asrs r0, r5, 16
	asrs r4, 16
	adds r1, r4, 0
	bl GetTile
	ldrb r0, [r0, 0x9]
	str r0, [sp, 0x20]
	movs r2, 0
	str r5, [sp, 0x24]
	mov r10, r4
_0806B4C6:
	lsls r0, r2, 2
	add r0, sp
	adds r0, 0xC
	ldr r6, [r0]
	adds r2, 0x1
	str r2, [sp, 0x28]
	cmp r6, 0
	bne _0806B4D8
	b _0806B65E
_0806B4D8:
	ldrh r1, [r6]
	movs r2, 0x1
	adds r0, r2, 0
	ands r0, r1
	cmp r0, 0
	bne _0806B4E6
	b _0806B65E
_0806B4E6:
	lsrs r0, r1, 1
	ands r0, r2
	cmp r0, 0
	bne _0806B4F0
	b _0806B65E
_0806B4F0:
	movs r3, 0xA
	ldrsh r1, [r6, r3]
	ldr r0, _0806B56C
	cmp r1, r0
	beq _0806B4FC
	b _0806B65E
_0806B4FC:
	ldr r0, _0806B570
	strh r0, [r6, 0xA]
	movs r7, 0
	ldr r2, _0806B574
	ldr r0, [r2]
	str r0, [sp, 0x1C]
	add r0, sp, 0x1C
	movs r3, 0
	ldrsh r1, [r0, r3]
	mov r9, r2
	adds r2, r0, 0
	cmp r1, 0x63
	beq _0806B58C
	ldr r0, [sp, 0x24]
	asrs r0, 16
	mov r8, r0
_0806B51C:
	movs r1, 0
	ldrsh r0, [r2, r1]
	add r0, r8
	ldr r1, [sp, 0x1C]
	asrs r1, 16
	mov r5, r10
	adds r1, r5
	str r2, [sp, 0x2C]
	bl GetTile
	adds r1, r0, 0
	ldrb r0, [r1, 0x9]
	ldr r2, [sp, 0x2C]
	ldr r3, [sp, 0x20]
	cmp r0, r3
	bne _0806B578
	movs r3, 0xE
	ldrsh r0, [r6, r3]
	bl sub_807034C
	lsls r0, 24
	lsrs r4, r0, 24
	ldr r2, [sp, 0x2C]
	cmp r4, 0
	bne _0806B578
	movs r1, 0xE
	ldrsh r0, [r6, r1]
	movs r3, 0
	ldrsh r1, [r2, r3]
	add r1, r8
	ldr r2, [sp, 0x1C]
	asrs r2, 16
	adds r2, r5
	b _0806B642
	.align 2, 0
_0806B560: .4byte gDungeon
_0806B564: .4byte 0x0000e218
_0806B568: .4byte 0x0000e21a
_0806B56C: .4byte 0x000055aa
_0806B570: .4byte 0x00005aa5
_0806B574: .4byte gUnknown_80F4598
_0806B578:
	adds r7, 0x1
	ldr r1, _0806B5E4
	lsls r0, r7, 2
	adds r0, r1
	ldr r0, [r0]
	str r0, [sp, 0x1C]
	movs r1, 0
	ldrsh r0, [r2, r1]
	cmp r0, 0x63
	bne _0806B51C
_0806B58C:
	movs r3, 0
	cmp r3, 0
	bne _0806B65E
	movs r7, 0
	mov r1, r9
	ldr r0, [r1]
	str r0, [sp, 0x1C]
	movs r3, 0
	ldrsh r0, [r2, r3]
	cmp r0, 0x63
	beq _0806B5FC
	ldr r0, [sp, 0x24]
	asrs r0, 16
	mov r8, r0
_0806B5A8:
	movs r1, 0
	ldrsh r0, [r2, r1]
	add r0, r8
	ldr r1, [sp, 0x1C]
	asrs r1, 16
	mov r5, r10
	adds r1, r5
	str r2, [sp, 0x2C]
	bl GetTile
	adds r1, r0, 0
	movs r3, 0xE
	ldrsh r0, [r6, r3]
	bl sub_807034C
	lsls r0, 24
	lsrs r4, r0, 24
	ldr r2, [sp, 0x2C]
	cmp r4, 0
	bne _0806B5E8
	movs r1, 0xE
	ldrsh r0, [r6, r1]
	movs r3, 0
	ldrsh r1, [r2, r3]
	add r1, r8
	ldr r2, [sp, 0x1C]
	asrs r2, 16
	adds r2, r5
	b _0806B642
	.align 2, 0
_0806B5E4: .4byte gUnknown_80F4598
_0806B5E8:
	adds r7, 0x1
	ldr r1, _0806B654
	lsls r0, r7, 2
	adds r0, r1
	ldr r0, [r0]
	str r0, [sp, 0x1C]
	movs r1, 0
	ldrsh r0, [r2, r1]
	cmp r0, 0x63
	bne _0806B5A8
_0806B5FC:
	movs r3, 0
	cmp r3, 0
	bne _0806B65E
	movs r7, 0
	adds r5, r2, 0
_0806B606:
	adds r0, r5, 0
	str r2, [sp, 0x2C]
	bl sub_8083660
	lsls r0, 24
	ldr r2, [sp, 0x2C]
	cmp r0, 0
	beq _0806B658
	movs r1, 0
	ldrsh r0, [r2, r1]
	movs r3, 0x2
	ldrsh r1, [r5, r3]
	bl GetTile
	adds r1, r0, 0
	movs r3, 0xE
	ldrsh r0, [r6, r3]
	bl sub_807034C
	lsls r0, 24
	lsrs r4, r0, 24
	ldr r2, [sp, 0x2C]
	cmp r4, 0
	bne _0806B658
	movs r1, 0xE
	ldrsh r0, [r6, r1]
	movs r3, 0
	ldrsh r1, [r2, r3]
	movs r3, 0x2
	ldrsh r2, [r5, r3]
_0806B642:
	str r4, [sp]
	movs r3, 0x1
	str r3, [sp, 0x4]
	str r4, [sp, 0x8]
	adds r3, r6, 0
	bl sub_806B8CC
	b _0806B65E
	.align 2, 0
_0806B654: .4byte gUnknown_80F4598
_0806B658:
	adds r7, 0x1
	cmp r7, 0x63
	ble _0806B606
_0806B65E:
	ldr r2, [sp, 0x28]
	cmp r2, 0x3
	bgt _0806B666
	b _0806B4C6
_0806B666:
	add sp, 0x30
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_806B404

	thumb_func_start sub_806B678
sub_806B678:
	push {r4,r5,lr}
	movs r5, 0
_0806B67C:
	ldr r0, _0806B6AC
	ldr r0, [r0]
	lsls r1, r5, 2
	ldr r2, _0806B6B0
	adds r0, r2
	adds r0, r1
	ldr r4, [r0]
	adds r0, r4, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	beq _0806B6B8
	ldr r0, [r4, 0x70]
	ldrb r0, [r0, 0x7]
	cmp r0, 0
	beq _0806B6B8
	adds r0, r4, 0
	bl sub_803F4A0
	ldr r1, _0806B6B4
	ldr r0, [r4, 0x4]
	str r0, [r1]
	b _0806B6BE
	.align 2, 0
_0806B6AC: .4byte gDungeon
_0806B6B0: .4byte 0x0001357c
_0806B6B4: .4byte gUnknown_202EE0C
_0806B6B8:
	adds r5, 0x1
	cmp r5, 0x3
	ble _0806B67C
_0806B6BE:
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_806B678

	thumb_func_start sub_806B6C4
sub_806B6C4:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x14
	ldr r4, _0806B708
	ldr r0, [r4]
	movs r1, 0xD1
	lsls r1, 3
	adds r0, r1
	movs r2, 0
	ldrsh r1, [r0, r2]
	negs r0, r1
	orrs r0, r1
	lsrs r0, 31
	mov r8, r0
	movs r0, 0x7A
	bl sub_80860A8
	lsls r0, 24
	cmp r0, 0
	beq _0806B710
	movs r0, 0x97
	bl HasRecruitedMon
	lsls r0, 24
	lsrs r1, r0, 24
	cmp r1, 0
	bne _0806B710
	ldr r0, [r4]
	ldr r2, _0806B70C
	adds r0, r2
	b _0806B71A
	.align 2, 0
_0806B708: .4byte gDungeon
_0806B70C: .4byte 0x000037ff
_0806B710:
	ldr r0, _0806B77C
	ldr r0, [r0]
	ldr r1, _0806B780
	adds r0, r1
	movs r1, 0x1
_0806B71A:
	strb r1, [r0]
	movs r0, 0x38
	bl DungeonRandInt
	adds r5, r0, 0
	movs r0, 0x20
	bl DungeonRandInt
	adds r7, r0, 0
	movs r0, 0
_0806B72E:
	adds r7, 0x1
	cmp r7, 0x20
	bne _0806B736
	movs r7, 0
_0806B736:
	adds r0, 0x1
	mov r10, r0
	mov r4, sp
	movs r2, 0x37
	mov r9, r2
_0806B740:
	adds r5, 0x1
	cmp r5, 0x38
	bne _0806B748
	movs r5, 0
_0806B748:
	adds r0, r5, 0
	adds r1, r7, 0
	bl GetTile
	ldrh r1, [r0, 0x4]
	movs r0, 0x8
	ands r0, r1
	cmp r0, 0
	beq _0806B7C2
	movs r6, 0
	mov r0, r8
	cmp r0, 0
	beq _0806B784
	ldr r0, _0806B77C
	ldr r0, [r0]
	movs r1, 0xD1
	lsls r1, 3
	adds r0, r1
	ldrh r0, [r0]
	strh r0, [r4]
	movs r1, 0x1
	movs r0, 0x1
	strh r0, [r4, 0x8]
	strb r1, [r4, 0x2]
	movs r6, 0x1
	b _0806B794
	.align 2, 0
_0806B77C: .4byte gDungeon
_0806B780: .4byte 0x000037ff
_0806B784:
	movs r0, 0
	bl sub_803D970
	movs r1, 0
	strh r0, [r4]
	mov r2, r8
	strh r2, [r4, 0x8]
	strb r1, [r4, 0x2]
_0806B794:
	movs r0, 0
	str r0, [sp, 0x4]
	strb r0, [r4, 0x10]
	strh r5, [r4, 0xC]
	strh r7, [r4, 0xE]
	cmp r6, 0
	bne _0806B7B2
	movs r1, 0
	ldrsh r0, [r4, r1]
	movs r1, 0x1
	bl sub_806AA0C
	lsls r0, 24
	cmp r0, 0
	beq _0806B7C2
_0806B7B2:
	mov r0, sp
	movs r1, 0
	bl sub_806B7F8
	cmp r0, 0
	beq _0806B7C2
	movs r2, 0
	mov r8, r2
_0806B7C2:
	movs r0, 0x1
	negs r0, r0
	add r9, r0
	mov r1, r9
	cmp r1, 0
	bge _0806B740
	mov r0, r10
	cmp r0, 0x1F
	ble _0806B72E
	mov r2, r8
	cmp r2, 0
	beq _0806B7E2
	ldr r0, _0806B7F4
	ldr r1, [r0]
	movs r0, 0x1
	strb r0, [r1, 0xA]
_0806B7E2:
	add sp, 0x14
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_0806B7F4: .4byte gDungeon
	thumb_func_end sub_806B6C4

	thumb_func_start sub_806B7F8
sub_806B7F8:
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	sub sp, 0x8
	adds r6, r0, 0
	lsls r1, 24
	lsrs r1, 24
	mov r8, r1
	movs r1, 0xC
	ldrsh r0, [r6, r1]
	movs r2, 0xE
	ldrsh r1, [r6, r2]
	bl GetTile
	adds r1, r0, 0
	movs r3, 0
	ldrsh r0, [r6, r3]
	bl sub_807034C
	lsls r0, 24
	cmp r0, 0
	bne _0806B834
	movs r4, 0
	ldrsh r0, [r6, r4]
	bl sub_804550C
	adds r7, r0, 0
	cmp r7, 0
	bne _0806B838
_0806B834:
	movs r0, 0
	b _0806B8B8
_0806B838:
	ldr r3, _0806B8C8
	movs r0, 0
	adds r1, r7, 0
	adds r2, r6, 0
	bl sub_806BC68
	ldr r5, [r7, 0x70]
	movs r0, 0x1
	strb r0, [r5, 0x6]
	movs r1, 0x8C
	lsls r1, 1
	adds r0, r5, r1
	adds r1, r5, 0
	adds r1, 0x10
	adds r2, r5, 0
	adds r2, 0x14
	movs r3, 0x16
	adds r3, r5
	mov r9, r3
	movs r3, 0x2
	ldrsh r4, [r5, r3]
	str r4, [sp]
	ldrb r4, [r5, 0x9]
	str r4, [sp, 0x4]
	mov r3, r9
	bl sub_806AED8
	ldrh r0, [r5, 0x10]
	strh r0, [r5, 0xE]
	movs r4, 0x8A
	lsls r4, 1
	adds r1, r5, r4
	ldr r0, [r6, 0x4]
	str r0, [r1]
	ldrb r0, [r6, 0x2]
	cmp r0, 0
	bne _0806B8B6
	mov r0, r8
	cmp r0, 0
	bne _0806B8B6
	ldrb r0, [r6, 0x10]
	cmp r0, 0
	bne _0806B8B6
	movs r0, 0x64
	bl DungeonRandInt
	adds r4, r0, 0
	movs r1, 0
	ldrsh r0, [r6, r1]
	bl GetChanceAsleep
	lsls r0, 24
	lsrs r0, 24
	cmp r0, r4
	ble _0806B8B6
	adds r0, r7, 0
	movs r1, 0x7F
	bl sub_8075BF4
	adds r0, r7, 0
	movs r1, 0x8
	bl sub_806CE68
_0806B8B6:
	adds r0, r7, 0
_0806B8B8:
	add sp, 0x8
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r1}
	bx r1
	.align 2, 0
_0806B8C8: .4byte gUnknown_202EE0C
	thumb_func_end sub_806B7F8

	thumb_func_start sub_806B8CC
sub_806B8CC:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x2C
	mov r9, r1
	mov r10, r2
	adds r5, r3, 0
	ldr r1, [sp, 0x50]
	ldr r2, [sp, 0x54]
	lsls r0, 16
	asrs r4, r0, 16
	lsls r1, 24
	lsrs r6, r1, 24
	lsls r2, 24
	lsrs r2, 24
	str r2, [sp, 0x18]
	ldrb r1, [r5, 0x2]
	negs r0, r1
	orrs r0, r1
	lsrs r0, 31
	mov r8, r0
	ldr r0, [sp, 0x4C]
	cmp r0, 0
	beq _0806B906
	movs r0, 0
	ldr r1, [sp, 0x4C]
	str r0, [r1]
_0806B906:
	adds r0, r4, 0
	bl GetBaseSpecies
	lsls r0, 16
	asrs r1, r0, 16
	movs r0, 0xCF
	lsls r0, 1
	cmp r1, r0
	bne _0806B932
	cmp r6, 0
	beq _0806B930
	ldr r0, _0806B92C
	ldr r0, [r0]
	movs r2, 0xE0
	lsls r2, 6
	adds r0, r2
	movs r3, 0
	ldrsh r4, [r0, r3]
	b _0806B932
	.align 2, 0
_0806B92C: .4byte gDungeon
_0806B930:
	adds r4, r1, 0
_0806B932:
	mov r0, r9
	mov r1, r10
	bl GetTile
	adds r1, r0, 0
	adds r0, r4, 0
	bl sub_807034C
	lsls r0, 24
	lsrs r6, r0, 24
	cmp r6, 0
	bne _0806B956
	adds r0, r4, 0
	bl sub_80453AC
	str r0, [sp, 0x1C]
	cmp r0, 0
	bne _0806B95A
_0806B956:
	movs r0, 0
	b _0806BB3C
_0806B95A:
	mov r0, sp
	movs r7, 0
	mov r1, r9
	strh r1, [r0, 0xC]
	mov r2, r10
	strh r2, [r0, 0xE]
	strh r4, [r0]
	mov r1, sp
	ldrb r0, [r5, 0x3]
	strh r0, [r1, 0x8]
	mov r0, sp
	strb r7, [r0, 0x2]
	str r6, [sp, 0x4]
	strb r7, [r0, 0x10]
	ldr r4, _0806BB4C
	ldr r3, _0806BB50
	ldrb r0, [r3]
	lsls r0, 2
	adds r0, r4
	ldrh r0, [r0]
	add r0, r9
	lsls r0, 16
	lsrs r0, 16
	ldr r2, _0806BB54
	ldr r1, [sp, 0x14]
	ands r1, r2
	orrs r1, r0
	str r1, [sp, 0x14]
	ldrb r0, [r3]
	lsls r0, 2
	adds r0, r4
	ldrh r0, [r0, 0x2]
	add r0, r10
	lsls r0, 16
	ldr r2, _0806BB58
	ands r1, r2
	orrs r1, r0
	str r1, [sp, 0x14]
	ldr r3, _0806BB5C
	mov r0, r8
	cmp r0, 0
	beq _0806B9B0
	add r3, sp, 0x14
_0806B9B0:
	movs r0, 0x1
	ldr r1, [sp, 0x1C]
	mov r2, sp
	bl sub_806BC68
	ldr r1, [sp, 0x1C]
	ldr r4, [r1, 0x70]
	strb r7, [r4, 0x6]
	strb r7, [r4, 0x8]
	mov r2, r8
	strb r2, [r4, 0x7]
	adds r0, r4, 0
	adds r0, 0xF9
	mov r3, sp
	ldrb r3, [r3, 0x18]
	strb r3, [r0]
	ldr r0, _0806BB60
	str r6, [r0]
	mov r6, r8
	cmp r6, 0
	beq _0806B9E4
	ldr r0, _0806BB5C
	mov r7, r9
	strh r7, [r0]
	mov r1, r10
	strh r1, [r0, 0x2]
_0806B9E4:
	ldrh r0, [r5, 0x10]
	strh r0, [r4, 0xE]
	ldrh r0, [r5, 0x12]
	strh r0, [r4, 0x10]
	ldr r0, [r5, 0x18]
	str r0, [r4, 0x18]
	movs r3, 0
	movs r2, 0x1C
	adds r2, r5
	mov r8, r2
	movs r6, 0x50
	adds r6, r5
	mov r10, r6
	movs r7, 0x94
	adds r7, r4
	mov r9, r7
	adds r0, r4, 0
	adds r0, 0x8C
	str r0, [sp, 0x20]
	adds r1, r4, 0
	adds r1, 0xF3
	str r1, [sp, 0x24]
	adds r2, r4, 0
	adds r2, 0x64
	str r2, [sp, 0x28]
	movs r6, 0x14
	adds r6, r4
	mov r12, r6
	adds r7, r5, 0
	adds r7, 0x14
	adds r6, r4, 0
	adds r6, 0x16
	adds r2, r5, 0
	adds r2, 0x16
_0806BA28:
	mov r0, r12
	adds r1, r0, r3
	adds r0, r7, r3
	ldrb r0, [r0]
	strb r0, [r1]
	adds r1, r6, r3
	adds r0, r2, r3
	ldrb r0, [r0]
	strb r0, [r1]
	adds r3, 0x1
	cmp r3, 0x1
	ble _0806BA28
	movs r1, 0x8C
	lsls r1, 1
	adds r2, r4, r1
	adds r1, r2, 0
	mov r0, r8
	ldm r0!, {r3,r6,r7}
	stm r1!, {r3,r6,r7}
	ldm r0!, {r3,r6,r7}
	stm r1!, {r3,r6,r7}
	ldm r0!, {r3,r6,r7}
	stm r1!, {r3,r6,r7}
	movs r0, 0x1
	mov r8, r0
	movs r7, 0xEF
	movs r6, 0xDF
	movs r3, 0x3
_0806BA60:
	ldrb r1, [r2]
	mov r0, r8
	ands r0, r1
	cmp r0, 0
	beq _0806BA72
	adds r0, r7, 0
	ands r0, r1
	ands r0, r6
	strb r0, [r2]
_0806BA72:
	adds r2, 0x8
	subs r3, 0x1
	cmp r3, 0
	bge _0806BA60
	movs r1, 0x9C
	lsls r1, 1
	adds r2, r4, r1
	ldrb r1, [r2]
	movs r0, 0xEF
	ands r0, r1
	movs r1, 0xDF
	ands r0, r1
	strb r0, [r2]
	ldrb r0, [r5, 0x3]
	strb r0, [r4, 0x9]
	ldrh r0, [r5, 0x8]
	movs r2, 0
	strh r0, [r4, 0xC]
	mov r3, r10
	ldrb r0, [r3]
	mov r6, r9
	strb r0, [r6]
	ldr r0, [r5, 0x4C]
	ldr r7, [sp, 0x20]
	str r0, [r7]
	ldr r0, [r5, 0x54]
	str r0, [r4, 0x3C]
	ldr r0, [r5, 0x4]
	str r0, [r4, 0x40]
	movs r0, 0x9E
	lsls r0, 1
	adds r1, r4, r0
	ldr r0, [r5, 0x44]
	str r0, [r1]
	movs r3, 0xA0
	lsls r3, 1
	adds r1, r4, r3
	ldr r0, [r5, 0x48]
	str r0, [r1]
	ldrh r0, [r5, 0xC]
	strb r0, [r4, 0xA]
	ldr r0, [r5, 0x40]
	str r0, [r4, 0x60]
	ldr r0, [sp, 0x24]
	strb r2, [r0]
	ldr r6, [sp, 0x28]
	strb r2, [r6]
	ldr r7, _0806BB64
	ldr r0, [r7]
	ldr r1, _0806BB68
	adds r0, r1
	ldrb r0, [r0]
	cmp r0, 0
	beq _0806BB24
	bl IsBossFight
	lsls r0, 24
	cmp r0, 0
	bne _0806BB24
	adds r0, r4, 0
	adds r0, 0x5E
	ldrb r0, [r0]
	cmp r0, 0x47
	beq _0806BAFC
	adds r0, r4, 0
	adds r0, 0x5F
	ldrb r0, [r0]
	cmp r0, 0x47
	bne _0806BB24
_0806BAFC:
	adds r4, 0x60
	ldrb r1, [r4]
	movs r5, 0x1
	adds r0, r5, 0
	ands r0, r1
	cmp r0, 0
	bne _0806BB24
	movs r0, 0
	bl sub_803D73C
	lsls r0, 24
	lsrs r1, r0, 24
	cmp r1, 0x69
	beq _0806BB24
	adds r0, r4, 0
	movs r2, 0
	bl xxx_init_itemslot_8090A8C
	ldr r2, [sp, 0x24]
	strb r5, [r2]
_0806BB24:
	ldr r0, [sp, 0x1C]
	bl sub_806A6E8
	ldr r0, [sp, 0x1C]
	bl LoadIQSkills
	ldr r3, [sp, 0x4C]
	cmp r3, 0
	beq _0806BB3A
	ldr r6, [sp, 0x1C]
	str r6, [r3]
_0806BB3A:
	movs r0, 0x1
_0806BB3C:
	add sp, 0x2C
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	.align 2, 0
_0806BB4C: .4byte gAdjacentTileOffsets
_0806BB50: .4byte gUnknown_202F32C
_0806BB54: .4byte 0xffff0000
_0806BB58: .4byte 0x0000ffff
_0806BB5C: .4byte gUnknown_202EE0C
_0806BB60: .4byte gLeaderPointer
_0806BB64: .4byte gDungeon
_0806BB68: .4byte 0x00000644
	thumb_func_end sub_806B8CC

	thumb_func_start sub_806BB6C
sub_806BB6C:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x1C
	adds r7, r0, 0
	lsls r4, r1, 16
	asrs r4, 16
	ldr r0, [r7, 0x70]
	mov r9, r0
	mov r8, r9
	adds r0, 0x98
	ldr r0, [r0]
	bl DeletePokemonDungeonSprite
	add r0, sp, 0x8
	movs r1, 0
	mov r10, r1
	movs r6, 0
	lsls r5, r4, 16
	lsrs r5, 16
	strh r5, [r0]
	strh r6, [r0, 0x8]
	mov r2, r10
	strb r2, [r0, 0x2]
	ldr r0, [r7, 0x4]
	str r0, [sp, 0x14]
	str r6, [sp, 0xC]
	movs r0, 0
	adds r1, r4, 0
	bl sub_8069F54
	lsls r0, 16
	adds r1, r7, 0
	adds r1, 0x22
	mov r2, r10
	strb r2, [r1]
	ldr r1, [r7, 0x70]
	asrs r2, r0, 16
	lsrs r0, 16
	strh r0, [r1, 0x4]
	ldr r0, [r7, 0x70]
	strh r5, [r0, 0x2]
	adds r0, r2, 0
	bl GetSpriteData
	str r0, [r7, 0x64]
	adds r1, r7, 0
	adds r1, 0x6A
	movs r0, 0x7
	strb r0, [r1]
	adds r0, r7, 0
	adds r0, 0x6C
	mov r5, r10
	strb r5, [r0]
	adds r1, 0x1
	movs r0, 0xFF
	strb r0, [r1]
	adds r1, 0x2
	movs r0, 0x1
	strb r0, [r1]
	adds r1, 0x2
	strb r0, [r1]
	str r6, [r7, 0x1C]
	mov r0, r9
	adds r0, 0xB0
	ldrb r0, [r0]
	subs r0, 0x3
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bhi _0806BC08
	mov r0, r9
	adds r0, 0x9C
	ldr r0, [r0]
	bl sub_8076CB4
_0806BC08:
	movs r1, 0
	mov r6, r9
	ldrb r0, [r6, 0x6]
	cmp r0, 0
	bne _0806BC14
	movs r1, 0x1
_0806BC14:
	adds r0, r1, 0
	adds r1, r7, 0
	add r2, sp, 0x8
	movs r3, 0
	bl sub_806BC68
	movs r0, 0x8C
	lsls r0, 1
	add r0, r8
	mov r1, r8
	adds r1, 0x10
	mov r2, r8
	adds r2, 0x14
	mov r3, r8
	adds r3, 0x16
	mov r5, r8
	movs r6, 0x2
	ldrsh r4, [r5, r6]
	str r4, [sp]
	ldrb r4, [r5, 0x9]
	str r4, [sp, 0x4]
	bl sub_806AED8
	ldrh r0, [r5, 0x10]
	strh r0, [r5, 0xE]
	mov r0, r10
	strb r0, [r5, 0x8]
	adds r0, r7, 0
	bl sub_80429E8
	adds r0, r7, 0
	bl EntityUpdateStatusSprites
	add sp, 0x1C
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_806BB6C

	thumb_func_start sub_806BC68
sub_806BC68:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0xC
	adds r4, r0, 0
	mov r8, r1
	adds r7, r2, 0
	mov r10, r3
	lsls r4, 24
	lsrs r4, 24
	ldr r1, _0806BD0C
	ldr r0, [r1]
	movs r5, 0
	movs r2, 0x1
	mov r9, r2
	mov r3, r9
	strb r3, [r0, 0xC]
	mov r0, r8
	ldr r6, [r0, 0x70]
	adds r0, r6, 0
	movs r1, 0x1
	bl sub_806BFC0
	ldrb r1, [r7, 0x2]
	adds r0, r6, 0
	adds r0, 0xA4
	strb r1, [r0]
	mov r0, r8
	adds r0, 0x20
	mov r1, r9
	strb r1, [r0]
	adds r0, 0x2
	strb r5, [r0]
	ldr r0, _0806BD10
	mov r2, r8
	strh r0, [r2, 0x8]
	movs r0, 0x1
	negs r0, r0
	strh r0, [r2, 0xA]
	ldr r0, _0806BD14
	strh r0, [r2, 0x4]
	strh r0, [r2, 0x6]
	movs r3, 0xC
	ldrsh r1, [r7, r3]
	movs r0, 0xE
	ldrsh r2, [r7, r0]
	mov r0, r8
	movs r3, 0x1
	bl sub_80694C0
	mov r0, r8
	movs r1, 0
	bl sub_804535C
	cmp r4, 0
	bne _0806BD5E
	movs r2, 0
	ldrsh r1, [r7, r2]
	movs r0, 0xBE
	lsls r0, 1
	cmp r1, r0
	bne _0806BD20
	ldr r3, _0806BD0C
	ldr r1, [r3]
	ldr r4, _0806BD18
	adds r0, r1, r4
	ldrb r0, [r0]
	cmp r0, 0
	bne _0806BD20
	ldr r2, _0806BD1C
	adds r0, r1, r2
	ldrb r0, [r0]
	cmp r0, 0
	beq _0806BD20
	ldrb r0, [r7, 0x2]
	cmp r0, 0
	bne _0806BD20
	mov r3, r9
	strb r3, [r6, 0x8]
	b _0806BD24
	.align 2, 0
_0806BD0C: .4byte gDungeon
_0806BD10: .4byte 0x0000ffff
_0806BD14: .4byte 0x0000fffe
_0806BD18: .4byte 0x0000066e
_0806BD1C: .4byte 0x00003a0a
_0806BD20:
	movs r0, 0
	strb r0, [r6, 0x8]
_0806BD24:
	movs r4, 0x2
	ldrsh r0, [r6, r4]
	bl GetBaseSpecies
	lsls r0, 16
	movs r1, 0xCF
	lsls r1, 17
	cmp r0, r1
	bne _0806BD42
	ldr r0, _0806BD94
	ldr r0, [r0]
	ldr r1, _0806BD98
	adds r0, r1
	movs r1, 0x1
	strb r1, [r0]
_0806BD42:
	movs r2, 0x2
	ldrsh r0, [r6, r2]
	bl GetBaseSpecies
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x97
	bne _0806BD5E
	ldr r0, _0806BD94
	ldr r0, [r0]
	ldr r3, _0806BD9C
	adds r0, r3
	movs r1, 0x1
	strb r1, [r0]
_0806BD5E:
	adds r2, r6, 0
	adds r2, 0x98
	ldr r0, _0806BD94
	ldr r1, [r0]
	ldr r4, _0806BDA0
	adds r1, r4
	ldr r0, [r1]
	str r0, [r2]
	ldr r0, [r1]
	adds r0, 0x1
	str r0, [r1]
	adds r1, r6, 0
	adds r1, 0x9C
	movs r0, 0
	str r0, [r1]
	ldrh r1, [r7, 0x8]
	movs r3, 0x8
	ldrsh r0, [r7, r3]
	mov r9, r2
	cmp r0, 0
	bne _0806BDA4
	movs r4, 0
	ldrsh r0, [r7, r4]
	bl sub_803DA20
	strb r0, [r6, 0x9]
	b _0806BDA6
	.align 2, 0
_0806BD94: .4byte gDungeon
_0806BD98: .4byte 0x000037fd
_0806BD9C: .4byte 0x000037ff
_0806BDA0: .4byte 0x000037f0
_0806BDA4:
	strb r1, [r6, 0x9]
_0806BDA6:
	movs r0, 0x8A
	lsls r0, 1
	adds r1, r6, r0
	ldr r0, [r7, 0x4]
	str r0, [r1]
	movs r4, 0x1
	strh r4, [r6, 0xC]
	adds r0, r6, 0
	adds r0, 0x8C
	movs r1, 0
	bl SetDefaultIQSkills
	adds r0, r6, 0
	adds r0, 0x3C
	bl GenerateHiddenPower
	strh r4, [r6, 0x10]
	strh r4, [r6, 0xE]
	mov r0, sp
	movs r1, 0x64
	bl IntToFixedPoint
	movs r2, 0x9E
	lsls r2, 1
	adds r1, r6, r2
	ldr r0, [sp]
	str r0, [r1]
	add r0, sp, 0x4
	movs r1, 0x64
	bl IntToFixedPoint
	movs r3, 0xA0
	lsls r3, 1
	adds r1, r6, r3
	ldr r0, [sp, 0x4]
	str r0, [r1]
	mov r4, r10
	cmp r4, 0
	beq _0806BE00
	movs r0, 0xB6
	lsls r0, 1
	adds r1, r6, r0
	ldr r0, [r4]
	str r0, [r1]
	b _0806BE12
_0806BE00:
	movs r1, 0xB6
	lsls r1, 1
	adds r0, r6, r1
	mov r2, r10
	strh r2, [r0]
	movs r3, 0xB7
	lsls r3, 1
	adds r0, r6, r3
	strh r2, [r0]
_0806BE12:
	movs r7, 0
	movs r4, 0
	strh r4, [r6]
	movs r1, 0xA2
	lsls r1, 1
	adds r0, r6, r1
	strb r7, [r0]
	ldr r2, _0806BFB4
	adds r0, r6, r2
	strb r7, [r0]
	movs r3, 0xFA
	lsls r3, 1
	adds r0, r6, r3
	strh r4, [r0]
	adds r1, 0xB2
	adds r0, r6, r1
	strh r4, [r0]
	adds r0, r6, 0
	adds r0, 0x78
	strb r7, [r0]
	adds r1, r6, 0
	adds r1, 0x88
	mov r2, r8
	ldr r0, [r2, 0x4]
	str r0, [r1]
	adds r0, r6, 0
	adds r0, 0x80
	str r4, [r0]
	adds r0, 0x4
	str r4, [r0]
	subs r0, 0x8
	strh r4, [r0]
	adds r0, 0x83
	strb r7, [r0]
	subs r3, 0x80
	adds r0, r6, r3
	str r4, [r0]
	movs r1, 0x80
	lsls r1, 1
	adds r0, r6, r1
	strb r7, [r0]
	adds r0, r6, 0
	movs r1, 0x1
	bl sub_806BFC0
	adds r0, r6, 0
	adds r0, 0x60
	strb r7, [r0, 0x2]
	strb r7, [r0, 0x1]
	strb r7, [r0]
	adds r0, 0x4
	strb r7, [r0]
	movs r2, 0x80
	lsls r2, 2
	adds r0, r6, r2
	str r4, [r0]
	movs r3, 0xB2
	lsls r3, 1
	adds r1, r6, r3
	movs r0, 0xFF
	strb r0, [r1]
	adds r0, 0x66
	adds r1, r6, r0
	movs r0, 0x1
	negs r0, r0
	strb r0, [r1]
	movs r1, 0xFE
	lsls r1, 1
	adds r0, r6, r1
	str r4, [r0]
	subs r2, 0xB9
	adds r0, r6, r2
	strb r7, [r0]
	subs r3, 0x1E
	adds r0, r6, r3
	strb r7, [r0]
	subs r1, 0x96
	adds r0, r6, r1
	strb r7, [r0]
	adds r2, 0xB1
	adds r0, r6, r2
	strh r4, [r0]
	adds r3, 0xB4
	adds r0, r6, r3
	strh r4, [r0]
	subs r1, 0x1E
	adds r0, r6, r1
	strb r7, [r0]
	subs r2, 0xAF
	adds r0, r6, r2
	strb r7, [r0]
	subs r3, 0x82
	adds r0, r6, r3
	strh r4, [r0]
	adds r0, r6, 0
	adds r0, 0xFA
	strb r7, [r0]
	adds r0, 0x2
	strb r7, [r0]
	adds r1, 0x3
	adds r0, r6, r1
	strb r7, [r0]
	adds r2, 0x3
	adds r0, r6, r2
	movs r5, 0x1
	strb r5, [r0]
	subs r3, 0x2A
	adds r0, r6, r3
	strh r4, [r0]
	adds r1, 0x5
	adds r0, r6, r1
	strh r4, [r0]
	adds r2, 0x6
	adds r0, r6, r2
	strb r7, [r0]
	adds r3, 0x5
	adds r0, r6, r3
	strb r7, [r0]
	movs r4, 0xAA
	lsls r4, 1
	adds r0, r6, r4
	strb r7, [r0]
	adds r1, 0x5
	adds r0, r6, r1
	strb r7, [r0]
	adds r2, 0x17
	adds r0, r6, r2
	strb r7, [r0]
	adds r0, r6, 0
	adds r0, 0xFD
	strb r7, [r0]
	adds r1, r6, 0
	adds r1, 0xFE
	movs r0, 0x63
	strb r0, [r1]
	adds r3, 0x5
	adds r0, r6, r3
	strb r7, [r0]
	adds r4, 0x5
	adds r0, r6, r4
	strb r7, [r0]
	movs r1, 0xAD
	lsls r1, 1
	adds r0, r6, r1
	strb r7, [r0]
	mov r0, r8
	bl CalcSpeedStage
	movs r2, 0xAB
	lsls r2, 1
	adds r1, r6, r2
	strb r5, [r1]
	movs r3, 0xAE
	lsls r3, 1
	adds r0, r6, r3
	strb r7, [r0]
	adds r4, 0x5
	adds r0, r6, r4
	strb r7, [r0]
	adds r2, 0x7
	adds r0, r6, r2
	strb r7, [r0]
	adds r3, 0x3
	adds r0, r6, r3
	strb r7, [r0]
	adds r4, 0x2
	adds r0, r6, r4
	strb r7, [r0]
	ldrh r0, [r6, 0x4]
	subs r0, 0x32
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0x1
	bhi _0806BF70
	strb r7, [r1]
_0806BF70:
	mov r0, r8
	ldrh r1, [r0, 0x6]
	lsls r1, 16
	ldrh r0, [r0, 0x4]
	orrs r0, r1
	str r0, [sp, 0x8]
	mov r1, r9
	ldr r0, [r1]
	movs r2, 0x4
	ldrsh r1, [r6, r2]
	add r2, sp, 0x8
	ldr r3, _0806BFB8
	ldr r3, [r3]
	ldr r4, _0806BFBC
	adds r3, r4
	ldrb r3, [r3]
	bl AddPokemonDungeonSprite
	mov r0, r8
	bl LoadIQSkills
	mov r0, r8
	movs r1, 0
	movs r2, 0
	bl sub_806A898
	add sp, 0xC
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_0806BFB4: .4byte 0x00000145
_0806BFB8: .4byte gDungeon
_0806BFBC: .4byte 0x00018208
	thumb_func_end sub_806BC68

	thumb_func_start sub_806BFC0
sub_806BFC0:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x3C
	adds r4, r0, 0
	lsls r1, 24
	lsrs r1, 24
	str r1, [sp]
	adds r1, r4, 0
	adds r1, 0xA8
	movs r0, 0
	strb r0, [r1]
	adds r1, 0x1
	strb r0, [r1]
	adds r1, 0x3
	strb r0, [r1]
	adds r1, 0x1
	strb r0, [r1]
	adds r1, 0x1
	strb r0, [r1]
	adds r1, 0x1
	strb r0, [r1]
	adds r1, 0x1
	strb r0, [r1]
	adds r1, 0x8
	strb r0, [r1]
	adds r1, 0x1
	strb r0, [r1]
	adds r2, r4, 0
	adds r2, 0xB4
	movs r1, 0x22
	str r1, [r2]
	adds r1, r4, 0
	adds r1, 0xBC
	strb r0, [r1]
	adds r1, 0x1
	strb r0, [r1]
	adds r1, 0x3
	strb r0, [r1]
	adds r1, 0x4
	strb r0, [r1]
	adds r1, 0x1
	strb r0, [r1]
	adds r1, 0x3
	strb r0, [r1]
	adds r1, 0x3
	strb r0, [r1]
	adds r1, 0x1
	strb r0, [r1]
	adds r1, 0x4
	strb r0, [r1]
	adds r1, 0x9
	strb r0, [r1]
	adds r1, 0x1
	strb r0, [r1]
	adds r1, 0x2
	strb r0, [r1]
	adds r1, 0x1
	strb r0, [r1]
	adds r1, 0x3
	strb r0, [r1]
	adds r1, 0x4
	strb r0, [r1]
	adds r1, 0x1
	strb r0, [r1]
	adds r1, 0x3
	strb r0, [r1]
	adds r1, 0x1
	strb r0, [r1]
	adds r1, 0x3
	strb r0, [r1]
	adds r1, 0x1
	strb r0, [r1]
	adds r1, 0x3
	strb r0, [r1]
	adds r1, 0x1
	strb r0, [r1]
	adds r1, 0x1
	strb r0, [r1]
	movs r0, 0xB2
	lsls r0, 1
	adds r1, r4, r0
	movs r0, 0xFF
	strb r0, [r1]
	ldr r2, _0806C168
	adds r1, r4, r2
	movs r0, 0x1
	negs r0, r0
	strb r0, [r1]
	movs r1, 0
	movs r7, 0x84
	lsls r7, 1
	adds r0, r4, r7
	movs r5, 0x4
_0806C080:
	strb r1, [r0]
	strb r1, [r0, 0x5]
	adds r0, 0x1
	subs r5, 0x1
	cmp r5, 0
	bge _0806C080
	movs r0, 0
	str r0, [sp, 0x4]
	movs r5, 0
	adds r1, r4, 0
	adds r1, 0x5E
	str r1, [sp, 0x8]
	movs r2, 0x5C
	adds r2, r4
	mov r10, r2
	adds r7, r4, 0
	adds r7, 0xFD
	str r7, [sp, 0x20]
	adds r0, r4, 0
	adds r0, 0xF4
	str r0, [sp, 0xC]
	adds r1, 0x9D
	str r1, [sp, 0x1C]
	adds r2, r4, 0
	adds r2, 0xF5
	str r2, [sp, 0x10]
	subs r7, 0x7
	str r7, [sp, 0x14]
	adds r0, 0x3
	str r0, [sp, 0x18]
	adds r1, 0x4
	str r1, [sp, 0x24]
	movs r2, 0x1
	mov r9, r2
	movs r3, 0xA
	subs r7, 0xC2
	str r7, [sp, 0x28]
	subs r0, 0xCB
	str r0, [sp, 0x2C]
	adds r2, r4, 0
	adds r2, 0x24
	subs r1, 0xDF
	str r1, [sp, 0x38]
	adds r6, r4, 0
	adds r6, 0x1C
	movs r7, 0x80
	lsls r7, 1
	mov r8, r7
_0806C0E0:
	movs r1, 0x2
	ldrsh r0, [r4, r1]
	adds r1, r5, 0
	str r2, [sp, 0x30]
	str r3, [sp, 0x34]
	bl GetPokemonAbility
	ldr r7, [sp, 0x8]
	adds r1, r7, r5
	strb r0, [r1]
	lsls r0, 24
	lsrs r0, 24
	ldr r2, [sp, 0x30]
	ldr r3, [sp, 0x34]
	cmp r0, 0x25
	bne _0806C104
	movs r0, 0x1
	str r0, [sp, 0x4]
_0806C104:
	ldr r1, [sp]
	cmp r1, 0
	beq _0806C11E
	adds r0, r4, 0
	adds r0, 0x14
	adds r0, r5
	mov r7, r9
	strb r7, [r0]
	adds r0, r4, 0
	adds r0, 0x16
	adds r0, r5
	mov r1, r9
	strb r1, [r0]
_0806C11E:
	strh r3, [r6]
	ldr r7, [sp, 0x38]
	strh r3, [r7]
	strh r3, [r2]
	ldr r1, [sp, 0x2C]
	mov r0, r8
	stm r1!, {r0}
	str r1, [sp, 0x2C]
	ldr r7, [sp, 0x28]
	stm r7!, {r0}
	str r7, [sp, 0x28]
	adds r2, 0x2
	ldr r0, [sp, 0x38]
	adds r0, 0x2
	str r0, [sp, 0x38]
	adds r6, 0x2
	adds r5, 0x1
	cmp r5, 0x1
	ble _0806C0E0
	ldr r1, [sp, 0x4]
	cmp r1, 0
	beq _0806C170
	movs r0, 0
	bl GetApparentWeather
	ldr r1, _0806C16C
	lsls r0, 24
	lsrs r0, 22
	adds r0, r1
	ldrb r0, [r0]
	movs r1, 0
	mov r2, r10
	strb r0, [r2]
	adds r0, r4, 0
	adds r0, 0x5D
	strb r1, [r0]
	b _0806C188
	.align 2, 0
_0806C168: .4byte 0x00000165
_0806C16C: .4byte gUnknown_80F520C
_0806C170:
	movs r5, 0
_0806C172:
	movs r7, 0x2
	ldrsh r0, [r4, r7]
	adds r1, r5, 0
	bl GetPokemonType
	mov r2, r10
	adds r1, r2, r5
	strb r0, [r1]
	adds r5, 0x1
	cmp r5, 0x1
	ble _0806C172
_0806C188:
	ldr r0, _0806C1D0
	ldr r1, [r0]
	movs r2, 0
	movs r0, 0x1
	strb r0, [r1, 0xC]
	movs r0, 0
	strh r2, [r4, 0x28]
	movs r7, 0x89
	lsls r7, 1
	adds r1, r4, r7
	strb r0, [r1]
	ldr r1, [sp, 0x20]
	strb r0, [r1]
	ldr r2, _0806C1D4
	adds r1, r4, r2
	strb r0, [r1]
	ldr r7, [sp, 0xC]
	strb r0, [r7]
	ldr r1, [sp, 0x1C]
	strb r0, [r1]
	ldr r2, [sp, 0x10]
	strb r0, [r2]
	ldr r7, [sp, 0x14]
	strb r0, [r7]
	ldr r1, [sp, 0x18]
	strb r0, [r1]
	ldr r2, [sp, 0x24]
	strb r0, [r2]
	add sp, 0x3C
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_0806C1D0: .4byte gDungeon
_0806C1D4: .4byte 0x00000113
	thumb_func_end sub_806BFC0

	thumb_func_start sub_806C1D8
sub_806C1D8:
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	movs r5, 0
_0806C1E2:
	ldr r0, _0806C258
	ldr r0, [r0]
	lsls r1, r5, 2
	ldr r2, _0806C25C
	adds r0, r2
	adds r0, r1
	ldr r4, [r0]
	adds r0, r4, 0
	bl EntityExists
	lsls r0, 24
	adds r5, 0x1
	mov r9, r5
	cmp r0, 0
	beq _0806C244
	ldr r4, [r4, 0x70]
	ldrb r6, [r4, 0xA]
	cmp r6, 0
	blt _0806C244
	movs r5, 0
	movs r0, 0x8C
	lsls r0, 1
	mov r12, r0
	movs r2, 0x1
	mov r8, r2
	adds r3, r4, 0
	movs r7, 0xFE
_0806C218:
	lsls r0, r5, 3
	adds r0, r4
	add r0, r12
	ldrb r1, [r0]
	mov r0, r8
	ands r0, r1
	cmp r0, 0
	beq _0806C234
	ldr r0, _0806C260
	adds r2, r3, r0
	ldrb r1, [r2]
	adds r0, r7, 0
	ands r0, r1
	strb r0, [r2]
_0806C234:
	adds r3, 0x8
	adds r5, 0x1
	cmp r5, 0x3
	ble _0806C218
	adds r0, r6, 0
	adds r1, r4, 0
	bl sub_806C264
_0806C244:
	mov r5, r9
	cmp r5, 0x3
	ble _0806C1E2
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_0806C258: .4byte gDungeon
_0806C25C: .4byte 0x0001357c
_0806C260: .4byte 0x00000119
	thumb_func_end sub_806C1D8

	thumb_func_start sub_806C264
sub_806C264:
	push {r4,r5,lr}
	mov r12, r1
	ldr r2, _0806C31C
	movs r1, 0x64
	muls r0, r1
	ldr r1, _0806C320
	adds r0, r1
	ldr r1, [r2]
	adds r3, r1, r0
	mov r2, r12
	ldrh r0, [r2, 0xE]
	strh r0, [r3, 0x10]
	ldrh r0, [r2, 0x10]
	strh r0, [r3, 0x12]
	ldr r0, [r2, 0x18]
	str r0, [r3, 0x18]
	adds r2, 0x14
	adds r1, r3, 0
	adds r1, 0x14
	movs r4, 0x1
_0806C28C:
	ldrb r0, [r2]
	strb r0, [r1]
	ldrb r0, [r2, 0x2]
	strb r0, [r1, 0x2]
	adds r2, 0x1
	adds r1, 0x1
	subs r4, 0x1
	cmp r4, 0
	bge _0806C28C
	ldr r4, _0806C324
	adds r0, r4, 0
	mov r5, r12
	ldrh r5, [r5, 0x4]
	adds r0, r5
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0x2
	bhi _0806C2B6
	movs r0, 0xBC
	lsls r0, 1
	strh r0, [r3, 0xE]
_0806C2B6:
	adds r1, r3, 0
	adds r1, 0x1C
	movs r0, 0x8C
	lsls r0, 1
	add r0, r12
	ldm r0!, {r2,r4,r5}
	stm r1!, {r2,r4,r5}
	ldm r0!, {r2,r4,r5}
	stm r1!, {r2,r4,r5}
	ldm r0!, {r2,r4,r5}
	stm r1!, {r2,r4,r5}
	mov r1, r12
	ldrb r0, [r1, 0x9]
	strb r0, [r3, 0x3]
	ldrh r0, [r1, 0xC]
	strh r0, [r3, 0x8]
	mov r0, r12
	adds r0, 0x8C
	ldr r0, [r0]
	str r0, [r3, 0x4C]
	mov r0, r12
	adds r0, 0x94
	ldrb r1, [r0]
	adds r0, r3, 0
	adds r0, 0x50
	strb r1, [r0]
	mov r2, r12
	ldr r0, [r2, 0x3C]
	str r0, [r3, 0x54]
	movs r0, 0x9E
	lsls r0, 1
	add r0, r12
	ldr r0, [r0]
	str r0, [r3, 0x44]
	movs r0, 0xA0
	lsls r0, 1
	add r0, r12
	ldr r0, [r0]
	str r0, [r3, 0x48]
	ldr r0, [r2, 0x60]
	str r0, [r3, 0x40]
	movs r4, 0xA
	ldrsh r1, [r3, r4]
	ldr r0, _0806C328
	cmp r1, r0
	bne _0806C316
	ldr r0, _0806C32C
	strh r0, [r3, 0xA]
_0806C316:
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_0806C31C: .4byte gRecruitedPokemonRef
_0806C320: .4byte 0x00008df8
_0806C324: .4byte 0xfffffe87
_0806C328: .4byte 0x000055aa
_0806C32C: .4byte 0x00005aa5
	thumb_func_end sub_806C264

	thumb_func_start sub_806C330
sub_806C330:
	push {r4-r7,lr}
	adds r4, r0, 0
	adds r5, r1, 0
	lsls r2, 16
	asrs r2, 16
	mov r12, r2
	lsls r3, 24
	lsrs r7, r3, 24
	ldr r0, _0806C370
	ldr r0, [r0]
	ldr r1, _0806C374
	adds r2, r0, r1
	movs r3, 0
	ldr r0, [r2, 0x40]
	cmp r3, r0
	bge _0806C382
	mov r1, r12
	lsls r0, r1, 16
	lsrs r6, r0, 16
	adds r1, r2, 0
_0806C358:
	ldrb r0, [r1, 0x3]
	cmp r0, 0
	beq _0806C378
	ldrb r0, [r1, 0x4]
	cmp r0, r4
	bne _0806C378
	ldrb r0, [r1, 0x5]
	cmp r0, r5
	bne _0806C378
	strh r6, [r1]
	strb r7, [r1, 0x2]
	b _0806C3B8
	.align 2, 0
_0806C370: .4byte gDungeon
_0806C374: .4byte 0x0000057c
_0806C378:
	adds r1, 0x8
	adds r3, 0x1
	ldr r0, [r2, 0x40]
	cmp r3, r0
	blt _0806C358
_0806C382:
	ldr r0, [r2, 0x40]
	cmp r0, 0x7
	bgt _0806C3B8
	lsls r0, 3
	adds r0, r2, r0
	movs r1, 0x1
	strb r1, [r0, 0x3]
	ldr r0, [r2, 0x40]
	lsls r0, 3
	adds r0, r2, r0
	strb r4, [r0, 0x4]
	ldr r0, [r2, 0x40]
	lsls r0, 3
	adds r0, r2, r0
	strb r5, [r0, 0x5]
	ldr r0, [r2, 0x40]
	lsls r0, 3
	adds r0, r2, r0
	mov r1, r12
	strh r1, [r0]
	ldr r0, [r2, 0x40]
	lsls r0, 3
	adds r0, r2, r0
	strb r7, [r0, 0x2]
	ldr r0, [r2, 0x40]
	adds r0, 0x1
	str r0, [r2, 0x40]
_0806C3B8:
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_806C330

	thumb_func_start sub_806C3C0
sub_806C3C0:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0x18
	ldr r0, _0806C424
	ldr r0, [r0]
	ldr r1, _0806C428
	adds r7, r0, r1
	movs r6, 0
	ldr r0, [r7, 0x40]
	cmp r6, r0
	bge _0806C416
	mov r5, sp
	movs r0, 0
	mov r8, r0
	movs r2, 0
	adds r4, r7, 0
_0806C3E2:
	ldrb r0, [r4, 0x3]
	cmp r0, 0
	beq _0806C40C
	ldrh r0, [r4]
	strh r0, [r5]
	strh r2, [r5, 0x8]
	ldrb r0, [r4, 0x4]
	strh r0, [r5, 0xC]
	ldrb r0, [r4, 0x5]
	strh r0, [r5, 0xE]
	ldrb r0, [r4, 0x2]
	strb r0, [r5, 0x2]
	str r2, [sp, 0x4]
	mov r1, r8
	strb r1, [r5, 0x10]
	mov r0, sp
	movs r1, 0x1
	str r2, [sp, 0x14]
	bl sub_806B7F8
	ldr r2, [sp, 0x14]
_0806C40C:
	adds r4, 0x8
	adds r6, 0x1
	ldr r0, [r7, 0x40]
	cmp r6, r0
	blt _0806C3E2
_0806C416:
	add sp, 0x18
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_0806C424: .4byte gDungeon
_0806C428: .4byte 0x0000057c
	thumb_func_end sub_806C3C0

	thumb_func_start sub_806C42C
sub_806C42C:
	ldr r0, _0806C43C
	ldr r0, [r0]
	ldr r1, _0806C440
	adds r0, r1
	movs r1, 0
	str r1, [r0, 0x40]
	bx lr
	.align 2, 0
_0806C43C: .4byte gDungeon
_0806C440: .4byte 0x0000057c
	thumb_func_end sub_806C42C

	thumb_func_start sub_806C444
sub_806C444:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0xC
	adds r7, r1, 0
	lsls r0, 16
	asrs r6, r0, 16
	adds r0, r6, 0
	bl GetBaseHP
	adds r5, r0, 0
	movs r4, 0x2
	cmp r4, r7
	bgt _0806C478
	mov r8, sp
_0806C462:
	mov r0, sp
	adds r1, r6, 0
	adds r2, r4, 0
	bl GetPokemonLevelData
	mov r1, r8
	ldrh r0, [r1, 0x4]
	adds r5, r0
	adds r4, 0x1
	cmp r4, r7
	ble _0806C462
_0806C478:
	adds r0, r5, 0
	add sp, 0xC
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_806C444

	thumb_func_start sub_806C488
sub_806C488:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0xC
	adds r7, r1, 0
	mov r8, r2
	lsls r0, 16
	asrs r6, r0, 16
	adds r0, r6, 0
	mov r1, r8
	bl GetBaseOffensiveStat
	adds r5, r0, 0
	movs r4, 0x2
	cmp r4, r7
	bgt _0806C4C4
	mov r0, sp
	adds r0, 0x6
	add r8, r0
_0806C4AE:
	mov r0, sp
	adds r1, r6, 0
	adds r2, r4, 0
	bl GetPokemonLevelData
	mov r1, r8
	ldrb r0, [r1]
	adds r5, r0
	adds r4, 0x1
	cmp r4, r7
	ble _0806C4AE
_0806C4C4:
	adds r0, r5, 0
	add sp, 0xC
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_806C488

	thumb_func_start sub_806C4D4
sub_806C4D4:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0xC
	adds r7, r1, 0
	mov r8, r2
	lsls r0, 16
	asrs r6, r0, 16
	adds r0, r6, 0
	mov r1, r8
	bl GetBaseDefensiveStat
	adds r5, r0, 0
	movs r4, 0x2
	cmp r4, r7
	bgt _0806C50E
	add r0, sp, 0x8
	add r8, r0
_0806C4F8:
	mov r0, sp
	adds r1, r6, 0
	adds r2, r4, 0
	bl GetPokemonLevelData
	mov r1, r8
	ldrb r0, [r1]
	adds r5, r0
	adds r4, 0x1
	cmp r4, r7
	ble _0806C4F8
_0806C50E:
	adds r0, r5, 0
	add sp, 0xC
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_806C4D4

	thumb_func_start sub_806C51C
sub_806C51C:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x50
	adds r6, r0, 0
	ldr r0, [r6, 0x70]
	mov r8, r0
	ldr r0, _0806C544
	ldr r1, [r0]
	ldr r2, _0806C548
	adds r0, r1, r2
	ldr r0, [r0]
	cmp r0, r6
	bne _0806C54C
	movs r3, 0
	str r3, [sp, 0x38]
	b _0806C554
	.align 2, 0
_0806C544: .4byte gDungeon
_0806C548: .4byte 0x000181f8
_0806C54C:
	ldr r4, _0806C5AC
	adds r0, r1, r4
	ldrb r0, [r0]
	str r0, [sp, 0x38]
_0806C554:
	mov r0, r8
	adds r0, 0xC8
	ldrb r1, [r0]
	str r0, [sp, 0x40]
	cmp r1, 0x2
	bne _0806C564
	movs r7, 0x1
	str r7, [sp, 0x38]
_0806C564:
	adds r0, r6, 0
	adds r0, 0x6B
	adds r1, r6, 0
	adds r1, 0x6A
	ldrb r2, [r0]
	str r0, [sp, 0x48]
	mov r9, r1
	adds r5, r6, 0
	adds r5, 0x6D
	adds r0, 0x1
	str r0, [sp, 0x4C]
	adds r4, r6, 0
	adds r4, 0x6F
	subs r1, 0x47
	str r1, [sp, 0x44]
	mov r3, r9
	ldrb r3, [r3]
	cmp r2, r3
	bne _0806C676
	ldrb r0, [r5]
	ldr r7, [sp, 0x4C]
	ldrb r7, [r7]
	cmp r0, r7
	bne _0806C654
	ldrb r0, [r4]
	cmp r0, 0
	bne _0806C654
	movs r2, 0
	ldrh r1, [r6, 0x28]
	movs r0, 0x80
	lsls r0, 6
	ands r0, r1
	cmp r0, 0
	beq _0806C5B0
	movs r0, 0
	b _0806C5B2
	.align 2, 0
_0806C5AC: .4byte 0x00018210
_0806C5B0:
	lsrs r0, r1, 15
_0806C5B2:
	cmp r0, 0
	bne _0806C5B8
	movs r2, 0x1
_0806C5B8:
	adds r0, r6, 0
	adds r0, 0x23
	str r0, [sp, 0x44]
	cmp r2, 0
	beq _0806C654
	adds r0, r6, 0
	bl sub_806CEBC
	lsls r0, 24
	lsrs r3, r0, 24
	adds r1, r6, 0
	adds r1, 0x21
	movs r0, 0x1
	strb r0, [r1]
	mov r1, r8
	adds r1, 0xFE
	ldrb r0, [r1]
	cmp r0, 0x63
	bne _0806C620
	ldr r1, [sp, 0x48]
	ldrb r0, [r1]
	cmp r0, 0xC
	bhi _0806C61C
	mov r0, r8
	adds r0, 0xC0
	ldrb r0, [r0]
	cmp r0, 0x1
	bne _0806C5F4
	movs r2, 0x2
	b _0806C600
_0806C5F4:
	ldr r2, [sp, 0x44]
	ldrb r0, [r2]
	movs r2, 0x1
	cmp r0, 0x2
	bhi _0806C600
	movs r2, 0
_0806C600:
	ldr r1, _0806C618
	movs r0, 0xD
	muls r0, r2
	ldr r7, [sp, 0x48]
	ldrb r7, [r7]
	adds r0, r7
	adds r0, r1
	ldrb r0, [r0]
	cmp r0, 0x7
	bne _0806C622
	adds r0, r3, 0
	b _0806C622
	.align 2, 0
_0806C618: .4byte gUnknown_8106EC8
_0806C61C:
	movs r0, 0x63
	b _0806C622
_0806C620:
	ldrb r0, [r1]
_0806C622:
	cmp r0, 0x63
	beq _0806C654
	mov r1, r9
	strb r0, [r1]
	ldrb r1, [r5]
	movs r0, 0x7
	ands r0, r1
	ldr r2, [sp, 0x4C]
	strb r0, [r2]
	movs r0, 0x1
	strb r0, [r4]
	mov r7, r9
	ldrb r0, [r7]
	cmp r0, 0x6
	bne _0806C654
	adds r1, r6, 0
	adds r1, 0x6E
	ldrb r0, [r1]
	adds r0, 0x1
	strb r0, [r1]
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x10
	bne _0806C654
	strb r3, [r7]
_0806C654:
	ldr r1, [sp, 0x48]
	ldrb r0, [r1]
	mov r2, r9
	ldrb r2, [r2]
	cmp r0, r2
	bne _0806C676
	ldrb r0, [r5]
	ldr r3, [sp, 0x4C]
	ldrb r3, [r3]
	cmp r0, r3
	bne _0806C676
	ldrb r0, [r4]
	movs r7, 0x28
	adds r7, r6
	mov r10, r7
	cmp r0, 0
	beq _0806C714
_0806C676:
	mov r1, r9
	ldrb r0, [r1]
	ldr r2, [sp, 0x48]
	strb r0, [r2]
	ldr r3, [sp, 0x4C]
	mov r10, r3
	ldrb r0, [r3]
	strb r0, [r5]
	movs r7, 0
	strb r7, [r4]
	adds r0, r6, 0
	adds r0, 0x68
	movs r1, 0
	ldrsh r7, [r0, r1]
	mov r2, r8
	movs r3, 0x4
	ldrsh r0, [r2, r3]
	mov r4, r9
	ldrb r1, [r4]
	bl sub_808DA44
	lsls r0, 24
	cmp r0, 0
	beq _0806C6A8
	movs r7, 0
_0806C6A8:
	ldr r0, [sp, 0x38]
	cmp r0, 0
	bne _0806C6D6
	bl Rand32Bit
	movs r4, 0x3
	ands r4, r0
	adds r5, r6, 0
	adds r5, 0x28
	ldr r1, [r6, 0x64]
	mov r3, r9
	ldrb r2, [r3]
	mov r0, r10
	ldrb r3, [r0]
	str r7, [sp]
	str r4, [sp, 0x4]
	ldr r4, [sp, 0x38]
	str r4, [sp, 0x8]
	adds r0, r5, 0
	bl AxResInitFile
	mov r10, r5
	b _0806C704
_0806C6D6:
	ldr r0, _0806C774
	bl GetSpriteData
	adds r5, r0, 0
	bl Rand32Bit
	movs r1, 0x3
	ands r1, r0
	adds r4, r6, 0
	adds r4, 0x28
	mov r0, r9
	ldrb r2, [r0]
	ldr r0, [sp, 0x4C]
	ldrb r3, [r0]
	str r7, [sp]
	str r1, [sp, 0x4]
	movs r1, 0
	str r1, [sp, 0x8]
	adds r0, r4, 0
	adds r1, r5, 0
	bl AxResInitFile
	mov r10, r4
_0806C704:
	mov r2, r9
	ldrb r0, [r2]
	cmp r0, 0x6
	beq _0806C714
	adds r1, r6, 0
	adds r1, 0x6E
	movs r0, 0
	strb r0, [r1]
_0806C714:
	ldr r0, _0806C778
	ldr r1, [r0]
	ldr r3, _0806C77C
	adds r0, r1, r3
	ldrb r0, [r0]
	cmp r0, 0
	beq _0806C784
	ldr r4, [sp, 0x48]
	ldrb r0, [r4]
	cmp r0, 0x7
	bne _0806C73C
	mov r7, r8
	movs r1, 0x4
	ldrsh r0, [r7, r1]
	bl GetMovementType
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x2
	bne _0806C7E2
_0806C73C:
	movs r0, 0xAE
	lsls r0, 1
	add r0, r8
	ldrb r0, [r0]
	cmp r0, 0
	beq _0806C76A
	movs r0, 0xB0
	lsls r0, 1
	add r0, r8
	ldrb r0, [r0]
	cmp r0, 0
	bne _0806C7E2
	ldr r0, _0806C780
	add r0, r8
	ldrb r0, [r0]
	cmp r0, 0
	beq _0806C76A
	mov r0, r10
	bl RunAxAnimationFrame
	mov r0, r10
	bl RunAxAnimationFrame
_0806C76A:
	mov r0, r10
	bl RunAxAnimationFrame
	b _0806C7E2
	.align 2, 0
_0806C774: .4byte 0x000001a5
_0806C778: .4byte gDungeon
_0806C77C: .4byte 0x0001356c
_0806C780: .4byte 0x0000015f
_0806C784:
	mov r0, r8
	adds r0, 0xB0
	ldrb r0, [r0]
	cmp r0, 0x1
	beq _0806C7E2
	cmp r0, 0x6
	beq _0806C7E2
	ldr r2, _0806C7B4
	adds r0, r1, r2
	ldrb r0, [r0]
	cmp r0, 0
	beq _0806C7BC
	ldr r3, _0806C7B8
	adds r0, r1, r3
	ldrb r0, [r0]
	cmp r0, 0
	bne _0806C7BC
	mov r0, r10
	bl RunAxAnimationFrame
	mov r0, r10
	bl RunAxAnimationFrame
	b _0806C7DC
	.align 2, 0
_0806C7B4: .4byte 0x0000066c
_0806C7B8: .4byte 0x0001c05f
_0806C7BC:
	ldr r4, [sp, 0x48]
	ldrb r0, [r4]
	cmp r0, 0
	beq _0806C7C8
	cmp r0, 0x7
	bne _0806C7DC
_0806C7C8:
	ldr r0, [r6, 0x70]
	movs r7, 0x82
	lsls r7, 1
	adds r0, r7
	ldr r0, [r0]
	cmp r0, 0x1
	ble _0806C7DC
	mov r0, r10
	bl RunAxAnimationFrame
_0806C7DC:
	mov r0, r10
	bl RunAxAnimationFrame
_0806C7E2:
	ldr r1, [r6, 0xC]
	ldr r0, [r6, 0x14]
	cmp r1, r0
	bne _0806C800
	ldr r1, [r6, 0x10]
	ldr r0, [r6, 0x18]
	cmp r1, r0
	bne _0806C800
	ldr r1, [sp, 0x44]
	ldrb r0, [r1]
	cmp r0, 0x9
	bhi _0806C806
	adds r0, 0x1
	strb r0, [r1]
	b _0806C806
_0806C800:
	movs r0, 0
	ldr r2, [sp, 0x44]
	strb r0, [r2]
_0806C806:
	ldr r0, [r6, 0xC]
	str r0, [r6, 0x14]
	ldr r2, [r6, 0x10]
	str r2, [r6, 0x18]
	cmp r0, 0
	bge _0806C814
	adds r0, 0xFF
_0806C814:
	asrs r1, r0, 8
	ldr r0, _0806C88C
	ldr r3, [r0]
	ldr r4, _0806C890
	adds r0, r3, r4
	movs r7, 0
	ldrsh r0, [r0, r7]
	subs r1, r0
	str r1, [sp, 0x2C]
	ldr r0, [r6, 0x1C]
	subs r0, r2, r0
	movs r1, 0xBA
	lsls r1, 1
	add r1, r8
	ldr r1, [r1]
	subs r0, r1
	cmp r0, 0
	bge _0806C83A
	adds r0, 0xFF
_0806C83A:
	asrs r1, r0, 8
	ldr r4, _0806C894
	adds r0, r3, r4
	movs r7, 0
	ldrsh r3, [r0, r7]
	subs r1, r3
	str r1, [sp, 0x30]
	adds r0, r2, 0
	cmp r0, 0
	bge _0806C850
	adds r0, 0xFF
_0806C850:
	asrs r0, 8
	subs r0, r3
	mov r9, r0
	lsrs r0, 31
	add r0, r9
	asrs r0, 1
	mov r9, r0
	movs r0, 0xAB
	lsls r0, 1
	add r0, r8
	ldrb r0, [r0]
	cmp r0, 0
	bne _0806C870
	movs r0, 0x1
	negs r0, r0
	add r9, r0
_0806C870:
	movs r0, 0xAE
	lsls r0, 1
	add r0, r8
	ldrb r0, [r0]
	cmp r0, 0
	bne _0806C898
	adds r0, r6, 0
	bl sub_8042768
	lsls r0, 24
	lsrs r0, 24
	str r0, [sp, 0x34]
	b _0806C8D8
	.align 2, 0
_0806C88C: .4byte gDungeon
_0806C890: .4byte 0x000181f0
_0806C894: .4byte 0x000181f2
_0806C898:
	ldr r0, _0806C8B8
	add r0, r8
	ldrb r0, [r0]
	cmp r0, 0
	beq _0806C8C6
	ldr r0, _0806C8BC
	ldr r0, [r0]
	movs r1, 0x4
	ands r0, r1
	cmp r0, 0
	beq _0806C8C0
	ldr r1, [sp, 0x2C]
	adds r1, 0x1
	str r1, [sp, 0x2C]
	b _0806C8C6
	.align 2, 0
_0806C8B8: .4byte 0x0000015d
_0806C8BC: .4byte gUnknown_202EDCC
_0806C8C0:
	ldr r2, [sp, 0x2C]
	subs r2, 0x1
	str r2, [sp, 0x2C]
_0806C8C6:
	movs r1, 0
	movs r0, 0xAF
	lsls r0, 1
	add r0, r8
	ldrb r0, [r0]
	cmp r0, 0
	bne _0806C8D6
	movs r1, 0x1
_0806C8D6:
	str r1, [sp, 0x34]
_0806C8D8:
	ldr r0, [r6, 0xC]
	cmp r0, 0
	bge _0806C8E0
	adds r0, 0xFF
_0806C8E0:
	lsls r0, 8
	lsrs r0, 16
	ldr r1, _0806C998
	ldr r2, [sp, 0x28]
	ands r2, r1
	orrs r2, r0
	str r2, [sp, 0x28]
	ldr r1, [r6, 0x10]
	ldr r0, [r6, 0x1C]
	subs r1, r0
	movs r5, 0xBA
	lsls r5, 1
	add r5, r8
	ldr r0, [r5]
	subs r0, r1, r0
	cmp r0, 0
	bge _0806C904
	adds r0, 0xFF
_0806C904:
	lsls r0, 8
	lsrs r0, 16
	lsls r0, 16
	ldr r1, _0806C99C
	ands r2, r1
	orrs r2, r0
	str r2, [sp, 0x28]
	add r0, sp, 0xC
	mov r1, r10
	bl sub_8005700
	mov r4, r8
	adds r4, 0x98
	ldr r0, [r4]
	add r1, sp, 0x28
	ldr r2, _0806C9A0
	ldr r2, [r2]
	ldr r3, _0806C9A4
	adds r2, r3
	ldrb r3, [r2]
	add r2, sp, 0xC
	bl sub_800F958
	adds r0, r6, 0
	bl EntityGetStatusSprites
	adds r2, r0, 0
	ldr r4, [r4]
	mov r0, r8
	movs r1, 0x4
	ldrsh r7, [r0, r1]
	movs r3, 0
	ldr r0, [sp, 0x34]
	cmp r0, 0
	beq _0806C958
	movs r0, 0xA6
	lsls r0, 1
	add r0, r8
	ldrb r1, [r0]
	negs r0, r1
	orrs r0, r1
	lsrs r3, r0, 31
_0806C958:
	adds r0, r4, 0
	adds r1, r7, 0
	bl UpdateDungeonPokemonSprite
	adds r0, r6, 0
	mov r1, r9
	bl sub_8042EC8
	movs r0, 0xAE
	lsls r0, 1
	add r0, r8
	ldrb r1, [r0]
	cmp r1, 0
	bne _0806C9BA
	mov r0, r8
	adds r0, 0xFF
	ldrb r0, [r0]
	cmp r0, 0x1
	bne _0806C9AC
	ldr r1, [r5]
	ldr r0, _0806C9A8
	cmp r1, r0
	bgt _0806C9BA
	movs r2, 0x80
	lsls r2, 4
	adds r0, r1, r2
	str r0, [r5]
	movs r1, 0xC8
	lsls r1, 8
	cmp r0, r1
	ble _0806C9BA
	b _0806C9B8
	.align 2, 0
_0806C998: .4byte 0xffff0000
_0806C99C: .4byte 0x0000ffff
_0806C9A0: .4byte gDungeon
_0806C9A4: .4byte 0x00018208
_0806C9A8: .4byte 0x0000c7ff
_0806C9AC:
	ldr r0, [r5]
	ldr r3, _0806CA5C
	adds r0, r3
	str r0, [r5]
	cmp r0, 0
	bge _0806C9BA
_0806C9B8:
	str r1, [r5]
_0806C9BA:
	ldr r4, [sp, 0x34]
	cmp r4, 0
	bne _0806C9C2
	b _0806CBDE
_0806C9C2:
	movs r4, 0
	adds r0, r6, 0
	bl sub_806CF54
	lsls r0, 24
	lsrs r7, r0, 24
	add r1, sp, 0x1C
	ldr r2, _0806CA60
	strh r2, [r1]
	ldr r0, _0806CA64
	strh r0, [r1, 0x2]
	strh r2, [r1, 0x4]
	strh r4, [r1, 0x6]
	strh r4, [r1, 0x8]
	ldr r0, _0806CA68
	ldr r0, [r0]
	ldr r2, _0806CA6C
	adds r0, r2
	ldrb r0, [r0]
	lsls r0, 10
	strh r0, [r1, 0xA]
	mov r3, r8
	ldrb r0, [r3, 0x6]
	adds r5, r1, 0
	cmp r0, 0
	beq _0806CA08
	ldr r1, _0806CA70
	adds r0, r1, 0
	ldrh r2, [r3, 0x4]
	adds r0, r2
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0x2
	bhi _0806CA08
	movs r4, 0x1
_0806CA08:
	mov r0, r8
	adds r0, 0xE4
	ldrb r0, [r0]
	cmp r0, 0x1
	bne _0806CA22
	ldr r0, _0806CA68
	ldr r0, [r0]
	ldr r3, _0806CA74
	adds r0, r3
	ldrb r0, [r0]
	cmp r0, 0
	bne _0806CA22
	movs r4, 0x1
_0806CA22:
	cmp r4, 0
	beq _0806CA32
	ldrh r1, [r5, 0x6]
	movs r4, 0x80
	lsls r4, 3
	adds r0, r4, 0
	orrs r0, r1
	strh r0, [r5, 0x6]
_0806CA32:
	movs r0, 0
	str r0, [sp, 0x3C]
	mov r1, r8
	ldrb r0, [r1, 0x6]
	cmp r0, 0
	beq _0806CA46
	ldr r2, [sp, 0x40]
	ldrb r0, [r2]
	cmp r0, 0x2
	bne _0806CA4A
_0806CA46:
	movs r3, 0x1
	str r3, [sp, 0x3C]
_0806CA4A:
	mov r0, r8
	adds r0, 0x40
	ldrb r0, [r0]
	cmp r0, 0x4A
	beq _0806CA58
	cmp r0, 0x47
	bne _0806CA78
_0806CA58:
	movs r0, 0x1
	b _0806CA7A
	.align 2, 0
_0806CA5C: .4byte 0xfffff400
_0806CA60: .4byte 0x0000f3ff
_0806CA64: .4byte 0x0000ffff
_0806CA68: .4byte gDungeon
_0806CA6C: .4byte 0x00018208
_0806CA70: .4byte 0xfffffe5f
_0806CA74: .4byte 0x0001820f
_0806CA78:
	movs r0, 0
_0806CA7A:
	cmp r0, 0
	bne _0806CA88
	mov r0, r8
	adds r0, 0xA4
	ldrb r0, [r0]
	cmp r0, 0x1
	bne _0806CA8C
_0806CA88:
	movs r4, 0x1
	str r4, [sp, 0x3C]
_0806CA8C:
	mov r0, r8
	adds r0, 0xFF
	ldrb r0, [r0]
	cmp r0, 0x2
	beq _0806CB16
	mov r0, r8
	adds r0, 0xB0
	ldrb r1, [r0]
	cmp r1, 0x6
	beq _0806CAAC
	subs r0, 0x4
	ldrb r0, [r0]
	cmp r0, 0x4
	beq _0806CAAC
	cmp r1, 0x2
	bne _0806CABA
_0806CAAC:
	ldr r0, _0806CAC4
	ldr r0, [r0]
	movs r1, 0x2
	ands r0, r1
	ldr r1, [sp, 0x2C]
	adds r1, r0
	str r1, [sp, 0x2C]
_0806CABA:
	ldr r2, [sp, 0x38]
	cmp r2, 0
	beq _0806CACC
	ldr r0, _0806CAC8
	b _0806CAD2
	.align 2, 0
_0806CAC4: .4byte gUnknown_202EDCC
_0806CAC8: .4byte 0x000001a5
_0806CACC:
	mov r3, r8
	movs r4, 0x4
	ldrsh r0, [r3, r4]
_0806CAD2:
	movs r1, 0
	bl GetPokemonOverworldPalette
	lsls r0, 24
	lsrs r2, r0, 24
	adds r0, r6, 0
	adds r0, 0x22
	ldrb r1, [r0]
	cmp r1, 0
	bne _0806CAF8
	str r2, [sp]
	str r5, [sp, 0x4]
	mov r0, r10
	ldr r1, [sp, 0x2C]
	ldr r2, [sp, 0x30]
	mov r3, r9
	bl DoAxFrame_800558C
	b _0806CB16
_0806CAF8:
	cmp r1, 0x1
	bne _0806CB16
	ldr r0, _0806CBF0
	ldr r0, [r0]
	ands r0, r1
	cmp r0, 0
	beq _0806CB16
	str r2, [sp]
	str r5, [sp, 0x4]
	mov r0, r10
	ldr r1, [sp, 0x2C]
	ldr r2, [sp, 0x30]
	mov r3, r9
	bl DoAxFrame_800558C
_0806CB16:
	ldr r0, [r6, 0xC]
	cmp r0, 0
	bge _0806CB1E
	adds r0, 0xFF
_0806CB1E:
	asrs r0, 8
	ldrh r1, [r6, 0x38]
	adds r0, r1
	movs r1, 0xB8
	lsls r1, 1
	add r1, r8
	strh r0, [r1]
	ldr r0, [r6, 0x10]
	cmp r0, 0
	bge _0806CB34
	adds r0, 0xFF
_0806CB34:
	asrs r0, 8
	ldrh r2, [r6, 0x3A]
	adds r0, r2
	movs r3, 0xB9
	lsls r3, 1
	add r3, r8
	strh r0, [r3]
	movs r4, 0
	ldrsh r2, [r1, r4]
	ldr r0, _0806CBF4
	ldr r1, [r0]
	ldr r4, _0806CBF8
	adds r0, r1, r4
	movs r4, 0
	ldrsh r0, [r0, r4]
	subs r4, r2, r0
	movs r0, 0
	ldrsh r2, [r3, r0]
	ldr r3, _0806CBFC
	adds r1, r3
	movs r3, 0
	ldrsh r0, [r1, r3]
	subs r5, r2, r0
	movs r0, 0x20
	negs r0, r0
	cmp r4, r0
	blt _0806CBDE
	cmp r5, r0
	blt _0806CBDE
	ldr r0, _0806CC00
	cmp r4, r0
	bgt _0806CBDE
	cmp r5, 0xBF
	bgt _0806CBDE
	cmp r7, 0x6
	beq _0806CBDE
	adds r0, r6, 0
	adds r0, 0x22
	ldrb r0, [r0]
	cmp r0, 0
	bne _0806CBDE
	ldr r0, [sp, 0x3C]
	lsls r2, r0, 3
	adds r2, r0
	lsls r2, 3
	lsls r0, r7, 1
	adds r0, r7
	lsls r0, 2
	ldr r1, _0806CC04
	adds r0, r1
	adds r3, r2, r0
	movs r0, 0xAB
	lsls r0, 1
	add r0, r8
	ldrb r0, [r0]
	cmp r0, 0
	beq _0806CBDE
	movs r2, 0x8
	ldrsh r1, [r3, r2]
	adds r1, r4, r1
	ldr r0, _0806CC08
	ands r1, r0
	ldrh r2, [r3, 0x2]
	movs r0, 0xFE
	lsls r0, 8
	ands r0, r2
	orrs r0, r1
	strh r0, [r3, 0x2]
	movs r4, 0xA
	ldrsh r1, [r3, r4]
	adds r1, r5, r1
	ldr r0, _0806CC0C
	ands r1, r0
	lsls r1, 4
	ldrh r2, [r3, 0x6]
	movs r0, 0xF
	ands r0, r2
	orrs r0, r1
	strh r0, [r3, 0x6]
	adds r0, r3, 0
	movs r1, 0
	movs r2, 0
	movs r3, 0
	bl AddSprite
_0806CBDE:
	add sp, 0x50
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_0806CBF0: .4byte gUnknown_202EDCC
_0806CBF4: .4byte gDungeon
_0806CBF8: .4byte 0x000181f0
_0806CBFC: .4byte 0x000181f2
_0806CC00: .4byte 0x0000010f
_0806CC04: .4byte gUnknown_202ED28
_0806CC08: .4byte 0x000001ff
_0806CC0C: .4byte 0x00000fff
	thumb_func_end sub_806C51C

        .align 2,0
