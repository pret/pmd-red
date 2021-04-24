        .include "constants/gba_constants.inc"
	.include "asm/macros.inc"

	.syntax unified

	.text

	thumb_func_start sub_802D1B8
sub_802D1B8:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	ldr r4, _0802D1E0
	ldr r0, [r4]
	movs r1, 0xD4
	lsls r1, 1
	adds r0, r1
	bl sub_8006518
	ldr r0, [r4]
	ldr r0, [r0]
	cmp r0, 0xD
	beq _0802D1EA
	cmp r0, 0xD
	bgt _0802D1E4
	cmp r0, 0x2
	beq _0802D27E
	b _0802D254
	.align 2, 0
_0802D1E0: .4byte gUnknown_203B2F8
_0802D1E4:
	cmp r0, 0xE
	beq _0802D21C
	b _0802D254
_0802D1EA:
	bl sub_802D5A4
	ldr r2, [r4]
	movs r0, 0xEC
	lsls r0, 1
	adds r2, r0
	ldr r1, _0802D218
	ldm r1!, {r3,r5,r6}
	stm r2!, {r3,r5,r6}
	ldm r1!, {r3,r5,r7}
	stm r2!, {r3,r5,r7}
	ldr r1, [r4]
	adds r0, r1, r0
	movs r6, 0x8C
	lsls r6, 1
	adds r1, r6
	bl sub_8012CAC
	ldr r0, [r4]
	movs r7, 0xF2
	lsls r7, 1
	b _0802D246
	.align 2, 0
_0802D218: .4byte gUnknown_80DFE04
_0802D21C:
	bl sub_802D63C
	ldr r2, [r4]
	movs r0, 0xF8
	lsls r0, 1
	adds r2, r0
	ldr r1, _0802D250
	ldm r1!, {r3,r5,r6}
	stm r2!, {r3,r5,r6}
	ldm r1!, {r3,r5,r7}
	stm r2!, {r3,r5,r7}
	ldr r1, [r4]
	adds r0, r1, r0
	movs r6, 0xAC
	lsls r6, 1
	adds r1, r6
	bl sub_8012CAC
	ldr r0, [r4]
	movs r7, 0xFE
	lsls r7, 1
_0802D246:
	adds r0, r7
	movs r1, 0x6
	strh r1, [r0]
	b _0802D27E
	.align 2, 0
_0802D250: .4byte gUnknown_80DFE1C
_0802D254:
	ldr r0, _0802D2A0
	mov r12, r0
	movs r1, 0xD4
	lsls r1, 1
	mov r8, r1
	ldr r4, _0802D2A4
	movs r3, 0
	movs r2, 0x3
_0802D264:
	mov r5, r12
	ldr r1, [r5]
	adds r1, r3
	add r1, r8
	adds r0, r4, 0
	ldm r0!, {r5-r7}
	stm r1!, {r5-r7}
	ldm r0!, {r5-r7}
	stm r1!, {r5-r7}
	adds r3, 0x18
	subs r2, 0x1
	cmp r2, 0
	bge _0802D264
_0802D27E:
	bl ResetUnusedInputStruct
	ldr r0, _0802D2A0
	ldr r0, [r0]
	movs r6, 0xD4
	lsls r6, 1
	adds r0, r6
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_0802D2A0: .4byte gUnknown_203B2F8
_0802D2A4: .4byte gUnknown_80DFDD4
	thumb_func_end sub_802D1B8

	thumb_func_start sub_802D2A8
sub_802D2A8:
	push {r4,lr}
	sub sp, 0x14
	ldr r1, _0802D2C4
	ldr r0, [r1]
	ldr r0, [r0]
	adds r4, r1, 0
	cmp r0, 0x10
	bls _0802D2BA
	b _0802D59A
_0802D2BA:
	lsls r0, 2
	ldr r1, _0802D2C8
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0802D2C4: .4byte gUnknown_203B2F8
_0802D2C8: .4byte _0802D2CC
	.align 2, 0
_0802D2CC:
	.4byte _0802D310
	.4byte _0802D398
	.4byte _0802D59A
	.4byte _0802D3B4
	.4byte _0802D3C4
	.4byte _0802D3D4
	.4byte _0802D3E4
	.4byte _0802D3F4
	.4byte _0802D404
	.4byte _0802D498
	.4byte _0802D4C8
	.4byte _0802D4E4
	.4byte _0802D4F0
	.4byte _0802D4F8
	.4byte _0802D524
	.4byte _0802D558
	.4byte _0802D576
_0802D310:
	ldr r0, [r4]
	ldr r0, [r0, 0xC]
	bl sub_80968B0
	lsls r0, 24
	cmp r0, 0
	beq _0802D326
	movs r0, 0x3
	bl sub_802D1A0
	b _0802D59A
_0802D326:
	ldr r0, [r4]
	ldr r0, [r0, 0xC]
	bl sub_8096F50
	lsls r0, 24
	cmp r0, 0
	beq _0802D33C
	movs r0, 0x4
	bl sub_802D1A0
	b _0802D59A
_0802D33C:
	ldr r1, [r4]
	ldr r0, [r1, 0xC]
	ldrb r0, [r0, 0x2]
	cmp r0, 0x4
	bne _0802D36E
	adds r0, r1, 0
	adds r0, 0x10
	bl sub_8096C08
	lsls r0, 24
	cmp r0, 0
	beq _0802D36E
	bl sub_802DAA8
	lsls r0, 24
	cmp r0, 0
	beq _0802D366
	movs r0, 0x9
	bl sub_802D1A0
	b _0802D59A
_0802D366:
	movs r0, 0x5
	bl sub_802D1A0
	b _0802D59A
_0802D36E:
	bl sub_80969AC
	cmp r0, 0x7
	ble _0802D390
	bl sub_802DADC
	lsls r0, 24
	cmp r0, 0
	beq _0802D388
	movs r0, 0xA
	bl sub_802D1A0
	b _0802D59A
_0802D388:
	movs r0, 0x6
	bl sub_802D1A0
	b _0802D59A
_0802D390:
	movs r0, 0x8
	bl sub_802D1A0
	b _0802D59A
_0802D398:
	bl sub_802D73C
	ldr r0, _0802D3AC
	ldr r1, _0802D3B0
	ldr r3, [r1]
	ldr r2, [r3, 0x70]
	movs r1, 0xAC
	lsls r1, 1
	adds r3, r1
	b _0802D4AA
	.align 2, 0
_0802D3AC: .4byte gUnknown_80DFE4C
_0802D3B0: .4byte gUnknown_203B2F8
_0802D3B4:
	ldr r1, [r4]
	movs r0, 0x2
	str r0, [r1, 0x4]
	ldr r0, _0802D3C0
	b _0802D4D0
	.align 2, 0
_0802D3C0: .4byte gUnknown_80DFE9C
_0802D3C4:
	ldr r1, [r4]
	movs r0, 0x2
	str r0, [r1, 0x4]
	ldr r0, _0802D3D0
	b _0802D4D0
	.align 2, 0
_0802D3D0: .4byte gUnknown_80DFED0
_0802D3D4:
	ldr r1, [r4]
	movs r0, 0x2
	str r0, [r1, 0x4]
	ldr r0, _0802D3E0
	b _0802D4D0
	.align 2, 0
_0802D3E0: .4byte gUnknown_80DFF2C
_0802D3E4:
	ldr r1, [r4]
	movs r0, 0x2
	str r0, [r1, 0x4]
	ldr r0, _0802D3F0
	b _0802D4D0
	.align 2, 0
_0802D3F0: .4byte gUnknown_80DFFA4
_0802D3F4:
	ldr r1, [r4]
	movs r0, 0xC
	str r0, [r1, 0x4]
	ldr r0, _0802D400
	b _0802D4D0
	.align 2, 0
_0802D400: .4byte gUnknown_80E0010
_0802D404:
	ldr r4, _0802D45C
	ldr r1, [r4]
	movs r0, 0x1
	strb r0, [r1, 0x8]
	ldr r0, [r4]
	ldr r0, [r0, 0xC]
	bl sub_8096A78
	bl sub_8096C80
	bl sub_8096D24
	ldr r0, [r4]
	ldr r0, [r0, 0xC]
	ldrb r0, [r0, 0x2]
	cmp r0, 0x4
	bne _0802D446
	bl sub_8096DD8
	ldr r1, [r4]
	ldr r1, [r1, 0xC]
	ldr r1, [r1, 0x14]
	movs r2, 0x28
	bl MemoryCopy8
	bl sub_8096DE8
	ldr r1, [r4]
	ldr r1, [r1, 0xC]
	ldr r1, [r1, 0x18]
	movs r2, 0x78
	bl MemoryCopy8
_0802D446:
	ldr r0, [r4]
	ldr r0, [r0, 0xC]
	ldrb r0, [r0, 0x4]
	cmp r0, 0x2C
	beq _0802D46E
	cmp r0, 0x2C
	bgt _0802D460
	cmp r0, 0x2B
	beq _0802D46A
	b _0802D484
	.align 2, 0
_0802D45C: .4byte gUnknown_203B2F8
_0802D460:
	cmp r0, 0x2D
	beq _0802D472
	cmp r0, 0x2E
	beq _0802D47C
	b _0802D484
_0802D46A:
	movs r0, 0x2A
	b _0802D474
_0802D46E:
	movs r0, 0x2B
	b _0802D474
_0802D472:
	movs r0, 0x2C
_0802D474:
	movs r1, 0x1
	bl sub_8097418
	b _0802D484
_0802D47C:
	movs r0, 0x2D
	movs r1, 0x1
	bl sub_8097418
_0802D484:
	ldr r0, _0802D490
	ldr r1, [r0]
	movs r0, 0x2
	str r0, [r1, 0x4]
	ldr r0, _0802D494
	b _0802D4D0
	.align 2, 0
_0802D490: .4byte gUnknown_203B2F8
_0802D494: .4byte gUnknown_80E0074
_0802D498:
	bl sub_802D690
	ldr r0, _0802D4C0
	ldr r1, _0802D4C4
	ldr r3, [r1]
	ldr r2, [r3, 0x74]
	movs r4, 0xAC
	lsls r4, 1
	adds r3, r4
_0802D4AA:
	movs r4, 0
	str r4, [sp]
	movs r1, 0x4
	str r1, [sp, 0x4]
	str r4, [sp, 0x8]
	str r4, [sp, 0xC]
	str r4, [sp, 0x10]
	movs r1, 0
	bl sub_8014248
	b _0802D59A
	.align 2, 0
_0802D4C0: .4byte gUnknown_80E0094
_0802D4C4: .4byte gUnknown_203B2F8
_0802D4C8:
	ldr r1, [r4]
	movs r0, 0xB
	str r0, [r1, 0x4]
	ldr r0, _0802D4DC
_0802D4D0:
	ldr r3, _0802D4E0
	movs r1, 0
	movs r2, 0
	bl sub_80141B4
	b _0802D59A
	.align 2, 0
_0802D4DC: .4byte gUnknown_80E0108
_0802D4E0: .4byte 0x00000101
_0802D4E4:
	movs r0, 0
	movs r1, 0
	movs r2, 0x4
	bl sub_802C4C8
	b _0802D59A
_0802D4F0:
	movs r0, 0x1
	bl sub_802C640
	b _0802D59A
_0802D4F8:
	bl sub_802C750
	ldr r0, _0802D520
	ldr r2, [r0]
	adds r0, r2, 0
	adds r0, 0x78
	movs r3, 0x8C
	lsls r3, 1
	adds r1, r2, r3
	movs r4, 0xCC
	lsls r4, 1
	adds r3, r2, r4
	ldr r2, [r2, 0x6C]
	str r2, [sp]
	movs r2, 0x2
	str r2, [sp, 0x4]
	movs r2, 0
	bl sub_8012D60
	b _0802D59A
	.align 2, 0
_0802D520: .4byte gUnknown_203B2F8
_0802D524:
	bl sub_802C750
	ldr r4, _0802D554
	ldr r0, [r4]
	adds r0, 0x78
	movs r1, 0
	bl sub_8012EA4
	ldr r1, [r4]
	adds r0, r1, 0
	adds r0, 0xC8
	movs r2, 0xAC
	lsls r2, 1
	adds r1, r2
	movs r2, 0x4
	str r2, [sp]
	movs r2, 0x3
	str r2, [sp, 0x4]
	movs r2, 0
	movs r3, 0
	bl sub_8012D60
	b _0802D59A
	.align 2, 0
_0802D554: .4byte gUnknown_203B2F8
_0802D558:
	ldr r0, [r4]
	ldrb r0, [r0, 0x10]
	bl sub_8096AB4
	ldr r1, [r4]
	adds r1, 0x14
	bl sub_803B35C
	ldr r0, [r4]
	movs r1, 0x3
	str r1, [r0, 0x14]
	adds r0, 0x14
	bl sub_802DE84
	b _0802D59A
_0802D576:
	ldr r1, [r4]
	ldr r0, [r1, 0xC]
	adds r1, 0x14
	bl sub_803B35C
	ldr r0, [r4]
	movs r1, 0x3
	str r1, [r0, 0x14]
	adds r0, 0x58
	movs r1, 0
	strb r1, [r0]
	ldr r0, [r4]
	ldr r1, [r0, 0xC]
	ldr r1, [r1, 0x18]
	str r1, [r0, 0x64]
	adds r0, 0x14
	bl sub_802DE84
_0802D59A:
	add sp, 0x14
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_802D2A8

	thumb_func_start sub_802D5A4
sub_802D5A4:
	push {r4-r7,lr}
	ldr r4, _0802D630
	ldr r0, [r4]
	movs r5, 0xCC
	lsls r5, 1
	adds r0, r5
	movs r1, 0
	movs r2, 0x10
	bl MemoryFill16
	ldr r0, [r4]
	mov r12, r0
	movs r3, 0
	movs r1, 0x8C
	lsls r1, 1
	add r1, r12
	ldr r0, _0802D634
	ldr r0, [r0]
	str r0, [r1]
	movs r1, 0x8E
	lsls r1, 1
	add r1, r12
	movs r0, 0x2
	str r0, [r1]
	movs r2, 0x1
	movs r1, 0x90
	lsls r1, 1
	add r1, r12
	ldr r0, _0802D638
	ldr r0, [r0]
	str r0, [r1]
	movs r1, 0x92
	lsls r1, 1
	add r1, r12
	movs r0, 0x5
	str r0, [r1]
	movs r7, 0x2
	movs r0, 0x94
	lsls r0, 1
	add r0, r12
	str r3, [r0]
	movs r0, 0x96
	lsls r0, 1
	add r0, r12
	str r2, [r0]
	movs r6, 0
	movs r3, 0x8E
	lsls r3, 1
	add r3, r12
	mov r0, r12
	adds r2, r0, r5
_0802D60A:
	ldrh r0, [r2]
	cmp r0, 0
	bne _0802D61A
	ldr r1, [r3]
	mov r5, r12
	ldr r0, [r5, 0x6C]
	cmp r1, r0
	beq _0802D62A
_0802D61A:
	adds r3, 0x8
	adds r2, 0x2
	adds r6, 0x1
	cmp r6, r7
	blt _0802D60A
	ldr r1, [r4]
	movs r0, 0x2
	str r0, [r1, 0x6C]
_0802D62A:
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_0802D630: .4byte gUnknown_203B2F8
_0802D634: .4byte gUnknown_80D494C
_0802D638: .4byte gUnknown_80D4970
	thumb_func_end sub_802D5A4

	thumb_func_start sub_802D63C
sub_802D63C:
	ldr r0, _0802D684
	ldr r0, [r0]
	mov r12, r0
	movs r3, 0
	movs r1, 0xAC
	lsls r1, 1
	add r1, r12
	ldr r0, _0802D688
	ldr r0, [r0]
	str r0, [r1]
	movs r1, 0xAE
	lsls r1, 1
	add r1, r12
	movs r0, 0x3
	str r0, [r1]
	movs r2, 0x1
	movs r1, 0xB0
	lsls r1, 1
	add r1, r12
	ldr r0, _0802D68C
	ldr r0, [r0]
	str r0, [r1]
	movs r1, 0xB2
	lsls r1, 1
	add r1, r12
	movs r0, 0x4
	str r0, [r1]
	movs r0, 0xB4
	lsls r0, 1
	add r0, r12
	str r3, [r0]
	movs r0, 0xB6
	lsls r0, 1
	add r0, r12
	str r2, [r0]
	bx lr
	.align 2, 0
_0802D684: .4byte gUnknown_203B2F8
_0802D688: .4byte gUnknown_80D4920
_0802D68C: .4byte gUnknown_80D4928
	thumb_func_end sub_802D63C

	thumb_func_start sub_802D690
sub_802D690:
	push {r4,r5,lr}
	ldr r2, _0802D728
	ldr r0, [r2]
	mov r12, r0
	movs r4, 0
	movs r1, 0xAC
	lsls r1, 1
	add r1, r12
	ldr r0, _0802D72C
	ldr r0, [r0]
	str r0, [r1]
	movs r1, 0xAE
	lsls r1, 1
	add r1, r12
	movs r0, 0x3
	str r0, [r1]
	movs r3, 0x1
	movs r1, 0xB0
	lsls r1, 1
	add r1, r12
	ldr r0, _0802D730
	ldr r0, [r0]
	str r0, [r1]
	movs r1, 0xB2
	lsls r1, 1
	add r1, r12
	movs r0, 0x4
	str r0, [r1]
	movs r1, 0xB4
	lsls r1, 1
	add r1, r12
	ldr r0, _0802D734
	str r0, [r1]
	movs r1, 0xB6
	lsls r1, 1
	add r1, r12
	movs r0, 0x6
	str r0, [r1]
	movs r1, 0xB8
	lsls r1, 1
	add r1, r12
	ldr r0, _0802D738
	str r0, [r1]
	movs r1, 0xBA
	lsls r1, 1
	add r1, r12
	movs r0, 0x7
	str r0, [r1]
	movs r5, 0x4
	movs r0, 0xBC
	lsls r0, 1
	add r0, r12
	str r4, [r0]
	movs r0, 0xBE
	lsls r0, 1
	add r0, r12
	str r3, [r0]
	movs r3, 0
	mov r0, r12
	ldr r4, [r0, 0x74]
	movs r1, 0xAE
	lsls r1, 1
	add r1, r12
_0802D70E:
	ldr r0, [r1]
	cmp r0, r4
	beq _0802D722
	adds r1, 0x8
	adds r3, 0x1
	cmp r3, r5
	blt _0802D70E
	ldr r1, [r2]
	movs r0, 0x4
	str r0, [r1, 0x74]
_0802D722:
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_0802D728: .4byte gUnknown_203B2F8
_0802D72C: .4byte gUnknown_80D4920
_0802D730: .4byte gUnknown_80D4928
_0802D734: .4byte gUnknown_80E014C
_0802D738: .4byte gUnknown_80E0158
	thumb_func_end sub_802D690

	thumb_func_start sub_802D73C
sub_802D73C:
	push {r4,r5,lr}
	ldr r3, _0802D7C0
	ldr r0, [r3]
	mov r12, r0
	movs r4, 0
	movs r1, 0xAC
	lsls r1, 1
	add r1, r12
	ldr r0, _0802D7C4
	ldr r0, [r0]
	str r0, [r1]
	movs r1, 0xAE
	lsls r1, 1
	add r1, r12
	movs r0, 0x3
	str r0, [r1]
	movs r2, 0x1
	movs r1, 0xB0
	lsls r1, 1
	add r1, r12
	ldr r0, _0802D7C8
	ldr r0, [r0]
	str r0, [r1]
	movs r1, 0xB2
	lsls r1, 1
	add r1, r12
	movs r0, 0x4
	str r0, [r1]
	movs r1, 0xB4
	lsls r1, 1
	add r1, r12
	ldr r0, _0802D7CC
	str r0, [r1]
	movs r1, 0xB6
	lsls r1, 1
	add r1, r12
	movs r0, 0x6
	str r0, [r1]
	movs r5, 0x3
	movs r0, 0xB8
	lsls r0, 1
	add r0, r12
	str r4, [r0]
	movs r0, 0xBA
	lsls r0, 1
	add r0, r12
	str r2, [r0]
	movs r2, 0
	mov r0, r12
	ldr r4, [r0, 0x70]
	movs r1, 0xAE
	lsls r1, 1
	add r1, r12
_0802D7A6:
	ldr r0, [r1]
	cmp r0, r4
	beq _0802D7BA
	adds r1, 0x8
	adds r2, 0x1
	cmp r2, r5
	blt _0802D7A6
	ldr r1, [r3]
	movs r0, 0x4
	str r0, [r1, 0x70]
_0802D7BA:
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_0802D7C0: .4byte gUnknown_203B2F8
_0802D7C4: .4byte gUnknown_80D4920
_0802D7C8: .4byte gUnknown_80D4928
_0802D7CC: .4byte gUnknown_80E014C
	thumb_func_end sub_802D73C

	thumb_func_start sub_802D7D0
sub_802D7D0:
	push {lr}
	sub sp, 0x4
	mov r0, sp
	bl sub_80144A4
	cmp r0, 0
	bne _0802D826
	ldr r1, [sp]
	cmp r1, 0x1
	beq _0802D7EA
	ldr r0, _0802D800
	ldr r0, [r0]
	str r1, [r0, 0x70]
_0802D7EA:
	ldr r0, [sp]
	cmp r0, 0x3
	beq _0802D804
	cmp r0, 0x3
	ble _0802D820
	cmp r0, 0x4
	beq _0802D820
	cmp r0, 0x6
	beq _0802D80C
	b _0802D820
	.align 2, 0
_0802D800: .4byte gUnknown_203B2F8
_0802D804:
	movs r0, 0x2
	bl sub_802D1A0
	b _0802D826
_0802D80C:
	ldr r0, _0802D81C
	ldr r1, [r0]
	movs r0, 0x1
	str r0, [r1, 0x4]
	movs r0, 0x10
	bl sub_802D1A0
	b _0802D826
	.align 2, 0
_0802D81C: .4byte gUnknown_203B2F8
_0802D820:
	movs r0, 0
	bl sub_802D1A0
_0802D826:
	add sp, 0x4
	pop {r0}
	bx r0
	thumb_func_end sub_802D7D0

	thumb_func_start sub_802D82C
sub_802D82C:
	push {lr}
	sub sp, 0x4
	mov r0, sp
	bl sub_80144A4
	cmp r0, 0
	bne _0802D8C6
	ldr r1, [sp]
	cmp r1, 0x1
	beq _0802D846
	ldr r0, _0802D858
	ldr r0, [r0]
	str r1, [r0, 0x74]
_0802D846:
	ldr r0, [sp]
	subs r0, 0x1
	cmp r0, 0x6
	bhi _0802D8C0
	lsls r0, 2
	ldr r1, _0802D85C
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0802D858: .4byte gUnknown_203B2F8
_0802D85C: .4byte _0802D860
	.align 2, 0
_0802D860:
	.4byte _0802D8C0
	.4byte _0802D8C0
	.4byte _0802D87C
	.4byte _0802D8C0
	.4byte _0802D8C0
	.4byte _0802D898
	.4byte _0802D8AC
_0802D87C:
	ldr r0, _0802D894
	ldr r0, [r0]
	ldrb r0, [r0, 0x10]
	bl sub_8096C3C
	bl sub_8096C80
	movs r0, 0x8
	bl sub_802D1A0
	b _0802D8C6
	.align 2, 0
_0802D894: .4byte gUnknown_203B2F8
_0802D898:
	ldr r0, _0802D8A8
	ldr r1, [r0]
	movs r0, 0x9
	str r0, [r1, 0x4]
	movs r0, 0x10
	bl sub_802D1A0
	b _0802D8C6
	.align 2, 0
_0802D8A8: .4byte gUnknown_203B2F8
_0802D8AC:
	ldr r0, _0802D8BC
	ldr r1, [r0]
	movs r0, 0x9
	str r0, [r1, 0x4]
	movs r0, 0xF
	bl sub_802D1A0
	b _0802D8C6
	.align 2, 0
_0802D8BC: .4byte gUnknown_203B2F8
_0802D8C0:
	movs r0, 0x1
	bl sub_802D1A0
_0802D8C6:
	add sp, 0x4
	pop {r0}
	bx r0
	thumb_func_end sub_802D82C

	thumb_func_start sub_802D8CC
sub_802D8CC:
	push {lr}
	movs r0, 0x1
	bl sub_802C598
	cmp r0, 0x4
	bhi _0802D93A
	lsls r0, 2
	ldr r1, _0802D8E4
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0802D8E4: .4byte _0802D8E8
	.align 2, 0
_0802D8E8:
	.4byte _0802D93A
	.4byte _0802D93A
	.4byte _0802D930
	.4byte _0802D8FC
	.4byte _0802D914
_0802D8FC:
	bl sub_802C620
	ldr r1, _0802D910
	ldr r1, [r1]
	strb r0, [r1, 0x10]
	movs r0, 0xD
	bl sub_802D1A0
	b _0802D93A
	.align 2, 0
_0802D910: .4byte gUnknown_203B2F8
_0802D914:
	bl sub_802C620
	ldr r2, _0802D92C
	ldr r1, [r2]
	strb r0, [r1, 0x10]
	ldr r1, [r2]
	movs r0, 0xC
	str r0, [r1, 0x4]
	movs r0, 0xF
	bl sub_802D1A0
	b _0802D93A
	.align 2, 0
_0802D92C: .4byte gUnknown_203B2F8
_0802D930:
	bl sub_802C688
	movs r0, 0x1
	bl sub_802D1A0
_0802D93A:
	pop {r0}
	bx r0
	thumb_func_end sub_802D8CC

	thumb_func_start sub_802D940
sub_802D940:
	push {r4,lr}
	sub sp, 0x4
	movs r0, 0
	str r0, [sp]
	bl sub_802C598
	ldr r4, _0802D980
	ldr r0, [r4]
	adds r0, 0x78
	bl sub_8012FD8
	lsls r0, 24
	cmp r0, 0
	bne _0802D970
	ldr r0, [r4]
	adds r0, 0x78
	mov r1, sp
	bl sub_8013114
	ldr r1, [sp]
	cmp r1, 0x1
	beq _0802D970
	ldr r0, [r4]
	str r1, [r0, 0x6C]
_0802D970:
	ldr r0, [sp]
	cmp r0, 0x2
	beq _0802D98A
	cmp r0, 0x2
	bgt _0802D984
	cmp r0, 0x1
	beq _0802D9E0
	b _0802D9E6
	.align 2, 0
_0802D980: .4byte gUnknown_203B2F8
_0802D984:
	cmp r0, 0x5
	beq _0802D9CC
	b _0802D9E6
_0802D98A:
	ldr r0, _0802D9BC
	ldr r3, [r0]
	ldrb r0, [r3, 0x9]
	cmp r0, 0
	beq _0802D9C4
	ldr r2, _0802D9C0
	ldrb r1, [r3, 0x10]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 2
	adds r0, 0xF0
	ldr r1, [r2]
	adds r1, r0
	ldrb r0, [r1]
	cmp r0, 0x5
	bls _0802D9C4
	ldrb r0, [r3, 0xA]
	ldrb r1, [r1, 0x4]
	cmp r0, r1
	bne _0802D9C4
	movs r0, 0x7
	bl sub_802D1A0
	b _0802D9E6
	.align 2, 0
_0802D9BC: .4byte gUnknown_203B2F8
_0802D9C0: .4byte gUnknown_203B490
_0802D9C4:
	movs r0, 0xE
	bl sub_802D1A0
	b _0802D9E6
_0802D9CC:
	ldr r0, _0802D9DC
	ldr r1, [r0]
	movs r0, 0xC
	str r0, [r1, 0x4]
	movs r0, 0xF
	bl sub_802D1A0
	b _0802D9E6
	.align 2, 0
_0802D9DC: .4byte gUnknown_203B2F8
_0802D9E0:
	movs r0, 0xC
	bl sub_802D1A0
_0802D9E6:
	add sp, 0x4
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_802D940

	thumb_func_start sub_802D9F0
sub_802D9F0:
	push {r4,lr}
	sub sp, 0x4
	movs r0, 0
	str r0, [sp]
	bl sub_802C598
	ldr r4, _0802DA30
	ldr r0, [r4]
	adds r0, 0x78
	bl sub_8012FD8
	ldr r0, [r4]
	adds r0, 0xC8
	bl sub_8012FD8
	lsls r0, 24
	cmp r0, 0
	bne _0802DA1E
	ldr r0, [r4]
	adds r0, 0xC8
	mov r1, sp
	bl sub_8013114
_0802DA1E:
	ldr r0, [sp]
	cmp r0, 0x3
	beq _0802DA40
	cmp r0, 0x3
	bgt _0802DA34
	cmp r0, 0x1
	beq _0802DA38
	b _0802DA56
	.align 2, 0
_0802DA30: .4byte gUnknown_203B2F8
_0802DA34:
	cmp r0, 0x4
	bne _0802DA56
_0802DA38:
	movs r0, 0xC
	bl sub_802D1A0
	b _0802DA56
_0802DA40:
	bl sub_802C688
	ldr r0, [r4]
	ldrb r0, [r0, 0x10]
	bl sub_8096C3C
	bl sub_8096C80
	movs r0, 0x8
	bl sub_802D1A0
_0802DA56:
	add sp, 0x4
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_802D9F0

	thumb_func_start sub_802DA60
sub_802DA60:
	push {lr}
	bl sub_802DEE0
	cmp r0, 0x1
	bls _0802DA7C
	cmp r0, 0x3
	bhi _0802DA7C
	bl sub_802DF24
	ldr r0, _0802DA80
	ldr r0, [r0]
	ldr r0, [r0, 0x4]
	bl sub_802D1A0
_0802DA7C:
	pop {r0}
	bx r0
	.align 2, 0
_0802DA80: .4byte gUnknown_203B2F8
	thumb_func_end sub_802DA60

	thumb_func_start sub_802DA84
sub_802DA84:
	push {lr}
	sub sp, 0x4
	mov r0, sp
	bl sub_80144A4
	cmp r0, 0
	bne _0802DA9C
	ldr r0, _0802DAA4
	ldr r0, [r0]
	ldr r0, [r0, 0x4]
	bl sub_802D1A0
_0802DA9C:
	add sp, 0x4
	pop {r0}
	bx r0
	.align 2, 0
_0802DAA4: .4byte gUnknown_203B2F8
	thumb_func_end sub_802DA84

	thumb_func_start sub_802DAA8
sub_802DAA8:
	push {r4,lr}
	ldr r4, _0802DAD0
	ldr r0, [r4]
	ldrb r0, [r0, 0x10]
	bl sub_8096AB4
	adds r1, r0, 0
	ldr r4, [r4]
	ldrb r0, [r4, 0x9]
	cmp r0, 0
	beq _0802DAD4
	ldrb r0, [r1]
	cmp r0, 0x5
	beq _0802DAD4
	ldrb r0, [r4, 0xA]
	ldrb r1, [r1, 0x4]
	cmp r0, r1
	bne _0802DAD4
	movs r0, 0
	b _0802DAD6
	.align 2, 0
_0802DAD0: .4byte gUnknown_203B2F8
_0802DAD4:
	movs r0, 0x1
_0802DAD6:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_802DAA8

	thumb_func_start sub_802DADC
sub_802DADC:
	push {r4,lr}
	ldr r3, _0802DAEC
	ldr r0, [r3]
	ldrb r0, [r0, 0x9]
	cmp r0, 0
	bne _0802DAF0
_0802DAE8:
	movs r0, 0x1
	b _0802DB1C
	.align 2, 0
_0802DAEC: .4byte gUnknown_203B2F8
_0802DAF0:
	ldr r0, _0802DB24
	ldr r0, [r0]
	adds r1, r0, 0
	adds r1, 0xF0
	movs r2, 0
_0802DAFA:
	ldrb r0, [r1]
	cmp r0, 0
	beq _0802DAE8
	cmp r0, 0x5
	beq _0802DAE8
	cmp r0, 0x5
	bls _0802DB12
	ldr r0, [r3]
	ldrb r0, [r0, 0xA]
	ldrb r4, [r1, 0x4]
	cmp r0, r4
	bne _0802DAE8
_0802DB12:
	adds r1, 0x14
	adds r2, 0x1
	cmp r2, 0x7
	ble _0802DAFA
	movs r0, 0
_0802DB1C:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_0802DB24: .4byte gUnknown_203B490
	thumb_func_end sub_802DADC

	thumb_func_start sub_802DB28
