	.include "constants/gba_constants.inc"
	.include "asm/macros.inc"

	.syntax unified

	.text

	thumb_func_start sub_800B540
sub_800B540:
	push {r4,lr}
	ldr r1, _0800B5C8
	movs r2, 0
	adds r0, r1, 0
	adds r0, 0x14
_0800B54A:
	str r2, [r0]
	subs r0, 0x4
	cmp r0, r1
	bge _0800B54A
	bl nullsub_17
	bl sub_800BD08
	ldr r1, _0800B5CC
_0800B55C:
	ldrh r0, [r1]
	cmp r0, 0x9F
	bls _0800B55C
	ldr r4, _0800B5D0
	ldrh r0, [r4]
	movs r1, 0x45
	eors r0, r1
	strh r0, [r4]
	movs r2, 0x80
	lsls r2, 19
	ldrb r0, [r2]
	movs r1, 0x80
	orrs r0, r1
	strb r0, [r2]
	ldr r0, _0800B5D4
	bl sub_800B6B0
	ldr r1, _0800B5D8
	movs r0, 0xC1
	lsls r0, 16
	str r0, [r1]
	ldrh r0, [r4]
	ldr r2, _0800B5DC
	adds r1, r2, 0
	orrs r0, r1
	strh r0, [r4]
	ldr r1, _0800B5E0
	movs r0, 0x28
	strh r0, [r1]
	ldr r1, _0800B5E4
	movs r2, 0x1
	negs r2, r2
	adds r0, r2, 0
	strh r0, [r1]
	ldr r1, _0800B5E8
	movs r0, 0
	strh r0, [r1]
	bl sub_800D6AC
	bl sub_800D7D0
	ldr r1, _0800B5EC
	movs r0, 0x1
	strb r0, [r1]
	bl sub_800B5F0
	ldr r1, _0800B5CC
_0800B5BA:
	ldrh r0, [r1]
	cmp r0, 0x9F
	bls _0800B5BA
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0800B5C8: .4byte gUnknown_202D5F0
_0800B5CC: .4byte 0x04000006
_0800B5D0: .4byte 0x04000200
_0800B5D4: .4byte gUnknown_80B9C00
_0800B5D8: .4byte 0x0400010c
_0800B5DC: .4byte 0x00002045
_0800B5E0: .4byte 0x04000004
_0800B5E4: .4byte gUnknown_203B0AE
_0800B5E8: .4byte gUnknown_203B0AC
_0800B5EC: .4byte gUnknown_203B098
	thumb_func_end sub_800B540

	thumb_func_start sub_800B5F0
sub_800B5F0:
	push {lr}
	ldr r0, _0800B610
	ldrb r0, [r0]
	cmp r0, 0
	beq _0800B618
	ldr r3, _0800B614
	ldrh r1, [r3]
	movs r2, 0x1
	adds r0, r2, 0
	ands r0, r1
	cmp r0, 0
	bne _0800B618
	strh r2, [r3]
	movs r0, 0x1
	b _0800B61A
	.align 2, 0
_0800B610: .4byte gUnknown_203B098
_0800B614: .4byte 0x04000208
_0800B618:
	movs r0, 0
_0800B61A:
	pop {r1}
	bx r1
	thumb_func_end sub_800B5F0

	thumb_func_start sub_800B620
sub_800B620:
	push {lr}
	ldr r0, _0800B640
	ldrb r0, [r0]
	cmp r0, 0
	beq _0800B648
	ldr r2, _0800B644
	ldrh r1, [r2]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _0800B648
	movs r0, 0
	strh r0, [r2]
	movs r0, 0x1
	b _0800B64A
	.align 2, 0
_0800B640: .4byte gUnknown_203B098
_0800B644: .4byte 0x04000208
_0800B648:
	movs r0, 0
_0800B64A:
	pop {r1}
	bx r1
	thumb_func_end sub_800B620

	thumb_func_start sub_800B650
sub_800B650:
	push {lr}
	ldr r0, _0800B66C
	ldrb r0, [r0]
	cmp r0, 0
	beq _0800B674
	ldr r0, _0800B670
	ldrh r1, [r0]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	bne _0800B674
	movs r0, 0x1
	b _0800B676
	.align 2, 0
_0800B66C: .4byte gUnknown_203B098
_0800B670: .4byte 0x04000208
_0800B674:
	movs r0, 0
_0800B676:
	pop {r1}
	bx r1
	thumb_func_end sub_800B650

	thumb_func_start sub_800B67C
sub_800B67C:
	push {r4,lr}
	lsls r0, 16
	lsrs r4, r0, 16
	ldr r0, _0800B6A4
	ldrb r0, [r0]
	cmp r0, 0
	beq _0800B69E
	ldr r3, _0800B6A8
	movs r0, 0
	strh r0, [r3]
	ldr r2, _0800B6AC
	ldrh r1, [r2]
	adds r0, r4, 0
	orrs r0, r1
	strh r0, [r2]
	movs r0, 0x1
	strh r0, [r3]
_0800B69E:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0800B6A4: .4byte gUnknown_203B098
_0800B6A8: .4byte 0x04000208
_0800B6AC: .4byte INTR_CHECK
	thumb_func_end sub_800B67C

	thumb_func_start sub_800B6B0
sub_800B6B0:
	push {r4,lr}
	ldr r1, _0800B6D0
	ldr r2, _0800B6D4
	bl CpuSet
	ldr r0, _0800B6D8
	ldr r4, _0800B6DC
	ldr r2, _0800B6E0
	adds r1, r4, 0
	bl CpuSet
	ldr r0, _0800B6E4
	str r4, [r0]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0800B6D0: .4byte gIntrTable
_0800B6D4: .4byte 0x04000006
_0800B6D8: .4byte IntrMain
_0800B6DC: .4byte gUnknown_202D4B8
_0800B6E0: .4byte 0x04000048
_0800B6E4: .4byte INTR_VECTOR
	thumb_func_end sub_800B6B0

	thumb_func_start sub_800B6E8
sub_800B6E8:
	lsls r0, 2
	ldr r1, _0800B6F0
	adds r0, r1
	bx lr
	.align 2, 0
_0800B6F0: .4byte gIntrTable
	thumb_func_end sub_800B6E8

	thumb_func_start sub_800B6F4
sub_800B6F4:
	push {r4-r6,lr}
	adds r4, r0, 0
	adds r5, r1, 0
	bl sub_800B620
	lsls r0, 24
	ldr r1, _0800B71C
	lsls r4, 2
	adds r4, r1
	ldr r6, [r4]
	str r5, [r4]
	cmp r0, 0
	beq _0800B712
	bl sub_800B5F0
_0800B712:
	adds r0, r6, 0
	pop {r4-r6}
	pop {r1}
	bx r1
	.align 2, 0
_0800B71C: .4byte gUnknown_202D5F0
	thumb_func_end sub_800B6F4

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
	bl sub_800B620
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
	bl sub_800B5F0
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
	bl sub_800B620
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
	bl sub_800B5F0
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
	bl sub_800B5F0
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
	bl sub_800B67C
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
	bl sub_800B67C
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
	bl sub_800B67C
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
	bl sub_800B620
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
	bl sub_800B5F0
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

	thumb_func_start nullsub_17
nullsub_17:
	bx lr
	thumb_func_end nullsub_17

	thumb_func_start UpdateBGControlRegisters
UpdateBGControlRegisters:
	push {r4,lr}
	sub sp, 0x10
	ldr r0, _0800BC2C
	ldrb r0, [r0]
	cmp r0, 0x1
	bne _0800BC30
	str r0, [sp]
	movs r0, 0x2
	str r0, [sp, 0x4]
	movs r0, 0
	b _0800BC3A
	.align 2, 0
_0800BC2C: .4byte gUnknown_202D7FE
_0800BC30:
	movs r0, 0
	str r0, [sp]
	movs r0, 0x1
	str r0, [sp, 0x4]
	movs r0, 0x2
_0800BC3A:
	str r0, [sp, 0x8]
	movs r0, 0x3
	str r0, [sp, 0xC]
	ldr r1, _0800BCA8
	ldr r2, _0800BCAC
	ldrh r0, [r2, 0x4]
	strh r0, [r1]
	adds r1, 0x2
	ldrh r0, [r2, 0x6]
	strh r0, [r1]
	adds r1, 0x2
	ldr r2, _0800BCB0
	ldrh r0, [r2, 0x4]
	strh r0, [r1]
	adds r1, 0x2
	ldrh r0, [r2, 0x6]
	strh r0, [r1]
	adds r1, 0x2
	ldr r3, _0800BCB4
	ldrh r0, [r3, 0x4]
	strh r0, [r1]
	adds r1, 0x2
	ldrh r0, [r3, 0x6]
	strh r0, [r1]
	adds r1, 0x2
	ldr r2, _0800BCB8
	ldrh r0, [r2, 0x4]
	strh r0, [r1]
	adds r1, 0x2
	ldrh r0, [r2, 0x6]
	strh r0, [r1]
	ldr r2, _0800BCBC
	ldr r0, [sp]
	movs r4, 0xB0
	lsls r4, 6
	adds r1, r4, 0
	orrs r0, r1
	strh r0, [r2]
	adds r2, 0x2
	ldr r0, [sp, 0x4]
	movs r4, 0xB4
	lsls r4, 6
	adds r1, r4, 0
	orrs r0, r1
	strh r0, [r2]
	ldrh r1, [r3, 0x2]
	movs r0, 0x80
	lsls r0, 8
	cmp r1, r0
	bne _0800BCC8
	ldr r0, _0800BCC0
	ldr r1, [sp, 0x8]
	ldr r3, _0800BCC4
	adds r2, r3, 0
	b _0800BCD2
	.align 2, 0
