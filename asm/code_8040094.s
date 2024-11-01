	#include "asm/constants/gba_constants.inc"
	#include "asm/macros.inc"

	.syntax unified

	.text

	thumb_func_start sub_8040150
sub_8040150:
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	sub sp, 0x4
	lsls r0, 24
	lsrs r0, 24
	mov r9, r0
	movs r0, 0
	ldr r2, _080401EC
_08040164:
	movs r4, 0
	lsls r1, r0, 3
	adds r3, r0, 0x1
	mov r8, r3
	subs r1, r0
	lsls r0, r1, 7
	ldr r3, _080401F0
	adds r6, r0, r3
	lsls r5, r1, 2
_08040176:
	ldr r0, [r2]
	adds r0, r6
	lsls r1, r4, 5
	adds r0, r1
	movs r1, 0x20
	str r2, [sp]
	bl CpuClear
	ldr r2, [sp]
	ldr r0, [r2]
	adds r1, r4, r5
	ldr r3, _080401F4
	adds r0, r3
	adds r0, r1
	movs r7, 0
	strb r7, [r0]
	adds r4, 0x1
	cmp r4, 0x1B
	ble _08040176
	mov r0, r8
	cmp r0, 0xF
	ble _08040164
	mov r0, r9
	cmp r0, 0
	bne _080401B0
	ldr r1, _080401F8
	movs r0, 0x64
	strh r0, [r1]
	strh r0, [r1, 0x2]
_080401B0:
	ldr r3, _080401EC
	ldr r0, [r3]
	ldr r2, _080401FC
	adds r1, r0, r2
	str r7, [r1]
	ldr r1, _08040200
	adds r0, r1
	movs r2, 0x1
	strb r2, [r0]
	ldr r0, [r3]
	ldr r3, _08040204
	adds r0, r3
	strb r7, [r0]
	ldr r0, _08040208
	strb r2, [r0]
	ldr r1, _0804020C
	ldr r0, _08040210
	str r0, [r1]
	ldr r0, _08040214
	strb r2, [r0]
	bl sub_8040238
	add sp, 0x4
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_080401EC: .4byte gDungeon
_080401F0: .4byte 0x0001822c
_080401F4: .4byte 0x0001ba2c
_080401F8: .4byte gUnknown_203B410
_080401FC: .4byte 0x0001bdcc
_08040200: .4byte 0x0001bdd0
_08040204: .4byte 0x0001bdd2
_08040208: .4byte gUnknown_202EE00
_0804020C: .4byte gUnknown_202EE08
_08040210: .4byte 0x06001700
_08040214: .4byte gUnknown_202EE01
	thumb_func_end sub_8040150

	thumb_func_start sub_8040218
sub_8040218:
	push {lr}
	ldr r0, _08040230
	ldr r0, [r0]
	cmp r0, 0
	beq _08040226
	bl CloseFile
_08040226:
	bl sub_8040124
	pop {r0}
	bx r0
	.align 2, 0
_08040230: .4byte gUnknown_202EE04
	thumb_func_end sub_8040218

	thumb_func_start nullsub_203
nullsub_203:
	bx lr
	thumb_func_end nullsub_203

	thumb_func_start sub_8040238
sub_8040238:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	ldr r1, _0804026C
	ldr r0, [r1]
	cmp r0, 0
	beq _080402A0
	ldr r0, _08040270
	ldrb r0, [r0]
	cmp r0, 0
	beq _080402A0
	movs r6, 0
	ldr r0, _08040274
	mov r8, r0
	adds r7, r1, 0
_08040256:
	cmp r6, 0xE
	bne _08040278
	movs r0, 0xEE
	mov r1, r8
	bl SetBGPaletteBufferColorArray
	movs r0, 0xEE
	mov r1, r8
	bl nullsub_5
	b _0804029A
	.align 2, 0
_0804026C: .4byte gUnknown_202EE04
_08040270: .4byte gUnknown_202EE01
_08040274: .4byte gUnknown_202D03C
_08040278:
	adds r5, r6, 0
	adds r5, 0xE0
	ldr r0, [r7]
	ldr r0, [r0, 0x4]
	lsls r4, r6, 2
	ldr r1, [r0, 0x4]
	adds r1, r4
	adds r0, r5, 0
	bl SetBGPaletteBufferColorArray
	ldr r0, [r7]
	ldr r0, [r0, 0x4]
	ldr r1, [r0, 0x4]
	adds r1, r4
	adds r0, r5, 0
	bl nullsub_5
_0804029A:
	adds r6, 0x1
	cmp r6, 0xF
	ble _08040256
_080402A0:
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_8040238

	thumb_func_start sub_80402AC
sub_80402AC:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x1C
	mov r8, r0
	str r1, [sp]
	ldr r4, _0804034C
	ldr r0, [r4]
	str r0, [sp, 0x4]
	movs r1, 0x1
	mov r10, r1
	ldr r0, _08040350
	ldr r0, [r0]
	cmp r0, 0
	bne _080402D0
	b _08040776
_080402D0:
	ldr r0, _08040354
	ldrb r0, [r0]
	cmp r0, 0
	bne _080402DA
	b _08040776
_080402DA:
	bl sub_800EC74
	lsls r0, 24
	cmp r0, 0
	beq _080402E6
	b _08040776
_080402E6:
	mov r2, r8
	cmp r2, 0
	bge _080402EE
	b _08040776
_080402EE:
	ldr r3, [sp]
	cmp r3, 0x1
	bgt _080402F6
	b _08040776
_080402F6:
	cmp r2, 0x37
	ble _080402FC
	b _08040776
_080402FC:
	cmp r3, 0x1E
	ble _08040302
	b _08040776
_08040302:
	mov r0, r8
	adds r1, r3, 0
	bl GetTile
	mov r9, r0
	ldrh r0, [r0]
	movs r5, 0x3
	ands r5, r0
	str r5, [sp, 0x8]
	ldr r0, [r4]
	ldr r7, _08040358
	adds r1, r0, r7
	ldrb r1, [r1]
	str r1, [sp, 0xC]
	ldr r2, _0804035C
	adds r1, r0, r2
	ldrb r5, [r1]
	ldr r3, _08040360
	adds r1, r0, r3
	ldrb r1, [r1]
	str r1, [sp, 0x14]
	subs r7, 0x2
	adds r1, r0, r7
	ldrb r1, [r1]
	str r1, [sp, 0x10]
	ldr r1, _08040364
	adds r0, r1
	ldrb r0, [r0]
	cmp r5, 0
	beq _08040368
	mov r2, r9
	ldrb r0, [r2, 0x4]
	mov r7, r10
	ands r7, r0
	movs r3, 0
	str r3, [sp, 0x18]
	b _0804039C
	.align 2, 0
_0804034C: .4byte gDungeon
_08040350: .4byte gUnknown_202EE04
_08040354: .4byte gUnknown_202EE01
_08040358: .4byte 0x00018210
_0804035C: .4byte 0x0001820a
_08040360: .4byte 0x0001820f
_08040364: .4byte 0x0001820b
_08040368:
	cmp r0, 0
	beq _08040370
	movs r7, 0x1
	b _08040378
_08040370:
	mov r7, r9
	ldrb r0, [r7, 0x4]
	mov r7, r10
	ands r7, r0
_08040378:
	bl sub_8043D10
	lsls r0, 24
	cmp r0, 0
	bne _08040398
	ldr r0, _08040390
	ldr r0, [r0]
	ldr r1, _08040394
	adds r0, r1
	ldrb r0, [r0]
	str r0, [sp, 0x18]
	b _0804039C
	.align 2, 0
_08040390: .4byte gDungeon
_08040394: .4byte 0x00018211
_08040398:
	movs r2, 0
	str r2, [sp, 0x18]
_0804039C:
	bl sub_8094C48
	lsls r0, 24
	cmp r0, 0
	bne _080403A8
	b _08040632
_080403A8:
	ldr r0, _080403FC
	ldr r0, [r0]
	ldr r3, _08040400
	adds r0, r3
	ldrb r0, [r0]
	cmp r0, 0
	beq _080403B8
	b _08040632
_080403B8:
	movs r6, 0
	cmp r5, 0
	bne _0804045E
	mov r0, r9
	ldr r4, [r0, 0x10]
	cmp r4, 0
	beq _0804045E
	adds r0, r4, 0
	bl GetEntityType
	adds r1, r0, 0
	ldr r0, _08040404
	ldrb r0, [r0]
	cmp r0, 0
	beq _0804045E
	cmp r1, 0x1
	bne _0804045E
	adds r0, r4, 0
	bl sub_8045804
	lsls r0, 24
	cmp r0, 0
	beq _0804045E
	ldr r1, [r4, 0x70]
	adds r0, r1, 0
	adds r0, 0x40
	ldrb r0, [r0]
	cmp r0, 0x4A
	beq _080403F6
	cmp r0, 0x47
	bne _08040408
