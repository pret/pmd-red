        #include "asm/constants/gba_constants.inc"
	#include "asm/macros.inc"

	.syntax unified

	.text


	thumb_func_start sub_8025728
sub_8025728:
	push {r4-r7,lr}
	ldr r3, _080257CC
	ldr r5, _080257D0
	ldr r0, [r5]
	movs r1, 0xE
	ldrsh r2, [r0, r1]
	movs r1, 0x58
	muls r2, r1
	ldr r1, [r3]
	adds r7, r1, r2
	movs r2, 0x84
	lsls r2, 1
	adds r0, r2
	movs r1, 0
	movs r2, 0x10
	bl MemoryFill16
	ldr r4, [r5]
	ldr r0, [r4]
	cmp r0, 0
	bne _080257E0
	adds r1, r4, 0
	adds r1, 0xC8
	ldr r0, _080257D4
	str r0, [r1]
	adds r1, 0x4
	movs r0, 0xA
	str r0, [r1]
	bl GetNumberOfFilledInventorySlots
	cmp r0, 0
	bne _08025774
	ldr r0, [r5]
	movs r4, 0x84
	lsls r4, 1
	adds r0, r4
	movs r1, 0x1
	strh r1, [r0]
_08025774:
	movs r6, 0x1
	ldr r1, [r5]
	adds r2, r1, 0
	adds r2, 0xD0
	ldr r0, _080257D8
	str r0, [r2]
	adds r1, 0xD4
	movs r0, 0xB
	str r0, [r1]
	bl GetNumberOfFilledInventorySlots
	cmp r0, 0x13
	bgt _08025796
	ldr r0, [r5]
	ldrb r0, [r0, 0x18]
	cmp r0, 0
	bne _080257A0
_08025796:
	ldr r0, [r5]
	movs r1, 0x85
	lsls r1, 1
	adds r0, r1
	strh r6, [r0]
_080257A0:
	adds r6, 0x1
	adds r0, r7, 0
	bl sub_8025EC4
	lsls r0, 24
	cmp r0, 0
	beq _08025810
	ldr r0, _080257D0
	ldr r2, [r0]
	lsls r3, r6, 3
	adds r0, r2, 0
	adds r0, 0xC8
	adds r0, r3
	ldr r1, _080257DC
	str r1, [r0]
	adds r2, 0xCC
	adds r2, r3
	movs r0, 0x9
	str r0, [r2]
	adds r6, 0x1
	b _08025810
	.align 2, 0
_080257CC: .4byte gRecruitedPokemonRef
_080257D0: .4byte gUnknown_203B2B4
_080257D4: .4byte gUnknown_80DD2B0
_080257D8: .4byte gUnknown_80DD2B8
_080257DC: .4byte gUnknown_80DD2C0
_080257E0:
	adds r1, r4, 0
	adds r1, 0xC8
	ldr r0, _080258D4
	str r0, [r1]
	adds r1, 0x4
	movs r0, 0x7
	str r0, [r1]
	ldr r0, [r4, 0x1C]
	movs r2, 0x8
	ldrsh r0, [r0, r2]
	bl GetFriendArea
	ldrb r1, [r4, 0xC]
	lsls r0, 24
	lsrs r0, 24
	cmp r1, r0
	bne _0802580E
	ldr r0, [r5]
	movs r4, 0x84
	lsls r4, 1
	adds r0, r4
	movs r1, 0x1
	strh r1, [r0]
_0802580E:
	movs r6, 0x1
_08025810:
	movs r0, 0x8
	ldrsh r1, [r7, r0]
	ldr r0, _080258D8
	cmp r1, r0
	bne _08025840
	adds r0, r7, 0
	bl IsPokemonRenamed
	lsls r0, 24
	cmp r0, 0
	beq _08025840
	ldr r0, _080258DC
	ldr r2, [r0]
	lsls r3, r6, 3
	adds r0, r2, 0
	adds r0, 0xC8
	adds r0, r3
	ldr r1, _080258E0
	str r1, [r0]
	adds r2, 0xCC
	adds r2, r3
	movs r0, 0x8
	str r0, [r2]
	adds r6, 0x1
_08025840:
	ldr r4, _080258DC
	ldr r5, [r4]
	lsls r1, r6, 3
	adds r3, r5, 0
	adds r3, 0xC8
	adds r2, r3, r1
	ldr r0, _080258E4
	str r0, [r2]
	adds r7, r5, 0
	adds r7, 0xCC
	adds r1, r7, r1
	movs r0, 0x4
	str r0, [r1]
	adds r6, 0x1
	lsls r1, r6, 3
	adds r2, r3, r1
	ldr r0, _080258E8
	str r0, [r2]
	adds r1, r7, r1
	movs r0, 0x6
	str r0, [r1]
	adds r6, 0x1
	lsls r1, r6, 3
	adds r2, r3, r1
	ldr r0, _080258EC
	str r0, [r2]
	adds r1, r7, r1
	movs r0, 0x5
	str r0, [r1]
	adds r6, 0x1
	lsls r1, r6, 3
	adds r3, r1
	movs r0, 0
	str r0, [r3]
	adds r1, r7, r1
	movs r0, 0x1
	str r0, [r1]
	movs r3, 0
	mov r12, r4
	cmp r3, r6
	bge _080258B2
	movs r1, 0x84
	lsls r1, 1
	adds r4, r5, r1
	adds r2, r7, 0
_0802589A:
	ldrh r0, [r4]
	cmp r0, 0
	bne _080258A8
	ldr r1, [r2]
	ldr r0, [r5, 0x70]
	cmp r1, r0
	beq _08025916
_080258A8:
	adds r4, 0x2
	adds r2, 0x8
	adds r3, 0x1
	cmp r3, r6
	blt _0802589A
_080258B2:
	movs r3, 0
	cmp r3, r6
	bge _08025916
	mov r2, r12
	ldr r1, [r2]
	movs r4, 0x84
	lsls r4, 1
	adds r0, r1, r4
	ldrh r0, [r0]
	cmp r0, 0
	bne _080258F0
	adds r0, r1, 0
	adds r0, 0xCC
	ldr r0, [r0]
	str r0, [r1, 0x70]
	b _08025916
	.align 2, 0
_080258D4: .4byte gUnknown_80DD2CC
_080258D8: .4byte 0x0000013d
_080258DC: .4byte gUnknown_203B2B4
_080258E0: .4byte gUnknown_80DD2D4
_080258E4: .4byte gUnknown_80DD2DC
_080258E8: .4byte gUnknown_80DD2E4
_080258EC: .4byte gUnknown_80DD2EC
_080258F0:
	adds r3, 0x1
	cmp r3, r6
	bge _08025916
	mov r0, r12
	ldr r2, [r0]
	lsls r0, r3, 1
	movs r4, 0x84
	lsls r4, 1
	adds r1, r2, r4
	adds r1, r0
	ldrh r0, [r1]
	cmp r0, 0
	bne _080258F0
	lsls r0, r3, 3
	adds r1, r2, 0
	adds r1, 0xCC
	adds r1, r0
	ldr r0, [r1]
	str r0, [r2, 0x70]
_08025916:
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_8025728

	thumb_func_start sub_802591C
