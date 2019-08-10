	.include "constants/gba_constants.inc"
	.include "asm/macros.inc"

	.syntax unified

	.text

	thumb_func_start nullsub_152
nullsub_152:
	bx lr
	thumb_func_end nullsub_152

	thumb_func_start sub_8006518
sub_8006518:
	push {r4-r7,lr}
	ldr r4, _0800653C
	adds r2, r0, 0
	movs r3, 0x3
_08006520:
	adds r1, r2, 0
	adds r0, r4, 0
	ldm r0!, {r5-r7}
	stm r1!, {r5-r7}
	ldm r0!, {r5-r7}
	stm r1!, {r5-r7}
	adds r4, 0x18
	adds r2, 0x18
	subs r3, 0x1
	cmp r3, 0
	bge _08006520
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_0800653C: .4byte gUnknown_202AFC0
	thumb_func_end sub_8006518

	thumb_func_start nullsub_153
nullsub_153:
	bx lr
	thumb_func_end nullsub_153

	thumb_func_start sub_8006544
sub_8006544:
	ldr r1, _08006550
	lsls r0, 2
	adds r0, r1
	ldr r0, [r0]
	bx lr
	.align 2, 0
_08006550: .4byte gUnknown_80B8814
	thumb_func_end sub_8006544

	thumb_func_start sub_8006554
sub_8006554:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x24
	str r0, [sp, 0x4]
	adds r7, r1, 0
	adds r6, r2, 0
	str r3, [sp, 0x8]
	ldr r1, [sp, 0x4C]
	ldr r3, [sp, 0x50]
	ldr r2, [sp, 0x54]
	ldr r0, [sp, 0x58]
	lsls r1, 24
	lsrs r1, 24
	str r1, [sp, 0xC]
	lsls r0, 24
	lsrs r0, 24
	str r0, [sp, 0x10]
	ldr r1, [sp, 0x44]
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 3
	ldr r4, [sp, 0x4]
	adds r5, r4, r0
	ldr r0, [sp, 0x48]
	movs r4, 0x8
	ldrsh r1, [r0, r4]
	movs r4, 0
	ldrsh r0, [r2, r4]
	adds r1, r0
	str r1, [sp, 0x14]
	ldr r0, [sp, 0x48]
	movs r4, 0xA
	ldrsh r1, [r0, r4]
	movs r4, 0x2
	ldrsh r0, [r2, r4]
	adds r4, r1, r0
	mov r0, sp
	ldrh r0, [r0, 0x14]
	strh r0, [r5]
	strh r4, [r5, 0x2]
	ldr r1, [sp, 0x48]
	ldrh r0, [r1, 0xC]
	strh r0, [r5, 0x4]
	ldrh r0, [r1, 0x10]
	strh r0, [r5, 0x8]
	ldrh r0, [r1, 0xE]
	strh r0, [r5, 0x6]
	ldr r0, [r1, 0x4]
	str r0, [r5, 0xC]
	str r3, [r5, 0x10]
	cmp r0, 0x6
	bne _080065C6
	str r3, [r5, 0x14]
	b _080065D6
_080065C6:
	ldr r2, [sp, 0x48]
	movs r0, 0x12
	ldrsh r1, [r2, r0]
	movs r2, 0x4
	ldrsh r0, [r5, r2]
	muls r0, r1
	adds r0, r3, r0
	str r0, [r5, 0x14]
_080065D6:
	ldr r0, [r5, 0x10]
	lsls r0, 5
	adds r0, r6, r0
	str r0, [r5, 0x18]
	ldr r0, [r5, 0x14]
	lsls r0, 5
	adds r1, r6, r0
	str r1, [r5, 0x1C]
	ldr r3, [sp, 0x48]
	movs r6, 0x12
	ldrsh r1, [r3, r6]
	str r1, [r5, 0x24]
	adds r0, r7, r0
	str r0, [r5, 0x28]
	ldr r3, [r5, 0xC]
	cmp r3, 0x6
	bne _0800660C
	movs r7, 0x4
	ldrsh r2, [r5, r7]
	movs r1, 0x6
	ldrsh r0, [r5, r1]
	ldr r6, [sp, 0x48]
	movs r7, 0x12
	ldrsh r1, [r6, r7]
	adds r0, r1
	muls r0, r2
	b _08006616
_0800660C:
	movs r0, 0x4
	ldrsh r1, [r5, r0]
	movs r2, 0x6
	ldrsh r0, [r5, r2]
	muls r0, r1
_08006616:
	lsls r0, 5
	str r0, [r5, 0x2C]
	movs r0, 0
	str r0, [r5, 0x30]
	str r0, [r5, 0x34]
	str r0, [r5, 0x38]
	movs r6, 0x4
	ldrsh r0, [r5, r6]
	lsls r0, 3
	subs r0, 0x8
	str r0, [r5, 0x20]
	movs r1, 0
	cmp r3, 0
	bne _08006634
	movs r1, 0x1
_08006634:
	adds r0, r5, 0
	adds r0, 0x45
	strb r1, [r0]
	movs r7, 0x8
	ldrsh r0, [r5, r7]
	cmp r0, 0
	bne _08006644
	b _0800676C
_08006644:
	ldr r0, [sp, 0x48]
	ldrb r1, [r0]
	movs r0, 0xA0
	ands r0, r1
	adds r1, r5, 0
	adds r1, 0x46
	str r1, [sp, 0x1C]
	cmp r0, 0x80
	beq _08006752
	subs r7, r4, 0x1
	ldr r0, [r5, 0xC]
	cmp r0, 0x6
	bne _080066A8
	movs r2, 0
	mov r8, r2
	ldr r3, [sp, 0xC]
	cmp r3, 0
	beq _0800666C
	ldr r6, [r5, 0x14]
	mov r8, r6
_0800666C:
	ldr r0, [sp, 0x48]
	ldr r3, [r0, 0x14]
	ldr r1, [sp, 0x8]
	str r1, [sp]
	adds r0, r5, 0
	adds r1, r7, 0
	mov r2, r8
	bl sub_8006E94
	adds r7, r4, 0x2
	ldr r2, [sp, 0xC]
	cmp r2, 0
	beq _0800669A
	movs r3, 0x4
	ldrsh r1, [r5, r3]
	ldr r4, [sp, 0x48]
	movs r6, 0x12
	ldrsh r0, [r4, r6]
	adds r0, 0x2
	muls r1, r0
	ldr r0, [r5, 0x14]
	adds r0, r1
	b _0800669C
_0800669A:
	movs r0, 0
_0800669C:
	mov r8, r0
	movs r1, 0x6
	ldrsh r0, [r5, r1]
	subs r0, 0x2
	str r0, [sp, 0x18]
	b _080066CA
_080066A8:
	adds r0, r5, 0
	adds r1, r7, 0
	ldr r2, [sp, 0x8]
	ldr r3, [sp, 0x10]
	bl sub_800677C
	adds r7, r4, 0
	movs r2, 0
	mov r8, r2
	ldr r3, [sp, 0xC]
	cmp r3, 0
	beq _080066C4
	ldr r4, [r5, 0x14]
	mov r8, r4
_080066C4:
	movs r0, 0x6
	ldrsh r6, [r5, r0]
	str r6, [sp, 0x18]
_080066CA:
	movs r1, 0
	mov r9, r1
	adds r2, r5, 0
	adds r2, 0x46
	str r2, [sp, 0x1C]
	ldr r3, [sp, 0x18]
	cmp r9, r3
	bge _08006746
_080066DA:
	ldr r4, [sp, 0x14]
	subs r4, 0x1
	ldr r6, [sp, 0x8]
	str r6, [sp]
	adds r0, r5, 0
	adds r1, r4, 0
	adds r2, r7, 0
	mov r3, r9
	bl sub_80069CC
	ldr r4, [sp, 0x14]
	movs r6, 0
	movs r1, 0x4
	ldrsh r0, [r5, r1]
	adds r2, r7, 0x1
	mov r10, r2
	mov r3, r9
	adds r3, 0x1
	str r3, [sp, 0x20]
	cmp r6, r0
	bge _0800672A
_08006704:
	ldr r0, [sp, 0x8]
	str r0, [sp]
	adds r0, r5, 0
	adds r1, r4, 0
	adds r2, r7, 0
	mov r3, r8
	bl sub_8006AC4
	adds r4, 0x1
	ldr r1, [sp, 0xC]
	cmp r1, 0
	beq _08006720
	movs r2, 0x1
	add r8, r2
_08006720:
	adds r6, 0x1
	movs r3, 0x4
	ldrsh r0, [r5, r3]
	cmp r6, r0
	blt _08006704
_0800672A:
	ldr r6, [sp, 0x8]
	str r6, [sp]
	adds r0, r5, 0
	adds r1, r4, 0
	adds r2, r7, 0
	mov r3, r9
	bl sub_8006B70
	mov r7, r10
	ldr r0, [sp, 0x20]
	mov r9, r0
	ldr r1, [sp, 0x18]
	cmp r9, r1
	blt _080066DA
_08006746:
	adds r0, r5, 0
	adds r1, r7, 0
	ldr r2, [sp, 0x8]
	ldr r3, [sp, 0x10]
	bl sub_8006C44
_08006752:
	ldr r2, [sp, 0x48]
	ldrb r1, [r2]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	bne _08006766
	ldr r0, [sp, 0x4]
	ldr r1, [sp, 0x44]
	bl sub_8008C6C
_08006766:
	movs r0, 0
	ldr r3, [sp, 0x1C]
	strb r0, [r3]
_0800676C:
	add sp, 0x24
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_8006554

	thumb_func_start sub_800677C
sub_800677C:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x4
	adds r6, r0, 0
	adds r4, r1, 0
	str r2, [sp]
	lsls r3, 24
	lsrs r3, 24
	mov r9, r3
	movs r1, 0
	ldrsh r0, [r6, r1]
	subs r3, r0, 0x1
	cmp r4, 0x1C
	ble _080067A0
	b _080069AE
_080067A0:
	cmp r4, 0
	bge _080067A6
	b _080069AE
_080067A6:
	ldr r0, [r6, 0xC]
	cmp r0, 0x7
	bls _080067AE
	b _080069AE
_080067AE:
	lsls r0, 2
	ldr r1, _080067B8
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080067B8: .4byte _080067BC
	.align 2, 0
_080067BC:
	.4byte _080069AE
	.4byte _080069AE
	.4byte _080069AE
	.4byte _080067DC
	.4byte _0800689C
	.4byte _08006920
	.4byte _080069AE
	.4byte _0800696C
_080067DC:
	lsls r1, r3, 1
	lsls r2, r4, 6
	ldr r4, [sp]
	adds r0, r2, r4
	adds r1, r0
	ldr r7, _08006800
	adds r0, r7, 0
	strh r0, [r1]
	adds r5, r2, 0
	mov r0, r9
	cmp r0, 0
	beq _08006808
	movs r2, 0x80
	lsls r2, 4
	adds r1, r2
	ldr r4, _08006804
	adds r0, r4, 0
	b _08006812
	.align 2, 0
_08006800: .4byte 0x0000f2d8
_08006804: .4byte 0x0000f293
_08006808:
	movs r7, 0x80
	lsls r7, 4
	adds r1, r7
	ldr r2, _08006878
	adds r0, r2, 0
_08006812:
	strh r0, [r1]
	adds r3, 0x1
	movs r4, 0
	movs r7, 0x4
	ldrsh r0, [r6, r7]
	cmp r4, r0
	bge _08006856
	ldr r0, _0800687C
	mov r8, r0
	lsls r0, r3, 1
	ldr r2, [sp]
	movs r7, 0x80
	lsls r7, 4
	adds r1, r2, r7
	adds r1, r5, r1
	adds r2, r0, r1
	ldr r7, [sp]
	adds r1, r5, r7
	adds r1, r0, r1
	ldr r0, _08006878
	mov r12, r0
_0800683C:
	mov r7, r8
	strh r7, [r1]
	mov r0, r12
	strh r0, [r2]
	adds r2, 0x2
	adds r1, 0x2
	adds r3, 0x1
	adds r4, 0x1
	movs r0, 0x4
	ldrsh r7, [r6, r0]
	mov r10, r7
	cmp r4, r10
	blt _0800683C
_08006856:
	lsls r0, r3, 1
	ldr r2, [sp]
	adds r1, r5, r2
	adds r1, r0, r1
	ldr r4, _08006880
	adds r0, r4, 0
	strh r0, [r1]
	mov r7, r9
	cmp r7, 0
	beq _08006888
	movs r0, 0x80
	lsls r0, 4
	adds r1, r0
	ldr r2, _08006884
	adds r0, r2, 0
	strh r0, [r1]
	b _080069AE
	.align 2, 0
_08006878: .4byte 0x0000f2db
_0800687C: .4byte 0x0000f2d9
_08006880: .4byte 0x0000f6d8
_08006884: .4byte 0x0000f693
_08006888:
	movs r4, 0x80
	lsls r4, 4
	adds r1, r4
	ldr r7, _08006898
	adds r0, r7, 0
	strh r0, [r1]
	b _080069AE
	.align 2, 0
_08006898: .4byte 0x0000f2db
_0800689C:
	lsls r1, r3, 1
	lsls r2, r4, 6
	ldr r0, [sp]
	adds r0, r2
	mov r12, r0
	add r1, r12
	ldr r4, _08006910
	adds r0, r4, 0
	strh r0, [r1]
	movs r7, 0x80
	lsls r7, 4
	mov r8, r7
	add r1, r8
	ldr r0, _08006914
	mov r9, r0
	strh r0, [r1]
	adds r3, 0x1
	movs r4, 0
	movs r1, 0x4
	ldrsh r0, [r6, r1]
	adds r5, r2, 0
	cmp r4, r0
	bge _080068F6
	ldr r2, _08006918
	mov r10, r2
	lsls r1, r3, 1
	ldr r0, [sp]
	add r0, r8
	adds r0, r5, r0
	adds r2, r1, r0
	add r1, r12
	mov r12, r9
_080068DC:
	mov r7, r10
	strh r7, [r1]
	mov r0, r12
	strh r0, [r2]
	adds r2, 0x2
	adds r1, 0x2
	adds r3, 0x1
	adds r4, 0x1
	movs r0, 0x4
	ldrsh r7, [r6, r0]
	mov r8, r7
	cmp r4, r8
	blt _080068DC
_080068F6:
	lsls r0, r3, 1
	ldr r2, [sp]
	adds r1, r5, r2
	adds r0, r1
	ldr r4, _0800691C
	adds r1, r4, 0
	strh r1, [r0]
	movs r7, 0x80
	lsls r7, 4
	adds r0, r7
	ldr r2, _08006914
	adds r1, r2, 0
	b _080069AC
	.align 2, 0
_08006910: .4byte 0x0000f2e8
_08006914: .4byte 0x0000f2db
_08006918: .4byte 0x0000f2e9
_0800691C: .4byte 0x0000f6e8
_08006920:
	lsls r0, r3, 1
	lsls r2, r4, 6
	ldr r4, [sp]
	adds r4, r2
	mov r12, r4
	add r0, r12
	ldr r7, _08006960
	adds r1, r7, 0
	strh r1, [r0]
	adds r3, 0x1
	movs r1, 0x4
	ldrsh r0, [r6, r1]
	adds r5, r2, 0
	cmp r0, 0
	ble _08006954
	ldr r2, _08006964
	adds r1, r2, 0
	adds r4, r0, 0
	lsls r0, r3, 1
	add r0, r12
_08006948:
	strh r1, [r0]
	adds r0, 0x2
	adds r3, 0x1
	subs r4, 0x1
	cmp r4, 0
	bne _08006948
_08006954:
	lsls r0, r3, 1
	ldr r4, [sp]
	adds r1, r5, r4
	adds r0, r1
	ldr r7, _08006968
	b _080069AA
	.align 2, 0
_08006960: .4byte 0x0000f2dc
_08006964: .4byte 0x0000f2dd
_08006968: .4byte 0x0000f6dc
_0800696C:
	lsls r0, r3, 1
	lsls r2, r4, 6
	ldr r1, [sp]
	adds r1, r2
	mov r12, r1
	add r0, r12
	ldr r4, _080069C0
	adds r1, r4, 0
	strh r1, [r0]
	adds r3, 0x1
	movs r7, 0x4
	ldrsh r0, [r6, r7]
	adds r5, r2, 0
	cmp r0, 0
	ble _080069A0
	ldr r2, _080069C4
	adds r1, r2, 0
	adds r4, r0, 0
	lsls r0, r3, 1
	add r0, r12
_08006994:
	strh r1, [r0]
	adds r0, 0x2
	adds r3, 0x1
	subs r4, 0x1
	cmp r4, 0
	bne _08006994
_080069A0:
	lsls r0, r3, 1
	ldr r4, [sp]
	adds r1, r5, r4
	adds r0, r1
	ldr r7, _080069C8
_080069AA:
	adds r1, r7, 0
_080069AC:
	strh r1, [r0]
_080069AE:
	add sp, 0x4
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_080069C0: .4byte 0x0000f293
_080069C4: .4byte 0x0000f297
_080069C8: .4byte 0x0000f693
	thumb_func_end sub_800677C

	thumb_func_start sub_80069CC
sub_80069CC:
	push {r4-r6,lr}
	adds r6, r0, 0
	adds r4, r1, 0
	adds r5, r3, 0
	ldr r3, [sp, 0x10]
	cmp r2, 0x1C
	bgt _08006ABA
	cmp r2, 0
	blt _08006ABA
	ldr r0, [r6, 0xC]
	cmp r0, 0x7
	bhi _08006ABA
	lsls r0, 2
	ldr r1, _080069F0
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080069F0: .4byte _080069F4
	.align 2, 0
_080069F4:
	.4byte _08006A14
	.4byte _08006ABA
	.4byte _08006ABA
	.4byte _08006A60
	.4byte _08006A7C
	.4byte _08006A9C
	.4byte _08006A60
	.4byte _08006AAC
_08006A14:
	cmp r5, 0
	bne _08006A34
	lsls r1, r4, 1
	lsls r0, r2, 6
	adds r0, r3
	adds r1, r0
	ldr r2, _08006A30
	adds r0, r2, 0
	strh r0, [r1]
	movs r0, 0x80
	lsls r0, 4
	adds r1, r0
	adds r2, 0x44
	b _08006A92
	.align 2, 0
_08006A30: .4byte 0x0000f297
_08006A34:
	movs r1, 0x6
	ldrsh r0, [r6, r1]
	subs r0, 0x1
	cmp r5, r0
	bne _08006A60
	lsls r1, r4, 1
	lsls r0, r2, 6
	adds r0, r3
	adds r1, r0
	ldr r2, _08006A58
	adds r0, r2, 0
	strh r0, [r1]
	movs r0, 0x80
	lsls r0, 4
	adds r1, r0
	ldr r2, _08006A5C
	b _08006A92
	.align 2, 0
_08006A58: .4byte 0x0000fa97
_08006A5C: .4byte 0x0000f2db
_08006A60:
	lsls r1, r4, 1
	lsls r0, r2, 6
	adds r0, r3
	adds r1, r0
	ldr r2, _08006A78
	adds r0, r2, 0
	strh r0, [r1]
	movs r0, 0x80
	lsls r0, 4
	adds r1, r0
	adds r2, 0x1
	b _08006A92
	.align 2, 0
_08006A78: .4byte 0x0000f2da
_08006A7C:
	lsls r1, r4, 1
	lsls r0, r2, 6
	adds r0, r3
	adds r1, r0
	ldr r2, _08006A98
	adds r0, r2, 0
	strh r0, [r1]
	movs r0, 0x80
	lsls r0, 4
	adds r1, r0
	subs r2, 0xF
_08006A92:
	adds r0, r2, 0
	strh r0, [r1]
	b _08006ABA
	.align 2, 0
_08006A98: .4byte 0x0000f2ea
_08006A9C:
	lsls r0, r4, 1
	lsls r1, r2, 6
	adds r1, r3
	adds r0, r1
	ldr r2, _08006AA8
	b _08006AB6
	.align 2, 0
_08006AA8: .4byte 0x0000f2de
_08006AAC:
	lsls r0, r4, 1
	lsls r1, r2, 6
	adds r1, r3
	adds r0, r1
	ldr r2, _08006AC0
_08006AB6:
	adds r1, r2, 0
	strh r1, [r0]
_08006ABA:
	pop {r4-r6}
	pop {r0}
	bx r0
	.align 2, 0
_08006AC0: .4byte 0x0000f2b6
	thumb_func_end sub_80069CC

	thumb_func_start sub_8006AC4
sub_8006AC4:
	push {r4,r5,lr}
	adds r4, r1, 0
	ldr r5, [sp, 0xC]
	cmp r2, 0x1C
	bgt _08006B64
	cmp r2, 0
	blt _08006B64
	ldr r0, [r0, 0xC]
	cmp r0, 0x7
	bhi _08006B64
	lsls r0, 2
	ldr r1, _08006AE4
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08006AE4: .4byte _08006AE8
	.align 2, 0
_08006AE8:
	.4byte _08006B2C
	.4byte _08006B2C
	.4byte _08006B08
	.4byte _08006B2C
	.4byte _08006B2C
	.4byte _08006B54
	.4byte _08006B2C
	.4byte _08006B54
_08006B08:
	lsls r1, r4, 1
	lsls r0, r2, 6
	adds r0, r5
	adds r1, r0
	ldr r2, _08006B24
	adds r0, r2, 0
	orrs r3, r0
	strh r3, [r1]
	movs r0, 0x80
	lsls r0, 4
	adds r1, r0
	ldr r2, _08006B28
	b _08006B44
	.align 2, 0
_08006B24: .4byte 0xfffff000
_08006B28: .4byte 0x0000f278
_08006B2C:
	lsls r1, r4, 1
	lsls r0, r2, 6
	adds r0, r5
	adds r1, r0
	ldr r2, _08006B4C
	adds r0, r2, 0
	orrs r3, r0
	strh r3, [r1]
	movs r0, 0x80
	lsls r0, 4
	adds r1, r0
	ldr r2, _08006B50
_08006B44:
	adds r0, r2, 0
	strh r0, [r1]
	b _08006B64
	.align 2, 0
_08006B4C: .4byte 0xfffff000
_08006B50: .4byte 0x0000f2db
_08006B54:
	lsls r0, r4, 1
	lsls r1, r2, 6
	adds r1, r5
	adds r0, r1
	ldr r2, _08006B6C
	adds r1, r2, 0
	orrs r3, r1
	strh r3, [r0]
_08006B64:
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_08006B6C: .4byte 0xfffff000
	thumb_func_end sub_8006AC4

	thumb_func_start sub_8006B70