_080403F6:
	movs r0, 0x1
	b _0804040A
	.align 2, 0
_080403FC: .4byte gDungeon
_08040400: .4byte 0x0001356c
_08040404: .4byte gUnknown_202EE00
_08040408:
	movs r0, 0
_0804040A:
	cmp r0, 0
	bne _08040458
	adds r0, r1, 0
	adds r0, 0xA4
	ldrb r0, [r0]
	cmp r0, 0x1
	beq _08040458
	cmp r0, 0x4
	beq _08040458
	ldrb r0, [r1, 0x6]
	cmp r0, 0
	beq _08040426
	movs r6, 0x2
	b _0804045A
_08040426:
	ldrb r0, [r1, 0x7]
	cmp r0, 0
	beq _08040458
	ldr r0, _0804044C
	mov r1, r8
	strh r1, [r0]
	mov r2, sp
	ldrh r2, [r2]
	strh r2, [r0, 0x2]
	ldr r0, _08040450
	ldr r0, [r0]
	ldr r3, _08040454
	adds r0, r3
	ldrb r0, [r0]
	cmp r0, 0
	beq _0804045A
	movs r6, 0x8
	b _0804045A
	.align 2, 0
_0804044C: .4byte gUnknown_203B410
_08040450: .4byte gDungeon
_08040454: .4byte 0x00018214
_08040458:
	movs r6, 0xA
_0804045A:
	movs r0, 0
	mov r10, r0
_0804045E:
	mov r1, r10
	cmp r1, 0
	beq _0804054E
	cmp r5, 0
	bne _08040548
	mov r2, r9
	ldr r4, [r2, 0x14]
	cmp r4, 0
	beq _08040500
	adds r0, r4, 0
	bl GetEntityType
	adds r5, r0, 0
	cmp r7, 0
	bne _0804049E
	movs r6, 0
	cmp r5, 0x3
	bne _0804054E
	ldr r3, [sp, 0x10]
	cmp r3, 0
	bne _08040494
	mov r5, r9
	ldrh r1, [r5, 0x4]
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	beq _0804054E
_08040494:
	ldr r0, [sp, 0x8]
	cmp r0, 0
	beq _0804054E
	movs r6, 0x3
	b _0804054E
_0804049E:
	cmp r5, 0x2
	bne _080404C4
	adds r0, r4, 0
	adds r0, 0x20
	ldrb r0, [r0]
	cmp r0, 0
	bne _080404B2
	ldr r1, [sp, 0x14]
	cmp r1, 0
	beq _080404C4
_080404B2:
	adds r0, r4, 0
	bl GetTrapData
	ldr r1, _080404FC
	ldrb r0, [r0]
	adds r0, r1
	ldrb r6, [r0]
	movs r2, 0
	mov r10, r2
_080404C4:
	mov r3, r10
	cmp r3, 0
	beq _0804054E
	cmp r5, 0x3
	bne _080404EC
	ldr r5, [sp, 0x10]
	cmp r5, 0
	bne _080404E0
	mov r0, r9
	ldrh r1, [r0, 0x4]
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	beq _080404EC
_080404E0:
	ldr r1, [sp, 0x8]
	cmp r1, 0
	beq _080404EC
	movs r6, 0x3
	movs r2, 0
	mov r10, r2
_080404EC:
	mov r3, r10
	cmp r3, 0
	beq _0804054E
	ldr r5, [sp, 0x8]
	cmp r5, 0x1
	beq _08040548
	movs r6, 0
	b _0804054E
	.align 2, 0
_080404FC: .4byte gUnknown_80F65F0
_08040500:
	cmp r7, 0
	bne _08040528
	ldr r0, [sp, 0x18]
	cmp r0, 0
	beq _08040548
	mov r2, r9
	ldrh r1, [r2]
	movs r0, 0x80
	lsls r0, 2
	ands r0, r1
	cmp r0, 0
	beq _08040548
	bl sub_8043D10
	lsls r0, 24
	movs r6, 0x5
	cmp r0, 0
	bne _0804054E
	movs r6, 0x6
	b _0804054E
_08040528:
	mov r3, r9
	ldrh r1, [r3]
	movs r0, 0x80
	lsls r0, 2
	ands r0, r1
	cmp r0, 0
	beq _08040548
	bl sub_8043D10
	lsls r0, 24
	movs r6, 0x5
	cmp r0, 0
	bne _08040544
	movs r6, 0x6
_08040544:
	movs r5, 0
	mov r10, r5
_08040548:
	mov r0, r10
	cmp r0, 0
	bne _0804055A
_0804054E:
	ldr r1, [sp, 0xC]
	cmp r1, 0
	beq _0804055A
	cmp r6, 0
	beq _0804055E
	movs r6, 0xB
_0804055A:
	cmp r6, 0
	bne _08040606
_0804055E:
	cmp r7, 0
	beq _08040568
	ldr r2, [sp, 0x8]
	cmp r2, 0x1
	beq _0804056C
_08040568:
	movs r6, 0x1
	b _08040606
_0804056C:
	movs r4, 0xF
	ldr r3, [sp]
	cmp r3, 0x1E
	bgt _0804058A
	adds r1, r3, 0
	adds r1, 0x1
	mov r0, r8
	bl GetTile
	ldrh r1, [r0]
	movs r0, 0x3
	ands r0, r1
	cmp r0, 0x1
	bne _0804058A
	movs r4, 0xE
_0804058A:
	ldr r5, [sp]
	cmp r5, 0
	ble _080405AA
	adds r1, r5, 0
	subs r1, 0x1
	mov r0, r8
	bl GetTile
	ldrh r1, [r0]
	movs r0, 0x3
	ands r0, r1
	cmp r0, 0x1
	bne _080405AA
	movs r0, 0x5
	negs r0, r0
	ands r4, r0
_080405AA:
	mov r7, r8
	cmp r7, 0x36
	bgt _080405CA
	mov r0, r8
	adds r0, 0x1
	ldr r1, [sp]
	bl GetTile
	ldrh r1, [r0]
	movs r0, 0x3
	ands r0, r1
	cmp r0, 0x1
	bne _080405CA
	movs r0, 0x3
	negs r0, r0
	ands r4, r0
_080405CA:
	mov r0, r8
	cmp r0, 0
	ble _080405E8
	subs r0, 0x1
	ldr r1, [sp]
	bl GetTile
	ldrh r1, [r0]
	movs r0, 0x3
	ands r0, r1
	cmp r0, 0x1
	bne _080405E8
	movs r0, 0x9
	negs r0, r0
	ands r4, r0
_080405E8:
	lsls r0, r4, 16
	asrs r6, r0, 16
	mov r2, r9
	ldrh r1, [r2, 0x4]
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	beq _080405FE
	adds r0, r6, 0
	adds r0, 0x10
	b _08040602
_080405FE:
	adds r0, r6, 0
	adds r0, 0x20
_08040602:
	lsls r0, 16
	asrs r6, r0, 16
_08040606:
	ldr r0, _08040618
	ldr r0, [r0]
	ldrb r0, [r0, 0x4]
	cmp r0, 0x6
	bne _0804061C
	adds r0, r6, 0
	adds r0, 0x80
	b _0804062C
	.align 2, 0
_08040618: .4byte gGameOptionsRef
_0804061C:
	bl DoesNotHaveShadedMap
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _0804063A
	adds r0, r6, 0
	adds r0, 0x40
_0804062C:
	lsls r0, 16
	asrs r6, r0, 16
	b _0804063A
_08040632:
	movs r6, 0x1
	ldr r1, _0804074C
	movs r0, 0x64
	strh r0, [r1]
