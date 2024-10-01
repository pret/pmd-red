	#include "asm/constants/gba_constants.inc"
  	#include "asm/macros.inc"

  	.syntax unified

  	.text

	thumb_func_start sub_8045DB4
sub_8045DB4:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0xB8
	mov r10, r0
	lsls r1, 24
	lsrs r1, 24
	str r1, [sp, 0xA8]
	bl GetLeader
	adds r7, r0, 0
	ldr r0, [r7, 0x70]
	str r0, [sp, 0xAC]
	mov r1, r10
	movs r2, 0
	ldrsh r0, [r1, r2]
	movs r3, 0x2
	ldrsh r1, [r1, r3]
	bl GetTile
	ldr r4, [r0, 0x14]
	cmp r4, 0
	bne _08045DE8
	b _080460E0
_08045DE8:
	adds r0, r4, 0
	bl GetEntityType
	cmp r0, 0x3
	beq _08045DF4
	b _080460E0
_08045DF4:
	adds r0, r4, 0
	bl GetItemData
	adds r5, r0, 0
	ldr r0, [sp, 0xAC]
	adds r0, 0x48
	ldrb r0, [r0]
	cmp r0, 0
	bne _08045E08
	b _0804602E
_08045E08:
	adds r0, r7, 0
	movs r1, 0x1
	bl ShouldMonsterRunAwayAndShowEffect
	lsls r0, 24
	cmp r0, 0
	beq _08045E40
	ldr r0, [sp, 0xA8]
	cmp r0, 0
	bne _08045E1E
	b _080460E0
_08045E1E:
	ldr r0, _08045E34
	adds r1, r5, 0
	bl sub_8045BF8
	ldr r0, _08045E38
	adds r1, r7, 0
	movs r2, 0
	bl SetMessageArgument
	ldr r0, _08045E3C
	b _08046048
	.align 2, 0
_08045E34: .4byte gFormatItems
_08045E38: .4byte gAvailablePokemonNames
_08045E3C: .4byte gMonTerrifiedCouldntPickUpItem
_08045E40:
	ldrb r0, [r5, 0x2]
	bl GetItemCategory
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x6
	bne _08045E7C
	movs r0, 0xA6
	lsls r0, 1
	bl PlaySoundEffect
	adds r0, r5, 0
	bl GetMoneyValue
	bl AddToTeamMoney
	ldr r0, _08045E74
	adds r1, r5, 0
	bl sub_8045BF8
	mov r0, r10
	movs r1, 0x1
	bl sub_80461C8
	ldr r0, _08045E78
	b _08045FD0
	.align 2, 0
_08045E74: .4byte gFormatItems
_08045E78: .4byte gPickedUpItem
_08045E7C:
	ldr r0, _08045EA8
	ldr r0, [r0]
	ldr r1, _08045EAC
	adds r0, r1
	ldrb r0, [r0]
	cmp r0, 0
	beq _08045EB4
	movs r4, 0
	ldr r0, _08045EB0
	mov r2, sp
	ldr r0, [r0]
	add r1, sp, 0x54
_08045E94:
	stm r1!, {r0}
	stm r2!, {r4}
	adds r0, 0x4
	adds r4, 0x1
	cmp r4, 0x13
	ble _08045E94
	movs r2, 0x14
	mov r8, r2
	b _08045EC4
	.align 2, 0
_08045EA8: .4byte gDungeon
_08045EAC: .4byte 0x0000065b
_08045EB0: .4byte gTeamInventoryRef
_08045EB4:
	ldr r0, [sp, 0xAC]
	adds r0, 0x60
	str r0, [sp, 0x54]
	movs r0, 0x1
	negs r0, r0
	str r0, [sp]
	movs r3, 0x1
	mov r8, r3
_08045EC4:
	ldrb r0, [r5, 0x2]
	add r6, sp, 0xB0
	strb r0, [r6]
	cmp r0, 0x8
	bls _08045ED0
	b _08046000
_08045ED0:
	ldrb r1, [r5]
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	beq _08045EDC
	b _08046000
_08045EDC:
	movs r1, 0x1
	negs r1, r1
	mov r12, r1
	mov r2, r12
	str r2, [sp, 0xB4]
	movs r4, 0
	cmp r4, r8
	bge _08045F2C
	ldr r3, _08045FDC
	mov r9, r3
	add r3, sp, 0x54
_08045EF2:
	ldr r2, [r3]
	ldrb r1, [r2]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _08045F24
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	bne _08045F24
	ldr r1, [r5]
	mov r6, r9
	ands r1, r6
	ldr r0, [r2]
	ands r0, r6
	cmp r1, r0
	bne _08045F24
	ldrb r0, [r2, 0x1]
	cmp r0, 0x63
	beq _08045F24
	ldr r1, [sp, 0xB4]
	cmp r1, r0
	bge _08045F24
	str r0, [sp, 0xB4]
	mov r12, r4
_08045F24:
	adds r3, 0x4
	adds r4, 0x1
	cmp r4, r8
	blt _08045EF2
_08045F2C:
	movs r0, 0x1
	negs r0, r0
	cmp r12, r0
	bne _08045F80
	mov r2, r12
	str r2, [sp, 0xB4]
	movs r4, 0
	cmp r4, r8
	bge _08045F78
	add r3, sp, 0xB0
	ldrb r3, [r3]
	mov r9, r3
	add r3, sp, 0x54
_08045F46:
	ldr r2, [r3]
	ldrb r1, [r2]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _08045F70
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	bne _08045F70
	ldrb r6, [r2, 0x2]
	cmp r9, r6
	bne _08045F70
	ldrb r0, [r2, 0x1]
	cmp r0, 0x63
	beq _08045F70
	ldr r1, [sp, 0xB4]
	cmp r1, r0
	bge _08045F70
	str r0, [sp, 0xB4]
	mov r12, r4
_08045F70:
	adds r3, 0x4
	adds r4, 0x1
	cmp r4, r8
	blt _08045F46
_08045F78:
	movs r0, 0x1
	negs r0, r0
	cmp r12, r0
	beq _08046000
