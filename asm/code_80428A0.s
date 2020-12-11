	.include "constants/gba_constants.inc"
	.include "asm/macros.inc"

	.syntax unified

	.text	

	thumb_func_start sub_8042A84
sub_8042A84:
	push {r4-r7,lr}
	adds r4, r1, 0
	adds r7, r2, 0
	lsls r0, 16
	asrs r5, r0, 16
	movs r6, 0x80
	lsls r6, 2
	adds r0, r4, 0
	bl sub_8042768
	lsls r0, 24
	cmp r0, 0
	beq _08042AF8
	adds r0, r4, 0
	adds r1, r5, 0
	movs r2, 0
	bl sub_804151C
	adds r0, r7, 0
	movs r1, 0x42
	bl sub_803E708
	adds r5, r4, 0
	adds r5, 0x20
_08042AB4:
	ldr r1, [r4, 0x1C]
	ldr r0, _08042B00
	cmp r1, r0
	bgt _08042AF0
	movs r0, 0x42
	bl sub_803E46C
	ldr r1, [r4, 0x1C]
	adds r1, r6
	str r1, [r4, 0x1C]
	movs r0, 0x80
	lsls r0, 1
	adds r6, r0
	ldr r0, [r4, 0x10]
	subs r0, r1
	cmp r0, 0
	bge _08042AD8
	adds r0, 0xFF
_08042AD8:
	asrs r1, r0, 8
	ldr r0, _08042B04
	ldr r0, [r0]
	ldr r2, _08042B08
	adds r0, r2
	movs r2, 0
	ldrsh r0, [r0, r2]
	subs r1, r0
	movs r0, 0x8
	negs r0, r0
	cmp r1, r0
	bge _08042AB4
_08042AF0:
	movs r0, 0
	strb r0, [r5]
	bl sub_804178C
_08042AF8:
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_08042B00: .4byte 0x0000c7ff
_08042B04: .4byte gUnknown_203B418
_08042B08: .4byte 0x000181f2
	thumb_func_end sub_8042A84

	thumb_func_start sub_8042B0C
sub_8042B0C:
	push {lr}
	adds r1, r0, 0
	movs r0, 0x9F
	lsls r0, 1
	movs r2, 0x5
	bl sub_8042A84
	pop {r0}
	bx r0
	thumb_func_end sub_8042B0C

	thumb_func_start sub_8042B20
sub_8042B20:
	push {lr}
	adds r1, r0, 0
	movs r0, 0xDE
	lsls r0, 1
	movs r2, 0xE
	bl sub_8042A84
	pop {r0}
	bx r0
	thumb_func_end sub_8042B20

	thumb_func_start sub_8042B34
sub_8042B34:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x28
	adds r5, r0, 0
	adds r4, r1, 0
	adds r6, r2, 0
	movs r0, 0
	mov r8, r0
	bl sub_8085480
	mov r10, r0
	ldr r7, _08042CB0
	movs r0, 0xCC
	movs r1, 0x7
	bl MemoryAlloc
	str r0, [r7]
	str r5, [r0]
	adds r4, 0x1
	lsls r4, 2
	str r4, [r0, 0x8]
	ldr r4, _08042CB4
	lsls r0, r5, 1
	adds r0, r5
	lsls r0, 3
	adds r0, r4
	movs r1, 0
	ldrsh r0, [r0, r1]
	bl sub_800EE5C
	bl sub_800EF64
	movs r0, 0x46
	bl sub_803E46C
	ldr r0, [r7]
	str r6, [r0, 0x4]
	movs r5, 0
	ldr r0, [r0, 0x8]
	cmp r5, r0
	blt _08042B8E
	b _08042C9E
_08042B8E:
	mov r9, sp
_08042B90:
	mov r2, r8
	lsls r6, r2, 3
	ldr r0, [r7]
	ldr r1, [r0]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 3
	adds r0, r6, r0
	ldr r3, _08042CB4
	adds r0, r3
	movs r1, 0
	ldrsh r0, [r0, r1]
	str r0, [sp]
	str r5, [sp, 0x4]
	movs r0, 0
	str r0, [sp, 0x8]
	mov r2, r10
	ldr r0, [r2, 0xC]
	cmp r0, 0
	bge _08042BBA
	adds r0, 0xFF
_08042BBA:
	asrs r0, 8
	mov r3, r9
	strh r0, [r3, 0xC]
	mov r1, sp
	mov r2, r10
	ldr r0, [r2, 0x10]
	cmp r0, 0
	bge _08042BCC
	adds r0, 0xFF
_08042BCC:
	asrs r0, 8
	strh r0, [r1, 0xE]
	movs r0, 0x2
	bl RandomCapped
	ldr r1, [r7]
	lsls r4, r5, 2
	adds r3, r1, 0
	adds r3, 0x4C
	adds r3, r4
	ldr r2, [r1]
	lsls r1, r2, 1
	adds r1, r2
	lsls r1, 3
	adds r1, r6, r1
	ldr r2, _08042CB4
	adds r2, 0x4
	adds r1, r2
	ldr r1, [r1]
	lsls r1, 1
	adds r1, r0
	str r1, [r3]
	movs r0, 0xF0
	bl RandomCapped
	ldr r1, [r7]
	adds r1, r4
	adds r0, 0x98
	adds r1, 0x8C
	strh r0, [r1]
	lsls r0, r5, 1
	adds r0, 0x8
	bl RandomCapped
	ldr r1, [r7]
	adds r2, r1, r4
	adds r3, r0, 0
	adds r3, 0x18
	adds r1, r5, 0
	cmp r5, 0
	bge _08042C20
	adds r1, r5, 0x3
_08042C20:
	asrs r1, 2
	lsls r1, 2
	subs r1, r5, r1
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 3
	subs r0, r3, r0
	adds r1, r2, 0
	adds r1, 0x8E
	strh r0, [r1]
	adds r0, r2, 0
	adds r0, 0x8C
	ldrh r0, [r0]
	mov r3, r9
	strh r0, [r3, 0x10]
	ldrh r0, [r1]
	strh r0, [r3, 0x12]
	movs r0, 0x4
	str r0, [sp, 0x14]
	ldr r0, _08042CB8
	str r0, [sp, 0x18]
	add r1, sp, 0x1C
	ldr r0, _08042CBC
	ldm r0!, {r2,r3,r6}
	stm r1!, {r2,r3,r6}
	mov r0, sp
	bl sub_800E890
	ldr r2, [r7]
	adds r1, r2, 0
	adds r1, 0xC
	adds r1, r4
	str r0, [r1]
	movs r6, 0x1
	add r8, r6
	mov r0, r8
	cmp r0, 0x2
	bgt _08042C82
	ldr r0, [r2]
	lsls r1, r0, 1
	adds r1, r0
	add r1, r8
	lsls r1, 3
	ldr r2, _08042CB4
	adds r1, r2
	movs r3, 0
	ldrsh r0, [r1, r3]
	cmp r0, 0
	bne _08042C86
_08042C82:
	movs r6, 0
	mov r8, r6
_08042C86:
	ldr r0, [sp]
	bl sub_800ECA4
	ldr r0, [r0, 0x4]
	bl sub_800F15C
	adds r5, 0x1
	ldr r0, [r7]
	ldr r0, [r0, 0x8]
	cmp r5, r0
	bge _08042C9E
	b _08042B90
_08042C9E:
	add sp, 0x28
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_08042CB0: .4byte gUnknown_203B414
_08042CB4: .4byte gUnknown_80F6624
_08042CB8: .4byte 0x0000ffff
_08042CBC: .4byte gUnknown_80F683C
	thumb_func_end sub_8042B34

	thumb_func_start sub_8042CC0
sub_8042CC0:
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	sub sp, 0x4
	movs r7, 0
	ldr r2, _08042D20
	ldr r1, [r2]
	ldr r0, [r1, 0x4]
	cmp r0, 0
	beq _08042CDC
	movs r7, 0x1
	subs r0, 0x1
	str r0, [r1, 0x4]
_08042CDC:
	movs r5, 0
	ldr r0, [r2]
	ldr r0, [r0, 0x8]
	cmp r5, r0
	bge _08042D56
	adds r6, r2, 0
	movs r0, 0x98
	negs r0, r0
	mov r9, r0
	movs r4, 0
	ldr r1, _08042D24
	mov r8, r1
_08042CF4:
	ldr r3, [r6]
	adds r0, r3, r4
	adds r2, r0, 0
	adds r2, 0x8C
	adds r0, r3, 0
	adds r0, 0x4C
	adds r0, r4
	ldr r1, [r0]
	ldrh r0, [r2]
	subs r0, r1
	strh r0, [r2]
	lsls r0, 16
	asrs r0, 16
	cmp r0, r9
	bgt _08042D2E
	ldr r0, [r3, 0x4]
	cmp r0, 0
	ble _08042D28
	movs r0, 0x98
	strh r0, [r2]
	b _08042D30
	.align 2, 0
_08042D20: .4byte gUnknown_203B414
_08042D24: .4byte 0x0000ff68
_08042D28:
	mov r0, r8
	strh r0, [r2]
	b _08042D30
_08042D2E:
	movs r7, 0x1
_08042D30:
	ldr r2, [r6]
	adds r0, r2, 0
	adds r0, 0xC
	adds r0, r4
	ldr r0, [r0]
	adds r1, r4, 0
	adds r1, 0x8C
	adds r2, r1
	movs r1, 0
	str r1, [sp]
	movs r3, 0
	bl sub_800E8AC
	adds r4, 0x4
	adds r5, 0x1
	ldr r0, [r6]
	ldr r0, [r0, 0x8]
	cmp r5, r0
	blt _08042CF4
_08042D56:
	ldr r0, _08042D74
	ldr r0, [r0]
	ldr r1, _08042D78
	adds r0, r1
	bl sub_800E90C
	adds r0, r7, 0
	add sp, 0x4
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r1}
	bx r1
	.align 2, 0
_08042D74: .4byte gUnknown_203B418
_08042D78: .4byte 0x000181f0
	thumb_func_end sub_8042CC0

	thumb_func_start sub_8042D7C
sub_8042D7C:
	push {r4-r6,lr}
	ldr r1, _08042DD0
	ldr r0, [r1]
	cmp r0, 0
	beq _08042DCA
	movs r5, 0
	ldr r0, [r0, 0x8]
	cmp r5, r0
	bge _08042DBA
	adds r6, r1, 0
_08042D90:
	ldr r0, [r6]
	lsls r4, r5, 2
	adds r0, 0xC
	adds r0, r4
	ldr r0, [r0]
	bl sub_800E9A8
	lsls r0, 24
	cmp r0, 0
	beq _08042DB0
	ldr r0, [r6]
	adds r0, 0xC
	adds r0, r4
	ldr r0, [r0]
	bl sub_800DC14
_08042DB0:
	adds r5, 0x1
	ldr r0, [r6]
	ldr r0, [r0, 0x8]
	cmp r5, r0
	blt _08042D90
_08042DBA:
	bl sub_800DBBC
	ldr r4, _08042DD0
	ldr r0, [r4]
	bl MemoryFree
	movs r0, 0
	str r0, [r4]
_08042DCA:
	pop {r4-r6}
	pop {r0}
	bx r0
	.align 2, 0
_08042DD0: .4byte gUnknown_203B414
	thumb_func_end sub_8042D7C

	thumb_func_start sub_8042DD4
sub_8042DD4:
	push {r4-r7,lr}
	adds r5, r0, 0
	adds r6, r1, 0
	adds r7, r2, 0
	movs r2, 0
	ldr r0, _08042E04
	mov r12, r0
	ldr r3, _08042E08
_08042DE4:
	mov r1, r12
	ldr r0, [r1]
	adds r4, r0, r3
	ldr r1, [r4]
	movs r0, 0x1
	negs r0, r0
	cmp r1, r0
	bne _08042E0C
	str r5, [r4]
	str r6, [r4, 0xC]
	str r7, [r4, 0x4]
	adds r0, r5, 0
	bl sub_800E6D8
	str r0, [r4, 0x8]
	b _08042E14
	.align 2, 0
_08042E04: .4byte gUnknown_203B418
_08042E08: .4byte 0x000005c4
_08042E0C:
	adds r3, 0x10
	adds r2, 0x1
	cmp r2, 0x2
	ble _08042DE4
_08042E14:
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_8042DD4

	thumb_func_start sub_8042E1C
sub_8042E1C:
	push {r4-r6,lr}
	movs r5, 0
	ldr r6, _08042E44
	ldr r4, _08042E48
_08042E24:
	ldr r0, [r6]
	adds r0, r4
	ldr r1, [r0]
	movs r0, 0x1
	negs r0, r0
	cmp r1, r0
	beq _08042E4C
	adds r0, r1, 0
	bl sub_800E9A8
	lsls r0, 24
	cmp r0, 0
	beq _08042E4C
	movs r0, 0x1
	b _08042E56
	.align 2, 0
_08042E44: .4byte gUnknown_203B418
_08042E48: .4byte 0x000005c4
_08042E4C:
	adds r4, 0x10
	adds r5, 0x1
	cmp r5, 0x2
	ble _08042E24
	movs r0, 0
_08042E56:
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end sub_8042E1C

	thumb_func_start sub_8042E5C
sub_8042E5C:
	push {r4-r7,lr}
	ldr r7, _08042E90
	ldr r6, _08042E94
	movs r5, 0x2
_08042E64:
	ldr r0, [r7]
	adds r4, r0, r6
	ldr r0, [r4]
	cmp r0, 0
	blt _08042E82
	bl sub_800E9A8
	lsls r0, 24
	lsrs r1, r0, 24
	cmp r1, 0
	bne _08042E82
	movs r0, 0x1
	negs r0, r0
	str r0, [r4]
	str r1, [r4, 0xC]
_08042E82:
	adds r6, 0x10
	subs r5, 0x1
	cmp r5, 0
	bge _08042E64
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_08042E90: .4byte gUnknown_203B418
_08042E94: .4byte 0x000005c4
	thumb_func_end sub_8042E5C

	thumb_func_start sub_8042E98
sub_8042E98:
	push {r4,r5,lr}
	ldr r5, _08042EC0
	movs r4, 0x1
	negs r4, r4
	movs r3, 0
	ldr r2, _08042EC4
	movs r1, 0x2
_08042EA6:
	ldr r0, [r5]
	adds r0, r2
	str r4, [r0]
	str r3, [r0, 0x4]
	str r3, [r0, 0xC]
	adds r2, 0x10
	subs r1, 0x1
	cmp r1, 0
	bge _08042EA6
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_08042EC0: .4byte gUnknown_203B418
_08042EC4: .4byte 0x000005c4
	thumb_func_end sub_8042E98

	thumb_func_start sub_8042EC8
sub_8042EC8:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0xC
	adds r6, r0, 0
	mov r8, r1
	movs r7, 0
_08042ED6:
	ldr r1, _08042F5C
	lsls r0, r7, 4
	ldr r2, _08042F60
	adds r0, r2
	ldr r1, [r1]
	adds r4, r1, r0
	ldr r0, [r4]
	cmp r0, 0
	blt _08042F4A
	ldr r0, [r4, 0xC]
	cmp r0, r6
	bne _08042F4A
	ldr r0, [r6, 0xC]
	cmp r0, 0
	bge _08042EF6
	adds r0, 0xFF
_08042EF6:
	lsls r0, 8
	lsrs r0, 16
	ldr r1, _08042F64
	ldr r2, [sp, 0x8]
	ands r2, r1
	orrs r2, r0
	str r2, [sp, 0x8]
	ldr r1, [r6, 0x10]
	cmp r1, 0
	bge _08042F0C
	adds r1, 0xFF
_08042F0C:
	lsls r1, 8
	lsrs r1, 16
	lsls r1, 16
	ldr r0, _08042F68
	ands r2, r0
	orrs r2, r1
	str r2, [sp, 0x8]
	movs r0, 0
	str r0, [sp, 0x4]
	ldr r5, [r6, 0x70]
	ldr r2, [r4, 0x8]
	subs r0, 0x1
	cmp r2, r0
	beq _08042F36
	lsls r2, 24
	lsrs r2, 24
	add r0, sp, 0x4
	adds r1, r6, 0
	adds r1, 0x28
	bl sub_800569C
_08042F36:
	ldr r0, [r4]
	adds r1, r5, 0
	adds r1, 0x46
	ldrb r1, [r1]
	str r1, [sp]
	add r1, sp, 0x8
	add r2, sp, 0x4
	mov r3, r8
	bl sub_800EB24
_08042F4A:
	adds r7, 0x1
	cmp r7, 0x2
	ble _08042ED6
	add sp, 0xC
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_08042F5C: .4byte gUnknown_203B418
_08042F60: .4byte 0x000005c4
_08042F64: .4byte 0xffff0000
_08042F68: .4byte 0x0000ffff
	thumb_func_end sub_8042EC8

	thumb_func_start xxx_dungeon_8042F6C
xxx_dungeon_8042F6C:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x10
	mov r8, r0
	ldr r1, _0804310C
	movs r0, 0
	strb r0, [r1]
	mov r0, r8
	ldrb r6, [r0, 0x8]
	ldrb r1, [r0, 0x11]
	mov r9, r1
	ldrb r2, [r0, 0x10]
	mov r10, r2
	ldr r0, _08043110
	mov r3, r8
	ldr r1, [r3, 0x74]
	str r1, [r0]
	ldr r2, _08043114
	ldr r0, [r3, 0x78]
	str r0, [r2]
	cmp r6, 0
	bne _08042FA0
	strb r6, [r1]
_08042FA0:
	ldr r2, [r2]
	movs r1, 0
	ldr r4, _08043118
	ldr r5, _0804311C
	mov r0, sp
	adds r0, 0x4
	str r0, [sp, 0x8]
	mov r3, r8
	adds r3, 0x7C
	str r3, [sp, 0xC]
	movs r3, 0
_08042FB6:
	adds r0, r2, r1
	strb r3, [r0]
	adds r1, 0x1
	cmp r1, r4
	bls _08042FB6
	movs r7, 0
	movs r0, 0x64
	strh r0, [r5]
	cmp r6, 0
	bne _0804300C
	ldr r4, _08043114
	ldr r0, [r4]
	mov r5, r8
	ldrb r1, [r5, 0xF]
	movs r2, 0xCF
	lsls r2, 3
	adds r0, r2
	strb r1, [r0]
	ldr r2, [r4]
	ldr r3, _08043120
	adds r2, r3
	ldr r0, [r5, 0x14]
	ldr r1, [r5, 0x18]
	str r0, [r2]
	str r1, [r2, 0x4]
	ldrb r0, [r5, 0x4]
	bl GetUnkC
	ldr r1, [r4]
	ldr r5, _08043124
	adds r2, r1, r5
	strh r0, [r2]
	ldr r0, _08043128
	adds r1, r0
	strb r7, [r1]
	mov r1, r8
	ldrb r0, [r1, 0x4]
	bl GetUnk3
	ldr r1, [r4]
	ldr r2, _0804312C
	adds r1, r2
	strb r0, [r1]
_0804300C:
	ldr r4, _08043114
	ldr r0, [r4]
	movs r3, 0xD3
	lsls r3, 3
	adds r0, r3
	strb r7, [r0]
	ldr r0, [r4]
	ldr r5, _08043130
	adds r0, r5
	strb r7, [r0]
	ldr r0, [r4]
	mov r2, r8
	ldrb r1, [r2, 0x9]
	subs r3, 0x3C
	adds r0, r3
	strb r1, [r0]
	ldr r0, [r4]
	ldrb r1, [r2, 0xC]
	subs r5, 0x3F
	adds r0, r5
	strb r1, [r0]
	ldr r0, [r4]
	ldrb r1, [r2, 0xA]
	movs r2, 0xCB
	lsls r2, 3
	adds r0, r2
	strb r1, [r0]
	ldr r0, [r4]
	mov r3, r8
	ldrb r1, [r3, 0xB]
	subs r5, 0x1
	adds r0, r5
	strb r1, [r0]
	ldr r0, [r4]
	ldrb r1, [r3, 0xD]
	adds r2, 0x3
	adds r0, r2
	strb r1, [r0]
	ldr r0, [r4]
	ldrb r1, [r3, 0xE]
	ldr r3, _08043134
	adds r0, r3
	strb r1, [r0]
	bl sub_8083F34
	bl sub_803D4AC
	bl sub_804513C
	bl sub_8043CD8
	bl sub_80495E4
	bl sub_803E250
	bl sub_8040130
	bl sub_8040124
	movs r0, 0x1
	bl sub_803F27C
	ldr r1, _08043138
	ldr r5, _0804313C
	adds r0, r5, 0
	strh r0, [r1]
	movs r0, 0x1
	movs r1, 0x14
	bl sub_80095CC
	movs r0, 0
	bl sub_800DAC0
	movs r0, 0x1
	bl xxx_update_some_bg_tiles
	bl sub_803DF60
	bl sub_803E02C
	bl sub_8042E98
	ldr r0, _08043140
	strb r7, [r0]
	cmp r6, 0
	beq _080430C8
	ldr r0, _08043110
	ldr r0, [r0]
	movs r1, 0x90
	lsls r1, 7
	bl sub_8081BF4
	bl sub_8049840
_080430C8:
	mov r0, r9
	cmp r0, 0
	beq _080430D2
	bl sub_8043D60
_080430D2:
	cmp r6, 0
	beq _080430D8
	b _080431DC
_080430D8:
	ldr r0, [r4]
	ldr r1, _08043144
	adds r0, r1
	movs r1, 0x1
	strb r1, [r0]
	ldr r0, [r4]
	ldr r2, _08043148
	adds r0, r2
	strb r1, [r0]
	ldr r2, [r4]
	movs r3, 0xCF
	lsls r3, 3
	adds r0, r2, r3
	ldrb r3, [r0]
	cmp r3, 0x1
	bne _08043154
	mov r5, r8
	ldrb r1, [r5, 0x14]
	ldr r5, _0804314C
	adds r0, r2, r5
	strb r1, [r0]
	ldr r0, [r4]
	ldr r1, _08043150
	adds r0, r1
	strb r3, [r0]
	b _0804315E
	.align 2, 0
_0804310C: .4byte gUnknown_203B40C
_08043110: .4byte gUnknown_203B41C
_08043114: .4byte gUnknown_203B418
_08043118: .4byte 0x0001cedb
_0804311C: .4byte gUnknown_203B410
_08043120: .4byte 0x0000064c
_08043124: .4byte 0x00000666
_08043128: .4byte 0x0000067a
_0804312C: .4byte 0x0000067b
_08043130: .4byte 0x00000699
_08043134: .4byte 0x0000065d
_08043138: .4byte gUnknown_2026E4E
_0804313C: .4byte 0x00000808
_08043140: .4byte gUnknown_202F32C
_08043144: .4byte 0x0001820b
_08043148: .4byte 0x0001820c
_0804314C: .4byte 0x00000644
_08043150: .4byte 0x00000645
_08043154:
	ldr r3, _0804318C
	adds r1, r2, r3
	mov r5, r8
	ldr r0, [r5, 0x4]
	str r0, [r1]
_0804315E:
	ldr r4, _08043190
	ldr r0, [r4]
	ldr r1, _08043194
	adds r0, r1
	movs r1, 0
	strb r1, [r0]
	bl sub_8044124
	cmp r6, 0
	bne _080431DC
	ldr r1, [r4]
	movs r2, 0xCF
	lsls r2, 3
	adds r0, r1, r2
	ldrb r0, [r0]
	cmp r0, 0x1
	bne _0804319C
	ldr r3, _08043198
	adds r1, r3
	mov r5, r8
	ldr r0, [r5, 0x18]
	str r0, [r1]
	b _080431AC
	.align 2, 0
_0804318C: .4byte 0x00000644
_08043190: .4byte gUnknown_203B418
_08043194: .4byte 0x00000674
_08043198: .4byte 0x0000067c
_0804319C:
	bl Random
	ldr r2, [r4]
	ldr r1, _08043208
	adds r2, r1
	ldr r1, _0804320C
	ands r1, r0
	str r1, [r2]
_080431AC:
	ldr r4, _08043210
	ldr r0, [r4]
	ldr r2, _08043208
	adds r0, r2
	ldr r0, [r0]
	bl sub_808408C
	cmp r6, 0
	bne _080431DC
	bl sub_80980A4
	lsls r0, 24
	cmp r0, 0
	bne _080431D8
	ldr r0, [r4]
	ldr r3, _08043214
	adds r0, r3
	ldrb r0, [r0]
	cmp r0, 0
	bne _080431D8
	bl sub_8043FD0
_080431D8:
	bl sub_806890C
_080431DC:
	mov r5, r9
	cmp r5, 0
	beq _08043230
	ldr r1, _08043218
	ldr r0, _08043210
	ldr r0, [r0]
	ldr r2, _0804321C
	adds r0, r2
	ldrb r0, [r0]
	lsls r0, 24
	asrs r0, 24
	str r0, [r1]
	cmp r0, 0
	beq _08043224
	ldr r0, _08043220
	ldr r1, [r0]
	movs r0, 0
	movs r2, 0x1
	bl PrintFieldMessage
	b _08043230
	.align 2, 0
_08043208: .4byte 0x0000067c
_0804320C: .4byte 0x00ffffff
_08043210: .4byte gUnknown_203B418
_08043214: .4byte 0x00000644
_08043218: .4byte gUnknown_202DE30
_0804321C: .4byte 0x0000067b
_08043220: .4byte gUnknown_80FEC48
_08043224:
	ldr r0, _080432B4
	ldr r1, [r0]
	movs r0, 0
	movs r2, 0x1
	bl PrintFieldMessage
_08043230:
	mov r3, r10
	cmp r3, 0
	beq _0804326A
	mov r1, r8
	adds r1, 0x44
	movs r0, 0
	strb r0, [r1]
	ldr r0, _080432B8
	ldr r0, [r0]
	ldr r5, _080432BC
	adds r0, r5
	ldrb r0, [r0]
	bl GetLevelCondition
	lsls r0, 24
	mov r4, r8
	adds r4, 0x1C
	cmp r0, 0
	beq _0804325C
	adds r0, r4, 0
	bl sub_808D0D8
_0804325C:
	adds r0, r4, 0
	bl sub_8068A84
	cmp r6, 0
	beq _0804326A
	bl sub_806B404
_0804326A:
	bl sub_8068614
	cmp r6, 0
	bne _080432F4
	ldr r0, _080432B8
	ldr r0, [r0]
	movs r1, 0xCF
	lsls r1, 3
	adds r0, r1
	ldrb r0, [r0]
	cmp r0, 0x1
	bne _080432F4
	mov r0, sp
	bl sub_8099394
	lsls r0, 24
	cmp r0, 0
	beq _080432F4
	mov r0, sp
	ldrb r0, [r0]
	bl sub_8095228
	adds r2, r0, 0
	adds r2, 0x2C
	movs r0, 0
	ldrsb r0, [r2, r0]
	cmp r0, 0
	beq _080432E8
	ldr r1, _080432C0
	str r0, [r1]
	ldr r0, _080432C4
	ldr r1, [r0]
	movs r0, 0
	movs r2, 0x1
	bl PrintFieldMessage
	b _080432F4
	.align 2, 0
_080432B4: .4byte gUnknown_80FEC7C
_080432B8: .4byte gUnknown_203B418
_080432BC: .4byte 0x00000644
_080432C0: .4byte gUnknown_202DE30
_080432C4: .4byte gUnknown_81002B8
_080432C8:
	ldr r4, _080432CC
	b _080432D2
	.align 2, 0
_080432CC: .4byte 0x00000226
_080432D0:
	ldr r4, _080432E4
_080432D2:
	bl sub_8083600
	adds r2, r0, 0
	adds r0, r4, 0
	movs r1, 0
	bl sub_8083AB0
	bl _08043AF4
	.align 2, 0
_080432E4: .4byte 0x00000227
_080432E8:
	ldr r0, _080434B8
	ldr r1, [r0]
	movs r0, 0
	movs r2, 0x1
	bl PrintFieldMessage
_080432F4:
	movs r2, 0
	mov r10, r2
	movs r3, 0
	mov r9, r3
_080432FC:
	bl sub_8098080
	bl nullsub_16
	bl sub_80521D0
	bl sub_80531A8
	bl sub_800F690
	cmp r6, 0
	bne _08043318
	bl sub_804513C
_08043318:
	ldr r0, _080434BC
	movs r5, 0
	str r5, [r0]
	ldr r4, _080434C0
	ldr r0, [r4]
	strb r5, [r0]
	cmp r6, 0
	bne _08043346
	bl sub_80840A4
	ldr r1, [r4]
	movs r3, 0xD0
	lsls r3, 3
	adds r2, r1, r3
	str r0, [r2]
	movs r0, 0xCD
	lsls r0, 3
	adds r1, r0
	movs r0, 0xA
	strh r0, [r1]
	ldr r0, [r2]
	bl sub_80840D8
_08043346:
	ldr r0, [r4]
	ldr r1, _080434C4
	adds r0, r1
	strb r5, [r0]
	cmp r6, 0
	bne _08043390
	ldr r0, [r4]
	ldr r2, _080434C8
	adds r0, r2
	strb r6, [r0]
	movs r0, 0x4
	bl sub_8084100
	ldr r1, [r4]
	ldr r3, _080434CC
	adds r1, r3
	strb r6, [r1]
	ldr r1, [r4]
	ldr r2, _080434D0
	adds r1, r2
	strb r6, [r1]
	ldr r2, [r4]
	ldr r1, _080434D4
	lsls r0, 1
	adds r0, r1
	ldrh r1, [r0]
	adds r3, 0x3
	adds r0, r2, r3
	strh r1, [r0]
	ldr r0, _080434D8
	adds r2, r0
	mov r1, r10
	strb r1, [r2]
	ldr r0, [r4]
	ldr r2, _080434DC
	adds r0, r2
	strb r1, [r0]
_08043390:
	bl sub_803D4D0
	ldr r0, [r4]
	strb r5, [r0, 0x1]
	ldr r0, [r4]
	strb r5, [r0, 0x10]
	ldr r0, [r4]
	strb r5, [r0, 0x2]
	ldr r0, [r4]
	strb r5, [r0, 0x4]
	ldr r0, [r4]
	strb r5, [r0, 0x11]
	ldr r0, [r4]
	strb r5, [r0, 0x8]
	ldr r0, [r4]
	strb r5, [r0, 0x3]
	ldr r0, [r4]
	strb r5, [r0, 0x6]
	ldr r0, [r4]
	strb r5, [r0, 0xF]
	ldr r2, [r4]
	movs r3, 0xB8
	lsls r3, 3
	adds r1, r2, r3
	movs r0, 0x1
	negs r0, r0
	str r0, [r1]
	strb r5, [r2, 0x7]
	ldr r0, [r4]
	strb r5, [r0, 0x9]
	ldr r0, [r4]
	strb r5, [r0, 0xA]
	ldr r0, [r4]
	movs r1, 0x1
	strb r1, [r0, 0xB]
	ldr r0, [r4]
	strb r1, [r0, 0xD]
	ldr r0, [r4]
	strb r5, [r0, 0xE]
	ldr r0, [r4]
	ldr r2, _080434E0
	adds r0, r2
	strb r5, [r0]
	cmp r6, 0
	bne _080434A6
	ldr r0, [r4]
	adds r3, 0xB9
	adds r0, r3
	strb r6, [r0]
	ldr r1, [r4]
	ldr r5, _080434E4
	adds r0, r1, r5
	str r6, [r0]
	movs r2, 0xD2
	lsls r2, 3
	adds r0, r1, r2
	str r6, [r0]
	adds r3, 0x1B
	adds r0, r1, r3
	str r6, [r0]
	subs r5, 0x2C
	adds r0, r1, r5
	strh r6, [r0]
	subs r2, 0x2E
	adds r0, r1, r2
	strh r6, [r0]
	subs r3, 0x26
	adds r1, r3
	mov r5, r10
	strb r5, [r1]
	ldr r0, [r4]
	ldr r1, _080434E8
	adds r0, r1
	strb r5, [r0]
	ldr r0, [r4]
	adds r2, 0xE
	adds r0, r2
	strb r5, [r0]
	ldr r0, [r4]
	adds r3, 0x8
	adds r0, r3
	strb r5, [r0]
	ldr r0, [r4]
	ldr r5, _080434EC
	adds r0, r5
	mov r1, r10
	strb r1, [r0]
	ldr r0, [r4]
	adds r2, 0x2
	adds r0, r2
	strb r1, [r0]
	ldr r1, [r4]
	subs r3, 0xC
	adds r2, r1, r3
	ldr r0, _080434F0
	strh r0, [r2]
	adds r5, 0x17
	adds r0, r1, r5
	strh r6, [r0]
	ldr r0, _080434F4
	adds r1, r0
	mov r2, r10
	strb r2, [r1]
	ldr r1, [r4]
	adds r3, 0x1A
	adds r0, r1, r3
	movs r2, 0x63
	strh r2, [r0]
	subs r5, 0x2
	adds r0, r1, r5
	strh r2, [r0]
	ldr r0, _080434F8
	adds r1, r0
	mov r2, r10
	strb r2, [r1]
	ldr r1, [r4]
	ldr r3, _080434FC
	adds r0, r1, r3
	ldrb r2, [r0]
	ldr r5, _08043500
	adds r0, r1, r5
	strh r2, [r0]
	ldr r2, _08043504
	adds r0, r1, r2
	ldrb r2, [r0]
	ldr r3, _08043508
	adds r0, r1, r3
	strh r2, [r0]
	ldr r5, _0804350C
	adds r0, r1, r5
	ldrb r0, [r0]
	ldr r2, _08043510
	adds r1, r2
	strh r0, [r1]
	movs r0, 0
	bl sub_807E5E4
	bl sub_80842F0
_080434A6:
	bl sub_803D8F0
	bl sub_8068658
	cmp r6, 0
	bne _08043514
	bl sub_80687AC
	b _0804351C
	.align 2, 0
_080434B8: .4byte gUnknown_81002D8
_080434BC: .4byte gUnknown_203B450
_080434C0: .4byte gUnknown_203B418
_080434C4: .4byte 0x000037ec
_080434C8: .4byte 0x000037fc
_080434CC: .4byte 0x000037fd
_080434D0: .4byte 0x000037fe
_080434D4: .4byte gUnknown_80F6850
_080434D8: .4byte 0x000037ff
_080434DC: .4byte 0x00000675
_080434E0: .4byte 0x0001c05e
_080434E4: .4byte 0x0000068c
_080434E8: .4byte 0x0000066f
_080434EC: .4byte 0x00000671
_080434F0: .4byte 0x000003e7
_080434F4: .4byte 0x0000068a
_080434F8: .4byte 0x0000e264
_080434FC: .4byte 0x0001c576
_08043500: .4byte 0x00003a0e
_08043504: .4byte 0x0001c577
_08043508: .4byte 0x00003a10
_0804350C: .4byte 0x0001c586
_08043510: .4byte 0x00003a14
_08043514:
	bl sub_8068768
	bl sub_8082B40
_0804351C:
	bl sub_806C42C
	bl sub_806AD3C
	cmp r6, 0
	bne _08043544
	ldr r1, _080435B4
	ldr r3, _080435B8
	ldr r0, [r3]
	ldr r5, _080435BC
	adds r0, r5
	movs r2, 0
	ldrsh r0, [r0, r2]
	lsls r0, 1
	adds r0, r1
	ldrh r0, [r0]
	bl sub_8083E88
	bl sub_80847D4
_08043544:
	bl sub_8049840
	bl sub_803E178
	ldr r0, _080435C0
	mov r3, r9
	str r3, [r0]
	bl sub_8040124
	movs r0, 0x4
	movs r1, 0
	bl sub_803EAF0
	movs r0, 0
	bl sub_8052210
	adds r0, r6, 0
	bl sub_803F27C
	bl ShowDungeonNameBanner
	cmp r6, 0
	bne _08043594
	bl sub_804AFAC
	ldr r5, _080435B8
	ldr r0, [r5]
	ldr r1, _080435C4
	adds r0, r1
	ldrb r0, [r0]
	bl GetUnkC
	ldr r2, [r5]
	ldr r3, _080435C8
	adds r1, r2, r3
	strh r0, [r1]
	ldr r5, _080435CC
	adds r2, r5
	mov r0, r10
	strb r0, [r2]
