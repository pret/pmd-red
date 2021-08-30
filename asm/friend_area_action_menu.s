        .include "constants/gba_constants.inc"
	.include "asm/macros.inc"

	.syntax unified

	.text

        @ Menu that gets created when you talk to friend
	thumb_func_start CreateFriendActionMenu
CreateFriendActionMenu:
	push {r4-r7,lr}
	ldr r3, _080274E4
	ldr r4, _080274E8
	ldr r0, [r4]
	movs r1, 0x8
	ldrsh r2, [r0, r1]
	movs r1, 0x58
	muls r2, r1
	ldr r1, [r3]
	adds r5, r1, r2
	movs r2, 0xB6
	lsls r2, 1
	adds r0, r2
	movs r1, 0
	movs r2, 0x14
	bl MemoryFill16
	ldrh r0, [r5]
	lsrs r0, 1
	movs r6, 0x1
	ands r0, r6
	cmp r0, 0
	beq _080274F4
	ldr r2, [r4]
	movs r3, 0x8E
	lsls r3, 1
	adds r1, r2, r3
	ldr r0, _080274EC
	str r0, [r1]
	movs r0, 0x90
	lsls r0, 1
	adds r1, r2, r0
	movs r0, 0x7
	str r0, [r1]
	adds r0, r5, 0
	bl sub_8027D9C
	lsls r0, 24
	cmp r0, 0
	bne _080274B6
	ldr r0, [r4]
	movs r1, 0xB6
	lsls r1, 1
	adds r0, r1
	strh r6, [r0]
_080274B6:
	movs r7, 0x1
	movs r0, 0x8
	bl sub_80023E4
	lsls r0, 24
	cmp r0, 0
	beq _08027552
	ldrb r0, [r5, 0x2]
	cmp r0, 0
	bne _08027552
	ldr r3, [r4]
	movs r2, 0x8
	movs r4, 0x92
	lsls r4, 1
	adds r1, r3, r4
	ldr r0, _080274F0
	str r0, [r1]
	movs r1, 0x94
	lsls r1, 1
	adds r0, r3, r1
	str r2, [r0]
	b _08027550
	.align 2, 0
_080274E4: .4byte gRecruitedPokemonRef
_080274E8: .4byte gUnknown_203B2BC
_080274EC: .4byte gFriendActionStandby
_080274F0: .4byte gFriendActionMakeLeader
_080274F4:
	ldr r2, [r4]
	movs r3, 0x8E
	lsls r3, 1
	adds r1, r2, r3
	ldr r0, _08027658
	str r0, [r1]
	movs r0, 0x90
	lsls r0, 1
	adds r1, r2, r0
	movs r0, 0x6
	str r0, [r1]
	movs r1, 0x8
	ldrsh r0, [r2, r1]
	bl sub_808D750
	lsls r0, 24
	cmp r0, 0
	bne _08027522
	ldr r0, [r4]
	movs r2, 0xB6
	lsls r2, 1
	adds r0, r2
	strh r6, [r0]
_08027522:
	movs r7, 0x1
	ldr r2, [r4]
	movs r3, 0x92
	lsls r3, 1
	adds r1, r2, r3
	ldr r0, _0802765C
	str r0, [r1]
	movs r0, 0x94
	lsls r0, 1
	adds r1, r2, r0
	movs r0, 0x9
	str r0, [r1]
	adds r0, r5, 0
	bl sub_8027DCC
	lsls r0, 24
	cmp r0, 0
	bne _08027550
	ldr r0, [r4]
	movs r1, 0xB7
	lsls r1, 1
	adds r0, r1
	strh r7, [r0]
_08027550:
	movs r7, 0x2
_08027552:
	ldr r4, _08027660
	ldr r2, [r4]
	lsls r3, r7, 3
	movs r6, 0x8E
	lsls r6, 1
	adds r0, r2, r6
	adds r0, r3
	ldr r1, _08027664
	str r1, [r0]
	movs r5, 0x90
	lsls r5, 1
	adds r2, r5
	adds r2, r3
	movs r0, 0xA
	str r0, [r2]
	bl GetNumberOfFilledInventorySlots
	cmp r0, 0
	bne _08027588
	ldr r0, [r4]
	lsls r1, r7, 1
	movs r2, 0xB6
	lsls r2, 1
	adds r0, r2
	adds r0, r1
	movs r1, 0x1
	strh r1, [r0]
