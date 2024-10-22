	#include "asm/constants/gba_constants.inc"
  	#include "asm/macros.inc"

  	.syntax unified

  	.text

	thumb_func_start sub_806890C
sub_806890C:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x64
	movs r0, 0
	mov r8, r0
	mov r10, r0
	ldr r6, _08068A60
	add r5, sp, 0x8
_08068922:
	movs r0, 0x58
	mov r1, r10
	muls r1, r0
	adds r0, r1, 0
	ldr r2, [r6]
	adds r7, r2, r0
	ldrh r1, [r7]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _08068A1C
	lsrs r0, r1, 1
	movs r3, 0x1
	ands r0, r3
	cmp r0, 0
	beq _08068A1C
	movs r0, 0x64
	mov r4, r8
	muls r4, r0
	ldr r0, _08068A64
	adds r0, r4
	mov r9, r0
	adds r0, r2, r0
	mov r1, r10
	bl xxx_pokemonstruct_index_to_pokemon2_808DE30
	ldr r0, _08068A68
	ldr r0, [r0]
	ldr r1, _08068A6C
	adds r0, r1
	ldrb r0, [r0]
	bl IsLevelResetTo1
	lsls r0, 24
	cmp r0, 0
	beq _08068A06
	movs r0, 0x80
	lsls r0, 1
	str r0, [sp, 0x60]
	movs r2, 0x8
	ldrsh r1, [r7, r2]
	add r0, sp, 0x60
	str r0, [sp]
	movs r3, 0
	str r3, [sp, 0x4]
	add r0, sp, 0x8
	movs r2, 0
	bl sub_808CFD0
	ldr r0, [r6]
	adds r0, r4
	ldrb r1, [r5, 0x3]
	ldr r2, _08068A70
	adds r0, r2
	strb r1, [r0]
	ldr r1, [r6]
	adds r1, r4
	ldrh r2, [r5, 0x14]
	movs r3, 0x8E
	lsls r3, 8
	adds r0, r1, r3
	strh r2, [r0]
	ldrh r2, [r5, 0x16]
	adds r3, 0x8
	adds r0, r1, r3
	strh r2, [r0]
	ldrh r2, [r5, 0x16]
	adds r3, 0x2
	adds r0, r1, r3
	strh r2, [r0]
	ldrb r0, [r5, 0x18]
	ldr r2, _08068A74
	adds r1, r2
	strb r0, [r1]
	ldr r0, [r6]
	adds r0, r4
	ldrb r1, [r5, 0x19]
	adds r3, 0x3
	adds r0, r3
	strb r1, [r0]
	ldr r0, [r6]
	adds r0, r4
	ldrb r1, [r5, 0x1A]
	adds r2, 0x2
	adds r0, r2
	strb r1, [r0]
	ldr r0, [r6]
	adds r0, r4
	ldrb r1, [r5, 0x1B]
	adds r3, 0x2
	adds r0, r3
	strb r1, [r0]
	ldr r2, [r6]
	ldr r1, _08068A78
	adds r0, r2, r1
	adds r0, r4
	ldr r1, [sp, 0x24]
	str r1, [r0]
	adds r2, r4
	adds r3, 0x35
	adds r1, r2, r3
	ldr r0, [sp, 0x28]
	str r0, [r1]
	add r0, sp, 0x2C
	ldrb r0, [r0]
	ldr r1, _08068A7C
	adds r2, r1
	strb r0, [r2]
	ldr r0, [r6]
	add r0, r9
	adds r0, 0x1C
	add r1, sp, 0x34
	bl CopyAndResetMoves
_08068A06:
	ldr r0, [r6]
	adds r0, r4
	ldr r2, _08068A80
	adds r0, r2
	mov r3, r8
	strh r3, [r0]
	movs r0, 0x1
	add r8, r0
	mov r1, r8
	cmp r1, 0x4
	beq _08068A2A
_08068A1C:
	movs r2, 0x1
	add r10, r2
	movs r0, 0xCE
	lsls r0, 1
	cmp r10, r0
	bgt _08068A2A
	b _08068922
_08068A2A:
	mov r3, r8
	cmp r3, 0x3
	bgt _08068A50
	ldr r4, _08068A60
	ldr r3, _08068A64
	movs r2, 0
	movs r0, 0x64
	mov r1, r8
	muls r1, r0
_08068A3C:
	ldr r0, [r4]
	adds r0, r1
	adds r0, r3
	strh r2, [r0]
	adds r1, 0x64
	movs r0, 0x1
	add r8, r0
	mov r0, r8
	cmp r0, 0x3
	ble _08068A3C
_08068A50:
	add sp, 0x64
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_08068A60: .4byte gRecruitedPokemonRef
_08068A64: .4byte 0x00008df8
_08068A68: .4byte gDungeon
_08068A6C: .4byte 0x00000644
_08068A70: .4byte 0x00008dfb
_08068A74: .4byte 0x00008e0c
_08068A78: .4byte 0x00008e10
_08068A7C: .4byte 0x00008e48
_08068A80: .4byte 0x00008e04
	thumb_func_end sub_806890C

	thumb_func_start sub_8068A84
sub_8068A84:
	push {r4-r7,lr}
	adds r6, r0, 0
	movs r4, 0
	movs r5, 0
	ldr r7, _08068AE0
_08068A8E:
	movs r0, 0x64
	muls r0, r5
	ldr r1, _08068AE4
	adds r0, r1
	ldr r1, [r7]
	adds r2, r1, r0
	ldrb r1, [r2]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _08068AB2
	movs r1, 0xE
	ldrsh r0, [r2, r1]
	bl GetBodySize
	lsls r0, 24
	lsrs r0, 24
	adds r4, r0
_08068AB2:
	adds r5, 0x1
	cmp r5, 0x3
	ble _08068A8E
	movs r1, 0x8
	ldrsh r0, [r6, r1]
	bl GetBodySize
	lsls r0, 24
	lsrs r0, 24
	adds r4, r0
	cmp r4, 0x6
	ble _08068B04
	ldr r0, _08068AE8
	adds r1, r6, 0
	movs r2, 0
	bl PrintColoredPokeNameToBuffer
	ldrb r0, [r6, 0x4]
	cmp r0, 0x4A
	bne _08068AF0
	ldr r0, _08068AEC
	b _08068BB2
	.align 2, 0
_08068AE0: .4byte gRecruitedPokemonRef
_08068AE4: .4byte 0x00008df8
_08068AE8: .4byte gAvailablePokemonNames
_08068AEC: .4byte gUnknown_80FE0F4
_08068AF0:
	cmp r0, 0x47
	bne _08068AFC
	ldr r0, _08068AF8
	b _08068BB2
	.align 2, 0
_08068AF8: .4byte gUnknown_80FE0F8
_08068AFC:
	ldr r0, _08068B00
	b _08068BB2
	.align 2, 0
_08068B00: .4byte gUnknown_80FE0AC
_08068B04:
	movs r5, 0
	ldr r2, _08068B6C
_08068B08:
	movs r0, 0x64
	muls r0, r5
	ldr r1, _08068B70
	adds r0, r1
	ldr r1, [r2]
	adds r4, r1, r0
	ldrb r1, [r4]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	bne _08068B80
	adds r0, r4, 0
	adds r1, r6, 0
	ldr r2, _08068B74
	bl xxx_pokemonstruct_to_pokemon2_808DE50
	ldrh r0, [r4]
	movs r1, 0x1
	movs r2, 0
	orrs r1, r0
	strh r1, [r4]
	movs r1, 0x8
	ldrsh r0, [r4, r1]
	cmp r0, 0x19
	bgt _08068B3E
	movs r0, 0x1A
	strh r0, [r4, 0x8]
_08068B3E:
	ldrh r0, [r4]
	movs r1, 0x2
	orrs r0, r1
	strh r0, [r4]
	strh r5, [r4, 0xC]
	adds r0, r4, 0
	adds r0, 0x40
	strb r2, [r0, 0x2]
	strb r2, [r0, 0x1]
	strb r2, [r0]
	ldr r0, _08068B78
	adds r1, r6, 0
	movs r2, 0x6
	bl PrintColoredPokeNameToBuffer
	ldrb r0, [r6, 0x4]
	cmp r0, 0x4A
	beq _08068BB0
	cmp r0, 0x47
	beq _08068BD0
	ldr r0, _08068B7C
	b _08068BB2
	.align 2, 0
_08068B6C: .4byte gRecruitedPokemonRef
_08068B70: .4byte 0x00008df8
_08068B74: .4byte 0x000055aa
_08068B78: .4byte gAvailablePokemonNames
_08068B7C: .4byte gUnknown_80FE134
_08068B80:
	adds r5, 0x1
	cmp r5, 0x3
	ble _08068B08
	ldr r0, _08068B9C
	adds r1, r6, 0
	movs r2, 0x6
	bl PrintColoredPokeNameToBuffer
	ldrb r0, [r6, 0x4]
	cmp r0, 0x4A
	bne _08068BA4
	ldr r0, _08068BA0
	b _08068BB2
	.align 2, 0
