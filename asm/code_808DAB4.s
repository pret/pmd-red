	.include "constants/gba_constants.inc"
	.include "asm/macros.inc"

	.syntax unified

	.text

	thumb_func_start sub_808DE30
sub_808DE30:
	push {r4,lr}
	adds r2, r1, 0
	ldr r4, _0808DE4C
	movs r1, 0x58
	adds r3, r2, 0
	muls r3, r1
	ldr r1, [r4]
	adds r1, r3
	bl sub_808DE50
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0808DE4C: .4byte gUnknown_203B45C
	thumb_func_end sub_808DE30

	thumb_func_start sub_808DE50
sub_808DE50:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0x8
	adds r5, r0, 0
	adds r6, r1, 0
	adds r4, r2, 0
	ldrh r0, [r6]
	strh r0, [r5]
	ldrb r0, [r6, 0x3]
	strb r0, [r5, 0x3]
	ldrh r0, [r6, 0x14]
	strh r0, [r5, 0x8]
	ldr r0, [r6, 0x20]
	str r0, [r5, 0x4C]
	adds r0, r5, 0
	adds r0, 0x54
	bl sub_808E6F4
	ldr r0, [r6, 0x4]
	str r0, [r5, 0x4]
	ldrb r0, [r6, 0x2]
	strb r0, [r5, 0x2]
	strh r4, [r5, 0xA]
	ldrh r0, [r6, 0x8]
	strh r0, [r5, 0xE]
	adds r0, r6, 0
	adds r0, 0x24
	ldrb r1, [r0]
	adds r0, r5, 0
	adds r0, 0x50
	strb r1, [r0]
	ldrh r0, [r6, 0x16]
	strh r0, [r5, 0x12]
	strh r0, [r5, 0x10]
	add r0, sp, 0x4
	mov r8, r0
	adds r2, r6, 0
	adds r2, 0x18
	adds r1, r5, 0
	adds r1, 0x14
	movs r3, 0x1
_0808DEA4:
	ldrb r0, [r2]
	strb r0, [r1]
	ldrb r0, [r2, 0x2]
	strb r0, [r1, 0x2]
	adds r2, 0x1
	adds r1, 0x1
	subs r3, 0x1
	cmp r3, 0
	bge _0808DEA4
	ldr r0, [r6, 0x1C]
	str r0, [r5, 0x18]
	adds r0, r5, 0
	adds r0, 0x1C
	adds r1, r6, 0
	adds r1, 0x2C
	bl sub_8093F50
	movs r3, 0
	movs r0, 0x28
	adds r0, r6
	mov r12, r0
	adds r2, r5, 0
	adds r2, 0x40
	adds r7, r5, 0
	adds r7, 0x58
	adds r4, r6, 0
	adds r4, 0x4C
_0808DEDA:
	adds r0, r7, r3
	adds r1, r4, r3
	ldrb r1, [r1]
	strb r1, [r0]
	adds r3, 0x1
	cmp r3, 0x9
	ble _0808DEDA
	mov r0, r12
	ldrb r1, [r0]
	negs r0, r1
	orrs r0, r1
	lsrs r0, 31
	cmp r0, 0
	beq _0808DF00
	adds r0, r2, 0
	mov r1, r12
	bl sub_8090B64
	b _0808DF06
_0808DF00:
	strb r0, [r2, 0x2]
	strb r0, [r2, 0x1]
	strb r0, [r2]
_0808DF06:
	mov r0, sp
	movs r1, 0x64
	bl sub_80943A0
	ldr r0, [sp]
	str r0, [r5, 0x44]
	mov r0, r8
	movs r1, 0x64
	bl sub_80943A0
	ldr r0, [sp, 0x4]
	str r0, [r5, 0x48]
	add sp, 0x8
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_808DE50

	thumb_func_start sub_808DF2C
sub_808DF2C:
	push {lr}
	ldr r3, _0808DF40
	movs r2, 0x58
	muls r2, r0
	ldr r0, [r3]
	adds r0, r2
	bl sub_808DF44
	pop {r0}
	bx r0
	.align 2, 0
_0808DF40: .4byte gUnknown_203B45C
	thumb_func_end sub_808DF2C

	thumb_func_start sub_808DF44
sub_808DF44:
	push {r4-r7,lr}
	adds r5, r0, 0
	adds r4, r1, 0
	ldrh r0, [r4]
	strh r0, [r5]
	ldrb r0, [r4, 0x3]
	strb r0, [r5, 0x3]
	ldrh r0, [r4, 0x8]
	strh r0, [r5, 0x14]
	ldr r0, [r4, 0x4C]
	str r0, [r5, 0x20]
	ldr r0, [r4, 0x4]
	str r0, [r5, 0x4]
	ldrb r0, [r4, 0x2]
	strb r0, [r5, 0x2]
	ldrh r0, [r4, 0xE]
	strh r0, [r5, 0x8]
	adds r0, r4, 0
	adds r0, 0x50
	ldrb r1, [r0]
	adds r0, r5, 0
	adds r0, 0x24
	strb r1, [r0]
	ldrh r0, [r4, 0x12]
	strh r0, [r5, 0x16]
	adds r2, r4, 0
	adds r2, 0x14
	adds r1, r5, 0
	adds r1, 0x18
	movs r3, 0x1
_0808DF80:
	ldrb r0, [r2]
	strb r0, [r1]
	ldrb r0, [r2, 0x2]
	strb r0, [r1, 0x2]
	adds r2, 0x1
	adds r1, 0x1
	subs r3, 0x1
	cmp r3, 0
	bge _0808DF80
	ldr r0, [r4, 0x18]
	str r0, [r5, 0x1C]
	adds r0, r5, 0
	adds r0, 0x2C
	adds r1, r4, 0
	adds r1, 0x1C
	bl sub_8093FA8
	movs r3, 0
	adds r7, r4, 0
	adds r7, 0x40
	adds r6, r5, 0
	adds r6, 0x28
	adds r5, 0x4C
	adds r2, r4, 0
	adds r2, 0x58
_0808DFB2:
	adds r0, r5, r3
	adds r1, r2, r3
	ldrb r1, [r1]
	strb r1, [r0]
	adds r3, 0x1
	cmp r3, 0x9
	ble _0808DFB2
	ldrb r0, [r7]
	movs r1, 0x1
	ands r1, r0
	cmp r1, 0
	beq _0808DFD4
	adds r0, r6, 0
	adds r1, r7, 0
	bl sub_8090BB0
	b _0808DFD6
_0808DFD4:
	strb r1, [r6]
_0808DFD6:
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_808DF44

	thumb_func_start sub_808DFDC
sub_808DFDC:
	push {lr}
	ldr r3, _0808E000
	movs r2, 0x58
	muls r2, r0
	ldr r0, [r3]
	adds r3, r0, r2
	adds r1, 0x40
	ldrb r0, [r1]
	movs r2, 0x1
	ands r2, r0
	cmp r2, 0
	beq _0808E004
	adds r0, r3, 0
	adds r0, 0x28
	bl sub_8090BB0
	b _0808E00A
	.align 2, 0
_0808E000: .4byte gUnknown_203B45C
_0808E004:
	adds r0, r3, 0
	adds r0, 0x28
	strb r2, [r0]
_0808E00A:
	pop {r0}
	bx r0
	thumb_func_end sub_808DFDC

	thumb_func_start sub_808E010
sub_808E010:
	push {r4-r6,lr}
	sub sp, 0xC
	adds r6, r0, 0
	adds r5, r2, 0
	lsls r1, 16
	asrs r2, r1, 16
	ldr r1, _0808E06C
	movs r3, 0
	ldrsh r0, [r1, r3]
	cmp r0, r2
	beq _0808E04A
	strh r2, [r1]
	ldr r1, _0808E070
	mov r0, sp
	bl sprintf
	ldr r1, _0808E074
	mov r0, sp
	bl OpenFileAndGetFileDataPtr
	adds r4, r0, 0
	ldr r0, _0808E078
	movs r1, 0
	adds r2, r4, 0
	bl sub_800AAA8
	adds r0, r4, 0
	bl CloseFile
_0808E04A:
	subs r5, 0x1
	cmp r5, 0
	bge _0808E052
	movs r5, 0
_0808E052:
	ldr r0, _0808E078
	lsls r1, r5, 1
	adds r1, r5
	lsls r1, 2
	adds r2, r6, 0
	adds r1, r0
	ldm r1!, {r0,r3,r4}
	stm r2!, {r0,r3,r4}
	add sp, 0xC
	pop {r4-r6}
	pop {r0}
	bx r0
	.align 2, 0
_0808E06C: .4byte gUnknown_20384E8
_0808E070: .4byte gUnknown_810768C
_0808E074: .4byte gUnknown_8300500
_0808E078: .4byte gUnknown_20384F0
	thumb_func_end sub_808E010

	thumb_func_start sub_808E07C
sub_808E07C:
	push {r4,lr}
	adds r2, r0, 0
	adds r4, r1, 0
	ldrb r1, [r2]
	adds r2, 0x1
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	beq _0808E094
	ldrb r3, [r2]
	adds r2, 0x1
	b _0808E098
_0808E094:
	adds r3, r1, 0
	movs r1, 0
_0808E098:
	movs r0, 0x7F
	ands r3, r0
	ands r1, r0
	lsls r0, r1, 7
	orrs r0, r3
	strh r0, [r4]
	adds r0, r2, 0
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_808E07C

	thumb_func_start sub_808E0AC
sub_808E0AC:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x4
	adds r6, r0, 0
	mov r8, r2
	adds r5, r3, 0
	lsls r1, 16
	asrs r1, 16
	adds r2, r1, 0
	movs r7, 0
	ldr r0, _0808E0DC
	cmp r1, r0
	beq _0808E0D8
	cmp r1, 0
	beq _0808E0D8
	movs r0, 0xD2
	lsls r0, 1
	cmp r1, r0
	bne _0808E0E0
_0808E0D8:
	movs r0, 0
	b _0808E170
	.align 2, 0
_0808E0DC: .4byte 0x000001a5
_0808E0E0:
	adds r0, r2, 0
	bl sub_8092B18
	adds r1, r0, 0
	mov r4, sp
	movs r0, 0x88
	lsls r0, 1
	mov r10, r0
	movs r3, 0xB1
	lsls r3, 1
	mov r9, r3
	b _0808E156
_0808E0F8:
	cmp r0, r8
	bne _0808E156
	movs r2, 0x1
	ldrh r0, [r4]
	cmp r0, 0xEE
	bne _0808E110
	ldr r0, _0808E180
	movs r3, 0
	ldrsh r0, [r0, r3]
	cmp r5, r0
	bge _0808E110
	movs r2, 0
_0808E110:
	ldrh r0, [r4]
	cmp r0, 0xEF
	bne _0808E122
	ldr r0, _0808E184
	movs r3, 0
	ldrsh r0, [r0, r3]
	cmp r5, r0
	bge _0808E122
	movs r2, 0
_0808E122:
	ldrh r0, [r4]
	cmp r0, r10
	bne _0808E134
	ldr r0, _0808E188
	movs r3, 0
	ldrsh r0, [r0, r3]
	cmp r5, r0
	bge _0808E134
	movs r2, 0
_0808E134:
	ldrh r0, [r4]
	cmp r0, r9
	bne _0808E146
	ldr r0, _0808E18C
	movs r3, 0
	ldrsh r0, [r0, r3]
	cmp r5, r0
	bge _0808E146
	movs r2, 0
_0808E146:
	cmp r2, 0
	beq _0808E156
	cmp r7, 0xF
	bgt _0808E156
	ldrh r0, [r4]
	strh r0, [r6]
	adds r6, 0x2
	adds r7, 0x1
_0808E156:
	ldrb r0, [r1]
	cmp r0, 0
	beq _0808E16E
	adds r0, r1, 0
	mov r1, sp
	bl sub_808E07C
	adds r1, r0, 0
	ldrb r0, [r1]
	adds r1, 0x1
	cmp r0, r8
	ble _0808E0F8
_0808E16E:
	adds r0, r7, 0
_0808E170:
	add sp, 0x4
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	.align 2, 0
_0808E180: .4byte gUnknown_810ACB8
_0808E184: .4byte gUnknown_810ACBA
_0808E188: .4byte gUnknown_810ACBC
_0808E18C: .4byte gUnknown_810ACBE
	thumb_func_end sub_808E0AC

	thumb_func_start sub_808E190
sub_808E190:
	push {r4,r5,lr}
	sub sp, 0x4
	lsls r0, 16
	lsrs r5, r0, 16
	lsls r1, 16
	asrs r4, r1, 16
	ldr r0, _0808E1B8
	cmp r4, r0
	beq _0808E20C
	cmp r4, 0
	beq _0808E20C
	movs r0, 0xD2
	lsls r0, 1
	cmp r4, r0
	beq _0808E20C
	movs r0, 0xB0
	lsls r0, 1
	cmp r5, r0
	bne _0808E1C0
	b _0808E20C
	.align 2, 0
_0808E1B8: .4byte 0x000001a5
_0808E1BC:
	movs r0, 0x1
	b _0808E20E
_0808E1C0:
	adds r0, r4, 0
	bl sub_8092B18
	adds r1, r0, 0
	b _0808E1DE
_0808E1CA:
	adds r0, r1, 0
	mov r1, sp
	bl sub_808E07C
	adds r1, r0, 0
	adds r1, 0x1
	mov r0, sp
	ldrh r0, [r0]
	cmp r5, r0
	beq _0808E1BC
_0808E1DE:
	ldrb r0, [r1]
	cmp r0, 0
	bne _0808E1CA
	adds r0, r4, 0
	bl sub_8092B54
	adds r1, r0, 0
	ldrb r0, [r1]
	cmp r0, 0
	beq _0808E20C
	mov r4, sp
	adds r4, 0x2
_0808E1F6:
	adds r0, r1, 0
	adds r1, r4, 0
	bl sub_808E07C
	adds r1, r0, 0
	ldrh r0, [r4]
	cmp r0, r5
	beq _0808E1BC
	ldrb r0, [r1]
	cmp r0, 0
	bne _0808E1F6
_0808E20C:
	movs r0, 0
_0808E20E:
	add sp, 0x4
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_808E190

	thumb_func_start sub_808E218
sub_808E218:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x1C
	mov r10, r0
	mov r8, r1
	movs r0, 0
	mov r9, r0
	movs r0, 0xCF
	lsls r0, 2
	add r0, r10
	mov r1, r9
	str r1, [r0]
	mov r2, r8
	movs r3, 0x8
	ldrsh r1, [r2, r3]
	ldr r0, _0808E254
	cmp r1, r0
	beq _0808E24E
	cmp r1, 0
	beq _0808E24E
	movs r0, 0xD2
	lsls r0, 1
	cmp r1, r0
	bne _0808E258
_0808E24E:
	movs r0, 0
	b _0808E396
	.align 2, 0
_0808E254: .4byte 0x000001a5
_0808E258:
	mov r0, r8
	mov r1, sp
	bl sub_808E3B8
	str r0, [sp, 0x10]
	movs r5, 0
	cmp r9, r0
	blt _0808E26A
	b _0808E38A
