	#include "asm/constants/gba_constants.inc"
	#include "asm/macros.inc"

	.syntax unified

	.text

	thumb_func_start sub_800A088
sub_800A088:
	push {lr}
	adds r2, r0, 0
	lsls r0, r1, 8
	str r0, [r2, 0x4]
	asrs r1, 24
	str r1, [r2]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	beq _0800A0A4
	movs r0, 0x80
	negs r0, r0
	orrs r1, r0
	b _0800A0A8
_0800A0A4:
	movs r0, 0x7F
	ands r1, r0
_0800A0A8:
	str r1, [r2]
	pop {r0}
	bx r0
	thumb_func_end sub_800A088

	thumb_func_start sub_800A0B0
sub_800A0B0:
	push {lr}
	ldr r2, [r0, 0x4]
	ldr r3, [r0]
	cmp r2, 0
	bne _0800A0C2
	cmp r3, 0
	bne _0800A0C2
	movs r0, 0
	b _0800A254
_0800A0C2:
	cmp r2, 0
	ble _0800A18C
	cmp r3, 0
	ble _0800A124
	cmp r2, r3
	bge _0800A0F0
	asrs r1, r3, 8
	cmp r1, 0
	beq _0800A0FE
	adds r0, r2, 0
	bl __divsi3
	adds r2, r0, 0
	cmp r2, 0xFF
	ble _0800A0E2
	movs r2, 0xFF
_0800A0E2:
	ldr r0, _0800A0EC
	lsls r1, r2, 2
	adds r1, r0
	ldr r0, [r1]
	b _0800A252
	.align 2, 0
_0800A0EC: .4byte gFastUnknownFn1Lookup
_0800A0F0:
	adds r1, r2, 0
	cmp r2, 0
	bge _0800A0F8
	adds r1, 0xFF
_0800A0F8:
	asrs r1, 8
	cmp r1, 0
	bne _0800A104
_0800A0FE:
	movs r0, 0x80
	lsls r0, 2
	b _0800A254
_0800A104:
	adds r0, r3, 0
	bl __divsi3
	adds r2, r0, 0
	cmp r2, 0xFF
	ble _0800A112
	movs r2, 0xFF
_0800A112:
	ldr r1, _0800A120
	lsls r0, r2, 2
	adds r0, r1
	ldr r1, [r0]
	movs r0, 0x40
	b _0800A250
	.align 2, 0
_0800A120: .4byte gFastUnknownFn1Lookup
_0800A124:
	negs r3, r3
	cmp r2, r3
	bge _0800A158
	adds r1, r3, 0
	cmp r3, 0
	bge _0800A132
	adds r1, 0xFF
_0800A132:
	asrs r1, 8
	cmp r1, 0
	beq _0800A166
	adds r0, r2, 0
	bl __divsi3
	adds r2, r0, 0
	cmp r2, 0xFF
	ble _0800A146
	movs r2, 0xFF
_0800A146:
	ldr r1, _0800A154
	lsls r0, r2, 2
	adds r0, r1
	ldr r1, [r0]
	movs r0, 0x80
	b _0800A250
	.align 2, 0
_0800A154: .4byte gFastUnknownFn1Lookup
_0800A158:
	adds r1, r2, 0
	cmp r2, 0
	bge _0800A160
	adds r1, 0xFF
_0800A160:
	asrs r1, 8
	cmp r1, 0
	bne _0800A16C
_0800A166:
	movs r0, 0xC0
	lsls r0, 3
	b _0800A254
_0800A16C:
	adds r0, r3, 0
	bl __divsi3
	adds r2, r0, 0
	cmp r2, 0xFF
	ble _0800A17A
	movs r2, 0xFF
_0800A17A:
	ldr r0, _0800A188
	lsls r1, r2, 2
	adds r1, r0
	ldr r0, [r1]
	adds r0, 0x40
	b _0800A252
	.align 2, 0