_08043594:
	bl sub_804AAD4
	bl sub_8049B8C
	bl sub_804966C
	cmp r6, 0
	bne _080435D0
	bl sub_806B168
	bl sub_806C3C0
	bl sub_806B6C4
	b _080435D4
	.align 2, 0
_080435B4: .4byte gUnknown_80F5668
_080435B8: .4byte gUnknown_203B418
_080435BC: .4byte 0x00003a10
_080435C0: .4byte gUnknown_202EDC8
_080435C4: .4byte 0x00000644
_080435C8: .4byte 0x00000666
_080435CC: .4byte 0x0000067a
_080435D0:
	bl sub_806B678
_080435D4:
	ldr r4, _0804362C
	ldr r1, [r4]
	ldr r2, _08043630
	adds r0, r1, r2
	mov r3, r9
	str r3, [r0]
	ldr r5, _08043634
	adds r0, r1, r5
	str r3, [r0]
	adds r2, 0x4
	adds r0, r1, r2
	str r3, [r0]
	ldr r3, _08043638
	adds r0, r1, r3
	mov r5, r9
	str r5, [r0]
	adds r2, 0x4
	adds r0, r1, r2
	str r5, [r0]
	adds r3, 0x4
	adds r1, r3
	str r5, [r1]
	cmp r6, 0
	bne _08043644
	bl sub_807FA18
	bl sub_8045CB0
	ldr r1, [r4]
	ldr r5, _0804363C
	adds r2, r1, r5
	ldr r3, _08043640
	adds r0, r1, r3
	ldr r0, [r0]
	str r0, [r2]
	subs r5, 0x4
	adds r1, r5
	str r6, [r1]
	bl sub_8051E3C
	bl sub_804AAAC
	b _08043648
	.align 2, 0
_0804362C: .4byte gUnknown_203B418
_08043630: .4byte 0x00017b2c
_08043634: .4byte 0x00017b38
_08043638: .4byte 0x00017b3c
_0804363C: .4byte 0x00000694
_08043640: .4byte 0x0000068c
_08043644:
	bl sub_806A338
_08043648:
	bl sub_8068F80
	bl sub_8049884
	bl sub_8049ED4
	cmp r6, 0
	bne _08043664
	movs r0, 0x1
	movs r1, 0
	movs r2, 0
	bl sub_806A914
	b _0804366C
_08043664:
	bl sub_806CF60
	bl sub_806A974
_0804366C:
	movs r0, 0x1
	bl sub_8041888
	cmp r6, 0
	bne _0804367E
	bl sub_80848F0
	bl sub_8097890
_0804367E:
	ldr r0, _080436A0
	movs r1, 0x1
	strb r1, [r0]
	cmp r6, 0
	beq _08043690
	bl sub_807E88C
	bl sub_806AB2C
_08043690:
	ldr r2, _080436A4
	ldr r0, [r2]
	ldrb r0, [r0, 0x7]
	cmp r0, 0
	bne _080436A8
	bl sub_803E748
	b _080436AC
	.align 2, 0
_080436A0: .4byte gUnknown_203B40C
_080436A4: .4byte gUnknown_203B418
_080436A8:
	bl sub_803E7C8
_080436AC:
	movs r0, 0
	bl sub_8040094
	movs r0, 0
	movs r1, 0
	bl sub_803EAF0
	adds r0, r6, 0
	bl sub_8040150
	bl sub_8040A84
	ldr r4, _08043730
	ldr r1, [r4]
	adds r0, r1, 0
	adds r0, 0xB8
	mov r3, r9
	str r3, [r0]
	ldr r5, _08043734
	adds r1, r5
	strb r3, [r1]
	ldr r0, [r4]
	ldr r1, _08043738
	adds r0, r1
	mov r2, r9
	strb r2, [r0]
	ldr r1, [r4]
	movs r5, 0
	movs r0, 0x63
	strh r0, [r1, 0x12]
	movs r3, 0x1
	strb r3, [r1]
	cmp r6, 0
	bne _08043706
	bl sub_8052DD0
	ldr r1, [r4]
	ldrb r0, [r1, 0x9]
	cmp r0, 0
	beq _08043706
	strb r5, [r1, 0x9]
	bl sub_8083D68
	bl sub_8052F80
_08043706:
	ldr r0, _0804373C
	mov r5, r9
	str r5, [r0]
	ldr r4, _08043730
	ldr r0, [r4]
	strb r5, [r0, 0x5]
	cmp r6, 0
	bne _08043778
	bl sub_8084B64
	ldr r1, [r4]
	ldrb r0, [r1, 0x4]
	cmp r0, 0
	bne _08043728
	ldrb r0, [r1, 0x2]
	cmp r0, 0
	beq _08043740
_08043728:
	movs r0, 0x1
	strb r0, [r1, 0x5]
	b _0804374C
	.align 2, 0
_08043730: .4byte gUnknown_203B418
_08043734: .4byte 0x0000066c
_08043738: .4byte 0x0000066d
_0804373C: .4byte gUnknown_203B450
_08043740:
	bl sub_8083600
	bl sub_803F4A0
	bl sub_8040A84
_0804374C:
	cmp r6, 0
	bne _08043778
	ldr r1, _08043774
	ldr r0, [r1]
	ldrb r0, [r0, 0x5]
	cmp r0, 0
	bne _0804377C
	bl sub_807E5AC
	movs r0, 0
	bl sub_807E580
	lsls r0, 24
	cmp r0, 0
	beq _0804377C
	movs r0, 0x1
	bl sub_807E7FC
	b _0804377C
	.align 2, 0
_08043774: .4byte gUnknown_203B418
_08043778:
	bl sub_8069E8C
_0804377C:
	cmp r6, 0
	beq _08043784
	movs r6, 0
	b _080437A2
_08043784:
	bl sub_80427AC
	bl sub_8083600
	ldr r2, _08043960
	ldr r1, [r2]
	ldr r3, _08043964
	adds r1, r3
	ldrb r1, [r1]
	bl sub_8075900
	movs r0, 0x1
	movs r1, 0
	bl sub_807EAA0
_080437A2:
	bl nullsub_16
	ldr r2, _08043960
	ldr r0, [r2]
	ldrb r1, [r0, 0x5]
	cmp r1, 0
	bne _080437DA
	movs r4, 0x1
	ldr r5, _08043968
	adds r0, r5
	strb r1, [r0]
	ldr r0, [r2]
	ldr r3, _0804396C
	adds r0, r3
	strb r1, [r0]
	ldr r0, [r2]
	ldr r5, _08043970
	adds r0, r5
	strb r4, [r0]
_080437C8:
	adds r0, r4, 0
	bl RunDungeon
	movs r4, 0
	bl sub_8044B28
	lsls r0, 24
	cmp r0, 0
	beq _080437C8
_080437DA:
	bl sub_8083600
	adds r4, r0, 0
	bl sub_80450E0
	lsls r0, 24
	cmp r0, 0
	beq _080437F0
	adds r0, r4, 0
	bl sub_8071DA4
_080437F0:
	ldr r5, _08043960
	ldr r0, [r5]
	ldr r4, _08043968
	adds r0, r4
	ldrb r0, [r0]
	cmp r0, 0x1
	beq _08043822
	movs r0, 0x1
	bl sub_8043ED0
	lsls r0, 24
	cmp r0, 0
	beq _08043812
	ldr r0, [r5]
	adds r0, r4
	movs r1, 0x1
	strb r1, [r0]
_08043812:
	ldr r1, [r5]
	adds r0, r1, r4
	ldrb r0, [r0]
	cmp r0, 0x1
	beq _08043822
	ldrb r0, [r1, 0x11]
	cmp r0, 0
	beq _08043830
_08043822:
	ldr r2, _08043960
	ldr r0, [r2]
	ldrb r0, [r0, 0x6]
	cmp r0, 0
	bne _08043830
	bl sub_806AA70
_08043830:
	bl sub_8083600
	bl sub_80450E0
	lsls r0, 24
	cmp r0, 0
	beq _0804384A
	movs r0, 0x4F
	bl sub_80526D0
	movs r0, 0x4F
	bl sub_8052740
_0804384A:
	bl sub_8040124
	movs r0, 0x1
	movs r1, 0
	bl sub_803EAF0
	ldr r3, _08043960
	ldr r0, [r3]
	ldr r5, _08043970
	adds r0, r5
	mov r1, r9
	strb r1, [r0]
	ldr r0, [r3]
	ldr r2, _0804396C
	adds r0, r2
	movs r3, 0x1
	strb r3, [r0]
	ldr r5, _08043960
	ldr r1, [r5]
	ldrb r0, [r1, 0x3]
	cmp r0, 0
	bne _08043896
	ldrb r0, [r1, 0x6]
	cmp r0, 0
	bne _08043896
	ldr r2, _08043974
	adds r0, r1, r2
	ldrh r0, [r0]
	cmp r0, 0x72
	bne _08043896
	ldr r3, _08043978
	adds r0, r1, r3
	ldrb r0, [r0]
	cmp r0, 0x1B
	bne _08043896
	movs r0, 0x3C
	bl sub_8083ED8
_08043896:
	movs r0, 0x4
	movs r1, 0x4F
	bl sub_803E708
	ldr r5, _08043960
	ldr r0, [r5]
	ldrb r0, [r0, 0x7]
	cmp r0, 0
	bne _080438AC
	bl sub_803E830
_080438AC:
	movs r0, 0
	bl SetBGOBJEnableFlags
	ldr r1, _0804397C
	ldr r0, [sp, 0x4]
	ands r0, r1
	movs r1, 0x60
	orrs r0, r1
	ldr r1, _08043980
	ands r0, r1
	movs r1, 0x80
	lsls r1, 8
	orrs r0, r1
	ldr r1, _08043984
	ands r0, r1
	movs r1, 0xF8
	lsls r1, 16
	orrs r0, r1
	str r0, [sp, 0x4]
	ldr r0, _08043988
	ldr r2, [r0]
	movs r0, 0xFD
	ldr r1, [sp, 0x8]
	movs r3, 0
	bl SetBGPaletteBufferColorRGB
	movs r0, 0x1
	bl sub_8040094
	ldr r0, [r5]
	ldr r1, _0804396C
	adds r0, r1
	movs r7, 0
	movs r2, 0x1
	strb r2, [r0]
	ldr r1, [r5]
	ldrb r0, [r1, 0x10]
	subs r0, 0x2
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bhi _08043926
	ldrb r0, [r1, 0x6]
	cmp r0, 0
	beq _08043926
	bl sub_8083600
	adds r4, r0, 0
	ldr r0, _0804398C
	ldr r1, [r0]
	movs r0, 0
	movs r2, 0x1
	bl PrintFieldMessage
	ldr r0, [r5]
	strb r7, [r0, 0x6]
	ldr r0, _08043990
	adds r1, r4, 0
	adds r2, r4, 0
	bl sub_8083AB0
_08043926:
	bl sub_80688CC
	bl sub_8049820
	ldr r0, _08043994
	ldr r0, [r0]
	bl CloseFile
	bl sub_800F740
	ldr r0, _08043998
	mov r3, r10
	strb r3, [r0]
	ldr r4, _08043960
	ldr r1, [r4]
	ldrb r0, [r1, 0x3]
	cmp r0, 0
	beq _0804394C
	b _08043BFC
_0804394C:
	ldrb r0, [r1, 0x6]
	cmp r0, 0
	beq _080439A0
	ldr r0, _0804399C
	ldr r0, [r0]
	movs r1, 0x90
	lsls r1, 7
	bl sub_8080B30
	b _080439A6
	.align 2, 0
_08043960: .4byte gUnknown_203B418
_08043964: .4byte 0x00003a08
_08043968: .4byte 0x00000654
_0804396C: .4byte 0x00018218
_08043970: .4byte 0x00018219
_08043974: .4byte 0x0001ceda
_08043978: .4byte 0x00000644
_0804397C: .4byte 0xffffff00
_08043980: .4byte 0xffff00ff
_08043984: .4byte 0xff00ffff
_08043988: .4byte gUnknown_202EDC8
_0804398C: .4byte gUnknown_81006A4
_08043990: .4byte 0x00000222
_08043994: .4byte gDungeonNameBannerPalette
_08043998: .4byte gUnknown_203B40C
_0804399C: .4byte gUnknown_203B41C
_080439A0:
	movs r0, 0x2
	bl sub_8046F84
_080439A6:
	bl sub_806C1D8
	ldr r4, _080439CC
	ldr r1, [r4]
	ldr r5, _080439D0
	adds r0, r1, r5
	ldrb r0, [r0]
	cmp r0, 0x1
	bne _080439D4
	adds r5, 0x1A
	adds r0, r1, r5
	ldrb r0, [r0]
	cmp r0, 0
	bne _080439C4
	b _08043AF4
_080439C4:
	bl sub_804700C
	b _08043AF4
	.align 2, 0
_080439CC: .4byte gUnknown_203B418
_080439D0: .4byte 0x00000654
_080439D4:
	ldrb r0, [r1, 0x11]
	cmp r0, 0x1
	bne _080439DC
	b _080432C8
_080439DC:
	cmp r0, 0x2
	bne _08043A00
	bl sub_8083600
	adds r2, r0, 0
	ldr r0, _080439F8
	movs r1, 0
	bl sub_8083AB0
	ldr r0, [r4]
	ldr r1, _080439FC
	adds r0, r1
	b _08043A62
	.align 2, 0
_080439F8: .4byte 0x00000229
_080439FC: .4byte 0x0000066e
_08043A00:
	cmp r0, 0x3
	bne _08043A24
	bl sub_8083600
	adds r2, r0, 0
	ldr r0, _08043A1C
	movs r1, 0
	bl sub_8083AB0
	ldr r0, [r4]
	ldr r2, _08043A20
	adds r0, r2
	b _08043A62
	.align 2, 0
_08043A1C: .4byte 0x0000022a
_08043A20: .4byte 0x0000066e
_08043A24:
	cmp r0, 0x4
	bne _08043A2A
	b _080432D0
_08043A2A:
	movs r3, 0xCF
	lsls r3, 3
	adds r0, r1, r3
	ldrb r0, [r0]
	cmp r0, 0x1
	bne _08043A74
	bl sub_8043D10
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x2
	bne _08043A74
	ldr r0, [r4]
	adds r0, r5
	ldrb r0, [r0]
	cmp r0, 0x2
	bne _08043A74
	bl sub_8083600
	adds r2, r0, 0
	movs r0, 0x8A
	lsls r0, 2
	movs r1, 0
	bl sub_8083AB0
	ldr r0, [r4]
	ldr r5, _08043A70
	adds r0, r5
_08043A62:
	ldrb r0, [r0]
	cmp r0, 0
	beq _08043AF4
	bl sub_8097810
	b _08043AF4
	.align 2, 0
_08043A70: .4byte 0x0000066e
_08043A74:
	ldr r4, _08043ACC
	ldr r0, [r4]
	ldr r1, _08043AD0
	adds r0, r1
	ldrb r0, [r0]
	cmp r0, 0
	beq _08043A86
	bl sub_8097810
_08043A86:
	ldr r1, [r4]
	ldr r3, _08043AD4
	adds r2, r1, r3
	ldrb r0, [r2]
	adds r0, 0x1
	ldr r5, _08043AD8
	adds r1, r5
	ldrb r1, [r1]
	cmp r0, r1
	bge _08043AE4
	strb r0, [r2]
	ldr r0, [r4]
	ldr r1, _08043ADC
	adds r0, r1
	ldrh r1, [r0]
	ldr r0, _08043AE0
	cmp r1, r0
	beq _08043AAC
	b _080432FC
_08043AAC:
	movs r0, 0x1F
	bl sub_8098100
	lsls r0, 24
	cmp r0, 0
	beq _08043ABA
	b _080432FC
_08043ABA:
	movs r0, 0x1F
	bl sub_8097FA8
	bl sub_8086130
	bl sub_8097FF8
	b _080432FC
	.align 2, 0
_08043ACC: .4byte gUnknown_203B418
_08043AD0: .4byte 0x0000066e
_08043AD4: .4byte 0x00000645
_08043AD8: .4byte 0x0001cec8
_08043ADC: .4byte 0x00000644
_08043AE0: .4byte 0x0000060b
_08043AE4:
	ldr r4, _08043B80
	bl sub_8083600
	adds r2, r0, 0
	adds r0, r4, 0
	movs r1, 0
	bl sub_8083AB0
_08043AF4:
	ldr r1, _08043B84
	movs r0, 0
	strb r0, [r1]
	mov r4, r8
	adds r4, 0x7E
	movs r0, 0
	strb r0, [r4]
	bl sub_8097FF8
	movs r0, 0x1
	movs r1, 0x14
	bl sub_80095CC
	bl sub_803E13C
	movs r0, 0x4
	bl sub_800CDA8
	ldr r0, _08043B88
	ldr r1, [r0]
	ldrb r0, [r1, 0x6]
	cmp r0, 0
	bne _08043B38
	movs r2, 0xCF
	lsls r2, 3
	adds r0, r1, r2
	ldrb r0, [r0]
	bl sub_8083C88
	lsls r0, 24
	cmp r0, 0
	beq _08043B38
	bl sub_80841EC
_08043B38:
	bl sub_8083C24
	lsls r0, 24
	cmp r0, 0
	beq _08043BA4
	ldr r5, _08043B88
	ldr r0, [r5]
	ldrb r0, [r0, 0x6]
	cmp r0, 0
	beq _08043B98
	ldr r0, _08043B8C
	ldr r3, [sp, 0xC]
	strh r0, [r3]
	mov r4, r8
	adds r4, 0x84
	adds r0, r4, 0
	movs r1, 0
	movs r2, 0x8
	bl memset
	mov r3, r8
	adds r3, 0x80
	ldr r1, [r5]
	ldr r5, _08043B90
	adds r2, r1, r5
	ldr r0, [r2]
	str r0, [r3]
	ldr r0, [r2]
	str r0, [r4]
	mov r2, r8
	adds r2, 0x88
	ldr r0, _08043B94
	adds r1, r0
	ldr r0, [r1]
	str r0, [r2]
	b _08043C32
	.align 2, 0
_08043B80: .4byte 0x00000227
_08043B84: .4byte gUnknown_203B40C
_08043B88: .4byte gUnknown_203B418
_08043B8C: .4byte 0x0000fffe
_08043B90: .4byte 0x00000644
_08043B94: .4byte 0x0000067c
_08043B98:
	ldr r0, _08043BA0
	ldr r1, [sp, 0xC]
	strh r0, [r1]
	b _08043C32
	.align 2, 0
_08043BA0: .4byte 0x0000ffff
_08043BA4:
	bl sub_8083C50
	lsls r0, 24
	cmp r0, 0
	beq _08043C28
	ldr r0, _08043BC8
	ldr r0, [r0]
	movs r2, 0xCF
	lsls r2, 3
	adds r0, r2
	ldrb r0, [r0]
	cmp r0, 0x1
	bne _08043BCC
	movs r0, 0x4
	ldr r3, [sp, 0xC]
	strh r0, [r3]
	b _08043BE6
	.align 2, 0
_08043BC8: .4byte gUnknown_203B418
_08043BCC:
	cmp r0, 0
	bne _08043BDC
	movs r0, 0x1
	ldr r5, [sp, 0xC]
	strh r0, [r5]
	bl sub_8084424
	b _08043BE6
_08043BDC:
	movs r0, 0x1
	ldr r1, [sp, 0xC]
	strh r0, [r1]
	bl sub_8084424
_08043BE6:
	ldr r0, _08043BF4
	ldr r0, [r0]
	ldr r2, _08043BF8
	adds r0, r2
	ldrb r0, [r0]
	strb r0, [r4]
	b _08043C32
	.align 2, 0
_08043BF4: .4byte gUnknown_203B418
_08043BF8: .4byte 0x00000674
_08043BFC:
	ldr r0, _08043C20
	ldr r0, [r0]
	movs r1, 0x90
	lsls r1, 7
	bl sub_8080B30
	movs r0, 0x3
	ldr r3, [sp, 0xC]
	strh r0, [r3]
	mov r1, r8
	adds r1, 0x80
	ldr r0, [r4]
	ldr r5, _08043C24
	adds r0, r5
	ldr r0, [r0]
	str r0, [r1]
	b _08043C32
	.align 2, 0
_08043C20: .4byte gUnknown_203B41C
_08043C24: .4byte 0x00000644
_08043C28:
	movs r0, 0x2
	ldr r1, [sp, 0xC]
	strh r0, [r1]
	bl sub_8084424
_08043C32:
	bl sub_806863C
	bl sub_803E214
	bl nullsub_56
	bl sub_8040218
	ldr r2, [sp, 0xC]
	movs r3, 0
	ldrsh r0, [r2, r3]
	cmp r0, 0x1
	beq _08043C54
	cmp r0, 0x4
	beq _08043C54
	cmp r0, 0x2
	bne _08043C58
_08043C54:
	bl sub_8047104
_08043C58:
	ldr r5, [sp, 0xC]
	movs r0, 0
	ldrsh r1, [r5, r0]
	cmp r1, 0x1
	beq _08043C8A
	movs r0, 0x2
	negs r0, r0
	cmp r1, r0
	beq _08043C78
	cmp r1, 0x4
	beq _08043C78
	adds r0, 0x1
	cmp r1, r0
	beq _08043C78
	cmp r1, 0x2
	bne _08043CAC
_08043C78:
	ldr r2, [sp, 0xC]
	movs r3, 0
	ldrsh r1, [r2, r3]
	cmp r1, 0x1
	beq _08043C8A
	cmp r1, 0x4
	beq _08043C8A
	cmp r1, 0x2
	bne _08043C92
_08043C8A:
	movs r0, 0x1
	bl sub_8068BDC
	b _08043CAC
_08043C92:
	movs r0, 0x2
	negs r0, r0
	cmp r1, r0
	bne _08043CA2
	movs r0, 0
	bl sub_8068BDC
	b _08043CAC
_08043CA2:
	bl sub_8068F28
	movs r0, 0
	bl sub_8068BDC
_08043CAC:
	bl sub_800DB7C
	ldr r0, _08043CD0
	movs r1, 0
	str r1, [r0]
	ldr r0, _08043CD4
	str r1, [r0]
	bl nullsub_16
	add sp, 0x10
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_08043CD0: .4byte gUnknown_203B418
_08043CD4: .4byte gUnknown_203B41C
	thumb_func_end xxx_dungeon_8042F6C

	thumb_func_start sub_8043CD8
sub_8043CD8:
	push {lr}
	bl vram_related_8009804
	pop {r0}
	bx r0
	thumb_func_end sub_8043CD8

	thumb_func_start sub_8043CE4
sub_8043CE4:
	push {lr}
	adds r1, r0, 0
	ldr r0, _08043CF4
	ldrb r0, [r0]
	cmp r0, 0
	beq _08043CF8
	movs r0, 0x1
	b _08043D08
	.align 2, 0
_08043CF4: .4byte gUnknown_202F1A8
_08043CF8:
	movs r2, 0
	ldr r0, _08043D0C
	adds r0, r1, r0
	ldrb r0, [r0]
	cmp r0, 0x2
	bne _08043D06
	movs r2, 0x1
_08043D06:
	adds r0, r2, 0
_08043D08:
	pop {r1}
	bx r1
	.align 2, 0
_08043D0C: .4byte gUnknown_810ACC0
	thumb_func_end sub_8043CE4

	thumb_func_start sub_8043D10
sub_8043D10:
	push {lr}
	ldr r0, _08043D38
	ldr r1, [r0]
	movs r2, 0xCF
	lsls r2, 3
	adds r0, r1, r2
	ldrb r0, [r0]
	cmp r0, 0x1
	bne _08043D3C
	subs r2, 0x2B
	adds r0, r1, r2
	subs r2, 0x8
	adds r1, r2
	ldrb r0, [r0]
	ldrb r1, [r1]
	cmp r0, r1
	bne _08043D3C
	movs r0, 0x2
	b _08043D4C
	.align 2, 0
_08043D38: .4byte gUnknown_203B418
_08043D3C:
	bl sub_80441BC
	lsls r0, 24
	cmp r0, 0
	bne _08043D4A
	movs r0, 0
	b _08043D4C
_08043D4A:
	movs r0, 0x1
_08043D4C:
	pop {r1}
	bx r1
	thumb_func_end sub_8043D10

	thumb_func_start sub_8043D50
sub_8043D50:
	ldr r2, _08043D5C
	str r2, [r1]
	movs r1, 0x90
	lsls r1, 7
	str r1, [r0]
	bx lr
	.align 2, 0
_08043D5C: .4byte 0x0001cedc
	thumb_func_end sub_8043D50

	thumb_func_start sub_8043D60
sub_8043D60:
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	movs r5, 0
_08043D6A:
	ldr r0, _08043DA4
	ldr r0, [r0]
	lsls r1, r5, 2
	ldr r2, _08043DA8
	adds r0, r2
	adds r0, r1
	ldr r4, [r0]
	adds r0, r4, 0
	bl sub_80450E0
	lsls r0, 24
	cmp r0, 0
	beq _08043DCE
	ldr r2, [r4, 0x70]
	movs r1, 0x1
	ldrb r0, [r2, 0x8]
	eors r0, r1
	negs r1, r0
	orrs r1, r0
	lsrs r1, 31
	adds r0, r2, 0
	adds r0, 0x40
	ldrb r0, [r0]
	cmp r0, 0x4A
	beq _08043DA0
	cmp r0, 0x47
	bne _08043DAC
_08043DA0:
	movs r0, 0x1
	b _08043DAE
	.align 2, 0
_08043DA4: .4byte gUnknown_203B418
_08043DA8: .4byte 0x0001358c
_08043DAC:
	movs r0, 0
_08043DAE:
	cmp r0, 0
	beq _08043DB4
	movs r1, 0
_08043DB4:
	adds r0, r2, 0
	adds r0, 0xA4
	ldrb r0, [r0]
	cmp r0, 0x1
	bne _08043DC0
	movs r1, 0
_08043DC0:
	cmp r1, 0
	beq _08043DCE
	adds r0, r4, 0
	ldr r1, _08043EC0
	adds r2, r4, 0
	bl sub_8068FE0
_08043DCE:
	adds r5, 0x1
	cmp r5, 0xF
	ble _08043D6A
	movs r5, 0
	ldr r0, _08043EC4
	mov r9, r0
	mov r8, r5
_08043DDC:
	mov r1, r9
	ldr r0, [r1]
	lsls r1, r5, 2
	ldr r2, _08043EC8
	adds r0, r2
	adds r0, r1
	ldr r4, [r0]
	adds r0, r4, 0
	bl sub_80450E0
	lsls r0, 24
	adds r7, r5, 0x1
	cmp r0, 0
	beq _08043E62
	adds r0, r4, 0
	adds r0, 0x22
	mov r1, r8
	strb r1, [r0]
	adds r1, r4, 0
	adds r1, 0x20
	movs r0, 0x1
	strb r0, [r1]
	ldr r4, [r4, 0x70]
	ldrh r0, [r4, 0x10]
	strh r0, [r4, 0xE]
	movs r2, 0x9E
	lsls r2, 1
	adds r1, r4, r2
	adds r2, 0x4
	adds r0, r4, r2
	ldr r0, [r0]
	str r0, [r1]
	mov r1, r9
	ldr r0, [r1]
	ldr r2, _08043ECC
	adds r0, r2
	mov r1, r8
	strb r1, [r0]
	adds r0, r4, 0
	movs r1, 0
	bl sub_806BFC0
	ldrh r0, [r4, 0x2]
	strh r0, [r4, 0x4]
	adds r0, r4, 0
	adds r0, 0xFD
	mov r2, r8
	strb r2, [r0]
	movs r0, 0x8C
	lsls r0, 1
	adds r5, r4, r0
	adds r4, r5, 0
	movs r6, 0x3
_08043E46:
	ldrb r1, [r4]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _08043E58
	adds r0, r5, 0
	bl sub_8092BF4
	strb r0, [r4, 0x4]
_08043E58:
	adds r4, 0x8
	adds r5, 0x8
	subs r6, 0x1
	cmp r6, 0
	bge _08043E46
_08043E62:
	adds r5, r7, 0
	cmp r5, 0x3
	ble _08043DDC
	movs r6, 0
_08043E6A:
	movs r5, 0
	adds r7, r6, 0x1
_08043E6E:
	adds r0, r5, 0
	adds r1, r6, 0
	bl sub_8049590
	ldr r4, [r0, 0x14]
	adds r0, r4, 0
	bl sub_80450E0
	lsls r0, 24
	cmp r0, 0
	beq _08043EA0
	adds r0, r4, 0
	bl sub_80450F8
	cmp r0, 0x2
	bne _08043EA0
	adds r0, r4, 0
	bl sub_8045104
	adds r1, r0, 0
	ldrb r0, [r1]
	cmp r0, 0x1B
	bne _08043EA0
	movs r0, 0x5
	strb r0, [r1]
_08043EA0:
	adds r5, 0x1
	cmp r5, 0x37
	ble _08043E6E
	adds r6, r7, 0
	cmp r6, 0x1F
	ble _08043E6A
	movs r0, 0x2
	bl sub_8046F84
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_08043EC0: .4byte 0x00000207
_08043EC4: .4byte gUnknown_203B418
_08043EC8: .4byte 0x0001357c
_08043ECC: .4byte 0x00000676
	thumb_func_end sub_8043D60

	thumb_func_start sub_8043ED0
sub_8043ED0:
	push {r4-r7,lr}
	lsls r0, 24
	lsrs r5, r0, 24
	movs r7, 0
	cmp r5, 0
	bne _08043EEA
	bl sub_8044B28
	lsls r0, 24
	cmp r0, 0
	beq _08043EEA
	movs r0, 0
	b _08043FB8
_08043EEA:
	ldr r6, _08043F2C
	ldr r0, [r6]
	ldrb r0, [r0, 0x10]
	cmp r0, 0x1
	bne _08043F40
	bl sub_8083600
	adds r4, r0, 0
	bl sub_80450E0
	lsls r0, 24
	cmp r0, 0
	beq _08043FB6
	cmp r5, 0
	bne _08043F20
	ldr r0, _08043F30
	ldr r1, [r6]
	ldr r2, _08043F34
	adds r1, r2
	bl strcpy
	ldr r0, _08043F38
	ldr r1, [r0]
	movs r0, 0
	movs r2, 0x1
	bl PrintFieldMessage
_08043F20:
	adds r0, r4, 0
	bl sub_8042B0C
	ldr r1, _08043F3C
	b _08043FAC
	.align 2, 0
_08043F2C: .4byte gUnknown_203B418
_08043F30: .4byte gUnknown_202DF98
_08043F34: .4byte 0x000005f4
_08043F38: .4byte gUnknown_80F89B4
_08043F3C: .4byte 0x0000021f
_08043F40:
	cmp r0, 0x2
	bne _08043F74
	bl sub_8083600
	adds r4, r0, 0
	bl sub_80450E0
	lsls r0, 24
	cmp r0, 0
	beq _08043FB6
	cmp r5, 0
	bne _08043FA4
	ldr r0, _08043F68
	ldr r1, [r6]
	ldr r2, _08043F6C
	adds r1, r2
	bl strcpy
	ldr r0, _08043F70
	b _08043F9A
	.align 2, 0
_08043F68: .4byte gUnknown_202DF98
_08043F6C: .4byte 0x000005f4
_08043F70: .4byte gUnknown_80F89D4
_08043F74:
	cmp r0, 0x3
	bne _08043FB6
	bl sub_8083600
	adds r4, r0, 0
	bl sub_80450E0
	lsls r0, 24
	cmp r0, 0
	beq _08043FB6
	cmp r5, 0
	bne _08043FA4
	ldr r0, _08043FC0
	ldr r1, [r6]
	ldr r2, _08043FC4
	adds r1, r2
	bl strcpy
	ldr r0, _08043FC8
_08043F9A:
	ldr r1, [r0]
	movs r0, 0
	movs r2, 0x1
	bl PrintFieldMessage
_08043FA4:
	adds r0, r4, 0
	bl sub_8042B0C
	ldr r1, _08043FCC
_08043FAC:
	adds r0, r4, 0
	adds r2, r4, 0
	bl sub_8068FE0
	movs r7, 0x1
_08043FB6:
	adds r0, r7, 0
_08043FB8:
	pop {r4-r7}
	pop {r1}
	bx r1
	.align 2, 0
_08043FC0: .4byte gUnknown_202DF98
_08043FC4: .4byte 0x000005f4
_08043FC8: .4byte gUnknown_80F89D8
_08043FCC: .4byte 0x00000222
	thumb_func_end sub_8043ED0

	thumb_func_start sub_8043FD0
sub_8043FD0:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x44
	movs r0, 0x2
	mov r9, r0
	movs r1, 0x1
	mov r10, r1
	movs r0, 0xFF
	mov r8, r0
_08043FE8:
	movs r3, 0
	mov r1, r9
	adds r1, 0x1
	str r1, [sp, 0x3C]
_08043FF0:
	ldr r2, _080440E4
	movs r0, 0x58
	adds r1, r3, 0
	muls r1, r0
	ldr r0, [r2]
	adds r4, r0, r1
	ldrh r1, [r4]
	mov r0, r10
	ands r0, r1
	adds r3, 0x1
	str r3, [sp, 0x40]
	cmp r0, 0
	beq _080440FE
	lsrs r0, r1, 1
	mov r1, r10
	ands r0, r1
	cmp r0, 0
	beq _080440FE
	add r5, sp, 0x20
	movs r0, 0x8
	ldrsh r1, [r4, r0]
	adds r0, r5, 0
	mov r2, r9
	bl sub_808E010
	mov r1, r9
	strb r1, [r4, 0x3]
	ldr r0, [sp, 0x20]
	str r0, [r4, 0x1C]
	ldrh r0, [r5, 0x4]
	ldrh r1, [r4, 0x16]
	adds r0, r1
	movs r2, 0
	strh r0, [r4, 0x16]
	lsls r0, 16
	ldr r1, _080440E8
	cmp r0, r1
	ble _08044040
	ldr r0, _080440EC
	strh r0, [r4, 0x16]
_08044040:
	ldrb r0, [r4, 0x18]
	str r0, [sp, 0x2C]
	ldrb r0, [r4, 0x19]
	str r0, [sp, 0x30]
	ldrb r0, [r4, 0x1A]
	str r0, [sp, 0x34]
	ldrb r0, [r4, 0x1B]
	str r0, [sp, 0x38]
	ldrb r1, [r5, 0x6]
	ldr r0, [sp, 0x2C]
	adds r0, r1
	str r0, [sp, 0x2C]
	ldrb r1, [r5, 0x7]
	ldr r0, [sp, 0x30]
	adds r0, r1
	str r0, [sp, 0x30]
	ldrb r1, [r5, 0x8]
	ldr r0, [sp, 0x34]
	adds r0, r1
	str r0, [sp, 0x34]
	ldrb r1, [r5, 0x9]
	ldr r0, [sp, 0x38]
	adds r0, r1
	str r0, [sp, 0x38]
	ldr r0, [sp, 0x2C]
	cmp r0, 0xFE
	ble _0804407A
	mov r0, r8
	str r0, [sp, 0x2C]
_0804407A:
	ldr r0, [sp, 0x30]
	cmp r0, 0xFE
	ble _08044084
	mov r1, r8
	str r1, [sp, 0x30]
_08044084:
	ldr r0, [sp, 0x34]
	cmp r0, 0xFE
	ble _0804408E
	mov r0, r8
	str r0, [sp, 0x34]
_0804408E:
	ldr r0, [sp, 0x38]
	cmp r0, 0xFE
	ble _08044098
	mov r1, r8
	str r1, [sp, 0x38]
_08044098:
	ldr r0, [sp, 0x2C]
	strb r0, [r4, 0x18]
	ldr r0, [sp, 0x30]
	strb r0, [r4, 0x19]
	ldr r0, [sp, 0x34]
	strb r0, [r4, 0x1A]
	ldr r0, [sp, 0x38]
	strb r0, [r4, 0x1B]
	movs r0, 0x8
	ldrsh r1, [r4, r0]
	ldrb r2, [r4, 0x3]
	mov r0, sp
	ldr r3, _080440EC
	bl sub_808E0AC
	adds r6, r0, 0
	cmp r6, 0
	beq _080440FE
	movs r0, 0
	cmp r0, r6
	bge _080440FE