sub_802DB28:
	push {r4-r6,lr}
	sub sp, 0x8
	adds r2, r1, 0
	lsls r0, 24
	lsrs r6, r0, 24
	lsls r2, 24
	lsrs r2, 24
	mov r0, sp
	adds r1, r6, 0
	bl sub_8096AF8
	mov r0, sp
	ldrb r0, [r0]
	cmp r0, 0
	bne _0802DB4A
	movs r0, 0
	b _0802DBC6
_0802DB4A:
	bl ResetUnusedInputStruct
	movs r0, 0
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	ldr r4, _0802DBD0
	movs r0, 0xA8
	movs r1, 0x8
	bl MemoryAlloc
	str r0, [r4]
	adds r0, 0x30
	movs r5, 0
	strb r6, [r0]
	adds r0, r6, 0
	bl sub_8096AB4
	ldr r1, [r4]
	str r0, [r1, 0x34]
	bl sub_8096EEC
	ldr r1, [r4]
	ldr r0, [r1, 0x34]
	adds r1, 0x8
	bl sub_803C21C
	ldr r0, [r4]
	ldr r0, [r0, 0x34]
	movs r1, 0xC
	ldrsh r0, [r0, r1]
	bl GetDialogueSpriteDataPtr
	ldr r1, [r4]
	str r0, [r1, 0x38]
	str r5, [r1, 0x3C]
	adds r1, 0x44
	strb r5, [r1]
	ldr r0, [r4]
	adds r0, 0x45
	strb r5, [r0]
	ldr r0, [r4]
	adds r0, 0x46
	strb r5, [r0]
	ldr r2, [r4]
	adds r1, r2, 0
	adds r1, 0x40
	movs r0, 0x2
	strh r0, [r1]
	adds r1, 0x2
	movs r0, 0x8
	strh r0, [r1]
	ldr r0, [r2, 0x38]
	cmp r0, 0
	beq _0802DBBE
	ldr r0, [r0, 0x4]
	str r0, [r2, 0x3C]
_0802DBBE:
	movs r0, 0
	bl sub_802DC28
	movs r0, 0x1
_0802DBC6:
	add sp, 0x8
	pop {r4-r6}
	pop {r1}
	bx r1
	.align 2, 0
_0802DBD0: .4byte gUnknown_203B2FC
	thumb_func_end sub_802DB28

	thumb_func_start sub_802DBD4
sub_802DBD4:
	push {lr}
	ldr r0, _0802DBEC
	ldr r0, [r0]
	ldr r1, [r0]
	cmp r1, 0x6
	beq _0802DBF0
	cmp r1, 0x7
	bne _0802DBF6
	ldr r0, [r0, 0x34]
	strb r1, [r0]
	movs r0, 0x3
	b _0802DBFC
	.align 2, 0
_0802DBEC: .4byte gUnknown_203B2FC
_0802DBF0:
	bl sub_802DE44
	b _0802DBFA
_0802DBF6:
	bl sub_802DE60
_0802DBFA:
	movs r0, 0
_0802DBFC:
	pop {r1}
	bx r1
	thumb_func_end sub_802DBD4

	thumb_func_start sub_802DC00
sub_802DC00:
	push {r4,lr}
	ldr r4, _0802DC24
	ldr r0, [r4]
	cmp r0, 0
	beq _0802DC1E
	ldr r0, [r0, 0x38]
	cmp r0, 0
	beq _0802DC14
	bl CloseFile
_0802DC14:
	ldr r0, [r4]
	bl MemoryFree
	movs r0, 0
	str r0, [r4]
_0802DC1E:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0802DC24: .4byte gUnknown_203B2FC
	thumb_func_end sub_802DC00

	thumb_func_start sub_802DC28
sub_802DC28:
	push {lr}
	ldr r1, _0802DC3C
	ldr r1, [r1]
	str r0, [r1]
	bl sub_802DC40
	bl sub_802DC9C
	pop {r0}
	bx r0
	.align 2, 0
_0802DC3C: .4byte gUnknown_203B2FC
	thumb_func_end sub_802DC28

	thumb_func_start sub_802DC40
sub_802DC40:
	push {r4-r7,lr}
	ldr r4, _0802DC94
	ldr r0, [r4]
	adds r0, 0x48
	bl sub_8006518
	ldr r0, [r4]
	ldr r0, [r0]
	cmp r0, 0
	beq _0802DC58
	cmp r0, 0x7
	bne _0802DC7A
_0802DC58:
	mov r12, r4
	ldr r4, _0802DC98
	movs r3, 0
	movs r2, 0x3
_0802DC60:
	mov r0, r12
	ldr r1, [r0]
	adds r1, r3
	adds r1, 0x48
	adds r0, r4, 0
	ldm r0!, {r5-r7}
	stm r1!, {r5-r7}
	ldm r0!, {r5-r7}
	stm r1!, {r5-r7}
	adds r3, 0x18
	subs r2, 0x1
	cmp r2, 0
	bge _0802DC60
_0802DC7A:
	bl ResetUnusedInputStruct
	ldr r0, _0802DC94
	ldr r0, [r0]
	adds r0, 0x48
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_0802DC94: .4byte gUnknown_203B2FC
_0802DC98: .4byte gUnknown_80E016C
	thumb_func_end sub_802DC40

	thumb_func_start sub_802DC9C
sub_802DC9C:
	push {r4,r5,lr}
	ldr r1, _0802DCB8
	ldr r0, [r1]
	ldr r0, [r0]
	adds r5, r1, 0
	cmp r0, 0x7
	bls _0802DCAC
	b _0802DE3E
_0802DCAC:
	lsls r0, 2
	ldr r1, _0802DCBC
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0802DCB8: .4byte gUnknown_203B2FC
_0802DCBC: .4byte _0802DCC0
	.align 2, 0
_0802DCC0:
	.4byte _0802DCE0
	.4byte _0802DDDC
	.4byte _0802DDE4
	.4byte _0802DDEC
	.4byte _0802DDFC
	.4byte _0802DDF4
	.4byte _0802DE34
	.4byte _0802DE3E
_0802DCE0:
	ldr r0, _0802DD60
	ldr r1, [r5]
	ldr r1, [r1, 0x34]
	movs r2, 0xC
	ldrsh r1, [r1, r2]
	bl CopyYellowSpeciesNametoBuffer
	ldr r4, _0802DD64
	ldr r0, [r5]
	ldr r0, [r0, 0x34]
	movs r2, 0xC
	ldrsh r1, [r0, r2]
	adds r0, r4, 0
	bl CopyYellowSpeciesNametoBuffer
	ldr r0, [r5]
	ldr r0, [r0, 0x34]
	movs r1, 0xC
	ldrsh r0, [r0, r1]
	bl GetMonSpecies
	adds r1, r0, 0
	ldr r2, _0802DD68
	adds r0, r4, r2
	bl strcpy
	ldr r0, [r5]
	ldr r0, [r0, 0x34]
	movs r1, 0xE
	ldrsh r0, [r0, r1]
	bl GetMonSpecies
	adds r1, r0, 0
	ldr r2, _0802DD6C
	adds r4, r2
	adds r0, r4, 0
	bl strcpy
	ldr r0, [r5]
	ldr r0, [r0, 0x34]
	movs r1, 0xC
	ldrsh r0, [r0, r1]
	bl UnlockExclusivePokemon
	ldr r0, _0802DD70
	ldr r1, [r5]
	ldr r1, [r1, 0x34]
	ldrb r1, [r1, 0x10]
	movs r2, 0
	bl sub_8090DC4
	ldr r1, [r5]
	movs r0, 0x6
	str r0, [r1, 0x4]
	ldr r0, [r1, 0x34]
	ldrb r0, [r0, 0x1]
	cmp r0, 0x4
	bhi _0802DDD4
	lsls r0, 2
	ldr r1, _0802DD74
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0802DD60: .4byte gUnknown_202E5D8
_0802DD64: .4byte gUnknown_202E1C8
_0802DD68: .4byte 0xfffffdd0
_0802DD6C: .4byte 0xfffffe20
_0802DD70: .4byte gUnknown_202DE58
_0802DD74: .4byte _0802DD78
	.align 2, 0
_0802DD78:
	.4byte _0802DDD4
	.4byte _0802DD9C
	.4byte _0802DDB8
	.4byte _0802DD94
	.4byte _0802DD8C
_0802DD8C:
	movs r0, 0x5
	bl sub_802DC28
	b _0802DE3E
_0802DD94:
	movs r0, 0x4
	bl sub_802DC28
	b _0802DE3E
_0802DD9C:
	movs r0, 0x2
	bl sub_802DC28
	ldr r0, _0802DDB4
	ldr r0, [r0]
	ldr r0, [r0, 0x34]
	movs r2, 0xE
	ldrsh r0, [r0, r2]
	bl UnlockExclusivePokemon
	b _0802DE3E
	.align 2, 0
_0802DDB4: .4byte gUnknown_203B2FC
_0802DDB8:
	movs r0, 0x3
	bl sub_802DC28
	ldr r0, _0802DDD0
	ldr r0, [r0]
	ldr r0, [r0, 0x34]
	movs r1, 0xE
	ldrsh r0, [r0, r1]
	bl UnlockExclusivePokemon
	b _0802DE3E
	.align 2, 0
_0802DDD0: .4byte gUnknown_203B2FC
_0802DDD4:
	movs r0, 0x1
	bl sub_802DC28
	b _0802DE3E
_0802DDDC:
	ldr r0, _0802DDE0
	b _0802DE1C
	.align 2, 0
_0802DDE0: .4byte gUnknown_80E0184
_0802DDE4:
	ldr r0, _0802DDE8
	b _0802DE1C
	.align 2, 0
_0802DDE8: .4byte gUnknown_80E01A0
_0802DDEC:
	ldr r0, _0802DDF0
	b _0802DE1C
	.align 2, 0
_0802DDF0: .4byte gUnknown_80E01C4
_0802DDF4:
	ldr r0, _0802DDF8
	b _0802DE1C
	.align 2, 0
_0802DDF8: .4byte gUnknown_80E01F0
_0802DDFC:
	ldr r0, [r5]
	ldr r0, [r0, 0x34]
	ldrb r0, [r0, 0x10]
	bl sub_8091130
	adds r1, r0, 0
	movs r0, 0x1
	negs r0, r0
	cmp r1, r0
	beq _0802DE1A
	adds r0, r1, 0
	bl sub_80911F8
	bl sub_80910B4
_0802DE1A:
	ldr r0, _0802DE2C
_0802DE1C:
	ldr r2, [r5]
	adds r2, 0x38
	ldr r3, _0802DE30
	movs r1, 0
	bl sub_80141B4
	b _0802DE3E
	.align 2, 0
_0802DE2C: .4byte gUnknown_80E0218
_0802DE30: .4byte 0x0000010d
_0802DE34:
	ldr r0, [r5]
	adds r0, 0x8
	movs r1, 0x1
	bl sub_802F204
_0802DE3E:
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_802DC9C

	thumb_func_start sub_802DE44
sub_802DE44:
	push {lr}
	bl sub_802F298
	cmp r0, 0x1
	bls _0802DE5C
	cmp r0, 0x3
	bhi _0802DE5C
	bl sub_802F2C0
	movs r0, 0x7
	bl sub_802DC28
_0802DE5C:
	pop {r0}
	bx r0
	thumb_func_end sub_802DE44

	thumb_func_start sub_802DE60
sub_802DE60:
	push {lr}
	sub sp, 0x4
	mov r0, sp
	bl sub_80144A4
	cmp r0, 0
	bne _0802DE78
	ldr r0, _0802DE80
	ldr r0, [r0]
	ldr r0, [r0, 0x4]
	bl sub_802DC28
_0802DE78:
	add sp, 0x4
	pop {r0}
	bx r0
	.align 2, 0
_0802DE80: .4byte gUnknown_203B2FC
	thumb_func_end sub_802DE60

	thumb_func_start sub_802DE84
sub_802DE84:
	push {r4,r5,lr}
	adds r5, r0, 0
	ldr r4, _0802DED8
	movs r0, 0x7C
	movs r1, 0x8
	bl MemoryAlloc
	str r0, [r4]
	str r5, [r0, 0xC]
	bl sub_801317C
	ldr r0, [r4]
	ldr r1, [r0, 0xC]
	ldr r2, [r1]
	str r2, [r0, 0x10]
	lsls r1, r2, 1
	adds r1, r2
	lsls r1, 3
	adds r1, 0x18
	adds r1, r0, r1
	str r1, [r0, 0x14]
	adds r0, 0x18
	bl sub_8006518
	ldr r1, [r4]
	ldr r2, [r1, 0x10]
	lsls r0, r2, 1
	adds r0, r2
	lsls r0, 3
	adds r1, r0
	adds r1, 0x18
	ldr r0, _0802DEDC
	ldm r0!, {r2-r4}
	stm r1!, {r2-r4}
	ldm r0!, {r2-r4}
	stm r1!, {r2-r4}
	bl sub_802DF14
	movs r0, 0x1
	pop {r4,r5}
	pop {r1}
	bx r1
	.align 2, 0
_0802DED8: .4byte gUnknown_203B300
_0802DEDC: .4byte gUnknown_80E0264
	thumb_func_end sub_802DE84

	thumb_func_start sub_802DEE0
sub_802DEE0:
	push {lr}
	ldr r0, _0802DF00
	ldr r0, [r0]
	ldr r1, [r0, 0x10]
	bl sub_8012A64
	cmp r0, 0x1
	beq _0802DF04
	cmp r0, 0x2
	bne _0802DF0E
	movs r0, 0x1
	bl PlayMenuSoundEffect
	movs r0, 0x2
	b _0802DF10
	.align 2, 0
_0802DF00: .4byte gUnknown_203B300
_0802DF04:
	movs r0, 0
	bl PlayMenuSoundEffect
	movs r0, 0x3
	b _0802DF10
_0802DF0E:
	movs r0, 0
_0802DF10:
	pop {r1}
	bx r1
	thumb_func_end sub_802DEE0

	thumb_func_start sub_802DF14
sub_802DF14:
	push {lr}
	bl sub_802DF6C
	bl sub_802DF88
	pop {r0}
	bx r0
	thumb_func_end sub_802DF14

	thumb_func_start sub_802DF24
sub_802DF24:
	push {r4,r5,lr}
	ldr r4, _0802DF64
	ldr r2, [r4]
	cmp r2, 0
	beq _0802DF5E
	ldr r0, [r2, 0x10]
	lsls r1, r0, 1
	adds r1, r0
	lsls r1, 3
	adds r1, r2, r1
	adds r1, 0x18
	ldr r0, _0802DF68
	ldm r0!, {r2,r3,r5}
	stm r1!, {r2,r3,r5}
	ldm r0!, {r2,r3,r5}
	stm r1!, {r2,r3,r5}
	bl ResetUnusedInputStruct
	ldr r0, [r4]
	adds r0, 0x18
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	ldr r0, [r4]
	bl MemoryFree
	movs r0, 0
	str r0, [r4]
_0802DF5E:
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_0802DF64: .4byte gUnknown_203B300
_0802DF68: .4byte gUnknown_80E0248
	thumb_func_end sub_802DF24

	thumb_func_start sub_802DF6C
sub_802DF6C:
	push {lr}
	bl ResetUnusedInputStruct
	ldr r0, _0802DF84
	ldr r0, [r0]
	adds r0, 0x18
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	pop {r0}
	bx r0
	.align 2, 0
_0802DF84: .4byte gUnknown_203B300
	thumb_func_end sub_802DF6C

	thumb_func_start sub_802DF88
sub_802DF88:
	push {r4,lr}
	ldr r4, _0802DFAC
	ldr r0, [r4]
	ldr r0, [r0, 0x10]
	bl sub_80073B8
	ldr r0, [r4]
	ldr r0, [r0, 0xC]
	bl CreateRescueDescription
	ldr r0, [r4]
	ldr r0, [r0, 0x10]
	bl sub_80073E0
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0802DFAC: .4byte gUnknown_203B300
	thumb_func_end sub_802DF88

	thumb_func_start sub_802DFB0
sub_802DFB0:
	push {r4,lr}
	ldr r4, _0802DFD4
	movs r0, 0xB6
	lsls r0, 1
	movs r1, 0x8
	bl MemoryAlloc
	str r0, [r4]
	movs r1, 0
	str r1, [r0, 0x64]
	str r1, [r0, 0x68]
	movs r0, 0
	bl sub_802E088
	movs r0, 0x1
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_0802DFD4: .4byte gUnknown_203B304
	thumb_func_end sub_802DFB0

	thumb_func_start sub_802DFD8
sub_802DFD8:
	push {lr}
	ldr r0, _0802DFF0
	ldr r0, [r0]
	ldr r0, [r0]
	cmp r0, 0xB
	bhi _0802E060
	lsls r0, 2
	ldr r1, _0802DFF4
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0802DFF0: .4byte gUnknown_203B304
_0802DFF4: .4byte _0802DFF8
	.align 2, 0
_0802DFF8:
	.4byte _0802E028
	.4byte _0802E030
	.4byte _0802E036
	.4byte _0802E060
	.4byte _0802E03C
	.4byte _0802E03C
	.4byte _0802E042
	.4byte _0802E048
	.4byte _0802E04E
	.4byte _0802E054
	.4byte _0802E054
	.4byte _0802E05A
_0802E028:
	movs r0, 0x1
	bl sub_802E088
	b _0802E064
_0802E030:
	bl sub_802E4B0
	b _0802E064
_0802E036:
	bl nullsub_133
	b _0802E064
_0802E03C:
	bl sub_802E578
	b _0802E064
_0802E042:
	bl sub_802E60C
	b _0802E064
_0802E048:
	bl sub_802E73C
	b _0802E064
_0802E04E:
	bl sub_802E758
	b _0802E064
_0802E054:
	bl sub_802E774
	b _0802E064
_0802E05A:
	bl sub_802E7D0
	b _0802E064
_0802E060:
	movs r0, 0x3
	b _0802E066
_0802E064:
	movs r0, 0
_0802E066:
	pop {r1}
	bx r1
	thumb_func_end sub_802DFD8

	thumb_func_start sub_802E06C
sub_802E06C:
	push {r4,lr}
	ldr r4, _0802E084
	ldr r0, [r4]
	cmp r0, 0
	beq _0802E07E
	bl MemoryFree
	movs r0, 0
	str r0, [r4]
_0802E07E:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0802E084: .4byte gUnknown_203B304
	thumb_func_end sub_802E06C

	thumb_func_start sub_802E088
sub_802E088:
	push {lr}
	ldr r1, _0802E09C
	ldr r1, [r1]
	str r0, [r1]
	bl sub_802E0A0
	bl sub_802E1AC
	pop {r0}
	bx r0
	.align 2, 0
_0802E09C: .4byte gUnknown_203B304
	thumb_func_end sub_802E088

	thumb_func_start sub_802E0A0
sub_802E0A0:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	ldr r4, _0802E0C8
	ldr r0, [r4]
	movs r6, 0x86
	lsls r6, 1
	adds r0, r6
	bl sub_8006518
	ldr r0, [r4]
	ldr r5, [r0]
	cmp r5, 0x1
	beq _0802E0D0
	cmp r5, 0x6
	beq _0802E124
	movs r3, 0
	ldr r2, _0802E0CC
	b _0802E168
	.align 2, 0
_0802E0C8: .4byte gUnknown_203B304
_0802E0CC: .4byte gUnknown_80E0284
_0802E0D0:
	mov r12, r6
	ldr r0, _0802E118
	mov r8, r0
	movs r2, 0
	movs r3, 0x3
_0802E0DA:
	ldr r1, [r4]
	adds r1, r2
	add r1, r12
	mov r0, r8
	ldm r0!, {r5-r7}
	stm r1!, {r5-r7}
	ldm r0!, {r5-r7}
	stm r1!, {r5-r7}
	adds r2, 0x18
	subs r3, 0x1
	cmp r3, 0
	bge _0802E0DA
	bl CreateMailboxMenu
	ldr r3, _0802E11C
	ldr r2, [r3]
	movs r0, 0x9E
	lsls r0, 1
	adds r2, r0
	ldr r1, _0802E120
	ldm r1!, {r4-r6}
	stm r2!, {r4-r6}
	ldm r1!, {r4,r5,r7}
	stm r2!, {r4,r5,r7}
	ldr r1, [r3]
	adds r0, r1, r0
	adds r1, 0xBC
	bl sub_8012CAC
	b _0802E188
	.align 2, 0
_0802E118: .4byte gUnknown_80E0284
_0802E11C: .4byte gUnknown_203B304
_0802E120: .4byte gUnknown_80E029C
_0802E124:
	bl CreateMailActionMenu
	ldr r2, [r4]
	movs r0, 0x9E
	lsls r0, 1
	adds r2, r0
	ldr r1, _0802E160
	ldm r1!, {r3,r6,r7}
	stm r2!, {r3,r6,r7}
	ldm r1!, {r3,r6,r7}
	stm r2!, {r3,r6,r7}
	ldr r1, [r4]
	adds r0, r1, r0
	adds r1, 0xBC
	bl sub_8012CAC
	ldr r1, [r4]
	movs r4, 0xA4
	lsls r4, 1
	adds r0, r1, r4
	strh r5, [r0]
	movs r5, 0xAA
	lsls r5, 1
	adds r1, r5
	ldr r0, _0802E164
	ldm r0!, {r2,r6,r7}
	stm r1!, {r2,r6,r7}
	ldm r0!, {r3-r5}
	stm r1!, {r3-r5}
	b _0802E188
	.align 2, 0
_0802E160: .4byte gUnknown_80E02B4
_0802E164: .4byte gUnknown_80E02CC
_0802E168:
	ldr r0, [r4]
	lsls r1, r3, 1
	adds r1, r3
	lsls r1, 3
	adds r0, r1
	movs r6, 0x86
	lsls r6, 1
	adds r0, r6
	adds r1, r2, 0
	ldm r1!, {r5-r7}
	stm r0!, {r5-r7}
	ldm r1!, {r5-r7}
	stm r0!, {r5-r7}
	adds r3, 0x1
	cmp r3, 0x3
	ble _0802E168
_0802E188:
	bl ResetUnusedInputStruct
	ldr r0, _0802E1A8
	ldr r0, [r0]
	movs r7, 0x86
	lsls r7, 1
	adds r0, r7
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_0802E1A8: .4byte gUnknown_203B304
	thumb_func_end sub_802E0A0

	thumb_func_start sub_802E1AC
sub_802E1AC:
	push {r4,lr}
	sub sp, 0x8
	ldr r1, _0802E1C8
	ldr r0, [r1]
	ldr r0, [r0]
	adds r4, r1, 0
	cmp r0, 0xB
	bhi _0802E2AA
	lsls r0, 2
	ldr r1, _0802E1CC
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0802E1C8: .4byte gUnknown_203B304
_0802E1CC: .4byte _0802E1D0
	.align 2, 0
_0802E1D0:
	.4byte _0802E2AA
	.4byte _0802E200
	.4byte _0802E2AA
	.4byte _0802E2AA
	.4byte _0802E21E
	.4byte _0802E22A
	.4byte _0802E232
	.4byte _0802E260
	.4byte _0802E286
	.4byte _0802E28E
	.4byte _0802E29A
	.4byte _0802E2A2
_0802E200:
	ldr r2, [r4]
	adds r0, r2, 0
	adds r0, 0x6C
	adds r1, r2, 0
	adds r1, 0xBC
	adds r3, r2, 0
	adds r3, 0xFC
	ldr r2, [r2, 0x64]
	str r2, [sp]
	movs r2, 0x2
	str r2, [sp, 0x4]
	movs r2, 0
	bl sub_8012D60
	b _0802E2AA
_0802E21E:
	movs r0, 0
	movs r1, 0
	movs r2, 0x4
	bl sub_802BD14
	b _0802E2AA
_0802E22A:
	movs r0, 0x1
	bl sub_802BE94
	b _0802E2AA
_0802E232:
	bl CreateMailMenu
	movs r0, 0x3
	bl CreateMailAcceptedStatusBox
	ldr r0, _0802E25C
	ldr r2, [r0]
	adds r0, r2, 0
	adds r0, 0x6C
	adds r1, r2, 0
	adds r1, 0xBC
	ldr r2, [r2, 0x68]
	str r2, [sp]
	movs r2, 0x2
	str r2, [sp, 0x4]
	movs r2, 0
	movs r3, 0
	bl sub_8012D60
	b _0802E2AA
	.align 2, 0
_0802E25C: .4byte gUnknown_203B304
_0802E260:
	ldr r0, [r4]
	ldrb r0, [r0, 0x8]
	bl sub_8095FE8
	ldr r1, [r4]
	adds r1, 0xC
	bl sub_803B35C
	ldr r0, [r4]
	movs r1, 0x3
	str r1, [r0, 0xC]
	adds r0, 0x50
	movs r1, 0
	strb r1, [r0]
	ldr r0, [r4]
	adds r0, 0xC
	bl sub_802DE84
	b _0802E2AA
_0802E286:
	movs r0, 0
	bl sub_802C860
	b _0802E2AA
_0802E28E:
	movs r0, 0
	movs r1, 0
	movs r2, 0x8
	bl sub_802B640
	b _0802E2AA
_0802E29A:
	movs r0, 0x1
	bl sub_802B7D0
	b _0802E2AA
_0802E2A2:
	ldr r0, [r4]
	ldrb r0, [r0, 0x9]
	bl sub_802B9FC
_0802E2AA:
	add sp, 0x8
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_802E1AC

	thumb_func_start CreateMailboxMenu
CreateMailboxMenu:
	push {r4-r7,lr}
	ldr r4, _0802E380
	ldr r0, [r4]
	adds r0, 0xFC
	movs r1, 0
	movs r2, 0x10
	bl MemoryFill16
	ldr r1, [r4]
	adds r2, r1, 0
	adds r2, 0xBC
	ldr r0, _0802E384
	str r0, [r2]
	adds r1, 0xC0
	movs r0, 0x2
	str r0, [r1]
	bl sub_802C0E8
	lsls r0, 24
	cmp r0, 0
	beq _0802E2E6
	ldr r0, [r4]
	adds r0, 0xFC
	movs r1, 0x1
	strh r1, [r0]
_0802E2E6:
	movs r5, 0x1
	ldr r1, [r4]
	movs r6, 0x1
	adds r2, r1, 0
	adds r2, 0xC4
	ldr r0, _0802E388
	str r0, [r2]
	adds r1, 0xC8
	movs r0, 0x3
	str r0, [r1]
	bl sub_802C83C
	lsls r0, 24
	cmp r0, 0
	beq _0802E30A
	ldr r0, [r4]
	adds r0, 0xFE
	strh r5, [r0]
_0802E30A:
	ldr r1, [r4]
	adds r2, r1, 0
	adds r2, 0xCC
	ldr r0, _0802E38C
	str r0, [r2]
	adds r1, 0xD0
	movs r0, 0x4
	str r0, [r1]
	bl sub_802B9D8
	lsls r0, 24
	cmp r0, 0
	beq _0802E32E
	ldr r0, [r4]
	movs r1, 0x80
	lsls r1, 1
	adds r0, r1
	strh r6, [r0]
_0802E32E:
	movs r5, 0x3
	ldr r2, [r4]
	adds r0, r2, 0
	adds r0, 0xD4
	movs r1, 0
	str r1, [r0]
	adds r0, 0x4
	str r6, [r0]
	movs r3, 0
	adds r6, r4, 0
	mov r12, r2
	mov r4, r12
	adds r4, 0xFC
	adds r2, 0xC0
_0802E34A:
	ldrh r0, [r4]
	cmp r0, 0
	bne _0802E35A
	ldr r1, [r2]
	mov r7, r12
	ldr r0, [r7, 0x64]
	cmp r1, r0
	beq _0802E3B2
_0802E35A:
	adds r4, 0x2
	adds r2, 0x8
	adds r3, 0x1
	cmp r3, r5
	blt _0802E34A
	movs r3, 0
	cmp r3, r5
	bge _0802E3B2
	ldr r1, [r6]
	adds r0, r1, 0
	adds r0, 0xFC
	ldrh r0, [r0]
	cmp r0, 0
	bne _0802E390
	adds r0, r1, 0
	adds r0, 0xC0
	ldr r0, [r0]
	str r0, [r1, 0x64]
	b _0802E3B2
	.align 2, 0
_0802E380: .4byte gUnknown_203B304
_0802E384: .4byte gMailboxCheckMail
_0802E388: .4byte gMailboxJobList
_0802E38C: .4byte gMailboxPKMNNews
_0802E390:
	adds r3, 0x1
	cmp r3, r5
	bge _0802E3B2
	ldr r2, [r6]
	lsls r0, r3, 1
	adds r1, r2, 0
	adds r1, 0xFC
	adds r1, r0
	ldrh r0, [r1]
	cmp r0, 0
	bne _0802E390
	lsls r0, r3, 3
	adds r1, r2, 0
	adds r1, 0xC0
	adds r1, r0
	ldr r0, [r1]
	str r0, [r2, 0x64]
_0802E3B2:
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end CreateMailboxMenu

	thumb_func_start CreateMailActionMenu
CreateMailActionMenu:
	push {r4-r7,lr}
	movs r5, 0
	ldr r4, _0802E3F0
	ldr r0, [r4]
	ldrb r0, [r0, 0x8]
	bl sub_8095FE8
	adds r7, r0, 0
	ldrb r0, [r7]
	cmp r0, 0x1
	bne _0802E3FC
	ldr r2, [r4]
	adds r1, r2, 0
	adds r1, 0xBC
	ldr r0, _0802E3F4
	str r0, [r1]
	adds r1, 0x4
	movs r0, 0x6
	str r0, [r1]
	adds r1, 0x4
	ldr r0, _0802E3F8
	str r0, [r1]
	adds r1, 0x4
	movs r0, 0x7
	str r0, [r1]
	movs r5, 0x2
	b _0802E44A
	.align 2, 0
_0802E3F0: .4byte gUnknown_203B304
_0802E3F4: .4byte gMailActionStore
_0802E3F8: .4byte gMailActionRead
_0802E3FC:
	ldr r1, [r4]
	adds r2, r1, 0
	adds r2, 0xBC
	ldr r0, _0802E494
	ldr r0, [r0]
	str r0, [r2]
	adds r1, 0xC0
	movs r0, 0x5
	str r0, [r1]
	adds r0, r7, 0
	bl sub_80968B0
	lsls r0, 24
	cmp r0, 0
	bne _0802E422
	bl sub_80969AC
	cmp r0, 0x7
	ble _0802E42C
_0802E422:
	ldr r0, [r4]
	adds r0, 0xC0
	movs r1, 0x1
	negs r1, r1
	str r1, [r0]
_0802E42C:
	adds r5, 0x1
	ldr r4, _0802E498
	ldr r2, [r4]
	lsls r3, r5, 3
	adds r0, r2, 0
	adds r0, 0xBC
	adds r0, r3
	ldr r1, _0802E49C
	ldr r1, [r1]
	str r1, [r0]
	adds r2, 0xC0
	adds r2, r3
	movs r0, 0x8
	str r0, [r2]
	adds r5, 0x1
_0802E44A:
	mov r12, r4
	mov r0, r12
	ldr r4, [r0]
	lsls r2, r5, 3
	adds r0, r4, 0
	adds r0, 0xBC
	adds r0, r2
	movs r1, 0
	str r1, [r0]
	adds r1, r4, 0
	adds r1, 0xC0
	adds r2, r1, r2
	movs r0, 0x1
	str r0, [r2]
	movs r3, 0
	cmp r3, r5
	bge _0802E486
	movs r6, 0x1
	negs r6, r6
	adds r2, r1, 0
_0802E472:
	ldr r1, [r2]
	cmp r1, r6
	beq _0802E47E
	ldr r0, [r4, 0x68]
	cmp r1, r0
	beq _0802E4A8
_0802E47E:
	adds r2, 0x8
	adds r3, 0x1
	cmp r3, r5
	blt _0802E472
_0802E486:
	ldrb r0, [r7]
	cmp r0, 0x1
	bne _0802E4A0
	mov r0, r12
	ldr r1, [r0]
	movs r0, 0x7
	b _0802E4A6
	.align 2, 0
_0802E494: .4byte gUnknown_80D4990
_0802E498: .4byte gUnknown_203B304
_0802E49C: .4byte gUnknown_80D4970
_0802E4A0:
	mov r0, r12
	ldr r1, [r0]
	movs r0, 0x8
_0802E4A6:
	str r0, [r1, 0x68]
_0802E4A8:
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end CreateMailActionMenu

	thumb_func_start sub_802E4B0
