	#include "asm/constants/gba_constants.inc"
  	#include "asm/macros.inc"

  	.syntax unified

  	.text


	thumb_func_start sub_8051288
sub_8051288:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0xC
	str r0, [sp, 0x4]
	ldr r0, _08051374
	ldr r7, [r0]
	ldr r0, _08051378
	adds r3, r7, r0
	ldr r0, [r3]
	ldr r0, [r0, 0x4]
	ldr r2, [sp, 0x4]
	lsls r1, r2, 2
	adds r0, r1, r0
	ldr r0, [r0]
	ldrb r2, [r0]
	mov r10, r2
	ldrb r0, [r0, 0x1]
	mov r9, r0
	ldr r2, _0805137C
	adds r0, r7, r2
	movs r4, 0
	mov r2, r10
	strh r2, [r0]
	ldr r2, _08051380
	adds r0, r7, r2
	mov r2, r9
	strh r2, [r0]
	ldr r2, _08051384
	ldr r0, [r3]
	ldr r0, [r0, 0x4]
	adds r1, r0
	ldr r0, [r1]
	adds r0, 0x3
	str r0, [r2]
	ldr r0, _08051388
	strb r4, [r0]
	movs r6, 0x5
	mov r0, r9
	adds r0, 0x5
	cmp r6, r0
	bge _0805132E
	movs r1, 0x5
	add r1, r10
	mov r8, r1
	str r0, [sp, 0x8]
_080512E8:
	movs r5, 0x5
	cmp r5, r8
	bge _08051326
_080512EE:
	bl sub_80511F0
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	adds r0, r5, 0
	adds r1, r6, 0
	bl GetTileSafe
	movs r1, 0x1
	str r1, [sp]
	adds r1, r4, 0
	adds r2, r5, 0
	adds r3, r6, 0
	bl sub_805124C
	lsls r0, 24
	cmp r0, 0
	beq _08051320
	ldr r2, _0805138C
	adds r0, r7, r2
	strh r5, [r0]
	ldr r1, _08051390
	adds r0, r7, r1
	strh r6, [r0]
_08051320:
	adds r5, 0x1
	cmp r5, r8
	blt _080512EE
_08051326:
	adds r6, 0x1
	ldr r2, [sp, 0x8]
	cmp r6, r2
	blt _080512E8
_0805132E:
	movs r6, 0
	ldr r0, _08051394
	adds r7, r0, 0
_08051334:
	movs r5, 0
	adds r4, r6, 0x1
_08051338:
	cmp r5, 0x4
	ble _08051350
	mov r0, r10
	adds r0, 0x5
	cmp r5, r0
	bge _08051350
	cmp r6, 0x4
	ble _08051350
	mov r0, r9
	adds r0, 0x5
	cmp r6, r0
	blt _080513A0
_08051350:
	adds r0, r5, 0
	adds r1, r6, 0
	bl GetTileSafe
	adds r2, r0, 0
	ldrh r1, [r2]
	movs r0, 0x10
	movs r3, 0
	orrs r1, r0
	strh r1, [r2]
	ldr r0, _08051398
	ldrb r0, [r0]
	cmp r0, 0
	beq _0805139C
	ands r1, r7
	movs r0, 0x3
	orrs r1, r0
	b _0805139E
	.align 2, 0
_08051374: .4byte gDungeon
_08051378: .4byte 0x00013568
_0805137C: .4byte 0x0000e260
_08051380: .4byte 0x0000e262
_08051384: .4byte gUnknown_202F1DC
_08051388: .4byte gUnknown_202F1E1
_0805138C: .4byte 0x0000e21c
_08051390: .4byte 0x0000e21e
_08051394: .4byte 0x0000fffc
_08051398: .4byte gUnknown_202F1A8
_0805139C:
	ands r1, r7
_0805139E:
	strh r1, [r2]
_080513A0:
	adds r5, 0x1
	cmp r5, 0x37
	ble _08051338
	adds r6, r4, 0
	cmp r6, 0x1F
	ble _08051334
	ldr r1, [sp, 0x4]
	cmp r1, 0x4
	bne _080513DA
	movs r6, 0x5
	ldr r2, _0805142C
	adds r7, r2, 0
_080513B8:
	movs r5, 0x2
	adds r4, r6, 0x1
_080513BC:
	adds r0, r5, 0
	adds r1, r6, 0
	bl GetTileSafe
	ldrh r2, [r0]
	movs r1, 0x10
	orrs r1, r2
	ands r1, r7
	strh r1, [r0]
	adds r5, 0x1
	cmp r5, 0x4
	ble _080513BC
	adds r6, r4, 0
	cmp r6, 0x10
	ble _080513B8
_080513DA:
	ldr r0, _08051430
	ldr r0, [r0]
	ldr r1, _08051434
	adds r0, r1
	movs r2, 0
	ldrsh r0, [r0, r2]
	cmp r0, 0x3F
	ble _08051416
	movs r6, 0
_080513EC:
	movs r5, 0
	adds r4, r6, 0x1
_080513F0:
	adds r0, r5, 0
	adds r1, r6, 0
	bl GetTileSafe
	adds r2, r0, 0
	ldrh r1, [r2]
	movs r0, 0x3
	ands r0, r1
	cmp r0, 0
	bne _0805140A
	movs r0, 0x10
	orrs r0, r1
	strh r0, [r2]
_0805140A:
	adds r5, 0x1
	cmp r5, 0x37
	ble _080513F0
	adds r6, r4, 0
	cmp r6, 0x1F
	ble _080513EC
_08051416:
	bl sub_804E9DC
	add sp, 0xC
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_0805142C: .4byte 0x0000fffc
_08051430: .4byte gDungeon
_08051434: .4byte 0x00003a0e
	thumb_func_end sub_8051288

	thumb_func_start sub_8051438
sub_8051438:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x1C
	mov r9, r0
	ldr r0, _080515AC
	ldr r0, [r0]
	str r0, [sp, 0x4]
	ldr r2, _080515B0
	ldr r4, _080515B4
	adds r3, r0, r4
	ldr r0, [r3]
	ldr r0, [r0, 0x4]
	lsls r1, 2
	adds r0, r1, r0
	ldr r0, [r0]
	adds r0, 0x3
	str r0, [r2]
	ldr r2, _080515B8
	movs r0, 0
	strb r0, [r2]
	ldr r0, [r3]
	ldr r0, [r0, 0x4]
	adds r1, r0
	ldr r0, [r1]
	ldrb r1, [r0, 0x2]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	bne _0805147A
	b _080515D8
