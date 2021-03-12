        .include "constants/gba_constants.inc"
	.include "asm/macros.inc"

	.syntax unified

	.text

	thumb_func_start sub_803A3BC
sub_803A3BC:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x84
	movs r5, 0x1
	add r4, sp, 0x60
	add r6, sp, 0x68
	add r0, sp, 0x7C
	mov r8, r0
	add r0, sp, 0x80
	mov r10, r0
_0803A3D6:
	lsls r0, r5, 24
	lsrs r0, 24
	bl UnlockFriendArea
	adds r5, 0x1
	cmp r5, 0x39
	ble _0803A3D6
	movs r5, 0
	adds r7, r4, 0
_0803A3E8:
	movs r0, 0
	mov r9, r0
	ldr r0, _0803A454
	str r0, [sp, 0x7C]
	adds r5, 0x1
	lsls r4, r5, 16
	asrs r4, 16
	adds r0, r7, 0
	movs r1, 0
	movs r2, 0x8
	bl memset
	movs r0, 0x27
	strh r0, [r7]
	adds r0, r6, 0
	adds r1, r4, 0
	bl CopySpeciesNametoBuffer
	adds r0, r6, 0
	adds r1, r6, 0
	bl CopyStringtoBuffer
	movs r0, 0x40
	strb r0, [r6]
	mov r0, r8
	str r0, [sp]
	str r7, [sp, 0x4]
	add r0, sp, 0x8
	adds r1, r4, 0
	adds r2, r6, 0
	movs r3, 0x43
	bl sub_808CFD0
	add r0, sp, 0x8
	bl sub_808D1DC
	ldr r0, _0803A458
	cmp r5, r0
	ble _0803A3E8
	mov r0, r9
	str r0, [sp, 0x80]
	mov r0, r10
	movs r1, 0x1
	bl sub_801203C
	add sp, 0x84
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_0803A454: .4byte 0x00001006
_0803A458: .4byte 0x0000012b
	thumb_func_end sub_803A3BC

	thumb_func_start sub_803A45C
sub_803A45C:
	push {r4,lr}
	bl ResetUnusedInputStruct
	movs r0, 0
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	ldr r4, _0803A488
	movs r0, 0x9C
	lsls r0, 1
	movs r1, 0x8
	bl MemoryAlloc
	str r0, [r4]
	movs r0, 0
	bl sub_803A504
	movs r0, 0x1
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_0803A488: .4byte gUnknown_203B3F0
	thumb_func_end sub_803A45C

	thumb_func_start sub_803A48C
sub_803A48C:
	push {lr}
	ldr r0, _0803A4A4
	ldr r0, [r0]
	ldr r0, [r0]
	cmp r0, 0x5
	bhi _0803A4E0
	lsls r0, 2
	ldr r1, _0803A4A8
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0803A4A4: .4byte gUnknown_203B3F0
_0803A4A8: .4byte _0803A4AC
	.align 2, 0
_0803A4AC:
	.4byte _0803A4C4
	.4byte _0803A4C4
	.4byte _0803A4CA
	.4byte _0803A4D0
	.4byte _0803A4D6
	.4byte _0803A4DC
_0803A4C4:
	bl sub_803A740
	b _0803A4E0
_0803A4CA:
	bl sub_803A7B0
	b _0803A4E0
_0803A4D0:
	bl sub_803A810
	b _0803A4E0
_0803A4D6:
	bl sub_803A86C
	b _0803A4E0
_0803A4DC:
	movs r0, 0x3
	b _0803A4E2
_0803A4E0:
	movs r0, 0
_0803A4E2:
	pop {r1}
	bx r1
	thumb_func_end sub_803A48C

	thumb_func_start sub_803A4E8
sub_803A4E8:
	push {r4,lr}
	ldr r4, _0803A500
	ldr r0, [r4]
	cmp r0, 0
	beq _0803A4FA
	bl MemoryFree
	movs r0, 0
	str r0, [r4]
_0803A4FA:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0803A500: .4byte gUnknown_203B3F0
	thumb_func_end sub_803A4E8

	thumb_func_start sub_803A504
sub_803A504:
	push {lr}
	ldr r1, _0803A518
	ldr r1, [r1]
	str r0, [r1]
	bl sub_803A51C
	bl sub_803A5A0
	pop {r0}
	bx r0
	.align 2, 0
_0803A518: .4byte gUnknown_203B3F0
	thumb_func_end sub_803A504

	thumb_func_start sub_803A51C
sub_803A51C:
	push {r4-r7,lr}
	ldr r4, _0803A53C
	ldr r0, [r4]
	adds r0, 0xD8
	bl sub_8006518
	ldr r1, [r4]
	ldr r0, [r1]
	cmp r0, 0x2
	beq _0803A544
	cmp r0, 0x3
	bne _0803A55C
	adds r1, 0xF0
	ldr r0, _0803A540
	b _0803A54C
	.align 2, 0
_0803A53C: .4byte gUnknown_203B3F0
_0803A540: .4byte gUnknown_80E7E64
_0803A544:
	movs r0, 0x84
	lsls r0, 1
	adds r1, r0
	ldr r0, _0803A558
