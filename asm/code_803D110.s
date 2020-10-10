	.include "constants/gba_constants.inc"
	.include "asm/macros.inc"

	.syntax unified

	.text	

        thumb_func_start sub_803D110
sub_803D110:
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	sub sp, 0x6C
	adds r6, r0, 0
	mov r9, r1
	adds r5, r2, 0
	add r7, sp, 0x48
	adds r2, r7, 0
	movs r1, 0
	mov r0, sp
	adds r0, 0x69
_0803D12A:
	strb r1, [r0]
	subs r0, 0x1
	cmp r0, r2
	bge _0803D12A
	movs r4, 0
	cmp r4, r5
	bge _0803D158
_0803D138:
	ldrb r0, [r6]
	bl sub_803D0F0
	add r1, sp, 0x10
	adds r1, r4
	strb r0, [r1]
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0xFF
	bne _0803D150
	movs r0, 0
	b _0803D19A
_0803D150:
	adds r6, 0x1
	adds r4, 0x1
	cmp r4, r5
	blt _0803D138
_0803D158:
	lsls r0, r5, 2
	adds r0, r5
	adds r2, r0, 0x5
	cmp r2, 0
	bge _0803D164
	adds r2, 0x7
_0803D164:
	asrs r2, 3
	mov r8, r2
	mov r0, sp
	adds r1, r7, 0
	bl sub_809486C
	movs r4, 0
	cmp r4, r5
	bge _0803D188
	add r6, sp, 0x10
_0803D178:
	adds r1, r6, r4
	mov r0, sp
	movs r2, 0x5
	bl sub_809488C
	adds r4, 0x1
	cmp r4, r5
	blt _0803D178
_0803D188:
	mov r0, sp
	bl nullsub_102
	mov r0, r9
	adds r1, r7, 0
	mov r2, r8
	bl MemoryCopy8
	movs r0, 0x1
_0803D19A:
	add sp, 0x6C
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_803D110

	thumb_func_start sub_803D1A8
sub_803D1A8:
	push {r4-r7,lr}
	sub sp, 0x48
	adds r7, r0, 0
	adds r5, r2, 0
	lsls r0, r5, 2
	adds r0, r5
	adds r2, r0, 0x5
	cmp r2, 0
	bge _0803D1BC
	adds r2, 0x7
_0803D1BC:
	asrs r2, 3
	mov r0, sp
	bl sub_809485C
	movs r4, 0
	cmp r4, r5
	bge _0803D1DC
	add r6, sp, 0x10
_0803D1CC:
	adds r1, r6, r4
	mov r0, sp
	movs r2, 0x5
	bl sub_8094924
	adds r4, 0x1
	cmp r4, r5
	blt _0803D1CC
_0803D1DC:
	mov r0, sp
	bl nullsub_102
	movs r4, 0
	cmp r4, r5
	bge _0803D1FC
	add r6, sp, 0x10
_0803D1EA:
	adds r0, r6, r4
	ldrb r0, [r0]
	bl sub_803D100
	strb r0, [r7]
	adds r7, 0x1
	adds r4, 0x1
	cmp r4, r5
	blt _0803D1EA
_0803D1FC:
	add sp, 0x48
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_803D1A8

	thumb_func_start sub_803D204
sub_803D204:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0xA4
	adds r2, r0, 0
	mov r9, r1
	movs r6, 0
	add r4, sp, 0x5C
	adds r0, r4, 0
	adds r1, r2, 0
	movs r2, 0x36
	bl MemoryCopy8
	movs r2, 0
	mov r8, r4
	add r5, sp, 0x24
	ldr r4, _0803D2A8
	mov r12, r4
	mov r10, r5
_0803D22E:
	movs r1, 0
	mov r3, r12
	adds r0, r2, r3
	adds r3, r2, 0x1
	ldrb r0, [r0]
	cmp r1, r0
	beq _0803D24A
	adds r0, r2, r4
_0803D23E:
	adds r1, 0x1
	cmp r1, 0x35
	bgt _0803D24A
	ldrb r7, [r0]
	cmp r1, r7
	bne _0803D23E
_0803D24A:
	mov r7, r10
	adds r0, r7, r2
	add r1, r8
	ldrb r1, [r1]
	strb r1, [r0]
	adds r2, r3, 0
	cmp r2, 0x35
	ble _0803D22E
	adds r0, r5, 0
	mov r1, sp
	movs r2, 0x36
	bl sub_803D110
	lsls r0, 24
	cmp r0, 0
	beq _0803D2AC
	movs r2, 0x1
_0803D26C:
	mov r1, sp
	adds r0, r1, r2
	ldrb r0, [r0]
	adds r0, r2
	adds r0, r6, r0
	lsls r0, 24
	lsrs r6, r0, 24
	adds r2, 0x1
	cmp r2, 0x21
	ble _0803D26C
	mov r0, sp
	ldrb r0, [r0]
	cmp r0, r6
	bne _0803D2AC
	add r4, sp, 0x94
	adds r1, 0x1
	adds r0, r4, 0
	movs r2, 0x21
	bl sub_809485C
	adds r0, r4, 0
	mov r1, r9
	bl sub_8095774
	adds r0, r4, 0
	bl nullsub_102
	movs r0, 0x1
	b _0803D2AE
	.align 2, 0
_0803D2A8: .4byte gUnknown_80F43F0
_0803D2AC:
	movs r0, 0
_0803D2AE:
	add sp, 0xA4
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_803D204

	thumb_func_start sub_803D2C0
sub_803D2C0:
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	sub sp, 0xA4
	mov r9, r0
	adds r6, r1, 0
	movs r5, 0
	add r4, sp, 0x94
	mov r1, sp
	adds r1, 0x1
	add r7, sp, 0x24
	add r0, sp, 0x5C
	mov r8, r0
	movs r2, 0
	mov r0, sp
	adds r0, 0x21
_0803D2E2:
	strb r2, [r0]
	subs r0, 0x1
	cmp r0, sp
	bge _0803D2E2
	adds r0, r4, 0
	movs r2, 0x21
	bl sub_809486C
	adds r0, r4, 0
	adds r1, r6, 0
	bl sub_8095824
	adds r0, r4, 0
	bl nullsub_102
	movs r2, 0x1
_0803D302:
	mov r1, sp
	adds r0, r1, r2
	ldrb r0, [r0]
	adds r0, r2
	adds r0, r5, r0
	lsls r0, 24
	lsrs r5, r0, 24
	adds r2, 0x1
	cmp r2, 0x21
	ble _0803D302
	mov r0, sp
	strb r5, [r0]
	adds r0, r7, 0
	movs r2, 0x36
	bl sub_803D1A8
	movs r2, 0
	mov r4, r8
	ldr r5, _0803D354
	adds r3, r7, 0
_0803D32A:
	adds r0, r2, r5
	ldrb r1, [r0]
	adds r1, r4, r1
	adds r0, r3, r2
	ldrb r0, [r0]
	strb r0, [r1]
	adds r2, 0x1
	cmp r2, 0x35
	ble _0803D32A
	mov r0, r9
	mov r1, r8
	movs r2, 0x36
	bl MemoryCopy8
	add sp, 0xA4
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_0803D354: .4byte gUnknown_80F43F0
	thumb_func_end sub_803D2C0

	thumb_func_start sub_803D358
sub_803D358:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x50
	adds r2, r0, 0
	mov r9, r1
	movs r6, 0
	add r4, sp, 0x28
	adds r0, r4, 0
	adds r1, r2, 0
	movs r2, 0x18
	bl MemoryCopy8
	movs r2, 0
	mov r8, r4
	add r5, sp, 0x10
	ldr r4, _0803D3FC
	mov r12, r4
	mov r10, r5
_0803D382:
	movs r1, 0
	mov r3, r12
	adds r0, r2, r3
	adds r3, r2, 0x1
	ldrb r0, [r0]
	cmp r1, r0
	beq _0803D39E
	adds r0, r2, r4
_0803D392:
	adds r1, 0x1
	cmp r1, 0x17
	bgt _0803D39E
	ldrb r7, [r0]
	cmp r1, r7
	bne _0803D392
_0803D39E:
	mov r7, r10
	adds r0, r7, r2
	add r1, r8
	ldrb r1, [r1]
	strb r1, [r0]
	adds r2, r3, 0
	cmp r2, 0x17
	ble _0803D382
	adds r0, r5, 0
	mov r1, sp
	movs r2, 0x18
	bl sub_803D110
	lsls r0, 24
	cmp r0, 0
	beq _0803D400
	movs r2, 0x1
_0803D3C0:
	mov r1, sp
	adds r0, r1, r2
	ldrb r0, [r0]
	adds r0, r2
	adds r0, r6, r0
	lsls r0, 24
	lsrs r6, r0, 24
	adds r2, 0x1
	cmp r2, 0xE
	ble _0803D3C0
	mov r0, sp
	ldrb r0, [r0]
	cmp r0, r6
	bne _0803D400
	add r4, sp, 0x40
	adds r1, 0x1
	adds r0, r4, 0
	movs r2, 0xC
	bl sub_809485C
	adds r0, r4, 0
	mov r1, r9
	bl sub_80971EC
	adds r0, r4, 0
	bl nullsub_102
	movs r0, 0x1
	b _0803D402
	.align 2, 0
_0803D3FC: .4byte gUnknown_80F4426
_0803D400:
	movs r0, 0
_0803D402:
	add sp, 0x50
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_803D358

	thumb_func_start sub_803D414
sub_803D414:
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	sub sp, 0x50
	mov r9, r0
	adds r6, r1, 0
	movs r5, 0
	add r4, sp, 0x40
	mov r1, sp
	adds r1, 0x1
	add r7, sp, 0x10
	add r0, sp, 0x28
	mov r8, r0
	movs r2, 0
	mov r0, sp
	adds r0, 0xE
_0803D436:
	strb r2, [r0]
	subs r0, 0x1
	cmp r0, sp
	bge _0803D436
	adds r0, r4, 0
	movs r2, 0xC
	bl sub_809486C
	adds r0, r4, 0
	adds r1, r6, 0
	bl sub_8097270
	adds r0, r4, 0
	bl nullsub_102
	movs r2, 0x1
_0803D456:
	mov r1, sp
	adds r0, r1, r2
	ldrb r0, [r0]
	adds r0, r2
	adds r0, r5, r0
	lsls r0, 24
	lsrs r5, r0, 24
	adds r2, 0x1
	cmp r2, 0xE
	ble _0803D456
	mov r0, sp
	strb r5, [r0]
	adds r0, r7, 0
	movs r2, 0x18
	bl sub_803D1A8
	movs r2, 0
	mov r4, r8
	ldr r5, _0803D4A8
	adds r3, r7, 0
_0803D47E:
	adds r0, r2, r5
	ldrb r1, [r0]
	adds r1, r4, r1
	adds r0, r3, r2
	ldrb r0, [r0]
	strb r0, [r1]
	adds r2, 0x1
	cmp r2, 0x17
	ble _0803D47E
	mov r0, r9
	mov r1, r8
	movs r2, 0x18
	bl MemoryCopy8
	add sp, 0x50
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_0803D4A8: .4byte gUnknown_80F4426
	thumb_func_end sub_803D414

	thumb_func_start sub_803D4AC
sub_803D4AC:
	ldr r2, _0803D4C4
	ldr r0, [r2]
	ldr r1, _0803D4C8
	adds r0, r1
	movs r1, 0x63
	strb r1, [r0]
	ldr r0, [r2]
	ldr r1, _0803D4CC
	adds r0, r1
	movs r1, 0xFF
	strb r1, [r0]
	bx lr
	.align 2, 0
_0803D4C4: .4byte gUnknown_203B418
_0803D4C8: .4byte 0x0001c570
_0803D4CC: .4byte 0x0001c571
	thumb_func_end sub_803D4AC

	thumb_func_start sub_803D4D0
sub_803D4D0:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x1FC
	ldr r6, _0803D654
	ldr r1, [r6]
	movs r4, 0xC9
	lsls r4, 3
	adds r0, r1, r4
	ldr r2, _0803D658
	adds r1, r2
	bl sub_80901D8
	ldr r0, [r6]
	ldr r3, _0803D65C
	adds r2, r0, r3
	adds r1, r0, r4
	ldrh r0, [r2]
	ldrh r4, [r1]
	cmp r0, r4
	bne _0803D500
	b _0803D6E0
_0803D500:
	ldr r0, [r1]
	str r0, [r2]
	ldr r0, _0803D660
	ldr r1, _0803D664
	bl OpenFileAndGetFileDataPtr
	mov r9, r0
	ldr r3, [r0, 0x4]
	ldr r2, [r6]
	ldr r7, _0803D65C
	adds r0, r2, r7
	ldrb r1, [r0]
	ldr r0, [r3]
	lsls r1, 2
	adds r1, r0
	ldr r3, _0803D668
	adds r0, r2, r3
	ldrb r0, [r0]
	lsls r0, 4
	ldr r1, [r1]
	adds r1, r0
	mov r8, r1
	ldr r4, _0803D658
	adds r2, r4
	ldrb r0, [r2]
	bl sub_8090298
	ldr r1, [r6]
	ldr r7, _0803D66C
	adds r1, r7
	strb r0, [r1]
	ldr r0, [r6]
	adds r0, r4
	ldrb r0, [r0]
	bl sub_80902C8
	ldr r1, [r6]
	strh r0, [r1, 0x14]
	mov r2, r9
	ldr r0, [r2, 0x4]
	mov r3, r8
	movs r4, 0
	ldrsh r2, [r3, r4]
	ldr r3, [r0, 0x4]
	lsls r0, r2, 3
	subs r0, r2
	lsls r0, 2
	ldr r7, _0803D670
	adds r1, r7
	adds r0, r3
	ldm r0!, {r2-r4}
	stm r1!, {r2-r4}
	ldm r0!, {r2,r3,r7}
	stm r1!, {r2,r3,r7}
	ldr r0, [r0]
	str r0, [r1]
	movs r5, 0
	mov r10, r6
	ldr r4, _0803D674
_0803D576:
	mov r6, r10
	ldr r2, [r6]
	lsls r3, r5, 1
	adds r2, r4
	adds r2, r3
	mov r7, r9
	ldr r1, [r7, 0x4]
	mov r6, r8
	movs r7, 0x4
	ldrsh r0, [r6, r7]
	ldr r1, [r1, 0x10]
	lsls r0, 2
	adds r0, r1
	ldr r0, [r0]
	adds r3, r0
	ldrh r0, [r3]
	strh r0, [r2]
	adds r5, 0x1
	cmp r5, 0x13
	ble _0803D576
	movs r5, 0
	adds r6, 0x6
	str r6, [sp, 0x1F8]
	ldr r6, _0803D678
	mov r10, r6
_0803D5A8:
	ldr r1, _0803D654
	ldr r0, [r1]
	lsls r3, r5, 3
	mov r2, r10
	adds r4, r0, r2
	adds r4, r3
	mov r12, r4
	mov r4, r9
	ldr r2, [r4, 0x4]
	mov r7, r8
	movs r4, 0x2
	ldrsh r1, [r7, r4]
	ldr r2, [r2, 0xC]
	lsls r1, 2
	adds r1, r2
	ldr r1, [r1]
	adds r3, r1
	ldr r1, [r3]
	ldr r2, [r3, 0x4]
	mov r7, r12
	str r1, [r7]
	str r2, [r7, 0x4]
	adds r0, r6
	bl sub_808E9B8
	lsls r0, 16
	cmp r0, 0
	beq _0803D5E8
	adds r6, 0x8
	adds r5, 0x1
	cmp r5, 0x1E
	ble _0803D5A8
_0803D5E8:
	cmp r5, 0x1F
	bgt _0803D606
	ldr r6, _0803D654
	lsls r0, r5, 3
	ldr r1, _0803D678
	adds r4, r0, r1
_0803D5F4:
	ldr r0, [r6]
	adds r0, r4
	movs r1, 0
	bl sub_808E9C4
	adds r4, 0x8
	adds r5, 0x1
	cmp r5, 0x1F
	ble _0803D5F4
_0803D606:
	movs r5, 0
	ldr r2, _0803D67C
	mov r10, r2
_0803D60C:
	mov r3, r9
	ldr r1, [r3, 0x4]
	lsls r0, r5, 1
	ldr r4, [sp, 0x1F8]
	adds r0, r4, r0
	movs r6, 0
	ldrsh r0, [r0, r6]
	ldr r1, [r1, 0x8]
	lsls r0, 2
	adds r0, r1
	movs r4, 0
	adds r7, r5, 0x1
	mov r8, r7
	lsls r1, r5, 6
	mov r12, r1
	ldr r3, [r0]
	mov r2, sp
_0803D62E:
	ldrh r0, [r3]
	cmp r0, r10
	bls _0803D684
	ldrh r0, [r3]
	ldr r6, _0803D680
	adds r1, r0, r6
	cmp r1, 0
	beq _0803D68A
	movs r6, 0
	lsls r0, r4, 1
	add r0, sp
_0803D644:
	strh r6, [r0]
	adds r0, 0x2
	adds r2, 0x2
	adds r4, 0x1
	subs r1, 0x1
	cmp r1, 0
	bne _0803D644
	b _0803D68A
	.align 2, 0
_0803D654: .4byte gUnknown_203B418
_0803D658: .4byte 0x00000644
_0803D65C: .4byte 0x0001c570
_0803D660: .4byte gUnknown_80F4D8C
_0803D664: .4byte gUnknown_83B0000
_0803D668: .4byte 0x0001c571
_0803D66C: .4byte 0x0001cec8
_0803D670: .4byte 0x0001c574
_0803D674: .4byte 0x0001cd70
_0803D678: .4byte 0x0001cd98
_0803D67C: .4byte 0x0000752f
_0803D680: .4byte 0xffff8ad0
_0803D684:
	strh r0, [r2]
	adds r2, 0x2
	adds r4, 0x1
_0803D68A:
	adds r3, 0x2
	cmp r4, 0xFB
	ble _0803D62E
	ldr r7, _0803D6F0
	mov r1, r12
	subs r0, r1, r5
	movs r4, 0xB
	mov r3, sp
	lsls r2, r0, 3
	ldr r6, _0803D6F4
_0803D69E:
	ldr r0, [r7]
	adds r0, r6
	adds r0, r2
	ldrh r1, [r3]
	strh r1, [r0]
	adds r3, 0x2
	adds r2, 0x2
	subs r4, 0x1
	cmp r4, 0
	bge _0803D69E
	ldr r6, _0803D6F0
	mov r2, r12
	subs r0, r2, r5
	lsls r3, r0, 3
	add r2, sp, 0x18
	ldr r5, _0803D6F8
	movs r4, 0xEF
_0803D6C0:
	ldr r0, [r6]
	adds r0, r5
	adds r0, r3
	ldrh r1, [r2]
	strh r1, [r0]
	adds r2, 0x2
	adds r3, 0x2
	subs r4, 0x1
	cmp r4, 0
	bge _0803D6C0
	mov r5, r8
	cmp r5, 0x3
	ble _0803D60C
	mov r0, r9
	bl CloseFile
_0803D6E0:
	add sp, 0x1FC
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_0803D6F0: .4byte gUnknown_203B418
_0803D6F4: .4byte 0x0001c590
_0803D6F8: .4byte 0x0001c5a8
	thumb_func_end sub_803D4D0

	thumb_func_start sub_803D6FC
sub_803D6FC:
	push {r4,lr}
	ldr r0, _0803D720
	bl sub_8084100
	adds r3, r0, 0
	movs r2, 0
	ldr r0, _0803D724
	ldr r0, [r0]
	ldr r4, _0803D728
	adds r1, r0, r4
_0803D710:
	ldrh r0, [r1]
	cmp r0, 0
	beq _0803D72C
	cmp r0, r3
	blt _0803D72C
	lsls r0, r2, 24
	lsrs r0, 24
	b _0803D736
	.align 2, 0
_0803D720: .4byte 0x00002710
_0803D724: .4byte gUnknown_203B418
_0803D728: .4byte 0x0001cd70
_0803D72C:
	adds r1, 0x2
	adds r2, 0x1
	cmp r2, 0x13
	ble _0803D710
	movs r0, 0x10
_0803D736:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_803D6FC

	thumb_func_start sub_803D73C
sub_803D73C:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0x8
	adds r4, r0, 0
	ldr r0, _0803D784
	bl sub_8084100
	adds r7, r0, 0
	movs r0, 0xC
	mov r8, r0
	movs r6, 0
	ldr r0, _0803D788
	ldr r2, [r0]
	lsls r1, r4, 6
	subs r0, r1, r4
	adds r5, r1, 0
	lsls r0, 3
	ldr r1, _0803D78C
	adds r2, r1
	adds r1, r0, r2
_0803D766:
	movs r2, 0
	ldrsh r0, [r1, r2]
	cmp r0, 0
	beq _0803D772
	cmp r0, r7
	bge _0803D790
_0803D772:
	adds r1, 0x2
	adds r6, 0x1
	cmp r6, 0xB
	ble _0803D766
_0803D77A:
	mov r0, r8
	cmp r0, 0xC
	bne _0803D79C
	b _0803D7EC
	.align 2, 0
_0803D784: .4byte 0x00002710
_0803D788: .4byte gUnknown_203B418
_0803D78C: .4byte 0x0001c590
_0803D790:
	lsls r0, r6, 24
	lsrs r0, 24
	mov r8, r0
	b _0803D77A
_0803D798:
	adds r0, r5, 0
	b _0803D7EE
_0803D79C:
	ldr r0, _0803D7FC
	bl sub_8084100
	adds r7, r0, 0
	movs r6, 0
	ldr r2, _0803D800
	subs r0, r5, r4
	ldr r1, _0803D804
	lsls r4, r0, 3
_0803D7AE:
	ldr r0, [r2]
	adds r0, r1
	adds r0, r4
	movs r3, 0
	ldrsh r0, [r0, r3]
	cmp r0, 0
	beq _0803D7E4
	lsls r0, r6, 24
	lsrs r5, r0, 24
	adds r0, r5, 0
	str r1, [sp]
	str r2, [sp, 0x4]
	bl sub_8090BD0
	lsls r0, 24
	lsrs r0, 24
	ldr r1, [sp]
	ldr r2, [sp, 0x4]
	cmp r0, r8
	bne _0803D7E4
	ldr r0, [r2]
	adds r0, r1
	adds r0, r4
	movs r3, 0
	ldrsh r0, [r0, r3]
	cmp r0, r7
	bge _0803D798
_0803D7E4:
	adds r4, 0x2
	adds r6, 0x1
	cmp r6, 0xEF
	ble _0803D7AE
_0803D7EC:
	movs r0, 0x69
_0803D7EE:
	add sp, 0x8
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r1}
	bx r1
	.align 2, 0
_0803D7FC: .4byte 0x00002710
_0803D800: .4byte gUnknown_203B418
_0803D804: .4byte 0x0001c5a8
	thumb_func_end sub_803D73C

	thumb_func_start sub_803D808
sub_803D808:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0x4
	adds r7, r1, 0
	movs r6, 0
	ldr r2, _0803D820
	lsls r1, r7, 3
	adds r1, r0
	mov r8, r1
	b _0803D840
	.align 2, 0
_0803D820: .4byte 0x0001cd98
_0803D824:
	ldr r0, [r5]
	ldr r1, _0803D868
	adds r0, r1
	adds r0, r4
	ldr r1, [r0, 0x4]
	ldr r0, [r0]
	mov r3, r8
	adds r3, 0x8
	mov r8, r3
	subs r3, 0x8
	stm r3!, {r0,r1}
	adds r7, 0x1
	adds r2, 0x8
	adds r6, 0x1
_0803D840:
	cmp r6, 0x1F
	bgt _0803D85A
	ldr r5, _0803D86C
	lsls r4, r6, 3
	ldr r0, [r5]
	adds r0, r2
	str r2, [sp]
	bl sub_808E9B8
	lsls r0, 16
	ldr r2, [sp]
	cmp r0, 0
	bne _0803D824
_0803D85A:
	adds r0, r7, 0
	add sp, 0x4
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r1}
	bx r1
	.align 2, 0
_0803D868: .4byte 0x0001cd98
_0803D86C: .4byte gUnknown_203B418
	thumb_func_end sub_803D808

	thumb_func_start sub_803D870
sub_803D870:
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	adds r6, r1, 0
	movs r5, 0
	lsls r1, r6, 3
	adds r1, r0
	mov r9, r1
	b _0803D8B8
_0803D884:
	bl GetPokemonSize
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bhi _0803D8B6
	ldr r1, [r7]
	adds r0, r1, r4
	ldr r2, _0803D8E4
	adds r0, r2
	movs r2, 0
	ldrsh r0, [r0, r2]
	cmp r0, 0
	beq _0803D8B6
	mov r2, r8
	adds r0, r1, r2
	adds r0, r4
	ldr r1, [r0, 0x4]
	ldr r0, [r0]
	mov r2, r9
	adds r2, 0x8
	mov r9, r2
	subs r2, 0x8
	stm r2!, {r0,r1}
	adds r6, 0x1
_0803D8B6:
	adds r5, 0x1
_0803D8B8:
	cmp r5, 0x1F
	bgt _0803D8D6
	ldr r7, _0803D8E8
	lsls r4, r5, 3
	ldr r0, _0803D8EC
	mov r8, r0
	adds r1, r4, r0
	ldr r0, [r7]
	adds r0, r1
	bl sub_808E9B8
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0
	bne _0803D884
_0803D8D6:
	adds r0, r6, 0
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r1}
	bx r1
	.align 2, 0
_0803D8E4: .4byte 0x0001cd9a
_0803D8E8: .4byte gUnknown_203B418
_0803D8EC: .4byte 0x0001cd98
	thumb_func_end sub_803D870

	thumb_func_start sub_803D8F0
sub_803D8F0:
	push {r4,lr}
	ldr r4, _0803D920
	ldr r0, [r4]
	ldr r2, _0803D924
	adds r1, r0, r2
	ldrb r0, [r1]
	cmp r0, 0
	bne _0803D918
	movs r0, 0x1
	strb r0, [r1]
	ldr r0, [r4]
	ldr r1, _0803D928
	adds r0, r1
	movs r1, 0
	bl sub_803D808
	ldr r1, [r4]
	ldr r2, _0803D92C
	adds r1, r2
	str r0, [r1]
_0803D918:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0803D920: .4byte gUnknown_203B418
_0803D924: .4byte 0x000037ec
_0803D928: .4byte 0x0000343c
_0803D92C: .4byte 0x000037e4
	thumb_func_end sub_803D8F0

	thumb_func_start sub_803D930
sub_803D930:
	push {r4-r7,lr}
	lsls r0, 16
	asrs r6, r0, 16
	movs r5, 0
	ldr r7, _0803D940
	ldr r4, _0803D944
	b _0803D954
	.align 2, 0
_0803D940: .4byte gUnknown_203B418
_0803D944: .4byte 0x0001cd98
_0803D948:
	cmp r0, r6
	bne _0803D950
	movs r0, 0x1
	b _0803D96A
_0803D950:
	adds r4, 0x8
	adds r5, 0x1
_0803D954:
	cmp r5, 0x1F
	bgt _0803D968
	ldr r0, [r7]
	adds r0, r4
	bl sub_808E9B8
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0
	bne _0803D948
_0803D968:
	movs r0, 0
_0803D96A:
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_803D930

	thumb_func_start sub_803D970
sub_803D970:
	push {r4-r7,lr}
	adds r5, r0, 0
	ldr r0, _0803D9EC
	bl sub_8084100
	adds r6, r0, 0
	movs r3, 0
	ldr r1, _0803D9F0
	ldr r0, [r1]
	ldr r2, _0803D9F4
	adds r0, r2
	ldr r0, [r0]
	cmp r3, r0
	bge _0803D9BA
	ldr r4, _0803D9F8
_0803D98E:
	ldr r2, [r1]
	lsls r1, r5, 1
	lsls r0, r3, 3
	adds r1, r0
	ldr r7, _0803D9FC
	adds r0, r2, r7
	adds r1, r0, r1
	movs r7, 0
	ldrsh r0, [r1, r7]
	cmp r0, 0
	beq _0803D9A8
	cmp r0, r6
	bge _0803D9E0
_0803D9A8:
	adds r4, 0x8
	adds r3, 0x1
	ldr r1, _0803D9F0
	ldr r0, [r1]
	ldr r2, _0803D9F4
	adds r0, r2
	ldr r0, [r0]
	cmp r3, r0
	blt _0803D98E
_0803D9BA:
	movs r3, 0
	ldr r0, _0803D9F0
	ldr r1, [r0]
	ldr r7, _0803D9F4
	adds r1, r7
	ldr r1, [r1]
	adds r6, r0, 0
	cmp r3, r1
	bge _0803DA10
	ldr r4, _0803D9F8
	lsls r1, r5, 1
_0803D9D0:
	ldr r2, [r6]
	ldr r5, _0803D9FC
	adds r0, r2, r5
	adds r0, r1
	movs r7, 0
	ldrsh r0, [r0, r7]
	cmp r0, 0
	beq _0803DA00
_0803D9E0:
	adds r0, r2, r4
	bl sub_808E9B8
	lsls r0, 16
	asrs r0, 16
	b _0803DA14
	.align 2, 0
_0803D9EC: .4byte 0x00002710
_0803D9F0: .4byte gUnknown_203B418
_0803D9F4: .4byte 0x000037e4
_0803D9F8: .4byte 0x0000343c
_0803D9FC: .4byte 0x0000343e
_0803DA00:
	adds r4, 0x8
	adds r1, 0x8
	adds r3, 0x1
	ldr r5, _0803DA1C
	adds r0, r2, r5
	ldr r0, [r0]
	cmp r3, r0
	blt _0803D9D0
_0803DA10:
	movs r0, 0xBE
	lsls r0, 1
_0803DA14:
	pop {r4-r7}
	pop {r1}
	bx r1
	.align 2, 0
_0803DA1C: .4byte 0x000037e4
	thumb_func_end sub_803D970

	thumb_func_start sub_803DA20
sub_803DA20:
	push {r4-r7,lr}
	lsls r0, 16
	asrs r7, r0, 16
	movs r5, 0
	ldr r1, _0803DA54
	ldr r0, [r1]
	ldr r2, _0803DA58
	adds r0, r2
	ldr r0, [r0]
	cmp r5, r0
	bge _0803DA70
	adds r6, r1, 0
	ldr r4, _0803DA5C
_0803DA3A:
	ldr r0, [r6]
	adds r0, r4
	bl sub_808E9B8
	lsls r0, 16
	asrs r0, 16
	cmp r0, r7
	bne _0803DA60
	ldr r0, [r6]
	adds r0, r4
	bl sub_808E9E4
	b _0803DA72
	.align 2, 0
_0803DA54: .4byte gUnknown_203B418
_0803DA58: .4byte 0x000037e4
_0803DA5C: .4byte 0x0000343c
_0803DA60:
	adds r4, 0x8
	adds r5, 0x1
	ldr r0, [r6]
	ldr r1, _0803DA78
	adds r0, r1
	ldr r0, [r0]
	cmp r5, r0
	blt _0803DA3A
_0803DA70:
	movs r0, 0x1
_0803DA72:
	pop {r4-r7}
	pop {r1}
	bx r1
	.align 2, 0
_0803DA78: .4byte 0x000037e4
	thumb_func_end sub_803DA20

	thumb_func_start ShowDungeonNameBanner
ShowDungeonNameBanner:
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	sub sp, 0x68
	ldr r0, _0803DB84
	ldr r4, _0803DB88
	adds r1, r4, 0
	bl OpenFileAndGetFileDataPtr
	ldr r5, _0803DB8C
	str r0, [r5]
	ldr r0, _0803DB90
	adds r1, r4, 0
	bl OpenFileAndGetFileDataPtr
	ldr r1, _0803DB94
	str r0, [r1]
	ldr r1, _0803DB98
	ldr r0, [r0, 0x4]
	ldr r0, [r0, 0x4]
	str r0, [r1]
	movs r4, 0
_0803DAAA:
	adds r0, r4, 0
	adds r0, 0xE0
	ldr r1, [r5]
	lsls r2, r4, 2
	ldr r1, [r1, 0x4]
	adds r1, r2
	bl SetBGPaletteBufferColorArray
	adds r4, 0x1
	cmp r4, 0xF
	ble _0803DAAA
	ldr r0, _0803DB9C
	movs r1, 0xE0
	lsls r1, 5
	bl CpuClear
	bl sub_80848EC
	lsls r0, 24
	cmp r0, 0
	bne _0803DAD6
	b _0803DBEA
_0803DAD6:
	ldr r0, _0803DBA0
	ldr r0, [r0]
	ldr r1, _0803DBA4
	adds r2, r0, r1
	movs r3, 0x14
	ldrsh r1, [r0, r3]
	ldrb r2, [r2]
	adds r2, r1
	mov r8, r2
	ldr r1, _0803DBA8
	adds r0, r1
	ldrb r0, [r0]
	bl GetDungeonName2
	mov r9, r0
	movs r5, 0xA
	movs r0, 0
_0803DAF8:
	movs r4, 0
	adds r6, r0, 0x4
	adds r7, r0, 0x1
_0803DAFE:
	adds r4, 0x1
	ldr r3, _0803DBAC
	adds r0, r3, 0
	adds r2, r5, 0
	orrs r2, r0
	lsls r2, 16
	lsrs r2, 16
	adds r0, r4, 0
	adds r1, r6, 0
	movs r3, 0
	bl sub_8008DC8
	adds r5, 0x1
	cmp r4, 0x1B
	ble _0803DAFE
	adds r0, r7, 0
	cmp r0, 0x7
	ble _0803DAF8
	mov r0, r9
	bl CalcStringWidth
	movs r1, 0xE0
	subs r1, r0
	lsrs r0, r1, 31
	adds r1, r0
	asrs r1, 1
	mov r0, r9
	movs r2, 0
	bl sub_803DC14
	adds r7, r0, 0
	ldr r0, _0803DBA0
	ldr r0, [r0]
	ldr r1, _0803DBA8
	adds r0, r1
	ldrb r0, [r0]
	bl GetStairDirection
	lsls r0, 24
	ldr r6, _0803DBB0
	cmp r0, 0
	beq _0803DB54
	ldr r6, _0803DBB4
_0803DB54:
	mov r3, r8
	cmp r3, 0x9
	ble _0803DBBC
	ldr r5, _0803DBB8
	mov r0, r8
	movs r1, 0xA
	bl __divsi3
	adds r4, r0, 0
	adds r4, 0x30
	mov r0, r8
	movs r1, 0xA
	bl __modsi3
	adds r0, 0x30
	str r0, [sp]
	add r0, sp, 0x4
	adds r1, r5, 0
	adds r2, r6, 0
	adds r3, r4, 0
	bl sub_800D158
	b _0803DBCA
	.align 2, 0
_0803DB84: .4byte gUnknown_80F60F8
_0803DB88: .4byte gUnknown_83B0000
_0803DB8C: .4byte gDungeonNameBannerPalette
_0803DB90: .4byte gUnknown_80F6100
_0803DB94: .4byte gDungeonNameBannerFontFile
_0803DB98: .4byte gDungeonNameBannerFont
_0803DB9C: .4byte 0x06000140
_0803DBA0: .4byte gUnknown_203B418
_0803DBA4: .4byte 0x00000645
_0803DBA8: .4byte 0x00000644
_0803DBAC: .4byte 0xffffe000
_0803DBB0: .4byte gUnknown_80F610C
_0803DBB4: .4byte gUnknown_80F6108
_0803DBB8: .4byte gUnknown_80F6110
_0803DBBC:
	ldr r1, _0803DC08
	mov r3, r8
	adds r3, 0x30
	add r0, sp, 0x4
	adds r2, r6, 0
	bl sub_800D158
_0803DBCA:
	add r0, sp, 0x4
	bl CalcStringWidth
	movs r1, 0xE0
	subs r1, r0
	lsrs r0, r1, 31
	adds r1, r0
	asrs r1, 1
	adds r2, r7, 0
	adds r2, 0x20
	add r0, sp, 0x4
	bl sub_803DC14
	ldr r1, _0803DC0C
	movs r0, 0x1
	strb r0, [r1]
_0803DBEA:
	ldr r0, _0803DC10
	ldr r0, [r0]
	bl CloseFile
	movs r0, 0x2
	bl sub_803E46C
	add sp, 0x68
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_0803DC08: .4byte gUnknown_80F6118
_0803DC0C: .4byte gUnknown_20274A5
_0803DC10: .4byte gDungeonNameBannerFontFile
	thumb_func_end ShowDungeonNameBanner

	thumb_func_start sub_803DC14
sub_803DC14:
	push {r4-r6,lr}
	adds r4, r0, 0
	adds r5, r1, 0
	adds r6, r2, 0
	b _0803DC5C
_0803DC1E:
	ldrb r1, [r4]
	adds r4, 0x1
	cmp r1, 0x2F
	bne _0803DC2C
	movs r5, 0
	adds r6, 0x18
	b _0803DC5C
_0803DC2C:
	cmp r1, 0x23
	bne _0803DC34
	adds r5, 0x8
	b _0803DC5C
_0803DC34:
	cmp r1, 0x20
	bne _0803DC3C
	adds r5, 0xC
	b _0803DC5C
_0803DC3C:
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	beq _0803DC50
	ldrb r0, [r4]
	cmp r0, 0
	beq _0803DC50
	lsls r1, 8
	orrs r1, r0
	adds r4, 0x1