_080440C2:
	movs r3, 0
	adds r7, r0, 0x1
	lsls r0, 1
	mov r1, sp
	adds r5, r1, r0
	adds r2, r4, 0
	adds r2, 0x2C
_080440D0:
	ldrb r1, [r2]
	mov r0, r10
	ands r0, r1
	cmp r0, 0
	bne _080440F0
	ldrh r1, [r5]
	adds r0, r2, 0
	bl sub_8092AD4
	b _080440F8
	.align 2, 0
_080440E4: .4byte gUnknown_203B45C
_080440E8: .4byte 0x03e60000
_080440EC: .4byte 0x000003e7
_080440F0:
	adds r2, 0x8
	adds r3, 0x1
	cmp r3, 0x3
	ble _080440D0
_080440F8:
	adds r0, r7, 0
	cmp r0, r6
	blt _080440C2
_080440FE:
	ldr r3, [sp, 0x40]
	movs r0, 0xCE
	lsls r0, 1
	cmp r3, r0
	bgt _0804410A
	b _08043FF0
_0804410A:
	ldr r0, [sp, 0x3C]
	mov r9, r0
	cmp r0, 0x5
	bgt _08044114
	b _08043FE8
_08044114:
	add sp, 0x44
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_8043FD0

	thumb_func_start sub_8044124
sub_8044124:
	push {r4,r5,lr}
	ldr r0, _080441AC
	ldr r0, [r0]
	ldr r1, _080441B0
	adds r0, r1
	ldrb r0, [r0]
	bl GetMaxItemCount
	cmp r0, 0
	bne _08044182
	movs r3, 0
	ldr r4, _080441B4
	movs r2, 0
_0804413E:
	lsls r1, r3, 2
	ldr r0, [r4]
	adds r1, r0
	strb r2, [r1, 0x2]
	strb r2, [r1, 0x1]
	strb r2, [r1]
	adds r3, 0x1
	cmp r3, 0x13
	ble _0804413E
	movs r3, 0
	ldr r5, _080441B8
	movs r4, 0x1
_08044156:
	movs r0, 0x58
	adds r1, r3, 0
	muls r1, r0
	ldr r0, [r5]
	adds r1, r0, r1
	ldrh r2, [r1]
	adds r0, r4, 0
	ands r0, r2
	cmp r0, 0
	beq _08044178
	lsrs r0, r2, 1
	ands r0, r4
	cmp r0, 0
	beq _08044178
	adds r1, 0x28
	movs r0, 0
	strb r0, [r1]
_08044178:
	adds r3, 0x1
	movs r0, 0xCE
	lsls r0, 1
	cmp r3, r0
	ble _08044156
_08044182:
	ldr r0, _080441AC
	ldr r0, [r0]
	ldr r2, _080441B0
	adds r0, r2
	ldrb r0, [r0]
	bl GetMoneyCondition
	lsls r0, 24
	lsrs r1, r0, 24
	cmp r1, 0
	bne _080441A4
	ldr r0, _080441B4
	ldr r0, [r0]
	movs r2, 0x98
	lsls r2, 2
	adds r0, r2
	str r1, [r0]
_080441A4:
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_080441AC: .4byte gUnknown_203B418
_080441B0: .4byte 0x00000644
_080441B4: .4byte gUnknown_203B460
_080441B8: .4byte gUnknown_203B45C
	thumb_func_end sub_8044124

	thumb_func_start sub_80441BC
sub_80441BC:
	push {lr}
	ldr r0, _080441D8
	ldr r0, [r0]
	ldr r1, _080441DC
	adds r0, r1
	movs r1, 0
	ldrsh r0, [r0, r1]
	cmp r0, 0
	beq _080441E0
	cmp r0, 0x31
	bgt _080441E0
	movs r0, 0x1
	b _080441E2
	.align 2, 0
_080441D8: .4byte gUnknown_203B418
_080441DC: .4byte 0x00003a14
_080441E0:
	movs r0, 0
_080441E2:
	pop {r1}
	bx r1
	thumb_func_end sub_80441BC

	thumb_func_start sub_80441E8
sub_80441E8:
	push {lr}
	ldr r0, _08044200
	ldr r0, [r0]
	ldr r1, _08044204
	adds r0, r1
	movs r1, 0
	ldrsh r0, [r0, r1]
	cmp r0, 0x3F
	bgt _08044208
	movs r0, 0
	b _0804420A
	.align 2, 0
_08044200: .4byte gUnknown_203B418
_08044204: .4byte 0x00003a0e
_08044208:
	movs r0, 0x1
_0804420A:
	pop {r1}
	bx r1
	thumb_func_end sub_80441E8

	thumb_func_start sub_8044210
sub_8044210:
	push {lr}
	ldr r0, _0804422C
	ldr r0, [r0]
	ldr r1, _08044230
	adds r0, r1
	ldrb r0, [r0]
	subs r0, 0x4B
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x16
	bls _08044234
	movs r0, 0
	b _08044236
	.align 2, 0
_0804422C: .4byte gUnknown_203B418
_08044230: .4byte 0x00000644
_08044234:
	movs r0, 0x1
_08044236:
	pop {r1}
	bx r1
	thumb_func_end sub_8044210

	thumb_func_start RunDungeon
