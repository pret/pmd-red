	.include "constants/gba_constants.inc"
	.include "asm/macros.inc"

	.syntax unified

	.text

	thumb_func_start InitBGPaletteBuffer
InitBGPaletteBuffer:
	push {lr}
	movs r2, 0
	ldr r1, _0800465C
	movs r0, 0x80
	lsls r0, 2
_0800463E:
	strh r2, [r1]
	adds r1, 0x2
	subs r0, 0x1
	cmp r0, 0
	bne _0800463E
	ldr r1, _08004660
	movs r2, 0x1
	adds r0, r1, 0
	adds r0, 0x1F
_08004650:
	strb r2, [r0]
	subs r0, 0x1
	cmp r0, r1
	bge _08004650
	pop {r0}
	bx r0
	.align 2, 0
_0800465C: .4byte gUnknown_20251F0
_08004660: .4byte gUnknown_20251D0
	thumb_func_end InitBGPaletteBuffer

	thumb_func_start SetBGPaletteBufferColorRGB
SetBGPaletteBufferColorRGB:
	push {r4-r7,lr}
	adds r4, r0, 0
	adds r5, r1, 0
	cmp r2, 0
	bge _08004670
	movs r2, 0
_08004670:
	cmp r2, 0x1F
	ble _08004676
	movs r2, 0x1F
_08004676:
	ldr r1, _080046CC
	adds r0, r4, 0
	cmp r4, 0
	bge _08004680
	adds r0, 0xF
_08004680:
	asrs r0, 4
	adds r0, r1
	movs r1, 0x1
	strb r1, [r0]
	cmp r3, 0
	bne _080046D4
	ldr r0, _080046D0
	lsls r1, r4, 1
	adds r6, r1, r0
	ldrb r0, [r5, 0x2]
	muls r0, r2
	cmp r0, 0
	bge _0800469C
	adds r0, 0xFF
_0800469C:
	asrs r0, 8
	movs r3, 0x1F
	ands r0, r3
	lsls r4, r0, 10
	ldrb r0, [r5, 0x1]
	muls r0, r2
	cmp r0, 0
	bge _080046AE
	adds r0, 0xFF
_080046AE:
	asrs r0, 8
	ands r0, r3
	lsls r1, r0, 5
	orrs r1, r4
	ldrb r0, [r5]
	muls r0, r2
	cmp r0, 0
	bge _080046C0
	adds r0, 0xFF
_080046C0:
	asrs r0, 8
	ands r0, r3
	orrs r1, r0
	strh r1, [r6]
	b _08004722
	.align 2, 0
_080046CC: .4byte gUnknown_20251D0
_080046D0: .4byte gUnknown_20251F0
_080046D4:
	ldr r1, _08004728
	lsls r0, r4, 1
	adds r7, r0, r1
	ldrb r0, [r5, 0x2]
	lsls r0, 2
	adds r0, r3
	ldrb r0, [r0, 0x2]
	muls r0, r2
	cmp r0, 0
	bge _080046EA
	adds r0, 0xFF
_080046EA:
	asrs r0, 8
	movs r4, 0x1F
	ands r0, r4
	lsls r6, r0, 10
	ldrb r0, [r5, 0x1]
	lsls r0, 2
	adds r0, r3
	ldrb r0, [r0, 0x1]
	muls r0, r2
	cmp r0, 0
	bge _08004702
	adds r0, 0xFF
_08004702:
	asrs r0, 8
	ands r0, r4
	lsls r1, r0, 5
	orrs r1, r6
	ldrb r0, [r5]
	lsls r0, 2
	adds r0, r3
	ldrb r0, [r0]
	muls r0, r2
	cmp r0, 0
	bge _0800471A
	adds r0, 0xFF
_0800471A:
	asrs r0, 8
	ands r0, r4
	orrs r1, r0
	strh r1, [r7]
_08004722:
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_08004728: .4byte gUnknown_20251F0
	thumb_func_end SetBGPaletteBufferColorRGB

	thumb_func_start SetBGPaletteBufferColorArray
SetBGPaletteBufferColorArray:
	push {lr}
	adds r2, r0, 0
	adds r3, r1, 0
	ldr r1, _08004764
	cmp r2, 0
	bge _0800473A
	adds r0, 0xF
_0800473A:
	asrs r0, 4
	adds r0, r1
	movs r1, 0x1
	strb r1, [r0]
	ldr r0, _08004768
	lsls r2, 1
	adds r2, r0
	ldrb r1, [r3, 0x2]
	lsrs r1, 3
	lsls r1, 10
	ldrb r0, [r3, 0x1]
	lsrs r0, 3
	lsls r0, 5
	orrs r1, r0
	ldrb r0, [r3]
	lsrs r0, 3
	orrs r0, r1
	strh r0, [r2]
	pop {r0}
	bx r0
	.align 2, 0
_08004764: .4byte gUnknown_20251D0
_08004768: .4byte gUnknown_20251F0
	thumb_func_end SetBGPaletteBufferColorArray

	thumb_func_start SetBGPaletteBufferColor
SetBGPaletteBufferColor:
	push {lr}
	adds r2, r0, 0
	adds r3, r1, 0
	ldr r1, _08004790
	cmp r2, 0
	bge _0800477A
	adds r0, 0xF
_0800477A:
	asrs r0, 4
	adds r0, r1
	movs r1, 0x1
	strb r1, [r0]
	ldr r1, _08004794
	lsls r0, r2, 1
	adds r0, r1
	ldrh r1, [r3]
	strh r1, [r0]
	pop {r0}
	bx r0
	.align 2, 0
_08004790: .4byte gUnknown_20251D0
_08004794: .4byte gUnknown_20251F0
	thumb_func_end SetBGPaletteBufferColor

	thumb_func_start nullsub_4
nullsub_4:
	bx lr
	thumb_func_end nullsub_4

	thumb_func_start nullsub_5
nullsub_5:
	bx lr
	thumb_func_end nullsub_5

	thumb_func_start nullsub_143
nullsub_143:
	bx lr
	thumb_func_end nullsub_143

	thumb_func_start TransferBGPaletteBuffer
TransferBGPaletteBuffer:
	push {r4-r6,lr}
	movs r6, 0
	movs r4, 0
	movs r5, 0xA0
	lsls r5, 19
_080047AE:
	ldr r0, _080047DC
	adds r1, r6, r0
	ldrb r0, [r1]
	cmp r0, 0
	beq _080047CA
	movs r0, 0
	strb r0, [r1]
	lsls r1, r4, 1
	ldr r0, _080047E0
	adds r1, r0
	adds r0, r5, 0
	movs r2, 0x20
	bl CpuCopy
_080047CA:
	adds r6, 0x1
	adds r5, 0x20
	adds r4, 0x10
	ldr r0, _080047E4
	cmp r4, r0
	ble _080047AE
	pop {r4-r6}
	pop {r0}
	bx r0
	.align 2, 0
_080047DC: .4byte gUnknown_20251D0
_080047E0: .4byte gUnknown_20251F0
_080047E4: .4byte 0x000001ff
	thumb_func_end TransferBGPaletteBuffer

	.align 2, 0 @ Don't pad with nop.
