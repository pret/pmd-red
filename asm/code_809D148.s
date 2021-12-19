	#include "asm/constants/gba_constants.inc"
	#include "asm/macros.inc"

	.syntax unified

	.text

	thumb_func_start sub_809D25C
sub_809D25C:
	push {r4-r6,lr}
	sub sp, 0x24
	ldr r4, _0809D274
	ldr r0, [r4]
	cmp r0, 0x2
	beq _0809D28C
	cmp r0, 0x2
	bhi _0809D278
	cmp r0, 0x1
	beq _0809D27E
	b _0809D2B2
	.align 2, 0
_0809D274: .4byte gUnknown_20399E8
_0809D278:
	cmp r0, 0x3
	beq _0809D29A
	b _0809D2B2
_0809D27E:
	movs r1, 0x4
	ldrsh r0, [r4, r1]
	adds r1, r4, 0
	adds r1, 0x1C
	bl sub_80A8FD8
	b _0809D2A6
_0809D28C:
	movs r1, 0x4
	ldrsh r0, [r4, r1]
	adds r1, r4, 0
	adds r1, 0x1C
	bl sub_80AC448
	b _0809D2A6
_0809D29A:
	movs r1, 0x4
	ldrsh r0, [r4, r1]
	adds r1, r4, 0
	adds r1, 0x1C
	bl sub_80AD360
_0809D2A6:
	lsls r0, 16
	ldr r1, _0809D2C4
	cmp r0, r1
	bne _0809D2B2
	movs r0, 0
	str r0, [r4]
_0809D2B2:
	ldr r4, _0809D2C8
	ldr r0, [r4, 0x8]
	cmp r0, 0x2
	beq _0809D356
	cmp r0, 0x2
	bhi _0809D2CC
	cmp r0, 0x1
	beq _0809D2D2
	b _0809D388
	.align 2, 0
_0809D2C4: .4byte 0xffff0000
_0809D2C8: .4byte gUnknown_20399E8
_0809D2CC:
	cmp r0, 0x3
	beq _0809D314
	b _0809D388
_0809D2D2:
	ldr r0, [r4, 0x1C]
	ldr r1, [r4, 0x14]
	subs r0, r1
	str r0, [sp, 0x4]
	ldr r0, [r4, 0x20]
	ldr r1, [r4, 0x18]
	subs r0, r1
	str r0, [sp, 0x8]
	ldr r1, [r4, 0xC]
	add r0, sp, 0x4
	bl sub_800290C
	ldr r0, [sp, 0x4]
	cmp r0, 0
	bne _0809D2FA
	ldr r0, [sp, 0x8]
	cmp r0, 0
	bne _0809D2FA
	str r0, [r4, 0x8]
	b _0809D392
_0809D2FA:
	ldr r2, _0809D310
	ldr r0, [r2, 0x14]
	ldr r1, [sp, 0x4]
	adds r0, r1
	str r0, [r2, 0x14]
	ldr r0, [r2, 0x18]
	ldr r1, [sp, 0x8]
	adds r0, r1
	str r0, [r2, 0x18]
	b _0809D392
	.align 2, 0
_0809D310: .4byte gUnknown_20399E8
_0809D314:
	ldr r1, [r4, 0x1C]
	ldr r0, [r4, 0x14]
	subs r0, r1, r0
	cmp r0, 0
	bge _0809D320
	adds r0, 0xFF
_0809D320:
	asrs r2, r0, 8
	ldr r1, [r4, 0x20]
	ldr r0, [r4, 0x18]
	subs r1, r0
	cmp r1, 0
	bge _0809D32E
	adds r1, 0xFF
_0809D32E:
	asrs r1, 8
	lsls r0, r2, 8
	lsls r1, 8
	bl sub_8009FB8
	cmp r0, 0
	bge _0809D33E
	adds r0, 0xFF
_0809D33E:
	asrs r0, 8
	lsls r0, 8
	ldr r1, [r4, 0xC]
	bl __divsi3
	str r0, [r4, 0x10]
	cmp r0, 0
	bgt _0809D352
	movs r0, 0x1
	str r0, [r4, 0x10]