_0800A188: .4byte gFastUnknownFn1Lookup
_0800A18C:
	negs r2, r2
	cmp r3, 0
	ble _0800A1F0
	cmp r2, r3
	bge _0800A1BC
	asrs r1, r3, 8
	cmp r1, 0
	beq _0800A1CA
	adds r0, r2, 0
	bl __divsi3
	adds r2, r0, 0
	cmp r2, 0xFF
	ble _0800A1AA
	movs r2, 0xFF
_0800A1AA:
	ldr r1, _0800A1B8
	lsls r0, r2, 2
	adds r0, r1
	ldr r1, [r0]
	movs r0, 0x80
	lsls r0, 1
	b _0800A250
	.align 2, 0
_0800A1B8: .4byte gFastUnknownFn1Lookup
_0800A1BC:
	adds r1, r2, 0
	cmp r2, 0
	bge _0800A1C4
	adds r1, 0xFF
_0800A1C4:
	asrs r1, 8
	cmp r1, 0
	bne _0800A1D0
_0800A1CA:
	movs r0, 0xE0
	lsls r0, 4
	b _0800A254
_0800A1D0:
	adds r0, r3, 0
	bl __divsi3
	adds r2, r0, 0
	cmp r2, 0xFF
	ble _0800A1DE
	movs r2, 0xFF
_0800A1DE:
	ldr r0, _0800A1EC
	lsls r1, r2, 2
	adds r1, r0
	ldr r0, [r1]
	adds r0, 0xC0
	b _0800A252
	.align 2, 0
_0800A1EC: .4byte gFastUnknownFn1Lookup
_0800A1F0:
	negs r3, r3
	cmp r2, r3
	bge _0800A224
	adds r1, r3, 0
	cmp r3, 0
	bge _0800A1FE
	adds r1, 0xFF
_0800A1FE:
	asrs r1, 8
	cmp r1, 0
	beq _0800A232
	adds r0, r2, 0
	bl __divsi3
	adds r2, r0, 0
	cmp r2, 0xFF
	ble _0800A212
	movs r2, 0xFF
_0800A212:
	ldr r0, _0800A220
	lsls r1, r2, 2
	adds r1, r0
	ldr r0, [r1]
	adds r0, 0x80
	b _0800A252
	.align 2, 0
_0800A220: .4byte gFastUnknownFn1Lookup
_0800A224:
	adds r0, r2, 0
	cmp r0, 0
	bge _0800A22C
	adds r0, 0xFF
_0800A22C:
	asrs r1, r0, 8
	cmp r1, 0
	bne _0800A238
_0800A232:
	movs r0, 0xA0
	lsls r0, 4
	b _0800A254
_0800A238:
	adds r0, r3, 0
	bl __divsi3
	adds r2, r0, 0
	cmp r2, 0xFF
	ble _0800A246
	movs r2, 0xFF
_0800A246:
	ldr r1, _0800A258
	lsls r0, r2, 2
	adds r0, r1
	ldr r1, [r0]
	movs r0, 0xC0
_0800A250:
	subs r0, r1
_0800A252:
	lsls r0, 4
_0800A254:
	pop {r1}
	bx r1
	.align 2, 0
_0800A258: .4byte gFastUnknownFn1Lookup
	thumb_func_end sub_800A0B0

// invert signed lex pair
	thumb_func_start sub_800A25C
sub_800A25C:
	push {lr}
	adds r1, r0, 0
	ldr r0, [r1]
	mvns r2, r0
	str r2, [r1]
	ldr r0, [r1, 0x4]
	mvns r0, r0
	adds r0, 0x1
	str r0, [r1, 0x4]
	cmp r0, 0
	bne _0800A276
	adds r0, r2, 0x1
	str r0, [r1]
_0800A276:
	pop {r0}
	bx r0
	thumb_func_end sub_800A25C

// absolute value of signed lex pair
	thumb_func_start sub_800A27C
sub_800A27C:
	push {lr}
	adds r1, r0, 0
	ldr r0, [r1]
	cmp r0, 0
	bge _0800A29A
	mvns r2, r0
	str r2, [r1]
	ldr r0, [r1, 0x4]
	mvns r0, r0
	adds r0, 0x1
	str r0, [r1, 0x4]
	cmp r0, 0
	bne _0800A29A
	adds r0, r2, 0x1
	str r0, [r1]
