        .include "constants/gba_constants.inc"
	.include "asm/macros.inc"

	.syntax unified

	.text

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
