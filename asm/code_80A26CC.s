	.include "constants/gba_constants.inc"
	.include "asm/macros.inc"

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

	thumb_func_start sub_80A2B28
sub_80A2B28:
	push {lr}
	movs r0, 0
	movs r1, 0x11
	bl sub_8001658
	lsls r0, 16
	asrs r0, 16
	bl sub_80A2B18
	pop {r1}
	bx r1
	thumb_func_end sub_80A2B28

	thumb_func_start sub_80A2B40
sub_80A2B40:
	push {r4-r6,lr}
	adds r5, r0, 0
	ldr r2, _080A2BFC
	adds r0, r5, r2
	ldm r1!, {r2-r4}
	stm r0!, {r2-r4}
	ldm r1!, {r2-r4}
	stm r0!, {r2-r4}
	ldr r3, _080A2C00
	adds r0, r5, r3
	movs r4, 0
	ldrsh r1, [r0, r4]
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 1
	movs r1, 0x6
	bl MemoryAlloc
	movs r2, 0xA9
	lsls r2, 3
	adds r1, r5, r2
	str r0, [r1]
	movs r6, 0
	movs r3, 0xA7
	lsls r3, 3
	adds r0, r5, r3
	movs r4, 0
	ldrsh r0, [r0, r4]
	cmp r6, r0
	bge _080A2BC0
_080A2B7C:
	lsls r4, r6, 2
	ldr r0, _080A2C04
	adds r2, r5, r0
	adds r2, r4
	ldr r1, _080A2C08
	adds r0, r5, r1
	movs r3, 0
	ldrsh r0, [r0, r3]
	adds r1, r6, 0x2
	adds r0, r1
	lsls r0, 11
	ldr r1, _080A2C0C
	adds r0, r1
	str r0, [r2]
	ldr r1, _080A2C10
	adds r0, r5, r1
	movs r2, 0
	ldrsh r0, [r0, r2]
	lsls r0, 7
	movs r1, 0x6
	bl MemoryAlloc
	ldr r3, _080A2C14
	adds r1, r5, r3
	adds r1, r4
	str r0, [r1]
	adds r6, 0x1
	movs r4, 0xA7
	lsls r4, 3
	adds r0, r5, r4
	movs r1, 0
	ldrsh r0, [r0, r1]
	cmp r6, r0
	blt _080A2B7C
_080A2BC0:
	cmp r6, 0x1
	bgt _080A2BD8
	movs r1, 0
	lsls r0, r6, 2
	ldr r2, _080A2C14
	adds r0, r2
	adds r0, r5
_080A2BCE:
	str r1, [r0, 0x8]
	stm r0!, {r1}
	adds r6, 0x1
	cmp r6, 0x1
	ble _080A2BCE
_080A2BD8:
	movs r3, 0xA8
	lsls r3, 3
	adds r0, r5, r3
	ldr r1, [r0]
	cmp r1, 0
	beq _080A2C20
	ldr r4, _080A2C18
	adds r0, r5, r4
	movs r1, 0
	ldrsh r0, [r0, r1]
	lsls r0, 8
	movs r1, 0x6
	bl MemoryAlloc
	ldr r2, _080A2C1C
	adds r1, r5, r2
	str r0, [r1]
	b _080A2C26
	.align 2, 0
_080A2BFC: .4byte 0x0000052c
_080A2C00: .4byte 0x00000534
_080A2C04: .4byte 0x00000554
_080A2C08: .4byte 0x00000536
_080A2C0C: .4byte gUnknown_202B038
_080A2C10: .4byte 0x0000053c
_080A2C14: .4byte 0x0000054c
_080A2C18: .4byte 0x0000053a
_080A2C1C: .4byte 0x00000544
_080A2C20:
	ldr r3, _080A2CF0
	adds r0, r5, r3
	str r1, [r0]
_080A2C26:
	movs r4, 0x86
	lsls r4, 3
	adds r0, r5, r4
	movs r1, 0
	str r1, [r0]
	ldr r2, _080A2CF4
	adds r0, r5, r2
	str r1, [r0]
	movs r3, 0x87
	lsls r3, 3
	adds r0, r5, r3
	str r1, [r0]
	adds r4, 0xC
	adds r0, r5, r4
	str r1, [r0]
	adds r2, 0xC
	adds r0, r5, r2
	str r1, [r0]
	adds r3, 0xF2
	adds r0, r5, r3
	strb r1, [r0]
	adds r4, 0x8
	adds r2, r5, r4
	ldr r0, _080A2CF8
	strh r0, [r2]
	movs r2, 0x8D
	lsls r2, 3
	adds r0, r5, r2
	str r1, [r0]
	subs r3, 0xE2
	adds r0, r5, r3
	strb r1, [r0]
	adds r4, 0x5
	adds r0, r5, r4
	strb r1, [r0]
	subs r2, 0x1E
	adds r0, r5, r2
	strb r1, [r0]
	adds r3, 0x3
	adds r0, r5, r3
	strb r1, [r0]
	adds r4, 0x3
	adds r0, r5, r4
	strb r1, [r0]
	adds r2, 0x3
	adds r0, r5, r2
	strb r1, [r0]
	adds r2, r5, 0
	adds r3, 0x21
	adds r0, r5, r3
	str r1, [r0]
	adds r4, 0x24
	adds r0, r5, r4
	strb r1, [r0]
	adds r3, 0x5
	adds r0, r5, r3
	strb r1, [r0]
	movs r0, 0
	movs r1, 0xD
_080A2C9C:
	strh r0, [r2]
	strh r0, [r2, 0x2]
	str r0, [r2, 0x8]
	str r0, [r2, 0x4]
	subs r1, 0x1
	adds r2, 0x10
	cmp r1, 0
	bge _080A2C9C
	movs r1, 0
	movs r4, 0xF8
	lsls r4, 2
	adds r0, r5, r4
	movs r2, 0x1
_080A2CB6:
	strb r1, [r0]
	strb r1, [r0, 0x1]
	strh r1, [r0, 0x2]
	strh r1, [r0, 0x4]
	str r1, [r0, 0x8]
	str r1, [r0, 0xC]
	str r1, [r0, 0x14]
	str r1, [r0, 0x10]
	str r1, [r0, 0x1C]
	str r1, [r0, 0x18]
	str r1, [r0, 0x20]
	str r1, [r0, 0x24]
	adds r0, 0x28
	subs r2, 0x1
	cmp r2, 0
	bge _080A2CB6
	movs r4, 0
_080A2CD8:
	adds r0, r5, 0
	adds r1, r4, 0
	ldr r2, _080A2CFC
	bl sub_80A456C
	adds r4, 0x1
	cmp r4, 0x1
	ble _080A2CD8
	pop {r4-r6}
	pop {r0}
	bx r0
	.align 2, 0
_080A2CF0: .4byte 0x00000544
_080A2CF4: .4byte 0x00000434
_080A2CF8: .4byte 0x0000ffff
_080A2CFC: .4byte gUnknown_81172B8
	thumb_func_end sub_80A2B40

	thumb_func_start sub_80A2D00
sub_80A2D00:
	push {r4-r7,lr}
	adds r6, r0, 0
	bl sub_80A2DD4
	ldr r0, _080A2D5C
	adds r4, r6, r0
	ldr r0, [r4]
	cmp r0, 0
	beq _080A2D1A
	bl MemoryFree
	movs r0, 0
	str r0, [r4]
_080A2D1A:
	movs r1, 0xA9
	lsls r1, 3
	adds r4, r6, r1
	ldr r0, [r4]
	bl MemoryFree
	movs r0, 0
	str r0, [r4]
	movs r5, 0
	movs r7, 0
_080A2D2E:
	lsls r2, r5, 2
	ldr r1, _080A2D60
	adds r0, r6, r1
	adds r1, r0, r2
	ldr r0, [r1]
	cmp r0, 0
	beq _080A2D3E
	str r7, [r1]
_080A2D3E:
	ldr r1, _080A2D64
	adds r0, r6, r1
	adds r4, r0, r2
	ldr r0, [r4]
	cmp r0, 0
	beq _080A2D50
	bl MemoryFree
	str r7, [r4]
_080A2D50:
	adds r5, 0x1
	cmp r5, 0x1
	ble _080A2D2E
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_080A2D5C: .4byte 0x00000544
_080A2D60: .4byte 0x00000554
_080A2D64: .4byte 0x0000054c
	thumb_func_end sub_80A2D00

	thumb_func_start sub_80A2D68
sub_80A2D68:
	push {r4,lr}
	ldr r1, _080A2D84
	adds r4, r0, r1
	ldr r0, [r4]
	cmp r0, 0
	beq _080A2D7C
	bl MemoryFree
	movs r0, 0
	str r0, [r4]
_080A2D7C:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080A2D84: .4byte 0x00000544
	thumb_func_end sub_80A2D68

	thumb_func_start sub_80A2D88
sub_80A2D88:
	push {r4-r7,lr}
	adds r6, r0, 0
	movs r0, 0xA8
	lsls r0, 3
	adds r7, r6, r0
	ldr r0, [r7]
	cmp r0, 0
	beq _080A2DC6
	movs r1, 0x89
	lsls r1, 3
	adds r5, r6, r1
	ldr r2, _080A2DCC
	adds r4, r6, r2
	movs r1, 0
	ldrsh r0, [r4, r1]
	lsls r0, 8
	movs r1, 0x6
	bl MemoryAlloc
	ldr r2, _080A2DD0
	adds r1, r6, r2
	str r0, [r1]
	subs r2, 0xDC
	adds r1, r6, r2
	ldr r1, [r1]
	movs r2, 0
	ldrsh r3, [r4, r2]
	ldr r4, [r7]
	adds r2, r5, 0
	bl _call_via_r4
_080A2DC6:
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_080A2DCC: .4byte 0x0000053a
_080A2DD0: .4byte 0x00000544
	thumb_func_end sub_80A2D88

	thumb_func_start sub_80A2DD4
sub_80A2DD4:
	push {r4-r6,lr}
	adds r6, r0, 0
	movs r0, 0xFA
	lsls r0, 2
	adds r4, r6, r0
	movs r5, 0x1
_080A2DE0:
	ldr r0, [r4]
	cmp r0, 0
	beq _080A2DEE
	bl CloseFile
	movs r0, 0
	str r0, [r4]
_080A2DEE:
	adds r4, 0x28
	subs r5, 0x1
	cmp r5, 0
	bge _080A2DE0
	ldr r0, _080A2E5C
	adds r4, r6, r0
	ldr r0, [r4]
	cmp r0, 0
	beq _080A2E08
	bl CloseFile
	movs r0, 0
	str r0, [r4]
_080A2E08:
	movs r0, 0x88
	lsls r0, 3
	adds r4, r6, r0
	ldr r0, [r4]
	cmp r0, 0
	beq _080A2E1C
	bl CloseFile
	movs r0, 0
	str r0, [r4]
_080A2E1C:
	movs r0, 0x86
	lsls r0, 3
	adds r4, r6, r0
	ldr r0, [r4]
	cmp r0, 0
	beq _080A2E30
	bl CloseFile
	movs r0, 0
	str r0, [r4]
_080A2E30:
	ldr r0, _080A2E60
	adds r4, r6, r0
	ldr r0, [r4]
	cmp r0, 0
	beq _080A2E42
	bl CloseFile
	movs r0, 0
	str r0, [r4]
_080A2E42:
	movs r0, 0x87
	lsls r0, 3
	adds r4, r6, r0
	ldr r0, [r4]
	cmp r0, 0
	beq _080A2E56
	bl CloseFile
	movs r0, 0
	str r0, [r4]
_080A2E56:
	pop {r4-r6}
	pop {r0}
	bx r0
	.align 2, 0
_080A2E5C: .4byte 0x0000043c
_080A2E60: .4byte 0x00000434
	thumb_func_end sub_80A2DD4

	thumb_func_start sub_80A2E64
sub_80A2E64:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x8
	adds r7, r0, 0
	bl sub_80A2DD4
	ldr r0, _080A2FA4
	adds r1, r7, r0
	ldr r0, _080A2FA8
	strh r0, [r1]
	movs r1, 0xA5
	lsls r1, 3
	adds r0, r7, r1
	movs r1, 0
	movs r2, 0
	strh r2, [r0]
	movs r3, 0x89
	lsls r3, 3
	adds r0, r7, r3
	strb r1, [r0]
	ldr r4, _080A2FAC
	adds r0, r7, r4
	strb r1, [r0]
	adds r3, 0x2
	adds r0, r7, r3
	strb r1, [r0]
	adds r4, 0x2
	adds r0, r7, r4
	strb r1, [r0]
	adds r3, 0x2
	adds r0, r7, r3
	strb r1, [r0]
	adds r4, 0x2
	adds r0, r7, r4
	strb r1, [r0]
	adds r3, r7, 0
	adds r4, 0x1F
	adds r0, r7, r4
	str r2, [r0]
	movs r2, 0x8E
	lsls r2, 3
	adds r0, r7, r2
	strb r1, [r0]
	adds r4, 0x5
	adds r0, r7, r4
	strb r1, [r0]
	movs r0, 0
	movs r1, 0xD
_080A2ECA:
	strh r0, [r3]
	strh r0, [r3, 0x2]
	str r0, [r3, 0x8]
	str r0, [r3, 0x4]
	subs r1, 0x1
	adds r3, 0x10
	cmp r1, 0
	bge _080A2ECA
	movs r1, 0
	movs r2, 0xF8
	lsls r2, 2
	adds r0, r7, r2
	movs r2, 0x1
_080A2EE4:
	strb r1, [r0]
	strb r1, [r0, 0x1]
	strh r1, [r0, 0x2]
	strh r1, [r0, 0x4]
	str r1, [r0, 0x8]
	str r1, [r0, 0xC]
	str r1, [r0, 0x14]
	str r1, [r0, 0x10]
	str r1, [r0, 0x1C]
	str r1, [r0, 0x18]
	str r1, [r0, 0x20]
	str r1, [r0, 0x24]
	adds r0, 0x28
	subs r2, 0x1
	cmp r2, 0
	bge _080A2EE4
	ldr r3, _080A2FB0
	adds r0, r7, r3
	movs r4, 0
	ldrsh r0, [r0, r4]
	lsls r0, 20
	lsrs r6, r0, 16
	movs r5, 0
	ldr r1, _080A2FB4
	adds r0, r7, r1
	movs r2, 0
	ldrsh r0, [r0, r2]
	cmp r5, r0
	bge _080A2F78
	mov r10, r5
	add r4, sp, 0x4
	movs r3, 0xFF
	mov r9, r3
_080A2F26:
	mov r0, r10
	str r0, [sp]
	ldrb r0, [r4]
	mov r1, r9
	orrs r0, r1
	strb r0, [r4]
	ldrb r0, [r4, 0x1]
	orrs r0, r1
	strb r0, [r4, 0x1]
	ldrb r0, [r4, 0x2]
	orrs r0, r1
	strb r0, [r4, 0x2]
	mov r2, r10
	strb r2, [r4, 0x3]
	adds r0, r6, 0
	adds r1, r0, 0x1
	lsls r1, 16
	lsrs r6, r1, 16
	ldr r1, [sp]
	bl sub_8003810
	adds r5, 0x1
	mov r8, r5
	movs r5, 0xE
_080A2F56:
	adds r0, r6, 0
	adds r1, r0, 0x1
	lsls r1, 16
	lsrs r6, r1, 16
	ldr r1, [sp, 0x4]
	bl sub_8003810
	subs r5, 0x1
	cmp r5, 0
	bge _080A2F56
	mov r5, r8
	ldr r3, _080A2FB4
	adds r0, r7, r3
	movs r1, 0
	ldrsh r0, [r0, r1]
	cmp r5, r0
	blt _080A2F26
_080A2F78:
	adds r0, r7, 0
	movs r1, 0
	bl sub_80A3BB0
	movs r2, 0x91
	lsls r2, 3
	adds r0, r7, r2
	bl sub_80A3EB0
	ldr r3, _080A2FB8
	adds r1, r7, r3
	movs r0, 0x1
	strb r0, [r1]
	add sp, 0x8
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_080A2FA4: .4byte 0x00000444
_080A2FA8: .4byte 0x0000ffff
_080A2FAC: .4byte 0x00000449
_080A2FB0: .4byte 0x0000052c
_080A2FB4: .4byte 0x0000052e
_080A2FB8: .4byte 0x0000052a
	thumb_func_end sub_80A2E64

	thumb_func_start sub_80A2FBC
sub_80A2FBC:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x2C
	mov r9, r0
	lsls r1, 16
	asrs r4, r1, 16
	movs r0, 0x1
	negs r0, r0
	cmp r4, r0
	bne _080A2FDE
	mov r0, r9
	bl sub_80A2E64
	b _080A3428
_080A2FDE:
	mov r0, r9
	bl sub_80A2DD4
	ldr r0, _080A3284
	add r0, r9
	strh r4, [r0]
	lsls r0, r4, 3
	subs r0, r4
	lsls r0, 2
	ldr r1, _080A3288
	adds r0, r1
	str r0, [sp, 0xC]
	ldr r0, [r0]
	ldr r4, _080A328C
	adds r1, r4, 0
	bl OpenFileAndGetFileDataPtr
	movs r6, 0x86
	lsls r6, 3
	add r6, r9
	str r0, [r6]
	ldr r1, [sp, 0xC]
	ldr r0, [r1, 0x4]
	adds r1, r4, 0
	bl OpenFileAndGetFileDataPtr
	ldr r5, _080A3290
	add r5, r9
	str r0, [r5]
	ldr r2, [sp, 0xC]
	ldr r0, [r2, 0x8]
	adds r1, r4, 0
	bl OpenFileAndGetFileDataPtr
	movs r1, 0x87
	lsls r1, 3
	add r1, r9
	str r0, [r1]
	ldr r1, [r6]
	ldr r1, [r1, 0x4]
	str r1, [sp, 0x18]
	ldr r1, [r5]
	ldr r1, [r1, 0x4]
	mov r8, r1
	ldr r6, [r0, 0x4]
	ldr r3, _080A3294
	add r3, r9
	str r3, [sp, 0x10]
	ldr r4, _080A3298
	add r4, r9
	str r4, [sp, 0x14]
	movs r5, 0x89
	lsls r5, 3
	add r5, r9
	mov r10, r5
	ldr r7, [sp, 0x18]
	ldrb r0, [r7]
	strh r0, [r3]
	adds r0, r7, 0
	adds r0, 0x2
	str r0, [sp, 0x18]
	ldrb r0, [r0]
	strh r0, [r3, 0x2]
	ldr r1, [sp, 0x18]
	adds r1, 0x2
	str r1, [sp, 0x18]
	mov r2, r8
	ldrh r0, [r2]
	strh r0, [r4]
	movs r3, 0x2
	add r8, r3
	mov r4, r8
	ldrh r0, [r4]
	ldr r5, [sp, 0x14]
	strh r0, [r5, 0x2]
	add r8, r3
	mov r7, r8
	ldrh r0, [r7]
	strh r0, [r5, 0x4]
	add r8, r3
	add r3, sp, 0x8
	ldr r0, _080A329C
	add r0, r9
	str r0, [sp, 0x1C]
	adds r1, r0, 0
	movs r2, 0x3
_080A308A:
	mov r4, r8
	ldrh r0, [r4]
	strh r0, [r1]
	movs r5, 0x2
	add r8, r5
	adds r1, 0x2
	subs r2, 0x1
	cmp r2, 0
	bge _080A308A
	mov r7, r8
	ldrh r0, [r7]
	movs r2, 0
	movs r1, 0
	ldr r4, [sp, 0x14]
	strh r0, [r4, 0xE]
	add r8, r5
	ldrb r0, [r6]
	mov r5, r10
	strb r0, [r5]
	adds r6, 0x1
	ldrb r0, [r6]
	strb r0, [r5, 0x1]
	adds r6, 0x1
	ldrb r0, [r6]
	strb r0, [r5, 0x2]
	adds r6, 0x1
	ldrb r0, [r6]
	strb r0, [r5, 0x3]
	adds r6, 0x1
	ldrb r0, [r6]
	strb r0, [r5, 0x4]
	adds r6, 0x1
	ldrb r0, [r6]
	strb r0, [r5, 0x5]
	adds r6, 0x1
	ldrb r0, [r6]
	strh r0, [r5, 0x6]
	adds r6, 0x2
	ldrb r0, [r6]
	strh r0, [r5, 0x8]
	adds r6, 0x2
	ldrb r0, [r6]
	strh r0, [r5, 0xA]
	adds r6, 0x2
	ldr r7, [sp, 0x18]
	ldr r0, _080A32A0
	add r0, r9
	movs r4, 0
	ldrsh r0, [r0, r4]
	lsls r0, 20
	lsrs r5, r0, 16
	str r1, [sp, 0x4]
	movs r0, 0xFF
	strb r0, [r3]
	movs r0, 0x1
	negs r0, r0
	strb r0, [r3, 0x1]
	strb r0, [r3, 0x2]
	strb r2, [r3, 0x3]
	movs r4, 0
	ldr r1, [sp, 0x10]
	movs r2, 0
	ldrsh r0, [r1, r2]
	ldr r3, [sp, 0xC]
	adds r3, 0xC
	str r3, [sp, 0x20]
	cmp r4, r0
	bge _080A3158
	ldr r0, _080A32A4
	add r0, r9
	movs r1, 0
	ldrsh r0, [r0, r1]
	cmp r4, r0
	bge _080A3198
_080A311E:
	adds r0, r5, 0
	adds r1, r0, 0x1
	lsls r1, 16
	lsrs r5, r1, 16
	ldr r1, [sp, 0x4]
	bl sub_8003810
	adds r0, r5, 0
	adds r1, r7, 0
	movs r2, 0xF
	bl sub_809971C
	adds r0, r5, 0
	adds r0, 0xF
	lsls r0, 16
	lsrs r5, r0, 16
	adds r7, 0x3C
	adds r4, 0x1
	ldr r2, [sp, 0x10]
	movs r3, 0
	ldrsh r0, [r2, r3]
	cmp r4, r0
	bge _080A3158
	ldr r0, _080A32A4
	add r0, r9
	movs r1, 0
	ldrsh r0, [r0, r1]
	cmp r4, r0
	blt _080A311E
_080A3158:
	ldr r0, _080A32A4
	add r0, r9
	movs r2, 0
	ldrsh r0, [r0, r2]
	cmp r4, r0
	bge _080A3198
_080A3164:
	adds r0, r5, 0
	adds r1, r0, 0x1
	lsls r1, 16
	lsrs r5, r1, 16
	ldr r1, [sp, 0x4]
	bl sub_8003810
	adds r7, r4, 0x1
	movs r4, 0xE
_080A3176:
	adds r0, r5, 0
	adds r1, r0, 0x1
	lsls r1, 16
	lsrs r5, r1, 16
	ldr r1, [sp, 0x8]
	bl sub_8003810
	subs r4, 0x1
	cmp r4, 0
	bge _080A3176
	adds r4, r7, 0
	ldr r0, _080A32A4
	add r0, r9
	movs r3, 0
	ldrsh r0, [r0, r3]
	cmp r4, r0
	blt _080A3164
_080A3198:
	movs r0, 0xA6
	lsls r0, 3
	add r0, r9
	movs r4, 0
	ldrsh r0, [r0, r4]
	lsls r0, 5
	ldr r5, _080A32A8
	adds r0, r5
	ldr r4, _080A32A0
	add r4, r9
	ldr r5, _080A3298
	add r5, r9
	mov r1, r8
	adds r2, r4, 0
	adds r3, r5, 0
	bl sub_80A37C4
	movs r0, 0xA9
	lsls r0, 3
	add r0, r9
	ldr r0, [r0]
	movs r1, 0xA5
	lsls r1, 3
	add r1, r9
	ldr r7, [sp, 0x14]
	movs r3, 0x4
	ldrsh r2, [r7, r3]
	subs r2, 0x1
	lsls r2, 5
	add r2, r8
	str r5, [sp]
	adds r3, r4, 0
	bl _UncompressCell
	ldr r0, _080A32AC
	add r0, r9
	movs r3, 0x89
	lsls r3, 3
	add r3, r9
	adds r1, r6, 0
	adds r2, r4, 0
	bl sub_80A3908
	adds r6, r0, 0
	movs r0, 0x8D
	lsls r0, 3
	add r0, r9
	str r6, [r0]
	ldr r0, _080A32B0
	add r0, r9
	ldr r2, [r0]
	cmp r2, 0
	beq _080A321C
	movs r1, 0xA8
	lsls r1, 3
	add r1, r9
	ldr r0, _080A32B4
	add r0, r9
	movs r4, 0
	ldrsh r3, [r0, r4]
	ldr r4, [r1]
	adds r0, r2, 0
	adds r1, r6, 0
	mov r2, r10
	bl _call_via_r4
_080A321C:
	mov r2, r9
	movs r4, 0
	ldr r5, [sp, 0x10]
	movs r6, 0x2
	ldrsh r0, [r5, r6]
	cmp r0, 0
	beq _080A32E4
	movs r7, 0
	ldrsh r1, [r5, r7]
	lsls r0, r1, 4
	subs r0, r1
	lsls r0, 2
	ldr r5, [sp, 0x18]
	adds r3, r5, r0
	lsls r1, 2
	adds r6, r3, r1
	ldr r0, _080A32B8
	add r0, r9
	str r3, [r0]
	movs r0, 0x8E
	lsls r0, 3
	add r0, r9
	movs r1, 0x1
	strb r1, [r0]
	ldr r0, _080A32BC
	add r0, r9
	strb r1, [r0]
	ldr r7, [sp, 0x10]
	movs r1, 0
	ldrsh r0, [r7, r1]
	cmp r4, r0
	bge _080A32F8
	ldr r1, _080A32A4
	add r1, r9
	movs r5, 0
	ldrsh r0, [r1, r5]
	cmp r4, r0
	bge _080A32F8
	movs r5, 0
	mov r8, r1
_080A326C:
	movs r7, 0x2
	ldrsh r0, [r3, r7]
	cmp r0, 0
	ble _080A32C0
	str r6, [r2, 0x4]
	movs r0, 0x2
	ldrsh r1, [r3, r0]
	lsls r0, r1, 4
	subs r0, r1
	lsls r0, 2
	adds r6, r0
	b _080A32C2
	.align 2, 0
_080A3284: .4byte 0x00000444
_080A3288: .4byte gUnknown_81188F0
_080A328C: .4byte gUnknown_9890000
_080A3290: .4byte 0x00000434
_080A3294: .4byte 0x00000464
_080A3298: .4byte 0x00000454
_080A329C: .4byte 0x0000045a
_080A32A0: .4byte 0x0000052c
_080A32A4: .4byte 0x0000052e
_080A32A8: .4byte 0x06008000
_080A32AC: .4byte 0x0000054c
_080A32B0: .4byte 0x00000544
_080A32B4: .4byte 0x0000053a
_080A32B8: .4byte 0x0000046c
_080A32BC: .4byte 0x00000471
_080A32C0:
	str r5, [r2, 0x4]
_080A32C2:
	strh r5, [r2]
	strh r5, [r2, 0x2]
	str r5, [r2, 0x8]
	adds r4, 0x1
	adds r2, 0x10
	adds r3, 0x4
	ldr r1, [sp, 0x10]
	movs r7, 0
	ldrsh r0, [r1, r7]
	cmp r4, r0
	bge _080A32F8
	mov r1, r8
	movs r7, 0
	ldrsh r0, [r1, r7]
	cmp r4, r0
	blt _080A326C
	b _080A32F8
_080A32E4:
	ldr r0, _080A3384
	add r0, r9
	str r4, [r0]
	movs r0, 0x8E
	lsls r0, 3
	add r0, r9
	strb r4, [r0]
	ldr r0, _080A3388
	add r0, r9
	strb r4, [r0]
_080A32F8:
	cmp r4, 0xD
	bgt _080A330E
	movs r0, 0
_080A32FE:
	strh r0, [r2]
	strh r0, [r2, 0x2]
	str r0, [r2, 0x8]
	str r0, [r2, 0x4]
	adds r4, 0x1
	adds r2, 0x10
	cmp r4, 0xD
	ble _080A32FE
_080A330E:
	movs r0, 0xA6
	lsls r0, 3
	add r0, r9
	movs r1, 0
	ldrsh r0, [r0, r1]
	ldr r2, [sp, 0x14]
	movs r3, 0x4
	ldrsh r1, [r2, r3]
	adds r0, r1
	lsls r0, 5
	ldr r4, _080A338C
	adds r5, r0, r4
	movs r7, 0
	movs r6, 0
	mov r8, r6
	movs r4, 0xF8
	lsls r4, 2
	add r4, r9
	ldr r0, [sp, 0x1C]
	str r0, [sp, 0x28]
	ldr r3, [sp, 0x20]
_080A3338:
	ldr r0, [r3]
	cmp r0, 0
	beq _080A3394
	ldr r1, _080A3390
	str r3, [sp, 0x24]
	bl OpenFileAndGetFileDataPtr
	str r0, [r4, 0x8]
	movs r1, 0x1
	strb r1, [r4]
	strb r1, [r4, 0x1]
	ldr r2, [r0, 0x4]
	str r2, [r4, 0xC]
	adds r1, r2, 0x4
	movs r0, 0x2
	ldrsh r6, [r2, r0]
	lsls r6, 2
	adds r0, r1, r6
	str r1, [r4, 0x14]
	str r1, [r4, 0x10]
	str r0, [r4, 0x1C]
	str r0, [r4, 0x18]
	mov r1, r8
	strh r1, [r4, 0x2]
	ldr r0, [r2, 0x4]
	strh r0, [r4, 0x4]
	str r5, [r4, 0x20]
	ldr r2, [sp, 0x28]
	movs r6, 0
	ldrsh r0, [r2, r6]
	lsls r0, 5
	str r0, [r4, 0x24]
	movs r1, 0
	ldrsh r0, [r2, r1]
	lsls r0, 5
	adds r5, r0
	ldr r3, [sp, 0x24]
	b _080A33AC
	.align 2, 0
_080A3384: .4byte 0x0000046c
_080A3388: .4byte 0x00000471
_080A338C: .4byte 0x06008000
_080A3390: .4byte gUnknown_9890000
_080A3394:
	strb r0, [r4]
	strb r0, [r4, 0x1]
	strh r0, [r4, 0x4]
	strh r0, [r4, 0x2]
	str r0, [r4, 0x8]
	str r0, [r4, 0xC]
	str r0, [r4, 0x14]
	str r0, [r4, 0x10]
	str r0, [r4, 0x1C]
	str r0, [r4, 0x18]
	str r0, [r4, 0x20]
	str r0, [r4, 0x24]
_080A33AC:
	adds r4, 0x28
	ldr r2, [sp, 0x28]
	adds r2, 0x2
	str r2, [sp, 0x28]
	adds r3, 0x4
	adds r7, 0x1
	cmp r7, 0x1
	ble _080A3338
	cmp r7, 0x3
	bgt _080A340E
_080A33C0:
	lsls r0, r7, 2
	ldr r3, [sp, 0x20]
	adds r0, r3, r0
	ldr r0, [r0]
	adds r4, r7, 0x1
	cmp r0, 0
	beq _080A3408
	ldr r1, _080A3438
	bl OpenFileAndGetFileDataPtr
	adds r3, r0, 0
	ldr r0, [r3, 0x4]
	adds r1, r0, 0x4
	movs r6, 0x2
	ldrsh r0, [r0, r6]
	lsls r0, 2
	adds r1, r0
	lsls r0, r7, 1
	ldr r7, [sp, 0x1C]
	adds r0, r7, r0
	movs r2, 0
	ldrsh r0, [r0, r2]
	lsls r0, 4
	cmp r0, 0
	ble _080A3402
	adds r2, r0, 0
_080A33F4:
	ldrh r0, [r1]
	strh r0, [r5]
	adds r1, 0x2
	adds r5, 0x2
	subs r2, 0x1
	cmp r2, 0
	bne _080A33F4
_080A3402:
	adds r0, r3, 0
	bl CloseFile
_080A3408:
	adds r7, r4, 0
	cmp r7, 0x3
	ble _080A33C0
_080A340E:
	mov r0, r9
	movs r1, 0
	bl sub_80A3BB0
	movs r0, 0x91
	lsls r0, 3
	add r0, r9
	bl sub_80A3EB0
	ldr r1, _080A343C
	add r1, r9
	movs r0, 0x1
	strb r0, [r1]
_080A3428:
	add sp, 0x2C
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_080A3438: .4byte gUnknown_9890000
_080A343C: .4byte 0x0000052a
	thumb_func_end sub_80A2FBC

	thumb_func_start sub_80A3440
sub_80A3440:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x4C
	mov r9, r0
	str r2, [sp, 0x34]
	str r3, [sp, 0x38]
	lsls r1, 16
	asrs r5, r1, 16
	movs r0, 0x1
	negs r0, r0
	cmp r5, r0
	beq _080A3464
	ldrb r0, [r2]
	cmp r0, 0x63
	bne _080A346C
_080A3464:
	mov r0, r9
	bl sub_80A2E64
	b _080A376C
