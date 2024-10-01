	#include "asm/constants/gba_constants.inc"
	#include "asm/macros.inc"

	.syntax unified

	.text



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

@ https://decomp.me/scratch/A63Io
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

	thumb_func_start InterpretColorChar
InterpretColorChar:
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
	thumb_func_end InterpretColorChar

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
