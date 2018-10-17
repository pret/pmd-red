	.include "constants/gba_constants.inc"
	.include "asm/macros.inc"

	.syntax unified

	.text

	thumb_func_start InitInput
InitInput:
	ldr r0, =gUnknown_20255F0
	movs r3, 0
	movs r2, 0
	strh r2, [r0]
	strh r2, [r0, 0x2]
	strh r2, [r0, 0x4]
	strh r2, [r0, 0x6]
	ldr r0, =gUnknown_2025638
	strh r2, [r0]
	strh r2, [r0, 0x2]
	strh r2, [r0, 0x4]
	strh r2, [r0, 0x6]
	ldr r1, =gUnknown_202562C
	ldr r0, =0x4a14c1
	str r0, [r1]
	ldr r0, =gUnknown_2025600
	str r2, [r0, 0x20]
	ldr r1, =0xffff
	strh r1, [r0]
	movs r1, 0x1
	negs r1, r1
	strh r1, [r0, 0x2]
	strh r1, [r0, 0x4]
	strh r1, [r0, 0x6]
	strh r1, [r0, 0x1C]
	strh r1, [r0, 0x1E]
	strh r1, [r0, 0x8]
	strh r1, [r0, 0xA]
	strh r1, [r0, 0xC]
	strh r1, [r0, 0xE]
	strh r1, [r0, 0x10]
	strh r1, [r0, 0x12]
	strh r1, [r0, 0x14]
	strh r1, [r0, 0x16]
	adds r1, r0, 0
	adds r1, 0x28
	strb r3, [r1]
	adds r0, 0x29
	strb r3, [r0]
	ldr r0, =gUnknown_2025668
	strh r2, [r0]
	strh r2, [r0, 0x2]
	bx lr
	.align 2, 0
	.pool
	thumb_func_end InitInput

	thumb_func_start sub_800485C
sub_800485C:
	push {r4,r5,lr}
	ldr r2, =gUnknown_2025638
	ldr r1, =gUnknown_20255F0
	adds r0, r2, 0
	ldm r0!, {r3-r5}
	stm r1!, {r3-r5}
	ldr r0, [r0]
	str r0, [r1]
	movs r3, 0
	movs r0, 0
	strh r0, [r2]
	strh r0, [r2, 0x2]
	strh r0, [r2, 0x4]
	strh r0, [r2, 0x6]
	ldr r0, =gUnknown_2025600
	ldr r1, =0xffff
	strh r1, [r0]
	movs r1, 0x1
	negs r1, r1
	strh r1, [r0, 0x2]
	strh r1, [r0, 0x4]
	strh r1, [r0, 0x6]
	strh r1, [r0, 0x8]
	strh r1, [r0, 0xA]
	strh r1, [r0, 0xC]
	strh r1, [r0, 0xE]
	strh r1, [r0, 0x10]
	strh r1, [r0, 0x12]
	strh r1, [r0, 0x14]
	strh r1, [r0, 0x16]
	adds r1, r0, 0
	adds r1, 0x28
	strb r3, [r1]
	adds r0, 0x29
	strb r3, [r0]
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
	.pool 
	thumb_func_end sub_800485C

	thumb_func_start sub_80048B8
sub_80048B8:
	movs r0, 0
	bx lr
	thumb_func_end sub_80048B8

	thumb_func_start sub_80048BC
sub_80048BC:
	movs r0, 0
	bx lr
	thumb_func_end sub_80048BC

	thumb_func_start sub_80048C0
sub_80048C0:
	movs r0, 0
	bx lr
	thumb_func_end sub_80048C0

	thumb_func_start sub_80048C4
sub_80048C4:
	movs r0, 0
	bx lr
	thumb_func_end sub_80048C4

	thumb_func_start sub_80048C8
sub_80048C8:
	movs r0, 0
	bx lr
	thumb_func_end sub_80048C8

	thumb_func_start sub_80048CC
sub_80048CC:
	movs r0, 0
	bx lr
	thumb_func_end sub_80048CC

	thumb_func_start sub_80048D0
sub_80048D0:
	ldr r1, =gUnknown_20255F0
	movs r0, 0
	strh r0, [r1, 0x4]
	ldr r1, =gUnknown_2025648
	str r0, [r1, 0xC]
	strh r0, [r1, 0x8]
	ldr r1, =gUnknown_2025668
	ldr r0, =0x3e7
	strh r0, [r1]
	strh r0, [r1, 0x2]
	bx lr
	.align 2, 0
	.pool
	thumb_func_end sub_80048D0

	thumb_func_start sub_80048F8
sub_80048F8:
	ldr r0, =gUnknown_20255F0
	movs r1, 0
	strh r1, [r0, 0x2]
	ldr r0, =gUnknown_2025638
	strh r1, [r0, 0x2]
	ldr r0, =gUnknown_2025648
	strh r1, [r0, 0x2]
	bx lr
	.align 2, 0
	.pool
	thumb_func_end sub_80048F8

	thumb_func_start sub_8004914
sub_8004914:
	ldr r0, =gUnknown_2025600
	movs r1, 0x5
	str r1, [r0, 0x20]
	movs r2, 0
	movs r1, 0
	strh r1, [r0, 0x24]
	ldr r1, =0xffff
	strh r1, [r0]
	movs r1, 0x1
	negs r1, r1
	strh r1, [r0, 0x2]
	strh r1, [r0, 0x4]
	strh r1, [r0, 0x6]
	strh r1, [r0, 0x8]
	strh r1, [r0, 0xA]
	strh r1, [r0, 0xC]
	strh r1, [r0, 0xE]
	strh r1, [r0, 0x10]
	strh r1, [r0, 0x12]
	strh r1, [r0, 0x14]
	strh r1, [r0, 0x16]
	adds r1, r0, 0
	adds r1, 0x28
	strb r2, [r1]
	adds r0, 0x29
	strb r2, [r0]
	bx lr
	.align 2, 0
	.pool
	thumb_func_end sub_8004914

	thumb_func_start UpdateInput