_0803A54C:
	ldm r0!, {r2-r4}
	stm r1!, {r2-r4}
	ldm r0!, {r5-r7}
	stm r1!, {r5-r7}
	b _0803A57E
	.align 2, 0
_0803A558: .4byte gUnknown_80E7E4C
_0803A55C:
	mov r12, r4
	ldr r4, _0803A598
	movs r3, 0
	movs r2, 0x3
_0803A564:
	mov r0, r12
	ldr r1, [r0]
	adds r1, r3
	adds r1, 0xD8
	adds r0, r4, 0
	ldm r0!, {r5-r7}
	stm r1!, {r5-r7}
	ldm r0!, {r5-r7}
	stm r1!, {r5-r7}
	adds r3, 0x18
	subs r2, 0x1
	cmp r2, 0
	bge _0803A564
_0803A57E:
	bl ResetUnusedInputStruct
	ldr r0, _0803A59C
	ldr r0, [r0]
	adds r0, 0xD8
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_0803A598: .4byte gUnknown_80E7E34
_0803A59C: .4byte gUnknown_203B3F0
	thumb_func_end sub_803A51C

	thumb_func_start sub_803A5A0
sub_803A5A0:
	push {lr}
	sub sp, 0xC
	ldr r1, _0803A5BC
	ldr r0, [r1]
	ldr r0, [r0]
	adds r2, r1, 0
	cmp r0, 0x5
	bhi _0803A68A
	lsls r0, 2
	ldr r1, _0803A5C0
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0803A5BC: .4byte gUnknown_203B3F0
_0803A5C0: .4byte _0803A5C4
	.align 2, 0
_0803A5C4:
	.4byte _0803A5DC
	.4byte _0803A5EA
	.4byte _0803A5F2
	.4byte _0803A61C
	.4byte _0803A678
	.4byte _0803A68A
_0803A5DC:
	movs r0, 0x2
	movs r1, 0x3
	movs r2, 0
	movs r3, 0xA
	bl sub_801C8C4
	b _0803A68A
_0803A5EA:
	movs r0, 0x1
	bl sub_801CB5C
	b _0803A68A
_0803A5F2:
	bl sub_801CCD8
	bl sub_803A6F0
	ldr r0, _0803A618
	ldr r2, [r0]
	adds r0, r2, 0
	adds r0, 0x4C
	adds r1, r2, 0
	adds r1, 0xC
	ldr r2, [r2, 0x8]
	str r2, [sp]
	movs r2, 0x2
	str r2, [sp, 0x4]
	movs r2, 0
	movs r3, 0
	bl sub_8012D60
	b _0803A68A
	.align 2, 0
_0803A618: .4byte gUnknown_203B3F0
_0803A61C:
	ldr r3, [r2]
	adds r1, r3, 0
	adds r1, 0xAC
	movs r0, 0x3
	str r0, [r1]
	subs r1, 0x8
	movs r0, 0
	str r0, [r1]
	adds r1, 0x4
	ldr r0, _0803A670
	str r0, [r1]
	adds r2, r3, 0
	adds r2, 0xA0
	ldr r0, _0803A674
	ldr r1, [r0]
	ldrb r0, [r3, 0x4]
	lsls r0, 1
	adds r1, 0x50
	adds r1, r0
	ldrh r0, [r1]
	str r0, [r2]
	adds r1, r3, 0
	adds r1, 0xB0
	movs r0, 0x1
	str r0, [r1]
	adds r1, 0x4
	adds r0, r3, 0
	adds r0, 0xF0
	str r0, [r1]
	adds r1, 0x4
	movs r0, 0x2C
	str r0, [r1]
	adds r1, 0x4
	movs r0, 0x12
	str r0, [r1]
	adds r0, r3, 0
	adds r0, 0x9C
	bl sub_8013AA0
	bl sub_803A690
	b _0803A68A
	.align 2, 0
_0803A670: .4byte 0x000003e7
_0803A674: .4byte gUnknown_203B460
_0803A678:
	ldr r0, [r2]
	ldrb r1, [r0, 0x4]
	add r0, sp, 0x8
	movs r2, 0
	bl sub_8090A8C
	add r0, sp, 0x8
	bl sub_801B3C0
_0803A68A:
	add sp, 0xC
	pop {r0}
	bx r0
	thumb_func_end sub_803A5A0

	thumb_func_start sub_803A690
sub_803A690:
	push {r4,lr}
	sub sp, 0x4
	ldr r4, _0803A6E8
	ldr r0, [r4]
	adds r0, 0xB0
	ldr r0, [r0]
	bl sub_8008C54
	ldr r0, [r4]
	adds r0, 0xB0
	ldr r0, [r0]
	bl sub_80073B8
	ldr r2, _0803A6EC
	ldr r0, [r4]
	adds r0, 0xB0
	ldr r3, [r0]
	movs r0, 0
	str r0, [sp]
	movs r0, 0x4
	movs r1, 0
	bl xxx_call_draw_string
	ldr r0, [r4]
	adds r0, 0x9C
	bl sub_8013C68
	ldr r0, [r4]
	adds r0, 0xB0
	ldr r0, [r0]
	bl sub_80073E0
	bl sub_801CCD8
	ldr r0, [r4]
	adds r0, 0x4C
	movs r1, 0
	bl sub_8012EA4
	add sp, 0x4
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0803A6E8: .4byte gUnknown_203B3F0
_0803A6EC: .4byte gUnknown_80E7E7C
	thumb_func_end sub_803A690

	thumb_func_start sub_803A6F0
