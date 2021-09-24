        .include "constants/gba_constants.inc"
	.include "asm/macros.inc"

	.syntax unified

	.text

	thumb_func_start CreatePelipperBoardMenu
CreatePelipperBoardMenu:
	push {r4-r7,lr}
	ldr r4, _0802EBDC
	ldr r0, [r4]
	adds r0, 0xFC
	movs r1, 0
	movs r2, 0x10
	bl MemoryFill16
	ldr r1, [r4]
	adds r2, r1, 0
	adds r2, 0xBC
	ldr r0, _0802EBE0
	str r0, [r2]
	adds r1, 0xC0
	movs r0, 0x2
	str r0, [r1]
	bl sub_802C4A4
	lsls r0, 24
	cmp r0, 0
	beq _0802EB66
	ldr r0, [r4]
	adds r0, 0xFC
	movs r1, 0x1
	strh r1, [r0]
_0802EB66:
	movs r5, 0x1
	ldr r1, [r4]
	adds r2, r1, 0
	adds r2, 0xC4
	ldr r0, _0802EBE4
	str r0, [r2]
	adds r1, 0xC8
	movs r0, 0x3
	str r0, [r1]
	bl HasNoAcceptedJobs
	lsls r0, 24
	cmp r0, 0
	beq _0802EB88
	ldr r0, [r4]
	adds r0, 0xFE
	strh r5, [r0]
_0802EB88:
	movs r5, 0x2
	ldr r2, [r4]
	adds r1, r2, 0
	adds r1, 0xCC
	movs r0, 0
	str r0, [r1]
	adds r1, 0x4
	movs r0, 0x1
	str r0, [r1]
	movs r3, 0
	adds r6, r4, 0
	mov r12, r2
	mov r4, r12
	adds r4, 0xFC
	adds r2, 0xC0
_0802EBA6:
	ldrh r0, [r4]
	cmp r0, 0
	bne _0802EBB6
	ldr r1, [r2]
	mov r7, r12
	ldr r0, [r7, 0x64]
	cmp r1, r0
	beq _0802EC0A
_0802EBB6:
	adds r4, 0x2
	adds r2, 0x8
	adds r3, 0x1
	cmp r3, r5
	blt _0802EBA6
	movs r3, 0
	cmp r3, r5
	bge _0802EC0A
	ldr r1, [r6]
	adds r0, r1, 0
	adds r0, 0xFC
	ldrh r0, [r0]
	cmp r0, 0
	bne _0802EBE8
	adds r0, r1, 0
	adds r0, 0xC0
	ldr r0, [r0]
	str r0, [r1, 0x64]
	b _0802EC0A
	.align 2, 0
_0802EBDC: .4byte gUnknown_203B308
_0802EBE0: .4byte gPelipperBoard_BulletinBoard
_0802EBE4: .4byte gPelipperBoard_JobList
_0802EBE8:
	adds r3, 0x1
	cmp r3, r5
	bge _0802EC0A
	ldr r2, [r6]
	lsls r0, r3, 1
	adds r1, r2, 0
	adds r1, 0xFC
	adds r1, r0
	ldrh r0, [r1]
	cmp r0, 0
	bne _0802EBE8
	lsls r0, r3, 3
	adds r1, r2, 0
	adds r1, 0xC0
	adds r1, r0
	ldr r0, [r1]
	str r0, [r2, 0x64]
_0802EC0A:
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end CreatePelipperBoardMenu

	thumb_func_start sub_802EC10
sub_802EC10:
	push {r4-r7,lr}
	movs r6, 0
	ldr r4, _0802ECA8
	ldr r2, [r4]
	adds r1, r2, 0
	adds r1, 0xBC
	ldr r0, _0802ECAC
	ldr r0, [r0]
	str r0, [r1]
	adds r1, 0x4
	movs r0, 0x4
	str r0, [r1]
	ldrb r0, [r2, 0x8]
	bl sub_8096574
	bl sub_80968B0
	lsls r0, 24
	cmp r0, 0
	bne _0802EC40
	bl sub_80969AC
	cmp r0, 0x7
	ble _0802EC4A