_0808E26A:
	lsls r4, r5, 2
	mov r1, sp
	adds r0, r1, r4
	movs r2, 0
	ldrsh r0, [r0, r2]
	bl sub_8092B18
	adds r6, r0, 0
	str r4, [sp, 0x18]
	adds r5, 0x1
	str r5, [sp, 0x14]
	b _0808E35E
_0808E282:
	movs r0, 0xCE
	lsls r0, 1
	cmp r9, r0
	bgt _0808E35E
	movs r7, 0x1
	ldrh r0, [r4]
	cmp r0, 0xEE
	bne _0808E2A4
	ldr r0, _0808E3A8
	mov r3, r8
	movs r4, 0x14
	ldrsh r1, [r3, r4]
	movs r2, 0
	ldrsh r0, [r0, r2]
	cmp r1, r0
	bge _0808E2A4
	movs r7, 0
_0808E2A4:
	mov r3, r12
	ldrh r0, [r3]
	cmp r0, 0xEF
	bne _0808E2BE
	ldr r0, _0808E3AC
	mov r4, r8
	movs r2, 0x14
	ldrsh r1, [r4, r2]
	movs r3, 0
	ldrsh r0, [r0, r3]
	cmp r1, r0
	bge _0808E2BE
	movs r7, 0
_0808E2BE:
	mov r4, r12
	ldrh r1, [r4]
	movs r0, 0x88
	lsls r0, 1
	cmp r1, r0
	bne _0808E2DC
	ldr r0, _0808E3B0
	mov r2, r8
	movs r3, 0x14
	ldrsh r1, [r2, r3]
	movs r4, 0
	ldrsh r0, [r0, r4]
	cmp r1, r0
	bge _0808E2DC
	movs r7, 0
_0808E2DC:
	mov r0, r12
	ldrh r1, [r0]
	movs r0, 0xB1
	lsls r0, 1
	cmp r1, r0
	bne _0808E2FA
	ldr r0, _0808E3B4
	mov r2, r8
	movs r3, 0x14
	ldrsh r1, [r2, r3]
	movs r4, 0
	ldrsh r0, [r0, r4]
	cmp r1, r0
	bge _0808E2FA
	movs r7, 0
_0808E2FA:
	movs r4, 0x1
	mov r5, r12
	mov r2, r8
	adds r2, 0x2C
	movs r3, 0x3
_0808E304:
	ldrb r1, [r2]
	adds r0, r4, 0
	ands r0, r1
	cmp r0, 0
	beq _0808E318
	ldrh r0, [r2, 0x2]
	ldrh r1, [r5]
	cmp r0, r1
	bne _0808E318
	movs r7, 0
_0808E318:
	adds r2, 0x8
	subs r3, 0x1
	cmp r3, 0
	bge _0808E304
	cmp r7, 0
	beq _0808E35E
	movs r2, 0
	cmp r2, r9
	bge _0808E34A
	mov r3, r10
	ldrh r0, [r3]
	mov r4, r12
	ldrh r4, [r4]
	cmp r0, r4
	beq _0808E34A
	mov r3, r12
	mov r1, r10
_0808E33A:
	adds r1, 0x2
	adds r2, 0x1
	cmp r2, r9
	bge _0808E34A
	ldrh r0, [r1]
	ldrh r4, [r3]
	cmp r0, r4
	bne _0808E33A
_0808E34A:
	cmp r2, r9
	bne _0808E35E
	mov r1, r9
	lsls r0, r1, 1
	add r0, r10
	mov r2, r12
	ldrh r1, [r2]
	strh r1, [r0]
	movs r3, 0x1
	add r9, r3
_0808E35E:
	ldrb r0, [r6]
	cmp r0, 0
	beq _0808E380
	add r4, sp, 0xC
	adds r0, r6, 0
	adds r1, r4, 0
	bl sub_808E07C
	adds r6, r0, 0
	ldrb r0, [r6]
	adds r6, 0x1
	ldr r1, [sp, 0x18]
	add r1, sp
	ldrb r1, [r1, 0x2]
	mov r12, r4
	cmp r0, r1
	ble _0808E282
_0808E380:
	ldr r5, [sp, 0x14]
	ldr r4, [sp, 0x10]
	cmp r5, r4
	bge _0808E38A
	b _0808E26A
_0808E38A:
	movs r0, 0xCF
	lsls r0, 2
	add r0, r10
	mov r1, r9
	str r1, [r0]
	mov r0, r9
_0808E396:
	add sp, 0x1C
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	.align 2, 0
_0808E3A8: .4byte gUnknown_810ACB8
_0808E3AC: .4byte gUnknown_810ACBA
_0808E3B0: .4byte gUnknown_810ACBC
_0808E3B4: .4byte gUnknown_810ACBE
	thumb_func_end sub_808E218

	thumb_func_start sub_808E3B8
sub_808E3B8:
	push {r4-r7,lr}
	ldrh r2, [r0, 0x8]
	strh r2, [r1]
	ldrb r2, [r0, 0x3]
	strb r2, [r1, 0x2]
	movs r7, 0x1
	movs r3, 0x8
	ldrsh r2, [r0, r3]
	movs r6, 0
	adds r5, r0, 0
	adds r5, 0xC
	adds r4, r1, 0x4
	b _0808E3E0
_0808E3D2:
	strh r2, [r4]
	ldrb r0, [r5]
	strb r0, [r4, 0x2]
	adds r4, 0x4
	adds r7, 0x1
	adds r5, 0x4
	adds r6, 0x1
_0808E3E0:
	cmp r6, 0x1
	bgt _0808E3F8
	ldrb r0, [r5]
	cmp r0, 0
	beq _0808E3F8
	adds r0, r2, 0
	bl sub_808DC0C
	lsls r0, 16
	asrs r2, r0, 16
	cmp r2, 0
	bne _0808E3D2
_0808E3F8:
	adds r0, r7, 0
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_808E3B8

	thumb_func_start sub_808E400
sub_808E400:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x8
	lsls r0, 16
	asrs r0, 16
	mov r9, r0
	lsls r2, 24
	lsrs r2, 24
	str r2, [sp]
	lsls r3, 24
	lsrs r3, 24
	str r3, [sp, 0x4]
	movs r0, 0
	mov r10, r0
	movs r7, 0x1
	adds r6, r1, 0
_0808E426:
	lsls r0, r7, 16
	asrs r5, r0, 16
	mov r8, r5
	adds r0, r5, 0
	bl sub_808DC0C
	lsls r0, 16
	asrs r0, 16
	cmp r9, r0
	bne _0808E46C
	ldr r0, [sp]
	cmp r0, 0
	bne _0808E456
	mov r0, r9
	bl sub_808DACC
	adds r4, r0, 0
	adds r0, r5, 0
	bl sub_808DACC
	lsls r4, 24
	lsls r0, 24
	cmp r4, r0
	bne _0808E46C
_0808E456:
	ldr r0, [sp, 0x4]
	cmp r0, 0
	bne _0808E462
	ldr r0, _0808E488
	cmp r5, r0
	beq _0808E46C
_0808E462:
	mov r0, r8
	strh r0, [r6]
	adds r6, 0x2
	movs r0, 0x1
	add r10, r0
_0808E46C:
	adds r7, 0x1
	ldr r0, _0808E48C
	cmp r7, r0
	ble _0808E426
	mov r0, r10
	add sp, 0x8
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	.align 2, 0
_0808E488: .4byte 0x0000013d
_0808E48C: .4byte 0x000001a7
	thumb_func_end sub_808E400

	thumb_func_start sub_808E490
sub_808E490:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0x20
	mov r8, r0
	lsls r1, 16
	asrs r1, 16
	ldr r3, _0808E4F8
	mov r0, sp
	movs r2, 0x1
	bl sub_808E0AC
	adds r7, r0, 0
	cmp r7, 0
	bne _0808E4B8
	movs r7, 0x1
	mov r1, sp
	movs r0, 0xCC
	lsls r0, 1
	strh r0, [r1]
_0808E4B8:
	movs r4, 0
	cmp r4, r7
	bge _0808E4D8
	mov r6, sp
	mov r5, r8
	adds r4, r7, 0
_0808E4C4:
	ldrh r1, [r6]
	adds r0, r5, 0
	bl sub_8092AD4
	adds r6, 0x2
	adds r5, 0x8
	subs r4, 0x1
	cmp r4, 0
	bne _0808E4C4
	adds r4, r7, 0
_0808E4D8:
	cmp r4, 0x3
	bgt _0808E4EC
	movs r1, 0
	lsls r0, r4, 3
	add r0, r8
_0808E4E2:
	strb r1, [r0]
	adds r0, 0x8
	adds r4, 0x1
	cmp r4, 0x3
	ble _0808E4E2
_0808E4EC:
	add sp, 0x20
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_0808E4F8: .4byte 0x000003e7
	thumb_func_end sub_808E490

	thumb_func_start sub_808E4FC
sub_808E4FC:
	push {lr}
	sub sp, 0x10
	ldr r1, _0808E518
	lsls r0, 2
	adds r0, r1
	ldr r0, [r0]
	mov r1, sp
	bl sub_8097DF0
	ldr r0, [sp]
	ldr r0, [r0]
	add sp, 0x10
	pop {r1}
	bx r1
	.align 2, 0
_0808E518: .4byte gUnknown_810D628
	thumb_func_end sub_808E4FC

	thumb_func_start sub_808E51C
sub_808E51C:
	push {lr}
	sub sp, 0x10
	ldr r1, _0808E538
	lsls r0, 2
	adds r0, r1
	ldr r0, [r0]
	mov r1, sp
	bl sub_8097DF0
	ldr r0, [sp]
	ldr r0, [r0, 0x4]
	add sp, 0x10
	pop {r1}
	bx r1
	.align 2, 0
_0808E538: .4byte gUnknown_810D628
	thumb_func_end sub_808E51C

	thumb_func_start sub_808E53C
sub_808E53C:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x4
	mov r8, r0
	str r1, [sp]
	ldr r0, _0808E628
	ldr r1, _0808E62C
	bl OpenFileAndGetFileDataPtr
	adds r7, r0, 0
	ldr r4, [r7, 0x4]
	movs r6, 0x7
	adds r4, 0x4
	mov r1, r8
	lsls r0, r1, 5
	ldr r2, _0808E630
	adds r5, r0, r2
_0808E564:
	adds r0, r5, 0
	adds r1, r4, 0
	movs r2, 0x20
	bl CpuCopy
	adds r5, 0x20
	adds r4, 0x20
	subs r6, 0x1
	cmp r6, 0
	bne _0808E564
	adds r0, r7, 0
	bl CloseFile
	movs r6, 0
	movs r0, 0x3
	mov r12, r0
	ldr r1, _0808E634
	mov r10, r1
	ldr r2, _0808E638
	mov r9, r2
	ldr r5, _0808E63C
	movs r7, 0
	mov r4, r12
	ldr r0, [sp]
	ands r4, r0
	lsls r4, 10
_0808E598:
	lsls r3, r6, 3
	ldr r0, _0808E640
	adds r3, r0
	ldrh r1, [r3]
	ldr r0, _0808E644
	ands r0, r1
	ldr r1, _0808E648
	ands r0, r1
	mov r2, r10
	ands r0, r2
	ldr r1, _0808E64C
	ands r0, r1
	ldr r1, _0808E650
	ands r0, r1
	strh r0, [r3]
	ldr r1, [r5]
	mov r2, r12
	ands r1, r2
	lsls r1, 14
	mov r2, r9
	ands r0, r2
	orrs r0, r1
	strh r0, [r3]
	ldrh r0, [r3, 0x2]
	ldr r1, _0808E654
	ands r1, r0
	strh r1, [r3, 0x2]
	ldr r0, _0808E63C
	adds r0, 0x4
	adds r0, r7, r0
	ldr r0, [r0]
	mov r2, r12
	ands r0, r2
	lsls r0, 14
	mov r2, r9
	ands r1, r2
	orrs r1, r0
	strh r1, [r3, 0x2]
	ldr r1, [r5, 0x8]
	add r1, r8
	ldr r0, _0808E658
	ands r1, r0
	ldrh r2, [r3, 0x4]
	movs r0, 0xFC
	lsls r0, 8
	ands r0, r2
	orrs r0, r1
	mov r1, r10
	ands r0, r1
	orrs r0, r4
	ldr r1, _0808E65C
	ands r0, r1
	strh r0, [r3, 0x4]
	ldrh r1, [r3, 0x6]
	ldr r0, _0808E660
	ands r0, r1
	ldr r1, _0808E664
	ands r0, r1
	strh r0, [r3, 0x6]
	adds r5, 0xC
	adds r7, 0xC
	adds r6, 0x1
	cmp r6, 0x2
	ble _0808E598
	add sp, 0x4
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_0808E628: .4byte gUnknown_81076BC
_0808E62C: .4byte gUnknown_83B0000
_0808E630: .4byte 0x06010000
_0808E634: .4byte 0x0000f3ff
_0808E638: .4byte 0x00003fff
_0808E63C: .4byte gUnknown_8107698
_0808E640: .4byte gUnknown_202F3E8
_0808E644: .4byte 0x0000feff
_0808E648: .4byte 0x0000fdff
_0808E64C: .4byte 0x0000efff
_0808E650: .4byte 0x0000dfff
_0808E654: .4byte 0x0000c1ff
_0808E658: .4byte 0x000003ff
_0808E65C: .4byte 0x00000fff
_0808E660: .4byte 0x0000fffe
_0808E664: .4byte 0x0000fffd
	thumb_func_end sub_808E53C

	thumb_func_start sub_808E668
sub_808E668:
	push {r4,r5,lr}
	adds r4, r1, 0
	adds r5, r2, 0
	lsls r0, 16
	asrs r1, r0, 16
	ldr r2, _0808E6E0
	adds r0, r2
	lsrs r0, 16
	cmp r0, 0x1
	bls _0808E6D6
	adds r0, r1, 0
	bl sub_808DAE4
	lsls r0, 24
	lsrs r0, 24
	movs r3, 0
	ldrsh r2, [r4, r3]
	movs r3, 0x10
	ldrsh r1, [r5, r3]
	adds r2, r1
	movs r1, 0x2
	ldrsh r3, [r4, r1]
	movs r4, 0x12
	ldrsh r1, [r5, r4]
	adds r3, r1
	ldr r4, _0808E6E4
	lsls r1, r0, 2
	adds r1, r4
	ldr r1, [r1]
	adds r2, r1
	subs r3, 0x4
	ldr r1, _0808E6E8
	ands r2, r1
	lsls r0, 3
	ldr r1, _0808E6EC
	adds r0, r1
	ldrh r4, [r0, 0x2]
	movs r1, 0xFE
	lsls r1, 8
	ands r1, r4
	orrs r1, r2
	strh r1, [r0, 0x2]
	ldr r1, _0808E6F0
	ands r3, r1
	lsls r3, 4
	ldrh r2, [r0, 0x6]
	movs r1, 0xF
	ands r1, r2
	orrs r1, r3
	strh r1, [r0, 0x6]
	movs r1, 0
	movs r2, 0
	movs r3, 0
	bl AddSprite