sub_803A6F0:
	push {r4,lr}
	ldr r4, _0803A734
	ldr r1, [r4]
	ldr r0, _0803A738
	str r0, [r1, 0xC]
	movs r0, 0x2
	str r0, [r1, 0x10]
	str r0, [r1, 0x8]
	ldrb r0, [r1, 0x4]
	bl sub_8091524
	lsls r0, 24
	cmp r0, 0
	bne _0803A718
	ldr r0, [r4]
	movs r1, 0x1
	negs r1, r1
	str r1, [r0, 0x10]
	movs r1, 0x3
	str r1, [r0, 0x8]
_0803A718:
	ldr r1, [r4]
	movs r2, 0x1
	ldr r0, _0803A73C
	ldr r0, [r0]
	str r0, [r1, 0x14]
	movs r0, 0x3
	str r0, [r1, 0x18]
	movs r0, 0
	str r0, [r1, 0x1C]
	str r2, [r1, 0x20]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0803A734: .4byte gUnknown_203B3F0
_0803A738: .4byte gUnknown_80E7E7C
_0803A73C: .4byte gUnknown_80D4970
	thumb_func_end sub_803A6F0

	thumb_func_start sub_803A740
sub_803A740:
	push {lr}
	movs r0, 0x1
	bl sub_801CA08
	cmp r0, 0x4
	bhi _0803A7AA
	lsls r0, 2
	ldr r1, _0803A758
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0803A758: .4byte _0803A75C
	.align 2, 0
_0803A75C:
	.4byte _0803A7AA
	.4byte _0803A7AA
	.4byte _0803A7A0
	.4byte _0803A770
	.4byte _0803A788
_0803A770:
	bl sub_801CB24
	ldr r1, _0803A784
	ldr r1, [r1]
	strb r0, [r1, 0x4]
	movs r0, 0x2
	bl sub_803A504
	b _0803A7AA
	.align 2, 0
_0803A784: .4byte gUnknown_203B3F0
_0803A788:
	bl sub_801CB24
	ldr r1, _0803A79C
	ldr r1, [r1]
	strb r0, [r1, 0x4]
	movs r0, 0x4
	bl sub_803A504
	b _0803A7AA
	.align 2, 0
_0803A79C: .4byte gUnknown_203B3F0
_0803A7A0:
	bl sub_801CBB8
	movs r0, 0x5
	bl sub_803A504
_0803A7AA:
	pop {r0}
	bx r0
	thumb_func_end sub_803A740

	thumb_func_start sub_803A7B0
sub_803A7B0:
	push {r4,lr}
	sub sp, 0x4
	movs r0, 0
	str r0, [sp]
	bl sub_801CA08
	ldr r4, _0803A7E8
	ldr r0, [r4]
	adds r0, 0x4C
	bl sub_8012FD8
	lsls r0, 24
	cmp r0, 0
	bne _0803A7D6
	ldr r0, [r4]
	adds r0, 0x4C
	mov r1, sp
	bl sub_8013114
_0803A7D6:
	ldr r0, [sp]
	cmp r0, 0x2
	beq _0803A7F2
	cmp r0, 0x2
	bgt _0803A7EC
	cmp r0, 0x1
	beq _0803A802
	b _0803A808
	.align 2, 0
_0803A7E8: .4byte gUnknown_203B3F0
_0803A7EC:
	cmp r0, 0x3
	beq _0803A7FA
	b _0803A808
_0803A7F2:
	movs r0, 0x3
	bl sub_803A504
	b _0803A808
_0803A7FA:
	movs r0, 0x4
	bl sub_803A504
	b _0803A808
_0803A802:
	movs r0, 0x1
	bl sub_803A504
_0803A808:
	add sp, 0x4
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_803A7B0

	thumb_func_start sub_803A810
sub_803A810:
	push {r4,lr}
	movs r0, 0
	bl sub_801CA08
	ldr r4, _0803A838
	ldr r0, [r4]
	adds r0, 0x4C
	bl sub_8012FD8
	ldr r0, [r4]
	adds r0, 0x9C
	bl sub_8013BBC
	cmp r0, 0x2
	beq _0803A854
	cmp r0, 0x2
	bhi _0803A83C
	cmp r0, 0x1
	beq _0803A860
	b _0803A864
	.align 2, 0
