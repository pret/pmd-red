	#include "asm/constants/gba_constants.inc"
	#include "asm/macros.inc"

	.syntax unified

	.text


	thumb_func_start sub_8043CD8
sub_8043CD8:
	push {lr}
	bl vram_related_8009804
	pop {r0}
	bx r0
	thumb_func_end sub_8043CD8

	thumb_func_start sub_8043CE4
sub_8043CE4:
	push {lr}
	adds r1, r0, 0
	ldr r0, _08043CF4
	ldrb r0, [r0]
	cmp r0, 0
	beq _08043CF8
	movs r0, 0x1
	b _08043D08
	.align 2, 0
_08043CF4: .4byte gUnknown_202F1A8
_08043CF8:
	movs r2, 0
	ldr r0, _08043D0C
	adds r0, r1, r0
	ldrb r0, [r0]
	cmp r0, 0x2
	bne _08043D06
	movs r2, 0x1
_08043D06:
	adds r0, r2, 0
_08043D08:
	pop {r1}
	bx r1
	.align 2, 0
_08043D0C: .4byte gDungeonWaterType
	thumb_func_end sub_8043CE4

	thumb_func_start sub_8043D10
sub_8043D10:
	push {lr}
	ldr r0, _08043D38
	ldr r1, [r0]
	movs r2, 0xCF
	lsls r2, 3
	adds r0, r1, r2
	ldrb r0, [r0]
	cmp r0, 0x1
	bne _08043D3C
	subs r2, 0x2B
	adds r0, r1, r2
	subs r2, 0x8
	adds r1, r2
	ldrb r0, [r0]
	ldrb r1, [r1]
	cmp r0, r1
	bne _08043D3C
	movs r0, 0x2
	b _08043D4C
	.align 2, 0
_08043D38: .4byte gDungeon
_08043D3C:
	bl IsBossFight
	lsls r0, 24
	cmp r0, 0
	bne _08043D4A
	movs r0, 0
	b _08043D4C
_08043D4A:
	movs r0, 0x1
_08043D4C:
	pop {r1}
	bx r1
	thumb_func_end sub_8043D10

	thumb_func_start sub_8043D50
sub_8043D50:
	ldr r2, _08043D5C
	str r2, [r1]
	movs r1, 0x90
	lsls r1, 7
	str r1, [r0]
	bx lr
	.align 2, 0
_08043D5C: .4byte 0x0001cedc
	thumb_func_end sub_8043D50

	thumb_func_start sub_8043D60
sub_8043D60:
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	movs r5, 0
_08043D6A:
	ldr r0, _08043DA4
	ldr r0, [r0]
	lsls r1, r5, 2
	ldr r2, _08043DA8
	adds r0, r2
	adds r0, r1
	ldr r4, [r0]
	adds r0, r4, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	beq _08043DCE
	ldr r2, [r4, 0x70]
	movs r1, 0x1
	ldrb r0, [r2, 0x8]
	eors r0, r1
	negs r1, r0
	orrs r1, r0
	lsrs r1, 31
	adds r0, r2, 0
	adds r0, 0x40
	ldrb r0, [r0]
	cmp r0, 0x4A
	beq _08043DA0
	cmp r0, 0x47
	bne _08043DAC
_08043DA0:
	movs r0, 0x1
	b _08043DAE
	.align 2, 0
_08043DA4: .4byte gDungeon
_08043DA8: .4byte 0x0001358c
_08043DAC:
	movs r0, 0
_08043DAE:
	cmp r0, 0
	beq _08043DB4
	movs r1, 0
_08043DB4:
	adds r0, r2, 0
	adds r0, 0xA4
	ldrb r0, [r0]
	cmp r0, 0x1
	bne _08043DC0
	movs r1, 0
_08043DC0:
	cmp r1, 0
	beq _08043DCE
	adds r0, r4, 0
	ldr r1, _08043EC0
	adds r2, r4, 0
	bl sub_8068FE0
_08043DCE:
	adds r5, 0x1
	cmp r5, 0xF
	ble _08043D6A
	movs r5, 0
	ldr r0, _08043EC4
	mov r9, r0
	mov r8, r5
