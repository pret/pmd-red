	#include "asm/constants/gba_constants.inc"
	#include "asm/macros.inc"

	.syntax unified

	.text

	thumb_func_start sub_806D528
sub_806D528:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x58
	mov r9, r0
	adds r7, r1, 0
	adds r5, r2, 0
	str r3, [sp, 0x4C]
	ldr r0, [sp, 0x7C]
	lsls r0, 16
	asrs r0, 16
	str r0, [sp, 0x50]
	movs r0, 0
	str r0, [sp, 0x54]
	mov r10, r0
	mov r8, r0
	mov r1, r10
	strb r1, [r5, 0xF]
	adds r0, r7, 0
	bl GetEntityType
	cmp r0, 0x1
	beq _0806D55C
	b _0806D754
_0806D55C:
	ldr r6, [r7, 0x70]
	mov r0, r9
	adds r1, r7, 0
	bl TrySendImmobilizeSleepEndMsg
	mov r0, r9
	adds r1, r7, 0
	bl SetShopkeeperAggression
	mov r0, r9
	bl GetEntityType
	cmp r0, 0x1
	bne _0806D592
	mov r2, r9
	ldr r0, [r2, 0x70]
	adds r0, 0xDC
	ldrb r0, [r0]
	cmp r0, 0x3
	bne _0806D592
	ldrb r0, [r5, 0xE]
	cmp r0, 0
	bne _0806D592
	ldr r0, _0806D5C8
	movs r3, 0
	ldrsh r0, [r0, r3]
	str r0, [r5]
_0806D592:
	ldr r0, _0806D5CC
	ldr r1, [sp, 0x50]
	cmp r1, r0
	beq _0806D5DC
	adds r0, r7, 0
	movs r1, 0xD
	bl HasAbility
	lsls r0, 24
	cmp r0, 0
	beq _0806D5DC
	ldr r1, [r5]
	ldr r0, _0806D5D0
	cmp r1, r0
	bne _0806D5DC
	ldr r0, _0806D5D4
	adds r1, r7, 0
	movs r2, 0
	bl SetMessageArgument
	ldr r0, _0806D5D8
	ldr r2, [r0]
	mov r0, r9
	adds r1, r7, 0
	bl sub_80522F4
	b _0806D71E
	.align 2, 0
_0806D5C8: .4byte gUnknown_80F4F8C
_0806D5CC: .4byte 0x0000020e
_0806D5D0: .4byte 0x0000270f
_0806D5D4: .4byte gUnknown_202DFE8
_0806D5D8: .4byte gUnknown_80FCA90
_0806D5DC:
	adds r0, r6, 0
	adds r0, 0xB0
	ldrb r4, [r0]
	mov r10, r0
	cmp r4, 0x1
	bne _0806D618
	ldr r0, _0806D610
	adds r1, r7, 0
	movs r2, 0
	bl SetMessageArgument
	ldr r0, _0806D614
	ldr r2, [r0]
	mov r0, r9
	adds r1, r7, 0
	bl sub_80522F4
	mov r0, r9
	adds r1, r7, 0
	bl sub_8042238
	strb r4, [r5, 0xF]
_0806D608:
	movs r0, 0
	bl _0806E0F0
	.align 2, 0
_0806D610: .4byte gUnknown_202DFE8
_0806D614: .4byte gUnknown_80F9600
_0806D618:
	adds r0, r6, 0
	adds r0, 0xA8
	ldrb r0, [r0]
	cmp r0, 0x1
	beq _0806D62A
	cmp r0, 0x5
	beq _0806D62A
	cmp r0, 0x3
	bne _0806D63A
_0806D62A:
	adds r0, r6, 0
	adds r0, 0xA9
	ldrb r0, [r0]
	cmp r0, 0x7F
	bne _0806D63A
	adds r0, r7, 0
	bl WakeUpPokemon
_0806D63A:
	adds r0, r7, 0
	movs r1, 0x23
	bl HasAbility
	lsls r0, 24
	cmp r0, 0
	beq _0806D660
	ldrb r0, [r5, 0xC]
	cmp r0, 0x5
	bne _0806D660
_0806D64E:
	ldr r2, [r5]
	movs r0, 0
	str r0, [sp]
	mov r0, r9
	adds r1, r7, 0
	movs r3, 0
	bl HealTargetHP
	b _0806D754
_0806D660:
	adds r0, r7, 0
	movs r1, 0x24
	bl HasAbility
	lsls r0, 24
	cmp r0, 0
	beq _0806D674
	ldrb r0, [r5, 0xC]
	cmp r0, 0x3
	beq _0806D64E
_0806D674:
	movs r2, 0xA9
	lsls r2, 1
	adds r0, r6, r2
	ldrb r0, [r0]
	cmp r0, 0
	bne _0806D6D0
	ldrb r0, [r5, 0xD]
	cmp r0, 0
	beq _0806D692
	ldr r0, _0806D6A4
	ldr r2, [r0]
	mov r0, r9
	adds r1, r7, 0
	bl sub_80522F4
_0806D692:
	ldr r0, [r5, 0x8]
	cmp r0, 0x1
	beq _0806D6B0
	cmp r0, 0x1
	bcc _0806D6A8
	cmp r0, 0x3
	beq _0806D6C4
	b _0806D6D0
	.align 2, 0