sub_802E4B0:
	push {r4,lr}
	sub sp, 0x4
	movs r0, 0
	str r0, [sp]
	ldr r4, _0802E4F0
	ldr r0, [r4]
	adds r0, 0x6C
	bl sub_8012FD8
	lsls r0, 24
	cmp r0, 0
	bne _0802E4DC
	ldr r0, [r4]
	adds r0, 0x6C
	mov r1, sp
	bl sub_8013114
	ldr r1, [sp]
	cmp r1, 0x1
	beq _0802E4DC
	ldr r0, [r4]
	str r1, [r0, 0x64]
_0802E4DC:
	ldr r0, [sp]
	subs r0, 0x1
	cmp r0, 0x7
	bhi _0802E56E
	lsls r0, 2
	ldr r1, _0802E4F4
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0802E4F0: .4byte gUnknown_203B304
_0802E4F4: .4byte _0802E4F8
	.align 2, 0
_0802E4F8:
	.4byte _0802E568
	.4byte _0802E518
	.4byte _0802E52A
	.4byte _0802E53C
	.4byte _0802E56E
	.4byte _0802E56E
	.4byte _0802E56E
	.4byte _0802E560
_0802E518:
	bl sub_802C0E8
	lsls r0, 24
	cmp r0, 0
	bne _0802E54E
	movs r0, 0x4
	bl sub_802E088
	b _0802E56E
_0802E52A:
	bl sub_802C83C
	lsls r0, 24
	cmp r0, 0
	bne _0802E54E
	movs r0, 0x8
	bl sub_802E088
	b _0802E56E
_0802E53C:
	bl sub_802B9D8
	lsls r0, 24
	cmp r0, 0
	bne _0802E54E
	movs r0, 0x9
	bl sub_802E088
	b _0802E56E
_0802E54E:
	ldr r0, _0802E55C
	ldr r0, [r0]
	adds r0, 0x6C
	movs r1, 0x1
	bl sub_8012EA4
	b _0802E56E
	.align 2, 0
_0802E55C: .4byte gUnknown_203B304
_0802E560:
	movs r0, 0x2
	bl sub_802E088
	b _0802E56E
_0802E568:
	movs r0, 0x3
	bl sub_802E088
_0802E56E:
	add sp, 0x4
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_802E4B0

	thumb_func_start sub_802E578
sub_802E578:
	push {r4,lr}
	movs r0, 0x1
	bl sub_802BDEC
	cmp r0, 0x4
	bhi _0802E606
	lsls r0, 2
	ldr r1, _0802E590
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0802E590: .4byte _0802E594
	.align 2, 0
_0802E594:
	.4byte _0802E606
	.4byte _0802E606
	.4byte _0802E5FC
	.4byte _0802E5A8
	.4byte _0802E5C0
_0802E5A8:
	bl sub_802BE74
	ldr r1, _0802E5BC
	ldr r1, [r1]
	strb r0, [r1, 0x8]
	movs r0, 0x6
	bl sub_802E088
	b _0802E606
	.align 2, 0
_0802E5BC: .4byte gUnknown_203B304
_0802E5C0:
	bl sub_802BE74
	ldr r4, _0802E5F0
	ldr r1, [r4]
	strb r0, [r1, 0x8]
	ldr r0, [r4]
	ldrb r0, [r0, 0x8]
	bl sub_8095FE8
	adds r2, r0, 0
	ldrb r0, [r2]
	cmp r0, 0x1
	bne _0802E5F4
	ldr r1, [r4]
	ldrb r0, [r2, 0x5]
	strb r0, [r1, 0x9]
	ldr r1, [r4]
	movs r0, 0x5
	str r0, [r1, 0x4]
	movs r0, 0xB
	bl sub_802E088
	b _0802E606
	.align 2, 0
_0802E5F0: .4byte gUnknown_203B304
_0802E5F4:
	movs r0, 0x7
	bl sub_802E088
	b _0802E606
_0802E5FC:
	bl sub_802BEDC
	movs r0, 0x1
	bl sub_802E088
_0802E606:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_802E578

	thumb_func_start sub_802E60C
sub_802E60C:
	push {r4,lr}
	sub sp, 0x4
	movs r0, 0
	str r0, [sp]
	bl sub_802BDEC
	ldr r4, _0802E650
	ldr r0, [r4]
	adds r0, 0x6C
	bl sub_8012FD8
	lsls r0, 24
	cmp r0, 0
	bne _0802E63C
	ldr r0, [r4]
	adds r0, 0x6C
	mov r1, sp
	bl sub_8013114
	ldr r1, [sp]
	cmp r1, 0x1
	beq _0802E63C
	ldr r0, [r4]
	str r1, [r0, 0x68]
_0802E63C:
	ldr r0, [sp]
	subs r0, 0x1
	cmp r0, 0x7
	bhi _0802E732
	lsls r0, 2
	ldr r1, _0802E654
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0802E650: .4byte gUnknown_203B304
_0802E654: .4byte _0802E658
	.align 2, 0
_0802E658:
	.4byte _0802E72C
	.4byte _0802E732
	.4byte _0802E732
	.4byte _0802E732
	.4byte _0802E678
	.4byte _0802E6BC
	.4byte _0802E704
	.4byte _0802E6B4
_0802E678:
	ldr r0, _0802E6AC
	bl sub_8011988
	ldr r4, _0802E6B0
	ldr r0, [r4]
	ldrb r0, [r0, 0x8]
	bl sub_8095FE8
	bl sub_8096A78
	bl sub_8096C80
	bl sub_8096D24
	ldr r0, [r4]
	ldrb r0, [r0, 0x8]
	bl sub_8096040
	bl sub_8096078
	bl sub_802C0E8
	lsls r0, 24
	cmp r0, 0
	bne _0802E6E8
	b _0802E6FC
	.align 2, 0
_0802E6AC: .4byte 0x00000133
_0802E6B0: .4byte gUnknown_203B304
_0802E6B4:
	movs r0, 0x7
	bl sub_802E088
	b _0802E732
_0802E6BC:
	ldr r0, _0802E6F4
	bl sub_8011988
	ldr r4, _0802E6F8
	ldr r0, [r4]
	ldrb r0, [r0, 0x8]
	bl sub_8095FE8
	ldrb r0, [r0, 0x5]
	bl sub_8096DF8
	ldr r0, [r4]
	ldrb r0, [r0, 0x8]
	bl sub_8096040
	bl sub_8096078
	bl sub_802C0E8
	lsls r0, 24
	cmp r0, 0
	beq _0802E6FC
_0802E6E8:
	bl sub_802BEDC
	movs r0, 0x1
	bl sub_802E088
	b _0802E732
	.align 2, 0
_0802E6F4: .4byte 0x00000133
_0802E6F8: .4byte gUnknown_203B304
_0802E6FC:
	movs r0, 0x5
	bl sub_802E088
	b _0802E732
_0802E704:
	movs r0, 0
	bl PlayMenuSoundEffect
	ldr r4, _0802E728
	ldr r0, [r4]
	ldrb r0, [r0, 0x8]
	bl sub_8095FE8
	ldr r1, [r4]
	ldrb r0, [r0, 0x5]
	strb r0, [r1, 0x9]
	ldr r1, [r4]
	movs r0, 0x5
	str r0, [r1, 0x4]
	movs r0, 0xB
	bl sub_802E088
	b _0802E732
	.align 2, 0
_0802E728: .4byte gUnknown_203B304
_0802E72C:
	movs r0, 0x5
	bl sub_802E088
_0802E732:
	add sp, 0x4
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_802E60C

	thumb_func_start sub_802E73C
sub_802E73C:
	push {lr}
	bl sub_802DEE0
	cmp r0, 0x1
	bls _0802E754
	cmp r0, 0x3
	bhi _0802E754
	bl sub_802DF24
	movs r0, 0x5
	bl sub_802E088
_0802E754:
	pop {r0}
	bx r0
	thumb_func_end sub_802E73C

	thumb_func_start sub_802E758
sub_802E758:
	push {lr}
	bl sub_802C898
	cmp r0, 0x1
	bls _0802E770
	cmp r0, 0x3
	bhi _0802E770
	bl sub_802C8F4
	movs r0, 0x1
	bl sub_802E088
_0802E770:
	pop {r0}
	bx r0
	thumb_func_end sub_802E758

	thumb_func_start sub_802E774
sub_802E774:
	push {lr}
	movs r0, 0x1
	bl sub_802B720
	cmp r0, 0x4
	bhi _0802E7CA
	lsls r0, 2
	ldr r1, _0802E78C
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0802E78C: .4byte _0802E790
	.align 2, 0
_0802E790:
	.4byte _0802E7CA
	.4byte _0802E7CA
	.4byte _0802E7C0
	.4byte _0802E7A4
	.4byte _0802E7A4
_0802E7A4:
	bl sub_802B7A8
	ldr r2, _0802E7BC
	ldr r1, [r2]
	strb r0, [r1, 0x9]
	ldr r1, [r2]
	movs r0, 0xA
	str r0, [r1, 0x4]
	movs r0, 0xB
	bl sub_802E088
	b _0802E7CA
	.align 2, 0
_0802E7BC: .4byte gUnknown_203B304
_0802E7C0:
	bl sub_802B81C
	movs r0, 0x1
	bl sub_802E088
_0802E7CA:
	pop {r0}
	bx r0
	thumb_func_end sub_802E774

	thumb_func_start sub_802E7D0
sub_802E7D0:
	push {lr}
	bl sub_802BA8C
	cmp r0, 0x1
	bls _0802E7EC
	cmp r0, 0x3
	bhi _0802E7EC
	bl sub_802BACC
	ldr r0, _0802E7F0
	ldr r0, [r0]
	ldr r0, [r0, 0x4]
	bl sub_802E088
_0802E7EC:
	pop {r0}
	bx r0
	.align 2, 0
_0802E7F0: .4byte gUnknown_203B304
	thumb_func_end sub_802E7D0

	thumb_func_start nullsub_133
nullsub_133:
	bx lr
	thumb_func_end nullsub_133

	thumb_func_start CreateMailAcceptedStatusBox
CreateMailAcceptedStatusBox:
	push {r4-r6,lr}
	sub sp, 0x8
	adds r4, r0, 0
	bl sub_8008C54
	adds r0, r4, 0
	bl sub_80073B8
	ldr r2, _0802E85C
	movs r6, 0
	str r6, [sp]
	movs r0, 0x3
	movs r1, 0
	adds r3, r4, 0
	bl xxx_call_draw_string
	bl sub_80969AC
	adds r2, r0, 0
	movs r5, 0x7
	str r5, [sp]
	str r4, [sp, 0x4]
	movs r0, 0x12
	movs r1, 0xD
	movs r3, 0x2
	bl sub_8012BC4
	ldr r2, _0802E860
	str r6, [sp]
	movs r0, 0x16
	movs r1, 0xD
	adds r3, r4, 0
	bl xxx_call_draw_string
	str r5, [sp]
	str r4, [sp, 0x4]
	movs r0, 0x23
	movs r1, 0xD
	movs r2, 0x8
	movs r3, 0x2
	bl sub_8012BC4
	adds r0, r4, 0
	bl sub_80073E0
	add sp, 0x8
	pop {r4-r6}
	pop {r0}
	bx r0
	.align 2, 0
_0802E85C: .4byte gMailAccepted
_0802E860: .4byte gUnknown_80E0324
	thumb_func_end CreateMailAcceptedStatusBox

	thumb_func_start sub_802E864
sub_802E864:
	push {r4,lr}
	ldr r4, _0802E88C
	movs r0, 0xB6
	lsls r0, 1
	movs r1, 0x8
	bl MemoryAlloc
	str r0, [r4]
	movs r1, 0
	str r1, [r0, 0x64]
	str r1, [r0, 0x68]
	str r1, [r0, 0x4]
	movs r0, 0
	bl sub_802E934
	movs r0, 0x1
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_0802E88C: .4byte gUnknown_203B308
	thumb_func_end sub_802E864

	thumb_func_start sub_802E890
sub_802E890:
	push {lr}
	ldr r0, _0802E8A8
	ldr r0, [r0]
	ldr r0, [r0]
	cmp r0, 0x8
	bhi _0802E900
	lsls r0, 2
	ldr r1, _0802E8AC
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0802E8A8: .4byte gUnknown_203B308
_0802E8AC: .4byte _0802E8B0
	.align 2, 0
_0802E8B0:
	.4byte _0802E8D4
	.4byte _0802E8DC
	.4byte _0802E8E2
	.4byte _0802E900
	.4byte _0802E8E8
	.4byte _0802E8E8
	.4byte _0802E8EE
	.4byte _0802E8F4
	.4byte _0802E8FA
_0802E8D4:
	movs r0, 0x1
	bl sub_802E934
	b _0802E904
_0802E8DC:
	bl sub_802ECB4
	b _0802E904
_0802E8E2:
	bl nullsub_134
	b _0802E904
_0802E8E8:
	bl sub_802ED4C
	b _0802E904
_0802E8EE:
	bl sub_802EDBC
	b _0802E904
_0802E8F4:
	bl sub_802EEA0
	b _0802E904
_0802E8FA:
	bl sub_802EEBC
	b _0802E904
_0802E900:
	movs r0, 0x3
	b _0802E906
_0802E904:
	movs r0, 0
_0802E906:
	pop {r1}
	bx r1
	thumb_func_end sub_802E890

	thumb_func_start sub_802E90C
sub_802E90C:
	ldr r0, _0802E914
	ldr r0, [r0]
	ldr r0, [r0, 0x4]
	bx lr
	.align 2, 0
_0802E914: .4byte gUnknown_203B308
	thumb_func_end sub_802E90C

	thumb_func_start sub_802E918
sub_802E918:
	push {r4,lr}
	ldr r4, _0802E930
	ldr r0, [r4]
	cmp r0, 0
	beq _0802E92A
	bl MemoryFree
	movs r0, 0
	str r0, [r4]
_0802E92A:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0802E930: .4byte gUnknown_203B308
	thumb_func_end sub_802E918

	thumb_func_start sub_802E934
sub_802E934:
	push {lr}
	ldr r1, _0802E948
	ldr r1, [r1]
	str r0, [r1]
	bl sub_802E94C
	bl sub_802EA58
	pop {r0}
	bx r0
	.align 2, 0
_0802E948: .4byte gUnknown_203B308
	thumb_func_end sub_802E934

	thumb_func_start sub_802E94C
sub_802E94C:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	ldr r4, _0802E974
	ldr r0, [r4]
	movs r6, 0x86
	lsls r6, 1
	adds r0, r6
	bl sub_8006518
	ldr r0, [r4]
	ldr r5, [r0]
	cmp r5, 0x1
	beq _0802E97C
	cmp r5, 0x6
	beq _0802E9D0
	movs r3, 0
	ldr r2, _0802E978
	b _0802EA14
	.align 2, 0
_0802E974: .4byte gUnknown_203B308
_0802E978: .4byte gUnknown_80E0330
_0802E97C:
	mov r12, r6
	ldr r0, _0802E9C4
	mov r8, r0
	movs r2, 0
	movs r3, 0x3
_0802E986:
	ldr r1, [r4]
	adds r1, r2
	add r1, r12
	mov r0, r8
	ldm r0!, {r5-r7}
	stm r1!, {r5-r7}
	ldm r0!, {r5-r7}
	stm r1!, {r5-r7}
	adds r2, 0x18
	subs r3, 0x1
	cmp r3, 0
	bge _0802E986
	bl CreatePelliperBoardMenu
	ldr r3, _0802E9C8
	ldr r2, [r3]
	movs r0, 0x9E
	lsls r0, 1
	adds r2, r0
	ldr r1, _0802E9CC
	ldm r1!, {r4-r6}
	stm r2!, {r4-r6}
	ldm r1!, {r4,r5,r7}
	stm r2!, {r4,r5,r7}
	ldr r1, [r3]
	adds r0, r1, r0
	adds r1, 0xBC
	bl sub_8012CAC
	b _0802EA34
	.align 2, 0
_0802E9C4: .4byte gUnknown_80E0330
_0802E9C8: .4byte gUnknown_203B308
_0802E9CC: .4byte gUnknown_80E0348
_0802E9D0:
	bl sub_802EC10
	ldr r2, [r4]
	movs r0, 0x9E
	lsls r0, 1
	adds r2, r0
	ldr r1, _0802EA0C
	ldm r1!, {r3,r6,r7}
	stm r2!, {r3,r6,r7}
	ldm r1!, {r3,r6,r7}
	stm r2!, {r3,r6,r7}
	ldr r1, [r4]
	adds r0, r1, r0
	adds r1, 0xBC
	bl sub_8012CAC
	ldr r1, [r4]
	movs r4, 0xA4
	lsls r4, 1
	adds r0, r1, r4
	strh r5, [r0]
	movs r5, 0xAA
	lsls r5, 1
	adds r1, r5
	ldr r0, _0802EA10
	ldm r0!, {r2,r6,r7}
	stm r1!, {r2,r6,r7}
	ldm r0!, {r3-r5}
	stm r1!, {r3-r5}
	b _0802EA34
	.align 2, 0
_0802EA0C: .4byte gUnknown_80E0360
_0802EA10: .4byte gUnknown_80E0378
_0802EA14:
	ldr r0, [r4]
	lsls r1, r3, 1
	adds r1, r3
	lsls r1, 3
	adds r0, r1
	movs r6, 0x86
	lsls r6, 1
	adds r0, r6
	adds r1, r2, 0
	ldm r1!, {r5-r7}
	stm r0!, {r5-r7}
	ldm r1!, {r5-r7}
	stm r0!, {r5-r7}
	adds r3, 0x1
	cmp r3, 0x3
	ble _0802EA14
_0802EA34:
	bl ResetUnusedInputStruct
	ldr r0, _0802EA54
	ldr r0, [r0]
	movs r7, 0x86
	lsls r7, 1
	adds r0, r7
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_0802EA54: .4byte gUnknown_203B308
	thumb_func_end sub_802E94C

	thumb_func_start sub_802EA58
sub_802EA58:
	push {r4,lr}
	sub sp, 0x8
	ldr r1, _0802EA74
	ldr r0, [r1]
	ldr r0, [r0]
	adds r4, r1, 0
	cmp r0, 0x8
	bhi _0802EB2C
	lsls r0, 2
	ldr r1, _0802EA78
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0802EA74: .4byte gUnknown_203B308
_0802EA78: .4byte _0802EA7C
	.align 2, 0
_0802EA7C:
	.4byte _0802EB2C
	.4byte _0802EAA0
	.4byte _0802EB2C
	.4byte _0802EB2C
	.4byte _0802EABE
	.4byte _0802EACA
	.4byte _0802EAD2
	.4byte _0802EB00
	.4byte _0802EB26
_0802EAA0:
	ldr r2, [r4]
	adds r0, r2, 0
	adds r0, 0x6C
	adds r1, r2, 0
	adds r1, 0xBC
	adds r3, r2, 0
	adds r3, 0xFC
	ldr r2, [r2, 0x64]
	str r2, [sp]
	movs r2, 0x2
	str r2, [sp, 0x4]
	movs r2, 0
	bl sub_8012D60
	b _0802EB2C
_0802EABE:
	movs r0, 0
	movs r1, 0
	movs r2, 0x4
	bl sub_802C10C
	b _0802EB2C
_0802EACA:
	movs r0, 0x1
	bl sub_802C28C
	b _0802EB2C
_0802EAD2:
	bl sub_802C39C
	movs r0, 0x3
	bl CreatePelliperAcceptedStatusBox
	ldr r0, _0802EAFC
	ldr r2, [r0]
	adds r0, r2, 0
	adds r0, 0x6C
	adds r1, r2, 0
	adds r1, 0xBC
	ldr r2, [r2, 0x68]
	str r2, [sp]
	movs r2, 0x2
	str r2, [sp, 0x4]
	movs r2, 0
	movs r3, 0
	bl sub_8012D60
	b _0802EB2C
	.align 2, 0
_0802EAFC: .4byte gUnknown_203B308
_0802EB00:
	ldr r0, [r4]
	ldrb r0, [r0, 0x8]
	bl sub_8096574
	ldr r1, [r4]
	adds r1, 0xC
	bl sub_803B35C
	ldr r0, [r4]
	movs r1, 0x3
	str r1, [r0, 0xC]
	adds r0, 0x50
	movs r1, 0
	strb r1, [r0]
	ldr r0, [r4]
	adds r0, 0xC
	bl sub_802DE84
	b _0802EB2C
_0802EB26:
	movs r0, 0
	bl sub_802C860
_0802EB2C:
	add sp, 0x8
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_802EA58

	thumb_func_start CreatePelliperBoardMenu
CreatePelliperBoardMenu:
	push {r4-r7,lr}
	ldr r4, _0802EBDC
	ldr r0, [r4]
	adds r0, 0xFC
	movs r1, 0
	movs r2, 0x10
	bl MemoryFill16
	ldr r1, [r4]
	adds r2, r1, 0
	adds r2, 0xBC
	ldr r0, _0802EBE0
	str r0, [r2]
	adds r1, 0xC0
	movs r0, 0x2
	str r0, [r1]
	bl sub_802C4A4
	lsls r0, 24
	cmp r0, 0
	beq _0802EB66
	ldr r0, [r4]
	adds r0, 0xFC
	movs r1, 0x1
	strh r1, [r0]
_0802EB66:
	movs r5, 0x1
	ldr r1, [r4]
	adds r2, r1, 0
	adds r2, 0xC4
	ldr r0, _0802EBE4
	str r0, [r2]
	adds r1, 0xC8
	movs r0, 0x3
	str r0, [r1]
	bl sub_802C83C
	lsls r0, 24
	cmp r0, 0
	beq _0802EB88
	ldr r0, [r4]
	adds r0, 0xFE
	strh r5, [r0]
_0802EB88:
	movs r5, 0x2
	ldr r2, [r4]
	adds r1, r2, 0
	adds r1, 0xCC
	movs r0, 0
	str r0, [r1]
	adds r1, 0x4
	movs r0, 0x1
	str r0, [r1]
	movs r3, 0
	adds r6, r4, 0
	mov r12, r2
	mov r4, r12
	adds r4, 0xFC
	adds r2, 0xC0
_0802EBA6:
	ldrh r0, [r4]
	cmp r0, 0
	bne _0802EBB6
	ldr r1, [r2]
	mov r7, r12
	ldr r0, [r7, 0x64]
	cmp r1, r0
	beq _0802EC0A
_0802EBB6:
	adds r4, 0x2
	adds r2, 0x8
	adds r3, 0x1
	cmp r3, r5
	blt _0802EBA6
	movs r3, 0
	cmp r3, r5
	bge _0802EC0A
	ldr r1, [r6]
	adds r0, r1, 0
	adds r0, 0xFC
	ldrh r0, [r0]
	cmp r0, 0
	bne _0802EBE8
	adds r0, r1, 0
	adds r0, 0xC0
	ldr r0, [r0]
	str r0, [r1, 0x64]
	b _0802EC0A
	.align 2, 0
_0802EBDC: .4byte gUnknown_203B308
_0802EBE0: .4byte gPelliperBoard_BulletinBoard
_0802EBE4: .4byte gPelliperBoard_JobList
_0802EBE8:
	adds r3, 0x1
	cmp r3, r5
	bge _0802EC0A
	ldr r2, [r6]
	lsls r0, r3, 1
	adds r1, r2, 0
	adds r1, 0xFC
	adds r1, r0
	ldrh r0, [r1]
	cmp r0, 0
	bne _0802EBE8
	lsls r0, r3, 3
	adds r1, r2, 0
	adds r1, 0xC0
	adds r1, r0
	ldr r0, [r1]
	str r0, [r2, 0x64]
_0802EC0A:
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end CreatePelliperBoardMenu

	thumb_func_start sub_802EC10
sub_802EC10:
	push {r4-r7,lr}
	movs r6, 0
	ldr r4, _0802ECA8
	ldr r2, [r4]
	adds r1, r2, 0
	adds r1, 0xBC
	ldr r0, _0802ECAC
	ldr r0, [r0]
	str r0, [r1]
	adds r1, 0x4
	movs r0, 0x4
	str r0, [r1]
	ldrb r0, [r2, 0x8]
	bl sub_8096574
	bl sub_80968B0
	lsls r0, 24
	cmp r0, 0
	bne _0802EC40
	bl sub_80969AC
	cmp r0, 0x7
	ble _0802EC4A
_0802EC40:
	ldr r0, [r4]
	adds r0, 0xC0
	movs r1, 0x1
	negs r1, r1
	str r1, [r0]
_0802EC4A:
	adds r6, 0x1
	ldr r4, _0802ECA8
	ldr r5, [r4]
	lsls r1, r6, 3
	adds r2, r5, 0
	adds r2, 0xBC
	adds r3, r2, r1
	ldr r0, _0802ECB0
	ldr r0, [r0]
	str r0, [r3]
	adds r3, r5, 0
	adds r3, 0xC0
	adds r1, r3, r1
	movs r0, 0x5
	str r0, [r1]
	adds r6, 0x1
	lsls r1, r6, 3
	adds r2, r1
	movs r0, 0
	str r0, [r2]
	adds r1, r3, r1
	movs r0, 0x1
	str r0, [r1]
	movs r2, 0
	adds r7, r4, 0
	cmp r2, r6
	bge _0802EC9C
	adds r4, r5, 0
	movs r5, 0x1
	negs r5, r5
	adds r1, r3, 0
_0802EC88:
	ldr r3, [r1]
	cmp r3, r5
	beq _0802EC94
	ldr r0, [r4, 0x68]
	cmp r3, r0
	beq _0802ECA2
_0802EC94:
	adds r1, 0x8
	adds r2, 0x1
	cmp r2, r6
	blt _0802EC88
_0802EC9C:
	ldr r1, [r7]
	movs r0, 0x5
	str r0, [r1, 0x68]
_0802ECA2:
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_0802ECA8: .4byte gUnknown_203B308
_0802ECAC: .4byte gUnknown_80D4990
_0802ECB0: .4byte gUnknown_80D4970
	thumb_func_end sub_802EC10

	thumb_func_start sub_802ECB4
sub_802ECB4:
	push {r4,lr}
	sub sp, 0x4
	movs r0, 0
	str r0, [sp]
	ldr r4, _0802ECF0
	ldr r0, [r4]
	adds r0, 0x6C
	bl sub_8012FD8
	lsls r0, 24
	cmp r0, 0
	bne _0802ECE0
	ldr r0, [r4]
	adds r0, 0x6C
	mov r1, sp
	bl sub_8013114
	ldr r1, [sp]
	cmp r1, 0x1
	beq _0802ECE0
	ldr r0, [r4]
	str r1, [r0, 0x64]
_0802ECE0:
	ldr r0, [sp]
	cmp r0, 0x2
	beq _0802ECFE
	cmp r0, 0x2
	bgt _0802ECF4
	cmp r0, 0x1
	beq _0802ED3C
	b _0802ED42
	.align 2, 0
_0802ECF0: .4byte gUnknown_203B308
_0802ECF4:
	cmp r0, 0x3
	beq _0802ED10
	cmp r0, 0x5
	beq _0802ED34
	b _0802ED42
_0802ECFE:
	bl sub_802C4A4
	lsls r0, 24
	cmp r0, 0
	bne _0802ED22
	movs r0, 0x4
	bl sub_802E934
	b _0802ED42
_0802ED10:
	bl sub_802C83C
	lsls r0, 24
	cmp r0, 0
	bne _0802ED22
	movs r0, 0x8
	bl sub_802E934
	b _0802ED42
_0802ED22:
	ldr r0, _0802ED30
	ldr r0, [r0]
	adds r0, 0x6C
	movs r1, 0x1
	bl sub_8012EA4
	b _0802ED42
	.align 2, 0
_0802ED30: .4byte gUnknown_203B308
_0802ED34:
	movs r0, 0x2
	bl sub_802E934
	b _0802ED42
_0802ED3C:
	movs r0, 0x3
	bl sub_802E934
_0802ED42:
	add sp, 0x4
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_802ECB4

	thumb_func_start sub_802ED4C
sub_802ED4C:
	push {lr}
	movs r0, 0x1
	bl sub_802C1E4
	cmp r0, 0x4
	bhi _0802EDB6
	lsls r0, 2
	ldr r1, _0802ED64
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0802ED64: .4byte _0802ED68
	.align 2, 0
_0802ED68:
	.4byte _0802EDB6
	.4byte _0802EDB6
	.4byte _0802EDAC
	.4byte _0802ED7C
	.4byte _0802ED94
_0802ED7C:
	bl sub_802C26C
	ldr r1, _0802ED90
	ldr r1, [r1]
	strb r0, [r1, 0x8]
	movs r0, 0x6
	bl sub_802E934
	b _0802EDB6
	.align 2, 0
_0802ED90: .4byte gUnknown_203B308
_0802ED94:
	bl sub_802C26C
	ldr r1, _0802EDA8
	ldr r1, [r1]
	strb r0, [r1, 0x8]
	movs r0, 0x7
	bl sub_802E934
	b _0802EDB6
	.align 2, 0
_0802EDA8: .4byte gUnknown_203B308
_0802EDAC:
	bl sub_802C2D4
	movs r0, 0x1
	bl sub_802E934
_0802EDB6:
	pop {r0}
	bx r0
	thumb_func_end sub_802ED4C

	thumb_func_start sub_802EDBC
sub_802EDBC:
	push {r4,lr}
	sub sp, 0x4
	movs r0, 0
	str r0, [sp]
	bl sub_802C1E4
	ldr r4, _0802EDFC
	ldr r0, [r4]
	adds r0, 0x6C
	bl sub_8012FD8
	lsls r0, 24
	cmp r0, 0
	bne _0802EDEC
	ldr r0, [r4]
	adds r0, 0x6C
	mov r1, sp
	bl sub_8013114
	ldr r1, [sp]
	cmp r1, 0x1
	beq _0802EDEC
	ldr r0, [r4]
	str r1, [r0, 0x68]
_0802EDEC:
	ldr r0, [sp]
	cmp r0, 0x4
	beq _0802EE06
	cmp r0, 0x4
	bgt _0802EE00
	cmp r0, 0x1
	beq _0802EE90
	b _0802EE96
	.align 2, 0
_0802EDFC: .4byte gUnknown_203B308
_0802EE00:
	cmp r0, 0x5
	beq _0802EE88
	b _0802EE96
_0802EE06:
	ldr r0, _0802EE28
	bl sub_8011988
	ldr r4, _0802EE2C
	ldr r0, [r4]
	ldrb r0, [r0, 0x8]
	bl sub_8096574
	ldrb r1, [r0]
	cmp r1, 0x3
	beq _0802EE3C
	cmp r1, 0x3
	bgt _0802EE30
	cmp r1, 0x2
	beq _0802EE36
	b _0802EE5E
	.align 2, 0
_0802EE28: .4byte 0x00000133
_0802EE2C: .4byte gUnknown_203B308
_0802EE30:
	cmp r1, 0x4
	beq _0802EE42
	b _0802EE5E
_0802EE36:
	ldr r0, [r4]
	movs r1, 0x1
	b _0802EE46
_0802EE3C:
	ldr r0, [r4]
	movs r1, 0x2
	b _0802EE46
_0802EE42:
	ldr r0, [r4]
	movs r1, 0x3
_0802EE46:
	str r1, [r0, 0x4]
	ldrb r0, [r0, 0x8]
	bl sub_80965B8
	bl sub_80965F4
	bl sub_802C2D4
	movs r0, 0x3
	bl sub_802E934
	b _0802EE96
_0802EE5E:
	bl sub_8096A78
	bl sub_8096C80
	bl sub_8096D24
	bl sub_802C4A4
	lsls r0, 24
	cmp r0, 0
	beq _0802EE80
	bl sub_802C2D4
	movs r0, 0x1
	bl sub_802E934
	b _0802EE96
_0802EE80:
	movs r0, 0x5
	bl sub_802E934
	b _0802EE96
_0802EE88:
	movs r0, 0x7
	bl sub_802E934
	b _0802EE96
_0802EE90:
	movs r0, 0x5
	bl sub_802E934
_0802EE96:
	add sp, 0x4
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_802EDBC

	thumb_func_start sub_802EEA0
sub_802EEA0:
	push {lr}
	bl sub_802DEE0
	cmp r0, 0x1
	bls _0802EEB8
	cmp r0, 0x3
	bhi _0802EEB8
	bl sub_802DF24
	movs r0, 0x5
	bl sub_802E934
_0802EEB8:
	pop {r0}
	bx r0
	thumb_func_end sub_802EEA0

	thumb_func_start sub_802EEBC