_080A346C:
	mov r0, r9
	adds r1, r5, 0
	bl sub_80A2FBC
	mov r0, r9
	bl sub_80A2DD4
	ldr r0, _080A377C
	add r0, r9
	strh r5, [r0]
	lsls r4, r5, 3
	subs r4, r5
	lsls r4, 2
	ldr r0, _080A3780
	adds r4, r0
	ldr r0, [r4]
	ldr r5, _080A3784
	adds r1, r5, 0
	bl OpenFileAndGetFileDataPtr
	movs r1, 0x86
	lsls r1, 3
	add r1, r9
	mov r8, r1
	str r0, [r1]
	ldr r0, [r4, 0x4]
	adds r1, r5, 0
	bl OpenFileAndGetFileDataPtr
	ldr r6, _080A3788
	add r6, r9
	str r0, [r6]
	ldr r0, [r4, 0x8]
	adds r1, r5, 0
	bl OpenFileAndGetFileDataPtr
	movs r1, 0x87
	lsls r1, 3
	add r1, r9
	str r0, [r1]
	mov r2, r8
	ldr r1, [r2]
	ldr r2, [r1, 0x4]
	ldr r1, [r6]
	ldr r3, [r1, 0x4]
	ldr r7, [r0, 0x4]
	ldr r1, _080A378C
	add r1, r9
	ldr r4, _080A3790
	add r4, r9
	str r4, [sp, 0x3C]
	movs r0, 0x89
	lsls r0, 3
	add r0, r9
	mov r10, r0
	ldrb r0, [r2]
	strh r0, [r1]
	ldrb r0, [r2, 0x2]
	strh r0, [r1, 0x2]
	ldrh r0, [r3]
	strh r0, [r4]
	adds r3, 0x2
	ldrh r0, [r3]
	strh r0, [r4, 0x2]
	adds r3, 0x2
	ldrh r0, [r3]
	strh r0, [r4, 0x4]
	adds r3, 0x2
	add r5, sp, 0x2C
	ldr r1, _080A3794
	add r1, r9
	str r1, [sp, 0x48]
	movs r2, 0x3
_080A34FE:
	ldrh r0, [r3]
	strh r0, [r1]
	adds r3, 0x2
	adds r1, 0x2
	subs r2, 0x1
	cmp r2, 0
	bge _080A34FE
	ldrh r0, [r3]
	movs r2, 0
	mov r8, r2
	ldr r4, [sp, 0x3C]
	strh r0, [r4, 0xE]
	ldrb r0, [r7]
	mov r1, r10
	strb r0, [r1]
	adds r7, 0x1
	ldrb r0, [r7]
	strb r0, [r1, 0x1]
	adds r7, 0x1
	ldrb r0, [r7]
	strb r0, [r1, 0x2]
	adds r7, 0x1
	ldrb r0, [r7]
	strb r0, [r1, 0x3]
	adds r7, 0x1
	ldrb r0, [r7]
	strb r0, [r1, 0x4]
	adds r7, 0x1
	ldrb r0, [r7]
	strb r0, [r1, 0x5]
	adds r7, 0x1
	ldrb r0, [r7]
	strh r0, [r1, 0x6]
	adds r7, 0x2
	ldrb r0, [r7]
	strh r0, [r1, 0x8]
	adds r7, 0x2
	ldrb r0, [r7]
	strh r0, [r1, 0xA]
	adds r7, 0x2
	ldr r4, _080A3798
	add r4, r9
	ldr r0, [r4]
	str r0, [sp, 0x2C]
	str r2, [r5, 0x4]
	ldr r2, _080A379C
	add r2, r9
	movs r3, 0x89
	lsls r3, 3
	add r3, r9
	adds r0, r5, 0
	adds r1, r7, 0
	bl sub_80A3908
	adds r7, r0, 0
	movs r0, 0x8D
	lsls r0, 3
	add r0, r9
	str r7, [r0]
	ldr r5, _080A37A0
	add r5, r9
	movs r6, 0x88
	lsls r6, 3
	add r6, r9
	ldr r2, _080A37A4
	movs r0, 0xA9
	lsls r0, 3
	add r0, r9
	ldr r3, [r0]
	ldr r0, _080A37A8
	add r0, r9
	ldr r0, [r0]
	str r0, [sp]
	ldr r0, [sp, 0x34]
	str r0, [sp, 0x4]
	ldr r1, [sp, 0x38]
	str r1, [sp, 0x8]
	movs r0, 0x40
	str r0, [sp, 0xC]
	mov r1, r10
	ldrb r0, [r1, 0x5]
	str r0, [sp, 0x10]
	ldr r0, [r4]
	str r0, [sp, 0x14]
	mov r0, r8
	str r0, [sp, 0x18]
	adds r0, r5, 0
	adds r1, r6, 0
	bl sub_80ADD9C
	ldr r0, [r5]
	movs r1, 0
	bl GetFileDataPtr
	ldr r0, [r6]
	movs r1, 0
	bl GetFileDataPtr
	movs r2, 0xA8
	lsls r2, 3
	add r2, r9
	ldr r0, [r4]
	ldr r1, _080A37AC
	add r1, r9
	movs r4, 0
	ldrsh r3, [r1, r4]
	ldr r4, [r2]
	adds r1, r7, 0
	mov r2, r10
	bl _call_via_r4
	movs r0, 0x80
	lsls r0, 2
	ldr r1, [sp, 0x3C]
	strh r0, [r1, 0x4]
	ldr r1, [sp, 0x48]
	movs r2, 0
	adds r0, r1, 0x6
_080A35EA:
	strh r2, [r0]
	subs r0, 0x2
	cmp r0, r1
	bge _080A35EA
	movs r2, 0
	movs r0, 0xFA
	ldr r4, [sp, 0x3C]
	strh r0, [r4, 0xE]
	ldr r1, _080A378C
	add r1, r9
	movs r0, 0xC
	strh r0, [r1]
	ldr r0, _080A37B0
	add r0, r9
	strh r2, [r0]
	ldr r0, _080A37A0
	add r0, r9
	ldr r0, [r0]
	cmp r0, 0
	beq _080A36E6
	ldr r4, [r0, 0x4]
	movs r7, 0
	str r7, [sp, 0x1C]
	add r1, sp, 0x20
	movs r0, 0xFF
	strb r0, [r1]
	movs r0, 0x1
	negs r0, r0
	strb r0, [r1, 0x1]
	strb r0, [r1, 0x2]
	movs r0, 0
	strb r0, [r1, 0x3]
	movs r5, 0
	ldr r0, _080A37B4
	add r0, r9
	movs r1, 0
	ldrsh r0, [r0, r1]
	cmp r5, r0
	bge _080A36E6
	mov r2, sp
	adds r2, 0x28
	str r2, [sp, 0x40]
	mov r0, sp
	adds r0, 0x29
	str r0, [sp, 0x44]
	movs r1, 0x2A
	add r1, sp
	mov r10, r1
	movs r2, 0x2B
	add r2, sp
	mov r8, r2
_080A3650:
	adds r0, r7, 0
	adds r1, r0, 0x1
	lsls r1, 16
	lsrs r7, r1, 16
	ldr r1, [sp, 0x1C]
	bl sub_8003810
	adds r4, 0x4
	adds r6, r5, 0x1
	movs r5, 0xE
_080A3664:
	ldrb r0, [r4]
	ldr r1, [sp, 0x40]
	strb r0, [r1]
	ldrb r0, [r4, 0x1]
	ldr r2, [sp, 0x44]
	strb r0, [r2]
	ldrb r0, [r4, 0x2]
	mov r1, r10
	strb r0, [r1]
	ldrb r0, [r4, 0x3]
	mov r2, r8
	strb r0, [r2]
	ldr r1, [sp, 0x28]
	str r1, [sp, 0x24]
	adds r0, r7, 0
	adds r2, r0, 0x1
	lsls r2, 16
	lsrs r7, r2, 16
	bl sub_8003810
	adds r4, 0x4
	subs r5, 0x1
	cmp r5, 0
	bge _080A3664
	adds r5, r6, 0
	cmp r5, 0xB
	bgt _080A36A6
	ldr r0, _080A37B4
	add r0, r9
	movs r1, 0
	ldrsh r0, [r0, r1]
	cmp r5, r0
	blt _080A3650
_080A36A6:
	ldr r0, _080A37B4
	add r0, r9
	movs r2, 0
	ldrsh r0, [r0, r2]
	cmp r5, r0
	bge _080A36E6
_080A36B2:
	adds r0, r7, 0
	adds r1, r0, 0x1
	lsls r1, 16
	lsrs r7, r1, 16
	ldr r1, [sp, 0x1C]
	bl sub_8003810
	adds r6, r5, 0x1
	movs r5, 0xE
_080A36C4:
	adds r0, r7, 0
	adds r1, r0, 0x1
	lsls r1, 16
	lsrs r7, r1, 16
	ldr r1, [sp, 0x20]
	bl sub_8003810
	subs r5, 0x1
	cmp r5, 0
	bge _080A36C4
	adds r5, r6, 0
	ldr r0, _080A37B4
	add r0, r9
	movs r4, 0
	ldrsh r0, [r0, r4]
	cmp r5, r0
	blt _080A36B2
_080A36E6:
	mov r4, r9
	movs r0, 0x88
	lsls r0, 3
	add r0, r9
	ldr r1, [r0]
	cmp r1, 0
	beq _080A36FE
	mov r0, r9
	adds r0, 0xE0
	movs r2, 0x20
	bl sub_8004AA4
_080A36FE:
	ldr r0, _080A37B8
	add r0, r9
	movs r1, 0
	str r1, [r0]
	movs r0, 0x8E
	lsls r0, 3
	add r0, r9
	strb r1, [r0]
	ldr r0, _080A37BC
	add r0, r9
	strb r1, [r0]
	movs r0, 0
	movs r1, 0xD
_080A3718:
	strh r0, [r4]
	strh r0, [r4, 0x2]
	str r0, [r4, 0x8]
	str r0, [r4, 0x4]
	subs r1, 0x1
	adds r4, 0x10
	cmp r1, 0
	bge _080A3718
	movs r1, 0
	movs r0, 0xF8
	lsls r0, 2
	add r0, r9
	movs r2, 0x1
_080A3732:
	strb r1, [r0]
	strb r1, [r0, 0x1]
	strh r1, [r0, 0x4]
	strh r1, [r0, 0x2]
	str r1, [r0, 0x8]
	str r1, [r0, 0xC]
	str r1, [r0, 0x14]
	str r1, [r0, 0x10]
	str r1, [r0, 0x1C]
	str r1, [r0, 0x18]
	str r1, [r0, 0x20]
	str r1, [r0, 0x24]
	adds r0, 0x28
	subs r2, 0x1
	cmp r2, 0
	bge _080A3732
	mov r0, r9
	movs r1, 0
	bl sub_80A3BB0
	movs r0, 0x91
	lsls r0, 3
	add r0, r9
	bl sub_80A3EB0
	ldr r1, _080A37C0
	add r1, r9
	movs r0, 0x1
	strb r0, [r1]
_080A376C:
	add sp, 0x4C
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_080A377C: .4byte 0x00000444
_080A3780: .4byte gUnknown_81188F0
_080A3784: .4byte gUnknown_9890000
_080A3788: .4byte 0x00000434
_080A378C: .4byte 0x00000464
_080A3790: .4byte 0x00000454
_080A3794: .4byte 0x0000045a
_080A3798: .4byte 0x00000544
_080A379C: .4byte 0x0000052c
_080A37A0: .4byte 0x0000043c
_080A37A4: .4byte 0x06008000
_080A37A8: .4byte 0x0000054c
_080A37AC: .4byte 0x0000053a
_080A37B0: .4byte 0x00000466
_080A37B4: .4byte 0x0000052e
_080A37B8: .4byte 0x0000046c
_080A37BC: .4byte 0x00000471
_080A37C0: .4byte 0x0000052a
	thumb_func_end sub_80A3440

	thumb_func_start sub_80A37C4
sub_80A37C4:
	push {r4-r6,lr}
	adds r6, r2, 0
	adds r4, r1, 0
	adds r2, r0, 0
	movs r0, 0
	movs r1, 0xF
_080A37D0:
	strh r0, [r2]
	adds r2, 0x2
	subs r1, 0x1
	cmp r1, 0
	bge _080A37D0
	movs r0, 0x1
	movs r1, 0x4
	ldrsh r3, [r3, r1]
	cmp r0, r3
	bge _080A37FE
	adds r5, r3, 0
_080A37E6:
	adds r3, r0, 0x1
	movs r1, 0xF
_080A37EA:
	ldrh r0, [r4]
	strh r0, [r2]
	adds r4, 0x2
	adds r2, 0x2
	subs r1, 0x1
	cmp r1, 0
	bge _080A37EA
	adds r0, r3, 0
	cmp r0, r5
	blt _080A37E6
_080A37FE:
	movs r3, 0x6
	ldrsh r1, [r6, r3]
	cmp r0, r1
	bge _080A3820
	ldr r3, _080A3828
	adds r4, r3, 0
	adds r5, r1, 0
_080A380C:
	adds r3, r0, 0x1
	movs r1, 0xF
_080A3810:
	strh r4, [r2]
	adds r2, 0x2
	subs r1, 0x1
	cmp r1, 0
	bge _080A3810
	adds r0, r3, 0
	cmp r0, r5
	blt _080A380C
_080A3820:
	pop {r4-r6}
	pop {r0}
	bx r0
	.align 2, 0
_080A3828: .4byte 0x0000ffff
	thumb_func_end sub_80A37C4

	thumb_func_start _UncompressCell
_UncompressCell:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	adds r5, r1, 0
	mov r8, r3
	ldr r3, [sp, 0x18]
	adds r4, r2, 0
	adds r2, r0, 0
	mov r1, r8
	ldrh r0, [r1]
	lsls r0, 12
	ldrh r1, [r1, 0x4]
	orrs r0, r1
	lsls r0, 16
	lsrs r6, r0, 16
	ldr r1, [r3]
	ldr r0, _080A385C
	cmp r1, r0
	bne _080A3860
	movs r0, 0x1
	strh r0, [r5]
	movs r5, 0x4
	b _080A3890
	.align 2, 0
_080A385C: .4byte 0x00020002
_080A3860:
	ldr r0, _080A3870
	cmp r1, r0
	bne _080A3874
	movs r0, 0x2
	strh r0, [r5]
	movs r5, 0x9
	b _080A3890
	.align 2, 0
_080A3870: .4byte 0x00030003
_080A3874:
	movs r0, 0
	strh r0, [r5]
	ldr r0, _080A3888
	ldr r1, _080A388C
	movs r4, 0
	ldrsh r2, [r3, r4]
	movs r6, 0x2
	ldrsh r3, [r3, r6]
	bl FatalError
	.align 2, 0
_080A3888: .4byte gUnknown_81172E8
_080A388C: .4byte gUnknown_81172F4
_080A3890:
	movs r0, 0
	movs r1, 0x8
_080A3894:
	strh r0, [r2]
	adds r2, 0x2
	subs r1, 0x1
	cmp r1, 0
	bge _080A3894
	movs r0, 0x1
	movs r7, 0xE
	ldrsh r1, [r3, r7]
	cmp r0, r1
	bge _080A38DC
	mov r12, r1
_080A38AA:
	movs r1, 0
	adds r3, r0, 0x1
	cmp r1, r5
	bge _080A38C6
	adds r1, r5, 0
_080A38B4:
	ldrh r0, [r4]
	adds r0, r6, r0
	strh r0, [r2]
	adds r4, 0x2
	adds r2, 0x2
	subs r1, 0x1
	cmp r1, 0
	bne _080A38B4
	adds r1, r5, 0
_080A38C6:
	cmp r1, 0x8
	bgt _080A38D6
	movs r0, 0
_080A38CC:
	strh r0, [r2]
	adds r2, 0x2
	adds r1, 0x1
	cmp r1, 0x8
	ble _080A38CC
_080A38D6:
	adds r0, r3, 0
	cmp r0, r12
	blt _080A38AA
_080A38DC:
	mov r1, r8
	movs r4, 0x8
	ldrsh r3, [r1, r4]
	cmp r0, r3
	bge _080A38FE
	movs r4, 0
	adds r5, r3, 0
_080A38EA:
	adds r3, r0, 0x1
	movs r1, 0x8
_080A38EE:
	strh r4, [r2]
	adds r2, 0x2
	subs r1, 0x1
	cmp r1, 0
	bge _080A38EE
	adds r0, r3, 0
	cmp r0, r5
	blt _080A38EA
_080A38FE:
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end _UncompressCell

	thumb_func_start sub_80A3908
sub_80A3908:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x10
	str r0, [sp]
	str r2, [sp, 0x4]
	mov r9, r3
	adds r6, r1, 0
	movs r2, 0
	ldr r1, [sp, 0x4]
	movs r3, 0xC
	ldrsh r0, [r1, r3]
	cmp r2, r0
	blt _080A392A
	b _080A3B6C
_080A392A:
	lsls r0, r2, 2
	ldr r4, [sp]
	adds r0, r4
	ldr r0, [r0]
	mov r12, r0
	movs r1, 0
	adds r2, 0x1
	str r2, [sp, 0x8]
	mov r5, r9
	ldrb r5, [r5, 0x5]
	cmp r1, r5
	blt _080A3944
	b _080A3B2A
_080A3944:
	ldr r0, _080A39A4
	mov r10, r0
_080A3948:
	movs r2, 0
	mov r8, r2
	cmp r1, 0
	bne _080A3A18
	movs r3, 0x1
	str r3, [sp, 0xC]
	mov r4, r9
	ldrb r4, [r4, 0x4]
	cmp r1, r4
	blt _080A395E
	b _080A3B04
_080A395E:
	ldrb r1, [r6]
	adds r6, 0x1
	cmp r1, 0xBF
	ble _080A39A8
	adds r2, r1, 0
	subs r2, 0xBF
	cmp r1, 0xBF
	ble _080A39A0
	ldr r5, _080A39A4
	adds r4, r5, 0
	adds r3, r2, 0
_080A3974:
	ldrb r1, [r6]
	ldrb r0, [r6, 0x1]
	lsls r0, 8
	orrs r1, r0
	ldrb r0, [r6, 0x2]
	lsls r0, 16
	orrs r1, r0
	adds r6, 0x3
	adds r0, r1, 0
	ands r0, r4
	mov r5, r12
	strh r0, [r5]
	movs r0, 0x2
	add r12, r0
	asrs r1, 12
	ands r1, r4
	mov r5, r12
	strh r1, [r5]
	add r12, r0
	subs r3, 0x1
	cmp r3, 0
	bne _080A3974
_080A39A0:
	lsls r0, r2, 1
	b _080A3A0C
	.align 2, 0
_080A39A4: .4byte 0x00000fff
_080A39A8:
	cmp r1, 0x7F
	ble _080A39EA
	ldrb r2, [r6]
	ldrb r0, [r6, 0x1]
	lsls r0, 8
	orrs r2, r0
	ldrb r0, [r6, 0x2]
	lsls r0, 16
	orrs r2, r0
	adds r6, 0x3
	adds r4, r1, 0
	subs r4, 0x7F
	cmp r1, 0x7F
	ble _080A39E6
	adds r0, r2, 0
	mov r1, r10
	ands r0, r1
	asrs r1, r2, 12
	mov r2, r10
	ands r1, r2
	adds r3, r4, 0
_080A39D2:
	mov r5, r12
	strh r0, [r5]
	movs r2, 0x2
	add r12, r2
	mov r5, r12
	strh r1, [r5]
	add r12, r2
	subs r3, 0x1
	cmp r3, 0
	bne _080A39D2
_080A39E6:
	lsls r0, r4, 1
	b _080A3A0C
_080A39EA:
	movs r3, 0
	adds r0, r1, 0x1
	cmp r3, r1
	bgt _080A3A0A
	movs r1, 0
	adds r3, r0, 0
_080A39F6:
	mov r2, r12
	strh r1, [r2]
	movs r4, 0x2
	add r12, r4
	mov r5, r12
	strh r1, [r5]
	add r12, r4
	subs r3, 0x1
	cmp r3, 0
	bne _080A39F6
_080A3A0A:
	lsls r0, 1
_080A3A0C:
	add r8, r0
	mov r0, r9
	ldrb r0, [r0, 0x4]
	cmp r8, r0
	blt _080A395E
	b _080A3B04
_080A3A18:
	mov r4, r12
	subs r4, 0x80
	adds r1, 0x1
	str r1, [sp, 0xC]
	mov r1, r9
	ldrb r1, [r1, 0x4]
	cmp r8, r1
	bge _080A3B04
_080A3A28:
	ldrb r1, [r6]
	adds r6, 0x1
	cmp r1, 0xBF
	ble _080A3A80
	adds r5, r1, 0
	subs r5, 0xBF
	cmp r1, 0xBF
	ble _080A3A78
	ldr r2, _080A3A7C
	adds r7, r2, 0
	adds r3, r5, 0
_080A3A3E:
	ldrb r2, [r6]
	ldrb r0, [r6, 0x1]
	lsls r0, 8
	orrs r2, r0
	ldrb r0, [r6, 0x2]
	lsls r0, 16
	orrs r2, r0
	adds r6, 0x3
	adds r0, r2, 0
	ands r0, r7
	ldrh r1, [r4]
	eors r0, r1
	mov r1, r12
	strh r0, [r1]
	adds r4, 0x2
	movs r0, 0x2
	add r12, r0
	asrs r2, 12
	ands r2, r7
	ldrh r0, [r4]
	eors r2, r0
	mov r1, r12
	strh r2, [r1]
	adds r4, 0x2
	movs r2, 0x2
	add r12, r2
	subs r3, 0x1
	cmp r3, 0
	bne _080A3A3E
_080A3A78:
	lsls r0, r5, 1
	b _080A3AFA
	.align 2, 0
_080A3A7C: .4byte 0x00000fff
_080A3A80:
	cmp r1, 0x7F
	ble _080A3AD2
	ldrb r2, [r6]
	ldrb r0, [r6, 0x1]
	lsls r0, 8
	orrs r2, r0
	ldrb r0, [r6, 0x2]
	lsls r0, 16
	orrs r2, r0
	adds r6, 0x3
	adds r7, r1, 0
	subs r7, 0x7F
	cmp r1, 0x7F
	ble _080A3ACE
	adds r5, r2, 0
	mov r3, r10
	ands r5, r3
	asrs r2, 12
	ands r2, r3
	adds r3, r7, 0
_080A3AA8:
	ldrh r1, [r4]
	adds r0, r5, 0
	eors r0, r1
	mov r1, r12
	strh r0, [r1]
	adds r4, 0x2
	movs r0, 0x2
	add r12, r0
	ldrh r1, [r4]
	adds r0, r2, 0
	eors r0, r1
	mov r1, r12
	strh r0, [r1]
	adds r4, 0x2
	movs r0, 0x2
	add r12, r0
	subs r3, 0x1
	cmp r3, 0
	bne _080A3AA8
_080A3ACE:
	lsls r0, r7, 1
	b _080A3AFA
_080A3AD2:
	movs r3, 0
	adds r2, r1, 0x1
	cmp r3, r1
	bgt _080A3AF8
	adds r3, r2, 0
_080A3ADC:
	ldrh r0, [r4]
	mov r1, r12
	strh r0, [r1]
	adds r4, 0x2
	movs r5, 0x2
	add r12, r5
	ldrh r0, [r4]
	mov r1, r12
	strh r0, [r1]
	adds r4, 0x2
	add r12, r5
	subs r3, 0x1
	cmp r3, 0
	bne _080A3ADC
_080A3AF8:
	lsls r0, r2, 1
_080A3AFA:
	add r8, r0
	mov r2, r9
	ldrb r2, [r2, 0x4]
	cmp r8, r2
	blt _080A3A28
_080A3B04:
	mov r3, r8
	cmp r3, 0x3F
	bgt _080A3B1E
	movs r0, 0
_080A3B0C:
	mov r4, r12
	strh r0, [r4]
	movs r5, 0x2
	add r12, r5
	movs r1, 0x1
	add r8, r1
	mov r2, r8
	cmp r2, 0x3F
	ble _080A3B0C
_080A3B1E:
	ldr r1, [sp, 0xC]
	mov r3, r9
	ldrb r3, [r3, 0x5]
	cmp r1, r3
	bge _080A3B2A
	b _080A3948
_080A3B2A:
	ldr r4, [sp, 0x4]
	movs r5, 0x10
	ldrsh r0, [r4, r5]
	cmp r1, r0
	bge _080A3B5E
	movs r2, 0
_080A3B36:
	adds r1, 0x1
	str r1, [sp, 0xC]
	movs r0, 0x3F
	mov r8, r0
_080A3B3E:
	mov r1, r12
	strh r2, [r1]
	movs r3, 0x2
	add r12, r3
	movs r4, 0x1
	negs r4, r4
	add r8, r4
	mov r5, r8
	cmp r5, 0
	bge _080A3B3E
	ldr r1, [sp, 0xC]
	ldr r3, [sp, 0x4]
	movs r4, 0x10
	ldrsh r0, [r3, r4]
	cmp r1, r0
	blt _080A3B36
_080A3B5E:
	ldr r2, [sp, 0x8]
	ldr r5, [sp, 0x4]
	movs r1, 0xC
	ldrsh r0, [r5, r1]
	cmp r2, r0
	bge _080A3B6C
	b _080A392A
_080A3B6C:
	adds r0, r6, 0
	add sp, 0x10
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_80A3908

	thumb_func_start sub_80A3B80
sub_80A3B80:
	push {r4,lr}
	adds r3, r0, 0
	lsls r1, 24
	lsrs r1, 24
	lsls r2, 24
	lsrs r2, 24
	ldr r4, _080A3BA8
	adds r0, r3, r4
	ldr r0, [r0]
	cmp r0, 0
	beq _080A3BA2
	adds r4, 0x4
	adds r0, r3, r4
	strb r1, [r0]
	ldr r1, _080A3BAC
	adds r0, r3, r1
	strb r2, [r0]
_080A3BA2:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080A3BA8: .4byte 0x0000046c
_080A3BAC: .4byte 0x00000471
	thumb_func_end sub_80A3B80

	thumb_func_start sub_80A3BB0
sub_80A3BB0:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0x4
	adds r5, r0, 0
	lsls r1, 16
	asrs r1, 16
	adds r6, r1, 0
	movs r0, 0x91
	lsls r0, 3
	adds r0, r5
	mov r8, r0
	cmp r1, 0
	blt _080A3BD4
	cmp r1, 0x1
	ble _080A3BD4
	cmp r1, 0x4
	ble _080A3C00
_080A3BD4:
	ldr r1, _080A3BFC
	adds r0, r5, r1
	movs r1, 0x1
	str r1, [r0]
	movs r2, 0xA7
	lsls r2, 3
	adds r0, r5, r2
	movs r1, 0
	ldrsh r3, [r0, r1]
	movs r0, 0
	cmp r6, 0x1
	bne _080A3BEE
	movs r0, 0x1
_080A3BEE:
	str r0, [sp]
	mov r0, r8
	adds r1, r5, 0
	movs r2, 0
	bl sub_80A3D40
	b _080A3C48
	.align 2, 0
_080A3BFC: .4byte 0x00000474
_080A3C00:
	ldr r2, _080A3C88
	adds r0, r5, r2
	movs r7, 0x2
	str r7, [r0]
	movs r0, 0xA7
	lsls r0, 3
	adds r4, r5, r0
	movs r2, 0
	ldrsh r0, [r4, r2]
	subs r3, r0, 0x1
	movs r0, 0
	cmp r1, 0x4
	bne _080A3C1C
	movs r0, 0x1
_080A3C1C:
	str r0, [sp]
	mov r0, r8
	adds r1, r5, 0
	movs r2, 0
	bl sub_80A3D40
	movs r1, 0x9B
	lsls r1, 3
	adds r0, r5, r1
	movs r1, 0
	ldrsh r2, [r4, r1]
	subs r2, 0x1
	adds r3, r7, 0
	eors r3, r6
	negs r1, r3
	orrs r1, r3
	lsrs r1, 31
	str r1, [sp]
	adds r1, r5, 0
	movs r3, 0x1
	bl sub_80A3D40
_080A3C48:
	movs r6, 0
	ldr r2, _080A3C88
	adds r0, r5, r2
	ldr r0, [r0]
	cmp r6, r0
	bge _080A3CF0
	movs r0, 0x8F
	lsls r0, 3
	adds r7, r5, r0
	mov r4, r8
_080A3C5C:
	adds r0, r5, 0
	adds r1, r6, 0
	ldr r2, _080A3C8C
	bl sub_80A456C
	movs r1, 0x4
	ldrsh r0, [r4, r1]
	cmp r0, 0x1
	beq _080A3C72
	cmp r0, 0x2
	beq _080A3CB4
_080A3C72:
	movs r2, 0
	ldrsh r0, [r4, r2]
	cmp r0, 0x1
	beq _080A3C94
	cmp r0, 0x1
	ble _080A3C82
	cmp r0, 0x2
	beq _080A3C9C
_080A3C82:
	ldr r0, _080A3C90
	b _080A3CD6
	.align 2, 0
_080A3C88: .4byte 0x00000474
_080A3C8C: .4byte gUnknown_8117314
_080A3C90: .4byte sub_80A3EBC
_080A3C94:
	ldr r0, _080A3C98
	b _080A3CD6
	.align 2, 0
_080A3C98: .4byte sub_80A3EF4
_080A3C9C:
	ldrb r0, [r4, 0x6]
	ldr r1, _080A3CAC
	cmp r0, 0
	beq _080A3CA6
	ldr r1, _080A3CB0
_080A3CA6:
	str r1, [r4, 0x18]
	b _080A3CD8
	.align 2, 0
_080A3CAC: .4byte sub_80A4088
_080A3CB0: .4byte sub_80A41C4
_080A3CB4:
	movs r1, 0
	ldrsh r0, [r4, r1]
	cmp r0, 0x1
	beq _080A3CCC
	cmp r0, 0x1
	ble _080A3CC4
	cmp r0, 0x2
	beq _080A3CD4
_080A3CC4:
	ldr r0, _080A3CC8
	b _080A3CD6
	.align 2, 0
_080A3CC8: .4byte sub_80A3ED4
_080A3CCC:
	ldr r0, _080A3CD0
	b _080A3CD6
	.align 2, 0
_080A3CD0: .4byte sub_80A3F94
_080A3CD4:
	ldr r0, _080A3D34
_080A3CD6:
	str r0, [r4, 0x18]
_080A3CD8:
	adds r0, r4, 0
	adds r1, r7, 0
	bl sub_80A3E14
	adds r7, 0x8
	adds r4, 0x50
	adds r6, 0x1
	ldr r2, _080A3D38
	adds r0, r5, r2
	ldr r0, [r0]
	cmp r6, r0
	blt _080A3C5C
_080A3CF0:
	ldr r1, _080A3D38
	adds r0, r5, r1
	ldr r6, [r0]
	cmp r6, 0x1
	bgt _080A3D26
	lsls r0, r6, 2
	adds r0, r6
	lsls r0, 4
	mov r2, r8
	adds r4, r0, r2
_080A3D04:
	adds r0, r5, 0
	adds r1, r6, 0
	ldr r2, _080A3D3C
	bl sub_80A456C
	movs r0, 0
	str r0, [sp]
	adds r0, r4, 0
	adds r1, r5, 0
	movs r2, 0
	movs r3, 0
	bl sub_80A3D40
	adds r4, 0x50
	adds r6, 0x1
	cmp r6, 0x1
	ble _080A3D04
_080A3D26:
	add sp, 0x4
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_080A3D34: .4byte sub_80A4358
_080A3D38: .4byte 0x00000474
_080A3D3C: .4byte gUnknown_8117314
	thumb_func_end sub_80A3BB0

	thumb_func_start sub_80A3D40
sub_80A3D40:
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	adds r4, r0, 0
	adds r5, r1, 0
	mov r8, r3
	ldr r1, [sp, 0x1C]
	movs r3, 0xA5
	lsls r3, 3
	adds r0, r5, r3
	ldrh r0, [r0]
	strh r0, [r4]
	strh r2, [r4, 0x2]
	mov r7, r8
	strh r7, [r4, 0x4]
	strb r1, [r4, 0x6]
	ldr r1, _080A3E10
	adds r0, r5, r1
	ldrb r0, [r0]
	str r0, [r4, 0x8]
	subs r3, 0xDB
	adds r0, r5, r3
	ldrb r0, [r0]
	str r0, [r4, 0xC]
	movs r7, 0x89
	lsls r7, 3
	adds r0, r5, r7
	ldrb r0, [r0]
	lsls r0, 3
	str r0, [r4, 0x10]
	subs r1, 0x3
	adds r0, r5, r1
	ldrb r0, [r0]
	lsls r0, 3
	str r0, [r4, 0x14]
	adds r3, 0xFB
	adds r0, r5, r3
	ldr r0, [r0]
	str r0, [r4, 0x1C]
	movs r3, 0
	cmp r3, r8
	bge _080A3DE0
	adds r7, 0xF0
	adds r6, r5, r7
	movs r1, 0
	ldrsh r0, [r6, r1]
	cmp r2, r0
	bge _080A3DE0
	lsls r0, r2, 2
	adds r7, 0x14
	adds r0, r7
	adds r1, r0, r5
	movs r0, 0x20
	adds r0, r4
	mov r12, r0
	movs r7, 0x28
	adds r7, r4
	mov r9, r7