_0808E6D6:
	movs r0, 0x1
	pop {r4,r5}
	pop {r1}
	bx r1
	.align 2, 0
_0808E6E0: .4byte 0xffce0000
_0808E6E4: .4byte gUnknown_81076C4
_0808E6E8: .4byte 0x000001ff
_0808E6EC: .4byte gUnknown_202F3E8
_0808E6F0: .4byte 0x00000fff
	thumb_func_end sub_808E668

	thumb_func_start sub_808E6F4
sub_808E6F4:
	push {r4,r5,lr}
	adds r5, r0, 0
	movs r0, 0xA
	bl RandomCapped
	ldr r1, _0808E70C
	lsls r0, 2
	adds r0, r1
	ldr r0, [r0]
	strh r0, [r5]
	movs r4, 0
	b _0808E712
	.align 2, 0
_0808E70C: .4byte gUnknown_810AC90
_0808E710:
	adds r4, 0x1
_0808E712:
	cmp r4, 0x63
	bgt _0808E724
	movs r0, 0x12
	bl RandomCapped
	strb r0, [r5, 0x2]
	lsls r0, 24
	cmp r0, 0
	beq _0808E710
_0808E724:
	cmp r4, 0x64
	bne _0808E72C
	movs r0, 0x2
	strb r0, [r5, 0x2]
_0808E72C:
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_808E6F4

	thumb_func_start sub_808E734
sub_808E734:
	push {r4-r6,lr}
	lsls r0, 16
	asrs r4, r0, 16
	movs r3, 0
	ldr r0, _0808E75C
	ldr r2, [r0]
	movs r6, 0x1
	movs r5, 0xCE
	lsls r5, 1
_0808E746:
	ldrb r1, [r2]
	adds r0, r6, 0
	ands r0, r1
	cmp r0, 0
	beq _0808E760
	movs r1, 0x8
	ldrsh r0, [r2, r1]
	cmp r0, r4
	bne _0808E760
	movs r0, 0x1
	b _0808E76A
	.align 2, 0
_0808E75C: .4byte gUnknown_203B45C
_0808E760:
	adds r2, 0x58
	adds r3, 0x1
	cmp r3, r5
	ble _0808E746
	movs r0, 0
_0808E76A:
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end sub_808E734

	thumb_func_start sub_808E770
sub_808E770:
	push {lr}
	lsls r0, 16
	asrs r1, r0, 16
	ldr r0, _0808E788
	cmp r1, r0
	beq _0808E792
	movs r0, 0xBD
	lsls r0, 1
	cmp r1, r0
	bne _0808E78C
	subs r0, 0x2
	b _0808E854
	.align 2, 0
_0808E788: .4byte 0x00000179
_0808E78C:
	ldr r0, _0808E798
	cmp r1, r0
	bne _0808E79C
_0808E792:
	movs r0, 0xBC
	lsls r0, 1
	b _0808E854
	.align 2, 0
_0808E798: .4byte 0x0000017b
_0808E79C:
	cmp r1, 0xCA
	beq _0808E80E
	cmp r1, 0xCB
	beq _0808E80E
	cmp r1, 0xCC
	beq _0808E80E
	cmp r1, 0xCD
	beq _0808E80E
	cmp r1, 0xCE
	beq _0808E80E
	cmp r1, 0xCF
	beq _0808E80E
	cmp r1, 0xD0
	beq _0808E80E
	cmp r1, 0xD1
	beq _0808E80E
	cmp r1, 0xD2
	beq _0808E80E
	cmp r1, 0xD3
	beq _0808E80E
	cmp r1, 0xD4
	beq _0808E80E
	cmp r1, 0xD5
	beq _0808E80E
	cmp r1, 0xD6
	beq _0808E80E
	cmp r1, 0xD7
	beq _0808E80E
	cmp r1, 0xD8
	beq _0808E80E
	cmp r1, 0xD9
	beq _0808E80E
	cmp r1, 0xDA
	beq _0808E80E
	cmp r1, 0xDB
	beq _0808E80E
	cmp r1, 0xDC
	beq _0808E80E
	cmp r1, 0xDD
	beq _0808E80E
	cmp r1, 0xDE
	beq _0808E80E
	cmp r1, 0xDF
	beq _0808E80E
	cmp r1, 0xE0
	beq _0808E80E
	cmp r1, 0xE1
	beq _0808E80E
	cmp r1, 0xE2
	beq _0808E80E
	ldr r0, _0808E814
	cmp r1, r0
	beq _0808E80E
	movs r0, 0xD0
	lsls r0, 1
	cmp r1, r0
	bne _0808E818
_0808E80E:
	movs r0, 0xC9
	b _0808E854
	.align 2, 0
_0808E814: .4byte 0x0000019f
_0808E818:
	ldr r0, _0808E82C
	cmp r1, r0
	beq _0808E836
	movs r0, 0xD1
	lsls r0, 1
	cmp r1, r0
	bne _0808E830
	subs r0, 0x4
	b _0808E854
	.align 2, 0
_0808E82C: .4byte 0x000001a1
_0808E830:
	ldr r0, _0808E83C
	cmp r1, r0
	bne _0808E840
_0808E836:
	movs r0, 0xCF
	lsls r0, 1
	b _0808E854
	.align 2, 0
_0808E83C: .4byte 0x000001a3
_0808E840:
	ldr r0, _0808E84C
	cmp r1, r0
	beq _0808E850
	adds r0, r1, 0
	b _0808E854
	.align 2, 0
_0808E84C: .4byte 0x000001a7
_0808E850:
	movs r0, 0xCE
	lsls r0, 1
_0808E854:
	pop {r1}
	bx r1
	thumb_func_end sub_808E770

	thumb_func_start sub_808E858
sub_808E858:
	push {lr}
	lsls r0, 16
	asrs r1, r0, 16
	adds r2, r1, 0
	ldr r0, _0808E874
	cmp r1, r0
	beq _0808E87E
	movs r0, 0xBD
	lsls r0, 1
	cmp r1, r0
	bne _0808E878
	subs r0, 0x2
	b _0808E8C4
	.align 2, 0
_0808E874: .4byte 0x00000179
_0808E878:
	ldr r0, _0808E884
	cmp r1, r0
	bne _0808E888
_0808E87E:
	movs r0, 0xBC
	lsls r0, 1
	b _0808E8C4
	.align 2, 0
_0808E884: .4byte 0x0000017b
_0808E888:
	ldr r0, _0808E89C
	cmp r1, r0
	beq _0808E8A6
	movs r0, 0xD1
	lsls r0, 1
	cmp r1, r0
	bne _0808E8A0
	subs r0, 0x4
	b _0808E8C4
	.align 2, 0
_0808E89C: .4byte 0x000001a1
_0808E8A0:
	ldr r0, _0808E8AC
	cmp r1, r0
	bne _0808E8B0
_0808E8A6:
	movs r0, 0xCF
	lsls r0, 1
	b _0808E8C4
	.align 2, 0
_0808E8AC: .4byte 0x000001a3
_0808E8B0:
	ldr r0, _0808E8BC
	cmp r2, r0
	beq _0808E8C0
	adds r0, r2, 0
	b _0808E8C4
	.align 2, 0
_0808E8BC: .4byte 0x000001a7
_0808E8C0:
	movs r0, 0xCE
	lsls r0, 1
_0808E8C4:
	pop {r1}
	bx r1
	thumb_func_end sub_808E858

	thumb_func_start sub_808E8C8
sub_808E8C8:
	push {lr}
	lsls r0, 16
	asrs r1, r0, 16
	cmp r1, 0xCA
	bne _0808E8D6
	movs r0, 0x1
	b _0808E9B2
_0808E8D6:
	cmp r1, 0xCB
	bne _0808E8DE
	movs r0, 0x2
	b _0808E9B2
_0808E8DE:
	cmp r1, 0xCC
	bne _0808E8E6
	movs r0, 0x3
	b _0808E9B2
_0808E8E6:
	cmp r1, 0xCD
	bne _0808E8EE
	movs r0, 0x4
	b _0808E9B2
_0808E8EE:
	cmp r1, 0xCE
	bne _0808E8F6
	movs r0, 0x5
	b _0808E9B2
_0808E8F6:
	cmp r1, 0xCF
	bne _0808E8FE
	movs r0, 0x6
	b _0808E9B2
_0808E8FE:
	cmp r1, 0xD0
	bne _0808E906
	movs r0, 0x7
	b _0808E9B2
_0808E906:
	cmp r1, 0xD1
	bne _0808E90E
	movs r0, 0x8
	b _0808E9B2
_0808E90E:
	cmp r1, 0xD2
	bne _0808E916
	movs r0, 0x9
	b _0808E9B2
_0808E916:
	cmp r1, 0xD3
	bne _0808E91E
	movs r0, 0xA
	b _0808E9B2
_0808E91E:
	cmp r1, 0xD4
	bne _0808E926
	movs r0, 0xB
	b _0808E9B2
_0808E926:
	cmp r1, 0xD5
	bne _0808E92E
	movs r0, 0xC
	b _0808E9B2
_0808E92E:
	cmp r1, 0xD6
	bne _0808E936
	movs r0, 0xD
	b _0808E9B2
_0808E936:
	cmp r1, 0xD7
	bne _0808E93E
	movs r0, 0xE
	b _0808E9B2
_0808E93E:
	cmp r1, 0xD8
	bne _0808E946
	movs r0, 0xF
	b _0808E9B2
_0808E946:
	cmp r1, 0xD9
	bne _0808E94E
	movs r0, 0x10
	b _0808E9B2
_0808E94E:
	cmp r1, 0xDA
	bne _0808E956
	movs r0, 0x11
	b _0808E9B2
_0808E956:
	cmp r1, 0xDB
	bne _0808E95E
	movs r0, 0x12
	b _0808E9B2
_0808E95E:
	cmp r1, 0xDC
	bne _0808E966
	movs r0, 0x13
	b _0808E9B2
_0808E966:
	cmp r1, 0xDD
	bne _0808E96E
	movs r0, 0x14
	b _0808E9B2
_0808E96E:
	cmp r1, 0xDE
	bne _0808E976
	movs r0, 0x15
	b _0808E9B2
_0808E976:
	cmp r1, 0xDF
	bne _0808E97E
	movs r0, 0x16
	b _0808E9B2
_0808E97E:
	cmp r1, 0xE0
	bne _0808E986
	movs r0, 0x17
	b _0808E9B2
_0808E986:
	cmp r1, 0xE1
	bne _0808E98E
	movs r0, 0x18
	b _0808E9B2
_0808E98E:
	cmp r1, 0xE2
	bne _0808E996
	movs r0, 0x19
	b _0808E9B2
_0808E996:
	ldr r0, _0808E9A0
	cmp r1, r0
	bne _0808E9A4
	movs r0, 0x1A
	b _0808E9B2
	.align 2, 0
_0808E9A0: .4byte 0x0000019f
_0808E9A4:
	movs r0, 0xD0
	lsls r0, 1
	cmp r1, r0
	beq _0808E9B0
	movs r0, 0
	b _0808E9B2
_0808E9B0:
	movs r0, 0x1B
_0808E9B2:
	pop {r1}
	bx r1
	thumb_func_end sub_808E8C8

	thumb_func_start sub_808E9B8
sub_808E9B8:
	ldrh r1, [r0]
	ldr r0, _0808E9C0
	ands r0, r1
	bx lr
	.align 2, 0
_0808E9C0: .4byte 0x000001ff
	thumb_func_end sub_808E9B8

	thumb_func_start sub_808E9C4
sub_808E9C4:
	lsls r1, 16
	asrs r1, 16
	ldrh r3, [r0]
	movs r2, 0xFE
	lsls r2, 8
	ands r2, r3
	orrs r2, r1
	strh r2, [r0]
	bx lr
	thumb_func_end sub_808E9C4

	thumb_func_start sub_808E9D8
sub_808E9D8:
	lsls r2, 16
	asrs r2, 16
	lsls r1, 9
	orrs r2, r1
	strh r2, [r0]
	bx lr
	thumb_func_end sub_808E9D8

	thumb_func_start sub_808E9E4
sub_808E9E4:
	ldrh r0, [r0]
	lsrs r0, 9
	bx lr
	thumb_func_end sub_808E9E4

	thumb_func_start sub_808E9EC
sub_808E9EC:
	push {r4-r6,lr}
	adds r3, r1, 0
	ldrb r2, [r0, 0x18]
	str r2, [r3]
	ldrb r1, [r0, 0x19]
	str r1, [r3, 0x4]
	ldrb r1, [r0, 0x1A]
	str r1, [r3, 0x8]
	ldrb r1, [r0, 0x1B]
	str r1, [r3, 0xC]
	movs r1, 0
	strb r1, [r3, 0x10]
	strb r1, [r3, 0x11]
	strb r1, [r3, 0x12]
	strb r1, [r3, 0x13]
	adds r1, r0, 0
	adds r1, 0x28
	ldrb r0, [r1]
	cmp r0, 0
	beq _0808EA96
	adds r4, r0, 0
	adds r5, r4, 0
	cmp r4, 0x13
	bne _0808EA2A
	ldr r1, _0808EA9C
	ldrh r0, [r1]
	strb r0, [r3, 0x10]
	movs r6, 0
	ldrsh r0, [r1, r6]
	adds r0, r2, r0
	str r0, [r3]
_0808EA2A:
	cmp r4, 0x21
	bne _0808EA42
	ldr r1, _0808EAA0
	ldrb r0, [r1]
	ldrb r2, [r3, 0x11]
	adds r0, r2
	strb r0, [r3, 0x11]
	movs r6, 0
	ldrsh r1, [r1, r6]
	ldr r0, [r3, 0x4]
	adds r0, r1
	str r0, [r3, 0x4]
_0808EA42:
	cmp r4, 0x2B
	bne _0808EA66
	ldr r2, _0808EAA4
	ldrb r0, [r2]
	ldrb r6, [r3, 0x10]
	adds r1, r0, r6
	strb r1, [r3, 0x10]
	ldrb r1, [r3, 0x11]
	adds r0, r1
	strb r0, [r3, 0x11]
	movs r6, 0
	ldrsh r1, [r2, r6]
	ldr r0, [r3]
	adds r0, r1
	str r0, [r3]
	ldr r0, [r3, 0x4]
	adds r0, r1
	str r0, [r3, 0x4]
_0808EA66:
	cmp r4, 0x1E
	bne _0808EA7E
	ldr r1, _0808EAA8
	ldrb r0, [r1]
	ldrb r2, [r3, 0x12]
	adds r0, r2
	strb r0, [r3, 0x12]
	movs r6, 0
	ldrsh r1, [r1, r6]
	ldr r0, [r3, 0x8]
	adds r0, r1
	str r0, [r3, 0x8]