_0806D6A4: .4byte gUnknown_80F9614
_0806D6A8:
	ldr r0, _0806D6AC
	b _0806D6B2
	.align 2, 0
_0806D6AC: .4byte gUnknown_80F9630
_0806D6B0:
	ldr r0, _0806D6C0
_0806D6B2:
	ldr r2, [r0]
	mov r0, r9
	adds r1, r7, 0
	bl sub_80522F4
	b _0806D6D0
	.align 2, 0
_0806D6C0: .4byte gUnknown_80F9654
_0806D6C4:
	ldr r0, _0806D728
	ldr r2, [r0]
	mov r0, r9
	adds r1, r7, 0
	bl sub_80522F4
_0806D6D0:
	ldr r4, _0806D72C
	adds r0, r4, 0
	mov r1, r9
	movs r2, 0
	bl SetMessageArgument
	adds r4, 0x50
	adds r0, r4, 0
	adds r1, r7, 0
	movs r2, 0
	bl SetMessageArgument
	ldr r1, [r5]
	cmp r1, 0
	bne _0806D760
	mov r0, r9
	bl sub_8045888
	lsls r0, 24
	cmp r0, 0
	beq _0806D734
	adds r0, r7, 0
	bl sub_8045888
	lsls r0, 24
	cmp r0, 0
	beq _0806D734
	movs r3, 0xA9
	lsls r3, 1
	adds r0, r6, r3
	ldrb r0, [r0]
	cmp r0, 0
	bne _0806D71E
	ldr r0, _0806D730
	ldr r2, [r0]
	mov r0, r9
	adds r1, r7, 0
	bl sub_80522F4
_0806D71E:
	mov r0, r9
	adds r1, r7, 0
	bl sub_8042238
	b _0806D754
	.align 2, 0
_0806D728: .4byte gUnknown_80F9670
_0806D72C: .4byte gAvailablePokemonNames
_0806D730: .4byte gUnknown_80F9688
_0806D734:
	movs r1, 0xA9
	lsls r1, 1
	adds r0, r6, r1
	ldrb r0, [r0]
	cmp r0, 0
	bne _0806D74C
	ldr r0, _0806D75C
	ldr r2, [r0]
	mov r0, r9
	adds r1, r7, 0
	bl sub_80522F4
_0806D74C:
	movs r0, 0x1E
	movs r1, 0x18
	bl sub_803E708
_0806D754:
	movs r0, 0x1
	strb r0, [r5, 0xF]
	b _0806D608
	.align 2, 0
_0806D75C: .4byte gUnknown_80F9688
_0806D760:
	ldr r0, _0806D7B8
	cmp r1, r0
	bne _0806D7C4
	ldr r0, [sp, 0x80]
	cmp r0, 0
	beq _0806D796
	adds r0, r7, 0
	bl sub_8045888
	lsls r0, 24
	cmp r0, 0
	beq _0806D796
	adds r0, r7, 0
	bl GetTileAtEntitySafe
	mov r8, r0
	movs r0, 0x14
	movs r1, 0x18
	bl sub_803E708
	mov r2, r8
	ldrh r1, [r2, 0x4]
	movs r0, 0x4
	orrs r0, r1
	strh r0, [r2, 0x4]
	bl sub_8049ED4
_0806D796:
	movs r3, 0xA9
	lsls r3, 1
	adds r0, r6, r3
	ldrb r0, [r0]
	cmp r0, 0
	bne _0806D7AE
	ldr r0, _0806D7BC
	ldr r2, [r0]
	mov r0, r9
	adds r1, r7, 0
	bl sub_80522F4
_0806D7AE:
	adds r1, r6, 0
	adds r1, 0xA0
	ldr r0, _0806D7C0
	str r0, [r1]
	b _0806D84A
	.align 2, 0
_0806D7B8: .4byte 0x0000270f
_0806D7BC: .4byte gUnknown_80F96A8
_0806D7C0: .4byte 0x000003e7
_0806D7C4:
	ldr r0, _0806D824
	str r1, [r0]
	ldr r1, _0806D828
	ldr r0, [r5, 0x4]
	lsls r0, 2
	adds r0, r1
	ldr r4, [r0]
	adds r2, r6, 0
	adds r2, 0xA0
	ldr r0, [r2]
	ldr r1, [r5]
	adds r0, r1
	str r0, [r2]
	ldr r1, _0806D82C
	cmp r0, r1
	ble _0806D7E6
	str r1, [r2]
_0806D7E6:
	adds r0, r7, 0
	bl sub_8045888
	lsls r0, 24
	cmp r0, 0
	beq _0806D830
	ldr r0, [r5, 0x4]
	cmp r0, 0xE
	beq _0806D808
	ldr r0, [r5]
	negs r0, r0
	movs r3, 0x1
	negs r3, r3
	adds r1, r7, 0
	movs r2, 0x1
	bl sub_803ED30
_0806D808:
	movs r1, 0xA9
	lsls r1, 1
	adds r0, r6, r1
	ldrb r0, [r0]
	cmp r0, 0
	bne _0806D84A
	cmp r4, 0
	beq _0806D84A
	mov r0, r9
	adds r1, r7, 0
	adds r2, r4, 0
	bl sub_80522F4
	b _0806D84A
	.align 2, 0
