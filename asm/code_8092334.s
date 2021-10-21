	.include "constants/gba_constants.inc"
	.include "asm/macros.inc"

	.syntax unified

	.text

	thumb_func_start LoadWazaParameters
LoadWazaParameters:
	push {lr}
	ldr r0, _08092868
	ldr r1, _0809286C
	bl OpenFileAndGetFileDataPtr
	ldr r1, _08092870
	str r0, [r1]
	ldr r1, _08092874
	ldr r2, [r0, 0x4]
	ldr r0, [r2]
	str r0, [r1]
	ldr r1, _08092878
	ldr r0, [r2, 0x4]
	str r0, [r1]
	pop {r0}
	bx r0
	.align 2, 0
_08092868: .4byte gUnknown_81098D0
_0809286C: .4byte gSystemFileArchive
_08092870: .4byte gWazaParametersFile
_08092874: .4byte gMovesData
_08092878: .4byte gMovesRelated_2038C6C
	thumb_func_end LoadWazaParameters

	thumb_func_start sub_809287C
sub_809287C:
	push {lr}
	adds r2, r0, 0
	ldrb r1, [r2]
	movs r0, 0x20
	ands r0, r1
	cmp r0, 0
	bne _08092894
	ldrb r1, [r2, 0x1]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _08092898
_08092894:
	movs r0, 0x32
	b _0809289A
_08092898:
	movs r0, 0x34
_0809289A:
	pop {r1}
	bx r1
	thumb_func_end sub_809287C

	thumb_func_start sub_80928A0
sub_80928A0:
	push {r4,r5,lr}
	sub sp, 0x8
	adds r4, r0, 0
	adds r5, r2, 0
	mov r0, sp
	bl sub_8093F10
	adds r0, r4, 0
	mov r1, sp
	adds r2, r5, 0
	bl sub_80928C0
	add sp, 0x8
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_80928A0

	thumb_func_start sub_80928C0
sub_80928C0:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0x20
	adds r7, r0, 0
	adds r4, r1, 0
	adds r5, r2, 0
	adds r0, r4, 0
	bl sub_809287C
	lsls r0, 24
	lsrs r6, r0, 24
	cmp r5, 0
	bne _080928DE
	ldr r5, _080928F0
_080928DE:
	ldrb r1, [r4, 0x5]
	cmp r1, 0
	beq _080928F8
	ldr r1, _080928F4
	ldrb r2, [r4, 0x5]
	add r0, sp, 0x14
	bl ExpandPlaceholdersBuffer
	b _080928FC
	.align 2, 0
_080928F0: .4byte gUnknown_81098C4
_080928F4: .4byte gUnknown_81098DC
_080928F8:
	add r0, sp, 0x14
	strb r1, [r0]
_080928FC:
	ldrb r0, [r5, 0x8]
	cmp r0, 0
	beq _08092904
	movs r6, 0x2
_08092904:
	ldrb r0, [r5, 0x9]
	cmp r0, 0
	beq _08092918
	ldrh r0, [r4, 0x2]
	bl sub_809422C
	lsls r0, 24
	cmp r0, 0
	beq _08092918
	movs r6, 0x2
_08092918:
	ldr r0, [r5]
	cmp r0, 0x4
	bls _08092920
	b _08092A6A
_08092920:
	lsls r0, 2
	ldr r1, _0809292C
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0809292C: .4byte _08092930
	.align 2, 0
_08092930:
	.4byte _08092944
	.4byte _0809296C
	.4byte _08092998
	.4byte _080929C4
	.4byte _08092A20
_08092944:
	ldr r1, _08092964
	ldrh r2, [r4, 0x2]
	ldr r0, _08092968
	ldr r3, [r0]
	lsls r0, r2, 3
	adds r0, r2
	lsls r0, 2
	adds r0, r3
	ldr r3, [r0]
	add r0, sp, 0x14
	str r0, [sp]
	adds r0, r7, 0
	adds r2, r6, 0
	bl ExpandPlaceholdersBuffer
	b _08092A6A
	.align 2, 0
_08092964: .4byte gUnknown_81098E0
_08092968: .4byte gMovesData
_0809296C:
	adds r0, r4, 0
	bl sub_8092BF4
	adds r3, r0, 0
	ldr r1, _0809298C
	mov r8, r1
	ldrb r1, [r4]
	movs r0, 0x8
	ands r0, r1
	ldr r1, _08092990
	mov r12, r1
	cmp r0, 0
	beq _080929E2
	ldr r0, _08092994
	b _080929E0
	.align 2, 0
_0809298C: .4byte gUnknown_81098EC
_08092990: .4byte gUnknown_810990C
_08092994: .4byte gUnknown_8109908
_08092998:
	adds r0, r4, 0
	bl sub_8092BF4
	adds r3, r0, 0
	ldr r0, _080929B8
	mov r8, r0
	ldrb r1, [r4]
	movs r0, 0x8
	ands r0, r1
	ldr r1, _080929BC
	mov r12, r1
	cmp r0, 0
	beq _080929E2
	ldr r0, _080929C0
	b _080929E0
	.align 2, 0
_080929B8: .4byte gUnknown_8109910
_080929BC: .4byte gUnknown_810990C
_080929C0: .4byte gUnknown_8109908
_080929C4:
	adds r0, r4, 0
	bl sub_8092BF4
	adds r3, r0, 0
	ldr r0, _08092A10
	mov r8, r0
	ldrb r1, [r4]
	movs r0, 0x4
	ands r0, r1
	ldr r1, _08092A14
	mov r12, r1
	cmp r0, 0
	beq _080929E2
	ldr r0, _08092A18
_080929E0:
	mov r12, r0
_080929E2:
	ldrh r1, [r4, 0x2]
	ldr r0, _08092A1C
	ldr r2, [r0]
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldr r0, [r0]
	str r0, [sp]
	add r1, sp, 0x14
	str r1, [sp, 0x4]
	ldr r0, [r5, 0x4]
	str r0, [sp, 0x8]
	ldrb r0, [r4, 0x4]
	str r0, [sp, 0xC]
	str r3, [sp, 0x10]
	adds r0, r7, 0
	mov r1, r8
	adds r2, r6, 0
	mov r3, r12
	bl ExpandPlaceholdersBuffer
	b _08092A6A
	.align 2, 0
_08092A10: .4byte gUnknown_81098EC
_08092A14: .4byte gUnknown_810990C
_08092A18: .4byte gUnknown_8109928
_08092A1C: .4byte gMovesData
_08092A20:
	adds r0, r4, 0
	bl sub_8092BF4
	adds r3, r0, 0
	ldr r0, _08092A78
	mov r8, r0
	ldrb r1, [r4]
	movs r0, 0x4
	ands r0, r1
	ldr r1, _08092A7C
	mov r12, r1
	cmp r0, 0
	beq _08092A3E
	ldr r0, _08092A80
	mov r12, r0
_08092A3E:
	ldrh r1, [r4, 0x2]
	ldr r0, _08092A84
	ldr r2, [r0]
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldr r0, [r0]
	str r0, [sp]
	add r1, sp, 0x14
	str r1, [sp, 0x4]
	ldr r0, [r5, 0x4]
	str r0, [sp, 0x8]
	ldrb r0, [r4, 0x4]
	str r0, [sp, 0xC]
	str r3, [sp, 0x10]
	adds r0, r7, 0
	mov r1, r8
	adds r2, r6, 0
	mov r3, r12
	bl ExpandPlaceholdersBuffer
_08092A6A:
	add sp, 0x20
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_08092A78: .4byte gUnknown_8109910
_08092A7C: .4byte gUnknown_810990C
_08092A80: .4byte gUnknown_8109928
_08092A84: .4byte gMovesData
	thumb_func_end sub_80928C0

	thumb_func_start sub_8092A88
sub_8092A88:
	push {r4,r5,lr}
	adds r4, r0, 0
	movs r2, 0
	movs r0, 0x5
	strb r0, [r4]
	strb r2, [r4, 0x1]
	movs r5, 0
	strh r1, [r4, 0x2]
	adds r0, r4, 0
	bl sub_8092BF4
	strb r0, [r4, 0x4]
	strb r5, [r4, 0x5]
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_8092A88

	thumb_func_start sub_8092AA8
sub_8092AA8:
	push {r4,r5,lr}
	adds r5, r0, 0
	lsls r1, 16
	lsrs r2, r1, 16
	cmp r2, 0
	bne _08092AB8
	strb r2, [r5]
	b _08092ACE
_08092AB8:
	movs r1, 0
	movs r0, 0x5
	strb r0, [r5]
	strb r1, [r5, 0x1]
	movs r4, 0
	strh r2, [r5, 0x2]
	adds r0, r5, 0
	bl sub_8092BF4
	strb r0, [r5, 0x4]
	strb r4, [r5, 0x5]
_08092ACE:
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_8092AA8

	thumb_func_start sub_8092AD4
sub_8092AD4:
	movs r2, 0x5
	strb r2, [r0]
	movs r2, 0
	strh r1, [r0, 0x2]
	strb r2, [r0, 0x4]
	bx lr
	thumb_func_end sub_8092AD4

	thumb_func_start sub_8092AE0
sub_8092AE0:
	ldrh r2, [r0, 0x2]
	ldr r0, _08092AFC
	ldr r3, [r0]
	lsls r0, r2, 3
	adds r0, r2
	lsls r0, 2
	adds r0, r3
	lsls r1, 1
	adds r0, 0x8
	adds r0, r1
	movs r1, 0
	ldrsh r0, [r0, r1]
	bx lr
	.align 2, 0
_08092AFC: .4byte gMovesData
	thumb_func_end sub_8092AE0

	thumb_func_start sub_8092B00
sub_8092B00:
	ldrh r1, [r0, 0x2]
	ldr r0, _08092B14
	ldr r2, [r0]
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldrb r0, [r0, 0x6]
	bx lr
	.align 2, 0
_08092B14: .4byte gMovesData
	thumb_func_end sub_8092B00

	thumb_func_start sub_8092B18
sub_8092B18:
	push {lr}
	lsls r0, 16
	asrs r1, r0, 16
	adds r2, r1, 0
	ldr r0, _08092B40
	cmp r1, r0
	beq _08092B48
	cmp r1, 0
	beq _08092B48
	movs r0, 0xD2
	lsls r0, 1
	cmp r2, r0
	beq _08092B48
	ldr r0, _08092B44
	ldr r1, [r0]
	lsls r0, r2, 3
	adds r0, r1
	ldr r0, [r0]
	b _08092B4A
	.align 2, 0
_08092B40: .4byte 0x000001a5
_08092B44: .4byte gMovesRelated_2038C6C
_08092B48:
	ldr r0, _08092B50
_08092B4A:
	pop {r1}
	bx r1
	.align 2, 0
_08092B50: .4byte gUnknown_810992B
	thumb_func_end sub_8092B18

	thumb_func_start sub_8092B54
sub_8092B54:
	push {lr}
	lsls r0, 16
	asrs r1, r0, 16
	adds r2, r1, 0
	ldr r0, _08092B7C
	cmp r1, r0
	beq _08092B84
	cmp r1, 0
	beq _08092B84
	movs r0, 0xD2
	lsls r0, 1
	cmp r2, r0
	beq _08092B84
	ldr r0, _08092B80
	ldr r1, [r0]
	lsls r0, r2, 3
	adds r0, r1
	ldr r0, [r0, 0x4]
	b _08092B86
	.align 2, 0
_08092B7C: .4byte 0x000001a5
_08092B80: .4byte gMovesRelated_2038C6C
_08092B84:
	ldr r0, _08092B8C
_08092B86:
	pop {r1}
	bx r1
	.align 2, 0
_08092B8C: .4byte gUnknown_810992B
	thumb_func_end sub_8092B54

	thumb_func_start sub_8092B90
sub_8092B90:
	ldrh r1, [r0, 0x2]
	ldr r0, _08092BA4
	ldr r2, [r0]
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldrb r0, [r0, 0xD]
	bx lr
	.align 2, 0
_08092BA4: .4byte gMovesData
	thumb_func_end sub_8092B90

	thumb_func_start sub_8092BA8
sub_8092BA8:
	ldrh r1, [r0, 0x2]
	ldr r0, _08092BBC
	ldr r2, [r0]
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldrb r0, [r0, 0x11]
	bx lr
	.align 2, 0
_08092BBC: .4byte gMovesData
	thumb_func_end sub_8092BA8

	thumb_func_start sub_8092BC0
sub_8092BC0:
	ldrh r1, [r0, 0x2]
	ldr r0, _08092BD4
	ldr r2, [r0]
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	movs r1, 0x4
	ldrsh r0, [r0, r1]
	bx lr
	.align 2, 0
_08092BD4: .4byte gMovesData
	thumb_func_end sub_8092BC0

	thumb_func_start sub_8092BD8
sub_8092BD8:
	ldrh r2, [r0, 0x2]
	ldr r0, _08092BF0
	ldr r3, [r0]
	lsls r0, r2, 3
	adds r0, r2
	lsls r0, 2
	adds r0, r3
	adds r0, 0xE
	adds r0, r1
	ldrb r0, [r0]
	bx lr
	.align 2, 0
_08092BF0: .4byte gMovesData
	thumb_func_end sub_8092BD8

	thumb_func_start sub_8092BF4
sub_8092BF4:
	ldrh r1, [r0, 0x2]
	ldr r0, _08092C08
	ldr r2, [r0]
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldrb r0, [r0, 0xC]
	bx lr
	.align 2, 0