_0805147A:
	ldr r5, [sp, 0x4]
	ldr r0, _080515BC
	adds r1, r5, r0
	mov r2, r9
	movs r3, 0
	ldrsh r0, [r2, r3]
	str r0, [r1]
	ldr r4, _080515C0
	adds r1, r5, r4
	movs r5, 0x2
	ldrsh r0, [r2, r5]
	str r0, [r1]
	ldr r0, [sp, 0x4]
	ldr r2, _080515C4
	adds r1, r0, r2
	mov r3, r9
	movs r4, 0x4
	ldrsh r0, [r3, r4]
	str r0, [r1]
	ldr r5, [sp, 0x4]
	ldr r0, _080515C8
	adds r1, r5, r0
	movs r2, 0x6
	ldrsh r0, [r3, r2]
	str r0, [r1]
	movs r3, 0
	str r3, [sp, 0x8]
	mov r4, r9
	movs r5, 0x2
	ldrsh r4, [r4, r5]
	mov r8, r4
	mov r1, r9
	movs r2, 0x6
	ldrsh r0, [r1, r2]
	cmp r8, r0
	blt _080514C4
	b _08051640
_080514C4:
	mov r3, r9
	movs r4, 0
	ldrsh r7, [r3, r4]
	movs r5, 0x4
	ldrsh r0, [r3, r5]
	ldr r1, [sp, 0x8]
	adds r1, 0x1
	str r1, [sp, 0x10]
	mov r2, r8
	adds r2, 0x1
	str r2, [sp, 0xC]
	cmp r7, r0
	bge _08051598
	ldr r4, _080515CC
	ldr r3, [sp, 0x4]
	adds r4, r3, r4
	str r4, [sp, 0x14]
	movs r5, 0
	str r5, [sp, 0x18]
	ldr r0, [sp, 0x8]
	mov r10, r0
_080514EE:
	bl sub_80511F0
	adds r5, r0, 0
	lsls r5, 24
	lsrs r5, 24
	adds r0, r7, 0
	mov r1, r8
	bl GetTileSafe
	adds r6, r0, 0
	ldr r1, [sp, 0x4]
	ldr r2, _080515D0
	adds r0, r1, r2
	add r0, r10
	strb r5, [r0]
	ldr r3, [sp, 0x8]
	lsls r4, r3, 1
	adds r4, r3
	lsls r4, 3
	ldr r1, [sp, 0x14]
	adds r0, r1, r4
	movs r2, 0
	str r2, [sp]
	adds r1, r5, 0
	adds r2, r7, 0
	mov r3, r8
	bl sub_805124C
	ldrb r1, [r6, 0x9]
	ldr r3, [sp, 0x18]
	adds r4, r3
	ldr r5, [sp, 0x4]
	adds r4, r5, r4
	adds r0, r6, 0
	ldr r2, _080515CC
	adds r4, r2
	ldm r4!, {r2,r3,r5}
	stm r0!, {r2,r3,r5}
	ldm r4!, {r2,r3,r5}
	stm r0!, {r2,r3,r5}
	mov r3, r9
	movs r4, 0
	ldrsh r0, [r3, r4]
	adds r0, 0x2
	cmp r7, r0
	blt _08051572
	movs r5, 0x4
	ldrsh r0, [r3, r5]
	subs r0, 0x2
	cmp r7, r0
	bge _08051572
	movs r2, 0x2
	ldrsh r0, [r3, r2]
	adds r0, 0x2
	cmp r8, r0
	blt _08051572
	movs r4, 0x6
	ldrsh r0, [r3, r4]
	subs r0, 0x2
	cmp r8, r0
	bge _08051572
	movs r0, 0x88
	lsls r0, 1
	strh r0, [r6]
	movs r0, 0xE
	strb r0, [r6, 0xE]
_08051572:
	strb r1, [r6, 0x9]
	ldr r5, [sp, 0x4]
	ldr r2, _080515D4
	adds r0, r5, r2
	strb r1, [r0]
	ldr r3, [sp, 0x14]
	adds r3, 0xC0
	str r3, [sp, 0x14]
	ldr r4, [sp, 0x18]
	adds r4, 0xC0
	str r4, [sp, 0x18]
	movs r5, 0x8
	add r10, r5
	adds r7, 0x1
	mov r1, r9
	movs r2, 0x4
	ldrsh r0, [r1, r2]
	cmp r7, r0
	blt _080514EE
_08051598:
	ldr r3, [sp, 0x10]
	str r3, [sp, 0x8]
	ldr r4, [sp, 0xC]
	mov r8, r4
	mov r5, r9
	movs r1, 0x6
	ldrsh r0, [r5, r1]
	cmp r8, r0
	blt _080514C4
	b _08051640
	.align 2, 0
_080515AC: .4byte gDungeon
_080515B0: .4byte gUnknown_202F1DC
_080515B4: .4byte 0x00013568
_080515B8: .4byte gUnknown_202F1E1
_080515BC: .4byte 0x0000e250
_080515C0: .4byte 0x0000e254
_080515C4: .4byte 0x0000e258
_080515C8: .4byte 0x0000e25c
_080515CC: .4byte 0x0000e27c
_080515D0: .4byte 0x0000e87c
_080515D4: .4byte 0x0000e8bc
_080515D8:
	mov r2, r9
	movs r3, 0x2
	ldrsh r2, [r2, r3]
	mov r8, r2
	b _08051636
_080515E2:
	mov r0, r9
	movs r1, 0
	ldrsh r7, [r0, r1]
	movs r2, 0x4
	ldrsh r0, [r0, r2]
	mov r3, r8
	adds r3, 0x1
	str r3, [sp, 0xC]
	cmp r7, r0
	bge _08051632
_080515F6:
	bl sub_80511F0
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	adds r0, r7, 0
	mov r1, r8
	bl GetTileSafe
	adds r5, r0, 0
	ldrb r6, [r5, 0x9]
	movs r0, 0x1
	str r0, [sp]
	adds r0, r5, 0
	adds r1, r4, 0
	adds r2, r7, 0
	mov r3, r8
	bl sub_805124C
	strb r6, [r5, 0x9]
	ldr r4, [sp, 0x4]
	ldr r5, _08051650
	adds r0, r4, r5
	strb r6, [r0]
	adds r7, 0x1
	mov r1, r9
	movs r2, 0x4
	ldrsh r0, [r1, r2]
	cmp r7, r0
	blt _080515F6