_0808EA7E:
	cmp r5, 0x22
	bne _0808EA96
	ldr r1, _0808EAAC
	ldrb r0, [r1]
	ldrb r2, [r3, 0x13]
	adds r0, r2
	strb r0, [r3, 0x13]
	movs r6, 0
	ldrsh r1, [r1, r6]
	ldr r0, [r3, 0xC]
	adds r0, r1
	str r0, [r3, 0xC]
_0808EA96:
	pop {r4-r6}
	pop {r0}
	bx r0
	.align 2, 0
_0808EA9C: .4byte gUnknown_810AC60
_0808EAA0: .4byte gUnknown_810AC62
_0808EAA4: .4byte gUnknown_810AC68
_0808EAA8: .4byte gUnknown_810AC64
_0808EAAC: .4byte gUnknown_810AC66
	thumb_func_end sub_808E9EC

	thumb_func_start sub_808EAB0
sub_808EAB0:
	lsls r0, 24
	ldr r1, _0808EABC
	lsrs r0, 22
	adds r0, r1
	ldr r0, [r0]
	bx lr
	.align 2, 0
_0808EABC: .4byte gIQSkillNames
	thumb_func_end sub_808EAB0

	thumb_func_start sub_808EAC0
sub_808EAC0:
	push {lr}
	lsls r1, 24
	ldr r2, _0808EAD8
	lsrs r1, 22
	adds r1, r2
	ldr r1, [r1]
	movs r2, 0x14
	bl strncpy
	pop {r0}
	bx r0
	.align 2, 0
_0808EAD8: .4byte gUnknown_8112C14
	thumb_func_end sub_808EAC0

	thumb_func_start sub_808EADC
sub_808EADC:
	lsls r0, 24
	ldr r1, _0808EAE8
	lsrs r0, 22
	adds r0, r1
	ldr r0, [r0]
	bx lr
	.align 2, 0
_0808EAE8: .4byte gIQSkillDescriptions
	thumb_func_end sub_808EADC

	thumb_func_start sub_808EAEC
sub_808EAEC:
	lsls r0, 24
	ldr r1, _0808EAF8
	lsrs r0, 22
	adds r0, r1
	ldr r0, [r0]
	bx lr
	.align 2, 0
_0808EAF8: .4byte gTacticsDescriptions
	thumb_func_end sub_808EAEC

	thumb_func_start sub_808EAFC
sub_808EAFC:
	lsls r0, 24
	lsrs r0, 24
	ldr r1, _0808EB08
	adds r0, r1
	ldrb r0, [r0]
	bx lr
	.align 2, 0
_0808EB08: .4byte gUnknown_810A36B
	thumb_func_end sub_808EAFC

	thumb_func_start sub_808EB0C
sub_808EB0C:
	push {r4-r6,lr}
	adds r4, r0, 0
	adds r5, r1, 0
	movs r2, 0
	movs r3, 0
	ldr r1, _0808EB44
_0808EB18:
	movs r6, 0
	ldrsh r0, [r1, r6]
	cmp r0, r5
	bgt _0808EB26
	adds r0, r4, r2
	strb r3, [r0]
	adds r2, 0x1
_0808EB26:
	adds r1, 0x2
	adds r3, 0x1
	cmp r3, 0xB
	ble _0808EB18
	cmp r2, 0xB
	bgt _0808EB3E
	movs r1, 0xB
_0808EB34:
	adds r0, r4, r2
	strb r1, [r0]
	adds r2, 0x1
	cmp r2, 0xB
	ble _0808EB34
_0808EB3E:
	pop {r4-r6}
	pop {r0}
	bx r0
	.align 2, 0
_0808EB44: .4byte gUnknown_810A378
	thumb_func_end sub_808EB0C

	thumb_func_start sub_808EB48
sub_808EB48:
	push {r4-r7,lr}
	adds r4, r1, 0
	movs r6, 0x1
	movs r5, 0
	adds r2, r0, 0
	ldr r1, _0808EB64
	movs r3, 0xB
_0808EB56:
	movs r7, 0
	ldrsh r0, [r1, r7]
	cmp r0, r4
	bgt _0808EB68
	strb r6, [r2]
	b _0808EB6A
	.align 2, 0
_0808EB64: .4byte gUnknown_810A378
_0808EB68:
	strb r5, [r2]
_0808EB6A:
	adds r2, 0x1
	adds r1, 0x2
	subs r3, 0x1
	cmp r3, 0
	bge _0808EB56
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_808EB48

	thumb_func_start sub_808EB7C
sub_808EB7C:
	push {lr}
	adds r2, r0, 0
	lsls r1, 24
	lsrs r1, 24
	cmp r1, 0
	bne _0808EB8C
	movs r0, 0
	b _0808EB9E
_0808EB8C:
	movs r3, 0
	ldr r0, _0808EBA4
	lsls r1, 2
	adds r1, r0
	ldr r0, [r1]
	cmp r0, r2
	bgt _0808EB9C
	movs r3, 0x1
_0808EB9C:
	adds r0, r3, 0
_0808EB9E:
	pop {r1}
	bx r1
	.align 2, 0
_0808EBA4: .4byte gUnknown_810A390
	thumb_func_end sub_808EB7C

	thumb_func_start sub_808EBA8
sub_808EBA8:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	adds r7, r0, 0
	mov r8, r1
	movs r6, 0
	movs r5, 0x1
_0808EBB6:
	lsls r0, r5, 24
	lsrs r4, r0, 24
	mov r0, r8
	adds r1, r4, 0
	bl sub_808EB7C
	lsls r0, 24
	cmp r0, 0
	beq _0808EBCE
	adds r0, r7, r6
	strb r4, [r0]
	adds r6, 0x1
_0808EBCE:
	adds r5, 0x1
	cmp r5, 0x17
	ble _0808EBB6
	adds r1, r6, 0
	cmp r6, 0x17
	bgt _0808EBE6
	movs r2, 0
_0808EBDC:
	adds r0, r7, r1
	strb r2, [r0]
	adds r1, 0x1
	cmp r1, 0x17
	ble _0808EBDC
_0808EBE6:
	adds r0, r6, 0
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_808EBA8

	thumb_func_start sub_808EBF4
sub_808EBF4:
	push {r4-r6,lr}
	adds r4, r0, 0
	adds r6, r1, 0
	movs r5, 0x1
	lsls r5, r6
	adds r1, r5, 0
	bl sub_808ECD0
	lsls r0, 24
	cmp r0, 0
	beq _0808EC22
	ldrb r0, [r4]
	bics r0, r5
	strb r0, [r4]
	asrs r1, r5, 8
	ldrb r0, [r4, 0x1]
	bics r0, r1
	strb r0, [r4, 0x1]
	asrs r1, r5, 16
	ldrb r0, [r4, 0x2]
	bics r0, r1
	strb r0, [r4, 0x2]
	b _0808EC2A
_0808EC22:
	adds r0, r4, 0
	adds r1, r6, 0
	bl sub_808EC30
_0808EC2A:
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end sub_808EBF4

	thumb_func_start sub_808EC30
sub_808EC30:
	push {r4-r7,lr}
	adds r3, r0, 0
	adds r7, r1, 0
	movs r4, 0
	ldr r1, _0808EC90
	lsls r0, r7, 2
	adds r0, r1
	ldr r6, [r0]
	adds r5, r1, 0
	movs r0, 0x1
	mov r12, r0
_0808EC46:
	ldr r0, [r5]
	cmp r6, r0
	bne _0808EC66
	mov r1, r12
	lsls r1, r4
	ldrb r0, [r3]
	bics r0, r1
	strb r0, [r3]
	asrs r2, r1, 8
	ldrb r0, [r3, 0x1]
	bics r0, r2
	strb r0, [r3, 0x1]
	asrs r1, 16
	ldrb r0, [r3, 0x2]
	bics r0, r1
	strb r0, [r3, 0x2]
_0808EC66:
	adds r5, 0x4
	adds r4, 0x1
	cmp r4, 0x17
	ble _0808EC46
	movs r1, 0x1
	lsls r1, r7
	ldrb r2, [r3]
	adds r0, r1, 0
	orrs r0, r2
	strb r0, [r3]
	asrs r0, r1, 8
	ldrb r2, [r3, 0x1]
	orrs r0, r2
	strb r0, [r3, 0x1]
	asrs r1, 16
	ldrb r0, [r3, 0x2]
	orrs r1, r0
	strb r1, [r3, 0x2]
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_0808EC90: .4byte gUnknown_81076E4
	thumb_func_end sub_808EC30

	thumb_func_start sub_808EC94
sub_808EC94:
	push {r4,r5,lr}
	adds r5, r0, 0
	lsls r4, r1, 24
	lsrs r4, 24
	movs r0, 0
	strb r0, [r5]
	strb r0, [r5, 0x1]
	strb r0, [r5, 0x2]
	adds r0, r5, 0
	movs r1, 0x2
	bl sub_808EC30
	adds r0, r5, 0
	movs r1, 0x3
	bl sub_808EC30
	adds r0, r5, 0
	movs r1, 0x16
	bl sub_808EC30
	cmp r4, 0
	beq _0808ECC8
	adds r0, r5, 0
	movs r1, 0x12
	bl sub_808EC30
_0808ECC8:
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_808EC94

	thumb_func_start sub_808ECD0
sub_808ECD0:
	push {lr}
	adds r2, r0, 0
	adds r3, r1, 0
	ldrb r0, [r2]
	ands r0, r3
	cmp r0, 0
	bne _0808ECF6
	ldrb r0, [r2, 0x1]
	lsrs r1, r3, 8
	ands r0, r1
	cmp r0, 0
	bne _0808ECF6
	ldrb r0, [r2, 0x2]
	lsrs r1, r3, 16
	ands r0, r1
	cmp r0, 0
	bne _0808ECF6
	movs r0, 0
	b _0808ECF8
_0808ECF6:
	movs r0, 0x1
_0808ECF8:
	pop {r1}
	bx r1
	thumb_func_end sub_808ECD0

	thumb_func_start sub_808ECFC
sub_808ECFC:
	movs r0, 0
	bx lr
	thumb_func_end sub_808ECFC

	thumb_func_start sub_808ED00
sub_808ED00:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0x10
	mov r0, sp
	bl sub_808D580
	adds r6, r0, 0
	movs r4, 0
	cmp r4, r6
	bge _0808ED44
	movs r0, 0x58
	mov r8, r0
	mov r7, sp
	movs r5, 0
	adds r4, r6, 0
_0808ED20:
	ldr r0, _0808ED70
	ldr r1, [r0]
	adds r0, r1, r5
	ldr r2, _0808ED74
	adds r0, r2
	ldm r7!, {r2}
	mov r3, r8
	muls r3, r2
	adds r2, r3, 0
	adds r1, r2
	movs r2, 0x58
	bl memcpy
	adds r5, 0x58
	subs r4, 0x1
	cmp r4, 0
	bne _0808ED20
	adds r4, r6, 0
_0808ED44:
	cmp r4, 0x3
	bgt _0808ED64
	ldr r5, _0808ED70
	ldr r3, _0808ED74
	movs r2, 0
	movs r0, 0x58
	adds r1, r4, 0
	muls r1, r0
_0808ED54:
	ldr r0, [r5]
	adds r0, r1
	adds r0, r3
	strh r2, [r0]
	adds r1, 0x58
	adds r4, 0x1
	cmp r4, 0x3
	ble _0808ED54
_0808ED64:
	add sp, 0x10
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_0808ED70: .4byte gUnknown_203B45C
_0808ED74: .4byte 0x00008f88
	thumb_func_end sub_808ED00

	thumb_func_start sub_808ED78
sub_808ED78:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x24
	adds r3, r0, 0
	adds r2, r1, 0
	add r4, sp, 0xC
	adds r0, r4, 0
	adds r1, r3, 0
	bl sub_809486C
	mov r10, r4
	mov r0, sp
	adds r0, 0x1E
	str r0, [sp, 0x20]
	add r1, sp, 0x1C
	mov r8, r1
	ldr r0, _0808EDF0
	adds r2, r0, 0
	mov r1, sp
	movs r5, 0x5
_0808EDA6:
	ldrh r0, [r1]
	orrs r0, r2
	strh r0, [r1]
	adds r1, 0x2
	subs r5, 0x1
	cmp r5, 0
	bge _0808EDA6
	movs r0, 0x1
	negs r0, r0
	ldr r1, [sp, 0x20]
	strh r0, [r1]
	movs r5, 0
	mov r4, sp
_0808EDC0:
	ldr r2, _0808EDF4
	movs r0, 0x58
	adds r1, r5, 0
	muls r1, r0
	ldr r0, [r2]
	adds r1, r0, r1
	ldrh r2, [r1]
	movs r0, 0x1
	ands r0, r2
	cmp r0, 0
	beq _0808EDF8
	movs r0, 0x2
	ands r0, r2
	cmp r0, 0
	beq _0808EDE2
	strh r5, [r4]
	adds r4, 0x2
_0808EDE2:
	ldrb r0, [r1, 0x2]
	cmp r0, 0
	beq _0808EDFA
	ldr r0, [sp, 0x20]
	strh r5, [r0]
	b _0808EDFA
	.align 2, 0
_0808EDF0: .4byte 0x0000ffff
_0808EDF4: .4byte gUnknown_203B45C
_0808EDF8:
	strb r0, [r1, 0x3]
_0808EDFA:
	mov r0, r10
	bl sub_808EFA0
	adds r5, 0x1
	movs r0, 0xCE
	lsls r0, 1
	cmp r5, r0
	ble _0808EDC0
	ldr r1, _0808EE34
	mov r9, r1
	mov r4, r10
	ldr r7, _0808EE38
	movs r6, 0
	movs r5, 0x3
_0808EE16:
	mov r1, r9
	ldr r0, [r1]
	adds r0, r6, r0
	ldr r1, _0808EE38
	adds r0, r1
	ldrb r0, [r0]
	movs r1, 0x1
	ands r1, r0
	cmp r1, 0
	beq _0808EE3C
	movs r0, 0xFF
	mov r1, r8
	strb r0, [r1]
	b _0808EE40
	.align 2, 0
_0808EE34: .4byte gUnknown_203B45C
_0808EE38: .4byte 0x00008f88
_0808EE3C:
	mov r0, r8
	strb r1, [r0]
_0808EE40:
	adds r0, r4, 0
	mov r1, r8
	movs r2, 0x1
	bl sub_809488C
	mov r0, r9
	ldr r1, [r0]
	adds r1, r7
	adds r0, r4, 0
	bl sub_808EFA0
	adds r7, 0x58
	adds r6, 0x58
	subs r5, 0x1
	cmp r5, 0
	bge _0808EE16
	mov r4, sp
	movs r5, 0x5
_0808EE64:
	mov r0, r10
	adds r1, r4, 0
	movs r2, 0x10
	bl sub_809488C
	adds r4, 0x2
	subs r5, 0x1
	cmp r5, 0
	bge _0808EE64
	mov r0, r10
	ldr r1, [sp, 0x20]
	movs r2, 0x10
	bl sub_809488C
	mov r0, r10
	bl nullsub_102
	mov r1, r10
	ldr r0, [r1, 0x8]
	add sp, 0x24
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_808ED78

	thumb_func_start sub_808EE9C
