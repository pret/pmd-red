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

	thumb_func_start sub_800290C
sub_800290C:
	push {lr}
	ldr r3, [r0]
	cmp r3, r1
	ble _08002918
	str r1, [r0]
	b _08002920
_08002918:
	negs r2, r1
	cmp r3, r2
	bge _08002920
	str r2, [r0]
_08002920:
	ldr r2, [r0, 0x4]
	cmp r2, r1
	bgt _0800292C
	negs r1, r1
	cmp r2, r1
	bge _0800292E
_0800292C:
	str r1, [r0, 0x4]
_0800292E:
	pop {r0}
	bx r0
	thumb_func_end sub_800290C

	thumb_func_start sub_8002934
sub_8002934:
	push {r4-r6,lr}
	mov r6, r10
	mov r5, r9
	mov r4, r8
	push {r4-r6}
	mov r10, r0
	adds r6, r1, 0
	mov r8, r2
	adds r4, r3, 0
	ldr r5, [sp, 0x1C]
	adds r0, r4, r5
	mov r9, r0
	ldr r0, [r6]
	muls r0, r4
	ldr r1, [r2]
	muls r1, r5
	adds r0, r1
	mov r1, r9
	bl __divsi3
	mov r1, r10
	str r0, [r1]
	ldr r0, [r6, 0x4]
	muls r0, r4
	mov r2, r8
	ldr r1, [r2, 0x4]
	muls r1, r5
	adds r0, r1
	mov r1, r9
	bl __divsi3
	mov r1, r10
	str r0, [r1, 0x4]
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end sub_8002934

	thumb_func_start sub_8002984
sub_8002984:
	push {r4,lr}
	lsls r0, 24
	asrs r4, r0, 24
	lsls r1, 24
	lsrs r1, 24
	subs r0, r1, 0x1
	cmp r0, 0x8
	bhi _08002A68
	lsls r0, 2
	ldr r1, _080029A0
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080029A0: .4byte _080029A4
	.align 2, 0
_080029A4:
	.4byte _080029C8
	.4byte _080029D0
	.4byte _080029D8
	.4byte _080029E0
	.4byte _080029E8
	.4byte _080029F4
	.4byte _08002A34
	.4byte _08002A4E
	.4byte _08002A5E
_080029C8:
	cmp r4, 0
	blt _08002A68
	adds r4, 0x7
	b _080029EE
_080029D0:
	cmp r4, 0
	blt _08002A68
	adds r4, 0x1
	b _080029EE
_080029D8:
	cmp r4, 0
	blt _08002A68
	adds r4, 0x6
	b _080029EE
_080029E0:
	cmp r4, 0
	blt _08002A68
	adds r4, 0x2
	b _080029EE
_080029E8:
	cmp r4, 0
	blt _08002A68
	adds r4, 0x4
_080029EE:
	movs r0, 0x7
	ands r4, r0
	b _08002A68
_080029F4:
	movs r0, 0x1
	ands r0, r4
	cmp r0, 0
	beq _08002A18
	movs r0, 0x2
	bl OtherRandInt
	adds r1, r4, 0x7
	lsls r0, 1
	adds r1, r0
	adds r0, r1, 0
	cmp r1, 0
	bge _08002A10
	adds r0, r1, 0x7
_08002A10:
	asrs r0, 3
	lsls r0, 3
	subs r0, r1, r0
	b _08002A64
_08002A18:
	movs r0, 0x3
	bl OtherRandInt
	adds r1, r4, 0x6
	lsls r0, 1
	adds r1, r0
	adds r0, r1, 0
	cmp r1, 0
	bge _08002A2C
	adds r0, r1, 0x7
_08002A2C:
	asrs r0, 3
	lsls r0, 3
	subs r0, r1, r0
	b _08002A64
_08002A34:
	movs r0, 0x3
	bl OtherRandInt
	adds r1, r4, 0x7
	adds r1, r0
	adds r0, r1, 0
	cmp r1, 0
	bge _08002A46
	adds r0, r1, 0x7
