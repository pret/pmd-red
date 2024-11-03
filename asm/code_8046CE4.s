	#include "asm/constants/gba_constants.inc"
  	#include "asm/macros.inc"

  	.syntax unified

  	.text

	thumb_func_start sub_8047158
sub_8047158:
	push {r4-r6,lr}
	movs r3, 0
	ldr r5, _0804718C
	movs r6, 0x1
	movs r4, 0x4
_08047162:
	lsls r1, r3, 2
	ldr r0, [r5]
	adds r2, r0, r1
	ldrb r1, [r2]
	adds r0, r6, 0
	ands r0, r1
	cmp r0, 0
	beq _08047180
	adds r0, r4, 0
	ands r0, r1
	cmp r0, 0
	beq _08047180
	movs r0, 0xFB
	ands r0, r1
	strb r0, [r2]
_08047180:
	adds r3, 0x1
	cmp r3, 0x13
	ble _08047162
	pop {r4-r6}
	pop {r0}
	bx r0
	.align 2, 0
_0804718C: .4byte gTeamInventoryRef
	thumb_func_end sub_8047158

	thumb_func_start sub_8047190
sub_8047190:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	ldr r4, _080472E8
	add sp, r4
	mov r9, r0
	str r1, [sp, 0x214]
	ldr r6, _080472EC
	ldr r1, [r6]
	ldr r4, _080472F0
	adds r0, r1, r4
	ldrb r0, [r0]
	str r0, [sp, 0x220]
	mov r8, r3
	adds r7, r1, 0
	adds r7, 0xC0
	movs r0, 0x3
	str r0, [r7]
	adds r0, r1, 0
	adds r0, 0xE4
	movs r4, 0
	strb r4, [r0]
	subs r0, 0x4
	movs r5, 0x1
	strb r5, [r0]
	adds r0, 0x2
	strb r4, [r0]
	ldr r0, [sp, 0x214]
	str r0, [r7, 0x70]
	str r4, [r7, 0x1C]
	ldr r0, [r2]
	str r0, [r7, 0x4]
	movs r1, 0
	ldrsh r0, [r2, r1]
	lsls r1, r0, 1
	adds r1, r0
	lsls r1, 3
	adds r1, 0x4
	lsls r1, 8
	movs r3, 0x2
	ldrsh r0, [r2, r3]
	lsls r2, r0, 1
	adds r2, r0
	lsls r2, 11
	adds r0, r7, 0
	bl SetEntityPixelPos
	strh r4, [r7, 0x26]
	str r4, [sp, 0x224]
	mov r0, r9
	bl GetEntityType
	cmp r0, 0x1
	bne _08047214
	mov r0, r9
	movs r1, 0x2A
	bl HasHeldItem
	lsls r0, 24
	lsrs r0, 24
	negs r1, r0
	orrs r1, r0
	lsrs r1, 31
	str r1, [sp, 0x224]
_08047214:
	ldr r0, [sp, 0x260]
	movs r1, 0x2
	ldrsh r0, [r0, r1]
	str r0, [sp, 0x218]
	movs r2, 0
	str r2, [sp, 0x21C]
	ldr r0, [r6]
	ldr r3, _080472F4
	adds r0, r3
	strb r5, [r0]
_08047228:
	ldr r4, [r7, 0x4]
	mov r10, r4
	ldr r1, [sp, 0x260]
	ldrb r0, [r1, 0x1]
	cmp r0, 0
	beq _080472AE
	ldrb r0, [r1]
	cmp r0, 0
	bne _080472AE
	movs r2, 0x4
	ldrsh r0, [r7, r2]
	ldr r2, _080472F8
	mov r3, r8
	lsls r4, r3, 2
	adds r2, r4, r2
	movs r3, 0
	ldrsh r1, [r2, r3]
	adds r0, r1
	movs r3, 0x6
	ldrsh r1, [r7, r3]
	movs r3, 0x2
	ldrsh r2, [r2, r3]
	adds r1, r2
	bl GetTile
	adds r5, r0, 0
	ldrh r1, [r5]
	movs r0, 0x3
	ands r0, r1
	str r4, [sp, 0x230]
	cmp r0, 0
	bne _080472AE
	movs r6, 0
	ldr r1, _080472FC
	mov r4, r10
	lsls r0, r4, 16
	asrs r0, 16
	str r0, [sp, 0x23C]
	ldr r0, [sp, 0x230]
	adds r5, r0, r1
	asrs r2, r4, 16
