	.include "constants/gba_constants.inc"
	.include "asm/macros.inc"

	.syntax unified

	.text

        thumb_func_start HasStatusAffectingActions
HasStatusAffectingActions:
	push {r4-r6,lr}
	adds r5, r0, 0
	ldr r4, [r5, 0x70]
	ldr r0, _08070050
	adds r1, r5, 0
	movs r2, 0
	bl SetMessageArgument
	adds r0, r4, 0
	adds r0, 0x44
	movs r1, 0x1
	bl SetAction
	adds r0, r4, 0
	adds r0, 0xA8
	ldrb r0, [r0]
	cmp r0, 0x3
	bne _08070042
	b _0807019C
_08070042:
	cmp r0, 0x3
	bgt _08070054
	cmp r0, 0x1
	bne _0807004C
	b _0807019C
_0807004C:
	b _0807005A
	.align 2, 0
_08070050: .4byte gAvailablePokemonNames
_08070054:
	cmp r0, 0x5
	bne _0807005A
	b _0807019C
_0807005A:
	adds r0, r4, 0
	adds r0, 0xB0
	ldrb r0, [r0]
	cmp r0, 0x3
	beq _0807008C
	cmp r0, 0x3
	bgt _0807006E
	cmp r0, 0x1
	beq _0807007A
	b _080700AC
_0807006E:
	cmp r0, 0x4
	beq _0807009C
	cmp r0, 0x6
	bne _08070078
	b _0807019C
_08070078:
	b _080700AC
_0807007A:
	ldr r0, _08070088
	ldr r1, [r0]
	adds r0, r5, 0
	bl SendMessage
	b _0807019C
	.align 2, 0
_08070088: .4byte gUnknown_80F954C
_0807008C:
	ldr r0, _08070098
	ldr r1, [r0]
	adds r0, r5, 0
	bl SendMessage
	b _0807019C
	.align 2, 0
_08070098: .4byte gUnknown_80F956C
_0807009C:
	ldr r0, _080700A8
	ldr r1, [r0]
	adds r0, r5, 0
	bl SendMessage
	b _0807019C
	.align 2, 0
_080700A8: .4byte gUnknown_80F958C
_080700AC:
	adds r0, r4, 0
	adds r0, 0xBC
	ldrb r0, [r0]
	cmp r0, 0x3
	beq _080700D4
	cmp r0, 0x7
	beq _080700E4
	adds r0, r4, 0
	adds r0, 0xC0
	ldrb r0, [r0]
	cmp r0, 0x1
	bne _080700F4
	ldr r0, _080700D0
	ldr r1, [r0]
	adds r0, r5, 0
	bl SendMessage
	b _0807019C
	.align 2, 0
_080700D0: .4byte gUnknown_80F95D8
_080700D4:
	ldr r0, _080700E0
	ldr r1, [r0]
	adds r0, r5, 0
	bl SendMessage
	b _0807019C
	.align 2, 0
_080700E0: .4byte gUnknown_80F95A4
_080700E4:
	ldr r0, _080700F0
	ldr r1, [r0]
	adds r0, r5, 0
	bl SendMessage
	b _0807019C
	.align 2, 0
_080700F0: .4byte gUnknown_80F95BC
_080700F4:
	adds r0, r4, 0
	adds r0, 0xC8
	ldrb r0, [r0]
	cmp r0, 0x2
	bne _0807012E
	adds r0, r4, 0
	adds r0, 0x44
	movs r2, 0x2
	ldrsh r1, [r4, r2]
	bl SetWalkAction
	movs r0, 0x8
	bl DungeonRandomCapped
	adds r1, r4, 0
	adds r1, 0x46
	strb r0, [r1]
	ldrh r1, [r5, 0x4]
	movs r2, 0xB6
	lsls r2, 1
	adds r0, r4, r2
	strh r1, [r0]
	ldrh r0, [r5, 0x6]
	subs r0, 0x1
	movs r1, 0xB7
	lsls r1, 1
	adds r2, r4, r1
	strh r0, [r2]
	b _0807019C
_0807012E:
	ldrb r0, [r4, 0x8]
	cmp r0, 0x1
	beq _0807019C
	adds r0, r4, 0
	adds r0, 0xE8
	ldrb r0, [r0]
	cmp r0, 0x1
	bne _0807017C
	adds r6, r4, 0
	adds r6, 0x46
	ldrb r1, [r6]
	adds r0, r5, 0
	bl sub_8070D6C
	lsls r0, 24
	cmp r0, 0
	bne _08070166
	movs r0, 0x2
	bl DungeonRandomCapped
	cmp r0, 0
	beq _08070174
	movs r0, 0x8
	bl DungeonRandomCapped
	movs r1, 0x7
	ands r1, r0
	strb r1, [r6]
_08070166:
	adds r0, r4, 0
	adds r0, 0x44
	movs r2, 0x2
	ldrsh r1, [r4, r2]
	bl SetWalkAction
	b _0807019C
_08070174:
	adds r0, r5, 0
	bl DecideAttack
	b _0807019C
