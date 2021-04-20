	.include "constants/gba_constants.inc"
	.include "asm/macros.inc"

	.syntax unified

	.text

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

	thumb_func_start GetPokemonLevelData
GetPokemonLevelData:
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
	bl DecompressATFile
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
_0808E06C: .4byte gLevelCurrentPokeId
_0808E070: .4byte gUnknown_810768C
_0808E074: .4byte gSystemFileArchive
_0808E078: .4byte gLevelCurrentData
	thumb_func_end GetPokemonLevelData

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
	bl GetPokemonEvolveFrom
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
	bl GetPokemonEvolveFrom
	lsls r0, 16
	asrs r0, 16
	cmp r9, r0
	bne _0808E46C
	ldr r0, [sp]
	cmp r0, 0
	bne _0808E456
	mov r0, r9
	bl GetPokemonSize
	adds r4, r0, 0
	adds r0, r5, 0
	bl GetPokemonSize
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
_0808E518: .4byte gFormattedStatusNames
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
_0808E538: .4byte gFormattedStatusNames
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
_0808E62C: .4byte gDungeonFileArchive
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
	bl GetShadowSize
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

	thumb_func_start HasRecruitedMon
HasRecruitedMon:
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
	thumb_func_end HasRecruitedMon

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

	.align 2, 0 @ Don't pad with nop.