_08045F80:
	add r0, sp, 0x54
	mov r2, r12
	lsls r4, r2, 2
	adds r3, r0, r4
	ldr r2, [r3]
	ldrb r1, [r2, 0x1]
	ldrb r0, [r5, 0x1]
	adds r1, r0
	cmp r1, 0x62
	ble _08045F96
	movs r1, 0x63
_08045F96:
	strb r1, [r2, 0x1]
	ldrb r1, [r5]
	movs r0, 0x8
	ands r0, r1
	cmp r0, 0
	beq _08045FAC
	ldr r0, [r3]
	ldrb r1, [r0]
	movs r2, 0x8
	orrs r1, r2
	strb r1, [r0]
_08045FAC:
	ldr r0, _08045FE0
	adds r1, r5, 0
	bl sub_8045BF8
	mov r0, r10
	movs r1, 0x1
	bl sub_80461C8
	movs r0, 0xA5
	lsls r0, 1
	bl PlaySoundEffect
	mov r3, sp
	adds r0, r3, r4
	ldr r0, [r0]
	cmp r0, 0
	bge _08045FE8
	ldr r0, _08045FE4
_08045FD0:
	ldr r1, [r0]
	adds r0, r7, 0
	bl SendMessage
	b _08045FF2
	.align 2, 0
_08045FDC: .4byte 0x00ff0008
_08045FE0: .4byte gFormatItems
_08045FE4: .4byte gPickedUpItem2
_08045FE8:
	ldr r0, _08045FFC
	ldr r1, [r0]
	adds r0, r7, 0
	bl SendMessage
_08045FF2:
	ldrb r0, [r5, 0x2]
	bl HandleOnPickupTutorial
	b _080460E0
	.align 2, 0
_08045FFC: .4byte gPickedUpItemToolbox
_08046000:
	movs r4, 0
	cmp r4, r8
	bge _0804602A
	ldr r0, [sp, 0x54]
	ldrb r1, [r0]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _0804602A
	movs r3, 0x1
	add r2, sp, 0x54
_08046016:
	adds r2, 0x4
	adds r4, 0x1
	cmp r4, r8
	bge _0804602A
	ldr r0, [r2]
	ldrb r1, [r0]
	adds r0, r3, 0
	ands r0, r1
	cmp r0, 0
	bne _08046016
_0804602A:
	cmp r4, r8
	bne _08046060
_0804602E:
	ldr r6, [sp, 0xA8]
	cmp r6, 0
	beq _080460E0
	ldr r0, _08046054
	adds r1, r5, 0
	bl sub_8045BF8
	ldr r0, _08046058
	adds r1, r7, 0
	movs r2, 0
	bl SetMessageArgument
	ldr r0, _0804605C
_08046048:
	ldr r1, [r0]
	adds r0, r7, 0
	bl SendMessage
	b _080460E0
	.align 2, 0
_08046054: .4byte gFormatItems
_08046058: .4byte gAvailablePokemonNames
_0804605C: .4byte gMonSteppedOnItem
_08046060:
	movs r0, 0xA5
	lsls r0, 1
	bl PlaySoundEffect
	lsls r0, r4, 2
	add r0, sp
	ldr r0, [r0]
	cmp r0, 0
	bge _08046094
	ldr r0, [r5]
	ldr r1, [sp, 0xAC]
	str r0, [r1, 0x60]
	ldr r0, _0804608C
	adds r1, r5, 0
	bl sub_8045BF8
	mov r0, r10
	movs r1, 0x1
	bl sub_80461C8
	ldr r0, _08046090
	b _080460AC
	.align 2, 0
_0804608C: .4byte gFormatItems
_08046090: .4byte gPickedUpItem2
_08046094:
	adds r0, r5, 0
	bl AddItemToInventory
	lsls r0, 24
	cmp r0, 0
	beq _080460C0
	ldr r0, _080460B8
	adds r1, r7, 0
	movs r2, 0
	bl SetMessageArgument
	ldr r0, _080460BC
_080460AC:
	ldr r1, [r0]
	adds r0, r7, 0
	bl SendMessage
	b _080460DA
	.align 2, 0
_080460B8: .4byte gAvailablePokemonNames
_080460BC: .4byte gMonCouldntPickUpItem
_080460C0:
	ldr r0, _080460F0
	adds r1, r5, 0
	bl sub_8045BF8
	mov r0, r10
	movs r1, 0x1
	bl sub_80461C8
	ldr r0, _080460F4
	ldr r1, [r0]
	adds r0, r7, 0
	bl SendMessage
_080460DA:
	ldrb r0, [r5, 0x2]
	bl HandleOnPickupTutorial
_080460E0:
	add sp, 0xB8
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_080460F0: .4byte gFormatItems
_080460F4: .4byte gPickedUpItemToolbox
	thumb_func_end sub_8045DB4

	thumb_func_start sub_80460F8
sub_80460F8:
	push {r4-r7,lr}
	adds r5, r0, 0
	adds r6, r1, 0
	lsls r2, 24
	lsrs r7, r2, 24
	bl sub_8045708
	adds r4, r0, 0
	cmp r4, 0
	bne _08046110
	movs r0, 0
	b _080461B6
_08046110:
	ldr r1, [r4, 0x70]
	ldr r0, [r6]
	str r0, [r1]
	ldr r2, [r4, 0x70]
	ldrb r1, [r2]
	movs r0, 0xEF
	ands r0, r1
	strb r0, [r2]
	adds r1, r4, 0
	adds r1, 0x20
	movs r0, 0x1
	strb r0, [r1]
	movs r1, 0
	ldrsh r0, [r5, r1]
	movs r2, 0x2
	ldrsh r1, [r5, r2]
	bl GetTileSafe
	str r4, [r0, 0x14]
	ldrh r1, [r0]
	movs r0, 0x20
	ands r0, r1
	cmp r0, 0
	beq _08046186
	ldrb r0, [r6, 0x2]
	bl CanSellItem
	lsls r0, 24
	cmp r0, 0
	beq _08046186
	ldrb r1, [r6]
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	beq _08046170
	cmp r7, 0
	beq _08046186
	adds r0, r6, 0
	bl GetStackBuyPrice
	ldr r1, _08046168
	ldr r2, [r1]
	ldr r1, _0804616C
	b _0804617E
	.align 2, 0
