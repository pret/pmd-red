	.include "constants/gba_constants.inc"
	.include "asm/macros.inc"

	.syntax unified

	.text

	thumb_func_start Hang
Hang:
	push {lr}
_0800D092:
	swi 0x2
	b _0800D092
	thumb_func_end Hang

	thumb_func_start sub_800D098
sub_800D098:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	ldr r1, _0800D138
_0800D0A4:
	ldrh r0, [r1]
	cmp r0, 0x9F
	bls _0800D0A4
	movs r1, 0x80
	lsls r1, 19
	ldrh r0, [r1]
	adds r7, r0, 0
	movs r0, 0
	strh r0, [r1]
	movs r1, 0xA0
	lsls r1, 19
	ldr r2, _0800D13C
	adds r0, r2, 0
	strh r0, [r1]
	ldr r2, _0800D140
	ldrh r0, [r2]
	ldr r1, _0800D144
	cmp r0, r1
	beq _0800D0D0
_0800D0CA:
	ldrh r0, [r2]
	cmp r0, r1
	bne _0800D0CA
_0800D0D0:
	ldr r6, _0800D148
	movs r0, 0
	mov r8, r0
	strh r0, [r6]
	ldr r5, _0800D14C
	ldrh r4, [r5]
	movs r1, 0xC0
	lsls r1, 6
	adds r0, r1, 0
	strh r0, [r5]
	ldr r2, _0800D150
	mov r10, r2
	ldr r1, _0800D154
	adds r0, r1, 0
	strh r0, [r2]
	movs r2, 0x1
	mov r9, r2
	strh r2, [r6]
	bl SoundBiasReset
	swi 0x3
	bl SoundBiasSet
	mov r0, r8
	strh r0, [r6]
	strh r4, [r5]
	mov r1, r10
	strh r0, [r1]
	mov r2, r9
	strh r2, [r6]
	ldr r1, _0800D138
_0800D10E:
	ldrh r0, [r1]
	cmp r0, 0x9F
	bls _0800D10E
	movs r0, 0x80
	lsls r0, 19
	strh r7, [r0]
	ldr r2, _0800D140
	ldrh r0, [r2]
	ldr r1, _0800D144
	cmp r0, r1
	beq _0800D12A
_0800D124:
	ldrh r0, [r2]
	cmp r0, r1
	bne _0800D124
_0800D12A:
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_0800D138: .4byte 0x04000006
_0800D13C: .4byte 0x0000efff
_0800D140: .4byte 0x04000130
_0800D144: .4byte 0x000003ff
_0800D148: .4byte 0x04000208
_0800D14C: .4byte 0x04000200
_0800D150: .4byte 0x04000132
_0800D154: .4byte 0x0000c304
	thumb_func_end sub_800D098

	thumb_func_start sub_800D158
sub_800D158:
	push {r1-r3}
	push {lr}
	ldr r1, [sp, 0x4]
	add r2, sp, 0x8
	bl vsprintf
	pop {r3}
	add sp, 0xC
	bx r3
	thumb_func_end sub_800D158

	thumb_func_start sub_800D16C
sub_800D16C:
	push {r0-r3}
	push {lr}
	mov r12, r4
	ldr r4, _0800D198
	add sp, r4
	mov r4, r12
	ldr r0, _0800D19C
	add r0, sp
	ldr r1, [r0]
	movs r2, 0x81
	lsls r2, 3
	add r2, sp
	mov r0, sp
	bl vsprintf
	movs r3, 0x80
	lsls r3, 3
	add sp, r3
	pop {r3}
	add sp, 0x10
	bx r3
	.align 2, 0
_0800D198: .4byte 0xfffffc00
_0800D19C: .4byte 0x00000404
	thumb_func_end sub_800D16C

	thumb_func_start sub_800D1A0
sub_800D1A0:
	push {r3}
	add sp, 0x4
	bx lr
	thumb_func_end sub_800D1A0

	thumb_func_start nullsub_183
nullsub_183:
	bx lr
	thumb_func_end nullsub_183

	thumb_func_start nullsub_188
nullsub_188:
	bx lr
	thumb_func_end nullsub_188

	thumb_func_start nullsub_184
nullsub_184:
	bx lr
	thumb_func_end nullsub_184

	thumb_func_start sub_800D1B4
sub_800D1B4:
	movs r0, 0
	bx lr
	thumb_func_end sub_800D1B4

	thumb_func_start sub_800D1B8
sub_800D1B8:
	adds r0, r2, 0
	bx lr
	thumb_func_end sub_800D1B8

	thumb_func_start nullsub_187
nullsub_187:
	bx lr
	thumb_func_end nullsub_187

	thumb_func_start sub_800D1C0
sub_800D1C0:
	push {lr}
	ldr r1, _0800D1D4
	ldr r0, [r1]
	cmp r0, 0x2
	bne _0800D1D8
	ldr r0, [r1, 0x4]
	cmp r0, 0x2
	bne _0800D1D8
	movs r0, 0x1
	b _0800D1DA
	.align 2, 0
_0800D1D4: .4byte gUnknown_202DB60
_0800D1D8:
	movs r0, 0
_0800D1DA:
	pop {r1}
	bx r1
	thumb_func_end sub_800D1C0

	thumb_func_start sub_800D1E0
sub_800D1E0:
	push {r4-r7,lr}
	movs r0, 0
	ldr r1, _0800D218
	mov r12, r1
	ldr r6, _0800D21C
	ldr r7, _0800D220
	movs r5, 0x1
_0800D1EE:
	movs r2, 0
	lsls r1, r0, 4
	adds r4, r0, 0x1
	lsls r0, 2
	adds r3, r0, r7
	add r1, r12
_0800D1FA:
	ldrh r0, [r1]
	cmp r0, r6
	bne _0800D202
	str r5, [r3]
_0800D202:
	adds r1, 0x2
	adds r2, 0x1
	cmp r2, 0x7
	bls _0800D1FA
	adds r0, r4, 0
	cmp r0, 0x1
	ble _0800D1EE
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_0800D218: .4byte gUnknown_202DB30
_0800D21C: .4byte 0x0000fdfd
_0800D220: .4byte gUnknown_202DB60
	thumb_func_end sub_800D1E0

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

	thumb_func_start nullsub_189
nullsub_189:
	bx lr
	thumb_func_end nullsub_189

	thumb_func_start nullsub_190
nullsub_190:
	bx lr
	thumb_func_end nullsub_190

	thumb_func_start nullsub_191
nullsub_191:
	bx lr
	thumb_func_end nullsub_191

	thumb_func_start nullsub_192
nullsub_192:
	bx lr
	thumb_func_end nullsub_192

	thumb_func_start nullsub_193
nullsub_193:
	bx lr
	thumb_func_end nullsub_193

	thumb_func_start nullsub_194
nullsub_194:
	bx lr
	thumb_func_end nullsub_194

	thumb_func_start nullsub_195
nullsub_195:
	bx lr
	thumb_func_end nullsub_195

	thumb_func_start sub_800DA94
sub_800DA94:
	movs r0, 0
	bx lr
	thumb_func_end sub_800DA94

	thumb_func_start sub_800DA98
sub_800DA98:
	movs r0, 0
	bx lr
	thumb_func_end sub_800DA98

	thumb_func_start sub_800DA9C
sub_800DA9C:
	movs r0, 0
	bx lr
	thumb_func_end sub_800DA9C

	thumb_func_start nullsub_196
nullsub_196:
	bx lr
	thumb_func_end nullsub_196

	thumb_func_start nullsub_197
nullsub_197:
	bx lr
	thumb_func_end nullsub_197

	thumb_func_start nullsub_198
nullsub_198:
	bx lr
	thumb_func_end nullsub_198

	thumb_func_start sub_800DAAC
sub_800DAAC:
	movs r0, 0
	bx lr
	thumb_func_end sub_800DAAC

	thumb_func_start sub_800DAB0
sub_800DAB0:
	movs r0, 0
	bx lr
	thumb_func_end sub_800DAB0

	thumb_func_start sub_800DAB4
sub_800DAB4:
	movs r0, 0
	bx lr
	thumb_func_end sub_800DAB4

	thumb_func_start sub_800DAB8
sub_800DAB8:
	movs r0, 0
	bx lr
	thumb_func_end sub_800DAB8

	thumb_func_start sub_800DABC
sub_800DABC:
	movs r0, 0
	bx lr
	thumb_func_end sub_800DABC

	thumb_func_start sub_800DAC0
sub_800DAC0:
	push {r4-r6,lr}
	adds r6, r0, 0
	ldr r5, _0800DB38
	ldr r0, [r5]
	cmp r0, 0
	beq _0800DAD0
	bl sub_800DB7C
_0800DAD0:
	ldr r4, _0800DB3C
	adds r0, r4, 0
	movs r1, 0xB
	bl MemoryAlloc
	str r0, [r5]
	adds r1, r4, 0
	bl MemoryClear8
	ldr r1, [r5]
	ldr r2, _0800DB40
	adds r0, r1, r2
	str r6, [r0]
	movs r2, 0x1
	negs r2, r2
	movs r0, 0x1F
_0800DAF0:
	str r2, [r1, 0x4]
	subs r0, 0x1
	adds r1, 0xD0
	cmp r0, 0
	bge _0800DAF0
	adds r0, r6, 0
	bl sub_800ED38
	bl sub_800F034
	ldr r0, _0800DB38
	ldr r0, [r0]
	ldr r1, _0800DB40
	adds r0, r1
	ldr r0, [r0]
	cmp r0, 0
	beq _0800DB4C
	cmp r0, 0x1
	bne _0800DB6C
	ldr r0, _0800DB44
	ldr r1, _0800DB48
	bl Call_OpenFileAndGetFileDataPtr
	adds r4, r0, 0
	cmp r4, 0
	beq _0800DB6C
	movs r1, 0x92
	lsls r1, 2
	movs r2, 0x1F
	movs r3, 0
	bl sub_8005610
	adds r0, r4, 0
	bl CloseFile
	b _0800DB6C
	.align 2, 0
_0800DB38: .4byte gUnknown_203B0CC
_0800DB3C: .4byte 0x00001a18
_0800DB40: .4byte 0x00001a04
_0800DB44: .4byte gUnknown_80B9C6C
_0800DB48: .4byte gUnknown_9740000
_0800DB4C:
	ldr r0, _0800DB74
	ldr r1, _0800DB78
	bl Call_OpenFileAndGetFileDataPtr
	adds r4, r0, 0
	cmp r4, 0
	beq _0800DB6C
	movs r1, 0x92
	lsls r1, 2
	movs r2, 0x1F
	movs r3, 0
	bl sub_8005610
	adds r0, r4, 0
	bl CloseFile
_0800DB6C:
	pop {r4-r6}
	pop {r0}
	bx r0
	.align 2, 0
_0800DB74: .4byte gUnknown_80B9C74
_0800DB78: .4byte gUnknown_9740000
	thumb_func_end sub_800DAC0

	thumb_func_start sub_800DB7C
sub_800DB7C:
	push {r4-r6,lr}
	ldr r0, _0800DBB8
	ldr r4, [r0]
	movs r6, 0x1
	negs r6, r6
	movs r5, 0x1F
_0800DB88:
	ldr r0, [r4, 0x4]
	cmp r0, r6
	beq _0800DB92
	bl sub_800DC14
_0800DB92:
	subs r5, 0x1
	adds r4, 0xD0
	cmp r5, 0
	bge _0800DB88
	bl sub_800F078
	bl sub_800ED64
	ldr r4, _0800DBB8
	ldr r0, [r4]
	cmp r0, 0
	beq _0800DBB2
	bl MemoryFree
	movs r0, 0
	str r0, [r4]
_0800DBB2:
	pop {r4-r6}
	pop {r0}
	bx r0
	.align 2, 0
_0800DBB8: .4byte gUnknown_203B0CC
	thumb_func_end sub_800DB7C

	thumb_func_start sub_800DBBC
sub_800DBBC:
	push {r4-r6,lr}
	ldr r0, _0800DBFC
	ldr r4, [r0]
	movs r6, 0x1
	negs r6, r6
	movs r5, 0x1F
_0800DBC8:
	ldr r0, [r4, 0x4]
	cmp r0, r6
	beq _0800DBD2
	bl sub_800DC14
_0800DBD2:
	subs r5, 0x1
	adds r4, 0xD0
	cmp r5, 0
	bge _0800DBC8
	ldr r0, _0800DBFC
	ldr r0, [r0]
	movs r2, 0x1
	negs r2, r2
	movs r1, 0x1F
_0800DBE4:
	str r2, [r0, 0x4]
	subs r1, 0x1
	adds r0, 0xD0
	cmp r1, 0
	bge _0800DBE4
	bl sub_800ED80
	bl sub_800F094
	pop {r4-r6}
	pop {r0}
	bx r0
	.align 2, 0
_0800DBFC: .4byte gUnknown_203B0CC
	thumb_func_end sub_800DBBC

	thumb_func_start sub_800DC00
sub_800DC00:
	push {lr}
	ldr r0, _0800DC10
	ldr r0, [r0]
	cmp r0, 0
	beq _0800DC0C
	movs r0, 0x1
_0800DC0C:
	pop {r1}
	bx r1
	.align 2, 0
_0800DC10: .4byte gUnknown_203B0CC
	thumb_func_end sub_800DC00

	thumb_func_start sub_800DC14
sub_800DC14:
	push {r4,r5,lr}
	bl sub_800E2C0
	adds r1, r0, 0
	movs r0, 0x1
	negs r0, r0
	cmp r1, r0
	beq _0800DC96
	ldr r2, _0800DC60
	movs r0, 0xD0
	muls r1, r0
	ldr r0, [r2]
	adds r5, r0, r1
	ldr r0, [r5, 0x34]
	cmp r0, 0x4
	bne _0800DC56
	bl sub_8009BE4
	bl sub_8000728
	cmp r0, 0x1
	bne _0800DC56
	bl sub_8040238
	movs r0, 0
	movs r1, 0
	bl sub_803EAF0
	movs r0, 0x80
	lsls r0, 8
	movs r1, 0
	bl sub_800CD64
_0800DC56:
	ldr r0, [r5, 0x34]
	cmp r0, 0x3
	bne _0800DC82
	movs r4, 0
	b _0800DC66
	.align 2, 0
_0800DC60: .4byte gUnknown_203B0CC
_0800DC64:
	adds r4, 0x1
_0800DC66:
	cmp r4, 0x1
	bgt _0800DC90
	adds r0, r4, 0
	bl sub_800F18C
	adds r2, r0, 0
	ldr r1, [r2]
	ldr r0, [r5, 0x38]
	cmp r1, r0
	bne _0800DC64
	ldr r0, [r2, 0x4]
	subs r0, 0x1
	str r0, [r2, 0x4]
	b _0800DC90
_0800DC82:
	movs r0, 0x1
	bl sub_800F18C
	movs r1, 0
	str r1, [r0, 0x4]
	subs r1, 0x1
	str r1, [r0]
_0800DC90:
	adds r0, r5, 0
	bl sub_800DCA8
_0800DC96:
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_800DC14

	thumb_func_start sub_800DC9C
sub_800DC9C:
	push {lr}
	bl sub_800E900
	pop {r1}
	bx r1
	thumb_func_end sub_800DC9C

	thumb_func_start sub_800DCA8
sub_800DCA8:
	push {r4,r5,lr}
	movs r1, 0x1
	negs r1, r1
	str r1, [r0, 0x4]
	adds r1, r0, 0
	adds r1, 0x54
	movs r5, 0
	strb r5, [r1]
	adds r4, r0, 0
	adds r4, 0xB8
	ldr r0, [r4]
	cmp r0, 0
	beq _0800DCC8
	bl sub_800F204
	str r5, [r4]
_0800DCC8:
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_800DCA8

	thumb_func_start sub_800DCD0
sub_800DCD0:
	push {r4,r5,lr}
	adds r4, r0, 0
	ldr r0, [r4, 0x4C]
	movs r5, 0x1
	negs r5, r5
	cmp r0, r5
	beq _0800DCFA
	ldr r0, [r4, 0x50]
	cmp r0, 0
	bne _0800DCFA
	bl sub_8000728
	cmp r0, 0x2
	beq _0800DCF6
	ldr r0, [r4, 0x4C]
	lsls r0, 16
	lsrs r0, 16
	bl sub_8011988
_0800DCF6:
	str r5, [r4, 0x4C]
	str r5, [r4, 0x50]
_0800DCFA:
	ldr r0, [r4, 0x50]
	cmp r0, 0
	ble _0800DD04
	subs r0, 0x1
	str r0, [r4, 0x50]
_0800DD04:
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_800DCD0

	thumb_func_start sub_800DD0C
sub_800DD0C:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0x8
	adds r5, r0, 0
	adds r6, r1, 0
	movs r0, 0x58
	adds r0, r5
	mov r8, r0
	ldrh r1, [r0]
	movs r0, 0x80
	lsls r0, 6
	ands r0, r1
	cmp r0, 0
	beq _0800DD2E
	movs r0, 0
	b _0800DD30
_0800DD2E:
	lsrs r0, r1, 15
_0800DD30:
	cmp r0, 0
	bne _0800DD64
	adds r0, r5, 0
	bl sub_800DCA8
	ldr r0, [r5, 0x34]
	cmp r0, 0x3
	bne _0800DD60
	movs r4, 0
	b _0800DD46
_0800DD44:
	adds r4, 0x1
_0800DD46:
	cmp r4, 0x1
	bgt _0800DD60
	adds r0, r4, 0
	bl sub_800F18C
	adds r2, r0, 0
	ldr r1, [r2]
	ldr r0, [r5, 0x38]
	cmp r1, r0
	bne _0800DD44
	ldr r0, [r2, 0x4]
	subs r0, 0x1
	str r0, [r2, 0x4]
_0800DD60:
	movs r0, 0
	b _0800DE28
_0800DD64:
	mov r0, r8
	bl sub_80054BC
	movs r4, 0
	ldr r0, [r5, 0x8]
	movs r1, 0x7
	ands r0, r1
	cmp r0, 0
	bne _0800DD88
	ldr r0, [r5, 0x14]
	cmp r0, 0x5
	bgt _0800DD84
	cmp r0, 0x3
	blt _0800DD84
	subs r4, 0x3
	b _0800DD8A
_0800DD84:
	adds r4, 0x3
	b _0800DD8A
_0800DD88:
	movs r4, 0x3
_0800DD8A:
	movs r2, 0
	ldr r1, [r5, 0x20]
	movs r0, 0x1
	negs r0, r0
	cmp r1, r0
	beq _0800DD9E
	ldrh r0, [r5, 0x1E]
	lsls r0, 16
	ldrh r2, [r5, 0x1C]
	orrs r2, r0
_0800DD9E:
	lsls r0, r2, 16
	asrs r1, r0, 16
	adds r7, r0, 0
	cmp r1, 0x63
	beq _0800DE26
	asrs r0, r2, 16
	adds r2, r0, 0
	cmp r2, 0x63
	beq _0800DE26
	ldr r3, [r5, 0x24]
	ldr r0, _0800DE34
	cmp r3, r0
	bne _0800DDCA
	movs r1, 0x1A
	ldrsh r0, [r5, r1]
	movs r3, 0x2
	ldrsh r1, [r6, r3]
	subs r0, r1
	lsrs r1, r0, 31
	adds r0, r1
	asrs r0, 1
	adds r3, r0, r4
_0800DDCA:
	movs r4, 0x18
	ldrsh r0, [r5, r4]
	movs r4, 0
	ldrsh r1, [r6, r4]
	subs r0, r1
	asrs r1, r7, 16
	adds r4, r0, r1
	movs r7, 0x1A
	ldrsh r0, [r5, r7]
	movs r7, 0x2
	ldrsh r1, [r6, r7]
	subs r0, r1
	adds r2, r0, r2
	adds r0, r5, 0
	adds r0, 0xCC
	ldrh r0, [r0]
	ldrh r1, [r5, 0x18]
	adds r0, r1
	strh r0, [r5, 0x18]
	adds r0, r5, 0
	adds r0, 0xCE
	ldrh r0, [r0]
	ldrh r7, [r5, 0x1A]
	adds r0, r7
	strh r0, [r5, 0x1A]
	adds r1, r4, 0
	adds r1, 0x3F
	movs r0, 0xB7
	lsls r0, 1
	cmp r1, r0
	bhi _0800DE26
	movs r0, 0x40
	negs r0, r0
	cmp r2, r0
	ble _0800DE26
	cmp r2, 0xDF
	bgt _0800DE26
	ldr r0, [r5, 0x3C]
	str r0, [sp]
	adds r0, r5, 0
	adds r0, 0x28
	str r0, [sp, 0x4]
	mov r0, r8
	adds r1, r4, 0
	bl sub_800558C
_0800DE26:
	movs r0, 0x1
_0800DE28:
	add sp, 0x8
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r1}
	bx r1
	.align 2, 0
_0800DE34: .4byte 0x0000ffff
	thumb_func_end sub_800DD0C

	thumb_func_start sub_800DE38
sub_800DE38:
	push {r4,r5,lr}
	adds r5, r0, 0
	adds r0, 0x58
	ldrh r1, [r0]
	movs r0, 0x80
	lsls r0, 6
	ands r0, r1
	cmp r0, 0
	beq _0800DE4E
	movs r0, 0
	b _0800DE50
_0800DE4E:
	lsrs r0, r1, 15
_0800DE50:
	cmp r0, 0
	bne _0800DE84
	adds r0, r5, 0
	bl sub_800DCA8
	ldr r0, [r5, 0x34]
	cmp r0, 0x3
	bne _0800DE80
	movs r4, 0
	b _0800DE66
_0800DE64:
	adds r4, 0x1
_0800DE66:
	cmp r4, 0x1
	bgt _0800DE80
	adds r0, r4, 0
	bl sub_800F18C
	adds r2, r0, 0
	ldr r1, [r2]
	ldr r0, [r5, 0x38]
	cmp r1, r0
	bne _0800DE64
	ldr r0, [r2, 0x4]
	subs r0, 0x1
	str r0, [r2, 0x4]
_0800DE80:
	movs r0, 0
	b _0800DE86
_0800DE84:
	movs r0, 0x1
_0800DE86:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_800DE38

	thumb_func_start sub_800DE8C
sub_800DE8C:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0x14
	adds r6, r0, 0
	movs r0, 0x94
	adds r0, r6
	mov r8, r0
	ldr r4, [r0, 0x18]
	cmp r4, 0
	beq _0800DEA4
	b _0800E09C
_0800DEA4:
	ldr r1, [r0, 0x14]
	movs r7, 0x1
	str r7, [sp]
	adds r0, r6, 0
	adds r0, 0xAC
	str r0, [sp, 0x4]
	add r2, sp, 0xC
	str r2, [sp, 0x8]
	mov r0, r8
	movs r2, 0
	movs r3, 0
	bl sub_8009A7C
	lsls r0, 24
	lsrs r5, r0, 24
	cmp r5, 0
	bne _0800DEC8
	b _0800E030
_0800DEC8:
	add r0, sp, 0xC
	movs r1, 0
	ldrsh r0, [r0, r1]
	cmp r0, 0
	beq _0800DEE8
	adds r0, r6, 0
	adds r0, 0xB4
	strb r7, [r0]
	ldr r0, _0800DF0C
	ldr r0, [r0]
	ldr r2, _0800DF10
	adds r1, r0, r2
	str r4, [r1]
	ldr r1, _0800DF14
	adds r0, r1
	str r4, [r0]
_0800DEE8:
	add r0, sp, 0xC
	ldrh r0, [r0, 0x2]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0
	beq _0800DF6C
	cmp r0, 0x63
	bne _0800DF1C
	ldr r0, _0800DF0C
	ldr r0, [r0]
	ldr r1, _0800DF10
	adds r2, r0, r1
	ldr r1, _0800DF18
	str r1, [r2]
	ldr r2, _0800DF14
	adds r0, r2
	str r4, [r0]
	b _0800DF6C
	.align 2, 0
_0800DF0C: .4byte gUnknown_203B0CC
_0800DF10: .4byte 0x00001a08
_0800DF14: .4byte 0x00001a0c
_0800DF18: .4byte 0x00000c1c
_0800DF1C:
	cmp r0, 0
	ble _0800DF50
	ldr r0, _0800DF40
	ldr r4, [r0]
	ldr r0, _0800DF44
	adds r5, r4, r0
	ldr r1, _0800DF48
	adds r4, r1
	add r0, sp, 0xC
	movs r2, 0x2
	ldrsh r1, [r0, r2]
	ldr r0, _0800DF4C
	bl __divsi3
	str r0, [r4]
	str r0, [r5]
	b _0800DF6C
	.align 2, 0
_0800DF40: .4byte gUnknown_203B0CC
_0800DF44: .4byte 0x00001a08
_0800DF48: .4byte 0x00001a0c
_0800DF4C: .4byte 0x00000c1c
_0800DF50:
	ldr r0, _0800DFA4
	ldr r4, [r0]
	ldr r0, _0800DFA8
	adds r1, r4, r0
	ldr r0, _0800DFAC
	str r0, [r1]
	ldr r1, _0800DFB0
	adds r4, r1
	add r1, sp, 0xC
	movs r2, 0x2
	ldrsh r1, [r1, r2]
	bl __divsi3
	str r0, [r4]
_0800DF6C:
	mov r0, r8
	adds r0, 0x20
	ldrb r0, [r0]
	cmp r0, 0
	bne _0800DF78
	b _0800E094
_0800DF78:
	ldr r0, _0800DFA4
	ldr r1, [r0]
	ldr r2, _0800DFB4
	adds r0, r1, r2
	ldr r0, [r0]
	cmp r0, 0
	beq _0800DFB8
	cmp r0, 0x1
	bne _0800DFEA
	adds r0, r6, 0
	adds r0, 0xB8
	ldr r0, [r0]
	ldr r0, [r0, 0x4]
	ldr r1, [r0, 0x10]
	movs r0, 0xE0
	lsls r0, 2
	adds r1, r0
	movs r0, 0xE0
	movs r2, 0x10
	bl sub_809971C
	b _0800DFEA
	.align 2, 0
_0800DFA4: .4byte gUnknown_203B0CC
_0800DFA8: .4byte 0x00001a08
_0800DFAC: .4byte 0x00000c1c
_0800DFB0: .4byte 0x00001a0c
_0800DFB4: .4byte 0x00001a04
_0800DFB8:
	ldr r2, _0800E010
	adds r0, r1, r2
	ldr r0, [r0]
	movs r1, 0x64
	bl __divsi3
	adds r7, r0, 0
	movs r4, 0
	adds r6, 0xB8
	movs r5, 0xE0
	lsls r5, 2
_0800DFCE:
	adds r0, r4, 0
	adds r0, 0xE0
	ldr r1, [r6]
	ldr r1, [r1, 0x4]
	ldr r1, [r1, 0x10]
	adds r1, r5
	adds r2, r7, 0
	movs r3, 0
	bl SetBGPaletteBufferColorRGB
	adds r5, 0x4
	adds r4, 0x1
	cmp r4, 0xF
	ble _0800DFCE
_0800DFEA:
	ldr r1, _0800E014
	ldr r2, _0800E018
	adds r0, r2, 0
	strh r0, [r1]
	ldr r0, _0800E01C
	ldr r0, [r0]
	ldr r1, _0800E010
	adds r2, r0, r1
	adds r1, 0x4
	adds r0, r1
	ldr r1, [r2]
	ldr r0, [r0]
	adds r1, r0
	str r1, [r2]
	cmp r1, 0
	bge _0800E020
	movs r0, 0
	str r0, [r2]
	b _0800E094
	.align 2, 0
_0800E010: .4byte 0x00001a08
_0800E014: .4byte gUnknown_2026E4E
_0800E018: .4byte 0x00000a0a
_0800E01C: .4byte gUnknown_203B0CC
_0800E020:
	ldr r0, _0800E02C
	cmp r1, r0
	ble _0800E094
	str r0, [r2]
	b _0800E094
	.align 2, 0
_0800E02C: .4byte 0x00000c1c
_0800E030:
	bl sub_8009BE4
	adds r0, r6, 0
	bl sub_800DCA8
	bl sub_8000728
	cmp r0, 0x1
	bne _0800E058
	bl sub_8040238
	movs r0, 0
	movs r1, 0
	bl sub_803EAF0
	movs r0, 0x80
	lsls r0, 8
	movs r1, 0
	bl sub_800CD64
_0800E058:
	ldr r4, _0800E084
	ldr r0, [r4]
	ldr r2, _0800E088
	adds r0, r2
	ldr r0, [r0]
	bl sub_800CDA8
	ldr r1, _0800E08C
	ldr r0, [r4]
	ldr r2, _0800E090
	adds r0, r2
	ldrh r0, [r0]
	strh r0, [r1]
	movs r0, 0x1
	bl sub_800F18C
	str r5, [r0, 0x4]
	movs r1, 0x1
	negs r1, r1
	str r1, [r0]
	movs r0, 0
	b _0800E0A6
	.align 2, 0
_0800E084: .4byte gUnknown_203B0CC
_0800E088: .4byte 0x00001a10
_0800E08C: .4byte gUnknown_2026E4E
_0800E090: .4byte 0x00001a14
_0800E094:
	mov r1, r8
	ldr r0, [r1, 0x14]
	adds r0, 0x1
	str r0, [r1, 0x14]