_0803A838: .4byte gUnknown_203B3F0
_0803A83C:
	cmp r0, 0x3
	bne _0803A864
	ldr r0, _0803A85C
	ldr r2, [r0]
	ldr r1, [r4]
	ldrb r0, [r1, 0x4]
	lsls r0, 1
	adds r2, 0x50
	adds r2, r0
	adds r1, 0x9C
	ldr r0, [r1]
	strh r0, [r2]
_0803A854:
	movs r0, 0x1
	bl sub_803A504
	b _0803A864
	.align 2, 0
_0803A85C: .4byte gUnknown_203B460
_0803A860:
	bl sub_803A690
_0803A864:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_803A810

	thumb_func_start sub_803A86C
sub_803A86C:
	push {lr}
	bl sub_801B410
	cmp r0, 0x1
	bls _0803A884
	cmp r0, 0x3
	bhi _0803A884
	bl sub_801B450
	movs r0, 0x1
	bl sub_803A504
_0803A884:
	pop {r0}
	bx r0
	thumb_func_end sub_803A86C

	thumb_func_start sub_803A888
sub_803A888:
	push {r4,lr}
	bl ResetUnusedInputStruct
	movs r0, 0
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	ldr r4, _0803A8B4
	movs r0, 0xFC
	movs r1, 0x8
	bl MemoryAlloc
	str r0, [r4]
	movs r0, 0
	bl sub_803A924
	movs r0, 0x1
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_0803A8B4: .4byte gUnknown_203B3F4
	thumb_func_end sub_803A888

	thumb_func_start sub_803A8B8
sub_803A8B8:
	push {lr}
	ldr r0, _0803A8D0
	ldr r0, [r0]
	ldr r0, [r0]
	cmp r0, 0x4
	bhi _0803A902
	lsls r0, 2
	ldr r1, _0803A8D4
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0803A8D0: .4byte gUnknown_203B3F4
_0803A8D4: .4byte _0803A8D8
	.align 2, 0
_0803A8D8:
	.4byte _0803A8EC
	.4byte _0803A8EC
	.4byte _0803A8F2
	.4byte _0803A8F8
	.4byte _0803A8FE
_0803A8EC:
	bl sub_803AAC4
	b _0803A902
_0803A8F2:
	bl sub_803AB34
	b _0803A902
_0803A8F8:
	bl sub_803ABAC
	b _0803A902
_0803A8FE:
	movs r0, 0x3
	b _0803A904
_0803A902:
	movs r0, 0
_0803A904:
	pop {r1}
	bx r1
	thumb_func_end sub_803A8B8

	thumb_func_start sub_803A908
sub_803A908:
	push {r4,lr}
	ldr r4, _0803A920
	ldr r0, [r4]
	cmp r0, 0
	beq _0803A91A
	bl MemoryFree
	movs r0, 0
	str r0, [r4]
_0803A91A:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0803A920: .4byte gUnknown_203B3F4
	thumb_func_end sub_803A908

	thumb_func_start sub_803A924
sub_803A924:
	push {lr}
	ldr r1, _0803A938
	ldr r1, [r1]
	str r0, [r1]
	bl sub_803A93C
	bl sub_803A9AC
	pop {r0}
	bx r0
	.align 2, 0
_0803A938: .4byte gUnknown_203B3F4
	thumb_func_end sub_803A924

	thumb_func_start sub_803A93C
sub_803A93C:
	push {r4-r7,lr}
	ldr r4, _0803A960
	ldr r0, [r4]
	adds r0, 0x9C
	bl sub_8006518
	ldr r1, [r4]
	ldr r0, [r1]
	cmp r0, 0x2
	bne _0803A968
	adds r1, 0xCC
	ldr r0, _0803A964
	ldm r0!, {r2-r4}
	stm r1!, {r2-r4}
	ldm r0!, {r5-r7}
	stm r1!, {r5-r7}
	b _0803A98A
	.align 2, 0
_0803A960: .4byte gUnknown_203B3F4
_0803A964: .4byte gUnknown_80E7EA4
_0803A968:
	mov r12, r4
	ldr r4, _0803A9A4
	movs r3, 0
	movs r2, 0x3
_0803A970:
	mov r0, r12
	ldr r1, [r0]
	adds r1, r3
	adds r1, 0x9C
	adds r0, r4, 0
	ldm r0!, {r5-r7}
	stm r1!, {r5-r7}
	ldm r0!, {r5-r7}
	stm r1!, {r5-r7}
	adds r3, 0x18
	subs r2, 0x1
	cmp r2, 0
	bge _0803A970
_0803A98A:
	bl ResetUnusedInputStruct
	ldr r0, _0803A9A8
	ldr r0, [r0]
	adds r0, 0x9C
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_0803A9A4: .4byte gUnknown_80E7E8C
_0803A9A8: .4byte gUnknown_203B3F4
	thumb_func_end sub_803A93C

	thumb_func_start sub_803A9AC
sub_803A9AC:
	push {lr}
	sub sp, 0x8
	ldr r1, _0803A9C8
	ldr r0, [r1]
	ldr r0, [r0]
	adds r2, r1, 0
	cmp r0, 0x4
	bhi _0803AA2C
	lsls r0, 2
	ldr r1, _0803A9CC
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0803A9C8: .4byte gUnknown_203B3F4
_0803A9CC: .4byte _0803A9D0
	.align 2, 0