_08051632:
	ldr r3, [sp, 0xC]
	mov r8, r3
_08051636:
	mov r4, r9
	movs r5, 0x6
	ldrsh r0, [r4, r5]
	cmp r8, r0
	blt _080515E2
_08051640:
	add sp, 0x1C
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_08051650: .4byte 0x0000e8bc
	thumb_func_end sub_8051438

	thumb_func_start sub_8051654
sub_8051654:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x14
	str r0, [sp]
	ldr r4, _080516EC
	ldr r1, [r4, 0x8]
	ldr r0, [r4]
	subs r1, r0
	subs r1, 0x2
	movs r0, 0x3
	bl DungeonRandRange
	mov r8, r0
	cmp r0, 0x2
	bgt _0805167C
	movs r0, 0x3
	mov r8, r0
_0805167C:
	ldr r1, [r4, 0xC]
	ldr r0, [r4, 0x4]
	subs r1, r0
	subs r1, 0x2
	movs r0, 0x3
	bl DungeonRandRange
	mov r9, r0
	cmp r0, 0x2
	bgt _08051694
	movs r1, 0x3
	mov r9, r1
_08051694:
	movs r0, 0x2
	movs r1, 0x4
	bl DungeonRandRange
	mov r10, r0
	movs r5, 0
	cmp r5, r10
	bge _08051734
	ldr r0, [r4, 0x8]
	ldr r1, [r4]
	subs r0, r1
	cmp r0, r8
	ble _08051734
	adds r6, r4, 0
_080516B0:
	movs r0, 0x64
	bl DungeonRandInt
	cmp r0, 0x31
	bgt _080516F4
	ldr r4, [r6, 0x4]
	ldr r0, [r6, 0xC]
	adds r7, r5, 0x1
	cmp r4, r0
	bge _080516E4
	ldr r5, _080516EC
	ldr r0, _080516F0
	adds r2, r0, 0
_080516CA:
	ldr r0, [r5]
	adds r1, r4, 0
	str r2, [sp, 0xC]
	bl GetTileSafe
	ldrh r1, [r0]
	ldr r2, [sp, 0xC]
	ands r1, r2
	strh r1, [r0]
	adds r4, 0x1
	ldr r0, [r5, 0xC]
	cmp r4, r0
	blt _080516CA
_080516E4:
	ldr r0, [r6]
	adds r0, 0x1
	str r0, [r6]
	b _08051724
	.align 2, 0
_080516EC: .4byte sKecleonShopPosition
_080516F0: .4byte 0x0000ffdf
_080516F4:
	ldr r0, [r6, 0x8]
	subs r0, 0x1
	str r0, [r6, 0x8]
	ldr r4, [r6, 0x4]
	ldr r0, [r6, 0xC]
	adds r7, r5, 0x1
	cmp r4, r0
	bge _08051724
	ldr r5, _08051784
	ldr r1, _08051788
	adds r2, r1, 0
_0805170A:
	ldr r0, [r5, 0x8]
	adds r1, r4, 0
	str r2, [sp, 0xC]
	bl GetTileSafe
	ldrh r1, [r0]
	ldr r2, [sp, 0xC]
	ands r1, r2
	strh r1, [r0]
	adds r4, 0x1
	ldr r0, [r5, 0xC]
	cmp r4, r0
	blt _0805170A
_08051724:
	adds r5, r7, 0
	cmp r5, r10
	bge _08051734
	ldr r0, [r6, 0x8]
	ldr r1, [r6]
	subs r0, r1
	cmp r0, r8
	bgt _080516B0
_08051734:
	movs r5, 0
	ldr r3, _08051784
	cmp r5, r10
	bge _080517CE
	ldr r0, [r3, 0xC]
	ldr r1, [r3, 0x4]
	subs r0, r1
	cmp r0, r9
	ble _080517CE
	adds r6, r3, 0
_08051748:
	movs r0, 0x64
	bl DungeonRandInt
	cmp r0, 0x31
	bgt _0805178C
	ldr r4, [r6]
	ldr r0, [r6, 0x8]
	adds r7, r5, 0x1
	cmp r4, r0
	bge _0805177C
	ldr r5, _08051784
	ldr r0, _08051788
	adds r2, r0, 0
_08051762:
	ldr r1, [r5, 0x4]
	adds r0, r4, 0
	str r2, [sp, 0xC]
	bl GetTileSafe
	ldrh r1, [r0]
	ldr r2, [sp, 0xC]
	ands r1, r2
	strh r1, [r0]
	adds r4, 0x1
	ldr r0, [r5, 0x8]
	cmp r4, r0
	blt _08051762
_0805177C:
	ldr r0, [r6, 0x4]
	adds r0, 0x1
	str r0, [r6, 0x4]
	b _080517BC
	.align 2, 0
_08051784: .4byte sKecleonShopPosition
_08051788: .4byte 0x0000ffdf
_0805178C:
	ldr r0, [r6, 0xC]
	subs r0, 0x1
	str r0, [r6, 0xC]
	ldr r4, [r6]
	ldr r0, [r6, 0x8]
	adds r7, r5, 0x1
	cmp r4, r0
	bge _080517BC
	ldr r5, _080518E4
	ldr r1, _080518E8
	adds r2, r1, 0
_080517A2:
	ldr r1, [r5, 0xC]
	adds r0, r4, 0
	str r2, [sp, 0xC]
	bl GetTileSafe
	ldrh r1, [r0]
	ldr r2, [sp, 0xC]
	ands r1, r2
	strh r1, [r0]
	adds r4, 0x1
	ldr r0, [r5, 0x8]
	cmp r4, r0
	blt _080517A2
_080517BC:
	adds r5, r7, 0
	ldr r3, _080518E4
	cmp r5, r10
	bge _080517CE
	ldr r1, [r6, 0xC]
	ldr r0, [r6, 0x4]
	subs r1, r0
	cmp r1, r9
	bgt _08051748
_080517CE:
	ldr r7, [r3]
	ldr r0, [r3, 0x8]
	cmp r7, r0
	bge _08051824
	adds r4, r3, 0
	mov r9, r3
_080517DA:
	ldr r5, [r4, 0x4]
	ldr r0, [r4, 0xC]
	adds r1, r7, 0x1
	mov r8, r1
	cmp r5, r0
	bge _0805181A
	ldr r3, _080518E4
	ldr r0, _080518E8
	adds r6, r0, 0
