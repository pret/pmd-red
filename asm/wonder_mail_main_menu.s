        .include "constants/gba_constants.inc"
	.include "asm/macros.inc"

	.syntax unified

	.text

	thumb_func_start sub_8039880
sub_8039880:
	push {r4,lr}
	movs r4, 0
	movs r0, 0x1
	bl sub_8095324
	cmp r0, 0
	bne _080398A0
	movs r0, 0x7
	bl sub_8095324
	cmp r0, 0
	bne _080398A0
	bl sub_8011C1C
	cmp r0, 0x2
	bne _080398A2
_080398A0:
	movs r4, 0x1
_080398A2:
	adds r0, r4, 0
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_8039880

        thumb_func_start CreateWonderMailMenu
CreateWonderMailMenu:
	push {r4,r5,lr}
	bl ResetUnusedInputStruct
	movs r0, 0
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	ldr r5, _0803991C
	ldr r4, _08039920
	adds r0, r4, 0
	movs r1, 0x8
	bl MemoryAlloc
	str r0, [r5]
	movs r1, 0
	adds r2, r4, 0
	bl MemoryFill8
	movs r1, 0
	movs r2, 0
	adds r4, r5, 0
_080398D8:
	ldr r0, [r5]
	adds r0, 0x1
	adds r0, r1
	strb r2, [r0]
	adds r1, 0x1
	cmp r1, 0x35
	ble _080398D8
	ldr r1, [r4]
	movs r3, 0x92
	lsls r3, 3
	adds r2, r1, r3
	movs r0, 0x3
	str r0, [r2]
	ldr r0, _08039924
	adds r2, r1, r0
	movs r0, 0x2
	str r0, [r2]
	movs r0, 0x93
	lsls r0, 3
	adds r1, r0
	movs r0, 0x1
	strb r0, [r1]
	ldr r0, [r4]
	adds r0, r3
	movs r1, 0x5
	str r1, [r0]
	movs r0, 0x11
	bl sub_803A1C0
	movs r0, 0x1
	pop {r4,r5}
	pop {r1}
	bx r1
	.align 2, 0
_0803991C: .4byte gUnknown_203B3E8
_08039920: .4byte 0x0000049c
_08039924: .4byte 0x00000494
	thumb_func_end CreateWonderMailMenu

	thumb_func_start UpdateWonderMailMenu
UpdateWonderMailMenu:
	push {lr}
	ldr r0, _08039940
	ldr r0, [r0]
	ldrb r0, [r0]
	subs r0, 0x4
	cmp r0, 0xF
	bhi _080399DE
	lsls r0, 2
	ldr r1, _08039944
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08039940: .4byte gUnknown_203B3E8
_08039944: .4byte _08039948
	.align 2, 0
_08039948:
	.4byte _08039988
	.4byte _0803998E
	.4byte _0803999E
	.4byte _080399AA
	.4byte _08039992
	.4byte _080399A4
	.4byte _080399C8
	.4byte _080399DE
	.4byte _08039998
	.4byte _080399B0
	.4byte _080399B6
	.4byte _080399BC
	.4byte _080399C2
	.4byte _080399CE
	.4byte _080399D4
	.4byte _080399DA
_08039988:
	bl sub_8039A18
	b _080399DE
_0803998E:
	movs r0, 0x3
	b _080399E0
_08039992:
	bl sub_8039AA8
	b _080399DE
_08039998:
	bl sub_8039B14
	b _080399DE
_0803999E:
	bl sub_8039B20
	b _080399DE
_080399A4:
	bl sub_8039B58
	b _080399DE
_080399AA:
	bl sub_8039D88
	b _080399DE
_080399B0:
	bl sub_8039D28
	b _080399DE
_080399B6:
	bl sub_8039D68
	b _080399DE
_080399BC:
	bl sub_8039DA4
	b _080399DE
_080399C2:
	bl sub_8039DCC
	b _080399DE
_080399C8:
	bl sub_8039B3C
	b _080399DE
_080399CE:
	bl sub_8039D0C
	b _080399DE
_080399D4:
	bl sub_8039C60
	b _080399DE
_080399DA:
	bl sub_8039DE8
_080399DE:
	movs r0, 0
_080399E0:
	pop {r1}
	bx r1
	thumb_func_end UpdateWonderMailMenu

	thumb_func_start CleanWonderMailMenu