sub_8006B70:
	push {r4-r6,lr}
	adds r6, r0, 0
	adds r4, r1, 0
	adds r5, r3, 0
	ldr r3, [sp, 0x10]
	cmp r2, 0x1C
	bgt _08006C3A
	cmp r2, 0
	blt _08006C3A
	ldr r0, [r6, 0xC]
	cmp r0, 0x7
	bhi _08006C3A
	lsls r0, 2
	ldr r1, _08006B94
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08006B94: .4byte _08006B98
	.align 2, 0
_08006B98:
	.4byte _08006BB8
	.4byte _08006C3A
	.4byte _08006C3A
	.4byte _08006BE8
	.4byte _08006BF8
	.4byte _08006C1C
	.4byte _08006BE8
	.4byte _08006C2C
_08006BB8:
	cmp r5, 0
	bne _08006BCC
	lsls r1, r4, 1
	lsls r0, r2, 6
	adds r0, r3
	adds r1, r0
	ldr r2, _08006BC8
	b _08006C02
	.align 2, 0
_08006BC8: .4byte 0x0000f697
_08006BCC:
	movs r1, 0x6
	ldrsh r0, [r6, r1]
	subs r0, 0x1
	cmp r5, r0
	bne _08006BE8
	lsls r1, r4, 1
	lsls r0, r2, 6
	adds r0, r3
	adds r1, r0
	ldr r2, _08006BE4
	b _08006C02
	.align 2, 0
_08006BE4: .4byte 0x0000fe97
_08006BE8:
	lsls r1, r4, 1
	lsls r0, r2, 6
	adds r0, r3
	adds r1, r0
	ldr r2, _08006BF4
	b _08006C02
	.align 2, 0
_08006BF4: .4byte 0x0000f6da
_08006BF8:
	lsls r1, r4, 1
	lsls r0, r2, 6
	adds r0, r3
	adds r1, r0
	ldr r2, _08006C14
_08006C02:
	adds r0, r2, 0
	strh r0, [r1]
	movs r0, 0x80
	lsls r0, 4
	adds r1, r0
	ldr r2, _08006C18
	adds r0, r2, 0
	strh r0, [r1]
	b _08006C3A
	.align 2, 0
_08006C14: .4byte 0x0000f6ea
_08006C18: .4byte 0x0000f2db
_08006C1C:
	lsls r0, r4, 1
	lsls r1, r2, 6
	adds r1, r3
	adds r0, r1
	ldr r2, _08006C28
	b _08006C36
	.align 2, 0
_08006C28: .4byte 0x0000f6de
_08006C2C:
	lsls r0, r4, 1
	lsls r1, r2, 6
	adds r1, r3
	adds r0, r1
	ldr r2, _08006C40
_08006C36:
	adds r1, r2, 0
	strh r1, [r0]
_08006C3A:
	pop {r4-r6}
	pop {r0}
	bx r0
	.align 2, 0
_08006C40: .4byte 0x0000f6b6
	thumb_func_end sub_8006B70

	thumb_func_start sub_8006C44
sub_8006C44:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x4
	adds r6, r0, 0
	adds r4, r1, 0
	str r2, [sp]
	lsls r3, 24
	lsrs r3, 24
	mov r9, r3
	movs r1, 0
	ldrsh r0, [r6, r1]
	subs r3, r0, 0x1
	cmp r4, 0x1C
	ble _08006C68
	b _08006E76
_08006C68:
	cmp r4, 0
	bge _08006C6E
	b _08006E76
_08006C6E:
	ldr r0, [r6, 0xC]
	cmp r0, 0x7
	bls _08006C76
	b _08006E76
_08006C76:
	lsls r0, 2
	ldr r1, _08006C80
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08006C80: .4byte _08006C84
	.align 2, 0
_08006C84:
	.4byte _08006E76
	.4byte _08006E76
	.4byte _08006E76
	.4byte _08006CA4
	.4byte _08006D64
	.4byte _08006DE8
	.4byte _08006CA4
	.4byte _08006E34
_08006CA4:
	lsls r1, r3, 1
	lsls r2, r4, 6
	ldr r4, [sp]
	adds r0, r2, r4
	adds r1, r0
	ldr r7, _08006CC8
	adds r0, r7, 0
	strh r0, [r1]
	adds r5, r2, 0
	mov r0, r9
	cmp r0, 0
	beq _08006CD0
	movs r2, 0x80
	lsls r2, 4
	adds r1, r2
	ldr r4, _08006CCC
	adds r0, r4, 0
	b _08006CDA
	.align 2, 0
_08006CC8: .4byte 0x0000fad8
_08006CCC: .4byte 0x0000fa93
_08006CD0:
	movs r7, 0x80
	lsls r7, 4
	adds r1, r7
	ldr r2, _08006D40
	adds r0, r2, 0
_08006CDA:
	strh r0, [r1]
	adds r3, 0x1
	movs r4, 0
	movs r7, 0x4
	ldrsh r0, [r6, r7]
	cmp r4, r0
	bge _08006D1E
	ldr r0, _08006D44
	mov r8, r0
	lsls r0, r3, 1
	ldr r2, [sp]
	movs r7, 0x80
	lsls r7, 4
	adds r1, r2, r7
	adds r1, r5, r1
	adds r2, r0, r1
	ldr r7, [sp]
	adds r1, r5, r7
	adds r1, r0, r1
	ldr r0, _08006D40
	mov r12, r0
_08006D04:
	mov r7, r8
	strh r7, [r1]
	mov r0, r12
	strh r0, [r2]
	adds r2, 0x2
	adds r1, 0x2
	adds r3, 0x1
	adds r4, 0x1
	movs r0, 0x4
	ldrsh r7, [r6, r0]
	mov r10, r7
	cmp r4, r10
	blt _08006D04
_08006D1E:
	lsls r0, r3, 1
	ldr r2, [sp]
	adds r1, r5, r2
	adds r1, r0, r1
	ldr r4, _08006D48
	adds r0, r4, 0
	strh r0, [r1]
	mov r7, r9
	cmp r7, 0
	beq _08006D50
	movs r0, 0x80
	lsls r0, 4
	adds r1, r0
	ldr r2, _08006D4C
	adds r0, r2, 0
	strh r0, [r1]
	b _08006E76
	.align 2, 0
_08006D40: .4byte 0x0000f2db
_08006D44: .4byte 0x0000fad9
_08006D48: .4byte 0x0000fed8
_08006D4C: .4byte 0x0000fe93
_08006D50:
	movs r4, 0x80
	lsls r4, 4
	adds r1, r4
	ldr r7, _08006D60
	adds r0, r7, 0
	strh r0, [r1]
	b _08006E76
	.align 2, 0
_08006D60: .4byte 0x0000f2db
_08006D64:
	lsls r1, r3, 1
	lsls r2, r4, 6
	ldr r0, [sp]
	adds r0, r2
	mov r12, r0
	add r1, r12
	ldr r4, _08006DD8
	adds r0, r4, 0
	strh r0, [r1]
	movs r7, 0x80
	lsls r7, 4
	mov r8, r7
	add r1, r8
	ldr r0, _08006DDC
	mov r9, r0
	strh r0, [r1]
	adds r3, 0x1
	movs r4, 0
	movs r1, 0x4
	ldrsh r0, [r6, r1]
	adds r5, r2, 0
	cmp r4, r0
	bge _08006DBE
	ldr r2, _08006DE0
	mov r10, r2
	lsls r1, r3, 1
	ldr r0, [sp]
	add r0, r8
	adds r0, r5, r0
	adds r2, r1, r0
	add r1, r12
	mov r12, r9
_08006DA4:
	mov r7, r10
	strh r7, [r1]
	mov r0, r12
	strh r0, [r2]
	adds r2, 0x2
	adds r1, 0x2
	adds r3, 0x1
	adds r4, 0x1
	movs r0, 0x4
	ldrsh r7, [r6, r0]
	mov r8, r7
	cmp r4, r8
	blt _08006DA4
_08006DBE:
	lsls r0, r3, 1
	ldr r2, [sp]
	adds r1, r5, r2
	adds r0, r1
	ldr r4, _08006DE4
	adds r1, r4, 0
	strh r1, [r0]
	movs r7, 0x80
	lsls r7, 4
	adds r0, r7
	ldr r2, _08006DDC
	adds r1, r2, 0
	b _08006E74
	.align 2, 0
_08006DD8: .4byte 0x0000fae8
_08006DDC: .4byte 0x0000f2db
_08006DE0: .4byte 0x0000fae9
_08006DE4: .4byte 0x0000fee8
_08006DE8:
	lsls r0, r3, 1
	lsls r2, r4, 6
	ldr r4, [sp]
	adds r4, r2
	mov r12, r4
	add r0, r12
	ldr r7, _08006E28
	adds r1, r7, 0
	strh r1, [r0]
	adds r3, 0x1
	movs r1, 0x4
	ldrsh r0, [r6, r1]
	adds r5, r2, 0
	cmp r0, 0
	ble _08006E1C
	ldr r2, _08006E2C
	adds r1, r2, 0
	adds r4, r0, 0
	lsls r0, r3, 1
	add r0, r12
_08006E10:
	strh r1, [r0]
	adds r0, 0x2
	adds r3, 0x1
	subs r4, 0x1
	cmp r4, 0
	bne _08006E10
_08006E1C:
	lsls r0, r3, 1
	ldr r4, [sp]
	adds r1, r5, r4
	adds r0, r1
	ldr r7, _08006E30
	b _08006E72
	.align 2, 0
_08006E28: .4byte 0x0000fadc
_08006E2C: .4byte 0x0000fadd
_08006E30: .4byte 0x0000fedc
_08006E34:
	lsls r0, r3, 1
	lsls r2, r4, 6
	ldr r1, [sp]
	adds r1, r2
	mov r12, r1
	add r0, r12
	ldr r4, _08006E88
	adds r1, r4, 0
	strh r1, [r0]
	adds r3, 0x1
	movs r7, 0x4
	ldrsh r0, [r6, r7]
	adds r5, r2, 0
	cmp r0, 0
	ble _08006E68
	ldr r2, _08006E8C
	adds r1, r2, 0
	adds r4, r0, 0
	lsls r0, r3, 1
	add r0, r12
_08006E5C:
	strh r1, [r0]
	adds r0, 0x2
	adds r3, 0x1
	subs r4, 0x1
	cmp r4, 0
	bne _08006E5C
_08006E68:
	lsls r0, r3, 1
	ldr r4, [sp]
	adds r1, r5, r4
	adds r0, r1
	ldr r7, _08006E90
_08006E72:
	adds r1, r7, 0
_08006E74:
	strh r1, [r0]
_08006E76:
	add sp, 0x4
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_08006E88: .4byte 0x0000fa93
_08006E8C: .4byte 0x0000fa97
_08006E90: .4byte 0x0000fe93
	thumb_func_end sub_8006C44

	thumb_func_start sub_8006E94
sub_8006E94:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x30
	str r0, [sp]
	adds r4, r1, 0
	adds r7, r2, 0
	str r3, [sp, 0x4]
	movs r1, 0
	ldrsh r0, [r0, r1]
	mov r10, r0
	movs r2, 0x1
	negs r2, r2
	add r2, r10
	movs r3, 0
	str r3, [sp, 0x8]
	cmp r4, 0x1C
	ble _08006EBE
	b _080072FE
_08006EBE:
	cmp r4, 0
	bge _08006EC4
	b _080072FE
_08006EC4:
	lsls r1, r2, 1
	lsls r4, 6
	ldr r6, [sp, 0x50]
	adds r5, r4, r6
	adds r1, r5
	ldr r0, _08006F9C
	adds r3, r0, 0
	strh r3, [r1]
	movs r2, 0x80
	lsls r2, 4
	adds r0, r1, r2
	ldr r6, _08006FA0
	adds r2, r6, 0
	strh r2, [r0]
	adds r0, r1, 0
	adds r0, 0x40
	strh r3, [r0]
	movs r0, 0x84
	lsls r0, 4
	adds r0, r1, r0
	strh r2, [r0]
	adds r2, r1, 0
	adds r2, 0x80
	ldr r3, _08006FA4
	adds r0, r3, 0
	strh r0, [r2]
	movs r6, 0x88
	lsls r6, 4
	adds r1, r6
	ldr r2, _08006FA8
	adds r0, r2, 0
	strh r0, [r1]
	mov r12, r10
	movs r3, 0
	str r4, [sp, 0x18]
	ldr r4, [sp, 0x4]
	ldrb r4, [r4]
	cmp r3, r4
	blt _08006F14
	b _08007238
_08006F14:
	adds r2, r5, 0
	mov r5, r12
	lsls r1, r5, 1
	ldr r0, [sp, 0x50]
	adds r0, 0x80
	ldr r6, [sp, 0x18]
	adds r0, r6, r0
	adds r0, r1
	mov r9, r0
	ldr r0, [sp, 0x50]
	adds r0, 0x40
	adds r0, r6, r0
	adds r0, r1
	mov r8, r0
	ldr r4, [sp, 0x50]
	movs r5, 0x80
	lsls r5, 4
	adds r0, r4, r5
	adds r0, r6, r0
	adds r0, r1, r0
	str r0, [sp, 0x20]
	movs r6, 0x84
	lsls r6, 4
	adds r0, r4, r6
	ldr r4, [sp, 0x18]
	adds r0, r4, r0
	adds r0, r1
	mov r10, r0
	adds r4, r1, r2
	ldr r5, [sp, 0x18]
	str r5, [sp, 0x10]
	str r2, [sp, 0x1C]
	str r1, [sp, 0x24]
_08006F56:
	ldr r6, [sp, 0x4]
	ldrb r6, [r6, 0x1]
	cmp r3, r6
	bne _08006F60
	b _080070C8
_08006F60:
	ldr r0, [sp, 0x8]
	cmp r0, 0
	bne _08007008
	ldr r1, [sp, 0x4]
	ldrb r0, [r1, 0x3]
	asrs r0, r3
	movs r1, 0x1
	ands r0, r1
	cmp r0, 0
	beq _08006FB8
	movs r1, 0x1F
	cmp r3, 0
	bne _08006F7C
	movs r1, 0x1B
_08006F7C:
	movs r2, 0x9E
	lsls r2, 2
	adds r0, r1, r2
	ldr r5, _08006FAC
	adds r1, r5, 0
	orrs r0, r1
	strh r0, [r4]
	ldr r6, _08006FB0
	adds r0, r6, 0
	mov r1, r8
	strh r0, [r1]
	ldr r5, _08006FB4
	mov r2, r9
	strh r5, [r2]
	b _08006FDC
	.align 2, 0
_08006F9C: .4byte 0x0000f278
_08006FA0: .4byte 0x0000f27a
_08006FA4: .4byte 0x0000f2d8
_08006FA8: .4byte 0x0000f2db
_08006FAC: .4byte 0xfffff400
_08006FB0: .4byte 0x0000f2b6
_08006FB4: .4byte 0x0000f2d9
_08006FB8:
	movs r1, 0x6B
	cmp r3, 0
	bne _08006FC0
	movs r1, 0x67
_08006FC0:
	movs r6, 0x9E
	lsls r6, 2
	adds r0, r1, r6
	ldr r2, _08006FF4
	adds r1, r2, 0
	orrs r0, r1
	strh r0, [r4]
	ldr r5, _08006FF8
	adds r0, r5, 0
	mov r6, r8
	strh r0, [r6]
	ldr r1, _08006FFC
	mov r0, r9
	strh r1, [r0]
_08006FDC:
	ldr r2, _08007000
	adds r0, r2, 0
	ldr r5, [sp, 0x20]
	strh r0, [r5]
	ldr r0, _08007004
	mov r6, r10
	strh r0, [r6]
	movs r1, 0x88
	lsls r1, 4
	adds r0, r4, r1
	adds r2, 0x61
	b _0800708E
	.align 2, 0
_08006FF4: .4byte 0xfffff400
_08006FF8: .4byte 0x0000f2ef
_08006FFC: .4byte 0x0000f2d9
_08007000: .4byte 0x0000f27a
_08007004: .4byte 0x0000f2db
_08007008:
	ldr r5, [sp, 0x4]
	ldrb r0, [r5, 0x3]
	asrs r0, r3
	movs r1, 0x1
	ands r0, r1
	cmp r0, 0
	beq _0800704C
	ldrb r0, [r5]
	subs r0, 0x1
	movs r1, 0x1F
	cmp r3, r0
	bne _08007022
	movs r1, 0x1B
_08007022:
	movs r6, 0x9E
	lsls r6, 2
	adds r0, r1, r6
	ldr r2, _08007040
	adds r1, r2, 0
	orrs r0, r1
	strh r0, [r4]
	ldr r5, _08007044
	adds r0, r5, 0
	mov r6, r8
	strh r0, [r6]
	ldr r1, _08007048
	mov r0, r9
	strh r1, [r0]
	b _08007076
	.align 2, 0
_08007040: .4byte 0xfffff000
_08007044: .4byte 0x0000f6b6
_08007048: .4byte 0x0000f2d9
_0800704C:
	ldr r2, [sp, 0x4]
	ldrb r0, [r2]
	subs r0, 0x1
	movs r1, 0x6B
	cmp r3, r0
	bne _0800705A
	movs r1, 0x67
_0800705A:
	movs r5, 0x9E
	lsls r5, 2
	adds r0, r1, r5
	ldr r6, _080070B0
	adds r1, r6, 0
	orrs r0, r1
	strh r0, [r4]
	ldr r1, _080070B4
	adds r0, r1, 0
	mov r2, r8
	strh r0, [r2]
	ldr r6, _080070B8
	mov r5, r9
	strh r6, [r5]
_08007076:
	ldr r1, _080070BC
	adds r0, r1, 0
	ldr r2, [sp, 0x20]
	strh r0, [r2]
	ldr r5, _080070C0
	adds r0, r5, 0
	mov r6, r10
	strh r0, [r6]
	movs r1, 0x88
	lsls r1, 4
	adds r0, r4, r1
	ldr r2, _080070C4
_0800708E:
	strh r2, [r0]
	movs r5, 0x2
	add r9, r5
	add r8, r5
	ldr r6, [sp, 0x20]
	adds r6, 0x2
	str r6, [sp, 0x20]
	add r10, r5
	adds r4, 0x2
	ldr r0, [sp, 0x24]
	adds r0, 0x2
	str r0, [sp, 0x24]
	movs r1, 0x1
	add r12, r1
	adds r3, 0x1
	str r3, [sp, 0x14]
	b _08007226
	.align 2, 0
_080070B0: .4byte 0xfffff000
_080070B4: .4byte 0x0000f6ef
_080070B8: .4byte 0x0000f2d9
_080070BC: .4byte 0x0000f27a
_080070C0: .4byte 0x0000f6db
_080070C4: .4byte 0x0000f2db
_080070C8:
	movs r2, 0x1
	str r2, [sp, 0x8]
	ldr r5, _08007128
	adds r0, r5, 0
	strh r0, [r4]
	ldr r6, _0800712C
	adds r0, r6, 0
	ldr r1, [sp, 0x20]
	strh r0, [r1]
	ldr r2, _08007130
	adds r0, r2, 0
	mov r5, r8
	strh r0, [r5]
	ldr r0, _08007134
	mov r6, r10
	strh r0, [r6]
	ldr r1, _08007138
	adds r0, r1, 0
	mov r2, r9
	strh r0, [r2]
	movs r5, 0x88
	lsls r5, 4
	adds r0, r4, r5
	ldr r6, _08007134
	strh r6, [r0]
	movs r0, 0x2
	add r9, r0
	add r8, r0
	ldr r1, [sp, 0x20]
	adds r1, 0x2
	str r1, [sp, 0x20]
	add r10, r0
	adds r4, 0x2
	ldr r2, [sp, 0x24]
	adds r2, 0x2
	str r2, [sp, 0x24]
	movs r5, 0x1
	add r12, r5
	cmp r7, 0
	beq _0800713C
	adds r7, 0x1
	cmp r7, 0
	beq _0800713C
	ldr r6, [sp]
	movs r1, 0x4
	ldrsh r0, [r6, r1]
	adds r2, r7, r0
	b _0800713E
	.align 2, 0
_08007128: .4byte 0x0000f2e0
_0800712C: .4byte 0x0000f2e2
_08007130: .4byte 0x0000f2da
_08007134: .4byte 0x0000f2db
_08007138: .4byte 0x0000f6e7
_0800713C:
	movs r2, 0
_0800713E:
	movs r5, 0
	str r5, [sp, 0xC]
	adds r3, 0x1
	str r3, [sp, 0x14]
	ldr r6, [sp, 0x4]
	ldrb r6, [r6, 0x2]
	cmp r5, r6
	bge _080071E0
	ldr r0, [sp, 0x50]
	adds r0, 0x80
	ldr r1, [sp, 0x10]
	adds r0, r1, r0
	ldr r3, [sp, 0x24]
	adds r0, r3, r0
	str r0, [sp, 0x2C]
	ldr r0, [sp, 0x50]
	adds r0, 0x40
	adds r0, r1, r0
	adds r5, r3, r0
	ldr r6, [sp, 0x1C]
	adds r3, r6
_08007168:
	ldr r1, _08007310
	adds r0, r1, 0
	strh r0, [r3]
	movs r6, 0x80
	lsls r6, 4
	adds r6, r3, r6
	str r6, [sp, 0x28]
	adds r1, 0x1
	adds r0, r1, 0
	strh r0, [r6]
	adds r0, r7, 0
	ldr r6, _08007314
	orrs r0, r6
	strh r0, [r5]
	movs r1, 0x84
	lsls r1, 4
	adds r0, r3, r1
	ldr r6, _08007318
	strh r6, [r0]
	adds r0, r2, 0
	ldr r1, _08007314
	orrs r0, r1
	ldr r6, [sp, 0x2C]
	strh r0, [r6]
	movs r1, 0x88
	lsls r1, 4
	adds r0, r3, r1
	ldr r6, _08007318
	strh r6, [r0]
	ldr r0, [sp, 0x2C]
	adds r0, 0x2
	str r0, [sp, 0x2C]
	adds r5, 0x2
	adds r3, 0x2
	movs r1, 0x2
	add r9, r1
	add r8, r1
	ldr r6, [sp, 0x20]
	adds r6, 0x2
	str r6, [sp, 0x20]
	add r10, r1
	adds r4, 0x2
	ldr r0, [sp, 0x24]
	adds r0, 0x2
	str r0, [sp, 0x24]
	movs r1, 0x1
	add r12, r1
	cmp r7, 0
	beq _080071CC
	adds r7, 0x1
_080071CC:
	cmp r2, 0
	beq _080071D2
	adds r2, 0x1
_080071D2:
	ldr r6, [sp, 0xC]
	adds r6, 0x1
	str r6, [sp, 0xC]
	ldr r0, [sp, 0x4]
	ldrb r0, [r0, 0x2]
	cmp r6, r0
	blt _08007168
