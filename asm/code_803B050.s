        #include "asm/constants/gba_constants.inc"
	#include "asm/macros.inc"

	.syntax unified

	.text

	thumb_func_start sub_803B344
sub_803B344:
	adds r1, r0, 0
	lsls r1, 24
	lsrs r1, 24
	lsls r0, r1, 3
	subs r0, r1
	lsls r0, 2
	ldr r1, _0803B358
	adds r0, r1
	bx lr
	.align 2, 0
_0803B358: .4byte gUnknown_80E7F94
	thumb_func_end sub_803B344

	thumb_func_start sub_803B35C
sub_803B35C:
	push {r4,r5,lr}
	adds r5, r0, 0
	adds r4, r1, 0
	adds r1, 0x18
	bl sub_803C21C
	ldrb r0, [r5, 0x2]
	subs r0, 0x1
	cmp r0, 0x8
	bls _0803B372
	b _0803B4FA
_0803B372:
	lsls r0, 2
	ldr r1, _0803B37C
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0803B37C: .4byte _0803B380
	.align 2, 0
_0803B380:
	.4byte _0803B3A4
	.4byte _0803B3BE
	.4byte _0803B3D8
	.4byte _0803B3F2
	.4byte _0803B414
	.4byte _0803B442
	.4byte _0803B470
	.4byte _0803B49E
	.4byte _0803B4CC
_0803B3A4:
	adds r0, r4, 0
	adds r0, 0x40
	movs r1, 0
	strb r1, [r0]
	adds r0, 0x1
	strb r1, [r0]
	adds r1, r4, 0
	adds r1, 0x42
	movs r0, 0x6
	strb r0, [r1]
	subs r1, 0x14
	movs r0, 0x5
	b _0803B576
_0803B3BE:
	adds r0, r4, 0
	adds r0, 0x40
	movs r1, 0x1
	strb r1, [r0]
	adds r0, 0x1
	strb r1, [r0]
	adds r1, r4, 0
	adds r1, 0x42
	movs r0, 0x6
	strb r0, [r1]
	subs r1, 0x14
	movs r0, 0x5
	b _0803B576
_0803B3D8:
	adds r0, r4, 0
	adds r0, 0x40
	movs r1, 0x2
	strb r1, [r0]
	adds r0, 0x1
	strb r1, [r0]
	adds r1, r4, 0
	adds r1, 0x42
	movs r0, 0x6
	strb r0, [r1]
	subs r1, 0x14
	movs r0, 0x5
	b _0803B576
_0803B3F2:
	adds r0, r4, 0
	adds r0, 0x40
	movs r1, 0x3
	strb r1, [r0]
	adds r0, 0x1
	strb r1, [r0]
	adds r1, r4, 0
	adds r1, 0x42
	movs r0, 0x6
	strb r0, [r1]
	bl sub_8096DD8
	str r0, [r4, 0x4C]
	bl sub_8096DE8
	str r0, [r4, 0x50]
	b _0803B578
_0803B414:
	ldrb r0, [r5, 0x1]
	cmp r0, 0x3
	bne _0803B42A
	adds r0, r4, 0
	adds r0, 0x40
	movs r1, 0xB
	strb r1, [r0]
	adds r1, r4, 0
	adds r1, 0x42
	movs r0, 0x1
	b _0803B438
_0803B42A:
	adds r0, r4, 0
	adds r0, 0x40
	movs r1, 0xC
	strb r1, [r0]
	adds r1, r4, 0
	adds r1, 0x42
	movs r0, 0x2
_0803B438:
	strb r0, [r1]
	adds r1, r4, 0
	adds r1, 0x41
	movs r0, 0x4
	b _0803B576
_0803B442:
	ldrb r0, [r5, 0x1]
	cmp r0, 0x3
	bne _0803B458
	adds r0, r4, 0
	adds r0, 0x40
	movs r1, 0xB
	strb r1, [r0]
	adds r1, r4, 0
	adds r1, 0x42
	movs r0, 0x1
	b _0803B466
_0803B458:
	adds r0, r4, 0
	adds r0, 0x40
	movs r1, 0xC
	strb r1, [r0]
	adds r1, r4, 0
	adds r1, 0x42
	movs r0, 0x2
_0803B466:
	strb r0, [r1]
	adds r1, r4, 0
	adds r1, 0x41
	movs r0, 0x5
	b _0803B576
