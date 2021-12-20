	#include "asm/constants/gba_constants.inc"
	#include "asm/macros.inc"

	.syntax unified

	.text

	thumb_func_start sub_8048524
sub_8048524:
	push {r4-r6,lr}
	sub sp, 0x4
	adds r6, r0, 0
	adds r4, r1, 0
	ldr r0, [r4, 0x70]
	adds r5, r0, 0
	ldrb r0, [r5, 0x7]
	cmp r0, 0
	beq _08048542
	adds r0, r6, 0
	movs r2, 0
	movs r3, 0x5
	bl sub_8078A58
	b _080485A4
_08048542:
	ldr r0, _08048560
	adds r1, r4, 0
	movs r2, 0
	bl SetMessageArgument
	adds r0, r4, 0
	movs r1, 0x12
	bl HasIQSkill
	lsls r0, 24
	cmp r0, 0
	beq _08048568
	ldr r0, _08048564
	b _08048586
	.align 2, 0
_08048560: .4byte gAvailablePokemonNames
_08048564: .4byte gPtrSelfHealPreventedHungerMessage
_08048568:
	movs r0, 0x9E
	lsls r0, 1
	adds r5, r0
	ldr r0, [r5]
	bl GetBellyRoundedUp
	cmp r0, 0
	beq _08048598
	mov r0, sp
	movs r1, 0
	bl sub_80943A0
	ldr r0, [sp]
	str r0, [r5]
	ldr r0, _08048594
_08048586:
	ldr r2, [r0]
	adds r0, r6, 0
	adds r1, r4, 0
	bl sub_80522F4
	b _080485A4
	.align 2, 0
_08048594: .4byte gUnknown_80F9740
_08048598:
	ldr r0, _080485AC
	ldr r2, [r0]
	adds r0, r6, 0
	adds r1, r4, 0
	bl sub_80522F4
_080485A4:
	add sp, 0x4
	pop {r4-r6}
	pop {r0}
	bx r0
	.align 2, 0
_080485AC: .4byte gUnknown_80F9760
	thumb_func_end sub_8048524

	thumb_func_start sub_80485B0
sub_80485B0:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x4
	mov r9, r0
	mov r8, r1
	movs r0, 0
	str r0, [sp]
	movs r2, 0x1
	mov r10, r2
	ldr r4, [r1, 0x70]
	movs r0, 0x64
	bl DungeonRandomCapped
	ldr r1, _0804865C
	movs r2, 0
	ldrsh r1, [r1, r2]
	cmp r0, r1
	bge _080485DE
	movs r0, 0x3
	mov r10, r0
_080485DE:
	ldrb r0, [r4, 0x7]
	cmp r0, 0
	beq _0804867C
	movs r2, 0x8C
	lsls r2, 1
	adds r4, r2
	adds r5, r4, 0
	movs r7, 0x3
_080485EE:
	ldrb r1, [r4]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _0804862C
	movs r0, 0x8
	ands r0, r1
	cmp r0, 0
	beq _0804862C
	adds r0, r5, 0
	bl GetMovePower
	cmp r0, 0
	beq _0804862C
	ldrb r6, [r4, 0x5]
	adds r0, r5, 0
	bl GetMoveUnk12
	adds r1, r0, 0
	ldrb r0, [r4, 0x5]
	add r0, r10
	strb r0, [r4, 0x5]
	ldrb r0, [r4, 0x5]
	cmp r0, r1
	blt _08048622
	strb r1, [r4, 0x5]
_08048622:
	ldrb r0, [r4, 0x5]
	cmp r6, r0
	beq _0804862C
	movs r2, 0x1
	str r2, [sp]
_0804862C:
	adds r4, 0x8
	adds r5, 0x8
	subs r7, 0x1
	cmp r7, 0
	bge _080485EE
	ldr r0, [sp]
	cmp r0, 0
	beq _08048668
	ldr r0, _08048660
	ldr r2, [r0]
	mov r0, r9
	mov r1, r8
	bl sub_80522F4
	mov r2, r10
	cmp r2, 0x1
	beq _08048688
	movs r0, 0xA
	movs r1, 0x40
	bl sub_803E708
	ldr r0, _08048664
	b _0804866A
	.align 2, 0
_0804865C: .4byte gUnknown_80F4F46
_08048660: .4byte gUnknown_80FE454
_08048664: .4byte gUnknown_80FE434
_08048668:
	ldr r0, _08048678
_0804866A:
	ldr r2, [r0]
	mov r0, r9
	mov r1, r8
	bl sub_80522F4
	b _08048688
	.align 2, 0
_08048678: .4byte gUnknown_80FE40C
_0804867C:
	ldr r0, _08048698
	ldr r2, [r0]
	mov r0, r9
	mov r1, r8
	bl sub_80522F4
_08048688:
	add sp, 0x4
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_08048698: .4byte gUnknown_80FE40C
	thumb_func_end sub_80485B0

	thumb_func_start sub_804869C
sub_804869C:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0x1C
	adds r4, r0, 0
	adds r7, r1, 0
	lsls r2, 24
	cmp r2, 0
	beq _08048724
	ldr r5, [r7, 0x70]
	ldr r0, _080486D4
	ldr r0, [r0]
	ldr r1, _080486D8
	adds r0, r1
	ldrb r0, [r0]
	cmp r0, 0
	beq _080486E4
	ldr r0, _080486DC
	movs r1, 0
	ldrsh r6, [r0, r1]
	ldr r0, _080486E0
	ldr r2, [r0]
	adds r0, r4, 0
	adds r1, r7, 0
	bl sub_80522F4
	b _080486EA
	.align 2, 0
_080486D4: .4byte gDungeonGlobalData
_080486D8: .4byte 0x00000675
_080486DC: .4byte gUnknown_80F4FA8
_080486E0: .4byte gUnknown_80FEAE8
_080486E4:
	ldr r0, _0804871C
	movs r1, 0
	ldrsh r6, [r0, r1]
_080486EA:
	adds r0, r5, 0
	adds r0, 0xB0
	ldrb r0, [r0]
	cmp r0, 0x1
	bne _080486FC
	adds r0, r4, 0
	adds r1, r7, 0
	bl SendImmobilizeEndMessage
