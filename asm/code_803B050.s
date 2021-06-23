        .include "constants/gba_constants.inc"
	.include "asm/macros.inc"

	.syntax unified

	.text	

        thumb_func_start sub_803B050
sub_803B050:
	push {r4-r7,lr}
	ldr r4, _0803B0F4
	movs r0, 0xF4
	lsls r0, 2
	movs r1, 0x8
	bl MemoryAlloc
	str r0, [r4]
	movs r1, 0x3
	str r1, [r0, 0x34]
	adds r1, r0, 0
	adds r1, 0x84
	str r1, [r0, 0x38]
	adds r0, 0x3C
	bl sub_8006518
	ldr r1, [r4]
	ldr r2, [r1, 0x34]
	lsls r0, r2, 1
	adds r0, r2
	lsls r0, 3
	adds r1, r0
	adds r1, 0x3C
	ldr r0, _0803B0F8
	ldm r0!, {r2,r3,r5}
	stm r1!, {r2,r3,r5}
	ldm r0!, {r2,r3,r5}
	stm r1!, {r2,r3,r5}
	ldr r0, [r4]
	ldr r1, [r0, 0x38]
	adds r0, 0x9C
	str r0, [r1, 0x14]
	bl ResetUnusedInputStruct
	ldr r0, [r4]
	adds r0, 0x3C
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	movs r2, 0
	movs r3, 0
	movs r7, 0xCB
	lsls r7, 1
	movs r6, 0x80
	lsls r6, 9
	movs r5, 0
_0803B0AE:
	ldr r0, _0803B0FC
	adds r0, r5, r0
	movs r1, 0x2
	ldrsh r0, [r0, r1]
	ldr r4, _0803B0F4
	cmp r0, 0xA
	bne _0803B0C8
	ldr r0, [r4]
	lsls r1, r2, 1
	adds r0, 0xA0
	adds r0, r1
	strh r3, [r0]
	adds r2, 0x1
_0803B0C8:
	adds r0, r6, 0
	movs r3, 0x80
	lsls r3, 9
	adds r6, r3
	adds r5, 0xC
	asrs r3, r0, 16
	cmp r3, r7
	ble _0803B0AE
	ldr r0, [r4]
	ldr r3, [r0, 0x34]
	adds r1, r2, 0
	movs r2, 0xA
	bl sub_8013818
	bl sub_803B204
	bl sub_803B284
	movs r0, 0x1
	pop {r4-r7}
	pop {r1}
	bx r1
	.align 2, 0
_0803B0F4: .4byte gUnknown_203B3FC
_0803B0F8: .4byte gUnknown_80E7F54
_0803B0FC: .4byte gFunctionScriptTable
	thumb_func_end sub_803B050

	thumb_func_start sub_803B100
sub_803B100:
	push {lr}
	adds r1, r0, 0
	lsls r1, 16
	asrs r1, 16
	ldr r0, _0803B11C
	ldr r0, [r0]
	bl sub_8013878
	bl sub_803B204
	bl sub_803B284
	pop {r0}
	bx r0
	.align 2, 0
_0803B11C: .4byte gUnknown_203B3FC
	thumb_func_end sub_803B100

	thumb_func_start sub_803B120
sub_803B120:
	push {r4,lr}
	ldr r4, _0803B13C
	ldr r0, [r4]
	bl GetKeyPress
	cmp r0, 0x1
	beq _0803B140
	cmp r0, 0x2
	bne _0803B144
	movs r0, 0x1
	bl PlayMenuSoundEffect
	movs r0, 0x2
	b _0803B160
	.align 2, 0
_0803B13C: .4byte gUnknown_203B3FC
_0803B140:
	movs r0, 0x3
	b _0803B160
_0803B144:
	ldr r0, [r4]
	movs r1, 0x1
	bl sub_80138B8
	lsls r0, 24
	cmp r0, 0
	bne _0803B156
	movs r0, 0
	b _0803B160
_0803B156:
	bl sub_803B204
	bl sub_803B284
	movs r0, 0x1
_0803B160:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_803B120

	thumb_func_start sub_803B168
sub_803B168:
	ldr r0, _0803B188
	ldr r0, [r0]
	movs r1, 0x1E
	ldrsh r2, [r0, r1]
	movs r3, 0x1C
	ldrsh r1, [r0, r3]
	muls r1, r2
	movs r3, 0x18
	ldrsh r2, [r0, r3]
	adds r1, r2
	lsls r1, 1
	adds r0, 0xA0
	adds r0, r1
	movs r1, 0
	ldrsh r0, [r0, r1]
	bx lr
	.align 2, 0
_0803B188: .4byte gUnknown_203B3FC
	thumb_func_end sub_803B168

	thumb_func_start sub_803B18C
sub_803B18C:
	push {r4,r5,lr}
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	ldr r5, _0803B1B8
	ldr r0, [r5]
	movs r1, 0xE5
	strh r1, [r0, 0x22]
	bl sub_8013984
	bl sub_803B204
	bl sub_803B284
	cmp r4, 0
	beq _0803B1B2
	ldr r0, [r5]
	bl AddMenuCursorSprite
_0803B1B2:
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_0803B1B8: .4byte gUnknown_203B3FC
	thumb_func_end sub_803B18C

	thumb_func_start sub_803B1BC
sub_803B1BC:
	push {r4,r5,lr}
	ldr r4, _0803B1FC
	ldr r2, [r4]
	cmp r2, 0
	beq _0803B1F6
	ldr r0, [r2, 0x34]
	lsls r1, r0, 1
	adds r1, r0
	lsls r1, 3
	adds r1, r2, r1
	adds r1, 0x3C
	ldr r0, _0803B200
	ldm r0!, {r2,r3,r5}
	stm r1!, {r2,r3,r5}
	ldm r0!, {r2,r3,r5}
	stm r1!, {r2,r3,r5}
	bl ResetUnusedInputStruct
	ldr r0, [r4]
	adds r0, 0x3C
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	ldr r0, [r4]
	bl MemoryFree
	movs r0, 0
	str r0, [r4]