_0803DC50:
	adds r0, r1, 0
	adds r1, r5, 0
	adds r2, r6, 0
	bl sub_803DC6C
	adds r5, r0
_0803DC5C:
	ldrb r0, [r4]
	cmp r0, 0
	bne _0803DC1E
	adds r0, r6, 0
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end sub_803DC14

	thumb_func_start sub_803DC6C
sub_803DC6C:
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	sub sp, 0x120
	adds r7, r1, 0
	adds r5, r2, 0
	bl sub_803DEC8
	adds r4, r0, 0
	ldr r0, [r4]
	mov r1, sp
	bl sub_803DD30
	ldrb r4, [r4, 0x6]
	mov r9, r4
	mov r6, sp
	adds r0, r5, 0
	cmp r5, 0
	bge _0803DC96
	adds r0, r5, 0x7
_0803DC96:
	asrs r0, 3
	lsls r3, r0, 3
	subs r0, r3, r0
	lsls r0, 2
	adds r1, r7, 0
	cmp r7, 0
	bge _0803DCA6
	adds r1, r7, 0x7
_0803DCA6:
	asrs r1, 3
	adds r0, r1
	lsls r0, 5
	ldr r4, _0803DD28
	adds r2, r0, r4
	subs r0, r5, r3
	lsls r0, 2
	adds r2, r0
	lsls r1, 3
	subs r1, r7, r1
	lsls r1, 4
	ldr r0, _0803DD2C
	adds r4, r1, r0
	movs r0, 0
_0803DCC2:
	adds r3, r2, 0
	adds r7, r3, 0x4
	adds r5, 0x1
	mov r12, r5
	adds r0, 0x1
	mov r8, r0
	movs r5, 0x2
_0803DCD0:
	ldr r2, [r6]
	cmp r2, 0
	beq _0803DCF6
	ldr r1, [r4]
	ands r1, r2
	ldr r0, [r4, 0x8]
	lsls r1, r0
	ldr r0, [r3]
	orrs r0, r1
	str r0, [r3]
	adds r3, 0x20
	ldr r0, [r4, 0x4]
	ands r2, r0
	ldr r0, [r4, 0xC]
	lsrs r2, r0
	ldr r0, [r3]
	orrs r0, r2
	str r0, [r3]
	subs r3, 0x20
_0803DCF6:
	adds r6, 0x4
	adds r3, 0x20
	subs r5, 0x1
	cmp r5, 0
	bge _0803DCD0
	adds r2, r7, 0
	mov r5, r12
	movs r0, 0x7
	ands r0, r5
	cmp r0, 0
	bne _0803DD12
	movs r0, 0xD8
	lsls r0, 2
	adds r2, r7, r0
_0803DD12:
	mov r0, r8
	cmp r0, 0x17
	ble _0803DCC2
	mov r0, r9
	add sp, 0x120
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r1}
	bx r1
	.align 2, 0
_0803DD28: .4byte 0x06000140
_0803DD2C: .4byte gUnknown_80F6120
	thumb_func_end sub_803DC6C

	thumb_func_start sub_803DD30
sub_803DD30:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	ldr r4, _0803DDBC
	add sp, r4
	adds r4, r0, 0
	mov r10, r1
	movs r3, 0
	movs r5, 0
	ldr r0, _0803DDC0
	mov r8, r0
	movs r6, 0xF
	movs r7, 0xF
	mov r2, sp
_0803DD50:
	ldrb r0, [r4]
	lsrs r1, r0, 4
	ands r1, r6
	strb r1, [r2]
	adds r1, r7, 0
	ands r1, r0
	strb r1, [r2, 0x1]
	adds r4, 0x1
	adds r2, 0x2
	adds r5, 0x2
	cmp r5, r8
	ble _0803DD50
	ldr r1, _0803DDC0
	cmp r3, r1
	bgt _0803DDF8
	movs r0, 0x90
	lsls r0, 2
	mov r2, sp
	adds r2, r0
	mov r12, r2
	mov r8, r1
	mov r2, sp
	mov r9, r0
_0803DD7E:
	ldrb r1, [r2]
	adds r2, 0x1
	movs r6, 0x7
	ands r6, r1
	movs r0, 0x8
	ands r1, r0
	cmp r1, 0
	beq _0803DDC4
	ldrb r1, [r2]
	adds r2, 0x1
	movs r4, 0
	cmp r4, r6
	bge _0803DDF4
	mov r5, r12
	adds r0, r5, r3
	strb r1, [r0]
	adds r3, 0x1
	cmp r3, r8
	bgt _0803DDF8
	mov r5, sp
	add r5, r9
	ldr r7, _0803DDC0
_0803DDAA:
	adds r4, 0x1
	cmp r4, r6
	bge _0803DDF4
	adds r0, r5, r3
	strb r1, [r0]
	adds r3, 0x1
	cmp r3, r7
	ble _0803DDAA
	b _0803DDF4
	.align 2, 0
_0803DDBC: .4byte 0xfffffb80
_0803DDC0: .4byte 0x0000023f
_0803DDC4:
	movs r4, 0
	cmp r4, r6
	bge _0803DDF4
	ldrb r1, [r2]
	adds r2, 0x1
	mov r5, r12
	adds r0, r5, r3
	strb r1, [r0]
	adds r3, 0x1
	cmp r3, r8
	bgt _0803DDF8
	mov r5, sp
	add r5, r9
	ldr r7, _0803DE78
_0803DDE0:
	adds r4, 0x1
	cmp r4, r6
	bge _0803DDF4
	ldrb r1, [r2]
	adds r2, 0x1
	adds r0, r5, r3
	strb r1, [r0]
	adds r3, 0x1
	cmp r3, r7
	ble _0803DDE0
_0803DDF4:
	cmp r3, r8
	ble _0803DD7E
_0803DDF8:
	movs r5, 0
	ldr r4, _0803DE78
	add r3, sp, 0x240
_0803DDFE:
	ldrb r2, [r3, 0x7]
	lsls r2, 28
	ldrb r0, [r3, 0x6]
	lsls r0, 24
	movs r1, 0xF0
	lsls r1, 20
	ands r0, r1
	orrs r2, r0
	ldrb r0, [r3, 0x5]
	lsls r0, 20
	movs r1, 0xF0
	lsls r1, 16
	ands r0, r1
	orrs r2, r0
	ldrb r0, [r3, 0x4]
	lsls r0, 16
	movs r1, 0xF0
	lsls r1, 12
	ands r0, r1
	orrs r2, r0
	ldrb r0, [r3, 0x3]
	lsls r0, 12
	movs r1, 0xF0
	lsls r1, 8
	ands r0, r1
	orrs r2, r0
	ldrb r0, [r3, 0x2]
	lsls r0, 8
	movs r1, 0xF0
	lsls r1, 4
	ands r0, r1
	orrs r2, r0
	ldrb r0, [r3, 0x1]
	lsls r0, 4
	movs r1, 0xF0
	ands r0, r1
	orrs r2, r0
	ldrb r1, [r3]
	movs r0, 0xF
	ands r0, r1
	orrs r2, r0
	mov r0, r10
	adds r0, 0x4
	mov r10, r0
	subs r0, 0x4
	stm r0!, {r2}
	adds r3, 0x8
	adds r5, 0x8
	cmp r5, r4
	ble _0803DDFE
	movs r3, 0x90
	lsls r3, 3
	add sp, r3
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_0803DE78: .4byte 0x0000023f
	thumb_func_end sub_803DD30

	thumb_func_start CalcStringWidth
CalcStringWidth:
	push {r4,r5,lr}
	adds r4, r0, 0
	movs r5, 0
	b _0803DEBA
_0803DE84:
	ldrb r1, [r4]
	adds r4, 0x1
	cmp r1, 0x23
	bne _0803DE90
	adds r5, 0x8
	b _0803DEBA
_0803DE90:
	cmp r1, 0x20
	bne _0803DE98
	adds r5, 0xC
	b _0803DEBA
_0803DE98:
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	beq _0803DEAC
	ldrb r0, [r4]
	cmp r0, 0
	beq _0803DEAC
	lsls r1, 8
	orrs r1, r0
	adds r4, 0x1
_0803DEAC:
	adds r0, r1, 0
	bl sub_803DEC8
	cmp r0, 0
	beq _0803DEBA
	ldrb r0, [r0, 0x6]
	adds r5, r0
_0803DEBA:
	ldrb r0, [r4]
	cmp r0, 0
	bne _0803DE84
	adds r0, r5, 0
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end CalcStringWidth

	thumb_func_start sub_803DEC8
sub_803DEC8:
	push {r4,r5,lr}
	adds r3, r0, 0
	ldr r0, _0803DEFC
	ldr r0, [r0]
	ldr r0, [r0, 0x4]
	ldr r5, [r0]
	ldr r0, _0803DF00
	adds r1, r3, r0
	ldr r0, _0803DF04
	cmp r1, r0
	bhi _0803DF08
	movs r2, 0xFF
	ands r2, r3
	movs r1, 0xFF
	lsls r1, 8
	ands r1, r3
	asrs r1, 8
	subs r2, 0x20
	subs r1, 0xF8
	lsls r0, r1, 3
	subs r0, r1
	lsls r0, 5
	adds r0, r2
	lsls r0, 3
	adds r1, r5, r0
	b _0803DF56
	.align 2, 0
_0803DEFC: .4byte gDungeonNameBannerFontFile
_0803DF00: .4byte 0xffff0800
_0803DF04: .4byte 0x000007fe
_0803DF08:
	movs r4, 0
	ldr r0, _0803DF1C
	ldr r0, [r0]
	subs r2, r0, 0x1
	cmp r4, r2
	bge _0803DF48
	lsrs r0, r2, 31
	adds r0, r2, r0
	b _0803DF3A
	.align 2, 0
_0803DF1C: .4byte gDungeonNameBannerFont
_0803DF20:
	lsls r0, r1, 3
	adds r0, r5
	ldrh r0, [r0, 0x4]
	cmp r0, r3
	bge _0803DF2E
	adds r4, r1, 0x1
	b _0803DF30
_0803DF2E:
	adds r2, r1, 0
_0803DF30:
	cmp r4, r2
	bge _0803DF48
	adds r0, r4, r2
	lsrs r1, r0, 31
	adds r0, r1
_0803DF3A:
	asrs r1, r0, 1
	lsls r0, r1, 3
	adds r0, r5
	ldrh r0, [r0, 0x4]
	cmp r0, r3
	bne _0803DF20
	adds r4, r1, 0
_0803DF48:
	lsls r0, r4, 3
	adds r1, r5, r0
	ldrh r0, [r1, 0x4]
	cmp r0, r3
	beq _0803DF56
	adds r1, r5, 0
	adds r1, 0x8
_0803DF56:
	adds r0, r1, 0
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_803DEC8

	thumb_func_start sub_803DF60
sub_803DF60:
	push {r4-r7,lr}
	ldr r0, _0803DFF8
	ldr r1, _0803DFFC
	bl OpenFileAndGetFileDataPtr
	adds r7, r0, 0
	ldr r0, [r7, 0x4]
	ldr r5, [r0]
	ldm r5!, {r4}
	ldr r6, _0803E000
	cmp r4, 0
	beq _0803DF8C
_0803DF78:
	adds r0, r6, 0
	adds r1, r5, 0
	movs r2, 0x20
	bl CpuCopy
	adds r6, 0x20
	adds r5, 0x20
	subs r4, 0x1
	cmp r4, 0
	bne _0803DF78
_0803DF8C:
	adds r0, r7, 0
	bl CloseFile
	ldr r0, _0803E004
	ldr r1, _0803DFFC
	bl OpenFileAndGetFileDataPtr
	adds r7, r0, 0
	ldr r5, [r7, 0x4]
	ldm r5!, {r4}
	ldr r6, _0803E008
	cmp r4, 0
	beq _0803DFBA
_0803DFA6:
	adds r0, r6, 0
	adds r1, r5, 0
	movs r2, 0x20
	bl CpuCopy
	adds r6, 0x20
	adds r5, 0x20
	subs r4, 0x1
	cmp r4, 0
	bne _0803DFA6
_0803DFBA:
	adds r0, r7, 0
	bl CloseFile
	ldr r0, _0803E00C
	ldr r4, _0803DFFC
	adds r1, r4, 0
	bl OpenFileAndGetFileDataPtr
	ldr r1, _0803E010
	str r0, [r1]
	ldr r0, _0803E014
	adds r1, r4, 0
	bl OpenFileAndGetFileDataPtr
	ldr r1, _0803E018
	str r0, [r1]
	ldr r0, _0803E01C
	adds r1, r4, 0
	bl OpenFileAndGetFileDataPtr
	ldr r1, _0803E020
	str r0, [r1]
	ldr r0, _0803E024
	adds r1, r4, 0
	bl OpenFileAndGetFileDataPtr
	ldr r1, _0803E028
	str r0, [r1]
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_0803DFF8: .4byte gUnknown_80F61A8
_0803DFFC: .4byte gUnknown_83B0000
_0803E000: .4byte 0x06013400
_0803E004: .4byte gUnknown_80F61B0
_0803E008: .4byte 0x06014000
_0803E00C: .4byte gUnknown_80F61B8
_0803E010: .4byte gUnknown_202EC94
_0803E014: .4byte gUnknown_80F61C4
_0803E018: .4byte gUnknown_202EC98
_0803E01C: .4byte gUnknown_80F61CC
_0803E020: .4byte gUnknown_202EC9C
_0803E024: .4byte gUnknown_80F61D4
_0803E028: .4byte gUnknown_202ECA0
	thumb_func_end sub_803DF60

	thumb_func_start sub_803E02C
sub_803E02C:
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	sub sp, 0xC
	bl sub_803E13C
	mov r1, sp
	ldr r0, _0803E118
	ldm r0!, {r2,r3}
	stm r1!, {r2,r3}
	ldr r1, _0803E11C
	mov r0, sp
	bl OpenFileAndGetFileDataPtr
	adds r7, r0, 0
	ldr r0, [r7, 0x4]
	ldr r5, [r0]
	ldm r5!, {r4}
	ldr r6, _0803E120
	cmp r4, 0
	beq _0803E06C
_0803E058:
	adds r0, r6, 0
	adds r1, r5, 0
	movs r2, 0x20
	bl CpuCopy
	adds r6, 0x20
	adds r5, 0x20
	subs r4, 0x1
	cmp r4, 0
	bne _0803E058
_0803E06C:
	ldr r0, _0803E124
	ldr r1, [r7, 0x4]
	ldr r1, [r1, 0x4]
	movs r2, 0x80
	bl CpuCopy
	adds r0, r7, 0
	bl CloseFile
	movs r6, 0x80
	lsls r6, 2
	movs r4, 0
	ldr r0, _0803E128
	mov r9, r0
	ldr r1, _0803E12C
	mov r12, r1
	movs r7, 0
	ldr r2, _0803E130
	mov r8, r2
_0803E092:
	mov r3, r12
	ldrh r0, [r3]
	lsls r5, r0, 12
	adds r2, r7, 0
	movs r3, 0x8
_0803E09C:
	mov r0, r9
	ldr r1, [r0]
	add r1, r8
	adds r1, r2
	adds r0, r5, 0
	orrs r0, r6
	strh r0, [r1]
	adds r6, 0x1
	adds r2, 0x2
	subs r3, 0x1
	cmp r3, 0
	bge _0803E09C
	movs r1, 0x2
	add r12, r1
	adds r7, 0x12
	adds r4, 0x1
	cmp r4, 0x1C
	ble _0803E092
	movs r4, 0
	ldr r5, _0803E128
	ldr r3, _0803E134
	movs r2, 0xC0
	lsls r2, 8
_0803E0CA:
	ldr r0, [r5]
	lsls r1, r4, 1
	adds r0, r3
	adds r0, r1
	strh r2, [r0]
	adds r4, 0x1
	cmp r4, 0x8
	ble _0803E0CA
	movs r4, 0
	ldr r2, _0803E128
	movs r6, 0xBE
	lsls r6, 1
	ldr r5, _0803E138
	movs r3, 0xBF
	lsls r3, 1
_0803E0E8:
	ldr r0, [r2]
	lsls r1, r4, 2
	adds r0, r1
	adds r0, r6
	strb r4, [r0]
	ldr r0, [r2]
	adds r0, r1
	adds r0, r5
	strb r4, [r0]
	ldr r0, [r2]
	adds r0, r1
	adds r0, r3
	strb r4, [r0]
	adds r4, 0x1
	cmp r4, 0xFF
	ble _0803E0E8
	add sp, 0xC
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_0803E118: .4byte gUnknown_80F61DC
_0803E11C: .4byte gUnknown_83B0000
_0803E120: .4byte 0x0600c000
_0803E124: .4byte gUnknown_202ECA4
_0803E128: .4byte gUnknown_203B418
_0803E12C: .4byte gUnknown_80F5F70
_0803E130: .4byte 0x00012a18
_0803E134: .4byte 0x00013554
_0803E138: .4byte 0x0000017d
	thumb_func_end sub_803E02C

	thumb_func_start sub_803E13C
sub_803E13C:
	push {r4,r5,lr}
	bl sub_8094C14
	ldr r0, _0803E170
	ldr r0, [r0]
	ldrb r0, [r0, 0xB]
	ldr r5, _0803E174
	cmp r0, 0
	beq _0803E154
	movs r0, 0x80
	lsls r0, 1
	adds r5, r0
_0803E154:
	movs r4, 0
_0803E156:
	adds r0, r4, 0
	adds r0, 0xF0
	adds r1, r5, 0
	bl SetBGPaletteBufferColorArray
	adds r5, 0x4
	adds r4, 0x1
	cmp r4, 0xF
	ble _0803E156
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_0803E170: .4byte gUnknown_203B46C
_0803E174: .4byte gUnknown_202D038
	thumb_func_end sub_803E13C

	thumb_func_start sub_803E178
sub_803E178:
	push {r4,lr}
	bl sub_8043D10
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0
	bne _0803E1E0
	ldr r0, _0803E1AC
	ldr r2, [r0]
	ldr r3, _0803E1B0
	adds r1, r2, r3
	ldrb r1, [r1]
	adds r3, r0, 0
	cmp r1, 0x15
	bne _0803E1BC
	ldr r1, _0803E1B4
	adds r0, r2, r1
	ldrb r0, [r0]
	cmp r0, 0
	bne _0803E1BC
	ldr r3, _0803E1B8
	adds r1, r2, r3
	movs r0, 0x1C
	strh r0, [r1]
	b _0803E204
	.align 2, 0
_0803E1AC: .4byte gUnknown_203B418
_0803E1B0: .4byte 0x00000644
_0803E1B4: .4byte 0x000037fe
_0803E1B8: .4byte 0x00003a12
_0803E1BC:
	ldr r4, [r3]
	ldr r1, _0803E1D8
	adds r0, r4, r1
	ldrb r0, [r0]
	bl GetStairDirection
	lsls r0, 24
	movs r1, 0x16
	cmp r0, 0
	beq _0803E1D2
	movs r1, 0x17
_0803E1D2:
	ldr r2, _0803E1DC
	adds r0, r4, r2
	b _0803E202
	.align 2, 0
_0803E1D8: .4byte 0x00000644
_0803E1DC: .4byte 0x00003a12
_0803E1E0:
	cmp r0, 0x1
	bne _0803E1F8
	ldr r0, _0803E1F0
	ldr r0, [r0]
	ldr r3, _0803E1F4
	adds r0, r3
	movs r1, 0x6
	b _0803E202
	.align 2, 0
_0803E1F0: .4byte gUnknown_203B418
_0803E1F4: .4byte 0x00003a12
_0803E1F8:
	ldr r0, _0803E20C
	ldr r0, [r0]
	ldr r1, _0803E210
	adds r0, r1
	movs r1, 0x18
_0803E202:
	strh r1, [r0]
_0803E204:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0803E20C: .4byte gUnknown_203B418
_0803E210: .4byte 0x00003a12
	thumb_func_end sub_803E178

	thumb_func_start sub_803E214
sub_803E214:
	push {lr}
	ldr r0, _0803E23C
	ldr r0, [r0]
	bl CloseFile
	ldr r0, _0803E240
	ldr r0, [r0]
	bl CloseFile
	ldr r0, _0803E244
	ldr r0, [r0]
	bl CloseFile
	ldr r0, _0803E248
	ldr r0, [r0]
	bl CloseFile
	pop {r0}
	bx r0
	.align 2, 0
_0803E23C: .4byte gUnknown_202EC94
_0803E240: .4byte gUnknown_202EC98
_0803E244: .4byte gUnknown_202EC9C
_0803E248: .4byte gUnknown_202ECA0
	thumb_func_end sub_803E214

	thumb_func_start nullsub_56
nullsub_56:
	bx lr
	thumb_func_end nullsub_56

	thumb_func_start sub_803E250
sub_803E250:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x8
	ldr r1, _0803E3FC
	ldr r0, _0803E400
	str r0, [r1]
	ldr r0, _0803E404
	movs r1, 0
	str r1, [r0]
	ldr r0, _0803E408
	strb r1, [r0]
	ldr r0, _0803E40C
	strh r1, [r0]
	ldr r5, _0803E410
	ldrh r0, [r5, 0x6]
	movs r3, 0xF
	adds r2, r3, 0
	ands r2, r0
	ldrh r4, [r5]
	ldr r1, _0803E414
	adds r0, r1, 0
	ands r0, r4
	ldr r4, _0803E418
	ands r0, r4
	ldr r6, _0803E41C
	ands r0, r6
	ldr r7, _0803E420
	ands r0, r7
	ldr r4, _0803E424
	mov r12, r4
	ands r0, r4
	ldr r4, _0803E428
	ands r0, r4
	strh r0, [r5]
	movs r0, 0x80
	lsls r0, 7
	strh r0, [r5, 0x2]
	movs r0, 0
	strh r0, [r5, 0x4]
	ldr r0, _0803E42C
	mov r10, r0
	ands r2, r0
	subs r0, 0x1
	mov r9, r0
	ands r2, r0
	subs r0, 0x2
	mov r8, r0
	ands r2, r0
	strh r2, [r5, 0x6]
	ldr r2, _0803E430
	ldrh r0, [r2, 0x6]
	ands r3, r0
	ldrh r0, [r2]
	ands r1, r0
	ldr r0, _0803E418
	ands r1, r0
	ands r1, r6
	ands r1, r7
	mov r7, r12
	ands r1, r7
	ands r1, r4
	strh r1, [r2]
	movs r0, 0
	strh r0, [r2, 0x2]
	movs r0, 0xB8
	lsls r0, 7
	strh r0, [r2, 0x4]
	mov r0, r10
	ands r3, r0
	mov r1, r9
	ands r3, r1
	mov r7, r8
	ands r3, r7
	strh r3, [r2, 0x6]
	movs r0, 0
	mov r8, r0
_0803E2EE:
	movs r1, 0
	mov r9, r1
	mov r2, r8
	lsls r0, r2, 3
	lsls r2, 1
	mov r12, r2
	mov r3, r8
	adds r3, 0x1
	str r3, [sp]
	mov r10, r1
	add r0, r8
	lsls r5, r0, 3
	ldr r4, _0803E434
	adds r4, r5, r4
	str r4, [sp, 0x4]
	ldr r7, _0803E438
	adds r6, r5, r7
	ldr r0, _0803E43C
	adds r3, r5, r0
	ldr r1, _0803E440
	adds r4, r5, r1
_0803E318:
	mov r7, r10
	adds r2, r5, r7
	ldrh r1, [r3]
	ldr r0, _0803E414
	ands r0, r1
	ldr r1, _0803E418
	ands r0, r1
	ldr r1, _0803E41C
	ands r0, r1
	ldr r1, _0803E420
	ands r0, r1
	ldr r1, _0803E424
	ands r0, r1
	strh r0, [r3]
	ldr r1, [r4]
	movs r7, 0x3
	ands r1, r7
	lsls r1, 14
	ldr r7, _0803E428
	ands r0, r7
	orrs r0, r1
	strh r0, [r3]
	ldrh r1, [r3, 0x2]
	ldr r0, _0803E444
	ands r0, r1
	strh r0, [r3, 0x2]
	ldr r1, _0803E440
	adds r1, 0x4
	adds r2, r1
	ldr r1, [r2]
	movs r2, 0x3
	ands r1, r2
	lsls r1, 14
	ands r0, r7
	orrs r0, r1
	strh r0, [r3, 0x2]
	ldr r1, [r6]
	ldr r0, _0803E448
	ands r1, r0
	ldrh r2, [r3, 0x4]
	movs r0, 0xFC
	lsls r0, 8
	ands r0, r2
	orrs r0, r1
	ldr r7, _0803E41C
	ands r0, r7
	movs r1, 0xC0
	lsls r1, 4
	orrs r0, r1
	movs r2, 0
	orrs r0, r2
	ldr r1, _0803E44C
	ands r0, r1
	strh r0, [r3, 0x4]
	ldrh r1, [r3, 0x6]
	ldr r0, _0803E42C
	ands r0, r1
	ldr r1, _0803E450
	ands r0, r1
	strh r0, [r3, 0x6]
	mov r7, r9
	lsls r1, r7, 2
	mov r0, r12
	add r0, r8
	lsls r0, 3
	adds r1, r0
	ldr r0, _0803E454
	adds r1, r0, r1
	ldr r0, [r1]
	ldr r1, [sp, 0x4]
	str r0, [r1]
	adds r1, 0xC
	str r1, [sp, 0x4]
	adds r6, 0xC
	adds r3, 0xC
	adds r4, 0xC
	movs r2, 0xC
	add r10, r2
	movs r7, 0x1
	add r9, r7
	mov r0, r9
	cmp r0, 0x5
	ble _0803E318
	ldr r1, [sp]
	mov r8, r1
	cmp r1, 0x1
	ble _0803E2EE
	movs r2, 0
	ldr r3, _0803E458
	ldr r0, [r3]
	ldr r4, _0803E45C
	adds r0, r4
	movs r1, 0x1
	strb r1, [r0]
	ldr r0, [r3]
	ldr r7, _0803E460
	adds r0, r7
	strb r1, [r0]
	ldr r0, _0803E464
	str r2, [r0]
	movs r0, 0xF8
	ldr r1, _0803E468
	movs r3, 0
	bl SetBGPaletteBufferColorRGB
	add sp, 0x8
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_0803E3FC: .4byte gUnknown_202EDD0
_0803E400: .4byte 0x000003e7
_0803E404: .4byte gUnknown_202EDD4
_0803E408: .4byte gUnknown_203B40D
_0803E40C: .4byte gUnknown_202EDE8
_0803E410: .4byte gUnknown_202EDC0
_0803E414: .4byte 0x0000feff
_0803E418: .4byte 0x0000fdff
_0803E41C: .4byte 0x0000f3ff
_0803E420: .4byte 0x0000efff
_0803E424: .4byte 0x0000dfff
_0803E428: .4byte 0x00003fff
_0803E42C: .4byte 0x0000fffe
_0803E430: .4byte gUnknown_202EDB8
_0803E434: .4byte gUnknown_202ED30
_0803E438: .4byte gUnknown_80F6224
_0803E43C: .4byte gUnknown_202ED28
_0803E440: .4byte gUnknown_80F621C
_0803E444: .4byte 0x0000c1ff
_0803E448: .4byte 0x000003ff
_0803E44C: .4byte 0x00000fff
_0803E450: .4byte 0x0000fffd
_0803E454: .4byte gUnknown_80F61EC
_0803E458: .4byte gUnknown_203B418
_0803E45C: .4byte 0x00018217
_0803E460: .4byte 0x00018218
_0803E464: .4byte gUnknown_202EDC8
_0803E468: .4byte gUnknown_202D058
	thumb_func_end sub_803E250

	thumb_func_start sub_803E46C
sub_803E46C:
	push {lr}
	adds r1, r0, 0
	ldr r0, _0803E480
	ldrb r0, [r0]
	cmp r0, 0
	beq _0803E484
	adds r0, r1, 0
	bl sub_803E490
	b _0803E48A
	.align 2, 0
_0803E480: .4byte gUnknown_203B40C
_0803E484:
	adds r0, r1, 0
	bl sub_803E668
_0803E48A:
	pop {r0}
	bx r0
	thumb_func_end sub_803E46C

	thumb_func_start sub_803E490
sub_803E490:
	push {r4,r5,lr}
	sub sp, 0x8
	ldr r1, _0803E4D8
	ldr r0, [r1]
	adds r0, 0x1
	str r0, [r1]
	bl xxx_draw_string_80524F0
	bl sub_8085F78
	movs r0, 0x1
	bl sub_803F580
	ldr r2, _0803E4DC
	ldr r1, [r2]
	ldr r3, _0803E4E0
	adds r0, r1, r3
	ldrb r0, [r0]
	cmp r0, 0
	beq _0803E4EC
	ldr r4, _0803E4E4
	adds r1, r4
	movs r0, 0x2
	strb r0, [r1]
	ldr r1, [r2]
	ldr r2, _0803E4E8
	adds r0, r1, r2
	movs r3, 0
	ldrsh r0, [r0, r3]
	subs r4, 0x16
	adds r1, r4
	movs r2, 0
	ldrsh r1, [r1, r2]
	bl sub_800CCA0
	b _0803E4FC
	.align 2, 0
_0803E4D8: .4byte gUnknown_202EDD4
_0803E4DC: .4byte gUnknown_203B418
_0803E4E0: .4byte 0x0001821a
_0803E4E4: .4byte 0x00018208
_0803E4E8: .4byte 0x000181f0
_0803E4EC:
	ldr r3, _0803E628
	adds r1, r3
	movs r0, 0x3
	strb r0, [r1]
	movs r0, 0
	movs r1, 0
	bl sub_800CCA0
_0803E4FC:
	ldr r4, _0803E62C
	ldr r2, [r4]
	ldr r5, _0803E630
	adds r0, r2, r5
	movs r1, 0
	ldrsh r0, [r0, r1]
	ldr r3, _0803E634
	adds r1, r2, r3
	movs r3, 0
	ldrsh r1, [r1, r3]
	ldr r3, _0803E638
	adds r2, r3
	ldr r2, [r2]
	subs r1, r2
	bl sub_800CCAC
	bl sub_806CC10
	bl sub_804522C
	bl sub_803F9CC
	ldr r0, [r4]
	adds r0, r5
	bl sub_800F7D0
	ldr r1, [r4]
	ldrh r2, [r1, 0x12]
	movs r3, 0x12
	ldrsh r0, [r1, r3]
	cmp r0, 0x63
	bgt _0803E540
	adds r0, r2, 0x1
	strh r0, [r1, 0x12]
_0803E540:
	ldr r0, [r4]
	adds r0, r5
	bl sub_800E90C
	bl sub_8042E5C
	ldr r0, _0803E63C
	ldr r0, [r0]
	cmp r0, 0
	beq _0803E562
	cmp r0, 0x3
	beq _0803E562
	ldr r0, _0803E640
	ldr r0, [r0]
	ldrb r0, [r0, 0x4]
	cmp r0, 0x6
	bne _0803E566
_0803E562:
	bl sub_8040894
_0803E566:
	bl sub_803ECE0
	bl sub_803EDF0
	ldr r0, _0803E62C
	ldr r3, [r0]
	ldr r4, _0803E644
	adds r0, r3, r4
	ldrb r0, [r0]
	cmp r0, 0
	beq _0803E5A2
	ldr r1, _0803E648
	adds r0, r3, r1
	ldr r0, [r0]
	cmp r0, 0x3
	beq _0803E5A2
	ldr r0, _0803E64C
	ldrb r0, [r0]
	ldr r1, _0803E650
	ldr r2, _0803E654
	ldr r2, [r2]
	str r2, [sp]
	movs r4, 0xBE
	lsls r4, 1
	adds r2, r3, r4
	str r2, [sp, 0x4]
	movs r2, 0xA0
	movs r3, 0x20
	bl sub_8004AF0
_0803E5A2:
	ldr r0, _0803E640
	ldr r0, [r0]
	ldrb r0, [r0, 0xA]
	bl nullsub_8
	bl sub_8005180
	bl nullsub_12
	bl sub_80060EC
	ldr r1, _0803E658
	ldr r0, [r1]
	adds r0, 0x1
	str r0, [r1]
	ldr r0, _0803E65C
	ldr r0, [r0]
	bl sub_8094FB4
	bl sub_800CB20
	bl sub_800485C
	bl CopySpritesToOam
	bl nullsub_13
	bl sub_8005304
	bl nullsub_14
	bl TransferBGPaletteBuffer
	bl sub_8009908
	bl xxx_call_update_bg_vram
	bl sub_8040788
	bl xxx_call_update_bg_sound_input
	ldr r0, _0803E62C
	ldr r0, [r0]
	ldr r1, _0803E660
	adds r0, r1
	movs r1, 0
	strb r1, [r0]
	bl sub_8083F58
	bl sub_8011860
	bl sub_8040B60
	movs r0, 0
	bl ResetSprites
	movs r0, 0
	bl nullsub_10
	ldr r1, _0803E664
	ldr r0, [r1]
	subs r0, 0x1
	str r0, [r1]
	add sp, 0x8
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_0803E628: .4byte 0x00018208
_0803E62C: .4byte gUnknown_203B418
_0803E630: .4byte 0x000181f0
_0803E634: .4byte 0x000181f2
_0803E638: .4byte 0x000181fc
_0803E63C: .4byte gUnknown_202EDD0
_0803E640: .4byte gUnknown_203B46C
_0803E644: .4byte 0x00018215
_0803E648: .4byte 0x0001c06c
_0803E64C: .4byte gUnknown_203B40D
_0803E650: .4byte gUnknown_202EE8C
_0803E654: .4byte gUnknown_202EDC8
_0803E658: .4byte gUnknown_202EDCC
_0803E65C: .4byte gUnknown_203B47C
_0803E660: .4byte 0x00018213
_0803E664: .4byte gUnknown_202EDD4
	thumb_func_end sub_803E490

	thumb_func_start sub_803E668
sub_803E668:
	push {r4,lr}
	ldr r4, _0803E6F0
	ldr r0, [r4]
	adds r0, 0x1
	str r0, [r4]
	ldr r0, _0803E6F4
	ldr r0, [r0]
	ldrb r0, [r0, 0xA]
	bl nullsub_8
	bl sub_8005180
	bl nullsub_12
	movs r0, 0
	movs r1, 0
	bl sub_8005838
	bl sub_80060EC
	ldr r1, _0803E6F8
	ldr r0, [r1]
	adds r0, 0x1
	str r0, [r1]
	ldr r0, _0803E6FC
	ldr r0, [r0]
	bl sub_8094FB4
	bl sub_800CB20
	bl sub_800485C
	bl CopySpritesToOam
	bl nullsub_13
	bl sub_8005304
	bl nullsub_14
	bl TransferBGPaletteBuffer
	bl sub_8009908
	bl xxx_call_update_bg_vram
	bl xxx_call_update_bg_sound_input
	ldr r0, _0803E700
	ldr r0, [r0]
	ldr r1, _0803E704
	adds r0, r1
	movs r1, 0
	strb r1, [r0]
	bl sub_8011860
	movs r0, 0
	bl ResetSprites
	movs r0, 0
	bl nullsub_10
	ldr r0, [r4]
	subs r0, 0x1
	str r0, [r4]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0803E6F0: .4byte gUnknown_202EDD4
_0803E6F4: .4byte gUnknown_203B46C
_0803E6F8: .4byte gUnknown_202EDCC
_0803E6FC: .4byte gUnknown_203B47C
_0803E700: .4byte gUnknown_203B418
_0803E704: .4byte 0x00018213
	thumb_func_end sub_803E668

	thumb_func_start sub_803E708
sub_803E708:
	push {r4,r5,lr}
	adds r4, r0, 0
	adds r5, r1, 0
	cmp r4, 0
	beq _0803E71E
_0803E712:
	adds r0, r5, 0
	bl sub_803E46C
	subs r4, 0x1
	cmp r4, 0
	bne _0803E712
_0803E71E:
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_803E708

	thumb_func_start sub_803E724
sub_803E724:
	push {r4-r6,lr}
	adds r4, r0, 0
	ldr r5, _0803E744
	movs r6, 0xF0
_0803E72C:
	adds r0, r4, 0
	bl sub_803E46C
	ldrh r1, [r5]
	adds r0, r6, 0
	ands r0, r1
	cmp r0, 0
	bne _0803E72C
	pop {r4-r6}
	pop {r0}
	bx r0
	.align 2, 0
_0803E744: .4byte gUnknown_20255F0
	thumb_func_end sub_803E724

	thumb_func_start sub_803E748
sub_803E748:
	push {r4,r5,lr}
	movs r5, 0x1F
	ldr r1, _0803E7B8
	movs r0, 0x1
	strb r0, [r1]
	ldr r1, _0803E7BC
	movs r0, 0
	str r0, [r1]
	movs r0, 0x1
	movs r1, 0x1F
	bl sub_803E874
	movs r4, 0
_0803E762:
	cmp r4, 0x1F
	bgt _0803E780
	subs r5, 0x2
	cmp r5, 0
	bgt _0803E780
	movs r5, 0
	movs r0, 0x1
	movs r1, 0
	bl sub_803EAF0
	ldr r0, _0803E7C0
	ldr r0, [r0]
	ldr r1, _0803E7C4
	adds r0, r1
	strb r5, [r0]
