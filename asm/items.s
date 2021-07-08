	.include "constants/gba_constants.inc"
	.include "asm/macros.inc"

	.syntax unified

	.text

	thumb_func_start sub_8090E14
sub_8090E14:
	push {r4-r7,lr}
	sub sp, 0x50
	adds r6, r0, 0
	adds r5, r1, 0
	adds r7, r2, 0
	movs r4, 0
	cmp r7, 0
	beq _08090E2C
	ldrb r1, [r7, 0x8]
	negs r0, r1
	orrs r0, r1
	lsrs r4, r0, 31
_08090E2C:
	ldrb r0, [r5, 0x2]
	bl GetItemType
	lsls r0, 24
	cmp r0, 0
	bne _08090E3E
	cmp r4, 0
	bne _08090E50
	b _08090E70
_08090E3E:
	ldrb r0, [r5, 0x2]
	bl GetItemType
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _08090E90
	cmp r4, 0
	beq _08090E70
_08090E50:
	ldr r1, _08090E68
	ldrb r0, [r5, 0x2]
	ldr r2, _08090E6C
	ldr r2, [r2]
	lsls r0, 5
	adds r0, r2
	ldr r2, [r0]
	ldrb r3, [r5, 0x1]
	mov r0, sp
	bl ExpandPlaceholdersBuffer
	b _08090EC4
	.align 2, 0
_08090E68: .4byte gUnknown_8109770
_08090E6C: .4byte gItemParametersData
_08090E70:
	ldr r1, _08090E88
	ldrb r0, [r5, 0x2]
	ldr r2, _08090E8C
	ldr r2, [r2]
	lsls r0, 5
	adds r0, r2
	ldr r2, [r0]
	mov r0, sp
	bl ExpandPlaceholdersBuffer
	b _08090EC4
	.align 2, 0
_08090E88: .4byte gUnknown_8109778
_08090E8C: .4byte gItemParametersData
_08090E90:
	ldrb r0, [r5, 0x2]
	cmp r0, 0x69
	bne _08090EB0
	ldr r4, _08090EAC
	adds r0, r5, 0
	bl sub_80915D4
	adds r2, r0, 0
	mov r0, sp
	adds r1, r4, 0
	bl ExpandPlaceholdersBuffer
	b _08090EC4
	.align 2, 0
_08090EAC: .4byte gUnknown_810977C
_08090EB0:
	ldrb r0, [r5, 0x2]
	ldr r1, _08090F2C
	ldr r1, [r1]
	lsls r0, 5
	adds r0, r1
	ldr r1, [r0]
	mov r0, sp
	movs r2, 0x50
	bl strncpy
_08090EC4:
	ldrb r1, [r5]
	movs r0, 0x8
	ands r0, r1
	cmp r0, 0
	beq _08090EE2
	ldr r1, _08090F30
	adds r0, r6, 0
	mov r2, sp
	bl ExpandPlaceholdersBuffer
	mov r0, sp
	adds r1, r6, 0
	movs r2, 0x50
	bl strncpy
_08090EE2:
	cmp r7, 0
	beq _08090F38
	ldrb r0, [r7, 0x4]
	cmp r0, 0
	beq _08090F0A
	ldrb r1, [r5]
	movs r0, 0x10
	ands r0, r1
	cmp r0, 0
	beq _08090F0A
	ldr r1, _08090F34
	adds r0, r6, 0
	mov r2, sp
	bl ExpandPlaceholdersBuffer
	mov r0, sp
	adds r1, r6, 0
	movs r2, 0x50
	bl strncpy
_08090F0A:
	ldr r0, [r7]
	cmp r0, 0x1
	beq _08090F14
	cmp r0, 0x3
	bne _08090F44
_08090F14:
	ldrb r1, [r5]
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	beq _08090F38
	adds r0, r6, 0
	mov r1, sp
	adds r2, r5, 0
	adds r3, r7, 0
	bl sub_8090F58
	b _08090F50
	.align 2, 0
_08090F2C: .4byte gItemParametersData
_08090F30: .4byte gUnknown_8109784
_08090F34: .4byte gUnknown_810978C
_08090F38:
	adds r0, r6, 0
	mov r1, sp
	movs r2, 0x50
	bl strncpy
	b _08090F50