_0806D824: .4byte gFormatData_202DE30
_0806D828: .4byte gUnknown_80F9764
_0806D82C: .4byte 0x000003e7
_0806D830:
	movs r2, 0xA9
	lsls r2, 1
	adds r0, r6, r2
	ldrb r0, [r0]
	cmp r0, 0
	bne _0806D84A
	cmp r4, 0
	beq _0806D84A
	mov r0, r9
	adds r1, r7, 0
	adds r2, r4, 0
	bl sub_80522F4
_0806D84A:
	ldr r0, [r5, 0x4]
	cmp r0, 0xE
	bne _0806D858
	movs r3, 0xE
	ldrsh r0, [r6, r3]
	cmp r0, 0x1
	bgt _0806D900
_0806D858:
	mov r0, r8
	cmp r0, 0
	bne _0806D900
	adds r0, r7, 0
	bl sub_8045888
	lsls r0, 24
	cmp r0, 0
	beq _0806D900
	mov r2, r9
	ldr r1, [r2, 0x4]
	ldr r0, [r7, 0x4]
	cmp r1, r0
	beq _0806D8E6
	mov r0, r9
	bl GetEntityType
	cmp r0, 0x1
	bne _0806D8E6
	movs r4, 0
	ldrb r0, [r6, 0x7]
	cmp r0, 0
	beq _0806D8B4
	ldr r0, _0806D8B0
	ldr r0, [r0]
	ldrb r0, [r0, 0x2]
	cmp r0, 0
	beq _0806D8B6
	adds r0, r7, 0
	bl sub_806A458
	lsls r0, 24
	cmp r0, 0
	bne _0806D8B6
	adds r0, r7, 0
	mov r1, r9
	bl CanSeeTarget
	lsls r0, 24
	lsrs r0, 24
	negs r1, r0
	orrs r1, r0
	lsrs r4, r1, 31
	b _0806D8B6
	.align 2, 0
_0806D8B0: .4byte gGameOptionsRef
_0806D8B4:
	movs r4, 0
_0806D8B6:
	adds r0, r6, 0
	adds r0, 0xE8
	ldrb r0, [r0]
	subs r0, 0x1
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bhi _0806D8C8
	movs r4, 0
_0806D8C8:
	cmp r4, 0
	beq _0806D8E0
	ldr r4, [r7, 0x70]
	adds r0, r7, 0x4
	mov r1, r9
	adds r1, 0x4
	bl GetDirectionTowardsPosition
	movs r1, 0x7
	ands r0, r1
	adds r4, 0x46
	strb r0, [r4]
_0806D8E0:
	adds r0, r7, 0
	bl TargetTileInFront
_0806D8E6:
	ldr r0, [r7, 0x70]
	adds r0, 0x46
	ldrb r2, [r0]
	adds r0, r7, 0
	movs r1, 0x6
	bl sub_806CDD4
	adds r0, r7, 0
	adds r1, r5, 0
	bl sub_80420E8
	movs r3, 0x1
	str r3, [sp, 0x54]
_0806D900:
	movs r0, 0xE
	ldrsh r4, [r6, r0]
	ldr r1, [r5]
	cmp r4, r1
	ble _0806D910
	ldrh r0, [r6, 0xE]
	subs r0, r1
	b _0806D912
_0806D910:
	movs r0, 0
_0806D912:
	strh r0, [r6, 0xE]
	adds r0, r6, 0
	adds r0, 0xC4
	ldrb r0, [r0]
	cmp r0, 0x9
	bne _0806D93C
	movs r1, 0xE
	ldrsh r0, [r6, r1]
	cmp r0, 0
	bne _0806D958
	movs r0, 0x1
	strh r0, [r6, 0xE]
	ldr r0, _0806D938
	ldr r2, [r0]
	mov r0, r9
	adds r1, r7, 0
	bl sub_80522F4
	b _0806D958
	.align 2, 0
_0806D938: .4byte gUnknown_8100548
_0806D93C:
	ldr r2, [sp, 0x4C]
	cmp r2, 0x1
	bne _0806D958
	movs r3, 0xE
	ldrsh r0, [r6, r3]
	cmp r0, 0
	bne _0806D958
	strh r2, [r6, 0xE]
	ldr r0, _0806D9C8
	ldr r2, [r0]
	mov r0, r9
	adds r1, r7, 0
	bl sub_80522F4
_0806D958:
	movs r1, 0xE
	ldrsh r0, [r6, r1]
	subs r4, r0
	cmp r4, 0
	bge _0806D964
	movs r4, 0
_0806D964:
	ldr r2, [sp, 0x54]
	cmp r2, 0
	bne _0806D970
	mov r3, r8
	cmp r3, 0
	beq _0806D978
_0806D970:
	movs r0, 0xA
	movs r1, 0x18
	bl sub_803E708
_0806D978:
	movs r1, 0xE
	ldrsh r0, [r6, r1]
	cmp r0, 0
	beq _0806D9D4
	ldr r2, [sp, 0x54]
	cmp r2, 0
	beq _0806D98E
	adds r0, r7, 0
	movs r1, 0x8
	bl sub_806CE68
