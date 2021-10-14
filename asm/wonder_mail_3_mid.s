        .include "constants/gba_constants.inc"
	.include "asm/macros.inc"

	.syntax unified

	.text

	thumb_func_start sub_802F9C0
sub_802F9C0:
	push {r4,r5,lr}
	ldr r4, _0802FA44
	ldr r0, [r4]
	movs r1, 0xAC
	lsls r1, 1
	adds r0, r1
	movs r2, 0
	movs r1, 0x1
	strb r1, [r0]
	ldr r0, [r4]
	ldr r3, _0802FA48
	adds r0, r3
	strb r2, [r0]
	ldr r0, [r4]
	adds r3, 0x1
	adds r1, r0, r3
	movs r0, 0x8
	strb r0, [r1]
	ldr r0, [r4]
	ldr r1, _0802FA4C
	adds r0, r1
	strb r2, [r0]
	ldr r0, [r4]
	adds r0, 0xD6
	movs r2, 0
	ldrsh r0, [r0, r2]
	movs r1, 0xC
	bl sub_80095E4
	adds r0, 0x2
	lsls r0, 16
	ldr r3, [r4]
	adds r5, r3, 0
	adds r5, 0xF0
	ldr r2, [r5]
	lsls r1, r2, 1
	adds r1, r2
	lsls r1, 3
	adds r1, r3, r1
	movs r2, 0x83
	lsls r2, 1
	adds r1, r2
	asrs r2, r0, 16
	lsrs r0, 16
	strh r0, [r1]
	ldr r1, [r5]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 3
	adds r3, r0
	adds r2, 0x2
	movs r0, 0x84
	lsls r0, 1
	adds r3, r0
	strh r2, [r3]
	bl ResetUnusedInputStruct
	ldr r0, [r4]
	adds r0, 0xF8
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_0802FA44: .4byte gUnknown_203B314
_0802FA48: .4byte 0x00000159
_0802FA4C: .4byte 0x0000015b
	thumb_func_end sub_802F9C0

	thumb_func_start sub_802FA50
sub_802FA50:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0x8
	ldr r4, _0802FB1C
	ldr r0, [r4]
	adds r0, 0xF0
	ldr r0, [r0]
	bl sub_8008C54
	ldr r0, [r4]
	adds r0, 0xF0
	ldr r0, [r0]
	bl sub_80073B8
	ldr r2, _0802FB20
	ldr r0, [r4]
	adds r0, 0xF0
	ldr r3, [r0]
	movs r0, 0
	str r0, [sp]
	movs r0, 0xA
	movs r1, 0
	bl xxx_call_draw_string
	ldr r3, [r4]
	movs r1, 0xAD
	lsls r1, 1
	adds r0, r3, r1
	ldrb r0, [r0]
	lsls r0, 3
	adds r0, 0x4
	adds r1, r3, 0
	adds r1, 0xDA
	movs r5, 0
	ldrsh r2, [r1, r5]
	adds r2, 0x1
	movs r1, 0x7
	str r1, [sp]
	adds r1, r3, 0
	adds r1, 0xF0
	ldr r1, [r1]
	str r1, [sp, 0x4]
	movs r1, 0
	movs r3, 0x2
	bl sub_8012BC4
	ldr r1, [r4]
	adds r0, r1, 0
	adds r0, 0xB8
	ldrb r0, [r0]
	cmp r0, 0
	beq _0802FB78
	movs r6, 0
	adds r0, r1, 0
	adds r0, 0xD6
	movs r1, 0
	ldrsh r0, [r0, r1]
	cmp r6, r0
	blt _0802FACA
	b _0802FBD6
_0802FACA:
	mov r8, r4
_0802FACC:
	mov r2, r8
	ldr r0, [r2]
	adds r0, 0xBC
	adds r1, r6, 0
	bl sub_8013800
	adds r5, r0, 0
	mov r3, r8
	ldr r2, [r3]
	adds r0, r2, 0
	adds r0, 0xDA
	movs r3, 0
	ldrsh r1, [r0, r3]
	subs r0, 0x2
	movs r3, 0
	ldrsh r0, [r0, r3]
	muls r0, r1
	adds r1, r0, r6
	lsls r0, r1, 1
	adds r0, r2, r0
	movs r3, 0
	ldrsh r7, [r0, r3]
	adds r0, r2, 0
	adds r0, 0x5C
	adds r0, r1
	ldrb r4, [r0]
	cmp r4, 0
	beq _0802FB28
	adds r0, r2, 0
	adds r0, 0xF0
	ldr r3, [r0]
	movs r0, 0
	str r0, [sp]
	movs r0, 0xA
	adds r1, r5, 0
	ldr r2, _0802FB24
	bl xxx_call_draw_string
	b _0802FB46
	.align 2, 0
_0802FB1C: .4byte gUnknown_203B314
_0802FB20: .4byte gUnknown_80E0744
_0802FB24: .4byte gUnknown_80E0750
_0802FB28:
	adds r0, r2, 0
	adds r0, 0x8A
	adds r0, r1
	ldrb r0, [r0]
	cmp r0, 0
	beq _0802FB46
	adds r0, r2, 0
	adds r0, 0xF0
	ldr r3, [r0]
	str r4, [sp]
	movs r0, 0xA
	adds r1, r5, 0
	ldr r2, _0802FB74
	bl xxx_call_draw_string