_080517EC:
	adds r0, r7, 0
	adds r1, r5, 0
	str r3, [sp, 0x10]
	bl GetTileSafe
	adds r2, r0, 0
	ldrh r1, [r2]
	movs r0, 0x20
	ands r0, r1
	ldr r3, [sp, 0x10]
	cmp r0, 0
	beq _08051812
	movs r0, 0x8
	ands r0, r1
	cmp r0, 0
	beq _08051812
	adds r0, r1, 0
	ands r0, r6
	strh r0, [r2]
_08051812:
	adds r5, 0x1
	ldr r0, [r4, 0xC]
	cmp r5, r0
	blt _080517EC
_0805181A:
	mov r7, r8
	mov r1, r9
	ldr r0, [r1, 0x8]
	cmp r7, r0
	blt _080517DA
_08051824:
	ldr r0, [r3]
	ldr r1, [r3, 0x8]
	adds r0, r1
	lsrs r1, r0, 31
	adds r0, r1
	asrs r2, r0, 1
	ldr r0, [r3, 0x4]
	ldr r1, [r3, 0xC]
	adds r0, r1
	lsrs r1, r0, 31
	adds r0, r1
	asrs r0, 1
	subs r0, 0x1
	mov r10, r0
	movs r0, 0
	mov r9, r0
	subs r7, r2, 0x1
	adds r0, r2, 0x2
	cmp r7, r0
	bge _080518D2
	adds r2, r0, 0
	str r2, [sp, 0x4]
_08051850:
	mov r5, r10
	adds r0, r5, 0x3
	adds r1, r7, 0x1
	mov r8, r1
	mov r1, r9
	adds r1, 0x1
	str r1, [sp, 0x8]
	cmp r5, r0
	bge _080518C6
	movs r3, 0
_08051864:
	adds r0, r7, 0
	adds r1, r5, 0
	str r3, [sp, 0x10]
	bl GetTileSafe
	adds r6, r0, 0
	ldrh r1, [r6]
	movs r0, 0x20
	ands r0, r1
	ldr r3, [sp, 0x10]
	cmp r0, 0
	beq _080518BA
	movs r0, 0x40
	ands r0, r1
	cmp r0, 0
	bne _080518BA
	movs r0, 0x8
	ands r0, r1
	cmp r0, 0
	bne _080518BA
	mov r0, r9
	lsls r2, r0, 1
	adds r2, r3
	ldr r0, [sp]
	ldrb r1, [r0, 0x18]
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 1
	adds r2, r0
	ldr r1, _080518EC
	adds r2, r1
	movs r0, 0
	ldrsh r4, [r2, r0]
	movs r0, 0x64
	bl DungeonRandInt
	ldr r3, [sp, 0x10]
	cmp r4, r0
	ble _080518BA
	ldrh r1, [r6, 0x4]
	movs r0, 0x2
	orrs r0, r1
	strh r0, [r6, 0x4]
_080518BA:
	adds r5, 0x1
	adds r3, 0x6
	mov r0, r10
	adds r0, 0x3
	cmp r5, r0
	blt _08051864
_080518C6:
	mov r7, r8
	ldr r1, [sp, 0x8]
	mov r9, r1
	ldr r0, [sp, 0x4]
	cmp r7, r0
	blt _08051850
_080518D2:
	add sp, 0x14
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_080518E4: .4byte sKecleonShopPosition
_080518E8: .4byte 0x0000ffdf
_080518EC: .4byte gUnknown_80F57D4
	thumb_func_end sub_8051654

	thumb_func_start sub_80518F0
sub_80518F0:
	push {r4-r7,lr}
	movs r5, 0
	movs r6, 0x10
	movs r7, 0
_080518F8:
	adds r0, r5, 0
	movs r1, 0x1
	bl GetTileSafe
	adds r4, r0, 0
	bl ResetTile
	cmp r5, 0
	beq _0805190E
	cmp r5, 0x37
	bne _08051914
_0805190E:
	ldrh r0, [r4]
	orrs r0, r6
	strh r0, [r4]
_08051914:
	adds r0, r5, 0
	movs r1, 0x1E
	bl GetTileSafe
	adds r4, r0, 0
	bl ResetTile
	cmp r5, 0
	beq _0805192A
	cmp r5, 0x37
	bne _08051930
_0805192A:
	ldrh r0, [r4]
	orrs r0, r6
	strh r0, [r4]
_08051930:
	adds r5, 0x1
	cmp r5, 0x37
	ble _080518F8
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_80518F0

	thumb_func_start sub_805193C
sub_805193C:
	push {r4-r6,lr}
	sub sp, 0x8
	adds r6, r3, 0
	ldr r4, [sp, 0x18]
	lsls r0, 24
	lsrs r5, r0, 24
	lsls r1, 16
	lsls r2, 16
	lsrs r1, 16
	orrs r1, r2
	str r1, [sp, 0x4]
	adds r0, r5, 0
	bl sub_805210C
	lsls r0, 24
	cmp r0, 0
	beq _0805196A
	mov r0, sp
	movs r1, 0x76
	movs r2, 0
	bl xxx_init_itemslot_8090A8C
	b _08051974
_0805196A:
	mov r0, sp
	adds r1, r5, 0
	movs r2, 0
	bl xxx_init_itemslot_8090A8C
_08051974:
	mov r0, sp
	ldrb r0, [r0]
	orrs r4, r0
	mov r0, sp
	strb r4, [r0]
	cmp r6, 0
	beq _08051984
	strb r6, [r0, 0x1]
_08051984:
	add r0, sp, 0x4
	mov r1, sp
	movs r2, 0x1
	bl sub_80460F8
	add sp, 0x8
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end sub_805193C

	thumb_func_start sub_8051998
sub_8051998:
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	sub sp, 0x14
	mov r8, r1
	mov r9, r2
	lsls r0, 16
	asrs r0, 16
	adds r1, r0, 0
	lsls r3, 24
	lsrs r6, r3, 24
	adds r7, r6, 0
	ldr r0, _080519E4
	cmp r1, r0
	bne _080519E8
	mov r1, sp
	movs r5, 0
	movs r4, 0
	movs r0, 0x3C
	strh r0, [r1]
	bl sub_803DA20
	mov r1, sp
	strh r0, [r1, 0x8]
	mov r0, sp
	strb r6, [r0, 0x2]
	str r4, [sp, 0x4]
	strb r5, [r0, 0x10]
	mov r1, r8
	strh r1, [r0, 0xC]
	mov r1, r9
	strh r1, [r0, 0xE]
	movs r1, 0x1
	bl sub_806B7F8
	b _08051A14
	.align 2, 0
