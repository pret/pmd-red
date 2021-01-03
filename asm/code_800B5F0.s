	.include "constants/gba_constants.inc"
	.include "asm/macros.inc"

	.syntax unified

	.text

	thumb_func_start sub_800B720
sub_800B720:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x14
	str r1, [sp]
	lsls r0, 16
	asrs r0, 16
	str r0, [sp, 0xC]
	bl DisableInterrupts
	lsls r0, 24
	lsrs r0, 24
	str r0, [sp, 0x4]
	ldr r0, _0800B780
	mov r8, r0
	ldr r1, _0800B784
	mov r10, r1
	ldr r2, _0800B788
	mov r9, r2
	ldr r5, _0800B78C
	mov r12, r5
_0800B74E:
	movs r7, 0
	str r7, [sp, 0x10]
	movs r4, 0
	ldr r3, _0800B784
	mov r1, r8
	movs r2, 0
	ldrsh r0, [r1, r2]
	ldr r6, _0800B78C
	ldr r5, [sp, 0xC]
	lsls r5, 16
	str r5, [sp, 0x8]
	cmp r4, r0
	bge _0800B7BA
	movs r7, 0
	ldrsh r1, [r3, r7]
	ldrh r2, [r6]
	movs r5, 0
	ldrsh r0, [r6, r5]
	cmp r1, r0
	bne _0800B790
	adds r0, r2, 0x1
	mov r7, r9
	ands r0, r7
	strh r0, [r6]
	b _0800B74E
	.align 2, 0
_0800B780: .4byte gUnknown_203B0AA
_0800B784: .4byte gUnknown_202D608
_0800B788: .4byte 0x00007fff
_0800B78C: .4byte gUnknown_203B0A8
_0800B790:
	adds r4, 0x1
	adds r3, 0x8
	mov r1, r8
	movs r2, 0
	ldrsh r0, [r1, r2]
	cmp r4, r0
	bge _0800B7BA
	movs r5, 0
	ldrsh r1, [r3, r5]
	mov r7, r12
	ldrh r2, [r7]
	movs r5, 0
	ldrsh r0, [r7, r5]
	cmp r1, r0
	bne _0800B790
	adds r0, r2, 0x1
	mov r7, r9
	ands r0, r7
	strh r0, [r6]
	movs r0, 0x1
	str r0, [sp, 0x10]
_0800B7BA:
	ldr r1, [sp, 0x10]
	cmp r1, 0
	bne _0800B74E
	movs r4, 0
	mov r3, r10
	ldr r2, _0800B84C
	movs r5, 0
	ldrsh r1, [r2, r5]
	cmp r4, r1
	bge _0800B7EA
	movs r7, 0x2
	ldrsh r0, [r3, r7]
	ldr r2, [sp, 0xC]
	cmp r0, r2
	bgt _0800B7EA
_0800B7D8:
	adds r4, 0x1
	adds r3, 0x8
	cmp r4, r1
	bge _0800B7EA
	movs r5, 0x2
	ldrsh r0, [r3, r5]
	ldr r7, [sp, 0xC]
	cmp r0, r7
	ble _0800B7D8
_0800B7EA:
	ldr r1, _0800B84C
	movs r2, 0
	ldrsh r0, [r1, r2]
	subs r2, r0, 0x1
	lsls r0, r2, 3
	mov r5, r10
	adds r3, r0, r5
	lsls r5, r4, 3
	cmp r2, r4
	blt _0800B80E
_0800B7FE:
	ldr r0, [r3]
	ldr r1, [r3, 0x4]
	str r0, [r3, 0x8]
	str r1, [r3, 0xC]
	subs r2, 0x1
	subs r3, 0x8
	cmp r2, r4
	bge _0800B7FE
_0800B80E:
	ldr r7, _0800B84C
	ldrh r0, [r7]
	adds r0, 0x1
	strh r0, [r7]
	mov r0, r10
	adds r1, r5, r0
	ldrh r0, [r6]
	strh r0, [r1]
	ldr r2, [sp, 0x8]
	lsrs r0, r2, 16
	strh r0, [r1, 0x2]
	mov r0, r10
	adds r0, 0x4
	adds r0, r5, r0
	ldr r5, [sp]
	str r5, [r0]
	ldr r7, [sp, 0x4]
	cmp r7, 0
	beq _0800B838
	bl EnableInterrupts
_0800B838:
	movs r1, 0
	ldrsh r0, [r6, r1]
	add sp, 0x14
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	.align 2, 0
_0800B84C: .4byte gUnknown_203B0AA
	thumb_func_end sub_800B720

	thumb_func_start sub_800B850
