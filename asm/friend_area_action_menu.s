        #include "asm/constants/gba_constants.inc"
	#include "asm/macros.inc"

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

        .align 2,0