_08068B9C: .4byte gAvailablePokemonNames
_08068BA0: .4byte gUnknown_80FE0F4
_08068BA4:
	cmp r0, 0x47
	bne _08068BC4
	ldr r0, _08068BAC
	b _08068BB2
	.align 2, 0
_08068BAC: .4byte gUnknown_80FE0F8
_08068BB0:
	ldr r0, _08068BC0
_08068BB2:
	ldr r1, [r0]
	movs r0, 0
	movs r2, 0x1
	bl DisplayDungeonMessage
	b _08068BD0
	.align 2, 0
_08068BC0: .4byte gUnknown_80FE168
_08068BC4:
	ldr r0, _08068BD8
	ldr r1, [r0]
	movs r0, 0
	movs r2, 0x1
	bl DisplayDungeonMessage
_08068BD0:
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_08068BD8: .4byte gUnknown_80FE0AC
	thumb_func_end sub_8068A84

	thumb_func_start sub_8068BDC
sub_8068BDC:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	ldr r4, _08068CC4
	add sp, r4
	lsls r0, 24
	lsrs r0, 24
	str r0, [sp, 0x220]
	movs r1, 0
	mov r0, sp
	adds r0, 0x39
_08068BF6:
	strb r1, [r0]
	subs r0, 0x1
	cmp r0, sp
	bge _08068BF6
	movs r6, 0
	ldr r0, _08068CC8
	mov r8, r0
	movs r7, 0x1
_08068C06:
	movs r0, 0x64
	muls r0, r6
	ldr r1, _08068CCC
	adds r0, r1
	mov r2, r8
	ldr r1, [r2]
	adds r4, r1, r0
	ldrb r1, [r4]
	adds r0, r7, 0
	ands r0, r1
	cmp r0, 0
	beq _08068C50
	movs r3, 0xA
	ldrsh r0, [r4, r3]
	bl sub_806A564
	lsls r0, 24
	lsrs r5, r0, 24
	cmp r5, 0
	bne _08068C50
	adds r4, 0x40
	ldrb r1, [r4]
	adds r0, r7, 0
	ands r0, r1
	cmp r0, 0
	beq _08068C50
	ldrb r0, [r4, 0x2]
	cmp r0, 0x69
	bne _08068C50
	adds r0, r4, 0
	bl GetMoneyValue
	bl AddToTeamMoney
	strb r5, [r4, 0x2]
	strb r5, [r4, 0x1]
	strb r5, [r4]
_08068C50:
	adds r6, 0x1
	cmp r6, 0x3
	ble _08068C06
	movs r6, 0
	movs r5, 0x1
_08068C5A:
	ldr r1, _08068CC8
	movs r0, 0x64
	muls r0, r6
	ldr r2, _08068CCC
	adds r0, r2
	ldr r1, [r1]
	adds r4, r1, r0
	ldrb r1, [r4]
	adds r0, r5, 0
	ands r0, r1
	cmp r0, 0
	beq _08068CFE
	movs r3, 0xA
	ldrsh r0, [r4, r3]
	bl sub_806A564
	lsls r0, 24
	cmp r0, 0
	bne _08068CFE
	ldr r1, _08068CD0
	adds r0, r1, 0
	ldrh r2, [r4, 0xE]
	adds r0, r2
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0x2
	bhi _08068C96
	movs r0, 0xBC
	lsls r0, 1
	strh r0, [r4, 0xE]
_08068C96:
	movs r3, 0xA
	ldrsh r0, [r4, r3]
	bl sub_806A58C
	lsls r0, 24
	cmp r0, 0
	beq _08068CE8
	ldr r0, _08068CD4
	ldr r0, [r0]
	ldr r1, _08068CD8
	adds r0, r1
	ldrb r0, [r0]
	bl IsLevelResetTo1
	lsls r0, 24
	cmp r0, 0
	beq _08068CDC
	movs r2, 0xA
	ldrsh r0, [r4, r2]
	adds r1, r4, 0
	bl sub_808DFDC
	b _08068CFE
	.align 2, 0
_08068CC4: .4byte 0xfffffdd8
_08068CC8: .4byte gRecruitedPokemonRef
_08068CCC: .4byte 0x00008df8
_08068CD0: .4byte 0xfffffe87
_08068CD4: .4byte gDungeon
_08068CD8: .4byte 0x00000644
_08068CDC:
	movs r3, 0xA
	ldrsh r0, [r4, r3]
	adds r1, r4, 0
	bl xxx_pokemon2_to_pokemonstruct_index_808DF2C
	b _08068CFE
_08068CE8:
	ldr r0, [sp, 0x220]
	cmp r0, 0
	beq _08068CFE
	movs r1, 0xE
	ldrsh r0, [r4, r1]
	bl GetFriendArea
	lsls r0, 24
	lsrs r0, 24
	add r0, sp
	strb r5, [r0]
_08068CFE:
	adds r6, 0x1
	cmp r6, 0x3
	ble _08068C5A
	movs r1, 0
_08068D06:
	lsls r0, r1, 24
	lsrs r0, 24
	mov r8, r0
	mov r0, sp
	add r0, r8
	ldrb r0, [r0]
	adds r1, 0x1
	str r1, [sp, 0x224]
	cmp r0, 0
	bne _08068D1C
	b _08068F08
_08068D1C:
	mov r0, r8
	add r1, sp, 0x1F0
	movs r2, 0x1
	movs r3, 0x1
	bl sub_8092404
	mov r0, r8
	add r1, sp, 0x214
	movs r2, 0
	movs r3, 0
	bl sub_8092638
	movs r7, 0
	add r1, sp, 0x1F0
	ldrh r0, [r1]
	ldr r2, _08068E10
	cmp r0, r2
	beq _08068D60
	ldr r0, _08068E14
	ldr r3, [r0]
	adds r5, r2, 0
	add r2, sp, 0x3C
	movs r4, 0x58
_08068D4A:
	ldrh r0, [r1]
	muls r0, r4
	adds r0, r3, r0
	stm r2!, {r0}
	adds r1, 0x2
	adds r7, 0x1
	cmp r7, 0x14
	bgt _08068D60
	ldrh r0, [r1]
	cmp r0, r5
	bne _08068D4A
_08068D60:
	movs r6, 0
	ldr r2, _08068E14
	mov r10, r2
	movs r3, 0
	mov r9, r3
_08068D6A:
	movs r0, 0x64
	muls r0, r6
	ldr r1, _08068E18
	adds r0, r1
	mov r2, r10
	ldr r1, [r2]
	adds r5, r1, r0
	ldrb r1, [r5]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _08068DD6
	movs r3, 0xA
	ldrsh r0, [r5, r3]
	bl sub_806A5A4
	lsls r0, 24
	cmp r0, 0
	beq _08068DD6
	movs r1, 0xE
	ldrsh r0, [r5, r1]
	bl GetFriendArea
	lsls r0, 24
	lsrs r0, 24
	cmp r0, r8
	bne _08068DD6
	ldr r2, [sp, 0x220]
	cmp r2, 0
	beq _08068DD6
	add r4, sp, 0x3C
	lsls r0, r7, 2
	adds r4, r0
	add r0, sp, 0x90
	movs r1, 0x58
	muls r1, r6
	adds r0, r1
	str r0, [r4]
	adds r1, r5, 0
	bl xxx_pokemon2_to_pokemonstruct_808DF44
	ldr r2, [r4]
	ldrh r0, [r2]
	movs r3, 0x80
	lsls r3, 7
	adds r1, r3, 0
	orrs r0, r1
	strh r0, [r2]
	ldr r0, [r4]
	mov r1, r9
	strb r1, [r0, 0xC]
	ldr r0, [r4]
	strb r1, [r0, 0x10]
	adds r7, 0x1
_08068DD6:
	adds r6, 0x1
	cmp r6, 0x3
	ble _08068D6A
	add r0, sp, 0x214
	movs r2, 0
	ldrsh r0, [r0, r2]
	cmp r7, r0
	bgt _08068E1C
	cmp r7, 0
	bgt _08068DEC
	b _08068F08
_08068DEC:
	add r5, sp, 0x3C
	movs r3, 0x80
	lsls r3, 7
	adds r6, r3, 0
	adds r4, r7, 0
_08068DF6:
	ldr r1, [r5]
	ldrh r0, [r1]
	ands r0, r6
	cmp r0, 0
	beq _08068E06
	adds r0, r1, 0
	bl sub_808D1DC