RunDungeon:
	push {r4,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	bl sub_8044B28
	lsls r0, 24
	cmp r0, 0
	bne _080442C6
	bl sub_8044994
	bl sub_8044B28
	lsls r0, 24
	cmp r0, 0
	bne _080442C6
	adds r0, r4, 0
	bl xxx_dungeon_80442D0
	lsls r0, 24
	lsrs r4, r0, 24
	bl sub_8044B28
	lsls r0, 24
	cmp r0, 0
	bne _080442C6
	cmp r4, 0
	beq _08044280
	bl sub_807E378
	bl sub_8044B28
	lsls r0, 24
	cmp r0, 0
	bne _080442C6
_08044280:
	bl sub_8044B28
	lsls r0, 24
	cmp r0, 0
	bne _080442C6
	bl sub_8044574
	bl sub_8044B28
	lsls r0, 24
	cmp r0, 0
	bne _080442C6
	bl sub_8044820
	bl sub_8044B28
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0
	bne _080442C6
	bl sub_8044AB4
	ldr r0, _080442CC
	ldr r0, [r0]
	movs r2, 0xCC
	lsls r2, 3
	adds r1, r0, r2
	ldrh r0, [r1]
	adds r0, 0x1
	strh r0, [r1]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x18
	bne _080442C6
	strh r4, [r1]
_080442C6:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080442CC: .4byte gUnknown_203B418
	thumb_func_end RunDungeon

	thumb_func_start xxx_dungeon_80442D0
xxx_dungeon_80442D0:
	push {r4-r7,lr}
	lsls r0, 24
	lsrs r7, r0, 24
	bl sub_8083600
	adds r5, r0, 0
	cmp r5, 0
	beq _0804431A
	bl sub_8069E8C
	adds r0, r5, 0
	bl sub_8070774
	ldr r3, _08044320
	ldr r1, _08044324
	ldr r1, [r1]
	movs r2, 0xCC
	lsls r2, 3
	adds r1, r2
	movs r2, 0
	ldrsh r1, [r1, r2]
	lsls r1, 1
	movs r2, 0x32
	muls r0, r2
	adds r1, r0
	adds r1, r3
	movs r3, 0
	ldrsh r0, [r1, r3]
	cmp r0, 0
	beq _0804431A
	ldr r0, [r5, 0x70]
	movs r1, 0xA4
	lsls r1, 1
	adds r0, r1
	ldrb r0, [r0]
	cmp r0, 0
	beq _08044328
_0804431A:
	movs r0, 0
	b _0804444E
	.align 2, 0
_08044320: .4byte gUnknown_80F6860
_08044324: .4byte gUnknown_203B418
_08044328:
	bl sub_8083600
	adds r5, r0, 0
	cmp r5, 0
	beq _0804431A
	movs r0, 0
	bl sub_807520C
	lsls r0, 24
	cmp r0, 0
	bne _0804435C
	ldr r0, _08044388
	ldr r1, [r0]
	ldr r2, _0804438C
	adds r0, r1, r2
	ldrb r0, [r0]
	cmp r0, 0
	bne _08044356
	ldr r3, _08044390
	adds r0, r1, r3
	ldrb r0, [r0]
	cmp r0, 0
	beq _0804435C
_08044356:
	movs r0, 0xC
	bl sub_803E46C
_0804435C:
	ldr r0, [r5, 0x70]
	adds r0, 0xF8
	movs r1, 0
	strb r1, [r0]
	bl sub_8044B28
	lsls r0, 24
	lsrs r2, r0, 24
	cmp r2, 0
	bne _0804431A
	ldr r0, _08044388
	ldr r1, [r0]
	adds r0, r1, 0
	adds r0, 0xB8
	str r5, [r0]
	adds r1, 0xBC
	str r2, [r1]
	cmp r7, 0
	beq _08044394
	movs r7, 0
	b _0804439A
	.align 2, 0
_08044388: .4byte gUnknown_203B418
_0804438C: .4byte 0x0000066c
_08044390: .4byte 0x00000673
_08044394:
	adds r0, r5, 0
	bl sub_8074B54
_0804439A:
	bl sub_8044B28
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0
	bne _0804431A
	adds r0, r5, 0
	bl sub_8071DA4
	ldr r6, _08044434
	ldr r1, [r6]
	movs r0, 0x1
	strb r0, [r1, 0xF]
	bl sub_805D8C8
	ldr r0, [r6]
	strb r4, [r0, 0xF]
	bl sub_8044B28
	lsls r0, 24
	cmp r0, 0
	bne _0804444C
	adds r0, r5, 0
	bl sub_8072CF4
	bl sub_8086AC0
	movs r0, 0
	bl sub_8043ED0
	bl sub_8044B28
	lsls r0, 24
	cmp r0, 0
	bne _0804444C
	ldr r2, [r5, 0x70]
	ldrh r1, [r2]
	movs r3, 0x80
	lsls r3, 8
	adds r0, r3, 0
	ands r0, r1
	cmp r0, 0
	beq _08044400
	subs r3, 0x1
	adds r0, r3, 0
	ands r0, r1
	movs r3, 0x80
	lsls r3, 7
	adds r1, r3, 0
	orrs r0, r1
	strh r0, [r2]
_08044400:
	bl sub_8044B28
	lsls r0, 24
	cmp r0, 0
	bne _0804444C
	bl sub_8044454
	bl sub_8044B28
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0
	bne _0804444C
	ldr r2, [r6]
	adds r0, r2, 0
	adds r0, 0xBC
	ldr r1, [r0]
	cmp r1, 0
	beq _08044438
	bl sub_805F02C
	ldr r0, [r6]
	adds r0, 0xBC
	str r4, [r0]
	movs r7, 0x1
	b _08044328
	.align 2, 0
_08044434: .4byte gUnknown_203B418
_08044438:
	ldr r0, [r5, 0x70]
	adds r0, 0xF8
	ldrb r0, [r0]
	cmp r0, 0
	beq _0804444C
	movs r3, 0xCC
	lsls r3, 3
	adds r0, r2, r3
	strh r1, [r0]
	b _08044328
_0804444C:
	movs r0, 0x1
_0804444E:
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end xxx_dungeon_80442D0

	thumb_func_start sub_8044454
sub_8044454:
	push {r4-r6,lr}
	ldr r0, _080444E8
	ldr r1, [r0]
	ldrb r0, [r1, 0xE]
	cmp r0, 0
	beq _080444E2
	movs r0, 0
	strb r0, [r1, 0xE]
	movs r6, 0
_08044466:
	ldr r0, _080444E8
	ldr r0, [r0]
	lsls r1, r6, 2
	ldr r2, _080444EC
	adds r0, r2
	adds r0, r1
	ldr r4, [r0]
	adds r0, r4, 0
	bl sub_80450E0
	lsls r0, 24
	cmp r0, 0
	beq _080444DC
	ldr r5, [r4, 0x70]
	ldrh r0, [r5]
	movs r2, 0x80
	lsls r2, 8
	adds r1, r2, 0
	ands r0, r1
	cmp r0, 0
	beq _080444DC
	bl sub_8044B28
	lsls r0, 24
	cmp r0, 0
	bne _080444E2
	adds r0, r4, 0
	bl sub_8074B54
	adds r0, r4, 0
	bl sub_80450E0
	lsls r0, 24
	cmp r0, 0
	beq _080444DC
	adds r0, r4, 0
	bl sub_8071DA4
	adds r0, r4, 0
	movs r1, 0
	bl sub_8075990
	adds r0, r4, 0
	bl sub_8072CF4
	bl sub_8086AC0
	movs r0, 0
	bl sub_8043ED0
	ldrh r0, [r5]
	ldr r2, _080444F0
	adds r1, r2, 0
	ands r0, r1
	movs r2, 0x80
	lsls r2, 7
	adds r1, r2, 0
	orrs r0, r1
	strh r0, [r5]
_080444DC:
	adds r6, 0x1
	cmp r6, 0x13
	ble _08044466
_080444E2:
	pop {r4-r6}
	pop {r0}
	bx r0
	.align 2, 0
_080444E8: .4byte gUnknown_203B418
_080444EC: .4byte 0x000135cc
_080444F0: .4byte 0x00007fff
	thumb_func_end sub_8044454

	thumb_func_start sub_80444F4
sub_80444F4:
	push {r4-r6,lr}
	adds r6, r0, 0
	bl sub_8083600
	cmp r6, r0
	bne _08044566
	ldr r0, _0804456C
	ldr r1, [r0]
	ldrb r0, [r1, 0xE]
	cmp r0, 0
	beq _08044566
	movs r0, 0
	strb r0, [r1, 0xE]
	movs r5, 0
_08044510:
	ldr r0, _0804456C
	ldr r0, [r0]
	lsls r1, r5, 2
	ldr r2, _08044570
	adds r0, r2
	adds r0, r1
	ldr r4, [r0]
	adds r0, r4, 0
	bl sub_80450E0
	lsls r0, 24
	cmp r0, 0
	beq _08044560
	cmp r6, r4
	beq _08044560
	ldr r0, [r4, 0x70]
	ldrh r0, [r0]
	movs r2, 0x80
	lsls r2, 8
	adds r1, r2, 0
	ands r0, r1
	cmp r0, 0
	beq _08044560
	bl sub_8044B28
	lsls r0, 24
	cmp r0, 0
	bne _08044566
	adds r0, r4, 0
	movs r1, 0
	bl sub_8075990
	adds r0, r4, 0
	bl sub_8072CF4
	bl sub_8086AC0
	movs r0, 0
	bl sub_8043ED0
_08044560:
	adds r5, 0x1
	cmp r5, 0x13
	ble _08044510
_08044566:
	pop {r4-r6}
	pop {r0}
	bx r0
	.align 2, 0
_0804456C: .4byte gUnknown_203B418
_08044570: .4byte 0x000135cc
	thumb_func_end sub_80444F4

	thumb_func_start sub_8044574
sub_8044574:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x44
	bl sub_8083600
	mov r10, r0
	movs r7, 0
	mov r0, sp
	adds r0, 0x4
	str r0, [sp, 0x40]
	ldr r1, _08044634
	mov r9, r1
_08044592:
	mov r2, r9
	ldr r0, [r2]
	lsls r1, r7, 2
	ldr r3, _08044638
	adds r0, r3
	adds r0, r1
	ldr r5, [r0]
	adds r0, r5, 0
	bl sub_80450E0
	lsls r0, 24
	cmp r0, 0
	beq _080446A4
	ldr r6, [r5, 0x70]
	mov r8, r6
	ldrb r0, [r6, 0x7]
	cmp r0, 0
	bne _080446A4
	bl sub_8044B28
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0
	bne _080446AC
	mov r1, r9
	ldr r0, [r1]
	adds r0, 0xB8
	str r5, [r0]
	bl sub_8069E8C
	movs r2, 0xA2
	lsls r2, 1
	adds r0, r6, r2
	strb r4, [r0]
	adds r0, r5, 0
	bl sub_8070774
	mov r3, r9
	ldr r1, [r3]
	movs r2, 0xCC
	lsls r2, 3
	adds r1, r2
	movs r3, 0
	ldrsh r1, [r1, r3]
	lsls r1, 1
	movs r2, 0x32
	muls r0, r2
	adds r1, r0
	ldr r0, _0804463C
	adds r1, r0
	movs r2, 0
	ldrsh r0, [r1, r2]
	cmp r0, 0
	beq _080446A4
	movs r3, 0xA4
	lsls r3, 1
	adds r0, r6, r3
	ldrb r0, [r0]
	cmp r0, 0
	bne _080446A4
	ldrh r1, [r6]
	movs r2, 0x80
	lsls r2, 8
	adds r0, r2, 0
	ands r0, r1
	cmp r0, 0
	bne _080446A4
	movs r3, 0x80
	lsls r3, 7
	adds r0, r3, 0
	ands r0, r1
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0
	beq _08044644
	ldr r2, _08044640
	adds r0, r2, 0
	ands r0, r1
	strh r0, [r6]
	b _080446A4
	.align 2, 0
_08044634: .4byte gUnknown_203B418
_08044638: .4byte 0x0001357c
_0804463C: .4byte gUnknown_80F6860
_08044640: .4byte 0x0000bfff
_08044644:
	ldr r1, _08044668
	add r1, r8
	strb r0, [r1]
	adds r0, r5, 0
	bl sub_8074B54
	adds r0, r5, 0
	bl sub_80450E0
	lsls r0, 24
	cmp r0, 0
	beq _080446A4
	adds r0, r5, 0
	bl sub_8071DA4
	movs r4, 0
	b _0804466E
	.align 2, 0
_08044668: .4byte 0x00000145
_0804466C:
	adds r4, 0x1
_0804466E:
	cmp r4, 0x2
	bgt _080446A4
	adds r0, r5, 0
	movs r1, 0
	bl sub_8075990
	bl sub_8044B28
	lsls r0, 24
	cmp r0, 0
	bne _080446A4
	adds r0, r5, 0
	bl sub_8072CF4
	lsls r0, 24
	cmp r0, 0
	beq _080446A4
	bl sub_8086AC0
	movs r0, 0
	bl sub_8043ED0
	bl sub_8044B28
	lsls r0, 24
	cmp r0, 0
	beq _0804466C
_080446A4:
	adds r7, 0x1
	cmp r7, 0x3
	bgt _080446AC
	b _08044592
_080446AC:
	movs r0, 0
	mov r8, r0
_080446B0:
	adds r0, 0x1
	mov r9, r0
	add r2, sp, 0x8
	ldr r1, [sp, 0x40]
	mov r0, sp
	movs r7, 0x2
_080446BC:
	mov r3, r8
	str r3, [r0]
	str r2, [r1]
	adds r2, 0x8
	adds r1, 0x8
	adds r0, 0x8
	subs r7, 0x1
	cmp r7, 0
	bge _080446BC
	str r3, [sp, 0x18]
	str r3, [sp, 0x1C]
	movs r7, 0
_080446D4:
	ldr r0, _08044710
	ldr r0, [r0]
	lsls r1, r7, 2
	ldr r2, _08044714
	adds r0, r2
	adds r0, r1
	ldr r4, [r0]
	adds r0, r4, 0
	bl sub_80450E0
	lsls r0, 24
	cmp r0, 0
	beq _08044760
	ldr r1, [r4, 0x70]
	movs r3, 0xA2
	lsls r3, 1
	adds r2, r1, r3
	ldrb r0, [r2]
	cmp r0, 0
	beq _08044760
	ldrb r0, [r1, 0x7]
	cmp r0, 0
	beq _08044718
	adds r3, 0x1
	adds r0, r1, r3
	mov r1, r8
	strb r1, [r0]
	strb r1, [r2]
	b _08044760
	.align 2, 0
_08044710: .4byte gUnknown_203B418
_08044714: .4byte 0x0001357c
_08044718:
	mov r2, r10
	movs r3, 0x4
	ldrsh r1, [r2, r3]
	movs r2, 0x4
	ldrsh r0, [r4, r2]
	subs r2, r1, r0
	cmp r2, 0
	bge _0804472A
	negs r2, r2
_0804472A:
	mov r3, r10
	movs r0, 0x6
	ldrsh r1, [r3, r0]
	movs r3, 0x6
	ldrsh r0, [r4, r3]
	subs r1, r0
	cmp r1, 0
	bge _0804473C
	negs r1, r1
_0804473C:
	cmp r1, r2
	bge _08044742
	adds r1, r2, 0
_08044742:
	cmp r1, 0x2
	ble _08044748
	movs r1, 0x2
_08044748:
	add r3, sp, 0x20
	lsls r0, r7, 3
	adds r3, r0
	str r4, [r3]
	add r2, sp, 0x24
	adds r2, r0
	lsls r1, 3
	ldr r0, [sp, 0x40]
	adds r1, r0, r1
	ldr r0, [r1]
	str r0, [r2]
	str r3, [r1]
_08044760:
	adds r7, 0x1
	cmp r7, 0x3
	ble _080446D4
	mov r5, sp
	movs r6, 0
_0804476A:
	ldr r4, [r5]
	cmp r4, 0
	beq _080447A0
	ldr r1, [r4, 0x70]
	ldr r3, _08044814
	adds r2, r1, r3
	movs r0, 0x1
	strb r0, [r2]
	movs r2, 0xA2
	lsls r2, 1
	adds r0, r1, r2
	strb r6, [r0]
	adds r0, r4, 0
	movs r1, 0x1
	bl sub_8075990
	adds r0, r4, 0
	bl sub_8072CF4
	bl sub_8086AC0
	movs r0, 0
	bl sub_8043ED0
	adds r0, r4, 0
	bl sub_80450E0
_080447A0:
	ldr r5, [r5, 0x4]
	cmp r5, 0
	bne _0804476A
	mov r0, r9
	cmp r0, 0x2
	ble _080446B0
	bl sub_8044B28
	lsls r0, 24
	cmp r0, 0
	bne _08044802
	movs r7, 0
_080447B8:
	ldr r0, _08044818
	ldr r0, [r0]
	lsls r1, r7, 2
	ldr r3, _0804481C
	adds r0, r3
	adds r0, r1
	ldr r4, [r0]
	adds r0, r4, 0
	bl sub_80450E0
	lsls r0, 24
	cmp r0, 0
	beq _080447FC
	ldr r0, [r4, 0x70]
	movs r1, 0xA2
	lsls r1, 1
	adds r5, r0, r1
	ldrb r0, [r5]
	cmp r0, 0
	beq _080447FC
	adds r0, r4, 0
	bl sub_8074094
	adds r0, r4, 0
	bl sub_80450E0
	lsls r0, 24
	cmp r0, 0
	beq _080447FC
	adds r0, r4, 0
	bl sub_8071DA4
	movs r0, 0
	strb r0, [r5]
_080447FC:
	adds r7, 0x1
	cmp r7, 0x3
	ble _080447B8
_08044802:
	add sp, 0x44
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_08044814: .4byte 0x00000145
_08044818: .4byte gUnknown_203B418
_0804481C: .4byte 0x0001357c
	thumb_func_end sub_8044574

	thumb_func_start sub_8044820
sub_8044820:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	movs r7, 0
	ldr r0, _08044830
	mov r8, r0
	b _080448FC
	.align 2, 0
_08044830: .4byte gUnknown_80F6860
_08044834:
	ldr r4, [r5, 0x70]
	ldr r0, [r6]
	adds r0, 0xB8
	str r5, [r0]
	bl sub_8069E8C
	ldrh r2, [r4]
	movs r1, 0x80
	lsls r1, 8
	adds r0, r1, 0
	ands r0, r2
	cmp r0, 0
	bne _080448FA
	movs r1, 0x80
	lsls r1, 7
	adds r0, r1, 0
	ands r0, r2
	lsls r0, 16
	lsrs r1, r0, 16
	cmp r1, 0
	beq _0804486C
	ldr r1, _08044868
	adds r0, r1, 0
	ands r0, r2
	strh r0, [r4]
	b _080448FA
	.align 2, 0
_08044868: .4byte 0x0000bfff
_0804486C:
	movs r2, 0xA2
	lsls r2, 1
	adds r0, r4, r2
	strb r1, [r0]
	adds r0, r5, 0
	bl sub_8070774
	ldr r1, [r6]
	movs r2, 0xCC
	lsls r2, 3
	adds r1, r2
	movs r2, 0
	ldrsh r1, [r1, r2]
	lsls r1, 1
	movs r2, 0x32
	muls r0, r2
	adds r1, r0
	add r1, r8
	movs r2, 0
	ldrsh r0, [r1, r2]
	cmp r0, 0
	beq _080448FA
	movs r1, 0xA4
	lsls r1, 1
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, 0
	bne _080448FA
	ldrh r1, [r4]
	ldr r2, _08044984
	adds r0, r2, 0
	ands r1, r0
	movs r0, 0
	strh r1, [r4]
	ldr r2, _08044988
	adds r1, r4, r2
	strb r0, [r1]
	adds r0, r5, 0
	bl sub_8074B54
	adds r0, r5, 0
	bl sub_80450E0
	lsls r0, 24
	cmp r0, 0
	beq _080448FA
	adds r0, r5, 0
	bl sub_8071DA4
	adds r0, r5, 0
	movs r1, 0
	bl sub_8075990
	bl sub_8044B28
	lsls r0, 24
	cmp r0, 0
	bne _08044924
	adds r0, r5, 0
	bl sub_8072CF4
	bl sub_8086AC0
	movs r0, 0
	bl sub_8043ED0
	bl sub_8044B28
	lsls r0, 24
	cmp r0, 0
	bne _08044924
_080448FA:
	adds r7, 0x1
_080448FC:
	cmp r7, 0xF
	bgt _08044924
	ldr r6, _0804498C
	ldr r0, [r6]
	lsls r1, r7, 2
	ldr r2, _08044990
	adds r0, r2
	adds r0, r1
	ldr r5, [r0]
	adds r0, r5, 0
	bl sub_80450E0
	lsls r0, 24
	cmp r0, 0
	beq _080448FA
	bl sub_8044B28
	lsls r0, 24
	cmp r0, 0
	beq _08044834
_08044924:
	bl sub_8044B28
	lsls r0, 24
	cmp r0, 0
	bne _0804497A
	movs r7, 0
_08044930:
	ldr r0, _0804498C
	ldr r0, [r0]
	lsls r1, r7, 2
	ldr r2, _08044990
	adds r0, r2
	adds r0, r1
	ldr r4, [r0]
	adds r0, r4, 0
	bl sub_80450E0
	lsls r0, 24
	cmp r0, 0
	beq _08044974
	ldr r0, [r4, 0x70]
	movs r1, 0xA2
	lsls r1, 1
	adds r5, r0, r1
	ldrb r0, [r5]
	cmp r0, 0
	beq _08044974
	adds r0, r4, 0
	bl sub_8074094
	adds r0, r4, 0
	bl sub_80450E0
	lsls r0, 24
	cmp r0, 0
	beq _08044974
	adds r0, r4, 0
	bl sub_8071DA4
	movs r0, 0
	strb r0, [r5]
_08044974:
	adds r7, 0x1
	cmp r7, 0xF
	ble _08044930
_0804497A:
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_08044984: .4byte 0x00003fff
_08044988: .4byte 0x00000145
_0804498C: .4byte gUnknown_203B418
_08044990: .4byte 0x0001358c
	thumb_func_end sub_8044820

	thumb_func_start sub_8044994
sub_8044994:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	ldr r1, _08044A94
	ldr r4, _08044A98
	ldr r0, [r4]
	movs r2, 0xCC
	lsls r2, 3
	adds r0, r2
	movs r3, 0
	ldrsh r0, [r0, r3]
	lsls r0, 1
	adds r1, 0x32
	adds r0, r1
	movs r1, 0
	ldrsh r0, [r0, r1]
	cmp r0, 0
	beq _08044A8A
	bl sub_8071B48
	ldr r0, [r4]
	ldr r2, _08044A9C
	adds r0, r2
	movs r2, 0
	strb r2, [r0]
	ldr r0, [r4]
	ldr r3, _08044AA0
	adds r0, r3
	strb r2, [r0]
	ldr r0, [r4]
	ldr r1, _08044AA4
	adds r0, r1
	strb r2, [r0]
	ldr r0, [r4]
	adds r3, 0x2
	adds r0, r3
	strb r2, [r0]
	ldr r0, [r4]
	ldr r3, _08044AA8
	adds r1, r0, r3
	str r2, [r1]
	ldr r1, _08044AAC
	adds r0, r1
	movs r1, 0x2
	str r1, [r0]
	mov r8, r2
	adds r7, r4, 0
_080449F2:
	ldr r0, [r7]
	mov r2, r8
	lsls r1, r2, 2
	ldr r3, _08044AB0
	adds r0, r3
	adds r0, r1
	ldr r5, [r0]
	adds r0, r5, 0
	bl sub_80450E0
	lsls r0, 24
	cmp r0, 0
	beq _08044A7A
	ldr r0, [r5, 0x70]
	adds r4, r0, 0
	movs r0, 0xA4
	lsls r0, 1
	adds r1, r4, r0
	movs r0, 0
	strb r0, [r1]
	ldrb r0, [r4, 0x6]
	movs r6, 0x1
	cmp r0, 0
	beq _08044A24
	movs r6, 0
_08044A24:
	adds r0, r5, 0
	movs r1, 0x32
	bl sub_8071824
	lsls r0, 24
	cmp r0, 0
	beq _08044A46
	ldr r1, [r7]
	ldr r2, _08044AA8
	adds r0, r1, r2
	str r5, [r0]
	ldr r3, _08044AAC
	adds r1, r3
	adds r0, r4, 0
	adds r0, 0x98
	ldr r0, [r0]
	str r0, [r1]
_08044A46:
	adds r0, r5, 0
	movs r1, 0x3F
	bl sub_8071824
	lsls r0, 24
	cmp r0, 0
	beq _08044A60
	ldr r0, [r7]
	ldr r1, _08044AA4
	adds r0, r1
	adds r0, r6
	movs r1, 0x1
	strb r1, [r0]
_08044A60:
	adds r0, r5, 0
	movs r1, 0x38
	bl sub_8071824
	lsls r0, 24
	cmp r0, 0
	beq _08044A7A
	ldr r0, [r7]
	ldr r2, _08044A9C
	adds r0, r2
	adds r0, r6
	movs r1, 0x1
	strb r1, [r0]
_08044A7A:
	movs r3, 0x1
	add r8, r3
	mov r0, r8
	cmp r0, 0x13
	ble _080449F2
	movs r0, 0
	bl sub_8043ED0
_08044A8A:
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_08044A94: .4byte gUnknown_80F6860
_08044A98: .4byte gUnknown_203B418
_08044A9C: .4byte 0x000037f8
_08044AA0: .4byte 0x000037f9
_08044AA4: .4byte 0x000037fa
_08044AA8: .4byte 0x00017b2c
_08044AAC: .4byte 0x00017b38
_08044AB0: .4byte 0x000135cc
	thumb_func_end sub_8044994

	thumb_func_start sub_8044AB4
sub_8044AB4:
	push {r4,lr}
	ldr r1, _08044ADC
	ldr r0, _08044AE0
	ldr r0, [r0]
	movs r2, 0xCC
	lsls r2, 3
	adds r0, r2
	movs r2, 0
	ldrsh r0, [r0, r2]
	adds r0, 0x1
	lsls r0, 1
	adds r1, 0x32
	adds r0, r1
	movs r1, 0
	ldrsh r0, [r0, r1]
	cmp r0, 0
	beq _08044B1A
	movs r4, 0
	b _08044AE6
	.align 2, 0
_08044ADC: .4byte gUnknown_80F6860
_08044AE0: .4byte gUnknown_203B418
_08044AE4:
	adds r4, 0x1
_08044AE6:
	cmp r4, 0x13
	bgt _08044B08
	ldr r0, _08044B20
	ldr r0, [r0]
	lsls r1, r4, 2
	ldr r2, _08044B24
	adds r0, r2
	adds r0, r1
	ldr r0, [r0]
	bl sub_80450E0
	lsls r0, 24
	cmp r0, 0
	beq _08044AE4
	movs r0, 0
	bl sub_807520C
_08044B08:
	movs r0, 0x1
	movs r1, 0
	bl sub_807EAA0
	bl sub_8086AC0
	movs r0, 0
	bl sub_8043ED0
_08044B1A:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08044B20: .4byte gUnknown_203B418
_08044B24: .4byte 0x000135cc
	thumb_func_end sub_8044AB4

	thumb_func_start sub_8044B28
sub_8044B28:
	push {r4,lr}
	ldr r4, _08044B48
	ldr r0, [r4]
	ldrb r0, [r0, 0x4]
	cmp r0, 0
	bne _08044B76
	bl sub_8083600
	cmp r0, 0
	bne _08044B50
	ldr r0, [r4]
	ldr r1, _08044B4C
	adds r0, r1
	movs r1, 0x1
	strb r1, [r0]
	b _08044B76
	.align 2, 0
_08044B48: .4byte gUnknown_203B418
_08044B4C: .4byte 0x00000654
_08044B50:
	ldr r0, [r4]
	ldrb r2, [r0, 0x2]
	cmp r2, 0x1
	bne _08044B68
	ldr r2, _08044B64
	adds r1, r0, r2
	movs r0, 0x2
	strb r0, [r1]
	b _08044B76
	.align 2, 0
_08044B64: .4byte 0x00000654
_08044B68:
	cmp r2, 0x2
	beq _08044B70
	movs r0, 0
	b _08044B78
_08044B70:
	ldr r1, _08044B80
	adds r0, r1
	strb r2, [r0]
_08044B76:
	movs r0, 0x1
_08044B78:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_08044B80: .4byte 0x00000654
	thumb_func_end sub_8044B28

	thumb_func_start sub_8044B84
sub_8044B84:
	push {lr}
	ldr r0, _08044B9C
	ldr r0, [r0]
	ldrb r0, [r0, 0x10]
	cmp r0, 0
	bne _08044BA0
	bl sub_8044B28
	lsls r0, 24
	lsrs r0, 24
	b _08044BA2
	.align 2, 0
_08044B9C: .4byte gUnknown_203B418
_08044BA0:
	movs r0, 0x1
_08044BA2:
	pop {r1}
	bx r1
	thumb_func_end sub_8044B84

	thumb_func_start sub_8044BA8
sub_8044BA8:
	push {r4,r5,lr}
	lsls r0, 16
	lsrs r4, r0, 16
	lsls r1, 24
	lsrs r5, r1, 24
	cmp r4, 0x26
	bne _08044BCC
	bl sub_8043D10
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x2
	bne _08044BCC
	ldr r0, _08044BC8
	b _08044C02
	.align 2, 0
_08044BC8: .4byte gUnknown_80F91EC
_08044BCC:
	ldr r1, _08044BEC
	lsls r0, r4, 3
	adds r4, r0, r1
	ldr r0, [r4]
	ldr r1, _08044BF0
	bl strcmp
	cmp r0, 0
	beq _08044BE0
	movs r0, 0x1
_08044BE0:
	lsls r0, 24
	cmp r0, 0
	beq _08044BF4
	ldr r0, [r4]
	b _08044C04
	.align 2, 0
_08044BEC: .4byte gUnknown_80F7C50
_08044BF0: .4byte gUnknown_80F697C
_08044BF4:
	ldr r4, _08044C0C
	adds r0, r5, 0
	bl sub_8090D6C
	lsls r0, 3
	adds r4, 0x4
	adds r0, r4
_08044C02:
	ldr r0, [r0]
_08044C04:
	pop {r4,r5}
	pop {r1}
	bx r1
	.align 2, 0
_08044C0C: .4byte gActions
	thumb_func_end sub_8044BA8

	thumb_func_start sub_8044C10
sub_8044C10:
	push {r4,lr}
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	bl sub_8083654
	adds r2, r0, 0
	adds r1, r2, 0
	adds r1, 0x44
	movs r3, 0
	movs r0, 0
	strh r0, [r1]
	cmp r4, 0
	beq _08044C44
	adds r0, r2, 0
	adds r0, 0x48
	strb r3, [r0]
	adds r0, 0x8
	strb r3, [r0]
	adds r1, 0x14
	ldr r0, _08044C4C
	strh r0, [r1]
	adds r1, 0x2
	movs r0, 0x1
	negs r0, r0
	strh r0, [r1]
_08044C44:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08044C4C: .4byte 0x0000ffff
	thumb_func_end sub_8044C10

	thumb_func_start sub_8044C50
sub_8044C50:
	push {r4,lr}
	adds r4, r0, 0
	lsls r4, 16
	lsrs r4, 16
	bl sub_8083654
	adds r2, r0, 0
	adds r0, 0x44
	movs r1, 0
	strh r4, [r0]
	adds r0, 0x4
	strb r1, [r0]
	adds r0, 0x8
	strb r1, [r0]
	adds r1, r2, 0
	adds r1, 0x58
	ldr r0, _08044C84
	strh r0, [r1]
	adds r1, 0x2
	movs r0, 0x1
	negs r0, r0
	strh r0, [r1]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08044C84: .4byte 0x0000ffff
	thumb_func_end sub_8044C50

	thumb_func_start sub_8044C88
sub_8044C88:
	movs r2, 0
	movs r1, 0
	strh r1, [r0]
	strb r2, [r0, 0x4]
	strb r2, [r0, 0xC]
	bx lr
	thumb_func_end sub_8044C88

	thumb_func_start sub_8044C94
sub_8044C94:
	movs r2, 0
	strh r1, [r0]
	strb r2, [r0, 0x4]
	strb r2, [r0, 0xC]
	bx lr
	thumb_func_end sub_8044C94

	thumb_func_start sub_8044CA0
sub_8044CA0:
	push {r4,lr}
	adds r4, r0, 0
	lsls r0, r1, 16
	asrs r0, 16
	bl GetIsMoving
	lsls r0, 24
	cmp r0, 0
	beq _08044CB6
	movs r0, 0x2
	b _08044CB8
_08044CB6:
	movs r0, 0x1
_08044CB8:
	strh r0, [r4]
	movs r0, 0
	strb r0, [r4, 0x4]
	strb r0, [r4, 0xC]
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_8044CA0

	thumb_func_start sub_8044CC8
sub_8044CC8:
	push {lr}
	adds r3, r0, 0
	adds r2, r1, 0
	ldrb r1, [r2]
	subs r0, r1, 0x1
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x13
	bhi _08044CEC
	ldr r0, _08044CE8
	ldrb r1, [r2]
	lsls r1, 2
	subs r1, 0x4
	ldr r0, [r0]
	adds r0, r1
	b _08044D34
	.align 2, 0
_08044CE8: .4byte gUnknown_203B460
_08044CEC:
	adds r0, r1, 0
	cmp r0, 0x80
	bne _08044D06
	movs r1, 0x4
	ldrsh r0, [r2, r1]
	movs r3, 0x6
	ldrsh r1, [r2, r3]
	bl sub_804954C
	ldr r0, [r0, 0x14]
	bl sub_8045108
	b _08044D34
_08044D06:
	cmp r0, 0x81
	bne _08044D0E
	ldr r0, [r3, 0x70]
	b _08044D32
_08044D0E:
	adds r0, r1, 0
	adds r0, 0x70
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x3
	bls _08044D1E
	movs r0, 0
	b _08044D34
_08044D1E:
	ldr r0, _08044D38
	ldr r1, [r0]
	ldrb r0, [r2]
	subs r0, 0x90
	lsls r0, 2
	ldr r2, _08044D3C
	adds r1, r2
	adds r1, r0
	ldr r0, [r1]
	ldr r0, [r0, 0x70]
_08044D32:
	adds r0, 0x60
_08044D34:
	pop {r1}
	bx r1
	.align 2, 0
_08044D38: .4byte gUnknown_203B418
_08044D3C: .4byte 0x0001357c
	thumb_func_end sub_8044CC8

	thumb_func_start sub_8044D40
sub_8044D40:
	push {lr}
	lsls r1, 3
	adds r1, 0x4
	adds r2, r0, r1
	ldrb r1, [r2]
	subs r0, r1, 0x1
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x13
	bhi _08044D74
	ldr r1, _08044D70
	ldrb r0, [r2]
	lsls r0, 2
	subs r0, 0x4
	ldr r1, [r1]
	adds r1, r0
	movs r0, 0
	strb r0, [r1, 0x2]
	strb r0, [r1, 0x1]
	strb r0, [r1]
	bl sub_80910B4
	b _08044D88
	.align 2, 0
_08044D70: .4byte gUnknown_203B460
_08044D74:
	lsls r0, r1, 24
	lsrs r0, 24
	cmp r0, 0x80
	beq _08044D80
	movs r0, 0
	b _08044D8A
_08044D80:
	adds r0, r2, 0x4
	movs r1, 0x1
	bl sub_80461C8
_08044D88:
	movs r0, 0x1
_08044D8A:
	pop {r1}
	bx r1
	thumb_func_end sub_8044D40

	thumb_func_start sub_8044D90
sub_8044D90:
	push {lr}
	ldr r3, [r0, 0x70]
	lsls r1, 3
	adds r1, 0x48
	adds r3, r1
	adds r1, r3, 0
	bl sub_8044CC8
	pop {r1}
	bx r1
	thumb_func_end sub_8044D90

	thumb_func_start sub_8044DA4
sub_8044DA4:
	ldr r0, [r0, 0x70]
	ldr r2, _08044DC0
	ldr r2, [r2]
	lsls r1, 3
	adds r0, r1
	adds r0, 0x48
	ldrb r0, [r0]
	lsls r0, 2
	ldr r1, _08044DC4
	adds r2, r1
	adds r2, r0
	ldr r0, [r2]
	bx lr
	.align 2, 0
_08044DC0: .4byte gUnknown_203B418
_08044DC4: .4byte 0x0001357c
	thumb_func_end sub_8044DA4

	thumb_func_start sub_8044DC8
sub_8044DC8:
	push {r4,lr}
	adds r1, r0, 0
	ldrb r0, [r1, 0x2]
	cmp r0, 0xE9
	beq _08044DE8
	ldr r4, _08044DE4
	bl sub_8090BD0
	lsls r0, 24
	lsrs r0, 23
	adds r0, r4
	ldrh r0, [r0]
	b _08044DEA
	.align 2, 0
_08044DE4: .4byte gUnknown_80F6964
_08044DE8:
	movs r0, 0x35
_08044DEA:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_8044DC8

	thumb_func_start sub_8044DF0
sub_8044DF0:
	push {r4,lr}
	ldr r4, [r0, 0x70]
	bl sub_8044D90
	adds r1, r0, 0
	adds r0, r4, 0
	adds r0, 0x48
	ldrb r0, [r0]
	cmp r0, 0x80
	bne _08044E10
	adds r0, r4, 0
	adds r0, 0x4C
	movs r1, 0x1
	bl sub_80461C8
	b _08044E1C
_08044E10:
	movs r0, 0
	strb r0, [r1, 0x2]
	strb r0, [r1, 0x1]
	strb r0, [r1]
	bl sub_80910B4
_08044E1C:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_8044DF0

	thumb_func_start sub_8044E24
sub_8044E24:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0x4
	adds r4, r0, 0
	adds r6, r1, 0
	adds r7, r2, 0
	bl sub_8044D90
	adds r5, r0, 0
	ldr r0, [r4, 0x70]
	mov r8, r0
	ldrb r0, [r5, 0x2]
	bl sub_80915A0
	lsls r0, 24
	cmp r0, 0
	bne _08044EBA
	ldrb r0, [r5, 0x2]
	bl sub_8090BD0
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x5
	bne _08044EB0
	lsls r1, r6, 3
	mov r2, r8
	adds r0, r2, r1
	adds r0, 0x48
	ldrb r0, [r0]
	cmp r0, 0x80
	bne _08044EA4
	ldr r0, [r5]
	str r0, [sp]
	adds r4, r1, r2
	adds r4, 0x4C
	adds r0, r4, 0
	movs r1, 0x1
	bl sub_80461C8
	ldrb r1, [r5, 0x2]
	subs r1, 0x7D
	lsls r1, 24
	lsrs r1, 16
	ldr r2, _08044E9C
	ldr r0, [sp]
	ands r0, r2
	orrs r0, r1
	ldr r1, _08044EA0
	ands r0, r1
	movs r1, 0xF8
	lsls r1, 15
	orrs r0, r1
	str r0, [sp]
	adds r0, r4, 0
	mov r1, sp
	movs r2, 0x1
	bl sub_80460F8
	b _08044EBA
	.align 2, 0
_08044E9C: .4byte 0xffff00ff
_08044EA0: .4byte 0xff00ffff
_08044EA4:
	ldrb r0, [r5, 0x2]
	subs r0, 0x7D
	strb r0, [r5, 0x1]
	movs r0, 0x7C
	strb r0, [r5, 0x2]
	b _08044EBA
_08044EB0:
	adds r0, r4, 0
	adds r1, r6, 0
	adds r2, r7, 0
	bl sub_8044DF0
_08044EBA:
	add sp, 0x4
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_8044E24

	thumb_func_start sub_8044EC8
sub_8044EC8:
	push {r4,r5,lr}
	adds r5, r0, 0
	ldr r1, _08044EE8
	lsls r0, r5, 2
	adds r0, r1
	ldrh r4, [r0]
	cmp r4, 0x26
	bne _08044EF0
	bl sub_8043D10
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x2
	bne _08044EF0
	ldr r0, _08044EEC
	b _08044F2C
	.align 2, 0
_08044EE8: .4byte gUnknown_202EE44
_08044EEC: .4byte gUnknown_80F91EC
_08044EF0:
	ldr r1, _08044F10
	lsls r0, r4, 3
	adds r4, r0, r1
	ldr r0, [r4]
	ldr r1, _08044F14
	bl strcmp
	cmp r0, 0
	beq _08044F04
	movs r0, 0x1
_08044F04:
	lsls r0, 24
	cmp r0, 0
	beq _08044F18
	ldr r0, [r4]
	b _08044F2E
	.align 2, 0
_08044F10: .4byte gUnknown_80F7C50
_08044F14: .4byte gUnknown_80F697C
_08044F18:
	ldr r4, _08044F34
	ldr r1, _08044F38
	lsls r0, r5, 2
	adds r0, r1
	ldrb r0, [r0, 0x2]
	bl sub_8090D6C
	lsls r0, 3
	adds r4, 0x4
	adds r0, r4
_08044F2C:
	ldr r0, [r0]
_08044F2E:
	pop {r4,r5}
	pop {r1}
	bx r1
	.align 2, 0
_08044F34: .4byte gActions
_08044F38: .4byte gUnknown_202EE44
	thumb_func_end sub_8044EC8

	thumb_func_start sub_8044F3C
sub_8044F3C:
	push {lr}
	adds r1, r0, 0
	cmp r1, 0
	blt _08044F54
	ldr r0, _08044F50
	lsls r1, 2
	adds r1, r0
	ldrb r0, [r1, 0x3]
	b _08044F56
	.align 2, 0
_08044F50: .4byte gUnknown_202EE44
_08044F54:
	movs r0, 0
_08044F56:
	pop {r1}
	bx r1
	thumb_func_end sub_8044F3C

	thumb_func_start sub_8044F5C
sub_8044F5C:
	push {r4-r7,lr}
	lsls r0, 16
	lsrs r4, r0, 16
	lsls r1, 24
	lsrs r7, r1, 24
	ldr r0, _08044FAC
	ldr r2, [r0]
	adds r6, r0, 0
	cmp r2, 0x9
	bgt _08044FA4
	movs r3, 0
	ldr r5, _08044FB0
	cmp r3, r2
	bge _08044F8A
	adds r1, r2, 0
	adds r2, r5, 0
_08044F7C:
	ldrh r0, [r2]
	cmp r0, r4
	beq _08044FA4
	adds r2, 0x4
	adds r3, 0x1
	cmp r3, r1
	blt _08044F7C
_08044F8A:
	ldr r0, [r6]
	lsls r0, 2
	adds r0, r5
	strh r4, [r0]
	strb r7, [r0, 0x2]
	ldr r0, [r6]
	lsls r0, 2
	adds r0, r5
	movs r1, 0x1
	strb r1, [r0, 0x3]
	ldr r0, [r6]
	adds r0, 0x1
	str r0, [r6]
_08044FA4:
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_08044FAC: .4byte gUnknown_202EE6C
_08044FB0: .4byte gUnknown_202EE44
	thumb_func_end sub_8044F5C

	thumb_func_start sub_8044FB4
sub_8044FB4:
	push {r4,lr}
	lsls r0, 16
	lsrs r4, r0, 16
	movs r1, 0
	ldr r0, _08044FD4
	ldr r0, [r0]
	cmp r1, r0
	bge _08044FE4
	adds r3, r0, 0
	ldr r2, _08044FD8
_08044FC8:
	ldrh r0, [r2]
	cmp r0, r4
	bne _08044FDC
	adds r0, r1, 0
	b _08044FE8
	.align 2, 0
_08044FD4: .4byte gUnknown_202EE6C
_08044FD8: .4byte gUnknown_202EE44
_08044FDC:
	adds r2, 0x4
	adds r1, 0x1
	cmp r1, r3
	blt _08044FC8
_08044FE4:
	movs r0, 0x1
	negs r0, r0
_08044FE8:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_8044FB4

	thumb_func_start sub_8044FF0
sub_8044FF0:
	push {r4,r5,lr}
	lsls r0, 16
	lsrs r3, r0, 16
	movs r2, 0
	ldr r1, _08045010
	ldr r0, [r1]
	cmp r2, r0
	bge _08045022
	movs r5, 0
	adds r4, r1, 0
	ldr r1, _08045014
_08045006:
	ldrh r0, [r1]
	cmp r0, r3
	bne _08045018
	strb r5, [r1, 0x3]
	b _08045022
	.align 2, 0
_08045010: .4byte gUnknown_202EE6C
_08045014: .4byte gUnknown_202EE44
_08045018:
	adds r1, 0x4
	adds r2, 0x1
	ldr r0, [r4]
	cmp r2, r0
	blt _08045006
_08045022:
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_8044FF0

	thumb_func_start sub_8045028
sub_8045028:
	push {r4,lr}
	adds r2, r0, 0
	lsls r1, 24
	ldr r0, [r2, 0x70]
	adds r4, r0, 0
	adds r4, 0x44
	cmp r1, 0
	beq _08045044
	adds r0, r2, 0
	bl sub_8045888
	lsls r0, 24
	cmp r0, 0
	beq _0804505A
_08045044:
	ldrh r0, [r4]
	cmp r0, 0
	beq _0804505A
	cmp r0, 0x2
	beq _0804505A
	cmp r0, 0x1
	beq _0804505A
	cmp r0, 0x5
	beq _0804505A
	movs r0, 0
	b _0804505C
_0804505A:
	movs r0, 0x1
_0804505C:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_8045028

	thumb_func_start sub_8045064
sub_8045064:
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	movs r1, 0
	ldr r0, _080450D4
	mov r8, r0
	ldr r0, [r0]
	cmp r1, r0
	bge _080450C8
	mov r7, r8
	ldr r2, _080450D8
	mov r9, r2
	ldr r0, _080450DC
	mov r12, r0
_08045082:
	adds r4, r1, 0x1
	ldr r0, [r7]
	adds r5, r4, 0
	cmp r5, r0
	bge _080450BE
	lsls r0, r1, 2
	mov r1, r12
	adds r3, r0, r1
	mov r6, r9
	lsls r0, r5, 2
	adds r2, r0, r1
_08045098:
	ldrh r1, [r3]
	lsls r1, 3
	adds r1, r6
	ldrh r0, [r2]
	lsls r0, 3
	adds r0, r6
	ldr r1, [r1]
	ldr r0, [r0]
	cmp r1, r0
	ble _080450B4
	ldr r1, [r3]
	ldr r0, [r2]
	str r0, [r3]
	str r1, [r2]
_080450B4:
	adds r2, 0x4
	adds r4, 0x1
	ldr r0, [r7]
	cmp r4, r0
	blt _08045098
_080450BE:
	adds r1, r5, 0
	mov r2, r8
	ldr r0, [r2]
	cmp r1, r0
	blt _08045082
_080450C8:
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_080450D4: .4byte gUnknown_202EE6C
_080450D8: .4byte gUnknown_80F7C54
_080450DC: .4byte gUnknown_202EE44
	thumb_func_end sub_8045064

	thumb_func_start sub_80450E0
sub_80450E0:
	push {lr}
	cmp r0, 0
	bne _080450EA
	movs r0, 0
	b _080450F2
_080450EA:
	ldr r0, [r0]
	cmp r0, 0
	beq _080450F2
	movs r0, 0x1
_080450F2:
	pop {r1}
	bx r1
	thumb_func_end sub_80450E0

	thumb_func_start sub_80450F8
sub_80450F8:
	ldr r0, [r0]
	bx lr
	thumb_func_end sub_80450F8

	thumb_func_start sub_80450FC
sub_80450FC:
	adds r0, 0x25
	ldrb r0, [r0]
	bx lr
	thumb_func_end sub_80450FC

	thumb_func_start sub_8045104
sub_8045104:
	ldr r0, [r0, 0x70]
	bx lr
	thumb_func_end sub_8045104

	thumb_func_start sub_8045108
sub_8045108:
	ldr r0, [r0, 0x70]
	bx lr
	thumb_func_end sub_8045108

	thumb_func_start sub_804510C
sub_804510C:
	ldr r0, [r0, 0x70]
	bx lr
	thumb_func_end sub_804510C

	thumb_func_start sub_8045110
sub_8045110:
	ldr r0, [r0, 0x70]
	bx lr
	thumb_func_end sub_8045110

	thumb_func_start sub_8045114
sub_8045114:
	push {lr}
	movs r1, 0x4
	ldrsh r2, [r0, r1]
	movs r3, 0x6
	ldrsh r1, [r0, r3]
	adds r0, r2, 0
	bl sub_804954C
	pop {r1}
	bx r1
	thumb_func_end sub_8045114

	thumb_func_start sub_8045128
sub_8045128:
	push {lr}
	movs r1, 0x4
	ldrsh r2, [r0, r1]
	movs r3, 0x6
	ldrsh r1, [r0, r3]
	adds r0, r2, 0
	bl sub_8049590
	pop {r1}
	bx r1
	thumb_func_end sub_8045128

	thumb_func_start sub_804513C
sub_804513C:
	push {r4-r7,lr}
	movs r3, 0
	ldr r7, _080451FC
	ldr r6, _08045200
	ldr r4, _08045204
	movs r5, 0
_08045148:
	ldr r0, [r7]
	lsls r2, r3, 2
	adds r1, r0, r6
	adds r1, r2
	adds r0, r4
	str r0, [r1]
	str r5, [r0]
	adds r4, 0x74
	adds r3, 0x1
	cmp r3, 0x3
	ble _08045148
	ldr r1, _08045208
	movs r2, 0
	adds r0, r1, 0x5
_08045164:
	strb r2, [r0]
	subs r0, 0x1
	cmp r0, r1
	bge _08045164
	movs r3, 0
	ldr r7, _080451FC
	ldr r6, _0804520C
	ldr r4, _08045210
	movs r5, 0
_08045176:
	ldr r0, [r7]
	lsls r2, r3, 2
	adds r1, r0, r6
	adds r1, r2
	adds r0, r4
	str r0, [r1]
	str r5, [r0]
	adds r4, 0x74
	adds r3, 0x1
	cmp r3, 0xF
	ble _08045176
	ldr r1, _08045214
	movs r2, 0
	adds r0, r1, 0
	adds r0, 0xF
_08045194:
	strb r2, [r0]
	subs r0, 0x1
	cmp r0, r1
	bge _08045194
	movs r3, 0
	ldr r5, _080451FC
	ldr r4, _08045218
	movs r2, 0
_080451A4:
	ldr r0, [r5]
	lsls r1, r3, 2
	adds r0, r4
	adds r0, r1
	str r2, [r0]
	adds r3, 0x1
	cmp r3, 0x13
	ble _080451A4
	movs r3, 0
	ldr r7, _080451FC
	ldr r6, _0804521C
	ldr r4, _08045220
	movs r5, 0
_080451BE:
	ldr r0, [r7]
	lsls r2, r3, 2
	adds r1, r0, r6
	adds r1, r2
	adds r0, r4
	str r0, [r1]
	str r5, [r0]
	adds r4, 0x74
	adds r3, 0x1
	cmp r3, 0x3F
	ble _080451BE
	movs r3, 0
	ldr r7, _080451FC
	ldr r6, _08045224
	ldr r4, _08045228
	movs r5, 0
_080451DE:
	ldr r0, [r7]
	lsls r2, r3, 2
	adds r1, r0, r6
	adds r1, r2
	adds r0, r4
	str r0, [r1]
	str r5, [r0]
	adds r4, 0x74
	adds r3, 0x1
	cmp r3, 0x3F
	ble _080451DE
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_080451FC: .4byte gUnknown_203B418
_08045200: .4byte 0x0001357c
_08045204: .4byte 0x0001381c
_08045208: .4byte gUnknown_202EE70
_0804520C: .4byte 0x0001358c
_08045210: .4byte 0x000139ec
_08045214: .4byte gUnknown_202EE76
_08045218: .4byte 0x000135cc
_0804521C: .4byte 0x0001361c
_08045220: .4byte 0x0001412c
_08045224: .4byte 0x0001371c
_08045228: .4byte 0x00015e2c
	thumb_func_end sub_804513C

	thumb_func_start sub_804522C
sub_804522C:
	push {r4-r7,lr}
	sub sp, 0x4
	ldr r2, _08045274
	ldr r0, [r2]
	ldr r3, _08045278
	adds r1, r0, r3
	ldrb r7, [r1]
	ldr r1, _0804527C
	adds r0, r1
	ldrb r0, [r0]
	cmp r0, 0
	beq _080452AA
	movs r6, 0
	adds r7, r2, 0
_08045248:
	ldr r0, [r7]
	lsls r1, r6, 2
	ldr r2, _08045280
	adds r0, r2
	adds r0, r1
	ldr r5, [r0]
	adds r0, r5, 0
	bl sub_80450E0
	lsls r0, 24
	cmp r0, 0
	beq _080452A2
	ldr r0, [r7]
	ldr r3, _08045284
	adds r0, r3
	ldr r0, [r0]
	cmp r5, r0
	bne _08045288
	adds r0, r5, 0
	bl sub_806C51C
	b _080452A2
	.align 2, 0
_08045274: .4byte gUnknown_203B418
_08045278: .4byte 0x00018210
_0804527C: .4byte 0x0001820a
_08045280: .4byte 0x000135cc
_08045284: .4byte 0x000181f8
_08045288:
	ldr r4, [r5, 0x70]
	adds r0, r5, 0
	bl sub_804187C
	adds r2, r0, 0
	adds r0, r4, 0
	adds r0, 0x98
	ldr r0, [r0]
	movs r3, 0x4
	ldrsh r1, [r4, r3]
	movs r3, 0
	bl sub_800F75C
_080452A2:
	adds r6, 0x1
	cmp r6, 0x13
	ble _08045248
	b _0804533E
_080452AA:
	movs r6, 0
_080452AC:
	ldr r0, _08045348
	ldr r0, [r0]
	lsls r1, r6, 2
	ldr r2, _0804534C
	adds r0, r2
	adds r0, r1
	ldr r4, [r0]
	adds r0, r4, 0
	bl sub_80450E0
	lsls r0, 24
	cmp r0, 0
	beq _080452CC
	adds r0, r4, 0
	bl sub_806C51C
_080452CC:
	adds r6, 0x1
	cmp r6, 0x3
	ble _080452AC
	movs r6, 0
_080452D4:
	ldr r5, _08045348
	ldr r0, [r5]
	lsls r1, r6, 2
	ldr r3, _08045350
	adds r0, r3
	adds r0, r1
	ldr r4, [r0]
	adds r0, r4, 0
	bl sub_80450E0
	lsls r0, 24
	cmp r0, 0
	beq _080452F4
	adds r0, r4, 0
	bl sub_806C51C
_080452F4:
	adds r6, 0x1
	cmp r6, 0xF
	ble _080452D4
	movs r6, 0
	ldr r0, [r5]
	ldr r1, _08045354
	adds r0, r1
	movs r2, 0
	ldrsh r0, [r0, r2]
	cmp r6, r0
	bge _08045336
	adds r4, r5, 0
_0804530C:
	ldr r0, [r4]
	lsls r1, r6, 2
	ldr r3, _08045358
	adds r0, r3
	adds r0, r1
	ldr r0, [r0]
	movs r1, 0
	str r1, [sp]
	adds r1, r7, 0
	movs r2, 0x1
	movs r3, 0xFF
	bl sub_80462AC
	adds r6, 0x1
	ldr r0, [r4]
	ldr r1, _08045354
	adds r0, r1
	movs r2, 0
	ldrsh r0, [r0, r2]
	cmp r6, r0
	blt _0804530C
_08045336:
	cmp r7, 0
	beq _0804533E
	bl sub_807FA9C
_0804533E:
	add sp, 0x4
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_08045348: .4byte gUnknown_203B418
_0804534C: .4byte 0x0001357c
_08045350: .4byte 0x0001358c
_08045354: .4byte 0x00003904
_08045358: .4byte 0x0001361c
	thumb_func_end sub_804522C

	thumb_func_start sub_804535C
sub_804535C:
	push {lr}
	adds r2, r0, 0
	cmp r1, 0
	beq _0804536C
	ldr r0, [r1]
	str r0, [r2, 0xC]
	ldr r0, [r1, 0x4]
	b _0804538E
_0804536C:
	movs r0, 0x4
	ldrsh r1, [r2, r0]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 11
	movs r1, 0xC0
	lsls r1, 4
	adds r0, r1
	str r0, [r2, 0xC]
	movs r0, 0x6
	ldrsh r1, [r2, r0]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 11
	movs r1, 0x80
	lsls r1, 5
	adds r0, r1
_0804538E:
	str r0, [r2, 0x10]
	pop {r0}
	bx r0
	thumb_func_end sub_804535C

	thumb_func_start sub_8045394
sub_8045394:
	str r1, [r0, 0xC]
	str r2, [r0, 0x10]
	bx lr
	thumb_func_end sub_8045394

	thumb_func_start sub_804539C
sub_804539C:
	ldr r3, [r0, 0xC]
	adds r3, r1
	str r3, [r0, 0xC]
	ldr r1, [r0, 0x10]
	adds r1, r2
	str r1, [r0, 0x10]
	bx lr
	thumb_func_end sub_804539C

	thumb_func_start sub_80453AC
sub_80453AC:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	lsls r0, 16
	asrs r0, 16
	mov r8, r0
	movs r0, 0x1
	negs r0, r0
	mov r9, r0
	mov r0, r8
	bl GetPokemonSize
	lsls r0, 24
	lsrs r6, r0, 24
	movs r5, 0
	movs r0, 0x6
	subs r3, r0, r6
	ldr r4, _080453D8
	b _080453DE
	.align 2, 0
_080453D8: .4byte gUnknown_202EE70
_080453DC:
	adds r5, 0x1
_080453DE:
	cmp r5, r3
	bgt _08045400
	movs r2, 0
	cmp r2, r6
	bge _080453FA
	adds r1, r5, r4
	b _080453F4
_080453EC:
	adds r1, 0x1
	adds r2, 0x1
	cmp r2, r6
	bge _080453FA
_080453F4:
	ldrb r0, [r1]
	cmp r0, 0
	beq _080453EC
_080453FA:
	cmp r2, r6
	bne _080453DC
	mov r9, r5
_08045400:
	movs r0, 0x1
	negs r0, r0
	cmp r9, r0
	beq _080454FC
	movs r5, 0
	ldr r7, _080454DC
_0804540C:
	ldr r1, _080454E0
	ldr r0, [r1]
	lsls r1, r5, 2
	ldr r2, _080454E4
	adds r0, r2
	adds r0, r1
	ldr r4, [r0]
	adds r0, r4, 0
	bl sub_80450E0
	lsls r0, 24
	lsrs r0, 24
	mov r10, r0
	cmp r0, 0
	bne _080454F0
	movs r0, 0x1
	str r0, [r4]
	adds r0, r4, 0
	adds r0, 0x24
	strb r5, [r0]
	ldr r1, _080454E0
	ldr r0, [r1]
	adds r0, r7
	str r0, [r4, 0x70]
	mov r2, r8
	strh r2, [r0, 0x2]
	movs r0, 0
	mov r1, r8
	bl sub_8069F54
	ldr r1, [r4, 0x70]
	strh r0, [r1, 0x4]
	ldr r0, [r4, 0x70]
	movs r5, 0
	strb r5, [r0, 0x6]
	movs r0, 0
	mov r1, r8
	bl sub_8069F54
	lsls r0, 16
	asrs r0, 16
	bl sub_80687D0
	str r0, [r4, 0x64]
	mov r1, r9
	lsls r0, r1, 4
	adds r0, 0x40
	adds r1, r4, 0
	adds r1, 0x68
	strh r0, [r1]
	adds r1, 0x2
	movs r0, 0x7
	strb r0, [r1]
	adds r0, r4, 0
	adds r0, 0x6C
	movs r2, 0
	strb r2, [r0]
	adds r1, 0x1
	movs r0, 0xFF
	strb r0, [r1]
	adds r0, r4, 0
	adds r0, 0x6D
	movs r5, 0x1
	strb r5, [r0]
	adds r0, 0x2
	strb r5, [r0]
	mov r0, r10
	str r0, [r4, 0x1C]
	bl sub_8045ACC
	ldr r0, [r4, 0x70]
	ldr r1, _080454E8
	adds r0, r1
	mov r2, r9
	strb r2, [r0]
	ldr r0, [r4, 0x70]
	movs r5, 0xB4
	lsls r5, 1
	adds r0, r5
	strb r6, [r0]
	cmp r6, 0
	beq _080454C6
	ldr r3, _080454EC
	movs r2, 0x1
	adds r1, r6, 0
_080454B6:
	mov r5, r9
	adds r0, r5, r3
	strb r2, [r0]
	movs r0, 0x1
	add r9, r0
	subs r1, 0x1
	cmp r1, 0
	bne _080454B6
_080454C6:
	ldr r1, _080454E0
	ldr r0, [r1]
	movs r2, 0xCD
	lsls r2, 3
	adds r0, r2
	ldrh r2, [r0]
	adds r1, r2, 0x1
	strh r1, [r0]
	strh r2, [r4, 0x26]
	adds r0, r4, 0
	b _080454FE
	.align 2, 0
_080454DC: .4byte 0x0000069c
_080454E0: .4byte gUnknown_203B418
_080454E4: .4byte 0x0001357c
_080454E8: .4byte 0x00000167
_080454EC: .4byte gUnknown_202EE70
_080454F0:
	movs r0, 0x82
	lsls r0, 2
	adds r7, r0
	adds r5, 0x1
	cmp r5, 0x3
	ble _0804540C
_080454FC:
	movs r0, 0
_080454FE:
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_80453AC

	thumb_func_start sub_804550C
sub_804550C:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x8
	lsls r0, 16
	asrs r0, 16
	mov r8, r0
	movs r0, 0x1
	negs r0, r0
	mov r9, r0
	mov r0, r8
	bl GetPokemonSize
	lsls r0, 24
	lsrs r7, r0, 24
	movs r5, 0
	movs r0, 0x10
	subs r3, r0, r7
	ldr r4, _08045538
	b _0804553E
	.align 2, 0
_08045538: .4byte gUnknown_202EE76
_0804553C:
	adds r5, 0x1
_0804553E:
	cmp r5, r3
	bgt _08045560
	movs r2, 0
	cmp r2, r7
	bge _0804555A
	adds r1, r5, r4
	b _08045554
_0804554C:
	adds r1, 0x1
	adds r2, 0x1
	cmp r2, r7
	bge _0804555A
_08045554:
	ldrb r0, [r1]
	cmp r0, 0
	beq _0804554C
_0804555A:
	cmp r2, r7
	bne _0804553C
	mov r9, r5
_08045560:
	movs r0, 0x1
	negs r0, r0
	cmp r9, r0
	bne _0804556A
	b _08045670
_0804556A:
	movs r5, 0
	movs r1, 0x1
	mov r10, r1
	ldr r2, _08045650
	mov r3, r9
	lsls r0, r3, 4
	adds r0, 0xA0
	str r0, [sp]
_0804557A:
	ldr r1, _08045654
	ldr r0, [r1]
	lsls r1, r5, 2
	ldr r3, _08045658
	adds r0, r3
	adds r0, r1
	ldr r4, [r0]
	adds r0, r4, 0
	str r2, [sp, 0x4]
	bl sub_80450E0
	lsls r0, 24
	lsrs r6, r0, 24
	ldr r2, [sp, 0x4]
	cmp r6, 0
	bne _08045664
	mov r0, r10
	str r0, [r4]
	adds r0, r4, 0
	adds r0, 0x24
	strb r5, [r0]
	subs r0, 0x2
	strb r6, [r0]
	ldr r1, _08045654
	ldr r0, [r1]
	adds r0, r2
	str r0, [r4, 0x70]
	mov r2, r8
	strh r2, [r0, 0x2]
	movs r0, 0
	mov r1, r8
	bl sub_8069F54
	ldr r1, [r4, 0x70]
	strh r0, [r1, 0x4]
	ldr r0, [r4, 0x70]
	mov r3, r10
	strb r3, [r0, 0x6]
	movs r0, 0
	mov r1, r8
	bl sub_8069F54
	lsls r0, 16
	asrs r0, 16
	bl sub_80687D0
	str r0, [r4, 0x64]
	adds r0, r4, 0
	adds r0, 0x68
	mov r5, sp
	ldrh r5, [r5]
	strh r5, [r0]
	adds r1, r4, 0
	adds r1, 0x6A
	movs r0, 0x7
	strb r0, [r1]
	adds r0, r4, 0
	adds r0, 0x6C
	movs r1, 0
	strb r1, [r0]
	adds r1, r4, 0
	adds r1, 0x6B
	movs r0, 0xFF
	strb r0, [r1]
	adds r0, r4, 0
	adds r0, 0x6D
	mov r2, r10
	strb r2, [r0]
	adds r0, 0x2
	strb r2, [r0]
	str r6, [r4, 0x1C]
	ldr r0, [r4, 0x70]
	ldr r3, _0804565C
	adds r0, r3
	mov r5, r9
	strb r5, [r0]
	ldr r0, [r4, 0x70]
	movs r1, 0xB4
	lsls r1, 1
	adds r0, r1
	strb r7, [r0]
	cmp r7, 0
	beq _08045636
	ldr r3, _08045660
	movs r2, 0x1
	adds r1, r7, 0
_08045626:
	mov r5, r9
	adds r0, r5, r3
	strb r2, [r0]
	movs r0, 0x1
	add r9, r0
	subs r1, 0x1
	cmp r1, 0
	bne _08045626
_08045636:
	bl sub_8045ACC
	ldr r1, _08045654
	ldr r0, [r1]
	movs r2, 0xCD
	lsls r2, 3
	adds r0, r2
	ldrh r2, [r0]
	adds r1, r2, 0x1
	strh r1, [r0]
	strh r2, [r4, 0x26]
	adds r0, r4, 0
	b _08045672
	.align 2, 0
_08045650: .4byte 0x00000ebc
_08045654: .4byte gUnknown_203B418
_08045658: .4byte 0x0001358c
_0804565C: .4byte 0x00000167
_08045660: .4byte gUnknown_202EE76
_08045664:
	movs r3, 0x82
	lsls r3, 2
	adds r2, r3
	adds r5, 0x1
	cmp r5, 0xF
	ble _0804557A
_08045670:
	movs r0, 0
_08045672:
	add sp, 0x8
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_804550C

	thumb_func_start sub_8045684
sub_8045684:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	mov r10, r1
	lsls r0, 24
	lsrs r0, 24
	mov r8, r0
	lsls r2, 24
	lsrs r2, 24
	mov r9, r2
	movs r5, 0
	ldr r7, _080456E4
	ldr r6, _080456E8
_080456A2:
	ldr r0, [r7]
	lsls r1, r5, 2
	ldr r2, _080456EC
	adds r0, r2
	adds r0, r1
	ldr r4, [r0]
	adds r0, r4, 0
	bl sub_80450E0
	lsls r0, 24
	lsrs r1, r0, 24
	cmp r1, 0
	bne _080456F0
	movs r0, 0x2
	str r0, [r4]
	ldr r0, [r7]
	adds r0, r6
	str r0, [r4, 0x70]
	mov r2, r8
	strb r2, [r0]
	ldr r0, [r4, 0x70]
	mov r2, r9
	strb r2, [r0, 0x1]
	str r1, [r4, 0x1C]
	adds r0, r4, 0
	adds r0, 0x22
	strb r1, [r0]
	mov r2, r10
	ldr r0, [r2]
	str r0, [r4, 0x4]
	strh r1, [r4, 0x26]
	adds r0, r4, 0
	b _080456FA
	.align 2, 0
_080456E4: .4byte gUnknown_203B418
_080456E8: .4byte 0x00003908
_080456EC: .4byte 0x0001371c
_080456F0:
	adds r6, 0x4
	adds r5, 0x1
	cmp r5, 0x3F
	ble _080456A2
	movs r0, 0
_080456FA:
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_8045684

	thumb_func_start sub_8045708
sub_8045708:
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	mov r8, r0
	ldr r1, _08045744
	ldr r0, _08045748
	ldr r0, [r0]
	ldr r2, _0804574C
	adds r0, r2
	movs r3, 0
	ldrsh r0, [r0, r3]
	adds r0, r1
	ldrb r0, [r0]
	cmp r0, 0x1
	bne _0804579C
	mov r1, r8
	movs r2, 0
	ldrsh r0, [r1, r2]
	movs r3, 0x2
	ldrsh r1, [r1, r3]
	bl sub_8049590
	ldrh r1, [r0]
	movs r0, 0x3
	ands r0, r1
	cmp r0, 0x2
	bne _0804579C
	b _080457C4
	.align 2, 0
_08045744: .4byte gUnknown_810ACC0
_08045748: .4byte gUnknown_203B418
_0804574C: .4byte 0x00003a0e
_08045750:
	movs r0, 0x3
	str r0, [r4]
	ldr r0, _08045798
	adds r1, r6, r0
	mov r2, r9
	ldr r0, [r2]
	adds r0, r1
	str r0, [r4, 0x70]
	mov r3, r8
	ldr r0, [r3]
	str r0, [r4, 0x4]
	movs r1, 0
	ldrsh r0, [r3, r1]
	lsls r1, r0, 1
	adds r1, r0
	lsls r1, 3
	adds r1, 0x4
	lsls r1, 8
	movs r2, 0x2
	ldrsh r0, [r3, r2]
	lsls r2, r0, 1
	adds r2, r0
	lsls r2, 3
	adds r2, 0x4
	lsls r2, 8
	adds r0, r4, 0
	bl sub_8045394
	movs r0, 0
	strh r7, [r4, 0x26]
	adds r1, r4, 0
	adds r1, 0x22
	strb r0, [r1]
	str r7, [r4, 0x1C]
	adds r0, r4, 0
	b _080457C6
	.align 2, 0
_08045798: .4byte 0x00003804
_0804579C:
	movs r5, 0
	ldr r3, _080457D4
	mov r9, r3
_080457A2:
	mov r1, r9
	ldr r0, [r1]
	lsls r6, r5, 2
	ldr r2, _080457D8
	adds r0, r2
	adds r0, r6
	ldr r4, [r0]
	adds r0, r4, 0
	bl sub_80450E0
	lsls r0, 24
	lsrs r7, r0, 24
	cmp r7, 0
	beq _08045750
	adds r5, 0x1
	cmp r5, 0x3F
	ble _080457A2
_080457C4:
	movs r0, 0
_080457C6:
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r1}
	bx r1
	.align 2, 0