_0800E09C:
	mov r2, r8
	ldr r0, [r2, 0x18]
	subs r0, 0x1
	str r0, [r2, 0x18]
	movs r0, 0x1
_0800E0A6:
	add sp, 0x14
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_800DE8C

	thumb_func_start sub_800E0B4
sub_800E0B4:
	push {r4-r6,lr}
	sub sp, 0x8
	adds r5, r0, 0
	ldr r0, [r5, 0xC]
	bl sub_800ECA4
	adds r6, r0, 0
	ldr r0, [r6]
	str r0, [r5, 0x34]
	ldr r0, [r6, 0x4]
	str r0, [r5, 0x38]
	ldr r0, [r6, 0x10]
	str r0, [r5, 0x4C]
	ldr r0, [r5, 0x10]
	ldr r1, [r6, 0x14]
	adds r0, r1
	str r0, [r5, 0x50]
	adds r0, r6, 0
	adds r0, 0x21
	ldrb r0, [r0]
	adds r1, r5, 0
	adds r1, 0x55
	strb r0, [r1]
	adds r0, r6, 0
	adds r0, 0x20
	ldrb r1, [r0]
	adds r0, r5, 0
	adds r0, 0x54
	strb r1, [r0]
	adds r0, 0x64
	ldr r0, [r0]
	bl sub_800E2B8
	adds r2, r0, 0
	str r2, [r5, 0x8]
	ldr r3, [r6, 0xC]
	str r3, [r5, 0x40]
	ldr r1, [r5, 0x14]
	movs r0, 0x1
	negs r0, r0
	cmp r1, r0
	beq _0800E114
	movs r0, 0x7
	ands r0, r2
	cmp r0, 0
	bne _0800E114
	adds r0, r3, r1
	str r0, [r5, 0x40]
_0800E114:
	ldr r0, [r5, 0x34]
	cmp r0, 0x3
	beq _0800E12E
	cmp r0, 0x3
	bhi _0800E128
	cmp r0, 0x1
	bcc _0800E184
	movs r0, 0x92
	lsls r0, 2
	b _0800E132
_0800E128:
	cmp r0, 0x4
	beq _0800E140
	b _0800E184
_0800E12E:
	movs r0, 0xDC
	lsls r0, 2
_0800E132:
	str r0, [r5, 0x48]
	ldr r0, [r6, 0x8]
	str r0, [r5, 0x3C]
	movs r0, 0x1
	negs r0, r0
	str r0, [r5, 0x44]
	b _0800E184
_0800E140:
	movs r0, 0x1
	negs r0, r0
	str r0, [r5, 0x48]
	ldr r0, [r6, 0x8]
	str r0, [r5, 0x3C]
	movs r0, 0xF0
	lsls r0, 4
	str r0, [r5, 0x44]
	ldr r4, _0800E194
	ldr r0, [r4]
	ldr r2, _0800E198
	adds r1, r0, r2
	movs r2, 0
	str r2, [r1]
	ldr r3, _0800E19C
	adds r0, r3
	str r2, [r0]
	bl sub_800CDC8
	ldr r2, [r4]
	ldr r4, _0800E1A0
	adds r1, r2, r4
	str r0, [r1]
	ldr r0, _0800E1A4
	ldrh r0, [r0]
	ldr r1, _0800E1A8
	adds r2, r1
	strh r0, [r2]
	ldrb r0, [r6, 0x18]
	cmp r0, 0
	beq _0800E184
	movs r0, 0x5
	bl sub_800CDA8
_0800E184:
	ldr r0, [r5, 0x34]
	cmp r0, 0x3
	beq _0800E1C2
	cmp r0, 0x3
	bls _0800E1AC
	cmp r0, 0x4
	beq _0800E1E4
	b _0800E200
	.align 2, 0
_0800E194: .4byte gUnknown_203B0CC
_0800E198: .4byte 0x00001a08
_0800E19C: .4byte 0x00001a0c
_0800E1A0: .4byte 0x00001a10
_0800E1A4: .4byte gUnknown_2026E4E
_0800E1A8: .4byte 0x00001a14
_0800E1AC:
	cmp r0, 0x1
	bcc _0800E200
	adds r0, r5, 0
	adds r0, 0x58
	adds r1, r5, 0
	adds r1, 0xB8
	ldr r1, [r1]
	ldr r2, [r5, 0x40]
	movs r3, 0x92
	lsls r3, 2
	b _0800E1D2
_0800E1C2:
	adds r0, r5, 0
	adds r0, 0x58
	adds r1, r5, 0
	adds r1, 0xB8
	ldr r1, [r1]
	ldr r2, [r5, 0x40]
	movs r3, 0xDC
	lsls r3, 2
_0800E1D2:
	movs r4, 0
	str r4, [sp]
	adds r4, r5, 0
	adds r4, 0x55
	ldrb r4, [r4]
	str r4, [sp, 0x4]
	bl sub_800543C
	b _0800E200
_0800E1E4:
	adds r0, r5, 0
	adds r0, 0xB8
	ldr r0, [r0]
	adds r1, r5, 0
	adds r1, 0x94
	ldr r0, [r0, 0x4]
	ldm r0!, {r2-r4}
	stm r1!, {r2-r4}
	ldm r0!, {r2,r3}
	stm r1!, {r2,r3}
	adds r1, r5, 0
	adds r1, 0xB4
	movs r0, 0
	strb r0, [r1]
_0800E200:
	add sp, 0x8
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end sub_800E0B4

	thumb_func_start sub_800E208
sub_800E208:
	push {r4-r7,lr}
	adds r7, r0, 0
	adds r6, r1, 0
	ldr r0, _0800E220
	ldr r4, [r0]
	ldr r0, [r6]
	cmp r0, 0
	bne _0800E224
_0800E218:
	movs r0, 0x1
	negs r0, r0
	b _0800E2B0
	.align 2, 0
_0800E220: .4byte gUnknown_203B0CC
_0800E224:
	movs r1, 0
_0800E226:
	ldr r5, [r4, 0x4]
	movs r0, 0x1
	negs r0, r0
	cmp r5, r0
	bne _0800E2A8
	adds r0, r4, 0
	movs r1, 0xD0
	bl MemoryClear8
	ldr r0, [r6]
	bl sub_800ECA4
	adds r1, r0, 0
	ldr r2, [r1]
	cmp r2, 0x2
	bne _0800E254
	ldr r0, _0800E2A0
	ldr r0, [r0]
	ldr r3, _0800E2A4
	adds r0, r3
	ldr r0, [r0]
	cmp r0, 0x1
	bne _0800E218
_0800E254:
	cmp r2, 0x1
	bne _0800E266
	ldr r0, _0800E2A0
	ldr r0, [r0]
	ldr r3, _0800E2A4
	adds r0, r3
	ldr r0, [r0]
	cmp r0, 0
	bne _0800E218
_0800E266:
	ldr r1, [r1, 0x4]
	adds r0, r2, 0
	bl sub_800F1C0
	adds r1, r4, 0
	adds r1, 0xB8
	str r0, [r1]
	cmp r0, 0
	beq _0800E218
	str r7, [r4]
	bl sub_800E2F0
	str r0, [r4, 0x4]
	adds r1, r4, 0
	adds r1, 0xC
	adds r0, r6, 0
	ldm r0!, {r2,r3,r5}
	stm r1!, {r2,r3,r5}
	ldm r0!, {r2,r3,r5}
	stm r1!, {r2,r3,r5}
	ldm r0!, {r2,r3,r5}
	stm r1!, {r2,r3,r5}
	ldr r0, [r0]
	str r0, [r1]
	adds r0, r4, 0
	bl sub_800E0B4
	ldr r0, [r4, 0x4]
	b _0800E2B0
	.align 2, 0
_0800E2A0: .4byte gUnknown_203B0CC
_0800E2A4: .4byte 0x00001a04
_0800E2A8:
	adds r1, 0x1
	adds r4, 0xD0
	cmp r1, 0x1F
	ble _0800E226
_0800E2B0:
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_800E208

	thumb_func_start sub_800E2B8
sub_800E2B8:
	ldr r0, [r0, 0x4]
	ldr r0, [r0, 0x8]
	bx lr
	thumb_func_end sub_800E2B8

	thumb_func_start sub_800E2C0
sub_800E2C0:
	push {lr}
	adds r3, r0, 0
	movs r0, 0x1
	negs r0, r0
	cmp r3, r0
	beq _0800E2E8
	ldr r0, _0800E2DC
	ldr r1, [r0]
	movs r2, 0
_0800E2D2:
	ldr r0, [r1, 0x4]
	cmp r0, r3
	bne _0800E2E0
	adds r0, r2, 0
	b _0800E2EC
	.align 2, 0
_0800E2DC: .4byte gUnknown_203B0CC
_0800E2E0:
	adds r2, 0x1
	adds r1, 0xD0
	cmp r2, 0x1F
	ble _0800E2D2
_0800E2E8:
	movs r0, 0x1
	negs r0, r0
_0800E2EC:
	pop {r1}
	bx r1
	thumb_func_end sub_800E2C0

	thumb_func_start sub_800E2F0
sub_800E2F0:
	ldr r0, _0800E304
	ldr r1, [r0]
	movs r0, 0xD0
	lsls r0, 5
	adds r1, r0
	ldr r0, [r1]
	adds r2, r0, 0x1
	str r2, [r1]
	bx lr
	.align 2, 0
_0800E304: .4byte gUnknown_203B0CC
	thumb_func_end sub_800E2F0

	thumb_func_start sub_800E308
sub_800E308:
	push {r4-r7,lr}
	sub sp, 0x50
	adds r4, r0, 0
	adds r7, r1, 0
	ldrh r0, [r4]
	bl sub_800ECB8
	movs r1, 0x6
	ldrsh r0, [r0, r1]
	str r0, [sp, 0x28]
	ldr r0, [r4, 0x10]
	str r0, [sp, 0x2C]
	ldr r0, [r4, 0xC]
	str r0, [sp, 0x30]
	ldr r0, [r4, 0x4]
	str r0, [sp, 0x34]
	ldr r0, [r4, 0x8]
	str r0, [sp, 0x38]
	movs r2, 0x2
	ldrsh r0, [r4, r2]
	ldrh r1, [r4]
	bl sub_800E750
	str r0, [sp, 0x3C]
	ldr r0, _0800E3A0
	str r0, [sp, 0x40]
	add r1, sp, 0x44
	ldr r0, _0800E3A4
	ldm r0!, {r2,r3,r5}
	stm r1!, {r2,r3,r5}
	add r1, sp, 0x28
	mov r0, sp
	movs r2, 0x28
	bl memcpy
	movs r0, 0x2
	mov r1, sp
	bl sub_800E208
	adds r5, r0, 0
	movs r6, 0x1
	negs r6, r6
	cmp r5, r6
	beq _0800E396
	adds r0, r5, 0
	bl sub_800E2C0
	adds r1, r0, 0
	cmp r1, r6
	beq _0800E396
	ldr r2, _0800E3A8
	movs r0, 0xD0
	muls r1, r0
	ldr r0, [r2]
	adds r2, r0, r1
	adds r1, r2, 0
	adds r1, 0xBC
	ldr r0, [r4, 0x4]
	str r0, [r1]
	adds r1, 0x4
	ldr r0, [r7]
	str r0, [r1]
	ldrh r1, [r4, 0x2]
	adds r0, r2, 0
	adds r0, 0xC4
	strh r1, [r0]
	adds r1, r2, 0
	adds r1, 0xC8
	ldr r0, [r2, 0x1C]
	str r0, [r1]
	adds r0, r5, 0
_0800E396:
	add sp, 0x50
	pop {r4-r7}
	pop {r1}
	bx r1
	.align 2, 0
_0800E3A0: .4byte 0x0000ffff
_0800E3A4: .4byte gUnknown_80B9C60
_0800E3A8: .4byte gUnknown_203B0CC
	thumb_func_end sub_800E308

	thumb_func_start sub_800E3AC
sub_800E3AC:
	push {r4-r6,lr}
	adds r4, r1, 0
	adds r6, r2, 0
	bl sub_800E2C0
	adds r1, r0, 0
	movs r0, 0x1
	negs r0, r0
	cmp r1, r0
	beq _0800E43C
	ldr r2, _0800E444
	movs r0, 0xD0
	muls r1, r0
	ldr r0, [r2]
	adds r5, r0, r1
	ldr r0, [r4]
	str r0, [r5, 0x18]
	adds r0, r5, 0
	adds r0, 0xC0
	movs r2, 0
	ldrsh r1, [r0, r2]
	subs r0, 0x4
	movs r3, 0
	ldrsh r0, [r0, r3]
	subs r2, r1, r0
	cmp r2, 0
	bge _0800E3E4
	negs r2, r2
_0800E3E4:
	adds r0, r5, 0
	adds r0, 0xC2
	movs r3, 0
	ldrsh r1, [r0, r3]
	subs r0, 0x4
	movs r3, 0
	ldrsh r0, [r0, r3]
	subs r1, r0
	cmp r1, 0
	bge _0800E3FA
	negs r1, r1
_0800E3FA:
	cmp r1, r2
	bge _0800E400
	adds r1, r2, 0
_0800E400:
	cmp r1, 0
	bge _0800E406
	adds r1, 0x3
_0800E406:
	asrs r4, r1, 2
	subs r1, r4, 0x1
	ldrh r0, [r5, 0x1E]
	adds r0, 0x9
	strh r0, [r5, 0x1E]
	movs r2, 0x1C
	ldrsh r0, [r5, r2]
	muls r0, r1
	strh r0, [r5, 0x1C]
	movs r3, 0x1E
	ldrsh r0, [r5, r3]
	muls r0, r1
	strh r0, [r5, 0x1E]
	movs r1, 0x1C
	ldrsh r0, [r5, r1]
	adds r1, r4, 0
	bl __divsi3
	strh r0, [r5, 0x1C]
	movs r2, 0x1E
	ldrsh r0, [r5, r2]
	adds r1, r4, 0
	bl __divsi3
	subs r0, 0x9
	strh r0, [r5, 0x1E]
	str r6, [r5, 0x24]
_0800E43C:
	pop {r4-r6}
	pop {r0}
	bx r0
	.align 2, 0
_0800E444: .4byte gUnknown_203B0CC
	thumb_func_end sub_800E3AC

	thumb_func_start sub_800E448
sub_800E448:
	push {r4,lr}
	sub sp, 0x50
	adds r4, r1, 0
	lsls r0, 24
	lsrs r0, 24
	bl sub_800ECE4
	lsls r0, 16
	asrs r0, 16
	str r0, [sp, 0x28]
	movs r2, 0
	str r2, [sp, 0x2C]
	movs r1, 0x1
	negs r1, r1
	str r1, [sp, 0x30]
	ldr r0, [r4]
	str r0, [sp, 0x34]
	str r2, [sp, 0x38]
	str r1, [sp, 0x3C]
	ldr r0, _0800E494
	str r0, [sp, 0x40]
	add r1, sp, 0x44
	ldr r0, _0800E498
	ldm r0!, {r2-r4}
	stm r1!, {r2-r4}
	add r1, sp, 0x28
	mov r0, sp
	movs r2, 0x28
	bl memcpy
	movs r0, 0x3
	mov r1, sp
	bl sub_800E208
	add sp, 0x50
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_0800E494: .4byte 0x0000ffff
_0800E498: .4byte gUnknown_80B9C60
	thumb_func_end sub_800E448

	thumb_func_start sub_800E49C
sub_800E49C:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0x50
	adds r7, r1, 0
	mov r8, r2
	lsls r0, 24
	lsrs r0, 24
	lsls r3, 24
	lsrs r6, r3, 24
	cmp r6, 0
	beq _0800E4BA
	bl sub_800ECF8
	b _0800E4BE
_0800E4BA:
	bl sub_800ED0C
_0800E4BE:
	lsls r0, 16
	asrs r4, r0, 16
	adds r0, r4, 0
	bl sub_800E700
	adds r5, r0, 0
	str r4, [sp, 0x28]
	movs r1, 0
	str r1, [sp, 0x2C]
	movs r4, 0x1
	negs r4, r4
	str r4, [sp, 0x30]
	ldr r0, [r7]
	str r0, [sp, 0x34]
	str r1, [sp, 0x38]
	str r4, [sp, 0x3C]
	str r1, [sp, 0x40]
	add r1, sp, 0x44
	ldr r0, _0800E508
	ldm r0!, {r2,r3,r7}
	stm r1!, {r2,r3,r7}
	add r1, sp, 0x28
	mov r0, sp
	movs r2, 0x28
	bl memcpy
	ldr r0, [sp, 0x68]
	str r0, [sp, 0x18]
	cmp r6, 0
	beq _0800E50C
	cmp r5, r4
	beq _0800E516
	str r5, [sp, 0x14]
	lsls r0, r5, 2
	add r0, r8
	ldr r0, [r0]
	b _0800E514
	.align 2, 0
_0800E508: .4byte gUnknown_80B9C60
_0800E50C:
	movs r0, 0x3
	str r0, [sp, 0x14]
	mov r1, r8
	ldr r0, [r1, 0xC]
_0800E514:
	str r0, [sp, 0x10]
_0800E516:
	movs r0, 0x4
	mov r1, sp
	bl sub_800E208
	add sp, 0x50
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_800E49C

	thumb_func_start sub_800E52C
sub_800E52C:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x1B0
	adds r7, r0, 0
	ldrh r0, [r7]
	cmp r0, 0x52
	bne _0800E628
	mov r1, sp
	ldr r0, _0800E618
	ldm r0!, {r2-r4}
	stm r1!, {r2-r4}
	ldm r0!, {r2,r3,r5}
	stm r1!, {r2,r3,r5}
	ldm r0!, {r4,r5}
	stm r1!, {r4,r5}
	movs r0, 0
	mov r10, r0
	mov r9, r0
	mov r8, sp
	add r6, sp, 0x20
	adds r4, r6, 0
_0800E55C:
	ldrh r0, [r7]
	bl sub_800ECB8
	movs r1, 0x2
	ldrsh r0, [r0, r1]
	str r0, [r4]
	ldr r0, [r7, 0x10]
	str r0, [r4, 0x4]
	ldr r0, [r7, 0xC]
	str r0, [r4, 0x8]
	ldr r0, [r7, 0x4]
	str r0, [r4, 0xC]
	ldrh r0, [r4, 0xE]
	adds r0, 0x40
	strh r0, [r4, 0xE]
	ldr r0, [r7, 0x8]
	str r0, [r4, 0x10]
	mov r2, r8
	ldrh r0, [r2]
	ldrh r3, [r4, 0x10]
	adds r0, r3
	strh r0, [r4, 0x10]
	ldrh r0, [r4, 0x12]
	subs r0, 0x40
	ldrh r5, [r2, 0x2]
	adds r0, r5
	strh r0, [r4, 0x12]
	movs r1, 0x2
	ldrsh r0, [r7, r1]
	ldrh r1, [r7]
	bl sub_800E750
	str r0, [r4, 0x14]
	ldr r0, _0800E61C
	str r0, [r4, 0x18]
	adds r1, r6, 0
	adds r1, 0x1C
	ldr r0, _0800E620
	ldm r0!, {r2,r3,r5}
	stm r1!, {r2,r3,r5}
	movs r0, 0x1
	adds r1, r6, 0
	bl sub_800E208
	adds r5, r0, 0
	bl sub_800E2C0
	adds r1, r0, 0
	movs r0, 0x1
	negs r0, r0
	cmp r1, r0
	beq _0800E5D4
	ldr r2, _0800E624
	movs r0, 0xD0
	muls r1, r0
	ldr r0, [r2]
	adds r0, r1
	adds r0, 0xCC
	movs r1, 0x6
	strh r1, [r0]
_0800E5D4:
	mov r0, r9
	cmp r0, 0
	bne _0800E5DC
	mov r10, r5
_0800E5DC:
	movs r1, 0x4
	add r8, r1
	adds r4, 0x28
	adds r6, 0x28
	movs r2, 0x1
	add r9, r2
	mov r3, r9
	cmp r3, 0x7
	ble _0800E55C
	movs r4, 0x6
	mov r9, r4
_0800E5F2:
	ldrh r0, [r7]
	bl sub_800ECB8
	movs r5, 0x2
	ldrsh r0, [r0, r5]
	bl sub_800ECA4
	ldr r0, [r0, 0x4]
	bl sub_800F15C
	movs r0, 0x1
	negs r0, r0
	add r9, r0
	mov r1, r9
	cmp r1, 0
	bge _0800E5F2
	mov r0, r10
	b _0800E67E
	.align 2, 0
_0800E618: .4byte gUnknown_80B9C7C
_0800E61C: .4byte 0x0000ffff
_0800E620: .4byte gUnknown_80B9C60
_0800E624: .4byte gUnknown_203B0CC
_0800E628:
	add r6, sp, 0x160
	add r5, sp, 0x188
	ldrh r0, [r7]
	bl sub_800ECB8
	movs r2, 0x2
	ldrsh r0, [r0, r2]
	str r0, [r5]
	add r1, sp, 0x18C
	ldr r0, [r7, 0x10]
	str r0, [r1]
	add r1, sp, 0x190
	ldr r0, [r7, 0xC]
	str r0, [r1]
	add r1, sp, 0x194
	ldr r0, [r7, 0x4]
	str r0, [r1]
	add r1, sp, 0x198
	ldr r0, [r7, 0x8]
	str r0, [r1]
	add r4, sp, 0x19C
	movs r3, 0x2
	ldrsh r0, [r7, r3]
	ldrh r1, [r7]
	bl sub_800E750
	str r0, [r4]
	add r1, sp, 0x1A0
	ldr r0, _0800E690
	str r0, [r1]
	add r1, sp, 0x1A4
	ldr r0, _0800E694
	ldm r0!, {r2-r4}
	stm r1!, {r2-r4}
	adds r0, r6, 0
	adds r1, r5, 0
	movs r2, 0x28
	bl memcpy
	movs r0, 0x1
	adds r1, r6, 0
	bl sub_800E208
_0800E67E:
	add sp, 0x1B0
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	.align 2, 0
_0800E690: .4byte 0x0000ffff
_0800E694: .4byte gUnknown_80B9C60
	thumb_func_end sub_800E52C

	thumb_func_start sub_800E698
sub_800E698:
	push {r4,r5,lr}
	adds r4, r1, 0
	adds r5, r2, 0
	bl sub_800E2C0
	adds r1, r0, 0
	movs r3, 0x1
	negs r3, r3
	cmp r1, r3
	beq _0800E6D2
	ldr r2, _0800E6C8
	movs r0, 0xD0
	muls r1, r0
	ldr r0, [r2]
	adds r1, r0, r1
	ldr r0, [r4]
	str r0, [r1, 0x18]
	ldr r0, [r1, 0x20]
	cmp r0, r3
	beq _0800E6CC
	ldr r0, [r5]
	str r0, [r1, 0x1C]
	b _0800E6D2
	.align 2, 0
_0800E6C8: .4byte gUnknown_203B0CC
_0800E6CC:
	movs r0, 0
	strh r0, [r1, 0x1C]
	strh r0, [r1, 0x1E]
_0800E6D2:
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_800E698

	thumb_func_start sub_800E6D8
sub_800E6D8:
	push {lr}
	bl sub_800E2C0
	adds r1, r0, 0
	movs r0, 0x1
	negs r0, r0
	cmp r1, r0
	bne _0800E6EC
	adds r0, r1, 0
	b _0800E6F8
_0800E6EC:
	ldr r2, _0800E6FC
	movs r0, 0xD0
	muls r1, r0
	ldr r0, [r2]
	adds r0, r1
	ldr r0, [r0, 0x20]
_0800E6F8:
	pop {r1}
	bx r1
	.align 2, 0
_0800E6FC: .4byte gUnknown_203B0CC
	thumb_func_end sub_800E6D8

	thumb_func_start sub_800E700
sub_800E700:
	push {lr}
	lsls r0, 16
	asrs r0, 16
	bl sub_800E900
	pop {r1}
	bx r1
	thumb_func_end sub_800E700

	thumb_func_start sub_800E710
sub_800E710:
	push {r4-r6,lr}
	lsls r0, 16
	asrs r5, r0, 16
	lsls r1, 16
	lsrs r1, 16
	adds r0, r1, 0
	bl sub_800ECB8
	adds r4, r0, 0
	ldr r0, [r4, 0x20]
	bl sub_800ECD0
	adds r1, r0, 0
	movs r2, 0
	ldr r0, [r4, 0x1C]
	cmp r2, r0
	bge _0800E748
	adds r3, r0, 0
_0800E734:
	movs r6, 0
	ldrsh r0, [r1, r6]
	cmp r0, r5
	bne _0800E740
	ldr r0, [r1, 0x4]
	b _0800E74A
_0800E740:
	adds r2, 0x1
	adds r1, 0xC
	cmp r2, r3
	blt _0800E734
_0800E748:
	ldr r0, [r4, 0x14]
_0800E74A:
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end sub_800E710

	thumb_func_start sub_800E750
sub_800E750:
	push {r4-r6,lr}
	lsls r0, 16
	asrs r5, r0, 16
	lsls r1, 16
	lsrs r1, 16
	adds r0, r1, 0
	bl sub_800ECB8
	adds r4, r0, 0
	ldr r0, [r4, 0x20]
	bl sub_800ECD0
	adds r1, r0, 0
	movs r2, 0
	ldr r0, [r4, 0x1C]
	cmp r2, r0
	bge _0800E788
	adds r3, r0, 0
_0800E774:
	movs r6, 0
	ldrsh r0, [r1, r6]
	cmp r0, r5
	bne _0800E780
	ldr r0, [r1, 0x4]
	b _0800E78A
_0800E780:
	adds r2, 0x1
	adds r1, 0xC
	cmp r2, r3
	blt _0800E774
_0800E788:
	ldr r0, [r4, 0x14]
_0800E78A:
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end sub_800E750

	thumb_func_start sub_800E790
sub_800E790:
	push {r4-r6,lr}
	lsls r0, 16
	asrs r5, r0, 16
	lsls r1, 16
	lsrs r1, 16
	adds r0, r1, 0
	bl sub_800ECB8
	adds r4, r0, 0
	ldr r0, [r4, 0x20]
	bl sub_800ECD0
	adds r1, r0, 0
	movs r2, 0
	ldr r0, [r4, 0x1C]
	cmp r2, r0
	bge _0800E7C8
	adds r3, r0, 0
_0800E7B4:
	movs r6, 0
	ldrsh r0, [r1, r6]
	cmp r0, r5
	bne _0800E7C0
	ldr r0, [r1, 0x8]
	b _0800E7CA
_0800E7C0:
	adds r2, 0x1
	adds r1, 0xC
	cmp r2, r3
	blt _0800E7B4
_0800E7C8:
	ldr r0, [r4, 0x18]
_0800E7CA:
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end sub_800E790

	thumb_func_start sub_800E7D0
sub_800E7D0:
	push {r4-r6,lr}
	sub sp, 0x10
	adds r4, r0, 0
	movs r6, 0
	ldrh r0, [r4]
	bl sub_800ECB8
	movs r1, 0
	ldrsh r0, [r0, r1]
	str r0, [sp]
	ldrh r0, [r4]
	bl sub_800ECB8
	movs r1, 0x2
	ldrsh r0, [r0, r1]
	str r0, [sp, 0x4]
	ldrh r0, [r4]
	bl sub_800ECB8
	movs r1, 0x4
	ldrsh r0, [r0, r1]
	str r0, [sp, 0x8]
	ldrh r0, [r4]
	bl sub_800ECB8
	movs r1, 0x6
	ldrsh r0, [r0, r1]
	str r0, [sp, 0xC]
	movs r5, 0
	mov r4, sp
	b _0800E812
_0800E80E:
	adds r4, 0x4
	adds r5, 0x1
_0800E812:
	cmp r5, 0x3
	bgt _0800E82C
	ldr r0, [r4]
	bl sub_800ECA4
	movs r1, 0
	ldr r0, [r0]
	cmp r0, 0x4
	bne _0800E826
	movs r1, 0x1
_0800E826:
	adds r6, r1, 0
	cmp r6, 0
	beq _0800E80E
_0800E82C:
	adds r0, r6, 0
	add sp, 0x10
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end sub_800E7D0

	thumb_func_start sub_800E838
sub_800E838:
	push {r4,r5,lr}
	sub sp, 0x10
	adds r4, r0, 0
	adds r5, r1, 0
	ldrh r0, [r4]
	bl sub_800ECB8
	movs r1, 0
	ldrsh r0, [r0, r1]
	str r0, [sp]
	ldrh r0, [r4]
	bl sub_800ECB8
	movs r1, 0x2
	ldrsh r0, [r0, r1]
	str r0, [sp, 0x4]
	ldrh r0, [r4]
	bl sub_800ECB8
	movs r1, 0x4
	ldrsh r0, [r0, r1]
	str r0, [sp, 0x8]
	ldrh r0, [r4]
	bl sub_800ECB8
	movs r1, 0x6
	ldrsh r0, [r0, r1]
	str r0, [sp, 0xC]
	lsls r5, 2
	mov r1, sp
	adds r0, r1, r5
	ldr r0, [r0]
	bl sub_800ECA4
	movs r1, 0
	ldr r0, [r0]
	cmp r0, 0x4
	bne _0800E886
	movs r1, 0x1
_0800E886:
	adds r0, r1, 0
	add sp, 0x10
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_800E838

	thumb_func_start sub_800E890
