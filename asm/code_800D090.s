	#include "asm/constants/gba_constants.inc"
	#include "asm/macros.inc"

	.syntax unified

	.text

	thumb_func_start sub_800D224
sub_800D224:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x4
	str r0, [sp]
	movs r6, 0
	ldr r0, _0800D280
	mov r12, r0
	ldr r1, _0800D284
	mov r10, r1
	movs r2, 0x2
	mov r9, r2
_0800D240:
	ldr r1, [sp]
	asrs r1, r6
	movs r0, 0x1
	ands r1, r0
	adds r3, r6, 0x1
	mov r8, r3
	cmp r1, 0
	beq _0800D2CE
	lsls r0, r6, 2
	ldr r1, _0800D288
	adds r2, r0, r1
	ldr r1, [r2]
	adds r5, r0, 0
	cmp r1, 0x1
	bne _0800D2CE
	lsls r0, r6, 5
	adds r0, r6
	lsls r0, 3
	ldr r1, _0800D28C
	adds r7, r0, r1
	movs r4, 0
	mov r3, r12
	adds r0, r5, r3
	ldr r1, [r0]
	mov r3, r10
	ldr r0, [r3]
	lsrs r0, 1
	cmp r1, r0
	bcc _0800D290
	mov r0, r9
	str r0, [r2]
	b _0800D2C4
	.align 2, 0
_0800D280: .4byte gUnknown_202DB58
_0800D284: .4byte gUnknown_202DB74
_0800D288: .4byte gUnknown_202DB60
_0800D28C: .4byte gUnknown_202D910
_0800D290:
	mov r1, r12
	adds r0, r5, r1
	ldr r3, [r0]
	adds r2, r3, r4
	lsls r2, 1
	adds r2, r7
	lsls r0, r4, 1
	lsls r1, r6, 4
	adds r0, r1
	ldr r1, _0800D2E4
	adds r0, r1
	ldrh r0, [r0]
	strh r0, [r2]
	adds r4, 0x1
	cmp r4, 0x7
	bhi _0800D2C4
	adds r1, r3, r4
	mov r2, r10
	ldr r0, [r2]
	lsrs r0, 1
	cmp r1, r0
	bcc _0800D290
	ldr r3, _0800D2E8
	adds r0, r5, r3
	mov r1, r9
	str r1, [r0]
_0800D2C4:
	mov r2, r12
	adds r1, r5, r2
	ldr r0, [r1]
	adds r0, 0x8
	str r0, [r1]
_0800D2CE:
	mov r6, r8
	cmp r6, 0x1
	ble _0800D240
	add sp, 0x4
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_0800D2E4: .4byte gUnknown_202DB30
_0800D2E8: .4byte gUnknown_202DB60
	thumb_func_end sub_800D224

	thumb_func_start sub_800D2EC
sub_800D2EC:
	push {r4-r7,lr}
	ldr r0, _0800D318
	mov r12, r0
	ldr r3, _0800D31C
	adds r7, r3, 0
	ldr r6, _0800D320
	ldr r2, _0800D324
	adds r5, r2, 0
	adds r5, 0xE
	ldr r4, _0800D328
_0800D300:
	ldr r0, [r4]
	lsrs r0, 1
	ldr r1, [r7]
	cmp r1, r0
	bcs _0800D32C
	lsls r0, r1, 1
	add r0, r12
	ldrh r0, [r0]
	strh r0, [r2]
	adds r0, r1, 0x1
	str r0, [r3]
	b _0800D32E
	.align 2, 0
_0800D318: .4byte gUnknown_202D808
_0800D31C: .4byte gUnknown_202DB50
_0800D320: .4byte 0x0000fcfc
_0800D324: .4byte gUnknown_202DB20
_0800D328: .4byte gUnknown_202DB74
_0800D32C:
	strh r6, [r2]
_0800D32E:
	adds r2, 0x2
	cmp r2, r5
	bls _0800D300
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_800D2EC

	thumb_func_start sub_800D33C
sub_800D33C:
	push {r4,r5,lr}
	movs r5, 0
	ldr r1, _0800D370
	ldr r4, _0800D374
	ldr r0, [r4]
	str r0, [r1]
	ldr r0, _0800D378
	ldr r1, _0800D37C
	bl sub_800D820
	adds r2, r0, 0
	str r2, [r4]
	ldr r1, _0800D380
	ldrb r0, [r1]
	cmp r0, 0
	bne _0800D384
	movs r0, 0x80
	lsls r0, 1
	ands r0, r2
	cmp r0, 0
	beq _0800D36A
	movs r0, 0x1
	strb r0, [r1]