_0803E780:
	cmp r4, 0xB
	ble _0803E790
	ldr r1, _0803E7BC
	ldr r0, [r1]
	cmp r0, 0x1E
	bgt _0803E790
	adds r0, 0x1
	str r0, [r1]
_0803E790:
	movs r0, 0x1
	adds r1, r5, 0
	bl sub_803E874
	movs r0, 0x5
	bl sub_803E46C
	adds r4, 0x1
	cmp r4, 0x2B
	ble _0803E762
	ldr r1, _0803E7B8
	movs r0, 0
	strb r0, [r1]
	ldr r1, _0803E7BC
	movs r0, 0x1F
	str r0, [r1]
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_0803E7B8: .4byte gUnknown_203B40D
_0803E7BC: .4byte gUnknown_202EDC8
_0803E7C0: .4byte gUnknown_203B418
_0803E7C4: .4byte 0x00018217
	thumb_func_end sub_803E748

	thumb_func_start sub_803E7C8
sub_803E7C8:
	push {r4,r5,lr}
	movs r4, 0x1F
	ldr r1, _0803E820
	movs r0, 0x1
	strb r0, [r1]
	ldr r1, _0803E824
	movs r0, 0
	str r0, [r1]
	movs r0, 0x5
	bl sub_803E46C
	movs r5, 0
_0803E7E0:
	movs r0, 0x1
	adds r1, r4, 0
	bl sub_803E874
	cmp r5, 0x1F
	bgt _0803E806
	subs r4, 0x2
	cmp r4, 0
	bgt _0803E806
	movs r4, 0
	movs r0, 0x1
	movs r1, 0
	bl sub_803EAF0
	ldr r0, _0803E828
	ldr r0, [r0]
	ldr r1, _0803E82C
	adds r0, r1
	strb r4, [r0]
_0803E806:
	movs r0, 0x5
	bl sub_803E46C
	adds r5, 0x1
	cmp r5, 0x2B
	ble _0803E7E0
	ldr r1, _0803E820
	movs r0, 0
	strb r0, [r1]
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_0803E820: .4byte gUnknown_203B40D
_0803E824: .4byte gUnknown_202EDC8
_0803E828: .4byte gUnknown_203B418
_0803E82C: .4byte 0x00018217
	thumb_func_end sub_803E7C8

	thumb_func_start sub_803E830
sub_803E830:
	push {r4,r5,lr}
	ldr r1, _0803E86C
	movs r0, 0x1
	strb r0, [r1]
	ldr r5, _0803E870
	movs r4, 0x1F
_0803E83C:
	movs r0, 0
	movs r1, 0
	bl sub_803E874
	movs r0, 0x5
	bl sub_803E46C
	ldr r0, [r5]
	cmp r0, 0
	ble _0803E854
	subs r0, 0x1
	str r0, [r5]
_0803E854:
	subs r4, 0x1
	cmp r4, 0
	bge _0803E83C
	ldr r0, _0803E870
	movs r1, 0
	str r1, [r0]
	ldr r0, _0803E86C
	strb r1, [r0]
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_0803E86C: .4byte gUnknown_203B40D
_0803E870: .4byte gUnknown_202EDC8
	thumb_func_end sub_803E830

	thumb_func_start sub_803E874
sub_803E874:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x8
	mov r9, r1
	lsls r0, 24
	lsrs r0, 24
	mov r10, r0
	ldr r0, _0803E9A4
	ldr r0, [r0]
	ldr r5, [r0, 0x4]
	ldr r1, _0803E9A8
	ldr r0, _0803E9AC
	ldr r2, [r0]
	ldr r0, _0803E9B0
	ldr r3, [r0]
	movs r0, 0xBE
	lsls r0, 1
	adds r3, r0
	movs r0, 0
	bl SetBGPaletteBufferColorRGB
	adds r5, 0x4
	movs r6, 0x1
	movs r4, 0x9F
_0803E8AA:
	ldr r1, _0803E9AC
	mov r8, r1
	ldr r2, [r1]
	ldr r7, _0803E9B0
	ldr r3, [r7]
	movs r0, 0xBE
	lsls r0, 1
	adds r3, r0
	adds r0, r6, 0
	adds r1, r5, 0
	bl SetBGPaletteBufferColorRGB
	adds r5, 0x4
	adds r6, 0x1
	subs r4, 0x1
	cmp r4, 0
	bne _0803E8AA
	ldr r3, [r7]
	ldr r1, _0803E9B4
	adds r0, r3, r1
	ldrb r0, [r0]
	cmp r0, 0
	beq _0803E8E2
	ldr r2, _0803E9B8
	adds r0, r3, r2
	ldr r0, [r0]
	cmp r0, 0x3
	bne _0803E8FC
_0803E8E2:
	ldr r1, _0803E9BC
	mov r2, r8
	ldr r0, [r2]
	str r0, [sp]
	movs r2, 0xBE
	lsls r2, 1
	adds r0, r3, r2
	str r0, [sp, 0x4]
	movs r0, 0x1
	movs r2, 0xA0
	movs r3, 0x20
	bl sub_8004AF0
_0803E8FC:
	adds r6, 0x20
	ldr r5, _0803E9C0
	movs r4, 0x20
_0803E902:
	ldr r0, _0803E9AC
	ldr r2, [r0]
	ldr r0, _0803E9B0
	ldr r3, [r0]
	movs r0, 0xBE
	lsls r0, 1
	adds r3, r0
	adds r0, r6, 0
	adds r1, r5, 0
	bl SetBGPaletteBufferColorRGB
	adds r5, 0x4
	adds r6, 0x1
	subs r4, 0x1
	cmp r4, 0
	bne _0803E902
	mov r1, r10
	cmp r1, 0
	beq _0803E948
	movs r6, 0xE0
	ldr r0, _0803E9C4
	ldr r0, [r0]
	ldr r5, [r0, 0x4]
	movs r4, 0x10
_0803E932:
	adds r0, r6, 0
	adds r1, r5, 0
	mov r2, r9
	movs r3, 0
	bl SetBGPaletteBufferColorRGB
	adds r5, 0x4
	adds r6, 0x1
	subs r4, 0x1
	cmp r4, 0
	bne _0803E932
_0803E948:
	ldr r1, _0803E9C8
	ldr r4, _0803E9AC
	ldr r2, [r4]
	movs r0, 0xF8
	movs r3, 0
	bl SetBGPaletteBufferColorRGB
	ldr r0, _0803E9B0
	ldr r0, [r0]
	ldr r2, _0803E9CC
	adds r0, r2
	ldr r0, [r0]
	ldr r5, [r0, 0x4]
	movs r6, 0x80
	lsls r6, 1
	adds r7, r4, 0
	movs r4, 0xD0
_0803E96A:
	ldr r2, [r7]
	ldr r0, _0803E9B0
	ldr r3, [r0]
	movs r0, 0xBE
	lsls r0, 1
	adds r3, r0
	adds r0, r6, 0
	adds r1, r5, 0
	bl SetBGPaletteBufferColorRGB
	ldr r2, [r7]
	adds r0, r6, 0
	adds r1, r5, 0
	movs r3, 0
	bl nullsub_4
	adds r5, 0x4
	adds r6, 0x1
	subs r4, 0x1
	cmp r4, 0
	bne _0803E96A
	add sp, 0x8
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_0803E9A4: .4byte gUnknown_202EE88
_0803E9A8: .4byte gUnknown_80F62AC
_0803E9AC: .4byte gUnknown_202EDC8
_0803E9B0: .4byte gUnknown_203B418
_0803E9B4: .4byte 0x00018215
_0803E9B8: .4byte 0x0001c06c
_0803E9BC: .4byte gUnknown_202EE8C
_0803E9C0: .4byte gUnknown_202ECA4
_0803E9C4: .4byte gDungeonNameBannerPalette
_0803E9C8: .4byte gUnknown_202D058
_0803E9CC: .4byte 0x000181e4
	thumb_func_end sub_803E874

	thumb_func_start sub_803E9D0
sub_803E9D0:
	push {r4-r7,lr}
	ldr r0, _0803EA04
	ldr r0, [r0]
	ldr r1, _0803EA08
	adds r0, r1
	ldr r0, [r0]
	ldr r4, [r0, 0x4]
	movs r6, 0x80
	lsls r6, 1
	ldr r7, _0803EA0C
	movs r5, 0xD0
_0803E9E6:
	ldr r2, [r7]
	adds r0, r6, 0
	adds r1, r4, 0
	movs r3, 0
	bl nullsub_4
	adds r4, 0x4
	adds r6, 0x1
	subs r5, 0x1
	cmp r5, 0
	bne _0803E9E6
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_0803EA04: .4byte gUnknown_203B418
_0803EA08: .4byte 0x000181e4
_0803EA0C: .4byte gUnknown_202EDC8
	thumb_func_end sub_803E9D0

	thumb_func_start sub_803EA10
sub_803EA10:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0x8
	ldr r0, _0803EACC
	ldr r0, [r0]
	ldr r4, [r0, 0x4]
	ldr r1, _0803EAD0
	ldr r0, _0803EAD4
	ldr r2, [r0]
	ldr r0, _0803EAD8
	ldr r3, [r0]
	movs r0, 0xBE
	lsls r0, 1
	adds r3, r0
	movs r0, 0
	bl SetBGPaletteBufferColorRGB
	adds r4, 0x4
	movs r6, 0x1
	movs r5, 0x9F
_0803EA3A:
	ldr r1, _0803EAD4
	mov r8, r1
	ldr r2, [r1]
	ldr r7, _0803EAD8
	ldr r3, [r7]
	movs r0, 0xBE
	lsls r0, 1
	adds r3, r0
	adds r0, r6, 0
	adds r1, r4, 0
	bl SetBGPaletteBufferColorRGB
	adds r4, 0x4
	adds r6, 0x1
	subs r5, 0x1
	cmp r5, 0
	bne _0803EA3A
	ldr r3, [r7]
	ldr r1, _0803EADC
	adds r0, r3, r1
	ldrb r0, [r0]
	cmp r0, 0
	beq _0803EA72
	ldr r2, _0803EAE0
	adds r0, r3, r2
	ldr r0, [r0]
	cmp r0, 0x3
	bne _0803EA8C
_0803EA72:
	ldr r1, _0803EAE4
	mov r2, r8
	ldr r0, [r2]
	str r0, [sp]
	movs r2, 0xBE
	lsls r2, 1
	adds r0, r3, r2
	str r0, [sp, 0x4]
	movs r0, 0x1
	movs r2, 0xA0
	movs r3, 0x20
	bl sub_8004AF0
_0803EA8C:
	adds r6, 0x20
	ldr r4, _0803EAE8
	movs r5, 0x20
_0803EA92:
	ldr r7, _0803EAD4
	ldr r2, [r7]
	ldr r0, _0803EAD8
	ldr r3, [r0]
	movs r0, 0xBE
	lsls r0, 1
	adds r3, r0
	adds r0, r6, 0
	adds r1, r4, 0
	bl SetBGPaletteBufferColorRGB
	adds r4, 0x4
	adds r6, 0x1
	subs r5, 0x1
	cmp r5, 0
	bne _0803EA92
	ldr r1, _0803EAEC
	ldr r2, [r7]
	movs r0, 0xF8
	movs r3, 0
	bl SetBGPaletteBufferColorRGB
	add sp, 0x8
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_0803EACC: .4byte gUnknown_202EE88
_0803EAD0: .4byte gUnknown_80F62AC
_0803EAD4: .4byte gUnknown_202EDC8
_0803EAD8: .4byte gUnknown_203B418
_0803EADC: .4byte 0x00018215
_0803EAE0: .4byte 0x0001c06c
_0803EAE4: .4byte gUnknown_202EE8C
_0803EAE8: .4byte gUnknown_202ECA4
_0803EAEC: .4byte gUnknown_202D058
	thumb_func_end sub_803EA10

	thumb_func_start sub_803EAF0
sub_803EAF0:
	push {r4,r5,lr}
	adds r4, r0, 0
	adds r5, r1, 0
	ldr r0, _0803EB20
	ldr r0, [r0]
	cmp r4, r0
	bne _0803EB00
	b _0803EC88
_0803EB00:
	cmp r4, 0x5
	bne _0803EB06
	b _0803EC1C
_0803EB06:
	cmp r4, 0x5
	bhi _0803EB2E
	cmp r4, 0x2
	bne _0803EB10
	b _0803EBFC
_0803EB10:
	cmp r4, 0x2
	bhi _0803EB24
	cmp r4, 0
	beq _0803EB70
	cmp r4, 0x1
	beq _0803EB50
	b _0803EC84
	.align 2, 0
_0803EB20: .4byte gUnknown_202EDD0
_0803EB24:
	cmp r4, 0x3
	beq _0803EB98
	cmp r4, 0x4
	beq _0803EBFC
	b _0803EC84
_0803EB2E:
	cmp r4, 0x8
	bne _0803EB34
	b _0803EC34
_0803EB34:
	cmp r4, 0x8
	bhi _0803EB42
	cmp r4, 0x6
	beq _0803EBBC
	cmp r4, 0x7
	beq _0803EBDC
	b _0803EC84
_0803EB42:
	cmp r4, 0xA
	bne _0803EB48
	b _0803EC80
_0803EB48:
	cmp r4, 0xA
	bcs _0803EB4E
	b _0803EC54
_0803EB4E:
	b _0803EC84
_0803EB50:
	ldr r0, _0803EB6C
	ldrb r0, [r0]
	cmp r0, 0
	beq _0803EB5E
	movs r0, 0
	bl sub_8052210
_0803EB5E:
	bl sub_8004914
	bl sub_803EC94
	movs r0, 0
	movs r1, 0x1
	b _0803EC6E
	.align 2, 0
_0803EB6C: .4byte gUnknown_203B40C
_0803EB70:
	bl sub_803EC94
	movs r0, 0
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	ldr r0, _0803EB94
	ldrb r0, [r0]
	cmp r0, 0
	bne _0803EB88
	b _0803EC84
_0803EB88:
	bl sub_8040A84
	movs r0, 0
	bl sub_8040ABC
	b _0803EC84
	.align 2, 0
_0803EB94: .4byte gUnknown_203B40C
_0803EB98:
	ldr r0, _0803EBB4
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	ldr r0, _0803EBB8
	ldrb r0, [r0]
	cmp r0, 0
	beq _0803EC84
	movs r0, 0x1
	bl sub_8040ABC
	b _0803EC84
	.align 2, 0
_0803EBB4: .4byte gUnknown_80F62B0
_0803EBB8: .4byte gUnknown_203B40C
_0803EBBC:
	ldr r0, _0803EBD4
	ldrb r0, [r0]
	cmp r0, 0
	beq _0803EBCA
	movs r0, 0
	bl sub_8052210
_0803EBCA:
	bl sub_8004914
	ldr r0, _0803EBD8
	movs r1, 0x1
	b _0803EC6E
	.align 2, 0
_0803EBD4: .4byte gUnknown_203B40C
_0803EBD8: .4byte gUnknown_80F6310
_0803EBDC:
	ldr r0, _0803EBF4
	ldrb r0, [r0]
	cmp r0, 0
	beq _0803EBEA
	movs r0, 0
	bl sub_8052210
_0803EBEA:
	bl sub_8004914
	ldr r0, _0803EBF8
	movs r1, 0x1
	b _0803EC6E
	.align 2, 0
_0803EBF4: .4byte gUnknown_203B40C
_0803EBF8: .4byte gUnknown_80F6370
_0803EBFC:
	ldr r0, _0803EC18
	ldrb r0, [r0]
	cmp r0, 0
	beq _0803EC0A
	movs r0, 0
	bl sub_8052210
_0803EC0A:
	bl sub_8004914
	bl sub_803EC94
	movs r0, 0
	movs r1, 0x1
	b _0803EC6E
	.align 2, 0
_0803EC18: .4byte gUnknown_203B40C
_0803EC1C:
	ldr r0, _0803EC30
	ldrb r0, [r0]
	cmp r0, 0
	beq _0803EC2A
	movs r0, 0
	bl sub_8052210
_0803EC2A:
	movs r0, 0
	movs r1, 0x1
	b _0803EC6E
	.align 2, 0
_0803EC30: .4byte gUnknown_203B40C
_0803EC34:
	ldr r0, _0803EC50
	ldrb r0, [r0]
	cmp r0, 0
	beq _0803EC46
	bl sub_8083D44
	movs r0, 0
	bl sub_8052210
_0803EC46:
	movs r0, 0x2
	adds r1, r5, 0
	bl sub_801602C
	b _0803EC84
	.align 2, 0
_0803EC50: .4byte gUnknown_203B40C
_0803EC54:
	ldr r0, _0803EC78
	ldrb r0, [r0]
	cmp r0, 0
	beq _0803EC66
	movs r0, 0
	bl sub_8052210
	bl sub_8083D44
_0803EC66:
	bl sub_8004914
	ldr r0, _0803EC7C
	movs r1, 0
_0803EC6E:
	movs r2, 0x1
	bl sub_800641C
	b _0803EC84
	.align 2, 0
_0803EC78: .4byte gUnknown_203B40C
_0803EC7C: .4byte gUnknown_80F63D0
_0803EC80:
	bl sub_8083D44
_0803EC84:
	ldr r0, _0803EC90
	str r4, [r0]
_0803EC88:
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_0803EC90: .4byte gUnknown_202EDD0
	thumb_func_end sub_803EAF0

	thumb_func_start sub_803EC94
sub_803EC94:
	push {lr}
	ldr r0, _0803ECB0
	movs r1, 0
	strh r1, [r0, 0x1E]
	strh r1, [r0, 0x20]
	strh r1, [r0, 0xC]
	strh r1, [r0, 0xE]
	strh r1, [r0, 0x14]
	adds r0, 0x28
	bl sub_801317C
	pop {r0}
	bx r0
	.align 2, 0
_0803ECB0: .4byte gUnknown_202EE10
	thumb_func_end sub_803EC94

	thumb_func_start sub_803ECB4
sub_803ECB4:
	push {r4,r5,lr}
	adds r5, r0, 0
	lsls r4, r1, 24
	lsrs r4, 24
	ldr r1, _0803ECDC
	movs r0, 0xA
	str r0, [r1]
	movs r0, 0
	bl sub_8052210
	bl sub_8004914
	adds r0, r5, 0
	movs r1, 0x1
	adds r2, r4, 0
	bl sub_800641C
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_0803ECDC: .4byte gUnknown_202EDD0
	thumb_func_end sub_803ECB4

	thumb_func_start sub_803ECE0
sub_803ECE0:
	push {lr}
	ldr r1, _0803ED24
	ldr r0, [r1]
	adds r0, 0x1
	str r0, [r1]
	cmp r0, 0
	bge _0803ECF2
	movs r0, 0
	str r0, [r1]
_0803ECF2:
	ldr r0, [r1]
	cmp r0, 0xB
	ble _0803ECFC
	movs r0, 0
	str r0, [r1]
_0803ECFC:
	ldr r0, _0803ED28
	ldr r2, [r0]
	ldr r0, [r1]
	cmp r0, 0
	bge _0803ED08
	adds r0, 0x3
_0803ED08:
	asrs r1, r0, 2
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 6
	ldr r1, [r2, 0x4]
	adds r1, r0
	movs r2, 0x90
	lsls r2, 2
	ldr r0, _0803ED2C
	bl sub_80098BC
	pop {r0}
	bx r0
	.align 2, 0
_0803ED24: .4byte gUnknown_202EDD8
_0803ED28: .4byte gUnknown_202EC94
_0803ED2C: .4byte 0x06014400
	thumb_func_end sub_803ECE0

	thumb_func_start sub_803ED30
sub_803ED30:
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	adds r5, r0, 0
	adds r7, r1, 0
	mov r9, r3
	lsls r2, 24
	lsrs r2, 24
	mov r8, r2
	cmp r5, 0
	beq _0803EDDA
	ldr r0, _0803EDAC
	ldr r0, [r0]
	ldr r1, _0803EDB0
	adds r0, r1
	ldrb r0, [r0]
	cmp r0, 0
	bne _0803EDDA
	movs r4, 0
	ldr r1, _0803EDB4
	movs r2, 0
	ldrsh r0, [r1, r2]
	cmp r0, 0
	beq _0803ED78
	adds r6, r1, 0
_0803ED64:
	movs r0, 0x29
	bl sub_803E46C
	adds r4, 0x1
	cmp r4, 0x13
	bgt _0803ED78
	movs r1, 0
	ldrsh r0, [r6, r1]
	cmp r0, 0
	bne _0803ED64
_0803ED78:
	adds r0, r5, 0
	mov r1, r8
	bl sub_803EF90
	ldr r3, _0803EDB4
	movs r2, 0
	movs r1, 0x3C
	strh r1, [r3]
	str r7, [r3, 0x4]
	ldrh r1, [r7, 0x26]
	str r1, [r3, 0x8]
	lsls r1, r0, 1
	adds r1, r0
	lsls r1, 8
	negs r1, r1
	str r1, [r3, 0xC]
	str r2, [r3, 0x10]
	mov r2, r9
	cmp r2, 0
	bge _0803EDC8
	ldr r0, _0803EDB8
	cmp r5, r0
	bge _0803EDBC
	movs r0, 0x6
	b _0803EDCA
	.align 2, 0
_0803EDAC: .4byte gUnknown_203B418
_0803EDB0: .4byte 0x0001820a
_0803EDB4: .4byte gUnknown_202EDE8
_0803EDB8: .4byte 0xfffffc19
_0803EDBC:
	cmp r5, 0
	blt _0803EDC4
	movs r0, 0xA
	b _0803EDCA
_0803EDC4:
	movs r0, 0x3
	b _0803EDCA
_0803EDC8:
	mov r0, r9
_0803EDCA:
	strh r0, [r3, 0x2]
	ldr r0, _0803EDE8
	ldr r1, _0803EDEC
	ldr r1, [r1]
	adds r1, 0x18
	movs r2, 0x80
	bl sub_80098BC
_0803EDDA:
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_0803EDE8: .4byte 0x060142c0
_0803EDEC: .4byte gUnknown_203B418
	thumb_func_end sub_803ED30

	thumb_func_start sub_803EDF0
sub_803EDF0:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	ldr r6, _0803EE18
	movs r1, 0
	ldrsh r0, [r6, r1]
	cmp r0, 0
	bne _0803EE06
	b _0803EF42
_0803EE06:
	ldr r0, [r6, 0x4]
	bl sub_80450E0
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0
	bne _0803EE1C
	strh r0, [r6]
	b _0803EF42
	.align 2, 0
_0803EE18: .4byte gUnknown_202EDE8
_0803EE1C:
	ldr r1, [r6, 0x4]
	ldr r0, [r6, 0x8]
	ldrh r2, [r1, 0x26]
	cmp r0, r2
	beq _0803EE2C
	movs r0, 0
	strh r0, [r6]
	b _0803EF42
_0803EE2C:
	ldrh r0, [r6]
	subs r0, 0x1
	strh r0, [r6]
	ldr r4, [r6, 0x10]
	adds r3, r4, 0
	subs r3, 0x2E
	str r3, [r6, 0x10]
	ldr r2, [r1, 0x70]
	movs r5, 0xB8
	lsls r5, 1
	adds r0, r2, r5
	movs r1, 0
	ldrsh r0, [r0, r1]
	ldr r1, [r6, 0xC]
	cmp r1, 0
	bge _0803EE4E
	adds r1, 0xFF
_0803EE4E:
	asrs r1, 8
	adds r1, r0, r1
	ldr r0, _0803EF50
	ldr r0, [r0]
	mov r12, r0
	ldr r0, _0803EF54
	add r0, r12
	movs r5, 0
	ldrsh r0, [r0, r5]
	subs r7, r1, r0
	movs r1, 0xB9
	lsls r1, 1
	adds r0, r2, r1
	movs r2, 0
	ldrsh r0, [r0, r2]
	adds r1, r3, 0
	cmp r1, 0
	bge _0803EE76
	adds r1, r4, 0
	adds r1, 0xD1
_0803EE76:
	asrs r1, 8
	adds r1, r0, r1
	ldr r0, _0803EF58
	add r0, r12
	movs r3, 0
	ldrsh r0, [r0, r3]
	adds r0, 0x18
	subs r2, r1, r0
	movs r0, 0x20
	negs r0, r0
	cmp r7, r0
	blt _0803EF42
	adds r0, 0x18
	cmp r2, r0
	blt _0803EF42
	cmp r7, 0xEF
	bgt _0803EF42
	cmp r2, 0x9F
	bgt _0803EF42
	ldr r1, _0803EF5C
	ands r1, r2
	lsls r1, 4
	ldr r0, _0803EF60
	ldrh r2, [r0, 0x6]
	movs r4, 0xF
	mov r8, r4
	mov r3, r8
	ands r3, r2
	orrs r3, r1
	strh r3, [r0, 0x6]
	ldrh r2, [r0]
	ldr r1, _0803EF64
	ands r1, r2
	ldr r2, _0803EF68
	ands r1, r2
	movs r5, 0x3
	mov r9, r5
	ldr r2, _0803EF6C
	mov r10, r2
	ands r1, r2
	ldr r2, _0803EF70
	ands r1, r2
	ldr r2, _0803EF74
	ands r1, r2
	movs r5, 0x80
	lsls r5, 7
	ldr r4, _0803EF78
	ands r1, r4
	orrs r1, r5
	strh r1, [r0]
	ldr r1, _0803EF7C
	ands r7, r1
	ldrh r2, [r0, 0x2]
	movs r1, 0xFE
	lsls r1, 8
	ands r1, r2
	orrs r1, r7
	ldr r2, _0803EF80
	ands r1, r2
	ands r1, r4
	orrs r1, r5
	strh r1, [r0, 0x2]
	ldr r4, _0803EF84
	ldrh r2, [r0, 0x4]
	movs r1, 0xFC
	lsls r1, 8
	ands r1, r2
	orrs r1, r4
	movs r2, 0
	orrs r1, r2
	strh r1, [r0, 0x4]
	ldr r2, _0803EF88
	add r2, r12
	ldrb r2, [r2]
	mov r4, r9
	ands r2, r4
	lsls r2, 10
	mov r5, r10
	ands r1, r5
	orrs r1, r2
	movs r4, 0x2
	ldrsh r2, [r6, r4]
	mov r5, r8
	ands r2, r5
	lsls r2, 12
	ldr r4, _0803EF5C
	ands r1, r4
	orrs r1, r2
	strh r1, [r0, 0x4]
	ldr r1, _0803EF8C
	ands r3, r1
	subs r1, 0x1
	ands r3, r1
	subs r1, 0x2
	ands r3, r1
	strh r3, [r0, 0x6]
	movs r1, 0x80
	lsls r1, 1
	movs r2, 0
	movs r3, 0
	bl AddSprite
_0803EF42:
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_0803EF50: .4byte gUnknown_203B418
_0803EF54: .4byte 0x000181f0
_0803EF58: .4byte 0x000181f2
_0803EF5C: .4byte 0x00000fff
_0803EF60: .4byte gUnknown_202EDDC
_0803EF64: .4byte 0x0000feff
_0803EF68: .4byte 0x0000fdff
_0803EF6C: .4byte 0x0000f3ff
_0803EF70: .4byte 0x0000efff
_0803EF74: .4byte 0x0000dfff
_0803EF78: .4byte 0x00003fff
_0803EF7C: .4byte 0x000001ff
_0803EF80: .4byte 0x0000c1ff
_0803EF84: .4byte 0x00000216
_0803EF88: .4byte 0x00018208
_0803EF8C: .4byte 0x0000fffe
	thumb_func_end sub_803EDF0

	thumb_func_start sub_803EF90
sub_803EF90:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x58
	str r0, [sp, 0x48]
	lsls r1, 24
	lsrs r5, r1, 24
	ldr r0, _0803F060
	ldr r0, [r0]
	adds r0, 0x18
	mov r8, r0
	ldr r0, _0803F064
	ldr r1, [r0]
	ldr r0, [r1, 0x4]
	movs r2, 0x92
	lsls r2, 1
	adds r0, r2
	str r0, [sp, 0x24]
	ldr r0, [r1, 0x4]
	movs r3, 0x82
	lsls r3, 1
	adds r0, r3
	str r0, [sp, 0x28]
	ldr r0, [r1, 0x4]
	adds r0, 0xE4
	str r0, [sp, 0x2C]
	ldr r0, [r1, 0x4]
	adds r0, 0xC4
	str r0, [sp, 0x30]
	ldr r0, [r1, 0x4]
	adds r0, 0xA4
	str r0, [sp, 0x34]
	ldr r0, [r1, 0x4]
	adds r0, 0x84
	str r0, [sp, 0x38]
	ldr r0, [r1, 0x4]
	adds r0, 0x64
	str r0, [sp, 0x3C]
	ldr r0, [r1, 0x4]
	adds r0, 0x44
	str r0, [sp, 0x40]
	ldr r0, [r1, 0x4]
	adds r0, 0x24
	str r0, [sp, 0x44]
	add r4, sp, 0x24
	mov r0, sp
	adds r1, r4, 0
	movs r2, 0x24
	bl memcpy
	movs r1, 0
	movs r6, 0x3
	mov r0, r8
_0803EFFE:
	stm r0!, {r1}
	stm r0!, {r1}
	stm r0!, {r1}
	stm r0!, {r1}
	stm r0!, {r1}
	stm r0!, {r1}
	stm r0!, {r1}
	stm r0!, {r1}
	subs r6, 0x1
	cmp r6, 0
	bge _0803EFFE
	ldr r0, _0803F068
	ldr r1, [sp, 0x48]
	cmp r1, r0
	bne _0803F0A6
	adds r0, r4, 0
	ldr r1, _0803F06C
	ldm r1!, {r2,r3,r5}
	stm r0!, {r2,r3,r5}
	ldr r1, [r1]
	str r1, [r0]
	movs r5, 0
	movs r2, 0
	mov r12, r4
	movs r0, 0x20
	mov r10, r0
_0803F032:
	mov r3, r8
	ldr r0, _0803F064
	ldr r1, [r0]
	lsls r0, r2, 2
	add r0, r12
	ldr r0, [r0]
	lsls r0, 5
	adds r0, 0x4
	ldr r1, [r1, 0x4]
	adds r4, r1, r0
	movs r1, 0x18
	adds r1, r5
	mov r9, r1
	adds r2, 0x1
	str r2, [sp, 0x54]
	mov r2, r10
	subs r7, r2, r5
	movs r6, 0x7
_0803F056:
	cmp r5, 0
	bne _0803F070
	movs r1, 0
	ldr r2, [r4]
	b _0803F07A
	.align 2, 0
_0803F060: .4byte gUnknown_203B418
_0803F064: .4byte gUnknown_202EC9C
_0803F068: .4byte 0x0000270f
_0803F06C: .4byte gUnknown_80F6478
_0803F070:
	ldr r0, [r4]
	adds r1, r0, 0
	lsrs r1, r7
	adds r2, r0, 0
	lsls r2, r5
_0803F07A:
	adds r4, 0x4
	ldr r0, [r3]
	orrs r0, r2
	str r0, [r3]
	ldr r0, [r3, 0x20]
	orrs r0, r1
	str r0, [r3, 0x20]
	adds r3, 0x4
	subs r6, 0x1
	cmp r6, 0
	bge _0803F056
	mov r5, r9
	cmp r5, 0x1F
	ble _0803F09C
	subs r5, 0x20
	movs r3, 0x20
	add r8, r3
_0803F09C:
	ldr r2, [sp, 0x54]
	cmp r2, 0x3
	ble _0803F032
	movs r0, 0x4
	b _0803F26A
_0803F0A6:
	ldr r0, _0803F0D8
	ldr r1, [sp, 0x48]
	cmp r1, r0
	ble _0803F0B0
	str r0, [sp, 0x48]
_0803F0B0:
	ldr r0, _0803F0DC
	ldr r2, [sp, 0x48]
	cmp r2, r0
	bge _0803F0BA
	str r0, [sp, 0x48]
_0803F0BA:
	ldr r1, _0803F0E0
	ldr r0, [r1]
	ldr r0, [r0, 0x4]
	movs r3, 0xC2
	lsls r3, 1
	adds r2, r0, r3
	cmp r5, 0
	beq _0803F0F4
	ldr r5, [sp, 0x48]
	cmp r5, 0
	ble _0803F0E4
	movs r1, 0xA2
	lsls r1, 1
	adds r2, r0, r1
	b _0803F0F4
	.align 2, 0
_0803F0D8: .4byte 0x000003e7
_0803F0DC: .4byte 0xfffffc19
_0803F0E0: .4byte gUnknown_202EC9C
_0803F0E4:
	ldr r3, [sp, 0x48]
	cmp r3, 0
	bge _0803F0F4
	movs r5, 0xB2
	lsls r5, 1
	adds r2, r0, r5
	negs r3, r3
	str r3, [sp, 0x48]
_0803F0F4:
	ldm r2!, {r0}
	mov r1, r8
	str r0, [r1]
	ldm r2!, {r0}
	str r0, [r1, 0x4]
	ldm r2!, {r0}
	str r0, [r1, 0x8]
	ldm r2!, {r0}
	str r0, [r1, 0xC]
	ldm r2!, {r0}
	str r0, [r1, 0x10]
	ldm r2!, {r0}
	str r0, [r1, 0x14]
	ldm r2!, {r0}
	str r0, [r1, 0x18]
	ldr r0, [r2]
	str r0, [r1, 0x1C]
	movs r5, 0x18
	movs r2, 0x1
	str r2, [sp, 0x4C]
	movs r3, 0
	str r3, [sp, 0x50]
	movs r2, 0
_0803F122:
	movs r0, 0
	mov r10, r0
	adds r1, r2, 0x1
	str r1, [sp, 0x54]
	lsls r0, r2, 3
	adds r0, r2
	lsls r0, 2
	mov r1, sp
	ldr r2, _0803F15C
	adds r7, r0, r2
_0803F136:
	ldr r0, [r7]
	ldr r3, [sp, 0x48]
	cmp r0, r3
	bgt _0803F1A2
	ldr r4, [r1]
	mov r2, r8
	movs r0, 0x18
	adds r0, r5
	mov r9, r0
	movs r1, 0x20
	subs r1, r5
	mov r12, r1
	movs r6, 0x7
_0803F150:
	cmp r5, 0
	bne _0803F160
	movs r3, 0
	ldr r1, [r4]
	b _0803F16C
	.align 2, 0
_0803F15C: .4byte gUnknown_80F6430
_0803F160:
	ldr r0, [r4]
	adds r3, r0, 0
	mov r1, r12
	lsrs r3, r1
	adds r1, r0, 0
	lsls r1, r5
_0803F16C:
	adds r4, 0x4
	ldr r0, [r2]
	orrs r0, r1
	str r0, [r2]
	ldr r0, [r2, 0x20]
	orrs r0, r3
	str r0, [r2, 0x20]
	adds r2, 0x4
	movs r3, 0x1
	str r3, [sp, 0x50]
	subs r6, 0x1
	cmp r6, 0
	bge _0803F150
	mov r5, r9
	cmp r5, 0x1F
	ble _0803F192
	subs r5, 0x20
	movs r0, 0x20
	add r8, r0
_0803F192:
	ldr r0, [r7]
	ldr r1, [sp, 0x48]
	subs r1, r0
	str r1, [sp, 0x48]
	ldr r2, [sp, 0x4C]
	adds r2, 0x1
	str r2, [sp, 0x4C]
	b _0803F1B0
_0803F1A2:
	adds r1, 0x4
	adds r7, 0x4
	movs r3, 0x1
	add r10, r3
	mov r0, r10
	cmp r0, 0x8
	ble _0803F136
_0803F1B0:
	mov r1, r10
	cmp r1, 0x9
	bne _0803F212
	ldr r2, [sp, 0x50]
	cmp r2, 0
	beq _0803F212
	ldr r3, _0803F1DC
	ldr r0, [r3]
	ldr r0, [r0, 0x4]
	adds r4, r0, 0x4
	mov r2, r8
	movs r0, 0x18
	adds r0, r5
	mov r9, r0
	movs r1, 0x20
	subs r7, r1, r5
	movs r6, 0x7
_0803F1D2:
	cmp r5, 0
	bne _0803F1E0
	movs r3, 0
	ldr r1, [r4]
	b _0803F1EA
	.align 2, 0
_0803F1DC: .4byte gUnknown_202EC9C
_0803F1E0:
	ldr r0, [r4]
	adds r3, r0, 0
	lsrs r3, r7
	adds r1, r0, 0
	lsls r1, r5
_0803F1EA:
	adds r4, 0x4
	ldr r0, [r2]
	orrs r0, r1
	str r0, [r2]
	ldr r0, [r2, 0x20]
	orrs r0, r3
	str r0, [r2, 0x20]
	adds r2, 0x4
	subs r6, 0x1
	cmp r6, 0
	bge _0803F1D2
	mov r5, r9
	cmp r5, 0x1F
	ble _0803F20C
	subs r5, 0x20
	movs r2, 0x20
	add r8, r2
_0803F20C:
	ldr r3, [sp, 0x4C]
	adds r3, 0x1
	str r3, [sp, 0x4C]