_0804063A:
	mov r3, r8
	lsrs r0, r3, 31
	add r0, r8
	asrs r0, 1
	mov r9, r0
	ldr r0, [sp]
	subs r0, 0x2
	lsrs r1, r0, 31
	adds r1, r0, r1
	asrs r1, 1
	mov r5, r9
	lsls r3, r5, 1
	mov r7, r8
	subs r3, r7, r3
	lsls r2, r1, 1
	subs r0, r2
	lsls r0, 1
	adds r3, r0
	lsls r0, r1, 3
	subs r5, r0, r1
	lsls r0, r5, 7
	ldr r1, _08040750
	adds r0, r1
	ldr r2, [sp, 0x4]
	adds r0, r2, r0
	mov r7, r9
	lsls r1, r7, 5
	adds r4, r0, r1
	ldr r0, _08040754
	ldr r0, [r0]
	ldr r1, [r0, 0x4]
	lsls r0, r6, 2
	adds r0, r3
	ldr r1, [r1]
	lsls r0, 2
	adds r0, r1
	ldr r2, [r0]
	ldr r0, [r4]
	ldr r1, [r2]
	ands r0, r1
	ldr r1, [r2, 0x4]
	orrs r0, r1
	str r0, [r4]
	ldr r0, [r4, 0x4]
	ldr r1, [r2, 0x8]
	ands r0, r1
	ldr r1, [r2, 0xC]
	orrs r0, r1
	str r0, [r4, 0x4]
	ldr r0, [r4, 0x8]
	ldr r1, [r2, 0x10]
	ands r0, r1
	ldr r1, [r2, 0x14]
	orrs r0, r1
	str r0, [r4, 0x8]
	ldr r0, [r4, 0xC]
	ldr r1, [r2, 0x18]
	ands r0, r1
	ldr r1, [r2, 0x1C]
	orrs r0, r1
	str r0, [r4, 0xC]
	ldr r0, [r4, 0x10]
	ldr r1, [r2, 0x20]
	ands r0, r1
	ldr r1, [r2, 0x24]
	orrs r0, r1
	str r0, [r4, 0x10]
	ldr r0, [r4, 0x14]
	ldr r1, [r2, 0x28]
	ands r0, r1
	ldr r1, [r2, 0x2C]
	orrs r0, r1
	str r0, [r4, 0x14]
	ldr r0, [r4, 0x18]
	ldr r1, [r2, 0x30]
	ands r0, r1
	ldr r1, [r2, 0x34]
	orrs r0, r1
	str r0, [r4, 0x18]
	ldr r0, [r4, 0x1C]
	ldr r1, [r2, 0x38]
	ands r0, r1
	ldr r1, [r2, 0x3C]
	orrs r0, r1
	str r0, [r4, 0x1C]
	ldr r0, [sp, 0x4]
	ldr r1, _08040758
	adds r2, r0, r1
	ldrb r0, [r2]
	cmp r0, 0
	bne _08040776
	lsls r5, 2
	mov r10, r5
	mov r3, r9
	add r3, r10
	ldr r5, _0804075C
	mov r8, r5
	ldr r0, [sp, 0x4]
	add r0, r8
	adds r1, r0, r3
	ldrb r0, [r1]
	cmp r0, 0
	bne _08040776
	movs r0, 0x1
	strb r0, [r1]
	ldr r7, [sp, 0x4]
	ldr r1, _08040760
	adds r6, r7, r1
	ldr r5, [r6]
	cmp r5, 0x27
	bgt _08040774
	lsls r1, r5, 1
	adds r1, r5
	lsls r1, 2
	ldr r0, _08040764
	adds r2, r7, r0
	adds r2, r1
	ldr r0, _08040768
	lsls r3, 5
	ldr r0, [r0]
	adds r0, r3
	str r0, [r2]
	ldr r2, _0804076C
	adds r0, r7, r2
	adds r0, r1
	str r4, [r0]
	ldr r3, _08040770
	adds r2, r7, r3
	adds r2, r1
	mov r0, r10
	add r0, r8
	adds r0, r7, r0
	add r0, r9
	str r0, [r2]
	adds r0, r5, 0x1
	str r0, [r6]
	b _08040776
	.align 2, 0
_0804074C: .4byte gUnknown_203B410
_08040750: .4byte 0x0001822c
_08040754: .4byte gUnknown_202EE04
_08040758: .4byte 0x0001bdd1
_0804075C: .4byte 0x0001ba2c
_08040760: .4byte 0x0001bdcc
_08040764: .4byte 0x0001bbec
_08040768: .4byte gUnknown_202EE08
_0804076C: .4byte 0x0001bbf0
_08040770: .4byte 0x0001bbf4
_08040774:
	strb r0, [r2]
_08040776:
	add sp, 0x1C
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_80402AC

	thumb_func_start sub_8040788
sub_8040788:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	ldr r0, _08040814
	ldr r0, [r0]
	mov r8, r0
	cmp r0, 0
	beq _08040870
	ldr r0, _08040818
	add r0, r8
	ldrb r0, [r0]
	cmp r0, 0
	beq _08040870
	bl sub_800EC74
	lsls r0, 24
	lsrs r2, r0, 24
	cmp r2, 0
	bne _08040870
	ldr r1, _0804081C
	add r1, r8
	ldrb r0, [r1]
	cmp r0, 0
	bne _0804082C
	movs r6, 0
	ldr r1, _08040820
	add r1, r8
	ldr r0, [r1]
	cmp r6, r0
	bge _08040868
	adds r5, r1, 0
	movs r4, 0
_080407C8:
	ldr r1, _08040824
	adds r0, r4, r1
	mov r1, r8
	adds r3, r1, r0
	ldr r1, [r3, 0x4]
	ldr r2, [r3]
	ldr r0, _08040828
	ldr r0, [r0]
	cmp r0, 0
	beq _080407E0
	cmp r0, 0x3
	bne _08040800
_080407E0:
	ldm r1!, {r0}
	stm r2!, {r0}
	ldm r1!, {r0}
	stm r2!, {r0}
	ldm r1!, {r0}
	stm r2!, {r0}
	ldm r1!, {r0}
	stm r2!, {r0}
	ldm r1!, {r0}
	stm r2!, {r0}
	ldm r1!, {r0}
	stm r2!, {r0}
	ldm r1!, {r0}
	stm r2!, {r0}
	ldr r0, [r1]
	str r0, [r2]
_08040800:
	ldr r0, [r3, 0x8]
	movs r1, 0
	strb r1, [r0]
	adds r4, 0xC
	adds r6, 0x1
	ldr r0, [r5]
	cmp r6, r0
	blt _080407C8
	b _08040868
	.align 2, 0
_08040814: .4byte gDungeon
_08040818: .4byte 0x0001bdd0
_0804081C: .4byte 0x0001bdd1
_08040820: .4byte 0x0001bdcc
_08040824: .4byte 0x0001bbec
_08040828: .4byte gUnknown_202EDD0
_0804082C:
	strb r2, [r1]
	ldr r0, _0804087C
	ldr r5, [r0]
	ldr r4, _08040880
	add r4, r8
	movs r6, 0
	movs r7, 0x80
	lsls r7, 1
_0804083C:
	ldr r0, _08040884
	ldr r0, [r0]
	cmp r0, 0
	beq _08040848
	cmp r0, 0x3
	bne _08040854
_08040848:
	adds r0, r5, 0
	adds r1, r4, 0
	movs r2, 0x80
	lsls r2, 1
	bl CpuCopy
_08040854:
	adds r5, r7
	adds r4, r7
	adds r6, 0x8
	ldr r0, _08040888
	cmp r6, r0
	ble _0804083C
	ldr r1, _0804088C
	add r1, r8
	movs r0, 0x1
	strb r0, [r1]
_08040868:
	ldr r1, _08040890
	add r1, r8
	movs r0, 0
	str r0, [r1]
_08040870:
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_0804087C: .4byte gUnknown_202EE08
_08040880: .4byte 0x0001822c
_08040884: .4byte gUnknown_202EDD0
_08040888: .4byte 0x000001bf
_0804088C: .4byte 0x0001bdd2
_08040890: .4byte 0x0001bdcc
	thumb_func_end sub_8040788

	thumb_func_start sub_8040894
sub_8040894:
	push {r4-r7,lr}
	sub sp, 0x8
	ldr r0, _080409F4
	ldr r1, [r0]
	ldr r2, _080409F8
	adds r0, r1, r2
	ldrb r0, [r0]
	cmp r0, 0
	beq _080408A8
	b _08040A6A
_080408A8:
	adds r2, 0x5
	adds r0, r1, r2
	ldrb r0, [r0]
	cmp r0, 0
	bne _080408B4
	b _08040A6A
_080408B4:
	ldr r7, _080409FC
	movs r1, 0
	ldrsh r0, [r7, r1]
	cmp r0, 0x63
	ble _080408C0
	b _08040A6A
_080408C0:
	ldr r0, _08040A00
	ldrb r1, [r0]
	adds r1, 0x1
	strb r1, [r0]
	movs r0, 0x8
	ands r1, r0
	cmp r1, 0
	beq _080408D2
	b _08040A6A