_080519E4: .4byte 0x000001a5
_080519E8:
	cmp r1, 0
	beq _08051A14
	mov r0, sp
	movs r5, 0
	movs r4, 0
	strh r1, [r0]
	adds r0, r1, 0
	bl sub_803DA20
	mov r1, sp
	strh r0, [r1, 0x8]
	mov r0, sp
	strb r7, [r0, 0x2]
	str r4, [sp, 0x4]
	strb r5, [r0, 0x10]
	mov r1, r8
	strh r1, [r0, 0xC]
	mov r1, r9
	strh r1, [r0, 0xE]
	movs r1, 0x1
	bl sub_806B7F8
_08051A14:
	add sp, 0x14
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_8051998

	thumb_func_start sub_8051A24
sub_8051A24:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0x4
	adds r6, r0, 0
	adds r4, r1, 0
	adds r5, r2, 0
	lsls r6, 24
	lsrs r6, 24
	lsls r3, 24
	lsrs r3, 24
	mov r8, r3
	adds r0, r4, 0
	adds r1, r5, 0
	bl GetTileSafe
	adds r7, r0, 0
	lsls r4, 16
	lsls r5, 16
	lsrs r4, 16
	orrs r4, r5
	str r4, [sp]
	adds r0, r6, 0
	mov r1, sp
	movs r2, 0
	bl sub_8045684
	cmp r0, 0
	beq _08051A66
	str r0, [r7, 0x14]
	adds r0, 0x20
	mov r1, r8
	strb r1, [r0]
_08051A66:
	add sp, 0x4
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_8051A24

	thumb_func_start sub_8051A74
sub_8051A74:
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	sub sp, 0x4
	adds r4, r0, 0
	adds r6, r2, 0
	adds r7, r3, 0
	ldr r0, [sp, 0x20]
	lsls r1, 24
	lsrs r1, 24
	mov r8, r1
	lsls r0, 24
	lsrs r0, 24
	mov r9, r0
	cmp r1, 0xF
	bls _08051AA2
	ldrh r0, [r4]
	ldr r1, _08051AB4
	ands r1, r0
	movs r0, 0x1
	orrs r1, r0
	strh r1, [r4]
_08051AA2:
	mov r0, r8
	cmp r0, 0x45
	bls _08051AAA
	b _08051D68
_08051AAA:
	lsls r0, 2
	ldr r1, _08051AB8
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08051AB4: .4byte 0x0000fffc
_08051AB8: .4byte _08051ABC
	.align 2, 0
_08051ABC:
	.4byte _08051BF0
	.4byte _08051C0C
	.4byte _08051D50
	.4byte _08051E1A
	.4byte _08051C20
	.4byte _08051C54
	.4byte _08051C64
	.4byte _08051C74
	.4byte _08051C94
	.4byte _08051D00
	.4byte _08051C7E
	.4byte _08051D10
	.4byte _08051D24
	.4byte _08051D50
	.4byte _08051D50
	.4byte _08051E1A
	.4byte _08051D68
	.4byte _08051D68
	.4byte _08051D68
	.4byte _08051D68
	.4byte _08051D68
	.4byte _08051D68
	.4byte _08051D68
	.4byte _08051D68
	.4byte _08051D68
	.4byte _08051D68
	.4byte _08051D68
	.4byte _08051D68
	.4byte _08051D68
	.4byte _08051D68
	.4byte _08051D68
	.4byte _08051D68
	.4byte _08051D68
	.4byte _08051D68
	.4byte _08051D68
	.4byte _08051D68
	.4byte _08051D68
	.4byte _08051D68
	.4byte _08051D68
	.4byte _08051D68
	.4byte _08051D68
	.4byte _08051D68
	.4byte _08051D68
	.4byte _08051D68
	.4byte _08051D68
	.4byte _08051D68
	.4byte _08051D68
	.4byte _08051D68
	.4byte _08051D68
	.4byte _08051D68
	.4byte _08051D68
	.4byte _08051D68
	.4byte _08051D68
	.4byte _08051D68
	.4byte _08051D68
	.4byte _08051D68
	.4byte _08051D68
	.4byte _08051D68
	.4byte _08051D68
	.4byte _08051D68
	.4byte _08051D68
	.4byte _08051D68
	.4byte _08051D68
	.4byte _08051D68
	.4byte _08051D68
	.4byte _08051D68
	.4byte _08051D68
	.4byte _08051C94
	.4byte _08051CD4
	.4byte _08051BD4
_08051BD4:
	ldr r0, _08051BFC
	ldr r0, [r0]
	ldr r2, _08051C00
	adds r1, r0, r2
	strh r6, [r1]
	ldr r3, _08051C04
	adds r0, r3
	strh r7, [r0]
	movs r0, 0xB
	adds r1, r6, 0
	adds r2, r7, 0
	movs r3, 0
	bl sub_8051A24
_08051BF0:
	ldrh r1, [r4]
	ldr r0, _08051C08
	ands r0, r1
	movs r1, 0x1
	movs r2, 0
	b _08051D42
	.align 2, 0
_08051BFC: .4byte gDungeon
_08051C00: .4byte 0x00000684
_08051C04: .4byte 0x00000686
_08051C08: .4byte 0x0000fffc
_08051C0C:
	ldrh r1, [r4]
	ldr r0, _08051C18
	ands r0, r1
	ldr r1, _08051C1C
	ands r0, r1
	b _08051D5A
	.align 2, 0
_08051C18: .4byte 0x0000fffc
_08051C1C: .4byte 0x0000feff
_08051C20:
	ldrh r1, [r4]
	ldr r0, _08051C44
	ands r0, r1
	movs r1, 0x1
	movs r2, 0
	orrs r0, r1
	strh r0, [r4]
	ldr r0, _08051C48
	ldr r0, [r0]
	ldr r3, _08051C4C
	adds r1, r0, r3
	strh r6, [r1]
	ldr r1, _08051C50
	adds r0, r1
	strh r7, [r0]
	strb r2, [r4, 0x9]
	b _08051E1A
	.align 2, 0
_08051C44: .4byte 0x0000fffc
_08051C48: .4byte gDungeon
_08051C4C: .4byte 0x0000e218
_08051C50: .4byte 0x0000e21a
_08051C54:
	ldrh r1, [r4]
	ldr r0, _08051C60
	ands r0, r1
	movs r2, 0
	movs r1, 0x2
	b _08051D42
	.align 2, 0