_0802EC40:
	ldr r0, [r4]
	adds r0, 0xC0
	movs r1, 0x1
	negs r1, r1
	str r1, [r0]
_0802EC4A:
	adds r6, 0x1
	ldr r4, _0802ECA8
	ldr r5, [r4]
	lsls r1, r6, 3
	adds r2, r5, 0
	adds r2, 0xBC
	adds r3, r2, r1
	ldr r0, _0802ECB0
	ldr r0, [r0]
	str r0, [r3]
	adds r3, r5, 0
	adds r3, 0xC0
	adds r1, r3, r1
	movs r0, 0x5
	str r0, [r1]
	adds r6, 0x1
	lsls r1, r6, 3
	adds r2, r1
	movs r0, 0
	str r0, [r2]
	adds r1, r3, r1
	movs r0, 0x1
	str r0, [r1]
	movs r2, 0
	adds r7, r4, 0
	cmp r2, r6
	bge _0802EC9C
	adds r4, r5, 0
	movs r5, 0x1
	negs r5, r5
	adds r1, r3, 0
_0802EC88:
	ldr r3, [r1]
	cmp r3, r5
	beq _0802EC94
	ldr r0, [r4, 0x68]
	cmp r3, r0
	beq _0802ECA2
_0802EC94:
	adds r1, 0x8
	adds r2, 0x1
	cmp r2, r6
	blt _0802EC88
_0802EC9C:
	ldr r1, [r7]
	movs r0, 0x5
	str r0, [r1, 0x68]
_0802ECA2:
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_0802ECA8: .4byte gUnknown_203B308
_0802ECAC: .4byte gUnknown_80D4990
_0802ECB0: .4byte gUnknown_80D4970
	thumb_func_end sub_802EC10

	thumb_func_start sub_802ECB4
sub_802ECB4:
	push {r4,lr}
	sub sp, 0x4
	movs r0, 0
	str r0, [sp]
	ldr r4, _0802ECF0
	ldr r0, [r4]
	adds r0, 0x6C
	bl sub_8012FD8
	lsls r0, 24
	cmp r0, 0
	bne _0802ECE0
	ldr r0, [r4]
	adds r0, 0x6C
	mov r1, sp
	bl sub_8013114
	ldr r1, [sp]
	cmp r1, 0x1
	beq _0802ECE0
	ldr r0, [r4]
	str r1, [r0, 0x64]
_0802ECE0:
	ldr r0, [sp]
	cmp r0, 0x2
	beq _0802ECFE
	cmp r0, 0x2
	bgt _0802ECF4
	cmp r0, 0x1
	beq _0802ED3C
	b _0802ED42
	.align 2, 0
_0802ECF0: .4byte gUnknown_203B308
_0802ECF4:
	cmp r0, 0x3
	beq _0802ED10
	cmp r0, 0x5
	beq _0802ED34
	b _0802ED42
_0802ECFE:
	bl sub_802C4A4
	lsls r0, 24
	cmp r0, 0
	bne _0802ED22
	movs r0, 0x4
	bl SetPelipperBoardState
	b _0802ED42
_0802ED10:
	bl HasNoAcceptedJobs
	lsls r0, 24
	cmp r0, 0
	bne _0802ED22
	movs r0, 0x8
	bl SetPelipperBoardState
	b _0802ED42
_0802ED22:
	ldr r0, _0802ED30
	ldr r0, [r0]
	adds r0, 0x6C
	movs r1, 0x1
	bl sub_8012EA4
	b _0802ED42
	.align 2, 0
_0802ED30: .4byte gUnknown_203B308
_0802ED34:
	movs r0, 0x2
	bl SetPelipperBoardState
	b _0802ED42
_0802ED3C:
	movs r0, 0x3
	bl SetPelipperBoardState
_0802ED42:
	add sp, 0x4
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_802ECB4

	thumb_func_start sub_802ED4C
sub_802ED4C:
	push {lr}
	movs r0, 0x1
	bl sub_802C1E4
	cmp r0, 0x4
	bhi _0802EDB6
	lsls r0, 2
	ldr r1, _0802ED64
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0802ED64: .4byte _0802ED68
	.align 2, 0
