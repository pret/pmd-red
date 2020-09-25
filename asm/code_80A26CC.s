	.include "constants/gba_constants.inc"
	.include "asm/macros.inc"

	.syntax unified

	.text	

	thumb_func_start sub_80A26CC
sub_80A26CC:
	lsls r0, 16
	movs r1, 0xDC
	lsls r1, 14
	adds r0, r1
	asrs r0, 16
	bx lr
	thumb_func_end sub_80A26CC

	thumb_func_start sub_80A26D8
sub_80A26D8:
	push {r4-r6,lr}
	lsls r0, 24
	lsrs r6, r0, 24
	movs r5, 0
_080A26E0:
	lsls r0, r5, 16
	asrs r4, r0, 16
	adds r0, r4, 0
	bl sub_80A2608
	adds r1, r0, 0
	ldrb r0, [r1, 0x11]
	cmp r0, 0
	beq _080A26FC
	ldrb r0, [r1, 0xC]
	cmp r0, r6
	bne _080A26FC
	adds r0, r4, 0
	b _080A2706
_080A26FC:
	adds r5, 0x1
	cmp r5, 0x52
	ble _080A26E0
	movs r0, 0x1
	negs r0, r0
_080A2706:
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end sub_80A26D8

	thumb_func_start sub_80A270C
sub_80A270C:
	push {lr}
	lsls r0, 16
	ldr r1, _080A2724
	asrs r0, 15
	adds r0, r1
	movs r1, 0
	ldrsh r0, [r0, r1]
	bl sub_80A2608
	ldrb r0, [r0, 0xC]
	pop {r1}
	bx r1
	.align 2, 0
_080A2724: .4byte gUnknown_8116F9A
	thumb_func_end sub_80A270C

	thumb_func_start sub_80A2728
sub_80A2728:
	push {lr}
	lsls r0, 16
	movs r1, 0xDC
	lsls r1, 14
	adds r0, r1
	asrs r0, 16
	bl sub_80A2608
	ldrb r0, [r0, 0xC]
	pop {r1}
	bx r1
	thumb_func_end sub_80A2728

	thumb_func_start sub_80A2740
sub_80A2740:
	push {lr}
	lsls r0, 16
	asrs r0, 16
	bl sub_80A2608
	ldrb r0, [r0, 0xC]
	pop {r1}
	bx r1
	thumb_func_end sub_80A2740

        thumb_func_start sub_80A2750
sub_80A2750:
	push {r4,lr}
	lsls r0, 16
	asrs r1, r0, 16
	adds r2, r1, 0
	cmp r1, 0x50
	bne _080A2760
	movs r0, 0x3
	b _080A27C4
_080A2760:
	cmp r1, 0x51
	beq _080A27BE
	cmp r1, 0x52
	beq _080A2780
	adds r0, r1, 0
	subs r0, 0x28
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0xE
	bls _080A27BE
	adds r0, r1, 0
	subs r0, 0x37
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0x18
	bhi _080A2784
_080A2780:
	movs r0, 0x4
	b _080A27C4
_080A2784:
	adds r0, r2, 0
	bl sub_80A2608
	adds r4, r0, 0
	movs r0, 0xE
	ldrsh r1, [r4, r0]
	movs r0, 0x1
	negs r0, r0
	cmp r1, r0
	beq _080A27C2
	movs r0, 0x5
	bl sub_80023E4
	lsls r0, 24
	cmp r0, 0
	bne _080A27C2
	movs r1, 0xE
	ldrsh r0, [r4, r1]
	bl sub_80973F4
	lsls r0, 24
	cmp r0, 0
	beq _080A27C2
	movs r0, 0x1
	bl sub_80023E4
	lsls r0, 24
	cmp r0, 0
	beq _080A27C2
_080A27BE:
	movs r0, 0x2
	b _080A27C4
_080A27C2:
	movs r0, 0x1
_080A27C4:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_80A2750

	thumb_func_start sub_80A27CC
sub_80A27CC:
	push {r4,r5,lr}
	lsls r0, 16
	asrs r4, r0, 16
	adds r5, r4, 0
	adds r0, r4, 0
	bl sub_80A2620
	movs r2, 0
	ldrsh r1, [r0, r2]
	movs r0, 0x1
	negs r0, r0
	cmp r1, r0
	beq _080A281A
	movs r0, 0x5
	bl sub_80023E4
	lsls r0, 24
	cmp r0, 0
	bne _080A281A
	adds r0, r4, 0
	bl sub_8097384
	lsls r0, 24
	cmp r0, 0
	bne _080A2816
	movs r0, 0x1
	bl sub_80023E4
	lsls r0, 24
	cmp r0, 0
	beq _080A281A
	adds r0, r5, 0
	bl sub_80973F4
	lsls r0, 24
	cmp r0, 0
	beq _080A281A
_080A2816:
	movs r0, 0x1
	b _080A281C
_080A281A:
	movs r0, 0
_080A281C:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_80A27CC

	thumb_func_start sub_80A2824
sub_80A2824:
	push {r4-r6,lr}
	lsls r0, 24
	lsrs r6, r0, 24
	movs r0, 0x5
	bl sub_80023E4
	lsls r0, 24
	cmp r0, 0
	bne _080A28AC
	movs r0, 0x1
	bl sub_80023E4
	lsls r0, 24
	cmp r0, 0
	beq _080A2880
	movs r5, 0
_080A2844:
	lsls r0, r5, 16
	asrs r4, r0, 16
	adds r0, r4, 0
	bl sub_80A2620
	adds r1, r0, 0
	ldrb r0, [r1, 0x11]
	cmp r0, 0
	beq _080A2874
	ldrb r0, [r1, 0xC]
	cmp r0, r6
	bne _080A2874
	adds r0, r4, 0
	bl sub_8097384
	lsls r0, 24
	cmp r0, 0
	bne _080A287C
	adds r0, r4, 0
	bl sub_80973F4
	lsls r0, 24
	cmp r0, 0
	bne _080A287C
_080A2874:
	adds r5, 0x1
	cmp r5, 0x2D
	ble _080A2844
	b _080A28AC
_080A287C:
	movs r0, 0x1
	b _080A28AE
_080A2880:
	movs r5, 0
_080A2882:
	lsls r0, r5, 16
	asrs r4, r0, 16
	adds r0, r4, 0
	bl sub_80A2620
	adds r1, r0, 0
	ldrb r0, [r1, 0x11]
	cmp r0, 0
	beq _080A28A6
	ldrb r0, [r1, 0xC]
	cmp r0, r6
	bne _080A28A6
	adds r0, r4, 0
	bl sub_8097384
	lsls r0, 24
	cmp r0, 0
	bne _080A287C
_080A28A6:
	adds r5, 0x1
	cmp r5, 0x2D
	ble _080A2882
_080A28AC:
	movs r0, 0
_080A28AE:
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end sub_80A2824

	thumb_func_start sub_80A28B4
sub_80A28B4:
	push {r4,lr}
	lsls r0, 16
	asrs r4, r0, 16
	adds r0, r4, 0
	bl sub_80A2620
	movs r2, 0
	ldrsh r1, [r0, r2]
	movs r0, 0x1
	negs r0, r0
	cmp r1, r0
	beq _080A28E8
	adds r0, r4, 0
	bl sub_8097384
	lsls r0, 24
	cmp r0, 0
	bne _080A28E4
	adds r0, r4, 0
	bl sub_80973F4
	lsls r0, 24
	cmp r0, 0
	beq _080A28E8
_080A28E4:
	movs r0, 0x1
	b _080A28EA
_080A28E8:
	movs r0, 0
_080A28EA:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_80A28B4

	thumb_func_start sub_80A28F0
sub_80A28F0:
	push {r4-r6,lr}
	lsls r0, 24
	lsrs r6, r0, 24
	movs r5, 0
_080A28F8:
	lsls r0, r5, 16
	asrs r4, r0, 16
	adds r0, r4, 0
	bl sub_80A2620
	adds r1, r0, 0
	ldrb r0, [r1, 0x11]
	cmp r0, 0
	beq _080A292C
	ldrb r0, [r1, 0xC]
	cmp r0, r6
	bne _080A292C
	adds r0, r4, 0
	bl sub_8097384
	lsls r0, 24
	cmp r0, 0
	bne _080A2928
	adds r0, r4, 0
	bl sub_80973F4
	lsls r0, 24
	cmp r0, 0
	beq _080A292C
_080A2928:
	movs r0, 0x1
	b _080A2934
_080A292C:
	adds r5, 0x1
	cmp r5, 0x2D
	ble _080A28F8
	movs r0, 0
_080A2934:
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end sub_80A28F0

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
	bl sub_800CCA0
	b _080A49AE
_080A49A6:
	ldr r0, [r4, 0x48]
	ldr r1, [r4, 0x4C]
	bl sub_800CCAC
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
	bl sub_808DACC
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

	thumb_func_start sub_80A7714
sub_80A7714:
	push {lr}
	bl sub_80A68A0
	pop {r0}
	bx r0
	thumb_func_end sub_80A7714

	thumb_func_start sub_80A7720
sub_80A7720:
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
	thumb_func_end sub_80A7720

	thumb_func_start sub_80A7744
sub_80A7744:
	ldr r1, _080A7750
	movs r2, 0x1
	negs r2, r2
	adds r0, r2, 0
	strh r0, [r1]
	bx lr
	.align 2, 0
_080A7750: .4byte gUnknown_2039DE0
	thumb_func_end sub_80A7744

	thumb_func_start sub_80A7754
sub_80A7754:
	ldr r1, _080A7760
	movs r2, 0x1
	negs r2, r2
	adds r0, r2, 0
	strh r0, [r1]
	bx lr
	.align 2, 0
_080A7760: .4byte gUnknown_2039DE0
	thumb_func_end sub_80A7754

	thumb_func_start sub_80A7764
sub_80A7764:
	push {r4,lr}
	lsls r0, 16
	asrs r4, r0, 16
	bl sub_80A7784
	movs r0, 0x1
	negs r0, r0
	cmp r4, r0
	beq _080A777A
	ldr r0, _080A7780
	strh r4, [r0]
_080A777A:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080A7780: .4byte gUnknown_2039DE0
	thumb_func_end sub_80A7764

	thumb_func_start sub_80A7784
sub_80A7784:
	push {lr}
	ldr r2, _080A779C
	movs r1, 0
	ldrsh r0, [r2, r1]
	movs r1, 0x1
	negs r1, r1
	cmp r0, r1
	beq _080A7796
	strh r1, [r2]
_080A7796:
	pop {r0}
	bx r0
	.align 2, 0
_080A779C: .4byte gUnknown_2039DE0
	thumb_func_end sub_80A7784

	thumb_func_start sub_80A77A0
sub_80A77A0:
	push {lr}
	lsls r0, 16
	asrs r1, r0, 16
	adds r2, r1, 0
	ldr r0, _080A77BC
	movs r3, 0
	ldrsh r0, [r0, r3]
	cmp r0, r1
	beq _080A77CA
	cmp r1, 0
	bge _080A77C0
	bl sub_80A7784
	b _080A77C6
	.align 2, 0
_080A77BC: .4byte gUnknown_2039DE0
_080A77C0:
	adds r0, r2, 0
	bl sub_80A7764
_080A77C6:
	movs r0, 0x1
	b _080A77CC
_080A77CA:
	movs r0, 0
_080A77CC:
	pop {r1}
	bx r1
	thumb_func_end sub_80A77A0

	thumb_func_start sub_80A77D0
sub_80A77D0:
	push {lr}
	lsls r0, 16
	asrs r1, r0, 16
	movs r0, 0x1
	negs r0, r0
	cmp r1, r0
	bne _080A77E8
	ldr r0, _080A77E4
	b _080A77F0
	.align 2, 0
_080A77E4: .4byte gUnknown_8117EFC
_080A77E8:
	ldr r0, _080A77F4
	lsls r1, 2
	adds r1, r0
	ldr r0, [r1]
_080A77F0:
	pop {r1}
	bx r1
	.align 2, 0
_080A77F4: .4byte gUnknown_811E258
	thumb_func_end sub_80A77D0

	thumb_func_start sub_80A77F8
sub_80A77F8:
	push {r4,r5,lr}
	ldr r4, _080A7860
	movs r0, 0xCE
	lsls r0, 2
	movs r1, 0x6
	bl MemoryAlloc
	str r0, [r4]
	ldr r4, _080A7864
	movs r0, 0xBA
	lsls r0, 6
	movs r1, 0x6
	bl MemoryAlloc
	str r0, [r4]
	adds r1, r0, 0
	ldr r0, _080A7868
	adds r5, r0, 0
	movs r4, 0xF8
	lsls r4, 1
	movs r2, 0x80
	lsls r2, 9
	adds r3, r2, 0
_080A7826:
	ldrh r0, [r1, 0x2]
	orrs r0, r5
	strh r0, [r1, 0x2]
	adds r0, r2, 0
	adds r2, r3
	asrs r0, 16
	adds r1, r4
	cmp r0, 0x17
	ble _080A7826
	ldr r4, _080A7860
	ldr r1, [r4]
	movs r0, 0xCB
	lsls r0, 2
	adds r1, r0
	movs r0, 0
	movs r2, 0x19
	bl sub_809D710
	ldr r0, [r4]
	movs r1, 0xCC
	lsls r1, 2
	adds r0, r1
	movs r1, 0x1
	strh r1, [r0]
	bl sub_80A786C
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_080A7860: .4byte gUnknown_3001B80
_080A7864: .4byte gUnknown_3001B84
_080A7868: .4byte 0x0000ffff
	thumb_func_end sub_80A77F8

	thumb_func_start sub_80A786C
sub_80A786C:
	push {r4-r6,lr}
	ldr r0, _080A78E8
	ldr r4, [r0]
	movs r1, 0
	movs r6, 0x1
	negs r6, r6
	movs r5, 0x80
	lsls r5, 9
_080A787C:
	movs r2, 0x2
	ldrsh r0, [r4, r2]
	cmp r0, r6
	beq _080A788A
	adds r0, r1, 0
	bl GroundLives_Delete
_080A788A:
	adds r0, r5, 0
	movs r1, 0x80
	lsls r1, 9
	adds r5, r1
	asrs r1, r0, 16
	movs r2, 0xF8
	lsls r2, 1
	adds r4, r2
	cmp r1, 0x17
	ble _080A787C
	ldr r3, _080A78EC
	ldr r0, [r3]
	movs r2, 0x1
	negs r2, r2
	str r2, [r0, 0x24]
	adds r0, 0x28
	movs r1, 0xFF
	strb r1, [r0]
	movs r5, 0
	movs r4, 0
	movs r1, 0x2
_080A78B4:
	ldr r0, [r3]
	adds r0, r4
	str r2, [r0, 0x8]
	str r5, [r0]
	str r5, [r0, 0x4]
	adds r4, 0xC
	subs r1, 0x1
	cmp r1, 0
	bge _080A78B4
	ldr r4, _080A78EC
	movs r2, 0
	movs r3, 0x2C
	movs r1, 0x3F
_080A78CE:
	ldr r0, [r4]
	adds r0, r3
	str r2, [r0]
	str r2, [r0, 0x4]
	str r2, [r0, 0x8]
	adds r3, 0xC
	subs r1, 0x1
	cmp r1, 0
	bge _080A78CE
	pop {r4-r6}
	pop {r0}
	bx r0
	.align 2, 0
_080A78E8: .4byte gUnknown_3001B84
_080A78EC: .4byte gUnknown_3001B80
	thumb_func_end sub_80A786C

	thumb_func_start sub_80A78F0
sub_80A78F0:
	push {r4,r5,lr}
	bl sub_80A786C
	ldr r4, _080A7914
	ldr r0, [r4]
	bl MemoryFree
	movs r5, 0
	str r5, [r4]
	ldr r4, _080A7918
	ldr r0, [r4]
	bl MemoryFree
	str r5, [r4]
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_080A7914: .4byte gUnknown_3001B84
_080A7918: .4byte gUnknown_3001B80
	thumb_func_end sub_80A78F0

	thumb_func_start GroundLives_Select
GroundLives_Select:
	push {r4-r7,lr}
	sub sp, 0x4
	adds r4, r0, 0
	lsls r4, 16
	asrs r4, 16
	lsls r1, 16
	asrs r7, r1, 16
	lsls r2, 24
	asrs r6, r2, 24
	ldr r1, _080A7980
	adds r0, r4, 0
	bl sub_80A77D0
	adds r5, r0, 0
	ldr r1, _080A7984
	str r6, [sp]
	movs r0, 0
	adds r2, r4, 0
	adds r3, r7, 0
	bl Log
	lsls r1, r7, 3
	ldr r0, [r5, 0x4]
	adds r0, r1
	lsls r1, r6, 2
	adds r1, r6
	lsls r1, 3
	ldr r0, [r0, 0x4]
	adds r0, r1
	ldr r5, [r0, 0x4]
	ldr r0, [r0]
	cmp r0, 0
	ble _080A7976
	adds r4, r0, 0
_080A7960:
	movs r0, 0x1
	negs r0, r0
	adds r1, r5, 0
	adds r2, r7, 0
	adds r3, r6, 0
	bl GroundLives_Add
	subs r4, 0x1
	adds r5, 0x18
	cmp r4, 0
	bne _080A7960
_080A7976:
	add sp, 0x4
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_080A7980: .4byte gUnknown_811808C
_080A7984: .4byte gUnknown_8118098
	thumb_func_end GroundLives_Select

	thumb_func_start GroundLives_Cancel
GroundLives_Cancel:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	lsls r0, 16
	asrs r7, r0, 16
	lsls r1, 24
	asrs r5, r1, 24
	ldr r1, _080A79F4
	movs r0, 0
	adds r2, r7, 0
	adds r3, r5, 0
	bl Log
	movs r1, 0
	ldr r0, _080A79F8
	ldr r4, [r0]
	movs r0, 0x1
	negs r0, r0
	mov r8, r0
	movs r6, 0x80
	lsls r6, 9
_080A79B2:
	movs r2, 0x2
	ldrsh r0, [r4, r2]
	cmp r0, r8
	beq _080A79D4
	movs r2, 0x4
	ldrsh r0, [r4, r2]
	cmp r0, r7
	bne _080A79D4
	cmp r5, 0
	blt _080A79CE
	movs r0, 0x6
	ldrsb r0, [r4, r0]
	cmp r0, r5
	bne _080A79D4
_080A79CE:
	adds r0, r1, 0
	bl GroundLives_Delete
_080A79D4:
	adds r0, r6, 0
	movs r1, 0x80
	lsls r1, 9
	adds r6, r1
	asrs r1, r0, 16
	movs r2, 0xF8
	lsls r2, 1
	adds r4, r2
	cmp r1, 0x17
	ble _080A79B2
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_080A79F4: .4byte gUnknown_81180BC
_080A79F8: .4byte gUnknown_3001B84
	thumb_func_end GroundLives_Cancel

	thumb_func_start sub_80A79FC
sub_80A79FC:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0x8
	ldr r1, _080A7A70
	movs r0, 0
	bl Log
	movs r6, 0
	ldr r0, _080A7A74
	ldr r4, [r0]
	movs r0, 0x1
	negs r0, r0
	mov r8, r0
	movs r1, 0xA2
	lsls r1, 1
	adds r5, r4, r1
	mov r7, sp
_080A7A20:
	movs r1, 0x2
	ldrsh r0, [r4, r1]
	cmp r0, r8
	beq _080A7A50
	ldr r0, [r5]
	ldr r1, [r4, 0x14]
	adds r0, r1
	str r0, [sp]
	ldr r0, [r5, 0x4]
	ldr r1, [r4, 0x18]
	adds r0, r1
	str r0, [r7, 0x4]
	movs r1, 0xB8
	lsls r1, 1
	adds r0, r4, r1
	mov r1, sp
	bl sub_80A675C
	lsls r0, 24
	cmp r0, 0
	bne _080A7A50
	adds r0, r6, 0
	bl GroundLives_Delete
_080A7A50:
	adds r0, r6, 0x1
	lsls r0, 16
	asrs r6, r0, 16
	movs r0, 0xF8
	lsls r0, 1
	adds r5, r0
	adds r4, r0
	cmp r6, 0x17
	ble _080A7A20
	add sp, 0x8
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_080A7A70: .4byte gUnknown_81180D8
_080A7A74: .4byte gUnknown_3001B84
	thumb_func_end sub_80A79FC

	thumb_func_start sub_80A7A78
sub_80A7A78:
	push {r4-r7,lr}
	ldr r1, _080A7AC0
	movs r0, 0
	bl Log
	movs r6, 0
	ldr r0, _080A7AC4
	ldr r4, [r0]
	movs r7, 0x1
	negs r7, r7
	movs r0, 0x9F
	lsls r0, 1
	adds r5, r4, r0
_080A7A92:
	movs r1, 0x2
	ldrsh r0, [r4, r1]
	cmp r0, r7
	beq _080A7ACC
	movs r1, 0x8E
	lsls r1, 1
	adds r0, r4, r1
	ldr r0, [r0]
	movs r1, 0x80
	lsls r1, 4
	ands r0, r1
	cmp r0, 0
	beq _080A7AC8
	movs r0, 0xA2
	lsls r0, 1
	adds r1, r4, r0
	adds r0, 0x8
	adds r2, r4, r0
	movs r0, 0x20
	bl sub_80ADCA0
	b _080A7ACA
	.align 2, 0
_080A7AC0: .4byte gUnknown_81180D8
_080A7AC4: .4byte gUnknown_3001B84
_080A7AC8:
	ldr r0, _080A7AE4
_080A7ACA:
	strh r0, [r5]
_080A7ACC:
	adds r0, r6, 0x1
	lsls r0, 16
	asrs r6, r0, 16
	movs r1, 0xF8
	lsls r1, 1
	adds r5, r1
	adds r4, r1
	cmp r6, 0x17
	ble _080A7A92
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_080A7AE4: .4byte 0x0000ffff
	thumb_func_end sub_80A7A78

	thumb_func_start sub_80A7AE8
sub_80A7AE8:
	push {r4-r7,lr}
	sub sp, 0x4
	mov r1, sp
	strh r0, [r1]
	mov r0, sp
	bl sub_80A7B94
	mov r0, sp
	movs r1, 0
	ldrsh r2, [r0, r1]
	movs r0, 0x1
	negs r0, r0
	cmp r2, r0
	beq _080A7B34
	movs r3, 0
	ldr r0, _080A7B24
	ldr r1, [r0]
	adds r4, r2, 0
	movs r2, 0x80
	lsls r2, 9
	adds r6, r2, 0
	movs r5, 0xF8
	lsls r5, 1
_080A7B16:
	movs r7, 0x2
	ldrsh r0, [r1, r7]
	cmp r0, r4
	bne _080A7B28
	adds r0, r3, 0
	b _080A7B38
	.align 2, 0
_080A7B24: .4byte gUnknown_3001B84
_080A7B28:
	adds r0, r2, 0
	adds r2, r6
	asrs r3, r0, 16
	adds r1, r5
	cmp r3, 0x17
	ble _080A7B16
_080A7B34:
	movs r0, 0x1
	negs r0, r0
_080A7B38:
	add sp, 0x4
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_80A7AE8

	thumb_func_start sub_80A7B40
sub_80A7B40:
	push {r4-r7,lr}
	lsls r0, 16
	asrs r4, r0, 16
	movs r3, 0
	ldr r0, _080A7B70
	ldr r1, [r0]
	movs r6, 0x1
	negs r6, r6
	movs r2, 0x80
	lsls r2, 9
	movs r5, 0x9E
	lsls r5, 1
_080A7B58:
	movs r7, 0x2
	ldrsh r0, [r1, r7]
	cmp r0, r6
	beq _080A7B74
	adds r0, r1, r5
	movs r7, 0
	ldrsh r0, [r0, r7]
	cmp r0, r4
	bne _080A7B74
	adds r0, r3, 0
	b _080A7B8C
	.align 2, 0
_080A7B70: .4byte gUnknown_3001B84
_080A7B74:
	adds r0, r2, 0
	movs r3, 0x80
	lsls r3, 9
	adds r2, r3
	asrs r3, r0, 16
	movs r7, 0xF8
	lsls r7, 1
	adds r1, r7
	cmp r3, 0x17
	ble _080A7B58
	movs r0, 0x1
	negs r0, r0
_080A7B8C:
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_80A7B40

	thumb_func_start sub_80A7B94
sub_80A7B94:
	push {r4-r7,lr}
	sub sp, 0x10
	adds r7, r0, 0
	movs r0, 0
	ldrsh r2, [r7, r0]
	lsls r0, r2, 1
	adds r0, r2
	lsls r0, 2
	ldr r1, _080A7BD4
	adds r0, r1
	movs r6, 0x1
	negs r6, r6
	movs r1, 0
	ldrsh r5, [r0, r1]
	cmp r5, 0x1
	bne _080A7C14
	adds r0, r2, 0
	cmp r0, 0
	bne _080A7C10
	movs r0, 0
	movs r1, 0x1C
	bl sub_8001658
	adds r4, r0, 0
	cmp r4, 0x1
	beq _080A7BDE
	cmp r4, 0x1
	bgt _080A7BD8
	cmp r4, 0
	beq _080A7BF2
	b _080A7C08
	.align 2, 0
_080A7BD4: .4byte gUnknown_811E63C
_080A7BD8:
	cmp r4, 0x2
	beq _080A7BE4
	b _080A7C08
_080A7BDE:
	movs r0, 0x2
	strh r0, [r7]
	b _080A7C10
_080A7BE4:
	bl sub_808D33C
	adds r6, r0, 0
	bl sub_808D3BC
	cmp r0, r6
	bne _080A7BF6
_080A7BF2:
	strh r5, [r7]
	b _080A7C10
_080A7BF6:
	bl sub_808D3F8
	cmp r0, r6
	bne _080A7C02
	strh r4, [r7]
	b _080A7C10
_080A7C02:
	movs r0, 0x3
	strh r0, [r7]
	b _080A7C10
_080A7C08:
	movs r1, 0x1
	negs r1, r1
	adds r0, r1, 0
	b _080A7DAC
_080A7C10:
	movs r6, 0
	b _080A7DD2
_080A7C14:
	cmp r5, 0x2
	bne _080A7CD2
	movs r0, 0
	movs r1, 0x1D
	bl sub_8001658
	adds r4, r0, 0
	movs r0, 0
	movs r1, 0x1E
	bl sub_8001658
	adds r2, r0, 0
	ldrh r1, [r7]
	subs r0, r1, 0x4
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0x1
	bhi _080A7C82
	cmp r1, 0x4
	bne _080A7C44
	adds r0, r4, 0
	cmp r0, 0
	bne _080A7C4C
	b _080A7C4A
_080A7C44:
	movs r0, 0
	cmp r4, 0
	beq _080A7C4C
_080A7C4A:
	adds r0, r2, 0
_080A7C4C:
	cmp r0, 0x2
	beq _080A7C7A
	cmp r0, 0x2
	bhi _080A7C5A
	cmp r0, 0x1
	beq _080A7C6E
	b _080A7DA6
_080A7C5A:
	cmp r0, 0x3
	beq _080A7C60
	b _080A7DA6
_080A7C60:
	bl sub_808D33C
	adds r4, r0, 0
	bl sub_808D3BC
	cmp r0, r4
	bne _080A7C72
_080A7C6E:
	movs r0, 0x6
	b _080A7C80
_080A7C72:
	bl sub_808D3F8
	cmp r0, r4
	bne _080A7C7E
_080A7C7A:
	movs r0, 0x7
	b _080A7C80
_080A7C7E:
	movs r0, 0x8
_080A7C80:
	strh r0, [r7]
_080A7C82:
	movs r0, 0
	ldrsh r5, [r7, r0]
	cmp r5, 0x7
	beq _080A7CB0
	cmp r5, 0x7
	bgt _080A7C94
	cmp r5, 0x6
	beq _080A7C9A
	b _080A7CCA
_080A7C94:
	cmp r5, 0x8
	beq _080A7CC6
	b _080A7CCA
_080A7C9A:
	movs r6, 0x2
	bl sub_808D33C
	adds r4, r0, 0
	bl sub_808D3BC
	cmp r4, r0
	beq _080A7CAC
	b _080A7DD2
_080A7CAC:
	strh r5, [r7]
	b _080A7DD2
_080A7CB0:
	movs r6, 0x1
	bl sub_808D33C
	adds r4, r0, 0
	bl sub_808D3F8
	cmp r4, r0
	beq _080A7CC2
	b _080A7DD2
_080A7CC2:
	movs r0, 0x6
	b _080A7DD0
_080A7CC6:
	movs r6, 0x2
	b _080A7DD2
_080A7CCA:
	movs r1, 0x1
	negs r1, r1
	adds r0, r1, 0
	b _080A7DAC
_080A7CD2:
	cmp r5, 0x3
	bne _080A7DB0
	ldrh r1, [r7]
	adds r0, r1, 0
	subs r0, 0xA
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0x3
	bhi _080A7D12
	adds r4, r2, 0
	subs r4, 0xA
	bl sub_8098F88
	lsls r0, 24
	cmp r0, 0
	bne _080A7DD2
	movs r0, 0x9
	bl sub_80023E4
	lsls r0, 24
	cmp r0, 0
	beq _080A7D06
	mov r0, sp
	bl sub_808D6A4
	b _080A7D0C
_080A7D06:
	mov r0, sp
	bl sub_808D654
_080A7D0C:
	cmp r4, r0
	bge _080A7DA6
	b _080A7D7E
_080A7D12:
	adds r0, r1, 0
	subs r0, 0xE
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0xF
	bhi _080A7DA6
	movs r0, 0
	movs r1, 0x10
	bl sub_8001658
	lsls r0, 16
	asrs r0, 16
	bl sub_8002658
	lsls r0, 24
	lsrs r1, r0, 24
	cmp r1, 0
	beq _080A7DA6
	movs r2, 0
	ldrsh r0, [r7, r2]
	adds r4, r0, 0
	subs r4, 0xE
	adds r0, r1, 0
	mov r1, sp
	movs r2, 0
	movs r3, 0
	bl sub_8092638
	mov r0, sp
	movs r1, 0
	ldrsh r0, [r0, r1]
	cmp r4, r0
	bge _080A7DA6
	ldr r2, _080A7D84
	ldr r0, [sp, 0x8]
	adds r0, r4
	movs r1, 0x58
	muls r1, r0
	ldr r0, [r2]
	adds r4, r0, r1
	movs r0, 0x9
	bl sub_80023E4
	lsls r0, 24
	cmp r0, 0
	beq _080A7D88
	ldrb r1, [r4]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _080A7DA6
	ldrb r0, [r4, 0x2]
	cmp r0, 0
	bne _080A7DA6
_080A7D7E:
	movs r0, 0x1
	negs r0, r0
	b _080A7DD4
	.align 2, 0
_080A7D84: .4byte gUnknown_203B45C
_080A7D88:
	ldrb r1, [r4]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _080A7DA6
	ldrb r0, [r4, 0x2]
	cmp r0, 0
	bne _080A7DA6
	movs r1, 0
	ldrb r0, [r4, 0x4]
	cmp r0, 0x41
	bne _080A7DA2
	movs r1, 0x1
_080A7DA2:
	cmp r1, 0
	beq _080A7D7E
_080A7DA6:
	movs r2, 0x1
	negs r2, r2
	adds r0, r2, 0
_080A7DAC:
	strh r0, [r7]
	b _080A7D7E
_080A7DB0:
	cmp r2, 0x23
	bne _080A7DD2
	bl sub_808D33C
	adds r4, r0, 0
	bl sub_808D3BC
	cmp r0, r4
	bne _080A7DC6
	movs r0, 0x21
	b _080A7DD0
_080A7DC6:
	bl sub_808D3F8
	cmp r0, r4
	bne _080A7DD2
	movs r0, 0x22
_080A7DD0:
	strh r0, [r7]
_080A7DD2:
	adds r0, r6, 0
_080A7DD4:
	add sp, 0x10
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_80A7B94

	thumb_func_start sub_80A7DDC
sub_80A7DDC:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0x24
	adds r7, r0, 0
	adds r5, r1, 0
	bl sub_80A7B94
	lsls r0, 16
	asrs r0, 16
	mov r8, r0
	movs r0, 0
	strh r0, [r5]
	ldrh r3, [r7]
	movs r1, 0
	ldrsh r0, [r7, r1]
	movs r6, 0x1
	negs r6, r6
	cmp r0, r6
	bne _080A7E0A
_080A7E04:
	movs r0, 0x1
	negs r0, r0
	b _080A8098
_080A7E0A:
	movs r0, 0
	ldrsh r2, [r7, r0]
	lsls r0, r2, 1
	adds r0, r2
	lsls r0, 2
	ldr r1, _080A7E50
	adds r4, r0, r1
	movs r1, 0
	ldrsh r0, [r4, r1]
	cmp r0, 0x3
	beq _080A7E22
	b _080A7F38
_080A7E22:
	adds r0, r3, 0
	subs r0, 0xA
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0x3
	bhi _080A7E90
	adds r4, r2, 0
	subs r4, 0xA
	bl sub_8098F88
	lsls r0, 24
	cmp r0, 0
	beq _080A7E58
	ldr r0, _080A7E54
	lsls r1, r4, 1
	adds r1, r0
	ldrh r0, [r1]
	strh r0, [r5]
	cmp r0, 0
	bne _080A7E04
	strh r6, [r7]
	b _080A7E04
	.align 2, 0
_080A7E50: .4byte gUnknown_811E63C
_080A7E54: .4byte gUnknown_81180F0
_080A7E58:
	movs r0, 0x9
	bl sub_80023E4
	lsls r0, 24
	cmp r0, 0
	beq _080A7E6C
	mov r0, sp
	bl sub_808D6A4
	b _080A7E72
_080A7E6C:
	mov r0, sp
	bl sub_808D654
_080A7E72:
	cmp r4, r0
	blt _080A7E78
	b _080A8080
_080A7E78:
	ldr r2, _080A7E8C
	lsls r0, r4, 2
	add r0, sp
	ldr r1, [r0]
	movs r0, 0x58
	muls r1, r0
	ldr r0, [r2]
	adds r0, r1
	ldrh r0, [r0, 0x8]
	b _080A800A
	.align 2, 0
_080A7E8C: .4byte gUnknown_203B45C
_080A7E90:
	adds r0, r3, 0
	subs r0, 0xE
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0xF
	bls _080A7E9E
	b _080A8080
_080A7E9E:
	movs r0, 0
	movs r1, 0x10
	bl sub_8001658
	lsls r0, 16
	asrs r0, 16
	bl sub_8002658
	lsls r0, 24
	lsrs r1, r0, 24
	cmp r1, 0
	bne _080A7EB8
	b _080A8080
_080A7EB8:
	movs r2, 0
	ldrsh r0, [r7, r2]
	adds r4, r0, 0
	subs r4, 0xE
	adds r0, r1, 0
	mov r1, sp
	movs r2, 0
	movs r3, 0
	bl sub_8092638
	mov r0, sp
	movs r1, 0
	ldrsh r0, [r0, r1]
	cmp r4, r0
	blt _080A7ED8
	b _080A8080
_080A7ED8:
	ldr r2, _080A7F0C
	ldr r0, [sp, 0x8]
	adds r0, r4
	movs r1, 0x58
	muls r1, r0
	ldr r0, [r2]
	adds r4, r0, r1
	movs r0, 0x9
	bl sub_80023E4
	lsls r0, 24
	cmp r0, 0
	beq _080A7F10
	ldrb r1, [r4]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	bne _080A7EFE
	b _080A8080
_080A7EFE:
	ldrb r0, [r4, 0x2]
	cmp r0, 0
	beq _080A7F06
	b _080A8080
_080A7F06:
	ldrh r0, [r4, 0x8]
	b _080A800A
	.align 2, 0
_080A7F0C: .4byte gUnknown_203B45C
_080A7F10:
	ldrb r1, [r4]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	bne _080A7F1C
	b _080A8080
_080A7F1C:
	ldrb r0, [r4, 0x2]
	cmp r0, 0
	beq _080A7F24
	b _080A8080
_080A7F24:
	movs r1, 0
	ldrb r0, [r4, 0x4]
	cmp r0, 0x41
	bne _080A7F2E
	movs r1, 0x1
_080A7F2E:
	cmp r1, 0
	beq _080A7F34
	b _080A8080
_080A7F34:
	ldrh r0, [r4, 0x8]
	b _080A800A
_080A7F38:
	subs r0, r3, 0x1
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x23
	bls _080A7F44
	b _080A808A
_080A7F44:
	lsls r0, 2
	ldr r1, _080A7F50
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080A7F50: .4byte _080A7F54
	.align 2, 0
_080A7F54:
	.4byte _080A7FE4
	.4byte _080A7FEC
	.4byte _080A7FF4
	.4byte _080A808A
	.4byte _080A808A
	.4byte _080A7FE4
	.4byte _080A7FEC
	.4byte _080A7FF4
	.4byte _080A808A
	.4byte _080A808A
	.4byte _080A808A
	.4byte _080A808A
	.4byte _080A808A
	.4byte _080A808A
	.4byte _080A808A
	.4byte _080A808A
	.4byte _080A808A
	.4byte _080A808A
	.4byte _080A808A
	.4byte _080A808A
	.4byte _080A808A
	.4byte _080A808A
	.4byte _080A808A
	.4byte _080A808A
	.4byte _080A808A
	.4byte _080A808A
	.4byte _080A808A
	.4byte _080A808A
	.4byte _080A808A
	.4byte _080A8032
	.4byte _080A8032
	.4byte _080A8014
	.4byte _080A7FE4
	.4byte _080A7FEC
	.4byte _080A7FF4
	.4byte _080A7FFC
_080A7FE4:
	bl sub_808D3BC
	ldrh r0, [r0, 0x8]
	b _080A8094
_080A7FEC:
	bl sub_808D3F8
	ldrh r0, [r0, 0x8]
	b _080A8094
_080A7FF4:
	bl sub_808D33C
	ldrh r0, [r0, 0x8]
	b _080A8094
_080A7FFC:
	movs r0, 0xF
	bl RandomCapped
	ldr r1, _080A8010
	lsls r0, 1
	adds r0, r1
	ldrh r0, [r0]
_080A800A:
	strh r0, [r5]
	b _080A7E04
	.align 2, 0
_080A8010: .4byte gUnknown_81180FC
_080A8014:
	movs r0, 0
	movs r1, 0x1F
	bl sub_8001658
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0
	beq _080A8028
	strh r0, [r5]
	b _080A7E04
_080A8028:
	movs r1, 0x1
	negs r1, r1
	adds r0, r1, 0
	strh r0, [r7]
	b _080A7E04
_080A8032:
	movs r0, 0x89
	strh r0, [r5]
	add r6, sp, 0x10
	adds r0, r6, 0
	bl sub_8099328
	lsls r0, 24
	cmp r0, 0
	bne _080A8046
	b _080A7E04
_080A8046:
	add r1, sp, 0x14
	add r2, sp, 0x18
	movs r0, 0x2
	bl sub_8001B88
	add r4, sp, 0x1C
	ldr r1, [sp, 0x18]
	lsls r1, 24
	lsrs r1, 24
	ldrb r2, [r6]
	adds r0, r4, 0
	bl sub_8096AF8
	ldrb r0, [r4]
	cmp r0, 0
	beq _080A8076
	movs r2, 0
	ldrsh r0, [r7, r2]
	cmp r0, 0x1E
	bne _080A8072
	ldrh r0, [r4, 0x2]
	b _080A8074
_080A8072:
	ldrh r0, [r4, 0x4]
_080A8074:
	strh r0, [r5]
_080A8076:
	movs r1, 0
	ldrsh r0, [r5, r1]
	cmp r0, 0
	beq _080A8080
	b _080A7E04
_080A8080:
	movs r2, 0x1
	negs r2, r2
	adds r0, r2, 0
	strh r0, [r7]
	b _080A7E04
_080A808A:
	movs r1, 0
	ldrsh r0, [r5, r1]
	cmp r0, 0
	bne _080A8096
	ldrh r0, [r4, 0x2]
_080A8094:
	strh r0, [r5]
_080A8096:
	mov r0, r8
_080A8098:
	add sp, 0x24
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_80A7DDC

	thumb_func_start GroundLives_Add
GroundLives_Add:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x24
	str r1, [sp, 0x10]
	lsls r0, 16
	asrs r6, r0, 16
	lsls r2, 16
	asrs r2, 16
	str r2, [sp, 0x14]
	lsls r3, 24
	asrs r3, 24
	str r3, [sp, 0x18]
	ldrb r1, [r1]
	add r0, sp, 0xC
	strh r1, [r0]
	movs r0, 0
	mov r8, r0
	mov r4, sp
	adds r4, 0xE
	add r0, sp, 0xC
	adds r1, r4, 0
	bl sub_80A7DDC
	lsls r0, 16
	asrs r7, r0, 16
	add r0, sp, 0xC
	movs r2, 0
	ldrsh r1, [r0, r2]
	movs r0, 0x1
	negs r0, r0
	mov r9, r4
	cmp r1, r0
	beq _080A81AE
	cmp r7, 0x1
	beq _080A8104
	cmp r7, 0x1
	bgt _080A80FA
	cmp r7, 0
	beq _080A8100
	b _080A8118
_080A80FA:
	cmp r7, 0x2
	beq _080A8108
	b _080A8118
_080A8100:
	movs r6, 0
	b _080A8118
_080A8104:
	movs r6, 0x1
	b _080A8118
_080A8108:
	movs r0, 0
	movs r1, 0x1D
	bl sub_8001658
	cmp r0, 0
	bne _080A8116
	movs r7, 0x1
_080A8116:
	movs r6, 0x2
_080A8118:
	add r0, sp, 0xC
	movs r3, 0
	ldrsh r2, [r0, r3]
	lsls r0, r2, 1
	adds r0, r2
	lsls r0, 2
	ldr r1, _080A813C
	adds r0, r1
	str r0, [sp, 0x1C]
	cmp r6, 0
	bge _080A81B4
	cmp r2, 0x21
	beq _080A8140
	cmp r2, 0x23
	beq _080A8154
	adds r0, r2, 0
	b _080A8162
	.align 2, 0
_080A813C: .4byte gUnknown_811E63C
_080A8140:
	ldr r0, _080A8150
	ldr r0, [r0]
	movs r4, 0x2
	ldrsh r0, [r0, r4]
	cmp r0, 0x1
	beq _080A81AE
	movs r0, 0x21
	b _080A8162
	.align 2, 0
_080A8150: .4byte gUnknown_3001B84
_080A8154:
	ldr r0, _080A8188
	ldr r0, [r0]
	movs r1, 0x2
	ldrsh r0, [r0, r1]
	cmp r0, 0x3
	beq _080A81AE
	movs r0, 0x23
_080A8162:
	bl sub_80A7AE8
	adds r6, r0, 0
	cmp r6, 0
	bge _080A81B4
	movs r2, 0x3
	ldr r0, _080A8188
	ldr r0, [r0]
	movs r3, 0xBA
	lsls r3, 3
	adds r5, r0, r3
	movs r4, 0x2
	ldrsh r1, [r5, r4]
	movs r0, 0x1
	negs r0, r0
	cmp r1, r0
	bne _080A818C
	movs r6, 0x3
	b _080A81B4
	.align 2, 0
_080A8188: .4byte gUnknown_3001B84
_080A818C:
	adds r0, r2, 0x1
	lsls r0, 16
	asrs r2, r0, 16
	movs r0, 0xF8
	lsls r0, 1
	adds r5, r0
	cmp r2, 0x17
	bgt _080A81AA
	movs r3, 0x2
	ldrsh r1, [r5, r3]
	movs r0, 0x1
	negs r0, r0
	cmp r1, r0
	bne _080A818C
	adds r6, r2, 0
_080A81AA:
	cmp r6, 0
	bge _080A81B4
_080A81AE:
	movs r0, 0x1
	negs r0, r0
	b _080A8674
_080A81B4:
	ldr r1, _080A8234
	lsls r0, r6, 5
	subs r0, r6
	lsls r0, 4
	ldr r1, [r1]
	adds r5, r1, r0
	ldr r1, _080A8238
	add r0, sp, 0xC
	movs r4, 0
	ldrsh r3, [r0, r4]
	ldr r2, [sp, 0x1C]
	movs r4, 0
	ldrsh r0, [r2, r4]
	str r0, [sp]
	ldr r0, [sp, 0x14]
	str r0, [sp, 0x4]
	ldr r2, [sp, 0x18]
	str r2, [sp, 0x8]
	movs r0, 0
	adds r2, r6, 0
	bl Log
	movs r2, 0
	movs r3, 0x2
	ldrsh r1, [r5, r3]
	movs r0, 0x1
	negs r0, r0
	cmp r1, r0
	bne _080A81F0
	movs r2, 0x1
_080A81F0:
	str r2, [sp, 0x20]
	strh r6, [r5]
	add r0, sp, 0xC
	ldrh r0, [r0]
	strh r0, [r5, 0x2]
	mov r4, sp
	ldrh r4, [r4, 0x14]
	strh r4, [r5, 0x4]
	mov r0, sp
	ldrb r0, [r0, 0x18]
	strb r0, [r5, 0x6]
	mov r1, r9
	ldrh r0, [r1]
	strh r0, [r5, 0x8]
	movs r2, 0x90
	lsls r2, 1
	adds r4, r5, r2
	adds r0, r4, 0
	bl sub_809CD68
	movs r0, 0x9
	str r0, [r4]
	ldr r3, [sp, 0x1C]
	ldrh r0, [r3]
	subs r0, 0x1
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x9
	bhi _080A82D8
	lsls r0, 2
	ldr r1, _080A823C
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080A8234: .4byte gUnknown_3001B84
_080A8238: .4byte gUnknown_811811C
_080A823C: .4byte _080A8240
	.align 2, 0
_080A8240:
	.4byte _080A8268
	.4byte _080A8280
	.4byte _080A8290
	.4byte _080A82D8
	.4byte _080A82D8
	.4byte _080A8298
	.4byte _080A82A8
	.4byte _080A82B4
	.4byte _080A82BE
	.4byte _080A82CA
_080A8268:
	movs r4, 0x8E
	lsls r4, 1
	adds r1, r5, r4
	ldr r0, _080A827C
	str r0, [r1]
	movs r0, 0x90
	lsls r0, 1
	adds r1, r5, r0
	movs r0, 0x1
	b _080A82E0
	.align 2, 0
_080A827C: .4byte 0x2300181d
_080A8280:
	movs r2, 0x8E
	lsls r2, 1
	adds r1, r5, r2
	ldr r0, _080A828C
	b _080A82E0
	.align 2, 0
_080A828C: .4byte 0x23001000
_080A8290:
	movs r3, 0x8E
	lsls r3, 1
	adds r1, r5, r3
	b _080A82DE
_080A8298:
	movs r4, 0x8E
	lsls r4, 1
	adds r1, r5, r4
	ldr r0, _080A82A4
	b _080A82E0
	.align 2, 0
_080A82A4: .4byte 0x2000000d
_080A82A8:
	movs r0, 0x8E
	lsls r0, 1
	adds r1, r5, r0
	movs r0, 0x80
	lsls r0, 10
	b _080A82E0
_080A82B4:
	movs r2, 0x8E
	lsls r2, 1
	adds r1, r5, r2
	movs r0, 0
	b _080A82E0
_080A82BE:
	movs r3, 0x8E
	lsls r3, 1
	adds r1, r5, r3
	movs r0, 0xC0
	lsls r0, 12
	b _080A82E0
_080A82CA:
	movs r4, 0x8E
	lsls r4, 1
	adds r1, r5, r4
	ldr r0, _080A82D4
	b _080A82E0
	.align 2, 0
_080A82D4: .4byte 0x20010000
_080A82D8:
	movs r0, 0x8E
	lsls r0, 1
	adds r1, r5, r0
_080A82DE:
	ldr r0, _080A83DC
_080A82E0:
	str r0, [r1]
	ldr r2, [sp, 0x1C]
	ldrb r1, [r2, 0x8]
	lsls r1, 11
	str r1, [r5, 0xC]
	ldrb r0, [r2, 0x9]
	lsls r0, 11
	str r0, [r5, 0x10]
	lsrs r1, 1
	str r1, [r5, 0x14]
	lsrs r0, 1
	str r0, [r5, 0x18]
	ldr r3, [sp, 0x10]
	ldrb r0, [r3, 0x1]
	strb r0, [r5, 0x1C]
	adds r2, r3, 0
	adds r2, 0x4
	adds r4, r5, 0
	adds r4, 0x20
	ldrb r1, [r2, 0x2]
	movs r0, 0x4
	ands r0, r1
	cmp r0, 0
	bne _080A8328
	ldrb r0, [r3, 0x4]
	lsls r3, r0, 11
	str r3, [r5, 0x20]
	ldrb r1, [r2, 0x2]
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	beq _080A8328
	movs r1, 0x80
	lsls r1, 3
	adds r0, r3, r1
	str r0, [r5, 0x20]
_080A8328:
	ldrb r1, [r2, 0x3]
	movs r0, 0x4
	ands r0, r1
	cmp r0, 0
	bne _080A834A
	ldrb r0, [r2, 0x1]
	lsls r3, r0, 11
	str r3, [r4, 0x4]
	ldrb r1, [r2, 0x3]
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	beq _080A834A
	movs r2, 0x80
	lsls r2, 3
	adds r0, r3, r2
	str r0, [r4, 0x4]
_080A834A:
	ldr r3, [sp, 0x20]
	cmp r3, 0
	beq _080A83EC
	ldrb r0, [r5, 0x1C]
	movs r4, 0xA1
	lsls r4, 1
	adds r1, r5, r4
	movs r3, 0
	strb r0, [r1]
	movs r0, 0xA2
	lsls r0, 1
	adds r2, r5, r0
	ldr r0, [r5, 0x20]
	ldr r1, [r5, 0x14]
	subs r0, r1
	str r0, [r2]
	movs r1, 0xA6
	lsls r1, 1
	adds r2, r5, r1
	ldr r0, [r5, 0x20]
	ldr r1, [r5, 0x14]
	adds r0, r1
	str r0, [r2]
	adds r4, 0x6
	adds r2, r5, r4
	ldr r0, [r5, 0x24]
	ldr r1, [r5, 0x18]
	subs r0, r1
	str r0, [r2]
	movs r0, 0xA8
	lsls r0, 1
	adds r2, r5, r0
	ldr r0, [r5, 0x24]
	ldr r1, [r5, 0x18]
	adds r0, r1
	str r0, [r2]
	movs r2, 0xAA
	lsls r2, 1
	adds r1, r5, r2
	adds r4, 0x10
	adds r0, r5, r4
	str r3, [r0]
	str r3, [r1]
	movs r1, 0x9E
	lsls r1, 1
	adds r0, r5, r1
	strh r7, [r0]
	ldr r1, _080A83E0
	lsls r0, r7, 1
	adds r0, r7
	lsls r0, 2
	ldr r1, [r1]
	adds r1, r0
	movs r0, 0x1
	negs r0, r0
	str r0, [r1, 0x8]
	str r3, [r1]
	str r3, [r1, 0x4]
	ldrh r0, [r5, 0x2]
	subs r0, 0xE
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0xF
	bhi _080A83E4
	movs r0, 0x12
	bl OtherRandomCapped
	movs r2, 0xA0
	lsls r2, 1
	adds r1, r5, r2
	strh r0, [r1]
	b _080A83EC
	.align 2, 0
_080A83DC: .4byte 0x2300068d
_080A83E0: .4byte gUnknown_3001B80
_080A83E4:
	movs r4, 0xA0
	lsls r4, 1
	adds r0, r5, r4
	strh r3, [r0]
_080A83EC:
	movs r1, 0x8E
	lsls r1, 1
	adds r0, r5, r1
	ldr r0, [r0]
	movs r1, 0x80
	lsls r1, 4
	ands r0, r1
	cmp r0, 0
	beq _080A8418
	movs r2, 0xA2
	lsls r2, 1
	adds r1, r5, r2
	movs r3, 0xA6
	lsls r3, 1
	adds r2, r5, r3
	movs r0, 0x20
	bl sub_80ADCA0
	movs r4, 0x9F
	lsls r4, 1
	adds r1, r5, r4
	b _080A8420
_080A8418:
	movs r0, 0x9F
	lsls r0, 1
	adds r1, r5, r0
	ldr r0, _080A849C
_080A8420:
	strh r0, [r1]
	adds r0, r5, 0
	adds r0, 0x28
	adds r1, r5, 0
	adds r1, 0x30
	bl sub_80A5778
	ldr r1, [sp, 0x20]
	cmp r1, 0
	beq _080A84AC
	ldr r2, _080A84A0
	adds r1, r5, r2
	movs r0, 0xFF
	strb r0, [r1]
	movs r3, 0xAF
	lsls r3, 1
	adds r1, r5, r3
	movs r3, 0
	movs r0, 0xC0
	lsls r0, 2
	strh r0, [r1]
	movs r4, 0xB0
	lsls r4, 1
	adds r1, r5, r4
	movs r2, 0x1
	movs r0, 0x1
	strh r0, [r1]
	movs r1, 0xB2
	lsls r1, 1
	adds r0, r5, r1
	str r3, [r0]
	adds r4, 0x8
	adds r1, r5, r4
	ldr r0, _080A84A4
	strh r0, [r1]
	movs r1, 0xAE
	lsls r1, 1
	adds r0, r5, r1
	strb r2, [r0]
	movs r2, 0xB5
	lsls r2, 1
	adds r0, r5, r2
	strh r3, [r0]
	movs r3, 0xB8
	lsls r3, 1
	adds r0, r5, r3
	movs r4, 0x2
	ldrsh r1, [r5, r4]
	movs r3, 0x8
	ldrsh r2, [r5, r3]
	movs r4, 0x8E
	lsls r4, 1
	adds r3, r5, r4
	ldr r3, [r3]
	bl sub_80A7428
	adds r4, r5, 0
	adds r4, 0x38
	ldr r1, _080A84A8
	ldr r0, [sp, 0x18]
	str r0, [sp]
	b _080A855C
	.align 2, 0
_080A849C: .4byte 0x0000ffff
_080A84A0: .4byte 0x0000015d
_080A84A4: .4byte 0x00000807
_080A84A8: .4byte gUnknown_8117F10
_080A84AC:
	adds r4, r5, 0
	adds r4, 0x38
	ldr r0, _080A84F0
	ldr r1, [r0]
	movs r2, 0xCB
	lsls r2, 2
	adds r1, r2
	adds r0, r4, 0
	bl sub_809D684
	lsls r0, 24
	cmp r0, 0
	beq _080A8550
	adds r0, r5, 0
	adds r0, 0xBE
	movs r3, 0
	ldrsh r0, [r0, r3]
	cmp r0, 0
	beq _080A84F4
	adds r0, r5, 0
	adds r0, 0xE0
	ldrh r0, [r0]
	mov r10, r0
	adds r0, r5, 0
	adds r0, 0xE2
	ldrb r0, [r0]
	lsls r0, 24
	asrs r0, 24
	mov r9, r0
	adds r7, r5, 0
	adds r7, 0x80
	movs r0, 0x82
	adds r0, r5
	b _080A8508
	.align 2, 0
_080A84F0: .4byte gUnknown_3001B80
_080A84F4:
	adds r1, r5, 0
	adds r1, 0x80
	ldrh r2, [r1]
	mov r10, r2
	adds r0, r5, 0
	adds r0, 0x82
	movs r3, 0
	ldrsb r3, [r0, r3]
	mov r9, r3
	adds r7, r1, 0
_080A8508:
	mov r8, r0
	adds r0, r4, 0
	bl sub_809D648
	ldr r1, _080A8544
	ldr r0, [sp, 0x18]
	str r0, [sp]
	adds r0, r4, 0
	adds r2, r5, 0
	ldr r3, [sp, 0x14]
	bl sub_809D600
	ldr r0, _080A8548
	ldr r2, [r0]
	movs r1, 0xCB
	lsls r1, 2
	adds r2, r1
	ldr r3, _080A854C
	adds r0, r4, 0
	movs r1, 0
	bl GroundScript_ExecutePP
	mov r2, r10
	strh r2, [r7]
	mov r0, r9
	mov r3, r8
	strb r0, [r3]
	movs r1, 0x1
	mov r8, r1
	b _080A8566
	.align 2, 0
_080A8544: .4byte gUnknown_8117F10
_080A8548: .4byte gUnknown_3001B80
_080A854C: .4byte gUnknown_8118170
_080A8550:
	adds r0, r4, 0
	bl sub_809D648
	ldr r1, _080A861C
	ldr r2, [sp, 0x18]
	str r2, [sp]
_080A855C:
	adds r0, r4, 0
	adds r2, r5, 0
	ldr r3, [sp, 0x14]
	bl sub_809D600
_080A8566:
	ldr r3, [sp, 0x10]
	ldr r2, [r3, 0xC]
	cmp r2, 0
	bne _080A8574
	ldr r0, _080A8620
	adds r0, 0xEC
	ldr r2, [r0]
_080A8574:
	adds r0, r4, 0
	movs r1, 0x1
	bl sub_809D6D8
	ldr r0, [sp, 0x10]
	ldr r2, [r0, 0x10]
	cmp r2, 0
	bne _080A8588
	ldr r0, _080A8620
	ldr r2, [r0, 0x38]
_080A8588:
	adds r0, r4, 0
	movs r1, 0x2
	bl sub_809D6D8
	ldr r1, [sp, 0x10]
	ldr r2, [r1, 0x14]
	cmp r2, 0
	bne _080A859C
	ldr r0, _080A8620
	ldr r2, [r0, 0x50]
_080A859C:
	adds r0, r4, 0
	movs r1, 0x3
	bl sub_809D6D8
	ldr r3, [sp, 0x10]
	ldr r2, [r3, 0x8]
	cmp r2, 0
	beq _080A8630
	adds r0, r4, 0
	movs r1, 0
	bl sub_809D6D8
	ldr r0, [sp, 0x20]
	cmp r0, 0
	bne _080A860C
	mov r1, r8
	cmp r1, 0
	bne _080A860C
	movs r2, 0x8E
	lsls r2, 1
	adds r0, r5, r2
	ldr r0, [r0]
	movs r1, 0xC0
	lsls r1, 5
	ands r0, r1
	cmp r0, 0
	bne _080A860C
	ldr r0, _080A8624
	ldr r2, [r0]
	movs r3, 0xCB
	lsls r3, 2
	adds r2, r3
	ldr r3, _080A8628
	adds r0, r4, 0
	movs r1, 0
	bl GroundScript_ExecutePP
	movs r1, 0xB0
	lsls r1, 1
	adds r0, r5, r1
	movs r2, 0xAF
	lsls r2, 1
	adds r1, r5, r2
	ldrh r0, [r0]
	ldrh r1, [r1]
	orrs r0, r1
	adds r1, r5, 0
	adds r1, 0x80
	strh r0, [r1]
	movs r3, 0xA1
	lsls r3, 1
	adds r0, r5, r3
	ldrb r1, [r0]
	adds r0, r5, 0
	adds r0, 0x82
	strb r1, [r0]
_080A860C:
	ldr r3, _080A862C
	adds r0, r4, 0
	movs r1, 0
	movs r2, 0
	bl sub_809D8C0
	b _080A865A
	.align 2, 0
_080A861C: .4byte gUnknown_8117F10
_080A8620: .4byte gUnknown_812F1F8
_080A8624: .4byte gUnknown_3001B80
_080A8628: .4byte gUnknown_811817C
_080A862C: .4byte gUnknown_8118188
_080A8630:
	mov r4, r8
	cmp r4, 0
	beq _080A865A
	movs r0, 0xAE
	lsls r0, 1
	adds r1, r5, r0
	movs r0, 0x1
	strb r0, [r1]
	adds r0, r5, 0
	adds r0, 0x82
	ldrb r0, [r0]
	movs r2, 0xA1
	lsls r2, 1
	adds r1, r5, r2
	strb r0, [r1]
	adds r0, r5, 0
	adds r0, 0x80
	ldrh r1, [r0]
	adds r0, r5, 0
	bl sub_80A9750
_080A865A:
	ldr r3, [sp, 0x1C]
	movs r4, 0
	ldrsh r0, [r3, r4]
	cmp r0, 0x1
	bne _080A8672
	ldr r0, [sp, 0x20]
	cmp r0, 0
	beq _080A8672
	movs r0, 0x1
	adds r1, r6, 0
	bl sub_809D170
_080A8672:
	adds r0, r6, 0
_080A8674:
	add sp, 0x24
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end GroundLives_Add

	thumb_func_start GroundLives_Delete
GroundLives_Delete:
	push {r4,lr}
	adds r2, r0, 0
	lsls r2, 16
	asrs r2, 16
	ldr r1, _080A86BC
	lsls r0, r2, 5
	subs r0, r2
	lsls r0, 4
	ldr r1, [r1]
	adds r4, r1, r0
	ldr r1, _080A86C0
	movs r0, 0
	bl Log
	movs r1, 0xB8
	lsls r1, 1
	adds r0, r4, r1
	bl sub_80A74E4
	adds r0, r4, 0
	adds r0, 0x38
	bl sub_809D648
	ldr r0, _080A86C4
	strh r0, [r4, 0x2]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080A86BC: .4byte gUnknown_3001B84
_080A86C0: .4byte gUnknown_8118194
_080A86C4: .4byte 0x0000ffff
	thumb_func_end GroundLives_Delete

	thumb_func_start sub_80A86C8
sub_80A86C8:
	push {r4,r5,lr}
	adds r5, r1, 0
	lsls r0, 16
	asrs r0, 16
	ldr r2, _080A8708
	lsls r1, r0, 5
	subs r1, r0
	lsls r1, 4
	ldr r0, [r2]
	adds r4, r0, r1
	movs r1, 0x2
	ldrsh r0, [r4, r1]
	movs r3, 0x1
	negs r3, r3
	cmp r0, r3
	beq _080A8744
	movs r2, 0x9E
	lsls r2, 1
	adds r1, r4, r2
	movs r2, 0
	ldrsh r0, [r1, r2]
	cmp r0, 0
	bne _080A870C
	movs r0, 0xC0
	lsls r0, 6
	ands r0, r5
	cmp r0, 0
	beq _080A872E
	bl sub_80AB5A4
	b _080A872E
	.align 2, 0
_080A8708: .4byte gUnknown_3001B84
_080A870C:
	movs r0, 0x80
	lsls r0, 5
	ands r0, r5
	cmp r0, 0
	beq _080A872E
	ldr r2, _080A874C
	movs r0, 0
	ldrsh r1, [r1, r0]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 2
	ldr r1, [r2]
	adds r1, r0
	str r3, [r1, 0x8]
	movs r0, 0
	str r0, [r1]
	str r0, [r1, 0x4]
_080A872E:
	movs r1, 0x8E
	lsls r1, 1
	adds r0, r4, r1
	ldr r1, [r0]
	orrs r1, r5
	str r1, [r0]
	movs r2, 0xB8
	lsls r2, 1
	adds r0, r4, r2
	bl sub_80A6688
_080A8744:
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_080A874C: .4byte gUnknown_3001B80
	thumb_func_end sub_80A86C8

	thumb_func_start sub_80A8750
sub_80A8750:
	push {r4,r5,lr}
	adds r5, r1, 0
	lsls r0, 16
	asrs r0, 16
	ldr r2, _080A87A8
	lsls r1, r0, 5
	subs r1, r0
	lsls r1, 4
	ldr r0, [r2]
	adds r4, r0, r1
	movs r0, 0x2
	ldrsh r1, [r4, r0]
	movs r0, 0x1
	negs r0, r0
	cmp r1, r0
	beq _080A87A2
	movs r1, 0x9E
	lsls r1, 1
	adds r0, r4, r1
	movs r2, 0
	ldrsh r0, [r0, r2]
	cmp r0, 0
	bne _080A878C
	movs r0, 0xC0
	lsls r0, 6
	ands r0, r5
	cmp r0, 0
	beq _080A878C
	bl sub_80AB5A4
_080A878C:
	movs r1, 0x8E
	lsls r1, 1
	adds r0, r4, r1
	ldr r1, [r0]
	bics r1, r5
	str r1, [r0]
	movs r2, 0xB8
	lsls r2, 1
	adds r0, r4, r2
	bl sub_80A6688
_080A87A2:
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_080A87A8: .4byte gUnknown_3001B84
	thumb_func_end sub_80A8750

	thumb_func_start sub_80A87AC
sub_80A87AC:
	push {lr}
	adds r3, r1, 0
	lsls r0, 16
	asrs r0, 16
	ldr r2, _080A87DC
	lsls r1, r0, 5
	subs r1, r0
	lsls r1, 4
	ldr r0, [r2]
	adds r2, r0, r1
	movs r0, 0x2
	ldrsh r1, [r2, r0]
	movs r0, 0x1
	negs r0, r0
	cmp r1, r0
	beq _080A87D8
	movs r1, 0x90
	lsls r1, 1
	adds r0, r2, r1
	adds r1, r3, 0
	bl sub_809CD8C
_080A87D8:
	pop {r0}
	bx r0
	.align 2, 0
_080A87DC: .4byte gUnknown_3001B84
	thumb_func_end sub_80A87AC

	thumb_func_start sub_80A87E0
sub_80A87E0:
	push {r4,lr}
	adds r3, r1, 0
	lsls r0, 16
	asrs r0, 16
	ldr r2, _080A8820
	lsls r1, r0, 5
	subs r1, r0
	lsls r1, 4
	ldr r0, [r2]
	adds r4, r0, r1
	movs r0, 0x2
	ldrsh r1, [r4, r0]
	movs r0, 0x1
	negs r0, r0
	cmp r1, r0
	beq _080A8824
	movs r0, 0x7
	movs r1, 0
	adds r2, r3, 0
	bl sub_809B1C0
	lsls r0, 24
	cmp r0, 0
	beq _080A8824
	movs r1, 0x90
	lsls r1, 1
	adds r0, r4, r1
	movs r1, 0x5
	bl sub_809CD8C
	movs r0, 0x1
	b _080A8826
	.align 2, 0
_080A8820: .4byte gUnknown_3001B84
_080A8824:
	movs r0, 0
_080A8826:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_80A87E0

	thumb_func_start sub_80A882C
sub_80A882C:
	push {lr}
	lsls r0, 16
	asrs r0, 16
	ldr r2, _080A8850
	lsls r1, r0, 5
	subs r1, r0
	lsls r1, 4
	ldr r0, [r2]
	adds r2, r0, r1
	movs r0, 0x2
	ldrsh r1, [r2, r0]
	movs r0, 0x1
	negs r0, r0
	cmp r1, r0
	bne _080A8854
	movs r0, 0
	b _080A8858
	.align 2, 0
_080A8850: .4byte gUnknown_3001B84
_080A8854:
	adds r0, r2, 0
	adds r0, 0x38
_080A8858:
	pop {r1}
	bx r1
	thumb_func_end sub_80A882C

	thumb_func_start sub_80A885C
sub_80A885C:
	push {r4,lr}
	adds r4, r1, 0
	lsls r0, 16
	asrs r0, 16
	lsls r2, 16
	asrs r3, r2, 16
	ldr r2, _080A8884
	lsls r1, r0, 5
	subs r1, r0
	lsls r1, 4
	ldr r0, [r2]
	adds r2, r0, r1
	movs r0, 0x2
	ldrsh r1, [r2, r0]
	movs r0, 0x1
	negs r0, r0
	cmp r1, r0
	bne _080A8888
	movs r0, 0
	b _080A8898
	.align 2, 0
_080A8884: .4byte gUnknown_3001B84
_080A8888:
	adds r0, r2, 0
	adds r0, 0x38
	adds r1, r4, 0
	adds r2, r3, 0
	bl sub_809D6E4
	lsls r0, 24
	lsrs r0, 24
_080A8898:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_80A885C

	thumb_func_start sub_80A88A0
sub_80A88A0:
	push {lr}
	lsls r0, 16
	asrs r0, 16
	ldr r2, _080A88C4
	lsls r1, r0, 5
	subs r1, r0
	lsls r1, 4
	ldr r0, [r2]
	adds r2, r0, r1
	movs r0, 0x2
	ldrsh r1, [r2, r0]
	movs r0, 0x1
	negs r0, r0
	cmp r1, r0
	bne _080A88C8
	movs r0, 0
	b _080A88D4
	.align 2, 0
_080A88C4: .4byte gUnknown_3001B84
_080A88C8:
	adds r0, r2, 0
	adds r0, 0x38
	bl sub_809D678
	lsls r0, 24
	lsrs r0, 24
_080A88D4:
	pop {r1}
	bx r1
	thumb_func_end sub_80A88A0

	thumb_func_start GroundLives_ExecuteScript
GroundLives_ExecuteScript:
	push {r4-r7,lr}
	sub sp, 0x4
	adds r4, r0, 0
	adds r7, r1, 0
	adds r6, r2, 0
	lsls r4, 16
	asrs r4, 16
	ldr r1, _080A8914
	lsls r0, r4, 5
	subs r0, r4
	lsls r0, 4
	ldr r1, [r1]
	adds r5, r1, r0
	ldr r1, _080A8918
	movs r0, 0x2
	ldrsh r3, [r5, r0]
	str r6, [sp]
	movs r0, 0
	adds r2, r4, 0
	bl Log
	movs r0, 0x2
	ldrsh r1, [r5, r0]
	movs r0, 0x1
	negs r0, r0
	cmp r1, r0
	bne _080A891C
	movs r0, 0
	b _080A8934
	.align 2, 0
_080A8914: .4byte gUnknown_3001B84
_080A8918: .4byte gUnknown_81181B0
_080A891C:
	adds r0, r5, 0
	adds r0, 0x38
	ldr r3, _080A893C
	adds r1, r7, 0
	adds r2, r6, 0
	bl GroundScript_ExecutePP
	movs r0, 0xAE
	lsls r0, 1
	adds r1, r5, r0
	movs r0, 0x1
	strb r0, [r1]
_080A8934:
	add sp, 0x4
	pop {r4-r7}
	pop {r1}
	bx r1
	.align 2, 0
_080A893C: .4byte gUnknown_81181F4
	thumb_func_end GroundLives_ExecuteScript

	thumb_func_start _ExecutePlayerScript
_ExecutePlayerScript:
	push {r4,r5,lr}
	adds r3, r0, 0
	adds r5, r1, 0
	adds r4, r2, 0
	movs r0, 0xAF
	lsls r0, 1
	adds r1, r3, r0
	movs r2, 0
	movs r0, 0xC0
	lsls r0, 2
	strh r0, [r1]
	movs r0, 0xB0
	lsls r0, 1
	adds r1, r3, r0
	movs r0, 0x1
	strh r0, [r1]
	movs r1, 0xB2
	lsls r1, 1
	adds r0, r3, r1
	str r2, [r0]
	movs r0, 0xB4
	lsls r0, 1
	adds r2, r3, r0
	movs r1, 0
	ldrsh r0, [r2, r1]
	ldr r1, _080A898C
	cmp r0, r1
	beq _080A8984
	strh r1, [r2]
	movs r0, 0xAE
	lsls r0, 1
	adds r1, r3, r0
	movs r0, 0x1
	strb r0, [r1]
_080A8984:
	cmp r4, 0
	bne _080A8990
	movs r0, 0
	b _080A89A2
	.align 2, 0
_080A898C: .4byte 0x00000807
_080A8990:
	adds r0, r3, 0
	adds r0, 0x38
	ldr r3, _080A89A8
	adds r1, r5, 0
	adds r2, r4, 0
	bl GroundScript_ExecutePP
	lsls r0, 24
	lsrs r0, 24
_080A89A2:
	pop {r4,r5}
	pop {r1}
	bx r1
	.align 2, 0
_080A89A8: .4byte gUnknown_8118218
	thumb_func_end _ExecutePlayerScript

	thumb_func_start sub_80A89AC
sub_80A89AC:
	push {r4,lr}
	lsls r0, 16
	asrs r0, 16
	ldr r4, _080A89CC
	lsls r3, r0, 5
	subs r3, r0
	lsls r3, 4
	ldr r0, [r4]
	adds r0, r3
	bl _ExecutePlayerScript
	lsls r0, 24
	lsrs r0, 24
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_080A89CC: .4byte gUnknown_3001B84
	thumb_func_end sub_80A89AC

	thumb_func_start GroundLives_ExecutePlayerScriptActionLives
GroundLives_ExecutePlayerScriptActionLives:
	push {r4-r6,lr}
	sub sp, 0x10
	lsls r0, 16
	asrs r2, r0, 16
	lsls r1, 16
	asrs r4, r1, 16
	cmp r2, 0
	blt _080A8A50
	cmp r4, 0
	blt _080A8A50
	ldr r1, _080A8A48
	lsls r0, r2, 5
	subs r0, r2
	lsls r0, 4
	ldr r1, [r1]
	adds r5, r1, r0
	lsls r0, r4, 5
	subs r0, r4
	lsls r0, 4
	adds r1, r0
	movs r2, 0x2
	ldrsh r0, [r5, r2]
	movs r2, 0x1
	negs r2, r2
	cmp r0, r2
	beq _080A8A50
	movs r3, 0x2
	ldrsh r0, [r1, r3]
	cmp r0, r2
	beq _080A8A50
	adds r6, r1, 0
	adds r6, 0x38
	adds r0, r6, 0
	mov r1, sp
	movs r2, 0x2
	bl sub_809D6E4
	lsls r0, 24
	cmp r0, 0
	beq _080A8A50
	movs r1, 0x1
	lsls r0, r4, 16
	orrs r0, r1
	str r0, [sp, 0xC]
	adds r1, r5, 0
	adds r1, 0x40
	ldr r3, _080A8A4C
	adds r0, r6, 0
	movs r2, 0x3
	bl sub_809D8C0
	add r1, sp, 0xC
	adds r0, r5, 0
	mov r2, sp
	bl _ExecutePlayerScript
	lsls r0, 24
	lsrs r0, 24
	b _080A8A52
	.align 2, 0
_080A8A48: .4byte gUnknown_3001B84
_080A8A4C: .4byte gUnknown_8118250
_080A8A50:
	movs r0, 0
_080A8A52:
	add sp, 0x10
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end GroundLives_ExecutePlayerScriptActionLives

	thumb_func_start sub_80A8A5C
sub_80A8A5C:
	push {r4-r6,lr}
	sub sp, 0x1C
	lsls r0, 16
	asrs r2, r0, 16
	lsls r1, 16
	asrs r5, r1, 16
	cmp r2, 0
	blt _080A8AC0
	cmp r5, 0
	blt _080A8AC0
	ldr r1, _080A8ABC
	lsls r0, r2, 5
	subs r0, r2
	lsls r0, 4
	ldr r1, [r1]
	adds r6, r1, r0
	adds r0, r5, 0
	mov r1, sp
	movs r2, 0x2
	bl sub_80AC274
	lsls r0, 24
	cmp r0, 0
	beq _080A8AC0
	movs r1, 0x2
	lsls r0, r5, 16
	orrs r0, r1
	str r0, [sp, 0x18]
	add r4, sp, 0xC
	adds r0, r5, 0
	adds r1, r4, 0
	movs r2, 0x3
	bl sub_80AC274
	adds r1, r6, 0
	adds r1, 0x40
	adds r0, r5, 0
	adds r2, r4, 0
	bl GroundObject_ExecuteScript
	add r1, sp, 0x18
	adds r0, r6, 0
	mov r2, sp
	bl _ExecutePlayerScript
	lsls r0, 24
	lsrs r0, 24
	b _080A8AC2
	.align 2, 0
_080A8ABC: .4byte gUnknown_3001B84
_080A8AC0:
	movs r0, 0
_080A8AC2:
	add sp, 0x1C
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end sub_80A8A5C

	thumb_func_start sub_80A8ACC
sub_80A8ACC:
	push {r4,lr}
	sub sp, 0xC
	lsls r0, 16
	asrs r2, r0, 16
	lsls r1, 16
	asrs r3, r1, 16
	cmp r2, 0
	blt _080A8B10
	cmp r3, 0
	blt _080A8B10
	ldr r1, _080A8B0C
	lsls r0, r2, 5
	subs r0, r2
	lsls r0, 4
	ldr r1, [r1]
	adds r4, r1, r0
	adds r0, r3, 0
	mov r1, sp
	bl sub_80ADC64
	lsls r0, 24
	cmp r0, 0
	beq _080A8B10
	adds r0, r4, 0
	movs r1, 0
	mov r2, sp
	bl _ExecutePlayerScript
	lsls r0, 24
	lsrs r0, 24
	b _080A8B12
	.align 2, 0
_080A8B0C: .4byte gUnknown_3001B84
_080A8B10:
	movs r0, 0
_080A8B12:
	add sp, 0xC
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_80A8ACC

	thumb_func_start sub_80A8B1C
sub_80A8B1C:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	lsls r0, 16
	asrs r7, r0, 16
	ldr r0, _080A8B70
	ldr r4, [r0]
	movs r5, 0
	movs r0, 0x1
	negs r0, r0
	mov r8, r0
	movs r6, 0x80
	lsls r6, 9
_080A8B36:
	movs r1, 0x2
	ldrsh r0, [r4, r1]
	cmp r0, r8
	beq _080A8B4E
	adds r0, r4, 0
	adds r0, 0x38
	adds r1, r7, 0
	bl sub_809D968
	orrs r5, r0
	lsls r0, r5, 24
	lsrs r5, r0, 24
_080A8B4E:
	adds r0, r6, 0
	movs r1, 0x80
	lsls r1, 9
	adds r6, r1
	asrs r0, 16
	movs r1, 0xF8
	lsls r1, 1
	adds r4, r1
	cmp r0, 0x17
	ble _080A8B36
	adds r0, r5, 0
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r1}
	bx r1
	.align 2, 0
_080A8B70: .4byte gUnknown_3001B84
	thumb_func_end sub_80A8B1C

	thumb_func_start sub_80A8B74
sub_80A8B74:
	push {r4-r7,lr}
	ldr r0, _080A8BB8
	ldr r4, [r0]
	movs r5, 0
	movs r7, 0x1
	negs r7, r7
	movs r6, 0x80
	lsls r6, 9
_080A8B84:
	movs r1, 0x2
	ldrsh r0, [r4, r1]
	cmp r0, r7
	beq _080A8B9A
	adds r0, r4, 0
	adds r0, 0x38
	bl sub_809D92C
	orrs r5, r0
	lsls r0, r5, 24
	lsrs r5, r0, 24
_080A8B9A:
	adds r0, r6, 0
	movs r1, 0x80
	lsls r1, 9
	adds r6, r1
	asrs r0, 16
	movs r1, 0xF8
	lsls r1, 1
	adds r4, r1
	cmp r0, 0x17
	ble _080A8B84
	adds r0, r5, 0
	pop {r4-r7}
	pop {r1}
	bx r1
	.align 2, 0
_080A8BB8: .4byte gUnknown_3001B84
	thumb_func_end sub_80A8B74

	thumb_func_start sub_80A8BBC
sub_80A8BBC:
	lsls r0, 16
	asrs r0, 16
	ldr r2, _080A8BD4
	lsls r1, r0, 5
	subs r1, r0
	lsls r1, 4
	ldr r0, [r2]
	adds r0, r1
	movs r1, 0x2
	ldrsh r0, [r0, r1]
	bx lr
	.align 2, 0
_080A8BD4: .4byte gUnknown_3001B84
	thumb_func_end sub_80A8BBC

	thumb_func_start sub_80A8BD8
sub_80A8BD8:
	lsls r0, 16
	asrs r0, 16
	ldr r3, _080A8BF8
	lsls r2, r0, 5
	subs r2, r0
	lsls r2, 4
	ldr r0, [r3]
	adds r0, r2
	movs r3, 0x8E
	lsls r3, 1
	adds r2, r0, r3
	ldr r2, [r2]
	str r2, [r1]
	movs r1, 0x2
	ldrsh r0, [r0, r1]
	bx lr
	.align 2, 0
_080A8BF8: .4byte gUnknown_3001B84
	thumb_func_end sub_80A8BD8

	thumb_func_start sub_80A8BFC
sub_80A8BFC:
	push {lr}
	lsls r0, 16
	asrs r0, 16
	ldr r2, _080A8C20
	lsls r1, r0, 5
	subs r1, r0
	lsls r1, 4
	ldr r0, [r2]
	adds r2, r0, r1
	movs r0, 0x2
	ldrsh r1, [r2, r0]
	movs r0, 0x1
	negs r0, r0
	cmp r1, r0
	bne _080A8C24
	movs r0, 0
	b _080A8C28
	.align 2, 0
_080A8C20: .4byte gUnknown_3001B84
_080A8C24:
	movs r1, 0x8
	ldrsh r0, [r2, r1]
_080A8C28:
	pop {r1}
	bx r1
	thumb_func_end sub_80A8BFC

	thumb_func_start sub_80A8C2C
sub_80A8C2C:
	push {r4,lr}
	sub sp, 0x4
	mov r1, sp
	strh r0, [r1]
	mov r4, sp
	adds r4, 0x2
	mov r0, sp
	adds r1, r4, 0
	bl sub_80A7DDC
	movs r1, 0
	ldrsh r0, [r4, r1]
	add sp, 0x4
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_80A8C2C

	thumb_func_start sub_80A8C4C
sub_80A8C4C:
	push {r4,r5,lr}
	adds r5, r1, 0
	lsls r0, 16
	asrs r0, 16
	ldr r2, _080A8C80
	lsls r1, r0, 5
	subs r1, r0
	lsls r1, 4
	ldr r0, [r2]
	adds r4, r0, r1
	movs r0, 0x2
	ldrsh r1, [r4, r0]
	movs r0, 0x1
	negs r0, r0
	cmp r1, r0
	beq _080A8C90
	adds r0, r1, 0
	bl sub_80A8D54
	adds r1, r0, 0
	cmp r1, 0
	beq _080A8C84
	ldr r0, [r1, 0x4]
	str r0, [r5]
	b _080A8C8A
	.align 2, 0
_080A8C80: .4byte gUnknown_3001B84
_080A8C84:
	movs r0, 0x63
	strb r0, [r5]
	strb r1, [r5, 0x1]
_080A8C8A:
	movs r1, 0x8
	ldrsh r0, [r4, r1]
	b _080A8C92
_080A8C90:
	movs r0, 0
_080A8C92:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_80A8C4C

	thumb_func_start sub_80A8C98
sub_80A8C98:
	push {r4,lr}
	lsls r0, 16
	asrs r0, 16
	ldr r2, _080A8CD4
	lsls r1, r0, 5
	subs r1, r0
	lsls r1, 4
	ldr r0, [r2]
	adds r3, r0, r1
	movs r0, 0x2
	ldrsh r1, [r3, r0]
	movs r0, 0x1
	negs r0, r0
	cmp r1, r0
	beq _080A8CE8
	ldr r1, _080A8CD8
	ldrh r2, [r1]
	movs r4, 0
	ldrsh r0, [r1, r4]
	cmp r0, 0
	beq _080A8CE8
	movs r0, 0x8
	ldrsh r3, [r3, r0]
_080A8CC6:
	lsls r0, r2, 16
	asrs r0, 16
	cmp r0, r3
	bne _080A8CDC
	movs r0, 0x1
	b _080A8CEA
	.align 2, 0
_080A8CD4: .4byte gUnknown_3001B84
_080A8CD8: .4byte gUnknown_8117FCE
_080A8CDC:
	adds r1, 0x2
	ldrh r2, [r1]
	movs r4, 0
	ldrsh r0, [r1, r4]
	cmp r0, 0
	bne _080A8CC6
_080A8CE8:
	movs r0, 0
_080A8CEA:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_80A8C98

	thumb_func_start sub_80A8CF0
sub_80A8CF0:
	push {r4,lr}
	lsls r0, 16
	asrs r3, r0, 16
	ldr r1, _080A8CFC
	b _080A8D0E
	.align 2, 0
_080A8CFC: .4byte gUnknown_8117FCE
_080A8D00:
	lsls r0, r2, 16
	asrs r0, 16
	cmp r0, r3
	bne _080A8D0C
	movs r0, 0x1
	b _080A8D1A
_080A8D0C:
	adds r1, 0x2
_080A8D0E:
	ldrh r2, [r1]
	movs r4, 0
	ldrsh r0, [r1, r4]
	cmp r0, 0
	bne _080A8D00
	movs r0, 0
_080A8D1A:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_80A8CF0

	thumb_func_start sub_80A8D20
sub_80A8D20:
	push {lr}
	movs r0, 0
	bl sub_80A7AE8
	lsls r0, 16
	asrs r0, 16
	ldr r2, _080A8D50
	lsls r1, r0, 5
	subs r1, r0
	lsls r1, 4
	ldr r0, [r2]
	adds r0, r1
	movs r1, 0x90
	lsls r1, 1
	adds r0, r1
	bl sub_809CDB8
	movs r1, 0
	cmp r0, 0x1
	bne _080A8D4A
	movs r1, 0x1
_080A8D4A:
	adds r0, r1, 0
	pop {r1}
	bx r1
	.align 2, 0
_080A8D50: .4byte gUnknown_3001B84
	thumb_func_end sub_80A8D20

	thumb_func_start sub_80A8D54
sub_80A8D54:
	push {r4,r5,lr}
	sub sp, 0x14
	mov r1, sp
	strh r0, [r1]
	mov r0, sp
	bl sub_80A7B94
	mov r0, sp
	ldrh r1, [r0]
	movs r2, 0
	ldrsh r0, [r0, r2]
	cmp r0, 0x1
	beq _080A8D76
	cmp r0, 0x6
	beq _080A8D76
	cmp r0, 0x21
	bne _080A8D7C
_080A8D76:
	bl sub_808D3BC
	b _080A8E94
_080A8D7C:
	cmp r0, 0x2
	beq _080A8D88
	cmp r0, 0x7
	beq _080A8D88
	cmp r0, 0x22
	bne _080A8D8E
_080A8D88:
	bl sub_808D3F8
	b _080A8E94
_080A8D8E:
	cmp r0, 0x3
	beq _080A8D9A
	cmp r0, 0x8
	beq _080A8D9A
	cmp r0, 0x23
	bne _080A8DA0
_080A8D9A:
	bl sub_808D33C
	b _080A8E94
_080A8DA0:
	adds r0, r1, 0
	subs r0, 0xA
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0x3
	bhi _080A8DF8
	mov r0, sp
	movs r1, 0
	ldrsh r0, [r0, r1]
	adds r5, r0, 0
	subs r5, 0xA
	bl sub_8098F88
	lsls r0, 24
	cmp r0, 0
	bne _080A8E92
	movs r0, 0x9
	bl sub_80023E4
	lsls r0, 24
	cmp r0, 0
	beq _080A8DD6
	add r4, sp, 0x4
	adds r0, r4, 0
	bl sub_808D6A4
	b _080A8DDE
_080A8DD6:
	add r4, sp, 0x4
	adds r0, r4, 0
	bl sub_808D654
_080A8DDE:
	cmp r5, r0
	bge _080A8E92
	ldr r2, _080A8DF4
	lsls r0, r5, 2
	adds r0, r4, r0
	ldr r1, [r0]
	movs r0, 0x58
	muls r1, r0
	ldr r0, [r2]
	adds r0, r1
	b _080A8E94
	.align 2, 0
_080A8DF4: .4byte gUnknown_203B45C
_080A8DF8:
	adds r0, r1, 0
	subs r0, 0xE
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0xF
	bhi _080A8E92
	movs r0, 0
	movs r1, 0x10
	bl sub_8001658
	lsls r0, 16
	asrs r0, 16
	bl sub_8002658
	lsls r0, 24
	lsrs r1, r0, 24
	cmp r1, 0
	beq _080A8E92
	mov r0, sp
	movs r2, 0
	ldrsh r0, [r0, r2]
	adds r5, r0, 0
	subs r5, 0xE
	add r4, sp, 0x4
	adds r0, r1, 0
	adds r1, r4, 0
	movs r2, 0
	movs r3, 0
	bl sub_8092638
	movs r1, 0
	ldrsh r0, [r4, r1]
	cmp r5, r0
	bge _080A8E92
	ldr r2, _080A8E6C
	ldr r0, [r4, 0x8]
	adds r0, r5
	movs r1, 0x58
	muls r1, r0
	ldr r0, [r2]
	adds r4, r0, r1
	movs r0, 0x9
	bl sub_80023E4
	lsls r0, 24
	cmp r0, 0
	beq _080A8E70
	ldrb r1, [r4]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _080A8E92
	ldrb r0, [r4, 0x2]
	cmp r0, 0
	bne _080A8E92
	adds r0, r4, 0
	b _080A8E94
	.align 2, 0
_080A8E6C: .4byte gUnknown_203B45C
_080A8E70:
	ldrb r1, [r4]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _080A8E92
	ldrb r0, [r4, 0x2]
	cmp r0, 0
	bne _080A8E92
	movs r1, 0
	ldrb r0, [r4, 0x4]
	cmp r0, 0x41
	bne _080A8E8A
	movs r1, 0x1
_080A8E8A:
	cmp r1, 0
	bne _080A8E92
	adds r0, r4, 0
	b _080A8E94
_080A8E92:
	movs r0, 0
_080A8E94:
	add sp, 0x14
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_80A8D54

	thumb_func_start sub_80A8E9C
sub_80A8E9C:
	push {lr}
	lsls r0, 16
	asrs r0, 16
	ldr r2, _080A8EBC
	lsls r1, r0, 5
	subs r1, r0
	lsls r1, 4
	ldr r0, [r2]
	adds r0, r1
	movs r1, 0x2
	ldrsh r0, [r0, r1]
	bl sub_80A8D54
	pop {r1}
	bx r1
	.align 2, 0
_080A8EBC: .4byte gUnknown_3001B84
	thumb_func_end sub_80A8E9C

	thumb_func_start sub_80A8EC0
sub_80A8EC0:
	push {r4,r5,lr}
	sub sp, 0x4
	adds r4, r0, 0
	mov r0, sp
	strh r1, [r0]
	mov r5, sp
	adds r5, 0x2
	adds r1, r5, 0
	bl sub_80A7DDC
	mov r0, sp
	movs r1, 0
	ldrsh r0, [r0, r1]
	bl sub_80A8D54
	cmp r0, 0
	beq _080A8EF0
	adds r1, r0, 0
	adds r1, 0x4C
	adds r0, r4, 0
	movs r2, 0xA
	bl sub_80922B4
	b _080A8F44
_080A8EF0:
	mov r0, sp
	movs r2, 0
	ldrsh r1, [r0, r2]
	cmp r1, 0x20
	bne _080A8F00
	movs r0, 0
	ldrsh r1, [r5, r0]
	b _080A8F34
_080A8F00:
	movs r0, 0x1
	negs r0, r0
	cmp r1, r0
	beq _080A8F3C
	mov r0, sp
	movs r1, 0
	ldrsh r2, [r0, r1]
	lsls r0, r2, 1
	adds r0, r2
	lsls r0, 2
	ldr r1, _080A8F2C
	adds r0, r1
	cmp r2, 0x34
	beq _080A8F20
	cmp r2, 0x64
	bne _080A8F30
_080A8F20:
	ldr r1, [r0, 0x4]
	adds r0, r4, 0
	bl strcpy
	b _080A8F44
	.align 2, 0
_080A8F2C: .4byte gUnknown_811E63C
_080A8F30:
	movs r2, 0x2
	ldrsh r1, [r0, r2]
_080A8F34:
	adds r0, r4, 0
	bl sub_808D8BC
	b _080A8F44
_080A8F3C:
	ldr r1, _080A8F4C
	adds r0, r4, 0
	bl strcpy
_080A8F44:
	add sp, 0x4
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_080A8F4C: .4byte gUnknown_811825C
	thumb_func_end sub_80A8EC0

	thumb_func_start sub_80A8F50
sub_80A8F50:
	push {r4,r5,lr}
	sub sp, 0x80
	adds r4, r0, 0
	adds r5, r2, 0
	lsls r1, 16
	asrs r1, 16
	mov r0, sp
	bl sub_80A8EC0
	adds r0, r4, 0
	mov r1, sp
	adds r2, r5, 0
	bl sub_8092310
	add sp, 0x80
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_80A8F50

	thumb_func_start sub_80A8F74
sub_80A8F74:
	push {lr}
	adds r3, r1, 0
	lsls r0, 16
	asrs r0, 16
	ldr r2, _080A8F98
	lsls r1, r0, 5
	subs r1, r0
	lsls r1, 4
	ldr r0, [r2]
	adds r0, r1
	movs r2, 0x2
	ldrsh r1, [r0, r2]
	adds r0, r3, 0
	bl sub_80A8EC0
	pop {r0}
	bx r0
	.align 2, 0
_080A8F98: .4byte gUnknown_3001B84
	thumb_func_end sub_80A8F74

	thumb_func_start sub_80A8F9C
sub_80A8F9C:
	push {lr}
	adds r3, r1, 0
	lsls r0, 16
	asrs r0, 16
	ldr r2, _080A8FC4
	lsls r1, r0, 5
	subs r1, r0
	lsls r1, 4
	ldr r0, [r2]
	adds r2, r0, r1
	movs r0, 0x2
	ldrsh r1, [r2, r0]
	movs r0, 0x1
	negs r0, r0
	cmp r1, r0
	bne _080A8FC8
	movs r0, 0
	str r0, [r3]
	str r0, [r3, 0x4]
	b _080A8FD0
	.align 2, 0
_080A8FC4: .4byte gUnknown_3001B84
_080A8FC8:
	ldr r0, [r2, 0xC]
	ldr r1, [r2, 0x10]
	str r0, [r3]
	str r1, [r3, 0x4]
_080A8FD0:
	movs r1, 0x2
	ldrsh r0, [r2, r1]
	pop {r1}
	bx r1
	thumb_func_end sub_80A8F9C

	thumb_func_start sub_80A8FD8
sub_80A8FD8:
	push {lr}
	adds r3, r1, 0
	lsls r0, 16
	asrs r0, 16
	ldr r2, _080A9000
	lsls r1, r0, 5
	subs r1, r0
	lsls r1, 4
	ldr r0, [r2]
	adds r2, r0, r1
	movs r0, 0x2
	ldrsh r1, [r2, r0]
	movs r0, 0x1
	negs r0, r0
	cmp r1, r0
	bne _080A9004
	movs r0, 0
	str r0, [r3]
	b _080A901E
	.align 2, 0
_080A9000: .4byte gUnknown_3001B84
_080A9004:
	movs r1, 0xA2
	lsls r1, 1
	adds r0, r2, r1
	ldr r0, [r0]
	ldr r1, [r2, 0x14]
	adds r0, r1
	str r0, [r3]
	movs r1, 0xA4
	lsls r1, 1
	adds r0, r2, r1
	ldr r0, [r0]
	ldr r1, [r2, 0x18]
	adds r0, r1
_080A901E:
	str r0, [r3, 0x4]
	movs r1, 0x2
	ldrsh r0, [r2, r1]
	pop {r1}
	bx r1
	thumb_func_end sub_80A8FD8

	thumb_func_start sub_80A9028
sub_80A9028:
	push {r4,lr}
	lsls r0, 16
	asrs r0, 16
	ldr r3, _080A904C
	lsls r2, r0, 5
	subs r2, r0
	lsls r2, 4
	ldr r4, [r3]
	adds r4, r2
	adds r0, r4, 0
	bl sub_80A9F20
	movs r1, 0x2
	ldrsh r0, [r4, r1]
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_080A904C: .4byte gUnknown_3001B84
	thumb_func_end sub_80A9028

	thumb_func_start sub_80A9050
sub_80A9050:
	push {r4,lr}
	adds r4, r1, 0
	lsls r0, 16
	asrs r0, 16
	ldr r2, _080A9078
	lsls r1, r0, 5
	subs r1, r0
	lsls r1, 4
	ldr r0, [r2]
	adds r2, r0, r1
	movs r0, 0x2
	ldrsh r1, [r2, r0]
	movs r0, 0x1
	negs r0, r0
	adds r3, r0, 0
	cmp r1, r0
	bne _080A907C
	strb r3, [r4]
	b _080A9086
	.align 2, 0
_080A9078: .4byte gUnknown_3001B84
_080A907C:
	movs r1, 0xA1
	lsls r1, 1
	adds r0, r2, r1
	ldrb r0, [r0]
	strb r0, [r4]
_080A9086:
	movs r1, 0x2
	ldrsh r0, [r2, r1]
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_80A9050

	thumb_func_start sub_80A9090
sub_80A9090:
	push {lr}
	lsls r0, 16
	asrs r0, 16
	lsls r1, 24
	asrs r3, r1, 24
	ldr r2, _080A90C4
	lsls r1, r0, 5
	subs r1, r0
	lsls r1, 4
	ldr r0, [r2]
	adds r2, r0, r1
	movs r0, 0x2
	ldrsh r1, [r2, r0]
	movs r0, 0x1
	negs r0, r0
	cmp r1, r0
	beq _080A90BA
	movs r1, 0xA1
	lsls r1, 1
	adds r0, r2, r1
	strb r3, [r0]
_080A90BA:
	movs r1, 0x2
	ldrsh r0, [r2, r1]
	pop {r1}
	bx r1
	.align 2, 0
_080A90C4: .4byte gUnknown_3001B84
	thumb_func_end sub_80A9090

	thumb_func_start sub_80A90C8
sub_80A90C8:
	lsls r0, 16
	asrs r0, 16
	ldr r2, _080A90E4
	lsls r1, r0, 5
	subs r1, r0
	lsls r1, 4
	ldr r0, [r2]
	adds r0, r1
	movs r1, 0xA0
	lsls r1, 1
	adds r0, r1
	movs r1, 0
	ldrsh r0, [r0, r1]
	bx lr
	.align 2, 0
_080A90E4: .4byte gUnknown_3001B84
	thumb_func_end sub_80A90C8

	thumb_func_start sub_80A90E8
sub_80A90E8:
	push {r4,r5,lr}
	sub sp, 0x10
	lsls r0, 16
	asrs r2, r0, 16
	lsls r1, 16
	asrs r3, r1, 16
	cmp r2, r3
	beq _080A9196
	ldr r1, _080A916C
	lsls r0, r2, 5
	subs r0, r2
	lsls r0, 4
	ldr r1, [r1]
	adds r5, r1, r0
	lsls r0, r3, 5
	subs r0, r3
	lsls r0, 4
	adds r4, r1, r0
	movs r1, 0x2
	ldrsh r0, [r5, r1]
	movs r1, 0x1
	negs r1, r1
	cmp r0, r1
	beq _080A9196
	movs r2, 0x2
	ldrsh r0, [r4, r2]
	cmp r0, r1
	beq _080A9196
	movs r3, 0xA2
	lsls r3, 1
	adds r0, r5, r3
	ldr r0, [r0]
	ldr r1, [r5, 0x14]
	adds r0, r1
	str r0, [sp]
	movs r2, 0xA4
	lsls r2, 1
	adds r0, r5, r2
	ldr r0, [r0]
	ldr r1, [r5, 0x18]
	adds r0, r1
	str r0, [sp, 0x4]
	adds r3, r4, r3
	ldr r0, [r3]
	ldr r1, [r4, 0x14]
	adds r0, r1
	str r0, [sp, 0x8]
	adds r2, r4, r2
	ldr r0, [r2]
	ldr r1, [r4, 0x18]
	adds r0, r1
	add r2, sp, 0x8
	str r0, [r2, 0x4]
	movs r1, 0x2
	ldrsh r0, [r5, r1]
	cmp r0, 0x24
	bgt _080A9170
	adds r1, r5, 0
	adds r1, 0xC
	adds r3, r4, 0
	adds r3, 0xC
	mov r0, sp
	bl sub_8002DF0
	b _080A917E
	.align 2, 0
_080A916C: .4byte gUnknown_3001B84
_080A9170:
	adds r1, r5, 0
	adds r1, 0xC
	adds r3, r4, 0
	adds r3, 0xC
	mov r0, sp
	bl sub_8002D54
_080A917E:
	lsls r0, 24
	asrs r1, r0, 24
	movs r0, 0x1
	negs r0, r0
	cmp r1, r0
	beq _080A9196
	movs r2, 0xA1
	lsls r2, 1
	adds r0, r5, r2
	strb r1, [r0]
	movs r0, 0x1
	b _080A9198
_080A9196:
	movs r0, 0
_080A9198:
	add sp, 0x10
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_80A90E8

	thumb_func_start sub_80A91A0
sub_80A91A0:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x10
	lsls r0, 16
	asrs r2, r0, 16
	lsls r1, 16
	asrs r4, r1, 16
	cmp r2, r4
	beq _080A928E
	ldr r1, _080A9260
	lsls r0, r2, 5
	subs r0, r2
	lsls r0, 4
	ldr r1, [r1]
	adds r7, r1, r0
	lsls r0, r4, 5
	subs r0, r4
	lsls r0, 4
	adds r1, r0
	mov r8, r1
	movs r1, 0x2
	ldrsh r0, [r7, r1]
	movs r2, 0x1
	negs r2, r2
	mov r10, r2
	cmp r0, r10
	beq _080A928E
	mov r3, r8
	movs r1, 0x2
	ldrsh r0, [r3, r1]
	cmp r0, r10
	beq _080A928E
	movs r3, 0xA2
	lsls r3, 1
	adds r0, r7, r3
	ldr r0, [r0]
	ldr r1, [r7, 0x14]
	adds r0, r1
	str r0, [sp]
	movs r2, 0xA4
	lsls r2, 1
	adds r0, r7, r2
	ldr r0, [r0]
	ldr r1, [r7, 0x18]
	adds r0, r1
	str r0, [sp, 0x4]
	add r3, r8
	ldr r0, [r3]
	mov r3, r8
	ldr r1, [r3, 0x14]
	adds r0, r1
	str r0, [sp, 0x8]
	add r2, r8
	ldr r0, [r2]
	ldr r1, [r3, 0x18]
	adds r0, r1
	add r4, sp, 0x8
	str r0, [r4, 0x4]
	adds r5, r7, 0
	adds r5, 0xC
	mov r6, r8
	adds r6, 0xC
	mov r0, sp
	adds r1, r5, 0
	adds r2, r4, 0
	adds r3, r6, 0
	bl sub_8002DF0
	lsls r0, 24
	asrs r0, 24
	mov r9, r0
	mov r0, sp
	adds r1, r5, 0
	adds r2, r4, 0
	adds r3, r6, 0
	bl sub_8002D54
	lsls r0, 24
	asrs r1, r0, 24
	cmp r9, r10
	beq _080A928E
	cmp r1, r10
	beq _080A928E
	movs r2, 0x2
	ldrsh r0, [r7, r2]
	cmp r0, 0x24
	bgt _080A9264
	movs r3, 0xA1
	lsls r3, 1
	adds r0, r7, r3
	mov r2, r9
	strb r2, [r0]
	b _080A926C
	.align 2, 0
_080A9260: .4byte gUnknown_3001B84
_080A9264:
	movs r3, 0xA1
	lsls r3, 1
	adds r0, r7, r3
	strb r1, [r0]
_080A926C:
	mov r2, r8
	movs r3, 0x2
	ldrsh r0, [r2, r3]
	cmp r0, 0x25
	bgt _080A927A
	mov r0, r9
	b _080A927C
_080A927A:
	adds r0, r1, 0
_080A927C:
	movs r1, 0x5
	bl sub_8002984
	movs r1, 0xA1
	lsls r1, 1
	add r1, r8
	strb r0, [r1]
	movs r0, 0x1
	b _080A9290
_080A928E:
	movs r0, 0
_080A9290:
	add sp, 0x10
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_80A91A0

	thumb_func_start sub_80A92A0
sub_80A92A0:
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	mov r9, r1
	adds r4, r2, 0
	lsls r0, 16
	asrs r6, r0, 16
	ldr r0, _080A931C
	ldr r0, [r0]
	mov r12, r0
	movs r2, 0
	movs r0, 0x1
	negs r0, r0
	mov r8, r0
	movs r5, 0x80
	lsls r5, 9
_080A92C2:
	cmp r2, r6
	beq _080A9320
	mov r1, r12
	movs r7, 0x2
	ldrsh r0, [r1, r7]
	cmp r0, r8
	beq _080A9320
	movs r0, 0x8E
	lsls r0, 1
	add r0, r12
	ldr r0, [r0]
	mov r1, r9
	ands r0, r1
	cmp r0, 0
	beq _080A9320
	movs r0, 0xA2
	lsls r0, 1
	add r0, r12
	ldr r1, [r0]
	ldr r0, [r3]
	cmp r1, r0
	bge _080A9320
	movs r0, 0xA6
	lsls r0, 1
	add r0, r12
	ldr r1, [r0]
	ldr r0, [r4]
	cmp r1, r0
	ble _080A9320
	movs r0, 0xA4
	lsls r0, 1
	add r0, r12
	ldr r1, [r0]
	ldr r0, [r3, 0x4]
	cmp r1, r0
	bge _080A9320
	movs r0, 0xA8
	lsls r0, 1
	add r0, r12
	ldr r1, [r0]
	ldr r0, [r4, 0x4]
	cmp r1, r0
	ble _080A9320
	adds r0, r2, 0
	b _080A9338
	.align 2, 0
_080A931C: .4byte gUnknown_3001B84
_080A9320:
	adds r0, r5, 0
	movs r7, 0x80
	lsls r7, 9
	adds r5, r7
	asrs r2, r0, 16
	movs r0, 0xF8
	lsls r0, 1
	add r12, r0
	cmp r2, 0x17
	ble _080A92C2
	movs r0, 0x1
	negs r0, r0
_080A9338:
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_80A92A0

	thumb_func_start sub_80A9344
sub_80A9344:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x4
	mov r9, r1
	str r2, [sp]
	adds r5, r3, 0
	lsls r0, 16
	asrs r0, 16
	mov r8, r0
	ldr r0, _080A93C4
	ldr r0, [r0]
	mov r12, r0
	movs r4, 0
	movs r0, 0x1
	negs r0, r0
	mov r10, r0
	movs r7, 0x80
	lsls r7, 9
_080A936E:
	cmp r4, r8
	beq _080A93C8
	mov r1, r12
	movs r2, 0x2
	ldrsh r0, [r1, r2]
	cmp r0, r10
	beq _080A93C8
	movs r0, 0x8E
	lsls r0, 1
	add r0, r12
	ldr r0, [r0]
	mov r6, r9
	ands r0, r6
	cmp r0, 0
	beq _080A93C8
	movs r0, 0xA2
	lsls r0, 1
	add r0, r12
	ldr r1, [r0]
	mov r6, r12
	ldr r0, [r6, 0x14]
	adds r2, r1, r0
	movs r0, 0xA4
	lsls r0, 1
	add r0, r12
	ldr r1, [r0]
	ldr r0, [r6, 0x18]
	adds r3, r1, r0
	ldr r0, [r5]
	cmp r2, r0
	bge _080A93C8
	ldr r1, [sp]
	ldr r0, [r1]
	cmp r2, r0
	ble _080A93C8
	ldr r0, [r5, 0x4]
	cmp r3, r0
	bge _080A93C8
	ldr r0, [r1, 0x4]
	cmp r3, r0
	ble _080A93C8
	adds r0, r4, 0
	b _080A93E0
	.align 2, 0
_080A93C4: .4byte gUnknown_3001B84
_080A93C8:
	adds r0, r7, 0
	movs r2, 0x80
	lsls r2, 9
	adds r7, r2
	asrs r4, r0, 16
	movs r6, 0xF8
	lsls r6, 1
	add r12, r6
	cmp r4, 0x17
	ble _080A936E
	movs r0, 0x1
	negs r0, r0
_080A93E0:
	add sp, 0x4
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_80A9344

	thumb_func_start sub_80A93F0
sub_80A93F0:
	push {r4-r7,lr}
	sub sp, 0x10
	lsls r0, 16
	asrs r0, 16
	lsls r1, 24
	lsrs r6, r1, 24
	ldr r2, _080A947C
	lsls r1, r0, 5
	subs r1, r0
	lsls r1, 4
	ldr r0, [r2]
	adds r0, r1
	mov r12, r0
	movs r0, 0xA2
	lsls r0, 1
	add r0, r12
	ldr r0, [r0]
	cmp r0, 0
	bge _080A941A
	ldr r1, _080A9480
	adds r0, r1
_080A941A:
	asrs r5, r0, 11
	str r5, [sp]
	movs r0, 0xA4
	lsls r0, 1
	add r0, r12
	ldr r0, [r0]
	cmp r0, 0
	bge _080A942E
	ldr r7, _080A9480
	adds r0, r7
_080A942E:
	asrs r4, r0, 11
	str r4, [sp, 0x4]
	movs r0, 0xA6
	lsls r0, 1
	add r0, r12
	ldr r0, [r0]
	subs r1, r0, 0x1
	cmp r1, 0
	bge _080A9444
	ldr r7, _080A9484
	adds r1, r0, r7
_080A9444:
	asrs r2, r1, 11
	movs r0, 0xA8
	lsls r0, 1
	add r0, r12
	ldr r0, [r0]
	subs r1, r0, 0x1
	cmp r1, 0
	bge _080A9458
	ldr r7, _080A9484
	adds r1, r0, r7
_080A9458:
	asrs r3, r1, 11
	subs r0, r2, r5
	adds r0, 0x1
	str r0, [sp, 0x8]
	subs r0, r3, r4
	adds r0, 0x1
	add r2, sp, 0x8
	str r0, [r2, 0x4]
	adds r0, r6, 0
	mov r1, sp
	bl sub_80A5934
	lsls r0, 24
	lsrs r0, 24
	add sp, 0x10
	pop {r4-r7}
	pop {r1}
	bx r1
	.align 2, 0
_080A947C: .4byte gUnknown_3001B84
_080A9480: .4byte 0x000007ff
_080A9484: .4byte 0x000007fe
	thumb_func_end sub_80A93F0

	thumb_func_start sub_80A9488
sub_80A9488:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0x10
	adds r5, r0, 0
	adds r7, r1, 0
	mov r8, r2
	ldr r0, [r7]
	cmp r0, 0
	bge _080A94A0
	ldr r1, _080A9528
	adds r0, r1
_080A94A0:
	asrs r0, 11
	mov r12, r0
	str r0, [sp]
	ldr r0, [r7, 0x4]
	cmp r0, 0
	bge _080A94B0
	ldr r3, _080A9528
	adds r0, r3
_080A94B0:
	asrs r4, r0, 11
	str r4, [sp, 0x4]
	mov r6, r8
	ldr r3, [r6]
	subs r0, r3, 0x1
	cmp r0, 0
	bge _080A94C2
	ldr r6, _080A952C
	adds r0, r3, r6
_080A94C2:
	asrs r1, r0, 11
	mov r0, r8
	ldr r3, [r0, 0x4]
	subs r0, r3, 0x1
	cmp r0, 0
	bge _080A94D2
	ldr r6, _080A952C
	adds r0, r3, r6
_080A94D2:
	asrs r2, r0, 11
	mov r3, r12
	subs r0, r1, r3
	adds r0, 0x1
	str r0, [sp, 0x8]
	subs r0, r2, r4
	adds r0, 0x1
	add r2, sp, 0x8
	str r0, [r2, 0x4]
	movs r6, 0x8E
	lsls r6, 1
	adds r0, r5, r6
	ldr r0, [r0]
	movs r1, 0x1
	ands r0, r1
	adds r4, r2, 0
	cmp r0, 0
	beq _080A9504
	mov r0, sp
	adds r1, r4, 0
	bl sub_80A585C
	lsls r0, 24
	cmp r0, 0
	bne _080A9522
_080A9504:
	movs r1, 0x8E
	lsls r1, 1
	adds r0, r5, r1
	ldr r0, [r0]
	movs r1, 0x2
	ands r0, r1
	cmp r0, 0
	beq _080A9530
	mov r0, sp
	adds r1, r4, 0
	bl sub_80A58C8
	lsls r0, 24
	cmp r0, 0
	beq _080A9530
_080A9522:
	movs r0, 0x1
	b _080A95A0
	.align 2, 0
_080A9528: .4byte 0x000007ff
_080A952C: .4byte 0x000007fe
_080A9530:
	movs r3, 0x8E
	lsls r3, 1
	adds r0, r5, r3
	ldr r0, [r0]
	movs r1, 0x4
	ands r0, r1
	cmp r0, 0
	beq _080A9556
	movs r6, 0
	ldrsh r0, [r5, r6]
	adds r2, r7, 0
	mov r3, r8
	bl sub_80A92A0
	lsls r0, 16
	cmp r0, 0
	blt _080A9556
	movs r0, 0x4
	b _080A95A0
_080A9556:
	movs r1, 0x8E
	lsls r1, 1
	adds r0, r5, r1
	ldr r0, [r0]
	movs r1, 0x8
	ands r0, r1
	cmp r0, 0
	beq _080A957A
	movs r0, 0x4
	adds r1, r7, 0
	mov r2, r8
	bl sub_80AC4C8
	lsls r0, 16
	cmp r0, 0
	blt _080A957A
	movs r0, 0x8
	b _080A95A0
_080A957A:
	movs r3, 0x8E
	lsls r3, 1
	adds r0, r5, r3
	ldr r0, [r0]
	movs r1, 0x10
	ands r0, r1
	cmp r0, 0
	beq _080A959E
	movs r0, 0x40
	adds r1, r7, 0
	mov r2, r8
	bl sub_80ADCA0
	lsls r0, 16
	cmp r0, 0
	blt _080A959E
	movs r0, 0x10
	b _080A95A0
_080A959E:
	movs r0, 0
_080A95A0:
	add sp, 0x10
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_80A9488

	thumb_func_start sub_80A95AC
sub_80A95AC:
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	sub sp, 0x14
	adds r5, r0, 0
	adds r7, r1, 0
	mov r8, r2
	ldr r0, [r7]
	cmp r0, 0
	bge _080A95C6
	ldr r1, _080A96BC
	adds r0, r1
_080A95C6:
	asrs r0, 11
	mov r9, r0
	str r0, [sp]
	ldr r0, [r7, 0x4]
	cmp r0, 0
	bge _080A95D6
	ldr r2, _080A96BC
	adds r0, r2
_080A95D6:
	asrs r4, r0, 11
	str r4, [sp, 0x4]
	mov r6, r8
	ldr r3, [r6]
	subs r0, r3, 0x1
	cmp r0, 0
	bge _080A95E8
	ldr r6, _080A96C0
	adds r0, r3, r6
_080A95E8:
	asrs r1, r0, 11
	mov r0, r8
	ldr r3, [r0, 0x4]
	subs r0, r3, 0x1
	cmp r0, 0
	bge _080A95F8
	ldr r6, _080A96C0
	adds r0, r3, r6
_080A95F8:
	asrs r2, r0, 11
	mov r3, r9
	subs r0, r1, r3
	adds r0, 0x1
	str r0, [sp, 0x8]
	subs r0, r2, r4
	adds r0, 0x1
	add r2, sp, 0x8
	str r0, [r2, 0x4]
	movs r6, 0x8E
	lsls r6, 1
	adds r0, r5, r6
	ldr r0, [r0]
	movs r1, 0x1
	ands r0, r1
	adds r4, r2, 0
	cmp r0, 0
	beq _080A962C
	mov r0, sp
	adds r1, r4, 0
	bl sub_80A585C
	lsls r0, 24
	cmp r0, 0
	beq _080A962C
	b _080A973C
_080A962C:
	movs r1, 0x8E
	lsls r1, 1
	adds r0, r5, r1
	ldr r0, [r0]
	movs r1, 0x2
	ands r0, r1
	cmp r0, 0
	beq _080A964A
	mov r0, sp
	adds r1, r4, 0
	bl sub_80A58C8
	lsls r0, 24
	cmp r0, 0
	bne _080A973C
_080A964A:
	movs r4, 0x8E
	lsls r4, 1
	adds r0, r5, r4
	ldr r0, [r0]
	movs r1, 0x4
	ands r0, r1
	cmp r0, 0
	beq _080A96C8
	movs r2, 0
	ldrsh r0, [r5, r2]
	movs r1, 0x44
	adds r2, r7, 0
	mov r3, r8
	bl sub_80A92A0
	lsls r0, 16
	asrs r2, r0, 16
	mov r9, r2
	cmp r2, 0
	blt _080A96C8
	ldr r1, _080A96C4
	lsls r0, r2, 5
	subs r0, r2
	lsls r0, 4
	ldr r1, [r1]
	adds r6, r1, r0
	adds r0, r6, r4
	ldr r1, [r0]
	movs r0, 0x40
	ands r0, r1
	cmp r0, 0
	beq _080A973C
	movs r0, 0x80
	lsls r0, 2
	ands r1, r0
	cmp r1, 0
	beq _080A96A8
	adds r4, 0x26
	adds r0, r5, r4
	ldrb r0, [r0]
	lsls r0, 24
	asrs r0, 24
	movs r1, 0x5
	bl sub_8002984
	adds r4, r6, r4
	strb r0, [r4]
_080A96A8:
	movs r3, 0
	ldrsh r0, [r5, r3]
	mov r1, r9
	bl GroundLives_ExecutePlayerScriptActionLives
_080A96B2:
	lsls r0, 24
	cmp r0, 0
	bne _080A9738
	b _080A973C
	.align 2, 0
_080A96BC: .4byte 0x000007ff
_080A96C0: .4byte 0x000007fe
_080A96C4: .4byte gUnknown_3001B84
_080A96C8:
	movs r6, 0x8E
	lsls r6, 1
	adds r0, r5, r6
	ldr r0, [r0]
	movs r1, 0x8
	ands r0, r1
	cmp r0, 0
	beq _080A9708
	movs r0, 0x44
	adds r1, r7, 0
	mov r2, r8
	bl sub_80AC4C8
	lsls r0, 16
	asrs r4, r0, 16
	cmp r4, 0
	blt _080A9708
	add r1, sp, 0x10
	adds r0, r4, 0
	bl sub_80AC3E0
	ldr r0, [sp, 0x10]
	movs r1, 0x40
	ands r0, r1
	cmp r0, 0
	beq _080A973C
	movs r1, 0
	ldrsh r0, [r5, r1]
	adds r1, r4, 0
	bl sub_80A8A5C
	b _080A96B2
_080A9708:
	movs r2, 0x8E
	lsls r2, 1
	adds r0, r5, r2
	ldr r0, [r0]
	movs r1, 0x10
	ands r0, r1
	cmp r0, 0
	beq _080A9740
	movs r0, 0x40
	adds r1, r7, 0
	mov r2, r8
	bl sub_80ADCA0
	lsls r0, 16
	asrs r1, r0, 16
	cmp r1, 0
	blt _080A9740
	movs r3, 0
	ldrsh r0, [r5, r3]
	bl sub_80A8ACC
	lsls r0, 24
	cmp r0, 0
	beq _080A973C
_080A9738:
	movs r0, 0x2
	b _080A9742
_080A973C:
	movs r0, 0x1
	b _080A9742
_080A9740:
	movs r0, 0
_080A9742:
	add sp, 0x14
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_80A95AC

	thumb_func_start sub_80A9750
sub_80A9750:
	push {r4,lr}
	mov r12, r0
	lsls r1, 16
	lsrs r1, 16
	adds r4, r1, 0
	movs r3, 0xFF
	ands r3, r1
	movs r2, 0xF0
	lsls r2, 4
	ands r2, r1
	cmp r3, 0
	beq _080A9770
	movs r0, 0xB0
	lsls r0, 1
	add r0, r12
	strh r3, [r0]
_080A9770:
	cmp r2, 0
	beq _080A977C
	movs r0, 0xAF
	lsls r0, 1
	add r0, r12
	strh r2, [r0]
_080A977C:
	movs r2, 0xB0
	lsls r2, 1
	add r2, r12
	ldrh r0, [r2]
	cmp r0, 0x1
	bne _080A97A8
	movs r0, 0x80
	lsls r0, 5
	cmp r1, r0
	beq _080A97B6
	movs r0, 0xB2
	lsls r0, 1
	add r0, r12
	ldr r0, [r0]
	ldr r2, _080A97A4
	cmp r0, 0
	bgt _080A97A0
	b _080A9E98
_080A97A0:
	b _080A97C0
	.align 2, 0
_080A97A4: .4byte 0x00000807
_080A97A8:
	cmp r0, 0x2
	beq _080A97AE
	b _080A9E8C
_080A97AE:
	movs r0, 0x80
	lsls r0, 5
	cmp r4, r0
	bne _080A97C6
_080A97B6:
	movs r1, 0xB2
	lsls r1, 1
	add r1, r12
	movs r0, 0x4
	str r0, [r1]
_080A97C0:
	movs r2, 0x80
	lsls r2, 4
	b _080A9E98
_080A97C6:
	movs r0, 0xB2
	lsls r0, 1
	add r0, r12
	ldr r0, [r0]
	cmp r0, 0
	bgt _080A97C0
	mov r1, r12
	ldrh r0, [r1, 0x8]
	subs r0, 0xC
	lsls r0, 16
	asrs r1, r0, 16
	ldr r0, _080A97F0
	cmp r1, r0
	bls _080A97E4
	b _080A9E7E
_080A97E4:
	lsls r0, r1, 2
	ldr r1, _080A97F4
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080A97F0: .4byte 0x00000197
_080A97F4: .4byte _080A97F8
	.align 2, 0
_080A97F8:
	.4byte _080A9E58
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E58
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E58
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E58
	.4byte _080A9E58
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E58
	.4byte _080A9E60
	.4byte _080A9E60
	.4byte _080A9E7E
	.4byte _080A9E60
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E60
	.4byte _080A9E60
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E68
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E58
	.4byte _080A9E58
	.4byte _080A9E58
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E58
	.4byte _080A9E58
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E58
	.4byte _080A9E58
	.4byte _080A9E58
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E60
	.4byte _080A9E60
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E58
	.4byte _080A9E58
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E58
	.4byte _080A9E58
	.4byte _080A9E58
	.4byte _080A9E58
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E58
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E58
	.4byte _080A9E60
	.4byte _080A9E60
	.4byte _080A9E7E
	.4byte _080A9E58
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E58
	.4byte _080A9E7E
	.4byte _080A9E58
	.4byte _080A9E58
	.4byte _080A9E58
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E58
	.4byte _080A9E58
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E60
	.4byte _080A9E60
	.4byte _080A9E7E
	.4byte _080A9E60
	.4byte _080A9E58
	.4byte _080A9E58
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E58
	.4byte _080A9E58
	.4byte _080A9E58
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E58
	.4byte _080A9E58
	.4byte _080A9E58
	.4byte _080A9E58
	.4byte _080A9E58
	.4byte _080A9E7E
	.4byte _080A9E58
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E58
	.4byte _080A9E7E
	.4byte _080A9E58
	.4byte _080A9E58
	.4byte _080A9E58
	.4byte _080A9E58
	.4byte _080A9E58
	.4byte _080A9E58
	.4byte _080A9E58
	.4byte _080A9E58
	.4byte _080A9E58
	.4byte _080A9E58
	.4byte _080A9E58
	.4byte _080A9E58
	.4byte _080A9E58
	.4byte _080A9E58
	.4byte _080A9E58
	.4byte _080A9E58
	.4byte _080A9E58
	.4byte _080A9E58
	.4byte _080A9E58
	.4byte _080A9E58
	.4byte _080A9E58
	.4byte _080A9E58
	.4byte _080A9E58
	.4byte _080A9E58
	.4byte _080A9E58
	.4byte _080A9E58
	.4byte _080A9E58
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E58
	.4byte _080A9E7E
	.4byte _080A9E58
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E58
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E58
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E58
	.4byte _080A9E60
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E58
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E58
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E58
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E58
	.4byte _080A9E58
	.4byte _080A9E60
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E60
	.4byte _080A9E60
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E58
	.4byte _080A9E7E
	.4byte _080A9E58
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E58
	.4byte _080A9E58
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E58
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E58
	.4byte _080A9E58
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E60
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E60
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E58
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E60
	.4byte _080A9E60
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E58
	.4byte _080A9E58
	.4byte _080A9E58
	.4byte _080A9E58
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E60
	.4byte _080A9E58
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E58
	.4byte _080A9E60
	.4byte _080A9E60
	.4byte _080A9E7E
	.4byte _080A9E58
	.4byte _080A9E58
	.4byte _080A9E58
	.4byte _080A9E58
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E58
	.4byte _080A9E58
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E58
	.4byte _080A9E7E
	.4byte _080A9E58
	.4byte _080A9E58
	.4byte _080A9E58
	.4byte _080A9E58
	.4byte _080A9E7E
	.4byte _080A9E58
	.4byte _080A9E7E
	.4byte _080A9E58
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E58
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E58
	.4byte _080A9E60
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E58
	.4byte _080A9E58
	.4byte _080A9E58
	.4byte _080A9E58
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E60
	.4byte _080A9E58
	.4byte _080A9E58
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E58
	.4byte _080A9E7E
	.4byte _080A9E58
	.4byte _080A9E58
	.4byte _080A9E58
	.4byte _080A9E7E
	.4byte _080A9E58
	.4byte _080A9E58
	.4byte _080A9E58
	.4byte _080A9E58
	.4byte _080A9E58
	.4byte _080A9E58
	.4byte _080A9E58
	.4byte _080A9E58
_080A9E58:
	ldr r2, _080A9E5C
	b _080A9E98
	.align 2, 0
_080A9E5C: .4byte 0x00000807
_080A9E60:
	ldr r2, _080A9E64
	b _080A9E98
	.align 2, 0
_080A9E64: .4byte 0x00000307
_080A9E68:
	movs r0, 0xB4
	lsls r0, 1
	add r0, r12
	movs r2, 0
	ldrsh r1, [r0, r2]
	ldr r2, _080A9E84
	cmp r1, r2
	beq _080A9E98
	ldr r0, _080A9E88
	cmp r1, r0
	beq _080A9E98
_080A9E7E:
	movs r2, 0xC0
	lsls r2, 2
	b _080A9E98
	.align 2, 0
_080A9E84: .4byte 0x00000807
_080A9E88: .4byte 0x00000307
_080A9E8C:
	ldr r1, _080A9EC4
	ldrh r0, [r2]
	lsls r0, 1
	adds r0, r1
	movs r4, 0
	ldrsh r2, [r0, r4]
_080A9E98:
	movs r0, 0xE0
	lsls r0, 3
	ands r0, r2
	cmp r0, 0
	bne _080A9EEE
	movs r0, 0xAF
	lsls r0, 1
	add r0, r12
	ldrh r1, [r0]
	movs r0, 0xC0
	lsls r0, 2
	cmp r1, r0
	beq _080A9EEE
	cmp r1, r0
	bgt _080A9EC8
	movs r3, 0x80
	lsls r3, 1
	cmp r1, r3
	beq _080A9EDA
	movs r0, 0x80
	lsls r0, 2
	b _080A9ED4
	.align 2, 0
_080A9EC4: .4byte gUnknown_8117F64
_080A9EC8:
	movs r3, 0x80
	lsls r3, 3
	cmp r1, r3
	beq _080A9EDE
	movs r0, 0x80
	lsls r0, 4
_080A9ED4:
	cmp r1, r0
	beq _080A9EEC
	b _080A9EEE
_080A9EDA:
	orrs r2, r0
	b _080A9EEE
_080A9EDE:
	movs r1, 0x80
	lsls r1, 2
	adds r0, r1, 0
	orrs r2, r0
	lsls r0, r2, 16
	asrs r2, r0, 16
	b _080A9EEE
_080A9EEC:
	orrs r2, r3
_080A9EEE:
	movs r1, 0xB4
	lsls r1, 1
	add r1, r12
	ldrh r3, [r1]
	movs r4, 0
	ldrsh r0, [r1, r4]
	cmp r0, r2
	beq _080A9F02
	strh r2, [r1]
	b _080A9F0C
_080A9F02:
	movs r0, 0x80
	lsls r0, 5
	ands r0, r3
	cmp r0, 0
	beq _080A9F16
_080A9F0C:
	movs r1, 0xAE
	lsls r1, 1
	add r1, r12
	movs r0, 0x1
	strb r0, [r1]
_080A9F16:
	movs r0, 0
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_80A9750

	thumb_func_start sub_80A9F20
sub_80A9F20:
	push {r4,r5,lr}
	sub sp, 0x10
	adds r5, r0, 0
	ldr r2, [r1]
	ldr r4, [r5, 0x14]
	subs r0, r2, r4
	str r0, [sp]
	ldr r3, [r1, 0x4]
	ldr r1, [r5, 0x18]
	subs r0, r3, r1
	str r0, [sp, 0x4]
	adds r2, r4
	str r2, [sp, 0x8]
	adds r3, r1
	add r2, sp, 0x8
	str r3, [r2, 0x4]
	ldr r1, [r5, 0x28]
	ldr r0, [sp]
	cmp r0, r1
	blt _080A9F5E
	ldr r1, [r5, 0x30]
	ldr r0, [sp, 0x8]
	cmp r0, r1
	bge _080A9F5E
	ldr r1, [r5, 0x2C]
	ldr r0, [sp, 0x4]
	cmp r0, r1
	blt _080A9F5E
	ldr r0, [r5, 0x34]
	cmp r3, r0
	blt _080A9F62
_080A9F5E:
	movs r0, 0x1
	b _080A9F8C
_080A9F62:
	adds r0, r5, 0
	mov r1, sp
	bl sub_80A9488
	cmp r0, 0
	bne _080A9F8C
	movs r0, 0xA2
	lsls r0, 1
	adds r2, r5, r0
	ldr r0, [sp]
	ldr r1, [sp, 0x4]
	str r0, [r2]
	str r1, [r2, 0x4]
	movs r0, 0xA6
	lsls r0, 1
	adds r2, r5, r0
	ldr r0, [sp, 0x8]
	ldr r1, [sp, 0xC]
	str r0, [r2]
	str r1, [r2, 0x4]
	movs r0, 0
_080A9F8C:
	add sp, 0x10
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_80A9F20

	thumb_func_start sub_80A9F94
sub_80A9F94:
	push {r4-r6,lr}
	sub sp, 0x10
	adds r4, r0, 0
	movs r2, 0xA2
	lsls r2, 1
	adds r0, r4, r2
	ldr r0, [r0]
	ldr r2, [r1]
	adds r0, r2
	str r0, [sp]
	movs r3, 0xA4
	lsls r3, 1
	adds r0, r4, r3
	ldr r0, [r0]
	ldr r1, [r1, 0x4]
	adds r0, r1
	str r0, [sp, 0x4]
	adds r3, 0x4
	adds r0, r4, r3
	ldr r0, [r0]
	adds r0, r2
	str r0, [sp, 0x8]
	movs r2, 0xA8
	lsls r2, 1
	adds r0, r4, r2
	ldr r0, [r0]
	adds r0, r1
	add r1, sp, 0x8
	str r0, [r1, 0x4]
	movs r6, 0
	ldr r3, [r4, 0x28]
	ldr r0, [sp]
	adds r2, r1, 0
	cmp r0, r3
	bge _080A9FE4
	str r3, [sp]
	ldr r0, [r4, 0xC]
	adds r0, r3, r0
	str r0, [sp, 0x8]
	b _080A9FF4
_080A9FE4:
	ldr r1, [r4, 0x30]
	ldr r0, [sp, 0x8]
	cmp r0, r1
	blt _080A9FF6
	ldr r0, [r4, 0xC]
	subs r0, r1, r0
	str r0, [sp]
	str r1, [sp, 0x8]
_080A9FF4:
	movs r6, 0x1
_080A9FF6:
	ldr r1, [r4, 0x2C]
	ldr r0, [sp, 0x4]
	cmp r0, r1
	bge _080AA008
	str r1, [sp, 0x4]
	ldr r0, [r4, 0x10]
	adds r0, r1, r0
	str r0, [r2, 0x4]
	b _080AA018
_080AA008:
	ldr r1, [r4, 0x34]
	ldr r0, [r2, 0x4]
	cmp r0, r1
	blt _080AA01A
	ldr r0, [r4, 0x10]
	subs r0, r1, r0
	str r0, [sp, 0x4]
	str r1, [r2, 0x4]
_080AA018:
	movs r6, 0x1
_080AA01A:
	adds r0, r4, 0
	mov r1, sp
	bl sub_80A9488
	adds r5, r0, 0
	cmp r5, 0
	beq _080AA034
	adds r0, r4, 0
	movs r1, 0
	bl sub_80AAF68
	adds r0, r5, 0
	b _080AA06A
_080AA034:
	movs r3, 0xA2
	lsls r3, 1
	adds r2, r4, r3
	ldr r0, [sp]
	ldr r1, [sp, 0x4]
	str r0, [r2]
	str r1, [r2, 0x4]
	movs r0, 0xA6
	lsls r0, 1
	adds r2, r4, r0
	ldr r0, [sp, 0x8]
	ldr r1, [sp, 0xC]
	str r0, [r2]
	str r1, [r2, 0x4]
	cmp r6, 0
	bne _080AA060
	adds r0, r4, 0
	movs r1, 0x1
	bl sub_80AAF68
	movs r0, 0
	b _080AA06A
_080AA060:
	adds r0, r4, 0
	movs r1, 0
	bl sub_80AAF68
	movs r0, 0x1
_080AA06A:
	add sp, 0x10
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end sub_80A9F94

	thumb_func_start sub_80AA074
sub_80AA074:
	push {r4-r7,lr}
	sub sp, 0x10
	adds r4, r0, 0
	movs r2, 0xA2
	lsls r2, 1
	adds r0, r4, r2
	ldr r0, [r0]
	ldr r2, [r1]
	adds r0, r2
	str r0, [sp]
	movs r3, 0xA4
	lsls r3, 1
	adds r0, r4, r3
	ldr r0, [r0]
	ldr r1, [r1, 0x4]
	adds r0, r1
	str r0, [sp, 0x4]
	adds r3, 0x4
	adds r0, r4, r3
	ldr r0, [r0]
	adds r0, r2
	str r0, [sp, 0x8]
	movs r2, 0xA8
	lsls r2, 1
	adds r0, r4, r2
	ldr r0, [r0]
	adds r0, r1
	add r1, sp, 0x8
	str r0, [r1, 0x4]
	ldr r3, [r4, 0x28]
	ldr r0, [sp]
	adds r5, r1, 0
	cmp r0, r3
	bge _080AA0C2
	str r3, [sp]
	ldr r0, [r4, 0xC]
	adds r0, r3, r0
	str r0, [sp, 0x8]
	b _080AA0D2
_080AA0C2:
	ldr r1, [r4, 0x30]
	ldr r0, [sp, 0x8]
	cmp r0, r1
	blt _080AA0D2
	ldr r0, [r4, 0xC]
	subs r0, r1, r0
	str r0, [sp]
	str r1, [sp, 0x8]
_080AA0D2:
	ldr r1, [r4, 0x2C]
	ldr r0, [sp, 0x4]
	cmp r0, r1
	bge _080AA0E4
	str r1, [sp, 0x4]
	ldr r0, [r4, 0x10]
	adds r0, r1, r0
	str r0, [r5, 0x4]
	b _080AA0F4
_080AA0E4:
	ldr r1, [r4, 0x34]
	ldr r0, [r5, 0x4]
	cmp r0, r1
	blt _080AA0F4
	ldr r0, [r4, 0x10]
	subs r0, r1, r0
	str r0, [sp, 0x4]
	str r1, [r5, 0x4]
_080AA0F4:
	adds r0, r4, 0
	mov r1, sp
	adds r2, r5, 0
	bl sub_80A95AC
	adds r6, r0, 0
	cmp r6, 0
	bne _080AA170
	movs r3, 0xA2
	lsls r3, 1
	adds r2, r4, r3
	ldr r0, [sp]
	ldr r1, [sp, 0x4]
	str r0, [r2]
	str r1, [r2, 0x4]
	movs r0, 0xA6
	lsls r0, 1
	adds r2, r4, r0
	ldr r0, [sp, 0x8]
	ldr r1, [sp, 0xC]
	str r0, [r2]
	str r1, [r2, 0x4]
	movs r1, 0x8E
	lsls r1, 1
	adds r0, r4, r1
	ldr r0, [r0]
	movs r1, 0x10
	ands r0, r1
	cmp r0, 0
	beq _080AA170
	movs r0, 0x20
	mov r1, sp
	adds r2, r5, 0
	bl sub_80ADCA0
	lsls r0, 16
	asrs r5, r0, 16
	cmp r5, 0
	blt _080AA166
	movs r2, 0x9F
	lsls r2, 1
	adds r7, r4, r2
	movs r3, 0
	ldrsh r0, [r7, r3]
	cmp r0, r5
	beq _080AA170
	movs r1, 0
	ldrsh r0, [r4, r1]
	adds r1, r5, 0
	bl sub_80A8ACC
	lsls r0, 24
	cmp r0, 0
	beq _080AA170
	strh r5, [r7]
	movs r6, 0x2
	b _080AA170
_080AA166:
	movs r2, 0x9F
	lsls r2, 1
	adds r1, r4, r2
	ldr r0, _080AA17C
	strh r0, [r1]
_080AA170:
	adds r0, r6, 0
	add sp, 0x10
	pop {r4-r7}
	pop {r1}
	bx r1
	.align 2, 0
_080AA17C: .4byte 0x0000ffff
	thumb_func_end sub_80AA074

	thumb_func_start sub_80AA180
sub_80AA180:
	push {r4-r7,lr}
	sub sp, 0x10
	adds r4, r0, 0
	adds r5, r1, 0
	adds r6, r2, 0
	adds r7, r3, 0
	movs r0, 0x4
	ands r0, r5
	cmp r0, 0
	beq _080AA220
	movs r1, 0
	ldrsh r0, [r4, r1]
	movs r1, 0x80
	bl sub_80A9344
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0
	blt _080AA220
	mov r1, sp
	bl sub_80A8FD8
	movs r2, 0xA2
	lsls r2, 1
	adds r0, r4, r2
	ldr r1, [r0]
	ldr r0, [r4, 0x14]
	adds r1, r0
	ldr r0, [sp]
	subs r0, r1
	str r0, [sp, 0x8]
	movs r3, 0xA4
	lsls r3, 1
	adds r0, r4, r3
	ldr r0, [r0]
	ldr r1, [r4, 0x18]
	adds r0, r1
	ldr r1, [sp, 0x4]
	subs r1, r0
	add r0, sp, 0x8
	str r1, [r0, 0x4]
	bl sub_8002C60
	lsls r0, 24
	asrs r1, r0, 24
	movs r0, 0x1
	negs r0, r0
	cmp r1, r0
	beq _080AA2B2
	movs r0, 0xA1
	lsls r0, 1
	adds r2, r4, r0
	lsls r0, r1, 24
	lsrs r0, 24
	strb r0, [r2]
	ldr r3, _080AA21C
	adds r1, r4, r3
	ldrb r1, [r1]
	lsls r1, 24
	asrs r1, 24
	lsls r0, 24
	asrs r0, 24
	cmp r1, r0
	beq _080AA20A
	movs r0, 0xAE
	lsls r0, 1
	adds r1, r4, r0
	movs r0, 0x1
	strb r0, [r1]
_080AA20A:
	movs r1, 0
	ldrsb r1, [r2, r1]
	adds r0, r4, 0
	bl sub_80AA3F8
	lsls r0, 24
	cmp r0, 0
	bne _080AA2AE
	b _080AA2B2
	.align 2, 0
_080AA21C: .4byte 0x0000015d
_080AA220:
	movs r0, 0x8
	ands r0, r5
	cmp r0, 0
	beq _080AA2B2
	movs r0, 0x80
	adds r1, r6, 0
	adds r2, r7, 0
	bl sub_80AC554
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0
	blt _080AA2B2
	mov r1, sp
	bl sub_80AC448
	movs r1, 0xA2
	lsls r1, 1
	adds r0, r4, r1
	ldr r1, [r0]
	ldr r0, [r4, 0x14]
	adds r1, r0
	ldr r0, [sp]
	subs r0, r1
	str r0, [sp, 0x8]
	add r0, sp, 0x8
	movs r2, 0xA4
	lsls r2, 1
	adds r1, r4, r2
	ldr r2, [r1]
	ldr r1, [r4, 0x18]
	adds r2, r1
	ldr r1, [sp, 0x4]
	subs r1, r2
	str r1, [r0, 0x4]
	bl sub_8002C60
	lsls r0, 24
	asrs r1, r0, 24
	movs r0, 0x1
	negs r0, r0
	cmp r1, r0
	beq _080AA2B2
	movs r3, 0xA1
	lsls r3, 1
	adds r2, r4, r3
	lsls r0, r1, 24
	lsrs r0, 24
	strb r0, [r2]
	adds r3, 0x1B
	adds r1, r4, r3
	ldrb r1, [r1]
	lsls r1, 24
	asrs r1, 24
	lsls r0, 24
	asrs r0, 24
	cmp r1, r0
	beq _080AA29E
	movs r0, 0xAE
	lsls r0, 1
	adds r1, r4, r0
	movs r0, 0x1
	strb r0, [r1]
_080AA29E:
	movs r1, 0
	ldrsb r1, [r2, r1]
	adds r0, r4, 0
	bl sub_80AA3F8
	lsls r0, 24
	cmp r0, 0
	beq _080AA2B2
_080AA2AE:
	movs r0, 0x3
	b _080AA2B4
_080AA2B2:
	movs r0, 0
_080AA2B4:
	add sp, 0x10
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_80AA180

	thumb_func_start sub_80AA2BC
sub_80AA2BC:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x20
	adds r7, r0, 0
	mov r8, r1
	ldr r0, [r2]
	ldr r1, [r2, 0x4]
	str r0, [sp]
	str r1, [sp, 0x4]
	ldr r0, [r3]
	ldr r1, [r3, 0x4]
	str r0, [sp, 0x10]
	str r1, [sp, 0x14]
	ldr r0, [sp]
	cmp r0, 0
	bge _080AA2E6
	ldr r1, _080AA3C4
	adds r0, r1
_080AA2E6:
	asrs r0, 11
	str r0, [sp, 0x8]
	ldr r0, [sp, 0x4]
	cmp r0, 0
	bge _080AA2F4
	ldr r2, _080AA3C4
	adds r0, r2
_080AA2F4:
	asrs r0, 11
	add r1, sp, 0x8
	str r0, [r1, 0x4]
	ldr r4, [sp, 0x10]
	subs r0, r4, 0x1
	mov r10, r1
	cmp r0, 0
	bge _080AA308
	ldr r1, _080AA3C8
	adds r0, r4, r1
_080AA308:
	asrs r2, r0, 11
	add r0, sp, 0x10
	ldr r4, [r0, 0x4]
	subs r1, r4, 0x1
	mov r9, r0
	cmp r1, 0
	bge _080AA31A
	ldr r0, _080AA3C8
	adds r1, r4, r0
_080AA31A:
	asrs r3, r1, 11
	ldr r0, [sp, 0x8]
	subs r0, r2, r0
	adds r0, 0x1
	str r0, [sp, 0x18]
	mov r1, r10
	ldr r0, [r1, 0x4]
	subs r0, r3, r0
	adds r0, 0x1
	add r1, sp, 0x18
	str r0, [r1, 0x4]
	movs r0, 0x4
	mov r2, r8
	ands r0, r2
	cmp r0, 0
	beq _080AA394
	movs r1, 0
	ldrsh r0, [r7, r1]
	movs r1, 0x80
	mov r2, sp
	mov r3, r9
	bl sub_80A92A0
	lsls r0, 16
	asrs r5, r0, 16
	cmp r5, 0
	blt _080AA394
	ldr r1, _080AA3CC
	lsls r0, r5, 5
	subs r0, r5
	lsls r0, 4
	ldr r1, [r1]
	adds r6, r1, r0
	movs r2, 0x8E
	lsls r2, 1
	adds r0, r6, r2
	ldr r0, [r0]
	movs r1, 0x80
	lsls r1, 2
	ands r0, r1
	cmp r0, 0
	beq _080AA384
	movs r4, 0xA1
	lsls r4, 1
	adds r0, r7, r4
	ldrb r0, [r0]
	lsls r0, 24
	asrs r0, 24
	movs r1, 0x5
	bl sub_8002984
	adds r4, r6, r4
	strb r0, [r4]
_080AA384:
	movs r1, 0
	ldrsh r0, [r7, r1]
	adds r1, r5, 0
	bl GroundLives_ExecutePlayerScriptActionLives
	lsls r0, 24
	cmp r0, 0
	bne _080AA3BE
_080AA394:
	movs r0, 0x8
	mov r2, r8
	ands r0, r2
	cmp r0, 0
	beq _080AA3D0
	movs r0, 0x80
	mov r1, sp
	mov r2, r9
	bl sub_80AC4C8
	lsls r0, 16
	asrs r1, r0, 16
	cmp r1, 0
	blt _080AA3D0
	movs r2, 0
	ldrsh r0, [r7, r2]
	bl sub_80A8A5C
	lsls r0, 24
	cmp r0, 0
	beq _080AA3D0
_080AA3BE:
	movs r0, 0x3
	b _080AA3E6
	.align 2, 0
_080AA3C4: .4byte 0x000007ff
_080AA3C8: .4byte 0x000007fe
_080AA3CC: .4byte gUnknown_3001B84
_080AA3D0:
	movs r0, 0x10
	mov r1, r10
	add r2, sp, 0x18
	bl sub_80A595C
	lsls r0, 24
	cmp r0, 0
	bne _080AA3E4
	movs r0, 0
	b _080AA3E6
_080AA3E4:
	movs r0, 0x6
_080AA3E6:
	add sp, 0x20
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_80AA2BC

	thumb_func_start sub_80AA3F8
sub_80AA3F8:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x40
	adds r6, r0, 0
	lsls r1, 24
	asrs r1, 24
	str r1, [sp, 0x28]
	movs r2, 0x80
	lsls r2, 1
	mov r0, sp
	bl sub_8002BB8
	ldr r4, [sp]
	ldr r5, [sp, 0x4]
	movs r0, 0xA2
	lsls r0, 1
	adds r0, r6
	mov r9, r0
	ldr r0, [r0]
	adds r0, r4
	str r0, [sp, 0x8]
	movs r1, 0xA4
	lsls r1, 1
	adds r1, r6
	mov r10, r1
	ldr r0, [r1]
	adds r0, r5
	add r2, sp, 0x8
	str r0, [r2, 0x4]
	movs r1, 0xA6
	lsls r1, 1
	adds r0, r6, r1
	ldr r0, [r0]
	adds r0, r4
	str r0, [sp, 0x10]
	adds r1, 0x4
	adds r0, r6, r1
	ldr r0, [r0]
	adds r0, r5
	add r3, sp, 0x10
	str r0, [r3, 0x4]
	adds r0, r6, 0
	movs r1, 0xC
	bl sub_80AA2BC
	adds r7, r0, 0
	cmp r7, 0x3
	bne _080AA462
_080AA45E:
	movs r0, 0x1
	b _080AA650
_080AA462:
	ldr r0, [r6, 0xC]
	lsrs r1, r0, 31
	adds r0, r1
	asrs r0, 1
	movs r2, 0x80
	lsls r2, 2
	mov r8, r2
	add r0, r8
	muls r0, r4
	cmp r0, 0
	bge _080AA47A
	adds r0, 0xFF
_080AA47A:
	asrs r0, 8
	str r0, [sp, 0x2C]
	ldr r0, [r6, 0x10]
	lsrs r1, r0, 31
	adds r0, r1
	asrs r0, 1
	add r0, r8
	muls r0, r5
	cmp r0, 0
	bge _080AA490
	adds r0, 0xFF
_080AA490:
	asrs r0, 8
	str r0, [sp, 0x30]
	mov r1, r9
	ldr r0, [r1]
	ldr r1, [r6, 0x14]
	adds r0, r1
	ldr r2, [sp, 0x2C]
	adds r0, r2
	ldr r2, _080AA4F4
	adds r0, r2
	str r0, [sp, 0x18]
	mov r1, r10
	ldr r0, [r1]
	ldr r1, [r6, 0x18]
	adds r0, r1
	ldr r1, [sp, 0x30]
	adds r0, r1
	adds r0, r2
	add r2, sp, 0x18
	str r0, [r2, 0x4]
	movs r1, 0xC0
	lsls r1, 3
	ldr r0, [sp, 0x18]
	adds r0, r1
	str r0, [sp, 0x20]
	ldr r0, [r2, 0x4]
	adds r0, r1
	add r3, sp, 0x20
	str r0, [r3, 0x4]
	ldr r0, _080AA4F8
	mov r9, r0
	ldr r0, [sp, 0x28]
	lsls r1, r0, 2
	add r9, r1
	mov r0, r9
	ldr r0, [r0]
	str r0, [sp, 0x34]
	ldr r0, _080AA4FC
	adds r0, r1, r0
	ldr r0, [r0]
	str r0, [sp, 0x38]
	ldr r0, _080AA500
	adds r1, r0
	ldr r1, [r1]
	str r1, [sp, 0x3C]
	mov r10, r8
	mov r9, r2
	mov r8, r3
	b _080AA568
	.align 2, 0
_080AA4F4: .4byte 0xfffffd00
_080AA4F8: .4byte gUnknown_8117FF0
_080AA4FC: .4byte gUnknown_8118010
_080AA500: .4byte gUnknown_8118030
_080AA504:
	ldr r1, [r6, 0x28]
	ldr r0, [sp, 0x18]
	cmp r0, r1
	bge _080AA50E
	b _080AA64E
_080AA50E:
	ldr r1, [r6, 0x30]
	ldr r0, [sp, 0x20]
	cmp r0, r1
	blt _080AA518
	b _080AA64E
_080AA518:
	ldr r1, [r6, 0x2C]
	mov r2, r9
	ldr r0, [r2, 0x4]
	cmp r0, r1
	bge _080AA524
	b _080AA64E
_080AA524:
	ldr r1, [r6, 0x34]
	mov r2, r8
	ldr r0, [r2, 0x4]
	cmp r0, r1
	blt _080AA530
	b _080AA64E
_080AA530:
	adds r0, r6, 0
	movs r1, 0xC
	mov r2, r9
	mov r3, r8
	bl sub_80AA2BC
	adds r7, r0, 0
	cmp r7, 0x3
	beq _080AA45E
	ldr r0, [sp, 0x18]
	adds r0, r4
	str r0, [sp, 0x18]
	mov r1, r9
	ldr r0, [r1, 0x4]
	adds r0, r5
	str r0, [r1, 0x4]
	ldr r0, [sp, 0x20]
	adds r0, r4
	str r0, [sp, 0x20]
	mov r2, r8
	ldr r0, [r2, 0x4]
	adds r0, r5
	str r0, [r2, 0x4]
	cmp r7, 0x6
	beq _080AA572
	movs r0, 0x80
	lsls r0, 1
	add r10, r0
_080AA568:
	ldr r1, [sp, 0x34]
	cmp r10, r1
	blt _080AA504
	cmp r7, 0x6
	bne _080AA64E
_080AA572:
	ldr r2, [sp, 0x38]
	cmp r10, r2
	bge _080AA5DC
_080AA578:
	ldr r1, [sp, 0x18]
	ldr r0, [r6, 0x28]
	cmp r1, r0
	blt _080AA64E
	ldr r1, [sp, 0x20]
	ldr r0, [r6, 0x30]
	cmp r1, r0
	bge _080AA64E
	mov r0, r9
	ldr r1, [r0, 0x4]
	ldr r0, [r6, 0x2C]
	cmp r1, r0
	blt _080AA64E
	mov r2, r8
	ldr r1, [r2, 0x4]
	ldr r0, [r6, 0x34]
	cmp r1, r0
	bge _080AA64E
	adds r0, r6, 0
	movs r1, 0x4
	mov r2, r9
	mov r3, r8
	bl sub_80AA2BC
	adds r7, r0, 0
	cmp r7, 0x3
	bne _080AA5B0
	b _080AA45E
_080AA5B0:
	ldr r0, [sp, 0x18]
	adds r0, r4
	str r0, [sp, 0x18]
	mov r1, r9
	ldr r0, [r1, 0x4]
	adds r0, r5
	str r0, [r1, 0x4]
	ldr r0, [sp, 0x20]
	adds r0, r4
	str r0, [sp, 0x20]
	mov r2, r8
	ldr r0, [r2, 0x4]
	adds r0, r5
	str r0, [r2, 0x4]
	cmp r7, 0x6
	bne _080AA5E0
	movs r0, 0x80
	lsls r0, 1
	add r10, r0
	ldr r1, [sp, 0x38]
	cmp r10, r1
	blt _080AA578
_080AA5DC:
	cmp r7, 0x6
	beq _080AA64E
_080AA5E0:
	movs r2, 0
	mov r10, r2
	ldr r0, [sp, 0x3C]
	cmp r10, r0
	bge _080AA64E
_080AA5EA:
	ldr r1, [sp, 0x18]
	ldr r0, [r6, 0x28]
	cmp r1, r0
	blt _080AA64E
	ldr r1, [sp, 0x20]
	ldr r0, [r6, 0x30]
	cmp r1, r0
	bge _080AA64E
	mov r2, r9
	ldr r1, [r2, 0x4]
	ldr r0, [r6, 0x2C]
	cmp r1, r0
	blt _080AA64E
	mov r0, r8
	ldr r1, [r0, 0x4]
	ldr r0, [r6, 0x34]
	cmp r1, r0
	bge _080AA64E
	adds r0, r6, 0
	movs r1, 0x4
	mov r2, r9
	mov r3, r8
	bl sub_80AA2BC
	adds r7, r0, 0
	cmp r7, 0x3
	bne _080AA622
	b _080AA45E
_080AA622:
	cmp r7, 0x6
	beq _080AA64E
	ldr r0, [sp, 0x18]
	adds r0, r4
	str r0, [sp, 0x18]
	mov r1, r9
	ldr r0, [r1, 0x4]
	adds r0, r5
	str r0, [r1, 0x4]
	ldr r0, [sp, 0x20]
	adds r0, r4
	str r0, [sp, 0x20]
	mov r2, r8
	ldr r0, [r2, 0x4]
	adds r0, r5
	str r0, [r2, 0x4]
	movs r0, 0x80
	lsls r0, 1
	add r10, r0
	ldr r1, [sp, 0x3C]
	cmp r10, r1
	blt _080AA5EA
_080AA64E:
	movs r0, 0
_080AA650:
	add sp, 0x40
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_80AA3F8

	thumb_func_start sub_80AA660
sub_80AA660:
	push {r4,lr}
	adds r4, r0, 0
	movs r0, 0x80
	lsls r0, 1
	bl sub_80AC4C8
	lsls r0, 16
	asrs r1, r0, 16
	cmp r1, 0
	blt _080AA686
	movs r2, 0
	ldrsh r0, [r4, r2]
	bl sub_80A8A5C
	lsls r0, 24
	cmp r0, 0
	beq _080AA686
	movs r0, 0x4
	b _080AA688
_080AA686:
	movs r0, 0
_080AA688:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_80AA660

	thumb_func_start sub_80AA690
sub_80AA690:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x18
	adds r7, r0, 0
	lsls r1, 24
	asrs r1, 24
	mov r9, r1
	movs r2, 0x80
	lsls r2, 1
	mov r0, sp
	bl sub_8002BB8
	ldr r5, [sp]
	ldr r6, [sp, 0x4]
	ldr r0, [r7, 0xC]
	lsrs r1, r0, 31
	adds r0, r1
	asrs r0, 1
	movs r1, 0x80
	lsls r1, 2
	mov r8, r1
	add r0, r8
	muls r0, r5
	cmp r0, 0
	bge _080AA6CA
	adds r0, 0xFF
_080AA6CA:
	asrs r3, r0, 8
	ldr r0, [r7, 0x10]
	lsrs r1, r0, 31
	adds r0, r1
	asrs r0, 1
	add r0, r8
	muls r0, r6
	cmp r0, 0
	bge _080AA6DE
	adds r0, 0xFF
_080AA6DE:
	asrs r4, r0, 8
	movs r2, 0xA2
	lsls r2, 1
	adds r0, r7, r2
	ldr r0, [r0]
	ldr r1, [r7, 0x14]
	adds r0, r1
	adds r0, r3
	ldr r2, _080AA76C
	adds r0, r2
	str r0, [sp, 0x8]
	movs r1, 0xA4
	lsls r1, 1
	adds r0, r7, r1
	ldr r0, [r0]
	ldr r1, [r7, 0x18]
	adds r0, r1
	adds r0, r4
	adds r0, r2
	add r2, sp, 0x8
	str r0, [r2, 0x4]
	movs r1, 0xC0
	lsls r1, 3
	ldr r0, [sp, 0x8]
	adds r0, r1
	str r0, [sp, 0x10]
	ldr r0, [r2, 0x4]
	adds r0, r1
	add r3, sp, 0x10
	str r0, [r3, 0x4]
	ldr r1, _080AA770
	mov r4, r9
	lsls r0, r4, 2
	adds r0, r1
	ldr r0, [r0]
	mov r10, r0
	mov r9, r8
	mov r8, r2
	adds r4, r3, 0
	cmp r9, r10
	bge _080AA79C
_080AA730:
	ldr r1, [r7, 0x28]
	ldr r0, [sp, 0x8]
	cmp r0, r1
	blt _080AA79C
	ldr r1, [r7, 0x30]
	ldr r0, [sp, 0x10]
	cmp r0, r1
	bge _080AA79C
	ldr r1, [r7, 0x2C]
	mov r2, r8
	ldr r0, [r2, 0x4]
	cmp r0, r1
	blt _080AA79C
	ldr r1, [r7, 0x34]
	ldr r0, [r4, 0x4]
	cmp r0, r1
	bge _080AA79C
	adds r0, r7, 0
	mov r1, r8
	adds r2, r4, 0
	bl sub_80AA660
	cmp r0, 0x4
	beq _080AA774
	cmp r0, 0x4
	bhi _080AA778
	cmp r0, 0
	bne _080AA778
	b _080AA79C
	.align 2, 0
_080AA76C: .4byte 0xfffffd00
_080AA770: .4byte gUnknown_8117FF0
_080AA774:
	movs r0, 0x1
	b _080AA79E
_080AA778:
	ldr r0, [sp, 0x8]
	adds r0, r5
	str r0, [sp, 0x8]
	mov r1, r8
	ldr r0, [r1, 0x4]
	adds r0, r6
	str r0, [r1, 0x4]
	ldr r0, [sp, 0x10]
	adds r0, r5
	str r0, [sp, 0x10]
	ldr r0, [r4, 0x4]
	adds r0, r6
	str r0, [r4, 0x4]
	movs r2, 0x80
	lsls r2, 1
	add r9, r2
	cmp r9, r10
	blt _080AA730
_080AA79C:
	movs r0, 0
_080AA79E:
	add sp, 0x18
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_80AA690

	thumb_func_start sub_80AA7B0
sub_80AA7B0:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0x20
	adds r7, r0, 0
	adds r6, r1, 0
	mov r12, r2
	ldr r2, [sp, 0x38]
	ldr r0, [r3]
	ldr r1, [r3, 0x4]
	str r0, [sp]
	str r1, [sp, 0x4]
	ldr r0, [r2]
	ldr r1, [r2, 0x4]
	str r0, [sp, 0x10]
	str r1, [sp, 0x14]
	ldr r0, [sp]
	cmp r0, 0
	bge _080AA7DA
	ldr r1, _080AA884
	adds r0, r1
_080AA7DA:
	asrs r0, 11
	str r0, [sp, 0x8]
	ldr r0, [sp, 0x4]
	cmp r0, 0
	bge _080AA7E8
	ldr r2, _080AA884
	adds r0, r2
_080AA7E8:
	asrs r0, 11
	add r1, sp, 0x8
	str r0, [r1, 0x4]
	ldr r4, [sp, 0x10]
	subs r0, r4, 0x1
	mov r8, r1
	cmp r0, 0
	bge _080AA7FC
	ldr r5, _080AA888
	adds r0, r4, r5
_080AA7FC:
	asrs r2, r0, 11
	add r4, sp, 0x10
	ldr r1, [r4, 0x4]
	subs r0, r1, 0x1
	cmp r0, 0
	bge _080AA80C
	ldr r5, _080AA888
	adds r0, r1, r5
_080AA80C:
	asrs r3, r0, 11
	ldr r0, [sp, 0x8]
	subs r0, r2, r0
	adds r0, 0x1
	str r0, [sp, 0x18]
	mov r1, r8
	ldr r0, [r1, 0x4]
	subs r0, r3, r0
	adds r0, 0x1
	add r1, sp, 0x18
	str r0, [r1, 0x4]
	movs r0, 0x4
	mov r2, r12
	ands r0, r2
	adds r5, r1, 0
	cmp r0, 0
	beq _080AA890
	movs r1, 0
	ldrsh r0, [r7, r1]
	movs r1, 0x80
	mov r2, sp
	adds r3, r4, 0
	bl sub_80A92A0
	lsls r0, 16
	asrs r4, r0, 16
	cmp r4, 0
	blt _080AA890
	adds r0, r4, 0
	bl sub_80A8BBC
	lsls r0, 16
	ldr r2, _080AA88C
	adds r0, r2
	lsrs r0, 16
	cmp r0, 0xF
	bhi _080AA890
	adds r0, r4, 0
	bl sub_80A8E9C
	cmp r0, 0
	beq _080AA890
	strh r4, [r6]
	movs r5, 0xA1
	lsls r5, 1
	adds r0, r7, r5
	ldrb r0, [r0]
	lsls r0, 24
	asrs r0, 24
	movs r1, 0x5
	bl sub_8002984
	adds r1, r0, 0
	lsls r1, 24
	asrs r1, 24
	adds r0, r4, 0
	bl sub_80A9090
	movs r0, 0x5
	b _080AA8AE
	.align 2, 0
_080AA884: .4byte 0x000007ff
_080AA888: .4byte 0x000007fe
_080AA88C: .4byte 0xfff20000
_080AA890:
	movs r1, 0x1
	negs r1, r1
	adds r0, r1, 0
	strh r0, [r6]
	movs r0, 0x10
	mov r1, r8
	adds r2, r5, 0
	bl sub_80A595C
	lsls r0, 24
	cmp r0, 0
	bne _080AA8AC
	movs r0, 0
	b _080AA8AE
_080AA8AC:
	movs r0, 0x6
_080AA8AE:
	add sp, 0x20
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_80AA7B0

	thumb_func_start sub_80AA8BC
sub_80AA8BC:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x30
	adds r6, r0, 0
	str r1, [sp, 0x1C]
	lsls r2, 24
	asrs r2, 24
	mov r8, r2
	movs r2, 0x80
	lsls r2, 1
	add r0, sp, 0x4
	mov r1, r8
	bl sub_8002BB8
	ldr r4, [sp, 0x4]
	ldr r5, [sp, 0x8]
	ldr r0, [r6, 0xC]
	lsrs r1, r0, 31
	adds r0, r1
	asrs r0, 1
	movs r1, 0x80
	lsls r1, 2
	mov r9, r1
	add r0, r9
	muls r0, r4
	cmp r0, 0
	bge _080AA8FA
	adds r0, 0xFF
_080AA8FA:
	asrs r0, 8
	str r0, [sp, 0x20]
	ldr r0, [r6, 0x10]
	lsrs r1, r0, 31
	adds r0, r1
	asrs r0, 1
	add r0, r9
	muls r0, r5
	cmp r0, 0
	bge _080AA910
	adds r0, 0xFF
_080AA910:
	asrs r0, 8
	str r0, [sp, 0x24]
	movs r2, 0xA2
	lsls r2, 1
	adds r0, r6, r2
	ldr r0, [r0]
	ldr r1, [r6, 0x14]
	adds r0, r1
	ldr r7, [sp, 0x20]
	adds r0, r7
	ldr r2, _080AA9F0
	adds r0, r2
	str r0, [sp, 0xC]
	movs r1, 0xA4
	lsls r1, 1
	adds r0, r6, r1
	ldr r0, [r0]
	ldr r1, [r6, 0x18]
	adds r0, r1
	ldr r7, [sp, 0x24]
	adds r0, r7
	adds r0, r2
	add r2, sp, 0xC
	str r0, [r2, 0x4]
	movs r1, 0xC0
	lsls r1, 3
	ldr r0, [sp, 0xC]
	adds r0, r1
	str r0, [sp, 0x14]
	ldr r0, [r2, 0x4]
	adds r0, r1
	add r3, sp, 0x14
	str r0, [r3, 0x4]
	ldr r0, _080AA9F4
	mov r7, r8
	lsls r1, r7, 2
	adds r0, r1, r0
	ldr r0, [r0]
	mov r10, r0
	ldr r0, _080AA9F8
	adds r0, r1, r0
	ldr r0, [r0]
	str r0, [sp, 0x28]
	ldr r0, _080AA9FC
	adds r1, r0
	ldr r1, [r1]
	str r1, [sp, 0x2C]
	movs r1, 0
	movs r7, 0x1
	negs r7, r7
	adds r0, r7, 0
	ldr r7, [sp, 0x1C]
	strh r0, [r7]
	mov r8, r2
	adds r7, r3, 0
	cmp r9, r10
	bge _080AA9E8
_080AA982:
	ldr r1, [r6, 0x28]
	ldr r0, [sp, 0xC]
	cmp r0, r1
	bge _080AA98C
	b _080AAAD4
_080AA98C:
	ldr r1, [r6, 0x30]
	ldr r0, [sp, 0x14]
	cmp r0, r1
	blt _080AA996
	b _080AAAD4
_080AA996:
	ldr r1, [r6, 0x2C]
	mov r2, r8
	ldr r0, [r2, 0x4]
	cmp r0, r1
	bge _080AA9A2
	b _080AAAD4
_080AA9A2:
	ldr r1, [r6, 0x34]
	ldr r0, [r7, 0x4]
	cmp r0, r1
	blt _080AA9AC
	b _080AAAD4
_080AA9AC:
	str r7, [sp]
	adds r0, r6, 0
	ldr r1, [sp, 0x1C]
	movs r2, 0xC
	mov r3, r8
	bl sub_80AA7B0
	adds r1, r0, 0
	cmp r1, 0x5
	beq _080AAA66
	ldr r0, [sp, 0xC]
	adds r0, r4
	str r0, [sp, 0xC]
	mov r2, r8
	ldr r0, [r2, 0x4]
	adds r0, r5
	str r0, [r2, 0x4]
	ldr r0, [sp, 0x14]
	adds r0, r4
	str r0, [sp, 0x14]
	ldr r0, [r7, 0x4]
	adds r0, r5
	str r0, [r7, 0x4]
	cmp r1, 0x6
	beq _080AAA5A
	movs r0, 0x80
	lsls r0, 1
	add r9, r0
	cmp r9, r10
	blt _080AA982
_080AA9E8:
	cmp r1, 0x6
	bne _080AAAD4
	b _080AAA5A
	.align 2, 0
_080AA9F0: .4byte 0xfffffd00
_080AA9F4: .4byte gUnknown_8117FF0
_080AA9F8: .4byte gUnknown_8118010
_080AA9FC: .4byte gUnknown_8118030
_080AAA00:
	ldr r1, [sp, 0xC]
	ldr r0, [r6, 0x28]
	cmp r1, r0
	blt _080AAAD4
	ldr r1, [sp, 0x14]
	ldr r0, [r6, 0x30]
	cmp r1, r0
	bge _080AAAD4
	mov r0, r8
	ldr r1, [r0, 0x4]
	ldr r0, [r6, 0x2C]
	cmp r1, r0
	blt _080AAAD4
	ldr r1, [r7, 0x4]
	ldr r0, [r6, 0x34]
	cmp r1, r0
	bge _080AAAD4
	str r7, [sp]
	adds r0, r6, 0
	ldr r1, [sp, 0x1C]
	movs r2, 0x4
	mov r3, r8
	bl sub_80AA7B0
	adds r1, r0, 0
	cmp r1, 0x5
	beq _080AAA66
	ldr r0, [sp, 0xC]
	adds r0, r4
	str r0, [sp, 0xC]
	mov r2, r8
	ldr r0, [r2, 0x4]
	adds r0, r5
	str r0, [r2, 0x4]
	ldr r0, [sp, 0x14]
	adds r0, r4
	str r0, [sp, 0x14]
	ldr r0, [r7, 0x4]
	adds r0, r5
	str r0, [r7, 0x4]
	cmp r1, 0x6
	bne _080AAA6A
	movs r0, 0x80
	lsls r0, 1
	add r9, r0
_080AAA5A:
	ldr r2, [sp, 0x28]
	cmp r9, r2
	blt _080AAA00
	cmp r1, 0x6
	bne _080AAA6A
	b _080AAAD4
_080AAA66:
	movs r0, 0x1
	b _080AAAD6
_080AAA6A:
	movs r0, 0
	mov r9, r0
	ldr r1, [sp, 0x2C]
	cmp r9, r1
	bge _080AAAD4
_080AAA74:
	ldr r1, [sp, 0xC]
	ldr r0, [r6, 0x28]
	cmp r1, r0
	blt _080AAAD4
	ldr r1, [sp, 0x14]
	ldr r0, [r6, 0x30]
	cmp r1, r0
	bge _080AAAD4
	mov r2, r8
	ldr r1, [r2, 0x4]
	ldr r0, [r6, 0x2C]
	cmp r1, r0
	blt _080AAAD4
	ldr r1, [r7, 0x4]
	ldr r0, [r6, 0x34]
	cmp r1, r0
	bge _080AAAD4
	str r7, [sp]
	adds r0, r6, 0
	ldr r1, [sp, 0x1C]
	movs r2, 0x4
	mov r3, r8
	bl sub_80AA7B0
	adds r1, r0, 0
	cmp r1, 0x5
	beq _080AAA66
	cmp r1, 0x6
	beq _080AAAD4
	ldr r0, [sp, 0xC]
	adds r0, r4
	str r0, [sp, 0xC]
	mov r1, r8
	ldr r0, [r1, 0x4]
	adds r0, r5
	str r0, [r1, 0x4]
	ldr r0, [sp, 0x14]
	adds r0, r4
	str r0, [sp, 0x14]
	ldr r0, [r7, 0x4]
	adds r0, r5
	str r0, [r7, 0x4]
	movs r2, 0x80
	lsls r2, 1
	add r9, r2
	ldr r0, [sp, 0x2C]
	cmp r9, r0
	blt _080AAA74
_080AAAD4:
	movs r0, 0
_080AAAD6:
	add sp, 0x30
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_80AA8BC

	thumb_func_start sub_80AAAE8
sub_80AAAE8:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x80
	adds r5, r0, 0
	adds r3, r1, 0
	lsls r2, 24
	asrs r4, r2, 24
	movs r0, 0x1
	negs r0, r0
	str r0, [sp, 0x78]
	movs r2, 0xAF
	lsls r2, 1
	adds r1, r5, r2
	movs r0, 0xC0
	lsls r0, 2
	strh r0, [r1]
	movs r6, 0xB0
	lsls r6, 1
	adds r1, r5, r6
	movs r0, 0x1
	strh r0, [r1]
	ldr r0, [sp, 0x78]
	cmp r4, r0
	beq _080AAB26
	movs r1, 0xA1
	lsls r1, 1
	adds r0, r5, r1
	strb r4, [r0]
_080AAB26:
	subs r0, r3, 0x1
	cmp r0, 0x13
	bls _080AAB2E
	b _080AAEB8
_080AAB2E:
	lsls r0, 2
	ldr r1, _080AAB38
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080AAB38: .4byte _080AAB3C
	.align 2, 0
_080AAB3C:
	.4byte _080AAB8C
	.4byte _080AAD60
	.4byte _080AAC9C
	.4byte _080AAC9C
	.4byte _080AAC9C
	.4byte _080AAB9E
	.4byte _080AAB9E
	.4byte _080AAB9E
	.4byte _080AAD7C
	.4byte _080AADF4
	.4byte _080AAE06
	.4byte _080AAEB8
	.4byte _080AAEB8
	.4byte _080AAEB8
	.4byte _080AAEB8
	.4byte _080AAEB8
	.4byte _080AAEB8
	.4byte _080AAEB8
	.4byte _080AAE32
	.4byte _080AAE9C
_080AAB8C:
	movs r4, 0xB2
	lsls r4, 1
	adds r1, r5, r4
	movs r0, 0
	str r0, [r1]
	movs r6, 0xC0
	lsls r6, 2
	str r6, [sp, 0x78]
	b _080AAD6E
_080AAB9E:
	movs r0, 0x1
	negs r0, r0
	cmp r4, r0
	beq _080AAC88
	movs r6, 0
	movs r0, 0xB2
	lsls r0, 1
	adds r1, r5, r0
	movs r0, 0x4
	str r0, [r1]
	cmp r3, 0x7
	beq _080AABD2
	cmp r3, 0x7
	bhi _080AABC0
	cmp r3, 0x6
	beq _080AABC6
	b _080AABEA
_080AABC0:
	cmp r3, 0x8
	beq _080AABDE
	b _080AABEA
_080AABC6:
	movs r1, 0x90
	lsls r1, 4
	str r1, [sp, 0x78]
	movs r2, 0x1
	str r2, [sp, 0x7C]
	b _080AABFC
_080AABD2:
	movs r3, 0x80
	lsls r3, 4
	str r3, [sp, 0x78]
	movs r0, 0x2
	str r0, [sp, 0x7C]
	b _080AABFC
_080AABDE:
	movs r1, 0xA0
	lsls r1, 4
	str r1, [sp, 0x78]
	movs r2, 0x4
	str r2, [sp, 0x7C]
	b _080AABFC
_080AABEA:
	movs r3, 0xB2
	lsls r3, 1
	adds r1, r5, r3
	movs r0, 0
	str r0, [r1]
	ldr r0, _080AAC20
	str r0, [sp, 0x78]
	movs r1, 0
	str r1, [sp, 0x7C]
_080AABFC:
	movs r2, 0x80
	lsls r2, 1
	add r0, sp, 0x28
	adds r1, r4, 0
	bl sub_8002BB8
	ldr r0, [sp, 0x28]
	ldr r1, [sp, 0x2C]
	str r0, [sp, 0x38]
	str r1, [sp, 0x3C]
	movs r2, 0
	mov r10, r2
	add r3, sp, 0x40
	mov r9, r3
	add r4, sp, 0x30
	mov r8, r4
	b _080AAC42
	.align 2, 0
_080AAC20: .4byte 0x00000807
_080AAC24:
	cmp r6, 0x1
	bne _080AAC3E
	ldr r0, [sp, 0x38]
	str r0, [sp, 0x30]
	mov r6, r8
	str r7, [r6, 0x4]
	adds r0, r5, 0
	mov r1, r8
	bl sub_80AA074
	adds r6, r0, 0
	cmp r6, 0x2
	beq _080AAC78
_080AAC3E:
	movs r0, 0x1
	add r10, r0
_080AAC42:
	ldr r1, [sp, 0x7C]
	cmp r10, r1
	bge _080AAC74
	add r4, sp, 0x38
	adds r0, r5, 0
	adds r1, r4, 0
	bl sub_80AA074
	adds r6, r0, 0
	cmp r6, 0x2
	beq _080AAC78
	cmp r6, 0x1
	bne _080AAC3E
	movs r7, 0
	str r7, [sp, 0x40]
	ldr r0, [r4, 0x4]
	mov r2, r9
	str r0, [r2, 0x4]
	adds r0, r5, 0
	mov r1, r9
	bl sub_80AA074
	adds r6, r0, 0
	cmp r6, 0x2
	bne _080AAC24
_080AAC74:
	cmp r6, 0x2
	bne _080AAC7E
_080AAC78:
	movs r3, 0x1
	negs r3, r3
	b _080AAD6C
_080AAC7E:
	adds r0, r5, 0
	movs r1, 0x1
	bl sub_80AAF68
	b _080AAEC0
_080AAC88:
	movs r4, 0xB2
	lsls r4, 1
	adds r1, r5, r4
	movs r0, 0
	str r0, [r1]
	ldr r6, _080AAC98
	str r6, [sp, 0x78]
	b _080AAD6E
	.align 2, 0
_080AAC98: .4byte 0x00000807
_080AAC9C:
	movs r0, 0x1
	negs r0, r0
	cmp r4, r0
	beq _080AAD60
	movs r0, 0xB2
	lsls r0, 1
	adds r1, r5, r0
	movs r0, 0x4
	str r0, [r1]
	cmp r3, 0x4
	beq _080AACCE
	cmp r3, 0x4
	bhi _080AACBC
	cmp r3, 0x3
	beq _080AACC2
	b _080AACE6
_080AACBC:
	cmp r3, 0x5
	beq _080AACDA
	b _080AACE6
_080AACC2:
	movs r1, 0x90
	lsls r1, 4
	str r1, [sp, 0x78]
	movs r2, 0x1
	mov r9, r2
	b _080AACF6
_080AACCE:
	movs r3, 0x80
	lsls r3, 4
	str r3, [sp, 0x78]
	movs r6, 0x2
	mov r9, r6
	b _080AACF6
_080AACDA:
	movs r0, 0xA0
	lsls r0, 4
	str r0, [sp, 0x78]
	movs r1, 0x4
	mov r9, r1
	b _080AACF6
_080AACE6:
	movs r2, 0xB2
	lsls r2, 1
	adds r1, r5, r2
	movs r0, 0
	str r0, [r1]
	ldr r3, _080AAD5C
	str r3, [sp, 0x78]
	mov r9, r0
_080AACF6:
	movs r2, 0x80
	lsls r2, 1
	add r0, sp, 0x48
	adds r1, r4, 0
	bl sub_8002BB8
	ldr r0, [sp, 0x48]
	ldr r1, [sp, 0x4C]
	str r0, [sp, 0x50]
	str r1, [sp, 0x54]
	movs r6, 0
	cmp r6, r9
	bge _080AAD52
	add r4, sp, 0x50
	mov r8, r4
	add r7, sp, 0x58
_080AAD16:
	adds r0, r5, 0
	mov r1, r8
	bl sub_80A9F94
	cmp r0, 0
	beq _080AAD4C
	movs r4, 0
	str r4, [sp, 0x58]
	mov r1, r8
	ldr r0, [r1, 0x4]
	str r0, [r7, 0x4]
	adds r0, r5, 0
	adds r1, r7, 0
	bl sub_80A9F94
	cmp r0, 0
	beq _080AAD4C
	ldr r0, [sp, 0x50]
	str r0, [sp, 0x60]
	add r1, sp, 0x60
	str r4, [r1, 0x4]
	adds r0, r5, 0
	bl sub_80A9F94
	cmp r0, 0
	beq _080AAD4C
	mov r9, r4
_080AAD4C:
	adds r6, 0x1
	cmp r6, r9
	blt _080AAD16
_080AAD52:
	adds r0, r5, 0
	mov r1, r9
	bl sub_80AAF68
	b _080AAEC0
	.align 2, 0
_080AAD5C: .4byte 0x00000807
_080AAD60:
	movs r2, 0xB2
	lsls r2, 1
	adds r1, r5, r2
	movs r0, 0
	str r0, [r1]
	ldr r3, _080AAD78
_080AAD6C:
	str r3, [sp, 0x78]
_080AAD6E:
	adds r0, r5, 0
	movs r1, 0
	bl sub_80AAF68
	b _080AAEC0
	.align 2, 0
_080AAD78: .4byte 0x00000807
_080AAD7C:
	movs r6, 0x8E
	lsls r6, 1
	adds r0, r5, r6
	ldr r0, [r0]
	movs r1, 0x80
	lsls r1, 5
	ands r0, r1
	cmp r0, 0
	beq _080AAD9C
	ldr r0, _080AAD98
	ldr r0, [r0]
	adds r0, 0x28
	strb r4, [r0]
	b _080AADA6
	.align 2, 0
_080AAD98: .4byte gUnknown_3001B80
_080AAD9C:
	ldr r0, _080AADF0
	ldr r0, [r0]
	adds r0, 0x28
	movs r1, 0xFF
	strb r1, [r0]
_080AADA6:
	movs r1, 0xB2
	lsls r1, 1
	adds r0, r5, r1
	movs r1, 0
	str r1, [r0]
	movs r2, 0x80
	lsls r2, 4
	str r2, [sp, 0x78]
	movs r3, 0xA1
	lsls r3, 1
	adds r1, r5, r3
	movs r0, 0x4
	strb r0, [r1]
	movs r6, 0x1
	negs r6, r6
	cmp r4, r6
	bne _080AADCA
	b _080AAEC0
_080AADCA:
	movs r2, 0x80
	lsls r2, 1
	add r0, sp, 0x68
	adds r1, r4, 0
	bl sub_8002BB8
	ldr r0, [sp, 0x68]
	ldr r1, [sp, 0x6C]
	str r0, [sp, 0x70]
	str r1, [sp, 0x74]
	add r1, sp, 0x70
	adds r0, r5, 0
	bl sub_80AA074
	cmp r0, 0x2
	bne _080AAEC0
	str r6, [sp, 0x78]
	b _080AAEC0
	.align 2, 0
_080AADF0: .4byte gUnknown_3001B80
_080AADF4:
	movs r4, 0xA1
	lsls r4, 1
	adds r0, r5, r4
	movs r1, 0
	ldrsb r1, [r0, r1]
	adds r0, r5, 0
	bl sub_80AA3F8
	b _080AAEC0
_080AAE06:
	movs r6, 0xA1
	lsls r6, 1
	adds r0, r5, r6
	movs r1, 0
	ldrsb r1, [r0, r1]
	adds r0, r5, 0
	bl sub_80AA690
	lsls r0, 24
	cmp r0, 0
	bne _080AAEC0
	movs r0, 0
	mov r1, sp
	movs r2, 0x9
	bl sub_809D710
	adds r0, r5, 0
	movs r1, 0
	mov r2, sp
	bl _ExecutePlayerScript
	b _080AAEC0
_080AAE32:
	add r6, sp, 0xC
	movs r1, 0xA1
	lsls r1, 1
	adds r0, r5, r1
	movs r2, 0
	ldrsb r2, [r0, r2]
	adds r0, r5, 0
	adds r1, r6, 0
	bl sub_80AA8BC
	lsls r0, 24
	cmp r0, 0
	beq _080AAE84
	add r4, sp, 0x10
	movs r0, 0
	adds r1, r4, 0
	movs r2, 0x6
	bl sub_809D710
	movs r2, 0
	ldrsh r0, [r6, r2]
	adds r1, r5, 0
	adds r1, 0x40
	adds r2, r4, 0
	bl GroundLives_ExecuteScript
	adds r0, r5, 0
	movs r1, 0
	movs r2, 0
	bl _ExecutePlayerScript
	movs r3, 0
	ldrsh r0, [r6, r3]
	bl sub_80A8E9C
	adds r2, r0, 0
	movs r0, 0x7
	movs r1, 0
	bl sub_809B1C0
	b _080AAE8E
_080AAE84:
	movs r0, 0x7
	movs r1, 0
	movs r2, 0
	bl sub_809B1C0
_080AAE8E:
	movs r4, 0x90
	lsls r4, 1
	adds r0, r5, r4
	movs r1, 0x5
	bl sub_809CD8C
	b _080AAEC0
_080AAE9C:
	add r4, sp, 0x1C
	ldr r2, _080AAEB4
	movs r0, 0
	adds r1, r4, 0
	bl sub_809D710
	adds r0, r5, 0
	movs r1, 0
	adds r2, r4, 0
	bl _ExecutePlayerScript
	b _080AAEC0
	.align 2, 0
_080AAEB4: .4byte 0x00000195
_080AAEB8:
	adds r0, r5, 0
	movs r1, 0
	bl sub_80AAF68
_080AAEC0:
	movs r0, 0x1
	negs r0, r0
	ldr r6, [sp, 0x78]
	cmp r6, r0
	beq _080AAF04
	movs r0, 0xB4
	lsls r0, 1
	adds r2, r5, r0
	movs r1, 0
	ldrsh r0, [r2, r1]
	cmp r6, r0
	beq _080AAF04
	movs r3, 0xAE
	lsls r3, 1
	adds r1, r5, r3
	movs r0, 0
	strb r0, [r1]
	movs r4, 0xB8
	lsls r4, 1
	adds r0, r5, r4
	strh r6, [r2]
	movs r1, 0xA1
	lsls r1, 1
	adds r3, r5, r1
	ldrb r1, [r3]
	subs r4, 0x13
	adds r2, r5, r4
	strb r1, [r2]
	movs r2, 0
	ldrsb r2, [r3, r2]
	ldr r1, [sp, 0x78]
	bl sub_80A6EFC
	b _080AAF54
_080AAF04:
	movs r6, 0xAE
	lsls r6, 1
	adds r2, r5, r6
	ldrb r0, [r2]
	cmp r0, 0
	bne _080AAF2A
	ldr r0, _080AAF64
	adds r1, r5, r0
	movs r3, 0xA1
	lsls r3, 1
	adds r0, r5, r3
	ldrb r1, [r1]
	lsls r1, 24
	asrs r1, 24
	ldrb r0, [r0]
	lsls r0, 24
	asrs r0, 24
	cmp r1, r0
	beq _080AAF54
_080AAF2A:
	movs r0, 0
	strb r0, [r2]
	movs r4, 0xB8
	lsls r4, 1
	adds r0, r5, r4
	movs r6, 0xB4
	lsls r6, 1
	adds r1, r5, r6
	movs r2, 0
	ldrsh r1, [r1, r2]
	movs r3, 0xA1
	lsls r3, 1
	adds r4, r5, r3
	ldrb r2, [r4]
	subs r6, 0xB
	adds r3, r5, r6
	strb r2, [r3]
	movs r2, 0
	ldrsb r2, [r4, r2]
	bl sub_80A6EFC
_080AAF54:
	add sp, 0x80
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_080AAF64: .4byte 0x0000015d
	thumb_func_end sub_80AAAE8

	thumb_func_start sub_80AAF68
sub_80AAF68:
	push {r4,lr}
	adds r4, r0, 0
	movs r1, 0x8E
	lsls r1, 1
	adds r0, r4, r1
	ldr r0, [r0]
	movs r1, 0x80
	lsls r1, 7
	ands r0, r1
	cmp r0, 0
	beq _080AB002
	movs r2, 0
	ldrsh r0, [r4, r2]
	movs r1, 0x1
	bl sub_80A93F0
	lsls r0, 24
	cmp r0, 0
	beq _080AAFD0
	movs r1, 0xE4
	lsls r1, 1
	adds r0, r4, r1
	movs r2, 0
	ldrsh r1, [r0, r2]
	cmp r1, 0
	bne _080AAFA6
	movs r0, 0xB5
	lsls r0, 1
	adds r1, r4, r0
	adds r0, 0x4C
	b _080AAFB4
_080AAFA6:
	movs r0, 0xDB
	lsls r0, 1
	cmp r1, r0
	beq _080AAFC2
	subs r0, 0x4C
	adds r1, r4, r0
	adds r0, 0x56
_080AAFB4:
	strh r0, [r1]
	movs r2, 0xB6
	lsls r2, 1
	adds r1, r4, r2
	movs r0, 0x1
	negs r0, r0
	str r0, [r1]
_080AAFC2:
	movs r1, 0
	ldrsh r0, [r4, r1]
	movs r1, 0x80
	lsls r1, 17
	bl sub_80A8750
	b _080AB002
_080AAFD0:
	movs r2, 0xE4
	lsls r2, 1
	adds r0, r4, r2
	movs r2, 0
	ldrsh r1, [r0, r2]
	movs r0, 0xDB
	lsls r0, 1
	cmp r1, r0
	bne _080AAFF6
	subs r0, 0x4C
	adds r1, r4, r0
	adds r0, 0x56
	strh r0, [r1]
	movs r2, 0xB6
	lsls r2, 1
	adds r1, r4, r2
	movs r0, 0x1
	negs r0, r0
	str r0, [r1]
_080AAFF6:
	movs r1, 0
	ldrsh r0, [r4, r1]
	movs r1, 0x80
	lsls r1, 17
	bl sub_80A86C8
_080AB002:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_80AAF68

	thumb_func_start sub_80AB008
sub_80AB008:
	movs r1, 0
	ldrsh r0, [r0, r1]
	bx lr
	thumb_func_end sub_80AB008

	thumb_func_start sub_80AB010
sub_80AB010:
	ldr r2, [r0, 0xC]
	ldr r3, [r0, 0x10]
	str r2, [r1]
	str r3, [r1, 0x4]
	bx lr
	thumb_func_end sub_80AB010

	thumb_func_start sub_80AB01C
sub_80AB01C:
	push {r4,lr}
	adds r3, r0, 0
	adds r4, r1, 0
	cmp r4, 0
	beq _080AB05C
	movs r0, 0xA2
	lsls r0, 1
	adds r2, r3, r0
	ldr r1, [r4]
	ldr r0, [r3, 0x14]
	subs r0, r1, r0
	str r0, [r2]
	movs r0, 0xA6
	lsls r0, 1
	adds r2, r3, r0
	ldr r0, [r3, 0x14]
	adds r1, r0
	str r1, [r2]
	movs r0, 0xA4
	lsls r0, 1
	adds r2, r3, r0
	ldr r1, [r4, 0x4]
	ldr r0, [r3, 0x18]
	subs r0, r1, r0
	str r0, [r2]
	movs r0, 0xA8
	lsls r0, 1
	adds r2, r3, r0
	ldr r0, [r3, 0x18]
	adds r1, r0
	str r1, [r2]
	b _080AB0C2
_080AB05C:
	movs r0, 0xA2
	lsls r0, 1
	adds r2, r3, r0
	ldr r0, [r3, 0x20]
	ldr r1, [r3, 0x14]
	subs r0, r1
	str r0, [r2]
	movs r0, 0xA6
	lsls r0, 1
	adds r2, r3, r0
	ldr r0, [r3, 0x20]
	ldr r1, [r3, 0x14]
	adds r0, r1
	str r0, [r2]
	movs r0, 0xA4
	lsls r0, 1
	adds r2, r3, r0
	ldr r0, [r3, 0x24]
	ldr r1, [r3, 0x18]
	subs r0, r1
	str r0, [r2]
	movs r0, 0xA8
	lsls r0, 1
	adds r2, r3, r0
	ldr r0, [r3, 0x24]
	ldr r1, [r3, 0x18]
	adds r0, r1
	str r0, [r2]
	movs r2, 0xAA
	lsls r2, 1
	adds r1, r3, r2
	adds r2, 0x4
	adds r0, r3, r2
	str r4, [r0]
	str r4, [r1]
	movs r0, 0xA1
	lsls r0, 1
	adds r2, r3, r0
	movs r1, 0
	ldrsb r1, [r2, r1]
	movs r0, 0x1C
	ldrsb r0, [r3, r0]
	cmp r1, r0
	beq _080AB0BE
	movs r0, 0xAE
	lsls r0, 1
	adds r1, r3, r0
	movs r0, 0x1
	strb r0, [r1]
_080AB0BE:
	ldrb r0, [r3, 0x1C]
	strb r0, [r2]
_080AB0C2:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_80AB01C

	thumb_func_start sub_80AB0C8
sub_80AB0C8:
	push {r4,lr}
	ldr r3, [r1]
	ldr r4, [r1, 0x4]
	str r3, [r0, 0x28]
	str r4, [r0, 0x2C]
	ldr r1, [r2]
	ldr r2, [r2, 0x4]
	str r1, [r0, 0x30]
	str r2, [r0, 0x34]
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_80AB0C8

	thumb_func_start sub_80AB0E0
sub_80AB0E0:
	adds r3, r0, 0
	movs r2, 0xA2
	lsls r2, 1
	adds r0, r3, r2
	ldr r0, [r0]
	ldr r2, [r3, 0x14]
	adds r0, r2
	str r0, [r1]
	movs r2, 0xA4
	lsls r2, 1
	adds r0, r3, r2
	ldr r0, [r0]
	ldr r2, [r3, 0x18]
	adds r0, r2
	str r0, [r1, 0x4]
	bx lr
	thumb_func_end sub_80AB0E0

	thumb_func_start sub_80AB100
sub_80AB100:
	push {lr}
	bl sub_80A9F20
	pop {r1}
	bx r1
	thumb_func_end sub_80AB100

	thumb_func_start sub_80AB10C
sub_80AB10C:
	push {r4,lr}
	adds r3, r0, 0
	movs r4, 0xAA
	lsls r4, 1
	adds r0, r3, r4
	ldr r0, [r0]
	str r0, [r1]
	movs r1, 0xAC
	lsls r1, 1
	adds r0, r3, r1
	ldr r0, [r0]
	str r0, [r2]
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_80AB10C

	thumb_func_start sub_80AB12C
sub_80AB12C:
	movs r2, 0xAA
	lsls r2, 1
	adds r0, r2
	str r1, [r0]
	bx lr
	thumb_func_end sub_80AB12C

	thumb_func_start sub_80AB138
sub_80AB138:
	movs r2, 0xA1
	lsls r2, 1
	adds r0, r2
	ldrb r0, [r0]
	strb r0, [r1]
	bx lr
	thumb_func_end sub_80AB138

	thumb_func_start sub_80AB144
sub_80AB144:
	push {lr}
	adds r3, r0, 0
	lsls r1, 24
	asrs r1, 24
	movs r0, 0x1
	negs r0, r0
	cmp r1, r0
	beq _080AB17C
	movs r0, 0xA1
	lsls r0, 1
	adds r2, r3, r0
	lsls r0, r1, 24
	lsrs r0, 24
	strb r0, [r2]
	ldr r2, _080AB180
	adds r1, r3, r2
	ldrb r1, [r1]
	lsls r1, 24
	asrs r1, 24
	lsls r0, 24
	asrs r0, 24
	cmp r1, r0
	beq _080AB17C
	movs r0, 0xAE
	lsls r0, 1
	adds r1, r3, r0
	movs r0, 0x1
	strb r0, [r1]
_080AB17C:
	pop {r0}
	bx r0
	.align 2, 0
_080AB180: .4byte 0x0000015d
	thumb_func_end sub_80AB144

	thumb_func_start sub_80AB184
sub_80AB184:
	push {lr}
	lsls r1, 16
	lsrs r1, 16
	bl sub_80A9750
	pop {r0}
	bx r0
	thumb_func_end sub_80AB184

	thumb_func_start sub_80AB194
sub_80AB194:
	push {lr}
	mov r12, r0
	lsls r1, 16
	asrs r1, 16
	adds r3, r1, 0
	cmp r1, 0
	bne _080AB1A8
	movs r0, 0xE0
	lsls r0, 1
	adds r3, r0, 0
_080AB1A8:
	movs r0, 0xB5
	lsls r0, 1
	add r0, r12
	strh r3, [r0]
	movs r0, 0xB6
	lsls r0, 1
	add r0, r12
	str r2, [r0]
	pop {r0}
	bx r0
	thumb_func_end sub_80AB194

	thumb_func_start nullsub_211
nullsub_211:
	bx lr
	thumb_func_end nullsub_211

	thumb_func_start sub_80AB1C0
sub_80AB1C0:
	push {lr}
	adds r1, r0, 0
	movs r2, 0xAE
	lsls r2, 1
	adds r0, r1, r2
	ldrb r0, [r0]
	cmp r0, 0
	bne _080AB1DE
	adds r2, 0x14
	adds r0, r1, r2
	bl sub_80A66F8
	lsls r0, 24
	lsrs r0, 24
	b _080AB1E0
_080AB1DE:
	movs r0, 0x1
_080AB1E0:
	pop {r1}
	bx r1
	thumb_func_end sub_80AB1C0

	thumb_func_start sub_80AB1E4
sub_80AB1E4:
	push {lr}
	adds r1, r0, 0
	movs r2, 0xB5
	lsls r2, 1
	adds r0, r1, r2
	movs r2, 0
	ldrsh r0, [r0, r2]
	cmp r0, 0
	bne _080AB206
	movs r2, 0xB8
	lsls r2, 1
	adds r0, r1, r2
	bl sub_80A671C
	lsls r0, 24
	lsrs r0, 24
	b _080AB208
_080AB206:
	movs r0, 0x1
_080AB208:
	pop {r1}
	bx r1
	thumb_func_end sub_80AB1E4

	thumb_func_start sub_80AB20C
sub_80AB20C:
	movs r2, 0x8E
	lsls r2, 1
	adds r0, r2
	ldr r0, [r0]
	str r0, [r1]
	bx lr
	thumb_func_end sub_80AB20C

	thumb_func_start sub_80AB218
sub_80AB218:
	push {lr}
	movs r2, 0
	ldrsh r0, [r0, r2]
	bl sub_80A86C8
	pop {r0}
	bx r0
	thumb_func_end sub_80AB218

	thumb_func_start sub_80AB228
sub_80AB228:
	push {lr}
	movs r2, 0
	ldrsh r0, [r0, r2]
	bl sub_80A8750
	pop {r0}
	bx r0
	thumb_func_end sub_80AB228

	thumb_func_start sub_80AB238
sub_80AB238:
	push {lr}
	movs r2, 0xB8
	lsls r2, 1
	adds r0, r2
	bl sub_80A6EC8
	pop {r0}
	bx r0
	thumb_func_end sub_80AB238

	thumb_func_start sub_80AB248
sub_80AB248:
	push {lr}
	bl sub_80A9F94
	pop {r1}
	bx r1
	thumb_func_end sub_80AB248

	thumb_func_start GroundLives_Action
GroundLives_Action:
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	sub sp, 0x3C
	ldr r0, _080AB29C
	ldr r5, [r0]
	movs r0, 0
	mov r9, r0
_080AB266:
	movs r2, 0x2
	ldrsh r1, [r5, r2]
	movs r3, 0x1
	negs r3, r3
	mov r8, r3
	adds r0, r3, 0
	cmp r1, r0
	bne _080AB278
	b _080AB47C
_080AB278:
	adds r4, r5, 0
	adds r4, 0x38
	ldr r1, _080AB2A0
	adds r0, r4, 0
	bl HandleAction
	lsls r0, 16
	asrs r3, r0, 16
	cmp r3, 0
	beq _080AB2A4
	cmp r3, 0x4
	beq _080AB292
	b _080AB44C
_080AB292:
	mov r0, r9
	bl GroundLives_Delete
	b _080AB47C
	.align 2, 0
_080AB29C: .4byte gUnknown_3001B84
_080AB2A0: .4byte gUnknown_8118280
_080AB2A4:
	movs r0, 0x8E
	lsls r0, 1
	adds r2, r5, r0
	ldr r1, [r2]
	movs r0, 0x80
	lsls r0, 4
	ands r0, r1
	cmp r0, 0
	bne _080AB2B8
	b _080AB42E
_080AB2B8:
	str r3, [sp, 0xC]
	add r0, sp, 0x8
	mov r1, r8
	strb r1, [r0]
	str r3, [sp, 0x10]
	movs r3, 0x90
	lsls r3, 1
	adds r0, r5, r3
	add r1, sp, 0xC
	add r3, sp, 0x10
	add r4, sp, 0x14
	str r4, [sp]
	ldr r2, [r2]
	str r2, [sp, 0x4]
	add r2, sp, 0x8
	bl sub_809CDC8
	subs r0, 0x1
	mov r8, r4
	cmp r0, 0x7
	bls _080AB2E4
	b _080AB44C
_080AB2E4:
	lsls r0, 2
	ldr r1, _080AB2F0
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080AB2F0: .4byte _080AB2F4
	.align 2, 0
_080AB2F4:
	.4byte _080AB314
	.4byte _080AB314
	.4byte _080AB326
	.4byte _080AB44C
	.4byte _080AB314
	.4byte _080AB44C
	.4byte _080AB44C
	.4byte _080AB314
_080AB314:
	ldr r1, [sp, 0xC]
	add r0, sp, 0x8
	movs r2, 0
	ldrsb r2, [r0, r2]
	ldr r3, [sp, 0x10]
	adds r0, r5, 0
	bl sub_80AAAE8
	b _080AB44C
_080AB326:
	add r4, sp, 0x1C
	adds r0, r4, 0
	bl sub_809D248
	ldr r1, [sp, 0x1C]
	ldr r0, [sp, 0x14]
	adds r6, r1, r0
	ldr r1, [r4, 0x4]
	mov r2, r8
	ldr r0, [r2, 0x4]
	adds r7, r1, r0
	movs r3, 0xA2
	lsls r3, 1
	adds r0, r5, r3
	ldr r1, [r0]
	ldr r0, [r5, 0x14]
	adds r0, r1, r0
	cmp r0, 0
	bge _080AB34E
	adds r0, 0xFF
_080AB34E:
	asrs r0, 8
	subs r0, r6, r0
	str r0, [sp, 0x24]
	movs r1, 0xA4
	lsls r1, 1
	adds r0, r5, r1
	ldr r1, [r0]
	ldr r0, [r5, 0x18]
	adds r0, r1, r0
	cmp r0, 0
	bge _080AB366
	adds r0, 0xFF
_080AB366:
	asrs r0, 8
	subs r0, r7, r0
	add r1, sp, 0x24
	str r0, [r1, 0x4]
	adds r0, r6, 0
	subs r0, 0x10
	lsls r0, 8
	str r0, [sp, 0x2C]
	adds r0, r6, 0
	adds r0, 0x10
	lsls r0, 8
	str r0, [sp, 0x34]
	subs r0, r7, 0x4
	lsls r0, 8
	add r2, sp, 0x2C
	str r0, [r2, 0x4]
	adds r0, r7, 0
	adds r0, 0x1C
	lsls r0, 8
	add r3, sp, 0x34
	str r0, [r3, 0x4]
	ldr r0, [sp, 0xC]
	adds r4, r1, 0
	cmp r0, 0xC
	bne _080AB3C4
	adds r0, r5, 0
	movs r1, 0xC
	bl sub_80AA180
	cmp r0, 0
	bne _080AB44C
	ldr r0, [sp, 0x24]
	adds r0, 0x10
	cmp r0, 0x20
	bhi _080AB44C
	movs r0, 0x1C
	negs r0, r0
	ldr r1, [r4, 0x4]
	cmp r1, r0
	blt _080AB44C
	cmp r1, 0x4
	bgt _080AB44C
	movs r2, 0x1
	negs r2, r2
	adds r0, r5, 0
	movs r1, 0x13
	b _080AB426
_080AB3C4:
	ldr r0, [sp, 0x24]
	adds r0, 0x10
	cmp r0, 0x20
	bhi _080AB3DA
	movs r0, 0x1C
	negs r0, r0
	ldr r1, [r4, 0x4]
	cmp r1, r0
	blt _080AB3DA
	cmp r1, 0x4
	ble _080AB44C
_080AB3DA:
	adds r0, r4, 0
	bl sub_8002C60
	add r1, sp, 0x8
	strb r0, [r1]
	lsls r0, 24
	movs r1, 0xFF
	lsls r1, 24
	cmp r0, r1
	beq _080AB44C
	ldr r0, [sp, 0xC]
	cmp r0, 0x11
	beq _080AB410
	cmp r0, 0x11
	bhi _080AB3FE
	cmp r0, 0x10
	beq _080AB404
	b _080AB44C
_080AB3FE:
	cmp r0, 0x12
	beq _080AB41C
	b _080AB44C
_080AB404:
	add r0, sp, 0x8
	movs r2, 0
	ldrsb r2, [r0, r2]
	adds r0, r5, 0
	movs r1, 0x6
	b _080AB426
_080AB410:
	add r0, sp, 0x8
	movs r2, 0
	ldrsb r2, [r0, r2]
	adds r0, r5, 0
	movs r1, 0x7
	b _080AB426
_080AB41C:
	add r0, sp, 0x8
	movs r2, 0
	ldrsb r2, [r0, r2]
	adds r0, r5, 0
	movs r1, 0x8
_080AB426:
	movs r3, 0
	bl sub_80AAAE8
	b _080AB44C
_080AB42E:
	movs r0, 0x80
	lsls r0, 5
	ands r1, r0
	cmp r1, 0
	beq _080AB440
	adds r0, r5, 0
	bl sub_80AB5D4
	b _080AB44C
_080AB440:
	ldr r3, _080AB4C4
	adds r0, r4, 0
	movs r1, 0
	movs r2, 0x1
	bl sub_809D8C0
_080AB44C:
	movs r2, 0xAE
	lsls r2, 1
	adds r1, r5, r2
	ldrb r0, [r1]
	cmp r0, 0
	beq _080AB47C
	movs r0, 0
	strb r0, [r1]
	movs r3, 0xB8
	lsls r3, 1
	adds r0, r5, r3
	adds r2, 0xC
	adds r1, r5, r2
	movs r3, 0
	ldrsh r1, [r1, r3]
	subs r2, 0x26
	adds r4, r5, r2
	ldrb r2, [r4]
	ldr r3, _080AB4C8
	strb r2, [r3, r5]
	movs r2, 0
	ldrsb r2, [r4, r2]
	bl sub_80A6EFC
_080AB47C:
	mov r0, r9
	adds r0, 0x1
	lsls r0, 16
	asrs r0, 16
	mov r9, r0
	movs r0, 0xF8
	lsls r0, 1
	adds r5, r0
	mov r1, r9
	cmp r1, 0x17
	bgt _080AB494
	b _080AB266
_080AB494:
	ldr r0, _080AB4CC
	ldr r6, [r0]
	ldr r0, _080AB4D0
	ldr r5, [r0]
	movs r0, 0
	str r0, [r6]
	str r0, [r6, 0x4]
	movs r2, 0x2
	ldrsh r1, [r5, r2]
	subs r0, 0x1
	cmp r1, r0
	beq _080AB4BE
	movs r3, 0x8E
	lsls r3, 1
	adds r0, r5, r3
	ldr r1, [r0]
	movs r3, 0x80
	lsls r3, 6
	ands r3, r1
	cmp r3, 0
	beq _080AB4D4
_080AB4BE:
	bl sub_80AB5A4
	b _080AB594
	.align 2, 0
_080AB4C4: .4byte gUnknown_811828C
_080AB4C8: .4byte 0x0000015d
_080AB4CC: .4byte gUnknown_3001B80
_080AB4D0: .4byte gUnknown_3001B84
_080AB4D4:
	movs r0, 0x80
	lsls r0, 5
	ands r1, r0
	cmp r1, 0
	beq _080AB590
	ldr r7, [r6, 0x24]
	cmp r7, 0
	bge _080AB51E
	adds r2, r6, 0
	adds r2, 0x2C
	str r3, [r6, 0x24]
	str r3, [r6, 0x2C]
	movs r1, 0xA2
	lsls r1, 1
	adds r0, r5, r1
	ldr r0, [r0]
	ldr r1, [r5, 0x14]
	adds r0, r1
	str r0, [r2, 0x4]
	movs r3, 0xA4
	lsls r3, 1
	adds r0, r5, r3
	ldr r0, [r0]
	ldr r1, [r5, 0x18]
	adds r0, r1
	str r0, [r2, 0x8]
	adds r0, r6, 0
	movs r2, 0
	movs r1, 0x2
_080AB50E:
	str r2, [r0, 0x8]
	str r2, [r0]
	str r2, [r0, 0x4]
	subs r1, 0x1
	adds r0, 0xC
	cmp r1, 0
	bge _080AB50E
	b _080AB594
_080AB51E:
	adds r2, r7, 0x1
	adds r0, r2, 0
	cmp r2, 0
	bge _080AB52A
	adds r0, r7, 0
	adds r0, 0x40
_080AB52A:
	asrs r1, r0, 6
	lsls r0, r1, 6
	subs r1, r2, r0
	str r1, [r6, 0x24]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 2
	adds r0, 0x2C
	adds r0, r6
	mov r8, r0
	movs r1, 0xA2
	lsls r1, 1
	adds r0, r5, r1
	ldr r2, [r0]
	ldr r0, [r5, 0x14]
	adds r2, r0
	mov r3, r8
	str r2, [r3, 0x4]
	adds r1, 0x4
	adds r0, r5, r1
	ldr r1, [r0]
	ldr r0, [r5, 0x18]
	adds r1, r0
	str r1, [r3, 0x8]
	lsls r0, r7, 1
	adds r0, r7
	lsls r0, 2
	adds r0, 0x2C
	adds r0, r6, r0
	ldr r3, [r0, 0x4]
	ldr r0, [r0, 0x8]
	subs r0, r1, r0
	subs r2, r3
	cmp r2, 0
	bge _080AB572
	negs r2, r2
_080AB572:
	adds r4, r2, 0
	cmp r0, 0
	bge _080AB57A
	negs r0, r0
_080AB57A:
	cmp r0, r4
	bge _080AB580
	adds r0, r2, 0
_080AB580:
	mov r2, r8
	str r0, [r2]
	cmp r0, 0
	bgt _080AB58C
	str r7, [r6, 0x24]
	b _080AB594
_080AB58C:
	str r0, [r6]
	b _080AB594
_080AB590:
	bl sub_80AB5A4
_080AB594:
	add sp, 0x3C
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end GroundLives_Action

	thumb_func_start sub_80AB5A4
sub_80AB5A4:
	push {lr}
	ldr r3, _080AB5D0
	ldr r0, [r3]
	movs r2, 0x1
	negs r2, r2
	str r2, [r0, 0x24]
	adds r0, 0x28
	movs r1, 0xFF
	strb r1, [r0]
	ldr r3, [r3]
	movs r1, 0
	movs r0, 0x2
_080AB5BC:
	str r2, [r3, 0x8]
	str r1, [r3]
	str r1, [r3, 0x4]
	subs r0, 0x1
	adds r3, 0xC
	cmp r0, 0
	bge _080AB5BC
	pop {r0}
	bx r0
	.align 2, 0
_080AB5D0: .4byte gUnknown_3001B80
	thumb_func_end sub_80AB5A4

	thumb_func_start sub_80AB5D4
sub_80AB5D4:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x2C
	mov r9, r0
	ldr r4, _080AB6BC
	movs r2, 0x9E
	lsls r2, 1
	add r2, r9
	movs r0, 0
	ldrsh r1, [r2, r0]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 2
	ldr r3, [r4]
	adds r0, r3
	mov r8, r0
	adds r0, r1, 0
	adds r5, r4, 0
	cmp r0, 0
	bne _080AB604
	b _080AB9E6
_080AB604:
	movs r1, 0xAF
	lsls r1, 1
	add r1, r9
	movs r0, 0xC0
	lsls r0, 2
	strh r0, [r1]
	movs r1, 0xB0
	lsls r1, 1
	add r1, r9
	movs r0, 0x1
	strh r0, [r1]
	movs r0, 0x8E
	lsls r0, 1
	add r0, r9
	ldr r2, [r0]
	movs r0, 0x80
	lsls r0, 6
	ands r2, r0
	cmp r2, 0
	beq _080AB6D4
	movs r2, 0xA1
	lsls r2, 1
	add r2, r9
	movs r0, 0
	ldrsb r0, [r2, r0]
	cmp r0, 0x4
	bne _080AB64C
	movs r0, 0xB4
	lsls r0, 1
	add r0, r9
	movs r3, 0
	ldrsh r1, [r0, r3]
	movs r0, 0x80
	lsls r0, 4
	cmp r1, r0
	beq _080AB670
_080AB64C:
	movs r1, 0xB2
	lsls r1, 1
	add r1, r9
	movs r0, 0
	str r0, [r1]
	movs r1, 0xB4
	lsls r1, 1
	add r1, r9
	movs r0, 0x80
	lsls r0, 4
	strh r0, [r1]
	movs r0, 0x4
	strb r0, [r2]
	movs r1, 0xAE
	lsls r1, 1
	add r1, r9
	movs r0, 0x1
	strb r0, [r1]
_080AB670:
	ldr r0, [r5]
	adds r2, r0, 0
	adds r2, 0x28
	movs r1, 0
	ldrsb r1, [r2, r1]
	movs r0, 0x1
	negs r0, r0
	cmp r1, r0
	beq _080AB69C
	movs r2, 0x80
	lsls r2, 1
	mov r0, sp
	bl sub_8002BB8
	ldr r0, [sp]
	ldr r1, [sp, 0x4]
	str r0, [sp, 0x8]
	str r1, [sp, 0xC]
	add r1, sp, 0x8
	mov r0, r9
	bl sub_80A9F94
_080AB69C:
	mov r4, r8
	ldr r0, [r4, 0x8]
	cmp r0, 0
	blt _080AB6A6
	b _080AB9E6
_080AB6A6:
	ldr r0, [r5]
	ldr r0, [r0, 0x24]
	cmp r0, 0
	bge _080AB6B0
	b _080AB9E6
_080AB6B0:
	str r0, [r4, 0x8]
	movs r0, 0
	str r0, [r4]
	str r0, [r4, 0x4]
	b _080AB9E6
	.align 2, 0
_080AB6BC: .4byte gUnknown_3001B80
_080AB6C0:
	ldr r5, [sp, 0x28]
	ldr r0, [r5, 0x4]
	adds r0, r7, r0
	str r0, [r5, 0x4]
	b _080AB7E2
_080AB6CA:
	ldr r1, [sp, 0x28]
	ldr r0, [r1, 0x4]
	subs r0, r7
	str r0, [r1, 0x4]
	b _080AB7E2
_080AB6D4:
	movs r0, 0xA2
	lsls r0, 1
	add r0, r9
	ldr r1, [r0]
	mov r5, r9
	ldr r0, [r5, 0x14]
	adds r0, r1, r0
	str r0, [sp, 0x20]
	movs r0, 0xA4
	lsls r0, 1
	add r0, r9
	ldr r1, [r0]
	ldr r0, [r5, 0x18]
	adds r0, r1, r0
	str r0, [sp, 0x24]
	ldr r0, [sp, 0x20]
	ldr r1, [sp, 0x24]
	str r0, [sp, 0x10]
	str r1, [sp, 0x14]
	mov r1, r8
	ldr r0, [r1, 0x8]
	cmp r0, 0
	bge _080AB710
	ldr r0, [r3, 0x24]
	cmp r0, 0
	bge _080AB70A
	b _080AB9E6
_080AB70A:
	str r0, [r1, 0x8]
	str r2, [r1]
	str r2, [r1, 0x4]
_080AB710:
	mov r2, r8
	ldr r7, [r2]
	movs r3, 0x1
	mov r10, r3
	mov r5, sp
	adds r5, 0x10
	str r5, [sp, 0x28]
_080AB71E:
	mov r0, r8
	ldr r1, [r0, 0x8]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 2
	adds r0, 0x2C
	ldr r2, _080AB754
	ldr r1, [r2]
	adds r1, r0
	mov r12, r1
	ldr r6, [r1, 0x4]
	ldr r5, [sp, 0x10]
	subs r4, r6, r5
	adds r2, r4, 0
	ldr r1, [r1, 0x8]
	ldr r0, [sp, 0x14]
	subs r3, r1, r0
	cmp r4, 0
	ble _080AB75E
	cmp r2, r7
	ble _080AB758
	adds r0, r7, r5
	str r0, [sp, 0x10]
	movs r4, 0
	mov r10, r4
	b _080AB75A
	.align 2, 0
_080AB754: .4byte gUnknown_3001B80
_080AB758:
	str r6, [sp, 0x10]
_080AB75A:
	adds r1, r2, 0
	b _080AB778
_080AB75E:
	cmp r4, 0
	bge _080AB776
	cmn r2, r7
	bge _080AB770
	subs r0, r5, r7
	str r0, [sp, 0x10]
	movs r5, 0
	mov r10, r5
	b _080AB772
_080AB770:
	str r6, [sp, 0x10]
_080AB772:
	negs r1, r2
	b _080AB778
_080AB776:
	movs r1, 0
_080AB778:
	cmp r3, 0
	ble _080AB78E
	cmp r3, r7
	bgt _080AB6C0
	mov r4, r12
	ldr r0, [r4, 0x8]
	str r0, [sp, 0x14]
	cmp r3, r1
	ble _080AB7A2
	adds r1, r3, 0
	b _080AB7A2
_080AB78E:
	cmp r3, 0
	bge _080AB7A2
	cmn r3, r7
	blt _080AB6CA
	mov r5, r12
	ldr r0, [r5, 0x8]
	str r0, [sp, 0x14]
	cmn r3, r1
	bge _080AB7A2
	negs r1, r3
_080AB7A2:
	mov r0, r10
	cmp r0, 0
	beq _080AB7E2
	subs r7, r1
	cmp r7, 0
	ble _080AB7E2
	ldr r1, _080AB7D4
	ldr r0, [r1]
	mov r3, r8
	ldr r2, [r3, 0x8]
	ldr r0, [r0, 0x24]
	cmp r2, r0
	beq _080AB7D8
	adds r1, r2, 0x1
	adds r0, r1, 0
	cmp r1, 0
	bge _080AB7C8
	adds r0, r2, 0
	adds r0, 0x40
_080AB7C8:
	asrs r0, 6
	lsls r0, 6
	subs r0, r1, r0
	mov r4, r8
	str r0, [r4, 0x8]
	b _080AB7DC
	.align 2, 0
_080AB7D4: .4byte gUnknown_3001B80
_080AB7D8:
	movs r5, 0
	mov r10, r5
_080AB7DC:
	mov r0, r10
	cmp r0, 0
	bne _080AB71E
_080AB7E2:
	mov r1, r8
	ldr r0, [r1, 0x8]
	bl sub_80ABA00
	adds r6, r0, 0
	ldr r0, _080AB860
	ldr r7, [r0]
	movs r2, 0x9E
	lsls r2, 1
	add r2, r9
	mov r10, r2
	movs r3, 0
	ldrsh r2, [r2, r3]
	subs r1, r2, 0x1
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 2
	adds r1, r7, 0x4
	adds r1, r0
	ldr r0, _080AB864
	lsls r2, 2
	adds r2, r0
	ldr r1, [r1]
	ldr r0, [r2]
	adds r1, r0
	mov r12, r1
	mov r4, r8
	ldr r1, [r4, 0x8]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 2
	adds r0, 0x2C
	adds r0, r7, r0
	ldr r3, [r0, 0x4]
	ldr r2, [sp, 0x10]
	ldr r1, [r0, 0x8]
	ldr r5, [sp, 0x28]
	ldr r0, [r5, 0x4]
	subs r1, r0
	subs r3, r2
	cmp r3, 0
	bge _080AB838
	negs r3, r3
_080AB838:
	adds r4, r3, 0
	cmp r1, 0
	bge _080AB840
	negs r1, r1
_080AB840:
	cmp r1, r4
	bge _080AB846
	adds r1, r3, 0
_080AB846:
	adds r6, r1
	mov r0, r8
	str r6, [r0, 0x4]
	cmp r6, r12
	bgt _080AB86C
	ldr r0, [r0]
	cmp r0, 0
	ble _080AB8B2
	ldr r1, _080AB868
	adds r0, r1
	mov r2, r8
	b _080AB8B0
	.align 2, 0
_080AB860: .4byte gUnknown_3001B80
_080AB864: .4byte gUnknown_8118050
_080AB868: .4byte 0xffffff00
_080AB86C:
	mov r3, r10
	movs r4, 0
	ldrsh r1, [r3, r4]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 11
	cmp r6, r0
	bgt _080AB88E
	mov r5, r8
	ldr r0, [r5]
	cmp r0, 0xFF
	bgt _080AB8B2
	movs r1, 0x80
	lsls r1, 1
	adds r0, r1
	str r0, [r5]
	b _080AB8B2
_080AB88E:
	subs r1, 0x1
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 2
	adds r0, r7, r0
	ldr r0, [r0]
	cmp r0, 0xFF
	bgt _080AB8A2
	movs r0, 0x80
	lsls r0, 1
_080AB8A2:
	mov r2, r8
	ldr r1, [r2]
	cmp r1, r0
	bge _080AB8B2
	movs r3, 0x80
	lsls r3, 1
	adds r0, r1, r3
_080AB8B0:
	str r0, [r2]
_080AB8B2:
	ldr r0, _080AB96C
	ldr r3, [r0]
	mov r4, r8
	ldr r0, [r4, 0x8]
	subs r0, 0x40
	ldr r2, [r3, 0x24]
	subs r1, r2, r0
	adds r0, r1, 0
	cmp r1, 0
	bge _080AB8C8
	adds r0, 0x3F
_080AB8C8:
	asrs r0, 6
	lsls r0, 6
	subs r0, r1, r0
	cmp r0, 0x3B
	ble _080AB8FC
	adds r1, r2, 0x5
	adds r0, r1, 0
	cmp r1, 0
	bge _080AB8DE
	adds r0, r2, 0
	adds r0, 0x44
_080AB8DE:
	asrs r0, 6
	lsls r0, 6
	subs r0, r1, r0
	mov r5, r8
	str r0, [r5, 0x8]
	lsls r1, r0, 1
	adds r1, r0
	lsls r1, 2
	adds r0, r3, 0
	adds r0, 0x30
	adds r0, r1
	ldr r1, [r0, 0x4]
	ldr r0, [r0]
	str r0, [sp, 0x10]
	str r1, [sp, 0x14]
_080AB8FC:
	mov r0, r9
	ldr r1, [sp, 0x28]
	bl sub_80A9F20
	adds r6, r0, 0
	cmp r6, 0
	bne _080AB9E6
	ldr r0, [sp, 0x10]
	ldr r1, [sp, 0x20]
	subs r0, r1
	str r0, [sp, 0x18]
	ldr r2, [sp, 0x28]
	ldr r1, [r2, 0x4]
	ldr r3, [sp, 0x24]
	subs r1, r3
	add r0, sp, 0x18
	str r1, [r0, 0x4]
	movs r5, 0xA1
	lsls r5, 1
	add r5, r9
	movs r4, 0
	ldrsb r4, [r5, r4]
	bl sub_8002C60
	adds r1, r0, 0
	lsls r1, 24
	asrs r1, 24
	adds r0, r4, 0
	bl sub_8002B04
	strb r0, [r5]
	mov r4, r8
	ldr r0, [r4]
	cmp r0, 0
	ble _080AB970
	movs r1, 0xB2
	lsls r1, 1
	add r1, r9
	movs r0, 0x4
	str r0, [r1]
	ldr r1, [r4]
	movs r0, 0x80
	lsls r0, 2
	movs r2, 0x80
	lsls r2, 4
	cmp r1, r0
	ble _080AB95E
	movs r2, 0xA0
	lsls r2, 4
_080AB95E:
	adds r4, r2, 0
	mov r0, r9
	movs r1, 0x1
	bl sub_80AAF68
	b _080AB982
	.align 2, 0
_080AB96C: .4byte gUnknown_3001B80
_080AB970:
	ldr r4, _080AB9F8
	movs r0, 0xB2
	lsls r0, 1
	add r0, r9
	str r6, [r0]
	mov r0, r9
	movs r1, 0
	bl sub_80AAF68
_080AB982:
	movs r0, 0xAE
	lsls r0, 1
	add r0, r9
	ldrb r0, [r0]
	cmp r0, 0
	bne _080AB9B6
	movs r0, 0xB4
	lsls r0, 1
	add r0, r9
	movs r5, 0
	ldrsh r0, [r0, r5]
	cmp r4, r0
	bne _080AB9B6
	ldr r1, _080AB9FC
	add r1, r9
	movs r0, 0xA1
	lsls r0, 1
	add r0, r9
	ldrb r1, [r1]
	lsls r1, 24
	asrs r1, 24
	ldrb r0, [r0]
	lsls r0, 24
	asrs r0, 24
	cmp r1, r0
	beq _080AB9E6
_080AB9B6:
	movs r1, 0xAE
	lsls r1, 1
	add r1, r9
	movs r0, 0
	strb r0, [r1]
	movs r0, 0xB8
	lsls r0, 1
	add r0, r9
	movs r1, 0xB4
	lsls r1, 1
	add r1, r9
	strh r4, [r1]
	movs r3, 0xA1
	lsls r3, 1
	add r3, r9
	ldrb r1, [r3]
	ldr r2, _080AB9FC
	add r2, r9
	strb r1, [r2]
	movs r2, 0
	ldrsb r2, [r3, r2]
	adds r1, r4, 0
	bl sub_80A6EFC
_080AB9E6:
	add sp, 0x2C
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_080AB9F8: .4byte 0x00000807
_080AB9FC: .4byte 0x0000015d
	thumb_func_end sub_80AB5D4

	thumb_func_start sub_80ABA00
sub_80ABA00:
	push {r4,r5,lr}
	adds r1, r0, 0
	movs r4, 0
	ldr r0, _080ABA34
	ldr r2, [r0]
	ldr r3, [r2, 0x24]
	adds r5, r0, 0
	cmp r3, r1
	ble _080ABA38
	adds r1, 0x1
	cmp r1, r3
	bge _080ABA72
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 2
	adds r0, 0x2C
	adds r2, r0, r2
	subs r1, r3, r1
_080ABA24:
	ldr r0, [r2]
	adds r4, r0
	adds r2, 0xC
	subs r1, 0x1
	cmp r1, 0
	bne _080ABA24
	b _080ABA72
	.align 2, 0
_080ABA34: .4byte gUnknown_3001B80
_080ABA38:
	cmp r3, r1
	bge _080ABA72
	adds r1, 0x1
	cmp r1, 0x3F
	bgt _080ABA58
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 2
	adds r0, 0x2C
	adds r2, r0, r2
_080ABA4C:
	ldr r0, [r2]
	adds r4, r0
	adds r2, 0xC
	adds r1, 0x1
	cmp r1, 0x3F
	ble _080ABA4C
_080ABA58:
	ldr r1, [r5]
	ldr r0, [r1, 0x24]
	cmp r0, 0
	ble _080ABA72
	adds r2, r1, 0
	adds r2, 0x2C
	adds r1, r0, 0
_080ABA66:
	ldr r0, [r2]
	adds r4, r0
	adds r2, 0xC
	subs r1, 0x1
	cmp r1, 0
	bne _080ABA66
_080ABA72:
	adds r0, r4, 0
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_80ABA00

	thumb_func_start sub_80ABA7C
sub_80ABA7C:
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	sub sp, 0x8
	ldr r0, _080ABB50
	ldr r5, [r0]
	movs r0, 0
	mov r8, r0
	movs r1, 0xA2
	lsls r1, 1
	adds r4, r5, r1
	movs r2, 0x1
	negs r2, r2
	mov r9, r2
_080ABA9A:
	movs r1, 0x2
	ldrsh r0, [r5, r1]
	cmp r0, r9
	beq _080ABB2C
	ldr r0, [r4]
	ldr r1, [r5, 0x14]
	adds r0, r1
	str r0, [sp]
	ldr r0, [r4, 0x4]
	ldr r1, [r5, 0x18]
	adds r0, r1
	str r0, [sp, 0x4]
	ldr r1, [r4, 0x10]
	ldr r0, [r4, 0x14]
	adds r7, r1, r0
	ldr r0, [r4, 0x20]
	cmp r0, 0
	ble _080ABADA
	subs r0, 0x1
	str r0, [r4, 0x20]
	cmp r0, 0
	bgt _080ABADA
	ldrh r0, [r4, 0x1C]
	subs r0, 0x1
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0x1
	bhi _080ABADA
	ldrh r1, [r4, 0x1C]
	adds r0, r5, 0
	bl sub_80A9750
_080ABADA:
	movs r2, 0xB8
	lsls r2, 1
	adds r6, r5, r2
	adds r0, r6, 0
	bl sub_80A66D4
	lsls r0, 24
	cmp r0, 0
	beq _080ABAFE
	movs r0, 0
	strb r0, [r4, 0x18]
	movs r0, 0x24
	ldrsh r1, [r4, r0]
	movs r2, 0x19
	ldrsb r2, [r4, r2]
	adds r0, r6, 0
	bl sub_80A6EFC
_080ABAFE:
	movs r1, 0x26
	ldrsh r0, [r4, r1]
	cmp r0, 0
	beq _080ABB1E
	adds r1, r0, 0
	movs r2, 0xA1
	lsls r2, 1
	adds r0, r5, r2
	movs r2, 0
	ldrsb r2, [r0, r2]
	ldr r3, [r4, 0x28]
	adds r0, r6, 0
	bl sub_80A74F0
	movs r0, 0
	strh r0, [r4, 0x26]
_080ABB1E:
	movs r0, 0x8
	ldrsh r1, [r5, r0]
	adds r0, r6, 0
	mov r2, sp
	adds r3, r7, 0
	bl sub_80A7524
_080ABB2C:
	mov r0, r8
	adds r0, 0x1
	lsls r0, 16
	asrs r0, 16
	mov r8, r0
	movs r1, 0xF8
	lsls r1, 1
	adds r4, r1
	adds r5, r1
	cmp r0, 0x17
	ble _080ABA9A
	add sp, 0x8
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_080ABB50: .4byte gUnknown_3001B84
	thumb_func_end sub_80ABA7C

	thumb_func_start sub_80ABB54
sub_80ABB54:
	push {r4,r5,lr}
	ldr r4, _080ABB90
	movs r0, 0xE2
	lsls r0, 5
	movs r1, 0x6
	bl MemoryAlloc
	str r0, [r4]
	adds r1, r0, 0
	ldr r0, _080ABB94
	adds r5, r0, 0
	movs r4, 0xE2
	lsls r4, 1
	movs r2, 0x80
	lsls r2, 9
	adds r3, r2, 0
_080ABB74:
	ldrh r0, [r1, 0x6]
	orrs r0, r5
	strh r0, [r1, 0x6]
	adds r0, r2, 0
	adds r2, r3
	asrs r0, 16
	adds r1, r4
	cmp r0, 0xF
	ble _080ABB74
	bl sub_80ABB98
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_080ABB90: .4byte gUnknown_3001B88
_080ABB94: .4byte 0x0000ffff
	thumb_func_end sub_80ABB54

	thumb_func_start sub_80ABB98
sub_80ABB98:
	push {r4-r6,lr}
	ldr r0, _080ABBD0
	ldr r4, [r0]
	movs r1, 0
	movs r6, 0x1
	negs r6, r6
	movs r5, 0x80
	lsls r5, 9
_080ABBA8:
	movs r2, 0x6
	ldrsh r0, [r4, r2]
	cmp r0, r6
	beq _080ABBB6
	adds r0, r1, 0
	bl GroundObject_Delete
_080ABBB6:
	adds r0, r5, 0
	movs r1, 0x80
	lsls r1, 9
	adds r5, r1
	asrs r1, r0, 16
	movs r2, 0xE2
	lsls r2, 1
	adds r4, r2
	cmp r1, 0xF
	ble _080ABBA8
	pop {r4-r6}
	pop {r0}
	bx r0
	.align 2, 0
_080ABBD0: .4byte gUnknown_3001B88
	thumb_func_end sub_80ABB98

	thumb_func_start sub_80ABBD4
sub_80ABBD4:
	push {r4,lr}
	bl sub_80ABB98
	ldr r4, _080ABBEC
	ldr r0, [r4]
	bl MemoryFree
	movs r0, 0
	str r0, [r4]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080ABBEC: .4byte gUnknown_3001B88
	thumb_func_end sub_80ABBD4

	thumb_func_start GroundObject_Select
GroundObject_Select:
	push {r4-r7,lr}
	sub sp, 0x4
	adds r4, r0, 0
	lsls r4, 16
	asrs r4, 16
	lsls r1, 16
	asrs r7, r1, 16
	lsls r2, 24
	asrs r6, r2, 24
	ldr r1, _080ABC54
	adds r0, r4, 0
	bl sub_80A77D0
	adds r5, r0, 0
	ldr r1, _080ABC58
	str r6, [sp]
	movs r0, 0
	adds r2, r4, 0
	adds r3, r7, 0
	bl Log
	lsls r1, r7, 3
	ldr r0, [r5, 0x4]
	adds r0, r1
	lsls r1, r6, 2
	adds r1, r6
	lsls r1, 3
	ldr r0, [r0, 0x4]
	adds r0, r1
	ldr r5, [r0, 0xC]
	ldr r0, [r0, 0x8]
	cmp r0, 0
	ble _080ABC4A
	adds r4, r0, 0
_080ABC34:
	movs r0, 0x1
	negs r0, r0
	adds r1, r5, 0
	adds r2, r7, 0
	adds r3, r6, 0
	bl GroundObject_Add
	subs r4, 0x1
	adds r5, 0x18
	cmp r4, 0
	bne _080ABC34
_080ABC4A:
	add sp, 0x4
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_080ABC54: .4byte gUnknown_81183E4
_080ABC58: .4byte gUnknown_81183F0
	thumb_func_end GroundObject_Select

	thumb_func_start GroundObject_Cancel
GroundObject_Cancel:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	lsls r0, 16
	asrs r7, r0, 16
	lsls r1, 24
	asrs r5, r1, 24
	ldr r1, _080ABCC4
	movs r0, 0
	adds r2, r7, 0
	bl Log
	movs r1, 0
	ldr r0, _080ABCC8
	ldr r4, [r0]
	movs r0, 0x1
	negs r0, r0
	mov r8, r0
	movs r6, 0x80
	lsls r6, 9
_080ABC84:
	movs r2, 0x6
	ldrsh r0, [r4, r2]
	cmp r0, r8
	beq _080ABCA6
	movs r2, 0x8
	ldrsh r0, [r4, r2]
	cmp r0, r7
	bne _080ABCA6
	cmp r5, 0
	blt _080ABCA0
	movs r0, 0xA
	ldrsb r0, [r4, r0]
	cmp r0, r5
	bne _080ABCA6
_080ABCA0:
	adds r0, r1, 0
	bl GroundObject_Delete
_080ABCA6:
	adds r0, r6, 0
	movs r1, 0x80
	lsls r1, 9
	adds r6, r1
	asrs r1, r0, 16
	movs r2, 0xE2
	lsls r2, 1
	adds r4, r2
	cmp r1, 0xF
	ble _080ABC84
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_080ABCC4: .4byte gUnknown_8118414
_080ABCC8: .4byte gUnknown_3001B88
	thumb_func_end GroundObject_Cancel

	thumb_func_start GroundObject_CancelBlank
GroundObject_CancelBlank:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0x8
	ldr r1, _080ABD40
	movs r0, 0
	bl Log
	movs r6, 0
	ldr r0, _080ABD44
	ldr r4, [r0]
	movs r0, 0x1
	negs r0, r0
	mov r8, r0
	movs r1, 0x92
	lsls r1, 1
	adds r5, r4, r1
	mov r7, sp
_080ABCF0:
	movs r1, 0x6
	ldrsh r0, [r4, r1]
	cmp r0, r8
	beq _080ABD20
	ldr r0, [r5]
	ldr r1, [r4, 0x14]
	adds r0, r1
	str r0, [sp]
	ldr r0, [r5, 0x4]
	ldr r1, [r4, 0x18]
	adds r0, r1
	str r0, [r7, 0x4]
	movs r1, 0xA2
	lsls r1, 1
	adds r0, r4, r1
	mov r1, sp
	bl sub_80A675C
	lsls r0, 24
	cmp r0, 0
	bne _080ABD20
	adds r0, r6, 0
	bl GroundObject_Delete
_080ABD20:
	adds r0, r6, 0x1
	lsls r0, 16
	asrs r6, r0, 16
	movs r0, 0xE2
	lsls r0, 1
	adds r5, r0
	adds r4, r0
	cmp r6, 0xF
	ble _080ABCF0
	add sp, 0x8
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_080ABD40: .4byte gUnknown_811842C
_080ABD44: .4byte gUnknown_3001B88
	thumb_func_end GroundObject_CancelBlank

	thumb_func_start sub_80ABD48
sub_80ABD48:
	push {r4-r7,lr}
	lsls r0, 16
	asrs r4, r0, 16
	movs r3, 0
	ldr r0, _080ABD6C
	ldr r1, [r0]
	movs r6, 0xE2
	lsls r6, 1
	movs r2, 0x80
	lsls r2, 9
	adds r5, r2, 0
_080ABD5E:
	movs r7, 0x6
	ldrsh r0, [r1, r7]
	cmp r0, r4
	bne _080ABD70
	adds r0, r3, 0
	b _080ABD80
	.align 2, 0
_080ABD6C: .4byte gUnknown_3001B88
_080ABD70:
	adds r0, r2, 0
	adds r2, r5
	asrs r3, r0, 16
	adds r1, r6
	cmp r3, 0xF
	ble _080ABD5E
	movs r0, 0x1
	negs r0, r0
_080ABD80:
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_80ABD48

	thumb_func_start GroundObject_Add
GroundObject_Add:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x14
	mov r8, r1
	lsls r0, 16
	asrs r7, r0, 16
	lsls r2, 16
	asrs r2, 16
	mov r10, r2
	lsls r3, 24
	asrs r3, 24
	mov r9, r3
	ldrb r4, [r1]
	cmp r4, 0x1A
	bne _080ABDDA
	movs r0, 0
	movs r1, 0x28
	bl sub_8001658
	cmp r0, 0x1
	bgt _080ABDBC
	movs r4, 0x1B
	b _080ABDDA
_080ABDBC:
	movs r0, 0
	movs r1, 0x29
	bl sub_8001658
	cmp r0, 0
	bne _080ABDD4
	movs r0, 0
	movs r1, 0x27
	bl sub_8001658
	adds r0, 0x1C
	b _080ABDD6
_080ABDD4:
	adds r0, 0x2B
_080ABDD6:
	lsls r0, 16
	asrs r4, r0, 16
_080ABDDA:
	lsls r1, r4, 2
	ldr r0, _080ABE10
	adds r6, r1, r0
	cmp r7, 0
	bge _080ABE40
	cmp r4, 0xE
	bgt _080ABDF4
	cmp r4, 0xD
	blt _080ABDF4
	adds r0, r4, 0
	bl sub_80ABD48
	adds r7, r0, 0
_080ABDF4:
	cmp r7, 0
	bge _080ABE40
	movs r3, 0
	ldr r0, _080ABE14
	ldr r5, [r0]
	movs r0, 0x6
	ldrsh r1, [r5, r0]
	movs r0, 0x1
	negs r0, r0
	cmp r1, r0
	bne _080ABE18
	movs r7, 0
	b _080ABE40
	.align 2, 0
_080ABE10: .4byte gUnknown_811ED20
_080ABE14: .4byte gUnknown_3001B88
_080ABE18:
	adds r0, r3, 0x1
	lsls r0, 16
	asrs r3, r0, 16
	movs r1, 0xE2
	lsls r1, 1
	adds r5, r1
	cmp r3, 0xF
	bgt _080ABE36
	movs r2, 0x6
	ldrsh r1, [r5, r2]
	movs r0, 0x1
	negs r0, r0
	cmp r1, r0
	bne _080ABE18
	adds r7, r3, 0
_080ABE36:
	cmp r7, 0
	bge _080ABE40
	movs r0, 0x1
	negs r0, r0
	b _080AC142
_080ABE40:
	ldr r1, _080ABEA8
	lsls r0, r7, 3
	subs r0, r7
	lsls r0, 4
	adds r0, r7
	lsls r0, 2
	ldr r1, [r1]
	adds r5, r1, r0
	ldr r1, _080ABEAC
	mov r3, r8
	ldrb r0, [r3]
	str r0, [sp]
	movs r2, 0
	ldrsh r0, [r6, r2]
	str r0, [sp, 0x4]
	mov r3, r10
	str r3, [sp, 0x8]
	mov r0, r9
	str r0, [sp, 0xC]
	movs r0, 0
	adds r2, r7, 0
	adds r3, r4, 0
	bl Log
	movs r2, 0
	movs r3, 0x6
	ldrsh r1, [r5, r3]
	movs r0, 0x1
	negs r0, r0
	cmp r1, r0
	bne _080ABE80
	movs r2, 0x1
_080ABE80:
	str r2, [sp, 0x10]
	strh r7, [r5, 0x4]
	strh r4, [r5, 0x6]
	mov r0, r10
	strh r0, [r5, 0x8]
	mov r1, r9
	strb r1, [r5, 0xA]
	ldrh r0, [r6]
	subs r0, 0x1
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0xE
	bls _080ABE9C
	b _080ABF8C
_080ABE9C:
	lsls r0, 2
	ldr r1, _080ABEB0
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080ABEA8: .4byte gUnknown_3001B88
_080ABEAC: .4byte gUnknown_8118448
_080ABEB0: .4byte _080ABEB4
	.align 2, 0
_080ABEB4:
	.4byte _080ABEF0
	.4byte _080ABF7C
	.4byte _080ABF46
	.4byte _080ABF54
	.4byte _080ABF54
	.4byte _080ABF5E
	.4byte _080ABF68
	.4byte _080ABF72
	.4byte _080ABF3C
	.4byte _080ABEFA
	.4byte _080ABEF0
	.4byte _080ABF06
	.4byte _080ABF2C
	.4byte _080ABF1E
	.4byte _080ABF12
_080ABEF0:
	movs r2, 0x8E
	lsls r2, 1
	adds r1, r5, r2
	movs r0, 0
	b _080ABF94
_080ABEFA:
	movs r3, 0x8E
	lsls r3, 1
	adds r1, r5, r3
	movs r0, 0x80
	lsls r0, 10
	b _080ABF94
_080ABF06:
	movs r0, 0x8E
	lsls r0, 1
	adds r1, r5, r0
	movs r0, 0x80
	lsls r0, 11
	b _080ABF94
_080ABF12:
	movs r2, 0x8E
	lsls r2, 1
	adds r1, r5, r2
	movs r0, 0x83
	lsls r0, 18
	b _080ABF94
_080ABF1E:
	movs r3, 0x8E
	lsls r3, 1
	adds r1, r5, r3
	ldr r0, _080ABF28
	b _080ABF94
	.align 2, 0
_080ABF28: .4byte 0x220c0000
_080ABF2C:
	movs r0, 0x8E
	lsls r0, 1
	adds r1, r5, r0
	ldr r0, _080ABF38
	b _080ABF94
	.align 2, 0
_080ABF38: .4byte 0x20010000
_080ABF3C:
	movs r2, 0x8E
	lsls r2, 1
	adds r1, r5, r2
	movs r0, 0x5
	b _080ABF94
_080ABF46:
	movs r3, 0x8E
	lsls r3, 1
	adds r1, r5, r3
	ldr r0, _080ABF50
	b _080ABF94
	.align 2, 0
_080ABF50: .4byte 0x22000184
_080ABF54:
	movs r0, 0x8E
	lsls r0, 1
	adds r1, r5, r0
	adds r0, 0x68
	b _080ABF94
_080ABF5E:
	movs r2, 0x8E
	lsls r2, 1
	adds r1, r5, r2
	movs r0, 0x44
	b _080ABF94
_080ABF68:
	movs r3, 0x8E
	lsls r3, 1
	adds r1, r5, r3
	movs r0, 0x84
	b _080ABF94
_080ABF72:
	movs r0, 0x8E
	lsls r0, 1
	adds r1, r5, r0
	adds r0, 0x64
	b _080ABF94
_080ABF7C:
	movs r2, 0x8E
	lsls r2, 1
	adds r1, r5, r2
	ldr r0, _080ABF88
	b _080ABF94
	.align 2, 0
_080ABF88: .4byte 0x020000c4
_080ABF8C:
	movs r3, 0x8E
	lsls r3, 1
	adds r1, r5, r3
	ldr r0, _080ABFA8
_080ABF94:
	str r0, [r1]
	ldrb r0, [r6, 0x2]
	cmp r0, 0
	bne _080ABFAC
	mov r1, r8
	ldrb r0, [r1, 0x2]
	lsls r0, 11
	str r0, [r5, 0xC]
	ldrb r0, [r1, 0x3]
	b _080ABFB4
	.align 2, 0
_080ABFA8: .4byte 0x02000185
_080ABFAC:
	ldrb r0, [r6, 0x2]
	lsls r0, 11
	str r0, [r5, 0xC]
	ldrb r0, [r6, 0x3]
_080ABFB4:
	lsls r0, 11
	str r0, [r5, 0x10]
	ldr r0, [r5, 0xC]
	lsrs r1, r0, 31
	adds r0, r1
	asrs r0, 1
	str r0, [r5, 0x14]
	ldr r0, [r5, 0x10]
	lsrs r1, r0, 31
	adds r0, r1
	asrs r0, 1
	str r0, [r5, 0x18]
	mov r2, r8
	ldrb r0, [r2, 0x1]
	strb r0, [r5, 0x1C]
	adds r2, 0x4
	adds r4, r5, 0
	adds r4, 0x20
	ldrb r1, [r2, 0x2]
	movs r0, 0x4
	ands r0, r1
	cmp r0, 0
	bne _080ABFFC
	mov r3, r8
	ldrb r0, [r3, 0x4]
	lsls r3, r0, 11
	str r3, [r5, 0x20]
	ldrb r1, [r2, 0x2]
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	beq _080ABFFC
	movs r1, 0x80
	lsls r1, 3
	adds r0, r3, r1
	str r0, [r5, 0x20]
_080ABFFC:
	ldrb r1, [r2, 0x3]
	movs r0, 0x4
	ands r0, r1
	cmp r0, 0
	bne _080AC01E
	ldrb r0, [r2, 0x1]
	lsls r3, r0, 11
	str r3, [r4, 0x4]
	ldrb r1, [r2, 0x3]
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	beq _080AC01E
	movs r2, 0x80
	lsls r2, 3
	adds r0, r3, r2
	str r0, [r4, 0x4]
_080AC01E:
	ldr r3, [sp, 0x10]
	cmp r3, 0
	beq _080AC076
	ldrb r1, [r5, 0x1C]
	movs r2, 0x90
	lsls r2, 1
	adds r0, r5, r2
	movs r3, 0
	strb r1, [r0]
	movs r0, 0x92
	lsls r0, 1
	adds r2, r5, r0
	ldr r0, [r5, 0x20]
	ldr r1, [r5, 0x14]
	subs r0, r1
	str r0, [r2]
	movs r1, 0x96
	lsls r1, 1
	adds r2, r5, r1
	ldr r0, [r5, 0x20]
	ldr r1, [r5, 0x14]
	adds r0, r1
	str r0, [r2]
	movs r0, 0x94
	lsls r0, 1
	adds r2, r5, r0
	ldr r0, [r5, 0x24]
	ldr r1, [r5, 0x18]
	subs r0, r1
	str r0, [r2]
	movs r1, 0x98
	lsls r1, 1
	adds r2, r5, r1
	ldr r0, [r5, 0x24]
	ldr r1, [r5, 0x18]
	adds r0, r1
	str r0, [r2]
	movs r2, 0x9A
	lsls r2, 1
	adds r1, r5, r2
	adds r2, 0x4
	adds r0, r5, r2
	str r3, [r0]
	str r3, [r1]
_080AC076:
	adds r0, r5, 0
	adds r0, 0x28
	adds r1, r5, 0
	adds r1, 0x30
	bl sub_80A5778
	ldr r3, [sp, 0x10]
	cmp r3, 0
	beq _080AC0C0
	movs r0, 0x9F
	lsls r0, 1
	adds r1, r5, r0
	movs r2, 0
	movs r0, 0x80
	lsls r0, 4
	strh r0, [r1]
	movs r3, 0x9E
	lsls r3, 1
	adds r1, r5, r3
	movs r0, 0x1
	strb r0, [r1]
	movs r1, 0xA0
	lsls r1, 1
	adds r0, r5, r1
	strh r2, [r0]
	movs r2, 0xA2
	lsls r2, 1
	adds r0, r5, r2
	movs r3, 0x6
	ldrsh r2, [r5, r3]
	movs r3, 0x8E
	lsls r3, 1
	adds r1, r5, r3
	ldr r3, [r1]
	adds r1, r7, 0
	bl sub_80A75CC
_080AC0C0:
	adds r4, r5, 0
	adds r4, 0x38
	ldr r1, _080AC154
	mov r0, r9
	str r0, [sp]
	adds r0, r4, 0
	adds r2, r5, 0
	mov r3, r10
	bl sub_809D600
	adds r6, r4, 0
	mov r1, r8
	ldr r2, [r1, 0xC]
	cmp r2, 0
	bne _080AC0F2
	movs r2, 0xA2
	lsls r2, 1
	adds r0, r5, r2
	bl sub_80A66A4
	lsls r0, 24
	ldr r2, _080AC158
	cmp r0, 0
	beq _080AC0F2
	ldr r2, _080AC15C
_080AC0F2:
	adds r0, r6, 0
	movs r1, 0x1
	bl sub_809D6D8
	adds r1, r4, 0
	mov r3, r8
	ldr r2, [r3, 0x10]
	cmp r2, 0
	bne _080AC108
	ldr r0, _080AC160
	ldr r2, [r0, 0x38]
_080AC108:
	adds r0, r1, 0
	movs r1, 0x2
	bl sub_809D6D8
	mov r0, r8
	ldr r2, [r0, 0x14]
	cmp r2, 0
	bne _080AC11C
	ldr r0, _080AC160
	ldr r2, [r0, 0x68]
_080AC11C:
	adds r0, r4, 0
	movs r1, 0x3
	bl sub_809D6D8
	mov r1, r8
	ldr r2, [r1, 0x8]
	cmp r2, 0
	beq _080AC140
	adds r0, r4, 0
	movs r1, 0
	bl sub_809D6D8
	ldr r3, _080AC164
	adds r0, r4, 0
	movs r1, 0
	movs r2, 0
	bl sub_809D8C0
_080AC140:
	adds r0, r7, 0
_080AC142:
	add sp, 0x14
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	.align 2, 0
_080AC154: .4byte gUnknown_81182A0
_080AC158: .4byte gUnknown_81182F4
_080AC15C: .4byte gUnknown_8118350
_080AC160: .4byte gUnknown_812F1F8
_080AC164: .4byte gUnknown_81184A4
	thumb_func_end GroundObject_Add

	thumb_func_start GroundObject_Delete
GroundObject_Delete:
	push {r4,lr}
	adds r2, r0, 0
	lsls r2, 16
	asrs r2, 16
	ldr r1, _080AC1A4
	lsls r0, r2, 3
	subs r0, r2
	lsls r0, 4
	adds r0, r2
	lsls r0, 2
	ldr r1, [r1]
	adds r4, r1, r0
	ldr r1, _080AC1A8
	movs r0, 0
	bl Log
	movs r1, 0xA2
	lsls r1, 1
	adds r0, r4, r1
	bl sub_80A7658
	adds r0, r4, 0
	adds r0, 0x38
	bl sub_809D648
	ldr r0, _080AC1AC
	strh r0, [r4, 0x6]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080AC1A4: .4byte gUnknown_3001B88
_080AC1A8: .4byte gUnknown_81184B0
_080AC1AC: .4byte 0x0000ffff
	thumb_func_end GroundObject_Delete

	thumb_func_start sub_80AC1B0
sub_80AC1B0:
	push {lr}
	adds r3, r1, 0
	lsls r0, 16
	asrs r0, 16
	ldr r2, _080AC1F0
	lsls r1, r0, 3
	subs r1, r0
	lsls r1, 4
	adds r1, r0
	lsls r1, 2
	ldr r0, [r2]
	adds r2, r0, r1
	movs r0, 0x6
	ldrsh r1, [r2, r0]
	movs r0, 0x1
	negs r0, r0
	cmp r1, r0
	beq _080AC1EA
	movs r1, 0x8E
	lsls r1, 1
	adds r0, r2, r1
	ldr r1, [r0]
	orrs r1, r3
	str r1, [r0]
	movs r3, 0xA2
	lsls r3, 1
	adds r0, r2, r3
	bl sub_80A6688
_080AC1EA:
	pop {r0}
	bx r0
	.align 2, 0
_080AC1F0: .4byte gUnknown_3001B88
	thumb_func_end sub_80AC1B0

	thumb_func_start sub_80AC1F4
sub_80AC1F4:
	push {r4,lr}
	adds r4, r1, 0
	lsls r0, 16
	asrs r0, 16
	ldr r2, _080AC238
	lsls r1, r0, 3
	subs r1, r0
	lsls r1, 4
	adds r1, r0
	lsls r1, 2
	ldr r0, [r2]
	adds r3, r0, r1
	movs r0, 0x6
	ldrsh r1, [r3, r0]
	movs r0, 0x1
	negs r0, r0
	cmp r1, r0
	beq _080AC232
	movs r0, 0x8E
	lsls r0, 1
	adds r2, r3, r0
	ldr r0, _080AC23C
	eors r0, r4
	ldr r1, [r2]
	ands r1, r0
	str r1, [r2]
	movs r2, 0xA2
	lsls r2, 1
	adds r0, r3, r2
	bl sub_80A6688
_080AC232:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080AC238: .4byte gUnknown_3001B88
_080AC23C: .4byte 0x337fffff
	thumb_func_end sub_80AC1F4

	thumb_func_start sub_80AC240
sub_80AC240:
	push {lr}
	lsls r0, 16
	asrs r0, 16
	ldr r2, _080AC268
	lsls r1, r0, 3
	subs r1, r0
	lsls r1, 4
	adds r1, r0
	lsls r1, 2
	ldr r0, [r2]
	adds r2, r0, r1
	movs r0, 0x6
	ldrsh r1, [r2, r0]
	movs r0, 0x1
	negs r0, r0
	cmp r1, r0
	bne _080AC26C
	movs r0, 0
	b _080AC270
	.align 2, 0
_080AC268: .4byte gUnknown_3001B88
_080AC26C:
	adds r0, r2, 0
	adds r0, 0x38
_080AC270:
	pop {r1}
	bx r1
	thumb_func_end sub_80AC240

	thumb_func_start sub_80AC274
sub_80AC274:
	push {r4,lr}
	adds r4, r1, 0
	lsls r0, 16
	asrs r0, 16
	lsls r2, 16
	asrs r3, r2, 16
	ldr r2, _080AC2A0
	lsls r1, r0, 3
	subs r1, r0
	lsls r1, 4
	adds r1, r0
	lsls r1, 2
	ldr r0, [r2]
	adds r2, r0, r1
	movs r0, 0x6
	ldrsh r1, [r2, r0]
	movs r0, 0x1
	negs r0, r0
	cmp r1, r0
	bne _080AC2A4
	movs r0, 0
	b _080AC2B4
	.align 2, 0
_080AC2A0: .4byte gUnknown_3001B88
_080AC2A4:
	adds r0, r2, 0
	adds r0, 0x38
	adds r1, r4, 0
	adds r2, r3, 0
	bl sub_809D6E4
	lsls r0, 24
	lsrs r0, 24
_080AC2B4:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_80AC274

	thumb_func_start GroundObject_ExecuteScript
GroundObject_ExecuteScript:
	push {r4-r6,lr}
	adds r3, r0, 0
	adds r5, r1, 0
	adds r6, r2, 0
	lsls r3, 16
	asrs r3, 16
	ldr r1, _080AC2F4
	lsls r0, r3, 3
	subs r0, r3
	lsls r0, 4
	adds r0, r3
	lsls r0, 2
	ldr r1, [r1]
	adds r4, r1, r0
	ldr r1, _080AC2F8
	movs r0, 0
	adds r2, r3, 0
	bl Log
	movs r0, 0x6
	ldrsh r1, [r4, r0]
	movs r0, 0x1
	negs r0, r0
	cmp r1, r0
	bne _080AC2FC
	movs r0, 0
	b _080AC314
	.align 2, 0
_080AC2F4: .4byte gUnknown_3001B88
_080AC2F8: .4byte gUnknown_81184CC
_080AC2FC:
	adds r0, r4, 0
	adds r0, 0x38
	ldr r3, _080AC31C
	adds r1, r5, 0
	adds r2, r6, 0
	bl GroundScript_ExecutePP
	movs r0, 0x9E
	lsls r0, 1
	adds r1, r4, r0
	movs r0, 0x1
	strb r0, [r1]
_080AC314:
	pop {r4-r6}
	pop {r1}
	bx r1
	.align 2, 0
_080AC31C: .4byte gUnknown_8118504
	thumb_func_end GroundObject_ExecuteScript

	thumb_func_start sub_80AC320
sub_80AC320:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	lsls r0, 16
	asrs r7, r0, 16
	ldr r0, _080AC374
	ldr r4, [r0]
	movs r5, 0
	movs r0, 0x1
	negs r0, r0
	mov r8, r0
	movs r6, 0x80
	lsls r6, 9
_080AC33A:
	movs r1, 0x6
	ldrsh r0, [r4, r1]
	cmp r0, r8
	beq _080AC352
	adds r0, r4, 0
	adds r0, 0x38
	adds r1, r7, 0
	bl sub_809D968
	orrs r5, r0
	lsls r0, r5, 24
	lsrs r5, r0, 24
_080AC352:
	adds r0, r6, 0
	movs r1, 0x80
	lsls r1, 9
	adds r6, r1
	asrs r0, 16
	movs r1, 0xE2
	lsls r1, 1
	adds r4, r1
	cmp r0, 0xF
	ble _080AC33A
	adds r0, r5, 0
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r1}
	bx r1
	.align 2, 0
_080AC374: .4byte gUnknown_3001B88
	thumb_func_end sub_80AC320

	thumb_func_start sub_80AC378
sub_80AC378:
	push {r4-r7,lr}
	ldr r0, _080AC3BC
	ldr r4, [r0]
	movs r5, 0
	movs r7, 0x1
	negs r7, r7
	movs r6, 0x80
	lsls r6, 9
_080AC388:
	movs r1, 0x6
	ldrsh r0, [r4, r1]
	cmp r0, r7
	beq _080AC39E
	adds r0, r4, 0
	adds r0, 0x38
	bl sub_809D92C
	orrs r5, r0
	lsls r0, r5, 24
	lsrs r5, r0, 24
_080AC39E:
	adds r0, r6, 0
	movs r1, 0x80
	lsls r1, 9
	adds r6, r1
	asrs r0, 16
	movs r1, 0xE2
	lsls r1, 1
	adds r4, r1
	cmp r0, 0xF
	ble _080AC388
	adds r0, r5, 0
	pop {r4-r7}
	pop {r1}
	bx r1
	.align 2, 0
_080AC3BC: .4byte gUnknown_3001B88
	thumb_func_end sub_80AC378

	thumb_func_start sub_80AC3C0
sub_80AC3C0:
	lsls r0, 16
	asrs r0, 16
	ldr r2, _080AC3DC
	lsls r1, r0, 3
	subs r1, r0
	lsls r1, 4
	adds r1, r0
	lsls r1, 2
	ldr r0, [r2]
	adds r0, r1
	movs r1, 0x6
	ldrsh r0, [r0, r1]
	bx lr
	.align 2, 0
_080AC3DC: .4byte gUnknown_3001B88
	thumb_func_end sub_80AC3C0

	thumb_func_start sub_80AC3E0
sub_80AC3E0:
	lsls r0, 16
	asrs r0, 16
	ldr r3, _080AC404
	lsls r2, r0, 3
	subs r2, r0
	lsls r2, 4
	adds r2, r0
	lsls r2, 2
	ldr r0, [r3]
	adds r0, r2
	movs r3, 0x8E
	lsls r3, 1
	adds r2, r0, r3
	ldr r2, [r2]
	str r2, [r1]
	movs r1, 0x6
	ldrsh r0, [r0, r1]
	bx lr
	.align 2, 0
_080AC404: .4byte gUnknown_3001B88
	thumb_func_end sub_80AC3E0

	thumb_func_start sub_80AC408
sub_80AC408:
	push {lr}
	adds r3, r1, 0
	lsls r0, 16
	asrs r0, 16
	ldr r2, _080AC434
	lsls r1, r0, 3
	subs r1, r0
	lsls r1, 4
	adds r1, r0
	lsls r1, 2
	ldr r0, [r2]
	adds r2, r0, r1
	movs r0, 0x6
	ldrsh r1, [r2, r0]
	movs r0, 0x1
	negs r0, r0
	cmp r1, r0
	bne _080AC438
	movs r0, 0
	str r0, [r3]
	str r0, [r3, 0x4]
	b _080AC440
	.align 2, 0
_080AC434: .4byte gUnknown_3001B88
_080AC438:
	ldr r0, [r2, 0xC]
	ldr r1, [r2, 0x10]
	str r0, [r3]
	str r1, [r3, 0x4]
_080AC440:
	movs r1, 0x6
	ldrsh r0, [r2, r1]
	pop {r1}
	bx r1
	thumb_func_end sub_80AC408

	thumb_func_start sub_80AC448
sub_80AC448:
	push {lr}
	adds r3, r1, 0
	lsls r0, 16
	asrs r0, 16
	ldr r2, _080AC474
	lsls r1, r0, 3
	subs r1, r0
	lsls r1, 4
	adds r1, r0
	lsls r1, 2
	ldr r0, [r2]
	adds r2, r0, r1
	movs r0, 0x6
	ldrsh r1, [r2, r0]
	movs r0, 0x1
	negs r0, r0
	cmp r1, r0
	bne _080AC478
	movs r0, 0
	str r0, [r3]
	b _080AC492
	.align 2, 0
_080AC474: .4byte gUnknown_3001B88
_080AC478:
	movs r1, 0x92
	lsls r1, 1
	adds r0, r2, r1
	ldr r0, [r0]
	ldr r1, [r2, 0x14]
	adds r0, r1
	str r0, [r3]
	movs r1, 0x94
	lsls r1, 1
	adds r0, r2, r1
	ldr r0, [r0]
	ldr r1, [r2, 0x18]
	adds r0, r1
_080AC492:
	str r0, [r3, 0x4]
	movs r1, 0x6
	ldrsh r0, [r2, r1]
	pop {r1}
	bx r1
	thumb_func_end sub_80AC448

	thumb_func_start sub_80AC49C
sub_80AC49C:
	push {r4,lr}
	lsls r0, 16
	asrs r0, 16
	ldr r3, _080AC4C4
	lsls r2, r0, 3
	subs r2, r0
	lsls r2, 4
	adds r2, r0
	lsls r2, 2
	ldr r4, [r3]
	adds r4, r2
	adds r0, r4, 0
	bl sub_80AC6AC
	movs r1, 0x6
	ldrsh r0, [r4, r1]
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_080AC4C4: .4byte gUnknown_3001B88
	thumb_func_end sub_80AC49C

	thumb_func_start sub_80AC4C8
sub_80AC4C8:
	push {r4-r7,lr}
	adds r7, r0, 0
	adds r4, r1, 0
	ldr r0, _080AC530
	ldr r3, [r0]
	movs r5, 0
	movs r0, 0x1
	negs r0, r0
	mov r12, r0
	movs r6, 0x80
	lsls r6, 9
_080AC4DE:
	movs r1, 0x6
	ldrsh r0, [r3, r1]
	cmp r0, r12
	beq _080AC534
	movs r1, 0x8E
	lsls r1, 1
	adds r0, r3, r1
	ldr r0, [r0]
	ands r0, r7
	cmp r0, 0
	beq _080AC534
	adds r1, 0x8
	adds r0, r3, r1
	ldr r1, [r0]
	ldr r0, [r2]
	cmp r1, r0
	bge _080AC534
	movs r1, 0x96
	lsls r1, 1
	adds r0, r3, r1
	ldr r1, [r0]
	ldr r0, [r4]
	cmp r1, r0
	ble _080AC534
	movs r1, 0x94
	lsls r1, 1
	adds r0, r3, r1
	ldr r1, [r0]
	ldr r0, [r2, 0x4]
	cmp r1, r0
	bge _080AC534
	movs r1, 0x98
	lsls r1, 1
	adds r0, r3, r1
	ldr r1, [r0]
	ldr r0, [r4, 0x4]
	cmp r1, r0
	ble _080AC534
	adds r0, r5, 0
	b _080AC54C
	.align 2, 0
_080AC530: .4byte gUnknown_3001B88
_080AC534:
	adds r0, r6, 0
	movs r1, 0x80
	lsls r1, 9
	adds r6, r1
	asrs r5, r0, 16
	movs r0, 0xE2
	lsls r0, 1
	adds r3, r0
	cmp r5, 0xF
	ble _080AC4DE
	movs r0, 0x1
	negs r0, r0
_080AC54C:
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_80AC4C8

	thumb_func_start sub_80AC554
sub_80AC554:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	mov r8, r0
	mov r10, r1
	adds r4, r2, 0
	ldr r0, _080AC5C8
	ldr r0, [r0]
	mov r12, r0
	movs r6, 0
	movs r0, 0x1
	negs r0, r0
	mov r9, r0
	movs r7, 0x80
	lsls r7, 9
_080AC576:
	mov r1, r12
	movs r2, 0x6
	ldrsh r0, [r1, r2]
	cmp r0, r9
	beq _080AC5CC
	movs r0, 0x8E
	lsls r0, 1
	add r0, r12
	ldr r0, [r0]
	mov r5, r8
	ands r0, r5
	cmp r0, 0
	beq _080AC5CC
	movs r0, 0x92
	lsls r0, 1
	add r0, r12
	ldr r1, [r0]
	mov r5, r12
	ldr r0, [r5, 0x14]
	adds r2, r1, r0
	movs r0, 0x94
	lsls r0, 1
	add r0, r12
	ldr r1, [r0]
	ldr r0, [r5, 0x18]
	adds r3, r1, r0
	ldr r0, [r4]
	cmp r2, r0
	bge _080AC5CC
	mov r1, r10
	ldr r0, [r1]
	cmp r2, r0
	ble _080AC5CC
	ldr r0, [r4, 0x4]
	cmp r3, r0
	bge _080AC5CC
	ldr r0, [r1, 0x4]
	cmp r3, r0
	ble _080AC5CC
	adds r0, r6, 0
	b _080AC5E4
	.align 2, 0
_080AC5C8: .4byte gUnknown_3001B88
_080AC5CC:
	adds r0, r7, 0
	movs r2, 0x80
	lsls r2, 9
	adds r7, r2
	asrs r6, r0, 16
	movs r5, 0xE2
	lsls r5, 1
	add r12, r5
	cmp r6, 0xF
	ble _080AC576
	movs r0, 0x1
	negs r0, r0
_080AC5E4:
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_80AC554

	thumb_func_start sub_80AC5F4
sub_80AC5F4:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0x10
	mov r8, r0
	adds r5, r1, 0
	adds r6, r2, 0
	ldr r0, [r5]
	cmp r0, 0
	bge _080AC60C
	ldr r1, _080AC670
	adds r0, r1
_080AC60C:
	asrs r0, 11
	mov r12, r0
	str r0, [sp]
	ldr r0, [r5, 0x4]
	cmp r0, 0
	bge _080AC61C
	ldr r3, _080AC670
	adds r0, r3
_080AC61C:
	asrs r4, r0, 11
	str r4, [sp, 0x4]
	ldr r3, [r6]
	subs r0, r3, 0x1
	cmp r0, 0
	bge _080AC62C
	ldr r7, _080AC674
	adds r0, r3, r7
_080AC62C:
	asrs r1, r0, 11
	ldr r3, [r6, 0x4]
	subs r0, r3, 0x1
	cmp r0, 0
	bge _080AC63A
	ldr r7, _080AC674
	adds r0, r3, r7
_080AC63A:
	asrs r2, r0, 11
	mov r3, r12
	subs r0, r1, r3
	adds r0, 0x1
	str r0, [sp, 0x8]
	subs r0, r2, r4
	adds r0, 0x1
	add r2, sp, 0x8
	str r0, [r2, 0x4]
	movs r0, 0x8E
	lsls r0, 1
	add r0, r8
	ldr r0, [r0]
	movs r1, 0x1
	ands r0, r1
	cmp r0, 0
	beq _080AC678
	mov r0, sp
	adds r1, r2, 0
	bl sub_80A585C
	lsls r0, 24
	cmp r0, 0
	beq _080AC678
	movs r0, 0x1
	b _080AC6A0
	.align 2, 0
_080AC670: .4byte 0x000007ff
_080AC674: .4byte 0x000007fe
_080AC678:
	movs r0, 0x8E
	lsls r0, 1
	add r0, r8
	ldr r0, [r0]
	movs r1, 0x4
	ands r0, r1
	cmp r0, 0
	beq _080AC69E
	movs r0, 0x1
	negs r0, r0
	adds r2, r5, 0
	adds r3, r6, 0
	bl sub_80A92A0
	lsls r0, 16
	cmp r0, 0
	blt _080AC69E
	movs r0, 0x4
	b _080AC6A0
_080AC69E:
	movs r0, 0
_080AC6A0:
	add sp, 0x10
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_80AC5F4

	thumb_func_start sub_80AC6AC
sub_80AC6AC:
	push {r4,r5,lr}
	sub sp, 0x10
	adds r5, r0, 0
	ldr r2, [r1]
	ldr r4, [r5, 0x14]
	subs r0, r2, r4
	str r0, [sp]
	ldr r3, [r1, 0x4]
	ldr r1, [r5, 0x18]
	subs r0, r3, r1
	str r0, [sp, 0x4]
	adds r2, r4
	str r2, [sp, 0x8]
	adds r3, r1
	add r2, sp, 0x8
	str r3, [r2, 0x4]
	ldr r1, [r5, 0x28]
	ldr r0, [sp]
	cmp r0, r1
	blt _080AC6EA
	ldr r1, [r5, 0x30]
	ldr r0, [sp, 0x8]
	cmp r0, r1
	bge _080AC6EA
	ldr r1, [r5, 0x2C]
	ldr r0, [sp, 0x4]
	cmp r0, r1
	blt _080AC6EA
	ldr r0, [r5, 0x34]
	cmp r3, r0
	blt _080AC6EE
_080AC6EA:
	movs r0, 0x1
	b _080AC718
_080AC6EE:
	adds r0, r5, 0
	mov r1, sp
	bl sub_80AC5F4
	cmp r0, 0
	bne _080AC718
	movs r0, 0x92
	lsls r0, 1
	adds r2, r5, r0
	ldr r0, [sp]
	ldr r1, [sp, 0x4]
	str r0, [r2]
	str r1, [r2, 0x4]
	movs r0, 0x96
	lsls r0, 1
	adds r2, r5, r0
	ldr r0, [sp, 0x8]
	ldr r1, [sp, 0xC]
	str r0, [r2]
	str r1, [r2, 0x4]
	movs r0, 0
_080AC718:
	add sp, 0x10
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_80AC6AC

	thumb_func_start sub_80AC720
sub_80AC720:
	push {r4,r5,lr}
	sub sp, 0x10
	adds r4, r0, 0
	movs r2, 0x92
	lsls r2, 1
	adds r0, r4, r2
	ldr r0, [r0]
	ldr r2, [r1]
	adds r0, r2
	str r0, [sp]
	movs r3, 0x94
	lsls r3, 1
	adds r0, r4, r3
	ldr r0, [r0]
	ldr r1, [r1, 0x4]
	adds r0, r1
	str r0, [sp, 0x4]
	adds r3, 0x4
	adds r0, r4, r3
	ldr r0, [r0]
	adds r0, r2
	str r0, [sp, 0x8]
	movs r2, 0x98
	lsls r2, 1
	adds r0, r4, r2
	ldr r0, [r0]
	adds r0, r1
	add r1, sp, 0x8
	str r0, [r1, 0x4]
	movs r5, 0
	ldr r3, [r4, 0x28]
	ldr r0, [sp]
	adds r2, r1, 0
	cmp r0, r3
	bge _080AC770
	str r3, [sp]
	ldr r0, [r4, 0xC]
	adds r0, r3, r0
	str r0, [sp, 0x8]
	b _080AC780
_080AC770:
	ldr r1, [r4, 0x30]
	ldr r0, [sp, 0x8]
	cmp r0, r1
	blt _080AC782
	ldr r0, [r4, 0xC]
	subs r0, r1, r0
	str r0, [sp]
	str r1, [sp, 0x8]
_080AC780:
	movs r5, 0x1
_080AC782:
	ldr r1, [r4, 0x2C]
	ldr r0, [sp, 0x4]
	cmp r0, r1
	bge _080AC794
	str r1, [sp, 0x4]
	ldr r0, [r4, 0x10]
	adds r0, r1, r0
	str r0, [r2, 0x4]
	b _080AC7A4
_080AC794:
	ldr r1, [r4, 0x34]
	ldr r0, [r2, 0x4]
	cmp r0, r1
	blt _080AC7A6
	ldr r0, [r4, 0x10]
	subs r0, r1, r0
	str r0, [sp, 0x4]
	str r1, [r2, 0x4]
_080AC7A4:
	movs r5, 0x1
_080AC7A6:
	adds r0, r4, 0
	mov r1, sp
	bl sub_80AC5F4
	cmp r0, 0
	bne _080AC7D8
	movs r3, 0x92
	lsls r3, 1
	adds r2, r4, r3
	ldr r0, [sp]
	ldr r1, [sp, 0x4]
	str r0, [r2]
	str r1, [r2, 0x4]
	movs r0, 0x96
	lsls r0, 1
	adds r2, r4, r0
	ldr r0, [sp, 0x8]
	ldr r1, [sp, 0xC]
	str r0, [r2]
	str r1, [r2, 0x4]
	cmp r5, 0
	bne _080AC7D6
	movs r0, 0
	b _080AC7D8
_080AC7D6:
	movs r0, 0x1
_080AC7D8:
	add sp, 0x10
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_80AC720

	thumb_func_start sub_80AC7E0
sub_80AC7E0:
	movs r1, 0x4
	ldrsh r0, [r0, r1]
	bx lr
	thumb_func_end sub_80AC7E0

	thumb_func_start sub_80AC7E8
sub_80AC7E8:
	ldr r2, [r0, 0xC]
	ldr r3, [r0, 0x10]
	str r2, [r1]
	str r3, [r1, 0x4]
	bx lr
	thumb_func_end sub_80AC7E8

	thumb_func_start sub_80AC7F4
sub_80AC7F4:
	push {r4,lr}
	adds r3, r0, 0
	adds r4, r1, 0
	cmp r4, 0
	beq _080AC834
	movs r0, 0x92
	lsls r0, 1
	adds r2, r3, r0
	ldr r1, [r4]
	ldr r0, [r3, 0x14]
	subs r0, r1, r0
	str r0, [r2]
	movs r0, 0x96
	lsls r0, 1
	adds r2, r3, r0
	ldr r0, [r3, 0x14]
	adds r1, r0
	str r1, [r2]
	movs r0, 0x94
	lsls r0, 1
	adds r2, r3, r0
	ldr r1, [r4, 0x4]
	ldr r0, [r3, 0x18]
	subs r0, r1, r0
	str r0, [r2]
	movs r0, 0x98
	lsls r0, 1
	adds r2, r3, r0
	ldr r0, [r3, 0x18]
	adds r1, r0
	str r1, [r2]
	b _080AC89A
_080AC834:
	movs r0, 0x92
	lsls r0, 1
	adds r2, r3, r0
	ldr r0, [r3, 0x20]
	ldr r1, [r3, 0x14]
	subs r0, r1
	str r0, [r2]
	movs r0, 0x96
	lsls r0, 1
	adds r2, r3, r0
	ldr r0, [r3, 0x20]
	ldr r1, [r3, 0x14]
	adds r0, r1
	str r0, [r2]
	movs r0, 0x94
	lsls r0, 1
	adds r2, r3, r0
	ldr r0, [r3, 0x24]
	ldr r1, [r3, 0x18]
	subs r0, r1
	str r0, [r2]
	movs r0, 0x98
	lsls r0, 1
	adds r2, r3, r0
	ldr r0, [r3, 0x24]
	ldr r1, [r3, 0x18]
	adds r0, r1
	str r0, [r2]
	movs r2, 0x9A
	lsls r2, 1
	adds r1, r3, r2
	adds r2, 0x4
	adds r0, r3, r2
	str r4, [r0]
	str r4, [r1]
	movs r0, 0x90
	lsls r0, 1
	adds r2, r3, r0
	movs r1, 0
	ldrsb r1, [r2, r1]
	movs r0, 0x1C
	ldrsb r0, [r3, r0]
	cmp r1, r0
	beq _080AC896
	movs r0, 0x9E
	lsls r0, 1
	adds r1, r3, r0
	movs r0, 0x1
	strb r0, [r1]
_080AC896:
	ldrb r0, [r3, 0x1C]
	strb r0, [r2]
_080AC89A:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_80AC7F4

	thumb_func_start sub_80AC8A0
sub_80AC8A0:
	push {r4,lr}
	ldr r3, [r1]
	ldr r4, [r1, 0x4]
	str r3, [r0, 0x28]
	str r4, [r0, 0x2C]
	ldr r1, [r2]
	ldr r2, [r2, 0x4]
	str r1, [r0, 0x30]
	str r2, [r0, 0x34]
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_80AC8A0

	thumb_func_start sub_80AC8B8
sub_80AC8B8:
	adds r3, r0, 0
	movs r2, 0x92
	lsls r2, 1
	adds r0, r3, r2
	ldr r0, [r0]
	ldr r2, [r3, 0x14]
	adds r0, r2
	str r0, [r1]
	movs r2, 0x94
	lsls r2, 1
	adds r0, r3, r2
	ldr r0, [r0]
	ldr r2, [r3, 0x18]
	adds r0, r2
	str r0, [r1, 0x4]
	bx lr
	thumb_func_end sub_80AC8B8

	thumb_func_start sub_80AC8D8
sub_80AC8D8:
	push {lr}
	bl sub_80AC6AC
	pop {r1}
	bx r1
	thumb_func_end sub_80AC8D8

	thumb_func_start sub_80AC8E4
sub_80AC8E4:
	push {r4,lr}
	adds r3, r0, 0
	movs r4, 0x9A
	lsls r4, 1
	adds r0, r3, r4
	ldr r0, [r0]
	str r0, [r1]
	movs r1, 0x9C
	lsls r1, 1
	adds r0, r3, r1
	ldr r0, [r0]
	str r0, [r2]
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_80AC8E4

	thumb_func_start sub_80AC904
sub_80AC904:
	movs r2, 0x9A
	lsls r2, 1
	adds r0, r2
	str r1, [r0]
	bx lr
	thumb_func_end sub_80AC904

	thumb_func_start sub_80AC910
sub_80AC910:
	movs r2, 0x90
	lsls r2, 1
	adds r0, r2
	ldrb r0, [r0]
	strb r0, [r1]
	bx lr
	thumb_func_end sub_80AC910

	thumb_func_start sub_80AC91C
sub_80AC91C:
	push {lr}
	adds r2, r0, 0
	lsls r1, 24
	asrs r1, 24
	movs r0, 0x1
	negs r0, r0
	cmp r1, r0
	beq _080AC934
	movs r3, 0x90
	lsls r3, 1
	adds r0, r2, r3
	strb r1, [r0]
_080AC934:
	pop {r0}
	bx r0
	thumb_func_end sub_80AC91C

	thumb_func_start sub_80AC938
sub_80AC938:
	push {r4,r5,lr}
	lsls r1, 16
	adds r3, r0, 0
	movs r0, 0xFF
	lsls r0, 16
	ands r0, r1
	lsrs r0, 16
	cmp r0, 0
	beq _080AC958
	ldr r1, _080AC954
	lsls r0, 1
	adds r0, r1
	b _080AC95E
	.align 2, 0
_080AC954: .4byte gUnknown_81183A0
_080AC958:
	movs r5, 0x9F
	lsls r5, 1
	adds r0, r3, r5
_080AC95E:
	movs r1, 0
	ldrsh r2, [r0, r1]
	movs r5, 0x9F
	lsls r5, 1
	adds r1, r3, r5
	ldrh r4, [r1]
	movs r5, 0
	ldrsh r0, [r1, r5]
	cmp r0, r2
	beq _080AC97C
	strh r2, [r1]
	movs r0, 0x9E
	lsls r0, 1
	adds r1, r3, r0
	b _080AC98C
_080AC97C:
	movs r0, 0x80
	lsls r0, 5
	ands r0, r4
	cmp r0, 0
	beq _080AC990
	movs r5, 0x9E
	lsls r5, 1
	adds r1, r3, r5
_080AC98C:
	movs r0, 0x1
	strb r0, [r1]
_080AC990:
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_80AC938

	thumb_func_start sub_80AC998
sub_80AC998:
	push {lr}
	lsls r1, 16
	asrs r1, 16
	adds r2, r1, 0
	cmp r1, 0
	bne _080AC9AA
	movs r1, 0xE0
	lsls r1, 1
	adds r2, r1, 0
_080AC9AA:
	movs r1, 0xA0
	lsls r1, 1
	adds r0, r1
	strh r2, [r0]
	pop {r0}
	bx r0
	thumb_func_end sub_80AC998

	thumb_func_start sub_80AC9B8
sub_80AC9B8:
	push {lr}
	adds r1, r0, 0
	movs r2, 0x9E
	lsls r2, 1
	adds r0, r1, r2
	ldrb r0, [r0]
	cmp r0, 0
	bne _080AC9D6
	adds r2, 0x8
	adds r0, r1, r2
	bl sub_80A66F8
	lsls r0, 24
	lsrs r0, 24
	b _080AC9D8
_080AC9D6:
	movs r0, 0x1
_080AC9D8:
	pop {r1}
	bx r1
	thumb_func_end sub_80AC9B8

	thumb_func_start sub_80AC9DC
sub_80AC9DC:
	push {lr}
	adds r1, r0, 0
	movs r2, 0xA0
	lsls r2, 1
	adds r0, r1, r2
	movs r2, 0
	ldrsh r0, [r0, r2]
	cmp r0, 0
	bne _080AC9FE
	movs r2, 0xA2
	lsls r2, 1
	adds r0, r1, r2
	bl sub_80A671C
	lsls r0, 24
	lsrs r0, 24
	b _080ACA00
_080AC9FE:
	movs r0, 0x1
_080ACA00:
	pop {r1}
	bx r1
	thumb_func_end sub_80AC9DC

	thumb_func_start sub_80ACA04
sub_80ACA04:
	movs r2, 0x8E
	lsls r2, 1
	adds r0, r2
	ldr r0, [r0]
	str r0, [r1]
	bx lr
	thumb_func_end sub_80ACA04

	thumb_func_start sub_80ACA10
sub_80ACA10:
	push {lr}
	movs r2, 0x4
	ldrsh r0, [r0, r2]
	bl sub_80AC1B0
	pop {r0}
	bx r0
	thumb_func_end sub_80ACA10

	thumb_func_start sub_80ACA20
sub_80ACA20:
	push {lr}
	movs r2, 0x4
	ldrsh r0, [r0, r2]
	bl sub_80AC1F4
	pop {r0}
	bx r0
	thumb_func_end sub_80ACA20

	thumb_func_start sub_80ACA30
sub_80ACA30:
	push {lr}
	bl sub_80AC720
	pop {r1}
	bx r1
	thumb_func_end sub_80ACA30

	thumb_func_start GroundObject_Action
GroundObject_Action:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	ldr r0, _080ACA7C
	ldr r5, [r0]
	movs r7, 0
	movs r0, 0x1
	negs r0, r0
	mov r8, r0
	movs r1, 0x9E
	lsls r1, 1
	adds r6, r5, r1
_080ACA54:
	movs r3, 0x6
	ldrsh r0, [r5, r3]
	cmp r0, r8
	beq _080ACAB2
	adds r4, r5, 0
	adds r4, 0x38
	adds r0, r4, 0
	ldr r1, _080ACA80
	bl HandleAction
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0
	beq _080ACA84
	cmp r0, 0x4
	bne _080ACA90
	adds r0, r7, 0
	bl GroundObject_Delete
	b _080ACAB2
	.align 2, 0
_080ACA7C: .4byte gUnknown_3001B88
_080ACA80: .4byte gUnknown_8118524
_080ACA84:
	adds r0, r4, 0
	movs r1, 0
	movs r2, 0x1
	ldr r3, _080ACAD0
	bl sub_809D8C0
_080ACA90:
	ldrb r0, [r6]
	cmp r0, 0
	beq _080ACAB2
	movs r0, 0
	strb r0, [r6]
	movs r1, 0xA2
	lsls r1, 1
	adds r0, r5, r1
	ldrh r2, [r6, 0x2]
	movs r3, 0xF8
	lsls r3, 5
	adds r1, r3, 0
	ands r1, r2
	lsls r2, 24
	asrs r2, 24
	bl sub_80A6EFC
_080ACAB2:
	adds r0, r7, 0x1
	lsls r0, 16
	asrs r7, r0, 16
	movs r0, 0xE2
	lsls r0, 1
	adds r6, r0
	adds r5, r0
	cmp r7, 0xF
	ble _080ACA54
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_080ACAD0: .4byte gUnknown_8118530
	thumb_func_end GroundObject_Action

	thumb_func_start sub_80ACAD4
sub_80ACAD4:
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	sub sp, 0x8
	ldr r0, _080ACB8C
	ldr r6, [r0]
	movs r0, 0
	mov r8, r0
	movs r1, 0x1
	negs r1, r1
	mov r9, r1
	movs r2, 0x90
	lsls r2, 1
	adds r4, r6, r2
_080ACAF2:
	movs r0, 0x6
	ldrsh r1, [r6, r0]
	mov r2, r9
	lsls r0, r2, 16
	asrs r0, 16
	cmp r1, r0
	beq _080ACB64
	ldr r0, [r4, 0x4]
	ldr r1, [r6, 0x14]
	adds r0, r1
	str r0, [sp]
	ldr r0, [r4, 0x8]
	ldr r1, [r6, 0x18]
	adds r0, r1
	str r0, [sp, 0x4]
	ldr r1, [r4, 0x14]
	ldr r0, [r4, 0x18]
	adds r7, r1, r0
	movs r0, 0xA2
	lsls r0, 1
	adds r5, r6, r0
	adds r0, r5, 0
	bl sub_80A66D4
	lsls r0, 24
	cmp r0, 0
	beq _080ACB40
	movs r0, 0
	strb r0, [r4, 0x1C]
	ldrh r2, [r4, 0x1E]
	movs r0, 0xF8
	lsls r0, 5
	adds r1, r0, 0
	ands r1, r2
	lsls r2, 24
	asrs r2, 24
	adds r0, r5, 0
	bl sub_80A6EFC
_080ACB40:
	movs r1, 0x20
	ldrsh r0, [r4, r1]
	cmp r0, 0
	beq _080ACB5A
	adds r1, r0, 0
	movs r2, 0
	ldrsb r2, [r4, r2]
	adds r0, r5, 0
	movs r3, 0
	bl sub_80A7040
	movs r0, 0
	strh r0, [r4, 0x20]
_080ACB5A:
	adds r0, r5, 0
	mov r1, sp
	adds r2, r7, 0
	bl sub_80A7664
_080ACB64:
	mov r0, r8
	adds r0, 0x1
	lsls r0, 16
	asrs r0, 16
	mov r8, r0
	movs r0, 0xE2
	lsls r0, 1
	adds r4, r0
	adds r6, r0
	mov r1, r8
	cmp r1, 0xF
	ble _080ACAF2
	add sp, 0x8
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_080ACB8C: .4byte gUnknown_3001B88
	thumb_func_end sub_80ACAD4

	thumb_func_start sub_80ACB90
sub_80ACB90:
	push {r4,r5,lr}
	ldr r4, _080ACBCC
	movs r0, 0xE2
	lsls r0, 5
	movs r1, 0x6
	bl MemoryAlloc
	str r0, [r4]
	adds r1, r0, 0
	ldr r0, _080ACBD0
	adds r5, r0, 0
	movs r4, 0xE2
	lsls r4, 1
	movs r2, 0x80
	lsls r2, 9
	adds r3, r2, 0
_080ACBB0:
	ldrh r0, [r1, 0x6]
	orrs r0, r5
	strh r0, [r1, 0x6]
	adds r0, r2, 0
	adds r2, r3
	asrs r0, 16
	adds r1, r4
	cmp r0, 0xF
	ble _080ACBB0
	bl sub_80ACBD4
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_080ACBCC: .4byte gUnknown_3001B8C
_080ACBD0: .4byte 0x0000ffff
	thumb_func_end sub_80ACB90

	thumb_func_start sub_80ACBD4
sub_80ACBD4:
	push {r4-r6,lr}
	ldr r0, _080ACC0C
	ldr r4, [r0]
	movs r1, 0
	movs r6, 0x1
	negs r6, r6
	movs r5, 0x80
	lsls r5, 9
_080ACBE4:
	movs r2, 0x6
	ldrsh r0, [r4, r2]
	cmp r0, r6
	beq _080ACBF2
	adds r0, r1, 0
	bl GroundEffect_Delete
_080ACBF2:
	adds r0, r5, 0
	movs r1, 0x80
	lsls r1, 9
	adds r5, r1
	asrs r1, r0, 16
	movs r2, 0xE2
	lsls r2, 1
	adds r4, r2
	cmp r1, 0xF
	ble _080ACBE4
	pop {r4-r6}
	pop {r0}
	bx r0
	.align 2, 0
_080ACC0C: .4byte gUnknown_3001B8C
	thumb_func_end sub_80ACBD4

	thumb_func_start sub_80ACC10
sub_80ACC10:
	push {r4,lr}
	bl sub_80ACBD4
	ldr r4, _080ACC28
	ldr r0, [r4]
	bl MemoryFree
	movs r0, 0
	str r0, [r4]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080ACC28: .4byte gUnknown_3001B8C
	thumb_func_end sub_80ACC10

	thumb_func_start GroundEffect_Select
GroundEffect_Select:
	push {r4-r7,lr}
	sub sp, 0x4
	adds r4, r0, 0
	lsls r4, 16
	asrs r4, 16
	lsls r1, 16
	asrs r7, r1, 16
	lsls r2, 24
	asrs r6, r2, 24
	ldr r1, _080ACC90
	adds r0, r4, 0
	bl sub_80A77D0
	adds r5, r0, 0
	ldr r1, _080ACC94
	str r6, [sp]
	movs r0, 0
	adds r2, r4, 0
	adds r3, r7, 0
	bl Log
	lsls r1, r7, 3
	ldr r0, [r5, 0x4]
	adds r0, r1
	lsls r1, r6, 2
	adds r1, r6
	lsls r1, 3
	ldr r0, [r0, 0x4]
	adds r0, r1
	ldr r5, [r0, 0x14]
	ldr r0, [r0, 0x10]
	cmp r0, 0
	ble _080ACC86
	adds r4, r0, 0
_080ACC70:
	movs r0, 0x1
	negs r0, r0
	adds r1, r5, 0
	adds r2, r7, 0
	adds r3, r6, 0
	bl GroundEffect_Add
	subs r4, 0x1
	adds r5, 0xC
	cmp r4, 0
	bne _080ACC70
_080ACC86:
	add sp, 0x4
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_080ACC90: .4byte gUnknown_8118610
_080ACC94: .4byte gUnknown_811861C
	thumb_func_end GroundEffect_Select

	thumb_func_start GroundEffect_Cancel
GroundEffect_Cancel:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	lsls r0, 16
	asrs r7, r0, 16
	lsls r1, 24
	asrs r5, r1, 24
	ldr r1, _080ACD00
	movs r0, 0
	adds r2, r7, 0
	bl Log
	movs r1, 0
	ldr r0, _080ACD04
	ldr r4, [r0]
	movs r0, 0x1
	negs r0, r0
	mov r8, r0
	movs r6, 0x80
	lsls r6, 9
_080ACCC0:
	movs r2, 0x6
	ldrsh r0, [r4, r2]
	cmp r0, r8
	beq _080ACCE2
	movs r2, 0x8
	ldrsh r0, [r4, r2]
	cmp r0, r7
	bne _080ACCE2
	cmp r5, 0
	blt _080ACCDC
	movs r0, 0xA
	ldrsb r0, [r4, r0]
	cmp r0, r5
	bne _080ACCE2
_080ACCDC:
	adds r0, r1, 0
	bl GroundEffect_Delete
_080ACCE2:
	adds r0, r6, 0
	movs r1, 0x80
	lsls r1, 9
	adds r6, r1
	asrs r1, r0, 16
	movs r2, 0xE2
	lsls r2, 1
	adds r4, r2
	cmp r1, 0xF
	ble _080ACCC0
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_080ACD00: .4byte gUnknown_8118640
_080ACD04: .4byte gUnknown_3001B8C
	thumb_func_end GroundEffect_Cancel

	thumb_func_start GroundEffect_CancelBlank
GroundEffect_CancelBlank:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0x8
	ldr r1, _080ACD7C
	movs r0, 0
	bl Log
	movs r6, 0
	ldr r0, _080ACD80
	ldr r4, [r0]
	movs r0, 0x1
	negs r0, r0
	mov r8, r0
	movs r1, 0x92
	lsls r1, 1
	adds r5, r4, r1
	mov r7, sp
_080ACD2C:
	movs r1, 0x6
	ldrsh r0, [r4, r1]
	cmp r0, r8
	beq _080ACD5C
	ldr r0, [r5]
	ldr r1, [r4, 0x14]
	adds r0, r1
	str r0, [sp]
	ldr r0, [r5, 0x4]
	ldr r1, [r4, 0x18]
	adds r0, r1
	str r0, [r7, 0x4]
	movs r1, 0xA2
	lsls r1, 1
	adds r0, r4, r1
	mov r1, sp
	bl sub_80A675C
	lsls r0, 24
	cmp r0, 0
	bne _080ACD5C
	adds r0, r6, 0
	bl GroundEffect_Delete
_080ACD5C:
	adds r0, r6, 0x1
	lsls r0, 16
	asrs r6, r0, 16
	movs r0, 0xE2
	lsls r0, 1
	adds r5, r0
	adds r4, r0
	cmp r6, 0xF
	ble _080ACD2C
	add sp, 0x8
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_080ACD7C: .4byte gUnknown_8118658
_080ACD80: .4byte gUnknown_3001B8C
	thumb_func_end GroundEffect_CancelBlank

	thumb_func_start sub_80ACD84
sub_80ACD84:
	push {r4-r7,lr}
	lsls r0, 16
	asrs r4, r0, 16
	movs r3, 0
	ldr r0, _080ACDA8
	ldr r1, [r0]
	movs r6, 0xE2
	lsls r6, 1
	movs r2, 0x80
	lsls r2, 9
	adds r5, r2, 0
_080ACD9A:
	movs r7, 0x6
	ldrsh r0, [r1, r7]
	cmp r0, r4
	bne _080ACDAC
	adds r0, r3, 0
	b _080ACDBC
	.align 2, 0
_080ACDA8: .4byte gUnknown_3001B8C
_080ACDAC:
	adds r0, r2, 0
	adds r2, r5
	asrs r3, r0, 16
	adds r1, r6
	cmp r3, 0xF
	ble _080ACD9A
	movs r0, 0x1
	negs r0, r0
_080ACDBC:
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_80ACD84

	thumb_func_start GroundEffect_Add
GroundEffect_Add:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x10
	adds r7, r1, 0
	lsls r0, 16
	asrs r6, r0, 16
	lsls r2, 16
	asrs r2, 16
	mov r10, r2
	lsls r3, 24
	asrs r3, 24
	mov r9, r3
	ldrb r0, [r7]
	lsls r0, 2
	ldr r1, _080ACE08
	adds r0, r1
	mov r8, r0
	ldr r3, _080ACE0C
	cmp r6, 0
	bge _080ACE38
	movs r2, 0
	ldr r5, [r3]
	movs r0, 0x6
	ldrsh r1, [r5, r0]
	movs r0, 0x1
	negs r0, r0
	cmp r1, r0
	bne _080ACE10
	movs r6, 0
	b _080ACE38
	.align 2, 0
_080ACE08: .4byte gUnknown_811EE38
_080ACE0C: .4byte gUnknown_3001B8C
_080ACE10:
	adds r0, r2, 0x1
	lsls r0, 16
	asrs r2, r0, 16
	movs r1, 0xE2
	lsls r1, 1
	adds r5, r1
	cmp r2, 0xF
	bgt _080ACE2E
	movs r4, 0x6
	ldrsh r1, [r5, r4]
	movs r0, 0x1
	negs r0, r0
	cmp r1, r0
	bne _080ACE10
	adds r6, r2, 0
_080ACE2E:
	cmp r6, 0
	bge _080ACE38
	movs r0, 0x1
	negs r0, r0
	b _080AD062
_080ACE38:
	lsls r0, r6, 3
	subs r0, r6
	lsls r0, 4
	adds r0, r6
	lsls r0, 2
	ldr r1, [r3]
	adds r5, r1, r0
	ldr r1, _080ACE9C
	ldrb r3, [r7]
	mov r2, r8
	movs r4, 0
	ldrsh r0, [r2, r4]
	str r0, [sp]
	mov r0, r10
	str r0, [sp, 0x4]
	mov r2, r9
	str r2, [sp, 0x8]
	movs r0, 0
	adds r2, r6, 0
	bl Log
	movs r2, 0
	movs r3, 0x6
	ldrsh r1, [r5, r3]
	movs r0, 0x1
	negs r0, r0
	cmp r1, r0
	bne _080ACE72
	movs r2, 0x1
_080ACE72:
	str r2, [sp, 0xC]
	strh r6, [r5, 0x4]
	ldrb r0, [r7]
	strh r0, [r5, 0x6]
	mov r4, r10
	strh r4, [r5, 0x8]
	mov r0, r9
	strb r0, [r5, 0xA]
	mov r1, r8
	ldrh r0, [r1]
	subs r0, 0x1
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x4
	bhi _080ACEEC
	lsls r0, 2
	ldr r1, _080ACEA0
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080ACE9C: .4byte gUnknown_8118674
_080ACEA0: .4byte _080ACEA4
	.align 2, 0
_080ACEA4:
	.4byte _080ACEB8
	.4byte _080ACEEC
	.4byte _080ACEC4
	.4byte _080ACED0
	.4byte _080ACEDC
_080ACEB8:
	movs r2, 0x8E
	lsls r2, 1
	adds r1, r5, r2
	movs r0, 0x81
	lsls r0, 22
	b _080ACEF4
_080ACEC4:
	movs r4, 0x8E
	lsls r4, 1
	adds r1, r5, r4
	movs r0, 0x83
	lsls r0, 18
	b _080ACEF4
_080ACED0:
	movs r0, 0x8E
	lsls r0, 1
	adds r1, r5, r0
	movs r0, 0x88
	lsls r0, 22
	b _080ACEF4
_080ACEDC:
	movs r2, 0x8E
	lsls r2, 1
	adds r1, r5, r2
	ldr r0, _080ACEE8
	b _080ACEF4
	.align 2, 0
_080ACEE8: .4byte 0x22020000
_080ACEEC:
	movs r3, 0x8E
	lsls r3, 1
	adds r1, r5, r3
	ldr r0, _080ACF08
_080ACEF4:
	str r0, [r1]
	mov r4, r8
	ldrb r0, [r4, 0x2]
	cmp r0, 0
	bne _080ACF0C
	ldrb r0, [r7, 0x2]
	lsls r0, 11
	str r0, [r5, 0xC]
	ldrb r0, [r7, 0x3]
	b _080ACF16
	.align 2, 0
_080ACF08: .4byte 0x220c0000
_080ACF0C:
	mov r1, r8
	ldrb r0, [r1, 0x2]
	lsls r0, 11
	str r0, [r5, 0xC]
	ldrb r0, [r1, 0x3]
_080ACF16:
	lsls r0, 11
	str r0, [r5, 0x10]
	ldr r0, [r5, 0xC]
	lsrs r1, r0, 31
	adds r0, r1
	asrs r0, 1
	str r0, [r5, 0x14]
	ldr r0, [r5, 0x10]
	lsrs r1, r0, 31
	adds r0, r1
	asrs r0, 1
	str r0, [r5, 0x18]
	ldrb r0, [r7, 0x1]
	strb r0, [r5, 0x1C]
	adds r2, r7, 0x4
	adds r4, r5, 0
	adds r4, 0x20
	ldrb r1, [r2, 0x2]
	movs r0, 0x4
	ands r0, r1
	cmp r0, 0
	bne _080ACF5A
	ldrb r0, [r7, 0x4]
	lsls r3, r0, 11
	str r3, [r5, 0x20]
	ldrb r1, [r2, 0x2]
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	beq _080ACF5A
	movs r1, 0x80
	lsls r1, 3
	adds r0, r3, r1
	str r0, [r5, 0x20]
_080ACF5A:
	ldrb r1, [r2, 0x3]
	movs r0, 0x4
	ands r0, r1
	cmp r0, 0
	bne _080ACF7C
	ldrb r0, [r2, 0x1]
	lsls r3, r0, 11
	str r3, [r4, 0x4]
	ldrb r1, [r2, 0x3]
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	beq _080ACF7C
	movs r2, 0x80
	lsls r2, 3
	adds r0, r3, r2
	str r0, [r4, 0x4]
_080ACF7C:
	ldr r3, [sp, 0xC]
	cmp r3, 0
	beq _080ACFD2
	ldrb r1, [r5, 0x1C]
	movs r4, 0x90
	lsls r4, 1
	adds r0, r5, r4
	movs r3, 0
	strb r1, [r0]
	movs r0, 0x92
	lsls r0, 1
	adds r2, r5, r0
	ldr r0, [r5, 0x20]
	ldr r1, [r5, 0x14]
	subs r0, r1
	str r0, [r2]
	movs r1, 0x96
	lsls r1, 1
	adds r2, r5, r1
	ldr r0, [r5, 0x20]
	ldr r1, [r5, 0x14]
	adds r0, r1
	str r0, [r2]
	adds r4, 0x8
	adds r2, r5, r4
	ldr r0, [r5, 0x24]
	ldr r1, [r5, 0x18]
	subs r0, r1
	str r0, [r2]
	movs r0, 0x98
	lsls r0, 1
	adds r2, r5, r0
	ldr r0, [r5, 0x24]
	ldr r1, [r5, 0x18]
	adds r0, r1
	str r0, [r2]
	movs r2, 0x9A
	lsls r2, 1
	adds r1, r5, r2
	adds r4, 0x10
	adds r0, r5, r4
	str r3, [r0]
	str r3, [r1]
_080ACFD2:
	adds r0, r5, 0
	adds r0, 0x28
	adds r1, r5, 0
	adds r1, 0x30
	bl sub_80A5778
	ldr r0, [sp, 0xC]
	cmp r0, 0
	beq _080AD01A
	movs r2, 0x9F
	lsls r2, 1
	adds r1, r5, r2
	movs r2, 0
	movs r0, 0x80
	lsls r0, 4
	strh r0, [r1]
	movs r3, 0x9E
	lsls r3, 1
	adds r1, r5, r3
	movs r0, 0x1
	strb r0, [r1]
	movs r4, 0xA0
	lsls r4, 1
	adds r0, r5, r4
	strh r2, [r0]
	movs r1, 0xA2
	lsls r1, 1
	adds r0, r5, r1
	movs r3, 0x6
	ldrsh r2, [r5, r3]
	subs r4, 0x24
	adds r1, r5, r4
	ldr r3, [r1]
	adds r1, r6, 0
	bl sub_80A7688
_080AD01A:
	adds r4, r5, 0
	adds r4, 0x38
	ldr r1, _080AD074
	mov r0, r9
	str r0, [sp]
	adds r0, r4, 0
	adds r2, r5, 0
	mov r3, r10
	bl sub_809D600
	ldr r2, [r7, 0x8]
	cmp r2, 0
	bne _080AD04C
	mov r1, r8
	movs r3, 0
	ldrsh r0, [r1, r3]
	cmp r0, 0x1
	bne _080AD048
	ldr r0, _080AD078
	movs r1, 0xB0
	lsls r1, 2
	adds r0, r1
	ldr r2, [r0]
_080AD048:
	cmp r2, 0
	beq _080AD060
_080AD04C:
	adds r0, r4, 0
	movs r1, 0
	bl sub_809D6D8
	ldr r3, _080AD07C
	adds r0, r4, 0
	movs r1, 0
	movs r2, 0
	bl sub_809D8C0
_080AD060:
	adds r0, r6, 0
_080AD062:
	add sp, 0x10
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	.align 2, 0
_080AD074: .4byte gUnknown_8118544
_080AD078: .4byte gUnknown_812F1F8
_080AD07C: .4byte gUnknown_81186CC
	thumb_func_end GroundEffect_Add

	thumb_func_start GroundEffect_Delete
GroundEffect_Delete:
	push {r4,lr}
	adds r2, r0, 0
	lsls r2, 16
	asrs r2, 16
	ldr r1, _080AD0BC
	lsls r0, r2, 3
	subs r0, r2
	lsls r0, 4
	adds r0, r2
	lsls r0, 2
	ldr r1, [r1]
	adds r4, r1, r0
	ldr r1, _080AD0C0
	movs r0, 0
	bl Log
	movs r1, 0xA2
	lsls r1, 1
	adds r0, r4, r1
	bl sub_80A7714
	adds r0, r4, 0
	adds r0, 0x38
	bl sub_809D648
	ldr r0, _080AD0C4
	strh r0, [r4, 0x6]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080AD0BC: .4byte gUnknown_3001B8C
_080AD0C0: .4byte gUnknown_81186D8
_080AD0C4: .4byte 0x0000ffff
	thumb_func_end GroundEffect_Delete

	thumb_func_start sub_80AD0C8
sub_80AD0C8:
	push {lr}
	adds r3, r1, 0
	lsls r0, 16
	asrs r0, 16
	ldr r2, _080AD108
	lsls r1, r0, 3
	subs r1, r0
	lsls r1, 4
	adds r1, r0
	lsls r1, 2
	ldr r0, [r2]
	adds r2, r0, r1
	movs r0, 0x6
	ldrsh r1, [r2, r0]
	movs r0, 0x1
	negs r0, r0
	cmp r1, r0
	beq _080AD102
	movs r1, 0x8E
	lsls r1, 1
	adds r0, r2, r1
	ldr r1, [r0]
	orrs r1, r3
	str r1, [r0]
	movs r3, 0xA2
	lsls r3, 1
	adds r0, r2, r3
	bl sub_80A6688
_080AD102:
	pop {r0}
	bx r0
	.align 2, 0
_080AD108: .4byte gUnknown_3001B8C
	thumb_func_end sub_80AD0C8

	thumb_func_start sub_80AD10C
sub_80AD10C:
	push {r4,lr}
	adds r4, r1, 0
	lsls r0, 16
	asrs r0, 16
	ldr r2, _080AD150
	lsls r1, r0, 3
	subs r1, r0
	lsls r1, 4
	adds r1, r0
	lsls r1, 2
	ldr r0, [r2]
	adds r3, r0, r1
	movs r0, 0x6
	ldrsh r1, [r3, r0]
	movs r0, 0x1
	negs r0, r0
	cmp r1, r0
	beq _080AD14A
	movs r0, 0x8E
	lsls r0, 1
	adds r2, r3, r0
	ldr r0, _080AD154
	eors r0, r4
	ldr r1, [r2]
	ands r1, r0
	str r1, [r2]
	movs r2, 0xA2
	lsls r2, 1
	adds r0, r3, r2
	bl sub_80A6688
_080AD14A:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080AD150: .4byte gUnknown_3001B8C
_080AD154: .4byte 0x337fffff
	thumb_func_end sub_80AD10C

	thumb_func_start sub_80AD158
sub_80AD158:
	push {lr}
	lsls r0, 16
	asrs r0, 16
	ldr r2, _080AD180
	lsls r1, r0, 3
	subs r1, r0
	lsls r1, 4
	adds r1, r0
	lsls r1, 2
	ldr r0, [r2]
	adds r2, r0, r1
	movs r0, 0x6
	ldrsh r1, [r2, r0]
	movs r0, 0x1
	negs r0, r0
	cmp r1, r0
	bne _080AD184
	movs r0, 0
	b _080AD188
	.align 2, 0
_080AD180: .4byte gUnknown_3001B8C
_080AD184:
	adds r0, r2, 0
	adds r0, 0x38
_080AD188:
	pop {r1}
	bx r1
	thumb_func_end sub_80AD158

	thumb_func_start sub_80AD18C
sub_80AD18C:
	push {r4,lr}
	adds r4, r1, 0
	lsls r0, 16
	asrs r0, 16
	lsls r2, 16
	asrs r3, r2, 16
	ldr r2, _080AD1B8
	lsls r1, r0, 3
	subs r1, r0
	lsls r1, 4
	adds r1, r0
	lsls r1, 2
	ldr r0, [r2]
	adds r2, r0, r1
	movs r0, 0x6
	ldrsh r1, [r2, r0]
	movs r0, 0x1
	negs r0, r0
	cmp r1, r0
	bne _080AD1BC
	movs r0, 0
	b _080AD1CC
	.align 2, 0
_080AD1B8: .4byte gUnknown_3001B8C
_080AD1BC:
	adds r0, r2, 0
	adds r0, 0x38
	adds r1, r4, 0
	adds r2, r3, 0
	bl sub_809D6E4
	lsls r0, 24
	lsrs r0, 24
_080AD1CC:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_80AD18C

	thumb_func_start GroundEffect_ExecuteScript
GroundEffect_ExecuteScript:
	push {r4-r6,lr}
	adds r3, r0, 0
	adds r5, r1, 0
	adds r6, r2, 0
	lsls r3, 16
	asrs r3, 16
	ldr r1, _080AD20C
	lsls r0, r3, 3
	subs r0, r3
	lsls r0, 4
	adds r0, r3
	lsls r0, 2
	ldr r1, [r1]
	adds r4, r1, r0
	ldr r1, _080AD210
	movs r0, 0
	adds r2, r3, 0
	bl Log
	movs r0, 0x6
	ldrsh r1, [r4, r0]
	movs r0, 0x1
	negs r0, r0
	cmp r1, r0
	bne _080AD214
	movs r0, 0
	b _080AD22C
	.align 2, 0
_080AD20C: .4byte gUnknown_3001B8C
_080AD210: .4byte gUnknown_81186F4
_080AD214:
	adds r0, r4, 0
	adds r0, 0x38
	ldr r3, _080AD234
	adds r1, r5, 0
	adds r2, r6, 0
	bl GroundScript_ExecutePP
	movs r0, 0x9E
	lsls r0, 1
	adds r1, r4, r0
	movs r0, 0x1
	strb r0, [r1]
_080AD22C:
	pop {r4-r6}
	pop {r1}
	bx r1
	.align 2, 0
_080AD234: .4byte gUnknown_811872C
	thumb_func_end GroundEffect_ExecuteScript

	thumb_func_start sub_80AD238
sub_80AD238:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	lsls r0, 16
	asrs r7, r0, 16
	ldr r0, _080AD28C
	ldr r4, [r0]
	movs r5, 0
	movs r0, 0x1
	negs r0, r0
	mov r8, r0
	movs r6, 0x80
	lsls r6, 9
_080AD252:
	movs r1, 0x6
	ldrsh r0, [r4, r1]
	cmp r0, r8
	beq _080AD26A
	adds r0, r4, 0
	adds r0, 0x38
	adds r1, r7, 0
	bl sub_809D968
	orrs r5, r0
	lsls r0, r5, 24
	lsrs r5, r0, 24
_080AD26A:
	adds r0, r6, 0
	movs r1, 0x80
	lsls r1, 9
	adds r6, r1
	asrs r0, 16
	movs r1, 0xE2
	lsls r1, 1
	adds r4, r1
	cmp r0, 0xF
	ble _080AD252
	adds r0, r5, 0
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r1}
	bx r1
	.align 2, 0
_080AD28C: .4byte gUnknown_3001B8C
	thumb_func_end sub_80AD238

	thumb_func_start sub_80AD290
sub_80AD290:
	push {r4-r7,lr}
	ldr r0, _080AD2D4
	ldr r4, [r0]
	movs r5, 0
	movs r7, 0x1
	negs r7, r7
	movs r6, 0x80
	lsls r6, 9
_080AD2A0:
	movs r1, 0x6
	ldrsh r0, [r4, r1]
	cmp r0, r7
	beq _080AD2B6
	adds r0, r4, 0
	adds r0, 0x38
	bl sub_809D92C
	orrs r5, r0
	lsls r0, r5, 24
	lsrs r5, r0, 24
_080AD2B6:
	adds r0, r6, 0
	movs r1, 0x80
	lsls r1, 9
	adds r6, r1
	asrs r0, 16
	movs r1, 0xE2
	lsls r1, 1
	adds r4, r1
	cmp r0, 0xF
	ble _080AD2A0
	adds r0, r5, 0
	pop {r4-r7}
	pop {r1}
	bx r1
	.align 2, 0
_080AD2D4: .4byte gUnknown_3001B8C
	thumb_func_end sub_80AD290

	thumb_func_start sub_80AD2D8
sub_80AD2D8:
	lsls r0, 16
	asrs r0, 16
	ldr r2, _080AD2F4
	lsls r1, r0, 3
	subs r1, r0
	lsls r1, 4
	adds r1, r0
	lsls r1, 2
	ldr r0, [r2]
	adds r0, r1
	movs r1, 0x6
	ldrsh r0, [r0, r1]
	bx lr
	.align 2, 0
_080AD2F4: .4byte gUnknown_3001B8C
	thumb_func_end sub_80AD2D8

	thumb_func_start sub_80AD2F8
sub_80AD2F8:
	lsls r0, 16
	asrs r0, 16
	ldr r3, _080AD31C
	lsls r2, r0, 3
	subs r2, r0
	lsls r2, 4
	adds r2, r0
	lsls r2, 2
	ldr r0, [r3]
	adds r0, r2
	movs r3, 0x8E
	lsls r3, 1
	adds r2, r0, r3
	ldr r2, [r2]
	str r2, [r1]
	movs r1, 0x6
	ldrsh r0, [r0, r1]
	bx lr
	.align 2, 0
_080AD31C: .4byte gUnknown_3001B8C
	thumb_func_end sub_80AD2F8

	thumb_func_start sub_80AD320
sub_80AD320:
	push {lr}
	adds r3, r1, 0
	lsls r0, 16
	asrs r0, 16
	ldr r2, _080AD34C
	lsls r1, r0, 3
	subs r1, r0
	lsls r1, 4
	adds r1, r0
	lsls r1, 2
	ldr r0, [r2]
	adds r2, r0, r1
	movs r0, 0x6
	ldrsh r1, [r2, r0]
	movs r0, 0x1
	negs r0, r0
	cmp r1, r0
	bne _080AD350
	movs r0, 0
	str r0, [r3]
	str r0, [r3, 0x4]
	b _080AD358
	.align 2, 0
_080AD34C: .4byte gUnknown_3001B8C
_080AD350:
	ldr r0, [r2, 0xC]
	ldr r1, [r2, 0x10]
	str r0, [r3]
	str r1, [r3, 0x4]
_080AD358:
	movs r1, 0x6
	ldrsh r0, [r2, r1]
	pop {r1}
	bx r1
	thumb_func_end sub_80AD320

	thumb_func_start sub_80AD360
sub_80AD360:
	push {lr}
	adds r3, r1, 0
	lsls r0, 16
	asrs r0, 16
	ldr r2, _080AD38C
	lsls r1, r0, 3
	subs r1, r0
	lsls r1, 4
	adds r1, r0
	lsls r1, 2
	ldr r0, [r2]
	adds r2, r0, r1
	movs r0, 0x6
	ldrsh r1, [r2, r0]
	movs r0, 0x1
	negs r0, r0
	cmp r1, r0
	bne _080AD390
	movs r0, 0
	str r0, [r3]
	b _080AD3AA
	.align 2, 0
_080AD38C: .4byte gUnknown_3001B8C
_080AD390:
	movs r1, 0x92
	lsls r1, 1
	adds r0, r2, r1
	ldr r0, [r0]
	ldr r1, [r2, 0x14]
	adds r0, r1
	str r0, [r3]
	movs r1, 0x94
	lsls r1, 1
	adds r0, r2, r1
	ldr r0, [r0]
	ldr r1, [r2, 0x18]
	adds r0, r1
_080AD3AA:
	str r0, [r3, 0x4]
	movs r1, 0x6
	ldrsh r0, [r2, r1]
	pop {r1}
	bx r1
	thumb_func_end sub_80AD360

	thumb_func_start sub_80AD3B4
sub_80AD3B4:
	push {r4,lr}
	lsls r0, 16
	asrs r0, 16
	ldr r3, _080AD3DC
	lsls r2, r0, 3
	subs r2, r0
	lsls r2, 4
	adds r2, r0
	lsls r2, 2
	ldr r4, [r3]
	adds r4, r2
	adds r0, r4, 0
	bl sub_80AD3E0
	movs r1, 0x6
	ldrsh r0, [r4, r1]
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_080AD3DC: .4byte gUnknown_3001B8C
	thumb_func_end sub_80AD3B4

	thumb_func_start sub_80AD3E0
sub_80AD3E0:
	push {r4-r7,lr}
	mov r12, r0
	ldr r3, [r1]
	ldr r2, [r0, 0x14]
	subs r6, r3, r2
	ldr r1, [r1, 0x4]
	ldr r0, [r0, 0x18]
	subs r7, r1, r0
	adds r4, r3, r2
	adds r5, r1, r0
	mov r1, r12
	ldr r0, [r1, 0x28]
	cmp r6, r0
	blt _080AD40E
	ldr r0, [r1, 0x30]
	cmp r4, r0
	bge _080AD40E
	ldr r0, [r1, 0x2C]
	cmp r7, r0
	blt _080AD40E
	ldr r0, [r1, 0x34]
	cmp r5, r0
	blt _080AD412
_080AD40E:
	movs r0, 0x1
	b _080AD428
_080AD412:
	movs r0, 0x92
	lsls r0, 1
	add r0, r12
	str r6, [r0]
	str r7, [r0, 0x4]
	movs r0, 0x96
	lsls r0, 1
	add r0, r12
	str r4, [r0]
	str r5, [r0, 0x4]
	movs r0, 0
_080AD428:
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_80AD3E0

	thumb_func_start sub_80AD430
sub_80AD430:
	push {r4-r6,lr}
	mov r12, r0
	movs r0, 0x92
	lsls r0, 1
	add r0, r12
	ldr r0, [r0]
	ldr r2, [r1]
	adds r5, r0, r2
	movs r0, 0x94
	lsls r0, 1
	add r0, r12
	ldr r0, [r0]
	ldr r1, [r1, 0x4]
	adds r6, r0, r1
	movs r0, 0x96
	lsls r0, 1
	add r0, r12
	ldr r0, [r0]
	adds r3, r0, r2
	movs r0, 0x98
	lsls r0, 1
	add r0, r12
	ldr r0, [r0]
	adds r4, r0, r1
	mov r0, r12
	ldr r1, [r0, 0x28]
	cmp r5, r1
	bge _080AD470
	adds r5, r1, 0
	ldr r0, [r0, 0xC]
	adds r3, r1, r0
	b _080AD47E
_080AD470:
	mov r2, r12
	ldr r1, [r2, 0x30]
	cmp r3, r1
	blt _080AD47E
	ldr r0, [r2, 0xC]
	subs r5, r1, r0
	adds r3, r1, 0
_080AD47E:
	mov r0, r12
	ldr r1, [r0, 0x2C]
	cmp r6, r1
	bge _080AD48E
	adds r6, r1, 0
	ldr r0, [r0, 0x10]
	adds r4, r1, r0
	b _080AD49C
_080AD48E:
	mov r2, r12
	ldr r1, [r2, 0x34]
	cmp r4, r1
	blt _080AD49C
	ldr r0, [r2, 0x10]
	subs r6, r1, r0
	adds r4, r1, 0
_080AD49C:
	movs r0, 0x92
	lsls r0, 1
	add r0, r12
	str r5, [r0]
	str r6, [r0, 0x4]
	movs r0, 0x96
	lsls r0, 1
	add r0, r12
	str r3, [r0]
	str r4, [r0, 0x4]
	movs r0, 0
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end sub_80AD430

	thumb_func_start sub_80AD4B8
sub_80AD4B8:
	movs r1, 0x4
	ldrsh r0, [r0, r1]
	bx lr
	thumb_func_end sub_80AD4B8

	thumb_func_start sub_80AD4C0
sub_80AD4C0:
	ldr r2, [r0, 0xC]
	ldr r3, [r0, 0x10]
	str r2, [r1]
	str r3, [r1, 0x4]
	bx lr
	thumb_func_end sub_80AD4C0

	thumb_func_start sub_80AD4CC
sub_80AD4CC:
	push {r4,lr}
	adds r3, r0, 0
	adds r4, r1, 0
	cmp r4, 0
	beq _080AD50C
	movs r0, 0x92
	lsls r0, 1
	adds r2, r3, r0
	ldr r1, [r4]
	ldr r0, [r3, 0x14]
	subs r0, r1, r0
	str r0, [r2]
	movs r0, 0x96
	lsls r0, 1
	adds r2, r3, r0
	ldr r0, [r3, 0x14]
	adds r1, r0
	str r1, [r2]
	movs r0, 0x94
	lsls r0, 1
	adds r2, r3, r0
	ldr r1, [r4, 0x4]
	ldr r0, [r3, 0x18]
	subs r0, r1, r0
	str r0, [r2]
	movs r0, 0x98
	lsls r0, 1
	adds r2, r3, r0
	ldr r0, [r3, 0x18]
	adds r1, r0
	str r1, [r2]
	b _080AD572
_080AD50C:
	movs r0, 0x92
	lsls r0, 1
	adds r2, r3, r0
	ldr r0, [r3, 0x20]
	ldr r1, [r3, 0x14]
	subs r0, r1
	str r0, [r2]
	movs r0, 0x96
	lsls r0, 1
	adds r2, r3, r0
	ldr r0, [r3, 0x20]
	ldr r1, [r3, 0x14]
	adds r0, r1
	str r0, [r2]
	movs r0, 0x94
	lsls r0, 1
	adds r2, r3, r0
	ldr r0, [r3, 0x24]
	ldr r1, [r3, 0x18]
	subs r0, r1
	str r0, [r2]
	movs r0, 0x98
	lsls r0, 1
	adds r2, r3, r0
	ldr r0, [r3, 0x24]
	ldr r1, [r3, 0x18]
	adds r0, r1
	str r0, [r2]
	movs r2, 0x9A
	lsls r2, 1
	adds r1, r3, r2
	adds r2, 0x4
	adds r0, r3, r2
	str r4, [r0]
	str r4, [r1]
	movs r0, 0x90
	lsls r0, 1
	adds r2, r3, r0
	movs r1, 0
	ldrsb r1, [r2, r1]
	movs r0, 0x1C
	ldrsb r0, [r3, r0]
	cmp r1, r0
	beq _080AD56E
	movs r0, 0x9E
	lsls r0, 1
	adds r1, r3, r0
	movs r0, 0x1
	strb r0, [r1]
_080AD56E:
	ldrb r0, [r3, 0x1C]
	strb r0, [r2]
_080AD572:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_80AD4CC

	thumb_func_start sub_80AD578
sub_80AD578:
	push {r4,lr}
	ldr r3, [r1]
	ldr r4, [r1, 0x4]
	str r3, [r0, 0x28]
	str r4, [r0, 0x2C]
	ldr r1, [r2]
	ldr r2, [r2, 0x4]
	str r1, [r0, 0x30]
	str r2, [r0, 0x34]
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_80AD578

	thumb_func_start sub_80AD590
sub_80AD590:
	adds r3, r0, 0
	movs r2, 0x92
	lsls r2, 1
	adds r0, r3, r2
	ldr r0, [r0]
	ldr r2, [r3, 0x14]
	adds r0, r2
	str r0, [r1]
	movs r2, 0x94
	lsls r2, 1
	adds r0, r3, r2
	ldr r0, [r0]
	ldr r2, [r3, 0x18]
	adds r0, r2
	str r0, [r1, 0x4]
	bx lr
	thumb_func_end sub_80AD590

	thumb_func_start sub_80AD5B0
sub_80AD5B0:
	push {lr}
	bl sub_80AD3E0
	pop {r1}
	bx r1
	thumb_func_end sub_80AD5B0

	thumb_func_start sub_80AD5BC
sub_80AD5BC:
	push {r4,lr}
	adds r3, r0, 0
	movs r4, 0x9A
	lsls r4, 1
	adds r0, r3, r4
	ldr r0, [r0]
	str r0, [r1]
	movs r1, 0x9C
	lsls r1, 1
	adds r0, r3, r1
	ldr r0, [r0]
	str r0, [r2]
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_80AD5BC

	thumb_func_start sub_80AD5DC
sub_80AD5DC:
	movs r2, 0x9A
	lsls r2, 1
	adds r0, r2
	str r1, [r0]
	bx lr
	thumb_func_end sub_80AD5DC

	thumb_func_start sub_80AD5E8
sub_80AD5E8:
	movs r2, 0x90
	lsls r2, 1
	adds r0, r2
	ldrb r0, [r0]
	strb r0, [r1]
	bx lr
	thumb_func_end sub_80AD5E8

	thumb_func_start sub_80AD5F4
sub_80AD5F4:
	push {lr}
	adds r2, r0, 0
	lsls r1, 24
	asrs r1, 24
	movs r0, 0x1
	negs r0, r0
	cmp r1, r0
	beq _080AD60C
	movs r3, 0x90
	lsls r3, 1
	adds r0, r2, r3
	strb r1, [r0]
_080AD60C:
	pop {r0}
	bx r0
	thumb_func_end sub_80AD5F4

	thumb_func_start sub_80AD610
sub_80AD610:
	push {r4,r5,lr}
	lsls r1, 16
	adds r3, r0, 0
	movs r0, 0xFF
	lsls r0, 16
	ands r0, r1
	lsrs r0, 16
	cmp r0, 0
	beq _080AD630
	ldr r1, _080AD62C
	lsls r0, 1
	adds r0, r1
	b _080AD636
	.align 2, 0
_080AD62C: .4byte gUnknown_81185F2
_080AD630:
	movs r5, 0x9F
	lsls r5, 1
	adds r0, r3, r5
_080AD636:
	movs r1, 0
	ldrsh r2, [r0, r1]
	movs r5, 0x9F
	lsls r5, 1
	adds r1, r3, r5
	ldrh r4, [r1]
	movs r5, 0
	ldrsh r0, [r1, r5]
	cmp r0, r2
	beq _080AD654
	strh r2, [r1]
	movs r0, 0x9E
	lsls r0, 1
	adds r1, r3, r0
	b _080AD664
_080AD654:
	movs r0, 0x80
	lsls r0, 5
	ands r0, r4
	cmp r0, 0
	beq _080AD668
	movs r5, 0x9E
	lsls r5, 1
	adds r1, r3, r5
_080AD664:
	movs r0, 0x1
	strb r0, [r1]
_080AD668:
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_80AD610

	thumb_func_start sub_80AD670
sub_80AD670:
	push {lr}
	lsls r1, 16
	asrs r1, 16
	adds r2, r1, 0
	cmp r1, 0
	bne _080AD682
	movs r1, 0xE0
	lsls r1, 1
	adds r2, r1, 0
_080AD682:
	movs r1, 0xA0
	lsls r1, 1
	adds r0, r1
	strh r2, [r0]
	pop {r0}
	bx r0
	thumb_func_end sub_80AD670

	thumb_func_start sub_80AD690
sub_80AD690:
	push {lr}
	adds r1, r0, 0
	movs r2, 0x9E
	lsls r2, 1
	adds r0, r1, r2
	ldrb r0, [r0]
	cmp r0, 0
	bne _080AD6AE
	adds r2, 0x8
	adds r0, r1, r2
	bl sub_80A66F8
	lsls r0, 24
	lsrs r0, 24
	b _080AD6B0
_080AD6AE:
	movs r0, 0x1
_080AD6B0:
	pop {r1}
	bx r1
	thumb_func_end sub_80AD690

	thumb_func_start sub_80AD6B4
sub_80AD6B4:
	push {lr}
	adds r1, r0, 0
	movs r2, 0xA0
	lsls r2, 1
	adds r0, r1, r2
	movs r2, 0
	ldrsh r0, [r0, r2]
	cmp r0, 0
	bne _080AD6D6
	movs r2, 0xA2
	lsls r2, 1
	adds r0, r1, r2
	bl sub_80A671C
	lsls r0, 24
	lsrs r0, 24
	b _080AD6D8
_080AD6D6:
	movs r0, 0x1
_080AD6D8:
	pop {r1}
	bx r1
	thumb_func_end sub_80AD6B4

	thumb_func_start sub_80AD6DC
sub_80AD6DC:
	movs r2, 0x8E
	lsls r2, 1
	adds r0, r2
	ldr r0, [r0]
	str r0, [r1]
	bx lr
	thumb_func_end sub_80AD6DC

	thumb_func_start sub_80AD6E8
sub_80AD6E8:
	push {lr}
	movs r2, 0x4
	ldrsh r0, [r0, r2]
	bl sub_80AD0C8
	pop {r0}
	bx r0
	thumb_func_end sub_80AD6E8

	thumb_func_start sub_80AD6F8
sub_80AD6F8:
	push {lr}
	movs r2, 0x4
	ldrsh r0, [r0, r2]
	bl sub_80AD10C
	pop {r0}
	bx r0
	thumb_func_end sub_80AD6F8

	thumb_func_start sub_80AD708
sub_80AD708:
	push {lr}
	bl sub_80AD430
	pop {r1}
	bx r1
	thumb_func_end sub_80AD708

	thumb_func_start GroundEffect_Action
GroundEffect_Action:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	ldr r0, _080AD754
	ldr r5, [r0]
	movs r7, 0
	movs r0, 0x1
	negs r0, r0
	mov r8, r0
	movs r1, 0x9E
	lsls r1, 1
	adds r6, r5, r1
_080AD72C:
	movs r3, 0x6
	ldrsh r0, [r5, r3]
	cmp r0, r8
	beq _080AD78A
	adds r4, r5, 0
	adds r4, 0x38
	adds r0, r4, 0
	ldr r1, _080AD758
	bl HandleAction
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0
	beq _080AD75C
	cmp r0, 0x4
	bne _080AD768
	adds r0, r7, 0
	bl GroundEffect_Delete
	b _080AD78A
	.align 2, 0
_080AD754: .4byte gUnknown_3001B8C
_080AD758: .4byte gUnknown_811874C
_080AD75C:
	adds r0, r4, 0
	movs r1, 0
	movs r2, 0x1
	ldr r3, _080AD7A8
	bl sub_809D8C0
_080AD768:
	ldrb r0, [r6]
	cmp r0, 0
	beq _080AD78A
	movs r0, 0
	strb r0, [r6]
	movs r1, 0xA2
	lsls r1, 1
	adds r0, r5, r1
	ldrh r2, [r6, 0x2]
	movs r3, 0xF8
	lsls r3, 5
	adds r1, r3, 0
	ands r1, r2
	lsls r2, 24
	asrs r2, 24
	bl sub_80A6EFC
_080AD78A:
	adds r0, r7, 0x1
	lsls r0, 16
	asrs r7, r0, 16
	movs r0, 0xE2
	lsls r0, 1
	adds r6, r0
	adds r5, r0
	cmp r7, 0xF
	ble _080AD72C
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_080AD7A8: .4byte gUnknown_8118758
	thumb_func_end GroundEffect_Action

	thumb_func_start sub_80AD7AC
sub_80AD7AC:
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	sub sp, 0x8
	ldr r0, _080AD864
	ldr r6, [r0]
	movs r0, 0
	mov r8, r0
	movs r1, 0x1
	negs r1, r1
	mov r9, r1
	movs r2, 0x90
	lsls r2, 1
	adds r4, r6, r2
_080AD7CA:
	movs r0, 0x6
	ldrsh r1, [r6, r0]
	mov r2, r9
	lsls r0, r2, 16
	asrs r0, 16
	cmp r1, r0
	beq _080AD83C
	ldr r0, [r4, 0x4]
	ldr r1, [r6, 0x14]
	adds r0, r1
	str r0, [sp]
	ldr r0, [r4, 0x8]
	ldr r1, [r6, 0x18]
	adds r0, r1
	str r0, [sp, 0x4]
	ldr r1, [r4, 0x14]
	ldr r0, [r4, 0x18]
	adds r7, r1, r0
	movs r0, 0xA2
	lsls r0, 1
	adds r5, r6, r0
	adds r0, r5, 0
	bl sub_80A66D4
	lsls r0, 24
	cmp r0, 0
	beq _080AD818
	movs r0, 0
	strb r0, [r4, 0x1C]
	ldrh r2, [r4, 0x1E]
	movs r0, 0xF8
	lsls r0, 5
	adds r1, r0, 0
	ands r1, r2
	lsls r2, 24
	asrs r2, 24
	adds r0, r5, 0
	bl sub_80A6EFC
_080AD818:
	movs r1, 0x20
	ldrsh r0, [r4, r1]
	cmp r0, 0
	beq _080AD832
	adds r1, r0, 0
	movs r2, 0
	ldrsb r2, [r4, r2]
	adds r0, r5, 0
	movs r3, 0
	bl sub_80A7040
	movs r0, 0
	strh r0, [r4, 0x20]
_080AD832:
	adds r0, r5, 0
	mov r1, sp
	adds r2, r7, 0
	bl sub_80A7720
_080AD83C:
	mov r0, r8
	adds r0, 0x1
	lsls r0, 16
	asrs r0, 16
	mov r8, r0
	movs r0, 0xE2
	lsls r0, 1
	adds r4, r0
	adds r6, r0
	mov r1, r8
	cmp r1, 0xF
	ble _080AD7CA
	add sp, 0x8
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_080AD864: .4byte gUnknown_3001B8C
	thumb_func_end sub_80AD7AC

	thumb_func_start sub_80AD868
sub_80AD868:
	ldr r1, _080AD870
	movs r0, 0
	str r0, [r1]
	bx lr
	.align 2, 0
_080AD870: .4byte gUnknown_203B4B8
	thumb_func_end sub_80AD868

	thumb_func_start sub_80AD874
sub_80AD874:
	ldr r1, _080AD87C
	movs r0, 0
	str r0, [r1]
	bx lr
	.align 2, 0
_080AD87C: .4byte gUnknown_203B4B8
	thumb_func_end sub_80AD874

	thumb_func_start GroundLink_Select
GroundLink_Select:
	push {lr}
	lsls r0, 16
	asrs r0, 16
	ldr r1, _080AD898
	bl sub_80A77D0
	ldr r1, _080AD89C
	ldr r0, [r0, 0x8]
	str r0, [r1]
	pop {r0}
	bx r0
	.align 2, 0
_080AD898: .4byte gUnknown_8118798
_080AD89C: .4byte gUnknown_203B4B8
	thumb_func_end GroundLink_Select

	thumb_func_start sub_80AD8A0
sub_80AD8A0:
	lsls r0, 16
	ldr r1, _080AD8B0
	asrs r0, 13
	ldr r1, [r1]
	adds r1, r0
	adds r0, r1, 0
	bx lr
	.align 2, 0
_080AD8B0: .4byte gUnknown_203B4B8
	thumb_func_end sub_80AD8A0

	thumb_func_start sub_80AD8B4
sub_80AD8B4:
	push {r4,lr}
	adds r4, r1, 0
	lsls r0, 16
	ldr r1, _080AD910
	asrs r0, 13
	ldr r1, [r1]
	adds r2, r1, r0
	ldrb r1, [r2, 0x2]
	movs r0, 0x4
	ands r0, r1
	cmp r0, 0
	bne _080AD8E4
	ldrb r0, [r2]
	lsls r3, r0, 11
	str r3, [r4]
	ldrb r1, [r2, 0x2]
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	beq _080AD8E4
	movs r1, 0x80
	lsls r1, 3
	adds r0, r3, r1
	str r0, [r4]
_080AD8E4:
	ldrb r1, [r2, 0x3]
	movs r0, 0x4
	ands r0, r1
	cmp r0, 0
	bne _080AD906
	ldrb r0, [r2, 0x1]
	lsls r3, r0, 11
	str r3, [r4, 0x4]
	ldrb r1, [r2, 0x3]
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	beq _080AD906
	movs r1, 0x80
	lsls r1, 3
	adds r0, r3, r1
	str r0, [r4, 0x4]
_080AD906:
	ldrb r0, [r2, 0x6]
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_080AD910: .4byte gUnknown_203B4B8
	thumb_func_end sub_80AD8B4

	thumb_func_start sub_80AD914
sub_80AD914:
	push {r4,r5,lr}
	adds r4, r1, 0
	adds r5, r2, 0
	lsls r0, 16
	ldr r1, _080AD98C
	asrs r0, 13
	ldr r1, [r1]
	adds r2, r1, r0
	ldr r0, [r3]
	ldr r1, [r3, 0x4]
	str r0, [r4]
	str r1, [r4, 0x4]
	ldrb r1, [r2, 0x2]
	movs r0, 0x4
	ands r0, r1
	cmp r0, 0
	bne _080AD94E
	ldrb r0, [r2]
	lsls r3, r0, 11
	str r3, [r4]
	ldrb r1, [r2, 0x2]
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	beq _080AD94E
	movs r1, 0x80
	lsls r1, 3
	adds r0, r3, r1
	str r0, [r4]
_080AD94E:
	ldrb r1, [r2, 0x3]
	movs r0, 0x4
	ands r0, r1
	cmp r0, 0
	bne _080AD970
	ldrb r0, [r2, 0x1]
	lsls r3, r0, 11
	str r3, [r4, 0x4]
	ldrb r1, [r2, 0x3]
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	beq _080AD970
	movs r1, 0x80
	lsls r1, 3
	adds r0, r3, r1
	str r0, [r4, 0x4]
_080AD970:
	ldrb r1, [r2, 0x4]
	lsls r1, 11
	ldr r0, [r4]
	adds r0, r1
	str r0, [r5]
	ldrb r1, [r2, 0x5]
	lsls r1, 11
	ldr r0, [r4, 0x4]
	adds r0, r1
	str r0, [r5, 0x4]
	ldrb r0, [r2, 0x6]
	pop {r4,r5}
	pop {r1}
	bx r1
	.align 2, 0
_080AD98C: .4byte gUnknown_203B4B8
	thumb_func_end sub_80AD914

	thumb_func_start sub_80AD990
sub_80AD990:
	push {r4,lr}
	ldr r4, _080AD9C8
	movs r0, 0x80
	lsls r0, 3
	movs r1, 0x6
	bl MemoryAlloc
	str r0, [r4]
	adds r1, r0, 0
	ldr r0, _080AD9CC
	adds r4, r0, 0
	movs r2, 0x80
	lsls r2, 9
	adds r3, r2, 0
_080AD9AC:
	ldrh r0, [r1, 0x2]
	orrs r0, r4
	strh r0, [r1, 0x2]
	adds r0, r2, 0
	adds r2, r3
	asrs r0, 16
	adds r1, 0x20
	cmp r0, 0x1F
	ble _080AD9AC
	bl sub_80AD9D0
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080AD9C8: .4byte gUnknown_3001B90
_080AD9CC: .4byte 0x0000ffff
	thumb_func_end sub_80AD990

	thumb_func_start sub_80AD9D0
sub_80AD9D0:
	push {r4-r6,lr}
	ldr r0, _080ADA04
	ldr r4, [r0]
	movs r1, 0
	movs r6, 0x1
	negs r6, r6
	movs r5, 0x80
	lsls r5, 9
_080AD9E0:
	movs r2, 0x2
	ldrsh r0, [r4, r2]
	cmp r0, r6
	beq _080AD9EE
	adds r0, r1, 0
	bl GroundEvent_Delete
_080AD9EE:
	adds r0, r5, 0
	movs r1, 0x80
	lsls r1, 9
	adds r5, r1
	asrs r1, r0, 16
	adds r4, 0x20
	cmp r1, 0x1F
	ble _080AD9E0
	pop {r4-r6}
	pop {r0}
	bx r0
	.align 2, 0
_080ADA04: .4byte gUnknown_3001B90
	thumb_func_end sub_80AD9D0

	thumb_func_start sub_80ADA08
sub_80ADA08:
	push {r4,lr}
	bl sub_80AD9D0
	ldr r4, _080ADA20
	ldr r0, [r4]
	bl MemoryFree
	movs r0, 0
	str r0, [r4]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080ADA20: .4byte gUnknown_3001B90
	thumb_func_end sub_80ADA08

	thumb_func_start GroundEvent_Select
GroundEvent_Select:
	push {r4-r7,lr}
	sub sp, 0x4
	adds r4, r0, 0
	lsls r4, 16
	asrs r4, 16
	lsls r1, 16
	asrs r7, r1, 16
	lsls r2, 24
	asrs r6, r2, 24
	ldr r1, _080ADA88
	adds r0, r4, 0
	bl sub_80A77D0
	adds r5, r0, 0
	ldr r1, _080ADA8C
	str r6, [sp]
	movs r0, 0
	adds r2, r4, 0
	adds r3, r7, 0
	bl Log
	lsls r1, r7, 3
	ldr r0, [r5, 0x4]
	adds r0, r1
	lsls r1, r6, 2
	adds r1, r6
	lsls r1, 3
	ldr r0, [r0, 0x4]
	adds r0, r1
	ldr r5, [r0, 0x1C]
	ldr r0, [r0, 0x18]
	cmp r0, 0
	ble _080ADA7E
	adds r4, r0, 0
_080ADA68:
	movs r0, 0x1
	negs r0, r0
	adds r1, r5, 0
	adds r2, r7, 0
	adds r3, r6, 0
	bl GroundEvent_Add
	subs r4, 0x1
	adds r5, 0xC
	cmp r4, 0
	bne _080ADA68
_080ADA7E:
	add sp, 0x4
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_080ADA88: .4byte gUnknown_81187DC
_080ADA8C: .4byte gUnknown_81187E8
	thumb_func_end GroundEvent_Select

	thumb_func_start GroundEvent_Cancel
GroundEvent_Cancel:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	lsls r0, 16
	asrs r7, r0, 16
	lsls r1, 24
	asrs r5, r1, 24
	ldr r1, _080ADAF8
	movs r0, 0
	adds r2, r7, 0
	adds r3, r5, 0
	bl Log
	movs r1, 0
	ldr r0, _080ADAFC
	ldr r4, [r0]
	movs r0, 0x1
	negs r0, r0
	mov r8, r0
	movs r6, 0x80
	lsls r6, 9
_080ADABA:
	movs r2, 0x2
	ldrsh r0, [r4, r2]
	cmp r0, r8
	beq _080ADADC
	movs r2, 0x4
	ldrsh r0, [r4, r2]
	cmp r0, r7
	bne _080ADADC
	cmp r5, 0
	blt _080ADAD6
	movs r0, 0x6
	ldrsb r0, [r4, r0]
	cmp r0, r5
	bne _080ADADC
_080ADAD6:
	adds r0, r1, 0
	bl GroundEvent_Delete
_080ADADC:
	adds r0, r6, 0
	movs r1, 0x80
	lsls r1, 9
	adds r6, r1
	asrs r1, r0, 16
	adds r4, 0x20
	cmp r1, 0x1F
	ble _080ADABA
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_080ADAF8: .4byte gUnknown_811880C
_080ADAFC: .4byte gUnknown_3001B90
	thumb_func_end GroundEvent_Cancel

	thumb_func_start GroundEvent_Add
GroundEvent_Add:
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	sub sp, 0x14
	mov r8, r1
	lsls r0, 16
	asrs r7, r0, 16
	lsls r2, 16
	asrs r6, r2, 16
	lsls r3, 24
	asrs r3, 24
	mov r9, r3
	ldr r5, [r1, 0x8]
	cmp r7, 0
	bge _080ADB60
	ldr r0, _080ADB38
	ldr r4, [r0]
	movs r2, 0
	movs r0, 0x2
	ldrsh r1, [r4, r0]
	movs r0, 0x1
	negs r0, r0
	cmp r1, r0
	bne _080ADB3C
	movs r7, 0
	b _080ADB68
	.align 2, 0
_080ADB38: .4byte gUnknown_3001B90
_080ADB3C:
	adds r0, r2, 0x1
	lsls r0, 16
	asrs r2, r0, 16
	adds r4, 0x20
	cmp r2, 0x1F
	bgt _080ADB56
	movs r3, 0x2
	ldrsh r1, [r4, r3]
	movs r0, 0x1
	negs r0, r0
	cmp r1, r0
	bne _080ADB3C
	adds r7, r2, 0
_080ADB56:
	cmp r7, 0
	bge _080ADB68
	movs r0, 0x1
	negs r0, r0
	b _080ADC24
_080ADB60:
	ldr r0, _080ADBA0
	lsls r1, r7, 5
	ldr r0, [r0]
	adds r4, r0, r1
_080ADB68:
	ldr r1, _080ADBA4
	movs r0, 0
	ldrsh r3, [r5, r0]
	str r6, [sp]
	mov r2, r9
	str r2, [sp, 0x4]
	mov r2, r8
	ldr r0, [r2, 0x8]
	ldr r0, [r0, 0x8]
	str r0, [sp, 0x8]
	movs r0, 0
	adds r2, r7, 0
	bl Log
	strh r7, [r4]
	ldrh r0, [r5]
	strh r0, [r4, 0x2]
	strh r6, [r4, 0x4]
	mov r3, r9
	strb r3, [r4, 0x6]
	movs r6, 0x2
	ldrsh r0, [r5, r6]
	cmp r0, 0x1
	blt _080ADBA8
	cmp r0, 0x2
	bgt _080ADBA8
	movs r0, 0x60
	b _080ADBAA
	.align 2, 0
_080ADBA0: .4byte gUnknown_3001B90
_080ADBA4: .4byte gUnknown_8118828
_080ADBA8:
	movs r0, 0x20
_080ADBAA:
	str r0, [r4, 0x8]
	mov r3, r8
	ldrb r0, [r3]
	lsls r1, r0, 11
	ldrb r0, [r3, 0x1]
	lsls r2, r0, 11
	mov r5, r8
	adds r5, 0x4
	add r6, sp, 0xC
	mov r12, r6
	ldrb r6, [r5, 0x2]
	movs r0, 0x4
	ands r0, r6
	cmp r0, 0
	bne _080ADBDE
	ldrb r0, [r3, 0x4]
	lsls r3, r0, 11
	str r3, [sp, 0xC]
	movs r0, 0x2
	ands r0, r6
	cmp r0, 0
	beq _080ADBDE
	movs r6, 0x80
	lsls r6, 3
	adds r0, r3, r6
	str r0, [sp, 0xC]
_080ADBDE:
	ldrb r6, [r5, 0x3]
	movs r0, 0x4
	ands r0, r6
	cmp r0, 0
	bne _080ADC02
	ldrb r0, [r5, 0x1]
	lsls r3, r0, 11
	mov r0, r12
	str r3, [r0, 0x4]
	movs r0, 0x2
	ands r0, r6
	cmp r0, 0
	beq _080ADC02
	movs r5, 0x80
	lsls r5, 3
	adds r0, r3, r5
	mov r6, r12
	str r0, [r6, 0x4]
_080ADC02:
	ldr r0, [sp, 0xC]
	str r0, [r4, 0xC]
	ldr r0, [sp, 0xC]
	adds r0, r1
	str r0, [r4, 0x14]
	ldr r0, [sp, 0x10]
	str r0, [r4, 0x10]
	ldr r0, [sp, 0x10]
	adds r0, r2
	str r0, [r4, 0x18]
	mov r1, r8
	ldr r0, [r1, 0x8]
	ldr r0, [r0, 0x8]
	str r0, [r4, 0x1C]
	bl sub_80A7A78
	adds r0, r7, 0
_080ADC24:
	add sp, 0x14
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end GroundEvent_Add

	thumb_func_start GroundEvent_Delete
GroundEvent_Delete:
	push {r4,lr}
	adds r2, r0, 0
	lsls r2, 16
	asrs r2, 16
	ldr r0, _080ADC58
	lsls r1, r2, 5
	ldr r4, [r0]
	adds r4, r1
	ldr r1, _080ADC5C
	movs r0, 0
	bl Log
	ldr r0, _080ADC60
	strh r0, [r4, 0x2]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080ADC58: .4byte gUnknown_3001B90
_080ADC5C: .4byte gUnknown_811886C
_080ADC60: .4byte 0x0000ffff
	thumb_func_end GroundEvent_Delete

	thumb_func_start sub_80ADC64
sub_80ADC64:
	push {lr}
	adds r3, r1, 0
	lsls r0, 16
	ldr r1, _080ADC84
	asrs r0, 11
	ldr r1, [r1]
	adds r2, r1, r0
	movs r0, 0x2
	ldrsh r1, [r2, r0]
	movs r0, 0x1
	negs r0, r0
	cmp r1, r0
	bne _080ADC88
	movs r0, 0
	b _080ADC9A
	.align 2, 0
_080ADC84: .4byte gUnknown_3001B90
_080ADC88:
	ldr r0, [r2, 0x1C]
	str r0, [r3]
	movs r0, 0x2
	strh r0, [r3, 0x4]
	ldrh r0, [r2, 0x4]
	strh r0, [r3, 0x6]
	ldrb r0, [r2, 0x6]
	strb r0, [r3, 0x8]
	movs r0, 0x1
_080ADC9A:
	pop {r1}
	bx r1
	thumb_func_end sub_80ADC64

	thumb_func_start sub_80ADCA0
sub_80ADCA0:
	push {r4-r7,lr}
	adds r7, r0, 0
	adds r4, r1, 0
	ldr r0, _080ADCEC
	ldr r3, [r0]
	movs r5, 0
	movs r0, 0x1
	negs r0, r0
	mov r12, r0
	movs r6, 0x80
	lsls r6, 9
_080ADCB6:
	movs r1, 0x2
	ldrsh r0, [r3, r1]
	cmp r0, r12
	beq _080ADCF0
	ldr r0, [r3, 0x8]
	ands r0, r7
	cmp r0, 0
	beq _080ADCF0
	ldr r1, [r3, 0xC]
	ldr r0, [r2]
	cmp r1, r0
	bge _080ADCF0
	ldr r1, [r3, 0x14]
	ldr r0, [r4]
	cmp r1, r0
	ble _080ADCF0
	ldr r1, [r3, 0x10]
	ldr r0, [r2, 0x4]
	cmp r1, r0
	bge _080ADCF0
	ldr r1, [r3, 0x18]
	ldr r0, [r4, 0x4]
	cmp r1, r0
	ble _080ADCF0
	adds r0, r5, 0
	b _080ADD04
	.align 2, 0
_080ADCEC: .4byte gUnknown_3001B90
_080ADCF0:
	adds r0, r6, 0
	movs r1, 0x80
	lsls r1, 9
	adds r6, r1
	asrs r5, r0, 16
	adds r3, 0x20
	cmp r5, 0x1F
	ble _080ADCB6
	movs r0, 0x1
	negs r0, r0
_080ADD04:
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_80ADCA0

	thumb_func_start sub_80ADD0C
sub_80ADD0C:
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	mov r8, r0
	adds r6, r1, 0
	adds r5, r2, 0
	ldr r0, _080ADD74
	ldr r4, [r0]
	movs r7, 0
	movs r0, 0x1
	negs r0, r0
	mov r9, r0
	movs r1, 0x80
	lsls r1, 9
	mov r12, r1
_080ADD2C:
	movs r1, 0x2
	ldrsh r0, [r4, r1]
	cmp r0, r9
	beq _080ADD78
	ldr r0, [r4, 0x8]
	mov r1, r8
	ands r0, r1
	cmp r0, 0
	beq _080ADD78
	ldr r0, [r4, 0xC]
	ldr r1, [r4, 0x14]
	adds r0, r1
	lsrs r1, r0, 31
	adds r0, r1
	asrs r2, r0, 1
	ldr r0, [r4, 0x10]
	ldr r1, [r4, 0x18]
	adds r0, r1
	lsrs r1, r0, 31
	adds r0, r1
	asrs r3, r0, 1
	ldr r0, [r5]
	cmp r2, r0
	bge _080ADD78
	ldr r0, [r6]
	cmp r2, r0
	ble _080ADD78
	ldr r0, [r5, 0x4]
	cmp r3, r0
	bge _080ADD78
	ldr r0, [r6, 0x4]
	cmp r3, r0
	ble _080ADD78
	adds r0, r7, 0
	b _080ADD8C
	.align 2, 0
_080ADD74: .4byte gUnknown_3001B90
_080ADD78:
	mov r0, r12
	movs r1, 0x80
	lsls r1, 9
	add r12, r1
	asrs r7, r0, 16
	adds r4, 0x20
	cmp r7, 0x1F
	ble _080ADD2C
	movs r0, 0x1
	negs r0, r0
_080ADD8C:
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_80ADD0C

	thumb_func_start nullsub_124
nullsub_124:
	bx lr
	thumb_func_end nullsub_124

	thumb_func_start sub_80ADD9C
sub_80ADD9C:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x30
	str r0, [sp, 0x20]
	str r1, [sp, 0x24]
	str r2, [sp, 0x28]
	str r3, [sp, 0x2C]
	ldr r5, [sp, 0x54]
	ldr r0, [sp, 0x5C]
	mov r9, r0
	movs r0, 0x93
	lsls r0, 4
	movs r1, 0x7
	bl MemoryAlloc
	mov r10, r0
	ldr r0, _080ADEB4
	ldr r7, _080ADEB8
	adds r1, r7, 0
	bl OpenFileAndGetFileDataPtr
	adds r6, r0, 0
	add r4, sp, 0x1C
	adds r0, r4, 0
	adds r1, r5, 0
	bl sub_80901D8
	ldrb r5, [r4]
	ldrb r4, [r4, 0x1]
	cmp r5, 0x3E
	bls _080ADDE2
	movs r5, 0x3E
_080ADDE2:
	cmp r4, 0
	bgt _080ADDE8
	movs r4, 0x1
_080ADDE8:
	adds r0, r5, 0
	bl sub_8090298
	cmp r4, r0
	blt _080ADDFA
	adds r0, r5, 0
	bl sub_8090298
	subs r4, r0, 0x1
_080ADDFA:
	ldr r2, [r6, 0x4]
	ldr r1, [r2]
	lsls r0, r5, 2
	adds r0, r1
	lsls r1, r4, 4
	ldr r0, [r0]
	adds r0, r1
	movs r3, 0
	ldrsh r1, [r0, r3]
	ldr r2, [r2, 0x4]
	lsls r0, r1, 3
	subs r0, r1
	lsls r0, 2
	adds r0, r2
	ldrb r0, [r0, 0x2]
	mov r8, r0
	adds r0, r6, 0
	bl CloseFile
	ldr r1, _080ADEBC
	ldr r0, _080ADEC0
	add r0, r8
	ldrb r5, [r0]
	add r0, sp, 0x10
	adds r2, r5, 0
	bl sprintf
	add r0, sp, 0x10
	adds r1, r7, 0
	bl OpenFileAndGetFileDataPtr
	adds r4, r0, 0
	ldr r0, [sp, 0x28]
	movs r1, 0
	adds r2, r4, 0
	bl sub_800AE28
	adds r0, r4, 0
	bl CloseFile
	ldr r1, _080ADEC4
	add r0, sp, 0x10
	mov r2, r8
	bl sprintf
	add r0, sp, 0x10
	adds r1, r7, 0
	bl OpenFile
	ldr r1, [sp, 0x20]
	str r0, [r1]
	ldr r1, _080ADEC8
	add r0, sp, 0x10
	adds r2, r5, 0
	bl sprintf
	add r0, sp, 0x10
	adds r1, r7, 0
	bl OpenFileAndGetFileDataPtr
	adds r4, r0, 0
	ldr r1, _080ADECC
	ldr r0, [sp, 0x2C]
	adds r2, r4, 0
	bl sub_800AAA8
	adds r0, r4, 0
	bl CloseFile
	mov r2, r8
	cmp r2, 0x3F
	bgt _080ADED4
	ldr r1, _080ADED0
	add r0, sp, 0x10
	adds r2, r5, 0
	bl sprintf
	add r0, sp, 0x10
	adds r1, r7, 0
	bl OpenFileAndGetFileDataPtr
	adds r4, r0, 0
	mov r0, r10
	movs r1, 0x93
	lsls r1, 4
	adds r2, r4, 0
	bl sub_800AAA8
	adds r0, r4, 0
	bl CloseFile
	b _080ADEFC
	.align 2, 0
_080ADEB4: .4byte gUnknown_8118890
_080ADEB8: .4byte gUnknown_83B0000
_080ADEBC: .4byte gUnknown_811889C
_080ADEC0: .4byte gUnknown_8108EC0
_080ADEC4: .4byte gUnknown_81188A8
_080ADEC8: .4byte gUnknown_81188B4
_080ADECC: .4byte 0x00001194
_080ADED0: .4byte gUnknown_81188C0
_080ADED4:
	ldr r1, _080ADF80
	add r0, sp, 0x10
	mov r2, r8
	ldr r3, [sp, 0x58]
	bl sprintf
	add r0, sp, 0x10
	adds r1, r7, 0
	bl OpenFileAndGetFileDataPtr
	adds r4, r0, 0
	movs r1, 0x90
	lsls r1, 2
	mov r0, r10
	adds r2, r4, 0
	bl sub_800AAA8
	adds r0, r4, 0
	bl CloseFile
_080ADEFC:
	movs r5, 0
	ldr r3, [sp, 0x60]
	cmp r5, r3
	bge _080ADF52
_080ADF04:
	mov r0, r8
	bl sub_8097F40
	lsls r0, 24
	movs r7, 0
	cmp r0, 0
	beq _080ADF14
	movs r7, 0x3
_080ADF14:
	movs r4, 0
	adds r6, r5, 0x1
	cmp r4, r9
	bge _080ADF4A
_080ADF1C:
	ldr r0, [sp, 0x64]
	str r0, [sp]
	str r7, [sp, 0x4]
	mov r1, r10
	str r1, [sp, 0x8]
	mov r2, r8
	str r2, [sp, 0xC]
	adds r0, r4, 0
	adds r1, r5, 0
	mov r2, r9
	ldr r3, [sp, 0x60]
	bl sub_80ADFB8
	mov r1, r9
	muls r1, r5
	adds r1, r4
	lsls r1, 1
	ldr r3, [sp, 0x50]
	adds r1, r3
	strh r0, [r1]
	adds r4, 0x1
	cmp r4, r9
	blt _080ADF1C
_080ADF4A:
	adds r5, r6, 0
	ldr r0, [sp, 0x60]
	cmp r5, r0
	blt _080ADF04
_080ADF52:
	ldr r1, _080ADF84
	add r0, sp, 0x10
	mov r2, r8
	bl sprintf
	ldr r1, _080ADF88
	add r0, sp, 0x10
	bl OpenFile
	ldr r1, [sp, 0x24]
	str r0, [r1]
	mov r0, r10
	bl MemoryFree
	add sp, 0x30
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_080ADF80: .4byte gUnknown_81188CC
_080ADF84: .4byte gUnknown_81188DC
_080ADF88: .4byte gUnknown_83B0000
	thumb_func_end sub_80ADD9C

	thumb_func_start sub_80ADF8C
sub_80ADF8C:
	push {r4,lr}
	adds r4, r0, 0
	ldr r0, [sp, 0xC]
	cmp r4, 0
	blt _080ADFB0
	cmp r1, 0
	blt _080ADFB0
	cmp r4, r2
	bge _080ADFB0
	cmp r1, r3
	bge _080ADFB0
	adds r0, r1, 0
	muls r0, r2
	adds r0, r4, r0
	lsls r0, 1
	ldr r1, [sp, 0x8]
	adds r0, r1
	ldrh r0, [r0]
_080ADFB0:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_80ADF8C

	thumb_func_start sub_80ADFB8
sub_80ADFB8:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x30
	mov r9, r0
	mov r10, r1
	adds r6, r2, 0
	mov r8, r3
	ldr r4, [sp, 0x5C]
	movs r7, 0
	ldr r0, [sp, 0x50]
	str r0, [sp]
	ldr r1, [sp, 0x54]
	str r1, [sp, 0x4]
	mov r0, r9
	mov r1, r10
	bl sub_80ADF8C
	str r0, [sp, 0x28]
	cmp r4, 0x3F
	ble _080AE000
	mov r0, r9
	cmp r0, 0x17
	bgt _080ADFFC
	mov r1, r10
	cmp r1, 0x17
	bgt _080ADFFC
	lsls r0, r1, 1
	add r0, r10
	lsls r0, 3
	add r0, r9
	b _080AE24E
_080ADFFC:
	ldr r0, [sp, 0x54]
	b _080AE254
_080AE000:
	mov r0, r10
	adds r0, 0x1
	str r0, [sp, 0x2C]
	ldr r1, [sp, 0x50]
	str r1, [sp]
	ldr r0, [sp, 0x54]
	str r0, [sp, 0x4]
	mov r0, r9
	ldr r1, [sp, 0x2C]
	adds r2, r6, 0
	mov r3, r8
	bl sub_80ADF8C
	str r0, [sp, 0x8]
	mov r4, r9
	adds r4, 0x1
	ldr r1, [sp, 0x50]
	str r1, [sp]
	ldr r0, [sp, 0x54]
	str r0, [sp, 0x4]
	adds r0, r4, 0
	ldr r1, [sp, 0x2C]
	adds r2, r6, 0
	mov r3, r8
	bl sub_80ADF8C
	str r0, [sp, 0xC]
	ldr r1, [sp, 0x50]
	str r1, [sp]
	ldr r0, [sp, 0x54]
	str r0, [sp, 0x4]
	adds r0, r4, 0
	mov r1, r10
	adds r2, r6, 0
	mov r3, r8
	bl sub_80ADF8C
	str r0, [sp, 0x10]
	mov r5, r10
	subs r5, 0x1
	ldr r1, [sp, 0x50]
	str r1, [sp]
	ldr r0, [sp, 0x54]
	str r0, [sp, 0x4]
	adds r0, r4, 0
	adds r1, r5, 0
	adds r2, r6, 0
	mov r3, r8
	bl sub_80ADF8C
	str r0, [sp, 0x14]
	ldr r1, [sp, 0x50]
	str r1, [sp]
	ldr r0, [sp, 0x54]
	str r0, [sp, 0x4]
	mov r0, r9
	adds r1, r5, 0
	adds r2, r6, 0
	mov r3, r8
	bl sub_80ADF8C
	str r0, [sp, 0x18]
	subs r4, 0x2
	ldr r1, [sp, 0x50]
	str r1, [sp]
	ldr r0, [sp, 0x54]
	str r0, [sp, 0x4]
	adds r0, r4, 0
	adds r1, r5, 0
	adds r2, r6, 0
	mov r3, r8
	bl sub_80ADF8C
	str r0, [sp, 0x1C]
	ldr r1, [sp, 0x50]
	str r1, [sp]
	ldr r0, [sp, 0x54]
	str r0, [sp, 0x4]
	adds r0, r4, 0
	mov r1, r10
	adds r2, r6, 0
	mov r3, r8
	bl sub_80ADF8C
	str r0, [sp, 0x20]
	ldr r1, [sp, 0x50]
	str r1, [sp]
	ldr r0, [sp, 0x54]
	str r0, [sp, 0x4]
	adds r0, r4, 0
	ldr r1, [sp, 0x2C]
	adds r2, r6, 0
	mov r3, r8
	bl sub_80ADF8C
	adds r1, r0, 0
	str r1, [sp, 0x24]
	ldr r0, [sp, 0x28]
	cmp r0, 0x1
	bne _080AE12A
	movs r7, 0xFF
	ldr r0, [sp, 0x8]
	cmp r0, 0
	bne _080AE0D2
	movs r7, 0xFE
_080AE0D2:
	ldr r0, [sp, 0xC]
	cmp r0, 0
	bne _080AE0DE
	movs r0, 0x3
	negs r0, r0
	ands r7, r0
_080AE0DE:
	ldr r0, [sp, 0x10]
	cmp r0, 0
	bne _080AE0EA
	movs r0, 0x5
	negs r0, r0
	ands r7, r0
_080AE0EA:
	ldr r0, [sp, 0x14]
	cmp r0, 0
	bne _080AE0F6
	movs r0, 0x9
	negs r0, r0
	ands r7, r0
_080AE0F6:
	ldr r0, [sp, 0x18]
	cmp r0, 0
	bne _080AE102
	movs r0, 0x11
	negs r0, r0
	ands r7, r0
_080AE102:
	ldr r0, [sp, 0x1C]
	cmp r0, 0
	bne _080AE10E
	movs r0, 0x21
	negs r0, r0
	ands r7, r0
_080AE10E:
	ldr r0, [sp, 0x20]
	cmp r0, 0
	bne _080AE11A
	movs r0, 0x41
	negs r0, r0
	ands r7, r0
_080AE11A:
	cmp r1, 0
	bne _080AE124
	movs r0, 0x81
	negs r0, r0
	ands r7, r0
_080AE124:
	movs r0, 0x80
	lsls r0, 2
	b _080AE248
_080AE12A:
	ldr r0, [sp, 0x28]
	cmp r0, 0x2
	bne _080AE192
	movs r7, 0xFF
	ldr r0, [sp, 0x8]
	cmp r0, 0x2
	beq _080AE13A
	movs r7, 0xFE
_080AE13A:
	ldr r0, [sp, 0xC]
	cmp r0, 0x2
	beq _080AE146
	movs r0, 0x3
	negs r0, r0
	ands r7, r0
_080AE146:
	ldr r0, [sp, 0x10]
	cmp r0, 0x2
	beq _080AE152
	movs r0, 0x5
	negs r0, r0
	ands r7, r0
_080AE152:
	ldr r0, [sp, 0x14]
	cmp r0, 0x2
	beq _080AE15E
	movs r0, 0x9
	negs r0, r0
	ands r7, r0
_080AE15E:
	ldr r0, [sp, 0x18]
	cmp r0, 0x2
	beq _080AE16A
	movs r0, 0x11
	negs r0, r0
	ands r7, r0
_080AE16A:
	ldr r0, [sp, 0x1C]
	cmp r0, 0x2
	beq _080AE176
	movs r0, 0x21
	negs r0, r0
	ands r7, r0
_080AE176:
	ldr r0, [sp, 0x20]
	cmp r0, 0x2
	beq _080AE182
	movs r0, 0x41
	negs r0, r0
	ands r7, r0
_080AE182:
	cmp r1, 0x2
	beq _080AE18C
	movs r0, 0x81
	negs r0, r0
	ands r7, r0
_080AE18C:
	movs r0, 0x80
	lsls r0, 1
	b _080AE248
_080AE192:
	ldr r1, [sp, 0x28]
	cmp r1, 0x3
	bne _080AE1FC
	movs r7, 0xFF
	ldr r0, [sp, 0x8]
	cmp r0, 0x3
	beq _080AE1A2
	movs r7, 0xFE
_080AE1A2:
	ldr r0, [sp, 0xC]
	cmp r0, 0x3
	beq _080AE1AE
	movs r0, 0x3
	negs r0, r0
	ands r7, r0
_080AE1AE:
	ldr r0, [sp, 0x10]
	cmp r0, 0x3
	beq _080AE1BA
	movs r0, 0x5
	negs r0, r0
	ands r7, r0
_080AE1BA:
	ldr r0, [sp, 0x14]
	cmp r0, 0x3
	beq _080AE1C6
	movs r0, 0x9
	negs r0, r0
	ands r7, r0
_080AE1C6:
	ldr r0, [sp, 0x18]
	cmp r0, 0x3
	beq _080AE1D2
	movs r0, 0x11
	negs r0, r0
	ands r7, r0
_080AE1D2:
	ldr r0, [sp, 0x1C]
	cmp r0, 0x3
	beq _080AE1DE
	movs r0, 0x21
	negs r0, r0
	ands r7, r0
_080AE1DE:
	ldr r0, [sp, 0x20]
	cmp r0, 0x3
	beq _080AE1EA
	movs r0, 0x41
	negs r0, r0
	ands r7, r0
_080AE1EA:
	ldr r0, [sp, 0x24]
	cmp r0, 0x3
	beq _080AE1F6
	movs r0, 0x81
	negs r0, r0
	ands r7, r0
_080AE1F6:
	movs r0, 0x80
	lsls r0, 1
	b _080AE248
_080AE1FC:
	ldr r0, [sp, 0x8]
	cmp r0, 0
	bne _080AE204
	movs r7, 0x1
_080AE204:
	ldr r0, [sp, 0xC]
	cmp r0, 0
	bne _080AE20E
	movs r0, 0x2
	orrs r7, r0
_080AE20E:
	ldr r0, [sp, 0x10]
	cmp r0, 0
	bne _080AE218
	movs r0, 0x4
	orrs r7, r0
_080AE218:
	ldr r0, [sp, 0x14]
	cmp r0, 0
	bne _080AE222
	movs r0, 0x8
	orrs r7, r0
_080AE222:
	ldr r0, [sp, 0x18]
	cmp r0, 0
	bne _080AE22C
	movs r0, 0x10
	orrs r7, r0
_080AE22C:
	ldr r0, [sp, 0x1C]
	cmp r0, 0
	bne _080AE236
	movs r0, 0x20
	orrs r7, r0
_080AE236:
	ldr r0, [sp, 0x20]
	cmp r0, 0
	bne _080AE240
	movs r0, 0x40
	orrs r7, r0
_080AE240:
	ldr r0, [sp, 0x24]
	cmp r0, 0
	bne _080AE24A
	movs r0, 0x80
_080AE248:
	orrs r7, r0
_080AE24A:
	lsls r0, r7, 1
	adds r0, r7
_080AE24E:
	ldr r1, [sp, 0x58]
	adds r0, r1, r0
	ldrb r0, [r0]
_080AE254:
	add sp, 0x30
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_80ADFB8

        .align 2,0