sub_802591C:
	push {r4-r7,lr}
	ldr r5, _080259B8
	ldr r0, [r5]
	movs r7, 0x84
	lsls r7, 1
	adds r0, r7
	movs r1, 0
	movs r2, 0x10
	bl MemoryFill16
	ldr r1, [r5]
	adds r2, r1, 0
	adds r2, 0xC8
	ldr r0, _080259BC
	str r0, [r2]
	adds r1, 0xCC
	movs r0, 0xA
	str r0, [r1]
	bl GetNumberOfFilledInventorySlots
	cmp r0, 0
	bne _08025952
	ldr r0, [r5]
	adds r1, r7, 0
	adds r0, r1
	movs r1, 0x1
	strh r1, [r0]
_08025952:
	ldr r4, [r5]
	movs r2, 0x1
	adds r1, r4, 0
	adds r1, 0xD0
	ldr r0, _080259C0
	ldr r0, [r0]
	str r0, [r1]
	adds r1, 0x4
	movs r0, 0x4
	str r0, [r1]
	movs r6, 0x2
	adds r1, 0x4
	movs r0, 0
	str r0, [r1]
	adds r0, r4, 0
	adds r0, 0xDC
	str r2, [r0]
	movs r3, 0
	mov r12, r4
	adds r4, r7
	mov r2, r12
	adds r2, 0xCC
_0802597E:
	ldrh r0, [r4]
	cmp r0, 0
	bne _0802598E
	ldr r1, [r2]
	mov r7, r12
	ldr r0, [r7, 0x74]
	cmp r1, r0
	beq _080259E8
_0802598E:
	adds r4, 0x2
	adds r2, 0x8
	adds r3, 0x1
	cmp r3, r6
	blt _0802597E
	movs r3, 0
	cmp r3, r6
	bge _080259E8
	ldr r1, [r5]
	movs r2, 0x84
	lsls r2, 1
	adds r0, r1, r2
	ldrh r0, [r0]
	cmp r0, 0
	bne _080259C4
	adds r0, r1, 0
	adds r0, 0xCC
	ldr r0, [r0]
	str r0, [r1, 0x74]
	b _080259E8
	.align 2, 0
_080259B8: .4byte gUnknown_203B2B4
_080259BC: .4byte gUnknown_80DD2B0
_080259C0: .4byte gUnknown_80D4970
_080259C4:
	adds r3, 0x1
	cmp r3, r6
	bge _080259E8
	ldr r2, [r5]
	lsls r0, r3, 1
	movs r4, 0x84
	lsls r4, 1
	adds r1, r2, r4
	adds r1, r0
	ldrh r0, [r1]
	cmp r0, 0
	bne _080259C4
	lsls r0, r3, 3
	adds r1, r2, 0
	adds r1, 0xCC
	adds r1, r0
	ldr r0, [r1]
	str r0, [r2, 0x74]
_080259E8:
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_802591C

	thumb_func_start sub_80259F0
sub_80259F0:
	push {lr}
	movs r0, 0x1
	bl sub_8023A94
	cmp r0, 0x3
	beq _08025A0C
	cmp r0, 0x3
	bhi _08025A06
	cmp r0, 0x2
	beq _08025A74
	b _08025A7E
_08025A06:
	cmp r0, 0x4
	beq _08025A40
	b _08025A7E
_08025A0C:
	bl sub_8023B44
	ldr r1, _08025A38
	ldr r1, [r1]
	strh r0, [r1, 0xE]
	ldr r3, _08025A3C
	movs r0, 0xE
	ldrsh r2, [r1, r0]
	movs r0, 0x58
	muls r2, r0
	ldr r0, [r3]
	adds r0, r2
	str r0, [r1, 0x1C]
	movs r2, 0xE
	ldrsh r0, [r1, r2]
	adds r1, 0x18
	bl PeekPokemonItem
	movs r0, 0x3
	bl sub_8025434
	b _08025A7E
	.align 2, 0
_08025A38: .4byte gUnknown_203B2B4
_08025A3C: .4byte gRecruitedPokemonRef
_08025A40:
	bl sub_8023B44
	ldr r1, _08025A6C
	ldr r1, [r1]
	strh r0, [r1, 0xE]
	ldr r3, _08025A70
	movs r0, 0xE
	ldrsh r2, [r1, r0]
	movs r0, 0x58
	muls r2, r0
	ldr r0, [r3]
	adds r0, r2
	str r0, [r1, 0x1C]
	movs r2, 0xE
	ldrsh r0, [r1, r2]
	adds r1, 0x18
	bl PeekPokemonItem
	movs r0, 0x4
	bl sub_8025434
	b _08025A7E
	.align 2, 0
_08025A6C: .4byte gUnknown_203B2B4
_08025A70: .4byte gRecruitedPokemonRef
_08025A74:
	bl sub_8023C60
	movs r0, 0x13
	bl sub_8025434
_08025A7E:
	pop {r0}
	bx r0
	thumb_func_end sub_80259F0

	thumb_func_start sub_8025A84
sub_8025A84:
	push {r4,lr}
	sub sp, 0x4
	movs r0, 0
	str r0, [sp]
	bl sub_8023A94
	ldr r4, _08025AC8
	ldr r0, [r4]
	adds r0, 0x78
	bl sub_8012FD8
	lsls r0, 24
	cmp r0, 0
	bne _08025AB4
	ldr r0, [r4]
	adds r0, 0x78
	mov r1, sp
	bl sub_8013114
	ldr r1, [sp]
	cmp r1, 0x1
	beq _08025AB4
	ldr r0, [r4]
	str r1, [r0, 0x70]
_08025AB4:
	ldr r0, [sp]
	subs r0, 0x1
	cmp r0, 0xA
	bls _08025ABE
	b _08025BC2
_08025ABE:
	lsls r0, 2
	ldr r1, _08025ACC
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08025AC8: .4byte gUnknown_203B2B4
_08025ACC: .4byte _08025AD0
	.align 2, 0
_08025AD0:
	.4byte _08025BBC
	.4byte _08025BC2
	.4byte _08025BC2
	.4byte _08025BAC
	.4byte _08025BB4
	.4byte _08025B9C
	.4byte _08025AFC
	.4byte _08025BA4
	.4byte _08025B70
	.4byte _08025B20
	.4byte _08025B28
_08025AFC:
	ldr r4, _08025B1C
	ldr r0, [r4]
	ldr r0, [r0, 0x1C]
	movs r1, 0x8
	ldrsh r0, [r0, r1]
	bl GetFriendArea
	ldr r1, [r4]
	strb r0, [r1, 0xD]
	bl sub_8023C60
	movs r0, 0x13
	bl sub_8025434
	b _08025BC2
	.align 2, 0
_08025B1C: .4byte gUnknown_203B2B4
_08025B20:
	movs r0, 0xB
	bl sub_8025434
	b _08025BC2
_08025B28:
	ldr r0, _08025B68
	bl PlaySound
	ldr r4, _08025B6C
	ldr r1, [r4]
	ldrb r0, [r1, 0x18]
	cmp r0, 0
	beq _08025B40
	adds r0, r1, 0
	adds r0, 0x18
	bl AddHeldItemToInventory
_08025B40:
	bl FillInventoryGaps
	ldr r0, [r4]
	movs r1, 0
	strb r1, [r0, 0x18]
	ldr r0, [r4]
	strb r1, [r0, 0x19]
	ldr r1, [r4]
	movs r2, 0xE
	ldrsh r0, [r1, r2]
	adds r1, 0x18
	bl GivePokemonItem
	bl nullsub_104
	movs r0, 0xA
	bl sub_8025434
	b _08025BC2
	.align 2, 0