_0800BCA8: .4byte 0x04000010
_0800BCAC: .4byte gUnknown_202D698
_0800BCB0: .4byte gUnknown_202D6A0
_0800BCB4: .4byte gUnknown_202D6A8
_0800BCB8: .4byte gUnknown_202D6B0
_0800BCBC: .4byte 0x04000008
_0800BCC0: .4byte 0x0400000c
_0800BCC4: .4byte 0x00002e08
_0800BCC8:
	ldr r0, _0800BCF4
	ldr r1, [sp, 0x8]
	movs r4, 0xB8
	lsls r4, 6
	adds r2, r4, 0
_0800BCD2:
	orrs r1, r2
	strh r1, [r0]
	ldr r2, _0800BCF8
	ldr r0, [sp, 0xC]
	ldr r3, _0800BCFC
	adds r1, r3, 0
	orrs r0, r1
	strh r0, [r2]
	ldr r1, _0800BD00
	ldr r0, _0800BD04
	ldrh r0, [r0]
	strh r0, [r1]
	add sp, 0x10
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0800BCF4: .4byte 0x0400000c
_0800BCF8: .4byte 0x0400000e
_0800BCFC: .4byte 0x00002f08
_0800BD00: .4byte 0x04000050
_0800BD04: .4byte gUnknown_202D7FC
	thumb_func_end UpdateBGControlRegisters

	thumb_func_start sub_800BD08
sub_800BD08:
	push {r4,lr}
	ldr r1, _0800BDA8
	ldrh r2, [r1, 0xA]
	ldr r4, _0800BDAC
	adds r0, r4, 0
	ands r0, r2
	strh r0, [r1, 0xA]
	ldrh r2, [r1, 0xA]
	ldr r3, _0800BDB0
	adds r0, r3, 0
	ands r0, r2
	strh r0, [r1, 0xA]
	ldrh r0, [r1, 0xA]
	adds r1, 0xC
	ldrh r2, [r1, 0xA]
	adds r0, r4, 0
	ands r0, r2
	strh r0, [r1, 0xA]
	ldrh r2, [r1, 0xA]
	adds r0, r3, 0
	ands r0, r2
	strh r0, [r1, 0xA]
	ldrh r0, [r1, 0xA]
	adds r1, 0xC
	ldrh r2, [r1, 0xA]
	adds r0, r4, 0
	ands r0, r2
	strh r0, [r1, 0xA]
	ldrh r2, [r1, 0xA]
	adds r0, r3, 0
	ands r0, r2
	strh r0, [r1, 0xA]
	ldrh r0, [r1, 0xA]
	ldr r0, _0800BDB4
	ldrh r1, [r0, 0xA]
	ands r4, r1
	strh r4, [r0, 0xA]
	ldrh r1, [r0, 0xA]
	ands r3, r1
	strh r3, [r0, 0xA]
	ldrh r0, [r0, 0xA]
	bl m4aSoundInit
	ldr r0, _0800BDB8
	movs r2, 0
	strh r2, [r0]
	ldr r0, _0800BDBC
	ldr r3, _0800BDC0
	adds r1, r3, 0
	strh r1, [r0]
	ldr r0, _0800BDC4
	strh r1, [r0]
	ldr r1, _0800BDC8
	subs r3, 0x2
	adds r0, r3, 0
	strh r0, [r1]
	ldr r0, _0800BDCC
	strh r2, [r0]
	ldr r0, _0800BDD0
	strh r2, [r0]
	ldr r0, _0800BDD4
	strb r2, [r0]
	ldr r0, _0800BDD8
	movs r4, 0
	movs r2, 0
	movs r1, 0x7
_0800BD8C:
	strh r2, [r0]
	strh r3, [r0, 0x2]
	strh r2, [r0, 0x4]
	strb r4, [r0, 0x6]
	subs r1, 0x1
	adds r0, 0x8
	cmp r1, 0
	bge _0800BD8C
	bl nullsub_19
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0800BDA8: .4byte 0x040000b0
_0800BDAC: .4byte 0x0000c5ff
_0800BDB0: .4byte 0x00007fff
_0800BDB4: .4byte 0x040000d4
_0800BDB8: .4byte gUnknown_202D688
_0800BDBC: .4byte gUnknown_202D68A
_0800BDC0: .4byte 0x000003e7
_0800BDC4: .4byte gUnknown_202D68C
_0800BDC8: .4byte gUnknown_202D68E
_0800BDCC: .4byte gUnknown_202D690
_0800BDD0: .4byte gUnknown_202D692
_0800BDD4: .4byte gUnknown_202D694
_0800BDD8: .4byte gUnknown_3000FD8
	thumb_func_end sub_800BD08

	thumb_func_start sub_800BDDC
sub_800BDDC:
	push {lr}
	bl sub_800BF80
	ldr r0, _0800BDF4
	bl sub_800C298
	ldr r0, _0800BDF8
	bl sub_800C298
	pop {r0}
	bx r0
	.align 2, 0
_0800BDF4: .4byte 0x000003e6
_0800BDF8: .4byte 0x000003e5
	thumb_func_end sub_800BDDC

	thumb_func_start sub_800BDFC
sub_800BDFC:
	push {r4-r6,lr}
	lsls r0, 16
	lsrs r4, r0, 16
	adds r6, r4, 0
	adds r0, r4, 0
	bl sub_800CA9C
	lsls r0, 24
	cmp r0, 0
	beq _0800BE78
	ldr r0, _0800BE40
	cmp r4, r0
	beq _0800BE78
	ldr r5, _0800BE44
	ldrh r0, [r5]
	cmp r4, r0
	bne _0800BE2C
	ldr r0, _0800BE48
	ldrh r0, [r0]
	subs r0, 0x1
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0x1
	bls _0800BE78
_0800BE2C:
	adds r0, r4, 0
	bl sub_800CAE0
	lsls r0, 16
	cmp r0, 0
	beq _0800BE4C
	adds r0, r4, 0
	bl nullsub_20
	b _0800BE78
	.align 2, 0
_0800BE40: .4byte 0x000003e7
_0800BE44: .4byte gUnknown_202D68A
_0800BE48: .4byte gUnknown_202D688
_0800BE4C:
	bl sub_800B620
	lsls r0, 24
	lsrs r4, r0, 24
	strh r6, [r5]
	ldr r1, _0800BE80
	movs r0, 0x1
	strb r0, [r1]
	ldr r0, _0800BE84
	ldrh r0, [r0]
	cmp r0, 0
	bne _0800BE70
	ldr r1, _0800BE88
	movs r0, 0x1
	strh r0, [r1]
	adds r0, r6, 0
	bl m4aSongNumStart
_0800BE70:
	cmp r4, 0
	beq _0800BE78
	bl sub_800B5F0
_0800BE78:
	pop {r4-r6}
	pop {r0}
	bx r0
	.align 2, 0
_0800BE80: .4byte gUnknown_202D694
_0800BE84: .4byte gUnknown_202D690
_0800BE88: .4byte gUnknown_202D688
	thumb_func_end sub_800BDFC

	thumb_func_start sub_800BE8C
sub_800BE8C:
	push {r4-r7,lr}
	lsls r0, 16
	lsrs r6, r0, 16
	lsls r4, r1, 16
	lsrs r5, r4, 16
	adds r0, r6, 0
	bl sub_800CA9C
	lsls r0, 24
	cmp r0, 0
	beq _0800BF2E
	ldr r0, _0800BECC
	cmp r6, r0
	beq _0800BF2E
	ldr r0, _0800BED0
	ldrh r0, [r0]
	cmp r6, r0
	bne _0800BEBE
	ldr r0, _0800BED4
	ldrh r0, [r0]
	subs r0, 0x1
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0x1
	bls _0800BF2E
_0800BEBE:
	movs r0, 0x80
	lsls r0, 1
	cmp r5, r0
	bls _0800BED8
	movs r5, 0x10
	b _0800BEE0
	.align 2, 0
_0800BECC: .4byte 0x000003e7
_0800BED0: .4byte gUnknown_202D68A
_0800BED4: .4byte gUnknown_202D688
_0800BED8:
	lsrs r5, r4, 20
	cmp r5, 0
	bne _0800BEE0
	movs r5, 0x1
_0800BEE0:
	bl sub_800B620
	lsls r0, 24
	lsrs r7, r0, 24
	ldr r0, _0800BF34
	strh r6, [r0]
	ldr r1, _0800BF38
	movs r0, 0x1
	strb r0, [r1]
	ldr r0, _0800BF3C
	ldrh r0, [r0]
	cmp r0, 0
	bne _0800BF26
	ldr r0, _0800BF40
	movs r1, 0x1
	strh r1, [r0]
	adds r0, r6, 0
	bl m4aSongNumStart
	ldr r4, _0800BF44
	adds r0, r4, 0
	bl m4aMPlayImmInit
	adds r0, r4, 0
	movs r1, 0xFF
	movs r2, 0
	bl m4aMPlayVolumeControl
	adds r0, r6, 0
	bl m4aSongNumStop
	adds r0, r4, 0
	adds r1, r5, 0
	bl m4aMPlayFadeIn
_0800BF26:
	cmp r7, 0
	beq _0800BF2E
	bl sub_800B5F0
_0800BF2E:
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_0800BF34: .4byte gUnknown_202D68A
_0800BF38: .4byte gUnknown_202D694
_0800BF3C: .4byte gUnknown_202D690
_0800BF40: .4byte gUnknown_202D688
_0800BF44: .4byte gUnknown_20008F0
	thumb_func_end sub_800BE8C

	thumb_func_start sub_800BF48
