	#include "asm/constants/gba_constants.inc"
  	#include "asm/macros.inc"

  	.syntax unified

  	.text

	thumb_func_start HealTargetHP
HealTargetHP:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x4
	mov r9, r0
	adds r5, r1, 0
	mov r10, r2
	mov r8, r3
	ldr r0, [sp, 0x24]
	lsls r0, 24
	lsrs r0, 24
	str r0, [sp]
	adds r0, r5, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	bne _08077C6E
	b _08077DC8
_08077C6E:
	ldr r4, [r5, 0x70]
	movs r0, 0x10
	ldrsh r7, [r4, r0]
	movs r1, 0xE
	ldrsh r6, [r4, r1]
	ldrh r2, [r4, 0xE]
	adds r0, r6, 0
	ldrh r1, [r4, 0x10]
	mov r12, r1
	adds r1, r7, 0
	cmp r0, r1
	bne _08077C8C
	mov r0, r8
	cmp r0, 0
	bgt _08077C92
_08077C8C:
	mov r3, r10
	cmp r3, 0
	bne _08077CD0
_08077C92:
	ldrh r1, [r4, 0x10]
	add r1, r8
	strh r1, [r4, 0x10]
	ldrh r0, [r4, 0xE]
	add r0, r8
	strh r0, [r4, 0xE]
	lsls r1, 16
	asrs r1, 16
	ldr r0, _08077CCC
	cmp r1, r0
	ble _08077CAA
	strh r0, [r4, 0x10]
_08077CAA:
	movs r1, 0xE
	ldrsh r0, [r4, r1]
	movs r3, 0x10
	ldrsh r2, [r4, r3]
	ldrh r1, [r4, 0x10]
	cmp r0, r2
	ble _08077CBA
	strh r1, [r4, 0xE]
_08077CBA:
	movs r1, 0xE
	ldrsh r0, [r4, r1]
	cmp r0, r2
	bne _08077CC4
	adds r6, r0, 0
_08077CC4:
	adds r0, r5, 0
	bl sub_8041C94
	b _08077CE8
	.align 2, 0
_08077CCC: .4byte 0x000003e7
_08077CD0:
	mov r3, r10
	adds r0, r2, r3
	strh r0, [r4, 0xE]
	lsls r0, 16
	asrs r0, 16
	cmp r0, r1
	ble _08077CE2
	mov r0, r12
	strh r0, [r4, 0xE]
_08077CE2:
	adds r0, r5, 0
	bl sub_8041CA8
_08077CE8:
	movs r1, 0x10
	ldrsh r0, [r4, r1]
	subs r7, r0, r7
	movs r2, 0xE
	ldrsh r0, [r4, r2]
	subs r6, r0, r6
	adds r0, r5, 0
	bl DungeonEntityUpdateStatusSprites
	ldr r0, _08077D1C
	str r6, [r0]
	str r7, [r0, 0x4]
	ldr r0, _08077D20
	adds r1, r5, 0
	movs r2, 0
	bl SetMessageArgument
	cmp r6, 0
	bne _08077D28
	cmp r7, 0
	bne _08077D28
	ldr r3, [sp]
	cmp r3, 0
	beq _08077DC8
	ldr r0, _08077D24
	b _08077D3A
	.align 2, 0
_08077D1C: .4byte gUnknown_202DE30
_08077D20: .4byte gAvailablePokemonNames
_08077D24: .4byte gUnknown_80FB204
_08077D28:
	mov r0, r8
	cmp r0, 0
	bne _08077D4C
	cmp r6, 0
	bne _08077D4C
	ldr r1, [sp]
	cmp r1, 0
	beq _08077DC8
	ldr r0, _08077D48
_08077D3A:
	ldr r2, [r0]
	mov r0, r9
	adds r1, r5, 0
	bl sub_80522F4
	b _08077DC8
	.align 2, 0
_08077D48: .4byte gUnknown_80FB21C
_08077D4C:
	movs r2, 0
	mov r8, r2
	cmp r7, 0
	beq _08077D6E
	adds r0, r5, 0
	bl sub_8045888
	lsls r0, 24
	cmp r0, 0
	beq _08077D62
	mov r8, r7
_08077D62:
	ldr r0, _08077DA0
	ldr r2, [r0]
	mov r0, r9
	adds r1, r5, 0
	bl sub_80522F4
_08077D6E:
	cmp r6, 0
	beq _08077DB4
	adds r0, r5, 0
	bl sub_8045888
	lsls r0, 24
	cmp r0, 0
	beq _08077D80
	mov r8, r6
_08077D80:
	mov r3, r10
	cmp r3, 0
	beq _08077DB4
	movs r0, 0x10
	ldrsh r1, [r4, r0]
	movs r2, 0xE
	ldrsh r0, [r4, r2]
	cmp r1, r0
	bne _08077DA8
	ldr r0, _08077DA4
	ldr r2, [r0]
	mov r0, r9
	adds r1, r5, 0
	bl sub_80522F4
	b _08077DB4
	.align 2, 0
_08077DA0: .4byte gUnknown_80FB240
_08077DA4: .4byte gUnknown_80FB1E0
_08077DA8:
	ldr r0, _08077DD8
	ldr r2, [r0]
	mov r0, r9
	adds r1, r5, 0
	bl sub_80522F4
_08077DB4:
	mov r3, r8
	cmp r3, 0
	beq _08077DC8
	movs r3, 0x1
	negs r3, r3
	mov r0, r8
	adds r1, r5, 0
	movs r2, 0x1
	bl sub_803ED30
_08077DC8:
	add sp, 0x4
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_08077DD8: .4byte gUnknown_80FB1C4
	thumb_func_end HealTargetHP

	thumb_func_start sub_8077DDC
sub_8077DDC:
	push {r4,r5,lr}
	adds r5, r0, 0
	adds r4, r1, 0
	adds r0, r4, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	beq _08077E3C
	ldr r0, [r4, 0x70]
	adds r1, r0, 0
	adds r1, 0xF1
	ldrb r0, [r1]
	cmp r0, 0
	beq _08077E0C
	ldr r0, _08077E08
	ldr r2, [r0]
	adds r0, r5, 0
	adds r1, r4, 0
	bl sub_80522F4
	b _08077E3C
	.align 2, 0
_08077E08: .4byte gUnknown_80FAEF0
_08077E0C:
	movs r0, 0x1
	strb r0, [r1]
	adds r0, r4, 0
	bl nullsub_75
	ldr r0, _08077E44
	adds r1, r4, 0
	movs r2, 0
	bl SetMessageArgument
	ldr r0, _08077E48
	ldr r2, [r0]
	adds r0, r5, 0
	adds r1, r4, 0
	bl sub_80522F4
	movs r0, 0
	bl sub_803F580
	bl sub_8040A84
	adds r0, r4, 0
	bl DungeonEntityUpdateStatusSprites
_08077E3C:
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_08077E44: .4byte gAvailablePokemonNames
_08077E48: .4byte gUnknown_80FAEA0
	thumb_func_end sub_8077DDC

	thumb_func_start sub_8077E4C