_0806D98E:
	adds r0, r7, 0
	movs r1, 0x10
	bl HasHeldItem
	lsls r0, 24
	cmp r0, 0
	beq _0806D9B2
	cmp r4, 0
	ble _0806D9B2
	ldr r1, [r5]
	ldr r0, _0806D9CC
	cmp r1, r0
	beq _0806D9B2
	mov r0, r9
	adds r1, r7, 0
	adds r2, r4, 0
	bl sub_8071D4C
_0806D9B2:
	mov r3, r8
	cmp r3, 0
	bne _0806D9BA
	b _0806D608
_0806D9BA:
	ldrh r1, [r3, 0x4]
	ldr r0, _0806D9D0
	ands r0, r1
	strh r0, [r3, 0x4]
	bl sub_8049ED4
	b _0806D608
	.align 2, 0
_0806D9C8: .4byte gUnknown_810056C
_0806D9CC: .4byte 0x0000270f
_0806D9D0: .4byte 0x0000fffb
_0806D9D4:
	adds r0, r6, 0
	adds r0, 0xE4
	ldrb r0, [r0]
	cmp r0, 0x2
	bne _0806D9E6
	mov r0, r9
	adds r1, r7, 0
	bl SendTransformEndMessage
_0806D9E6:
	mov r0, r8
	cmp r0, 0
	beq _0806DA18
	movs r0, 0x14
	movs r1, 0x18
	bl sub_803E708
	adds r1, r7, 0
	adds r1, 0x22
	movs r0, 0x2
	strb r0, [r1]
	movs r0, 0xA
	movs r1, 0x18
	bl sub_803E708
	mov r2, r8
	ldrh r1, [r2, 0x4]
	ldr r0, _0806DA14
	ands r0, r1
	strh r0, [r2, 0x4]
	bl sub_8049ED4
	b _0806DA2E
	.align 2, 0
_0806DA14: .4byte 0x0000fffb
_0806DA18:
	ldr r3, [sp, 0x54]
	cmp r3, 0
	beq _0806DA2E
	adds r1, r7, 0
	adds r1, 0x22
	movs r0, 0x1
	strb r0, [r1]
	movs r0, 0x1E
	movs r1, 0x18
	bl sub_803E708
_0806DA2E:
	movs r0, 0x1
	mov r8, r0
	mov r0, r9
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	beq _0806DA50
	mov r0, r9
	bl GetEntityType
	cmp r0, 0x1
	bne _0806DA50
	cmp r9, r7
	beq _0806DA50
	movs r1, 0
	mov r8, r1
_0806DA50:
	movs r2, 0xA6
	lsls r2, 1
	adds r1, r6, r2
	movs r0, 0
	strb r0, [r1]
	ldr r4, _0806DA88
	adds r0, r4, 0
	mov r1, r9
	movs r2, 0
	bl SetMessageArgument
	adds r4, 0x50
	adds r0, r4, 0
	adds r1, r7, 0
	movs r2, 0
	bl SetMessageArgument
	ldr r0, [r5, 0x4]
	subs r0, 0x13
	cmp r0, 0x1
	bhi _0806DA9C
	ldrb r0, [r6, 0x6]
	cmp r0, 0
	beq _0806DA90
	ldr r0, _0806DA8C
	ldr r2, [r0]
	b _0806DAC2
	.align 2, 0
_0806DA88: .4byte gAvailablePokemonNames
_0806DA8C: .4byte gUnknown_80F9E44
_0806DA90:
	ldr r0, _0806DA98
	ldr r1, [r0]
	b _0806DB86
	.align 2, 0
_0806DA98: .4byte gUnknown_80F9E44
_0806DA9C:
	ldrb r0, [r6, 0x6]
	cmp r0, 0
	beq _0806DAD0
	adds r0, r6, 0
	adds r0, 0xA4
	ldrb r0, [r0]
	cmp r0, 0x1
	bne _0806DAB8
	ldr r0, _0806DAB4
	mov r3, r8
	lsls r1, r3, 2
	b _0806DB82
	.align 2, 0
_0806DAB4: .4byte gUnknown_80F9DF0
_0806DAB8:
	ldr r0, _0806DACC
	mov r2, r8
	lsls r1, r2, 2
	adds r1, r0
	ldr r2, [r1]
_0806DAC2:
	mov r0, r9
	adds r1, r7, 0
	bl sub_80522F4
	b _0806DBA4
	.align 2, 0
_0806DACC: .4byte gUnknown_80F9CC0
_0806DAD0:
	ldr r2, _0806DB04
	ldrb r1, [r6, 0xA]
	movs r0, 0x64
	muls r0, r1
	ldr r3, _0806DB08
	adds r0, r3
	ldr r1, [r2]
	adds r3, r1, r0
	ldrb r0, [r6, 0x7]
	cmp r0, 0
	bne _0806DB00
	adds r0, r6, 0
	adds r0, 0x40
	ldrb r1, [r0]
	adds r2, r0, 0
	cmp r1, 0x41
	bne _0806DB18
	ldr r0, _0806DB0C
	ldr r0, [r0]
	ldr r1, _0806DB10
	adds r0, r1
	ldrb r0, [r0]
	cmp r0, 0
	bne _0806DB18
_0806DB00:
	ldr r0, _0806DB14
	b _0806DB7E
	.align 2, 0