_08092C08: .4byte gMovesData
	thumb_func_end sub_8092BF4

	thumb_func_start sub_8092C0C
sub_8092C0C:
	ldrh r1, [r0, 0x2]
	ldr r0, _08092C20
	ldr r2, [r0]
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldrb r0, [r0, 0x12]
	bx lr
	.align 2, 0
_08092C20: .4byte gMovesData
	thumb_func_end sub_8092C0C

	thumb_func_start sub_8092C24
sub_8092C24:
	ldrh r1, [r0, 0x2]
	ldr r0, _08092C38
	ldr r2, [r0]
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldrb r0, [r0, 0x13]
	bx lr
	.align 2, 0
_08092C38: .4byte gMovesData
	thumb_func_end sub_8092C24

	thumb_func_start sub_8092C3C
sub_8092C3C:
	ldrh r1, [r0, 0x2]
	ldr r0, _08092C50
	ldr r2, [r0]
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldrb r0, [r0, 0x17]
	bx lr
	.align 2, 0
_08092C50: .4byte gMovesData
	thumb_func_end sub_8092C3C

	thumb_func_start sub_8092C54
sub_8092C54:
	ldrh r1, [r0, 0x2]
	ldr r0, _08092C68
	ldr r2, [r0]
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldrb r0, [r0, 0x18]
	bx lr
	.align 2, 0
_08092C68: .4byte gMovesData
	thumb_func_end sub_8092C54

	thumb_func_start sub_8092C6C
sub_8092C6C:
	ldrh r1, [r0, 0x2]
	ldr r0, _08092C80
	ldr r2, [r0]
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldrb r0, [r0, 0x19]
	bx lr
	.align 2, 0
_08092C80: .4byte gMovesData
	thumb_func_end sub_8092C6C

	thumb_func_start sub_8092C84
sub_8092C84:
	push {r4,lr}
	sub sp, 0x8
	adds r4, r0, 0
	lsls r1, 16
	lsrs r1, 16
	mov r0, sp
	bl sub_8092A88
	adds r0, r4, 0
	mov r1, sp
	movs r2, 0
	bl sub_80928C0
	add sp, 0x8
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_8092C84

	thumb_func_start sub_8092CA8
sub_8092CA8:
	lsls r0, 16
	lsrs r0, 16
	ldr r1, _08092CBC
	ldr r2, [r1]
	lsls r1, r0, 3
	adds r1, r0
	lsls r1, 2
	adds r1, r2
	ldr r0, [r1, 0x20]
	bx lr
	.align 2, 0
_08092CBC: .4byte gMovesData
	thumb_func_end sub_8092CA8

	thumb_func_start sub_8092CC0
sub_8092CC0:
	lsls r0, 16
	lsrs r0, 16
	ldr r1, _08092CD4
	ldr r2, [r1]
	lsls r1, r0, 3
	adds r1, r0
	lsls r1, 2
	adds r1, r2
	ldrb r0, [r1, 0x14]
	bx lr
	.align 2, 0
_08092CD4: .4byte gMovesData
	thumb_func_end sub_8092CC0

	thumb_func_start sub_8092CD8
sub_8092CD8:
	lsls r0, 16
	lsrs r0, 16
	ldr r1, _08092CEC
	ldr r2, [r1]
	lsls r1, r0, 3
	adds r1, r0
	lsls r1, 2
	adds r1, r2
	ldrb r0, [r1, 0x15]
	bx lr
	.align 2, 0
_08092CEC: .4byte gMovesData
	thumb_func_end sub_8092CD8

	thumb_func_start sub_8092CF0
sub_8092CF0:
	lsls r0, 16
	lsrs r0, 16
	ldr r1, _08092D04
	ldr r2, [r1]
	lsls r1, r0, 3
	adds r1, r0
	lsls r1, 2
	adds r1, r2
	ldrb r0, [r1, 0x16]
	bx lr
	.align 2, 0
_08092D04: .4byte gMovesData
	thumb_func_end sub_8092CF0

	thumb_func_start sub_8092D08
sub_8092D08:
	push {lr}
	adds r2, r0, 0
	ldrh r1, [r2, 0x2]
	cmp r1, 0xD9
	beq _08092D4C
	movs r0, 0x8E
	lsls r0, 1
	cmp r1, r0
	beq _08092D4C
	cmp r1, 0x53
	beq _08092D4C
	cmp r1, 0x22
	beq _08092D4C
	cmp r1, 0x54
	beq _08092D4C
	cmp r1, 0xAB
	beq _08092D4C
	ldr r0, _08092D48
	cmp r1, r0
	beq _08092D4C
	cmp r1, 0x1B
	beq _08092D4C
	cmp r1, 0xF1
	beq _08092D4C
	cmp r1, 0x19
	beq _08092D4C
	ldrh r0, [r2, 0x2]
	cmp r0, 0x1A
	beq _08092D4C
	movs r0, 0
	b _08092D4E
	.align 2, 0
_08092D48: .4byte 0x00000125
_08092D4C:
	movs r0, 0x1
_08092D4E:
	pop {r1}
	bx r1
	thumb_func_end sub_8092D08

	thumb_func_start sub_8092D54
sub_8092D54:
	push {r4-r6,lr}
	adds r6, r0, 0
	adds r0, r1, 0
	ldr r5, _08092D78
	ldr r4, _08092D7C
	bl sub_8092C6C
	lsls r0, 2
	adds r0, r4
	ldr r2, [r0]
	adds r0, r6, 0
	adds r1, r5, 0
	bl ExpandPlaceholdersBuffer
	pop {r4-r6}
	pop {r0}
	bx r0
	.align 2, 0
_08092D78: .4byte gUnknown_810992C
_08092D7C: .4byte gRangeNames
	thumb_func_end sub_8092D54

	thumb_func_start sub_8092D80
sub_8092D80:
	push {r4,r5,lr}
	adds r3, r1, 0
	movs r5, 0
	lsls r1, r3, 3
	adds r1, r0
_08092D8A:
	adds r1, 0x8
	adds r3, 0x1
	cmp r3, 0x4
	beq _08092DB0
	ldrb r2, [r1]
	movs r4, 0x1
	adds r0, r4, 0
	ands r0, r2
	cmp r0, 0
	beq _08092DB0
	lsrs r0, r2, 1
	ands r0, r4
	cmp r0, 0
	bne _08092DAA
	adds r0, r3, 0
	b _08092DB2
_08092DAA:
	adds r5, 0x1
	cmp r5, 0x3
	ble _08092D8A
_08092DB0:
	movs r0, 0
_08092DB2:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_8092D80

	thumb_func_start sub_8092DB8
sub_8092DB8:
	push {r4-r6,lr}
	adds r4, r0, 0
	movs r5, 0
	movs r6, 0x1
_08092DC0:
	subs r1, 0x1
	cmp r1, 0
	bge _08092DF0
	movs r2, 0x3
	ldrb r1, [r4, 0x18]
	adds r0, r6, 0
	ands r0, r1
	cmp r0, 0
	beq _08092DD6
	movs r1, 0x3
	b _08092DEC
_08092DD6:
	subs r2, 0x1
	cmp r2, 0
	blt _08092E12
	lsls r0, r2, 3
	adds r0, r4
	ldrb r1, [r0]
	adds r0, r6, 0
	ands r0, r1
	cmp r0, 0
	beq _08092DD6
	adds r1, r2, 0
_08092DEC:
	cmp r2, 0
	blt _08092E12
_08092DF0:
	lsls r0, r1, 3
	adds r0, r4
	ldrb r2, [r0]
	movs r3, 0x1
	adds r0, r3, 0
	ands r0, r2
	cmp r0, 0
	beq _08092E12
	lsrs r0, r2, 1
	ands r0, r3
	cmp r0, 0
	bne _08092E0C
	adds r0, r1, 0
	b _08092E14
_08092E0C:
	adds r5, 0x1
	cmp r5, 0x3
	ble _08092DC0
_08092E12:
	movs r0, 0
_08092E14:
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end sub_8092DB8

	thumb_func_start sub_8092E1C
sub_8092E1C:
	push {r4,r5,lr}
	adds r3, r1, 0
	movs r5, 0
	lsls r1, r3, 3
	adds r1, r0
_08092E26:
	adds r1, 0x8
	adds r3, 0x1
	cmp r3, 0x8
	beq _08092E4C
	ldrb r2, [r1]
	movs r4, 0x1
	adds r0, r4, 0
	ands r0, r2
	cmp r0, 0
	beq _08092E4C
	lsrs r0, r2, 1
	ands r0, r4
	cmp r0, 0
	bne _08092E46
	adds r0, r3, 0
	b _08092E4E
_08092E46:
	adds r5, 0x1
	cmp r5, 0x7
	ble _08092E26
_08092E4C:
	movs r0, 0
_08092E4E:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_8092E1C

	thumb_func_start sub_8092E54
sub_8092E54:
	push {r4,r5,lr}
	adds r3, r1, 0
	movs r5, 0
	lsls r1, r3, 3
	adds r1, r0
_08092E5E:
	adds r1, 0x8
	adds r3, 0x1
	cmp r3, 0x8
	beq _08092E84
	ldrb r2, [r1]
	movs r4, 0x1
	adds r0, r4, 0
	ands r0, r2
	cmp r0, 0
	beq _08092E84
	lsrs r0, r2, 1
	ands r0, r4
	cmp r0, 0
	bne _08092E7E
	adds r0, r3, 0
	b _08092E86
_08092E7E:
	adds r5, 0x1
	cmp r5, 0x7
	ble _08092E5E
_08092E84:
	movs r0, 0
_08092E86:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_8092E54

	thumb_func_start sub_8092E8C
sub_8092E8C:
	push {r4-r6,lr}
	adds r6, r0, 0
	movs r5, 0
	lsls r0, r1, 3
	adds r3, r0, r6
_08092E96:
	subs r3, 0x8
	subs r1, 0x1
	cmp r1, 0
	bge _08092EC6
	movs r3, 0x7
	movs r4, 0x1
	adds r2, r6, 0
	adds r2, 0x38
_08092EA6:
	ldrb r1, [r2]
	adds r0, r4, 0
	ands r0, r1
	cmp r0, 0
	beq _08092EBC
	lsrs r0, r1, 1
	ands r0, r4
	cmp r0, 0
	bne _08092EBC
	adds r0, r3, 0
	b _08092EE6
_08092EBC:
	subs r2, 0x8
	subs r3, 0x1
	cmp r3, 0
	bgt _08092EA6
	b _08092EE4
_08092EC6:
	ldrb r2, [r3]
	movs r4, 0x1
	adds r0, r4, 0
	ands r0, r2
	cmp r0, 0
	beq _08092EE4
	lsrs r0, r2, 1
	ands r0, r4
	cmp r0, 0
	bne _08092EDE
	adds r0, r1, 0
	b _08092EE6
_08092EDE:
	adds r5, 0x1
	cmp r5, 0x7
	ble _08092E96
_08092EE4:
	movs r0, 0
_08092EE6:
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end sub_8092E8C

	thumb_func_start sub_8092EEC
sub_8092EEC:
	push {r4-r6,lr}
	adds r6, r0, 0
	movs r5, 0
	lsls r0, r1, 3
	adds r3, r0, r6
_08092EF6:
	subs r3, 0x8
	subs r1, 0x1
	cmp r1, 0
	bge _08092F26
	movs r3, 0x7
	movs r4, 0x1
	adds r2, r6, 0
	adds r2, 0x38
_08092F06:
	ldrb r1, [r2]
	adds r0, r4, 0
	ands r0, r1
	cmp r0, 0
	beq _08092F1C
	lsrs r0, r1, 1
	ands r0, r4
	cmp r0, 0
	bne _08092F1C
	adds r0, r3, 0
	b _08092F46
_08092F1C:
	subs r2, 0x8
	subs r3, 0x1
	cmp r3, 0
	bgt _08092F06
	b _08092F44
_08092F26:
	ldrb r2, [r3]
	movs r4, 0x1
	adds r0, r4, 0
	ands r0, r2
	cmp r0, 0
	beq _08092F44
	lsrs r0, r2, 1
	ands r0, r4
	cmp r0, 0
	bne _08092F3E
	adds r0, r1, 0
	b _08092F46
_08092F3E:
	adds r5, 0x1
	cmp r5, 0x7
	ble _08092EF6
_08092F44:
	movs r0, 0
_08092F46:
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end sub_8092EEC

	thumb_func_start sub_8092F4C
sub_8092F4C:
	push {r4,lr}
	adds r2, r0, 0
	cmp r1, 0
	ble _08092F78
	movs r4, 0x1
	lsls r0, r1, 3
	adds r3, r0, r2
_08092F5A:
	ldrb r2, [r3]
	adds r0, r4, 0
	ands r0, r2
	cmp r0, 0
	beq _08092F78
	lsrs r0, r2, 1
	ands r0, r4
	cmp r0, 0
	bne _08092F70
	adds r0, r1, 0
	b _08092F7A
_08092F70:
	subs r3, 0x8
	subs r1, 0x1
	cmp r1, 0
	bgt _08092F5A
_08092F78:
	movs r0, 0
_08092F7A:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_8092F4C

	thumb_func_start sub_8092F80
sub_8092F80:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0x80
	adds r7, r0, 0
	mov r8, r1
	lsls r0, r1, 3
	adds r0, r7, r0
	ldrb r2, [r0]
	movs r1, 0x80
	orrs r1, r2
	strb r1, [r0]
	adds r0, r7, 0
	mov r1, sp
	bl sub_8093784
	mov r0, sp
	bl sub_8093744
	adds r3, r0, 0
	cmp r3, 0x2
	bhi _08092FCC
	lsls r1, r3, 5
	adds r0, r3, 0x1
	lsls r0, 5
	mov r2, sp
	adds r5, r0, r2
	adds r4, r1, r2
	movs r6, 0x3
