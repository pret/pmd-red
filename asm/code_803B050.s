        #include "asm/constants/gba_constants.inc"
	#include "asm/macros.inc"

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
	bl RestoreUnkTextStruct_8006518
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
	bl xxx_call_save_unk_text_struct_800641C
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
	bl xxx_call_save_unk_text_struct_800641C
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
	bl xxx_call_save_unk_text_struct_800641C
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
	bl xxx_call_save_unk_text_struct_800641C
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
	bl CallPrepareTextbox_8008C54
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
	bl PrintStringOnWindow
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
	bl PrintStringOnWindow
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

        .align 2,0