_080486FC:
	add r0, sp, 0x18
	str r0, [sp]
	movs r1, 0
	str r1, [sp, 0x4]
	ldr r0, _08048720
	str r0, [sp, 0x8]
	str r1, [sp, 0xC]
	str r1, [sp, 0x10]
	str r1, [sp, 0x14]
	adds r0, r4, 0
	adds r1, r7, 0
	adds r2, r6, 0
	movs r3, 0x1
	bl sub_806F370
	b _080487B6
	.align 2, 0
_0804871C: .4byte gUnknown_80F4FA4
_08048720: .4byte 0x00000216
_08048724:
	adds r0, r4, 0
	bl sub_8042520
	adds r0, r4, 0
	bl sub_80696FC
	adds r5, r0, 0
	cmp r5, 0
	bne _08048748
	ldr r0, _08048744
	ldr r2, [r0]
	adds r0, r4, 0
	adds r1, r7, 0
	bl sub_80522F4
	b _080487B6
	.align 2, 0
_08048744: .4byte gUnknown_80FDBA0
_08048748:
	ldr r1, [r5, 0x70]
	mov r8, r1
	ldr r0, _08048770
	ldr r0, [r0]
	ldr r1, _08048774
	adds r0, r1
	ldrb r0, [r0]
	cmp r0, 0
	beq _08048780
	ldr r0, _08048778
	movs r1, 0
	ldrsh r6, [r0, r1]
	ldr r0, _0804877C
	ldr r2, [r0]
	adds r0, r4, 0
	adds r1, r7, 0
	bl sub_80522F4
	b _08048786
	.align 2, 0
_08048770: .4byte gDungeonGlobalData
_08048774: .4byte 0x00000675
_08048778: .4byte gUnknown_80F4FAA
_0804877C: .4byte gUnknown_80FEAE8
_08048780:
	ldr r0, _080487C4
	movs r1, 0
	ldrsh r6, [r0, r1]
_08048786:
	mov r0, r8
	adds r0, 0xB0
	ldrb r0, [r0]
	cmp r0, 0x1
	bne _08048798
	adds r0, r4, 0
	adds r1, r5, 0
	bl SendImmobilizeEndMessage
_08048798:
	add r0, sp, 0x18
	str r0, [sp]
	movs r1, 0
	str r1, [sp, 0x4]
	ldr r0, _080487C8
	str r0, [sp, 0x8]
	str r1, [sp, 0xC]
	str r1, [sp, 0x10]
	str r1, [sp, 0x14]
	adds r0, r4, 0
	adds r1, r5, 0
	adds r2, r6, 0
	movs r3, 0x1
	bl sub_806F370
_080487B6:
	add sp, 0x1C
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_080487C4: .4byte gUnknown_80F4FA6
_080487C8: .4byte 0x00000216
	thumb_func_end sub_804869C

	thumb_func_start sub_80487CC
sub_80487CC:
	push {r4,lr}
	sub sp, 0x4
	movs r4, 0x1
	str r4, [sp]
	bl sub_8078B5C
	add sp, 0x4
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_80487CC

	thumb_func_start sub_80487E0
sub_80487E0:
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	sub sp, 0x4
	mov r9, r0
	mov r8, r1
	lsls r3, r2, 24
	ldr r5, [r1, 0x70]
	ldr r4, _08048858
	lsrs r3, 23
	adds r0, r5, 0
	adds r0, 0x5C
	ldrb r0, [r0]
	lsls r1, r0, 3
	adds r1, r0
	lsls r1, 2
	adds r1, r3, r1
	adds r0, r1, r4
	movs r2, 0
	ldrsh r6, [r0, r2]
	adds r0, r5, 0
	adds r0, 0x5D
	ldrb r2, [r0]
	lsls r0, r2, 3
	adds r0, r2
	lsls r0, 2
	adds r3, r0
	adds r4, r3, r4
	movs r2, 0
	ldrsh r0, [r4, r2]
	adds r6, r0
	ldr r0, _0804885C
	adds r1, r0
	movs r4, 0
	ldrsh r2, [r1, r4]
	adds r3, r0
	movs r1, 0
	ldrsh r0, [r3, r1]
	adds r2, r0
	movs r0, 0x1
	str r0, [sp]
	mov r0, r9
	mov r1, r8
	movs r3, 0
	bl sub_8078B5C
	ldrb r0, [r5, 0x6]
	cmp r0, 0
	bne _08048906
	adds r0, r5, 0
	adds r0, 0x40
	ldrb r0, [r0]
	cmp r0, 0x4A
	beq _08048852
	cmp r0, 0x47
	bne _08048860
_08048852:
	movs r0, 0x1
	b _08048862
	.align 2, 0
_08048858: .4byte gTypeGummiIQBoost
_0804885C: .4byte gUnknown_810A808
_08048860:
	movs r0, 0
_08048862:
	cmp r0, 0
	bne _08048906
	movs r2, 0xC
	ldrsh r7, [r5, r2]
	ldrh r0, [r5, 0xC]
	adds r0, r6
	strh r0, [r5, 0xC]
	adds r2, r7, r6
	lsls r0, 16
	cmp r0, 0
	bgt _0804887C
	movs r0, 0x1
	strh r0, [r5, 0xC]
_0804887C:
	movs r4, 0xC
	ldrsh r0, [r5, r4]
	ldr r1, _080488A0
	cmp r0, r1
	ble _08048888
	strh r1, [r5, 0xC]
_08048888:
	movs r1, 0xC
	ldrsh r0, [r5, r1]
	cmp r7, r0
	bne _080488A8
	ldr r0, _080488A4
	ldr r2, [r0]
	mov r0, r9
	mov r1, r8
	bl sub_80522F4
	b _08048906
	.align 2, 0
_080488A0: .4byte 0x000003e7
_080488A4: .4byte gUnknown_80FD644
_080488A8:
	subs r0, r2, r7
	movs r2, 0
	cmp r0, 0x8
	bgt _080488BE
	movs r2, 0x1
	cmp r0, 0x4
	bgt _080488BE
	movs r2, 0x3
	cmp r0, 0x2
	ble _080488BE
	movs r2, 0x2