sub_800B850:
	push {r4-r7,lr}
	lsls r0, 16
	asrs r6, r0, 16
	bl DisableInterrupts
	lsls r0, 24
	lsrs r5, r0, 24
	movs r2, 0
	ldr r4, _0800B8A0
	ldr r3, _0800B8A4
	movs r1, 0
	ldrsh r0, [r3, r1]
	cmp r2, r0
	bge _0800B8B4
	adds r1, r3, 0
_0800B86E:
	movs r7, 0
	ldrsh r0, [r4, r7]
	cmp r0, r6
	bne _0800B8A8
	ldrh r0, [r1]
	subs r0, 0x1
	strh r0, [r1]
	movs r3, 0
	ldrsh r0, [r1, r3]
	cmp r2, r0
	bge _0800B896
	ldr r3, _0800B8A4
_0800B886:
	ldr r0, [r4, 0x8]
	ldr r1, [r4, 0xC]
	stm r4!, {r0,r1}
	adds r2, 0x1
	movs r7, 0
	ldrsh r0, [r3, r7]
	cmp r2, r0
	blt _0800B886
_0800B896:
	cmp r5, 0
	beq _0800B8BC
	bl EnableInterrupts
	b _0800B8BC
	.align 2, 0
_0800B8A0: .4byte gUnknown_202D608
_0800B8A4: .4byte gUnknown_203B0AA
_0800B8A8:
	adds r2, 0x1
	adds r4, 0x8
	movs r7, 0
	ldrsh r0, [r3, r7]
	cmp r2, r0
	blt _0800B86E
_0800B8B4:
	cmp r5, 0
	beq _0800B8BC
	bl EnableInterrupts
_0800B8BC:
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_800B850

	thumb_func_start nullsub_177
nullsub_177:
	bx lr
	thumb_func_end nullsub_177

	thumb_func_start VBlankIntr
VBlankIntr:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	ldr r0, _0800B95C
	ldr r1, [r0]
	adds r1, 0x1
	str r1, [r0]
	bl SoundVSync
	bl BlinkSavingIcon
	ldr r0, _0800B960
	ldr r0, [r0, 0x4]
	cmp r0, 0
	beq _0800B8EE
	bl _call_via_r0
_0800B8EE:
	movs r2, 0
	ldr r3, _0800B964
	movs r1, 0
	ldrsh r0, [r3, r1]
	adds r6, r3, 0
	ldr r7, _0800B968
	ldr r1, _0800B96C
	mov r12, r1
	ldr r1, _0800B970
	mov r8, r1
	ldr r1, _0800B974
	mov r9, r1
	ldr r1, _0800B978
	mov r10, r1
	cmp r2, r0
	bge _0800B920
	ldr r5, _0800B97C
	ldr r4, _0800B980
_0800B912:
	ldm r5!, {r0,r1}
	stm r4!, {r0,r1}
	adds r2, 0x1
	movs r1, 0
	ldrsh r0, [r3, r1]
	cmp r2, r0
	blt _0800B912
_0800B920:
	ldrh r0, [r6]
	strh r0, [r7]
	movs r1, 0x1
	negs r1, r1
	adds r0, r1, 0
	mov r1, r12
	strh r0, [r1]
	mov r1, r8
	strh r0, [r1]
	mov r1, r9
	strh r0, [r1]
	ldr r1, _0800B984
	movs r0, 0x28
	strh r0, [r1]
	mov r1, r10
	ldrb r0, [r1]
	cmp r0, 0
	bne _0800B948
	bl UpdateSound
_0800B948:
	movs r0, 0x1
	bl SetInterruptFlag
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_0800B95C: .4byte gUnknown_203B0A0
_0800B960: .4byte gUnknown_202D5F0
_0800B964: .4byte gUnknown_203B0AA
_0800B968: .4byte gUnknown_203B0AC
_0800B96C: .4byte gUnknown_203B0AE
_0800B970: .4byte gUnknown_203B0B0
_0800B974: .4byte gUnknown_203B0B2
_0800B978: .4byte gUnknown_203B099
_0800B97C: .4byte gUnknown_202D608
_0800B980: .4byte gUnknown_202D648
_0800B984: .4byte 0x04000004
	thumb_func_end VBlankIntr

	thumb_func_start VCountIntr