sub_808EE9C:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0x14
	adds r3, r0, 0
	adds r2, r1, 0
	mov r0, sp
	adds r1, r3, 0
	bl sub_809485C
	movs r5, 0
	add r7, sp, 0x10
	movs r0, 0x12
	add r0, sp
	mov r8, r0
	ldr r6, _0808EF10
	movs r4, 0
_0808EEBE:
	ldr r1, [r6]
	adds r1, r4
	mov r0, sp
	bl sub_808F068
	adds r4, 0x58
	adds r5, 0x1
	movs r0, 0xCE
	lsls r0, 1
	cmp r5, r0
	ble _0808EEBE
	movs r5, 0
	adds r6, r7, 0
	ldr r7, _0808EF10
_0808EEDA:
	mov r0, sp
	adds r1, r6, 0
	movs r2, 0x1
	bl sub_8094924
	movs r0, 0x58
	adds r4, r5, 0
	muls r4, r0
	ldr r1, _0808EF14
	adds r0, r4, r1
	ldr r1, [r7]
	adds r1, r0
	mov r0, sp
	bl sub_808F068
	ldrb r0, [r6]
	movs r1, 0x1
	ands r1, r0
	cmp r1, 0
	beq _0808EF18
	ldr r0, [r7]
	adds r0, r4
	ldr r2, _0808EF14
	adds r0, r2
	movs r1, 0x3
	b _0808EF20
	.align 2, 0
_0808EF10: .4byte gUnknown_203B45C
_0808EF14: .4byte 0x00008f88
_0808EF18:
	ldr r0, [r7]
	adds r0, r4
	ldr r3, _0808EF98
	adds r0, r3
_0808EF20:
	strh r1, [r0]
	adds r5, 0x1
	cmp r5, 0x3
	ble _0808EEDA
	mov r4, r8
	movs r6, 0xCE
	lsls r6, 1
	movs r5, 0x5
_0808EF30:
	mov r0, sp
	adds r1, r4, 0
	movs r2, 0x10
	bl sub_8094924
	ldrh r0, [r4]
	cmp r0, r6
	bhi _0808EF56
	ldr r0, _0808EF9C
	ldr r2, [r0]
	movs r0, 0
	ldrsh r1, [r4, r0]
	movs r0, 0x58
	muls r0, r1
	adds r2, r0
	ldrh r1, [r2]
	movs r0, 0x2
	orrs r0, r1
	strh r0, [r2]
_0808EF56:
	subs r5, 0x1
	cmp r5, 0
	bge _0808EF30
	mov r0, sp
	mov r1, r8
	movs r2, 0x10
	bl sub_8094924
	mov r2, r8
	ldrh r1, [r2]
	movs r0, 0xCE
	lsls r0, 1
	cmp r1, r0
	bhi _0808EF84
	ldr r0, _0808EF9C
	ldr r1, [r0]
	movs r3, 0
	ldrsh r2, [r2, r3]
	movs r0, 0x58
	muls r0, r2
	adds r1, r0
	movs r0, 0x1
	strb r0, [r1, 0x2]
_0808EF84:
	mov r0, sp
	bl nullsub_102
	ldr r0, [sp, 0x8]
	add sp, 0x14
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r1}
	bx r1
	.align 2, 0
_0808EF98: .4byte 0x00008f88
_0808EF9C: .4byte gUnknown_203B45C
	thumb_func_end sub_808EE9C

	thumb_func_start sub_808EFA0
sub_808EFA0:
	push {r4,r5,lr}
	adds r4, r0, 0
	adds r5, r1, 0
	adds r1, r5, 0x3
	movs r2, 0x7
	bl sub_809488C
	adds r1, r5, 0
	adds r1, 0x8
	adds r0, r4, 0
	movs r2, 0x9
	bl sub_809488C
	adds r1, r5, 0x4
	adds r0, r4, 0
	bl sub_80902F4
	adds r1, r5, 0
	adds r1, 0xC
	adds r0, r4, 0
	bl sub_808F41C
	adds r1, r5, 0
	adds r1, 0x10
	adds r0, r4, 0
	bl sub_808F41C
	adds r1, r5, 0
	adds r1, 0x14
	adds r0, r4, 0
	movs r2, 0xA
	bl sub_809488C
	adds r1, r5, 0
	adds r1, 0x16
	adds r0, r4, 0
	movs r2, 0xA
	bl sub_809488C
	adds r1, r5, 0
	adds r1, 0x18
	adds r0, r4, 0
	movs r2, 0x8
	bl sub_809488C
	adds r1, r5, 0
	adds r1, 0x19
	adds r0, r4, 0
	movs r2, 0x8
	bl sub_809488C
	adds r1, r5, 0
	adds r1, 0x1A
	adds r0, r4, 0
	movs r2, 0x8
	bl sub_809488C
	adds r1, r5, 0
	adds r1, 0x1B
	adds r0, r4, 0
	movs r2, 0x8
	bl sub_809488C
	adds r1, r5, 0
	adds r1, 0x1C
	adds r0, r4, 0
	movs r2, 0x18
	bl sub_809488C
	adds r1, r5, 0
	adds r1, 0x20
	adds r0, r4, 0
	movs r2, 0x18
	bl sub_809488C
	adds r1, r5, 0
	adds r1, 0x24
	adds r0, r4, 0
	movs r2, 0x4
	bl sub_809488C
	adds r1, r5, 0
	adds r1, 0x28
	adds r0, r4, 0
	bl sub_8091DE0
	adds r1, r5, 0
	adds r1, 0x2C
	adds r0, r4, 0
	bl sub_8094108
	adds r1, r5, 0
	adds r1, 0x4C
	adds r0, r4, 0
	movs r2, 0x50
	bl sub_809488C
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_808EFA0

	thumb_func_start sub_808F068
sub_808F068:
	push {r4-r6,lr}
	adds r5, r0, 0
	adds r4, r1, 0
	adds r0, r4, 0
	movs r1, 0
	movs r2, 0x58
	bl memset
	movs r6, 0
	movs r0, 0
	strh r0, [r4]
	strb r6, [r4, 0x2]
	adds r1, r4, 0x3
	adds r0, r5, 0
	movs r2, 0x7
	bl sub_8094924
	ldrb r0, [r4, 0x3]
	cmp r0, 0
	beq _0808F098
	ldrh r0, [r4]
	movs r1, 0x1
	orrs r0, r1
	strh r0, [r4]
_0808F098:
	adds r1, r4, 0
	adds r1, 0x8
	adds r0, r5, 0
	movs r2, 0x9
	bl sub_8094924
	adds r1, r4, 0x4
	adds r0, r5, 0
	bl sub_8090314
	adds r1, r4, 0
	adds r1, 0xC
	adds r0, r5, 0
	bl sub_808F410
	adds r1, r4, 0
	adds r1, 0x10
	adds r0, r5, 0
	bl sub_808F410
	adds r1, r4, 0
	adds r1, 0x14
	adds r0, r5, 0
	movs r2, 0xA
	bl sub_8094924
	adds r1, r4, 0
	adds r1, 0x16
	adds r0, r5, 0
	movs r2, 0xA
	bl sub_8094924
	adds r1, r4, 0
	adds r1, 0x18
	adds r0, r5, 0
	movs r2, 0x8
	bl sub_8094924
	adds r1, r4, 0
	adds r1, 0x19
	adds r0, r5, 0
	movs r2, 0x8
	bl sub_8094924
	adds r1, r4, 0
	adds r1, 0x1A
	adds r0, r5, 0
	movs r2, 0x8
	bl sub_8094924
	adds r1, r4, 0
	adds r1, 0x1B
	adds r0, r5, 0
	movs r2, 0x8
	bl sub_8094924
	adds r1, r4, 0
	adds r1, 0x1C
	adds r0, r5, 0
	movs r2, 0x18
	bl sub_8094924
	adds r1, r4, 0
	adds r1, 0x20
	adds r0, r5, 0
	movs r2, 0x18
	bl sub_8094924
	adds r1, r4, 0
	adds r1, 0x24
	adds r0, r5, 0
	movs r2, 0x4
	bl sub_8094924
	adds r1, r4, 0
	adds r1, 0x28
	adds r0, r5, 0
	bl sub_8091DC0
	adds r1, r4, 0
	adds r1, 0x2C
	adds r0, r5, 0
	bl sub_8094128
	adds r1, r4, 0
	adds r1, 0x4C
	adds r0, r5, 0
	movs r2, 0x50
	bl sub_8094924
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end sub_808F068

	thumb_func_start sub_808F154
sub_808F154:
	push {r4-r7,lr}
	sub sp, 0x14
	adds r3, r0, 0
	adds r2, r1, 0
	mov r0, sp
	adds r1, r3, 0
	bl sub_809486C
	add r2, sp, 0x10
	movs r0, 0xFF
	strb r0, [r2]
	mov r1, sp
	adds r1, 0x11
	movs r0, 0
	strb r0, [r1]
	movs r5, 0
	adds r6, r2, 0
	adds r7, r1, 0
_0808F178:
	ldr r1, _0808F2A8
	movs r0, 0x64
	muls r0, r5
	ldr r2, _0808F2AC
	adds r0, r2
	ldr r1, [r1]
	adds r4, r1, r0
	mov r0, sp
	adds r1, r4, 0
	movs r2, 0x2
	bl sub_809488C
	ldrb r0, [r4, 0x2]
	adds r1, r7, 0
	cmp r0, 0
	beq _0808F19A
	adds r1, r6, 0
_0808F19A:
	mov r0, sp
	movs r2, 0x1
	bl sub_809488C
	adds r1, r4, 0x3
	mov r0, sp
	movs r2, 0x7
	bl sub_809488C
	adds r1, r4, 0x4
	mov r0, sp
	bl sub_80902F4
	adds r1, r4, 0
	adds r1, 0x8
	mov r0, sp
	movs r2, 0xA
	bl sub_809488C
	adds r1, r4, 0
	adds r1, 0xA
	mov r0, sp
	movs r2, 0x10
	bl sub_809488C
	adds r1, r4, 0
	adds r1, 0xC
	mov r0, sp
	movs r2, 0x10
	bl sub_809488C
	adds r1, r4, 0
	adds r1, 0xE
	mov r0, sp
	movs r2, 0x9
	bl sub_809488C
	adds r1, r4, 0
	adds r1, 0x10
	mov r0, sp
	movs r2, 0xA
	bl sub_809488C
	adds r1, r4, 0
	adds r1, 0x12
	mov r0, sp
	movs r2, 0xA
	bl sub_809488C
	adds r1, r4, 0
	adds r1, 0x14
	mov r0, sp
	movs r2, 0x8
	bl sub_809488C
	adds r1, r4, 0
	adds r1, 0x15
	mov r0, sp
	movs r2, 0x8
	bl sub_809488C
	adds r1, r4, 0
	adds r1, 0x16
	mov r0, sp
	movs r2, 0x8
	bl sub_809488C
	adds r1, r4, 0
	adds r1, 0x17
	mov r0, sp
	movs r2, 0x8
	bl sub_809488C
	adds r1, r4, 0
	adds r1, 0x18
	mov r0, sp
	movs r2, 0x18
	bl sub_809488C
	adds r1, r4, 0
	adds r1, 0x1C
	mov r0, sp
	bl sub_8094184
	adds r1, r4, 0
	adds r1, 0x40
	mov r0, sp
	bl sub_8091E28
	adds r1, r4, 0
	adds r1, 0x44
	mov r0, sp
	bl sub_809449C
	adds r1, r4, 0
	adds r1, 0x48
	mov r0, sp
	bl sub_809449C
	adds r1, r4, 0
	adds r1, 0x4C
	mov r0, sp
	movs r2, 0x18
	bl sub_809488C
	adds r1, r4, 0
	adds r1, 0x50
	mov r0, sp
	movs r2, 0x4
	bl sub_809488C
	adds r1, r4, 0
	adds r1, 0x54
	mov r0, sp
	bl sub_808F448
	adds r1, r4, 0
	adds r1, 0x58
	mov r0, sp
	movs r2, 0x50
	bl sub_809488C
	adds r5, 0x1
	cmp r5, 0x3
	bgt _0808F296
	b _0808F178
_0808F296:
	mov r0, sp
	bl nullsub_102
	ldr r0, [sp, 0x8]
	add sp, 0x14
	pop {r4-r7}
	pop {r1}
	bx r1
	.align 2, 0
_0808F2A8: .4byte gUnknown_203B45C
_0808F2AC: .4byte 0x00008df8
	thumb_func_end sub_808F154

	thumb_func_start sub_808F2B0
sub_808F2B0:
	push {r4-r6,lr}
	sub sp, 0x14
	adds r3, r0, 0
	adds r2, r1, 0
	mov r0, sp
	adds r1, r3, 0
	bl sub_809485C
	movs r5, 0
	add r6, sp, 0x10
_0808F2C4:
	ldr r1, _0808F300
	movs r0, 0x64
	muls r0, r5
	ldr r2, _0808F304
	adds r0, r2
	ldr r1, [r1]
	adds r4, r1, r0
	adds r0, r4, 0
	movs r1, 0
	movs r2, 0x64
	bl memset
	mov r0, sp
	adds r1, r4, 0
	movs r2, 0x2
	bl sub_8094924
	mov r0, sp
	adds r1, r6, 0
	movs r2, 0x1
	bl sub_8094924
	ldrb r0, [r6]
	movs r2, 0x1
	adds r1, r2, 0
	ands r1, r0
	cmp r1, 0
	beq _0808F308
	strb r2, [r4, 0x2]
	b _0808F30A
	.align 2, 0
_0808F300: .4byte gUnknown_203B45C
_0808F304: .4byte 0x00008df8
_0808F308:
	strb r1, [r4, 0x2]