sub_802EEBC:
	push {lr}
	bl sub_802C898
	cmp r0, 0x1
	bls _0802EED4
	cmp r0, 0x3
	bhi _0802EED4
	bl sub_802C8F4
	movs r0, 0x1
	bl sub_802E934
_0802EED4:
	pop {r0}
	bx r0
	thumb_func_end sub_802EEBC

	thumb_func_start nullsub_134
nullsub_134:
	bx lr
	thumb_func_end nullsub_134

	thumb_func_start CreatePelliperAccepedStatusBox
CreatePelliperAcceptedStatusBox:
	push {r4-r6,lr}
	sub sp, 0x8
	adds r4, r0, 0
	bl sub_8008C54
	adds r0, r4, 0
	bl sub_80073B8
	ldr r2, _0802EF40
	movs r6, 0
	str r6, [sp]
	movs r0, 0x3
	movs r1, 0
	adds r3, r4, 0
	bl xxx_call_draw_string
	bl sub_80969AC
	adds r2, r0, 0
	movs r5, 0x7
	str r5, [sp]
	str r4, [sp, 0x4]
	movs r0, 0x12
	movs r1, 0xD
	movs r3, 0x2
	bl sub_8012BC4
	ldr r2, _0802EF44
	str r6, [sp]
	movs r0, 0x16
	movs r1, 0xD
	adds r3, r4, 0
	bl xxx_call_draw_string
	str r5, [sp]
	str r4, [sp, 0x4]
	movs r0, 0x23
	movs r1, 0xD
	movs r2, 0x8
	movs r3, 0x2
	bl sub_8012BC4
	adds r0, r4, 0
	bl sub_80073E0
	add sp, 0x8
	pop {r4-r6}
	pop {r0}
	bx r0
	.align 2, 0
_0802EF40: .4byte gUnknown_80E03AC
_0802EF44: .4byte gUnknown_80E03B8
	thumb_func_end CreatePelliperAcceptedStatusBox

	thumb_func_start sub_802EF48
sub_802EF48:
	push {r4,lr}
	ldr r4, _0802EF68
	movs r0, 0xA8
	lsls r0, 1
	movs r1, 0x8
	bl MemoryAlloc
	str r0, [r4]
	movs r0, 0
	bl sub_802EFEC
	movs r0, 0x1
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_0802EF68: .4byte gUnknown_203B30C
	thumb_func_end sub_802EF48

	thumb_func_start sub_802EF6C
sub_802EF6C:
	push {lr}
	ldr r0, _0802EF84
	ldr r0, [r0]
	ldr r0, [r0]
	cmp r0, 0x5
	bhi _0802EFBA
	lsls r0, 2
	ldr r1, _0802EF88
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0802EF84: .4byte gUnknown_203B30C
_0802EF88: .4byte _0802EF8C
	.align 2, 0
_0802EF8C:
	.4byte _0802EFA4
	.4byte _0802EFA4
	.4byte _0802EFAA
	.4byte _0802EFB0
	.4byte _0802EFB6
	.4byte _0802EFBA
_0802EFA4:
	bl sub_802F148
	b _0802EFBE
_0802EFAA:
	bl sub_802F184
	b _0802EFBE
_0802EFB0:
	bl sub_802F1E8
	b _0802EFBE
_0802EFB6:
	movs r0, 0x3
	b _0802EFC0
_0802EFBA:
	movs r0, 0x2
	b _0802EFC0
_0802EFBE:
	movs r0, 0
_0802EFC0:
	pop {r1}
	bx r1
	thumb_func_end sub_802EF6C

	thumb_func_start sub_802EFC4
sub_802EFC4:
	ldr r0, _0802EFCC
	ldr r0, [r0]
	ldrb r0, [r0, 0x4]
	bx lr
	.align 2, 0
_0802EFCC: .4byte gUnknown_203B30C
	thumb_func_end sub_802EFC4

	thumb_func_start sub_802EFD0
sub_802EFD0:
	push {r4,lr}
	ldr r4, _0802EFE8
	ldr r0, [r4]
	cmp r0, 0
	beq _0802EFE2
	bl MemoryFree
	movs r0, 0
	str r0, [r4]
_0802EFE2:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0802EFE8: .4byte gUnknown_203B30C
	thumb_func_end sub_802EFD0

	thumb_func_start sub_802EFEC
sub_802EFEC:
	push {lr}
	ldr r1, _0802F000
	ldr r1, [r1]
	str r0, [r1]
	bl sub_802F004
	bl sub_802F088
	pop {r0}
	bx r0
	.align 2, 0
_0802F000: .4byte gUnknown_203B30C
	thumb_func_end sub_802EFEC

	thumb_func_start sub_802F004
sub_802F004:
	push {r4-r7,lr}
	ldr r4, _0802F03C
	ldr r0, [r4]
	adds r0, 0xF0
	bl sub_8006518
	ldr r0, [r4]
	ldr r0, [r0]
	cmp r0, 0x2
	bne _0802F044
	bl sub_802F108
	ldr r2, [r4]
	movs r0, 0x90
	lsls r0, 1
	adds r2, r0
	ldr r1, _0802F040
	ldm r1!, {r3,r5,r6}
	stm r2!, {r3,r5,r6}
	ldm r1!, {r3,r5,r7}
	stm r2!, {r3,r5,r7}
	ldr r1, [r4]
	adds r0, r1, r0
	adds r1, 0xB0
	bl sub_8012CAC
	b _0802F066
	.align 2, 0
_0802F03C: .4byte gUnknown_203B30C
_0802F040: .4byte gUnknown_80E03F4
_0802F044:
	mov r12, r4
	ldr r4, _0802F080
	movs r2, 0
	movs r3, 0x3
_0802F04C:
	mov r6, r12
	ldr r1, [r6]
	adds r1, r2
	adds r1, 0xF0
	adds r0, r4, 0
	ldm r0!, {r5-r7}
	stm r1!, {r5-r7}
	ldm r0!, {r5-r7}
	stm r1!, {r5-r7}
	adds r2, 0x18
	subs r3, 0x1
	cmp r3, 0
	bge _0802F04C
_0802F066:
	bl ResetUnusedInputStruct
	ldr r0, _0802F084
	ldr r0, [r0]
	adds r0, 0xF0
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_0802F080: .4byte gUnknown_80E03C4
_0802F084: .4byte gUnknown_203B30C
	thumb_func_end sub_802F004

	thumb_func_start sub_802F088
sub_802F088:
	push {r4-r6,lr}
	sub sp, 0x8
	ldr r6, _0802F0A0
	ldr r0, [r6]
	ldr r5, [r0]
	cmp r5, 0x1
	beq _0802F0B6
	cmp r5, 0x1
	bgt _0802F0A4
	cmp r5, 0
	beq _0802F0AE
	b _0802F100
	.align 2, 0
_0802F0A0: .4byte gUnknown_203B30C
_0802F0A4:
	cmp r5, 0x2
	beq _0802F0BE
	cmp r5, 0x3
	beq _0802F0DA
	b _0802F100
_0802F0AE:
	movs r0, 0
	bl sub_802CDD4
	b _0802F100
_0802F0B6:
	movs r0, 0x1
	bl sub_802CED8
	b _0802F100
_0802F0BE:
	bl sub_802CFD0
	ldr r1, [r6]
	adds r0, r1, 0
	adds r0, 0x60
	adds r1, 0xB0
	movs r2, 0x3
	str r2, [sp]
	str r5, [sp, 0x4]
	movs r2, 0
	movs r3, 0
	bl sub_8012D60
	b _0802F100
_0802F0DA:
	ldrb r0, [r0, 0x4]
	bl sub_803B344
	adds r4, r0, 0
	ldr r1, [r6]
	adds r1, 0x8
	bl sub_803B35C
	ldr r0, [r6]
	str r5, [r0, 0x8]
	adds r0, 0x4C
	movs r1, 0
	strb r1, [r0]
	ldr r0, [r6]
	ldr r1, [r4, 0x18]
	str r1, [r0, 0x58]
	adds r0, 0x8
	bl sub_802DE84
_0802F100:
	add sp, 0x8
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end sub_802F088

	thumb_func_start sub_802F108
sub_802F108:
	ldr r0, _0802F13C
	ldr r0, [r0]
	mov r12, r0
	movs r3, 0
	mov r1, r12
	adds r1, 0xB0
	ldr r0, _0802F140
	str r0, [r1]
	adds r1, 0x4
	movs r0, 0x2
	str r0, [r1]
	movs r2, 0x1
	adds r1, 0x4
	ldr r0, _0802F144
	ldr r0, [r0]
	str r0, [r1]
	adds r1, 0x4
	movs r0, 0x3
	str r0, [r1]
	mov r0, r12
	adds r0, 0xC0
	str r3, [r0]
	adds r0, 0x4
	str r2, [r0]
	bx lr
	.align 2, 0
_0802F13C: .4byte gUnknown_203B30C
_0802F140: .4byte gUnknown_80E040C
_0802F144: .4byte gUnknown_80D4970
	thumb_func_end sub_802F108

	thumb_func_start sub_802F148
sub_802F148:
	push {lr}
	movs r0, 0x1
	bl sub_802CE5C
	cmp r0, 0x2
	beq _0802F174
	cmp r0, 0x2
	bcc _0802F17E
	cmp r0, 0x3
	bne _0802F17E
	bl sub_802CEBC
	ldr r1, _0802F170
	ldr r1, [r1]
	strb r0, [r1, 0x4]
	movs r0, 0x2
	bl sub_802EFEC
	b _0802F17E
	.align 2, 0
_0802F170: .4byte gUnknown_203B30C
_0802F174:
	bl sub_802CF14
	movs r0, 0x5
	bl sub_802EFEC
_0802F17E:
	pop {r0}
	bx r0
	thumb_func_end sub_802F148

	thumb_func_start sub_802F184
sub_802F184:
	push {r4,lr}
	sub sp, 0x4
	movs r0, 0
	str r0, [sp]
	bl sub_802CE5C
	ldr r4, _0802F1BC
	ldr r0, [r4]
	adds r0, 0x60
	bl sub_8012FD8
	lsls r0, 24
	cmp r0, 0
	bne _0802F1AA
	ldr r0, [r4]
	adds r0, 0x60
	mov r1, sp
	bl sub_8013114
_0802F1AA:
	ldr r0, [sp]
	cmp r0, 0x2
	beq _0802F1C6
	cmp r0, 0x2
	bgt _0802F1C0
	cmp r0, 0x1
	beq _0802F1DA
	b _0802F1E0
	.align 2, 0
_0802F1BC: .4byte gUnknown_203B30C
_0802F1C0:
	cmp r0, 0x3
	beq _0802F1D2
	b _0802F1E0
_0802F1C6:
	bl sub_802CF14
	movs r0, 0x4
	bl sub_802EFEC
	b _0802F1E0
_0802F1D2:
	movs r0, 0x3
	bl sub_802EFEC
	b _0802F1E0
_0802F1DA:
	movs r0, 0x1
	bl sub_802EFEC
_0802F1E0:
	add sp, 0x4
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_802F184

	thumb_func_start sub_802F1E8
sub_802F1E8:
	push {lr}
	bl sub_802DEE0
	cmp r0, 0x1
	bls _0802F200
	cmp r0, 0x3
	bhi _0802F200
	bl sub_802DF24
	movs r0, 0x1
	bl sub_802EFEC
_0802F200:
	pop {r0}
	bx r0
	thumb_func_end sub_802F1E8

	thumb_func_start sub_802F204
sub_802F204:
	push {r4-r6,lr}
	adds r6, r0, 0
	lsls r4, r1, 24
	lsrs r4, 24
	bl ResetUnusedInputStruct
	movs r0, 0
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	ldr r5, _0802F28C
	movs r0, 0x84
	movs r1, 0x8
	bl MemoryAlloc
	str r0, [r5]
	str r6, [r0, 0x10]
	movs r6, 0
	str r6, [r0, 0xC]
	strb r4, [r0, 0x8]
	ldr r1, [r5]
	ldr r0, _0802F290
	ldr r1, [r1, 0x10]
	bl strcpy
	ldr r4, _0802F294
	bl sub_808D33C
	adds r1, r0, 0
	adds r0, r4, 0
	bl sub_808DA34
	ldr r0, [r5]
	ldr r0, [r0, 0x10]
	movs r1, 0x14
	ldrsh r0, [r0, r1]
	bl GetDialogueSpriteDataPtr
	ldr r1, [r5]
	str r0, [r1, 0x14]
	str r6, [r1, 0x18]
	adds r1, 0x20
	strb r6, [r1]
	ldr r0, [r5]
	adds r0, 0x21
	strb r6, [r0]
	ldr r0, [r5]
	adds r0, 0x22
	strb r6, [r0]
	ldr r5, [r5]
	movs r0, 0x2
	strh r0, [r5, 0x1C]
	movs r0, 0x8
	strh r0, [r5, 0x1E]
	ldr r0, [r5, 0x14]
	cmp r0, 0
	beq _0802F27C
	ldr r0, [r0, 0x4]
	str r0, [r5, 0x18]
_0802F27C:
	movs r0, 0
	bl sub_802F2E8
	movs r0, 0x1
	pop {r4-r6}
	pop {r1}
	bx r1
	.align 2, 0
_0802F28C: .4byte gUnknown_203B310
_0802F290: .4byte gUnknown_202E5D8
_0802F294: .4byte gAvailablePokemonNames
	thumb_func_end sub_802F204

	thumb_func_start sub_802F298
sub_802F298:
	push {lr}
	ldr r0, _0802F2AC
	ldr r0, [r0]
	ldr r0, [r0]
	cmp r0, 0x5
	beq _0802F2B0
	cmp r0, 0x9
	bne _0802F2B6
	movs r0, 0x3
	b _0802F2BC
	.align 2, 0
_0802F2AC: .4byte gUnknown_203B310
_0802F2B0:
	bl sub_802F6FC
	b _0802F2BA
_0802F2B6:
	bl sub_802F718
_0802F2BA:
	movs r0, 0
_0802F2BC:
	pop {r1}
	bx r1
	thumb_func_end sub_802F298

	thumb_func_start sub_802F2C0
sub_802F2C0:
	push {r4,lr}
	ldr r4, _0802F2E4
	ldr r0, [r4]
	cmp r0, 0
	beq _0802F2DE
	ldr r0, [r0, 0x14]
	cmp r0, 0
	beq _0802F2D4
	bl CloseFile
_0802F2D4:
	ldr r0, [r4]
	bl MemoryFree
	movs r0, 0
	str r0, [r4]
_0802F2DE:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0802F2E4: .4byte gUnknown_203B310
	thumb_func_end sub_802F2C0

	thumb_func_start sub_802F2E8
sub_802F2E8:
	push {lr}
	ldr r1, _0802F2FC
	ldr r1, [r1]
	str r0, [r1]
	bl sub_802F300
	bl HandleMissionReward
	pop {r0}
	bx r0
	.align 2, 0
_0802F2FC: .4byte gUnknown_203B310
	thumb_func_end sub_802F2E8

	thumb_func_start sub_802F300
sub_802F300:
	push {r4-r7,lr}
	ldr r4, _0802F350
	ldr r1, [r4]
	ldr r0, [r1]
	cmp r0, 0
	bne _0802F348
	adds r0, r1, 0
	adds r0, 0x24
	bl sub_8006518
	mov r12, r4
	ldr r4, _0802F354
	movs r3, 0
	movs r2, 0x3
_0802F31C:
	mov r0, r12
	ldr r1, [r0]
	adds r1, r3
	adds r1, 0x24
	adds r0, r4, 0
	ldm r0!, {r5-r7}
	stm r1!, {r5-r7}
	ldm r0!, {r5-r7}
	stm r1!, {r5-r7}
	adds r3, 0x18
	subs r2, 0x1
	cmp r2, 0
	bge _0802F31C
	bl ResetUnusedInputStruct
	ldr r0, _0802F350
	ldr r0, [r0]
	adds r0, 0x24
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
_0802F348:
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_0802F350: .4byte gUnknown_203B310
_0802F354: .4byte gUnknown_80E041C
	thumb_func_end sub_802F300

	thumb_func_start HandleMissionReward
HandleMissionReward:
	push {r4-r6,lr}
	sub sp, 0x10
	ldr r1, _0802F374
	ldr r0, [r1]
	ldr r0, [r0]
	adds r6, r1, 0
	cmp r0, 0x9
	bls _0802F36A
	b _0802F6E4
_0802F36A:
	lsls r0, 2
	ldr r1, _0802F378
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0802F374: .4byte gUnknown_203B310
_0802F378: .4byte _0802F37C
	.align 2, 0
_0802F37C:
	.4byte _0802F3A4
	.4byte _0802F3E8
	.4byte _0802F444
	.4byte _0802F494
	.4byte _0802F524
	.4byte _0802F5CC
	.4byte _0802F614
	.4byte _0802F630
	.4byte _0802F6A4
	.4byte _0802F6E4
_0802F3A4:
	ldr r2, [r6]
	ldr r0, [r2, 0x10]
	ldr r1, [r0, 0x18]
	cmp r1, 0
	bne _0802F3B6
	movs r0, 0x2
	bl sub_802F2E8
	b _0802F6E4
_0802F3B6:
	ldr r0, _0802F3D4
	str r1, [r0]
	ldrb r0, [r2, 0x8]
	cmp r0, 0
	beq _0802F3E0
	ldr r0, _0802F3D8
	adds r2, 0x14
	ldr r3, _0802F3DC
	movs r1, 0
	bl sub_80141B4
	ldr r1, [r6]
	movs r0, 0x1
	str r0, [r1, 0x4]
	b _0802F6E4
	.align 2, 0
_0802F3D4: .4byte gUnknown_202DE30
_0802F3D8: .4byte gUnknown_80E0434
_0802F3DC: .4byte 0x0000010d
_0802F3E0:
	movs r0, 0x1
	bl sub_802F2E8
	b _0802F6E4
_0802F3E8:
	movs r0, 0xCB
	bl sub_8011988
	ldr r0, _0802F414
	ldr r0, [r0]
	ldr r0, [r0, 0x10]
	ldr r0, [r0, 0x18]
	bl sub_80913A0
	movs r0, 0
	bl sub_808D544
	cmp r0, 0x1
	bgt _0802F420
	ldr r0, _0802F418
	ldr r3, _0802F41C
	movs r1, 0
	movs r2, 0
	bl sub_80141B4
	b _0802F42C
	.align 2, 0
_0802F414: .4byte gUnknown_203B310
_0802F418: .4byte gUnknown_80E045C
_0802F41C: .4byte 0x00000101
_0802F420:
	ldr r0, _0802F438
	ldr r3, _0802F43C
	movs r1, 0
	movs r2, 0
	bl sub_80141B4
_0802F42C:
	ldr r0, _0802F440
	ldr r1, [r0]
	movs r0, 0x2
	str r0, [r1, 0x4]
	b _0802F6E4
	.align 2, 0
_0802F438: .4byte gUnknown_80E0484
_0802F43C: .4byte 0x00000101
_0802F440: .4byte gUnknown_203B310
_0802F444:
	ldr r0, [r6]
	ldr r0, [r0, 0x10]
	adds r1, r0, 0
	adds r1, 0x20
	ldrb r0, [r1]
	cmp r0, 0
	bne _0802F45A
	movs r0, 0x4
	bl sub_802F2E8
	b _0802F6E4
_0802F45A:
	ldr r0, _0802F480
	ldrb r1, [r1]
	movs r2, 0
	bl sub_8092578
	ldr r2, [r6]
	ldrb r0, [r2, 0x8]
	cmp r0, 0
	beq _0802F48C
	ldr r0, _0802F484
	adds r2, 0x14
	ldr r3, _0802F488
	movs r1, 0
	bl sub_80141B4
	ldr r1, [r6]
	movs r0, 0x3
	str r0, [r1, 0x4]
	b _0802F6E4
	.align 2, 0
_0802F480: .4byte gUnknown_202E628
_0802F484: .4byte gUnknown_80E04B4
_0802F488: .4byte 0x0000010d
_0802F48C:
	movs r0, 0x3
	bl sub_802F2E8
	b _0802F6E4
_0802F494:
	ldr r4, _0802F4B4
	ldr r0, [r4]
	ldr r0, [r0, 0x10]
	adds r0, 0x20
	ldrb r0, [r0]
	bl GetFriendAreaStatus
	lsls r0, 24
	cmp r0, 0
	beq _0802F4BC
	movs r0, 0xFA
	lsls r0, 2
	bl sub_80913A0
	ldr r0, _0802F4B8
	b _0802F4DA
	.align 2, 0
_0802F4B4: .4byte gUnknown_203B310
_0802F4B8: .4byte gUnknown_80E04F4
_0802F4BC:
	movs r0, 0
	bl sub_808D544
	cmp r0, 0x1
	bgt _0802F4F0
	ldr r0, [r4]
	ldr r0, [r0, 0x10]
	adds r0, 0x20
	ldrb r0, [r0]
	bl UnlockFriendArea
	movs r0, 0xCE
	bl sub_8011988
	ldr r0, _0802F4E8
_0802F4DA:
	ldr r3, _0802F4EC
	movs r1, 0
	movs r2, 0
	bl sub_80141B4
	b _0802F50E
	.align 2, 0
_0802F4E8: .4byte gUnknown_80E05C0
_0802F4EC: .4byte 0x00000101
_0802F4F0:
	ldr r0, [r4]
	ldr r0, [r0, 0x10]
	adds r0, 0x20
	ldrb r0, [r0]
	bl UnlockFriendArea
	movs r0, 0xCE
	bl sub_8011988
	ldr r0, _0802F518
	ldr r3, _0802F51C
	movs r1, 0
	movs r2, 0
	bl sub_80141B4
_0802F50E:
	ldr r0, _0802F520
	ldr r1, [r0]
	movs r0, 0x4
	str r0, [r1, 0x4]
	b _0802F6E4
	.align 2, 0
_0802F518: .4byte gUnknown_80E05FC
_0802F51C: .4byte 0x00000101
_0802F520: .4byte gUnknown_203B310
_0802F524:
	ldr r0, [r6]
	ldr r0, [r0, 0x10]
	ldrb r2, [r0, 0x1C]
	cmp r2, 0
	beq _0802F628
	ldr r0, [r0, 0x18]
	cmp r0, 0
	bne _0802F620
	lsls r2, 16
	ldr r1, _0802F564
	ldr r0, [sp, 0xC]
	ands r0, r1
	orrs r0, r2
	str r0, [sp, 0xC]
	lsrs r0, 16
	lsls r0, 24
	lsrs r0, 24
	bl sub_8090A60
	lsls r0, 24
	cmp r0, 0
	beq _0802F56C
	ldr r0, [r6]
	ldr r0, [r0, 0x10]
	ldrb r1, [r0, 0x1F]
	lsls r1, 8
	ldr r2, _0802F568
	ldr r0, [sp, 0xC]
	ands r0, r2
	orrs r0, r1
	b _0802F572
	.align 2, 0
_0802F564: .4byte 0xff00ffff
_0802F568: .4byte 0xffff00ff
_0802F56C:
	ldr r1, _0802F5B4
	ldr r0, [sp, 0xC]
	ands r0, r1
_0802F572:
	str r0, [sp, 0xC]
	ldr r1, _0802F5B8
	ldr r0, [sp, 0xC]
	ands r0, r1
	movs r2, 0x1
	orrs r0, r2
	str r0, [sp, 0xC]
	movs r1, 0
	str r1, [sp]
	mov r0, sp
	strb r1, [r0, 0x4]
	strb r2, [r0, 0x8]
	ldr r0, _0802F5BC
	add r1, sp, 0xC
	mov r2, sp
	bl sub_8090E14
	ldr r4, _0802F5C0
	ldr r2, [r4]
	ldrb r0, [r2, 0x8]
	cmp r0, 0
	beq _0802F620
	ldr r0, _0802F5C4
	adds r2, 0x14
	ldr r3, _0802F5C8
	movs r1, 0
	bl sub_80141B4
	ldr r1, [r4]
	movs r0, 0x5
	str r0, [r1, 0x4]
	b _0802F6E4
	.align 2, 0
_0802F5B4: .4byte 0xffff00ff
_0802F5B8: .4byte 0xffffff00
_0802F5BC: .4byte gUnknown_202DEA8
_0802F5C0: .4byte gUnknown_203B310
_0802F5C4: .4byte gUnknown_80E0640
_0802F5C8: .4byte 0x0000010d
_0802F5CC:
	ldr r0, [r6]
	ldr r2, [r0, 0x10]
	adds r1, r2, 0
	adds r1, 0x1C
	ldr r3, [r0, 0xC]
	adds r1, r3
	ldrb r0, [r1]
	cmp r0, 0
	bne _0802F5E6
	movs r0, 0x6
	bl sub_802F2E8
	b _0802F6E4
_0802F5E6:
	cmp r3, 0
	bne _0802F5FC
	ldr r0, [r2, 0x18]
	cmp r0, 0
	bne _0802F5FC
	ldrb r1, [r2, 0x1C]
	ldrb r2, [r2, 0x1F]
	movs r0, 0
	bl sub_801B60C
	b _0802F6E4
_0802F5FC:
	ldr r1, [r6]
	ldr r2, [r1, 0x10]
	adds r0, r2, 0
	adds r0, 0x1C
	ldr r1, [r1, 0xC]
	adds r0, r1
	ldrb r1, [r0]
	ldrb r2, [r2, 0x1F]
	movs r0, 0x1
	bl sub_801B60C
	b _0802F6E4
_0802F614:
	ldr r1, [r6]
	ldr r0, [r1, 0xC]
	adds r0, 0x1
	str r0, [r1, 0xC]
	cmp r0, 0x2
	bgt _0802F628
_0802F620:
	movs r0, 0x5
	bl sub_802F2E8
	b _0802F6E4
_0802F628:
	movs r0, 0x7
	bl sub_802F2E8
	b _0802F6E4
_0802F630:
	adds r5, r6, 0
	ldr r0, [r5]
	ldr r0, [r0, 0x10]
	ldr r0, [r0, 0x24]
	cmp r0, 0
	bne _0802F644
	movs r0, 0x9
	bl sub_802F2E8
	b _0802F6E4
_0802F644:
	bl GetRescueTeamRank
	ldr r1, [r5]
	strb r0, [r1, 0x9]
	ldr r0, [r5]
	ldr r0, [r0, 0x10]
	ldr r0, [r0, 0x24]
	bl AddToTeamRankPts
	movs r0, 0xCB
	bl sub_8011988
	ldr r4, [r5]
	bl GetRescueTeamRank
	ldrb r1, [r4, 0x9]
	lsls r0, 24
	lsrs r0, 24
	cmp r1, r0
	beq _0802F672
	ldr r1, [r5]
	movs r0, 0x8
	b _0802F676
_0802F672:
	ldr r1, [r6]
	movs r0, 0x9
_0802F676:
	str r0, [r1, 0x4]
	ldr r1, _0802F694
	ldr r0, _0802F698
	ldr r0, [r0]
	ldr r0, [r0, 0x10]
	ldr r0, [r0, 0x24]
	str r0, [r1]
	ldr r0, _0802F69C
	ldr r3, _0802F6A0
	movs r1, 0
	movs r2, 0
	bl sub_80141B4
	b _0802F6E4
	.align 2, 0
_0802F694: .4byte gUnknown_202DE30
_0802F698: .4byte gUnknown_203B310
_0802F69C: .4byte gUnknown_80E0670
_0802F6A0: .4byte 0x00000101
_0802F6A4:
	movs r0, 0xC9
	bl sub_8011988
	ldr r0, _0802F6EC
	ldr r1, [r0]
	movs r0, 0x9
	str r0, [r1, 0x4]
	ldrb r0, [r1, 0x9]
	bl GetTeamRankString
	adds r1, r0, 0
	ldr r4, _0802F6F0
	adds r0, r4, 0
	bl strcpy
	bl GetRescueTeamRank
	lsls r0, 24
	lsrs r0, 24
	bl GetTeamRankString
	adds r1, r0, 0
	adds r4, 0x50
	adds r0, r4, 0
	bl strcpy
	ldr r0, _0802F6F4
	ldr r3, _0802F6F8
	movs r1, 0
	movs r2, 0
	bl sub_80141B4
_0802F6E4:
	add sp, 0x10
	pop {r4-r6}
	pop {r0}
	bx r0
	.align 2, 0
_0802F6EC: .4byte gUnknown_203B310
_0802F6F0: .4byte gUnknown_202E038
_0802F6F4: .4byte gUnknown_80E06A8
_0802F6F8: .4byte 0x00000101
	thumb_func_end HandleMissionReward

	thumb_func_start sub_802F6FC
sub_802F6FC:
	push {lr}
	bl sub_801B6AC
	cmp r0, 0x1
	bls _0802F714
	cmp r0, 0x3
	bhi _0802F714
	bl sub_801B72C
	movs r0, 0x6
	bl sub_802F2E8
_0802F714:
	pop {r0}
	bx r0
	thumb_func_end sub_802F6FC

	thumb_func_start sub_802F718
sub_802F718:
	push {lr}
	sub sp, 0x4
	mov r0, sp
	bl sub_80144A4
	cmp r0, 0
	bne _0802F730
	ldr r0, _0802F738
	ldr r0, [r0]
	ldr r0, [r0, 0x4]
	bl sub_802F2E8
_0802F730:
	add sp, 0x4
	pop {r0}
	bx r0
	.align 2, 0
_0802F738: .4byte gUnknown_203B310
	thumb_func_end sub_802F718

	thumb_func_start sub_802F73C
sub_802F73C:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	adds r5, r0, 0
	adds r7, r1, 0
	mov r8, r2
	lsls r3, 24
	lsrs r6, r3, 24
	bl sub_802FCF0
	lsls r0, 24
	cmp r0, 0
	beq _0802F75A
	movs r0, 0
	b _0802F836
_0802F75A:
	ldr r4, _0802F7AC
	ldr r0, [r4]
	cmp r0, 0
	bne _0802F76E
	movs r0, 0xAE
	lsls r0, 1
	movs r1, 0x8
	bl MemoryAlloc
	str r0, [r4]
_0802F76E:
	ldr r0, [r4]
	adds r0, 0xB8
	strb r6, [r0]
	ldr r0, [r4]
	adds r1, r0, 0
	adds r1, 0xF0
	str r5, [r1]
	adds r2, r0, 0
	adds r2, 0xF4
	lsls r1, r5, 1
	adds r1, r5
	lsls r1, 3
	adds r1, 0xF8
	adds r1, r0, r1
	str r1, [r2]
	adds r0, 0xF8
	bl sub_8006518
	cmp r6, 0
	beq _0802F7B4
	ldr r1, [r4]
	adds r0, r1, 0
	adds r0, 0xF0
	ldr r2, [r0]
	lsls r0, r2, 1
	adds r0, r2
	lsls r0, 3
	adds r1, r0
	adds r1, 0xF8
	ldr r0, _0802F7B0
	b _0802F7C8
	.align 2, 0
_0802F7AC: .4byte gUnknown_203B314
_0802F7B0: .4byte gUnknown_80E072C
_0802F7B4:
	ldr r1, [r4]
	adds r0, r1, 0
	adds r0, 0xF0
	ldr r2, [r0]
	lsls r0, r2, 1
	adds r0, r2
	lsls r0, 3
	adds r1, r0
	adds r1, 0xF8
	ldr r0, _0802F840
_0802F7C8:
	ldm r0!, {r2-r4}
	stm r1!, {r2-r4}
	ldm r0!, {r2-r4}
	stm r1!, {r2-r4}
	ldr r4, _0802F844
	ldr r2, [r4]
	adds r0, r2, 0
	adds r0, 0xF4
	ldr r1, [r0]
	movs r3, 0xAC
	lsls r3, 1
	adds r0, r2, r3
	str r0, [r1, 0x14]
	cmp r7, 0
	beq _0802F7FC
	adds r0, r2, 0
	adds r0, 0xF0
	ldr r1, [r0]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 3
	subs r3, 0x58
	adds r1, r2, r3
	adds r1, r0
	ldr r0, [r7]
	str r0, [r1]
_0802F7FC:
	ldr r0, [r4]
	adds r0, 0xF4
	ldr r0, [r0]
	mov r1, r8
	bl sub_8012D08
	bl ResetUnusedInputStruct
	ldr r0, [r4]
	adds r0, 0xF8
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	ldr r4, [r4]
	adds r4, 0xBC
	bl sub_802FBF4
	adds r1, r0, 0
	adds r0, r4, 0
	mov r2, r8
	adds r3, r5, 0
	bl sub_8013818
	bl sub_802F9C0
	bl sub_802FA50
	movs r0, 0x1