_08002A46:
	asrs r0, 3
	lsls r0, 3
	subs r0, r1, r0
	b _08002A64
_08002A4E:
	movs r0, 0x8
	bl OtherRandInt
	movs r2, 0x2
	negs r2, r2
	adds r1, r2, 0
	ands r0, r1
	b _08002A64
_08002A5E:
	movs r0, 0x8
	bl OtherRandInt
_08002A64:
	lsls r0, 24
	asrs r4, r0, 24
_08002A68:
	adds r0, r4, 0
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_8002984

	thumb_func_start sub_8002A70
sub_8002A70:
	push {r4,lr}
	lsls r0, 24
	asrs r3, r0, 24
	lsls r1, 24
	asrs r4, r1, 24
	lsls r2, 24
	lsrs r0, r2, 24
	cmp r3, r4
	beq _08002AFC
	subs r0, 0x1
	cmp r0, 0xA
	bhi _08002AFC
	lsls r0, 2
	ldr r1, _08002A94
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08002A94: .4byte _08002A98
	.align 2, 0
_08002A98:
	.4byte _08002AC4
	.4byte _08002ACC
	.4byte _08002AD4
	.4byte _08002ADC
	.4byte _08002AFC
	.4byte _08002AFC
	.4byte _08002AFC
	.4byte _08002AFC
	.4byte _08002AFC
	.4byte _08002AF2
	.4byte _08002AE8
_08002AC4:
	cmp r3, 0
	blt _08002AFC
	adds r3, 0x7
	b _08002AE2
_08002ACC:
	cmp r3, 0
	blt _08002AFC
	adds r3, 0x1
	b _08002AE2
_08002AD4:
	cmp r3, 0
	blt _08002AFC
	adds r3, 0x6
	b _08002AE2
_08002ADC:
	cmp r3, 0
	blt _08002AFC
	adds r3, 0x2
_08002AE2:
	movs r0, 0x7
	ands r3, r0
	b _08002AFC
_08002AE8:
	adds r0, r3, 0
	adds r1, r4, 0
	bl sub_8002B04
	adds r3, r0, 0
_08002AF2:
	adds r0, r3, 0
	adds r1, r4, 0
	bl sub_8002B04
	adds r3, r0, 0
_08002AFC:
	adds r0, r3, 0
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_8002A70

	thumb_func_start sub_8002B04
sub_8002B04:
	push {lr}
	lsls r0, 24
	asrs r2, r0, 24
	lsls r1, 24
	asrs r1, 24
	movs r0, 0x1
	negs r0, r0
	cmp r1, r0
	beq _08002B56
	adds r0, r2, 0
	subs r0, 0x8
	subs r1, r0
	adds r0, r1, 0
	cmp r1, 0
	bge _08002B24
	adds r0, r1, 0x7
_08002B24:
	asrs r0, 3
	lsls r0, 3
	subs r0, r1, r0
	cmp r0, 0
	beq _08002B56
	cmp r0, 0x3
	bgt _08002B40
	adds r1, r2, 0x1
	adds r0, r1, 0
	cmp r1, 0
	bge _08002B4C
	adds r0, r2, 0
	adds r0, 0x8
	b _08002B4C
_08002B40:
	adds r1, r2, 0x7
	adds r0, r1, 0
	cmp r1, 0
	bge _08002B4C
	adds r0, r2, 0
	adds r0, 0xE
_08002B4C:
	asrs r0, 3
	lsls r0, 3
	subs r0, r1, r0
	lsls r0, 24
	asrs r2, r0, 24
_08002B56:
	adds r0, r2, 0
	pop {r1}
	bx r1
	thumb_func_end sub_8002B04

	thumb_func_start sub_8002B5C
sub_8002B5C:
	push {lr}
	lsls r0, 24
	asrs r2, r0, 24
	lsls r1, 24
	asrs r1, 24
	movs r0, 0x1
	negs r0, r0
	cmp r1, r0
	beq _08002BAE
	adds r0, r2, 0
	subs r0, 0x8
	subs r1, r0
	adds r0, r1, 0
	cmp r1, 0
	bge _08002B7C
	adds r0, r1, 0x7