sub_800E890:
	push {r4,lr}
	adds r4, r0, 0
	ldr r0, [r4]
	bl sub_800E900
	str r0, [r4, 0x14]
	movs r0, 0x7
	adds r1, r4, 0
	bl sub_800E208
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_800E890

	thumb_func_start sub_800E8AC
sub_800E8AC:
	push {r4-r7,lr}
	adds r4, r1, 0
	adds r5, r2, 0
	adds r6, r3, 0
	ldr r7, [sp, 0x14]
	bl sub_800E2C0
	adds r1, r0, 0
	movs r0, 0x1
	negs r0, r0
	cmp r1, r0
	beq _0800E8F2
	ldr r2, _0800E8F8
	movs r0, 0xD0
	muls r1, r0
	ldr r0, [r2]
	adds r1, r0, r1
	cmp r4, 0
	beq _0800E8D6
	ldr r0, [r4]
	str r0, [r1, 0x18]
_0800E8D6:
	cmp r5, 0
	beq _0800E8DE
	ldr r0, [r5]
	str r0, [r1, 0x1C]
_0800E8DE:
	ldr r0, _0800E8FC
	cmp r6, r0
	beq _0800E8E6
	str r6, [r1, 0x24]
_0800E8E6:
	cmp r7, 0
	beq _0800E8F2
	adds r1, 0x28
	adds r0, r7, 0
	ldm r0!, {r2-r4}
	stm r1!, {r2-r4}
_0800E8F2:
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_0800E8F8: .4byte gUnknown_203B0CC
_0800E8FC: .4byte 0x0000ffff
	thumb_func_end sub_800E8AC

	thumb_func_start sub_800E900
sub_800E900:
	push {lr}
	bl sub_800ECA4
	ldr r0, [r0, 0x1C]
	pop {r1}
	bx r1
	thumb_func_end sub_800E900

	thumb_func_start sub_800E90C
sub_800E90C:
	push {r4-r7,lr}
	adds r5, r0, 0
	movs r7, 0
	ldr r0, _0800E938
	ldr r4, [r0]
	movs r6, 0x1F
_0800E918:
	ldr r1, [r4, 0x4]
	movs r0, 0x1
	negs r0, r0
	cmp r1, r0
	beq _0800E960
	ldr r0, [r4, 0x10]
	cmp r0, 0
	bgt _0800E94A
	ldr r0, [r4, 0x34]
	cmp r0, 0x4
	bne _0800E93C
	adds r0, r4, 0
	adds r1, r5, 0
	bl sub_800DE8C
	b _0800E944
	.align 2, 0
_0800E938: .4byte gUnknown_203B0CC
_0800E93C:
	adds r0, r4, 0
	adds r1, r5, 0
	bl sub_800DD0C
_0800E944:
	ldr r0, [r4, 0x10]
	cmp r0, 0
	ble _0800E94E
_0800E94A:
	subs r0, 0x1
	str r0, [r4, 0x10]
_0800E94E:
	adds r0, r4, 0
	bl sub_800DCD0
	adds r0, r4, 0
	adds r0, 0x54
	ldrb r0, [r0]
	cmp r0, 0
	bne _0800E960
	movs r7, 0x1
_0800E960:
	subs r6, 0x1
	adds r4, 0xD0
	cmp r6, 0
	bge _0800E918
	adds r0, r7, 0
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_800E90C

	thumb_func_start sub_800E970
sub_800E970:
	push {r4,r5,lr}
	ldr r0, _0800E9A4
	ldr r4, [r0]
	movs r5, 0x1F
_0800E978:
	ldr r1, [r4, 0x4]
	movs r0, 0x1
	negs r0, r0
	cmp r1, r0
	beq _0800E994
	ldr r0, [r4, 0x10]
	cmp r0, 0
	bgt _0800E994
	ldr r0, [r4, 0x34]
	cmp r0, 0x4
	beq _0800E994
	adds r0, r4, 0
	bl sub_800DE38
_0800E994:
	subs r5, 0x1
	adds r4, 0xD0
	cmp r5, 0
	bge _0800E978
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_0800E9A4: .4byte gUnknown_203B0CC
	thumb_func_end sub_800E970

	thumb_func_start sub_800E9A8
sub_800E9A8:
	push {lr}
	adds r3, r0, 0
	movs r0, 0x1
	negs r0, r0
	cmp r3, r0
	beq _0800E9DC
	ldr r0, _0800E9D0
	ldr r1, [r0]
	movs r2, 0
_0800E9BA:
	ldr r0, [r1, 0x4]
	cmp r0, r3
	bne _0800E9D4
	adds r0, r1, 0
	adds r0, 0x54
	ldrb r0, [r0]
	cmp r0, 0
	bne _0800E9DC
	movs r0, 0x1
	b _0800E9DE
	.align 2, 0
_0800E9D0: .4byte gUnknown_203B0CC
_0800E9D4:
	adds r2, 0x1
	adds r1, 0xD0
	cmp r2, 0x1F
	ble _0800E9BA
_0800E9DC:
	movs r0, 0
_0800E9DE:
	pop {r1}
	bx r1
	thumb_func_end sub_800E9A8

	thumb_func_start sub_800E9E4
sub_800E9E4:
	push {lr}
	bl sub_800E2C0
	movs r1, 0x1
	negs r1, r1
	cmp r0, r1
	bne _0800E9F6
	movs r0, 0
	b _0800E9F8
_0800E9F6:
	movs r0, 0x1
_0800E9F8:
	pop {r1}
	bx r1
	thumb_func_end sub_800E9E4

	thumb_func_start sub_800E9FC
sub_800E9FC:
	push {r4,lr}
	lsls r0, 24
	lsrs r3, r0, 24
	ldr r0, _0800EA38
	ldr r1, [r0]
	movs r2, 0
	movs r4, 0x1
	negs r4, r4
_0800EA0C:
	ldr r0, [r1, 0x4]
	cmp r0, r4
	beq _0800EA20
	cmp r3, 0
	bne _0800EA3C
	adds r0, r1, 0
	adds r0, 0x54
	ldrb r0, [r0]
	cmp r0, 0
	beq _0800EA3C
_0800EA20:
	adds r2, 0x1
	adds r1, 0xD0
	cmp r2, 0x1F
	ble _0800EA0C
	bl sub_800EC74
	lsls r0, 24
	cmp r0, 0
	bne _0800EA3C
	movs r0, 0
	b _0800EA3E
	.align 2, 0
_0800EA38: .4byte gUnknown_203B0CC
_0800EA3C:
	movs r0, 0x1
_0800EA3E:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_800E9FC

	thumb_func_start sub_800EA44
sub_800EA44:
	push {r4-r6,lr}
	lsls r0, 16
	asrs r5, r0, 16
	lsls r1, 16
	lsrs r1, 16
	adds r0, r1, 0
	bl sub_800ECB8
	adds r4, r0, 0
	ldr r0, [r4, 0x20]
	bl sub_800ECD0
	adds r1, r0, 0
	movs r2, 0
	ldr r0, [r4, 0x1C]
	cmp r2, r0
	bge _0800EA7C
	adds r3, r0, 0
_0800EA68:
	movs r6, 0
	ldrsh r0, [r1, r6]
	cmp r0, r5
	bne _0800EA74
	ldrb r0, [r1, 0x2]
	b _0800EA7E
_0800EA74:
	adds r2, 0x1
	adds r1, 0xC
	cmp r2, r3
	blt _0800EA68
_0800EA7C:
	ldrb r0, [r4, 0x10]
_0800EA7E:
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end sub_800EA44

	thumb_func_start sub_800EA84
sub_800EA84:
	push {r4,lr}
	sub sp, 0x50
	adds r4, r0, 0
	ldrh r0, [r4]
	bl sub_800ECB8
	movs r1, 0
	ldrsh r0, [r0, r1]
	str r0, [sp, 0x28]
	ldr r0, [r4, 0x10]
	str r0, [sp, 0x2C]
	ldr r0, [r4, 0xC]
	str r0, [sp, 0x30]
	ldr r0, [r4, 0x4]
	str r0, [sp, 0x34]
	ldr r0, [r4, 0x8]
	str r0, [sp, 0x38]
	ldrh r0, [r4]
	bl sub_800ECB8
	movs r2, 0
	ldrsh r0, [r0, r2]
	bl sub_800EBBC
	str r0, [sp, 0x3C]
	ldr r0, _0800EADC
	str r0, [sp, 0x40]
	add r1, sp, 0x44
	ldr r0, _0800EAE0
	ldm r0!, {r2-r4}
	stm r1!, {r2-r4}
	add r1, sp, 0x28
	mov r0, sp
	movs r2, 0x28
	bl memcpy
	movs r0, 0x5
	mov r1, sp
	bl sub_800E208
	add sp, 0x50
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_0800EADC: .4byte 0x0000ffff
_0800EAE0: .4byte gUnknown_80B9C60
	thumb_func_end sub_800EA84

	thumb_func_start sub_800EAE4
sub_800EAE4:
	push {r4,r5,lr}
	adds r4, r1, 0
	adds r5, r2, 0
	bl sub_800E2C0
	adds r1, r0, 0
	movs r3, 0x1
	negs r3, r3
	cmp r1, r3
	beq _0800EB1E
	ldr r2, _0800EB14
	movs r0, 0xD0
	muls r1, r0
	ldr r0, [r2]
	adds r1, r0, r1
	ldr r0, [r4]
	str r0, [r1, 0x18]
	ldr r0, [r1, 0x20]
	cmp r0, r3
	beq _0800EB18
	ldr r0, [r5]
	str r0, [r1, 0x1C]
	b _0800EB1E
	.align 2, 0
_0800EB14: .4byte gUnknown_203B0CC
_0800EB18:
	movs r0, 0
	strh r0, [r1, 0x1C]
	strh r0, [r1, 0x1E]
_0800EB1E:
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_800EAE4

	thumb_func_start sub_800EB24
sub_800EB24:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0x20
	adds r6, r1, 0
	mov r8, r2
	adds r5, r3, 0
	ldr r4, [sp, 0x38]
	bl sub_800E2C0
	adds r1, r0, 0
	movs r0, 0x1
	negs r0, r0
	cmp r1, r0
	beq _0800EBB0
	ldr r2, _0800EB8C
	movs r0, 0xD0
	muls r1, r0
	ldr r0, [r2]
	adds r2, r0, r1
	adds r0, r2, 0
	adds r0, 0xCC
	ldr r0, [r0]
	cmp r0, 0
	bne _0800EB5A
	ldr r0, [r6]
	str r0, [r2, 0x18]
_0800EB5A:
	ldr r0, [r2]
	cmp r0, 0x6
	beq _0800EB94
	ldr r0, [r2, 0x8]
	movs r1, 0x7
	mov r12, r1
	ands r0, r1
	cmp r0, 0
	bne _0800EB94
	mov r1, sp
	ldr r0, _0800EB90
	ldm r0!, {r3,r6,r7}
	stm r1!, {r3,r6,r7}
	ldm r0!, {r3,r6,r7}
	stm r1!, {r3,r6,r7}
	ldm r0!, {r3,r6}
	stm r1!, {r3,r6}
	mov r7, r12
	ands r4, r7
	lsls r0, r4, 2
	add r0, sp
	ldr r0, [r0]
	adds r0, r5, r0
	b _0800EB96
	.align 2, 0
_0800EB8C: .4byte gUnknown_203B0CC
_0800EB90: .4byte gUnknown_80B9C9C
_0800EB94:
	adds r0, r5, 0x1
_0800EB96:
	str r0, [r2, 0x24]
	ldr r1, [r2, 0x20]
	movs r0, 0x1
	negs r0, r0
	cmp r1, r0
	beq _0800EBAA
	mov r1, r8
	ldr r0, [r1]
	str r0, [r2, 0x1C]
	b _0800EBB0
_0800EBAA:
	movs r0, 0
	strh r0, [r2, 0x1C]
	strh r0, [r2, 0x1E]
_0800EBB0:
	add sp, 0x20
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_800EB24

	thumb_func_start sub_800EBBC
sub_800EBBC:
	push {lr}
	bl sub_800ECA4
	ldr r0, [r0, 0x1C]
	pop {r1}
	bx r1
	thumb_func_end sub_800EBBC

	thumb_func_start sub_800EBC8
sub_800EBC8:
	push {r4,lr}
	sub sp, 0x50
	adds r4, r0, 0
	ldrh r0, [r4]
	bl sub_800ECB8
	movs r1, 0x4
	ldrsh r0, [r0, r1]
	str r0, [sp, 0x28]
	ldr r0, [r4, 0x10]
	str r0, [sp, 0x2C]
	ldr r0, [r4, 0xC]
	str r0, [sp, 0x30]
	ldr r0, [r4, 0x4]
	str r0, [sp, 0x34]
	ldr r0, [r4, 0x8]
	str r0, [sp, 0x38]
	ldrh r0, [r4]
	bl sub_800ECB8
	movs r2, 0x4
	ldrsh r0, [r0, r2]
	bl sub_800EC68
	str r0, [sp, 0x3C]
	ldr r0, _0800EC20
	str r0, [sp, 0x40]
	add r1, sp, 0x44
	ldr r0, _0800EC24
	ldm r0!, {r2-r4}
	stm r1!, {r2-r4}
	add r1, sp, 0x28
	mov r0, sp
	movs r2, 0x28
	bl memcpy
	movs r0, 0x6
	mov r1, sp
	bl sub_800E208
	add sp, 0x50
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_0800EC20: .4byte 0x0000ffff
_0800EC24: .4byte gUnknown_80B9C60
	thumb_func_end sub_800EBC8

	thumb_func_start sub_800EC28
sub_800EC28:
	push {r4,r5,lr}
	adds r4, r1, 0
	adds r5, r2, 0
	bl sub_800E2C0
	adds r1, r0, 0
	movs r3, 0x1
	negs r3, r3
	cmp r1, r3
	beq _0800EC62
	ldr r2, _0800EC58
	movs r0, 0xD0
	muls r1, r0
	ldr r0, [r2]
	adds r1, r0, r1
	ldr r0, [r4]
	str r0, [r1, 0x18]
	ldr r0, [r1, 0x20]
	cmp r0, r3
	beq _0800EC5C
	ldr r0, [r5]
	str r0, [r1, 0x1C]
	b _0800EC62
	.align 2, 0
_0800EC58: .4byte gUnknown_203B0CC
_0800EC5C:
	movs r0, 0
	strh r0, [r1, 0x1C]
	strh r0, [r1, 0x1E]
_0800EC62:
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_800EC28

	thumb_func_start sub_800EC68
sub_800EC68:
	push {lr}
	bl sub_800ECA4
	ldr r0, [r0, 0x1C]
	pop {r1}
	bx r1
	thumb_func_end sub_800EC68

	thumb_func_start sub_800EC74
sub_800EC74:
	push {lr}
	movs r0, 0x1
	bl sub_800F19C
	lsls r0, 24
	lsrs r0, 24
	pop {r1}
	bx r1
	thumb_func_end sub_800EC74

	thumb_func_start sub_800EC84
sub_800EC84:
	push {lr}
	lsls r0, 16
	lsrs r0, 16
	bl sub_800ECB8
	ldrb r0, [r0, 0x8]
	pop {r1}
	bx r1
	thumb_func_end sub_800EC84

	thumb_func_start sub_800EC94
sub_800EC94:
	push {lr}
	lsls r0, 16
	lsrs r0, 16
	bl sub_800ECB8
	ldrb r0, [r0, 0x9]
	pop {r1}
	bx r1
	thumb_func_end sub_800EC94

	thumb_func_start sub_800ECA4
sub_800ECA4:
	adds r1, r0, 0
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 2
	ldr r1, _0800ECB4
	adds r0, r1
	bx lr
	.align 2, 0
_0800ECB4: .4byte gUnknown_80B9CC4
	thumb_func_end sub_800ECA4

	thumb_func_start sub_800ECB8
sub_800ECB8:
	adds r1, r0, 0
	lsls r1, 16
	lsrs r1, 16
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 2
	ldr r1, _0800ECCC
	adds r0, r1
	bx lr
	.align 2, 0
_0800ECCC: .4byte gUnknown_80BDBC4
	thumb_func_end sub_800ECB8

	thumb_func_start sub_800ECD0
sub_800ECD0:
	adds r1, r0, 0
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 2
	ldr r1, _0800ECE0
	adds r0, r1
	bx lr
	.align 2, 0
_0800ECE0: .4byte gUnknown_80C183C
	thumb_func_end sub_800ECD0

	thumb_func_start sub_800ECE4
sub_800ECE4:
	lsls r0, 24
	ldr r1, _0800ECF4
	lsrs r0, 23
	adds r0, r1
	movs r1, 0
	ldrsh r0, [r0, r1]
	bx lr
	.align 2, 0
_0800ECF4: .4byte gUnknown_80CE73C
	thumb_func_end sub_800ECE4

	thumb_func_start sub_800ECF8
sub_800ECF8:
	lsls r0, 24
	ldr r1, _0800ED08
	lsrs r0, 22
	adds r0, r1
	movs r1, 0
	ldrsh r0, [r0, r1]
	bx lr
	.align 2, 0
_0800ED08: .4byte gUnknown_80CE37C
	thumb_func_end sub_800ECF8

	thumb_func_start sub_800ED0C
sub_800ED0C:
	lsls r0, 24
	ldr r1, _0800ED1C
	lsrs r0, 22
	adds r0, r1
	movs r1, 0x2
	ldrsh r0, [r0, r1]
	bx lr
	.align 2, 0
_0800ED1C: .4byte gUnknown_80CE37C
	thumb_func_end sub_800ED0C

	thumb_func_start sub_800ED20
sub_800ED20:
	lsls r0, 16
	lsrs r0, 16
	ldr r2, _0800ED34
	lsls r1, r0, 3
	adds r1, r0
	lsls r1, 2
	adds r2, 0xC
	adds r1, r2
	ldr r0, [r1]
	bx lr
	.align 2, 0
_0800ED34: .4byte gUnknown_80BDBC4
	thumb_func_end sub_800ED20

	thumb_func_start sub_800ED38
sub_800ED38:
	push {r4,r5,lr}
	adds r5, r0, 0
	ldr r4, _0800ED60
	ldr r0, [r4]
	cmp r0, 0
	bne _0800ED54
	movs r0, 0x4C
	movs r1, 0xB
	bl MemoryAlloc
	str r0, [r4]
	movs r1, 0x4C
	bl MemoryClear8
_0800ED54:
	ldr r0, [r4]
	str r5, [r0]
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_0800ED60: .4byte gUnknown_203B0D0
	thumb_func_end sub_800ED38

	thumb_func_start sub_800ED64
sub_800ED64:
	push {r4,lr}
	ldr r4, _0800ED7C
	ldr r0, [r4]
	cmp r0, 0
	beq _0800ED76
	bl MemoryFree
	movs r0, 0
	str r0, [r4]
_0800ED76:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0800ED7C: .4byte gUnknown_203B0D0
	thumb_func_end sub_800ED64

	thumb_func_start sub_800ED80
sub_800ED80:
	push {r4,lr}
	ldr r2, _0800EDAC
	ldr r1, [r2]
	movs r0, 0
	str r0, [r1]
	adds r4, r2, 0
	movs r3, 0
	movs r2, 0x4
	movs r1, 0x1
_0800ED92:
	ldr r0, [r4]
	adds r0, r2
	str r3, [r0]
	str r3, [r0, 0x4]
	str r3, [r0, 0x8]
	adds r2, 0x24
	subs r1, 0x1
	cmp r1, 0
	bge _0800ED92
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0800EDAC: .4byte gUnknown_203B0D0
	thumb_func_end sub_800ED80

	thumb_func_start sub_800EDB0
sub_800EDB0:
	push {r4,r5,lr}
	adds r4, r0, 0
	movs r3, 0
	ldr r5, _0800EDDC
	movs r2, 0
_0800EDBA:
	ldr r1, [r5]
	adds r0, r1, 0x4
	adds r0, r2
	ldr r0, [r0]
	cmp r0, 0
	bne _0800EDE0
	adds r1, r2
	adds r1, 0x4
	adds r0, r4, 0
	ldm r0!, {r2-r4}
	stm r1!, {r2-r4}
	ldm r0!, {r2-r4}
	stm r1!, {r2-r4}
	ldm r0!, {r2-r4}
	stm r1!, {r2-r4}
	movs r0, 0x1
	b _0800EDEA
	.align 2, 0
_0800EDDC: .4byte gUnknown_203B0D0
_0800EDE0:
	adds r2, 0x24
	adds r3, 0x1
	cmp r3, 0x1
	ble _0800EDBA
	movs r0, 0
_0800EDEA:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_800EDB0

	thumb_func_start sub_800EDF0
sub_800EDF0:
	push {r4,lr}
	sub sp, 0x24
	adds r4, r1, 0
	cmp r0, 0
	beq _0800EE00
	cmp r0, 0x1
	beq _0800EE1A
	b _0800EE44
_0800EE00:
	movs r0, 0x3
	str r0, [sp]
	movs r0, 0xE
	str r0, [sp, 0xC]
	movs r1, 0x1
	negs r1, r1
	str r1, [sp, 0x10]
	movs r0, 0xDC
	lsls r0, 2
	str r0, [sp, 0x18]
	movs r0, 0x1F
	str r0, [sp, 0x1C]
	b _0800EE40
_0800EE1A:
	movs r0, 0x4
	str r0, [sp]
	movs r0, 0xE
	str r0, [sp, 0xC]
	movs r0, 0xF0
	lsls r0, 4
	str r0, [sp, 0x10]
	movs r0, 0x1
	negs r0, r0
	str r0, [sp, 0x18]
	str r0, [sp, 0x1C]
	bl sub_8000728
	movs r2, 0x2
	eors r0, r2
	negs r1, r0
	orrs r1, r0
	asrs r1, 31
	ands r1, r2
_0800EE40:
	str r1, [sp, 0x14]
	str r4, [sp, 0x4]
_0800EE44:
	ldr r0, [r4, 0x4]
	str r0, [sp, 0x8]
	movs r0, 0
	str r0, [sp, 0x20]
	mov r0, sp
	bl sub_800EDB0
	add sp, 0x24
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_800EDF0

	thumb_func_start sub_800EE5C
sub_800EE5C:
	push {r4-r6,lr}
	adds r4, r0, 0
	bl sub_800ECA4
	adds r6, r0, 0
	cmp r4, 0
	beq _0800EEC2
	ldr r2, [r6]
	subs r0, r2, 0x1
	cmp r0, 0x1
	bls _0800EEC2
	ldr r1, [r6, 0x4]
	adds r0, r2, 0
	bl sub_800F1C0
	adds r5, r0, 0
	cmp r5, 0
	beq _0800EEC2
	ldr r0, [r6]
	ldr r1, [r6, 0x4]
	bl sub_800F0F4
	adds r4, r0, 0
	movs r0, 0x1
	negs r0, r0
	cmp r4, r0
	bne _0800EE9A
	adds r0, r5, 0
	bl sub_800F204
	b _0800EEC2
_0800EE9A:
	movs r0, 0x2
	negs r0, r0
	cmp r4, r0
	beq _0800EEB6
	adds r0, r4, 0
	adds r1, r5, 0
	adds r2, r6, 0
	bl sub_800F13C
	adds r0, r4, 0
	adds r1, r5, 0
	bl sub_800EDF0
	b _0800EEBC
_0800EEB6:
	adds r0, r5, 0
	bl sub_800F204
_0800EEBC:
	ldr r0, [r6, 0x4]
	bl sub_800F15C
_0800EEC2:
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end sub_800EE5C

	thumb_func_start sub_800EEC8
sub_800EEC8:
	push {lr}
	lsls r0, 16
	lsrs r0, 16
	bl sub_800ECB8
	movs r1, 0
	ldrsh r0, [r0, r1]
	bl sub_800EE5C
	pop {r0}
	bx r0
	thumb_func_end sub_800EEC8

	thumb_func_start sub_800EEE0
sub_800EEE0:
	push {lr}
	lsls r0, 16
	lsrs r0, 16
	bl sub_800ECB8
	movs r1, 0x4
	ldrsh r0, [r0, r1]
	bl sub_800EE5C
	pop {r0}
	bx r0
	thumb_func_end sub_800EEE0

	thumb_func_start sub_800EEF8
sub_800EEF8:
	push {lr}
	lsls r0, 16
	lsrs r0, 16
	bl sub_800ECB8
	movs r1, 0x2
	ldrsh r0, [r0, r1]
	bl sub_800EE5C
	pop {r0}
	bx r0
	thumb_func_end sub_800EEF8

	thumb_func_start sub_800EF10
sub_800EF10:
	push {lr}
	lsls r0, 16
	lsrs r0, 16
	bl sub_800ECB8
	movs r1, 0x6
	ldrsh r0, [r0, r1]
	bl sub_800EE5C
	pop {r0}
	bx r0
	thumb_func_end sub_800EF10

	thumb_func_start sub_800EF28
sub_800EF28:
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	bl sub_800ECE4
	lsls r0, 16
	asrs r0, 16
	bl sub_800EE5C
	pop {r0}
	bx r0
	thumb_func_end sub_800EF28

	thumb_func_start sub_800EF40
sub_800EF40:
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	lsls r1, 24
	cmp r1, 0
	beq _0800EF52
	bl sub_800ECF8
	b _0800EF56
_0800EF52:
	bl sub_800ED0C
_0800EF56:
	lsls r0, 16
	asrs r0, 16
	bl sub_800EE5C
	pop {r0}
	bx r0
	thumb_func_end sub_800EF40

	thumb_func_start sub_800EF64
sub_800EF64:
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	ldr r0, _0800EF9C
	mov r9, r0
	movs r1, 0x4
	mov r8, r1
	movs r7, 0
	movs r6, 0
	movs r5, 0x1
_0800EF7A:
	mov r0, r9
	ldr r1, [r0]
	adds r0, r1, 0x4
	adds r0, r7
	ldr r0, [r0]
	cmp r0, 0
	beq _0800F01A
	mov r0, r8
	adds r4, r1, r0
	ldr r0, [r4]
	cmp r0, 0x3
	beq _0800EFA0
	cmp r0, 0x3
	bls _0800F018
	cmp r0, 0x4
	beq _0800EFDA
	b _0800F018
	.align 2, 0
_0800EF9C: .4byte gUnknown_203B0D0
_0800EFA0:
	ldr r0, [r4, 0x8]
	ldr r1, [r4, 0x18]
	bl sub_8005674
	mov r1, r9
	ldr r0, [r1]
	ldr r0, [r0]
	cmp r0, 0
	beq _0800EFCA
	cmp r0, 0x1
	bne _0800F00C
	ldr r0, [r4, 0x8]
	ldr r1, [r0, 0x18]
	ldr r0, [r4, 0xC]
	adds r0, 0x10
	lsls r0, 20
	lsrs r0, 16
	movs r2, 0x10
	bl sub_809971C
	b _0800F00C
_0800EFCA:
	ldr r0, [r4, 0xC]
	ldr r1, [r4, 0x8]
	ldr r1, [r1, 0x18]
	ldr r2, [r4, 0x1C]
	ldr r3, [r4, 0x20]
	bl sub_8005770
	b _0800F00C
_0800EFDA:
	bl sub_8000728
	cmp r0, 0x1
	bne _0800F000
	movs r0, 0
	movs r1, 0x1
	bl sub_800CD64
	movs r0, 0
	bl sub_8052210
	movs r0, 0x5
	movs r1, 0
	bl sub_803EAF0
	bl sub_800CB20
	bl xxx_call_update_bg_vram
_0800F000:
	ldr r0, [r4, 0x8]
	ldr r1, [r4, 0xC]
	ldr r2, [r4, 0x10]
	ldr r3, [r4, 0x14]
	bl sub_8009A1C
_0800F00C:
	ldr r0, [r4, 0x4]
	cmp r0, 0
	beq _0800F018
	bl sub_800F204
	str r6, [r4, 0x4]
_0800F018:
	str r6, [r4]
_0800F01A:
	movs r0, 0x24
	add r8, r0
	adds r7, 0x24
	subs r5, 0x1
	cmp r5, 0
	bge _0800EF7A
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_800EF64

	thumb_func_start sub_800F034
sub_800F034:
	push {r4-r6,lr}
	ldr r4, _0800F074
	ldr r0, [r4]
	cmp r0, 0
	bne _0800F04E
	movs r0, 0x10
	movs r1, 0xB
	bl MemoryAlloc
	str r0, [r4]
	movs r1, 0x10
	bl MemoryClear8
_0800F04E:
	movs r3, 0
	adds r6, r4, 0
	movs r5, 0x1
	negs r5, r5
	movs r4, 0
_0800F058:
	ldr r0, [r6]
	lsls r2, r3, 3
	adds r1, r0, r2
	str r5, [r1]
	adds r0, 0x4
	adds r0, r2
	str r4, [r0]
	adds r3, 0x1
	cmp r3, 0x1
	ble _0800F058
	pop {r4-r6}
	pop {r0}
	bx r0
	.align 2, 0
_0800F074: .4byte gUnknown_203B0D4
	thumb_func_end sub_800F034

	thumb_func_start sub_800F078
sub_800F078:
	push {r4,lr}
	ldr r4, _0800F090
	ldr r0, [r4]
	cmp r0, 0
	beq _0800F08A
	bl MemoryFree
	movs r0, 0
	str r0, [r4]
_0800F08A:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0800F090: .4byte gUnknown_203B0D4
	thumb_func_end sub_800F078

	thumb_func_start sub_800F094
