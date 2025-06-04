	#include "asm/constants/gba_constants.inc"
	#include "asm/macros.inc"

	.syntax unified

	.text	




	thumb_func_start sub_80A3440
sub_80A3440:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x4C
	mov r9, r0
	str r2, [sp, 0x34]
	str r3, [sp, 0x38]
	lsls r1, 16
	asrs r5, r1, 16
	movs r0, 0x1
	negs r0, r0
	cmp r5, r0
	beq _080A3464
	ldrb r0, [r2]
	cmp r0, 0x63
	bne _080A346C
_080A3464:
	mov r0, r9
	bl sub_80A2E64
	b _080A376C
_080A346C:
	mov r0, r9
	adds r1, r5, 0
	bl sub_80A2FBC
	mov r0, r9
	bl sub_80A2DD4
	ldr r0, _080A377C
	add r0, r9
	strh r5, [r0]
	lsls r4, r5, 3
	subs r4, r5
	lsls r4, 2
	ldr r0, _080A3780
	adds r4, r0
	ldr r0, [r4]
	ldr r5, _080A3784
	adds r1, r5, 0
	bl OpenFileAndGetFileDataPtr
	movs r1, 0x86
	lsls r1, 3
	add r1, r9
	mov r8, r1
	str r0, [r1]
	ldr r0, [r4, 0x4]
	adds r1, r5, 0
	bl OpenFileAndGetFileDataPtr
	ldr r6, _080A3788
	add r6, r9
	str r0, [r6]
	ldr r0, [r4, 0x8]
	adds r1, r5, 0
	bl OpenFileAndGetFileDataPtr
	movs r1, 0x87
	lsls r1, 3
	add r1, r9
	str r0, [r1]
	mov r2, r8
	ldr r1, [r2]
	ldr r2, [r1, 0x4]
	ldr r1, [r6]
	ldr r3, [r1, 0x4]
	ldr r7, [r0, 0x4]
	ldr r1, _080A378C
	add r1, r9
	ldr r4, _080A3790
	add r4, r9
	str r4, [sp, 0x3C]
	movs r0, 0x89
	lsls r0, 3
	add r0, r9
	mov r10, r0
	ldrb r0, [r2]
	strh r0, [r1]
	ldrb r0, [r2, 0x2]
	strh r0, [r1, 0x2]
	ldrh r0, [r3]
	strh r0, [r4]
	adds r3, 0x2
	ldrh r0, [r3]
	strh r0, [r4, 0x2]
	adds r3, 0x2
	ldrh r0, [r3]
	strh r0, [r4, 0x4]
	adds r3, 0x2
	add r5, sp, 0x2C
	ldr r1, _080A3794
	add r1, r9
	str r1, [sp, 0x48]
	movs r2, 0x3
_080A34FE:
	ldrh r0, [r3]
	strh r0, [r1]
	adds r3, 0x2
	adds r1, 0x2
	subs r2, 0x1
	cmp r2, 0
	bge _080A34FE
	ldrh r0, [r3]
	movs r2, 0
	mov r8, r2
	ldr r4, [sp, 0x3C]
	strh r0, [r4, 0xE]
	ldrb r0, [r7]
	mov r1, r10
	strb r0, [r1]
	adds r7, 0x1
	ldrb r0, [r7]
	strb r0, [r1, 0x1]
	adds r7, 0x1
	ldrb r0, [r7]
	strb r0, [r1, 0x2]
	adds r7, 0x1
	ldrb r0, [r7]
	strb r0, [r1, 0x3]
	adds r7, 0x1
	ldrb r0, [r7]
	strb r0, [r1, 0x4]
	adds r7, 0x1
	ldrb r0, [r7]
	strb r0, [r1, 0x5]
	adds r7, 0x1
	ldrb r0, [r7]
	strh r0, [r1, 0x6]
	adds r7, 0x2
	ldrb r0, [r7]
	strh r0, [r1, 0x8]
	adds r7, 0x2
	ldrb r0, [r7]
	strh r0, [r1, 0xA]
	adds r7, 0x2
	ldr r4, _080A3798
	add r4, r9
	ldr r0, [r4]
	str r0, [sp, 0x2C]
	str r2, [r5, 0x4]
	ldr r2, _080A379C
	add r2, r9
	movs r3, 0x89
	lsls r3, 3
	add r3, r9
	adds r0, r5, 0
	adds r1, r7, 0
	bl sub_80A3908
	adds r7, r0, 0
	movs r0, 0x8D
	lsls r0, 3
	add r0, r9
	str r7, [r0]
	ldr r5, _080A37A0
	add r5, r9
	movs r6, 0x88
	lsls r6, 3
	add r6, r9
	ldr r2, _080A37A4
	movs r0, 0xA9
	lsls r0, 3
	add r0, r9
	ldr r3, [r0]
	ldr r0, _080A37A8
	add r0, r9
	ldr r0, [r0]
	str r0, [sp]
	ldr r0, [sp, 0x34]
	str r0, [sp, 0x4]
	ldr r1, [sp, 0x38]
	str r1, [sp, 0x8]
	movs r0, 0x40
	str r0, [sp, 0xC]
	mov r1, r10
	ldrb r0, [r1, 0x5]
	str r0, [sp, 0x10]
	ldr r0, [r4]
	str r0, [sp, 0x14]
	mov r0, r8
	str r0, [sp, 0x18]
	adds r0, r5, 0
	adds r1, r6, 0
	bl sub_80ADD9C
	ldr r0, [r5]
	movs r1, 0
	bl GetFileDataPtr
	ldr r0, [r6]
	movs r1, 0
	bl GetFileDataPtr
	movs r2, 0xA8
	lsls r2, 3
	add r2, r9
	ldr r0, [r4]
	ldr r1, _080A37AC
	add r1, r9
	movs r4, 0
	ldrsh r3, [r1, r4]
	ldr r4, [r2]
	adds r1, r7, 0
	mov r2, r10
	bl _call_via_r4
	movs r0, 0x80
	lsls r0, 2
	ldr r1, [sp, 0x3C]
	strh r0, [r1, 0x4]
	ldr r1, [sp, 0x48]
	movs r2, 0
	adds r0, r1, 0x6
_080A35EA:
	strh r2, [r0]
	subs r0, 0x2
	cmp r0, r1
	bge _080A35EA
	movs r2, 0
	movs r0, 0xFA
	ldr r4, [sp, 0x3C]
	strh r0, [r4, 0xE]
	ldr r1, _080A378C
	add r1, r9
	movs r0, 0xC
	strh r0, [r1]
	ldr r0, _080A37B0
	add r0, r9
	strh r2, [r0]
	ldr r0, _080A37A0
	add r0, r9
	ldr r0, [r0]
	cmp r0, 0
	beq _080A36E6
	ldr r4, [r0, 0x4]
	movs r7, 0
	str r7, [sp, 0x1C]
	add r1, sp, 0x20
	movs r0, 0xFF
	strb r0, [r1]
	movs r0, 0x1
	negs r0, r0
	strb r0, [r1, 0x1]
	strb r0, [r1, 0x2]
	movs r0, 0
	strb r0, [r1, 0x3]
	movs r5, 0
	ldr r0, _080A37B4
	add r0, r9
	movs r1, 0
	ldrsh r0, [r0, r1]
	cmp r5, r0
	bge _080A36E6
	mov r2, sp
	adds r2, 0x28
	str r2, [sp, 0x40]
	mov r0, sp
	adds r0, 0x29
	str r0, [sp, 0x44]
	movs r1, 0x2A
	add r1, sp
	mov r10, r1
	movs r2, 0x2B
	add r2, sp
	mov r8, r2
_080A3650:
	adds r0, r7, 0
	adds r1, r0, 0x1
	lsls r1, 16
	lsrs r7, r1, 16
	ldr r1, [sp, 0x1C]
	bl sub_8003810
	adds r4, 0x4
	adds r6, r5, 0x1
	movs r5, 0xE
_080A3664:
	ldrb r0, [r4]
	ldr r1, [sp, 0x40]
	strb r0, [r1]
	ldrb r0, [r4, 0x1]
	ldr r2, [sp, 0x44]
	strb r0, [r2]
	ldrb r0, [r4, 0x2]
	mov r1, r10
	strb r0, [r1]
	ldrb r0, [r4, 0x3]
	mov r2, r8
	strb r0, [r2]
	ldr r1, [sp, 0x28]
	str r1, [sp, 0x24]
	adds r0, r7, 0
	adds r2, r0, 0x1
	lsls r2, 16
	lsrs r7, r2, 16
	bl sub_8003810
	adds r4, 0x4
	subs r5, 0x1
	cmp r5, 0
	bge _080A3664
	adds r5, r6, 0
	cmp r5, 0xB
	bgt _080A36A6
	ldr r0, _080A37B4
	add r0, r9
	movs r1, 0
	ldrsh r0, [r0, r1]
	cmp r5, r0
	blt _080A3650
_080A36A6:
	ldr r0, _080A37B4
	add r0, r9
	movs r2, 0
	ldrsh r0, [r0, r2]
	cmp r5, r0
	bge _080A36E6
_080A36B2:
	adds r0, r7, 0
	adds r1, r0, 0x1
	lsls r1, 16
	lsrs r7, r1, 16
	ldr r1, [sp, 0x1C]
	bl sub_8003810
	adds r6, r5, 0x1
	movs r5, 0xE
_080A36C4:
	adds r0, r7, 0
	adds r1, r0, 0x1
	lsls r1, 16
	lsrs r7, r1, 16
	ldr r1, [sp, 0x20]
	bl sub_8003810
	subs r5, 0x1
	cmp r5, 0
	bge _080A36C4
	adds r5, r6, 0
	ldr r0, _080A37B4
	add r0, r9
	movs r4, 0
	ldrsh r0, [r0, r4]
	cmp r5, r0
	blt _080A36B2
_080A36E6:
	mov r4, r9
	movs r0, 0x88
	lsls r0, 3
	add r0, r9
	ldr r1, [r0]
	cmp r1, 0
	beq _080A36FE
	mov r0, r9
	adds r0, 0xE0
	movs r2, 0x20
	bl sub_8004AA4