_08092FBA:
	ldr r2, [r4]
	ldr r3, [r4, 0x4]
	ldr r0, [r5]
	ldr r1, [r5, 0x4]
	stm r4!, {r0,r1}
	stm r5!, {r2,r3}
	subs r6, 0x1
	cmp r6, 0
	bge _08092FBA
_08092FCC:
	adds r0, r7, 0
	mov r1, sp
	bl sub_80937E0
	movs r3, 0
	movs r5, 0x80
	movs r4, 0x7F
	adds r1, r7, 0
_08092FDC:
	ldrb r2, [r1]
	adds r0, r5, 0
	ands r0, r2
	cmp r0, 0
	beq _08092FF0
	adds r0, r4, 0
	ands r0, r2
	strb r0, [r1]
	mov r8, r3
	b _08092FF8
_08092FF0:
	adds r1, 0x8
	adds r3, 0x1
	cmp r3, 0x3
	ble _08092FDC
_08092FF8:
	mov r0, r8
	add sp, 0x80
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_8092F80

	thumb_func_start sub_8093008
sub_8093008:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	ldr r4, _0809307C
	add sp, r4
	adds r7, r0, 0
	mov r8, r1
	lsls r0, r1, 3
	adds r0, r7, r0
	ldrb r2, [r0]
	movs r1, 0x80
	orrs r1, r2
	strb r1, [r0]
	adds r0, r7, 0
	mov r1, sp
	bl sub_8093974
	mov r0, sp
	bl sub_80938F4
	adds r3, r0, 0
	cmp r3, 0x6
	bhi _08093056
	lsls r1, r3, 6
	adds r0, r3, 0x1
	lsls r0, 6
	mov r2, sp
	adds r5, r0, r2
	adds r4, r1, r2
	movs r6, 0x7
_08093044:
	ldr r2, [r4]
	ldr r3, [r4, 0x4]
	ldr r0, [r5]
	ldr r1, [r5, 0x4]
	stm r4!, {r0,r1}
	stm r5!, {r2,r3}
	subs r6, 0x1
	cmp r6, 0
	bge _08093044
_08093056:
	adds r0, r7, 0
	mov r1, sp
	bl sub_8093A2C
	movs r3, 0
	movs r5, 0x80
	movs r4, 0x7F
	adds r1, r7, 0
_08093066:
	ldrb r2, [r1]
	adds r0, r5, 0
	ands r0, r2
	cmp r0, 0
	beq _08093080
	adds r0, r4, 0
	ands r0, r2
	strb r0, [r1]
	mov r8, r3
	b _08093088
	.align 2, 0
_0809307C: .4byte 0xfffffe00
_08093080:
	adds r1, 0x8
	adds r3, 0x1
	cmp r3, 0x7
	ble _08093066
_08093088:
	mov r0, r8
	movs r3, 0x80
	lsls r3, 2
	add sp, r3
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_8093008

	thumb_func_start sub_809309C
sub_809309C:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	ldr r4, _08093110
	add sp, r4
	adds r7, r0, 0
	mov r8, r1
	lsls r0, r1, 3
	adds r0, r7, r0
	ldrb r2, [r0]
	movs r1, 0x80
	orrs r1, r2
	strb r1, [r0]
	adds r0, r7, 0
	mov r1, sp
	bl sub_80939D0
	mov r0, sp
	bl sub_8093934
	adds r3, r0, 0
	cmp r3, 0x6
	bhi _080930EA
	lsls r1, r3, 6
	adds r0, r3, 0x1
	lsls r0, 6
	mov r2, sp
	adds r5, r0, r2
	adds r4, r1, r2
	movs r6, 0x7
_080930D8:
	ldr r2, [r4]
	ldr r3, [r4, 0x4]
	ldr r0, [r5]
	ldr r1, [r5, 0x4]
	stm r4!, {r0,r1}
	stm r5!, {r2,r3}
	subs r6, 0x1
	cmp r6, 0
	bge _080930D8
_080930EA:
	adds r0, r7, 0
	mov r1, sp
	bl sub_8093B40
	movs r3, 0
	movs r5, 0x80
	movs r4, 0x7F
	adds r1, r7, 0
_080930FA:
	ldrb r2, [r1]
	adds r0, r5, 0
	ands r0, r2
	cmp r0, 0
	beq _08093114
	adds r0, r4, 0
	ands r0, r2
	strb r0, [r1]
	mov r8, r3
	b _0809311C
	.align 2, 0
_08093110: .4byte 0xfffffe00
_08093114:
	adds r1, 0x8
	adds r3, 0x1
	cmp r3, 0x7
	ble _080930FA
_0809311C:
	mov r0, r8
	movs r3, 0x80
	lsls r3, 2
	add sp, r3
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_809309C

	thumb_func_start sub_8093130
sub_8093130:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0x80
	adds r7, r0, 0
	mov r8, r1
	lsls r0, r1, 3
	adds r0, r7, r0
	ldrb r2, [r0]
	movs r1, 0x80
	orrs r1, r2
	strb r1, [r0]
	adds r0, r7, 0
	mov r1, sp
	bl sub_8093784
	mov r0, sp
	bl sub_8093744
	adds r1, r0, 0
	subs r0, r1, 0x1
	cmp r0, 0x2
	bhi _0809317C
	lsls r1, 5
	lsls r0, 5
	mov r2, sp
	adds r5, r0, r2
	adds r4, r1, r2
	movs r6, 0x3
_0809316A:
	ldr r2, [r4]
	ldr r3, [r4, 0x4]
	ldr r0, [r5]
	ldr r1, [r5, 0x4]
	stm r4!, {r0,r1}
	stm r5!, {r2,r3}
	subs r6, 0x1
	cmp r6, 0
	bge _0809316A
_0809317C:
	adds r0, r7, 0
	mov r1, sp
	bl sub_80937E0
	movs r1, 0
	movs r5, 0x80
	movs r4, 0x7F
	adds r2, r7, 0
_0809318C:
	ldrb r3, [r2]
	adds r0, r5, 0
	ands r0, r3
	cmp r0, 0
	beq _080931A0
	adds r0, r4, 0
	ands r0, r3
	strb r0, [r2]
	mov r8, r1
	b _080931A8
_080931A0:
	adds r2, 0x8
	adds r1, 0x1
	cmp r1, 0x3
	ble _0809318C
_080931A8:
	mov r0, r8
	add sp, 0x80
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_8093130

	thumb_func_start sub_80931B8
sub_80931B8:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	ldr r4, _0809322C
	add sp, r4
	adds r7, r0, 0
	mov r8, r1
	lsls r0, r1, 3
	adds r0, r7, r0
	ldrb r2, [r0]
	movs r1, 0x80
	orrs r1, r2
	strb r1, [r0]
	adds r0, r7, 0
	mov r1, sp
	bl sub_8093974
	mov r0, sp
	bl sub_80938F4
	adds r1, r0, 0
	subs r0, r1, 0x1
	cmp r0, 0x6
	bhi _08093206
	lsls r1, 6
	lsls r0, 6
	mov r2, sp
	adds r5, r0, r2
	adds r4, r1, r2
	movs r6, 0x7
_080931F4:
	ldr r2, [r4]
	ldr r3, [r4, 0x4]
	ldr r0, [r5]
	ldr r1, [r5, 0x4]
	stm r4!, {r0,r1}
	stm r5!, {r2,r3}
	subs r6, 0x1
	cmp r6, 0
	bge _080931F4
_08093206:
	adds r0, r7, 0
	mov r1, sp
	bl sub_8093A2C
	movs r1, 0
	movs r5, 0x80
	movs r4, 0x7F
	adds r2, r7, 0
_08093216:
	ldrb r3, [r2]
	adds r0, r5, 0
	ands r0, r3
	cmp r0, 0
	beq _08093230
	adds r0, r4, 0
	ands r0, r3
	strb r0, [r2]
	mov r8, r1
	b _08093238
	.align 2, 0
_0809322C: .4byte 0xfffffe00
_08093230:
	adds r2, 0x8
	adds r1, 0x1
	cmp r1, 0x7
	ble _08093216
_08093238:
	mov r0, r8
	movs r3, 0x80
	lsls r3, 2
	add sp, r3
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_80931B8

	thumb_func_start sub_809324C
sub_809324C:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	ldr r4, _080932C0
	add sp, r4
	adds r7, r0, 0
	mov r8, r1
	lsls r0, r1, 3
	adds r0, r7, r0
	ldrb r2, [r0]
	movs r1, 0x80
	orrs r1, r2
	strb r1, [r0]
	adds r0, r7, 0
	mov r1, sp
	bl sub_80939D0
	mov r0, sp
	bl sub_8093934
	adds r1, r0, 0
	subs r0, r1, 0x1
	cmp r0, 0x6
	bhi _0809329A
	lsls r1, 6
	lsls r0, 6
	mov r2, sp
	adds r5, r0, r2
	adds r4, r1, r2
	movs r6, 0x7
_08093288:
	ldr r2, [r4]
	ldr r3, [r4, 0x4]
	ldr r0, [r5]
	ldr r1, [r5, 0x4]
	stm r4!, {r0,r1}
	stm r5!, {r2,r3}
	subs r6, 0x1
	cmp r6, 0
	bge _08093288
_0809329A:
	adds r0, r7, 0
	mov r1, sp
	bl sub_8093B40
	movs r1, 0
	movs r5, 0x80
	movs r4, 0x7F
	adds r2, r7, 0
_080932AA:
	ldrb r3, [r2]
	adds r0, r5, 0
	ands r0, r3
	cmp r0, 0
	beq _080932C4
	adds r0, r4, 0
	ands r0, r3
	strb r0, [r2]
	mov r8, r1
	b _080932CC
	.align 2, 0
_080932C0: .4byte 0xfffffe00
_080932C4:
	adds r2, 0x8
	adds r1, 0x1
	cmp r1, 0x7
	ble _080932AA
_080932CC:
	mov r0, r8
	movs r3, 0x80
	lsls r3, 2
	add sp, r3
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_809324C

	thumb_func_start sub_80932E0
sub_80932E0:
	push {lr}
	lsls r0, 3
	adds r0, r1
	ldrb r1, [r0]
	movs r0, 0x8
	ands r0, r1
	cmp r0, 0
	bne _080932F4
	movs r0, 0
	b _080932F6
_080932F4:
	movs r0, 0x1
_080932F6:
	pop {r1}
	bx r1
	thumb_func_end sub_80932E0

	thumb_func_start sub_80932FC
sub_80932FC:
	push {lr}
	lsls r0, 3
	adds r0, r1
	ldrb r1, [r0]
	movs r0, 0x4
	ands r0, r1
	cmp r0, 0
	bne _08093310
	movs r0, 0
	b _08093312
_08093310:
	movs r0, 0x1
_08093312:
	pop {r1}
	bx r1
	thumb_func_end sub_80932FC

	thumb_func_start sub_8093318
sub_8093318:
	push {r4,lr}
	sub sp, 0x40
	adds r4, r0, 0
	mov r0, sp
	movs r2, 0x40
	bl MemoryCopy8
	adds r0, r4, 0
	mov r1, sp
	bl sub_8093400
	lsls r0, 24
	lsrs r0, 24
	add sp, 0x40
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_8093318

	thumb_func_start sub_809333C
sub_809333C:
	push {r4,lr}
	sub sp, 0x40
	adds r4, r0, 0
	mov r0, sp
	movs r2, 0x40
	bl MemoryCopy8
	adds r0, r4, 0
	mov r1, sp
	bl sub_8093468
	lsls r0, 24
	lsrs r0, 24
	add sp, 0x40
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_809333C

	thumb_func_start sub_8093360
sub_8093360:
	push {r4,lr}
	sub sp, 0x40
	adds r4, r0, 0
	mov r0, sp
	movs r2, 0x40
	bl MemoryCopy8
	adds r0, r4, 0
	mov r1, sp
	bl sub_80933D8
	lsls r0, 24
	lsrs r0, 24
	add sp, 0x40
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_8093360

	thumb_func_start sub_8093384
sub_8093384:
	push {lr}
	lsls r0, 3
	adds r0, r1
	ldrb r1, [r0]
	movs r0, 0x8
	ands r0, r1
	cmp r0, 0
	bne _08093398
	movs r0, 0x1
	b _0809339A
_08093398:
	movs r0, 0
_0809339A:
	pop {r1}
	bx r1
	thumb_func_end sub_8093384

	thumb_func_start sub_80933A0
sub_80933A0:
	push {r4-r6,lr}
	movs r4, 0
	movs r6, 0x1
	movs r5, 0x2
	movs r3, 0x7
_080933AA:
	ldrb r2, [r1]
	adds r0, r6, 0
	ands r0, r2
	cmp r0, 0
	beq _080933BE
	adds r0, r5, 0
	ands r0, r2
	cmp r0, 0
	bne _080933BE
	adds r4, 0x1
_080933BE:
	adds r1, 0x8
	subs r3, 0x1
	cmp r3, 0
	bge _080933AA
	cmp r4, 0x1
	bgt _080933CE
	movs r0, 0
	b _080933D0
_080933CE:
	movs r0, 0x1
_080933D0:
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end sub_80933A0

	thumb_func_start sub_80933D8
