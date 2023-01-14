	#include "asm/constants/gba_constants.inc"
	#include "asm/macros.inc"

	.syntax unified

	.text

	thumb_func_start sub_8096C80
sub_8096C80:
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	movs r2, 0
	movs r3, 0
	ldr r0, _08096C98
	mov r12, r0
	mov r8, r3
	movs r4, 0
	mov r9, r4
	b _08096CC2
	.align 2, 0
_08096C98: .4byte gUnknown_203B490
_08096C9C:
	cmp r2, r3
	ble _08096CB6
	mov r1, r12
	ldr r0, [r1]
	mov r5, r8
	adds r1, r0, r5
	adds r0, r4
	adds r1, 0xF0
	adds r0, 0xF0
	ldm r0!, {r5-r7}
	stm r1!, {r5-r7}
	ldm r0!, {r6,r7}
	stm r1!, {r6,r7}
_08096CB6:
	adds r4, 0x14
	movs r0, 0x14
	add r9, r0
	adds r2, 0x1
	add r8, r0
	adds r3, 0x1
_08096CC2:
	cmp r2, 0x7
	bgt _08096CF2
	mov r1, r12
	ldr r0, [r1]
	adds r0, r4
	adds r0, 0xF0
	ldrb r0, [r0]
	cmp r0, 0
	bne _08096CF2
	ldr r6, _08096D20
	mov r1, r9
_08096CD8:
	adds r1, 0x14
	adds r4, 0x14
	movs r5, 0x14
	add r9, r5
	adds r2, 0x1
	cmp r2, 0x7
	bgt _08096CF2
	ldr r0, [r6]
	adds r0, r1
	adds r0, 0xF0
	ldrb r0, [r0]
	cmp r0, 0
	beq _08096CD8
_08096CF2:
	cmp r2, 0x8
	bne _08096C9C
	cmp r3, 0x7
	bgt _08096D14
	ldr r4, _08096D20
	movs r2, 0
	lsls r0, r3, 2
	adds r0, r3
	lsls r1, r0, 2
_08096D04:
	ldr r0, [r4]
	adds r0, r1
	adds r0, 0xF0
	strb r2, [r0]
	adds r1, 0x14
	adds r3, 0x1
	cmp r3, 0x7
	ble _08096D04
_08096D14:
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_08096D20: .4byte gUnknown_203B490
	thumb_func_end sub_8096C80

	thumb_func_start sub_8096D24
sub_8096D24:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x18
	movs r1, 0
_08096D32:
	adds r6, r1, 0x1
	mov r10, r6
	cmp r6, 0x7
	bgt _08096DBC
	ldr r0, _08096DD4
	mov r8, r0
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 2
	mov r9, r0
	lsls r0, r6, 2
	adds r0, r6
	lsls r4, r0, 2
_08096D4C:
	mov r1, r8
	ldr r2, [r1]
	adds r3, r2, r4
	adds r5, r3, 0
	adds r5, 0xF0
	str r5, [sp, 0x14]
	ldrb r0, [r5]
	cmp r0, 0
	beq _08096DB0
	add r2, r9
	mov r12, r2
	mov r0, r12
	adds r0, 0xF4
	adds r1, r3, 0
	adds r1, 0xF4
	ldrb r2, [r0]
	ldrb r0, [r1]
	cmp r2, r0
	bhi _08096D84
	cmp r2, r0
	bne _08096DB0
	mov r0, r12
	adds r0, 0xF5
	adds r1, 0x1
	ldrb r0, [r0]
	ldrb r1, [r1]
	cmp r0, r1
	bls _08096DB0
_08096D84:
	mov r2, r12
	adds r2, 0xF0
	mov r1, sp
	adds r0, r2, 0
	ldm r0!, {r3,r5,r7}
	stm r1!, {r3,r5,r7}
	ldm r0!, {r3,r7}
	stm r1!, {r3,r7}
	ldr r0, [sp, 0x14]
	ldm r0!, {r1,r5,r7}
	stm r2!, {r1,r5,r7}
	ldm r0!, {r3,r5}
	stm r2!, {r3,r5}
	mov r7, r8
	ldr r1, [r7]
	adds r1, r4
	adds r1, 0xF0
	mov r0, sp
	ldm r0!, {r2,r3,r5}
	stm r1!, {r2,r3,r5}
	ldm r0!, {r2,r7}
	stm r1!, {r2,r7}
_08096DB0:
	adds r4, 0x14
	movs r3, 0x1
	add r10, r3
	mov r5, r10
	cmp r5, 0x7
	ble _08096D4C
_08096DBC:
	adds r1, r6, 0
	cmp r1, 0x6
	ble _08096D32
	add sp, 0x18
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_08096DD4: .4byte gUnknown_203B490
	thumb_func_end sub_8096D24

	thumb_func_start sub_8096DD8
sub_8096DD8:
	ldr r0, _08096DE4
	ldr r0, [r0]
	movs r1, 0xC8
	lsls r1, 1
	adds r0, r1
	bx lr
	.align 2, 0
_08096DE4: .4byte gUnknown_203B490
	thumb_func_end sub_8096DD8

	thumb_func_start sub_8096DE8
sub_8096DE8:
	ldr r0, _08096DF4
	ldr r0, [r0]
	movs r1, 0xDC
	lsls r1, 1
	adds r0, r1
	bx lr
	.align 2, 0
_08096DF4: .4byte gUnknown_203B490
	thumb_func_end sub_8096DE8

	thumb_func_start ReceivePKMNNews