_0803A9D0:
	.4byte _0803A9E4
	.4byte _0803A9EE
	.4byte _0803A9F6
	.4byte _0803AA20
	.4byte _0803AA2C
_0803A9E4:
	movs r0, 0
	movs r1, 0x3
	bl sub_80211AC
	b _0803AA2C
_0803A9EE:
	movs r0, 0x1
	bl sub_8021354
	b _0803AA2C
_0803A9F6:
	bl sub_8021494
	bl sub_803AA34
	ldr r0, _0803AA1C
	ldr r2, [r0]
	adds r0, r2, 0
	adds r0, 0x4C
	adds r1, r2, 0
	adds r1, 0xC
	ldr r2, [r2, 0x8]
	str r2, [sp]
	movs r2, 0x2
	str r2, [sp, 0x4]
	movs r2, 0
	movs r3, 0
	bl sub_8012D60
	b _0803AA2C
	.align 2, 0
_0803AA1C: .4byte gUnknown_203B3F4
_0803AA20:
	ldr r0, [r2]
	ldrb r0, [r0, 0x4]
	movs r1, 0x1
	movs r2, 0
	bl sub_8021774
_0803AA2C:
	add sp, 0x8
	pop {r0}
	bx r0
	thumb_func_end sub_803A9AC

	thumb_func_start sub_803AA34
sub_803AA34:
	push {r4,r5,lr}
	movs r4, 0
	ldr r0, _0803AA64
	ldr r1, [r0]
	ldr r2, _0803AA68
	ldr r3, [r2]
	ldrb r0, [r3, 0x4]
	adds r1, r0
	ldrb r0, [r1]
	adds r5, r2, 0
	cmp r0, 0
	beq _0803AA7A
	ldr r0, _0803AA6C
	str r0, [r3, 0xC]
	bl sub_803ABC8
	lsls r0, 24
	cmp r0, 0
	beq _0803AA70
	ldr r1, [r5]
	movs r0, 0x3
	str r0, [r1, 0x10]
	b _0803AA82
	.align 2, 0
_0803AA64: .4byte gFriendAreas
_0803AA68: .4byte gUnknown_203B3F4
_0803AA6C: .4byte gUnknown_80E7EBC
_0803AA70:
	ldr r1, [r5]
	movs r0, 0x1
	negs r0, r0
	str r0, [r1, 0x10]
	b _0803AA82
_0803AA7A:
	ldr r0, _0803AABC
	str r0, [r3, 0xC]
	movs r0, 0x2
	str r0, [r3, 0x10]
_0803AA82:
	adds r4, 0x1
	ldr r5, [r5]
	mov r12, r5
	lsls r1, r4, 3
	mov r3, r12
	adds r3, 0xC
	adds r2, r3, r1
	ldr r0, _0803AAC0
	ldr r0, [r0]
	str r0, [r2]
	mov r2, r12
	adds r2, 0x10
	adds r1, r2, r1
	movs r0, 0x4
	str r0, [r1]
	adds r4, 0x1
	lsls r1, r4, 3
	adds r3, r1
	movs r0, 0
	str r0, [r3]
	adds r2, r1
	movs r0, 0x1
	str r0, [r2]
	mov r1, r12
	ldr r0, [r1, 0x10]
	str r0, [r1, 0x8]
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_0803AABC: .4byte gUnknown_80E7EC4
_0803AAC0: .4byte gUnknown_80D4970
	thumb_func_end sub_803AA34

	thumb_func_start sub_803AAC4
sub_803AAC4:
	push {lr}
	movs r0, 0x1
	bl sub_8021274
	cmp r0, 0x4
	bhi _0803AB2E
	lsls r0, 2
	ldr r1, _0803AADC
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0803AADC: .4byte _0803AAE0
	.align 2, 0
_0803AAE0:
	.4byte _0803AB2E
	.4byte _0803AB2E
	.4byte _0803AB24
	.4byte _0803AAF4
	.4byte _0803AB0C
_0803AAF4:
	bl sub_802132C
	ldr r1, _0803AB08
	ldr r1, [r1]
	strb r0, [r1, 0x4]
	movs r0, 0x2
	bl sub_803A924
	b _0803AB2E
	.align 2, 0
_0803AB08: .4byte gUnknown_203B3F4
_0803AB0C:
	bl sub_802132C
	ldr r1, _0803AB20
	ldr r1, [r1]
	strb r0, [r1, 0x4]
	movs r0, 0x3
	bl sub_803A924
	b _0803AB2E
	.align 2, 0
_0803AB20: .4byte gUnknown_203B3F4
_0803AB24:
	bl sub_80213A0
	movs r0, 0x4
	bl sub_803A924
_0803AB2E:
	pop {r0}
	bx r0
	thumb_func_end sub_803AAC4

	thumb_func_start sub_803AB34
