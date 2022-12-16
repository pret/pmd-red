	#include "asm/constants/gba_constants.inc"
	#include "asm/macros.inc"

  	.syntax unified

  	.text

	thumb_func_start sub_8073D14
sub_8073D14:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0xB0
	adds r6, r0, 0
	ldr r4, [r6, 0x70]
	bl GetMapTileForDungeonEntity_2
	ldr r5, [r0, 0x14]
	cmp r5, 0
	bne _08073D30
	b _0807407A
_08073D30:
	bl sub_8044B28
	lsls r0, 24
	cmp r0, 0
	beq _08073D3C
	b _0807407A
_08073D3C:
	ldr r0, _08073D68
	adds r1, r6, 0
	movs r2, 0
	bl SetMessageArgument
	ldrb r0, [r4, 0x7]
	cmp r0, 0
	beq _08073D4E
	b _0807407A
_08073D4E:
	ldrb r0, [r4, 0x8]
	cmp r0, 0x1
	bne _08073D56
	b _0807407A
_08073D56:
	adds r0, r4, 0
	adds r0, 0x40
	ldrb r0, [r0]
	cmp r0, 0x4A
	beq _08073D64
	cmp r0, 0x47
	bne _08073D6C
_08073D64:
	movs r0, 0x1
	b _08073D6E
	.align 2, 0
_08073D68: .4byte gAvailablePokemonNames
_08073D6C:
	movs r0, 0
_08073D6E:
	cmp r0, 0
	beq _08073D74
	b _0807407A
_08073D74:
	adds r0, r4, 0
	adds r0, 0xA4
	ldrb r0, [r0]
	cmp r0, 0x1
	bne _08073D80
	b _0807407A
_08073D80:
	ldr r0, [r6, 0x70]
	mov r10, r0
	adds r0, r5, 0
	bl GetItemData
	adds r5, r0, 0
	ldrb r1, [r5]
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	beq _08073D98
	b _0807407A
_08073D98:
	adds r0, r6, 0
	movs r1, 0x1
	bl ShouldAvoidEnemiesAndShowEffect
	lsls r0, 24
	cmp r0, 0
	beq _08073DC8
	ldr r0, _08073DBC
	adds r1, r5, 0
	bl sub_8045BF8
	ldr r0, _08073DC0
	adds r1, r6, 0
	movs r2, 0
	bl SetMessageArgument
	ldr r0, _08073DC4
	b _0807404C
	.align 2, 0
_08073DBC: .4byte gUnknown_202DE58
_08073DC0: .4byte gAvailablePokemonNames
_08073DC4: .4byte gUnknown_80F8F88
_08073DC8:
	mov r1, r10
	ldrb r0, [r1, 0x6]
	cmp r0, 0
	bne _08073E24
	ldrb r0, [r5, 0x2]
	bl GetItemType
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x6
	bne _08073E24
	mov r7, r10
	ldrb r0, [r7, 0x6]
	cmp r0, 0
	beq _08073DF4
	ldr r0, _08073DF0
	bl PlaySoundEffect
	b _08073DFC
	.align 2, 0
_08073DF0: .4byte 0x0000014b
_08073DF4:
	movs r0, 0xA6
	lsls r0, 1
	bl PlaySoundEffect
_08073DFC:
	adds r0, r5, 0
	bl GetMoneyValue
	bl AddToTeamMoney
	ldr r0, _08073E1C
	adds r1, r5, 0
	bl sub_8045BF8
	adds r0, r6, 0x4
	movs r1, 0x1
	bl sub_80461C8
	ldr r0, _08073E20
	b _0807404C
	.align 2, 0
_08073E1C: .4byte gUnknown_202DE58
_08073E20: .4byte gUnknown_80F9054
_08073E24:
	ldr r0, _08073E64
	ldr r0, [r0]
	ldr r1, _08073E68
	adds r0, r1
	ldrb r0, [r0]
	cmp r0, 0
	beq _08073E70
	mov r7, r10
	ldrb r0, [r7, 0x6]
	cmp r0, 0
	bne _08073E70
	movs r4, 0
	add r2, sp, 0x54
	adds r7, 0x60
	ldr r0, _08073E6C
	mov r1, sp
	ldr r0, [r0]
	adds r3, r2, 0
_08073E48:
	stm r3!, {r0}
	stm r1!, {r4}
	adds r0, 0x4
	adds r4, 0x1
	cmp r4, 0x13
	ble _08073E48
	str r7, [r2, 0x50]
	movs r0, 0x1
	negs r0, r0
	str r0, [sp, 0x50]
	movs r0, 0x15
	mov r8, r0
	b _08073E80
	.align 2, 0
_08073E64: .4byte gDungeonGlobalData
_08073E68: .4byte 0x0000065b
_08073E6C: .4byte gTeamInventory_203B460
_08073E70:
	mov r0, r10
	adds r0, 0x60
	str r0, [sp, 0x54]
	movs r0, 0x1
	negs r0, r0
	str r0, [sp]
	movs r1, 0x1
	mov r8, r1
_08073E80:
	ldrb r0, [r5, 0x2]
	add r7, sp, 0xA8
	strb r0, [r7]
	adds r0, r7, 0
	ldrb r0, [r0]
	cmp r0, 0x8
	bls _08073E90
	b _08073FA8
_08073E90:
	ldrb r1, [r5]
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	beq _08073E9C
	b _08073FA8
_08073E9C:
	movs r1, 0x1
	negs r1, r1
	mov r12, r1
	mov r7, r12
	str r7, [sp, 0xAC]
	movs r4, 0
	cmp r4, r8
	bge _08073EEC
	ldr r0, _08073F94
	mov r9, r0
	add r3, sp, 0x54
_08073EB2:
	ldr r2, [r3]
	ldrb r1, [r2]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _08073EE4
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	bne _08073EE4
	ldr r1, [r5]
	mov r7, r9
	ands r1, r7
	ldr r0, [r2]
	ands r0, r7
	cmp r1, r0
	bne _08073EE4
	ldrb r0, [r2, 0x1]
	cmp r0, 0x63
	beq _08073EE4
	ldr r1, [sp, 0xAC]
	cmp r1, r0
	bge _08073EE4
	str r0, [sp, 0xAC]
	mov r12, r4
_08073EE4:
	adds r3, 0x4
	adds r4, 0x1
	cmp r4, r8
	blt _08073EB2
_08073EEC:
	movs r0, 0x1
	negs r0, r0
	cmp r12, r0
	bne _08073F40
	mov r7, r12
	str r7, [sp, 0xAC]
	movs r4, 0
	cmp r4, r8
	bge _08073F38
	add r0, sp, 0xA8
	ldrb r0, [r0]
	mov r9, r0
	add r3, sp, 0x54
_08073F06:
	ldr r2, [r3]
	ldrb r1, [r2]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _08073F30
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	bne _08073F30
	ldrb r1, [r2, 0x2]
	cmp r9, r1
	bne _08073F30
	ldrb r0, [r2, 0x1]
	cmp r0, 0x63
	beq _08073F30
	ldr r7, [sp, 0xAC]
	cmp r7, r0
	bge _08073F30
	str r0, [sp, 0xAC]
	mov r12, r4
_08073F30:
	adds r3, 0x4
	adds r4, 0x1
	cmp r4, r8
	blt _08073F06
_08073F38:
	movs r0, 0x1
	negs r0, r0
	cmp r12, r0
	beq _08073FA8
_08073F40:
	add r0, sp, 0x54
	mov r1, r12
	lsls r4, r1, 2
	adds r3, r0, r4
	ldr r2, [r3]
	ldrb r1, [r2, 0x1]
	ldrb r0, [r5, 0x1]
	adds r1, r0
	cmp r1, 0x62
	ble _08073F56
	movs r1, 0x63
_08073F56:
	strb r1, [r2, 0x1]
	ldrb r1, [r5]
	movs r0, 0x8
	ands r0, r1
	cmp r0, 0
	beq _08073F6C
	ldr r0, [r3]
	ldrb r1, [r0]
	movs r2, 0x8
	orrs r1, r2
	strb r1, [r0]
_08073F6C:
	ldr r0, _08073F98
	adds r1, r5, 0
	bl sub_8045BF8
	adds r0, r6, 0x4
	movs r1, 0x1
	bl sub_80461C8
	movs r0, 0xA5
	lsls r0, 1
	bl PlaySoundEffect
	mov r7, sp
	adds r0, r7, r4
	ldr r0, [r0]
	cmp r0, 0
	bge _08073FA0
	ldr r0, _08073F9C
	b _0807404C
	.align 2, 0
_08073F94: .4byte 0x00ff0008
_08073F98: .4byte gUnknown_202DE58
_08073F9C: .4byte gUnknown_80F9018
_08073FA0:
	ldr r0, _08073FA4
	b _0807404C
	.align 2, 0
_08073FA4: .4byte gUnknown_80F9050
_08073FA8:
	movs r4, 0
	cmp r4, r8
	bge _08073FD2
	ldr r0, [sp, 0x54]
	ldrb r1, [r0]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _08073FD2
	movs r3, 0x1
	add r2, sp, 0x54
_08073FBE:
	adds r2, 0x4
	adds r4, 0x1
	cmp r4, r8
	bge _08073FD2
	ldr r0, [r2]
	ldrb r1, [r0]
	adds r0, r3, 0
	ands r0, r1
	cmp r0, 0
	bne _08073FBE
_08073FD2:
	cmp r4, r8
	bne _08073FEC
	ldr r0, _08073FE4
	adds r1, r5, 0
	bl sub_8045BF8
	ldr r0, _08073FE8
	b _0807404C
	.align 2, 0
_08073FE4: .4byte gUnknown_202DE58
_08073FE8: .4byte gUnknown_80F8F54
_08073FEC:
	mov r1, r10
	ldrb r0, [r1, 0x6]
	cmp r0, 0
	beq _08074000
	ldr r0, _08073FFC
	bl PlaySoundEffect
	b _08074008
	.align 2, 0
_08073FFC: .4byte 0x0000014b
_08074000:
	movs r0, 0xA5
	lsls r0, 1
	bl PlaySoundEffect
_08074008:
	lsls r0, r4, 2
	add r0, sp
	ldr r0, [r0]
	cmp r0, 0
	bge _08074034
	ldr r0, [r5]
	mov r7, r10
	str r0, [r7, 0x60]
	ldr r0, _0807402C
	adds r1, r5, 0
	bl sub_8045BF8
	adds r0, r6, 0x4
	movs r1, 0x1
	bl sub_80461C8
	ldr r0, _08074030
	b _0807404C
	.align 2, 0