sub_80933D8:
	push {r4,r5,lr}
	adds r4, r0, 0
	adds r5, r1, 0
	bl sub_8093400
	lsls r0, 24
	cmp r0, 0
	bne _080933F6
	adds r0, r4, 0
	adds r1, r5, 0
	bl sub_8093468
	lsls r0, 24
	lsrs r0, 24
	b _080933F8
_080933F6:
	movs r0, 0x1
_080933F8:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_80933D8

	thumb_func_start sub_8093400
sub_8093400:
	push {r4-r7,lr}
	adds r4, r0, 0
	adds r7, r1, 0
	lsls r0, r4, 3
	adds r0, r7, r0
	ldrh r0, [r0, 0x2]
	bl sub_809422C
	lsls r0, 24
	cmp r0, 0
	beq _08093428
	b _08093460
_08093418:
	adds r0, r1, 0
	orrs r0, r2
	strb r0, [r6]
	adds r0, r7, 0
	bl sub_809371C
	movs r0, 0x1
	b _08093462
_08093428:
	adds r5, r4, 0x1
	cmp r5, 0x7
	bgt _08093460
	lsls r0, r5, 3
	adds r4, r0, r7
	adds r6, r4, 0
_08093434:
	ldrb r1, [r4]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _08093460
	ldrh r0, [r4, 0x2]
	bl sub_809422C
	lsls r0, 24
	cmp r0, 0
	bne _08093460
	ldrb r1, [r4]
	movs r2, 0x2
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	beq _08093418
	adds r4, 0x8
	adds r6, 0x8
	adds r5, 0x1
	cmp r5, 0x7
	ble _08093434
_08093460:
	movs r0, 0
_08093462:
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_8093400

	thumb_func_start sub_8093468
sub_8093468:
	push {r4-r7,lr}
	adds r6, r1, 0
	movs r5, 0
	adds r1, r0, 0x1
	movs r4, 0
	cmp r1, 0x7
	bgt _080934A0
	movs r0, 0x2
	mov r12, r0
	movs r7, 0xFD
	lsls r0, r1, 3
	adds r3, r0, r6
_08093480:
	ldrb r2, [r3]
	mov r0, r12
	ands r0, r2
	cmp r0, 0
	beq _080934A0
	adds r0, r7, 0
	ands r0, r2
	strb r0, [r3]
	movs r5, 0x1
	adds r3, 0x8
	adds r1, 0x1
	adds r4, 0x1
	cmp r4, 0x7
	bgt _080934A0
	cmp r1, 0x7
	ble _08093480
_080934A0:
	adds r0, r6, 0
	bl sub_809371C
	adds r0, r5, 0
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_8093468

	thumb_func_start sub_80934B0
sub_80934B0:
	push {lr}
	adds r2, r0, 0
	adds r0, r2, 0x1
	cmp r0, 0x7
	bgt _080934D2
	lsls r0, r2, 3
	adds r0, 0x8
	adds r0, r1, r0
	ldrb r1, [r0]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _080934D2
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	bne _080934D6
_080934D2:
	movs r0, 0
	b _080934D8
_080934D6:
	movs r0, 0x1
_080934D8:
	pop {r1}
	bx r1
	thumb_func_end sub_80934B0

	thumb_func_start sub_80934DC
sub_80934DC:
	push {r4-r7,lr}
	adds r5, r1, 0
	lsls r0, 3
	adds r4, r5, r0
	ldrb r1, [r4]
	movs r0, 0x8
	ands r0, r1
	cmp r0, 0
	beq _080934F4
	movs r0, 0xF7
	ands r0, r1
	b _0809351A
_080934F4:
	movs r7, 0x1
	movs r6, 0xF7
	adds r1, r5, 0
	movs r3, 0x3
_080934FC:
	ldrb r2, [r1]
	adds r0, r7, 0
	ands r0, r2
	cmp r0, 0
	beq _0809350C
	adds r0, r6, 0
	ands r0, r2
	strb r0, [r1]
_0809350C:
	adds r1, 0x8
	subs r3, 0x1
	cmp r3, 0
	bge _080934FC
	ldrb r1, [r4]
	movs r0, 0x8
	orrs r0, r1
_0809351A:
	strb r0, [r4]
	adds r0, r5, 0
	bl sub_809371C
	movs r0, 0x1
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_80934DC

	thumb_func_start sub_809352C
sub_809352C:
	push {lr}
	lsls r0, 3
	adds r0, r1, r0
	ldrb r3, [r0]
	movs r2, 0xF7
	ands r2, r3
	strb r2, [r0]
	adds r0, r1, 0
	bl sub_809371C
	pop {r0}
	bx r0
	thumb_func_end sub_809352C

	thumb_func_start sub_8093544
sub_8093544:
	push {lr}
	lsls r0, 3
	adds r0, r1, r0
	ldrb r2, [r0]
	movs r3, 0x4
	eors r2, r3
	strb r2, [r0]
	adds r0, r1, 0
	bl sub_809371C
	movs r0, 0x1
	pop {r1}
	bx r1
	thumb_func_end sub_8093544

	thumb_func_start sub_8093560
sub_8093560:
	push {r4-r7,lr}
	adds r4, r0, 0
	adds r6, r1, 0
	movs r5, 0x1
	lsls r0, r4, 3
	adds r0, r6, r0
	ldrh r0, [r0, 0x2]
	strh r0, [r2]
	movs r1, 0
	adds r0, r2, 0x2
	movs r3, 0x2
_08093576:
	strh r1, [r0]
	adds r0, 0x2
	subs r3, 0x1
	cmp r3, 0
	bge _08093576
	adds r4, 0x1
	adds r2, 0x2
	cmp r4, 0x7
	bgt _080935B0
	cmp r5, 0x3
	bgt _080935B0
	movs r7, 0x2
	lsls r0, r4, 3
	adds r3, r0, r6
_08093592:
	ldrb r1, [r3]
	adds r0, r7, 0
	ands r0, r1
	cmp r0, 0
	beq _080935B0
	ldrh r0, [r3, 0x2]
	strh r0, [r2]
	adds r2, 0x2
	adds r5, 0x1
	adds r3, 0x8
	adds r4, 0x1
	cmp r4, 0x7
	bgt _080935B0
	cmp r5, 0x3
	ble _08093592
_080935B0:
	adds r0, r5, 0
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_8093560

	thumb_func_start sub_80935B8
sub_80935B8:
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	adds r5, r0, 0
	movs r0, 0x63
	mov r12, r0
	movs r0, 0
	mov r8, r0
	movs r6, 0
	adds r4, r1, 0
	cmp r4, 0
	blt _08093606
	lsls r0, r4, 3
	adds r2, r5, r0
	ldrb r1, [r2]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _08093606
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	beq _08093606
	movs r7, 0x1
	movs r3, 0x2
_080935EC:
	subs r2, 0x8
	subs r4, 0x1
	cmp r4, 0
	blt _08093606
	ldrb r1, [r2]
	adds r0, r7, 0
	ands r0, r1
	cmp r0, 0
	beq _08093606
	adds r0, r3, 0
	ands r0, r1
	cmp r0, 0
	bne _080935EC
_08093606:
	adds r2, r4, 0x1
	mov r9, r2
	cmp r2, 0x3
	bgt _08093642
	lsls r0, r2, 3
	adds r3, r5, r0
	ldrb r1, [r3]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _08093642
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	beq _08093642
	movs r6, 0x1
	movs r7, 0x2
_08093628:
	adds r3, 0x8
	adds r2, 0x1
	cmp r2, 0x3
	bgt _08093642
	ldrb r1, [r3]
	adds r0, r6, 0
	ands r0, r1
	cmp r0, 0
	beq _08093642
	adds r0, r7, 0
	ands r0, r1
	cmp r0, 0
	bne _08093628
_08093642:
	cmp r6, 0
	bne _0809364A
	movs r0, 0x63
	b _080936CC
_0809364A:
	movs r6, 0
	b _08093668
_0809364E:
	ldrb r0, [r3, 0x4]
	cmp r12, r0
	ble _08093656
	mov r12, r0
_08093656:
	cmp r0, 0
	bne _0809365C
	movs r6, 0x1
_0809365C:
	ldrb r1, [r3, 0x1]
	movs r0, 0x20
	ands r0, r1
	cmp r0, 0
	beq _08093668
	movs r6, 0x1
_08093668:
	subs r2, 0x1
	cmp r2, r4
	blt _0809367C
	lsls r0, r2, 3
	adds r3, r5, r0
	ldrb r1, [r3]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	bne _0809364E
_0809367C:
	cmp r6, 0
	beq _080936C6
	mov r2, r9
	cmp r2, 0x3
	bgt _080936C0
	lsls r0, r2, 3
	adds r3, r5, r0
	ldrb r1, [r3]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _080936C0
	movs r6, 0x2
	movs r4, 0xFD
_08093698:
	ldrb r1, [r3]
	adds r0, r6, 0
	ands r0, r1
	cmp r0, 0
	beq _080936C0
	adds r0, r4, 0
	ands r0, r1
	strb r0, [r3]
	movs r0, 0x1
	mov r8, r0
	adds r2, 0x1
	cmp r2, 0x3
	bgt _080936C0
	lsls r0, r2, 3
	adds r3, r5, r0
	ldrb r1, [r3]
	mov r0, r8
	ands r0, r1
	cmp r0, 0
	bne _08093698
_080936C0:
	mov r0, r8
	cmp r0, 0
	bne _080936CA
_080936C6:
	mov r0, r12
	b _080936CC
_080936CA:
	movs r0, 0
_080936CC:
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_80935B8

	thumb_func_start sub_80936D8
sub_80936D8:
	push {r4,lr}
	sub sp, 0x80
	adds r4, r0, 0
	mov r1, sp
	bl sub_8093784
	adds r0, r4, 0
	mov r1, sp
	bl sub_80937E0
	add sp, 0x80
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_80936D8

	thumb_func_start sub_80936F4
sub_80936F4:
	push {r4,lr}
	ldr r4, _08093718
	add sp, r4
	adds r4, r0, 0
	mov r1, sp
	bl sub_8093974
	adds r0, r4, 0
	mov r1, sp
	bl sub_8093A2C
	movs r3, 0x80
	lsls r3, 2
	add sp, r3
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08093718: .4byte 0xfffffe00
	thumb_func_end sub_80936F4

	thumb_func_start sub_809371C
sub_809371C:
	push {r4,lr}
	ldr r4, _08093740
	add sp, r4
	adds r4, r0, 0
	mov r1, sp
	bl sub_80939D0
	adds r0, r4, 0
	mov r1, sp
	bl sub_8093B40
	movs r3, 0x80
	lsls r3, 2
	add sp, r3
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08093740: .4byte 0xfffffe00
	thumb_func_end sub_809371C

	thumb_func_start sub_8093744
sub_8093744:
	push {r4-r7,lr}
	adds r7, r0, 0
	movs r4, 0
	movs r6, 0x1
	movs r5, 0x80
_0809374E:
	movs r3, 0
	lsls r0, r4, 5
	adds r2, r0, r7
_08093754:
	ldrb r1, [r2]
	adds r0, r6, 0
	ands r0, r1
	cmp r0, 0
	beq _0809376A
	adds r0, r5, 0
	ands r0, r1
	cmp r0, 0
	beq _0809376A
	adds r0, r4, 0
	b _0809377C
_0809376A:
	adds r2, 0x8
	adds r3, 0x1
	cmp r3, 0x3
	ble _08093754
	adds r4, 0x1
	cmp r4, 0x3
	ble _0809374E
	movs r0, 0x1
	negs r0, r0
_0809377C:
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_8093744

	thumb_func_start sub_8093784
sub_8093784:
	push {r4-r7,lr}
	adds r6, r0, 0
	movs r2, 0
	movs r4, 0
_0809378C:
	lsls r0, r2, 5
	adds r2, 0x1
	movs r3, 0x3
	adds r0, r1
	adds r0, 0x18
_08093796:
	strb r4, [r0]
	subs r0, 0x8
	subs r3, 0x1
	cmp r3, 0
	bge _08093796
	cmp r2, 0x3
	ble _0809378C
	movs r3, 0
	movs r5, 0
	adds r4, r1, 0
	subs r4, 0x20
	movs r7, 0x2
_080937AE:
	cmp r5, 0
	beq _080937BC
	ldrb r1, [r6]
	adds r0, r7, 0
	ands r0, r1
	cmp r0, 0
	bne _080937C0
_080937BC:
	adds r4, 0x20
	movs r3, 0
_080937C0:
	lsls r2, r3, 3
	adds r2, r4
	ldm r6!, {r0,r1}
	str r0, [r2]
	str r1, [r2, 0x4]
	ldrb r1, [r2]
	movs r0, 0xFD
	ands r0, r1
	strb r0, [r2]
	adds r3, 0x1
	adds r5, 0x1
	cmp r5, 0x3
	ble _080937AE
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_8093784

	thumb_func_start sub_80937E0
sub_80937E0:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x10
	str r0, [sp, 0x8]
	mov r9, r1
	movs r0, 0
	mov r8, r0
	movs r6, 0
	add r1, sp, 0x4
	mov r10, r1
	mov r12, r6
	movs r3, 0x1
_080937FE:
	mov r2, sp
	adds r0, r2, r6
	mov r7, r12
	strb r7, [r0]
	mov r1, sp
	adds r1, r6
	adds r1, 0x4
	mov r2, r12
	strb r2, [r1]
	adds r7, r0, 0
	lsls r0, r6, 5
	adds r6, 0x1
	adds r5, r1, 0
	mov r1, r9
	adds r2, r0, r1
	movs r4, 0x3