_080071E0:
	ldr r1, _0800731C
	adds r0, r1, 0
	strh r0, [r4]
	ldr r2, _08007320
	adds r0, r2, 0
	ldr r3, [sp, 0x20]
	strh r0, [r3]
	ldr r5, _08007324
	adds r0, r5, 0
	mov r6, r8
	strh r0, [r6]
	ldr r1, _08007318
	mov r0, r10
	strh r1, [r0]
	adds r2, 0x5
	adds r0, r2, 0
	mov r3, r9
	strh r0, [r3]
	movs r5, 0x88
	lsls r5, 4
	adds r0, r4, r5
	strh r1, [r0]
	movs r6, 0x2
	add r9, r6
	add r8, r6
	ldr r0, [sp, 0x20]
	adds r0, 0x2
	str r0, [sp, 0x20]
	add r10, r6
	adds r4, 0x2
	ldr r1, [sp, 0x24]
	adds r1, 0x2
	str r1, [sp, 0x24]
	movs r2, 0x1
	add r12, r2
_08007226:
	cmp r7, 0
	beq _0800722C
	adds r7, 0x1
_0800722C:
	ldr r3, [sp, 0x14]
	ldr r5, [sp, 0x4]
	ldrb r5, [r5]
	cmp r3, r5
	bge _08007238
	b _08006F56
_08007238:
	ldr r6, [sp]
	movs r0, 0
	ldrsh r1, [r6, r0]
	movs r2, 0x4
	ldrsh r0, [r6, r2]
	adds r0, r1, r0
	cmp r12, r0
	bge _080072BC
	ldr r3, _08007328
	adds r4, r3, 0
	mov r8, r0
	mov r5, r12
	lsls r1, r5, 1
	ldr r0, [sp, 0x50]
	adds r0, 0x80
	ldr r6, [sp, 0x18]
	adds r0, r6, r0
	adds r5, r1, r0
	ldr r0, [sp, 0x50]
	adds r0, 0x40
	adds r0, r6, r0
	adds r3, r1, r0
	ldr r0, [sp, 0x50]
	adds r6, r0
	adds r2, r1, r6
	movs r1, 0x80
	lsls r1, 4
	mov r10, r1
	movs r6, 0x84
	lsls r6, 4
	mov r9, r6
	mov r0, r8
	mov r1, r12
	subs r0, r1
	mov r12, r0
_0800727E:
	strh r4, [r2]
	mov r6, r10
	adds r0, r2, r6
	ldr r1, _0800732C
	strh r1, [r0]
	strh r4, [r3]
	mov r6, r9
	adds r0, r2, r6
	strh r1, [r0]
	adds r1, 0x5F
	adds r0, r1, 0
	strh r0, [r5]
	movs r6, 0x88
	lsls r6, 4
	adds r1, r2, r6
	ldr r6, _08007318
	adds r0, r6, 0
	strh r0, [r1]
	adds r5, 0x2
	adds r3, 0x2
	adds r2, 0x2
	movs r0, 0x1
	negs r0, r0
	add r12, r0
	cmp r7, 0
	beq _080072B4
	adds r7, 0x1
_080072B4:
	mov r1, r12
	cmp r1, 0
	bne _0800727E
	mov r12, r8
_080072BC:
	mov r2, r12
	lsls r1, r2, 1
	ldr r3, [sp, 0x18]
	ldr r4, [sp, 0x50]
	adds r0, r3, r4
	adds r1, r0
	ldr r5, _08007328
	adds r3, r5, 0
	strh r3, [r1]
	movs r6, 0x80
	lsls r6, 4
	adds r0, r1, r6
	ldr r4, _0800732C
	adds r2, r4, 0
	strh r2, [r0]
	adds r0, r1, 0
	adds r0, 0x40
	strh r3, [r0]
	movs r5, 0x84
	lsls r5, 4
	adds r0, r1, r5
	strh r2, [r0]
	adds r2, r1, 0
	adds r2, 0x80
	ldr r6, _08007330
	adds r0, r6, 0
	strh r0, [r2]
	movs r0, 0x88
	lsls r0, 4
	adds r1, r0
	ldr r2, _08007318
	adds r0, r2, 0
	strh r0, [r1]
_080072FE:
	add sp, 0x30
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_08007310: .4byte 0x0000f2e1
_08007314: .4byte 0xfffff000
_08007318: .4byte 0x0000f2db
_0800731C: .4byte 0x0000f6e0
_08007320: .4byte 0x0000f2e2
_08007324: .4byte 0x0000f6da
_08007328: .4byte 0x0000f278
_0800732C: .4byte 0x0000f27a
_08007330: .4byte 0x0000f6d8
	thumb_func_end sub_8006E94

	thumb_func_start sub_8007334
sub_8007334:
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	lsls r1, r0, 3
	adds r1, r0
	lsls r1, 3
	ldr r0, _080073AC
	adds r3, r1, r0
	ldr r5, [r3, 0x14]
	movs r0, 0x2
	ldrsh r6, [r3, r0]
	movs r2, 0
	movs r1, 0x6
	ldrsh r0, [r3, r1]
	cmp r2, r0
	bge _080073A0
	ldr r7, _080073B0
	mov r9, r7
_0800735A:
	movs r0, 0
	ldrsh r1, [r3, r0]
	movs r4, 0
	movs r7, 0x4
	ldrsh r0, [r3, r7]
	adds r7, r6, 0x1
	adds r2, 0x1
	mov r12, r2
	cmp r4, r0
	bge _08007394
	movs r0, 0xFC
	lsls r0, 8
	mov r8, r0
	lsls r1, 1
	lsls r0, r6, 6
	add r0, r9
	adds r2, r1, r0
_0800737C:
	ldrh r0, [r2]
	mov r1, r8
	ands r1, r0
	orrs r1, r5
	strh r1, [r2]
	adds r2, 0x2
	adds r5, 0x1
	adds r4, 0x1
	movs r1, 0x4
	ldrsh r0, [r3, r1]
	cmp r4, r0
	blt _0800737C
_08007394:
	adds r6, r7, 0
	mov r2, r12
	movs r7, 0x6
	ldrsh r0, [r3, r7]
	cmp r2, r0
	blt _0800735A
_080073A0:
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_080073AC: .4byte gUnknown_2027370
_080073B0: .4byte gUnknown_202B038
	thumb_func_end sub_8007334

	thumb_func_start nullsub_154
nullsub_154:
	bx lr
	thumb_func_end nullsub_154

	thumb_func_start sub_80073B8
sub_80073B8:
	lsls r1, r0, 3
	adds r1, r0
	lsls r1, 3
	ldr r0, _080073D8
	adds r1, r0
	ldr r0, [r1, 0x2C]
	lsrs r0, 2
	lsls r0, 2
	ldr r2, [r1, 0x1C]
	adds r0, r2, r0
	str r0, [r1, 0x3C]
	str r2, [r1, 0x40]
	adds r1, 0x46
	movs r0, 0x1
	strb r0, [r1]
	bx lr
	.align 2, 0
_080073D8: .4byte gUnknown_2027370
	thumb_func_end sub_80073B8

	thumb_func_start nullsub_155
nullsub_155:
	bx lr
	thumb_func_end nullsub_155

	thumb_func_start sub_80073E0
sub_80073E0:
	push {r4,lr}
	lsls r1, r0, 3
	adds r1, r0
	lsls r1, 3
	ldr r0, _08007434
	adds r3, r1, r0
	adds r0, r3, 0
	adds r0, 0x44
	ldrb r4, [r0]
	cmp r4, 0
	bne _08007424
	ldr r2, [r3, 0x3C]
	ldr r0, [r3, 0x1C]
	subs r0, r2, r0
	asrs r0, 2
	lsls r0, 2
	ldr r1, [r3, 0x28]
	adds r1, r0
	str r1, [r3, 0x30]
	str r2, [r3, 0x34]
	ldr r0, [r3, 0x40]
	subs r0, r2
	asrs r0, 2
	adds r0, 0x1
	lsls r0, 2
	str r0, [r3, 0x38]
	ldr r1, [r3, 0x2C]
	cmp r0, r1
	blt _0800741C
	str r1, [r3, 0x38]
_0800741C:
	ldr r0, [r3, 0x38]
	cmp r0, 0
	bge _08007424
	str r4, [r3, 0x38]
_08007424:
	adds r1, r3, 0
	adds r1, 0x46
	movs r0, 0
	strb r0, [r1]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08007434: .4byte gUnknown_2027370
	thumb_func_end sub_80073E0

	thumb_func_start nullsub_156
nullsub_156:
	bx lr
	thumb_func_end nullsub_156

	thumb_func_start xxx_call_draw_char
xxx_call_draw_char:
	push {r4-r6,lr}
	sub sp, 0x8
	adds r4, r0, 0
	adds r5, r1, 0
	adds r6, r2, 0
	ldr r1, [sp, 0x18]
	ldr r0, _08007460
	str r3, [sp]
	str r1, [sp, 0x4]
	adds r1, r4, 0
	adds r2, r5, 0
	adds r3, r6, 0
	bl xxx_draw_char
	add sp, 0x8
	pop {r4-r6}
	pop {r1}
	bx r1
	.align 2, 0
_08007460: .4byte gUnknown_2027370
	thumb_func_end xxx_call_draw_char

	thumb_func_start sub_8007464
sub_8007464:
	movs r0, 0
	bx lr
	thumb_func_end sub_8007464

	thumb_func_start xxx_draw_char
xxx_draw_char:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x28
	adds r6, r1, 0
	mov r10, r2
	adds r4, r3, 0
	ldr r2, [sp, 0x48]
	ldr r3, [sp, 0x4C]
	lsls r1, r3, 3
	adds r1, r3
	lsls r1, 3
	adds r5, r0, r1
	ldr r1, _080074B8
	movs r0, 0xF
	ands r2, r0
	lsls r2, 2
	adds r2, r1
	ldr r2, [r2]
	str r2, [sp, 0x18]
	ldr r0, _080074BC
	ldr r0, [r0]
	cmp r0, 0x1
	bne _080074CC
	cmp r4, 0x70
	beq _080074B0
	cmp r4, 0x6A
	beq _080074B0
	cmp r4, 0x71
	beq _080074B0
	cmp r4, 0x79
	beq _080074B0
	cmp r4, 0x67
	bne _080074C0
_080074B0:
	movs r0, 0x2
	add r10, r0
	b _080074CC
	.align 2, 0
_080074B8: .4byte gUnknown_80B853C
_080074BC: .4byte gUnknown_20274AC
_080074C0:
	ldr r0, _080074F8
	cmp r4, r0
	bne _080074CC
	movs r1, 0x2
	negs r1, r1
	add r10, r1
_080074CC:
	adds r0, r4, 0
	bl sub_8008584
	str r0, [sp]
	ldr r2, [r0]
	str r2, [sp, 0x4]
	str r2, [sp, 0xC]
	adds r3, r2, 0
	subs r3, 0x6
	str r3, [sp, 0x8]
	ldr r0, _080074FC
	ldrb r0, [r0]
	cmp r0, 0
	beq _08007500
	ldr r4, [sp]
	ldrb r1, [r4, 0xA]
	lsrs r7, r1, 1
	movs r0, 0x1
	adds r2, r7, 0
	ands r2, r0
	str r2, [sp, 0x1C]
	b _08007508
	.align 2, 0
_080074F8: .4byte 0x00008199
_080074FC: .4byte gUnknown_202B034
_08007500:
	movs r3, 0
	str r3, [sp, 0x1C]
	ldr r4, [sp]
	ldrb r1, [r4, 0xA]
_08007508:
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	bne _08007512
	b _08007670
_08007512:
	mov r0, r10
	cmp r0, 0
	bge _0800751A
	adds r0, 0x7
_0800751A:
	asrs r4, r0, 3
	movs r7, 0x4
	ldrsh r0, [r5, r7]
	muls r0, r4
	adds r2, r6, 0
	cmp r6, 0
	bge _0800752A
	adds r2, r6, 0x7
_0800752A:
	asrs r2, 3
	adds r0, r2
	lsls r0, 5
	ldr r1, [r5, 0x18]
	adds r3, r1, r0
	lsls r0, r4, 3
	mov r1, r10
	subs r0, r1, r0
	lsls r0, 2
	adds r3, r0
	lsls r0, r2, 3
	subs r0, r6, r0
	lsls r0, 4
	ldr r1, _08007664
	adds r0, r1
	mov r12, r0
	mov r9, r2
	str r4, [sp, 0x14]
	movs r2, 0x8
	ldrsh r0, [r5, r2]
	cmp r4, r0
	blt _08007558
	b _0800786C
_08007558:
	movs r4, 0
	str r4, [sp, 0x10]
	ldr r2, _08007668
	ldr r1, _0800766C
	ldr r0, [r1]
	lsls r0, 2
	adds r0, r2
	ldr r0, [r0]
	cmp r4, r0
	blt _0800756E
	b _0800786C
_0800756E:
	adds r4, r2, 0
_08007570:
	ldr r6, [sp, 0x4]
	ldrh r0, [r6, 0x2]
	lsls r2, r0, 16
	ldrh r0, [r6]
	orrs r2, r0
	cmp r2, 0
	beq _080075CC
	movs r7, 0x4
	ldrsh r0, [r5, r7]
	cmp r9, r0
	bge _080075A6
	mov r0, r12
	ldr r1, [r0]
	ands r1, r2
	ldr r0, [r0, 0x8]
	lsls r1, r0
	ldr r0, [r3]
	orrs r0, r1
	str r0, [r3]
	ldr r0, [r5, 0x3C]
	cmp r0, r3
	bls _0800759E
	str r3, [r5, 0x3C]
_0800759E:
	ldr r0, [r5, 0x40]
	cmp r0, r3
	bcs _080075A6
	str r3, [r5, 0x40]
_080075A6:
	movs r1, 0x4
	ldrsh r0, [r5, r1]
	subs r0, 0x1
	cmp r9, r0
	bge _080075CC
	adds r3, 0x20
	mov r6, r12
	ldr r0, [r6, 0x4]
	ands r2, r0
	ldr r0, [r6, 0xC]
	lsrs r2, r0
	ldr r0, [r3]
	orrs r0, r2
	str r0, [r3]
	ldr r0, [r5, 0x40]
	cmp r0, r3
	bcs _080075CA
	str r3, [r5, 0x40]
_080075CA:
	subs r3, 0x20
_080075CC:
	ldr r7, [sp, 0x4]
	ldrh r2, [r7, 0x4]
	cmp r2, 0
	beq _08007620
	movs r1, 0x4
	ldrsh r0, [r5, r1]
	subs r0, 0x1
	cmp r9, r0
	bge _080075FA
	adds r3, 0x20
	mov r6, r12
	ldr r1, [r6]
	ands r1, r2
	ldr r0, [r6, 0x8]
	lsls r1, r0
	ldr r0, [r3]
	orrs r0, r1
	str r0, [r3]
	ldr r0, [r5, 0x40]
	cmp r0, r3
	bcs _080075F8
	str r3, [r5, 0x40]
_080075F8:
	subs r3, 0x20
_080075FA:
	movs r7, 0x4
	ldrsh r0, [r5, r7]
	subs r0, 0x2
	cmp r9, r0
	bge _08007620
	adds r3, 0x40
	mov r1, r12
	ldr r0, [r1, 0x4]
	ands r2, r0
	ldr r0, [r1, 0xC]
	lsrs r2, r0
	ldr r0, [r3]
	orrs r0, r2
	str r0, [r3]
	ldr r0, [r5, 0x40]
	cmp r0, r3
	bcs _0800761E
	str r3, [r5, 0x40]
_0800761E:
	subs r3, 0x40
_08007620:
	ldr r2, [sp, 0x4]
	adds r2, 0x6
	str r2, [sp, 0x4]
	adds r3, 0x4
	movs r6, 0x1
	add r10, r6
	movs r0, 0x7
	mov r7, r10
	ands r0, r7
	cmp r0, 0
	bne _0800764E
	ldr r0, [r5, 0x20]
	lsls r0, 2
	adds r3, r0
	ldr r0, [sp, 0x14]
	adds r0, 0x1
	str r0, [sp, 0x14]
	movs r1, 0x8
	ldrsh r0, [r5, r1]
	ldr r2, [sp, 0x14]
	cmp r2, r0
	blt _0800764E
	b _0800786C
_0800764E:
	ldr r6, [sp, 0x10]
	adds r6, 0x1
	str r6, [sp, 0x10]
	ldr r7, _0800766C
	ldr r0, [r7]
	lsls r0, 2
	adds r0, r4
	ldr r0, [r0]
	cmp r6, r0
	blt _08007570
	b _0800786C
	.align 2, 0
_08007664: .4byte gUnknown_80B85DC
_08007668: .4byte gUnknown_202B028
_0800766C: .4byte gUnknown_20274AC
_08007670:
	movs r0, 0
	str r0, [sp, 0x20]
	mov r0, r10
	cmp r0, 0
	bge _0800767C
	adds r0, 0x7
_0800767C:
	asrs r4, r0, 3
	movs r1, 0x4
	ldrsh r0, [r5, r1]
	adds r1, r4, 0
	muls r1, r0
	adds r0, r6, 0
	cmp r6, 0
	bge _0800768E
	adds r0, r6, 0x7
_0800768E:
	asrs r2, r0, 3
	adds r0, r1, r2
	lsls r0, 5
	ldr r1, [r5, 0x18]
	adds r3, r1, r0
	lsls r0, r4, 3
	mov r7, r10
	subs r0, r7, r0
	lsls r0, 2
	adds r3, r0
	lsls r0, r2, 3
	subs r0, r6, r0
	lsls r0, 4
	ldr r1, _0800788C
	adds r0, r1
	mov r12, r0
	mov r9, r2
	str r4, [sp, 0x14]
	movs r1, 0x8
	ldrsh r0, [r5, r1]
	cmp r4, r0
	blt _080076BC
	b _0800786C
_080076BC:
	movs r2, 0
	str r2, [sp, 0x10]
	ldr r2, _08007890
	ldr r1, _08007894
	ldr r0, [r1]
	lsls r0, 2
	adds r0, r2
	ldr r0, [r0]
	ldr r4, [sp, 0x10]
	cmp r4, r0
	blt _080076D4
	b _0800786C
_080076D4:
	ldr r6, [sp, 0x4]
	ldrh r0, [r6, 0x2]
	lsls r4, r0, 16
	ldrh r0, [r6]
	orrs r4, r0
	ldr r1, _08007898
	ands r1, r4
	ldr r0, [sp, 0x18]
	ands r0, r4
	adds r2, r1, r0
	ldr r7, [sp, 0x1C]
	cmp r7, 0
	beq _08007724
	ldr r1, [sp, 0xC]
	ldrh r0, [r1, 0x2]
	lsls r0, 16
	ldrh r1, [r1]
	orrs r0, r1
	lsls r1, r0, 4
	mvns r6, r4
	mov r8, r6
	bics r1, r4
	ldr r7, _0800789C
	ldr r6, [r7]
	ands r1, r6
	orrs r2, r1
	ldr r0, [sp, 0x20]
	cmp r0, 0
	beq _08007724
	ldr r1, [sp, 0x8]
	ldrh r0, [r1, 0x2]
	lsls r0, 16
	ldrh r1, [r1]
	orrs r0, r1
	lsls r1, r0, 4
	eors r1, r4
	mov r4, r8
	ands r1, r4
	ands r1, r6
	orrs r2, r1
_08007724:
	cmp r2, 0
	beq _08007776
	movs r6, 0x4
	ldrsh r0, [r5, r6]
	cmp r9, r0
	bge _08007750
	mov r7, r12
	ldr r1, [r7]
	ands r1, r2
	ldr r0, [r7, 0x8]
	lsls r1, r0
	ldr r0, [r3]
	orrs r0, r1
	str r0, [r3]
	ldr r0, [r5, 0x3C]
	cmp r0, r3
	bls _08007748
	str r3, [r5, 0x3C]
_08007748:
	ldr r0, [r5, 0x40]
	cmp r0, r3
	bcs _08007750
	str r3, [r5, 0x40]
_08007750:
	movs r1, 0x4
	ldrsh r0, [r5, r1]
	subs r0, 0x1
	cmp r9, r0
	bge _08007776
	adds r3, 0x20
	mov r4, r12
	ldr r0, [r4, 0x4]
	ands r2, r0
	ldr r0, [r4, 0xC]
	lsrs r2, r0
	ldr r0, [r3]
	orrs r0, r2
	str r0, [r3]
	ldr r0, [r5, 0x40]
	cmp r0, r3
	bcs _08007774
	str r3, [r5, 0x40]
_08007774:
	subs r3, 0x20
_08007776:
	ldr r6, [sp, 0x4]
	ldrh r4, [r6, 0x4]
	ldr r1, _08007898
	ands r1, r4
	ldr r0, [sp, 0x18]
	ands r0, r4
	adds r2, r1, r0
	ldr r7, [sp, 0x1C]
	cmp r7, 0
	beq _080077CC
	ldr r1, [sp, 0xC]
	ldrh r0, [r1, 0x4]
	lsls r1, r0, 4
	ldr r6, [sp, 0xC]
	ldrh r0, [r6, 0x2]
	movs r7, 0xF
	mov r8, r7
	lsrs r0, 12
	orrs r1, r0
	mvns r0, r4
	str r0, [sp, 0x24]
	bics r1, r4
	ldr r7, _0800789C
	ldr r6, [r7]
	ands r1, r6
	orrs r2, r1
	ldr r0, [sp, 0x20]
	cmp r0, 0
	beq _080077CC
	ldr r1, [sp, 0x8]
	ldrh r0, [r1, 0x4]
	lsls r1, r0, 4
	ldr r7, [sp, 0x8]
	ldrh r0, [r7, 0x2]
	lsrs r0, 12
	mov r7, r8
	ands r0, r7
	orrs r1, r0
	eors r1, r4
	ldr r0, [sp, 0x24]
	ands r1, r0
	ands r1, r6
	orrs r2, r1
_080077CC:
	cmp r2, 0
	beq _0800781C
	movs r1, 0x4
	ldrsh r0, [r5, r1]
	subs r0, 0x1
	cmp r9, r0
	bge _080077F6
	adds r3, 0x20
	mov r4, r12
	ldr r1, [r4]
	ands r1, r2
	ldr r0, [r4, 0x8]
	lsls r1, r0
	ldr r0, [r3]
	orrs r0, r1
	str r0, [r3]
	ldr r0, [r5, 0x40]
	cmp r0, r3
	bcs _080077F4
	str r3, [r5, 0x40]
_080077F4:
	subs r3, 0x20