_0807017C:
	cmp r0, 0x2
	beq _08070184
	movs r0, 0
	b _0807019E
_08070184:
	adds r0, r4, 0
	adds r0, 0x44
	movs r2, 0x2
	ldrsh r1, [r4, r2]
	bl SetWalkAction
	movs r0, 0x8
	bl DungeonRandomCapped
	adds r1, r4, 0
	adds r1, 0x46
	strb r0, [r1]
_0807019C:
	movs r0, 0x1
_0807019E:
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end HasStatusAffectingActions

	thumb_func_start sub_80701A4
sub_80701A4:
	push {r4-r7,lr}
	adds r7, r0, 0
	ldr r6, [r7, 0x70]
	movs r4, 0
	ldr r0, _080701D4
	adds r1, r7, 0
	movs r2, 0
	bl SetMessageArgument
	adds r0, r6, 0
	adds r0, 0x44
	movs r1, 0x1
	bl SetAction
	adds r0, r6, 0
	adds r0, 0xA8
	ldrb r0, [r0]
	cmp r0, 0x3
	beq _080701DC
	cmp r0, 0x3
	bgt _080701D8
	cmp r0, 0x1
	beq _080701DC
	b _080701E4
	.align 2, 0
_080701D4: .4byte gAvailablePokemonNames
_080701D8:
	cmp r0, 0x5
	bne _080701E4
_080701DC:
	ldr r0, _080701E0
	b _08070278
	.align 2, 0
_080701E0: .4byte gUnknown_80F95EC
_080701E4:
	adds r0, r6, 0
	adds r0, 0xB0
	ldrb r0, [r0]
	cmp r0, 0x3
	beq _0807020C
	cmp r0, 0x3
	bgt _080701F8
	cmp r0, 0x1
	beq _08070202
	b _0807021C
_080701F8:
	cmp r0, 0x4
	beq _08070214
	cmp r0, 0x6
	beq _08070280
	b _0807021C
_08070202:
	ldr r0, _08070208
	b _08070278
	.align 2, 0
_08070208: .4byte gUnknown_80F954C
_0807020C:
	ldr r0, _08070210
	b _08070278
	.align 2, 0
_08070210: .4byte gUnknown_80F956C
_08070214:
	ldr r0, _08070218
	b _08070278
	.align 2, 0
_08070218: .4byte gUnknown_80F958C
_0807021C:
	adds r0, r6, 0
	adds r0, 0xBC
	ldrb r0, [r0]
	cmp r0, 0x8
	bhi _0807026C
	lsls r0, 2
	ldr r1, _08070230
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08070230: .4byte _08070234
	.align 2, 0
_08070234:
	.4byte _0807026C
	.4byte _0807026C
	.4byte _08070258
	.4byte _0807025C
	.4byte _0807026C
	.4byte _0807026C
	.4byte _0807026C
	.4byte _08070264
	.4byte _0807026C
_08070258:
	movs r4, 0x1
	b _0807026C
_0807025C:
	ldr r0, _08070260
	b _08070278
	.align 2, 0
_08070260: .4byte gUnknown_80F95A4
_08070264:
	ldr r0, _08070268
	b _08070278
	.align 2, 0
_08070268: .4byte gUnknown_80F95BC
_0807026C:
	adds r0, r6, 0
	adds r0, 0xC0
	ldrb r0, [r0]
	cmp r0, 0x1
	bne _08070288
	ldr r0, _08070284
_08070278:
	ldr r1, [r0]
	adds r0, r7, 0
	bl SendMessage
_08070280:
	movs r0, 0x1
	b _08070322
	.align 2, 0
_08070284: .4byte gUnknown_80F95D8
_08070288:
	cmp r0, 0
	beq _08070320
	cmp r0, 0xB
	beq _08070320
	cmp r0, 0xC
	beq _08070320
	cmp r4, 0
	beq _080702A8
	ldr r0, _080702A4
	ldr r1, [r0]
	adds r0, r7, 0
	bl SendMessage
	b _0807031A
	.align 2, 0
_080702A4: .4byte gPtrMoveInterruptedMessage
_080702A8:
	movs r5, 0
	movs r0, 0x8C
	lsls r0, 1
	adds r4, r6, r0
_080702B0:
	ldrb r1, [r4]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _08070312
	adds r0, r7, 0
	adds r1, r4, 0
	bl sub_80570AC
	lsls r0, 24
	cmp r0, 0
	beq _08070312
	adds r0, r6, 0
	adds r0, 0xC2
	ldrb r0, [r0]
	cmp r0, r5
	bne _08070312
	adds r0, r6, 0
	adds r0, 0x44
	movs r1, 0x14
	bl SetAction
	adds r3, r5, 0
	adds r7, r6, 0
	adds r7, 0x50
	cmp r5, 0
	ble _0807030E
	ldrb r1, [r4]
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	beq _0807030E
	movs r4, 0x2
	lsls r0, r5, 3
	movs r1, 0x8C
	lsls r1, 1
	adds r0, r1
	adds r2, r0, r6