_0809381E:
	ldrb r1, [r2]
	adds r0, r3, 0
	ands r0, r1
	cmp r0, 0
	beq _0809383E
	movs r0, 0x8
	ands r0, r1
	cmp r0, 0
	beq _08093832
	strb r3, [r7]
_08093832:
	ldrb r1, [r2]
	movs r0, 0x4
	ands r0, r1
	cmp r0, 0
	beq _0809383E
	strb r3, [r5]
_0809383E:
	adds r2, 0x8
	subs r4, 0x1
	cmp r4, 0
	bge _0809381E
	cmp r6, 0x3
	ble _080937FE
	movs r6, 0
	mov r2, r8
	lsls r2, 3
	str r2, [sp, 0xC]
_08093852:
	movs r4, 0
	lsls r0, r6, 5
	mov r7, r9
	adds r5, r0, r7
	ldr r0, [sp, 0xC]
	ldr r1, [sp, 0x8]
	adds r2, r0, r1
	mov r7, r10
	adds r7, r6
	mov r12, r7
_08093866:
	ldrb r1, [r5]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _080938D6
	ldr r0, [r5]
	ldr r1, [r5, 0x4]
	str r0, [r2]
	str r1, [r2, 0x4]
	cmp r4, 0
	bne _08093884
	ldrb r1, [r2]
	movs r0, 0xFD
	ands r0, r1
	b _0809388A
_08093884:
	ldrb r0, [r2]
	movs r1, 0x2
	orrs r0, r1
_0809388A:
	strb r0, [r2]
	ldrb r0, [r2]
	movs r3, 0xF7
	ands r3, r0
	movs r1, 0
	movs r0, 0xFB
	ands r3, r0
	strb r3, [r2]
	mov r7, sp
	adds r0, r7, r6
	ldrb r0, [r0]
	cmp r0, 0
	beq _080938B0
	cmp r4, 0
	bne _080938B0
	movs r1, 0x8
	adds r0, r3, 0
	orrs r0, r1
	strb r0, [r2]
_080938B0:
	mov r1, r12
	ldrb r0, [r1]
	cmp r0, 0
	beq _080938C4
	cmp r4, 0
	bne _080938C4
	ldrb r0, [r2]
	movs r1, 0x4
	orrs r0, r1
	strb r0, [r2]
_080938C4:
	adds r2, 0x8
	ldr r7, [sp, 0xC]
	adds r7, 0x8
	str r7, [sp, 0xC]
	movs r0, 0x1
	add r8, r0
	mov r1, r8
	cmp r1, 0x4
	beq _080938E4
_080938D6:
	adds r5, 0x8
	adds r4, 0x1
	cmp r4, 0x3
	ble _08093866
	adds r6, 0x1
	cmp r6, 0x3
	ble _08093852
_080938E4:
	add sp, 0x10
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_80937E0

	thumb_func_start sub_80938F4
sub_80938F4:
	push {r4-r7,lr}
	adds r7, r0, 0
	movs r4, 0
	movs r6, 0x1
	movs r5, 0x80
_080938FE:
	movs r3, 0
	lsls r0, r4, 6
	adds r2, r0, r7
_08093904:
	ldrb r1, [r2]
	adds r0, r6, 0
	ands r0, r1
	cmp r0, 0
	beq _0809391A
	adds r0, r5, 0
	ands r0, r1
	cmp r0, 0
	beq _0809391A
	adds r0, r4, 0
	b _0809392C
_0809391A:
	adds r2, 0x8
	adds r3, 0x1
	cmp r3, 0x7
	ble _08093904
	adds r4, 0x1
	cmp r4, 0x7
	ble _080938FE
	movs r0, 0x1
	negs r0, r0
_0809392C:
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_80938F4

	thumb_func_start sub_8093934
sub_8093934:
	push {r4-r7,lr}
	adds r7, r0, 0
	movs r4, 0
	movs r6, 0x1
	movs r5, 0x80
_0809393E:
	movs r3, 0
	lsls r0, r4, 6
	adds r2, r0, r7
_08093944:
	ldrb r1, [r2]
	adds r0, r6, 0
	ands r0, r1
	cmp r0, 0
	beq _0809395A
	adds r0, r5, 0
	ands r0, r1
	cmp r0, 0
	beq _0809395A
	adds r0, r4, 0
	b _0809396C
_0809395A:
	adds r2, 0x8
	adds r3, 0x1
	cmp r3, 0x7
	ble _08093944
	adds r4, 0x1
	cmp r4, 0x7
	ble _0809393E
	movs r0, 0x1
	negs r0, r0
_0809396C:
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_8093934

	thumb_func_start sub_8093974
sub_8093974:
	push {r4-r7,lr}
	adds r6, r0, 0
	movs r2, 0
	movs r4, 0
_0809397C:
	lsls r0, r2, 6
	adds r2, 0x1
	movs r3, 0x7
	adds r0, r1
	adds r0, 0x38
_08093986:
	strb r4, [r0]
	subs r0, 0x8
	subs r3, 0x1
	cmp r3, 0
	bge _08093986
	cmp r2, 0x7
	ble _0809397C
	movs r3, 0
	movs r5, 0
	adds r4, r1, 0
	subs r4, 0x40
	movs r7, 0x2
_0809399E:
	cmp r5, 0
	beq _080939AC
	ldrb r1, [r6]
	adds r0, r7, 0
	ands r0, r1
	cmp r0, 0
	bne _080939B0
_080939AC:
	adds r4, 0x40
	movs r3, 0
_080939B0:
	lsls r2, r3, 3
	adds r2, r4
	ldm r6!, {r0,r1}
	str r0, [r2]
	str r1, [r2, 0x4]
	ldrb r1, [r2]
	movs r0, 0xFD
	ands r0, r1
	strb r0, [r2]
	adds r3, 0x1
	adds r5, 0x1
	cmp r5, 0x7
	ble _0809399E
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_8093974

	thumb_func_start sub_80939D0
sub_80939D0:
	push {r4-r7,lr}
	adds r6, r0, 0
	movs r2, 0
	movs r4, 0
_080939D8:
	lsls r0, r2, 6
	adds r2, 0x1
	movs r3, 0x7
	adds r0, r1
	adds r0, 0x38
_080939E2:
	strb r4, [r0]
	subs r0, 0x8
	subs r3, 0x1
	cmp r3, 0
	bge _080939E2
	cmp r2, 0x7
	ble _080939D8
	movs r3, 0
	movs r5, 0
	adds r4, r1, 0
	subs r4, 0x40
	movs r7, 0x2
_080939FA:
	cmp r5, 0
	beq _08093A08
	ldrb r1, [r6]
	adds r0, r7, 0
	ands r0, r1
	cmp r0, 0
	bne _08093A0C
_08093A08:
	adds r4, 0x40
	movs r3, 0
_08093A0C:
	lsls r2, r3, 3
	adds r2, r4
	ldm r6!, {r0,r1}
	str r0, [r2]
	str r1, [r2, 0x4]
	ldrb r1, [r2]
	movs r0, 0xFD
	ands r0, r1
	strb r0, [r2]
	adds r3, 0x1
	adds r5, 0x1
	cmp r5, 0x7
	ble _080939FA
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_80939D0

	thumb_func_start sub_8093A2C
sub_8093A2C:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x18
	str r0, [sp, 0x10]
	mov r9, r1
	movs r0, 0
	mov r8, r0
	movs r6, 0
	add r1, sp, 0x8
	mov r10, r1
	mov r12, r6
	movs r3, 0x1
_08093A4A:
	mov r2, sp
	adds r0, r2, r6
	mov r7, r12
	strb r7, [r0]
	mov r1, sp
	adds r1, r6
	adds r1, 0x8
	mov r2, r12
	strb r2, [r1]
	adds r7, r0, 0
	lsls r0, r6, 6
	adds r6, 0x1
	adds r5, r1, 0
	mov r1, r9
	adds r2, r0, r1
	movs r4, 0x7
_08093A6A:
	ldrb r1, [r2]
	adds r0, r3, 0
	ands r0, r1
	cmp r0, 0
	beq _08093A8A
	movs r0, 0x8
	ands r0, r1
	cmp r0, 0
	beq _08093A7E
	strb r3, [r7]
_08093A7E:
	ldrb r1, [r2]
	movs r0, 0x4
	ands r0, r1
	cmp r0, 0
	beq _08093A8A
	strb r3, [r5]
_08093A8A:
	adds r2, 0x8
	subs r4, 0x1
	cmp r4, 0
	bge _08093A6A
	cmp r6, 0x7
	ble _08093A4A
	movs r6, 0
	mov r2, r8
	lsls r2, 3
	str r2, [sp, 0x14]
_08093A9E:
	movs r4, 0
	lsls r0, r6, 6
	mov r7, r9
	adds r5, r0, r7
	ldr r0, [sp, 0x14]
	ldr r1, [sp, 0x10]
	adds r2, r0, r1
	mov r7, r10
	adds r7, r6
	mov r12, r7
_08093AB2:
	ldrb r1, [r5]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _08093B22
	ldr r0, [r5]
	ldr r1, [r5, 0x4]
	str r0, [r2]
	str r1, [r2, 0x4]
	cmp r4, 0
	bne _08093AD0
	ldrb r1, [r2]
	movs r0, 0xFD
	ands r0, r1
	b _08093AD6
_08093AD0:
	ldrb r0, [r2]
	movs r1, 0x2
	orrs r0, r1
_08093AD6:
	strb r0, [r2]
	ldrb r0, [r2]
	movs r3, 0xF7
	ands r3, r0
	movs r1, 0
	movs r0, 0xFB
	ands r3, r0
	strb r3, [r2]
	mov r7, sp
	adds r0, r7, r6
	ldrb r0, [r0]
	cmp r0, 0
	beq _08093AFC
	cmp r4, 0
	bne _08093AFC
	movs r1, 0x8
	adds r0, r3, 0
	orrs r0, r1
	strb r0, [r2]
_08093AFC:
	mov r1, r12
	ldrb r0, [r1]
	cmp r0, 0
	beq _08093B10
	cmp r4, 0
	bne _08093B10
	ldrb r0, [r2]
	movs r1, 0x4
	orrs r0, r1
	strb r0, [r2]
_08093B10:
	adds r2, 0x8
	ldr r7, [sp, 0x14]
	adds r7, 0x8
	str r7, [sp, 0x14]
	movs r0, 0x1
	add r8, r0
	mov r1, r8
	cmp r1, 0x8
	beq _08093B30
_08093B22:
	adds r5, 0x8
	adds r4, 0x1
	cmp r4, 0x7
	ble _08093AB2
	adds r6, 0x1
	cmp r6, 0x7
	ble _08093A9E
_08093B30:
	add sp, 0x18
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_8093A2C

	thumb_func_start sub_8093B40
sub_8093B40:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x18
	str r0, [sp, 0x10]
	mov r9, r1
	movs r0, 0
	mov r8, r0
	movs r6, 0
	add r1, sp, 0x8
	mov r10, r1
	mov r12, r6
	movs r3, 0x1
_08093B5E:
	mov r2, sp
	adds r0, r2, r6
	mov r7, r12
	strb r7, [r0]
	mov r1, sp
	adds r1, r6
	adds r1, 0x8
	mov r2, r12
	strb r2, [r1]
	adds r7, r0, 0
	lsls r0, r6, 6
	adds r6, 0x1
	adds r5, r1, 0
	mov r1, r9
	adds r2, r0, r1
	movs r4, 0x7
_08093B7E:
	ldrb r1, [r2]
	adds r0, r3, 0
	ands r0, r1
	cmp r0, 0
	beq _08093B9E
	movs r0, 0x8
	ands r0, r1
	cmp r0, 0
	beq _08093B92
	strb r3, [r7]
_08093B92:
	ldrb r1, [r2]
	movs r0, 0x4
	ands r0, r1
	cmp r0, 0
	beq _08093B9E
	strb r3, [r5]
_08093B9E:
	adds r2, 0x8
	subs r4, 0x1
	cmp r4, 0
	bge _08093B7E
	cmp r6, 0x7
	ble _08093B5E
	movs r6, 0
	mov r2, r8
	lsls r2, 3
	str r2, [sp, 0x14]
_08093BB2:
	movs r4, 0
	lsls r0, r6, 6
	mov r7, r9
	adds r5, r0, r7
	ldr r0, [sp, 0x14]
	ldr r1, [sp, 0x10]
	adds r2, r0, r1
	mov r7, r10
	adds r7, r6
	mov r12, r7
_08093BC6:
	ldrb r1, [r5]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _08093C36
	ldr r0, [r5]
	ldr r1, [r5, 0x4]
	str r0, [r2]
	str r1, [r2, 0x4]
	cmp r4, 0
	bne _08093BE4
	ldrb r1, [r2]
	movs r0, 0xFD
	ands r0, r1
	b _08093BEA
_08093BE4:
	ldrb r0, [r2]
	movs r1, 0x2
	orrs r0, r1
_08093BEA:
	strb r0, [r2]
	ldrb r0, [r2]
	movs r3, 0xF7
	ands r3, r0
	movs r1, 0
	movs r0, 0xFB
	ands r3, r0
	strb r3, [r2]
	mov r7, sp
	adds r0, r7, r6
	ldrb r0, [r0]
	cmp r0, 0
	beq _08093C10
	cmp r4, 0
	bne _08093C10
	movs r1, 0x8
	adds r0, r3, 0
	orrs r0, r1
	strb r0, [r2]