_08068E06:
	adds r5, 0x4
	subs r4, 0x1
	cmp r4, 0
	bne _08068DF6
	b _08068F08
	.align 2, 0
_08068E10: .4byte 0x0000ffff
_08068E14: .4byte gRecruitedPokemonRef
_08068E18: .4byte 0x00008df8
_08068E1C:
	ldr r0, _08068E78
	mov r1, r8
	movs r2, 0
	bl WriteFriendAreaName
	ldr r0, _08068E7C
	ldr r1, [r0]
	movs r0, 0
	movs r2, 0x1
	bl DisplayDungeonMessage
	add r4, sp, 0x3C
_08068E34:
	add r0, sp, 0x214
	movs r2, 0
	ldrsh r1, [r0, r2]
	subs r1, r7, r1
	mov r0, r8
	adds r2, r7, 0
	adds r3, r4, 0
	bl sub_8067A80
	movs r6, 0
	cmp r6, r7
	bge _08068E8E
	movs r5, 0x80
	lsls r5, 8
	adds r3, r4, 0
_08068E52:
	ldr r2, [r3]
	ldrh r1, [r2]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _08068E86
	adds r0, r5, 0
	ands r0, r1
	cmp r0, 0
	beq _08068E86
	ldrb r0, [r2, 0x4]
	subs r0, 0x44
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bhi _08068E80
	movs r0, 0x1
	b _08068E82
	.align 2, 0
_08068E78: .4byte gFormatItems
_08068E7C: .4byte gUnknown_80FE1A4
_08068E80:
	movs r0, 0
_08068E82:
	cmp r0, 0
	bne _08068E8E
_08068E86:
	adds r3, 0x4
	adds r6, 0x1
	cmp r6, r7
	blt _08068E52
_08068E8E:
	cmp r6, r7
	beq _08068EA2
	ldr r0, _08068F24
	ldr r1, [r0]
	movs r0, 0
	movs r2, 0x1
	bl DisplayDungeonYesNoMessage
	cmp r0, 0x1
	bne _08068E34
_08068EA2:
	cmp r7, 0
	ble _08068ED4
	movs r3, 0x80
	lsls r3, 8
	mov r9, r3
	adds r3, r4, 0
	movs r0, 0x1
	mov r8, r0
	movs r5, 0
	adds r6, r7, 0
_08068EB6:
	ldr r2, [r3]
	ldrh r1, [r2]
	mov r0, r8
	ands r0, r1
	cmp r0, 0
	beq _08068ECC
	mov r0, r9
	ands r0, r1
	cmp r0, 0
	beq _08068ECC
	strh r5, [r2]
_08068ECC:
	adds r3, 0x4
	subs r6, 0x1
	cmp r6, 0
	bne _08068EB6
_08068ED4:
	cmp r7, 0
	ble _08068F08
	movs r1, 0x80
	lsls r1, 7
	adds r5, r1, 0
	adds r6, r7, 0
_08068EE0:
	ldr r2, [r4]
	ldrh r1, [r2]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _08068F00
	adds r0, r1, 0
	ands r0, r5
	cmp r0, 0
	beq _08068F00
	adds r0, r2, 0
	bl sub_808D1DC
	ldr r1, [r4]
	movs r0, 0
	strh r0, [r1]
_08068F00:
	adds r4, 0x4
	subs r6, 0x1
	cmp r6, 0
	bne _08068EE0
_08068F08:
	ldr r1, [sp, 0x224]
	cmp r1, 0x39
	bgt _08068F10
	b _08068D06
_08068F10:
	movs r3, 0x8A
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
_08068F24: .4byte gUnknown_80FE20C
	thumb_func_end sub_8068BDC

	thumb_func_start sub_8068F28
sub_8068F28:
	push {r4-r7,lr}
	movs r6, 0
	ldr r7, _08068F5C
_08068F2E:
	movs r0, 0x64
	muls r0, r6
	ldr r1, _08068F60
	adds r0, r1
	ldr r1, [r7]
	adds r4, r1, r0
	ldrb r1, [r4]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _08068F74
	movs r1, 0xA
	ldrsh r0, [r4, r1]
	bl sub_806A564
	lsls r0, 24
	lsrs r5, r0, 24
	cmp r5, 0
	beq _08068F64
	movs r0, 0
	strh r0, [r4]
	b _08068F74
	.align 2, 0
_08068F5C: .4byte gRecruitedPokemonRef
_08068F60: .4byte 0x00008df8
_08068F64:
	movs r1, 0xA
	ldrsh r0, [r4, r1]
	bl sub_806A538
	lsls r0, 24
	cmp r0, 0
	beq _08068F74
	strh r5, [r4]
_08068F74:
	adds r6, 0x1
	cmp r6, 0x3
	ble _08068F2E
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_8068F28

	thumb_func_start sub_8068F80
sub_8068F80:
	push {r4,r5,lr}
	bl GetLeader
	adds r5, r0, 0
	ldr r0, _08068FD4
	ldr r4, [r0]
	ldr r1, _08068FD8
	adds r0, r4, r1
	movs r1, 0
	strb r1, [r0]
	ldr r2, _08068FDC
	adds r0, r4, r2
	strb r1, [r0]
	adds r2, 0x6
	adds r0, r4, r2
	strb r1, [r0]
	adds r0, r4, 0
	adds r0, 0xC0
	str r1, [r0]
	cmp r5, 0
	beq _08068FCC
	adds r0, r5, 0
	bl GetTileAtEntitySafe
	ldrh r0, [r0]
	lsrs r0, 5
	movs r1, 0x1
	ands r0, r1
	movs r2, 0xD3
	lsls r2, 3
	adds r1, r4, r2
	strb r0, [r1]
	adds r2, 0x1
	adds r1, r4, r2
	strb r0, [r1]
	adds r0, r5, 0x4
	bl sub_804AC20
_08068FCC:
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_08068FD4: .4byte gDungeon
_08068FD8: .4byte 0x0000066c
_08068FDC: .4byte 0x0000066d
	thumb_func_end sub_8068F80

	thumb_func_start sub_8068FE0
sub_8068FE0:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x84
	mov r8, r0
	str r2, [sp, 0x74]
	lsls r1, 16
	asrs r1, 16
	mov r9, r1
	ldr r7, [r0, 0x70]
	bl GetTileAtEntitySafe
	adds r4, r0, 0
	ldr r0, [sp, 0x74]
	cmp r0, 0
	bne _0806900E
	mov r0, sp
	bl sub_80457DC
	mov r1, sp
	str r1, [sp, 0x74]
_0806900E:
	ldr r0, [r4, 0x10]
	cmp r0, r8
	bne _08069018
	movs r0, 0
	str r0, [r4, 0x10]
_08069018:
	mov r2, r8
	movs r3, 0x4
	ldrsh r0, [r2, r3]
	movs r3, 0x6
	ldrsh r1, [r2, r3]
	bl sub_80402AC
	movs r5, 0
	adds r6, r7, 0
	adds r6, 0xC8
	movs r0, 0xB0
	adds r0, r7
	mov r10, r0
	mov r1, r8
	adds r1, 0x22
	str r1, [sp, 0x80]
	mov r2, r8
	adds r2, 0x20
	str r2, [sp, 0x7C]
	adds r3, r7, 0
	adds r3, 0x40
	str r3, [sp, 0x78]
_08069044:
	ldr r0, _080690E4
	ldr r0, [r0]
	lsls r1, r5, 2
	ldr r2, _080690E8
	adds r0, r2
	adds r0, r1
	ldr r4, [r0]
	cmp r4, 0
	beq _08069072
	adds r0, r4, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	beq _08069072
	ldr r0, [r4, 0x70]
	adds r1, r0, 0
	adds r1, 0x80
	ldr r0, [r1]
	cmp r0, r8
	bne _08069072
	movs r0, 0
	str r0, [r1]
_08069072:
	adds r5, 0x1
	cmp r5, 0x13
	ble _08069044
	ldrb r0, [r6]
	cmp r0, 0x2
	bne _0806908A
	ldr r0, _080690E4
	ldr r0, [r0]
	ldr r3, _080690EC
	adds r0, r3
	movs r1, 0
	strb r1, [r0]
_0806908A:
	mov r1, r10
	ldrb r0, [r1]
	subs r0, 0x3
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bhi _080690A2
	adds r0, r7, 0
	adds r0, 0x9C
	ldr r0, [r0]
	bl sub_8076CB4