_08090F44:
	adds r0, r6, 0
	mov r1, sp
	adds r2, r5, 0
	adds r3, r7, 0
	bl sub_8090F58
_08090F50:
	add sp, 0x50
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_8090E14

	thumb_func_start sub_8090F58
sub_8090F58:
	push {r4-r6,lr}
	sub sp, 0x2C
	adds r5, r0, 0
	adds r6, r1, 0
	adds r0, r2, 0
	adds r4, r3, 0
	cmp r4, 0
	bne _08090F6C
	adds r0, r5, 0
	b _08090F94
_08090F6C:
	ldr r1, [r4]
	cmp r1, 0x1
	bcc _08090F8A
	cmp r1, 0x2
	bhi _08090F7E
	bl sub_8090BE4
	adds r1, r0, 0
	b _08090F8C
_08090F7E:
	cmp r1, 0x4
	bhi _08090F8A
	bl sub_8090C30
	adds r1, r0, 0
	b _08090F8C
_08090F8A:
	movs r1, 0
_08090F8C:
	cmp r1, 0
	bne _08090F9C
	adds r0, r5, 0
	adds r1, r6, 0
_08090F94:
	movs r2, 0x50
	bl strncpy
	b _08090FDE
_08090F9C:
	movs r2, 0x6
	ldrsh r0, [r4, r2]
	cmp r0, 0
	beq _08090FC8
	adds r0, r1, 0
	add r1, sp, 0x4
	movs r2, 0x1
	bl sub_8090FEC
	ldr r1, _08090FC4
	movs r0, 0x6
	ldrsh r3, [r4, r0]
	add r2, sp, 0x4
	str r2, [sp]
	adds r0, r5, 0
	adds r2, r6, 0
	bl ExpandPlaceholdersBuffer
	b _08090FDE
	.align 2, 0
_08090FC4: .4byte gUnknown_8109794
_08090FC8:
	adds r0, r1, 0
	add r1, sp, 0x4
	movs r2, 0
	bl sub_8090FEC
	ldr r1, _08090FE8
	adds r0, r5, 0
	adds r2, r6, 0
	add r3, sp, 0x4
	bl ExpandPlaceholdersBuffer
_08090FDE:
	add sp, 0x2C
	pop {r4-r6}
	pop {r0}
	bx r0
	.align 2, 0
_08090FE8: .4byte gUnknown_81097A4
	thumb_func_end sub_8090F58

	thumb_func_start sub_8090FEC
sub_8090FEC:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	adds r5, r0, 0
	adds r4, r1, 0
	lsls r2, 24
	lsrs r2, 24
	mov r10, r2
	movs r0, 0
	mov r8, r0
	movs r6, 0
	movs r2, 0
	ldr r1, _08091050
	mov r9, r1
	mov r12, r9
_0809100E:
	movs r1, 0
	lsls r3, r2, 2
	ldr r7, _08091054
	adds r0, r3, r7
	ldr r0, [r0]
	adds r7, r2, 0x1
	cmp r5, r0
	blt _0809102C
	ldr r2, _08091054
_08091020:
	adds r0, r3, r2
	ldr r0, [r0]
	subs r5, r0
	adds r1, 0x1
	cmp r5, r0
	bge _08091020
_0809102C:
	cmp r1, 0x9
	ble _08091032
	movs r1, 0x9
_08091032:
	cmp r1, 0
	beq _0809105C
	movs r0, 0x1
	mov r8, r0
	lsls r1, 1
	mov r2, r12
	adds r0, r1, r2
	ldrb r0, [r0]
	strb r0, [r4]
	adds r4, 0x1
	ldr r0, _08091058
	adds r1, r0
	ldrb r0, [r1]
	b _0809106C
	.align 2, 0
_08091050: .4byte gUnknown_81097C4
_08091054: .4byte gUnknown_81097B0
_08091058: .4byte gUnknown_81097C5
_0809105C:
	mov r1, r8
	cmp r1, 0
	beq _08091074
	mov r2, r12
	ldrb r0, [r2]
	strb r0, [r4]
	adds r4, 0x1
	ldrb r0, [r2, 0x1]
_0809106C:
	strb r0, [r4]
	adds r4, 0x1
	adds r6, 0x1
	b _08091080
_08091074:
	mov r0, r10
	cmp r0, 0
	beq _08091080
	movs r0, 0x60
	strb r0, [r4]
	adds r4, 0x1