_08051C60: .4byte 0x0000fffc
_08051C64:
	ldrh r1, [r4]
	ldr r0, _08051C70
	ands r0, r1
	movs r1, 0x3
	b _08051D58
	.align 2, 0
_08051C70: .4byte 0x0000fffc
_08051C74:
	ldr r1, _08051C8C
	movs r0, 0x1
	strb r0, [r1]
	bl sub_8049840
_08051C7E:
	ldrh r1, [r4]
	ldr r0, _08051C90
	ands r0, r1
	movs r1, 0x3
	orrs r0, r1
	b _08051D56
	.align 2, 0
_08051C8C: .4byte gUnknown_202F1A8
_08051C90: .4byte 0x0000fffc
_08051C94:
	ldrh r1, [r4]
	ldr r0, _08051CC0
	ands r0, r1
	movs r1, 0x1
	orrs r0, r1
	strh r0, [r4]
	ldrh r0, [r4, 0x4]
	movs r2, 0
	orrs r0, r1
	ldr r1, _08051CC4
	ands r0, r1
	strh r0, [r4, 0x4]
	strb r2, [r4, 0x9]
	ldr r0, _08051CC8
	ldr r0, [r0]
	ldr r2, _08051CCC
	adds r1, r0, r2
	strh r6, [r1]
	ldr r3, _08051CD0
	adds r0, r3
	strh r7, [r0]
	b _08051E1A
	.align 2, 0
_08051CC0: .4byte 0x0000fffc
_08051CC4: .4byte 0x0000fffd
_08051CC8: .4byte gDungeon
_08051CCC: .4byte 0x0000e21c
_08051CD0: .4byte 0x0000e21e
_08051CD4:
	ldrh r1, [r4]
	movs r2, 0x80
	lsls r2, 4
	adds r0, r2, 0
	orrs r0, r1
	ldr r1, _08051CF8
	ands r0, r1
	movs r1, 0x1
	movs r2, 0
	orrs r0, r1
	strh r0, [r4]
	ldrh r1, [r4, 0x4]
	ldr r0, _08051CFC
	ands r0, r1
	strh r0, [r4, 0x4]
	strb r2, [r4, 0x9]
	b _08051E1A
	.align 2, 0
_08051CF8: .4byte 0x0000fffc
_08051CFC: .4byte 0x0000fffd
_08051D00:
	ldrh r1, [r4]
	ldr r0, _08051D0C
	ands r0, r1
	movs r1, 0x1
	b _08051D58
	.align 2, 0
_08051D0C: .4byte 0x0000fffc
_08051D10:
	ldrh r1, [r4]
	ldr r0, _08051D20
	ands r0, r1
	movs r1, 0x1
	movs r2, 0
	orrs r0, r1
	b _08051D3C
	.align 2, 0
_08051D20: .4byte 0x0000fffc
_08051D24:
	ldrh r1, [r4]
	ldr r0, _08051D4C
	ands r0, r1
	movs r1, 0x1
	orrs r0, r1
	movs r2, 0x80
	lsls r2, 5
	adds r1, r2, 0
	orrs r0, r1
	movs r1, 0x10
	orrs r0, r1
	movs r2, 0
_08051D3C:
	movs r3, 0x80
	lsls r3, 4
	adds r1, r3, 0
_08051D42:
	orrs r0, r1
	strh r0, [r4]
	strb r2, [r4, 0x9]
	b _08051E1A
	.align 2, 0
_08051D4C: .4byte 0x0000fffc
_08051D50:
	ldrh r1, [r4]
	ldr r0, _08051D64
	ands r0, r1
_08051D56:
	movs r1, 0x10
_08051D58:
	orrs r0, r1
_08051D5A:
	strh r0, [r4]
	movs r0, 0xFF
	strb r0, [r4, 0x9]
	b _08051E1A
	.align 2, 0
_08051D64: .4byte 0x0000fffc
_08051D68:
	mov r0, r8
	subs r0, 0x10
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0xCB
	bhi _08051E1A
	mov r1, r8
	lsls r0, r1, 4
	ldr r1, _08051DA0
	adds r5, r0, r1
	ldrb r0, [r5, 0xC]
	strb r0, [r4, 0x9]
	ldrb r1, [r5]
	cmp r1, 0
	beq _08051DB8
	mov r2, r9
	cmp r2, 0
	beq _08051DA4
	ldrb r0, [r5]
	movs r1, 0x2
	ldrsh r3, [r5, r1]
	ldr r1, [r5, 0x4]
	str r1, [sp]
	adds r1, r6, 0
	adds r2, r7, 0
	bl sub_805193C
	b _08051DDC
	.align 2, 0
_08051DA0: .4byte gUnknown_80F6D20
_08051DA4:
	ldr r0, _08051DB0
	ldr r0, [r0]
	ldr r2, _08051DB4
	adds r0, r2
	strb r1, [r0]
	b _08051DDC
	.align 2, 0
_08051DB0: .4byte gDungeon
_08051DB4: .4byte 0x0000068b
_08051DB8:
	ldr r2, [r5, 0x4]
	cmp r2, 0
	beq _08051DDC
	ldr r0, _08051E2C
	ldr r1, [r0]
	subs r0, r2, 0x1
	lsls r0, 2
	adds r0, r1, r0
	ldr r3, _08051E30
	adds r0, r3
	strh r6, [r0]
	ldr r0, [r5, 0x4]
	subs r0, 0x1
	lsls r0, 2
	adds r1, r0
	ldr r0, _08051E34
	adds r1, r0
	strh r7, [r1]
_08051DDC:
	movs r1, 0x8
	ldrsh r0, [r5, r1]
	cmp r0, 0
	beq _08051DF2
	ldrb r3, [r5, 0xA]
	mov r1, r8
	str r1, [sp]
	adds r1, r6, 0
	adds r2, r7, 0
	bl sub_8051998
_08051DF2:
	ldrb r0, [r5, 0xB]
	cmp r0, 0x14
	beq _08051E08
	mov r2, r9
	cmp r2, 0
	beq _08051E08
	ldrb r3, [r5, 0xD]
	adds r1, r6, 0
	adds r2, r7, 0
	bl sub_8051A24
_08051E08:
	ldrb r0, [r5, 0xE]
	cmp r0, 0
	beq _08051E1A
	ldrh r0, [r4]
	ldr r1, _08051E38
	ands r1, r0
	movs r0, 0x2
	orrs r1, r0
	strh r1, [r4]