sub_800BF48:
	push {r4,lr}
	lsls r0, 16
	lsrs r1, r0, 16
	ldr r0, _0800BF64
	ldrh r4, [r0]
	ldr r0, _0800BF68
	cmp r4, r0
	bne _0800BF70
	adds r0, r1, 0
	bl sub_800BDFC
	ldr r0, _0800BF6C
	strh r4, [r0]
	b _0800BF74
	.align 2, 0
_0800BF64: .4byte gUnknown_202D68A
_0800BF68: .4byte 0x000003e7
_0800BF6C: .4byte gUnknown_202D68C
_0800BF70:
	ldr r0, _0800BF7C
	strh r1, [r0]
_0800BF74:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0800BF7C: .4byte gUnknown_202D68C
	thumb_func_end sub_800BF48

	thumb_func_start sub_800BF80
sub_800BF80:
	push {r4,lr}
	bl sub_800B620
	lsls r0, 24
	lsrs r4, r0, 24
	ldr r0, _0800BFBC
	ldrh r0, [r0]
	cmp r0, 0
	bne _0800BFA2
	ldr r0, _0800BFC0
	ldrh r1, [r0]
	ldr r0, _0800BFC4
	cmp r1, r0
	beq _0800BFA2
	ldr r0, _0800BFC8
	bl m4aMPlayStop
_0800BFA2:
	ldr r0, _0800BFC0
	ldr r2, _0800BFC4
	adds r1, r2, 0
	strh r1, [r0]
	ldr r0, _0800BFCC
	strh r1, [r0]
	cmp r4, 0
	beq _0800BFB6
	bl sub_800B5F0
_0800BFB6:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0800BFBC: .4byte gUnknown_202D690
_0800BFC0: .4byte gUnknown_202D68A
_0800BFC4: .4byte 0x000003e7
_0800BFC8: .4byte gUnknown_20008F0
_0800BFCC: .4byte gUnknown_202D68C
	thumb_func_end sub_800BF80

	thumb_func_start sub_800BFD0
sub_800BFD0:
	push {r4,r5,lr}
	lsls r1, r0, 16
	movs r0, 0x80
	lsls r0, 17
	cmp r1, r0
	bls _0800BFE0
	movs r4, 0x10
	b _0800BFE8
_0800BFE0:
	lsrs r4, r1, 20
	cmp r4, 0
	bne _0800BFE8
	movs r4, 0x1
_0800BFE8:
	bl sub_800B620
	lsls r0, 24
	lsrs r5, r0, 24
	ldr r0, _0800C018
	ldrh r0, [r0]
	cmp r0, 0
	bne _0800C03C
	ldr r3, _0800C01C
	ldrh r0, [r3]
	ldr r2, _0800C020
	cmp r0, r2
	beq _0800C044
	ldr r1, _0800C024
	ldrh r0, [r1]
	cmp r0, 0x2
	bne _0800C02C
	movs r0, 0x3
	strh r0, [r1]
	ldr r0, _0800C028
	adds r1, r4, 0
	bl m4aMPlayFadeOut
	b _0800C044
	.align 2, 0
_0800C018: .4byte gUnknown_202D690
_0800C01C: .4byte gUnknown_202D68A
_0800C020: .4byte 0x000003e7
_0800C024: .4byte gUnknown_202D688
_0800C028: .4byte gUnknown_20008F0
_0800C02C:
	strh r2, [r3]
	ldr r0, _0800C038
	bl m4aMPlayStop
	b _0800C044
	.align 2, 0
_0800C038: .4byte gUnknown_20008F0
_0800C03C:
	ldr r1, _0800C05C
	ldr r2, _0800C060
	adds r0, r2, 0
	strh r0, [r1]
_0800C044:
	ldr r1, _0800C064
	ldr r2, _0800C060
	adds r0, r2, 0
	strh r0, [r1]
	cmp r5, 0
	beq _0800C054
	bl sub_800B5F0
_0800C054:
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_0800C05C: .4byte gUnknown_202D68A
_0800C060: .4byte 0x000003e7
_0800C064: .4byte gUnknown_202D68C
	thumb_func_end sub_800BFD0

	thumb_func_start sub_800C068
sub_800C068:
	ldr r0, _0800C070
	ldrh r0, [r0]
	bx lr
	.align 2, 0
_0800C070: .4byte gUnknown_202D68A
	thumb_func_end sub_800C068

	thumb_func_start sub_800C074
sub_800C074:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	lsls r0, 16
	lsrs r5, r0, 16
	mov r8, r5
	lsls r1, 16
	lsrs r6, r1, 16
	ldr r0, _0800C0FC
	cmp r5, r0
	bne _0800C08C
	b _0800C208
_0800C08C:
	movs r7, 0x80
	lsls r7, 1
	cmp r6, r7
	bls _0800C096
	adds r6, r7, 0
_0800C096:
	adds r0, r5, 0
	bl sub_800CACC
	lsls r0, 24
	cmp r0, 0
	bne _0800C0A4
	b _0800C1B0
_0800C0A4:
	adds r0, r5, 0
	bl sub_800CAE0
	lsls r0, 16
	lsrs r7, r0, 16
	cmp r7, 0x1
	beq _0800C0B4
	b _0800C1D0
_0800C0B4:
	bl sub_800B620
	lsls r0, 24
	lsrs r0, 24
	mov r8, r0
	ldr r6, _0800C100
	strh r5, [r6]
	ldr r4, _0800C104
	ldrh r0, [r4]
	adds r2, r0, 0
	cmp r2, 0
	bne _0800C144
	ldr r0, _0800C108
	ldrh r1, [r0]
	ldr r0, _0800C10C
	cmp r1, r0
	beq _0800C12C
	ldr r0, _0800C110
	ldrh r1, [r0]
	subs r0, r1, 0x1
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0x1
	bhi _0800C120
	strh r7, [r4]
	ldr r1, _0800C114
	movs r0, 0x10
	strh r0, [r1]
	ldr r0, _0800C118
	strb r2, [r0]
	ldr r0, _0800C11C
	movs r1, 0x1
	bl m4aMPlayFadeOutTemporarily
	b _0800C15E
	.align 2, 0
_0800C0FC: .4byte 0x000003e5
_0800C100: .4byte gUnknown_202D68E
_0800C104: .4byte gUnknown_202D690
_0800C108: .4byte gUnknown_202D68A
_0800C10C: .4byte 0x000003e7
_0800C110: .4byte gUnknown_202D688
_0800C114: .4byte gUnknown_202D692
_0800C118: .4byte gUnknown_202D694
_0800C11C: .4byte gUnknown_20008F0
_0800C120:
	lsls r0, r1, 16
	lsrs r0, 16
	cmp r0, 0x3
	bne _0800C12C
	movs r0, 0x2
	b _0800C15C
_0800C12C:
	movs r0, 0x3
	strh r0, [r4]
	ldr r0, _0800C140
	bl m4aMPlayStop
	ldrh r0, [r6]
	bl m4aSongNumStart
	b _0800C15E
	.align 2, 0
_0800C140: .4byte gUnknown_20008F0
_0800C144:
	subs r0, 0x1
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0x1
	bls _0800C15E
	ldr r0, _0800C17C
	bl m4aMPlayStop
	ldrh r0, [r6]
	bl m4aSongNumStart
	movs r0, 0x3
_0800C15C:
	strh r0, [r4]
_0800C15E:
	ldr r0, _0800C180
	ldrh r0, [r0]
	cmp r0, 0x26
	bgt _0800C184
	cmp r0, 0x25
	bge _0800C19A
	cmp r0, 0x1A
	blt _0800C1A0
	cmp r0, 0x1F
	ble _0800C19A
	cmp r0, 0x23
	bgt _0800C1A0
	cmp r0, 0x22
	blt _0800C1A0
	b _0800C19A
	.align 2, 0
_0800C17C: .4byte gUnknown_20008F0
_0800C180: .4byte gUnknown_202D68A
_0800C184:
	cmp r0, 0x7A
	beq _0800C19A
	cmp r0, 0x7A
	bgt _0800C196
	cmp r0, 0x77
	bgt _0800C1A0
	cmp r0, 0x75
	blt _0800C1A0
	b _0800C19A
_0800C196:
	cmp r0, 0x7F
	bne _0800C1A0
_0800C19A:
	ldr r1, _0800C1AC
	movs r0, 0x1
	strb r0, [r1]
_0800C1A0:
	mov r0, r8
	cmp r0, 0
	beq _0800C208
	bl sub_800B5F0
	b _0800C208
	.align 2, 0
_0800C1AC: .4byte gUnknown_202D694
_0800C1B0:
	adds r0, r5, 0
	bl sub_800CAAC
	lsls r0, 24
	cmp r0, 0
	beq _0800C208
	adds r0, r5, 0
	bl sub_800CAE0
	lsls r0, 16
	lsrs r0, 16
	lsls r2, r0, 3
	ldr r1, _0800C1D8
	adds r4, r2, r1
	cmp r0, 0x1
	bhi _0800C1DC
_0800C1D0:
	adds r0, r5, 0
	bl nullsub_20
	b _0800C208
	.align 2, 0
_0800C1D8: .4byte gUnknown_3000FD8
_0800C1DC:
	bl sub_800B620
	lsls r0, 24
	lsrs r5, r0, 24
	mov r0, r8
	bl m4aSongNumStart
	movs r0, 0x1
	strh r0, [r4]
	mov r0, r8
	strh r0, [r4, 0x2]
	cmp r6, r7
	bne _0800C1FA
	movs r0, 0
	b _0800C1FC
_0800C1FA:
	movs r0, 0x1