sub_800F094:
	push {r4-r6,lr}
	movs r3, 0
	ldr r6, _0800F0BC
	movs r5, 0x1
	negs r5, r5
	movs r4, 0
_0800F0A0:
	ldr r0, [r6]
	lsls r2, r3, 3
	adds r1, r0, r2
	str r5, [r1]
	adds r0, 0x4
	adds r0, r2
	str r4, [r0]
	adds r3, 0x1
	cmp r3, 0x1
	ble _0800F0A0
	pop {r4-r6}
	pop {r0}
	bx r0
	.align 2, 0
_0800F0BC: .4byte gUnknown_203B0D4
	thumb_func_end sub_800F094

	thumb_func_start sub_800F0C0
sub_800F0C0:
	push {lr}
	cmp r0, 0x3
	bne _0800F0D8
	ldr r0, _0800F0D4
	ldr r0, [r0]
	ldr r0, [r0]
	cmp r0, r1
	bne _0800F0EC
	movs r0, 0
	b _0800F0F0
	.align 2, 0
_0800F0D4: .4byte gUnknown_203B0D4
_0800F0D8:
	ldr r0, _0800F0E8
	ldr r0, [r0]
	ldr r0, [r0, 0x8]
	cmp r0, r1
	bne _0800F0EC
	movs r0, 0x1
	b _0800F0F0
	.align 2, 0
_0800F0E8: .4byte gUnknown_203B0D4
_0800F0EC:
	movs r0, 0x3
	negs r0, r0
_0800F0F0:
	pop {r1}
	bx r1
	thumb_func_end sub_800F0C0

	thumb_func_start sub_800F0F4
sub_800F0F4:
	push {lr}
	cmp r0, 0x3
	bne _0800F114
	ldr r0, _0800F110
	ldr r2, [r0]
	ldr r0, [r2]
	cmp r0, r1
	beq _0800F11E
	ldr r0, [r2, 0x4]
	cmp r0, 0
	bne _0800F132
	movs r0, 0
	b _0800F136
	.align 2, 0
_0800F110: .4byte gUnknown_203B0D4
_0800F114:
	ldr r0, _0800F124
	ldr r2, [r0]
	ldr r0, [r2, 0x8]
	cmp r0, r1
	bne _0800F128
_0800F11E:
	movs r0, 0x2
	negs r0, r0
	b _0800F136
	.align 2, 0
_0800F124: .4byte gUnknown_203B0D4
_0800F128:
	ldr r0, [r2, 0xC]
	cmp r0, 0
	bne _0800F132
	movs r0, 0x1
	b _0800F136
_0800F132:
	movs r0, 0x1
	negs r0, r0
_0800F136:
	pop {r1}
	bx r1
	thumb_func_end sub_800F0F4

	thumb_func_start sub_800F13C
sub_800F13C:
	push {lr}
	ldr r1, _0800F158
	ldr r3, [r1]
	lsls r1, r0, 3
	adds r0, r3, 0x4
	adds r0, r1
	ldr r0, [r0]
	cmp r0, 0
	bne _0800F154
	adds r1, r3, r1
	ldr r0, [r2, 0x4]
	str r0, [r1]
_0800F154:
	pop {r0}
	bx r0
	.align 2, 0
_0800F158: .4byte gUnknown_203B0D4
	thumb_func_end sub_800F13C

	thumb_func_start sub_800F15C
sub_800F15C:
	push {r4,r5,lr}
	adds r4, r0, 0
	movs r3, 0
	ldr r5, _0800F17C
_0800F164:
	ldr r1, [r5]
	lsls r2, r3, 3
	adds r0, r1, r2
	ldr r0, [r0]
	cmp r0, r4
	bne _0800F180
	adds r1, 0x4
	adds r1, r2
	ldr r0, [r1]
	adds r0, 0x1
	str r0, [r1]
	b _0800F186
	.align 2, 0
_0800F17C: .4byte gUnknown_203B0D4
_0800F180:
	adds r3, 0x1
	cmp r3, 0x1
	ble _0800F164
_0800F186:
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_800F15C

	thumb_func_start sub_800F18C
sub_800F18C:
	ldr r1, _0800F198
	lsls r0, 3
	ldr r1, [r1]
	adds r1, r0
	adds r0, r1, 0
	bx lr
	.align 2, 0
_0800F198: .4byte gUnknown_203B0D4
	thumb_func_end sub_800F18C

	thumb_func_start sub_800F19C
sub_800F19C:
	push {lr}
	ldr r1, _0800F1B4
	ldr r1, [r1]
	lsls r0, 3
	adds r1, 0x4
	adds r1, r0
	ldr r0, [r1]
	cmp r0, 0
	beq _0800F1B8
	movs r0, 0x1
	b _0800F1BA
	.align 2, 0
_0800F1B4: .4byte gUnknown_203B0D4
_0800F1B8:
	movs r0, 0
_0800F1BA:
	pop {r1}
	bx r1
	thumb_func_end sub_800F19C

	thumb_func_start sub_800F1C0
sub_800F1C0:
	push {lr}
	sub sp, 0x8
	adds r2, r1, 0
	cmp r0, 0x1
	bcc _0800F1EC
	cmp r0, 0x3
	bls _0800F1D4
	cmp r0, 0x4
	beq _0800F1E4
	b _0800F1EC
_0800F1D4:
	ldr r1, _0800F1E0
	mov r0, sp
	bl sprintf
	b _0800F1EC
	.align 2, 0
_0800F1E0: .4byte gUnknown_80CE77C
_0800F1E4:
	ldr r1, _0800F1FC
	mov r0, sp
	bl sprintf
_0800F1EC:
	ldr r1, _0800F200
	mov r0, sp
	bl Call_OpenFileAndGetFileDataPtr
	add sp, 0x8
	pop {r1}
	bx r1
	.align 2, 0
_0800F1FC: .4byte gUnknown_80CE788
_0800F200: .4byte gUnknown_9740000
	thumb_func_end sub_800F1C0

	thumb_func_start sub_800F204
sub_800F204:
	push {lr}
	bl CloseFile
	pop {r0}
	bx r0
	thumb_func_end sub_800F204

	thumb_func_start sub_800F210
sub_800F210:
	push {r4,lr}
	adds r4, r0, 0
	movs r3, 0
	ldr r0, _0800F230
	ldr r0, [r0]
	adds r1, r0, 0x4
	adds r2, r0, 0
	adds r2, 0x8
_0800F220:
	ldrb r0, [r1]
	cmp r0, 0
	beq _0800F234
	ldr r0, [r2]
	cmp r0, r4
	bne _0800F234
	adds r0, r1, 0
	b _0800F240
	.align 2, 0
_0800F230: .4byte gUnknown_203B0D8
_0800F234:
	adds r1, 0x40
	adds r2, 0x40
	adds r3, 0x1
	cmp r3, 0x15
	ble _0800F220
	movs r0, 0
_0800F240:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_800F210

	thumb_func_start sub_800F248
sub_800F248:
	push {lr}
	movs r2, 0
	ldr r0, _0800F25C
	ldr r0, [r0]
	adds r1, r0, 0x4
_0800F252:
	ldrb r0, [r1]
	cmp r0, 0
	bne _0800F260
	adds r0, r1, 0
	b _0800F26A
	.align 2, 0
_0800F25C: .4byte gUnknown_203B0D8
_0800F260:
	adds r1, 0x40
	adds r2, 0x1
	cmp r2, 0x15
	ble _0800F252
	movs r0, 0
_0800F26A:
	pop {r1}
	bx r1
	thumb_func_end sub_800F248

	thumb_func_start sub_800F270
sub_800F270:
	push {r4-r6,lr}
	adds r2, r0, 0
	lsls r0, r1, 3
	adds r0, 0x28
	adds r3, r2, r0
	movs r5, 0x80
	lsls r5, 21
	cmp r1, 0
	bne _0800F284
	movs r5, 0x1
_0800F284:
	movs r6, 0x80
	lsls r6, 21
	cmp r1, 0
	bne _0800F290
	movs r6, 0x80
	lsls r6, 20
_0800F290:
	movs r4, 0x1
	cmp r1, 0
	bne _0800F298
	movs r4, 0x1C
_0800F298:
	ldr r0, [r2, 0xC]
	cmp r0, 0
	bne _0800F2A4
	b _0800F2CC
_0800F2A0:
	adds r0, r1, 0
	b _0800F2CE
_0800F2A4:
	ldr r2, [r3]
	adds r1, r5, 0
	cmp r2, 0
	beq _0800F2AE
	adds r1, r2, 0
_0800F2AE:
	movs r2, 0
	cmp r2, r4
	bge _0800F2CC
	adds r3, r0, 0
_0800F2B6:
	lsls r1, 1
	cmp r1, r6
	bls _0800F2BE
	adds r1, r5, 0
_0800F2BE:
	adds r0, r3, 0
	ands r0, r1
	cmp r0, 0
	bne _0800F2A0
	adds r2, 0x1
	cmp r2, r4
	blt _0800F2B6
_0800F2CC:
	movs r0, 0
_0800F2CE:
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end sub_800F270

	thumb_func_start sub_800F2D4
sub_800F2D4:
	push {lr}
	movs r1, 0
	cmp r0, 0
	beq _0800F2E4
_0800F2DC:
	lsrs r0, 1
	adds r1, 0x1
	cmp r0, 0
	bne _0800F2DC
_0800F2E4:
	adds r0, r1, 0
	pop {r1}
	bx r1
	thumb_func_end sub_800F2D4

	thumb_func_start sub_800F2EC
sub_800F2EC:
	push {r4-r7,lr}
	sub sp, 0xC
	adds r5, r0, 0
	adds r6, r1, 0
	adds r7, r2, 0
	lsls r0, r6, 3
	adds r0, 0x28
	adds r4, r5, r0
	ldr r0, [r5, 0xC]
	cmp r0, 0
	bne _0800F306
	str r0, [r4]
	b _0800F35C
_0800F306:
	ldr r0, [r4]
	cmp r0, 0
	bne _0800F30E
	str r0, [r4, 0x4]
_0800F30E:
	ldr r0, [r4, 0x4]
	cmp r0, 0
	bgt _0800F32A
	adds r0, r5, 0
	adds r1, r6, 0
	bl sub_800F270
	adds r1, r0, 0
	ldr r0, [r4]
	cmp r0, r1
	beq _0800F326
	str r1, [r4]
_0800F326:
	movs r0, 0x3C
	b _0800F32C
_0800F32A:
	subs r0, 0x1
_0800F32C:
	str r0, [r4, 0x4]
	ldrb r0, [r5, 0x10]
	cmp r0, 0
	beq _0800F35C
	ldr r0, [r4]
	cmp r0, 0
	beq _0800F35C
	bl sub_800F2D4
	adds r1, r0, 0
	movs r2, 0x8
	ldrsh r0, [r5, r2]
	adds r2, r5, 0
	adds r2, 0x14
	lsls r3, r6, 2
	adds r3, 0x18
	adds r3, r5, r3
	str r7, [sp]
	ldrb r4, [r5, 0x11]
	str r4, [sp, 0x4]
	ldr r4, [r5, 0x4]
	str r4, [sp, 0x8]
	bl sub_800F364
_0800F35C:
	add sp, 0xC
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_800F2EC

	thumb_func_start sub_800F364
sub_800F364:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0x8
	mov r12, r2
	ldr r0, [sp, 0x20]
	mov r8, r0
	ldr r4, [sp, 0x24]
	ldr r0, _0800F410
	lsls r1, 3
	adds r2, r1, r0
	ldr r0, [r2]
	ldr r1, [r2, 0x4]
	str r0, [sp]
	str r1, [sp, 0x4]
	lsls r2, r0, 1
	ldr r1, [sp]
	adds r2, r1
	lsls r2, 3
	ldr r0, _0800F414
	adds r2, r0
	ldr r0, [r2, 0x8]
	ldr r6, _0800F418
	adds r7, r0, r6
	movs r0, 0x3
	ands r4, r0
	lsls r4, 10
	ldr r5, _0800F41C
	ldrh r1, [r5, 0x4]
	ldr r0, _0800F420
	ands r0, r1
	orrs r0, r4
	strh r0, [r5, 0x4]
	mov r0, r12
	movs r4, 0
	ldrsh r1, [r0, r4]
	ldr r0, [r2]
	lsls r0, 2
	subs r1, r0
	mov r6, r8
	movs r4, 0
	ldrsh r0, [r6, r4]
	subs r1, r0
	movs r6, 0
	ldrsh r0, [r3, r6]
	adds r4, r1, r0
	mov r0, r12
	movs r6, 0x2
	ldrsh r1, [r0, r6]
	ldr r0, [r2, 0x4]
	lsls r0, 2
	subs r1, r0
	mov r2, r8
	movs r6, 0x2
	ldrsh r0, [r2, r6]
	subs r1, r0
	movs r2, 0x2
	ldrsh r0, [r3, r2]
	adds r3, r1, r0
	adds r6, r3, 0
	subs r6, 0x10
	movs r0, 0x20
	negs r0, r0
	cmp r4, r0
	bge _0800F3E8
	b _0800F5E4
_0800F3E8:
	cmp r3, r0
	bge _0800F3EE
	b _0800F5E4
_0800F3EE:
	cmp r4, 0xEF
	ble _0800F3F4
	b _0800F5E4
_0800F3F4:
	cmp r3, 0x9F
	ble _0800F3FA
	b _0800F5E4
_0800F3FA:
	ldr r0, [sp]
	subs r0, 0x1
	cmp r0, 0xF
	bls _0800F404
	b _0800F5A6
_0800F404:
	lsls r0, 2
	ldr r1, _0800F424
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0800F410: .4byte gUnknown_80D3474
_0800F414: .4byte gUnknown_80CE79C
_0800F418: .4byte 0x0000032b
_0800F41C: .4byte gUnknown_203B0DC
_0800F420: .4byte 0x0000f3ff
_0800F424: .4byte _0800F428
	.align 2, 0
_0800F428:
	.4byte _0800F468
	.4byte _0800F4CC
	.4byte _0800F4CC
	.4byte _0800F574
	.4byte _0800F538
	.4byte _0800F4CC
	.4byte _0800F4CC
	.4byte _0800F498
	.4byte _0800F4CC
	.4byte _0800F4CC
	.4byte _0800F4CC
	.4byte _0800F468
	.4byte _0800F4CC
	.4byte _0800F468
	.4byte _0800F4CC
	.4byte _0800F500
_0800F468:
	ldrh r2, [r5]
	ldr r1, _0800F48C
	adds r0, r1, 0
	ands r0, r2
	strh r0, [r5]
	ldrh r0, [r5, 0x2]
	ands r1, r0
	ldr r0, _0800F490
	ands r4, r0
	movs r0, 0xFE
	lsls r0, 8
	ands r1, r0
	orrs r1, r4
	strh r1, [r5, 0x2]
	ldr r1, _0800F494
	ands r1, r6
	b _0800F59A
	.align 2, 0
_0800F48C: .4byte 0x00003fff
_0800F490: .4byte 0x000001ff
_0800F494: .4byte 0x00000fff
_0800F498:
	movs r3, 0x80
	lsls r3, 8
	ldrh r2, [r5]
	ldr r1, _0800F4C0
	adds r0, r1, 0
	ands r0, r2
	orrs r0, r3
	strh r0, [r5]
	ldrh r0, [r5, 0x2]
	ands r1, r0
	ldr r0, _0800F4C4
	ands r4, r0
	movs r0, 0xFE
	lsls r0, 8
	ands r1, r0
	orrs r1, r4
	strh r1, [r5, 0x2]
	ldr r1, _0800F4C8
	ands r1, r6
	b _0800F59A
	.align 2, 0
_0800F4C0: .4byte 0x00003fff
_0800F4C4: .4byte 0x000001ff
_0800F4C8: .4byte 0x00000fff
_0800F4CC:
	ldrh r2, [r5]
	ldr r1, _0800F4F4
	adds r0, r1, 0
	ands r0, r2
	strh r0, [r5]
	movs r2, 0x80
	lsls r2, 7
	ldrh r0, [r5, 0x2]
	ands r1, r0
	orrs r1, r2
	ldr r0, _0800F4F8
	ands r4, r0
	movs r0, 0xFE
	lsls r0, 8
	ands r1, r0
	orrs r1, r4
	strh r1, [r5, 0x2]
	ldr r1, _0800F4FC
	ands r1, r6
	b _0800F59A
	.align 2, 0
_0800F4F4: .4byte 0x00003fff
_0800F4F8: .4byte 0x000001ff
_0800F4FC: .4byte 0x00000fff
_0800F500:
	ldrh r2, [r5]
	ldr r1, _0800F52C
	adds r0, r1, 0
	ands r0, r2
	strh r0, [r5]
	movs r2, 0x80
	lsls r2, 7
	ldrh r0, [r5, 0x2]
	ands r1, r0
	orrs r1, r2
	adds r2, r4, 0
	adds r2, 0x8
	ldr r0, _0800F530
	ands r2, r0
	movs r0, 0xFE
	lsls r0, 8
	ands r1, r0
	orrs r1, r2
	strh r1, [r5, 0x2]
	ldr r1, _0800F534
	ands r1, r6
	b _0800F59A
	.align 2, 0
_0800F52C: .4byte 0x00003fff
_0800F530: .4byte 0x000001ff
_0800F534: .4byte 0x00000fff
_0800F538:
	movs r3, 0x80
	lsls r3, 7
	ldrh r2, [r5]
	ldr r1, _0800F568
	adds r0, r1, 0
	ands r0, r2
	orrs r0, r3
	strh r0, [r5]
	movs r2, 0x80
	lsls r2, 8
	ldrh r0, [r5, 0x2]
	ands r1, r0
	orrs r1, r2
	ldr r0, _0800F56C
	ands r4, r0
	movs r0, 0xFE
	lsls r0, 8
	ands r1, r0
	orrs r1, r4
	strh r1, [r5, 0x2]
	ldr r1, _0800F570
	ands r1, r6
	b _0800F59A
	.align 2, 0
_0800F568: .4byte 0x00003fff
_0800F56C: .4byte 0x000001ff
_0800F570: .4byte 0x00000fff
_0800F574:
	ldrh r2, [r5]
	ldr r1, _0800F5F0
	adds r0, r1, 0
	ands r0, r2
	strh r0, [r5]
	movs r2, 0x80
	lsls r2, 8
	ldrh r0, [r5, 0x2]
	ands r1, r0
	orrs r1, r2
	ldr r0, _0800F5F4
	ands r4, r0
	movs r0, 0xFE
	lsls r0, 8
	ands r1, r0
	orrs r1, r4
	strh r1, [r5, 0x2]
	ldr r1, _0800F5F8
	ands r1, r3
_0800F59A:
	lsls r1, 4
	ldrh r2, [r5, 0x6]
	movs r0, 0xF
	ands r0, r2
	orrs r0, r1
	strh r0, [r5, 0x6]
_0800F5A6:
	ldr r0, _0800F5FC
	ands r7, r0
	ldrh r1, [r5, 0x4]
	movs r0, 0xFC
	lsls r0, 8
	ands r0, r1
	orrs r0, r7
	movs r1, 0xF
	ldr r3, [sp, 0x4]
	ands r1, r3
	lsls r1, 12
	ldr r2, _0800F5F8
	ands r0, r2
	orrs r0, r1
	strh r0, [r5, 0x4]
	mov r4, r12
	movs r6, 0x2
	ldrsh r1, [r4, r6]
	mov r2, r8
	movs r3, 0x2
	ldrsh r0, [r2, r3]
	subs r1, r0
	lsrs r0, r1, 31
	adds r1, r0
	asrs r1, 1
	adds r1, 0x1
	adds r0, r5, 0
	movs r2, 0
	movs r3, 0
	bl AddSprite
_0800F5E4:
	add sp, 0x8
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_0800F5F0: .4byte 0x00003fff
_0800F5F4: .4byte 0x000001ff
_0800F5F8: .4byte 0x00000fff
_0800F5FC: .4byte 0x000003ff
	thumb_func_end sub_800F364

	thumb_func_start sub_800F600
sub_800F600:
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	lsls r1, 24
	lsrs r1, 24
	mov r9, r1
	lsls r1, r0, 1
	adds r1, r0
	lsls r1, 3
	ldr r0, _0800F660
	adds r1, r0
	ldr r7, [r1, 0x14]
	ldr r3, [r1, 0x10]
	ldr r2, [r1]
	ldr r0, [r1, 0x4]
	muls r0, r2
	lsls r4, r0, 5
	mov r8, r4
	ldr r0, [r1, 0x8]
	ldr r1, _0800F664
	adds r0, r1
	lsls r5, r0, 5
	adds r6, r5, 0
	ldr r0, _0800F668
	ldr r0, [r0]
	ldr r0, [r0]
	cmp r0, 0
	bge _0800F63C
	adds r0, 0x3
_0800F63C:
	asrs r0, 2
	adds r1, r3, 0
	bl __modsi3
	muls r0, r4
	ldr r1, _0800F66C
	adds r0, r1
	adds r1, r7, r0
	mov r2, r9
	cmp r2, 0
	beq _0800F674
	ldr r2, _0800F670
	adds r0, r5, r2
	adds r2, r4, 0
	bl sub_80098BC
	b _0800F67E
	.align 2, 0
_0800F660: .4byte gUnknown_80CE79C
_0800F664: .4byte 0x0000032b
_0800F668: .4byte gUnknown_203B0D8
_0800F66C: .4byte gUnknown_80CE934
_0800F670: .4byte 0x06010000
_0800F674:
	ldr r2, _0800F68C
	adds r0, r6, r2
	mov r2, r8
	bl CpuCopy
_0800F67E:
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_0800F68C: .4byte 0x06010000
	thumb_func_end sub_800F600

	thumb_func_start sub_800F690
sub_800F690:
	push {r4,r5,lr}
	ldr r5, _0800F738
	ldr r0, [r5]
	cmp r0, 0
	bne _0800F6AC
	ldr r4, _0800F73C
	adds r0, r4, 0
	movs r1, 0xC
	bl MemoryAlloc
	str r0, [r5]
	adds r1, r4, 0
	bl MemoryClear8
_0800F6AC:
	ldr r1, [r5]
	movs r0, 0
	str r0, [r1]
	movs r0, 0x1
	movs r1, 0
	bl sub_800F600
	movs r0, 0x2
	movs r1, 0
	bl sub_800F600
	movs r0, 0x3
	movs r1, 0
	bl sub_800F600
	movs r0, 0x4
	movs r1, 0
	bl sub_800F600
	movs r0, 0x5
	movs r1, 0
	bl sub_800F600
	movs r0, 0x6
	movs r1, 0
	bl sub_800F600
	movs r0, 0x7
	movs r1, 0
	bl sub_800F600
	movs r0, 0x8
	movs r1, 0
	bl sub_800F600
	movs r0, 0x9
	movs r1, 0
	bl sub_800F600
	movs r0, 0xA
	movs r1, 0
	bl sub_800F600
	movs r0, 0xB
	movs r1, 0
	bl sub_800F600
	movs r0, 0xC
	movs r1, 0
	bl sub_800F600
	movs r0, 0xD
	movs r1, 0
	bl sub_800F600
	movs r0, 0xE
	movs r1, 0
	bl sub_800F600
	movs r0, 0xF
	movs r1, 0
	bl sub_800F600
	movs r0, 0x10
	movs r1, 0
	bl sub_800F600
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_0800F738: .4byte gUnknown_203B0D8
_0800F73C: .4byte 0x00000584
	thumb_func_end sub_800F690

	thumb_func_start sub_800F740
sub_800F740:
	push {r4,lr}
	ldr r4, _0800F758
	ldr r0, [r4]
	cmp r0, 0
	beq _0800F752
	bl MemoryFree
	movs r0, 0
	str r0, [r4]
_0800F752:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0800F758: .4byte gUnknown_203B0D8
	thumb_func_end sub_800F740

	thumb_func_start sub_800F75C
sub_800F75C:
	push {r4-r7,lr}
	adds r4, r0, 0
	adds r7, r2, 0
	lsls r1, 16
	asrs r5, r1, 16
	lsls r3, 24
	lsrs r6, r3, 24
	ldr r0, _0800F790
	ldr r0, [r0]
	cmp r0, 0
	beq _0800F788
	adds r0, r4, 0
	bl sub_800F210
	cmp r0, 0
	beq _0800F788
	movs r1, 0
	strh r5, [r0, 0x8]
	str r7, [r0, 0xC]
	strb r6, [r0, 0x10]
	adds r0, 0x38
	strb r1, [r0]
_0800F788:
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_0800F790: .4byte gUnknown_203B0D8
	thumb_func_end sub_800F75C

	thumb_func_start sub_800F794
sub_800F794:
	push {r4-r6,lr}
	adds r1, r0, 0
	adds r4, r2, 0
	adds r5, r3, 0
	ldr r6, [sp, 0x10]
	ldr r0, _0800F7CC
	ldr r0, [r0]
	cmp r0, 0
	beq _0800F7C6
	adds r0, r1, 0
	bl sub_800F210
	adds r2, r0, 0
	cmp r2, 0
	beq _0800F7C6
	adds r1, r2, 0
	adds r1, 0x38
	movs r0, 0x1
	strb r0, [r1]
	strh r4, [r2, 0x3C]
	strh r5, [r2, 0x3E]
	ldr r0, [r6]
	str r0, [r2, 0x20]
	ldr r0, [r6, 0xC]
	str r0, [r2, 0x24]
_0800F7C6:
	pop {r4-r6}
	pop {r0}
	bx r0
	.align 2, 0
_0800F7CC: .4byte gUnknown_203B0D8
	thumb_func_end sub_800F794

	thumb_func_start sub_800F7D0
sub_800F7D0:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	mov r8, r0
	ldr r0, _0800F800
	ldr r0, [r0]
	cmp r0, 0
	beq _0800F8C0
	ldr r1, [r0]
	adds r0, r1, 0
	cmp r1, 0
	bge _0800F7EA
	adds r0, r1, 0x3
_0800F7EA:
	asrs r0, 2
	lsls r0, 2
	subs r0, r1, r0
	cmp r0, 0x1
	beq _0800F82A
	cmp r0, 0x1
	bgt _0800F804
	cmp r0, 0
	beq _0800F80E
	b _0800F888
	.align 2, 0
_0800F800: .4byte gUnknown_203B0D8
_0800F804:
	cmp r0, 0x2
	beq _0800F846
	cmp r0, 0x3
	beq _0800F868
	b _0800F888
_0800F80E:
	movs r0, 0x1
	movs r1, 0x1
	bl sub_800F600
	movs r0, 0x2
	movs r1, 0x1
	bl sub_800F600
	movs r0, 0x3
	movs r1, 0x1
	bl sub_800F600
	movs r0, 0x4
	b _0800F860
_0800F82A:
	movs r0, 0x5
	movs r1, 0x1
	bl sub_800F600
	movs r0, 0x6
	movs r1, 0x1
	bl sub_800F600
	movs r0, 0x7
	movs r1, 0x1
	bl sub_800F600
	movs r0, 0x8
	b _0800F860
_0800F846:
	movs r0, 0x9
	movs r1, 0x1
	bl sub_800F600
	movs r0, 0xA
	movs r1, 0x1
	bl sub_800F600
	movs r0, 0xB
	movs r1, 0x1
	bl sub_800F600
	movs r0, 0xC
_0800F860:
	movs r1, 0x1
	bl sub_800F600
	b _0800F888
_0800F868:
	movs r0, 0xD
	movs r1, 0x1
	bl sub_800F600
	movs r0, 0xE
	movs r1, 0x1
	bl sub_800F600
	movs r0, 0xF
	movs r1, 0x1
	bl sub_800F600
	movs r0, 0x10
	movs r1, 0x1
	bl sub_800F600
_0800F888:
	movs r5, 0
	movs r6, 0x4
_0800F88C:
	ldr r7, _0800F8CC
	ldr r4, [r7]
	lsls r0, r5, 6
	adds r0, r4, r0
	ldrb r0, [r0, 0x4]
	cmp r0, 0
	beq _0800F8B0
	adds r4, r6
	adds r0, r4, 0
	movs r1, 0
	mov r2, r8
	bl sub_800F2EC
	adds r0, r4, 0
	movs r1, 0x1
	mov r2, r8
	bl sub_800F2EC
_0800F8B0:
	adds r6, 0x40
	adds r5, 0x1
	cmp r5, 0x15
	ble _0800F88C
	ldr r1, [r7]
	ldr r0, [r1]
	adds r0, 0x1
	str r0, [r1]
_0800F8C0:
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_0800F8CC: .4byte gUnknown_203B0D8
	thumb_func_end sub_800F7D0

	thumb_func_start sub_800F8D0
sub_800F8D0:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	adds r5, r0, 0
	adds r7, r2, 0
	mov r8, r3
	lsls r1, 16
	asrs r6, r1, 16
	ldr r0, _0800F92C
	ldr r0, [r0]
	cmp r0, 0
	beq _0800F920
	adds r0, r5, 0
	bl sub_800F210
	adds r4, r0, 0
	cmp r4, 0
	bne _0800F920
	bl sub_800F248
	adds r1, r0, 0
	cmp r1, 0
	beq _0800F920
	movs r0, 0x1
	strb r0, [r1]
	str r5, [r1, 0x4]
	strh r6, [r1, 0x8]
	str r4, [r1, 0xC]
	ldr r0, [r7]
	str r0, [r1, 0x14]
	mov r0, r8
	strb r0, [r1, 0x11]
	ldr r0, _0800F930
	ldr r0, [r0]
	str r0, [r1, 0x1C]
	str r0, [r1, 0x18]
	str r4, [r1, 0x28]
	str r4, [r1, 0x2C]
	str r4, [r1, 0x30]
	str r4, [r1, 0x34]