_0803F212:
	ldr r2, [sp, 0x54]
	cmp r2, 0x1
	ble _0803F122
	ldr r0, _0803F240
	ldr r1, [r0]
	ldr r2, [sp, 0x48]
	lsls r0, r2, 5
	adds r0, 0x4
	ldr r1, [r1, 0x4]
	adds r1, r0
	mov r3, r8
	ldr r0, [sp, 0x4C]
	adds r0, 0x1
	mov r8, r0
	movs r0, 0x20
	subs r7, r0, r5
	movs r6, 0x7
_0803F234:
	cmp r5, 0
	bne _0803F244
	movs r4, 0
	ldr r2, [r1]
	b _0803F24E
	.align 2, 0
_0803F240: .4byte gUnknown_202EC9C
_0803F244:
	ldr r0, [r1]
	adds r4, r0, 0
	lsrs r4, r7
	adds r2, r0, 0
	lsls r2, r5
_0803F24E:
	adds r1, 0x4
	ldr r0, [r3]
	orrs r0, r2
	str r0, [r3]
	ldr r0, [r3, 0x20]
	orrs r0, r4
	str r0, [r3, 0x20]
	adds r3, 0x4
	subs r6, 0x1
	cmp r6, 0
	bge _0803F234
	mov r1, r8
	str r1, [sp, 0x4C]
	adds r0, r1, 0
_0803F26A:
	add sp, 0x58
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_803EF90

	thumb_func_start sub_803F27C
sub_803F27C:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	lsls r0, 24
	lsrs r0, 24
	adds r7, r0, 0
	ldr r0, _0803F360
	mov r8, r0
	ldr r4, [r0]
	ldr r2, _0803F364
	adds r1, r4, r2
	movs r2, 0
	movs r3, 0
	strh r3, [r1, 0x8]
	strh r3, [r1, 0xA]
	strh r3, [r1]
	strh r3, [r1, 0x2]
	strh r3, [r1, 0xC]
	strh r3, [r1, 0xE]
	strh r3, [r1, 0x4]
	strh r3, [r1, 0x6]
	str r3, [r1, 0x14]
	ldr r5, _0803F368
	adds r0, r4, r5
	strb r2, [r0]
	ldr r6, _0803F36C
	adds r0, r4, r6
	movs r5, 0x1
	strb r5, [r0]
	adds r6, 0x1
	adds r0, r4, r6
	strb r5, [r0]
	adds r6, 0x1
	adds r0, r4, r6
	strb r2, [r0]
	str r3, [r1, 0x18]
	str r3, [r1, 0x1C]
	cmp r7, 0
	bne _0803F2FA
	subs r6, 0xF
	adds r0, r4, r6
	strb r2, [r0]
	adds r6, 0x6
	adds r0, r4, r6
	strb r2, [r0]
	subs r6, 0x1
	adds r0, r4, r6
	strb r2, [r0]
	subs r6, 0x2
	adds r0, r4, r6
	strb r2, [r0]
	adds r6, 0x4
	adds r0, r4, r6
	strb r2, [r0]
	subs r6, 0x3
	adds r0, r4, r6
	strb r2, [r0]
	subs r6, 0x3
	adds r0, r4, r6
	strb r2, [r0]
	adds r6, 0x1
	adds r0, r4, r6
	strb r2, [r0]
_0803F2FA:
	str r3, [r1, 0x10]
	ldr r1, _0803F370
	adds r0, r4, r1
	movs r6, 0x3
	strb r6, [r0]
	adds r1, 0x12
	adds r0, r4, r1
	strb r2, [r0]
	subs r1, 0x8
	adds r0, r4, r1
	strb r2, [r0]
	adds r1, 0x9
	adds r0, r4, r1
	strb r2, [r0]
	adds r1, 0x1
	adds r0, r4, r1
	strb r2, [r0]
	subs r1, 0x8
	adds r0, r4, r1
	strb r2, [r0]
	ldr r2, _0803F374
	adds r0, r4, r2
	strb r5, [r0]
	bl sub_803F38C
	ldr r1, _0803F378
	ldr r0, _0803F37C
	str r0, [r1]
	cmp r7, 0
	bne _0803F354
	mov r1, r8
	ldr r0, [r1]
	ldr r2, _0803F380
	adds r0, r2
	ldrb r1, [r0]
	adds r0, r6, 0
	ands r0, r1
	ldr r6, _0803F384
	adds r1, r4, r6
	strb r0, [r1]
	cmp r0, 0
	bne _0803F354
	ldr r1, _0803F388
	adds r0, r4, r1
	strb r5, [r0]
_0803F354:
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_0803F360: .4byte gUnknown_203B418
_0803F364: .4byte 0x000181e8
_0803F368: .4byte 0x00018216
_0803F36C: .4byte 0x00018217
_0803F370: .4byte 0x00018208
_0803F374: .4byte 0x00018215
_0803F378: .4byte gUnknown_202EDFC
_0803F37C: .4byte 0x0000ffff
_0803F380: .4byte 0x0001c58a
_0803F384: .4byte 0x00018209
_0803F388: .4byte 0x0001820c
	thumb_func_end sub_803F27C

	thumb_func_start sub_803F38C
sub_803F38C:
	push {r4-r6,lr}
	mov r6, r8
	push {r6}
	ldr r0, _0803F410
	ldr r1, [r0]
	ldr r0, _0803F414
	adds r2, r1, r0
	ldr r0, _0803F418
	strh r0, [r2, 0x3A]
	movs r0, 0x1
	negs r0, r0
	strh r0, [r2, 0x3C]
	strh r0, [r2, 0x3E]
	ldr r0, _0803F41C
	adds r1, r0
	movs r0, 0x1
	negs r0, r0
	strh r0, [r1]
	strh r0, [r2, 0x36]
	strh r0, [r2, 0x38]
	ldr r0, _0803F420
	ldr r0, [r0]
	ldrb r0, [r0, 0xB]
	negs r4, r0
	orrs r4, r0
	asrs r4, 31
	movs r0, 0x80
	lsls r0, 1
	ands r4, r0
	ldr r5, _0803F424
	adds r0, r4, r5
	mov r8, r0
	movs r0, 0xFD
	mov r1, r8
	bl SetBGPaletteBufferColorArray
	adds r6, r5, 0x4
	adds r6, r4, r6
	movs r0, 0xFE
	adds r1, r6, 0
	bl SetBGPaletteBufferColorArray
	adds r5, 0x8
	adds r4, r5
	movs r0, 0xFF
	adds r1, r4, 0
	bl SetBGPaletteBufferColorArray
	movs r0, 0xFD
	mov r1, r8
	bl nullsub_5
	movs r0, 0xFE
	adds r1, r6, 0
	bl nullsub_5
	movs r0, 0xFF
	adds r1, r4, 0
	bl nullsub_5
	pop {r3}
	mov r8, r3
	pop {r4-r6}
	pop {r0}
	bx r0
	.align 2, 0
_0803F410: .4byte gUnknown_203B418
_0803F414: .4byte 0x000181e8
_0803F418: .4byte 0x0000ffff
_0803F41C: .4byte 0x00018228
_0803F420: .4byte gUnknown_203B46C
_0803F424: .4byte gUnknown_202D06C
	thumb_func_end sub_803F38C

	thumb_func_start sub_803F428
sub_803F428:
	push {r4-r6,lr}
	adds r4, r0, 0
	ldr r0, _0803F484
	ldr r3, [r0]
	ldr r0, _0803F488
	adds r2, r3, r0
	ldr r5, [r2, 0x10]
	movs r6, 0
	ldrsh r1, [r2, r6]
	movs r6, 0
	ldrsh r0, [r4, r6]
	subs r1, r0
	cmp r1, 0
	bge _0803F446
	negs r1, r1
_0803F446:
	cmp r1, 0x6
	bgt _0803F498
	movs r0, 0x2
	ldrsh r1, [r2, r0]
	movs r6, 0x2
	ldrsh r0, [r4, r6]
	subs r1, r0
	cmp r1, 0
	bge _0803F45A
	negs r1, r1
_0803F45A:
	cmp r1, 0x5
	bgt _0803F498
	ldr r1, _0803F48C
	adds r0, r3, r1
	ldrb r0, [r0]
	cmp r0, 0
	bne _0803F494
	ldr r6, _0803F490
	adds r0, r3, r6
	ldrb r0, [r0]
	cmp r0, 0
	bne _0803F494
	cmp r5, 0
	beq _0803F494
	adds r0, r2, 0
	adds r1, r4, 0
	bl sub_8083294
	lsls r0, 24
	lsrs r0, 24
	b _0803F49A
	.align 2, 0
_0803F484: .4byte gUnknown_203B418
_0803F488: .4byte 0x000181e8
_0803F48C: .4byte 0x0001820b
_0803F490: .4byte 0x0001820c
_0803F494:
	movs r0, 0x1
	b _0803F49A
_0803F498:
	movs r0, 0
_0803F49A:
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end sub_803F428

	thumb_func_start sub_803F4A0
sub_803F4A0:
	push {lr}
	adds r2, r0, 0
	ldr r0, _0803F4B8
	ldr r1, [r0]
	ldr r3, _0803F4BC
	adds r0, r1, r3
	str r2, [r0, 0x10]
	cmp r2, 0
	bne _0803F4C0
	adds r3, 0x2E
	b _0803F4CA
	.align 2, 0
_0803F4B8: .4byte gUnknown_203B418
_0803F4BC: .4byte 0x000181e8
_0803F4C0:
	ldr r0, [r2, 0x70]
	ldrb r2, [r0, 0x7]
	cmp r2, 0
	bne _0803F4D4
	ldr r3, _0803F4D0
_0803F4CA:
	adds r0, r1, r3
	strb r2, [r0]
	b _0803F4DC
	.align 2, 0
_0803F4D0: .4byte 0x00018216
_0803F4D4:
	ldr r0, _0803F4FC
	adds r1, r0
	movs r0, 0x1
	strb r0, [r1]
_0803F4DC:
	movs r0, 0
	bl sub_803F580
	bl sub_803F38C
	ldr r0, _0803F500
	ldr r0, [r0]
	ldr r1, _0803F504
	adds r0, r1
	ldrb r0, [r0]
	cmp r0, 0
	bne _0803F4F8
	bl sub_806CD90
_0803F4F8:
	pop {r0}
	bx r0
	.align 2, 0
_0803F4FC: .4byte 0x00018216
_0803F500: .4byte gUnknown_203B418
_0803F504: .4byte 0x0001356c
	thumb_func_end sub_803F4A0

	thumb_func_start sub_803F508
sub_803F508:
	push {r4,r5,lr}
	adds r3, r0, 0
	ldr r0, _0803F520
	ldr r1, [r0]
	ldr r0, _0803F524
	adds r4, r1, r0
	cmp r3, 0
	bne _0803F52C
	ldr r2, _0803F528
	adds r0, r1, r2
	strb r3, [r0]
	b _0803F548
	.align 2, 0
_0803F520: .4byte gUnknown_203B418
_0803F524: .4byte 0x000181e8
_0803F528: .4byte 0x00018216
_0803F52C:
	ldr r0, [r3, 0x70]
	ldrb r2, [r0, 0x7]
	cmp r2, 0
	bne _0803F540
	ldr r5, _0803F53C
	adds r0, r1, r5
	strb r2, [r0]
	b _0803F548
	.align 2, 0
_0803F53C: .4byte 0x00018216
_0803F540:
	ldr r0, _0803F574
	adds r1, r0
	movs r0, 0x1
	strb r0, [r1]
_0803F548:
	str r3, [r4, 0x10]
	movs r0, 0
	bl sub_803F580
	bl sub_803F38C
	ldr r0, _0803F578
	ldr r0, [r0]
	ldr r1, _0803F57C
	adds r0, r1
	ldrb r0, [r0]
	cmp r0, 0
	bne _0803F566
	bl sub_806CD90
_0803F566:
	bl sub_8049ED4
	bl sub_8040A84
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_0803F574: .4byte 0x00018216
_0803F578: .4byte gUnknown_203B418
_0803F57C: .4byte 0x0001356c
	thumb_func_end sub_803F508

	thumb_func_start sub_803F580
sub_803F580:
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	lsls r0, 24
	lsrs r0, 24
	mov r9, r0
	ldr r0, _0803F600
	ldr r4, [r0]
	ldr r0, _0803F604
	adds r5, r4, r0
	ldr r6, [r5, 0x10]
	cmp r6, 0
	bne _0803F59E
	b _0803F7A0
_0803F59E:
	adds r0, r6, 0
	bl sub_80450E0
	lsls r0, 24
	cmp r0, 0
	bne _0803F5AC
	b _0803F7A0
_0803F5AC:
	ldr r7, [r6, 0x70]
	ldr r0, [r5, 0x8]
	str r0, [r5, 0xC]
	ldr r0, [r5]
	str r0, [r5, 0x4]
	ldrh r0, [r6, 0x4]
	strh r0, [r5]
	ldrh r0, [r6, 0x6]
	strh r0, [r5, 0x2]
	ldr r0, [r6, 0xC]
	cmp r0, 0
	bge _0803F5C6
	adds r0, 0xFF
_0803F5C6:
	asrs r0, 8
	subs r0, 0x78
	strh r0, [r5, 0x8]
	ldr r0, [r6, 0x10]
	cmp r0, 0
	bge _0803F5D4
	adds r0, 0xFF
_0803F5D4:
	asrs r0, 8
	subs r0, 0x60
	strh r0, [r5, 0xA]
	adds r0, r6, 0
	movs r1, 0x11
	bl sub_8046CB0
	lsls r0, 24
	cmp r0, 0
	beq _0803F610
	ldrb r0, [r7, 0x7]
	cmp r0, 0
	beq _0803F610
	ldr r1, _0803F608
	adds r0, r4, r1
	movs r1, 0x1
	strb r1, [r0]
	ldr r2, _0803F60C
	adds r0, r4, r2
	strb r1, [r0]
	b _0803F626
	.align 2, 0
_0803F600: .4byte gUnknown_203B418
_0803F604: .4byte 0x000181e8
_0803F608: .4byte 0x0001820d
_0803F60C: .4byte 0x0001820e
_0803F610:
	adds r0, r7, 0
	adds r0, 0xF0
	ldrb r0, [r0]
	adds r1, r5, 0
	adds r1, 0x25
	strb r0, [r1]
	adds r0, r7, 0
	adds r0, 0xF1
	ldrb r0, [r0]
	adds r1, 0x1
	strb r0, [r1]
_0803F626:
	adds r0, r7, 0
	adds r0, 0xF2
	ldrb r0, [r0]
	adds r1, r5, 0
	adds r1, 0x29
	strb r0, [r1]
	subs r1, 0x7
	ldrb r0, [r1]
	mov r8, r0
	adds r0, r5, 0
	adds r0, 0x2C
	ldrb r2, [r0]
	adds r4, r1, 0
	cmp r2, 0
	bne _0803F670
	adds r0, r7, 0
	adds r0, 0xE8
	ldrb r1, [r0]
	adds r7, r0, 0
	cmp r1, 0x1
	bne _0803F656
	strb r1, [r4]
	movs r1, 0xE
	b _0803F65A
_0803F656:
	strb r2, [r4]
	movs r1, 0
_0803F65A:
	ldr r2, _0803F66C
	ldr r0, [r2]
	cmp r0, r1
	beq _0803F678
	str r1, [r2]
	adds r0, r1, 0
	bl SetBGOBJEnableFlags
	b _0803F678
	.align 2, 0
_0803F66C: .4byte gUnknown_202EDFC
_0803F670:
	ldr r1, _0803F698
	ldr r0, _0803F69C
	str r0, [r1]
	adds r7, 0xE8
_0803F678:
	ldrb r4, [r4]
	cmp r8, r4
	beq _0803F684
	movs r0, 0
	bl sub_8041888
_0803F684:
	adds r0, r5, 0
	adds r0, 0x28
	ldrb r1, [r0]
	mov r8, r1
	ldrb r1, [r7]
	adds r2, r0, 0
	cmp r1, 0x2
	bne _0803F6A0
	movs r0, 0x1
	b _0803F6A2
	.align 2, 0
_0803F698: .4byte gUnknown_202EDFC
_0803F69C: .4byte 0x0000ffff
_0803F6A0:
	movs r0, 0
_0803F6A2:
	strb r0, [r2]
	ldrb r2, [r2]
	cmp r8, r2
	beq _0803F6B4
	bl sub_806CC70
	movs r0, 0
	bl sub_8041888
_0803F6B4:
	adds r4, r5, 0
	adds r4, 0x27
	ldrb r2, [r4]
	mov r8, r2
	adds r0, r6, 0
	bl sub_8071884
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0
	beq _0803F6CC
	movs r0, 0x1
_0803F6CC:
	strb r0, [r4]
	ldrb r4, [r4]
	cmp r8, r4
	beq _0803F6E2
	bl sub_8049ED4
	bl sub_8040A84
	movs r0, 0
	bl sub_8041888
_0803F6E2:
	mov r0, r9
	cmp r0, 0
	beq _0803F76A
	adds r0, r5, 0
	adds r0, 0x2B
	ldrb r1, [r0]
	adds r4, r0, 0
	cmp r1, 0
	bne _0803F76A
	movs r2, 0xC
	ldrsh r1, [r5, r2]
	movs r2, 0x8
	ldrsh r0, [r5, r2]
	subs r1, r0
	cmp r1, 0
	bge _0803F704
	negs r1, r1
_0803F704:
	cmp r1, 0x7
	bgt _0803F71C
	movs r0, 0xE
	ldrsh r1, [r5, r0]
	movs r2, 0xA
	ldrsh r0, [r5, r2]
	subs r1, r0
	cmp r1, 0
	bge _0803F718
	negs r1, r1
_0803F718:
	cmp r1, 0x7
	ble _0803F726
_0803F71C:
	bl sub_8049ED4
	movs r0, 0x1
	strb r0, [r4]
	b _0803F76A
_0803F726:
	movs r0, 0xC
	ldrsh r1, [r5, r0]
	movs r2, 0x8
	ldrsh r0, [r5, r2]
	cmp r1, r0
	bge _0803F73C
	movs r0, 0xF0
	movs r1, 0
	bl sub_804A1F0
	b _0803F748
_0803F73C:
	cmp r1, r0
	ble _0803F748
	movs r0, 0
	movs r1, 0
	bl sub_804A1F0
_0803F748:
	movs r0, 0xE
	ldrsh r1, [r5, r0]
	movs r2, 0xA
	ldrsh r0, [r5, r2]
	cmp r1, r0
	bge _0803F75E
	movs r0, 0
	movs r1, 0xA0
	bl sub_804A49C
	b _0803F76A
_0803F75E:
	cmp r1, r0
	ble _0803F76A
	movs r0, 0
	movs r1, 0
	bl sub_804A49C
_0803F76A:
	ldr r1, [r5]
	ldr r0, [r5, 0x4]
	cmp r1, r0
	beq _0803F7A0
	movs r5, 0
_0803F774:
	ldr r0, _0803F7B4
	ldr r0, [r0]
	lsls r1, r5, 2
	ldr r2, _0803F7B8
	adds r0, r2
	adds r0, r1
	ldr r4, [r0]
	adds r0, r4, 0
	bl sub_80450E0
	lsls r0, 24
	cmp r0, 0
	beq _0803F79A
	movs r1, 0x4
	ldrsh r0, [r4, r1]
	movs r2, 0x6
	ldrsh r1, [r4, r2]
	bl sub_80402AC
_0803F79A:
	adds r5, 0x1
	cmp r5, 0x13
	ble _0803F774
_0803F7A0:
	bl sub_80400D4
	bl sub_803F7BC
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_0803F7B4: .4byte gUnknown_203B418
_0803F7B8: .4byte 0x000135cc
	thumb_func_end sub_803F580

	thumb_func_start sub_803F7BC
sub_803F7BC:
	push {r4-r6,lr}
	sub sp, 0x10
	ldr r6, _0803F800
	ldr r4, [r6]
	ldr r0, _0803F804
	adds r5, r4, r0
	movs r1, 0
	ldrsh r0, [r5, r1]
	movs r2, 0x2
	ldrsh r1, [r5, r2]
	bl sub_804954C
	ldrb r1, [r0, 0x9]
	ldr r2, _0803F808
	adds r0, r4, r2
	ldrb r0, [r0]
	cmp r0, 0
	bne _0803F7F4
	adds r2, 0x1
	adds r0, r4, r2
	ldrb r0, [r0]
	cmp r0, 0
	bne _0803F7F4
	adds r2, 0xB
	adds r0, r4, r2
	ldrb r0, [r0]
	cmp r0, 0
	beq _0803F80C
_0803F7F4:
	movs r0, 0
	movs r1, 0
	bl sub_8005838
	b _0803F86A
	.align 2, 0
_0803F800: .4byte gUnknown_203B418
_0803F804: .4byte 0x000181e8
_0803F808: .4byte 0x0001820b
_0803F80C:
	cmp r1, 0xFF
	bne _0803F82C
	ldr r1, _0803F828
	adds r0, r4, r1
	ldrb r0, [r0]
	movs r1, 0x2
	cmp r0, 0x2
	bne _0803F81E
	movs r1, 0x1
_0803F81E:
	movs r0, 0
	bl sub_8005838
	b _0803F86A
	.align 2, 0
_0803F828: .4byte 0x00018209
_0803F82C:
	lsls r0, r1, 3
	subs r0, r1
	lsls r0, 2
	ldr r2, _0803F874
	adds r0, r2
	ldr r2, [r6]
	adds r2, r0
	movs r0, 0x8
	ldrsh r1, [r5, r0]
	ldr r0, [r2, 0xC]
	subs r0, r1
	str r0, [sp]
	movs r0, 0xA
	ldrsh r1, [r5, r0]
	ldr r0, [r2, 0x10]
	subs r0, r1
	str r0, [sp, 0x4]
	movs r0, 0x8
	ldrsh r1, [r5, r0]
	ldr r0, [r2, 0x14]
	subs r0, r1
	str r0, [sp, 0x8]
	movs r0, 0xA
	ldrsh r1, [r5, r0]
	ldr r0, [r2, 0x18]
	subs r0, r1
	str r0, [sp, 0xC]
	mov r0, sp
	movs r1, 0x3
	bl sub_8005838
_0803F86A:
	add sp, 0x10
	pop {r4-r6}
	pop {r0}
	bx r0
	.align 2, 0
_0803F874: .4byte 0x000104c4
	thumb_func_end sub_803F7BC

	thumb_func_start sub_803F878
sub_803F878:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	adds r2, r0, 0
	adds r6, r1, 0
	ldr r0, _0803F92C
	ldr r7, [r0]
	ldr r0, _0803F930
	adds r5, r7, r0
	ldr r0, [r5, 0x8]
	str r0, [r5, 0xC]
	ldr r0, [r5]
	str r0, [r5, 0x4]
	adds r0, r2, 0
	cmp r2, 0
	bge _0803F89A
	adds r0, 0xFF
_0803F89A:
	asrs r0, 8
	subs r0, 0x78
	movs r1, 0
	mov r8, r1
	strh r0, [r5, 0x8]
	adds r0, r6, 0
	cmp r6, 0
	bge _0803F8AC
	adds r0, 0xFF
_0803F8AC:
	asrs r0, 8
	subs r0, 0x60
	strh r0, [r5, 0xA]
	movs r4, 0xC0
	lsls r4, 5
	adds r0, r2, 0
	adds r1, r4, 0
	bl __divsi3
	strh r0, [r5]
	adds r0, r6, 0
	adds r1, r4, 0
	bl __divsi3
	strh r0, [r5, 0x2]
	ldr r2, _0803F934
	adds r0, r7, r2
	mov r1, r8
	strb r1, [r0]
	adds r2, 0x1
	adds r0, r7, r2
	strb r1, [r0]
	ldr r1, _0803F938
	adds r0, r7, r1
	mov r2, r8
	strb r2, [r0]
	adds r1, 0x5
	adds r0, r7, r1
	strb r2, [r0]
	ldr r1, _0803F93C
	ldr r0, [r1]
	cmp r0, 0
	beq _0803F8F6
	movs r0, 0
	str r0, [r1]
	bl SetBGOBJEnableFlags
_0803F8F6:
	movs r2, 0xC
	ldrsh r1, [r5, r2]
	movs r2, 0x8
	ldrsh r0, [r5, r2]
	subs r1, r0
	cmp r1, 0
	bge _0803F906
	negs r1, r1
_0803F906:
	cmp r1, 0x7
	bgt _0803F91E
	movs r0, 0xE
	ldrsh r1, [r5, r0]
	movs r2, 0xA
	ldrsh r0, [r5, r2]
	subs r1, r0
	cmp r1, 0
	bge _0803F91A
	negs r1, r1
_0803F91A:
	cmp r1, 0x7
	ble _0803F940
_0803F91E:
	bl sub_8049ED4
	adds r1, r5, 0
	adds r1, 0x2B
	movs r0, 0x1
	strb r0, [r1]
	b _0803F984
	.align 2, 0
_0803F92C: .4byte gUnknown_203B418
_0803F930: .4byte 0x000181e8
_0803F934: .4byte 0x0001820d
_0803F938: .4byte 0x00018211
_0803F93C: .4byte gUnknown_202EDFC
_0803F940:
	movs r0, 0xC
	ldrsh r1, [r5, r0]
	movs r2, 0x8
	ldrsh r0, [r5, r2]
	cmp r1, r0
	bge _0803F956
	movs r0, 0xF0
	movs r1, 0
	bl sub_804A1F0
	b _0803F962
_0803F956:
	cmp r1, r0
	ble _0803F962
	movs r0, 0
	movs r1, 0
	bl sub_804A1F0
_0803F962:
	movs r0, 0xE
	ldrsh r1, [r5, r0]
	movs r2, 0xA
	ldrsh r0, [r5, r2]
	cmp r1, r0
	bge _0803F978
	movs r0, 0
	movs r1, 0xA0
	bl sub_804A49C
	b _0803F984
_0803F978:
	cmp r1, r0
	ble _0803F984
	movs r0, 0
	movs r1, 0
	bl sub_804A49C
_0803F984:
	bl sub_803F7BC
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_803F878

	thumb_func_start sub_803F994
sub_803F994:
	ldr r0, _0803F9A8
	ldr r0, [r0]
	ldr r1, _0803F9AC
	adds r0, r1
	movs r1, 0x8
	ldrsh r0, [r0, r1]
	adds r0, 0x78
	lsls r0, 8
	bx lr
	.align 2, 0
_0803F9A8: .4byte gUnknown_203B418
_0803F9AC: .4byte 0x000181e8
	thumb_func_end sub_803F994

	thumb_func_start sub_803F9B0
sub_803F9B0:
	ldr r0, _0803F9C4
	ldr r0, [r0]
	ldr r1, _0803F9C8
	adds r0, r1
	movs r1, 0xA
	ldrsh r0, [r0, r1]
	adds r0, 0x60
	lsls r0, 8
	bx lr
	.align 2, 0
_0803F9C4: .4byte gUnknown_203B418
_0803F9C8: .4byte 0x000181e8
	thumb_func_end sub_803F9B0

	thumb_func_start sub_803F9CC
sub_803F9CC:
	push {r4,r5,lr}
	ldr r0, _0803FA24
	ldr r1, [r0]
	ldr r2, _0803FA28
	adds r0, r1, r2
	ldr r4, [r0]
	movs r5, 0
	ldr r2, _0803FA2C
	adds r0, r1, r2
	ldrb r0, [r0]
	cmp r0, 0
	bne _0803FA0C
	ldr r2, _0803FA30
	adds r0, r1, r2
	ldrb r0, [r0]
	cmp r0, 0
	bne _0803FA0C
	bl sub_800EC74
	lsls r0, 24
	cmp r0, 0
	bne _0803FA0C
	cmp r4, 0
	beq _0803FA08
	adds r0, r4, 0
	bl sub_80450F8
	cmp r0, 0x1
	bne _0803FA08
	movs r5, 0x1
_0803FA08:
	cmp r5, 0
	bne _0803FA38
_0803FA0C:
	ldr r0, _0803FA34
	movs r2, 0
	adds r0, 0x2
	movs r1, 0x1C
_0803FA14:
	strh r2, [r0]
	adds r0, 0x2
	subs r1, 0x1
	cmp r1, 0
	bge _0803FA14
	bl sub_803F38C
	b _0803FA3C
	.align 2, 0
_0803FA24: .4byte gUnknown_203B418
_0803FA28: .4byte 0x000181f8
_0803FA2C: .4byte 0x0001356c
_0803FA30: .4byte 0x00018218
_0803FA34: .4byte gUnknown_202B038
_0803FA38:
	bl sub_803FB74
_0803FA3C:
	ldr r1, _0803FA48
	movs r0, 0x1
	strb r0, [r1]
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_0803FA48: .4byte gUnknown_20274A5
	thumb_func_end sub_803F9CC

	thumb_func_start sub_803FA4C
sub_803FA4C:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x28
	adds r4, r0, 0
	mov r8, r1
	lsls r2, 24
	lsrs r2, 24
	mov r12, r2
	ldr r0, _0803FB4C
	ldr r3, [r0]
	ldr r0, _0803FB50
	adds r0, r3, r0
	str r0, [sp, 0x24]
	ldr r7, _0803FB54
	mov r1, sp
	ldr r0, _0803FB58
	ldm r0!, {r2,r5,r6}
	stm r1!, {r2,r5,r6}
	ldm r0!, {r2,r5,r6}
	stm r1!, {r2,r5,r6}
	ldm r0!, {r2,r5,r6}
	stm r1!, {r2,r5,r6}
	ldr r0, _0803FB5C
	mov r10, r0
	ldr r1, _0803FB60
	mov r9, r1
	ldr r2, [sp, 0x24]
	movs r5, 0x3E
	ldrsh r0, [r2, r5]
	cmp r4, r0
	bne _0803FA9C
	ldr r6, _0803FB64
	adds r0, r3, r6
	movs r1, 0
	ldrsh r0, [r0, r1]
	cmp r8, r0
	beq _0803FB3A
_0803FA9C:
	mov r2, r12
	cmp r2, 0
	bne _0803FAA6
	ldr r5, _0803FB68
	mov r9, r5
_0803FAA6:
	ldr r6, [sp, 0x24]
	strh r4, [r6, 0x3E]
	ldr r1, _0803FB64
	adds r0, r3, r1
	mov r2, r8
	strh r2, [r0]
	mov r5, r8
	cmp r5, 0x5F
	ble _0803FAC8
	movs r5, 0x60
	lsls r0, r4, 1
	adds r0, r4
	lsls r0, 5
	mov r1, r8
	bl __divsi3
	adds r4, r0, 0
_0803FAC8:
	movs r3, 0
	mov r8, r3
	movs r6, 0x58
	mov r12, r6
_0803FAD0:
	ldr r6, _0803FB6C
	adds r2, r4, 0
	adds r0, r5, 0
	cmp r4, 0x7
	ble _0803FADC
	movs r2, 0x8
_0803FADC:
	cmp r5, 0x7
	ble _0803FAE2
	movs r0, 0x8
_0803FAE2:
	lsls r0, 2
	mov r3, sp
	adds r1, r3, r0
	lsls r0, r2, 2
	add r0, sp
	ldr r2, [r0]
	ldr r3, [r1]
	adds r1, r3, 0
	bics r1, r2
	mov r0, r10
	ands r1, r0
	mov r0, r9
	ands r0, r2
	orrs r0, r1
	ands r6, r3
	mov r1, r8
	stm r7!, {r1}
	stm r7!, {r6}
	stm r7!, {r0}
	stm r7!, {r0}
	stm r7!, {r0}
	stm r7!, {r0}
	stm r7!, {r6}
	stm r7!, {r1}
	subs r4, 0x8
	subs r5, 0x8
	cmp r4, 0
	bge _0803FB1C
	movs r4, 0
_0803FB1C:
	cmp r5, 0
	bge _0803FB22
	movs r5, 0
_0803FB22:
	movs r2, 0x8
	negs r2, r2
	add r12, r2
	mov r3, r12
	cmp r3, 0
	bge _0803FAD0
	ldr r0, _0803FB70
	movs r2, 0xC0
	lsls r2, 1
	ldr r1, _0803FB54
	bl sub_80098BC
_0803FB3A:
	add sp, 0x28
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_0803FB4C: .4byte gUnknown_203B418
_0803FB50: .4byte 0x000181e8
_0803FB54: .4byte gUnknown_3001018
_0803FB58: .4byte gUnknown_80F6490
_0803FB5C: .4byte 0x22222222
_0803FB60: .4byte 0x44444444
_0803FB64: .4byte 0x00018228
_0803FB68: .4byte 0x55555555
_0803FB6C: .4byte 0x77777777
_0803FB70: .4byte 0x06005980
	thumb_func_end sub_803FA4C

	thumb_func_start sub_803FB74
sub_803FB74:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x4
	ldr r0, _0803FBE8
	ldr r0, [r0]
	ldr r1, _0803FBEC
	adds r7, r0, r1
	movs r4, 0
	movs r2, 0
	str r2, [sp]
	ldr r0, [r7, 0x10]
	ldr r0, [r0, 0x70]
	movs r1, 0xE
	ldrsh r3, [r0, r1]
	mov r9, r3
	movs r3, 0x10
	ldrsh r2, [r0, r3]
	mov r8, r2
	ldrb r1, [r0, 0x9]
	mov r10, r1
	movs r2, 0xE
	ldrsh r1, [r0, r2]
	cmp r1, 0
	ble _0803FBBA
	mov r0, r8
	cmp r0, 0
	bge _0803FBB2
	adds r0, 0x3
_0803FBB2:
	asrs r0, 2
	cmp r1, r0
	bgt _0803FBBA
	movs r4, 0x1
_0803FBBA:
	ldr r0, [r7, 0x10]
	ldr r0, [r0, 0x70]
	movs r3, 0x9E
	lsls r3, 1
	adds r0, r3
	ldr r0, [r0]
	bl sub_8094450
	cmp r0, 0
	bne _0803FBD2
	movs r0, 0x1
	str r0, [sp]
_0803FBD2:
	cmp r4, 0
	beq _0803FBF4
	ldr r0, _0803FBF0
	ldr r0, [r0]
	movs r1, 0x10
	ands r0, r1
	cmp r0, 0
	beq _0803FBF4
	movs r5, 0x20
	movs r6, 0x20
	b _0803FBF8
	.align 2, 0
_0803FBE8: .4byte gUnknown_203B418
_0803FBEC: .4byte 0x000181e8
_0803FBF0: .4byte gUnknown_202EDCC
_0803FBF4:
	movs r5, 0
	movs r6, 0
_0803FBF8:
	ldr r1, [sp]
	cmp r1, 0
	beq _0803FC0E
	ldr r0, _0803FC20
	ldr r0, [r0]
	movs r1, 0x10
	ands r0, r1
	cmp r0, 0
	beq _0803FC0E
	movs r5, 0x30
	movs r6, 0x30
_0803FC0E:
	cmp r5, 0
	bne _0803FC30
	adds r0, r7, 0
	adds r0, 0x2A
	ldrb r0, [r0]
	cmp r0, 0
	beq _0803FC24
	movs r5, 0x60
	b _0803FC30
	.align 2, 0
_0803FC20: .4byte gUnknown_202EDCC
_0803FC24:
	ldr r0, _0803FCE4
	ldr r0, [r0]
	ldrb r0, [r0, 0xB]
	cmp r0, 0
	beq _0803FC30
	movs r5, 0x40
_0803FC30:
	cmp r6, 0
	bne _0803FC40
	ldr r0, _0803FCE4
	ldr r0, [r0]
	ldrb r0, [r0, 0xB]
	cmp r0, 0
	beq _0803FC40
	movs r6, 0x40
_0803FC40:
	movs r2, 0x36
	ldrsh r0, [r7, r2]
	cmp r0, r5
	beq _0803FC78
	strh r5, [r7, 0x36]
	lsls r5, 2
	ldr r4, _0803FCE8
	adds r1, r5, r4
	movs r0, 0xFC
	bl SetBGPaletteBufferColorArray
	adds r1, r4, 0x4
	adds r1, r5, r1
	movs r0, 0xFD
	bl SetBGPaletteBufferColorArray
	adds r1, r4, 0
	adds r1, 0x8
	adds r1, r5, r1
	movs r0, 0xFE
	bl SetBGPaletteBufferColorArray
	adds r4, 0xC
	adds r5, r4
	movs r0, 0xFF
	adds r1, r5, 0
	bl SetBGPaletteBufferColorArray
_0803FC78:
	movs r3, 0x38
	ldrsh r0, [r7, r3]
	cmp r0, r6
	beq _0803FCB0
	strh r6, [r7, 0x38]
	lsls r5, r6, 2
	ldr r4, _0803FCE8
	adds r1, r5, r4
	movs r0, 0xFC
	bl nullsub_5
	adds r1, r4, 0x4
	adds r1, r5, r1
	movs r0, 0xFD
	bl nullsub_5
	adds r1, r4, 0
	adds r1, 0x8
	adds r1, r5, r1
	movs r0, 0xFE
	bl nullsub_5
	adds r4, 0xC
	adds r5, r4
	movs r0, 0xFF
	adds r1, r5, 0
	bl nullsub_5