_080077F6:
	movs r6, 0x4
	ldrsh r0, [r5, r6]
	subs r0, 0x2
	cmp r9, r0
	bge _0800781C
	adds r3, 0x40
	mov r7, r12
	ldr r0, [r7, 0x4]
	ands r2, r0
	ldr r0, [r7, 0xC]
	lsrs r2, r0
	ldr r0, [r3]
	orrs r0, r2
	str r0, [r3]
	ldr r0, [r5, 0x40]
	cmp r0, r3
	bcs _0800781A
	str r3, [r5, 0x40]
_0800781A:
	subs r3, 0x40
_0800781C:
	movs r0, 0x1
	str r0, [sp, 0x20]
	ldr r1, [sp, 0x4]
	adds r1, 0x6
	str r1, [sp, 0x4]
	ldr r2, [sp, 0x8]
	adds r2, 0x6
	str r2, [sp, 0x8]
	ldr r4, [sp, 0xC]
	adds r4, 0x6
	str r4, [sp, 0xC]
	adds r3, 0x4
	add r10, r0
	movs r0, 0x7
	mov r6, r10
	ands r0, r6
	cmp r0, 0
	bne _08007854
	ldr r0, [r5, 0x20]
	lsls r0, 2
	adds r3, r0
	ldr r7, [sp, 0x14]
	adds r7, 0x1
	str r7, [sp, 0x14]
	movs r1, 0x8
	ldrsh r0, [r5, r1]
	cmp r7, r0
	bge _0800786C
_08007854:
	ldr r2, [sp, 0x10]
	adds r2, 0x1
	str r2, [sp, 0x10]
	ldr r4, _08007894
	ldr r0, [r4]
	lsls r0, 2
	ldr r6, _08007890
	adds r0, r6
	ldr r0, [r0]
	cmp r2, r0
	bge _0800786C
	b _080076D4
_0800786C:
	ldr r7, [sp]
	movs r1, 0x6
	ldrsh r0, [r7, r1]
	ldr r2, _080078A0
	movs r3, 0
	ldrsh r1, [r2, r3]
	adds r0, r1
	add sp, 0x28
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	.align 2, 0
_0800788C: .4byte gUnknown_80B85DC
_08007890: .4byte gUnknown_202B028
_08007894: .4byte gUnknown_20274AC
_08007898: .4byte 0x11111111
_0800789C: .4byte gUnknown_202B030
_080078A0: .4byte gUnknown_2027498
	thumb_func_end xxx_draw_char

	thumb_func_start sub_80078A4
sub_80078A4:
	push {r4-r6,lr}
	mov r6, r8
	push {r6}
	sub sp, 0x4
	adds r5, r0, 0
	adds r6, r1, 0
	adds r4, r2, 0
	mov r8, r3
	ldr r0, [sp, 0x18]
	str r0, [sp]
	adds r0, r5, 0
	bl sub_800792C
	adds r4, 0x1
	ldr r0, _080078E4
	ldr r0, [r0]
	movs r1, 0xF
	ands r0, r1
	str r0, [sp]
	adds r0, r5, 0
	adds r1, r6, 0
	adds r2, r4, 0
	mov r3, r8
	bl sub_800792C
	add sp, 0x4
	pop {r3}
	mov r8, r3
	pop {r4-r6}
	pop {r0}
	bx r0
	.align 2, 0
_080078E4: .4byte gUnknown_202B030
	thumb_func_end sub_80078A4

	thumb_func_start sub_80078E8
sub_80078E8:
	push {r4-r6,lr}
	mov r6, r8
	push {r6}
	sub sp, 0x4
	adds r5, r0, 0
	adds r6, r1, 0
	adds r4, r2, 0
	mov r8, r3
	ldr r0, [sp, 0x18]
	str r0, [sp]
	adds r0, r5, 0
	bl nullsub_129
	adds r4, 0x1
	ldr r0, _08007928
	ldr r0, [r0]
	movs r1, 0xF
	ands r0, r1
	str r0, [sp]
	adds r0, r5, 0
	adds r1, r6, 0
	adds r2, r4, 0
	mov r3, r8
	bl nullsub_129
	add sp, 0x4
	pop {r3}
	mov r8, r3
	pop {r4-r6}
	pop {r0}
	bx r0
	.align 2, 0
_08007928: .4byte gUnknown_202B030
	thumb_func_end sub_80078E8

	thumb_func_start sub_800792C
sub_800792C:
	push {r4-r6,lr}
	sub sp, 0x8
	adds r4, r0, 0
	adds r5, r1, 0
	adds r6, r2, 0
	ldr r1, [sp, 0x18]
	ldr r0, _08007950
	str r3, [sp]
	str r1, [sp, 0x4]
	adds r1, r4, 0
	adds r2, r5, 0
	adds r3, r6, 0
	bl sub_8007958
	add sp, 0x8
	pop {r4-r6}
	pop {r0}
	bx r0
	.align 2, 0
_08007950: .4byte gUnknown_2027370
	thumb_func_end sub_800792C

	thumb_func_start nullsub_129
nullsub_129:
	bx lr
	thumb_func_end nullsub_129

	thumb_func_start sub_8007958
sub_8007958:
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	sub sp, 0x24
	mov r8, r2
	adds r7, r3, 0
	ldr r2, [sp, 0x40]
	mov r12, r2
	ldr r3, [sp, 0x44]
	lsls r2, r1, 3
	adds r2, r1
	lsls r2, 3
	adds r5, r0, r2
	ldr r1, _08007A68
	movs r0, 0xF
	ands r3, r0
	lsls r3, 2
	adds r3, r1
	ldr r3, [r3]
	mov r9, r3
	adds r0, r7, 0
	cmp r7, 0
	bge _0800798A
	adds r0, r7, 0x7
_0800798A:
	asrs r4, r0, 3
	movs r1, 0x4
	ldrsh r0, [r5, r1]
	muls r0, r4
	mov r2, r8
	cmp r2, 0
	bge _0800799A
	adds r2, 0x7
_0800799A:
	asrs r2, 3
	adds r0, r2
	lsls r0, 5
	ldr r1, [r5, 0x18]
	adds r3, r1, r0
	lsls r0, r4, 3
	subs r0, r7, r0
	lsls r0, 2
	adds r3, r0
	adds r6, r2, 0
	movs r2, 0x8
	ldrsh r0, [r5, r2]
	cmp r4, r0
	bge _08007A58
	mov r1, sp
	ldr r0, _08007A6C
	ldm r0!, {r2,r4,r7}
	stm r1!, {r2,r4,r7}
	ldm r0!, {r2,r4,r7}
	stm r1!, {r2,r4,r7}
	ldm r0!, {r2,r4,r7}
	stm r1!, {r2,r4,r7}
	mov r4, r12
	cmp r4, 0
	ble _08007A58
	ldr r7, _08007A70
_080079CE:
	mov r1, r12
	cmp r1, 0x7
	ble _080079D6
	movs r1, 0x8
_080079D6:
	mov r0, r8
	cmp r0, 0
	bge _080079DE
	adds r0, 0x7
_080079DE:
	asrs r0, 3
	lsls r0, 3
	mov r2, r8
	subs r0, r2, r0
	lsls r0, 4
	adds r4, r0, r7
	lsls r0, r1, 2
	add r0, sp
	ldr r2, [r0]
	ldr r1, _08007A74
	ands r1, r2
	mov r0, r9
	ands r0, r2
	adds r2, r1, r0
	cmp r2, 0
	beq _08007A48
	movs r1, 0x4
	ldrsh r0, [r5, r1]
	cmp r6, r0
	bge _08007A24
	ldr r1, [r4]
	ands r1, r2
	ldr r0, [r4, 0x8]
	lsls r1, r0
	ldr r0, [r3]
	orrs r0, r1
	str r0, [r3]
	ldr r0, [r5, 0x3C]
	cmp r0, r3
	bls _08007A1C
	str r3, [r5, 0x3C]
_08007A1C:
	ldr r0, [r5, 0x40]
	cmp r0, r3
	bcs _08007A24
	str r3, [r5, 0x40]
_08007A24:
	movs r1, 0x4
	ldrsh r0, [r5, r1]
	subs r0, 0x1
	cmp r6, r0
	bge _08007A48
	adds r3, 0x20
	ldr r0, [r4, 0x4]
	ands r2, r0
	ldr r0, [r4, 0xC]
	lsrs r2, r0
	ldr r0, [r3]
	orrs r0, r2
	str r0, [r3]
	ldr r0, [r5, 0x40]
	cmp r0, r3
	bcs _08007A46
	str r3, [r5, 0x40]
_08007A46:
	subs r3, 0x20
_08007A48:
	adds r6, 0x1
	adds r3, 0x20
	movs r2, 0x8
	negs r2, r2
	add r12, r2
	mov r4, r12
	cmp r4, 0
	bgt _080079CE
_08007A58:
	add sp, 0x24
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_08007A68: .4byte gUnknown_80B853C
_08007A6C: .4byte gUnknown_80B8824
_08007A70: .4byte gUnknown_80B85DC
_08007A74: .4byte 0x11111111
	thumb_func_end sub_8007958

	thumb_func_start sub_8007A78
sub_8007A78:
	push {r4-r6,lr}
	sub sp, 0x8
	adds r4, r0, 0
	adds r5, r1, 0
	adds r6, r2, 0
	ldr r1, [sp, 0x18]
	ldr r0, _08007A9C
	str r3, [sp]
	str r1, [sp, 0x4]
	adds r1, r4, 0
	adds r2, r5, 0
	adds r3, r6, 0
	bl sub_8007AA4
	add sp, 0x8
	pop {r4-r6}
	pop {r0}
	bx r0
	.align 2, 0
_08007A9C: .4byte gUnknown_2027370
	thumb_func_end sub_8007A78

	thumb_func_start nullsub_157
nullsub_157:
	bx lr
	thumb_func_end nullsub_157

	thumb_func_start sub_8007AA4
sub_8007AA4:
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	sub sp, 0x20
	mov r9, r2
	adds r5, r3, 0
	ldr r7, [sp, 0x3C]
	ldr r3, [sp, 0x40]
	lsls r2, r1, 3
	adds r2, r1
	lsls r2, 3
	adds r4, r0, r2
	ldr r1, _08007B28
	movs r0, 0xF
	ands r3, r0
	lsls r3, 2
	adds r3, r1
	ldr r0, [r3]
	ldr r1, _08007B2C
	adds r1, r0
	mov r12, r1
	mov r1, sp
	ldr r0, _08007B30
	ldm r0!, {r2,r3,r6}
	stm r1!, {r2,r3,r6}
	ldm r0!, {r2,r3,r6}
	stm r1!, {r2,r3,r6}
	ldm r0!, {r2,r3}
	stm r1!, {r2,r3}
	adds r0, r5, 0
	cmp r5, 0
	bge _08007AE8
	adds r0, r5, 0x7
_08007AE8:
	asrs r3, r0, 3
	movs r0, 0x4
	ldrsh r6, [r4, r0]
	mov r8, r6
	mov r0, r8
	muls r0, r3
	mov r2, r9
	cmp r2, 0
	bge _08007AFC
	adds r2, 0x7
_08007AFC:
	asrs r2, 3
	adds r0, r2
	lsls r0, 5
	ldr r1, [r4, 0x18]
	adds r1, r0
	lsls r0, r3, 3
	subs r0, r5, r0
	lsls r0, 2
	adds r1, r0
	movs r0, 0x7
	mov r6, r9
	ands r0, r6
	lsls r0, 2
	add r0, sp
	ldr r0, [r0]
	mov r6, r12
	ands r6, r0
	mov r12, r6
	cmp r2, r8
	bge _08007B6E
	b _08007B48
	.align 2, 0
_08007B28: .4byte gUnknown_80B853C
_08007B2C: .4byte 0x11111111
_08007B30: .4byte gUnknown_80B8848
_08007B34:
	adds r5, 0x1
	adds r1, 0x4
	movs r0, 0x7
	ands r0, r5
	cmp r0, 0
	bne _08007B46
	ldr r0, [r4, 0x20]
	lsls r0, 2
	adds r1, r0
_08007B46:
	subs r7, 0x1
_08007B48:
	cmp r7, 0
	ble _08007B6E
	movs r2, 0x8
	ldrsh r0, [r4, r2]
	cmp r3, r0
	bge _08007B6E
	ldr r0, [r1]
	mov r6, r12
	orrs r0, r6
	str r0, [r1]
	ldr r0, [r4, 0x3C]
	cmp r0, r1
	bls _08007B64
	str r1, [r4, 0x3C]
_08007B64:
	ldr r0, [r4, 0x40]
	cmp r0, r1
	bcs _08007B34
	str r1, [r4, 0x40]
	b _08007B34
_08007B6E:
	add sp, 0x20
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_8007AA4

	thumb_func_start sub_8007B7C
sub_8007B7C:
	push {r4-r6,lr}
	sub sp, 0x8
	adds r4, r0, 0
	adds r5, r1, 0
	adds r6, r2, 0
	ldr r1, [sp, 0x18]
	ldr r0, _08007BA0
	str r3, [sp]
	str r1, [sp, 0x4]
	adds r1, r4, 0
	adds r2, r5, 0
	adds r3, r6, 0
	bl sub_8007BA8
	add sp, 0x8
	pop {r4-r6}
	pop {r0}
	bx r0
	.align 2, 0
_08007BA0: .4byte gUnknown_2027370
	thumb_func_end sub_8007B7C

	thumb_func_start nullsub_158
nullsub_158:
	bx lr
	thumb_func_end nullsub_158

	thumb_func_start sub_8007BA8
sub_8007BA8:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x20
	str r2, [sp]
	lsls r2, r1, 3
	adds r2, r1
	lsls r2, 3
	adds r0, r2
	mov r12, r0
	adds r0, r3, 0
	cmp r3, 0
	bge _08007BC8
	adds r0, r3, 0x7
_08007BC8:
	asrs r0, 3
	str r0, [sp, 0x8]
	mov r1, r12
	movs r2, 0x8
	ldrsh r0, [r1, r2]
	ldr r4, [sp, 0x8]
	cmp r4, r0
	bge _08007CC4
	movs r7, 0x4
	ldrsh r0, [r1, r7]
	adds r1, r4, 0
	muls r1, r0
	ldr r0, [sp]
	cmp r0, 0
	bge _08007BE8
	adds r0, 0x7
_08007BE8:
	asrs r0, 3
	adds r0, r1, r0
	lsls r0, 5
	mov r2, r12
	ldr r1, [r2, 0x18]
	adds r4, r1, r0
	ldr r7, [sp, 0x8]
	lsls r0, r7, 3
	subs r0, r3, r0
	lsls r0, 2
	adds r4, r0
	movs r0, 0
	str r0, [sp, 0x4]
	ldr r1, [sp, 0x44]
	cmp r0, r1
	bge _08007CC4
_08007C08:
	adds r2, r4, 0
	ldr r0, [sp]
	cmp r0, 0
	bge _08007C12
	adds r0, 0x7
_08007C12:
	asrs r1, r0, 3
	movs r7, 0
	mov r8, r7
	adds r3, 0x1
	str r3, [sp, 0xC]
	adds r4, 0x4
	str r4, [sp, 0x14]
	ldr r0, [sp, 0x40]
	cmp r8, r0
	bge _08007C94
_08007C26:
	mov r3, r12
	movs r4, 0x4
	ldrsh r0, [r3, r4]
	cmp r1, r0
	bge _08007C94
	movs r6, 0xF0
	lsls r6, 24
	movs r5, 0xE0
	lsls r5, 24
	movs r7, 0
	str r7, [sp, 0x1C]
	ldr r4, [r2]
	adds r3, r4, 0
	mov r0, r12
	ldr r0, [r0, 0x3C]
	mov r9, r0
	mov r7, r12
	ldr r7, [r7, 0x40]
	mov r10, r7
	adds r1, 0x1
	str r1, [sp, 0x10]
	adds r0, r2, 0
	adds r0, 0x20
	str r0, [sp, 0x18]
	movs r1, 0x8
	add r8, r1
	movs r1, 0x7
_08007C5C:
	adds r0, r4, 0
	ands r0, r6
	cmp r0, 0
	bne _08007C6A
	ldr r7, [sp, 0x1C]
	orrs r7, r5
	str r7, [sp, 0x1C]
_08007C6A:
	lsrs r6, 4
	lsrs r5, 4
	subs r1, 0x1
	cmp r1, 0
	bge _08007C5C
	ldr r0, [sp, 0x1C]
	orrs r3, r0
	str r3, [r2]
	cmp r9, r2
	bls _08007C82
	mov r1, r12
	str r2, [r1, 0x3C]
_08007C82:
	cmp r10, r2
	bcs _08007C8A
	mov r3, r12
	str r2, [r3, 0x40]
_08007C8A:
	ldr r1, [sp, 0x10]
	ldr r2, [sp, 0x18]
	ldr r4, [sp, 0x40]
	cmp r8, r4
	blt _08007C26
_08007C94:
	ldr r3, [sp, 0xC]
	ldr r4, [sp, 0x14]
	movs r0, 0x7
	ands r0, r3
	cmp r0, 0
	bne _08007CB8
	mov r7, r12
	ldr r0, [r7, 0x20]
	lsls r0, 2
	adds r4, r0
	ldr r0, [sp, 0x8]
	adds r0, 0x1
	str r0, [sp, 0x8]
	movs r1, 0x8
	ldrsh r0, [r7, r1]
	ldr r2, [sp, 0x8]
	cmp r2, r0
	bge _08007CC4
_08007CB8:
	ldr r7, [sp, 0x4]
	adds r7, 0x1
	str r7, [sp, 0x4]
	ldr r0, [sp, 0x44]
	cmp r7, r0
	blt _08007C08
_08007CC4:
	add sp, 0x20
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_8007BA8

	thumb_func_start sub_8007CD4
sub_8007CD4:
	push {r4-r6,lr}
	sub sp, 0x8
	adds r4, r0, 0
	adds r5, r1, 0
	adds r6, r2, 0
	ldr r1, [sp, 0x18]
	ldr r0, _08007CF8
	str r3, [sp]
	str r1, [sp, 0x4]
	adds r1, r4, 0
	adds r2, r5, 0
	adds r3, r6, 0
	bl sub_8007D00
	add sp, 0x8
	pop {r4-r6}
	pop {r0}
	bx r0
	.align 2, 0
_08007CF8: .4byte gUnknown_2027370
	thumb_func_end sub_8007CD4

	thumb_func_start nullsub_159
nullsub_159:
	bx lr
	thumb_func_end nullsub_159

	thumb_func_start sub_8007D00
sub_8007D00:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x20
	str r2, [sp]
	lsls r2, r1, 3
	adds r2, r1
	lsls r2, 3
	adds r0, r2
	mov r12, r0
	adds r0, r3, 0
	cmp r3, 0
	bge _08007D20
	adds r0, r3, 0x7
_08007D20:
	asrs r0, 3
	str r0, [sp, 0x8]
	mov r1, r12
	movs r2, 0x8
	ldrsh r0, [r1, r2]
	ldr r4, [sp, 0x8]
	cmp r4, r0
	bge _08007E0E
	movs r5, 0x4
	ldrsh r0, [r1, r5]
	adds r1, r4, 0
	muls r1, r0
	ldr r0, [sp]
	cmp r0, 0
	bge _08007D40
	adds r0, 0x7
_08007D40:
	asrs r0, 3
	adds r0, r1, r0
	lsls r0, 5
	mov r2, r12
	ldr r1, [r2, 0x18]
	adds r4, r1, r0
	ldr r5, [sp, 0x8]
	lsls r0, r5, 3
	subs r0, r3, r0
	lsls r0, 2
	adds r4, r0
	movs r0, 0
	b _08007E06
_08007D5A:
	adds r2, r4, 0
	ldr r0, [sp]
	cmp r0, 0
	bge _08007D64
	adds r0, 0x7
_08007D64:
	asrs r1, r0, 3
	movs r5, 0
	mov r8, r5
	adds r3, 0x1
	str r3, [sp, 0xC]
	adds r4, 0x4
	str r4, [sp, 0x14]
	ldr r0, [sp, 0x40]
	cmp r8, r0
	bge _08007DE0
_08007D78:
	mov r3, r12
	movs r4, 0x4
	ldrsh r0, [r3, r4]
	cmp r1, r0
	bge _08007DE0
	movs r4, 0xF0
	lsls r4, 24
	movs r6, 0xE0
	lsls r6, 24
	movs r7, 0
	ldr r5, [r2]
	str r5, [sp, 0x1C]
	adds r3, r5, 0
	mov r0, r12
	ldr r0, [r0, 0x3C]
	mov r9, r0
	mov r5, r12
	ldr r5, [r5, 0x40]
	mov r10, r5
	adds r1, 0x1
	str r1, [sp, 0x10]
	adds r0, r2, 0
	adds r0, 0x20
	str r0, [sp, 0x18]
	movs r1, 0x8
	add r8, r1
	movs r1, 0x7
_08007DAE:
	ldr r0, [sp, 0x1C]
	ands r0, r4
	cmp r0, r6
	bne _08007DB8
	orrs r7, r4
_08007DB8:
	lsrs r4, 4
	lsrs r6, 4
	subs r1, 0x1
	cmp r1, 0
	bge _08007DAE
	bics r3, r7
	str r3, [r2]
	cmp r9, r2
	bls _08007DCE
	mov r3, r12
	str r2, [r3, 0x3C]
_08007DCE:
	cmp r10, r2
	bcs _08007DD6
	mov r4, r12
	str r2, [r4, 0x40]
_08007DD6:
	ldr r1, [sp, 0x10]
	ldr r2, [sp, 0x18]
	ldr r5, [sp, 0x40]
	cmp r8, r5
	blt _08007D78
_08007DE0:
	ldr r3, [sp, 0xC]
	ldr r4, [sp, 0x14]
	movs r0, 0x7
	ands r0, r3
	cmp r0, 0
	bne _08007E02
	mov r1, r12
	ldr r0, [r1, 0x20]
	lsls r0, 2
	adds r4, r0
	ldr r2, [sp, 0x8]
	adds r2, 0x1
	str r2, [sp, 0x8]
	movs r5, 0x8
	ldrsh r0, [r1, r5]
	cmp r2, r0
	bge _08007E0E
_08007E02:
	ldr r0, [sp, 0x4]
	adds r0, 0x1
_08007E06:
	str r0, [sp, 0x4]
	ldr r1, [sp, 0x44]
	cmp r0, r1
	blt _08007D5A
_08007E0E:
	add sp, 0x20
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_8007D00

	thumb_func_start sub_8007E20