_0807402C: .4byte gUnknown_202DE58
_08074030: .4byte gUnknown_80F9018
_08074034:
	adds r0, r5, 0
	bl AddItemToInventory
	lsls r0, 24
	cmp r0, 0
	beq _08074060
	ldr r0, _08074058
	adds r1, r6, 0
	movs r2, 0
	bl SetMessageArgument
	ldr r0, _0807405C
_0807404C:
	ldr r1, [r0]
	adds r0, r6, 0
	bl sub_805239C
	b _0807407A
	.align 2, 0
_08074058: .4byte gAvailablePokemonNames
_0807405C: .4byte gUnknown_80F8FAC
_08074060:
	ldr r0, _0807408C
	adds r1, r5, 0
	bl sub_8045BF8
	adds r0, r6, 0x4
	movs r1, 0x1
	bl sub_80461C8
	ldr r0, _08074090
	ldr r1, [r0]
	adds r0, r6, 0
	bl sub_805239C
_0807407A:
	add sp, 0xB0
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_0807408C: .4byte gUnknown_202DE58
_08074090: .4byte gUnknown_80F9050
	thumb_func_end sub_8073D14

	thumb_func_start sub_8074094
sub_8074094:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x30
	adds r5, r0, 0
	cmp r5, 0
	bne _080740AA
	bl _08074B2E
_080740AA:
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	bne _080740B8
	bl _08074B2E
_080740B8:
	bl sub_8044B28
	lsls r0, 24
	lsrs r6, r0, 24
	cmp r6, 0
	beq _080740C8
	bl _08074B2E
_080740C8:
	ldr r0, [r5, 0x70]
	mov r8, r0
	movs r0, 0xA3
	lsls r0, 1
	add r0, r8
	strb r6, [r0]
	bl sub_805229C
	adds r0, r5, 0
	bl sub_807E8F0
	adds r0, r5, 0
	movs r1, 0x16
	bl HasItem
	lsls r0, 24
	cmp r0, 0
	beq _08074170
	ldr r4, _0807434C
	add r4, r8
	ldrb r0, [r4]
	adds r0, 0x1
	strb r0, [r4]
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x13
	bls _08074102
	movs r0, 0x13
	strb r0, [r4]
_08074102:
	movs r0, 0x64
	bl DungeonRandomCapped
	ldr r2, _08074350
	ldrb r1, [r4]
	lsls r1, 1
	adds r1, r2
	movs r2, 0
	ldrsh r1, [r1, r2]
	cmp r0, r1
	bge _08074170
	strb r6, [r4]
	adds r0, r5, 0
	bl sub_80444F4
	movs r0, 0
	bl UseAttack
	adds r0, r5, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	bne _08074136
	bl _08074B2E
_08074136:
	bl sub_8044B28
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0
	beq _08074146
	bl _08074B2E
_08074146:
	adds r0, r5, 0
	adds r1, r5, 0
	movs r2, 0
	movs r3, 0
	bl sub_807D148
	mov r3, r8
	ldrb r0, [r3, 0x7]
	cmp r0, 0
	bne _0807415C
	b _080743B0
_0807415C:
	ldr r1, _08074354
	ldr r0, [r1]
	strb r4, [r0, 0x1]
	ldr r0, [r1]
	movs r4, 0xB8
	lsls r4, 3
	adds r0, r4
	movs r1, 0x1
	negs r1, r1
	str r1, [r0]
_08074170:
	mov r1, r8
	ldrb r0, [r1, 0x7]
	cmp r0, 0
	bne _0807417A
	b _080743B0
_0807417A:
	movs r2, 0
	mov r9, r2
	movs r4, 0xA
	adds r0, r5, 0
	movs r1, 0x17
	bl HasItem
	lsls r0, 24
	cmp r0, 0
	beq _08074190
	movs r4, 0
_08074190:
	adds r0, r5, 0
	movs r1, 0x1F
	bl HasItem
	lsls r0, 24
	cmp r0, 0
	beq _080741A0
	subs r4, 0x1
_080741A0:
	adds r0, r5, 0
	movs r1, 0x10
	bl HasIQSkill
	lsls r0, 24
	cmp r0, 0
	beq _080741B0
	subs r4, 0x1
_080741B0:
	adds r0, r5, 0
	movs r1, 0x1B
	bl HasItem
	lsls r0, 24
	cmp r0, 0
	beq _080741C0
	adds r4, 0x1
_080741C0:
	adds r0, r5, 0
	movs r1, 0xA
	bl HasItem
	lsls r0, 24
	cmp r0, 0
	beq _080741D0
	adds r4, 0x1
_080741D0:
	adds r0, r5, 0
	movs r1, 0x2B
	bl HasItem
	lsls r0, 24
	cmp r0, 0
	beq _080741E0
	adds r4, 0x1
_080741E0:
	cmp r4, 0
	bge _080741E6
	movs r4, 0
_080741E6:
	cmp r4, 0x13
	ble _080741EC
	movs r4, 0x13
_080741EC:
	mov r3, r9
	str r3, [sp, 0x8]
	ldr r0, _08074358
	str r0, [sp, 0xC]
	add r6, sp, 0x10
	lsls r2, r4, 3
	ldr r0, _0807435C
	adds r2, r0
	adds r0, r6, 0
	add r1, sp, 0x8
	bl sub_800A34C
	ldr r2, _08074360
	add r2, r8
	ldrb r0, [r2]
	cmp r0, 0x1
	bls _0807421E
	ldr r1, _08074364
	lsls r0, 2
	adds r0, r1
	ldr r1, [r0]
	lsls r1, 16
	ldr r0, [r6, 0x4]
	adds r0, r1
	str r0, [r6, 0x4]
_0807421E:
	mov r4, r9
	strb r4, [r2]
	movs r4, 0x9E
	lsls r4, 1
	add r4, r8
	ldr r7, [r4]
	add r0, sp, 0x18
	adds r1, r6, 0
	bl sub_80943A8
	ldr r2, [sp, 0x18]
	add r0, sp, 0x1C
	adds r1, r7, 0
	bl sub_80942C0
	ldr r0, [sp, 0x1C]
	str r0, [r4]
	movs r6, 0x1
	adds r0, r7, 0
	bl RoundUpFixedPoint
	cmp r0, 0x13
	ble _0807425C
	ldr r0, [r4]
	bl RoundUpFixedPoint
	cmp r0, 0x13
	bgt _0807425C
	ldr r0, _08074368
	ldr r0, [r0]
	mov r9, r0
_0807425C:
	adds r0, r7, 0
	bl RoundUpFixedPoint
	cmp r0, 0x9
	ble _0807427C
	movs r0, 0x9E
	lsls r0, 1
	add r0, r8
	ldr r0, [r0]
	bl RoundUpFixedPoint
	cmp r0, 0x9
	bgt _0807427C
	ldr r0, _0807436C
	ldr r0, [r0]
	mov r9, r0
_0807427C:
	movs r4, 0x9E
	lsls r4, 1
	add r4, r8
	ldr r0, [r4]
	bl RoundUpFixedPoint
	cmp r0, 0
	bne _08074298
	add r0, sp, 0x20
	movs r1, 0
	bl sub_80943A0
	ldr r0, [sp, 0x20]
	str r0, [r4]
_08074298:
	ldr r0, [r4]
	bl RoundUpFixedPoint
	cmp r0, 0
	bge _080742AE
	add r0, sp, 0x24
	movs r1, 0
	bl sub_80943A0
	ldr r0, [sp, 0x24]
	str r0, [r4]
_080742AE:
	ldr r0, [r4]
	bl RoundUpFixedPoint
	cmp r0, 0
	bne _08074384
	bl sub_805E804
	adds r0, r5, 0
	bl sub_80444F4
	movs r0, 0
	bl UseAttack
	adds r0, r5, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	bne _080742D8
	bl _08074B2E
_080742D8:
	bl sub_8044B28
	lsls r0, 24
	cmp r0, 0
	beq _080742E6
	bl _08074B2E
_080742E6:
	ldr r3, _08074354
	ldr r0, [r3]
	ldr r2, _08074370
	adds r1, r0, r2
	ldrb r0, [r1]
	cmp r0, 0x9
	bhi _080742F8
	adds r0, 0x1
	strb r0, [r1]
_080742F8:
	ldr r0, [r3]
	adds r0, r2
	ldrb r2, [r0]
	cmp r2, 0x1
	bne _08074308
	ldr r0, _08074374
	ldr r0, [r0]
	mov r9, r0
_08074308:
	cmp r2, 0x2
	bne _08074314
	ldr r0, _08074378
	ldr r0, [r0]
	mov r9, r0
	movs r6, 0
_08074314:
	cmp r2, 0x3
	bne _08074320
	ldr r0, _0807437C
	ldr r0, [r0]
	mov r9, r0
	movs r6, 0
_08074320:
	adds r0, r5, 0
	adds r1, r5, 0
	bl sub_807A96C
	ldr r3, _08074380
	adds r0, r5, 0
	movs r1, 0x1
	movs r2, 0xE
	bl sub_806F324
	movs r1, 0xA3
	lsls r1, 1
	add r1, r8
	movs r0, 0x1
	strb r0, [r1]
	ldr r0, [r4]
	bl RoundUpFixedPoint
	cmp r0, 0
	beq _08074390
	b _080743B0
	.align 2, 0
_0807434C: .4byte 0x00000169
_08074350: .4byte gWarpScarfActivationChances
_08074354: .4byte gDungeonGlobalData
_08074358: .4byte 0x0000199a
_0807435C: .4byte gUnknown_80F54F4
_08074360: .4byte 0x00000153
_08074364: .4byte gUnknown_80F60DC
_08074368: .4byte gUnknown_80FD594
_0807436C: .4byte gUnknown_80FD5B8
_08074370: .4byte 0x00000679
_08074374: .4byte gUnknown_80FD5DC
_08074378: .4byte gUnknown_80FD608
_0807437C: .4byte gUnknown_80FD628
_08074380: .4byte 0x00000211
_08074384:
	ldr r0, _08074408
	ldr r0, [r0]
	ldr r1, _0807440C
	adds r0, r1
	movs r1, 0
	strb r1, [r0]