_08046168: .4byte gDungeon
_0804616C: .4byte 0x0000068c
_08046170:
	adds r0, r6, 0
	bl GetStackSellPrice
	ldr r1, _080461BC
	ldr r2, [r1]
	movs r1, 0xD2
	lsls r1, 3
_0804617E:
	adds r2, r1
	ldr r1, [r2]
	adds r1, r0
	str r1, [r2]
_08046186:
	movs r6, 0
	movs r4, 0
_0804618A:
	ldr r5, _080461BC
	ldr r0, [r5]
	lsls r1, r4, 2
	ldr r2, _080461C0
	adds r0, r2
	adds r0, r1
	ldr r0, [r0]
	bl EntityExists
	lsls r0, 24
	adds r1, r4, 0x1
	cmp r0, 0
	beq _080461A6
	adds r6, r1, 0
_080461A6:
	adds r4, r1, 0
	cmp r4, 0x3F
	ble _0804618A
	ldr r0, [r5]
	ldr r1, _080461C4
	adds r0, r1
	strh r6, [r0]
	movs r0, 0x1
_080461B6:
	pop {r4-r7}
	pop {r1}
	bx r1
	.align 2, 0
_080461BC: .4byte gDungeon
_080461C0: .4byte 0x0001361c
_080461C4: .4byte 0x00003904
	thumb_func_end sub_80460F8

	thumb_func_start sub_80461C8
sub_80461C8:
	push {r4-r7,lr}
	adds r2, r0, 0
	lsls r1, 24
	lsrs r7, r1, 24
	movs r1, 0
	ldrsh r0, [r2, r1]
	movs r3, 0x2
	ldrsh r1, [r2, r3]
	bl GetTileSafe
	adds r6, r0, 0
	ldr r5, [r6, 0x14]
	cmp r5, 0
	beq _080461EE
	adds r0, r5, 0
	bl GetEntityType
	cmp r0, 0x3
	beq _080461F2
_080461EE:
	movs r0, 0
	b _08046284
_080461F2:
	adds r0, r5, 0
	bl GetItemData
	adds r4, r0, 0
	ldrh r1, [r6]
	movs r0, 0x20
	ands r0, r1
	cmp r0, 0
	beq _0804624E
	ldrb r0, [r4, 0x2]
	bl CanSellItem
	lsls r0, 24
	cmp r0, 0
	beq _0804624E
	ldrb r1, [r4]
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	beq _08046238
	cmp r7, 0
	beq _0804624E
	adds r0, r4, 0
	bl GetStackBuyPrice
	ldr r1, _08046230
	ldr r2, [r1]
	ldr r1, _08046234
	adds r2, r1
	b _08046248
	.align 2, 0
_08046230: .4byte gDungeon
_08046234: .4byte 0x0000068c
_08046238:
	adds r0, r4, 0
	bl GetStackSellPrice
	ldr r1, _0804628C
	ldr r2, [r1]
	movs r3, 0xD2
	lsls r3, 3
	adds r2, r3
_08046248:
	ldr r1, [r2]
	subs r1, r0
	str r1, [r2]
_0804624E:
	movs r0, 0
	str r0, [r6, 0x14]
	str r0, [r5]
	movs r6, 0
	movs r4, 0
_08046258:
	ldr r5, _0804628C
	ldr r0, [r5]
	lsls r1, r4, 2
	ldr r2, _08046290
	adds r0, r2
	adds r0, r1
	ldr r0, [r0]
	bl EntityExists
	lsls r0, 24
	adds r1, r4, 0x1
	cmp r0, 0
	beq _08046274
	adds r6, r1, 0
_08046274:
	adds r4, r1, 0
	cmp r4, 0x3F
	ble _08046258
	ldr r0, [r5]
	ldr r3, _08046294
	adds r0, r3
	strh r6, [r0]
	movs r0, 0x1
_08046284:
	pop {r4-r7}
	pop {r1}
	bx r1
	.align 2, 0
_0804628C: .4byte gDungeon
_08046290: .4byte 0x0001361c
_08046294: .4byte 0x00003904
	thumb_func_end sub_80461C8

	thumb_func_start sub_8046298
sub_8046298:
	ldrb r0, [r0, 0x2]
	ldr r1, _080462A8
	ldr r1, [r1]
	lsls r0, 5
	adds r0, r1
	ldrb r0, [r0, 0xD]
	bx lr
	.align 2, 0
_080462A8: .4byte gItemParametersData
	thumb_func_end sub_8046298

	thumb_func_start sub_80462AC
sub_80462AC:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x8
	adds r4, r0, 0
	ldr r0, [sp, 0x28]
	lsls r1, 24
	lsrs r1, 24
	mov r10, r1
	lsls r2, 24
	lsrs r5, r2, 24
	lsls r3, 24
	lsrs r3, 24
	mov r9, r3
	lsls r0, 24
	lsrs r0, 24
	str r0, [sp]
	movs r0, 0
	str r0, [sp, 0x4]
	adds r0, r4, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	bne _080462E4
	b _08046498
_080462E4:
	cmp r5, 0
	beq _08046316
	movs r1, 0x4
	ldrsh r0, [r4, r1]
	movs r2, 0x6
	ldrsh r1, [r4, r2]
	bl GetTile
	ldrh r0, [r0]
	movs r1, 0x3
	ands r1, r0
	cmp r1, 0
	bne _08046300
	b _08046498
_08046300:
	cmp r1, 0x2
	bne _08046308
	movs r3, 0x1
	str r3, [sp, 0x4]
_08046308:
	adds r0, r4, 0
	bl sub_8045888
	lsls r0, 24
	cmp r0, 0
	bne _08046316
	b _08046498
_08046316:
	ldr r1, [r4, 0xC]
	cmp r1, 0
	bge _0804631E
	adds r1, 0xFF
_0804631E:
	asrs r1, 8
	ldr r0, _080463A4
	ldr r2, [r0]
	ldr r5, _080463A8
	adds r0, r2, r5
	movs r3, 0
	ldrsh r0, [r0, r3]
	subs r6, r1, r0
	ldr r3, [r4, 0x10]
	ldr r0, [r4, 0x1C]
	subs r1, r3, r0
	cmp r1, 0
	bge _0804633A
	adds r1, 0xFF