_080A36FE:
	ldr r0, _080A37B8
	add r0, r9
	movs r1, 0
	str r1, [r0]
	movs r0, 0x8E
	lsls r0, 3
	add r0, r9
	strb r1, [r0]
	ldr r0, _080A37BC
	add r0, r9
	strb r1, [r0]
	movs r0, 0
	movs r1, 0xD
_080A3718:
	strh r0, [r4]
	strh r0, [r4, 0x2]
	str r0, [r4, 0x8]
	str r0, [r4, 0x4]
	subs r1, 0x1
	adds r4, 0x10
	cmp r1, 0
	bge _080A3718
	movs r1, 0
	movs r0, 0xF8
	lsls r0, 2
	add r0, r9
	movs r2, 0x1
_080A3732:
	strb r1, [r0]
	strb r1, [r0, 0x1]
	strh r1, [r0, 0x4]
	strh r1, [r0, 0x2]
	str r1, [r0, 0x8]
	str r1, [r0, 0xC]
	str r1, [r0, 0x14]
	str r1, [r0, 0x10]
	str r1, [r0, 0x1C]
	str r1, [r0, 0x18]
	str r1, [r0, 0x20]
	str r1, [r0, 0x24]
	adds r0, 0x28
	subs r2, 0x1
	cmp r2, 0
	bge _080A3732
	mov r0, r9
	movs r1, 0
	bl sub_80A3BB0
	movs r0, 0x91
	lsls r0, 3
	add r0, r9
	bl sub_80A3EB0
	ldr r1, _080A37C0
	add r1, r9
	movs r0, 0x1
	strb r0, [r1]
_080A376C:
	add sp, 0x4C
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_080A377C: .4byte 0x00000444
_080A3780: .4byte gUnknown_81188F0
_080A3784: .4byte gGroundFileArchive
_080A3788: .4byte 0x00000434
_080A378C: .4byte 0x00000464
_080A3790: .4byte 0x00000454
_080A3794: .4byte 0x0000045a
_080A3798: .4byte 0x00000544
_080A379C: .4byte 0x0000052c
_080A37A0: .4byte 0x0000043c
_080A37A4: .4byte 0x06008000
_080A37A8: .4byte 0x0000054c
_080A37AC: .4byte 0x0000053a
_080A37B0: .4byte 0x00000466
_080A37B4: .4byte 0x0000052e
_080A37B8: .4byte 0x0000046c
_080A37BC: .4byte 0x00000471
_080A37C0: .4byte 0x0000052a
	thumb_func_end sub_80A3440

	thumb_func_start sub_80A37C4
sub_80A37C4:
	push {r4-r6,lr}
	adds r6, r2, 0
	adds r4, r1, 0
	adds r2, r0, 0
	movs r0, 0
	movs r1, 0xF
_080A37D0:
	strh r0, [r2]
	adds r2, 0x2
	subs r1, 0x1
	cmp r1, 0
	bge _080A37D0
	movs r0, 0x1
	movs r1, 0x4
	ldrsh r3, [r3, r1]
	cmp r0, r3
	bge _080A37FE
	adds r5, r3, 0
_080A37E6:
	adds r3, r0, 0x1
	movs r1, 0xF
_080A37EA:
	ldrh r0, [r4]
	strh r0, [r2]
	adds r4, 0x2
	adds r2, 0x2
	subs r1, 0x1
	cmp r1, 0
	bge _080A37EA
	adds r0, r3, 0
	cmp r0, r5
	blt _080A37E6
_080A37FE:
	movs r3, 0x6
	ldrsh r1, [r6, r3]
	cmp r0, r1
	bge _080A3820
	ldr r3, _080A3828
	adds r4, r3, 0
	adds r5, r1, 0
_080A380C:
	adds r3, r0, 0x1
	movs r1, 0xF
_080A3810:
	strh r4, [r2]
	adds r2, 0x2
	subs r1, 0x1
	cmp r1, 0
	bge _080A3810
	adds r0, r3, 0
	cmp r0, r5
	blt _080A380C
_080A3820:
	pop {r4-r6}
	pop {r0}
	bx r0
	.align 2, 0
_080A3828: .4byte 0x0000ffff
	thumb_func_end sub_80A37C4

	thumb_func_start _UncompressCell
_UncompressCell:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	adds r5, r1, 0
	mov r8, r3
	ldr r3, [sp, 0x18]
	adds r4, r2, 0
	adds r2, r0, 0
	mov r1, r8
	ldrh r0, [r1]
	lsls r0, 12
	ldrh r1, [r1, 0x4]
	orrs r0, r1
	lsls r0, 16
	lsrs r6, r0, 16
	ldr r1, [r3]
	ldr r0, _080A385C
	cmp r1, r0
	bne _080A3860
	movs r0, 0x1
	strh r0, [r5]
	movs r5, 0x4
	b _080A3890
	.align 2, 0
_080A385C: .4byte 0x00020002
_080A3860:
	ldr r0, _080A3870
	cmp r1, r0
	bne _080A3874
	movs r0, 0x2
	strh r0, [r5]
	movs r5, 0x9
	b _080A3890
	.align 2, 0
_080A3870: .4byte 0x00030003
_080A3874:
	movs r0, 0
	strh r0, [r5]
	ldr r0, _080A3888
	ldr r1, _080A388C
	movs r4, 0
	ldrsh r2, [r3, r4]
	movs r6, 0x2
	ldrsh r3, [r3, r6]
	bl FatalError
	.align 2, 0
_080A3888: .4byte gUnknown_81172E8
_080A388C: .4byte gUnknown_81172F4
_080A3890:
	movs r0, 0
	movs r1, 0x8
_080A3894:
	strh r0, [r2]
	adds r2, 0x2
	subs r1, 0x1
	cmp r1, 0
	bge _080A3894
	movs r0, 0x1
	movs r7, 0xE
	ldrsh r1, [r3, r7]
	cmp r0, r1
	bge _080A38DC
	mov r12, r1
_080A38AA:
	movs r1, 0
	adds r3, r0, 0x1
	cmp r1, r5
	bge _080A38C6
	adds r1, r5, 0
_080A38B4:
	ldrh r0, [r4]
	adds r0, r6, r0
	strh r0, [r2]
	adds r4, 0x2
	adds r2, 0x2
	subs r1, 0x1
	cmp r1, 0
	bne _080A38B4
	adds r1, r5, 0
_080A38C6:
	cmp r1, 0x8
	bgt _080A38D6
	movs r0, 0
_080A38CC:
	strh r0, [r2]
	adds r2, 0x2
	adds r1, 0x1
	cmp r1, 0x8
	ble _080A38CC
_080A38D6:
	adds r0, r3, 0
	cmp r0, r12
	blt _080A38AA
_080A38DC:
	mov r1, r8
	movs r4, 0x8
	ldrsh r3, [r1, r4]
	cmp r0, r3
	bge _080A38FE
	movs r4, 0
	adds r5, r3, 0
_080A38EA:
	adds r3, r0, 0x1
	movs r1, 0x8
_080A38EE:
	strh r4, [r2]
	adds r2, 0x2
	subs r1, 0x1
	cmp r1, 0
	bge _080A38EE
	adds r0, r3, 0
	cmp r0, r5
	blt _080A38EA
_080A38FE:
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end _UncompressCell

	thumb_func_start sub_80A3908
sub_80A3908:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x10
	str r0, [sp]
	str r2, [sp, 0x4]
	mov r9, r3
	adds r6, r1, 0
	movs r2, 0
	ldr r1, [sp, 0x4]
	movs r3, 0xC
	ldrsh r0, [r1, r3]
	cmp r2, r0
	blt _080A392A
	b _080A3B6C
_080A392A:
	lsls r0, r2, 2
	ldr r4, [sp]
	adds r0, r4
	ldr r0, [r0]
	mov r12, r0
	movs r1, 0
	adds r2, 0x1
	str r2, [sp, 0x8]
	mov r5, r9
	ldrb r5, [r5, 0x5]
	cmp r1, r5
	blt _080A3944
	b _080A3B2A
_080A3944:
	ldr r0, _080A39A4
	mov r10, r0
_080A3948:
	movs r2, 0
	mov r8, r2
	cmp r1, 0
	bne _080A3A18
	movs r3, 0x1
	str r3, [sp, 0xC]
	mov r4, r9
	ldrb r4, [r4, 0x4]
	cmp r1, r4
	blt _080A395E
	b _080A3B04
_080A395E:
	ldrb r1, [r6]
	adds r6, 0x1
	cmp r1, 0xBF
	ble _080A39A8
	adds r2, r1, 0
	subs r2, 0xBF
	cmp r1, 0xBF
	ble _080A39A0
	ldr r5, _080A39A4
	adds r4, r5, 0
	adds r3, r2, 0
_080A3974:
	ldrb r1, [r6]
	ldrb r0, [r6, 0x1]
	lsls r0, 8
	orrs r1, r0
	ldrb r0, [r6, 0x2]
	lsls r0, 16
	orrs r1, r0
	adds r6, 0x3
	adds r0, r1, 0
	ands r0, r4
	mov r5, r12
	strh r0, [r5]
	movs r0, 0x2
	add r12, r0
	asrs r1, 12
	ands r1, r4
	mov r5, r12
	strh r1, [r5]
	add r12, r0
	subs r3, 0x1
	cmp r3, 0
	bne _080A3974
_080A39A0:
	lsls r0, r2, 1
	b _080A3A0C
	.align 2, 0
_080A39A4: .4byte 0x00000fff
_080A39A8:
	cmp r1, 0x7F
	ble _080A39EA
	ldrb r2, [r6]
	ldrb r0, [r6, 0x1]
	lsls r0, 8
	orrs r2, r0
	ldrb r0, [r6, 0x2]
	lsls r0, 16
	orrs r2, r0
	adds r6, 0x3
	adds r4, r1, 0
	subs r4, 0x7F
	cmp r1, 0x7F
	ble _080A39E6
	adds r0, r2, 0
	mov r1, r10
	ands r0, r1
	asrs r1, r2, 12
	mov r2, r10
	ands r1, r2
	adds r3, r4, 0