_0806DB04: .4byte gRecruitedPokemonRef
_0806DB08: .4byte 0x00008df8
_0806DB0C: .4byte gDungeon
_0806DB10: .4byte 0x0000065c
_0806DB14: .4byte gUnknown_80F9CEC
_0806DB18:
	ldrb r0, [r2]
	cmp r0, 0x4A
	beq _0806DB22
	cmp r0, 0x47
	bne _0806DB26
_0806DB22:
	movs r0, 0x1
	b _0806DB28
_0806DB26:
	movs r0, 0
_0806DB28:
	cmp r0, 0
	beq _0806DB38
	ldr r0, _0806DB34
	mov r3, r8
	lsls r1, r3, 2
	b _0806DB82
	.align 2, 0
_0806DB34: .4byte gUnknown_80F9DAC
_0806DB38:
	adds r0, r6, 0
	adds r0, 0xA4
	ldrb r0, [r0]
	cmp r0, 0x1
	bne _0806DB4C
	ldr r0, _0806DB48
	b _0806DB7E
	.align 2, 0
_0806DB48: .4byte gUnknown_80F9DF0
_0806DB4C:
	movs r1, 0xA
	ldrsh r0, [r3, r1]
	bl sub_806A58C
	lsls r0, 24
	cmp r0, 0
	beq _0806DB94
	ldr r0, _0806DB70
	ldr r0, [r0]
	ldr r2, _0806DB74
	adds r0, r2
	ldrb r0, [r0]
	cmp r0, 0
	beq _0806DB7C
	ldr r0, _0806DB78
	mov r3, r8
	lsls r1, r3, 2
	b _0806DB82
	.align 2, 0
_0806DB70: .4byte gDungeon
_0806DB74: .4byte 0x0000065d
_0806DB78: .4byte gUnknown_80F9D8C
_0806DB7C:
	ldr r0, _0806DB90
_0806DB7E:
	mov r2, r8
	lsls r1, r2, 2
_0806DB82:
	adds r1, r0
	ldr r1, [r1]
_0806DB86:
	mov r0, r9
	bl sub_805239C
	b _0806DBA4
	.align 2, 0
_0806DB90: .4byte gUnknown_80F9D84
_0806DB94:
	ldr r0, _0806DC4C
	mov r3, r8
	lsls r1, r3, 2
	adds r1, r0
	ldr r1, [r1]
	mov r0, r9
	bl sub_805239C
_0806DBA4:
	mov r1, r10
	ldrb r0, [r1]
	subs r0, 0x3
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bhi _0806DBBC
	adds r0, r6, 0
	adds r0, 0x9C
	ldr r0, [r0]
	bl sub_8076CB4
_0806DBBC:
	adds r1, r6, 0
	adds r1, 0x60
	ldrb r3, [r1]
	movs r2, 0x1
	mov r8, r2
	mov r0, r8
	ands r0, r3
	adds r5, r1, 0
	cmp r0, 0
	beq _0806DC5C
	movs r0, 0x8
	ands r0, r3
	cmp r0, 0
	bne _0806DC5C
	movs r0, 0x2
	ands r0, r3
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0
	bne _0806DC5C
	ldrb r0, [r5, 0x2]
	cmp r0, 0xD2
	bne _0806DC5C
	adds r0, r7, 0
	bl sub_8042148
	adds r0, r7, 0
	adds r0, 0x22
	strb r4, [r0]
	ldrh r0, [r6, 0x10]
	movs r2, 0
	strh r0, [r6, 0xE]
	movs r3, 0xAC
	lsls r3, 1
	adds r0, r6, r3
	strb r2, [r0]
	movs r1, 0xA6
	lsls r1, 1
	adds r0, r6, r1
	mov r3, r8
	strb r3, [r0]
	movs r0, 0x9E
	lsls r0, 1
	adds r1, r6, r0
	movs r3, 0xA0
	lsls r3, 1
	adds r0, r6, r3
	ldr r0, [r0]
	str r0, [r1]
	ldrb r0, [r6, 0x7]
	cmp r0, 0
	beq _0806DC36
	ldr r0, _0806DC50
	ldr r1, [r0]
	ldr r3, _0806DC54
	adds r1, r3
	strb r2, [r1]
	ldr r0, [r0]
	ldr r1, _0806DC58
	adds r0, r1
	strb r2, [r0]
_0806DC36:
	strb r2, [r5, 0x2]
	strb r2, [r5, 0x1]
	strb r2, [r5]
	adds r0, r6, 0
	adds r0, 0xC8
	ldrb r0, [r0]
	cmp r0, 0x3
	bne _0806DC48
	b _0806DEC8
_0806DC48:
	b _0806DEE4
	.align 2, 0
_0806DC4C: .4byte gUnknown_80F9D28
_0806DC50: .4byte gDungeon
_0806DC54: .4byte 0x00000679
_0806DC58: .4byte 0x00000676
_0806DC5C:
	ldrb r0, [r6, 0x7]
	cmp r0, 0
	bne _0806DC64
	b _0806DDFC
_0806DC64:
	mov r10, r5
	ldrb r1, [r5]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	bne _0806DC72
	b _0806DDFC