_0800C1FC:
	strb r0, [r4, 0x6]
	strh r6, [r4, 0x4]
	cmp r5, 0
	beq _0800C208
	bl sub_800B5F0
_0800C208:
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_800C074

	thumb_func_start sub_800C214
sub_800C214:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	lsls r0, 16
	lsrs r5, r0, 16
	lsls r1, 16
	lsrs r7, r1, 16
	movs r0, 0x80
	lsls r0, 1
	cmp r7, r0
	bls _0800C22C
	adds r7, r0, 0
_0800C22C:
	adds r0, r5, 0
	bl sub_800CACC
	lsls r0, 24
	cmp r0, 0
	bne _0800C286
	adds r0, r5, 0
	bl sub_800CAAC
	lsls r0, 24
	cmp r0, 0
	beq _0800C286
	adds r0, r5, 0
	bl sub_800CAE0
	lsls r0, 16
	lsrs r0, 16
	ldr r2, _0800C290
	lsls r1, r0, 1
	adds r1, r0
	lsls r1, 2
	adds r1, r2
	ldr r1, [r1]
	mov r8, r1
	lsls r2, r0, 3
	ldr r1, _0800C294
	adds r4, r2, r1
	cmp r0, 0x1
	bls _0800C286
	bl sub_800B620
	lsls r0, 24
	lsrs r6, r0, 24
	ldrh r0, [r4, 0x2]
	cmp r0, r5
	bne _0800C27E
	mov r0, r8
	movs r1, 0xF
	adds r2, r7, 0
	bl m4aMPlayVolumeControl
_0800C27E:
	cmp r6, 0
	beq _0800C286
	bl sub_800B5F0
_0800C286:
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_0800C290: .4byte gMPlayTable
_0800C294: .4byte gUnknown_3000FD8
	thumb_func_end sub_800C214

	thumb_func_start sub_800C298
sub_800C298:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	lsls r0, 16
	lsrs r5, r0, 16
	ldr r0, _0800C2F0
	mov r8, r0
	cmp r5, r8
	bne _0800C2FC
	bl sub_800B620
	lsls r0, 24
	lsrs r0, 24
	mov r9, r0
	ldr r4, _0800C2F4
	ldr r0, _0800C2F8
	movs r1, 0
	mov r10, r1
	movs r7, 0
	adds r6, r0, 0
	adds r6, 0x18
	movs r5, 0x4
_0800C2C8:
	ldr r0, [r6]
	bl m4aMPlayStop
	strh r7, [r4]
	mov r2, r8
	strh r2, [r4, 0x2]
	strh r7, [r4, 0x4]
	mov r0, r10
	strb r0, [r4, 0x6]
	adds r6, 0xC
	subs r5, 0x1
	adds r4, 0x8
	cmp r5, 0
	bge _0800C2C8
	mov r1, r9
	cmp r1, 0
	beq _0800C3DE
	bl sub_800B5F0
	b _0800C3DE
	.align 2, 0
_0800C2F0: .4byte 0x000003e5
_0800C2F4: .4byte gUnknown_3000FE8
_0800C2F8: .4byte gMPlayTable
_0800C2FC:
	adds r0, r5, 0
	bl sub_800CAAC
	lsls r0, 24
	cmp r0, 0
	beq _0800C364
	adds r0, r5, 0
	bl sub_800CAE0
	lsls r0, 16
	lsrs r0, 16
	ldr r2, _0800C330
	lsls r1, r0, 1
	adds r1, r0
	lsls r1, 2
	adds r1, r2
	ldr r7, [r1]
	lsls r2, r0, 3
	ldr r1, _0800C334
	adds r4, r2, r1
	cmp r0, 0x1
	bhi _0800C338
	adds r0, r5, 0
	bl nullsub_21
	b _0800C3DE
	.align 2, 0
_0800C330: .4byte gMPlayTable
_0800C334: .4byte gUnknown_3000FD8
_0800C338:
	bl sub_800B620
	lsls r0, 24
	lsrs r6, r0, 24
	ldrh r0, [r4, 0x2]
	cmp r0, r5
	bne _0800C35A
	adds r0, r7, 0
	bl m4aMPlayStop
	movs r1, 0
	movs r0, 0
	strh r0, [r4]
	mov r2, r8
	strh r2, [r4, 0x2]
	strh r0, [r4, 0x4]
	strb r1, [r4, 0x6]
_0800C35A:
	cmp r6, 0
	beq _0800C3DE
	bl sub_800B5F0
	b _0800C3DE
_0800C364:
	ldr r0, _0800C398
	cmp r5, r0
	bne _0800C3A8
	bl sub_800B620
	lsls r0, 24
	lsrs r4, r0, 24
	ldr r0, _0800C39C
	ldrh r0, [r0]
	cmp r0, 0
	beq _0800C38C
	ldr r1, _0800C3A0
	ldrh r0, [r1]
	cmp r0, r8
	beq _0800C38C
	mov r0, r8
	strh r0, [r1]
	ldr r0, _0800C3A4
	bl m4aMPlayStop
_0800C38C:
	cmp r4, 0
	beq _0800C3DE
	bl sub_800B5F0
	b _0800C3DE
	.align 2, 0
_0800C398: .4byte 0x000003e6
_0800C39C: .4byte gUnknown_202D690
_0800C3A0: .4byte gUnknown_202D68E
_0800C3A4: .4byte gUnknown_2000970
_0800C3A8:
	adds r0, r5, 0
	bl sub_800CACC
	lsls r0, 24
	cmp r0, 0
	beq _0800C3DE
	bl sub_800B620
	lsls r0, 24
	lsrs r4, r0, 24
	ldr r0, _0800C3EC
	ldrh r0, [r0]
	cmp r0, 0
	beq _0800C3D6
	ldr r1, _0800C3F0
	ldrh r0, [r1]
	cmp r0, r5
	bne _0800C3D6
	mov r2, r8
	strh r2, [r1]
	ldr r0, _0800C3F4
	bl m4aMPlayStop
_0800C3D6:
	cmp r4, 0
	beq _0800C3DE
	bl sub_800B5F0
_0800C3DE:
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_0800C3EC: .4byte gUnknown_202D690
_0800C3F0: .4byte gUnknown_202D68E
_0800C3F4: .4byte gUnknown_2000970
	thumb_func_end sub_800C298

	thumb_func_start sub_800C3F8
sub_800C3F8:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	lsls r0, 16
	lsrs r4, r0, 16
	lsls r1, 16
	movs r0, 0x80
	lsls r0, 17
	cmp r1, r0
	bls _0800C416
	movs r0, 0x10
	mov r9, r0
	b _0800C422
_0800C416:
	lsrs r1, 20
	mov r9, r1
	cmp r1, 0
	bne _0800C422
	movs r1, 0x1
	mov r9, r1
_0800C422:
	ldr r0, _0800C460
	mov r8, r0
	cmp r4, r8
	bne _0800C496
	bl sub_800B620
	lsls r0, 24
	lsrs r0, 24
	mov r10, r0
	movs r7, 0x2
	ldr r5, _0800C464
	ldr r0, _0800C468
	adds r6, r0, 0
	adds r6, 0x18
_0800C43E:
	ldrh r0, [r5, 0x2]
	cmp r0, r8
	beq _0800C47E
	lsls r0, r7, 16
	lsrs r0, 16
	bl sub_800CAF0
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0
	beq _0800C46C
	ldr r0, [r6]
	mov r1, r9
	bl m4aMPlayFadeOut
	b _0800C47E
	.align 2, 0
_0800C460: .4byte 0x000003e5
_0800C464: .4byte gUnknown_3000FE8
_0800C468: .4byte gMPlayTable
_0800C46C:
	ldr r0, [r6]
	bl m4aMPlayStop
	strh r4, [r5]
	mov r1, r8
	strh r1, [r5, 0x2]
	strh r4, [r5, 0x4]
	movs r0, 0
	strb r0, [r5, 0x6]
_0800C47E:
	adds r6, 0xC
	adds r7, 0x1
	adds r5, 0x8
	cmp r7, 0x6
	ble _0800C43E
	mov r1, r10
	cmp r1, 0
	bne _0800C490
	b _0800C5BE
_0800C490:
	bl sub_800B5F0
	b _0800C5BE
_0800C496:
	adds r0, r4, 0
	bl sub_800CAAC
	lsls r0, 24
	cmp r0, 0
	beq _0800C508
	adds r0, r4, 0
	bl sub_800CAE0
	lsls r0, 16
	lsrs r4, r0, 16
	lsls r1, r4, 3
	ldr r0, _0800C4E4
	adds r5, r1, r0
	ldr r1, _0800C4E8
	lsls r0, r4, 1
	adds r0, r4
	lsls r0, 2
	adds r0, r1
	ldr r6, [r0]
	bl sub_800B620
	lsls r0, 24
	lsrs r7, r0, 24
	ldrh r0, [r5, 0x2]
	cmp r0, r8
	beq _0800C4FE
	adds r0, r4, 0
	bl sub_800CAF0
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0
	beq _0800C4EC
	adds r0, r6, 0
	mov r1, r9
	bl m4aMPlayFadeOut
	b _0800C4FE
	.align 2, 0
_0800C4E4: .4byte gUnknown_3000FD8
_0800C4E8: .4byte gMPlayTable
_0800C4EC:
	adds r0, r6, 0
	bl m4aMPlayStop
	movs r0, 0
	strh r4, [r5]
	mov r1, r8
	strh r1, [r5, 0x2]
	strh r4, [r5, 0x4]
	strb r0, [r5, 0x6]
_0800C4FE:
	cmp r7, 0
	beq _0800C5BE
	bl sub_800B5F0
	b _0800C5BE
