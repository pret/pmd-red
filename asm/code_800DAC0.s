	#include "asm/constants/gba_constants.inc"
	#include "asm/macros.inc"

	.syntax unified

	.text


	thumb_func_start sub_800E698
sub_800E698:
	push {r4,r5,lr}
	adds r4, r1, 0
	adds r5, r2, 0
	bl sub_800E2C0
	adds r1, r0, 0
	movs r3, 0x1
	negs r3, r3
	cmp r1, r3
	beq _0800E6D2
	ldr r2, _0800E6C8
	movs r0, 0xD0
	muls r1, r0
	ldr r0, [r2]
	adds r1, r0, r1
	ldr r0, [r4]
	str r0, [r1, 0x18]
	ldr r0, [r1, 0x20]
	cmp r0, r3
	beq _0800E6CC
	ldr r0, [r5]
	str r0, [r1, 0x1C]
	b _0800E6D2
	.align 2, 0
_0800E6C8: .4byte gUnknown_203B0CC
_0800E6CC:
	movs r0, 0
	strh r0, [r1, 0x1C]
	strh r0, [r1, 0x1E]
_0800E6D2:
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_800E698

	thumb_func_start sub_800E6D8
sub_800E6D8:
	push {lr}
	bl sub_800E2C0
	adds r1, r0, 0
	movs r0, 0x1
	negs r0, r0
	cmp r1, r0
	bne _0800E6EC
	adds r0, r1, 0
	b _0800E6F8
_0800E6EC:
	ldr r2, _0800E6FC
	movs r0, 0xD0
	muls r1, r0
	ldr r0, [r2]
	adds r0, r1
	ldr r0, [r0, 0x20]
_0800E6F8:
	pop {r1}
	bx r1
	.align 2, 0
_0800E6FC: .4byte gUnknown_203B0CC
	thumb_func_end sub_800E6D8

	thumb_func_start sub_800E700
sub_800E700:
	push {lr}
	lsls r0, 16
	asrs r0, 16
	bl sub_800E900
	pop {r1}
	bx r1
	thumb_func_end sub_800E700

	thumb_func_start sub_800E710
sub_800E710:
	push {r4-r6,lr}
	lsls r0, 16
	asrs r5, r0, 16
	lsls r1, 16
	lsrs r1, 16
	adds r0, r1, 0
	bl sub_800ECB8
	adds r4, r0, 0
	ldr r0, [r4, 0x20]
	bl sub_800ECD0
	adds r1, r0, 0
	movs r2, 0
	ldr r0, [r4, 0x1C]
	cmp r2, r0
	bge _0800E748
	adds r3, r0, 0
_0800E734:
	movs r6, 0
	ldrsh r0, [r1, r6]
	cmp r0, r5
	bne _0800E740
	ldr r0, [r1, 0x4]
	b _0800E74A
_0800E740:
	adds r2, 0x1
	adds r1, 0xC
	cmp r2, r3
	blt _0800E734
_0800E748:
	ldr r0, [r4, 0x14]
_0800E74A:
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end sub_800E710

	thumb_func_start sub_800E750
sub_800E750:
	push {r4-r6,lr}
	lsls r0, 16
	asrs r5, r0, 16
	lsls r1, 16
	lsrs r1, 16
	adds r0, r1, 0
	bl sub_800ECB8
	adds r4, r0, 0
	ldr r0, [r4, 0x20]
	bl sub_800ECD0
	adds r1, r0, 0
	movs r2, 0
	ldr r0, [r4, 0x1C]
	cmp r2, r0
	bge _0800E788
	adds r3, r0, 0
_0800E774:
	movs r6, 0
	ldrsh r0, [r1, r6]
	cmp r0, r5
	bne _0800E780
	ldr r0, [r1, 0x4]
	b _0800E78A
_0800E780:
	adds r2, 0x1
	adds r1, 0xC
	cmp r2, r3
	blt _0800E774
_0800E788:
	ldr r0, [r4, 0x14]
_0800E78A:
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end sub_800E750

	thumb_func_start sub_800E790
sub_800E790:
	push {r4-r6,lr}
	lsls r0, 16
	asrs r5, r0, 16
	lsls r1, 16
	lsrs r1, 16
	adds r0, r1, 0
	bl sub_800ECB8
	adds r4, r0, 0
	ldr r0, [r4, 0x20]
	bl sub_800ECD0
	adds r1, r0, 0
	movs r2, 0
	ldr r0, [r4, 0x1C]
	cmp r2, r0
	bge _0800E7C8
	adds r3, r0, 0
_0800E7B4:
	movs r6, 0
	ldrsh r0, [r1, r6]
	cmp r0, r5
	bne _0800E7C0
	ldr r0, [r1, 0x8]
	b _0800E7CA
_0800E7C0:
	adds r2, 0x1
	adds r1, 0xC
	cmp r2, r3
	blt _0800E7B4
_0800E7C8:
	ldr r0, [r4, 0x18]
_0800E7CA:
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end sub_800E790

        .align 2,0