_080A39D2:
	mov r5, r12
	strh r0, [r5]
	movs r2, 0x2
	add r12, r2
	mov r5, r12
	strh r1, [r5]
	add r12, r2
	subs r3, 0x1
	cmp r3, 0
	bne _080A39D2
_080A39E6:
	lsls r0, r4, 1
	b _080A3A0C
_080A39EA:
	movs r3, 0
	adds r0, r1, 0x1
	cmp r3, r1
	bgt _080A3A0A
	movs r1, 0
	adds r3, r0, 0
_080A39F6:
	mov r2, r12
	strh r1, [r2]
	movs r4, 0x2
	add r12, r4
	mov r5, r12
	strh r1, [r5]
	add r12, r4
	subs r3, 0x1
	cmp r3, 0
	bne _080A39F6
_080A3A0A:
	lsls r0, 1
_080A3A0C:
	add r8, r0
	mov r0, r9
	ldrb r0, [r0, 0x4]
	cmp r8, r0
	blt _080A395E
	b _080A3B04
_080A3A18:
	mov r4, r12
	subs r4, 0x80
	adds r1, 0x1
	str r1, [sp, 0xC]
	mov r1, r9
	ldrb r1, [r1, 0x4]
	cmp r8, r1
	bge _080A3B04
_080A3A28:
	ldrb r1, [r6]
	adds r6, 0x1
	cmp r1, 0xBF
	ble _080A3A80
	adds r5, r1, 0
	subs r5, 0xBF
	cmp r1, 0xBF
	ble _080A3A78
	ldr r2, _080A3A7C
	adds r7, r2, 0
	adds r3, r5, 0
_080A3A3E:
	ldrb r2, [r6]
	ldrb r0, [r6, 0x1]
	lsls r0, 8
	orrs r2, r0
	ldrb r0, [r6, 0x2]
	lsls r0, 16
	orrs r2, r0
	adds r6, 0x3
	adds r0, r2, 0
	ands r0, r7
	ldrh r1, [r4]
	eors r0, r1
	mov r1, r12
	strh r0, [r1]
	adds r4, 0x2
	movs r0, 0x2
	add r12, r0
	asrs r2, 12
	ands r2, r7
	ldrh r0, [r4]
	eors r2, r0
	mov r1, r12
	strh r2, [r1]
	adds r4, 0x2
	movs r2, 0x2
	add r12, r2
	subs r3, 0x1
	cmp r3, 0
	bne _080A3A3E
_080A3A78:
	lsls r0, r5, 1
	b _080A3AFA
	.align 2, 0
_080A3A7C: .4byte 0x00000fff
_080A3A80:
	cmp r1, 0x7F
	ble _080A3AD2
	ldrb r2, [r6]
	ldrb r0, [r6, 0x1]
	lsls r0, 8
	orrs r2, r0
	ldrb r0, [r6, 0x2]
	lsls r0, 16
	orrs r2, r0
	adds r6, 0x3
	adds r7, r1, 0
	subs r7, 0x7F
	cmp r1, 0x7F
	ble _080A3ACE
	adds r5, r2, 0
	mov r3, r10
	ands r5, r3
	asrs r2, 12
	ands r2, r3
	adds r3, r7, 0
_080A3AA8:
	ldrh r1, [r4]
	adds r0, r5, 0
	eors r0, r1
	mov r1, r12
	strh r0, [r1]
	adds r4, 0x2
	movs r0, 0x2
	add r12, r0
	ldrh r1, [r4]
	adds r0, r2, 0
	eors r0, r1
	mov r1, r12
	strh r0, [r1]
	adds r4, 0x2
	movs r0, 0x2
	add r12, r0
	subs r3, 0x1
	cmp r3, 0
	bne _080A3AA8
_080A3ACE:
	lsls r0, r7, 1
	b _080A3AFA
_080A3AD2:
	movs r3, 0
	adds r2, r1, 0x1
	cmp r3, r1
	bgt _080A3AF8
	adds r3, r2, 0
_080A3ADC:
	ldrh r0, [r4]
	mov r1, r12
	strh r0, [r1]
	adds r4, 0x2
	movs r5, 0x2
	add r12, r5
	ldrh r0, [r4]
	mov r1, r12
	strh r0, [r1]
	adds r4, 0x2
	add r12, r5
	subs r3, 0x1
	cmp r3, 0
	bne _080A3ADC
_080A3AF8:
	lsls r0, r2, 1
_080A3AFA:
	add r8, r0
	mov r2, r9
	ldrb r2, [r2, 0x4]
	cmp r8, r2
	blt _080A3A28
_080A3B04:
	mov r3, r8
	cmp r3, 0x3F
	bgt _080A3B1E
	movs r0, 0
_080A3B0C:
	mov r4, r12
	strh r0, [r4]
	movs r5, 0x2
	add r12, r5
	movs r1, 0x1
	add r8, r1
	mov r2, r8
	cmp r2, 0x3F
	ble _080A3B0C
_080A3B1E:
	ldr r1, [sp, 0xC]
	mov r3, r9
	ldrb r3, [r3, 0x5]
	cmp r1, r3
	bge _080A3B2A
	b _080A3948
_080A3B2A:
	ldr r4, [sp, 0x4]
	movs r5, 0x10
	ldrsh r0, [r4, r5]
	cmp r1, r0
	bge _080A3B5E
	movs r2, 0
_080A3B36:
	adds r1, 0x1
	str r1, [sp, 0xC]
	movs r0, 0x3F
	mov r8, r0
_080A3B3E:
	mov r1, r12
	strh r2, [r1]
	movs r3, 0x2
	add r12, r3
	movs r4, 0x1
	negs r4, r4
	add r8, r4
	mov r5, r8
	cmp r5, 0
	bge _080A3B3E
	ldr r1, [sp, 0xC]
	ldr r3, [sp, 0x4]
	movs r4, 0x10
	ldrsh r0, [r3, r4]
	cmp r1, r0
	blt _080A3B36
_080A3B5E:
	ldr r2, [sp, 0x8]
	ldr r5, [sp, 0x4]
	movs r1, 0xC
	ldrsh r0, [r5, r1]
	cmp r2, r0
	bge _080A3B6C
	b _080A392A
_080A3B6C:
	adds r0, r6, 0
	add sp, 0x10
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_80A3908

	thumb_func_start sub_80A3B80
sub_80A3B80:
	push {r4,lr}
	adds r3, r0, 0
	lsls r1, 24
	lsrs r1, 24
	lsls r2, 24
	lsrs r2, 24
	ldr r4, _080A3BA8
	adds r0, r3, r4
	ldr r0, [r0]
	cmp r0, 0
	beq _080A3BA2
	adds r4, 0x4
	adds r0, r3, r4
	strb r1, [r0]
	ldr r1, _080A3BAC
	adds r0, r3, r1
	strb r2, [r0]
_080A3BA2:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080A3BA8: .4byte 0x0000046c
_080A3BAC: .4byte 0x00000471
	thumb_func_end sub_80A3B80

	thumb_func_start sub_80A3BB0
sub_80A3BB0:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0x4
	adds r5, r0, 0
	lsls r1, 16
	asrs r1, 16
	adds r6, r1, 0
	movs r0, 0x91
	lsls r0, 3
	adds r0, r5
	mov r8, r0
	cmp r1, 0
	blt _080A3BD4
	cmp r1, 0x1
	ble _080A3BD4
	cmp r1, 0x4
	ble _080A3C00
_080A3BD4:
	ldr r1, _080A3BFC
	adds r0, r5, r1
	movs r1, 0x1
	str r1, [r0]
	movs r2, 0xA7
	lsls r2, 3
	adds r0, r5, r2
	movs r1, 0
	ldrsh r3, [r0, r1]
	movs r0, 0
	cmp r6, 0x1
	bne _080A3BEE
	movs r0, 0x1
_080A3BEE:
	str r0, [sp]
	mov r0, r8
	adds r1, r5, 0
	movs r2, 0
	bl sub_80A3D40
	b _080A3C48
	.align 2, 0
_080A3BFC: .4byte 0x00000474
_080A3C00:
	ldr r2, _080A3C88
	adds r0, r5, r2
	movs r7, 0x2
	str r7, [r0]
	movs r0, 0xA7
	lsls r0, 3
	adds r4, r5, r0
	movs r2, 0
	ldrsh r0, [r4, r2]
	subs r3, r0, 0x1
	movs r0, 0
	cmp r1, 0x4
	bne _080A3C1C
	movs r0, 0x1
_080A3C1C:
	str r0, [sp]
	mov r0, r8
	adds r1, r5, 0
	movs r2, 0
	bl sub_80A3D40
	movs r1, 0x9B
	lsls r1, 3
	adds r0, r5, r1
	movs r1, 0
	ldrsh r2, [r4, r1]
	subs r2, 0x1
	adds r3, r7, 0
	eors r3, r6
	negs r1, r3
	orrs r1, r3
	lsrs r1, 31
	str r1, [sp]
	adds r1, r5, 0
	movs r3, 0x1
	bl sub_80A3D40
_080A3C48:
	movs r6, 0
	ldr r2, _080A3C88
	adds r0, r5, r2
	ldr r0, [r0]
	cmp r6, r0
	bge _080A3CF0
	movs r0, 0x8F
	lsls r0, 3
	adds r7, r5, r0
	mov r4, r8
_080A3C5C:
	adds r0, r5, 0
	adds r1, r6, 0
	ldr r2, _080A3C8C
	bl sub_80A456C
	movs r1, 0x4
	ldrsh r0, [r4, r1]
	cmp r0, 0x1
	beq _080A3C72
	cmp r0, 0x2
	beq _080A3CB4
_080A3C72:
	movs r2, 0
	ldrsh r0, [r4, r2]
	cmp r0, 0x1
	beq _080A3C94
	cmp r0, 0x1
	ble _080A3C82
	cmp r0, 0x2
	beq _080A3C9C
_080A3C82:
	ldr r0, _080A3C90
	b _080A3CD6
	.align 2, 0
_080A3C88: .4byte 0x00000474
_080A3C8C: .4byte gUnknown_8117314
_080A3C90: .4byte sub_80A3EBC
_080A3C94:
	ldr r0, _080A3C98
	b _080A3CD6
	.align 2, 0