_0803B1F6:
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_0803B1FC: .4byte gUnknown_203B3FC
_0803B200: .4byte gUnknown_80E7F3C
	thumb_func_end sub_803B1BC

	thumb_func_start sub_803B204
sub_803B204:
	push {r4,lr}
	ldr r4, _0803B280
	ldr r0, [r4]
	adds r0, 0x9C
	movs r2, 0
	movs r1, 0x1
	strb r1, [r0]
	ldr r0, [r4]
	adds r0, 0x9D
	strb r2, [r0]
	ldr r0, [r4]
	adds r0, 0x9E
	movs r1, 0x8
	strb r1, [r0]
	ldr r0, [r4]
	adds r0, 0x9F
	strb r2, [r0]
	bl ResetUnusedInputStruct
	ldr r0, [r4]
	adds r0, 0x3C
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	ldr r0, [r4]
	movs r1, 0x1A
	ldrsh r0, [r0, r1]
	movs r1, 0xC
	bl sub_80095E4
	adds r0, 0x2
	lsls r0, 16
	ldr r2, [r4]
	ldr r3, [r2, 0x34]
	lsls r1, r3, 1
	adds r1, r3
	lsls r1, 3
	adds r1, r2, r1
	adds r1, 0x4A
	asrs r3, r0, 16
	lsrs r0, 16
	strh r0, [r1]
	ldr r1, [r2, 0x34]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 3
	adds r2, r0
	adds r3, 0x2
	adds r2, 0x4C
	strh r3, [r2]
	bl ResetUnusedInputStruct
	ldr r0, [r4]
	adds r0, 0x3C
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0803B280: .4byte gUnknown_203B3FC
	thumb_func_end sub_803B204

	thumb_func_start sub_803B284
sub_803B284:
	push {r4-r6,lr}
	sub sp, 0x8
	ldr r6, _0803B338
	ldr r0, [r6]
	ldr r0, [r0, 0x34]
	bl sub_8008C54
	ldr r0, [r6]
	ldr r0, [r0, 0x34]
	bl sub_80073B8
	ldr r2, _0803B33C
	ldr r0, [r6]
	ldr r3, [r0, 0x34]
	movs r0, 0
	str r0, [sp]
	movs r0, 0xA
	movs r1, 0
	bl xxx_call_draw_string
	ldr r1, [r6]
	adds r0, r1, 0
	adds r0, 0x9E
	ldrb r4, [r0]
	lsls r4, 3
	subs r4, 0x2
	movs r0, 0x1E
	ldrsh r2, [r1, r0]
	adds r2, 0x1
	movs r0, 0x7
	str r0, [sp]
	ldr r0, [r1, 0x34]
	str r0, [sp, 0x4]
	adds r0, r4, 0
	movs r1, 0
	movs r3, 0x2
	bl sub_8012BC4
	movs r5, 0
	ldr r0, [r6]
	movs r1, 0x1A
	ldrsh r0, [r0, r1]
	cmp r5, r0
	bge _0803B324
_0803B2DC:
	ldr r0, [r6]
	movs r3, 0x1E
	ldrsh r2, [r0, r3]
	movs r3, 0x1C
	ldrsh r1, [r0, r3]
	muls r2, r1
	adds r2, r5
	lsls r2, 1
	adds r1, r0, 0
	adds r1, 0xA0
	adds r1, r2
	movs r2, 0
	ldrsh r1, [r1, r2]
	lsls r4, r1, 1
	adds r4, r1
	lsls r4, 2
	ldr r1, _0803B340
	adds r4, r1
	adds r1, r5, 0
	bl sub_8013800
	adds r1, r0, 0
	ldr r2, [r4, 0x4]
	ldr r0, [r6]
	ldr r3, [r0, 0x34]
	movs r0, 0
	str r0, [sp]
	movs r0, 0x8
	bl xxx_call_draw_string
	adds r5, 0x1
	ldr r0, [r6]
	movs r3, 0x1A
	ldrsh r0, [r0, r3]
	cmp r5, r0
	blt _0803B2DC
_0803B324:
	ldr r0, _0803B338
	ldr r0, [r0]
	ldr r0, [r0, 0x34]
	bl sub_80073E0
	add sp, 0x8
	pop {r4-r6}
	pop {r0}
	bx r0
	.align 2, 0
_0803B338: .4byte gUnknown_203B3FC
_0803B33C: .4byte gUnknown_80E7F6C
_0803B340: .4byte gFunctionScriptTable
	thumb_func_end sub_803B284

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

	thumb_func_start sub_803B6B0
sub_803B6B0:
	push {r4,lr}
	sub sp, 0x4
	lsls r2, 24
	ldr r4, _0803B6D0
	lsrs r2, 22
	adds r2, r4
	ldr r2, [r2]
	movs r4, 0
	str r4, [sp]
	bl xxx_call_draw_string
	add sp, 0x4
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0803B6D0: .4byte gUnknown_80E8B94
	thumb_func_end sub_803B6B0

	thumb_func_start sub_803B6D4
sub_803B6D4:
	push {r4-r7,lr}
	sub sp, 0x144
	adds r7, r0, 0
	ldr r1, [r7, 0x48]
	adds r0, 0x43
	ldrb r2, [r0]
	ldr r3, [r7]
	movs r0, 0xA
	bl sub_803B6B0
	adds r0, r7, 0
	adds r0, 0x40
	ldrb r0, [r0]
	cmp r0, 0xC
	bls _0803B6F4
	b _0803B86C
_0803B6F4:
	lsls r0, 2
	ldr r1, _0803B700
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0803B700: .4byte _0803B704
	.align 2, 0
_0803B704:
	.4byte _0803B73E
	.4byte _0803B748
	.4byte _0803B754
	.4byte _0803B738
	.4byte _0803B7A4
	.4byte _0803B7B0
	.4byte _0803B7C8
	.4byte _0803B760
	.4byte _0803B86C
	.4byte _0803B818
	.4byte _0803B7E0
	.4byte _0803B788
	.4byte _0803B76A
_0803B738:
	ldr r1, [r7, 0x48]
	ldr r2, [r7, 0x4C]
	b _0803B7CC