_08074390:
	mov r2, r9
	cmp r2, 0
	beq _080743B0
	cmp r6, 0
	beq _080743A0
	ldr r0, _08074410
	bl PlaySoundEffect
_080743A0:
	adds r0, r5, 0
	mov r1, r9
	bl SendMessage
	movs r0, 0x1E
	movs r1, 0x32
	bl sub_803E708
_080743B0:
	adds r0, r5, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	bne _080743BE
	b _08074B2E
_080743BE:
	bl sub_8044B28
	lsls r0, 24
	cmp r0, 0
	beq _080743CA
	b _08074B2E
_080743CA:
	ldr r0, _08074408
	ldr r0, [r0]
	ldr r3, _08074414
	adds r0, r3
	ldrb r0, [r0]
	cmp r0, 0
	bne _08074480
	adds r0, r5, 0
	bl GetWeather
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x5
	bne _0807441C
	adds r0, r5, 0
	movs r1, 0x6
	bl HasType
	lsls r0, 24
	cmp r0, 0
	bne _08074466
	ldr r0, _08074418
	movs r4, 0
	ldrsh r1, [r0, r4]
	movs r3, 0x88
	lsls r3, 2
	adds r0, r5, 0
	movs r2, 0x12
	bl sub_806F324
	b _08074466
	.align 2, 0
_08074408: .4byte gDungeonGlobalData
_0807440C: .4byte 0x00000679
_08074410: .4byte 0x00000153
_08074414: .4byte 0x0000e266
_08074418: .4byte gUnknown_80F4F8E
_0807441C:
	adds r0, r5, 0
	bl GetWeather
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x2
	bne _08074466
	adds r0, r5, 0
	movs r1, 0x9
	bl HasType
	lsls r0, 24
	cmp r0, 0
	bne _08074466
	adds r0, r5, 0
	movs r1, 0xD
	bl HasType
	lsls r0, 24
	cmp r0, 0
	bne _08074466
	adds r0, r5, 0
	movs r1, 0x11
	bl HasType
	lsls r0, 24
	cmp r0, 0
	bne _08074466
	ldr r0, _08074608
	movs r2, 0
	ldrsh r1, [r0, r2]
	movs r3, 0x88
	lsls r3, 2
	adds r0, r5, 0
	movs r2, 0x12
	bl sub_806F324
_08074466:
	adds r0, r5, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	bne _08074474
	b _08074B2E
_08074474:
	bl sub_8044B28
	lsls r0, 24
	cmp r0, 0
	beq _08074480
	b _08074B2E
_08074480:
	movs r0, 0x64
	bl DungeonRandomCapped
	adds r4, r0, 0
	adds r0, r5, 0
	movs r1, 0x21
	bl HasAbility
	lsls r0, 24
	cmp r0, 0
	beq _080744D8
	ldr r0, _0807460C
	movs r3, 0
	ldrsh r0, [r0, r3]
	cmp r4, r0
	bge _080744D8
	adds r0, r5, 0
	bl HasNegativeStatus
	lsls r0, 24
	cmp r0, 0
	beq _080744D8
	movs r0, 0
	bl UseAttack
	adds r0, r5, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	bne _080744C0
	b _08074B2E
_080744C0:
	bl sub_8044B28
	lsls r0, 24
	cmp r0, 0
	beq _080744CC
	b _08074B2E
_080744CC:
	adds r0, r5, 0
	adds r1, r5, 0
	movs r2, 0x1
	movs r3, 0
	bl sub_8079F20
_080744D8:
	adds r0, r5, 0
	movs r1, 0xB
	bl HasAbility
	lsls r0, 24
	cmp r0, 0
	beq _0807450C
	ldr r2, _08074610
	add r2, r8
	ldrb r0, [r2]
	adds r0, 0x1
	strb r0, [r2]
	ldrb r1, [r2]
	ldr r0, _08074614
	movs r4, 0
	ldrsh r0, [r0, r4]
	cmp r1, r0
	blt _0807450C
	movs r0, 0
	strb r0, [r2]
	adds r0, r5, 0
	adds r1, r5, 0
	movs r2, 0x7F
	movs r3, 0
	bl RaiseMovementSpeedTarget
_0807450C:
	mov r0, r8
	adds r0, 0xA8
	ldrb r0, [r0]
	cmp r0, 0x4
	bne _0807453C
	movs r0, 0
	bl UseAttack
	adds r0, r5, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	bne _0807452A
	b _08074B2E
_0807452A:
	bl sub_8044B28
	lsls r0, 24
	cmp r0, 0
	beq _08074536
	b _08074B2E
_08074536:
	adds r0, r5, 0
	bl sub_80420B8
_0807453C:
	mov r0, r8
	adds r0, 0xAC
	ldrb r1, [r0]
	adds r6, r0, 0
	cmp r1, 0x1
	bne _080745B6
	mov r4, r8
	adds r4, 0xAE
	ldrb r0, [r4]
	cmp r0, 0
	beq _0807455C
	subs r0, 0x1
	strb r0, [r4]
	lsls r0, 24
	cmp r0, 0
	bne _0807459C
_0807455C:
	movs r0, 0
	bl UseAttack
	adds r0, r5, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	bne _08074570
	b _08074B2E
_08074570:
	bl sub_8044B28
	lsls r0, 24
	cmp r0, 0
	beq _0807457C
	b _08074B2E
_0807457C:
	ldr r0, _08074618
	ldrh r0, [r0]
	strb r0, [r4]
	adds r0, r5, 0
	adds r1, r5, 0
	bl sub_807A96C
	ldr r0, _0807461C
	movs r2, 0
	ldrsh r1, [r0, r2]
	movs r3, 0x82
	lsls r3, 2
	adds r0, r5, 0
	movs r2, 0x1
	bl sub_806F324
_0807459C:
	adds r0, r5, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	bne _080745AA
	b _08074B2E
_080745AA:
	bl sub_8044B28
	lsls r0, 24
	cmp r0, 0
	beq _080745B6
	b _08074B2E
_080745B6:
	ldrb r0, [r6]
	cmp r0, 0x2
	bne _08074628
	mov r4, r8
	adds r4, 0xAE
	ldrb r0, [r4]
	cmp r0, 0
	beq _080745D0
	subs r0, 0x1
	strb r0, [r4]
	lsls r0, 24
	cmp r0, 0
	bne _08074696
_080745D0:
	movs r0, 0
	bl UseAttack
	adds r0, r5, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	bne _080745E4
	b _08074B2E
_080745E4:
	bl sub_8044B28
	lsls r0, 24
	cmp r0, 0
	beq _080745F0
	b _08074B2E
_080745F0:
	ldr r0, _08074620
	ldrh r0, [r0]
	strb r0, [r4]
	adds r0, r5, 0
	adds r1, r5, 0
	bl sub_807A96C
	ldr r0, _08074624
	movs r3, 0
	ldrsh r1, [r0, r3]
	b _0807468C
	.align 2, 0
_08074608: .4byte gUnknown_80F4F8E
_0807460C: .4byte gUnknown_80F4E0C
_08074610: .4byte 0x00000113
_08074614: .4byte gUnknown_80F4F30
_08074618: .4byte gUnknown_80F4F32
_0807461C: .4byte gUnknown_80F4F70
_08074620: .4byte gUnknown_80F4F34
_08074624: .4byte gUnknown_80F4F72
_08074628:
	cmp r0, 0x3
	bne _080746B0
	mov r2, r8
	adds r2, 0xAE
	ldrb r0, [r2]
	cmp r0, 0
	beq _08074640
	subs r0, 0x1
	strb r0, [r2]
	lsls r0, 24
	cmp r0, 0
	bne _08074696
_08074640:
	mov r1, r8
	adds r1, 0xAF
	ldrb r4, [r1]
	cmp r4, 0x1C
	bhi _0807464E
	adds r0, r4, 0x1
	strb r0, [r1]
_0807464E:
	ldr r0, _08074718
	ldrh r0, [r0]
	strb r0, [r2]
	cmp r4, 0x1C
	ble _0807465A
	movs r4, 0x1D
_0807465A:
	movs r0, 0
	bl UseAttack
	adds r0, r5, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	bne _0807466E
	b _08074B2E
_0807466E:
	bl sub_8044B28
	lsls r0, 24
	cmp r0, 0
	beq _0807467A
	b _08074B2E
_0807467A:
	adds r0, r5, 0
	adds r1, r5, 0
	bl sub_807A96C
	ldr r1, _0807471C
	lsls r0, r4, 1
	adds r0, r1
	movs r4, 0
	ldrsh r1, [r0, r4]
_0807468C:
	ldr r3, _08074720
	adds r0, r5, 0
	movs r2, 0x3
	bl sub_806F324
_08074696:
	adds r0, r5, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	bne _080746A4
	b _08074B2E
_080746A4:
	bl sub_8044B28
	lsls r0, 24
	cmp r0, 0
	beq _080746B0
	b _08074B2E
_080746B0:
	mov r0, r8
	adds r0, 0xB0
	ldrb r1, [r0]
	mov r10, r0
	cmp r1, 0x7
	bne _08074730
	mov r4, r8
	adds r4, 0xB9
	ldrb r0, [r4]
	cmp r0, 0
	beq _080746D0
	subs r0, 0x1
	strb r0, [r4]
	lsls r0, 24
	cmp r0, 0
	bne _08074786
_080746D0:
	movs r0, 0
	bl UseAttack
	adds r0, r5, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	bne _080746E4
	b _08074B2E
_080746E4:
	bl sub_8044B28
	lsls r0, 24
	cmp r0, 0
	beq _080746F0
	b _08074B2E
_080746F0:
	ldr r0, _08074724
	ldrh r0, [r0]
	strb r0, [r4]
	adds r0, r5, 0
	adds r1, r5, 0
	bl sub_807A96C
	mov r0, r8
	adds r0, 0xB4
	ldr r1, [r0]
	adds r0, r5, 0
	bl sub_8041C4C
	ldr r0, _08074728
	movs r2, 0
	ldrsh r1, [r0, r2]
	ldr r3, _0807472C
	adds r0, r5, 0
	movs r2, 0x2
	b _08074782
	.align 2, 0