sub_8077E4C:
	push {r4,r5,lr}
	adds r5, r0, 0
	adds r4, r1, 0
	adds r0, r4, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	beq _08077EC0
	bl sub_8043D10
	lsls r0, 24
	cmp r0, 0
	beq _08077E70
	ldr r0, _08077E6C
	b _08077E7E
	.align 2, 0
_08077E6C: .4byte gUnknown_80FAF3C
_08077E70:
	ldr r0, [r4, 0x70]
	adds r1, r0, 0
	adds r1, 0xF2
	ldrb r0, [r1]
	cmp r0, 0
	beq _08077E90
	ldr r0, _08077E8C
_08077E7E:
	ldr r2, [r0]
	adds r0, r5, 0
	adds r1, r4, 0
	bl sub_80522F4
	b _08077EC0
	.align 2, 0
_08077E8C: .4byte gUnknown_80FAF1C
_08077E90:
	movs r0, 0x1
	strb r0, [r1]
	adds r0, r4, 0
	bl nullsub_76
	ldr r0, _08077EC8
	adds r1, r4, 0
	movs r2, 0
	bl SetMessageArgument
	ldr r0, _08077ECC
	ldr r2, [r0]
	adds r0, r5, 0
	adds r1, r4, 0
	bl sub_80522F4
	movs r0, 0
	bl sub_803F580
	bl sub_8040A84
	adds r0, r4, 0
	bl DungeonEntityUpdateStatusSprites
_08077EC0:
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_08077EC8: .4byte gAvailablePokemonNames
_08077ECC: .4byte gUnknown_80FAEC8
	thumb_func_end sub_8077E4C

	thumb_func_start sub_8077ED0
sub_8077ED0:
	push {r4,r5,lr}
	adds r5, r0, 0
	adds r4, r1, 0
	adds r0, r4, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	beq _08077F30
	ldr r0, [r4, 0x70]
	adds r1, r0, 0
	adds r1, 0xF0
	ldrb r0, [r1]
	cmp r0, 0
	beq _08077F00
	ldr r0, _08077EFC
	ldr r2, [r0]
	adds r0, r5, 0
	adds r1, r4, 0
	bl sub_80522F4
	b _08077F30
	.align 2, 0
_08077EFC: .4byte gUnknown_80FAFD0
_08077F00:
	movs r0, 0x1
	strb r0, [r1]
	adds r0, r4, 0
	bl nullsub_77
	ldr r0, _08077F38
	adds r1, r4, 0
	movs r2, 0
	bl SetMessageArgument
	ldr r0, _08077F3C
	ldr r2, [r0]
	adds r0, r5, 0
	adds r1, r4, 0
	bl sub_80522F4
	movs r0, 0
	bl sub_803F580
	bl sub_8040A84
	adds r0, r4, 0
	bl DungeonEntityUpdateStatusSprites
_08077F30:
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_08077F38: .4byte gAvailablePokemonNames
_08077F3C: .4byte gUnknown_80FAFAC
	thumb_func_end sub_8077ED0

	thumb_func_start sub_8077F40
sub_8077F40:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	adds r5, r0, 0
	adds r4, r1, 0
	lsls r2, 24
	lsrs r6, r2, 24
	mov r9, r6
	adds r0, r4, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	bne _08077F62
	b _08078068
_08077F62:
	adds r0, r5, 0
	bl GetEntityType
	mov r10, r0
	cmp r0, 0x1
	beq _08077F70
	b _08078068
_08077F70:
	ldr r7, [r4, 0x70]
	cmp r5, r4
	bne _08077F88
	cmp r6, 0
	beq _08078068
	ldr r0, _08077F84
	ldr r2, [r0]
	adds r0, r4, 0
	b _08078022
	.align 2, 0
_08077F84: .4byte gPtrCantLeechSeedSelfMessage
_08077F88:
	adds r0, r5, 0
	adds r1, r4, 0
	mov r2, r9
	bl HasSafeguardStatus
	lsls r0, 24
	cmp r0, 0
	bne _08078068
	ldr r0, _08077FC0
	adds r1, r4, 0
	movs r2, 0
	bl SetMessageArgument
	adds r0, r4, 0
	movs r1, 0x4
	bl HasType
	lsls r0, 24
	lsrs r0, 24
	mov r8, r0
	cmp r0, 0
	beq _08077FC8
	mov r0, r9
	cmp r0, 0
	beq _08078068
	ldr r0, _08077FC4
	b _0807801E
	.align 2, 0
_08077FC0: .4byte gAvailablePokemonNames
_08077FC4: .4byte gPtrCantLeechSeedMonMessage
_08077FC8:
	adds r6, r7, 0
	adds r6, 0xD0
	ldrb r0, [r6]
	cmp r0, 0x1
	beq _0807801C
	cmp r0, 0x2
	bne _08077FE2
	ldr r0, _08078014
	ldr r2, [r0]
	adds r0, r5, 0
	adds r1, r4, 0
	bl sub_80522F4
_08077FE2:
	mov r1, r10
	strb r1, [r6]
	ldr r1, _08078018
	adds r0, r4, 0
	movs r2, 0x1
	bl CalculateStatusTurns
	adds r0, 0x1
	adds r1, r7, 0
	adds r1, 0xD9
	strb r0, [r1]
	adds r0, r7, 0
	adds r0, 0xDA
	mov r6, r8
	strb r6, [r0]
	adds r0, r4, 0
	bl nullsub_78
	adds r1, r7, 0
	adds r1, 0xD8
	movs r0, 0xFF
	strb r0, [r1]
	movs r2, 0
	adds r3, r1, 0
	b _08078030
	.align 2, 0
_08078014: .4byte gUnknown_80FAA8C
_08078018: .4byte gUnknown_80F4EB0
_0807801C:
	ldr r0, _0807802C
_0807801E:
	ldr r2, [r0]
	adds r0, r5, 0
_08078022:
	adds r1, r4, 0
	bl sub_80522F4
	b _08078068
	.align 2, 0
_0807802C: .4byte gUnknown_80FAE7C
_08078030:
	ldr r0, _08078078
	ldr r0, [r0]
	lsls r1, r2, 2
	ldr r6, _0807807C
	adds r0, r6
	adds r0, r1
	ldr r0, [r0]
	cmp r5, r0
	bne _08078050
	strb r2, [r3]
	ldr r0, [r5, 0x70]
	adds r1, r7, 0
	adds r1, 0xD4
	adds r0, 0x98
	ldr r0, [r0]
	str r0, [r1]
_08078050:
	adds r2, 0x1
	cmp r2, 0x13
	ble _08078030
	ldr r0, _08078080
	ldr r2, [r0]
	adds r0, r5, 0
	adds r1, r4, 0
	bl sub_80522F4
	adds r0, r4, 0
	bl DungeonEntityUpdateStatusSprites
_08078068:
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_08078078: .4byte gDungeonGlobalData
_0807807C: .4byte 0x000135cc
_08078080: .4byte gUnknown_80FAE58
	thumb_func_end sub_8077F40

	thumb_func_start sub_8078084
