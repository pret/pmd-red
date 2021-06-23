	.include "constants/gba_constants.inc"
	.include "asm/macros.inc"

	.syntax unified

	.text

	thumb_func_start sub_8094D28
sub_8094D28:
	push {r4-r7,lr}
	ldr r2, _08094D64
	str r0, [r2]
	ldr r1, _08094D68
	movs r0, 0x1
	str r0, [r1]
	ldr r7, _08094D6C
	adds r5, r2, 0
	adds r4, r1, 0
	ldr r6, _08094D70
_08094D3C:
	ldr r2, [r4]
	lsls r3, r2, 2
	adds r3, r5
	subs r0, r2, 0x1
	lsls r0, 2
	adds r0, r5
	ldr r0, [r0]
	lsrs r1, r0, 30
	eors r0, r1
	muls r0, r6
	adds r0, r2
	str r0, [r3]
	adds r2, 0x1
	str r2, [r4]
	cmp r2, r7
	ble _08094D3C
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_08094D64: .4byte gUnknown_3001198
_08094D68: .4byte gUnknown_203B470
_08094D6C: .4byte 0x0000026f
_08094D70: .4byte 0x6c078965
	thumb_func_end sub_8094D28

	thumb_func_start sub_8094D74
sub_8094D74:
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	mov r8, r0
	adds r7, r1, 0
	ldr r0, _08094E34
	bl sub_8094D28
	movs r4, 0x1
	movs r5, 0
	adds r3, r7, 0
	movs r0, 0x9C
	lsls r0, 2
	cmp r3, r0
	bge _08094D96
	adds r3, r0, 0
_08094D96:
	ldr r6, _08094E38
	cmp r3, 0
	beq _08094DE2
	mov r9, r6
	ldr r0, _08094E3C
	adds r0, r6
	mov r12, r0
	adds r2, r6, 0
_08094DA6:
	ldr r1, [r2]
	lsrs r0, r1, 30
	eors r1, r0
	ldr r0, _08094E40
	muls r0, r1
	ldr r1, [r2, 0x4]
	eors r1, r0
	lsls r0, r5, 2
	add r0, r8
	ldr r0, [r0]
	adds r1, r0
	adds r1, r5
	str r1, [r2, 0x4]
	adds r2, 0x4
	adds r4, 0x1
	adds r5, 0x1
	ldr r0, _08094E44
	cmp r4, r0
	ble _08094DD6
	mov r1, r12
	ldr r0, [r1]
	str r0, [r6]
	mov r2, r9
	movs r4, 0x1
_08094DD6:
	cmp r5, r7
	blt _08094DDC
	movs r5, 0
_08094DDC:
	subs r3, 0x1
	cmp r3, 0
	bne _08094DA6
_08094DE2:
	ldr r3, _08094E44
	ldr r5, _08094E38
	ldr r0, _08094E3C
	adds r0, r5
	mov r8, r0
	lsls r0, r4, 2
	subs r0, 0x4
	adds r2, r0, r5
	ldr r1, _08094E48
	mov r12, r1
	adds r7, r3, 0
_08094DF8:
	ldr r0, [r2]
	lsrs r1, r0, 30
	eors r0, r1
	mov r1, r12
	muls r1, r0
	ldr r0, [r2, 0x4]
	eors r0, r1
	subs r0, r4
	str r0, [r2, 0x4]
	adds r2, 0x4
	adds r4, 0x1
	cmp r4, r7
	ble _08094E1C
	mov r1, r8
	ldr r0, [r1]
	str r0, [r6]
	adds r2, r5, 0
	movs r4, 0x1
_08094E1C:
	subs r3, 0x1
	cmp r3, 0
	bne _08094DF8
	movs r0, 0x80
	lsls r0, 24
	str r0, [r6]
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_08094E34: .4byte 0x012bd6aa
_08094E38: .4byte gUnknown_3001198
_08094E3C: .4byte 0x000009bc
_08094E40: .4byte 0x0019660d
_08094E44: .4byte 0x0000026f
_08094E48: .4byte 0x5d588b65
	thumb_func_end sub_8094D74

	thumb_func_start sub_8094E4C