_0803B73E:
	ldr r1, [r7, 0x48]
	ldr r2, _0803B744
	b _0803B7CC
	.align 2, 0
_0803B744: .4byte gMankeyMission
_0803B748:
	ldr r1, [r7, 0x48]
	ldr r2, _0803B750
	b _0803B7CC
	.align 2, 0
_0803B750: .4byte gSmeargleMission
_0803B754:
	ldr r1, [r7, 0x48]
	ldr r2, _0803B75C
	b _0803B7CC
	.align 2, 0
_0803B75C: .4byte gMedichamMission
_0803B760:
	ldr r1, [r7, 0x8]
	add r0, sp, 0x4
	bl sub_8090208
	b _0803B850
_0803B76A:
	ldr r4, _0803B780
	ldrb r1, [r7, 0x14]
	adds r0, r4, 0
	movs r2, 0
	bl sub_8090DC4
	ldr r1, _0803B784
	add r0, sp, 0x4
	adds r2, r4, 0
	b _0803B84C
	.align 2, 0
_0803B780: .4byte gUnknown_202DE58
_0803B784: .4byte gUnknown_80E8830
_0803B788:
	ldr r4, _0803B79C
	ldrb r1, [r7, 0x14]
	adds r0, r4, 0
	movs r2, 0
	bl sub_8090DC4
	ldr r1, _0803B7A0
	add r0, sp, 0x4
	adds r2, r4, 0
	b _0803B84C
	.align 2, 0
_0803B79C: .4byte gUnknown_202DE58
_0803B7A0: .4byte gUnknown_80E8848
_0803B7A4:
	ldr r1, [r7, 0x48]
	ldr r2, _0803B7AC
	b _0803B7CC
	.align 2, 0
_0803B7AC: .4byte gUnknown_80E885C
_0803B7B0:
	ldr r1, [r7, 0x48]
	ldr r3, _0803B7C4
	ldr r2, [r7, 0x4]
	lsls r0, r2, 1
	adds r0, r2
	lsls r0, 2
	adds r3, 0x4
	adds r0, r3
	ldr r2, [r0]
	b _0803B7CC
	.align 2, 0
_0803B7C4: .4byte gUnknown_80E9F8C
_0803B7C8:
	ldr r1, [r7, 0x48]
	ldr r2, _0803B7DC
_0803B7CC:
	ldr r3, [r7]
	movs r0, 0
	str r0, [sp]
	movs r0, 0x15
	bl xxx_call_draw_string
	b _0803B8B4
	.align 2, 0
_0803B7DC: .4byte gUnknown_80E886C
_0803B7E0:
	ldr r0, [r7, 0x8]
	ldr r4, [r0, 0x4]
	ldrb r0, [r0]
	adds r4, r0
	lsls r4, 24
	lsrs r4, 24
	movs r1, 0x12
	ldrsh r0, [r7, r1]
	bl GetMonSpecies
	adds r1, r0, 0
	ldr r5, _0803B810
	adds r0, r5, 0
	bl strcpy
	ldr r1, _0803B814
	movs r0, 0x3
	ands r4, r0
	lsls r4, 2
	adds r4, r1
	ldr r1, [r4]
	add r0, sp, 0x4
	adds r2, r5, 0
	b _0803B84C
	.align 2, 0
_0803B810: .4byte gAvailablePokemonNames
_0803B814: .4byte gUnknown_80EAE5C
_0803B818:
	ldr r0, [r7, 0x8]
	ldr r4, [r0, 0x4]
	ldrb r0, [r0]
	adds r4, r0
	lsls r4, 24
	lsrs r4, 24
	movs r1, 0x12
	ldrsh r0, [r7, r1]
	bl GetMonSpecies
	adds r1, r0, 0
	ldr r6, _0803B864
	adds r0, r6, 0
	bl strcpy
	ldr r5, _0803B868
	adds r0, r4, 0
	movs r1, 0xA
	bl __umodsi3
	lsls r0, 24
	lsrs r0, 22
	adds r0, r5
	ldr r1, [r0]
	add r0, sp, 0x4
	adds r2, r6, 0
_0803B84C:
	bl ExpandPlaceholdersBuffer
_0803B850:
	ldr r1, [r7, 0x48]
	ldr r3, [r7]
	movs r0, 0
	str r0, [sp]
	movs r0, 0x15
	add r2, sp, 0x4
	bl xxx_call_draw_string
	b _0803B8B4
	.align 2, 0
_0803B864: .4byte gAvailablePokemonNames
_0803B868: .4byte gUnknown_80E910C
_0803B86C:
	ldr r0, [r7, 0x8]
	ldr r4, [r0, 0x4]
	ldrb r0, [r0]
	adds r4, r0
	lsls r4, 24
	lsrs r4, 24
	movs r1, 0x12
	ldrsh r0, [r7, r1]
	bl GetMonSpecies
	adds r1, r0, 0
	ldr r6, _0803B8E8
	adds r0, r6, 0
	bl strcpy
	ldr r5, _0803B8EC
	adds r0, r4, 0
	movs r1, 0xF
	bl __umodsi3
	lsls r0, 24
	lsrs r0, 22
	adds r0, r5
	ldr r1, [r0]
	add r0, sp, 0x4
	adds r2, r6, 0
	bl ExpandPlaceholdersBuffer
	ldr r1, [r7, 0x48]
	ldr r3, [r7]
	movs r0, 0
	str r0, [sp]
	movs r0, 0x15
	add r2, sp, 0x4
	bl xxx_call_draw_string
_0803B8B4:
	adds r0, r7, 0
	adds r0, 0x40
	ldrb r1, [r0]
	adds r6, r0, 0
	cmp r1, 0x7
	bne _0803B916
	ldr r5, [r7, 0xC]
	cmp r5, 0
	bne _0803B8F0
	bl sub_8016028
	movs r4, 0xB2
	subs r4, r0
	movs r1, 0x10
	ldrsh r0, [r7, r1]
	bl GetMonSpecies
	adds r2, r0, 0
	ldr r1, [r7, 0x48]
	ldr r3, [r7]
	str r5, [sp]
	adds r0, r4, 0
	bl xxx_call_draw_string
	b _0803B956
	.align 2, 0