sub_8078084:
	push {r4-r6,lr}
	ldr r6, [r0, 0x70]
	movs r5, 0
_0807808A:
	ldr r0, _080780DC
	ldr r0, [r0]
	lsls r1, r5, 2
	ldr r2, _080780E0
	adds r0, r2
	adds r0, r1
	ldr r4, [r0]
	adds r0, r4, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	beq _080780D0
	ldr r1, [r4, 0x70]
	adds r3, r1, 0
	adds r3, 0xD0
	ldrb r0, [r3]
	subs r0, 0x1
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bhi _080780D0
	adds r0, r1, 0
	adds r0, 0xD4
	adds r1, r6, 0
	adds r1, 0x98
	ldr r2, [r0]
	ldr r0, [r1]
	cmp r2, r0
	bne _080780D0
	movs r0, 0
	strb r0, [r3]
	adds r0, r4, 0
	bl DungeonEntityUpdateStatusSprites
_080780D0:
	adds r5, 0x1
	cmp r5, 0x13
	ble _0807808A
	pop {r4-r6}
	pop {r0}
	bx r0
	.align 2, 0
_080780DC: .4byte gDungeonGlobalData
_080780E0: .4byte 0x000135cc
	thumb_func_end sub_8078084

	thumb_func_start DestinyBondStatusTarget
DestinyBondStatusTarget:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	adds r4, r0, 0
	adds r5, r1, 0
	adds r0, r5, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	beq _080781C4
	adds r0, r4, 0
	bl GetEntityType
	cmp r0, 0x1
	bne _080781C4
	adds r0, r5, 0
	bl GetEntityType
	cmp r0, 0x1
	bne _080781C4
	ldr r6, [r4, 0x70]
	ldr r0, _0807816C
	adds r1, r4, 0
	movs r2, 0
	bl SetMessageArgument
	adds r7, r6, 0
	adds r7, 0xD0
	ldrb r0, [r7]
	cmp r0, 0x2
	beq _08078178
	cmp r0, 0x1
	bne _08078134
	ldr r0, _08078170
	ldr r2, [r0]
	adds r0, r4, 0
	adds r1, r5, 0
	bl sub_80522F4
_08078134:
	movs r0, 0
	mov r8, r0
	movs r0, 0x2
	strb r0, [r7]
	ldr r1, _08078174
	adds r0, r5, 0
	movs r2, 0x1
	bl CalculateStatusTurns
	adds r0, 0x1
	adds r1, r6, 0
	adds r1, 0xD9
	strb r0, [r1]
	adds r0, r6, 0
	adds r0, 0xDA
	mov r1, r8
	strb r1, [r0]
	adds r0, r5, 0
	bl nullsub_74
	adds r1, r6, 0
	adds r1, 0xD8
	movs r0, 0xFF
	strb r0, [r1]
	movs r2, 0
	adds r3, r1, 0
	b _0807818C
	.align 2, 0
_0807816C: .4byte gAvailablePokemonNames
_08078170: .4byte gUnknown_80FA79C
_08078174: .4byte gUnknown_80F4EF0
_08078178:
	ldr r0, _08078188
	ldr r2, [r0]
	adds r0, r4, 0
	adds r1, r5, 0
	bl sub_80522F4
	b _080781C4
	.align 2, 0
_08078188: .4byte gUnknown_80FBB78
_0807818C:
	ldr r0, _080781D0
	ldr r0, [r0]
	lsls r1, r2, 2
	ldr r7, _080781D4
	adds r0, r7
	adds r0, r1
	ldr r0, [r0]
	cmp r5, r0
	bne _080781AC
	strb r2, [r3]
	ldr r0, [r5, 0x70]
	adds r1, r6, 0
	adds r1, 0xD4
	adds r0, 0x98
	ldr r0, [r0]
	str r0, [r1]
_080781AC:
	adds r2, 0x1
	cmp r2, 0x13
	ble _0807818C
	ldr r0, _080781D8
	ldr r2, [r0]
	adds r0, r4, 0
	adds r1, r5, 0
	bl sub_80522F4
	adds r0, r5, 0
	bl DungeonEntityUpdateStatusSprites
_080781C4:
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_080781D0: .4byte gDungeonGlobalData
_080781D4: .4byte 0x000135cc
_080781D8: .4byte gUnknown_80FBB4C
	thumb_func_end DestinyBondStatusTarget

	thumb_func_start sub_80781DC
sub_80781DC:
	push {r4-r7,lr}
	adds r7, r0, 0
	adds r4, r1, 0
	adds r6, r2, 0
	adds r0, r4, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	beq _08078242
	ldr r5, [r4, 0x70]
	ldr r0, _08078228
	adds r1, r4, 0
	movs r2, 0
	bl SetMessageArgument
	adds r1, r5, 0
	adds r1, 0xDC
	ldrb r0, [r1]
	cmp r0, 0x1
	beq _08078230
	movs r0, 0x1
	strb r0, [r1]
	adds r1, r6, 0x1
	adds r0, r5, 0
	adds r0, 0xDD
	strb r1, [r0]
	adds r0, r4, 0
	bl sub_8041CDC
	ldr r0, _0807822C
	ldr r2, [r0]
	adds r0, r7, 0
	adds r1, r4, 0
	bl sub_80522F4
	b _0807823C
	.align 2, 0
_08078228: .4byte gAvailablePokemonNames
_0807822C: .4byte gUnknown_80FB73C
_08078230:
	ldr r0, _08078248
	ldr r2, [r0]
	adds r0, r7, 0
	adds r1, r4, 0
	bl sub_80522F4
_0807823C:
	adds r0, r4, 0
	bl DungeonEntityUpdateStatusSprites
_08078242:
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_08078248: .4byte gUnknown_80FB764
	thumb_func_end sub_80781DC

	thumb_func_start sub_807824C
sub_807824C:
	push {r4-r7,lr}
	adds r6, r0, 0
	adds r4, r1, 0
	adds r7, r2, 0
	adds r0, r4, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	beq _080782C2
	adds r0, r6, 0
	adds r1, r4, 0
	movs r2, 0x1
	bl HasSafeguardStatus
	lsls r0, 24
	cmp r0, 0
	bne _080782C2
	ldr r5, [r4, 0x70]
	ldr r0, _080782A8
	adds r1, r4, 0
	movs r2, 0
	bl SetMessageArgument
	adds r1, r5, 0
	adds r1, 0xDC
	ldrb r0, [r1]
	cmp r0, 0x2
	beq _080782B0
	movs r0, 0x2
	strb r0, [r1]
	adds r1, r7, 0x1
	adds r0, r5, 0
	adds r0, 0xDD
	strb r1, [r0]
	adds r0, r4, 0
	bl sub_8041CEC
	ldr r0, _080782AC
	ldr r2, [r0]
	adds r0, r6, 0
	adds r1, r4, 0
	bl sub_80522F4
	b _080782BC
	.align 2, 0