_080488BE:
	movs r4, 0xC
	ldrsh r0, [r5, r4]
	subs r0, r7
	movs r4, 0
	cmp r0, 0x8
	bgt _080488D8
	movs r4, 0x1
	cmp r0, 0x4
	bgt _080488D8
	movs r4, 0x3
	cmp r0, 0x2
	ble _080488D8
	movs r4, 0x2
_080488D8:
	ldr r1, _08048914
	lsls r0, r2, 2
	adds r0, r1
	ldr r2, [r0]
	mov r0, r9
	mov r1, r8
	bl sub_80522F4
	ldr r1, _08048918
	lsls r0, r4, 2
	adds r0, r1
	ldr r2, [r0]
	mov r0, r9
	mov r1, r8
	bl sub_80522F4
	mov r0, r8
	bl LoadIQSkills
	adds r0, r5, 0
	adds r1, r7, 0
	bl sub_806A7E8
_08048906:
	add sp, 0x4
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_08048914: .4byte gUnknown_80FD648
_08048918: .4byte gUnknown_80FD6E8
	thumb_func_end sub_80487E0

	thumb_func_start sub_804891C
sub_804891C:
	push {lr}
	movs r2, 0x3
	bl sub_80793B0
	pop {r0}
	bx r0
	thumb_func_end sub_804891C

	thumb_func_start sub_8048928
sub_8048928:
	push {lr}
	movs r2, 0x3
	bl sub_8079420
	pop {r0}
	bx r0
	thumb_func_end sub_8048928

	thumb_func_start sub_8048934
sub_8048934:
	push {lr}
	movs r2, 0x3
	bl sub_8079490
	pop {r0}
	bx r0
	thumb_func_end sub_8048934

	thumb_func_start sub_8048940
sub_8048940:
	push {lr}
	movs r2, 0x3
	bl sub_8079500
	pop {r0}
	bx r0
	thumb_func_end sub_8048940

	thumb_func_start nullsub_94
nullsub_94:
	bx lr
	thumb_func_end nullsub_94

	thumb_func_start sub_8048950
sub_8048950:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	mov r10, r0
	mov r8, r1
	ldrb r0, [r1, 0x2]
	bl GetItemMove
	lsls r0, 16
	lsrs r0, 16
	mov r9, r0
	mov r0, r8
	ldrb r1, [r0]
	movs r0, 0x8
	ands r0, r1
	cmp r0, 0
	beq _08048988
	ldr r0, _08048984
_08048978:
	ldr r1, [r0]
	movs r0, 0
	movs r2, 0x1
	bl PrintFieldMessage
	b _08048A58
	.align 2, 0
_08048984: .4byte gUnknown_80FE3E8
_08048988:
	mov r1, r8
	ldrb r0, [r1, 0x2]
	bl IsHMItem
	lsls r0, 24
	cmp r0, 0
	beq _080489A0
	ldr r0, _0804899C
	b _08048978
	.align 2, 0
_0804899C: .4byte gPtrCantUseInDungeonMessage
_080489A0:
	movs r7, 0
_080489A2:
	ldr r0, _080489FC
	ldr r0, [r0]
	lsls r1, r7, 2
	ldr r2, _08048A00
	adds r0, r2
	adds r0, r1
	ldr r4, [r0]
	adds r0, r4, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	beq _08048A12
	ldr r6, [r4, 0x70]
	movs r0, 0x2
	ldrsh r1, [r6, r0]
	mov r0, r9
	bl CanMonLearnMove
	lsls r0, 24
	lsrs r5, r0, 24
	adds r0, r4, 0
	movs r1, 0
	bl CannotMove
	lsls r0, 24
	cmp r0, 0
	beq _080489DC
	movs r5, 0
_080489DC:
	adds r0, r6, 0
	adds r0, 0xA4
	ldrb r0, [r0]
	cmp r0, 0x1
	bne _080489E8
	movs r5, 0
_080489E8:
	adds r0, r6, 0
	adds r0, 0x40
	ldrb r0, [r0]
	cmp r0, 0x4A
	beq _080489F6
	cmp r0, 0x47
	bne _08048A04
_080489F6:
	movs r0, 0x1
	b _08048A06
	.align 2, 0
_080489FC: .4byte gDungeonGlobalData
_08048A00: .4byte 0x0001357c
_08048A04:
	movs r0, 0
_08048A06:
	cmp r0, 0
	beq _08048A0C
	movs r5, 0
_08048A0C:
	ldr r1, _08048A50
	adds r0, r6, r1
	strb r5, [r0]
_08048A12:
	adds r7, 0x1
	cmp r7, 0x3
	ble _080489A2
	movs r0, 0
	movs r1, 0x1
	bl DrawFieldGiveItemMenu
	adds r4, r0, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	beq _08048A58
	mov r0, r10
	mov r1, r8
	bl sub_804245C
	adds r0, r4, 0
	mov r1, r9
	bl sub_8072938
	lsls r0, 24
	cmp r0, 0
	beq _08048A58
	ldr r2, _08048A54
	mov r0, r10
	movs r1, 0
	bl sub_8044E24
	movs r0, 0x1
	b _08048A5A
	.align 2, 0
_08048A50: .4byte 0x00000157
_08048A54: .4byte 0x00000141
_08048A58:
	movs r0, 0
_08048A5A:
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_8048950

	thumb_func_start sub_8048A68
sub_8048A68:
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	mov r9, r0
	mov r8, r1
	ldrb r1, [r1]
	movs r0, 0x8
	ands r0, r1
	cmp r0, 0
	beq _08048A90
	ldr r0, _08048A8C
_08048A80:
	ldr r1, [r0]
	movs r0, 0
	movs r2, 0x1
	bl PrintFieldMessage
	b _08048B8C
	.align 2, 0