_08027588:
	adds r7, 0x1
	ldr r2, [r4]
	lsls r3, r7, 3
	adds r0, r2, r6
	adds r0, r3
	ldr r1, _08027668
	str r1, [r0]
	adds r2, r5
	adds r2, r3
	movs r0, 0xB
	str r0, [r2]
	bl GetNumberOfFilledInventorySlots
	cmp r0, 0x13
	bgt _080275AE
	ldr r0, [r4]
	ldrb r0, [r0, 0x14]
	cmp r0, 0
	bne _080275BE
_080275AE:
	ldr r0, [r4]
	lsls r1, r7, 1
	movs r3, 0xB6
	lsls r3, 1
	adds r0, r3
	adds r0, r1
	movs r1, 0x1
	strh r1, [r0]
_080275BE:
	adds r7, 0x1
	ldr r4, _08027660
	ldr r5, [r4]
	lsls r1, r7, 3
	movs r0, 0x8E
	lsls r0, 1
	adds r3, r5, r0
	adds r2, r3, r1
	ldr r0, _0802766C
	str r0, [r2]
	movs r2, 0x90
	lsls r2, 1
	adds r6, r5, r2
	adds r1, r6, r1
	movs r0, 0x4
	str r0, [r1]
	adds r7, 0x1
	lsls r1, r7, 3
	adds r2, r3, r1
	ldr r0, _08027670
	str r0, [r2]
	adds r1, r6, r1
	movs r0, 0xC
	str r0, [r1]
	adds r7, 0x1
	lsls r1, r7, 3
	adds r2, r3, r1
	ldr r0, _08027674
	str r0, [r2]
	adds r1, r6, r1
	movs r0, 0x5
	str r0, [r1]
	adds r7, 0x1
	lsls r1, r7, 3
	adds r3, r1
	movs r0, 0
	str r0, [r3]
	adds r1, r6, r1
	movs r0, 0x1
	str r0, [r1]
	movs r3, 0
	mov r12, r4
	cmp r3, r7
	bge _08027636
	adds r4, r6, 0
	movs r0, 0xB6
	lsls r0, 1
	adds r2, r5, r0
_0802761E:
	ldrh r0, [r2]
	cmp r0, 0
	bne _0802762C
	ldr r1, [r4]
	ldr r0, [r5, 0x70]
	cmp r1, r0
	beq _080276A0
_0802762C:
	adds r4, 0x8
	adds r2, 0x2
	adds r3, 0x1
	cmp r3, r7
	blt _0802761E
_08027636:
	movs r3, 0
	cmp r3, r7
	bge _080276A0
	mov r2, r12
	ldr r1, [r2]
	movs r4, 0xB6
	lsls r4, 1
	adds r0, r1, r4
	ldrh r0, [r0]
	cmp r0, 0
	bne _08027678
	movs r2, 0x90
	lsls r2, 1
	adds r0, r1, r2
	ldr r0, [r0]
	str r0, [r1, 0x70]
	b _080276A0
	.align 2, 0
_08027658: .4byte gFriendActionJoinTeam
_0802765C: .4byte gFriendActionSayFarewell
_08027660: .4byte gUnknown_203B2BC
_08027664: .4byte gFriendActionGive
_08027668: .4byte gFriendActionTake
_0802766C: .4byte gFriendActionSummary
_08027670: .4byte gFriendActionMoves
_08027674: .4byte gFriendActionCheckIQ
_08027678:
	adds r3, 0x1
	cmp r3, r7
	bge _080276A0
	mov r4, r12
	ldr r2, [r4]
	lsls r0, r3, 1
	movs r4, 0xB6
	lsls r4, 1
	adds r1, r2, r4
	adds r1, r0
	ldrh r0, [r1]
	cmp r0, 0
	bne _08027678
	lsls r0, r3, 3
	movs r3, 0x90
	lsls r3, 1
	adds r1, r2, r3
	adds r1, r0
	ldr r0, [r1]
	str r0, [r2, 0x70]
_080276A0:
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end CreateFriendActionMenu

	thumb_func_start sub_80276A8
sub_80276A8:
	push {r4-r7,lr}
	ldr r5, _0802775C
	ldr r0, [r5]
	movs r7, 0xB6
	lsls r7, 1
	adds r0, r7
	movs r1, 0
	movs r2, 0x14
	bl MemoryFill16
	ldr r2, [r5]
	movs r0, 0x8E
	lsls r0, 1
	adds r1, r2, r0
	ldr r0, _08027760
	str r0, [r1]
	movs r3, 0x90
	lsls r3, 1
	adds r1, r2, r3
	movs r0, 0xA
	str r0, [r1]
	bl GetNumberOfFilledInventorySlots
	cmp r0, 0
	bne _080276E4
	ldr r0, [r5]
	adds r4, r7, 0
	adds r0, r4
	movs r1, 0x1
	strh r1, [r0]