_0803B8E8: .4byte gAvailablePokemonNames
_0803B8EC: .4byte gUnknown_80E8C98
_0803B8F0:
	add r4, sp, 0xCC
	adds r0, r4, 0
	adds r1, r5, 0
	movs r2, 0xA
	bl sub_80922B4
	bl sub_8016028
	adds r1, r0, 0
	movs r0, 0xB2
	subs r0, r1
	ldr r1, [r7, 0x48]
	ldr r3, [r7]
	movs r2, 0
	str r2, [sp]
	adds r2, r4, 0
	bl xxx_call_draw_string
	b _0803B956
_0803B916:
	adds r0, r7, 0
	adds r0, 0x42
	ldrb r0, [r0]
	cmp r0, 0x1
	bne _0803B93C
	add r4, sp, 0xE0
	ldr r1, [r7, 0x8]
	adds r0, r4, 0
	bl PrintDungeonLocationtoBuffer
	ldr r1, _0803B938
	add r0, sp, 0x4
	adds r2, r4, 0
	bl ExpandPlaceholdersBuffer
	b _0803B944
	.align 2, 0
_0803B938: .4byte gUnknown_80E8884
_0803B93C:
	ldr r1, [r7, 0x8]
	add r0, sp, 0x4
	bl PrintDungeonLocationtoBuffer
_0803B944:
	ldr r1, [r7, 0x48]
	adds r1, 0xC
	ldr r3, [r7]
	movs r0, 0
	str r0, [sp]
	movs r0, 0x1D
	add r2, sp, 0x4
	bl xxx_call_draw_string
_0803B956:
	ldrb r0, [r6]
	cmp r0, 0x7
	bne _0803B962
	ldr r0, [r7, 0x8]
	movs r1, 0
	b _0803B968
_0803B962:
	ldr r0, [r7, 0x8]
	ldr r1, [r7, 0x54]
	ldrb r1, [r1, 0x1]
_0803B968:
	bl sub_803C1D0
	lsls r0, 24
	lsrs r0, 24
	bl sub_803C1F0
	adds r2, r0, 0
	ldr r1, [r7, 0x48]
	ldr r3, [r7]
	movs r0, 0
	str r0, [sp]
	movs r0, 0xB4
	bl xxx_call_draw_string
	add sp, 0x144
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_803B6D4

	thumb_func_start CreateRescueDescription
CreateRescueDescription:
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	sub sp, 0x1FC
	adds r7, r0, 0
	movs r0, 0
	mov r9, r0
	ldr r2, _0803B9E0
	ldr r3, [r7]
	str r0, [sp]
	movs r0, 0xA
	movs r1, 0
	bl xxx_call_draw_string
	ldr r1, _0803B9E4
	adds r0, r7, 0
	adds r0, 0x44
	ldrb r0, [r0]
	lsls r0, 2
	adds r0, r1
	ldr r2, [r0]
	ldr r3, [r7]
	mov r1, r9
	str r1, [sp]
	movs r0, 0x6C
	movs r1, 0
	bl xxx_call_draw_string
	movs r0, 0x10
	mov r9, r0
	adds r0, r7, 0
	adds r0, 0x41
	ldrb r0, [r0]
	cmp r0, 0x10
	bls _0803B9D6
	b _0803BCC0
_0803B9D6:
	lsls r0, 2
	ldr r1, _0803B9E8
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0803B9E0: .4byte gUnknown_80E888C
_0803B9E4: .4byte gUnknown_80E8BCC
_0803B9E8: .4byte _0803B9EC
	.align 2, 0
_0803B9EC:
	.4byte _0803BA34
	.4byte _0803BA3C
	.4byte _0803BA44
	.4byte _0803BA30
	.4byte _0803BA4C
	.4byte _0803BA6C
	.4byte _0803BA8C
	.4byte _0803BAA0
	.4byte _0803BBF0
	.4byte _0803BAE8
	.4byte _0803BAF0
	.4byte _0803BAF8
	.4byte _0803BCC0
	.4byte _0803BC58
	.4byte _0803BB74
	.4byte _0803BB10
	.4byte _0803BB10
_0803BA30:
	ldr r2, [r7, 0x50]
	b _0803BAFA
_0803BA34:
	ldr r2, _0803BA38
	b _0803BAFA
	.align 2, 0
_0803BA38: .4byte gMankeyMissionDescription
_0803BA3C:
	ldr r2, _0803BA40
	b _0803BAFA
	.align 2, 0
_0803BA40: .4byte gSmeargleMissionDescription
_0803BA44:
	ldr r2, _0803BA48
	b _0803BAFA
	.align 2, 0
_0803BA48: .4byte gMedichamMissionDescription
_0803BA4C:
	ldr r4, _0803BA64
	ldrb r1, [r7, 0x14]
	adds r0, r4, 0
	movs r2, 0
	bl sub_8090DC4
	ldr r1, _0803BA68
	add r0, sp, 0x4
	adds r2, r4, 0
	bl ExpandPlaceholdersBuffer
	b _0803BACC
	.align 2, 0
_0803BA64: .4byte gUnknown_202DE58
_0803BA68: .4byte gUnknown_80E8968
_0803BA6C:
	ldr r4, _0803BA84
	ldrb r1, [r7, 0x14]
	adds r0, r4, 0
	movs r2, 0
	bl sub_8090DC4
	ldr r1, _0803BA88
	add r0, sp, 0x4
	adds r2, r4, 0
	bl ExpandPlaceholdersBuffer
	b _0803BACC
	.align 2, 0
_0803BA84: .4byte gUnknown_202DE58
_0803BA88: .4byte gUnknown_80E89B0
_0803BA8C:
	ldr r1, _0803BA9C
	ldr r0, [r7, 0x4]
	lsls r0, 3
	adds r1, 0x4
	adds r0, r1
	ldr r2, [r0]
	b _0803BAFA
	.align 2, 0