_0800D36A:
	movs r0, 0
	b _0800D40E
	.align 2, 0
_0800D370: .4byte gUnknown_202DB6C
_0800D374: .4byte gUnknown_202DB68
_0800D378: .4byte gUnknown_202DB20
_0800D37C: .4byte gUnknown_202DB30
_0800D380: .4byte gUnknown_202DB70
_0800D384:
	movs r0, 0x80
	lsls r0, 5
	ands r0, r2
	cmp r0, 0
	beq _0800D392
	movs r0, 0x3
	b _0800D40E
_0800D392:
	movs r0, 0x80
	lsls r0, 6
	ands r0, r2
	cmp r0, 0
	beq _0800D3A0
	movs r0, 0x4
	b _0800D40E
_0800D3A0:
	movs r0, 0x80
	lsls r0, 8
	ands r0, r2
	cmp r0, 0
	beq _0800D3BA
	lsls r1, r2, 28
	lsrs r1, 28
	lsls r0, r2, 20
	lsrs r0, 28
	cmp r1, r0
	beq _0800D3BA
	movs r0, 0x5
	b _0800D40E
_0800D3BA:
	ldr r4, _0800D3F8
	ldr r0, _0800D3FC
	ldr r2, [r4]
	ldr r0, [r0]
	orrs r0, r2
	movs r1, 0xE
	ands r0, r1
	cmp r0, 0
	beq _0800D40C
	ldr r0, _0800D400
	ldr r1, [r0]
	lsls r1, 26
	lsrs r1, 30
	movs r0, 0x1
	lsls r0, r1
	ands r2, r0
	cmp r2, 0
	beq _0800D40C
	bl sub_800D1E0
	ldr r0, [r4]
	bl sub_800D224
	ldr r0, [r4]
	bl sub_800D1C0
	lsls r0, 24
	cmp r0, 0
	beq _0800D404
	movs r0, 0x2
	b _0800D40E
	.align 2, 0
_0800D3F8: .4byte gUnknown_202DB68
_0800D3FC: .4byte gUnknown_202DB6C
_0800D400: .4byte 0x04000128
_0800D404:
	ldr r0, [r4]
	bl sub_800D2EC
	movs r5, 0x1
_0800D40C:
	adds r0, r5, 0
_0800D40E:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_800D33C

	thumb_func_start sub_800D414
sub_800D414:
	push {r4,lr}
	ldr r0, _0800D468
	movs r4, 0
	str r4, [r0]
	ldr r0, _0800D46C
	str r4, [r0]
	ldr r0, _0800D470
	strb r4, [r0]
	ldr r0, _0800D474
	str r4, [r0]
	ldr r0, _0800D478
	str r4, [r0]
	str r4, [r0, 0x4]
	ldr r0, _0800D47C
	movs r1, 0x10
	bl MemoryClear16
	ldr r0, _0800D480
	movs r1, 0x20
	bl MemoryClear16
	ldr r0, _0800D484
	str r4, [r0]
	ldr r0, _0800D488
	str r4, [r0]
	str r4, [r0, 0x4]
	ldr r0, _0800D48C
	movs r1, 0x84
	lsls r1, 1
	bl MemoryClear16
	ldr r0, _0800D490
	movs r1, 0x84
	lsls r1, 2
	bl MemoryClear16
	bl sub_800D6AC
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0800D468: .4byte gUnknown_202DB68
_0800D46C: .4byte gUnknown_202DB6C
_0800D470: .4byte gUnknown_202DB70
_0800D474: .4byte gUnknown_202DB74
_0800D478: .4byte gUnknown_202DB60
_0800D47C: .4byte gUnknown_202DB20
_0800D480: .4byte gUnknown_202DB30
_0800D484: .4byte gUnknown_202DB50
_0800D488: .4byte gUnknown_202DB58
_0800D48C: .4byte gUnknown_202D808
_0800D490: .4byte gUnknown_202D910
	thumb_func_end sub_800D414

	thumb_func_start sub_800D494