_080457D4: .4byte gUnknown_203B418
_080457D8: .4byte 0x0001361c
	thumb_func_end sub_8045708

	thumb_func_start sub_80457DC
sub_80457DC:
	push {r4-r6,lr}
	adds r4, r0, 0
	movs r0, 0x5
	str r0, [r4]
	movs r6, 0
	movs r5, 0
	strh r5, [r4, 0x4]
	strh r5, [r4, 0x6]
	adds r0, r4, 0
	movs r1, 0
	movs r2, 0
	bl sub_8045394
	strh r5, [r4, 0x26]
	adds r4, 0x22
	strb r6, [r4]
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end sub_80457DC

	thumb_func_start sub_8045804
sub_8045804:
	push {r4-r6,lr}
	adds r4, r0, 0
	bl sub_80450F8
	cmp r0, 0x1
	beq _0804581C
	cmp r0, 0x1
	bcc _08045880
	cmp r0, 0x5
	beq _08045880
_08045818:
	movs r0, 0x1
	b _08045882
_0804581C:
	adds r0, r4, 0
	adds r0, 0x20
	ldrb r0, [r0]
	cmp r0, 0
	beq _08045880
	ldr r0, _08045874
	ldr r1, [r0]
	ldr r0, _08045878
	adds r2, r1, r0
	ldr r5, [r2, 0x10]
	ldr r3, [r4, 0x70]
	ldrb r0, [r3, 0x6]
	cmp r0, 0
	beq _08045818
	ldr r6, _0804587C
	adds r0, r1, r6
	ldrb r0, [r0]
	cmp r0, 0
	bne _0804584C
	adds r0, r3, 0
	adds r0, 0xE4
	ldrb r0, [r0]
	cmp r0, 0x1
	beq _08045880
_0804584C:
	adds r0, r2, 0
	adds r0, 0x23
	ldrb r0, [r0]
	cmp r0, 0
	bne _08045818
	adds r0, r2, 0
	adds r0, 0x25
	ldrb r0, [r0]
	cmp r0, 0
	bne _08045818
	cmp r5, 0
	beq _08045880
	adds r1, r4, 0x4
	adds r0, r2, 0
	bl sub_8083294
	lsls r0, 24
	lsrs r0, 24
	b _08045882
	.align 2, 0
_08045874: .4byte gUnknown_203B418
_08045878: .4byte 0x000181e8
_0804587C: .4byte 0x0001820f
_08045880:
	movs r0, 0
_08045882:
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end sub_8045804

	thumb_func_start sub_8045888
sub_8045888:
	push {r4,r5,lr}
	adds r4, r0, 0
	adds r0, 0x20
	ldrb r0, [r0]
	cmp r0, 0
	beq _08045988
	ldr r1, [r4, 0xC]
	cmp r1, 0
	bge _0804589C
	adds r1, 0xFF
_0804589C:
	asrs r1, 8
	ldr r0, _080458F0
	ldr r2, [r0]
	ldr r3, _080458F4
	adds r0, r2, r3
	movs r5, 0
	ldrsh r0, [r0, r5]
	subs r3, r1, r0
	ldr r0, [r4, 0x10]
	cmp r0, 0
	bge _080458B4
	adds r0, 0xFF
_080458B4:
	asrs r0, 8
	ldr r5, _080458F8
	adds r1, r2, r5
	movs r5, 0
	ldrsh r1, [r1, r5]
	subs r1, r0, r1
	movs r0, 0x20
	negs r0, r0
	cmp r3, r0
	blt _08045988
	cmp r1, r0
	blt _08045988
	movs r0, 0x88
	lsls r0, 1
	cmp r3, r0
	bgt _08045988
	cmp r1, 0xC0
	bgt _08045988
	ldr r0, _080458FC
	adds r5, r2, r0
	adds r0, r4, 0
	bl sub_80450F8
	cmp r0, 0x5
	bhi _08045984
	lsls r0, 2
	ldr r1, _08045900
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080458F0: .4byte gUnknown_203B418
_080458F4: .4byte 0x000181f0
_080458F8: .4byte 0x000181f2
_080458FC: .4byte 0x000181e8
_08045900: .4byte _08045904
	.align 2, 0
_08045904:
	.4byte _08045988
	.4byte _08045934
	.4byte _08045964
	.4byte _0804591C
	.4byte _08045984
	.4byte _08045988
_0804591C:
	adds r0, r5, 0
	adds r0, 0x26
_08045920:
	ldrb r0, [r0]
	cmp r0, 0
	bne _08045984
	adds r0, r4, 0x4
	bl sub_803F428
	lsls r0, 24
_0804592E:
	cmp r0, 0
	bne _08045984
	b _08045988
_08045934:
	ldr r1, [r4, 0x70]
	ldrb r0, [r1, 0x6]
	cmp r0, 0
	beq _08045984
	ldr r0, _0804595C
	ldr r0, [r0]
	ldr r2, _08045960
	adds r0, r2
	ldrb r0, [r0]
	cmp r0, 0
	bne _08045954
	adds r0, r1, 0
	adds r0, 0xE4
	ldrb r0, [r0]
	cmp r0, 0x1
	beq _08045988
_08045954:
	adds r0, r5, 0
	adds r0, 0x25
	b _08045920
	.align 2, 0
_0804595C: .4byte gUnknown_203B418
_08045960: .4byte 0x0001820f
_08045964:
	ldr r0, _0804597C
	ldr r0, [r0]
	ldr r3, _08045980
	adds r0, r3
	ldrb r0, [r0]
	cmp r0, 0
	bne _08045984
	adds r0, r4, 0
	adds r0, 0x20
	ldrb r0, [r0]
	b _0804592E
	.align 2, 0
_0804597C: .4byte gUnknown_203B418
_08045980: .4byte 0x0001820f
_08045984:
	movs r0, 0x1
	b _0804598A
_08045988:
	movs r0, 0
_0804598A:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_8045888

	thumb_func_start sub_8045990
sub_8045990:
	push {r4,r5,lr}
	adds r5, r0, 0
	adds r4, r1, 0
	bl sub_80450E0
	lsls r0, 24
	cmp r0, 0
	beq _080459E8
	adds r0, r4, 0
	bl sub_80450E0
	lsls r0, 24
	cmp r0, 0
	beq _080459E8
	adds r0, r4, 0
	adds r0, 0x20
	ldrb r0, [r0]
	cmp r0, 0
	beq _080459E8
	ldr r0, [r4]
	cmp r0, 0x1
	bne _080459EC
	ldr r0, [r5]
	cmp r0, 0x1
	bne _080459DE
	adds r0, r5, 0
	bl sub_8071884
	lsls r0, 24
	cmp r0, 0
	bne _080459D8
	ldr r0, [r4, 0x70]
	adds r0, 0xE4
	ldrb r0, [r0]
	cmp r0, 0x1
	beq _080459E8
_080459D8:
	ldr r0, [r5, 0x70]
	adds r0, 0xE8
	b _080459E2
_080459DE:
	ldr r0, [r4, 0x70]
	adds r0, 0xE4
_080459E2:
	ldrb r0, [r0]
	cmp r0, 0x1
	bne _080459EC
_080459E8:
	movs r0, 0
	b _080459F8
_080459EC:
	adds r0, r5, 0x4
	adds r1, r4, 0x4
	bl sub_8083294
	lsls r0, 24
	lsrs r0, 24
_080459F8:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_8045990

	thumb_func_start sub_8045A00
sub_8045A00:
	push {r4,r5,lr}
	adds r5, r0, 0
	adds r4, r1, 0
	bl sub_80450E0
	lsls r0, 24
	cmp r0, 0
	beq _08045A58
	adds r0, r4, 0
	bl sub_80450E0
	lsls r0, 24
	cmp r0, 0
	beq _08045A58
	adds r0, r4, 0
	adds r0, 0x20
	ldrb r0, [r0]
	cmp r0, 0
	beq _08045A58
	ldr r0, [r4]
	cmp r0, 0x1
	bne _08045A5C
	ldr r0, [r5]
	cmp r0, 0x1
	bne _08045A4E
	adds r0, r5, 0
	bl sub_8071884
	lsls r0, 24
	cmp r0, 0
	bne _08045A48
	ldr r0, [r4, 0x70]
	adds r0, 0xE4
	ldrb r0, [r0]
	cmp r0, 0x1
	beq _08045A58
_08045A48:
	ldr r0, [r5, 0x70]
	adds r0, 0xE8
	b _08045A52
_08045A4E:
	ldr r0, [r4, 0x70]
	adds r0, 0xE4
_08045A52:
	ldrb r0, [r0]
	cmp r0, 0x1
	bne _08045A5C
_08045A58:
	movs r0, 0
	b _08045A68
_08045A5C:
	adds r0, r5, 0x4
	adds r1, r4, 0x4
	bl sub_808333C
	lsls r0, 24
	lsrs r0, 24
_08045A68:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_8045A00

	thumb_func_start sub_8045A70
sub_8045A70:
	push {r4,r5,lr}
	adds r5, r0, 0
	adds r4, r1, 0
	bl sub_80450E0
	lsls r0, 24
	cmp r0, 0
	beq _08045AA4
	adds r0, r4, 0
	bl sub_80450E0
	lsls r0, 24
	cmp r0, 0
	beq _08045AA4
	adds r0, r4, 0
	adds r0, 0x20
	ldrb r0, [r0]
	cmp r0, 0
	beq _08045AA4
	adds r0, r5, 0x4
	adds r1, r4, 0x4
	bl sub_8083294
	lsls r0, 24
	lsrs r0, 24
	b _08045AA6
_08045AA4:
	movs r0, 0
_08045AA6:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_8045A70

	thumb_func_start sub_8045AAC
sub_8045AAC:
	push {lr}
	adds r0, 0x4
	bl sub_8083294
	lsls r0, 24
	lsrs r0, 24
	pop {r1}
	bx r1
	thumb_func_end sub_8045AAC

	thumb_func_start sub_8045ABC
sub_8045ABC:
	push {lr}
	adds r0, 0x4
	bl sub_808333C
	lsls r0, 24
	lsrs r0, 24
	pop {r1}
	bx r1
	thumb_func_end sub_8045ABC

	thumb_func_start sub_8045ACC
sub_8045ACC:
	push {r4-r7,lr}
	movs r6, 0
	movs r5, 0
	ldr r7, _08045B50
_08045AD4:
	ldr r0, [r7]
	lsls r1, r5, 2
	ldr r2, _08045B54
	adds r0, r2
	adds r0, r1
	ldr r4, [r0]
	adds r0, r4, 0
	bl sub_80450E0
	lsls r0, 24
	cmp r0, 0
	beq _08045AFA
	ldr r0, [r7]
	lsls r1, r6, 2
	ldr r2, _08045B58
	adds r0, r2
	adds r0, r1
	str r4, [r0]
	adds r6, 0x1
_08045AFA:
	adds r5, 0x1
	cmp r5, 0x3
	ble _08045AD4
	movs r5, 0
	ldr r7, _08045B50
_08045B04:
	ldr r0, [r7]
	lsls r1, r5, 2
	ldr r2, _08045B5C
	adds r0, r2
	adds r0, r1
	ldr r4, [r0]
	adds r0, r4, 0
	bl sub_80450E0
	lsls r0, 24
	cmp r0, 0
	beq _08045B2A
	ldr r0, [r7]
	lsls r1, r6, 2
	ldr r2, _08045B58
	adds r0, r2
	adds r0, r1
	str r4, [r0]
	adds r6, 0x1
_08045B2A:
	adds r5, 0x1
	cmp r5, 0xF
	ble _08045B04
	cmp r6, 0x13
	bgt _08045B4A
	ldr r4, _08045B50
	ldr r3, _08045B58
	movs r2, 0
_08045B3A:
	ldr r0, [r4]
	lsls r1, r6, 2
	adds r0, r3
	adds r0, r1
	str r2, [r0]
	adds r6, 0x1
	cmp r6, 0x13
	ble _08045B3A
_08045B4A:
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_08045B50: .4byte gUnknown_203B418
_08045B54: .4byte 0x0001357c
_08045B58: .4byte 0x000135cc
_08045B5C: .4byte 0x0001358c
	thumb_func_end sub_8045ACC

	thumb_func_start sub_8045B60
sub_8045B60:
	push {r4,lr}
	adds r3, r0, 0
	movs r2, 0
	ldr r0, _08045B78
	ldr r0, [r0]
	ldr r4, _08045B7C
	adds r1, r0, r4
_08045B6E:
	ldr r0, [r1]
	cmp r3, r0
	bne _08045B80
	adds r0, r2, 0
	b _08045B8C
	.align 2, 0
_08045B78: .4byte gUnknown_203B418
_08045B7C: .4byte 0x0001357c
_08045B80:
	adds r1, 0x4
	adds r2, 0x1
	cmp r2, 0x3
	ble _08045B6E
	movs r0, 0x1
	negs r0, r0
_08045B8C:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_8045B60

	thumb_func_start sub_8045B94
sub_8045B94:
	push {r4-r6,lr}
	adds r5, r0, 0
	adds r4, r1, 0
	adds r6, r2, 0
	adds r0, r4, 0
	bl sub_80450F8
	cmp r0, 0x2
	beq _08045BD2
	cmp r0, 0x2
	bhi _08045BB0
	cmp r0, 0x1
	beq _08045BB6
	b _08045BE2
_08045BB0:
	cmp r0, 0x3
	beq _08045BC2
	b _08045BE2
_08045BB6:
	ldr r1, [r4, 0x70]
	adds r0, r5, 0
	adds r2, r6, 0
	bl sub_80708B4
	b _08045BEC
_08045BC2:
	adds r0, r4, 0
	bl sub_8045110
	adds r1, r0, 0
	adds r0, r5, 0
	bl sub_8045BF8
	b _08045BEC
_08045BD2:
	adds r0, r4, 0
	bl sub_804510C
	ldrb r1, [r0]
	adds r0, r5, 0
	bl sub_807FE84
	b _08045BEC
_08045BE2:
	ldr r0, _08045BF4
	ldr r1, [r0]
	adds r0, r5, 0
	bl strcpy
_08045BEC:
	pop {r4-r6}
	pop {r0}
	bx r0
	.align 2, 0
_08045BF4: .4byte gUnknown_80FE6F4
	thumb_func_end sub_8045B94

	thumb_func_start sub_8045BF8
sub_8045BF8:
	push {lr}
	ldr r2, _08045C04
	bl sub_8090E14
	pop {r0}
	bx r0
	.align 2, 0
_08045C04: .4byte gUnknown_80F699C
	thumb_func_end sub_8045BF8

	thumb_func_start sub_8045C08
sub_8045C08:
	push {lr}
	ldr r2, _08045C14
	bl sub_8090E14
	pop {r0}
	bx r0
	.align 2, 0
_08045C14: .4byte gUnknown_80F69A8
	thumb_func_end sub_8045C08

	thumb_func_start sub_8045C18
sub_8045C18:
	push {lr}
	ldr r2, _08045C24
	bl sub_8090E14
	pop {r0}
	bx r0
	.align 2, 0
_08045C24: .4byte gUnknown_80F6990
	thumb_func_end sub_8045C18

	thumb_func_start sub_8045C28
sub_8045C28:
	push {r4-r7,lr}
	adds r5, r0, 0
	adds r6, r2, 0
	lsls r1, 24
	lsrs r4, r1, 24
	adds r1, r4, 0
	movs r2, 0
	bl sub_8090A8C
	movs r7, 0
	adds r0, r4, 0
	bl sub_8091544
	lsls r0, 24
	cmp r0, 0
	beq _08045C72
	cmp r6, 0
	bne _08045C6C
	movs r0, 0x64
	bl sub_8084100
	ldr r1, _08045C64
	ldr r1, [r1]
	ldr r2, _08045C68
	adds r1, r2
	ldrb r1, [r1]
	cmp r0, r1
	bge _08045C72
	b _08045C76
	.align 2, 0
_08045C64: .4byte gUnknown_203B418
_08045C68: .4byte 0x0001c57e
_08045C6C:
	cmp r6, 0x1
	bne _08045C72
	movs r7, 0x1
_08045C72:
	cmp r7, 0
	beq _08045C7E
_08045C76:
	ldrb r1, [r5]
	movs r0, 0x8
	orrs r0, r1
	strb r0, [r5]
_08045C7E:
	adds r0, r4, 0
	bl sub_8090BD0
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x6
	bne _08045CA2
	ldr r0, _08045CA8
	ldr r0, [r0]
	ldr r1, _08045CAC
	adds r0, r1
	ldrb r0, [r0]
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	adds r0, r5, 0
	bl sub_8046CE4
_08045CA2:
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_08045CA8: .4byte gUnknown_203B418
_08045CAC: .4byte 0x0001c58b
	thumb_func_end sub_8045C28

	thumb_func_start sub_8045CB0
sub_8045CB0:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x8
	movs r0, 0x38
	bl sub_8084100
	adds r5, r0, 0
	movs r0, 0x20
	bl sub_8084100
	adds r6, r0, 0
	ldr r0, _08045D34
	ldr r0, [r0]
	ldr r1, _08045D38
	adds r0, r1
	movs r1, 0
	strh r1, [r0]
	movs r0, 0
_08045CDA:
	adds r6, 0x1
	cmp r6, 0x20
	bne _08045CE2
	movs r6, 0
_08045CE2:
	adds r0, 0x1
	mov r10, r0
	movs r3, 0x2
	mov r9, r3
	movs r0, 0x37
	mov r8, r0
_08045CEE:
	adds r5, 0x1
	cmp r5, 0x38
	bne _08045CF6
	movs r5, 0
_08045CF6:
	adds r0, r5, 0
	adds r1, r6, 0
	bl sub_804954C
	adds r2, r0, 0
	ldrh r0, [r2]
	movs r3, 0x80
	lsls r3, 2
	adds r1, r3, 0
	ands r0, r1
	cmp r0, 0
	bne _08045D92
	ldrh r1, [r2, 0x4]
	mov r0, r9
	ands r0, r1
	cmp r0, 0
	beq _08045D92
	movs r7, 0
	lsls r0, r5, 16
	lsls r1, r6, 16
	lsrs r0, 16
	orrs r0, r1
	str r0, [sp, 0x4]
	ldrh r1, [r2]
	movs r0, 0x20
	ands r0, r1
	cmp r0, 0
	beq _08045D3C
	movs r7, 0x1
	movs r0, 0x1
	b _08045D58
	.align 2, 0
_08045D34: .4byte gUnknown_203B418
_08045D38: .4byte 0x00003904
_08045D3C:
	movs r0, 0x3
	ands r0, r1
	cmp r0, 0
	bne _08045D48
	movs r0, 0x3
	b _08045D58
_08045D48:
	movs r0, 0x40
	ands r0, r1
	lsls r0, 16
	lsrs r0, 16
	negs r0, r0
	asrs r0, 31
	mov r1, r9
	ands r0, r1
_08045D58:
	bl sub_803D73C
	lsls r0, 24
	lsrs r0, 24
	adds r4, r0, 0
	bl sub_80914E4
	lsls r0, 24
	cmp r0, 0
	bne _08045D6E
	movs r7, 0
_08045D6E:
	mov r0, sp
	adds r1, r4, 0
	movs r2, 0
	bl sub_8045C28
	cmp r7, 0
	beq _08045D88
	mov r0, sp
	ldrb r1, [r0]
	mov r0, r9
	orrs r0, r1
	mov r1, sp
	strb r0, [r1]
_08045D88:
	add r0, sp, 0x4
	mov r1, sp
	movs r2, 0x1
	bl sub_80460F8
_08045D92:
	movs r3, 0x1
	negs r3, r3
	add r8, r3
	mov r0, r8
	cmp r0, 0
	bge _08045CEE
	mov r0, r10
	cmp r0, 0x1F
	ble _08045CDA
	add sp, 0x8
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_8045CB0

	thumb_func_start sub_8045DB4
sub_8045DB4:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0xB8
	mov r10, r0
	lsls r1, 24
	lsrs r1, 24
	str r1, [sp, 0xA8]
	bl sub_8083600
	adds r7, r0, 0
	ldr r0, [r7, 0x70]
	str r0, [sp, 0xAC]
	mov r1, r10
	movs r2, 0
	ldrsh r0, [r1, r2]
	movs r3, 0x2
	ldrsh r1, [r1, r3]
	bl sub_804954C
	ldr r4, [r0, 0x14]
	cmp r4, 0
	bne _08045DE8
	b _080460E0
_08045DE8:
	adds r0, r4, 0
	bl sub_80450F8
	cmp r0, 0x3
	beq _08045DF4
	b _080460E0
_08045DF4:
	adds r0, r4, 0
	bl sub_8045108
	adds r5, r0, 0
	ldr r0, [sp, 0xAC]
	adds r0, 0x48
	ldrb r0, [r0]
	cmp r0, 0
	bne _08045E08
	b _0804602E
_08045E08:
	adds r0, r7, 0
	movs r1, 0x1
	bl sub_8071518
	lsls r0, 24
	cmp r0, 0
	beq _08045E40
	ldr r0, [sp, 0xA8]
	cmp r0, 0
	bne _08045E1E
	b _080460E0
_08045E1E:
	ldr r0, _08045E34
	adds r1, r5, 0
	bl sub_8045BF8
	ldr r0, _08045E38
	adds r1, r7, 0
	movs r2, 0
	bl sub_8045B94
	ldr r0, _08045E3C
	b _08046048
	.align 2, 0
_08045E34: .4byte gUnknown_202DE58
_08045E38: .4byte gUnknown_202DF98
_08045E3C: .4byte gUnknown_80F8F88
_08045E40:
	ldrb r0, [r5, 0x2]
	bl sub_8090BD0
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x6
	bne _08045E7C
	movs r0, 0xA6
	lsls r0, 1
	bl sub_8083E38
	adds r0, r5, 0
	bl sub_80915D4
	bl sub_80913A0
	ldr r0, _08045E74
	adds r1, r5, 0
	bl sub_8045BF8
	mov r0, r10
	movs r1, 0x1
	bl sub_80461C8
	ldr r0, _08045E78
	b _08045FD0
	.align 2, 0
_08045E74: .4byte gUnknown_202DE58
_08045E78: .4byte gUnknown_80F8FFC
_08045E7C:
	ldr r0, _08045EA8
	ldr r0, [r0]
	ldr r1, _08045EAC
	adds r0, r1
	ldrb r0, [r0]
	cmp r0, 0
	beq _08045EB4
	movs r4, 0
	ldr r0, _08045EB0
	mov r2, sp
	ldr r0, [r0]
	add r1, sp, 0x54
_08045E94:
	stm r1!, {r0}
	stm r2!, {r4}
	adds r0, 0x4
	adds r4, 0x1
	cmp r4, 0x13
	ble _08045E94
	movs r2, 0x14
	mov r8, r2
	b _08045EC4
	.align 2, 0
_08045EA8: .4byte gUnknown_203B418
_08045EAC: .4byte 0x0000065b
_08045EB0: .4byte gUnknown_203B460
_08045EB4:
	ldr r0, [sp, 0xAC]
	adds r0, 0x60
	str r0, [sp, 0x54]
	movs r0, 0x1
	negs r0, r0
	str r0, [sp]
	movs r3, 0x1
	mov r8, r3
_08045EC4:
	ldrb r0, [r5, 0x2]
	add r6, sp, 0xB0
	strb r0, [r6]
	cmp r0, 0x8
	bls _08045ED0
	b _08046000
_08045ED0:
	ldrb r1, [r5]
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	beq _08045EDC
	b _08046000
_08045EDC:
	movs r1, 0x1
	negs r1, r1
	mov r12, r1
	mov r2, r12
	str r2, [sp, 0xB4]
	movs r4, 0
	cmp r4, r8
	bge _08045F2C
	ldr r3, _08045FDC
	mov r9, r3
	add r3, sp, 0x54
_08045EF2:
	ldr r2, [r3]
	ldrb r1, [r2]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _08045F24
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	bne _08045F24
	ldr r1, [r5]
	mov r6, r9
	ands r1, r6
	ldr r0, [r2]
	ands r0, r6
	cmp r1, r0
	bne _08045F24
	ldrb r0, [r2, 0x1]
	cmp r0, 0x63
	beq _08045F24
	ldr r1, [sp, 0xB4]
	cmp r1, r0
	bge _08045F24
	str r0, [sp, 0xB4]
	mov r12, r4
_08045F24:
	adds r3, 0x4
	adds r4, 0x1
	cmp r4, r8
	blt _08045EF2
_08045F2C:
	movs r0, 0x1
	negs r0, r0
	cmp r12, r0
	bne _08045F80
	mov r2, r12
	str r2, [sp, 0xB4]
	movs r4, 0
	cmp r4, r8
	bge _08045F78
	add r3, sp, 0xB0
	ldrb r3, [r3]
	mov r9, r3
	add r3, sp, 0x54
_08045F46:
	ldr r2, [r3]
	ldrb r1, [r2]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _08045F70
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	bne _08045F70
	ldrb r6, [r2, 0x2]
	cmp r9, r6
	bne _08045F70
	ldrb r0, [r2, 0x1]
	cmp r0, 0x63
	beq _08045F70
	ldr r1, [sp, 0xB4]
	cmp r1, r0
	bge _08045F70
	str r0, [sp, 0xB4]
	mov r12, r4
_08045F70:
	adds r3, 0x4
	adds r4, 0x1
	cmp r4, r8
	blt _08045F46
_08045F78:
	movs r0, 0x1
	negs r0, r0
	cmp r12, r0
	beq _08046000
_08045F80:
	add r0, sp, 0x54
	mov r2, r12
	lsls r4, r2, 2
	adds r3, r0, r4
	ldr r2, [r3]
	ldrb r1, [r2, 0x1]
	ldrb r0, [r5, 0x1]
	adds r1, r0
	cmp r1, 0x62
	ble _08045F96
	movs r1, 0x63
_08045F96:
	strb r1, [r2, 0x1]
	ldrb r1, [r5]
	movs r0, 0x8
	ands r0, r1
	cmp r0, 0
	beq _08045FAC
	ldr r0, [r3]
	ldrb r1, [r0]
	movs r2, 0x8
	orrs r1, r2
	strb r1, [r0]
_08045FAC:
	ldr r0, _08045FE0
	adds r1, r5, 0
	bl sub_8045BF8
	mov r0, r10
	movs r1, 0x1
	bl sub_80461C8
	movs r0, 0xA5
	lsls r0, 1
	bl sub_8083E38
	mov r3, sp
	adds r0, r3, r4
	ldr r0, [r0]
	cmp r0, 0
	bge _08045FE8
	ldr r0, _08045FE4
_08045FD0:
	ldr r1, [r0]
	adds r0, r7, 0
	bl sub_80522A8
	b _08045FF2
	.align 2, 0
_08045FDC: .4byte 0x00ff0008
_08045FE0: .4byte gUnknown_202DE58
_08045FE4: .4byte gUnknown_80F8FC4
_08045FE8:
	ldr r0, _08045FFC
	ldr r1, [r0]
	adds r0, r7, 0
	bl sub_80522A8
_08045FF2:
	ldrb r0, [r5, 0x2]
	bl sub_8052EC0
	b _080460E0
	.align 2, 0
_08045FFC: .4byte gUnknown_80F8FF8
_08046000:
	movs r4, 0
	cmp r4, r8
	bge _0804602A
	ldr r0, [sp, 0x54]
	ldrb r1, [r0]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _0804602A
	movs r3, 0x1
	add r2, sp, 0x54
_08046016:
	adds r2, 0x4
	adds r4, 0x1
	cmp r4, r8
	bge _0804602A
	ldr r0, [r2]
	ldrb r1, [r0]
	adds r0, r3, 0
	ands r0, r1
	cmp r0, 0
	bne _08046016
_0804602A:
	cmp r4, r8
	bne _08046060
_0804602E:
	ldr r6, [sp, 0xA8]
	cmp r6, 0
	beq _080460E0
	ldr r0, _08046054
	adds r1, r5, 0
	bl sub_8045BF8
	ldr r0, _08046058
	adds r1, r7, 0
	movs r2, 0
	bl sub_8045B94
	ldr r0, _0804605C
_08046048:
	ldr r1, [r0]
	adds r0, r7, 0
	bl sub_80522A8
	b _080460E0
	.align 2, 0
_08046054: .4byte gUnknown_202DE58
_08046058: .4byte gUnknown_202DF98
_0804605C: .4byte gUnknown_80F8F54
_08046060:
	movs r0, 0xA5
	lsls r0, 1
	bl sub_8083E38
	lsls r0, r4, 2
	add r0, sp
	ldr r0, [r0]
	cmp r0, 0
	bge _08046094
	ldr r0, [r5]
	ldr r1, [sp, 0xAC]
	str r0, [r1, 0x60]
	ldr r0, _0804608C
	adds r1, r5, 0
	bl sub_8045BF8
	mov r0, r10
	movs r1, 0x1
	bl sub_80461C8
	ldr r0, _08046090
	b _080460AC
	.align 2, 0
_0804608C: .4byte gUnknown_202DE58
_08046090: .4byte gUnknown_80F8FC4
_08046094:
	adds r0, r5, 0
	bl sub_8091290
	lsls r0, 24
	cmp r0, 0
	beq _080460C0
	ldr r0, _080460B8
	adds r1, r7, 0
	movs r2, 0
	bl sub_8045B94
	ldr r0, _080460BC
_080460AC:
	ldr r1, [r0]
	adds r0, r7, 0
	bl sub_80522A8
	b _080460DA
	.align 2, 0
_080460B8: .4byte gUnknown_202DF98
_080460BC: .4byte gUnknown_80F8FAC
_080460C0:
	ldr r0, _080460F0
	adds r1, r5, 0
	bl sub_8045BF8
	mov r0, r10
	movs r1, 0x1
	bl sub_80461C8
	ldr r0, _080460F4
	ldr r1, [r0]
	adds r0, r7, 0
	bl sub_80522A8
_080460DA:
	ldrb r0, [r5, 0x2]
	bl sub_8052EC0
_080460E0:
	add sp, 0xB8
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_080460F0: .4byte gUnknown_202DE58
_080460F4: .4byte gUnknown_80F8FF8
	thumb_func_end sub_8045DB4

	thumb_func_start sub_80460F8
sub_80460F8:
	push {r4-r7,lr}
	adds r5, r0, 0
	adds r6, r1, 0
	lsls r2, 24
	lsrs r7, r2, 24
	bl sub_8045708
	adds r4, r0, 0
	cmp r4, 0
	bne _08046110
	movs r0, 0
	b _080461B6
_08046110:
	ldr r1, [r4, 0x70]
	ldr r0, [r6]
	str r0, [r1]
	ldr r2, [r4, 0x70]
	ldrb r1, [r2]
	movs r0, 0xEF
	ands r0, r1
	strb r0, [r2]
	adds r1, r4, 0
	adds r1, 0x20
	movs r0, 0x1
	strb r0, [r1]
	movs r1, 0
	ldrsh r0, [r5, r1]
	movs r2, 0x2
	ldrsh r1, [r5, r2]
	bl sub_8049590
	str r4, [r0, 0x14]
	ldrh r1, [r0]
	movs r0, 0x20
	ands r0, r1
	cmp r0, 0
	beq _08046186
	ldrb r0, [r6, 0x2]
	bl sub_80914E4
	lsls r0, 24
	cmp r0, 0
	beq _08046186
	ldrb r1, [r6]
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	beq _08046170
	cmp r7, 0
	beq _08046186
	adds r0, r6, 0
	bl sub_8090C7C
	ldr r1, _08046168
	ldr r2, [r1]
	ldr r1, _0804616C
	b _0804617E
	.align 2, 0
_08046168: .4byte gUnknown_203B418
_0804616C: .4byte 0x0000068c
_08046170:
	adds r0, r6, 0
	bl sub_8090CCC
	ldr r1, _080461BC
	ldr r2, [r1]
	movs r1, 0xD2
	lsls r1, 3
_0804617E:
	adds r2, r1
	ldr r1, [r2]
	adds r1, r0
	str r1, [r2]
_08046186:
	movs r6, 0
	movs r4, 0
_0804618A:
	ldr r5, _080461BC
	ldr r0, [r5]
	lsls r1, r4, 2
	ldr r2, _080461C0
	adds r0, r2
	adds r0, r1
	ldr r0, [r0]
	bl sub_80450E0
	lsls r0, 24
	adds r1, r4, 0x1
	cmp r0, 0
	beq _080461A6
	adds r6, r1, 0