_08093C10:
	mov r1, r12
	ldrb r0, [r1]
	cmp r0, 0
	beq _08093C24
	cmp r4, 0
	bne _08093C24
	ldrb r0, [r2]
	movs r1, 0x4
	orrs r0, r1
	strb r0, [r2]
_08093C24:
	adds r2, 0x8
	ldr r7, [sp, 0x14]
	adds r7, 0x8
	str r7, [sp, 0x14]
	movs r0, 0x1
	add r8, r0
	mov r1, r8
	cmp r1, 0x8
	beq _08093C44
_08093C36:
	adds r5, 0x8
	adds r4, 0x1
	cmp r4, 0x7
	ble _08093BC6
	adds r6, 0x1
	cmp r6, 0x7
	ble _08093BB2
_08093C44:
	add sp, 0x18
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_8093B40

	thumb_func_start sub_8093C54
sub_8093C54:
	push {r4-r7,lr}
	sub sp, 0x40
	adds r6, r0, 0
	lsls r0, r1, 3
	adds r0, r6
	movs r2, 0
	strb r2, [r0]
	adds r3, r1, 0x1
	cmp r3, 0x7
	bgt _08093CA6
	lsls r0, r3, 3
	adds r4, r6, r0
	ldrb r1, [r4]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _08093CA6
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	beq _08093CA6
	mov r12, r2
	movs r7, 0x1
	adds r2, r4, 0
	movs r5, 0x2
_08093C86:
	mov r0, r12
	strb r0, [r4]
	adds r2, 0x8
	adds r3, 0x1
	cmp r3, 0x7
	bgt _08093CA6
	adds r4, r2, 0
	ldrb r1, [r2]
	adds r0, r7, 0
	ands r0, r1
	cmp r0, 0
	beq _08093CA6
	adds r0, r5, 0
	ands r0, r1
	cmp r0, 0
	bne _08093C86
_08093CA6:
	movs r4, 0
	movs r7, 0x1
	adds r2, r6, 0
	mov r5, sp
	movs r3, 0x7
_08093CB0:
	ldrb r1, [r2]
	adds r0, r7, 0
	ands r0, r1
	cmp r0, 0
	beq _08093CC2
	ldr r0, [r2]
	ldr r1, [r2, 0x4]
	stm r5!, {r0,r1}
	adds r4, 0x1
_08093CC2:
	adds r2, 0x8
	subs r3, 0x1
	cmp r3, 0
	bge _08093CB0
	cmp r4, 0x7
	bgt _08093CDE
	movs r1, 0
	lsls r0, r4, 3
	add r0, sp
_08093CD4:
	strb r1, [r0]
	adds r0, 0x8
	adds r4, 0x1
	cmp r4, 0x7
	ble _08093CD4
_08093CDE:
	mov r4, sp
	adds r2, r6, 0
	movs r3, 0x7
_08093CE4:
	ldm r4!, {r0,r1}
	stm r2!, {r0,r1}
	subs r3, 0x1
	cmp r3, 0
	bge _08093CE4
	add sp, 0x40
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_8093C54

	thumb_func_start sub_8093CF8
sub_8093CF8:
	push {r4-r7,lr}
	sub sp, 0x40
	adds r6, r0, 0
	lsls r0, r1, 3
	adds r0, r6
	movs r2, 0
	strb r2, [r0]
	adds r3, r1, 0x1
	cmp r3, 0x7
	bgt _08093D4A
	lsls r0, r3, 3
	adds r4, r6, r0
	ldrb r1, [r4]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _08093D4A
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	beq _08093D4A
	mov r12, r2
	movs r7, 0x1
	adds r2, r4, 0
	movs r5, 0x2
_08093D2A:
	mov r0, r12
	strb r0, [r4]
	adds r2, 0x8
	adds r3, 0x1
	cmp r3, 0x7
	bgt _08093D4A
	adds r4, r2, 0
	ldrb r1, [r2]
	adds r0, r7, 0
	ands r0, r1
	cmp r0, 0
	beq _08093D4A
	adds r0, r5, 0
	ands r0, r1
	cmp r0, 0
	bne _08093D2A
_08093D4A:
	movs r4, 0
	movs r7, 0x1
	adds r2, r6, 0
	mov r5, sp
	movs r3, 0x7
_08093D54:
	ldrb r1, [r2]
	adds r0, r7, 0
	ands r0, r1
	cmp r0, 0
	beq _08093D66
	ldr r0, [r2]
	ldr r1, [r2, 0x4]
	stm r5!, {r0,r1}
	adds r4, 0x1
_08093D66:
	adds r2, 0x8
	subs r3, 0x1
	cmp r3, 0
	bge _08093D54
	cmp r4, 0x7
	bgt _08093D82
	movs r1, 0
	lsls r0, r4, 3
	add r0, sp
_08093D78:
	strb r1, [r0]
	adds r0, 0x8
	adds r4, 0x1
	cmp r4, 0x7
	ble _08093D78
_08093D82:
	mov r4, sp
	adds r2, r6, 0
	movs r3, 0x7
_08093D88:
	ldm r4!, {r0,r1}
	stm r2!, {r0,r1}
	subs r3, 0x1
	cmp r3, 0
	bge _08093D88
	add sp, 0x40
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_8093CF8

	thumb_func_start sub_8093D9C
sub_8093D9C:
	push {r4-r6,lr}
	sub sp, 0x8
	adds r4, r0, 0
	adds r5, r2, 0
	adds r6, r3, 0
	lsls r1, 16
	lsrs r1, 16
	mov r0, sp
	bl sub_8092A88
	adds r0, r4, 0
	mov r1, sp
	adds r2, r5, 0
	adds r3, r6, 0
	bl sub_8093DE8
	add sp, 0x8
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end sub_8093D9C

	thumb_func_start sub_8093DC4
sub_8093DC4:
	push {r4-r6,lr}
	sub sp, 0x8
	adds r4, r0, 0
	adds r5, r2, 0
	adds r6, r3, 0
	mov r0, sp
	bl sub_8093F10
	adds r0, r4, 0
	mov r1, sp
	adds r2, r5, 0
	adds r3, r6, 0
	bl sub_8093DE8
	add sp, 0x8
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end sub_8093DC4

	thumb_func_start sub_8093DE8
sub_8093DE8:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	ldr r4, _08093E80
	add sp, r4
	adds r4, r0, 0
	adds r6, r1, 0
	adds r5, r2, 0
	mov r8, r3
	adds r0, r5, 0
	bl sub_80073B8
	ldr r0, _08093E84
	adds r1, r6, 0
	movs r2, 0
	bl sub_80928C0
	lsls r4, 3
	adds r4, 0x10
	ldr r2, _08093E88
	movs r7, 0
	str r7, [sp]
	adds r0, r4, 0
	movs r1, 0
	adds r3, r5, 0
	bl xxx_format_and_draw
	movs r3, 0x13
	ldrh r1, [r6, 0x2]
	ldr r4, _08093E8C
	ldr r2, [r4]
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldr r2, [r0, 0x1C]
	ldrb r0, [r2]
	cmp r0, 0x2A
	bne _08093E3A
	movs r3, 0x10
	adds r2, 0x1
_08093E3A:
	str r7, [sp]
	movs r0, 0x4
	adds r1, r3, 0
	adds r3, r5, 0
	bl xxx_format_and_draw
	adds r0, r6, 0
	adds r1, r5, 0
	bl sub_8093E90
	adds r0, r5, 0
	bl sub_80073E0
	ldrh r1, [r6, 0x2]
	ldr r2, [r4]
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldr r1, [r0, 0x1C]
	add r0, sp, 0x4
	bl strcpy
	add r0, sp, 0x4
	mov r1, r8
	bl sub_8097DF0
	movs r3, 0xC9
	lsls r3, 2
	add sp, r3
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r1}
	bx r1
	.align 2, 0
_08093E80: .4byte 0xfffffcdc
_08093E84: .4byte gAvailablePokemonNames
_08093E88: .4byte gUnknown_8109930
_08093E8C: .4byte gMovesData
	thumb_func_end sub_8093DE8

	thumb_func_start sub_8093E90
sub_8093E90:
	push {r4-r6,lr}
	sub sp, 0x4
	adds r6, r0, 0
	adds r5, r1, 0
	movs r0, 0x7
	str r0, [sp]
	adds r0, r5, 0
	movs r1, 0x4
	movs r2, 0x48
	movs r3, 0xC8
	bl sub_80078A4
	ldr r0, _08093F00
	adds r1, r6, 0
	bl sub_8092D54
	ldr r0, _08093F04
	ldr r2, [r0]
	movs r4, 0
	str r4, [sp]
	movs r0, 0x4
	movs r1, 0x4A
	adds r3, r5, 0
	bl xxx_format_and_draw
	ldr r0, _08093F08
	ldr r2, [r0]
	str r4, [sp]
	movs r0, 0x4
	movs r1, 0x56
	adds r3, r5, 0
	bl xxx_format_and_draw
	adds r0, r6, 0
	bl sub_8092B00
	lsls r0, 24
	lsrs r0, 24
	bl GetUnformattedTypeString 
	adds r2, r0, 0
	str r4, [sp]
	movs r0, 0x40
	movs r1, 0x56
	adds r3, r5, 0
	bl xxx_format_and_draw
	adds r0, r6, 0
	bl sub_8092BC0
	ldr r1, _08093F0C
	str r0, [r1]
	add sp, 0x4
	pop {r4-r6}
	pop {r0}
	bx r0
	.align 2, 0
_08093F00: .4byte gAvailablePokemonNames
_08093F04: .4byte gUnknown_810CF00
_08093F08: .4byte gPtrTypeText
_08093F0C: .4byte gUnknown_202DE30
	thumb_func_end sub_8093E90

	thumb_func_start sub_8093F10
sub_8093F10:
	push {r4,lr}
	adds r3, r0, 0
	adds r4, r1, 0
	ldrb r1, [r4]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _08093F48
	movs r0, 0
	strb r1, [r3]
	strb r0, [r3, 0x1]
	ldrh r0, [r4, 0x2]
	strh r0, [r3, 0x2]
	ldrh r1, [r4, 0x2]
	ldr r0, _08093F44
	ldr r2, [r0]
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldrb r0, [r0, 0xC]
	strb r0, [r3, 0x4]
	ldrb r0, [r4, 0x4]
	strb r0, [r3, 0x5]
	b _08093F4A
	.align 2, 0
_08093F44: .4byte gMovesData
_08093F48:
	strb r0, [r3]
_08093F4A:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_8093F10

	thumb_func_start sub_8093F50
sub_8093F50:
	push {r4-r7,lr}
	adds r6, r0, 0
	movs r7, 0
	adds r3, r6, 0
	adds r4, r1, 0
	movs r5, 0x3
_08093F5C:
	ldrb r1, [r4]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _08093F8C
	strb r1, [r3]
	strb r7, [r3, 0x1]
	ldrh r0, [r4, 0x2]
	strh r0, [r3, 0x2]
	ldrh r1, [r4, 0x2]
	ldr r0, _08093F88
	ldr r2, [r0]
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldrb r0, [r0, 0xC]
	strb r0, [r3, 0x4]
	ldrb r0, [r4, 0x4]
	strb r0, [r3, 0x5]
	b _08093F8E
	.align 2, 0
_08093F88: .4byte gMovesData
_08093F8C:
	strb r0, [r3]
_08093F8E:
	adds r3, 0x8
	adds r4, 0x8
	subs r5, 0x1
	cmp r5, 0
	bge _08093F5C
	adds r1, r6, 0
	adds r1, 0x20
	movs r0, 0
	strb r0, [r1]
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_8093F50

	thumb_func_start sub_8093FA8
sub_8093FA8:
	push {lr}
	adds r2, r0, 0
	movs r3, 0x3
_08093FAE:
	ldrb r0, [r1]
	strb r0, [r2]
	ldrh r0, [r1, 0x2]
	strh r0, [r2, 0x2]
	ldrb r0, [r1, 0x5]
	strb r0, [r2, 0x4]
	adds r2, 0x8
	adds r1, 0x8
	subs r3, 0x1
	cmp r3, 0
	bge _08093FAE
	pop {r0}
	bx r0
	thumb_func_end sub_8093FA8

	thumb_func_start sub_8093FC8
sub_8093FC8:
	push {r4-r7,lr}
	adds r5, r0, 0
	adds r2, r1, 0
	movs r3, 0
	ldrb r1, [r2]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _08094002
	movs r7, 0xFB
	movs r6, 0x1
	adds r4, r2, 0
	adds r2, r5, 0
_08093FE2:
	ldm r4!, {r0,r1}
	str r0, [r2]
	str r1, [r2, 0x4]
	ldrb r1, [r2, 0x1]
	adds r0, r7, 0
	ands r0, r1
	strb r0, [r2, 0x1]
	adds r2, 0x8
	adds r3, 0x1
	cmp r3, 0x3
	bgt _08094002
	ldrb r1, [r4]
	adds r0, r6, 0
	ands r0, r1
	cmp r0, 0
	bne _08093FE2
_08094002:
	cmp r3, 0x7
	bgt _08094016
	movs r1, 0
	lsls r0, r3, 3
	adds r0, r5
_0809400C:
	strb r1, [r0]
	adds r0, 0x8
	adds r3, 0x1
	cmp r3, 0x7
	ble _0809400C
_08094016:
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_8093FC8

	thumb_func_start sub_809401C
