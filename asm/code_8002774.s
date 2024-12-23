	#include "asm/constants/gba_constants.inc"
	#include "asm/macros.inc"

	.syntax unified

	.text

	thumb_func_start sub_8002774
sub_8002774:
	sub sp, 0x4
	str r0, [sp]
	mov r0, sp
	ldrb r1, [r0, 0x2]
	movs r0, 0xF8
	adds r2, r0, 0
	ands r2, r1
	lsls r2, 7
	mov r1, sp
	ldrb r3, [r1, 0x1]
	adds r1, r0, 0
	ands r1, r3
	lsls r1, 2
	orrs r2, r1
	mov r1, sp
	ldrb r1, [r1]
	ands r0, r1
	lsrs r0, 3
	orrs r0, r2
	add sp, 0x4
	bx lr
	thumb_func_end sub_8002774

	thumb_func_start sub_80027A0
sub_80027A0:
	push {r4,lr}
	sub sp, 0x4
	lsls r0, 16
	lsrs r2, r0, 16
	adds r3, r2, 0
	mov r4, sp
	movs r0, 0x1F
	ands r0, r2
	lsls r1, r0, 3
	movs r0, 0x1
	ands r0, r2
	cmp r0, 0
	beq _080027BE
	movs r0, 0x7
	orrs r1, r0
_080027BE:
	strb r1, [r4]
	mov r4, sp
	movs r0, 0xF8
	lsls r0, 2
	ands r0, r2
	lsrs r1, r0, 2
	movs r0, 0x20
	ands r0, r2
	cmp r0, 0
	beq _080027D6
	movs r0, 0x7
	orrs r1, r0
_080027D6:
	strb r1, [r4, 0x1]
	mov r2, sp
	movs r0, 0xF8
	lsls r0, 7
	ands r0, r3
	lsrs r1, r0, 7
	movs r0, 0x80
	lsls r0, 3
	ands r3, r0
	cmp r3, 0
	beq _080027F0
	movs r0, 0x7
	orrs r1, r0
_080027F0:
	strb r1, [r2, 0x2]
	mov r0, sp
	movs r1, 0
	strb r1, [r0, 0x3]
	ldr r0, [sp]
	add sp, 0x4
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_80027A0

	thumb_func_start sub_8002804
sub_8002804:
	push {r4,r5,lr}
	adds r5, r0, 0
	adds r4, r1, 0
	movs r3, 0
_0800280C:
	adds r1, r5, r3
	adds r0, r2, r3
	ldrb r0, [r0]
	muls r0, r4
	cmp r0, 0
	bge _0800281A
	adds r0, 0xFF
_0800281A:
	asrs r0, 8
	strb r0, [r1]
	adds r3, 0x1
	cmp r3, 0x3
	ble _0800280C
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_8002804

	thumb_func_start sub_800282C
sub_800282C:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x38
	mov r9, r0
	str r1, [sp, 0x20]
	adds r7, r2, 0
	mov r8, r3
	adds r0, r1, 0
	bl __floatsisf
	adds r1, r0, 0
	ldr r0, _08002904
	bl __divsf3
	str r0, [sp, 0x24]
	movs r5, 0
	mov r0, sp
	adds r0, 0x10
	str r0, [sp, 0x2C]
	str r0, [sp, 0x34]
	mov r10, sp
_0800285C:
	adds r6, r7, r5
	movs r4, 0
	ldrsb r4, [r6, r4]
	adds r0, r4, 0
	bl __floatsisf
	cmp r4, 0
	bge _08002872
	ldr r1, _08002908
	bl __addsf3
_08002872:
	mov r1, r10
	adds r1, 0x4
	mov r10, r1
	subs r1, 0x4
	stm r1!, {r0}
	mov r1, r8
	adds r0, r1, r5
	ldrb r0, [r0]
	ldrb r1, [r6]
	subs r0, r1
	bl __floatsisf
	ldr r1, [sp, 0x24]
	bl __mulsf3
	ldr r1, [sp, 0x34]
	stm r1!, {r0}
	str r1, [sp, 0x34]
	adds r5, 0x1
	cmp r5, 0x3
	ble _0800285C
	ldr r0, [r7]
	mov r1, r9
	adds r1, 0x4
	mov r9, r1
	subs r1, 0x4
	stm r1!, {r0}
	movs r5, 0x1
	ldr r0, [sp, 0x20]
	subs r0, 0x1
	str r0, [sp, 0x28]
	mov r1, r8
	ldr r1, [r1]
	str r1, [sp, 0x30]
	cmp r5, r0
	bge _080028EE
_080028BA:
	movs r6, 0
	adds r5, 0x1
	mov r10, r5
	movs r0, 0x4
	add r0, r9
	mov r8, r0
	mov r5, sp
	ldr r7, [sp, 0x2C]
_080028CA:
	mov r1, r9
	adds r4, r1, r6
	ldr r0, [r5]
	ldm r7!, {r1}
	bl __addsf3
	stm r5!, {r0}
	bl __fixunssfsi
	strb r0, [r4]
	adds r6, 0x1
	cmp r6, 0x3
	ble _080028CA
	mov r9, r8
	mov r5, r10
	ldr r0, [sp, 0x28]
	cmp r5, r0
	blt _080028BA
_080028EE:
	ldr r1, [sp, 0x30]
	mov r0, r9
	str r1, [r0]
	add sp, 0x38
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_08002904: .4byte 0x3f800000
_08002908: .4byte 0x43800000
	thumb_func_end sub_800282C

	.align 2, 0 @ Don't pad with nop.