_08074718: .4byte gUnknown_80F4F36
_0807471C: .4byte gUnknown_80F4FC8
_08074720: .4byte 0x0000020a
_08074724: .4byte gUnknown_80F4F38
_08074728: .4byte gUnknown_80F4F74
_0807472C: .4byte 0x00000209
_08074730:
	cmp r1, 0x4
	bne _080747B0
	mov r4, r8
	adds r4, 0xB9
	ldrb r0, [r4]
	cmp r0, 0
	beq _08074748
	subs r0, 0x1
	strb r0, [r4]
	lsls r0, 24
	cmp r0, 0
	bne _08074786
_08074748:
	movs r0, 0
	bl UseAttack
	adds r0, r5, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	bne _0807475C
	b _08074B2E
_0807475C:
	bl sub_8044B28
	lsls r0, 24
	cmp r0, 0
	beq _08074768
	b _08074B2E
_08074768:
	ldr r0, _080747A4
	ldrh r0, [r0]
	strb r0, [r4]
	adds r0, r5, 0
	adds r1, r5, 0
	bl sub_807A96C
	ldr r0, _080747A8
	movs r3, 0
	ldrsh r1, [r0, r3]
	ldr r3, _080747AC
	adds r0, r5, 0
	movs r2, 0x5
_08074782:
	bl sub_806F324
_08074786:
	adds r0, r5, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	bne _08074794
	b _08074B2E
_08074794:
	bl sub_8044B28
	lsls r0, 24
	cmp r0, 0
	beq _080747A0
	b _08074B2E
_080747A0:
	b _08074802
	.align 2, 0
_080747A4: .4byte gUnknown_80F4F3A
_080747A8: .4byte gUnknown_80F4F76
_080747AC: .4byte 0x0000020b
_080747B0:
	cmp r1, 0x5
	bne _08074802
	mov r4, r8
	adds r4, 0xB9
	ldrb r0, [r4]
	cmp r0, 0
	beq _080747C8
	subs r0, 0x1
	strb r0, [r4]
	lsls r0, 24
	cmp r0, 0
	bne _08074802
_080747C8:
	movs r0, 0
	bl UseAttack
	adds r0, r5, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	bne _080747DC
	b _08074B2E
_080747DC:
	bl sub_8044B28
	lsls r0, 24
	cmp r0, 0
	beq _080747E8
	b _08074B2E
_080747E8:
	ldr r0, _080748D4
	ldrh r0, [r0]
	strb r0, [r4]
	ldr r0, _080748D8
	movs r4, 0
	ldrsh r2, [r0, r4]
	movs r0, 0x1
	str r0, [sp]
	adds r0, r5, 0
	adds r1, r5, 0
	movs r3, 0
	bl HealTargetHP
_08074802:
	mov r0, r8
	adds r0, 0xC8
	ldrb r0, [r0]
	cmp r0, 0x1
	bne _0807488A
	mov r2, r8
	adds r2, 0xCC
	ldrb r0, [r2]
	cmp r0, 0
	beq _08074820
	subs r0, 0x1
	strb r0, [r2]
	lsls r0, 24
	cmp r0, 0
	bne _08074870
_08074820:
	mov r0, r8
	movs r3, 0x10
	ldrsh r1, [r0, r3]
	cmp r1, 0
	bge _0807482C
	adds r1, 0x3
_0807482C:
	asrs r4, r1, 2
	cmp r4, 0
	bne _08074834
	movs r4, 0x1
_08074834:
	ldr r0, _080748DC
	ldrh r0, [r0]
	strb r0, [r2]
	movs r0, 0
	bl UseAttack
	adds r0, r5, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	bne _0807484E
	b _08074B2E
_0807484E:
	bl sub_8044B28
	lsls r0, 24
	cmp r0, 0
	beq _0807485A
	b _08074B2E
_0807485A:
	adds r0, r5, 0
	adds r1, r5, 0
	bl sub_807A96C
	movs r3, 0x83
	lsls r3, 2
	adds r0, r5, 0
	adds r1, r4, 0
	movs r2, 0x7
	bl sub_806F324
_08074870:
	adds r0, r5, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	bne _0807487E
	b _08074B2E
_0807487E:
	bl sub_8044B28
	lsls r0, 24
	cmp r0, 0
	beq _0807488A
	b _08074B2E
_0807488A:
	mov r3, r8
	adds r3, 0xD0
	ldrb r4, [r3]
	mov r9, r4
	cmp r4, 0x1
	beq _08074898
	b _080749AE
_08074898:
	mov r2, r8
	adds r2, 0xDA
	ldrb r0, [r2]
	cmp r0, 0
	beq _080748AC
	subs r0, 0x1
	strb r0, [r2]
	lsls r0, 24
	cmp r0, 0
	bne _08074994
_080748AC:
	ldr r0, _080748E0
	movs r1, 0
	ldrsh r6, [r0, r1]
	ldr r0, _080748E4
	ldr r1, [r0]
	mov r0, r8
	adds r0, 0xD8
	ldrb r0, [r0]
	lsls r0, 2
	ldr r4, _080748E8
	adds r1, r4
	adds r1, r0
	ldr r4, [r1]
	ldr r0, _080748EC
	ldrh r0, [r0]
	strb r0, [r2]
	cmp r4, 0
	bne _080748F0
	strb r4, [r3]
	b _08074994
	.align 2, 0
_080748D4: .4byte gUnknown_80F4F3C
_080748D8: .4byte gUnknown_80F4FB2
_080748DC: .4byte gUnknown_80F4F3E
_080748E0: .4byte gUnknown_80F4FB4
_080748E4: .4byte gDungeonGlobalData
_080748E8: .4byte 0x000135cc
_080748EC: .4byte gUnknown_80F4F40
_080748F0:
	ldr r0, [r4, 0x70]
	adds r0, 0x98
	mov r1, r8
	adds r1, 0xD4
	ldr r2, [r0]
	ldr r0, [r1]
	cmp r2, r0
	beq _08074906
	movs r0, 0
	strb r0, [r3]
	b _08074994
_08074906:
	adds r0, r5, 0
	movs r1, 0x3A
	bl HasAbility
	lsls r0, 24
	lsrs r7, r0, 24
	adds r0, r5, 0
	bl sub_80444F4
	movs r0, 0
	bl UseAttack
	adds r0, r5, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	bne _0807492C
	b _08074B2E
_0807492C:
	adds r0, r4, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	bne _0807493A
	b _08074B2E
_0807493A:
	bl sub_8044B28
	lsls r0, 24
	cmp r0, 0
	beq _08074946
	b _08074B2E
_08074946:
	mov r1, r10
	ldrb r0, [r1]
	cmp r0, 0x1
	beq _08074994
	adds r0, r5, 0
	adds r1, r5, 0
	bl sub_807A96C
	ldr r3, _08074980
	adds r0, r5, 0
	adds r1, r6, 0
	movs r2, 0x9
	bl sub_806F324
	cmp r7, 0
	beq _08074984
	adds r0, r4, 0
	adds r1, r4, 0
	bl sub_807A96C
	movs r3, 0xFD
	lsls r3, 1
	adds r0, r4, 0
	adds r1, r6, 0
	movs r2, 0xD
	bl sub_806F324
	b _08074994
	.align 2, 0
_08074980: .4byte 0x0000020d
_08074984:
	mov r2, r9
	str r2, [sp]
	adds r0, r4, 0
	adds r1, r4, 0
	adds r2, r6, 0
	movs r3, 0
	bl HealTargetHP
_08074994:
	adds r0, r5, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	bne _080749A2
	b _08074B2E
_080749A2:
	bl sub_8044B28
	lsls r0, 24
	cmp r0, 0
	beq _080749AE
	b _08074B2E
_080749AE:
	mov r4, r8
	adds r4, 0xFD
	ldrb r0, [r4]
	cmp r0, 0
	beq _08074A46
	adds r0, r4, 0
	bl sub_80838EC
	ldrb r0, [r4]
	cmp r0, 0
	bne _08074A46
	movs r0, 0
	bl UseAttack
	adds r0, r5, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	bne _080749D8
	b _08074B2E
_080749D8:
	bl sub_8044B28
	lsls r0, 24
	cmp r0, 0
	beq _080749E4
	b _08074B2E
_080749E4:
	ldr r0, _08074A18
	adds r1, r5, 0
	movs r2, 0
	bl SetMessageArgument
	ldr r0, _08074A1C
	ldr r1, [r0]
	adds r0, r5, 0
	bl SendMessage
	adds r0, r5, 0
	adds r1, r5, 0
	bl sub_807A96C
	mov r0, r8
	adds r0, 0xC4
	ldrb r0, [r0]
	cmp r0, 0x7
	bne _08074A24
	ldr r0, _08074A20
	ldr r1, [r0]
	adds r0, r5, 0
	bl SendMessage
	b _08074A30
	.align 2, 0
_08074A18: .4byte gUnknown_202DFE8
_08074A1C: .4byte gUnknown_80FEB30
_08074A20: .4byte gPtrProtectSavedItMessage
_08074A24:
	ldr r1, _08074B40
	ldr r3, _08074B44
	adds r0, r5, 0
	movs r2, 0xB
	bl sub_806F324
_08074A30:
	adds r0, r5, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	beq _08074B2E
	bl sub_8044B28
	lsls r0, 24
	cmp r0, 0
	bne _08074B2E
_08074A46:
	mov r0, r8
	adds r0, 0xC0
	ldrb r1, [r0]
	adds r7, r0, 0
	cmp r1, 0x1
	bne _08074AD4
	mov r4, r8
	adds r4, 0xC1
	adds r0, r4, 0
	bl sub_80838EC
	ldrb r0, [r4]
	cmp r0, 0
	bne _08074AD4
	strb r0, [r7]
	adds r0, r5, 0
	movs r1, 0
	bl CannotMove
	lsls r0, 24
	cmp r0, 0
	bne _08074AD4
	adds r0, r5, 0
	movs r1, 0
	bl CannotAttack
	lsls r0, 24
	cmp r0, 0
	bne _08074AD4
	adds r0, r5, 0
	bl CannotAct
	lsls r0, 24
	lsrs r6, r0, 24
	cmp r6, 0
	bne _08074AD4
	movs r0, 0
	bl UseAttack
	add r4, sp, 0x28
	ldr r1, _08074B48
	adds r0, r4, 0
	bl InitPokemonMove
	ldrb r0, [r4]
	movs r1, 0x10
	orrs r0, r1
	strb r0, [r4]
	str r6, [sp]
	str r4, [sp, 0x4]
	adds r0, r5, 0
	movs r1, 0
	movs r2, 0
	movs r3, 0
	bl sub_8055FA0
	adds r0, r5, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	beq _08074B2E
	bl sub_8044B28
	lsls r0, 24
	lsrs r1, r0, 24
	cmp r1, 0
	bne _08074B2E
	mov r0, r8
	adds r0, 0xA0
	str r1, [r0]