_0802FB46:
	adds r0, r7, 0
	bl sub_80974A0
	adds r2, r0, 0
	mov r1, r8
	ldr r0, [r1]
	adds r0, 0xF0
	ldr r3, [r0]
	movs r0, 0
	str r0, [sp]
	movs r0, 0x18
	adds r1, r5, 0
	bl xxx_call_draw_string
	adds r6, 0x1
	mov r2, r8
	ldr r0, [r2]
	adds r0, 0xD6
	movs r3, 0
	ldrsh r0, [r0, r3]
	cmp r6, r0
	blt _0802FACC
	b _0802FBD6
	.align 2, 0
_0802FB74: .4byte gUnknown_80E0754
_0802FB78:
	movs r6, 0
	adds r0, r1, 0
	adds r0, 0xD6
	movs r5, 0
	ldrsh r0, [r0, r5]
	cmp r6, r0
	bge _0802FBD6
	adds r5, r4, 0
_0802FB88:
	ldr r0, [r5]
	adds r0, 0xBC
	adds r1, r6, 0
	bl sub_8013800
	adds r4, r0, 0
	ldr r1, [r5]
	adds r0, r1, 0
	adds r0, 0xDA
	movs r3, 0
	ldrsh r2, [r0, r3]
	subs r0, 0x2
	movs r3, 0
	ldrsh r0, [r0, r3]
	muls r0, r2
	adds r0, r6
	lsls r0, 1
	adds r1, r0
	movs r2, 0
	ldrsh r0, [r1, r2]
	bl sub_80974A0
	adds r2, r0, 0
	ldr r0, [r5]
	adds r0, 0xF0
	ldr r3, [r0]
	movs r0, 0
	str r0, [sp]
	movs r0, 0x8
	adds r1, r4, 0
	bl xxx_call_draw_string
	adds r6, 0x1
	ldr r0, [r5]
	adds r0, 0xD6
	movs r3, 0
	ldrsh r0, [r0, r3]
	cmp r6, r0
	blt _0802FB88
_0802FBD6:
	ldr r0, _0802FBF0
	ldr r0, [r0]
	adds r0, 0xF0
	ldr r0, [r0]
	bl sub_80073E0
	add sp, 0x8
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_0802FBF0: .4byte gUnknown_203B314
	thumb_func_end sub_802FA50

	thumb_func_start sub_802FBF4
sub_802FBF4:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x4
	movs r0, 0
	mov r8, r0
	movs r1, 0
	str r1, [sp]
_0802FC08:
	ldr r1, [sp]
	lsls r0, r1, 16
	asrs r4, r0, 16
	mov r10, r4
	adds r0, r4, 0
	bl sub_80A27CC
	lsls r0, 24
	cmp r0, 0
	beq _0802FCCE
	cmp r4, 0x13
	beq _0802FCCE
	cmp r4, 0x1D
	beq _0802FCCE
	ldr r7, _0802FC88
	ldr r1, [r7]
	mov r0, r8
	lsls r6, r0, 1
	adds r0, r1, r6
	strh r4, [r0]
	adds r1, 0x5C
	add r1, r8
	movs r0, 0
	strb r0, [r1]
	ldr r0, [r7]
	adds r0, 0x8A
	add r0, r8
	movs r1, 0
	strb r1, [r0]
	ldr r0, [r7]
	adds r0, 0xB8
	ldrb r0, [r0]
	cmp r0, 0
	beq _0802FCCA
	cmp r4, 0xD
	beq _0802FCCA
	adds r0, r4, 0
	bl sub_80A270C
	lsls r0, 24
	lsrs r0, 24
	mov r9, r0
	movs r5, 0
	cmp r4, 0x1E
	bgt _0802FCA8
	adds r0, r4, 0
	bl sub_8097384
	lsls r0, 24
	cmp r0, 0
	bne _0802FCA6
	cmp r4, 0x6
	bne _0802FC8C
	movs r0, 0x13
	bl sub_8097384
	lsls r0, 24
	cmp r0, 0
	beq _0802FCA8
	ldr r0, [r7]
	adds r0, r6
	movs r1, 0x13
	b _0802FCA4
	.align 2, 0
_0802FC88: .4byte gUnknown_203B314
_0802FC8C:
	mov r0, r10
	cmp r0, 0xA
	bne _0802FCA8
	movs r0, 0x1D
	bl sub_8097384
	lsls r0, 24
	cmp r0, 0
	beq _0802FCA8
	ldr r0, [r7]
	adds r0, r6
	movs r1, 0x1D
_0802FCA4:
	strh r1, [r0]
_0802FCA6:
	movs r5, 0x1
_0802FCA8:
	ldr r4, _0802FCEC
	ldr r0, [r4]
	adds r0, 0x5C
	add r0, r8
	strb r5, [r0]
	cmp r5, 0
	bne _0802FCCA
	mov r0, r9
	bl sub_80969D0
	cmp r0, 0
	ble _0802FCCA
	ldr r0, [r4]
	adds r0, 0x8A
	add r0, r8
	movs r1, 0x1
	strb r1, [r0]
_0802FCCA:
	movs r1, 0x1
	add r8, r1
_0802FCCE:
	ldr r0, [sp]
	adds r0, 0x1
	str r0, [sp]
	cmp r0, 0x2D
	ble _0802FC08
	mov r0, r8
	add sp, 0x4
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	.align 2, 0
_0802FCEC: .4byte gUnknown_203B314
	thumb_func_end sub_802FBF4

        .align 2,0