_0804633A:
	asrs r1, 8
	ldr r5, _080463AC
	adds r0, r2, r5
	movs r5, 0
	ldrsh r2, [r0, r5]
	subs r1, r2
	mov r8, r1
	adds r0, r3, 0
	cmp r0, 0
	bge _08046350
	adds r0, 0xFF
_08046350:
	asrs r0, 8
	subs r0, r2
	adds r7, r0, 0
	adds r7, 0x8
	lsrs r0, r7, 31
	adds r0, r7, r0
	asrs r7, r0, 1
	movs r0, 0x20
	negs r0, r0
	cmp r6, r0
	bge _08046368
	b _08046498
_08046368:
	cmp r8, r0
	bge _0804636E
	b _08046498
_0804636E:
	movs r0, 0x88
	lsls r0, 1
	cmp r6, r0
	ble _08046378
	b _08046498
_08046378:
	mov r0, r8
	cmp r0, 0xC0
	ble _08046380
	b _08046498
_08046380:
	ldr r5, _080463B0
	ldrh r1, [r5, 0x2]
	ldr r0, _080463B4
	ands r0, r1
	strh r0, [r5, 0x2]
	mov r1, r10
	cmp r1, 0
	beq _080463BC
	movs r2, 0x17
	mov r10, r2
	movs r2, 0xA0
	lsls r2, 8
	ldrh r1, [r5, 0x4]
	ldr r0, _080463B8
	ands r0, r1
	orrs r0, r2
	strh r0, [r5, 0x4]
	b _08046408
	.align 2, 0
_080463A4: .4byte gDungeon
_080463A8: .4byte 0x000181f0
_080463AC: .4byte 0x000181f2
_080463B0: .4byte gUnknown_202EDC0
_080463B4: .4byte 0x0000c1ff
_080463B8: .4byte 0x00000fff
_080463BC:
	ldr r0, [r4, 0x70]
	bl sub_8046298
	mov r10, r0
	mov r3, r9
	cmp r3, 0xFF
	beq _080463EE
	cmp r0, 0
	bne _080463EE
	ldr r0, _08046478
	add r0, r9
	ldrb r0, [r0]
	mov r10, r0
	ldr r0, _0804647C
	add r0, r9
	ldrb r1, [r0]
	lsls r1, 3
	movs r0, 0x1F
	ands r1, r0
	lsls r1, 9
	ldrh r2, [r5, 0x2]
	ldr r0, _08046480
	ands r0, r2
	orrs r0, r1
	strh r0, [r5, 0x2]
_080463EE:
	ldr r0, [r4, 0x70]
	ldrb r0, [r0, 0x2]
	bl GetItemPalette
	movs r1, 0xF
	ands r0, r1
	lsls r0, 12
	ldr r3, _08046484
	ldrh r2, [r3, 0x4]
	ldr r1, _08046488
	ands r1, r2
	orrs r1, r0
	strh r1, [r3, 0x4]
_08046408:
	ldr r1, _08046488
	mov r5, r8
	ands r1, r5
	lsls r1, 4
	ldr r4, _08046484
	ldrh r2, [r4, 0x6]
	movs r0, 0xF
	ands r0, r2
	orrs r0, r1
	strh r0, [r4, 0x6]
	ldr r0, _0804648C
	ands r6, r0
	ldrh r1, [r4, 0x2]
	movs r0, 0xFE
	lsls r0, 8
	ands r0, r1
	orrs r0, r6
	strh r0, [r4, 0x2]
	ldr r0, [sp, 0x4]
	lsls r3, r0, 10
	ldrh r2, [r4]
	ldr r1, _08046490
	adds r0, r1, 0
	ands r0, r2
	orrs r0, r3
	strh r0, [r4]
	movs r2, 0xC0
	lsls r2, 4
	ldrh r0, [r4, 0x4]
	ands r1, r0
	orrs r1, r2
	mov r2, r10
	lsls r0, r2, 2
	movs r3, 0xD0
	lsls r3, 1
	adds r0, r3
	ldr r2, _08046494
	ands r0, r2
	movs r2, 0xFC
	lsls r2, 8
	ands r1, r2
	orrs r1, r0
	strh r1, [r4, 0x4]
	ldr r5, [sp]
	cmp r5, 0
	bne _08046466
	movs r7, 0x1
_08046466:
	adds r0, r4, 0
	adds r1, r7, 0
	movs r2, 0
	movs r3, 0
	bl AddSprite
	movs r0, 0x1
	b _0804649A
	.align 2, 0
_08046478: .4byte gUnknown_203B420
_0804647C: .4byte gUnknown_203B428
_08046480: .4byte 0x0000c1ff
_08046484: .4byte gUnknown_202EDC0
_08046488: .4byte 0x00000fff
_0804648C: .4byte 0x000001ff
_08046490: .4byte 0x0000f3ff
_08046494: .4byte 0x000003ff
_08046498:
	movs r0, 0
_0804649A:
	add sp, 0x8
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_80462AC

	thumb_func_start sub_80464AC
sub_80464AC:
	push {r4,lr}
	ldr r4, _080464C4
	ldrb r0, [r0, 0x2]
	bl GetItemActionType
	lsls r0, 3
	adds r0, r4
	ldr r0, [r0]
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_080464C4: .4byte gActions
	thumb_func_end sub_80464AC

	thumb_func_start sub_80464C8
sub_80464C8:
	push {r4-r6,lr}
	sub sp, 0x78
	adds r6, r0, 0
	adds r3, r1, 0
	adds r5, r2, 0
	movs r0, 0x3
	str r0, [sp, 0x4]
	add r0, sp, 0x28
	movs r4, 0
	strb r4, [r0]
	add r1, sp, 0x24
	movs r0, 0x1
	strb r0, [r1]
	mov r0, sp
	adds r0, 0x26
	strb r4, [r0]
	str r5, [sp, 0x74]
	ldr r0, [r3]
	str r0, [sp, 0x8]
	movs r1, 0
	ldrsh r0, [r3, r1]
	lsls r1, r0, 1
	adds r1, r0
	lsls r1, 3
	adds r1, 0x4
	lsls r1, 8
	movs r2, 0x2
	ldrsh r0, [r3, r2]
	lsls r2, r0, 1
	adds r2, r0
	lsls r2, 3
	adds r2, 0x4
	lsls r2, 8
	add r0, sp, 0x4
	bl SetEntityPixelPos
	add r0, sp, 0x4
	strh r4, [r0, 0x26]
	str r4, [sp]
	adds r0, r6, 0
	add r1, sp, 0x4
	adds r2, r5, 0
	movs r3, 0x1
	bl sub_804652C
	add sp, 0x78
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end sub_80464C8

	thumb_func_start sub_804652C