_080690A2:
	mov r0, r8
	bl sub_8078084
	movs r0, 0
	ldr r2, [sp, 0x80]
	strb r0, [r2]
	ldr r3, [sp, 0x7C]
	strb r0, [r3]
	ldr r1, _080690F0
	str r0, [r1]
	ldr r1, [sp, 0x78]
	ldrb r0, [r1]
	cmp r0, 0x41
	bne _080690FC
	ldr r3, _080690E4
	ldr r2, [r3]
	ldr r1, _080690F4
	adds r0, r2, r1
	ldrb r1, [r0]
	cmp r1, 0
	bne _080690FC
	movs r0, 0x1
	strb r0, [r2, 0x10]
	strh r1, [r7, 0xE]
	ldr r0, [r3]
	ldr r2, _080690F8
	adds r0, r2
	mov r1, r8
	movs r2, 0
	bl SetMessageArgument
	b _08069484
	.align 2, 0
_080690E4: .4byte gDungeon
_080690E8: .4byte 0x000135cc
_080690EC: .4byte 0x000037fc
_080690F0: .4byte gLeaderPointer
_080690F4: .4byte 0x0000065c
_080690F8: .4byte 0x000005f4
_080690FC:
	ldrb r0, [r7, 0x7]
	cmp r0, 0
	bne _08069104
	b _0806928E
_08069104:
	movs r0, 0x3C
	movs r1, 0x49
	bl sub_803E708
	bl DisplayMessageLog
	ldr r5, _08069198
	ldr r2, [r5]
	ldrb r0, [r2, 0x6]
	cmp r0, 0
	bne _080691C8
	ldr r3, _0806919C
	adds r0, r2, r3
	ldrb r0, [r0]
	cmp r0, 0
	bne _080691E0
	movs r0, 0x87
	lsls r0, 2
	cmp r9, r0
	beq _080691E0
	adds r0, 0x6
	cmp r9, r0
	beq _080691E0
	subs r0, 0x4
	cmp r9, r0
	beq _080691E0
	ldr r1, _080691A0
	adds r0, r2, r1
	ldrb r0, [r0]
	cmp r0, 0
	bne _080691E0
	ldr r6, _080691A4
	adds r0, r2, r6
	movs r1, 0
	ldrsb r1, [r0, r1]
	cmp r1, 0
	blt _080691E0
	adds r3, 0xA
	adds r0, r2, r3
	ldrb r0, [r0]
	cmp r0, 0x1
	beq _080691E0
	cmp r1, 0
	ble _080691B4
	ldr r0, _080691A8
	ldr r1, [r0]
	movs r0, 0
	movs r2, 0x1
	bl DisplayDungeonYesNoMessage
	adds r4, r0, 0
	cmp r4, 0x1
	bne _080691E0
	ldr r0, _080691AC
	ldr r1, [r0]
	movs r0, 0
	movs r2, 0x1
	bl DisplayDungeonMessage
	ldr r0, [r5]
	strb r4, [r0, 0x4]
	ldr r0, [r5]
	strb r4, [r0, 0x6]
	ldr r0, [r5]
	ldr r1, _080691B0
	adds r0, r1
	strb r4, [r0]
	ldr r1, [r5]
	adds r1, r6
	ldrb r0, [r1]
	subs r0, 0x1
	strb r0, [r1]
	b _08069484
	.align 2, 0
_08069198: .4byte gDungeon
_0806919C: .4byte 0x0000066e
_080691A0: .4byte 0x00003a0d
_080691A4: .4byte 0x0000067b
_080691A8: .4byte gUnknown_80FE268
_080691AC: .4byte gUnknown_80FE28C
_080691B0: .4byte 0x00000654
_080691B4:
	ldr r0, _080691C4
	ldr r1, [r0]
	movs r0, 0
	movs r2, 0x1
	bl DisplayDungeonMessage
	b _080691E0
	.align 2, 0
_080691C4: .4byte gUnknown_80FE2D0
_080691C8:
	movs r1, 0x1
	strb r1, [r2, 0x4]
	ldr r0, [r5]
	strb r1, [r0, 0x6]
	ldr r0, [r5]
	ldr r2, _080691DC
	adds r0, r2
	strb r1, [r0]
	b _08069484
	.align 2, 0
_080691DC: .4byte 0x00000654
_080691E0:
	mov r0, r9
	ldr r1, [sp, 0x74]
	mov r2, r8
	bl sub_8083AB0
	ldr r0, _080691F8
	cmp r9, r0
	bne _0806928E
	movs r6, 0
	movs r5, 0
	b _080691FE
	.align 2, 0
_080691F8: .4byte 0x0000021f
_080691FC:
	adds r5, 0x1
_080691FE:
	cmp r5, 0x3
	bgt _08069228
	ldr r0, _080692C4
	ldr r0, [r0]
	lsls r1, r5, 2
	ldr r3, _080692C8
	adds r0, r3
	adds r0, r1
	ldr r4, [r0]
	adds r0, r4, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	beq _080691FC
	ldr r6, [r4, 0x70]
	adds r0, r6, 0
	adds r0, 0x40
	ldrb r0, [r0]
	cmp r0, 0x41
	bne _080691FC
_08069228:
	cmp r6, 0
	beq _0806928E
	ldr r5, _080692CC
	ldrb r0, [r6, 0xA]
	movs r1, 0x64
	muls r1, r0
	ldr r2, _080692D0
	adds r1, r2
	ldr r2, [r5]
	adds r4, r2, r1
	adds r1, r6, 0
	bl sub_806C264
	movs r3, 0xA
	ldrsh r0, [r4, r3]
	bl sub_806A58C
	lsls r0, 24
	cmp r0, 0
	beq _0806928A
	ldr r0, _080692C4
	ldr r0, [r0]
	ldr r1, _080692D4
	adds r0, r1
	ldrb r0, [r0]
	bl IsLevelResetTo1
	lsls r0, 24
	cmp r0, 0
	bne _0806926E
	movs r2, 0xA
	ldrsh r0, [r4, r2]
	adds r1, r4, 0
	bl xxx_pokemon2_to_pokemonstruct_index_808DF2C
_0806926E:
	bl IsMakuhitaTrainingMaze
	lsls r0, 24
	lsrs r2, r0, 24
	cmp r2, 0
	bne _0806928A
	movs r3, 0xA
	ldrsh r1, [r4, r3]
	movs r0, 0x58
	muls r0, r1
	ldr r1, [r5]
	adds r0, r1
	adds r0, 0x28
	strb r2, [r0]
_0806928A:
	movs r0, 0
	strh r0, [r4]
_0806928E:
	ldrb r0, [r7, 0x6]
	cmp r0, 0
	beq _080692DC
	movs r5, 0
	movs r1, 0xB4
	lsls r1, 1
	adds r0, r7, r1
	movs r2, 0x98
	adds r2, r7
	mov r10, r2
	ldrb r3, [r0]
	cmp r5, r3
	bge _0806930A
	ldr r4, _080692D8
	subs r1, 0x1
	adds r2, r7, r1
	movs r3, 0
	adds r1, r0, 0
_080692B2:
	ldrb r0, [r2]
	adds r0, r5
	adds r0, r4
	strb r3, [r0]
	adds r5, 0x1
	ldrb r0, [r1]
	cmp r5, r0
	blt _080692B2
	b _0806930A
	.align 2, 0
_080692C4: .4byte gDungeon
_080692C8: .4byte 0x0001357c
_080692CC: .4byte gRecruitedPokemonRef
_080692D0: .4byte 0x00008df8
_080692D4: .4byte 0x00000644
_080692D8: .4byte gUnknown_202EE76
_080692DC:
	movs r5, 0
	movs r1, 0xB4
	lsls r1, 1
	adds r0, r7, r1
	movs r2, 0x98
	adds r2, r7
	mov r10, r2
	ldrb r3, [r0]
	cmp r5, r3
	bge _0806930A
	ldr r4, _0806932C
	subs r1, 0x1
	adds r2, r7, r1
	movs r3, 0
	adds r1, r0, 0
_080692FA:
	ldrb r0, [r2]
	adds r0, r5
	adds r0, r4
	strb r3, [r0]
	adds r5, 0x1
	ldrb r0, [r1]
	cmp r5, r0
	blt _080692FA
_0806930A:
	ldr r1, [sp, 0x78]
	ldrb r0, [r1]
	cmp r0, 0x4A
	bne _08069338
	ldr r2, _08069330
	ldr r1, [r2]
	movs r0, 0x2
	strb r0, [r1, 0x10]
	ldr r0, [r2]
	ldr r2, _08069334
	adds r0, r2
	mov r1, r8
	movs r2, 0
	bl SetMessageArgument
	b _08069352
	.align 2, 0
_0806932C: .4byte gUnknown_202EE70
_08069330: .4byte gDungeon
_08069334: .4byte 0x000005f4
_08069338:
	cmp r0, 0x47
	bne _08069352
	ldr r2, _08069494
	ldr r1, [r2]
	movs r0, 0x3
	strb r0, [r1, 0x10]
	ldr r0, [r2]
	ldr r3, _08069498
	adds r0, r3
	mov r1, r8
	movs r2, 0
	bl SetMessageArgument