sub_800D494:
	push {r4,lr}
	ldr r0, _0800D4E4
	movs r4, 0
	str r4, [r0]
	ldr r0, _0800D4E8
	str r4, [r0]
	ldr r0, _0800D4EC
	strb r4, [r0]
	ldr r0, _0800D4F0
	str r4, [r0]
	ldr r0, _0800D4F4
	str r4, [r0]
	str r4, [r0, 0x4]
	ldr r0, _0800D4F8
	movs r1, 0x10
	bl MemoryClear16
	ldr r0, _0800D4FC
	movs r1, 0x20
	bl MemoryClear16
	ldr r0, _0800D500
	str r4, [r0]
	ldr r0, _0800D504
	str r4, [r0]
	str r4, [r0, 0x4]
	ldr r0, _0800D508
	movs r1, 0x84
	lsls r1, 1
	bl MemoryClear16
	ldr r0, _0800D50C
	movs r1, 0x84
	lsls r1, 2
	bl MemoryClear16
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0800D4E4: .4byte gUnknown_202DB68
_0800D4E8: .4byte gUnknown_202DB6C
_0800D4EC: .4byte gUnknown_202DB70
_0800D4F0: .4byte gUnknown_202DB74
_0800D4F4: .4byte gUnknown_202DB60
_0800D4F8: .4byte gUnknown_202DB20
_0800D4FC: .4byte gUnknown_202DB30
_0800D500: .4byte gUnknown_202DB50
_0800D504: .4byte gUnknown_202DB58
_0800D508: .4byte gUnknown_202D808
_0800D50C: .4byte gUnknown_202D910
	thumb_func_end sub_800D494

	thumb_func_start sub_800D510
sub_800D510:
	ldr r1, _0800D51C
	movs r2, 0x80
	lsls r2, 8
	adds r0, r2, 0
	strh r0, [r1]
	bx lr
	.align 2, 0
_0800D51C: .4byte 0x04000134
	thumb_func_end sub_800D510

	thumb_func_start sub_800D520
sub_800D520:
	push {r4,r5,lr}
	sub sp, 0x4
	mov r1, sp
	movs r0, 0x1
	strh r0, [r1]
	ldr r0, _0800D568
	ldrb r1, [r0]
	movs r0, 0x30
	ands r0, r1
	cmp r0, 0
	bne _0800D55C
	mov r1, sp
	mov r0, sp
	ldrh r0, [r0]
	subs r0, 0x1
	strh r0, [r1]
	ldrh r0, [r1]
	ldr r1, _0800D56C
	cmp r0, r1
	beq _0800D55C
	mov r4, sp
	adds r5, r1, 0
_0800D54C:
	bl VBlankIntrWait
	ldrh r0, [r4]
	subs r0, 0x1
	strh r0, [r4]
	ldrh r0, [r4]
	cmp r0, r5
	bne _0800D54C
_0800D55C:
	bl sub_800D7D0
	add sp, 0x4
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_0800D568: .4byte 0x04000128
_0800D56C: .4byte 0x0000ffff
	thumb_func_end sub_800D520

	thumb_func_start sub_800D570
sub_800D570:
	push {lr}
	bl sub_800D7B8
	pop {r0}
	bx r0
	thumb_func_end sub_800D570

	thumb_func_start sub_800D57C
sub_800D57C:
	ldr r0, _0800D584
	ldrb r0, [r0]
	bx lr
	.align 2, 0
_0800D584: .4byte gUnknown_202DB70
	thumb_func_end sub_800D57C

	thumb_func_start sub_800D588
sub_800D588:
	ldr r0, _0800D598
	ldr r0, [r0]
	movs r1, 0x80
	ands r0, r1
	lsls r0, 24
	lsrs r0, 24
	bx lr
	.align 2, 0
_0800D598: .4byte gUnknown_202DB68
	thumb_func_end sub_800D588

	thumb_func_start sub_800D59C
sub_800D59C:
	push {r4-r6,lr}
	adds r3, r0, 0
	adds r2, r1, 0
	movs r5, 0
	ldr r6, _0800D5F4
	ldr r4, _0800D5F8
	adds r0, r2, 0x1
	movs r1, 0x2
	negs r1, r1
	ands r0, r1
	adds r0, 0x8
	str r0, [r4]
	adds r0, r6, 0x4
	adds r1, r3, 0
	bl CpuCopy
	ldr r0, _0800D5FC
	strh r0, [r6]
	strh r5, [r6, 0x2]
	movs r2, 0
	ldr r0, [r4]
	lsrs r0, 1
	subs r0, 0x2
	cmp r5, r0
	bcs _0800D5DE
	adds r3, r0, 0
	adds r1, r6, 0