sub_804652C:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x10
	mov r10, r0
	adds r5, r1, 0
	mov r9, r2
	lsls r3, 24
	lsrs r6, r3, 24
	movs r1, 0x4
	ldrsh r0, [r5, r1]
	movs r2, 0x6
	ldrsh r1, [r5, r2]
	bl GetTile
	adds r4, r0, 0
	ldr r0, [r4, 0x14]
	movs r3, 0
	str r3, [sp, 0xC]
	cmp r0, 0
	beq _0804658C
	bl GetEntityType
	cmp r0, 0x2
	bne _0804658C
	adds r4, r5, 0x4
	adds r0, r5, 0
	adds r1, r4, 0
	bl sub_8046734
	adds r0, r4, 0
	movs r1, 0x1
	bl sub_807FE44
	ldr r0, _080465A4
	ldr r1, [r0]
	mov r0, r10
	bl SendMessage
	mov r0, r9
	ldrb r1, [r0]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	bne _0804658C
	b _0804671E
_0804658C:
	ldrh r1, [r5, 0x6]
	lsls r1, 16
	ldrh r0, [r5, 0x4]
	orrs r0, r1
	str r0, [sp]
	mov r8, r0
	movs r7, 0x1
	cmp r6, 0
	beq _08046632
	movs r7, 0
	b _08046632
	.align 2, 0
_080465A4: .4byte gUnknown_80FED30
_080465A8:
	lsls r3, r7, 2
	adds r3, r0
	ldrh r0, [r3]
	ldrh r1, [r5, 0x4]
	adds r0, r1
	lsls r0, 16
	lsrs r0, 16
	ldr r1, _08046628
	ldr r2, [sp]
	ands r2, r1
	orrs r2, r0
	str r2, [sp]
	ldrh r0, [r3, 0x2]
	ldrh r3, [r5, 0x6]
	adds r0, r3
	lsls r0, 16
	ldr r1, _0804662C
	ands r1, r2
	orrs r1, r0
	str r1, [sp]
	mov r0, sp
	movs r2, 0
	ldrsh r0, [r0, r2]
	asrs r1, 16
	bl GetTile
	adds r4, r0, 0
	ldrh r1, [r4]
	movs r6, 0x3
	adds r0, r6, 0
	ands r0, r1
	cmp r0, 0
	beq _08046630
	movs r0, 0x80
	lsls r0, 2
	ands r0, r1
	cmp r0, 0
	bne _08046630
	ldr r0, [r4, 0x14]
	cmp r0, 0
	bne _08046630
	adds r0, r5, 0
	mov r1, sp
	bl sub_8046734
	ldr r3, [sp]
	mov r8, r3
	ldrh r1, [r4]
	adds r0, r6, 0
	ands r0, r1
	cmp r0, 0x3
	beq _08046620
	mov r0, sp
	mov r1, r9
	movs r2, 0x1
	bl sub_80460F8
	lsls r0, 24
	cmp r0, 0
	beq _08046644
_08046620:
	movs r0, 0x1
	str r0, [sp, 0xC]
	b _08046644
	.align 2, 0
_08046628: .4byte 0xffff0000
_0804662C: .4byte 0x0000ffff
_08046630:
	adds r7, 0x1
_08046632:
	ldr r0, _08046688
	lsls r1, r7, 2
	adds r1, r0
	movs r2, 0
	ldrsh r1, [r1, r2]
	cmp r1, 0x63
	bne _080465A8
	movs r3, 0
	str r3, [sp, 0xC]
_08046644:
	ldr r0, _0804668C
	mov r1, r9
	bl sub_8045BF8
	ldr r0, [sp, 0xC]
	cmp r0, 0
	beq _080466C8
	mov r0, sp
	movs r1, 0
	ldrsh r0, [r0, r1]
	mov r4, sp
	movs r2, 0x2
	ldrsh r1, [r4, r2]
	bl sub_80402AC
	mov r0, sp
	movs r3, 0
	ldrsh r0, [r0, r3]
	movs r2, 0x2
	ldrsh r1, [r4, r2]
	bl GetTile
	ldrh r0, [r0]
	movs r1, 0x3
	ands r1, r0
	adds r0, r1, 0
	cmp r1, 0x1
	beq _0804669A
	cmp r1, 0x1
	bgt _08046690
	cmp r1, 0
	beq _080466AC
	b _0804671E
	.align 2, 0
_08046688: .4byte gUnknown_80F4468
_0804668C: .4byte gFormatItems
_08046690:
	cmp r0, 0x2
	beq _080466A4
	cmp r0, 0x3
	beq _080466B4
	b _0804671E
_0804669A:
	ldr r0, _080466A0
	b _080466B6
	.align 2, 0
_080466A0: .4byte gItemFellOnGround
_080466A4:
	ldr r0, _080466A8
	b _080466B6
	.align 2, 0
_080466A8: .4byte gItemFellInWater
_080466AC:
	ldr r0, _080466B0
	b _080466B6
	.align 2, 0
_080466B0: .4byte gItemBuried
_080466B4:
	ldr r0, _080466C4
_080466B6:
	ldr r2, [r0]
	mov r0, r10
	mov r1, sp
	bl sub_8052364
	b _0804671E
	.align 2, 0