_080A3DB6:
	ldr r0, [r1]
	mov r7, r12
	adds r7, 0x4
	mov r12, r7
	subs r7, 0x4
	stm r7!, {r0}
	ldr r0, [r1, 0x8]
	mov r7, r9
	adds r7, 0x4
	mov r9, r7
	subs r7, 0x4
	stm r7!, {r0}
	adds r3, 0x1
	adds r1, 0x4
	adds r2, 0x1
	cmp r3, r8
	bge _080A3DE0
	movs r7, 0
	ldrsh r0, [r6, r7]
	cmp r2, r0
	blt _080A3DB6
_080A3DE0:
	cmp r3, 0x1
	bgt _080A3DF8
	movs r1, 0
	lsls r0, r3, 2
	adds r0, 0x20
	adds r0, r4
_080A3DEC:
	str r1, [r0]
	str r1, [r0, 0x8]
	adds r0, 0x4
	adds r3, 0x1
	cmp r3, 0x1
	ble _080A3DEC
_080A3DF8:
	movs r0, 0x8F
	lsls r0, 3
	adds r1, r5, r0
	adds r0, r4, 0
	bl sub_80A3E14
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_080A3E10: .4byte 0x0000044c
	thumb_func_end sub_80A3D40

	thumb_func_start sub_80A3E14
sub_80A3E14:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	adds r4, r0, 0
	adds r0, r1, 0
	ldr r1, [r0]
	mov r8, r1
	str r1, [r4, 0x30]
	cmp r1, 0
	bge _080A3E2A
	adds r1, 0x7
_080A3E2A:
	asrs r6, r1, 3
	str r6, [r4, 0x38]
	ldr r7, [r0, 0x4]
	str r7, [r4, 0x34]
	adds r0, r7, 0
	cmp r7, 0
	bge _080A3E3A
	adds r0, r7, 0x7
_080A3E3A:
	asrs r5, r0, 3
	str r5, [r4, 0x3C]
	movs r3, 0
	ldrsh r2, [r4, r3]
	cmp r2, 0x1
	beq _080A3E60
	cmp r2, 0x1
	bgt _080A3E50
	cmp r2, 0
	beq _080A3E56
	b _080A3EA4
_080A3E50:
	cmp r2, 0x2
	beq _080A3E7E
	b _080A3EA4
_080A3E56:
	str r2, [r4, 0x40]
	str r2, [r4, 0x44]
	str r2, [r4, 0x48]
	str r2, [r4, 0x4C]
	b _080A3EA4
_080A3E60:
	lsrs r1, 31
	adds r1, r6, r1
	asrs r1, 1
	str r1, [r4, 0x40]
	lsrs r0, 31
	adds r0, r5, r0
	asrs r0, 1
	str r0, [r4, 0x44]
	lsls r1, 4
	mov r2, r8
	subs r1, r2, r1
	str r1, [r4, 0x48]
	lsls r0, 4
	subs r0, r7, r0
	b _080A3EA2
_080A3E7E:
	adds r0, r6, 0
	movs r1, 0x3
	bl __divsi3
	str r0, [r4, 0x40]
	adds r0, r5, 0
	movs r1, 0x3
	bl __divsi3
	str r0, [r4, 0x44]
	lsls r0, r6, 3
	mov r3, r8
	subs r0, r3, r0
	str r0, [r4, 0x48]
	adds r0, r7, 0
	movs r1, 0x18
	bl __modsi3
_080A3EA2:
	str r0, [r4, 0x4C]
_080A3EA4:
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_80A3E14

	thumb_func_start sub_80A3EB0
sub_80A3EB0:
	push {lr}
	ldr r1, [r0, 0x18]
	bl _call_via_r1
	pop {r0}
	bx r0
	thumb_func_end sub_80A3EB0

	thumb_func_start sub_80A3EBC
sub_80A3EBC:
	push {lr}
	ldr r0, [r0, 0x28]
	movs r2, 0
	movs r1, 0x80
	lsls r1, 3
_080A3EC6:
	strh r2, [r0]
	adds r0, 0x2
	subs r1, 0x1
	cmp r1, 0
	bne _080A3EC6
	pop {r0}
	bx r0
	thumb_func_end sub_80A3EBC

	thumb_func_start sub_80A3ED4
sub_80A3ED4:
	push {lr}
	ldr r1, [r0, 0x28]
	ldr r0, [r0, 0x2C]
	movs r3, 0
	movs r2, 0x80
	lsls r2, 3
_080A3EE0:
	strh r3, [r1]
	adds r1, 0x2
	strh r3, [r0]
	adds r0, 0x2
	subs r2, 0x1
	cmp r2, 0
	bne _080A3EE0
	pop {r0}
	bx r0
	thumb_func_end sub_80A3ED4

	thumb_func_start sub_80A3EF4
sub_80A3EF4:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x10
	ldr r1, [r0, 0x44]
	lsls r1, 6
	ldr r2, [r0, 0x40]
	adds r1, r2
	lsls r1, 1
	ldr r2, [r0, 0x20]
	adds r2, r1
	movs r1, 0
	mov r12, r1
	ldr r3, [r0, 0x28]
	str r3, [sp, 0xC]
	ldr r0, [r0, 0x1C]
	mov r10, r0
	mov r0, sp
	str r0, [sp, 0x8]
_080A3F1E:
	adds r5, r2, 0
	movs r2, 0x80
	adds r2, r5
	mov r9, r2
	adds r1, 0x1
	mov r8, r1
	ldr r1, [sp, 0x8]
	mov r3, r12
	lsls r0, r3, 1
	ldr r2, [sp, 0xC]
	adds r0, r2
	movs r2, 0x1
_080A3F36:
	stm r1!, {r0}
	adds r0, 0x40
	movs r3, 0x20
	add r12, r3
	subs r2, 0x1
	cmp r2, 0
	bge _080A3F36
	movs r4, 0
	mov r7, sp
_080A3F48:
	ldrh r1, [r5]
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 1
	mov r1, r10
	adds r3, r1, r0
	adds r5, 0x2
	adds r6, r4, 0x1
	adds r4, r7, 0
	movs r2, 0x1
_080A3F5C:
	ldr r0, [r4]
	ldrh r1, [r3]
	strh r1, [r0]
	adds r3, 0x2
	adds r0, 0x2
	ldrh r1, [r3]
	strh r1, [r0]
	adds r3, 0x2
	adds r0, 0x2
	stm r4!, {r0}
	subs r2, 0x1
	cmp r2, 0
	bge _080A3F5C
	adds r4, r6, 0
	cmp r4, 0xF
	ble _080A3F48
	mov r2, r9
	mov r1, r8
	cmp r1, 0xA
	ble _080A3F1E
	add sp, 0x10
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_80A3EF4

	thumb_func_start sub_80A3F94
sub_80A3F94:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x34
	ldr r1, [r0, 0x44]
	lsls r1, 6
	ldr r2, [r0, 0x40]
	adds r1, r2
	lsls r1, 1
	ldr r2, [r0, 0x20]
	adds r3, r2, r1
	ldr r2, [r0, 0x24]
	adds r2, r1
	movs r1, 0
	ldr r4, [r0, 0x28]
	str r4, [sp, 0x2C]
	ldr r5, [r0, 0x2C]
	str r5, [sp, 0x18]
	ldr r0, [r0, 0x1C]
	str r0, [sp, 0x1C]
	mov r0, sp
	str r0, [sp, 0x10]
	mov r4, sp
	adds r4, 0x8
	str r4, [sp, 0x14]
	movs r5, 0
	str r5, [sp, 0x30]
_080A3FCE:
	mov r8, r3
	mov r12, r2
	mov r0, r8
	adds r0, 0x80
	str r0, [sp, 0x20]
	mov r4, r12
	adds r4, 0x80
	str r4, [sp, 0x24]
	adds r1, 0x1
	str r1, [sp, 0x28]
	ldr r3, [sp, 0x14]
	ldr r2, [sp, 0x10]
	ldr r5, [sp, 0x30]
	ldr r0, [sp, 0x18]
	adds r1, r5, r0
	ldr r4, [sp, 0x2C]
	adds r0, r5, r4
	movs r5, 0x1
_080A3FF2:
	stm r2!, {r0}
	stm r3!, {r1}
	adds r1, 0x40
	adds r0, 0x40
	ldr r4, [sp, 0x30]
	adds r4, 0x40
	str r4, [sp, 0x30]
	subs r5, 0x1
	cmp r5, 0
	bge _080A3FF2
	movs r2, 0
	ldr r5, [sp, 0x1C]
	mov r9, r5
_080A400C:
	mov r0, r8
	ldrh r1, [r0]
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 1
	mov r1, r9
	adds r4, r1, r0
	movs r5, 0x2
	add r8, r5
	mov r0, r12
	ldrh r1, [r0]
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 1
	mov r1, r9
	adds r3, r1, r0
	add r12, r5
	movs r5, 0
	adds r2, 0x1
	mov r10, r2
	ldr r7, [sp, 0x14]
	ldr r6, [sp, 0x10]
_080A4038:
	ldr r1, [r6]
	ldr r2, [r7]
	ldrh r0, [r4]
	strh r0, [r1]
	adds r4, 0x2
	adds r1, 0x2
	ldrh r0, [r4]
	strh r0, [r1]
	adds r4, 0x2
	adds r1, 0x2
	ldrh r0, [r3]
	strh r0, [r2]
	adds r3, 0x2
	adds r2, 0x2
	ldrh r0, [r3]
	strh r0, [r2]
	adds r3, 0x2
	adds r2, 0x2
	stm r6!, {r1}
	stm r7!, {r2}
	adds r5, 0x1
	cmp r5, 0x1
	ble _080A4038
	mov r2, r10
	cmp r2, 0xF
	ble _080A400C
	ldr r3, [sp, 0x20]
	ldr r2, [sp, 0x24]
	ldr r1, [sp, 0x28]
	cmp r1, 0xA
	ble _080A3FCE
	add sp, 0x34
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_80A3F94

	thumb_func_start sub_80A4088
sub_80A4088:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x10
	adds r4, r0, 0
	ldr r0, [r4, 0x38]
	movs r1, 0x3
	bl __modsi3
	adds r7, r0, 0
	ldr r0, [r4, 0x44]
	lsls r0, 6
	ldr r1, [r4, 0x40]
	adds r0, r1
	lsls r0, 1
	ldr r1, [r4, 0x20]
	adds r1, r0
	movs r0, 0
	mov r8, r0
	ldr r2, [r4, 0x28]
	str r2, [sp, 0xC]
	ldr r4, [r4, 0x1C]
	mov r12, r4
_080A40BA:
	adds r5, r1, 0
	movs r1, 0x80
	adds r1, r5
	mov r9, r1
	adds r0, 0x1
	mov r10, r0
	mov r1, sp
	mov r2, r8
	lsls r0, r2, 1
	ldr r2, [sp, 0xC]
	adds r0, r2
	movs r3, 0x2
_080A40D2:
	stm r1!, {r0}
	adds r0, 0x40
	movs r2, 0x20
	add r8, r2
	subs r3, 0x1
	cmp r3, 0
	bge _080A40D2
	cmp r7, 0
	beq _080A412E
	ldrh r1, [r5]
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 1
	mov r1, r12
	adds r2, r1, r0
	adds r5, 0x2
	cmp r7, 0x1
	bne _080A4116
	adds r2, 0x2
	mov r4, sp
	movs r3, 0x2
_080A40FC:
	ldr r0, [r4]
	ldrh r1, [r2]
	strh r1, [r0]
	adds r0, 0x2
	ldrh r1, [r2, 0x2]
	strh r1, [r0]
	adds r0, 0x2
	stm r4!, {r0}
	adds r2, 0x6
	subs r3, 0x1
	cmp r3, 0
	bge _080A40FC
	b _080A412E
_080A4116:
	adds r2, 0x4
	mov r4, sp
	movs r3, 0x2
_080A411C:
	ldr r1, [r4]
	ldrh r0, [r2]
	strh r0, [r1]
	adds r1, 0x2
	stm r4!, {r1}
	adds r2, 0x6
	subs r3, 0x1
	cmp r3, 0
	bge _080A411C
_080A412E:
	movs r3, 0
_080A4130:
	ldrh r1, [r5]
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 1
	mov r1, r12
	adds r2, r1, r0
	adds r5, 0x2
	adds r6, r3, 0x1
	mov r4, sp
	movs r3, 0x2
_080A4144:
	ldr r1, [r4]
	ldrh r0, [r2]
	strh r0, [r1]
	adds r2, 0x2
	adds r1, 0x2
	ldrh r0, [r2]
	strh r0, [r1]
	adds r2, 0x2
	adds r1, 0x2
	ldrh r0, [r2]
	strh r0, [r1]
	adds r2, 0x2
	adds r1, 0x2
	stm r4!, {r1}
	subs r3, 0x1
	cmp r3, 0
	bge _080A4144
	adds r3, r6, 0
	cmp r3, 0x9
	ble _080A4130
	cmp r7, 0x1
	beq _080A41AA
	ldrh r1, [r5]
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 1
	mov r1, r12
	adds r2, r1, r0
	cmp r7, 0
	bne _080A4198
	mov r4, sp
	movs r3, 0x2
_080A4184:
	ldm r4!, {r0}
	ldrh r1, [r2]
	strh r1, [r0]
	ldrh r1, [r2, 0x2]
	strh r1, [r0, 0x2]
	adds r2, 0x6
	subs r3, 0x1
	cmp r3, 0
	bge _080A4184
	b _080A41AA
_080A4198:
	mov r4, sp
	movs r3, 0x2
_080A419C:
	ldm r4!, {r1}
	ldrh r0, [r2]
	strh r0, [r1]
	adds r2, 0x6
	subs r3, 0x1
	cmp r3, 0
	bge _080A419C
_080A41AA:
	mov r1, r9
	mov r0, r10
	cmp r0, 0x7
	ble _080A40BA
	add sp, 0x10
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_80A4088

	thumb_func_start sub_80A41C4
sub_80A41C4:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x20
	mov r8, r0
	ldr r0, [r0, 0x38]
	movs r1, 0x3
	bl __modsi3
	str r0, [sp, 0xC]
	mov r0, r8
	ldr r2, [r0, 0x44]
	lsls r0, r2, 6
	mov r1, r8
	ldr r3, [r1, 0x40]
	adds r0, r3
	lsls r0, 1
	ldr r1, [r1, 0x20]
	adds r4, r1, r0
	movs r0, 0
	str r0, [sp, 0x10]
	mov r1, r8
	ldr r0, [r1, 0xC]
	subs r0, r2
	mov r10, r0
	ldr r0, [r1, 0x8]
	subs r0, r3
	str r0, [sp, 0x14]
	movs r2, 0
_080A4202:
	ldr r5, [sp, 0x14]
	mov r3, r10
	cmp r3, 0
	ble _080A4212
	movs r0, 0x1
	negs r0, r0
	add r10, r0
	b _080A4222
_080A4212:
	mov r1, r8
	ldr r1, [r1, 0xC]
	mov r10, r1
	mov r3, r8
	ldr r0, [r3, 0x40]
	lsls r0, 1
	ldr r1, [r3, 0x20]
	adds r4, r1, r0
_080A4222:
	adds r6, r4, 0
	mov r0, r8
	ldr r1, [r0, 0x28]
	ldrh r7, [r4]
	ldr r3, [r0, 0x1C]
	mov r9, r3
	adds r0, r4, 0x2
	mov r12, r0
	adds r4, 0x80
	str r4, [sp, 0x18]
	adds r2, 0x1
	str r2, [sp, 0x1C]
	mov r2, sp
	ldr r3, [sp, 0x10]
	lsls r0, r3, 1
	adds r0, r1
	movs r3, 0x2
_080A4244:
	stm r2!, {r0}
	adds r0, 0x40
	ldr r4, [sp, 0x10]
	adds r4, 0x20
	str r4, [sp, 0x10]
	subs r3, 0x1
	cmp r3, 0
	bge _080A4244
	ldr r0, [sp, 0xC]
	cmp r0, 0
	beq _080A42B2
	lsls r0, r7, 3
	adds r0, r7
	lsls r0, 1
	mov r1, r9
	adds r2, r1, r0
	mov r6, r12
	ldr r3, [sp, 0xC]
	cmp r3, 0x1
	bne _080A428C
	adds r2, 0x2
	mov r4, sp
	movs r3, 0x2
_080A4272:
	ldr r0, [r4]
	ldrh r1, [r2]
	strh r1, [r0]
	adds r0, 0x2
	ldrh r1, [r2, 0x2]
	strh r1, [r0]
	adds r0, 0x2
	stm r4!, {r0}
	adds r2, 0x6
	subs r3, 0x1
	cmp r3, 0
	bge _080A4272
	b _080A42A4
_080A428C:
	adds r2, 0x4
	mov r4, sp
	movs r3, 0x2
_080A4292:
	ldr r1, [r4]
	ldrh r0, [r2]
	strh r0, [r1]
	adds r1, 0x2
	stm r4!, {r1}
	adds r2, 0x6
	subs r3, 0x1
	cmp r3, 0
	bge _080A4292
_080A42A4:
	subs r5, 0x1
	cmp r5, 0
	bgt _080A42B2
	mov r4, r8
	ldr r5, [r4, 0x8]
	lsls r0, r5, 1
	subs r6, r0
_080A42B2:
	movs r3, 0
_080A42B4:
	ldrh r1, [r6]
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 1
	mov r1, r9
	adds r2, r1, r0
	adds r6, 0x2
	subs r5, 0x1
	adds r7, r3, 0x1
	mov r4, sp
	movs r3, 0x2
_080A42CA:
	ldr r1, [r4]
	ldrh r0, [r2]
	strh r0, [r1]
	adds r2, 0x2
	adds r1, 0x2
	ldrh r0, [r2]
	strh r0, [r1]
	adds r2, 0x2
	adds r1, 0x2
	ldrh r0, [r2]
	strh r0, [r1]
	adds r2, 0x2
	adds r1, 0x2
	stm r4!, {r1}
	subs r3, 0x1
	cmp r3, 0
	bge _080A42CA
	cmp r5, 0
	bgt _080A42F8
	mov r3, r8
	ldr r5, [r3, 0x8]
	lsls r0, r5, 1
	subs r6, r0
_080A42F8:
	adds r3, r7, 0
	cmp r3, 0x9
	ble _080A42B4
	ldr r4, [sp, 0xC]
	cmp r4, 0x1
	beq _080A433E
	ldrh r1, [r6]
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 1
	mov r1, r9
	adds r2, r1, r0
	cmp r4, 0
	bne _080A432C
	mov r4, sp
	movs r3, 0x2
_080A4318:
	ldm r4!, {r0}
	ldrh r1, [r2]
	strh r1, [r0]
	ldrh r1, [r2, 0x2]
	strh r1, [r0, 0x2]
	adds r2, 0x6
	subs r3, 0x1
	cmp r3, 0
	bge _080A4318
	b _080A433E
_080A432C:
	mov r4, sp
	movs r3, 0x2
_080A4330:
	ldm r4!, {r1}
	ldrh r0, [r2]
	strh r0, [r1]
	adds r2, 0x6
	subs r3, 0x1
	cmp r3, 0
	bge _080A4330
_080A433E:
	ldr r4, [sp, 0x18]
	ldr r2, [sp, 0x1C]
	cmp r2, 0x7
	bgt _080A4348
	b _080A4202
_080A4348:
	add sp, 0x20
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_80A41C4

	thumb_func_start sub_80A4358
sub_80A4358:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x3C
	adds r4, r0, 0
	ldr r0, [r4, 0x38]
	movs r1, 0x3
	bl __modsi3
	str r0, [sp, 0x18]
	ldr r0, [r4, 0x44]
	lsls r0, 6
	ldr r1, [r4, 0x40]
	adds r0, r1
	lsls r0, 1
	ldr r1, [r4, 0x20]
	adds r2, r1, r0
	ldr r1, [r4, 0x24]
	adds r1, r0
	movs r0, 0
	ldr r3, [r4, 0x28]
	str r3, [sp, 0x24]
	ldr r5, [r4, 0x2C]
	str r5, [sp, 0x28]
	ldr r4, [r4, 0x1C]
	str r4, [sp, 0x20]
	mov r3, sp
	adds r3, 0xC
	str r3, [sp, 0x1C]
	movs r4, 0
	str r4, [sp, 0x38]
_080A439A:
	mov r12, r2
	mov r8, r1
	mov r5, r12
	adds r5, 0x80
	str r5, [sp, 0x30]
	adds r1, 0x80
	str r1, [sp, 0x34]
	adds r0, 0x1
	str r0, [sp, 0x2C]
	add r3, sp, 0xC
	mov r2, sp
	ldr r4, [sp, 0x38]
	ldr r5, [sp, 0x28]
	adds r1, r4, r5
	ldr r5, [sp, 0x24]
	adds r0, r4, r5
	movs r5, 0x2
_080A43BC:
	stm r2!, {r0}
	stm r3!, {r1}
	adds r1, 0x40
	adds r0, 0x40
	ldr r4, [sp, 0x38]
	adds r4, 0x40
	str r4, [sp, 0x38]
	subs r5, 0x1
	cmp r5, 0
	bge _080A43BC
	ldr r5, [sp, 0x18]
	cmp r5, 0
	beq _080A445C
	mov r0, r12
	ldrh r1, [r0]
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 1
	ldr r1, [sp, 0x20]
	adds r4, r1, r0
	movs r3, 0x2
	add r12, r3
	mov r5, r8
	ldrh r1, [r5]
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 1
	ldr r1, [sp, 0x20]
	adds r3, r1, r0
	movs r5, 0x2
	add r8, r5
	ldr r0, [sp, 0x18]
	cmp r0, 0x1
	bne _080A4434
	adds r4, 0x2
	adds r3, 0x2
	ldr r7, [sp, 0x1C]
	mov r6, sp
_080A4408:
	ldr r1, [r6]
	ldr r2, [r7]
	ldrh r0, [r4]
	strh r0, [r1]
	adds r1, 0x2
	ldrh r0, [r4, 0x2]
	strh r0, [r1]
	adds r1, 0x2
	ldrh r0, [r3]
	strh r0, [r2]
	adds r2, 0x2
	ldrh r0, [r3, 0x2]
	strh r0, [r2]
	adds r2, 0x2
	stm r6!, {r1}
	stm r7!, {r2}
	adds r4, 0x6
	adds r3, 0x6
	subs r5, 0x1
	cmp r5, 0
	bge _080A4408
	b _080A445C
_080A4434:
	adds r4, 0x4
	adds r3, 0x4
	ldr r6, [sp, 0x1C]
	mov r2, sp
	movs r5, 0x2
_080A443E:
	ldr r1, [r2]
	ldrh r0, [r4]
	strh r0, [r1]
	adds r1, 0x2
	stm r2!, {r1}
	ldr r1, [r6]
	ldrh r0, [r3]
	strh r0, [r1]
	adds r1, 0x2
	stm r6!, {r1}
	adds r4, 0x6
	adds r3, 0x6
	subs r5, 0x1
	cmp r5, 0
	bge _080A443E
_080A445C:
	movs r2, 0
	ldr r1, [sp, 0x20]
	mov r9, r1
_080A4462:
	mov r3, r12
	ldrh r1, [r3]
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 1
	mov r5, r9
	adds r4, r5, r0
	movs r0, 0x2
	add r12, r0
	mov r3, r8
	ldrh r1, [r3]
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 1
	adds r3, r5, r0
	movs r5, 0x2
	add r8, r5
	movs r5, 0
	adds r2, 0x1
	mov r10, r2
	mov r7, sp
	add r6, sp, 0xC
_080A448E:
	ldr r1, [r7]
	ldr r2, [r6]
	ldrh r0, [r4]
	strh r0, [r1]
	adds r4, 0x2
	adds r1, 0x2
	ldrh r0, [r4]
	strh r0, [r1]
	adds r4, 0x2
	adds r1, 0x2
	ldrh r0, [r4]
	strh r0, [r1]
	adds r4, 0x2
	adds r1, 0x2
	ldrh r0, [r3]
	strh r0, [r2]
	adds r3, 0x2
	adds r2, 0x2
	ldrh r0, [r3]
	strh r0, [r2]
	adds r3, 0x2
	adds r2, 0x2
	ldrh r0, [r3]
	strh r0, [r2]
	adds r3, 0x2
	adds r2, 0x2
	stm r7!, {r1}
	stm r6!, {r2}
	adds r5, 0x1
	cmp r5, 0x2
	ble _080A448E
	mov r2, r10
	cmp r2, 0x9
	ble _080A4462
	ldr r0, [sp, 0x18]
	cmp r0, 0x1
	beq _080A453A
	mov r3, r12
	ldrh r1, [r3]
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 1
	ldr r5, [sp, 0x20]
	adds r4, r5, r0
	mov r0, r8
	ldrh r1, [r0]
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 1
	adds r3, r5, r0
	ldr r1, [sp, 0x18]
	cmp r1, 0
	bne _080A451E
	ldr r7, [sp, 0x1C]
	mov r6, sp
	movs r5, 0x2
_080A44FE:
	ldm r6!, {r1}
	ldm r7!, {r2}
	ldrh r0, [r4]
	strh r0, [r1]
	ldrh r0, [r4, 0x2]
	strh r0, [r1, 0x2]
	ldrh r0, [r3]
	strh r0, [r2]
	ldrh r0, [r3, 0x2]
	strh r0, [r2, 0x2]
	adds r4, 0x6
	adds r3, 0x6
	subs r5, 0x1
	cmp r5, 0
	bge _080A44FE
	b _080A453A
_080A451E:
	ldr r6, [sp, 0x1C]
	mov r2, sp
	movs r5, 0x2
_080A4524:
	ldm r2!, {r1}
	ldrh r0, [r4]
	strh r0, [r1]
	ldm r6!, {r1}
	ldrh r0, [r3]
	strh r0, [r1]
	adds r4, 0x6
	adds r3, 0x6
	subs r5, 0x1
	cmp r5, 0
	bge _080A4524
_080A453A:
	ldr r2, [sp, 0x30]
	ldr r1, [sp, 0x34]
	ldr r0, [sp, 0x2C]
	cmp r0, 0x7
	bgt _080A4546
	b _080A439A
_080A4546:
	add sp, 0x3C
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_80A4358

	thumb_func_start sub_80A4558
sub_80A4558:
	lsls r1, 3
	movs r3, 0x8F
	lsls r3, 3
	adds r0, r3
	adds r0, r1
	ldr r1, [r0, 0x4]
	ldr r0, [r0]
	str r0, [r2]
	str r1, [r2, 0x4]
	bx lr
	thumb_func_end sub_80A4558

	thumb_func_start sub_80A456C
sub_80A456C:
	lsls r1, 3
	movs r3, 0x8F
	lsls r3, 3
	adds r0, r3
	adds r0, r1
	ldr r1, [r2]
	ldr r2, [r2, 0x4]
	str r1, [r0]
	str r2, [r0, 0x4]
	bx lr
	thumb_func_end sub_80A456C

	thumb_func_start sub_80A4580
sub_80A4580:
	push {r4,lr}
	adds r3, r2, 0
	lsls r2, r1, 2
	adds r2, r1
	lsls r2, 4
	movs r1, 0x91
	lsls r1, 3
	adds r2, r1
	adds r2, r0, r2
	ldr r0, [r3]
	cmp r0, 0
	bge _080A45AE
	ldrb r0, [r2, 0x6]
	ldr r4, [r3, 0x4]
	cmp r0, 0
	beq _080A45CA
	ldr r1, [r2, 0x10]
_080A45A2:
	ldr r0, [r3]
	adds r0, r1
	str r0, [r3]
	cmp r0, 0
	blt _080A45A2
	b _080A45CC
_080A45AE:
	ldr r1, [r2, 0x10]
	ldr r4, [r3, 0x4]
	cmp r0, r1
	blt _080A45CC
	ldrb r0, [r2, 0x6]
	cmp r0, 0
	beq _080A45C8
_080A45BC:
	ldr r0, [r3]
	subs r0, r1
	str r0, [r3]
	cmp r0, r1
	bge _080A45BC
	b _080A45CC
_080A45C8:
	subs r0, r1, 0x1
_080A45CA:
	str r0, [r3]
_080A45CC:
	cmp r4, 0
	bge _080A45E4
	ldrb r0, [r2, 0x6]
	cmp r0, 0
	beq _080A45FE
	ldr r1, [r2, 0x14]
_080A45D8:
	ldr r0, [r3, 0x4]
	adds r0, r1
	str r0, [r3, 0x4]
	cmp r0, 0
	blt _080A45D8
	b _080A4600
_080A45E4:
	ldr r1, [r2, 0x14]
	cmp r4, r1
	blt _080A4600
	ldrb r0, [r2, 0x6]
	cmp r0, 0
	beq _080A45FC
_080A45F0:
	ldr r0, [r3, 0x4]
	subs r0, r1
	str r0, [r3, 0x4]
	cmp r0, r1
	bge _080A45F0
	b _080A4600
_080A45FC:
	subs r0, r1, 0x1
_080A45FE:
	str r0, [r3, 0x4]
_080A4600:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_80A4580

	thumb_func_start sub_80A4608
sub_80A4608:
	movs r3, 0x89
	lsls r3, 3
	adds r2, r0, r3
	ldrb r2, [r2]
	str r2, [r1]
	ldr r2, _080A461C
	adds r0, r2
	ldrb r0, [r0]
	str r0, [r1, 0x4]
	bx lr
	.align 2, 0
_080A461C: .4byte 0x00000449
	thumb_func_end sub_80A4608

	thumb_func_start sub_80A4620
sub_80A4620:
	movs r3, 0x89
	lsls r3, 3
	adds r2, r0, r3
	ldrb r2, [r2]
	lsls r2, 3
	str r2, [r1]
	ldr r2, _080A4638
	adds r0, r2
	ldrb r0, [r0]
	lsls r0, 3
	str r0, [r1, 0x4]
	bx lr
	.align 2, 0
_080A4638: .4byte 0x00000449
	thumb_func_end sub_80A4620

	thumb_func_start sub_80A463C
sub_80A463C:
	movs r3, 0
	str r3, [r1]
	str r3, [r1, 0x4]
	movs r3, 0x89
	lsls r3, 3
	adds r1, r0, r3
	ldrb r1, [r1]
	lsls r1, 11
	str r1, [r2]
	ldr r1, _080A465C
	adds r0, r1
	ldrb r0, [r0]
	lsls r0, 11
	str r0, [r2, 0x4]
	bx lr
	.align 2, 0
_080A465C: .4byte 0x00000449
	thumb_func_end sub_80A463C

	thumb_func_start sub_80A4660
sub_80A4660:
	push {r4-r7,lr}
	adds r6, r3, 0
	lsls r1, 24
	lsrs r5, r1, 24
	ldr r1, _080A4678
	adds r0, r1
	ldr r4, [r0]
	cmp r4, 0
	bne _080A467C
	movs r0, 0
	b _080A46B6
	.align 2, 0
_080A4678: .4byte 0x00000544
_080A467C:
	ldr r0, [r2, 0x4]
	lsls r0, 8
	ldr r1, [r2]
	adds r0, r1
	ldr r1, _080A46BC
	adds r0, r1
	adds r4, r0
	ldr r3, [r6, 0x4]
	cmp r3, 0
	ble _080A46B4
	movs r7, 0x80
	lsls r7, 1
_080A4694:
	ldr r1, [r6]
	adds r2, r4, 0
	cmp r1, 0
	ble _080A46AC
_080A469C:
	ldrb r0, [r2]
	ands r0, r5
	adds r2, 0x1
	cmp r0, 0
	bne _080A46B6
	subs r1, 0x1
	cmp r1, 0
	bgt _080A469C
_080A46AC:
	adds r4, r7
	subs r3, 0x1
	cmp r3, 0
	bgt _080A4694
_080A46B4:
	movs r0, 0
_080A46B6:
	pop {r4-r7}
	pop {r1}
	bx r1
	.align 2, 0
_080A46BC: .4byte 0x00000405
	thumb_func_end sub_80A4660

	thumb_func_start sub_80A46C0
sub_80A46C0:
	push {r4-r7,lr}
	adds r6, r3, 0
	lsls r1, 24
	lsrs r5, r1, 24
	ldr r1, _080A46D8
	adds r0, r1
	ldr r4, [r0]
	cmp r4, 0
	bne _080A46DC
_080A46D2:
	movs r0, 0
	b _080A4716
	.align 2, 0
_080A46D8: .4byte 0x00000544
_080A46DC:
	ldr r0, [r2, 0x4]
	lsls r0, 8
	ldr r1, [r2]
	adds r0, r1
	ldr r1, _080A471C
	adds r0, r1
	adds r4, r0
	ldr r3, [r6, 0x4]
	cmp r3, 0
	ble _080A4714
	movs r7, 0x80
	lsls r7, 1
_080A46F4:
	ldr r1, [r6]
	adds r2, r4, 0
	cmp r1, 0
	ble _080A470C
_080A46FC:
	ldrb r0, [r2]
	ands r0, r5
	adds r2, 0x1
	cmp r0, r5
	bne _080A46D2
	subs r1, 0x1
	cmp r1, 0
	bgt _080A46FC
_080A470C:
	adds r4, r7
	subs r3, 0x1
	cmp r3, 0
	bgt _080A46F4
_080A4714:
	movs r0, 0x1
_080A4716:
	pop {r4-r7}
	pop {r1}
	bx r1
	.align 2, 0
_080A471C: .4byte 0x00000405
	thumb_func_end sub_80A46C0

	thumb_func_start sub_80A4720