_0804727A:
	ldrb r4, [r5]
	cmp r4, 0x7
	bgt _080472A6
	ldr r0, _080472F8
	lsls r1, r4, 2
	adds r1, r0
	movs r3, 0
	ldrsh r0, [r1, r3]
	ldr r3, [sp, 0x23C]
	adds r0, r3
	movs r3, 0x2
	ldrsh r1, [r1, r3]
	adds r1, r2
	str r2, [sp, 0x234]
	bl GetTile
	ldrh r1, [r0]
	movs r0, 0x3
	ands r0, r1
	ldr r2, [sp, 0x234]
	cmp r0, 0
	bne _08047300
_080472A6:
	adds r5, 0x1
	adds r6, 0x1
	cmp r6, 0x3
	ble _0804727A
_080472AE:
	ldr r0, _080472F8
	mov r4, r8
	lsls r2, r4, 2
	adds r3, r2, r0
	ldrh r1, [r3]
	ldrh r0, [r7, 0x4]
	adds r1, r0
	strh r1, [r7, 0x4]
	ldrh r0, [r3, 0x2]
	ldrh r4, [r7, 0x6]
	adds r0, r4
	strh r0, [r7, 0x6]
	lsls r1, 16
	asrs r1, 16
	str r2, [sp, 0x230]
	cmp r1, 0
	blt _080472E0
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0
	blt _080472E0
	cmp r1, 0x37
	bgt _080472E0
	cmp r0, 0x1F
	ble _08047304
_080472E0:
	movs r0, 0x2
	mov r10, r0
	b _0804744C
	.align 2, 0
_080472E8: .4byte 0xfffffdc0
_080472EC: .4byte gDungeon
_080472F0: .4byte 0x00018210
_080472F4: .4byte 0x0001c05e
_080472F8: .4byte gAdjacentTileOffsets
_080472FC: .4byte gUnknown_80F4D64
_08047300:
	mov r8, r4
	b _080472AE
_08047304:
	movs r1, 0
	ldrsh r0, [r3, r1]
	lsls r0, 10
	str r0, [sp, 0x228]
	movs r2, 0x2
	ldrsh r0, [r3, r2]
	lsls r0, 10
	str r0, [sp, 0x22C]
	mov r3, r8
	lsls r6, r3, 24
	movs r5, 0x5
_0804731A:
	movs r4, 0
	adds r0, r7, 0
	ldr r1, [sp, 0x228]
	ldr r2, [sp, 0x22C]
	bl IncreaseEntityPixelPos
	bl IsWaterTileset
	lsls r0, 24
	movs r2, 0
	cmp r0, 0
	beq _08047334
	movs r2, 0x3
_08047334:
	ldr r0, [r7, 0xC]
	cmp r0, 0
	bge _0804733C
	adds r0, 0xFF
_0804733C:
	asrs r0, 8
	adds r0, 0x8
	ldr r1, [r7, 0x10]
	cmp r1, 0
	bge _08047348
	adds r1, 0xFF
_08047348:
	asrs r1, 8
	adds r1, 0x10
	bl sub_8083568
	lsls r0, 24
	cmp r0, 0
	beq _08047358
	movs r4, 0x1
_08047358:
	movs r0, 0x1
	str r0, [sp]
	adds r0, r7, 0
	ldr r1, [sp, 0x220]
	movs r2, 0
	lsrs r3, r6, 24
	bl sub_80462AC
	lsls r0, 24
	cmp r0, 0
	beq _08047370
	movs r4, 0x1
_08047370:
	cmp r4, 0
	beq _0804737A
	movs r0, 0x12
	bl sub_803E46C