VCountIntr:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	ldr r0, _0800BA44
	ldrh r0, [r0]
	lsls r0, 16
	asrs r6, r0, 16
	ldr r0, _0800BA48
	movs r2, 0
	ldrsh r1, [r0, r2]
	adds r7, r0, 0
	cmp r1, 0
	bge _0800B9B2
	ldr r0, _0800BA4C
	ldr r0, [r0, 0x8]
	cmp r0, 0
	beq _0800B9AE
	bl _call_via_r0
_0800B9AE:
	movs r0, 0
	strh r0, [r7]
_0800B9B2:
	ldr r0, _0800BA50
	movs r3, 0
	ldrsh r2, [r7, r3]
	movs r3, 0
	ldrsh r1, [r0, r3]
	mov r8, r0
	cmp r2, r1
	bge _0800BA34
	ldr r1, _0800BA54
	adds r0, r2, 0
	lsls r0, 3
	adds r0, r1
	movs r3, 0x2
	ldrsh r0, [r0, r3]
	cmp r0, r6
	bgt _0800BA10
	adds r5, r1, 0
	adds r4, r7, 0
_0800B9D6:
	movs r1, 0
	ldrsh r0, [r4, r1]
	lsls r0, 3
	adds r1, r5, 0x4
	adds r0, r1
	ldr r0, [r0]
	cmp r0, 0
	beq _0800B9EA
	bl _call_via_r0
_0800B9EA:
	ldrh r0, [r4]
	adds r0, 0x1
	strh r0, [r4]
	ldr r1, _0800BA50
	lsls r0, 16
	asrs r0, 16
	movs r2, 0
	ldrsh r1, [r1, r2]
	cmp r0, r1
	bge _0800BA34
	movs r3, 0
	ldrsh r0, [r4, r3]
	lsls r0, 3
	adds r0, r5
	movs r1, 0x2
	ldrsh r0, [r0, r1]
	ldr r7, _0800BA48
	cmp r0, r6
	ble _0800B9D6
_0800BA10:
	movs r2, 0
	ldrsh r1, [r7, r2]
	mov r3, r8
	movs r2, 0
	ldrsh r0, [r3, r2]
	cmp r1, r0
	bge _0800BA34
	ldr r2, _0800BA58
	ldr r1, _0800BA54
	movs r3, 0
	ldrsh r0, [r7, r3]
	lsls r0, 3
	adds r0, r1
	ldrh r0, [r0, 0x2]
	lsls r0, 8
	movs r1, 0x28
	orrs r0, r1
	strh r0, [r2]
_0800BA34:
	movs r0, 0x4
	bl SetInterruptFlag
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_0800BA44: .4byte 0x04000006
_0800BA48: .4byte gUnknown_203B0AE
_0800BA4C: .4byte gUnknown_202D5F0
_0800BA50: .4byte gUnknown_203B0AC
_0800BA54: .4byte gUnknown_202D648
_0800BA58: .4byte 0x04000004
	thumb_func_end VCountIntr

	thumb_func_start sub_800BA5C
sub_800BA5C:
	push {r4,lr}
	ldr r4, _0800BAA4
	ldrb r0, [r4]
	cmp r0, 0
	beq _0800BA72
	ldr r1, _0800BAA8
	ldr r0, [r1]
	adds r0, 0x1
	str r0, [r1]
	bl xxx_update_bg_sound_input
_0800BA72:
	movs r0, 0x1
	strb r0, [r4]
	ldr r1, _0800BAAC
	movs r0, 0
	strb r0, [r1]
	ldr r1, _0800BAA8
	movs r0, 0
	str r0, [r1]
	bl nullsub_25
	ldr r1, _0800BAB0
_0800BA88:
	ldrh r0, [r1]
	cmp r0, 0x9F
	bhi _0800BA88
	ldr r1, _0800BAB4
	movs r0, 0x1
	strb r0, [r1]
	bl VBlankIntrWait
	bl nullsub_18
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0800BAA4: .4byte gUnknown_203B09A
_0800BAA8: .4byte gUnknown_203B09C
_0800BAAC: .4byte gUnknown_203B09B
_0800BAB0: .4byte 0x04000006
_0800BAB4: .4byte gUnknown_203B099
	thumb_func_end sub_800BA5C

	thumb_func_start xxx_update_bg_sound_input
xxx_update_bg_sound_input:
	push {r4,r5,lr}
	ldr r1, _0800BACC
	ldrb r4, [r1]
	cmp r4, 0
	beq _0800BAD4
	ldr r1, _0800BAD0
	ldr r0, [r1]
	adds r0, 0x1
	str r0, [r1]
	b _0800BAFE
	.align 2, 0