_08069352:
	bl GetLeader
	cmp r0, 0
	beq _080693C6
	movs r0, 0x87
	lsls r0, 2
	cmp r9, r0
	beq _080693C6
	ldrb r0, [r7, 0x7]
	cmp r0, 0
	bne _080693C6
	ldr r4, _08069494
	ldr r0, [r4]
	ldrb r0, [r0, 0x10]
	cmp r0, 0
	bne _080693C6
	adds r0, r7, 0
	adds r0, 0xA4
	ldrb r1, [r0]
	movs r2, 0
	movs r0, 0xFA
	lsls r0, 1
	cmp r9, r0
	bne _08069384
	movs r2, 0x1
_08069384:
	mov r0, r8
	bl sub_8084E00
	ldr r1, _0806949C
	adds r0, r1, 0
	ldrh r2, [r7, 0x4]
	adds r0, r2
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0x2
	bhi _080693C6
	bl IsBossFight
	lsls r0, 24
	cmp r0, 0
	bne _080693C6
	ldrb r0, [r7, 0x6]
	cmp r0, 0
	beq _080693CC
	ldr r0, [r4]
	ldr r3, _080694A0
	adds r0, r3
	movs r1, 0x1
	strb r1, [r0]
	ldr r0, _080694A4
	ldr r1, [r0]
	mov r0, r8
	bl DisplayDungeonLoggableMessageTrue
	bl sub_803E178
	bl sub_8049ED4
_080693C6:
	ldrb r0, [r7, 0x6]
	cmp r0, 0
	bne _08069466
_080693CC:
	ldr r6, _080694A8
	ldrb r0, [r7, 0xA]
	movs r1, 0x64
	muls r1, r0
	ldr r2, _080694AC
	adds r1, r2
	ldr r2, [r6]
	adds r4, r2, r1
	adds r1, r7, 0
	bl sub_806C264
	movs r3, 0xA
	ldrsh r0, [r4, r3]
	bl sub_806A58C
	lsls r0, 24
	cmp r0, 0
	beq _08069462
	ldr r5, _08069494
	ldr r0, [r5]
	ldr r1, _080694B0
	adds r0, r1
	ldrb r0, [r0]
	bl IsLevelResetTo1
	lsls r0, 24
	cmp r0, 0
	bne _0806940E
	movs r2, 0xA
	ldrsh r0, [r4, r2]
	adds r1, r4, 0
	bl xxx_pokemon2_to_pokemonstruct_index_808DF2C
_0806940E:
	bl IsMakuhitaTrainingMaze
	lsls r0, 24
	lsrs r2, r0, 24
	cmp r2, 0
	bne _0806942A
	movs r3, 0xA
	ldrsh r1, [r4, r3]
	movs r0, 0x58
	muls r0, r1
	ldr r1, [r6]
	adds r0, r1
	adds r0, 0x28
	strb r2, [r0]
_0806942A:
	ldrb r1, [r7, 0x7]
	negs r0, r1
	orrs r0, r1
	lsrs r1, r0, 31
	ldr r0, [r5]
	ldr r2, _080694B4
	adds r0, r2
	ldrb r0, [r0]
	cmp r0, 0
	bne _08069448
	ldr r3, [sp, 0x78]
	ldrb r0, [r3]
	cmp r0, 0x41
	bne _08069448
	movs r1, 0x1
_08069448:
	cmp r1, 0
	bne _08069462
	movs r0, 0xA
	ldrsh r1, [r4, r0]
	movs r0, 0x58
	muls r1, r0
	ldr r0, _080694A8
	ldr r0, [r0]
	adds r1, r0
	ldrh r2, [r1]
	ldr r0, _080694B8
	ands r0, r2
	strh r0, [r1]
_08069462:
	movs r0, 0
	strh r0, [r4]
_08069466:
	mov r1, r10
	ldr r0, [r1]
	bl DeletePokemonDungeonSprite
	ldr r0, _080694BC
	movs r2, 0
	str r2, [r0]
	ldr r0, _08069494
	ldr r1, [r0]
	movs r0, 0x1
	strb r0, [r1, 0xC]
	mov r3, r8
	str r2, [r3]
	bl sub_8045ACC
_08069484:
	add sp, 0x84
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_08069494: .4byte gDungeon
_08069498: .4byte 0x000005f4
_0806949C: .4byte 0xfffffe5f
_080694A0: .4byte 0x000037fe
_080694A4: .4byte gUnknown_80FA580
_080694A8: .4byte gRecruitedPokemonRef
_080694AC: .4byte 0x00008df8
_080694B0: .4byte 0x00000644
_080694B4: .4byte 0x0000065c
_080694B8: .4byte 0x0000fffd
_080694BC: .4byte gLeaderPointer
	thumb_func_end sub_8068FE0

	thumb_func_start sub_80694C0
sub_80694C0:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	adds r4, r0, 0
	adds r7, r1, 0
	mov r8, r2
	lsls r3, 24
	lsrs r3, 24
	mov r9, r3
	adds r0, r7, 0
	mov r1, r8
	bl GetTileSafe
	mov r10, r0
	ldr r5, [r4, 0x70]
	adds r6, r5, 0
	adds r6, 0xB0
	ldrb r0, [r6]
	subs r0, 0x3
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bhi _080694FC
	adds r0, r5, 0
	adds r0, 0x9C
	ldr r0, [r0]
	bl sub_8076CB4
_080694FC:
	ldrb r0, [r6]
	cmp r0, 0x7
	beq _0806950A
	cmp r0, 0x5
	beq _0806950A
	cmp r0, 0x2
	bne _08069512
_0806950A:
	adds r0, r4, 0
	adds r1, r4, 0
	bl SendImmobilizeEndMessage
_08069512:
	movs r0, 0x4
	ldrsh r2, [r4, r0]
	cmp r7, r2
	bne _08069522
	movs r1, 0x6
	ldrsh r0, [r4, r1]
	cmp r8, r0
	beq _080695DE
_08069522:
	movs r1, 0x4
	ldrsh r0, [r4, r1]
	cmp r0, 0
	blt _08069552
	movs r1, 0x6
	ldrsh r0, [r4, r1]
	cmp r0, 0
	blt _08069552
	adds r1, r0, 0
	adds r0, r2, 0
	bl GetTileSafe
	adds r1, r0, 0
	ldr r0, [r1, 0x10]
	cmp r0, r4
	bne _08069546
	movs r0, 0
	str r0, [r1, 0x10]
_08069546:
	movs r1, 0x4
	ldrsh r0, [r4, r1]
	movs r2, 0x6
	ldrsh r1, [r4, r2]
	bl sub_80402AC
_08069552:
	ldrh r0, [r4, 0x4]
	strh r0, [r4, 0x8]
	ldrh r0, [r4, 0x6]
	strh r0, [r4, 0xA]
	strh r7, [r4, 0x4]
	mov r0, r8
	strh r0, [r4, 0x6]
	ldrb r0, [r5, 0x7]
	cmp r0, 0
	beq _0806956E
	ldr r0, _0806959C
	strh r7, [r0]
	mov r1, r8
	strh r1, [r0, 0x2]
_0806956E:
	mov r2, r10
	str r4, [r2, 0x10]
	ldrb r0, [r5, 0x7]
	cmp r0, 0
	beq _08069588
	ldr r0, _080695A0
	strh r7, [r0]
	mov r1, r8
	strh r1, [r0, 0x2]
	ldr r0, _080695A4
	ldr r1, [r0]
	movs r0, 0
	strb r0, [r1, 0x1]
_08069588:
	adds r0, r7, 0
	mov r1, r8
	bl sub_80402AC
	mov r2, r9
	cmp r2, 0
	beq _080695A8
	cmp r2, 0x1
	beq _080695C4
	b _080695CE
	.align 2, 0
_0806959C: .4byte gUnknown_203B410
_080695A0: .4byte gUnknown_202EE0C
_080695A4: .4byte gDungeon
_080695A8:
	ldr r0, [r5, 0x70]
	str r0, [r5, 0x74]
	ldr r0, [r5, 0x6C]
	str r0, [r5, 0x70]
	ldr r0, [r5, 0x68]
	str r0, [r5, 0x6C]
	adds r0, r5, 0
	adds r0, 0xE4
	ldrb r0, [r0]
	cmp r0, 0x1
	beq _080695CE
	ldr r0, [r4, 0x8]
	str r0, [r5, 0x68]
	b _080695CE
_080695C4:
	ldr r0, [r4, 0x4]
	str r0, [r5, 0x68]
	str r0, [r5, 0x6C]
	str r0, [r5, 0x70]
	str r0, [r5, 0x74]
_080695CE:
	mov r1, r10
	ldrb r0, [r1, 0x9]
	adds r1, r4, 0
	adds r1, 0x25
	strb r0, [r1]
	adds r0, r4, 0
	bl sub_806CF98