_0803B470:
	adds r0, r5, 0
	bl sub_803B600
	str r0, [r4, 0x4]
	movs r1, 0x1
	negs r1, r1
	cmp r0, r1
	bne _0803B488
	adds r1, r4, 0
	adds r1, 0x40
	movs r0, 0x9
	b _0803B48E
_0803B488:
	adds r1, r4, 0
	adds r1, 0x40
	movs r0, 0x4
_0803B48E:
	strb r0, [r1]
	adds r1, r4, 0
	adds r1, 0x41
	movs r0, 0x6
	strb r0, [r1]
	adds r1, 0x1
	movs r0, 0x4
	b _0803B576
_0803B49E:
	adds r0, r5, 0
	bl sub_803B628
	str r0, [r4, 0x4]
	movs r1, 0x1
	negs r1, r1
	cmp r0, r1
	bne _0803B4B6
	adds r1, r4, 0
	adds r1, 0x40
	movs r0, 0x9
	b _0803B4BC
_0803B4B6:
	adds r1, r4, 0
	adds r1, 0x40
	movs r0, 0x5
_0803B4BC:
	strb r0, [r1]
	adds r1, r4, 0
	adds r1, 0x41
	movs r0, 0x7
	strb r0, [r1]
	adds r1, 0x1
	movs r0, 0x4
	b _0803B576
_0803B4CC:
	adds r0, r5, 0
	bl sub_803B66C
	str r0, [r4, 0x4]
	movs r1, 0x1
	negs r1, r1
	cmp r0, r1
	bne _0803B4E4
	adds r1, r4, 0
	adds r1, 0x40
	movs r0, 0xA
	b _0803B4EA
_0803B4E4:
	adds r1, r4, 0
	adds r1, 0x40
	movs r0, 0x6
_0803B4EA:
	strb r0, [r1]
	adds r1, r4, 0
	adds r1, 0x41
	movs r0, 0x8
	strb r0, [r1]
	adds r1, 0x1
	movs r0, 0x5
	b _0803B576
_0803B4FA:
	ldrb r0, [r5, 0x1]
	cmp r0, 0x2
	beq _0803B528
	cmp r0, 0x2
	bgt _0803B50A
	cmp r0, 0x1
	beq _0803B514
	b _0803B564
_0803B50A:
	cmp r0, 0x3
	beq _0803B53C
	cmp r0, 0x4
	beq _0803B550
	b _0803B564
_0803B514:
	adds r1, r4, 0
	adds r1, 0x40
	movs r0, 0x9
	strb r0, [r1]
	adds r1, 0x1
	movs r0, 0xD
	strb r0, [r1]
	adds r1, 0x1
	movs r0, 0x4
	b _0803B576
_0803B528:
	adds r1, r4, 0
	adds r1, 0x40
	movs r0, 0xA
	strb r0, [r1]
	adds r1, 0x1
	movs r0, 0xE
	strb r0, [r1]
	adds r1, 0x1
	movs r0, 0x5
	b _0803B576
_0803B53C:
	adds r1, r4, 0
	adds r1, 0x40
	movs r0, 0xB
	strb r0, [r1]
	adds r1, 0x1
	movs r0, 0xF
	strb r0, [r1]
	adds r1, 0x1
	movs r0, 0x1
	b _0803B576
_0803B550:
	adds r1, r4, 0
	adds r1, 0x40
	movs r0, 0xC
	strb r0, [r1]
	adds r1, 0x1
	movs r0, 0x10
	strb r0, [r1]
	adds r1, 0x1
	movs r0, 0x2
	b _0803B576
_0803B564:
	adds r1, r4, 0
	adds r1, 0x40
	movs r0, 0x8
	strb r0, [r1]
	adds r1, 0x1
	movs r0, 0xC
	strb r0, [r1]
	adds r1, 0x1
	movs r0, 0x3
_0803B576:
	strb r0, [r1]