_0802ED68:
	.4byte _0802EDB6
	.4byte _0802EDB6
	.4byte _0802EDAC
	.4byte _0802ED7C
	.4byte _0802ED94
_0802ED7C:
	bl sub_802C26C
	ldr r1, _0802ED90
	ldr r1, [r1]
	strb r0, [r1, 0x8]
	movs r0, 0x6
	bl SetPelipperBoardState
	b _0802EDB6
	.align 2, 0
_0802ED90: .4byte gUnknown_203B308
_0802ED94:
	bl sub_802C26C
	ldr r1, _0802EDA8
	ldr r1, [r1]
	strb r0, [r1, 0x8]
	movs r0, 0x7
	bl SetPelipperBoardState
	b _0802EDB6
	.align 2, 0
_0802EDA8: .4byte gUnknown_203B308
_0802EDAC:
	bl sub_802C2D4
	movs r0, 0x1
	bl SetPelipperBoardState
_0802EDB6:
	pop {r0}
	bx r0
	thumb_func_end sub_802ED4C

	thumb_func_start sub_802EDBC
sub_802EDBC:
	push {r4,lr}
	sub sp, 0x4
	movs r0, 0
	str r0, [sp]
	bl sub_802C1E4
	ldr r4, _0802EDFC
	ldr r0, [r4]
	adds r0, 0x6C
	bl sub_8012FD8
	lsls r0, 24
	cmp r0, 0
	bne _0802EDEC
	ldr r0, [r4]
	adds r0, 0x6C
	mov r1, sp
	bl sub_8013114
	ldr r1, [sp]
	cmp r1, 0x1
	beq _0802EDEC
	ldr r0, [r4]
	str r1, [r0, 0x68]
_0802EDEC:
	ldr r0, [sp]
	cmp r0, 0x4
	beq _0802EE06
	cmp r0, 0x4
	bgt _0802EE00
	cmp r0, 0x1
	beq _0802EE90
	b _0802EE96
	.align 2, 0
_0802EDFC: .4byte gUnknown_203B308
_0802EE00:
	cmp r0, 0x5
	beq _0802EE88
	b _0802EE96
_0802EE06:
	ldr r0, _0802EE28
	bl PlaySound
	ldr r4, _0802EE2C
	ldr r0, [r4]
	ldrb r0, [r0, 0x8]
	bl sub_8096574
	ldrb r1, [r0]
	cmp r1, 0x3
	beq _0802EE3C
	cmp r1, 0x3
	bgt _0802EE30
	cmp r1, 0x2
	beq _0802EE36
	b _0802EE5E
	.align 2, 0
_0802EE28: .4byte 0x00000133
_0802EE2C: .4byte gUnknown_203B308
_0802EE30:
	cmp r1, 0x4
	beq _0802EE42
	b _0802EE5E
_0802EE36:
	ldr r0, [r4]
	movs r1, 0x1
	b _0802EE46
_0802EE3C:
	ldr r0, [r4]
	movs r1, 0x2
	b _0802EE46
_0802EE42:
	ldr r0, [r4]
	movs r1, 0x3
_0802EE46:
	str r1, [r0, 0x4]
	ldrb r0, [r0, 0x8]
	bl sub_80965B8
	bl sub_80965F4
	bl sub_802C2D4
	movs r0, 0x3
	bl SetPelipperBoardState
	b _0802EE96
_0802EE5E:
	bl sub_8096A78
	bl sub_8096C80
	bl sub_8096D24
	bl sub_802C4A4
	lsls r0, 24
	cmp r0, 0
	beq _0802EE80
	bl sub_802C2D4
	movs r0, 0x1
	bl SetPelipperBoardState
	b _0802EE96
_0802EE80:
	movs r0, 0x5
	bl SetPelipperBoardState
	b _0802EE96
_0802EE88:
	movs r0, 0x7
	bl SetPelipperBoardState
	b _0802EE96
_0802EE90:
	movs r0, 0x5
	bl SetPelipperBoardState
_0802EE96:
	add sp, 0x4
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_802EDBC

        .align 2,0