_0806DC72:
	movs r0, 0x8
	ands r0, r1
	cmp r0, 0
	beq _0806DC7C
	b _0806DDFC
_0806DC7C:
	ldrb r0, [r5, 0x2]
	cmp r0, 0xD8
	beq _0806DC84
	b _0806DDFC
_0806DC84:
	movs r4, 0
_0806DC86:
	ldr r0, _0806DD80
	ldr r0, [r0]
	lsls r1, r4, 2
	ldr r2, _0806DD84
	adds r0, r2
	adds r0, r1
	ldr r0, [r0]
	mov r8, r0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	beq _0806DCDE
	cmp r8, r7
	beq _0806DCDE
	adds r0, r7, 0
	mov r1, r8
	bl CanSeeTarget
	lsls r0, 24
	cmp r0, 0
	beq _0806DCDE
	mov r3, r8
	movs r0, 0x4
	ldrsh r1, [r3, r0]
	movs r2, 0x4
	ldrsh r0, [r7, r2]
	subs r1, r0
	cmp r1, 0
	bge _0806DCC4
	negs r1, r1
_0806DCC4:
	cmp r1, 0x1
	bgt _0806DCDE
	mov r3, r8
	movs r0, 0x6
	ldrsh r1, [r3, r0]
	movs r2, 0x6
	ldrsh r0, [r7, r2]
	subs r1, r0
	cmp r1, 0
	bge _0806DCDA
	negs r1, r1
_0806DCDA:
	cmp r1, 0x1
	ble _0806DCE4
_0806DCDE:
	adds r4, 0x1
	cmp r4, 0x3
	ble _0806DC86
_0806DCE4:
	cmp r4, 0x4
	bne _0806DCEA
	b _0806DDFC
_0806DCEA:
	adds r0, r7, 0
	bl sub_8042148
	mov r3, r8
	ldr r4, [r3, 0x4]
	ldr r1, _0806DD88
	mov r0, r8
	adds r2, r7, 0
	bl sub_8068FE0
	lsls r1, r4, 16
	asrs r1, 16
	asrs r4, 16
	adds r0, r7, 0
	adds r2, r4, 0
	movs r3, 0x1
	bl sub_80694C0
	adds r0, r7, 0
	movs r1, 0
	bl sub_804535C
	adds r1, r7, 0
	adds r1, 0x22
	movs r0, 0
	strb r0, [r1]
	ldrh r0, [r6, 0x10]
	movs r4, 0
	strh r0, [r6, 0xE]
	adds r0, r7, 0
	bl sub_8042A24
	movs r1, 0xAC
	lsls r1, 1
	adds r0, r6, r1
	strb r4, [r0]
	movs r2, 0xA6
	lsls r2, 1
	adds r1, r6, r2
	movs r0, 0x1
	strb r0, [r1]
	movs r3, 0x9E
	lsls r3, 1
	adds r1, r6, r3
	subs r2, 0xC
	adds r0, r6, r2
	ldr r0, [r0]
	str r0, [r1]
	ldrb r0, [r6, 0x7]
	cmp r0, 0
	beq _0806DD62
	ldr r0, _0806DD80
	ldr r1, [r0]
	ldr r3, _0806DD8C
	adds r1, r3
	strb r4, [r1]
	ldr r0, [r0]
	ldr r1, _0806DD90
	adds r0, r1
	strb r4, [r0]
_0806DD62:
	mov r2, r10
	strb r4, [r2, 0x2]
	strb r4, [r2, 0x1]
	strb r4, [r2]
	adds r0, r6, 0
	adds r0, 0xC8
	ldrb r0, [r0]
	cmp r0, 0x3
	bne _0806DD94
	mov r0, r9
	adds r1, r7, 0
	movs r2, 0x3
	bl SendWaitingEndMessage
	b _0806DDA2
	.align 2, 0
_0806DD80: .4byte gDungeon
_0806DD84: .4byte 0x0001357c
_0806DD88: .4byte 0x00000221
_0806DD8C: .4byte 0x00000679
_0806DD90: .4byte 0x00000676
_0806DD94:
	cmp r0, 0x2
	bne _0806DDA2
	mov r0, r9
	adds r1, r7, 0
	movs r2, 0x2
	bl SendWaitingEndMessage
_0806DDA2:
	adds r0, r7, 0
	bl sub_8078084
	adds r0, r6, 0
	movs r1, 0
	bl sub_806BFC0
	bl sub_800DBBC
	adds r0, r7, 0
	bl sub_806A390
	adds r0, r7, 0
	bl sub_806CEBC
	adds r1, r0, 0
	lsls r1, 24
	lsrs r1, 24
	adds r0, r7, 0
	bl sub_806CCB4
	adds r0, r7, 0
	bl EntityUpdateStatusSprites
	ldr r4, _0806DDF0
	adds r0, r4, 0
	adds r1, r7, 0
	movs r2, 0
	bl SetMessageArgument
	adds r4, 0x50
	adds r0, r4, 0
	mov r1, r8
	movs r2, 0
	bl SetMessageArgument
	ldr r0, _0806DDF4
	b _0806DF2E
	.align 2, 0
_0806DDF0: .4byte gAvailablePokemonNames
_0806DDF4: .4byte gUnknown_80FD484
_0806DDF8:
	mov r4, r8
	b _0806DE64