_0800C508:
	ldr r0, _0800C53C
	cmp r4, r0
	bne _0800C564
	bl sub_800B620
	lsls r0, 24
	lsrs r5, r0, 24
	ldr r0, _0800C540
	ldrh r0, [r0]
	cmp r0, 0
	beq _0800C556
	ldr r4, _0800C544
	ldrh r0, [r4]
	cmp r0, r8
	beq _0800C556
	movs r0, 0x1
	bl sub_800CAF0
	lsls r0, 24
	cmp r0, 0
	beq _0800C54C
	ldr r0, _0800C548
	mov r1, r9
	bl m4aMPlayFadeOut
	b _0800C556
	.align 2, 0
_0800C53C: .4byte 0x000003e6
_0800C540: .4byte gUnknown_202D690
_0800C544: .4byte gUnknown_202D68E
_0800C548: .4byte gUnknown_2000970
_0800C54C:
	ldr r0, _0800C560
	bl m4aMPlayStop
	mov r0, r8
	strh r0, [r4]
_0800C556:
	cmp r5, 0
	beq _0800C5BE
	bl sub_800B5F0
	b _0800C5BE
	.align 2, 0
_0800C560: .4byte gUnknown_2000970
_0800C564:
	adds r0, r4, 0
	bl sub_800CACC
	lsls r0, 24
	cmp r0, 0
	beq _0800C5BE
	bl sub_800B620
	lsls r0, 24
	lsrs r6, r0, 24
	ldr r0, _0800C5A0
	ldrh r0, [r0]
	cmp r0, 0
	beq _0800C5B6
	ldr r5, _0800C5A4
	ldrh r0, [r5]
	cmp r0, r4
	bne _0800C5B6
	movs r0, 0x1
	bl sub_800CAF0
	lsls r0, 24
	cmp r0, 0
	beq _0800C5AC
	ldr r0, _0800C5A8
	mov r1, r9
	bl m4aMPlayFadeOut
	b _0800C5B6
	.align 2, 0
_0800C5A0: .4byte gUnknown_202D690
_0800C5A4: .4byte gUnknown_202D68E
_0800C5A8: .4byte gUnknown_2000970
_0800C5AC:
	ldr r0, _0800C5CC
	bl m4aMPlayStop
	mov r1, r8
	strh r1, [r5]
_0800C5B6:
	cmp r6, 0
	beq _0800C5BE
	bl sub_800B5F0
_0800C5BE:
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_0800C5CC: .4byte gUnknown_2000970
	thumb_func_end sub_800C3F8

	thumb_func_start sub_800C5D0
sub_800C5D0:
	push {r4,r5,lr}
	lsls r0, 16
	lsrs r4, r0, 16
	adds r5, r4, 0
	adds r0, r4, 0
	bl sub_800CACC
	lsls r0, 24
	cmp r0, 0
	beq _0800C600
	ldr r0, _0800C5F8
	ldrh r0, [r0]
	cmp r0, 0
	beq _0800C630
	ldr r0, _0800C5FC
	ldrh r0, [r0]
	cmp r0, r4
	bne _0800C630
	movs r0, 0x1
	b _0800C632
	.align 2, 0
_0800C5F8: .4byte gUnknown_202D690
_0800C5FC: .4byte gUnknown_202D68E
_0800C600:
	adds r0, r4, 0
	bl sub_800CAAC
	lsls r0, 24
	cmp r0, 0
	beq _0800C630
	adds r0, r4, 0
	bl sub_800CAE0
	lsls r0, 16
	lsrs r0, 16
	lsls r2, r0, 3
	ldr r1, _0800C62C
	adds r2, r1
	cmp r0, 0x1
	bls _0800C630
	ldrh r0, [r2, 0x2]
	cmp r0, r5
	bne _0800C630
	movs r0, 0x1
	b _0800C632
	.align 2, 0
_0800C62C: .4byte gUnknown_3000FD8
_0800C630:
	movs r0, 0
_0800C632:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_800C5D0

	thumb_func_start SoundVSync
SoundVSync:
	push {r4,lr}
	bl sub_800B620
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	bl m4aSoundVSync
	cmp r4, 0
	beq _0800C650
	bl sub_800B5F0
_0800C650:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end SoundVSync

	thumb_func_start nullsub_18
nullsub_18:
	bx lr
	thumb_func_end nullsub_18

	thumb_func_start UpdateSound
UpdateSound:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	bl m4aSoundMain
	ldr r4, _0800C680
	ldrh r0, [r4]
	cmp r0, 0
	bne _0800C670
	b _0800C7E0
_0800C670:
	cmp r0, 0x2
	beq _0800C6C0
	cmp r0, 0x2
	bgt _0800C684
	cmp r0, 0x1
	beq _0800C68E
	b _0800C8A2
	.align 2, 0
_0800C680: .4byte gUnknown_202D690
_0800C684:
	cmp r0, 0x3
	beq _0800C700
	cmp r0, 0x4
	beq _0800C730
	b _0800C8A2
_0800C68E:
	ldr r2, _0800C69C
	ldrh r0, [r2]
	cmp r0, 0
	beq _0800C6A0
	subs r0, 0x1
	strh r0, [r2]
	b _0800C8A2
	.align 2, 0
_0800C69C: .4byte gUnknown_202D692
_0800C6A0:
	ldr r3, _0800C6B4
	ldrh r1, [r3]
	ldr r0, _0800C6B8
	cmp r1, r0
	bne _0800C6BC
	movs r0, 0x4
	strh r0, [r4]
	movs r0, 0x20
	strh r0, [r2]
	b _0800C8A2
	.align 2, 0
_0800C6B4: .4byte gUnknown_202D68E
_0800C6B8: .4byte 0x000003e5
_0800C6BC:
	ldrh r0, [r3]
	b _0800C6E4
_0800C6C0:
	ldr r0, _0800C6F0
	ldrh r1, [r0]
	ldr r0, _0800C6F4
	cmp r1, r0
	beq _0800C6D8
	movs r0, 0
	bl sub_800CAF0
	lsls r0, 24
	cmp r0, 0
	beq _0800C6D8
	b _0800C8A2
_0800C6D8:
	ldr r2, _0800C6F8
	ldrh r1, [r2]
	ldr r0, _0800C6FC
	cmp r1, r0
	beq _0800C718
	ldrh r0, [r2]
_0800C6E4:
	bl m4aSongNumStart
	movs r0, 0x3
	strh r0, [r4]
	b _0800C8A2
	.align 2, 0
_0800C6F0: .4byte gUnknown_202D68A
_0800C6F4: .4byte 0x000003e7
_0800C6F8: .4byte gUnknown_202D68E
_0800C6FC: .4byte 0x000003e5
_0800C700:
	ldr r0, _0800C724
	ldrh r1, [r0]
	ldr r0, _0800C728
	cmp r1, r0
	beq _0800C718
	movs r0, 0x1
	bl sub_800CAF0
	lsls r0, 24
	cmp r0, 0
	bne _0800C718
	b _0800C8A2
_0800C718:
	movs r0, 0x4
	strh r0, [r4]
	ldr r1, _0800C72C
	movs r0, 0x20
	strh r0, [r1]
	b _0800C8A2
	.align 2, 0
_0800C724: .4byte gUnknown_202D68E
_0800C728: .4byte 0x000003e5
_0800C72C: .4byte gUnknown_202D692
_0800C730:
	ldr r0, _0800C74C
	ldrh r1, [r0]
	ldr r0, _0800C750
	cmp r1, r0
	beq _0800C754
	movs r0, 0x1
	bl sub_800CAF0
	lsls r0, 24
	cmp r0, 0
	beq _0800C748
	b _0800C8A2
_0800C748:
	b _0800C75A
	.align 2, 0
_0800C74C: .4byte gUnknown_202D68E
_0800C750: .4byte 0x000003e5
_0800C754:
	ldr r0, _0800C76C
	bl m4aMPlayStop
_0800C75A:
	ldr r1, _0800C770
	ldrh r0, [r1]
	adds r2, r0, 0
	cmp r2, 0
	beq _0800C774
	subs r0, 0x1
	strh r0, [r1]
	b _0800C8A2
	.align 2, 0
_0800C76C: .4byte gUnknown_2000970
_0800C770: .4byte gUnknown_202D692
_0800C774:
	ldr r3, _0800C794
	ldrh r1, [r3]
	ldr r0, _0800C798
	cmp r1, r0
	beq _0800C7B4
	ldr r1, _0800C79C
	movs r0, 0x1
	strh r0, [r1]
	ldr r0, _0800C7A0
	ldrb r0, [r0]
	cmp r0, 0
	beq _0800C7A4
	ldrh r0, [r3]
	bl m4aSongNumStart
	b _0800C7BE
	.align 2, 0
_0800C794: .4byte gUnknown_202D68A
_0800C798: .4byte 0x000003e7
_0800C79C: .4byte gUnknown_202D688
_0800C7A0: .4byte gUnknown_202D694
_0800C7A4:
	ldr r0, _0800C7B0
	movs r1, 0x4
	bl m4aMPlayFadeIn
	b _0800C7BE
	.align 2, 0
_0800C7B0: .4byte gUnknown_20008F0
_0800C7B4:
	ldr r0, _0800C7CC
	strh r2, [r0]
	ldr r0, _0800C7D0
	bl m4aMPlayStop
_0800C7BE:
	ldr r1, _0800C7D4
	movs r0, 0
	strh r0, [r1]
	ldr r1, _0800C7D8
	ldr r2, _0800C7DC
	b _0800C84C
	.align 2, 0