_0803FCB0:
	ldr r5, _0803FCEC
	ldr r0, _0803FCF0
	ldr r2, [r0]
	ldr r0, _0803FCF4
	adds r1, r2, r0
	movs r3, 0x14
	ldrsh r0, [r2, r3]
	ldrb r1, [r1]
	adds r6, r0, r1
	movs r1, 0x3A
	ldrsh r0, [r7, r1]
	adds r4, r7, 0
	adds r4, 0x2E
	cmp r0, r6
	beq _0803FD3E
	strh r6, [r7, 0x3A]
	ldr r3, _0803FCF8
	adds r0, r2, r3
	ldrb r0, [r0]
	bl GetStairDirection
	lsls r0, 24
	cmp r0, 0
	beq _0803FCFC
	movs r0, 0
	b _0803FD00
	.align 2, 0
_0803FCE4: .4byte gUnknown_203B46C
_0803FCE8: .4byte gUnknown_202D068
_0803FCEC: .4byte gUnknown_202B038
_0803FCF0: .4byte gUnknown_203B418
_0803FCF4: .4byte 0x00000645
_0803FCF8: .4byte 0x00000644
_0803FCFC:
	ldr r1, _0803FD20
	adds r0, r1, 0
_0803FD00:
	strh r0, [r5, 0x2]
	cmp r6, 0x9
	bgt _0803FD28
	adds r1, r5, 0x4
	adds r4, r7, 0
	adds r4, 0x2E
	ldrb r2, [r4]
	adds r0, r6, 0
	movs r3, 0x1
	bl sub_803FE30
	ldr r2, _0803FD24
	adds r0, r2, 0
	strh r0, [r5, 0x6]
	b _0803FD3E
	.align 2, 0
_0803FD20: .4byte 0x0000f2be
_0803FD24: .4byte 0x0000f2b8
_0803FD28:
	adds r1, r5, 0x4
	adds r4, r7, 0
	adds r4, 0x2E
	ldrb r2, [r4]
	adds r0, r6, 0
	movs r3, 0
	bl sub_803FE30
	ldr r3, _0803FE10
	adds r0, r3, 0
	strh r0, [r5, 0x8]
_0803FD3E:
	movs r1, 0x3C
	ldrsh r0, [r7, r1]
	cmp r0, r10
	beq _0803FD64
	mov r2, r10
	strh r2, [r7, 0x3C]
	ldr r3, _0803FE14
	adds r0, r3, 0
	strh r0, [r5, 0xA]
	ldr r1, _0803FE18
	adds r0, r1, 0
	strh r0, [r5, 0xC]
	adds r1, r5, 0
	adds r1, 0xE
	ldrb r2, [r4]
	mov r0, r10
	movs r3, 0
	bl sub_803FE30
_0803FD64:
	movs r2, 0x3E
	ldrsh r0, [r7, r2]
	cmp r0, r9
	beq _0803FD84
	ldr r3, _0803FE1C
	adds r0, r3, 0
	strh r0, [r5, 0x12]
	ldr r1, _0803FE20
	adds r0, r1, 0
	strh r0, [r5, 0x14]
	adds r1, r5, 0
	adds r1, 0x16
	ldrb r2, [r4]
	mov r0, r9
	bl sub_803FF18
_0803FD84:
	adds r6, r7, 0
	adds r6, 0x40
	movs r2, 0
	ldrsh r0, [r6, r2]
	cmp r0, r8
	beq _0803FDA2
	ldr r3, _0803FE24
	adds r0, r3, 0
	strh r0, [r5, 0x1C]
	adds r1, r5, 0
	adds r1, 0x1E
	ldrb r2, [r4]
	mov r0, r8
	bl sub_803FF18
_0803FDA2:
	ldrb r2, [r4]
	mov r0, r9
	mov r1, r8
	bl sub_803FA4C
	mov r0, r8
	strh r0, [r6]
	mov r1, r9
	strh r1, [r7, 0x3E]
	mov r0, r8
	cmp r0, 0
	bge _0803FDBC
	adds r0, 0x7
_0803FDBC:
	asrs r1, r0, 3
	adds r4, r7, 0
	adds r4, 0x42
	strh r1, [r4]
	movs r0, 0x7
	mov r2, r8
	ands r2, r0
	cmp r2, 0
	beq _0803FDD2
	adds r0, r1, 0x1
	strh r0, [r4]
_0803FDD2:
	movs r3, 0
	ldrsh r0, [r4, r3]
	cmp r0, 0xB
	ble _0803FDDE
	movs r0, 0xC
	strh r0, [r4]
_0803FDDE:
	movs r1, 0
	ldr r0, _0803FE28
	movs r2, 0xB3
	lsls r2, 2
	adds r4, r2, 0
	ldr r2, _0803FE2C
	adds r3, r2, 0
	adds r2, r0, 0
	adds r2, 0x24
_0803FDF0:
	adds r0, r1, r4
	orrs r0, r3
	strh r0, [r2]
	adds r2, 0x2
	adds r1, 0x1
	cmp r1, 0xB
	ble _0803FDF0
	add sp, 0x4
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_0803FE10: .4byte 0x0000f2b8
_0803FE14: .4byte 0x0000f2b9
_0803FE18: .4byte 0x0000f2ba
_0803FE1C: .4byte 0x0000f2bb
_0803FE20: .4byte 0x0000f2bc
_0803FE24: .4byte 0x0000f2bd
_0803FE28: .4byte gUnknown_202B038
_0803FE2C: .4byte 0xfffff000
	thumb_func_end sub_803FB74

	thumb_func_start sub_803FE30
sub_803FE30:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	adds r5, r0, 0
	adds r4, r1, 0
	lsls r2, 24
	lsrs r2, 24
	adds r1, r2, 0
	lsls r3, 24
	lsrs r3, 24
	mov r12, r3
	movs r0, 0
	cmp r2, 0
	bne _0803FE4E
	movs r0, 0x37
_0803FE4E:
	cmp r5, 0x64
	ble _0803FE70
	cmp r2, 0
	beq _0803FE60
	ldr r1, _0803FE5C
	adds r0, r1, 0
	b _0803FE64
	.align 2, 0
_0803FE5C: .4byte 0x0000f291
_0803FE60:
	ldr r2, _0803FE6C
	adds r0, r2, 0
_0803FE64:
	strh r0, [r4]
	strh r0, [r4, 0x2]
	b _0803FF00
	.align 2, 0
_0803FE6C: .4byte 0x0000f2c8
_0803FE70:
	cmp r5, 0x64
	bne _0803FEBC
	ldr r1, _0803FE84
	adds r0, r1, 0
	strh r0, [r4]
	ldr r2, _0803FE88
	adds r0, r2, 0
	strh r0, [r4, 0x2]
	b _0803FF00
	.align 2, 0
_0803FE84: .4byte 0x0000f294
_0803FE88: .4byte 0x0000f295
_0803FE8C:
	ldr r1, _0803FEB4
	lsls r0, r6, 3
	adds r0, r6
	adds r0, r2
	lsls r0, 1
	adds r0, r1
	ldrh r0, [r0]
	strh r0, [r4]
	subs r0, r5, r3
	adds r0, r7
	movs r1, 0x96
	lsls r1, 2
	adds r0, r1
	ldr r2, _0803FEB8
	adds r1, r2, 0
	orrs r0, r1
	mov r1, r8
	strh r0, [r1]
	b _0803FF00
	.align 2, 0
_0803FEB4: .4byte gUnknown_80F64D8
_0803FEB8: .4byte 0xfffff000
_0803FEBC:
	adds r2, r4, 0x2
	mov r8, r2
	adds r7, r0, 0
	adds r7, 0x30
	cmp r5, 0x9
	ble _0803FEE2
	movs r6, 0
	cmp r1, 0
	bne _0803FED0
	movs r6, 0x1
_0803FED0:
	movs r2, 0
	ldr r0, _0803FF0C
_0803FED4:
	ldr r3, [r0]
	cmp r3, r5
	ble _0803FE8C
	adds r0, 0x4
	adds r2, 0x1
	cmp r2, 0x8
	ble _0803FED4
_0803FEE2:
	mov r0, r12
	cmp r0, 0
	bne _0803FEF0
	ldr r1, _0803FF10
	adds r0, r1, 0
	strh r0, [r4]
	adds r4, 0x2
_0803FEF0:
	adds r0, r5, r7
	movs r2, 0x96
	lsls r2, 2
	adds r0, r2
	ldr r2, _0803FF14
	adds r1, r2, 0
	orrs r0, r1
	strh r0, [r4]
_0803FF00:
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_0803FF0C: .4byte gUnknown_80F64B4
_0803FF10: .4byte 0x0000f278
_0803FF14: .4byte 0xfffff000
	thumb_func_end sub_803FE30

	thumb_func_start sub_803FF18
sub_803FF18:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	adds r5, r0, 0
	adds r3, r1, 0
	lsls r2, 24
	lsrs r2, 24
	movs r6, 0
	cmp r2, 0
	bne _0803FF2E
	movs r6, 0x1
_0803FF2E:
	movs r1, 0
	cmp r2, 0
	bne _0803FF36
	movs r1, 0x37
_0803FF36:
	ldr r0, _0803FF54
	cmp r5, r0
	ble _0803FF7C
	ldr r0, _0803FF58
	lsls r1, r6, 3
	adds r1, r6
	lsls r1, 1
	adds r1, r0
	ldrh r0, [r1]
	strh r0, [r3]
	adds r3, 0x2
	strh r0, [r3]
	strh r0, [r3, 0x2]
	b _0804001A
	.align 2, 0
_0803FF54: .4byte 0x000003e7
_0803FF58: .4byte gUnknown_80F6544
_0803FF5C:
	ldr r1, _0803FF78
	lsls r0, r6, 3
	adds r0, r6
	adds r0, r4
	lsls r0, 1
	adds r0, r1
	ldrh r0, [r0]
	strh r0, [r3]
	adds r3, 0x2
	subs r5, r2
	mov r1, r8
	lsls r0, r1, 24
	lsrs r7, r0, 24
	b _0803FF98
	.align 2, 0
_0803FF78: .4byte gUnknown_80F6544
_0803FF7C:
	movs r7, 0x20
	movs r4, 0
	adds r1, 0x30
	mov r8, r1
	ldr r2, _0803FFC0
	mov r12, r2
	ldr r0, _0803FFC4
_0803FF8A:
	ldr r2, [r0]
	cmp r2, r5
	ble _0803FF5C
	adds r0, 0x4
	adds r4, 0x1
	cmp r4, 0x8
	ble _0803FF8A
_0803FF98:
	cmp r4, 0x9
	bne _0803FFAC
	movs r1, 0x96
	lsls r1, 2
	adds r0, r7, r1
	ldr r2, _0803FFC8
	adds r1, r2, 0
	orrs r0, r1
	strh r0, [r3]
	adds r3, 0x2
_0803FFAC:
	movs r4, 0
	mov r0, r12
	ldr r2, [r0]
	cmp r2, r5
	bgt _0803FFD0
	ldr r0, _0803FFCC
	lsls r1, r6, 3
	adds r1, r6
	b _0803FFE8
	.align 2, 0
_0803FFC0: .4byte gUnknown_80F6520
_0803FFC4: .4byte gUnknown_80F64FC
_0803FFC8: .4byte 0xfffff000
_0803FFCC: .4byte gUnknown_80F6544
_0803FFD0:
	adds r4, 0x1
	cmp r4, 0x8
	bgt _0803FFF4
	lsls r0, r4, 2
	add r0, r12
	ldr r2, [r0]
	cmp r2, r5
	bgt _0803FFD0
	ldr r0, _08040024
	lsls r1, r6, 3
	adds r1, r6
	adds r1, r4
_0803FFE8:
	lsls r1, 1
	adds r1, r0
	ldrh r0, [r1]
	strh r0, [r3]
	adds r3, 0x2
	subs r5, r2
_0803FFF4:
	cmp r4, 0x9
	bne _08040008
	movs r1, 0x96
	lsls r1, 2
	adds r0, r7, r1
	ldr r2, _08040028
	adds r1, r2, 0
	orrs r0, r1
	strh r0, [r3]
	adds r3, 0x2
_08040008:
	mov r1, r8
	adds r0, r5, r1
	movs r2, 0x96
	lsls r2, 2
	adds r0, r2
	ldr r2, _08040028
	adds r1, r2, 0
	orrs r0, r1
	strh r0, [r3]
_0804001A:
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_08040024: .4byte gUnknown_80F6544
_08040028: .4byte 0xfffff000
	thumb_func_end sub_803FF18

	thumb_func_start sub_804002C
sub_804002C:
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	mov r8, r0
	ldr r0, _08040088
	ldr r0, [r0]
	ldr r1, _0804008C
	adds r0, r1
	movs r1, 0x1
	strb r1, [r0]
	movs r5, 0
	movs r7, 0x1
_08040046:
	movs r4, 0
	adds r6, r5, 0x1
_0804004A:
	adds r0, r4, 0
	adds r1, r5, 0
	bl sub_8049590
	ldrh r1, [r0, 0x4]
	orrs r1, r7
	strh r1, [r0, 0x4]
	adds r4, 0x1
	cmp r4, 0x37
	ble _0804004A
	adds r5, r6, 0
	cmp r5, 0x1F
	ble _08040046
	movs r0, 0
	bl sub_803F580
	bl sub_8049ED4
	bl sub_8040A84
	ldr r0, _08040090
	ldr r1, [r0]
	mov r0, r8
	bl sub_80522A8
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_08040088: .4byte gUnknown_203B418
_0804008C: .4byte 0x0001820b
_08040090: .4byte gUnknown_80FD040
	thumb_func_end sub_804002C

	thumb_func_start sub_8040094
sub_8040094:
	push {lr}
	ldr r1, _080400C8
	ldr r1, [r1]
	ldr r2, _080400CC
	adds r1, r2
	strb r0, [r1]
	bl sub_803F7BC
	bl sub_80060EC
	ldr r0, _080400D0
	ldr r0, [r0]
	bl sub_8094FB4
	bl sub_800CB20
	bl sub_800485C
	bl xxx_call_update_bg_sound_input
	bl sub_8083F58
	bl sub_8011860
	pop {r0}
	bx r0
	.align 2, 0
_080400C8: .4byte gUnknown_203B418
_080400CC: .4byte 0x00018217
_080400D0: .4byte gUnknown_203B47C
	thumb_func_end sub_8040094

	thumb_func_start sub_80400D4
sub_80400D4:
	push {r4,lr}
	ldr r0, _08040114
	ldr r4, [r0]
	movs r0, 0xC1
	lsls r0, 9
	adds r3, r4, r0
	ldr r0, [r3]
	cmp r0, 0
	beq _0804010C
	cmp r0, 0x1E
	ble _080400EC
	movs r0, 0x1F
_080400EC:
	ldr r1, _08040118
	adds r2, r4, r1
	ldr r1, _0804011C
	lsls r0, 2
	adds r0, r1
	ldr r0, [r0]
	str r0, [r2]
	ldr r0, [r3]
	subs r0, 0x1
	str r0, [r3]
	cmp r0, 0
	bne _0804010C
	ldr r1, _08040120
	adds r0, r4, r1
	ldr r0, [r0]
	str r0, [r3]
_0804010C:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08040114: .4byte gUnknown_203B418
_08040118: .4byte 0x000181fc
_0804011C: .4byte gUnknown_80F6568
_08040120: .4byte 0x00018204
	thumb_func_end sub_80400D4

	thumb_func_start sub_8040124
sub_8040124:
	ldr r1, _0804012C
	movs r0, 0
	strb r0, [r1]
	bx lr
	.align 2, 0
_0804012C: .4byte gUnknown_202EE01
	thumb_func_end sub_8040124

	thumb_func_start sub_8040130
sub_8040130:
	push {lr}
	ldr r0, _08040144
	ldr r1, _08040148
	bl OpenFileAndGetFileDataPtr
	ldr r1, _0804014C
	str r0, [r1]
	pop {r0}
	bx r0
	.align 2, 0
_08040144: .4byte gUnknown_80F6604
_08040148: .4byte gUnknown_83B0000
_0804014C: .4byte gUnknown_202EE04
	thumb_func_end sub_8040130

	thumb_func_start sub_8040150
sub_8040150:
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	sub sp, 0x4
	lsls r0, 24
	lsrs r0, 24
	mov r9, r0
	movs r0, 0
	ldr r2, _080401EC
_08040164:
	movs r4, 0
	lsls r1, r0, 3
	adds r3, r0, 0x1
	mov r8, r3
	subs r1, r0
	lsls r0, r1, 7
	ldr r3, _080401F0
	adds r6, r0, r3
	lsls r5, r1, 2
_08040176:
	ldr r0, [r2]
	adds r0, r6
	lsls r1, r4, 5
	adds r0, r1
	movs r1, 0x20
	str r2, [sp]
	bl CpuClear
	ldr r2, [sp]
	ldr r0, [r2]
	adds r1, r4, r5
	ldr r3, _080401F4
	adds r0, r3
	adds r0, r1
	movs r7, 0
	strb r7, [r0]
	adds r4, 0x1
	cmp r4, 0x1B
	ble _08040176
	mov r0, r8
	cmp r0, 0xF
	ble _08040164
	mov r0, r9
	cmp r0, 0
	bne _080401B0
	ldr r1, _080401F8
	movs r0, 0x64
	strh r0, [r1]
	strh r0, [r1, 0x2]
_080401B0:
	ldr r3, _080401EC
	ldr r0, [r3]
	ldr r2, _080401FC
	adds r1, r0, r2
	str r7, [r1]
	ldr r1, _08040200
	adds r0, r1
	movs r2, 0x1
	strb r2, [r0]
	ldr r0, [r3]
	ldr r3, _08040204
	adds r0, r3
	strb r7, [r0]
	ldr r0, _08040208
	strb r2, [r0]
	ldr r1, _0804020C
	ldr r0, _08040210
	str r0, [r1]
	ldr r0, _08040214
	strb r2, [r0]
	bl sub_8040238
	add sp, 0x4
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_080401EC: .4byte gUnknown_203B418
_080401F0: .4byte 0x0001822c
_080401F4: .4byte 0x0001ba2c
_080401F8: .4byte gUnknown_203B410
_080401FC: .4byte 0x0001bdcc
_08040200: .4byte 0x0001bdd0
_08040204: .4byte 0x0001bdd2
_08040208: .4byte gUnknown_202EE00
_0804020C: .4byte gUnknown_202EE08
_08040210: .4byte 0x06001700
_08040214: .4byte gUnknown_202EE01
	thumb_func_end sub_8040150

	thumb_func_start sub_8040218
sub_8040218:
	push {lr}
	ldr r0, _08040230
	ldr r0, [r0]
	cmp r0, 0
	beq _08040226
	bl CloseFile
_08040226:
	bl sub_8040124
	pop {r0}
	bx r0
	.align 2, 0
_08040230: .4byte gUnknown_202EE04
	thumb_func_end sub_8040218

	thumb_func_start nullsub_203
nullsub_203:
	bx lr
	thumb_func_end nullsub_203

	thumb_func_start sub_8040238
sub_8040238:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	ldr r1, _0804026C
	ldr r0, [r1]
	cmp r0, 0
	beq _080402A0
	ldr r0, _08040270
	ldrb r0, [r0]
	cmp r0, 0
	beq _080402A0
	movs r6, 0
	ldr r0, _08040274
	mov r8, r0
	adds r7, r1, 0
_08040256:
	cmp r6, 0xE
	bne _08040278
	movs r0, 0xEE
	mov r1, r8
	bl SetBGPaletteBufferColorArray
	movs r0, 0xEE
	mov r1, r8
	bl nullsub_5
	b _0804029A
	.align 2, 0
_0804026C: .4byte gUnknown_202EE04
_08040270: .4byte gUnknown_202EE01
_08040274: .4byte gUnknown_202D03C
_08040278:
	adds r5, r6, 0
	adds r5, 0xE0
	ldr r0, [r7]
	ldr r0, [r0, 0x4]
	lsls r4, r6, 2
	ldr r1, [r0, 0x4]
	adds r1, r4
	adds r0, r5, 0
	bl SetBGPaletteBufferColorArray
	ldr r0, [r7]
	ldr r0, [r0, 0x4]
	ldr r1, [r0, 0x4]
	adds r1, r4
	adds r0, r5, 0
	bl nullsub_5
_0804029A:
	adds r6, 0x1
	cmp r6, 0xF
	ble _08040256
_080402A0:
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_8040238

	thumb_func_start sub_80402AC
sub_80402AC:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x1C
	mov r8, r0
	str r1, [sp]
	ldr r4, _0804034C
	ldr r0, [r4]
	str r0, [sp, 0x4]
	movs r1, 0x1
	mov r10, r1
	ldr r0, _08040350
	ldr r0, [r0]
	cmp r0, 0
	bne _080402D0
	b _08040776
_080402D0:
	ldr r0, _08040354
	ldrb r0, [r0]
	cmp r0, 0
	bne _080402DA
	b _08040776
_080402DA:
	bl sub_800EC74
	lsls r0, 24
	cmp r0, 0
	beq _080402E6
	b _08040776
_080402E6:
	mov r2, r8
	cmp r2, 0
	bge _080402EE
	b _08040776
_080402EE:
	ldr r3, [sp]
	cmp r3, 0x1
	bgt _080402F6
	b _08040776
_080402F6:
	cmp r2, 0x37
	ble _080402FC
	b _08040776
_080402FC:
	cmp r3, 0x1E
	ble _08040302
	b _08040776
_08040302:
	mov r0, r8
	adds r1, r3, 0
	bl sub_804954C
	mov r9, r0
	ldrh r0, [r0]
	movs r5, 0x3
	ands r5, r0
	str r5, [sp, 0x8]
	ldr r0, [r4]
	ldr r7, _08040358
	adds r1, r0, r7
	ldrb r1, [r1]
	str r1, [sp, 0xC]
	ldr r2, _0804035C
	adds r1, r0, r2
	ldrb r5, [r1]
	ldr r3, _08040360
	adds r1, r0, r3
	ldrb r1, [r1]
	str r1, [sp, 0x14]
	subs r7, 0x2
	adds r1, r0, r7
	ldrb r1, [r1]
	str r1, [sp, 0x10]
	ldr r1, _08040364
	adds r0, r1
	ldrb r0, [r0]
	cmp r5, 0
	beq _08040368
	mov r2, r9
	ldrb r0, [r2, 0x4]
	mov r7, r10
	ands r7, r0
	movs r3, 0
	str r3, [sp, 0x18]
	b _0804039C
	.align 2, 0
_0804034C: .4byte gUnknown_203B418
_08040350: .4byte gUnknown_202EE04
_08040354: .4byte gUnknown_202EE01
_08040358: .4byte 0x00018210
_0804035C: .4byte 0x0001820a
_08040360: .4byte 0x0001820f
_08040364: .4byte 0x0001820b
_08040368:
	cmp r0, 0
	beq _08040370
	movs r7, 0x1
	b _08040378
_08040370:
	mov r7, r9
	ldrb r0, [r7, 0x4]
	mov r7, r10
	ands r7, r0
_08040378:
	bl sub_8043D10
	lsls r0, 24
	cmp r0, 0
	bne _08040398
	ldr r0, _08040390
	ldr r0, [r0]
	ldr r1, _08040394
	adds r0, r1
	ldrb r0, [r0]
	str r0, [sp, 0x18]
	b _0804039C
	.align 2, 0
_08040390: .4byte gUnknown_203B418
_08040394: .4byte 0x00018211
_08040398:
	movs r2, 0
	str r2, [sp, 0x18]
_0804039C:
	bl sub_8094C48
	lsls r0, 24
	cmp r0, 0
	bne _080403A8
	b _08040632
_080403A8:
	ldr r0, _080403FC
	ldr r0, [r0]
	ldr r3, _08040400
	adds r0, r3
	ldrb r0, [r0]
	cmp r0, 0
	beq _080403B8
	b _08040632
_080403B8:
	movs r6, 0
	cmp r5, 0
	bne _0804045E
	mov r0, r9
	ldr r4, [r0, 0x10]
	cmp r4, 0
	beq _0804045E
	adds r0, r4, 0
	bl sub_80450F8
	adds r1, r0, 0
	ldr r0, _08040404
	ldrb r0, [r0]
	cmp r0, 0
	beq _0804045E
	cmp r1, 0x1
	bne _0804045E
	adds r0, r4, 0
	bl sub_8045804
	lsls r0, 24
	cmp r0, 0
	beq _0804045E
	ldr r1, [r4, 0x70]
	adds r0, r1, 0
	adds r0, 0x40
	ldrb r0, [r0]
	cmp r0, 0x4A
	beq _080403F6
	cmp r0, 0x47
	bne _08040408
_080403F6:
	movs r0, 0x1
	b _0804040A
	.align 2, 0
_080403FC: .4byte gUnknown_203B418
_08040400: .4byte 0x0001356c
_08040404: .4byte gUnknown_202EE00
_08040408:
	movs r0, 0
_0804040A:
	cmp r0, 0
	bne _08040458
	adds r0, r1, 0
	adds r0, 0xA4
	ldrb r0, [r0]
	cmp r0, 0x1
	beq _08040458
	cmp r0, 0x4
	beq _08040458
	ldrb r0, [r1, 0x6]
	cmp r0, 0
	beq _08040426
	movs r6, 0x2
	b _0804045A
_08040426:
	ldrb r0, [r1, 0x7]
	cmp r0, 0
	beq _08040458
	ldr r0, _0804044C
	mov r1, r8
	strh r1, [r0]
	mov r2, sp
	ldrh r2, [r2]
	strh r2, [r0, 0x2]
	ldr r0, _08040450
	ldr r0, [r0]
	ldr r3, _08040454
	adds r0, r3
	ldrb r0, [r0]
	cmp r0, 0
	beq _0804045A
	movs r6, 0x8
	b _0804045A
	.align 2, 0
_0804044C: .4byte gUnknown_203B410
_08040450: .4byte gUnknown_203B418
_08040454: .4byte 0x00018214
_08040458:
	movs r6, 0xA
_0804045A:
	movs r0, 0
	mov r10, r0
_0804045E:
	mov r1, r10
	cmp r1, 0
	beq _0804054E
	cmp r5, 0
	bne _08040548
	mov r2, r9
	ldr r4, [r2, 0x14]
	cmp r4, 0
	beq _08040500
	adds r0, r4, 0
	bl sub_80450F8
	adds r5, r0, 0
	cmp r7, 0
	bne _0804049E
	movs r6, 0
	cmp r5, 0x3
	bne _0804054E
	ldr r3, [sp, 0x10]
	cmp r3, 0
	bne _08040494
	mov r5, r9
	ldrh r1, [r5, 0x4]
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	beq _0804054E
_08040494:
	ldr r0, [sp, 0x8]
	cmp r0, 0
	beq _0804054E
	movs r6, 0x3
	b _0804054E
_0804049E:
	cmp r5, 0x2
	bne _080404C4
	adds r0, r4, 0
	adds r0, 0x20
	ldrb r0, [r0]
	cmp r0, 0
	bne _080404B2
	ldr r1, [sp, 0x14]
	cmp r1, 0
	beq _080404C4
_080404B2:
	adds r0, r4, 0
	bl sub_8045104
	ldr r1, _080404FC
	ldrb r0, [r0]
	adds r0, r1
	ldrb r6, [r0]
	movs r2, 0
	mov r10, r2
_080404C4:
	mov r3, r10
	cmp r3, 0
	beq _0804054E
	cmp r5, 0x3
	bne _080404EC
	ldr r5, [sp, 0x10]
	cmp r5, 0
	bne _080404E0
	mov r0, r9
	ldrh r1, [r0, 0x4]
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	beq _080404EC
_080404E0:
	ldr r1, [sp, 0x8]
	cmp r1, 0
	beq _080404EC
	movs r6, 0x3
	movs r2, 0
	mov r10, r2
_080404EC:
	mov r3, r10
	cmp r3, 0
	beq _0804054E
	ldr r5, [sp, 0x8]
	cmp r5, 0x1
	beq _08040548
	movs r6, 0
	b _0804054E
	.align 2, 0
_080404FC: .4byte gUnknown_80F65F0
_08040500:
	cmp r7, 0
	bne _08040528
	ldr r0, [sp, 0x18]
	cmp r0, 0
	beq _08040548
	mov r2, r9
	ldrh r1, [r2]
	movs r0, 0x80
	lsls r0, 2
	ands r0, r1
	cmp r0, 0
	beq _08040548
	bl sub_8043D10
	lsls r0, 24
	movs r6, 0x5
	cmp r0, 0
	bne _0804054E
	movs r6, 0x6
	b _0804054E
_08040528:
	mov r3, r9
	ldrh r1, [r3]
	movs r0, 0x80
	lsls r0, 2
	ands r0, r1
	cmp r0, 0
	beq _08040548
	bl sub_8043D10
	lsls r0, 24
	movs r6, 0x5
	cmp r0, 0
	bne _08040544
	movs r6, 0x6
_08040544:
	movs r5, 0
	mov r10, r5
_08040548:
	mov r0, r10
	cmp r0, 0
	bne _0804055A
_0804054E:
	ldr r1, [sp, 0xC]
	cmp r1, 0
	beq _0804055A
	cmp r6, 0
	beq _0804055E
	movs r6, 0xB
_0804055A:
	cmp r6, 0
	bne _08040606
_0804055E:
	cmp r7, 0
	beq _08040568
	ldr r2, [sp, 0x8]
	cmp r2, 0x1
	beq _0804056C
_08040568:
	movs r6, 0x1
	b _08040606
_0804056C:
	movs r4, 0xF
	ldr r3, [sp]
	cmp r3, 0x1E
	bgt _0804058A
	adds r1, r3, 0
	adds r1, 0x1
	mov r0, r8
	bl sub_804954C
	ldrh r1, [r0]
	movs r0, 0x3
	ands r0, r1
	cmp r0, 0x1
	bne _0804058A
	movs r4, 0xE
_0804058A:
	ldr r5, [sp]
	cmp r5, 0
	ble _080405AA
	adds r1, r5, 0
	subs r1, 0x1
	mov r0, r8
	bl sub_804954C
	ldrh r1, [r0]
	movs r0, 0x3
	ands r0, r1
	cmp r0, 0x1
	bne _080405AA
	movs r0, 0x5
	negs r0, r0
	ands r4, r0
_080405AA:
	mov r7, r8
	cmp r7, 0x36
	bgt _080405CA
	mov r0, r8
	adds r0, 0x1
	ldr r1, [sp]
	bl sub_804954C
	ldrh r1, [r0]
	movs r0, 0x3
	ands r0, r1
	cmp r0, 0x1
	bne _080405CA
	movs r0, 0x3
	negs r0, r0
	ands r4, r0
_080405CA:
	mov r0, r8
	cmp r0, 0
	ble _080405E8
	subs r0, 0x1
	ldr r1, [sp]
	bl sub_804954C
	ldrh r1, [r0]
	movs r0, 0x3
	ands r0, r1
	cmp r0, 0x1
	bne _080405E8
	movs r0, 0x9
	negs r0, r0
	ands r4, r0
_080405E8:
	lsls r0, r4, 16
	asrs r6, r0, 16
	mov r2, r9
	ldrh r1, [r2, 0x4]
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	beq _080405FE
	adds r0, r6, 0
	adds r0, 0x10
	b _08040602
_080405FE:
	adds r0, r6, 0
	adds r0, 0x20
_08040602:
	lsls r0, 16
	asrs r6, r0, 16
_08040606:
	ldr r0, _08040618
	ldr r0, [r0]
	ldrb r0, [r0, 0x4]
	cmp r0, 0x6
	bne _0804061C
	adds r0, r6, 0
	adds r0, 0x80
	b _0804062C
	.align 2, 0
_08040618: .4byte gUnknown_203B46C
_0804061C:
	bl sub_8094C68
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _0804063A
	adds r0, r6, 0
	adds r0, 0x40
_0804062C:
	lsls r0, 16
	asrs r6, r0, 16
	b _0804063A
_08040632:
	movs r6, 0x1
	ldr r1, _0804074C
	movs r0, 0x64
	strh r0, [r1]
_0804063A:
	mov r3, r8
	lsrs r0, r3, 31
	add r0, r8
	asrs r0, 1
	mov r9, r0
	ldr r0, [sp]
	subs r0, 0x2
	lsrs r1, r0, 31
	adds r1, r0, r1
	asrs r1, 1
	mov r5, r9
	lsls r3, r5, 1
	mov r7, r8
	subs r3, r7, r3
	lsls r2, r1, 1
	subs r0, r2
	lsls r0, 1
	adds r3, r0
	lsls r0, r1, 3
	subs r5, r0, r1
	lsls r0, r5, 7
	ldr r1, _08040750
	adds r0, r1
	ldr r2, [sp, 0x4]
	adds r0, r2, r0
	mov r7, r9
	lsls r1, r7, 5
	adds r4, r0, r1
	ldr r0, _08040754
	ldr r0, [r0]
	ldr r1, [r0, 0x4]
	lsls r0, r6, 2
	adds r0, r3
	ldr r1, [r1]
	lsls r0, 2
	adds r0, r1
	ldr r2, [r0]
	ldr r0, [r4]
	ldr r1, [r2]
	ands r0, r1
	ldr r1, [r2, 0x4]
	orrs r0, r1
	str r0, [r4]
	ldr r0, [r4, 0x4]
	ldr r1, [r2, 0x8]
	ands r0, r1
	ldr r1, [r2, 0xC]
	orrs r0, r1
	str r0, [r4, 0x4]
	ldr r0, [r4, 0x8]
	ldr r1, [r2, 0x10]
	ands r0, r1
	ldr r1, [r2, 0x14]
	orrs r0, r1
	str r0, [r4, 0x8]
	ldr r0, [r4, 0xC]
	ldr r1, [r2, 0x18]
	ands r0, r1
	ldr r1, [r2, 0x1C]
	orrs r0, r1
	str r0, [r4, 0xC]
	ldr r0, [r4, 0x10]
	ldr r1, [r2, 0x20]
	ands r0, r1
	ldr r1, [r2, 0x24]
	orrs r0, r1
	str r0, [r4, 0x10]
	ldr r0, [r4, 0x14]
	ldr r1, [r2, 0x28]
	ands r0, r1
	ldr r1, [r2, 0x2C]
	orrs r0, r1
	str r0, [r4, 0x14]
	ldr r0, [r4, 0x18]
	ldr r1, [r2, 0x30]
	ands r0, r1
	ldr r1, [r2, 0x34]
	orrs r0, r1
	str r0, [r4, 0x18]
	ldr r0, [r4, 0x1C]
	ldr r1, [r2, 0x38]
	ands r0, r1
	ldr r1, [r2, 0x3C]
	orrs r0, r1
	str r0, [r4, 0x1C]
	ldr r0, [sp, 0x4]
	ldr r1, _08040758
	adds r2, r0, r1
	ldrb r0, [r2]
	cmp r0, 0
	bne _08040776
	lsls r5, 2
	mov r10, r5
	mov r3, r9
	add r3, r10
	ldr r5, _0804075C
	mov r8, r5
	ldr r0, [sp, 0x4]
	add r0, r8
	adds r1, r0, r3
	ldrb r0, [r1]
	cmp r0, 0
	bne _08040776
	movs r0, 0x1
	strb r0, [r1]
	ldr r7, [sp, 0x4]
	ldr r1, _08040760
	adds r6, r7, r1
	ldr r5, [r6]
	cmp r5, 0x27
	bgt _08040774
	lsls r1, r5, 1
	adds r1, r5
	lsls r1, 2
	ldr r0, _08040764
	adds r2, r7, r0
	adds r2, r1
	ldr r0, _08040768
	lsls r3, 5
	ldr r0, [r0]
	adds r0, r3
	str r0, [r2]
	ldr r2, _0804076C
	adds r0, r7, r2
	adds r0, r1
	str r4, [r0]
	ldr r3, _08040770
	adds r2, r7, r3
	adds r2, r1
	mov r0, r10
	add r0, r8
	adds r0, r7, r0
	add r0, r9
	str r0, [r2]
	adds r0, r5, 0x1
	str r0, [r6]
	b _08040776
	.align 2, 0
_0804074C: .4byte gUnknown_203B410
_08040750: .4byte 0x0001822c
_08040754: .4byte gUnknown_202EE04
_08040758: .4byte 0x0001bdd1
_0804075C: .4byte 0x0001ba2c
_08040760: .4byte 0x0001bdcc
_08040764: .4byte 0x0001bbec
_08040768: .4byte gUnknown_202EE08
_0804076C: .4byte 0x0001bbf0
_08040770: .4byte 0x0001bbf4
_08040774:
	strb r0, [r2]
_08040776:
	add sp, 0x1C
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_80402AC

	thumb_func_start sub_8040788
sub_8040788:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	ldr r0, _08040814
	ldr r0, [r0]
	mov r8, r0
	cmp r0, 0
	beq _08040870
	ldr r0, _08040818
	add r0, r8
	ldrb r0, [r0]
	cmp r0, 0
	beq _08040870
	bl sub_800EC74
	lsls r0, 24
	lsrs r2, r0, 24
	cmp r2, 0
	bne _08040870
	ldr r1, _0804081C
	add r1, r8
	ldrb r0, [r1]
	cmp r0, 0
	bne _0804082C
	movs r6, 0
	ldr r1, _08040820
	add r1, r8
	ldr r0, [r1]
	cmp r6, r0
	bge _08040868
	adds r5, r1, 0
	movs r4, 0
_080407C8:
	ldr r1, _08040824
	adds r0, r4, r1
	mov r1, r8
	adds r3, r1, r0
	ldr r1, [r3, 0x4]
	ldr r2, [r3]
	ldr r0, _08040828
	ldr r0, [r0]
	cmp r0, 0
	beq _080407E0
	cmp r0, 0x3
	bne _08040800