_08025B68: .4byte 0x0000014d
_08025B6C: .4byte gUnknown_203B2B4
_08025B70:
	ldr r0, _08025B94
	ldr r0, [r0]
	ldr r2, [r0, 0x1C]
	ldrh r1, [r2]
	ldr r0, _08025B98
	ands r0, r1
	strh r0, [r2]
	bl nullsub_104
	bl sub_808ED00
	bl sub_8023C60
	movs r0, 0x7
	bl sub_8025434
	b _08025BC2
	.align 2, 0
_08025B94: .4byte gUnknown_203B2B4
_08025B98: .4byte 0x0000fffd
_08025B9C:
	movs r0, 0xF
	bl sub_8025434
	b _08025BC2
_08025BA4:
	movs r0, 0x12
	bl sub_8025434
	b _08025BC2
_08025BAC:
	movs r0, 0x4
	bl sub_8025434
	b _08025BC2
_08025BB4:
	movs r0, 0x5
	bl sub_8025434
	b _08025BC2
_08025BBC:
	movs r0, 0x2
	bl sub_8025434
_08025BC2:
	add sp, 0x4
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_8025A84

	thumb_func_start sub_8025BCC
sub_8025BCC:
	push {lr}
	bl sub_80244E4
	cmp r0, 0x1
	bls _08025BE4
	cmp r0, 0x3
	bhi _08025BE4
	bl sub_802453C
	movs r0, 0x2
	bl sub_8025434
_08025BE4:
	pop {r0}
	bx r0
	thumb_func_end sub_8025BCC

	thumb_func_start sub_8025BE8
sub_8025BE8:
	push {lr}
	bl sub_801BF48
	cmp r0, 0x1
	bls _08025C00
	cmp r0, 0x3
	bhi _08025C00
	bl sub_801BF98
	movs r0, 0x2
	bl sub_8025434
_08025C00:
	pop {r0}
	bx r0
	thumb_func_end sub_8025BE8

	thumb_func_start sub_8025C04
sub_8025C04:
	push {r4,lr}
	movs r0, 0x1
	bl sub_801A6E8
	cmp r0, 0x4
	bhi _08025CAE
	lsls r0, 2
	ldr r1, _08025C1C
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08025C1C: .4byte _08025C20
	.align 2, 0
_08025C20:
	.4byte _08025CAE
	.4byte _08025CAE
	.4byte _08025CA4
	.4byte _08025C34
	.4byte _08025C68
_08025C34:
	bl sub_801A8AC
	ldr r4, _08025C60
	ldr r2, [r4]
	str r0, [r2, 0x10]
	ldr r3, _08025C64
	ldr r1, [r3]
	lsls r0, 2
	adds r1, r0
	ldrb r0, [r1, 0x2]
	strb r0, [r2, 0x14]
	ldr r2, [r4]
	ldr r1, [r3]
	ldr r0, [r2, 0x10]
	lsls r0, 2
	adds r1, r0
	ldrb r0, [r1, 0x1]
	strb r0, [r2, 0x15]
	movs r0, 0xD
	bl sub_8025434
	b _08025CAE
	.align 2, 0
_08025C60: .4byte gUnknown_203B2B4
_08025C64: .4byte gTeamInventory_203B460
_08025C68:
	bl sub_801A8AC
	ldr r4, _08025C9C
	ldr r2, [r4]
	str r0, [r2, 0x10]
	ldr r3, _08025CA0
	ldr r1, [r3]
	lsls r0, 2
	adds r1, r0
	ldrb r0, [r1, 0x2]
	strb r0, [r2, 0x14]
	ldr r2, [r4]
	ldr r1, [r3]
	ldr r0, [r2, 0x10]
	lsls r0, 2
	adds r1, r0
	ldrb r0, [r1, 0x1]
	strb r0, [r2, 0x15]
	movs r0, 0
	bl sub_8099690
	movs r0, 0xE
	bl sub_8025434
	b _08025CAE
	.align 2, 0
_08025C9C: .4byte gUnknown_203B2B4
_08025CA0: .4byte gTeamInventory_203B460
_08025CA4:
	bl sub_801A928
	movs r0, 0x2
	bl sub_8025434
_08025CAE:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_8025C04

	thumb_func_start sub_8025CB4
sub_8025CB4:
	push {r4-r6,lr}
	sub sp, 0x14
	movs r0, 0
	str r0, [sp, 0xC]
	bl sub_801A6E8
	ldr r4, _08025CF4
	ldr r0, [r4]
	adds r0, 0x78
	bl sub_8012FD8
	lsls r0, 24
	cmp r0, 0
	bne _08025CE4
	ldr r0, [r4]
	adds r0, 0x78
	add r1, sp, 0xC
	bl sub_8013114
	ldr r1, [sp, 0xC]
	cmp r1, 0x1
	beq _08025CE4
	ldr r0, [r4]
	str r1, [r0, 0x74]
_08025CE4:
	ldr r0, [sp, 0xC]
	cmp r0, 0x4
	beq _08025D74
	cmp r0, 0x4
	bgt _08025CF8
	cmp r0, 0x1
	beq _08025D82
	b _08025D88
	.align 2, 0
_08025CF4: .4byte gUnknown_203B2B4
_08025CF8:
	cmp r0, 0xA
	bne _08025D88
	movs r6, 0x8
	ldr r0, _08025D68
	bl PlaySound
	ldr r5, _08025D6C
	ldr r0, [r5]
	ldr r0, [r0, 0x10]
	bl ShiftItemsDownFrom
	bl FillInventoryGaps
	ldr r1, [r5]
	ldrb r0, [r1, 0x18]
	cmp r0, 0
	beq _08025D24
	adds r0, r1, 0
	adds r0, 0x18
	bl AddHeldItemToInventory
	movs r6, 0x9
_08025D24:
	add r4, sp, 0x10
	ldr r1, [r5]
	adds r1, 0x14
	adds r0, r4, 0
	bl HeldItemToSlot
	movs r1, 0
	str r1, [sp]
	mov r0, sp
	strb r1, [r0, 0x4]
	mov r1, sp
	movs r0, 0x1
	strb r0, [r1, 0x8]
	strb r0, [r4]
	ldr r0, _08025D70
	adds r1, r4, 0
	mov r2, sp
	bl sub_8090E14
	ldr r1, [r5]
	movs r2, 0xE
	ldrsh r0, [r1, r2]
	adds r1, 0x14
	bl GivePokemonItem
	bl sub_801A928
	bl nullsub_104
	adds r0, r6, 0
	bl sub_8025434
	b _08025D88
	.align 2, 0
_08025D68: .4byte 0x0000014d
_08025D6C: .4byte gUnknown_203B2B4
_08025D70: .4byte gUnknown_202DEA8
_08025D74:
	movs r0, 0
	bl sub_8099690
	movs r0, 0xE
	bl sub_8025434
	b _08025D88
_08025D82:
	movs r0, 0xC
	bl sub_8025434
_08025D88:
	add sp, 0x14
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end sub_8025CB4

	thumb_func_start sub_8025D90
sub_8025D90:
	push {lr}
	bl sub_801B410
	cmp r0, 0x1
	bls _08025DA8
	cmp r0, 0x3
	bhi _08025DA8
	bl sub_801B450
	movs r0, 0xC
	bl sub_8025434
_08025DA8:
	pop {r0}
	bx r0
	thumb_func_end sub_8025D90

	thumb_func_start sub_8025DAC