_0802F836:
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r1}
	bx r1
	.align 2, 0
_0802F840: .4byte gUnknown_80E0714
_0802F844: .4byte gUnknown_203B314
	thumb_func_end sub_802F73C

	thumb_func_start sub_802F848
sub_802F848:
	push {r4,r5,lr}
	lsls r0, 16
	asrs r4, r0, 16
	movs r3, 0
	ldr r1, _0802F858
	ldr r0, [r1]
	b _0802F884
	.align 2, 0
_0802F858: .4byte gUnknown_203B314
_0802F85C:
	ldr r2, [r1]
	lsls r0, r3, 1
	adds r0, r2, r0
	movs r5, 0
	ldrsh r0, [r0, r5]
	cmp r0, r4
	bne _0802F880
	adds r0, r2, 0
	adds r0, 0xBC
	adds r1, r3, 0
	bl sub_8013878
	bl sub_802F9C0
	bl sub_802FA50
	movs r0, 0x1
	b _0802F89A
_0802F880:
	adds r3, 0x1
	adds r0, r2, 0
_0802F884:
	adds r0, 0xDE
	movs r2, 0
	ldrsh r0, [r0, r2]
	cmp r3, r0
	blt _0802F85C
	ldr r0, [r1]
	adds r0, 0xBC
	movs r1, 0
	bl sub_8013878
	movs r0, 0
_0802F89A:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_802F848

	thumb_func_start sub_802F8A0
sub_802F8A0:
	push {r4,lr}
	lsls r0, 24
	cmp r0, 0
	bne _0802F8BC
	ldr r0, _0802F8B8
	ldr r0, [r0]
	adds r0, 0xBC
	bl sub_8013660
	movs r0, 0
	b _0802F904
	.align 2, 0
_0802F8B8: .4byte gUnknown_203B314
_0802F8BC:
	ldr r4, _0802F8D8
	ldr r0, [r4]
	adds r0, 0xBC
	bl GetKeyPress
	cmp r0, 0x1
	beq _0802F8DC
	cmp r0, 0x2
	bne _0802F8E6
	movs r0, 0x1
	bl PlayMenuSoundEffect
	movs r0, 0x2
	b _0802F904
	.align 2, 0
_0802F8D8: .4byte gUnknown_203B314
_0802F8DC:
	movs r0, 0
	bl PlayMenuSoundEffect
	movs r0, 0x3
	b _0802F904
_0802F8E6:
	ldr r0, [r4]
	adds r0, 0xBC
	movs r1, 0x1
	bl sub_80138B8
	lsls r0, 24
	cmp r0, 0
	bne _0802F8FA
	movs r0, 0
	b _0802F904
_0802F8FA:
	bl sub_802F9C0
	bl sub_802FA50
	movs r0, 0x1
_0802F904:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_802F8A0

	thumb_func_start sub_802F90C
sub_802F90C:
	ldr r0, _0802F934
	ldr r2, [r0]
	adds r0, r2, 0
	adds r0, 0xDA
	movs r3, 0
	ldrsh r1, [r0, r3]
	subs r0, 0x2
	movs r3, 0
	ldrsh r0, [r0, r3]
	muls r0, r1
	adds r1, r2, 0
	adds r1, 0xD4
	movs r3, 0
	ldrsh r1, [r1, r3]
	adds r0, r1
	lsls r0, 1
	adds r0, r2, r0
	movs r1, 0
	ldrsh r0, [r0, r1]
	bx lr
	.align 2, 0
_0802F934: .4byte gUnknown_203B314
	thumb_func_end sub_802F90C

	thumb_func_start sub_802F938
sub_802F938:
	push {r4,r5,lr}
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	bl sub_802FBF4
	adds r1, r0, 0
	ldr r5, _0802F970
	ldr r0, [r5]
	adds r2, r0, 0
	adds r2, 0xDE
	strh r1, [r2]
	adds r0, 0xBC
	bl sub_8013984
	bl sub_802F9C0
	bl sub_802FA50
	cmp r4, 0
	beq _0802F96A
	ldr r0, [r5]
	adds r0, 0xBC
	bl AddMenuCursorSprite
_0802F96A:
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_0802F970: .4byte gUnknown_203B314
	thumb_func_end sub_802F938

	thumb_func_start sub_802F974
sub_802F974:
	push {r4,r5,lr}
	ldr r4, _0802F9B8
	ldr r2, [r4]
	cmp r2, 0
	beq _0802F9B2
	adds r0, r2, 0
	adds r0, 0xF0
	ldr r0, [r0]
	lsls r1, r0, 1
	adds r1, r0
	lsls r1, 3
	adds r1, r2, r1
	adds r1, 0xF8
	ldr r0, _0802F9BC
	ldm r0!, {r2,r3,r5}
	stm r1!, {r2,r3,r5}
	ldm r0!, {r2,r3,r5}
	stm r1!, {r2,r3,r5}
	bl ResetUnusedInputStruct
	ldr r0, [r4]
	adds r0, 0xF8
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	ldr r0, [r4]
	bl MemoryFree
	movs r0, 0
	str r0, [r4]
_0802F9B2:
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_0802F9B8: .4byte gUnknown_203B314
_0802F9BC: .4byte gUnknown_80E06FC
	thumb_func_end sub_802F974

	thumb_func_start sub_802F9C0
sub_802F9C0:
	push {r4,r5,lr}
	ldr r4, _0802FA44
	ldr r0, [r4]
	movs r1, 0xAC
	lsls r1, 1
	adds r0, r1
	movs r2, 0
	movs r1, 0x1
	strb r1, [r0]
	ldr r0, [r4]
	ldr r3, _0802FA48
	adds r0, r3
	strb r2, [r0]
	ldr r0, [r4]
	adds r3, 0x1
	adds r1, r0, r3
	movs r0, 0x8
	strb r0, [r1]
	ldr r0, [r4]
	ldr r1, _0802FA4C
	adds r0, r1
	strb r2, [r0]
	ldr r0, [r4]
	adds r0, 0xD6
	movs r2, 0
	ldrsh r0, [r0, r2]
	movs r1, 0xC
	bl sub_80095E4
	adds r0, 0x2
	lsls r0, 16
	ldr r3, [r4]
	adds r5, r3, 0
	adds r5, 0xF0
	ldr r2, [r5]
	lsls r1, r2, 1
	adds r1, r2
	lsls r1, 3
	adds r1, r3, r1
	movs r2, 0x83
	lsls r2, 1
	adds r1, r2
	asrs r2, r0, 16
	lsrs r0, 16
	strh r0, [r1]
	ldr r1, [r5]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 3
	adds r3, r0
	adds r2, 0x2
	movs r0, 0x84
	lsls r0, 1
	adds r3, r0
	strh r2, [r3]
	bl ResetUnusedInputStruct
	ldr r0, [r4]
	adds r0, 0xF8
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_0802FA44: .4byte gUnknown_203B314
_0802FA48: .4byte 0x00000159
_0802FA4C: .4byte 0x0000015b
	thumb_func_end sub_802F9C0

	thumb_func_start sub_802FA50
sub_802FA50:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0x8
	ldr r4, _0802FB1C
	ldr r0, [r4]
	adds r0, 0xF0
	ldr r0, [r0]
	bl sub_8008C54
	ldr r0, [r4]
	adds r0, 0xF0
	ldr r0, [r0]
	bl sub_80073B8
	ldr r2, _0802FB20
	ldr r0, [r4]
	adds r0, 0xF0
	ldr r3, [r0]
	movs r0, 0
	str r0, [sp]
	movs r0, 0xA
	movs r1, 0
	bl xxx_call_draw_string
	ldr r3, [r4]
	movs r1, 0xAD
	lsls r1, 1
	adds r0, r3, r1
	ldrb r0, [r0]
	lsls r0, 3
	adds r0, 0x4
	adds r1, r3, 0
	adds r1, 0xDA
	movs r5, 0
	ldrsh r2, [r1, r5]
	adds r2, 0x1
	movs r1, 0x7
	str r1, [sp]
	adds r1, r3, 0
	adds r1, 0xF0
	ldr r1, [r1]
	str r1, [sp, 0x4]
	movs r1, 0
	movs r3, 0x2
	bl sub_8012BC4
	ldr r1, [r4]
	adds r0, r1, 0
	adds r0, 0xB8
	ldrb r0, [r0]
	cmp r0, 0
	beq _0802FB78
	movs r6, 0
	adds r0, r1, 0
	adds r0, 0xD6
	movs r1, 0
	ldrsh r0, [r0, r1]
	cmp r6, r0
	blt _0802FACA
	b _0802FBD6
_0802FACA:
	mov r8, r4
_0802FACC:
	mov r2, r8
	ldr r0, [r2]
	adds r0, 0xBC
	adds r1, r6, 0
	bl sub_8013800
	adds r5, r0, 0
	mov r3, r8
	ldr r2, [r3]
	adds r0, r2, 0
	adds r0, 0xDA
	movs r3, 0
	ldrsh r1, [r0, r3]
	subs r0, 0x2
	movs r3, 0
	ldrsh r0, [r0, r3]
	muls r0, r1
	adds r1, r0, r6
	lsls r0, r1, 1
	adds r0, r2, r0
	movs r3, 0
	ldrsh r7, [r0, r3]
	adds r0, r2, 0
	adds r0, 0x5C
	adds r0, r1
	ldrb r4, [r0]
	cmp r4, 0
	beq _0802FB28
	adds r0, r2, 0
	adds r0, 0xF0
	ldr r3, [r0]
	movs r0, 0
	str r0, [sp]
	movs r0, 0xA
	adds r1, r5, 0
	ldr r2, _0802FB24
	bl xxx_call_draw_string
	b _0802FB46
	.align 2, 0
_0802FB1C: .4byte gUnknown_203B314
_0802FB20: .4byte gUnknown_80E0744
_0802FB24: .4byte gUnknown_80E0750
_0802FB28:
	adds r0, r2, 0
	adds r0, 0x8A
	adds r0, r1
	ldrb r0, [r0]
	cmp r0, 0
	beq _0802FB46
	adds r0, r2, 0
	adds r0, 0xF0
	ldr r3, [r0]
	str r4, [sp]
	movs r0, 0xA
	adds r1, r5, 0
	ldr r2, _0802FB74
	bl xxx_call_draw_string
_0802FB46:
	adds r0, r7, 0
	bl sub_80974A0
	adds r2, r0, 0
	mov r1, r8
	ldr r0, [r1]
	adds r0, 0xF0
	ldr r3, [r0]
	movs r0, 0
	str r0, [sp]
	movs r0, 0x18
	adds r1, r5, 0
	bl xxx_call_draw_string
	adds r6, 0x1
	mov r2, r8
	ldr r0, [r2]
	adds r0, 0xD6
	movs r3, 0
	ldrsh r0, [r0, r3]
	cmp r6, r0
	blt _0802FACC
	b _0802FBD6
	.align 2, 0
_0802FB74: .4byte gUnknown_80E0754
_0802FB78:
	movs r6, 0
	adds r0, r1, 0
	adds r0, 0xD6
	movs r5, 0
	ldrsh r0, [r0, r5]
	cmp r6, r0
	bge _0802FBD6
	adds r5, r4, 0
_0802FB88:
	ldr r0, [r5]
	adds r0, 0xBC
	adds r1, r6, 0
	bl sub_8013800
	adds r4, r0, 0
	ldr r1, [r5]
	adds r0, r1, 0
	adds r0, 0xDA
	movs r3, 0
	ldrsh r2, [r0, r3]
	subs r0, 0x2
	movs r3, 0
	ldrsh r0, [r0, r3]
	muls r0, r2
	adds r0, r6
	lsls r0, 1
	adds r1, r0
	movs r2, 0
	ldrsh r0, [r1, r2]
	bl sub_80974A0
	adds r2, r0, 0
	ldr r0, [r5]
	adds r0, 0xF0
	ldr r3, [r0]
	movs r0, 0
	str r0, [sp]
	movs r0, 0x8
	adds r1, r4, 0
	bl xxx_call_draw_string
	adds r6, 0x1
	ldr r0, [r5]
	adds r0, 0xD6
	movs r3, 0
	ldrsh r0, [r0, r3]
	cmp r6, r0
	blt _0802FB88
_0802FBD6:
	ldr r0, _0802FBF0
	ldr r0, [r0]
	adds r0, 0xF0
	ldr r0, [r0]
	bl sub_80073E0
	add sp, 0x8
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_0802FBF0: .4byte gUnknown_203B314
	thumb_func_end sub_802FA50

	thumb_func_start sub_802FBF4
sub_802FBF4:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x4
	movs r0, 0
	mov r8, r0
	movs r1, 0
	str r1, [sp]
_0802FC08:
	ldr r1, [sp]
	lsls r0, r1, 16
	asrs r4, r0, 16
	mov r10, r4
	adds r0, r4, 0
	bl sub_80A27CC
	lsls r0, 24
	cmp r0, 0
	beq _0802FCCE
	cmp r4, 0x13
	beq _0802FCCE
	cmp r4, 0x1D
	beq _0802FCCE
	ldr r7, _0802FC88
	ldr r1, [r7]
	mov r0, r8
	lsls r6, r0, 1
	adds r0, r1, r6
	strh r4, [r0]
	adds r1, 0x5C
	add r1, r8
	movs r0, 0
	strb r0, [r1]
	ldr r0, [r7]
	adds r0, 0x8A
	add r0, r8
	movs r1, 0
	strb r1, [r0]
	ldr r0, [r7]
	adds r0, 0xB8
	ldrb r0, [r0]
	cmp r0, 0
	beq _0802FCCA
	cmp r4, 0xD
	beq _0802FCCA
	adds r0, r4, 0
	bl sub_80A270C
	lsls r0, 24
	lsrs r0, 24
	mov r9, r0
	movs r5, 0
	cmp r4, 0x1E
	bgt _0802FCA8
	adds r0, r4, 0
	bl sub_8097384
	lsls r0, 24
	cmp r0, 0
	bne _0802FCA6
	cmp r4, 0x6
	bne _0802FC8C
	movs r0, 0x13
	bl sub_8097384
	lsls r0, 24
	cmp r0, 0
	beq _0802FCA8
	ldr r0, [r7]
	adds r0, r6
	movs r1, 0x13
	b _0802FCA4
	.align 2, 0
_0802FC88: .4byte gUnknown_203B314
_0802FC8C:
	mov r0, r10
	cmp r0, 0xA
	bne _0802FCA8
	movs r0, 0x1D
	bl sub_8097384
	lsls r0, 24
	cmp r0, 0
	beq _0802FCA8
	ldr r0, [r7]
	adds r0, r6
	movs r1, 0x1D
_0802FCA4:
	strh r1, [r0]
_0802FCA6:
	movs r5, 0x1
_0802FCA8:
	ldr r4, _0802FCEC
	ldr r0, [r4]
	adds r0, 0x5C
	add r0, r8
	strb r5, [r0]
	cmp r5, 0
	bne _0802FCCA
	mov r0, r9
	bl sub_80969D0
	cmp r0, 0
	ble _0802FCCA
	ldr r0, [r4]
	adds r0, 0x8A
	add r0, r8
	movs r1, 0x1
	strb r1, [r0]
_0802FCCA:
	movs r1, 0x1
	add r8, r1
_0802FCCE:
	ldr r0, [sp]
	adds r0, 0x1
	str r0, [sp]
	cmp r0, 0x2D
	ble _0802FC08
	mov r0, r8
	add sp, 0x4
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	.align 2, 0
_0802FCEC: .4byte gUnknown_203B314
	thumb_func_end sub_802FBF4

	thumb_func_start sub_802FCF0
sub_802FCF0:
	push {r4,lr}
	movs r4, 0
_0802FCF4:
	lsls r0, r4, 16
	asrs r0, 16
	bl sub_80A27CC
	lsls r0, 24
	cmp r0, 0
	beq _0802FD06
	movs r0, 0
	b _0802FD0E
_0802FD06:
	adds r4, 0x1
	cmp r4, 0x2D
	ble _0802FCF4
	movs r0, 0x1
_0802FD0E:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_802FCF0

	thumb_func_start CreateMakhuitaShop
CreateMakhuitaShop:
	push {r4-r6,lr}
	adds r5, r0, 0
	bl ResetUnusedInputStruct
	movs r0, 0
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	ldr r4, _0802FD48
	movs r0, 0xCC
	movs r1, 0x8
	bl MemoryAlloc
	str r0, [r4]
	ldr r1, _0802FD4C
	strh r1, [r0, 0x10]
	str r5, [r0]
	cmp r5, 0x7
	bhi _0802FDC0
	lsls r0, r5, 2
	ldr r1, _0802FD50
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0802FD48: .4byte gUnknown_203B318
_0802FD4C: .4byte 0x0000ffff
_0802FD50: .4byte _0802FD54
	.align 2, 0
_0802FD54:
	.4byte _0802FD74
	.4byte _0802FD84
	.4byte _0802FD94
	.4byte _0802FDA4
	.4byte _0802FDB4
	.4byte _0802FDB8
	.4byte _0802FDBC
	.4byte _0802FDC0
_0802FD74:
	movs r6, 0
	ldr r1, _0802FD80
	ldr r0, [r1]
	str r6, [r0, 0x4]
	b _0802FDCC
	.align 2, 0
_0802FD80: .4byte gUnknown_203B318
_0802FD84:
	movs r6, 0x7
	ldr r2, _0802FD90
	ldr r1, [r2]
	movs r0, 0
	b _0802FDC8
	.align 2, 0
_0802FD90: .4byte gUnknown_203B318
_0802FD94:
	movs r6, 0x6
	ldr r2, _0802FDA0
	ldr r1, [r2]
	movs r0, 0
	b _0802FDC8
	.align 2, 0
_0802FDA0: .4byte gUnknown_203B318
_0802FDA4:
	movs r6, 0x8
	ldr r2, _0802FDB0
	ldr r1, [r2]
	movs r0, 0
	b _0802FDC8
	.align 2, 0
_0802FDB0: .4byte gUnknown_203B318
_0802FDB4:
	movs r6, 0
	b _0802FDC2
_0802FDB8:
	movs r6, 0x7
	b _0802FDC2
_0802FDBC:
	movs r6, 0x6
	b _0802FDC2
_0802FDC0:
	movs r6, 0x8
_0802FDC2:
	ldr r2, _0802FDD8
	ldr r1, [r2]
	movs r0, 0x1
_0802FDC8:
	str r0, [r1, 0x4]
	adds r1, r2, 0
_0802FDCC:
	ldr r1, [r1]
	ldr r0, [r1, 0x4]
	cmp r0, 0x1
	bne _0802FDDC
	movs r0, 0
	b _0802FDE0
	.align 2, 0
_0802FDD8: .4byte gUnknown_203B318
_0802FDDC:
	adds r0, r1, 0
	adds r0, 0x58
_0802FDE0:
	str r0, [r1, 0x68]
	ldr r0, _0802FE48
	ldr r5, _0802FE4C
	adds r1, r5, 0
	bl CopyYellowSpeciesNametoBuffer
	ldr r4, _0802FE50
	adds r0, r4, 0
	adds r1, r5, 0
	bl CopyYellowSpeciesNametoBuffer
	adds r0, r5, 0
	bl GetMonSpecies
	adds r1, r0, 0
	subs r4, 0x50
	adds r0, r4, 0
	bl strcpy
	adds r0, r5, 0
	bl GetDialogueSpriteDataPtr
	ldr r3, _0802FE54
	ldr r1, [r3]
	str r0, [r1, 0x58]
	ldr r0, [r0, 0x4]
	str r0, [r1, 0x5C]
	adds r1, 0x64
	movs r2, 0
	strb r2, [r1]
	ldr r0, [r3]
	adds r0, 0x65
	strb r2, [r0]
	ldr r0, [r3]
	adds r0, 0x66
	strb r2, [r0]
	ldr r1, [r3]
	adds r2, r1, 0
	adds r2, 0x60
	movs r0, 0x2
	strh r0, [r2]
	adds r1, 0x62
	movs r0, 0x8
	strh r0, [r1]
	adds r0, r6, 0
	bl sub_802FF04
	movs r0, 0x1
	pop {r4-r6}
	pop {r1}
	bx r1
	.align 2, 0
_0802FE48: .4byte gUnknown_202E5D8
_0802FE4C: .4byte 0x00000141
_0802FE50: .4byte gUnknown_202E1C8
_0802FE54: .4byte gUnknown_203B318
	thumb_func_end CreateMakhuitaShop

	thumb_func_start sub_802FE58
sub_802FE58:
	push {lr}
	ldr r0, _0802FE70
	ldr r0, [r0]
	ldr r0, [r0, 0x8]
	cmp r0, 0xD
	bhi _0802FEC6
	lsls r0, 2
	ldr r1, _0802FE74
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0802FE70: .4byte gUnknown_203B318
_0802FE74: .4byte _0802FE78
	.align 2, 0
_0802FE78:
	.4byte _0802FEB0
	.4byte _0802FEB0
	.4byte _0802FEC6
	.4byte _0802FEC6
	.4byte _0802FEB6
	.4byte _0802FEC6
	.4byte _0802FEC6
	.4byte _0802FEC6
	.4byte _0802FEC6
	.4byte _0802FEC6
	.4byte _0802FEC6
	.4byte _0802FEBC
	.4byte _0802FEC6
	.4byte _0802FEC2
_0802FEB0:
	bl sub_8030208
	b _0802FECA
_0802FEB6:
	bl sub_8030258
	b _0802FECA
_0802FEBC:
	bl sub_80302A8
	b _0802FECA
_0802FEC2:
	movs r0, 0x3
	b _0802FECC
_0802FEC6:
	bl sub_80302C4
_0802FECA:
	movs r0, 0
_0802FECC:
	pop {r1}
	bx r1
	thumb_func_end sub_802FE58

	thumb_func_start sub_802FED0
sub_802FED0:
	ldr r0, _0802FEDC
	ldr r0, [r0]
	movs r1, 0x10
	ldrsh r0, [r0, r1]
	bx lr
	.align 2, 0
_0802FEDC: .4byte gUnknown_203B318
	thumb_func_end sub_802FED0

	thumb_func_start sub_802FEE0
sub_802FEE0:
	push {r4,lr}
	ldr r4, _0802FF00
	ldr r0, [r4]
	cmp r0, 0
	beq _0802FEFA
	ldr r0, [r0, 0x58]
	bl CloseFile
	ldr r0, [r4]
	bl MemoryFree
	movs r0, 0
	str r0, [r4]
_0802FEFA:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0802FF00: .4byte gUnknown_203B318
	thumb_func_end sub_802FEE0

	thumb_func_start sub_802FF04
sub_802FF04:
	push {lr}
	ldr r1, _0802FF18
	ldr r1, [r1]
	str r0, [r1, 0x8]
	bl sub_802FF1C
	bl sub_802FF88
	pop {r0}
	bx r0
	.align 2, 0
_0802FF18: .4byte gUnknown_203B318
	thumb_func_end sub_802FF04

	thumb_func_start sub_802FF1C
sub_802FF1C:
	push {r4-r7,lr}
	ldr r4, _0802FF3C
	ldr r0, [r4]
	adds r0, 0x6C
	bl sub_8006518
	ldr r0, [r4]
	ldr r0, [r0, 0x8]
	cmp r0, 0x4
	beq _0802FF44
	cmp r0, 0x4
	bgt _0802FF40
	cmp r0, 0
	beq _0802FF44
	b _0802FF68
	.align 2, 0
_0802FF3C: .4byte gUnknown_203B318
_0802FF40:
	cmp r0, 0xD
	bne _0802FF68
_0802FF44:
	ldr r0, _0802FF80
	mov r12, r0
	ldr r4, _0802FF84
	movs r3, 0
	movs r2, 0x3
_0802FF4E:
	mov r5, r12
	ldr r1, [r5]
	adds r1, r3
	adds r1, 0x6C
	adds r0, r4, 0
	ldm r0!, {r5-r7}
	stm r1!, {r5-r7}
	ldm r0!, {r5-r7}
	stm r1!, {r5-r7}
	adds r3, 0x18
	subs r2, 0x1
	cmp r2, 0
	bge _0802FF4E
_0802FF68:
	bl ResetUnusedInputStruct
	ldr r0, _0802FF80
	ldr r0, [r0]
	adds r0, 0x6C
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_0802FF80: .4byte gUnknown_203B318
_0802FF84: .4byte gUnknown_80E0760
	thumb_func_end sub_802FF1C

	thumb_func_start sub_802FF88
sub_802FF88:
	push {r4,r5,lr}
	sub sp, 0x18
	ldr r1, _0802FFA4
	ldr r0, [r1]
	ldr r0, [r0, 0x8]
	adds r5, r1, 0
	cmp r0, 0xD
	bls _0802FF9A
	b _080301A0
_0802FF9A:
	lsls r0, 2
	ldr r1, _0802FFA8
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0802FFA4: .4byte gUnknown_203B318
_0802FFA8: .4byte _0802FFAC
	.align 2, 0
_0802FFAC:
	.4byte _0802FFE4
	.4byte _08030000
	.4byte _08030038
	.4byte _08030050
	.4byte _08030068
	.4byte _08030074
	.4byte _080300DC
	.4byte _080300C4
	.4byte _080300F4
	.4byte _0803010C
	.4byte _08030148
	.4byte _08030174
	.4byte _08030180
	.4byte _080301A0
_0802FFE4:
	bl sub_80301B0
	ldr r2, _0802FFF8
	ldr r0, _0802FFFC
	ldr r5, [r0]
	ldr r1, [r5, 0x4]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 3
	b _0803000E
	.align 2, 0
_0802FFF8: .4byte gMakuhitaDialogue
_0802FFFC: .4byte gUnknown_203B318
_08030000:
	ldr r2, _08030034
	ldr r5, [r5]
	ldr r1, [r5, 0x4]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 3
	adds r2, 0x4
_0803000E:
	adds r0, r2
	ldr r0, [r0]
	ldr r2, [r5, 0x14]
	adds r3, r5, 0
	adds r3, 0x18
	movs r4, 0
	str r4, [sp]
	movs r1, 0x4
	str r1, [sp, 0x4]
	str r4, [sp, 0x8]
	ldr r1, [r5, 0x68]
	str r1, [sp, 0xC]
	movs r1, 0xC
	str r1, [sp, 0x10]
	movs r1, 0
	bl sub_8014248
	b _080301A0
	.align 2, 0
_08030034: .4byte gMakuhitaDialogue
_08030038:
	ldr r3, [r5]
	movs r0, 0xD
	str r0, [r3, 0xC]
	ldr r2, _0803004C
	ldr r1, [r3, 0x4]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 3
	adds r2, 0x8
	b _0803015A
	.align 2, 0
_0803004C: .4byte gMakuhitaDialogue
_08030050:
	ldr r3, [r5]
	movs r0, 0x4
	str r0, [r3, 0xC]
	ldr r2, _08030064
	ldr r1, [r3, 0x4]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 3
	adds r2, 0xC
	b _0803015A
	.align 2, 0
_08030064: .4byte gMakuhitaDialogue
_08030068:
	movs r0, 0x3
	movs r1, 0
	movs r2, 0xA
	bl sub_80302E8
	b _080301A0
_08030074:
	ldr r1, [r5]
	movs r0, 0xD
	str r0, [r1, 0xC]
	movs r2, 0x10
	ldrsh r0, [r1, r2]
	bl sub_80A2740
	lsls r0, 24
	lsrs r0, 24
	ldr r2, _080300B4
	ldr r1, [sp, 0x14]
	ands r1, r2
	orrs r1, r0
	ldr r0, _080300B8
	ands r1, r0
	movs r0, 0x80
	lsls r0, 1
	orrs r1, r0
	str r1, [sp, 0x14]
	ldr r0, _080300BC
	add r1, sp, 0x14
	bl sub_8090208
	ldr r2, _080300C0
	ldr r3, [r5]
	ldr r1, [r3, 0x4]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 3
	adds r2, 0x10
	b _0803015A
	.align 2, 0
_080300B4: .4byte 0xffffff00
_080300B8: .4byte 0xffff00ff
_080300BC: .4byte gAvailablePokemonNames
_080300C0: .4byte gMakuhitaDialogue
_080300C4:
	ldr r3, [r5]
	movs r0, 0xD
	str r0, [r3, 0xC]
	ldr r2, _080300D8
	ldr r1, [r3, 0x4]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 3
	adds r2, 0x18
	b _0803015A
	.align 2, 0
_080300D8: .4byte gMakuhitaDialogue
_080300DC:
	ldr r3, [r5]
	movs r0, 0xD
	str r0, [r3, 0xC]
	ldr r2, _080300F0
	ldr r1, [r3, 0x4]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 3
	adds r2, 0x14
	b _0803015A
	.align 2, 0
_080300F0: .4byte gMakuhitaDialogue
_080300F4:
	ldr r3, [r5]
	movs r0, 0x9
	str r0, [r3, 0xC]
	ldr r2, _08030108
	ldr r1, [r3, 0x4]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 3
	adds r2, 0x1C
	b _0803015A
	.align 2, 0
_08030108: .4byte gMakuhitaDialogue
_0803010C:
	ldr r4, _08030138
	bl sub_808D33C
	adds r1, r0, 0
	adds r0, r4, 0
	movs r2, 0x6
	bl sub_808D9AC
	ldr r0, _0803013C
	ldr r1, [r0]
	movs r0, 0xB
	str r0, [r1, 0xC]
	movs r0, 0xCB
	bl sub_8011988
	ldr r0, _08030140
	ldr r3, _08030144
	movs r1, 0
	movs r2, 0
	bl sub_80141B4
	b _080301A0
	.align 2, 0
_08030138: .4byte gPlayerName
_0803013C: .4byte gUnknown_203B318
_08030140: .4byte gUnknown_80E0778
_08030144: .4byte 0x00000101
_08030148:
	ldr r3, [r5]
	movs r0, 0xD
	str r0, [r3, 0xC]
	ldr r2, _0803016C
	ldr r1, [r3, 0x4]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 3
	adds r2, 0x20
_0803015A:
	adds r0, r2
	ldr r0, [r0]
	ldr r2, [r3, 0x68]
	ldr r3, _08030170
	movs r1, 0
	bl sub_80141B4
	b _080301A0
	.align 2, 0
_0803016C: .4byte gMakuhitaDialogue
_08030170: .4byte 0x0000010d
_08030174:
	movs r0, 0x1
	movs r1, 0x49
	movs r2, 0x1
	bl sub_801B60C
	b _080301A0
_08030180:
	ldr r3, [r5]
	movs r0, 0x1
	str r0, [r3, 0xC]
	ldr r2, _080301A8
	ldr r1, [r3, 0x4]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 3
	adds r2, 0x24
	adds r0, r2
	ldr r0, [r0]
	ldr r2, [r3, 0x68]
	ldr r3, _080301AC
	movs r1, 0
	bl sub_80141B4
_080301A0:
	add sp, 0x18
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_080301A8: .4byte gMakuhitaDialogue
_080301AC: .4byte 0x0000010d
	thumb_func_end sub_802FF88

	thumb_func_start sub_80301B0
sub_80301B0:
	push {r4,lr}
	ldr r4, _080301F8
	ldr r1, [r4]
	movs r2, 0x2
	str r2, [r1, 0x14]
	ldr r0, _080301FC
	str r0, [r1, 0x18]
	str r2, [r1, 0x1C]
	bl sub_80306A4
	lsls r0, 24
	cmp r0, 0
	beq _080301D6
	ldr r0, [r4]
	movs r1, 0x1
	negs r1, r1
	str r1, [r0, 0x1C]
	movs r1, 0x1
	str r1, [r0, 0x14]
_080301D6:
	ldr r1, [r4]
	movs r2, 0x1
	ldr r0, _08030200
	ldr r0, [r0]
	str r0, [r1, 0x20]
	movs r0, 0x3
	str r0, [r1, 0x24]
	ldr r0, _08030204
	ldr r0, [r0]
	str r0, [r1, 0x28]
	str r2, [r1, 0x2C]
	movs r0, 0
	str r0, [r1, 0x30]
	str r2, [r1, 0x34]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080301F8: .4byte gUnknown_203B318
_080301FC: .4byte gUnknown_80E07D8
_08030200: .4byte gUnknown_80D4970
_08030204: .4byte gUnknown_80D4934
	thumb_func_end sub_80301B0

	thumb_func_start sub_8030208