_0800D5D2:
	ldrh r0, [r1]
	adds r5, r0
	adds r1, 0x2
	adds r2, 0x1
	cmp r2, r3
	bcc _0800D5D2
_0800D5DE:
	ldr r2, _0800D5F4
	mvns r1, r5
	ldr r0, _0800D5F8
	ldr r0, [r0]
	lsrs r0, 1
	subs r1, r0
	strh r1, [r2, 0x2]
	pop {r4-r6}
	pop {r0}
	bx r0
	.align 2, 0
_0800D5F4: .4byte gUnknown_202D808
_0800D5F8: .4byte gUnknown_202DB74
_0800D5FC: .4byte 0x0000fdfd
	thumb_func_end sub_800D59C

	thumb_func_start sub_800D600
sub_800D600:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	movs r6, 0
	ldr r0, _0800D64C
	mov r8, r0
	ldr r7, _0800D650
	ldr r0, [r7]
	lsrs r0, 1
	subs r0, 0x2
	mov r12, r0
	movs r5, 0
_0800D618:
	movs r4, 0
	mov r2, r8
	adds r1, r5, r2
	movs r3, 0
	cmp r4, r12
	bcs _0800D636
	ldr r0, [r7]
	lsrs r0, 1
	subs r2, r0, 0x2
_0800D62A:
	ldrh r0, [r1]
	adds r4, r0
	adds r1, 0x2
	adds r3, 0x1
	cmp r3, r2
	bcc _0800D62A
_0800D636:
	ldr r0, [r7]
	lsrs r0, 1
	ldr r2, _0800D654
	adds r1, r2, 0
	subs r1, r0
	lsls r0, r4, 16
	lsls r1, 16
	cmp r0, r1
	beq _0800D658
	movs r0, 0
	b _0800D666
	.align 2, 0
_0800D64C: .4byte gUnknown_202D910
_0800D650: .4byte gUnknown_202DB74
_0800D654: .4byte 0x0000ffff
_0800D658:
	movs r0, 0x84
	lsls r0, 1
	adds r5, r0
	adds r6, 0x1
	cmp r6, 0x1
	bls _0800D618
	movs r0, 0x1
_0800D666:
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_800D600

	thumb_func_start sub_800D670
sub_800D670:
	push {lr}
	adds r3, r1, 0
	lsls r1, r0, 5
	adds r1, r0
	lsls r1, 3
	ldr r0, _0800D688
	adds r1, r0
	adds r0, r3, 0
	bl CpuCopy
	pop {r0}
	bx r0
	.align 2, 0
_0800D688: .4byte gUnknown_202D914
	thumb_func_end sub_800D670

	thumb_func_start sub_800D68C
sub_800D68C:
	push {lr}
	adds r1, r0, 0
	lsls r0, r1, 5
	adds r0, r1
	lsls r0, 3
	ldr r1, _0800D6A8
	adds r0, r1
	movs r2, 0x84
	lsls r2, 1
	movs r1, 0
	bl MemoryFill8
	pop {r0}
	bx r0
	.align 2, 0
_0800D6A8: .4byte gUnknown_202D910
	thumb_func_end sub_800D68C

	thumb_func_start sub_800D6AC