_080408D2:
	movs r0, 0
	movs r1, 0
	str r0, [sp]
	str r1, [sp, 0x4]
	mov r0, sp
	ldrh r0, [r0]
	ldr r1, _08040A04
	ands r1, r0
	ldr r3, _08040A08
	ldr r0, [sp]
	ands r0, r3
	orrs r0, r1
	str r0, [sp]
	mov r1, sp
	ldrh r1, [r1]
	adds r2, r3, 0
	ands r2, r0
	orrs r2, r1
	str r2, [sp]
	mov r0, sp
	ldrh r1, [r0]
	ldr r0, _08040A0C
	ands r0, r1
	adds r1, r3, 0
	ands r1, r2
	orrs r1, r0
	str r1, [sp]
	mov r0, sp
	ldrh r0, [r0]
	adds r2, r3, 0
	ands r2, r1
	orrs r2, r0
	str r2, [sp]
	mov r0, sp
	ldrh r1, [r0]
	ldr r5, _08040A10
	adds r0, r5, 0
	ands r0, r1
	adds r1, r3, 0
	ands r1, r2
	orrs r1, r0
	str r1, [sp]
	mov r0, sp
	ldrh r0, [r0]
	adds r2, r3, 0
	ands r2, r1
	orrs r2, r0
	str r2, [sp]
	mov r0, sp
	ldrh r1, [r0]
	ldr r0, _08040A14
	ands r0, r1
	adds r1, r3, 0
	ands r1, r2
	orrs r1, r0
	str r1, [sp]
	mov r0, sp
	ldrh r0, [r0]
	adds r2, r3, 0
	ands r2, r1
	orrs r2, r0
	str r2, [sp]
	mov r0, sp
	ldrh r1, [r0]
	ldr r0, _08040A18
	ands r0, r1
	adds r1, r3, 0
	ands r1, r2
	orrs r1, r0
	str r1, [sp]
	mov r0, sp
	ldrh r0, [r0]
	adds r2, r3, 0
	ands r2, r1
	orrs r2, r0
	str r2, [sp]
	mov r0, sp
	ldrh r1, [r0]
	ldr r4, _08040A1C
	adds r0, r4, 0
	ands r0, r1
	adds r1, r3, 0
	ands r1, r2
	orrs r1, r0
	str r1, [sp]
	mov r0, sp
	ldrh r0, [r0]
	ands r3, r1
	orrs r3, r0
	str r3, [sp]
	mov r3, sp
	ldrh r0, [r3, 0x2]
	ldr r6, _08040A20
	ands r6, r0
	ands r6, r4
	strh r6, [r3, 0x2]
	ldr r2, _08040A24
	ldrh r1, [r3, 0x4]
	movs r0, 0xFC
	lsls r0, 8
	ands r0, r1
	orrs r0, r2
	ands r0, r5
	movs r5, 0xF
	lsls r1, r5, 12
	ldr r4, _08040A28
	ands r0, r4
	orrs r0, r1
	strh r0, [r3, 0x4]
	ldrh r0, [r3, 0x6]
	ldr r2, _08040A2C
	ands r2, r0
	ldr r0, _08040A30
	ands r2, r0
	strh r2, [r3, 0x6]
	ldr r0, _08040A34
	ldr r0, [r0]
	ldrb r0, [r0, 0x4]
	cmp r0, 0x6
	bne _08040A3C
	movs r1, 0
	ldrsh r0, [r7, r1]
	lsls r0, 2
	adds r0, 0x10
	ldr r1, _08040A38
	ands r0, r1
	strh r0, [r3, 0x2]
	movs r1, 0x2
	ldrsh r0, [r7, r1]
	adds r0, 0x1
	lsls r0, 2
	ands r0, r4
	lsls r0, 4
	adds r1, r2, 0
	ands r1, r5
	orrs r1, r0
	strh r1, [r3, 0x6]
	movs r1, 0x80
	lsls r1, 1
	mov r0, sp
	movs r2, 0
	movs r3, 0
	bl nullsub_11
	b _08040A6A
	.align 2, 0
_080409F4: .4byte gDungeon
_080409F8: .4byte 0x00018214
_080409FC: .4byte gUnknown_203B410
_08040A00: .4byte gUnknown_202EE02
_08040A04: .4byte 0x0000feff
_08040A08: .4byte 0xffff0000
_08040A0C: .4byte 0x0000fdff
_08040A10: .4byte 0x0000f3ff
_08040A14: .4byte 0x0000efff
_08040A18: .4byte 0x0000dfff
_08040A1C: .4byte 0x00003fff
_08040A20: .4byte 0x0000c1ff
_08040A24: .4byte 0x00000215
_08040A28: .4byte 0x00000fff
_08040A2C: .4byte 0x0000fffe
_08040A30: .4byte 0x0000fffd
_08040A34: .4byte gGameOptionsRef
_08040A38: .4byte 0x000001ff
_08040A3C:
	movs r1, 0
	ldrsh r0, [r7, r1]
	lsls r0, 2
	adds r0, 0x8
	ldr r1, _08040A74
	ands r0, r1
	strh r0, [r3, 0x2]
	movs r1, 0x2
	ldrsh r0, [r7, r1]
	lsls r0, 2
	ands r0, r4
	lsls r0, 4
	adds r1, r2, 0
	ands r1, r5
	orrs r1, r0
	strh r1, [r3, 0x6]
	movs r1, 0x80
	lsls r1, 1
	mov r0, sp
	movs r2, 0
	movs r3, 0
	bl AddSprite
_08040A6A:
	add sp, 0x8
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_08040A74: .4byte 0x000001ff
	thumb_func_end sub_8040894

	thumb_func_start sub_8040A78
sub_8040A78:
	ldr r1, _08040A80
	movs r0, 0
	strb r0, [r1]
	bx lr
	.align 2, 0
_08040A80: .4byte gUnknown_202EE02
	thumb_func_end sub_8040A78

	thumb_func_start sub_8040A84
sub_8040A84:
	push {r4-r6,lr}
	ldr r0, _08040AB4
	ldr r0, [r0]
	ldr r1, _08040AB8
	adds r0, r1
	movs r1, 0x1
	strb r1, [r0]
	movs r5, 0
_08040A94:
	movs r4, 0
	adds r6, r5, 0x1
_08040A98:
	adds r0, r4, 0
	adds r1, r5, 0
	bl sub_80402AC
	adds r4, 0x1
	cmp r4, 0x37
	ble _08040A98
	adds r5, r6, 0
	cmp r5, 0x1F
	ble _08040A94
	pop {r4-r6}
	pop {r0}
	bx r0
	.align 2, 0
_08040AB4: .4byte gDungeon
_08040AB8: .4byte 0x0001bdd1
	thumb_func_end sub_8040A84

	thumb_func_start sub_8040ABC
sub_8040ABC:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	lsls r0, 24
	lsrs r1, r0, 24
	ldr r0, _08040AD8
	ldr r0, [r0]
	ldrb r0, [r0, 0x4]
	cmp r0, 0x6
	bne _08040ADC
	movs r7, 0xF
	movs r0, 0
	b _08040AEC
	.align 2, 0
_08040AD8: .4byte gGameOptionsRef
_08040ADC:
	cmp r1, 0
	beq _08040AE8
	movs r7, 0xE
	movs r4, 0
	mov r8, r4
	b _08040AEE
_08040AE8:
	movs r7, 0x10
	movs r0, 0x3
_08040AEC:
	mov r8, r0
_08040AEE:
	ldr r6, _08040B58
	movs r2, 0x1
	movs r1, 0
	cmp r1, r7
	bge _08040B22
	ldr r4, _08040B5C
	mov r12, r4
_08040AFC:
	lsls r0, r2, 6
	mov r4, r12
	adds r3, r0, r4
	adds r4, r2, 0x1
	adds r5, r1, 0x1
	movs r2, 0x1B
_08040B08:
	adds r1, r6, 0
	adds r0, r1, 0x1
	lsls r0, 16
	lsrs r6, r0, 16
	strh r1, [r3]
	adds r3, 0x2
	subs r2, 0x1
	cmp r2, 0
	bge _08040B08
	adds r2, r4, 0
	adds r1, r5, 0
	cmp r1, r7
	blt _08040AFC
_08040B22:
	movs r1, 0
	cmp r1, r8
	bge _08040B4C
	ldr r6, _08040B5C
	movs r0, 0xE0
	lsls r0, 8
	adds r3, r0, 0
_08040B30:
	lsls r0, r2, 6
	adds r0, r6
	adds r4, r2, 0x1
	adds r5, r1, 0x1
	movs r2, 0x1B
_08040B3A:
	strh r3, [r0]
	adds r0, 0x2
	subs r2, 0x1
	cmp r2, 0
	bge _08040B3A
	adds r2, r4, 0
	adds r1, r5, 0
	cmp r1, r8
	blt _08040B30
_08040B4C:
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_08040B58: .4byte 0x0000e0b8
_08040B5C: .4byte gUnknown_202B038 + 2
	thumb_func_end sub_8040ABC

	thumb_func_start sub_8040B60
sub_8040B60:
	push {r4,r5,lr}
	ldr r0, _08040BA4
	ldr r3, [r0]
	ldr r1, _08040BA8
	adds r0, r3, r1
	ldrb r0, [r0]
	cmp r0, 0
	beq _08040B9E
	movs r1, 0
	ldr r2, _08040BAC
	adds r5, r3, r2
	movs r4, 0
_08040B78:
	lsls r0, r1, 3
	adds r2, r1, 0x1
	subs r0, r1
	movs r1, 0x37
	lsls r0, 2
	adds r0, r5
	adds r0, 0x37
