	.include "constants/gba_constants.inc"
	.include "asm/macros.inc"

	.syntax unified

	.text

	thumb_func_start InitInput
InitInput:
	ldr r0, _08004840
	movs r3, 0
	movs r2, 0
	strh r2, [r0]
	strh r2, [r0, 0x2]
	strh r2, [r0, 0x4]
	strh r2, [r0, 0x6]
	ldr r0, _08004844
	strh r2, [r0]
	strh r2, [r0, 0x2]
	strh r2, [r0, 0x4]
	strh r2, [r0, 0x6]
	ldr r1, _08004848
	ldr r0, _0800484C
	str r0, [r1]
	ldr r0, _08004850
	str r2, [r0, 0x20]
	ldr r1, _08004854
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
	ldr r0, _08004858
	strh r2, [r0]
	strh r2, [r0, 0x2]
	bx lr
	.align 2, 0
_08004840: .4byte gUnknown_20255F0
_08004844: .4byte gUnknown_2025638
_08004848: .4byte gUnknown_202562C
_0800484C: .4byte 0x004a14c1
_08004850: .4byte gUnknown_2025600
_08004854: .4byte 0x0000ffff
_08004858: .4byte gUnknown_2025668
	thumb_func_end InitInput

	thumb_func_start sub_800485C
sub_800485C:
	push {r4,r5,lr}
	ldr r2, _080048A8
	ldr r1, _080048AC
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
	ldr r0, _080048B0
	ldr r1, _080048B4
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
_080048A8: .4byte gUnknown_2025638
_080048AC: .4byte gUnknown_20255F0
_080048B0: .4byte gUnknown_2025600
_080048B4: .4byte 0x0000ffff
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
	ldr r1, _080048E8
	movs r0, 0
	strh r0, [r1, 0x4]
	ldr r1, _080048EC
	str r0, [r1, 0xC]
	strh r0, [r1, 0x8]
	ldr r1, _080048F0
	ldr r0, _080048F4
	strh r0, [r1]
	strh r0, [r1, 0x2]
	bx lr
	.align 2, 0
_080048E8: .4byte gUnknown_20255F0
_080048EC: .4byte gUnknown_2025648
_080048F0: .4byte gUnknown_2025668
_080048F4: .4byte 0x000003e7
	thumb_func_end sub_80048D0

	thumb_func_start sub_80048F8
sub_80048F8:
	ldr r0, _08004908
	movs r1, 0
	strh r1, [r0, 0x2]
	ldr r0, _0800490C
	strh r1, [r0, 0x2]
	ldr r0, _08004910
	strh r1, [r0, 0x2]
	bx lr
	.align 2, 0
_08004908: .4byte gUnknown_20255F0
_0800490C: .4byte gUnknown_2025638
_08004910: .4byte gUnknown_2025648
	thumb_func_end sub_80048F8

	thumb_func_start sub_8004914
sub_8004914:
	ldr r0, _0800494C
	movs r1, 0x5
	str r1, [r0, 0x20]
	movs r2, 0
	movs r1, 0
	strh r1, [r0, 0x24]
	ldr r1, _08004950
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
_0800494C: .4byte gUnknown_2025600
_08004950: .4byte 0x0000ffff
	thumb_func_end sub_8004914

	thumb_func_start UpdateInput
UpdateInput:
	push {r4-r6,lr}
	ldr r4, _08004998
	ldr r5, _0800499C
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
_08004998: .4byte gUnknown_2025658
_0800499C: .4byte gUnknown_2025648
_080049A0:
	strh r2, [r5, 0x8]
	movs r0, 0x1
	str r0, [r5, 0xC]
	b _080049AC
_080049A8:
	str r0, [r5, 0xC]
	strh r0, [r5, 0x8]
_080049AC:
	ldr r0, _080049C4
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
_080049C4: .4byte gUnknown_2025648
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
	ldr r0, _08004A08
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
_08004A08: .4byte gUnknown_2025668
_08004A0C:
	ldr r1, _08004A44
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
_08004A44: .4byte gUnknown_2025668
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
	ldr r2, _08004A94
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
	ldr r2, _08004A98
	ldrh r0, [r3]
	ldr r1, _08004A9C
	orrs r0, r1
	ldr r1, [r2]
	muls r0, r1
	str r0, [r2]
	pop {r4-r6}
	pop {r0}
	bx r0
	.align 2, 0
_08004A94: .4byte gUnknown_2025638
_08004A98: .4byte gUnknown_202562C
_08004A9C: .4byte 0x054a1c41
	thumb_func_end UpdateInput

	thumb_func_start nullsub_6
nullsub_6:
	bx lr
	thumb_func_end nullsub_6

	thumb_func_start sub_8004AA4
sub_8004AA4:
	push {r4,r5,lr}
	adds r3, r0, 0
	ldr r4, [r1, 0x4]
	cmp r2, 0
	ble _08004AE8