CleanWonderMailMenu:
	push {r4,lr}
	ldr r4, _08039A14
	ldr r0, [r4]
	cmp r0, 0
	beq _08039A0E
	bl MemoryFree
	movs r0, 0
	str r0, [r4]
	bl sub_8030DE4
	bl sub_801B450
	bl sub_803084C
	bl sub_801CBB8
	bl sub_80155F0
	bl sub_8031E10
_08039A0E:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08039A14: .4byte gUnknown_203B3E8
	thumb_func_end CleanWonderMailMenu

	thumb_func_start sub_8039A18
sub_8039A18:
	push {lr}
	sub sp, 0x4
	mov r0, sp
	bl sub_80144A4
	cmp r0, 0
	bne _08039AA2
	ldr r0, _08039A48
	ldr r1, [r0]
	movs r2, 0x93
	lsls r2, 2
	adds r1, r2
	movs r2, 0xA
	str r2, [r1]
	ldr r1, [sp]
	adds r2, r0, 0
	cmp r1, 0x8
	bhi _08039AA2
	lsls r0, r1, 2
	ldr r1, _08039A4C
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08039A48: .4byte gUnknown_203B3E8
_08039A4C: .4byte _08039A50
	.align 2, 0
_08039A50:
	.4byte _08039A9C
	.4byte _08039AA2
	.4byte _08039AA2
	.4byte _08039A74
	.4byte _08039A74
	.4byte _08039A88
	.4byte _08039AA2
	.4byte _08039AA2
	.4byte _08039A9C
_08039A74:
	ldr r0, [r2]
	movs r1, 0x92
	lsls r1, 3
	adds r0, r1
	movs r1, 0x3
	str r1, [r0]
	movs r0, 0x8
	bl sub_803A1C0
	b _08039AA2
_08039A88:
	ldr r0, [r2]
	movs r2, 0x92
	lsls r2, 3
	adds r0, r2
	movs r1, 0x5
	str r1, [r0]
	movs r0, 0x11
	bl sub_803A1C0
	b _08039AA2
_08039A9C:
	movs r0, 0x5
	bl sub_803A1C0
_08039AA2:
	add sp, 0x4
	pop {r0}
	bx r0
	thumb_func_end sub_8039A18

	thumb_func_start sub_8039AA8
sub_8039AA8:
	push {lr}
	sub sp, 0x4
	mov r0, sp
	bl sub_80144A4
	cmp r0, 0
	bne _08039B0E
	ldr r0, [sp]
	cmp r0, 0
	beq _08039AE8
	cmp r0, 0x6
	bne _08039B0E
	ldr r0, _08039AD8
	ldr r0, [r0]
	ldr r1, _08039ADC
	adds r0, r1
	ldr r0, [r0]
	cmp r0, 0x1
	bne _08039AE0
	movs r0, 0x2
	bl sub_803A1C0
	b _08039B0E
	.align 2, 0
_08039AD8: .4byte gUnknown_203B3E8
_08039ADC: .4byte 0x00000494
_08039AE0:
	movs r0, 0xC
	bl sub_803A1C0
	b _08039B0E
_08039AE8:
	ldr r0, _08039B00
	ldr r0, [r0]
	ldr r1, _08039B04
	adds r0, r1
	ldr r0, [r0]
	cmp r0, 0x1
	bne _08039B08
	movs r0, 0x1
	bl sub_803A1C0
	b _08039B0E
	.align 2, 0
_08039B00: .4byte gUnknown_203B3E8
_08039B04: .4byte 0x00000494
_08039B08:
	movs r0, 0x4
	bl sub_803A1C0
_08039B0E:
	add sp, 0x4
	pop {r0}
	bx r0
	thumb_func_end sub_8039AA8

	thumb_func_start sub_8039B14
sub_8039B14:
	push {lr}
	movs r0, 0x6
	bl sub_803A1C0
	pop {r0}
	bx r0
	thumb_func_end sub_8039B14

	thumb_func_start sub_8039B20
sub_8039B20:
	push {lr}
	sub sp, 0x4
	mov r0, sp
	bl sub_80144A4
	cmp r0, 0
	bne _08039B34
	movs r0, 0x9
	bl sub_803A1C0
_08039B34:
	add sp, 0x4
	pop {r0}
	bx r0
	thumb_func_end sub_8039B20

	thumb_func_start sub_8039B3C
