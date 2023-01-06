	#include "asm/constants/gba_constants.inc"
	#include "asm/macros.inc"

	.syntax unified

	.text

	thumb_func_start sub_8096078
sub_8096078:
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	movs r2, 0
	movs r3, 0
	ldr r0, _08096090
	mov r12, r0
	mov r8, r3
	movs r4, 0
	mov r9, r4
	b _080960B6
	.align 2, 0
_08096090: .4byte gUnknown_203B490
_08096094:
	cmp r2, r3
	ble _080960AA
	mov r1, r12
	ldr r0, [r1]
	mov r5, r8
	adds r1, r0, r5
	adds r0, r4
	ldm r0!, {r5-r7}
	stm r1!, {r5-r7}
	ldm r0!, {r6,r7}
	stm r1!, {r6,r7}
_080960AA:
	adds r4, 0x14
	movs r0, 0x14
	add r9, r0
	adds r2, 0x1
	add r8, r0
	adds r3, 0x1
_080960B6:
	cmp r2, 0x3
	bgt _080960E2
	mov r1, r12
	ldr r0, [r1]
	adds r0, r4
	ldrb r0, [r0]
	cmp r0, 0
	bne _080960E2
	ldr r6, _08096110
	mov r1, r9
_080960CA:
	adds r1, 0x14
	adds r4, 0x14
	movs r5, 0x14
	add r9, r5
	adds r2, 0x1
	cmp r2, 0x3
	bgt _080960E2
	ldr r0, [r6]
	adds r0, r1
	ldrb r0, [r0]
	cmp r0, 0
	beq _080960CA
_080960E2:
	cmp r2, 0x4
	bne _08096094
	cmp r3, 0x3
	bgt _08096102
	ldr r4, _08096110
	movs r2, 0
	lsls r0, r3, 2
	adds r0, r3
	lsls r1, r0, 2
_080960F4:
	ldr r0, [r4]
	adds r0, r1
	strb r2, [r0]
	adds r1, 0x14
	adds r3, 0x1
	cmp r3, 0x3
	ble _080960F4
_08096102:
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_08096110: .4byte gUnknown_203B490
	thumb_func_end sub_8096078

	thumb_func_start sub_8096114
sub_8096114:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x14
	movs r1, 0
_08096122:
	adds r0, r1, 0x1
	mov r10, r0
	mov r8, r10
	cmp r0, 0x3
	bgt _08096198
	ldr r2, _080961B0
	mov r9, r2
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 2
	mov r12, r0
	mov r3, r10
	lsls r0, r3, 2
	add r0, r10
	lsls r4, r0, 2
_08096140:
	mov r5, r9
	ldr r1, [r5]
	adds r3, r1, r4
	ldrb r0, [r3]
	cmp r0, 0
	beq _0809618C
	mov r6, r12
	adds r2, r1, r6
	ldrb r1, [r2, 0x4]
	ldrb r0, [r3, 0x4]
	cmp r1, r0
	bhi _08096164
	cmp r1, r0
	bne _0809618C
	ldrb r0, [r2, 0x5]
	ldrb r7, [r3, 0x5]
	cmp r0, r7
	bls _0809618C
_08096164:
	mov r1, sp
	adds r0, r2, 0
	ldm r0!, {r5-r7}
	stm r1!, {r5-r7}
	ldm r0!, {r5,r6}
	stm r1!, {r5,r6}
	adds r1, r2, 0
	adds r0, r3, 0
	ldm r0!, {r2,r3,r7}
	stm r1!, {r2,r3,r7}
	ldm r0!, {r5,r6}
	stm r1!, {r5,r6}
	mov r7, r9
	ldr r1, [r7]
	adds r1, r4
	mov r0, sp
	ldm r0!, {r2,r3,r5}
	stm r1!, {r2,r3,r5}
	ldm r0!, {r6,r7}
	stm r1!, {r6,r7}
_0809618C:
	adds r4, 0x14
	movs r0, 0x1
	add r8, r0
	mov r1, r8
	cmp r1, 0x3
	ble _08096140
_08096198:
	mov r1, r10
	cmp r1, 0x2
	ble _08096122
	add sp, 0x14
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_080961B0: .4byte gUnknown_203B490
	thumb_func_end sub_8096114

	thumb_func_start sub_80961B4
