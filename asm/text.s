	#include "asm/constants/gba_constants.inc"
	#include "asm/macros.inc"

	.syntax unified

	.text



	thumb_func_start InitGraphics
InitGraphics:
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
	bl InitFontPalette
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
_0800979C: .4byte gSystemFileArchive
_080097A0: .4byte 0x06004f00
_080097A4: .4byte gUnknown_80B88B8
_080097A8: .4byte 0x06017e00
_080097AC: .4byte gUnknown_80B88C0
	thumb_func_end InitGraphics

	.align 2, 0 @ Don't pad with nop.