sub_80A4720:
	lsls r1, 2
	ldr r3, _080A473C
	adds r0, r3
	adds r0, r1
	ldr r1, [r2, 0x4]
	lsls r1, 7
	ldr r3, [r0]
	adds r3, r1
	ldr r0, [r2]
	lsls r0, 1
	adds r3, r0
	ldrh r0, [r3]
	bx lr
	.align 2, 0
_080A473C: .4byte 0x0000054c
	thumb_func_end sub_80A4720

	thumb_func_start sub_80A4740
sub_80A4740:
	push {r4,lr}
	lsls r1, 2
	ldr r4, _080A4760
	adds r0, r4
	adds r0, r1
	ldr r1, [r2, 0x4]
	lsls r1, 7
	ldr r4, [r0]
	adds r4, r1
	ldr r0, [r2]
	lsls r0, 1
	adds r4, r0
	strh r3, [r4]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080A4760: .4byte 0x0000054c
	thumb_func_end sub_80A4740

	thumb_func_start sub_80A4764
sub_80A4764:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x8
	mov r9, r0
	ldr r0, _080A47E8
	add r0, r9
	movs r2, 0
	ldrsh r1, [r0, r2]
	movs r0, 0x1
	negs r0, r0
	cmp r1, r0
	bne _080A4784
	b _080A49CE
_080A4784:
	ldr r0, _080A47EC
	add r0, r9
	movs r6, 0
	ldrsh r0, [r0, r6]
	cmp r0, 0
	beq _080A4864
	mov r4, r9
	ldr r0, _080A47F0
	add r0, r9
	ldr r5, [r0]
	ldr r0, _080A47F4
	add r0, r9
	movs r1, 0
	ldrsh r0, [r0, r1]
	lsls r0, 20
	lsrs r6, r0, 16
	movs r7, 0
	ldr r0, _080A47F8
	add r0, r9
	movs r2, 0
	ldrsh r0, [r0, r2]
	cmp r7, r0
	bge _080A484C
_080A47B2:
	ldr r1, [r4, 0x4]
	cmp r1, 0
	beq _080A4832
	ldrh r0, [r4, 0x2]
	subs r0, 0x1
	strh r0, [r4, 0x2]
	lsls r0, 16
	cmp r0, 0
	bgt _080A4832
	ldrh r0, [r4]
	subs r0, 0x1
	strh r0, [r4]
	lsls r0, 16
	cmp r0, 0
	bgt _080A4808
	ldr r0, _080A47FC
	add r0, r9
	ldrb r0, [r0]
	cmp r0, 0
	beq _080A4800
	ldrh r0, [r5]
	strh r0, [r4, 0x2]
	ldrh r0, [r5, 0x2]
	strh r0, [r4]
	str r1, [r4, 0x8]
	b _080A480C
	.align 2, 0
_080A47E8: .4byte 0x00000444
_080A47EC: .4byte 0x00000466
_080A47F0: .4byte 0x0000046c
_080A47F4: .4byte 0x0000052c
_080A47F8: .4byte 0x00000464
_080A47FC: .4byte 0x00000471
_080A4800:
	strh r0, [r4]
	strh r0, [r4, 0x2]
	str r0, [r4, 0x8]
	b _080A480C
_080A4808:
	ldrh r0, [r5]
	strh r0, [r4, 0x2]
_080A480C:
	ldr r0, [r4, 0x8]
	cmp r0, 0
	beq _080A4832
	movs r0, 0
	str r0, [sp]
	adds r0, r6, 0
	movs r1, 0
	bl sub_8003810
	adds r0, r6, 0x1
	lsls r0, 16
	lsrs r0, 16
	ldr r1, [r4, 0x8]
	movs r2, 0xF
	bl sub_809971C
	ldr r0, [r4, 0x8]
	adds r0, 0x3C
	str r0, [r4, 0x8]
_080A4832:
	adds r7, 0x1
	adds r4, 0x10
	adds r5, 0x4
	adds r0, r6, 0
	adds r0, 0x10
	lsls r0, 16
	lsrs r6, r0, 16
	ldr r0, _080A485C
	add r0, r9
	movs r1, 0
	ldrsh r0, [r0, r1]
	cmp r7, r0
	blt _080A47B2
_080A484C:
	movs r0, 0x8E
	lsls r0, 3
	add r0, r9
	ldrb r1, [r0]
	ldr r0, _080A4860
	add r0, r9
	strb r1, [r0]
	b _080A48E6
	.align 2, 0
_080A485C: .4byte 0x00000464
_080A4860: .4byte 0x00000471
_080A4864:
	movs r0, 0x88
	lsls r0, 3
	add r0, r9
	ldr r0, [r0]
	cmp r0, 0
	beq _080A48E6
	mov r4, r9
	adds r4, 0xE0
	movs r6, 0xA0
	movs r5, 0x1F
_080A4878:
	adds r0, r4, 0
	movs r1, 0x1
	bl sub_8004D14
	lsls r0, 24
	cmp r0, 0
	beq _080A48DC
	adds r0, r4, 0
	movs r1, 0x1
	bl sub_8004D40
	lsls r0, 24
	cmp r0, 0
	bne _080A48DC
	ldrh r0, [r4, 0x6]
	subs r0, 0x1
	strh r0, [r4, 0x6]
	lsls r0, 16
	cmp r0, 0
	bgt _080A48DC
	ldrh r0, [r4, 0x4]
	strh r0, [r4, 0x6]
	ldr r1, [r4, 0xC]
	ldr r0, [r4, 0x10]
	cmp r1, r0
	bcc _080A48B0
	ldr r0, [r4, 0x8]
	str r0, [r4, 0xC]
_080A48B0:
	ldr r1, [r4, 0xC]
	ldm r1!, {r0}
	str r0, [r4, 0x14]
	str r1, [r4, 0xC]
	ldrb r1, [r4, 0x14]
	add r0, sp, 0x4
	strb r1, [r0]
	ldrb r1, [r4, 0x15]
	adds r0, 0x1
	strb r1, [r0]
	ldrb r1, [r4, 0x16]
	adds r0, 0x1
	strb r1, [r0]
	ldrb r1, [r4, 0x17]
	adds r0, 0x1
	strb r1, [r0]
	ldr r1, [sp, 0x4]
	str r1, [sp]
	lsls r0, r6, 16
	lsrs r0, 16
	bl sub_8003810
_080A48DC:
	subs r5, 0x1
	adds r4, 0x18
	adds r6, 0x1
	cmp r5, 0
	bge _080A4878
_080A48E6:
	movs r5, 0
	movs r4, 0x1
_080A48EA:
	movs r2, 0xF8
	lsls r2, 2
	adds r0, r5, r2
	mov r6, r9
	adds r2, r6, r0
	ldrb r0, [r2]
	cmp r0, 0
	beq _080A4942
	ldrh r1, [r2, 0x4]
	subs r0, r1, 0x1
	strh r0, [r2, 0x4]
	lsls r1, 16
	cmp r1, 0
	bgt _080A4942
	ldr r0, [r2, 0x14]
	adds r0, 0x4
	str r0, [r2, 0x14]
	ldr r1, [r2, 0x24]
	lsrs r1, 1
	lsls r1, 1
	ldr r0, [r2, 0x1C]
	adds r0, r1
	str r0, [r2, 0x1C]
	ldrh r0, [r2, 0x2]
	adds r0, 0x1
	movs r3, 0
	strh r0, [r2, 0x2]
	ldr r1, [r2, 0xC]
	lsls r0, 16
	asrs r0, 16
	movs r6, 0x2
	ldrsh r1, [r1, r6]
	cmp r0, r1
	blt _080A4938
	ldr r0, [r2, 0x10]
	str r0, [r2, 0x14]
	ldr r0, [r2, 0x18]
	str r0, [r2, 0x1C]
	strh r3, [r2, 0x2]
_080A4938:
	movs r0, 0x1
	strb r0, [r2, 0x1]
	ldr r0, [r2, 0x14]
	ldr r0, [r0]
	strh r0, [r2, 0x4]
_080A4942:
	adds r5, 0x28
	subs r4, 0x1
	cmp r4, 0
	bge _080A48EA
	movs r4, 0x91
	lsls r4, 3
	add r4, r9
	movs r7, 0x8F
	lsls r7, 3
	add r7, r9
	movs r0, 0
	mov r8, r0
	b _080A49BC
_080A495C:
	adds r0, r4, 0
	adds r1, r7, 0
	bl sub_80A3E14
	adds r0, r4, 0
	bl sub_80A3EB0
	movs r6, 0
	movs r2, 0x2
	ldrsh r1, [r4, r2]
	ldr r0, _080A4998
	add r0, r9
	movs r2, 0
	ldrsh r0, [r0, r2]
	adds r5, r1, r0
	movs r1, 0x4
	ldrsh r0, [r4, r1]
	movs r2, 0x1
	add r8, r2
	movs r1, 0x50
	adds r1, r4
	mov r10, r1
	adds r7, 0x8
	cmp r6, r0
	bge _080A49BA
_080A498E:
	cmp r5, 0
	beq _080A499C
	cmp r5, 0x1
	beq _080A49A6
	b _080A49AE
	.align 2, 0
_080A4998: .4byte 0x00000536
_080A499C:
	ldr r0, [r4, 0x48]
	ldr r1, [r4, 0x4C]
	bl SetBG2RegOffsets
	b _080A49AE
_080A49A6:
	ldr r0, [r4, 0x48]
	ldr r1, [r4, 0x4C]
	bl SetBG3RegOffsets
_080A49AE:
	adds r6, 0x1
	adds r5, 0x1
	movs r2, 0x4
	ldrsh r0, [r4, r2]
	cmp r6, r0
	blt _080A498E
_080A49BA:
	mov r4, r10
_080A49BC:
	ldr r0, _080A49E0
	add r0, r9
	ldr r0, [r0]
	cmp r8, r0
	blt _080A495C
	ldr r1, _080A49E4
	add r1, r9
	movs r0, 0x1
	strb r0, [r1]
_080A49CE:
	add sp, 0x8
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_080A49E0: .4byte 0x00000474
_080A49E4: .4byte 0x0000052a
	thumb_func_end sub_80A4764

	thumb_func_start sub_80A49E8
sub_80A49E8:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	adds r6, r0, 0
	ldr r0, _080A4A74
	adds r5, r6, r0
	movs r1, 0xFF
	lsls r1, 2
	adds r4, r6, r1
	ldr r0, _080A4A78
	adds r0, r6
	mov r8, r0
	movs r7, 0x1
_080A4A02:
	ldrb r0, [r5]
	cmp r0, 0
	beq _080A4A1C
	ldr r0, [r4, 0x4]
	ldr r1, [r4]
	ldr r2, [r4, 0x8]
	bl MemoryCopy32
	movs r0, 0
	strb r0, [r5]
	movs r0, 0x1
	mov r1, r8
	strb r0, [r1]
_080A4A1C:
	adds r5, 0x28
	adds r4, 0x28
	subs r7, 0x1
	cmp r7, 0
	bge _080A4A02
	ldr r1, _080A4A78
	adds r0, r6, r1
	ldrb r0, [r0]
	cmp r0, 0
	beq _080A4A68
	movs r5, 0
	adds r1, 0xC
	adds r0, r6, r1
	movs r1, 0
	ldrsh r4, [r0, r1]
	movs r1, 0xA7
	lsls r1, 3
	adds r0, r6, r1
	movs r1, 0
	ldrsh r0, [r0, r1]
	cmp r5, r0
	bge _080A4A60
	movs r0, 0xA7
	lsls r0, 3
	adds r7, r6, r0
_080A4A4E:
	adds r0, r4, 0x2
	bl sub_80098F8
	adds r5, 0x1
	adds r4, 0x1
	movs r1, 0
	ldrsh r0, [r7, r1]
	cmp r5, r0
	blt _080A4A4E
_080A4A60:
	ldr r0, _080A4A78
	adds r1, r6, r0
	movs r0, 0
	strb r0, [r1]
_080A4A68:
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_080A4A74: .4byte 0x000003e1
_080A4A78: .4byte 0x0000052a
	thumb_func_end sub_80A49E8

	thumb_func_start sub_80A4A7C
sub_80A4A7C:
	push {r4,lr}
	sub sp, 0x4
	ldr r4, _080A4AB8
	movs r0, 0x88
	lsls r0, 1
	movs r1, 0x6
	bl MemoryAlloc
	str r0, [r4]
	adds r2, r0, 0
	adds r2, 0xE4
	ldr r1, _080A4ABC
	strh r1, [r2]
	ldr r1, _080A4AC0
	movs r3, 0x1
	negs r3, r3
	str r3, [sp]
	movs r2, 0
	bl sub_809D600
	movs r0, 0
	bl sub_80A5E8C
	bl sub_80A4AEC
	add sp, 0x4
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080A4AB8: .4byte gUnknown_3001B6C
_080A4ABC: .4byte 0x0000ffff
_080A4AC0: .4byte gUnknown_811736C
	thumb_func_end sub_80A4A7C

	thumb_func_start sub_80A4AC4
sub_80A4AC4:
	push {r4,lr}
	bl sub_80A4AEC
	bl sub_80A5EBC
	ldr r4, _080A4AE8
	ldr r0, [r4]
	bl sub_809D648
	ldr r0, [r4]
	bl MemoryFree
	movs r0, 0
	str r0, [r4]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080A4AE8: .4byte gUnknown_3001B6C
	thumb_func_end sub_80A4AC4

	thumb_func_start sub_80A4AEC
sub_80A4AEC:
	push {r4,lr}
	movs r0, 0
	movs r1, 0x37
	bl sub_80015C0
	movs r0, 0
	movs r1, 0x38
	bl sub_80015C0
	ldr r0, _080A4B2C
	ldr r0, [r0]
	ldr r1, _080A4B30
	bl sub_809D754
	ldr r4, _080A4B34
	ldr r0, [r4]
	cmp r0, 0
	beq _080A4B1E
	bl sub_80A2D00
	ldr r0, [r4]
	bl MemoryFree
	movs r0, 0
	str r0, [r4]
_080A4B1E:
	movs r0, 0
	bl sub_80A5EDC
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080A4B2C: .4byte gUnknown_3001B6C
_080A4B30: .4byte gUnknown_8117538
_080A4B34: .4byte gUnknown_3001B70
	thumb_func_end sub_80A4AEC

	thumb_func_start sub_80A4B38
sub_80A4B38:
	push {lr}
	bl nullsub_121
	ldr r0, _080A4B50
	ldr r0, [r0]
	cmp r0, 0
	beq _080A4B4A
	bl sub_80A2D68
_080A4B4A:
	pop {r0}
	bx r0
	.align 2, 0
_080A4B50: .4byte gUnknown_3001B70
	thumb_func_end sub_80A4B38

	thumb_func_start sub_80A4B54
sub_80A4B54:
	push {lr}
	ldr r0, _080A4B6C
	ldr r0, [r0]
	cmp r0, 0
	beq _080A4B62
	bl sub_80A2D88
_080A4B62:
	bl nullsub_122
	pop {r0}
	bx r0
	.align 2, 0
_080A4B6C: .4byte gUnknown_3001B70
	thumb_func_end sub_80A4B54

	thumb_func_start GroundMap_GetStationScript
GroundMap_GetStationScript:
	push {r4-r6,lr}
	mov r6, r9
	mov r5, r8
	push {r5,r6}
	sub sp, 0x4
	mov r8, r0
	adds r4, r1, 0
	adds r6, r2, 0
	adds r5, r3, 0
	lsls r4, 16
	asrs r4, 16
	lsls r6, 16
	asrs r6, 16
	lsls r5, 24
	asrs r5, 24
	adds r0, r4, 0
	bl sub_80A77A0
	ldr r1, _080A4BE0
	adds r0, r4, 0
	bl sub_80A77D0
	mov r9, r0
	ldr r1, _080A4BE4
	str r5, [sp]
	movs r0, 0
	adds r2, r4, 0
	adds r3, r6, 0
	bl Log
	lsls r1, r6, 3
	mov r2, r9
	ldr r0, [r2, 0x4]
	adds r0, r1
	lsls r1, r5, 2
	adds r1, r5
	lsls r1, 3
	ldr r0, [r0, 0x4]
	adds r0, r1
	ldr r0, [r0, 0x24]
	ldr r0, [r0]
	ldr r0, [r0, 0x8]
	mov r1, r8
	str r0, [r1]
	movs r0, 0x2
	strh r0, [r1, 0x4]
	strh r6, [r1, 0x6]
	strb r5, [r1, 0x8]
	add sp, 0x4
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r6}
	pop {r0}
	bx r0
	.align 2, 0
_080A4BE0: .4byte gUnknown_8117560
_080A4BE4: .4byte gUnknown_811756C
	thumb_func_end GroundMap_GetStationScript

	thumb_func_start sub_80A4BE8
sub_80A4BE8:
	push {lr}
	lsls r1, 16
	asrs r1, 16
	movs r2, 0
	movs r3, 0
	bl GroundMap_GetStationScript
	pop {r0}
	bx r0
	thumb_func_end sub_80A4BE8

	thumb_func_start GroundMap_ExecuteEvent
GroundMap_ExecuteEvent:
	push {r4,r5,lr}
	sub sp, 0xC
	adds r4, r0, 0
	adds r5, r1, 0
	lsls r4, 16
	asrs r4, 16
	lsls r5, 24
	lsrs r5, 24
	ldr r1, _080A4C44
	movs r0, 0
	adds r2, r4, 0
	adds r3, r5, 0
	bl Log
	movs r0, 0
	mov r1, sp
	adds r2, r4, 0
	bl sub_809D710
	cmp r5, 0
	beq _080A4C2C
	mov r1, sp
	movs r0, 0x5
	strh r0, [r1, 0x4]
_080A4C2C:
	ldr r0, _080A4C48
	ldr r0, [r0]
	ldr r3, _080A4C4C
	movs r1, 0
	mov r2, sp
	bl GroundScript_ExecutePP
	add sp, 0xC
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_080A4C44: .4byte gUnknown_8117594
_080A4C48: .4byte gUnknown_3001B6C
_080A4C4C: .4byte gUnknown_81175E0
	thumb_func_end GroundMap_ExecuteEvent

	thumb_func_start GroundMap_ExecuteStation
GroundMap_ExecuteStation:
	push {r4-r6,lr}
	mov r6, r8
	push {r6}
	sub sp, 0x14
	adds r4, r0, 0
	adds r5, r1, 0
	adds r6, r2, 0
	mov r8, r3
	lsls r4, 16
	asrs r4, 16
	lsls r5, 16
	asrs r5, 16
	lsls r6, 24
	asrs r6, 24
	mov r0, r8
	lsls r0, 24
	lsrs r0, 24
	mov r8, r0
	ldr r1, _080A4CB8
	str r6, [sp]
	str r0, [sp, 0x4]
	movs r0, 0
	adds r2, r4, 0
	adds r3, r5, 0
	bl Log
	add r0, sp, 0x8
	adds r1, r4, 0
	adds r2, r5, 0
	adds r3, r6, 0
	bl GroundMap_GetStationScript
	mov r0, r8
	cmp r0, 0
	beq _080A4C9C
	add r1, sp, 0x8
	movs r0, 0x5
	strh r0, [r1, 0x4]
_080A4C9C:
	ldr r0, _080A4CBC
	ldr r0, [r0]
	ldr r3, _080A4CC0
	movs r1, 0
	add r2, sp, 0x8
	bl GroundScript_ExecutePP
	add sp, 0x14
	pop {r3}
	mov r8, r3
	pop {r4-r6}
	pop {r0}
	bx r0
	.align 2, 0
_080A4CB8: .4byte gUnknown_81175EC
_080A4CBC: .4byte gUnknown_3001B6C
_080A4CC0: .4byte gUnknown_8117644
	thumb_func_end GroundMap_ExecuteStation

	thumb_func_start GroundMap_ExecuteEnter
GroundMap_ExecuteEnter:
	push {r4,lr}
	sub sp, 0xC
	adds r4, r0, 0
	lsls r4, 16
	asrs r4, 16
	ldr r1, _080A4D08
	movs r0, 0
	adds r2, r4, 0
	bl Log
	mov r0, sp
	adds r1, r4, 0
	bl sub_80A4BE8
	mov r1, sp
	movs r3, 0
	movs r2, 0
	movs r0, 0x2
	strh r0, [r1, 0x4]
	mov r0, sp
	strh r2, [r0, 0x6]
	strb r3, [r0, 0x8]
	ldr r0, _080A4D0C
	ldr r0, [r0]
	ldr r3, _080A4D10
	movs r1, 0
	mov r2, sp
	bl GroundScript_ExecutePP
	add sp, 0xC
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080A4D08: .4byte gUnknown_8117650
_080A4D0C: .4byte gUnknown_3001B6C
_080A4D10: .4byte gUnknown_8117698
	thumb_func_end GroundMap_ExecuteEnter

	thumb_func_start sub_80A4D14
sub_80A4D14:
	push {lr}
	ldr r0, _080A4D28
	ldr r0, [r0]
	bl sub_809D678
	lsls r0, 24
	lsrs r0, 24
	pop {r1}
	bx r1
	.align 2, 0
_080A4D28: .4byte gUnknown_3001B6C
	thumb_func_end sub_80A4D14

	thumb_func_start sub_80A4D2C
sub_80A4D2C:
	push {lr}
	adds r1, r0, 0
	lsls r1, 16
	asrs r1, 16
	ldr r0, _080A4D44
	ldr r0, [r0]
	bl sub_809D968
	lsls r0, 24
	lsrs r0, 24
	pop {r1}
	bx r1
	.align 2, 0
_080A4D44: .4byte gUnknown_3001B6C
	thumb_func_end sub_80A4D2C

	thumb_func_start sub_80A4D48
sub_80A4D48:
	push {lr}
	lsls r0, 16
	asrs r2, r0, 16
	movs r0, 0x1
	negs r0, r0
	cmp r2, r0
	beq _080A4D74
	ldr r1, _080A4D70
	lsls r0, r2, 1
	adds r0, r2
	lsls r0, 2
	adds r0, r1
	movs r1, 0
	ldrsh r0, [r0, r1]
	cmp r0, 0x5
	beq _080A4D6C
	cmp r0, 0x8
	bne _080A4D74
_080A4D6C:
	movs r0, 0
	b _080A4D76
	.align 2, 0
_080A4D70: .4byte gUnknown_811BAF4
_080A4D74:
	movs r0, 0x1
_080A4D76:
	pop {r1}
	bx r1
	thumb_func_end sub_80A4D48

	thumb_func_start sub_80A4D7C
sub_80A4D7C:
	push {r4,r5,lr}
	lsls r0, 16
	asrs r5, r0, 16
	cmp r5, 0x9
	beq _080A4D94
	cmp r5, 0x9
	bgt _080A4D90
	cmp r5, 0x2
	beq _080A4DB6
	b _080A4DC4
_080A4D90:
	cmp r5, 0xC
	bne _080A4DC4
_080A4D94:
	movs r0, 0
	movs r1, 0x27
	bl sub_8001658
	adds r4, r0, 0
	movs r0, 0
	movs r1, 0x28
	bl sub_8001658
	lsls r1, r4, 1
	adds r1, r4
	lsls r1, 1
	adds r1, r0
	adds r1, r5, r1
	lsls r1, 16
	asrs r5, r1, 16
	b _080A4DC4
_080A4DB6:
	movs r0, 0x6
	bl sub_80023E4
	lsls r0, 24
	cmp r0, 0
	beq _080A4DC4
	movs r5, 0x3
_080A4DC4:
	adds r0, r5, 0
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_80A4D7C

	thumb_func_start GroundMap_Select
GroundMap_Select:
	push {r4-r6,lr}
	lsls r0, 16
	asrs r5, r0, 16
	ldr r1, _080A4E38
	movs r0, 0
	adds r2, r5, 0
	bl Log
	movs r0, 0
	movs r1, 0x37
	bl sub_80015C0
	movs r0, 0
	movs r1, 0x38
	bl sub_80015C0
	movs r0, 0
	bl sub_80A5EDC
	ldr r4, _080A4E3C
	ldr r0, [r4]
	cmp r0, 0
	beq _080A4E08
	bl sub_80A2D00
	ldr r0, [r4]
	bl MemoryFree
	movs r0, 0
	str r0, [r4]
_080A4E08:
	ldr r0, _080A4E40
	movs r1, 0x6
	bl MemoryAlloc
	adds r2, r0, 0
	str r2, [r4]
	ldr r0, _080A4E44
	ldr r0, [r0]
	adds r0, 0xE4
	strh r5, [r0]
	movs r0, 0x1
	negs r0, r0
	cmp r5, r0
	bne _080A4E4C
	ldr r1, _080A4E48
	adds r0, r2, 0
	bl sub_80A2B40
	ldr r0, [r4]
	adds r1, r5, 0
	bl sub_80A2FBC
	b _080A50BA
	.align 2, 0
_080A4E38: .4byte gUnknown_81176A4
_080A4E3C: .4byte gUnknown_3001B70
_080A4E40: .4byte 0x0000055c
_080A4E44: .4byte gUnknown_3001B6C
_080A4E48: .4byte gUnknown_8117324
_080A4E4C:
	lsls r0, r5, 1
	adds r0, r5
	lsls r0, 2
	ldr r1, _080A4E6C
	adds r6, r0, r1
	ldrh r0, [r6]
	adds r0, 0x1
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0xC
	bhi _080A4F20
	lsls r0, 2
	ldr r1, _080A4E70
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080A4E6C: .4byte gUnknown_811BAF4
_080A4E70: .4byte _080A4E74
	.align 2, 0
_080A4E74:
	.4byte _080A4F08
	.4byte _080A4F20
	.4byte _080A4F20
	.4byte _080A4F20
	.4byte _080A4F20
	.4byte _080A4F20
	.4byte _080A4EA8
	.4byte _080A4EA8
	.4byte _080A4EA8
	.4byte _080A4EA8
	.4byte _080A4EA8
	.4byte _080A4ECC
	.4byte _080A4ECC
_080A4EA8:
	ldr r0, _080A4EC0
	ldr r0, [r0]
	ldr r1, _080A4EC4
	bl sub_80A2B40
	ldr r1, _080A4EC8
	movs r2, 0x80
	lsls r2, 5
	adds r0, r2, 0
	strh r0, [r1]
	b _080A4F30
	.align 2, 0
_080A4EC0: .4byte gUnknown_3001B70
_080A4EC4: .4byte gUnknown_811733C
_080A4EC8: .4byte gUnknown_2026E4E
_080A4ECC:
	ldr r4, _080A4EDC
	movs r1, 0
	ldrsh r0, [r4, r1]
	movs r1, 0x1
	negs r1, r1
	ldr r6, _080A4EE0
	b _080A4EEA
	.align 2, 0
_080A4EDC: .4byte gUnknown_81173C0
_080A4EE0: .4byte gUnknown_3001B70
_080A4EE4:
	adds r4, 0xC
	movs r2, 0
	ldrsh r0, [r4, r2]
_080A4EEA:
	cmp r0, r1
	beq _080A4EF2
	cmp r0, r5
	bne _080A4EE4
_080A4EF2:
	ldr r0, [r6]
	bl MemoryFree
	movs r0, 0
	str r0, [r6]
	adds r1, r4, 0x4
	ldr r2, [r4, 0x8]
	adds r0, r5, 0
	bl GroundMap_SelectDungeon
	b _080A50BA
_080A4F08:
	ldr r0, _080A4F18
	ldr r1, _080A4F1C
	movs r2, 0
	ldrsh r3, [r6, r2]
	adds r2, r5, 0
	bl FatalError
	.align 2, 0
_080A4F18: .4byte gUnknown_81176D0
_080A4F1C: .4byte gUnknown_81176DC
_080A4F20:
	ldr r0, _080A4FA0
	ldr r0, [r0]
	ldr r1, _080A4FA4
	bl sub_80A2B40
	movs r0, 0x1
	bl sub_80A5EDC
_080A4F30:
	ldr r5, _080A4FA0
	ldr r0, [r5]
	movs r2, 0x4
	ldrsh r1, [r6, r2]
	bl sub_80A2FBC
	ldr r0, _080A4FA8
	ldr r0, [r0]
	mov r12, r0
	adds r0, 0xE8
	movs r1, 0
	str r1, [r0]
	adds r0, 0x4
	str r1, [r0]
	adds r0, 0x4
	str r1, [r0]
	adds r0, 0x4
	str r1, [r0]
	adds r0, 0x4
	str r1, [r0]
	adds r0, 0x4
	str r1, [r0]
	movs r4, 0x80
	lsls r4, 1
	add r4, r12
	movs r3, 0x82
	lsls r3, 1
	add r3, r12
	movs r2, 0x84
	lsls r2, 1
	add r2, r12
	movs r0, 0x86
	lsls r0, 1
	add r0, r12
	str r1, [r0]
	str r1, [r2]
	str r1, [r3]
	str r1, [r4]
	mov r0, r12
	adds r0, 0xE4
	movs r1, 0
	ldrsh r0, [r0, r1]
	cmp r0, 0xAD
	beq _080A5034
	cmp r0, 0xAD
	bgt _080A4FC0
	cmp r0, 0xA3
	bgt _080A4FAC
	cmp r0, 0xA2
	bge _080A4FEE
	cmp r0, 0x4
	beq _080A5084
	cmp r0, 0xA1
	beq _080A5084
	b _080A50A2
	.align 2, 0
_080A4FA0: .4byte gUnknown_3001B70
_080A4FA4: .4byte gUnknown_8117324
_080A4FA8: .4byte gUnknown_3001B6C
_080A4FAC:
	cmp r0, 0xAA
	beq _080A500C
	cmp r0, 0xAA
	bgt _080A4FBA
	cmp r0, 0xA8
	beq _080A500C
	b _080A50A2
_080A4FBA:
	cmp r0, 0xAB
	beq _080A5018
	b _080A50A2
_080A4FC0:
	cmp r0, 0xBA
	beq _080A506A
	cmp r0, 0xBA
	bgt _080A4FD6
	cmp r0, 0xAF
	beq _080A5072
	cmp r0, 0xAF
	blt _080A5044
	cmp r0, 0xB0
	beq _080A5060
	b _080A50A2
_080A4FD6:
	cmp r0, 0xDF
	beq _080A4FEE
	cmp r0, 0xDF
	bgt _080A4FE4
	cmp r0, 0xC0
	beq _080A5020
	b _080A50A2
_080A4FE4:
	cmp r0, 0xE0
	beq _080A508E
	cmp r0, 0xE1
	beq _080A5096
	b _080A50A2
_080A4FEE:
	ldr r0, _080A5000
	ldr r0, [r0]
	movs r1, 0x4
	bl sub_80A3BB0
	ldr r1, _080A5004
	ldr r2, _080A5008
	b _080A5050
	.align 2, 0
_080A5000: .4byte gUnknown_3001B70
_080A5004: .4byte gUnknown_2026E4E
_080A5008: .4byte 0x00000808
_080A500C:
	ldr r0, _080A5014
	ldr r0, [r0]
	b _080A5062
	.align 2, 0
_080A5014: .4byte gUnknown_3001B70
_080A5018:
	ldr r0, [r5]
	movs r1, 0x1
	bl sub_80A3BB0
_080A5020:
	ldr r0, _080A5030
	ldr r0, [r0]
	movs r1, 0
	movs r2, 0
	bl sub_80A3B80
	b _080A50A2
	.align 2, 0
_080A5030: .4byte gUnknown_3001B70
_080A5034:
	ldr r1, _080A503C
	ldr r2, _080A5040
	b _080A5050
	.align 2, 0
_080A503C: .4byte gUnknown_2026E4E
_080A5040: .4byte 0x00001010
_080A5044:
	ldr r0, [r5]
	movs r1, 0x4
	bl sub_80A3BB0
	ldr r1, _080A5058
	ldr r2, _080A505C
_080A5050:
	adds r0, r2, 0
	strh r0, [r1]
	b _080A50A2
	.align 2, 0
_080A5058: .4byte gUnknown_2026E4E
_080A505C: .4byte 0x0000080c
_080A5060:
	ldr r0, [r5]
_080A5062:
	movs r1, 0x1
	bl sub_80A3BB0
	b _080A50A2
_080A506A:
	ldr r0, _080A507C
	ldr r2, _080A5080
	adds r1, r2, 0
	strh r1, [r0]
_080A5072:
	ldr r0, [r5]
	movs r1, 0x4
	bl sub_80A3BB0
	b _080A50A2
	.align 2, 0
_080A507C: .4byte gUnknown_2026E4E
_080A5080: .4byte 0x00001010
_080A5084:
	ldr r0, [r5]
	movs r1, 0x3
	bl sub_80A3BB0
	b _080A50A2
_080A508E:
	ldr r0, [r5]
	movs r1, 0x3
	bl sub_80A3BB0
_080A5096:
	ldr r0, _080A50C0
	ldr r0, [r0]
	movs r1, 0
	movs r2, 0
	bl sub_80A3B80
_080A50A2:
	movs r0, 0x6
	ldrsh r1, [r6, r0]
	movs r0, 0x1
	negs r0, r0
	cmp r1, r0
	beq _080A50B4
	adds r0, r1, 0
	bl GroundWeather_Select
_080A50B4:
	ldr r0, _080A50C4
	bl sub_80A56D8
_080A50BA:
	pop {r4-r6}
	pop {r0}
	bx r0
	.align 2, 0
_080A50C0: .4byte gUnknown_3001B70
_080A50C4: .4byte gUnknown_81176F8
	thumb_func_end GroundMap_Select

	thumb_func_start GroundMap_SelectDungeon