sub_80961B4:
	push {lr}
	bl sub_8096E2C
	lsls r0, 24
	cmp r0, 0
	beq _080961CE
	ldr r0, _080961D4
	ldr r0, [r0]
	movs r1, 0xCA
	lsls r1, 2
	adds r0, r1
	movs r1, 0x1
	strb r1, [r0]
_080961CE:
	pop {r0}
	bx r0
	.align 2, 0
_080961D4: .4byte gUnknown_203B490
	thumb_func_end sub_80961B4

	thumb_func_start sub_80961D8
sub_80961D8:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	movs r7, 0
	bl CountFilledMailboxSlots
	adds r6, r0, 0
	movs r1, 0x4
	bl RandomRange
	mov r8, r0
	cmp r6, 0x3
	bgt _08096202
	ldr r4, _08096208
	ldr r0, [r4]
	movs r2, 0xCA
	lsls r2, 2
	adds r1, r0, r2
	ldrb r0, [r1]
	cmp r0, 0
	bne _0809620C
_08096202:
	movs r0, 0
	b _080963A8
	.align 2, 0
_08096208: .4byte gUnknown_203B490
_0809620C:
	strb r7, [r1]
	movs r5, 0x38
	movs r0, 0xA
	movs r1, 0x31
	movs r2, 0x1
	bl sub_8001D08
	lsls r0, 24
	cmp r0, 0
	beq _0809623A
	ldr r0, [r4]
	ldr r1, _08096328
	adds r0, r1
	ldrb r0, [r0]
	cmp r0, 0
	bne _0809623A
	movs r0, 0x35
	bl sub_8096E80
	lsls r0, 24
	cmp r0, 0
	bne _0809623A
	movs r5, 0x35
_0809623A:
	movs r0, 0xF
	bl sub_80023E4
	lsls r0, 24
	cmp r0, 0
	beq _0809629C
	ldr r0, _0809632C
	ldr r0, [r0]
	movs r2, 0xC9
	lsls r2, 2
	adds r0, r2
	ldrb r0, [r0]
	cmp r0, 0
	bne _08096264
	movs r0, 0x34
	bl sub_8096E80
	lsls r0, 24
	cmp r0, 0
	bne _08096264
	movs r5, 0x34
_08096264:
	ldr r0, _0809632C
	ldr r0, [r0]
	ldr r1, _08096330
	adds r0, r1
	ldrb r0, [r0]
	cmp r0, 0
	bne _08096280
	movs r0, 0x33
	bl sub_8096E80
	lsls r0, 24
	cmp r0, 0
	bne _08096280
	movs r5, 0x33
_08096280:
	ldr r0, _0809632C
	ldr r0, [r0]
	ldr r2, _08096334
	adds r0, r2
	ldrb r0, [r0]
	cmp r0, 0
	bne _0809629C
	movs r0, 0x32
	bl sub_8096E80
	lsls r0, 24
	cmp r0, 0
	bne _0809629C
	movs r5, 0x32
_0809629C:
	bl GetRescueTeamRank
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x6
	bne _080962C4
	ldr r0, _0809632C
	ldr r0, [r0]
	ldr r1, _08096338
	adds r0, r1
	ldrb r0, [r0]
	cmp r0, 0
	bne _080962C4
	movs r0, 0x36
	bl sub_8096E80
	lsls r0, 24
	cmp r0, 0
	bne _080962C4
	movs r5, 0x36
_080962C4:
	movs r0, 0x6
	bl sub_80023E4
	lsls r0, 24
	cmp r0, 0
	beq _080962EC
	ldr r0, _0809632C
	ldr r0, [r0]
	ldr r2, _0809633C
	adds r0, r2
	ldrb r0, [r0]
	cmp r0, 0
	bne _080962EC
	movs r0, 0x37
	bl sub_8096E80
	lsls r0, 24
	cmp r0, 0
	bne _080962EC
	movs r5, 0x37