_0800C7CC: .4byte gUnknown_202D688
_0800C7D0: .4byte gUnknown_20008F0
_0800C7D4: .4byte gUnknown_202D690
_0800C7D8: .4byte gUnknown_202D68E
_0800C7DC: .4byte 0x000003e5
_0800C7E0:
	ldr r5, _0800C810
	ldrh r0, [r5]
	cmp r0, 0
	beq _0800C864
	cmp r0, 0x3
	bgt _0800C8A2
	cmp r0, 0x2
	bge _0800C81C
	cmp r0, 0x1
	bne _0800C8A2
	ldr r0, _0800C814
	ldrh r1, [r0]
	ldr r0, _0800C818
	cmp r1, r0
	beq _0800C80A
	movs r0, 0
	bl sub_800CAF0
	lsls r0, 24
	cmp r0, 0
	beq _0800C8A2
_0800C80A:
	movs r0, 0x2
	strh r0, [r5]
	b _0800C8A2
	.align 2, 0
_0800C810: .4byte gUnknown_202D688
_0800C814: .4byte gUnknown_202D68A
_0800C818: .4byte 0x000003e7
_0800C81C:
	ldr r0, _0800C834
	ldrh r1, [r0]
	ldr r0, _0800C838
	cmp r1, r0
	beq _0800C83C
	movs r0, 0
	bl sub_800CAF0
	lsls r0, 24
	cmp r0, 0
	bne _0800C8A2
	b _0800C842
	.align 2, 0
_0800C834: .4byte gUnknown_202D68A
_0800C838: .4byte 0x000003e7
_0800C83C:
	ldr r0, _0800C854
	bl m4aMPlayStop
_0800C842:
	ldr r1, _0800C858
	movs r0, 0
	strh r0, [r1]
	ldr r1, _0800C85C
	ldr r2, _0800C860
_0800C84C:
	adds r0, r2, 0
	strh r0, [r1]
	b _0800C8A2
	.align 2, 0
_0800C854: .4byte gUnknown_20008F0
_0800C858: .4byte gUnknown_202D688
_0800C85C: .4byte gUnknown_202D68A
_0800C860: .4byte 0x000003e7
_0800C864:
	movs r0, 0
	bl sub_800CAF0
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0
	bne _0800C8A2
	ldr r6, _0800C890
	ldrh r2, [r6]
	adds r1, r2, 0
	ldr r4, _0800C894
	cmp r1, r4
	beq _0800C89C
	movs r0, 0x1
	strh r0, [r5]
	ldr r0, _0800C898
	strh r2, [r0]
	adds r0, r1, 0
	bl m4aSongNumStart
	strh r4, [r6]
	b _0800C8A2
	.align 2, 0
_0800C890: .4byte gUnknown_202D68C
_0800C894: .4byte 0x000003e7
_0800C898: .4byte gUnknown_202D68A
_0800C89C:
	strh r0, [r5]
	ldr r0, _0800C8C4
	strh r1, [r0]
_0800C8A2:
	movs r5, 0x2
	ldr r4, _0800C8C8
	ldr r0, _0800C8CC
	mov r8, r0
	movs r6, 0x18
	movs r7, 0
_0800C8AE:
	ldrh r1, [r4, 0x2]
	cmp r1, r8
	beq _0800C926
	ldrh r0, [r4]
	cmp r0, 0x1
	beq _0800C8D0
	cmp r0, 0x1
	ble _0800C926
	cmp r0, 0x2
	beq _0800C8F0
	b _0800C926
	.align 2, 0
_0800C8C4: .4byte gUnknown_202D68A
_0800C8C8: .4byte gUnknown_3000FE8
_0800C8CC: .4byte 0x000003e5
_0800C8D0:
	ldr r0, _0800C8EC
	cmp r1, r0
	beq _0800C8E4
	lsls r0, r5, 16
	lsrs r0, 16
	bl sub_800CAF0
	lsls r0, 24
	cmp r0, 0
	beq _0800C926
_0800C8E4:
	movs r0, 0x2
	strh r0, [r4]
	b _0800C926
	.align 2, 0
_0800C8EC: .4byte 0x000003e7
_0800C8F0:
	lsls r0, r5, 16
	lsrs r0, 16
	bl sub_800CAF0
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0
	beq _0800C91C
	ldrb r0, [r4, 0x6]
	cmp r0, 0
	beq _0800C926
	strb r7, [r4, 0x6]
	ldr r0, _0800C918
	adds r0, r6, r0
	ldr r0, [r0]
	ldrh r2, [r4, 0x4]
	movs r1, 0xFF
	bl m4aMPlayVolumeControl
	b _0800C926
	.align 2, 0
_0800C918: .4byte gMPlayTable
_0800C91C:
	strh r0, [r4]
	mov r1, r8
	strh r1, [r4, 0x2]
	strh r0, [r4, 0x4]
	strb r7, [r4, 0x6]
_0800C926:
	adds r6, 0xC
	adds r5, 0x1
	adds r4, 0x8
	cmp r5, 0x6
	ble _0800C8AE
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end UpdateSound

	thumb_func_start sub_800C93C
sub_800C93C:
	push {r4,r5,lr}
	ldr r0, _0800C984
	movs r1, 0x10
	bl sub_800C3F8
	ldr r0, _0800C988
	movs r1, 0x10
	bl sub_800C3F8
	bl sub_800B620
	lsls r0, 24
	lsrs r5, r0, 24
	ldr r0, _0800C98C
	ldrh r3, [r0]
	cmp r3, 0
	bne _0800C9AC
	ldr r0, _0800C990
	ldrh r1, [r0]
	ldr r0, _0800C994
	cmp r1, r0
	beq _0800C9AC
	ldr r1, _0800C998
	ldrh r2, [r1]
	subs r0, r2, 0x1
	lsls r0, 16
	lsrs r0, 16
	adds r4, r1, 0
	cmp r0, 0x1
	bhi _0800C9AC
	adds r1, r2, 0
	cmp r1, 0x2
	bne _0800C9A0
	ldr r0, _0800C99C
	strb r3, [r0]
	b _0800C9A8
	.align 2, 0
_0800C984: .4byte 0x000003e5
_0800C988: .4byte 0x000003e6
_0800C98C: .4byte gUnknown_202D690
_0800C990: .4byte gUnknown_202D68A
_0800C994: .4byte 0x000003e7
_0800C998: .4byte gUnknown_202D688
_0800C99C: .4byte gUnknown_202D694
_0800C9A0:
	cmp r1, 0x1
	bne _0800C9A8
	ldr r0, _0800C9C4
	strb r1, [r0]
_0800C9A8:
	movs r0, 0x4
	strh r0, [r4]
_0800C9AC:
	ldr r0, _0800C9C8
	bl m4aMPlayStop
	bl m4aSoundVSyncOff
	cmp r5, 0
	beq _0800C9BE
	bl sub_800B5F0
_0800C9BE:
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_0800C9C4: .4byte gUnknown_202D694
_0800C9C8: .4byte gUnknown_20008F0
	thumb_func_end sub_800C93C

	thumb_func_start sub_800C9CC
sub_800C9CC:
	push {r4,lr}
	bl sub_800B620
	lsls r0, 24
	lsrs r4, r0, 24
	bl m4aSoundVSyncOn
	ldr r0, _0800CA08
	ldrh r0, [r0]
	cmp r0, 0
	bne _0800CA22
	ldr r2, _0800CA0C
	ldrh r1, [r2]
	ldr r0, _0800CA10
	cmp r1, r0
	beq _0800CA22
	ldr r1, _0800CA14
	ldrh r0, [r1]
	cmp r0, 0x4
	bne _0800CA22
	movs r0, 0x1
	strh r0, [r1]
	ldr r0, _0800CA18
	ldrb r0, [r0]
	cmp r0, 0
	beq _0800CA1C
	ldrh r0, [r2]
	bl m4aSongNumStart
	b _0800CA22
	.align 2, 0
_0800CA08: .4byte gUnknown_202D690
_0800CA0C: .4byte gUnknown_202D68A
_0800CA10: .4byte 0x000003e7
_0800CA14: .4byte gUnknown_202D688
_0800CA18: .4byte gUnknown_202D694
_0800CA1C:
	ldr r0, _0800CA30
	bl m4aMPlayContinue
_0800CA22:
	cmp r4, 0
	beq _0800CA2A
	bl sub_800B5F0
_0800CA2A:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0800CA30: .4byte gUnknown_20008F0
	thumb_func_end sub_800C9CC

	thumb_func_start nullsub_179
nullsub_179:
	bx lr
	thumb_func_end nullsub_179

	thumb_func_start sub_800CA38
sub_800CA38:
	push {r4,lr}
	adds r4, r0, 0
	bl sub_800CA9C
	lsls r0, 24
	cmp r0, 0
	beq _0800CA54
	lsls r0, r4, 16
	lsrs r0, 16
	bl sub_800CAE0
	lsls r0, 16
	cmp r0, 0
	beq _0800CA70
_0800CA54:
	adds r0, r4, 0
	bl sub_800CACC
	lsls r0, 24
	cmp r0, 0
	beq _0800CA74
	lsls r0, r4, 16
	lsrs r0, 16
	bl sub_800CAE0
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0x1
	bne _0800CA90
_0800CA70:
	movs r0, 0x1
	b _0800CA92
_0800CA74:
	adds r0, r4, 0
	bl sub_800CAAC
	lsls r0, 24
	cmp r0, 0
	beq _0800CA90
	lsls r0, r4, 16
	lsrs r0, 16
	bl sub_800CAE0
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0x1
	bhi _0800CA70
_0800CA90:
	movs r0, 0
_0800CA92:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_800CA38

	thumb_func_start nullsub_19
nullsub_19:
	bx lr
	thumb_func_end nullsub_19

	thumb_func_start sub_800CA9C