_0806DDFC:
	adds r0, r7, 0
	movs r1, 0x16
	bl IQSkillIsEnabled
	lsls r0, 24
	cmp r0, 0
	bne _0806DE0C
	b _0806DF48
_0806DE0C:
	movs r4, 0
	ldrb r1, [r5]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _0806DE28
	movs r0, 0x8
	ands r0, r1
	cmp r0, 0
	bne _0806DE28
	ldrb r0, [r5, 0x2]
	cmp r0, 0x3A
	bne _0806DE28
	adds r4, r5, 0
_0806DE28:
	cmp r4, 0
	bne _0806DE68
	ldrb r0, [r6, 0x6]
	cmp r0, 0
	bne _0806DE64
	movs r3, 0
	ldr r0, _0806DED4
	ldr r2, [r0]
	mov r12, r2
	movs r0, 0x1
	mov r10, r0
_0806DE3E:
	lsls r0, r3, 2
	add r0, r12
	mov r8, r0
	ldrb r1, [r2]
	mov r0, r10
	ands r0, r1
	cmp r0, 0
	beq _0806DE5C
	movs r0, 0x8
	ands r0, r1
	cmp r0, 0
	bne _0806DE5C
	ldrb r0, [r2, 0x2]
	cmp r0, 0x3A
	beq _0806DDF8
_0806DE5C:
	adds r2, 0x4
	adds r3, 0x1
	cmp r3, 0x13
	ble _0806DE3E
_0806DE64:
	cmp r4, 0
	beq _0806DF48
_0806DE68:
	adds r0, r7, 0
	bl sub_8042148
	adds r0, r4, 0
	movs r1, 0x46
	movs r2, 0x2
	bl sub_8045C28
	adds r1, r7, 0
	adds r1, 0x22
	movs r0, 0
	strb r0, [r1]
	ldrh r0, [r6, 0x10]
	movs r2, 0
	strh r0, [r6, 0xE]
	movs r1, 0xAC
	lsls r1, 1
	adds r0, r6, r1
	strb r2, [r0]
	movs r3, 0xA6
	lsls r3, 1
	adds r1, r6, r3
	movs r0, 0x1
	strb r0, [r1]
	movs r0, 0x9E
	lsls r0, 1
	adds r1, r6, r0
	subs r3, 0xC
	adds r0, r6, r3
	ldr r0, [r0]
	str r0, [r1]
	ldrb r0, [r6, 0x7]
	cmp r0, 0
	beq _0806DEBE
	ldr r0, _0806DED8
	ldr r1, [r0]
	ldr r3, _0806DEDC
	adds r1, r3
	strb r2, [r1]
	ldr r0, [r0]
	ldr r1, _0806DEE0
	adds r0, r1
	strb r2, [r0]
_0806DEBE:
	adds r0, r6, 0
	adds r0, 0xC8
	ldrb r0, [r0]
	cmp r0, 0x3
	bne _0806DEE4
_0806DEC8:
	mov r0, r9
	adds r1, r7, 0
	movs r2, 0x3
	bl SendWaitingEndMessage
	b _0806DEF2
	.align 2, 0
_0806DED4: .4byte gTeamInventoryRef
_0806DED8: .4byte gDungeon
_0806DEDC: .4byte 0x00000679
_0806DEE0: .4byte 0x00000676
_0806DEE4:
	cmp r0, 0x2
	bne _0806DEF2
	mov r0, r9
	adds r1, r7, 0
	movs r2, 0x2
	bl SendWaitingEndMessage
_0806DEF2:
	adds r0, r7, 0
	bl sub_8078084
	adds r0, r6, 0
	movs r1, 0
	bl sub_806BFC0
	bl sub_800DBBC
	adds r0, r7, 0
	bl sub_806A390
	adds r0, r7, 0
	bl sub_806CEBC
	adds r1, r0, 0
	lsls r1, 24
	lsrs r1, 24
	adds r0, r7, 0
	bl sub_806CCB4
	adds r0, r7, 0
	bl EntityUpdateStatusSprites
	ldr r0, _0806DF40
	adds r1, r7, 0
	movs r2, 0
	bl SetMessageArgument
	ldr r0, _0806DF44
_0806DF2E:
	ldr r1, [r0]
	mov r0, r9
	bl sub_805239C
	adds r0, r7, 0
	bl sub_806F63C
	bl _0806D608
	.align 2, 0
_0806DF40: .4byte gUnknown_202DFE8
_0806DF44: .4byte gUnknown_80FD46C
_0806DF48:
	ldrb r4, [r6, 0x7]
	cmp r4, 0
	bne _0806DF68
	ldrb r1, [r5]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _0806DF68
	adds r1, r7, 0x4
	adds r0, r7, 0
	adds r2, r5, 0
	bl sub_80464C8
	strb r4, [r5, 0x2]
	strb r4, [r5, 0x1]
	strb r4, [r5]
_0806DF68:
	adds r0, r6, 0
	adds r0, 0xF7
	ldrb r0, [r0]
	cmp r0, 0
	beq _0806DF7E
	ldr r0, _0806E02C
	ldr r0, [r0]
	ldr r2, _0806E030
	adds r0, r2
	ldr r1, _0806E034
	strh r1, [r0]