_0803BA9C: .4byte gUnknown_80E9920
_0803BAA0:
	movs r1, 0x12
	ldrsh r0, [r7, r1]
	bl GetMonSpecies
	adds r1, r0, 0
	ldr r4, _0803BAE0
	adds r0, r4, 0
	bl strcpy
	ldr r2, _0803BAE4
	ldr r1, [r7, 0x4]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 2
	adds r2, 0x8
	adds r0, r2
	ldr r1, [r0]
	add r0, sp, 0x4
	adds r2, r4, 0
	adds r3, r4, 0
	bl ExpandPlaceholdersBuffer
_0803BACC:
	ldr r3, [r7]
	movs r0, 0
	str r0, [sp]
	movs r0, 0xA
	mov r1, r9
	add r2, sp, 0x4
	bl xxx_call_draw_string
	b _0803BD42
	.align 2, 0
_0803BAE0: .4byte gAvailablePokemonNames
_0803BAE4: .4byte gUnknown_80E9F8C
_0803BAE8:
	ldr r2, _0803BAEC
	b _0803BAFA
	.align 2, 0
_0803BAEC: .4byte gUnknown_80E89FC
_0803BAF0:
	ldr r2, _0803BAF4
	b _0803BAFA
	.align 2, 0
_0803BAF4: .4byte gUnknown_80E8A40
_0803BAF8:
	ldr r2, _0803BB0C
_0803BAFA:
	ldr r3, [r7]
	movs r0, 0
	str r0, [sp]
	movs r0, 0xA
	mov r1, r9
	bl xxx_call_draw_string
	b _0803BD42
	.align 2, 0
_0803BB0C: .4byte gUnknown_80E8A7C
_0803BB10:
	ldr r0, [r7, 0x8]
	ldr r5, [r0, 0x4]
	ldrb r4, [r0]
	adds r4, r5, r4
	lsls r4, 24
	lsrs r4, 24
	ldrb r0, [r0, 0x1]
	adds r5, r0
	lsls r5, 24
	lsrs r5, 24
	ldr r0, _0803BB68
	mov r8, r0
	ldrb r1, [r7, 0x14]
	movs r2, 0
	bl sub_8090DC4
	ldr r6, _0803BB6C
	adds r0, r4, 0
	movs r1, 0x16
	bl __umodsi3
	lsls r0, 24
	lsrs r0, 22
	adds r0, r6
	ldr r1, [r0]
	add r0, sp, 0x4
	mov r2, r8
	bl ExpandPlaceholdersBuffer
	ldr r3, [r7]
	movs r6, 0
	str r6, [sp]
	movs r0, 0xA
	mov r1, r9
	add r2, sp, 0x4
	bl xxx_call_draw_string
	movs r1, 0xC
	add r9, r1
	ldr r4, _0803BB70
	adds r0, r5, 0
	movs r1, 0x16
	b _0803BD1A
	.align 2, 0
_0803BB68: .4byte gUnknown_202DE58
_0803BB6C: .4byte gUnknown_80EB3F8
_0803BB70: .4byte gUnknown_80EB72C
_0803BB74:
	ldr r0, [r7, 0x8]
	ldr r5, [r0, 0x4]
	ldrb r4, [r0]
	adds r4, r5, r4
	lsls r4, 24
	lsrs r4, 24
	ldrb r0, [r0, 0x1]
	adds r5, r0
	lsls r5, 24
	lsrs r5, 24
	movs r1, 0x12
	ldrsh r0, [r7, r1]
	bl GetMonSpecies
	adds r1, r0, 0
	ldr r0, _0803BBE4
	mov r8, r0
	bl strcpy
	ldr r6, _0803BBE8
	adds r0, r4, 0
	movs r1, 0x14
	bl __umodsi3
	lsls r0, 24
	lsrs r0, 22
	adds r0, r6
	ldr r1, [r0]
	add r0, sp, 0x4
	mov r2, r8
	bl ExpandPlaceholdersBuffer
	ldr r3, [r7]
	movs r4, 0
	str r4, [sp]
	movs r0, 0xA
	mov r1, r9
	add r2, sp, 0x4
	bl xxx_call_draw_string
	movs r1, 0xC
	add r9, r1
	ldr r1, _0803BBEC
	movs r0, 0x3
	ands r5, r0
	lsls r5, 2
	adds r5, r1
	ldr r1, [r5]
	add r0, sp, 0x4
	mov r2, r8
	bl ExpandPlaceholdersBuffer
	ldr r3, [r7]
	str r4, [sp]
	b _0803BD32
	.align 2, 0
_0803BBE4: .4byte gAvailablePokemonNames
_0803BBE8: .4byte gUnknown_80EAEB8
_0803BBEC: .4byte gUnknown_80EB198
_0803BBF0:
	ldr r0, [r7, 0x8]
	ldr r5, [r0, 0x4]
	ldrb r4, [r0]
	adds r4, r5, r4
	lsls r4, 24
	lsrs r4, 24
	ldrb r0, [r0, 0x1]
	adds r5, r0
	lsls r5, 24
	lsrs r5, 24
	movs r1, 0x12
	ldrsh r0, [r7, r1]
	bl GetMonSpecies
	adds r1, r0, 0
	ldr r0, _0803BC4C
	mov r8, r0
	bl strcpy
	ldr r6, _0803BC50
	adds r0, r4, 0
	movs r1, 0x6
	bl __umodsi3
	lsls r0, 24
	lsrs r0, 22
	adds r0, r6
	ldr r1, [r0]
	add r0, sp, 0x4
	mov r2, r8
	bl ExpandPlaceholdersBuffer
	ldr r3, [r7]
	movs r6, 0
	str r6, [sp]
	movs r0, 0xA
	mov r1, r9
	add r2, sp, 0x4
	bl xxx_call_draw_string
	movs r1, 0xC
	add r9, r1
	ldr r4, _0803BC54
	adds r0, r5, 0
	movs r1, 0x6
	b _0803BD1A
	.align 2, 0
