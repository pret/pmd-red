	.include "constants/gba_constants.inc"
	.include "asm/macros.inc"

	.syntax unified

	.text

	thumb_func_start sub_800558C
sub_800558C:
	push {r4-r7,lr}
	sub sp, 0x4
	adds r5, r0, 0
	adds r4, r1, 0
	adds r6, r2, 0
	adds r7, r3, 0
	ldrh r0, [r5]
	lsrs r0, 15
	cmp r0, 0
	beq _08005602
	movs r1, 0x20
	ldrsh r0, [r5, r1]
	cmp r0, 0
	bge _080055AE
	adds r0, r5, 0
	bl sub_80054BC
_080055AE:
	ldrh r0, [r5]
	lsrs r0, 15
	cmp r0, 0
	beq _08005602
	ldrh r0, [r5, 0xC]
	adds r0, r4
	strh r0, [r5, 0x8]
	ldrh r0, [r5, 0xE]
	adds r0, r6
	strh r0, [r5, 0xA]
	adds r1, r5, 0
	adds r1, 0x26
	ldr r0, [sp, 0x18]
	strb r0, [r1]
	strh r7, [r5, 0x1E]
	ldr r0, [r5, 0x34]
	ldr r1, [r5, 0x38]
	adds r2, r5, 0
	adds r2, 0x8
	movs r3, 0x22
	ldrsh r4, [r5, r3]
	movs r6, 0x20
	ldrsh r3, [r5, r6]
	eors r4, r3
	negs r3, r4
	orrs r3, r4
	lsrs r3, 31
	str r3, [sp]
	ldr r3, [sp, 0x1C]
	bl sub_800533C
	ldrh r0, [r5, 0x20]
	strh r0, [r5, 0x22]
	ldrh r1, [r5]
	movs r0, 0x80
	lsls r0, 4
	ands r0, r1
	cmp r0, 0
	beq _08005602
	ldr r0, _0800560C
	ands r0, r1
	strh r0, [r5]
_08005602:
	add sp, 0x4
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_0800560C: .4byte 0x0000f7ff
	thumb_func_end sub_800558C

	thumb_func_start sub_8005610
sub_8005610:
	push {lr}
	ldr r0, [r0, 0x4]
	bl sub_800561C
	pop {r0}
	bx r0
	thumb_func_end sub_8005610

	thumb_func_start sub_800561C
sub_800561C:
	push {r4-r7,lr}
	adds r5, r0, 0
	adds r0, r1, 0
	adds r7, r2, 0
	adds r6, r3, 0
	ldr r1, [r5, 0x14]
	cmp r1, 0
	beq _0800563A
	lsls r0, 5
	ldr r2, _08005664
	adds r0, r2
	ldr r2, [r5, 0x1C]
	lsls r2, 5
	bl CpuCopy
_0800563A:
	ldr r0, [r5, 0x18]
	cmp r0, 0
	beq _0800565C
	movs r4, 0
_08005642:
	movs r1, 0xF0
	lsls r1, 1
	adds r0, r4, r1
	lsls r2, r4, 2
	ldr r1, [r5, 0x18]
	adds r1, r2
	adds r2, r7, 0
	adds r3, r6, 0
	bl SetBGPaletteBufferColorRGB
	adds r4, 0x1
	cmp r4, 0xF
	ble _08005642
_0800565C:
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_08005664: .4byte 0x06010000
	thumb_func_end sub_800561C

	thumb_func_start sub_8005668
sub_8005668:
	push {lr}
	ldr r0, [r0, 0x4]
	bl sub_8005674
	pop {r1}
	bx r1
	thumb_func_end sub_8005668

	thumb_func_start sub_8005674
sub_8005674:
	push {r4,lr}
	adds r4, r0, 0
	ldr r3, [r4, 0x14]
	cmp r3, 0
	beq _0800568E
	lsls r0, r1, 5
	ldr r1, _08005698
	adds r0, r1
	ldr r2, [r4, 0x1C]
	lsls r2, 5
	adds r1, r3, 0
	bl CpuCopy
_0800568E:
	ldr r0, [r4, 0x18]
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_08005698: .4byte 0x06010000
	thumb_func_end sub_8005674

	thumb_func_start sub_800569C
sub_800569C:
	push {r4-r6,lr}
	adds r3, r0, 0
	adds r4, r1, 0
	lsls r2, 24
	lsrs r2, 24
	movs r0, 0
	strh r0, [r3]
	strh r0, [r3, 0x2]
	ldrh r0, [r4]
	lsrs r0, 15
	cmp r0, 0
	beq _080056F8
	cmp r2, 0x3
	bhi _080056F8
	ldr r1, [r4, 0x30]
	cmp r1, 0
	beq _080056F2
	movs r5, 0x20
	ldrsh r0, [r4, r5]
	lsls r0, 4
	adds r5, r1, r0
	lsls r0, r2, 2
	adds r2, r5, r0
	movs r6, 0
	ldrsh r1, [r2, r6]
	cmp r1, 0x63
	bne _080056E0
	movs r6, 0x2
	ldrsh r1, [r2, r6]
	cmp r1, 0x63
	bne _080056E0
	strh r1, [r3]
	strh r1, [r3, 0x2]
	b _080056F8
_080056E0:
	adds r0, r5, r0
	ldrh r1, [r0]
	ldrh r2, [r4, 0xC]
	adds r1, r2
	strh r1, [r3]
	ldrh r0, [r0, 0x2]
	ldrh r4, [r4, 0xE]
	adds r0, r4
	b _080056F6
_080056F2:
	movs r0, 0x63
	strh r0, [r3]