_0800F920:
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_0800F92C: .4byte gUnknown_203B0D8
_0800F930: .4byte gUnknown_80D3564
	thumb_func_end sub_800F8D0

	thumb_func_start sub_800F934
sub_800F934:
	push {lr}
	adds r1, r0, 0
	ldr r0, _0800F954
	ldr r0, [r0]
	cmp r0, 0
	beq _0800F950
	adds r0, r1, 0
	bl sub_800F210
	cmp r0, 0
	beq _0800F950
	movs r1, 0x40
	bl MemoryClear8
_0800F950:
	pop {r0}
	bx r0
	.align 2, 0
_0800F954: .4byte gUnknown_203B0D8
	thumb_func_end sub_800F934

	thumb_func_start sub_800F958
sub_800F958:
	push {r4-r7,lr}
	adds r4, r0, 0
	adds r6, r1, 0
	adds r5, r2, 0
	adds r7, r3, 0
	ldr r0, _0800F98C
	ldr r0, [r0]
	cmp r0, 0
	beq _0800F984
	adds r0, r4, 0
	bl sub_800F210
	adds r3, r0, 0
	cmp r3, 0
	beq _0800F984
	ldr r0, [r6]
	str r0, [r3, 0x14]
	strb r7, [r3, 0x11]
	ldr r0, [r5]
	str r0, [r3, 0x18]
	ldr r0, [r5, 0xC]
	str r0, [r3, 0x1C]
_0800F984:
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_0800F98C: .4byte gUnknown_203B0D8
	thumb_func_end sub_800F958

	thumb_func_start sub_800F990
sub_800F990:
	push {r4-r7,lr}
	sub sp, 0x8
	adds r6, r0, 0
	ldr r4, _0800FA20
	ldr r0, [r6, 0x8]
	str r0, [r4]
	ldr r1, _0800FA24
	ldr r2, _0800FA28
	adds r0, r2, 0
	strh r0, [r1]
	movs r0, 0
	movs r1, 0x14
	bl sub_80095CC
	movs r0, 0x2
	bl xxx_update_some_bg_tiles
	ldr r1, [r4]
	ldr r0, _0800FA2C
	adds r2, r1, r0
	ldr r0, _0800FA30
	str r0, [r2]
	ldrb r0, [r6, 0x5]
	ldr r2, _0800FA34
	adds r1, r2
	movs r5, 0
	strb r0, [r1]
	bl sub_8010DA4
	ldr r0, [r4]
	ldr r2, _0800FA38
	adds r1, r0, r2
	movs r2, 0x1
	negs r2, r2
	str r2, [r1]
	ldr r1, _0800FA3C
	adds r0, r1
	str r2, [r0]
	ldrb r0, [r6, 0x4]
	bl sub_800FC5C
	ldr r0, [r4]
	ldr r2, _0800FA40
	adds r1, r0, r2
	adds r2, 0x4
	adds r0, r2
	ldr r0, [r0]
	str r0, [r1]
	ldr r1, _0800FA44
	movs r0, 0xFF
	strb r0, [r1]
	ldr r0, _0800FA48
	strb r5, [r0]
	bl sub_8011760
	add r7, sp, 0x4
_0800FA00:
	movs r5, 0
	str r5, [sp]
	str r5, [sp, 0x4]
	mov r0, sp
	adds r1, r7, 0
	bl sub_800FAA8
	cmp r0, 0x1
	bne _0800FA4C
	ldr r0, [sp]
	ldr r1, [sp, 0x4]
	movs r2, 0x32
	bl sub_80100C0
	b _0800FA00
	.align 2, 0
_0800FA20: .4byte gUnknown_203B0E4
_0800FA24: .4byte gUnknown_2026E4E
_0800FA28: .4byte 0x00001010
_0800FA2C: .4byte 0x00004014
_0800FA30: .4byte gUnknown_80D3570
_0800FA34: .4byte 0x00004a2c
_0800FA38: .4byte 0x00004a28
_0800FA3C: .4byte 0x00004a1c
_0800FA40: .4byte 0x00004a20
_0800FA44: .4byte gUnknown_202DE18
_0800FA48: .4byte gUnknown_202DE19
_0800FA4C:
	cmp r0, 0x2
	bne _0800FA6C
	bl sub_800FB6C
	lsls r0, 24
	cmp r0, 0
	beq _0800FA00
	ldr r0, [r4]
	ldr r1, _0800FA68
	adds r0, r1
	ldrb r0, [r0]
	strb r0, [r6, 0xC]
	b _0800FA92
	.align 2, 0
_0800FA68: .4byte 0x00004df4
_0800FA6C:
	cmp r0, 0x3
	bne _0800FA00
	ldr r0, [r4]
	ldr r2, _0800FA8C
	adds r1, r0, r2
	adds r2, 0x8
	adds r0, r2
	ldr r1, [r1]
	ldr r0, [r0]
	cmp r1, r0
	beq _0800FA90
	movs r1, 0
	movs r2, 0xA
	bl sub_80100C0
	b _0800FA00
	.align 2, 0
_0800FA8C: .4byte 0x00004a18
_0800FA90:
	strb r5, [r6, 0xC]
_0800FA92:
	bl sub_800FC28
	bl sub_8010EF0
	bl nullsub_16
	add sp, 0x8
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_800F990

	thumb_func_start sub_800FAA8
sub_800FAA8:
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	mov r8, r0
	mov r9, r1
	movs r5, 0
	bl sub_8011300
	bl sub_8011398
_0800FABE:
	bl sub_801169C
	bl sub_8010014
	lsls r0, 24
	lsrs r3, r0, 24
	cmp r3, 0xFF
	beq _0800FB1C
	ldr r6, _0800FB50
	ldr r2, [r6]
	ldr r1, _0800FB54
	adds r0, r2, r1
	ldr r4, [r0]
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 4
	adds r0, r2
	lsls r1, r3, 1
	ldr r7, _0800FB58
	adds r0, r7
	adds r1, r0, r1
	movs r7, 0
	ldrsh r0, [r1, r7]
	cmp r0, 0
	blt _0800FB1C
	adds r1, r0, 0
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 4
	ldr r7, _0800FB5C
	adds r0, r7
	adds r0, r2, r0
	ldrb r0, [r0]
	cmp r0, 0
	beq _0800FB1C
	movs r5, 0x1
	mov r0, r8
	str r1, [r0]
	mov r1, r9
	str r3, [r1]
	ldr r1, [r6]
	ldr r2, _0800FB60
	adds r0, r1, r2
	str r3, [r0]
	ldr r7, _0800FB64
	adds r1, r7
	str r4, [r1]
_0800FB1C:
	ldr r4, _0800FB68
	ldrh r1, [r4, 0x2]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _0800FB2E
	bl sub_80117D0
	movs r5, 0x2
_0800FB2E:
	ldrh r1, [r4, 0x2]
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	beq _0800FB3E
	bl sub_80117E4
	movs r5, 0x3
_0800FB3E:
	cmp r5, 0
	beq _0800FABE
	adds r0, r5, 0
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r1}
	bx r1
	.align 2, 0
_0800FB50: .4byte gUnknown_203B0E4
_0800FB54: .4byte 0x00004a18
_0800FB58: .4byte 0x0000401a
_0800FB5C: .4byte 0x00004018
_0800FB60: .4byte 0x00004a28
_0800FB64: .4byte 0x00004a1c
_0800FB68: .4byte gUnknown_20255F0
	thumb_func_end sub_800FAA8

	thumb_func_start sub_800FB6C
sub_800FB6C:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	movs r0, 0
	mov r8, r0
	bl sub_8011494
	ldr r7, _0800FBE8
	ldr r6, _0800FBEC
_0800FB7E:
	ldr r5, [r7]
	ldr r1, _0800FBF0
	adds r4, r5, r1
	adds r0, r4, 0
	bl AddMenuCursorSprite
	bl sub_801169C
	ldrh r1, [r6, 0x4]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	beq _0800FBA2
	adds r0, r4, 0
	bl MoveMenuCursorDown
	bl sub_80117F8
_0800FBA2:
	ldrh r1, [r6, 0x4]
	movs r0, 0x40
	ands r0, r1
	cmp r0, 0
	beq _0800FBB6
	adds r0, r4, 0
	bl MoveMenuCursorUp
	bl sub_80117F8
_0800FBB6:
	ldrh r1, [r6, 0x2]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	bne _0800FBCA
	ldr r2, _0800FBF4
	adds r0, r5, r2
	ldrb r0, [r0]
	cmp r0, 0
	beq _0800FC00
_0800FBCA:
	bl sub_80117D0
	ldr r1, [r7]
	movs r3, 0x18
	ldrsh r2, [r4, r3]
	ldr r3, _0800FBF8
	adds r0, r1, r3
	adds r0, r2
	ldrb r0, [r0]
	ldr r2, _0800FBFC
	adds r1, r2
	strb r0, [r1]
	movs r3, 0x1
	mov r8, r3
	b _0800FC16
	.align 2, 0
_0800FBE8: .4byte gUnknown_203B0E4
_0800FBEC: .4byte gUnknown_20255F0
_0800FBF0: .4byte 0x00004dfc
_0800FBF4: .4byte 0x00004e25
_0800FBF8: .4byte 0x00004dec
_0800FBFC: .4byte 0x00004df4
_0800FC00:
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	bne _0800FC12
	ldr r1, _0800FC24
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, 0
	beq _0800FB7E
_0800FC12:
	bl sub_80117E4
_0800FC16:
	mov r0, r8
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r1}
	bx r1
	.align 2, 0
_0800FC24: .4byte 0x00004e26
	thumb_func_end sub_800FB6C

	thumb_func_start sub_800FC28
sub_800FC28:
	push {r4,r5,lr}
	bl sub_8011168
	bl sub_80117AC
	ldr r5, _0800FC54
	movs r4, 0x3B
_0800FC36:
	ldr r1, [r5]
	ldr r0, _0800FC58
	adds r1, r0
	ldr r0, [r1]
	subs r0, 0x2
	str r0, [r1]
	bl sub_801169C
	subs r4, 0x1
	cmp r4, 0
	bge _0800FC36
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_0800FC54: .4byte gUnknown_203B0E4
_0800FC58: .4byte 0x00004dcc
	thumb_func_end sub_800FC28

	thumb_func_start sub_800FC5C
sub_800FC5C:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x40
	lsls r0, 24
	lsrs r0, 24
	str r0, [sp, 0x14]
	movs r0, 0
	str r0, [sp, 0x18]
	mov r8, r0
	ldr r1, _0800FD1C
	mov r9, r1
	ldr r2, _0800FD20
	str r2, [sp, 0x38]
_0800FC7C:
	movs r7, 0
	movs r3, 0
	mov r10, r3
	mov r4, r9
	ldr r0, [r4]
	ldr r1, [sp, 0x38]
	adds r6, r0, r1
	ldr r2, _0800FD24
	adds r0, r2
	mov r3, r8
	lsls r1, r3, 5
	ldr r0, [r0]
	adds r2, r0, r1
	adds r1, r6, 0x2
	movs r5, 0x7
_0800FC9A:
	ldrh r0, [r1]
	ldr r4, _0800FD28
	orrs r0, r4
	strh r0, [r1]
	adds r1, 0x2
	subs r5, 0x1
	cmp r5, 0
	bge _0800FC9A
	movs r5, 0
	adds r1, r2, 0
	adds r1, 0x8
_0800FCB0:
	adds r4, r1, r5
	ldrb r0, [r4]
	str r1, [sp, 0x3C]
	bl sub_800FFE8
	lsls r0, 24
	ldr r1, [sp, 0x3C]
	cmp r0, 0
	beq _0800FCE4
	ldrb r0, [r4]
	ldr r7, [sp, 0x14]
	cmp r0, r7
	bne _0800FCCE
	mov r2, r8
	str r2, [sp, 0x18]
_0800FCCE:
	cmp r0, 0
	bne _0800FCE2
	mov r3, r9
	ldr r0, [r3]
	ldr r4, _0800FD2C
	adds r0, r4
	mov r7, r8
	str r7, [r0]
	movs r0, 0x1
	mov r10, r0
_0800FCE2:
	movs r7, 0x1
_0800FCE4:
	adds r5, 0x1
	cmp r5, 0x7
	ble _0800FCB0
	cmp r7, 0
	beq _0800FD30
	movs r5, 0
	movs r4, 0x1
	strb r4, [r6]
	adds r3, r6, 0
	adds r3, 0x14
	mov r1, r9
	ldr r0, [r1]
	ldr r1, [r0, 0x8]
	movs r2, 0x1
	mov r7, r10
	cmp r7, 0
	beq _0800FD08
	movs r2, 0xC
_0800FD08:
	movs r0, 0x40
	str r0, [sp]
	str r5, [sp, 0x4]
	str r4, [sp, 0x8]
	adds r0, r3, 0
	movs r3, 0
	bl sub_80053AC
	b _0800FD32
	.align 2, 0
_0800FD1C: .4byte gUnknown_203B0E4
_0800FD20: .4byte 0x00004018
_0800FD24: .4byte 0x00004014
_0800FD28: .4byte 0x0000ffff
_0800FD2C: .4byte 0x00004a24
_0800FD30:
	strb r7, [r6]
_0800FD32:
	ldr r0, [sp, 0x38]
	adds r0, 0x50
	str r0, [sp, 0x38]
	movs r1, 0x1
	add r8, r1
	mov r2, r8
	cmp r2, 0x1F
	ble _0800FC7C
	movs r3, 0
	mov r8, r3
	ldr r4, [sp, 0x18]
	lsls r4, 5
	str r4, [sp, 0x34]
_0800FD4C:
	mov r7, r8
	lsls r0, r7, 2
	add r0, r8
	lsls r0, 4
	ldr r1, _0800FEDC
	adds r0, r1
	ldr r2, _0800FEE0
	ldr r1, [r2]
	adds r3, r1, r0
	ldr r4, _0800FEE4
	adds r1, r4
	lsls r2, r7, 5
	ldr r0, [r1]
	adds r0, r2
	str r0, [sp, 0x1C]
	ldrb r0, [r3]
	adds r7, 0x1
	str r7, [sp, 0x28]
	cmp r0, 0
	bne _0800FD76
	b _0800FF56
_0800FD76:
	movs r5, 0
	adds r3, 0x2
	mov r10, r3
	ldr r4, [sp, 0x1C]
	adds r4, 0x10
	ldr r6, _0800FEE0
_0800FD82:
	lsls r0, r5, 1
	mov r1, r10
	adds r2, r1, r0
	ldr r1, _0800FEE8
	strh r1, [r2]
	adds r1, r4, r0
	ldrh r3, [r1]
	movs r7, 0
	ldrsh r0, [r1, r7]
	cmp r0, 0
	blt _0800FDB0
	adds r1, r0, 0
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 4
	ldr r1, _0800FEDC
	adds r0, r1
	ldr r1, [r6]
	adds r1, r0
	ldrb r0, [r1]
	cmp r0, 0
	beq _0800FDB0
	strh r3, [r2]
_0800FDB0:
	adds r5, 0x1
	cmp r5, 0x7
	ble _0800FD82
	ldr r3, _0800FEE0
	ldr r2, [r3]
	ldr r4, _0800FEEC
	adds r0, r2, r4
	ldr r1, [r0]
	ldr r7, _0800FEF0
	adds r0, r2, r7
	ldr r3, [r0]
	cmp r1, 0
	blt _0800FDEC
	cmp r3, 0
	blt _0800FDEC
	lsls r0, r3, 2
	adds r0, r3
	lsls r0, 4
	ldr r4, _0800FEDC
	adds r0, r4
	adds r0, r2, r0
	ldrb r0, [r0]
	cmp r0, 0
	beq _0800FDEC
	adds r1, 0x4
	movs r0, 0x7
	ands r1, r0
	lsls r0, r1, 1
	add r0, r10
	strh r3, [r0]
_0800FDEC:
	movs r5, 0
_0800FDEE:
	movs r7, 0x1
	negs r7, r7
	str r7, [sp, 0x20]
	ldr r0, _0800FEF4
	str r0, [sp, 0x24]
	lsls r0, r5, 1
	mov r2, r10
	adds r1, r2, r0
	movs r3, 0
	ldrsh r1, [r1, r3]
	str r0, [sp, 0x30]
	adds r4, r5, 0x1
	str r4, [sp, 0x2C]
	cmp r1, 0
	blt _0800FE0E
	b _0800FF4E
_0800FE0E:
	movs r6, 0
_0800FE10:
	lsls r0, r6, 2
	adds r0, r6
	lsls r0, 4
	ldr r7, _0800FEDC
	adds r0, r7
	ldr r2, _0800FEE0
	ldr r1, [r2]
	adds r3, r1, r0
	ldr r4, _0800FEE4
	adds r1, r4
	lsls r2, r6, 5
	ldr r0, [r1]
	adds r2, r0, r2
	adds r7, r6, 0x1
	mov r9, r7
	cmp r6, r8
	bne _0800FE34
	b _0800FF3A
_0800FE34:
	ldrb r0, [r3]
	cmp r0, 0
	bne _0800FE3C
	b _0800FF3A
_0800FE3C:
	movs r1, 0x4
	ldrsh r0, [r2, r1]
	ldr r3, [sp, 0x1C]
	movs r4, 0x4
	ldrsh r1, [r3, r4]
	subs r0, r1
	lsls r0, 8
	str r0, [sp, 0xC]
	movs r7, 0x6
	ldrsh r0, [r2, r7]
	movs r2, 0x6
	ldrsh r1, [r3, r2]
	subs r0, r1
	lsls r0, 8
	str r0, [sp, 0x10]
	add r0, sp, 0xC
	bl sub_800A0B0
	adds r2, r0, 0
	ldr r0, [sp, 0xC]
	cmp r0, 0
	bge _0800FE6A
	adds r0, 0x3
_0800FE6A:
	asrs r1, r0, 2
	str r1, [sp, 0xC]
	ldr r0, [sp, 0x10]
	cmp r0, 0
	bge _0800FE76
	adds r0, 0x3
_0800FE76:
	asrs r0, 2
	str r0, [sp, 0x10]
	cmp r1, 0
	bge _0800FE80
	adds r1, 0xFF
_0800FE80:
	asrs r1, 8
	str r1, [sp, 0xC]
	cmp r0, 0
	bge _0800FE8A
	adds r0, 0xFF
_0800FE8A:
	asrs r0, 8
	str r0, [sp, 0x10]
	cmp r1, 0
	bne _0800FE96
	movs r0, 0x1
	str r0, [sp, 0xC]
_0800FE96:
	ldr r0, [sp, 0x10]
	cmp r0, 0
	bne _0800FEA0
	movs r0, 0x1
	str r0, [sp, 0x10]
_0800FEA0:
	movs r7, 0
	cmp r5, 0x2
	bne _0800FF04
	ldr r1, _0800FEF8
	ldr r4, _0800FEFC
	movs r3, 0x8
	cmp r2, r1
	ble _0800FEB8
	ldr r0, _0800FF00
_0800FEB2:
	adds r2, r0
	cmp r2, r1
	bgt _0800FEB2
_0800FEB8:
	cmp r2, 0
	bge _0800FEC6
	movs r0, 0x80
	lsls r0, 5
_0800FEC0:
	adds r2, r0
	cmp r2, 0
	blt _0800FEC0
_0800FEC6:
	adds r1, r3, r4
	movs r3, 0
	ldrsh r0, [r1, r3]
	cmp r0, r2
	blt _0800FF20
	movs r4, 0x2
	ldrsh r0, [r1, r4]
	cmp r0, r2
	ble _0800FF1C
	b _0800FF20
	.align 2, 0
_0800FEDC: .4byte 0x00004018
_0800FEE0: .4byte gUnknown_203B0E4
_0800FEE4: .4byte 0x00004014
_0800FEE8: .4byte 0x0000ffff
_0800FEEC: .4byte 0x00004a28
_0800FEF0: .4byte 0x00004a1c
_0800FEF4: .4byte 0x000f423f
_0800FEF8: .4byte 0x00000fff
_0800FEFC: .4byte gUnknown_80D3EBC
_0800FF00: .4byte 0xfffff000
_0800FF04:
	ldr r0, _0800FFC8
	lsls r1, r5, 2
	adds r1, r0
	movs r3, 0
	ldrsh r0, [r1, r3]
	cmp r0, r2
	bgt _0800FF1C
	movs r4, 0x2
	ldrsh r0, [r1, r4]
	cmp r0, r2
	ble _0800FF1C
	movs r7, 0x1
_0800FF1C:
	cmp r7, 0
	beq _0800FF3A
_0800FF20:
	ldr r0, [sp, 0xC]
	adds r1, r0, 0
	muls r1, r0
	ldr r0, [sp, 0x10]
	adds r7, r0, 0
	muls r7, r0
	adds r0, r7, 0
	adds r1, r0
	ldr r0, [sp, 0x24]
	cmp r0, r1
	ble _0800FF3A
	str r1, [sp, 0x24]
	str r6, [sp, 0x20]
_0800FF3A:
	mov r6, r9
	cmp r6, 0x1F
	bgt _0800FF42
	b _0800FE10
_0800FF42:
	ldr r1, [sp, 0x20]
	cmp r1, 0
	blt _0800FF4E
	ldr r0, [sp, 0x30]
	add r0, r10
	strh r1, [r0]
_0800FF4E:
	ldr r5, [sp, 0x2C]
	cmp r5, 0x7
	bgt _0800FF56
	b _0800FDEE
_0800FF56:
	ldr r3, [sp, 0x28]
	mov r8, r3
	cmp r3, 0x1F
	bgt _0800FF60
	b _0800FD4C
_0800FF60:
	ldr r4, _0800FFCC
	ldr r1, [r4]
	ldr r7, _0800FFD0
	adds r0, r1, r7
	ldr r1, [r1, 0xC]
	movs r2, 0
	str r2, [sp]
	str r2, [sp, 0x4]
	movs r2, 0x1
	str r2, [sp, 0x8]
	movs r2, 0
	movs r3, 0
	bl sub_80053AC
	ldr r2, [r4]
	ldr r1, _0800FFD4
	adds r0, r2, r1
	ldr r3, [sp, 0x18]
	str r3, [r0]
	ldr r4, _0800FFD8
	adds r1, r2, r4
	ldr r7, _0800FFDC
	adds r0, r2, r7
	ldr r0, [r0]
	ldr r3, [sp, 0x34]
	adds r0, r3, r0
	ldr r0, [r0, 0x4]
	str r0, [r1]
	ldrh r0, [r1]
	subs r0, 0x78
	subs r4, 0x4
	adds r1, r2, r4
	strh r0, [r1]
	ldr r7, _0800FFE0
	adds r0, r2, r7
	ldrh r0, [r0]
	subs r0, 0x50
	ldr r1, _0800FFE4
	adds r2, r1
	strh r0, [r2]
	bl sub_8011240
	bl sub_80110B0
	add sp, 0x40
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_0800FFC8: .4byte gUnknown_80D3EBC
_0800FFCC: .4byte gUnknown_203B0E4
_0800FFD0: .4byte 0x00004c10
_0800FFD4: .4byte 0x00004a18
_0800FFD8: .4byte 0x00004dd8
_0800FFDC: .4byte 0x00004014
_0800FFE0: .4byte 0x00004dda
_0800FFE4: .4byte 0x00004dd6
	thumb_func_end sub_800FC5C

	thumb_func_start sub_800FFE8
sub_800FFE8:
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	adds r1, r0, 0
	cmp r0, 0x39
	bhi _08010004
	cmp r0, 0
	beq _0801000C
	ldr r0, _08010008
	ldr r0, [r0]
	adds r0, r1
	ldrb r0, [r0]
	cmp r0, 0
	bne _0801000C
_08010004:
	movs r0, 0
	b _0801000E
	.align 2, 0
_08010008: .4byte gUnknown_203B468
_0801000C:
	movs r0, 0x1
_0801000E:
	pop {r1}
	bx r1
	thumb_func_end sub_800FFE8

	thumb_func_start sub_8010014
sub_8010014:
	push {r4,r5,lr}
	sub sp, 0x20
	ldr r1, _08010094
	mov r0, sp
	movs r2, 0x10
	bl memcpy
	add r4, sp, 0x10
	ldr r1, _08010098
	adds r0, r4, 0
	movs r2, 0x10
	bl memcpy
	movs r2, 0
	ldr r0, _0801009C
	ldrh r3, [r0]
	movs r0, 0x80
	lsls r0, 1
	ands r0, r3
	mov r5, sp
	cmp r0, 0
	beq _08010042
	adds r5, r4, 0
_08010042:
	adds r1, r3, 0
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	beq _0801004E
	movs r2, 0x1
_0801004E:
	movs r0, 0x10
	ands r0, r1
	cmp r0, 0
	beq _0801005A
	movs r0, 0x2
	orrs r2, r0
_0801005A:
	movs r0, 0x40
	ands r0, r1
	cmp r0, 0
	beq _08010066
	movs r0, 0x4
	orrs r2, r0
_08010066:
	movs r0, 0x20
	ands r0, r3
	cmp r0, 0
	beq _08010072
	movs r0, 0x8
	orrs r2, r0
_08010072:
	ldr r3, _080100A0
	adds r2, r5, r2
	ldrb r1, [r2]
	ldrb r0, [r3]
	cmp r0, r1
	bne _080100A8
	ldr r1, _080100A4
	ldrb r0, [r1]
	adds r0, 0x1
	strb r0, [r1]
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x2
	bls _080100B0
	ldrb r0, [r2]
	b _080100B2
	.align 2, 0
_08010094: .4byte gUnknown_80D3EDC
_08010098: .4byte gUnknown_80D3EEC
_0801009C: .4byte gUnknown_20255F0
_080100A0: .4byte gUnknown_202DE18
_080100A4: .4byte gUnknown_202DE19
_080100A8:
	strb r1, [r3]
	ldr r1, _080100BC
	movs r0, 0
	strb r0, [r1]
_080100B0:
	movs r0, 0xFF
_080100B2:
	add sp, 0x20
	pop {r4,r5}
	pop {r1}
	bx r1
	.align 2, 0
_080100BC: .4byte gUnknown_202DE19
	thumb_func_end sub_8010014

	thumb_func_start sub_80100C0
sub_80100C0:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x18
	str r0, [sp, 0xC]
	mov r8, r2
	ldr r4, _080101E0
	ldr r2, [r4]
	ldr r3, _080101E4
	adds r0, r2, r3
	ldr r2, [r2, 0xC]
	movs r3, 0x7
	ands r3, r1
	movs r1, 0
	str r1, [sp]
	str r1, [sp, 0x4]
	movs r1, 0x1
	str r1, [sp, 0x8]
	adds r1, r2, 0
	movs r2, 0
	bl sub_80053AC
	bl sub_8011168
	ldr r0, [r4]
	ldr r2, _080101E8
	adds r1, r0, r2
	ldr r1, [r1]
	ldr r3, _080101EC
	adds r0, r3
	ldr r2, [r0]
	lsls r1, 5
	adds r1, r2
	ldr r1, [r1, 0x4]
	mov r9, r1
	ldr r1, [sp, 0xC]
	lsls r0, r1, 5
	adds r0, r2
	ldr r0, [r0, 0x4]
	str r0, [sp, 0x10]
	bl sub_80117F8
	movs r7, 0
	cmp r7, r8
	bge _0801018A
	ldr r2, [sp, 0x10]
	lsls r1, r2, 16
	asrs r1, 16
	mov r3, r9
	lsls r0, r3, 16
	asrs r0, 16
	subs r1, r0
	str r1, [sp, 0x14]
	movs r0, 0
	mov r10, r0
_08010132:
	ldr r0, _080101E0
	ldr r6, [r0]
	lsls r5, r7, 8
	mov r0, r10
	mov r1, r8
	bl __divsi3
	cmp r0, 0
	bge _08010146
	adds r0, 0xFF
_08010146:
	asrs r0, 8
	add r0, r9
	ldr r2, _080101F0
	adds r1, r6, r2
	strh r0, [r1]
	ldr r3, [sp, 0x10]
	asrs r0, r3, 16
	mov r1, r9
	asrs r4, r1, 16
	subs r0, r4
	muls r0, r5
	mov r1, r8
	bl __divsi3
	cmp r0, 0
	bge _08010168
	adds r0, 0xFF
_08010168:
	asrs r0, 8
	adds r0, r4
	ldr r2, _080101F4
	adds r1, r6, r2
	strh r0, [r1]
	bl sub_8011240
	bl sub_80110B0
	bl sub_801169C
	ldr r3, [sp, 0x14]
	lsls r0, r3, 8
	add r10, r0
	adds r7, 0x1
	cmp r7, r8
	blt _08010132