sub_8039B3C:
	push {lr}
	sub sp, 0x4
	mov r0, sp
	bl sub_80144A4
	cmp r0, 0
	bne _08039B50
	movs r0, 0x4
	bl sub_803A1C0
_08039B50:
	add sp, 0x4
	pop {r0}
	bx r0
	thumb_func_end sub_8039B3C

	thumb_func_start sub_8039B58
sub_8039B58:
	push {lr}
	sub sp, 0x4
	mov r0, sp
	bl sub_80144A4
	cmp r0, 0
	bne _08039BA6
	ldr r0, _08039B88
	ldr r1, [r0]
	movs r2, 0x94
	lsls r2, 2
	adds r0, r1, r2
	ldr r0, [r0]
	cmp r0, 0
	bne _08039B9C
	subs r2, 0x4
	adds r0, r1, r2
	ldr r0, [r0]
	cmp r0, 0x9
	beq _08039B8C
	cmp r0, 0xA
	beq _08039B94
	b _08039BA6
	.align 2, 0
_08039B88: .4byte gUnknown_203B3E8
_08039B8C:
	movs r0, 0x7
	bl sub_803A1C0
	b _08039BA6
_08039B94:
	movs r0, 0xD
	bl sub_803A1C0
	b _08039BA6
_08039B9C:
	bl sub_8039BAC
	movs r0, 0xA
	bl sub_803A1C0
_08039BA6:
	add sp, 0x4
	pop {r0}
	bx r0
	thumb_func_end sub_8039B58

	thumb_func_start sub_8039BAC
sub_8039BAC:
	push {lr}
	cmp r0, 0xF
	bhi _08039C48
	lsls r0, 2
	ldr r1, _08039BBC
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08039BBC: .4byte _08039BC0
	.align 2, 0
_08039BC0:
	.4byte _08039C54
	.4byte _08039C00
	.4byte _08039C10
	.4byte _08039C08
	.4byte _08039C18
	.4byte _08039C20
	.4byte _08039C48
	.4byte _08039C48
	.4byte _08039C48
	.4byte _08039C48
	.4byte _08039C48
	.4byte _08039C48
	.4byte _08039C48
	.4byte _08039C48
	.4byte _08039C28
	.4byte _08039C30
_08039C00:
	ldr r0, _08039C04
	b _08039C32
	.align 2, 0
_08039C04: .4byte gUnknown_80E7914
_08039C08:
	ldr r0, _08039C0C
	b _08039C32
	.align 2, 0
_08039C0C: .4byte gUnknown_80E7938
_08039C10:
	ldr r0, _08039C14
	b _08039C32
	.align 2, 0
_08039C14: .4byte gUnknown_80E7994
_08039C18:
	ldr r0, _08039C1C
	b _08039C32
	.align 2, 0
_08039C1C: .4byte gUnknown_80E79E4
_08039C20:
	ldr r0, _08039C24
	b _08039C32
	.align 2, 0
_08039C24: .4byte gUnknown_80E7914
_08039C28:
	ldr r0, _08039C2C
	b _08039C32
	.align 2, 0
_08039C2C: .4byte gUnknown_80E7914
_08039C30:
	ldr r0, _08039C40
_08039C32:
	ldr r3, _08039C44
	movs r1, 0
	movs r2, 0
	bl sub_80141B4
	b _08039C54
	.align 2, 0
_08039C40: .4byte gUnknown_80E7A48
_08039C44: .4byte 0x00000101
_08039C48:
	ldr r0, _08039C58
	ldr r3, _08039C5C
	movs r1, 0
	movs r2, 0
	bl sub_80141B4
_08039C54:
	pop {r0}
	bx r0
	.align 2, 0
_08039C58: .4byte gUnknown_80E7914
_08039C5C: .4byte 0x00000101
	thumb_func_end sub_8039BAC

	thumb_func_start sub_8039C60
sub_8039C60:
	push {r4,r5,lr}
	bl sub_80154F0
	adds r4, r0, 0
	ldr r5, _08039CBC
	ldr r0, [r5]
	adds r0, 0x38
	movs r1, 0
	movs r2, 0x30
	bl MemoryFill8
	cmp r4, 0x2
	beq _08039CE6
	cmp r4, 0x3
	bne _08039D04
	bl sub_80155F0
	bl ResetUnusedInputStruct
	ldr r0, [r5]
	movs r1, 0xF6
	lsls r1, 1
	adds r0, r1
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	ldr r1, [r5]
	adds r0, r1, 0x1
	adds r1, 0x38
	bl sub_803D358
	lsls r0, 24
	cmp r0, 0
	beq _08039CB4
	ldr r0, [r5]
	adds r0, 0x38
	bl sub_80959C0
	lsls r0, 24
	cmp r0, 0
	bne _08039CC0