_08004AAE:
	ldm r4!, {r1}
	movs r5, 0
	ldrsh r0, [r1, r5]
	cmp r0, 0
	beq _08004ADE
	movs r0, 0x80
	lsls r0, 24
	str r0, [r3]
	ldrh r0, [r1, 0x2]
	strh r0, [r3, 0x6]
	ldrh r0, [r1, 0x2]
	strh r0, [r3, 0x4]
	adds r0, r1, 0x4
	str r0, [r3, 0x8]
	str r0, [r3, 0xC]
	movs r5, 0
	ldrsh r0, [r1, r5]
	lsls r0, 2
	adds r0, 0x4
	adds r0, r1, r0
	str r0, [r3, 0x10]
	ldr r0, [r1, 0x4]
	str r0, [r3, 0x14]
	b _08004AE0
_08004ADE:
	str r0, [r3]
_08004AE0:
	adds r3, 0x18
	subs r2, 0x1
	cmp r2, 0
	bne _08004AAE
_08004AE8:
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_8004AA4

	thumb_func_start sub_8004AF0
sub_8004AF0:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	adds r4, r1, 0
	adds r6, r2, 0
	lsls r0, 24
	lsrs r0, 24
	mov r8, r0
	movs r7, 0
	cmp r7, r3
	bge _08004B6A
	adds r5, r3, 0
_08004B08:
	adds r0, r4, 0
	movs r1, 0x1
	bl sub_8004D14
	lsls r0, 24
	cmp r0, 0
	beq _08004B60
	adds r0, r4, 0
	movs r1, 0x1
	bl sub_8004D40
	lsls r0, 24
	cmp r0, 0
	bne _08004B60
	mov r1, r8
	ldrh r0, [r4, 0x6]
	subs r0, 0x1
	strh r0, [r4, 0x6]
	lsls r0, 16
	cmp r0, 0
	bgt _08004B4E
	ldrh r0, [r4, 0x4]
	strh r0, [r4, 0x6]
	ldr r1, [r4, 0xC]
	ldr r0, [r4, 0x10]
	cmp r1, r0
	bcc _08004B42
	ldr r0, [r4, 0x8]
	str r0, [r4, 0xC]
_08004B42:
	ldr r1, [r4, 0xC]
	ldm r1!, {r0}
	str r0, [r4, 0x14]
	str r1, [r4, 0xC]
	movs r1, 0x1
	movs r7, 0x1
_08004B4E:
	cmp r1, 0
	beq _08004B60
	adds r1, r4, 0
	adds r1, 0x14
	adds r0, r6, 0
	ldr r2, [sp, 0x18]
	ldr r3, [sp, 0x1C]
	bl SetBGPaletteBufferColorRGB
_08004B60:
	subs r5, 0x1
	adds r4, 0x18
	adds r6, 0x1
	cmp r5, 0
	bne _08004B08
_08004B6A:
	adds r0, r7, 0
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_8004AF0

	thumb_func_start sub_8004B78
sub_8004B78:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	adds r4, r1, 0
	adds r6, r2, 0
	lsls r0, 24
	lsrs r0, 24
	mov r8, r0
	movs r7, 0
	cmp r7, r3
	bge _08004BF2
	adds r5, r3, 0
_08004B90:
	adds r0, r4, 0
	movs r1, 0x1
	bl sub_8004D14
	lsls r0, 24
	cmp r0, 0
	beq _08004BE8
	adds r0, r4, 0
	movs r1, 0x1
	bl sub_8004D40
	lsls r0, 24
	cmp r0, 0
	bne _08004BE8
	mov r1, r8
	ldrh r0, [r4, 0x6]
	subs r0, 0x1
	strh r0, [r4, 0x6]
	lsls r0, 16
	cmp r0, 0
	bgt _08004BD6
	ldrh r0, [r4, 0x4]
	strh r0, [r4, 0x6]
	ldr r1, [r4, 0xC]
	ldr r0, [r4, 0x10]
	cmp r1, r0
	bcc _08004BCA
	ldr r0, [r4, 0x8]
	str r0, [r4, 0xC]
_08004BCA:
	ldr r1, [r4, 0xC]
	ldm r1!, {r0}
	str r0, [r4, 0x14]
	str r1, [r4, 0xC]
	movs r1, 0x1
	movs r7, 0x1
_08004BD6:
	cmp r1, 0
	beq _08004BE8
	adds r1, r4, 0
	adds r1, 0x14
	adds r0, r6, 0
	ldr r2, [sp, 0x18]
	ldr r3, [sp, 0x1C]
	bl nullsub_4
_08004BE8:
	subs r5, 0x1
	adds r4, 0x18
	adds r6, 0x1
	cmp r5, 0
	bne _08004B90
_08004BF2:
	adds r0, r7, 0
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_8004B78

	thumb_func_start sub_8004C00
sub_8004C00:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x4
	adds r4, r0, 0
	adds r7, r1, 0
	mov r10, r3
	ldr r0, [sp, 0x28]
	mov r8, r0
	movs r1, 0
	mov r9, r1
	cmp r9, r2
	bge _08004CDC
	adds r6, r2, 0