_0800A29A:
	pop {r0}
	bx r0
	thumb_func_end sub_800A27C

	thumb_func_start sub_800A2A0
sub_800A2A0:
	push {lr}
	adds r1, r0, 0
	ldr r0, [r1]
	cmp r0, 0
	bne _0800A2B4
	ldr r0, [r1, 0x4]
	cmp r0, 0
	bne _0800A2B4
	movs r0, 0x1
	b _0800A2B6
_0800A2B4:
	movs r0, 0
_0800A2B6:
	pop {r1}
	bx r1
	thumb_func_end sub_800A2A0

	thumb_func_start sub_800A2BC
sub_800A2BC:
	push {lr}
	adds r2, r0, 0
	adds r3, r1, 0
	ldr r1, [r2]
	ldr r0, [r3]
	cmp r1, r0
	bne _0800A2D6
	ldr r1, [r2, 0x4]
	ldr r0, [r3, 0x4]
	cmp r1, r0
	bne _0800A2D6
	movs r0, 0x1
	b _0800A2D8
_0800A2D6:
	movs r0, 0
_0800A2D8:
	pop {r1}
	bx r1
	thumb_func_end sub_800A2BC

	thumb_func_start sub_800A2DC
sub_800A2DC:
	push {lr}
	ldr r0, [r0]
	cmp r0, 0
	blt _0800A2E8
	movs r0, 0
	b _0800A2EA
_0800A2E8:
	movs r0, 0x1
_0800A2EA:
	pop {r1}
	bx r1
	thumb_func_end sub_800A2DC

	thumb_func_start sub_800A2F0
sub_800A2F0:
	push {r4,r5,lr}
	adds r3, r0, 0
	adds r2, r1, 0
	ldr r4, [r3]
	lsrs r1, r4, 31
	ldr r5, [r2]
	cmp r5, 0
	bge _0800A304
	movs r0, 0x2
	orrs r1, r0
_0800A304:
	cmp r1, 0x1
	beq _0800A326
	cmp r1, 0x1
	ble _0800A314
	cmp r1, 0x2
	beq _0800A32A
	cmp r1, 0x3
	beq _0800A32E
_0800A314:
	ldr r1, [r3, 0x4]
	ldr r3, [r2, 0x4]
	adds r0, r4, 0
	adds r2, r5, 0
	bl u32_pair_less_than
	lsls r0, 24
	lsrs r0, 24
	b _0800A346
_0800A326:
	movs r0, 0x1
	b _0800A346
_0800A32A:
	movs r0, 0
	b _0800A346
_0800A32E:
	ldr r1, [r3, 0x4]
	ldr r3, [r2, 0x4]
	adds r0, r4, 0
	adds r2, r5, 0
	bl u32_pair_less_than
	movs r1, 0
	lsls r0, 24
	cmp r0, 0
	bne _0800A344
	movs r1, 0x1
_0800A344:
	adds r0, r1, 0
_0800A346:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_800A2F0

	thumb_func_start sub_800A34C
sub_800A34C:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x18
	adds r6, r0, 0
	ldr r0, [r1]
	str r0, [sp]
	ldr r0, [r1, 0x4]
	str r0, [sp, 0x4]
	ldr r0, [r2]
	str r0, [sp, 0x8]
	ldr r0, [r2, 0x4]
	add r5, sp, 0x8
	str r0, [r5, 0x4]
	mov r0, sp
	bl sub_800A2DC
	lsls r0, 24
	lsrs r0, 24
	mov r8, r0
	mov r10, r8
	adds r0, r5, 0
	bl sub_800A2DC
	lsls r0, 24
	lsrs r7, r0, 24
	mov r9, r7
	mov r0, sp
	bl sub_800A2A0
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0
	beq _0800A39A
	movs r0, 0
	str r0, [r6]
	b _0800A3DE
_0800A39A:
	adds r0, r5, 0
	bl sub_800A2A0
	lsls r0, 24
	cmp r0, 0
	beq _0800A3AC
	str r4, [r6]
	str r4, [r6, 0x4]
	b _0800A3E0