UpdateInput:
	push {r4-r6,lr}
	ldr r4, =gUnknown_2025658
	ldr r5, =gUnknown_2025648
	adds r1, r4, 0
	adds r0, r5, 0
	ldm r0!, {r2,r3,r6}
	stm r1!, {r2,r3,r6}
	ldr r0, [r0]
	str r0, [r1]
	adds r0, r5, 0
	bl ReadKeyInput
	ldrh r0, [r4]
	ldrh r3, [r5]
	eors r0, r3
	ands r0, r3
	strh r0, [r5, 0x2]
	lsls r0, r3, 16
	lsrs r0, 16
	cmp r0, 0
	beq _080049A8
	ldrh r1, [r5, 0x8]
	movs r0, 0xF0
	adds r2, r0, 0
	ands r2, r3
	ands r0, r1
	cmp r0, r2
	bne _080049A0
	ldr r0, [r5, 0xC]
	cmp r0, 0x31
	bgt _080049AC
	adds r0, 0x1
	str r0, [r5, 0xC]
	b _080049AC
	.align 2, 0
	.pool
_080049A0:
	strh r2, [r5, 0x8]
	movs r0, 0x1
	str r0, [r5, 0xC]
	b _080049AC
_080049A8:
	str r0, [r5, 0xC]
	strh r0, [r5, 0x8]
_080049AC:
	ldr r0, =gUnknown_2025648
	ldr r2, [r0, 0xC]
	adds r3, r0, 0
	cmp r2, 0x1
	bne _080049C8
	ldrh r0, [r3, 0x8]
	movs r1, 0xF0
	ands r1, r0
	ldrh r0, [r3, 0x2]
	orrs r1, r0
	strh r1, [r3, 0x4]
	b _080049E0
	.align 2, 0
	.pool
_080049C8:
	cmp r2, 0x30
	bne _080049DC
	movs r0, 0x2B
	str r0, [r3, 0xC]
	ldrh r1, [r3, 0x8]
	movs r0, 0xF0
	ands r0, r1
	ldrh r1, [r3, 0x2]
	orrs r0, r1
	b _080049DE
_080049DC:
	movs r0, 0
_080049DE:
	strh r0, [r3, 0x4]
_080049E0:
	movs r0, 0
	strh r0, [r3, 0x6]
	ldrh r1, [r3]
	movs r5, 0x2
	adds r0, r5, 0
	ands r0, r1
	lsls r0, 16
	lsrs r2, r0, 16
	cmp r2, 0
	beq _08004A0C
	ldr r0, =gUnknown_2025668
	ldrh r2, [r0]
	movs r4, 0
	ldrsh r1, [r0, r4]
	adds r4, r0, 0
	cmp r1, 0x63
	bgt _08004A20
	adds r0, r2, 0x1
	strh r0, [r4]
	b _08004A20
	.align 2, 0
	.pool
_08004A0C:
	ldr r1, =gUnknown_2025668
	ldrh r0, [r1]
	subs r0, 0x2
	lsls r0, 16
	lsrs r0, 16
	adds r4, r1, 0
	cmp r0, 0x9
	bhi _08004A1E
	strh r5, [r3, 0x6]
_08004A1E:
	strh r2, [r4]
_08004A20:
	ldrh r1, [r3]
	movs r5, 0x80
	lsls r5, 1
	adds r0, r5, 0
	ands r0, r1
	lsls r0, 16
	lsrs r2, r0, 16
	cmp r2, 0
	beq _08004A48
	ldrh r1, [r4, 0x2]
	movs r6, 0x2
	ldrsh r0, [r4, r6]
	cmp r0, 0x63
	bgt _08004A5E
	adds r0, r1, 0x1
	strh r0, [r4, 0x2]
	b _08004A5E
	.align 2, 0
	.pool
_08004A48:
	ldrh r0, [r4, 0x2]
	subs r0, 0x2
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0x9
	bhi _08004A5C
	ldrh r1, [r3, 0x6]
	adds r0, r5, 0
	orrs r0, r1
	strh r0, [r3, 0x6]
_08004A5C:
	strh r2, [r4, 0x2]
_08004A5E:
	ldr r2, =gUnknown_2025638
	ldrh r0, [r2]
	ldrh r1, [r3]
	orrs r0, r1
	strh r0, [r2]
	ldrh r0, [r2, 0x2]
	ldrh r1, [r3, 0x2]
	orrs r0, r1
	strh r0, [r2, 0x2]
	ldrh r0, [r2, 0x4]
	ldrh r1, [r3, 0x4]
	orrs r0, r1
	strh r0, [r2, 0x4]
	ldrh r0, [r2, 0x6]
	ldrh r1, [r3, 0x6]
	orrs r0, r1
	strh r0, [r2, 0x6]
	ldr r2, =gUnknown_202562C
	ldrh r0, [r3]
	ldr r1, =0x054a1c41
	orrs r0, r1
	ldr r1, [r2]
	muls r0, r1
	str r0, [r2]
	pop {r4-r6}
	pop {r0}
	bx r0
	.align 2, 0
	.pool
	thumb_func_end UpdateInput

	.align 2, 0 @ Don't pad with nop.