sub_8025DAC:
	push {lr}
	movs r0, 0x1
	bl sub_801EF38
	cmp r0, 0x3
	beq _08025DC6
	cmp r0, 0x3
	bhi _08025DC2
	cmp r0, 0x2
	beq _08025DE4
	b _08025DFE
_08025DC2:
	cmp r0, 0x4
	bne _08025DFE
_08025DC6:
	bl sub_801F194
	ldr r1, _08025DE0
	ldr r1, [r1]
	str r0, [r1, 0x20]
	lsls r0, 3
	adds r0, r1, r0
	ldrh r0, [r0, 0x2A]
	strh r0, [r1, 0x24]
	movs r0, 0x11
	bl sub_8025434
	b _08025DFE
	.align 2, 0
_08025DE0: .4byte gUnknown_203B2B4
_08025DE4:
	bl sub_801F214
	ldr r0, _08025E04
	ldr r1, [r0]
	adds r0, r1, 0
	adds r0, 0x28
	ldr r1, [r1, 0x1C]
	adds r1, 0x2C
	bl sub_8094060
	movs r0, 0x2
	bl sub_8025434
_08025DFE:
	pop {r0}
	bx r0
	.align 2, 0
_08025E04: .4byte gUnknown_203B2B4
	thumb_func_end sub_8025DAC

	thumb_func_start sub_8025E08
sub_8025E08:
	push {lr}
	bl sub_801F890
	cmp r0, 0x1
	bls _08025E20
	cmp r0, 0x3
	bhi _08025E20
	bl sub_801F8D0
	movs r0, 0x10
	bl sub_8025434
_08025E20:
	pop {r0}
	bx r0
	thumb_func_end sub_8025E08

	thumb_func_start sub_8025E24
sub_8025E24:
	push {lr}
	bl sub_8016080
	cmp r0, 0x3
	bhi _08025E40
	cmp r0, 0x2
	bcc _08025E40
	bl sub_80160D8
	bl nullsub_104
	movs r0, 0x2
	bl sub_8025434
_08025E40:
	pop {r0}
	bx r0
	thumb_func_end sub_8025E24

	thumb_func_start sub_8025E44
sub_8025E44:
	push {lr}
	sub sp, 0x4
	mov r0, sp
	bl sub_80144A4
	cmp r0, 0
	bne _08025E5C
	ldr r0, _08025E64
	ldr r0, [r0]
	ldr r0, [r0, 0x8]
	bl sub_8025434
_08025E5C:
	add sp, 0x4
	pop {r0}
	bx r0
	.align 2, 0
_08025E64: .4byte gUnknown_203B2B4
	thumb_func_end sub_8025E44

	thumb_func_start sub_8025E68
sub_8025E68:
	push {r4-r6,lr}
	sub sp, 0x14
	adds r6, r0, 0
	adds r5, r1, 0
	bl sub_8008C54
	adds r0, r6, 0
	bl sub_80073B8
	add r4, sp, 0x10
	adds r0, r4, 0
	adds r1, r5, 0
	bl HeldItemToSlot
	movs r5, 0
	str r5, [sp, 0x4]
	add r0, sp, 0x4
	strb r5, [r0, 0x4]
	adds r1, r0, 0
	movs r0, 0x1
	strb r0, [r1, 0x8]
	strb r0, [r4]
	ldr r0, _08025EBC
	adds r1, r4, 0
	add r2, sp, 0x4
	bl sub_8090E14
	ldr r2, _08025EC0
	str r5, [sp]
	movs r0, 0x4
	movs r1, 0x3
	adds r3, r6, 0
	bl xxx_format_and_draw
	adds r0, r6, 0
	bl sub_80073E0
	add sp, 0x14
	pop {r4-r6}
	pop {r0}
	bx r0
	.align 2, 0
_08025EBC: .4byte gUnknown_202DE58
_08025EC0: .4byte gUnknown_80DD2F8
	thumb_func_end sub_8025E68

	thumb_func_start sub_8025EC4
sub_8025EC4:
	push {lr}
	adds r1, r0, 0
	ldrb r0, [r1, 0x2]
	cmp r0, 0
	bne _08025EE8
	movs r2, 0
	ldrb r0, [r1, 0x4]
	cmp r0, 0x41
	bne _08025ED8
	movs r2, 0x1
_08025ED8:
	cmp r2, 0
	beq _08025EEC
	movs r0, 0x8
	bl sub_80023E4
	lsls r0, 24
	cmp r0, 0
	bne _08025EEC
_08025EE8:
	movs r0, 0
	b _08025EEE
_08025EEC:
	movs r0, 0x1
_08025EEE:
	pop {r1}
	bx r1
	thumb_func_end sub_8025EC4

	thumb_func_start sub_8025EF4
sub_8025EF4:
	push {r4-r6,lr}
	adds r4, r0, 0
	ldr r6, _08025F1C
	movs r0, 0xA0
	lsls r0, 2
	movs r1, 0x8
	bl MemoryAlloc
	adds r1, r0, 0
	str r1, [r6]
	str r4, [r1, 0x18]
	movs r5, 0
	ldr r0, _08025F20
	ldr r0, [r0]
	cmp r4, r0
	bne _08025F24
	strh r5, [r1, 0xA]
	adds r4, r6, 0
	b _08025F48
	.align 2, 0
_08025F1C: .4byte gUnknown_203B2B8
_08025F20: .4byte gRecruitedPokemonRef
_08025F24:
	adds r5, 0x1
	movs r0, 0xCE
	lsls r0, 1
	ldr r4, _08025F60
	cmp r5, r0
	bgt _08025F48
	ldr r3, [r4]
	ldr r2, _08025F64
	lsls r0, r5, 16
	asrs r0, 16
	movs r1, 0x58
	muls r1, r0
	ldr r0, [r2]
	adds r0, r1
	ldr r1, [r3, 0x18]
	cmp r1, r0
	bne _08025F24
	strh r5, [r3, 0xA]
_08025F48:
	ldr r1, [r4]
	movs r0, 0
	str r0, [r1, 0x70]
	str r0, [r1, 0x74]
	str r0, [r1, 0x78]
	strb r0, [r1, 0x8]
	bl sub_8026074
	movs r0, 0x1
	pop {r4-r6}
	pop {r1}
	bx r1
	.align 2, 0
_08025F60: .4byte gUnknown_203B2B8
_08025F64: .4byte gRecruitedPokemonRef
	thumb_func_end sub_8025EF4

	thumb_func_start sub_8025F68
sub_8025F68:
	push {lr}
	ldr r0, _08025F80
	ldr r0, [r0]
	ldr r0, [r0]
	cmp r0, 0x19
	bhi _0802603A
	lsls r0, 2
	ldr r1, _08025F84
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08025F80: .4byte gUnknown_203B2B8
_08025F84: .4byte _08025F88
	.align 2, 0
_08025F88:
	.4byte _08025FF0
	.4byte _08025FF8
	.4byte _08025FF8
	.4byte _08025FFE
	.4byte _08026004
	.4byte _0802603A
	.4byte _0802603A
	.4byte _0802603A
	.4byte _0802603A
	.4byte _0802603A
	.4byte _0802603A
	.4byte _0802603A
	.4byte _0802600A
	.4byte _08026010
	.4byte _08026016
	.4byte _0802603A
	.4byte _0802603A
	.4byte _0802603A
	.4byte _0802601C
	.4byte _0802601C
	.4byte _08026022
	.4byte _08026028
	.4byte _0802602E
	.4byte _0802602E
	.4byte _08026034
	.4byte _08026040