_0803B578:
	adds r0, r5, 0x4
	str r0, [r4, 0x8]
	movs r0, 0
	str r0, [r4, 0xC]
	ldrh r0, [r5, 0xC]
	movs r1, 0
	strh r0, [r4, 0x10]
	ldrh r0, [r5, 0xE]
	strh r0, [r4, 0x12]
	ldrb r0, [r5, 0x10]
	strb r0, [r4, 0x14]
	ldrb r0, [r5]
	subs r0, 0x2
	cmp r0, 0x7
	bhi _0803B5EC
	lsls r0, 2
	ldr r1, _0803B5A0
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0803B5A0: .4byte _0803B5A4
	.align 2, 0
_0803B5A4:
	.4byte _0803B5C4
	.4byte _0803B5C4
	.4byte _0803B5C4
	.4byte _0803B5C4
	.4byte _0803B5DC
	.4byte _0803B5CC
	.4byte _0803B5DC
	.4byte _0803B5DC
_0803B5C4:
	adds r0, r4, 0
	adds r0, 0x43
	movs r1, 0x1
	b _0803B5F0
_0803B5CC:
	adds r1, r4, 0
	adds r1, 0x43
	movs r0, 0
	strb r0, [r1]
	adds r1, 0x1
	movs r0, 0x3
	strb r0, [r1]
	b _0803B5F6
_0803B5DC:
	adds r1, r4, 0
	adds r1, 0x43
	movs r0, 0x3
	strb r0, [r1]
	adds r1, 0x1
	movs r0, 0x2
	strb r0, [r1]
	b _0803B5F6
_0803B5EC:
	adds r0, r4, 0
	adds r0, 0x43
_0803B5F0:
	strb r1, [r0]
	adds r0, 0x1
	strb r1, [r0]
_0803B5F6:
	str r5, [r4, 0x54]
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_803B35C

	thumb_func_start sub_803B600
sub_803B600:
	push {lr}
	ldr r2, _0803B614
	movs r1, 0
	ldr r3, [r0, 0xC]
_0803B608:
	ldr r0, [r2]
	cmp r0, r3
	bne _0803B618
	adds r0, r1, 0
	b _0803B624
	.align 2, 0
_0803B614: .4byte gUnknown_80E9920
_0803B618:
	adds r2, 0x8
	adds r1, 0x1
	cmp r1, 0x14
	ble _0803B608
	movs r0, 0x1
	negs r0, r0
_0803B624:
	pop {r1}
	bx r1
	thumb_func_end sub_803B600

	thumb_func_start sub_803B628
sub_803B628:
	push {r4,r5,lr}
	adds r4, r0, 0
	ldr r2, _0803B654
	movs r3, 0
_0803B630:
	ldr r1, [r2]
	ldr r0, [r4, 0xC]
	cmp r1, r0
	beq _0803B650
	movs r0, 0x2
	ldrsh r1, [r2, r0]
	movs r5, 0xC
	ldrsh r0, [r4, r5]
	cmp r1, r0
	bne _0803B658
	movs r0, 0
	ldrsh r1, [r2, r0]
	movs r5, 0xE
	ldrsh r0, [r4, r5]
	cmp r1, r0
	bne _0803B658
_0803B650:
	adds r0, r3, 0
	b _0803B664
	.align 2, 0
_0803B654: .4byte gUnknown_80E9F8C
_0803B658:
	adds r2, 0xC
	adds r3, 0x1
	cmp r3, 0x2C
	ble _0803B630
	movs r0, 0x1
	negs r0, r0
_0803B664:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_803B628

	thumb_func_start sub_803B66C
sub_803B66C:
	push {r4,r5,lr}
	adds r4, r0, 0
	ldr r2, _0803B698
	movs r3, 0
_0803B674:
	ldr r1, [r2]
	ldr r0, [r4, 0xC]
	cmp r1, r0
	beq _0803B694
	movs r0, 0x2
	ldrsh r1, [r2, r0]
	movs r5, 0xC
	ldrsh r0, [r4, r5]
	cmp r1, r0
	bne _0803B69C
	movs r0, 0
	ldrsh r1, [r2, r0]
	movs r5, 0xE
	ldrsh r0, [r4, r5]
	cmp r1, r0
	bne _0803B69C
_0803B694:
	adds r0, r3, 0
	b _0803B6A8
	.align 2, 0
_0803B698: .4byte gUnknown_80E8168
_0803B69C:
	adds r2, 0x4
	adds r3, 0x1
	cmp r3, 0x5
	ble _0803B674
	movs r0, 0x1
	negs r0, r0
_0803B6A8:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_803B66C

        .align 2,0