_08002B7C:
	asrs r0, 3
	lsls r0, 3
	subs r0, r1, r0
	cmp r0, 0
	beq _08002BAE
	cmp r0, 0x3
	bgt _08002B98
	adds r1, r2, 0x2
	adds r0, r1, 0
	cmp r1, 0
	bge _08002BA4
	adds r0, r2, 0
	adds r0, 0x9
	b _08002BA4
_08002B98:
	adds r1, r2, 0x6
	adds r0, r1, 0
	cmp r1, 0
	bge _08002BA4
	adds r0, r2, 0
	adds r0, 0xD
_08002BA4:
	asrs r0, 3
	lsls r0, 3
	subs r0, r1, r0
	lsls r0, 24
	asrs r2, r0, 24
_08002BAE:
	movs r0, 0x6
	ands r2, r0
	adds r0, r2, 0
	pop {r1}
	bx r1
	thumb_func_end sub_8002B5C

	thumb_func_start sub_8002BB8
sub_8002BB8:
	push {r4,r5,lr}
	lsls r1, 24
	asrs r1, 21
	ldr r3, _08002BD8
	adds r1, r3
	ldr r5, [r1]
	adds r3, r5, 0
	muls r3, r2
	ldr r1, [r1, 0x4]
	adds r4, r1, 0
	muls r4, r2
	str r3, [r0]
	str r4, [r0, 0x4]
	pop {r4,r5}
	pop {r2}
	bx r2
	.align 2, 0
_08002BD8: .4byte gUnknown_80B7E3C
	thumb_func_end sub_8002BB8

	thumb_func_start sub_8002BDC
sub_8002BDC:
	push {lr}
	ldr r1, [r0]
	cmp r1, 0
	bge _08002BFA
	ldr r0, [r0, 0x4]
	cmp r0, 0
	bge _08002BEE
	movs r0, 0x5
	b _08002C2A
_08002BEE:
	cmp r0, 0
	ble _08002BF6
	movs r0, 0x7
	b _08002C2A
_08002BF6:
	movs r0, 0x6
	b _08002C2A
_08002BFA:
	cmp r1, 0
	ble _08002C14
	ldr r0, [r0, 0x4]
	cmp r0, 0
	bge _08002C08
	movs r0, 0x3
	b _08002C2A
_08002C08:
	cmp r0, 0
	ble _08002C10
	movs r0, 0x1
	b _08002C2A
_08002C10:
	movs r0, 0x2
	b _08002C2A
_08002C14:
	ldr r0, [r0, 0x4]
	cmp r0, 0
	bge _08002C1E
	movs r0, 0x4
	b _08002C2A
_08002C1E:
	cmp r0, 0
	bgt _08002C28
	movs r0, 0x1
	negs r0, r0
	b _08002C2A
_08002C28:
	movs r0, 0
_08002C2A:
	pop {r1}
	bx r1
	thumb_func_end sub_8002BDC

	thumb_func_start sub_8002C30
sub_8002C30:
	push {lr}
	ldr r1, [r0, 0x4]
	cmp r1, 0
	bge _08002C3C
	movs r0, 0x4
	b _08002C5A
_08002C3C:
	cmp r1, 0
	ble _08002C44
	movs r0, 0
	b _08002C5A
_08002C44:
	ldr r0, [r0]
	cmp r0, 0
	bge _08002C4E
	movs r0, 0x6
	b _08002C5A
_08002C4E:
	cmp r0, 0
	bgt _08002C58
	movs r0, 0x1
	negs r0, r0
	b _08002C5A
_08002C58:
	movs r0, 0x2
_08002C5A:
	pop {r1}
	bx r1
	thumb_func_end sub_8002C30

	thumb_func_start sub_8002C60
sub_8002C60:
	push {r4,r5,lr}
	adds r4, r0, 0
	ldr r0, [r4]
	cmp r0, 0
	bge _08002C6C
	negs r0, r0