_08039CB4:
	movs r0, 0x13
	bl sub_803A1C0
	b _08039D04
	.align 2, 0
_08039CBC: .4byte gUnknown_203B3E8
_08039CC0:
	ldr r0, [r5]
	movs r2, 0xF0
	lsls r2, 2
	adds r1, r0, r2
	adds r0, 0x38
	ldm r0!, {r2-r4}
	stm r1!, {r2-r4}
	ldm r0!, {r3,r4}
	stm r1!, {r3,r4}
	ldr r0, [r5]
	movs r1, 0x93
	lsls r1, 3
	adds r0, r1
	movs r1, 0x1
	strb r1, [r0]
	movs r0, 0xD
	bl sub_803A1C0
	b _08039D04
_08039CE6:
	bl sub_80155F0
	bl ResetUnusedInputStruct
	ldr r0, [r5]
	movs r2, 0xF6
	lsls r2, 1
	adds r0, r2
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	movs r0, 0x5
	bl sub_803A1C0
_08039D04:
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_8039C60

	thumb_func_start sub_8039D0C
sub_8039D0C:
	push {lr}
	sub sp, 0x4
	mov r0, sp
	bl sub_80144A4
	cmp r0, 0
	bne _08039D20
	movs r0, 0x12
	bl sub_803A1C0
_08039D20:
	add sp, 0x4
	pop {r0}
	bx r0
	thumb_func_end sub_8039D0C

	thumb_func_start sub_8039D28
sub_8039D28:
	push {r4,r5,lr}
	bl sub_802D0E0
	cmp r0, 0x3
	bne _08039D62
	bl sub_802D178
	ldr r5, _08039D58
	ldr r1, [r5]
	movs r4, 0x93
	lsls r4, 3
	adds r1, r4
	strb r0, [r1]
	bl sub_802D184
	ldr r0, [r5]
	adds r0, r4
	ldrb r0, [r0]
	cmp r0, 0
	beq _08039D5C
	movs r0, 0xE
	bl sub_803A1C0
	b _08039D62
	.align 2, 0
_08039D58: .4byte gUnknown_203B3E8
_08039D5C:
	movs r0, 0x10
	bl sub_803A1C0
_08039D62:
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_8039D28

	thumb_func_start sub_8039D68
sub_8039D68:
	push {lr}
	sub sp, 0x4
	mov r0, sp
	bl sub_80144A4
	cmp r0, 0
	bne _08039D82
	movs r0, 0xF
	bl sub_803A1C0
	movs r0, 0
	bl sub_8012574
_08039D82:
	add sp, 0x4
	pop {r0}
	bx r0
	thumb_func_end sub_8039D68

	thumb_func_start sub_8039D88
sub_8039D88:
	push {lr}
	sub sp, 0x4
	mov r0, sp
	bl sub_80144A4
	cmp r0, 0
	bne _08039D9C
	movs r0, 0x8
	bl sub_803A1C0
_08039D9C:
	add sp, 0x4
	pop {r0}
	bx r0
	thumb_func_end sub_8039D88

	thumb_func_start sub_8039DA4
sub_8039DA4:
	push {lr}
	sub sp, 0x4
	mov r0, sp
	bl sub_80144A4
	cmp r0, 0
	bne _08039DC6
	bl sub_8012600
	lsls r0, 24
	cmp r0, 0
	bne _08039DC6
	bl sub_8012750
	movs r0, 0x10
	bl sub_803A1C0
_08039DC6:
	add sp, 0x4
	pop {r0}
	bx r0
	thumb_func_end sub_8039DA4

	thumb_func_start sub_8039DCC
sub_8039DCC:
	push {lr}
	sub sp, 0x4
	mov r0, sp
	bl sub_80144A4
	cmp r0, 0
	bne _08039DE0
	movs r0, 0x5
	bl sub_803A1C0
_08039DE0:
	add sp, 0x4
	pop {r0}
	bx r0
	thumb_func_end sub_8039DCC

	thumb_func_start sub_8039DE8