_08091080:
	adds r2, r7, 0
	cmp r2, 0x4
	ble _0809100E
	lsls r1, r5, 1
	mov r2, r9
	adds r0, r1, r2
	ldrb r0, [r0]
	strb r0, [r4]
	adds r4, 0x1
	mov r0, r9
	adds r0, 0x1
	adds r1, r0
	ldrb r0, [r1]
	strb r0, [r4]
	adds r6, 0x1
	movs r0, 0
	strb r0, [r4, 0x1]
	adds r0, r6, 0
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_8090FEC

	thumb_func_start sub_80910B4
sub_80910B4:
	push {r4-r7,lr}
	movs r2, 0
	movs r4, 0
	ldr r7, _080910C0
	movs r3, 0
	b _080910DA
	.align 2, 0
_080910C0: .4byte gUnknown_203B460
_080910C4:
	cmp r2, r4
	ble _080910D4
	ldr r0, [r7]
	lsls r1, r4, 2
	adds r1, r0, r1
	adds r0, r3
	ldr r0, [r0]
	str r0, [r1]
_080910D4:
	adds r3, 0x4
	adds r2, 0x1
	adds r4, 0x1
_080910DA:
	cmp r2, 0x13
	bgt _08091106
	ldr r0, [r7]
	adds r0, r3, r0
	ldrb r1, [r0]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	bne _08091106
	ldr r5, _0809112C
	movs r6, 0x1
_080910F0:
	adds r3, 0x4
	adds r2, 0x1
	cmp r2, 0x13
	bgt _08091106
	ldr r0, [r5]
	adds r0, r3, r0
	ldrb r1, [r0]
	adds r0, r6, 0
	ands r0, r1
	cmp r0, 0
	beq _080910F0
_08091106:
	cmp r2, 0x14
	bne _080910C4
	cmp r4, 0x13
	bgt _08091124
	ldr r3, _0809112C
	movs r2, 0
_08091112:
	lsls r1, r4, 2
	ldr r0, [r3]
	adds r1, r0
	strb r2, [r1, 0x2]
	strb r2, [r1, 0x1]
	strb r2, [r1]
	adds r4, 0x1
	cmp r4, 0x13
	ble _08091112
_08091124:
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_0809112C: .4byte gUnknown_203B460
	thumb_func_end sub_80910B4

	thumb_func_start sub_8091130
sub_8091130:
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	movs r3, 0
	ldr r0, _08091154
	ldr r2, [r0]
	movs r5, 0x1
_0809113E:
	ldrb r1, [r2]
	adds r0, r5, 0
	ands r0, r1
	cmp r0, 0
	beq _08091158
	ldrb r0, [r2, 0x2]
	cmp r0, r4
	bne _08091158
	adds r0, r3, 0
	b _08091164
	.align 2, 0
_08091154: .4byte gUnknown_203B460
_08091158:
	adds r2, 0x4
	adds r3, 0x1
	cmp r3, 0x13
	ble _0809113E
	movs r0, 0x1
	negs r0, r0
_08091164:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_8091130

	thumb_func_start sub_809116C
sub_809116C:
	push {r4-r6,lr}
	lsls r0, 24
	lsrs r5, r0, 24
	movs r4, 0
	ldr r0, _080911A0
	ldr r2, [r0]
	movs r6, 0x1
	movs r3, 0x13
_0809117C:
	ldrb r1, [r2]
	adds r0, r6, 0
	ands r0, r1
	cmp r0, 0
	beq _0809118E
	ldrb r0, [r2, 0x2]
	cmp r0, r5
	bne _0809118E
	adds r4, 0x1
_0809118E:
	adds r2, 0x4
	subs r3, 0x1
	cmp r3, 0
	bge _0809117C
	adds r0, r4, 0
	pop {r4-r6}
	pop {r1}
	bx r1
	.align 2, 0
_080911A0: .4byte gUnknown_203B460
	thumb_func_end sub_809116C

	thumb_func_start sub_80911A4
sub_80911A4:
	push {r4-r7,lr}
	lsls r0, 24
	lsrs r5, r0, 24
	adds r0, r5, 0
	bl sub_809116C
	adds r4, r0, 0
	movs r3, 0
	ldr r0, _080911F4
	ldr r7, [r0]
	movs r6, 0x1