sub_8007E20:
	push {r4-r6,lr}
	mov r6, r9
	mov r5, r8
	push {r5,r6}
	sub sp, 0x14
	mov r8, r0
	mov r9, r1
	ldr r4, [sp, 0x2C]
	ldr r5, [sp, 0x30]
	ldr r6, [sp, 0x34]
	ldr r0, _08007E58
	ldr r1, _08007E5C
	str r2, [sp]
	str r3, [sp, 0x4]
	str r4, [sp, 0x8]
	str r5, [sp, 0xC]
	str r6, [sp, 0x10]
	mov r2, r8
	mov r3, r9
	bl sub_8007E64
	add sp, 0x14
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r6}
	pop {r0}
	bx r0
	.align 2, 0
_08007E58: .4byte gUnknown_2027370
_08007E5C: .4byte gUnknown_202B038
	thumb_func_end sub_8007E20

	thumb_func_start nullsub_160
nullsub_160:
	bx lr
	thumb_func_end nullsub_160

	thumb_func_start sub_8007E64
sub_8007E64:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x10
	str r1, [sp]
	str r3, [sp, 0x4]
	ldr r7, [sp, 0x30]
	ldr r1, [sp, 0x34]
	mov r9, r1
	ldr r1, [sp, 0x38]
	mov r10, r1
	ldr r5, [sp, 0x3C]
	lsls r1, r2, 3
	adds r1, r2
	lsls r1, 3
	adds r4, r0, r1
	adds r0, r3, 0
	cmp r0, 0
	bge _08007E90
	adds r0, 0x7
_08007E90:
	asrs r0, 3
	str r0, [sp, 0x4]
	adds r0, r7, 0
	cmp r7, 0
	bge _08007E9C
	adds r0, r7, 0x7
_08007E9C:
	asrs r7, r0, 3
	mov r0, r9
	cmp r0, 0
	bge _08007EA6
	adds r0, 0x7
_08007EA6:
	asrs r0, 3
	mov r9, r0
	mov r0, r10
	cmp r0, 0
	bge _08007EB2
	adds r0, 0x7
_08007EB2:
	asrs r0, 3
	mov r10, r0
	ldr r2, [sp, 0x40]
	lsls r2, 12
	str r2, [sp, 0x40]
	movs r1, 0x8
	ldrsh r0, [r4, r1]
	cmp r7, r0
	bge _08007F98
	movs r2, 0x4
	ldrsh r0, [r4, r2]
	muls r0, r7
	ldr r1, [sp, 0x4]
	adds r0, r1
	lsls r0, 5
	ldr r1, [r4, 0x18]
	adds r1, r0
	mov r8, r1
	movs r2, 0
	b _08007F92
_08007EDA:
	ldr r6, [sp, 0x4]
	mov r3, r8
	adds r0, r7, 0x1
	str r0, [sp, 0xC]
	mov r1, r9
	cmp r1, 0
	ble _08007F7A
	mov r12, r9
_08007EEA:
	movs r2, 0x4
	ldrsh r0, [r4, r2]
	cmp r6, r0
	bge _08007F68
	ldr r0, [r4, 0x3C]
	cmp r0, r3
	bls _08007EFA
	str r3, [r4, 0x3C]
_08007EFA:
	ldm r5!, {r0}
	stm r3!, {r0}
	ldm r5!, {r0}
	stm r3!, {r0}
	ldm r5!, {r0}
	stm r3!, {r0}
	ldm r5!, {r0}
	stm r3!, {r0}
	ldm r5!, {r0}
	stm r3!, {r0}
	ldm r5!, {r0}
	stm r3!, {r0}
	ldm r5!, {r0}
	stm r3!, {r0}
	ldr r0, [r5]
	stm r3!, {r0}
	ldr r0, [r4, 0x40]
	cmp r0, r3
	bcs _08007F22
	str r3, [r4, 0x40]
_08007F22:
	adds r5, 0x4
	movs r1, 0x2
	ldrsh r0, [r4, r1]
	adds r0, r7
	movs r2, 0
	ldrsh r1, [r4, r2]
	adds r1, r6
	lsls r1, 1
	lsls r0, 6
	ldr r2, [sp]
	adds r0, r2
	adds r1, r0
	ldrh r2, [r1]
	ldr r0, _08007F64
	ands r0, r2
	strh r0, [r1]
	movs r1, 0x2
	ldrsh r0, [r4, r1]
	adds r0, r7
	movs r2, 0
	ldrsh r1, [r4, r2]
	adds r1, r6
	lsls r1, 1
	lsls r0, 6
	ldr r2, [sp]
	adds r0, r2
	adds r1, r0
	ldrh r2, [r1]
	ldr r0, [sp, 0x40]
	orrs r0, r2
	strh r0, [r1]
	b _08007F6C
	.align 2, 0
_08007F64: .4byte 0x00000fff
_08007F68:
	adds r3, 0x20
	adds r5, 0x20
_08007F6C:
	adds r6, 0x1
	movs r0, 0x1
	negs r0, r0
	add r12, r0
	mov r1, r12
	cmp r1, 0
	bne _08007EEA
_08007F7A:
	ldr r7, [sp, 0xC]
	ldr r0, [r4, 0x20]
	lsls r0, 2
	add r8, r0
	movs r2, 0x20
	add r8, r2
	movs r1, 0x8
	ldrsh r0, [r4, r1]
	cmp r7, r0
	bge _08007F98
	ldr r2, [sp, 0x8]
	adds r2, 0x1
_08007F92:
	str r2, [sp, 0x8]
	cmp r2, r10
	blt _08007EDA
_08007F98:
	add sp, 0x10
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_8007E64

	thumb_func_start sub_8007FA8
sub_8007FA8:
	adds r3, r0, 0
	lsrs r0, r3, 28
	lsrs r1, r3, 20
	movs r2, 0xF0
	ands r1, r2
	orrs r0, r1
	lsrs r1, r3, 12
	movs r2, 0xF0
	lsls r2, 4
	ands r1, r2
	orrs r0, r1
	lsrs r1, r3, 4
	movs r2, 0xF0
	lsls r2, 8
	ands r1, r2
	orrs r0, r1
	lsls r1, r3, 4
	movs r2, 0xF0
	lsls r2, 12
	ands r1, r2
	orrs r0, r1
	lsls r1, r3, 12
	movs r2, 0xF0
	lsls r2, 16
	ands r1, r2
	orrs r0, r1
	lsls r1, r3, 20
	movs r2, 0xF0
	lsls r2, 20
	ands r1, r2
	orrs r0, r1
	lsls r3, 28
	orrs r0, r3
	bx lr
	thumb_func_end sub_8007FA8

	thumb_func_start sub_8007FEC
sub_8007FEC:
	push {r4-r6,lr}
	mov r6, r9
	mov r5, r8
	push {r5,r6}
	sub sp, 0x14
	mov r8, r0
	mov r9, r1
	ldr r4, [sp, 0x2C]
	ldr r5, [sp, 0x30]
	ldr r6, [sp, 0x34]
	ldr r0, _08008024
	ldr r1, _08008028
	str r2, [sp]
	str r3, [sp, 0x4]
	str r4, [sp, 0x8]
	str r5, [sp, 0xC]
	str r6, [sp, 0x10]
	mov r2, r8
	mov r3, r9
	bl sub_8008030
	add sp, 0x14
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r6}
	pop {r0}
	bx r0
	.align 2, 0
_08008024: .4byte gUnknown_2027370
_08008028: .4byte gUnknown_202B038
	thumb_func_end sub_8007FEC

	thumb_func_start nullsub_161
nullsub_161:
	bx lr
	thumb_func_end nullsub_161

	thumb_func_start sub_8008030
sub_8008030:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x10
	str r1, [sp]
	ldr r1, [sp, 0x30]
	mov r8, r1
	ldr r6, [sp, 0x3C]
	lsls r1, r2, 3
	adds r1, r2
	lsls r1, 3
	adds r5, r0, r1
	adds r0, r3, 0
	cmp r3, 0
	bge _08008054
	adds r0, r3, 0x7
_08008054:
	asrs r3, r0, 3
	mov r0, r8
	cmp r0, 0
	bge _0800805E
	adds r0, 0x7
_0800805E:
	asrs r0, 3
	mov r8, r0
	ldr r0, [sp, 0x34]
	cmp r0, 0
	bge _0800806A
	adds r0, 0x7
_0800806A:
	asrs r0, 3
	str r0, [sp, 0x34]
	ldr r0, [sp, 0x38]
	cmp r0, 0
	bge _08008076
	adds r0, 0x7
_08008076:
	asrs r0, 3
	str r0, [sp, 0x38]
	ldr r2, [sp, 0x40]
	lsls r2, 12
	str r2, [sp, 0x40]
	movs r1, 0x8
	ldrsh r0, [r5, r1]
	cmp r8, r0
	blt _0800808A
	b _08008194
_0800808A:
	movs r2, 0x4
	ldrsh r0, [r5, r2]
	mov r1, r8
	muls r1, r0
	adds r0, r1, 0
	ldr r1, [sp, 0x34]
	adds r2, r3, r1
	adds r0, r2
	lsls r0, 5
	ldr r1, [r5, 0x18]
	adds r1, r0
	mov r10, r1
	movs r3, 0
	str r3, [sp, 0x4]
	str r2, [sp, 0xC]
	ldr r0, [sp, 0x38]
	cmp r3, r0
	bge _08008194
_080080AE:
	ldr r7, [sp, 0xC]
	mov r4, r10
	mov r1, r8
	adds r1, 0x1
	str r1, [sp, 0x8]
	ldr r2, [sp, 0x34]
	cmp r2, 0
	ble _08008172
	mov r9, r2
_080080C0:
	subs r7, 0x1
	subs r4, 0x20
	movs r3, 0x4
	ldrsh r0, [r5, r3]
	cmp r7, r0
	bge _08008164
	ldr r0, [r5, 0x3C]
	cmp r0, r4
	bls _080080D4
	str r4, [r5, 0x3C]
_080080D4:
	ldm r6!, {r0}
	bl sub_8007FA8
	str r0, [r4]
	ldm r6!, {r0}
	bl sub_8007FA8
	str r0, [r4, 0x4]
	ldm r6!, {r0}
	bl sub_8007FA8
	str r0, [r4, 0x8]
	ldm r6!, {r0}
	bl sub_8007FA8
	str r0, [r4, 0xC]
	ldm r6!, {r0}
	bl sub_8007FA8
	str r0, [r4, 0x10]
	ldm r6!, {r0}
	bl sub_8007FA8
	str r0, [r4, 0x14]
	ldm r6!, {r0}
	bl sub_8007FA8
	str r0, [r4, 0x18]
	ldm r6!, {r0}
	bl sub_8007FA8
	str r0, [r4, 0x1C]
	adds r1, r4, 0
	adds r1, 0x20
	ldr r0, [r5, 0x40]
	cmp r0, r1
	bcs _08008120
	str r1, [r5, 0x40]
_08008120:
	movs r1, 0x2
	ldrsh r0, [r5, r1]
	add r0, r8
	movs r2, 0
	ldrsh r1, [r5, r2]
	adds r1, r7
	lsls r1, 1
	lsls r0, 6
	ldr r3, [sp]
	adds r0, r3
	adds r1, r0
	ldrh r0, [r1]
	ldr r3, _08008160
	adds r2, r3, 0
	ands r0, r2
	strh r0, [r1]
	movs r1, 0x2
	ldrsh r0, [r5, r1]
	add r0, r8
	movs r2, 0
	ldrsh r1, [r5, r2]
	adds r1, r7
	lsls r1, 1
	lsls r0, 6
	ldr r3, [sp]
	adds r0, r3
	adds r1, r0
	ldrh r2, [r1]
	ldr r0, [sp, 0x40]
	orrs r0, r2
	strh r0, [r1]
	b _08008166
	.align 2, 0
_08008160: .4byte 0x00000fff
_08008164:
	adds r6, 0x20
_08008166:
	movs r0, 0x1
	negs r0, r0
	add r9, r0
	mov r1, r9
	cmp r1, 0
	bne _080080C0
_08008172:
	ldr r2, [sp, 0x8]
	mov r8, r2
	ldr r0, [r5, 0x20]
	lsls r0, 2
	add r10, r0
	movs r3, 0x20
	add r10, r3
	movs r1, 0x8
	ldrsh r0, [r5, r1]
	cmp r8, r0
	bge _08008194
	ldr r2, [sp, 0x4]
	adds r2, 0x1
	str r2, [sp, 0x4]
	ldr r3, [sp, 0x38]
	cmp r2, r3
	blt _080080AE
_08008194:
	add sp, 0x10
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_8008030

	thumb_func_start sub_80081A4
sub_80081A4:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x4
	str r1, [sp]
	lsls r1, r0, 3
	adds r1, r0
	lsls r1, 3
	ldr r0, _08008234
	adds r6, r1, r0
	lsls r3, 7
	ldr r0, _08008238
	adds r3, r0
	ldr r0, [sp]
	cmp r0, 0
	bge _080081CA
	adds r0, 0x7
_080081CA:
	asrs r0, 3
	str r0, [sp]
	adds r0, r2, 0
	cmp r2, 0
	bge _080081D6
	adds r0, r2, 0x7
_080081D6:
	asrs r2, r0, 3
	movs r0, 0x2
	mov r9, r0
	mov r10, r0
	movs r1, 0x8
	ldrsh r0, [r6, r1]
	cmp r2, r0
	bge _08008262
	movs r7, 0x4
	ldrsh r0, [r6, r7]
	muls r0, r2
	ldr r1, [sp]
	adds r0, r1
	lsls r0, 5
	ldr r1, [r6, 0x28]
	adds r5, r1, r0
	movs r7, 0
	mov r8, r7
_080081FA:
	ldr r4, [sp]
	adds r1, r5, 0
	adds r2, 0x1
	mov r12, r2
	mov r0, r9
	cmp r0, 0
	beq _08008248
	mov r2, r9
_0800820A:
	movs r7, 0x4
	ldrsh r0, [r6, r7]
	cmp r4, r0
	bge _0800823C
	ldm r3!, {r0}
	stm r1!, {r0}
	ldm r3!, {r0}
	stm r1!, {r0}
	ldm r3!, {r0}
	stm r1!, {r0}
	ldm r3!, {r0}
	stm r1!, {r0}
	ldm r3!, {r0}
	stm r1!, {r0}
	ldm r3!, {r0}
	stm r1!, {r0}
	ldm r3!, {r0}
	stm r1!, {r0}
	ldm r3!, {r0}
	stm r1!, {r0}
	b _08008240
	.align 2, 0
_08008234: .4byte gUnknown_2027370
_08008238: .4byte gUnknown_80B86B4
_0800823C:
	adds r1, 0x20
	adds r3, 0x20
_08008240:
	adds r4, 0x1
	subs r2, 0x1
	cmp r2, 0
	bne _0800820A
_08008248:
	mov r2, r12
	ldr r0, [r6, 0x20]
	lsls r0, 2
	adds r5, r0
	adds r5, 0x20
	movs r1, 0x8
	ldrsh r0, [r6, r1]
	cmp r2, r0
	bge _08008262
	movs r7, 0x1
	add r8, r7
	cmp r8, r10
	blt _080081FA
_08008262:
	add sp, 0x4
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_80081A4

	thumb_func_start sub_8008274
sub_8008274:
	push {r4,lr}
	sub sp, 0x4
	adds r4, r0, 0
	adds r3, r1, 0
	ldr r0, _08008290
	ldr r1, _08008294
	str r2, [sp]
	adds r2, r4, 0
	bl sub_800829C
	add sp, 0x4
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08008290: .4byte gUnknown_2027370
_08008294: .4byte gUnknown_202B038
	thumb_func_end sub_8008274

	thumb_func_start nullsub_162
nullsub_162:
	bx lr
	thumb_func_end nullsub_162

	thumb_func_start sub_800829C
sub_800829C:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	mov r8, r1
	ldr r7, [sp, 0x18]
	lsls r1, r2, 3
	adds r1, r2
	lsls r1, 3
	adds r4, r0, r1
	lsls r7, 12
	ldr r0, [r4, 0x18]
	movs r1, 0x4
	ldrsh r2, [r4, r1]
	movs r5, 0x8
	ldrsh r1, [r4, r5]
	lsls r1, 5
	muls r1, r2
	adds r2, r3, 0
	bl sub_800AAB4
	movs r2, 0
	movs r1, 0x8
	ldrsh r0, [r4, r1]
	cmp r2, r0
	bge _08008312
	movs r0, 0x4
	ldrsh r5, [r4, r0]
	mov r12, r5
_080082D4:
	adds r5, r2, 0x1
	mov r1, r12
	cmp r1, 0
	ble _08008308
	movs r0, 0x2
	ldrsh r1, [r4, r0]
	adds r1, r2
	movs r2, 0
	ldrsh r0, [r4, r2]
	lsls r1, 6
	ldr r6, _08008330
	lsls r0, 1
	adds r0, r1
	mov r1, r8
	adds r2, r0, r1
	movs r0, 0x4
	ldrsh r3, [r4, r0]
_080082F6:
	ldrh r1, [r2]
	adds r0, r6, 0
	ands r0, r1
	orrs r0, r7
	strh r0, [r2]
	adds r2, 0x2
	subs r3, 0x1
	cmp r3, 0
	bne _080082F6
_08008308:
	adds r2, r5, 0
	movs r1, 0x8
	ldrsh r0, [r4, r1]
	cmp r2, r0
	blt _080082D4
_08008312:
	ldr r0, [r4, 0x28]
	str r0, [r4, 0x30]
	ldr r0, [r4, 0x1C]
	str r0, [r4, 0x34]
	ldr r0, [r4, 0x2C]
	str r0, [r4, 0x38]
	adds r1, r4, 0
	adds r1, 0x44
	movs r0, 0x1
	strb r0, [r1]
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_08008330: .4byte 0x00000fff
	thumb_func_end sub_800829C

	thumb_func_start sub_8008334
sub_8008334:
	push {r4-r7,lr}
	adds r7, r0, 0
	mov r12, r1
	ldr r4, [r7]
	ldr r1, [r1]
	movs r3, 0
	movs r2, 0
	movs r6, 0xF
	movs r5, 0x1C
_08008346:
	lsls r2, 4
	lsls r3, 4
	adds r0, r4, 0
	ands r0, r6
	orrs r2, r0
	adds r0, r1, 0
	ands r0, r6
	orrs r3, r0
	lsrs r4, 4
	lsrs r1, 4
	subs r5, 0x4
	cmp r5, 0
	bge _08008346
	str r3, [r7]
	mov r0, r12
	str r2, [r0]
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_8008334

	thumb_func_start sub_800836C
sub_800836C:
	push {r4,r5,lr}
	adds r4, r0, 0
	adds r5, r1, 0
	adds r3, r2, 0
	ldr r0, _08008384
	adds r1, r4, 0
	adds r2, r5, 0
	bl sub_800838C
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_08008384: .4byte gUnknown_2027370
	thumb_func_end sub_800836C

	thumb_func_start nullsub_163
nullsub_163:
	bx lr
	thumb_func_end nullsub_163

	thumb_func_start sub_800838C
sub_800838C:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	lsls r4, r1, 3
	adds r4, r1
	lsls r4, 3
	adds r7, r0, r4
	adds r0, r1, 0
	adds r1, r2, 0
	adds r2, r3, 0
	bl sub_8008274
	movs r0, 0
	mov r9, r0
	b _08008452
_080083AE:
	movs r1, 0x4
	ldrsh r0, [r7, r1]
	lsrs r1, r0, 31
	adds r0, r1
	asrs r0, 1
	mov r8, r0
	ldrh r1, [r7, 0x4]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _080083C8
	movs r0, 0x1
	add r8, r0
_080083C8:
	movs r6, 0
	movs r1, 0x1
	add r1, r9
	mov r10, r1
	cmp r6, r8
	bge _08008450
_080083D4:
	movs r0, 0x4
	ldrsh r1, [r7, r0]
	mov r0, r9
	muls r0, r1
	adds r4, r0, r6
	lsls r4, 5
	ldr r5, [r7, 0x18]
	adds r4, r5, r4
	subs r0, 0x1
	subs r1, r6
	adds r0, r1
	lsls r0, 5
	adds r5, r0
	adds r0, r4, 0
	adds r4, 0x4
	adds r1, r5, 0
	adds r5, 0x4
	bl sub_8008334
	adds r0, r4, 0
	adds r4, 0x4
	adds r1, r5, 0
	adds r5, 0x4
	bl sub_8008334
	adds r0, r4, 0
	adds r4, 0x4
	adds r1, r5, 0
	adds r5, 0x4
	bl sub_8008334
	adds r0, r4, 0
	adds r4, 0x4
	adds r1, r5, 0
	adds r5, 0x4
	bl sub_8008334
	adds r0, r4, 0
	adds r4, 0x4
	adds r1, r5, 0
	adds r5, 0x4
	bl sub_8008334
	adds r0, r4, 0
	adds r4, 0x4
	adds r1, r5, 0
	adds r5, 0x4
	bl sub_8008334
	adds r0, r4, 0
	adds r4, 0x4
	adds r1, r5, 0
	adds r5, 0x4
	bl sub_8008334
	adds r0, r4, 0
	adds r1, r5, 0
	bl sub_8008334
	adds r6, 0x1
	cmp r6, r8
	blt _080083D4
_08008450:
	mov r9, r10
_08008452:
	movs r1, 0x8
	ldrsh r0, [r7, r1]
	cmp r9, r0
	blt _080083AE
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_800838C

	thumb_func_start sub_8008468
sub_8008468:
	push {r4-r6,lr}
	mov r6, r8
	push {r6}
	sub sp, 0x10
	adds r6, r0, 0
	mov r8, r1
	ldr r4, [sp, 0x24]
	ldr r5, [sp, 0x28]
	ldr r0, _08008498
	ldr r1, _0800849C
	str r2, [sp]
	str r3, [sp, 0x4]
	str r4, [sp, 0x8]
	str r5, [sp, 0xC]
	adds r2, r6, 0
	mov r3, r8
	bl sub_80084A4
	add sp, 0x10
	pop {r3}
	mov r8, r3
	pop {r4-r6}
	pop {r0}
	bx r0
	.align 2, 0
_08008498: .4byte gUnknown_2027370
_0800849C: .4byte gUnknown_202B038
	thumb_func_end sub_8008468

	thumb_func_start nullsub_164
nullsub_164:
	bx lr
	thumb_func_end nullsub_164

	thumb_func_start sub_80084A4
sub_80084A4:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x4
	str r1, [sp]
	mov r10, r3
	ldr r6, [sp, 0x24]
	ldr r7, [sp, 0x28]
	ldr r1, [sp, 0x2C]
	mov r12, r1
	lsls r1, r2, 3
	adds r1, r2
	lsls r1, 3
	adds r4, r0, r1
	mov r0, r10
	cmp r0, 0
	bge _080084CC
	adds r0, 0x7
