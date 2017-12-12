	.include "constants/gba_constants.inc"
	.include "asm/macros.inc"

	.syntax unified

	.text

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