_080461A6:
	adds r4, r1, 0
	cmp r4, 0x3F
	ble _0804618A
	ldr r0, [r5]
	ldr r1, _080461C4
	adds r0, r1
	strh r6, [r0]
	movs r0, 0x1
_080461B6:
	pop {r4-r7}
	pop {r1}
	bx r1
	.align 2, 0
_080461BC: .4byte gUnknown_203B418
_080461C0: .4byte 0x0001361c
_080461C4: .4byte 0x00003904
	thumb_func_end sub_80460F8

	thumb_func_start sub_80461C8
sub_80461C8:
	push {r4-r7,lr}
	adds r2, r0, 0
	lsls r1, 24
	lsrs r7, r1, 24
	movs r1, 0
	ldrsh r0, [r2, r1]
	movs r3, 0x2
	ldrsh r1, [r2, r3]
	bl sub_8049590
	adds r6, r0, 0
	ldr r5, [r6, 0x14]
	cmp r5, 0
	beq _080461EE
	adds r0, r5, 0
	bl sub_80450F8
	cmp r0, 0x3
	beq _080461F2
_080461EE:
	movs r0, 0
	b _08046284
_080461F2:
	adds r0, r5, 0
	bl sub_8045108
	adds r4, r0, 0
	ldrh r1, [r6]
	movs r0, 0x20
	ands r0, r1
	cmp r0, 0
	beq _0804624E
	ldrb r0, [r4, 0x2]
	bl sub_80914E4
	lsls r0, 24
	cmp r0, 0
	beq _0804624E
	ldrb r1, [r4]
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	beq _08046238
	cmp r7, 0
	beq _0804624E
	adds r0, r4, 0
	bl sub_8090C7C
	ldr r1, _08046230
	ldr r2, [r1]
	ldr r1, _08046234
	adds r2, r1
	b _08046248
	.align 2, 0
_08046230: .4byte gUnknown_203B418
_08046234: .4byte 0x0000068c
_08046238:
	adds r0, r4, 0
	bl sub_8090CCC
	ldr r1, _0804628C
	ldr r2, [r1]
	movs r3, 0xD2
	lsls r3, 3
	adds r2, r3
_08046248:
	ldr r1, [r2]
	subs r1, r0
	str r1, [r2]
_0804624E:
	movs r0, 0
	str r0, [r6, 0x14]
	str r0, [r5]
	movs r6, 0
	movs r4, 0
_08046258:
	ldr r5, _0804628C
	ldr r0, [r5]
	lsls r1, r4, 2
	ldr r2, _08046290
	adds r0, r2
	adds r0, r1
	ldr r0, [r0]
	bl sub_80450E0
	lsls r0, 24
	adds r1, r4, 0x1
	cmp r0, 0
	beq _08046274
	adds r6, r1, 0
_08046274:
	adds r4, r1, 0
	cmp r4, 0x3F
	ble _08046258
	ldr r0, [r5]
	ldr r3, _08046294
	adds r0, r3
	strh r6, [r0]
	movs r0, 0x1
_08046284:
	pop {r4-r7}
	pop {r1}
	bx r1
	.align 2, 0
_0804628C: .4byte gUnknown_203B418
_08046290: .4byte 0x0001361c
_08046294: .4byte 0x00003904
	thumb_func_end sub_80461C8

	thumb_func_start sub_8046298
sub_8046298:
	ldrb r0, [r0, 0x2]
	ldr r1, _080462A8
	ldr r1, [r1]
	lsls r0, 5
	adds r0, r1
	ldrb r0, [r0, 0xD]
	bx lr
	.align 2, 0
_080462A8: .4byte gItemParametersFile + 4
	thumb_func_end sub_8046298

	thumb_func_start sub_80462AC
sub_80462AC:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x8
	adds r4, r0, 0
	ldr r0, [sp, 0x28]
	lsls r1, 24
	lsrs r1, 24
	mov r10, r1
	lsls r2, 24
	lsrs r5, r2, 24
	lsls r3, 24
	lsrs r3, 24
	mov r9, r3
	lsls r0, 24
	lsrs r0, 24
	str r0, [sp]
	movs r0, 0
	str r0, [sp, 0x4]
	adds r0, r4, 0
	bl sub_80450E0
	lsls r0, 24
	cmp r0, 0
	bne _080462E4
	b _08046498
_080462E4:
	cmp r5, 0
	beq _08046316
	movs r1, 0x4
	ldrsh r0, [r4, r1]
	movs r2, 0x6
	ldrsh r1, [r4, r2]
	bl sub_804954C
	ldrh r0, [r0]
	movs r1, 0x3
	ands r1, r0
	cmp r1, 0
	bne _08046300
	b _08046498
_08046300:
	cmp r1, 0x2
	bne _08046308
	movs r3, 0x1
	str r3, [sp, 0x4]
_08046308:
	adds r0, r4, 0
	bl sub_8045888
	lsls r0, 24
	cmp r0, 0
	bne _08046316
	b _08046498
_08046316:
	ldr r1, [r4, 0xC]
	cmp r1, 0
	bge _0804631E
	adds r1, 0xFF
_0804631E:
	asrs r1, 8
	ldr r0, _080463A4
	ldr r2, [r0]
	ldr r5, _080463A8
	adds r0, r2, r5
	movs r3, 0
	ldrsh r0, [r0, r3]
	subs r6, r1, r0
	ldr r3, [r4, 0x10]
	ldr r0, [r4, 0x1C]
	subs r1, r3, r0
	cmp r1, 0
	bge _0804633A
	adds r1, 0xFF
_0804633A:
	asrs r1, 8
	ldr r5, _080463AC
	adds r0, r2, r5
	movs r5, 0
	ldrsh r2, [r0, r5]
	subs r1, r2
	mov r8, r1
	adds r0, r3, 0
	cmp r0, 0
	bge _08046350
	adds r0, 0xFF
_08046350:
	asrs r0, 8
	subs r0, r2
	adds r7, r0, 0
	adds r7, 0x8
	lsrs r0, r7, 31
	adds r0, r7, r0
	asrs r7, r0, 1
	movs r0, 0x20
	negs r0, r0
	cmp r6, r0
	bge _08046368
	b _08046498
_08046368:
	cmp r8, r0
	bge _0804636E
	b _08046498
_0804636E:
	movs r0, 0x88
	lsls r0, 1
	cmp r6, r0
	ble _08046378
	b _08046498
_08046378:
	mov r0, r8
	cmp r0, 0xC0
	ble _08046380
	b _08046498
_08046380:
	ldr r5, _080463B0
	ldrh r1, [r5, 0x2]
	ldr r0, _080463B4
	ands r0, r1
	strh r0, [r5, 0x2]
	mov r1, r10
	cmp r1, 0
	beq _080463BC
	movs r2, 0x17
	mov r10, r2
	movs r2, 0xA0
	lsls r2, 8
	ldrh r1, [r5, 0x4]
	ldr r0, _080463B8
	ands r0, r1
	orrs r0, r2
	strh r0, [r5, 0x4]
	b _08046408
	.align 2, 0
_080463A4: .4byte gUnknown_203B418
_080463A8: .4byte 0x000181f0
_080463AC: .4byte 0x000181f2
_080463B0: .4byte gUnknown_202EDC0
_080463B4: .4byte 0x0000c1ff
_080463B8: .4byte 0x00000fff
_080463BC:
	ldr r0, [r4, 0x70]
	bl sub_8046298
	mov r10, r0
	mov r3, r9
	cmp r3, 0xFF
	beq _080463EE
	cmp r0, 0
	bne _080463EE
	ldr r0, _08046478
	add r0, r9
	ldrb r0, [r0]
	mov r10, r0
	ldr r0, _0804647C
	add r0, r9
	ldrb r1, [r0]
	lsls r1, 3
	movs r0, 0x1F
	ands r1, r0
	lsls r1, 9
	ldrh r2, [r5, 0x2]
	ldr r0, _08046480
	ands r0, r2
	orrs r0, r1
	strh r0, [r5, 0x2]
_080463EE:
	ldr r0, [r4, 0x70]
	ldrb r0, [r0, 0x2]
	bl sub_8090D58
	movs r1, 0xF
	ands r0, r1
	lsls r0, 12
	ldr r3, _08046484
	ldrh r2, [r3, 0x4]
	ldr r1, _08046488
	ands r1, r2
	orrs r1, r0
	strh r1, [r3, 0x4]
_08046408:
	ldr r1, _08046488
	mov r5, r8
	ands r1, r5
	lsls r1, 4
	ldr r4, _08046484
	ldrh r2, [r4, 0x6]
	movs r0, 0xF
	ands r0, r2
	orrs r0, r1
	strh r0, [r4, 0x6]
	ldr r0, _0804648C
	ands r6, r0
	ldrh r1, [r4, 0x2]
	movs r0, 0xFE
	lsls r0, 8
	ands r0, r1
	orrs r0, r6
	strh r0, [r4, 0x2]
	ldr r0, [sp, 0x4]
	lsls r3, r0, 10
	ldrh r2, [r4]
	ldr r1, _08046490
	adds r0, r1, 0
	ands r0, r2
	orrs r0, r3
	strh r0, [r4]
	movs r2, 0xC0
	lsls r2, 4
	ldrh r0, [r4, 0x4]
	ands r1, r0
	orrs r1, r2
	mov r2, r10
	lsls r0, r2, 2
	movs r3, 0xD0
	lsls r3, 1
	adds r0, r3
	ldr r2, _08046494
	ands r0, r2
	movs r2, 0xFC
	lsls r2, 8
	ands r1, r2
	orrs r1, r0
	strh r1, [r4, 0x4]
	ldr r5, [sp]
	cmp r5, 0
	bne _08046466
	movs r7, 0x1
_08046466:
	adds r0, r4, 0
	adds r1, r7, 0
	movs r2, 0
	movs r3, 0
	bl AddSprite
	movs r0, 0x1
	b _0804649A
	.align 2, 0
_08046478: .4byte gUnknown_203B420
_0804647C: .4byte gUnknown_203B428
_08046480: .4byte 0x0000c1ff
_08046484: .4byte gUnknown_202EDC0
_08046488: .4byte 0x00000fff
_0804648C: .4byte 0x000001ff
_08046490: .4byte 0x0000f3ff
_08046494: .4byte 0x000003ff
_08046498:
	movs r0, 0
_0804649A:
	add sp, 0x8
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_80462AC

	thumb_func_start sub_80464AC
sub_80464AC:
	push {r4,lr}
	ldr r4, _080464C4
	ldrb r0, [r0, 0x2]
	bl sub_8090D6C
	lsls r0, 3
	adds r0, r4
	ldr r0, [r0]
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_080464C4: .4byte gActions
	thumb_func_end sub_80464AC

	thumb_func_start sub_80464C8
sub_80464C8:
	push {r4-r6,lr}
	sub sp, 0x78
	adds r6, r0, 0
	adds r3, r1, 0
	adds r5, r2, 0
	movs r0, 0x3
	str r0, [sp, 0x4]
	add r0, sp, 0x28
	movs r4, 0
	strb r4, [r0]
	add r1, sp, 0x24
	movs r0, 0x1
	strb r0, [r1]
	mov r0, sp
	adds r0, 0x26
	strb r4, [r0]
	str r5, [sp, 0x74]
	ldr r0, [r3]
	str r0, [sp, 0x8]
	movs r1, 0
	ldrsh r0, [r3, r1]
	lsls r1, r0, 1
	adds r1, r0
	lsls r1, 3
	adds r1, 0x4
	lsls r1, 8
	movs r2, 0x2
	ldrsh r0, [r3, r2]
	lsls r2, r0, 1
	adds r2, r0
	lsls r2, 3
	adds r2, 0x4
	lsls r2, 8
	add r0, sp, 0x4
	bl sub_8045394
	add r0, sp, 0x4
	strh r4, [r0, 0x26]
	str r4, [sp]
	adds r0, r6, 0
	add r1, sp, 0x4
	adds r2, r5, 0
	movs r3, 0x1
	bl sub_804652C
	add sp, 0x78
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end sub_80464C8

	thumb_func_start sub_804652C
sub_804652C:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x10
	mov r10, r0
	adds r5, r1, 0
	mov r9, r2
	lsls r3, 24
	lsrs r6, r3, 24
	movs r1, 0x4
	ldrsh r0, [r5, r1]
	movs r2, 0x6
	ldrsh r1, [r5, r2]
	bl sub_804954C
	adds r4, r0, 0
	ldr r0, [r4, 0x14]
	movs r3, 0
	str r3, [sp, 0xC]
	cmp r0, 0
	beq _0804658C
	bl sub_80450F8
	cmp r0, 0x2
	bne _0804658C
	adds r4, r5, 0x4
	adds r0, r5, 0
	adds r1, r4, 0
	bl sub_8046734
	adds r0, r4, 0
	movs r1, 0x1
	bl sub_807FE44
	ldr r0, _080465A4
	ldr r1, [r0]
	mov r0, r10
	bl sub_80522A8
	mov r0, r9
	ldrb r1, [r0]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	bne _0804658C
	b _0804671E
_0804658C:
	ldrh r1, [r5, 0x6]
	lsls r1, 16
	ldrh r0, [r5, 0x4]
	orrs r0, r1
	str r0, [sp]
	mov r8, r0
	movs r7, 0x1
	cmp r6, 0
	beq _08046632
	movs r7, 0
	b _08046632
	.align 2, 0
_080465A4: .4byte gUnknown_80FED30
_080465A8:
	lsls r3, r7, 2
	adds r3, r0
	ldrh r0, [r3]
	ldrh r1, [r5, 0x4]
	adds r0, r1
	lsls r0, 16
	lsrs r0, 16
	ldr r1, _08046628
	ldr r2, [sp]
	ands r2, r1
	orrs r2, r0
	str r2, [sp]
	ldrh r0, [r3, 0x2]
	ldrh r3, [r5, 0x6]
	adds r0, r3
	lsls r0, 16
	ldr r1, _0804662C
	ands r1, r2
	orrs r1, r0
	str r1, [sp]
	mov r0, sp
	movs r2, 0
	ldrsh r0, [r0, r2]
	asrs r1, 16
	bl sub_804954C
	adds r4, r0, 0
	ldrh r1, [r4]
	movs r6, 0x3
	adds r0, r6, 0
	ands r0, r1
	cmp r0, 0
	beq _08046630
	movs r0, 0x80
	lsls r0, 2
	ands r0, r1
	cmp r0, 0
	bne _08046630
	ldr r0, [r4, 0x14]
	cmp r0, 0
	bne _08046630
	adds r0, r5, 0
	mov r1, sp
	bl sub_8046734
	ldr r3, [sp]
	mov r8, r3
	ldrh r1, [r4]
	adds r0, r6, 0
	ands r0, r1
	cmp r0, 0x3
	beq _08046620
	mov r0, sp
	mov r1, r9
	movs r2, 0x1
	bl sub_80460F8
	lsls r0, 24
	cmp r0, 0
	beq _08046644
_08046620:
	movs r0, 0x1
	str r0, [sp, 0xC]
	b _08046644
	.align 2, 0
_08046628: .4byte 0xffff0000
_0804662C: .4byte 0x0000ffff
_08046630:
	adds r7, 0x1
_08046632:
	ldr r0, _08046688
	lsls r1, r7, 2
	adds r1, r0
	movs r2, 0
	ldrsh r1, [r1, r2]
	cmp r1, 0x63
	bne _080465A8
	movs r3, 0
	str r3, [sp, 0xC]
_08046644:
	ldr r0, _0804668C
	mov r1, r9
	bl sub_8045BF8
	ldr r0, [sp, 0xC]
	cmp r0, 0
	beq _080466C8
	mov r0, sp
	movs r1, 0
	ldrsh r0, [r0, r1]
	mov r4, sp
	movs r2, 0x2
	ldrsh r1, [r4, r2]
	bl sub_80402AC
	mov r0, sp
	movs r3, 0
	ldrsh r0, [r0, r3]
	movs r2, 0x2
	ldrsh r1, [r4, r2]
	bl sub_804954C
	ldrh r0, [r0]
	movs r1, 0x3
	ands r1, r0
	adds r0, r1, 0
	cmp r1, 0x1
	beq _0804669A
	cmp r1, 0x1
	bgt _08046690
	cmp r1, 0
	beq _080466AC
	b _0804671E
	.align 2, 0
_08046688: .4byte gUnknown_80F4468
_0804668C: .4byte gUnknown_202DE58
_08046690:
	cmp r0, 0x2
	beq _080466A4
	cmp r0, 0x3
	beq _080466B4
	b _0804671E
_0804669A:
	ldr r0, _080466A0
	b _080466B6
	.align 2, 0
_080466A0: .4byte gUnknown_80F93E8
_080466A4:
	ldr r0, _080466A8
	b _080466B6
	.align 2, 0
_080466A8: .4byte gUnknown_80F9408
_080466AC:
	ldr r0, _080466B0
	b _080466B6
	.align 2, 0
_080466B0: .4byte gUnknown_80F9424
_080466B4:
	ldr r0, _080466C4
_080466B6:
	ldr r2, [r0]
	mov r0, r10
	mov r1, sp
	bl sub_8052364
	b _0804671E
	.align 2, 0
_080466C4: .4byte gUnknown_80F949C
_080466C8:
	mov r3, r8
	lsls r1, r3, 16
	asrs r1, 16
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 11
	movs r1, 0xC0
	lsls r1, 4
	adds r0, r1
	str r0, [sp, 0x4]
	asrs r1, r3, 16
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 11
	movs r2, 0xC0
	lsls r2, 4
	adds r0, r2
	add r2, sp, 0x4
	str r0, [r2, 0x4]
	ldr r3, [sp, 0x30]
	cmp r3, 0
	beq _0804670C
	movs r1, 0
	ldrsh r0, [r3, r1]
	lsls r0, 8
	ldr r1, [sp, 0x4]
	adds r0, r1
	str r0, [sp, 0x4]
	movs r1, 0x2
	ldrsh r0, [r3, r1]
	lsls r0, 8
	ldr r1, [r2, 0x4]
	adds r0, r1
	str r0, [r2, 0x4]
_0804670C:
	adds r0, r2, 0
	bl sub_804219C
	ldr r0, _08046730
	ldr r2, [r0]
	mov r0, r10
	mov r1, sp
	bl sub_8052364
_0804671E:
	add sp, 0x10
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_08046730: .4byte gUnknown_80F943C
	thumb_func_end sub_804652C

	thumb_func_start sub_8046734
sub_8046734:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x18
	mov r8, r0
	ldr r0, _08046858
	ldr r0, [r0]
	ldr r2, _0804685C
	adds r0, r2
	ldrb r0, [r0]
	str r0, [sp, 0xC]
	movs r0, 0
	ldrsh r2, [r1, r0]
	lsls r0, r2, 1
	adds r0, r2
	lsls r0, 3
	adds r0, 0x4
	lsls r4, r0, 8
	movs r2, 0x2
	ldrsh r1, [r1, r2]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 3
	adds r0, 0x4
	lsls r5, r0, 8
	mov r1, r8
	ldr r0, [r1, 0xC]
	subs r0, r4
	cmp r0, 0
	bge _08046776
	negs r0, r0
_08046776:
	mov r2, r8
	ldr r2, [r2, 0x10]
	mov r9, r2
	cmp r0, 0xB
	bgt _0804678C
	subs r0, r2, r5
	cmp r0, 0
	bge _08046788
	negs r0, r0
_08046788:
	cmp r0, 0xB
	ble _08046822
_0804678C:
	movs r0, 0
	mov r10, r0
	movs r1, 0
	str r1, [sp, 0x10]
	mov r2, r8
	ldr r0, [r2, 0xC]
	str r0, [sp, 0x4]
	mov r1, r9
	str r1, [sp, 0x8]
	subs r0, r4, r0
	movs r1, 0x18
	bl __divsi3
	adds r6, r0, 0
	mov r2, r9
	subs r0, r5, r2
	movs r1, 0x18
	bl __divsi3
	adds r7, r0, 0
	movs r0, 0
	mov r9, r0
	mov r1, sp
	adds r1, 0x4
	str r1, [sp, 0x14]
_080467BE:
	ldr r0, [sp, 0x4]
	adds r0, r6
	str r0, [sp, 0x4]
	ldr r2, [sp, 0x14]
	ldr r0, [r2, 0x4]
	adds r0, r7
	str r0, [r2, 0x4]
	ldr r0, [sp, 0x10]
	bl sub_8009C7C
	lsls r1, r0, 1
	adds r1, r0
	lsls r1, 2
	mov r0, r8
	str r1, [r0, 0x1C]
	add r1, sp, 0x4
	bl sub_804535C
	mov r1, r10
	lsls r3, r1, 24
	lsrs r3, 24
	movs r0, 0
	str r0, [sp]
	mov r0, r8
	ldr r1, [sp, 0xC]
	movs r2, 0
	bl sub_80462AC
	movs r0, 0x13
	bl sub_803E46C
	ldr r2, [sp, 0x10]
	adds r2, 0x55
	str r2, [sp, 0x10]
	movs r0, 0x3
	mov r1, r9
	ands r0, r1
	cmp r0, 0
	bne _08046810
	movs r2, 0x1
	add r10, r2
_08046810:
	movs r0, 0x7
	mov r1, r10
	ands r1, r0
	mov r10, r1
	movs r2, 0x1
	add r9, r2
	mov r0, r9
	cmp r0, 0x17
	ble _080467BE
_08046822:
	mov r0, r8
	adds r1, r4, 0
	adds r2, r5, 0
	bl sub_8045394
	movs r0, 0
	mov r1, r8
	str r0, [r1, 0x1C]
	str r0, [sp]
	mov r0, r8
	ldr r1, [sp, 0xC]
	movs r2, 0x1
	movs r3, 0xFF
	bl sub_80462AC
	movs r0, 0x13
	bl sub_803E46C
	add sp, 0x18
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_08046858: .4byte gUnknown_203B418
_0804685C: .4byte 0x00018210
	thumb_func_end sub_8046734

	thumb_func_start sub_8046860
sub_8046860:
	push {r4,r5,lr}
	sub sp, 0x4
	adds r4, r1, 0
	adds r5, r2, 0
	str r3, [sp]
	adds r2, r4, 0
	adds r3, r5, 0
	bl sub_804687C
	add sp, 0x4
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_8046860

	thumb_func_start sub_804687C
sub_804687C:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	ldr r4, _08046970
	add sp, r4
	ldr r5, _08046974
	add r5, sp
	str r0, [r5]
	movs r0, 0xA5
	lsls r0, 3
	add r0, sp
	str r1, [r0]
	mov r8, r2
	ldr r1, _08046978
	add r1, sp
	str r3, [r1]
	movs r1, 0
	movs r7, 0x1D
	ldr r0, _0804697C
	add r0, sp
_080468A8:
	strb r1, [r0]
	subs r0, 0x1
	subs r7, 0x1
	cmp r7, 0
	bge _080468A8
	movs r7, 0
	movs r2, 0xAD
	lsls r2, 3
	add r2, sp
	ldr r2, [r2]
	cmp r7, r2
	blt _080468C2
	b _080469DE
_080468C2:
	ldr r3, _08046980
	mov r9, r3
	ldr r5, _08046984
	movs r0, 0
	ldrsh r5, [r5, r0]
	ldr r0, _08046988
	add r0, sp
	str r5, [r0]
_080468D2:
	mov r1, r8
	ldrh r0, [r1]
	ldr r1, _0804698C
	ands r4, r1
	orrs r4, r0
	mov r2, r8
	ldrh r0, [r2, 0x2]
	lsls r0, 16
	mov r3, r9
	ands r4, r3
	orrs r4, r0
	movs r5, 0
	adds r0, r7, 0x1
	mov r10, r0
	ldr r1, _08046984
	ldr r2, _08046988
	add r2, sp
	ldr r2, [r2]
	cmp r2, 0x63
	beq _080469B0
	ldr r3, _08046990
	add r3, sp
	ldr r0, _08046994
	add r0, sp
	str r3, [r0]
_08046904:
	ldr r0, _08046998
	add r0, sp
	adds r6, r0, r5
	ldrb r0, [r6]
	cmp r0, 0
	bne _0804699C
	lsls r2, r5, 2
	adds r2, r1
	ldrh r0, [r2]
	mov r1, r8
	ldrh r1, [r1]
	adds r0, r1
	lsls r0, 16
	lsrs r0, 16
	ldr r1, _0804698C
	ands r4, r1
	orrs r4, r0
	ldrh r0, [r2, 0x2]
	mov r2, r8
	ldrh r2, [r2, 0x2]
	adds r0, r2
	lsls r0, 16
	mov r3, r9
	ands r4, r3
	orrs r4, r0
	lsls r0, r4, 16
	asrs r0, 16
	asrs r1, r4, 16
	bl sub_804954C
	adds r2, r0, 0
	ldrh r1, [r2]
	movs r0, 0x3
	ands r0, r1
	cmp r0, 0
	beq _0804699C
	movs r3, 0x80
	lsls r3, 2
	adds r0, r3, 0
	ands r0, r1
	cmp r0, 0
	bne _0804699C
	ldr r0, [r2, 0x14]
	cmp r0, 0
	bne _0804699C
	lsls r0, r7, 2
	ldr r5, _08046994
	add r5, sp
	ldr r5, [r5]
	adds r0, r5, r0
	str r4, [r0]
	movs r0, 0x1
	strb r0, [r6]
	b _080469CE
	.align 2, 0
_08046970: .4byte 0xfffffab8
_08046974: .4byte 0x00000524
_08046978: .4byte 0x0000052c
_0804697C: .4byte 0x00000521
_08046980: .4byte 0x0000ffff
_08046984: .4byte gUnknown_80F4468
_08046988: .4byte 0x00000534
_0804698C: .4byte 0xffff0000
_08046990: .4byte 0x0000048c
_08046994: .4byte 0x00000544
_08046998: .4byte 0x00000504
_0804699C:
	adds r5, 0x1
	cmp r5, 0x1D
	bgt _080469B0
	lsls r0, r5, 2
	ldr r1, _08046A18
	adds r0, r1
	movs r2, 0
	ldrsh r0, [r0, r2]
	cmp r0, 0x63
	bne _08046904
_080469B0:
	movs r3, 0
	cmp r3, 0
	bne _080469CE
	ldr r1, _08046A1C
	add r1, sp
	lsls r0, r7, 2
	adds r1, r0
	ldrh r2, [r1]
	mov r0, r9
	orrs r0, r2
	strh r0, [r1]
	ldrh r2, [r1, 0x2]
	mov r0, r9
	orrs r0, r2
	strh r0, [r1, 0x2]
_080469CE:
	mov r7, r10
	movs r5, 0xAD
	lsls r5, 3
	add r5, sp
	ldr r5, [r5]
	cmp r7, r5
	bge _080469DE
	b _080468D2
_080469DE:
	movs r1, 0
	mov r9, r1
	movs r7, 0
	movs r0, 0xAD
	lsls r0, 3
	add r0, sp
	ldr r0, [r0]
	cmp r7, r0
	blt _080469F2
	b _08046B0A
_080469F2:
	movs r2, 0
	mov r8, r2
_080469F6:
	ldr r0, _08046A1C
	add r0, sp
	lsls r2, r7, 2
	adds r3, r0, r2
	movs r4, 0
	ldrsh r0, [r3, r4]
	cmp r0, 0
	bge _08046A20
	movs r0, 0x74
	muls r0, r7
	add r0, sp
	adds r0, 0x4
	mov r5, r8
	str r5, [r0]
	movs r0, 0x1
	mov r9, r0
	b _08046AFA
	.align 2, 0
_08046A18: .4byte gUnknown_80F4468
_08046A1C: .4byte 0x0000048c
_08046A20:
	movs r0, 0x74
	adds r6, r7, 0
	muls r6, r0
	mov r4, sp
	adds r4, r6
	adds r4, 0x4
	movs r0, 0x3
	str r0, [r4]
	adds r0, r4, 0
	adds r0, 0x24
	mov r1, r8
	strb r1, [r0]
	adds r1, r4, 0
	adds r1, 0x20
	movs r0, 0x1
	strb r0, [r1]
	adds r0, r4, 0
	adds r0, 0x22
	mov r5, r8
	strb r5, [r0]
	add r0, sp, 0x74
	adds r0, r6
	ldr r1, _08046B2C
	add r1, sp
	ldr r1, [r1]
	adds r2, r1, r2
	str r2, [r0]
	add r0, sp, 0x8
	adds r0, r6
	ldr r1, [r3]
	str r1, [r0]
	movs r2, 0xA5
	lsls r2, 3
	add r2, sp
	ldr r2, [r2]
	movs r5, 0
	ldrsh r0, [r2, r5]
	lsls r1, r0, 1
	adds r1, r0
	lsls r1, 3
	adds r1, 0x4
	lsls r1, 8
	movs r5, 0x2
	ldrsh r0, [r2, r5]
	lsls r2, r0, 1
	adds r2, r0
	lsls r2, 3
	adds r2, 0x4
	lsls r2, 8
	adds r0, r4, 0
	movs r5, 0xA8
	lsls r5, 3
	add r5, sp
	str r3, [r5]
	bl sub_8045394
	mov r0, r8
	strh r0, [r4, 0x26]
	ldr r4, _08046B30
	add r4, sp
	lsls r5, r7, 3
	adds r4, r5
	movs r1, 0xA8
	lsls r1, 3
	add r1, sp
	ldr r3, [r1]
	movs r2, 0
	ldrsh r1, [r3, r2]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 3
	adds r0, 0x4
	lsls r0, 8
	add r1, sp, 0x10
	adds r1, r6
	ldr r1, [r1]
	subs r0, r1
	movs r1, 0x18
	movs r2, 0xA8
	lsls r2, 3
	add r2, sp
	str r3, [r2]
	bl __divsi3
	str r0, [r4]
	movs r4, 0x97
	lsls r4, 3
	add r4, sp
	adds r4, r5
	movs r5, 0xA8
	lsls r5, 3
	add r5, sp
	ldr r3, [r5]
	movs r0, 0x2
	ldrsh r1, [r3, r0]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 3
	adds r0, 0x4
	lsls r0, 8
	add r1, sp, 0x14
	adds r1, r6
	ldr r1, [r1]
	subs r0, r1
	movs r1, 0x18
	bl __divsi3
	str r0, [r4]
	movs r1, 0x1
_08046AFA:
	adds r7, 0x1
	movs r2, 0xAD
	lsls r2, 3
	add r2, sp
	ldr r2, [r2]
	cmp r7, r2
	bge _08046B0A
	b _080469F6
_08046B0A:
	cmp r1, 0
	bne _08046B54
	movs r3, 0xAD
	lsls r3, 3
	add r3, sp
	ldr r3, [r3]
	cmp r3, 0x1
	ble _08046B3C
	ldr r0, _08046B34
	ldr r1, [r0]
	ldr r4, _08046B38
	add r4, sp
	ldr r0, [r4]
	bl sub_80522A8
	b _08046C7C
	.align 2, 0
_08046B2C: .4byte 0x0000052c
_08046B30: .4byte 0x000004b4
_08046B34: .4byte gUnknown_80F945C
_08046B38: .4byte 0x00000524
_08046B3C:
	ldr r0, _08046B4C
	ldr r1, [r0]
	ldr r5, _08046B50
	add r5, sp
	ldr r0, [r5]
	bl sub_80522A8
	b _08046C7C
	.align 2, 0
_08046B4C: .4byte gUnknown_80F943C
_08046B50: .4byte 0x00000524
_08046B54:
	mov r0, r9
	cmp r0, 0
	beq _08046B68
	ldr r0, _08046C90
	ldr r1, [r0]
	ldr r2, _08046C94
	add r2, sp
	ldr r0, [r2]
	bl sub_80522A8
_08046B68:
	movs r3, 0
	mov r9, r3
	ldr r0, _08046C98
	ldr r0, [r0]
	ldr r4, _08046C9C
	adds r0, r4
	ldrb r0, [r0]
	movs r5, 0xA6
	lsls r5, 3
	add r5, sp
	str r0, [r5]
	mov r10, r3
	movs r6, 0
_08046B82:
	movs r7, 0
	mov r0, r10
	adds r0, 0x55
	movs r1, 0xA7
	lsls r1, 3
	add r1, sp
	str r0, [r1]
	adds r2, r6, 0x1
	ldr r3, _08046CA0
	add r3, sp
	str r2, [r3]
	movs r4, 0xAD
	lsls r4, 3
	add r4, sp
	ldr r4, [r4]
	cmp r7, r4
	bge _08046C14
	mov r5, r9
	lsls r5, 24
	mov r8, r5
_08046BAA:
	movs r0, 0x74
	adds r5, r7, 0
	muls r5, r0
	mov r4, sp
	adds r4, r5
	adds r4, 0x4
	adds r0, r4, 0
	bl sub_80450E0
	lsls r0, 24
	cmp r0, 0
	beq _08046C06
	ldr r0, _08046CA4
	add r0, sp
	lsls r2, r7, 3
	adds r0, r2
	ldr r1, [r0]
	movs r0, 0x97
	lsls r0, 3
	add r0, sp
	adds r0, r2
	ldr r2, [r0]
	adds r0, r4, 0
	bl sub_804539C
	mov r0, r10
	bl sub_8009C7C
	add r2, sp, 0x20
	adds r2, r5
	lsls r1, r0, 1
	adds r1, r0
	lsls r1, 2
	str r1, [r2]
	movs r0, 0
	str r0, [sp]
	adds r0, r4, 0
	movs r2, 0xA6
	lsls r2, 3
	add r2, sp
	ldr r1, [r2]
	movs r2, 0x1
	mov r4, r8
	lsrs r3, r4, 24
	bl sub_80462AC
_08046C06:
	adds r7, 0x1
	movs r5, 0xAD
	lsls r5, 3
	add r5, sp
	ldr r5, [r5]
	cmp r7, r5
	blt _08046BAA
_08046C14:
	movs r0, 0x13
	bl sub_803E46C
	movs r0, 0xA7
	lsls r0, 3
	add r0, sp
	ldr r0, [r0]
	mov r10, r0
	movs r0, 0x3
	ands r0, r6
	cmp r0, 0
	bne _08046C30
	movs r1, 0x1
	add r9, r1
_08046C30:
	movs r0, 0x7
	mov r2, r9
	ands r2, r0
	mov r9, r2
	ldr r3, _08046CA0
	add r3, sp
	ldr r6, [r3]
	cmp r6, 0x17
	ble _08046B82
	movs r4, 0xAD
	lsls r4, 3
	add r4, sp
	ldr r4, [r4]
	cmp r4, 0
	ble _08046C7C
	ldr r0, _08046CA8
	add r0, sp
	ldr r5, [r0]
	ldr r4, _08046CAC
	add r4, sp
	movs r1, 0xAD
	lsls r1, 3
	add r1, sp
	ldr r7, [r1]
_08046C60:
	movs r2, 0
	ldrsh r0, [r4, r2]
	cmp r0, 0
	blt _08046C72
	adds r0, r4, 0
	adds r1, r5, 0
	movs r2, 0x1
	bl sub_80460F8
_08046C72:
	adds r5, 0x4
	adds r4, 0x4
	subs r7, 0x1
	cmp r7, 0
	bne _08046C60
_08046C7C:
	movs r3, 0xA9
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
_08046C90: .4byte gUnknown_80F947C
_08046C94: .4byte 0x00000524
_08046C98: .4byte gUnknown_203B418
_08046C9C: .4byte 0x00018210
_08046CA0: .4byte 0x0000053c
_08046CA4: .4byte 0x000004b4
_08046CA8: .4byte 0x0000052c
_08046CAC: .4byte 0x0000048c
	thumb_func_end sub_804687C

	thumb_func_start sub_8046CB0
sub_8046CB0:
	push {lr}
	lsls r1, 24
	lsrs r1, 24
	ldr r0, [r0, 0x70]
	adds r3, r0, 0
	adds r0, 0x60
	ldrb r2, [r0]
	movs r0, 0x1
	ands r0, r2
	cmp r0, 0
	beq _08046CDC
	movs r0, 0x8
	ands r0, r2
	cmp r0, 0
	bne _08046CDC
	adds r0, r3, 0
	adds r0, 0x62
	ldrb r0, [r0]
	cmp r0, r1
	bne _08046CDC
	movs r0, 0x1
	b _08046CDE