_0804737A:
	subs r5, 0x1
	cmp r5, 0
	bge _0804731A
	movs r4, 0x4
	ldrsh r0, [r7, r4]
	movs r2, 0x6
	ldrsh r1, [r7, r2]
	bl GetTile
	adds r5, r0, 0
	ldrh r1, [r5]
	movs r0, 0x3
	ands r0, r1
	cmp r0, 0
	bne _080473A2
	ldr r3, [sp, 0x260]
	ldrb r0, [r3]
	cmp r0, 0
	bne _080473A2
	b _0804757A
_080473A2:
	ldr r1, [r5, 0x10]
	cmp r1, 0
	beq _08047436
	movs r4, 0
	ldr r2, [sp, 0x260]
	ldrb r0, [r2]
	cmp r0, 0
	bne _080473CE
	adds r0, r1, 0
	bl GetEntityType
	cmp r0, 0x1
	bne _080473CE
	ldr r0, [r5, 0x10]
	movs r1, 0x26
	bl HasHeldItem
	lsls r0, 24
	lsrs r0, 24
	negs r1, r0
	orrs r1, r0
	lsrs r4, r1, 31
_080473CE:
	cmp r4, 0
	beq _080473E0
	movs r3, 0x4
	add r8, r3
	movs r0, 0x7
	mov r4, r8
	ands r4, r0
	mov r8, r4
	b _08047436
_080473E0:
	movs r6, 0x1
	ldr r0, [r5, 0x10]
	bl GetEntityType
	cmp r0, 0x1
	bne _08047406
	add r4, sp, 0x208
	adds r0, r4, 0
	ldr r1, _080474B8
	bl InitPokemonMove
	ldr r0, [r5, 0x10]
	adds r1, r4, 0
	bl sub_80571F0
	lsls r0, 24
	cmp r0, 0
	beq _08047406
	movs r6, 0
_08047406:
	cmp r6, 0
	beq _08047436
	ldr r0, [sp, 0x21C]
	cmp r0, 0x3F
	bgt _0804742C
	lsls r0, 3
	mov r4, sp
	adds r4, r0
	adds r4, 0x8
	ldr r0, [r5, 0x10]
	str r0, [r4]
	ldr r1, [r5, 0x10]
	mov r0, r9
	bl sub_8047930
	strb r0, [r4, 0x4]
	ldr r1, [sp, 0x21C]
	adds r1, 0x1
	str r1, [sp, 0x21C]
_0804742C:
	ldr r2, [sp, 0x260]
	ldrb r0, [r2]
	cmp r0, 0
	bne _08047436
	b _08047574
_08047436:
	ldr r3, [sp, 0x218]
	subs r3, 0x1
	str r3, [sp, 0x218]
	cmp r3, 0
	ble _08047442
	b _08047228
_08047442:
	movs r4, 0x1
	mov r10, r4
	mov r0, r8
	lsls r0, 2
	str r0, [sp, 0x230]
_0804744C:
	ldr r0, _080474BC
	ldr r0, [r0]
	ldr r1, _080474C0
	adds r0, r1
	movs r1, 0
	strb r1, [r0]
	ldr r2, [sp, 0x21C]
	cmp r2, 0
	ble _0804752C
	add r5, sp, 0x8
	adds r6, r2, 0
_08047462:
	ldr r4, [r5]
	ldrb r0, [r5, 0x4]
	cmp r0, 0
	beq _080474D0
	ldr r0, _080474C4
	adds r1, r4, 0
	movs r2, 0
	bl SubstitutePlaceholderStringTags
	ldr r0, _080474C8
	ldr r1, [sp, 0x214]
	bl sub_8045C08
	ldr r0, _080474CC
	ldr r2, [r0]
	mov r0, r9
	adds r1, r4, 0
	bl TryDisplayDungeonLoggableMessage3
	mov r0, r9
	adds r1, r4, 0
	bl TrySendImmobilizeSleepEndMsg
	lsls r0, 24
	lsrs r2, r0, 24
	movs r1, 0
	ldr r3, [sp, 0x224]
	cmp r3, 0
	bne _080474A4
	ldr r3, [sp, 0x260]
	ldrb r0, [r3]
	cmp r0, 0
	beq _080474A6