_080056F6:
	strh r0, [r3, 0x2]
_080056F8:
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end sub_800569C

	thumb_func_start sub_8005700
sub_8005700:
	push {r4,r5,lr}
	adds r3, r0, 0
	ldrh r0, [r1]
	lsrs r0, 15
	cmp r0, 0
	beq _0800575C
	ldr r2, [r1, 0x30]
	cmp r2, 0
	beq _0800574C
	movs r4, 0x20
	ldrsh r0, [r1, r4]
	lsls r0, 4
	adds r2, r0
	adds r4, r2, 0
	adds r4, 0xC
_0800571E:
	movs r5, 0
	ldrsh r0, [r2, r5]
	cmp r0, 0x63
	bne _08005732
	movs r5, 0x2
	ldrsh r0, [r2, r5]
	cmp r0, 0x63
	bne _08005732
	strh r0, [r3]
	b _08005740
_08005732:
	ldrh r0, [r2]
	ldrh r5, [r1, 0xC]
	adds r0, r5
	strh r0, [r3]
	ldrh r0, [r2, 0x2]
	ldrh r5, [r1, 0xE]
	adds r0, r5
_08005740:
	strh r0, [r3, 0x2]
	adds r3, 0x4
	adds r2, 0x4
	cmp r2, r4
	ble _0800571E
	b _0800575C
_0800574C:
	movs r1, 0x63
	movs r0, 0x3
_08005750:
	strh r1, [r3]
	strh r1, [r3, 0x2]
	adds r3, 0x4
	subs r0, 0x1
	cmp r0, 0
	bge _08005750
_0800575C:
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_8005700

	thumb_func_start sub_8005764
sub_8005764:
	push {lr}
	ldr r1, [r1, 0x4]
	bl sub_8005770
	pop {r0}
	bx r0
	thumb_func_end sub_8005764

	thumb_func_start sub_8005770
sub_8005770:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	mov r8, r2
	adds r7, r3, 0
	movs r5, 0
	adds r0, 0x10
	lsls r6, r0, 4
	adds r4, r1, 0
_08005782:
	adds r0, r6, r5
	adds r1, r4, 0
	mov r2, r8
	adds r3, r7, 0
	bl SetBGPaletteBufferColorRGB
	adds r4, 0x4
	adds r5, 0x1
	cmp r5, 0xF
	ble _08005782
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_8005770

	thumb_func_start nullsub_7
nullsub_7:
	bx lr
	thumb_func_end nullsub_7

	thumb_func_start nullsub_8
nullsub_8:
	bx lr
	thumb_func_end nullsub_8

	thumb_func_start nullsub_9
nullsub_9:
	bx lr
	thumb_func_end nullsub_9

	thumb_func_start nullsub_10
nullsub_10:
	bx lr
	thumb_func_end nullsub_10

	thumb_func_start nullsub_144
nullsub_144:
	bx lr
	thumb_func_end nullsub_144

	thumb_func_start nullsub_11
nullsub_11:
	bx lr
	thumb_func_end nullsub_11

	thumb_func_start nullsub_12
nullsub_12:
	bx lr
	thumb_func_end nullsub_12

	thumb_func_start nullsub_13
nullsub_13:
	bx lr
	thumb_func_end nullsub_13

	thumb_func_start nullsub_145
nullsub_145:
	bx lr
	thumb_func_end nullsub_145

	thumb_func_start nullsub_14
nullsub_14:
	bx lr
	thumb_func_end nullsub_14

	thumb_func_start nullsub_146
nullsub_146:
	bx lr
	thumb_func_end nullsub_146

	thumb_func_start nullsub_147
nullsub_147:
	bx lr
	thumb_func_end nullsub_147

	thumb_func_start nullsub_148
nullsub_148:
	bx lr
	thumb_func_end nullsub_148

	thumb_func_start nullsub_149
nullsub_149:
	bx lr
	thumb_func_end nullsub_149

	thumb_func_start sub_80057D8
sub_80057D8:
	movs r0, 0
	bx lr
	thumb_func_end sub_80057D8

	thumb_func_start sub_80057DC
sub_80057DC:
	movs r0, 0
	bx lr
	thumb_func_end sub_80057DC

	thumb_func_start nullsub_150
nullsub_150:
	bx lr
	thumb_func_end nullsub_150

	thumb_func_start nullsub_151
nullsub_151:
	bx lr
	thumb_func_end nullsub_151

	thumb_func_start sub_80057E8
sub_80057E8:
	ldr r1, _08005814
	movs r0, 0x1
	strb r0, [r1]
	ldr r0, _08005818
	movs r2, 0
	str r2, [r0]
	ldr r1, _0800581C
	movs r0, 0x1
	str r0, [r1]
	ldr r0, _08005820
	str r2, [r0]
	ldr r0, _08005824
	str r2, [r0]
	ldr r0, _08005828
	strb r2, [r0]
	ldr r1, _0800582C
	ldr r3, _08005830
	adds r0, r3, 0
	strh r0, [r1]
	ldr r0, _08005834
	str r2, [r0]
	bx lr
	.align 2, 0
_08005814: .4byte gUnknown_2026E4C
_08005818: .4byte gUnknown_2026E54
_0800581C: .4byte gUnknown_2026E50
_08005820: .4byte gUnknown_2026E58
_08005824: .4byte gUnknown_2026E3C
_08005828: .4byte gUnknown_2026E38
_0800582C: .4byte gUnknown_2026E4E
_08005830: .4byte 0x0000060c
_08005834: .4byte gUnknown_203B078
	thumb_func_end sub_80057E8

	thumb_func_start sub_8005838