_0800BACC: .4byte gUnknown_203B09B
_0800BAD0: .4byte gUnknown_203B09C
_0800BAD4:
	movs r0, 0x1
	strb r0, [r1]
	ldr r0, _0800BB04
	strb r4, [r0]
	ldr r0, _0800BB08
	str r4, [r0]
	bl UpdateBGControlRegisters
	ldr r5, _0800BB0C
	ldrb r0, [r5]
	cmp r0, 0
	beq _0800BAF0
	bl UpdateSound
_0800BAF0:
	bl UpdateInput
	strb r4, [r5]
	ldr r0, _0800BB10
	ldr r1, _0800BB14
	ldr r1, [r1]
	str r1, [r0]
_0800BAFE:
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_0800BB04: .4byte gUnknown_203B09A
_0800BB08: .4byte gUnknown_203B09C
_0800BB0C: .4byte gUnknown_203B099
_0800BB10: .4byte gUnknown_203B0A4
_0800BB14: .4byte gUnknown_203B0A0
	thumb_func_end xxx_update_bg_sound_input

	thumb_func_start Timer3Intr
Timer3Intr:
	push {lr}
	ldr r0, _0800BB30
	ldr r0, [r0, 0x10]
	cmp r0, 0
	beq _0800BB26
	bl _call_via_r0
_0800BB26:
	movs r0, 0x40
	bl SetInterruptFlag
	pop {r0}
	bx r0
	.align 2, 0
_0800BB30: .4byte gUnknown_202D5F0
	thumb_func_end Timer3Intr

	thumb_func_start sub_800BB34
sub_800BB34:
	ldr r0, _0800BB3C
	ldr r0, [r0]
	bx lr
	.align 2, 0
_0800BB3C: .4byte gUnknown_203B0A0
	thumb_func_end sub_800BB34

	thumb_func_start nullsub_178
nullsub_178:
	bx lr
	thumb_func_end nullsub_178

	thumb_func_start sub_800BB44
sub_800BB44:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x4
	ldr r2, _0800BBF0
	ldrh r0, [r2]
	ldr r1, _0800BBF4
	cmp r0, r1
	beq _0800BB60
_0800BB5A:
	ldrh r0, [r2]
	cmp r0, r1
	bne _0800BB5A
_0800BB60:
	bl DisableInterrupts
	lsls r0, 24
	lsrs r0, 24
	str r0, [sp]
	ldr r1, _0800BBF8
_0800BB6C:
	ldrh r0, [r1]
	cmp r0, 0x9F
	bls _0800BB6C
	movs r0, 0x80
	lsls r0, 19
	mov r9, r0
	ldrh r1, [r0]
	mov r8, r1
	movs r0, 0x80
	mov r2, r9
	strh r0, [r2]
	movs r7, 0xA0
	lsls r7, 19
	ldr r1, _0800BBFC
	adds r0, r1, 0
	strh r0, [r7]
	ldr r5, _0800BC00
	ldrh r4, [r5]
	movs r2, 0xC0
	lsls r2, 6
	adds r0, r2, 0
	strh r0, [r5]
	ldr r0, _0800BC04
	mov r10, r0
	ldr r1, _0800BC08
	adds r0, r1, 0
	mov r2, r10
	strh r0, [r2]
	ldr r6, _0800BC0C
	movs r0, 0x1
	strh r0, [r6]
	bl SoundBiasReset
	swi 0x3
	bl SoundBiasSet
	movs r0, 0
	strh r0, [r6]
	strh r4, [r5]
	mov r1, r10
	strh r0, [r1]
	mov r1, r8
	mov r2, r9
	strh r1, [r2]
	strh r0, [r7]
	ldr r2, [sp]
	cmp r2, 0
	beq _0800BBD0
	bl EnableInterrupts
_0800BBD0:
	ldr r2, _0800BBF0
	ldrh r0, [r2]
	ldr r1, _0800BBF4
	cmp r0, r1
	beq _0800BBE0
_0800BBDA:
	ldrh r0, [r2]
	cmp r0, r1
	bne _0800BBDA
_0800BBE0:
	add sp, 0x4
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_0800BBF0: .4byte 0x04000130
_0800BBF4: .4byte 0x000003ff
_0800BBF8: .4byte 0x04000006
_0800BBFC: .4byte 0x00007fff
_0800BC00: .4byte 0x04000200
_0800BC04: .4byte 0x04000132
_0800BC08: .4byte 0x00008304
_0800BC0C: .4byte 0x04000208
	thumb_func_end sub_800BB44

	.align 2, 0 @ Don't pad with nop.