ReceivePKMNNews:
	lsls r0, 24
	lsrs r0, 24
	ldr r1, _08096E10
	ldr r1, [r1]
	movs r2, 0xBC
	lsls r2, 2
	adds r1, r2
	adds r1, r0
	movs r0, 0x1
	strb r0, [r1]
	bx lr
	.align 2, 0
_08096E10: .4byte gUnknown_203B490
	thumb_func_end ReceivePKMNNews

	thumb_func_start CheckPKMNNewsSlot
CheckPKMNNewsSlot:
	lsls r0, 24
	lsrs r0, 24
	ldr r1, _08096E28
	ldr r1, [r1]
	movs r2, 0xBC
	lsls r2, 2
	adds r1, r2
	adds r1, r0
	ldrb r0, [r1]
	bx lr
	.align 2, 0
_08096E28: .4byte gUnknown_203B490
	thumb_func_end CheckPKMNNewsSlot

	thumb_func_start sub_8096E2C
sub_8096E2C:
	push {lr}
	movs r3, 0
	ldr r0, _08096E70
	ldr r1, [r0]
	movs r2, 0x3
_08096E36:
	ldrb r0, [r1]
	cmp r0, 0x1
	bne _08096E48
	ldrb r0, [r1, 0x5]
	cmp r3, r0
	bgt _08096E48
	cmp r0, 0x31
	bhi _08096E48
	adds r3, r0, 0x1
_08096E48:
	adds r1, 0x14
	subs r2, 0x1
	cmp r2, 0
	bge _08096E36
	adds r2, r3, 0
	cmp r2, 0x31
	bgt _08096E7A
	ldr r0, _08096E70
	ldr r0, [r0]
	movs r3, 0xBC
	lsls r3, 2
	adds r1, r0, r3
_08096E60:
	adds r0, r1, r2
	ldrb r0, [r0]
	cmp r0, 0
	bne _08096E74
	lsls r0, r2, 24
	lsrs r0, 24
	b _08096E7C
	.align 2, 0
_08096E70: .4byte gUnknown_203B490
_08096E74:
	adds r2, 0x1
	cmp r2, 0x31
	ble _08096E60
_08096E7A:
	movs r0, 0x38
_08096E7C:
	pop {r1}
	bx r1
	thumb_func_end sub_8096E2C

	thumb_func_start sub_8096E80
sub_8096E80:
	push {lr}
	lsls r0, 24
	lsrs r3, r0, 24
	movs r2, 0
	ldr r0, _08096E9C
	ldr r1, [r0]
_08096E8C:
	ldrb r0, [r1]
	cmp r0, 0x1
	bne _08096EA0
	ldrb r0, [r1, 0x5]
	cmp r3, r0
	bne _08096EA0
	movs r0, 0x1
	b _08096EAA
	.align 2, 0
_08096E9C: .4byte gUnknown_203B490
_08096EA0:
	adds r1, 0x14
	adds r2, 0x1
	cmp r2, 0x3
	ble _08096E8C
	movs r0, 0
_08096EAA:
	pop {r1}
	bx r1
	thumb_func_end sub_8096E80

	thumb_func_start sub_8096EB0
sub_8096EB0:
	ldrb r1, [r0, 0x2]
	ldrb r2, [r0, 0x1]
	adds r1, r2
	ldrb r3, [r0, 0x4]
	adds r2, r1, r3
	ldrb r1, [r0, 0x5]
	adds r2, r1
	ldr r1, [r0, 0x8]
	lsls r1, 8
	adds r2, r1
	movs r3, 0xC
	ldrsh r1, [r0, r3]
	lsls r1, 12
	adds r2, r1
	movs r3, 0xE
	ldrsh r1, [r0, r3]
	lsls r1, 16
	adds r2, r1
	ldrb r1, [r0, 0x10]
	lsls r1, 24
	adds r1, r2, r1
	ldrb r3, [r0, 0x11]
	adds r2, r1, r3
	ldrb r1, [r0, 0x12]
	adds r1, r2, r1
	ldrb r0, [r0, 0x13]
	adds r2, r1, r0
	adds r0, r2, 0
	bx lr
	thumb_func_end sub_8096EB0

	thumb_func_start sub_8096EEC
sub_8096EEC:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	mov r12, r0
	movs r3, 0xF
	ldr r5, _08096F4C
	mov r8, r5
	movs r4, 0x8C
	lsls r4, 2
_08096EFE:
	mov r0, r8
	ldr r2, [r0]
	lsls r1, r3, 1
	adds r1, r3
	lsls r1, 2
	adds r1, r2, r1
	subs r3, 0x1
	lsls r0, r3, 1
	adds r0, r3
	lsls r0, 2
	adds r2, r0
	adds r1, r4
	adds r2, r4
	ldm r2!, {r0,r6,r7}
	stm r1!, {r0,r6,r7}
	cmp r3, 0
	bgt _08096EFE
	ldr r2, [r5]
	movs r3, 0x8C
	lsls r3, 2
	adds r2, r3
	mov r6, r12
	ldr r0, [r6, 0x4]
	ldr r1, [r6, 0x8]
	str r0, [r2]
	str r1, [r2, 0x4]
	mov r0, r12
	bl sub_8096EB0
	ldr r1, [r5]
	movs r7, 0x8E
	lsls r7, 2
	adds r1, r7
	str r0, [r1]
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_08096F4C: .4byte gUnknown_203B490
	thumb_func_end sub_8096EEC


        .align 2,0