_080276E4:
	ldr r4, [r5]
	movs r2, 0x1
	movs r0, 0x92
	lsls r0, 1
	adds r1, r4, r0
	ldr r0, _08027764
	ldr r0, [r0]
	str r0, [r1]
	movs r3, 0x94
	lsls r3, 1
	adds r1, r4, r3
	movs r0, 0x4
	str r0, [r1]
	movs r6, 0x2
	movs r0, 0x96
	lsls r0, 1
	adds r1, r4, r0
	movs r0, 0
	str r0, [r1]
	movs r1, 0x98
	lsls r1, 1
	adds r0, r4, r1
	str r2, [r0]
	movs r3, 0
	mov r12, r4
	movs r4, 0x90
	lsls r4, 1
	add r4, r12
	mov r0, r12
	adds r2, r0, r7
_08027720:
	ldrh r0, [r2]
	cmp r0, 0
	bne _08027730
	ldr r1, [r4]
	mov r7, r12
	ldr r0, [r7, 0x74]
	cmp r1, r0
	beq _0802778E
_08027730:
	adds r4, 0x8
	adds r2, 0x2
	adds r3, 0x1
	cmp r3, r6
	blt _08027720
	movs r3, 0
	cmp r3, r6
	bge _0802778E
	ldr r1, [r5]
	movs r2, 0xB6
	lsls r2, 1
	adds r0, r1, r2
	ldrh r0, [r0]
	cmp r0, 0
	bne _08027768
	movs r3, 0x90
	lsls r3, 1
	adds r0, r1, r3
	ldr r0, [r0]
	str r0, [r1, 0x74]
	b _0802778E
	.align 2, 0
_0802775C: .4byte gUnknown_203B2BC
_08027760: .4byte gFriendActionGive
_08027764: .4byte gUnknown_80D4970
_08027768:
	adds r3, 0x1
	cmp r3, r6
	bge _0802778E
	ldr r2, [r5]
	lsls r0, r3, 1
	movs r4, 0xB6
	lsls r4, 1
	adds r1, r2, r4
	adds r1, r0
	ldrh r0, [r1]
	cmp r0, 0
	bne _08027768
	lsls r0, r3, 3
	movs r7, 0x90
	lsls r7, 1
	adds r1, r2, r7
	adds r1, r0
	ldr r0, [r1]
	str r0, [r2, 0x74]
_0802778E:
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_80276A8

	thumb_func_start sub_8027794
sub_8027794:
	push {r4,lr}
	ldr r4, _080277F0
	ldr r0, [r4]
	movs r1, 0xB6
	lsls r1, 1
	adds r0, r1
	movs r1, 0
	movs r2, 0x14
	bl MemoryFill16
	ldr r4, [r4]
	movs r3, 0
	movs r0, 0x8E
	lsls r0, 1
	adds r1, r4, r0
	ldr r0, _080277F4
	ldr r0, [r0]
	str r0, [r1]
	movs r0, 0x90
	lsls r0, 1
	adds r1, r4, r0
	movs r0, 0x2
	str r0, [r1]
	movs r2, 0x1
	movs r0, 0x92
	lsls r0, 1
	adds r1, r4, r0
	ldr r0, _080277F8
	ldr r0, [r0]
	str r0, [r1]
	movs r0, 0x94
	lsls r0, 1
	adds r1, r4, r0
	movs r0, 0x3
	str r0, [r1]
	movs r1, 0x96
	lsls r1, 1
	adds r0, r4, r1
	str r3, [r0]
	adds r1, 0x4
	adds r0, r4, r1
	str r2, [r0]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080277F0: .4byte gUnknown_203B2BC
_080277F4: .4byte gUnknown_80D4920
_080277F8: .4byte gUnknown_80D4928
	thumb_func_end sub_8027794

	thumb_func_start sub_80277FC
sub_80277FC:
	push {r4,lr}
	movs r0, 0x1
	bl sub_8023A94
	cmp r0, 0x4
	bhi _080278AE
	lsls r0, 2
	ldr r1, _08027814
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08027814: .4byte _08027818
	.align 2, 0
_08027818:
	.4byte _080278AE
	.4byte _080278AE
	.4byte _080278A4
	.4byte _0802782C
	.4byte _08027868