_080A3C98: .4byte sub_80A3EF4
_080A3C9C:
	ldrb r0, [r4, 0x6]
	ldr r1, _080A3CAC
	cmp r0, 0
	beq _080A3CA6
	ldr r1, _080A3CB0
_080A3CA6:
	str r1, [r4, 0x18]
	b _080A3CD8
	.align 2, 0
_080A3CAC: .4byte sub_80A4088
_080A3CB0: .4byte sub_80A41C4
_080A3CB4:
	movs r1, 0
	ldrsh r0, [r4, r1]
	cmp r0, 0x1
	beq _080A3CCC
	cmp r0, 0x1
	ble _080A3CC4
	cmp r0, 0x2
	beq _080A3CD4
_080A3CC4:
	ldr r0, _080A3CC8
	b _080A3CD6
	.align 2, 0
_080A3CC8: .4byte sub_80A3ED4
_080A3CCC:
	ldr r0, _080A3CD0
	b _080A3CD6
	.align 2, 0
_080A3CD0: .4byte sub_80A3F94
_080A3CD4:
	ldr r0, _080A3D34
_080A3CD6:
	str r0, [r4, 0x18]
_080A3CD8:
	adds r0, r4, 0
	adds r1, r7, 0
	bl sub_80A3E14
	adds r7, 0x8
	adds r4, 0x50
	adds r6, 0x1
	ldr r2, _080A3D38
	adds r0, r5, r2
	ldr r0, [r0]
	cmp r6, r0
	blt _080A3C5C
_080A3CF0:
	ldr r1, _080A3D38
	adds r0, r5, r1
	ldr r6, [r0]
	cmp r6, 0x1
	bgt _080A3D26
	lsls r0, r6, 2
	adds r0, r6
	lsls r0, 4
	mov r2, r8
	adds r4, r0, r2
_080A3D04:
	adds r0, r5, 0
	adds r1, r6, 0
	ldr r2, _080A3D3C
	bl sub_80A456C
	movs r0, 0
	str r0, [sp]
	adds r0, r4, 0
	adds r1, r5, 0
	movs r2, 0
	movs r3, 0
	bl sub_80A3D40
	adds r4, 0x50
	adds r6, 0x1
	cmp r6, 0x1
	ble _080A3D04
_080A3D26:
	add sp, 0x4
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_080A3D34: .4byte sub_80A4358
_080A3D38: .4byte 0x00000474
_080A3D3C: .4byte gUnknown_8117314
	thumb_func_end sub_80A3BB0

	thumb_func_start sub_80A3D40
sub_80A3D40:
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	adds r4, r0, 0
	adds r5, r1, 0
	mov r8, r3
	ldr r1, [sp, 0x1C]
	movs r3, 0xA5
	lsls r3, 3
	adds r0, r5, r3
	ldrh r0, [r0]
	strh r0, [r4]
	strh r2, [r4, 0x2]
	mov r7, r8
	strh r7, [r4, 0x4]
	strb r1, [r4, 0x6]
	ldr r1, _080A3E10
	adds r0, r5, r1
	ldrb r0, [r0]
	str r0, [r4, 0x8]
	subs r3, 0xDB
	adds r0, r5, r3
	ldrb r0, [r0]
	str r0, [r4, 0xC]
	movs r7, 0x89
	lsls r7, 3
	adds r0, r5, r7
	ldrb r0, [r0]
	lsls r0, 3
	str r0, [r4, 0x10]
	subs r1, 0x3
	adds r0, r5, r1
	ldrb r0, [r0]
	lsls r0, 3
	str r0, [r4, 0x14]
	adds r3, 0xFB
	adds r0, r5, r3
	ldr r0, [r0]
	str r0, [r4, 0x1C]
	movs r3, 0
	cmp r3, r8
	bge _080A3DE0
	adds r7, 0xF0
	adds r6, r5, r7
	movs r1, 0
	ldrsh r0, [r6, r1]
	cmp r2, r0
	bge _080A3DE0
	lsls r0, r2, 2
	adds r7, 0x14
	adds r0, r7
	adds r1, r0, r5
	movs r0, 0x20
	adds r0, r4
	mov r12, r0
	movs r7, 0x28
	adds r7, r4
	mov r9, r7
_080A3DB6:
	ldr r0, [r1]
	mov r7, r12
	adds r7, 0x4
	mov r12, r7
	subs r7, 0x4
	stm r7!, {r0}
	ldr r0, [r1, 0x8]
	mov r7, r9
	adds r7, 0x4
	mov r9, r7
	subs r7, 0x4
	stm r7!, {r0}
	adds r3, 0x1
	adds r1, 0x4
	adds r2, 0x1
	cmp r3, r8
	bge _080A3DE0
	movs r7, 0
	ldrsh r0, [r6, r7]
	cmp r2, r0
	blt _080A3DB6
_080A3DE0:
	cmp r3, 0x1
	bgt _080A3DF8
	movs r1, 0
	lsls r0, r3, 2
	adds r0, 0x20
	adds r0, r4
_080A3DEC:
	str r1, [r0]
	str r1, [r0, 0x8]
	adds r0, 0x4
	adds r3, 0x1
	cmp r3, 0x1
	ble _080A3DEC
_080A3DF8:
	movs r0, 0x8F
	lsls r0, 3
	adds r1, r5, r0
	adds r0, r4, 0
	bl sub_80A3E14
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_080A3E10: .4byte 0x0000044c
	thumb_func_end sub_80A3D40

	thumb_func_start sub_80A3E14
sub_80A3E14:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	adds r4, r0, 0
	adds r0, r1, 0
	ldr r1, [r0]
	mov r8, r1
	str r1, [r4, 0x30]
	cmp r1, 0
	bge _080A3E2A
	adds r1, 0x7
_080A3E2A:
	asrs r6, r1, 3
	str r6, [r4, 0x38]
	ldr r7, [r0, 0x4]
	str r7, [r4, 0x34]
	adds r0, r7, 0
	cmp r7, 0
	bge _080A3E3A
	adds r0, r7, 0x7
_080A3E3A:
	asrs r5, r0, 3
	str r5, [r4, 0x3C]
	movs r3, 0
	ldrsh r2, [r4, r3]
	cmp r2, 0x1
	beq _080A3E60
	cmp r2, 0x1
	bgt _080A3E50
	cmp r2, 0
	beq _080A3E56
	b _080A3EA4
_080A3E50:
	cmp r2, 0x2
	beq _080A3E7E
	b _080A3EA4
_080A3E56:
	str r2, [r4, 0x40]
	str r2, [r4, 0x44]
	str r2, [r4, 0x48]
	str r2, [r4, 0x4C]
	b _080A3EA4
_080A3E60:
	lsrs r1, 31
	adds r1, r6, r1
	asrs r1, 1
	str r1, [r4, 0x40]
	lsrs r0, 31
	adds r0, r5, r0
	asrs r0, 1
	str r0, [r4, 0x44]
	lsls r1, 4
	mov r2, r8
	subs r1, r2, r1
	str r1, [r4, 0x48]
	lsls r0, 4
	subs r0, r7, r0
	b _080A3EA2
_080A3E7E:
	adds r0, r6, 0
	movs r1, 0x3
	bl __divsi3
	str r0, [r4, 0x40]
	adds r0, r5, 0
	movs r1, 0x3
	bl __divsi3
	str r0, [r4, 0x44]
	lsls r0, r6, 3
	mov r3, r8
	subs r0, r3, r0
	str r0, [r4, 0x48]
	adds r0, r7, 0
	movs r1, 0x18
	bl __modsi3
_080A3EA2:
	str r0, [r4, 0x4C]
_080A3EA4:
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_80A3E14

	thumb_func_start sub_80A3EB0
sub_80A3EB0:
	push {lr}
	ldr r1, [r0, 0x18]
	bl _call_via_r1
	pop {r0}
	bx r0
	thumb_func_end sub_80A3EB0

	thumb_func_start sub_80A3EBC
sub_80A3EBC:
	push {lr}
	ldr r0, [r0, 0x28]
	movs r2, 0
	movs r1, 0x80
	lsls r1, 3
_080A3EC6:
	strh r2, [r0]
	adds r0, 0x2
	subs r1, 0x1
	cmp r1, 0
	bne _080A3EC6
	pop {r0}
	bx r0
	thumb_func_end sub_80A3EBC

	thumb_func_start sub_80A3ED4
sub_80A3ED4:
	push {lr}
	ldr r1, [r0, 0x28]
	ldr r0, [r0, 0x2C]
	movs r3, 0
	movs r2, 0x80
	lsls r2, 3
_080A3EE0:
	strh r3, [r1]
	adds r1, 0x2
	strh r3, [r0]
	adds r0, 0x2
	subs r2, 0x1
	cmp r2, 0
	bne _080A3EE0
	pop {r0}
	bx r0
	thumb_func_end sub_80A3ED4

	thumb_func_start sub_80A3EF4
sub_80A3EF4:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x10
	ldr r1, [r0, 0x44]
	lsls r1, 6
	ldr r2, [r0, 0x40]
	adds r1, r2
	lsls r1, 1
	ldr r2, [r0, 0x20]
	adds r2, r1
	movs r1, 0
	mov r12, r1
	ldr r3, [r0, 0x28]
	str r3, [sp, 0xC]
	ldr r0, [r0, 0x1C]
	mov r10, r0
	mov r0, sp
	str r0, [sp, 0x8]
_080A3F1E:
	adds r5, r2, 0
	movs r2, 0x80
	adds r2, r5
	mov r9, r2
	adds r1, 0x1
	mov r8, r1
	ldr r1, [sp, 0x8]
	mov r3, r12
	lsls r0, r3, 1
	ldr r2, [sp, 0xC]
	adds r0, r2
	movs r2, 0x1
_080A3F36:
	stm r1!, {r0}
	adds r0, 0x40
	movs r3, 0x20
	add r12, r3
	subs r2, 0x1
	cmp r2, 0
	bge _080A3F36
	movs r4, 0
	mov r7, sp