_080962EC:
	cmp r5, 0x38
	bne _08096310
	cmp r6, r8
	bgt _08096392
	bl sub_8096E2C
	lsls r0, 24
	lsrs r5, r0, 24
	movs r0, 0xE
	bl sub_80023E4
	lsls r0, 24
	cmp r0, 0
	bne _0809630C
	cmp r5, 0x2
	bhi _0809638E
_0809630C:
	cmp r5, 0x31
	bhi _0809638E
_08096310:
	lsls r0, r6, 24
	lsrs r0, 24
	bl GetMailboxSlotInfo
	adds r4, r0, 0
	movs r0, 0x1
	strb r0, [r4]
	movs r0, 0x62
	strb r0, [r4, 0x4]
	strb r5, [r4, 0x5]
	b _0809638A
	.align 2, 0
_08096328: .4byte 0x00000325
_0809632C: .4byte gUnknown_203B490
_08096330: .4byte 0x00000323
_08096334: .4byte 0x00000322
_08096338: .4byte 0x00000326
_0809633C: .4byte 0x00000327
_08096340:
	lsls r0, r6, 24
	lsrs r0, 24
	bl GetMailboxSlotInfo
	adds r4, r0, 0
	bl sub_8095B28
	lsls r0, 24
	cmp r0, 0
	beq _08096392
	bl sub_8095E78
	lsls r0, 24
	lsrs r5, r0, 24
	adds r0, r4, 0x4
	ldrb r1, [r4, 0x1]
	bl sub_803C1D0
	lsls r0, 24
	cmp r0, 0
	bne _0809636C
	movs r5, 0
_0809636C:
	movs r0, 0x5
	movs r1, 0xA
	bl RandomRange
	strb r0, [r4, 0x11]
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x9
	bne _0809638A
	cmp r5, 0
	bne _08096388
	movs r0, 0x5
	strb r0, [r4, 0x11]
	b _0809638A
_08096388:
	strb r5, [r4, 0x13]
_0809638A:
	movs r7, 0x1
	adds r6, 0x1
_0809638E:
	cmp r6, r8
	ble _08096340
_08096392:
	bl sub_80963B4
	lsls r0, 24
	cmp r0, 0
	beq _0809639E
	movs r7, 0x1
_0809639E:
	bl sub_8096078
	bl sub_8096114
	adds r0, r7, 0
_080963A8:
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_80961D8

	thumb_func_start sub_80963B4
sub_80963B4:
	push {r4-r6,lr}
	movs r6, 0
	bl sub_8096E2C
	lsls r0, 24
	lsrs r5, r0, 24
	bl CountFilledMailboxSlots
	adds r4, r0, 0
	cmp r4, 0x3
	ble _080963CE
	movs r0, 0
	b _080963F4
_080963CE:
	movs r0, 0xE
	bl sub_80023E4
	lsls r0, 24
	cmp r0, 0
	beq _080963F2
	cmp r5, 0x31
	bhi _080963F2
	lsls r0, r4, 24
	lsrs r0, 24
	bl GetMailboxSlotInfo
	movs r1, 0x1
	strb r1, [r0]
	movs r1, 0x62
	strb r1, [r0, 0x4]
	strb r5, [r0, 0x5]
	movs r6, 0x1
_080963F2:
	adds r0, r6, 0
_080963F4:
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end sub_80963B4

	thumb_func_start sub_80963FC
sub_80963FC:
	push {r4-r6,lr}
	movs r6, 0
_08096400:
	lsls r0, r6, 24
	lsrs r4, r0, 24
	adds r0, r4, 0
	bl GetMailboxSlotInfo
	adds r5, r0, 0
	ldrb r0, [r5]
	cmp r0, 0x1
	beq _08096418
	adds r0, r4, 0
	bl ResetMailboxSlot
_08096418:
	adds r6, 0x1
	cmp r6, 0x3
	ble _08096400
	bl sub_8096078
	bl CountFilledMailboxSlots
	lsls r0, 24
	lsrs r0, 24
	bl GetMailboxSlotInfo
	adds r5, r0, 0
	movs r0, 0
	movs r4, 0x5
	strb r4, [r5]
	strb r0, [r5, 0x1]
	strb r0, [r5, 0x2]
	movs r0, 0x2
	strb r0, [r5, 0x4]
	movs r0, 0x3
	strb r0, [r5, 0x5]
	bl Random
	ldr r1, _08096484
	ands r1, r0
	str r1, [r5, 0x8]
	movs r0, 0x10
	strh r0, [r5, 0xC]
	strh r0, [r5, 0xE]
	ldrb r0, [r5, 0x4]
	bl sub_8095F28
	strb r0, [r5, 0x10]
	strb r4, [r5, 0x11]