_0800A3AC:
	mov r0, r8
	cmp r0, 0
	beq _0800A3B8
	mov r0, sp
	bl sub_800A25C
_0800A3B8:
	cmp r7, 0
	beq _0800A3C2
	adds r0, r5, 0
	bl sub_800A25C
_0800A3C2:
	add r4, sp, 0x10
	adds r0, r4, 0
	mov r1, sp
	adds r2, r5, 0
	bl sub_800A4E4
	cmp r10, r9
	beq _0800A3D8
	adds r0, r4, 0
	bl sub_800A25C
_0800A3D8:
	ldr r0, [sp, 0x10]
	str r0, [r6]
	ldr r0, [r4, 0x4]
_0800A3DE:
	str r0, [r6, 0x4]
_0800A3E0:
	add sp, 0x18
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_800A34C

	thumb_func_start sub_800A3F0
sub_800A3F0:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x18
	adds r6, r0, 0
	ldr r0, [r1]
	str r0, [sp]
	ldr r0, [r1, 0x4]
	str r0, [sp, 0x4]
	ldr r0, [r2]
	str r0, [sp, 0x8]
	ldr r0, [r2, 0x4]
	add r5, sp, 0x8
	str r0, [r5, 0x4]
	mov r0, sp
	bl sub_800A2DC
	lsls r0, 24
	lsrs r0, 24
	mov r8, r0
	mov r10, r8
	adds r0, r5, 0
	bl sub_800A2DC
	lsls r0, 24
	lsrs r7, r0, 24
	mov r9, r7
	adds r0, r5, 0
	bl sub_800A2A0
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0
	beq _0800A448
	ldr r0, _0800A444
	str r0, [r6]
	movs r0, 0x1
	negs r0, r0
	b _0800A48C
	.align 2, 0
_0800A444: .4byte 0x7fffffff
_0800A448:
	mov r0, sp
	bl sub_800A2A0
	lsls r0, 24
	cmp r0, 0
	beq _0800A45A
	str r4, [r6]
	str r4, [r6, 0x4]
	b _0800A48E
_0800A45A:
	mov r0, r8
	cmp r0, 0
	beq _0800A466
	mov r0, sp
	bl sub_800A25C
_0800A466:
	cmp r7, 0
	beq _0800A470
	adds r0, r5, 0
	bl sub_800A25C
_0800A470:
	add r4, sp, 0x10
	adds r0, r4, 0
	mov r1, sp
	adds r2, r5, 0
	bl sub_800A5A4
	cmp r10, r9
	beq _0800A486
	adds r0, r4, 0
	bl sub_800A25C
_0800A486:
	ldr r0, [sp, 0x10]
	str r0, [r6]
	ldr r0, [r4, 0x4]
_0800A48C:
	str r0, [r6, 0x4]
_0800A48E:
	add sp, 0x18
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_800A3F0

	thumb_func_start sub_800A4A0
sub_800A4A0:
	push {r4,r5,lr}
	sub sp, 0x10
	adds r5, r0, 0
	ldr r0, [r5]
	str r0, [sp]
	ldr r0, [r5, 0x4]
	str r0, [sp, 0x4]
	mov r0, sp
	bl sub_800A2A0
	lsls r0, 24
	cmp r0, 0
	beq _0800A4C0
	movs r0, 0
	str r0, [r5]
	b _0800A4D8
_0800A4C0:
	mov r0, sp
	bl sub_800A27C
	add r4, sp, 0x8
	adds r0, r4, 0
	mov r1, sp
	mov r2, sp
	bl sub_800A4E4
	ldr r0, [sp, 0x8]
	str r0, [r5]
	ldr r0, [r4, 0x4]
_0800A4D8:
	str r0, [r5, 0x4]
	add sp, 0x10
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_800A4A0

	thumb_func_start sub_800A4E4
sub_800A4E4:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	mov r8, r0
	adds r5, r1, 0
	adds r6, r2, 0
	adds r0, r5, 0
	bl sub_800A2A0
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0
	beq _0800A50C
	movs r0, 0
	mov r1, r8
	str r0, [r1]
	str r0, [r1, 0x4]
	b _0800A596