sub_803AB34:
	push {r4,lr}
	sub sp, 0x4
	movs r0, 0
	str r0, [sp]
	bl sub_8021274
	ldr r4, _0803AB6C
	ldr r0, [r4]
	adds r0, 0x4C
	bl sub_8012FD8
	lsls r0, 24
	cmp r0, 0
	bne _0803AB5A
	ldr r0, [r4]
	adds r0, 0x4C
	mov r1, sp
	bl sub_8013114
_0803AB5A:
	ldr r0, [sp]
	cmp r0, 0x2
	beq _0803AB7A
	cmp r0, 0x2
	bgt _0803AB70
	cmp r0, 0x1
	beq _0803AB9E
	b _0803ABA4
	.align 2, 0
_0803AB6C: .4byte gUnknown_203B3F4
_0803AB70:
	cmp r0, 0x3
	beq _0803AB84
	cmp r0, 0x4
	beq _0803AB96
	b _0803ABA4
_0803AB7A:
	ldr r0, [r4]
	ldrb r0, [r0, 0x4]
	bl UnlockFriendArea
	b _0803AB8E
_0803AB84:
	ldr r0, [r4]
	ldrb r0, [r0, 0x4]
	movs r1, 0x1
	bl sub_809249C
_0803AB8E:
	movs r0, 0x1
	bl sub_803A924
	b _0803ABA4
_0803AB96:
	movs r0, 0x3
	bl sub_803A924
	b _0803ABA4
_0803AB9E:
	movs r0, 0x1
	bl sub_803A924
_0803ABA4:
	add sp, 0x4
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_803AB34

	thumb_func_start sub_803ABAC
sub_803ABAC:
	push {lr}
	bl sub_80217EC
	cmp r0, 0x1
	bls _0803ABC4
	cmp r0, 0x3
	bhi _0803ABC4
	bl sub_8021830
	movs r0, 0x1
	bl sub_803A924
_0803ABC4:
	pop {r0}
	bx r0
	thumb_func_end sub_803ABAC

	thumb_func_start sub_803ABC8
sub_803ABC8:
	push {r4-r6,lr}
	movs r5, 0
	movs r6, 0x1
_0803ABCE:
	ldr r2, _0803AC08
	movs r0, 0x58
	adds r1, r5, 0
	muls r1, r0
	ldr r0, [r2]
	adds r2, r0, r1
	ldrh r1, [r2]
	adds r0, r6, 0
	ands r0, r1
	cmp r0, 0
	beq _0803AC10
	lsrs r0, r1, 1
	ands r0, r6
	cmp r0, 0
	beq _0803AC10
	ldr r0, _0803AC0C
	ldr r4, [r0]
	movs r1, 0x8
	ldrsh r0, [r2, r1]
	bl GetFriendArea
	ldrb r1, [r4, 0x4]
	lsls r0, 24
	lsrs r0, 24
	cmp r1, r0
	bne _0803AC10
	movs r0, 0
	b _0803AC1C
	.align 2, 0
_0803AC08: .4byte gUnknown_203B45C
_0803AC0C: .4byte gUnknown_203B3F4
_0803AC10:
	adds r5, 0x1
	movs r0, 0xCE
	lsls r0, 1
	cmp r5, r0
	ble _0803ABCE
	movs r0, 0x1
_0803AC1C:
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end sub_803ABC8

	thumb_func_start sub_803AC24
sub_803AC24:
	push {r4,lr}
	ldr r4, _0803AC44
	movs r0, 0xA0
	lsls r0, 1
	movs r1, 0x8
	bl MemoryAlloc
	str r0, [r4]
	movs r0, 0
	bl sub_803ACD0
	movs r0, 0x1
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_0803AC44: .4byte gUnknown_203B3F8
	thumb_func_end sub_803AC24

	thumb_func_start sub_803AC48
sub_803AC48:
	push {lr}
	ldr r0, _0803AC60
	ldr r0, [r0]
	ldr r0, [r0]
	cmp r0, 0x7
	bhi _0803ACA8
	lsls r0, 2
	ldr r1, _0803AC64
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0803AC60: .4byte gUnknown_203B3F8
_0803AC64: .4byte _0803AC68
	.align 2, 0
_0803AC68:
	.4byte _0803AC88
	.4byte _0803AC90
	.4byte _0803AC90
	.4byte _0803AC96
	.4byte _0803ACA8
	.4byte _0803AC9C
	.4byte _0803ACA2
	.4byte _0803ACA8
_0803AC88:
	movs r0, 0x1
	bl sub_803ACD0
	b _0803ACAC
_0803AC90:
	bl sub_803AF38
	b _0803ACAC
_0803AC96:
	bl sub_803AF88
	b _0803ACAC
_0803AC9C:
	bl sub_803AFE8
	b _0803ACAC
_0803ACA2:
	bl sub_803B034
	b _0803ACAC
_0803ACA8:
	movs r0, 0x3
	b _0803ACAE
_0803ACAC:
	movs r0, 0
_0803ACAE:
	pop {r1}
	bx r1
	thumb_func_end sub_803AC48

	thumb_func_start sub_803ACB4