_0801018A:
	ldr r4, _080101E0
	ldr r0, [r4]
	ldr r2, _080101E8
	adds r1, r0, r2
	ldr r3, [sp, 0xC]
	str r3, [r1]
	ldr r1, _080101F0
	adds r2, r0, r1
	ldr r3, _080101EC
	adds r0, r3
	ldr r1, [r0]
	ldr r3, [sp, 0xC]
	lsls r0, r3, 5
	adds r0, r1
	ldr r0, [r0, 0x4]
	str r0, [r2]
	bl sub_8011240
	bl sub_80110B0
	bl sub_801169C
	ldr r1, [r4]
	ldr r2, _080101E4
	adds r0, r1, r2
	ldr r1, [r1, 0xC]
	movs r2, 0
	str r2, [sp]
	str r2, [sp, 0x4]
	movs r2, 0x1
	str r2, [sp, 0x8]
	movs r2, 0
	movs r3, 0
	bl sub_80053AC
	add sp, 0x18
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_080101E0: .4byte gUnknown_203B0E4
_080101E4: .4byte 0x00004c10
_080101E8: .4byte 0x00004a18
_080101EC: .4byte 0x00004014
_080101F0: .4byte 0x00004dd8
_080101F4: .4byte 0x00004dda
	thumb_func_end sub_80100C0

	thumb_func_start sub_80101F8
sub_80101F8:
	push {lr}
	adds r3, r0, 0
	lsls r1, 24
	lsrs r1, 24
	cmp r1, 0
	bne _08010218
	ldr r0, _08010214
	adds r2, r3, 0
	adds r2, 0x50
	adds r1, r3, 0
	movs r3, 0
	bl xxx_format_string
	b _08010220
	.align 2, 0
_08010214: .4byte gUnknown_80D3EFC
_08010218:
	adds r0, r3, 0
	movs r2, 0
	bl sub_8092578
_08010220:
	pop {r0}
	bx r0
	thumb_func_end sub_80101F8

	thumb_func_start sub_8010224
sub_8010224:
	push {r4-r7,lr}
	lsls r0, 24
	lsrs r6, r0, 24
	movs r7, 0
	ldr r0, _08010248
	adds r4, r0, 0x4
	adds r5, r0, 0
	adds r5, 0x8
_08010234:
	movs r2, 0
	adds r3, r5, 0
_08010238:
	adds r0, r3, r2
	ldrb r0, [r0]
	cmp r0, r6
	bne _0801024C
	ldrh r0, [r4]
	strh r0, [r1]
	ldrh r0, [r4, 0x2]
	b _08010260
	.align 2, 0
_08010248: .4byte gUnknown_80D3570
_0801024C:
	adds r2, 0x1
	cmp r2, 0x7
	ble _08010238
	adds r4, 0x20
	adds r5, 0x20
	adds r7, 0x1
	cmp r7, 0x1F
	ble _08010234
	movs r0, 0
	strh r0, [r1]
_08010260:
	strh r0, [r1, 0x2]
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_8010224

	thumb_func_start sub_8010268
sub_8010268:
	push {r4-r6,lr}
	ldr r4, _080102D4
	add sp, r4
	adds r5, r0, 0
	ldr r1, _080102D8
	adds r0, 0xB0
	ldr r0, [r0]
	str r0, [r1]
	ldr r1, _080102DC
	ldr r2, _080102E0
	adds r0, r2, 0
	strh r0, [r1]
	movs r0, 0
	movs r1, 0x14
	bl sub_80095CC
	movs r0, 0x2
	bl xxx_update_some_bg_tiles
	bl sub_801059C
	adds r0, r5, 0x4
	bl sub_8010494
	bl sub_801178C
	movs r4, 0x3B
_0801029E:
	bl sub_8010960
	subs r4, 0x1
	cmp r4, 0
	bge _0801029E
	ldrb r0, [r5, 0x4]
	ldrb r1, [r5, 0x8]
	bl sub_8010344
	adds r0, r5, 0
	adds r0, 0x8
	bl sub_8010B74
	adds r6, r5, 0
	adds r6, 0x70
	movs r4, 0x3B
_080102BE:
	bl sub_8010960
	subs r4, 0x1
	cmp r4, 0
	bge _080102BE
	ldrb r0, [r5, 0x14]
	cmp r0, 0
	beq _080102E4
	movs r0, 0x20
	ldrsh r1, [r5, r0]
	b _080102E6
	.align 2, 0
_080102D4: .4byte 0xfffffc14
_080102D8: .4byte gUnknown_203B0E8
_080102DC: .4byte gUnknown_2026E4E
_080102E0: .4byte 0x00000a06
_080102E4:
	movs r1, 0
_080102E6:
	ldrb r0, [r5, 0x8]
	ldrb r3, [r6]
	movs r4, 0
	str r4, [sp]
	add r2, sp, 0x4
	bl sub_809034C
	cmp r0, 0
	beq _0801031C
	cmp r0, 0x1
	bne _0801030A
	add r0, sp, 0x4
	bl sub_8010C10
	adds r0, r5, 0
	adds r0, 0xB4
	strb r4, [r0]
	b _0801032C
_0801030A:
	cmp r0, 0x2
	bne _0801032C
	add r0, sp, 0x4
	bl sub_8010C58
	lsls r0, 24
	lsrs r1, r0, 24
	cmp r1, 0
	beq _08010326
_0801031C:
	adds r1, r5, 0
	adds r1, 0xB4
	movs r0, 0x1
	strb r0, [r1]
	b _0801032C
_08010326:
	adds r0, r5, 0
	adds r0, 0xB4
	strb r1, [r0]
_0801032C:
	bl sub_801091C
	bl sub_801073C
	bl nullsub_16
	movs r3, 0xFB
	lsls r3, 2
	add sp, r3
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end sub_8010268

	thumb_func_start sub_8010344
sub_8010344:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x1C
	lsls r0, 24
	lsls r1, 24
	ldr r2, _08010470
	lsrs r0, 22
	adds r0, r2
	lsrs r1, 22
	adds r1, r2
	ldr r2, [r1]
	str r2, [sp, 0x14]
	movs r3, 0
	ldrsh r5, [r1, r3]
	ldr r1, [r0]
	mov r9, r1
	movs r2, 0
	ldrsh r6, [r0, r2]
	subs r2, r5, r6
	cmp r2, 0
	bge _08010376
	negs r2, r2
_08010376:
	ldr r3, [sp, 0x14]
	asrs r0, r3, 16
	mov r3, r9
	asrs r1, r3, 16
	subs r4, r0, r1
	adds r3, r4, 0
	str r0, [sp, 0x18]
	mov r8, r1
	cmp r4, 0
	bge _0801038C
	negs r4, r4
_0801038C:
	cmp r4, r2
	bge _08010392
	adds r4, r2, 0
_08010392:
	lsrs r0, r4, 31
	adds r0, r4, r0
	asrs r4, r0, 1
	subs r0, r6, r5
	str r0, [sp, 0xC]
	str r3, [sp, 0x10]
	add r0, sp, 0xC
	bl sub_800A0B0
	ldr r1, _08010474
	adds r3, r0, r1
	cmp r3, 0
	bge _080103B0
	ldr r2, _08010478
	adds r3, r0, r2
_080103B0:
	asrs r3, 9
	movs r0, 0x7
	ands r3, r0
	ldr r0, _0801047C
	ldr r1, [r0]
	ldr r2, _08010480
	adds r0, r1, r2
	ldr r2, _08010484
	adds r1, r2
	ldr r1, [r1]
	movs r2, 0
	str r2, [sp]
	str r2, [sp, 0x4]
	movs r2, 0x1
	str r2, [sp, 0x8]
	movs r2, 0
	bl sub_80053AC
	movs r7, 0
	cmp r7, r4
	bge _08010448
	mov r10, r5
_080103DC:
	ldr r0, _0801047C
	ldr r6, [r0]
	mov r3, r9
	lsls r0, r3, 16
	asrs r0, 16
	mov r1, r10
	subs r0, r1, r0
	lsls r5, r7, 8
	muls r0, r5
	adds r1, r4, 0
	bl __divsi3
	cmp r0, 0
	bge _080103FA
	adds r0, 0xFF
_080103FA:
	asrs r0, 8
	add r0, r9
	ldr r2, _08010488
	adds r1, r6, r2
	strh r0, [r1]
	ldr r3, [sp, 0x18]
	mov r1, r8
	subs r0, r3, r1
	muls r0, r5
	adds r1, r4, 0
	bl __divsi3
	cmp r0, 0
	bge _08010418
	adds r0, 0xFF
_08010418:
	asrs r0, 8
	add r0, r8
	ldr r2, _0801048C
	adds r1, r6, r2
	strh r0, [r1]
	bl sub_8010798
	bl sub_8010858
	bl sub_8010960
	ldr r0, _08010490
	ldrh r1, [r0, 0x2]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	bne _08010448
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	bne _08010448
	adds r7, 0x1
	cmp r7, r4
	blt _080103DC
_08010448:
	ldr r0, _0801047C
	ldr r0, [r0]
	ldr r3, _08010488
	adds r0, r3
	ldr r1, [sp, 0x14]
	str r1, [r0]
	bl sub_8010798
	bl sub_8010858
	bl sub_8010960
	add sp, 0x1C
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_08010470: .4byte gUnknown_80D3F14
_08010474: .4byte 0xfffffc00
_08010478: .4byte 0xfffffdff
_0801047C: .4byte gUnknown_203B0E8
_08010480: .4byte 0x00005114
_08010484: .4byte 0x0000110c
_08010488: .4byte 0x000052dc
_0801048C: .4byte 0x000052de
_08010490: .4byte gUnknown_20255F0
	thumb_func_end sub_8010344

	thumb_func_start sub_8010494
sub_8010494:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0xC
	mov r9, r0
	movs r5, 0
	ldr r0, _080104C0
	mov r10, r0
	mov r8, r5
_080104AA:
	mov r1, r10
	ldr r0, [r1]
	mov r3, r8
	adds r4, r0, r3
	cmp r5, 0x3E
	bgt _080104C4
	mov r0, r9
	adds r0, 0x6D
	adds r0, r5
	ldrb r0, [r0]
	b _080104C6
	.align 2, 0
_080104C0: .4byte gUnknown_203B0E8
_080104C4:
	movs r0, 0x1
_080104C6:
	cmp r0, 0
	beq _0801050C
	movs r7, 0
	movs r6, 0x1
	strb r6, [r4]
	adds r3, r4, 0
	adds r3, 0x8
	mov r1, r10
	ldr r0, [r1]
	ldr r1, _08010504
	adds r0, r1
	ldr r1, [r0]
	movs r2, 0x1
	cmp r5, 0x3F
	bne _080104E6
	movs r2, 0xC
_080104E6:
	movs r0, 0x40
	str r0, [sp]
	str r7, [sp, 0x4]
	str r6, [sp, 0x8]
	adds r0, r3, 0
	movs r3, 0
	bl sub_80053AC
	ldr r1, _08010508
	lsls r0, r5, 2
	adds r0, r1
	ldr r0, [r0]
	str r0, [r4, 0x4]
	b _0801050E
	.align 2, 0
_08010504: .4byte 0x00001108
_08010508: .4byte gUnknown_80D3F14
_0801050C:
	strb r0, [r4]
_0801050E:
	movs r3, 0x44
	add r8, r3
	adds r5, 0x1
	cmp r5, 0x3F
	ble _080104AA
	movs r2, 0
	ldr r4, _0801057C
	ldr r1, [r4]
	ldr r3, _08010580
	adds r0, r1, r3
	ldr r3, _08010584
	adds r1, r3
	ldr r1, [r1]
	str r2, [sp]
	str r2, [sp, 0x4]
	movs r2, 0x1
	str r2, [sp, 0x8]
	movs r2, 0
	movs r3, 0
	bl sub_80053AC
	ldr r2, [r4]
	ldr r4, _08010588
	adds r3, r2, r4
	ldr r1, _0801058C
	mov r4, r9
	ldrb r0, [r4]
	lsls r0, 2
	adds r0, r1
	ldr r0, [r0]
	str r0, [r3]
	ldrh r0, [r3]
	subs r0, 0x78
	ldr r3, _08010590
	adds r1, r2, r3
	strh r0, [r1]
	ldr r4, _08010594
	adds r0, r2, r4
	ldrh r0, [r0]
	subs r0, 0x50
	ldr r1, _08010598
	adds r2, r1
	strh r0, [r2]
	bl sub_8010798
	bl sub_8010858
	add sp, 0xC
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_0801057C: .4byte gUnknown_203B0E8
_08010580: .4byte 0x00005114
_08010584: .4byte 0x0000110c
_08010588: .4byte 0x000052dc
_0801058C: .4byte gUnknown_80D3F14
_08010590: .4byte 0x000052d8
_08010594: .4byte 0x000052de
_08010598: .4byte 0x000052da
	thumb_func_end sub_8010494

	thumb_func_start sub_801059C
sub_801059C:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x14
	bl sub_808D33C
	adds r7, r0, 0
	ldr r6, _080106E4
	ldr r0, [r6]
	ldr r5, _080106E8
	adds r1, r5, 0
	bl OpenFileAndGetFileDataPtr
	str r0, [sp, 0xC]
	ldr r0, [r6, 0x4]
	adds r1, r5, 0
	bl OpenFileAndGetFileDataPtr
	str r0, [sp, 0x10]
	ldr r1, _080106EC
	movs r0, 0x8
	ldrsh r2, [r7, r0]
	mov r0, sp
	bl sprintf
	ldr r1, _080106F0
	mov r8, r1
	mov r0, sp
	bl OpenFileAndGetFileDataPtr
	ldr r4, _080106F4
	ldr r1, [r4]
	ldr r2, _080106F8
	adds r1, r2
	str r0, [r1]
	ldr r0, _080106FC
	adds r1, r5, 0
	bl OpenFileAndGetFileDataPtr
	ldr r1, [r4]
	ldr r3, _08010700
	mov r9, r3
	add r1, r9
	str r0, [r1]
	ldr r0, [r6, 0x8]
	adds r1, r5, 0
	bl OpenFileAndGetFileDataPtr
	ldr r1, [r4]
	ldr r2, _08010704
	mov r10, r2
	add r1, r10
	str r0, [r1]
	ldr r0, _08010708
	mov r1, r8
	bl OpenFileAndGetFileDataPtr
	ldr r1, [r4]
	ldr r3, _0801070C
	adds r1, r3
	str r0, [r1]
	ldr r0, [r6, 0xC]
	adds r1, r5, 0
	bl OpenFileAndGetFileDataPtr
	ldr r1, [r4]
	movs r2, 0x88
	lsls r2, 5
	adds r1, r2
	str r0, [r1]
	movs r3, 0x8
	ldrsh r0, [r7, r3]
	movs r1, 0
	bl sub_808DD68
	ldr r1, [r4]
	ldr r3, _08010710
	adds r2, r1, r3
	lsls r0, 24
	lsrs r0, 24
	str r0, [r2]
	add r1, r9
	ldr r0, [r1]
	movs r1, 0x40
	movs r2, 0x1F
	movs r3, 0
	bl sub_8005610
	ldr r0, _08010714
	movs r1, 0
	ldr r2, [sp, 0xC]
	bl sub_800AE28
	ldr r1, [r4]
	ldr r2, _08010718
	adds r0, r1, r2
	add r1, r10
	ldr r1, [r1]
	movs r2, 0x10
	bl sub_8004AA4
	movs r1, 0x80
	lsls r1, 7
	ldr r0, [r4]
	ldr r3, _0801071C
	adds r0, r3
	ldr r2, [sp, 0x10]
	bl sub_800AAA8
	ldr r1, [r4]
	ldr r2, _08010720
	adds r0, r1, r2
	movs r2, 0
	str r2, [r0]
	ldr r3, _08010724
	adds r0, r1, r3
	strh r2, [r0]
	ldr r0, _08010728
	adds r1, r0
	strh r2, [r1]
	movs r3, 0
	ldr r1, _0801072C
	mov r9, r1
	mov r8, r4
	ldr r7, _08010730
	ldr r2, _08010734
	adds r4, r2, 0
	ldr r6, _08010738
	movs r5, 0
_080106A2:
	mov r0, r8
	ldr r2, [r0]
	lsls r0, r3, 1
	adds r1, r2, r7
	adds r1, r0
	ldrh r0, [r1]
	orrs r0, r4
	strh r0, [r1]
	adds r2, r6
	adds r2, r3
	strb r5, [r2]
	adds r3, 0x1
	cmp r3, r9
	ble _080106A2
	ldr r0, [sp, 0xC]
	bl CloseFile
	ldr r0, [sp, 0x10]
	bl CloseFile
	movs r0, 0
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	add sp, 0x14
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_080106E4: .4byte gUnknown_80D4014
_080106E8: .4byte gUnknown_8380000
_080106EC: .4byte gUnknown_80D405C
_080106F0: .4byte gUnknown_8510000
_080106F4: .4byte gUnknown_203B0E8
_080106F8: .4byte 0x0000110c
_080106FC: .4byte gUnknown_80D4064
_08010700: .4byte 0x00001108
_08010704: .4byte 0x00001110
_08010708: .4byte gUnknown_80D406C
_0801070C: .4byte 0x00001104
_08010710: .4byte 0x000052d4
_08010714: .4byte 0x06008000
_08010718: .4byte 0x00005150
_0801071C: .4byte 0x00001114
_08010720: .4byte 0x000052d0
_08010724: .4byte 0x000052d8
_08010728: .4byte 0x000052da
_0801072C: .4byte 0x000005db
_08010730: .4byte 0x000052e0
_08010734: .4byte 0x0000ffff
_08010738: .4byte 0x00005e98
	thumb_func_end sub_801059C

	thumb_func_start sub_801073C
sub_801073C:
	push {r4,lr}
	ldr r4, _08010784
	ldr r0, [r4]
	ldr r1, _08010788
	adds r0, r1
	ldr r0, [r0]
	bl CloseFile
	ldr r0, [r4]
	ldr r1, _0801078C
	adds r0, r1
	ldr r0, [r0]
	bl CloseFile
	ldr r0, [r4]
	ldr r1, _08010790
	adds r0, r1
	ldr r0, [r0]
	bl CloseFile
	ldr r0, [r4]
	movs r1, 0x88
	lsls r1, 5
	adds r0, r1
	ldr r0, [r0]
	bl CloseFile
	ldr r0, [r4]
	ldr r1, _08010794
	adds r0, r1
	ldr r0, [r0]
	bl CloseFile
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08010784: .4byte gUnknown_203B0E8
_08010788: .4byte 0x00001110
_0801078C: .4byte 0x0000110c
_08010790: .4byte 0x00001108
_08010794: .4byte 0x00001104
	thumb_func_end sub_801073C

	thumb_func_start sub_8010798
sub_8010798:
	push {r4-r6,lr}
	ldr r2, _080107BC
	ldr r0, [r2]
	ldr r1, _080107C0
	adds r3, r0, r1
	movs r4, 0
	ldrsh r1, [r3, r4]
	ldr r5, _080107C4
	adds r4, r0, r5
	movs r6, 0
	ldrsh r0, [r4, r6]
	subs r1, r0
	adds r5, r2, 0
	cmp r1, 0x2F
	bgt _080107C8
	ldrh r0, [r3]
	subs r0, 0x30
	b _080107D0
	.align 2, 0
_080107BC: .4byte gUnknown_203B0E8
_080107C0: .4byte 0x000052dc
_080107C4: .4byte 0x000052d8
_080107C8:
	cmp r1, 0xC0
	ble _080107D2
	ldrh r0, [r3]
	subs r0, 0xC0
_080107D0:
	strh r0, [r4]
_080107D2:
	ldr r0, [r5]
	ldr r1, _080107F0
	adds r3, r0, r1
	movs r2, 0
	ldrsh r1, [r3, r2]
	ldr r4, _080107F4
	adds r2, r0, r4
	movs r6, 0
	ldrsh r0, [r2, r6]
	subs r1, r0
	cmp r1, 0x2F
	bgt _080107F8
	ldrh r0, [r3]
	subs r0, 0x30
	b _08010800
	.align 2, 0
_080107F0: .4byte 0x000052de
_080107F4: .4byte 0x000052da
_080107F8:
	cmp r1, 0x70
	ble _08010802
	ldrh r0, [r3]
	subs r0, 0x70
_08010800:
	strh r0, [r2]
_08010802:
	adds r3, r5, 0
	ldr r0, [r3]
	ldr r4, _08010850
	adds r1, r0, r4
	movs r2, 0
	ldrsh r0, [r1, r2]
	cmp r0, 0
	bge _08010816
	movs r0, 0
	strh r0, [r1]
_08010816:
	ldr r0, [r3]
	ldr r2, _08010854
	adds r1, r0, r2
	movs r6, 0
	ldrsh r0, [r1, r6]
	cmp r0, 0
	bge _08010828
	movs r0, 0
	strh r0, [r1]
_08010828:
	ldr r0, [r3]
	adds r1, r0, r4
	movs r3, 0
	ldrsh r0, [r1, r3]
	cmp r0, 0xEF
	ble _08010838
	movs r0, 0xF0
	strh r0, [r1]
_08010838:
	ldr r0, [r5]
	adds r2, r0, r2
	movs r4, 0
	ldrsh r0, [r2, r4]
	cmp r0, 0x9F
	ble _08010848
	movs r0, 0xA0
	strh r0, [r2]
_08010848:
	pop {r4-r6}
	pop {r0}
	bx r0
	.align 2, 0
_08010850: .4byte 0x000052d8
_08010854: .4byte 0x000052da
	thumb_func_end sub_8010798

	thumb_func_start sub_8010858
sub_8010858:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x4
	ldr r0, _080108FC
	ldr r1, [r0]
	ldr r2, _08010900
	adds r1, r2
	ldrh r1, [r1]
	lsls r1, 16
	asrs r6, r1, 19
	adds r2, r6, 0
	movs r3, 0
	mov r10, r0
	movs r0, 0x1F
	mov r9, r0
_0801087C:
	mov r1, r10
	ldr r0, [r1]
	ldr r1, _08010904
	adds r0, r1
	ldrh r0, [r0]
	lsls r0, 16
	asrs r4, r0, 19
	lsls r1, r2, 7
	adds r2, 0x1
	mov r12, r2
	adds r3, 0x1
	mov r8, r3
	movs r7, 0x1E
	lsls r0, r4, 1
	adds r5, r0, r1
_0801089A:
	mov r2, r9
	ands r4, r2
	ands r6, r2
	lsls r2, r4, 1
	lsls r0, r6, 6
	adds r2, r0
	ldr r3, _08010908
	adds r3, r2, r3
	str r3, [sp]
	mov r0, r10
	ldr r1, [r0]
	ldr r3, _0801090C
	adds r0, r1, r3
	adds r0, r5
	ldrh r0, [r0]
	ldr r3, [sp]
	strh r0, [r3]
	ldr r0, _08010910
	adds r2, r0
	ldr r3, _08010914
	adds r1, r3
	adds r1, r5
	ldrh r0, [r1]
	strh r0, [r2]
	adds r5, 0x2
	adds r4, 0x1
	subs r7, 0x1
	cmp r7, 0
	bge _0801089A
	mov r2, r12
	adds r6, 0x1
	mov r3, r8
	cmp r3, 0x14
	ble _0801087C
	movs r0, 0x2
	bl sub_80098F8
	movs r0, 0x3
	bl sub_80098F8
	add sp, 0x4
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_080108FC: .4byte gUnknown_203B0E8
_08010900: .4byte 0x000052da
_08010904: .4byte 0x000052d8
_08010908: .4byte gUnknown_202C038
_0801090C: .4byte 0x00003114
_08010910: .4byte gUnknown_202C838
_08010914: .4byte 0x00001114
	thumb_func_end sub_8010858

	thumb_func_start nullsub_24
nullsub_24:
	bx lr
	thumb_func_end nullsub_24

	thumb_func_start sub_801091C
sub_801091C:
	push {r4,r5,lr}
	bl sub_8010950
	bl sub_80117C4
	ldr r5, _08010948
	movs r4, 0x3B
_0801092A:
	ldr r1, [r5]
	ldr r0, _0801094C
	adds r1, r0
	ldr r0, [r1]
	subs r0, 0x2
	str r0, [r1]
	bl sub_8010960
	subs r4, 0x1
	cmp r4, 0
	bge _0801092A
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_08010948: .4byte gUnknown_203B0E8
_0801094C: .4byte 0x000052d0
	thumb_func_end sub_801091C

	thumb_func_start sub_8010950
sub_8010950:
	push {lr}
	movs r0, 0
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	pop {r0}
	bx r0
	thumb_func_end sub_8010950

	thumb_func_start sub_8010960
sub_8010960:
	push {r4-r6,lr}
	ldr r6, _080109EC
	ldr r1, [r6]
	ldr r4, _080109F0
	adds r0, r1, r4
	movs r2, 0
	ldrsh r0, [r0, r2]
	ldr r5, _080109F4
	adds r1, r5
	movs r2, 0
	ldrsh r1, [r1, r2]
	bl sub_800CCA0
	ldr r1, [r6]
	adds r4, r1, r4
	movs r2, 0
	ldrsh r0, [r4, r2]
	adds r1, r5
	movs r2, 0
	ldrsh r1, [r1, r2]
	bl sub_800CCAC
	movs r0, 0x1
	bl sub_8010A88
	bl sub_8010A00
	movs r0, 0
	movs r1, 0
	bl sub_8005838
	ldr r0, _080109F8
	ldr r0, [r0]
	ldrb r0, [r0, 0xA]
	bl nullsub_8
	bl sub_8005180
	bl sub_80060EC
	ldr r0, _080109FC
	ldr r0, [r0]
	bl sub_8094FB4
	bl sub_800CB20
	bl sub_800485C
	bl CopySpritesToOam
	bl sub_8005304
	bl TransferBGPaletteBuffer
	bl xxx_call_update_bg_vram
	bl nullsub_24
	bl sub_8009908
	bl xxx_call_update_bg_sound_input
	bl sub_8011860
	movs r0, 0
	bl ResetSprites
	pop {r4-r6}
	pop {r0}
	bx r0
	.align 2, 0
_080109EC: .4byte gUnknown_203B0E8
_080109F0: .4byte 0x000052d8
_080109F4: .4byte 0x000052da
_080109F8: .4byte gUnknown_203B46C
_080109FC: .4byte gUnknown_203B47C
	thumb_func_end sub_8010960

	thumb_func_start sub_8010A00
sub_8010A00:
	push {r4-r6,lr}
	movs r3, 0
	ldr r6, _08010A7C
	ldr r0, [r6]
	ldr r2, _08010A80
	adds r1, r0, r2
	ldr r2, [r1]
	cmp r2, 0x1E
	bgt _08010A74
	movs r3, 0x88
	lsls r3, 5
	adds r0, r3
	ldr r0, [r0]
	ldr r5, [r0, 0x4]
	adds r0, r2, 0x1
	str r0, [r1]
	cmp r0, 0x1E
	ble _08010A28
	movs r0, 0x1F
	str r0, [r1]
_08010A28:
	movs r4, 0
_08010A2A:
	ldr r0, [r6]
	ldr r1, _08010A80
	adds r0, r1
	ldr r2, [r0]
	adds r0, r4, 0
	adds r1, r5, 0
	movs r3, 0
	bl SetBGPaletteBufferColorRGB
	adds r5, 0x4
	adds r4, 0x1
	cmp r4, 0xDF
	ble _08010A2A
	ldr r0, _08010A7C
	ldr r0, [r0]
	ldr r2, _08010A84
	adds r0, r2
	ldr r0, [r0]
	ldr r5, [r0, 0x4]
	movs r4, 0
_08010A52:
	movs r3, 0x80
	lsls r3, 1
	adds r0, r4, r3
	ldr r1, _08010A7C
	ldr r1, [r1]
	ldr r2, _08010A80
	adds r1, r2
	ldr r2, [r1]
	adds r1, r5, 0
	movs r3, 0
	bl SetBGPaletteBufferColorRGB
	adds r5, 0x4
	adds r4, 0x1
	cmp r4, 0xEF
	ble _08010A52
	movs r3, 0x1
_08010A74:
	adds r0, r3, 0
	pop {r4-r6}
	pop {r1}
	bx r1
	.align 2, 0
_08010A7C: .4byte gUnknown_203B0E8
_08010A80: .4byte 0x000052d0
_08010A84: .4byte 0x00001104
	thumb_func_end sub_8010A00

	thumb_func_start sub_8010A88
sub_8010A88:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x14
	lsls r0, 24
	lsrs r0, 24
	mov r9, r0
	add r0, sp, 0x8
	bl sub_8004E8C
	add r1, sp, 0x8
	ldr r0, _08010B58
	strh r0, [r1, 0x4]
	movs r0, 0x80
	lsls r0, 4
	strh r0, [r1, 0xA]
	ldr r6, _08010B5C
	ldr r0, [r6]
	ldr r2, _08010B60
	adds r1, r0, r2
	ldr r5, [r1]
	ldr r3, _08010B64
	adds r0, r3
	bl sub_80054BC
	mov r0, r9
	cmp r0, 0
	beq _08010AF6
	ldr r4, [r6]
	ldr r1, _08010B64
	adds r0, r4, r1
	ldr r2, _08010B68
	adds r1, r4, r2
	movs r3, 0
	ldrsh r1, [r1, r3]
	lsls r2, r5, 16
	asrs r2, 16
	subs r1, r2
	ldr r3, _08010B6C
	adds r2, r4, r3
	movs r3, 0
	ldrsh r2, [r2, r3]
	asrs r3, r5, 16
	subs r2, r3
	ldr r3, _08010B70
	adds r4, r3
	ldr r3, [r4]
	str r3, [sp]
	add r3, sp, 0x8
	str r3, [sp, 0x4]
	movs r3, 0x3
	bl sub_800558C