_0800A50C:
	adds r0, r6, 0
	bl sub_800A2A0
	lsls r0, 24
	cmp r0, 0
	beq _0800A520
	mov r7, r8
	str r4, [r7]
	str r4, [r7, 0x4]
	b _0800A596
_0800A520:
	ldr r1, [r5]
	ldr r4, [r5, 0x4]
	ldr r0, [r6]
	mov r10, r0
	ldr r2, [r6, 0x4]
	movs r6, 0
	movs r5, 0
	movs r7, 0x80
	lsls r7, 24
	mov r9, r7
	movs r0, 0x3F
	mov r12, r0
_0800A538:
	adds r3, r5, 0
	movs r0, 0x1
	ands r0, r2
	cmp r0, 0
	beq _0800A54C
	adds r5, r4
	adds r6, r1
	cmp r3, r5
	bls _0800A54C
	adds r6, 0x1
_0800A54C:
	lsrs r2, 1
	movs r3, 0x1
	mov r0, r10
	ands r0, r3
	cmp r0, 0
	beq _0800A55C
	mov r7, r9
	orrs r2, r7
_0800A55C:
	mov r0, r10
	lsrs r0, 1
	mov r10, r0
	lsls r1, 1
	adds r0, r4, 0
	mov r7, r9
	ands r0, r7
	cmp r0, 0
	beq _0800A570
	orrs r1, r3
_0800A570:
	lsls r4, 1
	movs r0, 0x1
	negs r0, r0
	add r12, r0
	mov r7, r12
	cmp r7, 0
	bge _0800A538
	lsrs r1, r5, 15
	ands r1, r3
	lsrs r5, 16
	lsls r0, r6, 16
	orrs r5, r0
	lsrs r6, 16
	cmp r1, 0
	beq _0800A590
	adds r5, 0x1
_0800A590:
	mov r0, r8
	str r6, [r0]
	str r5, [r0, 0x4]
_0800A596:
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_800A4E4

	thumb_func_start sub_800A5A4
sub_800A5A4:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x14
	str r0, [sp]
	adds r5, r1, 0
	mov r8, r2
	mov r0, r8
	bl sub_800A2A0
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0
	beq _0800A5D8
	ldr r0, _0800A5D4
	ldr r1, [sp]
	str r0, [r1]
	movs r0, 0x1
	negs r0, r0
	str r0, [r1, 0x4]
	b _0800A6BE
	.align 2, 0
_0800A5D4: .4byte 0x7fffffff
_0800A5D8:
	adds r0, r5, 0
	bl sub_800A2A0
	lsls r0, 24
	cmp r0, 0
	beq _0800A5EC
	ldr r2, [sp]
	str r4, [r2]
	str r4, [r2, 0x4]
	b _0800A6BE
_0800A5EC:
	ldr r0, [r5]
	lsls r7, r0, 16
	ldr r1, [r5, 0x4]
	lsrs r0, r1, 16
	orrs r7, r0
	lsls r6, r1, 16
	movs r0, 0x80
	lsls r0, 8
	orrs r6, r0
	mov r0, r8
	ldr r0, [r0]
	str r0, [sp, 0x4]
	mov r1, r8
	ldr r1, [r1, 0x4]
	str r1, [sp, 0x8]
	movs r2, 0
	str r2, [sp, 0xC]
	mov r9, r2
	movs r5, 0
	movs r4, 0
	movs r0, 0x80
	lsls r0, 24
	mov r10, r0
	movs r1, 0x1
	mov r8, r1
	movs r2, 0x3F
	str r2, [sp, 0x10]
_0800A622:
	lsls r5, 1
	adds r0, r4, 0
	mov r1, r10
	ands r0, r1
	cmp r0, 0
	beq _0800A632
	mov r2, r8
	orrs r5, r2
_0800A632:
	movs r1, 0x2
	negs r1, r1
	lsls r4, 1
	adds r0, r7, 0
	mov r2, r10
	ands r0, r2
	cmp r0, 0
	beq _0800A646
	mov r0, r8
	orrs r4, r0