sub_803ACB4:
	push {r4,lr}
	ldr r4, _0803ACCC
	ldr r0, [r4]
	cmp r0, 0
	beq _0803ACC6
	bl MemoryFree
	movs r0, 0
	str r0, [r4]
_0803ACC6:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0803ACCC: .4byte gUnknown_203B3F8
	thumb_func_end sub_803ACB4

	thumb_func_start sub_803ACD0
sub_803ACD0:
	push {lr}
	ldr r1, _0803ACE4
	ldr r1, [r1]
	str r0, [r1]
	bl sub_803ACE8
	bl sub_803AD88
	pop {r0}
	bx r0
	.align 2, 0
_0803ACE4: .4byte gUnknown_203B3F8
	thumb_func_end sub_803ACD0

	thumb_func_start sub_803ACE8
sub_803ACE8:
	push {r4-r7,lr}
	ldr r4, _0803AD08
	ldr r0, [r4]
	adds r0, 0xE0
	bl sub_8006518
	ldr r1, [r4]
	ldr r0, [r1]
	cmp r0, 0x3
	beq _0803AD10
	cmp r0, 0x5
	beq _0803AD38
	movs r2, 0
	ldr r3, _0803AD0C
	b _0803AD50
	.align 2, 0
_0803AD08: .4byte gUnknown_203B3F8
_0803AD0C: .4byte gUnknown_80E7ED4
_0803AD10:
	bl sub_803AEB0
	ldr r2, [r4]
	movs r0, 0x88
	lsls r0, 1
	adds r2, r0
	ldr r1, _0803AD34
	ldm r1!, {r3,r5,r6}
	stm r2!, {r3,r5,r6}
	ldm r1!, {r3,r5,r7}
	stm r2!, {r3,r5,r7}
	ldr r1, [r4]
	adds r0, r1, r0
	adds r1, 0x90
	bl sub_8012CAC
	b _0803AD6C
	.align 2, 0
_0803AD34: .4byte gUnknown_80E7EEC
_0803AD38:
	movs r6, 0x94
	lsls r6, 1
	adds r1, r6
	ldr r0, _0803AD4C
	ldm r0!, {r2,r3,r7}
	stm r1!, {r2,r3,r7}
	ldm r0!, {r4-r6}
	stm r1!, {r4-r6}
	b _0803AD6C
	.align 2, 0
_0803AD4C: .4byte gUnknown_80E7F04
_0803AD50:
	ldr r0, [r4]
	lsls r1, r2, 1
	adds r1, r2
	lsls r1, 3
	adds r0, r1
	adds r0, 0xE0
	adds r1, r3, 0
	ldm r1!, {r5-r7}
	stm r0!, {r5-r7}
	ldm r1!, {r5-r7}
	stm r0!, {r5-r7}
	adds r2, 0x1
	cmp r2, 0x3
	ble _0803AD50
_0803AD6C:
	bl ResetUnusedInputStruct
	ldr r0, _0803AD84
	ldr r0, [r0]
	adds r0, 0xE0
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_0803AD84: .4byte gUnknown_203B3F8
	thumb_func_end sub_803ACE8

	thumb_func_start sub_803AD88
sub_803AD88:
	push {lr}
	sub sp, 0x8
	ldr r1, _0803ADA4
	ldr r0, [r1]
	ldr r0, [r0]
	adds r2, r1, 0
	cmp r0, 0x7
	bhi _0803AE50
	lsls r0, 2
	ldr r1, _0803ADA8
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0803ADA4: .4byte gUnknown_203B3F8
_0803ADA8: .4byte _0803ADAC
	.align 2, 0
_0803ADAC:
	.4byte _0803AE50
	.4byte _0803ADCC
	.4byte _0803ADDA
	.4byte _0803ADE2
	.4byte _0803AE50
	.4byte _0803AE0C
	.4byte _0803AE44
	.4byte _0803AE50
_0803ADCC:
	movs r0, 0x1
	movs r1, 0
	movs r2, 0
	movs r3, 0xA
	bl sub_8023868
	b _0803AE50
_0803ADDA:
	movs r0, 0x1
	bl sub_8023B7C
	b _0803AE50
_0803ADE2:
	bl sub_8023DA4
	ldr r0, _0803AE08
	ldr r2, [r0]
	adds r0, r2, 0
	adds r0, 0x10
	adds r1, r2, 0
	adds r1, 0x90
	adds r3, r2, 0
	adds r3, 0xD0
	ldr r2, [r2, 0xC]
	str r2, [sp]
	movs r2, 0x2
	str r2, [sp, 0x4]
	movs r2, 0
	bl sub_8012D60
	b _0803AE50
	.align 2, 0
_0803AE08: .4byte gUnknown_203B3F8
_0803AE0C:
	ldr r2, [r2]
	movs r1, 0x3
	str r1, [r2, 0x70]
	movs r0, 0x1
	str r0, [r2, 0x68]
	movs r0, 0x64
	str r0, [r2, 0x6C]
	ldr r0, [r2, 0x8]
	ldrb r0, [r0, 0x3]
	str r0, [r2, 0x64]
	str r1, [r2, 0x74]
	movs r1, 0x94
	lsls r1, 1
	adds r0, r2, r1
	str r0, [r2, 0x78]
	movs r0, 0x2C
	str r0, [r2, 0x7C]
	adds r1, r2, 0
	adds r1, 0x80
	movs r0, 0x12
	str r0, [r1]
	adds r0, r2, 0
	adds r0, 0x60
	bl sub_8013AA0
	bl sub_803AE58
	b _0803AE50