_080695DE:
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_80694C0

	thumb_func_start sub_80695EC
sub_80695EC:
	push {r4-r7,lr}
	adds r4, r0, 0
	adds r6, r1, 0
	adds r7, r2, 0
	ldr r1, [r4, 0x70]
	adds r5, r1, 0
	adds r0, r1, 0
	adds r0, 0xB0
	ldrb r0, [r0]
	subs r0, 0x3
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bhi _08069612
	adds r0, r1, 0
	adds r0, 0x9C
	ldr r0, [r0]
	bl sub_8076CB4
_08069612:
	movs r1, 0x4
	ldrsh r0, [r4, r1]
	cmp r6, r0
	bne _08069622
	movs r1, 0x6
	ldrsh r0, [r4, r1]
	cmp r7, r0
	beq _08069658
_08069622:
	ldrh r0, [r4, 0x4]
	strh r0, [r4, 0x8]
	ldrh r0, [r4, 0x6]
	strh r0, [r4, 0xA]
	strh r6, [r4, 0x4]
	strh r7, [r4, 0x6]
	ldr r0, [r5, 0x70]
	str r0, [r5, 0x74]
	ldr r0, [r5, 0x6C]
	str r0, [r5, 0x70]
	ldr r0, [r5, 0x68]
	str r0, [r5, 0x6C]
	adds r0, r5, 0
	adds r0, 0xE4
	ldrb r0, [r0]
	cmp r0, 0x1
	beq _08069648
	ldr r0, [r4, 0x8]
	str r0, [r5, 0x68]
_08069648:
	adds r0, r6, 0
	adds r1, r7, 0
	bl GetTile
	ldrb r1, [r0, 0x9]
	adds r0, r4, 0
	adds r0, 0x25
	strb r1, [r0]
_08069658:
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_80695EC

	thumb_func_start sub_8069660
sub_8069660:
	push {r4,r5,lr}
	adds r4, r0, 0
	ldr r0, [r4, 0x70]
	adds r5, r0, 0
	adds r5, 0x46
	ldrb r1, [r5]
	adds r0, r4, 0
	bl sub_8070F80
	lsls r0, 24
	cmp r0, 0
	bne _0806967C
	movs r0, 0
	b _0806969E
_0806967C:
	movs r1, 0x4
	ldrsh r0, [r4, r1]
	ldr r1, _080696A4
	ldrb r2, [r5]
	lsls r2, 2
	adds r2, r1
	movs r3, 0
	ldrsh r1, [r2, r3]
	adds r0, r1
	movs r3, 0x6
	ldrsh r1, [r4, r3]
	movs r3, 0x2
	ldrsh r2, [r2, r3]
	adds r1, r2
	bl GetTile
	ldr r0, [r0, 0x10]
_0806969E:
	pop {r4,r5}
	pop {r1}
	bx r1
	.align 2, 0
_080696A4: .4byte gAdjacentTileOffsets
	thumb_func_end sub_8069660

	thumb_func_start sub_80696A8
sub_80696A8:
	push {r4,r5,lr}
	adds r4, r0, 0
	ldr r0, [r4, 0x70]
	adds r5, r0, 0
	adds r5, 0x46
	ldrb r1, [r5]
	adds r0, r4, 0
	bl CanAttackInDirection
	lsls r0, 24
	cmp r0, 0
	beq _080696F4
	movs r1, 0x4
	ldrsh r0, [r4, r1]
	ldr r1, _080696F0
	ldrb r2, [r5]
	lsls r2, 2
	adds r2, r1
	movs r3, 0
	ldrsh r1, [r2, r3]
	adds r0, r1
	movs r3, 0x6
	ldrsh r1, [r4, r3]
	movs r3, 0x2
	ldrsh r2, [r2, r3]
	adds r1, r2
	bl GetTile
	ldr r1, [r0, 0x10]
	cmp r1, 0
	beq _080696F4
	ldr r0, [r1]
	cmp r0, 0x1
	bne _080696F4
	adds r0, r1, 0
	b _080696F6
	.align 2, 0
_080696F0: .4byte gAdjacentTileOffsets
_080696F4:
	movs r0, 0
_080696F6:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_80696A8

	thumb_func_start sub_80696FC
sub_80696FC:
	push {r4,r5,lr}
	sub sp, 0x4
	adds r4, r0, 0
	ldr r3, [r4, 0x70]
	ldr r5, _08069764
	adds r3, 0x46
	ldrb r0, [r3]
	lsls r0, 2
	adds r0, r5
	ldrh r0, [r0]
	ldrh r1, [r4, 0x4]
	adds r0, r1
	lsls r0, 16
	lsrs r0, 16
	ldr r1, _08069768
	ldr r2, [sp]
	ands r2, r1
	orrs r2, r0
	str r2, [sp]
	ldrb r0, [r3]
	lsls r0, 2
	adds r0, r5
	ldrh r0, [r0, 0x2]
	ldrh r1, [r4, 0x6]
	adds r0, r1
	lsls r0, 16
	ldr r1, _0806976C
	ands r1, r2
	orrs r1, r0
	str r1, [sp]
	mov r0, sp
	movs r2, 0
	ldrsh r0, [r0, r2]
	asrs r1, 16
	bl GetTile
	adds r5, r0, 0
	adds r0, r4, 0
	mov r1, sp
	bl sub_80705F0
	lsls r0, 24
	cmp r0, 0
	bne _08069770
	ldr r1, [r5, 0x10]
	cmp r1, 0
	beq _08069770
	ldr r0, [r1]
	cmp r0, 0x1
	bne _08069770
	adds r0, r1, 0
	b _08069772
	.align 2, 0
_08069764: .4byte gAdjacentTileOffsets
_08069768: .4byte 0xffff0000
_0806976C: .4byte 0x0000ffff
_08069770:
	movs r0, 0
_08069772:
	add sp, 0x4
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_80696FC

	thumb_func_start sub_806977C
sub_806977C:
	push {r4-r7,lr}
	sub sp, 0x4
	adds r4, r0, 0
	ldr r0, [r4, 0x70]
	ldr r7, _0806982C
	adds r5, r0, 0
	adds r5, 0x46
	ldrb r0, [r5]
	lsls r0, 2
	adds r0, r7
	ldrh r0, [r0]
	ldrh r1, [r4, 0x4]
	adds r0, r1
	lsls r0, 16
	lsrs r0, 16
	ldr r1, _08069830
	ldr r2, [sp]
	ands r2, r1
	orrs r2, r0
	str r2, [sp]
	ldrb r0, [r5]
	lsls r0, 2
	adds r0, r7
	ldrh r0, [r0, 0x2]
	ldrh r1, [r4, 0x6]
	adds r0, r1
	lsls r0, 16
	ldr r1, _08069834
	ands r1, r2
	orrs r1, r0
	str r1, [sp]
	mov r0, sp
	movs r2, 0
	ldrsh r0, [r0, r2]
	asrs r1, 16
	bl GetTile
	mov r6, sp
	adds r0, r4, 0
	mov r1, sp
	bl sub_80705F0
	lsls r0, 24
	cmp r0, 0
	bne _08069838
	ldrb r0, [r5]
	lsls r0, 2
	adds r0, r7
	movs r1, 0
	ldrsh r0, [r0, r1]
	lsls r0, 1
	ldrh r2, [r4, 0x4]
	adds r0, r2
	mov r1, sp
	strh r0, [r1]
	ldrb r0, [r5]
	lsls r0, 2
	adds r0, r7
	movs r1, 0x2
	ldrsh r0, [r0, r1]
	lsls r0, 1
	ldrh r2, [r4, 0x6]
	adds r0, r2
	strh r0, [r6, 0x2]
	mov r0, sp
	movs r1, 0
	ldrsh r0, [r0, r1]
	movs r2, 0x2
	ldrsh r1, [r6, r2]
	bl GetTile
	adds r5, r0, 0
	adds r0, r4, 0
	mov r1, sp
	bl sub_80705F0
	lsls r0, 24
	cmp r0, 0
	bne _08069838
	ldr r1, [r5, 0x10]
	cmp r1, 0
	beq _08069838
	ldr r0, [r1]
	cmp r0, 0x1
	bne _08069838
	adds r0, r1, 0
	b _0806983A
	.align 2, 0
_0806982C: .4byte gAdjacentTileOffsets
_08069830: .4byte 0xffff0000
_08069834: .4byte 0x0000ffff
_08069838:
	movs r0, 0
_0806983A:
	add sp, 0x4
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_806977C

	thumb_func_start sub_8069844