_080702FC:
	subs r2, 0x8
	subs r3, 0x1
	cmp r3, 0
	ble _0807030E
	ldrb r1, [r2]
	adds r0, r4, 0
	ands r0, r1
	cmp r0, 0
	bne _080702FC
_0807030E:
	strb r3, [r7]
	b _08070280
_08070312:
	adds r4, 0x8
	adds r5, 0x1
	cmp r5, 0x3
	ble _080702B0
_0807031A:
	adds r0, r7, 0
	bl sub_8079764
_08070320:
	movs r0, 0
_08070322:
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_80701A4

	thumb_func_start sub_8070328
sub_8070328:
	push {lr}
	lsls r0, 16
	asrs r0, 16
	bl GetWalkableTiles
	lsls r0, 24
	lsrs r1, r0, 24
	cmp r1, 0x3
	bhi _0807033E
	adds r0, r1, 0
	b _08070344
_0807033E:
	ldr r0, _08070348
	adds r0, r1, r0
	ldrb r0, [r0]
_08070344:
	pop {r1}
	bx r1
	.align 2, 0
_08070348: .4byte gUnknown_202F314
	thumb_func_end sub_8070328

	thumb_func_start sub_807034C
sub_807034C:
	push {r4,lr}
	adds r4, r1, 0
	lsls r0, 16
	asrs r2, r0, 16
	ldr r0, [r4, 0x10]
	cmp r0, 0
	bne _08070398
	ldrh r1, [r4]
	movs r0, 0x10
	ands r0, r1
	cmp r0, 0
	bne _08070398
	adds r0, r2, 0
	bl sub_8070328
	lsls r0, 24
	lsrs r2, r0, 24
	ldrh r0, [r4]
	movs r1, 0x3
	ands r1, r0
	cmp r2, 0x1
	beq _08070388
	cmp r2, 0x1
	bgt _08070382
	cmp r2, 0
	beq _0807038C
	b _08070390
_08070382:
	cmp r2, 0x2
	beq _08070394
	b _08070390
_08070388:
	cmp r1, 0x2
	beq _08070390
_0807038C:
	cmp r1, 0x1
	bne _08070398
_08070390:
	movs r0, 0
	b _0807039A
_08070394:
	cmp r1, 0
	bne _08070390
_08070398:
	movs r0, 0x1
_0807039A:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_807034C

	thumb_func_start sub_80703A0
sub_80703A0:
	push {r4-r7,lr}
	adds r6, r0, 0
	adds r4, r1, 0
	ldr r7, [r6, 0x70]
	movs r1, 0
	ldrsh r0, [r4, r1]
	movs r2, 0x2
	ldrsh r1, [r4, r2]
	bl GetMapTileAtPosition
	adds r5, r0, 0
	movs r1, 0
	ldrsh r0, [r4, r1]
	cmp r0, 0
	blt _08070456
	movs r2, 0x2
	ldrsh r1, [r4, r2]
	cmp r1, 0
	blt _08070456
	cmp r0, 0x37
	bgt _08070456
	cmp r1, 0x1F
	bgt _08070456
	ldr r0, [r5, 0x10]
	cmp r0, 0
	bne _08070456
	ldrh r1, [r5]
	movs r0, 0x10
	ands r0, r1
	cmp r0, 0
	bne _08070456
	bl sub_80441E8
	lsls r0, 24
	cmp r0, 0
	bne _08070400
	adds r0, r7, 0
	adds r0, 0xE4
	ldrb r0, [r0]
	cmp r0, 0x3
	beq _0807044E
	adds r0, r6, 0
	movs r1, 0x9
	bl sub_8046CB0
	lsls r0, 24
	cmp r0, 0
	bne _0807044E
_08070400:
	movs r1, 0x2
	ldrsh r0, [r7, r1]
	bl sub_8070328
	lsls r0, 24
	lsrs r4, r0, 24
	ldrh r0, [r5]
	movs r5, 0x3
	ands r5, r0
	adds r0, r6, 0
	movs r1, 0xC
	bl HasIQSkill
	lsls r0, 24
	cmp r0, 0
	beq _08070422
	movs r4, 0x2
_08070422:
	adds r0, r6, 0
	movs r1, 0xD
	bl HasIQSkill
	lsls r0, 24
	cmp r0, 0
	beq _08070432
	movs r4, 0x3
_08070432:
	cmp r4, 0x1
	beq _08070446
	cmp r4, 0x1
	bgt _08070440
	cmp r4, 0
	beq _0807044A
	b _0807044E
_08070440:
	cmp r4, 0x2
	beq _08070452
	b _0807044E
_08070446:
	cmp r5, 0x2
	beq _0807044E
_0807044A:
	cmp r5, 0x1
	bne _08070456
_0807044E:
	movs r0, 0
	b _08070458
_08070452:
	cmp r5, 0
	bne _0807044E
_08070456:
	movs r0, 0x1
_08070458:
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_80703A0

	thumb_func_start sub_8070460