_08025FF0:
	movs r0, 0x1
	bl sub_8026074
	b _08026044
_08025FF8:
	bl sub_80268CC
	b _08026044
_08025FFE:
	bl sub_8026A78
	b _08026044
_08026004:
	bl sub_8026A94
	b _08026044
_0802600A:
	bl sub_8026AB0
	b _08026044
_08026010:
	bl sub_8026B10
	b _08026044
_08026016:
	bl sub_8026B48
	b _08026044
_0802601C:
	bl sub_8026B64
	b _08026044
_08026022:
	bl sub_8026C14
	b _08026044
_08026028:
	bl sub_8026CF0
	b _08026044
_0802602E:
	bl sub_8026D0C
	b _08026044
_08026034:
	bl sub_8026D6C
	b _08026044
_0802603A:
	bl sub_8026D88
	b _08026044
_08026040:
	movs r0, 0x3
	b _08026046
_08026044:
	movs r0, 0
_08026046:
	pop {r1}
	bx r1
	thumb_func_end sub_8025F68

	thumb_func_start sub_802604C
sub_802604C:
	ldr r0, _08026054
	ldr r0, [r0]
	ldrb r0, [r0, 0x8]
	bx lr
	.align 2, 0
_08026054: .4byte gUnknown_203B2B8
	thumb_func_end sub_802604C

	thumb_func_start sub_8026058
sub_8026058:
	push {r4,lr}
	ldr r4, _08026070
	ldr r0, [r4]
	cmp r0, 0
	beq _0802606A
	bl MemoryFree
	movs r0, 0
	str r0, [r4]
_0802606A:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08026070: .4byte gUnknown_203B2B8
	thumb_func_end sub_8026058

	thumb_func_start sub_8026074
sub_8026074:
	push {lr}
	ldr r1, _08026088
	ldr r1, [r1]
	str r0, [r1]
	bl sub_802608C
	bl sub_80261D0
	pop {r0}
	bx r0
	.align 2, 0
_08026088: .4byte gUnknown_203B2B8
	thumb_func_end sub_8026074

	thumb_func_start sub_802608C
sub_802608C:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	ldr r4, _080260B8
	ldr r0, [r4]
	movs r5, 0x88
	lsls r5, 2
	adds r0, r5
	bl sub_8006518
	ldr r0, [r4]
	ldr r0, [r0]
	cmp r0, 0x1
	blt _08026178
	cmp r0, 0x2
	ble _080260BC
	cmp r0, 0x14
	beq _0802614C
	b _08026178
	.align 2, 0
_080260B8: .4byte gUnknown_203B2B8
_080260BC:
	ldr r0, _0802613C
	mov r12, r0
	ldr r1, _08026140
	mov r8, r1
	mov r9, r4
	mov r10, r5
	movs r3, 0
	movs r2, 0x3
_080260CC:
	mov r5, r9
	ldr r1, [r5]
	adds r1, r3
	add r1, r10
	ldr r0, _08026144
	ldm r0!, {r5-r7}
	stm r1!, {r5-r7}
	ldm r0!, {r5-r7}
	stm r1!, {r5-r7}
	adds r3, 0x18
	subs r2, 0x1
	cmp r2, 0
	bge _080260CC
	ldr r1, [r4]
	movs r6, 0x88
	lsls r6, 2
	adds r1, r6
	mov r0, r12
	ldm r0!, {r2,r3,r7}
	stm r1!, {r2,r3,r7}
	ldm r0!, {r5-r7}
	stm r1!, {r5-r7}
	ldr r1, [r4]
	movs r0, 0x9A
	lsls r0, 2
	adds r1, r0
	mov r0, r8
	ldm r0!, {r2,r3,r5}
	stm r1!, {r2,r3,r5}
	ldm r0!, {r2,r6,r7}
	stm r1!, {r2,r6,r7}
	bl sub_80264CC
	ldr r2, [r4]
	movs r0, 0x94
	lsls r0, 2
	adds r2, r0
	ldr r1, _08026148
	ldm r1!, {r3,r5,r6}
	stm r2!, {r3,r5,r6}
	ldm r1!, {r3,r5,r7}
	stm r2!, {r3,r5,r7}
	ldr r1, [r4]
	adds r0, r1, r0
	movs r6, 0xB6
	lsls r6, 1
	adds r1, r6
	bl sub_8012CAC
	ldr r0, [r4]
	movs r7, 0x97
	lsls r7, 2
	adds r0, r7
	movs r1, 0x9
	strh r1, [r0]
	b _080261A2
	.align 2, 0
_0802613C: .4byte gUnknown_80DD358
_08026140: .4byte gUnknown_80DD370
_08026144: .4byte gUnknown_80DD310
_08026148: .4byte gUnknown_80DD328
_0802614C:
	bl sub_802678C
	ldr r2, [r4]
	movs r0, 0x94
	lsls r0, 2
	adds r2, r0
	ldr r1, _08026174
	ldm r1!, {r3,r5,r6}
	stm r2!, {r3,r5,r6}
	ldm r1!, {r3,r5,r7}
	stm r2!, {r3,r5,r7}
	ldr r1, [r4]
	adds r0, r1, r0
	movs r6, 0xB6
	lsls r6, 1
	adds r1, r6
	bl sub_8012CAC
	b _080261A2
	.align 2, 0
_08026174: .4byte gUnknown_80DD340
_08026178:
	ldr r7, _080261C8
	mov r8, r7
	movs r0, 0x88
	lsls r0, 2
	mov r9, r0
	ldr r4, _080261CC
	movs r3, 0
	movs r2, 0x3
_08026188:
	mov r5, r8
	ldr r1, [r5]
	adds r1, r3
	add r1, r9
	adds r0, r4, 0
	ldm r0!, {r5-r7}
	stm r1!, {r5-r7}
	ldm r0!, {r5-r7}
	stm r1!, {r5-r7}
	adds r3, 0x18
	subs r2, 0x1
	cmp r2, 0
	bge _08026188
_080261A2:
	bl ResetUnusedInputStruct
	ldr r0, _080261C8
	ldr r0, [r0]
	movs r6, 0x88
	lsls r6, 2
	adds r0, r6
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_080261C8: .4byte gUnknown_203B2B8
_080261CC: .4byte gUnknown_80DD310
	thumb_func_end sub_802608C

	thumb_func_start sub_80261D0
sub_80261D0:
	push {r4,r5,lr}
	sub sp, 0x18
	ldr r1, _080261EC
	ldr r0, [r1]
	ldr r0, [r0]
	adds r4, r1, 0
	cmp r0, 0x19
	bls _080261E2
	b _080264BA
_080261E2:
	lsls r0, 2
	ldr r1, _080261F0
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080261EC: .4byte gUnknown_203B2B8
_080261F0: .4byte _080261F4
	.align 2, 0
_080261F4:
	.4byte _080264BA
	.4byte _0802625C
	.4byte _080262A8
	.4byte _080262EC
	.4byte _080262FA
	.4byte _080263F8
	.4byte _0802640C
	.4byte _08026420
	.4byte _08026434
	.4byte _08026448
	.4byte _0802648A
	.4byte _080264A8
	.4byte _08026392
	.4byte _080263AC
	.4byte _08026306
	.4byte _08026464
	.4byte _08026474
	.4byte _08026484
	.4byte _08026310
	.4byte _0802631E
	.4byte _08026326
	.4byte _08026350
	.4byte _08026362
	.4byte _08026388
	.4byte _080263E0
	.4byte _080264BA