_080A3F48:
	ldrh r1, [r5]
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 1
	mov r1, r10
	adds r3, r1, r0
	adds r5, 0x2
	adds r6, r4, 0x1
	adds r4, r7, 0
	movs r2, 0x1
_080A3F5C:
	ldr r0, [r4]
	ldrh r1, [r3]
	strh r1, [r0]
	adds r3, 0x2
	adds r0, 0x2
	ldrh r1, [r3]
	strh r1, [r0]
	adds r3, 0x2
	adds r0, 0x2
	stm r4!, {r0}
	subs r2, 0x1
	cmp r2, 0
	bge _080A3F5C
	adds r4, r6, 0
	cmp r4, 0xF
	ble _080A3F48
	mov r2, r9
	mov r1, r8
	cmp r1, 0xA
	ble _080A3F1E
	add sp, 0x10
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_80A3EF4

	thumb_func_start sub_80A3F94
sub_80A3F94:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x34
	ldr r1, [r0, 0x44]
	lsls r1, 6
	ldr r2, [r0, 0x40]
	adds r1, r2
	lsls r1, 1
	ldr r2, [r0, 0x20]
	adds r3, r2, r1
	ldr r2, [r0, 0x24]
	adds r2, r1
	movs r1, 0
	ldr r4, [r0, 0x28]
	str r4, [sp, 0x2C]
	ldr r5, [r0, 0x2C]
	str r5, [sp, 0x18]
	ldr r0, [r0, 0x1C]
	str r0, [sp, 0x1C]
	mov r0, sp
	str r0, [sp, 0x10]
	mov r4, sp
	adds r4, 0x8
	str r4, [sp, 0x14]
	movs r5, 0
	str r5, [sp, 0x30]
_080A3FCE:
	mov r8, r3
	mov r12, r2
	mov r0, r8
	adds r0, 0x80
	str r0, [sp, 0x20]
	mov r4, r12
	adds r4, 0x80
	str r4, [sp, 0x24]
	adds r1, 0x1
	str r1, [sp, 0x28]
	ldr r3, [sp, 0x14]
	ldr r2, [sp, 0x10]
	ldr r5, [sp, 0x30]
	ldr r0, [sp, 0x18]
	adds r1, r5, r0
	ldr r4, [sp, 0x2C]
	adds r0, r5, r4
	movs r5, 0x1
_080A3FF2:
	stm r2!, {r0}
	stm r3!, {r1}
	adds r1, 0x40
	adds r0, 0x40
	ldr r4, [sp, 0x30]
	adds r4, 0x40
	str r4, [sp, 0x30]
	subs r5, 0x1
	cmp r5, 0
	bge _080A3FF2
	movs r2, 0
	ldr r5, [sp, 0x1C]
	mov r9, r5
_080A400C:
	mov r0, r8
	ldrh r1, [r0]
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 1
	mov r1, r9
	adds r4, r1, r0
	movs r5, 0x2
	add r8, r5
	mov r0, r12
	ldrh r1, [r0]
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 1
	mov r1, r9
	adds r3, r1, r0
	add r12, r5
	movs r5, 0
	adds r2, 0x1
	mov r10, r2
	ldr r7, [sp, 0x14]
	ldr r6, [sp, 0x10]
_080A4038:
	ldr r1, [r6]
	ldr r2, [r7]
	ldrh r0, [r4]
	strh r0, [r1]
	adds r4, 0x2
	adds r1, 0x2
	ldrh r0, [r4]
	strh r0, [r1]
	adds r4, 0x2
	adds r1, 0x2
	ldrh r0, [r3]
	strh r0, [r2]
	adds r3, 0x2
	adds r2, 0x2
	ldrh r0, [r3]
	strh r0, [r2]
	adds r3, 0x2
	adds r2, 0x2
	stm r6!, {r1}
	stm r7!, {r2}
	adds r5, 0x1
	cmp r5, 0x1
	ble _080A4038
	mov r2, r10
	cmp r2, 0xF
	ble _080A400C
	ldr r3, [sp, 0x20]
	ldr r2, [sp, 0x24]
	ldr r1, [sp, 0x28]
	cmp r1, 0xA
	ble _080A3FCE
	add sp, 0x34
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_80A3F94

	thumb_func_start sub_80A4088
sub_80A4088:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x10
	adds r4, r0, 0
	ldr r0, [r4, 0x38]
	movs r1, 0x3
	bl __modsi3
	adds r7, r0, 0
	ldr r0, [r4, 0x44]
	lsls r0, 6
	ldr r1, [r4, 0x40]
	adds r0, r1
	lsls r0, 1
	ldr r1, [r4, 0x20]
	adds r1, r0
	movs r0, 0
	mov r8, r0
	ldr r2, [r4, 0x28]
	str r2, [sp, 0xC]
	ldr r4, [r4, 0x1C]
	mov r12, r4
_080A40BA:
	adds r5, r1, 0
	movs r1, 0x80
	adds r1, r5
	mov r9, r1
	adds r0, 0x1
	mov r10, r0
	mov r1, sp
	mov r2, r8
	lsls r0, r2, 1
	ldr r2, [sp, 0xC]
	adds r0, r2
	movs r3, 0x2
_080A40D2:
	stm r1!, {r0}
	adds r0, 0x40
	movs r2, 0x20
	add r8, r2
	subs r3, 0x1
	cmp r3, 0
	bge _080A40D2
	cmp r7, 0
	beq _080A412E
	ldrh r1, [r5]
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 1
	mov r1, r12
	adds r2, r1, r0
	adds r5, 0x2
	cmp r7, 0x1
	bne _080A4116
	adds r2, 0x2
	mov r4, sp
	movs r3, 0x2
_080A40FC:
	ldr r0, [r4]
	ldrh r1, [r2]
	strh r1, [r0]
	adds r0, 0x2
	ldrh r1, [r2, 0x2]
	strh r1, [r0]
	adds r0, 0x2
	stm r4!, {r0}
	adds r2, 0x6
	subs r3, 0x1
	cmp r3, 0
	bge _080A40FC
	b _080A412E
_080A4116:
	adds r2, 0x4
	mov r4, sp
	movs r3, 0x2
_080A411C:
	ldr r1, [r4]
	ldrh r0, [r2]
	strh r0, [r1]
	adds r1, 0x2
	stm r4!, {r1}
	adds r2, 0x6
	subs r3, 0x1
	cmp r3, 0
	bge _080A411C
_080A412E:
	movs r3, 0
_080A4130:
	ldrh r1, [r5]
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 1
	mov r1, r12
	adds r2, r1, r0
	adds r5, 0x2
	adds r6, r3, 0x1
	mov r4, sp
	movs r3, 0x2
_080A4144:
	ldr r1, [r4]
	ldrh r0, [r2]
	strh r0, [r1]
	adds r2, 0x2
	adds r1, 0x2
	ldrh r0, [r2]
	strh r0, [r1]
	adds r2, 0x2
	adds r1, 0x2
	ldrh r0, [r2]
	strh r0, [r1]
	adds r2, 0x2
	adds r1, 0x2
	stm r4!, {r1}
	subs r3, 0x1
	cmp r3, 0
	bge _080A4144
	adds r3, r6, 0
	cmp r3, 0x9
	ble _080A4130
	cmp r7, 0x1
	beq _080A41AA
	ldrh r1, [r5]
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 1
	mov r1, r12
	adds r2, r1, r0
	cmp r7, 0
	bne _080A4198
	mov r4, sp
	movs r3, 0x2
_080A4184:
	ldm r4!, {r0}
	ldrh r1, [r2]
	strh r1, [r0]
	ldrh r1, [r2, 0x2]
	strh r1, [r0, 0x2]
	adds r2, 0x6
	subs r3, 0x1
	cmp r3, 0
	bge _080A4184
	b _080A41AA
_080A4198:
	mov r4, sp
	movs r3, 0x2
_080A419C:
	ldm r4!, {r1}
	ldrh r0, [r2]
	strh r0, [r1]
	adds r2, 0x6
	subs r3, 0x1
	cmp r3, 0
	bge _080A419C
_080A41AA:
	mov r1, r9
	mov r0, r10
	cmp r0, 0x7
	ble _080A40BA
	add sp, 0x10
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_80A4088

	thumb_func_start sub_80A41C4
sub_80A41C4:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x20
	mov r8, r0
	ldr r0, [r0, 0x38]
	movs r1, 0x3
	bl __modsi3
	str r0, [sp, 0xC]
	mov r0, r8
	ldr r2, [r0, 0x44]
	lsls r0, r2, 6
	mov r1, r8
	ldr r3, [r1, 0x40]
	adds r0, r3
	lsls r0, 1
	ldr r1, [r1, 0x20]
	adds r4, r1, r0
	movs r0, 0
	str r0, [sp, 0x10]
	mov r1, r8
	ldr r0, [r1, 0xC]
	subs r0, r2
	mov r10, r0
	ldr r0, [r1, 0x8]
	subs r0, r3
	str r0, [sp, 0x14]
	movs r2, 0
_080A4202:
	ldr r5, [sp, 0x14]
	mov r3, r10
	cmp r3, 0
	ble _080A4212
	movs r0, 0x1
	negs r0, r0
	add r10, r0
	b _080A4222
_080A4212:
	mov r1, r8
	ldr r1, [r1, 0xC]
	mov r10, r1
	mov r3, r8
	ldr r0, [r3, 0x40]
	lsls r0, 1
	ldr r1, [r3, 0x20]
	adds r4, r1, r0
_080A4222:
	adds r6, r4, 0
	mov r0, r8
	ldr r1, [r0, 0x28]
	ldrh r7, [r4]
	ldr r3, [r0, 0x1C]
	mov r9, r3
	adds r0, r4, 0x2
	mov r12, r0
	adds r4, 0x80
	str r4, [sp, 0x18]
	adds r2, 0x1
	str r2, [sp, 0x1C]
	mov r2, sp
	ldr r3, [sp, 0x10]
	lsls r0, r3, 1
	adds r0, r1
	movs r3, 0x2