_0803BC4C: .4byte gAvailablePokemonNames
_0803BC50: .4byte gUnknown_80EB220
_0803BC54: .4byte gUnknown_80EB2F0
_0803BC58:
	ldr r0, [r7, 0x8]
	ldr r5, [r0, 0x4]
	ldrb r4, [r0]
	adds r4, r5, r4
	lsls r4, 24
	lsrs r4, 24
	ldrb r0, [r0, 0x1]
	adds r5, r0
	lsls r5, 24
	lsrs r5, 24
	movs r1, 0x12
	ldrsh r0, [r7, r1]
	bl GetMonSpecies
	adds r1, r0, 0
	ldr r0, _0803BCB4
	mov r8, r0
	bl strcpy
	ldr r6, _0803BCB8
	adds r0, r4, 0
	movs r1, 0x2D
	bl __umodsi3
	lsls r0, 24
	lsrs r0, 22
	adds r0, r6
	ldr r1, [r0]
	add r0, sp, 0x4
	mov r2, r8
	bl ExpandPlaceholdersBuffer
	ldr r3, [r7]
	movs r6, 0
	str r6, [sp]
	movs r0, 0xA
	mov r1, r9
	add r2, sp, 0x4
	bl xxx_call_draw_string
	movs r1, 0xC
	add r9, r1
	ldr r4, _0803BCBC
	adds r0, r5, 0
	movs r1, 0xA
	b _0803BD1A
	.align 2, 0
_0803BCB4: .4byte gAvailablePokemonNames
_0803BCB8: .4byte gUnknown_80E91D4
_0803BCBC: .4byte gUnknown_80E9820
_0803BCC0:
	ldr r0, [r7, 0x8]
	ldr r5, [r0, 0x4]
	ldrb r4, [r0]
	adds r4, r5, r4
	lsls r4, 24
	lsrs r4, 24
	ldrb r0, [r0, 0x1]
	adds r5, r0
	lsls r5, 24
	lsrs r5, 24
	movs r1, 0x10
	ldrsh r0, [r7, r1]
	bl GetMonSpecies
	adds r1, r0, 0
	ldr r0, _0803BD78
	mov r8, r0
	bl strcpy
	ldr r6, _0803BD7C
	adds r0, r4, 0
	movs r1, 0xD
	bl __umodsi3
	lsls r0, 24
	lsrs r0, 22
	adds r0, r6
	ldr r1, [r0]
	add r0, sp, 0x4
	mov r2, r8
	bl ExpandPlaceholdersBuffer
	ldr r3, [r7]
	movs r6, 0
	str r6, [sp]
	movs r0, 0xA
	mov r1, r9
	add r2, sp, 0x4
	bl xxx_call_draw_string
	movs r1, 0xC
	add r9, r1
	ldr r4, _0803BD80
	adds r0, r5, 0
	movs r1, 0xD
_0803BD1A:
	bl __umodsi3
	lsls r0, 24
	lsrs r0, 22
	adds r0, r4
	ldr r1, [r0]
	add r0, sp, 0x4
	mov r2, r8
	bl ExpandPlaceholdersBuffer
	ldr r3, [r7]
	str r6, [sp]
_0803BD32:
	movs r0, 0xA
	mov r1, r9
	add r2, sp, 0x4
	bl xxx_call_draw_string
	movs r0, 0xC
	negs r0, r0
	add r9, r0
_0803BD42:
	movs r1, 0x1C
	add r9, r1
	ldr r2, _0803BD84
	ldr r3, [r7]
	movs r0, 0
	mov r8, r0
	str r0, [sp]
	movs r0, 0xA
	mov r1, r9
	bl xxx_call_draw_string
	ldr r1, [r7, 0xC]
	cmp r1, 0
	bne _0803BD88
	movs r1, 0x10
	ldrsh r0, [r7, r1]
	bl GetMonSpecies
	adds r2, r0, 0
	ldr r3, [r7]
	mov r0, r8
	str r0, [sp]
	movs r0, 0x44
	mov r1, r9
	bl xxx_call_draw_string
	b _0803BDBC
	.align 2, 0
_0803BD78: .4byte gAvailablePokemonNames
_0803BD7C: .4byte gUnknown_80E8DE4
_0803BD80: .4byte gUnknown_80E8FB0
_0803BD84: .4byte gUnknown_80E8AC8
_0803BD88:
	add r6, sp, 0x158
	adds r0, r6, 0
	movs r2, 0xA
	bl sub_80922B4
	add r4, sp, 0x16C
	movs r0, 0x10
	ldrsh r1, [r7, r0]
	adds r0, r4, 0
	bl sub_808D930
	add r5, sp, 0x130
	ldr r1, _0803BDE8
	adds r0, r5, 0
	adds r2, r6, 0
	adds r3, r4, 0
	bl ExpandPlaceholdersBuffer
	ldr r3, [r7]
	mov r1, r8
	str r1, [sp]
	movs r0, 0x44
	mov r1, r9
	adds r2, r5, 0
	bl xxx_call_draw_string
_0803BDBC:
	movs r0, 0xC
	add r9, r0
	ldr r2, _0803BDEC
	ldr r3, [r7]
	movs r0, 0
	str r0, [sp]
	movs r0, 0xA
	mov r1, r9
	bl xxx_call_draw_string
	adds r0, r7, 0
	adds r0, 0x42
	ldrb r1, [r0]
	adds r5, r0, 0
	cmp r1, 0x6
	bhi _0803BEB8
	lsls r0, r1, 2
	ldr r1, _0803BDF0
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0803BDE8: .4byte gUnknown_80E8AD0
_0803BDEC: .4byte gUnknown_80E8AE0
_0803BDF0: .4byte _0803BDF4
	.align 2, 0
_0803BDF4:
	.4byte _0803BE10
	.4byte _0803BE30
	.4byte _0803BE18
	.4byte _0803BE48
	.4byte _0803BE80
	.4byte _0803BE60
	.4byte _0803BEB8
_0803BE10:
	ldr r2, _0803BE14
	b _0803BE4A
	.align 2, 0