sub_8005838:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x18
	adds r5, r0, 0
	lsls r1, 24
	lsrs r1, 24
	ldr r0, _08005880
	ldrb r0, [r0]
	cmp r0, 0
	bne _08005854
	movs r1, 0
_08005854:
	ldr r0, _08005884
	ldr r0, [r0]
	ldr r3, _08005888
	cmp r0, 0
	bne _08005860
	ldr r3, _0800588C
_08005860:
	ldr r0, _08005890
	ldr r2, [r0]
	cmp r2, 0
	bne _0800586A
	ldr r2, _08005894
_0800586A:
	ldr r0, _08005898
	str r3, [r0]
	cmp r1, 0x5
	bls _08005876
	bl _08006094
_08005876:
	lsls r0, r1, 2
	ldr r1, _0800589C
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08005880: .4byte gUnknown_2026E4C
_08005884: .4byte gUnknown_2026E54
_08005888: .4byte gUnknown_20270E8
_0800588C: .4byte gUnknown_2026E60
_08005890: .4byte gUnknown_203B078
_08005894: .4byte gUnknown_80B83EA
_08005898: .4byte gUnknown_2026E58
_0800589C: .4byte _080058A0
	.align 2, 0
_080058A0:
	.4byte _080058B8
	.4byte _08005984
	.4byte _08005A98
	.4byte _08005BAC
	.4byte _08005D46
	.4byte _08005E58
_080058B8:
	movs r1, 0
	movs r7, 0x9
_080058BC:
	ldrh r0, [r2]
	strh r0, [r3]
	adds r2, 0x2
	adds r3, 0x2
	strh r1, [r3]
	adds r3, 0x2
	ldrh r0, [r2]
	strh r0, [r3]
	adds r2, 0x2
	adds r3, 0x2
	strh r1, [r3]
	adds r3, 0x2
	ldrh r0, [r2]
	strh r0, [r3]
	adds r2, 0x2
	adds r3, 0x2
	strh r1, [r3]
	adds r3, 0x2
	ldrh r0, [r2]
	strh r0, [r3]
	adds r2, 0x2
	adds r3, 0x2
	strh r1, [r3]
	adds r3, 0x2
	ldrh r0, [r2]
	strh r0, [r3]
	adds r2, 0x2
	adds r3, 0x2
	strh r1, [r3]
	adds r3, 0x2
	ldrh r0, [r2]
	strh r0, [r3]
	adds r2, 0x2
	adds r3, 0x2
	strh r1, [r3]
	adds r3, 0x2
	ldrh r0, [r2]
	strh r0, [r3]
	adds r2, 0x2
	adds r3, 0x2
	strh r1, [r3]
	adds r3, 0x2
	ldrh r0, [r2]
	strh r0, [r3]
	adds r2, 0x2
	adds r3, 0x2
	strh r1, [r3]
	adds r3, 0x2
	ldrh r0, [r2]
	strh r0, [r3]
	adds r2, 0x2
	adds r3, 0x2
	strh r1, [r3]
	adds r3, 0x2
	ldrh r0, [r2]
	strh r0, [r3]
	adds r2, 0x2
	adds r3, 0x2
	strh r1, [r3]
	adds r3, 0x2
	ldrh r0, [r2]
	strh r0, [r3]
	adds r2, 0x2
	adds r3, 0x2
	strh r1, [r3]
	adds r3, 0x2
	ldrh r0, [r2]
	strh r0, [r3]
	adds r2, 0x2
	adds r3, 0x2
	strh r1, [r3]
	adds r3, 0x2
	ldrh r0, [r2]
	strh r0, [r3]
	adds r2, 0x2
	adds r3, 0x2
	strh r1, [r3]
	adds r3, 0x2
	ldrh r0, [r2]
	strh r0, [r3]
	adds r2, 0x2
	adds r3, 0x2
	strh r1, [r3]
	adds r3, 0x2
	ldrh r0, [r2]
	strh r0, [r3]
	adds r2, 0x2
	adds r3, 0x2
	strh r1, [r3]
	adds r3, 0x2
	ldrh r0, [r2]
	strh r0, [r3]
	adds r2, 0x2
	adds r3, 0x2
	strh r1, [r3]
	adds r3, 0x2
	subs r7, 0x1
	cmp r7, 0
	bge _080058BC
	b _08006094
_08005984:
	ldr r1, _08005A94
	movs r7, 0x9