_080A4244:
	stm r2!, {r0}
	adds r0, 0x40
	ldr r4, [sp, 0x10]
	adds r4, 0x20
	str r4, [sp, 0x10]
	subs r3, 0x1
	cmp r3, 0
	bge _080A4244
	ldr r0, [sp, 0xC]
	cmp r0, 0
	beq _080A42B2
	lsls r0, r7, 3
	adds r0, r7
	lsls r0, 1
	mov r1, r9
	adds r2, r1, r0
	mov r6, r12
	ldr r3, [sp, 0xC]
	cmp r3, 0x1
	bne _080A428C
	adds r2, 0x2
	mov r4, sp
	movs r3, 0x2
_080A4272:
	ldr r0, [r4]
	ldrh r1, [r2]
	strh r1, [r0]
	adds r0, 0x2
	ldrh r1, [r2, 0x2]
	strh r1, [r0]
	adds r0, 0x2
	stm r4!, {r0}
	adds r2, 0x6
	subs r3, 0x1
	cmp r3, 0
	bge _080A4272
	b _080A42A4
_080A428C:
	adds r2, 0x4
	mov r4, sp
	movs r3, 0x2
_080A4292:
	ldr r1, [r4]
	ldrh r0, [r2]
	strh r0, [r1]
	adds r1, 0x2
	stm r4!, {r1}
	adds r2, 0x6
	subs r3, 0x1
	cmp r3, 0
	bge _080A4292
_080A42A4:
	subs r5, 0x1
	cmp r5, 0
	bgt _080A42B2
	mov r4, r8
	ldr r5, [r4, 0x8]
	lsls r0, r5, 1
	subs r6, r0
_080A42B2:
	movs r3, 0
_080A42B4:
	ldrh r1, [r6]
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 1
	mov r1, r9
	adds r2, r1, r0
	adds r6, 0x2
	subs r5, 0x1
	adds r7, r3, 0x1
	mov r4, sp
	movs r3, 0x2
_080A42CA:
	ldr r1, [r4]
	ldrh r0, [r2]
	strh r0, [r1]
	adds r2, 0x2
	adds r1, 0x2
	ldrh r0, [r2]
	strh r0, [r1]
	adds r2, 0x2
	adds r1, 0x2
	ldrh r0, [r2]
	strh r0, [r1]
	adds r2, 0x2
	adds r1, 0x2
	stm r4!, {r1}
	subs r3, 0x1
	cmp r3, 0
	bge _080A42CA
	cmp r5, 0
	bgt _080A42F8
	mov r3, r8
	ldr r5, [r3, 0x8]
	lsls r0, r5, 1
	subs r6, r0
_080A42F8:
	adds r3, r7, 0
	cmp r3, 0x9
	ble _080A42B4
	ldr r4, [sp, 0xC]
	cmp r4, 0x1
	beq _080A433E
	ldrh r1, [r6]
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 1
	mov r1, r9
	adds r2, r1, r0
	cmp r4, 0
	bne _080A432C
	mov r4, sp
	movs r3, 0x2
_080A4318:
	ldm r4!, {r0}
	ldrh r1, [r2]
	strh r1, [r0]
	ldrh r1, [r2, 0x2]
	strh r1, [r0, 0x2]
	adds r2, 0x6
	subs r3, 0x1
	cmp r3, 0
	bge _080A4318
	b _080A433E
_080A432C:
	mov r4, sp
	movs r3, 0x2
_080A4330:
	ldm r4!, {r1}
	ldrh r0, [r2]
	strh r0, [r1]
	adds r2, 0x6
	subs r3, 0x1
	cmp r3, 0
	bge _080A4330
_080A433E:
	ldr r4, [sp, 0x18]
	ldr r2, [sp, 0x1C]
	cmp r2, 0x7
	bgt _080A4348
	b _080A4202
_080A4348:
	add sp, 0x20
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_80A41C4

	thumb_func_start sub_80A4358
sub_80A4358:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x3C
	adds r4, r0, 0
	ldr r0, [r4, 0x38]
	movs r1, 0x3
	bl __modsi3
	str r0, [sp, 0x18]
	ldr r0, [r4, 0x44]
	lsls r0, 6
	ldr r1, [r4, 0x40]
	adds r0, r1
	lsls r0, 1
	ldr r1, [r4, 0x20]
	adds r2, r1, r0
	ldr r1, [r4, 0x24]
	adds r1, r0
	movs r0, 0
	ldr r3, [r4, 0x28]
	str r3, [sp, 0x24]
	ldr r5, [r4, 0x2C]
	str r5, [sp, 0x28]
	ldr r4, [r4, 0x1C]
	str r4, [sp, 0x20]
	mov r3, sp
	adds r3, 0xC
	str r3, [sp, 0x1C]
	movs r4, 0
	str r4, [sp, 0x38]
_080A439A:
	mov r12, r2
	mov r8, r1
	mov r5, r12
	adds r5, 0x80
	str r5, [sp, 0x30]
	adds r1, 0x80
	str r1, [sp, 0x34]
	adds r0, 0x1
	str r0, [sp, 0x2C]
	add r3, sp, 0xC
	mov r2, sp
	ldr r4, [sp, 0x38]
	ldr r5, [sp, 0x28]
	adds r1, r4, r5
	ldr r5, [sp, 0x24]
	adds r0, r4, r5
	movs r5, 0x2
_080A43BC:
	stm r2!, {r0}
	stm r3!, {r1}
	adds r1, 0x40
	adds r0, 0x40
	ldr r4, [sp, 0x38]
	adds r4, 0x40
	str r4, [sp, 0x38]
	subs r5, 0x1
	cmp r5, 0
	bge _080A43BC
	ldr r5, [sp, 0x18]
	cmp r5, 0
	beq _080A445C
	mov r0, r12
	ldrh r1, [r0]
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 1
	ldr r1, [sp, 0x20]
	adds r4, r1, r0
	movs r3, 0x2
	add r12, r3
	mov r5, r8
	ldrh r1, [r5]
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 1
	ldr r1, [sp, 0x20]
	adds r3, r1, r0
	movs r5, 0x2
	add r8, r5
	ldr r0, [sp, 0x18]
	cmp r0, 0x1
	bne _080A4434
	adds r4, 0x2
	adds r3, 0x2
	ldr r7, [sp, 0x1C]
	mov r6, sp
_080A4408:
	ldr r1, [r6]
	ldr r2, [r7]
	ldrh r0, [r4]
	strh r0, [r1]
	adds r1, 0x2
	ldrh r0, [r4, 0x2]
	strh r0, [r1]
	adds r1, 0x2
	ldrh r0, [r3]
	strh r0, [r2]
	adds r2, 0x2
	ldrh r0, [r3, 0x2]
	strh r0, [r2]
	adds r2, 0x2
	stm r6!, {r1}
	stm r7!, {r2}
	adds r4, 0x6
	adds r3, 0x6
	subs r5, 0x1
	cmp r5, 0
	bge _080A4408
	b _080A445C
_080A4434:
	adds r4, 0x4
	adds r3, 0x4
	ldr r6, [sp, 0x1C]
	mov r2, sp
	movs r5, 0x2
_080A443E:
	ldr r1, [r2]
	ldrh r0, [r4]
	strh r0, [r1]
	adds r1, 0x2
	stm r2!, {r1}
	ldr r1, [r6]
	ldrh r0, [r3]
	strh r0, [r1]
	adds r1, 0x2
	stm r6!, {r1}
	adds r4, 0x6
	adds r3, 0x6
	subs r5, 0x1
	cmp r5, 0
	bge _080A443E
_080A445C:
	movs r2, 0
	ldr r1, [sp, 0x20]
	mov r9, r1
_080A4462:
	mov r3, r12
	ldrh r1, [r3]
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 1
	mov r5, r9
	adds r4, r5, r0
	movs r0, 0x2
	add r12, r0
	mov r3, r8
	ldrh r1, [r3]
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 1
	adds r3, r5, r0
	movs r5, 0x2
	add r8, r5
	movs r5, 0
	adds r2, 0x1
	mov r10, r2
	mov r7, sp
	add r6, sp, 0xC
_080A448E:
	ldr r1, [r7]
	ldr r2, [r6]
	ldrh r0, [r4]
	strh r0, [r1]
	adds r4, 0x2
	adds r1, 0x2
	ldrh r0, [r4]
	strh r0, [r1]
	adds r4, 0x2
	adds r1, 0x2
	ldrh r0, [r4]
	strh r0, [r1]
	adds r4, 0x2
	adds r1, 0x2
	ldrh r0, [r3]
	strh r0, [r2]
	adds r3, 0x2
	adds r2, 0x2
	ldrh r0, [r3]
	strh r0, [r2]
	adds r3, 0x2
	adds r2, 0x2
	ldrh r0, [r3]
	strh r0, [r2]
	adds r3, 0x2
	adds r2, 0x2
	stm r7!, {r1}
	stm r6!, {r2}
	adds r5, 0x1
	cmp r5, 0x2
	ble _080A448E
	mov r2, r10
	cmp r2, 0x9
	ble _080A4462
	ldr r0, [sp, 0x18]
	cmp r0, 0x1
	beq _080A453A
	mov r3, r12
	ldrh r1, [r3]
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 1
	ldr r5, [sp, 0x20]
	adds r4, r5, r0
	mov r0, r8
	ldrh r1, [r0]
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 1
	adds r3, r5, r0
	ldr r1, [sp, 0x18]
	cmp r1, 0
	bne _080A451E
	ldr r7, [sp, 0x1C]
	mov r6, sp
	movs r5, 0x2
_080A44FE:
	ldm r6!, {r1}
	ldm r7!, {r2}
	ldrh r0, [r4]
	strh r0, [r1]
	ldrh r0, [r4, 0x2]
	strh r0, [r1, 0x2]
	ldrh r0, [r3]
	strh r0, [r2]
	ldrh r0, [r3, 0x2]
	strh r0, [r2, 0x2]
	adds r4, 0x6
	adds r3, 0x6
	subs r5, 0x1
	cmp r5, 0
	bge _080A44FE
	b _080A453A
_080A451E:
	ldr r6, [sp, 0x1C]
	mov r2, sp
	movs r5, 0x2