sub_8069844:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	adds r6, r0, 0
	mov r8, r1
	ldr r5, [r1, 0x70]
	adds r0, r6, 0x2
	adds r1, r5, 0
	movs r2, 0
	bl SetMessageArgument_2
	ldrh r0, [r5, 0x2]
	strh r0, [r6]
	movs r1, 0xE
	ldrsh r0, [r5, r1]
	str r0, [r6, 0x24]
	movs r2, 0x10
	ldrsh r0, [r5, r2]
	str r0, [r6, 0x28]
	ldrb r0, [r5, 0x9]
	str r0, [r6, 0x2C]
	ldr r0, [r5, 0x18]
	str r0, [r6, 0x30]
	movs r2, 0
_08069874:
	adds r1, r6, 0
	adds r1, 0x34
	adds r1, r2
	adds r0, r5, 0
	adds r0, 0x14
	adds r0, r2
	ldrb r0, [r0]
	strb r0, [r1]
	adds r1, r6, 0
	adds r1, 0x36
	adds r1, r2
	adds r0, r5, 0
	adds r0, 0x16
	adds r0, r2
	ldrb r0, [r0]
	strb r0, [r1]
	adds r1, r6, 0
	adds r1, 0x16
	adds r1, r2
	adds r0, r5, 0
	adds r0, 0x5C
	adds r0, r2
	ldrb r0, [r0]
	strb r0, [r1]
	adds r1, r6, 0
	adds r1, 0x18
	adds r1, r2
	adds r0, r5, 0
	adds r0, 0x5E
	adds r0, r2
	ldrb r0, [r0]
	strb r0, [r1]
	adds r2, 0x1
	cmp r2, 0x1
	ble _08069874
	ldrb r2, [r5, 0x7]
	adds r1, r6, 0
	adds r1, 0x38
	movs r0, 0
	strb r2, [r1]
	adds r2, r6, 0
	adds r2, 0x39
	strb r0, [r2]
	adds r3, r6, 0
	adds r3, 0x3A
	strb r0, [r3]
	adds r4, r6, 0
	adds r4, 0x3B
	strb r0, [r4]
	movs r7, 0x3C
	adds r7, r6
	mov r12, r7
	strb r0, [r7]
	adds r0, r5, 0
	adds r0, 0x60
	ldrb r1, [r0]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _0806995C
	movs r0, 0x8
	ands r0, r1
	cmp r0, 0
	bne _0806995C
	adds r1, r5, 0
	adds r1, 0x62
	ldrb r0, [r1]
	cmp r0, 0x13
	bne _08069908
	ldr r0, _080699A4
	ldrb r0, [r0]
	ldrb r7, [r2]
	adds r0, r7
	strb r0, [r2]
_08069908:
	ldrb r0, [r1]
	cmp r0, 0x2B
	bne _08069918
	ldr r0, _080699A8
	ldrb r0, [r0]
	ldrb r7, [r2]
	adds r0, r7
	strb r0, [r2]
_08069918:
	ldrb r0, [r1]
	cmp r0, 0x21
	bne _08069928
	ldr r0, _080699AC
	ldrb r0, [r0]
	ldrb r2, [r3]
	adds r0, r2
	strb r0, [r3]
_08069928:
	ldrb r0, [r1]
	cmp r0, 0x2B
	bne _08069938
	ldr r0, _080699A8
	ldrb r0, [r0]
	ldrb r7, [r3]
	adds r0, r7
	strb r0, [r3]
_08069938:
	ldrb r0, [r1]
	cmp r0, 0x1E
	bne _08069948
	ldr r0, _080699B0
	ldrb r0, [r0]
	ldrb r2, [r4]
	adds r0, r2
	strb r0, [r4]
_08069948:
	ldrb r0, [r1]
	cmp r0, 0x22
	bne _0806995C
	ldr r0, _080699B4
	ldrb r0, [r0]
	mov r7, r12
	ldrb r7, [r7]
	adds r0, r7
	mov r1, r12
	strb r0, [r1]
_0806995C:
	adds r0, r5, 0
	adds r0, 0x94
	ldrb r1, [r0]
	adds r0, r6, 0
	adds r0, 0x54
	strb r1, [r0]
	ldr r0, [r5, 0x60]
	str r0, [r6, 0x20]
	ldrh r0, [r5, 0xC]
	movs r1, 0
	strh r0, [r6, 0x3E]
	ldr r0, [r5, 0x40]
	str r0, [r6, 0x1C]
	adds r0, r6, 0
	adds r0, 0x44
	strb r1, [r0]
	adds r0, 0x4
	strb r1, [r0]
	adds r0, r5, 0
	adds r0, 0x8C
	ldr r0, [r0]
	str r0, [r6, 0x50]
	ldr r0, _080699B8
	ldr r0, [r0]
	ldr r2, _080699BC
	adds r0, r2
	ldrb r0, [r0]
	cmp r0, 0
	beq _080699C0
	adds r0, r5, 0
	bl sub_806A4DC
	adds r1, r6, 0
	adds r1, 0x4C
	b _080699C6
	.align 2, 0
_080699A4: .4byte gUnknown_810AC60
_080699A8: .4byte gUnknown_810AC68
_080699AC: .4byte gUnknown_810AC62
_080699B0: .4byte gUnknown_810AC64
_080699B4: .4byte gUnknown_810AC66
_080699B8: .4byte gDungeon
_080699BC: .4byte 0x0000065a
_080699C0:
	adds r1, r6, 0
	adds r1, 0x4C
	movs r0, 0x3
_080699C6:
	strb r0, [r1]
	movs r4, 0
	movs r7, 0x10
	ldrsh r0, [r5, r7]
	cmp r0, 0
	bge _080699D4
	adds r0, 0x3
_080699D4:
	movs r2, 0xE
	ldrsh r1, [r5, r2]
	asrs r0, 2
	cmp r1, r0
	bgt _080699E8
	adds r1, r6, 0
	adds r1, 0x58
	movs r0, 0x6
	strb r0, [r1]
	movs r4, 0x1
_080699E8:
	ldr r0, _08069A24
	ldr r0, [r0]
	ldr r7, _08069A28
	adds r0, r7
	ldrb r0, [r0]
	cmp r0, 0
	beq _08069A02
	adds r0, r6, 0
	adds r0, 0x58
	adds r0, r4
	movs r1, 0xB
	strb r1, [r0]
	adds r4, 0x1
_08069A02:
	movs r1, 0x9E
	lsls r1, 1
	adds r0, r5, r1
	ldr r0, [r0]
	bl FixedPointToInt
	cmp r0, 0
	bne _08069A38
	ldrb r0, [r5, 0x7]
	cmp r0, 0
	beq _08069A2C
	adds r0, r6, 0
	adds r0, 0x58
	adds r0, r4
	movs r1, 0x13
	b _08069A34
	.align 2, 0
_08069A24: .4byte gDungeon
_08069A28: .4byte 0x00000676
_08069A2C:
	adds r0, r6, 0
	adds r0, 0x58
	adds r0, r4
	movs r1, 0x3B
_08069A34:
	strb r1, [r0]
	adds r4, 0x1
_08069A38:
	mov r2, r8
	ldr r0, [r2, 0x70]
	movs r7, 0x82
	lsls r7, 1
	adds r2, r0, r7
	ldr r0, [r2]
	cmp r0, 0x1
	ble _08069A54
	adds r0, r6, 0
	adds r0, 0x58
	adds r0, r4
	movs r1, 0x1B
	strb r1, [r0]
	adds r4, 0x1
_08069A54:
	ldr r0, [r2]
	cmp r0, 0
	bgt _08069A66
	adds r0, r6, 0
	adds r0, 0x58
	adds r0, r4
	movs r1, 0x28
	strb r1, [r0]
	adds r4, 0x1
_08069A66:
	ldr r0, [r5, 0x2C]
	cmp r0, 0xFF
	ble _08069AAE
	ldr r0, [r5, 0x30]
	cmp r0, 0xFF
	ble _08069AAE
	ldr r0, [r5, 0x34]
	cmp r0, 0xFF
	ble _08069AAE
	ldr r0, [r5, 0x38]
	cmp r0, 0xFF
	ble _08069AAE
	movs r1, 0x1C
	ldrsh r0, [r5, r1]
	cmp r0, 0x9
	ble _08069AAE
	movs r2, 0x1E
	ldrsh r0, [r5, r2]
	cmp r0, 0x9
	ble _08069AAE
	movs r7, 0x20
	ldrsh r0, [r5, r7]
	cmp r0, 0x9
	ble _08069AAE
	movs r1, 0x22
	ldrsh r0, [r5, r1]
	cmp r0, 0x9
	ble _08069AAE
	movs r2, 0x24
	ldrsh r0, [r5, r2]
	cmp r0, 0x9
	ble _08069AAE
	movs r7, 0x26
	ldrsh r0, [r5, r7]
	cmp r0, 0x9
	bgt _08069ABA
