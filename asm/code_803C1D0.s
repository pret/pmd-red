        #include "asm/constants/gba_constants.inc"
	#include "asm/macros.inc"

	.syntax unified

	.text

	thumb_func_start sub_803C3E0
sub_803C3E0:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0x54
	adds r7, r0, 0
	movs r6, 0
	ldr r5, _0803C42C
	movs r4, 0
	mov r8, sp
_0803C3F2:
	movs r1, 0
	ldrsh r0, [r5, r1]
	bl sub_803C110
	lsls r0, 24
	cmp r0, 0
	beq _0803C41A
	movs r1, 0x2
	ldrsh r0, [r5, r1]
	bl sub_803C110
	lsls r0, 24
	cmp r0, 0
	beq _0803C41A
	mov r0, r8
	adds r0, 0x4
	mov r8, r0
	subs r0, 0x4
	stm r0!, {r4}
	adds r6, 0x1
_0803C41A:
	adds r5, 0x8
	adds r4, 0x1
	cmp r4, 0x14
	ble _0803C3F2
	ldr r5, _0803C42C
	cmp r6, 0
	bne _0803C430
	movs r0, 0
	b _0803C44E
	.align 2, 0
_0803C42C: .4byte gUnknown_80E9920
_0803C430:
	adds r0, r6, 0
	bl RandInt
	lsls r0, 2
	add r0, sp
	ldr r4, [r0]
	lsls r0, r4, 3
	adds r5, r0, r5
	ldrh r0, [r5]
	strh r0, [r7, 0xC]
	ldrh r0, [r5, 0x2]
	strh r0, [r7, 0xE]
	movs r0, 0x7
	strb r0, [r7, 0x2]
	movs r0, 0x1
_0803C44E:
	add sp, 0x54
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_803C3E0

	thumb_func_start sub_803C45C
sub_803C45C:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0xB4
	adds r7, r0, 0
	movs r6, 0
	ldr r5, _0803C4CC
	movs r4, 0
	mov r8, sp
_0803C46E:
	movs r1, 0
	ldrsh r0, [r5, r1]
	bl sub_803C110
	lsls r0, 24
	cmp r0, 0
	beq _0803C496
	movs r1, 0x2
	ldrsh r0, [r5, r1]
	bl sub_803C110
	lsls r0, 24
	cmp r0, 0
	beq _0803C496
	mov r0, r8
	adds r0, 0x4
	mov r8, r0
	subs r0, 0x4
	stm r0!, {r4}
	adds r6, 0x1
_0803C496:
	adds r5, 0xC
	adds r4, 0x1
	cmp r4, 0x2C
	ble _0803C46E
	ldr r5, _0803C4CC
	cmp r6, 0
	beq _0803C4E0
	adds r0, r6, 0
	bl RandInt
	lsls r0, 2
	add r0, sp
	ldr r4, [r0]
	lsls r0, r4, 1
	adds r0, r4
	lsls r0, 2
	adds r5, r0, r5
	bl Rand32Bit
	movs r1, 0x10
	ands r1, r0
	cmp r1, 0
	beq _0803C4D0
	ldrh r0, [r5]
	strh r0, [r7, 0xC]
	ldrh r0, [r5, 0x2]
	b _0803C4D6
	.align 2, 0
_0803C4CC: .4byte gUnknown_80E9F8C
_0803C4D0:
	ldrh r0, [r5, 0x2]
	strh r0, [r7, 0xC]
	ldrh r0, [r5]
_0803C4D6:
	strh r0, [r7, 0xE]
	movs r0, 0x8
	strb r0, [r7, 0x2]
	movs r0, 0x1
	b _0803C4E2
_0803C4E0:
	movs r0, 0
_0803C4E2:
	add sp, 0xB4
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_803C45C

	thumb_func_start sub_803C4F0
sub_803C4F0:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0x18
	adds r7, r0, 0
	movs r6, 0
	ldr r5, _0803C55C
	movs r4, 0
	mov r8, sp
_0803C502:
	movs r1, 0
	ldrsh r0, [r5, r1]
	bl sub_803C110
	lsls r0, 24
	cmp r0, 0
	beq _0803C52A
	movs r1, 0x2
	ldrsh r0, [r5, r1]
	bl sub_803C110
	lsls r0, 24
	cmp r0, 0
	beq _0803C52A
	mov r0, r8
	adds r0, 0x4
	mov r8, r0
	subs r0, 0x4
	stm r0!, {r4}
	adds r6, 0x1
_0803C52A:
	adds r5, 0x4
	adds r4, 0x1
	cmp r4, 0x5
	ble _0803C502
	ldr r5, _0803C55C
	cmp r6, 0
	beq _0803C570
	adds r0, r6, 0
	bl RandInt
	lsls r0, 2
	add r0, sp
	ldr r4, [r0]
	lsls r0, r4, 2
	adds r5, r0, r5
	bl Rand32Bit
	movs r1, 0x10
	ands r1, r0
	cmp r1, 0
	beq _0803C560
	ldrh r0, [r5]
	strh r0, [r7, 0xC]
	ldrh r0, [r5, 0x2]
	b _0803C566
	.align 2, 0