_08074AD4:
	adds r0, r5, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	beq _08074B2E
	bl sub_8044B28
	lsls r0, 24
	cmp r0, 0
	bne _08074B2E
	ldrb r0, [r7]
	cmp r0, 0xC
	bne _08074B1E
	mov r4, r8
	adds r4, 0xC1
	adds r0, r4, 0
	bl sub_80838EC
	ldrb r0, [r4]
	cmp r0, 0
	bne _08074B1E
	strb r0, [r7]
	movs r1, 0xA5
	lsls r1, 1
	add r1, r8
	strb r0, [r1]
	ldr r0, _08074B4C
	adds r1, r5, 0
	movs r2, 0
	bl SetMessageArgument
	ldr r0, _08074B50
	ldr r1, [r0]
	adds r0, r5, 0
	bl SendMessage
_08074B1E:
	adds r0, r5, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	beq _08074B2E
	bl sub_8044B28
_08074B2E:
	add sp, 0x30
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_08074B40: .4byte 0x0000270f
_08074B44: .4byte 0x0000020e
_08074B48: .4byte 0x00000165
_08074B4C: .4byte gAvailablePokemonNames
_08074B50: .4byte gUnknown_80FABD8
	thumb_func_end sub_8074094

	thumb_func_start TickStatusHeal
TickStatusHeal:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	adds r7, r0, 0
	cmp r7, 0
	bne _08074B62
	b _08074F96
_08074B62:
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	bne _08074B6E
	b _08074F96
_08074B6E:
	bl sub_8044B28
	lsls r0, 24
	cmp r0, 0
	beq _08074B7A
	b _08074F96
_08074B7A:
	bl sub_805229C
	ldr r6, [r7, 0x70]
	movs r1, 0xA3
	lsls r1, 1
	adds r0, r6, r1
	ldrb r0, [r0]
	cmp r0, 0
	bne _08074C48
	adds r0, r6, 0
	adds r0, 0xAC
	ldrb r0, [r0]
	cmp r0, 0x2
	beq _08074C48
	cmp r0, 0x3
	beq _08074C48
	movs r4, 0
	ldrb r0, [r6, 0x6]
	cmp r0, 0
	bne _08074BAE
	movs r2, 0x2
	ldrsh r0, [r6, r2]
	bl GetUnk1B
	lsls r0, 24
	lsrs r4, r0, 24
_08074BAE:
	cmp r4, 0
	beq _08074C48
	adds r0, r7, 0
	movs r1, 0xA
	bl HasItem
	lsls r0, 24
	cmp r0, 0
	beq _08074BC8
	ldr r0, _08074EF8
	movs r3, 0
	ldrsh r0, [r0, r3]
	adds r4, r0
_08074BC8:
	adds r0, r6, 0
	adds r0, 0xC4
	ldrb r0, [r0]
	cmp r0, 0x6
	bne _08074BDA
	ldr r0, _08074EFC
	movs r1, 0
	ldrsh r0, [r0, r1]
	adds r4, r0
_08074BDA:
	adds r0, r7, 0
	movs r1, 0x3
	bl HasAbility
	lsls r0, 24
	cmp r0, 0
	beq _08074BFE
	adds r0, r7, 0
	bl GetWeather
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x4
	bne _08074BFE
	ldr r0, _08074F00
	movs r2, 0
	ldrsh r0, [r0, r2]
	adds r4, r0
_08074BFE:
	movs r0, 0xFA
	lsls r0, 1
	cmp r4, r0
	ble _08074C08
	adds r4, r0, 0
_08074C08:
	cmp r4, 0x1D
	bgt _08074C0E
	movs r4, 0x1E
_08074C0E:
	movs r3, 0xFC
	lsls r3, 1
	adds r1, r6, r3
	ldrh r0, [r6, 0x10]
	ldrh r2, [r1]
	adds r0, r2
	strh r0, [r1]
	movs r3, 0
	ldrsh r0, [r1, r3]
	cmp r0, r4
	blt _08074C38
_08074C24:
	ldrh r0, [r6, 0xE]
	adds r0, 0x1
	strh r0, [r6, 0xE]
	ldrh r0, [r1]
	subs r0, r4
	strh r0, [r1]
	movs r2, 0
	ldrsh r0, [r1, r2]
	cmp r0, r4
	bge _08074C24
_08074C38:
	movs r3, 0xE
	ldrsh r1, [r6, r3]
	ldrh r2, [r6, 0x10]
	movs r3, 0x10
	ldrsh r0, [r6, r3]
	cmp r1, r0
	blt _08074C48
	strh r2, [r6, 0xE]
_08074C48:
	adds r0, r6, 0
	adds r0, 0xA8
	ldrb r0, [r0]
	cmp r0, 0
	beq _08074C6E
	adds r4, r6, 0
	adds r4, 0xA9
	adds r0, r4, 0
	bl sub_80838EC
	ldrb r0, [r4]
	cmp r0, 0
	bne _08074C6E
	adds r0, r7, 0
	adds r1, r7, 0
	movs r2, 0x1
	movs r3, 0x1
	bl SendSleepEndMessage
_08074C6E:
	adds r0, r7, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	bne _08074C7C
	b _08074F96
_08074C7C:
	bl sub_8044B28
	lsls r0, 24
	cmp r0, 0
	beq _08074C88
	b _08074F96
_08074C88:
	adds r0, r6, 0
	adds r0, 0xAC
	ldrb r0, [r0]
	cmp r0, 0
	beq _08074CAA
	adds r4, r6, 0
	adds r4, 0xAD
	adds r0, r4, 0
	bl sub_80838EC
	ldrb r0, [r4]
	cmp r0, 0
	bne _08074CAA
	adds r0, r7, 0
	adds r1, r7, 0
	bl SendNonVolatileEndMessage
_08074CAA:
	adds r0, r7, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	bne _08074CB8
	b _08074F96
_08074CB8:
	bl sub_8044B28
	lsls r0, 24
	cmp r0, 0
	beq _08074CC4
	b _08074F96
_08074CC4:
	adds r0, r6, 0
	adds r0, 0xB0
	ldrb r0, [r0]
	cmp r0, 0
	beq _08074CE6
	adds r4, r6, 0
	adds r4, 0xB8
	adds r0, r4, 0
	bl sub_80838EC
	ldrb r0, [r4]
	cmp r0, 0
	bne _08074CE6
	adds r0, r7, 0
	adds r1, r7, 0
	bl SendImmobilizeEndMessage
_08074CE6:
	adds r0, r7, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	bne _08074CF4
	b _08074F96
_08074CF4:
	bl sub_8044B28
	lsls r0, 24
	cmp r0, 0
	beq _08074D00
	b _08074F96
_08074D00:
	adds r0, r6, 0
	adds r0, 0xBC
	ldrb r0, [r0]
	cmp r0, 0
	beq _08074D22
	adds r4, r6, 0
	adds r4, 0xBD
	adds r0, r4, 0
	bl sub_80838EC
	ldrb r0, [r4]
	cmp r0, 0
	bne _08074D22
	adds r0, r7, 0
	adds r1, r7, 0
	bl SendVolatileEndMessage
_08074D22:
	adds r0, r7, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	bne _08074D30
	b _08074F96
_08074D30:
	bl sub_8044B28
	lsls r0, 24
	cmp r0, 0
	beq _08074D3C
	b _08074F96
_08074D3C:
	adds r0, r6, 0
	adds r0, 0xC4
	ldrb r0, [r0]
	cmp r0, 0
	beq _08074D5E
	adds r4, r6, 0
	adds r4, 0xC5
	adds r0, r4, 0
	bl sub_80838EC
	ldrb r0, [r4]
	cmp r0, 0
	bne _08074D5E
	adds r0, r7, 0
	adds r1, r7, 0
	bl SendProtectionEndMessage
_08074D5E:
	adds r0, r7, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	bne _08074D6C
	b _08074F96
_08074D6C:
	bl sub_8044B28
	lsls r0, 24
	cmp r0, 0
	beq _08074D78
	b _08074F96
_08074D78:
	adds r0, r6, 0
	adds r0, 0xC8
	ldrb r0, [r0]
	cmp r0, 0
	beq _08074D9C
	adds r4, r6, 0
	adds r4, 0xCB
	adds r0, r4, 0
	bl sub_80838EC
	ldrb r0, [r4]
	cmp r0, 0
	bne _08074D9C
	adds r0, r7, 0
	adds r1, r7, 0
	movs r2, 0
	bl SendWaitingEndMessage
_08074D9C:
	adds r0, r7, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	bne _08074DAA
	b _08074F96
_08074DAA:
	bl sub_8044B28
	lsls r0, 24
	cmp r0, 0
	beq _08074DB6
	b _08074F96
_08074DB6:
	adds r0, r6, 0
	adds r0, 0xD0
	ldrb r0, [r0]
	cmp r0, 0
	beq _08074DD8
	adds r4, r6, 0
	adds r4, 0xD9
	adds r0, r4, 0
	bl sub_80838EC
	ldrb r0, [r4]
	cmp r0, 0
	bne _08074DD8
	adds r0, r7, 0
	adds r1, r7, 0
	bl SendLinkedEndMessage
_08074DD8:
	adds r0, r7, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	bne _08074DE6
	b _08074F96
_08074DE6:
	bl sub_8044B28
	lsls r0, 24
	cmp r0, 0
	beq _08074DF2
	b _08074F96
_08074DF2:
	adds r0, r6, 0
	adds r0, 0xDC
	ldrb r0, [r0]
	cmp r0, 0
	beq _08074E14
	adds r4, r6, 0
	adds r4, 0xDD
	adds r0, r4, 0
	bl sub_80838EC
	ldrb r0, [r4]
	cmp r0, 0
	bne _08074E14
	adds r0, r7, 0
	adds r1, r7, 0
	bl SendMoveEndMessage
_08074E14:
	adds r0, r7, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	bne _08074E22
	b _08074F96
_08074E22:
	bl sub_8044B28
	lsls r0, 24
	cmp r0, 0
	beq _08074E2E
	b _08074F96