_08048A8C: .4byte gUnknown_80FE3E8
_08048A90:
	ldr r0, _08048AA4
	ldr r0, [r0]
	ldr r1, _08048AA8
	adds r0, r1
	ldrb r0, [r0]
	cmp r0, 0
	bne _08048AB0
	ldr r0, _08048AAC
	b _08048A80
	.align 2, 0
_08048AA4: .4byte gDungeonGlobalData
_08048AA8: .4byte 0x0000065c
_08048AAC: .4byte gUnknown_80F9BD8
_08048AB0:
	movs r7, 0
_08048AB2:
	ldr r0, _08048B24
	ldr r0, [r0]
	lsls r1, r7, 2
	ldr r2, _08048B28
	adds r0, r2
	adds r0, r1
	ldr r4, [r0]
	adds r0, r4, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	beq _08048B4A
	ldr r5, [r4, 0x70]
	movs r6, 0x1
	ldrb r0, [r5, 0xA]
	cmp r0, 0x3
	bhi _08048AF4
	ldr r2, _08048B2C
	ldrb r1, [r5, 0xA]
	movs r0, 0x64
	muls r1, r0
	ldr r0, _08048B30
	adds r1, r0
	ldr r0, [r2]
	adds r0, r1
	movs r1, 0xA
	ldrsh r0, [r0, r1]
	bl sub_806A538
	lsls r0, 24
	cmp r0, 0
	beq _08048AF6
_08048AF4:
	movs r6, 0
_08048AF6:
	adds r0, r4, 0
	movs r1, 0
	bl CannotMove
	lsls r0, 24
	cmp r0, 0
	beq _08048B06
	movs r6, 0
_08048B06:
	adds r0, r5, 0
	adds r0, 0xA4
	ldrb r0, [r0]
	cmp r0, 0x1
	bne _08048B12
	movs r6, 0
_08048B12:
	adds r0, r5, 0
	adds r0, 0x40
	ldrb r0, [r0]
	cmp r0, 0x4A
	beq _08048B20
	cmp r0, 0x47
	bne _08048B34
_08048B20:
	movs r0, 0x1
	b _08048B36
	.align 2, 0
_08048B24: .4byte gDungeonGlobalData
_08048B28: .4byte 0x0001357c
_08048B2C: .4byte gRecruitedPokemonRef
_08048B30: .4byte 0x00008df8
_08048B34:
	movs r0, 0
_08048B36:
	cmp r0, 0
	beq _08048B3C
	movs r6, 0
_08048B3C:
	ldrb r0, [r5, 0x7]
	cmp r0, 0
	beq _08048B44
	movs r6, 0
_08048B44:
	ldr r2, _08048B84
	adds r0, r5, r2
	strb r6, [r0]
_08048B4A:
	adds r7, 0x1
	cmp r7, 0x3
	ble _08048AB2
	movs r0, 0
	movs r1, 0x1
	bl DrawFieldGiveItemMenu
	adds r4, r0, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	beq _08048B8C
	mov r0, r9
	mov r1, r8
	bl sub_804245C
	ldr r0, _08048B88
	ldr r0, [r0]
	adds r0, 0xBC
	str r4, [r0]
	movs r2, 0xA1
	lsls r2, 1
	mov r0, r9
	movs r1, 0
	bl sub_8044E24
	movs r0, 0x1
	b _08048B8E
	.align 2, 0
_08048B84: .4byte 0x00000157
_08048B88: .4byte gDungeonGlobalData
_08048B8C:
	movs r0, 0
_08048B8E:
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_8048A68

	thumb_func_start sub_8048B9C
sub_8048B9C:
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	sub sp, 0x20
	mov r9, r0
	movs r0, 0
	mov r8, r0
	mov r2, r9
	ldr r0, [r2, 0x70]
	adds r6, r0, 0
	adds r6, 0x44
	ldrb r1, [r1]
	movs r0, 0x8
	ands r0, r1
	cmp r0, 0
	beq _08048BD4
	ldr r0, _08048BD0
	ldr r1, [r0]
	movs r0, 0
	movs r2, 0x1
	bl PrintFieldMessage
	movs r0, 0
	b _08048D40
	.align 2, 0
_08048BD0: .4byte gUnknown_80FE3E8
_08048BD4:
	movs r2, 0
_08048BD6:
	ldr r0, _08048C28
	ldr r0, [r0]
	lsls r1, r2, 2
	ldr r3, _08048C2C
	adds r0, r3
	adds r0, r1
	ldr r4, [r0]
	adds r0, r4, 0
	str r2, [sp, 0x1C]
	bl EntityExists
	lsls r0, 24
	ldr r2, [sp, 0x1C]
	cmp r0, 0
	beq _08048C3E
	ldr r5, [r4, 0x70]
	movs r7, 0x1
	adds r0, r4, 0
	movs r1, 0
	bl CannotMove
	lsls r0, 24
	ldr r2, [sp, 0x1C]
	cmp r0, 0
	beq _08048C0A
	movs r7, 0
_08048C0A:
	adds r0, r5, 0
	adds r0, 0xA4
	ldrb r0, [r0]
	cmp r0, 0x1
	bne _08048C16
	movs r7, 0
_08048C16:
	adds r0, r5, 0
	adds r0, 0x40
	ldrb r0, [r0]
	cmp r0, 0x4A
	beq _08048C24
	cmp r0, 0x47
	bne _08048C30
_08048C24:
	movs r0, 0x1
	b _08048C32
	.align 2, 0
_08048C28: .4byte gDungeonGlobalData
_08048C2C: .4byte 0x0001357c
_08048C30:
	movs r0, 0
_08048C32:
	cmp r0, 0
	beq _08048C38
	movs r7, 0
_08048C38:
	ldr r4, _08048C5C
	adds r0, r5, r4
	strb r7, [r0]
_08048C3E:
	adds r2, 0x1
	cmp r2, 0x3
	ble _08048BD6
	movs r0, 0
	movs r1, 0x1
	bl DrawFieldGiveItemMenu
	adds r4, r0, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	bne _08048C60
	movs r0, 0
	b _08048D40
	.align 2, 0