_08046CDC:
	movs r0, 0
_08046CDE:
	pop {r1}
	bx r1
	thumb_func_end sub_8046CB0

	thumb_func_start sub_8046CE4
sub_8046CE4:
	push {r4,r5,lr}
	adds r4, r0, 0
	adds r5, r1, 0
	movs r0, 0x64
	bl sub_8084100
	adds r1, r0, 0
	movs r2, 0
	ldr r3, _08046D04
_08046CF6:
	lsls r0, r1, 2
	adds r0, r3
	ldr r0, [r0]
	cmp r0, r5
	bgt _08046D08
	strb r1, [r4, 0x1]
	b _08046D18
	.align 2, 0
_08046D04: .4byte gUnknown_810A3F0
_08046D08:
	lsrs r0, r1, 31
	adds r0, r1, r0
	asrs r1, r0, 1
	adds r2, 0x1
	cmp r2, 0xC7
	ble _08046CF6
	movs r0, 0x1
	strb r0, [r4, 0x1]
_08046D18:
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_8046CE4

	thumb_func_start sub_8046D20
sub_8046D20:
	push {r4,r5,lr}
	ldr r4, _08046D5C
	ldr r0, [r4]
	ldrb r5, [r0, 0x8]
	bl sub_8046D70
	ldr r1, [r4]
	strb r0, [r1, 0x8]
	ldr r0, [r4]
	ldrb r0, [r0, 0x8]
	cmp r0, 0x1
	bne _08046D64
	cmp r5, 0
	bne _08046D64
	ldr r0, _08046D60
	ldr r1, [r0]
	movs r0, 0
	movs r2, 0x1
	bl sub_8052B8C
	adds r1, r0, 0
	cmp r1, 0x1
	bne _08046D64
	ldr r0, [r4]
	strb r1, [r0, 0x4]
	ldr r1, [r4]
	movs r0, 0x2
	strb r0, [r1, 0x11]
	b _08046D68
	.align 2, 0
_08046D5C: .4byte gUnknown_203B418
_08046D60: .4byte gUnknown_80FA408
_08046D64:
	bl sub_8046D8C
_08046D68:
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_8046D20

	thumb_func_start sub_8046D70
sub_8046D70:
	push {lr}
	ldr r0, _08046D84
	ldr r0, [r0]
	ldr r1, _08046D88
	adds r0, r1
	ldrb r0, [r0]
	movs r0, 0
	pop {r1}
	bx r1
	.align 2, 0
_08046D84: .4byte gUnknown_203B418
_08046D88: .4byte 0x0000068a
	thumb_func_end sub_8046D70

	thumb_func_start sub_8046D8C
sub_8046D8C:
	push {r4-r7,lr}
	sub sp, 0xC
	movs r6, 0
	ldr r5, _08046EDC
	movs r4, 0
_08046D96:
	movs r7, 0
	movs r0, 0x1
	negs r0, r0
	str r0, [sp]
	str r0, [sp, 0x4]
	str r0, [sp, 0x8]
	movs r3, 0
	ldr r2, [r5]
_08046DA6:
	ldrb r1, [r2]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _08046DC8
	ldrb r0, [r2, 0x2]
	cmp r0, 0x79
	bne _08046DB8
	str r3, [sp]
_08046DB8:
	ldrb r0, [r2, 0x2]
	cmp r0, 0x77
	bne _08046DC0
	str r3, [sp, 0x4]
_08046DC0:
	ldrb r0, [r2, 0x2]
	cmp r0, 0x78
	bne _08046DC8
	str r3, [sp, 0x8]
_08046DC8:
	adds r2, 0x4
	adds r3, 0x1
	cmp r3, 0x13
	ble _08046DA6
	ldr r1, [sp]
	cmp r1, 0
	blt _08046E1E
	ldr r0, [sp, 0x4]
	cmp r0, 0
	blt _08046E1E
	ldr r0, [sp, 0x8]
	cmp r0, 0
	blt _08046E1E
	movs r7, 0x1
	movs r6, 0x1
	lsls r1, 2
	ldr r0, [r5]
	adds r1, r0
	strb r4, [r1, 0x2]
	strb r4, [r1, 0x1]
	strb r4, [r1]
	ldr r0, [sp, 0x4]
	lsls r0, 2
	ldr r1, [r5]
	adds r0, r1
	strb r4, [r0, 0x2]
	strb r4, [r0, 0x1]
	strb r4, [r0]
	ldr r0, [sp, 0x8]
	lsls r0, 2
	ldr r1, [r5]
	adds r0, r1
	strb r4, [r0, 0x2]
	strb r4, [r0, 0x1]
	strb r4, [r0]
	ldr r1, [sp]
	lsls r1, 2
	ldr r0, [r5]
	adds r0, r1
	movs r1, 0x7A
	movs r2, 0
	bl sub_8090A8C
_08046E1E:
	cmp r7, 0
	bne _08046D96
	bl sub_80910B4
	cmp r6, 0
	beq _08046ED4
	bl sub_8083600
	adds r4, r0, 0
	ldr r0, _08046EE0
	bl sub_80855E4
	ldr r6, _08046EE4
	ldr r0, [r6]
	ldr r5, _08046EE8
	adds r0, r5
	movs r1, 0x1
	strb r1, [r0]
	ldr r0, _08046EEC
	ldr r1, [r0]
	movs r0, 0
	movs r2, 0x1
	bl PrintFieldMessage
	movs r0, 0x3C
	movs r1, 0x41
	bl sub_803E708
	ldr r0, _08046EF0
	ldr r1, [r0]
	movs r0, 0
	movs r2, 0x1
	bl PrintFieldMessage
	adds r0, r4, 0
	movs r1, 0x4
	movs r2, 0xA
	movs r3, 0
	bl sub_80869E4
	adds r0, r4, 0
	adds r0, 0xC
	movs r1, 0x86
	lsls r1, 1
	movs r2, 0
	bl sub_80416E0
	adds r0, r4, 0
	movs r1, 0xD7
	bl sub_80421C0
	movs r0, 0x3C
	movs r1, 0x41
	bl sub_803E708
	ldr r0, _08046EF4
	adds r1, r4, 0
	movs r2, 0
	bl sub_8045B94
	ldr r0, _08046EF8
	ldr r1, [r0]
	movs r0, 0
	movs r2, 0x1
	bl PrintFieldMessage
	movs r0, 0xA
	movs r1, 0x41
	bl sub_803E708
	movs r0, 0xD4
	bl sub_8083E38
	ldr r0, _08046EFC
	ldr r1, [r0]
	movs r0, 0
	movs r2, 0x1
	bl PrintFieldMessage
	movs r0, 0xA
	movs r1, 0x41
	bl sub_803E708
	movs r0, 0x1
	bl sub_804178C
	ldr r0, [r6]
	adds r0, r5
	strb r7, [r0]
	bl sub_8040A84
_08046ED4:
	add sp, 0xC
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_08046EDC: .4byte gUnknown_203B460
_08046EE0: .4byte sub_80861A8
_08046EE4: .4byte gUnknown_203B418
_08046EE8: .4byte 0x0001356c
_08046EEC: .4byte gUnknown_810531C
_08046EF0: .4byte gUnknown_8105360
_08046EF4: .4byte gUnknown_202DF98
_08046EF8: .4byte gUnknown_81053A8
_08046EFC: .4byte gUnknown_8105434
	thumb_func_end sub_8046D8C

	thumb_func_start sub_8046F00
sub_8046F00:
	push {r4-r7,lr}
	adds r4, r0, 0
	ldrb r0, [r4, 0x2]
	bl sub_8090BD0
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x5
	bne _08046F7C
	ldrb r0, [r4, 0x2]
	bl sub_80913CC
	lsls r0, 16
	lsrs r7, r0, 16
	ldrb r0, [r4, 0x2]
	bl sub_80915A0
	lsls r0, 24
	cmp r0, 0
	bne _08046F6E
	movs r6, 0
_08046F2A:
	ldr r0, _08046F74
	ldr r0, [r0]
	lsls r1, r6, 2
	ldr r2, _08046F78
	adds r0, r2
	adds r0, r1
	ldr r4, [r0]
	adds r0, r4, 0
	bl sub_80450E0
	lsls r0, 24
	cmp r0, 0
	beq _08046F68
	ldr r0, [r4, 0x70]
	movs r2, 0x2
	ldrsh r1, [r0, r2]
	adds r0, r7, 0
	bl sub_808E190
	lsls r0, 24
	lsrs r5, r0, 24
	adds r0, r4, 0
	movs r1, 0
	bl sub_8070B6C
	lsls r0, 24
	cmp r0, 0
	beq _08046F64
	movs r5, 0
_08046F64:
	cmp r5, 0
	bne _08046F7C
_08046F68:
	adds r6, 0x1
	cmp r6, 0x3
	ble _08046F2A
_08046F6E:
	movs r0, 0
	b _08046F7E
	.align 2, 0
_08046F74: .4byte gUnknown_203B418
_08046F78: .4byte 0x0001357c
_08046F7C:
	movs r0, 0x1
_08046F7E:
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_8046F00

	thumb_func_start sub_8046F84
sub_8046F84:
	push {r4-r7,lr}
	adds r7, r0, 0
	movs r5, 0
	ldr r4, _08047000
	movs r6, 0x1
	movs r3, 0
_08046F90:
	lsls r1, r5, 2
	ldr r0, [r4]
	adds r2, r0, r1
	ldrb r1, [r2]
	adds r0, r6, 0
	ands r0, r1
	cmp r0, 0
	beq _08046FAE
	ldrb r0, [r2]
	ands r0, r7
	cmp r0, 0
	beq _08046FAE
	strb r3, [r2, 0x2]
	strb r3, [r2, 0x1]
	strb r3, [r2]
_08046FAE:
	adds r5, 0x1
	cmp r5, 0x13
	ble _08046F90
	bl sub_80910B4
	movs r5, 0
	movs r6, 0
_08046FBC:
	ldr r0, _08047004
	ldr r0, [r0]
	lsls r1, r5, 2
	ldr r2, _08047008
	adds r0, r2
	adds r0, r1
	ldr r4, [r0]
	adds r0, r4, 0
	bl sub_80450E0
	lsls r0, 24
	cmp r0, 0
	beq _08046FF4
	ldr r0, [r4, 0x70]
	adds r2, r0, 0
	adds r2, 0x60
	ldrb r1, [r2]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _08046FF4
	ldrb r0, [r2]
	ands r0, r7
	cmp r0, 0
	beq _08046FF4
	strb r6, [r2, 0x2]
	strb r6, [r2, 0x1]
	strb r6, [r2]
_08046FF4:
	adds r5, 0x1
	cmp r5, 0x3
	ble _08046FBC
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_08047000: .4byte gUnknown_203B460
_08047004: .4byte gUnknown_203B418
_08047008: .4byte 0x0001357c
	thumb_func_end sub_8046F84

	thumb_func_start sub_804700C
sub_804700C:
	push {r4,r5,lr}
	movs r5, 0
	ldr r4, _08047078
_08047012:
	lsls r1, r5, 2
	ldr r0, [r4]
	adds r2, r0, r1
	ldrb r1, [r2]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _0804702C
	adds r0, r2, 0
	movs r1, 0x46
	movs r2, 0
	bl sub_8090A8C
_0804702C:
	adds r5, 0x1
	cmp r5, 0x13
	ble _08047012
	bl sub_80910B4
	movs r5, 0
_08047038:
	ldr r0, _0804707C
	ldr r0, [r0]
	lsls r1, r5, 2
	ldr r2, _08047080
	adds r0, r2
	adds r0, r1
	ldr r4, [r0]
	adds r0, r4, 0
	bl sub_80450E0
	lsls r0, 24
	cmp r0, 0
	beq _0804706C
	ldr r0, [r4, 0x70]
	adds r2, r0, 0
	adds r2, 0x60
	ldrb r1, [r2]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _0804706C
	adds r0, r2, 0
	movs r1, 0x46
	movs r2, 0
	bl sub_8090A8C
_0804706C:
	adds r5, 0x1
	cmp r5, 0x3
	ble _08047038
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_08047078: .4byte gUnknown_203B460
_0804707C: .4byte gUnknown_203B418
_08047080: .4byte 0x0001357c
	thumb_func_end sub_804700C

	thumb_func_start sub_8047084
sub_8047084:
	push {r4-r6,lr}
	adds r6, r0, 0
	movs r5, 0
	ldr r0, _080470E8
	ldr r2, [r0]
	movs r3, 0x1
_08047090:
	ldrb r1, [r2]
	adds r0, r3, 0
	ands r0, r1
	cmp r0, 0
	beq _080470A2
	ldrb r0, [r2]
	ands r0, r6
	cmp r0, 0
	bne _080470E2
_080470A2:
	adds r2, 0x4
	adds r5, 0x1
	cmp r5, 0x13
	ble _08047090
	bl sub_80910B4
	movs r5, 0
_080470B0:
	ldr r0, _080470EC
	ldr r0, [r0]
	lsls r1, r5, 2
	ldr r2, _080470F0
	adds r0, r2
	adds r0, r1
	ldr r4, [r0]
	adds r0, r4, 0
	bl sub_80450E0
	lsls r0, 24
	cmp r0, 0
	beq _080470F4
	ldr r0, [r4, 0x70]
	adds r2, r0, 0
	adds r2, 0x60
	ldrb r1, [r2]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _080470F4
	ldrb r0, [r2]
	ands r0, r6
	cmp r0, 0
	beq _080470F4
_080470E2:
	movs r0, 0x1
	b _080470FC
	.align 2, 0
_080470E8: .4byte gUnknown_203B460
_080470EC: .4byte gUnknown_203B418
_080470F0: .4byte 0x0001357c
_080470F4:
	adds r5, 0x1
	cmp r5, 0x3
	ble _080470B0
	movs r0, 0
_080470FC:
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end sub_8047084

	thumb_func_start sub_8047104
sub_8047104:
	push {r4-r6,lr}
	movs r6, 0
	movs r5, 0
_0804710A:
	ldr r0, _08047154
	lsls r1, r6, 2
	ldr r0, [r0]
	adds r4, r0, r1
	ldrb r1, [r4]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _08047142
	ldrb r0, [r4, 0x2]
	cmp r0, 0x69
	bne _08047132
	adds r0, r4, 0
	bl sub_80915D4
	bl sub_80913A0
	strb r5, [r4, 0x2]
	strb r5, [r4, 0x1]
	strb r5, [r4]
_08047132:
	ldrb r1, [r4]
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	beq _08047142
	strb r5, [r4, 0x2]
	strb r5, [r4, 0x1]
	strb r5, [r4]
_08047142:
	adds r6, 0x1
	cmp r6, 0x13
	ble _0804710A
	bl sub_80910B4
	pop {r4-r6}
	pop {r0}
	bx r0
	.align 2, 0
_08047154: .4byte gUnknown_203B460
	thumb_func_end sub_8047104

	thumb_func_start sub_8047158
sub_8047158:
	push {r4-r6,lr}
	movs r3, 0
	ldr r5, _0804718C
	movs r6, 0x1
	movs r4, 0x4
_08047162:
	lsls r1, r3, 2
	ldr r0, [r5]
	adds r2, r0, r1
	ldrb r1, [r2]
	adds r0, r6, 0
	ands r0, r1
	cmp r0, 0
	beq _08047180
	adds r0, r4, 0
	ands r0, r1
	cmp r0, 0
	beq _08047180
	movs r0, 0xFB
	ands r0, r1
	strb r0, [r2]
_08047180:
	adds r3, 0x1
	cmp r3, 0x13
	ble _08047162
	pop {r4-r6}
	pop {r0}
	bx r0
	.align 2, 0
_0804718C: .4byte gUnknown_203B460
	thumb_func_end sub_8047158

	thumb_func_start sub_8047190
sub_8047190:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	ldr r4, _080472E8
	add sp, r4
	mov r9, r0
	str r1, [sp, 0x214]
	ldr r6, _080472EC
	ldr r1, [r6]
	ldr r4, _080472F0
	adds r0, r1, r4
	ldrb r0, [r0]
	str r0, [sp, 0x220]
	mov r8, r3
	adds r7, r1, 0
	adds r7, 0xC0
	movs r0, 0x3
	str r0, [r7]
	adds r0, r1, 0
	adds r0, 0xE4
	movs r4, 0
	strb r4, [r0]
	subs r0, 0x4
	movs r5, 0x1
	strb r5, [r0]
	adds r0, 0x2
	strb r4, [r0]
	ldr r0, [sp, 0x214]
	str r0, [r7, 0x70]
	str r4, [r7, 0x1C]
	ldr r0, [r2]
	str r0, [r7, 0x4]
	movs r1, 0
	ldrsh r0, [r2, r1]
	lsls r1, r0, 1
	adds r1, r0
	lsls r1, 3
	adds r1, 0x4
	lsls r1, 8
	movs r3, 0x2
	ldrsh r0, [r2, r3]
	lsls r2, r0, 1
	adds r2, r0
	lsls r2, 11
	adds r0, r7, 0
	bl sub_8045394
	strh r4, [r7, 0x26]
	str r4, [sp, 0x224]
	mov r0, r9
	bl sub_80450F8
	cmp r0, 0x1
	bne _08047214
	mov r0, r9
	movs r1, 0x2A
	bl sub_8046CB0
	lsls r0, 24
	lsrs r0, 24
	negs r1, r0
	orrs r1, r0
	lsrs r1, 31
	str r1, [sp, 0x224]
_08047214:
	ldr r0, [sp, 0x260]
	movs r1, 0x2
	ldrsh r0, [r0, r1]
	str r0, [sp, 0x218]
	movs r2, 0
	str r2, [sp, 0x21C]
	ldr r0, [r6]
	ldr r3, _080472F4
	adds r0, r3
	strb r5, [r0]
_08047228:
	ldr r4, [r7, 0x4]
	mov r10, r4
	ldr r1, [sp, 0x260]
	ldrb r0, [r1, 0x1]
	cmp r0, 0
	beq _080472AE
	ldrb r0, [r1]
	cmp r0, 0
	bne _080472AE
	movs r2, 0x4
	ldrsh r0, [r7, r2]
	ldr r2, _080472F8
	mov r3, r8
	lsls r4, r3, 2
	adds r2, r4, r2
	movs r3, 0
	ldrsh r1, [r2, r3]
	adds r0, r1
	movs r3, 0x6
	ldrsh r1, [r7, r3]
	movs r3, 0x2
	ldrsh r2, [r2, r3]
	adds r1, r2
	bl sub_804954C
	adds r5, r0, 0
	ldrh r1, [r5]
	movs r0, 0x3
	ands r0, r1
	str r4, [sp, 0x230]
	cmp r0, 0
	bne _080472AE
	movs r6, 0
	ldr r1, _080472FC
	mov r4, r10
	lsls r0, r4, 16
	asrs r0, 16
	str r0, [sp, 0x23C]
	ldr r0, [sp, 0x230]
	adds r5, r0, r1
	asrs r2, r4, 16
_0804727A:
	ldrb r4, [r5]
	cmp r4, 0x7
	bgt _080472A6
	ldr r0, _080472F8
	lsls r1, r4, 2
	adds r1, r0
	movs r3, 0
	ldrsh r0, [r1, r3]
	ldr r3, [sp, 0x23C]
	adds r0, r3
	movs r3, 0x2
	ldrsh r1, [r1, r3]
	adds r1, r2
	str r2, [sp, 0x234]
	bl sub_804954C
	ldrh r1, [r0]
	movs r0, 0x3
	ands r0, r1
	ldr r2, [sp, 0x234]
	cmp r0, 0
	bne _08047300
_080472A6:
	adds r5, 0x1
	adds r6, 0x1
	cmp r6, 0x3
	ble _0804727A
_080472AE:
	ldr r0, _080472F8
	mov r4, r8
	lsls r2, r4, 2
	adds r3, r2, r0
	ldrh r1, [r3]
	ldrh r0, [r7, 0x4]
	adds r1, r0
	strh r1, [r7, 0x4]
	ldrh r0, [r3, 0x2]
	ldrh r4, [r7, 0x6]
	adds r0, r4
	strh r0, [r7, 0x6]
	lsls r1, 16
	asrs r1, 16
	str r2, [sp, 0x230]
	cmp r1, 0
	blt _080472E0
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0
	blt _080472E0
	cmp r1, 0x37
	bgt _080472E0
	cmp r0, 0x1F
	ble _08047304
_080472E0:
	movs r0, 0x2
	mov r10, r0
	b _0804744C
	.align 2, 0
_080472E8: .4byte 0xfffffdc0
_080472EC: .4byte gUnknown_203B418
_080472F0: .4byte 0x00018210
_080472F4: .4byte 0x0001c05e
_080472F8: .4byte gUnknown_80F4448
_080472FC: .4byte gUnknown_80F4D64
_08047300:
	mov r8, r4
	b _080472AE
_08047304:
	movs r1, 0
	ldrsh r0, [r3, r1]
	lsls r0, 10
	str r0, [sp, 0x228]
	movs r2, 0x2
	ldrsh r0, [r3, r2]
	lsls r0, 10
	str r0, [sp, 0x22C]
	mov r3, r8
	lsls r6, r3, 24
	movs r5, 0x5
_0804731A:
	movs r4, 0
	adds r0, r7, 0
	ldr r1, [sp, 0x228]
	ldr r2, [sp, 0x22C]
	bl sub_804539C
	bl sub_804AF74
	lsls r0, 24
	movs r2, 0
	cmp r0, 0
	beq _08047334
	movs r2, 0x3
_08047334:
	ldr r0, [r7, 0xC]
	cmp r0, 0
	bge _0804733C
	adds r0, 0xFF
_0804733C:
	asrs r0, 8
	adds r0, 0x8
	ldr r1, [r7, 0x10]
	cmp r1, 0
	bge _08047348
	adds r1, 0xFF
_08047348:
	asrs r1, 8
	adds r1, 0x10
	bl sub_8083568
	lsls r0, 24
	cmp r0, 0
	beq _08047358
	movs r4, 0x1
_08047358:
	movs r0, 0x1
	str r0, [sp]
	adds r0, r7, 0
	ldr r1, [sp, 0x220]
	movs r2, 0
	lsrs r3, r6, 24
	bl sub_80462AC
	lsls r0, 24
	cmp r0, 0
	beq _08047370
	movs r4, 0x1
_08047370:
	cmp r4, 0
	beq _0804737A
	movs r0, 0x12
	bl sub_803E46C
_0804737A:
	subs r5, 0x1
	cmp r5, 0
	bge _0804731A
	movs r4, 0x4
	ldrsh r0, [r7, r4]
	movs r2, 0x6
	ldrsh r1, [r7, r2]
	bl sub_804954C
	adds r5, r0, 0
	ldrh r1, [r5]
	movs r0, 0x3
	ands r0, r1
	cmp r0, 0
	bne _080473A2
	ldr r3, [sp, 0x260]
	ldrb r0, [r3]
	cmp r0, 0
	bne _080473A2
	b _0804757A
_080473A2:
	ldr r1, [r5, 0x10]
	cmp r1, 0
	beq _08047436
	movs r4, 0
	ldr r2, [sp, 0x260]
	ldrb r0, [r2]
	cmp r0, 0
	bne _080473CE
	adds r0, r1, 0
	bl sub_80450F8
	cmp r0, 0x1
	bne _080473CE
	ldr r0, [r5, 0x10]
	movs r1, 0x26
	bl sub_8046CB0
	lsls r0, 24
	lsrs r0, 24
	negs r1, r0
	orrs r1, r0
	lsrs r4, r1, 31
_080473CE:
	cmp r4, 0
	beq _080473E0
	movs r3, 0x4
	add r8, r3
	movs r0, 0x7
	mov r4, r8
	ands r4, r0
	mov r8, r4
	b _08047436
_080473E0:
	movs r6, 0x1
	ldr r0, [r5, 0x10]
	bl sub_80450F8
	cmp r0, 0x1
	bne _08047406
	add r4, sp, 0x208
	adds r0, r4, 0
	ldr r1, _080474B8
	bl sub_8092A88
	ldr r0, [r5, 0x10]
	adds r1, r4, 0
	bl sub_80571F0
	lsls r0, 24
	cmp r0, 0
	beq _08047406
	movs r6, 0
_08047406:
	cmp r6, 0
	beq _08047436
	ldr r0, [sp, 0x21C]
	cmp r0, 0x3F
	bgt _0804742C
	lsls r0, 3
	mov r4, sp
	adds r4, r0
	adds r4, 0x8
	ldr r0, [r5, 0x10]
	str r0, [r4]
	ldr r1, [r5, 0x10]
	mov r0, r9
	bl sub_8047930
	strb r0, [r4, 0x4]
	ldr r1, [sp, 0x21C]
	adds r1, 0x1
	str r1, [sp, 0x21C]
_0804742C:
	ldr r2, [sp, 0x260]
	ldrb r0, [r2]
	cmp r0, 0
	bne _08047436
	b _08047574
_08047436:
	ldr r3, [sp, 0x218]
	subs r3, 0x1
	str r3, [sp, 0x218]
	cmp r3, 0
	ble _08047442
	b _08047228
_08047442:
	movs r4, 0x1
	mov r10, r4
	mov r0, r8
	lsls r0, 2
	str r0, [sp, 0x230]
_0804744C:
	ldr r0, _080474BC
	ldr r0, [r0]
	ldr r1, _080474C0
	adds r0, r1
	movs r1, 0
	strb r1, [r0]
	ldr r2, [sp, 0x21C]
	cmp r2, 0
	ble _0804752C
	add r5, sp, 0x8
	adds r6, r2, 0
_08047462:
	ldr r4, [r5]
	ldrb r0, [r5, 0x4]
	cmp r0, 0
	beq _080474D0
	ldr r0, _080474C4
	adds r1, r4, 0
	movs r2, 0
	bl sub_8045B94
	ldr r0, _080474C8
	ldr r1, [sp, 0x214]
	bl sub_8045C08
	ldr r0, _080474CC
	ldr r2, [r0]
	mov r0, r9
	adds r1, r4, 0
	bl sub_80522F4
	mov r0, r9
	adds r1, r4, 0
	bl sub_807A96C
	lsls r0, 24
	lsrs r2, r0, 24
	movs r1, 0
	ldr r3, [sp, 0x224]
	cmp r3, 0
	bne _080474A4
	ldr r3, [sp, 0x260]
	ldrb r0, [r3]
	cmp r0, 0
	beq _080474A6
_080474A4:
	movs r1, 0x1
_080474A6:
	str r4, [sp]
	ldr r4, [sp, 0x214]
	str r4, [sp, 0x4]
	movs r0, 0x1
	mov r3, r9
	bl sub_80479B8
	b _08047524
	.align 2, 0
_080474B8: .4byte 0x00000195
_080474BC: .4byte gUnknown_203B418
_080474C0: .4byte 0x0001c05e
_080474C4: .4byte gUnknown_202DF98
_080474C8: .4byte gUnknown_202DE58
_080474CC: .4byte gUnknown_80F94C4
_080474D0:
	ldr r1, [sp, 0x260]
	ldrb r0, [r1]
	cmp r0, 0
	bne _080474E2
	ldr r2, [sp, 0x21C]
	cmp r2, 0x1
	bne _080474E2
	movs r3, 0x1
	mov r10, r3
_080474E2:
	ldr r0, _0804750C
	adds r1, r4, 0
	movs r2, 0
	bl sub_8045B94
	ldr r0, _08047510
	ldr r1, [sp, 0x214]
	bl sub_8045BF8
	ldr r1, [sp, 0x260]
	ldrb r0, [r1]
	cmp r0, 0
	beq _08047518
	ldr r0, _08047514
	ldr r2, [r0]
	mov r0, r9
	adds r1, r4, 0
	bl sub_80522F4
	b _08047524
	.align 2, 0
_0804750C: .4byte gUnknown_202DF98
_08047510: .4byte gUnknown_202DE58
_08047514: .4byte gUnknown_80F94D8
_08047518:
	ldr r0, _08047564
	ldr r2, [r0]
	mov r0, r9
	adds r1, r4, 0
	bl sub_80522F4
_08047524:
	adds r5, 0x8
	subs r6, 0x1
	cmp r6, 0
	bne _08047462
_0804752C:
	ldr r2, _08047568
	ldr r3, [sp, 0x230]
	adds r2, r3, r2
	movs r4, 0
	ldrsh r1, [r2, r4]
	lsls r1, 19
	lsrs r1, 16
	ldr r4, _0804756C
	add r3, sp, 0x210
	ldr r0, [r3]
	ands r0, r4
	orrs r0, r1
	str r0, [r3]
	movs r4, 0x2
	ldrsh r1, [r2, r4]
	lsls r1, 19
	ldr r2, _08047570
	ands r0, r2
	orrs r0, r1
	str r0, [r3]
	mov r0, r10
	cmp r0, 0x1
	beq _08047584
	cmp r0, 0x1
	bcc _080475A8
	cmp r0, 0x2
	beq _08047596
	b _080475A8
	.align 2, 0
_08047564: .4byte gUnknown_80F94F0
_08047568: .4byte gUnknown_80F4448
_0804756C: .4byte 0xffff0000
_08047570: .4byte 0x0000ffff
_08047574:
	movs r1, 0
	mov r10, r1
	b _0804744C
_0804757A:
	mov r2, r10
	str r2, [r7, 0x4]
	movs r3, 0x1
	mov r10, r3
	b _0804744C
_08047584:
	add r0, sp, 0x210
	str r0, [sp]
	mov r0, r9
	adds r1, r7, 0
	ldr r2, [sp, 0x214]
	movs r3, 0x1
	bl sub_804652C
	b _080475A8
_08047596:
	ldr r0, _080475BC
	ldr r1, [sp, 0x214]
	bl sub_8045C08
	ldr r0, _080475C0
	ldr r1, [r0]
	mov r0, r9
	bl sub_80522A8
_080475A8:
	movs r3, 0x90
	lsls r3, 2
	add sp, r3
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_080475BC: .4byte gUnknown_202DE58
_080475C0: .4byte gUnknown_80F9530
	thumb_func_end sub_8047190

	thumb_func_start sub_80475C4
sub_80475C4:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x44
	str r0, [sp, 0x10]
	str r1, [sp, 0x14]
	adds r7, r2, 0
	str r3, [sp, 0x18]
	ldr r0, _08047848
	mov r8, r0
	ldr r2, [r0]
	ldr r1, _0804784C
	adds r0, r2, r1
	ldrb r0, [r0]
	str r0, [sp, 0x24]
	movs r4, 0
	movs r5, 0
	adds r3, r2, 0
	adds r3, 0xC0
	str r3, [sp, 0x1C]
	movs r0, 0x3
	str r0, [r3]
	adds r0, r2, 0
	adds r0, 0xE4
	strb r4, [r0]
	adds r1, r2, 0
	adds r1, 0xE0
	movs r0, 0x1
	strb r0, [r1]
	adds r0, r2, 0
	adds r0, 0xE2
	strb r4, [r0]
	ldr r0, [sp, 0x14]
	str r0, [r3, 0x70]
	str r5, [r3, 0x1C]
	ldr r0, [r7]
	str r0, [r3, 0x4]
	movs r1, 0
	ldrsh r0, [r7, r1]
	lsls r1, r0, 1
	adds r1, r0
	lsls r1, 3
	adds r1, 0x4
	lsls r1, 8
	movs r2, 0x2
	ldrsh r0, [r7, r2]
	lsls r2, r0, 1
	adds r2, r0
	lsls r2, 3
	adds r2, 0x4
	lsls r2, 8
	ldr r0, [sp, 0x1C]
	bl sub_8045394
	ldr r3, [sp, 0x1C]
	strh r4, [r3, 0x26]
	movs r0, 0x1
	str r0, [sp, 0x20]
	movs r1, 0
	str r1, [sp, 0x28]
	ldr r0, [sp, 0x10]
	bl sub_80450F8
	cmp r0, 0x1
	bne _0804765E
	ldr r0, [sp, 0x10]
	movs r1, 0x2A
	bl sub_8046CB0
	lsls r0, 24
	lsrs r0, 24
	negs r1, r0
	orrs r1, r0
	lsrs r1, 31
	str r1, [sp, 0x28]
_0804765E:
	adds r0, r7, 0
	bl sub_803F428
	lsls r0, 24
	lsrs r0, 24
	negs r1, r0
	orrs r1, r0
	lsrs r4, r1, 31
	ldr r0, [sp, 0x18]
	bl sub_803F428
	lsls r0, 24
	cmp r0, 0
	beq _0804767C
	movs r4, 0x1
_0804767C:
	mov r2, r8
	ldr r0, [r2]
	ldr r3, _08047850
	adds r0, r3
	add r1, sp, 0x20
	ldrb r1, [r1]
	strb r1, [r0]
	cmp r4, 0
	bne _08047690
	b _080477D0
_08047690:
	ldr r2, [sp, 0x1C]
	movs r3, 0x4
	ldrsh r0, [r2, r3]
	ldr r1, [sp, 0x18]
	movs r2, 0
	ldrsh r1, [r1, r2]
	mov r9, r1
	subs r1, r0, r1
	cmp r1, 0
	bge _080476A6
	negs r1, r1
_080476A6:
	ldr r3, [sp, 0x1C]
	movs r2, 0x6
	ldrsh r0, [r3, r2]
	ldr r3, [sp, 0x18]
	movs r2, 0x2
	ldrsh r3, [r3, r2]
	mov r10, r3
	subs r0, r3
	cmp r0, 0
	bge _080476BC
	negs r0, r0
_080476BC:
	adds r1, r0
	lsls r0, r1, 1
	adds r0, r1
	lsls r4, r0, 2
	adds r3, r4, 0
	adds r3, 0xC
	str r3, [sp, 0x30]
	cmp r3, 0x3F
	ble _080476D2
	movs r0, 0x40
	str r0, [sp, 0x30]
_080476D2:
	movs r1, 0
	str r1, [sp, 0x3C]
	movs r0, 0x80
	lsls r0, 12
	adds r1, r4, 0
	bl __divsi3
	str r0, [sp, 0x40]
	movs r2, 0
	ldrsh r1, [r7, r2]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 11
	mov r8, r0
	movs r3, 0x2
	ldrsh r1, [r7, r3]
	lsls r0, r1, 1
	adds r0, r1
	lsls r7, r0, 11
	mov r1, r9
	lsls r0, r1, 1
	add r0, r9
	lsls r0, 11
	mov r2, r8
	subs r0, r2
	adds r1, r4, 0
	bl __divsi3
	str r0, [sp, 0x34]
	mov r3, r10
	lsls r0, r3, 1
	add r0, r10
	lsls r0, 11
	subs r0, r7
	adds r1, r4, 0
	bl __divsi3
	str r0, [sp, 0x38]
	subs r0, r4, 0x3
	cmp r0, 0
	ble _080477D0
	str r0, [sp, 0x2C]
_08047726:
	movs r0, 0
	mov r10, r0
	ldr r0, [sp, 0x3C]
	cmp r0, 0
	bge _08047732
	adds r0, 0xFF
_08047732:
	asrs r0, 8
	bl sub_8009C7C
	ldr r2, [sp, 0x30]
	adds r1, r0, 0
	muls r1, r2
	movs r0, 0x80
	lsls r0, 3
	mov r2, r8
	adds r3, r2, r0
	adds r2, r7, r0
	ldr r0, [sp, 0x1C]
	str r1, [r0, 0x1C]
	mov r0, r8
	cmp r0, 0
	bge _08047754
	adds r0, 0xFF
_08047754:
	asrs r0, 8
	adds r0, 0x8
	mov r9, r0
	adds r0, r7, 0
	cmp r7, 0
	bge _08047762
	adds r0, 0xFF
_08047762:
	asrs r0, 8
	adds r4, r0, 0
	adds r4, 0x10
	ldr r1, [sp, 0x3C]
	ldr r0, [sp, 0x40]
	adds r1, r0
	str r1, [sp, 0x3C]
	ldr r0, [sp, 0x1C]
	adds r1, r3, 0
	bl sub_8045394
	bl sub_804AF74
	lsls r0, 24
	movs r2, 0
	cmp r0, 0
	beq _08047786
	movs r2, 0x3