_0803C55C: .4byte gUnknown_80E8168
_0803C560:
	ldrh r0, [r5, 0x2]
	strh r0, [r7, 0xC]
	ldrh r0, [r5]
_0803C566:
	strh r0, [r7, 0xE]
	movs r0, 0x9
	strb r0, [r7, 0x2]
	movs r0, 0x1
	b _0803C572
_0803C570:
	movs r0, 0
_0803C572:
	add sp, 0x18
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_803C4F0

	thumb_func_start sub_803C580
sub_803C580:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0x54
	adds r6, r0, 0
	movs r7, 0
	ldr r5, _0803C5D8
	movs r0, 0x6
	bl sub_80023E4
	lsls r0, 24
	cmp r0, 0
	beq _0803C5D2
	movs r4, 0
	mov r8, sp
_0803C59E:
	movs r1, 0
	ldrsh r0, [r5, r1]
	bl sub_803C110
	lsls r0, 24
	cmp r0, 0
	beq _0803C5C6
	ldrb r0, [r6, 0x4]
	ldrb r1, [r5, 0x2]
	bl xxx_bit_lut_lookup_8091E50
	lsls r0, 24
	cmp r0, 0
	beq _0803C5C6
	mov r0, r8
	adds r0, 0x4
	mov r8, r0
	subs r0, 0x4
	stm r0!, {r4}
	adds r7, 0x1
_0803C5C6:
	adds r5, 0x4
	adds r4, 0x1
	cmp r4, 0x14
	ble _0803C59E
	cmp r7, 0
	bne _0803C5DC
_0803C5D2:
	movs r0, 0
	b _0803C600
	.align 2, 0
_0803C5D8: .4byte gUnknown_80E8180
_0803C5DC:
	adds r0, r7, 0
	bl RandInt
	lsls r0, 2
	add r0, sp
	ldr r4, [r0]
	lsls r1, r4, 2
	ldr r0, _0803C60C
	adds r5, r1, r0
	ldrh r0, [r5]
	strh r0, [r6, 0xC]
	ldrh r0, [r5]
	strh r0, [r6, 0xE]
	ldrb r0, [r5, 0x2]
	strb r0, [r6, 0x10]
	movs r0, 0x5
	strb r0, [r6, 0x2]
	movs r0, 0x1
_0803C600:
	add sp, 0x54
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r1}
	bx r1
	.align 2, 0
_0803C60C: .4byte gUnknown_80E8180
	thumb_func_end sub_803C580

	thumb_func_start sub_803C610
sub_803C610:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	ldr r4, _0803C660
	add sp, r4
	adds r6, r0, 0
	movs r7, 0
	ldr r4, _0803C664
	movs r5, 0
	mov r8, sp
_0803C624:
	movs r1, 0
	ldrsh r0, [r4, r1]
	bl sub_803C110
	lsls r0, 24
	cmp r0, 0
	beq _0803C64C
	ldrb r0, [r6, 0x4]
	ldrb r1, [r4, 0x2]
	bl xxx_bit_lut_lookup_8091E50
	lsls r0, 24
	cmp r0, 0
	beq _0803C64C
	mov r0, r8
	adds r0, 0x4
	mov r8, r0
	subs r0, 0x4
	stm r0!, {r5}
	adds r7, 0x1
_0803C64C:
	adds r4, 0x4
	adds r5, 0x1
	ldr r0, _0803C668
	cmp r5, r0
	ble _0803C624
	cmp r7, 0
	bne _0803C66C
	movs r0, 0
	b _0803C690
	.align 2, 0
_0803C660: .4byte 0xfffff9f8
_0803C664: .4byte gUnknown_80E81D4
_0803C668: .4byte 0x00000181
_0803C66C:
	adds r0, r7, 0
	bl RandInt
	lsls r0, 2
	add r0, sp
	ldr r5, [r0]
	lsls r1, r5, 2
	ldr r0, _0803C6A0
	adds r4, r1, r0
	ldrh r0, [r4]
	strh r0, [r6, 0xC]
	ldrh r0, [r4]
	strh r0, [r6, 0xE]
	ldrb r0, [r4, 0x2]
	strb r0, [r6, 0x10]
	movs r0, 0x6
	strb r0, [r6, 0x2]
	movs r0, 0x1
_0803C690:
	movs r3, 0xC1
	lsls r3, 3
	add sp, r3
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r1}
	bx r1
	.align 2, 0
_0803C6A0: .4byte gUnknown_80E81D4
	thumb_func_end sub_803C610

        .align 2,0
