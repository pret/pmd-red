	#include "asm/constants/gba_constants.inc"
	#include "asm/macros.inc"

	.syntax unified

	.text

	thumb_func_start sub_800558C
sub_800558C:
	push {r4-r7,lr}
	sub sp, 0x4
	adds r5, r0, 0
	adds r4, r1, 0
	adds r6, r2, 0
	adds r7, r3, 0
	ldrh r0, [r5]
	lsrs r0, 15
	cmp r0, 0
	beq _08005602
	movs r1, 0x20
	ldrsh r0, [r5, r1]
	cmp r0, 0
	bge _080055AE
	adds r0, r5, 0
	bl sub_80054BC
_080055AE:
	ldrh r0, [r5]
	lsrs r0, 15
	cmp r0, 0
	beq _08005602
	ldrh r0, [r5, 0xC]
	adds r0, r4
	strh r0, [r5, 0x8]
	ldrh r0, [r5, 0xE]
	adds r0, r6
	strh r0, [r5, 0xA]
	adds r1, r5, 0
	adds r1, 0x26
	ldr r0, [sp, 0x18]
	strb r0, [r1]
	strh r7, [r5, 0x1E]
	ldr r0, [r5, 0x34]
	ldr r1, [r5, 0x38]
	adds r2, r5, 0
	adds r2, 0x8
	movs r3, 0x22
	ldrsh r4, [r5, r3]
	movs r6, 0x20
	ldrsh r3, [r5, r6]
	eors r4, r3
	negs r3, r4
	orrs r3, r4
	lsrs r3, 31
	str r3, [sp]
	ldr r3, [sp, 0x1C]
	bl sub_800533C
	ldrh r0, [r5, 0x20]
	strh r0, [r5, 0x22]
	ldrh r1, [r5]
	movs r0, 0x80
	lsls r0, 4
	ands r0, r1
	cmp r0, 0
	beq _08005602
	ldr r0, _0800560C
	ands r0, r1
	strh r0, [r5]
_08005602:
	add sp, 0x4
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_0800560C: .4byte 0x0000f7ff
	thumb_func_end sub_800558C

	thumb_func_start sub_8005610
sub_8005610:
	push {lr}
	ldr r0, [r0, 0x4]
	bl sub_800561C
	pop {r0}
	bx r0
	thumb_func_end sub_8005610

	thumb_func_start sub_800561C
sub_800561C:
	push {r4-r7,lr}
	adds r5, r0, 0
	adds r0, r1, 0
	adds r7, r2, 0
	adds r6, r3, 0
	ldr r1, [r5, 0x14]
	cmp r1, 0
	beq _0800563A
	lsls r0, 5
	ldr r2, _08005664
	adds r0, r2
	ldr r2, [r5, 0x1C]
	lsls r2, 5
	bl CpuCopy
_0800563A:
	ldr r0, [r5, 0x18]
	cmp r0, 0
	beq _0800565C
	movs r4, 0
_08005642:
	movs r1, 0xF0
	lsls r1, 1
	adds r0, r4, r1
	lsls r2, r4, 2
	ldr r1, [r5, 0x18]
	adds r1, r2
	adds r2, r7, 0
	adds r3, r6, 0
	bl SetBGPaletteBufferColorRGB
	adds r4, 0x1
	cmp r4, 0xF
	ble _08005642
_0800565C:
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_08005664: .4byte 0x06010000
	thumb_func_end sub_800561C

	thumb_func_start sub_8005668
sub_8005668:
	push {lr}
	ldr r0, [r0, 0x4]
	bl sub_8005674
	pop {r1}
	bx r1
	thumb_func_end sub_8005668

	thumb_func_start sub_8005674
sub_8005674:
	push {r4,lr}
	adds r4, r0, 0
	ldr r3, [r4, 0x14]
	cmp r3, 0
	beq _0800568E
	lsls r0, r1, 5
	ldr r1, _08005698
	adds r0, r1
	ldr r2, [r4, 0x1C]
	lsls r2, 5
	adds r1, r3, 0
	bl CpuCopy
_0800568E:
	ldr r0, [r4, 0x18]
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_08005698: .4byte 0x06010000
	thumb_func_end sub_8005674

	thumb_func_start sub_800569C
sub_800569C:
	push {r4-r6,lr}
	adds r3, r0, 0
	adds r4, r1, 0
	lsls r2, 24
	lsrs r2, 24
	movs r0, 0
	strh r0, [r3]
	strh r0, [r3, 0x2]
	ldrh r0, [r4]
	lsrs r0, 15
	cmp r0, 0
	beq _080056F8
	cmp r2, 0x3
	bhi _080056F8
	ldr r1, [r4, 0x30]
	cmp r1, 0
	beq _080056F2
	movs r5, 0x20
	ldrsh r0, [r4, r5]
	lsls r0, 4
	adds r5, r1, r0
	lsls r0, r2, 2
	adds r2, r5, r0
	movs r6, 0
	ldrsh r1, [r2, r6]
	cmp r1, 0x63
	bne _080056E0
	movs r6, 0x2
	ldrsh r1, [r2, r6]
	cmp r1, 0x63
	bne _080056E0
	strh r1, [r3]
	strh r1, [r3, 0x2]
	b _080056F8
_080056E0:
	adds r0, r5, r0
	ldrh r1, [r0]
	ldrh r2, [r4, 0xC]
	adds r1, r2
	strh r1, [r3]
	ldrh r0, [r0, 0x2]
	ldrh r4, [r4, 0xE]
	adds r0, r4
	b _080056F6
_080056F2:
	movs r0, 0x63
	strh r0, [r3]
_080056F6:
	strh r0, [r3, 0x2]
_080056F8:
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end sub_800569C

	thumb_func_start sub_8005700
sub_8005700:
	push {r4,r5,lr}
	adds r3, r0, 0
	ldrh r0, [r1]
	lsrs r0, 15
	cmp r0, 0
	beq _0800575C
	ldr r2, [r1, 0x30]
	cmp r2, 0
	beq _0800574C
	movs r4, 0x20
	ldrsh r0, [r1, r4]
	lsls r0, 4
	adds r2, r0
	adds r4, r2, 0
	adds r4, 0xC
_0800571E:
	movs r5, 0
	ldrsh r0, [r2, r5]
	cmp r0, 0x63
	bne _08005732
	movs r5, 0x2
	ldrsh r0, [r2, r5]
	cmp r0, 0x63
	bne _08005732
	strh r0, [r3]
	b _08005740
_08005732:
	ldrh r0, [r2]
	ldrh r5, [r1, 0xC]
	adds r0, r5
	strh r0, [r3]
	ldrh r0, [r2, 0x2]
	ldrh r5, [r1, 0xE]
	adds r0, r5
_08005740:
	strh r0, [r3, 0x2]
	adds r3, 0x4
	adds r2, 0x4
	cmp r2, r4
	ble _0800571E
	b _0800575C
_0800574C:
	movs r1, 0x63
	movs r0, 0x3
_08005750:
	strh r1, [r3]
	strh r1, [r3, 0x2]
	adds r3, 0x4
	subs r0, 0x1
	cmp r0, 0
	bge _08005750
_0800575C:
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_8005700

	.align 2, 0 @ Don't pad with nop.