_08043DDC:
	mov r1, r9
	ldr r0, [r1]
	lsls r1, r5, 2
	ldr r2, _08043EC8
	adds r0, r2
	adds r0, r1
	ldr r4, [r0]
	adds r0, r4, 0
	bl EntityExists
	lsls r0, 24
	adds r7, r5, 0x1
	cmp r0, 0
	beq _08043E62
	adds r0, r4, 0
	adds r0, 0x22
	mov r1, r8
	strb r1, [r0]
	adds r1, r4, 0
	adds r1, 0x20
	movs r0, 0x1
	strb r0, [r1]
	ldr r4, [r4, 0x70]
	ldrh r0, [r4, 0x10]
	strh r0, [r4, 0xE]
	movs r2, 0x9E
	lsls r2, 1
	adds r1, r4, r2
	adds r2, 0x4
	adds r0, r4, r2
	ldr r0, [r0]
	str r0, [r1]
	mov r1, r9
	ldr r0, [r1]
	ldr r2, _08043ECC
	adds r0, r2
	mov r1, r8
	strb r1, [r0]
	adds r0, r4, 0
	movs r1, 0
	bl sub_806BFC0
	ldrh r0, [r4, 0x2]
	strh r0, [r4, 0x4]
	adds r0, r4, 0
	adds r0, 0xFD
	mov r2, r8
	strb r2, [r0]
	movs r0, 0x8C
	lsls r0, 1
	adds r5, r4, r0
	adds r4, r5, 0
	movs r6, 0x3
_08043E46:
	ldrb r1, [r4]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _08043E58
	adds r0, r5, 0
	bl GetMoveBasePP
	strb r0, [r4, 0x4]
_08043E58:
	adds r4, 0x8
	adds r5, 0x8
	subs r6, 0x1
	cmp r6, 0
	bge _08043E46
_08043E62:
	adds r5, r7, 0
	cmp r5, 0x3
	ble _08043DDC
	movs r6, 0
_08043E6A:
	movs r5, 0
	adds r7, r6, 0x1
_08043E6E:
	adds r0, r5, 0
	adds r1, r6, 0
	bl GetTileSafe
	ldr r4, [r0, 0x14]
	adds r0, r4, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	beq _08043EA0
	adds r0, r4, 0
	bl GetEntityType
	cmp r0, 0x2
	bne _08043EA0
	adds r0, r4, 0
	bl GetTrapData
	adds r1, r0, 0
	ldrb r0, [r1]
	cmp r0, 0x1B
	bne _08043EA0
	movs r0, 0x5
	strb r0, [r1]
_08043EA0:
	adds r5, 0x1
	cmp r5, 0x37
	ble _08043E6E
	adds r6, r7, 0
	cmp r6, 0x1F
	ble _08043E6A
	movs r0, 0x2
	bl sub_8046F84
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_08043EC0: .4byte 0x00000207
_08043EC4: .4byte gDungeon
_08043EC8: .4byte 0x0001357c
_08043ECC: .4byte 0x00000676
	thumb_func_end sub_8043D60

	thumb_func_start sub_8043ED0
sub_8043ED0:
	push {r4-r7,lr}
	lsls r0, 24
	lsrs r5, r0, 24
	movs r7, 0
	cmp r5, 0
	bne _08043EEA
	bl sub_8044B28
	lsls r0, 24
	cmp r0, 0
	beq _08043EEA
	movs r0, 0
	b _08043FB8
_08043EEA:
	ldr r6, _08043F2C
	ldr r0, [r6]
	ldrb r0, [r0, 0x10]
	cmp r0, 0x1
	bne _08043F40
	bl GetLeader
	adds r4, r0, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	beq _08043FB6
	cmp r5, 0
	bne _08043F20
	ldr r0, _08043F30
	ldr r1, [r6]
	ldr r2, _08043F34
	adds r1, r2
	bl strcpy
	ldr r0, _08043F38
	ldr r1, [r0]
	movs r0, 0
	movs r2, 0x1
	bl PrintFieldMessage
_08043F20:
	adds r0, r4, 0
	bl sub_8042B0C
	ldr r1, _08043F3C
	b _08043FAC
	.align 2, 0
_08043F2C: .4byte gDungeon
_08043F30: .4byte gAvailablePokemonNames
_08043F34: .4byte 0x000005f4
_08043F38: .4byte gUnknown_80F89B4
_08043F3C: .4byte 0x0000021f
_08043F40:
	cmp r0, 0x2
	bne _08043F74
	bl GetLeader
	adds r4, r0, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	beq _08043FB6
	cmp r5, 0
	bne _08043FA4
	ldr r0, _08043F68
	ldr r1, [r6]
	ldr r2, _08043F6C
	adds r1, r2
	bl strcpy
	ldr r0, _08043F70
	b _08043F9A
	.align 2, 0