_08048C5C: .4byte 0x00000157
_08048C60:
	add r1, sp, 0x4
	adds r0, r6, 0
	ldm r0!, {r2,r3,r5}
	stm r1!, {r2,r3,r5}
	ldm r0!, {r2,r3,r5}
	stm r1!, {r2,r3,r5}
	b _08048CE2
_08048C6E:
	ldrh r0, [r6]
	cmp r0, 0x1D
	bne _08048C7C
	adds r0, r6, 0
	bl sub_80637E8
	b _08048CE2
_08048C7C:
	cmp r0, 0x20
	bne _08048C9A
	movs r0, 0
	movs r1, 0
	bl sub_803EAF0
	adds r0, r6, 0
	bl sub_8063BB4
	movs r0, 0x1
	bl sub_8044C10
	movs r5, 0x1
	mov r8, r5
	b _08048CE2
_08048C9A:
	cmp r0, 0x21
	bne _08048CB6
	movs r0, 0
	movs r1, 0
	bl sub_803EAF0
	adds r0, r6, 0
	movs r1, 0
	bl sub_8063CF0
	movs r0, 0x1
	bl sub_8044C10
	b _08048CE2
_08048CB6:
	cmp r0, 0x1E
	beq _08048CBE
	cmp r0, 0x33
	bne _08048CD0
_08048CBE:
	movs r0, 0
	movs r1, 0
	bl sub_803EAF0
	adds r0, r6, 0
	movs r1, 0
	bl sub_8063A70
	b _08048CE2
_08048CD0:
	cmp r0, 0x1F
	bne _08048CE2
	movs r0, 0
	movs r1, 0
	bl sub_803EAF0
	adds r0, r6, 0
	bl sub_8063B54
_08048CE2:
	adds r0, r6, 0
	bl ResetAction
	movs r0, 0x1
	str r0, [sp]
	adds r0, r4, 0
	movs r1, 0x1
	movs r2, 0
	movs r3, 0
	bl sub_8062F90
	lsls r0, 24
	cmp r0, 0
	beq _08048C6E
	mov r0, r8
	cmp r0, 0
	beq _08048D38
	ldr r0, _08048D34
	ldr r1, [r0]
	movs r0, 0
	movs r2, 0x1
	bl sub_8052B8C
	cmp r0, 0x1
	bne _08048C6E
	adds r1, r6, 0
	add r0, sp, 0x4
	ldm r0!, {r2-r4}
	stm r1!, {r2-r4}
	ldm r0!, {r2,r3,r5}
	stm r1!, {r2,r3,r5}
	mov r0, r9
	movs r1, 0
	movs r2, 0x6E
	bl sub_8044DF0
	adds r0, r6, 0
	movs r1, 0x2C
	bl SetAction
	b _08048D3E
	.align 2, 0
_08048D34: .4byte gUnknown_80FECA0
_08048D38:
	movs r0, 0x1
	bl sub_8044C10
_08048D3E:
	mov r0, r8
_08048D40:
	add sp, 0x20
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_8048B9C

	thumb_func_start sub_8048D50
sub_8048D50:
	push {r4,lr}
	adds r4, r0, 0
	adds r2, r1, 0
	ldr r3, [r4, 0x70]
	ldrb r1, [r2]
	movs r0, 0x8
	ands r0, r1
	cmp r0, 0
	beq _08048D78
	ldr r0, _08048D70
	adds r1, r2, 0
	bl sub_8045BF8
	ldr r0, _08048D74
	b _08048D9A
	.align 2, 0
_08048D70: .4byte gUnknown_202DE58
_08048D74: .4byte gUnknown_80FE3E8
_08048D78:
	adds r0, r3, 0
	adds r0, 0xEC
	ldrb r0, [r0]
	cmp r0, 0x1
	bne _08048DB0
	ldrb r0, [r2, 0x2]
	bl IsEdibleItem
	lsls r0, 24
	cmp r0, 0
	beq _08048DB0
	ldr r0, _08048DA8
	adds r1, r4, 0
	movs r2, 0
	bl SetMessageArgument
	ldr r0, _08048DAC
_08048D9A:
	ldr r1, [r0]
	adds r0, r4, 0
	bl SendMessage
	movs r0, 0
	b _08048DB2
	.align 2, 0
_08048DA8: .4byte gAvailablePokemonNames
_08048DAC: .4byte gUnknown_80FDCA4
_08048DB0:
	movs r0, 0x1
_08048DB2:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_8048D50

	thumb_func_start sub_8048DB8
sub_8048DB8:
	push {r4,lr}
	sub sp, 0x1C
	adds r3, r0, 0
	adds r4, r1, 0
	lsls r2, 24
	cmp r2, 0
	beq _08048DF4
	ldr r0, _08048DEC
	movs r1, 0
	ldrsh r2, [r0, r1]
	add r0, sp, 0x18
	str r0, [sp]
	movs r1, 0
	str r1, [sp, 0x4]
	ldr r0, _08048DF0
	str r0, [sp, 0x8]
	str r1, [sp, 0xC]
	str r1, [sp, 0x10]
	str r1, [sp, 0x14]
	adds r0, r3, 0
	adds r1, r4, 0
	movs r3, 0x1
	bl sub_806F370
	b _08048DFA
	.align 2, 0
_08048DEC: .4byte gUnknown_80F4FAC
_08048DF0: .4byte 0x00000217
_08048DF4:
	adds r0, r3, 0
	bl sub_8051E7C
_08048DFA:
	add sp, 0x1C
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_8048DB8

	thumb_func_start sub_8048E04
sub_8048E04:
	push {r4-r6,lr}
	sub sp, 0x8
	adds r5, r0, 0
	adds r6, r1, 0
	movs r0, 0x1
	str r0, [sp]
	adds r0, r5, 0
	movs r2, 0x1E
	movs r3, 0
	bl sub_8078B5C
	movs r0, 0x5
	bl DungeonRandomCapped
	cmp r0, 0x4
	bhi _08048E9E
	lsls r0, 2
	ldr r1, _08048E30
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08048E30: .4byte _08048E34
	.align 2, 0
_08048E34:
	.4byte _08048E48
	.4byte _08048E54
	.4byte _08048E5E
	.4byte _08048E6C
	.4byte _08048E78