sub_800D6AC:
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	sub sp, 0x4
	ldr r3, _0800D784
	movs r4, 0
	strh r4, [r3]
	ldr r2, _0800D788
	ldrh r1, [r2]
	ldr r0, _0800D78C
	ands r0, r1
	strh r0, [r2]
	movs r0, 0x1
	strh r0, [r3]
	ldr r0, _0800D790
	strh r4, [r0]
	subs r2, 0xD8
	movs r0, 0x80
	lsls r0, 6
	str r0, [r2]
	ldrh r0, [r2]
	ldr r3, _0800D794
	adds r1, r3, 0
	orrs r0, r1
	strh r0, [r2]
	movs r0, 0
	str r0, [sp]
	ldr r4, _0800D798
	ldr r2, _0800D79C
	mov r0, sp
	adds r1, r4, 0
	bl CpuSet
	ldr r0, _0800D7A0
	ldr r1, _0800D7A4
	ldr r2, _0800D7A8
	bl CpuSet
	ldr r0, _0800D7AC
	ldr r1, _0800D7B0
	ldr r2, _0800D7B4
	bl CpuSet
	movs r0, 0x1
	negs r0, r0
	str r0, [r4, 0x14]
	adds r0, r4, 0
	adds r0, 0x60
	str r0, [r4, 0x28]
	adds r0, 0x18
	str r0, [r4, 0x2C]
	movs r3, 0
	adds r5, r4, 0
	adds r5, 0xC0
	movs r2, 0
	movs r7, 0x30
	adds r7, r4
	mov r8, r7
	movs r0, 0x90
	adds r0, r4
	mov r12, r0
	adds r6, r4, 0
	adds r6, 0xA8
	movs r7, 0x40
	adds r7, r4
	mov r9, r7
_0800D732:
	lsls r1, r3, 2
	mov r7, r12
	adds r0, r2, r7
	mov r7, r8
	adds r7, 0x4
	mov r8, r7
	subs r7, 0x4
	stm r7!, {r0}
	adds r0, r2, r6
	mov r7, r9
	adds r7, 0x4
	mov r9, r7
	subs r7, 0x4
	stm r7!, {r0}
	adds r0, r4, 0
	adds r0, 0x50
	adds r1, r0
	str r5, [r1]
	adds r5, 0x48
	adds r2, 0x48
	adds r3, 0x1
	cmp r3, 0x1
	ble _0800D732
	movs r0, 0
	ldr r3, _0800D784
	strh r0, [r3]
	ldr r2, _0800D788
	ldrh r0, [r2]
	movs r1, 0x80
	orrs r0, r1
	strh r0, [r2]
	movs r0, 0x1
	strh r0, [r3]
	add sp, 0x4
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_0800D784: .4byte 0x04000208
_0800D788: .4byte 0x04000200
_0800D78C: .4byte 0x0000ff3f
_0800D790: .4byte 0x04000134
_0800D794: .4byte 0x00004003
_0800D798: .4byte gUnknown_202DCF8
_0800D79C: .4byte 0x05000048
_0800D7A0: .4byte sub_80001E8
_0800D7A4: .4byte gUnknown_202DB78
_0800D7A8: .4byte 0x04000010
_0800D7AC: .4byte sub_8000228
_0800D7B0: .4byte gUnknown_202DBB8
_0800D7B4: .4byte 0x04000050
	thumb_func_end sub_800D6AC

	thumb_func_start sub_800D7B8
sub_800D7B8:
	push {lr}
	ldr r1, _0800D7CC
	ldrb r0, [r1]
	cmp r0, 0
	beq _0800D7C6
	movs r0, 0x1
	strb r0, [r1, 0x8]
_0800D7C6:
	pop {r0}
	bx r0
	.align 2, 0
_0800D7CC: .4byte gUnknown_202DCF8
	thumb_func_end sub_800D7B8

	thumb_func_start sub_800D7D0
sub_800D7D0:
	push {r4,lr}
	ldr r3, _0800D804
	movs r4, 0
	strh r4, [r3]
	ldr r2, _0800D808
	ldrh r1, [r2]
	ldr r0, _0800D80C
	ands r0, r1
	strh r0, [r2]
	movs r0, 0x1
	strh r0, [r3]
	ldr r1, _0800D810
	ldr r2, _0800D814
	adds r0, r2, 0
	strh r0, [r1]
	subs r1, 0x1C
	ldr r0, _0800D818
	str r0, [r1]
	adds r1, 0xF6
	movs r0, 0xC0
	strh r0, [r1]
	ldr r0, _0800D81C
	strb r4, [r0, 0x8]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0800D804: .4byte 0x04000208
_0800D808: .4byte 0x04000200
_0800D80C: .4byte 0x0000ff3f
_0800D810: .4byte 0x04000128
_0800D814: .4byte 0x00002003
_0800D818: .4byte 0x0000b1fc
_0800D81C: .4byte gUnknown_202DCF8
	thumb_func_end sub_800D7D0

	thumb_func_start sub_800D820