sub_800CA9C:
	push {lr}
	cmp r0, 0x80
	bls _0800CAA6
	movs r0, 0
	b _0800CAA8
_0800CAA6:
	movs r0, 0x1
_0800CAA8:
	pop {r1}
	bx r1
	thumb_func_end sub_800CA9C

	thumb_func_start sub_800CAAC
sub_800CAAC:
	push {lr}
	ldr r1, _0800CABC
	adds r0, r1
	ldr r1, _0800CAC0
	cmp r0, r1
	bls _0800CAC4
	movs r0, 0
	b _0800CAC6
	.align 2, 0
_0800CABC: .4byte 0xfffffed4
_0800CAC0: .4byte 0x0000027f
_0800CAC4:
	movs r0, 0x1
_0800CAC6:
	pop {r1}
	bx r1
	thumb_func_end sub_800CAAC

	thumb_func_start sub_800CACC
sub_800CACC:
	push {lr}
	subs r0, 0xC8
	cmp r0, 0x13
	bls _0800CAD8
	movs r0, 0
	b _0800CADA
_0800CAD8:
	movs r0, 0x1
_0800CADA:
	pop {r1}
	bx r1
	thumb_func_end sub_800CACC

	thumb_func_start sub_800CAE0
sub_800CAE0:
	lsls r0, 16
	ldr r1, _0800CAEC
	lsrs r0, 13
	adds r0, r1
	ldrh r0, [r0, 0x4]
	bx lr
	.align 2, 0
_0800CAEC: .4byte gSongTable
	thumb_func_end sub_800CAE0

	thumb_func_start sub_800CAF0
sub_800CAF0:
	push {lr}
	lsls r0, 16
	lsrs r0, 16
	ldr r2, _0800CB0C
	lsls r1, r0, 1
	adds r1, r0
	lsls r1, 2
	adds r1, r2
	ldr r0, [r1]
	ldrh r0, [r0, 0x4]
	cmp r0, 0
	beq _0800CB10
	movs r0, 0x1
	b _0800CB12
	.align 2, 0
_0800CB0C: .4byte gMPlayTable
_0800CB10:
	movs r0, 0
_0800CB12:
	pop {r1}
	bx r1
	thumb_func_end sub_800CAF0

	thumb_func_start nullsub_20
nullsub_20:
	bx lr
	thumb_func_end nullsub_20

	thumb_func_start nullsub_21
nullsub_21:
	bx lr
	thumb_func_end nullsub_21

	thumb_func_start sub_800CB20
sub_800CB20:
	push {lr}
	bl sub_800BA5C
	ldr r1, _0800CB48
	ldr r0, [r1]
	adds r0, 0x1
	str r0, [r1]
	ldr r0, _0800CB4C
	ldrh r1, [r0]
	movs r0, 0x5
	ands r0, r1
	cmp r0, 0
	beq _0800CB3E
	bl Random
_0800CB3E:
	bl Random
	pop {r0}
	bx r0
	.align 2, 0
_0800CB48: .4byte gUnknown_203B0B8
_0800CB4C: .4byte gUnknown_203B0BC
	thumb_func_end sub_800CB20

	thumb_func_start sub_800CB50
sub_800CB50:
	ldr r0, _0800CB58
	ldr r0, [r0]
	bx lr
	.align 2, 0
_0800CB58: .4byte gUnknown_203B0B8
	thumb_func_end sub_800CB50

	thumb_func_start nullsub_180
nullsub_180:
	bx lr
	thumb_func_end nullsub_180

	thumb_func_start xxx_call_update_bg_sound_input
xxx_call_update_bg_sound_input:
	push {lr}
	bl xxx_update_bg_sound_input
	pop {r0}
	bx r0
	thumb_func_end xxx_call_update_bg_sound_input

	thumb_func_start nullsub_181
nullsub_181:
	bx lr
	thumb_func_end nullsub_181

	thumb_func_start sub_800CB70
sub_800CB70:
	movs r0, 0
	bx lr
	thumb_func_end sub_800CB70

	thumb_func_start ReadKeyInput
ReadKeyInput:
	push {r4,lr}
	adds r2, r0, 0
	ldr r0, _0800CC38
	ldrh r1, [r0]
	ldr r3, _0800CC3C
	adds r0, r3, 0
	adds r3, r0, 0
	eors r3, r1
	movs r0, 0
	strh r0, [r2]
	movs r1, 0x40
	adds r0, r3, 0
	ands r0, r1
	cmp r0, 0
	beq _0800CB94
	strh r1, [r2]
_0800CB94:
	movs r0, 0x80
	ands r0, r3
	cmp r0, 0
	beq _0800CBA4
	ldrh r0, [r2]
	movs r1, 0x80
	orrs r0, r1
	strh r0, [r2]
_0800CBA4:
	movs r0, 0x20
	ands r0, r3
	cmp r0, 0
	beq _0800CBB4
	ldrh r0, [r2]
	movs r1, 0x20
	orrs r0, r1
	strh r0, [r2]
_0800CBB4:
	movs r0, 0x10
	ands r0, r3
	cmp r0, 0
	beq _0800CBC4
	ldrh r0, [r2]
	movs r1, 0x10
	orrs r0, r1
	strh r0, [r2]
_0800CBC4:
	movs r0, 0x1
	ands r0, r3
	cmp r0, 0
	beq _0800CBD4
	ldrh r0, [r2]
	movs r1, 0x1
	orrs r0, r1
	strh r0, [r2]
_0800CBD4:
	movs r0, 0x2
	ands r0, r3
	cmp r0, 0
	beq _0800CBE4
	ldrh r0, [r2]
	movs r1, 0x2
	orrs r0, r1
	strh r0, [r2]
_0800CBE4:
	movs r0, 0x8
	ands r0, r3
	cmp r0, 0
	beq _0800CBF4
	ldrh r0, [r2]
	movs r1, 0x8
	orrs r0, r1
	strh r0, [r2]
_0800CBF4:
	movs r0, 0x4
	ands r0, r3
	cmp r0, 0
	beq _0800CC04
	ldrh r0, [r2]
	movs r1, 0x4
	orrs r0, r1
	strh r0, [r2]
_0800CC04:
	movs r4, 0x80
	lsls r4, 1
	adds r0, r3, 0
	ands r0, r4
	cmp r0, 0
	beq _0800CC18
	ldrh r1, [r2]
	adds r0, r4, 0
	orrs r0, r1
	strh r0, [r2]
_0800CC18:
	movs r4, 0x80
	lsls r4, 2
	adds r0, r3, 0
	ands r0, r4
	cmp r0, 0
	beq _0800CC2C
	ldrh r1, [r2]
	adds r0, r4, 0
	orrs r0, r1
	strh r0, [r2]
_0800CC2C:
	ldr r0, _0800CC40
	strh r3, [r0]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0800CC38: .4byte 0x04000130
_0800CC3C: .4byte 0x000003ff
_0800CC40: .4byte gUnknown_203B0BC
	thumb_func_end ReadKeyInput

	thumb_func_start sub_800CC44
sub_800CC44:
	push {lr}
	adds r2, r1, 0
	cmp r0, 0
	bge _0800CC50
	movs r0, 0
	b _0800CC56
_0800CC50:
	cmp r0, 0x10
	ble _0800CC56
	movs r0, 0x10
_0800CC56:
	cmp r2, 0
	bge _0800CC5E
	movs r2, 0
	b _0800CC64
_0800CC5E:
	cmp r2, 0x10
	ble _0800CC64
	movs r2, 0x10
_0800CC64:
	ldr r1, _0800CC7C
	strb r0, [r1]
	ldr r0, _0800CC80
	strb r2, [r0]
	ldr r2, _0800CC84
	ldrb r1, [r1]
	ldrb r0, [r0]
	lsls r0, 8
	orrs r1, r0
	strh r1, [r2]
	pop {r0}
	bx r0
	.align 2, 0
_0800CC7C: .4byte gUnknown_202D6B8
_0800CC80: .4byte gUnknown_202D6B9
_0800CC84: .4byte gUnknown_202D7FA
	thumb_func_end sub_800CC44

	thumb_func_start sub_800CC88
sub_800CC88:
	ldr r2, _0800CC90
	strh r0, [r2, 0x4]
	strh r1, [r2, 0x6]
	bx lr
	.align 2, 0
_0800CC90: .4byte gUnknown_202D698
	thumb_func_end sub_800CC88

	thumb_func_start sub_800CC94
sub_800CC94:
	ldr r2, _0800CC9C
	strh r0, [r2, 0x4]
	strh r1, [r2, 0x6]
	bx lr
	.align 2, 0
_0800CC9C: .4byte gUnknown_202D6A0
	thumb_func_end sub_800CC94

	thumb_func_start sub_800CCA0
sub_800CCA0:
	ldr r2, _0800CCA8
	strh r0, [r2, 0x4]
	strh r1, [r2, 0x6]
	bx lr
	.align 2, 0
_0800CCA8: .4byte gUnknown_202D6A8
	thumb_func_end sub_800CCA0

	thumb_func_start sub_800CCAC
sub_800CCAC:
	ldr r2, _0800CCB4
	strh r0, [r2, 0x4]
	strh r1, [r2, 0x6]
	bx lr
	.align 2, 0
_0800CCB4: .4byte gUnknown_202D6B0
	thumb_func_end sub_800CCAC

	thumb_func_start sub_800CCB8
sub_800CCB8:
	push {lr}
	cmp r0, 0x1
	beq _0800CCD4
	cmp r0, 0x1
	ble _0800CCCA
	cmp r0, 0x2
	beq _0800CCDE
	cmp r0, 0x3
	beq _0800CCE8