_0803AE44:
	ldr r0, [r2]
	ldr r1, [r0, 0x8]
	adds r1, 0x4C
	movs r0, 0x2
	bl sub_801602C
_0803AE50:
	add sp, 0x8
	pop {r0}
	bx r0
	thumb_func_end sub_803AD88

	thumb_func_start sub_803AE58
sub_803AE58:
	push {r4,lr}
	sub sp, 0x4
	ldr r4, _0803AEA8
	ldr r0, [r4]
	ldr r0, [r0, 0x74]
	bl sub_8008C54
	ldr r0, [r4]
	ldr r0, [r0, 0x74]
	bl sub_80073B8
	ldr r2, _0803AEAC
	ldr r0, [r4]
	ldr r3, [r0, 0x74]
	movs r0, 0
	str r0, [sp]
	movs r0, 0x4
	movs r1, 0
	bl xxx_call_draw_string
	ldr r0, [r4]
	adds r0, 0x60
	bl sub_8013C68
	ldr r0, [r4]
	ldr r0, [r0, 0x74]
	bl sub_80073E0
	bl sub_8023DA4
	ldr r0, [r4]
	adds r0, 0x10
	movs r1, 0
	bl sub_8012EA4
	add sp, 0x4
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0803AEA8: .4byte gUnknown_203B3F8
_0803AEAC: .4byte gUnknown_80E7F1C
	thumb_func_end sub_803AE58

	thumb_func_start sub_803AEB0
sub_803AEB0:
	push {r4-r6,lr}
	ldr r4, _0803AEFC
	ldr r0, [r4]
	adds r0, 0xD0
	movs r1, 0
	movs r2, 0x10
	bl MemoryFill16
	ldr r4, [r4]
	movs r3, 0
	adds r1, r4, 0
	adds r1, 0x90
	ldr r0, _0803AF00
	str r0, [r1]
	adds r5, r4, 0
	adds r5, 0x94
	movs r0, 0x4
	str r0, [r5]
	movs r2, 0x1
	adds r1, 0x8
	ldr r0, _0803AF04
	str r0, [r1]
	adds r1, 0x4
	movs r0, 0x5
	str r0, [r1]
	movs r6, 0x2
	adds r0, r4, 0
	adds r0, 0xA0
	str r3, [r0]
	adds r0, 0x4
	str r2, [r0]
	adds r0, 0x2C
	ldrh r0, [r0]
	cmp r0, 0
	bne _0803AF08
	ldr r0, [r5]
	str r0, [r4, 0xC]
	b _0803AF2C
	.align 2, 0
_0803AEFC: .4byte gUnknown_203B3F8
_0803AF00: .4byte gUnknown_80E7F24
_0803AF04: .4byte gUnknown_80E7F2C
_0803AF08:
	adds r3, 0x1
	cmp r3, r6
	bge _0803AF2C
	ldr r0, _0803AF34
	ldr r2, [r0]
	lsls r1, r3, 1
	adds r0, r2, 0
	adds r0, 0xD0
	adds r0, r1
	ldrh r0, [r0]
	cmp r0, 0
	bne _0803AF08
	lsls r0, r3, 3
	adds r1, r2, 0
	adds r1, 0x94
	adds r1, r0
	ldr r0, [r1]
	str r0, [r2, 0xC]
_0803AF2C:
	pop {r4-r6}
	pop {r0}
	bx r0
	.align 2, 0
_0803AF34: .4byte gUnknown_203B3F8
	thumb_func_end sub_803AEB0

	thumb_func_start sub_803AF38
sub_803AF38:
	push {lr}
	movs r0, 0x1
	bl sub_8023A94
	cmp r0, 0x2
	beq _0803AF78
	cmp r0, 0x2
	bcc _0803AF82
	cmp r0, 0x3
	bne _0803AF82
	bl sub_8023B44
	ldr r1, _0803AF70
	ldr r1, [r1]
	strh r0, [r1, 0x4]
	ldr r3, _0803AF74
	movs r0, 0x4
	ldrsh r2, [r1, r0]
	movs r0, 0x58
	muls r2, r0
	ldr r0, [r3]
	adds r0, r2
	str r0, [r1, 0x8]
	movs r0, 0x3
	bl sub_803ACD0
	b _0803AF82
	.align 2, 0
_0803AF70: .4byte gUnknown_203B3F8
_0803AF74: .4byte gUnknown_203B45C
_0803AF78:
	bl sub_8023C60
	movs r0, 0x7
	bl sub_803ACD0
_0803AF82:
	pop {r0}
	bx r0
	thumb_func_end sub_803AF38

        .align 2,0