_080466C4: .4byte gItemFellOutOfSight
_080466C8:
	mov r3, r8
	lsls r1, r3, 16
	asrs r1, 16
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 11
	movs r1, 0xC0
	lsls r1, 4
	adds r0, r1
	str r0, [sp, 0x4]
	asrs r1, r3, 16
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 11
	movs r2, 0xC0
	lsls r2, 4
	adds r0, r2
	add r2, sp, 0x4
	str r0, [r2, 0x4]
	ldr r3, [sp, 0x30]
	cmp r3, 0
	beq _0804670C
	movs r1, 0
	ldrsh r0, [r3, r1]
	lsls r0, 8
	ldr r1, [sp, 0x4]
	adds r0, r1
	str r0, [sp, 0x4]
	movs r1, 0x2
	ldrsh r0, [r3, r1]
	lsls r0, 8
	ldr r1, [r2, 0x4]
	adds r0, r1
	str r0, [r2, 0x4]
_0804670C:
	adds r0, r2, 0
	bl sub_804219C
	ldr r0, _08046730
	ldr r2, [r0]
	mov r0, r10
	mov r1, sp
	bl sub_8052364
_0804671E:
	add sp, 0x10
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_08046730: .4byte gItemLost
	thumb_func_end sub_804652C

	thumb_func_start sub_8046734
sub_8046734:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x18
	mov r8, r0
	ldr r0, _08046858
	ldr r0, [r0]
	ldr r2, _0804685C
	adds r0, r2
	ldrb r0, [r0]
	str r0, [sp, 0xC]
	movs r0, 0
	ldrsh r2, [r1, r0]
	lsls r0, r2, 1
	adds r0, r2
	lsls r0, 3
	adds r0, 0x4
	lsls r4, r0, 8
	movs r2, 0x2
	ldrsh r1, [r1, r2]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 3
	adds r0, 0x4
	lsls r5, r0, 8
	mov r1, r8
	ldr r0, [r1, 0xC]
	subs r0, r4
	cmp r0, 0
	bge _08046776
	negs r0, r0
_08046776:
	mov r2, r8
	ldr r2, [r2, 0x10]
	mov r9, r2
	cmp r0, 0xB
	bgt _0804678C
	subs r0, r2, r5
	cmp r0, 0
	bge _08046788
	negs r0, r0
_08046788:
	cmp r0, 0xB
	ble _08046822
_0804678C:
	movs r0, 0
	mov r10, r0
	movs r1, 0
	str r1, [sp, 0x10]
	mov r2, r8
	ldr r0, [r2, 0xC]
	str r0, [sp, 0x4]
	mov r1, r9
	str r1, [sp, 0x8]
	subs r0, r4, r0
	movs r1, 0x18
	bl __divsi3
	adds r6, r0, 0
	mov r2, r9
	subs r0, r5, r2
	movs r1, 0x18
	bl __divsi3
	adds r7, r0, 0
	movs r0, 0
	mov r9, r0
	mov r1, sp
	adds r1, 0x4
	str r1, [sp, 0x14]
_080467BE:
	ldr r0, [sp, 0x4]
	adds r0, r6
	str r0, [sp, 0x4]
	ldr r2, [sp, 0x14]
	ldr r0, [r2, 0x4]
	adds r0, r7
	str r0, [r2, 0x4]
	ldr r0, [sp, 0x10]
	bl sin_abs_4096
	lsls r1, r0, 1
	adds r1, r0
	lsls r1, 2
	mov r0, r8
	str r1, [r0, 0x1C]
	add r1, sp, 0x4
	bl sub_804535C
	mov r1, r10
	lsls r3, r1, 24
	lsrs r3, 24
	movs r0, 0
	str r0, [sp]
	mov r0, r8
	ldr r1, [sp, 0xC]
	movs r2, 0
	bl sub_80462AC
	movs r0, 0x13
	bl sub_803E46C
	ldr r2, [sp, 0x10]
	adds r2, 0x55
	str r2, [sp, 0x10]
	movs r0, 0x3
	mov r1, r9
	ands r0, r1
	cmp r0, 0
	bne _08046810
	movs r2, 0x1
	add r10, r2
_08046810:
	movs r0, 0x7
	mov r1, r10
	ands r1, r0
	mov r10, r1
	movs r2, 0x1
	add r9, r2
	mov r0, r9
	cmp r0, 0x17
	ble _080467BE
_08046822:
	mov r0, r8
	adds r1, r4, 0
	adds r2, r5, 0
	bl SetEntityPixelPos
	movs r0, 0
	mov r1, r8
	str r0, [r1, 0x1C]
	str r0, [sp]
	mov r0, r8
	ldr r1, [sp, 0xC]
	movs r2, 0x1
	movs r3, 0xFF
	bl sub_80462AC
	movs r0, 0x13
	bl sub_803E46C
	add sp, 0x18
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_08046858: .4byte gDungeon
_0804685C: .4byte 0x00018210
	thumb_func_end sub_8046734

	thumb_func_start sub_8046860
sub_8046860:
	push {r4,r5,lr}
	sub sp, 0x4
	adds r4, r1, 0
	adds r5, r2, 0
	str r3, [sp]
	adds r2, r4, 0
	adds r3, r5, 0
	bl sub_804687C
	add sp, 0x4
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_8046860

	thumb_func_start sub_804687C
sub_804687C:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	ldr r4, _08046970
	add sp, r4
	ldr r5, _08046974
	add r5, sp
	str r0, [r5]
	movs r0, 0xA5
	lsls r0, 3
	add r0, sp
	str r1, [r0]
	mov r8, r2
	ldr r1, _08046978
	add r1, sp
	str r3, [r1]
	movs r1, 0
	movs r7, 0x1D
	ldr r0, _0804697C
	add r0, sp
_080468A8:
	strb r1, [r0]
	subs r0, 0x1
	subs r7, 0x1
	cmp r7, 0
	bge _080468A8
	movs r7, 0
	movs r2, 0xAD
	lsls r2, 3
	add r2, sp
	ldr r2, [r2]
	cmp r7, r2
	blt _080468C2
	b _080469DE
_080468C2:
	ldr r3, _08046980
	mov r9, r3
	ldr r5, _08046984
	movs r0, 0
	ldrsh r5, [r5, r0]
	ldr r0, _08046988
	add r0, sp
	str r5, [r0]
