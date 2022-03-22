	#include "asm/constants/gba_constants.inc"
	#include "asm/macros.inc"

	.syntax unified

	.text	

	thumb_func_start sub_80A293C
sub_80A293C:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0x40
	mov r8, r0
	movs r7, 0
	movs r1, 0
	mov r0, sp
	adds r0, 0x3E
_080A294E:
	strb r1, [r0]
	subs r0, 0x1
	cmp r0, sp
	bge _080A294E
	movs r5, 0
_080A2958:
	lsls r0, r5, 16
	asrs r4, r0, 16
	adds r0, r4, 0
	bl sub_80A2620
	adds r6, r0, 0
	ldrb r0, [r6, 0x11]
	cmp r0, 0
	beq _080A2980
	adds r0, r4, 0
	bl sub_8097384
	lsls r0, 24
	cmp r0, 0
	beq _080A2980
	ldrb r0, [r6, 0xC]
	mov r2, sp
	adds r1, r2, r0
	movs r0, 0x1
	strb r0, [r1]
_080A2980:
	adds r5, 0x1
	cmp r5, 0x2D
	ble _080A2958
	movs r5, 0
_080A2988:
	mov r1, sp
	adds r0, r1, r5
	ldrb r0, [r0]
	cmp r0, 0
	beq _080A299A
	mov r2, r8
	adds r0, r2, r7
	strb r5, [r0]
	adds r7, 0x1
_080A299A:
	adds r5, 0x1
	cmp r5, 0x3E
	ble _080A2988
	adds r0, r7, 0
	add sp, 0x40
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_80A293C

	thumb_func_start sub_80A29B0
sub_80A29B0:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x48
	mov r8, r0
	movs r7, 0
	movs r0, 0x2B
	add r0, sp
	mov r9, r0
	add r1, sp, 0x2C
	mov r10, r1
	mov r2, sp
	adds r2, 0x2D
	str r2, [sp, 0x40]
	mov r0, sp
	adds r0, 0x2E
	str r0, [sp, 0x44]
	movs r1, 0
	adds r0, 0x10
_080A29DA:
	strb r1, [r0]
	subs r0, 0x1
	cmp r0, sp
	bge _080A29DA
	movs r0, 0x1
	bl sub_80023E4
	lsls r0, 24
	cmp r0, 0
	beq _080A2A1E
	movs r5, 0
_080A29F0:
	lsls r0, r5, 16
	asrs r4, r0, 16
	adds r0, r4, 0
	bl sub_80A2620
	adds r6, r0, 0
	ldrb r0, [r6, 0x11]
	cmp r0, 0
	beq _080A2A18
	adds r0, r4, 0
	bl sub_80973F4
	lsls r0, 24
	cmp r0, 0
	beq _080A2A18
	ldrb r0, [r6, 0xC]
	mov r2, sp
	adds r1, r2, r0
	movs r0, 0x1
	strb r0, [r1]
_080A2A18:
	adds r5, 0x1
	cmp r5, 0x2D
	ble _080A29F0
_080A2A1E:
	movs r0, 0
	mov r1, r9
	strb r0, [r1]
	mov r2, r10
	strb r0, [r2]
	ldr r1, [sp, 0x40]
	strb r0, [r1]
	ldr r2, [sp, 0x44]
	strb r0, [r2]
	movs r5, 0
_080A2A32:
	mov r1, sp
	adds r0, r1, r5
	ldrb r0, [r0]
	cmp r0, 0
	beq _080A2A44
	mov r2, r8
	adds r0, r2, r7
	strb r5, [r0]
	adds r7, 0x1
_080A2A44:
	adds r5, 0x1
	cmp r5, 0x3E
	ble _080A2A32
	adds r0, r7, 0
	add sp, 0x48
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_80A29B0

	thumb_func_start sub_80A2A5C
sub_80A2A5C:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0x40
	mov r8, r0
	movs r7, 0
	movs r1, 0
	mov r0, sp
	adds r0, 0x3E
_080A2A6E:
	strb r1, [r0]
	subs r0, 0x1
	cmp r0, sp
	bge _080A2A6E
	movs r0, 0x1
	bl sub_80023E4
	lsls r0, 24
	cmp r0, 0
	beq _080A2AC0
	movs r6, 0
_080A2A84:
	lsls r0, r6, 16
	asrs r4, r0, 16
	adds r0, r4, 0
	bl sub_80A2620
	adds r5, r0, 0
	ldrb r0, [r5, 0x11]
	cmp r0, 0
	beq _080A2AB8
	adds r0, r4, 0
	bl sub_8097384
	lsls r0, 24
	cmp r0, 0
	bne _080A2AAE
	adds r0, r4, 0
	bl sub_80973F4
	lsls r0, 24
	cmp r0, 0
	beq _080A2AB8
_080A2AAE:
	ldrb r0, [r5, 0xC]
	mov r2, sp
	adds r1, r2, r0
	movs r0, 0x1
	strb r0, [r1]
_080A2AB8:
	adds r6, 0x1
	cmp r6, 0x2D
	ble _080A2A84
	b _080A2AF0
_080A2AC0:
	movs r6, 0
_080A2AC2:
	lsls r0, r6, 16
	asrs r4, r0, 16
	adds r0, r4, 0
	bl sub_80A2620
	adds r5, r0, 0
	ldrb r0, [r5, 0x11]
	cmp r0, 0
	beq _080A2AEA
	adds r0, r4, 0
	bl sub_8097384
	lsls r0, 24
	cmp r0, 0
	beq _080A2AEA
	ldrb r0, [r5, 0xC]
	mov r2, sp
	adds r1, r2, r0
	movs r0, 0x1
	strb r0, [r1]
_080A2AEA:
	adds r6, 0x1
	cmp r6, 0x2D
	ble _080A2AC2
_080A2AF0:
	movs r6, 0
_080A2AF2:
	mov r1, sp
	adds r0, r1, r6
	ldrb r0, [r0]
	cmp r0, 0
	beq _080A2B04
	mov r2, r8
	adds r0, r2, r7
	strb r6, [r0]
	adds r7, 0x1
_080A2B04:
	adds r6, 0x1
	cmp r6, 0x3E
	ble _080A2AF2
	adds r0, r7, 0
	add sp, 0x40
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_80A2A5C

	thumb_func_start sub_80A2B18
sub_80A2B18:
	lsls r0, 16
	ldr r1, _080A2B24
	asrs r0, 14
	adds r0, r1
	ldr r0, [r0]
	bx lr
	.align 2, 0
_080A2B24: .4byte gUnknown_8117000
	thumb_func_end sub_80A2B18