GroundMap_SelectDungeon:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	mov r8, r1
	mov r10, r2
	lsls r0, 16
	asrs r5, r0, 16
	ldr r1, _080A514C
	movs r0, 0
	adds r2, r5, 0
	bl Log
	movs r0, 0
	movs r1, 0x37
	bl sub_80015C0
	movs r0, 0
	movs r1, 0x38
	bl sub_80015C0
	movs r0, 0
	bl sub_80A5EDC
	ldr r7, _080A5150
	ldr r0, [r7]
	cmp r0, 0
	beq _080A5110
	bl sub_80A2D00
	ldr r0, [r7]
	bl MemoryFree
	movs r0, 0
	str r0, [r7]
_080A5110:
	ldr r0, _080A5154
	movs r1, 0x6
	bl MemoryAlloc
	adds r2, r0, 0
	str r2, [r7]
	ldr r0, _080A5158
	mov r9, r0
	ldr r0, [r0]
	adds r0, 0xE4
	movs r4, 0
	strh r5, [r0]
	movs r6, 0x1
	negs r6, r6
	cmp r5, r6
	beq _080A5138
	mov r1, r8
	ldrb r0, [r1]
	cmp r0, 0x63
	bne _080A5160
_080A5138:
	ldr r1, _080A515C
	adds r0, r2, 0
	bl sub_80A2B40
	ldr r0, [r7]
	adds r1, r6, 0
	bl sub_80A2FBC
	b _080A51EC
	.align 2, 0
_080A514C: .4byte gUnknown_8117700
_080A5150: .4byte gUnknown_3001B70
_080A5154: .4byte 0x0000055c
_080A5158: .4byte gUnknown_3001B6C
_080A515C: .4byte gUnknown_8117324
_080A5160:
	lsls r0, r5, 1
	adds r0, r5
	lsls r0, 2
	ldr r1, _080A5180
	adds r6, r0, r1
	ldrh r0, [r6]
	subs r0, 0xA
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0x1
	bls _080A518C
	ldr r0, _080A5184
	ldr r1, _080A5188
	adds r2, r5, 0
	bl FatalError
	.align 2, 0
_080A5180: .4byte gUnknown_811BAF4
_080A5184: .4byte gUnknown_8117734
_080A5188: .4byte gUnknown_8117740
_080A518C:
	ldr r1, _080A51FC
	adds r0, r2, 0
	bl sub_80A2B40
	movs r0, 0x1
	bl sub_80A5EDC
	ldr r0, [r7]
	movs r2, 0x4
	ldrsh r1, [r6, r2]
	mov r2, r8
	mov r3, r10
	bl sub_80A3440
	mov r0, r9
	ldr r0, [r0]
	mov r12, r0
	adds r0, 0xE8
	str r4, [r0]
	adds r0, 0x4
	str r4, [r0]
	adds r0, 0x4
	str r4, [r0]
	adds r0, 0x4
	str r4, [r0]
	adds r0, 0x4
	str r4, [r0]
	adds r0, 0x4
	str r4, [r0]
	movs r3, 0x80
	lsls r3, 1
	add r3, r12
	movs r2, 0x82
	lsls r2, 1
	add r2, r12
	movs r1, 0x84
	lsls r1, 1
	add r1, r12
	movs r0, 0x86
	lsls r0, 1
	add r0, r12
	str r4, [r0]
	str r4, [r1]
	str r4, [r2]
	str r4, [r3]
	ldr r0, _080A5200
	bl sub_80A56D8
_080A51EC:
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_080A51FC: .4byte gUnknown_8117354
_080A5200: .4byte gUnknown_8117754
	thumb_func_end GroundMap_SelectDungeon

	thumb_func_start sub_80A5204
sub_80A5204:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x18
	str r0, [sp]
	mov r8, r1
	str r2, [sp, 0x4]
	str r3, [sp, 0x8]
	movs r1, 0x8
	ldrsh r0, [r2, r1]
	cmp r0, 0
	bgt _080A5222
	b _080A53EA
_080A5222:
	mov r5, r8
	ldr r2, [sp]
	mov r12, r2
	movs r0, 0
	ldr r3, [sp, 0x4]
	ldrb r3, [r3, 0x1]
	str r3, [sp, 0x10]
	ldr r1, [sp, 0x4]
	ldrh r2, [r1, 0xA]
	mov r1, sp
	strh r2, [r1, 0xC]
	movs r1, 0xFF
_080A523A:
	adds r0, 0x1
	mov r10, r0
	movs r3, 0xFF
	mov r9, r3
_080A5242:
	mov r0, r12
	strb r1, [r0]
	movs r2, 0x1
	add r12, r2
	movs r3, 0x1
	negs r3, r3
	add r9, r3
	mov r0, r9
	cmp r0, 0
	bge _080A5242
	mov r0, r10
	cmp r0, 0x3
	ble _080A523A
	movs r1, 0
	ldr r2, [sp, 0x10]
	cmp r1, r2
	blt _080A5266
	b _080A53BA
_080A5266:
	ldr r3, [sp, 0x4]
	ldrb r7, [r3]
_080A526A:
	adds r0, 0x1
	mov r10, r0
	adds r0, r1, 0x1
	str r0, [sp, 0x14]
	movs r0, 0xFF
	movs r2, 0x4
	mov r9, r2
_080A5278:
	mov r3, r12
	strb r0, [r3]
	movs r2, 0x1
	add r12, r2
	movs r3, 0x1
	negs r3, r3
	add r9, r3
	mov r2, r9
	cmp r2, 0
	bge _080A5278
	movs r3, 0x5
	mov r9, r3
	movs r0, 0
	cmp r1, 0
	bne _080A5308
	cmp r1, r7
	bge _080A5394
_080A529A:
	ldrb r1, [r5]
	adds r5, 0x1
	cmp r1, 0xBF
	ble _080A52C2
	adds r6, r0, 0
	subs r6, 0xBF
	cmp r1, 0xBF
	ble _080A5300
	adds r2, r1, 0
	subs r2, 0xBF
_080A52AE:
	ldrb r0, [r5]
	mov r3, r12
	strb r0, [r3]
	adds r5, 0x1
	movs r0, 0x1
	add r12, r0
	subs r2, 0x1
	cmp r2, 0
	bne _080A52AE
	b _080A5300
_080A52C2:
	cmp r1, 0x7F
	ble _080A52E6
	ldrb r4, [r5]
	adds r5, 0x1
	adds r6, r0, 0
	subs r6, 0x7F
	cmp r1, 0x7F
	ble _080A5300
	adds r2, r1, 0
	subs r2, 0x7F
_080A52D6:
	mov r3, r12
	strb r4, [r3]
	movs r0, 0x1
	add r12, r0
	subs r2, 0x1
	cmp r2, 0
	bne _080A52D6
	b _080A5300
_080A52E6:
	movs r2, 0
	adds r6, r0, 0x1
	cmp r2, r1
	bgt _080A5300
	movs r0, 0
	adds r2, r1, 0x1
_080A52F2:
	mov r3, r12
	strb r0, [r3]
	movs r3, 0x1
	add r12, r3
	subs r2, 0x1
	cmp r2, 0
	bne _080A52F2
_080A5300:
	adds r0, r6, r1
	cmp r0, r7
	blt _080A529A
	b _080A5394
_080A5308:
	ldr r4, _080A5340
	add r4, r12
	cmp r0, r7
	bge _080A5394
_080A5310:
	ldrb r3, [r5]
	adds r5, 0x1
	cmp r3, 0xBF
	ble _080A5344
	adds r6, r0, 0
	subs r6, 0xBF
	cmp r3, 0xBF
	ble _080A538E
	adds r2, r3, 0
	subs r2, 0xBF
_080A5324:
	ldrb r1, [r5]
	ldrb r0, [r4]
	eors r1, r0
	mov r0, r12
	strb r1, [r0]
	adds r4, 0x1
	adds r5, 0x1
	movs r1, 0x1
	add r12, r1
	subs r2, 0x1
	cmp r2, 0
	bne _080A5324
	b _080A538E
	.align 2, 0
_080A5340: .4byte 0xffffff00
_080A5344:
	cmp r3, 0x7F
	ble _080A5372
	ldrb r2, [r5]
	mov r8, r2
	adds r5, 0x1
	adds r6, r0, 0
	subs r6, 0x7F
	cmp r3, 0x7F
	ble _080A538E
	adds r2, r3, 0
	subs r2, 0x7F
_080A535A:
	ldrb r1, [r4]
	mov r0, r8
	eors r0, r1
	mov r1, r12
	strb r0, [r1]
	adds r4, 0x1
	movs r0, 0x1
	add r12, r0
	subs r2, 0x1
	cmp r2, 0
	bne _080A535A
	b _080A538E
_080A5372:
	movs r2, 0
	adds r6, r0, 0x1
	cmp r2, r3
	bgt _080A538E
	adds r2, r3, 0x1
_080A537C:
	ldrb r0, [r4]
	mov r1, r12
	strb r0, [r1]
	adds r4, 0x1
	movs r0, 0x1
	add r12, r0
	subs r2, 0x1
	cmp r2, 0
	bne _080A537C
_080A538E:
	adds r0, r6, r3
	cmp r0, r7
	blt _080A5310
_080A5394:
	add r9, r7
	mov r1, r9
	cmp r1, 0xFF
	bgt _080A53AE
	movs r0, 0xFF
_080A539E:
	mov r2, r12
	strb r0, [r2]
	movs r3, 0x1
	add r12, r3
	add r9, r3
	mov r1, r9
	cmp r1, 0xFF
	ble _080A539E
_080A53AE:
	ldr r1, [sp, 0x14]
	mov r0, r10
	ldr r2, [sp, 0x10]
	cmp r1, r2
	bge _080A53BA
	b _080A526A
_080A53BA:
	ldr r3, [sp, 0x8]
	cmp r0, r3
	bge _080A53E6
	movs r1, 0xFF
_080A53C2:
	adds r0, 0x1
	mov r10, r0
	movs r0, 0xFF
	mov r9, r0
_080A53CA:
	mov r2, r12
	strb r1, [r2]
	movs r3, 0x1
	add r12, r3
	movs r0, 0x1
	negs r0, r0
	add r9, r0
	mov r2, r9
	cmp r2, 0
	bge _080A53CA
	mov r0, r10
	ldr r3, [sp, 0x8]
	cmp r0, r3
	blt _080A53C2
_080A53E6:
	mov r8, r5
	b _080A547E
_080A53EA:
	ldr r1, [sp]
	movs r0, 0
	ldr r2, [sp, 0x4]
	ldrb r2, [r2, 0x1]
	str r2, [sp, 0x10]
	ldr r3, [sp, 0x4]
	ldrh r2, [r3, 0xA]
	mov r3, sp
	strh r2, [r3, 0xC]
	movs r6, 0xFF
_080A53FE:
	adds r5, r0, 0x1
	movs r4, 0xFF
_080A5402:
	strb r6, [r1]
	adds r1, 0x1
	subs r4, 0x1
	cmp r4, 0
	bge _080A5402
	adds r0, r5, 0
	cmp r0, 0x3
	ble _080A53FE
	movs r4, 0
	ldr r3, [sp, 0x10]
	cmp r4, r3
	bge _080A5460
	ldr r2, [sp, 0x4]
	ldrb r7, [r2]
	movs r3, 0xFF
_080A5420:
	adds r5, r0, 0x1
	adds r2, r4, 0x1
	movs r4, 0x4
_080A5426:
	strb r3, [r1]
	adds r1, 0x1
	subs r4, 0x1
	cmp r4, 0
	bge _080A5426
	movs r4, 0x5
	cmp r7, 0
	beq _080A5444
	movs r6, 0
	adds r0, r7, 0
_080A543A:
	strb r6, [r1]
	adds r1, 0x1
	subs r0, 0x1
	cmp r0, 0
	bne _080A543A
_080A5444:
	adds r4, r7
	cmp r4, 0xFF
	bgt _080A5456
	movs r0, 0xFF
_080A544C:
	strb r0, [r1]
	adds r1, 0x1
	adds r4, 0x1
	cmp r4, 0xFF
	ble _080A544C
_080A5456:
	adds r4, r2, 0
	adds r0, r5, 0
	ldr r2, [sp, 0x10]
	cmp r4, r2
	blt _080A5420
_080A5460:
	ldr r3, [sp, 0x8]
	cmp r0, r3
	bge _080A547E
	movs r6, 0xFF
_080A5468:
	adds r5, r0, 0x1
	movs r4, 0xFF
_080A546C:
	strb r6, [r1]
	adds r1, 0x1
	subs r4, 0x1
	cmp r4, 0
	bge _080A546C
	adds r0, r5, 0
	ldr r2, [sp, 0x8]
	cmp r0, r2
	blt _080A5468
_080A547E:
	mov r3, sp
	ldrh r3, [r3, 0xC]
	lsls r0, r3, 16
	cmp r0, 0
	bgt _080A548A
	b _080A5590
_080A548A:
	mov r6, r8
	ldr r0, [sp]
	movs r1, 0x80
	lsls r1, 3
	adds r2, r0, r1
	movs r0, 0
	ldr r3, [sp, 0x10]
	cmp r0, r3
	bge _080A5586
	movs r1, 0xFB
	mov r10, r1
_080A54A0:
	adds r2, 0x5
	movs r4, 0
	cmp r0, 0
	bne _080A54EC
	ldr r3, [sp, 0x4]
	ldrb r7, [r3]
	movs r1, 0x1
	mov r9, r1
	cmp r0, r7
	bge _080A5574
_080A54B4:
	ldrb r1, [r6]
	adds r6, 0x1
	cmp r1, 0x7F
	ble _080A54DE
	subs r4, 0x7F
	cmp r1, 0x7F
	ble _080A54D6
	movs r5, 0x80
	adds r3, r1, 0
	subs r3, 0x7F
_080A54C8:
	ldrb r0, [r2]
	orrs r0, r5
	strb r0, [r2]
	adds r2, 0x1
	subs r3, 0x1
	cmp r3, 0
	bne _080A54C8
_080A54D6:
	adds r4, r1
	ldr r3, [sp, 0x4]
	ldrb r7, [r3]
	b _080A54E6
_080A54DE:
	adds r0, r1, 0x1
	adds r2, r0
	adds r0, r4, 0x1
	adds r4, r0, r1
_080A54E6:
	cmp r4, r7
	blt _080A54B4
	b _080A5574
_080A54EC:
	ldr r1, _080A5538
	adds r1, r2
	mov r12, r1
	ldr r3, [sp, 0x4]
	ldrb r7, [r3]
	adds r0, 0x1
	mov r9, r0
	cmp r4, r7
	bge _080A5574
_080A54FE:
	ldrb r5, [r6]
	adds r6, 0x1
	cmp r5, 0x7F
	ble _080A553C
	subs r4, 0x7F
	cmp r5, 0x7F
	ble _080A556A
	movs r7, 0x80
	movs r0, 0x80
	mov r8, r0
	adds r3, r5, 0
	subs r3, 0x7F
_080A5516:
	mov r0, r12
	ldrb r1, [r0]
	mov r0, r8
	ands r0, r1
	movs r1, 0x1
	add r12, r1
	cmp r0, 0
	bne _080A552C
	ldrb r0, [r2]
	orrs r0, r7
	strb r0, [r2]
_080A552C:
	adds r2, 0x1
	subs r3, 0x1
	cmp r3, 0
	bne _080A5516
	b _080A556A
	.align 2, 0
_080A5538: .4byte 0xffffff00
_080A553C:
	movs r3, 0
	adds r4, 0x1
	cmp r3, r5
	bgt _080A556A
	movs r7, 0x80
	movs r3, 0x80
	mov r8, r3
	adds r3, r5, 0x1
_080A554C:
	mov r0, r12
	ldrb r1, [r0]
	mov r0, r8
	ands r0, r1
	movs r1, 0x1
	add r12, r1
	cmp r0, 0
	beq _080A5562
	ldrb r0, [r2]
	orrs r0, r7
	strb r0, [r2]
_080A5562:
	adds r2, 0x1
	subs r3, 0x1
	cmp r3, 0
	bne _080A554C
_080A556A:
	adds r4, r5
	ldr r3, [sp, 0x4]
	ldrb r7, [r3]
	cmp r4, r7
	blt _080A54FE
_080A5574:
	mov r1, r10
	subs r0, r1, r7
	adds r2, r0
	mov r0, r9
	ldr r3, [sp, 0x4]
	ldrb r3, [r3, 0x1]
	str r3, [sp, 0x10]
	cmp r0, r3
	blt _080A54A0
_080A5586:
	mov r8, r6
	ldr r0, [sp, 0x4]
	ldrh r1, [r0, 0xA]
	mov r0, sp
	strh r1, [r0, 0xC]
_080A5590:
	mov r2, sp
	ldrh r2, [r2, 0xC]
	lsls r0, r2, 16
	asrs r0, 16
	cmp r0, 0x1
	ble _080A568C
	mov r6, r8
	ldr r3, [sp]
	movs r0, 0x80
	lsls r0, 3
	adds r2, r3, r0
	movs r0, 0
	b _080A5684
_080A55AA:
	adds r2, 0x5
	movs r4, 0
	cmp r0, 0
	bne _080A55F2
	ldr r3, [sp, 0x4]
	ldrb r7, [r3]
	movs r1, 0x1
	mov r10, r1
	cmp r0, r7
	bge _080A567C
_080A55BE:
	ldrb r1, [r6]
	adds r6, 0x1
	cmp r1, 0x7F
	ble _080A55E4
	subs r4, 0x7F
	cmp r1, 0x7F
	ble _080A55E0
	movs r5, 0x40
	adds r3, r1, 0
	subs r3, 0x7F
_080A55D2:
	ldrb r0, [r2]
	orrs r0, r5
	strb r0, [r2]
	adds r2, 0x1
	subs r3, 0x1
	cmp r3, 0
	bne _080A55D2
_080A55E0:
	adds r4, r1
	b _080A55EC
_080A55E4:
	adds r0, r1, 0x1
	adds r2, r0
	adds r0, r4, 0x1
	adds r4, r0, r1
_080A55EC:
	cmp r4, r7
	blt _080A55BE
	b _080A567C
_080A55F2:
	ldr r3, _080A5640
	adds r3, r2
	mov r12, r3
	ldr r1, [sp, 0x4]
	ldrb r7, [r1]
	adds r0, 0x1
	mov r10, r0
	cmp r4, r7
	bge _080A567C
_080A5604:
	ldrb r5, [r6]
	adds r6, 0x1
	cmp r5, 0x7F
	ble _080A5644
	subs r4, 0x7F
	cmp r5, 0x7F
	ble _080A5676
	movs r3, 0x40
	mov r8, r3
	movs r0, 0x40
	mov r9, r0
	adds r3, r5, 0
	subs r3, 0x7F
_080A561E:
	mov r0, r12
	ldrb r1, [r0]
	mov r0, r9
	ands r0, r1
	movs r1, 0x1
	add r12, r1
	cmp r0, 0
	bne _080A5636
	ldrb r0, [r2]
	mov r1, r8
	orrs r0, r1
	strb r0, [r2]
_080A5636:
	adds r2, 0x1
	subs r3, 0x1
	cmp r3, 0
	bne _080A561E
	b _080A5676
	.align 2, 0
_080A5640: .4byte 0xffffff00
_080A5644:
	movs r3, 0
	adds r4, 0x1
	cmp r3, r5
	bgt _080A5676
	movs r3, 0x40
	mov r8, r3
	movs r0, 0x40
	mov r9, r0
	adds r3, r5, 0x1
_080A5656:
	mov r0, r12
	ldrb r1, [r0]
	mov r0, r9
	ands r0, r1
	movs r1, 0x1
	add r12, r1
	cmp r0, 0
	beq _080A566E
	ldrb r0, [r2]
	mov r1, r8
	orrs r0, r1
	strb r0, [r2]
_080A566E:
	adds r2, 0x1
	subs r3, 0x1
	cmp r3, 0
	bne _080A5656
_080A5676:
	adds r4, r5
	cmp r4, r7
	blt _080A5604
_080A567C:
	movs r3, 0xFB
	subs r0, r3, r7
	adds r2, r0
	mov r0, r10
_080A5684:
	ldr r1, [sp, 0x10]
	cmp r0, r1
	blt _080A55AA
	mov r8, r6
_080A568C:
	mov r0, r8
	add sp, 0x18
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_80A5204

	thumb_func_start sub_80A56A0
sub_80A56A0:
	push {lr}
	adds r3, r0, 0
	adds r2, r1, 0
	lsls r3, 24
	lsrs r3, 24
	lsls r2, 24
	lsrs r2, 24
	ldr r0, _080A56BC
	ldr r0, [r0]
	adds r1, r3, 0
	bl sub_80A3B80
	pop {r0}
	bx r0
	.align 2, 0
_080A56BC: .4byte gUnknown_3001B70
	thumb_func_end sub_80A56A0

	thumb_func_start sub_80A56C0
sub_80A56C0:
	push {lr}
	adds r2, r0, 0
	ldr r0, _080A56D4
	ldr r0, [r0]
	movs r1, 0
	bl sub_80A4558
	pop {r0}
	bx r0
	.align 2, 0
_080A56D4: .4byte gUnknown_3001B70
	thumb_func_end sub_80A56C0

	thumb_func_start sub_80A56D8
sub_80A56D8:
	push {lr}
	adds r2, r0, 0
	ldr r0, _080A56EC
	ldr r0, [r0]
	movs r1, 0
	bl sub_80A456C
	pop {r0}
	bx r0
	.align 2, 0
_080A56EC: .4byte gUnknown_3001B70
	thumb_func_end sub_80A56D8

	thumb_func_start sub_80A56F0
sub_80A56F0:
	ldr r1, _080A5700
	ldr r2, [r1]
	adds r2, 0xE8
	ldr r1, [r0, 0x4]
	ldr r0, [r0]
	str r0, [r2]
	str r1, [r2, 0x4]
	bx lr
	.align 2, 0
_080A5700: .4byte gUnknown_3001B6C
	thumb_func_end sub_80A56F0

	thumb_func_start sub_80A5704
sub_80A5704:
	ldr r1, _080A5724
	ldr r3, [r1]
	adds r2, r3, 0
	adds r2, 0xF8
	ldr r1, [r0, 0x4]
	ldr r0, [r0]
	str r0, [r2]
	str r1, [r2, 0x4]
	adds r0, r3, 0
	adds r0, 0xF0
	movs r1, 0
	str r1, [r0]
	adds r0, 0x4
	str r1, [r0]
	bx lr
	.align 2, 0
_080A5724: .4byte gUnknown_3001B6C
	thumb_func_end sub_80A5704

	thumb_func_start sub_80A5728
sub_80A5728:
	ldr r0, _080A5734
	ldr r0, [r0]
	adds r0, 0xE4
	movs r1, 0
	ldrsh r0, [r0, r1]
	bx lr
	.align 2, 0
_080A5734: .4byte gUnknown_3001B6C
	thumb_func_end sub_80A5728

	thumb_func_start sub_80A5738
sub_80A5738:
	ldr r0, _080A5750
	ldr r0, [r0]
	adds r0, 0xE4
	movs r2, 0
	ldrsh r1, [r0, r2]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 2
	ldr r1, _080A5754
	adds r0, r1
	bx lr
	.align 2, 0
_080A5750: .4byte gUnknown_3001B6C
_080A5754: .4byte gUnknown_811BAF4
	thumb_func_end sub_80A5738

	thumb_func_start sub_80A5758
sub_80A5758:
	push {lr}
	adds r1, r0, 0
	ldr r0, _080A5768
	ldr r0, [r0]
	cmp r0, 0
	bne _080A576C
	movs r0, 0
	b _080A5772
	.align 2, 0
_080A5768: .4byte gUnknown_3001B70
_080A576C:
	bl sub_80A4608
	movs r0, 0x1
_080A5772:
	pop {r1}
	bx r1
	thumb_func_end sub_80A5758

	thumb_func_start sub_80A5778
sub_80A5778:
	push {lr}
	adds r3, r0, 0
	adds r2, r1, 0
	ldr r0, _080A578C
	ldr r0, [r0]
	cmp r0, 0
	bne _080A5790
	movs r0, 0
	b _080A5798
	.align 2, 0
_080A578C: .4byte gUnknown_3001B70
_080A5790:
	adds r1, r3, 0
	bl sub_80A463C
	movs r0, 0x1
_080A5798:
	pop {r1}
	bx r1
	thumb_func_end sub_80A5778

	thumb_func_start sub_80A579C
sub_80A579C:
	push {r4-r7,lr}
	adds r6, r0, 0
	adds r5, r1, 0
	ldr r0, _080A5838
	ldr r3, [r0]
	cmp r3, 0
	beq _080A5854
	ldr r0, _080A583C
	ldr r0, [r0]
	adds r2, r0, 0
	adds r2, 0xE4
	movs r0, 0
	ldrsh r1, [r2, r0]
	movs r0, 0x1
	negs r0, r0
	cmp r1, r0
	beq _080A5854
	adds r0, r1, 0
	lsls r4, r0, 1
	adds r4, r0
	lsls r4, 2
	ldr r0, _080A5840
	adds r4, r0
	adds r0, r3, 0
	adds r1, r6, 0
	adds r2, r5, 0
	bl sub_80A463C
	ldr r2, [r6]
	mov r12, r2
	movs r0, 0xF0
	lsls r0, 7
	add r0, r12
	str r0, [r6]
	ldr r3, [r6, 0x4]
	movs r7, 0xA0
	lsls r7, 7
	adds r0, r3, r7
	str r0, [r6, 0x4]
	ldr r2, [r5]
	ldr r1, _080A5844
	adds r0, r2, r1
	str r0, [r5]
	ldr r1, [r5, 0x4]
	ldr r7, _080A5848
	adds r0, r1, r7
	str r0, [r5, 0x4]
	movs r7, 0
	ldrsh r0, [r4, r7]
	cmp r0, 0xA
	bne _080A581E
	movs r0, 0x90
	lsls r0, 8
	add r0, r12
	str r0, [r6]
	movs r4, 0xD0
	lsls r4, 7
	adds r0, r3, r4
	str r0, [r6, 0x4]
	ldr r7, _080A584C
	adds r0, r2, r7
	str r0, [r5]
	ldr r2, _080A5850
	adds r0, r1, r2
	str r0, [r5, 0x4]
_080A581E:
	ldr r1, [r6]
	ldr r0, [r5]
	cmp r1, r0
	ble _080A5828
	str r1, [r5]
_080A5828:
	ldr r1, [r6, 0x4]
	ldr r0, [r5, 0x4]
	cmp r1, r0
	ble _080A5832
	str r1, [r5, 0x4]
_080A5832:
	movs r0, 0x1
	b _080A5856
	.align 2, 0
_080A5838: .4byte gUnknown_3001B70
_080A583C: .4byte gUnknown_3001B6C
_080A5840: .4byte gUnknown_811BAF4
_080A5844: .4byte 0xffff8800
_080A5848: .4byte 0xffffb000
_080A584C: .4byte 0xffff7000
_080A5850: .4byte 0xffff9800
_080A5854:
	movs r0, 0
_080A5856:
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_80A579C

	thumb_func_start sub_80A585C
sub_80A585C:
	push {r4-r7,lr}
	adds r7, r1, 0
	ldr r1, _080A5884
	ldr r2, [r1]
	ldr r1, _080A5888
	adds r2, r1
	ldr r1, [r0, 0x4]
	lsls r1, 8
	ldr r0, [r0]
	adds r1, r0
	ldr r0, _080A588C
	adds r1, r0
	ldr r0, [r2]
	adds r5, r0, r1
	ldr r4, [r7, 0x4]
	cmp r0, 0
	bne _080A5890
_080A587E:
	movs r0, 0x1
	b _080A58C0
	.align 2, 0
_080A5884: .4byte gUnknown_3001B70
_080A5888: .4byte 0x00000544
_080A588C: .4byte 0x00000405
_080A5890:
	cmp r4, 0
	ble _080A58BE
	movs r1, 0x80
	lsls r1, 1
	mov r12, r1
_080A589A:
	ldr r2, [r7]
	adds r3, r5, 0
	cmp r2, 0
	ble _080A58B6
	movs r6, 0x80
_080A58A4:
	ldrb r1, [r3]
	adds r0, r6, 0
	ands r0, r1
	adds r3, 0x1
	cmp r0, 0
	bne _080A587E
	subs r2, 0x1
	cmp r2, 0
	bgt _080A58A4
_080A58B6:
	add r5, r12
	subs r4, 0x1
	cmp r4, 0
	bgt _080A589A
_080A58BE:
	movs r0, 0
_080A58C0:
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_80A585C

	thumb_func_start sub_80A58C8
sub_80A58C8:
	push {r4-r7,lr}
	adds r7, r1, 0
	ldr r1, _080A58F0
	ldr r2, [r1]
	ldr r1, _080A58F4
	adds r2, r1
	ldr r1, [r0, 0x4]
	lsls r1, 8
	ldr r0, [r0]
	adds r1, r0
	ldr r0, _080A58F8
	adds r1, r0
	ldr r0, [r2]
	adds r5, r0, r1
	ldr r4, [r7, 0x4]
	cmp r0, 0
	bne _080A58FC
_080A58EA:
	movs r0, 0x1
	b _080A592C
	.align 2, 0
_080A58F0: .4byte gUnknown_3001B70
_080A58F4: .4byte 0x00000544
_080A58F8: .4byte 0x00000405
_080A58FC:
	cmp r4, 0
	ble _080A592A
	movs r1, 0x80
	lsls r1, 1
	mov r12, r1
_080A5906:
	ldr r2, [r7]
	adds r3, r5, 0
	cmp r2, 0
	ble _080A5922
	movs r6, 0x40
_080A5910:
	ldrb r1, [r3]
	adds r0, r6, 0
	ands r0, r1
	adds r3, 0x1
	cmp r0, 0
	bne _080A58EA
	subs r2, 0x1
	cmp r2, 0
	bgt _080A5910
_080A5922:
	add r5, r12
	subs r4, 0x1
	cmp r4, 0
	bgt _080A5906
_080A592A:
	movs r0, 0
_080A592C:
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_80A58C8

	thumb_func_start sub_80A5934
sub_80A5934:
	push {r4,r5,lr}
	adds r4, r0, 0
	adds r5, r1, 0
	adds r3, r2, 0
	lsls r4, 24
	lsrs r4, 24
	ldr r0, _080A5958
	ldr r0, [r0]
	adds r1, r4, 0
	adds r2, r5, 0
	bl sub_80A4660
	lsls r0, 24
	lsrs r0, 24
	pop {r4,r5}
	pop {r1}
	bx r1
	.align 2, 0
_080A5958: .4byte gUnknown_3001B70
	thumb_func_end sub_80A5934

	thumb_func_start sub_80A595C
sub_80A595C:
	push {r4,r5,lr}
	adds r4, r0, 0
	adds r5, r1, 0
	adds r3, r2, 0
	lsls r4, 24
	lsrs r4, 24
	ldr r0, _080A5980
	ldr r0, [r0]
	adds r1, r4, 0
	adds r2, r5, 0
	bl sub_80A46C0
	lsls r0, 24
	lsrs r0, 24
	pop {r4,r5}
	pop {r1}
	bx r1
	.align 2, 0
_080A5980: .4byte gUnknown_3001B70
	thumb_func_end sub_80A595C

	thumb_func_start sub_80A5984
sub_80A5984:
	push {lr}
	adds r3, r0, 0
	adds r2, r1, 0
	ldr r0, _080A599C
	ldr r0, [r0]
	adds r1, r3, 0
	bl sub_80A4720
	lsls r0, 16
	lsrs r0, 16
	pop {r1}
	bx r1
	.align 2, 0
_080A599C: .4byte gUnknown_3001B70
	thumb_func_end sub_80A5984

	thumb_func_start sub_80A59A0
sub_80A59A0:
	push {r4,r5,lr}
	adds r4, r0, 0
	adds r5, r1, 0
	lsls r3, r2, 16
	lsrs r3, 16
	ldr r0, _080A59BC
	ldr r0, [r0]
	adds r1, r4, 0
	adds r2, r5, 0
	bl sub_80A4740
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_080A59BC: .4byte gUnknown_3001B70
	thumb_func_end sub_80A59A0

	thumb_func_start GroundMap_Action
GroundMap_Action:
	push {lr}
	bl nullsub_123
	ldr r0, _080A59D4
	ldr r0, [r0]
	ldr r1, _080A59D8
	bl HandleAction
	pop {r0}
	bx r0
	.align 2, 0
_080A59D4: .4byte gUnknown_3001B6C
_080A59D8: .4byte gUnknown_8117770
	thumb_func_end GroundMap_Action

	thumb_func_start sub_80A59DC
sub_80A59DC:
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	sub sp, 0x58
	ldr r7, _080A5A34
	ldr r0, [r7]
	cmp r0, 0
	bne _080A59F0
	b _080A5E5A
_080A59F0:
	mov r9, sp
	mov r0, sp
	bl sub_809D248
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0
	bne _080A5A04
	str r0, [sp]
	str r0, [sp, 0x4]
_080A5A04:
	ldr r0, _080A5A38
	mov r8, r0
	ldr r3, [r0]
	adds r0, r3, 0
	adds r0, 0xE4
	movs r1, 0
	ldrsh r0, [r0, r1]
	mov r6, r8
	cmp r0, 0xAB
	bne _080A5A1A
	b _080A5BBE