sub_8070460:
	push {r4,lr}
	adds r1, r0, 0
	ldr r0, [r1, 0x70]
	adds r4, r0, 0
	adds r0, 0xE4
	ldrb r0, [r0]
	cmp r0, 0x3
	beq _08070492
	adds r0, r1, 0
	movs r1, 0x9
	bl sub_8046CB0
	lsls r0, 24
	cmp r0, 0
	bne _08070492
	movs r1, 0x2
	ldrsh r0, [r4, r1]
	bl sub_8070328
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x3
	beq _08070492
	movs r0, 0
	b _08070494
_08070492:
	movs r0, 0x1
_08070494:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_8070460

	thumb_func_start sub_807049C
sub_807049C:
	push {r4-r7,lr}
	adds r6, r0, 0
	adds r4, r1, 0
	ldr r7, [r6, 0x70]
	movs r1, 0
	ldrsh r0, [r4, r1]
	movs r2, 0x2
	ldrsh r1, [r4, r2]
	bl GetMapTileAtPosition
	adds r5, r0, 0
	movs r1, 0
	ldrsh r0, [r4, r1]
	cmp r0, 0
	blt _0807055A
	movs r2, 0x2
	ldrsh r1, [r4, r2]
	cmp r1, 0
	blt _0807055A
	cmp r0, 0x37
	bgt _0807055A
	cmp r1, 0x1F
	bgt _0807055A
	ldrh r1, [r5]
	movs r0, 0x10
	ands r0, r1
	cmp r0, 0
	bne _0807055A
	ldr r0, [r5, 0x10]
	cmp r0, 0
	beq _080704E2
	bl GetEntityType
	cmp r0, 0x1
	bne _0807055A
_080704E2:
	bl sub_80441E8
	lsls r0, 24
	cmp r0, 0
	bne _08070504
	adds r0, r7, 0
	adds r0, 0xE4
	ldrb r0, [r0]
	cmp r0, 0x3
	beq _08070552
	adds r0, r6, 0
	movs r1, 0x9
	bl sub_8046CB0
	lsls r0, 24
	cmp r0, 0
	bne _08070552
_08070504:
	movs r1, 0x2
	ldrsh r0, [r7, r1]
	bl sub_8070328
	lsls r0, 24
	lsrs r4, r0, 24
	ldrh r0, [r5]
	movs r5, 0x3
	ands r5, r0
	adds r0, r6, 0
	movs r1, 0xC
	bl HasIQSkill
	lsls r0, 24
	cmp r0, 0
	beq _08070526
	movs r4, 0x2
_08070526:
	adds r0, r6, 0
	movs r1, 0xD
	bl HasIQSkill
	lsls r0, 24
	cmp r0, 0
	beq _08070536
	movs r4, 0x3
_08070536:
	cmp r4, 0x1
	beq _0807054A
	cmp r4, 0x1
	bgt _08070544
	cmp r4, 0
	beq _0807054E
	b _08070552
_08070544:
	cmp r4, 0x2
	beq _08070556
	b _08070552
_0807054A:
	cmp r5, 0x2
	beq _08070552
_0807054E:
	cmp r5, 0x1
	bne _0807055A
_08070552:
	movs r0, 0
	b _0807055C
_08070556:
	cmp r5, 0
	bne _08070552
_0807055A:
	movs r0, 0x1
_0807055C:
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_807049C

	thumb_func_start sub_8070564
sub_8070564:
	push {r4-r6,lr}
	adds r4, r1, 0
	ldr r6, [r0, 0x70]
	movs r1, 0
	ldrsh r0, [r4, r1]
	movs r2, 0x2
	ldrsh r1, [r4, r2]
	bl GetMapTileAtPosition
	adds r5, r0, 0
	movs r1, 0
	ldrsh r0, [r4, r1]
	cmp r0, 0
	blt _080705E6
	movs r2, 0x2
	ldrsh r1, [r4, r2]
	cmp r1, 0
	blt _080705E6
	cmp r0, 0x37
	bgt _080705E6
	cmp r1, 0x1F
	bgt _080705E6
	ldrh r1, [r5]
	movs r0, 0x10
	ands r0, r1
	cmp r0, 0
	bne _080705E6
	ldr r0, [r5, 0x10]
	cmp r0, 0
	beq _080705A8
	bl GetEntityType
	cmp r0, 0x1
	bne _080705E6
_080705A8:
	movs r1, 0x2
	ldrsh r0, [r6, r1]
	bl sub_8070328
	lsls r0, 24
	lsrs r2, r0, 24
	adds r3, r2, 0
	ldrh r0, [r5]
	movs r1, 0x3
	ands r1, r0
	adds r0, r1, 0
	cmp r2, 0x1
	beq _080705DE
	cmp r2, 0x1
	bgt _080705CC
	cmp r2, 0
	beq _080705D8
	b _080705D4
_080705CC:
	cmp r3, 0x3
	bgt _080705D4
	cmp r1, 0
	beq _080705E6