_080474A4:
	movs r1, 0x1
_080474A6:
	str r4, [sp]
	ldr r4, [sp, 0x214]
	str r4, [sp, 0x4]
	movs r0, 0x1
	mov r3, r9
	bl sub_80479B8
	b _08047524
	.align 2, 0
_080474B8: .4byte 0x00000195
_080474BC: .4byte gDungeon
_080474C0: .4byte 0x0001c05e
_080474C4: .4byte gFormatBuffer_Monsters
_080474C8: .4byte gFormatBuffer_Items
_080474CC: .4byte gUnknown_80F94C4
_080474D0:
	ldr r1, [sp, 0x260]
	ldrb r0, [r1]
	cmp r0, 0
	bne _080474E2
	ldr r2, [sp, 0x21C]
	cmp r2, 0x1
	bne _080474E2
	movs r3, 0x1
	mov r10, r3
_080474E2:
	ldr r0, _0804750C
	adds r1, r4, 0
	movs r2, 0
	bl SubstitutePlaceholderStringTags
	ldr r0, _08047510
	ldr r1, [sp, 0x214]
	bl sub_8045BF8
	ldr r1, [sp, 0x260]
	ldrb r0, [r1]
	cmp r0, 0
	beq _08047518
	ldr r0, _08047514
	ldr r2, [r0]
	mov r0, r9
	adds r1, r4, 0
	bl TryDisplayDungeonLoggableMessage3
	b _08047524
	.align 2, 0
_0804750C: .4byte gFormatBuffer_Monsters
_08047510: .4byte gFormatBuffer_Items
_08047514: .4byte gUnknown_80F94D8
_08047518:
	ldr r0, _08047564
	ldr r2, [r0]
	mov r0, r9
	adds r1, r4, 0
	bl TryDisplayDungeonLoggableMessage3
_08047524:
	adds r5, 0x8
	subs r6, 0x1
	cmp r6, 0
	bne _08047462
_0804752C:
	ldr r2, _08047568
	ldr r3, [sp, 0x230]
	adds r2, r3, r2
	movs r4, 0
	ldrsh r1, [r2, r4]
	lsls r1, 19
	lsrs r1, 16
	ldr r4, _0804756C
	add r3, sp, 0x210
	ldr r0, [r3]
	ands r0, r4
	orrs r0, r1
	str r0, [r3]
	movs r4, 0x2
	ldrsh r1, [r2, r4]
	lsls r1, 19
	ldr r2, _08047570
	ands r0, r2
	orrs r0, r1
	str r0, [r3]
	mov r0, r10
	cmp r0, 0x1
	beq _08047584
	cmp r0, 0x1
	bcc _080475A8
	cmp r0, 0x2
	beq _08047596
	b _080475A8
	.align 2, 0
_08047564: .4byte gUnknown_80F94F0
_08047568: .4byte gAdjacentTileOffsets
_0804756C: .4byte 0xffff0000
_08047570: .4byte 0x0000ffff
_08047574:
	movs r1, 0
	mov r10, r1
	b _0804744C
_0804757A:
	mov r2, r10
	str r2, [r7, 0x4]
	movs r3, 0x1
	mov r10, r3
	b _0804744C
_08047584:
	add r0, sp, 0x210
	str r0, [sp]
	mov r0, r9
	adds r1, r7, 0
	ldr r2, [sp, 0x214]
	movs r3, 0x1
	bl sub_804652C
	b _080475A8
_08047596:
	ldr r0, _080475BC
	ldr r1, [sp, 0x214]
	bl sub_8045C08
	ldr r0, _080475C0
	ldr r1, [r0]
	mov r0, r9
	bl LogMessageByIdWithPopupCheckUser
_080475A8:
	movs r3, 0x90
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
_080475BC: .4byte gFormatBuffer_Items
_080475C0: .4byte gUnknown_80F9530
	thumb_func_end sub_8047190

	thumb_func_start sub_80475C4