_080A5A1A:
	cmp r0, 0xAB
	bgt _080A5A46
	cmp r0, 0xA3
	bgt _080A5A3C
	cmp r0, 0xA2
	bge _080A5A76
	cmp r0, 0x4
	bne _080A5A2C
	b _080A5D76
_080A5A2C:
	cmp r0, 0xA1
	bne _080A5A32
	b _080A5E28
_080A5A32:
	b _080A5E46
	.align 2, 0
_080A5A34: .4byte gUnknown_3001B70
_080A5A38: .4byte gUnknown_3001B6C
_080A5A3C:
	cmp r0, 0xA8
	beq _080A5AF4
	cmp r0, 0xAA
	beq _080A5AF4
	b _080A5E46
_080A5A46:
	cmp r0, 0xB0
	bne _080A5A4C
	b _080A5C76
_080A5A4C:
	cmp r0, 0xB0
	bgt _080A5A5E
	cmp r0, 0xAE
	bne _080A5A56
	b _080A5B58
_080A5A56:
	cmp r0, 0xAF
	bne _080A5A5C
	b _080A5BD8
_080A5A5C:
	b _080A5E46
_080A5A5E:
	cmp r0, 0xDF
	beq _080A5A76
	cmp r0, 0xDF
	bgt _080A5A6E
	cmp r0, 0xBA
	bne _080A5A6C
	b _080A5D18
_080A5A6C:
	b _080A5E46
_080A5A6E:
	cmp r0, 0xE0
	bne _080A5A74
	b _080A5DDA
_080A5A74:
	b _080A5E46
_080A5A76:
	ldr r3, [r6]
	adds r2, r3, 0
	adds r2, 0xF4
	ldr r1, [r2]
	adds r0, r1, 0x2
	str r0, [r2]
	adds r4, r3, 0
	adds r4, 0xFC
	cmp r0, 0
	bge _080A5A8C
	adds r0, r1, 0x5
_080A5A8C:
	asrs r1, r0, 2
	ldr r0, [r4]
	adds r0, r1
	str r0, [r4]
	ldr r0, [r2]
	movs r1, 0x3
	ands r0, r1
	str r0, [r2]
	ldr r5, _080A5AF0
	ldr r0, [r5]
	adds r2, r3, 0
	adds r2, 0xF8
	movs r1, 0
	bl sub_80A4580
	ldr r0, [sp]
	str r0, [sp, 0x8]
	ldr r0, [r6]
	adds r0, 0xFC
	ldr r1, [sp, 0x4]
	ldr r0, [r0]
	adds r1, r0
	add r4, sp, 0x8
	str r1, [r4, 0x4]
	ldr r0, [r5]
	movs r1, 0
	adds r2, r4, 0
	bl sub_80A4580
	ldr r0, [r5]
	movs r1, 0
	adds r2, r4, 0
	bl sub_80A456C
	ldr r0, [sp]
	str r0, [sp, 0x8]
	ldr r0, [r6]
	adds r0, 0xFC
	ldr r1, [sp, 0x4]
	ldr r0, [r0]
	subs r1, r0
	str r1, [r4, 0x4]
	ldr r0, [r5]
	movs r1, 0x1
	adds r2, r4, 0
	bl sub_80A4580
	ldr r0, [r5]
	b _080A5DD0
	.align 2, 0
_080A5AF0: .4byte gUnknown_3001B70
_080A5AF4:
	ldr r2, [r6]
	adds r3, r2, 0
	adds r3, 0xF0
	adds r0, r2, 0
	adds r0, 0xE8
	ldr r1, [r3]
	ldr r0, [r0]
	adds r1, r0
	str r1, [r3]
	adds r2, 0xF8
	cmp r1, 0
	bge _080A5B0E
	adds r1, 0x7
_080A5B0E:
	asrs r1, 3
	ldr r0, [r2]
	adds r0, r1
	str r0, [r2]
	ldr r1, [r3]
	adds r0, r1, 0
	cmp r1, 0
	bge _080A5B20
	adds r0, r1, 0x7
_080A5B20:
	asrs r0, 3
	lsls r0, 3
	subs r0, r1, r0
	str r0, [r3]
	ldr r5, _080A5B54
	ldr r0, [r5]
	movs r1, 0
	bl sub_80A4580
	ldr r0, [r6]
	adds r0, 0xF8
	ldr r1, [sp]
	ldr r0, [r0]
	adds r1, r0
	str r1, [sp, 0x10]
	ldr r0, [sp, 0x4]
	add r4, sp, 0x10
	str r0, [r4, 0x4]
	ldr r0, [r5]
	movs r1, 0
	adds r2, r4, 0
	bl sub_80A4580
	ldr r0, [r5]
	movs r1, 0
	b _080A5DD2
	.align 2, 0
_080A5B54: .4byte gUnknown_3001B70
_080A5B58:
	adds r4, r3, 0
	adds r4, 0xF0
	adds r0, r3, 0
	adds r0, 0xE8
	ldr r1, [r4]
	ldr r0, [r0]
	adds r1, r0
	str r1, [r4]
	adds r2, r3, 0
	adds r2, 0xF8
	cmp r1, 0
	bge _080A5B72
	adds r1, 0x7
_080A5B72:
	asrs r1, 3
	ldr r0, [r2]
	adds r0, r1
	str r0, [r2]
	ldr r1, [r4]
	adds r0, r1, 0
	cmp r1, 0
	bge _080A5B84
	adds r0, r1, 0x7
_080A5B84:
	asrs r0, 3
	lsls r0, 3
	subs r0, r1, r0
	str r0, [r4]
	ldr r0, [r7]
	movs r1, 0
	bl sub_80A4580
	mov r1, r8
	ldr r0, [r1]
	adds r0, 0xF8
	ldr r1, [sp]
	ldr r0, [r0]
	adds r1, r0
	str r1, [sp, 0x18]
	ldr r0, [sp, 0x4]
	add r4, sp, 0x18
	str r0, [r4, 0x4]
	ldr r0, [r7]
	movs r1, 0
	adds r2, r4, 0
	bl sub_80A4580
	ldr r0, [r7]
	movs r1, 0
	adds r2, r4, 0
	bl sub_80A456C
	b _080A5DCE
_080A5BBE:
	ldr r0, [sp]
	ldr r1, [sp, 0x4]
	str r0, [sp, 0x20]
	str r1, [sp, 0x24]
	ldr r0, [r7]
	add r4, sp, 0x20
	movs r1, 0
	adds r2, r4, 0
	bl sub_80A4580
	ldr r0, [r7]
	movs r1, 0
	b _080A5DD2
_080A5BD8:
	ldr r0, [r7]
	movs r1, 0
	mov r2, sp
	bl sub_80A456C
	mov r0, r8
	ldr r3, [r0]
	adds r4, r3, 0
	adds r4, 0xF0
	adds r1, r3, 0
	adds r1, 0xE8
	ldr r0, [r4]
	ldr r1, [r1]
	adds r0, r1
	str r0, [r4]
	adds r5, r3, 0
	adds r5, 0xF4
	adds r1, r3, 0
	adds r1, 0xEC
	ldr r0, [r5]
	ldr r1, [r1]
	adds r0, r1
	str r0, [r5]
	adds r2, r3, 0
	adds r2, 0xF8
	ldr r1, [r4]
	cmp r1, 0
	bge _080A5C12
	adds r1, 0x7
_080A5C12:
	asrs r1, 3
	ldr r0, [r2]
	adds r0, r1
	str r0, [r2]
	adds r3, 0xFC
	ldr r1, [r5]
	cmp r1, 0
	bge _080A5C24
	adds r1, 0x7
_080A5C24:
	asrs r1, 3
	ldr r0, [r3]
	adds r0, r1
	str r0, [r3]
	ldr r1, [r4]
	adds r0, r1, 0
	cmp r1, 0
	bge _080A5C36
	adds r0, r1, 0x7
_080A5C36:
	asrs r0, 3
	lsls r0, 3
	subs r0, r1, r0
	str r0, [r4]
	ldr r1, [r5]
	adds r0, r1, 0
	cmp r1, 0
	bge _080A5C48
	adds r0, r1, 0x7
_080A5C48:
	asrs r0, 3
	lsls r0, 3
	subs r0, r1, r0
	str r0, [r5]
	ldr r0, [r7]
	movs r1, 0
	bl sub_80A4580
	mov r1, r8
	ldr r2, [r1]
	adds r1, r2, 0
	adds r1, 0xF8
	ldr r0, [sp]
	ldr r1, [r1]
	adds r0, r1
	str r0, [sp, 0x28]
	adds r2, 0xFC
	mov r1, r9
	ldr r0, [r1, 0x4]
	ldr r1, [r2]
	adds r0, r1
	add r4, sp, 0x28
	b _080A5DC2
_080A5C76:
	adds r4, r3, 0
	adds r4, 0xF0
	adds r1, r3, 0
	adds r1, 0xE8
	ldr r0, [r4]
	ldr r1, [r1]
	adds r0, r1
	str r0, [r4]
	adds r5, r3, 0
	adds r5, 0xF4
	adds r1, r3, 0
	adds r1, 0xEC
	ldr r0, [r5]
	ldr r1, [r1]
	adds r0, r1
	str r0, [r5]
	adds r6, r3, 0
	adds r6, 0xF8
	ldr r1, [r4]
	cmp r1, 0
	bge _080A5CA2
	adds r1, 0x7
_080A5CA2:
	asrs r1, 3
	ldr r0, [r6]
	adds r0, r1
	str r0, [r6]
	adds r2, r3, 0
	adds r2, 0xFC
	ldr r1, [r5]
	cmp r1, 0
	bge _080A5CB6
	adds r1, 0x7
_080A5CB6:
	asrs r1, 3
	ldr r0, [r2]
	adds r0, r1
	str r0, [r2]
	ldr r1, [r4]
	adds r0, r1, 0
	cmp r1, 0
	bge _080A5CC8
	adds r0, r1, 0x7
_080A5CC8:
	asrs r0, 3
	lsls r0, 3
	subs r0, r1, r0
	str r0, [r4]
	ldr r1, [r5]
	adds r0, r1, 0
	cmp r1, 0
	bge _080A5CDA
	adds r0, r1, 0x7
_080A5CDA:
	asrs r0, 3
	lsls r0, 3
	subs r0, r1, r0
	str r0, [r5]
	ldr r0, [r7]
	movs r1, 0
	adds r2, r6, 0
	bl sub_80A4580
	mov r0, r8
	ldr r2, [r0]
	adds r1, r2, 0
	adds r1, 0xF8
	ldr r0, [sp]
	ldr r1, [r1]
	adds r0, r1
	str r0, [sp, 0x30]
	adds r2, 0xFC
	ldr r0, [sp, 0x4]
	ldr r1, [r2]
	adds r0, r1
	add r4, sp, 0x30
	str r0, [r4, 0x4]
	ldr r0, [r7]
	movs r1, 0
	adds r2, r4, 0
	bl sub_80A4580
	ldr r0, [r7]
	movs r1, 0
	b _080A5DD2
_080A5D18:
	ldr r0, [r7]
	movs r1, 0x1
	mov r2, sp
	bl sub_80A456C
	mov r0, r8
	ldr r1, [r0]
	adds r3, r1, 0
	adds r3, 0xF0
	ldr r4, [r3]
	adds r0, r4, 0x1
	str r0, [r3]
	adds r2, r1, 0
	adds r2, 0xF8
	cmp r0, 0
	bge _080A5D3A
	adds r0, r4, 0x4
_080A5D3A:
	asrs r1, r0, 2
	ldr r0, [r2]
	adds r0, r1
	str r0, [r2]
	ldr r0, [r3]
	movs r1, 0x3
	ands r0, r1
	str r0, [r3]
	ldr r0, [r7]
	movs r1, 0x1
	bl sub_80A4580
	mov r1, r8
	ldr r0, [r1]
	adds r0, 0xF8
	ldr r1, [sp]
	ldr r0, [r0]
	adds r1, r0
	str r1, [sp, 0x38]
	ldr r0, [sp, 0x4]
	add r4, sp, 0x38
	str r0, [r4, 0x4]
	ldr r0, [r7]
	movs r1, 0
	adds r2, r4, 0
	bl sub_80A4580
	ldr r0, [r7]
	movs r1, 0
	b _080A5DD2
_080A5D76:
	ldr r0, [r7]
	movs r1, 0
	mov r2, sp
	bl sub_80A456C
	mov r0, r8
	ldr r1, [r0]
	adds r3, r1, 0
	adds r3, 0xF0
	ldr r4, [r3]
	adds r0, r4, 0x1
	str r0, [r3]
	adds r2, r1, 0
	adds r2, 0xF8
	cmp r0, 0
	bge _080A5D98
	adds r0, 0x7
_080A5D98:
	asrs r1, r0, 3
	ldr r0, [r2]
	adds r0, r1
	str r0, [r2]
	ldr r0, [r3]
	movs r1, 0x7
	ands r0, r1
	str r0, [r3]
	ldr r0, [r7]
	movs r1, 0x1
	bl sub_80A4580
	mov r1, r8
	ldr r0, [r1]
	adds r0, 0xF8
	ldr r1, [sp]
	ldr r0, [r0]
	adds r1, r0
	str r1, [sp, 0x40]
	ldr r0, [sp, 0x4]
	add r4, sp, 0x40
_080A5DC2:
	str r0, [r4, 0x4]
	ldr r0, [r7]
	movs r1, 0x1
	adds r2, r4, 0
	bl sub_80A4580
_080A5DCE:
	ldr r0, [r7]
_080A5DD0:
	movs r1, 0x1
_080A5DD2:
	adds r2, r4, 0
	bl sub_80A456C
	b _080A5E52
_080A5DDA:
	ldr r0, [r7]
	movs r1, 0
	mov r2, sp
	bl sub_80A456C
	mov r0, r8
	ldr r1, [r0]
	adds r3, r1, 0
	adds r3, 0xF0
	ldr r4, [r3]
	adds r0, r4, 0x1
	str r0, [r3]
	adds r2, r1, 0
	adds r2, 0xF8
	cmp r0, 0
	bge _080A5DFC
	adds r0, 0x7
_080A5DFC:
	asrs r1, r0, 3
	ldr r0, [r2]
	adds r0, r1
	str r0, [r2]
	ldr r0, [r3]
	movs r1, 0x7
	ands r0, r1
	str r0, [r3]
	ldr r0, [r7]
	movs r1, 0x1
	bl sub_80A4580
	mov r1, r8
	ldr r0, [r1]
	adds r0, 0xF8
	ldr r0, [r0]
	str r0, [sp, 0x48]
	ldr r0, [sp, 0x4]
	add r2, sp, 0x48
	str r0, [r2, 0x4]
	ldr r0, [r7]
	b _080A5E3E
_080A5E28:
	ldr r0, [r7]
	movs r1, 0
	mov r2, sp
	bl sub_80A456C
	movs r0, 0
	movs r1, 0
	str r0, [sp, 0x50]
	str r1, [sp, 0x54]
	ldr r0, [r7]
	add r2, sp, 0x50
_080A5E3E:
	movs r1, 0x1
	bl sub_80A456C
	b _080A5E52
_080A5E46:
	ldr r0, _080A5E6C
	ldr r0, [r0]
	movs r1, 0
	mov r2, sp
	bl sub_80A456C
_080A5E52:
	ldr r0, _080A5E6C
	ldr r0, [r0]
	bl sub_80A4764
_080A5E5A:
	bl sub_80A60D8
	add sp, 0x58
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_080A5E6C: .4byte gUnknown_3001B70
	thumb_func_end sub_80A59DC

	thumb_func_start sub_80A5E70
sub_80A5E70:
	push {lr}
	ldr r0, _080A5E88
	ldr r0, [r0]
	cmp r0, 0
	beq _080A5E7E
	bl sub_80A49E8
_080A5E7E:
	bl sub_80A62D0
	pop {r0}
	bx r0
	.align 2, 0
_080A5E88: .4byte gUnknown_3001B70
	thumb_func_end sub_80A5E70

	thumb_func_start sub_80A5E8C
sub_80A5E8C:
	push {r4,r5,lr}
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	ldr r5, _080A5EB4
	movs r0, 0x24
	movs r1, 0x6
	bl MemoryAlloc
	str r0, [r5]
	ldr r1, _080A5EB8
	strh r1, [r0]
	movs r1, 0
	strb r1, [r0, 0x2]
	adds r0, r4, 0
	bl sub_80A5EDC
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_080A5EB4: .4byte gUnknown_3001B74
_080A5EB8: .4byte 0x0000ffff
	thumb_func_end sub_80A5E8C

	thumb_func_start sub_80A5EBC
sub_80A5EBC:
	push {r4,lr}
	movs r0, 0
	bl sub_80A5EDC
	ldr r4, _080A5ED8
	ldr r0, [r4]
	bl MemoryFree
	movs r0, 0
	str r0, [r4]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080A5ED8: .4byte gUnknown_3001B74
	thumb_func_end sub_80A5EBC

	thumb_func_start sub_80A5EDC
sub_80A5EDC:
	push {r4-r6,lr}
	lsls r0, 24
	lsrs r0, 24
	adds r5, r0, 0
	movs r6, 0x1
	negs r6, r6
	movs r0, 0
	movs r1, 0x1B
	adds r2, r6, 0
	bl sub_80018D8
	ldr r0, _080A5F34
	ldr r1, [r0]
	ldr r0, _080A5F38
	strh r0, [r1]
	strb r5, [r1, 0x2]
	ldr r4, _080A5F3C
	ldr r0, [r4]
	cmp r0, 0
	beq _080A5F12
	bl sub_80A2D00
	ldr r0, [r4]
	bl MemoryFree
	movs r0, 0
	str r0, [r4]
_080A5F12:
	cmp r5, 0
	beq _080A5F2E
	ldr r0, _080A5F40
	movs r1, 0x6
	bl MemoryAlloc
	str r0, [r4]
	ldr r1, _080A5F44
	bl sub_80A2B40
	ldr r0, [r4]
	adds r1, r6, 0
	bl sub_80A2FBC
_080A5F2E:
	pop {r4-r6}
	pop {r0}
	bx r0
	.align 2, 0
_080A5F34: .4byte gUnknown_3001B74
_080A5F38: .4byte 0x0000ffff
_080A5F3C: .4byte gUnknown_3001B78
_080A5F40: .4byte 0x0000055c
_080A5F44: .4byte gUnknown_8117784
	thumb_func_end sub_80A5EDC

	thumb_func_start nullsub_121
nullsub_121:
	bx lr
	thumb_func_end nullsub_121

	thumb_func_start nullsub_122
nullsub_122:
	bx lr
	thumb_func_end nullsub_122

	thumb_func_start GroundWeather_Select
GroundWeather_Select:
	push {r4-r7,lr}
	lsls r0, 16
	asrs r5, r0, 16
	adds r7, r5, 0
	ldr r1, _080A5F94
	ldr r6, _080A5F98
	ldr r0, [r6]
	ldrb r3, [r0, 0x2]
	movs r0, 0
	adds r2, r5, 0
	bl Log
	movs r0, 0
	movs r1, 0x1B
	adds r2, r5, 0
	bl sub_80018D8
	ldr r0, [r6]
	movs r4, 0
	strh r5, [r0]
	ldrb r0, [r0, 0x2]
	cmp r0, 0
	bne _080A5F80
	b _080A60B4
_080A5F80:
	movs r0, 0x1
	negs r0, r0
	cmp r5, r0
	bne _080A5FA0
	ldr r0, _080A5F9C
	ldr r0, [r0]
	adds r1, r5, 0
	bl sub_80A2FBC
	b _080A60B4
	.align 2, 0
_080A5F94: .4byte gUnknown_811779C
_080A5F98: .4byte gUnknown_3001B74
_080A5F9C: .4byte gUnknown_3001B78
_080A5FA0:
	lsls r1, r7, 2
	ldr r0, _080A5FD8
	adds r5, r1, r0
	ldr r0, _080A5FDC
	ldr r0, [r0]
	movs r2, 0x2
	ldrsh r1, [r5, r2]
	bl sub_80A2FBC
	ldr r0, [r6]
	str r4, [r0, 0x4]
	str r4, [r0, 0x8]
	str r4, [r0, 0xC]
	str r4, [r0, 0x10]
	str r4, [r0, 0x20]
	str r4, [r0, 0x1C]
	str r4, [r0, 0x18]
	str r4, [r0, 0x14]
	movs r1, 0
	ldrsh r0, [r0, r1]
	cmp r0, 0xF
	bhi _080A6098
	lsls r0, 2
	ldr r1, _080A5FE0
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080A5FD8: .4byte gUnknown_811E5F4
_080A5FDC: .4byte gUnknown_3001B78
_080A5FE0: .4byte _080A5FE4
	.align 2, 0
_080A5FE4:
	.4byte _080A6088
	.4byte _080A6098
	.4byte _080A6098
	.4byte _080A6088
	.4byte _080A6088
	.4byte _080A6088
	.4byte _080A6098
	.4byte _080A6040
	.4byte _080A6088
	.4byte _080A6024
	.4byte _080A6098
	.4byte _080A6098
	.4byte _080A6098
	.4byte _080A6098
	.4byte _080A6050
	.4byte _080A606C
_080A6024:
	ldr r0, _080A6034
	ldr r0, [r0]
	movs r1, 0x1
	bl sub_80A3BB0
	ldr r1, _080A6038
	ldr r2, _080A603C
	b _080A60B0
	.align 2, 0
_080A6034: .4byte gUnknown_3001B78
_080A6038: .4byte gUnknown_2026E4E
_080A603C: .4byte 0x0000040c
_080A6040:
	ldr r1, _080A6048
	ldr r2, _080A604C
	b _080A60B0
	.align 2, 0
_080A6048: .4byte gUnknown_2026E4E
_080A604C: .4byte 0x00000808
_080A6050:
	ldr r0, _080A6060
	ldr r0, [r0]
	movs r1, 0x1
	bl sub_80A3BB0
	ldr r1, _080A6064
	ldr r2, _080A6068
	b _080A60B0
	.align 2, 0
_080A6060: .4byte gUnknown_3001B78
_080A6064: .4byte gUnknown_2026E4E
_080A6068: .4byte 0x00001010
_080A606C:
	ldr r0, _080A607C
	ldr r0, [r0]
	movs r1, 0x1
	bl sub_80A3BB0
	ldr r1, _080A6080
	ldr r2, _080A6084
	b _080A60B0
	.align 2, 0
_080A607C: .4byte gUnknown_3001B78
_080A6080: .4byte gUnknown_2026E4E
_080A6084: .4byte 0x0000040c
_080A6088:
	ldr r1, _080A6090
	ldr r2, _080A6094
	b _080A60B0
	.align 2, 0
_080A6090: .4byte gUnknown_2026E4E
_080A6094: .4byte 0x00001010
_080A6098:
	movs r1, 0
	ldrsh r0, [r5, r1]
	cmp r0, 0x1
	bne _080A60AA
	ldr r0, _080A60BC
	ldr r0, [r0]
	movs r1, 0x1
	bl sub_80A3BB0
_080A60AA:
	ldr r1, _080A60C0
	movs r2, 0x80
	lsls r2, 5
_080A60B0:
	adds r0, r2, 0
	strh r0, [r1]
_080A60B4:
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_080A60BC: .4byte gUnknown_3001B78
_080A60C0: .4byte gUnknown_2026E4E
	thumb_func_end GroundWeather_Select

	thumb_func_start sub_80A60C4
sub_80A60C4:
	ldr r0, _080A60D0
	ldr r0, [r0]
	movs r1, 0
	ldrsh r0, [r0, r1]
	bx lr
	.align 2, 0
_080A60D0: .4byte gUnknown_3001B74
	thumb_func_end sub_80A60C4

	thumb_func_start nullsub_123
nullsub_123:
	bx lr
	thumb_func_end nullsub_123

	thumb_func_start sub_80A60D8
sub_80A60D8:
	push {r4-r6,lr}
	sub sp, 0x28
	ldr r0, _080A6104
	ldr r3, [r0]
	ldrb r1, [r3, 0x2]
	adds r6, r0, 0
	cmp r1, 0
	bne _080A60EA
	b _080A62C0
_080A60EA:
	ldrh r0, [r3]
	adds r0, 0x1
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x10
	bls _080A60F8
	b _080A6278
_080A60F8:
	lsls r0, 2
	ldr r1, _080A6108
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080A6104: .4byte gUnknown_3001B74
_080A6108: .4byte _080A610C
	.align 2, 0
_080A610C:
	.4byte _080A62AC
	.4byte _080A6278
	.4byte _080A6278
	.4byte _080A6278
	.4byte _080A6278
	.4byte _080A6278
	.4byte _080A6278
	.4byte _080A6278
	.4byte _080A6278
	.4byte _080A6278
	.4byte _080A6150
	.4byte _080A61CC
	.4byte _080A61CC
	.4byte _080A61CC
	.4byte _080A61CC
	.4byte _080A61D0
	.4byte _080A6224
_080A6150:
	ldr r2, [r6]
	ldr r1, [r2, 0x4]
	adds r0, r1, 0x2
	str r0, [r2, 0x4]
	ldr r4, [r2, 0x8]
	adds r3, r4, 0x1
	str r3, [r2, 0x8]
	cmp r0, 0
	bge _080A6164
	adds r0, r1, 0x5
_080A6164:
	asrs r1, r0, 2
	ldr r0, [r2, 0xC]
	adds r0, r1
	str r0, [r2, 0xC]
	adds r1, r3, 0
	cmp r1, 0
	bge _080A6174
	adds r1, r4, 0x4
_080A6174:
	asrs r1, 2
	ldr r0, [r2, 0x10]
	adds r0, r1
	str r0, [r2, 0x10]
	ldr r4, _080A61C8
	ldr r0, [r4]
	adds r2, 0xC
	movs r1, 0
	bl sub_80A4580
	ldr r1, [r6]
	ldr r0, [r1, 0x4]
	movs r2, 0x3
	ands r0, r2
	str r0, [r1, 0x4]
	ldr r0, [r1, 0x8]
	ands r0, r2
	str r0, [r1, 0x8]
	mov r0, sp
	bl sub_80A56C0
	ldr r2, [r6]
	ldr r0, [sp]
	ldr r1, [r2, 0xC]
	subs r0, r1
	str r0, [sp]
	ldr r0, [sp, 0x4]
	ldr r1, [r2, 0x10]
	adds r0, r1
	str r0, [sp, 0x4]
	ldr r0, [r4]
	movs r1, 0
	mov r2, sp
	bl sub_80A4580
	ldr r0, [r4]
	movs r1, 0
	mov r2, sp
	bl sub_80A456C
	b _080A62B8
	.align 2, 0
_080A61C8: .4byte gUnknown_3001B78
_080A61CC:
	add r4, sp, 0x8
	b _080A628E
_080A61D0:
	ldr r2, [r6]
	ldr r1, [r2, 0x4]
	adds r0, r1, 0x1
	str r0, [r2, 0x4]
	cmp r0, 0
	bge _080A61DE
	adds r0, r1, 0x4
_080A61DE:
	asrs r1, r0, 2
	ldr r0, [r2, 0xC]
	adds r0, r1
	str r0, [r2, 0xC]
	ldr r5, _080A6220
	ldr r0, [r5]
	adds r2, 0xC
	movs r1, 0
	bl sub_80A4580
	ldr r2, [r6]
	ldr r0, [r2, 0x4]
	movs r1, 0x3
	ands r0, r1
	str r0, [r2, 0x4]
	add r4, sp, 0x10
	adds r0, r4, 0
	bl sub_80A56C0
	ldr r1, [r6]
	ldr r0, [sp, 0x10]
	ldr r1, [r1, 0xC]
	subs r0, r1
	str r0, [sp, 0x10]
	movs r0, 0
	str r0, [r4, 0x4]
	ldr r0, [r5]
	movs r1, 0
	adds r2, r4, 0
	bl sub_80A4580
	ldr r0, [r5]
	b _080A6298
	.align 2, 0
_080A6220: .4byte gUnknown_3001B78
_080A6224:
	ldr r2, [r6]
	ldr r1, [r2, 0x4]
	adds r0, r1, 0x2
	str r0, [r2, 0x4]
	cmp r0, 0
	bge _080A6232
	adds r0, r1, 0x5
_080A6232:
	asrs r1, r0, 2
	ldr r0, [r2, 0xC]
	adds r0, r1
	str r0, [r2, 0xC]
	ldr r5, _080A6274
	ldr r0, [r5]
	adds r2, 0xC
	movs r1, 0
	bl sub_80A4580
	ldr r2, [r6]
	ldr r0, [r2, 0x4]
	movs r1, 0x3
	ands r0, r1
	str r0, [r2, 0x4]
	add r4, sp, 0x18
	adds r0, r4, 0
	bl sub_80A56C0
	ldr r1, [r6]
	ldr r0, [sp, 0x18]
	ldr r1, [r1, 0xC]
	subs r0, r1
	str r0, [sp, 0x18]
	movs r0, 0
	str r0, [r4, 0x4]
	ldr r0, [r5]
	movs r1, 0
	adds r2, r4, 0
	bl sub_80A4580
	ldr r0, [r5]
	b _080A6298
	.align 2, 0
_080A6274: .4byte gUnknown_3001B78
_080A6278:
	ldr r0, [r6]
	movs r1, 0
	ldrsh r0, [r0, r1]
	lsls r0, 2
	ldr r1, _080A62A4
	adds r0, r1
	movs r1, 0
	ldrsh r0, [r0, r1]
	cmp r0, 0
	bne _080A62AC
	add r4, sp, 0x20
_080A628E:
	adds r0, r4, 0
	bl sub_80A56C0
	ldr r0, _080A62A8
	ldr r0, [r0]
_080A6298:
	movs r1, 0
	adds r2, r4, 0
	bl sub_80A456C
	b _080A62B8
	.align 2, 0
_080A62A4: .4byte gUnknown_811E5F4
_080A62A8: .4byte gUnknown_3001B78
_080A62AC:
	ldr r0, _080A62C8
	ldr r0, [r0]
	ldr r2, _080A62CC
	movs r1, 0
	bl sub_80A456C
_080A62B8:
	ldr r0, _080A62C8
	ldr r0, [r0]
	bl sub_80A4764
_080A62C0:
	add sp, 0x28
	pop {r4-r6}
	pop {r0}
	bx r0
	.align 2, 0
_080A62C8: .4byte gUnknown_3001B78
_080A62CC: .4byte gUnknown_81177BC
	thumb_func_end sub_80A60D8

	thumb_func_start sub_80A62D0
sub_80A62D0:
	push {lr}
	ldr r0, _080A62E8
	ldr r0, [r0]
	ldrb r0, [r0, 0x2]
	cmp r0, 0
	beq _080A62E4
	ldr r0, _080A62EC
	ldr r0, [r0]
	bl sub_80A49E8
_080A62E4:
	pop {r0}
	bx r0
	.align 2, 0
_080A62E8: .4byte gUnknown_3001B74
_080A62EC: .4byte gUnknown_3001B78
	thumb_func_end sub_80A62D0

	thumb_func_start sub_80A62F0
sub_80A62F0:
	push {r4-r7,lr}
	ldr r4, _080A6378
	movs r0, 0x88
	lsls r0, 1
	movs r1, 0x6
	bl MemoryAlloc
	str r0, [r4]
	ldr r0, _080A637C
	ldr r1, _080A6380
	bl OpenFileAndGetFileDataPtr
	ldr r1, _080A6384
	str r0, [r1]
	movs r0, 0x1
	bl sub_800DAC0
	ldr r4, [r4]
	ldr r1, _080A6388
	movs r0, 0x16
	str r0, [r1]
	ldr r1, _080A638C
	movs r0, 0x1
	strb r0, [r1]
	movs r0, 0
	movs r2, 0
	movs r1, 0x80
	lsls r1, 9
	adds r3, r1, 0
_080A632A:
	str r2, [r4]
	lsls r0, 4
	str r0, [r4, 0x4]
	str r2, [r4, 0x8]
	adds r0, r1, 0
	adds r1, r3
	asrs r0, 16
	adds r4, 0xC
	cmp r0, 0x15
	ble _080A632A
	ldr r0, _080A6378
	ldr r0, [r0]
	movs r1, 0x84
	lsls r1, 1
	adds r4, r0, r1
	movs r6, 0
	movs r7, 0
	movs r5, 0xE8
	lsls r5, 13
_080A6350:
	strh r7, [r4]
	strh r7, [r4, 0x2]
	lsrs r0, r5, 16
	movs r1, 0
	bl sub_80997F4
	movs r0, 0x80
	lsls r0, 9
	adds r5, r0
	adds r6, 0x1
	adds r4, 0x4
	cmp r6, 0x1
	ble _080A6350
	movs r0, 0x1
	negs r0, r0
	bl GroundSprite_Reset
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_080A6378: .4byte gUnknown_3001B7C
_080A637C: .4byte gUnknown_81177CC
_080A6380: .4byte gUnknown_83B0000
_080A6384: .4byte gUnknown_203B4B4
_080A6388: .4byte gUnknown_2039DD4
_080A638C: .4byte gUnknown_2039DD0
	thumb_func_end sub_80A62F0

	thumb_func_start GroundSprite_Reset