_080705D4:
	movs r0, 0
	b _080705E8
_080705D8:
	cmp r1, 0x1
	bne _080705E6
	b _080705D4
_080705DE:
	cmp r1, 0x2
	beq _080705D4
	cmp r0, 0x1
	beq _080705D4
_080705E6:
	movs r0, 0x1
_080705E8:
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end sub_8070564

	thumb_func_start sub_80705F0
sub_80705F0:
	push {r4-r7,lr}
	adds r6, r0, 0
	adds r4, r1, 0
	ldr r7, [r6, 0x70]
	movs r1, 0
	ldrsh r0, [r4, r1]
	movs r2, 0x2
	ldrsh r1, [r4, r2]
	bl GetMapTileAtPosition
	adds r5, r0, 0
	movs r1, 0
	ldrsh r0, [r4, r1]
	cmp r0, 0
	blt _0807069A
	movs r2, 0x2
	ldrsh r1, [r4, r2]
	cmp r1, 0
	blt _0807069A
	cmp r0, 0x37
	bgt _0807069A
	cmp r1, 0x1F
	bgt _0807069A
	ldrh r1, [r5]
	movs r0, 0x10
	ands r0, r1
	cmp r0, 0
	bne _0807069A
	ldr r0, [r5, 0x10]
	cmp r0, 0
	beq _08070636
	bl GetEntityType
	cmp r0, 0x1
	bne _0807069A
_08070636:
	bl sub_80441E8
	lsls r0, 24
	cmp r0, 0
	bne _08070658
	adds r0, r7, 0
	adds r0, 0xE4
	ldrb r0, [r0]
	cmp r0, 0x3
	beq _08070696
	adds r0, r6, 0
	movs r1, 0x9
	bl sub_8046CB0
	lsls r0, 24
	cmp r0, 0
	bne _08070696
_08070658:
	movs r1, 0x2
	ldrsh r0, [r7, r1]
	bl sub_8070328
	lsls r0, 24
	lsrs r4, r0, 24
	ldrh r0, [r5]
	movs r5, 0x3
	ands r5, r0
	adds r0, r6, 0
	movs r1, 0xC
	bl HasIQSkill
	lsls r0, 24
	cmp r0, 0
	beq _0807067A
	movs r4, 0x2
_0807067A:
	adds r0, r6, 0
	movs r1, 0xD
	bl HasIQSkill
	lsls r0, 24
	cmp r0, 0
	beq _0807068A
	movs r4, 0x3
_0807068A:
	cmp r4, 0
	blt _08070696
	cmp r4, 0x2
	bgt _08070696
	cmp r5, 0
	beq _0807069A
_08070696:
	movs r0, 0
	b _0807069C
_0807069A:
	movs r0, 0x1
_0807069C:
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_80705F0

	thumb_func_start sub_80706A4
sub_80706A4:
	push {r4-r7,lr}
	adds r7, r0, 0
	adds r4, r1, 0
	ldr r6, [r7, 0x70]
	movs r1, 0
	ldrsh r0, [r4, r1]
	movs r2, 0x2
	ldrsh r1, [r4, r2]
	bl GetMapTileAtPosition
	adds r5, r0, 0
	movs r1, 0
	ldrsh r0, [r4, r1]
	cmp r0, 0
	blt _0807076A
	movs r2, 0x2
	ldrsh r1, [r4, r2]
	cmp r1, 0
	blt _0807076A
	cmp r0, 0x37
	bgt _0807076A
	cmp r1, 0x1F
	bgt _0807076A
	ldrh r1, [r5]
	movs r0, 0x10
	ands r0, r1
	cmp r0, 0
	bne _0807076A
	ldr r0, [r5, 0x10]
	cmp r0, 0
	beq _080706F2
	bl GetEntityType
	cmp r0, 0x1
	bne _0807076A
	ldr r0, [r5, 0x10]
	ldr r0, [r0, 0x70]
	cmp r0, r6
	bne _0807076A
_080706F2:
	bl sub_80441E8
	lsls r0, 24
	cmp r0, 0
	bne _08070714
	adds r0, r6, 0
	adds r0, 0xE4
	ldrb r0, [r0]
	cmp r0, 0x3
	beq _08070762
	adds r0, r7, 0
	movs r1, 0x9
	bl sub_8046CB0
	lsls r0, 24
	cmp r0, 0
	bne _08070762
_08070714:
	movs r1, 0x2
	ldrsh r0, [r6, r1]
	bl sub_8070328
	lsls r0, 24
	lsrs r4, r0, 24
	ldrh r0, [r5]
	movs r5, 0x3
	ands r5, r0
	adds r0, r7, 0
	movs r1, 0xC
	bl HasIQSkill
	lsls r0, 24
	cmp r0, 0
	beq _08070736
	movs r4, 0x2
_08070736:
	adds r0, r7, 0
	movs r1, 0xD
	bl HasIQSkill
	lsls r0, 24
	cmp r0, 0
	beq _08070746
	movs r4, 0x3