_0808F30A:
	adds r1, r4, 0x3
	mov r0, sp
	movs r2, 0x7
	bl sub_8094924
	adds r1, r4, 0x4
	mov r0, sp
	bl sub_8090314
	adds r1, r4, 0
	adds r1, 0x8
	mov r0, sp
	movs r2, 0xA
	bl sub_8094924
	adds r1, r4, 0
	adds r1, 0xA
	mov r0, sp
	movs r2, 0x10
	bl sub_8094924
	adds r1, r4, 0
	adds r1, 0xC
	mov r0, sp
	movs r2, 0x10
	bl sub_8094924
	adds r1, r4, 0
	adds r1, 0xE
	mov r0, sp
	movs r2, 0x9
	bl sub_8094924
	adds r1, r4, 0
	adds r1, 0x10
	mov r0, sp
	movs r2, 0xA
	bl sub_8094924
	adds r1, r4, 0
	adds r1, 0x12
	mov r0, sp
	movs r2, 0xA
	bl sub_8094924
	adds r1, r4, 0
	adds r1, 0x14
	mov r0, sp
	movs r2, 0x8
	bl sub_8094924
	adds r1, r4, 0
	adds r1, 0x15
	mov r0, sp
	movs r2, 0x8
	bl sub_8094924
	adds r1, r4, 0
	adds r1, 0x16
	mov r0, sp
	movs r2, 0x8
	bl sub_8094924
	adds r1, r4, 0
	adds r1, 0x17
	mov r0, sp
	movs r2, 0x8
	bl sub_8094924
	adds r1, r4, 0
	adds r1, 0x18
	mov r0, sp
	movs r2, 0x18
	bl sub_8094924
	adds r1, r4, 0
	adds r1, 0x1C
	mov r0, sp
	bl sub_80941FC
	adds r1, r4, 0
	adds r1, 0x40
	mov r0, sp
	bl sub_8091E00
	adds r1, r4, 0
	adds r1, 0x44
	mov r0, sp
	bl sub_809447C
	adds r1, r4, 0
	adds r1, 0x48
	mov r0, sp
	bl sub_809447C
	adds r1, r4, 0
	adds r1, 0x4C
	mov r0, sp
	movs r2, 0x18
	bl sub_8094924
	adds r1, r4, 0
	adds r1, 0x50
	mov r0, sp
	movs r2, 0x4
	bl sub_8094924
	adds r1, r4, 0
	adds r1, 0x54
	mov r0, sp
	bl sub_808F428
	adds r1, r4, 0
	adds r1, 0x58
	mov r0, sp
	movs r2, 0x50
	bl sub_8094924
	adds r5, 0x1
	cmp r5, 0x3
	bgt _0808F3FE
	b _0808F2C4
_0808F3FE:
	mov r0, sp
	bl nullsub_102
	ldr r0, [sp, 0x8]
	add sp, 0x14
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end sub_808F2B0

	thumb_func_start sub_808F410
sub_808F410:
	push {lr}
	movs r2, 0x7
	bl sub_8094924
	pop {r0}
	bx r0
	thumb_func_end sub_808F410

	thumb_func_start sub_808F41C
sub_808F41C:
	push {lr}
	movs r2, 0x7
	bl sub_809488C
	pop {r0}
	bx r0
	thumb_func_end sub_808F41C

	thumb_func_start sub_808F428
sub_808F428:
	push {r4,r5,lr}
	adds r5, r0, 0
	adds r4, r1, 0
	movs r2, 0xA
	bl sub_8094924
	adds r4, 0x2
	adds r0, r5, 0
	adds r1, r4, 0
	movs r2, 0x5
	bl sub_8094924
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_808F428

	thumb_func_start sub_808F448
sub_808F448:
	push {r4,r5,lr}
	adds r5, r0, 0
	adds r4, r1, 0
	movs r2, 0xA
	bl sub_809488C
	adds r4, 0x2
	adds r0, r5, 0
	adds r1, r4, 0
	movs r2, 0x5
	bl sub_809488C
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_808F448

	thumb_func_start sub_808F468
sub_808F468:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x20
	mov r8, r0
	adds r4, r1, 0
	lsls r2, 24
	lsrs r2, 24
	str r2, [sp, 0x14]
	movs r0, 0
	strh r0, [r4, 0x4]
	movs r0, 0x1
	str r0, [sp, 0x18]
	add r7, sp, 0xC
_0808F488:
	ldr r1, [sp, 0x18]
	lsls r0, r1, 16
	asrs r0, 16
	cmp r0, 0x41
	bne _0808F49C
	movs r0, 0x41
	adds r1, r7, 0
	bl sub_808DD48
	b _0808F4A2
_0808F49C:
	adds r1, r7, 0
	bl sub_808DD48
_0808F4A2:
	ldrh r0, [r7, 0x2]
	cmp r0, 0
	beq _0808F4B6
	mov r2, r8
	movs r3, 0x8
	ldrsh r1, [r2, r3]
	movs r2, 0
	ldrsh r0, [r7, r2]
	cmp r1, r0
	beq _0808F4C2
_0808F4B6:
	ldr r3, [sp, 0x18]
	adds r3, 0x1
	str r3, [sp, 0x18]
	ldr r0, _0808F4D4
	cmp r3, r0
	ble _0808F488
_0808F4C2:
	movs r0, 0xD4
	lsls r0, 1
	ldr r1, [sp, 0x18]
	cmp r1, r0
	bne _0808F4D8
	movs r0, 0x4
	strh r0, [r4, 0x4]
	b _0808F6EC
	.align 2, 0
_0808F4D4: .4byte 0x000001a7
_0808F4D8:
	movs r2, 0x1
	str r2, [sp, 0x18]
	movs r3, 0x8
	mov r10, r3
_0808F4E0:
	movs r0, 0
	mov r9, r0
	ldr r1, [sp, 0x18]
	lsls r0, r1, 16
	asrs r0, 16
	str r0, [sp, 0x1C]
	adds r1, r7, 0
	bl sub_808DD48
	ldrh r0, [r7, 0x2]
	cmp r0, 0
	bne _0808F4FA
	b _0808F6DE
_0808F4FA:
	mov r2, r8
	movs r3, 0x8
	ldrsh r1, [r2, r3]
	movs r2, 0
	ldrsh r0, [r7, r2]
	cmp r1, r0
	beq _0808F50A
	b _0808F6DE
_0808F50A:
	ldr r0, [sp, 0x1C]
	bl sub_808DBA8
	lsls r0, 24
	lsrs r5, r0, 24
	mov r3, r8
	movs r1, 0x8
	ldrsh r0, [r3, r1]
	bl sub_808DBA8
	lsls r0, 24
	lsrs r6, r0, 24
	adds r0, r5, 0
	mov r1, sp
	movs r2, 0
	movs r3, 0
	bl sub_8092638
	mov r0, sp
	ldrb r0, [r0, 0x4]
	cmp r0, 0
	bne _0808F544
	ldrh r0, [r4, 0x4]
	movs r1, 0x20
	orrs r0, r1
	strh r0, [r4, 0x4]
	movs r2, 0x1
	mov r9, r2
	b _0808F566
_0808F544:
	mov r0, sp
	movs r3, 0x2
	ldrsh r1, [r0, r3]
	cmp r5, r6
	bne _0808F550
	subs r1, 0x1
_0808F550:
	mov r0, sp
	movs r2, 0
	ldrsh r0, [r0, r2]
	cmp r0, r1
	bgt _0808F566
	ldrh r0, [r4, 0x4]
	movs r1, 0x40
	orrs r0, r1
	strh r0, [r4, 0x4]
	movs r3, 0x1
	mov r9, r3
_0808F566:
	ldrh r0, [r7, 0x2]
	cmp r0, 0x1
	bne _0808F588
	ldrh r2, [r4, 0x4]
	ands r0, r2
	cmp r0, 0
	beq _0808F576
	b _0808F6DE
_0808F576:
	mov r0, r8
	ldrb r1, [r0, 0x3]
	movs r3, 0x4
	ldrsh r0, [r7, r3]
	cmp r1, r0
	bge _0808F5E6
	movs r0, 0x2
	orrs r0, r2
	b _0808F5C8
_0808F588:
	cmp r0, 0x2
	bne _0808F5A8
	mov r2, r8
	movs r3, 0x14
	ldrsh r1, [r2, r3]
	movs r2, 0x4
	ldrsh r0, [r7, r2]
	cmp r1, r0
	bge _0808F5E6
	ldrh r0, [r4, 0x4]
	movs r1, 0x10
	orrs r0, r1
	strh r0, [r4, 0x4]
	movs r3, 0x1
	mov r9, r3
	b _0808F5E6
_0808F5A8:
	cmp r0, 0x3
	bne _0808F5E6
	ldr r0, [sp, 0x14]
	cmp r0, 0
	beq _0808F5D0
	ldrb r0, [r4]
	movs r2, 0x4
	ldrsh r1, [r7, r2]
	cmp r0, r1
	beq _0808F5E6
	ldrb r0, [r4, 0x1]
	cmp r0, r1
	beq _0808F5E6
	ldrh r0, [r4, 0x4]
	mov r3, r10
	orrs r0, r3
_0808F5C8:
	strh r0, [r4, 0x4]
	movs r0, 0x1
	mov r9, r0
	b _0808F5E6
_0808F5D0:
	ldrb r0, [r7, 0x4]
	bl sub_8091130
	cmp r0, 0
	bge _0808F5E6
	ldrh r0, [r4, 0x4]
	mov r1, r10
	orrs r0, r1
	strh r0, [r4, 0x4]
	movs r2, 0x1
	mov r9, r2
_0808F5E6:
	ldrh r0, [r7, 0x6]
	cmp r0, 0x4
	bne _0808F604
	ldr r3, [sp, 0x14]
	cmp r3, 0
	beq _0808F600
	ldrb r0, [r4]
	cmp r0, 0x76
	beq _0808F6CA
	ldrb r0, [r4, 0x1]
	cmp r0, 0x76
	beq _0808F6CA
	b _0808F666
_0808F600:
	movs r0, 0x76
	b _0808F672
_0808F604:
	cmp r0, 0x5
	bne _0808F614
	mov r3, r8
	ldrb r0, [r3, 0x18]
	ldrb r1, [r3, 0x1A]
	cmp r0, r1
	bhi _0808F6CA
	b _0808F6DE
_0808F614:
	cmp r0, 0x6
	bne _0808F624
	mov r2, r8
	ldrb r0, [r2, 0x18]
	ldrb r3, [r2, 0x1A]
	cmp r0, r3
	bcc _0808F6CA
	b _0808F6DE
_0808F624:
	cmp r0, 0x7
	bne _0808F634
	mov r1, r8
	ldrb r0, [r1, 0x18]
	ldrb r2, [r1, 0x1A]
	cmp r0, r2
	beq _0808F6CA
	b _0808F6DE
_0808F634:
	cmp r0, 0x8
	bne _0808F650
	ldr r3, [sp, 0x14]
	cmp r3, 0
	beq _0808F64C
	ldrb r0, [r4]
	cmp r0, 0x30
	beq _0808F6CA
	ldrb r0, [r4, 0x1]
	cmp r0, 0x30
	beq _0808F6CA
	b _0808F666
_0808F64C:
	movs r0, 0x30
	b _0808F672
_0808F650:
	cmp r0, 0x9
	bne _0808F684
	ldr r3, [sp, 0x14]
	cmp r3, 0
	beq _0808F670
	ldrb r0, [r4]
	cmp r0, 0x31
	beq _0808F6CA
	ldrb r0, [r4, 0x1]
	cmp r0, 0x31
	beq _0808F6CA
_0808F666:
	ldrh r0, [r4, 0x4]
	mov r1, r10
	orrs r0, r1
	strh r0, [r4, 0x4]
	b _0808F6DE
_0808F670:
	movs r0, 0x31
_0808F672:
	bl sub_8091130
	cmp r0, 0
	bge _0808F6CA
	ldrh r0, [r4, 0x4]
	mov r2, r10
	orrs r0, r2
	strh r0, [r4, 0x4]
	b _0808F6DE
_0808F684:
	cmp r0, 0xB
	bne _0808F694
	ldrb r1, [r4, 0x2]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _0808F6CA
	b _0808F6DE
_0808F694:
	cmp r0, 0xC
	bne _0808F6A4
	ldrb r1, [r4, 0x2]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	bne _0808F6CA
	b _0808F6DE
_0808F6A4:
	cmp r0, 0xA
	bne _0808F6CA
	ldr r3, [sp, 0x14]
	cmp r3, 0
	beq _0808F6BC
	ldrb r0, [r4]
	cmp r0, 0x2F
	beq _0808F6CA
	ldrb r0, [r4, 0x1]
	cmp r0, 0x2F
	beq _0808F6CA
	b _0808F6DE
_0808F6BC:
	movs r0, 0x2F
	bl sub_8091130
	cmp r0, 0
	bge _0808F6CA
	movs r0, 0x1
	mov r9, r0
_0808F6CA:
	mov r1, r9
	cmp r1, 0
	bne _0808F6DE
	ldrh r0, [r4, 0x4]
	movs r1, 0x1
	orrs r0, r1
	strh r0, [r4, 0x4]
	mov r2, sp
	ldrh r2, [r2, 0x1C]
	strh r2, [r4, 0x6]
_0808F6DE:
	ldr r3, [sp, 0x18]
	adds r3, 0x1
	str r3, [sp, 0x18]
	ldr r0, _0808F6FC
	cmp r3, r0
	bgt _0808F6EC
	b _0808F4E0
_0808F6EC:
	add sp, 0x20
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_0808F6FC: .4byte 0x000001a7
	thumb_func_end sub_808F468

	thumb_func_start sub_808F700
sub_808F700:
	push {r4,lr}
	sub sp, 0x8
	mov r4, sp
	mov r1, sp
	movs r2, 0
	bl sub_808F468
	ldrh r1, [r4, 0x4]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _0808F71C
	movs r0, 0x1
	b _0808F72A
_0808F71C:
	movs r0, 0x4
	ands r0, r1
	cmp r0, 0
	bne _0808F728
	movs r0, 0
	b _0808F72A
_0808F728:
	movs r0, 0x2
_0808F72A:
	add sp, 0x8
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_808F700

	thumb_func_start sub_808F734
sub_808F734:
	push {r4-r7,lr}
	sub sp, 0x58
	adds r5, r0, 0
	lsls r4, r1, 16
	asrs r4, 16
	movs r6, 0
	mov r0, sp
	adds r1, r5, 0
	movs r2, 0x58
	bl memcpy
	adds r0, r5, 0
	adds r1, r4, 0
	bl sub_808F798
	adds r7, r0, 0
	movs r0, 0x9E
	lsls r0, 1
	cmp r4, r0
	bne _0808F782
	mov r0, sp
	strb r6, [r0, 0x2]
	add r0, sp, 0x28
	strb r6, [r0]
	add r4, sp, 0x4C
	ldr r5, _0808F794
	adds r0, r5, 0
	bl sub_808D994
	adds r1, r0, 0
	adds r0, r4, 0
	movs r2, 0xA
	bl sub_8092310
	mov r0, sp
	adds r1, r5, 0
	bl sub_808F798
	adds r6, r0, 0
_0808F782:
	cmp r6, 0
	beq _0808F78A
	bl sub_8097848
_0808F78A:
	adds r0, r7, 0
	add sp, 0x58
	pop {r4-r7}
	pop {r1}
	bx r1
	.align 2, 0
_0808F794: .4byte 0x0000013d
	thumb_func_end sub_808F734

	thumb_func_start sub_808F798
sub_808F798:
	push {r4-r6,lr}
	sub sp, 0xA4
	adds r4, r0, 0
	lsls r1, 16
	asrs r5, r1, 16
	mov r0, sp
	adds r1, r4, 0
	movs r2, 0x58
	bl memcpy
	mov r0, sp
	movs r1, 0x8
	ldrsh r6, [r0, r1]
	add r0, sp, 0x58
	mov r1, sp
	ldrb r2, [r1, 0x3]
	adds r1, r5, 0
	bl sub_808E010
	ldr r0, [sp, 0x58]
	str r0, [sp, 0x1C]
	movs r0, 0
	strh r0, [r4]
	mov r0, sp
	strh r5, [r0, 0x8]
	ldrb r0, [r0, 0xC]
	cmp r0, 0
	bne _0808F7DA
	mov r0, sp
	mov r1, sp
	ldrb r1, [r1, 0x3]
	strb r1, [r0, 0xC]
	b _0808F7EA