_080084CC:
	asrs r0, 3
	mov r10, r0
	adds r0, r6, 0
	cmp r6, 0
	bge _080084D8
	adds r0, r6, 0x7
_080084D8:
	asrs r6, r0, 3
	adds r0, r7, 0
	cmp r7, 0
	bge _080084E2
	adds r0, r7, 0x7
_080084E2:
	asrs r7, r0, 3
	mov r0, r12
	cmp r0, 0
	bge _080084EC
	adds r0, 0x7
_080084EC:
	asrs r0, 3
	mov r12, r0
	ldr r2, [sp, 0x30]
	lsls r2, 12
	str r2, [sp, 0x30]
	movs r1, 0x8
	ldrsh r0, [r4, r1]
	cmp r6, r0
	bge _08008570
	movs r2, 0
	mov r8, r2
	cmp r8, r12
	bge _08008570
_08008506:
	mov r3, r10
	adds r0, r6, 0x1
	mov r9, r0
	cmp r7, 0
	ble _0800855E
	adds r5, r7, 0
_08008512:
	movs r1, 0x4
	ldrsh r0, [r4, r1]
	cmp r3, r0
	bge _08008556
	movs r2, 0x2
	ldrsh r0, [r4, r2]
	adds r0, r6
	movs r2, 0
	ldrsh r1, [r4, r2]
	adds r1, r3
	lsls r1, 1
	lsls r0, 6
	ldr r2, [sp]
	adds r0, r2
	adds r1, r0
	ldrh r2, [r1]
	ldr r0, _08008580
	ands r0, r2
	strh r0, [r1]
	movs r1, 0x2
	ldrsh r0, [r4, r1]
	adds r0, r6
	movs r2, 0
	ldrsh r1, [r4, r2]
	adds r1, r3
	lsls r1, 1
	lsls r0, 6
	ldr r2, [sp]
	adds r0, r2
	adds r1, r0
	ldrh r2, [r1]
	ldr r0, [sp, 0x30]
	orrs r0, r2
	strh r0, [r1]
_08008556:
	adds r3, 0x1
	subs r5, 0x1
	cmp r5, 0
	bne _08008512
_0800855E:
	mov r6, r9
	movs r1, 0x8
	ldrsh r0, [r4, r1]
	cmp r6, r0
	bge _08008570
	movs r2, 0x1
	add r8, r2
	cmp r8, r12
	blt _08008506
_08008570:
	add sp, 0x4
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_08008580: .4byte 0x00000fff
	thumb_func_end sub_80084A4

	thumb_func_start sub_8008584
sub_8008584:
	push {r4,r5,lr}
	adds r3, r0, 0
	ldr r1, _080085C4
	ldr r0, _080085C8
	ldr r0, [r0]
	lsls r0, 2
	adds r0, r1
	ldr r2, [r0]
	ldr r5, [r2, 0x4]
	ldr r0, _080085CC
	adds r1, r3, r0
	ldr r0, _080085D0
	cmp r1, r0
	bhi _080085D4
	movs r2, 0xFF
	ands r2, r3
	movs r1, 0xFF
	lsls r1, 8
	ands r1, r3
	asrs r1, 8
	subs r2, 0x20
	subs r1, 0xF8
	lsls r0, r1, 3
	subs r0, r1
	lsls r0, 5
	adds r0, r2
	lsls r1, r0, 1
	adds r1, r0
	lsls r1, 2
	adds r1, r5, r1
	b _08008624
	.align 2, 0
_080085C4: .4byte gKanji
_080085C8: .4byte gUnknown_20274AC
_080085CC: .4byte 0xffff0800
_080085D0: .4byte 0x000007fe
_080085D4:
	movs r4, 0
	ldr r0, [r2]
	subs r2, r0, 0x1
	cmp r4, r2
	bge _08008614
	lsrs r0, r2, 31
	adds r0, r2, r0
	b _08008602
_080085E4:
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 2
	adds r0, r5
	ldrh r0, [r0, 0x4]
	cmp r0, r3
	bge _080085F6
	adds r4, r1, 0x1
	b _080085F8
_080085F6:
	adds r2, r1, 0
_080085F8:
	cmp r4, r2
	bge _08008614
	adds r0, r4, r2
	lsrs r1, r0, 31
	adds r0, r1
_08008602:
	asrs r1, r0, 1
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 2
	adds r0, r5
	ldrh r0, [r0, 0x4]
	cmp r0, r3
	bne _080085E4
	adds r4, r1, 0
_08008614:
	lsls r0, r4, 1
	adds r0, r4
	lsls r0, 2
	adds r1, r5, r0
	ldrh r0, [r1, 0x4]
	cmp r0, r3
	beq _08008624
	ldr r1, _0800862C
_08008624:
	adds r0, r1, 0
	pop {r4,r5}
	pop {r1}
	bx r1
	.align 2, 0
_0800862C: .4byte gUnknown_80B86A4
	thumb_func_end sub_8008584

	thumb_func_start sub_8008630
sub_8008630:
	push {lr}
	lsls r0, 24
	lsrs r1, r0, 24
	adds r3, r1, 0
	adds r2, r1, 0
	subs r2, 0x30
	lsls r0, r2, 24
	lsrs r0, 24
	cmp r0, 0x9
	bhi _08008648
	adds r0, r2, 0
	b _0800865C
_08008648:
	adds r0, r1, 0
	subs r0, 0x61
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x5
	bls _08008658
	movs r0, 0x1
	b _0800865C
_08008658:
	adds r0, r3, 0
	subs r0, 0x57
_0800865C:
	pop {r1}
	bx r1
	thumb_func_end sub_8008630

	thumb_func_start xxx_get_next_char_from_string
xxx_get_next_char_from_string:
	push {r4-r6,lr}
	adds r5, r0, 0
	adds r6, r1, 0
	ldrb r1, [r5]
	cmp r1, 0x7E
	bne _08008696
	adds r5, 0x1
	ldrb r0, [r5]
	bl sub_8008630
	adds r4, r0, 0
	ldrb r0, [r5, 0x1]
	bl sub_8008630
	lsls r4, 4
	adds r4, r0
	ldrb r0, [r5]
	cmp r0, 0
	beq _08008690
	adds r5, 0x1
	ldrb r0, [r5]
	cmp r0, 0
	beq _08008690
	adds r5, 0x1
_08008690:
	str r4, [r6]
	adds r0, r5, 0
	b _080086B2
_08008696:
	adds r0, r1, 0
	subs r0, 0x81
	cmp r0, 0x3
	bls _080086A2
	cmp r1, 0x87
	bne _080086AE
_080086A2:
	ldrb r0, [r5, 0x1]
	lsls r1, 8
	orrs r0, r1
	str r0, [r6]
	adds r0, r5, 0x2
	b _080086B2
_080086AE:
	str r1, [r6]
	adds r0, r5, 0x1
_080086B2:
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end xxx_get_next_char_from_string

	thumb_func_start nullsub_165
nullsub_165:
	bx lr
	thumb_func_end nullsub_165

	thumb_func_start nullsub_166
nullsub_166:
	bx lr
	thumb_func_end nullsub_166

	thumb_func_start nullsub_167
nullsub_167:
	bx lr
	thumb_func_end nullsub_167

	thumb_func_start nullsub_168
nullsub_168:
	bx lr
	thumb_func_end nullsub_168

	thumb_func_start sub_80086C8
sub_80086C8:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0xC
	mov r9, r2
	ldr r7, [sp, 0x30]
	lsls r2, r1, 3
	adds r2, r1
	lsls r2, 3
	adds r0, r2
	mov r12, r0
	mov r0, r9
	cmp r0, 0
	bge _080086F2
	ldr r1, [sp, 0x2C]
	add r1, r9
	str r1, [sp, 0x2C]
	movs r2, 0
	mov r9, r2
_080086F2:
	cmp r3, 0
	bge _080086FA
	adds r7, r3
	movs r3, 0
_080086FA:
	ldr r0, [sp, 0x2C]
	add r0, r9
	mov r4, r12
	movs r5, 0x4
	ldrsh r2, [r4, r5]
	lsls r1, r2, 3
	cmp r0, r1
	ble _08008710
	mov r0, r9
	subs r0, r1, r0
	str r0, [sp, 0x2C]
_08008710:
	adds r1, r3, r7
	mov r4, r12
	movs r5, 0x8
	ldrsh r0, [r4, r5]
	lsls r0, 3
	cmp r1, r0
	ble _08008720
	subs r7, r0, r3
_08008720:
	adds r1, r3, 0
	cmp r3, 0
	bge _08008728
	adds r1, r3, 0x7
_08008728:
	asrs r1, 3
	muls r2, r1
	mov r0, r9
	cmp r0, 0
	bge _08008734
	adds r0, 0x7
_08008734:
	asrs r0, 3
	adds r0, r2, r0
	lsls r0, 3
	lsls r1, 3
	subs r1, r3, r1
	adds r0, r1
	lsls r0, 2
	mov r2, r12
	ldr r1, [r2, 0x18]
	b _080087D6
_08008748:
	adds r2, r5, 0
	ldr r4, [sp, 0x2C]
	mov r6, r9
	mov r1, r12
	ldr r0, [r1, 0x3C]
	cmp r0, r5
	bls _08008758
	str r5, [r1, 0x3C]
_08008758:
	subs r0, r7, 0x1
	str r0, [sp, 0x4]
	adds r3, 0x1
	str r3, [sp, 0x8]
	mov r1, r12
	ldr r1, [r1, 0x40]
	str r1, [sp]
	adds r0, r5, 0x4
	mov r10, r0
	cmp r4, 0
	ble _080087B6
	ldr r1, _0800878C
	mov r8, r1
	movs r7, 0x7
_08008774:
	cmp r4, 0x7
	bgt _08008790
	adds r3, r4, 0
	adds r0, r4, 0
	ands r0, r7
	adds r0, 0x8
	lsls r0, 2
	add r0, r8
	ldr r1, [r2]
	ldr r0, [r0]
	ands r1, r0
	b _080087AA
	.align 2, 0
_0800878C: .4byte gUnknown_80B8868
_08008790:
	adds r1, r6, 0
	ands r1, r7
	cmp r1, 0
	beq _080087A8
	movs r0, 0x8
	subs r3, r0, r1
	lsls r0, r1, 2
	add r0, r8
	ldr r1, [r2]
	ldr r0, [r0]
	ands r1, r0
	b _080087AA
_080087A8:
	movs r3, 0x8
_080087AA:
	str r1, [r2]
	adds r2, 0x20
	subs r4, r3
	adds r6, r3
	cmp r4, 0
	bgt _08008774
_080087B6:
	ldr r7, [sp, 0x4]
	ldr r3, [sp, 0x8]
	ldr r2, [sp]
	cmp r2, r5
	bcs _080087C4
	mov r4, r12
	str r5, [r4, 0x40]
_080087C4:
	mov r5, r10
	movs r0, 0x7
	ands r0, r3
	cmp r0, 0
	bne _080087D8
	mov r5, r12
	ldr r0, [r5, 0x20]
	lsls r0, 2
	mov r1, r10
_080087D6:
	adds r5, r1, r0
_080087D8:
	cmp r7, 0
	bgt _08008748
	add sp, 0xC
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_80086C8

	thumb_func_start sub_80087EC
sub_80087EC:
	push {r4-r6,lr}
	sub sp, 0x8
	adds r4, r0, 0
	adds r5, r1, 0
	adds r6, r2, 0
	ldr r1, [sp, 0x18]
	ldr r0, _08008810
	str r3, [sp]
	str r1, [sp, 0x4]
	adds r1, r4, 0
	adds r2, r5, 0
	adds r3, r6, 0
	bl sub_8008818
	add sp, 0x8
	pop {r4-r6}
	pop {r0}
	bx r0
	.align 2, 0
_08008810: .4byte gUnknown_2027370
	thumb_func_end sub_80087EC

	thumb_func_start nullsub_176
nullsub_176:
	bx lr
	thumb_func_end nullsub_176

	thumb_func_start sub_8008818
sub_8008818:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	adds r5, r3, 0
	ldr r7, [sp, 0x18]
	ldr r3, [sp, 0x1C]
	mov r12, r3
	lsls r3, r1, 3
	adds r3, r1
	lsls r3, 3
	adds r4, r0, r3
	cmp r2, 0
	bge _08008834
	adds r2, 0x7
_08008834:
	asrs r2, 3
	mov r8, r2
	adds r3, r5, 0
	cmp r3, 0
	bge _08008840
	adds r3, 0x7
_08008840:
	asrs r3, 3
	movs r2, 0
	cmp r2, r12
	bge _08008892
_08008848:
	movs r1, 0x4
	ldrsh r0, [r4, r1]
	muls r0, r3
	add r0, r8
	lsls r0, 5
	ldr r1, [r4, 0x18]
	adds r1, r0
	movs r5, 0
	adds r3, 0x1
	adds r6, r2, 0
	adds r6, 0x8
	cmp r5, r7
	bge _0800888C
	movs r2, 0
_08008864:
	ldr r0, [r4, 0x3C]
	cmp r0, r1
	bls _0800886C
	str r1, [r4, 0x3C]
_0800886C:
	stm r1!, {r2}
	stm r1!, {r2}
	stm r1!, {r2}
	stm r1!, {r2}
	stm r1!, {r2}
	stm r1!, {r2}
	stm r1!, {r2}
	str r2, [r1]
	ldr r0, [r4, 0x40]
	cmp r0, r1
	bcs _08008884
	str r1, [r4, 0x40]
_08008884:
	adds r1, 0x4
	adds r5, 0x8
	cmp r5, r7
	blt _08008864
_0800888C:
	adds r2, r6, 0
	cmp r2, r12
	blt _08008848
_08008892:
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_8008818

	thumb_func_start xxx_call_update_bg_vram
xxx_call_update_bg_vram:
	push {lr}
	movs r1, 0
	ldr r2, _080088C0
	ldrb r0, [r2]
	cmp r0, 0
	beq _080088AE
	strb r1, [r2]
	bl sub_80099C0
_080088AE:
	ldr r0, _080088C4
	bl xxx_update_bg_vram
	lsls r0, 24
	lsrs r1, r0, 24
	adds r0, r1, 0
	pop {r1}
	bx r1
	.align 2, 0
_080088C0: .4byte gUnknown_20274A5
_080088C4: .4byte gUnknown_2027370
	thumb_func_end xxx_call_update_bg_vram

	thumb_func_start xxx_update_bg_vram
xxx_update_bg_vram:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	mov r8, r0
	movs r2, 0
	movs r1, 0
	movs r7, 0xD0
	lsls r7, 4
_080088D8:
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 3
	mov r3, r8
	adds r4, r3, r0
	movs r5, 0x4
	ldrsh r0, [r4, r5]
	adds r6, r1, 0x1
	cmp r0, 0
	beq _0800897A
	ldr r5, [r4, 0x38]
	cmp r5, 0
	beq _0800897A
	adds r0, r4, 0
	adds r0, 0x45
	ldrb r0, [r0]
	cmp r0, 0
	beq _0800894C
	ldr r0, [r4, 0x28]
	ldr r1, [r4, 0x18]
	adds r2, r7, 0
	bl CpuCopy
	ldr r0, [r4, 0x18]
	adds r2, r0, r7
	ldr r0, [r4, 0x28]
	adds r1, r0, r7
	movs r3, 0
	b _08008938
_08008912:
	ldm r2!, {r0}
	stm r1!, {r0}
	ldm r2!, {r0}
	stm r1!, {r0}
	ldm r2!, {r0}
	stm r1!, {r0}
	ldm r2!, {r0}
	stm r1!, {r0}
	ldm r2!, {r0}
	stm r1!, {r0}
	ldr r0, _08008944
	stm r1!, {r0}
	ldr r0, _08008948
	stm r1!, {r0}
	movs r0, 0x1
	negs r0, r0
	stm r1!, {r0}
	adds r2, 0xC
	adds r3, 0x1
_08008938:
	movs r5, 0x4
	ldrsh r0, [r4, r5]
	cmp r3, r0
	blt _08008912
	movs r0, 0
	b _0800896A
	.align 2, 0
_08008944: .4byte 0xdddddddd
_08008948: .4byte 0xeeeeeeee
_0800894C:
	ldr r0, [r4, 0x30]
	ldr r1, [r4, 0x34]
	adds r2, r5, 0
	bl CpuCopy
	lsrs r1, r5, 2
	lsls r1, 2
	ldr r0, [r4, 0x34]
	adds r0, r1
	str r0, [r4, 0x34]
	ldr r0, [r4, 0x30]
	adds r0, r5
	str r0, [r4, 0x30]
	ldr r0, [r4, 0x38]
	subs r0, r5
_0800896A:
	str r0, [r4, 0x38]
	ldr r1, [r4, 0x38]
	cmp r1, 0
	bne _08008978
	adds r0, r4, 0
	adds r0, 0x44
	strb r1, [r0]
_08008978:
	movs r2, 0x1
_0800897A:
	adds r1, r6, 0
	cmp r1, 0x3
	ble _080088D8
	adds r0, r2, 0
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end xxx_update_bg_vram

	thumb_func_start sub_800898C
sub_800898C:
	push {lr}
	ldr r1, _080089A4
	ldr r2, _080089A8
	movs r3, 0xA0
	lsls r3, 1
	adds r0, r1, r3
_08008998:
	strh r2, [r0]
	subs r0, 0x2
	cmp r0, r1
	bge _08008998
	pop {r0}
	bx r0
	.align 2, 0
_080089A4: .4byte gUnknown_3000E94
_080089A8: .4byte 0x0000f0f0
	thumb_func_end sub_800898C

	thumb_func_start sub_80089AC
sub_80089AC:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x4
	adds r4, r0, 0
	adds r5, r1, 0
	ldrb r1, [r4]
	movs r0, 0x40
	ands r0, r1
	cmp r0, 0
	beq _080089C8
	b _08008C44
_080089C8:
	ldr r6, _08008A3C
	ldr r7, [r4, 0x4]
	cmp r7, 0x1
	bne _08008A60
	movs r0, 0x8
	ldrsh r2, [r4, r0]
	movs r1, 0
	ldrsh r0, [r5, r1]
	adds r2, r0
	lsls r3, r2, 3
	mov r12, r3
	movs r7, 0xA
	ldrsh r1, [r4, r7]
	movs r3, 0x2
	ldrsh r0, [r5, r3]
	adds r1, r0
	lsls r5, r1, 3
	movs r7, 0xC
	ldrsh r0, [r4, r7]
	adds r2, r0
	lsls r7, r2, 3
	movs r2, 0xE
	ldrsh r0, [r4, r2]
	adds r1, r0
	lsls r2, r1, 3
	cmp r0, 0
	bne _08008A00
	b _08008C44
_08008A00:
	cmp r5, 0
	bge _08008A06
	movs r5, 0
_08008A06:
	cmp r2, 0
	bge _08008A0C
	movs r2, 0
_08008A0C:
	cmp r5, 0xA0
	ble _08008A12
	movs r5, 0xA0
_08008A12:
	cmp r2, 0xA0
	ble _08008A18
	movs r2, 0xA0
_08008A18:
	cmp r5, r2
	blt _08008A1E
	b _08008C44
_08008A1E:
	lsls r3, r5, 1
	adds r1, r6, r3
	ldrb r0, [r1]
	cmp r0, 0xF0
	bne _08008A40
	ldrb r0, [r1, 0x1]
	cmp r0, 0xF0
	bne _08008A40
	strb r7, [r1]
	adds r3, 0x1
	adds r0, r6, r3
	mov r1, r12
	strb r1, [r0]
	b _08008A58
	.align 2, 0
_08008A3C: .4byte gUnknown_3000E94
_08008A40:
	adds r1, r6, r3
	ldrb r0, [r1]
	cmp r0, r7
	bge _08008A4A
	strb r7, [r1]
_08008A4A:
	adds r3, 0x1
	adds r3, r6, r3
	ldrb r0, [r3]
	cmp r0, r12
	ble _08008A58
	mov r0, r12
	strb r0, [r3]
_08008A58:
	adds r5, 0x1
	cmp r5, r2
	blt _08008A1E
	b _08008C44
_08008A60:
	cmp r7, 0x6
	beq _08008A66
	b _08008BA8
_08008A66:
	movs r2, 0x8
	ldrsh r1, [r4, r2]
	movs r3, 0
	ldrsh r0, [r5, r3]
	adds r1, r0
	lsls r3, r1, 3
	subs r7, r3, 0x5
	mov r9, r7
	movs r2, 0xA
	ldrsh r0, [r4, r2]
	movs r7, 0x2
	ldrsh r2, [r5, r7]
	adds r0, r2
	lsls r2, r0, 3
	subs r5, r2, 0x4
	movs r7, 0xC
	ldrsh r2, [r4, r7]
	adds r1, r2
	lsls r1, 3
	adds r1, 0x5
	str r1, [sp]
	movs r2, 0xE
	ldrsh r1, [r4, r2]
	adds r0, r1
	lsls r0, 3
	adds r0, 0x5
	mov r8, r0
	adds r3, 0x3
	mov r12, r3
	ldr r2, [r4, 0x14]
	ldrb r1, [r2, 0x2]
	subs r0, r1, 0x1
	ldrb r3, [r2]
	adds r0, r3
	adds r0, 0x2
	lsls r0, 3
	add r0, r12
	subs r0, 0x4
	mov r10, r0
	ldrb r0, [r2, 0x1]
	adds r0, 0x1
	lsls r0, 3
	mov r7, r9
	adds r4, r7, r0
	adds r1, 0x2
	lsls r1, 3
	adds r1, r4, r1
	subs r7, r1, 0x4
	cmp r5, 0
	bge _08008ACC
	movs r5, 0
_08008ACC:
	mov r0, r8
	cmp r0, 0
	bge _08008AD6
	movs r1, 0
	mov r8, r1
_08008AD6:
	cmp r5, 0xA0
	ble _08008ADC
	movs r5, 0xA0
_08008ADC:
	mov r2, r8
	cmp r2, 0xA0
	ble _08008AE6
	movs r3, 0xA0
	mov r8, r3
_08008AE6:
	movs r3, 0x3
_08008AE8:
	lsls r2, r5, 1
	adds r1, r6, r2
	ldrb r0, [r1]
	cmp r0, 0xF0
	bne _08008B02
	ldrb r0, [r1, 0x1]
	cmp r0, 0xF0
	bne _08008B02
	strb r7, [r1]
	adds r2, 0x1
	adds r0, r6, r2
	strb r4, [r0]
	b _08008B18
_08008B02:
	adds r1, r6, r2
	ldrb r0, [r1]
	cmp r0, r7
	bge _08008B0C
	strb r7, [r1]
_08008B0C:
	adds r2, 0x1
	adds r2, r6, r2
	ldrb r0, [r2]
	cmp r0, r4
	ble _08008B18
	strb r4, [r2]