_0802625C:
	movs r0, 0x3
	bl sub_8026E08
	ldr r5, _080262A0
	ldr r1, [r5]
	adds r1, 0x14
	movs r0, 0
	bl sub_8026DAC
	ldr r4, _080262A4
	ldr r0, [r5]
	ldr r1, [r0, 0x18]
	adds r0, r4, 0
	movs r2, 0x7
	bl PrintColoredPokeNameToBuffer
	adds r4, 0x50
	ldr r0, [r5]
	ldr r1, [r0, 0x18]
	adds r0, r4, 0
	movs r2, 0x6
	bl PrintColoredPokeNameToBuffer
	ldr r2, [r5]
	adds r0, r2, 0
	adds r0, 0x7C
	movs r3, 0xB6
	lsls r3, 1
	adds r1, r2, r3
	movs r4, 0x83
	lsls r4, 2
	adds r3, r2, r4
	ldr r2, [r2, 0x70]
	b _0802633E
	.align 2, 0
_080262A0: .4byte gUnknown_203B2B8
_080262A4: .4byte gAvailablePokemonNames
_080262A8:
	movs r0, 0x3
	bl sub_8026E08
	ldr r5, _080262E4
	ldr r1, [r5]
	adds r1, 0x14
	movs r0, 0
	bl sub_8026DAC
	ldr r4, _080262E8
	ldr r0, [r5]
	ldr r1, [r0, 0x18]
	adds r0, r4, 0
	movs r2, 0x7
	bl PrintColoredPokeNameToBuffer
	adds r4, 0x50
	ldr r0, [r5]
	ldr r1, [r0, 0x18]
	adds r0, r4, 0
	movs r2, 0x6
	bl PrintColoredPokeNameToBuffer
	ldr r0, [r5]
	adds r0, 0x7C
	movs r1, 0x1
	bl sub_8012EA4
	b _080264BA
	.align 2, 0
_080262E4: .4byte gUnknown_203B2B8
_080262E8: .4byte gAvailablePokemonNames
_080262EC:
	ldr r0, [r4]
	movs r1, 0xA
	ldrsh r0, [r0, r1]
	movs r1, 0x2
	bl sub_8024458
	b _080264BA
_080262FA:
	ldr r0, [r4]
	movs r3, 0xA
	ldrsh r0, [r0, r3]
	bl sub_801BEEC
	b _080264BA
_08026306:
	ldr r0, [r4]
	ldr r0, [r0, 0x18]
	bl sub_80227B8
	b _080264BA
_08026310:
	movs r0, 0x1
	movs r1, 0
	movs r2, 0
	movs r3, 0xA
	bl sub_801A5D8
	b _080264BA
_0802631E:
	movs r0, 0x1
	bl sub_801A8D0
	b _080264BA
_08026326:
	bl sub_801A9E0
	ldr r0, _0802634C
	ldr r2, [r0]
	adds r0, r2, 0
	adds r0, 0xCC
	movs r4, 0xB6
	lsls r4, 1
	adds r1, r2, r4
	adds r4, 0xA0
	adds r3, r2, r4
	ldr r2, [r2, 0x74]
_0802633E:
	str r2, [sp]
	movs r2, 0x2
	str r2, [sp, 0x4]
	movs r2, 0
	bl sub_8012D60
	b _080264BA
	.align 2, 0
_0802634C: .4byte gUnknown_203B2B8
_08026350:
	ldr r1, [r4]
	adds r1, 0x10
	add r0, sp, 0x14
	bl HeldItemToSlot
	add r0, sp, 0x14
	bl sub_801B3C0
	b _080264BA
_08026362:
	ldr r1, [r4]
	adds r0, r1, 0
	adds r0, 0x28
	ldr r1, [r1, 0x18]
	adds r1, 0x2C
	bl sub_809401C
	ldr r2, [r4]
	movs r0, 0xA
	ldrsh r1, [r2, r0]
	adds r2, 0x28
	movs r0, 0
	str r0, [sp]
	str r0, [sp, 0x4]
	movs r0, 0x3
	movs r3, 0
	bl sub_801EE10
	b _080264BA
_08026388:
	movs r0, 0x1
	movs r1, 0
	bl sub_801F1B0
	b _080264BA
_08026392:
	bl sub_8026878
	ldr r0, _080263A4
	ldr r1, _080263A8
	ldr r3, [r1]
	movs r1, 0xDE
	lsls r1, 1
	adds r3, r1
	b _080263BC
	.align 2, 0
_080263A4: .4byte gUnknown_80DD388
_080263A8: .4byte gUnknown_203B2B8
_080263AC:
	bl sub_8026878
	ldr r0, _080263D8
	ldr r1, _080263DC
	ldr r3, [r1]
	movs r4, 0xDE
	lsls r4, 1
	adds r3, r4
_080263BC:
	movs r2, 0
	str r2, [sp]
	movs r1, 0x4
	str r1, [sp, 0x4]
	str r2, [sp, 0x8]
	str r2, [sp, 0xC]
	adds r1, 0xFD
	str r1, [sp, 0x10]
	movs r1, 0
	movs r2, 0x3
	bl sub_8014248
	b _080264BA
	.align 2, 0
_080263D8: .4byte gUnknown_80DD420
_080263DC: .4byte gUnknown_203B2B8
_080263E0:
	ldr r2, [r4]
	ldr r0, [r2, 0x20]
	adds r1, r2, 0
	adds r1, 0x28
	adds r2, 0x68
	bl sub_8093560
	ldr r0, [r4]
	adds r0, 0x68
	bl sub_801F808
	b _080264BA
_080263F8:
	ldr r1, [r4]
	movs r0, 0x19
	str r0, [r1, 0x4]
	movs r0, 0xCF
	bl PlaySound
	ldr r0, _08026408
	b _08026492
	.align 2, 0
_08026408: .4byte gUnknown_80DD4C4
_0802640C:
	ldr r1, [r4]
	movs r0, 0x19
	str r0, [r1, 0x4]
	movs r0, 0xCF
	bl PlaySound
	ldr r0, _0802641C
	b _08026492
	.align 2, 0
_0802641C: .4byte gUnknown_80DD4F4
_08026420:
	ldr r1, [r4]
	movs r0, 0x19
	str r0, [r1, 0x4]
	movs r0, 0xCC
	bl PlaySound
	ldr r0, _08026430
	b _08026492
	.align 2, 0
_08026430: .4byte gUnknown_80DD534
_08026434:
	ldr r1, [r4]
	movs r0, 0x9
	str r0, [r1, 0x4]
	movs r0, 0xCA
	bl PlaySound
	ldr r0, _08026444
	b _08026492
	.align 2, 0
_08026444: .4byte gUnknown_80DD564
_08026448:
	bl sub_8026FA4
	ldr r4, _08026460
	ldr r0, [r4]
	ldr r0, [r0, 0x18]
	bl sub_808D31C
	ldr r1, [r4]
	movs r0, 0x1
	strb r0, [r1, 0x8]
	b _080264BA
	.align 2, 0
_08026460: .4byte gUnknown_203B2B8
_08026464:
	ldr r1, [r4]
	movs r0, 0x2
	str r0, [r1, 0x4]
	ldr r0, _08026470
	b _08026492
	.align 2, 0
_08026470: .4byte gUnknown_80DD594
_08026474:
	ldr r1, [r4]
	movs r0, 0x2
	str r0, [r1, 0x4]
	ldr r0, _08026480
	b _08026492
	.align 2, 0