_08005988:
	ldrh r0, [r2]
	strh r0, [r3]
	adds r2, 0x2
	adds r3, 0x2
	ldrh r0, [r1]
	strh r0, [r3]
	adds r1, 0x2
	adds r3, 0x2
	ldrh r0, [r2]
	strh r0, [r3]
	adds r2, 0x2
	adds r3, 0x2
	ldrh r0, [r1]
	strh r0, [r3]
	adds r1, 0x2
	adds r3, 0x2
	ldrh r0, [r2]
	strh r0, [r3]
	adds r2, 0x2
	adds r3, 0x2
	ldrh r0, [r1]
	strh r0, [r3]
	adds r1, 0x2
	adds r3, 0x2
	ldrh r0, [r2]
	strh r0, [r3]
	adds r2, 0x2
	adds r3, 0x2
	ldrh r0, [r1]
	strh r0, [r3]
	adds r1, 0x2
	adds r3, 0x2
	ldrh r0, [r2]
	strh r0, [r3]
	adds r2, 0x2
	adds r3, 0x2
	ldrh r0, [r1]
	strh r0, [r3]
	adds r1, 0x2
	adds r3, 0x2
	ldrh r0, [r2]
	strh r0, [r3]
	adds r2, 0x2
	adds r3, 0x2
	ldrh r0, [r1]
	strh r0, [r3]
	adds r1, 0x2
	adds r3, 0x2
	ldrh r0, [r2]
	strh r0, [r3]
	adds r2, 0x2
	adds r3, 0x2
	ldrh r0, [r1]
	strh r0, [r3]
	adds r1, 0x2
	adds r3, 0x2
	ldrh r0, [r2]
	strh r0, [r3]
	adds r2, 0x2
	adds r3, 0x2
	ldrh r0, [r1]
	strh r0, [r3]
	adds r1, 0x2
	adds r3, 0x2
	ldrh r0, [r2]
	strh r0, [r3]
	adds r2, 0x2
	adds r3, 0x2
	ldrh r0, [r1]
	strh r0, [r3]
	adds r1, 0x2
	adds r3, 0x2
	ldrh r0, [r2]
	strh r0, [r3]
	adds r2, 0x2
	adds r3, 0x2
	ldrh r0, [r1]
	strh r0, [r3]
	adds r1, 0x2
	adds r3, 0x2
	ldrh r0, [r2]
	strh r0, [r3]
	adds r2, 0x2
	adds r3, 0x2
	ldrh r0, [r1]
	strh r0, [r3]
	adds r1, 0x2
	adds r3, 0x2
	ldrh r0, [r2]
	strh r0, [r3]
	adds r2, 0x2
	adds r3, 0x2
	ldrh r0, [r1]
	strh r0, [r3]
	adds r1, 0x2
	adds r3, 0x2
	ldrh r0, [r2]
	strh r0, [r3]
	adds r2, 0x2
	adds r3, 0x2
	ldrh r0, [r1]
	strh r0, [r3]
	adds r1, 0x2
	adds r3, 0x2
	ldrh r0, [r2]
	strh r0, [r3]
	adds r2, 0x2
	adds r3, 0x2
	ldrh r0, [r1]
	strh r0, [r3]
	adds r1, 0x2
	adds r3, 0x2
	ldrh r0, [r2]
	strh r0, [r3]
	adds r2, 0x2
	adds r3, 0x2
	ldrh r0, [r1]
	strh r0, [r3]
	adds r1, 0x2
	adds r3, 0x2
	ldrh r0, [r2]
	strh r0, [r3]
	adds r2, 0x2
	adds r3, 0x2
	ldrh r0, [r1]
	strh r0, [r3]
	adds r1, 0x2
	adds r3, 0x2
	subs r7, 0x1
	cmp r7, 0
	blt _08005A90
	b _08005988
_08005A90:
	b _08006094
	.align 2, 0
_08005A94: .4byte gUnknown_80B816A
_08005A98:
	ldr r1, _08005BA8
	movs r7, 0x9
_08005A9C:
	ldrh r0, [r2]
	strh r0, [r3]
	adds r2, 0x2
	adds r3, 0x2
	ldrh r0, [r1]
	strh r0, [r3]
	adds r1, 0x2
	adds r3, 0x2
	ldrh r0, [r2]
	strh r0, [r3]
	adds r2, 0x2
	adds r3, 0x2
	ldrh r0, [r1]
	strh r0, [r3]
	adds r1, 0x2
	adds r3, 0x2
	ldrh r0, [r2]
	strh r0, [r3]
	adds r2, 0x2
	adds r3, 0x2
	ldrh r0, [r1]
	strh r0, [r3]
	adds r1, 0x2
	adds r3, 0x2
	ldrh r0, [r2]
	strh r0, [r3]
	adds r2, 0x2
	adds r3, 0x2
	ldrh r0, [r1]
	strh r0, [r3]
	adds r1, 0x2
	adds r3, 0x2
	ldrh r0, [r2]
	strh r0, [r3]
	adds r2, 0x2
	adds r3, 0x2
	ldrh r0, [r1]
	strh r0, [r3]
	adds r1, 0x2
	adds r3, 0x2
	ldrh r0, [r2]
	strh r0, [r3]
	adds r2, 0x2
	adds r3, 0x2
	ldrh r0, [r1]
	strh r0, [r3]
	adds r1, 0x2
	adds r3, 0x2
	ldrh r0, [r2]
	strh r0, [r3]
	adds r2, 0x2
	adds r3, 0x2
	ldrh r0, [r1]
	strh r0, [r3]
	adds r1, 0x2
	adds r3, 0x2
	ldrh r0, [r2]
	strh r0, [r3]
	adds r2, 0x2
	adds r3, 0x2
	ldrh r0, [r1]
	strh r0, [r3]
	adds r1, 0x2
	adds r3, 0x2
	ldrh r0, [r2]
	strh r0, [r3]
	adds r2, 0x2
	adds r3, 0x2
	ldrh r0, [r1]
	strh r0, [r3]
	adds r1, 0x2
	adds r3, 0x2
	ldrh r0, [r2]
	strh r0, [r3]
	adds r2, 0x2
	adds r3, 0x2
	ldrh r0, [r1]
	strh r0, [r3]
	adds r1, 0x2
	adds r3, 0x2
	ldrh r0, [r2]
	strh r0, [r3]
	adds r2, 0x2
	adds r3, 0x2
	ldrh r0, [r1]
	strh r0, [r3]
	adds r1, 0x2
	adds r3, 0x2
	ldrh r0, [r2]
	strh r0, [r3]
	adds r2, 0x2
	adds r3, 0x2
	ldrh r0, [r1]
	strh r0, [r3]
	adds r1, 0x2
	adds r3, 0x2
	ldrh r0, [r2]
	strh r0, [r3]
	adds r2, 0x2
	adds r3, 0x2
	ldrh r0, [r1]
	strh r0, [r3]
	adds r1, 0x2
	adds r3, 0x2
	ldrh r0, [r2]
	strh r0, [r3]
	adds r2, 0x2
	adds r3, 0x2
	ldrh r0, [r1]
	strh r0, [r3]
	adds r1, 0x2
	adds r3, 0x2
	ldrh r0, [r2]
	strh r0, [r3]
	adds r2, 0x2
	adds r3, 0x2
	ldrh r0, [r1]
	strh r0, [r3]
	adds r1, 0x2
	adds r3, 0x2
	ldrh r0, [r2]
	strh r0, [r3]
	adds r2, 0x2
	adds r3, 0x2
	ldrh r0, [r1]
	strh r0, [r3]
	adds r1, 0x2
	adds r3, 0x2
	subs r7, 0x1
	cmp r7, 0
	blt _08005BA4
	b _08005A9C
