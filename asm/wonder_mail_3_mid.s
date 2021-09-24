        .include "constants/gba_constants.inc"
	.include "asm/macros.inc"

	.syntax unified

	.text

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
	bl PlaySound
	ldr r0, _0802F414
	ldr r0, [r0]
	ldr r0, [r0, 0x10]
	ldr r0, [r0, 0x18]
	bl AddToTeamMoney
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
	bl AddToTeamMoney
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
	bl PlaySound
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
	bl PlaySound
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
	bl IsThrowableItem
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
	bl PlaySound
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
	bl PlaySound
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

        .align 2,0