_0803BE14: .4byte gUnknown_80E8AEC
_0803BE18:
	ldr r4, _0803BE28
	ldrb r1, [r7, 0x14]
	adds r0, r4, 0
	movs r2, 0
	bl sub_8090DC4
	ldr r1, _0803BE2C
	b _0803BE94
	.align 2, 0
_0803BE28: .4byte gUnknown_202DE58
_0803BE2C: .4byte gUnknown_80E8AFC
_0803BE30:
	ldr r4, _0803BE40
	ldrb r1, [r7, 0x14]
	adds r0, r4, 0
	movs r2, 0
	bl sub_8090DC4
	ldr r1, _0803BE44
	b _0803BE94
	.align 2, 0
_0803BE40: .4byte gUnknown_202DE58
_0803BE44: .4byte gUnknown_80E8B10
_0803BE48:
	ldr r2, _0803BE5C
_0803BE4A:
	ldr r3, [r7]
	movs r0, 0
	str r0, [sp]
	movs r0, 0x44
	mov r1, r9
	bl xxx_call_draw_string
	b _0803BEC8
	.align 2, 0
_0803BE5C: .4byte gUnknown_80E8B20
_0803BE60:
	movs r1, 0x12
	ldrsh r0, [r7, r1]
	bl GetMonSpecies
	adds r1, r0, 0
	ldr r4, _0803BE78
	adds r0, r4, 0
	bl strcpy
	ldr r1, _0803BE7C
	b _0803BE94
	.align 2, 0
_0803BE78: .4byte gAvailablePokemonNames
_0803BE7C: .4byte gUnknown_80E8B2C
_0803BE80:
	movs r1, 0x12
	ldrsh r0, [r7, r1]
	bl GetMonSpecies
	adds r1, r0, 0
	ldr r4, _0803BEB0
	adds r0, r4, 0
	bl strcpy
	ldr r1, _0803BEB4
_0803BE94:
	add r0, sp, 0x4
	adds r2, r4, 0
	bl ExpandPlaceholdersBuffer
	ldr r3, [r7]
	movs r0, 0
	str r0, [sp]
	movs r0, 0x44
	mov r1, r9
	add r2, sp, 0x4
	bl xxx_call_draw_string
	b _0803BEC8
	.align 2, 0
_0803BEB0: .4byte gAvailablePokemonNames
_0803BEB4: .4byte gUnknown_80E8B40
_0803BEB8:
	ldr r2, _0803BEF8
	ldr r3, [r7]
	movs r0, 0
	str r0, [sp]
	movs r0, 0x44
	mov r1, r9
	bl xxx_call_draw_string
_0803BEC8:
	movs r0, 0xC
	add r9, r0
	ldr r2, _0803BEFC
	ldr r3, [r7]
	movs r0, 0
	str r0, [sp]
	movs r0, 0xA
	mov r1, r9
	bl xxx_call_draw_string
	ldrb r0, [r5]
	cmp r0, 0x1
	bne _0803BF04
	add r4, sp, 0x180
	ldr r1, [r7, 0x8]
	adds r0, r4, 0
	bl PrintDungeonLocationtoBuffer
	ldr r1, _0803BF00
	add r0, sp, 0x4
	adds r2, r4, 0
	bl ExpandPlaceholdersBuffer
	b _0803BF0C
	.align 2, 0
_0803BEF8: .4byte gSpecialMissionText
_0803BEFC: .4byte gPlaceText
_0803BF00: .4byte gUnknown_80E8884
_0803BF04:
	ldr r1, [r7, 0x8]
	add r0, sp, 0x4
	bl PrintDungeonLocationtoBuffer
_0803BF0C:
	ldr r3, [r7]
	movs r0, 0
	str r0, [sp]
	movs r0, 0x44
	mov r1, r9
	add r2, sp, 0x4
	bl xxx_call_draw_string
	ldrb r0, [r5]
	cmp r0, 0
	bne _0803BF28
	ldr r0, [r7, 0x8]
	movs r1, 0
	b _0803BF2E
_0803BF28:
	ldr r0, [r7, 0x8]
	ldr r1, [r7, 0x54]
	ldrb r1, [r1, 0x1]
_0803BF2E:
	bl sub_803C1D0
	lsls r0, 24
	lsrs r4, r0, 24
	movs r1, 0xC
	add r9, r1
	ldr r2, _0803BF88
	ldr r3, [r7]
	movs r6, 0
	str r6, [sp]
	movs r0, 0xA
	mov r1, r9
	bl xxx_call_draw_string
	adds r0, r4, 0
	bl sub_803C1F0
	adds r2, r0, 0
	ldr r3, [r7]
	str r6, [sp]
	movs r0, 0x44
	mov r1, r9
	bl xxx_call_draw_string
	movs r0, 0xC
	add r9, r0
	ldr r2, _0803BF8C
	ldr r3, [r7]
	str r6, [sp]
	movs r0, 0xA
	mov r1, r9
	bl xxx_call_draw_string
	adds r0, r7, 0
	adds r0, 0x2E
	ldrb r2, [r0]
	adds r5, r0, 0
	cmp r2, 0x4
	bhi _0803C02C
	lsls r0, r2, 2
	ldr r1, _0803BF90
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0803BF88: .4byte gDifficultyText
_0803BF8C: .4byte gRewardText
_0803BF90: .4byte _0803BF94
	.align 2, 0
_0803BF94:
	.4byte _0803BFA8
	.4byte _0803BFBC
	.4byte _0803BFD0
	.4byte _0803BFD0
	.4byte _0803C00C
_0803BFA8:
	ldr r1, _0803BFB8
	ldrb r0, [r5]
	lsls r0, 2
	adds r0, r1
	ldr r1, [r0]
	ldr r2, [r7, 0x30]
	add r0, sp, 0x4
	b _0803BFEE
	.align 2, 0
_0803BFB8: .4byte gMissionRewardText
_0803BFBC:
	ldr r1, _0803BFCC
	ldrb r0, [r5]
	lsls r0, 2
	adds r0, r1
	ldr r1, [r0]
	ldr r2, [r7, 0x30]
	add r0, sp, 0x4
	b _0803BFEE
	.align 2, 0