_08005BA4:
	b _08006094
	.align 2, 0
_08005BA8: .4byte gUnknown_80B802A
_08005BAC:
	ldr r0, [r5]
	mov r10, r0
	cmp r0, 0
	bge _08005BBA
	ldr r0, [r5, 0x8]
	cmp r0, 0
	blt _08005BDC
_08005BBA:
	ldr r1, [r5, 0x4]
	cmp r1, 0
	bge _08005BC6
	ldr r0, [r5, 0xC]
	cmp r0, 0
	blt _08005BDC
_08005BC6:
	mov r4, r10
	cmp r4, 0xEF
	ble _08005BD2
	ldr r0, [r5, 0x8]
	cmp r0, 0xEF
	bgt _08005BDC
_08005BD2:
	cmp r1, 0x9F
	ble _08005CA8
	ldr r0, [r5, 0xC]
	cmp r0, 0x9F
	ble _08005CA8
_08005BDC:
	movs r1, 0xF0
	movs r7, 0x9
_08005BE0:
	ldrh r0, [r2]
	strh r0, [r3]
	adds r2, 0x2
	adds r3, 0x2
	strh r1, [r3]
	adds r3, 0x2
	ldrh r0, [r2]
	strh r0, [r3]
	adds r2, 0x2
	adds r3, 0x2
	strh r1, [r3]
	adds r3, 0x2
	ldrh r0, [r2]
	strh r0, [r3]
	adds r2, 0x2
	adds r3, 0x2
	strh r1, [r3]
	adds r3, 0x2
	ldrh r0, [r2]
	strh r0, [r3]
	adds r2, 0x2
	adds r3, 0x2
	strh r1, [r3]
	adds r3, 0x2
	ldrh r0, [r2]
	strh r0, [r3]
	adds r2, 0x2
	adds r3, 0x2
	strh r1, [r3]
	adds r3, 0x2
	ldrh r0, [r2]
	strh r0, [r3]
	adds r2, 0x2
	adds r3, 0x2
	strh r1, [r3]
	adds r3, 0x2
	ldrh r0, [r2]
	strh r0, [r3]
	adds r2, 0x2
	adds r3, 0x2
	strh r1, [r3]
	adds r3, 0x2
	ldrh r0, [r2]
	strh r0, [r3]
	adds r2, 0x2
	adds r3, 0x2
	strh r1, [r3]
	adds r3, 0x2
	ldrh r0, [r2]
	strh r0, [r3]
	adds r2, 0x2
	adds r3, 0x2
	strh r1, [r3]
	adds r3, 0x2
	ldrh r0, [r2]
	strh r0, [r3]
	adds r2, 0x2
	adds r3, 0x2
	strh r1, [r3]
	adds r3, 0x2
	ldrh r0, [r2]
	strh r0, [r3]
	adds r2, 0x2
	adds r3, 0x2
	strh r1, [r3]
	adds r3, 0x2
	ldrh r0, [r2]
	strh r0, [r3]
	adds r2, 0x2
	adds r3, 0x2
	strh r1, [r3]
	adds r3, 0x2
	ldrh r0, [r2]
	strh r0, [r3]
	adds r2, 0x2
	adds r3, 0x2
	strh r1, [r3]
	adds r3, 0x2
	ldrh r0, [r2]
	strh r0, [r3]
	adds r2, 0x2
	adds r3, 0x2
	strh r1, [r3]
	adds r3, 0x2
	ldrh r0, [r2]
	strh r0, [r3]
	adds r2, 0x2
	adds r3, 0x2
	strh r1, [r3]
	adds r3, 0x2
	ldrh r0, [r2]
	strh r0, [r3]
	adds r2, 0x2
	adds r3, 0x2
	strh r1, [r3]
	adds r3, 0x2
	subs r7, 0x1
	cmp r7, 0
	bge _08005BE0
	b _08006094
_08005CA8:
	movs r7, 0
	mov r8, r1
	movs r6, 0x80
	lsls r6, 1
	mov r12, r6
	lsls r0, r1, 1
	ldr r1, _08005CCC
	subs r6, r1, r0
	mov r9, r10
_08005CBA:
	cmp r8, r7
	ble _08005CD0
	ldrh r0, [r2]
	strh r0, [r3]
	adds r2, 0x2
	adds r3, 0x2
	mov r4, r12
	strh r4, [r3]
	b _08005D3A
	.align 2, 0