_08040B86:
	strb r4, [r0]
	subs r0, 0x1
	subs r1, 0x1
	cmp r1, 0
	bge _08040B86
	adds r1, r2, 0
	cmp r1, 0x1F
	ble _08040B78
	movs r1, 0
	ldr r2, _08040BA8
	adds r0, r3, r2
	strb r1, [r0]
_08040B9E:
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_08040BA4: .4byte gDungeon
_08040BA8: .4byte 0x0001bdd2
_08040BAC: .4byte 0x0001ba2c
	thumb_func_end sub_8040B60

	thumb_func_start sub_8040BB0
sub_8040BB0:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	adds r6, r0, 0
	adds r7, r1, 0
	lsls r2, 24
	lsrs r2, 24
	mov r10, r2
	bl sub_804143C
	mov r8, r0
	ldrh r4, [r7, 0x2]
	adds r0, r6, 0
	bl GetApparentWeather
	adds r1, r0, 0
	lsls r1, 24
	lsrs r1, 24
	adds r0, r4, 0
	mov r2, r8
	bl sub_804141C
	lsls r0, 24
	lsrs r5, r0, 24
	mov r9, r5
	ldrh r4, [r7, 0x2]
	adds r0, r6, 0
	bl GetApparentWeather
	adds r1, r0, 0
	lsls r1, 24
	lsrs r1, 24
	adds r0, r4, 0
	mov r2, r8
	bl sub_80412E0
	lsls r0, 16
	lsrs r0, 16
	bl sub_800ECB8
	movs r1, 0
	ldrsh r4, [r0, r1]
	adds r0, r6, 0
	bl sub_8042768
	lsls r0, 24
	cmp r0, 0
	beq _08040C28
	adds r0, r6, 0
	adds r1, r7, 0
	bl sub_80414C0
	lsls r0, 24
	cmp r0, 0
	bne _08040C28
	mov r0, r10
	cmp r0, 0
	bne _08040C2C
_08040C28:
	adds r0, r5, 0
	b _08040C3C
_08040C2C:
	cmp r4, 0
	beq _08040C3A
	adds r0, r6, 0
	adds r1, r7, 0
	mov r2, r8
	bl sub_8040C4C
_08040C3A:
	mov r0, r9
_08040C3C:
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_8040BB0

	thumb_func_start sub_8040C4C
sub_8040C4C:
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	sub sp, 0x14
	adds r7, r0, 0
	adds r4, r1, 0
	adds r6, r2, 0
	ldrh r5, [r4, 0x2]
	bl GetApparentWeather
	adds r1, r0, 0
	lsls r1, 24
	lsrs r1, 24
	adds r0, r5, 0
	adds r2, r6, 0
	bl sub_80412E0
	lsls r0, 16
	lsrs r0, 16
	mov r9, r0
	ldr r6, [r7, 0x70]
	ldrh r0, [r4, 0x2]
	bl sub_800EC94
	lsls r0, 24
	lsrs r0, 24
	mov r8, r0
	movs r0, 0x4
	ldrsh r5, [r6, r0]
	ldrh r4, [r4, 0x2]
	adds r0, r7, 0
	bl GetApparentWeather
	adds r1, r0, 0
	lsls r1, 24
	lsrs r1, 24
	adds r0, r4, 0
	movs r2, 0x1
	bl sub_80412E0
	adds r1, r0, 0
	lsls r1, 16
	lsrs r1, 16
	adds r0, r5, 0
	bl sub_800E710
	adds r2, r0, 0
	movs r0, 0x1
	negs r0, r0
	cmp r2, r0
	beq _08040CC4
	add r0, sp, 0x8
	adds r1, r7, 0
	adds r1, 0x28
	lsls r2, 24
	lsrs r2, 24
	bl sub_800569C
	b _08040CC8
_08040CC4:
	movs r0, 0
	str r0, [sp, 0x8]
_08040CC8:
	mov r0, sp
	mov r1, r9
	strh r1, [r0]
	mov r1, sp
	ldrh r0, [r6, 0x4]
	strh r0, [r1, 0x2]
	ldr r0, [r7, 0xC]
	cmp r0, 0
	bge _08040CDC
	adds r0, 0xFF
_08040CDC:
	asrs r0, 8
	strh r0, [r1, 0x4]
	mov r1, sp
	ldr r0, [r7, 0x10]
	cmp r0, 0
	bge _08040CEA
	adds r0, 0xFF
_08040CEA:
	asrs r0, 8
	strh r0, [r1, 0x6]
	adds r0, r6, 0
	adds r0, 0x46
	ldrb r0, [r0]
	str r0, [sp, 0xC]
	movs r0, 0
	str r0, [sp, 0x10]
	mov r0, sp
	bl sub_8041500
	mov r0, r9
	bl sub_800EEC8
	bl sub_800EF64
	movs r0, 0x58
	bl sub_803E46C
	mov r0, sp
	bl sub_800EA84
	adds r4, r0, 0
	adds r1, r7, 0
	movs r2, 0x5
	bl sub_8042DD4
	ldr r0, _08040D28
	ldrb r5, [r0]
	ldr r6, _08040D2C
	b _08040D78
	.align 2, 0
_08040D28: .4byte gUnknown_203B40D
_08040D2C: .4byte 0x00001010
_08040D30:
	ldr r0, _08040D58
	movs r1, 0x1
	strb r1, [r0]
	ldr r1, _08040D5C
	ldrh r2, [r1]
	movs r3, 0
	ldrsh r0, [r1, r3]
	cmp r0, r6
	beq _08040D48
	ldr r3, _08040D60
	adds r0, r2, r3
	strh r0, [r1]
_08040D48:
	ldr r1, _08040D64
	ldr r0, [r1]
	cmp r0, 0x4
	ble _08040D68
	subs r0, 0x4
	str r0, [r1]
	b _08040D6E
	.align 2, 0
_08040D58: .4byte gUnknown_203B40D
_08040D5C: .4byte gUnknown_2026E4E
_08040D60: .4byte 0x00000101
_08040D64: .4byte gDungeonBrightness
_08040D68:
	movs r0, 0
	str r0, [r1]
	mov r8, r0
_08040D6E:
	bl sub_803EA10
	movs r0, 0x26
	bl sub_803E46C
_08040D78:
	adds r0, r4, 0
	bl sub_800E9A8
	lsls r0, 24
	cmp r0, 0
	beq _08040D8A
	mov r0, r8
	cmp r0, 0
	bne _08040D30
_08040D8A:
	ldr r0, _08040D9C
	strb r5, [r0]
	add sp, 0x14
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_08040D9C: .4byte gUnknown_203B40D
	thumb_func_end sub_8040C4C

	thumb_func_start sub_8040DA0
sub_8040DA0:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x1C
	adds r7, r0, 0
	mov r8, r1
	bl sub_804143C
	mov r9, r0
	movs r0, 0
	str r0, [sp, 0x14]
	ldr r1, [r7, 0x70]
	mov r10, r1
	movs r0, 0x4
	ldrsh r5, [r1, r0]
	mov r1, r8
	ldrh r4, [r1, 0x2]
	adds r0, r7, 0
	bl GetApparentWeather
	adds r1, r0, 0
	lsls r1, 24
	lsrs r1, 24
	adds r0, r4, 0
	mov r2, r9
	bl sub_80412E0
	adds r1, r0, 0
	lsls r1, 16
	lsrs r1, 16
	adds r0, r5, 0
	bl sub_800EA44
	lsls r0, 24
	lsrs r0, 24
	str r0, [sp, 0x18]
	mov r0, sp
	adds r1, r7, 0
	mov r2, r8
	mov r3, r9
	bl sub_8041038
	mov r0, sp
	movs r1, 0x1
	bl sub_800E838
	lsls r0, 24
	cmp r0, 0
	bne _08040E0E
	mov r1, r8
	ldrh r0, [r1, 0x2]
	cmp r0, 0x52
	bne _08040E24
_08040E0E:
	ldr r0, _08040E1C
	ldr r0, [r0]
	ldr r1, _08040E20
	adds r0, r1
	ldr r6, [r0]
	b _08040E26
	.align 2, 0
_08040E1C: .4byte gDungeon
_08040E20: .4byte 0x000181f8
_08040E24:
	adds r6, r7, 0
_08040E26:
	adds r0, r6, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	bne _08040E34
	adds r6, r7, 0
_08040E34:
	mov r1, sp
	ldr r0, [r6, 0xC]
	cmp r0, 0
	bge _08040E3E
	adds r0, 0xFF
_08040E3E:
	asrs r0, 8
	strh r0, [r1, 0x4]
	mov r1, sp
	ldr r0, [r6, 0x10]
	cmp r0, 0
	bge _08040E4C
	adds r0, 0xFF