sub_8039DE8:
	push {lr}
	sub sp, 0x4
	mov r0, sp
	bl sub_80144A4
	cmp r0, 0
	bne _08039E0E
	ldr r0, [sp]
	cmp r0, 0
	beq _08039E08
	cmp r0, 0x6
	bne _08039E0E
	movs r0, 0x11
	bl sub_803A1C0
	b _08039E0E
_08039E08:
	movs r0, 0x5
	bl sub_803A1C0
_08039E0E:
	add sp, 0x4
	pop {r0}
	bx r0
	thumb_func_end sub_8039DE8

	thumb_func_start nullsub_54
nullsub_54:
	bx lr
	thumb_func_end nullsub_54

	thumb_func_start sub_8039E18
sub_8039E18:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0x14
	ldr r1, _08039E38
	ldr r0, [r1]
	ldrb r0, [r0]
	adds r6, r1, 0
	cmp r0, 0x13
	bls _08039E2E
	b _0803A1AA
_08039E2E:
	lsls r0, 2
	ldr r1, _08039E3C
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08039E38: .4byte gUnknown_203B3E8
_08039E3C: .4byte _08039E40
	.align 2, 0
_08039E40:
	.4byte _08039E90
	.4byte _08039EB8
	.4byte _0803A1AA
	.4byte _08039EC8
	.4byte _08039EDC
	.4byte _0803A1AA
	.4byte _08039FF4
	.4byte _08039FA4
	.4byte _08039FCC
	.4byte _0803A00C
	.4byte _0803A1AA
	.4byte _0803A1AA
	.4byte _0803A1AA
	.4byte _08039F04
	.4byte _08039F68
	.4byte _0803A1AA
	.4byte _08039FAC
	.4byte _0803A152
	.4byte _0803A168
	.4byte _0803A18E
_08039E90:
	ldr r0, _08039EB0
	ldr r3, _08039EB4
	movs r2, 0
	str r2, [sp]
	movs r1, 0x4
	str r1, [sp, 0x4]
	str r2, [sp, 0x8]
	str r2, [sp, 0xC]
	adds r1, 0xFD
	str r1, [sp, 0x10]
	movs r1, 0
	movs r2, 0x1
	bl sub_8014248
	b _0803A1AA
	.align 2, 0
_08039EB0: .4byte gUnknown_80E7AC4
_08039EB4: .4byte gUnknown_80E786C
_08039EB8:
	ldr r0, _08039EC0
	ldr r3, _08039EC4
	b _08039EE0
	.align 2, 0
_08039EC0: .4byte gUnknown_80E7AE0
_08039EC4: .4byte gUnknown_80E7894
_08039EC8:
	bl ResetUnusedInputStruct
	movs r0, 0
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	bl sub_802EF48
	b _0803A1AA
_08039EDC:
	ldr r0, _08039EFC
	ldr r3, _08039F00
_08039EE0:
	movs r2, 0
	str r2, [sp]
	movs r1, 0x4
	str r1, [sp, 0x4]
	str r2, [sp, 0x8]
	str r2, [sp, 0xC]
	adds r1, 0xFD
	str r1, [sp, 0x10]
	movs r1, 0
	movs r2, 0x3
	bl sub_8014248
	b _0803A1AA
	.align 2, 0
_08039EFC: .4byte gUnknown_80E7B14
_08039F00: .4byte gUnknown_80E78D8
_08039F04:
	ldr r0, [r6]
	ldr r2, _08039F3C
	adds r1, r0, r2
	movs r3, 0xF0
	lsls r3, 2
	adds r0, r3
	ldm r0!, {r2-r4}
	stm r1!, {r2-r4}
	ldm r0!, {r2,r4}
	stm r1!, {r2,r4}
	ldr r2, [r6]
	ldr r3, _08039F40
	adds r0, r2, r3
	ldrb r0, [r0]
	cmp r0, 0x4
	bne _08039F44
	movs r4, 0x91
	lsls r4, 3
	adds r1, r2, r4
	subs r3, 0xA2
	adds r0, r2, r3
	str r0, [r1]
	adds r4, 0x4
	adds r1, r2, r4
	adds r3, 0x28
	adds r0, r2, r3
	str r0, [r1]
	b _08039F54
	.align 2, 0