_08070746:
	cmp r4, 0x1
	beq _0807075A
	cmp r4, 0x1
	bgt _08070754
	cmp r4, 0
	beq _0807075E
	b _08070762
_08070754:
	cmp r4, 0x2
	beq _08070766
	b _08070762
_0807075A:
	cmp r5, 0x2
	beq _08070762
_0807075E:
	cmp r5, 0x1
	bne _0807076A
_08070762:
	movs r0, 0
	b _0807076C
_08070766:
	cmp r5, 0
	bne _08070762
_0807076A:
	movs r0, 0x1
_0807076C:
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_80706A4

	thumb_func_start sub_8070774
sub_8070774:
	push {r4-r6,lr}
	adds r6, r0, 0
	ldr r5, [r6, 0x70]
	movs r4, 0
	movs r0, 0x84
	lsls r0, 1
	adds r1, r5, r0
	movs r2, 0x4
_08070784:
	ldrb r0, [r1, 0x5]
	cmp r0, 0
	beq _0807078C
	subs r4, 0x1
_0807078C:
	ldrb r0, [r1]
	cmp r0, 0
	beq _08070794
	adds r4, 0x1
_08070794:
	adds r1, 0x1
	subs r2, 0x1
	cmp r2, 0
	bge _08070784
	adds r0, r5, 0
	adds r0, 0xAC
	ldrb r0, [r0]
	cmp r0, 0x4
	bne _080707A8
	subs r4, 0x1
_080707A8:
	movs r1, 0x2
	ldrsh r0, [r5, r1]
	bl GetMoveSpeed
	adds r4, r0
	adds r0, r6, 0
	movs r1, 0x6
	bl sub_8071858
	lsls r0, 24
	cmp r0, 0
	beq _080707D0
	adds r0, r6, 0
	bl sub_807E580
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x7
	bne _080707D0
	adds r4, 0x1
_080707D0:
	movs r0, 0x4
	ldrsh r1, [r5, r0]
	ldr r0, _0807081C
	cmp r1, r0
	bne _080707DC
	adds r4, 0x1
_080707DC:
	movs r0, 0x2
	ldrsh r1, [r5, r0]
	movs r0, 0xBE
	lsls r0, 1
	cmp r1, r0
	bne _080707FE
	ldrb r0, [r5, 0x6]
	cmp r0, 0
	beq _080707FE
	ldr r0, _08070820
	ldr r0, [r0]
	ldr r1, _08070824
	adds r0, r1
	ldrb r0, [r0]
	cmp r0, 0
	beq _080707FE
	adds r4, 0x1
_080707FE:
	cmp r4, 0
	bge _08070804
	movs r4, 0
_08070804:
	cmp r4, 0x4
	ble _0807080A
	movs r4, 0x4
_0807080A:
	movs r1, 0x82
	lsls r1, 1
	adds r0, r5, r1
	str r4, [r0]
	adds r0, r4, 0
	pop {r4-r6}
	pop {r1}
	bx r1
	.align 2, 0
_0807081C: .4byte 0x000001a3
_08070820: .4byte gDungeonGlobalData
_08070824: .4byte 0x0000066e
	thumb_func_end sub_8070774

	thumb_func_start sub_8070828
sub_8070828:
	push {r4-r6,lr}
	adds r4, r0, 0
	lsls r1, 24
	lsrs r6, r1, 24
	movs r5, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	bne _08070840
	movs r0, 0
	b _080708AE
_08070840:
	adds r0, r4, 0
	movs r1, 0x1B
	bl HasAbility
	lsls r0, 24
	cmp r0, 0
	beq _0807085E
	adds r0, r4, 0
	bl sub_807E580
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x4
	bne _0807085E
	movs r5, 0x1
_0807085E:
	adds r0, r4, 0
	movs r1, 0x4A
	bl HasAbility
	lsls r0, 24
	cmp r0, 0
	beq _0807087C
	adds r0, r4, 0
	bl sub_807E580
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _0807087C
	movs r5, 0x1
_0807087C:
	cmp r6, 0
	beq _080708A0
	ldr r0, [r4, 0x70]
	movs r1, 0x40
	adds r2, r5, 0
	bl sub_8071ACC
	lsls r0, 24
	cmp r0, 0
	beq _080708A0
	adds r0, r4, 0
	bl sub_80429B4
	ldr r0, _080708A8
	ldr r1, [r0]
	adds r0, r4, 0
	bl SendMessage
_080708A0:
	cmp r5, 0
	bne _080708AC
	movs r0, 0x1
	b _080708AE
	.align 2, 0
_080708A8: .4byte gUnknown_80FEE80
_080708AC:
	movs r0, 0x2
_080708AE:
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end sub_8070828

	thumb_func_start sub_80708B4