_08048E48:
	adds r0, r5, 0
	adds r1, r6, 0
	movs r2, 0x1
	bl sub_80763F8
	b _08048E9E
_08048E54:
	adds r0, r5, 0
	adds r1, r6, 0
	bl sub_80769CC
	b _08048E9E
_08048E5E:
	adds r0, r5, 0
	adds r1, r6, 0
	movs r2, 0x1
	movs r3, 0x1
	bl sub_8076210
	b _08048E9E
_08048E6C:
	adds r0, r5, 0
	adds r1, r6, 0
	movs r2, 0x1
	bl sub_8077780
	b _08048E9E
_08048E78:
	ldr r0, _08048EA8
	ldr r2, [r0]
	movs r4, 0x1
	str r4, [sp]
	str r4, [sp, 0x4]
	adds r0, r5, 0
	adds r1, r6, 0
	movs r3, 0x3
	bl sub_8076E20
	ldr r0, _08048EAC
	ldr r2, [r0]
	str r4, [sp]
	str r4, [sp, 0x4]
	adds r0, r5, 0
	adds r1, r6, 0
	movs r3, 0x3
	bl sub_8076E20
_08048E9E:
	add sp, 0x8
	pop {r4-r6}
	pop {r0}
	bx r0
	.align 2, 0
_08048EA8: .4byte gUnknown_8106A4C
_08048EAC: .4byte gUnknown_8106A50
	thumb_func_end sub_8048E04

	thumb_func_start sub_8048EB0
sub_8048EB0:
	push {lr}
	ldr r1, _08048EC0
	ldr r1, [r1]
	bl SendMessage
	pop {r0}
	bx r0
	.align 2, 0
_08048EC0: .4byte gPtrIcePartCrumbledMessage
	thumb_func_end sub_8048EB0

	thumb_func_start sub_8048EC4
sub_8048EC4:
	push {lr}
	ldr r1, _08048ED4
	ldr r1, [r1]
	bl SendMessage
	pop {r0}
	bx r0
	.align 2, 0
_08048ED4: .4byte gPtrRockPartCrumbledMessage
	thumb_func_end sub_8048EC4

	thumb_func_start sub_8048ED8
sub_8048ED8:
	push {lr}
	ldr r1, _08048EE8
	ldr r1, [r1]
	bl SendMessage
	pop {r0}
	bx r0
	.align 2, 0
_08048EE8: .4byte gPtrSteelPartCrumbledMessage
	thumb_func_end sub_8048ED8

	thumb_func_start sub_8048EEC
sub_8048EEC:
	push {lr}
	ldr r1, _08048EFC
	ldr r1, [r1]
	bl SendMessage
	pop {r0}
	bx r0
	.align 2, 0
_08048EFC: .4byte gPtrWishStoneCrumbledMessage
	thumb_func_end sub_8048EEC

	thumb_func_start sub_8048F00
sub_8048F00:
	push {r4,lr}
	adds r4, r0, 0
	movs r1, 0xD6
	bl sub_80421C0
	ldr r0, _08048F24
	ldr r1, [r0]
	adds r0, r4, 0
	bl SendMessage
	movs r0, 0x3C
	movs r1, 0x46
	bl sub_803E708
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08048F24: .4byte gPtrMusicBoxPlayedCrumbledMessage
	thumb_func_end sub_8048F00

	thumb_func_start EvaluateItem
EvaluateItem:
	push {r4-r7,lr}
	sub sp, 0x4
	adds r4, r0, 0
	ldr r3, [r4, 0x70]
	movs r6, 0
	movs r0, 0x1
	adds r5, r2, 0
	ands r5, r0
	lsrs r2, 1
	movs r0, 0x1
	ands r2, r0
	ldrb r0, [r1, 0x2]
	subs r0, 0x1
	cmp r0, 0xCC
	bls _08048F48
	b _080494E0
_08048F48:
	lsls r0, 2
	ldr r1, _08048F54
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08048F54: .4byte _08048F58
	.align 2, 0