sub_809401C:
	push {r4-r6,lr}
	adds r5, r0, 0
	adds r3, r1, 0
	movs r2, 0
	ldrb r1, [r3]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _08094046
	movs r6, 0x1
	adds r4, r5, 0
_08094032:
	ldm r3!, {r0,r1}
	stm r4!, {r0,r1}
	adds r2, 0x1
	cmp r2, 0x3
	bgt _08094046
	ldrb r1, [r3]
	adds r0, r6, 0
	ands r0, r1
	cmp r0, 0
	bne _08094032
_08094046:
	cmp r2, 0x7
	bgt _0809405A
	movs r1, 0
	lsls r0, r2, 3
	adds r0, r5
_08094050:
	strb r1, [r0]
	adds r0, 0x8
	adds r2, 0x1
	cmp r2, 0x7
	ble _08094050
_0809405A:
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end sub_809401C

	thumb_func_start sub_8094060
sub_8094060:
	push {r4-r7,lr}
	adds r6, r0, 0
	adds r7, r1, 0
	movs r4, 0
	movs r5, 0
	adds r3, r6, 0
	ldrb r1, [r3]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _08094084
_08094076:
	lsls r2, r4, 3
	adds r2, r7, r2
	ldr r0, [r3]
	ldr r1, [r3, 0x4]
	str r0, [r2]
	str r1, [r2, 0x4]
	adds r4, 0x1
_08094084:
	adds r5, 0x1
	cmp r5, 0x7
	bgt _0809409C
	lsls r0, r5, 3
	adds r3, r6, r0
	ldrb r1, [r3]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _08094084
	cmp r4, 0x3
	ble _08094076
_0809409C:
	cmp r4, 0x3
	bgt _080940B0
	movs r1, 0
	lsls r0, r4, 3
	adds r0, r7
_080940A6:
	strb r1, [r0]
	adds r0, 0x8
	adds r4, 0x1
	cmp r4, 0x3
	ble _080940A6
_080940B0:
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_8094060

	thumb_func_start sub_80940B8
sub_80940B8:
	push {r4,r5,lr}
	adds r4, r0, 0
	adds r5, r1, 0
	movs r2, 0x4
	bl SaveIntegerBits
	adds r1, r5, 0x2
	adds r0, r4, 0
	movs r2, 0x9
	bl SaveIntegerBits
	adds r5, 0x4
	adds r0, r4, 0
	adds r1, r5, 0
	movs r2, 0x7
	bl SaveIntegerBits
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_80940B8

	thumb_func_start sub_80940E0
sub_80940E0:
	push {r4,r5,lr}
	adds r4, r0, 0
	adds r5, r1, 0
	movs r2, 0x4
	bl RestoreIntegerBits
	adds r1, r5, 0x2
	adds r0, r4, 0
	movs r2, 0x9
	bl RestoreIntegerBits
	adds r5, 0x4
	adds r0, r4, 0
	adds r1, r5, 0
	movs r2, 0x7
	bl RestoreIntegerBits
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_80940E0

	thumb_func_start SavePokemonMoves
SavePokemonMoves:
	push {r4-r6,lr}
	adds r6, r0, 0
	adds r4, r1, 0
	movs r5, 0x3
_08094110:
	adds r0, r6, 0
	adds r1, r4, 0
	bl sub_80940B8
	adds r4, 0x8
	subs r5, 0x1
	cmp r5, 0
	bge _08094110
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end SavePokemonMoves

	thumb_func_start RestorePokemonMoves
RestorePokemonMoves:
	push {r4-r6,lr}
	adds r6, r0, 0
	adds r4, r1, 0
	movs r5, 0x3
_08094130:
	adds r0, r6, 0
	adds r1, r4, 0
	bl sub_80940E0
	adds r4, 0x8
	subs r5, 0x1
	cmp r5, 0
	bge _08094130
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end RestorePokemonMoves

	thumb_func_start sub_8094148
sub_8094148:
	push {r4,r5,lr}
	adds r5, r0, 0
	adds r4, r1, 0
	movs r2, 0x4
	bl SaveIntegerBits
	adds r1, r4, 0x1
	adds r0, r5, 0
	movs r2, 0x1
	bl SaveIntegerBits
	adds r1, r4, 0x2
	adds r0, r5, 0
	movs r2, 0x9
	bl SaveIntegerBits
	adds r1, r4, 0x4
	adds r0, r5, 0
	movs r2, 0x7
	bl SaveIntegerBits
	adds r4, 0x5
	adds r0, r5, 0
	adds r1, r4, 0
	movs r2, 0x7
	bl SaveIntegerBits
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_8094148

	thumb_func_start sub_8094184
sub_8094184:
	push {r4-r7,lr}
	adds r6, r0, 0
	adds r7, r1, 0
	adds r4, r7, 0
	movs r5, 0x3
_0809418E:
	adds r0, r6, 0
	adds r1, r4, 0
	bl sub_8094148
	adds r4, 0x8
	subs r5, 0x1
	cmp r5, 0
	bge _0809418E
	adds r1, r7, 0
	adds r1, 0x20
	adds r0, r6, 0
	movs r2, 0x8
	bl SaveIntegerBits
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_8094184

	thumb_func_start sub_80941B0
sub_80941B0:
	push {r4,r5,lr}
	adds r5, r0, 0
	adds r4, r1, 0
	adds r0, r4, 0
	movs r1, 0
	movs r2, 0x8
	bl memset
	adds r0, r5, 0
	adds r1, r4, 0
	movs r2, 0x4
	bl RestoreIntegerBits
	adds r1, r4, 0x1
	adds r0, r5, 0
	movs r2, 0x1
	bl RestoreIntegerBits
	adds r1, r4, 0x2
	adds r0, r5, 0
	movs r2, 0x9
	bl RestoreIntegerBits
	adds r1, r4, 0x4
	adds r0, r5, 0
	movs r2, 0x7
	bl RestoreIntegerBits
	adds r4, 0x5
	adds r0, r5, 0
	adds r1, r4, 0
	movs r2, 0x7
	bl RestoreIntegerBits
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_80941B0

	thumb_func_start sub_80941FC
sub_80941FC:
	push {r4-r7,lr}
	adds r6, r0, 0
	adds r7, r1, 0
	adds r4, r7, 0
	movs r5, 0x3
_08094206:
	adds r0, r6, 0
	adds r1, r4, 0
	bl sub_80941B0
	adds r4, 0x8
	subs r5, 0x1
	cmp r5, 0
	bge _08094206
	adds r1, r7, 0
	adds r1, 0x20
	movs r0, 0
	strb r0, [r1]
	adds r0, r6, 0
	movs r2, 0x8
	bl RestoreIntegerBits
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_80941FC

	thumb_func_start sub_809422C
sub_809422C:
	push {lr}
	lsls r0, 16
	lsrs r1, r0, 16
	adds r2, r1, 0
	cmp r1, 0x97
	beq _08094260
	cmp r1, 0x64
	beq _08094260
	cmp r1, 0x3C
	beq _08094260
	cmp r1, 0x4B
	beq _08094260
	movs r0, 0xAE
	lsls r0, 1
	cmp r1, r0
	beq _08094260
	cmp r1, 0x99
	beq _08094260
	cmp r1, 0xCD
	beq _08094260
	cmp r1, 0x9C
	beq _08094260
	cmp r2, 0x8
	beq _08094260
	movs r0, 0
	b _08094262
_08094260:
	movs r0, 0x1
_08094262:
	pop {r1}
	bx r1
	thumb_func_end sub_809422C

	thumb_func_start sub_8094268
sub_8094268:
	push {r4-r6,lr}
	adds r5, r0, 0
	adds r3, r1, 0
	asrs r0, r3, 16
	asrs r1, r2, 16
	adds r0, r1
	lsls r0, 16
	ldr r6, _080942B0
	ands r3, r6
	orrs r3, r0
	adds r2, r3, r2
	lsls r2, 16
	lsrs r2, 16
	ldr r4, _080942B4
	ands r3, r4
	orrs r3, r2
	asrs r1, r3, 16
	ldr r0, _080942B8
	cmp r1, r0
	ble _080942A6
	adds r0, r3, 0x1
	lsls r0, 16
	lsrs r0, 16
	ands r3, r4
	orrs r3, r0
	asrs r0, r3, 16
	ldr r1, _080942BC
	adds r0, r1
	lsls r0, 16
	ands r3, r6
	orrs r3, r0
_080942A6:
	str r3, [r5]
	adds r0, r5, 0
	pop {r4-r6}
	pop {r1}
	bx r1
	.align 2, 0
_080942B0: .4byte 0x0000ffff
_080942B4: .4byte 0xffff0000
_080942B8: .4byte 0x000003e7
_080942BC: .4byte 0xfffffc18
	thumb_func_end sub_8094268

	thumb_func_start sub_80942C0
sub_80942C0:
	push {r4,r5,lr}
	adds r5, r0, 0
	adds r3, r1, 0
	asrs r0, r3, 16
	asrs r1, r2, 16
	subs r0, r1
	lsls r0, 16
	ldr r4, _08094310
	ands r3, r4
	orrs r3, r0
	subs r2, r3, r2
	lsls r2, 16
	lsrs r2, 16
	ldr r1, _08094314
	ands r3, r1
	orrs r3, r2
	cmp r3, 0
	bge _080942FC
	subs r0, r3, 0x1
	lsls r0, 16
	lsrs r0, 16
	ands r3, r1
	orrs r3, r0
	asrs r0, r3, 16
	movs r2, 0xFA
	lsls r2, 2
	adds r0, r2
	lsls r0, 16
	ands r3, r4
	orrs r3, r0
_080942FC:
	lsls r0, r3, 16
	cmp r0, 0
	bge _08094304
	movs r3, 0
_08094304:
	str r3, [r5]
	adds r0, r5, 0
	pop {r4,r5}
	pop {r1}
	bx r1
	.align 2, 0
_08094310: .4byte 0x0000ffff
_08094314: .4byte 0xffff0000
	thumb_func_end sub_80942C0

	thumb_func_start sub_8094318
sub_8094318:
	push {r4,lr}
	adds r4, r0, 0
	adds r3, r1, 0
	lsls r0, r3, 16
	asrs r1, r0, 16
	lsls r0, r2, 16
	asrs r0, 16
	cmp r1, r0
	bgt _08094336
	cmp r1, r0
	blt _0809433A
	asrs r1, r3, 16
	asrs r0, r2, 16
	cmp r1, r0
	ble _0809433A
_08094336:
	str r2, [r4]
	b _0809433C
_0809433A:
	str r3, [r4]
_0809433C:
	adds r0, r4, 0
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_8094318

	thumb_func_start sub_8094344
sub_8094344:
	push {r4,lr}
	adds r4, r0, 0
	adds r3, r1, 0
	lsls r0, r3, 16
	asrs r1, r0, 16
	lsls r0, r2, 16
	asrs r0, 16
	cmp r1, r0
	bgt _08094362
	cmp r1, r0
	blt _08094366
	asrs r1, r3, 16
	asrs r0, r2, 16
	cmp r1, r0
	ble _08094366
_08094362:
	str r3, [r4]
	b _08094368
_08094366:
	str r2, [r4]
_08094368:
	adds r0, r4, 0
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_8094344

	thumb_func_start sub_8094370
sub_8094370:
	push {r4,r5,lr}
	adds r5, r0, 0
	lsls r1, 16
	lsls r2, 16
	ldr r4, _08094398
	lsrs r3, r1, 16
	orrs r3, r2
	asrs r2, 16
	ldr r1, _0809439C
	asrs r0, r1, 16
	cmp r2, r0
	ble _0809438C
	ands r3, r4
	orrs r3, r1
_0809438C:
	str r3, [r5]
	adds r0, r5, 0
	pop {r4,r5}
	pop {r1}
	bx r1
	.align 2, 0
_08094398: .4byte 0x0000ffff
_0809439C: .4byte 0x03e70000
	thumb_func_end sub_8094370

	thumb_func_start sub_80943A0
sub_80943A0:
	lsls r1, 16
	lsrs r2, r1, 16
	str r2, [r0]
	bx lr
	thumb_func_end sub_80943A0

	thumb_func_start sub_80943A8
sub_80943A8:
	push {r4,r5,lr}
	ldr r3, [r1, 0x4]
	lsrs r2, r3, 16
	ldr r1, _080943D4
	ands r5, r1
	orrs r5, r2
	ldr r4, _080943D8
	adds r2, r4, 0
	ands r2, r3
	lsls r1, r2, 5
	subs r1, r2
	lsls r1, 2
	adds r1, r2
	lsls r1, 3
	lsrs r1, 16
	lsls r1, 16
	ands r5, r4
	orrs r5, r1
	str r5, [r0]
	pop {r4,r5}
	pop {r1}
	bx r1
	.align 2, 0
_080943D4: .4byte 0xffff0000
_080943D8: .4byte 0x0000ffff
	thumb_func_end sub_80943A8

	thumb_func_start sub_80943DC