_080782A8: .4byte gAvailablePokemonNames
_080782AC: .4byte gUnknown_80FB780
_080782B0:
	ldr r0, _080782C8
	ldr r2, [r0]
	adds r0, r6, 0
	adds r1, r4, 0
	bl sub_80522F4
_080782BC:
	adds r0, r4, 0
	bl DungeonEntityUpdateStatusSprites
_080782C2:
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_080782C8: .4byte gUnknown_80FB7A0
	thumb_func_end sub_807824C

	thumb_func_start sub_80782CC
sub_80782CC:
	push {r4-r6,lr}
	adds r6, r0, 0
	adds r4, r1, 0
	adds r0, r4, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	beq _0807833E
	ldr r5, [r4, 0x70]
	ldr r0, _08078320
	adds r1, r4, 0
	movs r2, 0
	bl SetMessageArgument
	adds r1, r5, 0
	adds r1, 0xDC
	ldrb r0, [r1]
	cmp r0, 0x3
	beq _0807832C
	movs r0, 0x3
	strb r0, [r1]
	ldr r1, _08078324
	adds r0, r4, 0
	movs r2, 0
	bl CalculateStatusTurns
	adds r0, 0x1
	adds r1, r5, 0
	adds r1, 0xDD
	strb r0, [r1]
	adds r0, r4, 0
	bl nullsub_79
	ldr r0, _08078328
	ldr r2, [r0]
	adds r0, r6, 0
	adds r1, r4, 0
	bl sub_80522F4
	b _08078338
	.align 2, 0
_08078320: .4byte gAvailablePokemonNames
_08078324: .4byte gUnknown_80F4EC4
_08078328: .4byte gUnknown_80FB8BC
_0807832C:
	ldr r0, _08078344
	ldr r2, [r0]
	adds r0, r6, 0
	adds r1, r4, 0
	bl sub_80522F4
_08078338:
	adds r0, r4, 0
	bl DungeonEntityUpdateStatusSprites
_0807833E:
	pop {r4-r6}
	pop {r0}
	bx r0
	.align 2, 0
_08078344: .4byte gUnknown_80FB8E4
	thumb_func_end sub_80782CC

	thumb_func_start sub_8078348
sub_8078348:
	push {r4-r6,lr}
	adds r6, r0, 0
	adds r4, r1, 0
	adds r0, r4, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	beq _080783BA
	ldr r5, [r4, 0x70]
	ldr r0, _0807839C
	adds r1, r4, 0
	movs r2, 0
	bl SetMessageArgument
	adds r1, r5, 0
	adds r1, 0xDC
	ldrb r0, [r1]
	cmp r0, 0x4
	beq _080783A8
	movs r0, 0x4
	strb r0, [r1]
	ldr r1, _080783A0
	adds r0, r4, 0
	movs r2, 0
	bl CalculateStatusTurns
	adds r0, 0x1
	adds r1, r5, 0
	adds r1, 0xDD
	strb r0, [r1]
	adds r0, r4, 0
	bl nullsub_80
	ldr r0, _080783A4
	ldr r2, [r0]
	adds r0, r6, 0
	adds r1, r4, 0
	bl sub_80522F4
	b _080783B4
	.align 2, 0
_0807839C: .4byte gAvailablePokemonNames
_080783A0: .4byte gUnknown_80F4EC8
_080783A4: .4byte gUnknown_80FB900
_080783A8:
	ldr r0, _080783C0
	ldr r2, [r0]
	adds r0, r6, 0
	adds r1, r4, 0
	bl sub_80522F4
_080783B4:
	adds r0, r4, 0
	bl DungeonEntityUpdateStatusSprites
_080783BA:
	pop {r4-r6}
	pop {r0}
	bx r0
	.align 2, 0
_080783C0: .4byte gUnknown_80FB924
	thumb_func_end sub_8078348

	thumb_func_start sub_80783C4
sub_80783C4:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x24
	adds r5, r0, 0
	adds r7, r1, 0
	lsls r2, 24
	lsrs r2, 24
	str r2, [sp, 0x18]
	adds r0, r7, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	bne _080783E8
	b _0807856A
_080783E8:
	adds r0, r5, 0
	adds r1, r7, 0
	movs r2, 0x1
	bl HasSafeguardStatus
	lsls r0, 24
	cmp r0, 0
	beq _080783FA
	b _0807856A
_080783FA:
	ldr r4, [r7, 0x70]
	ldr r0, _08078420
	adds r1, r7, 0
	movs r2, 0
	bl SetMessageArgument
	adds r1, r4, 0
	adds r1, 0xC8
	ldrb r0, [r1]
	cmp r0, 0x2
	bne _08078428
	ldr r0, _08078424
	ldr r2, [r0]
	adds r0, r5, 0
	adds r1, r7, 0
	bl sub_80522F4
	b _0807856A
	.align 2, 0
_08078420: .4byte gAvailablePokemonNames
_08078424: .4byte gUnknown_80FB994
_08078428:
	movs r6, 0
	mov r8, r1
	movs r0, 0xC9
	adds r0, r4
	mov r9, r0
	movs r1, 0xCA
	adds r1, r4
	mov r10, r1
	adds r2, r4, 0
	adds r2, 0xCB
	str r2, [sp, 0x1C]
	adds r4, 0xCC
	str r4, [sp, 0x20]
_08078442:
	ldr r0, _0807857C
	ldr r0, [r0]
	lsls r1, r6, 2
	ldr r3, _08078580
	adds r0, r3
	adds r0, r1
	ldr r4, [r0]
	adds r0, r4, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	beq _08078480
	cmp r7, r4
	beq _08078480
	ldr r0, [r4, 0x70]
	adds r0, 0xC8
	ldrb r0, [r0]
	subs r0, 0x2
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bhi _08078480
	adds r0, r5, 0
	adds r1, r4, 0
	movs r2, 0
	bl SendWaitingEndMessage
	movs r0, 0x2A
	bl sub_803E46C
_08078480:
	adds r6, 0x1
	cmp r6, 0x13
	ble _08078442
	adds r0, r7, 0
	bl sub_8041D38
	ldr r0, _08078584
	adds r1, r7, 0
	movs r2, 0
	bl SetMessageArgument
	mov r4, r8
	ldrb r0, [r4]
	cmp r0, 0
	beq _080784A8
	adds r0, r5, 0
	adds r1, r7, 0
	movs r2, 0x2
	bl SendWaitingEndMessage
_080784A8:
	movs r4, 0
	movs r0, 0x2
	mov r1, r8
	strb r0, [r1]
	ldr r0, [r5, 0x70]
	ldrb r0, [r0, 0x6]
	mov r2, r9
	strb r0, [r2]
	mov r3, sp
	ldrb r0, [r3, 0x18]
	mov r3, r10
	strb r0, [r3]
	ldr r1, _08078588
	adds r0, r7, 0
	movs r2, 0x1
	bl CalculateStatusTurns
	adds r0, 0x1
	ldr r1, [sp, 0x1C]
	strb r0, [r1]
	ldr r2, [sp, 0x20]
	strb r4, [r2]
	adds r0, r7, 0
	bl sub_806CEBC
	adds r1, r0, 0
	lsls r1, 24
	lsrs r1, 24
	adds r0, r7, 0
	bl sub_806CCB4
	ldr r0, _0807857C
	ldr r0, [r0]
	ldr r3, _0807858C
	adds r0, r3
	movs r1, 0x1
	strb r1, [r0]
	ldr r0, _08078590
	ldr r2, [r0]
	adds r0, r5, 0
	adds r1, r7, 0
	bl sub_80522F4
	movs r6, 0
	mov r8, r6