_08002C6C:
	adds r1, r0, 0
	ldr r3, [r4, 0x4]
	adds r5, r3, 0
	cmp r3, 0
	bge _08002C78
	negs r5, r3
_08002C78:
	adds r2, r5, 0
	ldr r4, [r4]
	cmp r4, 0
	bge _08002CA8
	cmp r3, 0
	bge _08002C94
	lsls r0, 1
	cmp r2, r0
	bgt _08002CD8
	lsls r0, r5, 1
	cmp r1, r0
	bgt _08002CA0
	movs r0, 0x5
	b _08002CE8
_08002C94:
	lsls r0, 1
	cmp r2, r0
	bgt _08002CE6
	lsls r0, r5, 1
	cmp r1, r0
	ble _08002CA4
_08002CA0:
	movs r0, 0x6
	b _08002CE8
_08002CA4:
	movs r0, 0x7
	b _08002CE8
_08002CA8:
	cmp r4, 0
	ble _08002CD4
	cmp r3, 0
	bge _08002CC0
	lsls r0, 1
	cmp r2, r0
	bgt _08002CD8
	lsls r0, r5, 1
	cmp r1, r0
	bgt _08002CCC
	movs r0, 0x3
	b _08002CE8
_08002CC0:
	lsls r0, 1
	cmp r2, r0
	bgt _08002CE6
	lsls r0, r5, 1
	cmp r1, r0
	ble _08002CD0
_08002CCC:
	movs r0, 0x2
	b _08002CE8
_08002CD0:
	movs r0, 0x1
	b _08002CE8
_08002CD4:
	cmp r3, 0
	bge _08002CDC
_08002CD8:
	movs r0, 0x4
	b _08002CE8
_08002CDC:
	cmp r3, 0
	bgt _08002CE6
	movs r0, 0x1
	negs r0, r0
	b _08002CE8
_08002CE6:
	movs r0, 0
_08002CE8:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_8002C60

	thumb_func_start sub_8002CF0
sub_8002CF0:
	push {r4,lr}
	adds r4, r0, 0
	ldr r3, [r4]
	cmp r3, 0
	bge _08002CFC
	negs r3, r3
_08002CFC:
	adds r1, r3, 0
	ldr r3, [r4, 0x4]
	adds r0, r3, 0
	cmp r3, 0
	bge _08002D08
	negs r0, r3
_08002D08:
	adds r2, r0, 0
	ldr r0, [r4]
	cmp r0, 0
	bge _08002D22
	cmp r3, 0
	bge _08002D1A
	cmp r2, r1
	bgt _08002D3C
	b _08002D1E
_08002D1A:
	cmp r2, r1
	bgt _08002D4A
_08002D1E:
	movs r0, 0x6
	b _08002D4C
_08002D22:
	cmp r0, 0
	ble _08002D38
	cmp r3, 0
	bge _08002D30
	cmp r2, r1
	bgt _08002D3C
	b _08002D34
_08002D30:
	cmp r2, r1
	bgt _08002D4A
_08002D34:
	movs r0, 0x2
	b _08002D4C
_08002D38:
	cmp r3, 0
	bge _08002D40
_08002D3C:
	movs r0, 0x4
	b _08002D4C
_08002D40:
	cmp r3, 0
	bgt _08002D4A
	movs r0, 0x1
	negs r0, r0
	b _08002D4C
_08002D4A:
	movs r0, 0
_08002D4C:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_8002CF0

	thumb_func_start sub_8002D54
sub_8002D54:
	push {r4,r5,lr}
	sub sp, 0x8
	adds r4, r1, 0
	adds r5, r3, 0
	ldr r3, [r2]
	ldr r1, [r0]
	subs r3, r1
	str r3, [sp]
	ldr r1, [r2, 0x4]
	ldr r0, [r0, 0x4]
	subs r1, r0
	str r1, [sp, 0x4]
	adds r2, r3, 0
	cmp r2, 0
	blt _08002D8A
	adds r2, 0x1
	ldr r0, [r4]
	ldr r1, [r5]
	adds r0, r1
	lsrs r1, r0, 31
	adds r0, r1
	asrs r0, 1
	subs r2, r0
	str r2, [sp]
	cmp r2, 0
	bge _08002DA4
	b _08002DA0