_0803BFCC: .4byte gMissionRewardText
_0803BFD0:
	ldr r4, _0803C004
	adds r0, r7, 0
	adds r0, 0x34
	ldrb r1, [r0]
	adds r0, r4, 0
	movs r2, 0
	bl sub_8090DC4
	ldr r1, _0803C008
	ldrb r0, [r5]
	lsls r0, 2
	adds r0, r1
	ldr r1, [r0]
	add r0, sp, 0x4
	adds r2, r4, 0
_0803BFEE:
	bl ExpandPlaceholdersBuffer
	ldr r3, [r7]
	movs r0, 0
	str r0, [sp]
	movs r0, 0x44
	mov r1, r9
	add r2, sp, 0x4
	bl xxx_call_draw_string
	b _0803C040
	.align 2, 0
_0803C004: .4byte gUnknown_202DE58
_0803C008: .4byte gMissionRewardText
_0803C00C:
	ldr r1, _0803C028
	ldrb r0, [r5]
	lsls r0, 2
	adds r0, r1
	ldr r2, [r0]
	ldr r3, [r7]
	movs r0, 0
	str r0, [sp]
	movs r0, 0x44
	mov r1, r9
	bl xxx_call_draw_string
	b _0803C040
	.align 2, 0
_0803C028: .4byte gMissionRewardText
_0803C02C:
	ldr r1, _0803C0D4
	lsls r0, r2, 2
	adds r0, r1
	ldr r2, [r0]
	ldr r3, [r7]
	str r6, [sp]
	movs r0, 0x44
	mov r1, r9
	bl xxx_call_draw_string
_0803C040:
	movs r1, 0xC
	add r9, r1
	adds r0, r7, 0
	adds r0, 0x41
	ldrb r1, [r0]
	adds r0, r1, 0
	subs r0, 0x9
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x2
	bls _0803C0C6
	cmp r1, 0x3
	beq _0803C0C6
	ldr r0, [r7, 0x54]
	ldrb r0, [r0]
	cmp r0, 0x5
	bne _0803C0C6
	ldr r2, _0803C0D8
	ldr r3, [r7]
	movs r0, 0
	str r0, [sp]
	movs r0, 0xA
	mov r1, r9
	bl xxx_call_draw_string
	add r0, sp, 0x1E4
	ldr r1, [r7, 0x54]
	bl sub_803D414
	movs r4, 0
_0803C07C:
	cmp r4, 0xC
	bne _0803C084
	movs r0, 0xC
	add r9, r0
_0803C084:
	movs r5, 0x7
	cmp r4, 0x3
	ble _0803C09C
	movs r5, 0x6
	cmp r4, 0x7
	ble _0803C09C
	movs r5, 0x7
	cmp r4, 0xF
	ble _0803C09C
	cmp r4, 0x13
	bgt _0803C09C
	movs r5, 0x6
_0803C09C:
	adds r0, r4, 0
	movs r1, 0xC
	bl __modsi3
	adds r1, r0, 0
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 1
	adds r0, 0x54
	add r1, sp, 0x1E4
	adds r1, r4
	ldrb r2, [r1]
	ldr r1, [r7]
	str r1, [sp]
	mov r1, r9
	adds r3, r5, 0
	bl sub_8012C60
	adds r4, 0x1
	cmp r4, 0x17
	ble _0803C07C
_0803C0C6:
	add sp, 0x1FC
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_0803C0D4: .4byte gMissionRewardText
_0803C0D8: .4byte gUnknown_80E8B7C
	thumb_func_end CreateRescueDescription

	thumb_func_start sub_803C0DC
sub_803C0DC:
	push {lr}
	lsls r0, 16
	asrs r0, 16
	bl sub_808E770
	lsls r0, 16
	asrs r2, r0, 16
	ldr r1, _0803C0F0
	b _0803C102
	.align 2, 0
_0803C0F0: .4byte gUnknown_80E80E0
_0803C0F4:
	movs r3, 0
	ldrsh r0, [r1, r3]
	cmp r0, r2
	bne _0803C100
	movs r0, 0
	b _0803C10C
_0803C100:
	adds r1, 0x2
_0803C102:
	movs r3, 0
	ldrsh r0, [r1, r3]
	cmp r0, 0
	bne _0803C0F4
	movs r0, 0x1
_0803C10C:
	pop {r1}
	bx r1
	thumb_func_end sub_803C0DC

	thumb_func_start sub_803C110
sub_803C110:
	push {r4,lr}
	lsls r0, 16
	asrs r4, r0, 16
	adds r0, r4, 0
	bl sub_8098134
	lsls r0, 24
	cmp r0, 0
	beq _0803C180
	adds r0, r4, 0
	bl sub_808E770
	lsls r0, 16
	asrs r0, 16
	cmp r4, r0
	bne _0803C180
	adds r0, r4, 0
	bl sub_803C0DC
	lsls r0, 24
	cmp r0, 0
	beq _0803C180
	movs r0, 0x6
	bl sub_80023E4
	lsls r0, 24
	cmp r0, 0
	bne _0803C188
	ldr r1, _0803C184
	movs r2, 0
	ldrsh r0, [r1, r2]
	cmp r0, 0
	beq _0803C168
	adds r2, r1, 0
_0803C154:
	movs r3, 0
	ldrsh r0, [r2, r3]
	cmp r0, r4
	beq _0803C180
	adds r1, 0x2
	adds r2, 0x2
	movs r3, 0
	ldrsh r0, [r1, r3]
	cmp r0, 0
	bne _0803C154
_0803C168:
	bl sub_808D33C
	movs r1, 0x8
	ldrsh r0, [r0, r1]
	cmp r0, r4
	beq _0803C180
	bl sub_808D378
	movs r2, 0x8
	ldrsh r0, [r0, r2]
	cmp r0, r4
	bne _0803C188
_0803C180:
	movs r0, 0
	b _0803C18A
	.align 2, 0
_0803C184: .4byte gUnknown_80E8126
_0803C188:
	movs r0, 0x1
_0803C18A:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_803C110

        .align 2,0