_08043F68: .4byte gAvailablePokemonNames
_08043F6C: .4byte 0x000005f4
_08043F70: .4byte gUnknown_80F89D4
_08043F74:
	cmp r0, 0x3
	bne _08043FB6
	bl GetLeader
	adds r4, r0, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	beq _08043FB6
	cmp r5, 0
	bne _08043FA4
	ldr r0, _08043FC0
	ldr r1, [r6]
	ldr r2, _08043FC4
	adds r1, r2
	bl strcpy
	ldr r0, _08043FC8
_08043F9A:
	ldr r1, [r0]
	movs r0, 0
	movs r2, 0x1
	bl PrintFieldMessage
_08043FA4:
	adds r0, r4, 0
	bl sub_8042B0C
	ldr r1, _08043FCC
_08043FAC:
	adds r0, r4, 0
	adds r2, r4, 0
	bl sub_8068FE0
	movs r7, 0x1
_08043FB6:
	adds r0, r7, 0
_08043FB8:
	pop {r4-r7}
	pop {r1}
	bx r1
	.align 2, 0
_08043FC0: .4byte gAvailablePokemonNames
_08043FC4: .4byte 0x000005f4
_08043FC8: .4byte gUnknown_80F89D8
_08043FCC: .4byte 0x00000222
	thumb_func_end sub_8043ED0

	thumb_func_start sub_8043FD0
sub_8043FD0:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x44
	movs r0, 0x2
	mov r9, r0
	movs r1, 0x1
	mov r10, r1
	movs r0, 0xFF
	mov r8, r0
_08043FE8:
	movs r3, 0
	mov r1, r9
	adds r1, 0x1
	str r1, [sp, 0x3C]
_08043FF0:
	ldr r2, _080440E4
	movs r0, 0x58
	adds r1, r3, 0
	muls r1, r0
	ldr r0, [r2]
	adds r4, r0, r1
	ldrh r1, [r4]
	mov r0, r10
	ands r0, r1
	adds r3, 0x1
	str r3, [sp, 0x40]
	cmp r0, 0
	beq _080440FE
	lsrs r0, r1, 1
	mov r1, r10
	ands r0, r1
	cmp r0, 0
	beq _080440FE
	add r5, sp, 0x20
	movs r0, 0x8
	ldrsh r1, [r4, r0]
	adds r0, r5, 0
	mov r2, r9
	bl GetPokemonLevelData
	mov r1, r9
	strb r1, [r4, 0x3]
	ldr r0, [sp, 0x20]
	str r0, [r4, 0x1C]
	ldrh r0, [r5, 0x4]
	ldrh r1, [r4, 0x16]
	adds r0, r1
	movs r2, 0
	strh r0, [r4, 0x16]
	lsls r0, 16
	ldr r1, _080440E8
	cmp r0, r1
	ble _08044040
	ldr r0, _080440EC
	strh r0, [r4, 0x16]
_08044040:
	ldrb r0, [r4, 0x18]
	str r0, [sp, 0x2C]
	ldrb r0, [r4, 0x19]
	str r0, [sp, 0x30]
	ldrb r0, [r4, 0x1A]
	str r0, [sp, 0x34]
	ldrb r0, [r4, 0x1B]
	str r0, [sp, 0x38]
	ldrb r1, [r5, 0x6]
	ldr r0, [sp, 0x2C]
	adds r0, r1
	str r0, [sp, 0x2C]
	ldrb r1, [r5, 0x7]
	ldr r0, [sp, 0x30]
	adds r0, r1
	str r0, [sp, 0x30]
	ldrb r1, [r5, 0x8]
	ldr r0, [sp, 0x34]
	adds r0, r1
	str r0, [sp, 0x34]
	ldrb r1, [r5, 0x9]
	ldr r0, [sp, 0x38]
	adds r0, r1
	str r0, [sp, 0x38]
	ldr r0, [sp, 0x2C]
	cmp r0, 0xFE
	ble _0804407A
	mov r0, r8
	str r0, [sp, 0x2C]
_0804407A:
	ldr r0, [sp, 0x30]
	cmp r0, 0xFE
	ble _08044084
	mov r1, r8
	str r1, [sp, 0x30]