_0800A646:
	lsls r7, 1
	adds r0, r6, 0
	mov r2, r10
	ands r0, r2
	cmp r0, 0
	beq _0800A656
	mov r0, r8
	orrs r7, r0
_0800A656:
	lsls r6, 1
	ands r6, r1
	adds r0, r5, 0
	adds r1, r4, 0
	ldr r2, [sp, 0x4]
	ldr r3, [sp, 0x8]
	bl u32_pair_less_than
	lsls r0, 24
	cmp r0, 0
	bne _0800A680
	adds r0, r4, 0
	movs r1, 0x1
	ldr r2, [sp, 0x8]
	subs r4, r2
	ldr r2, [sp, 0x4]
	subs r5, r2
	cmp r0, r4
	bcs _0800A682
	subs r5, 0x1
	b _0800A682
_0800A680:
	movs r1, 0
_0800A682:
	ldr r0, [sp, 0xC]
	lsls r0, 1
	str r0, [sp, 0xC]
	mov r0, r9
	mov r2, r10
	ands r0, r2
	cmp r0, 0
	beq _0800A69A
	ldr r0, [sp, 0xC]
	mov r2, r8
	orrs r0, r2
	str r0, [sp, 0xC]
_0800A69A:
	mov r0, r9
	lsls r0, 1
	mov r9, r0
	cmp r1, 0
	beq _0800A6AA
	mov r1, r8
	orrs r0, r1
	mov r9, r0
_0800A6AA:
	ldr r2, [sp, 0x10]
	subs r2, 0x1
	str r2, [sp, 0x10]
	cmp r2, 0
	bge _0800A622
	ldr r0, [sp, 0xC]
	ldr r1, [sp]
	str r0, [r1]
	mov r2, r9
	str r2, [r1, 0x4]
_0800A6BE:
	add sp, 0x14
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_800A5A4

	thumb_func_start sub_800A6D0
sub_800A6D0:
	push {r4,lr}
	adds r4, r0, 0
	ldr r3, [r1]
	ldr r0, [r2]
	adds r3, r0
	ldr r1, [r1, 0x4]
	ldr r0, [r2, 0x4]
	adds r0, r1, r0
	cmp r0, r1
	bcs _0800A6E6
	adds r3, 0x1
_0800A6E6:
	str r3, [r4]
	str r0, [r4, 0x4]
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_800A6D0

	thumb_func_start sub_800A6F0
sub_800A6F0:
	push {r4,lr}
	adds r4, r0, 0
	ldr r3, [r1]
	ldr r0, [r2]
	subs r3, r0
	ldr r1, [r1, 0x4]
	ldr r0, [r2, 0x4]
	subs r0, r1, r0
	cmp r0, r1
	bls _0800A706
	subs r3, 0x1
_0800A706:
	str r3, [r4]
	str r0, [r4, 0x4]
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_800A6F0

	thumb_func_start sub_800A710
sub_800A710:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0x18
	mov r8, r0
	adds r6, r2, 0
	ldr r0, [r1]
	str r0, [sp]
	ldr r0, [r1, 0x4]
	str r0, [sp, 0x4]
	adds r4, r6, 0
	cmp r6, 0
	bge _0800A72C
	negs r4, r6
_0800A72C:
	movs r0, 0
	str r0, [sp, 0x8]
	movs r1, 0x80
	lsls r1, 9
	add r0, sp, 0x8
	str r1, [r0, 0x4]
	adds r7, r0, 0
	cmp r4, 0
	beq _0800A75E
	adds r5, r7, 0
_0800A740:
	movs r0, 0x1
	ands r0, r4
	cmp r0, 0
	beq _0800A752
	adds r0, r5, 0
	adds r1, r5, 0
	mov r2, sp
	bl sub_800A34C
_0800A752:
	mov r0, sp
	bl sub_800A4A0
	asrs r4, 1
	cmp r4, 0
	bne _0800A740