_08078502:
	ldr r0, _0807857C
	ldr r0, [r0]
	lsls r1, r6, 2
	ldr r4, _08078580
	adds r0, r4
	adds r0, r1
	ldr r0, [r0]
	mov r9, r0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	beq _0807855E
	mov r5, r9
	ldr r4, [r5, 0x70]
	adds r1, r4, 0
	adds r1, 0x78
	movs r0, 0x6
	strb r0, [r1]
	adds r0, r4, 0
	adds r0, 0x80
	mov r1, r8
	str r1, [r0]
	subs r0, 0x4
	strh r1, [r0]
	ldrb r0, [r4, 0x7]
	cmp r0, 0
	bne _0807855E
	mov r1, sp
	adds r0, r4, 0
	adds r0, 0x44
	ldm r0!, {r2,r3,r5}
	stm r1!, {r2,r3,r5}
	ldm r0!, {r2,r3,r5}
	stm r1!, {r2,r3,r5}
	mov r0, r9
	movs r1, 0x1
	bl MoveIfPossible
	adds r1, r4, 0
	adds r1, 0x44
	mov r0, sp
	ldm r0!, {r2-r4}
	stm r1!, {r2-r4}
	ldm r0!, {r2,r3,r5}
	stm r1!, {r2,r3,r5}
_0807855E:
	adds r6, 0x1
	cmp r6, 0x13
	ble _08078502
	adds r0, r7, 0
	bl DungeonEntityUpdateStatusSprites
_0807856A:
	add sp, 0x24
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_0807857C: .4byte gDungeonGlobalData
_08078580: .4byte 0x000135cc
_08078584: .4byte gAvailablePokemonNames
_08078588: .4byte gUnknown_80F4ED0
_0807858C: .4byte 0x000037fc
_08078590: .4byte gUnknown_80FB978
	thumb_func_end sub_80783C4

	thumb_func_start sub_8078594
sub_8078594:
	push {r4-r7,lr}
	adds r5, r0, 0
	adds r6, r1, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	beq _0807866E
	adds r0, r6, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	beq _0807866E
	ldr r4, [r5, 0x70]
	ldr r7, [r6, 0x70]
	adds r0, r5, 0
	movs r1, 0xE
	bl HasType
	lsls r0, 24
	cmp r0, 0
	beq _08078640
	adds r0, r5, 0
	adds r1, r6, 0
	movs r2, 0x1
	bl HasSafeguardStatus
	lsls r0, 24
	cmp r0, 0
	bne _0807866E
	adds r0, r5, 0
	adds r1, r6, 0
	movs r2, 0x1
	bl SendWaitingEndMessage
	adds r0, r6, 0
	bl sub_8041D48
	movs r1, 0xE
	ldrsh r0, [r4, r1]
	lsrs r1, r0, 31
	adds r0, r1
	asrs r0, 1
	strh r0, [r4, 0xE]
	cmp r0, 0
	bne _080785F6
	movs r0, 0x1
	strh r0, [r4, 0xE]
_080785F6:
	adds r1, r7, 0
	adds r1, 0xC8
	ldrb r0, [r1]
	cmp r0, 0x1
	beq _0807861C
	movs r0, 0x1
	strb r0, [r1]
	ldr r1, _08078634
	adds r0, r6, 0
	movs r2, 0x1
	bl CalculateStatusTurns
	adds r0, 0x1
	adds r1, r7, 0
	adds r1, 0xCB
	strb r0, [r1]
	adds r1, 0x1
	movs r0, 0
	strb r0, [r1]
_0807861C:
	ldr r0, _08078638
	adds r1, r6, 0
	movs r2, 0
	bl SetMessageArgument
	ldr r0, _0807863C
	ldr r2, [r0]
	adds r0, r5, 0
	adds r1, r6, 0
	bl sub_80522F4
	b _08078668
	.align 2, 0
_08078634: .4byte gUnknown_80F4EA4
_08078638: .4byte gAvailablePokemonNames
_0807863C: .4byte gUnknown_80FB004
_08078640:
	ldr r0, _08078674
	ldr r4, [r0]
	adds r0, r5, 0
	adds r1, r5, 0
	adds r2, r4, 0
	movs r3, 0x1
	bl sub_8077084
	adds r0, r5, 0
	adds r1, r5, 0
	adds r2, r4, 0
	movs r3, 0x1
	bl sub_8077160
	adds r0, r5, 0
	adds r1, r5, 0
	movs r2, 0x1
	movs r3, 0x1
	bl sub_80779F0
_08078668:
	adds r0, r6, 0
	bl DungeonEntityUpdateStatusSprites
_0807866E:
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_08078674: .4byte gUnknown_8106A4C
	thumb_func_end sub_8078594

	thumb_func_start sub_8078678
sub_8078678:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	adds r7, r0, 0
	adds r6, r1, 0
	adds r0, r6, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	beq _08078732
	adds r0, r7, 0
	adds r1, r6, 0
	movs r2, 0x3
	bl SendWaitingEndMessage
	movs r5, 0
_0807869A:
	ldr r0, _0807873C
	ldr r0, [r0]
	lsls r1, r5, 2
	ldr r2, _08078740
	adds r0, r2
	adds r0, r1
	ldr r4, [r0]
	adds r0, r4, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	beq _080786C8
	ldr r0, [r4, 0x70]
	adds r0, 0xC8
	ldrb r0, [r0]
	cmp r0, 0x3
	bne _080786C8
	adds r0, r7, 0
	adds r1, r4, 0
	movs r2, 0
	bl SendWaitingEndMessage
_080786C8:
	adds r5, 0x1
	cmp r5, 0x13
	ble _0807869A
	adds r0, r6, 0
	bl nullsub_81
	ldr r5, [r6, 0x70]
	mov r8, r5
	adds r1, r5, 0
	adds r1, 0xC8
	ldrb r0, [r1]
	cmp r0, 0x3
	beq _08078700
	movs r4, 0
	movs r0, 0x3
	strb r0, [r1]
	ldr r1, _08078744
	adds r0, r6, 0
	movs r2, 0
	bl CalculateStatusTurns
	adds r0, 0x1
	adds r1, r5, 0
	adds r1, 0xCB
	strb r0, [r1]
	adds r0, r5, 0
	adds r0, 0xCC
	strb r4, [r0]