_08044084:
	ldr r0, [sp, 0x34]
	cmp r0, 0xFE
	ble _0804408E
	mov r0, r8
	str r0, [sp, 0x34]
_0804408E:
	ldr r0, [sp, 0x38]
	cmp r0, 0xFE
	ble _08044098
	mov r1, r8
	str r1, [sp, 0x38]
_08044098:
	ldr r0, [sp, 0x2C]
	strb r0, [r4, 0x18]
	ldr r0, [sp, 0x30]
	strb r0, [r4, 0x19]
	ldr r0, [sp, 0x34]
	strb r0, [r4, 0x1A]
	ldr r0, [sp, 0x38]
	strb r0, [r4, 0x1B]
	movs r0, 0x8
	ldrsh r1, [r4, r0]
	ldrb r2, [r4, 0x3]
	mov r0, sp
	ldr r3, _080440EC
	bl sub_808E0AC
	adds r6, r0, 0
	cmp r6, 0
	beq _080440FE
	movs r0, 0
	cmp r0, r6
	bge _080440FE
_080440C2:
	movs r3, 0
	adds r7, r0, 0x1
	lsls r0, 1
	mov r1, sp
	adds r5, r1, r0
	adds r2, r4, 0
	adds r2, 0x2C
_080440D0:
	ldrb r1, [r2]
	mov r0, r10
	ands r0, r1
	cmp r0, 0
	bne _080440F0
	ldrh r1, [r5]
	adds r0, r2, 0
	bl InitZeroedPPPokemonMove
	b _080440F8
	.align 2, 0
_080440E4: .4byte gRecruitedPokemonRef
_080440E8: .4byte 0x03e60000
_080440EC: .4byte 0x000003e7
_080440F0:
	adds r2, 0x8
	adds r3, 0x1
	cmp r3, 0x3
	ble _080440D0
_080440F8:
	adds r0, r7, 0
	cmp r0, r6
	blt _080440C2
_080440FE:
	ldr r3, [sp, 0x40]
	movs r0, 0xCE
	lsls r0, 1
	cmp r3, r0
	bgt _0804410A
	b _08043FF0
_0804410A:
	ldr r0, [sp, 0x3C]
	mov r9, r0
	cmp r0, 0x5
	bgt _08044114
	b _08043FE8
_08044114:
	add sp, 0x44
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_8043FD0

	thumb_func_start sub_8044124
sub_8044124:
	push {r4,r5,lr}
	ldr r0, _080441AC
	ldr r0, [r0]
	ldr r1, _080441B0
	adds r0, r1
	ldrb r0, [r0]
	bl GetMaxItemsAllowed
	cmp r0, 0
	bne _08044182
	movs r3, 0
	ldr r4, _080441B4
	movs r2, 0
_0804413E:
	lsls r1, r3, 2
	ldr r0, [r4]
	adds r1, r0
	strb r2, [r1, 0x2]
	strb r2, [r1, 0x1]
	strb r2, [r1]
	adds r3, 0x1
	cmp r3, 0x13
	ble _0804413E
	movs r3, 0
	ldr r5, _080441B8
	movs r4, 0x1
_08044156:
	movs r0, 0x58
	adds r1, r3, 0
	muls r1, r0
	ldr r0, [r5]
	adds r1, r0, r1
	ldrh r2, [r1]
	adds r0, r4, 0
	ands r0, r2
	cmp r0, 0
	beq _08044178
	lsrs r0, r2, 1
	ands r0, r4
	cmp r0, 0
	beq _08044178
	adds r1, 0x28
	movs r0, 0
	strb r0, [r1]
_08044178:
	adds r3, 0x1
	movs r0, 0xCE
	lsls r0, 1
	cmp r3, r0
	ble _08044156
_08044182:
	ldr r0, _080441AC
	ldr r0, [r0]
	ldr r2, _080441B0
	adds r0, r2
	ldrb r0, [r0]
	bl IsKeepMoney
	lsls r0, 24
	lsrs r1, r0, 24
	cmp r1, 0
	bne _080441A4
	ldr r0, _080441B4
	ldr r0, [r0]
	movs r2, 0x98
	lsls r2, 2
	adds r0, r2
	str r1, [r0]
_080441A4:
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_080441AC: .4byte gDungeon
_080441B0: .4byte 0x00000644
_080441B4: .4byte gTeamInventoryRef
_080441B8: .4byte gRecruitedPokemonRef
	thumb_func_end sub_8044124

	.align 2, 0