_08008B18:
	adds r5, 0x1
	subs r3, 0x1
	cmp r3, 0
	bge _08008AE8
	movs r3, 0x7
_08008B22:
	lsls r1, r5, 1
	adds r2, r6, r1
	ldrb r0, [r2]
	cmp r0, 0xF0
	bne _08008B40
	ldrb r0, [r2, 0x1]
	cmp r0, 0xF0
	bne _08008B40
	mov r7, r10
	strb r7, [r2]
	adds r1, 0x1
	adds r0, r6, r1
	mov r1, r12
	strb r1, [r0]
	b _08008B5A
_08008B40:
	adds r2, r6, r1
	ldrb r0, [r2]
	cmp r0, r10
	bge _08008B4C
	mov r7, r10
	strb r7, [r2]
_08008B4C:
	adds r1, 0x1
	adds r1, r6, r1
	ldrb r0, [r1]
	cmp r0, r12
	ble _08008B5A
	mov r0, r12
	strb r0, [r1]
_08008B5A:
	adds r5, 0x1
	subs r3, 0x1
	cmp r3, 0
	bge _08008B22
	cmp r5, r8
	bge _08008C44
_08008B66:
	lsls r1, r5, 1
	adds r2, r6, r1
	ldrb r0, [r2]
	cmp r0, 0xF0
	bne _08008B86
	ldrb r0, [r2, 0x1]
	cmp r0, 0xF0
	bne _08008B86
	mov r3, sp
	ldrb r3, [r3]
	strb r3, [r2]
	adds r1, 0x1
	adds r0, r6, r1
	mov r7, r9
	strb r7, [r0]
	b _08008BA0
_08008B86:
	adds r2, r6, r1
	ldrb r0, [r2]
	ldr r3, [sp]
	cmp r0, r3
	bge _08008B92
	strb r3, [r2]
_08008B92:
	adds r1, 0x1
	adds r1, r6, r1
	ldrb r0, [r1]
	cmp r0, r9
	ble _08008BA0
	mov r0, r9
	strb r0, [r1]
_08008BA0:
	adds r5, 0x1
	cmp r5, r8
	blt _08008B66
	b _08008C44
_08008BA8:
	movs r1, 0x8
	ldrsh r0, [r4, r1]
	movs r2, 0
	ldrsh r1, [r5, r2]
	adds r0, r1
	lsls r1, r0, 3
	subs r1, 0x5
	mov r8, r1
	movs r3, 0xA
	ldrsh r2, [r4, r3]
	movs r3, 0x2
	ldrsh r1, [r5, r3]
	adds r2, r1
	lsls r5, r2, 3
	mov r9, r5
	mov r3, r9
	subs r3, 0x5
	movs r5, 0xC
	ldrsh r1, [r4, r5]
	adds r0, r1
	lsls r0, 3
	adds r0, 0x5
	mov r12, r0
	movs r1, 0xE
	ldrsh r0, [r4, r1]
	adds r2, r0
	lsls r1, r2, 3
	adds r5, r1, 0x5
	cmp r0, 0
	beq _08008C44
	cmp r7, 0
	bne _08008BEC
	adds r3, 0x8
	subs r5, r1, 0x3
_08008BEC:
	cmp r3, 0
	bge _08008BF2
	movs r3, 0
_08008BF2:
	cmp r5, 0
	bge _08008BF8
	movs r5, 0
_08008BF8:
	cmp r3, 0xA0
	ble _08008BFE
	movs r3, 0xA0
_08008BFE:
	cmp r5, 0xA0
	ble _08008C40
	movs r5, 0xA0
	b _08008C40
_08008C06:
	lsls r1, r3, 1
	adds r2, r6, r1
	ldrb r0, [r2]
	cmp r0, 0xF0
	bne _08008C24
	ldrb r0, [r2, 0x1]
	cmp r0, 0xF0
	bne _08008C24
	mov r7, r12
	strb r7, [r2]
	adds r1, 0x1
	adds r0, r6, r1
	mov r1, r8
	strb r1, [r0]
	b _08008C3E
_08008C24:
	adds r2, r6, r1
	ldrb r0, [r2]
	cmp r0, r12
	bge _08008C30
	mov r7, r12
	strb r7, [r2]
_08008C30:
	adds r1, 0x1
	adds r1, r6, r1
	ldrb r0, [r1]
	cmp r0, r8
	ble _08008C3E
	mov r0, r8
	strb r0, [r1]
_08008C3E:
	adds r3, 0x1
_08008C40:
	cmp r3, r5
	blt _08008C06
_08008C44:
	add sp, 0x4
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_80089AC

	thumb_func_start sub_8008C54
sub_8008C54:
	push {lr}
	adds r1, r0, 0
	ldr r0, _08008C64
	bl sub_8008C6C
	pop {r0}
	bx r0
	.align 2, 0
_08008C64: .4byte gUnknown_2027370
	thumb_func_end sub_8008C54

	thumb_func_start nullsub_169
nullsub_169:
	bx lr
	thumb_func_end nullsub_169

	thumb_func_start sub_8008C6C
sub_8008C6C:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0xC
	mov r9, r0
	mov r8, r1
	lsls r0, r1, 3
	add r0, r8
	lsls r0, 3
	mov r1, r9
	adds r6, r1, r0
	adds r0, r6, 0
	adds r0, 0x45
	ldrb r0, [r0]
	cmp r0, 0
	bne _08008CBE
	movs r2, 0x4
	ldrsh r0, [r6, r2]
	movs r7, 0x8
	ldrsh r1, [r6, r7]
	muls r0, r1
	lsls r4, r0, 5
	movs r5, 0
	movs r0, 0x44
	adds r0, r6
	mov r10, r0
	cmp r5, r4
	bge _08008D1E
_08008CA8:
	lsrs r1, r5, 2
	lsls r1, 2
	ldr r0, [r6, 0x18]
	adds r0, r1
	movs r1, 0x20
	bl CpuClear
	adds r5, 0x20
	cmp r5, r4
	blt _08008CA8
	b _08008D1E
_08008CBE:
	movs r1, 0x4
	ldrsh r0, [r6, r1]
	movs r2, 0x8
	ldrsh r1, [r6, r2]
	subs r1, 0x1
	muls r1, r0
	lsls r1, 5
	str r1, [sp, 0x8]
	ldr r4, [r6, 0x18]
	movs r5, 0
	movs r7, 0x44
	adds r7, r6
	mov r10, r7
	cmp r5, r0
	bge _08008D04
	movs r0, 0x1
	negs r0, r0
	mov r12, r0
	movs r1, 0
	ldr r3, _08008D84
	ldr r2, _08008D88
_08008CE8:
	mov r7, r12
	stm r4!, {r7}
	stm r4!, {r3}
	stm r4!, {r2}
	stm r4!, {r1}
	stm r4!, {r1}
	stm r4!, {r1}
	stm r4!, {r1}
	stm r4!, {r1}
	adds r5, 0x1
	movs r7, 0x4
	ldrsh r0, [r6, r7]
	cmp r5, r0
	blt _08008CE8
_08008D04:
	movs r5, 0
	ldr r0, [sp, 0x8]
	cmp r5, r0
	bge _08008D1E
_08008D0C:
	adds r0, r4, 0
	movs r1, 0x20
	bl CpuClear
	adds r4, 0x20
	adds r5, 0x20
	ldr r1, [sp, 0x8]
	cmp r5, r1
	blt _08008D0C
_08008D1E:
	ldr r0, [r6, 0xC]
	cmp r0, 0x6
	bne _08008D60
	adds r5, r6, 0
	adds r5, 0x46
	movs r4, 0
	movs r0, 0x1
	strb r0, [r5]
	movs r2, 0x4
	ldrsh r0, [r6, r2]
	lsls r0, 3
	str r0, [sp]
	movs r0, 0xE
	str r0, [sp, 0x4]
	mov r0, r9
	mov r1, r8
	movs r2, 0
	movs r3, 0xA
	bl sub_8007958
	movs r7, 0x4
	ldrsh r0, [r6, r7]
	lsls r0, 3
	str r0, [sp]
	movs r0, 0xD
	str r0, [sp, 0x4]
	mov r0, r9
	mov r1, r8
	movs r2, 0
	movs r3, 0xB
	bl sub_8007958
	strb r4, [r5]
_08008D60:
	ldr r0, [r6, 0x28]
	str r0, [r6, 0x30]
	ldr r0, [r6, 0x1C]
	str r0, [r6, 0x34]
	ldr r0, [r6, 0x2C]
	str r0, [r6, 0x38]
	movs r0, 0x1
	mov r1, r10
	strb r0, [r1]
	add sp, 0xC
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_08008D84: .4byte 0xeeeeeeee
_08008D88: .4byte 0xdddddddd
	thumb_func_end sub_8008C6C

	thumb_func_start sub_8008D8C
sub_8008D8C:
	push {lr}
	lsls r1, r0, 3
	adds r1, r0
	lsls r1, 3
	ldr r0, _08008DA4
	adds r1, r0
	ldr r0, [r1, 0x38]
	cmp r0, 0
	beq _08008DA0
	movs r0, 0x1
_08008DA0:
	pop {r1}
	bx r1
	.align 2, 0
_08008DA4: .4byte gUnknown_2027370
	thumb_func_end sub_8008D8C

	thumb_func_start sub_8008DA8
sub_8008DA8:
	movs r0, 0
	bx lr
	thumb_func_end sub_8008DA8

	thumb_func_start sub_8008DAC
sub_8008DAC:
	ldr r3, _08008DC0
	lsls r0, 1
	lsls r1, 6
	adds r0, r1
	adds r0, r3
	strh r2, [r0]
	ldr r1, _08008DC4
	movs r0, 0x1
	strb r0, [r1]
	bx lr
	.align 2, 0
_08008DC0: .4byte gUnknown_202B038
_08008DC4: .4byte gUnknown_20274A5
	thumb_func_end sub_8008DAC

	thumb_func_start sub_8008DC8
sub_8008DC8:
	push {r4,lr}
	ldr r4, _08008DEC
	lsls r0, 1
	lsls r1, 6
	adds r0, r1
	adds r1, r0, r4
	strh r2, [r1]
	movs r1, 0x80
	lsls r1, 4
	adds r4, r1
	adds r0, r4
	strh r3, [r0]
	ldr r1, _08008DF0
	movs r0, 0x1
	strb r0, [r1]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08008DEC: .4byte gUnknown_202B038
_08008DF0: .4byte gUnknown_20274A5
	thumb_func_end sub_8008DC8

	thumb_func_start sub_8008DF4
sub_8008DF4:
	push {r4-r7,lr}
	adds r4, r0, 0
	adds r5, r1, 0
	adds r3, r2, 0
	ldrb r0, [r3]
	ldr r1, _08008E4C
	mov r12, r1
	cmp r0, 0
	beq _08008E3E
	ldr r6, _08008E50
_08008E08:
	ldrb r1, [r3]
	adds r0, r1, 0
	subs r0, 0x61
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x19
	bhi _08008E1E
	adds r0, r1, 0
	subs r0, 0x20
	lsls r0, 24
	lsrs r1, r0, 24
_08008E1E:
	lsls r2, r4, 1
	lsls r0, r5, 6
	adds r2, r0
	adds r2, r6
	movs r7, 0x96
	lsls r7, 2
	adds r0, r1, r7
	ldr r7, _08008E54
	adds r1, r7, 0
	orrs r0, r1
	strh r0, [r2]
	adds r3, 0x1
	adds r4, 0x1
	ldrb r0, [r3]
	cmp r0, 0
	bne _08008E08
_08008E3E:
	movs r0, 0x1
	mov r1, r12
	strb r0, [r1]
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_08008E4C: .4byte gUnknown_20274A5
_08008E50: .4byte gUnknown_202B038
_08008E54: .4byte 0xfffff000
	thumb_func_end sub_8008DF4

	thumb_func_start sub_8008E58
sub_8008E58:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	adds r5, r0, 0
	mov r8, r1
	adds r4, r2, 0
	ldrb r0, [r4]
	ldr r7, _08008EC4
	cmp r0, 0
	beq _08008EB4
	adds r1, r0, 0
	cmp r3, 0
	beq _08008EB4
	ldr r0, _08008EC8
	mov r12, r0
_08008E76:
	adds r0, r1, 0
	subs r0, 0x61
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x19
	bhi _08008E8A
	adds r0, r1, 0
	subs r0, 0x20
	lsls r0, 24
	lsrs r1, r0, 24
_08008E8A:
	lsls r2, r5, 1
	mov r6, r8
	lsls r0, r6, 6
	adds r2, r0
	add r2, r12
	movs r6, 0x96
	lsls r6, 2
	adds r0, r1, r6
	ldr r6, _08008ECC
	adds r1, r6, 0
	orrs r0, r1
	strh r0, [r2]
	adds r4, 0x1
	adds r5, 0x1
	subs r3, 0x1
	ldrb r0, [r4]
	cmp r0, 0
	beq _08008EB4
	adds r1, r0, 0
	cmp r3, 0
	bne _08008E76
_08008EB4:
	movs r0, 0x1
	strb r0, [r7]
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_08008EC4: .4byte gUnknown_20274A5
_08008EC8: .4byte gUnknown_202B038
_08008ECC: .4byte 0xfffff000
	thumb_func_end sub_8008E58

	thumb_func_start sub_8008ED0
sub_8008ED0:
	push {r4,r5,lr}
	sub sp, 0x4
	adds r4, r0, 0
	movs r5, 0
	b _08008F64
_08008EDA:
	ldr r0, _08008F18
	cmp r1, r0
	beq _08008F64
	adds r0, 0x2
	cmp r1, r0
	beq _08008F64
	cmp r1, 0x1B
	beq _08008F7E
	cmp r1, 0x23
	bne _08008F44
	ldrb r0, [r2]
	cmp r0, 0x6E
	beq _08008F7E
	cmp r0, 0x5B
	beq _08008F7E
	cmp r0, 0x50
	beq _08008F7E
	cmp r0, 0x57
	beq _08008F40
	cmp r0, 0x57
	bgt _08008F22
	cmp r0, 0x43
	beq _08008F38
	cmp r0, 0x43
	bgt _08008F1C
	cmp r0, 0x2B
	beq _08008F40
	cmp r0, 0x3D
	beq _08008F34
	b _08008F64
	.align 2, 0
_08008F18: .4byte 0x000082a0
_08008F1C:
	cmp r0, 0x52
	beq _08008F3C
	b _08008F64
_08008F22:
	cmp r0, 0x72
	beq _08008F3C
	cmp r0, 0x72
	bgt _08008F30
	cmp r0, 0x63
	beq _08008F38
	b _08008F64
_08008F30:
	cmp r0, 0x7E
	bne _08008F64
_08008F34:
	adds r4, r2, 0x2
	b _08008F64
_08008F38:
	adds r4, 0x2
	b _08008F64
_08008F3C:
	adds r4, 0x1
	b _08008F64
_08008F40:
	adds r4, r2, 0x1
	b _08008F64
_08008F44:
	cmp r1, 0x60
	bne _08008F4C
	adds r5, 0x6
	b _08008F64
_08008F4C:
	adds r0, r1, 0
	bl sub_8008584
	cmp r0, 0
	beq _08008F64
	movs r1, 0x6
	ldrsh r0, [r0, r1]
	ldr r1, _08008F88
	movs r2, 0
	ldrsh r1, [r1, r2]
	adds r0, r1
	adds r5, r0
_08008F64:
	adds r0, r4, 0
	mov r1, sp
	bl xxx_get_next_char_from_string
	adds r2, r0, 0
	adds r4, r2, 0
	ldr r1, [sp]
	cmp r1, 0
	beq _08008F7E
	cmp r1, 0xD
	beq _08008F7E
	cmp r1, 0xA
	bne _08008EDA
_08008F7E:
	adds r0, r5, 0
	add sp, 0x4
	pop {r4,r5}
	pop {r1}
	bx r1
	.align 2, 0
_08008F88: .4byte gUnknown_2027498
	thumb_func_end sub_8008ED0

	thumb_func_start sub_8008F8C
sub_8008F8C:
	push {r4-r6,lr}
	sub sp, 0x10
	adds r4, r0, 0
	adds r5, r1, 0
	adds r6, r2, 0
	ldr r1, [sp, 0x20]
	ldr r2, [sp, 0x24]
	ldr r0, _08008FB8
	str r3, [sp]
	str r1, [sp, 0x4]
	movs r1, 0
	str r1, [sp, 0x8]
	str r2, [sp, 0xC]
	adds r1, r4, 0
	adds r2, r5, 0
	adds r3, r6, 0
	bl xxx_draw_string
	add sp, 0x10
	pop {r4-r6}
	pop {r0}
	bx r0
	.align 2, 0
_08008FB8: .4byte gUnknown_2027370
	thumb_func_end sub_8008F8C

	thumb_func_start xxx_call_draw_string
xxx_call_draw_string:
	push {r4-r6,lr}
	sub sp, 0x10
	adds r4, r0, 0
	adds r5, r1, 0
	adds r6, r2, 0
	ldr r1, [sp, 0x20]
	ldr r0, _08008FE8
	str r3, [sp]
	str r1, [sp, 0x4]
	movs r1, 0
	str r1, [sp, 0x8]
	movs r1, 0xD
	str r1, [sp, 0xC]
	adds r1, r4, 0
	adds r2, r5, 0
	adds r3, r6, 0
	bl xxx_draw_string
	add sp, 0x10
	pop {r4-r6}
	pop {r0}
	bx r0
	.align 2, 0
_08008FE8: .4byte gUnknown_2027370
	thumb_func_end xxx_call_draw_string

	thumb_func_start nullsub_170
nullsub_170:
	bx lr
	thumb_func_end nullsub_170

	thumb_func_start sub_8008FF0
sub_8008FF0:
	push {r4-r6,lr}
	sub sp, 0x10
	adds r4, r0, 0
	adds r5, r1, 0
	adds r6, r2, 0
	ldr r1, [sp, 0x20]
	ldr r0, _0800901C
	str r3, [sp]
	str r1, [sp, 0x4]
	movs r1, 0
	str r1, [sp, 0x8]
	movs r1, 0xD
	str r1, [sp, 0xC]
	adds r1, r4, 0
	adds r2, r5, 0
	adds r3, r6, 0
	bl xxx_draw_string
	add sp, 0x10
	pop {r4-r6}
	pop {r0}
	bx r0
	.align 2, 0
_0800901C: .4byte gUnknown_2027370
	thumb_func_end sub_8008FF0

	thumb_func_start nullsub_171
nullsub_171:
	bx lr
	thumb_func_end nullsub_171

	thumb_func_start xxx_draw_string
xxx_draw_string:
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	sub sp, 0x40
	adds r5, r0, 0
	adds r4, r3, 0
	ldr r0, [sp, 0x5C]
	mov r8, r0
	ldr r7, [sp, 0x64]
	add r0, sp, 0x8
	strh r1, [r0]
	strh r2, [r0, 0x2]
	str r1, [sp, 0x14]
	movs r0, 0x7
	str r0, [sp, 0x18]
	add r2, sp, 0x3C
	mov r9, r2
	b _08009128
_0800904A:
	ldr r0, _08009058
	cmp r3, r0
	bne _08009060
	ldr r1, _0800905C
	movs r0, 0
	str r0, [r1]
	b _08009128
	.align 2, 0
_08009058: .4byte 0x000082a0
_0800905C: .4byte gUnknown_20274AC
_08009060:
	ldr r0, _08009070
	cmp r3, r0
	bne _08009078
	ldr r1, _08009074
	movs r0, 0x1
	str r0, [r1]
	b _08009128
	.align 2, 0
_08009070: .4byte 0x000082a2
_08009074: .4byte gUnknown_20274AC
_08009078:
	cmp r3, 0x1B
	beq _0800914A
	cmp r3, 0xD
	beq _08009084
	cmp r3, 0xA
	bne _08009096
_08009084:
	add r1, sp, 0x8
	ldr r0, [sp, 0x14]
	strh r0, [r1]
	adds r0, r1, 0
	ldrh r0, [r0, 0x2]
	ldr r3, [sp, 0x68]
	adds r0, r3
	strh r0, [r1, 0x2]
	b _08009128
_08009096:
	cmp r3, 0x1D
	bne _080090AA
	add r1, sp, 0x8
	ldr r0, [sp, 0x14]
	strh r0, [r1]
	adds r0, r1, 0
	ldrh r0, [r0, 0x2]
	adds r0, 0x5
	strh r0, [r1, 0x2]
	b _08009128
_080090AA:
	cmp r3, 0x60
	bne _080090B8
	add r1, sp, 0x8
	adds r0, r1, 0
	ldrh r0, [r0]
	adds r0, 0x6
	b _08009126
_080090B8:
	cmp r7, 0
	bne _080090E0
	add r0, sp, 0x8
	movs r6, 0
	ldrsh r1, [r0, r6]
	movs r6, 0x2
	ldrsh r2, [r0, r6]
	ldr r0, [sp, 0x18]
	str r0, [sp]
	mov r0, r8
	str r0, [sp, 0x4]
	adds r0, r5, 0
	bl xxx_draw_char
	add r2, sp, 0x8
	adds r1, r2, 0
	ldrh r1, [r1]
	adds r1, r0
	strh r1, [r2]
	b _08009128
_080090E0:
	adds r0, r3, 0
	bl sub_8008584
	adds r2, r0, 0
	cmp r2, 0
	beq _08009128
	add r0, sp, 0x8
	movs r3, 0
	ldrsh r1, [r0, r3]
	ldr r0, _08009158
	movs r6, 0
	ldrsh r0, [r0, r6]
	adds r0, 0xA
	movs r3, 0x6
	ldrsh r2, [r2, r3]
	subs r0, r2
	lsrs r2, r0, 31
	adds r0, r2
	asrs r0, 1
	adds r1, r0
	add r0, sp, 0x8
	movs r6, 0x2
	ldrsh r2, [r0, r6]
	ldr r3, [sp, 0x3C]
	ldr r0, [sp, 0x18]
	str r0, [sp]
	mov r0, r8
	str r0, [sp, 0x4]
	adds r0, r5, 0
	bl xxx_draw_char
	add r1, sp, 0x8
	adds r0, r1, 0
	ldrh r0, [r0]
	adds r0, r7
_08009126:
	strh r0, [r1]
_08009128:
	adds r0, r5, 0
	adds r1, r4, 0
	add r2, sp, 0x8
	bl sub_80091AC
	adds r4, r0, 0
	mov r1, r9
	bl xxx_get_next_char_from_string
	adds r4, r0, 0
	ldr r3, [sp, 0x3C]
	cmp r3, 0
	beq _0800914A
	ldr r2, [sp, 0x60]
	cmp r3, r2
	beq _0800914A
	b _0800904A