sub_80708B4:
	push {r4,r5,lr}
	adds r3, r0, 0
	adds r4, r2, 0
	ldr r0, _080708E8
	ldr r2, [r0]
	ldr r5, _080708EC
	adds r0, r2, r5
	ldrb r0, [r0]
	cmp r0, 0
	bne _080708DC
	adds r5, 0x6
	adds r0, r2, r5
	ldrb r0, [r0]
	cmp r0, 0
	bne _080708DC
	adds r0, r1, 0
	adds r0, 0xE4
	ldrb r0, [r0]
	cmp r0, 0x1
	bne _080708F4
_080708DC:
	ldrb r0, [r1, 0x6]
	cmp r0, 0
	beq _080708F4
	ldr r0, _080708F0
	b _08070900
	.align 2, 0
_080708E8: .4byte gDungeonGlobalData
_080708EC: .4byte 0x0001820a
_080708F0: .4byte gUnknown_80F8988
_080708F4:
	adds r0, r1, 0
	adds r0, 0xC8
	ldrb r0, [r0]
	cmp r0, 0x2
	bne _08070910
	ldr r0, _0807090C
_08070900:
	ldr r1, [r0]
	adds r0, r3, 0
	bl strcpy
	b _0807095A
	.align 2, 0
_0807090C: .4byte gUnknown_80F8968
_08070910:
	ldrb r0, [r1, 0x6]
	cmp r0, 0
	beq _08070942
	adds r0, r1, 0
	adds r0, 0x40
	ldrb r0, [r0]
	cmp r0, 0x4A
	beq _0807092A
	adds r0, r1, 0
	adds r0, 0xA4
	ldrb r0, [r0]
	cmp r0, 0x1
	bne _08070936
_0807092A:
	movs r0, 0x4
	ldrsh r1, [r1, r0]
	adds r0, r3, 0
	bl CopyYellowSpeciesNametoBuffer
	b _0807095A
_08070936:
	movs r5, 0x4
	ldrsh r1, [r1, r5]
	adds r0, r3, 0
	bl CopyCyanSpeciesNametoBuffer
	b _0807095A
_08070942:
	ldr r2, _08070960
	ldrb r1, [r1, 0xA]
	movs r0, 0x64
	muls r0, r1
	ldr r1, _08070964
	adds r0, r1
	ldr r1, [r2]
	adds r1, r0
	adds r0, r3, 0
	adds r2, r4, 0
	bl sub_808D9DC
_0807095A:
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_08070960: .4byte gRecruitedPokemonRef
_08070964: .4byte 0x00008df8
	thumb_func_end sub_80708B4

	thumb_func_start sub_8070968
sub_8070968:
	push {r4,lr}
	adds r4, r0, 0
	adds r3, r2, 0
	adds r0, r1, 0
	adds r0, 0xC8
	ldrb r0, [r0]
	cmp r0, 0x2
	bne _08070990
	ldr r1, _08070988
	adds r2, 0x30
	ldr r0, _0807098C
	ldr r3, [r0]
	adds r0, r4, 0
	bl ExpandPlaceholdersBuffer
	b _080709BA
	.align 2, 0
_08070988: .4byte gUnknown_8106FA4
_0807098C: .4byte gUnknown_80F8974
_08070990:
	ldrb r0, [r1, 0x6]
	cmp r0, 0
	beq _080709A2
	movs r0, 0x4
	ldrsh r1, [r1, r0]
	adds r0, r4, 0
	bl CopyCyanSpeciesNametoBuffer
	b _080709BA
_080709A2:
	ldr r2, _080709C0
	ldrb r1, [r1, 0xA]
	movs r0, 0x64
	muls r0, r1
	ldr r1, _080709C4
	adds r0, r1
	ldr r1, [r2]
	adds r1, r0
	adds r0, r4, 0
	adds r2, r3, 0
	bl sub_808D9DC
_080709BA:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080709C0: .4byte gRecruitedPokemonRef
_080709C4: .4byte 0x00008df8
	thumb_func_end sub_8070968

	thumb_func_start sub_80709C8
sub_80709C8:
	push {r4,lr}
	adds r3, r0, 0
	ldr r0, _080709F8
	ldr r2, [r0]
	ldr r4, _080709FC
	adds r0, r2, r4
	ldrb r0, [r0]
	cmp r0, 0
	bne _080709EE
	adds r4, 0x6
	adds r0, r2, r4
	ldrb r0, [r0]
	cmp r0, 0
	bne _080709EE
	adds r0, r1, 0
	adds r0, 0xE4
	ldrb r0, [r0]
	cmp r0, 0x1
	bne _08070A04
_080709EE:
	ldrb r0, [r1, 0x6]
	cmp r0, 0
	beq _08070A04
	ldr r0, _08070A00
	b _08070A10
	.align 2, 0
_080709F8: .4byte gDungeonGlobalData
_080709FC: .4byte 0x0001820a
_08070A00: .4byte gUnknown_80F8994
_08070A04:
	adds r0, r1, 0
	adds r0, 0xC8
	ldrb r0, [r0]
	cmp r0, 0x2
	bne _08070A20
	ldr r0, _08070A1C
_08070A10:
	ldr r1, [r0]
	adds r0, r3, 0
	bl strcpy
	b _08070A48
	.align 2, 0