_080468D2:
	mov r1, r8
	ldrh r0, [r1]
	ldr r1, _0804698C
	ands r4, r1
	orrs r4, r0
	mov r2, r8
	ldrh r0, [r2, 0x2]
	lsls r0, 16
	mov r3, r9
	ands r4, r3
	orrs r4, r0
	movs r5, 0
	adds r0, r7, 0x1
	mov r10, r0
	ldr r1, _08046984
	ldr r2, _08046988
	add r2, sp
	ldr r2, [r2]
	cmp r2, 0x63
	beq _080469B0
	ldr r3, _08046990
	add r3, sp
	ldr r0, _08046994
	add r0, sp
	str r3, [r0]
_08046904:
	ldr r0, _08046998
	add r0, sp
	adds r6, r0, r5
	ldrb r0, [r6]
	cmp r0, 0
	bne _0804699C
	lsls r2, r5, 2
	adds r2, r1
	ldrh r0, [r2]
	mov r1, r8
	ldrh r1, [r1]
	adds r0, r1
	lsls r0, 16
	lsrs r0, 16
	ldr r1, _0804698C
	ands r4, r1
	orrs r4, r0
	ldrh r0, [r2, 0x2]
	mov r2, r8
	ldrh r2, [r2, 0x2]
	adds r0, r2
	lsls r0, 16
	mov r3, r9
	ands r4, r3
	orrs r4, r0
	lsls r0, r4, 16
	asrs r0, 16
	asrs r1, r4, 16
	bl GetTile
	adds r2, r0, 0
	ldrh r1, [r2]
	movs r0, 0x3
	ands r0, r1
	cmp r0, 0
	beq _0804699C
	movs r3, 0x80
	lsls r3, 2
	adds r0, r3, 0
	ands r0, r1
	cmp r0, 0
	bne _0804699C
	ldr r0, [r2, 0x14]
	cmp r0, 0
	bne _0804699C
	lsls r0, r7, 2
	ldr r5, _08046994
	add r5, sp
	ldr r5, [r5]
	adds r0, r5, r0
	str r4, [r0]
	movs r0, 0x1
	strb r0, [r6]
	b _080469CE
	.align 2, 0
_08046970: .4byte 0xfffffab8
_08046974: .4byte 0x00000524
_08046978: .4byte 0x0000052c
_0804697C: .4byte 0x00000521
_08046980: .4byte 0x0000ffff
_08046984: .4byte gUnknown_80F4468
_08046988: .4byte 0x00000534
_0804698C: .4byte 0xffff0000
_08046990: .4byte 0x0000048c
_08046994: .4byte 0x00000544
_08046998: .4byte 0x00000504
_0804699C:
	adds r5, 0x1
	cmp r5, 0x1D
	bgt _080469B0
	lsls r0, r5, 2
	ldr r1, _08046A18
	adds r0, r1
	movs r2, 0
	ldrsh r0, [r0, r2]
	cmp r0, 0x63
	bne _08046904
_080469B0:
	movs r3, 0
	cmp r3, 0
	bne _080469CE
	ldr r1, _08046A1C
	add r1, sp
	lsls r0, r7, 2
	adds r1, r0
	ldrh r2, [r1]
	mov r0, r9
	orrs r0, r2
	strh r0, [r1]
	ldrh r2, [r1, 0x2]
	mov r0, r9
	orrs r0, r2
	strh r0, [r1, 0x2]
_080469CE:
	mov r7, r10
	movs r5, 0xAD
	lsls r5, 3
	add r5, sp
	ldr r5, [r5]
	cmp r7, r5
	bge _080469DE
	b _080468D2
_080469DE:
	movs r1, 0
	mov r9, r1
	movs r7, 0
	movs r0, 0xAD
	lsls r0, 3
	add r0, sp
	ldr r0, [r0]
	cmp r7, r0
	blt _080469F2
	b _08046B0A
_080469F2:
	movs r2, 0
	mov r8, r2
_080469F6:
	ldr r0, _08046A1C
	add r0, sp
	lsls r2, r7, 2
	adds r3, r0, r2
	movs r4, 0
	ldrsh r0, [r3, r4]
	cmp r0, 0
	bge _08046A20
	movs r0, 0x74
	muls r0, r7
	add r0, sp
	adds r0, 0x4
	mov r5, r8
	str r5, [r0]
	movs r0, 0x1
	mov r9, r0
	b _08046AFA
	.align 2, 0
_08046A18: .4byte gUnknown_80F4468
_08046A1C: .4byte 0x0000048c
_08046A20:
	movs r0, 0x74
	adds r6, r7, 0
	muls r6, r0
	mov r4, sp
	adds r4, r6
	adds r4, 0x4
	movs r0, 0x3
	str r0, [r4]
	adds r0, r4, 0
	adds r0, 0x24
	mov r1, r8
	strb r1, [r0]
	adds r1, r4, 0
	adds r1, 0x20
	movs r0, 0x1
	strb r0, [r1]
	adds r0, r4, 0
	adds r0, 0x22
	mov r5, r8
	strb r5, [r0]
	add r0, sp, 0x74
	adds r0, r6
	ldr r1, _08046B2C
	add r1, sp
	ldr r1, [r1]
	adds r2, r1, r2
	str r2, [r0]
	add r0, sp, 0x8
	adds r0, r6
	ldr r1, [r3]
	str r1, [r0]
	movs r2, 0xA5
	lsls r2, 3
	add r2, sp
	ldr r2, [r2]
	movs r5, 0
	ldrsh r0, [r2, r5]
	lsls r1, r0, 1
	adds r1, r0
	lsls r1, 3
	adds r1, 0x4
	lsls r1, 8
	movs r5, 0x2
	ldrsh r0, [r2, r5]
	lsls r2, r0, 1
	adds r2, r0
	lsls r2, 3
	adds r2, 0x4
	lsls r2, 8
	adds r0, r4, 0
	movs r5, 0xA8
	lsls r5, 3
	add r5, sp
	str r3, [r5]
	bl SetEntityPixelPos
	mov r0, r8
	strh r0, [r4, 0x26]
	ldr r4, _08046B30
	add r4, sp
	lsls r5, r7, 3
	adds r4, r5
	movs r1, 0xA8
	lsls r1, 3
	add r1, sp
	ldr r3, [r1]
	movs r2, 0
	ldrsh r1, [r3, r2]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 3
	adds r0, 0x4
	lsls r0, 8
	add r1, sp, 0x10
	adds r1, r6
	ldr r1, [r1]
	subs r0, r1
	movs r1, 0x18
	movs r2, 0xA8
	lsls r2, 3
	add r2, sp
	str r3, [r2]
	bl __divsi3
	str r0, [r4]
	movs r4, 0x97
	lsls r4, 3
	add r4, sp
	adds r4, r5
	movs r5, 0xA8
	lsls r5, 3
	add r5, sp
	ldr r3, [r5]
	movs r0, 0x2
	ldrsh r1, [r3, r0]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 3
	adds r0, 0x4
	lsls r0, 8
	add r1, sp, 0x14
	adds r1, r6
	ldr r1, [r1]
	subs r0, r1
	movs r1, 0x18
	bl __divsi3
	str r0, [r4]
	movs r1, 0x1