_0800CCCA:
	adds r0, r1, 0
	adds r1, r2, 0
	bl sub_800CC88
	b _0800CCF0
_0800CCD4:
	adds r0, r1, 0
	adds r1, r2, 0
	bl sub_800CC94
	b _0800CCF0
_0800CCDE:
	adds r0, r1, 0
	adds r1, r2, 0
	bl sub_800CCA0
	b _0800CCF0
_0800CCE8:
	adds r0, r1, 0
	adds r1, r2, 0
	bl sub_800CCAC
_0800CCF0:
	pop {r0}
	bx r0
	thumb_func_end sub_800CCB8

	thumb_func_start sub_800CCF4
sub_800CCF4:
	push {lr}
	cmp r0, 0x1
	beq _0800CD10
	cmp r0, 0x1
	ble _0800CD06
	cmp r0, 0x2
	beq _0800CD18
	cmp r0, 0x3
	beq _0800CD20
_0800CD06:
	ldr r0, _0800CD0C
	b _0800CD22
	.align 2, 0
_0800CD0C: .4byte gUnknown_202D698
_0800CD10:
	ldr r0, _0800CD14
	b _0800CD22
	.align 2, 0
_0800CD14: .4byte gUnknown_202D6A0
_0800CD18:
	ldr r0, _0800CD1C
	b _0800CD22
	.align 2, 0
_0800CD1C: .4byte gUnknown_202D6A8
_0800CD20:
	ldr r0, _0800CD28
_0800CD22:
	strh r1, [r0, 0x4]
	pop {r0}
	bx r0
	.align 2, 0
_0800CD28: .4byte gUnknown_202D6B0
	thumb_func_end sub_800CCF4

	thumb_func_start sub_800CD2C
sub_800CD2C:
	push {lr}
	cmp r0, 0x1
	beq _0800CD48
	cmp r0, 0x1
	ble _0800CD3E
	cmp r0, 0x2
	beq _0800CD50
	cmp r0, 0x3
	beq _0800CD58
_0800CD3E:
	ldr r0, _0800CD44
	b _0800CD5A
	.align 2, 0
_0800CD44: .4byte gUnknown_202D698
_0800CD48:
	ldr r0, _0800CD4C
	b _0800CD5A
	.align 2, 0
_0800CD4C: .4byte gUnknown_202D6A0
_0800CD50:
	ldr r0, _0800CD54
	b _0800CD5A
	.align 2, 0
_0800CD54: .4byte gUnknown_202D6A8
_0800CD58:
	ldr r0, _0800CD60
_0800CD5A:
	strh r1, [r0, 0x6]
	pop {r0}
	bx r0
	.align 2, 0
_0800CD60: .4byte gUnknown_202D6B0
	thumb_func_end sub_800CD2C

	thumb_func_start sub_800CD64
sub_800CD64:
	ldr r2, _0800CD7C
	strb r1, [r2]
	ldr r2, _0800CD80
	negs r1, r0
	orrs r1, r0
	asrs r1, 31
	movs r3, 0x80
	lsls r3, 8
	adds r0, r3, 0
	ands r1, r0
	strh r1, [r2, 0x2]
	bx lr
	.align 2, 0
_0800CD7C: .4byte gUnknown_202D7FE
_0800CD80: .4byte gUnknown_202D6A8
	thumb_func_end sub_800CD64

	thumb_func_start SetBGOBJEnableFlags
SetBGOBJEnableFlags:
	push {r4,lr}
	movs r3, 0x80
	lsls r3, 19
	ldrh r1, [r3]
	ldr r2, _0800CDA4
	ands r2, r1
	lsls r0, 8
	movs r4, 0xF8
	lsls r4, 5
	adds r1, r4, 0
	bics r1, r0
	orrs r2, r1
	strh r2, [r3]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0800CDA4: .4byte 0x0000e0ff
	thumb_func_end SetBGOBJEnableFlags

	thumb_func_start sub_800CDA8
sub_800CDA8:
	ldr r1, _0800CDBC
	str r0, [r1]
	ldr r2, _0800CDC0
	ldr r1, _0800CDC4
	lsls r0, 1
	adds r0, r1
	ldrh r0, [r0]
	strh r0, [r2]
	bx lr
	.align 2, 0
_0800CDBC: .4byte gUnknown_202D800
_0800CDC0: .4byte gUnknown_202D7FC
_0800CDC4: .4byte gUnknown_203B0BE
	thumb_func_end sub_800CDA8

	thumb_func_start sub_800CDC8
sub_800CDC8:
	ldr r0, _0800CDD0
	ldr r0, [r0]
	bx lr
	.align 2, 0
_0800CDD0: .4byte gUnknown_202D800
	thumb_func_end sub_800CDC8

	thumb_func_start SetWindowTitle
SetWindowTitle:
	bx lr
	thumb_func_end SetWindowTitle

	thumb_func_start nullsub_23
nullsub_23:
	bx lr
	thumb_func_end nullsub_23

	thumb_func_start nullsub_182
nullsub_182:
	bx lr
	thumb_func_end nullsub_182

	thumb_func_start sub_800CDE0
sub_800CDE0:
	movs r0, 0x1
	bx lr
	thumb_func_end sub_800CDE0

	thumb_func_start CpuCopy
CpuCopy:
	push {lr}
	adds r3, r0, 0
	cmp r2, 0
	bge _0800CDEE
	adds r2, 0x3
_0800CDEE:
	lsls r2, 9
	lsrs r2, 11
	movs r0, 0x80
	lsls r0, 19
	orrs r2, r0
	adds r0, r1, 0
	adds r1, r3, 0
	bl CpuSet
	pop {r0}
	bx r0
	thumb_func_end CpuCopy

	thumb_func_start CpuClear
CpuClear:
	push {lr}
	sub sp, 0x4
	adds r3, r0, 0
	movs r0, 0
	str r0, [sp]
	cmp r1, 0
	bge _0800CE14
	adds r1, 0x3
_0800CE14:
	lsls r2, r1, 9
	lsrs r2, 11
	movs r0, 0xA0
	lsls r0, 19
	orrs r2, r0
	mov r0, sp
	adds r1, r3, 0
	bl CpuSet
	add sp, 0x4
	pop {r0}
	bx r0
	thumb_func_end CpuClear

	thumb_func_start CpuFill
CpuFill:
	push {lr}
	sub sp, 0x4
	adds r3, r0, 0
	str r1, [sp]
	cmp r2, 0
	bge _0800CE3A
	adds r2, 0x3
_0800CE3A:
	lsls r2, 9
	lsrs r2, 11
	movs r0, 0xA0
	lsls r0, 19
	orrs r2, r0
	mov r0, sp
	adds r1, r3, 0
	bl CpuSet
	add sp, 0x4
	pop {r0}
	bx r0
	thumb_func_end CpuFill

	thumb_func_start sub_800CE54
sub_800CE54:
	push {lr}
	ldr r2, _0800CEC0
	ldrh r0, [r2]
	movs r3, 0x80
	lsls r3, 8
	adds r1, r3, 0
	orrs r0, r1
	ldr r1, _0800CEC4
	ands r0, r1
	strh r0, [r2]
	mov r8, r8
	mov r8, r8
	mov r8, r8
	mov r8, r8
	ldr r1, _0800CEC8
	ands r0, r1
	strh r0, [r2]
	ldr r1, _0800CECC
	ldr r2, _0800CED0
	adds r0, r2, 0
	strh r0, [r1]
	adds r1, 0x2
	movs r0, 0x3D
	strh r0, [r1]
	adds r1, 0x6
	ldr r0, _0800CED4
	ldrh r0, [r0]
	strh r0, [r1]
	adds r1, 0x2
	ldr r0, _0800CED8
	ldrh r0, [r0]
	strh r0, [r1]
	ldr r0, _0800CEDC
	ldrb r1, [r0]
	cmp r1, 0
	beq _0800CEF4
	ldr r1, _0800CEE0
	ldr r0, _0800CEE4
	ldr r2, [r0]
	adds r0, r2, 0x4
	str r0, [r1]
	ldr r3, _0800CEE8
	str r3, [r1, 0x4]
	ldr r0, _0800CEEC
	str r0, [r1, 0x8]
	ldr r0, [r1, 0x8]
	ldrh r0, [r2]
	strh r0, [r3]
	subs r1, 0x6E
	ldrh r0, [r2, 0x2]
	strh r0, [r1]
	ldr r0, _0800CEF0
	movs r1, 0xA0
	b _0800CEFE
	.align 2, 0
_0800CEC0: .4byte 0x040000ba
_0800CEC4: .4byte 0x0000cdff
_0800CEC8: .4byte 0x00007fff
_0800CECC: .4byte 0x04000048
_0800CED0: .4byte 0x00003f3f
_0800CED4: .4byte gUnknown_202D7FC
_0800CED8: .4byte gUnknown_202D7FA
_0800CEDC: .4byte gUnknown_2026E38
_0800CEE0: .4byte 0x040000b0
_0800CEE4: .4byte gUnknown_2026E3C
_0800CEE8: .4byte 0x04000040
_0800CEEC: .4byte 0xa2600002
_0800CEF0: .4byte 0x04000044
_0800CEF4:
	ldr r0, _0800CF08
	strh r1, [r0]
	adds r0, 0x2
	strh r1, [r0]
	adds r0, 0x2
_0800CEFE:
	strh r1, [r0]
	adds r0, 0x2
	strh r1, [r0]
	pop {r0}
	bx r0
	.align 2, 0
_0800CF08: .4byte 0x04000040
	thumb_func_end sub_800CE54

	.align 2, 0 @ Don't pad with nop.