_0809645C:
	ldrb r1, [r5, 0x1]
	adds r0, r5, 0x4
	adds r2, r5, 0
	adds r2, 0x12
	bl sub_803C37C
	ldrb r0, [r5, 0x10]
	ldrb r1, [r5, 0x12]
	cmp r0, r1
	beq _0809645C
	movs r0, 0
	strb r0, [r5, 0x13]
	bl sub_8096078
	bl sub_8096114
	pop {r4-r6}
	pop {r0}
	bx r0
	.align 2, 0
_08096484: .4byte 0x00ffffff
	thumb_func_end sub_80963FC

	thumb_func_start sub_8096488
sub_8096488:
	push {r4,lr}
	movs r4, 0
_0809648C:
	lsls r0, r4, 24
	lsrs r0, 24
	bl ResetMailboxSlot
	adds r4, 0x1
	cmp r4, 0x3
	ble _0809648C
	movs r0, 0
	bl GetMailboxSlotInfo
	movs r2, 0
	movs r1, 0x1
	strb r1, [r0]
	movs r1, 0x62
	strb r1, [r0, 0x4]
	strb r2, [r0, 0x5]
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_8096488

	thumb_func_start sub_80964B4
sub_80964B4:
	push {lr}
	ldr r0, _080964D4
	ldr r0, [r0]
	ldr r1, _080964D8
	adds r0, r1
	ldrb r0, [r0]
	cmp r0, 0
	bne _080964DC
	movs r0, 0x35
	bl sub_8096E80
	lsls r0, 24
	cmp r0, 0
	bne _080964DC
	movs r0, 0
	b _080964DE
	.align 2, 0
_080964D4: .4byte gUnknown_203B490
_080964D8: .4byte 0x00000325
_080964DC:
	movs r0, 0x1
_080964DE:
	pop {r1}
	bx r1
	thumb_func_end sub_80964B4

	thumb_func_start sub_80964E4
sub_80964E4:
	push {lr}
	ldr r0, _08096504
	ldr r0, [r0]
	ldr r1, _08096508
	adds r0, r1
	ldrb r0, [r0]
	cmp r0, 0
	bne _0809650C
	movs r0, 0x36
	bl sub_8096E80
	lsls r0, 24
	cmp r0, 0
	bne _0809650C
	movs r0, 0
	b _0809650E
	.align 2, 0
_08096504: .4byte gUnknown_203B490
_08096508: .4byte 0x00000326
_0809650C:
	movs r0, 0x1
_0809650E:
	pop {r1}
	bx r1
	thumb_func_end sub_80964E4

	thumb_func_start sub_8096514
sub_8096514:
	push {r4,r5,lr}
	movs r5, 0
	movs r4, 0
_0809651A:
	lsls r0, r4, 24
	lsrs r0, 24
	bl IsPelliperBoardSlotEmpty
	lsls r0, 24
	cmp r0, 0
	bne _0809652A
	adds r5, 0x1
_0809652A:
	adds r4, 0x1
	cmp r4, 0x7
	ble _0809651A
	adds r0, r5, 0
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_8096514

	thumb_func_start sub_8096538
sub_8096538:
	push {r4,r5,lr}
	adds r4, r0, 0
	movs r3, 0
	ldr r5, _08096560
	movs r2, 0
_08096542:
	ldr r0, [r5]
	adds r0, r2
	adds r1, r0, 0
	adds r1, 0x50
	ldrb r0, [r1]
	cmp r0, 0
	bne _08096564
	adds r0, r4, 0
	ldm r0!, {r2-r4}
	stm r1!, {r2-r4}
	ldm r0!, {r2,r3}
	stm r1!, {r2,r3}
	movs r0, 0
	b _0809656E
	.align 2, 0