_08005CCC: .4byte gUnknown_80B8008
_08005CD0:
	ldr r1, [r5, 0xC]
	cmp r1, r7
	bgt _08005CE2
	ldrh r0, [r2]
	strh r0, [r3]
	adds r2, 0x2
	adds r3, 0x2
	mov r0, r12
	b _08005D38
_08005CE2:
	mov r4, r8
	subs r0, r7, r4
	cmp r0, 0xF
	bgt _08005CF0
	movs r0, 0
	ldrsh r1, [r6, r0]
	b _08005D00
_08005CF0:
	subs r0, r1, r7
	cmp r0, 0xF
	bgt _08005D10
	lsls r0, 1
	ldr r1, _08005D0C
	adds r0, r1
	movs r4, 0
	ldrsh r1, [r0, r4]
_08005D00:
	mov r0, r9
	adds r4, r0, r1
	ldr r0, [r5, 0x8]
	subs r1, r0, r1
	b _08005D14
	.align 2, 0
_08005D0C: .4byte gUnknown_80B8008
_08005D10:
	mov r4, r10
	ldr r1, [r5, 0x8]
_08005D14:
	cmp r4, 0
	bge _08005D1A
	movs r4, 0
_08005D1A:
	cmp r4, 0xEF
	ble _08005D20
	movs r4, 0xEF
_08005D20:
	cmp r1, 0
	bgt _08005D26
	movs r1, 0x1
_08005D26:
	cmp r1, 0xF0
	ble _08005D2C
	movs r1, 0xF0
_08005D2C:
	ldrh r0, [r2]
	strh r0, [r3]
	adds r2, 0x2
	adds r3, 0x2
	lsls r0, r1, 8
	orrs r0, r4
_08005D38:
	strh r0, [r3]
_08005D3A:
	adds r3, 0x2
	adds r6, 0x2
	adds r7, 0x1
	cmp r7, 0x9F
	ble _08005CBA
	b _08006094
_08005D46:
	ldr r1, _08005E54
	movs r7, 0xE
_08005D4A:
	ldrh r0, [r2]
	strh r0, [r3]
	adds r2, 0x2
	adds r3, 0x2
	ldrh r0, [r1]
	strh r0, [r3]
	adds r1, 0x2
	adds r3, 0x2
	ldrh r0, [r2]
	strh r0, [r3]
	adds r2, 0x2
	adds r3, 0x2
	ldrh r0, [r1]
	strh r0, [r3]
	adds r1, 0x2
	adds r3, 0x2
	ldrh r0, [r2]
	strh r0, [r3]
	adds r2, 0x2
	adds r3, 0x2
	ldrh r0, [r1]
	strh r0, [r3]
	adds r1, 0x2
	adds r3, 0x2
	ldrh r0, [r2]
	strh r0, [r3]
	adds r2, 0x2
	adds r3, 0x2
	ldrh r0, [r1]
	strh r0, [r3]
	adds r1, 0x2
	adds r3, 0x2
	ldrh r0, [r2]
	strh r0, [r3]
	adds r2, 0x2
	adds r3, 0x2
	ldrh r0, [r1]
	strh r0, [r3]
	adds r1, 0x2
	adds r3, 0x2
	ldrh r0, [r2]
	strh r0, [r3]
	adds r2, 0x2
	adds r3, 0x2
	ldrh r0, [r1]
	strh r0, [r3]
	adds r1, 0x2
	adds r3, 0x2
	ldrh r0, [r2]
	strh r0, [r3]
	adds r2, 0x2
	adds r3, 0x2
	ldrh r0, [r1]
	strh r0, [r3]
	adds r1, 0x2
	adds r3, 0x2
	ldrh r0, [r2]
	strh r0, [r3]
	adds r2, 0x2
	adds r3, 0x2
	ldrh r0, [r1]
	strh r0, [r3]
	adds r1, 0x2
	adds r3, 0x2
	ldrh r0, [r2]
	strh r0, [r3]
	adds r2, 0x2
	adds r3, 0x2
	ldrh r0, [r1]
	strh r0, [r3]
	adds r1, 0x2
	adds r3, 0x2
	ldrh r0, [r2]
	strh r0, [r3]
	adds r2, 0x2
	adds r3, 0x2
	ldrh r0, [r1]
	strh r0, [r3]
	adds r1, 0x2
	adds r3, 0x2
	ldrh r0, [r2]
	strh r0, [r3]
	adds r2, 0x2
	adds r3, 0x2
	ldrh r0, [r1]
	strh r0, [r3]
	adds r1, 0x2
	adds r3, 0x2
	ldrh r0, [r2]
	strh r0, [r3]
	adds r2, 0x2
	adds r3, 0x2
	ldrh r0, [r1]
	strh r0, [r3]
	adds r1, 0x2
	adds r3, 0x2
	ldrh r0, [r2]
	strh r0, [r3]
	adds r2, 0x2
	adds r3, 0x2
	ldrh r0, [r1]
	strh r0, [r3]
	adds r1, 0x2
	adds r3, 0x2
	ldrh r0, [r2]
	strh r0, [r3]
	adds r2, 0x2
	adds r3, 0x2
	ldrh r0, [r1]
	strh r0, [r3]
	adds r1, 0x2
	adds r3, 0x2
	ldrh r0, [r2]
	strh r0, [r3]
	adds r2, 0x2
	adds r3, 0x2
	ldrh r0, [r1]
	strh r0, [r3]
	adds r1, 0x2
	adds r3, 0x2
	ldrh r0, [r2]
	strh r0, [r3]
	adds r2, 0x2
	adds r3, 0x2
	ldrh r0, [r1]
	strh r0, [r3]
	adds r1, 0x2
	adds r3, 0x2
	subs r7, 0x1
	cmp r7, 0
	blt _08005E52
	b _08005D4A