sub_800D820:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	mov r8, r0
	mov r12, r1
	ldr r5, _0800D844
	ldr r6, [r5]
	ldr r0, _0800D848
	ldrb r2, [r0, 0x1]
	adds r7, r0, 0
	cmp r2, 0x1
	beq _0800D8AA
	cmp r2, 0x1
	bgt _0800D84C
	cmp r2, 0
	beq _0800D852
	b _0800D8E8
	.align 2, 0
_0800D844: .4byte 0x04000128
_0800D848: .4byte gUnknown_202DCF8
_0800D84C:
	cmp r2, 0x2
	beq _0800D8DC
	b _0800D8E8
_0800D852:
	ldr r1, [r7, 0x14]
	movs r0, 0x1
	negs r0, r0
	cmp r1, r0
	bne _0800D8A6
	movs r0, 0x88
	adds r4, r6, 0
	ands r4, r0
	cmp r4, 0x8
	bne _0800D8E8
	movs r1, 0x4
	adds r0, r6, 0
	ands r0, r1
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0
	bne _0800D8A6
	ldr r3, _0800D8C0
	strh r0, [r3]
	ldr r2, _0800D8C4
	ldrh r1, [r2]
	ldr r0, _0800D8C8
	ands r0, r1
	strh r0, [r2]
	ldrh r0, [r2]
	movs r1, 0x40
	orrs r0, r1
	strh r0, [r2]
	movs r0, 0x1
	strh r0, [r3]
	ldrb r1, [r5, 0x1]
	movs r0, 0x41
	negs r0, r0
	ands r0, r1
	strb r0, [r5, 0x1]
	ldr r1, _0800D8CC
	movs r0, 0xC0
	strh r0, [r1]
	subs r1, 0xF6
	ldr r0, _0800D8D0
	str r0, [r1]
	strb r4, [r7]
_0800D8A6:
	movs r0, 0x1
	strb r0, [r7, 0x1]
_0800D8AA:
	ldr r1, _0800D8D4
	ldrb r0, [r1, 0x2]
	cmp r0, 0
	beq _0800D8DC
	ldrb r0, [r1, 0xA]
	cmp r0, 0x7
	bhi _0800D8D8
	adds r0, 0x1
	strb r0, [r1, 0xA]
	b _0800D8DC
	.align 2, 0
_0800D8C0: .4byte 0x04000208
_0800D8C4: .4byte 0x04000200
_0800D8C8: .4byte 0x0000ff7f
_0800D8CC: .4byte 0x04000202
_0800D8D0: .4byte 0x0000b1fc
_0800D8D4: .4byte gUnknown_202DCF8
_0800D8D8:
	movs r0, 0x2
	strb r0, [r1, 0x1]
_0800D8DC:
	mov r0, r12
	bl sub_800D9B8
	mov r0, r8
	bl sub_800D944
_0800D8E8:
	ldr r1, _0800D908
	ldrb r0, [r1, 0xB]
	adds r0, 0x1
	strb r0, [r1, 0xB]
	ldrb r3, [r1, 0x3]
	ldrb r0, [r1, 0x2]
	lsls r2, r0, 8
	ldrb r0, [r1]
	adds r7, r1, 0
	cmp r0, 0x8
	bne _0800D90C
	movs r0, 0x80
	orrs r0, r2
	orrs r0, r3
	b _0800D910
	.align 2, 0
_0800D908: .4byte gUnknown_202DCF8
_0800D90C:
	adds r0, r3, 0
	orrs r0, r2
_0800D910:
	adds r2, r0, 0
	ldrb r0, [r7, 0x9]
	cmp r0, 0
	beq _0800D91E
	movs r0, 0x80
	lsls r0, 5
	orrs r2, r0
_0800D91E:
	ldrb r0, [r7, 0xA]
	lsrs r0, 3
	lsls r1, r0, 15
	lsls r0, r6, 26
	lsrs r0, 30
	cmp r0, 0x1
	bls _0800D936
	movs r0, 0x80
	lsls r0, 6
	orrs r0, r1
	orrs r0, r2
	b _0800D93A
_0800D936:
	adds r0, r2, 0
	orrs r0, r1
_0800D93A:
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_800D820

	thumb_func_start sub_800D944