_08010AF6:
	lsls r0, r5, 16
	asrs r0, 16
	mov r10, r0
	movs r7, 0
	asrs r5, 16
	mov r8, r5
	movs r6, 0x3F
_08010B04:
	ldr r1, _08010B5C
	ldr r0, [r1]
	adds r4, r0, r7
	ldrb r0, [r4]
	cmp r0, 0
	beq _08010B40
	adds r5, r4, 0
	adds r5, 0x8
	adds r0, r5, 0
	bl sub_80054BC
	mov r2, r9
	cmp r2, 0
	beq _08010B40
	movs r3, 0x4
	ldrsh r1, [r4, r3]
	mov r0, r10
	subs r1, r0
	movs r3, 0x6
	ldrsh r2, [r4, r3]
	mov r0, r8
	subs r2, r0
	movs r0, 0
	str r0, [sp]
	add r3, sp, 0x8
	str r3, [sp, 0x4]
	adds r0, r5, 0
	movs r3, 0x1
	bl sub_800558C
_08010B40:
	adds r7, 0x44
	subs r6, 0x1
	cmp r6, 0
	bge _08010B04
	add sp, 0x14
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_08010B58: .4byte 0x0000f3ff
_08010B5C: .4byte gUnknown_203B0E8
_08010B60: .4byte 0x000052d8
_08010B64: .4byte 0x00005114
_08010B68: .4byte 0x000052dc
_08010B6C: .4byte 0x000052de
_08010B70: .4byte 0x000052d4
	thumb_func_end sub_8010A88

	thumb_func_start sub_8010B74
sub_8010B74:
	push {r4,r5,lr}
	sub sp, 0x64
	adds r5, r0, 0
	add r4, sp, 0x4
	adds r0, r4, 0
	movs r1, 0
	movs r2, 0x60
	bl memset
	movs r2, 0x3
	str r2, [sp, 0x8]
	movs r0, 0xC
	strh r0, [r4, 0x8]
	movs r1, 0x2
	strh r1, [r4, 0xA]
	movs r0, 0x10
	strh r0, [r4, 0xC]
	strh r1, [r4, 0xE]
	strh r1, [r4, 0x10]
	str r2, [sp, 0x20]
	str r2, [sp, 0x38]
	str r2, [sp, 0x50]
	ldr r0, _08010BC0
	ldr r0, [r0]
	ldr r2, _08010BC4
	adds r1, r0, r2
	movs r2, 0
	ldrsh r1, [r1, r2]
	ldr r2, _08010BC8
	adds r0, r2
	movs r2, 0
	ldrsh r0, [r0, r2]
	subs r1, r0
	cmp r1, 0x50
	bgt _08010BCC
	add r1, sp, 0x4
	movs r0, 0x11
	b _08010BD0
	.align 2, 0
_08010BC0: .4byte gUnknown_203B0E8
_08010BC4: .4byte 0x000052de
_08010BC8: .4byte 0x000052da
_08010BCC:
	add r1, sp, 0x4
	movs r0, 0x1
_08010BD0:
	strh r0, [r1, 0xA]
	add r0, sp, 0x4
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	movs r0, 0
	bl sub_80073B8
	ldr r0, _08010C08
	adds r1, r5, 0
	bl sub_809027C
	ldr r2, _08010C0C
	movs r0, 0
	str r0, [sp]
	movs r0, 0xC
	movs r1, 0x2
	movs r3, 0
	bl sub_8014FF0
	movs r0, 0
	bl sub_80073E0
	add sp, 0x64
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_08010C08: .4byte gUnknown_202DF98
_08010C0C: .4byte gUnknown_80D4074
	thumb_func_end sub_8010B74

	thumb_func_start sub_8010C10
sub_8010C10:
	push {r4,lr}
	sub sp, 0x18
	movs r2, 0
	str r2, [sp]
	movs r1, 0x3
	str r1, [sp, 0x4]
	str r2, [sp, 0x8]
	str r2, [sp, 0xC]
	ldr r1, _08010C54
	str r1, [sp, 0x10]
	movs r1, 0
	movs r3, 0
	bl sub_8014248
_08010C2C:
	bl xxx_draw_string_80144C4
	bl sub_8010960
	add r0, sp, 0x14
	bl sub_80144A4
	cmp r0, 0
	bne _08010C2C
	movs r4, 0x9
_08010C40:
	bl sub_8010960
	subs r4, 0x1
	cmp r4, 0
	bge _08010C40
	add sp, 0x18
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08010C54: .4byte 0x00000301
	thumb_func_end sub_8010C10

	thumb_func_start sub_8010C58
sub_8010C58:
	push {r4-r6,lr}
	sub sp, 0x38
	adds r5, r0, 0
	movs r2, 0
	ldrb r0, [r5]
	ldr r3, _08010D70
	add r6, sp, 0x2C
	cmp r0, 0
	beq _08010C7C
	adds r1, r5, 0
_08010C6C:
	ldrb r0, [r1]
	cmp r0, 0xA
	bne _08010C74
	adds r2, 0xC
_08010C74:
	adds r1, 0x1
	ldrb r0, [r1]
	cmp r0, 0
	bne _08010C6C
_08010C7C:
	adds r2, 0xB
	adds r0, r2, 0
	cmp r2, 0
	bge _08010C86
	adds r0, r2, 0x7
_08010C86:
	asrs r2, r0, 3
	movs r0, 0x13
	subs r0, r2
	movs r4, 0
	strh r0, [r3, 0xA]
	strh r2, [r3, 0x10]
	strh r2, [r3, 0xE]
	movs r0, 0xE
	subs r0, r2
	strh r0, [r3, 0x22]
	adds r0, r3, 0
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	movs r0, 0
	bl sub_80073B8
	str r4, [sp]
	movs r0, 0x4
	movs r1, 0
	adds r2, r5, 0
	movs r3, 0
	bl sub_8014FF0
	movs r0, 0
	bl sub_80073E0
	movs r0, 0x1
	bl sub_80073B8
	ldr r2, _08010D74
	str r4, [sp]
	movs r0, 0xA
	movs r1, 0
	movs r3, 0x1
	bl sub_8014FF0
	ldr r2, _08010D78
	str r4, [sp]
	movs r0, 0xA
	movs r1, 0xC
	movs r3, 0x1
	bl sub_8014FF0
	movs r0, 0x1
	bl sub_80073E0
	add r0, sp, 0x4
	movs r2, 0x1
	strh r2, [r0, 0x18]
	movs r1, 0x2
	strh r1, [r0, 0x1A]
	strh r1, [r0, 0x1C]
	strh r4, [r0, 0x1E]
	strh r4, [r0, 0x20]
	strh r4, [r0, 0x4]
	strh r4, [r0, 0x6]
	str r2, [sp, 0x4]
	strh r4, [r0, 0xC]
	strh r4, [r0, 0xE]
	strh r4, [r0, 0x14]
	strh r4, [r0, 0x16]
	movs r1, 0x8
	strh r1, [r0, 0x8]
	strh r1, [r0, 0xA]
	movs r1, 0x18
	bl sub_80137B0
	adds r0, r6, 0
	bl sub_801317C
	ldr r4, _08010D7C
_08010D18:
	add r0, sp, 0x4
	bl AddMenuCursorSprite
	bl sub_8010960
	ldrh r1, [r4, 0x4]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	beq _08010D36
	add r0, sp, 0x4
	bl MoveMenuCursorDown
	bl sub_80117F8
_08010D36:
	ldrh r1, [r4, 0x4]
	movs r0, 0x40
	ands r0, r1
	cmp r0, 0
	beq _08010D4A
	add r0, sp, 0x4
	bl MoveMenuCursorUp
	bl sub_80117F8
_08010D4A:
	ldrh r1, [r4, 0x2]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	bne _08010D5E
	mov r0, sp
	adds r0, 0x2D
	ldrb r0, [r0]
	cmp r0, 0
	beq _08010D18
_08010D5E:
	bl sub_80117D0
	add r0, sp, 0x4
	movs r1, 0x18
	ldrsh r0, [r0, r1]
	cmp r0, 0
	beq _08010D80
	movs r0, 0
	b _08010D82
	.align 2, 0
_08010D70: .4byte gUnknown_203B0EC
_08010D74: .4byte gUnknown_80D407C
_08010D78: .4byte gUnknown_80D4080
_08010D7C: .4byte gUnknown_20255F0
_08010D80:
	movs r0, 0x1
_08010D82:
	add sp, 0x38
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end sub_8010C58

	thumb_func_start sub_8010D8C
sub_8010D8C:
	lsls r0, 24
	ldr r2, _08010DA0
	lsrs r0, 22
	adds r0, r2
	ldrh r2, [r0]
	strh r2, [r1]
	ldrh r0, [r0, 0x2]
	strh r0, [r1, 0x2]
	bx lr
	.align 2, 0
_08010DA0: .4byte gUnknown_80D3F14
	thumb_func_end sub_8010D8C

	thumb_func_start sub_8010DA4
sub_8010DA4:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0xC
	bl sub_808D33C
	mov r9, r0
	ldr r6, _08010EBC
	ldr r0, [r6]
	ldr r5, _08010EC0
	adds r1, r5, 0
	bl OpenFileAndGetFileDataPtr
	mov r10, r0
	ldr r0, [r6, 0x4]
	adds r1, r5, 0
	bl OpenFileAndGetFileDataPtr
	adds r7, r0, 0
	ldr r1, _08010EC4
	mov r0, r9
	movs r3, 0x8
	ldrsh r2, [r0, r3]
	mov r0, sp
	bl sprintf
	ldr r0, _08010EC8
	mov r8, r0
	mov r0, sp
	mov r1, r8
	bl OpenFileAndGetFileDataPtr
	ldr r4, _08010ECC
	ldr r1, [r4]
	str r0, [r1, 0xC]
	ldr r0, _08010ED0
	adds r1, r5, 0
	bl OpenFileAndGetFileDataPtr
	ldr r1, [r4]
	str r0, [r1, 0x8]
	ldr r0, [r6, 0x8]
	adds r1, r5, 0
	bl OpenFileAndGetFileDataPtr
	ldr r1, [r4]
	str r0, [r1, 0x10]
	ldr r0, _08010ED4
	mov r1, r8
	bl OpenFileAndGetFileDataPtr
	ldr r1, [r4]
	str r0, [r1, 0x4]
	ldr r0, [r6, 0xC]
	adds r1, r5, 0
	bl OpenFileAndGetFileDataPtr
	ldr r1, [r4]
	str r0, [r1]
	mov r1, r9
	movs r2, 0x8
	ldrsh r0, [r1, r2]
	movs r1, 0
	bl sub_808DD68
	ldr r2, [r4]
	ldr r3, _08010ED8
	adds r1, r2, r3
	lsls r0, 24
	lsrs r0, 24
	str r0, [r1]
	ldr r0, [r2, 0x8]
	movs r1, 0x40
	movs r2, 0x1F
	movs r3, 0
	bl sub_8005610
	ldr r0, _08010EDC
	movs r1, 0
	mov r2, r10
	bl sub_800AE28
	ldr r1, [r4]
	ldr r2, _08010EE0
	adds r0, r1, r2
	ldr r1, [r1, 0x10]
	movs r2, 0x10
	bl sub_8004AA4
	movs r1, 0x80
	lsls r1, 7
	ldr r0, [r4]
	adds r0, 0x14
	adds r2, r7, 0
	bl sub_800AAA8
	ldr r1, [r4]
	ldr r3, _08010EE4
	adds r0, r1, r3
	movs r2, 0
	str r2, [r0]
	adds r3, 0x8
	adds r0, r1, r3
	strh r2, [r0]
	ldr r0, _08010EE8
	adds r1, r0
	strh r2, [r1]
	ldr r5, _08010EEC
	movs r3, 0
	movs r1, 0x7
_08010E84:
	ldr r0, [r4]
	adds r0, r2, r0
	adds r0, r5
	strh r3, [r0]
	adds r2, 0x3C
	subs r1, 0x1
	cmp r1, 0
	bge _08010E84
	mov r0, r10
	bl CloseFile
	adds r0, r7, 0
	bl CloseFile
	movs r0, 0
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	add sp, 0xC
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_08010EBC: .4byte gUnknown_80D408C
_08010EC0: .4byte gUnknown_8380000
_08010EC4: .4byte gUnknown_80D40E4
_08010EC8: .4byte gUnknown_8510000
_08010ECC: .4byte gUnknown_203B0E4
_08010ED0: .4byte gUnknown_80D40EC
_08010ED4: .4byte gUnknown_80D40F4
_08010ED8: .4byte 0x00004dd0
_08010EDC: .4byte 0x06008000
_08010EE0: .4byte 0x00004c4c
_08010EE4: .4byte 0x00004dcc
_08010EE8: .4byte 0x00004dd6
_08010EEC: .4byte 0x00004a30
	thumb_func_end sub_8010DA4

	thumb_func_start sub_8010EF0
sub_8010EF0:
	push {r4,lr}
	ldr r4, _08010F24
	ldr r0, [r4]
	ldr r0, [r0, 0x10]
	bl CloseFile
	ldr r0, [r4]
	ldr r0, [r0, 0x8]
	bl CloseFile
	ldr r0, [r4]
	ldr r0, [r0, 0xC]
	bl CloseFile
	ldr r0, [r4]
	ldr r0, [r0]
	bl CloseFile
	ldr r0, [r4]
	ldr r0, [r0, 0x4]
	bl CloseFile
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08010F24: .4byte gUnknown_203B0E4
	thumb_func_end sub_8010EF0

	thumb_func_start sub_8010F28
sub_8010F28:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x18
	add r0, sp, 0x8
	bl sub_8004E8C
	add r1, sp, 0x8
	ldr r0, _08011080
	strh r0, [r1, 0x4]
	movs r0, 0x80
	lsls r0, 4
	strh r0, [r1, 0xA]
	ldr r6, _08011084
	ldr r0, [r6]
	ldr r2, _08011088
	adds r1, r0, r2
	ldr r1, [r1]
	mov r8, r1
	ldr r4, _0801108C
	adds r0, r4
	bl sub_80054BC
	ldr r3, [r6]
	adds r4, r3, r4
	ldr r7, _08011090
	adds r0, r3, r7
	movs r2, 0
	ldrsh r1, [r0, r2]
	mov r7, r8
	lsls r5, r7, 16
	asrs r5, 16
	subs r1, r5
	ldr r2, _08011094
	adds r0, r3, r2
	movs r7, 0
	ldrsh r2, [r0, r7]
	mov r7, r8
	asrs r0, r7, 16
	subs r2, r0
	ldr r0, _08011098
	adds r3, r0
	ldr r0, [r3]
	str r0, [sp]
	add r3, sp, 0x8
	str r3, [sp, 0x4]
	adds r0, r4, 0
	movs r3, 0x3
	bl sub_800558C
	movs r7, 0
	mov r10, r6
	ldr r6, _0801109C
	mov r9, r5
_08010F98:
	mov r4, r10
	ldr r0, [r4]
	adds r4, r0, r6
	ldr r1, _080110A0
	adds r0, r1
	lsls r1, r7, 5
	ldr r0, [r0]
	adds r5, r0, r1
	ldrb r0, [r4]
	cmp r0, 0
	beq _08010FD8
	adds r4, 0x14
	adds r0, r4, 0
	bl sub_80054BC
	movs r2, 0x4
	ldrsh r1, [r5, r2]
	mov r3, r9
	subs r1, r3
	movs r0, 0x6
	ldrsh r2, [r5, r0]
	mov r3, r8
	asrs r0, r3, 16
	subs r2, r0
	movs r0, 0
	str r0, [sp]
	add r0, sp, 0x8
	str r0, [sp, 0x4]
	adds r0, r4, 0
	movs r3, 0x1
	bl sub_800558C
_08010FD8:
	adds r6, 0x50
	adds r7, 0x1
	cmp r7, 0x1F
	ble _08010F98
	movs r5, 0
	ldr r1, _08011084
	mov r9, r1
	ldr r6, _080110A4
	movs r2, 0
	str r2, [sp, 0x14]
_08010FEC:
	mov r3, r9
	ldr r1, [r3]
	ldr r4, [sp, 0x14]
	adds r0, r4, r1
	ldr r7, _080110A4
	adds r0, r7
	ldrh r0, [r0]
	lsrs r0, 15
	cmp r0, 0
	beq _08011062
	adds r0, r1, r6
	bl sub_80054BC
	ldr r0, _080110A8
	ldrh r0, [r0]
	movs r2, 0x80
	lsls r2, 1
	adds r1, r2, 0
	ands r0, r1
	cmp r0, 0
	beq _0801101E
	movs r0, 0x1
	ands r0, r5
	cmp r0, 0
	beq _08011062
_0801101E:
	mov r3, r9
	ldr r4, [r3]
	adds r0, r4, r6
	ldr r1, _080110AC
	lsls r3, r5, 2
	adds r3, r1
	movs r7, 0
	ldrsh r1, [r3, r7]
	ldr r7, _08011090
	adds r2, r4, r7
	movs r7, 0
	ldrsh r2, [r2, r7]
	adds r1, r2
	mov r7, r8
	lsls r2, r7, 16
	asrs r2, 16
	subs r1, r2
	movs r7, 0x2
	ldrsh r2, [r3, r7]
	ldr r3, _08011094
	adds r3, r4
	movs r4, 0
	ldrsh r3, [r3, r4]
	adds r2, r3
	mov r7, r8
	asrs r3, r7, 16
	subs r2, r3
	movs r3, 0
	str r3, [sp]
	add r3, sp, 0x8
	str r3, [sp, 0x4]
	movs r3, 0x2
	bl sub_800558C
_08011062:
	adds r6, 0x3C
	ldr r4, [sp, 0x14]
	adds r4, 0x3C
	str r4, [sp, 0x14]
	adds r5, 0x1
	cmp r5, 0x7
	ble _08010FEC
	add sp, 0x18
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_08011080: .4byte 0x0000f3ff
_08011084: .4byte gUnknown_203B0E4
_08011088: .4byte 0x00004dd4
_0801108C: .4byte 0x00004c10
_08011090: .4byte 0x00004dd8
_08011094: .4byte 0x00004dda
_08011098: .4byte 0x00004dd0
_0801109C: .4byte 0x00004018
_080110A0: .4byte 0x00004014
_080110A4: .4byte 0x00004a30
_080110A8: .4byte gUnknown_20255F0
_080110AC: .4byte gUnknown_80D40C4
	thumb_func_end sub_8010F28

	thumb_func_start sub_80110B0
sub_80110B0:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x4
	ldr r0, _08011150
	ldr r1, [r0]
	ldr r2, _08011154
	adds r1, r2
	ldrh r1, [r1]
	lsls r1, 16
	asrs r6, r1, 19
	adds r2, r6, 0
	movs r3, 0
	mov r10, r0
	movs r0, 0x1F
	mov r9, r0
_080110D4:
	mov r1, r10
	ldr r0, [r1]
	ldr r1, _08011158
	adds r0, r1
	ldrh r0, [r0]
	lsls r0, 16
	asrs r4, r0, 19
	lsls r1, r2, 7
	adds r2, 0x1
	mov r12, r2
	adds r3, 0x1
	mov r8, r3
	movs r7, 0x1E
	lsls r0, r4, 1
	adds r5, r0, r1
_080110F2:
	mov r2, r9
	ands r4, r2
	ands r6, r2
	lsls r2, r4, 1
	lsls r0, r6, 6
	adds r2, r0
	ldr r3, _0801115C
	adds r3, r2, r3
	str r3, [sp]
	mov r0, r10
	ldr r1, [r0]
	ldr r3, _08011160
	adds r0, r1, r3
	adds r0, r5
	ldrh r0, [r0]
	ldr r3, [sp]
	strh r0, [r3]
	ldr r0, _08011164
	adds r2, r0
	adds r1, 0x14
	adds r1, r5
	ldrh r0, [r1]
	strh r0, [r2]
	adds r5, 0x2
	adds r4, 0x1
	subs r7, 0x1
	cmp r7, 0
	bge _080110F2
	mov r2, r12
	adds r6, 0x1
	mov r3, r8
	cmp r3, 0x14
	ble _080110D4
	movs r0, 0x2
	bl sub_80098F8
	movs r0, 0x3
	bl sub_80098F8
	add sp, 0x4
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_08011150: .4byte gUnknown_203B0E4
_08011154: .4byte 0x00004dd6
_08011158: .4byte 0x00004dd4
_0801115C: .4byte gUnknown_202C038
_08011160: .4byte 0x00002014
_08011164: .4byte gUnknown_202C838
	thumb_func_end sub_80110B0

	thumb_func_start sub_8011168
sub_8011168:
	push {r4,r5,lr}
	movs r0, 0
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	ldr r3, _080111B0
	ldr r1, [r3]
	ldr r2, _080111B4
	adds r0, r1, r2
	movs r2, 0
	str r2, [r0]
	ldr r4, _080111B8
	adds r0, r1, r4
	str r2, [r0]
	adds r4, 0x4
	adds r0, r1, r4
	str r2, [r0]
	ldr r0, _080111BC
	adds r1, r0
	str r2, [r1]
	adds r5, r3, 0
	ldr r4, _080111C0
	movs r3, 0
	movs r1, 0x7
_0801119A:
	ldr r0, [r5]
	adds r0, r2, r0
	adds r0, r4
	strh r3, [r0]
	adds r2, 0x3C
	subs r1, 0x1
	cmp r1, 0
	bge _0801119A
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_080111B0: .4byte gUnknown_203B0E4
_080111B4: .4byte 0x00004ddc
_080111B8: .4byte 0x00004de0
_080111BC: .4byte 0x00004de8
_080111C0: .4byte 0x00004a30
	thumb_func_end sub_8011168

	thumb_func_start sub_80111C4
sub_80111C4:
	push {r4-r6,lr}
	movs r3, 0
	ldr r6, _08011238
	ldr r0, [r6]
	ldr r2, _0801123C
	adds r1, r0, r2
	ldr r2, [r1]
	cmp r2, 0x1E
	bgt _0801122E
	ldr r0, [r0]
	ldr r5, [r0, 0x4]
	adds r0, r2, 0x1
	str r0, [r1]
	cmp r0, 0x1E
	ble _080111E6
	movs r0, 0x1F
	str r0, [r1]
_080111E6:
	movs r4, 0
_080111E8:
	ldr r0, [r6]
	ldr r1, _0801123C
	adds r0, r1
	ldr r2, [r0]
	adds r0, r4, 0
	adds r1, r5, 0
	movs r3, 0
	bl SetBGPaletteBufferColorRGB
	adds r5, 0x4
	adds r4, 0x1
	cmp r4, 0xDF
	ble _080111E8
	ldr r0, _08011238
	ldr r0, [r0]
	ldr r0, [r0, 0x4]
	ldr r5, [r0, 0x4]
	movs r4, 0
_0801120C:
	movs r2, 0x80
	lsls r2, 1
	adds r0, r4, r2
	ldr r1, _08011238
	ldr r1, [r1]
	ldr r2, _0801123C
	adds r1, r2
	ldr r2, [r1]
	adds r1, r5, 0
	movs r3, 0
	bl SetBGPaletteBufferColorRGB
	adds r5, 0x4
	adds r4, 0x1
	cmp r4, 0xEF
	ble _0801120C
	movs r3, 0x1
_0801122E:
	adds r0, r3, 0
	pop {r4-r6}
	pop {r1}
	bx r1
	.align 2, 0
_08011238: .4byte gUnknown_203B0E4
_0801123C: .4byte 0x00004dcc
	thumb_func_end sub_80111C4

	thumb_func_start sub_8011240
sub_8011240:
	push {r4-r6,lr}
	ldr r2, _08011264
	ldr r0, [r2]
	ldr r1, _08011268
	adds r3, r0, r1
	movs r4, 0
	ldrsh r1, [r3, r4]
	ldr r5, _0801126C
	adds r4, r0, r5
	movs r6, 0
	ldrsh r0, [r4, r6]
	subs r1, r0
	adds r5, r2, 0
	cmp r1, 0x2F
	bgt _08011270
	ldrh r0, [r3]
	subs r0, 0x30
	b _08011278
	.align 2, 0
_08011264: .4byte gUnknown_203B0E4
_08011268: .4byte 0x00004dd8
_0801126C: .4byte 0x00004dd4
_08011270:
	cmp r1, 0xC0
	ble _0801127A
	ldrh r0, [r3]
	subs r0, 0xC0
_08011278:
	strh r0, [r4]
_0801127A:
	ldr r0, [r5]
	ldr r1, _08011298
	adds r3, r0, r1
	movs r2, 0
	ldrsh r1, [r3, r2]
	ldr r4, _0801129C
	adds r2, r0, r4
	movs r6, 0
	ldrsh r0, [r2, r6]
	subs r1, r0
	cmp r1, 0x2F
	bgt _080112A0
	ldrh r0, [r3]
	subs r0, 0x30
	b _080112A8
	.align 2, 0
_08011298: .4byte 0x00004dda
_0801129C: .4byte 0x00004dd6
_080112A0:
	cmp r1, 0x70
	ble _080112AA
	ldrh r0, [r3]
	subs r0, 0x70
_080112A8:
	strh r0, [r2]
_080112AA:
	adds r3, r5, 0
	ldr r0, [r3]
	ldr r4, _080112F8
	adds r1, r0, r4
	movs r2, 0
	ldrsh r0, [r1, r2]
	cmp r0, 0
	bge _080112BE
	movs r0, 0
	strh r0, [r1]
_080112BE:
	ldr r0, [r3]
	ldr r2, _080112FC
	adds r1, r0, r2
	movs r6, 0
	ldrsh r0, [r1, r6]
	cmp r0, 0
	bge _080112D0
	movs r0, 0
	strh r0, [r1]
_080112D0:
	ldr r0, [r3]
	adds r1, r0, r4
	movs r3, 0
	ldrsh r0, [r1, r3]
	cmp r0, 0xEF
	ble _080112E0
	movs r0, 0xEF
	strh r0, [r1]
_080112E0:
	ldr r0, [r5]
	adds r2, r0, r2
	movs r4, 0
	ldrsh r0, [r2, r4]
	cmp r0, 0x97
	ble _080112F0
	movs r0, 0x97
	strh r0, [r2]
_080112F0:
	pop {r4-r6}
	pop {r0}
	bx r0
	.align 2, 0
_080112F8: .4byte 0x00004dd4
_080112FC: .4byte 0x00004dd6
	thumb_func_end sub_8011240

	thumb_func_start sub_8011300
sub_8011300:
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	sub sp, 0xC
	ldr r0, _08011388
	ldr r2, [r0]
	ldr r1, _0801138C
	adds r0, r2, r1
	ldr r1, [r0]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 4
	ldr r3, _08011390
	adds r0, r3
	adds r2, r0
	mov r9, r2
	movs r4, 0
	ldr r0, _08011394
	mov r8, r0
	movs r7, 0
	mov r6, r8
	movs r5, 0
_0801132E:
	ldr r0, _08011388
	ldr r2, [r0]
	adds r0, r5, r2
	add r0, r8
	strh r7, [r0]
	lsls r1, r4, 1
	mov r0, r9
	adds r0, 0x2
	adds r1, r0, r1
	movs r3, 0
	ldrsh r0, [r1, r3]
	cmp r0, 0
	blt _08011370
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 4
	ldr r0, _08011390
	adds r1, r0
	adds r1, r2, r1
	ldrb r0, [r1]
	cmp r0, 0
	beq _08011370
	adds r0, r2, r6
	ldr r1, [r2, 0x8]
	adds r2, r4, 0x4
	movs r3, 0x40
	str r3, [sp]
	str r7, [sp, 0x4]
	movs r3, 0x1
	str r3, [sp, 0x8]
	movs r3, 0
	bl sub_80053AC
_08011370:
	adds r6, 0x3C
	adds r5, 0x3C
	adds r4, 0x1
	cmp r4, 0x7
	ble _0801132E
	add sp, 0xC
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_08011388: .4byte gUnknown_203B0E4
_0801138C: .4byte 0x00004a18
_08011390: .4byte 0x00004018
_08011394: .4byte 0x00004a30
	thumb_func_end sub_8011300

	thumb_func_start sub_8011398
sub_8011398:
	push {r4-r6,lr}
	sub sp, 0x12C
	ldr r5, _080113F4
	ldr r0, [r5]
	ldr r2, _080113F8
	adds r1, r0, r2
	ldr r1, [r1]
	ldr r3, _080113FC
	adds r0, r3
	lsls r1, 5
	ldr r0, [r0]
	adds r6, r0, r1
	add r4, sp, 0xCC
	adds r0, r4, 0
	movs r1, 0
	movs r2, 0x60
	bl memset
	movs r2, 0x3
	str r2, [r4, 0x4]
	movs r0, 0x7
	strh r0, [r4, 0x8]
	movs r1, 0x2
	strh r1, [r4, 0xA]
	movs r0, 0x15
	strh r0, [r4, 0xC]
	strh r1, [r4, 0xE]
	strh r1, [r4, 0x10]
	str r2, [r4, 0x1C]
	str r2, [r4, 0x34]
	str r2, [r4, 0x4C]
	ldr r0, [r5]
	ldr r2, _08011400
	adds r1, r0, r2
	movs r3, 0
	ldrsh r1, [r1, r3]
	subs r2, 0x4
	adds r0, r2
	movs r3, 0
	ldrsh r0, [r0, r3]
	subs r1, r0
	cmp r1, 0x50
	bgt _08011404
	movs r0, 0x11
	b _08011406
	.align 2, 0