GroundSprite_Reset:
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	lsls r0, 16
	asrs r0, 16
	mov r9, r0
	ldr r1, _080A641C
	movs r0, 0
	bl Log
	ldr r0, _080A6420
	movs r1, 0
	mov r8, r1
	strh r1, [r0]
	ldr r0, _080A6424
	strh r1, [r0]
	bl sub_80A6460
	mov r0, r9
	bl sub_80A4D48
	lsls r0, 24
	movs r1, 0x2
	cmp r0, 0
	beq _080A63C6
	movs r1, 0x3
_080A63C6:
	movs r0, 0xF8
	lsls r0, 1
	bl sub_808E53C
	ldr r5, _080A6428
	adds r0, r5, 0
	bl sub_8004E8C
	ldr r4, _080A642C
	adds r0, r4, 0
	bl sub_8004E8C
	ldrh r1, [r4, 0x4]
	ldr r6, _080A6430
	adds r0, r6, 0
	ands r0, r1
	strh r0, [r4, 0x4]
	ldrh r1, [r4, 0xA]
	adds r0, r6, 0
	ands r0, r1
	movs r2, 0x80
	lsls r2, 4
	adds r7, r2, 0
	orrs r0, r7
	strh r0, [r4, 0xA]
	mov r0, r9
	bl sub_80A4D48
	lsls r0, 24
	cmp r0, 0
	beq _080A6434
	ldrh r1, [r5, 0x4]
	adds r0, r6, 0
	ands r0, r1
	strh r0, [r5, 0x4]
	ldrh r1, [r5, 0xA]
	adds r0, r6, 0
	ands r0, r1
	movs r2, 0xC0
	lsls r2, 4
	adds r1, r2, 0
	orrs r0, r1
	b _080A6444
	.align 2, 0
_080A641C: .4byte gUnknown_81177D8
_080A6420: .4byte gUnknown_2039DCC
_080A6424: .4byte gUnknown_2039DCE
_080A6428: .4byte gUnknown_2039DB0
_080A642C: .4byte gUnknown_2039DC0
_080A6430: .4byte 0x0000f3ff
_080A6434:
	ldrh r1, [r5, 0x4]
	adds r0, r6, 0
	ands r0, r1
	strh r0, [r5, 0x4]
	ldrh r1, [r5, 0xA]
	adds r0, r6, 0
	ands r0, r1
	orrs r0, r7
_080A6444:
	strh r0, [r5, 0xA]
	movs r0, 0x1
	bl ResetSprites
	movs r0, 0x1
	bl nullsub_10
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end GroundSprite_Reset

	thumb_func_start sub_80A6460
sub_80A6460:
	push {r4-r7,lr}
	ldr r0, _080A649C
	ldr r1, _080A64A0
	bl OpenFileAndGetFileDataPtr
	adds r7, r0, 0
	movs r5, 0x80
	lsls r5, 1
	ldr r4, [r7, 0x4]
	movs r6, 0xC
_080A6474:
	adds r0, r5, 0
	adds r1, r4, 0
	movs r2, 0x10
	bl sub_809971C
	adds r0, r5, 0
	adds r0, 0x10
	lsls r0, 16
	lsrs r5, r0, 16
	adds r4, 0x40
	subs r6, 0x1
	cmp r6, 0
	bge _080A6474
	adds r0, r7, 0
	bl CloseFile
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_080A649C: .4byte gUnknown_81177EC
_080A64A0: .4byte gUnknown_8510000
	thumb_func_end sub_80A6460

	thumb_func_start sub_80A64A4
sub_80A64A4:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	ldr r0, _080A6508
	ldr r0, [r0]
	movs r1, 0x84
	lsls r1, 1
	adds r7, r0, r1
	bl sub_80A6460
	movs r0, 0
	mov r8, r0
_080A64C0:
	movs r1, 0x2
	ldrsh r0, [r7, r1]
	cmp r0, 0
	ble _080A6568
	ldrh r5, [r7]
	mov r0, r8
	adds r0, 0x1D
	lsls r0, 16
	lsrs r0, 16
	mov r10, r0
	mov r1, r8
	lsls r0, r1, 20
	movs r1, 0xE8
	lsls r1, 17
	adds r0, r1
	lsrs r0, 16
	mov r9, r0
	movs r0, 0x80
	lsls r0, 2
	adds r1, r0, 0
	adds r0, r5, 0
	ands r0, r1
	cmp r0, 0
	beq _080A6514
	ldr r0, _080A650C
	ldr r1, _080A6510
	bl OpenFileAndGetFileDataPtr
	adds r6, r0, 0
	movs r0, 0xFF
	ands r0, r5
	lsls r0, 6
	ldr r1, [r6, 0x4]
	adds r2, r1, r0
	b _080A652A
	.align 2, 0
_080A6508: .4byte gUnknown_3001B7C
_080A650C: .4byte gUnknown_81177EC
_080A6510: .4byte gUnknown_8510000
_080A6514:
	movs r0, 0xFF
	ands r0, r5
	lsls r0, 2
	ldr r1, _080A6584
	adds r0, r1
	ldr r0, [r0]
	ldr r1, _080A6588
	bl OpenFileAndGetFileDataPtr
	adds r6, r0, 0
	ldr r2, [r6, 0x4]
_080A652A:
	movs r1, 0x80
	lsls r1, 5
	adds r0, r1, 0
	adds r1, r5, 0
	ands r1, r0
	lsls r1, 16
	lsrs r1, 16
	negs r1, r1
	lsrs r4, r1, 31
	movs r1, 0x80
	lsls r1, 6
	adds r0, r1, 0
	ands r5, r0
	cmp r5, 0
	beq _080A654C
	movs r0, 0x2
	orrs r4, r0
_080A654C:
	mov r0, r9
	adds r1, r2, 0
	movs r2, 0x10
	bl sub_809971C
	mov r0, r10
	adds r1, r4, 0
	bl sub_80997F4
	cmp r6, 0
	beq _080A6568
	adds r0, r6, 0
	bl CloseFile
_080A6568:
	movs r0, 0x1
	add r8, r0
	adds r7, 0x4
	mov r1, r8
	cmp r1, 0x1
	ble _080A64C0
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_080A6584: .4byte gUnknown_81178F4
_080A6588: .4byte gUnknown_9E60000
	thumb_func_end sub_80A64A4

	thumb_func_start sub_80A658C
sub_80A658C:
	push {r4,lr}
	bl sub_800DB7C
	movs r0, 0
	bl ResetSprites
	movs r0, 0
	bl nullsub_10
	bl sub_8005180
	bl nullsub_12
	bl CopySpritesToOam
	bl nullsub_13
	bl sub_8005304
	bl nullsub_14
	ldr r0, _080A65D0
	ldr r0, [r0]
	bl CloseFile
	ldr r4, _080A65D4
	ldr r0, [r4]
	bl MemoryFree
	movs r0, 0
	str r0, [r4]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080A65D0: .4byte gUnknown_203B4B4
_080A65D4: .4byte gUnknown_3001B7C
	thumb_func_end sub_80A658C

	thumb_func_start sub_80A65D8
sub_80A65D8:
	adds r0, 0x50
	ldrh r0, [r0]
	bx lr
	thumb_func_end sub_80A65D8

	thumb_func_start sub_80A65E0
sub_80A65E0:
	lsrs r0, 16
	ldr r2, _080A65EC
	adds r1, r2, 0
	ands r0, r1
	bx lr
	.align 2, 0
_080A65EC: .4byte 0x0000337f
	thumb_func_end sub_80A65E0

	thumb_func_start sub_80A65F0
sub_80A65F0:
	push {r4-r6,lr}
	adds r3, r0, 0
	lsls r1, 16
	lsrs r1, 16
	adds r0, 0x50
	strh r1, [r0]
	movs r0, 0x4
	ands r0, r1
	lsls r0, 16
	lsrs r0, 16
	negs r0, r0
	asrs r2, r0, 31
	movs r0, 0x40
	ands r2, r0
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	beq _080A6616
	subs r2, 0x40
_080A6616:
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _080A6624
	adds r1, r2, 0
	adds r1, 0x48
	b _080A6628
_080A6624:
	adds r1, r2, 0
	adds r1, 0x40
_080A6628:
	adds r0, r3, 0
	adds r0, 0x6A
	strh r1, [r0]
	adds r2, r3, 0
	adds r2, 0x50
	ldrh r1, [r2]
	movs r0, 0x8
	ands r0, r1
	cmp r0, 0
	beq _080A6648
	adds r1, r3, 0
	adds r1, 0x3C
	ldr r0, _080A6644
	b _080A664E
	.align 2, 0
_080A6644: .4byte gUnknown_2039DC0
_080A6648:
	adds r1, r3, 0
	adds r1, 0x3C
	ldr r0, _080A6680
_080A664E:
	ldm r0!, {r4-r6}
	stm r1!, {r4-r6}
	ldrh r1, [r2]
	movs r0, 0x20
	ands r0, r1
	cmp r0, 0
	beq _080A6678
	ldrh r2, [r3, 0x3C]
	ldr r1, _080A6684
	adds r0, r1, 0
	ands r0, r2
	strh r0, [r3, 0x3C]
	adds r2, r3, 0
	adds r2, 0x42
	ldrh r0, [r2]
	ands r1, r0
	movs r3, 0x80
	lsls r3, 3
	adds r0, r3, 0
	orrs r1, r0
	strh r1, [r2]
_080A6678:
	pop {r4-r6}
	pop {r0}
	bx r0
	.align 2, 0
_080A6680: .4byte gUnknown_2039DB0
_080A6684: .4byte 0x0000f3ff
	thumb_func_end sub_80A65F0

	thumb_func_start sub_80A6688
sub_80A6688:
	push {r4,lr}
	adds r4, r0, 0
	adds r0, r1, 0
	bl sub_80A65E0
	adds r1, r0, 0
	lsls r1, 16
	lsrs r1, 16
	adds r0, r4, 0
	bl sub_80A65F0
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_80A6688

	thumb_func_start sub_80A66A4
sub_80A66A4:
	push {lr}
	movs r1, 0
	adds r0, 0x48
	movs r2, 0
	ldrsh r0, [r0, r2]
	cmp r0, 0
	ble _080A66B4
	movs r1, 0x1
_080A66B4:
	adds r0, r1, 0
	pop {r1}
	bx r1
	thumb_func_end sub_80A66A4

	thumb_func_start sub_80A66BC
sub_80A66BC:
	push {lr}
	adds r0, 0x52
	movs r1, 0
	ldrsh r0, [r0, r1]
	cmp r0, 0
	bge _080A66CC
	movs r0, 0
	b _080A66CE
_080A66CC:
	movs r0, 0x1
_080A66CE:
	pop {r1}
	bx r1
	thumb_func_end sub_80A66BC

	thumb_func_start sub_80A66D4
sub_80A66D4:
	push {lr}
	adds r1, r0, 0
	adds r0, 0x52
	movs r2, 0
	ldrsh r0, [r0, r2]
	cmp r0, 0
	bge _080A66F2
	adds r0, r1, 0
	adds r0, 0x48
	movs r1, 0
	ldrsh r0, [r0, r1]
	cmp r0, 0
	ble _080A66F2
	movs r0, 0x1
	b _080A66F4
_080A66F2:
	movs r0, 0
_080A66F4:
	pop {r1}
	bx r1
	thumb_func_end sub_80A66D4

	thumb_func_start sub_80A66F8
sub_80A66F8:
	push {lr}
	adds r1, r0, 0
	adds r0, 0x52
	movs r2, 0
	ldrsh r0, [r0, r2]
	cmp r0, 0
	blt _080A6716
	ldrh r1, [r1]
	movs r0, 0x80
	lsls r0, 6
	ands r0, r1
	cmp r0, 0
	bne _080A6716
	lsrs r0, r1, 15
	b _080A6718
_080A6716:
	movs r0, 0
_080A6718:
	pop {r1}
	bx r1
	thumb_func_end sub_80A66F8

	thumb_func_start sub_80A671C
sub_80A671C:
	push {r4-r6,lr}
	adds r4, r0, 0
	adds r6, r4, 0
	adds r6, 0x58
	movs r0, 0
	ldrsh r1, [r6, r0]
	cmp r1, 0
	beq _080A6752
	movs r0, 0xE0
	lsls r0, 1
	cmp r1, r0
	beq _080A674A
	ldr r0, [r4, 0x5C]
	movs r5, 0x1
	negs r5, r5
	cmp r0, r5
	beq _080A674A
	bl sub_800E9E4
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0
	beq _080A674E
_080A674A:
	movs r0, 0x1
	b _080A6754
_080A674E:
	str r5, [r4, 0x5C]
	strh r0, [r6]
_080A6752:
	movs r0, 0
_080A6754:
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end sub_80A671C

	thumb_func_start sub_80A675C
sub_80A675C:
	push {r4-r6,lr}
	sub sp, 0x8
	adds r6, r1, 0
	mov r0, sp
	bl sub_809D248
	lsls r0, 24
	cmp r0, 0
	beq _080A678C
	ldr r1, [r6]
	cmp r1, 0
	bge _080A6776
	adds r1, 0xFF
_080A6776:
	asrs r1, 8
	ldr r0, [sp]
	subs r4, r1, r0
	ldr r1, [r6, 0x4]
	cmp r1, 0
	bge _080A6784
	adds r1, 0xFF
_080A6784:
	asrs r1, 8
	ldr r0, [sp, 0x4]
	subs r5, r1, r0
	b _080A67A0
_080A678C:
	ldr r0, [r6]
	cmp r0, 0
	bge _080A6794
	adds r0, 0xFF
_080A6794:
	asrs r4, r0, 8
	ldr r1, [r6, 0x4]
	cmp r1, 0
	bge _080A679E
	adds r1, 0xFF
_080A679E:
	asrs r5, r1, 8
_080A67A0:
	adds r1, r4, 0
	adds r1, 0x40
	ldr r0, _080A67BC
	cmp r1, r0
	bhi _080A67C0
	movs r0, 0x10
	negs r0, r0
	cmp r5, r0
	blt _080A67C0
	cmp r5, 0xCF
	bgt _080A67C0
	movs r0, 0x1
	b _080A67C2
	.align 2, 0
_080A67BC: .4byte 0x0000016f
_080A67C0:
	movs r0, 0
_080A67C2:
	add sp, 0x8
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end sub_80A675C

	thumb_func_start sub_80A67CC
sub_80A67CC:
	push {r4-r7,lr}
	adds r4, r0, 0
	adds r5, r1, 0
	movs r7, 0
	cmp r5, 0
	beq _080A67E2
	movs r1, 0
	ldrsh r0, [r5, r1]
	cmp r0, 0
	ble _080A67E2
	movs r7, 0x1
_080A67E2:
	adds r0, r2, 0
	bl sub_80A65E0
	adds r1, r0, 0
	lsls r1, 16
	lsrs r1, 16
	adds r0, r4, 0
	bl sub_80A65F0
	movs r1, 0
	str r1, [r4, 0x74]
	str r1, [r4, 0x78]
	movs r6, 0x1
	negs r6, r6
	str r6, [r4, 0x7C]
	adds r0, r4, 0
	adds r0, 0x70
	strb r1, [r0]
	subs r0, 0x4
	strh r1, [r0]
	adds r0, 0x2
	strh r1, [r0]
	adds r2, r4, 0
	adds r2, 0x52
	ldr r0, _080A6884
	strh r0, [r2]
	str r1, [r4, 0x54]
	adds r0, r4, 0
	adds r0, 0x64
	strh r1, [r0]
	adds r2, 0x14
	adds r0, r6, 0
	adds r3, r0, 0
	strh r0, [r2]
	adds r0, r4, 0
	adds r0, 0x68
	strh r1, [r0]
	subs r0, 0x10
	strh r1, [r0]
	adds r1, r4, 0
	adds r1, 0x5A
	movs r0, 0xFF
	strb r0, [r1]
	str r6, [r4, 0x5C]
	str r6, [r4, 0x60]
	cmp r7, 0
	beq _080A6888
	ldr r0, [r5]
	ldr r1, [r5, 0x4]
	str r0, [r4, 0x48]
	str r1, [r4, 0x4C]
	adds r5, r4, 0
	adds r5, 0x48
	adds r0, r4, 0
	adds r1, r5, 0
	adds r2, r6, 0
	bl sub_80A68F8
	lsls r0, 24
	cmp r0, 0
	bne _080A689A
	adds r0, r4, 0
	adds r0, 0x50
	ldrh r1, [r0]
	movs r0, 0x80
	lsls r0, 5
	ands r0, r1
	cmp r0, 0
	bne _080A689A
	adds r0, r5, 0
	bl sub_80A6CF4
	lsls r0, 24
	cmp r0, 0
	beq _080A689A
	adds r0, r4, 0
	adds r1, r5, 0
	adds r2, r6, 0
	bl sub_80A68F8
	b _080A689A
	.align 2, 0
_080A6884: .4byte 0x0000ffff
_080A6888:
	adds r1, r4, 0
	adds r1, 0x48
	ldrh r0, [r1]
	orrs r0, r3
	strh r0, [r1]
	adds r0, r4, 0
	adds r0, 0x4A
	strh r7, [r0]
	str r7, [r4, 0x4C]
_080A689A:
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_80A67CC

	thumb_func_start sub_80A68A0
sub_80A68A0:
	push {r4,lr}
	adds r4, r0, 0
	adds r0, 0x50
	ldrh r1, [r0]
	movs r0, 0x80
	lsls r0, 2
	ands r0, r1
	cmp r0, 0
	beq _080A68CE
	adds r0, r4, 0
	adds r0, 0x58
	movs r1, 0
	ldrsh r0, [r0, r1]
	cmp r0, 0
	beq _080A68CE
	ldr r1, [r4, 0x5C]
	movs r0, 0x1
	negs r0, r0
	cmp r1, r0
	beq _080A68CE
	adds r0, r1, 0
	bl sub_800DC14
_080A68CE:
	ldr r0, [r4, 0x54]
	cmp r0, 0
	beq _080A68DC
	bl CloseFile
	movs r0, 0
	str r0, [r4, 0x54]
_080A68DC:
	adds r0, r4, 0
	bl sub_80A69FC
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_80A68A0

	thumb_func_start sub_80A68E8
sub_80A68E8:
	push {lr}
	movs r0, 0x15
_080A68EC:
	subs r0, 0x1
	cmp r0, 0
	bge _080A68EC
	pop {r0}
	bx r0
	thumb_func_end sub_80A68E8

	thumb_func_start sub_80A68F8
sub_80A68F8:
	push {r4-r7,lr}
	mov r12, r0
	adds r5, r2, 0
	ldr r0, _080A6924
	ldr r4, [r0]
	movs r2, 0
	ldrsh r0, [r1, r2]
	cmp r0, r5
	blt _080A6956
	adds r5, r0, 0
	movs r3, 0
	ldr r0, [r4]
	mov r6, r12
	adds r6, 0x52
	mov r7, r12
	adds r7, 0x64
	cmp r0, 0
	bne _080A6928
	movs r2, 0x1
	cmp r2, r5
	blt _080A692A
	b _080A6986
	.align 2, 0
_080A6924: .4byte gUnknown_3001B7C
_080A6928:
	movs r2, 0
_080A692A:
	adds r0, r3, 0x1
	lsls r0, 16
	asrs r3, r0, 16
	adds r4, 0xC
	cmp r3, 0x15
	bgt _080A6986
	ldr r0, [r4]
	cmp r0, 0
	bne _080A6928
	adds r2, 0x1
	cmp r2, r5
	blt _080A692A
	lsls r0, r2, 1
	adds r0, r2
	lsls r0, 2
	subs r0, 0xC
	subs r4, r0
	adds r0, r3, 0x1
	subs r0, r2
	lsls r0, 16
	asrs r3, r0, 16
	b _080A6986
_080A6956:
	movs r3, 0x15
	adds r4, 0xFC
	ldr r0, [r4]
	mov r6, r12
	adds r6, 0x52
	mov r7, r12
	adds r7, 0x64
	cmp r0, 0
	bne _080A696C
	movs r2, 0x1
	b _080A6982
_080A696C:
	movs r2, 0
_080A696E:
	subs r0, r3, 0x1
	lsls r0, 16
	asrs r3, r0, 16
	subs r4, 0xC
	cmp r3, 0
	blt _080A6986
	ldr r0, [r4]
	cmp r0, 0
	bne _080A696C
	adds r2, 0x1
_080A6982:
	cmp r2, r5
	blt _080A696E
_080A6986:
	cmp r2, r5
	blt _080A69C4
	strh r3, [r6]
	strh r5, [r7]
	movs r0, 0x1
	str r0, [r4]
	mov r0, r12
	str r0, [r4, 0x8]
	ldrh r1, [r1, 0x2]
	bl GroundSprite_ExtendPaletteAdd
	cmp r5, 0x1
	ble _080A69B2
	movs r2, 0x2
	adds r0, r4, 0
	adds r0, 0xC
	subs r1, r5, 0x1
_080A69A8:
	str r2, [r0]
	adds r0, 0xC
	subs r1, 0x1
	cmp r1, 0
	bne _080A69A8
_080A69B2:
	ldr r1, _080A69C0
	ldr r0, [r1]
	subs r0, r5
	str r0, [r1]
	movs r0, 0x1
	b _080A69EC
	.align 2, 0
_080A69C0: .4byte gUnknown_2039DD4
_080A69C4:
	ldr r1, _080A69F4
	movs r0, 0
	strb r0, [r1]
	movs r0, 0x1
	negs r0, r0
	mov r1, r12
	str r0, [r1, 0x7C]
	mov r0, r12
	adds r0, 0x70
	movs r1, 0
	strb r1, [r0]
	ldr r0, _080A69F8
	strh r0, [r6]
	strh r1, [r7]
	mov r0, r12
	adds r0, 0x6C
	strh r1, [r0]
	adds r0, 0x2
	strh r1, [r0]
	movs r0, 0
_080A69EC:
	pop {r4-r7}
	pop {r1}
	bx r1
	.align 2, 0
_080A69F4: .4byte gUnknown_2039DD0
_080A69F8: .4byte 0x0000ffff
	thumb_func_end sub_80A68F8

	thumb_func_start sub_80A69FC
sub_80A69FC:
	push {r4-r7,lr}
	adds r6, r0, 0
	adds r7, r6, 0
	adds r7, 0x52
	movs r0, 0
	ldrsh r4, [r7, r0]
	ldr r0, _080A6A80
	lsls r1, r4, 1
	adds r1, r4
	lsls r1, 2
	ldr r0, [r0]
	adds r5, r0, r1
	cmp r4, 0
	blt _080A6A7A
	adds r0, r6, 0
	bl GroundSprite_ExtendPaletteDelete
	movs r0, 0
	str r0, [r5, 0x8]
	str r0, [r5]
	adds r5, 0xC
	ldr r1, _080A6A84
	ldr r0, [r1]
	adds r0, 0x1
	str r0, [r1]
	adds r0, r4, 0x1
	lsls r0, 16
	asrs r4, r0, 16
	adds r6, 0x64
	mov r12, r6
	cmp r4, 0x15
	bgt _080A6A6A
	ldr r0, [r5]
	cmp r0, 0x2
	bne _080A6A6A
	movs r6, 0
	adds r2, r1, 0
	lsls r1, r4, 16
	movs r0, 0x80
	lsls r0, 9
	adds r1, r0
	adds r3, r0, 0
_080A6A50:
	str r6, [r5]
	adds r5, 0xC
	ldr r0, [r2]
	adds r0, 0x1
	str r0, [r2]
	adds r0, r1, 0
	adds r1, r3
	asrs r4, r0, 16
	cmp r4, 0x15
	bgt _080A6A6A
	ldr r0, [r5]
	cmp r0, 0x2
	beq _080A6A50
_080A6A6A:
	ldr r0, _080A6A88
	strh r0, [r7]
	movs r0, 0
	mov r1, r12
	strh r0, [r1]
	ldr r1, _080A6A8C
	movs r0, 0x1
	strb r0, [r1]
_080A6A7A:
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_080A6A80: .4byte gUnknown_3001B7C
_080A6A84: .4byte gUnknown_2039DD4
_080A6A88: .4byte 0x0000ffff
_080A6A8C: .4byte gUnknown_2039DD0
	thumb_func_end sub_80A69FC

	thumb_func_start GroundSprite_ExtendPaletteAdd
GroundSprite_ExtendPaletteAdd:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x14
	mov r10, r0
	lsls r1, 16
	lsrs r2, r1, 16
	adds r5, r2, 0
	movs r0, 0xC0
	lsls r0, 2
	ands r0, r2
	cmp r0, 0
	bne _080A6AB0
	b _080A6C6C
_080A6AB0:
	movs r0, 0x80
	lsls r0, 3
	ands r0, r2
	cmp r0, 0
	beq _080A6AD8
	ldr r0, _080A6AD4
	ldr r1, [r0]
	movs r3, 0x86
	lsls r3, 1
	adds r4, r1, r3
	ldrh r1, [r4]
	adds r3, r0, 0
	cmp r1, r2
	bne _080A6B36
	ldrh r0, [r4, 0x2]
	adds r0, 0x1
	strh r0, [r4, 0x2]
	b _080A6C78
	.align 2, 0
_080A6AD4: .4byte gUnknown_3001B7C
_080A6AD8:
	movs r0, 0
	mov r8, r0
	ldr r1, _080A6B1C
	ldr r0, [r1]
	movs r2, 0x84
	lsls r2, 1
	adds r4, r0, r2
	adds r3, r1, 0
	movs r1, 0xE8
	lsls r1, 13
_080A6AEC:
	ldrh r0, [r4]
	cmp r0, r5
	bne _080A6B24
	lsrs r1, 16
	adds r3, r1, 0
	ldrh r0, [r4, 0x2]
	adds r0, 0x1
	strh r0, [r4, 0x2]
	mov r0, r10
	cmp r0, 0
	beq _080A6B08
	subs r1, 0x10
	adds r0, 0x68
	strh r1, [r0]
_080A6B08:
	adds r0, r3, 0
	subs r0, 0x10
	str r0, [sp]
	str r5, [sp, 0x4]
	movs r0, 0
	ldr r1, _080A6B20
	mov r2, r8
	bl Log
	b _080A6C78
	.align 2, 0
_080A6B1C: .4byte gUnknown_3001B7C
_080A6B20: .4byte gUnknown_81177F4
_080A6B24:
	movs r2, 0x80
	lsls r2, 9
	adds r1, r2
	movs r0, 0x1
	add r8, r0
	adds r4, 0x4
	mov r2, r8
	cmp r2, 0x1
	ble _080A6AEC
_080A6B36:
	movs r0, 0x80
	lsls r0, 3
	ands r0, r5
	cmp r0, 0
	beq _080A6B68
	movs r0, 0x1
	mov r8, r0
	ldr r0, [r3]
	movs r1, 0x86
	lsls r1, 1
	adds r4, r0, r1
	movs r2, 0x2
	ldrsh r0, [r4, r2]
	cmp r0, 0
	ble _080A6BA8
	ldr r0, _080A6B60
	ldr r1, _080A6B64
	adds r2, r5, 0
	bl FatalError
	.align 2, 0
_080A6B60: .4byte gUnknown_8117858
_080A6B64: .4byte gUnknown_8117864
_080A6B68:
	movs r0, 0
	mov r8, r0
	ldr r0, [r3]
	movs r1, 0x84
	lsls r1, 1
	adds r4, r0, r1
	movs r2, 0x2
	ldrsh r0, [r4, r2]
	cmp r0, 0
	ble _080A6B90
_080A6B7C:
	movs r3, 0x1
	add r8, r3
	adds r4, 0x4
	mov r0, r8
	cmp r0, 0x1
	bgt _080A6B96
	movs r1, 0x2
	ldrsh r0, [r4, r1]
	cmp r0, 0
	bgt _080A6B7C
_080A6B90:
	mov r2, r8
	cmp r2, 0x1
	ble _080A6BA8
_080A6B96:
	ldr r0, _080A6BA0
	ldr r1, _080A6BA4
	adds r2, r5, 0
	bl FatalError
	.align 2, 0
_080A6BA0: .4byte gUnknown_8117888
_080A6BA4: .4byte gUnknown_8117864
_080A6BA8:
	mov r0, r8
	adds r0, 0x1D
	lsls r0, 16
	lsrs r0, 16
	str r0, [sp, 0xC]
	mov r3, r8
	lsls r0, r3, 20
	movs r1, 0xE8
	lsls r1, 17
	adds r0, r1
	lsrs r0, 16
	str r0, [sp, 0x10]
	movs r0, 0x80
	lsls r0, 2
	ands r0, r5
	cmp r0, 0
	beq _080A6BE8
	ldr r0, _080A6BE0
	ldr r1, _080A6BE4
	bl OpenFileAndGetFileDataPtr
	mov r9, r0
	ldr r7, [r0, 0x4]
	movs r0, 0xFF
	ands r0, r5
	lsls r0, 6
	adds r7, r0
	b _080A6BFE
	.align 2, 0
_080A6BE0: .4byte gUnknown_81177EC
_080A6BE4: .4byte gUnknown_8510000
_080A6BE8:
	movs r0, 0xFF
	ands r0, r5
	lsls r0, 2
	ldr r1, _080A6C60
	adds r0, r1
	ldr r0, [r0]
	ldr r1, _080A6C64
	bl OpenFileAndGetFileDataPtr
	mov r9, r0
	ldr r7, [r0, 0x4]
_080A6BFE:
	movs r0, 0x80
	lsls r0, 5
	ands r0, r5
	lsls r0, 16
	lsrs r0, 16
	negs r0, r0
	lsrs r6, r0, 31
	movs r0, 0x80
	lsls r0, 6
	ands r0, r5
	cmp r0, 0
	beq _080A6C1A
	movs r0, 0x2
	orrs r6, r0
_080A6C1A:
	ldr r0, [sp, 0xC]
	adds r1, r6, 0
	bl sub_80997F4
	ldr r0, [sp, 0x10]
	adds r1, r7, 0
	movs r2, 0x10
	bl sub_809971C
	strh r5, [r4]
	movs r0, 0x1
	strh r0, [r4, 0x2]
	ldr r2, [sp, 0xC]
	subs r2, 0x10
	mov r3, r10
	cmp r3, 0
	beq _080A6C42
	mov r0, r10
	adds r0, 0x68
	strh r2, [r0]
_080A6C42:
	ldr r1, _080A6C68
	str r2, [sp]
	str r5, [sp, 0x4]
	str r6, [sp, 0x8]
	movs r0, 0
	mov r2, r8
	ldr r3, [sp, 0xC]
	bl Log
	mov r0, r9
	cmp r0, 0
	beq _080A6C78
	bl CloseFile
	b _080A6C78
	.align 2, 0
_080A6C60: .4byte gUnknown_81178F4
_080A6C64: .4byte gUnknown_9E60000
_080A6C68: .4byte gUnknown_8117894
_080A6C6C:
	mov r1, r10
	cmp r1, 0
	beq _080A6C78
	mov r0, r10
	adds r0, 0x68
	strh r5, [r0]
_080A6C78:
	add sp, 0x14
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end GroundSprite_ExtendPaletteAdd

	thumb_func_start GroundSprite_ExtendPaletteDelete
GroundSprite_ExtendPaletteDelete:
	push {r4-r6,lr}
	adds r2, r0, 0
	cmp r2, 0
	beq _080A6C9E
	adds r0, 0x68
	ldrh r0, [r0]
	adds r5, r0, 0
	subs r5, 0xD
	cmp r5, 0
	blt _080A6CE6
	b _080A6CA0
_080A6C9E:
	movs r5, 0x1
_080A6CA0:
	ldr r0, _080A6CEC
	lsls r1, r5, 2
	movs r3, 0x84
	lsls r3, 1
	adds r1, r3
	ldr r0, [r0]
	adds r4, r0, r1
	cmp r2, 0
	beq _080A6CBA
	adds r1, r2, 0
	adds r1, 0x68
	movs r0, 0
	strh r0, [r1]
_080A6CBA:
	ldrh r0, [r4, 0x2]
	subs r0, 0x1
	movs r6, 0
	strh r0, [r4, 0x2]
	lsls r0, 16
	cmp r0, 0
	bgt _080A6CE6
	ldr r1, _080A6CF0
	ldrh r3, [r4]
	movs r0, 0
	adds r2, r5, 0
	bl Log
	strh r6, [r4]
	strh r6, [r4, 0x2]
	adds r0, r5, 0
	adds r0, 0x1D
	lsls r0, 16
	lsrs r0, 16
	movs r1, 0
	bl sub_80997F4
_080A6CE6:
	pop {r4-r6}
	pop {r0}
	bx r0
	.align 2, 0
_080A6CEC: .4byte gUnknown_3001B7C
_080A6CF0: .4byte gUnknown_81178C0
	thumb_func_end GroundSprite_ExtendPaletteDelete

	thumb_func_start sub_80A6CF4
sub_80A6CF4:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x68
	movs r1, 0
	mov r8, r1
	movs r1, 0
	ldrsh r2, [r0, r1]
	mov r9, r2
	movs r2, 0
	mov r10, r2
	movs r0, 0x1
	negs r0, r0
	str r0, [sp, 0x60]
	str r0, [sp, 0x64]
	add r4, sp, 0x58
	adds r0, r4, 0
	bl sub_809D248
	movs r7, 0
	ldr r0, _080A6D70
	ldr r3, [r0]
	movs r1, 0x80
	lsls r1, 6
	mov r12, r1
	mov r4, sp