_0800A75E:
	cmp r6, 0
	bge _0800A776
	movs r0, 0
	str r0, [sp, 0x10]
	movs r0, 0x80
	lsls r0, 9
	add r1, sp, 0x10
	str r0, [r1, 0x4]
	adds r0, r7, 0
	adds r2, r7, 0
	bl sub_800A3F0
_0800A776:
	ldr r0, [sp, 0x8]
	mov r1, r8
	str r0, [r1]
	ldr r0, [r7, 0x4]
	str r0, [r1, 0x4]
	add sp, 0x18
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_800A710

	thumb_func_start sub_800A78C
sub_800A78C:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x20
	mov r10, r0
	ldr r0, [r1]
	ldr r1, [r1, 0x4]
	str r0, [sp]
	str r1, [sp, 0x4]
	ldr r0, [r2]
	ldr r1, [r2, 0x4]
	str r0, [sp, 0x8]
	str r1, [sp, 0xC]
	mov r0, sp
	bl sub_800A27C
	add r4, sp, 0x8
	adds r0, r4, 0
	bl sub_800A27C
	mov r0, sp
	adds r1, r4, 0
	bl sub_800A2F0
	lsls r0, 24
	mov r8, r4
	cmp r0, 0
	beq _0800A7DC
	ldr r2, [sp]
	ldr r3, [sp, 0x4]
	str r2, [sp, 0x10]
	str r3, [sp, 0x14]
	ldr r0, [sp, 0x8]
	ldr r1, [sp, 0xC]
	str r0, [sp]
	str r1, [sp, 0x4]
	str r2, [sp, 0x8]
	str r3, [sp, 0xC]
_0800A7DC:
	mov r0, r8
	bl sub_800A2A0
	lsls r0, 24
	cmp r0, 0
	bne _0800A878
	movs r0, 0
	mov r9, r0
	add r7, sp, 0x10
	add r6, sp, 0x18
	b _0800A800
_0800A7F2:
	mov r0, r8
	mov r1, r8
	adds r2, r7, 0
	bl sub_800A34C
	movs r2, 0x1
	add r9, r2
_0800A800:
	adds r4, r7, 0
	mov r1, r8
	adds r0, r4, 0
	mov r2, sp
	bl sub_800A3F0
	adds r0, r4, 0
	bl sub_800A4A0
	ldr r0, [sp, 0x10]
	str r0, [sp, 0x18]
	ldr r1, [r4, 0x4]
	movs r0, 0x80
	lsls r0, 11
	adds r1, r0
	adds r5, r6, 0
	str r1, [r5, 0x4]
	ldr r0, [r4, 0x4]
	cmp r1, r0
	bcs _0800A82E
	ldr r0, [sp, 0x18]
	adds r0, 0x1
	str r0, [sp, 0x18]
_0800A82E:
	adds r0, r4, 0
	adds r1, r4, 0
	adds r2, r5, 0
	bl sub_800A3F0
	adds r0, r5, 0
	mov r1, sp
	adds r2, r4, 0
	bl sub_800A34C
	ldr r0, [sp, 0x18]
	lsls r1, r0, 1
	str r1, [sp, 0x18]
	ldr r0, [r5, 0x4]
	cmp r0, 0
	bge _0800A854
	movs r0, 0x1
	orrs r1, r0
	str r1, [sp, 0x18]
_0800A854:
	ldr r0, [r6, 0x4]
	lsls r0, 1
	str r0, [r6, 0x4]
	ldr r2, [sp, 0x4]
	ldr r1, [sp]
	ldr r0, [sp, 0x18]
	adds r1, r0
	str r1, [sp]
	ldr r0, [r6, 0x4]
	adds r0, r2, r0
	str r0, [sp, 0x4]
	cmp r2, r0
	bls _0800A872
	adds r0, r1, 0x1
	str r0, [sp]
_0800A872:
	mov r2, r9
	cmp r2, 0x2
	bne _0800A7F2
_0800A878:
	ldr r0, [sp]
	ldr r1, [sp, 0x4]
	mov r2, r10
	str r0, [r2]
	str r1, [r2, 0x4]
	add sp, 0x20
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_800A78C

	.align 2, 0 @ Don't pad with nop.