_08046AFA:
	adds r7, 0x1
	movs r2, 0xAD
	lsls r2, 3
	add r2, sp
	ldr r2, [r2]
	cmp r7, r2
	bge _08046B0A
	b _080469F6
_08046B0A:
	cmp r1, 0
	bne _08046B54
	movs r3, 0xAD
	lsls r3, 3
	add r3, sp
	ldr r3, [r3]
	cmp r3, 0x1
	ble _08046B3C
	ldr r0, _08046B34
	ldr r1, [r0]
	ldr r4, _08046B38
	add r4, sp
	ldr r0, [r4]
	bl SendMessage
	b _08046C7C
	.align 2, 0
_08046B2C: .4byte 0x0000052c
_08046B30: .4byte 0x000004b4
_08046B34: .4byte gAllItemsLost
_08046B38: .4byte 0x00000524
_08046B3C:
	ldr r0, _08046B4C
	ldr r1, [r0]
	ldr r5, _08046B50
	add r5, sp
	ldr r0, [r5]
	bl SendMessage
	b _08046C7C
	.align 2, 0
_08046B4C: .4byte gItemLost
_08046B50: .4byte 0x00000524
_08046B54:
	mov r0, r9
	cmp r0, 0
	beq _08046B68
	ldr r0, _08046C90
	ldr r1, [r0]
	ldr r2, _08046C94
	add r2, sp
	ldr r0, [r2]
	bl SendMessage
_08046B68:
	movs r3, 0
	mov r9, r3
	ldr r0, _08046C98
	ldr r0, [r0]
	ldr r4, _08046C9C
	adds r0, r4
	ldrb r0, [r0]
	movs r5, 0xA6
	lsls r5, 3
	add r5, sp
	str r0, [r5]
	mov r10, r3
	movs r6, 0
_08046B82:
	movs r7, 0
	mov r0, r10
	adds r0, 0x55
	movs r1, 0xA7
	lsls r1, 3
	add r1, sp
	str r0, [r1]
	adds r2, r6, 0x1
	ldr r3, _08046CA0
	add r3, sp
	str r2, [r3]
	movs r4, 0xAD
	lsls r4, 3
	add r4, sp
	ldr r4, [r4]
	cmp r7, r4
	bge _08046C14
	mov r5, r9
	lsls r5, 24
	mov r8, r5
_08046BAA:
	movs r0, 0x74
	adds r5, r7, 0
	muls r5, r0
	mov r4, sp
	adds r4, r5
	adds r4, 0x4
	adds r0, r4, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	beq _08046C06
	ldr r0, _08046CA4
	add r0, sp
	lsls r2, r7, 3
	adds r0, r2
	ldr r1, [r0]
	movs r0, 0x97
	lsls r0, 3
	add r0, sp
	adds r0, r2
	ldr r2, [r0]
	adds r0, r4, 0
	bl IncreaseEntityPixelPos
	mov r0, r10
	bl sin_abs_4096
	add r2, sp, 0x20
	adds r2, r5
	lsls r1, r0, 1
	adds r1, r0
	lsls r1, 2
	str r1, [r2]
	movs r0, 0
	str r0, [sp]
	adds r0, r4, 0
	movs r2, 0xA6
	lsls r2, 3
	add r2, sp
	ldr r1, [r2]
	movs r2, 0x1
	mov r4, r8
	lsrs r3, r4, 24
	bl sub_80462AC
_08046C06:
	adds r7, 0x1
	movs r5, 0xAD
	lsls r5, 3
	add r5, sp
	ldr r5, [r5]
	cmp r7, r5
	blt _08046BAA
_08046C14:
	movs r0, 0x13
	bl sub_803E46C
	movs r0, 0xA7
	lsls r0, 3
	add r0, sp
	ldr r0, [r0]
	mov r10, r0
	movs r0, 0x3
	ands r0, r6
	cmp r0, 0
	bne _08046C30
	movs r1, 0x1
	add r9, r1
_08046C30:
	movs r0, 0x7
	mov r2, r9
	ands r2, r0
	mov r9, r2
	ldr r3, _08046CA0
	add r3, sp
	ldr r6, [r3]
	cmp r6, 0x17
	ble _08046B82
	movs r4, 0xAD
	lsls r4, 3
	add r4, sp
	ldr r4, [r4]
	cmp r4, 0
	ble _08046C7C
	ldr r0, _08046CA8
	add r0, sp
	ldr r5, [r0]
	ldr r4, _08046CAC
	add r4, sp
	movs r1, 0xAD
	lsls r1, 3
	add r1, sp
	ldr r7, [r1]
_08046C60:
	movs r2, 0
	ldrsh r0, [r4, r2]
	cmp r0, 0
	blt _08046C72
	adds r0, r4, 0
	adds r1, r5, 0
	movs r2, 0x1
	bl sub_80460F8
_08046C72:
	adds r5, 0x4
	adds r4, 0x4
	subs r7, 0x1
	cmp r7, 0
	bne _08046C60
_08046C7C:
	movs r3, 0xA9
	lsls r3, 3
	add sp, r3
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_08046C90: .4byte gSeveralItemsLost
_08046C94: .4byte 0x00000524
_08046C98: .4byte gDungeon
_08046C9C: .4byte 0x00018210
_08046CA0: .4byte 0x0000053c
_08046CA4: .4byte 0x000004b4
_08046CA8: .4byte 0x0000052c
_08046CAC: .4byte 0x0000048c
	thumb_func_end sub_804687C

	.align 2, 0