_08005E52:
	b _08006094
	.align 2, 0
_08005E54: .4byte gUnknown_80B82AA
_08005E58:
	ldr r4, _08005FF4
	ldr r5, _08005FF8
	ldr r6, _08005FFC
	movs r0, 0x80
	lsls r0, 1
	adds r1, r0, 0
	movs r7, 0xE
_08005E66:
	ldrh r0, [r2]
	strh r0, [r3]
	adds r2, 0x2
	adds r3, 0x2
	strh r1, [r3]
	adds r3, 0x2
	ldrh r0, [r2]
	strh r0, [r3]
	adds r2, 0x2
	adds r3, 0x2
	strh r1, [r3]
	adds r3, 0x2
	ldrh r0, [r2]
	strh r0, [r3]
	adds r2, 0x2
	adds r3, 0x2
	strh r1, [r3]
	adds r3, 0x2
	ldrh r0, [r2]
	strh r0, [r3]
	adds r2, 0x2
	adds r3, 0x2
	strh r1, [r3]
	adds r3, 0x2
	ldrh r0, [r2]
	strh r0, [r3]
	adds r2, 0x2
	adds r3, 0x2
	strh r1, [r3]
	adds r3, 0x2
	ldrh r0, [r2]
	strh r0, [r3]
	adds r2, 0x2
	adds r3, 0x2
	strh r1, [r3]
	adds r3, 0x2
	ldrh r0, [r2]
	strh r0, [r3]
	adds r2, 0x2
	adds r3, 0x2
	strh r1, [r3]
	adds r3, 0x2
	ldrh r0, [r2]
	strh r0, [r3]
	adds r2, 0x2
	adds r3, 0x2
	strh r1, [r3]
	adds r3, 0x2
	ldrh r0, [r2]
	strh r0, [r3]
	adds r2, 0x2
	adds r3, 0x2
	strh r1, [r3]
	adds r3, 0x2
	ldrh r0, [r2]
	strh r0, [r3]
	adds r2, 0x2
	adds r3, 0x2
	strh r1, [r3]
	adds r3, 0x2
	ldrh r0, [r2]
	strh r0, [r3]
	adds r2, 0x2
	adds r3, 0x2
	strh r1, [r3]
	adds r3, 0x2
	ldrh r0, [r2]
	strh r0, [r3]
	adds r2, 0x2
	adds r3, 0x2
	strh r1, [r3]
	adds r3, 0x2
	ldrh r0, [r2]
	strh r0, [r3]
	adds r2, 0x2
	adds r3, 0x2
	strh r1, [r3]
	adds r3, 0x2
	ldrh r0, [r2]
	strh r0, [r3]
	adds r2, 0x2
	adds r3, 0x2
	strh r1, [r3]
	adds r3, 0x2
	ldrh r0, [r2]
	strh r0, [r3]
	adds r2, 0x2
	adds r3, 0x2
	strh r1, [r3]
	adds r3, 0x2
	ldrh r0, [r2]
	strh r0, [r3]
	adds r2, 0x2
	adds r3, 0x2
	strh r1, [r3]
	adds r3, 0x2
	subs r7, 0x1
	cmp r7, 0
	bge _08005E66
	ldr r4, [r4]
	str r4, [sp]
	ldr r5, [r5]
	str r5, [sp, 0x4]
	ldr r6, [r6]
	str r6, [sp, 0x8]
	adds r1, r6, 0
	cmp r6, 0
	bge _08005F40
	adds r1, 0xFF
_08005F40:
	asrs r1, 8
	adds r1, 0x1
	movs r0, 0x80
	lsls r0, 3
	bl __divsi3
	str r0, [sp, 0xC]
	ldr r0, [sp, 0x4]
	cmp r0, 0
	bge _08005F56
	adds r0, 0xFF
_08005F56:
	asrs r4, r0, 8
	adds r5, r4, 0
	movs r3, 0
	lsls r0, r4, 2
	adds r7, r0, 0x2
	mov r9, r7
_08005F62:
	adds r0, r3, 0
	str r3, [sp, 0x10]
	bl sub_8009C7C
	ldr r1, [sp, 0x8]
	muls r0, r1
	ldr r3, [sp, 0x10]
	cmp r0, 0
	bge _08005F76
	adds r0, 0xFF
_08005F76:
	asrs r0, 8
	ldr r2, [sp, 0x4]
	adds r1, r2, r0
	cmp r1, 0
	bge _08005F82
	adds r1, 0xFF
_08005F82:
	asrs r1, 8
	str r1, [sp, 0x14]
	ldr r6, [sp, 0x4]
	subs r0, r6, r0
	cmp r0, 0
	bge _08005F90
	adds r0, 0xFF
_08005F90:
	asrs r0, 8
	mov r8, r0
	ldr r0, [sp, 0x14]
	cmp r5, r0
	blt _08005FA4
	ldr r1, [sp, 0xC]
	adds r1, r3
	mov r10, r1
	cmp r4, r8
	ble _0800608A
_08005FA4:
	adds r0, r3, 0
	str r3, [sp, 0x10]
	bl sub_8009D04
	ldr r2, [sp, 0x8]
	muls r0, r2
	ldr r3, [sp, 0x10]
	cmp r0, 0
	bge _08005FB8
	adds r0, 0xFF
_08005FB8:
	asrs r0, 8
	ldr r6, [sp]
	subs r1, r6, r0
	cmp r1, 0
	bge _08005FC4
	adds r1, 0xFF