_0800914A:
	add sp, 0x40
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_08009158: .4byte gUnknown_2027498
	thumb_func_end xxx_draw_string

	thumb_func_start sub_800915C
sub_800915C:
	push {r4,lr}
	adds r3, r0, 0
	movs r2, 0
_08009162:
	ldrb r0, [r1]
	cmp r0, 0x2E
	beq _08009184
	subs r0, 0x30
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x9
	bhi _08009186
	lsls r0, r2, 2
	adds r0, r2
	lsls r2, r0, 1
	adds r0, r2, 0
	subs r0, 0x30
	ldrb r4, [r1]
	adds r2, r0, r4
	adds r1, 0x1
	b _08009162
_08009184:
	adds r1, 0x1
_08009186:
	strh r2, [r3]
	adds r0, r1, 0
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_800915C

	thumb_func_start sub_8009190
sub_8009190:
	push {lr}
	adds r3, r0, 0
	adds r2, r1, 0
	ldr r0, _080091A4
	adds r1, r3, 0
	bl sub_80091AC
	pop {r1}
	bx r1
	.align 2, 0
_080091A4: .4byte gUnknown_2027370
	thumb_func_end sub_8009190

	thumb_func_start sub_80091A8
sub_80091A8:
	adds r0, 0x1
	bx lr
	thumb_func_end sub_80091A8

	thumb_func_start sub_80091AC
sub_80091AC:
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	mov r8, r0
	adds r4, r1, 0
	adds r5, r2, 0
	movs r0, 0
	mov r9, r0
	movs r7, 0x1
_080091C0:
	ldrb r0, [r4]
	cmp r0, 0x23
	beq _080091C8
	b _0800937A
_080091C8:
	ldrb r0, [r4, 0x1]
	adds r1, r0, 0
	cmp r1, 0x5B
	bne _08009216
	adds r2, r4, 0
	adds r4, 0x2
	adds r0, r5, 0
	adds r0, 0x21
	mov r1, r9
	strb r1, [r0]
	ldrb r1, [r4]
	adds r6, r0, 0
	cmp r1, 0
	beq _080091F6
	cmp r1, 0x5D
	beq _080091F4
_080091E8:
	adds r4, 0x1
	ldrb r0, [r4]
	cmp r0, 0
	beq _080091F6
	cmp r0, 0x5D
	bne _080091E8
_080091F4:
	adds r4, 0x1
_080091F6:
	ldr r3, [r5, 0x24]
	cmp r3, 0
	beq _0800920C
	adds r0, r2, 0
	adds r1, r4, 0
	adds r2, r5, 0
	bl _call_via_r3
	cmp r0, 0
	beq _0800920C
	adds r4, r0, 0
_0800920C:
	ldrb r0, [r6]
	cmp r0, 0
	beq _08009214
	b _0800937A
_08009214:
	b _080091C0
_08009216:
	cmp r1, 0x3D
	bne _08009220
	ldrb r0, [r4, 0x2]
	strh r0, [r5]
	b _080092BA
_08009220:
	cmp r1, 0x79
	bne _0800922A
	ldrb r0, [r4, 0x2]
	strh r0, [r5, 0x2]
	b _080092BA
_0800922A:
	cmp r1, 0x3E
	bne _0800923A
	adds r1, r4, 0x2
	adds r0, r5, 0
	bl sub_800915C
	adds r4, r0, 0
	b _080091C0
_0800923A:
	cmp r1, 0x2E
	bne _08009246
	ldrh r0, [r5]
	ldrb r2, [r4, 0x2]
	adds r0, r2
	b _0800926E
_08009246:
	cmp r1, 0x6E
	bne _08009258
	ldr r0, [r5, 0xC]
	strh r0, [r5]
	ldrh r0, [r5, 0x2]
	adds r0, 0xB
	strh r0, [r5, 0x2]
	adds r4, 0x2
	b _080091C0
_08009258:
	cmp r1, 0x3A
	bne _08009264
	ldrh r0, [r5]
	strh r0, [r5, 0x4]
	adds r4, 0x2
	b _080091C0
_08009264:
	cmp r1, 0x3B
	bne _08009274
	ldrh r0, [r5, 0x4]
	ldrb r3, [r4, 0x2]
	adds r0, r3
_0800926E:
	strh r0, [r5]
	adds r4, 0x3
	b _080091C0
_08009274:
	cmp r1, 0x2B
	bne _0800929A
	adds r4, 0x2
	adds r0, r4, 0
	bl sub_8008ED0
	mov r2, r8
	movs r3, 0x4
	ldrsh r1, [r2, r3]
	lsls r1, 3
	subs r1, r0
	strh r1, [r5]
	movs r1, 0
	ldrsh r0, [r5, r1]
	lsrs r1, r0, 31
	adds r0, r1
	asrs r0, 1
	strh r0, [r5]
	b _080091C0
_0800929A:
	cmp r1, 0x43
	bne _080092A4
	ldr r0, [r5, 0x10]
	str r0, [r5, 0x14]
	b _080092DC
_080092A4:
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x5F
	bne _080092CC
	ldr r0, [r5, 0x10]
	str r0, [r5, 0x14]
	ldr r1, _080092C8
	ldrb r0, [r4, 0x2]
	adds r0, r1
	ldrb r0, [r0]
	str r0, [r5, 0x10]
_080092BA:
	adds r4, 0x3
	ldrb r0, [r4]
	cmp r0, 0x2E
	beq _080092C4
	b _080091C0
_080092C4:
	adds r4, 0x1
	b _080091C0
	.align 2, 0
_080092C8: .4byte gUnknown_202749A
_080092CC:
	cmp r0, 0x52
	bne _080092D4
	ldr r0, [r5, 0x14]
	b _080092EE
_080092D4:
	cmp r0, 0x63
	bne _080092E8
	ldr r0, [r5, 0x10]
	str r0, [r5, 0x18]
_080092DC:
	ldrb r0, [r4, 0x2]
	bl sub_800963C
	str r0, [r5, 0x10]
	adds r4, 0x3
	b _080091C0
_080092E8:
	cmp r0, 0x72
	bne _080092F4
	ldr r0, [r5, 0x18]
_080092EE:
	str r0, [r5, 0x10]
	adds r4, 0x2
	b _080091C0
_080092F4:
	cmp r0, 0x53
	bne _08009314
	ldr r3, _08009310
	ldrb r2, [r4, 0x2]
	movs r0, 0x7F
	adds r1, r0, 0
	ands r1, r2
	adds r1, r3
	ldrb r2, [r4, 0x3]
	ands r0, r2
	strb r0, [r1]
	adds r4, 0x4
	b _080091C0
	.align 2, 0
_08009310: .4byte gUnknown_20274A6
_08009314:
	cmp r0, 0x57
	bne _0800933A
	adds r4, 0x2
	mov r2, r8
	movs r3, 0
	ldrsh r0, [r2, r3]
	lsls r0, 3
	ldrh r1, [r5]
	adds r0, r1
	subs r0, 0x2
	strh r0, [r5, 0x8]
	movs r3, 0x2
	ldrsh r0, [r2, r3]
	lsls r0, 3
	ldrh r1, [r5, 0x2]
	adds r0, r1
	adds r0, 0x3
	strh r0, [r5, 0xA]
	b _0800935C
_0800933A:
	cmp r0, 0x50
	bne _08009350
	adds r4, 0x2
	ldr r0, _0800934C
	strh r0, [r5, 0x2]
	mov r2, r9
	str r2, [r5, 0x1C]
	b _0800935C
	.align 2, 0
_0800934C: .4byte 0x0000270f
_08009350:
	cmp r0, 0x70
	bne _08009368
	adds r4, 0x2
	ldr r0, _08009364
	strh r0, [r5, 0x2]
	str r7, [r5, 0x1C]
_0800935C:
	adds r0, r5, 0
	adds r0, 0x20
	strb r7, [r0]
	b _0800937A
	.align 2, 0
_08009364: .4byte 0x0000270f
_08009368:
	cmp r0, 0x7E
	bne _0800937A
	ldrb r0, [r4, 0x2]
	str r0, [r5, 0x2C]
	adds r0, r5, 0
	adds r0, 0x21
	strb r7, [r0]
	adds r4, 0x3
	b _080091C0
_0800937A:
	adds r0, r4, 0
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_80091AC

	thumb_func_start sub_8009388
sub_8009388:
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	ldr r2, _080093F4
	ldr r6, _080093F8
	strh r6, [r2]
	movs r0, 0x80
	lsls r0, 4
	adds r5, r2, r0
	ldr r4, _080093FC
	strh r4, [r5]
	ldr r0, _08009400
	ldr r3, [r0]
	ldr r0, _08009404
	ldr r1, [r0]
	mov r9, r0
	cmp r3, r1
	bge _080093E6
	mov r8, r2
	mov r12, r6
	adds r6, r5, 0
	movs r5, 0
	adds r7, r6, 0
_080093B8:
	lsls r0, r3, 6
	mov r1, r8
	adds r2, r0, r1
	mov r1, r12
	strh r1, [r2]
	adds r1, r0, r6
	strh r4, [r1]
	adds r3, 0x1
	adds r0, r7
	adds r0, 0x2
	adds r2, 0x2
	movs r1, 0x1E
_080093D0:
	strh r5, [r2]
	strh r4, [r0]
	adds r0, 0x2
	adds r2, 0x2
	subs r1, 0x1
	cmp r1, 0
	bge _080093D0
	mov r1, r9
	ldr r0, [r1]
	cmp r3, r0
	blt _080093B8
_080093E6:
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_080093F4: .4byte gUnknown_202B038
_080093F8: .4byte 0x0000f279
_080093FC: .4byte 0x0000f27a
_08009400: .4byte gUnknown_202B020
_08009404: .4byte gUnknown_202B024
	thumb_func_end sub_8009388

	thumb_func_start sub_8009408
sub_8009408:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	adds r5, r1, 0
	ldr r1, _08009478
	ldr r6, _0800947C
	strh r6, [r1]
	movs r2, 0x80
	lsls r2, 4
	adds r4, r1, r2
	ldr r2, _08009480
	strh r2, [r4]
	adds r3, r0, 0
	ldr r0, _08009484
	mov r10, r0
	cmp r3, r5
	bge _08009464
	mov r9, r1
	mov r8, r6
	adds r7, r4, 0
	adds r4, r2, 0
	movs r6, 0
	mov r12, r7
_0800943A:
	lsls r0, r3, 6
	mov r1, r9
	adds r2, r0, r1
	mov r1, r8
	strh r1, [r2]
	adds r1, r0, r7
	strh r4, [r1]
	adds r3, 0x1
	add r0, r12
	adds r0, 0x2
	adds r2, 0x2
	movs r1, 0x1E
_08009452:
	strh r6, [r2]
	strh r4, [r0]
	adds r0, 0x2
	adds r2, 0x2
	subs r1, 0x1
	cmp r1, 0
	bge _08009452
	cmp r3, r5
	blt _0800943A
_08009464:
	movs r0, 0x1
	mov r2, r10
	strb r0, [r2]
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_08009478: .4byte gUnknown_202B038
_0800947C: .4byte 0x0000f279
_08009480: .4byte 0x0000f27a
_08009484: .4byte gUnknown_20274A5
	thumb_func_end sub_8009408

	thumb_func_start sub_8009488
sub_8009488:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	lsls r1, r0, 3
	adds r1, r0
	lsls r1, 3
	ldr r0, _08009514
	adds r4, r1, r0
	movs r0, 0x2
	ldrsh r1, [r4, r0]
	movs r3, 0
	movs r2, 0x6
	ldrsh r0, [r4, r2]
	cmp r3, r0
	bge _08009506
	ldr r6, _08009518
	mov r9, r6
	ldr r0, _0800951C
	mov r8, r0
	movs r2, 0x80
	lsls r2, 4
	add r2, r8
	mov r10, r2
_080094BA:
	movs r6, 0
	ldrsh r2, [r4, r6]
	movs r5, 0
	movs r6, 0x4
	ldrsh r0, [r4, r6]
	adds r6, r1, 0x1
	adds r7, r3, 0x1
	cmp r5, r0
	bge _080094FA
	movs r0, 0xFC
	lsls r0, 8
	mov r12, r0
	lsls r2, 1
	lsls r1, 6
	mov r3, r10
	adds r0, r1, r3
	adds r3, r2, r0
	add r1, r8
	adds r2, r1
_080094E0:
	ldrh r0, [r2]
	mov r1, r12
	ands r1, r0
	strh r1, [r2]
	mov r0, r9
	strh r0, [r3]
	adds r3, 0x2
	adds r2, 0x2
	adds r5, 0x1
	movs r1, 0x4
	ldrsh r0, [r4, r1]
	cmp r5, r0
	blt _080094E0
_080094FA:
	adds r1, r6, 0
	adds r3, r7, 0
	movs r2, 0x6
	ldrsh r0, [r4, r2]
	cmp r3, r0
	blt _080094BA
_08009506:
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_08009514: .4byte gUnknown_2027370
_08009518: .4byte 0x0000f27a
_0800951C: .4byte gUnknown_202B038
	thumb_func_end sub_8009488

	thumb_func_start nullsub_172
nullsub_172:
	bx lr
	thumb_func_end nullsub_172

	thumb_func_start sub_8009524
sub_8009524:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	lsls r1, r0, 3
	adds r1, r0
	lsls r1, 3
	ldr r0, _080095BC
	adds r4, r1, r0
	movs r1, 0x2
	ldrsh r0, [r4, r1]
	subs r1, r0, 0x1
	movs r3, 0
	movs r2, 0x6
	ldrsh r0, [r4, r2]
	adds r0, 0x2
	cmp r3, r0
	bge _080095AE
	ldr r6, _080095C0
	mov r9, r6
	ldr r0, _080095C4
	mov r8, r0
	movs r2, 0x80
	lsls r2, 4
	add r2, r8
	mov r10, r2
_0800955A:
	movs r6, 0
	ldrsh r0, [r4, r6]
	subs r2, r0, 0x1
	movs r5, 0
	movs r6, 0x4
	ldrsh r0, [r4, r6]
	adds r0, 0x2
	adds r6, r1, 0x1
	adds r7, r3, 0x1
	cmp r5, r0
	bge _080095A0
	movs r0, 0xFC
	lsls r0, 8
	mov r12, r0
	lsls r2, 1
	lsls r1, 6
	mov r3, r10
	adds r0, r1, r3
	adds r3, r2, r0
	add r1, r8
	adds r2, r1
_08009584:
	ldrh r0, [r2]
	mov r1, r12
	ands r1, r0
	strh r1, [r2]
	mov r0, r9
	strh r0, [r3]
	adds r3, 0x2
	adds r2, 0x2
	adds r5, 0x1
	movs r1, 0x4
	ldrsh r0, [r4, r1]
	adds r0, 0x2
	cmp r5, r0
	blt _08009584
_080095A0:
	adds r1, r6, 0
	adds r3, r7, 0
	movs r2, 0x6
	ldrsh r0, [r4, r2]
	adds r0, 0x2
	cmp r3, r0
	blt _0800955A
_080095AE:
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_080095BC: .4byte gUnknown_2027370
_080095C0: .4byte 0x0000f27a
_080095C4: .4byte gUnknown_202B038
	thumb_func_end sub_8009524

	thumb_func_start nullsub_173
nullsub_173:
	bx lr
	thumb_func_end nullsub_173

	thumb_func_start sub_80095CC
sub_80095CC:
	ldr r2, _080095D8
	str r0, [r2]
	ldr r0, _080095DC
	str r1, [r0]
	bx lr
	.align 2, 0
_080095D8: .4byte gUnknown_202B020
_080095DC: .4byte gUnknown_202B024
	thumb_func_end sub_80095CC

	thumb_func_start nullsub_174
nullsub_174:
	bx lr
	thumb_func_end nullsub_174

	thumb_func_start sub_80095E4
sub_80095E4:
	push {lr}
	cmp r1, 0
	bne _080095EC
	movs r1, 0xA
_080095EC:
	muls r1, r0
	movs r0, 0x7
	ands r0, r1
	cmp r0, 0
	beq _08009604
	adds r0, r1, 0
	cmp r1, 0
	bge _080095FE
	adds r0, r1, 0x7
_080095FE:
	asrs r0, 3
	adds r0, 0x1
	b _0800960E
_08009604:
	adds r0, r1, 0
	cmp r0, 0
	bge _0800960C
	adds r0, 0x7
_0800960C:
	asrs r0, 3
_0800960E:
	pop {r1}
	bx r1
	thumb_func_end sub_80095E4

	thumb_func_start sub_8009614
sub_8009614:
	push {lr}
	muls r1, r0
	movs r0, 0x7
	ands r0, r1
	cmp r0, 0
	beq _0800962E
	adds r0, r1, 0
	cmp r1, 0
	bge _08009628
	adds r0, r1, 0x7
_08009628:
	asrs r0, 3
	adds r0, 0x1
	b _08009638
_0800962E:
	adds r0, r1, 0
	cmp r0, 0
	bge _08009636
	adds r0, 0x7
_08009636:
	asrs r0, 3
_08009638:
	pop {r1}
	bx r1
	thumb_func_end sub_8009614

	thumb_func_start sub_800963C
sub_800963C:
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	adds r2, r0, 0
	cmp r0, 0xF
	bls _080096DA
	adds r1, r0, 0
	subs r1, 0x30
	lsls r0, r1, 24
	lsrs r0, 24
	cmp r0, 0xF
	bhi _08009658
	adds r0, r1, 0
	b _080096DA
_08009658:
	adds r0, r2, 0
	subs r0, 0x43
	cmp r0, 0x14
	bhi _080096D8
	lsls r0, 2
	ldr r1, _0800966C
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0800966C: .4byte _08009670
	.align 2, 0
_08009670:
	.4byte _080096D0
	.4byte _080096D0
	.4byte _080096C8
	.4byte _080096D8
	.4byte _080096CC
	.4byte _080096C4
	.4byte _080096C4
	.4byte _080096D8
	.4byte _080096D8
	.4byte _080096D8
	.4byte _080096CC
	.4byte _080096D0
	.4byte _080096D8
	.4byte _080096D8
	.4byte _080096D8
	.4byte _080096D8
	.4byte _080096C8
	.4byte _080096C8
	.4byte _080096D8
	.4byte _080096D8
	.4byte _080096D4
_080096C4:
	movs r0, 0x4
	b _080096DA
_080096C8:
	movs r0, 0xF
	b _080096DA
_080096CC:
	movs r0, 0x5
	b _080096DA
_080096D0:
	movs r0, 0x6
	b _080096DA
_080096D4:
	movs r0, 0x2
	b _080096DA
_080096D8:
	movs r0, 0x7
_080096DA:
	pop {r1}
	bx r1
	thumb_func_end sub_800963C

	thumb_func_start sub_80096E0
sub_80096E0:
	push {r4-r6,lr}
	ldr r1, _0800978C
	movs r0, 0x1
	strb r0, [r1]
	movs r1, 0xC0
	lsls r1, 19
	movs r5, 0
	ldr r3, _08009790
	ldr r0, _08009794
	movs r2, 0
_080096F4:
	stm r1!, {r2}
	adds r5, 0x1
	cmp r5, r3
	bls _080096F4
	movs r1, 0xA0
	lsls r1, 19
	movs r5, 0
	movs r2, 0
_08009704:
	stm r1!, {r2}
	adds r5, 0x1
	cmp r5, 0xFF
	bls _08009704
	movs r1, 0xE0
	lsls r1, 19
	movs r5, 0
	ldr r2, _08009798
_08009714:
	stm r1!, {r2}
	adds r5, 0x1
	cmp r5, 0xFF
	bls _08009714
	ldr r4, _0800979C
	adds r1, r4, 0
	bl OpenFileAndGetFileDataPtr
	adds r6, r0, 0
	ldr r1, [r6, 0x4]
	ldm r1!, {r5}
	ldr r0, _080097A0
	lsls r2, r5, 5
	bl CpuCopy
	adds r0, r6, 0
	bl CloseFile
	ldr r0, _080097A4
	adds r1, r4, 0
	bl OpenFileAndGetFileDataPtr
	adds r6, r0, 0
	ldr r1, [r6, 0x4]
	ldm r1!, {r5}
	ldr r0, _080097A8
	lsls r2, r5, 5
	bl CpuCopy
	adds r0, r6, 0
	bl CloseFile
	bl sub_80097B0
	ldr r0, _080097AC
	adds r1, r4, 0
	bl OpenFileAndGetFileDataPtr
	adds r6, r0, 0
	ldr r4, [r6, 0x4]
	movs r5, 0
_08009766:
	movs r1, 0xF8
	lsls r1, 1
	adds r0, r5, r1
	adds r1, r4, 0
	bl SetBGPaletteBufferColorArray
	adds r4, 0x4
	adds r5, 0x1
	cmp r5, 0xF
	ble _08009766
	adds r0, r6, 0
	bl CloseFile
	bl TransferBGPaletteBuffer
	pop {r4-r6}
	pop {r0}
	bx r0
	.align 2, 0
_0800978C: .4byte gUnknown_203B090
_08009790: .4byte 0x00005fff
_08009794: .4byte gUnknown_80B88B0
_08009798: .4byte 0x00a000a0
_0800979C: .4byte gUnknown_8300500
_080097A0: .4byte 0x06004f00
_080097A4: .4byte gUnknown_80B88B8
_080097A8: .4byte 0x06017e00
_080097AC: .4byte gUnknown_80B88C0
	thumb_func_end sub_80096E0

	thumb_func_start sub_80097B0
sub_80097B0:
	push {r4-r6,lr}
	ldr r0, _080097F8
	ldr r1, _080097FC
	bl OpenFileAndGetFileDataPtr
	adds r6, r0, 0
	ldr r4, _08009800
	ldr r1, [r6, 0x4]
	movs r2, 0x80
	lsls r2, 2
	adds r0, r4, 0
	bl CpuCopy
	bl sub_80063B0
	adds r5, r4, 0
	adds r5, 0x40
	cmp r0, 0x1
	bne _080097D8
	adds r5, r4, 0
_080097D8:
	movs r4, 0
_080097DA:
	adds r0, r4, 0
	adds r0, 0xF0
	adds r1, r5, 0
	bl SetBGPaletteBufferColorArray
	adds r5, 0x4
	adds r4, 0x1
	cmp r4, 0xF
	ble _080097DA
	adds r0, r6, 0
	bl CloseFile
	pop {r4-r6}
	pop {r0}
	bx r0
	.align 2, 0
_080097F8: .4byte gUnknown_80B88CC
_080097FC: .4byte gUnknown_8300500
_08009800: .4byte gUnknown_202D038
	thumb_func_end sub_80097B0

	.align 2, 0 @ Don't pad with nop.