_08078700:
	ldr r0, _0807873C
	ldr r1, [r0]
	ldr r2, _08078748
	adds r0, r1, r2
	str r6, [r0]
	ldr r0, _0807874C
	adds r1, r0
	mov r0, r8
	adds r0, 0x98
	ldr r0, [r0]
	str r0, [r1]
	ldr r0, _08078750
	adds r1, r6, 0
	movs r2, 0
	bl SetMessageArgument
	ldr r0, _08078754
	ldr r2, [r0]
	adds r0, r7, 0
	adds r1, r6, 0
	bl sub_80522F4
	adds r0, r6, 0
	bl DungeonEntityUpdateStatusSprites
_08078732:
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_0807873C: .4byte gDungeonGlobalData
_08078740: .4byte 0x000135cc
_08078744: .4byte gUnknown_80F4EA8
_08078748: .4byte 0x00017b30
_0807874C: .4byte 0x00017b3c
_08078750: .4byte gAvailablePokemonNames
_08078754: .4byte gUnknown_80FB01C
	thumb_func_end sub_8078678

	thumb_func_start sub_8078758
sub_8078758:
	push {r4-r6,lr}
	adds r5, r0, 0
	adds r4, r1, 0
	adds r0, r4, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	beq _080787DA
	adds r0, r5, 0
	adds r1, r4, 0
	movs r2, 0x1
	bl HasSafeguardStatus
	lsls r0, 24
	cmp r0, 0
	bne _080787DA
	ldr r6, [r4, 0x70]
	ldr r0, _080787BC
	adds r1, r4, 0
	movs r2, 0
	bl SetMessageArgument
	adds r1, r6, 0
	adds r1, 0xBC
	ldrb r0, [r1]
	cmp r0, 0x5
	beq _080787C8
	movs r0, 0x5
	strb r0, [r1]
	ldr r1, _080787C0
	adds r0, r4, 0
	movs r2, 0x1
	bl CalculateStatusTurns
	adds r0, 0x1
	adds r1, r6, 0
	adds r1, 0xBD
	strb r0, [r1]
	adds r0, r4, 0
	bl nullsub_73
	ldr r0, _080787C4
	ldr r2, [r0]
	adds r0, r5, 0
	adds r1, r4, 0
	bl sub_80522F4
	b _080787D4
	.align 2, 0
_080787BC: .4byte gAvailablePokemonNames
_080787C0: .4byte gUnknown_80F4ED8
_080787C4: .4byte gUnknown_80FB9F0
_080787C8:
	ldr r0, _080787E0
	ldr r2, [r0]
	adds r0, r5, 0
	adds r1, r4, 0
	bl sub_80522F4
_080787D4:
	adds r0, r4, 0
	bl DungeonEntityUpdateStatusSprites
_080787DA:
	pop {r4-r6}
	pop {r0}
	bx r0
	.align 2, 0
_080787E0: .4byte gUnknown_80FBA14
	thumb_func_end sub_8078758

	thumb_func_start sub_80787E4
sub_80787E4:
	push {r4-r6,lr}
	adds r6, r0, 0
	adds r5, r1, 0
	adds r0, r5, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	beq _08078852
	ldr r4, [r5, 0x70]
	ldr r0, _08078834
	adds r1, r5, 0
	movs r2, 0
	bl SetMessageArgument
	movs r0, 0x89
	lsls r0, 1
	adds r4, r0
	ldrb r0, [r4]
	cmp r0, 0x2
	bhi _08078840
	adds r0, 0x1
	strb r0, [r4]
	movs r0, 0x1
	bl sub_804178C
	adds r0, r5, 0
	bl sub_8041D5C
	ldr r1, _08078838
	ldrb r0, [r4]
	str r0, [r1]
	ldr r0, _0807883C
	ldr r2, [r0]
	adds r0, r6, 0
	adds r1, r5, 0
	bl sub_80522F4
	b _0807884C
	.align 2, 0
_08078834: .4byte gAvailablePokemonNames
_08078838: .4byte gUnknown_202DE30
_0807883C: .4byte gUnknown_80FBA38
_08078840:
	ldr r0, _08078858
	ldr r2, [r0]
	adds r0, r6, 0
	adds r1, r5, 0
	bl sub_80522F4
_0807884C:
	adds r0, r5, 0
	bl DungeonEntityUpdateStatusSprites
_08078852:
	pop {r4-r6}
	pop {r0}
	bx r0
	.align 2, 0
_08078858: .4byte gUnknown_80FBA60
	thumb_func_end sub_80787E4

	thumb_func_start sub_807885C
sub_807885C:
	push {r4-r7,lr}
	adds r6, r0, 0
	adds r4, r1, 0
	adds r0, r4, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	beq _080788DE
	ldr r0, [r4, 0x70]
	adds r7, r0, 0
	adds r5, r7, 0
	adds r5, 0xE4
	ldrb r0, [r5]
	cmp r0, 0x2
	bne _08078884
	adds r0, r6, 0
	adds r1, r4, 0
	bl SendTransformEndMessage
_08078884:
	ldr r0, _080788C0
	adds r1, r4, 0
	movs r2, 0
	bl SetMessageArgument
	ldrb r0, [r5]
	cmp r0, 0x1
	beq _080788CC
	movs r0, 0x1
	strb r0, [r5]
	ldr r1, _080788C4
	adds r0, r4, 0
	movs r2, 0
	bl CalculateStatusTurns
	adds r0, 0x1
	adds r1, r7, 0
	adds r1, 0xE5
	strb r0, [r1]
	adds r0, r4, 0
	bl sub_8041D84
	ldr r0, _080788C8
	ldr r2, [r0]
	adds r0, r6, 0
	adds r1, r4, 0
	bl sub_80522F4
	b _080788D8
	.align 2, 0
_080788C0: .4byte gAvailablePokemonNames
_080788C4: .4byte gUnknown_80F4EE4
_080788C8: .4byte gUnknown_80FBA80
_080788CC:
	ldr r0, _080788E4
	ldr r2, [r0]
	adds r0, r6, 0
	adds r1, r4, 0
	bl sub_80522F4
_080788D8:
	adds r0, r4, 0
	bl DungeonEntityUpdateStatusSprites
_080788DE:
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_080788E4: .4byte gUnknown_80FBAA0
	thumb_func_end sub_807885C

	thumb_func_start sub_80788E8
sub_80788E8:
	push {r4-r6,lr}
	adds r6, r0, 0
	adds r5, r1, 0
	adds r0, r5, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	beq _0807895E
	adds r0, r6, 0
	adds r1, r5, 0
	movs r2, 0x1
	bl HasSafeguardStatus
	lsls r0, 24
	cmp r0, 0
	bne _0807895E
	adds r0, r5, 0
	bl nullsub_82
	ldr r4, [r5, 0x70]
	ldr r0, _08078940
	adds r1, r5, 0
	movs r2, 0
	bl SetMessageArgument
	adds r4, 0xFD
	ldrb r0, [r4]
	cmp r0, 0
	bne _0807894C
	ldr r1, _08078944
	adds r0, r5, 0
	movs r2, 0
	bl CalculateStatusTurns
	adds r0, 0x1
	strb r0, [r4]
	ldr r0, _08078948
	ldr r2, [r0]
	adds r0, r6, 0
	adds r1, r5, 0
	bl sub_80522F4
	b _08078958
	.align 2, 0