_080911BA:
	movs r0, 0x58
	muls r0, r3
	adds r2, r7, r0
	ldrh r1, [r2]
	adds r0, r6, 0
	ands r0, r1
	cmp r0, 0
	beq _080911E2
	lsrs r0, r1, 1
	ands r0, r6
	cmp r0, 0
	beq _080911E2
	adds r0, r2, 0
	adds r0, 0x28
	ldrb r0, [r0]
	cmp r0, 0
	beq _080911E2
	cmp r0, r5
	bne _080911E2
	adds r4, 0x1
_080911E2:
	adds r3, 0x1
	movs r0, 0xCE
	lsls r0, 1
	cmp r3, r0
	ble _080911BA
	adds r0, r4, 0
	pop {r4-r7}
	pop {r1}
	bx r1
	.align 2, 0
_080911F4: .4byte gRecruitedPokemonRef
	thumb_func_end sub_80911A4

	thumb_func_start sub_80911F8
sub_80911F8:
	push {r4,r5,lr}
	adds r2, r0, 0
	ldr r4, _08091230
	cmp r2, 0x12
	bgt _0809121C
	adds r5, r4, 0
	lsls r0, r2, 2
	adds r3, r0, 0x4
_08091208:
	ldr r0, [r5]
	lsls r1, r2, 2
	adds r1, r0, r1
	adds r0, r3
	ldr r0, [r0]
	str r0, [r1]
	adds r3, 0x4
	adds r2, 0x1
	cmp r2, 0x12
	ble _08091208
_0809121C:
	ldr r0, [r4]
	adds r0, 0x4E
	movs r1, 0
	strb r1, [r0]
	ldr r0, [r4]
	adds r0, 0x4C
	strb r1, [r0]
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_08091230: .4byte gUnknown_203B460
	thumb_func_end sub_80911F8

	thumb_func_start sub_8091234
sub_8091234:
	ldr r3, _08091248
	ldr r1, [r3]
	lsls r0, 2
	adds r1, r0
	movs r2, 0
	strb r2, [r1, 0x2]
	ldr r1, [r3]
	adds r1, r0
	strb r2, [r1]
	bx lr
	.align 2, 0
_08091248: .4byte gUnknown_203B460
	thumb_func_end sub_8091234

	thumb_func_start sub_809124C
sub_809124C:
	push {lr}
	sub sp, 0x4
	adds r3, r0, 0
	adds r2, r1, 0
	lsls r3, 24
	lsrs r3, 24
	lsls r2, 24
	lsrs r2, 24
	mov r0, sp
	adds r1, r3, 0
	bl sub_8090A8C
	mov r0, sp
	bl sub_8091290
	lsls r0, 24
	lsrs r0, 24
	add sp, 0x4
	pop {r1}
	bx r1
	thumb_func_end sub_809124C

	thumb_func_start sub_8091274
sub_8091274:
	push {lr}
	sub sp, 0x4
	adds r1, r0, 0
	mov r0, sp
	bl sub_8090B64
	mov r0, sp
	bl sub_8091290
	lsls r0, 24
	lsrs r0, 24
	add sp, 0x4
	pop {r1}
	bx r1
	thumb_func_end sub_8091274

@ 	thumb_func_start sub_8091290
@ sub_8091290:
@ 	push {r4-r6,lr}
@ 	adds r4, r0, 0
@ 	movs r3, 0
@ 	ldr r5, _080912B4
@ 	movs r6, 0x1
@ _0809129A:
@ 	lsls r1, r3, 2
@ 	ldr r0, [r5]
@ 	adds r2, r1, r0
@ 	ldrb r1, [r2]
@ 	adds r0, r6, 0
@ 	ands r0, r1
@ 	cmp r0, 0
@ 	bne _080912B8
@ 	ldr r0, [r4]
@ 	str r0, [r2]
@ 	movs r0, 0
@ 	b _080912C0
@ 	.align 2, 0
@ _080912B4: .4byte gUnknown_203B460
@ _080912B8:
@ 	adds r3, 0x1
@ 	cmp r3, 0x13
@ 	ble _0809129A
@ 	movs r0, 0x1
@ _080912C0:
@ 	pop {r4-r6}
@ 	pop {r1}
@ 	bx r1
@ 	thumb_func_end sub_8091290
        .align 2,0