sub_80475C4:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x44
	str r0, [sp, 0x10]
	str r1, [sp, 0x14]
	adds r7, r2, 0
	str r3, [sp, 0x18]
	ldr r0, _08047848
	mov r8, r0
	ldr r2, [r0]
	ldr r1, _0804784C
	adds r0, r2, r1
	ldrb r0, [r0]
	str r0, [sp, 0x24]
	movs r4, 0
	movs r5, 0
	adds r3, r2, 0
	adds r3, 0xC0
	str r3, [sp, 0x1C]
	movs r0, 0x3
	str r0, [r3]
	adds r0, r2, 0
	adds r0, 0xE4
	strb r4, [r0]
	adds r1, r2, 0
	adds r1, 0xE0
	movs r0, 0x1
	strb r0, [r1]
	adds r0, r2, 0
	adds r0, 0xE2
	strb r4, [r0]
	ldr r0, [sp, 0x14]
	str r0, [r3, 0x70]
	str r5, [r3, 0x1C]
	ldr r0, [r7]
	str r0, [r3, 0x4]
	movs r1, 0
	ldrsh r0, [r7, r1]
	lsls r1, r0, 1
	adds r1, r0
	lsls r1, 3
	adds r1, 0x4
	lsls r1, 8
	movs r2, 0x2
	ldrsh r0, [r7, r2]
	lsls r2, r0, 1
	adds r2, r0
	lsls r2, 3
	adds r2, 0x4
	lsls r2, 8
	ldr r0, [sp, 0x1C]
	bl SetEntityPixelPos
	ldr r3, [sp, 0x1C]
	strh r4, [r3, 0x26]
	movs r0, 0x1
	str r0, [sp, 0x20]
	movs r1, 0
	str r1, [sp, 0x28]
	ldr r0, [sp, 0x10]
	bl GetEntityType
	cmp r0, 0x1
	bne _0804765E
	ldr r0, [sp, 0x10]
	movs r1, 0x2A
	bl HasHeldItem
	lsls r0, 24
	lsrs r0, 24
	negs r1, r0
	orrs r1, r0
	lsrs r1, 31
	str r1, [sp, 0x28]
_0804765E:
	adds r0, r7, 0
	bl sub_803F428
	lsls r0, 24
	lsrs r0, 24
	negs r1, r0
	orrs r1, r0
	lsrs r4, r1, 31
	ldr r0, [sp, 0x18]
	bl sub_803F428
	lsls r0, 24
	cmp r0, 0
	beq _0804767C
	movs r4, 0x1
_0804767C:
	mov r2, r8
	ldr r0, [r2]
	ldr r3, _08047850
	adds r0, r3
	add r1, sp, 0x20
	ldrb r1, [r1]
	strb r1, [r0]
	cmp r4, 0
	bne _08047690
	b _080477D0
_08047690:
	ldr r2, [sp, 0x1C]
	movs r3, 0x4
	ldrsh r0, [r2, r3]
	ldr r1, [sp, 0x18]
	movs r2, 0
	ldrsh r1, [r1, r2]
	mov r9, r1
	subs r1, r0, r1
	cmp r1, 0
	bge _080476A6
	negs r1, r1
_080476A6:
	ldr r3, [sp, 0x1C]
	movs r2, 0x6
	ldrsh r0, [r3, r2]
	ldr r3, [sp, 0x18]
	movs r2, 0x2
	ldrsh r3, [r3, r2]
	mov r10, r3
	subs r0, r3
	cmp r0, 0
	bge _080476BC
	negs r0, r0
_080476BC:
	adds r1, r0
	lsls r0, r1, 1
	adds r0, r1
	lsls r4, r0, 2
	adds r3, r4, 0
	adds r3, 0xC
	str r3, [sp, 0x30]
	cmp r3, 0x3F
	ble _080476D2
	movs r0, 0x40
	str r0, [sp, 0x30]