_080A6D2C:
	ldr r0, [r3]
	cmp r0, 0x1
	bne _080A6DB4
	ldr r2, [r3, 0x8]
	adds r0, r2, 0
	adds r0, 0x50
	ldrh r1, [r0]
	mov r0, r12
	ands r0, r1
	cmp r0, 0
	bne _080A6DB4
	ldr r0, [r2, 0x7C]
	cmp r0, 0
	blt _080A6DB4
	ldr r1, [r2, 0x74]
	cmp r1, 0
	bge _080A6D50
	adds r1, 0xFF
_080A6D50:
	asrs r1, 8
	ldr r0, [sp, 0x58]
	subs r5, r1, r0
	ldr r1, [r2, 0x78]
	cmp r1, 0
	bge _080A6D5E
	adds r1, 0xFF
_080A6D5E:
	asrs r1, 8
	ldr r0, [sp, 0x5C]
	subs r1, r0
	adds r6, r1, 0
	cmp r1, 0
	ble _080A6D74
	adds r0, r6, 0
	adds r0, 0x28
	b _080A6D78
	.align 2, 0
_080A6D70: .4byte gUnknown_3001B7C
_080A6D74:
	movs r0, 0x28
	subs r0, r6
_080A6D78:
	str r0, [r2, 0x7C]
	cmp r5, 0
	ble _080A6D88
	ldr r0, [r2, 0x7C]
	cmp r5, r0
	ble _080A6D92
	str r5, [r2, 0x7C]
	b _080A6D92
_080A6D88:
	negs r1, r5
	ldr r0, [r2, 0x7C]
	cmp r1, r0
	ble _080A6D92
	str r1, [r2, 0x7C]
_080A6D92:
	adds r0, r2, 0
	adds r0, 0x48
	movs r1, 0
	ldrsh r0, [r0, r1]
	add r10, r0
	cmp r0, r9
	blt _080A6DAE
	ldr r0, [r2, 0x7C]
	ldr r1, [sp, 0x64]
	cmp r1, r0
	bge _080A6DAE
	mov r1, r8
	str r1, [sp, 0x60]
	str r0, [sp, 0x64]
_080A6DAE:
	stm r4!, {r2}
	movs r2, 0x1
	add r8, r2
_080A6DB4:
	adds r0, r7, 0x1
	lsls r0, 16
	asrs r7, r0, 16
	adds r3, 0xC
	cmp r7, 0x15
	ble _080A6D2C
	cmp r10, r9
	blt _080A6E54
	ldr r0, [sp, 0x60]
	cmp r0, 0
	blt _080A6DD8
	lsls r0, 2
	add r0, sp
	ldr r0, [r0]
	bl sub_80A69FC
	movs r0, 0x1
	b _080A6E56
_080A6DD8:
	mov r1, r8
	cmp r1, 0
	ble _080A6E54
_080A6DDE:
	movs r5, 0x1
	negs r5, r5
	adds r3, r5, 0
	movs r6, 0
	mov r7, r8
	subs r7, 0x1
	mov r2, r8
	cmp r2, 0
	ble _080A6E08
	mov r2, sp
	mov r1, r8
_080A6DF4:
	ldr r0, [r2]
	ldr r0, [r0, 0x7C]
	cmp r3, r0
	bge _080A6E00
	mov r5, r8
	adds r3, r0, 0
_080A6E00:
	adds r2, 0x4
	subs r1, 0x1
	cmp r1, 0
	bne _080A6DF4
_080A6E08:
	lsls r0, r5, 2
	mov r1, sp
	adds r4, r1, r0
	ldr r0, [r4]
	bl sub_80A69FC
	mov r8, r7
	adds r1, r5, 0
	cmp r1, r8
	bge _080A6E28
	adds r2, r4, 0
_080A6E1E:
	ldr r0, [r2, 0x4]
	stm r2!, {r0}
	adds r1, 0x1
	cmp r1, r8
	blt _080A6E1E
_080A6E28:
	movs r1, 0
	ldr r0, _080A6E40
	ldr r3, [r0]
_080A6E2E:
	ldr r0, [r3]
	cmp r0, 0
	bne _080A6E44
	adds r6, 0x1
	cmp r6, r9
	blt _080A6E46
	movs r0, 0x1
	b _080A6E56
	.align 2, 0
_080A6E40: .4byte gUnknown_3001B7C
_080A6E44:
	movs r6, 0
_080A6E46:
	adds r1, 0x1
	adds r3, 0xC
	cmp r1, 0x15
	ble _080A6E2E
	mov r2, r8
	cmp r2, 0
	bgt _080A6DDE
_080A6E54:
	movs r0, 0
_080A6E56:
	add sp, 0x68
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_80A6CF4

	thumb_func_start sub_80A6E68
sub_80A6E68:
	push {lr}
	movs r0, 0
	bl ResetSprites
	movs r0, 0
	bl nullsub_10
	bl sub_800E970
	pop {r0}
	bx r0
	thumb_func_end sub_80A6E68

	thumb_func_start sub_80A6E80
sub_80A6E80:
	push {r4,lr}
	sub sp, 0x4
	ldr r4, _080A6EC4
	adds r0, r4, 0
	bl sub_809D248
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0
	bne _080A6E98
	str r0, [r4]
	str r0, [r4, 0x4]
_080A6E98:
	bl sub_80ABA7C
	bl sub_80ACAD4
	bl sub_80AD7AC
	ldrh r1, [r4, 0x4]
	lsls r1, 16
	ldrh r0, [r4]
	orrs r0, r1
	str r0, [sp]
	mov r0, sp
	bl sub_800E90C
	bl sub_8005180
	bl nullsub_12
	add sp, 0x4
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080A6EC4: .4byte gUnknown_2039DD8
	thumb_func_end sub_80A6E80

	thumb_func_start sub_80A6EC8
sub_80A6EC8:
	push {lr}
	adds r2, r0, 0
	adds r0, 0x52
	movs r3, 0
	ldrsh r0, [r0, r3]
	cmp r0, 0
	ble _080A6EF6
	adds r0, r2, 0
	adds r0, 0x48
	movs r3, 0
	ldrsh r0, [r0, r3]
	cmp r1, r0
	bgt _080A6EE4
	adds r1, r0, 0
_080A6EE4:
	adds r0, r2, 0
	adds r0, 0x64
	movs r3, 0
	ldrsh r0, [r0, r3]
	cmp r0, r1
	beq _080A6EF6
	adds r0, r2, 0
	adds r0, 0x66
	strh r1, [r0]
_080A6EF6:
	pop {r0}
	bx r0
	thumb_func_end sub_80A6EC8

	thumb_func_start sub_80A6EFC
sub_80A6EFC:
	push {r4-r7,lr}
	sub sp, 0xC
	adds r4, r0, 0
	lsls r1, 16
	asrs r7, r1, 16
	lsls r2, 24
	asrs r6, r2, 24
	adds r0, 0x52
	movs r1, 0
	ldrsh r0, [r0, r1]
	cmp r0, 0
	bge _080A6F48
	adds r5, r4, 0
	adds r5, 0x66
	movs r2, 0
	ldrsh r0, [r5, r2]
	cmp r0, 0
	blt _080A6F28
	adds r1, r4, 0
	adds r1, 0x48
	adds r2, r0, 0
	b _080A6F62
_080A6F28:
	adds r1, r4, 0
	adds r1, 0x48
	movs r2, 0
	ldrsh r0, [r1, r2]
	cmp r0, 0
	bgt _080A6F36
	b _080A7038
_080A6F36:
	movs r2, 0x1
	negs r2, r2
	adds r0, r4, 0
	bl sub_80A68F8
	lsls r0, 24
	cmp r0, 0
	beq _080A7038
	b _080A6F72
_080A6F48:
	adds r5, r4, 0
	adds r5, 0x66
	movs r1, 0
	ldrsh r0, [r5, r1]
	cmp r0, 0
	blt _080A6F72
	adds r0, r4, 0
	bl sub_80A69FC
	adds r1, r4, 0
	adds r1, 0x48
	movs r0, 0
	ldrsh r2, [r5, r0]
_080A6F62:
	adds r0, r4, 0
	bl sub_80A68F8
	lsls r0, 24
	cmp r0, 0
	beq _080A7038
	ldr r0, _080A6F8C
	strh r0, [r5]
_080A6F72:
	movs r0, 0x80
	lsls r0, 3
	ands r0, r7
	lsls r0, 16
	asrs r3, r0, 16
	cmp r3, 0
	beq _080A6F94
	ldrh r1, [r4]
	ldr r0, _080A6F90
	ands r0, r1
	strh r0, [r4]
	b _080A7038
	.align 2, 0
_080A6F8C: .4byte 0x0000ffff
_080A6F90: .4byte 0x0000efff
_080A6F94:
	ldr r2, _080A6FE0
	adds r0, r4, 0
	adds r0, 0x52
	movs r5, 0
	ldrsh r1, [r0, r5]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 2
	ldr r1, [r2]
	adds r1, r0
	mov r12, r1
	adds r1, r4, 0
	adds r1, 0x70
	movs r0, 0x1
	strb r0, [r1]
	subs r0, 0x2
	str r0, [r4, 0x7C]
	movs r1, 0xE0
	lsls r1, 3
	ands r1, r7
	movs r0, 0x80
	lsls r0, 1
	cmp r1, r0
	beq _080A6FE4
	cmp r1, r0
	ble _080A6FEE
	movs r0, 0x80
	lsls r0, 2
	cmp r1, r0
	beq _080A6FFA
	movs r0, 0xC0
	lsls r0, 2
	cmp r1, r0
	bne _080A6FEE
	adds r0, r4, 0
	adds r0, 0x6C
	strh r3, [r0]
	b _080A7000
	.align 2, 0
_080A6FE0: .4byte gUnknown_3001B7C
_080A6FE4:
	adds r1, r4, 0
	adds r1, 0x6C
	movs r0, 0x80
	strh r0, [r1]
	b _080A7000
_080A6FEE:
	adds r1, r4, 0
	adds r1, 0x6C
	movs r0, 0x80
	lsls r0, 1
	strh r0, [r1]
	b _080A7000
_080A6FFA:
	adds r0, r4, 0
	adds r0, 0x6C
	strh r1, [r0]
_080A7000:
	adds r0, r4, 0
	adds r0, 0x6E
	movs r1, 0
	strh r1, [r0]
	ldr r5, [r4, 0x4C]
	movs r0, 0xFF
	ands r0, r7
	adds r2, r6, 0
	cmp r6, 0
	bge _080A7016
	adds r2, r6, 0x7
_080A7016:
	asrs r2, 3
	adds r2, r0, r2
	movs r3, 0x7
	ands r3, r6
	mov r6, r12
	ldr r0, [r6, 0x4]
	str r0, [sp]
	str r1, [sp, 0x4]
	lsls r0, r7, 16
	lsrs r0, 27
	movs r1, 0x1
	ands r0, r1
	str r0, [sp, 0x8]
	adds r0, r4, 0
	adds r1, r5, 0
	bl sub_80053D0
_080A7038:
	add sp, 0xC
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_80A6EFC

	thumb_func_start sub_80A7040
sub_80A7040:
	push {r4,r5,lr}
	adds r4, r0, 0
	adds r5, r3, 0
	lsls r1, 16
	asrs r3, r1, 16
	lsls r2, 24
	asrs r2, 24
	adds r0, 0x50
	ldrh r1, [r0]
	movs r0, 0x80
	lsls r0, 2
	ands r0, r1
	cmp r0, 0
	beq _080A708C
	cmp r3, 0
	beq _080A7068
	movs r0, 0xE0
	lsls r0, 1
	cmp r3, r0
	bne _080A7080
_080A7068:
	adds r0, r4, 0
	bl sub_80A671C
	lsls r0, 24
	cmp r0, 0
	beq _080A708C
	adds r1, r4, 0
	adds r1, 0x58
	movs r0, 0xE0
	lsls r0, 1
	strh r0, [r1]
	b _080A708C
_080A7080:
	adds r0, r4, 0
	adds r0, 0x58
	strh r3, [r0]
	adds r0, 0x2
	strb r2, [r0]
	str r5, [r4, 0x60]
_080A708C:
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_80A7040

	thumb_func_start sub_80A7094
sub_80A7094:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x40
	adds r7, r0, 0
	mov r10, r1
	mov r8, r2
	str r3, [sp, 0x3C]
	ldr r0, [r2]
	ldr r1, [r2, 0x4]
	str r0, [r7, 0x74]
	str r1, [r7, 0x78]
	movs r6, 0
	str r6, [r7, 0x7C]
	adds r0, r7, 0
	adds r0, 0x50
	ldrh r1, [r0]
	movs r0, 0x80
	lsls r0, 2
	ands r0, r1
	cmp r0, 0
	beq _080A7172
	adds r4, r7, 0
	adds r4, 0x58
	movs r0, 0
	ldrsh r1, [r4, r0]
	cmp r1, 0
	beq _080A7172
	movs r0, 0xE0
	lsls r0, 1
	cmp r1, r0
	bne _080A70EC
	ldr r0, [r7, 0x5C]
	movs r5, 0x1
	negs r5, r5
	cmp r0, r5
	beq _080A70E8
	bl sub_800DC14
	str r5, [r7, 0x5C]
_080A70E8:
	strh r6, [r4]
	b _080A7172
_080A70EC:
	ldr r0, [r7, 0x5C]
	movs r1, 0x1
	negs r1, r1
	mov r9, r1
	cmp r0, r9
	bne _080A7160
	add r1, sp, 0x8
	ldr r0, _080A715C
	ldm r0!, {r2,r3,r5}
	stm r1!, {r2,r3,r5}
	movs r1, 0
	ldrsh r0, [r4, r1]
	bl sub_800EE5C
	bl sub_800EF64
	add r2, sp, 0x14
	movs r3, 0
	ldrsh r0, [r4, r3]
	str r0, [sp, 0x14]
	str r6, [r2, 0x4]
	adds r0, r7, 0
	adds r0, 0x5A
	ldrb r0, [r0]
	lsls r0, 24
	asrs r0, 24
	str r0, [r2, 0x8]
	mov r4, r8
	ldr r0, [r4]
	cmp r0, 0
	bge _080A712C
	adds r0, 0xFF
_080A712C:
	asrs r0, 8
	strh r0, [r2, 0xC]
	mov r5, r8
	ldr r0, [r5, 0x4]
	cmp r0, 0
	bge _080A713A
	adds r0, 0xFF
_080A713A:
	asrs r0, 8
	strh r0, [r2, 0xE]
	strh r6, [r2, 0x10]
	strh r6, [r2, 0x12]
	mov r0, r9
	str r0, [r2, 0x14]
	str r6, [r2, 0x18]
	add r1, sp, 0x30
	add r0, sp, 0x8
	ldm r0!, {r3-r5}
	stm r1!, {r3-r5}
	adds r0, r2, 0
	bl sub_800E890
	str r0, [r7, 0x5C]
	b _080A7172
	.align 2, 0
_080A715C: .4byte gUnknown_81178E0
_080A7160:
	bl sub_800E9E4
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0
	bne _080A7172
	mov r1, r9
	str r1, [r7, 0x5C]
	strh r0, [r4]
_080A7172:
	adds r0, r7, 0
	adds r0, 0x52
	movs r2, 0
	ldrsh r0, [r0, r2]
	cmp r0, 0
	blt _080A7222
	adds r0, r7, 0
	adds r0, 0x50
	ldrh r4, [r0]
	movs r0, 0x40
	ands r0, r4
	lsls r0, 16
	lsrs r0, 16
	mov r9, r0
	cmp r0, 0
	bne _080A7222
	mov r3, r8
	ldr r1, [r3]
	cmp r1, 0
	bge _080A719C
	adds r1, 0xFF
_080A719C:
	asrs r1, 8
	ldr r2, _080A7228
	ldr r0, [r2]
	subs r5, r1, r0
	mov r1, r8
	ldr r0, [r1, 0x4]
	cmp r0, 0
	bge _080A71AE
	adds r0, 0xFF
_080A71AE:
	asrs r1, r0, 8
	ldr r0, [r2, 0x4]
	subs r6, r1, r0
	ldr r3, [sp, 0x3C]
	cmp r3, 0
	bge _080A71BC
	adds r3, 0xFF
_080A71BC:
	asrs r0, r3, 8
	subs r0, r6, r0
	mov r8, r0
	adds r1, r5, 0
	adds r1, 0x40
	ldr r0, _080A722C
	cmp r1, r0
	bhi _080A7274
	movs r0, 0x10
	negs r0, r0
	cmp r6, r0
	blt _080A7274
	cmp r6, 0xCF
	bgt _080A7274
	cmp r8, r0
	blt _080A7274
	mov r2, r8
	cmp r2, 0xCF
	bgt _080A7274
	movs r0, 0x10
	ands r0, r4
	cmp r0, 0
	beq _080A7234
	ldr r0, _080A7230
	ldrh r1, [r0]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _080A7234
	adds r0, r7, 0
	movs r1, 0
	bl sub_80A72B8
	movs r1, 0x98
	lsls r1, 1
	adds r0, r7, 0
	adds r0, 0x68
	ldrh r0, [r0]
	str r0, [sp]
	adds r0, r7, 0
	adds r0, 0x3C
	str r0, [sp, 0x4]
	adds r0, r7, 0
	movs r2, 0xD0
	movs r3, 0
	bl sub_800558C
	adds r0, r7, 0
	adds r0, 0x70
	mov r3, r9
	strb r3, [r0]
_080A7222:
	movs r0, 0
	b _080A72A6
	.align 2, 0
_080A7228: .4byte gUnknown_2039DD8
_080A722C: .4byte 0x0000016f
_080A7230: .4byte gUnknown_2039DCC
_080A7234:
	adds r4, r7, 0
	adds r4, 0x70
	ldrb r1, [r4]
	adds r0, r7, 0
	bl sub_80A72B8
	adds r0, r7, 0
	adds r0, 0x6A
	movs r1, 0
	ldrsh r3, [r0, r1]
	adds r3, r6
	subs r0, 0x2
	ldrh r0, [r0]
	str r0, [sp]
	adds r0, r7, 0
	adds r0, 0x3C
	str r0, [sp, 0x4]
	adds r0, r7, 0
	adds r1, r5, 0
	mov r2, r8
	bl sub_800558C
	movs r0, 0
	strb r0, [r4]
	mov r2, r10
	cmp r2, 0
	beq _080A7270
	mov r3, r10
	str r5, [r3]
	str r6, [r3, 0x4]
_080A7270:
	movs r0, 0x1
	b _080A72A6
_080A7274:
	adds r4, r7, 0
	adds r4, 0x70
	ldrb r0, [r4]
	cmp r0, 0
	beq _080A7222
	adds r0, r7, 0
	movs r1, 0x1
	bl sub_80A72B8
	movs r1, 0x98
	lsls r1, 1
	adds r0, r7, 0
	adds r0, 0x68
	ldrh r0, [r0]
	str r0, [sp]
	adds r0, r7, 0
	adds r0, 0x3C
	str r0, [sp, 0x4]
	adds r0, r7, 0
	movs r2, 0xD0
	movs r3, 0
	bl sub_800558C
	movs r0, 0
	strb r0, [r4]
_080A72A6:
	add sp, 0x40
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_80A7094

	thumb_func_start sub_80A72B8
sub_80A72B8:
	push {r4-r7,lr}
	adds r6, r0, 0
	lsls r1, 24
	cmp r1, 0
	beq _080A72D2
	adds r1, r6, 0
	adds r1, 0x6E
	movs r0, 0
	strh r0, [r1]
	adds r0, r6, 0
	bl sub_80054BC
	b _080A7304
_080A72D2:
	adds r5, r6, 0
	adds r5, 0x6E
	adds r0, r6, 0
	adds r0, 0x6C
	ldrh r0, [r0]
	ldrh r1, [r5]
	adds r0, r1
	strh r0, [r5]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0xFF
	ble _080A7304
	ldr r0, _080A730C
	adds r7, r0, 0
_080A72EE:
	adds r4, r5, 0
	ldrh r1, [r5]
	adds r0, r7, r1
	strh r0, [r5]
	adds r0, r6, 0
	bl sub_80054BC
	movs r1, 0
	ldrsh r0, [r4, r1]
	cmp r0, 0xFF
	bgt _080A72EE
_080A7304:
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_080A730C: .4byte 0xffffff00
	thumb_func_end sub_80A72B8

	thumb_func_start sub_80A7310
sub_80A7310:
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	sub sp, 0x8
	mov r12, r0
	adds r4, r1, 0
	adds r5, r2, 0
	adds r0, 0x50
	ldrh r1, [r0]
	movs r0, 0x80
	lsls r0, 2
	ands r0, r1
	cmp r0, 0
	beq _080A73DC
	mov r0, r12
	ldr r0, [r0, 0x5C]
	mov r8, r0
	movs r0, 0x1
	negs r0, r0
	cmp r8, r0
	beq _080A73DC
	ldr r0, [r4]
	cmp r0, 0
	bge _080A7344
	adds r0, 0xFF
_080A7344:
	lsls r0, 8
	lsrs r0, 16
	ldr r1, _080A73D0
	mov r9, r1
	ldr r2, [sp, 0x4]
	ands r2, r1
	orrs r2, r0
	str r2, [sp, 0x4]
	ldr r0, [r4, 0x4]
	cmp r0, 0
	bge _080A735C
	adds r0, 0xFF
_080A735C:
	lsls r0, 8
	lsrs r0, 16
	lsls r0, 16
	ldr r6, _080A73D4
	adds r4, r6, 0
	ands r4, r2
	orrs r4, r0
	str r4, [sp, 0x4]
	asrs r2, r4, 16
	ldr r0, _080A73D8
	ldr r0, [r0, 0x4]
	subs r0, r2, r0
	mov r1, r12
	adds r1, 0x6A
	movs r7, 0
	ldrsh r1, [r1, r7]
	adds r0, r1
	adds r7, r0, 0x2
	cmp r3, 0
	bge _080A7386
	adds r3, 0xFF
_080A7386:
	asrs r0, r3, 8
	subs r0, r2, r0
	lsls r0, 16
	adds r2, r6, 0
	ands r2, r4
	orrs r2, r0
	str r2, [sp, 0x4]
	cmp r5, 0
	beq _080A73B8
	ldr r1, [r5]
	add r0, sp, 0x4
	ldrh r0, [r0]
	adds r1, r0
	lsls r1, 16
	lsrs r1, 16
	mov r0, r9
	ands r0, r2
	orrs r0, r1
	asrs r2, r0, 16
	ldr r1, [r5, 0x4]
	adds r1, r2
	lsls r1, 16
	ands r0, r6
	orrs r0, r1
	str r0, [sp, 0x4]
_080A73B8:
	mov r0, r12
	adds r0, 0x3C
	str r0, [sp]
	mov r0, r8
	add r1, sp, 0x4
	movs r2, 0
	adds r3, r7, 0
	bl sub_800E8AC
	movs r0, 0x1
	b _080A73DE
	.align 2, 0
_080A73D0: .4byte 0xffff0000
_080A73D4: .4byte 0x0000ffff
_080A73D8: .4byte gUnknown_2039DD8
_080A73DC:
	movs r0, 0
_080A73DE:
	add sp, 0x8
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_80A7310

	thumb_func_start sub_80A73EC
sub_80A73EC:
	push {lr}
	bl CopySpritesToOam
	bl nullsub_13
	bl sub_8005304
	bl nullsub_14
	ldr r1, _080A7420
	ldrh r0, [r1]
	adds r0, 0x1
	strh r0, [r1]
	ldr r1, _080A7424
	ldrh r0, [r1]
	adds r0, 0x1
	strh r0, [r1]
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0xB
	bls _080A741A
	movs r0, 0
	strh r0, [r1]
_080A741A:
	pop {r0}
	bx r0
	.align 2, 0
_080A7420: .4byte gUnknown_2039DCC
_080A7424: .4byte gUnknown_2039DCE
	thumb_func_end sub_80A73EC

	thumb_func_start sub_80A7428
sub_80A7428:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0x14
	adds r6, r0, 0
	mov r8, r3
	lsls r1, 16
	asrs r7, r1, 16
	lsls r2, 16
	asrs r2, 16
	adds r4, r2, 0
	ldr r1, _080A7480
	mov r0, sp
	bl sprintf
	ldr r1, _080A7484
	mov r0, sp
	bl OpenFile
	adds r5, r0, 0
	movs r1, 0
	bl GetFileDataPtr
	adds r0, r4, 0
	bl GetPokemonSize
	lsls r0, 24
	lsrs r0, 24
	ldr r1, _080A7488
	ldr r2, [sp, 0xC]
	ands r2, r1
	orrs r2, r0
	str r2, [sp, 0xC]
	movs r0, 0xD3
	lsls r0, 1
	cmp r4, r0
	bne _080A7490
	ldr r0, _080A748C
	ands r0, r2
	movs r1, 0x91
	lsls r1, 17
	orrs r0, r1
	str r0, [sp, 0xC]
	b _080A74AC
	.align 2, 0
_080A7480: .4byte gUnknown_8117EDC
_080A7484: .4byte gUnknown_8510000
_080A7488: .4byte 0xffff0000
_080A748C: .4byte 0x0000ffff
_080A7490:
	movs r1, 0
	cmp r7, 0x47
	bne _080A7498
	movs r1, 0x1
_080A7498:
	adds r0, r4, 0
	bl sub_808DD68
	lsls r0, 24
	lsrs r0, 8
	ldr r2, _080A74E0
	ldr r1, [sp, 0xC]
	ands r1, r2
	orrs r1, r0
	str r1, [sp, 0xC]
_080A74AC:
	ldr r0, [r5, 0x4]
	add r1, sp, 0xC
	str r0, [r1, 0x4]
	adds r0, r6, 0
	mov r2, r8
	bl sub_80A67CC
	str r5, [r6, 0x54]
	adds r0, r6, 0
	adds r0, 0x52
	movs r1, 0
	ldrsh r0, [r0, r1]
	cmp r0, 0
	blt _080A74D4
	movs r1, 0xC0
	lsls r1, 2
	adds r0, r6, 0
	movs r2, 0
	bl sub_80A6EFC
_080A74D4:
	add sp, 0x14
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_080A74E0: .4byte 0x0000ffff
	thumb_func_end sub_80A7428

	thumb_func_start sub_80A74E4
sub_80A74E4:
	push {lr}
	bl sub_80A68A0
	pop {r0}
	bx r0
	thumb_func_end sub_80A74E4

	thumb_func_start sub_80A74F0
sub_80A74F0:
	push {r4-r6,lr}
	adds r6, r0, 0
	lsls r1, 16
	asrs r4, r1, 16
	lsls r2, 24
	asrs r5, r2, 24
	cmp r3, 0
	bge _080A7514
	movs r0, 0xE0
	lsls r0, 1
	cmp r4, r0
	beq _080A7512
	adds r0, r4, 0
	bl sub_800E700
	adds r3, r0, 0
	b _080A7514
_080A7512:
	movs r3, 0
_080A7514:
	adds r0, r6, 0
	adds r1, r4, 0
	adds r2, r5, 0
	bl sub_80A7040
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end sub_80A74F0

	thumb_func_start sub_80A7524
sub_80A7524:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0x18
	adds r5, r0, 0
	adds r6, r2, 0
	adds r7, r3, 0
	lsls r1, 16
	asrs r1, 16
	mov r8, r1
	mov r1, sp
	bl sub_80A7094
	lsls r0, 24
	cmp r0, 0
	beq _080A75C0
	ldr r1, [r5, 0x5C]
	movs r0, 0x1
	negs r0, r0
	cmp r1, r0
	beq _080A758C
	ldr r2, [r5, 0x60]
	cmp r2, 0x3
	bgt _080A7580
	cmp r2, 0
	blt _080A7580
	add r4, sp, 0x8
	lsls r2, 24
	lsrs r2, 24
	adds r0, r4, 0
	adds r1, r5, 0
	bl sub_800569C
	movs r1, 0
	ldrsh r0, [r4, r1]
	str r0, [sp, 0xC]
	movs r1, 0x2
	ldrsh r0, [r4, r1]
	add r2, sp, 0xC
	str r0, [r2, 0x4]
	adds r0, r5, 0
	adds r1, r6, 0
	adds r3, r7, 0
	bl sub_80A7310
	b _080A758C
_080A7580:
	adds r0, r5, 0
	adds r1, r6, 0
	movs r2, 0
	adds r3, r7, 0
	bl sub_80A7310
_080A758C:
	adds r0, r5, 0
	adds r0, 0x50
	ldrh r1, [r0]
	movs r0, 0x80
	lsls r0, 1
	ands r0, r1
	cmp r0, 0
	beq _080A75B4
	ldr r0, [sp]
	lsls r0, 16
	ldr r1, [sp, 0x4]
	lsls r1, 16
	lsrs r0, 16
	orrs r0, r1
	str r0, [sp, 0x14]
	add r1, sp, 0x14
	mov r0, r8
	adds r2, r5, 0
	bl sub_808E668
_080A75B4:
	adds r0, r5, 0
	adds r1, r6, 0
	movs r2, 0
	adds r3, r7, 0
	bl sub_80A7310
_080A75C0:
	add sp, 0x18
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_80A7524

	thumb_func_start sub_80A75CC
sub_80A75CC:
	push {r4-r6,lr}
	sub sp, 0x8
	adds r4, r0, 0
	adds r6, r3, 0
	lsls r2, 16
	asrs r2, 13
	ldr r0, _080A7618
	adds r2, r0
	movs r5, 0
	movs r0, 0
	ldrsb r0, [r2, r0]
	lsls r0, 16
	lsrs r0, 16
	ldr r3, _080A761C
	ldr r1, [sp]
	ands r1, r3
	orrs r1, r0
	str r1, [sp]
	ldrh r3, [r2, 0x2]
	lsls r3, 16
	ldr r0, _080A7620
	ands r0, r1
	orrs r0, r3
	str r0, [sp]
	ldr r0, [r2, 0x4]
	cmp r0, 0
	beq _080A7628
	ldr r1, _080A7624
	bl OpenFile
	adds r5, r0, 0
	movs r1, 0
	bl GetFileDataPtr
	ldr r0, [r5, 0x4]
	str r0, [sp, 0x4]
	b _080A762A
	.align 2, 0
_080A7618: .4byte gUnknown_8117AE4
_080A761C: .4byte 0xffff0000
_080A7620: .4byte 0x0000ffff
_080A7624: .4byte gUnknown_9E60000
_080A7628:
	str r5, [sp, 0x4]
_080A762A:
	adds r0, r4, 0
	mov r1, sp
	adds r2, r6, 0
	bl sub_80A67CC
	str r5, [r4, 0x54]
	adds r0, r4, 0
	adds r0, 0x52
	movs r1, 0
	ldrsh r0, [r0, r1]
	cmp r0, 0
	blt _080A764E
	movs r1, 0x80
	lsls r1, 4
	adds r0, r4, 0
	movs r2, 0
	bl sub_80A6EFC
_080A764E:
	add sp, 0x8
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end sub_80A75CC

	thumb_func_start sub_80A7658
sub_80A7658:
	push {lr}
	bl sub_80A68A0
	pop {r0}
	bx r0
	thumb_func_end sub_80A7658

	thumb_func_start sub_80A7664
sub_80A7664:
	push {r4-r6,lr}
	adds r4, r0, 0
	adds r5, r1, 0
	adds r6, r2, 0
	movs r1, 0
	adds r2, r5, 0
	adds r3, r6, 0
	bl sub_80A7094
	adds r0, r4, 0
	adds r1, r5, 0
	movs r2, 0
	adds r3, r6, 0
	bl sub_80A7310
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end sub_80A7664

	thumb_func_start sub_80A7688
sub_80A7688:
	push {r4-r6,lr}
	sub sp, 0x8
	adds r4, r0, 0
	adds r6, r3, 0
	lsls r2, 16
	asrs r2, 13
	ldr r0, _080A76D4
	adds r2, r0
	movs r5, 0
	movs r0, 0
	ldrsb r0, [r2, r0]
	lsls r0, 16
	lsrs r0, 16
	ldr r3, _080A76D8
	ldr r1, [sp]
	ands r1, r3
	orrs r1, r0
	str r1, [sp]
	ldrh r3, [r2, 0x2]
	lsls r3, 16
	ldr r0, _080A76DC
	ands r0, r1
	orrs r0, r3
	str r0, [sp]
	ldr r0, [r2, 0x4]
	cmp r0, 0
	beq _080A76E4
	ldr r1, _080A76E0
	bl OpenFile
	adds r5, r0, 0
	movs r1, 0
	bl GetFileDataPtr
	ldr r0, [r5, 0x4]
	str r0, [sp, 0x4]
	b _080A76E6
	.align 2, 0
_080A76D4: .4byte gUnknown_8117E8C
_080A76D8: .4byte 0xffff0000
_080A76DC: .4byte 0x0000ffff
_080A76E0: .4byte gUnknown_9E60000
_080A76E4:
	str r5, [sp, 0x4]
_080A76E6:
	adds r0, r4, 0
	mov r1, sp
	adds r2, r6, 0
	bl sub_80A67CC
	str r5, [r4, 0x54]
	adds r0, r4, 0
	adds r0, 0x52
	movs r1, 0
	ldrsh r0, [r0, r1]
	cmp r0, 0
	blt _080A770A
	movs r1, 0x80
	lsls r1, 4
	adds r0, r4, 0
	movs r2, 0
	bl sub_80A6EFC
_080A770A:
	add sp, 0x8
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end sub_80A7688

        .align 2,0