_08051E1A:
	movs r0, 0
	add sp, 0x4
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r1}
	bx r1
	.align 2, 0
_08051E2C: .4byte gDungeon
_08051E30: .4byte 0x0000e220
_08051E34: .4byte 0x0000e222
_08051E38: .4byte 0x0000fffc
	thumb_func_end sub_8051A74

	thumb_func_start sub_8051E3C
sub_8051E3C:
	push {r4-r6,lr}
	sub sp, 0x4
	movs r5, 0
_08051E42:
	movs r4, 0
	adds r6, r5, 0x1
_08051E46:
	adds r0, r4, 0
	adds r1, r5, 0
	bl GetTileSafe
	adds r2, r0, 0
	ldrb r0, [r2, 0xE]
	cmp r0, 0xF
	bls _08051E66
	adds r1, r0, 0
	movs r0, 0
	str r0, [sp]
	adds r0, r2, 0
	adds r2, r4, 0
	adds r3, r5, 0
	bl sub_8051A74
_08051E66:
	adds r4, 0x1
	cmp r4, 0x37
	ble _08051E46
	adds r5, r6, 0
	cmp r5, 0x1F
	ble _08051E42
	add sp, 0x4
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end sub_8051E3C

	thumb_func_start sub_8051E7C
sub_8051E7C:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x14
	mov r9, r0
	movs r1, 0x4
	ldrsh r0, [r0, r1]
	mov r2, r9
	movs r3, 0x6
	ldrsh r1, [r2, r3]
	subs r1, 0x1
	bl GetTileSafe
	str r0, [sp, 0x8]
	ldrh r1, [r0]
	movs r0, 0x80
	lsls r0, 5
	ands r0, r1
	cmp r0, 0
	bne _08051EB8
	ldr r0, _08051EB4
	ldr r1, [r0]
	mov r0, r9
	bl TryDisplayDungeonLoggableMessage
	b _080520F6
	.align 2, 0
_08051EB4: .4byte gUnknown_80FDDF0
_08051EB8:
	ldr r0, _08051EF0
	ldr r0, [r0]
	ldr r1, _08051EF4
	adds r0, r1
	ldrb r0, [r0]
	cmp r0, 0
	beq _08051EC8
	b _080520EC
_08051EC8:
	mov r2, r9
	ldrh r1, [r2, 0x6]
	subs r1, 0x1
	lsls r1, 16
	ldrh r0, [r2, 0x4]
	orrs r0, r1
	str r0, [sp, 0x4]
	mov r0, r9
	bl GetEntityRoom
	lsls r0, 24
	lsrs r0, 24
	str r0, [sp, 0xC]
	mov r3, r9
	movs r1, 0x6
	ldrsh r0, [r3, r1]
	adds r6, r0, 0
	subs r6, 0x15
	b _08051FE0
	.align 2, 0
_08051EF0: .4byte gDungeon
_08051EF4: .4byte 0x00003a09
_08051EF8:
	mov r2, r9
	movs r3, 0x4
	ldrsh r0, [r2, r3]
	adds r5, r0, 0
	subs r5, 0x14
	adds r0, 0x14
	adds r1, r6, 0x1
	str r1, [sp, 0x10]
	cmp r5, r0
	bgt _08051FD8
	ldr r2, _080520C0
	mov r10, r2
_08051F10:
	mov r0, r10
	ldr r3, [r0]
	ldr r1, _080520C4
	adds r0, r3, r1
	ldr r1, [r0]
	subs r2, r5, r1
	mov r8, r2
	ldr r2, _080520C8
	adds r0, r3, r2
	ldr r2, [r0]
	subs r7, r6, r2
	mov r0, r8
	cmp r0, 0
	blt _08051FCA
	cmp r7, 0
	blt _08051FCA
	cmp r0, 0x7
	bgt _08051FCA
	cmp r7, 0x7
	bgt _08051FCA
	adds r0, r1, 0x1
	cmp r5, r0
	blt _08051FCA
	adds r0, r2, 0x1
	cmp r6, r0
	blt _08051FCA
	ldr r1, _080520CC
	adds r0, r3, r1
	ldr r0, [r0]
	subs r0, 0x1
	cmp r5, r0
	bge _08051FCA
	ldr r2, _080520D0
	adds r0, r3, r2
	ldr r0, [r0]
	subs r0, 0x1
	cmp r6, r0
	bge _08051FCA
	adds r0, r5, 0
	adds r1, r6, 0
	bl GetTileSafe
	adds r4, r0, 0
	ldrh r0, [r4]
	movs r3, 0x80
	lsls r3, 1
	adds r1, r3, 0
	ands r0, r1
	cmp r0, 0
	beq _08051F9A
	mov r0, r10
	ldr r2, [r0]
	lsls r1, r7, 1
	adds r1, r7
	lsls r1, 3
	mov r3, r8
	lsls r0, r3, 1
	add r0, r8
	lsls r0, 6
	adds r1, r0
	adds r2, r1
	ldr r1, _080520D4
	adds r0, r2, r1
	ldrh r0, [r0]
	strh r0, [r4]
	ldr r3, _080520D8
	adds r2, r3
	ldrh r0, [r2]
	strh r0, [r4, 0x4]
_08051F9A:
	mov r1, r10
	ldr r0, [r1]
	mov r2, r8
	lsls r1, r2, 3
	adds r1, r7, r1
	ldr r3, _080520DC
	adds r0, r3
	adds r0, r1
	ldrb r1, [r0]
	movs r0, 0x1
	str r0, [sp]
	adds r0, r4, 0
	adds r2, r5, 0
	adds r3, r6, 0
	bl sub_8051A74
	ldrh r1, [r4, 0x4]
	movs r0, 0x3
	orrs r0, r1
	strh r0, [r4, 0x4]
	ldr r0, [sp, 0xC]
	cmp r0, 0xFF
	beq _08051FCA
	strb r0, [r4, 0x9]
_08051FCA:
	adds r5, 0x1
	mov r2, r9
	movs r3, 0x4
	ldrsh r0, [r2, r3]
	adds r0, 0x14
	cmp r5, r0
	ble _08051F10
_08051FD8:
	ldr r6, [sp, 0x10]
	mov r1, r9
	movs r2, 0x6
	ldrsh r0, [r1, r2]
_08051FE0:
	adds r0, 0x13
	cmp r6, r0
	ble _08051EF8
	mov r3, r9
	movs r1, 0x6
	ldrsh r0, [r3, r1]
	adds r6, r0, 0
	subs r6, 0x15
	adds r0, 0x13
	ldr r7, _080520C0
	cmp r6, r0
	bgt _0805207A