_08004C20:
	adds r0, r4, 0
	movs r1, 0x1
	bl sub_8004D14
	lsls r0, 24
	cmp r0, 0
	beq _08004CD2
	adds r0, r4, 0
	movs r1, 0x1
	bl sub_8004D40
	lsls r0, 24
	cmp r0, 0
	bne _08004CD2
	ldrh r0, [r4, 0x6]
	subs r0, 0x1
	strh r0, [r4, 0x6]
	lsls r0, 16
	cmp r0, 0
	bgt _08004C64
	ldrh r0, [r4, 0x4]
	strh r0, [r4, 0x6]
	ldr r1, [r4, 0xC]
	ldr r0, [r4, 0x10]
	cmp r1, r0
	bcc _08004C58
	ldr r0, [r4, 0x8]
	str r0, [r4, 0xC]
_08004C58:
	ldr r1, [r4, 0xC]
	ldm r1!, {r0}
	str r0, [r4, 0x14]
	str r1, [r4, 0xC]
	movs r2, 0x1
	mov r9, r2
_08004C64:
	mov r3, r8
	movs r5, 0
	ldrsh r0, [r3, r5]
	ldrb r2, [r4, 0x14]
	adds r1, r0, r2
	movs r5, 0x2
	ldrsh r0, [r3, r5]
	ldrb r2, [r4, 0x15]
	adds r3, r0, r2
	mov r5, r8
	movs r2, 0x4
	ldrsh r0, [r5, r2]
	ldrb r2, [r4, 0x16]
	adds r5, r0, r2
	cmp r1, 0xFF
	ble _08004C86
	movs r1, 0xFF
_08004C86:
	cmp r3, 0xFF
	ble _08004C8C
	movs r3, 0xFF
_08004C8C:
	cmp r5, 0xFF
	ble _08004C92
	movs r5, 0xFF
_08004C92:
	cmp r1, 0
	bge _08004C98
	movs r1, 0
_08004C98:
	cmp r3, 0
	bge _08004C9E
	movs r3, 0
_08004C9E:
	cmp r5, 0
	bge _08004CA4
	movs r5, 0
_08004CA4:
	lsls r1, 24
	lsrs r1, 24
	ldr r2, _08004CF0
	ldr r0, [sp]
	ands r0, r2
	orrs r0, r1
	lsls r2, r3, 24
	lsrs r2, 16
	ldr r1, _08004CF4
	ands r0, r1
	orrs r0, r2
	lsls r2, r5, 24
	lsrs r2, 8
	ldr r1, _08004CF8
	ands r0, r1
	orrs r0, r2
	str r0, [sp]
	adds r0, r7, 0
	mov r1, sp
	mov r2, r10
	ldr r3, [sp, 0x24]
	bl SetBGPaletteBufferColorRGB
_08004CD2:
	subs r6, 0x1
	adds r4, 0x18
	adds r7, 0x1
	cmp r6, 0
	bne _08004C20
_08004CDC:
	mov r0, r9
	add sp, 0x4
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	.align 2, 0
_08004CF0: .4byte 0xffffff00
_08004CF4: .4byte 0xffff00ff
_08004CF8: .4byte 0xff00ffff
	thumb_func_end sub_8004C00

	thumb_func_start sub_8004CFC
sub_8004CFC:
	push {lr}
	cmp r1, 0
	ble _08004D0E
	movs r2, 0
_08004D04:
	str r2, [r0]
	adds r0, 0x18
	subs r1, 0x1
	cmp r1, 0
	bne _08004D04
_08004D0E:
	pop {r0}
	bx r0
	thumb_func_end sub_8004CFC

	thumb_func_start sub_8004D14
sub_8004D14:
	push {r4,lr}
	adds r2, r0, 0
	movs r3, 0
	cmp r3, r1
	bge _08004D36
	movs r4, 0x80
	lsls r4, 24
_08004D22:
	ldr r0, [r2]
	ands r0, r4
	cmp r0, 0
	beq _08004D2E
	movs r0, 0x1
	b _08004D38
_08004D2E:
	adds r2, 0x18
	adds r3, 0x1
	cmp r3, r1
	blt _08004D22
_08004D36:
	movs r0, 0
_08004D38:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_8004D14

	thumb_func_start sub_8004D40
sub_8004D40:
	push {r4-r6,lr}
	adds r3, r0, 0
	adds r4, r1, 0
	movs r1, 0
	cmp r1, r4
	bge _08004D70
	movs r6, 0x80
	lsls r6, 24
	movs r5, 0x80
	lsls r5, 22
_08004D54:
	ldr r2, [r3]
	adds r0, r2, 0
	ands r0, r6
	cmp r0, 0
	beq _08004D6A
	ands r2, r5
	cmp r2, 0
	bne _08004D68
	movs r0, 0
	b _08004D72
_08004D68:
	adds r3, 0x18
_08004D6A:
	adds r1, 0x1
	cmp r1, r4
	blt _08004D54
_08004D70:
	movs r0, 0x1
_08004D72:
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end sub_8004D40

	.align 2, 0 @ Don't pad with nop.