_080407E0:
	ldm r1!, {r0}
	stm r2!, {r0}
	ldm r1!, {r0}
	stm r2!, {r0}
	ldm r1!, {r0}
	stm r2!, {r0}
	ldm r1!, {r0}
	stm r2!, {r0}
	ldm r1!, {r0}
	stm r2!, {r0}
	ldm r1!, {r0}
	stm r2!, {r0}
	ldm r1!, {r0}
	stm r2!, {r0}
	ldr r0, [r1]
	str r0, [r2]
_08040800:
	ldr r0, [r3, 0x8]
	movs r1, 0
	strb r1, [r0]
	adds r4, 0xC
	adds r6, 0x1
	ldr r0, [r5]
	cmp r6, r0
	blt _080407C8
	b _08040868
	.align 2, 0
_08040814: .4byte gUnknown_203B418
_08040818: .4byte 0x0001bdd0
_0804081C: .4byte 0x0001bdd1
_08040820: .4byte 0x0001bdcc
_08040824: .4byte 0x0001bbec
_08040828: .4byte gUnknown_202EDD0
_0804082C:
	strb r2, [r1]
	ldr r0, _0804087C
	ldr r5, [r0]
	ldr r4, _08040880
	add r4, r8
	movs r6, 0
	movs r7, 0x80
	lsls r7, 1
_0804083C:
	ldr r0, _08040884
	ldr r0, [r0]
	cmp r0, 0
	beq _08040848
	cmp r0, 0x3
	bne _08040854
_08040848:
	adds r0, r5, 0
	adds r1, r4, 0
	movs r2, 0x80
	lsls r2, 1
	bl CpuCopy
_08040854:
	adds r5, r7
	adds r4, r7
	adds r6, 0x8
	ldr r0, _08040888
	cmp r6, r0
	ble _0804083C
	ldr r1, _0804088C
	add r1, r8
	movs r0, 0x1
	strb r0, [r1]
_08040868:
	ldr r1, _08040890
	add r1, r8
	movs r0, 0
	str r0, [r1]
_08040870:
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_0804087C: .4byte gUnknown_202EE08
_08040880: .4byte 0x0001822c
_08040884: .4byte gUnknown_202EDD0
_08040888: .4byte 0x000001bf
_0804088C: .4byte 0x0001bdd2
_08040890: .4byte 0x0001bdcc
	thumb_func_end sub_8040788

	thumb_func_start sub_8040894
sub_8040894:
	push {r4-r7,lr}
	sub sp, 0x8
	ldr r0, _080409F4
	ldr r1, [r0]
	ldr r2, _080409F8
	adds r0, r1, r2
	ldrb r0, [r0]
	cmp r0, 0
	beq _080408A8
	b _08040A6A
_080408A8:
	adds r2, 0x5
	adds r0, r1, r2
	ldrb r0, [r0]
	cmp r0, 0
	bne _080408B4
	b _08040A6A
_080408B4:
	ldr r7, _080409FC
	movs r1, 0
	ldrsh r0, [r7, r1]
	cmp r0, 0x63
	ble _080408C0
	b _08040A6A
_080408C0:
	ldr r0, _08040A00
	ldrb r1, [r0]
	adds r1, 0x1
	strb r1, [r0]
	movs r0, 0x8
	ands r1, r0
	cmp r1, 0
	beq _080408D2
	b _08040A6A
_080408D2:
	movs r0, 0
	movs r1, 0
	str r0, [sp]
	str r1, [sp, 0x4]
	mov r0, sp
	ldrh r0, [r0]
	ldr r1, _08040A04
	ands r1, r0
	ldr r3, _08040A08
	ldr r0, [sp]
	ands r0, r3
	orrs r0, r1
	str r0, [sp]
	mov r1, sp
	ldrh r1, [r1]
	adds r2, r3, 0
	ands r2, r0
	orrs r2, r1
	str r2, [sp]
	mov r0, sp
	ldrh r1, [r0]
	ldr r0, _08040A0C
	ands r0, r1
	adds r1, r3, 0
	ands r1, r2
	orrs r1, r0
	str r1, [sp]
	mov r0, sp
	ldrh r0, [r0]
	adds r2, r3, 0
	ands r2, r1
	orrs r2, r0
	str r2, [sp]
	mov r0, sp
	ldrh r1, [r0]
	ldr r5, _08040A10
	adds r0, r5, 0
	ands r0, r1
	adds r1, r3, 0
	ands r1, r2
	orrs r1, r0
	str r1, [sp]
	mov r0, sp
	ldrh r0, [r0]
	adds r2, r3, 0
	ands r2, r1
	orrs r2, r0
	str r2, [sp]
	mov r0, sp
	ldrh r1, [r0]
	ldr r0, _08040A14
	ands r0, r1
	adds r1, r3, 0
	ands r1, r2
	orrs r1, r0
	str r1, [sp]
	mov r0, sp
	ldrh r0, [r0]
	adds r2, r3, 0
	ands r2, r1
	orrs r2, r0
	str r2, [sp]
	mov r0, sp
	ldrh r1, [r0]
	ldr r0, _08040A18
	ands r0, r1
	adds r1, r3, 0
	ands r1, r2
	orrs r1, r0
	str r1, [sp]
	mov r0, sp
	ldrh r0, [r0]
	adds r2, r3, 0
	ands r2, r1
	orrs r2, r0
	str r2, [sp]
	mov r0, sp
	ldrh r1, [r0]
	ldr r4, _08040A1C
	adds r0, r4, 0
	ands r0, r1
	adds r1, r3, 0
	ands r1, r2
	orrs r1, r0
	str r1, [sp]
	mov r0, sp
	ldrh r0, [r0]
	ands r3, r1
	orrs r3, r0
	str r3, [sp]
	mov r3, sp
	ldrh r0, [r3, 0x2]
	ldr r6, _08040A20
	ands r6, r0
	ands r6, r4
	strh r6, [r3, 0x2]
	ldr r2, _08040A24
	ldrh r1, [r3, 0x4]
	movs r0, 0xFC
	lsls r0, 8
	ands r0, r1
	orrs r0, r2
	ands r0, r5
	movs r5, 0xF
	lsls r1, r5, 12
	ldr r4, _08040A28
	ands r0, r4
	orrs r0, r1
	strh r0, [r3, 0x4]
	ldrh r0, [r3, 0x6]
	ldr r2, _08040A2C
	ands r2, r0
	ldr r0, _08040A30
	ands r2, r0
	strh r2, [r3, 0x6]
	ldr r0, _08040A34
	ldr r0, [r0]
	ldrb r0, [r0, 0x4]
	cmp r0, 0x6
	bne _08040A3C
	movs r1, 0
	ldrsh r0, [r7, r1]
	lsls r0, 2
	adds r0, 0x10
	ldr r1, _08040A38
	ands r0, r1
	strh r0, [r3, 0x2]
	movs r1, 0x2
	ldrsh r0, [r7, r1]
	adds r0, 0x1
	lsls r0, 2
	ands r0, r4
	lsls r0, 4
	adds r1, r2, 0
	ands r1, r5
	orrs r1, r0
	strh r1, [r3, 0x6]
	movs r1, 0x80
	lsls r1, 1
	mov r0, sp
	movs r2, 0
	movs r3, 0
	bl nullsub_11
	b _08040A6A
	.align 2, 0
_080409F4: .4byte gUnknown_203B418
_080409F8: .4byte 0x00018214
_080409FC: .4byte gUnknown_203B410
_08040A00: .4byte gUnknown_202EE02
_08040A04: .4byte 0x0000feff
_08040A08: .4byte 0xffff0000
_08040A0C: .4byte 0x0000fdff
_08040A10: .4byte 0x0000f3ff
_08040A14: .4byte 0x0000efff
_08040A18: .4byte 0x0000dfff
_08040A1C: .4byte 0x00003fff
_08040A20: .4byte 0x0000c1ff
_08040A24: .4byte 0x00000215
_08040A28: .4byte 0x00000fff
_08040A2C: .4byte 0x0000fffe
_08040A30: .4byte 0x0000fffd
_08040A34: .4byte gUnknown_203B46C
_08040A38: .4byte 0x000001ff
_08040A3C:
	movs r1, 0
	ldrsh r0, [r7, r1]
	lsls r0, 2
	adds r0, 0x8
	ldr r1, _08040A74
	ands r0, r1
	strh r0, [r3, 0x2]
	movs r1, 0x2
	ldrsh r0, [r7, r1]
	lsls r0, 2
	ands r0, r4
	lsls r0, 4
	adds r1, r2, 0
	ands r1, r5
	orrs r1, r0
	strh r1, [r3, 0x6]
	movs r1, 0x80
	lsls r1, 1
	mov r0, sp
	movs r2, 0
	movs r3, 0
	bl AddSprite
_08040A6A:
	add sp, 0x8
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_08040A74: .4byte 0x000001ff
	thumb_func_end sub_8040894

	thumb_func_start sub_8040A78
sub_8040A78:
	ldr r1, _08040A80
	movs r0, 0
	strb r0, [r1]
	bx lr
	.align 2, 0
_08040A80: .4byte gUnknown_202EE02
	thumb_func_end sub_8040A78

	thumb_func_start sub_8040A84
sub_8040A84:
	push {r4-r6,lr}
	ldr r0, _08040AB4
	ldr r0, [r0]
	ldr r1, _08040AB8
	adds r0, r1
	movs r1, 0x1
	strb r1, [r0]
	movs r5, 0
_08040A94:
	movs r4, 0
	adds r6, r5, 0x1
_08040A98:
	adds r0, r4, 0
	adds r1, r5, 0
	bl sub_80402AC
	adds r4, 0x1
	cmp r4, 0x37
	ble _08040A98
	adds r5, r6, 0
	cmp r5, 0x1F
	ble _08040A94
	pop {r4-r6}
	pop {r0}
	bx r0
	.align 2, 0
_08040AB4: .4byte gUnknown_203B418
_08040AB8: .4byte 0x0001bdd1
	thumb_func_end sub_8040A84

	thumb_func_start sub_8040ABC
sub_8040ABC:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	lsls r0, 24
	lsrs r1, r0, 24
	ldr r0, _08040AD8
	ldr r0, [r0]
	ldrb r0, [r0, 0x4]
	cmp r0, 0x6
	bne _08040ADC
	movs r7, 0xF
	movs r0, 0
	b _08040AEC
	.align 2, 0
_08040AD8: .4byte gUnknown_203B46C
_08040ADC:
	cmp r1, 0
	beq _08040AE8
	movs r7, 0xE
	movs r4, 0
	mov r8, r4
	b _08040AEE
_08040AE8:
	movs r7, 0x10
	movs r0, 0x3
_08040AEC:
	mov r8, r0
_08040AEE:
	ldr r6, _08040B58
	movs r2, 0x1
	movs r1, 0
	cmp r1, r7
	bge _08040B22
	ldr r4, _08040B5C
	mov r12, r4
_08040AFC:
	lsls r0, r2, 6
	mov r4, r12
	adds r3, r0, r4
	adds r4, r2, 0x1
	adds r5, r1, 0x1
	movs r2, 0x1B
_08040B08:
	adds r1, r6, 0
	adds r0, r1, 0x1
	lsls r0, 16
	lsrs r6, r0, 16
	strh r1, [r3]
	adds r3, 0x2
	subs r2, 0x1
	cmp r2, 0
	bge _08040B08
	adds r2, r4, 0
	adds r1, r5, 0
	cmp r1, r7
	blt _08040AFC
_08040B22:
	movs r1, 0
	cmp r1, r8
	bge _08040B4C
	ldr r6, _08040B5C
	movs r0, 0xE0
	lsls r0, 8
	adds r3, r0, 0
_08040B30:
	lsls r0, r2, 6
	adds r0, r6
	adds r4, r2, 0x1
	adds r5, r1, 0x1
	movs r2, 0x1B
_08040B3A:
	strh r3, [r0]
	adds r0, 0x2
	subs r2, 0x1
	cmp r2, 0
	bge _08040B3A
	adds r2, r4, 0
	adds r1, r5, 0
	cmp r1, r8
	blt _08040B30
_08040B4C:
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_08040B58: .4byte 0x0000e0b8
_08040B5C: .4byte gUnknown_202B03A
	thumb_func_end sub_8040ABC

	thumb_func_start sub_8040B60
sub_8040B60:
	push {r4,r5,lr}
	ldr r0, _08040BA4
	ldr r3, [r0]
	ldr r1, _08040BA8
	adds r0, r3, r1
	ldrb r0, [r0]
	cmp r0, 0
	beq _08040B9E
	movs r1, 0
	ldr r2, _08040BAC
	adds r5, r3, r2
	movs r4, 0
_08040B78:
	lsls r0, r1, 3
	adds r2, r1, 0x1
	subs r0, r1
	movs r1, 0x37
	lsls r0, 2
	adds r0, r5
	adds r0, 0x37
_08040B86:
	strb r4, [r0]
	subs r0, 0x1
	subs r1, 0x1
	cmp r1, 0
	bge _08040B86
	adds r1, r2, 0
	cmp r1, 0x1F
	ble _08040B78
	movs r1, 0
	ldr r2, _08040BA8
	adds r0, r3, r2
	strb r1, [r0]
_08040B9E:
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_08040BA4: .4byte gUnknown_203B418
_08040BA8: .4byte 0x0001bdd2
_08040BAC: .4byte 0x0001ba2c
	thumb_func_end sub_8040B60

	thumb_func_start sub_8040BB0
sub_8040BB0:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	adds r6, r0, 0
	adds r7, r1, 0
	lsls r2, 24
	lsrs r2, 24
	mov r10, r2
	bl sub_804143C
	mov r8, r0
	ldrh r4, [r7, 0x2]
	adds r0, r6, 0
	bl sub_807E580
	adds r1, r0, 0
	lsls r1, 24
	lsrs r1, 24
	adds r0, r4, 0
	mov r2, r8
	bl sub_804141C
	lsls r0, 24
	lsrs r5, r0, 24
	mov r9, r5
	ldrh r4, [r7, 0x2]
	adds r0, r6, 0
	bl sub_807E580
	adds r1, r0, 0
	lsls r1, 24
	lsrs r1, 24
	adds r0, r4, 0
	mov r2, r8
	bl sub_80412E0
	lsls r0, 16
	lsrs r0, 16
	bl sub_800ECB8
	movs r1, 0
	ldrsh r4, [r0, r1]
	adds r0, r6, 0
	bl sub_8042768
	lsls r0, 24
	cmp r0, 0
	beq _08040C28
	adds r0, r6, 0
	adds r1, r7, 0
	bl sub_80414C0
	lsls r0, 24
	cmp r0, 0
	bne _08040C28
	mov r0, r10
	cmp r0, 0
	bne _08040C2C
_08040C28:
	adds r0, r5, 0
	b _08040C3C
_08040C2C:
	cmp r4, 0
	beq _08040C3A
	adds r0, r6, 0
	adds r1, r7, 0
	mov r2, r8
	bl sub_8040C4C
_08040C3A:
	mov r0, r9
_08040C3C:
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_8040BB0

	thumb_func_start sub_8040C4C
sub_8040C4C:
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	sub sp, 0x14
	adds r7, r0, 0
	adds r4, r1, 0
	adds r6, r2, 0
	ldrh r5, [r4, 0x2]
	bl sub_807E580
	adds r1, r0, 0
	lsls r1, 24
	lsrs r1, 24
	adds r0, r5, 0
	adds r2, r6, 0
	bl sub_80412E0
	lsls r0, 16
	lsrs r0, 16
	mov r9, r0
	ldr r6, [r7, 0x70]
	ldrh r0, [r4, 0x2]
	bl sub_800EC94
	lsls r0, 24
	lsrs r0, 24
	mov r8, r0
	movs r0, 0x4
	ldrsh r5, [r6, r0]
	ldrh r4, [r4, 0x2]
	adds r0, r7, 0
	bl sub_807E580
	adds r1, r0, 0
	lsls r1, 24
	lsrs r1, 24
	adds r0, r4, 0
	movs r2, 0x1
	bl sub_80412E0
	adds r1, r0, 0
	lsls r1, 16
	lsrs r1, 16
	adds r0, r5, 0
	bl sub_800E710
	adds r2, r0, 0
	movs r0, 0x1
	negs r0, r0
	cmp r2, r0
	beq _08040CC4
	add r0, sp, 0x8
	adds r1, r7, 0
	adds r1, 0x28
	lsls r2, 24
	lsrs r2, 24
	bl sub_800569C
	b _08040CC8
_08040CC4:
	movs r0, 0
	str r0, [sp, 0x8]
_08040CC8:
	mov r0, sp
	mov r1, r9
	strh r1, [r0]
	mov r1, sp
	ldrh r0, [r6, 0x4]
	strh r0, [r1, 0x2]
	ldr r0, [r7, 0xC]
	cmp r0, 0
	bge _08040CDC
	adds r0, 0xFF
_08040CDC:
	asrs r0, 8
	strh r0, [r1, 0x4]
	mov r1, sp
	ldr r0, [r7, 0x10]
	cmp r0, 0
	bge _08040CEA
	adds r0, 0xFF
_08040CEA:
	asrs r0, 8
	strh r0, [r1, 0x6]
	adds r0, r6, 0
	adds r0, 0x46
	ldrb r0, [r0]
	str r0, [sp, 0xC]
	movs r0, 0
	str r0, [sp, 0x10]
	mov r0, sp
	bl sub_8041500
	mov r0, r9
	bl sub_800EEC8
	bl sub_800EF64
	movs r0, 0x58
	bl sub_803E46C
	mov r0, sp
	bl sub_800EA84
	adds r4, r0, 0
	adds r1, r7, 0
	movs r2, 0x5
	bl sub_8042DD4
	ldr r0, _08040D28
	ldrb r5, [r0]
	ldr r6, _08040D2C
	b _08040D78
	.align 2, 0
_08040D28: .4byte gUnknown_203B40D
_08040D2C: .4byte 0x00001010
_08040D30:
	ldr r0, _08040D58
	movs r1, 0x1
	strb r1, [r0]
	ldr r1, _08040D5C
	ldrh r2, [r1]
	movs r3, 0
	ldrsh r0, [r1, r3]
	cmp r0, r6
	beq _08040D48
	ldr r3, _08040D60
	adds r0, r2, r3
	strh r0, [r1]
_08040D48:
	ldr r1, _08040D64
	ldr r0, [r1]
	cmp r0, 0x4
	ble _08040D68
	subs r0, 0x4
	str r0, [r1]
	b _08040D6E
	.align 2, 0
_08040D58: .4byte gUnknown_203B40D
_08040D5C: .4byte gUnknown_2026E4E
_08040D60: .4byte 0x00000101
_08040D64: .4byte gUnknown_202EDC8
_08040D68:
	movs r0, 0
	str r0, [r1]
	mov r8, r0
_08040D6E:
	bl sub_803EA10
	movs r0, 0x26
	bl sub_803E46C
_08040D78:
	adds r0, r4, 0
	bl sub_800E9A8
	lsls r0, 24
	cmp r0, 0
	beq _08040D8A
	mov r0, r8
	cmp r0, 0
	bne _08040D30
_08040D8A:
	ldr r0, _08040D9C
	strb r5, [r0]
	add sp, 0x14
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_08040D9C: .4byte gUnknown_203B40D
	thumb_func_end sub_8040C4C

	thumb_func_start sub_8040DA0
sub_8040DA0:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x1C
	adds r7, r0, 0
	mov r8, r1
	bl sub_804143C
	mov r9, r0
	movs r0, 0
	str r0, [sp, 0x14]
	ldr r1, [r7, 0x70]
	mov r10, r1
	movs r0, 0x4
	ldrsh r5, [r1, r0]
	mov r1, r8
	ldrh r4, [r1, 0x2]
	adds r0, r7, 0
	bl sub_807E580
	adds r1, r0, 0
	lsls r1, 24
	lsrs r1, 24
	adds r0, r4, 0
	mov r2, r9
	bl sub_80412E0
	adds r1, r0, 0
	lsls r1, 16
	lsrs r1, 16
	adds r0, r5, 0
	bl sub_800EA44
	lsls r0, 24
	lsrs r0, 24
	str r0, [sp, 0x18]
	mov r0, sp
	adds r1, r7, 0
	mov r2, r8
	mov r3, r9
	bl sub_8041038
	mov r0, sp
	movs r1, 0x1
	bl sub_800E838
	lsls r0, 24
	cmp r0, 0
	bne _08040E0E
	mov r1, r8
	ldrh r0, [r1, 0x2]
	cmp r0, 0x52
	bne _08040E24
_08040E0E:
	ldr r0, _08040E1C
	ldr r0, [r0]
	ldr r1, _08040E20
	adds r0, r1
	ldr r6, [r0]
	b _08040E26
	.align 2, 0
_08040E1C: .4byte gUnknown_203B418
_08040E20: .4byte 0x000181f8
_08040E24:
	adds r6, r7, 0
_08040E26:
	adds r0, r6, 0
	bl sub_80450E0
	lsls r0, 24
	cmp r0, 0
	bne _08040E34
	adds r6, r7, 0
_08040E34:
	mov r1, sp
	ldr r0, [r6, 0xC]
	cmp r0, 0
	bge _08040E3E
	adds r0, 0xFF
_08040E3E:
	asrs r0, 8
	strh r0, [r1, 0x4]
	mov r1, sp
	ldr r0, [r6, 0x10]
	cmp r0, 0
	bge _08040E4C
	adds r0, 0xFF
_08040E4C:
	asrs r0, 8
	strh r0, [r1, 0x6]
	adds r0, r6, 0
	bl sub_8042768
	lsls r0, 24
	cmp r0, 0
	bne _08040E5E
	b _08041026
_08040E5E:
	adds r0, r7, 0
	mov r1, r8
	bl sub_80414C0
	lsls r0, 24
	cmp r0, 0
	beq _08040E6E
	b _08041026
_08040E6E:
	mov r0, r8
	ldrh r1, [r0, 0x2]
	movs r0, 0x94
	lsls r0, 1
	cmp r1, r0
	bne _08040ED0
	movs r0, 0x7
	bl sub_8084100
	ldr r1, _08040EB8
	str r0, [r1]
	ldr r1, _08040EBC
	ldr r2, [r1]
	ldr r1, _08040EC0
	adds r4, r2, r1
	subs r1, 0x4
	adds r2, r1
	ldr r3, _08040EC4
	lsls r1, r0, 2
	adds r1, r3
	ldr r1, [r1]
	str r1, [r2]
	str r1, [r4]
	ldr r1, _08040EC8
	adds r0, 0x4
	str r0, [r1]
	ldr r0, _08040ECC
	ldr r1, [r0]
	adds r0, r6, 0
	bl sub_80522A8
	movs r1, 0xD2
	lsls r1, 1
	adds r0, r6, 0
	bl sub_80421C0
	b _08040EF0
	.align 2, 0
_08040EB8: .4byte gUnknown_202F224
_08040EBC: .4byte gUnknown_203B418
_08040EC0: .4byte 0x00018204
_08040EC4: .4byte gUnknown_8106A8C
_08040EC8: .4byte gUnknown_202DE30
_08040ECC: .4byte gUnknown_8100224
_08040ED0:
	cmp r1, 0x76
	bne _08040EF0
	ldr r0, _08040F70
	ldr r0, [r0]
	ldr r1, _08040F74
	adds r2, r0, r1
	subs r1, 0x4
	adds r0, r1
	movs r1, 0xC
	str r1, [r0]
	str r1, [r2]
	movs r1, 0xD2
	lsls r1, 1
	adds r0, r6, 0
	bl sub_80421C0
_08040EF0:
	mov r0, r10
	movs r1, 0x4
	ldrsh r5, [r0, r1]
	mov r0, r8
	ldrh r4, [r0, 0x2]
	adds r0, r7, 0
	bl sub_807E580
	adds r1, r0, 0
	lsls r1, 24
	lsrs r1, 24
	adds r0, r4, 0
	mov r2, r9
	bl sub_80412E0
	adds r1, r0, 0
	lsls r1, 16
	lsrs r1, 16
	adds r0, r5, 0
	bl sub_800E790
	adds r1, r0, 0
	ldr r0, _08040F78
	cmp r1, r0
	beq _08040F2A
	lsls r0, r1, 16
	lsrs r0, 16
	bl sub_8083E38
_08040F2A:
	ldr r1, [sp, 0x18]
	cmp r1, 0x63
	bne _08040F7C
	adds r0, r6, 0
	bl sub_8042768
	lsls r0, 24
	cmp r0, 0
	beq _08041026
	mov r0, r10
	adds r0, 0x46
	ldrb r4, [r0]
	mov r0, sp
	adds r1, r7, 0
	mov r2, r8
	mov r3, r9
	bl sub_8041108
	movs r6, 0x7
	movs r5, 0x7
_08040F52:
	subs r4, 0x1
	ands r4, r6
	adds r0, r7, 0
	movs r1, 0
	adds r2, r4, 0
	bl sub_806CDD4
	movs r0, 0x2
	movs r1, 0x15
	bl sub_803E708
	subs r5, 0x1
	cmp r5, 0
	bge _08040F52
	b _08041026
	.align 2, 0
_08040F70: .4byte gUnknown_203B418
_08040F74: .4byte 0x00018204
_08040F78: .4byte 0x000003e5
_08040F7C:
	ldr r0, [sp, 0x18]
	cmp r0, 0x62
	bne _08040FC2
	adds r0, r6, 0
	bl sub_8042768
	lsls r0, 24
	cmp r0, 0
	beq _08041026
	mov r0, r10
	adds r0, 0x46
	ldrb r4, [r0]
	mov r0, sp
	adds r1, r7, 0
	mov r2, r8
	mov r3, r9
	bl sub_8041108
	movs r6, 0x7
	movs r5, 0x8
_08040FA4:
	ands r4, r6
	adds r0, r7, 0
	movs r1, 0
	adds r2, r4, 0
	bl sub_806CDD4
	movs r0, 0x2
	movs r1, 0x15
	bl sub_803E708
	adds r4, 0x1
	subs r5, 0x1
	cmp r5, 0
	bge _08040FA4
	b _08041026
_08040FC2:
	mov r0, r10
	adds r0, 0x46
	ldrb r2, [r0]
	adds r0, r7, 0
	ldr r1, [sp, 0x18]
	bl sub_806CDD4
	adds r0, r7, 0
	adds r0, 0x21
	movs r1, 0
	strb r1, [r0]
	movs r5, 0
	adds r6, r0, 0
	b _08040FE6
_08040FDE:
	ldrb r0, [r6]
	cmp r0, 0
	bne _08041022
	adds r5, 0x1
_08040FE6:
	cmp r5, 0x77
	bgt _08041022
	movs r0, 0x59
	bl sub_803E46C
	ldr r4, [r7, 0x40]
	ldr r1, [sp, 0x18]
	cmp r1, 0x9
	bne _08040FFC
	movs r0, 0x2
	orrs r4, r0
_08040FFC:
	movs r0, 0x2
	ands r0, r4
	cmp r0, 0
	beq _0804101A
	ldr r0, [sp, 0x14]
	cmp r0, 0
	bne _0804101A
	mov r0, sp
	adds r1, r7, 0
	mov r2, r8
	mov r3, r9
	bl sub_8041108
	movs r1, 0x1
	str r1, [sp, 0x14]
_0804101A:
	movs r0, 0x1
	ands r4, r0
	cmp r4, 0
	beq _08040FDE
_08041022:
	movs r0, 0
	strb r0, [r6]
_08041026:
	add sp, 0x1C
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_8040DA0

	thumb_func_start sub_8041038
sub_8041038:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x4
	adds r6, r0, 0
	adds r7, r1, 0
	mov r8, r2
	mov r10, r3
	ldr r0, [r7, 0x70]
	mov r9, r0
	ldrh r4, [r2, 0x2]
	adds r0, r7, 0
	bl sub_807E580
	adds r1, r0, 0
	lsls r1, 24
	lsrs r1, 24
	adds r0, r4, 0
	mov r2, r10
	bl sub_80412E0
	lsls r0, 16
	lsrs r0, 16
	str r0, [sp]
	bl sub_800ECB8
	movs r1, 0x2
	ldrsh r0, [r0, r1]
	cmp r0, 0
	beq _080410F4
	mov r0, r9
	movs r1, 0x4
	ldrsh r5, [r0, r1]
	mov r0, r8
	ldrh r4, [r0, 0x2]
	adds r0, r7, 0
	bl sub_807E580
	adds r1, r0, 0
	lsls r1, 24
	lsrs r1, 24
	adds r0, r4, 0
	mov r2, r10
	bl sub_80412E0
	adds r1, r0, 0
	lsls r1, 16
	lsrs r1, 16
	adds r0, r5, 0
	bl sub_800E710
	adds r2, r0, 0
	movs r0, 0x1
	negs r0, r0
	cmp r2, r0
	beq _080410BE
	adds r0, r6, 0
	adds r0, 0x8
	adds r1, r7, 0
	adds r1, 0x28
	lsls r2, 24
	lsrs r2, 24
	bl sub_800569C
	b _080410C2
_080410BE:
	movs r0, 0
	str r0, [r6, 0x8]
_080410C2:
	mov r1, sp
	ldrh r1, [r1]
	strh r1, [r6]
	mov r1, r9
	ldrh r0, [r1, 0x4]
	strh r0, [r6, 0x2]
	ldr r0, [r7, 0xC]
	cmp r0, 0
	bge _080410D6
	adds r0, 0xFF
_080410D6:
	asrs r0, 8
	strh r0, [r6, 0x4]
	ldr r0, [r7, 0x10]
	cmp r0, 0
	bge _080410E2
	adds r0, 0xFF
_080410E2:
	asrs r0, 8
	strh r0, [r6, 0x6]
	mov r0, r9
	adds r0, 0x46
	ldrb r0, [r0]
	str r0, [r6, 0xC]
	movs r0, 0
	str r0, [r6, 0x10]
	b _080410F6
_080410F4:
	strh r0, [r6]
_080410F6:
	add sp, 0x4
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_8041038

	thumb_func_start sub_8041108
sub_8041108:
	push {r4-r7,lr}
	adds r6, r0, 0
	adds r7, r1, 0
	adds r5, r3, 0
	ldrh r4, [r2, 0x2]
	adds r0, r7, 0
	bl sub_807E580
	adds r1, r0, 0
	lsls r1, 24
	lsrs r1, 24
	adds r0, r4, 0
	adds r2, r5, 0
	bl sub_80412E0
	lsls r0, 16
	lsrs r4, r0, 16
	adds r0, r4, 0
	bl sub_800ECB8
	movs r2, 0x2
	ldrsh r1, [r0, r2]
	ldrh r0, [r6]
	cmp r0, 0
	beq _08041162
	cmp r1, 0
	beq _08041162
	adds r0, r6, 0
	bl sub_8041500
	adds r0, r4, 0
	bl sub_800EEF8
	bl sub_800EF64
	movs r0, 0x5A
	bl sub_803E46C
	adds r0, r6, 0
	bl sub_800E52C
	adds r1, r7, 0
	movs r2, 0x1
	bl sub_8042DD4
_08041162:
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_8041108

	thumb_func_start sub_8041168
sub_8041168:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x18
	mov r8, r0
	adds r6, r1, 0
	adds r7, r2, 0
	mov r9, r3
	adds r1, r7, 0
	bl sub_804143C
	adds r5, r0, 0
	cmp r5, 0
	beq _0804118A
	movs r5, 0x1
_0804118A:
	ldrh r4, [r7, 0x2]
	mov r0, r8
	bl sub_807E580
	adds r1, r0, 0
	lsls r1, 24
	lsrs r1, 24
	adds r0, r4, 0
	adds r2, r5, 0
	bl sub_80412E0
	lsls r0, 16
	lsrs r0, 16
	mov r10, r0
	bl sub_800ECB8
	movs r1, 0x4
	ldrsh r5, [r0, r1]
	movs r2, 0
	str r2, [sp, 0x14]
	adds r0, r6, 0
	bl sub_80450E0
	lsls r0, 24
	cmp r0, 0
	beq _080411CA
	ldr r0, [r6, 0x70]
	str r0, [sp, 0x14]
	adds r0, r6, 0
	bl sub_8042768
	b _080411D0
_080411CA:
	mov r0, r9
	bl sub_803F428
_080411D0:
	lsls r0, 24
	cmp r0, 0
	beq _080412CE
	mov r0, r8
	adds r1, r7, 0
	bl sub_80414C0
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0
	bne _080412CE
	cmp r5, 0
	beq _080412CE
	adds r0, r5, 0
	bl sub_800ECA4
	ldr r5, [r0, 0x1C]
	movs r0, 0x1
	negs r0, r0
	cmp r5, r0
	beq _08041216
	adds r0, r6, 0
	bl sub_80450E0
	lsls r0, 24
	cmp r0, 0
	beq _08041216
	add r0, sp, 0x8
	adds r1, r6, 0
	adds r1, 0x28
	lsls r2, r5, 24
	lsrs r2, 24
	bl sub_800569C
	b _08041218
_08041216:
	str r4, [sp, 0x8]
_08041218:
	mov r0, sp
	mov r1, r10
	strh r1, [r0]
	ldr r2, [sp, 0x14]
	cmp r2, 0
	beq _08041248
	mov r1, sp
	ldrh r0, [r2, 0x4]
	strh r0, [r1, 0x2]
	ldr r0, [r6, 0xC]
	cmp r0, 0
	bge _08041232
	adds r0, 0xFF
_08041232:
	asrs r0, 8
	strh r0, [r1, 0x4]
	mov r1, sp
	ldr r0, [r6, 0x10]
	cmp r0, 0
	bge _08041240
	adds r0, 0xFF
_08041240:
	asrs r0, 8
	strh r0, [r1, 0x6]
	movs r0, 0
	b _0804128C
_08041248:
	mov r1, sp
	movs r0, 0x1
	strh r0, [r1, 0x2]
	mov r0, r9
	movs r2, 0
	ldrsh r1, [r0, r2]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 11
	mov r1, sp
	movs r2, 0xC0
	lsls r2, 4
	adds r0, r2
	cmp r0, 0
	bge _08041268
	adds r0, 0xFF
_08041268:
	asrs r0, 8
	strh r0, [r1, 0x4]
	mov r0, r9
	movs r2, 0x2
	ldrsh r1, [r0, r2]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 11
	mov r1, sp
	movs r2, 0x80
	lsls r2, 5
	adds r0, r2
	cmp r0, 0
	bge _08041286
	adds r0, 0xFF
_08041286:
	asrs r0, 8
	strh r0, [r1, 0x6]
	ldr r0, [sp, 0x14]
_0804128C:
	str r0, [sp, 0xC]
	movs r0, 0
	str r0, [sp, 0x10]
	mov r0, sp
	bl sub_8041500
	mov r0, r10
	bl sub_800EEE0
	bl sub_800EF64
	mov r0, sp
	bl sub_800EBC8
	adds r4, r0, 0
	movs r0, 0x5B
	bl sub_803E46C
	adds r0, r4, 0
	adds r1, r6, 0
	movs r2, 0x6
	bl sub_8042DD4
	b _080412C2
_080412BC:
	movs r0, 0x28
	bl sub_803E46C
_080412C2:
	adds r0, r4, 0
	bl sub_800E9A8
	lsls r0, 24
	cmp r0, 0
	bne _080412BC
_080412CE:
	add sp, 0x18
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_8041168

	thumb_func_start sub_80412E0
sub_80412E0:
	push {r4,lr}
	lsls r0, 16
	lsrs r4, r0, 16
	lsls r1, 24
	lsrs r0, r1, 24
	adds r3, r4, 0
	cmp r3, 0x1F
	bne _08041344
	cmp r0, 0x7
	bls _080412F6
	b _080413F6
_080412F6:
	lsls r0, 2
	ldr r1, _08041300
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08041300: .4byte _08041304
	.align 2, 0
_08041304:
	.4byte _080413F4
	.4byte _08041324
	.4byte _0804132A
	.4byte _080413F4
	.4byte _08041334
	.4byte _0804133A
	.4byte _080413F4
	.4byte _0804133A
_08041324:
	movs r3, 0xCF
	lsls r3, 1
	b _080413F6
_0804132A:
	ldr r3, _08041330
	b _080413F6
	.align 2, 0
_08041330: .4byte 0x000001a1
_08041334:
	movs r3, 0xD0
	lsls r3, 1
	b _080413F6
_0804133A:
	ldr r3, _08041340
	b _080413F6
	.align 2, 0
_08041340: .4byte 0x0000019f
_08041344:
	cmp r2, 0
	beq _080413F6
	cmp r3, 0x97
	beq _080413B4
	cmp r3, 0x97
	bgt _0804136C
	cmp r3, 0x3C
	beq _0804139C
	cmp r3, 0x3C
	bgt _08041362
	cmp r3, 0x8
	beq _08041396
	cmp r3, 0x19
	beq _080413E4
	b _080413F4
_08041362:
	cmp r3, 0x4B
	beq _080413A4
	cmp r3, 0x64
	beq _080413AA
	b _080413F4
_0804136C:
	cmp r3, 0xCD
	beq _080413CA
	cmp r3, 0xCD
	bgt _0804137E
	cmp r3, 0x99
	beq _080413BA
	cmp r3, 0x9C
	beq _080413C4
	b _080413F4