_08074E2E:
	adds r0, r6, 0
	adds r0, 0xE4
	ldrb r0, [r0]
	cmp r0, 0
	beq _08074E50
	adds r4, r6, 0
	adds r4, 0xE5
	adds r0, r4, 0
	bl sub_80838EC
	ldrb r0, [r4]
	cmp r0, 0
	bne _08074E50
	adds r0, r7, 0
	adds r1, r7, 0
	bl SendTransformEndMessage
_08074E50:
	adds r0, r7, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	bne _08074E5E
	b _08074F96
_08074E5E:
	bl sub_8044B28
	lsls r0, 24
	cmp r0, 0
	beq _08074E6A
	b _08074F96
_08074E6A:
	adds r0, r6, 0
	adds r0, 0xE8
	ldrb r0, [r0]
	cmp r0, 0
	beq _08074E8C
	adds r4, r6, 0
	adds r4, 0xE9
	adds r0, r4, 0
	bl sub_80838EC
	ldrb r0, [r4]
	cmp r0, 0
	bne _08074E8C
	adds r0, r7, 0
	adds r1, r7, 0
	bl SendEyesightEndMessage
_08074E8C:
	adds r0, r7, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	bne _08074E9A
	b _08074F96
_08074E9A:
	bl sub_8044B28
	lsls r0, 24
	cmp r0, 0
	bne _08074F96
	adds r0, r6, 0
	adds r0, 0xEC
	ldrb r0, [r0]
	cmp r0, 0
	beq _08074EC6
	adds r4, r6, 0
	adds r4, 0xED
	adds r0, r4, 0
	bl sub_80838EC
	ldrb r0, [r4]
	cmp r0, 0
	bne _08074EC6
	adds r0, r7, 0
	adds r1, r7, 0
	bl SendMuzzledEndMessage
_08074EC6:
	adds r0, r7, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	beq _08074F96
	bl sub_8044B28
	lsls r0, 24
	cmp r0, 0
	bne _08074F96
	adds r4, r6, 0
	adds r4, 0xFA
	ldrb r0, [r4]
	cmp r0, 0
	beq _08074F18
	adds r0, r4, 0
	bl sub_80838EC
	ldrb r0, [r4]
	cmp r0, 0
	bne _08074F18
	ldr r0, _08074F04
	adds r1, r7, 0
	b _08074F08
	.align 2, 0
_08074EF8: .4byte gUnknown_80F4FC4
_08074EFC: .4byte gUnknown_80F4FC0
_08074F00: .4byte gUnknown_80F4FC2
_08074F04: .4byte gAvailablePokemonNames
_08074F08:
	movs r2, 0
	bl SetMessageArgument
	ldr r0, _08074FA0
	ldr r1, [r0]
	adds r0, r7, 0
	bl SendMessage
_08074F18:
	movs r0, 0
	mov r8, r0
	movs r5, 0
_08074F1E:
	ldr r1, _08074FA4
	adds r0, r6, r1
	adds r4, r0, r5
	ldrb r0, [r4]
	cmp r0, 0
	beq _08074F3C
	adds r0, r5, r1
	adds r0, r6, r0
	bl sub_80838EC
	ldrb r0, [r4]
	cmp r0, 0
	bne _08074F3C
	movs r2, 0x1
	mov r8, r2
_08074F3C:
	movs r3, 0x84
	lsls r3, 1
	adds r0, r6, r3
	adds r4, r0, r5
	ldrb r0, [r4]
	cmp r0, 0
	beq _08074F5C
	adds r0, r5, r3
	adds r0, r6, r0
	bl sub_80838EC
	ldrb r0, [r4]
	cmp r0, 0
	bne _08074F5C
	movs r0, 0x1
	mov r8, r0
_08074F5C:
	adds r5, 0x1
	cmp r5, 0x4
	ble _08074F1E
	mov r1, r8
	cmp r1, 0
	beq _08074F96
	ldr r0, [r7, 0x70]
	movs r2, 0x82
	lsls r2, 1
	adds r0, r2
	ldr r4, [r0]
	adds r0, r7, 0
	bl GetMovementSpeed
	adds r5, r0, 0
	cmp r4, r5
	beq _08074F96
	ldr r0, _08074FA8
	adds r1, r7, 0
	movs r2, 0
	bl SetMessageArgument
	ldr r1, _08074FAC
	lsls r0, r5, 2
	adds r0, r1
	ldr r1, [r0]
	adds r0, r7, 0
	bl SendMessage
_08074F96:
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_08074FA0: .4byte gPtrStenchWavedOffMessage
_08074FA4: .4byte 0x0000010d
_08074FA8: .4byte gAvailablePokemonNames
_08074FAC: .4byte gUnknown_80FA124
	thumb_func_end TickStatusHeal

	thumb_func_start sub_8074FB0
sub_8074FB0:
	push {r4-r6,lr}
	adds r3, r0, 0
	adds r5, r1, 0
	ldr r4, [r3, 0x70]
	movs r1, 0xFA
	lsls r1, 1
	adds r0, r4, r1
	movs r1, 0
	ldrsh r0, [r0, r1]
	cmp r0, 0x3
	ble _08074FD0
	adds r1, r4, 0
	adds r1, 0x44
	movs r0, 0
	strh r0, [r1]
	b _08075040
_08074FD0:
	ldr r0, _08074FE0
	ldr r0, [r0]
	ldrb r0, [r0]
	cmp r0, 0
	beq _08074FE8
	ldr r1, _08074FE4
	movs r0, 0x2
	b _08074FEC
	.align 2, 0
_08074FE0: .4byte gUnknown_203B46C
_08074FE4: .4byte gUnknown_202F378
_08074FE8:
	ldr r1, _08075048
	movs r0, 0x1
_08074FEC:
	str r0, [r1]
	adds r6, r1, 0
	movs r1, 0xFA
	lsls r1, 1
	adds r0, r4, r1
	movs r1, 0
	ldrsh r0, [r0, r1]
	lsls r1, r0, 3
	subs r1, r0
	lsls r1, 2
	movs r0, 0xC2
	lsls r0, 1
	adds r1, r0
	adds r1, r4, r1
	movs r0, 0
	strb r0, [r1, 0x1A]
	str r5, [r1, 0xC]
	ldrh r0, [r3, 0x4]
	strh r0, [r1]
	ldrh r0, [r3, 0x6]
	strh r0, [r1, 0x2]
	movs r3, 0
	ldrsh r0, [r2, r3]
	str r0, [r1, 0x4]
	movs r3, 0x2
	ldrsh r0, [r2, r3]
	str r0, [r1, 0x8]
	ldr r0, _0807504C
	lsls r2, r5, 2
	adds r2, r0
	movs r5, 0
	ldrsh r0, [r2, r5]
	ldr r3, [r6]
	muls r0, r3
	str r0, [r1, 0x10]
	movs r5, 0x2
	ldrsh r0, [r2, r5]
	muls r0, r3
	str r0, [r1, 0x14]
	adds r0, r4, 0
	bl sub_8075050
_08075040:
	pop {r4-r6}
	pop {r0}
	bx r0
	.align 2, 0
_08075048: .4byte gUnknown_202F378
_0807504C: .4byte gUnknown_80F4D44
	thumb_func_end sub_8074FB0

	thumb_func_start sub_8075050
sub_8075050:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x8
	mov r9, r0
	adds r6, r1, 0
	ldr r0, _08075070
	ldr r0, [r0]
	ldrb r0, [r0]
	cmp r0, 0
	beq _08075078
	ldr r1, _08075074
	movs r0, 0x2
	b _0807507C
	.align 2, 0
_08075070: .4byte gUnknown_203B46C
_08075074: .4byte gUnknown_202F378
_08075078:
	ldr r1, _080750D0
	movs r0, 0x1
_0807507C:
	str r0, [r1]
	movs r1, 0xFA
	lsls r1, 1
	add r1, r9
	ldrh r0, [r1]
	adds r0, 0x1
	strh r0, [r1]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x2
	bne _080750D4
	ldr r0, _080750D0
	ldr r1, [r0]
	lsls r1, 1
	movs r0, 0x18
	bl __divsi3
	movs r1, 0xCE
	lsls r1, 1
	add r1, r9
	strh r0, [r1]
	movs r2, 0xCA
	lsls r2, 1
	add r2, r9
	ldr r1, [r2]
	lsls r1, 1
	str r1, [r2]
	movs r2, 0xCC
	lsls r2, 1
	add r2, r9
	ldr r1, [r2]
	lsls r1, 1
	str r1, [r2]
	strh r0, [r6, 0x18]
	ldr r0, [r6, 0x10]
	lsls r0, 1
	str r0, [r6, 0x10]
	ldr r0, [r6, 0x14]
	lsls r0, 1
	str r0, [r6, 0x14]
	b _080751F8
	.align 2, 0
_080750D0: .4byte gUnknown_202F378
_080750D4:
	cmp r0, 0x3
	bne _08075160
	ldr r1, [r6, 0x10]
	str r1, [sp]
	ldr r0, [r6, 0x14]
	str r0, [sp, 0x4]
	movs r4, 0xCE
	lsls r4, 1
	add r4, r9
	movs r5, 0
	movs r7, 0x1
_080750EA:
	ldr r1, _0807515C
	ldr r0, [r1]
	lsls r1, r0, 1
	adds r1, r0
	movs r0, 0x18
	bl __divsi3
	strh r0, [r4]
	movs r3, 0xCA
	lsls r3, 1
	add r3, r9
	adds r3, r5
	ldr r1, [r3]
	lsls r0, r1, 1
	adds r0, r1
	str r0, [r3]
	movs r2, 0xCC
	lsls r2, 1
	add r2, r9
	adds r2, r5
	ldr r1, [r2]
	lsls r0, r1, 1
	adds r0, r1
	str r0, [r2]
	ldr r0, [r3]
	lsrs r1, r0, 31
	adds r0, r1
	asrs r0, 1
	str r0, [r3]
	ldr r0, [r2]
	lsrs r1, r0, 31
	adds r0, r1
	asrs r0, 1
	str r0, [r2]
	adds r4, 0x1C
	adds r5, 0x1C
	subs r7, 0x1
	cmp r7, 0
	bge _080750EA
	ldr r1, _0807515C
	ldr r0, [r1]
	lsls r1, r0, 1
	adds r1, r0
	movs r0, 0x18
	bl __divsi3
	strh r0, [r6, 0x18]
	ldr r1, [sp]
	lsls r0, r1, 1
	adds r0, r1
	str r0, [r6, 0x10]
	ldr r1, [sp, 0x4]
	lsls r0, r1, 1
	adds r0, r1
	str r0, [r6, 0x14]
	b _080751F8
	.align 2, 0