_08047786:
	mov r0, r9
	adds r1, r4, 0
	bl sub_8083568
	lsls r0, 24
	cmp r0, 0
	beq _08047798
	movs r1, 0x1
	mov r10, r1
_08047798:
	movs r0, 0x1
	str r0, [sp]
	ldr r0, [sp, 0x1C]
	ldr r1, [sp, 0x24]
	movs r2, 0
	movs r3, 0xFF
	bl sub_80462AC
	lsls r0, 24
	cmp r0, 0
	beq _080477B2
	movs r2, 0x1
	mov r10, r2
_080477B2:
	mov r3, r10
	cmp r3, 0
	beq _080477BE
	movs r0, 0x17
	bl sub_803E46C
_080477BE:
	ldr r0, [sp, 0x34]
	add r8, r0
	ldr r1, [sp, 0x38]
	adds r7, r1
	ldr r2, [sp, 0x2C]
	subs r2, 0x1
	str r2, [sp, 0x2C]
	cmp r2, 0
	bne _08047726
_080477D0:
	ldr r3, [sp, 0x18]
	ldr r0, [r3]
	ldr r1, [sp, 0x1C]
	str r0, [r1, 0x4]
	ldr r0, _08047848
	ldr r0, [r0]
	ldr r2, _08047850
	adds r0, r2
	movs r1, 0
	strb r1, [r0]
	movs r1, 0
	ldrsh r0, [r3, r1]
	movs r2, 0x2
	ldrsh r1, [r3, r2]
	bl sub_804954C
	adds r4, r0, 0
	ldr r0, [r4, 0x10]
	cmp r0, 0
	bne _080477FA
	b _08047904
_080477FA:
	movs r3, 0x1
	mov r8, r3
	movs r7, 0
	bl sub_80450F8
	cmp r0, 0x1
	bne _08047834
	ldr r0, [r4, 0x10]
	movs r1, 0x26
	bl sub_8046CB0
	lsls r0, 24
	lsrs r0, 24
	negs r1, r0
	orrs r1, r0
	lsrs r7, r1, 31
	ldr r1, _08047854
	add r0, sp, 0x8
	bl sub_8092A88
	ldr r0, [r4, 0x10]
	add r1, sp, 0x8
	bl sub_80571F0
	lsls r0, 24
	cmp r0, 0
	beq _08047834
	movs r0, 0
	mov r8, r0
_08047834:
	mov r1, r8
	cmp r1, 0
	beq _08047904
	ldr r1, [r4, 0x10]
	adds r5, r1, 0
	cmp r7, 0
	beq _0804785C
	ldr r0, _08047858
	ands r6, r0
	b _0804786E
	.align 2, 0
_08047848: .4byte gUnknown_203B418
_0804784C: .4byte 0x00018210
_08047850: .4byte 0x0001c05e
_08047854: .4byte 0x00000195
_08047858: .4byte 0xffffff00
_0804785C:
	ldr r0, [sp, 0x10]
	bl sub_8047930
	lsls r0, 24
	lsrs r0, 24
	ldr r1, _080478CC
	ands r1, r6
	adds r6, r1, 0
	orrs r6, r0
_0804786E:
	ldr r0, _080478D0
	ldr r1, [sp, 0x14]
	bl sub_8045C08
	ldr r0, _080478D4
	adds r1, r5, 0
	movs r2, 0
	bl sub_8045B94
	lsls r0, r6, 24
	cmp r0, 0
	beq _080478DC
	adds r0, r5, 0
	movs r1, 0x8
	bl sub_806CE94
	ldr r0, _080478D8
	ldr r2, [r0]
	ldr r0, [sp, 0x10]
	adds r1, r5, 0
	bl sub_80522F4
	ldr r0, [sp, 0x10]
	adds r1, r5, 0
	bl sub_807A96C
	lsls r0, 24
	lsrs r2, r0, 24
	movs r1, 0
	ldr r3, [sp, 0x28]
	cmp r3, 0
	bne _080478B6
	ldr r0, [sp, 0x64]
	ldrb r0, [r0]
	cmp r0, 0
	beq _080478B8
_080478B6:
	movs r1, 0x1
_080478B8:
	str r5, [sp]
	ldr r0, [sp, 0x14]
	str r0, [sp, 0x4]
	movs r0, 0x1
	ldr r3, [sp, 0x10]
	bl sub_80479B8
	movs r1, 0
	str r1, [sp, 0x20]
	b _08047904
	.align 2, 0
_080478CC: .4byte 0xffffff00
_080478D0: .4byte gUnknown_202DE58
_080478D4: .4byte gUnknown_202DF98
_080478D8: .4byte gUnknown_80F94C4
_080478DC:
	cmp r7, 0
	beq _080478F4
	ldr r0, _080478F0
	ldr r2, [r0]
	ldr r0, [sp, 0x10]
	adds r1, r5, 0
	bl sub_80522F4
	b _08047900
	.align 2, 0
_080478F0: .4byte gUnknown_80F9510
_080478F4:
	ldr r0, _0804792C
	ldr r2, [r0]
	ldr r0, [sp, 0x10]
	adds r1, r5, 0
	bl sub_80522F4
_08047900:
	movs r2, 0x1
	str r2, [sp, 0x20]
_08047904:
	ldr r3, [sp, 0x20]
	cmp r3, 0x1
	bne _0804791A
	movs r0, 0
	str r0, [sp]
	ldr r0, [sp, 0x10]
	ldr r1, [sp, 0x1C]
	ldr r2, [sp, 0x14]
	movs r3, 0
	bl sub_804652C
_0804791A:
	add sp, 0x44
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_0804792C: .4byte gUnknown_80F94F0
	thumb_func_end sub_80475C4

	thumb_func_start sub_8047930
sub_8047930:
	push {r4-r6,lr}
	adds r4, r0, 0
	adds r5, r1, 0
	ldr r1, [r5, 0x70]
	ldrb r0, [r1, 0x8]
	cmp r0, 0x1
	beq _0804794C
	adds r0, r1, 0
	adds r0, 0xA4
	ldrb r0, [r0]
	cmp r0, 0x4
	beq _0804794C
	cmp r0, 0x1
	bne _08047950
_0804794C:
	movs r0, 0
	b _080479B0
_08047950:
	movs r0, 0x64
	bl sub_8084100
	ldr r1, _08047980
	movs r2, 0
	ldrsh r1, [r1, r2]
	movs r6, 0
	cmp r0, r1
	bge _08047964
	movs r6, 0x1
_08047964:
	adds r0, r4, 0
	bl sub_80450F8
	cmp r0, 0x1
	bne _08047994
	adds r0, r4, 0
	movs r1, 0x28
	bl sub_8046CB0
	lsls r0, 24
	cmp r0, 0
	beq _08047984
	movs r6, 0
	b _08047994
	.align 2, 0
_08047980: .4byte gUnknown_80F4FA2
_08047984:
	adds r0, r4, 0
	movs r1, 0x2A
	bl sub_8046CB0
	lsls r0, 24
	cmp r0, 0
	beq _08047994
	movs r6, 0x1
_08047994:
	adds r0, r5, 0
	bl sub_80450F8
	cmp r0, 0x1
	bne _080479AE
	adds r0, r5, 0
	movs r1, 0x25
	bl sub_8046CB0
	lsls r0, 24
	cmp r0, 0
	beq _080479AE
	movs r6, 0
_080479AE:
	adds r0, r6, 0
_080479B0:
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end sub_8047930

	thumb_func_start sub_80479B8
sub_80479B8:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x1C
	adds r4, r3, 0
	ldr r5, [sp, 0x3C]
	ldr r7, [sp, 0x40]
	lsls r0, 24
	lsrs r6, r0, 24
	lsls r1, 24
	lsrs r1, 24
	lsls r2, 24
	lsrs r2, 24
	mov r10, r2
	cmp r6, 0
	beq _08047AD0
	cmp r1, 0
	bne _08047ABC
	movs r0, 0
	mov r8, r0
	ldr r1, [r5, 0x70]
	mov r9, r1
	ldrb r0, [r1, 0x6]
	cmp r0, 0
	beq _08047A20
	ldrb r0, [r7, 0x2]
	bl sub_8090BD0
	lsls r0, 24
	cmp r0, 0
	beq _08047A3C
	ldrb r0, [r7, 0x2]
	bl sub_8090BD0
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x2
	beq _08047A3C
	ldrb r0, [r7, 0x2]
	bl sub_8090BD0
	lsls r0, 24
	lsrs r0, 24
	movs r1, 0x1
	eors r0, r1
	negs r1, r0
	orrs r1, r0
	lsrs r1, 31
	mov r8, r1
	b _08047A3C
_08047A20:
	ldrb r0, [r7, 0x2]
	bl sub_8090BD0
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x2
	beq _08047A3C
	adds r0, r5, 0
	movs r1, 0x2
	bl sub_80718D8
	lsls r0, 24
	lsrs r0, 24
	mov r8, r0
_08047A3C:
	adds r0, r5, 0
	bl sub_8070C60
	lsls r0, 24
	cmp r0, 0
	beq _08047A4C
	movs r0, 0
	mov r8, r0
_08047A4C:
	mov r1, r8
	cmp r1, 0
	beq _08047ABC
	mov r0, r9
	adds r0, 0x60
	ldrb r1, [r0]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	bne _08047ABC
	mov r1, r9
	ldrb r0, [r1, 0x8]
	cmp r0, 0x1
	bne _08047A76
	adds r1, r5, 0x4
	adds r0, r4, 0
	adds r2, r7, 0
	bl sub_80464C8
	bl _080482BA
_08047A76:
	ldr r0, _08047AAC
	bl sub_8083E38
	ldr r0, _08047AB0
	adds r1, r7, 0
	bl sub_8045BF8
	ldr r0, _08047AB4
	adds r1, r5, 0
	movs r2, 0
	bl sub_8045B94
	ldr r0, _08047AB8
	ldr r2, [r0]
	adds r0, r4, 0
	adds r1, r5, 0
	bl sub_80522F4
	ldr r0, [r7]
	mov r1, r9
	str r0, [r1, 0x60]
	adds r0, r5, 0
	bl sub_806A6E8
	bl _080482BA
	.align 2, 0
_08047AAC: .4byte 0x0000014d
_08047AB0: .4byte gUnknown_202DE58
_08047AB4: .4byte gUnknown_202DF98
_08047AB8: .4byte gUnknown_80FDBB8
_08047ABC:
	cmp r6, 0
	beq _08047AD0
	adds r0, r5, 0
	adds r1, r7, 0
	bl sub_8042390
	adds r0, r4, 0
	adds r1, r5, 0
	bl sub_806F450
_08047AD0:
	ldrb r1, [r7]
	movs r0, 0x8
	ands r0, r1
	cmp r0, 0
	beq _08047B2C
	ldr r0, _08047B1C
	adds r1, r7, 0
	bl sub_8045BF8
	ldr r0, _08047B20
	ldr r2, [r0]
	adds r0, r4, 0
	adds r1, r5, 0
	bl sub_80522F4
	cmp r6, 0
	beq _08047B30
	ldr r0, _08047B24
	movs r1, 0
	ldrsh r2, [r0, r1]
	add r0, sp, 0x18
	str r0, [sp]
	movs r1, 0
	str r1, [sp, 0x4]
	ldr r0, _08047B28
	str r0, [sp, 0x8]
	str r1, [sp, 0xC]
	str r1, [sp, 0x10]
	str r1, [sp, 0x14]
	adds r0, r4, 0
	adds r1, r5, 0
	movs r3, 0x1
	bl sub_806F370
	adds r0, r4, 0
	bl sub_8071DA4
	b _080482BA
	.align 2, 0
_08047B1C: .4byte gUnknown_202DE58
_08047B20: .4byte gUnknown_80FE3E8
_08047B24: .4byte gUnknown_80F4FAE
_08047B28: .4byte 0x00000217
_08047B2C:
	cmp r6, 0
	bne _08047B38
_08047B30:
	adds r0, r5, 0
	adds r1, r7, 0
	bl sub_804245C
_08047B38:
	ldrb r0, [r7, 0x2]
	bl sub_8090BD0
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x2
	bne _08047B56
	movs r0, 0
	str r0, [sp]
	adds r0, r4, 0
	adds r1, r5, 0
	movs r2, 0x5
	movs r3, 0
	bl sub_8078B5C
_08047B56:
	ldrb r0, [r7, 0x2]
	bl sub_8090BD0
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x5
	beq _08047B72
	ldrb r0, [r7, 0x2]
	bl sub_8090BD0
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0xA
	bne _08047B9C
_08047B72:
	cmp r6, 0
	beq _08047B88
	ldr r0, _08047B84
	movs r1, 0
	ldrsh r2, [r0, r1]
	mov r0, sp
	adds r0, 0x19
	b _08048284
	.align 2, 0
_08047B84: .4byte gUnknown_80F4FAC
_08047B88:
	ldr r0, _08047B98
	ldr r2, [r0]
	adds r0, r4, 0
	adds r1, r5, 0
	bl sub_80522F4
	b _080482B4
	.align 2, 0
_08047B98: .4byte gUnknown_80FE458
_08047B9C:
	ldrb r0, [r7, 0x2]
	subs r0, 0x1
	cmp r0, 0xE8
	bls _08047BA6
	b _08048276
_08047BA6:
	lsls r0, 2
	ldr r1, _08047BB0
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08047BB0: .4byte _08047BB4
	.align 2, 0
_08047BB4:
	.4byte _08047F58
	.4byte _08047F70
	.4byte _08047F88
	.4byte _08047FA0
	.4byte _08047FB8
	.4byte _08047FD0
	.4byte _08047FF0
	.4byte _08047FE8
	.4byte _08048276
	.4byte _08048276
	.4byte _08048276
	.4byte _08048276
	.4byte _08048276
	.4byte _08048276
	.4byte _08048276
	.4byte _08048276
	.4byte _08048276
	.4byte _08048276
	.4byte _08048276
	.4byte _08048276
	.4byte _08048276
	.4byte _08048276
	.4byte _08048276
	.4byte _08048276
	.4byte _08048276
	.4byte _08048276
	.4byte _08048276
	.4byte _08048276
	.4byte _08048276
	.4byte _08048276
	.4byte _08048276
	.4byte _08048276
	.4byte _08048276
	.4byte _08048276
	.4byte _08048276
	.4byte _08048276
	.4byte _08048276
	.4byte _08048276
	.4byte _08048276
	.4byte _08048276
	.4byte _08048276
	.4byte _08048276
	.4byte _08048276
	.4byte _08048276
	.4byte _08048276
	.4byte _08048276
	.4byte _08048276
	.4byte _08048276
	.4byte _08048276
	.4byte _08048276
	.4byte _08048276
	.4byte _08048276
	.4byte _08048004
	.4byte _0804825E
	.4byte _08048010
	.4byte _0804801A
	.4byte _0804804C
	.4byte _08048276
	.4byte _0804802E
	.4byte _0804809C
	.4byte _08048038
	.4byte _08048024
	.4byte _080480BA
	.4byte _080480C4
	.4byte _08048042
	.4byte _0804806A
	.4byte _08048060
	.4byte _08048056
	.4byte _0804807E
	.4byte _080480B0
	.4byte _08048074
	.4byte _080480D8
	.4byte _080480CE
	.4byte _08048092
	.4byte _08048088
	.4byte _080480A6
	.4byte _080480E4
	.4byte _080480EE
	.4byte _080480F8
	.4byte _08048102
	.4byte _0804810C
	.4byte _08048212
	.4byte _08048122
	.4byte _0804813C
	.4byte _0804812A
	.4byte _08048146
	.4byte _08048152
	.4byte _0804815E
	.4byte _0804816A
	.4byte _08048176
	.4byte _08048182
	.4byte _0804818E
	.4byte _0804819A
	.4byte _080481A6
	.4byte _080481B2
	.4byte _080481BE
	.4byte _080481CA
	.4byte _080481D6
	.4byte _080481E2
	.4byte _080481EE
	.4byte _080481FA
	.4byte _08048206
	.4byte _08048212
	.4byte _08048220
	.4byte _08048276
	.4byte _08048276
	.4byte _08048276
	.4byte _08048276
	.4byte _08048276
	.4byte _08048276
	.4byte _08048276
	.4byte _08048276
	.4byte _08048276
	.4byte _08048276
	.4byte _08048276
	.4byte _08048276
	.4byte _08048276
	.4byte _08048276
	.4byte _0804823A
	.4byte _08048252
	.4byte _08048246
	.4byte _0804826A
	.4byte _0804822E
	.4byte _08048276
	.4byte _08048276
	.4byte _08048276
	.4byte _08048276
	.4byte _08048276
	.4byte _08048276
	.4byte _08048276
	.4byte _08048276
	.4byte _08048276
	.4byte _08048276
	.4byte _08048276
	.4byte _08048276
	.4byte _08048276
	.4byte _08048276
	.4byte _08048276
	.4byte _08048276
	.4byte _08048276
	.4byte _08048276
	.4byte _08048276
	.4byte _08048276
	.4byte _08048276
	.4byte _08048276
	.4byte _08048276
	.4byte _08048276
	.4byte _08048276
	.4byte _08048276
	.4byte _08048276
	.4byte _08048276
	.4byte _08048276
	.4byte _08048276
	.4byte _08048276
	.4byte _08048276
	.4byte _08048276
	.4byte _08048276
	.4byte _08048276
	.4byte _08048276
	.4byte _08048276
	.4byte _08048276
	.4byte _08048276
	.4byte _08048276
	.4byte _08048276
	.4byte _08048276
	.4byte _08048276
	.4byte _08048276
	.4byte _08048276
	.4byte _08048276
	.4byte _08048276
	.4byte _08048276
	.4byte _08048276
	.4byte _08048276
	.4byte _08048276
	.4byte _08048276
	.4byte _08048276
	.4byte _08048276
	.4byte _08048276
	.4byte _08048276
	.4byte _08048276
	.4byte _08048276
	.4byte _08048276
	.4byte _08048276
	.4byte _08048276
	.4byte _08048276
	.4byte _08048276
	.4byte _08048276
	.4byte _08048276
	.4byte _08048276
	.4byte _08048276
	.4byte _08048276
	.4byte _08048276
	.4byte _08048276
	.4byte _08048276
	.4byte _08048276
	.4byte _08048276
	.4byte _08048276
	.4byte _08048276
	.4byte _08048276
	.4byte _08048276
	.4byte _08048276
	.4byte _08048276
	.4byte _08048276
	.4byte _08048276
	.4byte _08048276
	.4byte _08048276
	.4byte _08048276
	.4byte _08048276
	.4byte _08048276
	.4byte _08048276
	.4byte _08048276
	.4byte _08048276
	.4byte _08048276
	.4byte _08048276
	.4byte _08048276
	.4byte _08048276
	.4byte _08048276
	.4byte _08048276
	.4byte _08048276
	.4byte _08048276
	.4byte _08048276
	.4byte _08048276
	.4byte _08048276
	.4byte _08048276
	.4byte _08048276
	.4byte _08048276
	.4byte _08048276
	.4byte _08048276
	.4byte _08048276
	.4byte _08048276
	.4byte _08048276
	.4byte _08048276
	.4byte _08048116
_08047F58:
	ldr r0, _08047F6C
	movs r1, 0
	ldrsh r2, [r0, r1]
	adds r0, r4, 0
	adds r1, r5, 0
	movs r3, 0x1
	bl sub_80482FC
	b _080482B4
	.align 2, 0
_08047F6C: .4byte gUnknown_80F503A
_08047F70:
	ldr r0, _08047F84
	movs r1, 0
	ldrsh r2, [r0, r1]
	adds r0, r4, 0
	adds r1, r5, 0
	movs r3, 0x2
	bl sub_80482FC
	b _080482B4
	.align 2, 0
_08047F84: .4byte gUnknown_80F503C
_08047F88:
	ldr r0, _08047F9C
	movs r1, 0
	ldrsh r2, [r0, r1]
	adds r0, r4, 0
	adds r1, r5, 0
	movs r3, 0x3
	bl sub_80482FC
	b _080482B4
	.align 2, 0
_08047F9C: .4byte gUnknown_80F503E
_08047FA0:
	ldr r0, _08047FB4
	movs r1, 0
	ldrsh r2, [r0, r1]
	adds r0, r4, 0
	adds r1, r5, 0
	movs r3, 0x4
	bl sub_80482FC
	b _080482B4
	.align 2, 0
_08047FB4: .4byte gUnknown_80F5040
_08047FB8:
	ldr r0, _08047FCC
	movs r1, 0
	ldrsh r2, [r0, r1]
	adds r0, r4, 0
	adds r1, r5, 0
	movs r3, 0x5
	bl sub_80482FC
	b _080482B4
	.align 2, 0
_08047FCC: .4byte gUnknown_80F5042
_08047FD0:
	ldr r0, _08047FE4
	movs r1, 0
	ldrsh r2, [r0, r1]
	adds r0, r4, 0
	adds r1, r5, 0
	movs r3, 0x6
	bl sub_80482FC
	b _080482B4
	.align 2, 0
_08047FE4: .4byte gUnknown_80F5044
_08047FE8:
	ldr r0, _08047FEC
	b _08047FF2
	.align 2, 0
_08047FEC: .4byte gUnknown_80F5048
_08047FF0:
	ldr r0, _08048000
_08047FF2:
	movs r1, 0
	ldrsh r2, [r0, r1]
	adds r0, r4, 0
	adds r1, r5, 0
	bl sub_8048340
	b _080482B4
	.align 2, 0
_08048000: .4byte gUnknown_80F5046
_08048004:
	adds r0, r4, 0
	adds r1, r5, 0
	mov r2, r10
	bl sub_8048364
	b _080482B4
_08048010:
	adds r0, r4, 0
	adds r1, r5, 0
	bl sub_8048374
	b _080482B4
_0804801A:
	adds r0, r4, 0
	adds r1, r5, 0
	bl sub_804839C
	b _080482B4
_08048024:
	adds r0, r4, 0
	adds r1, r5, 0
	bl sub_80483D4
	b _080482B4
_0804802E:
	adds r0, r4, 0
	adds r1, r5, 0
	bl sub_80483F4
	b _080482B4
_08048038:
	adds r0, r4, 0
	adds r1, r5, 0
	bl sub_8048400
	b _080482B4
_08048042:
	adds r0, r4, 0
	adds r1, r5, 0
	bl sub_804840C
	b _080482B4
_0804804C:
	adds r0, r4, 0
	adds r1, r5, 0
	bl sub_804841C
	b _080482B4
_08048056:
	adds r0, r4, 0
	adds r1, r5, 0
	bl sub_804849C
	b _080482B4
_08048060:
	adds r0, r4, 0
	adds r1, r5, 0
	bl sub_8048428
	b _080482B4
_0804806A:
	adds r0, r4, 0
	adds r1, r5, 0
	bl sub_8048450
	b _080482B4
_08048074:
	adds r0, r4, 0
	adds r1, r5, 0
	bl sub_8048480
	b _080482B4
_0804807E:
	adds r0, r4, 0
	adds r1, r5, 0
	bl sub_80482D4
	b _080482B4
_08048088:
	adds r0, r4, 0
	adds r1, r5, 0
	bl sub_8048490
	b _080482B4
_08048092:
	adds r0, r4, 0
	adds r1, r5, 0
	bl sub_80484A8
	b _080482B4
_0804809C:
	adds r0, r4, 0
	adds r1, r5, 0
	bl sub_80484DC
	b _080482B4
_080480A6:
	adds r0, r4, 0
	adds r1, r5, 0
	bl sub_80484BC
	b _080482B4
_080480B0:
	adds r0, r4, 0
	adds r1, r5, 0
	bl sub_80484C8
	b _080482B4
_080480BA:
	adds r0, r4, 0
	adds r1, r5, 0
	bl sub_80484E8
	b _080482B4
_080480C4:
	adds r0, r4, 0
	adds r1, r5, 0
	bl sub_8048524
	b _080482B4
_080480CE:
	adds r0, r4, 0
	adds r1, r5, 0
	bl sub_80485B0
	b _080482B4
_080480D8:
	adds r0, r4, 0
	adds r1, r5, 0
	adds r2, r6, 0
	bl sub_804869C
	b _080482B4
_080480E4:
	adds r0, r4, 0
	adds r1, r5, 0
	bl sub_80483C4
	b _080482B4
_080480EE:
	adds r0, r4, 0
	adds r1, r5, 0
	bl sub_804891C
	b _080482B4
_080480F8:
	adds r0, r4, 0
	adds r1, r5, 0
	bl sub_8048928
	b _080482B4
_08048102:
	adds r0, r4, 0
	adds r1, r5, 0
	bl sub_8048934
	b _080482B4
_0804810C:
	adds r0, r4, 0
	adds r1, r5, 0
	bl sub_8048940
	b _080482B4
_08048116:
	adds r0, r4, 0
	adds r1, r5, 0
	adds r2, r6, 0
	bl nullsub_94
	b _080482B4
_08048122:
	adds r0, r4, 0
	adds r1, r5, 0
	movs r2, 0x64
	b _08048130
_0804812A:
	ldr r2, _08048138
	adds r0, r4, 0
	adds r1, r5, 0
_08048130:
	movs r3, 0xA
	bl sub_80487CC
	b _080482B4
	.align 2, 0
_08048138: .4byte 0x000003e7
_0804813C:
	adds r0, r4, 0
	adds r1, r5, 0
	bl sub_8048E04
	b _080482B4
_08048146:
	adds r0, r4, 0
	adds r1, r5, 0
	movs r2, 0x1
	bl sub_80487E0
	b _080482B4
_08048152:
	adds r0, r4, 0
	adds r1, r5, 0
	movs r2, 0x2
	bl sub_80487E0
	b _080482B4
_0804815E:
	adds r0, r4, 0
	adds r1, r5, 0
	movs r2, 0x3
	bl sub_80487E0
	b _080482B4
_0804816A:
	adds r0, r4, 0
	adds r1, r5, 0
	movs r2, 0x4
	bl sub_80487E0
	b _080482B4
_08048176:
	adds r0, r4, 0
	adds r1, r5, 0
	movs r2, 0x5
	bl sub_80487E0
	b _080482B4
_08048182:
	adds r0, r4, 0
	adds r1, r5, 0
	movs r2, 0x6
	bl sub_80487E0
	b _080482B4
_0804818E:
	adds r0, r4, 0
	adds r1, r5, 0
	movs r2, 0x7
	bl sub_80487E0
	b _080482B4
_0804819A:
	adds r0, r4, 0
	adds r1, r5, 0
	movs r2, 0x8
	bl sub_80487E0
	b _080482B4
_080481A6:
	adds r0, r4, 0
	adds r1, r5, 0
	movs r2, 0x9
	bl sub_80487E0
	b _080482B4
_080481B2:
	adds r0, r4, 0
	adds r1, r5, 0
	movs r2, 0xA
	bl sub_80487E0
	b _080482B4
_080481BE:
	adds r0, r4, 0
	adds r1, r5, 0
	movs r2, 0xB
	bl sub_80487E0
	b _080482B4
_080481CA:
	adds r0, r4, 0
	adds r1, r5, 0
	movs r2, 0xC
	bl sub_80487E0
	b _080482B4
_080481D6:
	adds r0, r4, 0
	adds r1, r5, 0
	movs r2, 0xD
	bl sub_80487E0
	b _080482B4
_080481E2:
	adds r0, r4, 0
	adds r1, r5, 0
	movs r2, 0xE
	bl sub_80487E0
	b _080482B4
_080481EE:
	adds r0, r4, 0
	adds r1, r5, 0
	movs r2, 0xF
	bl sub_80487E0
	b _080482B4
_080481FA:
	adds r0, r4, 0
	adds r1, r5, 0
	movs r2, 0x10
	bl sub_80487E0
	b _080482B4
_08048206:
	adds r0, r4, 0
	adds r1, r5, 0
	movs r2, 0x11
	bl sub_80487E0
	b _080482B4
_08048212:
	adds r0, r4, 0
	adds r1, r5, 0
	movs r2, 0x32
	movs r3, 0x5
	bl sub_80487CC
	b _080482B4
_08048220:
	adds r0, r4, 0
	adds r1, r5, 0
	movs r2, 0xA
	movs r3, 0
	bl sub_80487CC
	b _080482B4
_0804822E:
	adds r0, r4, 0
	adds r1, r5, 0
	adds r2, r6, 0
	bl sub_8048DB8
	b _080482B4
_0804823A:
	adds r0, r4, 0
	adds r1, r5, 0
	adds r2, r6, 0
	bl sub_8048EB0
	b _080482B4
_08048246:
	adds r0, r4, 0
	adds r1, r5, 0
	adds r2, r6, 0
	bl sub_8048EC4
	b _080482B4
_08048252:
	adds r0, r4, 0
	adds r1, r5, 0
	adds r2, r6, 0
	bl sub_8048ED8
	b _080482B4
_0804825E:
	adds r0, r4, 0
	adds r1, r5, 0
	adds r2, r6, 0
	bl sub_8048EEC
	b _080482B4
_0804826A:
	adds r0, r4, 0
	adds r1, r5, 0
	adds r2, r6, 0
	bl sub_8048F00
	b _080482B4
_08048276:
	cmp r6, 0
	beq _080482A8
	ldr r0, _080482A0
	movs r1, 0
	ldrsh r2, [r0, r1]
	mov r0, sp
	adds r0, 0x1A
_08048284:
	str r0, [sp]
	movs r1, 0
	str r1, [sp, 0x4]
	ldr r0, _080482A4
	str r0, [sp, 0x8]
	str r1, [sp, 0xC]
	str r1, [sp, 0x10]
	str r1, [sp, 0x14]
	adds r0, r4, 0
	adds r1, r5, 0
	movs r3, 0x1
	bl sub_806F370
	b _080482B4
	.align 2, 0
_080482A0: .4byte gUnknown_80F4FAC
_080482A4: .4byte 0x00000217
_080482A8:
	ldr r0, _080482CC
	ldr r2, [r0]
	adds r0, r4, 0
	adds r1, r5, 0
	bl sub_80522F4
_080482B4:
	adds r0, r4, 0
	bl sub_8071DA4
_080482BA:
	add sp, 0x1C
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_080482CC: .4byte gUnknown_80FE458
	thumb_func_end sub_80479B8

	thumb_func_start nullsub_205
nullsub_205:
	bx lr
	thumb_func_end nullsub_205

	thumb_func_start sub_80482D4
sub_80482D4:
	push {r4,r5,lr}
	adds r5, r0, 0
	adds r4, r1, 0
	ldr r1, _080482F8
	adds r0, r4, 0
	movs r2, 0x1
	bl sub_808417C
	adds r2, r0, 0
	adds r0, r5, 0
	adds r1, r4, 0
	movs r3, 0x1
	bl sub_8075C58
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_080482F8: .4byte gUnknown_80F4E74
	thumb_func_end sub_80482D4

	thumb_func_start sub_80482FC
sub_80482FC:
	push {r4-r6,lr}
	mov r6, r9
	mov r5, r8
	push {r5,r6}
	sub sp, 0xC
	mov r8, r0
	mov r9, r1
	adds r6, r2, 0
	lsls r4, r3, 24
	lsrs r4, 24
	add r5, sp, 0x4
	ldr r1, _0804833C
	adds r0, r5, 0
	bl sub_8092A88
	strb r6, [r5, 0x4]
	movs r3, 0x80
	lsls r3, 1
	str r4, [sp]
	mov r0, r8
	mov r1, r9
	add r2, sp, 0x4
	bl sub_8055640
	add sp, 0xC
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r6}
	pop {r0}
	bx r0
	.align 2, 0
_0804833C: .4byte 0x00000195
	thumb_func_end sub_80482FC

	thumb_func_start sub_8048340
sub_8048340:
	push {r4,lr}
	sub sp, 0x18
	movs r4, 0
	str r4, [sp]
	str r4, [sp, 0x4]
	movs r3, 0x84
	lsls r3, 2
	str r3, [sp, 0x8]
	str r4, [sp, 0xC]
	str r4, [sp, 0x10]
	str r4, [sp, 0x14]
	movs r3, 0x1
	bl sub_806F370
	add sp, 0x18
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_8048340

	thumb_func_start sub_8048364
sub_8048364:
	push {lr}
	lsls r3, r2, 24
	lsrs r3, 24
	movs r2, 0x1
	bl sub_8079F20
	pop {r0}
	bx r0
	thumb_func_end sub_8048364

	thumb_func_start sub_8048374
sub_8048374:
	push {r4,lr}
	sub sp, 0x4
	ldr r2, _08048394
	movs r3, 0
	ldrsh r2, [r2, r3]
	ldr r3, _08048398
	movs r4, 0
	ldrsh r3, [r3, r4]
	movs r4, 0x1
	str r4, [sp]
	bl sub_8077C44
	add sp, 0x4
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08048394: .4byte gUnknown_80F4FB6
_08048398: .4byte gUnknown_80F4FB8
	thumb_func_end sub_8048374

	thumb_func_start sub_804839C
sub_804839C:
	push {r4,lr}
	sub sp, 0x4
	ldr r2, _080483BC
	movs r3, 0
	ldrsh r2, [r2, r3]
	ldr r3, _080483C0
	movs r4, 0
	ldrsh r3, [r3, r4]
	movs r4, 0x1
	str r4, [sp]
	bl sub_8077C44
	add sp, 0x4
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080483BC: .4byte gUnknown_80F4FBA
_080483C0: .4byte gUnknown_80F4FBC
	thumb_func_end sub_804839C

	thumb_func_start sub_80483C4
sub_80483C4:
	push {lr}
	ldr r2, _080483D0
	bl sub_80792F8
	pop {r0}
	bx r0
	.align 2, 0
_080483D0: .4byte 0x000003e7
	thumb_func_end sub_80483C4

	thumb_func_start sub_80483D4
sub_80483D4:
	push {r4,lr}
	sub sp, 0x4
	ldr r2, _080483F0
	movs r4, 0
	ldrsh r3, [r2, r4]
	movs r2, 0x1
	str r2, [sp]
	movs r2, 0
	bl sub_8077C44
	add sp, 0x4
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080483F0: .4byte gUnknown_80F4FBE
	thumb_func_end sub_80483D4

	thumb_func_start sub_80483F4
sub_80483F4:
	push {lr}
	bl sub_8079140
	pop {r0}
	bx r0
	thumb_func_end sub_80483F4

	thumb_func_start sub_8048400
sub_8048400:
	push {lr}
	bl sub_80791D8
	pop {r0}
	bx r0
	thumb_func_end sub_8048400

	thumb_func_start sub_804840C
sub_804840C:
	push {lr}
	movs r2, 0
	movs r3, 0x1
	bl sub_8077910
	pop {r0}
	bx r0
	thumb_func_end sub_804840C

	thumb_func_start sub_804841C
sub_804841C:
	push {lr}
	bl sub_8079270
	pop {r0}
	bx r0
	thumb_func_end sub_804841C

	thumb_func_start sub_8048428
sub_8048428:
	push {lr}
	adds r3, r0, 0
	ldr r0, [r1, 0x70]
	adds r0, 0xAC
	ldrb r0, [r0]
	cmp r0, 0x4
	bne _0804843E
	adds r0, r3, 0
	bl sub_807A290
	b _08048448
_0804843E:
	ldr r0, _0804844C
	ldr r2, [r0]
	adds r0, r3, 0
	bl sub_80522F4
_08048448:
	pop {r0}
	bx r0
	.align 2, 0
_0804844C: .4byte gUnknown_80F89F4
	thumb_func_end sub_8048428

	thumb_func_start sub_8048450
sub_8048450:
	push {lr}
	adds r3, r0, 0
	ldr r0, [r1, 0x70]
	adds r0, 0xAC
	ldrb r0, [r0]
	subs r0, 0x2
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bhi _0804846C
	adds r0, r3, 0
	bl sub_807A290
	b _08048476
_0804846C:
	ldr r0, _0804847C
	ldr r2, [r0]
	adds r0, r3, 0
	bl sub_80522F4
_08048476:
	pop {r0}
	bx r0
	.align 2, 0
_0804847C: .4byte gUnknown_80F89F4
	thumb_func_end sub_8048450

        .align 2,0