_0804137E:
	cmp r3, 0xED
	beq _080413DA
	cmp r3, 0xED
	bgt _0804138C
	cmp r3, 0xE3
	beq _080413EA
	b _080413F4
_0804138C:
	movs r0, 0xAE
	lsls r0, 1
	cmp r3, r0
	beq _080413D4
	b _080413F4
_08041396:
	movs r3, 0xD1
	lsls r3, 1
	b _080413F6
_0804139C:
	ldr r3, _080413A0
	b _080413F6
	.align 2, 0
_080413A0: .4byte 0x000001a3
_080413A4:
	movs r3, 0xD2
	lsls r3, 1
	b _080413F6
_080413AA:
	ldr r3, _080413B0
	b _080413F6
	.align 2, 0
_080413B0: .4byte 0x000001a5
_080413B4:
	movs r3, 0xD3
	lsls r3, 1
	b _080413F6
_080413BA:
	ldr r3, _080413C0
	b _080413F6
	.align 2, 0
_080413C0: .4byte 0x000001a7
_080413C4:
	movs r3, 0xD4
	lsls r3, 1
	b _080413F6
_080413CA:
	ldr r3, _080413D0
	b _080413F6
	.align 2, 0
_080413D0: .4byte 0x000001a9
_080413D4:
	movs r3, 0xD5
	lsls r3, 1
	b _080413F6
_080413DA:
	ldr r3, _080413E0
	b _080413F6
	.align 2, 0
_080413E0: .4byte 0x000001ab
_080413E4:
	movs r3, 0xD6
	lsls r3, 1
	b _080413F6
_080413EA:
	ldr r3, _080413F0
	b _080413F6
	.align 2, 0
_080413F0: .4byte 0x000001ad
_080413F4:
	adds r3, r4, 0
_080413F6:
	adds r0, r3, 0
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_80412E0

	thumb_func_start sub_8041400
sub_8041400:
	push {lr}
	lsls r0, 16
	lsrs r0, 16
	lsls r1, 24
	lsrs r1, 24
	bl sub_80412E0
	lsls r0, 16
	lsrs r0, 16
	bl sub_800ED20
	pop {r1}
	bx r1
	thumb_func_end sub_8041400

	thumb_func_start sub_804141C
sub_804141C:
	push {lr}
	lsls r0, 16
	lsrs r0, 16
	lsls r1, 24
	lsrs r1, 24
	bl sub_80412E0
	lsls r0, 16
	lsrs r0, 16
	bl sub_800EC84
	lsls r0, 24
	lsrs r0, 24
	pop {r1}
	bx r1
	thumb_func_end sub_804141C

	thumb_func_start sub_804143C
sub_804143C:
	push {r4,r5,lr}
	adds r4, r0, 0
	adds r5, r1, 0
	ldrh r0, [r5, 0x2]
	cmp r0, 0xED
	bne _08041476
	adds r0, r4, 0
	bl sub_80450E0
	lsls r0, 24
	cmp r0, 0
	beq _080414A4
	adds r0, r4, 0
	bl sub_80450F8
	cmp r0, 0x1
	bne _080414A4
	ldr r1, [r4, 0x70]
	adds r0, r1, 0
	adds r0, 0x5C
	ldrb r0, [r0]
	cmp r0, 0xE
	beq _080414A0
	adds r0, r1, 0
	adds r0, 0x5D
	ldrb r0, [r0]
	cmp r0, 0xE
	beq _080414A0
	b _0804148A
_08041476:
	cmp r0, 0x19
	beq _0804147E
	cmp r0, 0xE3
	bne _0804148E
_0804147E:
	adds r0, r4, 0
	bl sub_8070B28
	lsls r0, 24
	cmp r0, 0
	beq _080414A0
_0804148A:
	movs r0, 0
	b _080414B8
_0804148E:
	cmp r0, 0x97
	bne _080414A4
	adds r0, r4, 0
	bl sub_807E580
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _080414A4
_080414A0:
	movs r0, 0x1
	b _080414B8
_080414A4:
	adds r0, r4, 0
	adds r1, r5, 0
	bl sub_80570AC
	adds r1, r0, 0
	lsls r1, 24
	lsrs r1, 24
	negs r0, r1
	orrs r0, r1
	lsrs r0, 31
_080414B8:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_804143C

	thumb_func_start sub_80414C0
sub_80414C0:
	push {r4,r5,lr}
	adds r5, r0, 0
	adds r4, r1, 0
	ldrh r0, [r4, 0x2]
	cmp r0, 0x9C
	bne _080414DC
	adds r0, r5, 0
	bl sub_8045128
	bl sub_804AF20
	lsls r0, 24
	cmp r0, 0
	bne _080414F2
_080414DC:
	ldrh r0, [r4, 0x2]
	cmp r0, 0x8
	bne _080414F6
	adds r0, r5, 0
	bl sub_8045128
	ldrh r1, [r0]
	movs r0, 0x3
	ands r0, r1
	cmp r0, 0x1
	beq _080414F6
_080414F2:
	movs r0, 0x1
	b _080414F8
_080414F6:
	movs r0, 0
_080414F8:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_80414C0

	thumb_func_start sub_8041500
sub_8041500:
	push {lr}
	bl sub_800E7D0
	lsls r0, 24
	cmp r0, 0
	beq _08041518
	movs r0, 0x5C
	bl sub_803E46C
	movs r0, 0x5D
	bl sub_8052740
_08041518:
	pop {r0}
	bx r0
	thumb_func_end sub_8041500

	thumb_func_start sub_804151C
sub_804151C:
	push {r4-r6,lr}
	sub sp, 0x8
	adds r6, r0, 0
	adds r5, r1, 0
	lsls r4, r2, 24
	lsrs r4, 24
	adds r0, r5, 0
	bl sub_800DC9C
	adds r3, r0, 0
	lsls r3, 24
	lsrs r3, 24
	movs r0, 0x2
	str r0, [sp]
	movs r0, 0
	str r0, [sp, 0x4]
	adds r0, r6, 0
	adds r1, r5, 0
	adds r2, r4, 0
	bl sub_8041550
	add sp, 0x8
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end sub_804151C

	thumb_func_start sub_8041550
sub_8041550:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x30
	adds r7, r0, 0
	mov r10, r1
	ldr r0, [sp, 0x54]
	lsls r2, 24
	lsrs r2, 24
	str r2, [sp, 0x2C]
	lsls r3, 24
	lsrs r3, 24
	mov r9, r3
	lsls r0, 24
	lsrs r6, r0, 24
	adds r0, r7, 0
	bl sub_80450E0
	lsls r0, 24
	cmp r0, 0
	beq _0804159C
	ldr r0, [r7, 0x70]
	mov r8, r0
	adds r0, r7, 0
	bl sub_8042768
	lsls r0, 24
	cmp r0, 0
	beq _0804159C
	cmp r6, 0
	bne _080415A2
	mov r0, r8
	adds r0, 0xFF
	ldrb r0, [r0]
	cmp r0, 0x2
	bne _080415A2
_0804159C:
	movs r0, 0x1
	negs r0, r0
	b _08041692
_080415A2:
	ldr r1, [sp, 0x50]
	cmp r1, 0
	beq _080415B4
	movs r0, 0
	cmp r1, 0x2
	bne _080415B0
	movs r0, 0x1
_080415B0:
	bl sub_804178C
_080415B4:
	add r6, sp, 0x28
	adds r1, r7, 0
	adds r1, 0x28
	adds r0, r6, 0
	mov r2, r9
	bl sub_800569C
	movs r2, 0
	ldrsh r0, [r6, r2]
	cmp r0, 0x63
	beq _080415F2
	ldrh r0, [r6, 0x2]
	cmp r0, 0x63
	beq _080415F2
	movs r1, 0
	ldrsh r0, [r6, r1]
	lsls r0, 8
	ldr r1, [r7, 0xC]
	adds r4, r1, r0
	movs r2, 0x2
	ldrsh r0, [r6, r2]
	lsls r0, 8
	ldr r2, [r7, 0x10]
	adds r0, r2, r0
	movs r1, 0xBA
	lsls r1, 1
	add r1, r8
	ldr r1, [r1]
	subs r5, r0, r1
	adds r1, r2, 0
	b _08041600
_080415F2:
	ldr r4, [r7, 0xC]
	movs r0, 0xBA
	lsls r0, 1
	add r0, r8
	ldr r1, [r7, 0x10]
	ldr r0, [r0]
	subs r5, r1, r0
_08041600:
	cmp r1, 0
	bge _08041606
	adds r1, 0xFF
_08041606:
	asrs r1, 8
	ldr r0, _0804166C
	ldr r0, [r0]
	ldr r2, _08041670
	adds r0, r2
	movs r2, 0
	ldrsh r0, [r0, r2]
	subs r1, r0
	lsrs r0, r1, 31
	adds r0, r1, r0
	asrs r1, r0, 1
	adds r1, 0x1
	mov r0, r10
	str r0, [sp]
	movs r3, 0
	str r3, [sp, 0x4]
	movs r6, 0x1
	negs r6, r6
	str r6, [sp, 0x8]
	mov r2, sp
	adds r0, r4, 0
	cmp r4, 0
	bge _08041636
	adds r0, 0xFF
_08041636:
	asrs r0, 8
	strh r0, [r2, 0xC]
	mov r2, sp
	adds r0, r5, 0
	cmp r0, 0
	bge _08041644
	adds r0, 0xFF
_08041644:
	asrs r0, 8
	strh r0, [r2, 0xE]
	str r6, [sp, 0x14]
	mov r0, sp
	strh r3, [r0, 0x10]
	strh r3, [r0, 0x12]
	str r1, [sp, 0x18]
	add r0, sp, 0x1C
	bl sub_8004E8C
	mov r0, sp
	movs r1, 0
	bl sub_8041764
	adds r4, r0, 0
	ldr r1, [sp, 0x2C]
	cmp r1, 0
	beq _08041690
	movs r5, 0
	b _0804167C
	.align 2, 0
_0804166C: .4byte gUnknown_203B418
_08041670: .4byte 0x000181f2
_08041674:
	movs r0, 0x42
	bl sub_803E46C
	adds r5, 0x1
_0804167C:
	cmp r5, 0x63
	bgt _0804168C
	adds r0, r4, 0
	bl sub_800E9A8
	lsls r0, 24
	cmp r0, 0
	bne _08041674
_0804168C:
	movs r4, 0x1
	negs r4, r4
_08041690:
	adds r0, r4, 0
_08041692:
	add sp, 0x30
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_8041550

	thumb_func_start sub_80416A4
sub_80416A4:
	push {r4,lr}
	sub sp, 0x8
	lsls r2, 24
	lsrs r2, 24
	movs r3, 0
	ldrsh r4, [r0, r3]
	lsls r3, r4, 1
	adds r3, r4
	lsls r3, 11
	movs r4, 0xC0
	lsls r4, 4
	adds r3, r4
	str r3, [sp]
	movs r4, 0x2
	ldrsh r3, [r0, r4]
	lsls r0, r3, 1
	adds r0, r3
	lsls r0, 11
	movs r3, 0x80
	lsls r3, 5
	adds r0, r3
	str r0, [sp, 0x4]
	mov r0, sp
	bl sub_80416E0
	add sp, 0x8
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_80416A4

	thumb_func_start sub_80416E0
sub_80416E0:
	push {r4,r5,lr}
	sub sp, 0x28
	adds r3, r0, 0
	lsls r2, 24
	lsrs r5, r2, 24
	str r1, [sp]
	movs r2, 0
	str r2, [sp, 0x4]
	movs r4, 0x1
	negs r4, r4
	str r4, [sp, 0x8]
	mov r1, sp
	ldr r0, [r3]
	cmp r0, 0
	bge _08041700
	adds r0, 0xFF
_08041700:
	asrs r0, 8
	strh r0, [r1, 0xC]
	mov r1, sp
	ldr r0, [r3, 0x4]
	cmp r0, 0
	bge _0804170E
	adds r0, 0xFF
_0804170E:
	asrs r0, 8
	strh r0, [r1, 0xE]
	str r4, [sp, 0x14]
	mov r0, sp
	strh r2, [r0, 0x10]
	strh r2, [r0, 0x12]
	ldr r0, _08041738
	str r0, [sp, 0x18]
	add r0, sp, 0x1C
	bl sub_8004E8C
	mov r0, sp
	movs r1, 0
	bl sub_8041764
	adds r4, r0, 0
	cmp r5, 0
	beq _08041758
	movs r5, 0
	b _08041744
	.align 2, 0
_08041738: .4byte 0x0000ffff
_0804173C:
	movs r0, 0x42
	bl sub_803E46C
	adds r5, 0x1
_08041744:
	cmp r5, 0x63
	bgt _08041754
	adds r0, r4, 0
	bl sub_800E9A8
	lsls r0, 24
	cmp r0, 0
	bne _0804173C
_08041754:
	movs r4, 0x1
	negs r4, r4
_08041758:
	adds r0, r4, 0
	add sp, 0x28
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_80416E0

	thumb_func_start sub_8041764
sub_8041764:
	push {r4,r5,lr}
	adds r5, r0, 0
	lsls r4, r1, 24
	lsrs r4, 24
	ldr r0, [r5]
	bl sub_800EE5C
	bl sub_800EF64
	cmp r4, 0
	beq _08041780
	movs r0, 0x42
	bl sub_803E46C
_08041780:
	adds r0, r5, 0
	bl sub_800E890
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_8041764

	thumb_func_start sub_804178C
sub_804178C:
	push {r4-r7,lr}
	lsls r0, 24
	lsrs r5, r0, 24
	movs r4, 0
	ldr r0, _080417B0
	ldr r0, [r0]
	ldr r1, _080417B4
	adds r0, r1
	str r4, [r0]
	adds r0, r5, 0
	bl sub_800E9FC
	lsls r0, 24
	cmp r0, 0
	beq _080417E0
	ldr r6, _080417B8
	b _080417C4
	.align 2, 0
_080417B0: .4byte gUnknown_203B418
_080417B4: .4byte 0x00018204
_080417B8: .4byte 0x000003e7
_080417BC:
	movs r0, 0x4A
	bl sub_803E46C
	adds r4, 0x1
_080417C4:
	cmp r4, r6
	bgt _080417D4
	adds r0, r5, 0
	bl sub_800E9FC
	lsls r0, 24
	cmp r0, 0
	bne _080417BC
_080417D4:
	movs r0, 0x4A
	bl sub_803E46C
	movs r0, 0x4A
	bl sub_803E46C
_080417E0:
	movs r0, 0xFA
	lsls r0, 2
	cmp r4, r0
	beq _080417EC
	cmp r5, 0
	beq _080417F0
_080417EC:
	bl sub_800DBBC
_080417F0:
	ldr r2, _08041824
	ldr r0, [r2]
	cmp r0, 0x1E
	bgt _08041860
	ldr r1, _08041828
	ldrb r7, [r1]
	movs r0, 0x1
	strb r0, [r1]
	movs r4, 0
	adds r5, r2, 0
	ldr r6, _0804182C
_08041806:
	ldr r0, [r5]
	cmp r0, 0x1E
	bgt _08041838
	adds r0, 0x4
	str r0, [r5]
	ldr r1, _08041830
	ldrh r2, [r1]
	movs r3, 0
	ldrsh r0, [r1, r3]
	cmp r0, r6
	beq _0804183C
	ldr r3, _08041834
	adds r0, r2, r3
	strh r0, [r1]
	b _0804183C
	.align 2, 0
_08041824: .4byte gUnknown_202EDC8
_08041828: .4byte gUnknown_203B40D
_0804182C: .4byte 0x00000808
_08041830: .4byte gUnknown_2026E4E
_08041834: .4byte 0xfffffeff
_08041838:
	movs r0, 0x1F
	str r0, [r5]
_0804183C:
	bl sub_803EA10
	movs r0, 0x4A
	bl sub_803E46C
	ldr r0, [r5]
	cmp r0, 0x1F
	beq _08041854
	adds r4, 0x1
	ldr r0, _0804186C
	cmp r4, r0
	ble _08041806
_08041854:
	ldr r0, _08041870
	ldr r2, _08041874
	adds r1, r2, 0
	strh r1, [r0]
	ldr r0, _08041878
	strb r7, [r0]
_08041860:
	bl sub_8042E98
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_0804186C: .4byte 0x000003e7
_08041870: .4byte gUnknown_2026E4E
_08041874: .4byte 0x00000808
_08041878: .4byte gUnknown_203B40D
	thumb_func_end sub_804178C

	thumb_func_start sub_804187C
sub_804187C:
	ldr r0, [r0, 0x70]
	movs r1, 0x80
	lsls r1, 2
	adds r0, r1
	ldr r0, [r0]
	bx lr
	thumb_func_end sub_804187C

	thumb_func_start sub_8041888
sub_8041888:
	push {r4-r6,lr}
	lsls r0, 24
	lsrs r6, r0, 24
	movs r5, 0
_08041890:
	ldr r0, _080418CC
	ldr r0, [r0]
	lsls r1, r5, 2
	ldr r2, _080418D0
	adds r0, r2
	adds r0, r1
	ldr r4, [r0]
	adds r0, r4, 0
	bl sub_80450E0
	lsls r0, 24
	cmp r0, 0
	beq _080418C0
	ldr r1, [r4, 0x70]
	cmp r6, 0
	beq _080418BA
	movs r0, 0xA6
	lsls r0, 1
	adds r1, r0
	movs r0, 0x1
	strb r0, [r1]
_080418BA:
	adds r0, r4, 0
	bl sub_80418D4
_080418C0:
	adds r5, 0x1
	cmp r5, 0x13
	ble _08041890
	pop {r4-r6}
	pop {r0}
	bx r0
	.align 2, 0
_080418CC: .4byte gUnknown_203B418
_080418D0: .4byte 0x000135cc
	thumb_func_end sub_8041888

	thumb_func_start sub_80418D4
sub_80418D4:
	push {r4,lr}
	adds r4, r0, 0
	bl sub_80450E0
	lsls r0, 24
	cmp r0, 0
	bne _080418E4
	b _08041A8C
_080418E4:
	ldr r2, [r4, 0x70]
	movs r3, 0
	movs r1, 0x1
	movs r4, 0x2
	ldrsh r0, [r2, r4]
	cmp r0, 0xB9
	bne _08041902
	adds r0, r2, 0
	adds r0, 0xA9
	ldrb r0, [r0]
	movs r1, 0x7F
	eors r0, r1
	negs r1, r0
	orrs r1, r0
	lsrs r1, 31
_08041902:
	cmp r1, 0
	beq _08041914
	ldr r1, _08041A94
	adds r0, r2, 0
	adds r0, 0xA8
	ldrb r0, [r0]
	lsls r0, 2
	adds r0, r1
	ldr r3, [r0]
_08041914:
	ldr r1, _08041A98
	adds r0, r2, 0
	adds r0, 0xAC
	ldrb r0, [r0]
	lsls r0, 2
	adds r0, r1
	ldr r0, [r0]
	orrs r3, r0
	ldr r1, _08041A9C
	adds r0, r2, 0
	adds r0, 0xB0
	ldrb r0, [r0]
	lsls r0, 2
	adds r0, r1
	ldr r0, [r0]
	orrs r3, r0
	ldr r1, _08041AA0
	adds r0, r2, 0
	adds r0, 0xBC
	ldrb r0, [r0]
	lsls r0, 2
	adds r0, r1
	ldr r0, [r0]
	orrs r3, r0
	ldr r1, _08041AA4
	adds r0, r2, 0
	adds r0, 0xC0
	ldrb r0, [r0]
	lsls r0, 2
	adds r0, r1
	ldr r0, [r0]
	orrs r3, r0
	ldr r1, _08041AA8
	adds r0, r2, 0
	adds r0, 0xC4
	ldrb r0, [r0]
	lsls r0, 2
	adds r0, r1
	ldr r0, [r0]
	orrs r3, r0
	ldr r1, _08041AAC
	adds r0, r2, 0
	adds r0, 0xC8
	ldrb r0, [r0]
	lsls r0, 2
	adds r0, r1
	ldr r0, [r0]
	orrs r3, r0
	ldr r1, _08041AB0
	adds r0, r2, 0
	adds r0, 0xD0
	ldrb r0, [r0]
	lsls r0, 2
	adds r0, r1
	ldr r0, [r0]
	orrs r3, r0
	ldr r1, _08041AB4
	adds r0, r2, 0
	adds r0, 0xDC
	ldrb r0, [r0]
	lsls r0, 2
	adds r0, r1
	ldr r0, [r0]
	orrs r3, r0
	ldr r1, _08041AB8
	adds r0, r2, 0
	adds r0, 0xE0
	ldrb r0, [r0]
	lsls r0, 2
	adds r0, r1
	ldr r0, [r0]
	orrs r3, r0
	ldr r1, _08041ABC
	adds r0, r2, 0
	adds r0, 0xE4
	ldrb r0, [r0]
	lsls r0, 2
	adds r0, r1
	ldr r0, [r0]
	orrs r3, r0
	ldr r1, _08041AC0
	adds r0, r2, 0
	adds r0, 0xE8
	ldrb r0, [r0]
	lsls r0, 2
	adds r0, r1
	ldr r0, [r0]
	orrs r3, r0
	ldr r1, _08041AC4
	adds r0, r2, 0
	adds r0, 0xEC
	ldrb r0, [r0]
	lsls r0, 2
	adds r0, r1
	ldr r0, [r0]
	orrs r3, r0
	adds r0, r2, 0
	adds r0, 0xF4
	ldrb r0, [r0]
	cmp r0, 0
	beq _080419E4
	movs r0, 0x80
	lsls r0, 17
	orrs r3, r0
_080419E4:
	adds r0, r2, 0
	adds r0, 0xF5
	ldrb r0, [r0]
	cmp r0, 0
	beq _080419F4
	movs r0, 0x80
	lsls r0, 18
	orrs r3, r0
_080419F4:
	ldrb r0, [r2, 0x6]
	cmp r0, 0
	bne _08041A14
	movs r0, 0x10
	ldrsh r1, [r2, r0]
	cmp r1, 0
	bge _08041A04
	adds r1, 0x3
_08041A04:
	asrs r1, 2
	movs r4, 0xE
	ldrsh r0, [r2, r4]
	cmp r1, r0
	ble _08041A14
	movs r0, 0x80
	lsls r0, 6
	orrs r3, r0
_08041A14:
	ldr r0, _08041AC8
	ldr r0, [r0]
	ldr r1, _08041ACC
	adds r0, r1
	ldrb r0, [r0]
	cmp r0, 0
	beq _08041A36
	adds r0, r2, 0
	adds r0, 0x60
	ldrb r1, [r0]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _08041A36
	movs r0, 0x80
	lsls r0, 6
	orrs r3, r0
_08041A36:
	ldr r0, [r2, 0x2C]
	cmp r0, 0xFF
	ble _08041A7E
	ldr r0, [r2, 0x30]
	cmp r0, 0xFF
	ble _08041A7E
	ldr r0, [r2, 0x34]
	cmp r0, 0xFF
	ble _08041A7E
	ldr r0, [r2, 0x38]
	cmp r0, 0xFF
	ble _08041A7E
	movs r4, 0x1C
	ldrsh r0, [r2, r4]
	cmp r0, 0x9
	ble _08041A7E
	movs r1, 0x1E
	ldrsh r0, [r2, r1]
	cmp r0, 0x9
	ble _08041A7E
	movs r4, 0x20
	ldrsh r0, [r2, r4]
	cmp r0, 0x9
	ble _08041A7E
	movs r1, 0x22
	ldrsh r0, [r2, r1]
	cmp r0, 0x9
	ble _08041A7E
	movs r4, 0x24
	ldrsh r0, [r2, r4]
	cmp r0, 0x9
	ble _08041A7E
	movs r1, 0x26
	ldrsh r0, [r2, r1]
	cmp r0, 0x9
	bgt _08041A84
_08041A7E:
	movs r0, 0x80
	lsls r0, 20
	orrs r3, r0
_08041A84:
	movs r4, 0x80
	lsls r4, 2
	adds r0, r2, r4
	str r3, [r0]
_08041A8C:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08041A94: .4byte gUnknown_80F669C
_08041A98: .4byte gUnknown_80F66B4
_08041A9C: .4byte gUnknown_80F66C8
_08041AA0: .4byte gUnknown_80F66E8
_08041AA4: .4byte gUnknown_80F6708
_08041AA8: .4byte gUnknown_80F673C
_08041AAC: .4byte gUnknown_80F6778
_08041AB0: .4byte gUnknown_80F6788
_08041AB4: .4byte gUnknown_80F6794
_08041AB8: .4byte gUnknown_80F67A8
_08041ABC: .4byte gUnknown_80F67B4
_08041AC0: .4byte gUnknown_80F67C4
_08041AC4: .4byte gUnknown_80F67D4
_08041AC8: .4byte gUnknown_203B418
_08041ACC: .4byte 0x00000676
	thumb_func_end sub_80418D4

	thumb_func_start sub_8041AD0
sub_8041AD0:
	push {lr}
	movs r1, 0xA2
	lsls r1, 1
	movs r2, 0x1
	bl sub_804151C
	pop {r0}
	bx r0
	thumb_func_end sub_8041AD0

	thumb_func_start sub_8041AE0
sub_8041AE0:
	push {lr}
	ldr r1, _08041AF0
	movs r2, 0x1
	bl sub_804151C
	pop {r0}
	bx r0
	.align 2, 0
_08041AF0: .4byte 0x00000143
	thumb_func_end sub_8041AE0

	thumb_func_start sub_8041AF4
sub_8041AF4:
	push {r4,lr}
	adds r4, r0, 0
	movs r1, 0x25
	movs r2, 0x1
	bl sub_804151C
	ldr r1, _08041B10
	adds r0, r4, 0
	bl sub_80421C0
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08041B10: .4byte 0x00000197
	thumb_func_end sub_8041AF4

	thumb_func_start nullsub_57
nullsub_57:
	bx lr
	thumb_func_end nullsub_57

	thumb_func_start sub_8041B18
sub_8041B18:
	push {lr}
	ldr r1, _08041B28
	movs r2, 0x1
	bl sub_804151C
	pop {r0}
	bx r0
	.align 2, 0
_08041B28: .4byte 0x00000141
	thumb_func_end sub_8041B18

	thumb_func_start nullsub_58
nullsub_58:
	bx lr
	thumb_func_end nullsub_58

	thumb_func_start nullsub_59
nullsub_59:
	bx lr
	thumb_func_end nullsub_59

	thumb_func_start sub_8041B34
sub_8041B34:
	push {lr}
	movs r1, 0x7
	movs r2, 0x1
	bl sub_804151C
	pop {r0}
	bx r0
	thumb_func_end sub_8041B34

	thumb_func_start nullsub_60
nullsub_60:
	bx lr
	thumb_func_end nullsub_60

	thumb_func_start sub_8041B48
sub_8041B48:
	push {lr}
	movs r1, 0x4
	movs r2, 0
	bl sub_804151C
	pop {r0}
	bx r0
	thumb_func_end sub_8041B48

	thumb_func_start nullsub_61
nullsub_61:
	bx lr
	thumb_func_end nullsub_61

	thumb_func_start sub_8041B5C
sub_8041B5C:
	push {lr}
	ldr r1, _08041B6C
	movs r2, 0x1
	bl sub_804151C
	pop {r0}
	bx r0
	.align 2, 0
_08041B6C: .4byte 0x00000171
	thumb_func_end sub_8041B5C

	thumb_func_start nullsub_62
nullsub_62:
	bx lr
	thumb_func_end nullsub_62

	thumb_func_start sub_8041B74
sub_8041B74:
	push {lr}
	ldr r1, _08041B84
	movs r2, 0
	bl sub_804151C
	pop {r0}
	bx r0
	.align 2, 0
_08041B84: .4byte 0x00000171
	thumb_func_end sub_8041B74

	thumb_func_start nullsub_63
nullsub_63:
	bx lr
	thumb_func_end nullsub_63

	thumb_func_start nullsub_64
nullsub_64:
	bx lr
	thumb_func_end nullsub_64

	thumb_func_start sub_8041B90
sub_8041B90:
	push {lr}
	movs r1, 0xD6
	lsls r1, 1
	movs r2, 0
	bl sub_804151C
	pop {r0}
	bx r0
	thumb_func_end sub_8041B90

	thumb_func_start nullsub_65
nullsub_65:
	bx lr
	thumb_func_end nullsub_65

	thumb_func_start nullsub_66
nullsub_66:
	bx lr
	thumb_func_end nullsub_66

	thumb_func_start sub_8041BA8
sub_8041BA8:
	push {lr}
	movs r1, 0x4
	movs r2, 0x1
	bl sub_804151C
	pop {r0}
	bx r0
	thumb_func_end sub_8041BA8

	thumb_func_start nullsub_67
nullsub_67:
	bx lr
	thumb_func_end nullsub_67

	thumb_func_start sub_8041BBC
sub_8041BBC:
	push {lr}
	movs r1, 0xD4
	lsls r1, 1
	movs r2, 0x1
	bl sub_804151C
	pop {r0}
	bx r0
	thumb_func_end sub_8041BBC

	thumb_func_start nullsub_68
nullsub_68:
	bx lr
	thumb_func_end nullsub_68

	thumb_func_start sub_8041BD0
sub_8041BD0:
	push {lr}
	lsls r1, 24
	cmp r1, 0
	beq _08041BDE
	ldr r1, _08041BE4
	bl sub_80421C0
_08041BDE:
	pop {r0}
	bx r0
	.align 2, 0
_08041BE4: .4byte 0x000001a5
	thumb_func_end sub_8041BD0

	thumb_func_start sub_8041BE8
sub_8041BE8:
	push {lr}
	movs r1, 0xCB
	lsls r1, 1
	bl sub_80421C0
	pop {r0}
	bx r0
	thumb_func_end sub_8041BE8

	thumb_func_start sub_8041BF8
sub_8041BF8:
	push {lr}
	movs r1, 0xA
	movs r2, 0x8
	bl sub_806CDD4
	pop {r0}
	bx r0
	thumb_func_end sub_8041BF8

	thumb_func_start sub_8041C08
sub_8041C08:
	push {lr}
	ldr r1, _08041C18
	movs r2, 0x1
	bl sub_804151C
	pop {r0}
	bx r0
	.align 2, 0
_08041C18: .4byte 0x000001a7
	thumb_func_end sub_8041C08

	thumb_func_start sub_8041C1C
sub_8041C1C:
	push {lr}
	ldr r1, _08041C2C
	movs r2, 0x1
	bl sub_804151C
	pop {r0}
	bx r0
	.align 2, 0
_08041C2C: .4byte 0x000001a7
	thumb_func_end sub_8041C1C

	thumb_func_start nullsub_69
nullsub_69:
	bx lr
	thumb_func_end nullsub_69

	thumb_func_start sub_8041C34
sub_8041C34:
	push {lr}
	movs r1, 0x4C
	movs r2, 0x1
	bl sub_804151C
	pop {r0}
	bx r0
	thumb_func_end sub_8041C34

	thumb_func_start nullsub_70
nullsub_70:
	bx lr
	thumb_func_end nullsub_70

	thumb_func_start nullsub_71
nullsub_71:
	bx lr
	thumb_func_end nullsub_71

	thumb_func_start sub_8041C4C
sub_8041C4C:
	push {lr}
	movs r2, 0x1
	bl sub_804151C
	pop {r0}
	bx r0
	thumb_func_end sub_8041C4C

	thumb_func_start sub_8041C58
sub_8041C58:
	push {lr}
	ldr r1, _08041C68
	movs r2, 0x1
	bl sub_804151C
	pop {r0}
	bx r0
	.align 2, 0
_08041C68: .4byte 0x000001a9
	thumb_func_end sub_8041C58

	thumb_func_start sub_8041C6C
sub_8041C6C:
	push {lr}
	movs r1, 0x9D
	lsls r1, 1
	movs r2, 0x1
	bl sub_804151C
	pop {r0}
	bx r0
	thumb_func_end sub_8041C6C

	thumb_func_start sub_8041C7C
sub_8041C7C:
	push {lr}
	movs r1, 0x9D
	lsls r1, 1
	movs r2, 0x1
	bl sub_804151C
	pop {r0}
	bx r0
	thumb_func_end sub_8041C7C

	thumb_func_start nullsub_72
nullsub_72:
	bx lr
	thumb_func_end nullsub_72

	thumb_func_start nullsub_73
nullsub_73:
	bx lr
	thumb_func_end nullsub_73

	thumb_func_start sub_8041C94
sub_8041C94:
	push {lr}
	ldr r1, _08041CA4
	movs r2, 0x1
	bl sub_804151C
	pop {r0}
	bx r0
	.align 2, 0
_08041CA4: .4byte 0x00000171
	thumb_func_end sub_8041C94

	thumb_func_start sub_8041CA8
sub_8041CA8:
	push {lr}
	movs r1, 0x7
	movs r2, 0x1
	bl sub_804151C
	pop {r0}
	bx r0
	thumb_func_end sub_8041CA8

	thumb_func_start sub_8041CB8
sub_8041CB8:
	push {lr}
	ldr r1, _08041CC8
	movs r2, 0x1
	bl sub_804151C
	pop {r0}
	bx r0
	.align 2, 0
_08041CC8: .4byte 0x0000018b
	thumb_func_end sub_8041CB8

	thumb_func_start sub_8041CCC
sub_8041CCC:
	push {lr}
	movs r1, 0xC5
	lsls r1, 1
	movs r2, 0x1
	bl sub_804151C
	pop {r0}
	bx r0
	thumb_func_end sub_8041CCC

	thumb_func_start sub_8041CDC
sub_8041CDC:
	push {lr}
	movs r1, 0x5
	movs r2, 0x1
	bl sub_804151C
	pop {r0}
	bx r0
	thumb_func_end sub_8041CDC

	thumb_func_start sub_8041CEC
sub_8041CEC:
	push {lr}
	ldr r1, _08041CF8
	bl sub_80421C0
	pop {r0}
	bx r0
	.align 2, 0
_08041CF8: .4byte 0x0000019d
	thumb_func_end sub_8041CEC

	thumb_func_start nullsub_74
nullsub_74:
	bx lr
	thumb_func_end nullsub_74

	thumb_func_start sub_8041D00
sub_8041D00:
	push {r4,lr}
	adds r4, r0, 0
	adds r0, r1, 0
	movs r1, 0x2F
	movs r2, 0x1
	bl sub_804151C
	adds r0, r4, 0
	movs r1, 0x30
	movs r2, 0x1
	bl sub_804151C
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_8041D00

	thumb_func_start nullsub_75
nullsub_75:
	bx lr
	thumb_func_end nullsub_75

	thumb_func_start nullsub_76
nullsub_76:
	bx lr
	thumb_func_end nullsub_76

	thumb_func_start nullsub_77
nullsub_77:
	bx lr
	thumb_func_end nullsub_77

	thumb_func_start nullsub_78
nullsub_78:
	bx lr
	thumb_func_end nullsub_78

	thumb_func_start nullsub_79
nullsub_79:
	bx lr
	thumb_func_end nullsub_79

	thumb_func_start nullsub_80
nullsub_80:
	bx lr
	thumb_func_end nullsub_80

	thumb_func_start sub_8041D38
sub_8041D38:
	push {lr}
	movs r1, 0x21
	movs r2, 0x1
	bl sub_804151C
	pop {r0}
	bx r0
	thumb_func_end sub_8041D38

	thumb_func_start sub_8041D48
sub_8041D48:
	push {lr}
	ldr r1, _08041D54
	bl sub_80421C0
	pop {r0}
	bx r0
	.align 2, 0
_08041D54: .4byte 0x00000191
	thumb_func_end sub_8041D48

	thumb_func_start nullsub_81
nullsub_81:
	bx lr
	thumb_func_end nullsub_81

	thumb_func_start sub_8041D5C
sub_8041D5C:
	push {r4,lr}
	adds r4, r0, 0
	bl sub_8042768
	lsls r0, 24
	cmp r0, 0
	beq _08041D7E
	ldr r0, [r4, 0x70]
	movs r1, 0x89
	lsls r1, 1
	adds r0, r1
	ldrb r0, [r0]
	adds r1, r4, 0
	movs r2, 0x1
	movs r3, 0xB
	bl sub_803ED30
_08041D7E:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_8041D5C

	thumb_func_start sub_8041D84
sub_8041D84:
	push {lr}
	ldr r1, _08041D90
	bl sub_80421C0
	pop {r0}
	bx r0
	.align 2, 0
_08041D90: .4byte 0x0000019f
	thumb_func_end sub_8041D84

	thumb_func_start nullsub_82
nullsub_82:
	bx lr
	thumb_func_end nullsub_82

	thumb_func_start nullsub_83
nullsub_83:
	bx lr
	thumb_func_end nullsub_83

	thumb_func_start sub_8041D9C
sub_8041D9C:
	push {lr}
	ldr r1, _08041DAC
	movs r2, 0x1
	bl sub_804151C
	pop {r0}
	bx r0
	.align 2, 0
_08041DAC: .4byte 0x00000131
	thumb_func_end sub_8041D9C

	thumb_func_start sub_8041DB0
sub_8041DB0:
	push {lr}
	movs r1, 0x30
	movs r2, 0x1
	bl sub_804151C
	pop {r0}
	bx r0
	thumb_func_end sub_8041DB0

	thumb_func_start nullsub_84