_0802782C:
	bl sub_8023B44
	ldr r4, _08027860
	ldr r1, [r4]
	strh r0, [r1, 0x8]
	ldr r3, _08027864
	movs r0, 0x8
	ldrsh r2, [r1, r0]
	movs r0, 0x58
	muls r2, r0
	ldr r0, [r3]
	adds r0, r2
	str r0, [r1, 0x18]
	ldrb r0, [r0, 0x2]
	strb r0, [r1, 0x1C]
	ldr r1, [r4]
	movs r2, 0x8
	ldrsh r0, [r1, r2]
	adds r1, 0x14
	bl PeekPokemonItem
	movs r0, 0x3
	bl SetFriendAreaActionMenuState
	b _080278AE
	.align 2, 0
_08027860: .4byte gUnknown_203B2BC
_08027864: .4byte gRecruitedPokemonRef
_08027868:
	bl sub_8023B44
	ldr r4, _0802789C
	ldr r1, [r4]
	strh r0, [r1, 0x8]
	ldr r3, _080278A0
	movs r0, 0x8
	ldrsh r2, [r1, r0]
	movs r0, 0x58
	muls r2, r0
	ldr r0, [r3]
	adds r0, r2
	str r0, [r1, 0x18]
	ldrb r0, [r0, 0x2]
	strb r0, [r1, 0x1C]
	ldr r1, [r4]
	movs r2, 0x8
	ldrsh r0, [r1, r2]
	adds r1, 0x14
	bl PeekPokemonItem
	movs r0, 0x4
	bl SetFriendAreaActionMenuState
	b _080278AE
	.align 2, 0
_0802789C: .4byte gUnknown_203B2BC
_080278A0: .4byte gRecruitedPokemonRef
_080278A4:
	bl sub_8023C60
	movs r0, 0x11
	bl SetFriendAreaActionMenuState
_080278AE:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_80277FC

	thumb_func_start sub_80278B4
sub_80278B4:
	push {r4,lr}
	sub sp, 0x4
	movs r0, 0
	str r0, [sp]
	bl sub_8023A94
	ldr r4, _080278F8
	ldr r0, [r4]
	adds r0, 0x7C
	bl sub_8012FD8
	lsls r0, 24
	cmp r0, 0
	bne _080278E4
	ldr r0, [r4]
	adds r0, 0x7C
	mov r1, sp
	bl sub_8013114
	ldr r1, [sp]
	cmp r1, 0x1
	beq _080278E4
	ldr r0, [r4]
	str r1, [r0, 0x70]
_080278E4:
	ldr r0, [sp]
	subs r0, 0x1
	cmp r0, 0xB
	bls _080278EE
	b _08027A36
_080278EE:
	lsls r0, 2
	ldr r1, _080278FC
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080278F8: .4byte gUnknown_203B2BC
_080278FC: .4byte _08027900
	.align 2, 0
_08027900:
	.4byte _08027A30
	.4byte _08027A36
	.4byte _08027A36
	.4byte _08027A20
	.4byte _08027A28
	.4byte _08027930
	.4byte _0802796C
	.4byte _0802798C
	.4byte _080279C0
	.4byte _080279D0
	.4byte _080279D8
	.4byte _080279C8
_08027930:
	ldr r4, _08027964
	ldr r0, [r4]
	movs r1, 0x8
	ldrsh r0, [r0, r1]
	bl sub_808D750
	lsls r0, 24
	cmp r0, 0
	beq _0802795E
	ldr r0, [r4]
	movs r2, 0x8
	ldrsh r1, [r0, r2]
	movs r0, 0x58
	muls r1, r0
	ldr r0, _08027968
	ldr r0, [r0]
	adds r1, r0
	ldrh r2, [r1]
	movs r0, 0x2
	orrs r0, r2
	strh r0, [r1]
	bl nullsub_104
_0802795E:
	bl sub_808ED00
	b _08027A0E
	.align 2, 0
_08027964: .4byte gUnknown_203B2BC
_08027968: .4byte gRecruitedPokemonRef
_0802796C:
	ldr r0, _08027984
	ldr r0, [r0]
	ldr r2, [r0, 0x18]
	ldrh r1, [r2]
	ldr r0, _08027988
	ands r0, r1
	strh r0, [r2]
	bl nullsub_104
	bl sub_808ED00
	b _08027A0E
	.align 2, 0
_08027984: .4byte gUnknown_203B2BC
_08027988: .4byte 0x0000fffd
_0802798C:
	ldr r2, _080279B8
	ldr r0, _080279BC
	ldr r0, [r0]
	movs r3, 0x8
	ldrsh r1, [r0, r3]
	movs r0, 0x58
	muls r1, r0
	ldr r0, [r2]
	adds r4, r0, r1
	bl sub_808D33C
	ldrb r1, [r4, 0x2]
	cmp r1, 0
	bne _080279B2
	strb r1, [r0, 0x2]
	movs r0, 0x1
	strb r0, [r4, 0x2]
	bl nullsub_104