_0807515C: .4byte gUnknown_202F378
_08075160:
	cmp r0, 0x4
	bne _080751EC
	ldr r0, [r6, 0x10]
	str r0, [sp]
	ldr r1, [r6, 0x14]
	str r1, [sp, 0x4]
	movs r7, 0xCE
	lsls r7, 1
	add r7, r9
	movs r0, 0
	mov r8, r0
	movs r1, 0x2
	mov r10, r1
_0807517A:
	ldr r0, _080751E8
	ldr r1, [r0]
	lsls r1, 2
	movs r0, 0x18
	bl __divsi3
	strh r0, [r7]
	movs r4, 0xCA
	lsls r4, 1
	add r4, r9
	add r4, r8
	ldr r0, [r4]
	lsls r0, 2
	str r0, [r4]
	movs r5, 0xCC
	lsls r5, 1
	add r5, r9
	add r5, r8
	ldr r0, [r5]
	lsls r0, 2
	str r0, [r5]
	ldr r0, [r4]
	movs r1, 0x3
	bl __divsi3
	str r0, [r4]
	ldr r0, [r5]
	movs r1, 0x3
	bl __divsi3
	str r0, [r5]
	adds r7, 0x1C
	movs r1, 0x1C
	add r8, r1
	movs r0, 0x1
	negs r0, r0
	add r10, r0
	mov r1, r10
	cmp r1, 0
	bge _0807517A
	ldr r0, _080751E8
	ldr r1, [r0]
	lsls r1, 2
	movs r0, 0x18
	bl __divsi3
	strh r0, [r6, 0x18]
	ldr r1, [sp]
	lsls r0, r1, 2
	str r0, [r6, 0x10]
	ldr r1, [sp, 0x4]
	lsls r0, r1, 2
	str r0, [r6, 0x14]
	b _080751F8
	.align 2, 0
_080751E8: .4byte gUnknown_202F378
_080751EC:
	ldr r0, _08075208
	ldr r1, [r0]
	movs r0, 0x18
	bl __divsi3
	strh r0, [r6, 0x18]
_080751F8:
	add sp, 0x8
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_08075208: .4byte gUnknown_202F378
	thumb_func_end sub_8075050

	thumb_func_start UseAttack
UseAttack:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x18
	mov r10, r0
	movs r7, 0
	movs r0, 0
	mov r9, r0
	ldr r0, _08075238
	mov r1, r9
	strb r1, [r0]
	ldr r0, _0807523C
	ldr r0, [r0]
	ldrb r0, [r0]
	cmp r0, 0
	beq _08075244
	ldr r1, _08075240
	movs r0, 0x2
	b _08075248
	.align 2, 0
_08075238: .4byte gUnknown_202F32D
_0807523C: .4byte gUnknown_203B46C
_08075240: .4byte gUnknown_202F378
_08075244:
	ldr r1, _080752D0
	movs r0, 0x1
_08075248:
	str r0, [r1]
	movs r2, 0
	mov r8, r2
_0807524E:
	ldr r0, _080752D4
	ldr r0, [r0]
	mov r3, r8
	lsls r1, r3, 2
	ldr r4, _080752D8
	adds r0, r4
	adds r0, r1
	ldr r5, [r0]
	adds r0, r5, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	beq _0807534C
	ldr r4, [r5, 0x70]
	movs r1, 0xFA
	lsls r1, 1
	adds r0, r4, r1
	movs r3, 0
	ldrsh r2, [r0, r3]
	cmp r2, 0
	bne _080752E0
	ldr r0, _080752DC
	adds r1, r4, r0
	ldrb r0, [r1]
	cmp r0, 0
	beq _0807534C
	strb r2, [r1]
	movs r1, 0xB6
	lsls r1, 1
	adds r6, r4, r1
	ldr r1, [r6]
	cmp r1, 0
	beq _0807534C
	ldr r0, [r5, 0x4]
	cmp r1, r0
	beq _0807534C
	adds r0, r5, 0
	movs r1, 0x1
	bl CannotMove
	lsls r0, 24
	cmp r0, 0
	beq _080752B2
	adds r0, r5, 0
	bl CannotAct
	lsls r0, 24
	cmp r0, 0
	bne _0807534C
_080752B2:
	adds r0, r5, 0x4
	adds r1, r6, 0
	bl CalculateFacingDir
	adds r1, r0, 0
	adds r0, r4, 0
	adds r0, 0x46
	ldrb r0, [r0]
	cmp r1, r0
	beq _0807534C
	adds r0, r5, 0
	bl sub_806CE68
	b _0807534C
	.align 2, 0
_080752D0: .4byte gUnknown_202F378
_080752D4: .4byte gDungeonGlobalData
_080752D8: .4byte 0x000135cc
_080752DC: .4byte 0x00000147
_080752E0:
	ldrh r1, [r4]
	movs r2, 0x80
	lsls r2, 6
	adds r0, r2, 0
	orrs r0, r1
	strh r0, [r4]
	movs r3, 0xC4
	lsls r3, 1
	adds r0, r4, r3
	ldr r1, [r0]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 11
	movs r1, 0xC0
	lsls r1, 4
	adds r0, r1
	str r0, [sp]
	movs r2, 0xC6
	lsls r2, 1
	adds r0, r4, r2
	ldr r1, [r0]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 11
	movs r3, 0x80
	lsls r3, 5
	adds r0, r3
	str r0, [sp, 0x4]
	adds r0, r5, 0
	mov r1, sp
	bl sub_804535C
	movs r1, 0xC8
	lsls r1, 1
	adds r0, r4, r1
	ldr r2, [r0]
	adds r0, r5, 0
	movs r1, 0
	bl sub_806CDFC
	movs r2, 0xFB
	lsls r2, 1
	adds r0, r4, r2
	movs r3, 0
	strh r3, [r0]
	movs r7, 0x1
	adds r0, r5, 0
	bl sub_8045888
	lsls r0, 24
	cmp r0, 0
	beq _0807534C
	movs r4, 0x1
	mov r9, r4
_0807534C:
	movs r0, 0x1
	add r8, r0
	mov r1, r8
	cmp r1, 0x13
	bgt _08075358
	b _0807524E
_08075358:
	cmp r7, 0
	bne _08075360
	movs r0, 0
	b _0807566C
_08075360:
	ldr r0, _08075390
	ldr r0, [r0]
	adds r1, r0, 0
	adds r1, 0xB8
	ldr r2, [r1]
	str r2, [sp, 0x10]
	mov r3, r10
	str r3, [r1]
	ldr r4, _08075394
	adds r0, r4
	ldrb r0, [r0]
	cmp r0, 0
	beq _0807537C
	b _080754AE
_0807537C:
	mov r0, r9
	cmp r0, 0
	bne _08075384
	b _080754AE
_08075384:
	movs r0, 0x35
	bl sub_80526D0
	movs r5, 0
	b _0807549E
	.align 2, 0
_08075390: .4byte gDungeonGlobalData
_08075394: .4byte 0x0000066c
_08075398:
	movs r0, 0x7
	bl sub_803E46C
	movs r1, 0
	mov r8, r1
	adds r5, 0x1
	mov r9, r5
_080753A6:
	ldr r0, _08075420
	ldr r0, [r0]
	mov r2, r8
	lsls r1, r2, 2
	ldr r3, _08075424
	adds r0, r3
	adds r0, r1
	ldr r3, [r0]
	adds r0, r3, 0
	str r3, [sp, 0x14]
	bl EntityExists
	lsls r0, 24
	ldr r3, [sp, 0x14]
	cmp r0, 0
	beq _08075492
	ldr r0, [r3, 0x70]
	adds r7, r0, 0
	movs r4, 0xFB
	lsls r4, 1
	adds r5, r7, r4
	movs r1, 0
	ldrsh r0, [r5, r1]
	lsls r1, r0, 3
	subs r1, r0
	lsls r1, 2
	movs r2, 0xC2
	lsls r2, 1
	adds r1, r2
	adds r4, r7, r1
	movs r0, 0xFA
	lsls r0, 1
	adds r6, r7, r0
	movs r1, 0
	ldrsh r0, [r6, r1]
	cmp r0, 0
	beq _08075492
	ldr r1, [r4, 0x10]
	ldr r2, [r4, 0x14]
	adds r0, r3, 0
	bl sub_804539C
	ldrh r0, [r4, 0x18]
	subs r0, 0x1
	strh r0, [r4, 0x18]
	lsls r0, 16
	asrs r2, r0, 16
	ldr r3, [sp, 0x14]
	cmp r2, 0
	bne _08075492
	ldrh r0, [r5]
	adds r0, 0x1
	strh r0, [r5]
	lsls r0, 16
	asrs r0, 16
	movs r4, 0
	ldrsh r1, [r6, r4]
	cmp r0, r1
	bne _08075428
	strh r2, [r6]
	b _08075492
	.align 2, 0
_08075420: .4byte gDungeonGlobalData
_08075424: .4byte 0x000135cc
_08075428:
	movs r0, 0
	ldrsh r1, [r5, r0]
	lsls r0, r1, 3
	subs r0, r1
	lsls r0, 2
	movs r2, 0xC4
	lsls r2, 1
	adds r1, r7, r2
	adds r1, r0
	ldr r1, [r1]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 11
	movs r4, 0xC0
	lsls r4, 4
	adds r0, r4
	str r0, [sp, 0x8]
	movs r0, 0
	ldrsh r1, [r5, r0]
	lsls r0, r1, 3
	subs r0, r1
	lsls r0, 2
	adds r2, 0x4
	adds r1, r7, r2
	adds r1, r0
	ldr r1, [r1]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 11
	movs r4, 0x80
	lsls r4, 5
	adds r0, r4
	add r1, sp, 0x8
	str r0, [r1, 0x4]
	adds r0, r3, 0
	str r3, [sp, 0x14]
	bl sub_804535C
	movs r0, 0
	ldrsh r1, [r5, r0]
	lsls r0, r1, 3
	subs r0, r1
	lsls r0, 2
	movs r2, 0xC8
	lsls r2, 1
	adds r1, r7, r2
	adds r1, r0
	ldr r2, [r1]
	ldr r3, [sp, 0x14]
	adds r0, r3, 0
	movs r1, 0
	bl sub_806CDFC