_08040E4C:
	asrs r0, 8
	strh r0, [r1, 0x6]
	adds r0, r6, 0
	bl sub_8042768
	lsls r0, 24
	cmp r0, 0
	bne _08040E5E
	b _08041026
_08040E5E:
	adds r0, r7, 0
	mov r1, r8
	bl sub_80414C0
	lsls r0, 24
	cmp r0, 0
	beq _08040E6E
	b _08041026
_08040E6E:
	mov r0, r8
	ldrh r1, [r0, 0x2]
	movs r0, 0x94
	lsls r0, 1
	cmp r1, r0
	bne _08040ED0
	movs r0, 0x7
	bl DungeonRandInt
	ldr r1, _08040EB8
	str r0, [r1]
	ldr r1, _08040EBC
	ldr r2, [r1]
	ldr r1, _08040EC0
	adds r4, r2, r1
	subs r1, 0x4
	adds r2, r1
	ldr r3, _08040EC4
	lsls r1, r0, 2
	adds r1, r3
	ldr r1, [r1]
	str r1, [r2]
	str r1, [r4]
	ldr r1, _08040EC8
	adds r0, 0x4
	str r0, [r1]
	ldr r0, _08040ECC
	ldr r1, [r0]
	adds r0, r6, 0
	bl TryDisplayDungeonLoggableMessage
	movs r1, 0xD2
	lsls r1, 1
	adds r0, r6, 0
	bl sub_80421C0
	b _08040EF0
	.align 2, 0
_08040EB8: .4byte gUnknown_202F224
_08040EBC: .4byte gDungeon
_08040EC0: .4byte 0x00018204
_08040EC4: .4byte gUnknown_8106A8C
_08040EC8: .4byte gFormatArgs
_08040ECC: .4byte gPtrMagnitudeMessage
_08040ED0:
	cmp r1, 0x76
	bne _08040EF0
	ldr r0, _08040F70
	ldr r0, [r0]
	ldr r1, _08040F74
	adds r2, r0, r1
	subs r1, 0x4
	adds r0, r1
	movs r1, 0xC
	str r1, [r0]
	str r1, [r2]
	movs r1, 0xD2
	lsls r1, 1
	adds r0, r6, 0
	bl sub_80421C0
_08040EF0:
	mov r0, r10
	movs r1, 0x4
	ldrsh r5, [r0, r1]
	mov r0, r8
	ldrh r4, [r0, 0x2]
	adds r0, r7, 0
	bl GetApparentWeather
	adds r1, r0, 0
	lsls r1, 24
	lsrs r1, 24
	adds r0, r4, 0
	mov r2, r9
	bl sub_80412E0
	adds r1, r0, 0
	lsls r1, 16
	lsrs r1, 16
	adds r0, r5, 0
	bl sub_800E790
	adds r1, r0, 0
	ldr r0, _08040F78
	cmp r1, r0
	beq _08040F2A
	lsls r0, r1, 16
	lsrs r0, 16
	bl PlaySoundEffect
_08040F2A:
	ldr r1, [sp, 0x18]
	cmp r1, 0x63
	bne _08040F7C
	adds r0, r6, 0
	bl sub_8042768
	lsls r0, 24
	cmp r0, 0
	beq _08041026
	mov r0, r10
	adds r0, 0x46
	ldrb r4, [r0]
	mov r0, sp
	adds r1, r7, 0
	mov r2, r8
	mov r3, r9
	bl sub_8041108
	movs r6, 0x7
	movs r5, 0x7
_08040F52:
	subs r4, 0x1
	ands r4, r6
	adds r0, r7, 0
	movs r1, 0
	adds r2, r4, 0
	bl sub_806CDD4
	movs r0, 0x2
	movs r1, 0x15
	bl sub_803E708
	subs r5, 0x1
	cmp r5, 0
	bge _08040F52
	b _08041026
	.align 2, 0
_08040F70: .4byte gDungeon
_08040F74: .4byte 0x00018204
_08040F78: .4byte 0x000003e5
_08040F7C:
	ldr r0, [sp, 0x18]
	cmp r0, 0x62
	bne _08040FC2
	adds r0, r6, 0
	bl sub_8042768
	lsls r0, 24
	cmp r0, 0
	beq _08041026
	mov r0, r10
	adds r0, 0x46
	ldrb r4, [r0]
	mov r0, sp
	adds r1, r7, 0
	mov r2, r8
	mov r3, r9
	bl sub_8041108
	movs r6, 0x7
	movs r5, 0x8
_08040FA4:
	ands r4, r6
	adds r0, r7, 0
	movs r1, 0
	adds r2, r4, 0
	bl sub_806CDD4
	movs r0, 0x2
	movs r1, 0x15
	bl sub_803E708
	adds r4, 0x1
	subs r5, 0x1
	cmp r5, 0
	bge _08040FA4
	b _08041026
_08040FC2:
	mov r0, r10
	adds r0, 0x46
	ldrb r2, [r0]
	adds r0, r7, 0
	ldr r1, [sp, 0x18]
	bl sub_806CDD4
	adds r0, r7, 0
	adds r0, 0x21
	movs r1, 0
	strb r1, [r0]
	movs r5, 0
	adds r6, r0, 0
	b _08040FE6
_08040FDE:
	ldrb r0, [r6]
	cmp r0, 0
	bne _08041022
	adds r5, 0x1
_08040FE6:
	cmp r5, 0x77
	bgt _08041022
	movs r0, 0x59
	bl sub_803E46C
	ldr r4, [r7, 0x40]
	ldr r1, [sp, 0x18]
	cmp r1, 0x9
	bne _08040FFC
	movs r0, 0x2
	orrs r4, r0
_08040FFC:
	movs r0, 0x2
	ands r0, r4
	cmp r0, 0
	beq _0804101A
	ldr r0, [sp, 0x14]
	cmp r0, 0
	bne _0804101A
	mov r0, sp
	adds r1, r7, 0
	mov r2, r8
	mov r3, r9
	bl sub_8041108
	movs r1, 0x1
	str r1, [sp, 0x14]
_0804101A:
	movs r0, 0x1
	ands r4, r0
	cmp r4, 0
	beq _08040FDE
_08041022:
	movs r0, 0
	strb r0, [r6]
_08041026:
	add sp, 0x1C
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_8040DA0

	thumb_func_start sub_8041038
sub_8041038:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x4
	adds r6, r0, 0
	adds r7, r1, 0
	mov r8, r2
	mov r10, r3
	ldr r0, [r7, 0x70]
	mov r9, r0
	ldrh r4, [r2, 0x2]
	adds r0, r7, 0
	bl GetApparentWeather
	adds r1, r0, 0
	lsls r1, 24
	lsrs r1, 24
	adds r0, r4, 0
	mov r2, r10
	bl sub_80412E0
	lsls r0, 16
	lsrs r0, 16
	str r0, [sp]
	bl sub_800ECB8
	movs r1, 0x2
	ldrsh r0, [r0, r1]
	cmp r0, 0
	beq _080410F4
	mov r0, r9
	movs r1, 0x4
	ldrsh r5, [r0, r1]
	mov r0, r8
	ldrh r4, [r0, 0x2]
	adds r0, r7, 0
	bl GetApparentWeather
	adds r1, r0, 0
	lsls r1, 24
	lsrs r1, 24
	adds r0, r4, 0
	mov r2, r10
	bl sub_80412E0
	adds r1, r0, 0
	lsls r1, 16
	lsrs r1, 16
	adds r0, r5, 0
	bl sub_800E710
	adds r2, r0, 0
	movs r0, 0x1
	negs r0, r0
	cmp r2, r0
	beq _080410BE
	adds r0, r6, 0
	adds r0, 0x8
	adds r1, r7, 0
	adds r1, 0x28
	lsls r2, 24
	lsrs r2, 24
	bl sub_800569C
	b _080410C2
_080410BE:
	movs r0, 0
	str r0, [r6, 0x8]
_080410C2:
	mov r1, sp
	ldrh r1, [r1]
	strh r1, [r6]
	mov r1, r9
	ldrh r0, [r1, 0x4]
	strh r0, [r6, 0x2]
	ldr r0, [r7, 0xC]
	cmp r0, 0
	bge _080410D6
	adds r0, 0xFF
_080410D6:
	asrs r0, 8
	strh r0, [r6, 0x4]
	ldr r0, [r7, 0x10]
	cmp r0, 0
	bge _080410E2
	adds r0, 0xFF
_080410E2:
	asrs r0, 8
	strh r0, [r6, 0x6]
	mov r0, r9
	adds r0, 0x46
	ldrb r0, [r0]
	str r0, [r6, 0xC]
	movs r0, 0
	str r0, [r6, 0x10]
	b _080410F6
_080410F4:
	strh r0, [r6]
_080410F6:
	add sp, 0x4
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_8041038

	thumb_func_start sub_8041108