_0808F7DA:
	mov r0, sp
	ldrb r0, [r0, 0x10]
	cmp r0, 0
	bne _0808F7EA
	mov r0, sp
	mov r1, sp
	ldrb r1, [r1, 0x3]
	strb r1, [r0, 0x10]
_0808F7EA:
	add r4, sp, 0x64
	adds r0, r6, 0
	bl sub_808D994
	adds r1, r0, 0
	adds r0, r4, 0
	bl sub_80922F4
	movs r2, 0
	b _0808F800
_0808F7FE:
	adds r2, 0x1
_0808F800:
	cmp r2, 0x9
	bgt _0808F816
	adds r1, r4, r2
	add r0, sp, 0x4C
	adds r0, r2
	ldrb r1, [r1]
	ldrb r0, [r0]
	cmp r1, r0
	bne _0808F82E
	cmp r1, 0
	bne _0808F7FE
_0808F816:
	movs r0, 0x1
	cmp r0, 0
	beq _0808F82E
	add r4, sp, 0x4C
	adds r0, r5, 0
	bl sub_808D994
	adds r1, r0, 0
	adds r0, r4, 0
	movs r2, 0xA
	bl sub_8092310
_0808F82E:
	mov r0, sp
	bl sub_808D1DC
	add sp, 0xA4
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end sub_808F798

	thumb_func_start sub_808F83C
sub_808F83C:
	movs r0, 0
	strb r0, [r2]
	bx lr
	thumb_func_end sub_808F83C

	thumb_func_start sub_808F844
sub_808F844:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x30
	adds r5, r0, 0
	adds r4, r1, 0
	mov r10, r2
	str r3, [sp, 0x2C]
	ldr r0, [sp, 0x50]
	bl sub_80073B8
	ldr r0, _0808F880
	mov r1, r10
	adds r1, 0x2
	movs r2, 0x14
	bl strncpy
	movs r0, 0x20
	mov r9, r0
	cmp r5, 0x5
	bls _0808F874
	b _0808FED6
_0808F874:
	lsls r0, r5, 2
	ldr r1, _0808F884
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0808F880: .4byte gUnknown_202DF98
_0808F884: .4byte _0808F888
	.align 2, 0
_0808F888:
	.4byte _0808FED6
	.4byte _0808FBF4
	.4byte _0808F8A0
	.4byte _0808FB44
	.4byte _0808FCB0
	.4byte _0808FDB0
_0808F8A0:
	lsls r0, r4, 3
	adds r0, 0x10
	ldr r2, _0808F998
	movs r5, 0
	str r5, [sp]
	movs r1, 0
	ldr r3, [sp, 0x50]
	bl sub_8014FF0
	ldr r4, _0808F99C
	mov r1, r10
	ldr r0, [r1, 0x2C]
	str r0, [r4]
	ldr r0, [r1, 0x30]
	str r0, [r4, 0x4]
	ldr r0, _0808F9A0
	ldr r2, [r0]
	str r5, [sp]
	movs r0, 0x4
	mov r1, r9
	ldr r3, [sp, 0x50]
	bl sub_8014FF0
	movs r2, 0xA
	add r9, r2
	ldr r0, _0808F9A4
	ldr r2, [r0]
	str r5, [sp]
	movs r0, 0x4
	mov r1, r9
	ldr r3, [sp, 0x50]
	bl sub_8014FF0
	movs r3, 0xA
	add r9, r3
	mov r0, r10
	ldr r2, [r0, 0x2C]
	cmp r2, 0x63
	bgt _0808F914
	movs r3, 0
	ldrsh r1, [r0, r3]
	adds r2, 0x1
	add r0, sp, 0x8
	bl sub_808E010
	ldr r0, [sp, 0x8]
	mov r2, r10
	ldr r1, [r2, 0x30]
	subs r0, r1
	str r0, [r4]
	ldr r0, _0808F9A8
	ldr r2, [r0]
	str r5, [sp]
	movs r0, 0x4
	mov r1, r9
	ldr r3, [sp, 0x50]
	bl sub_8014FF0
_0808F914:
	movs r3, 0xC
	add r9, r3
	mov r1, r10
	ldr r0, [r1, 0x24]
	str r0, [r4]
	ldr r0, [r1, 0x28]
	str r0, [r4, 0x4]
	ldr r0, _0808F9AC
	ldr r2, [r0]
	str r5, [sp]
	movs r0, 0x4
	mov r1, r9
	ldr r3, [sp, 0x50]
	bl sub_8014FF0
	movs r2, 0xA
	add r9, r2
	ldr r0, _0808F9B0
	ldr r2, [r0]
	str r5, [sp]
	movs r0, 0x4
	mov r1, r9
	ldr r3, [sp, 0x50]
	bl sub_8014FF0
	ldr r0, _0808F9B4
	ldr r2, [r0]
	mov r0, r10
	adds r0, 0x34
	ldrb r3, [r0]
	str r3, [r4]
	mov r1, r10
	adds r1, 0x39
	ldrb r0, [r1]
	cmp r0, 0
	beq _0808F964
	adds r0, r3, r0
	str r0, [r4]
	ldr r0, _0808F9B8
	ldr r2, [r0]
_0808F964:
	str r5, [sp]
	movs r0, 0x4
	mov r1, r9
	ldr r3, [sp, 0x50]
	bl sub_8014FF0
	mov r1, r10
	adds r1, 0x3B
	ldrb r3, [r1]
	cmp r3, 0
	beq _0808F9C0
	mov r0, r10
	adds r0, 0x36
	ldrb r0, [r0]
	adds r1, r3, 0
	adds r0, r1
	str r0, [r4]
	ldr r0, _0808F9BC
	ldr r2, [r0]
	str r5, [sp]
	movs r0, 0x4
	mov r1, r9
	ldr r3, [sp, 0x50]
	bl sub_8014FF0
	b _0808F9D8
	.align 2, 0
_0808F998: .4byte gUnknown_8107754
_0808F99C: .4byte gUnknown_202DE30
_0808F9A0: .4byte gUnknown_810DD80
_0808F9A4: .4byte gUnknown_810DD9C
_0808F9A8: .4byte gUnknown_810DDB8
_0808F9AC: .4byte gUnknown_810DDD0
_0808F9B0: .4byte gUnknown_810DDE4
_0808F9B4: .4byte gUnknown_810DE0C
_0808F9B8: .4byte gUnknown_810DE20
_0808F9BC: .4byte gUnknown_810DE4C
_0808F9C0:
	mov r0, r10
	adds r0, 0x36
	ldrb r0, [r0]
	str r0, [r4]
	ldr r0, _0808FA44
	ldr r2, [r0]
	str r3, [sp]
	movs r0, 0x4
	mov r1, r9
	ldr r3, [sp, 0x50]
	bl sub_8014FF0
_0808F9D8:
	movs r3, 0xA
	add r9, r3
	ldr r0, _0808FA48
	ldr r2, [r0]
	movs r5, 0
	str r5, [sp]
	movs r0, 0x4
	mov r1, r9
	ldr r3, [sp, 0x50]
	bl sub_8014FF0
	ldr r0, _0808FA4C
	ldr r2, [r0]
	ldr r4, _0808FA50
	mov r0, r10
	adds r0, 0x35
	ldrb r3, [r0]
	str r3, [r4]
	mov r1, r10
	adds r1, 0x3A
	ldrb r0, [r1]
	cmp r0, 0
	beq _0808FA0E
	adds r0, r3, r0
	str r0, [r4]
	ldr r0, _0808FA54
	ldr r2, [r0]
_0808FA0E:
	str r5, [sp]
	movs r0, 0x4
	mov r1, r9
	ldr r3, [sp, 0x50]
	bl sub_8014FF0
	mov r1, r10
	adds r1, 0x3C
	ldrb r3, [r1]
	cmp r3, 0
	beq _0808FA5C
	mov r0, r10
	adds r0, 0x37
	ldrb r0, [r0]
	adds r1, r3, 0
	adds r0, r1
	str r0, [r4]
	ldr r0, _0808FA58
	ldr r2, [r0]
	str r5, [sp]
	movs r0, 0x4
	mov r1, r9
	ldr r3, [sp, 0x50]
	bl sub_8014FF0
	b _0808FA74
	.align 2, 0
_0808FA44: .4byte gUnknown_810DE38
_0808FA48: .4byte gUnknown_810DDFC
_0808FA4C: .4byte gUnknown_810DE24
_0808FA50: .4byte gUnknown_202DE30
_0808FA54: .4byte gUnknown_810DE28
_0808FA58: .4byte gUnknown_810DE54
_0808FA5C:
	mov r0, r10
	adds r0, 0x37
	ldrb r0, [r0]
	str r0, [r4]
	ldr r0, _0808FA94
	ldr r2, [r0]
	str r3, [sp]
	movs r0, 0x4
	mov r1, r9
	ldr r3, [sp, 0x50]
	bl sub_8014FF0
_0808FA74:
	movs r0, 0xA
	add r9, r0
	mov r2, r10
	adds r2, 0x20
	ldrb r1, [r2]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _0808FA9C
	ldr r0, _0808FA98
	adds r1, r2, 0
	movs r2, 0
	bl sub_8090E14
	b _0808FAA6
	.align 2, 0
_0808FA94: .4byte gUnknown_810DE50
_0808FA98: .4byte gUnknown_202DE58
_0808FA9C:
	ldr r0, _0808FB24
	ldr r1, _0808FB28
	ldr r1, [r1]
	bl strcpy
_0808FAA6:
	ldr r0, _0808FB2C
	ldr r2, [r0]
	movs r4, 0
	str r4, [sp]
	movs r0, 0x4
	mov r1, r9
	ldr r3, [sp, 0x50]
	bl sub_8014FF0
	movs r1, 0xC
	add r9, r1
	ldr r1, _0808FB30
	mov r2, r10
	movs r3, 0x3E
	ldrsh r0, [r2, r3]
	str r0, [r1]
	movs r1, 0x3E
	ldrsh r0, [r2, r1]
	movs r1, 0xA
	bl __divsi3
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0
	bge _0808FADA
	movs r0, 0
_0808FADA:
	cmp r0, 0x62
	ble _0808FAE0
	movs r0, 0x63
_0808FAE0:
	ldr r1, _0808FB34
	lsls r0, 2
	adds r0, r1
	ldr r5, _0808FB38
	ldr r1, [r0]
	adds r0, r5, 0
	bl strcpy
	ldr r0, _0808FB3C
	ldr r2, [r0]
	str r4, [sp]
	movs r0, 0x4
	mov r1, r9
	ldr r3, [sp, 0x50]
	bl sub_8014FF0
	movs r2, 0xA
	add r9, r2
	mov r0, r10
	adds r0, 0x38
	ldrb r4, [r0]
	cmp r4, 0
	beq _0808FB10
	b _0808FED6
_0808FB10:
	adds r0, 0x1C
	ldrb r1, [r0]
	adds r0, r5, 0
	bl sub_808EAC0
	ldr r0, _0808FB40
	ldr r2, [r0]
	str r4, [sp]
	b _0808FECC
	.align 2, 0
_0808FB24: .4byte gUnknown_202DE58
_0808FB28: .4byte gUnknown_810DE58
_0808FB2C: .4byte gUnknown_810DE6C
_0808FB30: .4byte gUnknown_202DE30
_0808FB34: .4byte gUnknown_8115718
_0808FB38: .4byte gUnknown_202DF98
_0808FB3C: .4byte gUnknown_810DE80
_0808FB40: .4byte gUnknown_810DE98
_0808FB44:
	lsls r0, r4, 3
	adds r0, 0x10
	ldr r2, _0808FBE8
	movs r4, 0
	str r4, [sp]
	movs r1, 0
	ldr r3, [sp, 0x50]
	bl sub_8014FF0
	ldr r2, _0808FBEC
	str r4, [sp]
	movs r0, 0x4
	mov r1, r9
	ldr r3, [sp, 0x50]
	bl sub_8014FF0
	mov r3, r10
	ldrb r0, [r3, 0x16]
	bl sub_8092344
	adds r2, r0, 0
	str r4, [sp]
	movs r0, 0x38
	mov r1, r9
	ldr r3, [sp, 0x50]
	bl sub_8014FF0
	mov r1, r10
	ldrb r0, [r1, 0x17]
	cmp r0, 0
	beq _0808FB94
	bl sub_8092344
	adds r2, r0, 0
	str r4, [sp]
	movs r0, 0x60
	mov r1, r9
	ldr r3, [sp, 0x50]
	bl sub_8014FF0
_0808FB94:
	movs r2, 0xC
	add r9, r2
	ldr r2, _0808FBF0
	str r4, [sp]
	movs r0, 0x4
	mov r1, r9
	ldr r3, [sp, 0x50]
	bl sub_8014FF0
	movs r3, 0xC
	add r9, r3
	mov r1, r10
	ldrb r0, [r1, 0x18]
	bl sub_8092390
	adds r2, r0, 0
	str r4, [sp]
	movs r5, 0xB
	str r5, [sp, 0x4]
	movs r0, 0x4
	mov r1, r9
	ldr r3, [sp, 0x50]
	bl sub_8015034
	movs r2, 0x21
	add r9, r2
	mov r3, r10
	ldrb r0, [r3, 0x19]
	cmp r0, 0
	bne _0808FBD2
	b _0808FED6
_0808FBD2:
	bl sub_8092390
	adds r2, r0, 0
	str r4, [sp]
	str r5, [sp, 0x4]
	movs r0, 0x4
	mov r1, r9
	ldr r3, [sp, 0x50]
	bl sub_8015034
	b _0808FED6
	.align 2, 0
_0808FBE8: .4byte gUnknown_810775C
_0808FBEC: .4byte gUnknown_8107768
_0808FBF0: .4byte gUnknown_8107770
_0808FBF4:
	lsls r0, r4, 3
	adds r0, 0x10
	ldr r1, _0808FC34
	ldr r2, [r1]
	movs r1, 0
	str r1, [sp]
	ldr r3, [sp, 0x50]
	bl sub_8014FF0
	mov r0, r10
	adds r0, 0x56
	movs r1, 0
	ldrsh r0, [r0, r1]
	subs r5, r0, 0x1
	movs r2, 0xC
	negs r2, r2
	add r9, r2
	movs r7, 0
	ldr r6, [sp, 0x2C]
	adds r6, 0xC
	adds r1, r6, 0
	movs r2, 0
	ldr r0, [sp, 0x2C]
	adds r0, 0x2C
_0808FC24:
	str r2, [r0]
	subs r0, 0x4
	cmp r0, r1
	bge _0808FC24
	movs r3, 0
	mov r8, r3
	b _0808FC88
	.align 2, 0