_08070A1C: .4byte gUnknown_80F8974
_08070A20:
	ldrb r0, [r1, 0x6]
	cmp r0, 0
	beq _08070A32
	movs r0, 0x4
	ldrsh r1, [r1, r0]
	adds r0, r3, 0
	bl CopySpeciesNametoBuffer
	b _08070A48
_08070A32:
	ldr r2, _08070A50
	ldrb r1, [r1, 0xA]
	movs r0, 0x64
	muls r0, r1
	ldr r1, _08070A54
	adds r0, r1
	ldr r1, [r2]
	adds r1, r0
	adds r0, r3, 0
	bl sub_808DA0C
_08070A48:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08070A50: .4byte gRecruitedPokemonRef
_08070A54: .4byte 0x00008df8
	thumb_func_end sub_80709C8

	thumb_func_start sub_8070A58
sub_8070A58:
	push {r4,lr}
	ldr r0, [r0, 0x70]
	mov r12, r0
	adds r0, 0xA8
	ldrb r0, [r0]
	cmp r0, 0x1
	beq _08070ADE
	cmp r0, 0x3
	beq _08070ADE
	cmp r0, 0x4
	beq _08070ADE
	mov r0, r12
	adds r0, 0xAC
	ldrb r0, [r0]
	cmp r0, 0
	bne _08070ADE
	mov r0, r12
	adds r0, 0xB0
	ldrb r0, [r0]
	cmp r0, 0x5
	beq _08070A86
	cmp r0, 0
	bne _08070ADE
_08070A86:
	mov r0, r12
	adds r0, 0xBC
	ldrb r0, [r0]
	cmp r0, 0
	bne _08070ADE
	mov r0, r12
	adds r0, 0xC8
	ldrb r0, [r0]
	cmp r0, 0x1
	beq _08070ADE
	cmp r0, 0x2
	beq _08070ADE
	mov r0, r12
	adds r0, 0xD0
	ldrb r0, [r0]
	cmp r0, 0x1
	beq _08070ADE
	mov r0, r12
	adds r0, 0xDC
	ldrb r0, [r0]
	cmp r0, 0x2
	beq _08070ADE
	mov r0, r12
	adds r0, 0xE8
	ldrb r0, [r0]
	cmp r0, 0x1
	beq _08070ADE
	cmp r0, 0x2
	beq _08070ADE
	mov r0, r12
	adds r0, 0xEC
	ldrb r0, [r0]
	cmp r0, 0x1
	beq _08070ADE
	mov r0, r12
	adds r0, 0xF5
	ldrb r0, [r0]
	cmp r0, 0
	bne _08070ADE
	mov r0, r12
	adds r0, 0xFD
	ldrb r0, [r0]
	cmp r0, 0
	beq _08070AE2
_08070ADE:
	movs r0, 0x1
	b _08070B1E
_08070AE2:
	movs r3, 0
	movs r4, 0x1
	movs r2, 0x8C
	lsls r2, 1
	add r2, r12
_08070AEC:
	ldrb r1, [r2]
	adds r0, r4, 0
	ands r0, r1
	cmp r0, 0
	beq _08070B00
	ldrb r1, [r2, 0x1]
	adds r0, r4, 0
	ands r0, r1
	cmp r0, 0
	bne _08070ADE
_08070B00:
	adds r2, 0x8
	adds r3, 0x1
	cmp r3, 0x3
	ble _08070AEC
	movs r3, 0
	ldr r1, _08070B24
	add r1, r12
_08070B0E:
	adds r0, r1, r3
	ldrb r0, [r0]
	cmp r0, 0
	bne _08070ADE
	adds r3, 0x1
	cmp r3, 0x4
	ble _08070B0E
	movs r0, 0
_08070B1E:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_08070B24: .4byte 0x0000010d
	thumb_func_end sub_8070A58

	thumb_func_start sub_8070B28
sub_8070B28:
	push {lr}
	ldr r0, [r0, 0x70]
	adds r0, 0xA8
	ldrb r0, [r0]
	cmp r0, 0x1
	beq _08070B40
	cmp r0, 0x5
	beq _08070B40
	cmp r0, 0x3
	beq _08070B40
	movs r0, 0
	b _08070B42
_08070B40:
	movs r0, 0x1
_08070B42:
	pop {r1}
	bx r1
	thumb_func_end sub_8070B28

	thumb_func_start sub_8070B48
sub_8070B48:
	push {lr}
	ldr r0, [r0, 0x70]
	adds r1, r0, 0
	movs r2, 0x10
	ldrsh r0, [r1, r2]
	cmp r0, 0
	bge _08070B58
	adds r0, 0x3
_08070B58:
	movs r2, 0xE
	ldrsh r1, [r1, r2]
	asrs r0, 2
	cmp r1, r0
	ble _08070B66
	movs r0, 0
	b _08070B68
_08070B66:
	movs r0, 0x1
_08070B68:
	pop {r1}
	bx r1
	thumb_func_end sub_8070B48

	.align 2, 0