_08078940: .4byte gAvailablePokemonNames
_08078944: .4byte gUnknown_80F4EEC
_08078948: .4byte gUnknown_80FBB04
_0807894C:
	ldr r0, _08078964
	ldr r2, [r0]
	adds r0, r6, 0
	adds r1, r5, 0
	bl sub_80522F4
_08078958:
	adds r0, r5, 0
	bl DungeonEntityUpdateStatusSprites
_0807895E:
	pop {r4-r6}
	pop {r0}
	bx r0
	.align 2, 0
_08078964: .4byte gUnknown_80FBB28
	thumb_func_end sub_80788E8

	thumb_func_start sub_8078968
sub_8078968:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	adds r6, r0, 0
	adds r4, r1, 0
	ldr r5, [r4, 0x70]
	adds r0, r4, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	beq _08078A4A
	adds r0, r6, 0
	adds r1, r4, 0
	movs r2, 0x1
	bl HasSafeguardStatus
	lsls r0, 24
	cmp r0, 0
	bne _08078A4A
	movs r3, 0
	ldr r0, _080789E8
	mov r8, r0
	movs r1, 0x1
	mov r12, r1
	movs r0, 0x8C
	lsls r0, 1
	adds r2, r5, r0
	movs r7, 0x10
_080789A2:
	ldrb r1, [r2]
	mov r0, r12
	ands r0, r1
	cmp r0, 0
	beq _080789B4
	adds r0, r7, 0
	ands r0, r1
	cmp r0, 0
	bne _080789BC
_080789B4:
	adds r2, 0x8
	adds r3, 0x1
	cmp r3, 0x3
	ble _080789A2
_080789BC:
	cmp r3, 0x4
	bne _080789F0
	movs r1, 0x9C
	lsls r1, 1
	adds r0, r5, r1
	ldrb r1, [r0]
	movs r0, 0x10
	ands r0, r1
	cmp r0, 0
	bne _080789F0
	mov r0, r8
	adds r1, r4, 0
	movs r2, 0
	bl SetMessageArgument
	ldr r0, _080789EC
	ldr r2, [r0]
	adds r0, r6, 0
	adds r1, r4, 0
	bl sub_80522F4
	b _08078A4A
	.align 2, 0
_080789E8: .4byte gAvailablePokemonNames
_080789EC: .4byte gUnknown_80FBBD4
_080789F0:
	mov r0, r8
	adds r1, r4, 0
	movs r2, 0
	bl SetMessageArgument
	adds r1, r5, 0
	adds r1, 0xBC
	ldrb r0, [r1]
	cmp r0, 0x6
	beq _08078A38
	movs r0, 0x6
	strb r0, [r1]
	ldr r1, _08078A30
	adds r0, r4, 0
	movs r2, 0x1
	bl CalculateStatusTurns
	adds r0, 0x1
	adds r1, r5, 0
	adds r1, 0xBD
	strb r0, [r1]
	adds r0, r4, 0
	bl nullsub_83
	ldr r0, _08078A34
	ldr r2, [r0]
	adds r0, r6, 0
	adds r1, r4, 0
	bl sub_80522F4
	b _08078A44
	.align 2, 0
_08078A30: .4byte gUnknown_80F4EF4
_08078A34: .4byte gUnknown_80FBB94
_08078A38:
	ldr r0, _08078A54
	ldr r2, [r0]
	adds r0, r6, 0
	adds r1, r4, 0
	bl sub_80522F4
_08078A44:
	adds r0, r4, 0
	bl DungeonEntityUpdateStatusSprites
_08078A4A:
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_08078A54: .4byte gUnknown_80FBBB8
	thumb_func_end sub_8078968

	thumb_func_start sub_8078A58
sub_8078A58:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0x14
	mov r8, r0
	adds r6, r1, 0
	adds r7, r2, 0
	adds r5, r3, 0
	adds r0, r6, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	beq _08078B4A
	ldr r4, [r6, 0x70]
	cmp r5, 0
	beq _08078AE0
	mov r0, sp
	adds r1, r5, 0
	bl sub_80943A0
	ldr r2, [sp]
	movs r0, 0xA0
	lsls r0, 1
	adds r5, r4, r0
	ldr r7, [r5]
	add r0, sp, 0x4
	adds r1, r7, 0
	bl sub_80942C0
	ldr r2, [sp, 0x4]
	str r2, [r5]
	movs r0, 0x9E
	lsls r0, 1
	adds r4, r0
	ldr r1, [r4]
	add r0, sp, 0x8
	bl sub_8094318
	ldr r0, [sp, 0x8]
	str r0, [r4]
	ldr r0, _08078AD0
	adds r1, r6, 0
	movs r2, 0
	bl SetMessageArgument
	adds r0, r7, 0
	bl RoundUpFixedPoint
	adds r4, r0, 0
	ldr r0, [r5]
	bl RoundUpFixedPoint
	cmp r4, r0
	beq _08078AD8
	adds r0, r6, 0
	bl sub_8041D9C
	ldr r0, _08078AD4
	b _08078B22
	.align 2, 0
_08078AD0: .4byte gAvailablePokemonNames
_08078AD4: .4byte gUnknown_80FBD9C
_08078AD8:
	ldr r0, _08078ADC
	b _08078B22
	.align 2, 0
_08078ADC: .4byte gUnknown_80FBE3C
_08078AE0:
	add r0, sp, 0xC
	adds r1, r7, 0
	bl sub_80943A0
	ldr r2, [sp, 0xC]
	movs r0, 0x9E
	lsls r0, 1
	adds r4, r0
	ldr r7, [r4]
	add r0, sp, 0x10
	adds r1, r7, 0
	bl sub_80942C0
	ldr r0, [sp, 0x10]
	str r0, [r4]
	ldr r0, _08078B30
	adds r1, r6, 0
	movs r2, 0
	bl SetMessageArgument
	adds r0, r7, 0
	bl RoundUpFixedPoint
	adds r5, r0, 0
	ldr r0, [r4]
	bl RoundUpFixedPoint
	cmp r5, r0
	beq _08078B38
	adds r0, r6, 0
	bl nullsub_84
	ldr r0, _08078B34
_08078B22:
	ldr r2, [r0]
	mov r0, r8
	adds r1, r6, 0
	bl sub_80522F4
	b _08078B44
	.align 2, 0
_08078B30: .4byte gAvailablePokemonNames
_08078B34: .4byte gUnknown_80FBD78
_08078B38:
	ldr r0, _08078B58
	ldr r2, [r0]
	mov r0, r8
	adds r1, r6, 0
	bl sub_80522F4
_08078B44:
	adds r0, r6, 0
	bl DungeonEntityUpdateStatusSprites
_08078B4A:
	add sp, 0x14
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_08078B58: .4byte gUnknown_80FBE40
	thumb_func_end sub_8078A58

	thumb_func_start sub_8078B5C