_080279B2:
	bl sub_808ED00
	b _08027A0E
	.align 2, 0
_080279B8: .4byte gRecruitedPokemonRef
_080279BC: .4byte gUnknown_203B2BC
_080279C0:
	movs r0, 0x8
	bl SetFriendAreaActionMenuState
	b _08027A36
_080279C8:
	movs r0, 0xE
	bl SetFriendAreaActionMenuState
	b _08027A36
_080279D0:
	movs r0, 0xA
	bl SetFriendAreaActionMenuState
	b _08027A36
_080279D8:
	ldr r0, _08027A18
	bl PlaySound
	ldr r4, _08027A1C
	ldr r1, [r4]
	ldrb r0, [r1, 0x14]
	cmp r0, 0
	beq _080279F0
	adds r0, r1, 0
	adds r0, 0x14
	bl sub_8091274
_080279F0:
	bl FillInventoryGaps
	ldr r0, [r4]
	movs r1, 0
	strb r1, [r0, 0x14]
	ldr r0, [r4]
	strb r1, [r0, 0x15]
	ldr r1, [r4]
	movs r2, 0x8
	ldrsh r0, [r1, r2]
	adds r1, 0x14
	bl GivePokemonItem
	bl nullsub_104
_08027A0E:
	movs r0, 0x2
	bl SetFriendAreaActionMenuState
	b _08027A36
	.align 2, 0
_08027A18: .4byte 0x0000014d
_08027A1C: .4byte gUnknown_203B2BC
_08027A20:
	movs r0, 0x4
	bl SetFriendAreaActionMenuState
	b _08027A36
_08027A28:
	movs r0, 0x5
	bl SetFriendAreaActionMenuState
	b _08027A36
_08027A30:
	movs r0, 0x2
	bl SetFriendAreaActionMenuState
_08027A36:
	add sp, 0x4
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_80278B4

	thumb_func_start sub_8027A40
sub_8027A40:
	push {lr}
	bl sub_80244E4
	cmp r0, 0x1
	bls _08027A58
	cmp r0, 0x3
	bhi _08027A58
	bl sub_802453C
	movs r0, 0x2
	bl SetFriendAreaActionMenuState
_08027A58:
	pop {r0}
	bx r0
	thumb_func_end sub_8027A40

	thumb_func_start sub_8027A5C
sub_8027A5C:
	push {lr}
	bl sub_801BF48
	cmp r0, 0x1
	bls _08027A74
	cmp r0, 0x3
	bhi _08027A74
	bl sub_801BF98
	movs r0, 0x2
	bl SetFriendAreaActionMenuState
_08027A74:
	pop {r0}
	bx r0
	thumb_func_end sub_8027A5C

	thumb_func_start sub_8027A78
sub_8027A78:
	push {lr}
	sub sp, 0x4
	mov r0, sp
	bl sub_80144A4
	cmp r0, 0
	bne _08027AD8
	ldr r0, [sp]
	cmp r0, 0x2
	beq _08027AA2
	cmp r0, 0x2
	bgt _08027A96
	cmp r0, 0x1
	beq _08027A9A
	b _08027AD8
_08027A96:
	cmp r0, 0x3
	bne _08027AD8
_08027A9A:
	movs r0, 0x2
	bl SetFriendAreaActionMenuState
	b _08027AD8
_08027AA2:
	ldr r0, _08027AB8
	ldr r0, [r0]
	ldr r0, [r0, 0x18]
	ldrb r0, [r0, 0x4]
	subs r0, 0x44
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bhi _08027ABC
	movs r0, 0x1
	b _08027ABE
	.align 2, 0
_08027AB8: .4byte gUnknown_203B2BC
_08027ABC:
	movs r0, 0
_08027ABE:
	cmp r0, 0
	beq _08027ACA
	movs r0, 0x9
	bl SetFriendAreaActionMenuState
	b _08027AD8
_08027ACA:
	bl sub_8027EB8
	ldr r0, _08027AE0
	ldr r0, [r0]
	ldr r0, [r0, 0x18]
	bl sub_808D31C
_08027AD8:
	add sp, 0x4
	pop {r0}
	bx r0
	.align 2, 0
_08027AE0: .4byte gUnknown_203B2BC
	thumb_func_end sub_8027A78

        .align 2,0