_0809D352:
	movs r0, 0x2
	str r0, [r4, 0x8]
_0809D356:
	add r0, sp, 0xC
	ldr r1, _0809D384
	adds r2, r1, 0
	adds r2, 0x8
	adds r5, r1, 0
	subs r5, 0x14
	ldr r3, [r5, 0x10]
	movs r4, 0x1
	str r4, [sp]
	bl sub_8002934
	ldr r0, [sp, 0xC]
	ldr r1, [sp, 0x10]
	str r0, [r5, 0x14]
	str r1, [r5, 0x18]
	ldr r0, [r5, 0x10]
	subs r0, 0x1
	str r0, [r5, 0x10]
	cmp r0, 0
	bgt _0809D392
	movs r0, 0
	str r0, [r5, 0x8]
	b _0809D392
	.align 2, 0
_0809D384: .4byte gUnknown_20399FC
_0809D388:
	ldr r2, _0809D3A4
	ldr r0, [r2, 0x1C]
	ldr r1, [r2, 0x20]
	str r0, [r2, 0x14]
	str r1, [r2, 0x18]
_0809D392:
	ldr r5, _0809D3A4
	ldr r0, [r5, 0x24]
	cmp r0, 0x1
	beq _0809D3A8
	cmp r0, 0x2
	beq _0809D3D2
	movs r0, 0
	str r0, [r5, 0x34]
	b _0809D402
	.align 2, 0
_0809D3A4: .4byte gUnknown_20399E8
_0809D3A8:
	ldr r0, [r5, 0x30]
	subs r0, 0x1
	str r0, [r5, 0x30]
	cmp r0, 0
	bgt _0809D404
	movs r0, 0x4
	str r0, [r5, 0x30]
	movs r4, 0x2
	negs r4, r4
	adds r0, r4, 0
	movs r1, 0x2
	bl OtherRandomRange
	lsls r0, 10
	str r0, [r5, 0x34]
	adds r0, r4, 0
	movs r1, 0x2
	bl OtherRandomRange
	lsls r0, 10
	b _0809D402
_0809D3D2:
	ldr r0, [r5, 0x30]
	subs r0, 0x1
	str r0, [r5, 0x30]
	cmp r0, 0
	bgt _0809D404
	ldr r0, [r5, 0x2C]
	str r0, [r5, 0x30]
	movs r4, 0x2
	negs r4, r4
	adds r0, r4, 0
	movs r1, 0x2
	bl OtherRandomRange
	ldr r1, [r5, 0x28]
	muls r0, r1
	lsls r0, 8
	str r0, [r5, 0x34]
	adds r0, r4, 0
	movs r1, 0x2
	bl OtherRandomRange
	ldr r1, [r5, 0x28]
	muls r0, r1
	lsls r0, 8
_0809D402:
	str r0, [r5, 0x38]
_0809D404:
	add r5, sp, 0x14
	add r6, sp, 0x1C
	adds r0, r5, 0
	adds r1, r6, 0
	bl sub_80A579C
	lsls r0, 24
	cmp r0, 0
	beq _0809D474
	ldr r4, _0809D47C
	ldr r0, [r4, 0x14]
	ldr r1, [r4, 0x34]
	adds r0, r1
	adds r2, r0, 0
	subs r2, 0x80
	ldr r0, [r4, 0x18]
	ldr r1, [r4, 0x38]
	adds r0, r1
	ldr r1, _0809D480
	adds r3, r0, r1
	ldr r0, [sp, 0x14]
	cmp r2, r0
	bge _0809D434
	adds r2, r0, 0
_0809D434:
	ldr r0, [sp, 0x1C]
	cmp r2, r0
	blt _0809D43C
	subs r2, r0, 0x1
_0809D43C:
	ldr r0, [r5, 0x4]
	cmp r3, r0
	bge _0809D444
	adds r3, r0, 0
_0809D444:
	ldr r1, [r6, 0x4]
	cmp r3, r1
	blt _0809D44C
	subs r3, r1, 0x1
_0809D44C:
	ldr r1, _0809D484
	adds r0, r2, r1
	cmp r0, 0
	bge _0809D458
	adds r1, 0xFF
	adds r0, r2, r1