_08039F3C: .4byte 0x00000474
_08039F40: .4byte 0x00000476
_08039F44:
	movs r4, 0x91
	lsls r4, 3
	adds r0, r2, r4
	movs r1, 0
	str r1, [r0]
	ldr r3, _08039F60
	adds r0, r2, r3
	str r1, [r0]
_08039F54:
	ldr r0, [r6]
	ldr r4, _08039F64
	adds r0, r4
	bl sub_802D098
	b _0803A1AA
	.align 2, 0
_08039F60: .4byte 0x0000048c
_08039F64: .4byte 0x00000474
_08039F68:
	ldr r1, [r6]
	movs r2, 0x93
	lsls r2, 3
	adds r0, r1, r2
	ldrb r0, [r0]
	cmp r0, 0
	beq _08039F9C
	movs r3, 0x92
	lsls r3, 3
	adds r0, r1, r3
	ldr r0, [r0]
	cmp r0, 0x4
	bne _08039F84
	b _0803A1AA
_08039F84:
	cmp r0, 0x4
	bgt _08039F8E
	cmp r0, 0x3
	beq _08039F94
	b _0803A1AA
_08039F8E:
	cmp r0, 0x5
	beq _08039F94
	b _0803A1AA
_08039F94:
	ldr r0, _08039F98
	b _0803A154
	.align 2, 0
_08039F98: .4byte gUnknown_80E7B48
_08039F9C:
	ldr r0, _08039FA0
	b _0803A154
	.align 2, 0
_08039FA0: .4byte gUnknown_80E7B48
_08039FA4:
	ldr r0, _08039FA8
	b _0803A154
	.align 2, 0
_08039FA8: .4byte gUnknown_80E7B68
_08039FAC:
	ldr r0, [r6]
	movs r4, 0x93
	lsls r4, 3
	adds r0, r4
	ldrb r0, [r0]
	cmp r0, 0
	beq _08039FC4
	ldr r0, _08039FC0
	b _0803A154
	.align 2, 0
_08039FC0: .4byte gUnknown_80E7B88
_08039FC4:
	ldr r0, _08039FC8
	b _0803A154
	.align 2, 0
_08039FC8: .4byte gUnknown_80E7BC8
_08039FCC:
	ldr r0, _08039FEC
	ldr r3, _08039FF0
	movs r2, 0
	str r2, [sp]
	movs r1, 0x4
	str r1, [sp, 0x4]
	str r2, [sp, 0x8]
	str r2, [sp, 0xC]
	adds r1, 0xFD
	str r1, [sp, 0x10]
	movs r1, 0
	movs r2, 0x6
	bl sub_8014248
	b _0803A1AA
	.align 2, 0
_08039FEC: .4byte gUnknown_80E7BEC
_08039FF0: .4byte gUnknown_80E78F8
_08039FF4:
	movs r0, 0
	bl nullsub_23
	ldr r0, _0803A008
	movs r1, 0
	movs r2, 0
	movs r3, 0
	bl sub_80141B4
	b _0803A1AA
	.align 2, 0
_0803A008: .4byte gUnknown_80E7C48
_0803A00C:
	ldr r0, [r6]
	movs r1, 0x94
	lsls r1, 2
	mov r8, r1
	add r0, r8
	movs r1, 0
	str r1, [r0]
	bl sub_8011830
	ldr r0, [r6]
	movs r7, 0x93
	lsls r7, 2
	adds r0, r7
	ldr r0, [r0]
	bl sub_8037B28
	ldr r2, [r6]
	mov r3, r8
	adds r1, r2, r3
	str r0, [r1]
	cmp r0, 0
	beq _0803A03A
	b _0803A14C
_0803A03A:
	adds r4, r7, 0
	adds r0, r2, r4
	ldr r0, [r0]
	cmp r0, 0x9
	beq _0803A04A
	cmp r0, 0xA
	beq _0803A0AA
	b _0803A0DE
_0803A04A:
	movs r5, 0x95
	lsls r5, 2
	adds r0, r2, r5
	movs r1, 0
	movs r2, 0xB4
	bl MemoryFill8
	ldr r0, [r6]
	movs r1, 0xEF
	lsls r1, 2
	adds r0, r1
	ldrb r0, [r0]
	bl sub_803B344
	adds r4, r0, 0
	ldr r1, [r4, 0x14]
	cmp r1, 0
	beq _0803A08C
	ldr r0, [r6]
	movs r2, 0x9A
	lsls r2, 2
	adds r0, r2
	movs r2, 0x28
	bl MemoryCopy8
	ldr r0, [r6]
	movs r3, 0xA4
	lsls r3, 2
	adds r0, r3
	ldr r1, [r4, 0x18]
	movs r2, 0x78
	bl MemoryCopy8