_080476D2:
	movs r1, 0
	str r1, [sp, 0x3C]
	movs r0, 0x80
	lsls r0, 12
	adds r1, r4, 0
	bl __divsi3
	str r0, [sp, 0x40]
	movs r2, 0
	ldrsh r1, [r7, r2]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 11
	mov r8, r0
	movs r3, 0x2
	ldrsh r1, [r7, r3]
	lsls r0, r1, 1
	adds r0, r1
	lsls r7, r0, 11
	mov r1, r9
	lsls r0, r1, 1
	add r0, r9
	lsls r0, 11
	mov r2, r8
	subs r0, r2
	adds r1, r4, 0
	bl __divsi3
	str r0, [sp, 0x34]
	mov r3, r10
	lsls r0, r3, 1
	add r0, r10
	lsls r0, 11
	subs r0, r7
	adds r1, r4, 0
	bl __divsi3
	str r0, [sp, 0x38]
	subs r0, r4, 0x3
	cmp r0, 0
	ble _080477D0
	str r0, [sp, 0x2C]
_08047726:
	movs r0, 0
	mov r10, r0
	ldr r0, [sp, 0x3C]
	cmp r0, 0
	bge _08047732
	adds r0, 0xFF
_08047732:
	asrs r0, 8
	bl sin_4096
	ldr r2, [sp, 0x30]
	adds r1, r0, 0
	muls r1, r2
	movs r0, 0x80
	lsls r0, 3
	mov r2, r8
	adds r3, r2, r0
	adds r2, r7, r0
	ldr r0, [sp, 0x1C]
	str r1, [r0, 0x1C]
	mov r0, r8
	cmp r0, 0
	bge _08047754
	adds r0, 0xFF
_08047754:
	asrs r0, 8
	adds r0, 0x8
	mov r9, r0
	adds r0, r7, 0
	cmp r7, 0
	bge _08047762
	adds r0, 0xFF
_08047762:
	asrs r0, 8
	adds r4, r0, 0
	adds r4, 0x10
	ldr r1, [sp, 0x3C]
	ldr r0, [sp, 0x40]
	adds r1, r0
	str r1, [sp, 0x3C]
	ldr r0, [sp, 0x1C]
	adds r1, r3, 0
	bl SetEntityPixelPos
	bl IsWaterTileset
	lsls r0, 24
	movs r2, 0
	cmp r0, 0
	beq _08047786
	movs r2, 0x3
_08047786:
	mov r0, r9
	adds r1, r4, 0
	bl sub_8083568
	lsls r0, 24
	cmp r0, 0
	beq _08047798
	movs r1, 0x1
	mov r10, r1
_08047798:
	movs r0, 0x1
	str r0, [sp]
	ldr r0, [sp, 0x1C]
	ldr r1, [sp, 0x24]
	movs r2, 0
	movs r3, 0xFF
	bl sub_80462AC
	lsls r0, 24
	cmp r0, 0
	beq _080477B2
	movs r2, 0x1
	mov r10, r2
_080477B2:
	mov r3, r10
	cmp r3, 0
	beq _080477BE
	movs r0, 0x17
	bl sub_803E46C
_080477BE:
	ldr r0, [sp, 0x34]
	add r8, r0
	ldr r1, [sp, 0x38]
	adds r7, r1
	ldr r2, [sp, 0x2C]
	subs r2, 0x1
	str r2, [sp, 0x2C]
	cmp r2, 0
	bne _08047726
_080477D0:
	ldr r3, [sp, 0x18]
	ldr r0, [r3]
	ldr r1, [sp, 0x1C]
	str r0, [r1, 0x4]
	ldr r0, _08047848
	ldr r0, [r0]
	ldr r2, _08047850
	adds r0, r2
	movs r1, 0
	strb r1, [r0]
	movs r1, 0
	ldrsh r0, [r3, r1]
	movs r2, 0x2
	ldrsh r1, [r3, r2]
	bl GetTile
	adds r4, r0, 0
	ldr r0, [r4, 0x10]
	cmp r0, 0
	bne _080477FA
	b _08047904