_08096560: .4byte gUnknown_203B490
_08096564:
	adds r2, 0x14
	adds r3, 0x1
	cmp r3, 0x7
	ble _08096542
	movs r0, 0x1
_0809656E:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_8096538

	thumb_func_start GetPelliperBoardSlotInfo
GetPelliperBoardSlotInfo:
	lsls r0, 24
	lsrs r0, 24
	ldr r2, _08096588
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 2
	adds r1, 0x50
	ldr r0, [r2]
	adds r0, r1
	bx lr
	.align 2, 0
_08096588: .4byte gUnknown_203B490
	thumb_func_end GetPelliperBoardSlotInfo

	thumb_func_start IsPelliperBoardSlotEmpty
IsPelliperBoardSlotEmpty:
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	ldr r1, _080965AC
	ldr r2, [r1]
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 2
	adds r2, r1
	adds r2, 0x50
	ldrb r0, [r2]
	cmp r0, 0
	beq _080965B0
	movs r0, 0
	b _080965B2
	.align 2, 0
_080965AC: .4byte gUnknown_203B490
_080965B0:
	movs r0, 0x1
_080965B2:
	pop {r1}
	bx r1
	thumb_func_end IsPelliperBoardSlotEmpty

	thumb_func_start ResetPelliperBoardSlot
ResetPelliperBoardSlot:
	push {r4,lr}
	lsls r0, 24
	lsrs r0, 24
	ldr r4, _080965F0
	ldr r1, [r4]
	lsls r2, r0, 2
	adds r2, r0
	lsls r2, 2
	adds r1, r2
	adds r1, 0x50
	movs r3, 0
	strb r3, [r1]
	ldr r0, [r4]
	adds r0, r2
	adds r0, 0x54
	movs r1, 0x63
	strb r1, [r0]
	ldr r0, [r4]
	adds r0, r2
	adds r0, 0x55
	strb r3, [r0]
	ldr r0, [r4]
	adds r0, r2
	adds r0, 0x61
	strb r3, [r0]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080965F0: .4byte gUnknown_203B490
	thumb_func_end ResetPelliperBoardSlot

	thumb_func_start sub_80965F4
sub_80965F4:
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	movs r2, 0
	movs r3, 0
	ldr r0, _0809660C
	mov r12, r0
	mov r8, r3
	movs r4, 0
	mov r9, r4
	b _08096636
	.align 2, 0
_0809660C: .4byte gUnknown_203B490
_08096610:
	cmp r2, r3
	ble _0809662A
	mov r1, r12
	ldr r0, [r1]
	mov r5, r8
	adds r1, r0, r5
	adds r0, r4
	adds r1, 0x50
	adds r0, 0x50
	ldm r0!, {r5-r7}
	stm r1!, {r5-r7}
	ldm r0!, {r6,r7}
	stm r1!, {r6,r7}
_0809662A:
	adds r4, 0x14
	movs r0, 0x14
	add r9, r0
	adds r2, 0x1
	add r8, r0
	adds r3, 0x1
_08096636:
	cmp r2, 0x7
	bgt _08096666
	mov r1, r12
	ldr r0, [r1]
	adds r0, r4
	adds r0, 0x50
	ldrb r0, [r0]
	cmp r0, 0
	bne _08096666
	ldr r6, _08096694
	mov r1, r9
_0809664C:
	adds r1, 0x14
	adds r4, 0x14
	movs r5, 0x14
	add r9, r5
	adds r2, 0x1
	cmp r2, 0x7
	bgt _08096666
	ldr r0, [r6]
	adds r0, r1
	adds r0, 0x50
	ldrb r0, [r0]
	cmp r0, 0
	beq _0809664C
_08096666:
	cmp r2, 0x8
	bne _08096610
	cmp r3, 0x7
	bgt _08096688
	ldr r4, _08096694
	movs r2, 0
	lsls r0, r3, 2
	adds r0, r3
	lsls r1, r0, 2
_08096678:
	ldr r0, [r4]
	adds r0, r1
	adds r0, 0x50
	strb r2, [r0]
	adds r1, 0x14
	adds r3, 0x1
	cmp r3, 0x7
	ble _08096678
_08096688:
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_08096694: .4byte gUnknown_203B490
	thumb_func_end sub_80965F4

        .align 2,0