nullsub_84:
	bx lr
	thumb_func_end nullsub_84

	thumb_func_start nullsub_85
nullsub_85:
	bx lr
	thumb_func_end nullsub_85

	thumb_func_start nullsub_204
nullsub_204:
	bx lr
	thumb_func_end nullsub_204

	thumb_func_start nullsub_86
nullsub_86:
	bx lr
	thumb_func_end nullsub_86

	thumb_func_start nullsub_87
nullsub_87:
	bx lr
	thumb_func_end nullsub_87

	thumb_func_start nullsub_88
nullsub_88:
	bx lr
	thumb_func_end nullsub_88

	thumb_func_start sub_8041DD8
sub_8041DD8:
	push {r4,r5,lr}
	adds r4, r0, 0
	lsls r1, 16
	asrs r5, r1, 16
	movs r1, 0xE
	bl sub_8071858
	lsls r0, 24
	cmp r0, 0
	beq _08041DF8
	adds r0, r4, 0
	adds r1, r5, 0
	movs r2, 0x1
	bl sub_804151C
	b _08041E02
_08041DF8:
	adds r0, r4, 0
	movs r1, 0xE
	movs r2, 0x1
	bl sub_804151C
_08041E02:
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_8041DD8

	thumb_func_start nullsub_89
nullsub_89:
	bx lr
	thumb_func_end nullsub_89

	thumb_func_start sub_8041E0C
sub_8041E0C:
	push {lr}
	movs r1, 0x41
	movs r2, 0x1
	bl sub_804151C
	pop {r0}
	bx r0
	thumb_func_end sub_8041E0C

	thumb_func_start sub_8041E1C
sub_8041E1C:
	push {r4,lr}
	adds r4, r0, 0
	movs r1, 0x8F
	lsls r1, 1
	movs r2, 0x1
	bl sub_804151C
	movs r1, 0xCE
	lsls r1, 1
	adds r0, r4, 0
	bl sub_80421C0
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_8041E1C

	thumb_func_start sub_8041E3C
sub_8041E3C:
	push {lr}
	movs r1, 0xD7
	lsls r1, 1
	movs r2, 0x1
	bl sub_804151C
	pop {r0}
	bx r0
	thumb_func_end sub_8041E3C

	thumb_func_start sub_8041E4C
sub_8041E4C:
	push {lr}
	ldr r1, _08041E5C
	movs r2, 0x1
	bl sub_804151C
	pop {r0}
	bx r0
	.align 2, 0
_08041E5C: .4byte 0x000001b1
	thumb_func_end sub_8041E4C

	thumb_func_start sub_8041E60
sub_8041E60:
	push {lr}
	ldr r1, _08041E70
	movs r2, 0x1
	bl sub_804151C
	pop {r0}
	bx r0
	.align 2, 0
_08041E70: .4byte 0x000001a9
	thumb_func_end sub_8041E60

	thumb_func_start sub_8041E74
sub_8041E74:
	push {lr}
	movs r1, 0xC9
	lsls r1, 1
	movs r2, 0x1
	bl sub_804151C
	pop {r0}
	bx r0
	thumb_func_end sub_8041E74

	thumb_func_start sub_8041E84
sub_8041E84:
	push {lr}
	movs r1, 0xC7
	lsls r1, 1
	movs r2, 0x1
	bl sub_804151C
	pop {r0}
	bx r0
	thumb_func_end sub_8041E84

	thumb_func_start sub_8041E94
sub_8041E94:
	push {lr}
	movs r1, 0xC8
	lsls r1, 1
	movs r2, 0x1
	bl sub_804151C
	pop {r0}
	bx r0
	thumb_func_end sub_8041E94

	thumb_func_start sub_8041EA4
sub_8041EA4:
	push {lr}
	movs r1, 0x15
	movs r2, 0x1
	bl sub_804151C
	pop {r0}
	bx r0
	thumb_func_end sub_8041EA4

	thumb_func_start sub_8041EB4
sub_8041EB4:
	push {lr}
	ldr r1, _08041EC4
	movs r2, 0x1
	bl sub_804151C
	pop {r0}
	bx r0
	.align 2, 0
_08041EC4: .4byte 0x00000171
	thumb_func_end sub_8041EB4

	thumb_func_start sub_8041EC8
sub_8041EC8:
	push {lr}
	ldr r1, _08041ED4
	bl sub_80421C0
	pop {r0}
	bx r0
	.align 2, 0
_08041ED4: .4byte 0x00000197
	thumb_func_end sub_8041EC8

	thumb_func_start sub_8041ED8
sub_8041ED8:
	push {lr}
	ldr r1, _08041EE4
	bl sub_80421C0
	pop {r0}
	bx r0
	.align 2, 0
_08041EE4: .4byte 0x00000197
	thumb_func_end sub_8041ED8

	thumb_func_start sub_8041EE8
sub_8041EE8:
	push {lr}
	movs r1, 0x15
	movs r2, 0x1
	bl sub_804151C
	pop {r0}
	bx r0
	thumb_func_end sub_8041EE8

	thumb_func_start sub_8041EF8
sub_8041EF8:
	push {lr}
	movs r1, 0xF
	movs r2, 0x1
	bl sub_804151C
	pop {r0}
	bx r0
	thumb_func_end sub_8041EF8

	thumb_func_start sub_8041F08
sub_8041F08:
	push {lr}
	sub sp, 0x8
	movs r1, 0x2
	str r1, [sp]
	movs r1, 0
	str r1, [sp, 0x4]
	movs r1, 0x15
	movs r2, 0x1
	movs r3, 0x3
	bl sub_8041550
	add sp, 0x8
	pop {r0}
	bx r0
	thumb_func_end sub_8041F08

	thumb_func_start nullsub_90
nullsub_90:
	bx lr
	thumb_func_end nullsub_90

	thumb_func_start sub_8041F28
sub_8041F28:
	push {lr}
	cmp r1, 0
	bne _08041F3A
	movs r1, 0xCA
	lsls r1, 1
	movs r2, 0x1
	bl sub_804151C
	b _08041F42
_08041F3A:
	ldr r1, _08041F48
	movs r2, 0x1
	bl sub_804151C
_08041F42:
	pop {r0}
	bx r0
	.align 2, 0
_08041F48: .4byte 0x00000193
	thumb_func_end sub_8041F28

	thumb_func_start sub_8041F4C
sub_8041F4C:
	push {lr}
	cmp r1, 0
	bne _08041F60
	ldr r1, _08041F5C
	movs r2, 0x1
	bl sub_804151C
	b _08041F68
	.align 2, 0
_08041F5C: .4byte 0x0000018f
_08041F60:
	ldr r1, _08041F6C
	movs r2, 0x1
	bl sub_804151C
_08041F68:
	pop {r0}
	bx r0
	.align 2, 0
_08041F6C: .4byte 0x00000191
	thumb_func_end sub_8041F4C

	thumb_func_start sub_8041F70
sub_8041F70:
	push {lr}
	cmp r1, 0
	bne _08041F84
	ldr r1, _08041F80
	movs r2, 0x1
	bl sub_804151C
	b _08041F8E
	.align 2, 0
_08041F80: .4byte 0x000001a9
_08041F84:
	movs r1, 0xC9
	lsls r1, 1
	movs r2, 0x1
	bl sub_804151C
_08041F8E:
	pop {r0}
	bx r0
	thumb_func_end sub_8041F70

	thumb_func_start sub_8041F94
sub_8041F94:
	push {lr}
	cmp r1, 0
	bne _08041FA6
	movs r1, 0xC7
	lsls r1, 1
	movs r2, 0x1
	bl sub_804151C
	b _08041FB0
_08041FA6:
	movs r1, 0xC8
	lsls r1, 1
	movs r2, 0x1
	bl sub_804151C
_08041FB0:
	pop {r0}
	bx r0
	thumb_func_end sub_8041F94

	thumb_func_start sub_8041FB4
sub_8041FB4:
	push {lr}
	cmp r1, 0
	bne _08041FC8
	ldr r1, _08041FC4
	movs r2, 0x1
	bl sub_804151C
	b _08041FD2
	.align 2, 0
_08041FC4: .4byte 0x000001a9
_08041FC8:
	movs r1, 0xC9
	lsls r1, 1
	movs r2, 0x1
	bl sub_804151C
_08041FD2:
	pop {r0}
	bx r0
	thumb_func_end sub_8041FB4

	thumb_func_start sub_8041FD8
sub_8041FD8:
	push {lr}
	cmp r1, 0
	bne _08041FEA
	movs r1, 0xCA
	lsls r1, 1
	movs r2, 0x1
	bl sub_804151C
	b _08041FF2
_08041FEA:
	ldr r1, _08041FF8
	movs r2, 0x1
	bl sub_804151C
_08041FF2:
	pop {r0}
	bx r0
	.align 2, 0
_08041FF8: .4byte 0x00000193
	thumb_func_end sub_8041FD8

	thumb_func_start sub_8041FFC
sub_8041FFC:
	push {lr}
	cmp r1, 0
	bne _0804200E
	movs r1, 0xC7
	lsls r1, 1
	movs r2, 0x1
	bl sub_804151C
	b _08042018
_0804200E:
	movs r1, 0xC8
	lsls r1, 1
	movs r2, 0x1
	bl sub_804151C
_08042018:
	pop {r0}
	bx r0
	thumb_func_end sub_8041FFC

	thumb_func_start sub_804201C
sub_804201C:
	push {lr}
	cmp r1, 0
	bne _08042030
	ldr r1, _0804202C
	movs r2, 0x1
	bl sub_804151C
	b _08042038
	.align 2, 0
_0804202C: .4byte 0x0000018f
_08042030:
	ldr r1, _0804203C
	movs r2, 0x1
	bl sub_804151C
_08042038:
	pop {r0}
	bx r0
	.align 2, 0
_0804203C: .4byte 0x00000191
	thumb_func_end sub_804201C

	thumb_func_start sub_8042040
sub_8042040:
	push {lr}
	cmp r1, 0
	bne _08042052
	movs r1, 0xC6
	lsls r1, 1
	movs r2, 0x1
	bl sub_804151C
	b _0804205A
_08042052:
	movs r1, 0xD
	movs r2, 0x1
	bl sub_804151C
_0804205A:
	pop {r0}
	bx r0
	thumb_func_end sub_8042040

	thumb_func_start sub_8042060
sub_8042060:
	push {lr}
	cmp r1, 0
	bne _08042074
	ldr r1, _08042070
	movs r2, 0x1
	bl sub_804151C
	b _0804207C
	.align 2, 0
_08042070: .4byte 0x0000018d
_08042074:
	movs r1, 0xE
	movs r2, 0x1
	bl sub_804151C
_0804207C:
	pop {r0}
	bx r0
	thumb_func_end sub_8042060

	thumb_func_start sub_8042080
sub_8042080:
	push {lr}
	cmp r1, 0
	bne _08042092
	movs r1, 0xC6
	lsls r1, 1
	movs r2, 0x1
	bl sub_804151C
	b _0804209A
_08042092:
	movs r1, 0xD
	movs r2, 0x1
	bl sub_804151C
_0804209A:
	pop {r0}
	bx r0
	thumb_func_end sub_8042080

	thumb_func_start sub_80420A0
sub_80420A0:
	push {lr}
	ldr r1, _080420B0
	movs r2, 0x1
	bl sub_804151C
	pop {r0}
	bx r0
	.align 2, 0
_080420B0: .4byte 0x00000143
	thumb_func_end sub_80420A0

	thumb_func_start nullsub_91
nullsub_91:
	bx lr
	thumb_func_end nullsub_91

	thumb_func_start sub_80420B8
sub_80420B8:
	push {lr}
	movs r1, 0x19
	movs r2, 0x1
	bl sub_804151C
	pop {r0}
	bx r0
	thumb_func_end sub_80420B8

	thumb_func_start sub_80420C8
sub_80420C8:
	push {lr}
	sub sp, 0x8
	movs r1, 0x2
	str r1, [sp]
	movs r1, 0
	str r1, [sp, 0x4]
	movs r1, 0x15
	movs r2, 0x1
	movs r3, 0x3
	bl sub_8041550
	add sp, 0x8
	pop {r0}
	bx r0
	thumb_func_end sub_80420C8

	thumb_func_start nullsub_92
nullsub_92:
	bx lr
	thumb_func_end nullsub_92

	thumb_func_start sub_80420E8
sub_80420E8:
	push {r4,lr}
	sub sp, 0x8
	adds r4, r0, 0
	ldr r1, [r1, 0x8]
	ldr r0, _0804211C
	ldr r0, [r0]
	ldr r2, _08042120
	adds r0, r2
	ldrb r0, [r0]
	cmp r0, 0
	beq _08042106
	adds r0, r1, 0
	bl sub_806F62C
	adds r1, r0, 0
_08042106:
	cmp r1, 0x1
	beq _08042124
	cmp r1, 0x1
	bcc _08042116
	cmp r1, 0x2
	beq _08042128
	cmp r1, 0x3
	beq _0804212C
_08042116:
	movs r1, 0x8
	b _0804212E
	.align 2, 0
_0804211C: .4byte gUnknown_203B418
_08042120: .4byte 0x0000016d
_08042124:
	movs r1, 0x9
	b _0804212E
_08042128:
	movs r1, 0xA
	b _0804212E
_0804212C:
	movs r1, 0xB
_0804212E:
	movs r0, 0
	str r0, [sp]
	movs r0, 0x1
	str r0, [sp, 0x4]
	adds r0, r4, 0
	movs r2, 0x1
	movs r3, 0x3
	bl sub_8041550
	add sp, 0x8
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_80420E8

	thumb_func_start sub_8042148
sub_8042148:
	push {r4,lr}
	adds r4, r0, 0
	ldr r1, _08042164
	bl sub_80421C0
	movs r1, 0x9F
	lsls r1, 1
	adds r0, r4, 0
	movs r2, 0x1
	bl sub_804151C
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08042164: .4byte 0x000001a7
	thumb_func_end sub_8042148

	thumb_func_start nullsub_93
nullsub_93:
	bx lr
	thumb_func_end nullsub_93

	thumb_func_start sub_804216C
sub_804216C:
	push {lr}
	adds r0, r1, 0
	cmp r2, 0x1
	bne _0804217E
	movs r1, 0xF8
	movs r2, 0x1
	bl sub_804151C
	b _08042186
_0804217E:
	movs r1, 0xF9
	movs r2, 0x1
	bl sub_804151C
_08042186:
	pop {r0}
	bx r0
	thumb_func_end sub_804216C

	thumb_func_start sub_804218C
sub_804218C:
	push {lr}
	adds r0, r1, 0
	movs r1, 0x2A
	movs r2, 0x1
	bl sub_804151C
	pop {r0}
	bx r0
	thumb_func_end sub_804218C

	thumb_func_start sub_804219C
sub_804219C:
	push {lr}
	movs r1, 0x90
	movs r2, 0x1
	bl sub_80416E0
	pop {r0}
	bx r0
	thumb_func_end sub_804219C

	thumb_func_start sub_80421AC
sub_80421AC:
	push {lr}
	adds r0, r1, 0
	ldr r1, _080421BC
	movs r2, 0x1
	bl sub_804151C
	pop {r0}
	bx r0
	.align 2, 0
_080421BC: .4byte 0x00000167
	thumb_func_end sub_80421AC

	thumb_func_start sub_80421C0
sub_80421C0:
	push {r4,lr}
	adds r2, r0, 0
	lsls r1, 16
	lsrs r0, r1, 16
	adds r4, r0, 0
	cmp r2, 0
	bne _080421D4
	bl sub_8083E38
	b _080421E6
_080421D4:
	adds r0, r2, 0
	bl sub_8042768
	lsls r0, 24
	cmp r0, 0
	beq _080421E6
	adds r0, r4, 0
	bl sub_8083E38
_080421E6:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_80421C0

	thumb_func_start sub_80421EC
sub_80421EC:
	push {r4,lr}
	lsls r1, 16
	lsrs r4, r1, 16
	bl sub_803F428
	lsls r0, 24
	cmp r0, 0
	beq _08042202
	adds r0, r4, 0
	bl sub_8083E38
_08042202:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_80421EC

	thumb_func_start sub_8042208
sub_8042208:
	push {lr}
	lsls r1, 24
	lsrs r1, 24
	cmp r1, 0
	bne _0804221C
	movs r0, 0xA9
	lsls r0, 1
	bl sub_8083E38
	b _08042234
_0804221C:
	cmp r1, 0x1
	bne _0804222C
	ldr r0, _08042228
	bl sub_8083E38
	b _08042234
	.align 2, 0
_08042228: .4byte 0x00000151
_0804222C:
	movs r0, 0xA8
	lsls r0, 1
	bl sub_8083E38
_08042234:
	pop {r0}
	bx r0
	thumb_func_end sub_8042208

	thumb_func_start sub_8042238
sub_8042238:
	push {lr}
	ldr r0, [r1, 0x70]
	ldrb r0, [r0, 0x6]
	cmp r0, 0
	beq _08042250
	ldr r0, _0804224C
	bl sub_8083E38
	b _08042258
	.align 2, 0
_0804224C: .4byte 0x00000157
_08042250:
	movs r0, 0xAB
	lsls r0, 1
	bl sub_8083E38
_08042258:
	pop {r0}
	bx r0
	thumb_func_end sub_8042238

	thumb_func_start sub_804225C
sub_804225C:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0x4
	mov r8, r0
	adds r5, r1, 0
	lsls r2, 24
	lsrs r4, r2, 24
	adds r7, r4, 0
	cmp r4, 0x11
	bne _08042274
	b _08042384
_08042274:
	adds r0, r5, 0
	bl sub_803F428
	lsls r0, 24
	cmp r0, 0
	bne _08042282
	b _08042384
_08042282:
	adds r0, r4, 0
	bl sub_800EF28
	bl sub_800EF64
	movs r0, 0x4
	movs r1, 0x42
	bl sub_803E708
	movs r0, 0
	ldrsh r1, [r5, r0]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 11
	movs r1, 0xC0
	lsls r1, 4
	adds r0, r1
	cmp r0, 0
	bge _080422AA
	adds r0, 0xFF
_080422AA:
	lsls r0, 8
	lsrs r0, 16
	ldr r1, _080422FC
	ldr r2, [sp]
	ands r2, r1
	orrs r2, r0
	str r2, [sp]
	movs r0, 0x2
	ldrsh r1, [r5, r0]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 11
	movs r1, 0x80
	lsls r1, 5
	adds r0, r1
	cmp r0, 0
	bge _080422CE
	adds r0, 0xFF
_080422CE:
	lsls r0, 8
	lsrs r0, 16
	lsls r0, 16
	ldr r1, _08042300
	ands r2, r1
	orrs r2, r0
	str r2, [sp]
	adds r0, r4, 0
	mov r1, sp
	bl sub_800E448
	adds r6, r0, 0
	cmp r4, 0x4
	bne _08042308
	ldr r1, _08042304
	movs r0, 0
	bl sub_80421C0
	movs r0, 0x28
	movs r1, 0x33
	bl sub_803E708
	b _08042360
	.align 2, 0
_080422FC: .4byte 0xffff0000
_08042300: .4byte 0x0000ffff
_08042304: .4byte 0x00000193
_08042308:
	cmp r7, 0x8
	bne _08042358
	mov r0, r8
	ldr r7, [r0, 0x70]
	adds r0, r7, 0
	adds r0, 0x46
	ldrb r4, [r0]
	movs r5, 0
	b _0804231C
_0804231A:
	adds r5, 0x2
_0804231C:
	ldr r0, _08042354
	cmp r5, r0
	bgt _08042346
	subs r4, 0x1
	movs r0, 0x7
	ands r4, r0
	mov r0, r8
	movs r1, 0
	adds r2, r4, 0
	bl sub_806CDD4
	movs r0, 0x2
	movs r1, 0x33
	bl sub_803E708
	adds r0, r6, 0
	bl sub_800E9A8
	lsls r0, 24
	cmp r0, 0
	bne _0804231A
_08042346:
	movs r0, 0x7
	ands r4, r0
	adds r0, r7, 0
	adds r0, 0x46
	strb r4, [r0]
	b _08042360
	.align 2, 0
_08042354: .4byte 0x000003e7
_08042358:
	movs r0, 0x28
	movs r1, 0x33
	bl sub_803E708
_08042360:
	movs r5, 0
	ldr r4, _08042368
	b _0804236E
	.align 2, 0
_08042368: .4byte 0x000003e7
_0804236C:
	adds r5, 0x1
_0804236E:
	cmp r5, r4
	bgt _08042384
	movs r0, 0x42
	bl sub_803E46C
	adds r0, r6, 0
	bl sub_800E9A8
	lsls r0, 24
	cmp r0, 0
	bne _0804236C
_08042384:
	add sp, 0x4
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_804225C

	thumb_func_start sub_8042390
sub_8042390:
	push {r4-r6,lr}
	sub sp, 0x18
	adds r5, r0, 0
	adds r4, r1, 0
	bl sub_8042768
	lsls r0, 24
	cmp r0, 0
	beq _08042454
	ldrb r1, [r4]
	movs r0, 0x8
	ands r0, r1
	movs r6, 0
	cmp r0, 0
	bne _080423B0
	ldrb r6, [r4, 0x2]
_080423B0:
	adds r0, r6, 0
	movs r1, 0
	bl sub_800EF40
	bl sub_800EF64
	movs r0, 0x4
	movs r1, 0x42
	bl sub_803E708
	ldr r0, [r5, 0xC]
	cmp r0, 0
	bge _080423CC
	adds r0, 0xFF
_080423CC:
	lsls r0, 8
	lsrs r0, 16
	ldr r1, _08042428
	ldr r2, [sp, 0x14]
	ands r2, r1
	orrs r2, r0
	str r2, [sp, 0x14]
	ldr r0, [r5, 0x10]
	cmp r0, 0
	bge _080423E2
	adds r0, 0xFF
_080423E2:
	lsls r0, 8
	lsrs r0, 16
	lsls r0, 16
	ldr r4, _0804242C
	ands r4, r2
	orrs r4, r0
	str r4, [sp, 0x14]
	asrs r4, 16
	ldr r0, _08042430
	ldr r0, [r0]
	ldr r1, _08042434
	adds r0, r1
	movs r1, 0
	ldrsh r0, [r0, r1]
	subs r4, r0
	lsrs r0, r4, 31
	adds r4, r0
	asrs r4, 1
	adds r4, 0x1
	adds r1, r5, 0
	adds r1, 0x28
	add r0, sp, 0x4
	bl sub_8005700
	add r1, sp, 0x14
	str r4, [sp]
	adds r0, r6, 0
	add r2, sp, 0x4
	movs r3, 0
	bl sub_800E49C
	adds r5, r0, 0
	movs r4, 0
	ldr r6, _08042438
	b _0804243E
	.align 2, 0
_08042428: .4byte 0xffff0000
_0804242C: .4byte 0x0000ffff
_08042430: .4byte gUnknown_203B418
_08042434: .4byte 0x000181f2
_08042438: .4byte 0x000003e7
_0804243C:
	adds r4, 0x1
_0804243E:
	cmp r4, r6
	bgt _08042454
	movs r0, 0x42
	bl sub_803E46C
	adds r0, r5, 0
	bl sub_800E9A8
	lsls r0, 24
	cmp r0, 0
	bne _0804243C
_08042454:
	add sp, 0x18
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end sub_8042390

	thumb_func_start sub_804245C
sub_804245C:
	push {r4-r6,lr}
	sub sp, 0x18
	adds r5, r0, 0
	adds r4, r1, 0
	bl sub_8042768
	lsls r0, 24
	cmp r0, 0
	beq _08042518
	ldrb r1, [r4]
	movs r0, 0x8
	ands r0, r1
	movs r6, 0
	cmp r0, 0
	bne _0804247C
	ldrb r6, [r4, 0x2]
_0804247C:
	bl sub_800EF64
	movs r0, 0x4
	movs r1, 0x42
	bl sub_803E708
	ldr r0, [r5, 0xC]
	cmp r0, 0
	bge _08042490
	adds r0, 0xFF
_08042490:
	lsls r0, 8
	lsrs r0, 16
	ldr r1, _080424EC
	ldr r2, [sp, 0x14]
	ands r2, r1
	orrs r2, r0
	str r2, [sp, 0x14]
	ldr r0, [r5, 0x10]
	cmp r0, 0
	bge _080424A6
	adds r0, 0xFF
_080424A6:
	lsls r0, 8
	lsrs r0, 16
	lsls r0, 16
	ldr r4, _080424F0
	ands r4, r2
	orrs r4, r0
	str r4, [sp, 0x14]
	asrs r4, 16
	ldr r0, _080424F4
	ldr r0, [r0]
	ldr r1, _080424F8
	adds r0, r1
	movs r1, 0
	ldrsh r0, [r0, r1]
	subs r4, r0
	lsrs r0, r4, 31
	adds r4, r0
	asrs r4, 1
	adds r4, 0x1
	adds r1, r5, 0
	adds r1, 0x28
	add r0, sp, 0x4
	bl sub_8005700
	add r1, sp, 0x14
	str r4, [sp]
	adds r0, r6, 0
	add r2, sp, 0x4
	movs r3, 0x1
	bl sub_800E49C
	adds r5, r0, 0
	movs r4, 0
	ldr r6, _080424FC
	b _08042502
	.align 2, 0
_080424EC: .4byte 0xffff0000
_080424F0: .4byte 0x0000ffff
_080424F4: .4byte gUnknown_203B418
_080424F8: .4byte 0x000181f2
_080424FC: .4byte 0x000003e7
_08042500:
	adds r4, 0x1
_08042502:
	cmp r4, r6
	bgt _08042518
	movs r0, 0x42
	bl sub_803E46C
	adds r0, r5, 0
	bl sub_800E9A8
	lsls r0, 24
	cmp r0, 0
	bne _08042500
_08042518:
	add sp, 0x18
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end sub_804245C

	thumb_func_start sub_8042520
sub_8042520:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x3C
	adds r4, r0, 0
	bl sub_8045888
	lsls r0, 24
	cmp r0, 0
	bne _0804253A
	b _08042664
_0804253A:
	ldr r0, [r4, 0x70]
	adds r0, 0x46
	ldrb r5, [r0]
	ldr r0, [r4, 0xC]
	cmp r0, 0
	bge _08042548
	adds r0, 0xFF
_08042548:
	lsls r0, 8
	lsrs r0, 16
	ldr r1, _0804264C
	ldr r2, [sp, 0x2C]
	ands r2, r1
	orrs r2, r0
	str r2, [sp, 0x2C]
	ldr r0, [r4, 0x10]
	cmp r0, 0
	bge _0804255E
	adds r0, 0xFF
_0804255E:
	lsls r0, 8
	lsrs r0, 16
	lsls r0, 16
	ldr r1, _08042650
	ands r1, r2
	orrs r1, r0
	str r1, [sp, 0x2C]
	asrs r1, 16
	ldr r0, _08042654
	ldr r0, [r0]
	ldr r2, _08042658
	adds r0, r2
	movs r2, 0
	ldrsh r0, [r0, r2]
	subs r1, r0
	lsrs r0, r1, 31
	adds r1, r0
	asrs r7, r1, 1
	ldr r0, _0804265C
	str r0, [sp, 0x4]
	movs r2, 0
	str r2, [sp, 0x8]
	str r5, [sp, 0xC]
	add r1, sp, 0x4
	add r4, sp, 0x2C
	ldrh r0, [r4]
	strh r0, [r1, 0xC]
	ldr r0, [sp, 0x2C]
	asrs r0, 16
	strh r0, [r1, 0xE]
	adds r0, r1, 0
	strh r2, [r0, 0x10]
	strh r2, [r0, 0x12]
	movs r0, 0x1
	negs r0, r0
	str r0, [sp, 0x18]
	str r7, [sp, 0x1C]
	add r0, sp, 0x20
	bl sub_8004E8C
	add r0, sp, 0x4
	movs r1, 0
	bl sub_8041764
	adds r6, r0, 0
	mov r10, r4
	lsls r1, r5, 2
	mov r0, sp
	adds r0, 0x30
	str r0, [sp, 0x38]
	ldr r0, _08042660
	adds r5, r1, r0
	movs r1, 0x5
	mov r8, r1
	mov r9, r10
_080425CC:
	movs r0, 0
	str r0, [sp]
	adds r0, r6, 0
	adds r1, r4, 0
	movs r2, 0
	adds r3, r7, 0
	bl sub_800E8AC
	movs r0, 0x42
	bl sub_803E46C
	movs r2, 0
	ldrsh r0, [r5, r2]
	lsls r0, 2
	mov r1, r9
	ldrh r1, [r1]
	adds r0, r1
	mov r2, r9
	strh r0, [r2]
	movs r0, 0x2
	ldrsh r1, [r5, r0]
	lsls r1, 2
	ldrh r0, [r4, 0x2]
	adds r0, r1
	strh r0, [r4, 0x2]
	movs r2, 0x2
	ldrsh r1, [r4, r2]
	ldr r0, _08042654
	ldr r0, [r0]
	ldr r2, _08042658
	adds r0, r2
	movs r2, 0
	ldrsh r0, [r0, r2]
	subs r1, r0
	lsrs r0, r1, 31
	adds r1, r0
	asrs r7, r1, 1
	movs r0, 0x1
	negs r0, r0
	add r8, r0
	mov r1, r8
	cmp r1, 0
	bge _080425CC
	bl sub_800DBBC
	mov r2, r10
	movs r1, 0
	ldrsh r0, [r2, r1]
	lsls r0, 8
	str r0, [sp, 0x30]
	add r0, sp, 0x2C
	movs r2, 0x2
	ldrsh r0, [r0, r2]
	lsls r0, 8
	ldr r1, [sp, 0x38]
	str r0, [r1, 0x4]
	movs r1, 0xD0
	lsls r1, 1
	ldr r0, [sp, 0x38]
	movs r2, 0x1
	bl sub_80416E0
	adds r6, r0, 0
	b _08042668
	.align 2, 0
_0804264C: .4byte 0xffff0000
_08042650: .4byte 0x0000ffff
_08042654: .4byte gUnknown_203B418
_08042658: .4byte 0x000181f2
_0804265C: .4byte 0x00000165
_08042660: .4byte gUnknown_80F4448
_08042664:
	movs r6, 0x1
	negs r6, r6
_08042668:
	adds r0, r6, 0
	add sp, 0x3C
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_8042520

	thumb_func_start sub_804267C
sub_804267C:
	push {r4,lr}
	ldr r4, _080426B8
	bl sub_8043D10
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0
	beq _08042694
	cmp r0, 0
	blt _08042694
	cmp r0, 0x2
	ble _080426AC
_08042694:
	ldr r0, _080426BC
	ldr r0, [r0]
	ldr r1, _080426C0
	adds r0, r1
	ldrb r0, [r0]
	bl GetStairDirection
	lsls r0, 24
	ldr r4, _080426C4
	cmp r0, 0
	beq _080426AC
	subs r4, 0x1
_080426AC:
	adds r0, r4, 0
	bl sub_8083E38
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080426B8: .4byte 0x000003e5
_080426BC: .4byte gUnknown_203B418
_080426C0: .4byte 0x00000644
_080426C4: .4byte 0x00000155
	thumb_func_end sub_804267C

	thumb_func_start sub_80426C8
sub_80426C8:
	push {r4,r5,lr}
	adds r5, r0, 0
	adds r4, r1, 0
	cmp r4, 0x3
	bne _080426D8
	movs r0, 0
	bl sub_8083E88
_080426D8:
	cmp r5, 0x4
	beq _080426F0
	ldr r0, _080426EC
	lsls r1, r4, 1
	adds r1, r0
	ldrh r0, [r1]
	bl sub_8083E38
	b _080426FC
	.align 2, 0
_080426EC: .4byte gUnknown_80F67DC
_080426F0:
	ldr r0, _08042708
	lsls r1, r4, 1
	adds r1, r0
	ldrh r0, [r1]
	bl sub_8083E38
_080426FC:
	adds r0, r5, 0
	adds r1, r4, 0
	movs r2, 0x80
	bl sub_8042B34
	b _08042712
	.align 2, 0
_08042708: .4byte gUnknown_80F67E4
_0804270C:
	movs r0, 0x46
	bl sub_803E46C
_08042712:
	bl sub_8042CC0
	lsls r0, 24
	cmp r0, 0
	bne _0804270C
	bl sub_8042D7C
	bl sub_8040238
	movs r0, 0x1
	bl sub_8052210
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_80426C8

	thumb_func_start sub_8042730
sub_8042730:
	push {r4,r5,lr}
	adds r4, r0, 0
	movs r1, 0x8
	movs r2, 0x8
	bl sub_806CDD4
	movs r5, 0
	b _08042742
_08042740:
	adds r5, 0x1
_08042742:
	cmp r5, 0x63
	bgt _08042760
	movs r0, 0x51
	bl sub_803E46C
	ldr r0, [r4, 0x40]
	movs r1, 0x3
	ands r0, r1
	cmp r0, 0
	bne _08042760
	adds r0, r4, 0
	adds r0, 0x6B
	ldrb r0, [r0]
	cmp r0, 0x8
	beq _08042740
_08042760:
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_8042730

	thumb_func_start sub_8042768
sub_8042768:
	push {lr}
	adds r1, r0, 0
	adds r0, 0x20
	ldrb r0, [r0]
	cmp r0, 0
	bne _08042778
_08042774:
	movs r0, 0
	b _080427A6
_08042778:
	ldr r0, _08042794
	ldr r2, [r0]
	ldr r3, _08042798
	adds r0, r2, r3
	ldrb r0, [r0]
	cmp r0, 0
	beq _0804279C
	subs r3, 0x12
	adds r0, r2, r3
	ldr r0, [r0]
	cmp r0, r1
	bne _08042774
	movs r0, 0x1
	b _080427A6
	.align 2, 0
_08042794: .4byte gUnknown_203B418
_08042798: .4byte 0x0001820a
_0804279C:
	adds r0, r1, 0
	bl sub_8045888
	lsls r0, 24
	lsrs r0, 24
_080427A6:
	pop {r1}
	bx r1
	thumb_func_end sub_8042768

	thumb_func_start sub_80427AC
sub_80427AC:
	push {r4-r6,lr}
	movs r6, 0
_080427B0:
	ldr r0, _08042808
	ldr r0, [r0]
	lsls r1, r6, 2
	ldr r2, _0804280C
	adds r0, r2
	adds r0, r1
	ldr r4, [r0]
	adds r0, r4, 0
	bl sub_80450E0
	lsls r0, 24
	cmp r0, 0
	beq _080427FA
	ldr r5, [r4, 0x70]
	adds r1, r5, 0
	adds r1, 0xF3
	ldrb r0, [r1]
	cmp r0, 0
	beq _080427FA
	movs r0, 0
	strb r0, [r1]
	adds r0, r4, 0
	bl sub_80429A0
	ldrb r0, [r5, 0x6]
	cmp r0, 0
	bne _080427FA
	ldr r0, _08042810
	adds r1, r4, 0
	movs r2, 0
	bl sub_8045B94
	ldr r0, _08042814
	ldr r1, [r0]
	adds r0, r4, 0
	bl sub_805239C
_080427FA:
	adds r6, 0x1
	cmp r6, 0x13
	ble _080427B0
	pop {r4-r6}
	pop {r0}
	bx r0
	.align 2, 0
_08042808: .4byte gUnknown_203B418
_0804280C: .4byte 0x000135cc
_08042810: .4byte gUnknown_202DF98
_08042814: .4byte gUnknown_8100270
	thumb_func_end sub_80427AC

	thumb_func_start sub_8042818
sub_8042818:
	push {r4-r7,lr}
	lsls r0, 24
	lsrs r5, r0, 24
	lsls r1, 24
	lsrs r7, r1, 24
	ldr r0, _08042874
	ldr r0, [r0]
	ldr r1, _08042878
	adds r0, r1
	ldr r4, [r0]
	cmp r4, 0
	bne _08042836
	bl sub_8083600
	adds r4, r0, 0
_08042836:
	ldr r1, _0804287C
	lsls r0, r5, 1
	adds r2, r0, r1
	ldrh r1, [r2]
	ldr r0, _08042880
	cmp r1, r0
	beq _0804284A
	adds r0, r4, 0
	bl sub_80421C0
_0804284A:
	ldr r0, _08042884
	lsls r1, r5, 2
	adds r0, r1, r0
	ldr r5, [r0]
	adds r6, r1, 0
	cmp r5, 0
	blt _08042896
	cmp r7, 0
	beq _08042888
	bl sub_80441BC
	lsls r0, 24
	cmp r0, 0
	bne _08042888
	adds r0, r4, 0
	adds r1, r5, 0
	movs r2, 0
	bl sub_804151C
	b _08042896
	.align 2, 0
_08042874: .4byte gUnknown_203B418
_08042878: .4byte 0x000181f8
_0804287C: .4byte gUnknown_80F682C
_08042880: .4byte 0x000003e5
_08042884: .4byte gUnknown_80F67EC
_08042888:
	ldr r0, _0804289C
	adds r0, r6, r0
	ldr r1, [r0]
	adds r0, r4, 0
	movs r2, 0
	bl sub_804151C
_08042896:
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_0804289C: .4byte gUnknown_80F680C
	thumb_func_end sub_8042818

        .align 2,0 @ Don't pad with nop