_0809D458:
	asrs r0, 8
	str r0, [r4, 0x3C]
	ldr r1, _0809D488
	adds r0, r3, r1
	cmp r0, 0
	bge _0809D468
	adds r1, 0xFF
	adds r0, r3, r1
_0809D468:
	asrs r0, 8
	str r0, [r4, 0x40]
	adds r1, r4, 0
	adds r1, 0x44
	movs r0, 0x1
	strb r0, [r1]
_0809D474:
	add sp, 0x24
	pop {r4-r6}
	pop {r0}
	bx r0
	.align 2, 0
_0809D47C: .4byte gUnknown_20399E8
_0809D480: .4byte 0xfffff480
_0809D484: .4byte 0xffff8700
_0809D488: .4byte 0xffffb000
	thumb_func_end sub_809D25C

	thumb_func_start nullsub_120
nullsub_120:
	bx lr
	thumb_func_end nullsub_120

	thumb_func_start sub_809D490
sub_809D490:
	push {r4,lr}
	ldr r4, _0809D4AC
	movs r0, 0x80
	lsls r0, 3
	movs r1, 0x6
	bl MemoryAlloc
	str r0, [r4]
	bl sub_809D4B0
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0809D4AC: .4byte gUnknown_203B4B0
	thumb_func_end sub_809D490

	thumb_func_start sub_809D4B0
sub_809D4B0:
	push {r4,r5,lr}
	ldr r0, _0809D4EC
	movs r2, 0x1
	negs r2, r2
	adds r1, r2, 0
	strh r1, [r0]
	ldr r0, _0809D4F0
	strh r1, [r0]
	ldr r0, _0809D4F4
	strh r1, [r0]
	ldr r1, _0809D4F8
	movs r0, 0
	strb r0, [r1]
	movs r1, 0
	ldr r5, _0809D4FC
	movs r2, 0
	ldr r3, _0809D500
	ldr r4, _0809D504
_0809D4D4:
	adds r0, r1, r5
	strb r2, [r0]
	adds r0, r1, r3
	strb r2, [r0]
	stm r4!, {r2}
	adds r1, 0x1
	cmp r1, 0x80
	ble _0809D4D4
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_0809D4EC: .4byte gUnknown_2039A30
_0809D4F0: .4byte gUnknown_2039A32
_0809D4F4: .4byte gUnknown_2039A34
_0809D4F8: .4byte gUnknown_2039A36
_0809D4FC: .4byte gUnknown_2039A38
_0809D500: .4byte gUnknown_2039AC0
_0809D504: .4byte gUnknown_2039B48
	thumb_func_end sub_809D4B0

	thumb_func_start sub_809D508
sub_809D508:
	push {r4,lr}
	ldr r4, _0809D51C
	ldr r0, [r4]
	bl MemoryFree
	movs r0, 0
	str r0, [r4]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0809D51C: .4byte gUnknown_203B4B0
	thumb_func_end sub_809D508

	thumb_func_start sub_809D520
sub_809D520:
	ldr r1, _0809D528
	strh r1, [r0]
	bx lr
	.align 2, 0
_0809D528: .4byte 0x0000ffff
	thumb_func_end sub_809D520

	thumb_func_start sub_809D52C
sub_809D52C:
	push {lr}
	movs r2, 0
	ldrsh r1, [r0, r2]
	cmp r1, 0x1
	beq _0809D544
	cmp r1, 0x1
	ble _0809D562
	cmp r1, 0x2
	beq _0809D54E
	cmp r1, 0x3
	beq _0809D558
	b _0809D562
_0809D544:
	movs r1, 0x2
	ldrsh r0, [r0, r1]
	bl sub_80A882C
	b _0809D564
_0809D54E:
	movs r2, 0x2
	ldrsh r0, [r0, r2]
	bl sub_80AC240
	b _0809D564
_0809D558:
	movs r1, 0x2
	ldrsh r0, [r0, r1]
	bl sub_80AD158
	b _0809D564
_0809D562:
	movs r0, 0
_0809D564:
	pop {r1}
	bx r1
	thumb_func_end sub_809D52C

	thumb_func_start sub_809D568