_08026480: .4byte gUnknown_80DD5B8
_08026484:
	ldr r1, [r4]
	movs r0, 0x2
	b _0802648E
_0802648A:
	ldr r1, [r4]
	movs r0, 0x19
_0802648E:
	str r0, [r1, 0x4]
	ldr r0, _080264A0
_08026492:
	ldr r3, _080264A4
	movs r1, 0
	movs r2, 0
	bl sub_80141B4
	b _080264BA
	.align 2, 0
_080264A0: .4byte gUnknown_80DD60C
_080264A4: .4byte 0x00000101
_080264A8:
	ldr r1, [r4]
	movs r0, 0x19
	str r0, [r1, 0x4]
	ldr r0, _080264C4
	ldr r3, _080264C8
	movs r1, 0
	movs r2, 0
	bl sub_80141B4
_080264BA:
	add sp, 0x18
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_080264C4: .4byte gUnknown_80DD63C
_080264C8: .4byte 0x00000101
	thumb_func_end sub_80261D0

	thumb_func_start sub_80264CC
sub_80264CC:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	ldr r3, _08026574
	ldr r4, _08026578
	ldr r0, [r4]
	movs r1, 0xA
	ldrsh r2, [r0, r1]
	movs r1, 0x58
	muls r2, r1
	ldr r1, [r3]
	adds r1, r2
	mov r8, r1
	movs r2, 0x83
	lsls r2, 2
	adds r0, r2
	movs r1, 0
	movs r2, 0x14
	bl MemoryFill16
	ldr r1, [r4]
	ldr r0, [r1, 0x18]
	ldrb r0, [r0, 0x2]
	strb r0, [r1, 0x1C]
	ldr r1, [r4]
	movs r3, 0xA
	ldrsh r0, [r1, r3]
	adds r1, 0x14
	bl PeekPokemonItem
	mov r1, r8
	ldrh r0, [r1]
	lsrs r0, 1
	movs r5, 0x1
	ands r0, r5
	cmp r0, 0
	beq _08026584
	ldr r2, [r4]
	movs r3, 0xB6
	lsls r3, 1
	adds r1, r2, r3
	ldr r0, _0802657C
	str r0, [r1]
	movs r0, 0xB8
	lsls r0, 1
	adds r1, r2, r0
	movs r0, 0x7
	str r0, [r1]
	mov r0, r8
	bl sub_8026E88
	lsls r0, 24
	cmp r0, 0
	bne _08026542
	ldr r0, [r4]
	movs r1, 0x83
	lsls r1, 2
	adds r0, r1
	strh r5, [r0]
_08026542:
	movs r6, 0x1
	movs r0, 0x8
	bl sub_80023E4
	lsls r0, 24
	cmp r0, 0
	beq _080265B4
	mov r2, r8
	ldrb r0, [r2, 0x2]
	cmp r0, 0
	bne _080265B4
	ldr r3, [r4]
	movs r2, 0x8
	movs r4, 0xBA
	lsls r4, 1
	adds r1, r3, r4
	ldr r0, _08026580
	str r0, [r1]
	movs r1, 0xBC
	lsls r1, 1
	adds r0, r3, r1
	str r2, [r0]
	movs r6, 0x2
	b _080265B4
	.align 2, 0
_08026574: .4byte gRecruitedPokemonRef
_08026578: .4byte gUnknown_203B2B8
_0802657C: .4byte gPartyMenuStandBy
_08026580: .4byte gPartyMenuMakeLeader
_08026584:
	ldr r2, [r4]
	movs r3, 0xB6
	lsls r3, 1
	adds r1, r2, r3
	ldr r0, _08026734
	str r0, [r1]
	movs r0, 0xB8
	lsls r0, 1
	adds r1, r2, r0
	movs r0, 0x6
	str r0, [r1]
	movs r1, 0xA
	ldrsh r0, [r2, r1]
	bl sub_808D750
	lsls r0, 24
	cmp r0, 0
	bne _080265B2
	ldr r0, [r4]
	movs r2, 0x83
	lsls r2, 2
	adds r0, r2
	strh r5, [r0]
_080265B2:
	movs r6, 0x1
_080265B4:
	ldr r4, _08026738
	ldr r2, [r4]
	lsls r3, r6, 3
	movs r7, 0xB6
	lsls r7, 1
	adds r0, r2, r7
	adds r0, r3
	ldr r1, _0802673C
	str r1, [r0]
	movs r5, 0xB8
	lsls r5, 1
	adds r2, r5
	adds r2, r3
	movs r0, 0xA
	str r0, [r2]
	bl HasGummiItem
	lsls r0, 24
	cmp r0, 0
	bne _080265EC
	ldr r0, [r4]
	lsls r1, r6, 1
	movs r3, 0x83
	lsls r3, 2
	adds r0, r3
	adds r0, r1
	movs r1, 0x1
	strh r1, [r0]
_080265EC:
	adds r6, 0x1
	ldr r2, [r4]
	lsls r3, r6, 3
	adds r0, r2, r7
	adds r0, r3
	ldr r1, _08026740
	str r1, [r0]
	adds r2, r5
	adds r2, r3
	movs r0, 0xB
	str r0, [r2]
	bl GetNumberOfFilledInventorySlots
	cmp r0, 0
	bne _0802661A
	ldr r0, [r4]
	lsls r1, r6, 1
	movs r2, 0x83
	lsls r2, 2
	adds r0, r2
	adds r0, r1
	movs r1, 0x1
	strh r1, [r0]
_0802661A:
	adds r6, 0x1
	ldr r2, [r4]
	lsls r3, r6, 3
	adds r0, r2, r7
	adds r0, r3
	ldr r1, _08026744
	str r1, [r0]
	adds r2, r5
	adds r2, r3
	movs r0, 0xC
	str r0, [r2]
	bl GetNumberOfFilledInventorySlots
	cmp r0, 0x13
	bgt _08026640
	ldr r0, [r4]
	ldrb r0, [r0, 0x14]
	cmp r0, 0
	bne _08026650
_08026640:
	ldr r0, [r4]
	lsls r1, r6, 1
	movs r3, 0x83
	lsls r3, 2
	adds r0, r3
	adds r0, r1
	movs r1, 0x1
	strh r1, [r0]
_08026650:
	adds r6, 0x1
	mov r4, r8
	ldrh r0, [r4]
	lsrs r0, 1
	movs r5, 0x1
	ands r0, r5
	cmp r0, 0
	bne _0802669A
	ldr r4, _08026738
	ldr r3, [r4]
	lsls r2, r6, 3
	movs r1, 0xB6
	lsls r1, 1
	adds r0, r3, r1
	adds r0, r2
	ldr r1, _08026748
	str r1, [r0]
	movs r1, 0xB8
	lsls r1, 1
	adds r0, r3, r1
	adds r0, r2
	movs r1, 0x9
	str r1, [r0]
	mov r0, r8
	bl sub_8026EB8
	lsls r0, 24
	cmp r0, 0
	bne _08026698
	ldr r0, [r4]
	lsls r1, r6, 1
	movs r2, 0x83
	lsls r2, 2
	adds r0, r2
	adds r0, r1
	strh r5, [r0]
_08026698:
	adds r6, 0x1
