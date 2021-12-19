	#include "asm/constants/gba_constants.inc"
	#include "asm/macros.inc"

	.syntax unified

	.text

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