sub_80943DC:
	push {r4-r6,lr}
	mov r6, r8
	push {r6}
	mov r8, r0
	adds r4, r1, 0
	lsls r1, r4, 16
	asrs r1, 16
	lsls r0, r1, 5
	subs r0, r1
	lsls r0, 2
	adds r0, r1
	lsls r0, 3
	asrs r1, r4, 16
	adds r0, r1
	lsls r3, r2, 16
	asrs r3, 16
	lsls r1, r3, 5
	subs r1, r3
	lsls r1, 2
	adds r1, r3
	lsls r1, 3
	asrs r2, 16
	adds r1, r2
	muls r0, r1
	movs r5, 0xFA
	lsls r5, 2
	adds r1, r5, 0
	bl __divsi3
	adds r6, r0, 0
	adds r1, r5, 0
	bl __divsi3
	lsls r0, 16
	lsrs r0, 16
	ldr r1, _08094448
	ands r4, r1
	orrs r4, r0
	adds r0, r6, 0
	adds r1, r5, 0
	bl __modsi3
	lsls r0, 16
	ldr r1, _0809444C
	ands r1, r4
	orrs r0, r1
	mov r1, r8
	str r0, [r1]
	mov r0, r8
	pop {r3}
	mov r8, r3
	pop {r4-r6}
	pop {r1}
	bx r1
	.align 2, 0
_08094448: .4byte 0xffff0000
_0809444C: .4byte 0x0000ffff
	thumb_func_end sub_80943DC

	thumb_func_start sub_8094450
sub_8094450:
	push {lr}
	adds r1, r0, 0
	lsls r0, r1, 16
	asrs r2, r0, 16
	cmp r2, 0
	bne _0809446A
	asrs r0, r1, 16
	cmp r0, 0
	bne _08094466
	movs r0, 0
	b _08094476
_08094466:
	movs r0, 0x1
	b _08094476
_0809446A:
	asrs r0, r1, 16
	cmp r0, 0
	bne _08094474
	adds r0, r2, 0
	b _08094476
_08094474:
	adds r0, r2, 0x1
_08094476:
	pop {r1}
	bx r1
	thumb_func_end sub_8094450

	thumb_func_start sub_809447C
sub_809447C:
	push {r4,r5,lr}
	adds r5, r0, 0
	adds r4, r1, 0
	movs r2, 0x10
	bl RestoreIntegerBits
	adds r4, 0x2
	adds r0, r5, 0
	adds r1, r4, 0
	movs r2, 0x10
	bl RestoreIntegerBits
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_809447C

	thumb_func_start sub_809449C
sub_809449C:
	push {r4,r5,lr}
	adds r5, r0, 0
	adds r4, r1, 0
	movs r2, 0x10
	bl SaveIntegerBits
	adds r4, 0x2
	adds r0, r5, 0
	adds r1, r4, 0
	movs r2, 0x10
	bl SaveIntegerBits
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_809449C

	thumb_func_start sub_80944BC
sub_80944BC:
	push {r4,lr}
	sub sp, 0x8
	adds r4, r1, 0
	lsls r0, 16
	asrs r1, r0, 16
	ldr r0, _080944F4
	cmp r1, r0
	bgt _08094500
	lsls r1, 16
	lsrs r1, 16
	mov r0, sp
	bl sub_8092AA8
	ldr r0, _080944F8
	mov r1, sp
	movs r2, 0
	bl sub_80928C0
	ldr r0, _080944FC
	ldr r0, [r0]
	adds r2, r4, 0
	adds r2, 0xC8
	adds r1, r4, 0
	movs r3, 0
	bl xxx_format_string
	b _08094516
	.align 2, 0
_080944F4: .4byte 0x000001f3
_080944F8: .4byte gUnknown_202DE58
_080944FC: .4byte gUnknown_811383C
_08094500:
	ldr r0, _08094520
	ldr r2, _08094524
	adds r1, r2
	lsls r1, 3
	adds r0, 0x4
	adds r1, r0
	ldr r1, [r1]
	adds r0, r4, 0
	movs r2, 0xC8
	bl strncpy
_08094516:
	add sp, 0x8
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08094520: .4byte gUnknown_8113080
_08094524: .4byte 0xfffffe0c
	thumb_func_end sub_80944BC

	thumb_func_start sub_8094528
sub_8094528:
	push {lr}
	lsls r0, 16
	asrs r1, r0, 16
	ldr r0, _08094544
	cmp r1, r0
	ble _08094550
	ldr r0, _08094548
	ldr r2, _0809454C
	adds r1, r2
	lsls r1, 3
	adds r1, r0
	ldrb r0, [r1]
	b _08094552
	.align 2, 0
_08094544: .4byte 0x000001f3
_08094548: .4byte gUnknown_8113080
_0809454C: .4byte 0xfffffe0c
_08094550:
	movs r0, 0x1
_08094552:
	pop {r1}
	bx r1
	thumb_func_end sub_8094528

	thumb_func_start sub_8094558
sub_8094558:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0xCC
	adds r7, r0, 0
	adds r4, r1, 0
	adds r6, r2, 0
	bl sub_80073B8
	movs r5, 0
	str r5, [sp]
	movs r0, 0x10
	movs r1, 0
	adds r2, r4, 0
	adds r3, r7, 0
	bl xxx_format_and_draw
	ldr r4, _080945D0
	adds r1, r6, 0
	adds r1, 0x18
	adds r0, r4, 0
	bl sub_8090208
	ldr r0, _080945D4
	ldr r2, [r0]
	str r5, [sp]
	movs r0, 0x4
	movs r1, 0x10
	adds r3, r7, 0
	bl xxx_format_and_draw
	movs r5, 0x1A
	adds r0, r4, 0
	adds r1, r6, 0
	movs r2, 0xA
	bl sub_80922B4
	adds r4, 0x50
	adds r1, r6, 0
	adds r1, 0xA
	adds r0, r4, 0
	movs r2, 0xA
	bl sub_80922B4
	movs r1, 0x14
	ldrsh r0, [r6, r1]
	bl sub_8094528
	lsls r0, 24
	cmp r0, 0
	beq _080945DC
	ldr r0, _080945D8
	ldr r0, [r0]
	add r2, sp, 0xCC
	add r1, sp, 0x4
	movs r3, 0
	bl xxx_format_string
	b _080945EA
	.align 2, 0
_080945D0: .4byte gAvailablePokemonNames
_080945D4: .4byte gUnknown_8113850
_080945D8: .4byte gUnknown_8113868
_080945DC:
	ldr r0, _0809465C
	ldr r0, [r0]
	add r2, sp, 0xCC
	add r1, sp, 0x4
	movs r3, 0
	bl xxx_format_string
_080945EA:
	add r0, sp, 0x4
	bl sub_8008ED0
	movs r4, 0xB0
	subs r0, r4, r0
	lsrs r1, r0, 31
	adds r0, r1
	asrs r0, 1
	movs r1, 0
	mov r8, r1
	str r1, [sp]
	adds r1, r5, 0
	add r2, sp, 0x4
	adds r3, r7, 0
	bl xxx_format_and_draw
	adds r5, 0xA
	movs r1, 0x14
	ldrsh r0, [r6, r1]
	add r1, sp, 0x4
	bl sub_80944BC
	add r0, sp, 0x4
	bl sub_8008ED0
	subs r4, r0
	lsrs r0, r4, 31
	adds r4, r0
	asrs r0, r4, 1
	mov r1, r8
	str r1, [sp]
	adds r1, r5, 0
	add r2, sp, 0x4
	adds r3, r7, 0
	bl xxx_format_and_draw
	adds r5, 0x10
	ldr r1, _08094660
	ldr r0, [r6, 0x20]
	str r0, [r1]
	adds r0, r6, 0
	adds r0, 0x2A
	ldrb r0, [r0]
	str r0, [r1, 0x4]
	cmp r0, 0x63
	ble _08094668
	ldr r0, _08094664
	ldr r2, [r0]
	mov r0, r8
	str r0, [sp]
	movs r0, 0x4
	adds r1, r5, 0
	adds r3, r7, 0
	bl xxx_format_and_draw
	b _0809467A
	.align 2, 0
_0809465C: .4byte gUnknown_8113870
_08094660: .4byte gUnknown_202DE30
_08094664: .4byte gUnknown_81138C0
_08094668:
	ldr r0, _080946CC
	ldr r2, [r0]
	mov r1, r8
	str r1, [sp]
	movs r0, 0x4
	adds r1, r5, 0
	adds r3, r7, 0
	bl xxx_format_and_draw
_0809467A:
	adds r5, 0xA
	ldr r4, _080946D0
	movs r1, 0x24
	ldrsh r0, [r6, r1]
	str r0, [r4]
	ldr r0, _080946D4
	ldr r2, [r0]
	movs r0, 0
	mov r8, r0
	str r0, [sp]
	movs r0, 0x4
	adds r1, r5, 0
	adds r3, r7, 0
	bl xxx_format_and_draw
	adds r5, 0xA
	adds r0, r6, 0
	adds r0, 0x26
	ldrb r2, [r0]
	str r2, [r4]
	adds r0, 0x2
	ldrb r0, [r0]
	str r0, [r4, 0x4]
	adds r0, r6, 0
	adds r0, 0x2B
	ldrb r1, [r0]
	cmp r1, 0
	beq _080946DC
	adds r0, r1, 0
	adds r0, r2, r0
	str r0, [r4]
	ldr r0, _080946D8
	ldr r2, [r0]
	mov r1, r8
	str r1, [sp]
	movs r0, 0x4
	adds r1, r5, 0
	adds r3, r7, 0
	bl xxx_format_and_draw
	b _080946EC
	.align 2, 0
_080946CC: .4byte gUnknown_8113898
_080946D0: .4byte gUnknown_202DE30
_080946D4: .4byte gUnknown_81138D0
_080946D8: .4byte gUnknown_8113950
_080946DC:
	ldr r0, _08094714
	ldr r2, [r0]
	str r1, [sp]
	movs r0, 0x4
	adds r1, r5, 0
	adds r3, r7, 0
	bl xxx_format_and_draw
_080946EC:
	adds r0, r6, 0
	adds r0, 0x2D
	ldrb r1, [r0]
	cmp r1, 0
	beq _08094720
	ldr r2, _08094718
	ldr r0, [r2, 0x4]
	adds r0, r1
	str r0, [r2, 0x4]
	ldr r0, _0809471C
	ldr r2, [r0]
	movs r0, 0
	str r0, [sp]
	movs r0, 0x4
	adds r1, r5, 0
	adds r3, r7, 0
	bl xxx_format_and_draw
	b _08094730
	.align 2, 0
_08094714: .4byte gUnknown_81138E4
_08094718: .4byte gUnknown_202DE30
_0809471C: .4byte gUnknown_8113974
_08094720:
	ldr r0, _08094768
	ldr r2, [r0]
	str r1, [sp]
	movs r0, 0x4
	adds r1, r5, 0
	adds r3, r7, 0
	bl xxx_format_and_draw
_08094730:
	adds r5, 0xA
	ldr r2, _0809476C
	adds r0, r6, 0
	adds r0, 0x27
	ldrb r3, [r0]
	str r3, [r2]
	adds r0, 0x2
	ldrb r0, [r0]
	str r0, [r2, 0x4]
	adds r0, r6, 0
	adds r0, 0x2C
	ldrb r1, [r0]
	cmp r1, 0
	beq _08094774
	adds r0, r1, 0
	adds r0, r3, r0
	str r0, [r2]
	ldr r0, _08094770
	ldr r2, [r0]
	movs r0, 0
	str r0, [sp]
	movs r0, 0x4
	adds r1, r5, 0
	adds r3, r7, 0
	bl xxx_format_and_draw
	b _08094784
	.align 2, 0
_08094768: .4byte gUnknown_8113900
_0809476C: .4byte gUnknown_202DE30
_08094770: .4byte gUnknown_8113990
_08094774:
	ldr r0, _080947AC
	ldr r2, [r0]
	str r1, [sp]
	movs r0, 0x4
	adds r1, r5, 0
	adds r3, r7, 0
	bl xxx_format_and_draw
_08094784:
	adds r0, r6, 0
	adds r0, 0x2E
	ldrb r1, [r0]
	cmp r1, 0
	beq _080947B8
	ldr r2, _080947B0
	ldr r0, [r2, 0x4]
	adds r0, r1
	str r0, [r2, 0x4]
	ldr r0, _080947B4
	ldr r2, [r0]
	movs r0, 0
	str r0, [sp]
	movs r0, 0x4
	adds r1, r5, 0
	adds r3, r7, 0
	bl xxx_format_and_draw
	b _080947C8
	.align 2, 0
_080947AC: .4byte gUnknown_8113918
_080947B0: .4byte gUnknown_202DE30
_080947B4: .4byte gUnknown_81139B4
_080947B8:
	ldr r0, _080947E4
	ldr r2, [r0]
	str r1, [sp]
	movs r0, 0x4
	adds r1, r5, 0
	adds r3, r7, 0
	bl xxx_format_and_draw
_080947C8:
	adds r5, 0x10
	adds r2, r6, 0
	adds r2, 0x1C
	ldrb r1, [r6, 0x1C]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _080947EC
	ldr r0, _080947E8
	adds r1, r2, 0
	movs r2, 0
	bl sub_8090E14
	b _080947F6
	.align 2, 0
_080947E4: .4byte gUnknown_8113934
_080947E8: .4byte gUnknown_202DE58
_080947EC:
	ldr r0, _0809481C
	ldr r1, _08094820
	ldr r1, [r1]
	bl strcpy
_080947F6:
	ldr r0, _08094824
	ldr r2, [r0]
	movs r0, 0
	str r0, [sp]
	movs r0, 0x4
	adds r1, r5, 0
	adds r3, r7, 0
	bl xxx_format_and_draw
	adds r0, r7, 0
	bl sub_80073E0
	add sp, 0xCC
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_0809481C: .4byte gUnknown_202DE58
_08094820: .4byte gUnknown_81139B8
_08094824: .4byte gUnknown_81139CC
	thumb_func_end sub_8094558

        .align 2,0 @ Don't pad with nop