_08005FC4:
	asrs r1, 8
	ldr r2, [sp]
	adds r0, r2, r0
	cmp r0, 0
	bge _08005FD0
	adds r0, 0xFF
_08005FD0:
	asrs r0, 8
	cmp r1, 0
	bge _08005FD8
	movs r1, 0
_08005FD8:
	cmp r0, 0
	bge _08005FDE
	movs r0, 0
_08005FDE:
	cmp r1, 0xEF
	ble _08005FE4
	movs r1, 0x9F
_08005FE4:
	cmp r0, 0xEF
	ble _08005FEA
	movs r0, 0x9F
_08005FEA:
	cmp r1, r0
	ble _08006000
	lsls r2, r1, 8
	orrs r2, r0
	b _08006004
	.align 2, 0
_08005FF4: .4byte gUnknown_2026E40
_08005FF8: .4byte gUnknown_2026E44
_08005FFC: .4byte gUnknown_2026E48
_08006000:
	lsls r2, r0, 8
	orrs r2, r1
_08006004:
	ldr r6, [sp, 0xC]
	adds r3, r6
	mov r10, r3
	ldr r0, [sp, 0x14]
	cmp r5, r0
	bge _0800604E
	ldr r1, _08006030
	mov r12, r1
	ldr r3, _08006034
	add r3, r9
	ldr r1, _08006038
	add r1, r9
_0800601C:
	cmp r5, 0
	blt _0800603E
	cmp r5, 0x9F
	bgt _0800603E
	mov r6, r12
	ldr r0, [r6]
	cmp r0, 0
	bne _0800603C
	strh r2, [r1]
	b _0800603E
	.align 2, 0
_08006030: .4byte gUnknown_2026E54
_08006034: .4byte gUnknown_20270E8
_08006038: .4byte gUnknown_2026E60
_0800603C:
	strh r2, [r3]
_0800603E:
	adds r3, 0x4
	adds r1, 0x4
	movs r0, 0x4
	add r9, r0
	adds r5, 0x1
	ldr r6, [sp, 0x14]
	cmp r5, r6
	blt _0800601C
_0800604E:
	cmp r4, r8
	ble _0800608A
	ldr r6, _08006070
	ldr r0, _08006074
	adds r3, r7, r0
	ldr r0, _08006078
	adds r1, r7, r0
_0800605C:
	cmp r4, 0
	blt _0800607E
	cmp r4, 0x9F
	bgt _0800607E
	ldr r0, [r6]
	cmp r0, 0
	bne _0800607C
	strh r2, [r1]
	b _0800607E
	.align 2, 0
_08006070: .4byte gUnknown_2026E54
_08006074: .4byte gUnknown_20270E8
_08006078: .4byte gUnknown_2026E60
_0800607C:
	strh r2, [r3]
_0800607E:
	subs r3, 0x4
	subs r1, 0x4
	subs r7, 0x4
	subs r4, 0x1
	cmp r4, r8
	bgt _0800605C
_0800608A:
	mov r3, r10
	ldr r0, _080060A4
	cmp r3, r0
	bgt _08006094
	b _08005F62
_08006094:
	add sp, 0x18
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_080060A4: .4byte 0x000003ff
	thumb_func_end sub_8005838

	thumb_func_start sub_80060A8
sub_80060A8:
	push {lr}
	ldr r1, _080060D8
	ldr r0, _080060DC
	ldr r0, [r0]
	str r0, [r1]
	ldr r2, _080060E0
	movs r1, 0
	ldr r0, [r2]
	cmp r0, 0
	bne _080060BE
	movs r1, 0x1
_080060BE:
	str r1, [r2]
	ldr r2, _080060E4
	movs r1, 0
	ldr r0, [r2]
	cmp r0, 0
	bne _080060CC
	movs r1, 0x1
_080060CC:
	str r1, [r2]
	ldr r1, _080060E8
	movs r0, 0
	strb r0, [r1]
	pop {r0}
	bx r0
	.align 2, 0
_080060D8: .4byte gUnknown_2026E3C
_080060DC: .4byte gUnknown_2026E58
_080060E0: .4byte gUnknown_2026E54
_080060E4: .4byte gUnknown_2026E50
_080060E8: .4byte gUnknown_2026E38
	thumb_func_end sub_80060A8

	thumb_func_start sub_80060EC
sub_80060EC:
	push {lr}
	ldr r1, _08006130
	ldr r0, _08006134
	ldr r0, [r0]
	str r0, [r1]
	ldr r2, _08006138
	movs r1, 0
	ldr r0, [r2]
	cmp r0, 0
	bne _08006102
	movs r1, 0x1
_08006102:
	str r1, [r2]
	ldr r2, _0800613C
	movs r1, 0
	ldr r0, [r2]
	cmp r0, 0
	bne _08006110
	movs r1, 0x1
_08006110:
	str r1, [r2]
	ldr r0, _08006140
	ldrh r2, [r0]
	movs r0, 0xF8
	lsls r0, 5
	ands r0, r2
	lsrs r0, 8
	movs r1, 0x1F
	ands r1, r2
	bl sub_800CC44
	ldr r1, _08006144
	movs r0, 0x1
	strb r0, [r1]
	pop {r0}
	bx r0
	.align 2, 0
_08006130: .4byte gUnknown_2026E3C
_08006134: .4byte gUnknown_2026E58
_08006138: .4byte gUnknown_2026E54
_0800613C: .4byte gUnknown_2026E50
_08006140: .4byte gUnknown_2026E4E
_08006144: .4byte gUnknown_2026E38
	thumb_func_end sub_80060EC

	.align 2, 0 @ Don't pad with nop.
