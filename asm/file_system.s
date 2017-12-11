	.include "constants/gba_constants.inc"
	.include "asm/macros.inc"

	.syntax unified

	.text

	thumb_func_start InitFileSystem
InitFileSystem:
	push {r4,lr}
	ldr r3, _0800A8EC
	ldr r4, _0800A8F0
	movs r2, 0
	ldr r0, _0800A8F4
	movs r1, 0x3F
_0800A8D0:
	str r2, [r0]
	str r2, [r0, 0x4]
	adds r0, 0x8
	subs r1, 0x1
	cmp r1, 0
	bge _0800A8D0
	movs r0, 0
	str r0, [r3]
	movs r0, 0x1
	str r0, [r4]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0800A8EC: .4byte gUnknown_203B094
_0800A8F0: .4byte gUnknown_202D2A4
_0800A8F4: .4byte gUnknown_202D2A8
	thumb_func_end InitFileSystem

	thumb_func_start sub_800A8F8
sub_800A8F8:
	ldr r1, _0800A904
	ldr r2, [r1]
	str r0, [r1]
	adds r0, r2, 0
	bx lr
	.align 2, 0
_0800A904: .4byte gUnknown_202D2A4
	thumb_func_end sub_800A8F8

	thumb_func_start OpenFile
OpenFile:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0x12C
	mov r8, r0
	adds r4, r1, 0
	ldr r1, _0800A93C
	adds r0, r4, 0
	bl strcmp
	cmp r0, 0
	beq _0800A922
	movs r0, 0x1
_0800A922:
	movs r1, 0
	lsls r0, 24
	cmp r0, 0
	bne _0800A92C
	movs r1, 0x1
_0800A92C:
	cmp r1, 0
	beq _0800A9B6
	ldr r7, [r4, 0xC]
	movs r6, 0
	ldr r0, [r4, 0x8]
	subs r5, r0, 0x1
	b _0800A94A
	.align 2, 0
_0800A93C: .4byte gUnknown_80B9B94
_0800A940:
	cmp r0, 0
	bge _0800A948
	adds r6, r4, 0x1
	b _0800A94A
_0800A948:
	adds r5, r4, 0
_0800A94A:
	cmp r6, r5
	bge _0800A968
	adds r0, r6, r5
	lsrs r1, r0, 31
	adds r0, r1
	asrs r4, r0, 1
	lsls r0, r4, 3
	adds r0, r7
	ldr r0, [r0]
	mov r1, r8
	bl strcmp
	cmp r0, 0
	bne _0800A940
	adds r6, r4, 0
_0800A968:
	lsls r0, r6, 3
	adds r6, r7, r0
	ldr r0, [r6]
	mov r1, r8
	bl strcmp
	cmp r0, 0
	beq _0800A994
	ldr r1, _0800A984
	mov r0, sp
	mov r2, r8
	bl sprintf
	b _0800A9B6
	.align 2, 0
_0800A984: .4byte gUnknown_80B9B9C
_0800A988:
	str r6, [r2]
	adds r0, r7, 0x4
	adds r0, r3, r0
	str r1, [r0]
	adds r0, r2, 0
	b _0800A9B8
_0800A994:
	ldr r0, _0800A9C4
	ldr r0, [r0]
	movs r4, 0
	ldr r5, _0800A9C8
	adds r7, r5, 0
_0800A99E:
	adds r0, 0x1
	cmp r0, 0x3F
	ble _0800A9A6
	movs r0, 0
_0800A9A6:
	lsls r3, r0, 3
	adds r2, r3, r5
	ldr r1, [r2]
	cmp r1, 0
	beq _0800A988
	adds r4, 0x1
	cmp r4, 0x3F
	ble _0800A99E
_0800A9B6:
	movs r0, 0
_0800A9B8:
	add sp, 0x12C
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r1}
	bx r1
	.align 2, 0
_0800A9C4: .4byte gUnknown_203B094
_0800A9C8: .4byte gUnknown_202D2A8
	thumb_func_end OpenFile

	thumb_func_start GetFileDataPtrFromFileEntry
GetFileDataPtrFromFileEntry:
	ldr r1, [r0]
	ldr r1, [r1, 0x4]
	str r1, [r0, 0x4]
	adds r0, r1, 0
	bx lr
	thumb_func_end GetFileDataPtrFromFileEntry

	thumb_func_start GetFileDataPtr
GetFileDataPtr:
	push {r4,lr}
	adds r4, r0, 0
	bl GetFileDataPtrFromFileEntry
	adds r0, r4, 0
	bl GetSiroPtr
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end GetFileDataPtr

	thumb_func_start OpenFileAndGetFileDataPtr
OpenFileAndGetFileDataPtr:
	push {r4,lr}
	bl OpenFile
	adds r4, r0, 0
	cmp r4, 0
	beq _0800A9FE
	movs r1, 0
	bl GetFileDataPtr
_0800A9FE:
	adds r0, r4, 0
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end OpenFileAndGetFileDataPtr

	thumb_func_start Call_OpenFileAndGetFileDataPtr
Call_OpenFileAndGetFileDataPtr:
	push {lr}
	bl OpenFileAndGetFileDataPtr
	pop {r1}
	bx r1
	thumb_func_end Call_OpenFileAndGetFileDataPtr

	thumb_func_start CloseFile
CloseFile:
	push {r4,r5,lr}
	adds r4, r0, 0
	movs r1, 0
	ldr r0, _0800AA30
	movs r3, 0
	ldr r5, _0800AA34
	adds r2, r0, 0x4
_0800AA22:
	cmp r0, r4
	bne _0800AA38
	str r3, [r0]
	str r3, [r2]
	str r1, [r5]
	b _0800AA42
	.align 2, 0
_0800AA30: .4byte gUnknown_202D2A8
_0800AA34: .4byte gUnknown_203B094
_0800AA38:
	adds r2, 0x8
	adds r0, 0x8
	adds r1, 0x1
	cmp r1, 0x3F
	ble _0800AA22
_0800AA42:
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end CloseFile

	thumb_func_start GetSiroPtr
GetSiroPtr:
	push {r4,r5,lr}
	adds r5, r0, 0
	ldr r4, [r5, 0x4]
	ldr r1, [r4]
	ldr r0, _0800AA60
	cmp r1, r0
	beq _0800AA68
	ldr r0, _0800AA64
	cmp r1, r0
	beq _0800AA6E
	adds r0, r4, 0
	b _0800AA72
	.align 2, 0
_0800AA60: .4byte 0x30524953
_0800AA64: .4byte 0x4f524953
_0800AA68:
	adds r0, r4, 0
	bl NDS_DecompressRLE
_0800AA6E:
	ldr r0, [r4, 0x4]
	str r0, [r5, 0x4]
_0800AA72:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end GetSiroPtr

	thumb_func_start UnusedGetSir0Ptr
UnusedGetSir0Ptr:
	push {r4,lr}
	adds r4, r0, 0
	ldr r1, [r4]
	ldr r0, _0800AA90
	cmp r1, r0
	bne _0800AA94
	adds r0, r4, 0
	bl NDS_DecompressRLE
	ldr r0, [r4, 0x4]
	b _0800AA96
	.align 2, 0
_0800AA90: .4byte 0x30524953
_0800AA94:
	adds r0, r4, 0
_0800AA96:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end UnusedGetSir0Ptr

	thumb_func_start NDS_DecompressRLE
NDS_DecompressRLE:
	bx lr
	thumb_func_end NDS_DecompressRLE

	.align 2, 0 @ Don't pad with nop.