_08048F58:
	.4byte _0804928C
	.4byte _0804928C
	.4byte _0804928C
	.4byte _0804928C
	.4byte _0804928C
	.4byte _0804928C
	.4byte _0804928C
	.4byte _0804928C
	.4byte _080494E0
	.4byte _080494E0
	.4byte _080494E0
	.4byte _080494E0
	.4byte _08049408
	.4byte _080494E0
	.4byte _080494E0
	.4byte _080494E0
	.4byte _080494E0
	.4byte _080494E0
	.4byte _080494E0
	.4byte _080494E0
	.4byte _080494E0
	.4byte _080494E0
	.4byte _080494E0
	.4byte _080494E0
	.4byte _080494E0
	.4byte _080494E0
	.4byte _08049296
	.4byte _080494E0
	.4byte _080494E0
	.4byte _080494E0
	.4byte _080494E0
	.4byte _080494E0
	.4byte _080494E0
	.4byte _080494E0
	.4byte _080494E0
	.4byte _080494E0
	.4byte _080494E0
	.4byte _080494E0
	.4byte _080494E0
	.4byte _080492B0
	.4byte _080492B0
	.4byte _080494E0
	.4byte _080494E0
	.4byte _080494E0
	.4byte _080494E0
	.4byte _080494E0
	.4byte _080494E0
	.4byte _080494E0
	.4byte _080494E0
	.4byte _080494E0
	.4byte _080494E0
	.4byte _080494E0
	.4byte _08049320
	.4byte _080494E0
	.4byte _080492B8
	.4byte _080492B8
	.4byte _0804935E
	.4byte _080494E0
	.4byte _080493E0
	.4byte _0804948E
	.4byte _08049394
	.4byte _08049344
	.4byte _0804946E
	.4byte _0804947A
	.4byte _08049378
	.4byte _080493CE
	.4byte _080493AC
	.4byte _080493B8
	.4byte _08049436
	.4byte _080494E0
	.4byte _080493F6
	.4byte _080494B2
	.4byte _0804946A
	.4byte _08049462
	.4byte _08049454
	.4byte _08049498
	.4byte _080492DC
	.4byte _0804932C
	.4byte _08049338
	.4byte _0804933C
	.4byte _08049340
	.4byte _080494C2
	.4byte _080494C2
	.4byte _080494D6
	.4byte _080494C2
	.4byte _080494E0
	.4byte _080494E0
	.4byte _080494E0
	.4byte _080494E0
	.4byte _080494E0
	.4byte _080494E0
	.4byte _080494E0
	.4byte _080494E0
	.4byte _080494E0
	.4byte _080494E0
	.4byte _080494E0
	.4byte _080494E0
	.4byte _080494E0
	.4byte _080494E0
	.4byte _080494E0
	.4byte _080494E0
	.4byte _080494E0
	.4byte _080494E0
	.4byte _080494E0
	.4byte _080494E0
	.4byte _080494E0
	.4byte _080494E0
	.4byte _080494E0
	.4byte _080494E0
	.4byte _080494E0
	.4byte _080494E0
	.4byte _080494E0
	.4byte _080494E0
	.4byte _080494E0
	.4byte _080494E0
	.4byte _080494E0
	.4byte _080494E0
	.4byte _080494E0
	.4byte _080494E0
	.4byte _080494E0
	.4byte _080494E0
	.4byte _080494E0
	.4byte _080494E0
	.4byte _080494E0
	.4byte _080494E0
	.4byte _080494E0
	.4byte _080494E0
	.4byte _080494E0
	.4byte _080494E0
	.4byte _080494E0
	.4byte _080494E0
	.4byte _080494E0
	.4byte _080494E0
	.4byte _080494E0
	.4byte _080494E0
	.4byte _080494E0
	.4byte _080494E0
	.4byte _080494E0
	.4byte _080494E0
	.4byte _080494E0
	.4byte _080494E0
	.4byte _080494E0
	.4byte _080494E0
	.4byte _080494E0
	.4byte _080494E0
	.4byte _080494E0
	.4byte _080494E0
	.4byte _080494E0
	.4byte _080494E0
	.4byte _080494E0
	.4byte _080494E0
	.4byte _080494E0
	.4byte _080494E0
	.4byte _080494E0
	.4byte _080494E0
	.4byte _080494E0
	.4byte _080494E0
	.4byte _080494E0
	.4byte _080494E0
	.4byte _080494E0
	.4byte _080494E0
	.4byte _080494E0
	.4byte _080494E0
	.4byte _080494E0
	.4byte _080494E0
	.4byte _080494E0
	.4byte _080494E0
	.4byte _080494E0
	.4byte _080494E0
	.4byte _080494E0
	.4byte _080494E0
	.4byte _080494E0
	.4byte _080494E0
	.4byte _080494E0
	.4byte _080494E0
	.4byte _080494E0
	.4byte _080494E0
	.4byte _080494E0
	.4byte _080494E0
	.4byte _080494E0
	.4byte _080494E0
	.4byte _080494E0
	.4byte _080494E0
	.4byte _080494E0
	.4byte _080494E0
	.4byte _080494E0
	.4byte _080494E0
	.4byte _080494E0
	.4byte _080494E0
	.4byte _080494E0
	.4byte _080494E0
	.4byte _080494E0
	.4byte _080494E0
	.4byte _080494E0
	.4byte _080494E0
	.4byte _080494E0
	.4byte _080494E0
	.4byte _080494E0
	.4byte _080494E0
	.4byte _080494E0
	.4byte _080494E0
	.4byte _080494E0
	.4byte _080494E0
	.4byte _080494E0
	.4byte _080494DA
_0804928C:
	cmp r5, 0
	bne _08049292
	b _080494E2
_08049292:
	movs r6, 0x46
	b _080494E2
_08049296:
	cmp r5, 0
	bne _0804929C
	b _080494E0
_0804929C:
	movs r1, 0x9E
	lsls r1, 1
	adds r0, r3, r1
	ldr r0, [r0]
	bl GetBellyRoundedUp
	cmp r0, 0
	ble _080492AE
	b _0804948A
_080492AE:
	b _080494E0
_080492B0:
	cmp r5, 0
	beq _080492B6
	b _0804948A
_080492B6:
	b _080494E0
_080492B8:
	movs r2, 0xE
	ldrsh r1, [r3, r2]
	movs r2, 0x10
	ldrsh r0, [r3, r2]
	cmp r1, r0
	blt _080492C6
	b _080494E2
_080492C6:
	cmp r0, 0
	bge _080492CC
	adds r0, 0x3
_080492CC:
	asrs r0, 2
	cmp r1, r0
	ble _080492D4
	b _080494E2
_080492D4:
	cmp r5, 0
	bne _080492DA
	b _08049420
_080492DA:
	b _08049432
_080492DC:
	movs r6, 0
	movs r0, 0x8C
	lsls r0, 1
	adds r5, r3, r0
	adds r7, r5, 0
	movs r2, 0x3
_080492E8:
	ldrb r1, [r5]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _0804930C
	ldrb r0, [r5, 0x4]
	cmp r0, 0
	bne _080492FA
	adds r6, 0x1E
_080492FA:
	ldrb r4, [r5, 0x4]
	adds r0, r7, 0
	str r2, [sp]
	bl GetMoveMaxPP
	ldr r2, [sp]
	cmp r4, r0
	beq _0804930C
	adds r6, 0x6
_0804930C:
	adds r5, 0x8
	adds r7, 0x8
	subs r2, 0x1
	cmp r2, 0
	bge _080492E8
	cmp r6, 0x62
	bgt _0804931C
	b _080494E2
_0804931C:
	movs r6, 0x63
	b _080494E2
_08049320:
	adds r0, r4, 0
	bl HasNegativeStatus
	lsls r0, 24
	movs r6, 0
	b _080494BC
_0804932C:
	ldrb r0, [r3, 0x14]
_0804932E:
	movs r6, 0x64
	cmp r0, 0xF9
	bhi _08049336
	b _080494E2
_08049336:
	b _080494E0
_08049338:
	ldrb r0, [r3, 0x15]
	b _0804932E
_0804933C:
	ldrb r0, [r3, 0x16]
	b _0804932E