sub_8041108:
	push {r4-r7,lr}
	adds r6, r0, 0
	adds r7, r1, 0
	adds r5, r3, 0
	ldrh r4, [r2, 0x2]
	adds r0, r7, 0
	bl GetApparentWeather
	adds r1, r0, 0
	lsls r1, 24
	lsrs r1, 24
	adds r0, r4, 0
	adds r2, r5, 0
	bl sub_80412E0
	lsls r0, 16
	lsrs r4, r0, 16
	adds r0, r4, 0
	bl sub_800ECB8
	movs r2, 0x2
	ldrsh r1, [r0, r2]
	ldrh r0, [r6]
	cmp r0, 0
	beq _08041162
	cmp r1, 0
	beq _08041162
	adds r0, r6, 0
	bl sub_8041500
	adds r0, r4, 0
	bl sub_800EEF8
	bl sub_800EF64
	movs r0, 0x5A
	bl sub_803E46C
	adds r0, r6, 0
	bl sub_800E52C
	adds r1, r7, 0
	movs r2, 0x1
	bl sub_8042DD4
_08041162:
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_8041108

	thumb_func_start sub_8041168
sub_8041168:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x18
	mov r8, r0
	adds r6, r1, 0
	adds r7, r2, 0
	mov r9, r3
	adds r1, r7, 0
	bl sub_804143C
	adds r5, r0, 0
	cmp r5, 0
	beq _0804118A
	movs r5, 0x1
_0804118A:
	ldrh r4, [r7, 0x2]
	mov r0, r8
	bl GetApparentWeather
	adds r1, r0, 0
	lsls r1, 24
	lsrs r1, 24
	adds r0, r4, 0
	adds r2, r5, 0
	bl sub_80412E0
	lsls r0, 16
	lsrs r0, 16
	mov r10, r0
	bl sub_800ECB8
	movs r1, 0x4
	ldrsh r5, [r0, r1]
	movs r2, 0
	str r2, [sp, 0x14]
	adds r0, r6, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	beq _080411CA
	ldr r0, [r6, 0x70]
	str r0, [sp, 0x14]
	adds r0, r6, 0
	bl sub_8042768
	b _080411D0
_080411CA:
	mov r0, r9
	bl sub_803F428
_080411D0:
	lsls r0, 24
	cmp r0, 0
	beq _080412CE
	mov r0, r8
	adds r1, r7, 0
	bl sub_80414C0
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0
	bne _080412CE
	cmp r5, 0
	beq _080412CE
	adds r0, r5, 0
	bl sub_800ECA4
	ldr r5, [r0, 0x1C]
	movs r0, 0x1
	negs r0, r0
	cmp r5, r0
	beq _08041216
	adds r0, r6, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	beq _08041216
	add r0, sp, 0x8
	adds r1, r6, 0
	adds r1, 0x28
	lsls r2, r5, 24
	lsrs r2, 24
	bl sub_800569C
	b _08041218
_08041216:
	str r4, [sp, 0x8]
_08041218:
	mov r0, sp
	mov r1, r10
	strh r1, [r0]
	ldr r2, [sp, 0x14]
	cmp r2, 0
	beq _08041248
	mov r1, sp
	ldrh r0, [r2, 0x4]
	strh r0, [r1, 0x2]
	ldr r0, [r6, 0xC]
	cmp r0, 0
	bge _08041232
	adds r0, 0xFF
_08041232:
	asrs r0, 8
	strh r0, [r1, 0x4]
	mov r1, sp
	ldr r0, [r6, 0x10]
	cmp r0, 0
	bge _08041240
	adds r0, 0xFF
_08041240:
	asrs r0, 8
	strh r0, [r1, 0x6]
	movs r0, 0
	b _0804128C
_08041248:
	mov r1, sp
	movs r0, 0x1
	strh r0, [r1, 0x2]
	mov r0, r9
	movs r2, 0
	ldrsh r1, [r0, r2]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 11
	mov r1, sp
	movs r2, 0xC0
	lsls r2, 4
	adds r0, r2
	cmp r0, 0
	bge _08041268
	adds r0, 0xFF
_08041268:
	asrs r0, 8
	strh r0, [r1, 0x4]
	mov r0, r9
	movs r2, 0x2
	ldrsh r1, [r0, r2]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 11
	mov r1, sp
	movs r2, 0x80
	lsls r2, 5
	adds r0, r2
	cmp r0, 0
	bge _08041286
	adds r0, 0xFF
_08041286:
	asrs r0, 8
	strh r0, [r1, 0x6]
	ldr r0, [sp, 0x14]
_0804128C:
	str r0, [sp, 0xC]
	movs r0, 0
	str r0, [sp, 0x10]
	mov r0, sp
	bl sub_8041500
	mov r0, r10
	bl sub_800EEE0
	bl sub_800EF64
	mov r0, sp
	bl sub_800EBC8
	adds r4, r0, 0
	movs r0, 0x5B
	bl sub_803E46C
	adds r0, r4, 0
	adds r1, r6, 0
	movs r2, 0x6
	bl sub_8042DD4
	b _080412C2
_080412BC:
	movs r0, 0x28
	bl sub_803E46C
_080412C2:
	adds r0, r4, 0
	bl sub_800E9A8
	lsls r0, 24
	cmp r0, 0
	bne _080412BC
_080412CE:
	add sp, 0x18
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_8041168

	thumb_func_start sub_80412E0
sub_80412E0:
	push {r4,lr}
	lsls r0, 16
	lsrs r4, r0, 16
	lsls r1, 24
	lsrs r0, r1, 24
	adds r3, r4, 0
	cmp r3, 0x1F
	bne _08041344
	cmp r0, 0x7
	bls _080412F6
	b _080413F6
_080412F6:
	lsls r0, 2
	ldr r1, _08041300
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08041300: .4byte _08041304
	.align 2, 0
_08041304:
	.4byte _080413F4
	.4byte _08041324
	.4byte _0804132A
	.4byte _080413F4
	.4byte _08041334
	.4byte _0804133A
	.4byte _080413F4
	.4byte _0804133A
_08041324:
	movs r3, 0xCF
	lsls r3, 1
	b _080413F6
_0804132A:
	ldr r3, _08041330
	b _080413F6
	.align 2, 0
_08041330: .4byte 0x000001a1
_08041334:
	movs r3, 0xD0
	lsls r3, 1
	b _080413F6
_0804133A:
	ldr r3, _08041340
	b _080413F6
	.align 2, 0
_08041340: .4byte 0x0000019f
_08041344:
	cmp r2, 0
	beq _080413F6
	cmp r3, 0x97
	beq _080413B4
	cmp r3, 0x97
	bgt _0804136C
	cmp r3, 0x3C
	beq _0804139C
	cmp r3, 0x3C
	bgt _08041362
	cmp r3, 0x8
	beq _08041396
	cmp r3, 0x19
	beq _080413E4
	b _080413F4
_08041362:
	cmp r3, 0x4B
	beq _080413A4
	cmp r3, 0x64
	beq _080413AA
	b _080413F4
_0804136C:
	cmp r3, 0xCD
	beq _080413CA
	cmp r3, 0xCD
	bgt _0804137E
	cmp r3, 0x99
	beq _080413BA
	cmp r3, 0x9C
	beq _080413C4
	b _080413F4
_0804137E:
	cmp r3, 0xED
	beq _080413DA
	cmp r3, 0xED
	bgt _0804138C
	cmp r3, 0xE3
	beq _080413EA
	b _080413F4
_0804138C:
	movs r0, 0xAE
	lsls r0, 1
	cmp r3, r0
	beq _080413D4
	b _080413F4
_08041396:
	movs r3, 0xD1
	lsls r3, 1
	b _080413F6
_0804139C:
	ldr r3, _080413A0
	b _080413F6
	.align 2, 0
_080413A0: .4byte 0x000001a3
_080413A4:
	movs r3, 0xD2
	lsls r3, 1
	b _080413F6
_080413AA:
	ldr r3, _080413B0
	b _080413F6
	.align 2, 0
_080413B0: .4byte 0x000001a5
_080413B4:
	movs r3, 0xD3
	lsls r3, 1
	b _080413F6
_080413BA:
	ldr r3, _080413C0
	b _080413F6
	.align 2, 0
_080413C0: .4byte 0x000001a7
_080413C4:
	movs r3, 0xD4
	lsls r3, 1
	b _080413F6
_080413CA:
	ldr r3, _080413D0
	b _080413F6
	.align 2, 0
_080413D0: .4byte 0x000001a9
_080413D4:
	movs r3, 0xD5
	lsls r3, 1
	b _080413F6
_080413DA:
	ldr r3, _080413E0
	b _080413F6
	.align 2, 0
_080413E0: .4byte 0x000001ab
_080413E4:
	movs r3, 0xD6
	lsls r3, 1
	b _080413F6
_080413EA:
	ldr r3, _080413F0
	b _080413F6
	.align 2, 0