_080113F4: .4byte gUnknown_203B0E4
_080113F8: .4byte 0x00004a18
_080113FC: .4byte 0x00004014
_08011400: .4byte 0x00004dda
_08011404:
	movs r0, 0x1
_08011406:
	strh r0, [r4, 0xA]
	adds r0, r4, 0
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	movs r0, 0
	bl sub_80073B8
	ldr r1, _0801147C
	ldr r2, [r6]
	add r0, sp, 0x4
	bl sub_800D158
	movs r0, 0
	str r0, [sp]
	movs r0, 0xC
	movs r1, 0x2
	add r2, sp, 0x4
	movs r3, 0
	bl sub_8014FF0
	movs r0, 0
	bl sub_80073E0
	ldr r0, _08011480
	ldr r1, [r0]
	ldr r0, _08011484
	adds r2, r1, r0
	movs r3, 0x8
	ldrsh r0, [r4, r3]
	lsls r0, 3
	subs r0, 0x5
	str r0, [r2]
	ldr r0, _08011488
	adds r2, r1, r0
	movs r3, 0xA
	ldrsh r0, [r4, r3]
	lsls r0, 3
	adds r0, 0x5
	str r0, [r2]
	ldr r0, _0801148C
	adds r2, r1, r0
	movs r3, 0xC
	ldrsh r0, [r4, r3]
	lsls r0, 3
	adds r0, 0xA
	str r0, [r2]
	ldr r0, _08011490
	adds r1, r0
	movs r2, 0xE
	ldrsh r0, [r4, r2]
	lsls r0, 3
	adds r0, 0xA
	str r0, [r1]
	add sp, 0x12C
	pop {r4-r6}
	pop {r0}
	bx r0
	.align 2, 0
_0801147C: .4byte gUnknown_80D40FC
_08011480: .4byte gUnknown_203B0E4
_08011484: .4byte 0x00004ddc
_08011488: .4byte 0x00004de0
_0801148C: .4byte 0x00004de4
_08011490: .4byte 0x00004de8
	thumb_func_end sub_8011398

	thumb_func_start sub_8011494
sub_8011494:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0xC8
	ldr r0, _08011610
	ldr r2, [r0]
	ldr r1, _08011614
	adds r0, r2, r1
	ldr r0, [r0]
	ldr r3, _08011618
	adds r1, r2, r3
	lsls r0, 5
	ldr r1, [r1]
	adds r1, r0
	mov r8, r1
	ldr r0, _0801161C
	adds r7, r2, r0
	add r4, sp, 0x64
	adds r0, r4, 0
	movs r1, 0
	movs r2, 0x60
	bl memset
	movs r0, 0x6
	str r0, [sp, 0x68]
	add r1, sp, 0x6C
	movs r0, 0x7
	strh r0, [r1]
	movs r2, 0x2
	strh r2, [r1, 0x2]
	add r1, sp, 0x70
	movs r0, 0x15
	strh r0, [r1]
	mov r0, sp
	adds r0, 0x72
	strh r2, [r0]
	add r0, sp, 0x74
	strh r2, [r0]
	add r5, sp, 0xC4
	str r5, [sp, 0x78]
	movs r1, 0x3
	str r1, [sp, 0x80]
	add r0, sp, 0x94
	str r1, [r0, 0x4]
	add r0, sp, 0xAC
	str r1, [r0, 0x4]
	add r0, sp, 0x4
	adds r1, r4, 0
	movs r2, 0x60
	bl memcpy
	movs r1, 0
	mov r9, r1
	movs r6, 0
	mov r10, r5
_08011506:
	mov r0, r8
	adds r0, 0x8
	adds r4, r0, r6
	ldrb r0, [r4]
	bl sub_800FFE8
	lsls r0, 24
	cmp r0, 0
	beq _0801152A
	ldr r0, _08011610
	ldr r0, [r0]
	ldr r2, _08011620
	adds r0, r2
	add r0, r9
	ldrb r1, [r4]
	strb r1, [r0]
	movs r3, 0x1
	add r9, r3
_0801152A:
	adds r6, 0x1
	cmp r6, 0x7
	ble _08011506
	ldr r5, _08011610
	ldr r0, [r5]
	ldr r1, _08011624
	adds r0, r1
	mov r2, r9
	str r2, [r0]
	movs r4, 0
	movs r0, 0x1
	mov r3, r10
	strb r0, [r3]
	add r0, sp, 0xC4
	strb r4, [r0, 0x1]
	movs r1, 0x12
	strb r1, [r0, 0x2]
	strb r4, [r0, 0x3]
	strh r4, [r7, 0x18]
	strh r2, [r7, 0x1A]
	mov r0, r9
	strh r0, [r7, 0x1C]
	strh r4, [r7, 0x1E]
	strh r4, [r7, 0x20]
	strh r4, [r7, 0x4]
	movs r0, 0x10
	strh r0, [r7, 0x6]
	str r4, [r7]
	strh r4, [r7, 0xC]
	strh r4, [r7, 0xE]
	strh r4, [r7, 0x14]
	strh r4, [r7, 0x16]
	movs r0, 0x8
	strh r0, [r7, 0x8]
	strh r0, [r7, 0xA]
	adds r0, r7, 0
	adds r0, 0x28
	bl sub_801317C
	movs r1, 0x1C
	ldrsh r0, [r7, r1]
	movs r1, 0
	bl sub_80095E4
	adds r1, r0, 0
	add r3, sp, 0x4
	adds r2, r3, 0
	adds r0, r1, 0x2
	strh r0, [r2, 0xE]
	strh r0, [r3, 0x10]
	lsls r1, 3
	adds r0, r7, 0
	bl sub_80137B0
	add r0, sp, 0x4
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	ldr r1, [r5]
	ldr r2, _08011628
	adds r0, r1, r2
	str r4, [r0]
	ldr r3, _0801162C
	adds r0, r1, r3
	str r4, [r0]
	adds r2, 0x8
	adds r0, r1, r2
	str r4, [r0]
	adds r3, 0x8
	adds r1, r3
	str r4, [r1]
	movs r0, 0
	bl sub_80073B8
	ldr r2, _08011630
	str r4, [sp]
	movs r0, 0x10
	movs r1, 0
	movs r3, 0
	bl sub_8014FF0
	movs r6, 0
	cmp r6, r9
	bge _08011678
	add r0, sp, 0x64
	mov r8, r0
	ldr r1, _08011634
	mov r10, r1
_080115DC:
	adds r0, r7, 0
	adds r1, r6, 0
	bl sub_8013800
	adds r4, r0, 0
	ldr r2, _08011610
	ldr r0, [r2]
	ldr r3, _08011620
	adds r0, r3
	adds r0, r6
	ldrb r5, [r0]
	ldr r0, _08011638
	adds r1, r5, 0
	bl sub_80101F8
	cmp r5, 0
	bne _08011640
	str r5, [sp]
	movs r0, 0xC
	adds r1, r4, 0
	ldr r2, _0801163C
	movs r3, 0
	bl sub_8014FF0
	b _08011672
	.align 2, 0
_08011610: .4byte gUnknown_203B0E4
_08011614: .4byte 0x00004a18
_08011618: .4byte 0x00004014
_0801161C: .4byte 0x00004dfc
_08011620: .4byte 0x00004dec
_08011624: .4byte 0x00004df8
_08011628: .4byte 0x00004ddc
_0801162C: .4byte 0x00004de0
_08011630: .4byte gUnknown_80D4104
_08011634: .4byte gUnknown_202DE30
_08011638: .4byte gUnknown_202DE58
_0801163C: .4byte gUnknown_80D4120
_08011640:
	ldr r1, _08011690
	ldr r0, [r1]
	ldr r2, _08011694
	adds r0, r2
	ldrb r2, [r0]
	adds r0, r5, 0
	mov r1, r8
	bl sub_80926F8
	mov r3, r8
	movs r1, 0x2
	ldrsh r0, [r3, r1]
	mov r2, r10
	str r0, [r2]
	movs r1, 0
	ldrsh r0, [r3, r1]
	str r0, [r2, 0x4]
	movs r0, 0
	str r0, [sp]
	movs r0, 0xC
	adds r1, r4, 0
	ldr r2, _08011698
	movs r3, 0
	bl sub_8014FF0
_08011672:
	adds r6, 0x1
	cmp r6, r9
	blt _080115DC
_08011678:
	movs r0, 0
	bl sub_80073E0
	add sp, 0xC8
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_08011690: .4byte gUnknown_203B0E4
_08011694: .4byte 0x00004a2c
_08011698: .4byte gUnknown_80D4124
	thumb_func_end sub_8011494

	thumb_func_start sub_801169C
sub_801169C:
	push {r4-r6,lr}
	sub sp, 0x8
	ldr r5, _08011744
	ldr r1, [r5]
	ldr r4, _08011748
	adds r0, r1, r4
	movs r2, 0
	ldrsh r0, [r0, r2]
	ldr r6, _0801174C
	adds r1, r6
	movs r3, 0
	ldrsh r1, [r1, r3]
	bl sub_800CCA0
	ldr r1, [r5]
	adds r4, r1, r4
	movs r2, 0
	ldrsh r0, [r4, r2]
	adds r1, r6
	movs r3, 0
	ldrsh r1, [r1, r3]
	bl sub_800CCAC
	bl sub_8010F28
	bl sub_80111C4
	lsls r0, 24
	lsrs r0, 24
	ldr r2, [r5]
	ldr r3, _08011750
	adds r1, r2, r3
	ldr r3, _08011754
	adds r2, r3
	ldr r2, [r2]
	str r2, [sp]
	movs r2, 0
	str r2, [sp, 0x4]
	movs r2, 0xB0
	movs r3, 0x10
	bl sub_8004AF0
	movs r0, 0
	movs r1, 0
	bl sub_8005838
	ldr r0, _08011758
	ldr r0, [r0]
	ldrb r0, [r0, 0xA]
	bl nullsub_8
	bl sub_8005180
	bl sub_80060EC
	ldr r0, _0801175C
	ldr r0, [r0]
	bl sub_8094FB4
	bl sub_800CB20
	bl sub_800485C
	bl CopySpritesToOam
	bl sub_8005304
	bl TransferBGPaletteBuffer
	bl xxx_call_update_bg_vram
	bl sub_8009908
	bl xxx_call_update_bg_sound_input
	bl sub_8011860
	movs r0, 0
	bl ResetSprites
	add sp, 0x8
	pop {r4-r6}
	pop {r0}
	bx r0
	.align 2, 0
_08011744: .4byte gUnknown_203B0E4
_08011748: .4byte 0x00004dd4
_0801174C: .4byte 0x00004dd6
_08011750: .4byte 0x00004c4c
_08011754: .4byte 0x00004dcc
_08011758: .4byte gUnknown_203B46C
_0801175C: .4byte gUnknown_203B47C
	thumb_func_end sub_801169C

	thumb_func_start sub_8011760
sub_8011760:
	push {lr}
	movs r0, 0xD
	bl sub_80023E4
	lsls r0, 24
	cmp r0, 0
	beq _08011776
	movs r0, 0x13
	bl sub_800BDFC
	b _08011788
_08011776:
	movs r0, 0xC
	bl sub_80023E4
	lsls r0, 24
	cmp r0, 0
	beq _08011788
	movs r0, 0x7
	bl sub_800BDFC
_08011788:
	pop {r0}
	bx r0
	thumb_func_end sub_8011760

	thumb_func_start sub_801178C
sub_801178C:
	push {lr}
	movs r0, 0xD
	bl sub_80023E4
	lsls r0, 24
	cmp r0, 0
	beq _080117A2
	movs r0, 0x13
	bl sub_800BDFC
	b _080117A8
_080117A2:
	movs r0, 0x7
	bl sub_800BDFC
_080117A8:
	pop {r0}
	bx r0
	thumb_func_end sub_801178C

	thumb_func_start sub_80117AC
sub_80117AC:
	push {lr}
	movs r0, 0xD
	bl sub_80023E4
	lsls r0, 24
	cmp r0, 0
	bne _080117C0
	movs r0, 0x1E
	bl sub_800BFD0
_080117C0:
	pop {r0}
	bx r0
	thumb_func_end sub_80117AC

	thumb_func_start sub_80117C4
sub_80117C4:
	push {lr}
	movs r0, 0x1E
	bl sub_800BFD0
	pop {r0}
	bx r0
	thumb_func_end sub_80117C4

	thumb_func_start sub_80117D0
sub_80117D0:
	push {lr}
	movs r0, 0x97
	lsls r0, 1
	movs r1, 0x80
	lsls r1, 1
	bl sub_800C074
	pop {r0}
	bx r0
	thumb_func_end sub_80117D0

	thumb_func_start sub_80117E4
sub_80117E4:
	push {lr}
	ldr r0, _080117F4
	movs r1, 0x80
	lsls r1, 1
	bl sub_800C074
	pop {r0}
	bx r0
	.align 2, 0
_080117F4: .4byte 0x0000012f
	thumb_func_end sub_80117E4

	thumb_func_start sub_80117F8
sub_80117F8:
	push {lr}
	ldr r0, _08011808
	movs r1, 0x80
	lsls r1, 1
	bl sub_800C074
	pop {r0}
	bx r0
	.align 2, 0
_08011808: .4byte 0x0000012d
	thumb_func_end sub_80117F8

	thumb_func_start sub_801180C
sub_801180C:
	ldr r0, _08011820
	movs r1, 0
	str r1, [r0]
	ldr r0, _08011824
	strh r1, [r0]
	ldr r0, _08011828
	strh r1, [r0]
	ldr r0, _0801182C
	strh r1, [r0]
	bx lr
	.align 2, 0
_08011820: .4byte gUnknown_202DE1C
_08011824: .4byte gUnknown_202DE20
_08011828: .4byte gUnknown_202DE22
_0801182C: .4byte gUnknown_202DE24
	thumb_func_end sub_801180C

	thumb_func_start sub_8011830
sub_8011830:
	push {lr}
	bl sub_800C93C
	ldr r0, _08011848
	movs r1, 0
	strh r1, [r0]
	ldr r0, _0801184C
	strh r1, [r0]
	ldr r0, _08011850
	strh r1, [r0]
	pop {r0}
	bx r0
	.align 2, 0
_08011848: .4byte gUnknown_202DE20
_0801184C: .4byte gUnknown_202DE22
_08011850: .4byte gUnknown_202DE24
	thumb_func_end sub_8011830

	thumb_func_start sub_8011854
sub_8011854:
	push {lr}
	bl sub_800C9CC
	pop {r0}
	bx r0
	thumb_func_end sub_8011854

	thumb_func_start sub_8011860
sub_8011860:
	push {lr}
	ldr r1, _08011898
	ldrh r2, [r1]
	movs r3, 0
	ldrsh r0, [r1, r3]
	cmp r0, 0
	ble _08011872
	subs r0, r2, 0x1
	strh r0, [r1]
_08011872:
	ldr r1, _0801189C
	ldrh r2, [r1]
	movs r3, 0
	ldrsh r0, [r1, r3]
	cmp r0, 0
	ble _08011882
	subs r0, r2, 0x1
	strh r0, [r1]
_08011882:
	ldr r1, _080118A0
	ldrh r2, [r1]
	movs r3, 0
	ldrsh r0, [r1, r3]
	cmp r0, 0
	ble _08011892
	subs r0, r2, 0x1
	strh r0, [r1]
_08011892:
	pop {r0}
	bx r0
	.align 2, 0
_08011898: .4byte gUnknown_202DE20
_0801189C: .4byte gUnknown_202DE22
_080118A0: .4byte gUnknown_202DE24
	thumb_func_end sub_8011860

	thumb_func_start sub_80118A4
sub_80118A4:
	push {lr}
	bl sub_8011924
	ldr r0, _080118BC
	bl sub_801199C
	ldr r0, _080118C0
	bl sub_801199C
	pop {r0}
	bx r0
	.align 2, 0
_080118BC: .4byte 0x000003e6
_080118C0: .4byte 0x000003e5
	thumb_func_end sub_80118A4

	thumb_func_start sub_80118C4
sub_80118C4:
	push {r4,lr}
	adds r4, r0, 0
	lsls r4, 16
	lsrs r4, 16
	adds r0, r4, 0
	bl sub_800BFD0
	ldr r0, _080118E8
	adds r1, r4, 0
	bl sub_800C3F8
	ldr r0, _080118EC
	adds r1, r4, 0
	bl sub_800C3F8
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080118E8: .4byte 0x000003e6
_080118EC: .4byte 0x000003e5
	thumb_func_end sub_80118C4

	thumb_func_start sub_80118F0
sub_80118F0:
	push {lr}
	lsls r0, 16
	lsrs r0, 16
	bl sub_800BDFC
	pop {r0}
	bx r0
	thumb_func_end sub_80118F0

	thumb_func_start sub_8011900
sub_8011900:
	push {lr}
	lsls r0, 16
	lsrs r0, 16
	lsls r1, 16
	lsrs r1, 16
	bl sub_800BE8C
	pop {r0}
	bx r0
	thumb_func_end sub_8011900

	thumb_func_start sub_8011914
sub_8011914:
	push {lr}
	lsls r0, 16
	lsrs r0, 16
	bl sub_800BF48
	pop {r0}
	bx r0
	thumb_func_end sub_8011914

	thumb_func_start sub_8011924
sub_8011924:
	push {lr}
	bl sub_800BF80
	pop {r0}
	bx r0
	thumb_func_end sub_8011924

	thumb_func_start sub_8011930
sub_8011930:
	push {lr}
	lsls r0, 16
	lsrs r0, 16
	bl sub_800BFD0
	pop {r0}
	bx r0
	thumb_func_end sub_8011930

	thumb_func_start sub_8011940
sub_8011940:
	push {r4,lr}
	lsls r0, 16
	lsrs r4, r0, 16
	bl sub_800C068
	lsls r0, 16
	lsrs r1, r0, 16
	ldr r0, _08011960
	cmp r4, r0
	bne _08011964
	eors r1, r4
	negs r0, r1
	orrs r0, r1
	lsrs r0, 31
	b _0801196C
	.align 2, 0
_08011960: .4byte 0x000003e7
_08011964:
	movs r0, 0
	cmp r1, r4
	bne _0801196C
	movs r0, 0x1
_0801196C:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_8011940

	thumb_func_start sub_8011974
sub_8011974:
	push {lr}
	lsls r0, 16
	lsrs r0, 16
	lsls r1, 16
	lsrs r1, 16
	bl sub_800C074
	pop {r0}
	bx r0
	thumb_func_end sub_8011974

	thumb_func_start sub_8011988
sub_8011988:
	push {lr}
	lsls r0, 16
	lsrs r0, 16
	movs r1, 0x80
	lsls r1, 1
	bl sub_800C074
	pop {r0}
	bx r0
	thumb_func_end sub_8011988

	thumb_func_start sub_801199C
sub_801199C:
	push {lr}
	lsls r0, 16
	lsrs r0, 16
	bl sub_800C298
	pop {r0}
	bx r0
	thumb_func_end sub_801199C

	thumb_func_start sub_80119AC
sub_80119AC:
	push {lr}
	lsls r0, 16
	lsrs r0, 16
	lsls r1, 16
	lsrs r1, 16
	bl sub_800C3F8
	pop {r0}
	bx r0
	thumb_func_end sub_80119AC

	thumb_func_start sub_80119C0
sub_80119C0:
	push {lr}
	lsls r0, 16
	lsrs r0, 16
	bl sub_800C5D0
	lsls r0, 24
	lsrs r0, 24
	pop {r1}
	bx r1
	thumb_func_end sub_80119C0

	thumb_func_start sub_80119D4
sub_80119D4:
	push {r4,lr}
	adds r2, r0, 0
	ldr r4, _080119FC
	movs r1, 0
	ldrsh r0, [r4, r1]
	cmp r0, 0
	bgt _080119F6
	ldr r1, _08011A00
	lsls r0, r2, 1
	adds r0, r1
	ldrh r0, [r0]
	movs r1, 0x80
	lsls r1, 1
	bl sub_800C074
	movs r0, 0x4
	strh r0, [r4]
_080119F6:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080119FC: .4byte gUnknown_202DE20
_08011A00: .4byte gUnknown_80D4144
	thumb_func_end sub_80119D4

	thumb_func_start sub_8011A04
sub_8011A04:
	push {lr}
	ldr r1, _08011A24
	movs r2, 0
	ldrsh r0, [r1, r2]
	cmp r0, 0
	bgt _08011A1E
	movs r0, 0x3
	strh r0, [r1]
	ldr r0, _08011A28
	movs r1, 0x80
	lsls r1, 1
	bl sub_800C074
_08011A1E:
	pop {r0}
	bx r0
	.align 2, 0
_08011A24: .4byte gUnknown_202DE22
_08011A28: .4byte 0x00000131
	thumb_func_end sub_8011A04

	thumb_func_start sub_8011A2C
sub_8011A2C:
	ldr r1, _08011A34
	str r0, [r1]
	bx lr
	.align 2, 0
_08011A34: .4byte gUnknown_202DE1C
	thumb_func_end sub_8011A2C

	thumb_func_start NDS_DebugInit
NDS_DebugInit:
	push {lr}
	bl nullsub_26
	bl nullsub_27
	bl nullsub_29
	bl nullsub_30
	bl nullsub_31
	bl nullsub_32
	bl nullsub_28
	ldr r1, _08011A60
	movs r0, 0x1
	str r0, [r1]
	pop {r0}
	bx r0
	.align 2, 0
_08011A60: .4byte gUnknown_203B14C
	thumb_func_end NDS_DebugInit

	thumb_func_start nullsub_25
nullsub_25:
	bx lr
	thumb_func_end nullsub_25

	thumb_func_start nullsub_26
nullsub_26:
	bx lr
	thumb_func_end nullsub_26

	thumb_func_start PrintFuncFileLineOrNotEntry
PrintFuncFileLineOrNotEntry:
	push {r4,lr}
	sub sp, 0x4
	adds r4, r0, 0
	adds r0, r1, 0
	cmp r0, 0
	beq _08011A90
	ldr r1, _08011A8C
	ldr r2, [r0, 0x8]
	ldr r3, [r0]
	ldr r0, [r0, 0x4]
	str r0, [sp]
	adds r0, r4, 0
	bl sprintf
	b _08011A98
	.align 2, 0
_08011A8C: .4byte gUnknown_80D418C
_08011A90:
	ldr r1, _08011AA0
	adds r0, r4, 0
	bl sprintf
_08011A98:
	add sp, 0x4
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08011AA0: .4byte gUnknown_80D41B0
	thumb_func_end PrintFuncFileLineOrNotEntry

	thumb_func_start PrintFuncFileLine
PrintFuncFileLine:
	push {r4,r5,lr}
	sub sp, 0x8
	ldr r5, _08011AC4
	ldr r3, [r1, 0x8]
	ldr r4, [r1]
	str r4, [sp]
	ldr r1, [r1, 0x4]
	str r1, [sp, 0x4]
	adds r1, r5, 0
	bl sprintf
	add sp, 0x8
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_08011AC4: .4byte gUnknown_80D41C4
	thumb_func_end PrintFuncFileLine

	thumb_func_start PrintMessageWithFuncFileLine
PrintMessageWithFuncFileLine:
	push {r2,r3}
	push {r4,r5,lr}
	sub sp, 0x4
	adds r4, r0, 0
	adds r5, r1, 0
	ldr r1, [sp, 0x10]
	add r2, sp, 0x14
	bl vsprintf
	adds r0, r4, 0
	bl strlen
	adds r4, r0
	ldr r1, _08011AFC
	ldr r2, [r5, 0x8]
	ldr r3, [r5]
	ldr r0, [r5, 0x4]
	str r0, [sp]
	adds r0, r4, 0
	bl sprintf
	add sp, 0x4
	pop {r4,r5}
	pop {r3}
	add sp, 0x8
	bx r3
	.align 2, 0
_08011AFC: .4byte gUnknown_80D41EC
	thumb_func_end PrintMessageWithFuncFileLine

	thumb_func_start nullsub_199
nullsub_199:
	bx lr
	thumb_func_end nullsub_199

	thumb_func_start nullsub_27
nullsub_27:
	bx lr
	thumb_func_end nullsub_27

	thumb_func_start sub_8011B08
sub_8011B08:
	ldr r1, _08011B10
	movs r0, 0x1
	strb r0, [r1]
	bx lr
	.align 2, 0
_08011B10: .4byte gUnknown_203B150
	thumb_func_end sub_8011B08

	thumb_func_start sub_8011B14
sub_8011B14:
	ldr r1, _08011B1C
	movs r0, 0
	strb r0, [r1]
	bx lr
	.align 2, 0
_08011B1C: .4byte gUnknown_203B150
	thumb_func_end sub_8011B14

	thumb_func_start sub_8011B20
sub_8011B20:
	push {lr}
	ldr r1, _08011B38
	movs r2, 0
	ldrb r0, [r1]
	cmp r0, 0
	bne _08011B2E
	movs r2, 0x1
_08011B2E:
	strb r2, [r1]
	ldrb r0, [r1]
	pop {r1}
	bx r1
	.align 2, 0
_08011B38: .4byte gUnknown_203B150
	thumb_func_end sub_8011B20

	thumb_func_start sub_8011B3C
sub_8011B3C:
	ldr r0, _08011B44
	ldrb r0, [r0]
	bx lr
	.align 2, 0
_08011B44: .4byte gUnknown_203B150
	thumb_func_end sub_8011B3C

	thumb_func_start nullsub_137
nullsub_137:
	bx lr
	thumb_func_end nullsub_137

	thumb_func_start FatalErrorPrintFuncFileLine
FatalErrorPrintFuncFileLine:
	push {lr}
	sub sp, 0x100
	adds r2, r0, 0
	cmp r2, 0
	beq _08011B5E
	mov r0, sp
	bl PrintFuncFileLine
	b _08011B66
_08011B5E:
	ldr r2, _08011B6C
	mov r0, sp
	bl PrintFuncFileLine
_08011B66:
	add sp, 0x100
	pop {r0}
	bx r0
	.align 2, 0
_08011B6C: .4byte gUnknown_80D421C
	thumb_func_end FatalErrorPrintFuncFileLine

	thumb_func_start FatalErrorFormatMessage
FatalErrorFormatMessage:
	push {r0-r3}
	push {lr}
	sub sp, 0x100
	ldr r1, [sp, 0x104]
	add r2, sp, 0x108
	mov r0, sp
	bl vsprintf
	add sp, 0x100
	pop {r3}
	add sp, 0x10
	bx r3
	thumb_func_end FatalErrorFormatMessage

	thumb_func_start sub_8011B88
sub_8011B88:
	push {r0-r3}
	push {lr}
	sub sp, 0x100
	ldr r1, [sp, 0x104]
	add r2, sp, 0x108
	mov r0, sp
	bl vsprintf
	add sp, 0x100
	pop {r3}
	add sp, 0x10
	bx r3
	thumb_func_end sub_8011B88

	thumb_func_start nullsub_28
nullsub_28:
	bx lr
	thumb_func_end nullsub_28

	thumb_func_start sub_8011BA4
sub_8011BA4:
	movs r0, 0
	bx lr
	thumb_func_end sub_8011BA4

	thumb_func_start sub_8011BA8
sub_8011BA8:
	movs r0, 0
	bx lr
	thumb_func_end sub_8011BA8

	thumb_func_start sub_8011BAC
sub_8011BAC:
	ldr r0, _08011BB0
	bx lr
	.align 2, 0
_08011BB0: .4byte gUnknown_80D4288
	thumb_func_end sub_8011BAC

	thumb_func_start sub_8011BB4
sub_8011BB4:
	push {lr}
	bl Hang
	pop {r0}
	bx r0
	thumb_func_end sub_8011BB4

	thumb_func_start Log
Log:
	push {r1-r3}
	add sp, 0xC
	bx lr
	thumb_func_end Log

	thumb_func_start sub_8011BC8
sub_8011BC8:
	push {r2,r3}
	add sp, 0x8
	bx lr
	thumb_func_end sub_8011BC8

	thumb_func_start nullsub_29
nullsub_29:
	bx lr
	thumb_func_end nullsub_29

	thumb_func_start nullsub_30
nullsub_30:
	bx lr
	thumb_func_end nullsub_30

	thumb_func_start nullsub_31
nullsub_31:
	bx lr
	thumb_func_end nullsub_31

	thumb_func_start nullsub_32
nullsub_32:
	bx lr
	thumb_func_end nullsub_32

	thumb_func_start FatalErrorHang
FatalErrorHang:
	push {lr}
	bl Hang
	pop {r0}
	bx r0
	thumb_func_end FatalErrorHang

	thumb_func_start FatalError
FatalError:
	push {r1-r3}
	push {r4,lr}
	sub sp, 0x100
	adds r1, r0, 0
	ldr r4, [sp, 0x108]
	ldr r0, _08011C14
	bl FatalErrorPrintFuncFileLine
	add r2, sp, 0x10C
	mov r0, sp
	adds r1, r4, 0
	bl vsprintf
	ldr r0, _08011C18
	mov r1, sp
	bl FatalErrorFormatMessage
	bl FatalErrorHang
	.align 2, 0
_08011C14: .4byte gUnknown_80D42C0
_08011C18: .4byte gUnknown_80D42D4
	thumb_func_end FatalError

	.align 2, 0 @ Don't pad with nop.