_0803A08C:
	ldr r1, [r6]
	adds r1, r5
	adds r0, r4, 0
	ldm r0!, {r2-r4}
	stm r1!, {r2-r4}
	ldm r0!, {r2,r4}
	stm r1!, {r2,r4}
	ldr r2, [r6]
	adds r0, r2, r7
	ldr r0, [r0]
	adds r1, r2, r5
	movs r3, 0xC2
	lsls r3, 2
	adds r2, r3
	b _0803A0D4
_0803A0AA:
	movs r4, 0x95
	lsls r4, 2
	adds r0, r2, r4
	movs r1, 0
	movs r2, 0xB4
	bl MemoryFill8
	ldr r0, [r6]
	movs r5, 0xC2
	lsls r5, 2
	adds r0, r5
	movs r1, 0
	movs r2, 0xB4
	bl MemoryFill8
	ldr r2, [r6]
	adds r0, r2, r7
	ldr r0, [r0]
	adds r4, r2, r4
	adds r2, r5
	adds r1, r4, 0
_0803A0D4:
	bl sub_8037D64
	ldr r1, [r6]
	add r1, r8
	str r0, [r1]
_0803A0DE:
	ldr r4, _0803A134
	ldr r2, [r4]
	movs r5, 0x94
	lsls r5, 2
	adds r0, r2, r5
	ldr r0, [r0]
	cmp r0, 0
	bne _0803A14C
	movs r1, 0x93
	lsls r1, 2
	adds r0, r2, r1
	ldr r0, [r0]
	cmp r0, 0xA
	bhi _0803A14C
	cmp r0, 0x9
	bcc _0803A14C
	movs r3, 0x95
	lsls r3, 2
	adds r1, r2, r3
	adds r3, 0xB4
	adds r2, r3
	bl sub_80381F4
	ldr r1, [r4]
	adds r1, r5
	str r0, [r1]
	bl sub_800D588
	lsls r0, 24
	cmp r0, 0
	beq _0803A138
	ldr r1, [r4]
	movs r4, 0xF0
	lsls r4, 2
	adds r0, r1, r4
	movs r2, 0xC2
	lsls r2, 2
	adds r1, r2
	movs r2, 0xB4
	bl memcpy
	b _0803A14C
	.align 2, 0
_0803A134: .4byte gUnknown_203B3E8
_0803A138:
	ldr r1, [r4]
	movs r3, 0xF0
	lsls r3, 2
	adds r0, r1, r3
	movs r4, 0x95
	lsls r4, 2
	adds r1, r4
	movs r2, 0xB4
	bl memcpy
_0803A14C:
	bl xxx_call_start_bg_music
	b _0803A1AA
_0803A152:
	ldr r0, _0803A160
_0803A154:
	ldr r3, _0803A164
	movs r1, 0
	movs r2, 0
	bl sub_80141B4
	b _0803A1AA
	.align 2, 0
_0803A160: .4byte gUnknown_80E7C98
_0803A164: .4byte 0x00000101
_0803A168:
	ldr r0, [r6]
	movs r1, 0xF6
	lsls r1, 1
	adds r0, r1
	bl sub_8006518
	bl ResetUnusedInputStruct
	movs r0, 0
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	ldr r1, [r6]
	adds r1, 0x1
	movs r0, 0x5
	bl sub_80151C0
	b _0803A1AA
_0803A18E:
	ldr r0, _0803A1B8
	ldr r3, _0803A1BC
	movs r2, 0
	str r2, [sp]
	movs r1, 0x4
	str r1, [sp, 0x4]
	str r2, [sp, 0x8]
	str r2, [sp, 0xC]
	adds r1, 0xFD
	str r1, [sp, 0x10]
	movs r1, 0
	movs r2, 0x6
	bl sub_8014248
_0803A1AA:
	add sp, 0x14
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_0803A1B8: .4byte gUnknown_80E7CC4
_0803A1BC: .4byte gUnknown_80E78F8
	thumb_func_end sub_8039E18

        .align 2,0