sub_8030208:
	push {lr}
	sub sp, 0x4
	mov r0, sp
	bl sub_80144A4
	cmp r0, 0
	bne _08030250
	ldr r0, _08030230
	ldr r1, [r0]
	ldr r0, [sp]
	str r0, [r1, 0x14]
	ldr r0, [sp]
	cmp r0, 0x2
	beq _0803023A
	cmp r0, 0x2
	bgt _08030234
	cmp r0, 0x1
	beq _0803024A
	b _08030250
	.align 2, 0
_08030230: .4byte gUnknown_203B318
_08030234:
	cmp r0, 0x3
	beq _08030242
	b _08030250
_0803023A:
	movs r0, 0x3
	bl sub_802FF04
	b _08030250
_08030242:
	movs r0, 0xC
	bl sub_802FF04
	b _08030250
_0803024A:
	movs r0, 0x2
	bl sub_802FF04
_08030250:
	add sp, 0x4
	pop {r0}
	bx r0
	thumb_func_end sub_8030208

	thumb_func_start sub_8030258
sub_8030258:
	push {lr}
	movs r0, 0x1
	bl sub_80303AC
	cmp r0, 0x2
	beq _08030288
	cmp r0, 0x2
	bcc _0803029A
	cmp r0, 0x3
	bne _0803029A
	bl sub_8030418
	ldr r1, _08030284
	ldr r1, [r1]
	strh r0, [r1, 0x10]
	bl sub_8030480
	movs r0, 0x5
	bl sub_802FF04
	b _0803029A
	.align 2, 0
_08030284: .4byte gUnknown_203B318
_08030288:
	bl sub_8030480
	ldr r0, _080302A0
	ldr r1, [r0]
	ldr r0, _080302A4
	strh r0, [r1, 0x10]
	movs r0, 0x1
	bl sub_802FF04
_0803029A:
	pop {r0}
	bx r0
	.align 2, 0
_080302A0: .4byte gUnknown_203B318
_080302A4: .4byte 0x0000ffff
	thumb_func_end sub_8030258

	thumb_func_start sub_80302A8
sub_80302A8:
	push {lr}
	bl sub_801B6AC
	cmp r0, 0x1
	bls _080302C0
	cmp r0, 0x3
	bhi _080302C0
	bl sub_801B72C
	movs r0, 0xA
	bl sub_802FF04
_080302C0:
	pop {r0}
	bx r0
	thumb_func_end sub_80302A8

	thumb_func_start sub_80302C4
sub_80302C4:
	push {lr}
	sub sp, 0x4
	mov r0, sp
	bl sub_80144A4
	cmp r0, 0
	bne _080302DC
	ldr r0, _080302E4
	ldr r0, [r0]
	ldr r0, [r0, 0xC]
	bl sub_802FF04
_080302DC:
	add sp, 0x4
	pop {r0}
	bx r0
	.align 2, 0
_080302E4: .4byte gUnknown_203B318
	thumb_func_end sub_80302C4

	thumb_func_start sub_80302E8
sub_80302E8:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	adds r5, r0, 0
	adds r6, r1, 0
	mov r8, r2
	bl sub_80306A4
	lsls r0, 24
	cmp r0, 0
	beq _08030302
	movs r0, 0
	b _0803039A
_08030302:
	ldr r4, _080303A4
	ldr r0, [r4]
	cmp r0, 0
	bne _08030314
	movs r0, 0xD0
	movs r1, 0x8
	bl MemoryAlloc
	str r0, [r4]
_08030314:
	ldr r0, [r4]
	str r5, [r0, 0x64]
	lsls r1, r5, 1
	adds r1, r5
	lsls r1, 3
	adds r1, 0x6C
	adds r1, r0, r1
	str r1, [r0, 0x68]
	adds r0, 0x6C
	bl sub_8006518
	ldr r1, [r4]
	ldr r2, [r1, 0x64]
	lsls r0, r2, 1
	adds r0, r2
	lsls r0, 3
	adds r1, r0
	adds r1, 0x6C
	ldr r0, _080303A8
	ldm r0!, {r2,r3,r7}
	stm r1!, {r2,r3,r7}
	ldm r0!, {r2,r3,r7}
	stm r1!, {r2,r3,r7}
	ldr r2, [r4]
	ldr r1, [r2, 0x68]
	adds r0, r2, 0
	adds r0, 0xCC
	str r0, [r1, 0x14]
	cmp r6, 0
	beq _08030362
	ldr r1, [r2, 0x64]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 3
	adds r1, r2, 0
	adds r1, 0x74
	adds r1, r0
	ldr r0, [r6]
	str r0, [r1]
_08030362:
	ldr r0, [r4]
	ldr r0, [r0, 0x68]
	mov r1, r8
	bl sub_8012D08
	bl ResetUnusedInputStruct
	ldr r0, [r4]
	adds r0, 0x6C
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	ldr r4, [r4]
	adds r4, 0x30
	bl sub_8030668
	adds r1, r0, 0
	adds r0, r4, 0
	mov r2, r8
	adds r3, r5, 0
	bl sub_8013818
	bl sub_80304C8
	bl sub_803053C
	movs r0, 0x1
_0803039A:
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r1}
	bx r1
	.align 2, 0
_080303A4: .4byte gUnknown_203B31C
_080303A8: .4byte gUnknown_80E0804
	thumb_func_end sub_80302E8

	thumb_func_start sub_80303AC
sub_80303AC:
	push {r4,lr}
	lsls r0, 24
	cmp r0, 0
	bne _080303C8
	ldr r0, _080303C4
	ldr r0, [r0]
	adds r0, 0x30
	bl sub_8013660
	movs r0, 0
	b _08030410
	.align 2, 0
_080303C4: .4byte gUnknown_203B31C
_080303C8:
	ldr r4, _080303E4
	ldr r0, [r4]
	adds r0, 0x30
	bl GetKeyPress
	cmp r0, 0x1
	beq _080303E8
	cmp r0, 0x2
	bne _080303F2
	movs r0, 0x1
	bl PlayMenuSoundEffect
	movs r0, 0x2
	b _08030410
	.align 2, 0
_080303E4: .4byte gUnknown_203B31C
_080303E8:
	movs r0, 0
	bl PlayMenuSoundEffect
	movs r0, 0x3
	b _08030410
_080303F2:
	ldr r0, [r4]
	adds r0, 0x30
	movs r1, 0x1
	bl sub_80138B8
	lsls r0, 24
	cmp r0, 0
	bne _08030406
	movs r0, 0
	b _08030410
_08030406:
	bl sub_80304C8
	bl sub_803053C
	movs r0, 0x1
_08030410:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_80303AC

	thumb_func_start sub_8030418
sub_8030418:
	ldr r0, _08030440
	ldr r2, [r0]
	adds r0, r2, 0
	adds r0, 0x4E
	movs r3, 0
	ldrsh r1, [r0, r3]
	subs r0, 0x2
	movs r3, 0
	ldrsh r0, [r0, r3]
	muls r0, r1
	adds r1, r2, 0
	adds r1, 0x48
	movs r3, 0
	ldrsh r1, [r1, r3]
	adds r0, r1
	lsls r0, 1
	adds r0, r2, r0
	movs r1, 0
	ldrsh r0, [r0, r1]
	bx lr
	.align 2, 0
_08030440: .4byte gUnknown_203B31C
	thumb_func_end sub_8030418

	thumb_func_start sub_8030444
sub_8030444:
	push {r4,r5,lr}
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	bl sub_8030668
	adds r1, r0, 0
	ldr r5, _0803047C
	ldr r0, [r5]
	adds r2, r0, 0
	adds r2, 0x52
	strh r1, [r2]
	adds r0, 0x30
	bl sub_8013984
	bl sub_80304C8
	bl sub_803053C
	cmp r4, 0
	beq _08030476
	ldr r0, [r5]
	adds r0, 0x30
	bl AddMenuCursorSprite
_08030476:
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_0803047C: .4byte gUnknown_203B31C
	thumb_func_end sub_8030444

	thumb_func_start sub_8030480
sub_8030480:
	push {r4,r5,lr}
	ldr r4, _080304C0
	ldr r2, [r4]
	cmp r2, 0
	beq _080304BA
	ldr r0, [r2, 0x64]
	lsls r1, r0, 1
	adds r1, r0
	lsls r1, 3
	adds r1, r2, r1
	adds r1, 0x6C
	ldr r0, _080304C4
	ldm r0!, {r2,r3,r5}
	stm r1!, {r2,r3,r5}
	ldm r0!, {r2,r3,r5}
	stm r1!, {r2,r3,r5}
	bl ResetUnusedInputStruct
	ldr r0, [r4]
	adds r0, 0x6C
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	ldr r0, [r4]
	bl MemoryFree
	movs r0, 0
	str r0, [r4]
_080304BA:
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_080304C0: .4byte gUnknown_203B31C
_080304C4: .4byte gUnknown_80E07EC
	thumb_func_end sub_8030480

	thumb_func_start sub_80304C8
sub_80304C8:
	push {r4,lr}
	ldr r4, _08030538
	ldr r0, [r4]
	adds r0, 0xCC
	movs r2, 0
	movs r1, 0x1
	strb r1, [r0]
	ldr r0, [r4]
	adds r0, 0xCD
	strb r2, [r0]
	ldr r0, [r4]
	adds r0, 0xCE
	movs r1, 0x8
	strb r1, [r0]
	ldr r0, [r4]
	adds r0, 0xCF
	strb r2, [r0]
	ldr r0, [r4]
	adds r0, 0x4A
	movs r1, 0
	ldrsh r0, [r0, r1]
	movs r1, 0xC
	bl sub_80095E4
	adds r0, 0x2
	lsls r0, 16
	ldr r2, [r4]
	ldr r3, [r2, 0x64]
	lsls r1, r3, 1
	adds r1, r3
	lsls r1, 3
	adds r1, r2, r1
	adds r1, 0x7A
	asrs r3, r0, 16
	lsrs r0, 16
	strh r0, [r1]
	ldr r1, [r2, 0x64]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 3
	adds r2, r0
	adds r3, 0x2
	adds r2, 0x7C
	strh r3, [r2]
	bl ResetUnusedInputStruct
	ldr r0, [r4]
	adds r0, 0x6C
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08030538: .4byte gUnknown_203B31C
	thumb_func_end sub_80304C8

	thumb_func_start sub_803053C
sub_803053C:
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	sub sp, 0x108
	ldr r4, _08030658
	ldr r0, [r4]
	ldr r0, [r0, 0x64]
	bl sub_8008C54
	ldr r0, [r4]
	ldr r0, [r0, 0x64]
	bl sub_80073B8
	ldr r2, _0803065C
	ldr r0, [r4]
	ldr r3, [r0, 0x64]
	movs r0, 0
	str r0, [sp]
	movs r0, 0xA
	movs r1, 0
	bl xxx_call_draw_string
	ldr r3, [r4]
	adds r0, r3, 0
	adds r0, 0xCE
	ldrb r0, [r0]
	lsls r0, 3
	adds r0, 0x4
	adds r1, r3, 0
	adds r1, 0x4E
	movs r5, 0
	ldrsh r2, [r1, r5]
	adds r2, 0x1
	movs r1, 0x7
	str r1, [sp]
	ldr r1, [r3, 0x64]
	str r1, [sp, 0x4]
	movs r1, 0
	movs r3, 0x2
	bl sub_8012BC4
	movs r0, 0
	mov r9, r0
	ldr r0, [r4]
	adds r0, 0x4A
	movs r1, 0
	ldrsh r0, [r0, r1]
	cmp r9, r0
	bge _0803063E
	mov r8, r4
_080305A2:
	mov r3, r8
	ldr r1, [r3]
	adds r0, r1, 0
	adds r0, 0x4E
	movs r5, 0
	ldrsh r2, [r0, r5]
	subs r0, 0x2
	movs r3, 0
	ldrsh r0, [r0, r3]
	muls r0, r2
	add r0, r9
	lsls r0, 1
	adds r1, r0
	movs r5, 0
	ldrsh r4, [r1, r5]
	adds r0, r4, 0
	bl sub_80A2740
	lsls r0, 24
	lsrs r7, r0, 24
	adds r0, r4, 0
	bl sub_80A2668
	adds r4, r0, 0
	lsls r4, 16
	asrs r4, 16
	mov r1, r8
	ldr r0, [r1]
	adds r0, 0x30
	mov r1, r9
	bl sub_8013800
	adds r6, r0, 0
	movs r5, 0x7
	adds r0, r4, 0
	bl sub_809758C
	lsls r0, 24
	cmp r0, 0
	beq _08030608
	mov r3, r8
	ldr r0, [r3]
	ldr r3, [r0, 0x64]
	movs r0, 0
	str r0, [sp]
	movs r0, 0x8
	adds r1, r6, 0
	ldr r2, _08030660
	bl xxx_call_draw_string
	movs r5, 0x4
_08030608:
	adds r0, r7, 0
	bl GetDungeonName1
	adds r3, r0, 0
	add r0, sp, 0x8
	ldr r1, _08030664
	adds r2, r5, 0
	bl sub_800D158
	mov r5, r8
	ldr r0, [r5]
	ldr r3, [r0, 0x64]
	movs r0, 0
	str r0, [sp]
	movs r0, 0x10
	adds r1, r6, 0
	add r2, sp, 0x8
	bl xxx_call_draw_string
	movs r0, 0x1
	add r9, r0
	ldr r0, [r5]
	adds r0, 0x4A
	movs r1, 0
	ldrsh r0, [r0, r1]
	cmp r9, r0
	blt _080305A2
_0803063E:
	ldr r0, _08030658
	ldr r0, [r0]
	ldr r0, [r0, 0x64]
	bl sub_80073E0
	add sp, 0x108
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_08030658: .4byte gUnknown_203B31C
_0803065C: .4byte gUnknown_80E081C
_08030660: .4byte gUnknown_80E0824
_08030664: .4byte gUnknown_80E0828
	thumb_func_end sub_803053C

	thumb_func_start sub_8030668
sub_8030668:
	push {r4-r6,lr}
	movs r6, 0
	movs r5, 0
_0803066E:
	lsls r0, r5, 16
	asrs r4, r0, 16
	adds r0, r4, 0
	bl sub_8097504
	lsls r0, 24
	cmp r0, 0
	beq _08030690
	adds r0, r4, 0
	bl sub_80A26CC
	ldr r1, _080306A0
	ldr r1, [r1]
	lsls r2, r6, 1
	adds r1, r2
	strh r0, [r1]
	adds r6, 0x1
_08030690:
	adds r5, 0x1
	cmp r5, 0x16
	ble _0803066E
	adds r0, r6, 0
	pop {r4-r6}
	pop {r1}
	bx r1
	.align 2, 0
_080306A0: .4byte gUnknown_203B31C
	thumb_func_end sub_8030668

	thumb_func_start sub_80306A4
sub_80306A4:
	movs r0, 0
	bx lr
	thumb_func_end sub_80306A4

	thumb_func_start sub_80306A8
sub_80306A8:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	adds r4, r0, 0
	adds r5, r1, 0
	adds r7, r2, 0
	mov r8, r3
	bl sub_8030C20
	lsls r0, 24
	cmp r0, 0
	beq _080306C4
	movs r0, 0
	b _08030756
_080306C4:
	ldr r6, _08030760
	movs r0, 0xC4
	movs r1, 0x8
	bl MemoryAlloc
	str r0, [r6]
	str r4, [r0, 0x20]
	str r5, [r0, 0x58]
	lsls r1, r5, 1
	adds r1, r5
	lsls r1, 3
	adds r1, 0x60
	adds r1, r0, r1
	str r1, [r0, 0x5C]
	adds r0, 0x60
	bl sub_8006518
	ldr r1, [r6]
	ldr r2, [r1, 0x58]
	lsls r0, r2, 1
	adds r0, r2
	lsls r0, 3
	adds r1, r0
	adds r1, 0x60
	ldr r0, _08030764
	ldm r0!, {r2-r4}
	stm r1!, {r2-r4}
	ldm r0!, {r2-r4}
	stm r1!, {r2-r4}
	ldr r2, [r6]
	ldr r1, [r2, 0x5C]
	adds r0, r2, 0
	adds r0, 0xC0
	str r0, [r1, 0x14]
	cmp r7, 0
	beq _0803071E
	ldr r1, [r2, 0x58]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 3
	adds r1, r2, 0
	adds r1, 0x68
	adds r1, r0
	ldr r0, [r7]
	str r0, [r1]
_0803071E:
	ldr r0, [r6]
	ldr r0, [r0, 0x5C]
	mov r1, r8
	bl sub_8012D08
	bl ResetUnusedInputStruct
	ldr r0, [r6]
	adds r0, 0x60
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	ldr r4, [r6]
	adds r4, 0x24
	bl sub_8030A74
	adds r1, r0, 0
	adds r0, r4, 0
	mov r2, r8
	adds r3, r5, 0
	bl sub_8013818
	bl sub_80308A0
	bl sub_803092C
	movs r0, 0x1
_08030756:
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r1}
	bx r1
	.align 2, 0
_08030760: .4byte gUnknown_203B320
_08030764: .4byte gUnknown_80E0854
	thumb_func_end sub_80306A8

	thumb_func_start sub_8030768
sub_8030768:
	push {lr}
	lsls r0, 24
	cmp r0, 0
	bne _08030784
	ldr r0, _08030780
	ldr r0, [r0]
	adds r0, 0x24
	bl sub_8013660
	movs r0, 0
	b _080307E6
	.align 2, 0
_08030780: .4byte gUnknown_203B320
_08030784:
	ldr r0, _0803079C
	ldr r0, [r0]
	adds r0, 0x24
	bl GetKeyPress
	cmp r0, 0x2
	beq _080307AE
	cmp r0, 0x2
	bgt _080307A0
	cmp r0, 0x1
	beq _080307B8
	b _080307C2
	.align 2, 0
_0803079C: .4byte gUnknown_203B320
_080307A0:
	cmp r0, 0x4
	bne _080307C2
	movs r0, 0x4
	bl PlayMenuSoundEffect
	movs r0, 0x4
	b _080307E6
_080307AE:
	movs r0, 0x1
	bl PlayMenuSoundEffect
	movs r0, 0x2
	b _080307E6
_080307B8:
	movs r0, 0
	bl PlayMenuSoundEffect
	movs r0, 0x3
	b _080307E6
_080307C2:
	ldr r0, _080307D8
	ldr r0, [r0]
	adds r0, 0x24
	movs r1, 0x1
	bl sub_80138B8
	lsls r0, 24
	cmp r0, 0
	bne _080307DC
	movs r0, 0
	b _080307E6
	.align 2, 0
_080307D8: .4byte gUnknown_203B320
_080307DC:
	bl sub_80308A0
	bl sub_803092C
	movs r0, 0x1
_080307E6:
	pop {r1}
	bx r1
	thumb_func_end sub_8030768

	thumb_func_start sub_80307EC
sub_80307EC:
	ldr r0, _0803080C
	ldr r2, [r0]
	adds r0, r2, 0
	adds r0, 0x42
	movs r3, 0
	ldrsh r1, [r0, r3]
	subs r0, 0x2
	movs r3, 0
	ldrsh r0, [r0, r3]
	muls r0, r1
	movs r3, 0x3C
	ldrsh r1, [r2, r3]
	adds r0, r1
	adds r2, r0
	ldrb r0, [r2]
	bx lr
	.align 2, 0
_0803080C: .4byte gUnknown_203B320
	thumb_func_end sub_80307EC

	thumb_func_start sub_8030810
sub_8030810:
	push {r4,r5,lr}
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	bl sub_8030A74
	adds r1, r0, 0
	ldr r5, _08030848
	ldr r0, [r5]
	adds r2, r0, 0
	adds r2, 0x46
	strh r1, [r2]
	adds r0, 0x24
	bl sub_8013984
	bl sub_80308A0
	bl sub_803092C
	cmp r4, 0
	beq _08030842
	ldr r0, [r5]
	adds r0, 0x24
	bl AddMenuCursorSprite
_08030842:
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_08030848: .4byte gUnknown_203B320
	thumb_func_end sub_8030810

	thumb_func_start sub_803084C
sub_803084C:
	push {r4,r5,lr}
	ldr r4, _0803088C
	ldr r2, [r4]
	cmp r2, 0
	beq _08030886
	ldr r0, [r2, 0x58]
	lsls r1, r0, 1
	adds r1, r0
	lsls r1, 3
	adds r1, r2, r1
	adds r1, 0x60
	ldr r0, _08030890
	ldm r0!, {r2,r3,r5}
	stm r1!, {r2,r3,r5}
	ldm r0!, {r2,r3,r5}
	stm r1!, {r2,r3,r5}
	bl ResetUnusedInputStruct
	ldr r0, [r4]
	adds r0, 0x60
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	ldr r0, [r4]
	bl MemoryFree
	movs r0, 0
	str r0, [r4]
_08030886:
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_0803088C: .4byte gUnknown_203B320
_08030890: .4byte gUnknown_80E083C
	thumb_func_end sub_803084C

	thumb_func_start sub_8030894
sub_8030894:
	ldr r0, _0803089C
	ldr r0, [r0]
	bx lr
	.align 2, 0
_0803089C: .4byte gUnknown_203B320
	thumb_func_end sub_8030894

	thumb_func_start sub_80308A0
sub_80308A0:
	push {r4,lr}
	ldr r4, _08030928
	ldr r0, [r4]
	adds r1, r0, 0
	adds r1, 0x44
	ldrh r1, [r1]
	adds r0, 0xC0
	movs r2, 0
	strb r1, [r0]
	ldr r0, [r4]
	adds r1, r0, 0
	adds r1, 0x42
	ldrh r1, [r1]
	adds r0, 0xC1
	strb r1, [r0]
	ldr r0, [r4]
	adds r0, 0xC2
	movs r1, 0xC
	strb r1, [r0]
	ldr r0, [r4]
	adds r0, 0xC3
	strb r2, [r0]
	bl ResetUnusedInputStruct
	ldr r0, [r4]
	adds r0, 0x60
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	ldr r0, [r4]
	movs r1, 0x3E
	ldrsh r0, [r0, r1]
	movs r1, 0xC
	bl sub_80095E4
	adds r0, 0x2
	lsls r0, 16
	ldr r2, [r4]
	ldr r3, [r2, 0x58]
	lsls r1, r3, 1
	adds r1, r3
	lsls r1, 3
	adds r1, r2, r1
	adds r1, 0x6E
	asrs r3, r0, 16
	lsrs r0, 16
	strh r0, [r1]
	ldr r1, [r2, 0x58]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 3
	adds r2, r0
	adds r3, 0x2
	adds r2, 0x70
	strh r3, [r2]
	bl ResetUnusedInputStruct
	ldr r0, [r4]
	adds r0, 0x60
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08030928: .4byte gUnknown_203B320
	thumb_func_end sub_80308A0

	thumb_func_start sub_803092C
sub_803092C:
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	sub sp, 0x60
	ldr r7, _08030A24
	ldr r0, [r7]
	ldr r0, [r0, 0x58]
	bl sub_8008C54
	ldr r0, [r7]
	ldr r0, [r0, 0x58]
	bl sub_80073B8
	ldr r1, [r7]
	adds r0, r1, 0
	adds r0, 0x42
	movs r2, 0
	ldrsh r4, [r0, r2]
	lsls r4, 3
	adds r5, r4, 0
	adds r5, 0xA
	ldr r2, _08030A28
	ldr r0, [r1, 0x20]
	lsls r0, 2
	adds r0, r2
	ldr r2, [r0]
	ldr r3, [r1, 0x58]
	movs r0, 0
	str r0, [sp]
	adds r0, r5, 0
	movs r1, 0
	bl xxx_call_draw_string
	adds r4, 0x4
	ldr r3, [r7]
	adds r0, r3, 0
	adds r0, 0xC2
	ldrb r0, [r0]
	lsls r0, 3
	adds r5, r4, r0
	adds r0, r3, 0
	adds r0, 0x42
	movs r1, 0
	ldrsh r2, [r0, r1]
	adds r2, 0x1
	movs r0, 0x7
	str r0, [sp]
	ldr r0, [r3, 0x58]
	str r0, [sp, 0x4]
	adds r0, r5, 0
	movs r1, 0
	movs r3, 0x1
	bl sub_8012BC4
	movs r6, 0
	ldr r0, [r7]
	movs r2, 0x3E
	ldrsh r0, [r0, r2]
	cmp r6, r0
	bge _08030A56
	mov r9, r7
	mov r8, r6
	add r7, sp, 0x8
	mov r5, sp
	adds r5, 0x4B
_080309B0:
	mov r3, r9
	ldr r1, [r3]
	adds r0, r1, 0
	adds r0, 0x42
	movs r3, 0
	ldrsh r2, [r0, r3]
	subs r0, 0x2
	movs r3, 0
	ldrsh r0, [r0, r3]
	muls r0, r2
	adds r0, r6
	adds r1, r0
	ldrb r0, [r1]
	bl sub_8095228
	adds r4, r0, 0
	mov r1, r9
	ldr r0, [r1]
	ldr r1, [r0, 0x58]
	str r1, [sp, 0x8]
	adds r0, 0x24
	adds r1, r6, 0
	bl sub_8013800
	str r0, [sp, 0x50]
	add r1, sp, 0x48
	movs r0, 0x7
	strb r0, [r1]
	mov r0, sp
	adds r0, 0x4A
	mov r2, r8
	strb r2, [r0]
	add r0, sp, 0x4C
	strb r2, [r0]
	adds r0, r4, 0x4
	str r0, [sp, 0x10]
	adds r0, 0x10
	str r0, [sp, 0x14]
	ldrh r0, [r4, 0xC]
	strh r0, [r7, 0x10]
	ldrh r0, [r4, 0xC]
	strh r0, [r7, 0x12]
	strb r2, [r7, 0x14]
	subs r1, 0x12
	movs r0, 0x5
	strb r0, [r1]
	ldrb r0, [r4]
	cmp r0, 0x4
	beq _08030A32
	cmp r0, 0x4
	bgt _08030A2C
	cmp r0, 0x2
	bgt _08030A3E
	cmp r0, 0x1
	blt _08030A3E
	movs r0, 0x1
	strb r0, [r5]
	b _08030A42
	.align 2, 0
_08030A24: .4byte gUnknown_203B320
_08030A28: .4byte gUnknown_80E086C
_08030A2C:
	cmp r0, 0x5
	beq _08030A38
	b _08030A3E
_08030A32:
	movs r0, 0x3
	strb r0, [r5]
	b _08030A42
_08030A38:
	movs r0, 0x4
	strb r0, [r5]
	b _08030A42
_08030A3E:
	mov r3, r8
	strb r3, [r5]
_08030A42:
	add r0, sp, 0x8
	bl sub_803B6D4
	adds r6, 0x1
	mov r1, r9
	ldr r0, [r1]
	movs r2, 0x3E
	ldrsh r0, [r0, r2]
	cmp r6, r0
	blt _080309B0
_08030A56:
	ldr r0, _08030A70
	ldr r0, [r0]
	ldr r0, [r0, 0x58]
	bl sub_80073E0
	add sp, 0x60
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_08030A70: .4byte gUnknown_203B320
	thumb_func_end sub_803092C

	thumb_func_start sub_8030A74
sub_8030A74:
	push {r4,r5,lr}
	movs r2, 0
	ldr r0, _08030A90
	ldr r0, [r0]
	ldr r0, [r0, 0x20]
	cmp r0, 0x7
	bls _08030A84
	b _08030C0E
_08030A84:
	lsls r0, 2
	ldr r1, _08030A94
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08030A90: .4byte gUnknown_203B320
_08030A94: .4byte _08030A98
	.align 2, 0
_08030A98:
	.4byte _08030AB8
	.4byte _08030B10
	.4byte _08030B3C
	.4byte _08030B94
	.4byte _08030B68
	.4byte _08030BC0
	.4byte _08030AE4
	.4byte _08030BEC
_08030AB8:
	movs r1, 0
	ldr r5, _08030ADC
	ldr r4, _08030AE0
	movs r3, 0
_08030AC0:
	ldr r0, [r5]
	adds r0, r3
	ldrb r0, [r0]
	cmp r0, 0
	beq _08030AD2
	ldr r0, [r4]
	adds r0, r2
	strb r1, [r0]
	adds r2, 0x1
_08030AD2:
	adds r3, 0x30
	adds r1, 0x1
	cmp r1, 0x1F
	ble _08030AC0
	b _08030C0E
	.align 2, 0
_08030ADC: .4byte gUnknown_203B480
_08030AE0: .4byte gUnknown_203B320
_08030AE4:
	movs r1, 0
	ldr r5, _08030B08
	ldr r4, _08030B0C
	movs r3, 0
_08030AEC:
	ldr r0, [r5]
	adds r0, r3
	ldrb r0, [r0]
	cmp r0, 0x6
	bne _08030AFE
	ldr r0, [r4]
	adds r0, r2
	strb r1, [r0]
	adds r2, 0x1
_08030AFE:
	adds r3, 0x30
	adds r1, 0x1
	cmp r1, 0x1F
	ble _08030AEC
	b _08030C0E
	.align 2, 0
_08030B08: .4byte gUnknown_203B480
_08030B0C: .4byte gUnknown_203B320
_08030B10:
	movs r1, 0
	ldr r5, _08030B34
	ldr r4, _08030B38
	movs r3, 0
_08030B18:
	ldr r0, [r5]
	adds r0, r3
	ldrb r0, [r0]
	cmp r0, 0x1
	bne _08030B2A
	ldr r0, [r4]
	adds r0, r2
	strb r1, [r0]
	adds r2, 0x1
_08030B2A:
	adds r3, 0x30
	adds r1, 0x1
	cmp r1, 0x1F
	ble _08030B18
	b _08030C0E
	.align 2, 0
_08030B34: .4byte gUnknown_203B480
_08030B38: .4byte gUnknown_203B320
_08030B3C:
	movs r1, 0
	ldr r5, _08030B60
	ldr r4, _08030B64
	movs r3, 0
_08030B44:
	ldr r0, [r5]
	adds r0, r3
	ldrb r0, [r0]
	cmp r0, 0x2
	bne _08030B56
	ldr r0, [r4]
	adds r0, r2
	strb r1, [r0]
	adds r2, 0x1
_08030B56:
	adds r3, 0x30
	adds r1, 0x1
	cmp r1, 0x1F
	ble _08030B44
	b _08030C0E
	.align 2, 0
_08030B60: .4byte gUnknown_203B480
_08030B64: .4byte gUnknown_203B320
_08030B68:
	movs r1, 0
	ldr r5, _08030B8C
	ldr r4, _08030B90
	movs r3, 0
_08030B70:
	ldr r0, [r5]
	adds r0, r3
	ldrb r0, [r0]
	cmp r0, 0x4
	bne _08030B82
	ldr r0, [r4]
	adds r0, r2
	strb r1, [r0]
	adds r2, 0x1
_08030B82:
	adds r3, 0x30
	adds r1, 0x1
	cmp r1, 0x1F
	ble _08030B70
	b _08030C0E
	.align 2, 0
_08030B8C: .4byte gUnknown_203B480
_08030B90: .4byte gUnknown_203B320
_08030B94:
	movs r1, 0
	ldr r5, _08030BB8
	ldr r4, _08030BBC
	movs r3, 0
_08030B9C:
	ldr r0, [r5]
	adds r0, r3
	ldrb r0, [r0]
	cmp r0, 0x3
	bne _08030BAE
	ldr r0, [r4]
	adds r0, r2
	strb r1, [r0]
	adds r2, 0x1
_08030BAE:
	adds r3, 0x30
	adds r1, 0x1
	cmp r1, 0x1F
	ble _08030B9C
	b _08030C0E
	.align 2, 0
_08030BB8: .4byte gUnknown_203B480
_08030BBC: .4byte gUnknown_203B320
_08030BC0:
	movs r1, 0
	ldr r5, _08030BE4
	ldr r4, _08030BE8
	movs r3, 0
_08030BC8:
	ldr r0, [r5]
	adds r0, r3
	ldrb r0, [r0]
	cmp r0, 0x5
	bne _08030BDA
	ldr r0, [r4]
	adds r0, r2
	strb r1, [r0]
	adds r2, 0x1
_08030BDA:
	adds r3, 0x30
	adds r1, 0x1
	cmp r1, 0x1F
	ble _08030BC8
	b _08030C0E
	.align 2, 0
_08030BE4: .4byte gUnknown_203B480
_08030BE8: .4byte gUnknown_203B320
_08030BEC:
	movs r1, 0
	ldr r5, _08030C18
	ldr r4, _08030C1C
	movs r3, 0