_08051FF8:
	mov r2, r9
	movs r3, 0x4
	ldrsh r0, [r2, r3]
	adds r5, r0, 0
	subs r5, 0x14
	adds r0, 0x14
	adds r1, r6, 0x1
	str r1, [sp, 0x10]
	cmp r5, r0
	bgt _0805206C
	ldr r7, _080520C0
_0805200E:
	ldr r0, _080520C0
	ldr r4, [r0]
	ldr r2, _080520C4
	adds r0, r4, r2
	ldr r2, [r0]
	subs r1, r5, r2
	ldr r3, _080520C8
	adds r0, r4, r3
	ldr r3, [r0]
	subs r0, r6, r3
	cmp r1, 0
	blt _0805205E
	cmp r0, 0
	blt _0805205E
	cmp r1, 0x7
	bgt _0805205E
	cmp r0, 0x7
	bgt _0805205E
	adds r0, r2, 0x1
	cmp r5, r0
	blt _0805205E
	adds r0, r3, 0x1
	cmp r6, r0
	blt _0805205E
	ldr r1, _080520CC
	adds r0, r4, r1
	ldr r0, [r0]
	subs r0, 0x1
	cmp r5, r0
	bge _0805205E
	ldr r2, _080520D0
	adds r0, r4, r2
	ldr r0, [r0]
	subs r0, 0x1
	cmp r6, r0
	bge _0805205E
	adds r0, r5, 0
	adds r1, r6, 0
	bl sub_80498A8
_0805205E:
	adds r5, 0x1
	mov r3, r9
	movs r1, 0x4
	ldrsh r0, [r3, r1]
	adds r0, 0x14
	cmp r5, r0
	ble _0805200E
_0805206C:
	ldr r6, [sp, 0x10]
	mov r2, r9
	movs r3, 0x6
	ldrsh r0, [r2, r3]
	adds r0, 0x13
	cmp r6, r0
	ble _08051FF8
_0805207A:
	ldr r0, [r7]
	ldr r1, _080520E0
	adds r0, r1
	movs r1, 0x1
	strb r1, [r0]
	ldr r2, [sp, 0x8]
	ldrh r1, [r2]
	ldr r0, _080520E4
	ands r0, r1
	strh r0, [r2]
	mov r3, r9
	movs r1, 0x4
	ldrsh r0, [r3, r1]
	movs r2, 0x6
	ldrsh r1, [r3, r2]
	subs r1, 0x1
	bl sub_80498A8
	bl sub_8049B8C
	bl sub_8049ED4
	add r0, sp, 0x4
	bl sub_80429FC
	ldr r0, _080520E8
	ldr r1, [r0]
	mov r0, r9
	bl TryDisplayDungeonLoggableMessage
	movs r0, 0x14
	movs r1, 0x3C
	bl sub_803E708
	b _080520F6
	.align 2, 0
_080520C0: .4byte gDungeon
_080520C4: .4byte 0x0000e250
_080520C8: .4byte 0x0000e254
_080520CC: .4byte 0x0000e258
_080520D0: .4byte 0x0000e25c
_080520D4: .4byte 0x0000e27c
_080520D8: .4byte 0x0000e280
_080520DC: .4byte 0x0000e87c
_080520E0: .4byte 0x00003a09
_080520E4: .4byte 0x0000efef
_080520E8: .4byte gUnknown_80FDDD0
_080520EC:
	ldr r0, _08052108
	ldr r1, [r0]
	mov r0, r9
	bl TryDisplayDungeonLoggableMessage
_080520F6:
	add sp, 0x14
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_08052108: .4byte gUnknown_80FDDF0
	thumb_func_end sub_8051E7C

	thumb_func_start sub_805210C
sub_805210C:
	push {r4-r7,lr}
	lsls r0, 24
	lsrs r5, r0, 24
	movs r3, 0
	ldr r7, _080521B4
	movs r4, 0x1
	ldr r2, [r7]
_0805211A:
	ldrb r1, [r2]
	adds r0, r4, 0
	ands r0, r1
	cmp r0, 0
	beq _0805212A
	ldrb r0, [r2, 0x2]
	cmp r0, r5
	beq _080521C8
_0805212A:
	adds r2, 0x4
	adds r3, 0x1
	cmp r3, 0x13
	ble _0805211A
	movs r3, 0
	ldr r0, _080521B8
	ldr r4, [r0]
	movs r6, 0x1
_0805213A:
	movs r0, 0x64
	adds r2, r3, 0
	muls r2, r0
	adds r0, r2, r4
	ldr r1, _080521BC
	adds r0, r1
	ldrb r1, [r0]
	adds r0, r6, 0
	ands r0, r1
	cmp r0, 0
	beq _0805216C
	adds r0, r2, r4
	ldr r1, _080521C0
	adds r0, r1
	ldrb r1, [r0]
	adds r0, r6, 0
	ands r0, r1
	adds r1, r2, r4
	cmp r0, 0
	beq _0805216C
	ldr r2, _080521C4
	adds r0, r1, r2
	ldrb r0, [r0]
	cmp r0, r5
	beq _080521C8
_0805216C:
	adds r3, 0x1
	cmp r3, 0x3
	ble _0805213A
	movs r3, 0
	ldr r0, _080521B8
	ldr r4, [r0]
_08052178:
	movs r0, 0x58
	muls r0, r3
	adds r2, r0, r4
	ldrb r1, [r2]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _08052196
	adds r0, r2, 0
	adds r0, 0x28
	ldrb r0, [r0]
	cmp r0, 0
	beq _08052196
	cmp r0, r5
	beq _080521C8
_08052196:
	adds r3, 0x1
	movs r0, 0xCE
	lsls r0, 1
	cmp r3, r0
	ble _08052178
	ldr r0, [r7]
	lsls r1, r5, 1
	adds r0, 0x50
	adds r0, r1
	ldrh r0, [r0]
	cmp r0, 0
	bne _080521C8
	movs r0, 0
	b _080521CA
	.align 2, 0
_080521B4: .4byte gTeamInventoryRef
_080521B8: .4byte gRecruitedPokemonRef
_080521BC: .4byte 0x00008df8
_080521C0: .4byte 0x00008e38
_080521C4: .4byte 0x00008e3a
_080521C8:
	movs r0, 0x1
_080521CA:
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_805210C

    .align 2,0