sub_800D944:
	push {r4,r5,lr}
	movs r5, 0
	ldr r4, _0800D9AC
	ldr r2, [r4, 0x28]
	ldrb r1, [r4, 0xB]
	strb r1, [r2]
	ldr r3, [r4, 0x28]
	ldrb r1, [r4, 0x2]
	ldrb r2, [r4, 0x3]
	eors r1, r2
	strb r1, [r3, 0x1]
	ldr r1, [r4, 0x28]
	strh r5, [r1, 0x2]
	ldr r1, [r4, 0x28]
	adds r1, 0x4
	ldr r2, _0800D9B0
	bl CpuSet
	movs r2, 0
	ldr r1, [r4, 0x28]
_0800D96C:
	ldrh r0, [r1]
	adds r5, r0
	adds r1, 0x2
	adds r2, 0x1
	cmp r2, 0x9
	bls _0800D96C
	adds r2, r4, 0
	ldr r1, [r2, 0x28]
	mvns r0, r5
	subs r0, 0xC
	strh r0, [r1, 0x2]
	ldrb r0, [r2]
	cmp r0, 0
	beq _0800D98E
	ldr r1, _0800D9B4
	movs r0, 0
	strh r0, [r1]
_0800D98E:
	movs r0, 0x1
	negs r0, r0
	str r0, [r4, 0x14]
	ldrb r0, [r4]
	cmp r0, 0
	beq _0800D9A6
	ldrb r0, [r4, 0x8]
	cmp r0, 0
	beq _0800D9A6
	ldr r1, _0800D9B4
	movs r0, 0xC0
	strh r0, [r1]
_0800D9A6:
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_0800D9AC: .4byte gUnknown_202DCF8
_0800D9B0: .4byte 0x04000004
_0800D9B4: .4byte 0x0400010e
	thumb_func_end sub_800D944

	thumb_func_start sub_800D9B8
sub_800D9B8:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0xC
	str r0, [sp, 0x8]
	ldr r0, _0800DA68
	bl _call_via_r0
	str r0, [sp]
	ldr r1, _0800DA6C
	movs r0, 0
	strb r0, [r1, 0x3]
	movs r6, 0
	add r0, sp, 0x4
	mov r10, r0
	mov r9, r1
	movs r1, 0x50
	add r1, r9
	mov r8, r1
_0800D9E2:
	movs r3, 0
	movs r2, 0
	lsls r5, r6, 2
	mov r0, sp
	adds r4, r0, r6
	adds r7, r6, 0x1
	mov r1, r8
	adds r0, r5, r1
	ldr r1, [r0]
_0800D9F4:
	ldrh r0, [r1]
	adds r3, r0
	adds r1, 0x2
	adds r2, 0x1
	cmp r2, 0x9
	bls _0800D9F4
	ldrb r0, [r4]
	cmp r0, 0
	beq _0800DA32
	lsls r0, r3, 16
	asrs r0, 16
	movs r2, 0xD
	negs r2, r2
	cmp r0, r2
	bne _0800DA32
	mov r1, r8
	adds r0, r5, r1
	ldr r0, [r0]
	adds r0, 0x4
	lsls r1, r6, 4
	ldr r2, [sp, 0x8]
	adds r1, r2, r1
	ldr r2, _0800DA70
	bl CpuSet
	movs r0, 0x1
	lsls r0, r6
	mov r2, r9
	ldrb r1, [r2, 0x3]
	orrs r0, r1
	strb r0, [r2, 0x3]
_0800DA32:
	movs r0, 0
	str r0, [sp, 0x4]
	mov r1, r8
	adds r0, r5, r1
	ldr r1, [r0]
	adds r1, 0x4
	mov r0, r10
	ldr r2, _0800DA74
	bl CpuSet
	adds r6, r7, 0
	cmp r6, 0x1
	ble _0800D9E2
	ldr r1, _0800DA6C
	ldrb r0, [r1, 0x2]
	ldrb r2, [r1, 0x3]
	orrs r0, r2
	strb r0, [r1, 0x2]
	ldrb r0, [r1, 0x3]
	add sp, 0xC
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	.align 2, 0
_0800DA68: .4byte gUnknown_202DB78
_0800DA6C: .4byte gUnknown_202DCF8
_0800DA70: .4byte 0x04000004
_0800DA74: .4byte 0x05000004
	thumb_func_end sub_800D9B8

	.align 2, 0 @ Don't pad with nop.