sub_809D568:
	push {lr}
	adds r3, r0, 0
	ldr r0, _0809D5B4
	strh r0, [r3]
	movs r2, 0
	movs r0, 0
	strh r0, [r3, 0x2]
	str r0, [r3, 0x8]
	str r0, [r3, 0x4]
	str r0, [r3, 0x14]
	str r0, [r3, 0x10]
	adds r1, r3, 0
	adds r1, 0x20
	strb r2, [r1]
	str r0, [r3, 0x1C]
	movs r1, 0x1
	negs r1, r1
	strh r1, [r3, 0x22]
	strh r0, [r3, 0x24]
	adds r2, r3, 0
	adds r2, 0x26
	movs r1, 0xFF
	strb r1, [r2]
	strh r0, [r3, 0x28]
	strh r0, [r3, 0x2A]
	strh r0, [r3, 0x2C]
	str r0, [r3, 0x30]
	movs r2, 0
	movs r1, 0x3
	adds r0, r3, 0
	adds r0, 0x5C
_0809D5A6:
	str r2, [r0]
	subs r0, 0x4
	subs r1, 0x1
	cmp r1, 0
	bge _0809D5A6
	pop {r0}
	bx r0
	.align 2, 0
_0809D5B4: .4byte 0x0000ffff
	thumb_func_end sub_809D568

	thumb_func_start sub_809D5B8
sub_809D5B8:
	push {r4,lr}
	adds r4, r0, 0
	movs r0, 0
	str r0, [r4]
	str r0, [r4, 0x4]
	ldr r0, _0809D5FC
	strh r0, [r4, 0x10]
	movs r0, 0xFF
	strb r0, [r4, 0x12]
	adds r0, r4, 0
	adds r0, 0xC
	bl sub_809D520
	movs r2, 0
	movs r1, 0x3
	adds r0, r4, 0
	adds r0, 0x20
_0809D5DA:
	str r2, [r0]
	subs r0, 0x4
	subs r1, 0x1
	cmp r1, 0
	bge _0809D5DA
	adds r0, r4, 0
	adds r0, 0x24
	bl sub_809D568
	adds r0, r4, 0
	adds r0, 0x84
	bl sub_809D568
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0809D5FC: .4byte 0x0000ffff
	thumb_func_end sub_809D5B8

	thumb_func_start sub_809D600
sub_809D600:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	adds r7, r0, 0
	adds r6, r1, 0
	mov r8, r2
	adds r4, r3, 0
	ldr r5, [sp, 0x18]
	lsls r4, 16
	asrs r4, 16
	lsls r5, 24
	asrs r5, 24
	bl sub_809D5B8
	str r6, [r7]
	mov r0, r8
	str r0, [r7, 0x4]
	strh r4, [r7, 0x10]
	strb r5, [r7, 0x12]
	ldrh r0, [r6]
	strh r0, [r7, 0x8]
	ldr r1, [r6, 0x4]
	cmp r1, 0
	beq _0809D63A
	mov r0, r8
	bl _call_via_r1
	strh r0, [r7, 0xA]
	b _0809D63C
_0809D63A:
	strh r1, [r7, 0xA]
_0809D63C:
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_809D600

	thumb_func_start sub_809D648
sub_809D648:
	push {lr}
	bl sub_809D5B8
	pop {r0}
	bx r0
	thumb_func_end sub_809D648

	thumb_func_start sub_809D654
sub_809D654:
	movs r1, 0x26
	ldrsh r0, [r0, r1]
	bx lr
	thumb_func_end sub_809D654

	thumb_func_start sub_809D65C
sub_809D65C:
	push {lr}
	adds r1, r0, 0
	movs r2, 0x26
	ldrsh r0, [r1, r2]
	cmp r0, 0
	bne _0809D66E
	movs r0, 0x1
	negs r0, r0
	b _0809D672
_0809D66E:
	movs r2, 0x24
	ldrsh r0, [r1, r2]
_0809D672:
	pop {r1}
	bx r1
	thumb_func_end sub_809D65C

	thumb_func_start sub_809D678