_0806DF7E:
	movs r3, 0
	mov r10, r3
	mov r0, r9
	bl GetEntityType
	cmp r0, 0x1
	bne _0806E066
	mov r0, r9
	ldr r4, [r0, 0x70]
	movs r1, 0x2
	ldrsh r0, [r6, r1]
	ldrb r1, [r6, 0x9]
	bl CalculateEXPGain
	adds r5, r0, 0
	adds r0, r6, 0
	adds r0, 0xFB
	ldrb r0, [r0]
	cmp r0, 0
	beq _0806DFAE
	cmp r0, 0x2
	bne _0806DFB4
	lsls r0, r5, 1
	adds r5, r0, r5
_0806DFAE:
	lsrs r0, r5, 31
	adds r0, r5, r0
	asrs r5, r0, 1
_0806DFB4:
	cmp r5, 0
	bne _0806DFBA
	movs r5, 0x1
_0806DFBA:
	ldrb r0, [r4, 0x7]
	cmp r0, 0
	beq _0806DFC8
	movs r2, 0x2
	ldrsh r0, [r6, r2]
	bl sub_80980B4
_0806DFC8:
	adds r0, r6, 0
	adds r0, 0xF4
	ldrb r0, [r0]
	cmp r0, 0
	beq _0806DFDA
	ldr r3, _0806E038
	adds r1, r4, r3
	movs r0, 0x1
	strb r0, [r1]
_0806DFDA:
	ldr r0, [sp, 0x78]
	cmp r0, 0x1
	bne _0806E066
	ldrb r0, [r4, 0x6]
	cmp r0, 0
	bne _0806E040
	ldrb r0, [r6, 0x6]
	cmp r0, 0
	beq _0806E066
	mov r0, r9
	mov r1, r9
	adds r2, r5, 0
	bl sub_8071D4C
	movs r6, 0
_0806DFF8:
	ldr r0, _0806E02C
	ldr r0, [r0]
	lsls r1, r6, 2
	ldr r2, _0806E03C
	adds r0, r2
	adds r0, r1
	ldr r4, [r0]
	adds r0, r4, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	beq _0806E020
	cmp r4, r9
	beq _0806E020
	mov r0, r9
	adds r1, r4, 0
	adds r2, r5, 0
	bl sub_8071D4C
_0806E020:
	adds r6, 0x1
	cmp r6, 0x3
	ble _0806DFF8
	movs r3, 0x1
	mov r10, r3
	b _0806E066
	.align 2, 0
_0806E02C: .4byte gDungeon
_0806E030: .4byte 0x0000066a
_0806E034: .4byte 0x000003e7
_0806E038: .4byte 0x0000014b
_0806E03C: .4byte 0x0001357c
_0806E040:
	ldr r5, _0806E0BC
	ldr r0, [r5]
	ldr r1, _0806E0C0
	adds r0, r1
	ldrb r0, [r0]
	bl DoEnemiesEvolveWhenKOed
	lsls r0, 24
	cmp r0, 0
	beq _0806E066
	ldr r2, _0806E0C4
	adds r0, r4, r2
	add r3, sp, 0x78
	ldrb r3, [r3]
	strb r3, [r0]
	ldr r0, [r5]
	add r1, sp, 0x78
	ldrb r1, [r1]
	strb r1, [r0, 0xD]
_0806E066:
	mov r0, r9
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	beq _0806E08A
	mov r0, r9
	bl GetEntityType
	cmp r0, 0x1
	bne _0806E08A
	mov r2, r9
	ldr r0, [r2, 0x70]
	ldrb r0, [r0, 0x7]
	cmp r0, 0
	bne _0806E08A
	movs r3, 0
	mov r10, r3
_0806E08A:
	mov r0, r10
	cmp r0, 0
	beq _0806E0E4
	add r0, sp, 0x4
	adds r1, r7, 0
	bl sub_8069D4C
	mov r0, r9
	adds r1, r7, 0
	bl sub_806F660
	lsls r0, 24
	cmp r0, 0
	beq _0806E0D8
	mov r0, r9
	adds r1, r7, 0
	add r2, sp, 0x4
	bl sub_806FA5C
	lsls r0, 24
	cmp r0, 0
	bne _0806E0CC
	ldr r1, _0806E0C8
	adds r0, r7, 0
	b _0806E0DC
	.align 2, 0
_0806E0BC: .4byte gDungeon
_0806E0C0: .4byte 0x00000644
_0806E0C4: .4byte 0x00000149
_0806E0C8: .4byte 0x000001f5
_0806E0CC:
	ldr r1, _0806E0D4
	movs r0, 0x1
	strb r0, [r1]
	b _0806E0EE
	.align 2, 0
_0806E0D4: .4byte gUnknown_202F221
_0806E0D8:
	adds r0, r7, 0
	ldr r1, [sp, 0x50]
_0806E0DC:
	mov r2, r9
	bl sub_8068FE0
	b _0806E0EE
_0806E0E4:
	adds r0, r7, 0
	ldr r1, [sp, 0x50]
	mov r2, r9
	bl sub_8068FE0
_0806E0EE:
	movs r0, 0x1
_0806E0F0:
	add sp, 0x58
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_806D528

	.align 2, 0