_08075492:
	movs r3, 0x1
	add r8, r3
	mov r4, r8
	cmp r4, 0x13
	ble _080753A6
	mov r5, r9
_0807549E:
	ldr r0, _08075510
	ldr r1, [r0]
	movs r0, 0x18
	bl __divsi3
	cmp r5, r0
	bge _080754AE
	b _08075398
_080754AE:
	movs r0, 0
	mov r8, r0
_080754B2:
	ldr r0, _08075514
	ldr r0, [r0]
	mov r2, r8
	lsls r1, r2, 2
	ldr r3, _08075518
	adds r0, r3
	adds r0, r1
	ldr r5, [r0]
	adds r0, r5, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	beq _080754F6
	ldr r4, [r5, 0x70]
	movs r0, 0xFA
	lsls r0, 1
	adds r1, r4, r0
	movs r0, 0
	strh r0, [r1]
	adds r0, r5, 0
	bl nullsub_97
	ldrh r0, [r4]
	movs r2, 0x80
	lsls r2, 6
	adds r1, r2, 0
	ands r0, r1
	cmp r0, 0
	beq _080754F6
	adds r0, r5, 0
	movs r1, 0
	bl sub_804535C
_080754F6:
	movs r3, 0x1
	add r8, r3
	mov r4, r8
	cmp r4, 0x13
	ble _080754B2
	bl sub_807AA30
	movs r7, 0
_08075506:
	movs r5, 0
	adds r0, r7, 0x1
	mov r8, r0
	b _08075600
	.align 2, 0
_08075510: .4byte gUnknown_202F378
_08075514: .4byte gDungeonGlobalData
_08075518: .4byte 0x000135cc
_0807551C:
	ldr r2, [r4, 0x70]
	cmp r7, 0
	bne _0807552A
	ldrb r0, [r2, 0x7]
	cmp r0, 0
	beq _080755FE
	b _08075530
_0807552A:
	ldrb r0, [r2, 0x7]
	cmp r0, 0
	bne _080755FE
_08075530:
	ldr r6, [r4, 0x4]
	ldrh r1, [r2]
	movs r3, 0x80
	lsls r3, 6
	adds r0, r3, 0
	ands r0, r1
	cmp r0, 0
	beq _080755BC
	ldr r3, _08075560
	adds r0, r3, 0
	ands r0, r1
	strh r0, [r2]
	ldrb r0, [r2, 0x7]
	cmp r0, 0
	beq _08075564
	adds r0, r4, 0x4
	bl sub_804AC20
	movs r0, 0
	bl sub_807EC28
	bl sub_805EE30
	b _0807556A
	.align 2, 0
_08075560: .4byte 0x0000dfff
_08075564:
	adds r0, r4, 0
	bl sub_8075708
_0807556A:
	adds r0, r4, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	beq _080755FE
	bl sub_8044B28
	lsls r0, 24
	cmp r0, 0
	bne _0807562A
	movs r0, 0
	bl sub_8043ED0
	adds r0, r4, 0
	bl sub_8074094
	adds r0, r4, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	beq _080755FE
	bl sub_8044B28
	lsls r0, 24
	cmp r0, 0
	bne _0807562A
	adds r0, r4, 0
	bl sub_8071DA4
	bl sub_8046D20
	ldr r0, _08075650
	ldr r0, [r0]
	ldr r1, _08075654
	adds r0, r1
	ldrb r1, [r0]
	adds r0, r4, 0
	bl sub_8075900
_080755BC:
	adds r0, r4, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	beq _080755FE
	bl sub_8044B28
	lsls r0, 24
	cmp r0, 0
	bne _0807562A
	ldr r0, [r4, 0x4]
	cmp r6, r0
	beq _080755DE
	ldr r1, _08075658
	movs r0, 0x1
	strb r0, [r1]
_080755DE:
	adds r0, r4, 0
	bl sub_806A5B8
	adds r1, r4, 0x4
	adds r0, r4, 0
	bl sub_80706A4
	lsls r0, 24
	cmp r0, 0
	beq _080755FE
	adds r0, r4, 0
	adds r1, r4, 0
	movs r2, 0
	movs r3, 0
	bl sub_807D148
_080755FE:
	adds r5, 0x1
_08075600:
	cmp r5, 0x13
	bgt _0807562A
	ldr r0, _08075650
	ldr r0, [r0]
	lsls r1, r5, 2
	ldr r2, _0807565C
	adds r0, r2
	adds r0, r1
	ldr r4, [r0]
	adds r0, r4, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	beq _080755FE
	bl sub_8044B28
	lsls r0, 24
	cmp r0, 0
	bne _0807562A
	b _0807551C
_0807562A:
	mov r7, r8
	cmp r7, 0x1
	bgt _08075632
	b _08075506
_08075632:
	bl sub_8086AC0
	bl sub_8044B28
	lsls r0, 24
	cmp r0, 0
	bne _08075660
	bl sub_8085140
	ldr r0, _08075650
	ldr r0, [r0]
	adds r0, 0xB8
	ldr r3, [sp, 0x10]
	str r3, [r0]
	b _0807566A
	.align 2, 0
_08075650: .4byte gDungeonGlobalData
_08075654: .4byte 0x00003a08
_08075658: .4byte gUnknown_202F32D
_0807565C: .4byte 0x000135cc
_08075660:
	ldr r0, _0807567C
	ldr r0, [r0]
	adds r0, 0xB8
	ldr r4, [sp, 0x10]
	str r4, [r0]
_0807566A:
	movs r0, 0x1
_0807566C:
	add sp, 0x18
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	.align 2, 0
_0807567C: .4byte gDungeonGlobalData
	thumb_func_end UseAttack

	thumb_func_start sub_8075680
sub_8075680:
	push {r4-r7,lr}
	movs r7, 0
_08075684:
	ldr r0, _080756FC
	ldr r0, [r0]
	lsls r1, r7, 2
	ldr r2, _08075700
	adds r0, r2
	adds r0, r1
	ldr r5, [r0]
	adds r0, r5, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	beq _080756EE
	ldr r6, [r5, 0x70]
	ldrb r0, [r6, 0x7]
	cmp r0, 0
	bne _080756EE
	movs r0, 0xB6
	lsls r0, 1
	adds r4, r6, r0
	ldr r1, [r4]
	cmp r1, 0
	beq _080756EE
	ldr r0, [r5, 0x4]
	cmp r1, r0
	beq _080756EE
	adds r0, r5, 0
	movs r1, 0x1
	bl CannotMove
	lsls r0, 24
	cmp r0, 0
	bne _080756EE
	adds r0, r5, 0x4
	adds r1, r4, 0
	bl CalculateFacingDir
	adds r4, r0, 0
	movs r1, 0x7
	ands r0, r1
	adds r1, r6, 0
	adds r1, 0x46
	strb r0, [r1]
	adds r0, r5, 0
	bl sub_806CEBC
	adds r1, r0, 0
	lsls r1, 24
	lsrs r1, 24
	adds r0, r5, 0
	adds r2, r4, 0
	bl sub_806CDD4
_080756EE:
	adds r7, 0x1
	cmp r7, 0x13
	ble _08075684
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_080756FC: .4byte gDungeonGlobalData
_08075700: .4byte 0x000135cc
	thumb_func_end sub_8075680

	thumb_func_start nullsub_97
nullsub_97:
	bx lr
	thumb_func_end nullsub_97

	thumb_func_start sub_8075708
sub_8075708:
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	adds r4, r0, 0
	ldr r6, [r4, 0x70]
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	beq _0807580C
	adds r0, r4, 0
	bl GetMapTileForDungeonEntity_2
	adds r5, r0, 0
	adds r0, r4, 0
	movs r1, 0xD
	bl HasIQSkill
	lsls r0, 24
	cmp r0, 0
	beq _08075752
	adds r0, r6, 0
	adds r0, 0xE4
	ldrb r0, [r0]
	cmp r0, 0x3
	beq _08075752
	adds r0, r4, 0
	movs r1, 0x9
	bl HasItem
	lsls r0, 24
	cmp r0, 0
	bne _08075752
	adds r0, r4, 0x4
	bl sub_804AE84
_08075752:
	ldr r5, [r5, 0x14]
	cmp r5, 0
	beq _0807580C
	adds r0, r5, 0
	bl GetEntityType
	cmp r0, 0x5
	bhi _0807580C
	lsls r0, 2
	ldr r1, _0807576C
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0807576C: .4byte _08075770
	.align 2, 0
_08075770:
	.4byte _0807580C
	.4byte _0807580C
	.4byte _08075788
	.4byte _08075806
	.4byte _0807580C
	.4byte _0807580C
_08075788:
	adds r0, r5, 0
	bl GetTrapData
	adds r7, r0, 0
	movs r0, 0
	mov r8, r0
	mov r9, r0
	adds r0, r4, 0
	movs r1, 0x13
	bl HasIQSkill
	lsls r0, 24
	cmp r0, 0
	beq _080757BA
	adds r1, r5, 0
	adds r1, 0x20
	ldrb r0, [r1]
	cmp r0, 0
	bne _080757BA
	movs r0, 0x1
	strb r0, [r1]
	bl sub_8049ED4
	movs r0, 0x1
	mov r9, r0
_080757BA:
	ldrb r0, [r7, 0x1]
	cmp r0, 0
	bne _080757D2
	adds r0, r5, 0
	adds r0, 0x20
	ldrb r0, [r0]
	cmp r0, 0
	beq _080757EC
	ldrb r0, [r6, 0x6]
	cmp r0, 0
	bne _080757EC
	b _080757F2
_080757D2:
	cmp r0, 0x1
	bne _080757DE
	ldrb r0, [r6, 0x6]
	cmp r0, 0
	beq _080757EC
	b _080757F2
_080757DE:
	cmp r0, 0x2
	bne _080757EC
	ldrb r0, [r6, 0x6]
	cmp r0, 0
	bne _080757EC
	movs r0, 0x1
	mov r8, r0
_080757EC:
	mov r0, r8
	cmp r0, 0
	beq _0807580C
_080757F2:
	mov r0, r9
	cmp r0, 0
	bne _0807580C
	adds r1, r4, 0x4
	adds r0, r4, 0
	movs r2, 0
	movs r3, 0x1
	bl sub_807FE9C
	b _0807580C
_08075806:
	adds r0, r4, 0
	bl sub_8073D14
_0807580C:
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_8075708

        .align 2,0