_0802669A:
	ldr r4, _08026738
	ldr r5, [r4]
	lsls r1, r6, 3
	movs r0, 0xB6
	lsls r0, 1
	adds r3, r5, r0
	adds r2, r3, r1
	ldr r0, _0802674C
	str r0, [r2]
	movs r2, 0xB8
	lsls r2, 1
	adds r7, r5, r2
	adds r1, r7, r1
	movs r0, 0x4
	str r0, [r1]
	adds r6, 0x1
	lsls r1, r6, 3
	adds r2, r3, r1
	ldr r0, _08026750
	str r0, [r2]
	adds r1, r7, r1
	movs r0, 0xD
	str r0, [r1]
	adds r6, 0x1
	lsls r1, r6, 3
	adds r2, r3, r1
	ldr r0, _08026754
	str r0, [r2]
	adds r1, r7, r1
	movs r0, 0x5
	str r0, [r1]
	adds r6, 0x1
	lsls r1, r6, 3
	adds r3, r1
	movs r0, 0
	str r0, [r3]
	adds r1, r7, r1
	movs r0, 0x1
	str r0, [r1]
	movs r3, 0
	mov r12, r4
	cmp r3, r6
	bge _08026710
	adds r4, r7, 0
	movs r0, 0x83
	lsls r0, 2
	adds r2, r5, r0
_080266F8:
	ldrh r0, [r2]
	cmp r0, 0
	bne _08026706
	ldr r1, [r4]
	ldr r0, [r5, 0x70]
	cmp r1, r0
	beq _08026780
_08026706:
	adds r4, 0x8
	adds r2, 0x2
	adds r3, 0x1
	cmp r3, r6
	blt _080266F8
_08026710:
	movs r3, 0
	cmp r3, r6
	bge _08026780
	mov r2, r12
	ldr r1, [r2]
	movs r4, 0x83
	lsls r4, 2
	adds r0, r1, r4
	ldrh r0, [r0]
	cmp r0, 0
	bne _08026758
	movs r2, 0xB8
	lsls r2, 1
	adds r0, r1, r2
	ldr r0, [r0]
	str r0, [r1, 0x70]
	b _08026780
	.align 2, 0
_08026734: .4byte gPartyMenuJoinTeam
_08026738: .4byte gUnknown_203B2B8
_0802673C: .4byte gPartyMenuGiveGummi
_08026740: .4byte gPartyMenuGive
_08026744: .4byte gPartyMenuTake
_08026748: .4byte gPartyMenuSayFarewell
_0802674C: .4byte gPartyMenuSummary
_08026750: .4byte gPartyMenuMoves
_08026754: .4byte gPartyMenuCheckIQ
_08026758:
	adds r3, 0x1
	cmp r3, r6
	bge _08026780
	mov r4, r12
	ldr r2, [r4]
	lsls r0, r3, 1
	movs r4, 0x83
	lsls r4, 2
	adds r1, r2, r4
	adds r1, r0
	ldrh r0, [r1]
	cmp r0, 0
	bne _08026758
	lsls r0, r3, 3
	movs r3, 0xB8
	lsls r3, 1
	adds r1, r2, r3
	adds r1, r0
	ldr r0, [r1]
	str r0, [r2, 0x70]
_08026780:
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_80264CC

	thumb_func_start sub_802678C
sub_802678C:
	push {r4-r7,lr}
	ldr r5, _08026840
	ldr r0, [r5]
	movs r7, 0x83
	lsls r7, 2
	adds r0, r7
	movs r1, 0
	movs r2, 0x14
	bl MemoryFill16
	ldr r2, [r5]
	movs r0, 0xB6
	lsls r0, 1
	adds r1, r2, r0
	ldr r0, _08026844
	str r0, [r1]
	movs r3, 0xB8
	lsls r3, 1
	adds r1, r2, r3
	movs r0, 0xB
	str r0, [r1]
	bl GetNumberOfFilledInventorySlots
	cmp r0, 0
	bne _080267C8
	ldr r0, [r5]
	adds r4, r7, 0
	adds r0, r4
	movs r1, 0x1
	strh r1, [r0]
_080267C8:
	ldr r4, [r5]
	movs r2, 0x1
	movs r0, 0xBA
	lsls r0, 1
	adds r1, r4, r0
	ldr r0, _08026848
	ldr r0, [r0]
	str r0, [r1]
	movs r3, 0xBC
	lsls r3, 1
	adds r1, r4, r3
	movs r0, 0x4
	str r0, [r1]
	movs r6, 0x2
	movs r0, 0xBE
	lsls r0, 1
	adds r1, r4, r0
	movs r0, 0
	str r0, [r1]
	movs r1, 0xC0
	lsls r1, 1
	adds r0, r4, r1
	str r2, [r0]
	movs r3, 0
	mov r12, r4
	movs r4, 0xB8
	lsls r4, 1
	add r4, r12
	mov r0, r12
	adds r2, r0, r7
_08026804:
	ldrh r0, [r2]
	cmp r0, 0
	bne _08026814
	ldr r1, [r4]
	mov r7, r12
	ldr r0, [r7, 0x74]
	cmp r1, r0
	beq _08026872
_08026814:
	adds r4, 0x8
	adds r2, 0x2
	adds r3, 0x1
	cmp r3, r6
	blt _08026804
	movs r3, 0
	cmp r3, r6
	bge _08026872
	ldr r1, [r5]
	movs r2, 0x83
	lsls r2, 2
	adds r0, r1, r2
	ldrh r0, [r0]
	cmp r0, 0
	bne _0802684C
	movs r3, 0xB8
	lsls r3, 1
	adds r0, r1, r3
	ldr r0, [r0]
	str r0, [r1, 0x74]
	b _08026872
	.align 2, 0
_08026840: .4byte gUnknown_203B2B8
_08026844: .4byte gPartyMenuGive
_08026848: .4byte gUnknown_80D4970
_0802684C:
	adds r3, 0x1
	cmp r3, r6
	bge _08026872
	ldr r2, [r5]
	lsls r0, r3, 1
	movs r4, 0x83
	lsls r4, 2
	adds r1, r2, r4
	adds r1, r0
	ldrh r0, [r1]
	cmp r0, 0
	bne _0802684C
	lsls r0, r3, 3
	movs r7, 0xB8
	lsls r7, 1
	adds r1, r2, r7
	adds r1, r0
	ldr r0, [r1]
	str r0, [r2, 0x74]
_08026872:
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_802678C

	thumb_func_start sub_8026878
sub_8026878:
	ldr r0, _080268C0
	ldr r0, [r0]
	mov r12, r0
	movs r3, 0
	movs r1, 0xDE
	lsls r1, 1
	add r1, r12
	ldr r0, _080268C4
	ldr r0, [r0]
	str r0, [r1]
	movs r1, 0xE0
	lsls r1, 1
	add r1, r12
	movs r0, 0x2
	str r0, [r1]
	movs r2, 0x1
	movs r1, 0xE2
	lsls r1, 1
	add r1, r12
	ldr r0, _080268C8
	ldr r0, [r0]
	str r0, [r1]
	movs r1, 0xE4
	lsls r1, 1
	add r1, r12
	movs r0, 0x3
	str r0, [r1]
	movs r0, 0xE6
	lsls r0, 1
	add r0, r12
	str r3, [r0]
	movs r0, 0xE8
	lsls r0, 1
	add r0, r12
	str r2, [r0]
	bx lr
	.align 2, 0
_080268C0: .4byte gUnknown_203B2B8
_080268C4: .4byte gUnknown_80D4920
_080268C8: .4byte gUnknown_80D4928
	thumb_func_end sub_8026878

        .align 2,0