_08030BF4:
	ldr r0, [r5]
	adds r0, r3
	ldrb r0, [r0]
	cmp r0, 0x7
	bne _08030C06
	ldr r0, [r4]
	adds r0, r2
	strb r1, [r0]
	adds r2, 0x1
_08030C06:
	adds r3, 0x30
	adds r1, 0x1
	cmp r1, 0x1F
	ble _08030BF4
_08030C0E:
	adds r0, r2, 0
	pop {r4,r5}
	pop {r1}
	bx r1
	.align 2, 0
_08030C18: .4byte gUnknown_203B480
_08030C1C: .4byte gUnknown_203B320
	thumb_func_end sub_8030A74

	thumb_func_start sub_8030C20
sub_8030C20:
	push {lr}
	cmp r0, 0x7
	bls _08030C28
	b _08030D34
_08030C28:
	lsls r0, 2
	ldr r1, _08030C34
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08030C34: .4byte _08030C38
	.align 2, 0
_08030C38:
	.4byte _08030C58
	.4byte _08030C90
	.4byte _08030CAC
	.4byte _08030CE4
	.4byte _08030CC8
	.4byte _08030D00
	.4byte _08030C74
	.4byte _08030D20
_08030C58:
	movs r1, 0
	ldr r0, _08030C70
	ldr r2, [r0]
_08030C5E:
	ldrb r0, [r2]
	cmp r0, 0
	bne _08030D1C
	adds r2, 0x30
	adds r1, 0x1
	cmp r1, 0x1F
	ble _08030C5E
	b _08030D34
	.align 2, 0
_08030C70: .4byte gUnknown_203B480
_08030C74:
	movs r1, 0
	ldr r0, _08030C8C
	ldr r2, [r0]
_08030C7A:
	ldrb r0, [r2]
	cmp r0, 0x6
	beq _08030D1C
	adds r2, 0x30
	adds r1, 0x1
	cmp r1, 0x1F
	ble _08030C7A
	b _08030D34
	.align 2, 0
_08030C8C: .4byte gUnknown_203B480
_08030C90:
	movs r1, 0
	ldr r0, _08030CA8
	ldr r2, [r0]
_08030C96:
	ldrb r0, [r2]
	cmp r0, 0x1
	beq _08030D1C
	adds r2, 0x30
	adds r1, 0x1
	cmp r1, 0x1F
	ble _08030C96
	b _08030D34
	.align 2, 0
_08030CA8: .4byte gUnknown_203B480
_08030CAC:
	movs r1, 0
	ldr r0, _08030CC4
	ldr r2, [r0]
_08030CB2:
	ldrb r0, [r2]
	cmp r0, 0x2
	beq _08030D1C
	adds r2, 0x30
	adds r1, 0x1
	cmp r1, 0x1F
	ble _08030CB2
	b _08030D34
	.align 2, 0
_08030CC4: .4byte gUnknown_203B480
_08030CC8:
	movs r1, 0
	ldr r0, _08030CE0
	ldr r2, [r0]
_08030CCE:
	ldrb r0, [r2]
	cmp r0, 0x4
	beq _08030D1C
	adds r2, 0x30
	adds r1, 0x1
	cmp r1, 0x1F
	ble _08030CCE
	b _08030D34
	.align 2, 0
_08030CE0: .4byte gUnknown_203B480
_08030CE4:
	movs r1, 0
	ldr r0, _08030CFC
	ldr r2, [r0]
_08030CEA:
	ldrb r0, [r2]
	cmp r0, 0x3
	beq _08030D1C
	adds r2, 0x30
	adds r1, 0x1
	cmp r1, 0x1F
	ble _08030CEA
	b _08030D34
	.align 2, 0
_08030CFC: .4byte gUnknown_203B480
_08030D00:
	movs r1, 0
	ldr r0, _08030D18
	ldr r2, [r0]
_08030D06:
	ldrb r0, [r2]
	cmp r0, 0x5
	beq _08030D1C
	adds r2, 0x30
	adds r1, 0x1
	cmp r1, 0x1F
	ble _08030D06
	b _08030D34
	.align 2, 0
_08030D18: .4byte gUnknown_203B480
_08030D1C:
	movs r0, 0
	b _08030D36
_08030D20:
	movs r1, 0
	ldr r0, _08030D3C
	ldr r2, [r0]
_08030D26:
	ldrb r0, [r2]
	cmp r0, 0x7
	beq _08030D1C
	adds r2, 0x30
	adds r1, 0x1
	cmp r1, 0x1F
	ble _08030D26
_08030D34:
	movs r0, 0x1
_08030D36:
	pop {r1}
	bx r1
	.align 2, 0
_08030D3C: .4byte gUnknown_203B480
	thumb_func_end sub_8030C20

	thumb_func_start sub_8030D40
sub_8030D40:
	push {r4-r6,lr}
	adds r4, r0, 0
	adds r5, r1, 0
	lsls r4, 24
	lsrs r4, 24
	ldr r6, _08030D98
	movs r0, 0x78
	movs r1, 0x8
	bl MemoryAlloc
	str r0, [r6]
	strb r4, [r0, 0xC]
	ldr r0, [r6]
	bl sub_801317C
	ldr r0, [r6]
	str r5, [r0, 0x10]
	lsls r1, r5, 1
	adds r1, r5
	lsls r1, 3
	adds r1, 0x18
	adds r1, r0, r1
	str r1, [r0, 0x14]
	adds r0, 0x18
	bl sub_8006518
	ldr r1, [r6]
	ldr r2, [r1, 0x10]
	lsls r0, r2, 1
	adds r0, r2
	lsls r0, 3
	adds r1, r0
	adds r1, 0x18
	ldr r0, _08030D9C
	ldm r0!, {r2-r4}
	stm r1!, {r2-r4}
	ldm r0!, {r2-r4}
	stm r1!, {r2-r4}
	bl sub_8030DD4
	movs r0, 0x1
	pop {r4-r6}
	pop {r1}
	bx r1
	.align 2, 0
_08030D98: .4byte gUnknown_203B324
_08030D9C: .4byte gUnknown_80E091C
	thumb_func_end sub_8030D40

	thumb_func_start sub_8030DA0
sub_8030DA0:
	push {lr}
	ldr r0, _08030DC0
	ldr r0, [r0]
	ldr r1, [r0, 0x10]
	bl sub_8012A64
	cmp r0, 0x1
	beq _08030DC4
	cmp r0, 0x2
	bne _08030DCE
	movs r0, 0x1
	bl PlayMenuSoundEffect
	movs r0, 0x2
	b _08030DD0
	.align 2, 0
_08030DC0: .4byte gUnknown_203B324
_08030DC4:
	movs r0, 0
	bl PlayMenuSoundEffect
	movs r0, 0x3
	b _08030DD0
_08030DCE:
	movs r0, 0
_08030DD0:
	pop {r1}
	bx r1
	thumb_func_end sub_8030DA0

	thumb_func_start sub_8030DD4
sub_8030DD4:
	push {lr}
	bl sub_8030E2C
	bl sub_8030E48
	pop {r0}
	bx r0
	thumb_func_end sub_8030DD4

	thumb_func_start sub_8030DE4
sub_8030DE4:
	push {r4,r5,lr}
	ldr r4, _08030E24
	ldr r2, [r4]
	cmp r2, 0
	beq _08030E1E
	ldr r0, [r2, 0x10]
	lsls r1, r0, 1
	adds r1, r0
	lsls r1, 3
	adds r1, r2, r1
	adds r1, 0x18
	ldr r0, _08030E28
	ldm r0!, {r2,r3,r5}
	stm r1!, {r2,r3,r5}
	ldm r0!, {r2,r3,r5}
	stm r1!, {r2,r3,r5}
	bl ResetUnusedInputStruct
	ldr r0, [r4]
	adds r0, 0x18
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	ldr r0, [r4]
	bl MemoryFree
	movs r0, 0
	str r0, [r4]
_08030E1E:
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_08030E24: .4byte gUnknown_203B324
_08030E28: .4byte gUnknown_80E0900
	thumb_func_end sub_8030DE4

	thumb_func_start sub_8030E2C
sub_8030E2C:
	push {lr}
	bl ResetUnusedInputStruct
	ldr r0, _08030E44
	ldr r0, [r0]
	adds r0, 0x18
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	pop {r0}
	bx r0
	.align 2, 0
_08030E44: .4byte gUnknown_203B324
	thumb_func_end sub_8030E2C

	thumb_func_start sub_8030E48
sub_8030E48:
	push {r4-r6,lr}
	mov r6, r8
	push {r6}
	sub sp, 0x15C
	ldr r3, _08030EA8
	ldr r4, _08030EAC
	ldr r2, [r4]
	ldrb r1, [r2, 0xC]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 4
	ldr r1, [r3]
	adds r5, r1, r0
	ldr r0, [r2, 0x10]
	bl sub_80073B8
	ldr r0, [r4]
	ldr r0, [r0, 0x10]
	str r0, [sp, 0x4]
	add r1, sp, 0x44
	movs r2, 0
	movs r0, 0x7
	strb r0, [r1]
	mov r0, sp
	adds r0, 0x46
	strb r2, [r0]
	add r0, sp, 0x48
	strb r2, [r0]
	adds r0, r5, 0x4
	str r0, [sp, 0xC]
	adds r0, 0x10
	str r0, [sp, 0x10]
	add r1, sp, 0x4
	ldrh r0, [r5, 0xC]
	strh r0, [r1, 0x10]
	ldrh r0, [r5, 0xC]
	strh r0, [r1, 0x12]
	adds r0, r1, 0
	strb r2, [r0, 0x14]
	adds r2, r5, 0
	adds r2, 0x22
	ldrb r0, [r2]
	cmp r0, 0
	bne _08030EB0
	adds r1, 0x2E
	movs r0, 0x5
	strb r0, [r1]
	b _08030EBE
	.align 2, 0
_08030EA8: .4byte gUnknown_203B480
_08030EAC: .4byte gUnknown_203B324
_08030EB0:
	mov r1, sp
	adds r1, 0x32
	movs r0, 0x2
	strb r0, [r1]
	ldrb r1, [r2]
	add r0, sp, 0x38
	strb r1, [r0]
_08030EBE:
	ldrb r0, [r5]
	cmp r0, 0x2
	beq _08030ED2
	cmp r0, 0x2
	ble _08030EE2
	cmp r0, 0x4
	beq _08030ED2
	cmp r0, 0x5
	beq _08030EDA
	b _08030EE2
_08030ED2:
	mov r1, sp
	adds r1, 0x45
	movs r0, 0xA
	b _08030EE8
_08030EDA:
	mov r1, sp
	adds r1, 0x45
	movs r0, 0xB
	b _08030EE8
_08030EE2:
	mov r1, sp
	adds r1, 0x45
	movs r0, 0x9
_08030EE8:
	strb r0, [r1]
	add r0, sp, 0x4
	bl CreateRescueDescription
	ldrh r0, [r5, 0x10]
	ldr r1, _08030F48
	bl __umodsi3
	adds r4, r0, 0
	lsls r4, 16
	lsrs r4, 16
	ldr r2, _08030F4C
	ldr r5, _08030F50
	ldr r0, [r5]
	ldr r3, [r0, 0x10]
	movs r0, 0
	mov r8, r0
	str r0, [sp]
	movs r0, 0xA
	movs r1, 0x68
	bl xxx_call_draw_string
	add r6, sp, 0x5C
	ldr r1, _08030F54
	adds r0, r6, 0
	adds r2, r4, 0
	bl sub_800D158
	ldr r0, [r5]
	ldr r3, [r0, 0x10]
	mov r0, r8
	str r0, [sp]
	movs r0, 0x44
	movs r1, 0x68
	adds r2, r6, 0
	bl xxx_call_draw_string
	ldr r0, [r5]
	ldr r0, [r0, 0x10]
	bl sub_80073E0
	add sp, 0x15C
	pop {r3}
	mov r8, r3
	pop {r4-r6}
	pop {r0}
	bx r0
	.align 2, 0
_08030F48: .4byte 0x00002710
_08030F4C: .4byte gUnknown_80E0934
_08030F50: .4byte gUnknown_203B324
_08030F54: .4byte gUnknown_80E0938
	thumb_func_end sub_8030E48

	thumb_func_start sub_8030F58
sub_8030F58:
	push {r4-r6,lr}
	adds r6, r0, 0
	bl ResetUnusedInputStruct
	movs r0, 0
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	ldr r5, _08030FF4
	ldr r0, [r5]
	cmp r0, 0
	bne _08030F88
	movs r4, 0x8E
	lsls r4, 1
	adds r0, r4, 0
	movs r1, 0x8
	bl MemoryAlloc
	str r0, [r5]
	movs r1, 0
	adds r2, r4, 0
	bl MemoryFill8
_08030F88:
	ldr r0, [r5]
	movs r1, 0x8C
	lsls r1, 1
	adds r0, r1
	str r6, [r0]
	movs r0, 0x98
	lsls r0, 1
	bl GetDialogueSpriteDataPtr
	ldr r2, [r5]
	movs r4, 0x84
	lsls r4, 1
	adds r1, r2, r4
	str r0, [r1]
	movs r3, 0x86
	lsls r3, 1
	adds r1, r2, r3
	ldr r0, [r0, 0x4]
	str r0, [r1]
	movs r0, 0x8A
	lsls r0, 1
	adds r2, r0
	movs r1, 0
	strb r1, [r2]
	ldr r0, [r5]
	ldr r2, _08030FF8
	adds r0, r2
	strb r1, [r0]
	ldr r0, [r5]
	adds r3, 0xA
	adds r0, r3
	strb r1, [r0]
	ldr r2, [r5]
	movs r0, 0x88
	lsls r0, 1
	adds r1, r2, r0
	movs r0, 0x2
	strh r0, [r1]
	subs r3, 0x4
	adds r1, r2, r3
	movs r0, 0x8
	strh r0, [r1]
	adds r0, r6, 0
	bl sub_8030C20
	lsls r0, 24
	lsrs r1, r0, 24
	cmp r1, 0
	beq _08031038
	cmp r6, 0x2
	beq _08030FFC
	cmp r6, 0x4
	beq _08031014
	b _08031022
	.align 2, 0
_08030FF4: .4byte gUnknown_203B328
_08030FF8: .4byte 0x00000115
_08030FFC:
	ldr r0, _0803100C
	ldr r2, [r5]
	adds r2, r4
	ldr r3, _08031010
	movs r1, 0
	bl sub_80141B4
	b _08031022
	.align 2, 0
_0803100C: .4byte gUnknown_80E09D8
_08031010: .4byte 0x00000101
_08031014:
	ldr r0, _0803102C
	ldr r2, [r5]
	adds r2, r4
	ldr r3, _08031030
	movs r1, 0
	bl sub_80141B4
_08031022:
	ldr r0, _08031034
	ldr r1, [r0]
	movs r0, 0x5
	str r0, [r1]
	b _08031048
	.align 2, 0
_0803102C: .4byte gUnknown_80E0A0C
_08031030: .4byte 0x00000101
_08031034: .4byte gUnknown_203B328
_08031038:
	ldr r0, [r5]
	str r1, [r0]
	adds r0, r6, 0
	movs r1, 0
	movs r2, 0
	movs r3, 0x8
	bl sub_80306A8
_08031048:
	movs r0, 0x1
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end sub_8030F58

	thumb_func_start sub_8031050
sub_8031050:
	push {lr}
	ldr r1, _08031068
	ldr r0, [r1]
	ldr r0, [r0]
	adds r2, r1, 0
	cmp r0, 0x6
	bhi _080310AC
	lsls r0, 2
	ldr r1, _0803106C
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08031068: .4byte gUnknown_203B328
_0803106C: .4byte _08031070
	.align 2, 0
_08031070:
	.4byte _0803108C
	.4byte _08031092
	.4byte _08031098
	.4byte _08031098
	.4byte _080310A2
	.4byte _080310A8
	.4byte _080310A8
_0803108C:
	bl sub_8031300
	b _080310AC
_08031092:
	bl sub_803136C
	b _080310AC
_08031098:
	ldr r0, [r2]
	ldr r0, [r0]
	bl sub_80313D8
	b _080310AC
_080310A2:
	bl sub_8031498
	b _080310AC
_080310A8:
	movs r0, 0x3
	b _080310AE
_080310AC:
	movs r0, 0
_080310AE:
	pop {r1}
	bx r1
	thumb_func_end sub_8031050

	thumb_func_start sub_80310B4
sub_80310B4:
	push {r4,lr}
	bl sub_803084C
	ldr r4, _080310E0
	ldr r0, [r4]
	cmp r0, 0
	beq _080310D8
	movs r1, 0x84
	lsls r1, 1
	adds r0, r1
	ldr r0, [r0]
	bl CloseFile
	ldr r0, [r4]
	bl MemoryFree
	movs r0, 0
	str r0, [r4]
_080310D8:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080310E0: .4byte gUnknown_203B328
	thumb_func_end sub_80310B4

	thumb_func_start sub_80310E4
sub_80310E4:
	push {lr}
	ldr r1, _080310F8
	ldr r1, [r1]
	str r0, [r1]
	bl sub_80310FC
	bl sub_8031258
	pop {r0}
	bx r0
	.align 2, 0
_080310F8: .4byte gUnknown_203B328
	thumb_func_end sub_80310E4

	thumb_func_start sub_80310FC
sub_80310FC:
	push {r4-r6,lr}
	ldr r4, _0803111C
	ldr r0, [r4]
	adds r0, 0xA8
	bl sub_8006518
	ldr r0, [r4]
	ldr r0, [r0]
	cmp r0, 0x6
	bls _08031112
	b _0803122C
_08031112:
	lsls r0, 2
	ldr r1, _08031120
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0803111C: .4byte gUnknown_203B328
_08031120: .4byte _08031124
	.align 2, 0
_08031124:
	.4byte _08031140
	.4byte _08031178
	.4byte _080311C0
	.4byte _080311C0
	.4byte _080311E8
	.4byte _0803122C
	.4byte _0803122C
_08031140:
	ldr r3, _08031170
	ldr r1, [r3]
	ldr r2, _08031174
	adds r1, 0xC0
	adds r0, r2, 0
	ldm r0!, {r4-r6}
	stm r1!, {r4-r6}
	ldm r0!, {r4-r6}
	stm r1!, {r4-r6}
	ldr r1, [r3]
	adds r1, 0xD8
	adds r0, r2, 0
	ldm r0!, {r4-r6}
	stm r1!, {r4-r6}
	ldm r0!, {r4-r6}
	stm r1!, {r4-r6}
	ldr r0, [r3]
	adds r0, 0xF0
	ldm r2!, {r1,r3,r4}
	stm r0!, {r1,r3,r4}
	ldm r2!, {r1,r5,r6}
	stm r0!, {r1,r5,r6}
	b _0803123A
	.align 2, 0
_08031170: .4byte gUnknown_203B328
_08031174: .4byte gUnknown_80E0990
_08031178:
	ldr r3, _080311B0
	ldr r1, [r3]
	adds r1, 0xC0
	ldr r0, _080311B4
	ldm r0!, {r2,r4,r5}
	stm r1!, {r2,r4,r5}
	ldm r0!, {r2,r4,r6}
	stm r1!, {r2,r4,r6}
	ldr r1, [r3]
	ldr r2, _080311B8
	adds r1, 0xD8
	adds r0, r2, 0
	ldm r0!, {r4-r6}
	stm r1!, {r4-r6}
	ldm r0!, {r4-r6}
	stm r1!, {r4-r6}
	ldr r0, [r3]
	adds r0, 0xF0
	ldm r2!, {r1,r5,r6}
	stm r0!, {r1,r5,r6}
	ldm r2!, {r4-r6}
	stm r0!, {r4-r6}
	ldr r0, [r3]
	adds r0, 0xC0
	ldr r1, _080311BC
	bl sub_8012CAC
	b _0803123A
	.align 2, 0
_080311B0: .4byte gUnknown_203B328
_080311B4: .4byte gUnknown_80E09A8
_080311B8: .4byte gUnknown_80E0990
_080311BC: .4byte gUnknown_80E0968
_080311C0:
	ldr r2, _080311DC
	ldr r1, [r2]
	adds r1, 0xD8
	ldr r0, _080311E0
	ldm r0!, {r3-r5}
	stm r1!, {r3-r5}
	ldm r0!, {r3,r4,r6}
	stm r1!, {r3,r4,r6}
	ldr r0, [r2]
	adds r0, 0xD8
	ldr r1, _080311E4
	bl sub_8012CAC
	b _0803123A
	.align 2, 0
_080311DC: .4byte gUnknown_203B328
_080311E0: .4byte gUnknown_80E09C0
_080311E4: .4byte gUnknown_80E0948
_080311E8:
	ldr r3, _08031224
	ldr r1, [r3]
	ldr r2, _08031228
	adds r1, 0xA8
	adds r0, r2, 0
	ldm r0!, {r4-r6}
	stm r1!, {r4-r6}
	ldm r0!, {r4-r6}
	stm r1!, {r4-r6}
	ldr r1, [r3]
	adds r1, 0xC0
	adds r0, r2, 0
	ldm r0!, {r4-r6}
	stm r1!, {r4-r6}
	ldm r0!, {r4-r6}
	stm r1!, {r4-r6}
	ldr r1, [r3]
	adds r1, 0xD8
	adds r0, r2, 0
	ldm r0!, {r4-r6}
	stm r1!, {r4-r6}
	ldm r0!, {r4-r6}
	stm r1!, {r4-r6}
	ldr r0, [r3]
	adds r0, 0xF0
	ldm r2!, {r1,r5,r6}
	stm r0!, {r1,r5,r6}
	ldm r2!, {r3-r5}
	stm r0!, {r3-r5}
	b _0803123A
	.align 2, 0
_08031224: .4byte gUnknown_203B328
_08031228: .4byte gUnknown_80E0990
_0803122C:
	bl ResetUnusedInputStruct
	movs r0, 0
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
_0803123A:
	bl ResetUnusedInputStruct
	ldr r0, _08031254
	ldr r0, [r0]
	adds r0, 0xA8
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	pop {r4-r6}
	pop {r0}
	bx r0
	.align 2, 0
_08031254: .4byte gUnknown_203B328
	thumb_func_end sub_80310FC

	thumb_func_start sub_8031258
sub_8031258:
	push {r4,lr}
	sub sp, 0x8
	ldr r1, _08031274
	ldr r0, [r1]
	ldr r0, [r0]
	adds r2, r1, 0
	cmp r0, 0x6
	bhi _080312F6
	lsls r0, 2
	ldr r1, _08031278
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08031274: .4byte gUnknown_203B328
_08031278: .4byte _0803127C
	.align 2, 0
_0803127C:
	.4byte _08031298
	.4byte _080312A0
	.4byte _080312BC
	.4byte _080312BC
	.4byte _080312EC
	.4byte _080312F6
	.4byte _080312F6
_08031298:
	movs r0, 0x1
	bl sub_8030810
	b _080312F6
_080312A0:
	bl sub_803092C
	ldr r0, _080312B4
	ldr r0, [r0]
	adds r0, 0x8
	ldr r1, _080312B8
	movs r2, 0x4
	str r2, [sp]
	movs r2, 0x1
	b _080312D8
	.align 2, 0
_080312B4: .4byte gUnknown_203B328
_080312B8: .4byte gUnknown_80E0968
_080312BC:
	bl sub_803092C
	ldr r4, _080312E4
	ldr r0, [r4]
	adds r0, 0x8
	movs r1, 0
	bl sub_8012EA4
	ldr r0, [r4]
	adds r0, 0x58
	ldr r1, _080312E8
	movs r2, 0x3
	str r2, [sp]
	movs r2, 0x2
_080312D8:
	str r2, [sp, 0x4]
	movs r2, 0
	movs r3, 0
	bl sub_8012D60
	b _080312F6
	.align 2, 0
_080312E4: .4byte gUnknown_203B328
_080312E8: .4byte gUnknown_80E0948
_080312EC:
	ldr r0, [r2]
	ldrb r0, [r0, 0x4]
	movs r1, 0x3
	bl sub_8030D40
_080312F6:
	add sp, 0x8
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_8031258

	thumb_func_start sub_8031300
sub_8031300:
	push {lr}
	movs r0, 0x1
	bl sub_8030768
	cmp r0, 0x4
	bhi _08031366
	lsls r0, 2
	ldr r1, _08031318
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08031318: .4byte _0803131C
	.align 2, 0
_0803131C:
	.4byte _08031366
	.4byte _08031366
	.4byte _08031360
	.4byte _08031330
	.4byte _08031348
_08031330:
	bl sub_80307EC
	ldr r1, _08031344
	ldr r1, [r1]
	strb r0, [r1, 0x4]
	movs r0, 0x1
	bl sub_80310E4
	b _08031366
	.align 2, 0
_08031344: .4byte gUnknown_203B328
_08031348:
	bl sub_80307EC
	ldr r1, _0803135C
	ldr r1, [r1]
	strb r0, [r1, 0x4]
	movs r0, 0x4
	bl sub_80310E4
	b _08031366
	.align 2, 0
_0803135C: .4byte gUnknown_203B328
_08031360:
	movs r0, 0x6
	bl sub_80310E4
_08031366:
	pop {r0}
	bx r0
	thumb_func_end sub_8031300

	thumb_func_start sub_803136C
sub_803136C:
	push {r4,lr}
	sub sp, 0x4
	movs r0, 0
	str r0, [sp]
	bl sub_8030768
	ldr r4, _080313A4
	ldr r0, [r4]
	adds r0, 0x8
	bl sub_8012FD8
	lsls r0, 24
	cmp r0, 0
	bne _08031392
	ldr r0, [r4]
	adds r0, 0x8
	mov r1, sp
	bl sub_8013114
_08031392:
	ldr r0, [sp]
	cmp r0, 0x4
	beq _080313C2
	cmp r0, 0x4
	bgt _080313A8
	cmp r0, 0x1
	beq _080313B2
	b _080313D0
	.align 2, 0
_080313A4: .4byte gUnknown_203B328
_080313A8:
	cmp r0, 0x5
	beq _080313CA
	cmp r0, 0x6
	beq _080313BA
	b _080313D0
_080313B2:
	movs r0, 0
	bl sub_80310E4
	b _080313D0
_080313BA:
	movs r0, 0x3
	bl sub_80310E4
	b _080313D0
_080313C2:
	movs r0, 0x2
	bl sub_80310E4
	b _080313D0
_080313CA:
	movs r0, 0x4
	bl sub_80310E4
_080313D0:
	add sp, 0x4
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_803136C

	thumb_func_start sub_80313D8
sub_80313D8:
	push {r4,r5,lr}
	sub sp, 0x4
	adds r5, r0, 0
	movs r0, 0
	str r0, [sp]
	bl sub_8030768
	ldr r4, _08031418
	ldr r0, [r4]
	adds r0, 0x8
	bl sub_8012FD8
	ldr r0, [r4]
	adds r0, 0x58
	bl sub_8012FD8
	lsls r0, 24
	cmp r0, 0
	bne _08031408
	ldr r0, [r4]
	adds r0, 0x58
	mov r1, sp
	bl sub_8013114
_08031408:
	ldr r0, [sp]
	cmp r0, 0x2
	beq _08031428
	cmp r0, 0x2
	bgt _0803141C
	cmp r0, 0x1
	beq _08031420
	b _0803148E
	.align 2, 0
_08031418: .4byte gUnknown_203B328
_0803141C:
	cmp r0, 0x3
	bne _0803148E
_08031420:
	movs r0, 0
	bl sub_80310E4
	b _0803148E
_08031428:
	cmp r5, 0x2
	beq _08031432
	cmp r5, 0x3
	beq _0803143C
	b _0803145A
_08031432:
	ldr r0, [r4]
	ldrb r0, [r0, 0x4]
	bl sub_8095240
	b _0803145A
_0803143C:
	ldr r4, _08031480
	movs r3, 0
	movs r1, 0
	movs r2, 0x1F
_08031444:
	ldr r0, [r4]
	adds r0, r1
	strb r3, [r0]
	ldr r0, [r4]
	adds r0, r1
	adds r0, 0x22
	strb r3, [r0]
	adds r1, 0x30
	subs r2, 0x1
	cmp r2, 0
	bge _08031444
_0803145A:
	ldr r0, _08031484
	ldr r0, [r0]
	movs r1, 0x8C
	lsls r1, 1
	adds r0, r1
	ldr r0, [r0]
	cmp r0, 0x2
	beq _0803146E
	cmp r0, 0x4
	bne _0803148E
_0803146E:
	bl sub_8030C20
	lsls r0, 24
	cmp r0, 0
	beq _08031488
	movs r0, 0x5
	bl sub_80310E4
	b _0803148E
	.align 2, 0
_08031480: .4byte gUnknown_203B480
_08031484: .4byte gUnknown_203B328
_08031488:
	movs r0, 0
	bl sub_80310E4
_0803148E:
	add sp, 0x4
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_80313D8

	thumb_func_start sub_8031498
sub_8031498:
	push {lr}
	bl sub_8030DA0
	cmp r0, 0x1
	bls _080314B0
	cmp r0, 0x3
	bhi _080314B0
	bl sub_8030DE4
	movs r0, 0
	bl sub_80310E4
_080314B0:
	pop {r0}
	bx r0
	thumb_func_end sub_8031498

	thumb_func_start sub_80314B4
sub_80314B4:
	push {r4-r6,lr}
	lsls r0, 16
	asrs r5, r0, 16
	bl ResetUnusedInputStruct
	movs r0, 0
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	ldr r6, _08031534
	movs r0, 0x18
	movs r1, 0x8
	bl MemoryAlloc
	str r0, [r6]
	ldr r0, _08031538
	adds r1, r5, 0
	bl CopyYellowSpeciesNametoBuffer
	adds r0, r5, 0
	bl GetMonSpecies
	adds r1, r0, 0
	ldr r0, _0803153C
	bl strcpy
	ldr r0, [r6]
	movs r4, 0
	str r4, [r0, 0x8]
	str r4, [r0, 0xC]
	cmp r5, 0
	beq _0803151E
	adds r0, r5, 0
	bl GetDialogueSpriteDataPtr
	ldr r1, [r6]
	str r0, [r1, 0x8]
	strb r4, [r1, 0x14]
	ldr r0, [r6]
	strb r4, [r0, 0x15]
	ldr r0, [r6]
	strb r4, [r0, 0x16]
	ldr r1, [r6]
	movs r0, 0x2
	strh r0, [r1, 0x10]
	movs r0, 0x8
	strh r0, [r1, 0x12]
	ldr r0, [r1, 0x8]
	cmp r0, 0
	beq _0803151E
	ldr r0, [r0, 0x4]
	str r0, [r1, 0xC]
_0803151E:
	ldr r0, _08031534
	ldr r1, [r0]
	movs r0, 0
	str r0, [r1, 0x4]
	movs r0, 0x1
	bl sub_80317C0
	movs r0, 0x1
	pop {r4-r6}
	pop {r1}
	bx r1
	.align 2, 0
_08031534: .4byte gUnknown_203B32C
_08031538: .4byte gUnknown_202E5D8
_0803153C: .4byte gAvailablePokemonNames
	thumb_func_end sub_80314B4

	thumb_func_start sub_8031540
sub_8031540:
	push {lr}
	ldr r0, _08031558
	ldr r0, [r0]
	ldrb r0, [r0]
	cmp r0, 0x9
	bhi _080315BA
	lsls r0, 2
	ldr r1, _0803155C
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08031558: .4byte gUnknown_203B32C
_0803155C: .4byte _08031560
	.align 2, 0
_08031560:
	.4byte _080315AC
	.4byte _08031588
	.4byte _08031588
	.4byte _0803158E
	.4byte _08031594
	.4byte _0803159A
	.4byte _080315A0
	.4byte _080315A6
	.4byte _080315B0
	.4byte _080315B6
_08031588:
	bl sub_80317D8
	b _080315BA
_0803158E:
	bl sub_8031848
	b _080315BA
_08031594:
	bl sub_8031864
	b _080315BA
_0803159A:
	bl sub_80318D0
	b _080315BA
_080315A0:
	bl sub_80318EC
	b _080315BA
_080315A6:
	bl sub_803192C
	b _080315BA
_080315AC:
	movs r0, 0x3
	b _080315BC
_080315B0:
	bl sub_8031948
	b _080315BA
_080315B6:
	bl sub_8031988
_080315BA:
	movs r0, 0
_080315BC:
	pop {r1}
	bx r1
	thumb_func_end sub_8031540

	thumb_func_start sub_80315C0