_08002D8A:
	subs r2, r3, 0x1
	ldr r0, [r4]
	ldr r1, [r5]
	adds r0, r1
	lsrs r1, r0, 31
	adds r0, r1
	asrs r0, 1
	adds r2, r0
	str r2, [sp]
	cmp r2, 0
	ble _08002DA4
_08002DA0:
	movs r0, 0
	str r0, [sp]
_08002DA4:
	ldr r2, [sp, 0x4]
	cmp r2, 0
	blt _08002DC2
	adds r2, 0x1
	ldr r0, [r4, 0x4]
	ldr r1, [r5, 0x4]
	adds r0, r1
	lsrs r1, r0, 31
	adds r0, r1
	asrs r0, 1
	subs r2, r0
	str r2, [sp, 0x4]
	cmp r2, 0
	bge _08002DDC
	b _08002DD8
_08002DC2:
	subs r2, 0x1
	ldr r0, [r4, 0x4]
	ldr r1, [r5, 0x4]
	adds r0, r1
	lsrs r1, r0, 31
	adds r0, r1
	asrs r0, 1
	adds r2, r0
	str r2, [sp, 0x4]
	cmp r2, 0
	ble _08002DDC
_08002DD8:
	movs r0, 0
	str r0, [sp, 0x4]
_08002DDC:
	mov r0, sp
	bl sub_8002CF0
	lsls r0, 24
	asrs r0, 24
	add sp, 0x8
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_8002D54

	thumb_func_start sub_8002DF0
sub_8002DF0:
	push {r4,r5,lr}
	sub sp, 0x8
	adds r4, r1, 0
	adds r5, r3, 0
	ldr r3, [r2]
	ldr r1, [r0]
	subs r3, r1
	str r3, [sp]
	ldr r1, [r2, 0x4]
	ldr r0, [r0, 0x4]
	subs r1, r0
	str r1, [sp, 0x4]
	adds r2, r3, 0
	cmp r2, 0
	blt _08002E26
	adds r2, 0x1
	ldr r0, [r4]
	ldr r1, [r5]
	adds r0, r1
	lsrs r1, r0, 31
	adds r0, r1
	asrs r0, 1
	subs r2, r0
	str r2, [sp]
	cmp r2, 0
	bge _08002E40
	b _08002E3C
_08002E26:
	subs r2, r3, 0x1
	ldr r0, [r4]
	ldr r1, [r5]
	adds r0, r1
	lsrs r1, r0, 31
	adds r0, r1
	asrs r0, 1
	adds r2, r0
	str r2, [sp]
	cmp r2, 0
	ble _08002E40
_08002E3C:
	movs r0, 0
	str r0, [sp]
_08002E40:
	ldr r2, [sp, 0x4]
	cmp r2, 0
	blt _08002E5E
	adds r2, 0x1
	ldr r0, [r4, 0x4]
	ldr r1, [r5, 0x4]
	adds r0, r1
	lsrs r1, r0, 31
	adds r0, r1
	asrs r0, 1
	subs r2, r0
	str r2, [sp, 0x4]
	cmp r2, 0
	bge _08002E78
	b _08002E74
_08002E5E:
	subs r2, 0x1
	ldr r0, [r4, 0x4]
	ldr r1, [r5, 0x4]
	adds r0, r1
	lsrs r1, r0, 31
	adds r0, r1
	asrs r0, 1
	adds r2, r0
	str r2, [sp, 0x4]
	cmp r2, 0
	ble _08002E78
_08002E74:
	movs r0, 0
	str r0, [sp, 0x4]
_08002E78:
	mov r0, sp
	bl sub_8002C60
	lsls r0, 24
	asrs r0, 24
	add sp, 0x8
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_8002DF0

	.align 2, 0 @ Don't pad with nop.