_080A4524:
	ldm r2!, {r1}
	ldrh r0, [r4]
	strh r0, [r1]
	ldm r6!, {r1}
	ldrh r0, [r3]
	strh r0, [r1]
	adds r4, 0x6
	adds r3, 0x6
	subs r5, 0x1
	cmp r5, 0
	bge _080A4524
_080A453A:
	ldr r2, [sp, 0x30]
	ldr r1, [sp, 0x34]
	ldr r0, [sp, 0x2C]
	cmp r0, 0x7
	bgt _080A4546
	b _080A439A
_080A4546:
	add sp, 0x3C
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_80A4358

	thumb_func_start sub_80A4558
sub_80A4558:
	lsls r1, 3
	movs r3, 0x8F
	lsls r3, 3
	adds r0, r3
	adds r0, r1
	ldr r1, [r0, 0x4]
	ldr r0, [r0]
	str r0, [r2]
	str r1, [r2, 0x4]
	bx lr
	thumb_func_end sub_80A4558

	thumb_func_start sub_80A456C
sub_80A456C:
	lsls r1, 3
	movs r3, 0x8F
	lsls r3, 3
	adds r0, r3
	adds r0, r1
	ldr r1, [r2]
	ldr r2, [r2, 0x4]
	str r1, [r0]
	str r2, [r0, 0x4]
	bx lr
	thumb_func_end sub_80A456C

	thumb_func_start sub_80A4580
sub_80A4580:
	push {r4,lr}
	adds r3, r2, 0
	lsls r2, r1, 2
	adds r2, r1
	lsls r2, 4
	movs r1, 0x91
	lsls r1, 3
	adds r2, r1
	adds r2, r0, r2
	ldr r0, [r3]
	cmp r0, 0
	bge _080A45AE
	ldrb r0, [r2, 0x6]
	ldr r4, [r3, 0x4]
	cmp r0, 0
	beq _080A45CA
	ldr r1, [r2, 0x10]
_080A45A2:
	ldr r0, [r3]
	adds r0, r1
	str r0, [r3]
	cmp r0, 0
	blt _080A45A2
	b _080A45CC
_080A45AE:
	ldr r1, [r2, 0x10]
	ldr r4, [r3, 0x4]
	cmp r0, r1
	blt _080A45CC
	ldrb r0, [r2, 0x6]
	cmp r0, 0
	beq _080A45C8
_080A45BC:
	ldr r0, [r3]
	subs r0, r1
	str r0, [r3]
	cmp r0, r1
	bge _080A45BC
	b _080A45CC
_080A45C8:
	subs r0, r1, 0x1
_080A45CA:
	str r0, [r3]
_080A45CC:
	cmp r4, 0
	bge _080A45E4
	ldrb r0, [r2, 0x6]
	cmp r0, 0
	beq _080A45FE
	ldr r1, [r2, 0x14]
_080A45D8:
	ldr r0, [r3, 0x4]
	adds r0, r1
	str r0, [r3, 0x4]
	cmp r0, 0
	blt _080A45D8
	b _080A4600
_080A45E4:
	ldr r1, [r2, 0x14]
	cmp r4, r1
	blt _080A4600
	ldrb r0, [r2, 0x6]
	cmp r0, 0
	beq _080A45FC
_080A45F0:
	ldr r0, [r3, 0x4]
	subs r0, r1
	str r0, [r3, 0x4]
	cmp r0, r1
	bge _080A45F0
	b _080A4600
_080A45FC:
	subs r0, r1, 0x1
_080A45FE:
	str r0, [r3, 0x4]
_080A4600:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_80A4580

	thumb_func_start sub_80A4608
sub_80A4608:
	movs r3, 0x89
	lsls r3, 3
	adds r2, r0, r3
	ldrb r2, [r2]
	str r2, [r1]
	ldr r2, _080A461C
	adds r0, r2
	ldrb r0, [r0]
	str r0, [r1, 0x4]
	bx lr
	.align 2, 0
_080A461C: .4byte 0x00000449
	thumb_func_end sub_80A4608

	thumb_func_start sub_80A4620
sub_80A4620:
	movs r3, 0x89
	lsls r3, 3
	adds r2, r0, r3
	ldrb r2, [r2]
	lsls r2, 3
	str r2, [r1]
	ldr r2, _080A4638
	adds r0, r2
	ldrb r0, [r0]
	lsls r0, 3
	str r0, [r1, 0x4]
	bx lr
	.align 2, 0
_080A4638: .4byte 0x00000449
	thumb_func_end sub_80A4620

	thumb_func_start GetDungeonBounds
GetDungeonBounds:
	movs r3, 0
	str r3, [r1]
	str r3, [r1, 0x4]
	movs r3, 0x89
	lsls r3, 3
	adds r1, r0, r3
	ldrb r1, [r1]
	lsls r1, 11
	str r1, [r2]
	ldr r1, _080A465C
	adds r0, r1
	ldrb r0, [r0]
	lsls r0, 11
	str r0, [r2, 0x4]
	bx lr
	.align 2, 0
_080A465C: .4byte 0x00000449
	thumb_func_end GetDungeonBounds

	thumb_func_start sub_80A4660
sub_80A4660:
	push {r4-r7,lr}
	adds r6, r3, 0
	lsls r1, 24
	lsrs r5, r1, 24
	ldr r1, _080A4678
	adds r0, r1
	ldr r4, [r0]
	cmp r4, 0
	bne _080A467C
	movs r0, 0
	b _080A46B6
	.align 2, 0
_080A4678: .4byte 0x00000544
_080A467C:
	ldr r0, [r2, 0x4]
	lsls r0, 8
	ldr r1, [r2]
	adds r0, r1
	ldr r1, _080A46BC
	adds r0, r1
	adds r4, r0
	ldr r3, [r6, 0x4]
	cmp r3, 0
	ble _080A46B4
	movs r7, 0x80
	lsls r7, 1
_080A4694:
	ldr r1, [r6]
	adds r2, r4, 0
	cmp r1, 0
	ble _080A46AC
_080A469C:
	ldrb r0, [r2]
	ands r0, r5
	adds r2, 0x1
	cmp r0, 0
	bne _080A46B6
	subs r1, 0x1
	cmp r1, 0
	bgt _080A469C
_080A46AC:
	adds r4, r7
	subs r3, 0x1
	cmp r3, 0
	bgt _080A4694
_080A46B4:
	movs r0, 0
_080A46B6:
	pop {r4-r7}
	pop {r1}
	bx r1
	.align 2, 0
_080A46BC: .4byte 0x00000405
	thumb_func_end sub_80A4660

	thumb_func_start sub_80A46C0
sub_80A46C0:
	push {r4-r7,lr}
	adds r6, r3, 0
	lsls r1, 24
	lsrs r5, r1, 24
	ldr r1, _080A46D8
	adds r0, r1
	ldr r4, [r0]
	cmp r4, 0
	bne _080A46DC
_080A46D2:
	movs r0, 0
	b _080A4716
	.align 2, 0
_080A46D8: .4byte 0x00000544
_080A46DC:
	ldr r0, [r2, 0x4]
	lsls r0, 8
	ldr r1, [r2]
	adds r0, r1
	ldr r1, _080A471C
	adds r0, r1
	adds r4, r0
	ldr r3, [r6, 0x4]
	cmp r3, 0
	ble _080A4714
	movs r7, 0x80
	lsls r7, 1
_080A46F4:
	ldr r1, [r6]
	adds r2, r4, 0
	cmp r1, 0
	ble _080A470C
_080A46FC:
	ldrb r0, [r2]
	ands r0, r5
	adds r2, 0x1
	cmp r0, r5
	bne _080A46D2
	subs r1, 0x1
	cmp r1, 0
	bgt _080A46FC
_080A470C:
	adds r4, r7
	subs r3, 0x1
	cmp r3, 0
	bgt _080A46F4
_080A4714:
	movs r0, 0x1
_080A4716:
	pop {r4-r7}
	pop {r1}
	bx r1
	.align 2, 0
_080A471C: .4byte 0x00000405
	thumb_func_end sub_80A46C0

	thumb_func_start sub_80A4720
sub_80A4720:
	lsls r1, 2
	ldr r3, _080A473C
	adds r0, r3
	adds r0, r1
	ldr r1, [r2, 0x4]
	lsls r1, 7
	ldr r3, [r0]
	adds r3, r1
	ldr r0, [r2]
	lsls r0, 1
	adds r3, r0
	ldrh r0, [r3]
	bx lr
	.align 2, 0
_080A473C: .4byte 0x0000054c
	thumb_func_end sub_80A4720

	thumb_func_start sub_80A4740
sub_80A4740:
	push {r4,lr}
	lsls r1, 2
	ldr r4, _080A4760
	adds r0, r4
	adds r0, r1
	ldr r1, [r2, 0x4]
	lsls r1, 7
	ldr r4, [r0]
	adds r4, r1
	ldr r0, [r2]
	lsls r0, 1
	adds r4, r0
	strh r3, [r4]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080A4760: .4byte 0x0000054c
	thumb_func_end sub_80A4740

	thumb_func_start sub_80A4764
sub_80A4764:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x8
	mov r9, r0
	ldr r0, _080A47E8
	add r0, r9
	movs r2, 0
	ldrsh r1, [r0, r2]
	movs r0, 0x1
	negs r0, r0
	cmp r1, r0
	bne _080A4784
	b _080A49CE
_080A4784:
	ldr r0, _080A47EC
	add r0, r9
	movs r6, 0
	ldrsh r0, [r0, r6]
	cmp r0, 0
	beq _080A4864
	mov r4, r9
	ldr r0, _080A47F0
	add r0, r9
	ldr r5, [r0]
	ldr r0, _080A47F4
	add r0, r9
	movs r1, 0
	ldrsh r0, [r0, r1]
	lsls r0, 20
	lsrs r6, r0, 16
	movs r7, 0
	ldr r0, _080A47F8
	add r0, r9
	movs r2, 0
	ldrsh r0, [r0, r2]
	cmp r7, r0
	bge _080A484C