_08069AAE:
	adds r0, r6, 0
	adds r0, 0x58
	adds r0, r4
	movs r1, 0x37
	strb r1, [r0]
	adds r4, 0x1
_08069ABA:
	adds r0, r5, 0
	adds r0, 0xA8
	ldrb r1, [r0]
	cmp r1, 0
	beq _08069AD2
	cmp r4, 0xB
	bgt _08069AD2
	adds r0, r6, 0
	adds r0, 0x58
	adds r0, r4
	strb r1, [r0]
	adds r4, 0x1
_08069AD2:
	adds r0, r5, 0
	adds r0, 0xAC
	ldrb r1, [r0]
	cmp r1, 0
	beq _08069AEC
	cmp r4, 0xB
	bgt _08069AEC
	adds r0, r6, 0
	adds r0, 0x58
	adds r0, r4
	adds r1, 0x6
	strb r1, [r0]
	adds r4, 0x1
_08069AEC:
	adds r0, r5, 0
	adds r0, 0xB0
	ldrb r1, [r0]
	cmp r1, 0
	beq _08069B06
	cmp r4, 0xB
	bgt _08069B06
	adds r0, r6, 0
	adds r0, 0x58
	adds r0, r4
	adds r1, 0xB
	strb r1, [r0]
	adds r4, 0x1
_08069B06:
	adds r0, r5, 0
	adds r0, 0xBC
	ldrb r1, [r0]
	cmp r1, 0
	beq _08069B20
	cmp r4, 0xB
	bgt _08069B20
	adds r0, r6, 0
	adds r0, 0x58
	adds r0, r4
	adds r1, 0x13
	strb r1, [r0]
	adds r4, 0x1
_08069B20:
	adds r0, r5, 0
	adds r0, 0xC0
	ldrb r1, [r0]
	cmp r1, 0
	beq _08069B3A
	cmp r4, 0xB
	bgt _08069B3A
	adds r0, r6, 0
	adds r0, 0x58
	adds r0, r4
	adds r1, 0x1B
	strb r1, [r0]
	adds r4, 0x1
_08069B3A:
	adds r0, r5, 0
	adds r0, 0xC4
	ldrb r1, [r0]
	cmp r1, 0
	beq _08069B54
	cmp r4, 0xB
	bgt _08069B54
	adds r0, r6, 0
	adds r0, 0x58
	adds r0, r4
	adds r1, 0x28
	strb r1, [r0]
	adds r4, 0x1
_08069B54:
	adds r0, r5, 0
	adds r0, 0xC8
	ldrb r1, [r0]
	cmp r1, 0
	beq _08069B6E
	cmp r4, 0xB
	bgt _08069B6E
	adds r0, r6, 0
	adds r0, 0x58
	adds r0, r4
	adds r1, 0x37
	strb r1, [r0]
	adds r4, 0x1
_08069B6E:
	adds r0, r5, 0
	adds r0, 0xD0
	ldrb r1, [r0]
	cmp r1, 0
	beq _08069B88
	cmp r4, 0xB
	bgt _08069B88
	adds r0, r6, 0
	adds r0, 0x58
	adds r0, r4
	adds r1, 0x3B
	strb r1, [r0]
	adds r4, 0x1
_08069B88:
	adds r0, r5, 0
	adds r0, 0xDC
	ldrb r1, [r0]
	cmp r1, 0
	beq _08069BA2
	cmp r4, 0xB
	bgt _08069BA2
	adds r0, r6, 0
	adds r0, 0x58
	adds r0, r4
	adds r1, 0x3E
	strb r1, [r0]
	adds r4, 0x1
_08069BA2:
	adds r0, r5, 0
	adds r0, 0xE0
	ldrb r1, [r0]
	cmp r1, 0
	beq _08069BBC
	cmp r4, 0xB
	bgt _08069BBC
	adds r0, r6, 0
	adds r0, 0x58
	adds r0, r4
	adds r1, 0x43
	strb r1, [r0]
	adds r4, 0x1
_08069BBC:
	adds r0, r5, 0
	adds r0, 0xE4
	ldrb r1, [r0]
	cmp r1, 0
	beq _08069BD6
	cmp r4, 0xB
	bgt _08069BD6
	adds r0, r6, 0
	adds r0, 0x58
	adds r0, r4
	adds r1, 0x46
	strb r1, [r0]
	adds r4, 0x1
_08069BD6:
	adds r0, r5, 0
	adds r0, 0xE8
	ldrb r1, [r0]
	cmp r1, 0
	beq _08069BF0
	cmp r4, 0xB
	bgt _08069BF0
	adds r0, r6, 0
	adds r0, 0x58
	adds r0, r4
	adds r1, 0x4A
	strb r1, [r0]
	adds r4, 0x1
_08069BF0:
	adds r0, r5, 0
	adds r0, 0xEC
	ldrb r1, [r0]
	cmp r1, 0
	beq _08069C0A
	cmp r4, 0xB
	bgt _08069C0A
	adds r0, r6, 0
	adds r0, 0x58
	adds r0, r4
	adds r1, 0x4E
	strb r1, [r0]
	adds r4, 0x1
_08069C0A:
	movs r1, 0x89
	lsls r1, 1
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, 0
	beq _08069C26
	cmp r4, 0xB
	bgt _08069C26
	adds r0, r6, 0
	adds r0, 0x58
	adds r0, r4
	movs r1, 0x50
	strb r1, [r0]
	adds r4, 0x1
_08069C26:
	adds r0, r5, 0
	adds r0, 0xF0
	ldrb r0, [r0]
	cmp r0, 0
	beq _08069C40
	cmp r4, 0xB
	bgt _08069C40
	adds r0, r6, 0
	adds r0, 0x58
	adds r0, r4
	movs r1, 0x51
	strb r1, [r0]
	adds r4, 0x1
_08069C40:
	adds r0, r5, 0
	adds r0, 0xF1
	ldrb r0, [r0]
	cmp r0, 0
	beq _08069C5A
	cmp r4, 0xB
	bgt _08069C5A
	adds r0, r6, 0
	adds r0, 0x58
	adds r0, r4
	movs r1, 0x52
	strb r1, [r0]
	adds r4, 0x1
_08069C5A:
	adds r0, r5, 0
	adds r0, 0xF4
	ldrb r0, [r0]
	cmp r0, 0
	beq _08069C74
	cmp r4, 0xB
	bgt _08069C74
	adds r0, r6, 0
	adds r0, 0x58
	adds r0, r4
	movs r1, 0x53
	strb r1, [r0]
	adds r4, 0x1
_08069C74:
	adds r0, r5, 0
	adds r0, 0xF5
	ldrb r0, [r0]
	cmp r0, 0
	beq _08069C8E
	cmp r4, 0xB
	bgt _08069C8E
	adds r0, r6, 0
	adds r0, 0x58
	adds r0, r4
	movs r1, 0x54
	strb r1, [r0]
	adds r4, 0x1
_08069C8E:
	mov r0, r8
	bl ShouldMonsterRunAway
	lsls r0, 24
	cmp r0, 0
	beq _08069CAA
	cmp r4, 0xB
	bgt _08069CAA
	adds r0, r6, 0
	adds r0, 0x58
	adds r0, r4
	movs r1, 0x55
	strb r1, [r0]
	adds r4, 0x1
_08069CAA:
	adds r0, r5, 0
	adds r0, 0xFD
	ldrb r0, [r0]
	cmp r0, 0
	beq _08069CC4
	cmp r4, 0xB
	bgt _08069CC4
	adds r0, r6, 0
	adds r0, 0x58
	adds r0, r4
	movs r1, 0x56
	strb r1, [r0]
	adds r4, 0x1
_08069CC4:
	mov r0, r8
	movs r1, 0
	bl sub_8070828
	cmp r0, 0x1
	ble _08069CE0
	cmp r4, 0xB
	bgt _08069CE0
	adds r0, r6, 0
	adds r0, 0x58
	adds r0, r4
	movs r1, 0x57
	strb r1, [r0]
	adds r4, 0x1
_08069CE0:
	adds r0, r5, 0
	adds r0, 0xF2
	ldrb r0, [r0]
	cmp r0, 0
	beq _08069CFA
	cmp r4, 0xB
	bgt _08069D0E
	adds r0, r6, 0
	adds r0, 0x58
	adds r0, r4
	movs r1, 0x58
	strb r1, [r0]
	adds r4, 0x1
_08069CFA:
	cmp r4, 0xB
	bgt _08069D0E
	adds r1, r6, 0
	adds r1, 0x58
	movs r2, 0
_08069D04:
	adds r0, r1, r4
	strb r2, [r0]
	adds r4, 0x1
	cmp r4, 0xB
	ble _08069D04
_08069D0E:
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_8069844

    .align 2,0