sub_80315C0:
	push {r4,lr}
	ldr r4, _080315E4
	ldr r0, [r4]
	cmp r0, 0
	beq _080315DE
	ldr r0, [r0, 0x8]
	cmp r0, 0
	beq _080315D4
	bl CloseFile
_080315D4:
	ldr r0, [r4]
	bl MemoryFree
	movs r0, 0
	str r0, [r4]
_080315DE:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080315E4: .4byte gUnknown_203B32C
	thumb_func_end sub_80315C0

	thumb_func_start nullsub_39
nullsub_39:
	bx lr
	thumb_func_end nullsub_39

	thumb_func_start sub_80315EC
sub_80315EC:
	push {r4,r5,lr}
	sub sp, 0x14
	movs r5, 0
	ldr r0, _08031618
	ldr r2, [r0]
	ldr r1, [r2, 0x8]
	adds r3, r0, 0
	cmp r1, 0
	beq _08031602
	adds r5, r2, 0
	adds r5, 0x8
_08031602:
	ldrb r0, [r2]
	subs r0, 0x1
	cmp r0, 0x8
	bls _0803160C
	b _080317B0
_0803160C:
	lsls r0, 2
	ldr r1, _0803161C
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08031618: .4byte gUnknown_203B32C
_0803161C: .4byte _08031620
	.align 2, 0
_08031620:
	.4byte _08031700
	.4byte _08031714
	.4byte _08031728
	.4byte _08031758
	.4byte _08031780
	.4byte _08031694
	.4byte _080316A8
	.4byte _08031644
	.4byte _08031658
_08031644:
	ldr r0, _08031650
	ldr r1, [r3]
	ldr r2, [r1, 0x4]
	ldr r3, _08031654
	b _08031760
	.align 2, 0
_08031650: .4byte gUnknown_80E0C4C
_08031654: .4byte gUnknown_80E0BD4
_08031658:
	ldr r0, [r3]
	ldr r0, [r0, 0x4]
	cmp r0, 0x10
	beq _0803167C
	cmp r0, 0x10
	bgt _0803166A
	cmp r0, 0xF
	beq _08031674
	b _080317B0
_0803166A:
	cmp r0, 0x11
	beq _08031684
	cmp r0, 0x12
	beq _0803168C
	b _080317B0
_08031674:
	ldr r0, _08031678
	b _08031790
	.align 2, 0
_08031678: .4byte gUnknown_80E0C70
_0803167C:
	ldr r0, _08031680
	b _08031790
	.align 2, 0
_08031680: .4byte gUnknown_80E0DD0
_08031684:
	ldr r0, _08031688
	b _08031790
	.align 2, 0
_08031688: .4byte gUnknown_80E0ED8
_0803168C:
	ldr r0, _08031690
	b _08031790
	.align 2, 0
_08031690: .4byte gUnknown_80E10C8
_08031694:
	ldr r0, _080316A0
	ldr r1, [r3]
	ldr r2, [r1, 0x4]
	ldr r3, _080316A4
	b _08031760
	.align 2, 0
_080316A0: .4byte gUnknown_80E0C4C
_080316A4: .4byte gUnknown_80E0B3C
_080316A8:
	ldr r0, [r3]
	ldr r0, [r0, 0x4]
	subs r0, 0xA
	cmp r0, 0x4
	bls _080316B4
	b _080317B0
_080316B4:
	lsls r0, 2
	ldr r1, _080316C0
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080316C0: .4byte _080316C4
	.align 2, 0
_080316C4:
	.4byte _080316D8
	.4byte _080316E0
	.4byte _080316F0
	.4byte _080316E8
	.4byte _080316F8
_080316D8:
	ldr r0, _080316DC
	b _08031790
	.align 2, 0
_080316DC: .4byte gUnknown_80E120C
_080316E0:
	ldr r0, _080316E4
	b _08031790
	.align 2, 0
_080316E4: .4byte gUnknown_80E136C
_080316E8:
	ldr r0, _080316EC
	b _08031790
	.align 2, 0
_080316EC: .4byte gUnknown_80E1420
_080316F0:
	ldr r0, _080316F4
	b _08031790
	.align 2, 0
_080316F4: .4byte gUnknown_80E157C
_080316F8:
	ldr r0, _080316FC
	b _08031790
	.align 2, 0
_080316FC: .4byte gUnknown_80E169C
_08031700:
	ldr r0, _0803170C
	ldr r1, [r3]
	ldr r2, [r1, 0x4]
	ldr r3, _08031710
	b _08031760
	.align 2, 0
_0803170C: .4byte gUnknown_80E17C8
_08031710: .4byte gUnknown_80E0A48
_08031714:
	ldr r0, _08031720
	ldr r1, [r3]
	ldr r2, [r1, 0x4]
	ldr r3, _08031724
	b _08031760
	.align 2, 0
_08031720: .4byte gUnknown_80E183C
_08031724: .4byte gUnknown_80E0A48
_08031728:
	ldr r0, [r3]
	ldr r0, [r0, 0x4]
	cmp r0, 0x1
	beq _08031748
	cmp r0, 0x1
	bgt _0803173A
	cmp r0, 0
	beq _08031740
	b _080317B0
_0803173A:
	cmp r0, 0x2
	beq _08031750
	b _080317B0
_08031740:
	ldr r0, _08031744
	b _08031790
	.align 2, 0
_08031744: .4byte gUnknown_80E1868
_08031748:
	ldr r0, _0803174C
	b _08031790
	.align 2, 0
_0803174C: .4byte gUnknown_80E1A30
_08031750:
	ldr r0, _08031754
	b _08031790
	.align 2, 0
_08031754: .4byte gUnknown_80E1AD8
_08031758:
	ldr r0, _08031778
	ldr r1, [r3]
	ldr r2, [r1, 0x4]
	ldr r3, _0803177C
_08031760:
	movs r4, 0
	str r4, [sp]
	movs r1, 0x4
	str r1, [sp, 0x4]
	str r4, [sp, 0x8]
	str r5, [sp, 0xC]
	movs r1, 0xC
	str r1, [sp, 0x10]
	movs r1, 0
	bl sub_8014248
	b _080317B0
	.align 2, 0
_08031778: .4byte gUnknown_80E0C4C
_0803177C: .4byte gUnknown_80E0ABC
_08031780:
	ldr r0, [r3]
	ldr r0, [r0, 0x4]
	cmp r0, 0x6
	beq _0803178E
	cmp r0, 0x9
	beq _080317A4
	b _080317B0
_0803178E:
	ldr r0, _0803179C
_08031790:
	ldr r3, _080317A0
	movs r1, 0
	adds r2, r5, 0
	bl sub_80141B4
	b _080317B0
	.align 2, 0
_0803179C: .4byte gUnknown_80E1B88
_080317A0: .4byte 0x0000010d
_080317A4:
	ldr r0, _080317B8
	ldr r3, _080317BC
	movs r1, 0
	adds r2, r5, 0
	bl sub_80141B4
_080317B0:
	add sp, 0x14
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_080317B8: .4byte gUnknown_80E1D84
_080317BC: .4byte 0x0000010d
	thumb_func_end sub_80315EC

	thumb_func_start sub_80317C0
sub_80317C0:
	push {lr}
	ldr r1, _080317D4
	ldr r1, [r1]
	strb r0, [r1]
	bl nullsub_39
	bl sub_80315EC
	pop {r0}
	bx r0
	.align 2, 0
_080317D4: .4byte gUnknown_203B32C
	thumb_func_end sub_80317C0

	thumb_func_start sub_80317D8
sub_80317D8:
	push {lr}
	sub sp, 0x4
	mov r0, sp
	bl sub_80144A4
	cmp r0, 0
	bne _0803183C
	ldr r2, [sp]
	cmp r2, 0x5
	bhi _0803183C
	lsls r0, r2, 2
	ldr r1, _080317F8
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080317F8: .4byte _080317FC
	.align 2, 0
_080317FC:
	.4byte _08031830
	.4byte _08031830
	.4byte _08031830
	.4byte _0803181C
	.4byte _08031814
	.4byte _08031814
_08031814:
	movs r0, 0
	bl sub_80317C0
	b _0803183C
_0803181C:
	ldr r0, _0803182C
	ldr r0, [r0]
	str r2, [r0, 0x4]
	movs r0, 0x4
	bl sub_80317C0
	b _0803183C
	.align 2, 0
_0803182C: .4byte gUnknown_203B32C
_08031830:
	ldr r0, _08031844
	ldr r0, [r0]
	str r2, [r0, 0x4]
	movs r0, 0x3
	bl sub_80317C0
_0803183C:
	add sp, 0x4
	pop {r0}
	bx r0
	.align 2, 0
_08031844: .4byte gUnknown_203B32C
	thumb_func_end sub_80317D8

	thumb_func_start sub_8031848
sub_8031848:
	push {lr}
	sub sp, 0x4
	mov r0, sp
	bl sub_80144A4
	cmp r0, 0
	bne _0803185C
	movs r0, 0x2
	bl sub_80317C0
_0803185C:
	add sp, 0x4
	pop {r0}
	bx r0
	thumb_func_end sub_8031848

	thumb_func_start sub_8031864
sub_8031864:
	push {lr}
	sub sp, 0x4
	mov r0, sp
	bl sub_80144A4
	cmp r0, 0
	bne _080318C4
	ldr r0, [sp]
	subs r1, r0, 0x5
	adds r2, r0, 0
	cmp r1, 0x4
	bhi _080318C4
	lsls r0, r1, 2
	ldr r1, _08031888
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08031888: .4byte _0803188C
	.align 2, 0
_0803188C:
	.4byte _080318A0
	.4byte _080318B8
	.4byte _080318A8
	.4byte _080318B0
	.4byte _080318B8
_080318A0:
	movs r0, 0x2
	bl sub_80317C0
	b _080318C4
_080318A8:
	movs r0, 0x6
	bl sub_80317C0
	b _080318C4
_080318B0:
	movs r0, 0x8
	bl sub_80317C0
	b _080318C4
_080318B8:
	ldr r0, _080318CC
	ldr r0, [r0]
	str r2, [r0, 0x4]
	movs r0, 0x5
	bl sub_80317C0
_080318C4:
	add sp, 0x4
	pop {r0}
	bx r0
	.align 2, 0
_080318CC: .4byte gUnknown_203B32C
	thumb_func_end sub_8031864

	thumb_func_start sub_80318D0
sub_80318D0:
	push {lr}
	sub sp, 0x4
	mov r0, sp
	bl sub_80144A4
	cmp r0, 0
	bne _080318E4
	movs r0, 0x4
	bl sub_80317C0
_080318E4:
	add sp, 0x4
	pop {r0}
	bx r0
	thumb_func_end sub_80318D0

	thumb_func_start sub_80318EC
sub_80318EC:
	push {lr}
	sub sp, 0x4
	mov r0, sp
	bl sub_80144A4
	cmp r0, 0
	bne _08031920
	ldr r1, [sp]
	cmp r1, 0x5
	bne _08031908
	movs r0, 0x4
	bl sub_80317C0
	b _08031920
_08031908:
	cmp r1, 0x5
	blt _08031920
	cmp r1, 0xE
	bgt _08031920
	cmp r1, 0xA
	blt _08031920
	ldr r0, _08031928
	ldr r0, [r0]
	str r1, [r0, 0x4]
	movs r0, 0x7
	bl sub_80317C0
_08031920:
	add sp, 0x4
	pop {r0}
	bx r0
	.align 2, 0
_08031928: .4byte gUnknown_203B32C
	thumb_func_end sub_80318EC

	thumb_func_start sub_803192C
sub_803192C:
	push {lr}
	sub sp, 0x4
	mov r0, sp
	bl sub_80144A4
	cmp r0, 0
	bne _08031940
	movs r0, 0x6
	bl sub_80317C0
_08031940:
	add sp, 0x4
	pop {r0}
	bx r0
	thumb_func_end sub_803192C

	thumb_func_start sub_8031948
sub_8031948:
	push {lr}
	sub sp, 0x4
	mov r0, sp
	bl sub_80144A4
	cmp r0, 0
	bne _0803197C
	ldr r1, [sp]
	cmp r1, 0x5
	bne _08031964
	movs r0, 0x4
	bl sub_80317C0
	b _0803197C
_08031964:
	cmp r1, 0x5
	blt _0803197C
	cmp r1, 0x12
	bgt _0803197C
	cmp r1, 0xF
	blt _0803197C
	ldr r0, _08031984
	ldr r0, [r0]
	str r1, [r0, 0x4]
	movs r0, 0x9
	bl sub_80317C0
_0803197C:
	add sp, 0x4
	pop {r0}
	bx r0
	.align 2, 0
_08031984: .4byte gUnknown_203B32C
	thumb_func_end sub_8031948

	thumb_func_start sub_8031988
sub_8031988:
	push {lr}
	sub sp, 0x4
	mov r0, sp
	bl sub_80144A4
	cmp r0, 0
	bne _0803199C
	movs r0, 0x8
	bl sub_80317C0
_0803199C:
	add sp, 0x4
	pop {r0}
	bx r0
	thumb_func_end sub_8031988

	thumb_func_start sub_80319A4
sub_80319A4:
	push {r4-r6,lr}
	mov r6, r8
	push {r6}
	adds r4, r0, 0
	adds r5, r1, 0
	mov r8, r2
	lsls r4, 24
	lsrs r4, 24
	lsls r5, 24
	lsrs r5, 24
	ldr r6, _080319F4
	movs r0, 0x78
	movs r1, 0x8
	bl MemoryAlloc
	str r0, [r6]
	strb r4, [r0, 0xC]
	ldr r0, [r6]
	strb r5, [r0, 0xD]
	ldr r0, [r6]
	bl sub_801317C
	ldr r1, [r6]
	mov r0, r8
	str r0, [r1, 0x10]
	lsls r0, 1
	add r0, r8
	lsls r0, 3
	adds r0, 0x18
	adds r0, r1, r0
	str r0, [r1, 0x14]
	bl sub_8031A2C
	movs r0, 0x1
	pop {r3}
	mov r8, r3
	pop {r4-r6}
	pop {r1}
	bx r1
	.align 2, 0
_080319F4: .4byte gUnknown_203B330
	thumb_func_end sub_80319A4

	thumb_func_start sub_80319F8
sub_80319F8:
	push {lr}
	ldr r0, _08031A18
	ldr r0, [r0]
	ldr r1, [r0, 0x10]
	bl sub_8012A64
	cmp r0, 0x1
	beq _08031A1C
	cmp r0, 0x2
	bne _08031A26
	movs r0, 0x1
	bl PlayMenuSoundEffect
	movs r0, 0x2
	b _08031A28
	.align 2, 0
_08031A18: .4byte gUnknown_203B330
_08031A1C:
	movs r0, 0
	bl PlayMenuSoundEffect
	movs r0, 0x3
	b _08031A28
_08031A26:
	movs r0, 0
_08031A28:
	pop {r1}
	bx r1
	thumb_func_end sub_80319F8

	thumb_func_start sub_8031A2C
sub_8031A2C:
	push {lr}
	bl sub_8031A84
	bl sub_8031AE8
	pop {r0}
	bx r0
	thumb_func_end sub_8031A2C

	thumb_func_start sub_8031A3C
sub_8031A3C:
	push {r4,r5,lr}
	ldr r4, _08031A7C
	ldr r2, [r4]
	cmp r2, 0
	beq _08031A76
	ldr r0, [r2, 0x10]
	lsls r1, r0, 1
	adds r1, r0
	lsls r1, 3
	adds r1, r2, r1
	adds r1, 0x18
	ldr r0, _08031A80
	ldm r0!, {r2,r3,r5}
	stm r1!, {r2,r3,r5}
	ldm r0!, {r2,r3,r5}
	stm r1!, {r2,r3,r5}
	bl ResetUnusedInputStruct
	ldr r0, [r4]
	adds r0, 0x18
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	ldr r0, [r4]
	bl MemoryFree
	movs r0, 0
	str r0, [r4]
_08031A76:
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_08031A7C: .4byte gUnknown_203B330
_08031A80: .4byte gUnknown_80E1EFC
	thumb_func_end sub_8031A3C

	thumb_func_start sub_8031A84
sub_8031A84:
	push {r4,r5,lr}
	ldr r4, _08031AE0
	ldr r0, [r4]
	adds r0, 0x18
	bl sub_8006518
	ldr r1, [r4]
	ldr r2, [r1, 0x10]
	lsls r0, r2, 1
	adds r0, r2
	lsls r0, 3
	adds r1, r0
	adds r1, 0x18
	ldr r0, _08031AE4
	ldm r0!, {r2,r3,r5}
	stm r1!, {r2,r3,r5}
	ldm r0!, {r2,r3,r5}
	stm r1!, {r2,r3,r5}
	ldr r1, [r4]
	ldrb r0, [r1, 0xC]
	cmp r0, 0x2
	bne _08031AC6
	ldrb r0, [r1, 0xD]
	bl sub_80969D0
	adds r1, r0, 0
	cmp r1, 0
	bne _08031ABE
	movs r1, 0x1
_08031ABE:
	ldr r0, [r4]
	ldr r0, [r0, 0x14]
	bl sub_8012D08
_08031AC6:
	bl ResetUnusedInputStruct
	ldr r0, _08031AE0
	ldr r0, [r0]
	adds r0, 0x18
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_08031AE0: .4byte gUnknown_203B330
_08031AE4: .4byte gUnknown_80E1F18
	thumb_func_end sub_8031A84

	thumb_func_start sub_8031AE8
sub_8031AE8:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0xDC
	ldr r7, _08031B24
	ldr r0, [r7]
	ldr r0, [r0, 0x10]
	bl sub_80073B8
	ldr r2, _08031B28
	ldr r0, [r7]
	ldr r3, [r0, 0x10]
	movs r6, 0
	str r6, [sp]
	movs r0, 0xA
	movs r1, 0
	bl xxx_call_draw_string
	ldr r1, [r7]
	ldrb r0, [r1, 0xC]
	cmp r0, 0x1
	beq _08031B2C
	cmp r0, 0x1
	bgt _08031B1E
	b _08031CD4
_08031B1E:
	cmp r0, 0x2
	beq _08031B94
	b _08031CD4
	.align 2, 0
_08031B24: .4byte gUnknown_203B330
_08031B28: .4byte gUnknown_80E1F30
_08031B2C:
	add r4, sp, 0x68
	adds r0, r4, 0
	bl sub_8099394
	ldrb r0, [r4]
	bl sub_8095228
	adds r5, r0, 0
	ldr r0, [r7]
	ldr r3, [r0, 0x10]
	movs r0, 0xA
	movs r1, 0x10
	movs r2, 0x3
	bl sub_803B6B0
	ldr r1, _08031B8C
	ldrb r2, [r5, 0x5]
	add r0, sp, 0x4
	bl sub_800D158
	ldr r0, [r7]
	ldr r3, [r0, 0x10]
	str r6, [sp]
	movs r0, 0x15
	movs r1, 0x10
	add r2, sp, 0x4
	bl xxx_call_draw_string
	ldr r4, _08031B90
	movs r1, 0xC
	ldrsh r0, [r5, r1]
	bl GetMonSpecies
	adds r2, r0, 0
	add r0, sp, 0x4
	adds r1, r4, 0
	bl sub_800D158
	ldr r0, [r7]
	ldr r3, [r0, 0x10]
	str r6, [sp]
	movs r0, 0x28
	movs r1, 0x10
	add r2, sp, 0x4
	bl xxx_call_draw_string
	b _08031D4E
	.align 2, 0
_08031B8C: .4byte gUnknown_80E1F3C
_08031B90: .4byte gUnknown_80E1F40
_08031B94:
	ldrb r0, [r1, 0xD]
	bl sub_80969D0
	adds r1, r0, 0
	cmp r1, 0
	bne _08031BB0
	ldr r2, _08031BAC
	ldr r0, [r7]
	ldr r3, [r0, 0x10]
	str r1, [sp]
	b _08031D2C
	.align 2, 0
_08031BAC: .4byte gUnknown_80E1F54
_08031BB0:
	movs r6, 0x10
	movs r2, 0
	mov r10, r2
	mov r8, r2
	ldr r0, _08031C28
	mov r9, r0
	mov r1, sp
	adds r1, 0x6C
	str r1, [sp, 0xD8]
_08031BC2:
	mov r2, r10
	lsls r0, r2, 24
	lsrs r0, 24
	bl sub_8096AB4
	adds r4, r0, 0
	ldr r1, [r7]
	ldrb r0, [r4, 0x4]
	ldrb r2, [r1, 0xD]
	cmp r0, r2
	bne _08031CC2
	ldrb r0, [r4]
	cmp r0, 0
	beq _08031CC2
	cmp r0, 0x5
	beq _08031CC2
	cmp r0, 0x7
	beq _08031CC2
	ldr r3, [r1, 0x10]
	movs r0, 0xA
	adds r1, r6, 0
	movs r2, 0x3
	bl sub_803B6B0
	ldrb r0, [r4, 0x1]
	add r5, sp, 0x6C
	cmp r0, 0x3
	beq _08031C16
	ldrb r2, [r4, 0x5]
	ldr r0, [sp, 0xD8]
	ldr r1, _08031C2C
	bl sub_800D158
	ldr r0, [r7]
	ldr r3, [r0, 0x10]
	mov r0, r8
	str r0, [sp]
	movs r0, 0x15
	adds r1, r6, 0
	ldr r2, [sp, 0xD8]
	bl xxx_call_draw_string
_08031C16:
	ldrb r0, [r4, 0x1]
	cmp r0, 0x3
	beq _08031C58
	cmp r0, 0x3
	bgt _08031C30
	cmp r0, 0x2
	beq _08031C70
	b _08031C9C
	.align 2, 0
_08031C28: .4byte gUnknown_202DE58
_08031C2C: .4byte gUnknown_80E1F3C
_08031C30:
	cmp r0, 0x4
	bne _08031C9C
	ldrb r1, [r4, 0x10]
	mov r0, r9
	movs r2, 0
	bl sub_8090DC4
	adds r0, r5, 0
	ldr r1, _08031C54
	mov r2, r9
	bl sub_800D158
	ldr r0, [r7]
	ldr r3, [r0, 0x10]
	mov r1, r8
	str r1, [sp]
	b _08031C8A
	.align 2, 0
_08031C54: .4byte gUnknown_80E1F60
_08031C58:
	ldrb r1, [r4, 0x10]
	mov r0, r9
	movs r2, 0
	bl sub_8090DC4
	adds r0, r5, 0
	ldr r1, _08031C6C
	mov r2, r9
	b _08031C7E
	.align 2, 0
_08031C6C: .4byte gUnknown_80E1F70
_08031C70:
	movs r1, 0xE
	ldrsh r0, [r4, r1]
	bl GetMonSpecies
	adds r2, r0, 0
	adds r0, r5, 0
	ldr r1, _08031C98
_08031C7E:
	bl sub_800D158
	ldr r0, [r7]
	ldr r3, [r0, 0x10]
	mov r2, r8
	str r2, [sp]
_08031C8A:
	movs r0, 0x28
	adds r1, r6, 0
	adds r2, r5, 0
	bl xxx_call_draw_string
	b _08031CC0
	.align 2, 0
_08031C98: .4byte gUnknown_80E1F80
_08031C9C:
	movs r1, 0xE
	ldrsh r0, [r4, r1]
	bl GetMonSpecies
	adds r2, r0, 0
	adds r0, r5, 0
	ldr r1, _08031CD0
	bl sub_800D158
	ldr r0, [r7]
	ldr r3, [r0, 0x10]
	mov r2, r8
	str r2, [sp]
	movs r0, 0x28
	adds r1, r6, 0
	adds r2, r5, 0
	bl xxx_call_draw_string
_08031CC0:
	adds r6, 0xC
_08031CC2:
	movs r0, 0x1
	add r10, r0
	mov r1, r10
	cmp r1, 0x7
	bgt _08031CCE
	b _08031BC2
_08031CCE:
	b _08031D4E
	.align 2, 0
_08031CD0: .4byte gUnknown_80E1F40
_08031CD4:
	add r0, sp, 0xD0
	mov r4, sp
	adds r4, 0xD2
	adds r1, r4, 0
	bl sub_80992E0
	lsls r0, 24
	lsrs r5, r0, 24
	cmp r5, 0
	beq _08031D04
	movs r2, 0
	ldrsh r0, [r4, r2]
	bl GetCurrentMissionText
	adds r2, r0, 0
	ldr r0, _08031D00
	ldr r0, [r0]
	ldr r3, [r0, 0x10]
	movs r0, 0
	str r0, [sp]
	b _08031D2C
	.align 2, 0
_08031D00: .4byte gUnknown_203B330
_08031D04:
	add r4, sp, 0xD4
	adds r0, r4, 0
	bl sub_8099360
	lsls r0, 24
	lsrs r1, r0, 24
	cmp r1, 0
	beq _08031D3C
	ldrb r0, [r4]
	bl sub_80A2688
	lsls r0, 16
	asrs r0, 16
	bl sub_80975DC
	adds r2, r0, 0
	ldr r0, _08031D38
	ldr r0, [r0]
	ldr r3, [r0, 0x10]
	str r5, [sp]
_08031D2C:
	movs r0, 0xA
	movs r1, 0x10
	bl xxx_call_draw_string
	b _08031D4E
	.align 2, 0
_08031D38: .4byte gUnknown_203B330
_08031D3C:
	ldr r2, _08031D68
	ldr r0, _08031D6C
	ldr r0, [r0]
	ldr r3, [r0, 0x10]
	str r1, [sp]
	movs r0, 0xA
	movs r1, 0x10
	bl xxx_call_draw_string
_08031D4E:
	ldr r0, _08031D6C
	ldr r0, [r0]
	ldr r0, [r0, 0x10]
	bl sub_80073E0
	add sp, 0xDC
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_08031D68: .4byte gUnknown_80E1F94
_08031D6C: .4byte gUnknown_203B330
	thumb_func_end sub_8031AE8

	thumb_func_start sub_8031D70
sub_8031D70:
	push {r4-r6,lr}
	adds r6, r0, 0
	adds r4, r1, 0
	ldr r5, _08031DC4
	movs r0, 0x7C
	movs r1, 0x8
	bl MemoryAlloc
	str r0, [r5]
	stm r0!, {r6}
	bl sub_801317C
	ldr r0, [r5]
	str r4, [r0, 0x10]
	lsls r1, r4, 1
	adds r1, r4
	lsls r1, 3
	adds r1, 0x18
	adds r1, r0, r1
	str r1, [r0, 0x14]
	adds r0, 0x18
	bl sub_8006518
	ldr r1, [r5]
	ldr r2, [r1, 0x10]
	lsls r0, r2, 1
	adds r0, r2
	lsls r0, 3
	adds r1, r0
	adds r1, 0x18
	ldr r0, _08031DC8
	ldm r0!, {r2-r4}
	stm r1!, {r2-r4}
	ldm r0!, {r2-r4}
	stm r1!, {r2-r4}
	bl sub_8031E00
	movs r0, 0x1
	pop {r4-r6}
	pop {r1}
	bx r1
	.align 2, 0
_08031DC4: .4byte gUnknown_203B334
_08031DC8: .4byte gUnknown_80E1FC4
	thumb_func_end sub_8031D70

	thumb_func_start sub_8031DCC
sub_8031DCC:
	push {lr}
	ldr r0, _08031DEC
	ldr r1, [r0]
	adds r0, r1, 0x4
	ldr r1, [r1, 0x10]
	bl sub_8012A64
	cmp r0, 0x1
	beq _08031DF0
	cmp r0, 0x2
	bne _08031DFA
	movs r0, 0x1
	bl PlayMenuSoundEffect
	movs r0, 0x2
	b _08031DFC
	.align 2, 0
_08031DEC: .4byte gUnknown_203B334
_08031DF0:
	movs r0, 0
	bl PlayMenuSoundEffect
	movs r0, 0x3
	b _08031DFC
_08031DFA:
	movs r0, 0
_08031DFC:
	pop {r1}
	bx r1
	thumb_func_end sub_8031DCC

	thumb_func_start sub_8031E00
sub_8031E00:
	push {lr}
	bl sub_8031E58
	bl sub_8031E74
	pop {r0}
	bx r0
	thumb_func_end sub_8031E00

	thumb_func_start sub_8031E10
sub_8031E10:
	push {r4,r5,lr}
	ldr r4, _08031E50
	ldr r2, [r4]
	cmp r2, 0
	beq _08031E4A
	ldr r0, [r2, 0x10]
	lsls r1, r0, 1
	adds r1, r0
	lsls r1, 3
	adds r1, r2, r1
	adds r1, 0x18
	ldr r0, _08031E54
	ldm r0!, {r2,r3,r5}
	stm r1!, {r2,r3,r5}
	ldm r0!, {r2,r3,r5}
	stm r1!, {r2,r3,r5}
	bl ResetUnusedInputStruct
	ldr r0, [r4]
	adds r0, 0x18
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	ldr r0, [r4]
	bl MemoryFree
	movs r0, 0
	str r0, [r4]
_08031E4A:
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_08031E50: .4byte gUnknown_203B334
_08031E54: .4byte gUnknown_80E1FA8
	thumb_func_end sub_8031E10

	thumb_func_start sub_8031E58
sub_8031E58:
	push {lr}
	bl ResetUnusedInputStruct
	ldr r0, _08031E70
	ldr r0, [r0]
	adds r0, 0x18
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	pop {r0}
	bx r0
	.align 2, 0
_08031E70: .4byte gUnknown_203B334
	thumb_func_end sub_8031E58

	thumb_func_start sub_8031E74
sub_8031E74:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0x3C
	ldr r3, _08031EC0
	ldr r5, _08031EC4
	ldr r2, [r5]
	ldr r1, [r2]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 4
	ldr r4, [r3]
	adds r4, r0
	ldr r0, [r2, 0x10]
	bl sub_80073B8
	ldr r2, _08031EC8
	ldr r0, [r5]
	ldr r3, [r0, 0x10]
	movs r0, 0
	str r0, [sp]
	movs r0, 0x14
	movs r1, 0
	bl xxx_call_draw_string
	add r0, sp, 0x4
	adds r1, r4, 0
	bl sub_803D2C0
	movs r7, 0
	mov r8, r5
_08031EB2:
	cmp r7, 0x4
	ble _08031ED0
	cmp r7, 0xC
	bgt _08031ECC
	movs r6, 0x6
	movs r5, 0x16
	b _08031F00
	.align 2, 0
_08031EC0: .4byte gUnknown_203B480
_08031EC4: .4byte gUnknown_203B334
_08031EC8: .4byte gUnknown_80E1FDC
_08031ECC:
	cmp r7, 0x11
	bgt _08031ED6
_08031ED0:
	movs r6, 0x7
	movs r5, 0x15
	b _08031F00
_08031ED6:
	cmp r7, 0x16
	ble _08031EE8
	cmp r7, 0x1E
	bgt _08031EE4
	movs r6, 0x6
	movs r5, 0x25
	b _08031F00
_08031EE4:
	cmp r7, 0x23
	bgt _08031EEE
_08031EE8:
	movs r6, 0x7
	movs r5, 0x24
	b _08031F00
_08031EEE:
	cmp r7, 0x28
	ble _08031EFC
	cmp r7, 0x30
	bgt _08031EFC
	movs r6, 0x6
	movs r5, 0x34
	b _08031F00
_08031EFC:
	movs r6, 0x7
	movs r5, 0x33
_08031F00:
	adds r0, r7, 0
	movs r1, 0x12
	bl __modsi3
	movs r1, 0xB
	adds r4, r0, 0
	muls r4, r1
	adds r4, 0x6
	mov r0, sp
	adds r0, r7
	adds r0, 0x4
	ldrb r2, [r0]
	mov r1, r8
	ldr r0, [r1]
	ldr r0, [r0, 0x10]
	str r0, [sp]
	adds r0, r4, 0
	adds r1, r5, 0
	adds r3, r6, 0
	bl sub_8012C60
	mov r1, r8
	ldr r0, [r1]
	ldr r0, [r0, 0x10]
	adds r2, r5, 0
	adds r2, 0xA
	movs r1, 0x5
	str r1, [sp]
	adds r1, r4, 0
	movs r3, 0xA
	bl sub_80078A4
	adds r7, 0x1
	cmp r7, 0x35
	ble _08031EB2
	ldr r0, _08031F5C
	ldr r0, [r0]
	ldr r0, [r0, 0x10]
	bl sub_80073E0
	add sp, 0x3C
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_08031F5C: .4byte gUnknown_203B334
	thumb_func_end sub_8031E74

        .align 2,0