_080413F0: .4byte 0x000001ad
_080413F4:
	adds r3, r4, 0
_080413F6:
	adds r0, r3, 0
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_80412E0

	thumb_func_start sub_8041400
sub_8041400:
	push {lr}
	lsls r0, 16
	lsrs r0, 16
	lsls r1, 24
	lsrs r1, 24
	bl sub_80412E0
	lsls r0, 16
	lsrs r0, 16
	bl sub_800ED20
	pop {r1}
	bx r1
	thumb_func_end sub_8041400

	thumb_func_start sub_804141C
sub_804141C:
	push {lr}
	lsls r0, 16
	lsrs r0, 16
	lsls r1, 24
	lsrs r1, 24
	bl sub_80412E0
	lsls r0, 16
	lsrs r0, 16
	bl sub_800EC84
	lsls r0, 24
	lsrs r0, 24
	pop {r1}
	bx r1
	thumb_func_end sub_804141C

	thumb_func_start sub_804143C
sub_804143C:
	push {r4,r5,lr}
	adds r4, r0, 0
	adds r5, r1, 0
	ldrh r0, [r5, 0x2]
	cmp r0, 0xED
	bne _08041476
	adds r0, r4, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	beq _080414A4
	adds r0, r4, 0
	bl GetEntityType
	cmp r0, 0x1
	bne _080414A4
	ldr r1, [r4, 0x70]
	adds r0, r1, 0
	adds r0, 0x5C
	ldrb r0, [r0]
	cmp r0, 0xE
	beq _080414A0
	adds r0, r1, 0
	adds r0, 0x5D
	ldrb r0, [r0]
	cmp r0, 0xE
	beq _080414A0
	b _0804148A
_08041476:
	cmp r0, 0x19
	beq _0804147E
	cmp r0, 0xE3
	bne _0804148E
_0804147E:
	adds r0, r4, 0
	bl IsSleeping
	lsls r0, 24
	cmp r0, 0
	beq _080414A0
_0804148A:
	movs r0, 0
	b _080414B8
_0804148E:
	cmp r0, 0x97
	bne _080414A4
	adds r0, r4, 0
	bl GetApparentWeather
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _080414A4
_080414A0:
	movs r0, 0x1
	b _080414B8
_080414A4:
	adds r0, r4, 0
	adds r1, r5, 0
	bl MoveMatchesChargingStatus
	adds r1, r0, 0
	lsls r1, 24
	lsrs r1, 24
	negs r0, r1
	orrs r0, r1
	lsrs r0, 31
_080414B8:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_804143C

	thumb_func_start sub_80414C0
sub_80414C0:
	push {r4,r5,lr}
	adds r5, r0, 0
	adds r4, r1, 0
	ldrh r0, [r4, 0x2]
	cmp r0, 0x9C
	bne _080414DC
	adds r0, r5, 0
	bl GetTileAtEntitySafe
	bl IsTileGround
	lsls r0, 24
	cmp r0, 0
	bne _080414F2
_080414DC:
	ldrh r0, [r4, 0x2]
	cmp r0, 0x8
	bne _080414F6
	adds r0, r5, 0
	bl GetTileAtEntitySafe
	ldrh r1, [r0]
	movs r0, 0x3
	ands r0, r1
	cmp r0, 0x1
	beq _080414F6
_080414F2:
	movs r0, 0x1
	b _080414F8
_080414F6:
	movs r0, 0
_080414F8:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_80414C0

	thumb_func_start sub_8041500
sub_8041500:
	push {lr}
	bl sub_800E7D0
	lsls r0, 24
	cmp r0, 0
	beq _08041518
	movs r0, 0x5C
	bl sub_803E46C
	movs r0, 0x5D
	bl sub_8052740
_08041518:
	pop {r0}
	bx r0
	thumb_func_end sub_8041500

	thumb_func_start sub_804151C
sub_804151C:
	push {r4-r6,lr}
	sub sp, 0x8
	adds r6, r0, 0
	adds r5, r1, 0
	lsls r4, r2, 24
	lsrs r4, 24
	adds r0, r5, 0
	bl sub_800DC9C
	adds r3, r0, 0
	lsls r3, 24
	lsrs r3, 24
	movs r0, 0x2
	str r0, [sp]
	movs r0, 0
	str r0, [sp, 0x4]
	adds r0, r6, 0
	adds r1, r5, 0
	adds r2, r4, 0
	bl sub_8041550
	add sp, 0x8
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end sub_804151C

	thumb_func_start sub_8041550
sub_8041550:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x30
	adds r7, r0, 0
	mov r10, r1
	ldr r0, [sp, 0x54]
	lsls r2, 24
	lsrs r2, 24
	str r2, [sp, 0x2C]
	lsls r3, 24
	lsrs r3, 24
	mov r9, r3
	lsls r0, 24
	lsrs r6, r0, 24
	adds r0, r7, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	beq _0804159C
	ldr r0, [r7, 0x70]
	mov r8, r0
	adds r0, r7, 0
	bl sub_8042768
	lsls r0, 24
	cmp r0, 0
	beq _0804159C
	cmp r6, 0
	bne _080415A2
	mov r0, r8
	adds r0, 0xFF
	ldrb r0, [r0]
	cmp r0, 0x2
	bne _080415A2
_0804159C:
	movs r0, 0x1
	negs r0, r0
	b _08041692
_080415A2:
	ldr r1, [sp, 0x50]
	cmp r1, 0
	beq _080415B4
	movs r0, 0
	cmp r1, 0x2
	bne _080415B0
	movs r0, 0x1
_080415B0:
	bl sub_804178C
_080415B4:
	add r6, sp, 0x28
	adds r1, r7, 0
	adds r1, 0x28
	adds r0, r6, 0
	mov r2, r9
	bl sub_800569C
	movs r2, 0
	ldrsh r0, [r6, r2]
	cmp r0, 0x63
	beq _080415F2
	ldrh r0, [r6, 0x2]
	cmp r0, 0x63
	beq _080415F2
	movs r1, 0
	ldrsh r0, [r6, r1]
	lsls r0, 8
	ldr r1, [r7, 0xC]
	adds r4, r1, r0
	movs r2, 0x2
	ldrsh r0, [r6, r2]
	lsls r0, 8
	ldr r2, [r7, 0x10]
	adds r0, r2, r0
	movs r1, 0xBA
	lsls r1, 1
	add r1, r8
	ldr r1, [r1]
	subs r5, r0, r1
	adds r1, r2, 0
	b _08041600
_080415F2:
	ldr r4, [r7, 0xC]
	movs r0, 0xBA
	lsls r0, 1
	add r0, r8
	ldr r1, [r7, 0x10]
	ldr r0, [r0]
	subs r5, r1, r0
_08041600:
	cmp r1, 0
	bge _08041606
	adds r1, 0xFF
_08041606:
	asrs r1, 8
	ldr r0, _0804166C
	ldr r0, [r0]
	ldr r2, _08041670
	adds r0, r2
	movs r2, 0
	ldrsh r0, [r0, r2]
	subs r1, r0
	lsrs r0, r1, 31
	adds r0, r1, r0
	asrs r1, r0, 1
	adds r1, 0x1
	mov r0, r10
	str r0, [sp]
	movs r3, 0
	str r3, [sp, 0x4]
	movs r6, 0x1
	negs r6, r6
	str r6, [sp, 0x8]
	mov r2, sp
	adds r0, r4, 0
	cmp r4, 0
	bge _08041636
	adds r0, 0xFF
_08041636:
	asrs r0, 8
	strh r0, [r2, 0xC]
	mov r2, sp
	adds r0, r5, 0
	cmp r0, 0
	bge _08041644
	adds r0, 0xFF
_08041644:
	asrs r0, 8
	strh r0, [r2, 0xE]
	str r6, [sp, 0x14]
	mov r0, sp
	strh r3, [r0, 0x10]
	strh r3, [r0, 0x12]
	str r1, [sp, 0x18]
	add r0, sp, 0x1C
	bl sub_8004E8C
	mov r0, sp
	movs r1, 0
	bl sub_8041764
	adds r4, r0, 0
	ldr r1, [sp, 0x2C]
	cmp r1, 0
	beq _08041690
	movs r5, 0
	b _0804167C
	.align 2, 0
_0804166C: .4byte gDungeon
_08041670: .4byte 0x000181f2
_08041674:
	movs r0, 0x42
	bl sub_803E46C
	adds r5, 0x1
_0804167C:
	cmp r5, 0x63
	bgt _0804168C
	adds r0, r4, 0
	bl sub_800E9A8
	lsls r0, 24
	cmp r0, 0
	bne _08041674
_0804168C:
	movs r4, 0x1
	negs r4, r4
_08041690:
	adds r0, r4, 0
_08041692:
	add sp, 0x30
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_8041550

        .align 2,0