_080A47B2:
	ldr r1, [r4, 0x4]
	cmp r1, 0
	beq _080A4832
	ldrh r0, [r4, 0x2]
	subs r0, 0x1
	strh r0, [r4, 0x2]
	lsls r0, 16
	cmp r0, 0
	bgt _080A4832
	ldrh r0, [r4]
	subs r0, 0x1
	strh r0, [r4]
	lsls r0, 16
	cmp r0, 0
	bgt _080A4808
	ldr r0, _080A47FC
	add r0, r9
	ldrb r0, [r0]
	cmp r0, 0
	beq _080A4800
	ldrh r0, [r5]
	strh r0, [r4, 0x2]
	ldrh r0, [r5, 0x2]
	strh r0, [r4]
	str r1, [r4, 0x8]
	b _080A480C
	.align 2, 0
_080A47E8: .4byte 0x00000444
_080A47EC: .4byte 0x00000466
_080A47F0: .4byte 0x0000046c
_080A47F4: .4byte 0x0000052c
_080A47F8: .4byte 0x00000464
_080A47FC: .4byte 0x00000471
_080A4800:
	strh r0, [r4]
	strh r0, [r4, 0x2]
	str r0, [r4, 0x8]
	b _080A480C
_080A4808:
	ldrh r0, [r5]
	strh r0, [r4, 0x2]
_080A480C:
	ldr r0, [r4, 0x8]
	cmp r0, 0
	beq _080A4832
	movs r0, 0
	str r0, [sp]
	adds r0, r6, 0
	movs r1, 0
	bl sub_8003810
	adds r0, r6, 0x1
	lsls r0, 16
	lsrs r0, 16
	ldr r1, [r4, 0x8]
	movs r2, 0xF
	bl sub_809971C
	ldr r0, [r4, 0x8]
	adds r0, 0x3C
	str r0, [r4, 0x8]
_080A4832:
	adds r7, 0x1
	adds r4, 0x10
	adds r5, 0x4
	adds r0, r6, 0
	adds r0, 0x10
	lsls r0, 16
	lsrs r6, r0, 16
	ldr r0, _080A485C
	add r0, r9
	movs r1, 0
	ldrsh r0, [r0, r1]
	cmp r7, r0
	blt _080A47B2
_080A484C:
	movs r0, 0x8E
	lsls r0, 3
	add r0, r9
	ldrb r1, [r0]
	ldr r0, _080A4860
	add r0, r9
	strb r1, [r0]
	b _080A48E6
	.align 2, 0
_080A485C: .4byte 0x00000464
_080A4860: .4byte 0x00000471
_080A4864:
	movs r0, 0x88
	lsls r0, 3
	add r0, r9
	ldr r0, [r0]
	cmp r0, 0
	beq _080A48E6
	mov r4, r9
	adds r4, 0xE0
	movs r6, 0xA0
	movs r5, 0x1F
_080A4878:
	adds r0, r4, 0
	movs r1, 0x1
	bl sub_8004D14
	lsls r0, 24
	cmp r0, 0
	beq _080A48DC
	adds r0, r4, 0
	movs r1, 0x1
	bl sub_8004D40
	lsls r0, 24
	cmp r0, 0
	bne _080A48DC
	ldrh r0, [r4, 0x6]
	subs r0, 0x1
	strh r0, [r4, 0x6]
	lsls r0, 16
	cmp r0, 0
	bgt _080A48DC
	ldrh r0, [r4, 0x4]
	strh r0, [r4, 0x6]
	ldr r1, [r4, 0xC]
	ldr r0, [r4, 0x10]
	cmp r1, r0
	bcc _080A48B0
	ldr r0, [r4, 0x8]
	str r0, [r4, 0xC]
_080A48B0:
	ldr r1, [r4, 0xC]
	ldm r1!, {r0}
	str r0, [r4, 0x14]
	str r1, [r4, 0xC]
	ldrb r1, [r4, 0x14]
	add r0, sp, 0x4
	strb r1, [r0]
	ldrb r1, [r4, 0x15]
	adds r0, 0x1
	strb r1, [r0]
	ldrb r1, [r4, 0x16]
	adds r0, 0x1
	strb r1, [r0]
	ldrb r1, [r4, 0x17]
	adds r0, 0x1
	strb r1, [r0]
	ldr r1, [sp, 0x4]
	str r1, [sp]
	lsls r0, r6, 16
	lsrs r0, 16
	bl sub_8003810
_080A48DC:
	subs r5, 0x1
	adds r4, 0x18
	adds r6, 0x1
	cmp r5, 0
	bge _080A4878
_080A48E6:
	movs r5, 0
	movs r4, 0x1
_080A48EA:
	movs r2, 0xF8
	lsls r2, 2
	adds r0, r5, r2
	mov r6, r9
	adds r2, r6, r0
	ldrb r0, [r2]
	cmp r0, 0
	beq _080A4942
	ldrh r1, [r2, 0x4]
	subs r0, r1, 0x1
	strh r0, [r2, 0x4]
	lsls r1, 16
	cmp r1, 0
	bgt _080A4942
	ldr r0, [r2, 0x14]
	adds r0, 0x4
	str r0, [r2, 0x14]
	ldr r1, [r2, 0x24]
	lsrs r1, 1
	lsls r1, 1
	ldr r0, [r2, 0x1C]
	adds r0, r1
	str r0, [r2, 0x1C]
	ldrh r0, [r2, 0x2]
	adds r0, 0x1
	movs r3, 0
	strh r0, [r2, 0x2]
	ldr r1, [r2, 0xC]
	lsls r0, 16
	asrs r0, 16
	movs r6, 0x2
	ldrsh r1, [r1, r6]
	cmp r0, r1
	blt _080A4938
	ldr r0, [r2, 0x10]
	str r0, [r2, 0x14]
	ldr r0, [r2, 0x18]
	str r0, [r2, 0x1C]
	strh r3, [r2, 0x2]
_080A4938:
	movs r0, 0x1
	strb r0, [r2, 0x1]
	ldr r0, [r2, 0x14]
	ldr r0, [r0]
	strh r0, [r2, 0x4]
_080A4942:
	adds r5, 0x28
	subs r4, 0x1
	cmp r4, 0
	bge _080A48EA
	movs r4, 0x91
	lsls r4, 3
	add r4, r9
	movs r7, 0x8F
	lsls r7, 3
	add r7, r9
	movs r0, 0
	mov r8, r0
	b _080A49BC
_080A495C:
	adds r0, r4, 0
	adds r1, r7, 0
	bl sub_80A3E14
	adds r0, r4, 0
	bl sub_80A3EB0
	movs r6, 0
	movs r2, 0x2
	ldrsh r1, [r4, r2]
	ldr r0, _080A4998
	add r0, r9
	movs r2, 0
	ldrsh r0, [r0, r2]
	adds r5, r1, r0
	movs r1, 0x4
	ldrsh r0, [r4, r1]
	movs r2, 0x1
	add r8, r2
	movs r1, 0x50
	adds r1, r4
	mov r10, r1
	adds r7, 0x8
	cmp r6, r0
	bge _080A49BA
_080A498E:
	cmp r5, 0
	beq _080A499C
	cmp r5, 0x1
	beq _080A49A6
	b _080A49AE
	.align 2, 0
_080A4998: .4byte 0x00000536
_080A499C:
	ldr r0, [r4, 0x48]
	ldr r1, [r4, 0x4C]
	bl SetBG2RegOffsets
	b _080A49AE
_080A49A6:
	ldr r0, [r4, 0x48]
	ldr r1, [r4, 0x4C]
	bl SetBG3RegOffsets
_080A49AE:
	adds r6, 0x1
	adds r5, 0x1
	movs r2, 0x4
	ldrsh r0, [r4, r2]
	cmp r6, r0
	blt _080A498E
_080A49BA:
	mov r4, r10
_080A49BC:
	ldr r0, _080A49E0
	add r0, r9
	ldr r0, [r0]
	cmp r8, r0
	blt _080A495C
	ldr r1, _080A49E4
	add r1, r9
	movs r0, 0x1
	strb r0, [r1]
_080A49CE:
	add sp, 0x8
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_080A49E0: .4byte 0x00000474
_080A49E4: .4byte 0x0000052a
	thumb_func_end sub_80A4764

	thumb_func_start sub_80A49E8
sub_80A49E8:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	adds r6, r0, 0
	ldr r0, _080A4A74
	adds r5, r6, r0
	movs r1, 0xFF
	lsls r1, 2
	adds r4, r6, r1
	ldr r0, _080A4A78
	adds r0, r6
	mov r8, r0
	movs r7, 0x1
_080A4A02:
	ldrb r0, [r5]
	cmp r0, 0
	beq _080A4A1C
	ldr r0, [r4, 0x4]
	ldr r1, [r4]
	ldr r2, [r4, 0x8]
	bl MemoryCopy32
	movs r0, 0
	strb r0, [r5]
	movs r0, 0x1
	mov r1, r8
	strb r0, [r1]
_080A4A1C:
	adds r5, 0x28
	adds r4, 0x28
	subs r7, 0x1
	cmp r7, 0
	bge _080A4A02
	ldr r1, _080A4A78
	adds r0, r6, r1
	ldrb r0, [r0]
	cmp r0, 0
	beq _080A4A68
	movs r5, 0
	adds r1, 0xC
	adds r0, r6, r1
	movs r1, 0
	ldrsh r4, [r0, r1]
	movs r1, 0xA7
	lsls r1, 3
	adds r0, r6, r1
	movs r1, 0
	ldrsh r0, [r0, r1]
	cmp r5, r0
	bge _080A4A60
	movs r0, 0xA7
	lsls r0, 3
	adds r7, r6, r0
_080A4A4E:
	adds r0, r4, 0x2
	bl sub_80098F8
	adds r5, 0x1
	adds r4, 0x1
	movs r1, 0
	ldrsh r0, [r7, r1]
	cmp r5, r0
	blt _080A4A4E
_080A4A60:
	ldr r0, _080A4A78
	adds r1, r6, r0
	movs r0, 0
	strb r0, [r1]
_080A4A68:
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_080A4A74: .4byte 0x000003e1
_080A4A78: .4byte 0x0000052a
	thumb_func_end sub_80A49E8

        .align 2,0