_08049340:
	ldrb r0, [r3, 0x17]
	b _0804932E
_08049344:
	cmp r5, 0
	beq _0804934A
	b _080494E0
_0804934A:
	adds r0, r4, 0
	bl CanTargetAdjacentPokemon
	lsls r0, 24
	movs r6, 0x64
	cmp r0, 0
	bne _0804935A
	b _080494E2
_0804935A:
	movs r6, 0xA
	b _080494E2
_0804935E:
	adds r0, r4, 0
	bl CanSeeInvisible
	lsls r0, 24
	cmp r0, 0
	beq _0804936C
	b _080494A2
_0804936C:
	adds r0, r4, 0
	bl CanTargetAdjacentPokemon
	lsls r0, 24
	movs r6, 0x5
	b _080494BC
_08049378:
	ldr r0, [r4, 0x70]
	movs r1, 0x82
	lsls r1, 1
	adds r0, r1
	ldr r0, [r0]
	cmp r0, 0x3
	ble _08049388
	b _080494A2
_08049388:
	adds r0, r4, 0
	bl CanTargetAdjacentPokemon
	lsls r0, 24
	movs r6, 0x5
	b _080494BC
_08049394:
	adds r0, r3, 0
	adds r0, 0xE8
	ldrb r0, [r0]
	cmp r0, 0x2
	bne _080493A0
	b _080494A2
_080493A0:
	adds r0, r4, 0
	bl CanTargetAdjacentPokemon
	lsls r0, 24
	movs r6, 0x5
	b _080494BC
_080493AC:
	adds r0, r3, 0
	adds r0, 0xAC
	ldrb r0, [r0]
	cmp r0, 0x4
	bne _080494A2
	b _080494B2
_080493B8:
	adds r0, r3, 0
	adds r0, 0xBC
	ldrb r0, [r0]
	cmp r0, 0x2
	beq _080494A2
	adds r0, r4, 0
	bl CanTargetAdjacentPokemon
	lsls r0, 24
	movs r6, 0xF
	b _080494BC
_080493CE:
	adds r0, r3, 0
	adds r0, 0xAC
	ldrb r0, [r0]
	subs r0, 0x2
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bhi _080494A2
	b _08049420
_080493E0:
	adds r0, r3, 0
	adds r0, 0xE8
	ldrb r0, [r0]
	cmp r0, 0x1
	beq _080494A2
	adds r0, r4, 0
	bl CanTargetAdjacentPokemon
	lsls r0, 24
	movs r6, 0x5
	b _080494BC
_080493F6:
	cmp r2, 0
	bne _0804940C
	adds r0, r4, 0
	bl CanTargetAdjacentPokemon
	lsls r0, 24
	movs r6, 0x5
	cmp r0, 0
	beq _080494E2
_08049408:
	movs r6, 0x28
	b _080494E2
_0804940C:
	movs r2, 0xE
	ldrsh r1, [r3, r2]
	movs r2, 0x10
	ldrsh r0, [r3, r2]
	cmp r1, r0
	bge _080494E2
	cmp r1, 0x13
	bgt _080494E2
	cmp r5, 0
	bne _08049432
_08049420:
	adds r0, r4, 0
	bl CanTargetAdjacentPokemon
	lsls r0, 24
	movs r6, 0x32
	cmp r0, 0
	beq _080494E2
	movs r6, 0x64
	b _080494E2
_08049432:
	movs r6, 0x32
	b _080494E2
_08049436:
	adds r0, r3, 0
	adds r0, 0xA8
	ldrb r0, [r0]
	cmp r0, 0x1
	beq _080494A2
	cmp r0, 0x5
	beq _080494A2
	cmp r0, 0x3
	beq _080494A2
	adds r0, r4, 0
	bl CanTargetAdjacentPokemon
	lsls r0, 24
	movs r6, 0x5
	b _080494BC
_08049454:
	adds r0, r3, 0
	adds r0, 0xA8
	ldrb r0, [r0]
	cmp r0, 0x2
	beq _080494A2
	movs r6, 0x5
	b _080494E2
_08049462:
	ldrb r0, [r3, 0x9]
	movs r6, 0
	cmp r0, 0x62
	bhi _080494E2
_0804946A:
	movs r6, 0x50
	b _080494E2
_0804946E:
	adds r0, r3, 0
	adds r0, 0xAC
	ldrb r0, [r0]
	cmp r0, 0x1
	beq _0804948A
	b _080494E0
_0804947A:
	movs r1, 0x9E
	lsls r1, 1
	adds r0, r3, r1
	ldr r0, [r0]
	bl GetBellyRoundedUp
	cmp r0, 0
	ble _080494E0
_0804948A:
	movs r0, 0x32
	b _080494E4
_0804948E:
	ldrb r0, [r3, 0x9]
	movs r6, 0
	cmp r0, 0x1
	bls _080494E2
	b _0804946A
_08049498:
	adds r0, r3, 0
	adds r0, 0xB0
	ldrb r0, [r0]
	cmp r0, 0x6
	bne _080494A6
_080494A2:
	movs r0, 0
	b _080494E4
_080494A6:
	adds r0, r4, 0
	bl CanTargetAdjacentPokemon
	lsls r0, 24
	movs r6, 0x5
	b _080494BC
_080494B2:
	adds r0, r4, 0
	bl CanTargetAdjacentPokemon
	lsls r0, 24
	movs r6, 0x1E
_080494BC:
	cmp r0, 0
	beq _080494E2
	b _0804946A
_080494C2:
	movs r2, 0x9E
	lsls r2, 1
	adds r0, r3, r2
	ldr r0, [r0]
	bl GetBellyRoundedUp
	cmp r0, 0x9
	bgt _080494E0
	movs r0, 0x64
	b _080494E4
_080494D6:
	movs r6, 0x1E
	b _080494E2
_080494DA:
	movs r6, 0x14
	cmp r5, 0
	beq _080494E2
_080494E0:
	movs r6, 0
_080494E2:
	adds r0, r6, 0
_080494E4:
	add sp, 0x4
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end EvaluateItem

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