sub_809D678:
	movs r2, 0x26
	ldrsh r1, [r0, r2]
	negs r0, r1
	orrs r0, r1
	lsrs r0, 31
	bx lr
	thumb_func_end sub_809D678

	thumb_func_start sub_809D684
sub_809D684:
	push {lr}
	adds r2, r0, 0
	adds r3, r1, 0
	movs r1, 0x26
	ldrsh r0, [r2, r1]
	cmp r0, 0
	beq _0809D6A4
	ldr r0, [r2, 0x34]
	cmp r0, 0
	beq _0809D69C
	ldr r1, [r2, 0x38]
	b _0809D69E
_0809D69C:
	ldr r1, [r2, 0x2C]
_0809D69E:
	ldr r0, [r3]
	cmp r1, r0
	beq _0809D6CC
_0809D6A4:
	adds r0, r2, 0
	adds r0, 0x86
	movs r1, 0
	ldrsh r0, [r0, r1]
	cmp r0, 0
	beq _0809D6D0
	adds r0, r2, 0
	adds r0, 0x94
	ldr r0, [r0]
	cmp r0, 0
	beq _0809D6C0
	adds r0, r2, 0
	adds r0, 0x98
	b _0809D6C4
_0809D6C0:
	adds r0, r2, 0
	adds r0, 0x8C
_0809D6C4:
	ldr r1, [r0]
	ldr r0, [r3]
	cmp r1, r0
	bne _0809D6D0
_0809D6CC:
	movs r0, 0x1
	b _0809D6D2
_0809D6D0:
	movs r0, 0
_0809D6D2:
	pop {r1}
	bx r1
	thumb_func_end sub_809D684

	thumb_func_start sub_809D6D8
sub_809D6D8:
	lsls r1, 16
	asrs r1, 14
	adds r0, 0x14
	adds r0, r1
	str r2, [r0]
	bx lr
	thumb_func_end sub_809D6D8

	thumb_func_start sub_809D6E4
sub_809D6E4:
	push {r4,lr}
	lsls r2, 16
	asrs r2, 16
	lsls r4, r2, 2
	adds r3, r0, 0
	adds r3, 0x14
	adds r3, r4
	ldr r3, [r3]
	str r3, [r1]
	strh r2, [r1, 0x4]
	ldrh r2, [r0, 0x10]
	strh r2, [r1, 0x6]
	ldrb r0, [r0, 0x12]
	strb r0, [r1, 0x8]
	adds r0, r3, 0
	cmp r0, 0
	beq _0809D708
	movs r0, 0x1
_0809D708:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_809D6E4

	thumb_func_start sub_809D710
sub_809D710:
	push {r4,lr}
	adds r4, r0, 0
	adds r3, r1, 0
	lsls r2, 16
	asrs r2, 16
	ldr r1, _0809D73C
	lsls r0, r2, 1
	adds r0, r2
	lsls r0, 2
	adds r1, 0x8
	adds r0, r1
	ldr r0, [r0]
	str r0, [r3]
	movs r0, 0x2
	strh r0, [r3, 0x4]
	cmp r4, 0
	beq _0809D740
	ldrh r0, [r4, 0x10]
	strh r0, [r3, 0x6]
	ldrb r0, [r4, 0x12]
	b _0809D746
	.align 2, 0
_0809D73C: .4byte gFunctionScriptTable
_0809D740:
	ldr r0, _0809D750
	strh r0, [r3, 0x6]
	movs r0, 0xFF
_0809D746:
	strb r0, [r3, 0x8]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0809D750: .4byte 0x0000ffff
	thumb_func_end sub_809D710

	thumb_func_start sub_809D754
sub_809D754:
	push {r4,lr}
	adds r4, r0, 0
	adds r0, 0x24
	bl sub_809D568
	adds r4, 0x84
	adds r0, r4, 0
	bl sub_809D568
	movs r0, 0x1
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_809D754

	thumb_func_start sub_809D770
sub_809D770:
	push {r4,lr}
	adds r4, r0, 0
	adds r0, 0x24
	bl sub_809D568
	adds r0, r4, 0
	adds r0, 0x84
	bl sub_809D568
	movs r0, 0x4
	strh r0, [r4, 0x26]
	movs r0, 0x1
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_809D770

        .align 2,0