sub_8078B5C:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x28
	mov r9, r0
	adds r6, r1, 0
	mov r10, r2
	str r3, [sp, 0x1C]
	ldr r0, [sp, 0x48]
	lsls r0, 24
	lsrs r0, 24
	mov r8, r0
	adds r0, r6, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	bne _08078B86
	b _08078D78
_08078B86:
	ldr r7, [r6, 0x70]
	ldrb r0, [r7, 0x7]
	cmp r0, 0
	bne _08078BB8
	adds r0, r6, 0
	movs r1, 0x1B
	bl HasItem
	lsls r0, 24
	cmp r0, 0
	beq _08078BB8
	mov r0, r8
	cmp r0, 0
	bne _08078BA4
	b _08078D78
_08078BA4:
	ldr r0, _08078BB4
	ldr r2, [r0]
	mov r0, r9
	adds r1, r6, 0
	bl sub_80522F4
	b _08078D78
	.align 2, 0
_08078BB4: .4byte gUnknown_80FBEA0
_08078BB8:
	movs r5, 0
	ldr r1, [sp, 0x1C]
	cmp r1, 0
	beq _08078BE8
	movs r1, 0x9E
	lsls r1, 1
	adds r0, r7, r1
	ldr r0, [r0]
	bl RoundUpFixedPoint
	adds r4, r0, 0
	movs r1, 0xA0
	lsls r1, 1
	adds r0, r7, r1
	ldr r0, [r0]
	bl RoundUpFixedPoint
	cmp r4, r0
	blt _08078BE0
	movs r5, 0x1
_08078BE0:
	ldr r0, _08078C8C
	cmp r10, r0
	bne _08078BE8
	movs r5, 0x1
_08078BE8:
	cmp r5, 0
	beq _08078CC0
	movs r0, 0xA0
	lsls r0, 1
	adds r5, r7, r0
	ldr r1, [r5]
	str r1, [sp, 0x20]
	subs r0, 0x4
	adds r0, r7
	mov r10, r0
	ldr r0, [r0]
	bl RoundUpFixedPoint
	adds r4, r0, 0
	ldr r0, [r5]
	bl RoundUpFixedPoint
	movs r1, 0
	str r1, [sp, 0x24]
	cmp r4, r0
	bne _08078C16
	movs r0, 0x1
	str r0, [sp, 0x24]
_08078C16:
	mov r0, sp
	ldr r1, [sp, 0x1C]
	bl sub_80943A0
	ldr r2, [sp]
	ldr r1, [r5]
	add r0, sp, 0x4
	bl sub_8094268
	ldr r4, [sp, 0x4]
	str r4, [r5]
	add r0, sp, 0x8
	movs r1, 0xC8
	bl sub_80943A0
	ldr r2, [sp, 0x8]
	add r0, sp, 0xC
	adds r1, r4, 0
	bl sub_8094318
	ldr r0, [sp, 0xC]
	str r0, [r5]
	mov r1, r10
	str r0, [r1]
	ldr r0, [sp, 0x24]
	cmp r0, 0
	bne _08078C5E
	mov r1, r8
	cmp r1, 0
	beq _08078C5E
	ldr r0, _08078C90
	ldr r2, [r0]
	mov r0, r9
	adds r1, r6, 0
	bl sub_80522F4
_08078C5E:
	ldr r0, [sp, 0x20]
	bl RoundUpFixedPoint
	adds r4, r0, 0
	movs r1, 0xA0
	lsls r1, 1
	adds r0, r7, r1
	ldr r0, [r0]
	bl RoundUpFixedPoint
	cmp r4, r0
	bne _08078C9C
	ldr r0, _08078C94
	adds r1, r6, 0
	movs r2, 0
	bl SetMessageArgument
	mov r0, r8
	cmp r0, 0
	beq _08078D72
	ldr r0, _08078C98
	b _08078D4E
	.align 2, 0
_08078C8C: .4byte 0x000003e7
_08078C90: .4byte gUnknown_80FBE64
_08078C94: .4byte gAvailablePokemonNames
_08078C98: .4byte gUnknown_80FBDF0
_08078C9C:
	adds r0, r6, 0
	bl sub_8041DB0
	ldr r0, _08078CB8
	adds r1, r6, 0
	movs r2, 0
	bl SetMessageArgument
	mov r1, r8
	cmp r1, 0
	beq _08078D72
	ldr r0, _08078CBC
	b _08078D4E
	.align 2, 0
_08078CB8: .4byte gAvailablePokemonNames
_08078CBC: .4byte gUnknown_80FBDC4
_08078CC0:
	movs r0, 0x9E
	lsls r0, 1
	adds r5, r7, r0
	ldr r4, [r5]
	add r0, sp, 0x10
	mov r1, r10
	bl sub_80943A0
	ldr r2, [sp, 0x10]
	ldr r1, [r5]
	add r0, sp, 0x14
	bl sub_8094268
	ldr r1, [sp, 0x14]
	str r1, [r5]
	movs r0, 0xA0
	lsls r0, 1
	adds r7, r0
	ldr r2, [r7]
	add r0, sp, 0x18
	bl sub_8094318
	ldr r0, [sp, 0x18]
	str r0, [r5]
	ldr r0, _08078D28
	cmp r10, r0
	bne _08078CFA
	ldr r0, [r7]
	str r0, [r5]
_08078CFA:
	adds r0, r6, 0
	bl nullsub_85
	ldr r0, _08078D2C
	adds r1, r6, 0
	movs r2, 0
	bl SetMessageArgument
	adds r0, r4, 0
	bl RoundUpFixedPoint
	adds r4, r0, 0
	ldr r0, [r5]
	bl RoundUpFixedPoint
	cmp r4, r0
	bne _08078D34
	mov r1, r8
	cmp r1, 0
	beq _08078D72
	ldr r0, _08078D30
	b _08078D4E
	.align 2, 0
_08078D28: .4byte 0x000003e7
_08078D2C: .4byte gAvailablePokemonNames
_08078D30: .4byte gUnknown_80FBE14
_08078D34:
	ldr r0, [r5]
	bl RoundUpFixedPoint
	adds r4, r0, 0
	ldr r0, [r7]
	bl RoundUpFixedPoint
	cmp r4, r0
	blt _08078D60
	mov r0, r8
	cmp r0, 0
	beq _08078D72
	ldr r0, _08078D5C
_08078D4E:
	ldr r2, [r0]
	mov r0, r9
	adds r1, r6, 0
	bl sub_80522F4
	b _08078D72
	.align 2, 0
_08078D5C: .4byte gUnknown_80FBE64
_08078D60:
	mov r1, r8
	cmp r1, 0
	beq _08078D72
	ldr r0, _08078D88
	ldr r2, [r0]
	mov r0, r9
	adds r1, r6, 0
	bl sub_80522F4
_08078D72:
	adds r0, r6, 0
	bl DungeonEntityUpdateStatusSprites
_08078D78:
	add sp, 0x28
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_08078D88: .4byte gUnknown_80FBE84
	thumb_func_end sub_8078B5C

        .align 2,0