_0808FC34: .4byte gUnknown_810DD58
_0808FC38:
	mov r0, r10
	adds r0, 0x58
	adds r4, r0, r5
	ldrb r0, [r4]
	cmp r0, 0
	beq _0808FC78
	movs r7, 0x1
	ldr r0, _0808FCA0
	ldrb r1, [r4]
	lsls r1, 2
	adds r1, r0
	ldr r0, _0808FCA4
	ldr r1, [r1]
	movs r2, 0x50
	bl strncpy
	ldr r2, _0808FCA8
	movs r0, 0
	str r0, [sp]
	movs r0, 0xC
	mov r1, r9
	ldr r3, [sp, 0x50]
	bl sub_8014FF0
	mov r0, r8
	cmp r0, 0
	ble _0808FC78
	subs r0, 0x1
	lsls r0, 2
	adds r0, r6, r0
	ldrb r1, [r4]
	str r1, [r0]
_0808FC78:
	movs r1, 0x1
	add r8, r1
	adds r5, 0x1
	movs r2, 0xC
	add r9, r2
	mov r3, r8
	cmp r3, 0x9
	bgt _0808FC90
_0808FC88:
	cmp r5, 0
	blt _0808FC78
	cmp r5, 0xB
	ble _0808FC38
_0808FC90:
	cmp r7, 0
	beq _0808FC96
	b _0808FED6
_0808FC96:
	ldr r0, _0808FCAC
	ldr r2, [r0]
	str r7, [sp]
	b _0808FD98
	.align 2, 0
_0808FCA0: .4byte gUnknown_810CF1C
_0808FCA4: .4byte gUnknown_202DEA8
_0808FCA8: .4byte gUnknown_8107784
_0808FCAC: .4byte gUnknown_810DF78
_0808FCB0:
	lsls r0, r4, 3
	adds r0, 0x10
	ldr r1, _0808FCF8
	ldr r2, [r1]
	movs r1, 0
	str r1, [sp]
	ldr r3, [sp, 0x50]
	bl sub_8014FF0
	add r4, sp, 0x14
	mov r0, r10
	movs r2, 0x3E
	ldrsh r1, [r0, r2]
	adds r0, r4, 0
	bl sub_808EBA8
	mov r0, r10
	adds r0, 0x40
	movs r3, 0
	ldrsh r0, [r0, r3]
	subs r7, r0, 0x1
	mov r1, r9
	subs r1, 0xC
	movs r2, 0
	ldr r0, [sp, 0x2C]
	adds r0, 0x8
_0808FCE4:
	strb r2, [r0]
	subs r0, 0x1
	ldr r3, [sp, 0x2C]
	cmp r0, r3
	bge _0808FCE4
	mov r9, r1
	movs r4, 0
	mov r8, r4
	b _0808FD84
	.align 2, 0
_0808FCF8: .4byte gUnknown_810DD68
_0808FCFC:
	mov r5, sp
	adds r5, r7
	adds r5, 0x14
	ldrb r0, [r5]
	cmp r0, 0
	beq _0808FD74
	movs r4, 0x1
	bl sub_808EAB0
	adds r1, r0, 0
	ldr r6, _0808FD3C
	adds r0, r6, 0
	movs r2, 0x50
	bl strncpy
	mov r0, r10
	adds r0, 0x50
	adds r1, r4, 0
	ldrb r5, [r5]
	lsls r1, r5
	bl sub_808ECD0
	lsls r0, 24
	cmp r0, 0
	beq _0808FD44
	adds r0, r6, 0
	subs r0, 0x50
	ldr r1, _0808FD40
	bl strcpy
	b _0808FD4E
	.align 2, 0
_0808FD3C: .4byte gUnknown_202DEA8
_0808FD40: .4byte gUnknown_8107788
_0808FD44:
	adds r0, r6, 0
	subs r0, 0x50
	ldr r1, _0808FDA4
	bl strcpy
_0808FD4E:
	mov r0, r8
	cmp r0, 0
	ble _0808FD64
	subs r0, 0x1
	ldr r1, [sp, 0x2C]
	adds r0, r1, r0
	mov r1, sp
	adds r1, r7
	adds r1, 0x14
	ldrb r1, [r1]
	strb r1, [r0]
_0808FD64:
	ldr r2, _0808FDA8
	movs r0, 0
	str r0, [sp]
	movs r0, 0xC
	mov r1, r9
	ldr r3, [sp, 0x50]
	bl sub_8014FF0
_0808FD74:
	movs r2, 0x1
	add r8, r2
	adds r7, 0x1
	movs r3, 0xC
	add r9, r3
	mov r0, r8
	cmp r0, 0x9
	bgt _0808FD8C
_0808FD84:
	cmp r7, 0
	blt _0808FD74
	cmp r7, 0x17
	ble _0808FCFC
_0808FD8C:
	cmp r4, 0
	beq _0808FD92
	b _0808FED6
_0808FD92:
	ldr r0, _0808FDAC
	ldr r2, [r0]
	str r4, [sp]
_0808FD98:
	movs r0, 0xC
	movs r1, 0x20
	ldr r3, [sp, 0x50]
	bl sub_8014FF0
	b _0808FED6
	.align 2, 0
_0808FDA4: .4byte gUnknown_810778C
_0808FDA8: .4byte gUnknown_8107790
_0808FDAC: .4byte gUnknown_810DF84
_0808FDB0:
	lsls r0, r4, 3
	adds r0, 0x10
	ldr r2, _0808FEEC
	movs r5, 0
	str r5, [sp]
	movs r1, 0
	ldr r3, [sp, 0x50]
	bl sub_8014FF0
	ldr r6, _0808FEF0
	mov r2, r10
	movs r3, 0
	ldrsh r1, [r2, r3]
	adds r0, r6, 0
	bl sub_808D8BC
	ldr r1, _0808FEF4
	mov r2, r10
	movs r3, 0
	ldrsh r0, [r2, r3]
	str r0, [r1]
	ldr r0, _0808FEF8
	ldr r2, [r0]
	str r5, [sp]
	movs r0, 0x4
	mov r1, r9
	ldr r3, [sp, 0x50]
	bl sub_8014FF0
	movs r0, 0xA
	add r9, r0
	mov r1, r10
	movs r2, 0
	ldrsh r0, [r1, r2]
	bl sub_808DBA8
	lsls r0, 24
	lsrs r0, 24
	bl sub_8092524
	adds r1, r0, 0
	ldr r4, _0808FEFC
	adds r0, r4, 0
	movs r2, 0x50
	bl strncpy
	ldr r0, _0808FF00
	ldr r2, [r0]
	str r5, [sp]
	movs r0, 0x4
	mov r1, r9
	ldr r3, [sp, 0x50]
	bl sub_8014FF0
	movs r3, 0xA
	add r9, r3
	ldr r0, _0808FF04
	ldr r2, [r0]
	str r5, [sp]
	movs r0, 0x4
	mov r1, r9
	ldr r3, [sp, 0x50]
	bl sub_8014FF0
	movs r0, 0xD
	add r9, r0
	ldr r0, _0808FF08
	ldr r2, [r0]
	str r5, [sp]
	movs r0, 0x4
	mov r1, r9
	ldr r3, [sp, 0x50]
	bl sub_8014FF0
	movs r1, 0xA
	add r9, r1
	mov r1, r10
	adds r1, 0x1C
	adds r0, r4, 0
	bl sub_8090208
	ldr r0, _0808FF0C
	ldr r2, [r0]
	str r5, [sp]
	movs r0, 0x4
	mov r1, r9
	ldr r3, [sp, 0x50]
	bl sub_8014FF0
	movs r2, 0xD
	add r9, r2
	mov r3, r10
	movs r1, 0
	ldrsh r0, [r3, r1]
	bl sub_808DAB4
	adds r1, r0, 0
	adds r0, r6, 0
	movs r2, 0x14
	bl strncpy
	ldr r0, _0808FF10
	ldr r2, [r0]
	str r5, [sp]
	movs r0, 0x4
	mov r1, r9
	ldr r3, [sp, 0x50]
	bl sub_8014FF0
	movs r2, 0xD
	add r9, r2
	ldr r4, _0808FF14
	mov r3, r10
	movs r1, 0
	ldrsh r0, [r3, r1]
	bl sub_808DACC
	lsls r0, 24
	lsrs r0, 22
	adds r0, r4
	ldr r1, [r0]
	adds r0, r6, 0
	bl strcpy
	ldr r0, _0808FF18
	ldr r2, [r0]
	str r5, [sp]
	movs r0, 0x4
	mov r1, r9
	ldr r3, [sp, 0x50]
	bl sub_8014FF0
	movs r2, 0xD
	add r9, r2
	ldr r1, _0808FF1C
	mov r0, r10
	adds r0, 0x4C
	ldrb r0, [r0]
	lsls r0, 2
	adds r0, r1
	ldr r2, [r0]
	str r5, [sp]
_0808FECC:
	movs r0, 0x4
	mov r1, r9
	ldr r3, [sp, 0x50]
	bl sub_8014FF0
_0808FED6:
	ldr r0, [sp, 0x50]
	bl sub_80073E0
	add sp, 0x30
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_0808FEEC: .4byte gUnknown_8107798
_0808FEF0: .4byte gUnknown_202DF98
_0808FEF4: .4byte gUnknown_202DE30
_0808FEF8: .4byte gUnknown_810DEB4
_0808FEFC: .4byte gUnknown_202DE58
_0808FF00: .4byte gUnknown_810DEC8
_0808FF04: .4byte gUnknown_810DEDC
_0808FF08: .4byte gUnknown_810DFB4
_0808FF0C: .4byte gUnknown_810DFC8
_0808FF10: .4byte gUnknown_810DEF4
_0808FF14: .4byte gUnknown_810E02C
_0808FF18: .4byte gUnknown_810DF98
_0808FF1C: .4byte gUnknown_810DFCC
	thumb_func_end sub_808F844

	thumb_func_start sub_808FF20
sub_808FF20:
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	adds r5, r0, 0
	adds r6, r1, 0
	lsls r2, 24
	lsrs r2, 24
	mov r8, r2
	adds r0, r5, 0x2
	movs r2, 0
	bl sub_808D9AC
	ldrh r0, [r6, 0x8]
	strh r0, [r5]
	movs r1, 0x16
	ldrsh r0, [r6, r1]
	str r0, [r5, 0x24]
	str r0, [r5, 0x28]
	ldrb r0, [r6, 0x3]
	str r0, [r5, 0x2C]
	ldr r0, [r6, 0x1C]
	str r0, [r5, 0x30]
	movs r4, 0
_0808FF50:
	adds r1, r5, 0
	adds r1, 0x34
	adds r1, r4
	adds r0, r6, 0
	adds r0, 0x18
	adds r0, r4
	ldrb r0, [r0]
	strb r0, [r1]
	adds r1, r5, 0
	adds r1, 0x36
	adds r1, r4
	adds r0, r6, 0
	adds r0, 0x1A
	adds r0, r4
	ldrb r0, [r0]
	strb r0, [r1]
	movs r7, 0x8
	ldrsh r0, [r6, r7]
	adds r1, r4, 0
	bl sub_808DC68
	adds r1, r5, 0
	adds r1, 0x16
	adds r1, r4
	strb r0, [r1]
	movs r1, 0x8
	ldrsh r0, [r6, r1]
	adds r1, r4, 0
	bl sub_808DC84
	adds r1, r5, 0
	adds r1, 0x18
	adds r1, r4
	strb r0, [r1]
	adds r4, 0x1
	cmp r4, 0x1
	ble _0808FF50
	ldrb r2, [r6, 0x2]
	adds r1, r5, 0
	adds r1, 0x38
	movs r0, 0
	strb r2, [r1]
	adds r2, r5, 0
	adds r2, 0x39
	strb r0, [r2]
	adds r3, r5, 0
	adds r3, 0x3A
	strb r0, [r3]
	movs r7, 0x3B
	adds r7, r5
	mov r12, r7
	strb r0, [r7]
	movs r1, 0x3C
	adds r1, r5
	mov r9, r1
	strb r0, [r1]
	adds r0, r6, 0
	adds r0, 0x28
	ldrb r1, [r0]
	adds r4, r0, 0
	cmp r1, 0
	beq _08090026
	cmp r1, 0x13
	bne _0808FFDA
	ldr r0, _08090060
	ldrb r0, [r0]
	ldrb r7, [r2]
	adds r0, r7
	strb r0, [r2]
_0808FFDA:
	ldrb r1, [r4]
	cmp r1, 0x21
	bne _0808FFEA
	ldr r0, _08090064
	ldrb r0, [r0]
	ldrb r7, [r3]
	adds r0, r7
	strb r0, [r3]
_0808FFEA:
	cmp r1, 0x2B
	bne _0808FFFE
	ldr r0, _08090068
	ldrb r0, [r0]
	ldrb r7, [r2]
	adds r1, r0, r7
	strb r1, [r2]
	ldrb r1, [r3]
	adds r0, r1
	strb r0, [r3]
_0808FFFE:
	ldrb r0, [r4]
	cmp r0, 0x1E
	bne _08090012
	ldr r0, _0809006C
	ldrb r0, [r0]
	mov r2, r12
	ldrb r2, [r2]
	adds r0, r2
	mov r7, r12
	strb r0, [r7]
_08090012:
	ldrb r0, [r4]
	cmp r0, 0x22
	bne _08090026
	ldr r0, _08090070
	ldrb r0, [r0]
	mov r1, r9
	ldrb r1, [r1]
	adds r0, r1
	mov r2, r9
	strb r0, [r2]
_08090026:
	adds r0, r6, 0
	adds r0, 0x24
	ldrb r1, [r0]
	adds r0, r5, 0
	adds r0, 0x54
	strb r1, [r0]
	subs r0, 0x34
	adds r1, r4, 0
	bl sub_8090B64
	ldrh r0, [r6, 0x14]
	strh r0, [r5, 0x3E]
	ldr r0, [r6, 0x4]
	str r0, [r5, 0x1C]
	ldr r0, [r6, 0xC]
	str r0, [r5, 0x44]
	ldr r0, [r6, 0x10]
	str r0, [r5, 0x48]
	ldr r0, [r6, 0x20]
	str r0, [r5, 0x50]
	mov r7, r8
	cmp r7, 0
	beq _08090074
	adds r0, r6, 0
	bl sub_808F700
	adds r1, r5, 0
	adds r1, 0x4C
	b _0809007A
	.align 2, 0
_08090060: .4byte gUnknown_810AC60
_08090064: .4byte gUnknown_810AC62
_08090068: .4byte gUnknown_810AC68
_0809006C: .4byte gUnknown_810AC64
_08090070: .4byte gUnknown_810AC66
_08090074:
	adds r1, r5, 0
	adds r1, 0x4C
	movs r0, 0x3
_0809007A:
	strb r0, [r1]
	adds r1, r5, 0
	adds r1, 0x58
	movs r2, 0
	adds r0, r5, 0
	adds r0, 0x63
_08090086:
	strb r2, [r0]
	subs r0, 0x1
	cmp r0, r1
	bge _08090086
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_808FF20

	.align 2, 0 @ Don't pad with nop.