sub_8094E4C:
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	ldr r0, _08094F54
	ldr r2, [r0]
	ldr r1, _08094F58
	mov r8, r0
	cmp r2, r1
	ble _08094F1C
	ldr r0, _08094F5C
	cmp r2, r0
	bne _08094E6C
	ldr r0, _08094F60
	bl sub_8094D28
_08094E6C:
	movs r3, 0
	ldr r0, _08094F64
	mov r9, r0
	ldr r7, _08094F68
	mov r12, r9
	adds r5, r7, 0
_08094E78:
	ldr r4, [r5]
	movs r6, 0x80
	lsls r6, 24
	ands r4, r6
	ldr r0, [r5, 0x4]
	ldr r1, _08094F6C
	ands r0, r1
	orrs r4, r0
	ldr r1, _08094F70
	adds r0, r3, r1
	lsls r0, 2
	adds r0, r7
	lsrs r2, r4, 1
	ldr r1, [r0]
	eors r1, r2
	movs r0, 0x1
	ands r4, r0
	lsls r0, r4, 2
	add r0, r12
	ldr r0, [r0]
	eors r1, r0
	stm r5!, {r1}
	adds r3, 0x1
	cmp r3, 0xE2
	ble _08094E78
	ldr r5, _08094F74
	cmp r3, r5
	bgt _08094EE6
	ldr r1, _08094F68
	ldr r4, _08094F64
	mov r12, r4
	lsls r0, r3, 2
	adds r2, r0, r1
	ldr r4, _08094F78
	adds r0, r4
	adds r7, r0, r1
_08094EC0:
	ldr r4, [r2]
	ands r4, r6
	ldr r0, [r2, 0x4]
	ldr r1, _08094F6C
	ands r0, r1
	orrs r4, r0
	lsrs r0, r4, 1
	ldm r7!, {r1}
	eors r1, r0
	movs r0, 0x1
	ands r4, r0
	lsls r0, r4, 2
	add r0, r12
	ldr r0, [r0]
	eors r1, r0
	stm r2!, {r1}
	adds r3, 0x1
	cmp r3, r5
	ble _08094EC0
_08094EE6:
	ldr r2, _08094F68
	ldr r0, _08094F7C
	adds r3, r2, r0
	ldr r4, [r3]
	movs r0, 0x80
	lsls r0, 24
	ands r4, r0
	ldr r0, [r2]
	ldr r1, _08094F6C
	ands r0, r1
	orrs r4, r0
	movs r1, 0xC6
	lsls r1, 3
	adds r2, r1
	lsrs r0, r4, 1
	ldr r1, [r2]
	eors r1, r0
	movs r0, 0x1
	ands r4, r0
	lsls r0, r4, 2
	add r0, r9
	ldr r0, [r0]
	eors r1, r0
	str r1, [r3]
	movs r0, 0
	mov r4, r8
	str r0, [r4]
_08094F1C:
	ldr r2, _08094F68
	mov r0, r8
	ldr r1, [r0]
	lsls r0, r1, 2
	adds r0, r2
	ldr r4, [r0]
	adds r1, 0x1
	mov r0, r8
	str r1, [r0]
	lsrs r0, r4, 11
	eors r4, r0
	lsls r0, r4, 7
	ldr r1, _08094F80
	ands r0, r1
	eors r4, r0
	lsls r0, r4, 15
	ldr r1, _08094F84
	ands r0, r1
	eors r4, r0
	lsrs r0, r4, 18
	eors r4, r0
	adds r0, r4, 0
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r1}
	bx r1
	.align 2, 0
_08094F54: .4byte gUnknown_203B470
_08094F58: .4byte 0x0000026f
_08094F5C: .4byte 0x00000271
_08094F60: .4byte 0x00001571
_08094F64: .4byte gUnknown_203B474
_08094F68: .4byte gUnknown_3001198
_08094F6C: .4byte 0x7fffffff
_08094F70: .4byte 0x0000018d
_08094F74: .4byte 0x0000026e
_08094F78: .4byte 0xfffffc74
_08094F7C: .4byte 0x000009bc
_08094F80: .4byte 0x9d2c5680
_08094F84: .4byte 0xefc60000
	thumb_func_end sub_8094E4C

        .align 2,0