_080477FA:
	movs r3, 0x1
	mov r8, r3
	movs r7, 0
	bl GetEntityType
	cmp r0, 0x1
	bne _08047834
	ldr r0, [r4, 0x10]
	movs r1, 0x26
	bl HasHeldItem
	lsls r0, 24
	lsrs r0, 24
	negs r1, r0
	orrs r1, r0
	lsrs r7, r1, 31
	ldr r1, _08047854
	add r0, sp, 0x8
	bl InitPokemonMove
	ldr r0, [r4, 0x10]
	add r1, sp, 0x8
	bl sub_80571F0
	lsls r0, 24
	cmp r0, 0
	beq _08047834
	movs r0, 0
	mov r8, r0
_08047834:
	mov r1, r8
	cmp r1, 0
	beq _08047904
	ldr r1, [r4, 0x10]
	adds r5, r1, 0
	cmp r7, 0
	beq _0804785C
	ldr r0, _08047858
	ands r6, r0
	b _0804786E
	.align 2, 0
_08047848: .4byte gDungeon
_0804784C: .4byte 0x00018210
_08047850: .4byte 0x0001c05e
_08047854: .4byte 0x00000195
_08047858: .4byte 0xffffff00
_0804785C:
	ldr r0, [sp, 0x10]
	bl sub_8047930
	lsls r0, 24
	lsrs r0, 24
	ldr r1, _080478CC
	ands r1, r6
	adds r6, r1, 0
	orrs r6, r0
_0804786E:
	ldr r0, _080478D0
	ldr r1, [sp, 0x14]
	bl sub_8045C08
	ldr r0, _080478D4
	adds r1, r5, 0
	movs r2, 0
	bl SubstitutePlaceholderStringTags
	lsls r0, r6, 24
	cmp r0, 0
	beq _080478DC
	adds r0, r5, 0
	movs r1, 0x8
	bl sub_806CE94
	ldr r0, _080478D8
	ldr r2, [r0]
	ldr r0, [sp, 0x10]
	adds r1, r5, 0
	bl TryDisplayDungeonLoggableMessage3
	ldr r0, [sp, 0x10]
	adds r1, r5, 0
	bl TrySendImmobilizeSleepEndMsg
	lsls r0, 24
	lsrs r2, r0, 24
	movs r1, 0
	ldr r3, [sp, 0x28]
	cmp r3, 0
	bne _080478B6
	ldr r0, [sp, 0x64]
	ldrb r0, [r0]
	cmp r0, 0
	beq _080478B8
_080478B6:
	movs r1, 0x1
_080478B8:
	str r5, [sp]
	ldr r0, [sp, 0x14]
	str r0, [sp, 0x4]
	movs r0, 0x1
	ldr r3, [sp, 0x10]
	bl sub_80479B8
	movs r1, 0
	str r1, [sp, 0x20]
	b _08047904
	.align 2, 0
_080478CC: .4byte 0xffffff00
_080478D0: .4byte gFormatBuffer_Items
_080478D4: .4byte gFormatBuffer_Monsters
_080478D8: .4byte gUnknown_80F94C4
_080478DC:
	cmp r7, 0
	beq _080478F4
	ldr r0, _080478F0
	ldr r2, [r0]
	ldr r0, [sp, 0x10]
	adds r1, r5, 0
	bl TryDisplayDungeonLoggableMessage3
	b _08047900
	.align 2, 0
_080478F0: .4byte gUnknown_80F9510
_080478F4:
	ldr r0, _0804792C
	ldr r2, [r0]
	ldr r0, [sp, 0x10]
	adds r1, r5, 0
	bl TryDisplayDungeonLoggableMessage3
_08047900:
	movs r2, 0x1
	str r2, [sp, 0x20]
_08047904:
	ldr r3, [sp, 0x20]
	cmp r3, 0x1
	bne _0804791A
	movs r0, 0
	str r0, [sp]
	ldr r0, [sp, 0x10]
	ldr r1, [sp, 0x1C]
	ldr r2, [sp, 0x14]
	movs r3, 0
	bl sub_804652C
_0804791A:
	add sp, 0x44
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_0804792C: .4byte gUnknown_80F94F0
	thumb_func_end sub_80475C4

	.align 2,0
