        .include "constants/gba_constants.inc"
        .include "asm/macros.inc"

        .syntax unified

        .text

	thumb_func_start sub_808CE08
sub_808CE08:
	push {r4-r7,lr}
	ldr r4, _0808CE60
	movs r3, 0
	movs r1, 0
	ldr r2, _0808CE64
_0808CE12:
	ldr r0, [r4]
	adds r0, r1
	strh r3, [r0]
	adds r1, 0x58
	subs r2, 0x1
	cmp r2, 0
	bne _0808CE12
	ldr r5, _0808CE60
	ldr r4, _0808CE68
	movs r3, 0
	movs r1, 0
	movs r2, 0x3
_0808CE2A:
	ldr r0, [r5]
	adds r0, r1
	adds r0, r4
	strh r3, [r0]
	adds r1, 0x64
	subs r2, 0x1
	cmp r2, 0
	bge _0808CE2A
	ldr r7, _0808CE60
	ldr r6, _0808CE6C
	movs r4, 0
	movs r3, 0
	ldr r5, _0808CE70
	movs r2, 0x3
_0808CE46:
	ldr r0, [r7]
	adds r0, r3
	adds r1, r0, r6
	strh r4, [r1]
	adds r0, r5
	strh r4, [r0]
	adds r3, 0x58
	subs r2, 0x1
	cmp r2, 0
	bge _0808CE46
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_0808CE60: .4byte gUnknown_203B45C
_0808CE64: .4byte 0x0000019d
_0808CE68: .4byte 0x00008df8
_0808CE6C: .4byte 0x00008f90
_0808CE70: .4byte 0x00008f88
	thumb_func_end sub_808CE08

	thumb_func_start sub_808CE74
sub_808CE74:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x6C
	mov r8, r2
	lsls r0, 16
	asrs r7, r0, 16
	lsls r1, 24
	mov r2, sp
	movs r0, 0x3
	strh r0, [r2]
	cmp r1, 0
	beq _0808CE9C
	mov r1, sp
	movs r0, 0x1
	strb r0, [r1, 0x2]
	movs r0, 0x40
	b _0808CEA4
_0808CE9C:
	mov r1, sp
	movs r0, 0
	strb r0, [r1, 0x2]
	movs r0, 0x41
_0808CEA4:
	strb r0, [r1, 0x4]
	mov r0, sp
	movs r6, 0
	movs r5, 0x1
	strb r5, [r0, 0x3]
	adds r0, r7, 0
	bl GetBaseHP
	mov r1, sp
	movs r4, 0
	strh r0, [r1, 0x16]
	adds r0, r7, 0
	movs r1, 0
	bl GetPokemonAttSpatt
	mov r1, sp
	strb r0, [r1, 0x18]
	adds r0, r7, 0
	movs r1, 0x1
	bl GetPokemonAttSpatt
	mov r1, sp
	strb r0, [r1, 0x19]
	adds r0, r7, 0
	movs r1, 0
	bl GetPokemonDefSpdef
	mov r1, sp
	strb r0, [r1, 0x1A]
	adds r0, r7, 0
	movs r1, 0x1
	bl GetPokemonDefSpdef
	mov r1, sp
	strb r0, [r1, 0x1B]
	mov r0, sp
	strh r5, [r0, 0x14]
	strb r4, [r0, 0xC]
	strb r4, [r0, 0x10]
	add r0, sp, 0x20
	movs r1, 0
	bl sub_808EC94
	mov r0, sp
	strh r7, [r0, 0x8]
	add r0, sp, 0x28
	strb r4, [r0]
	adds r0, 0x1
	strb r4, [r0]
	str r6, [sp, 0x1C]
	add r0, sp, 0x24
	strb r4, [r0]
	mov r0, sp
	strb r4, [r0, 0x5]
	add r0, sp, 0x2C
	adds r1, r7, 0
	bl sub_808E490
	mov r0, r8
	cmp r0, 0
	bne _0808CF5C
	add r4, sp, 0x58
	adds r0, r4, 0
	adds r1, r7, 0
	bl CopySpeciesNametoBuffer
	add r0, sp, 0x4C
	adds r1, r4, 0
	movs r2, 0xA
	bl BoundedCopyStringtoBuffer
	lsls r4, r7, 3
	b _0808CF72
_0808CF36:
	mov r1, r8
	ldr r0, [r1]
	adds r0, r6
	mov r1, sp
	movs r2, 0x58
	bl memcpy
	ldr r0, _0808CF58
	ldr r0, [r0]
	adds r0, r4
	mov r5, r9
	strb r5, [r0]
	adds r0, r7, 0
	bl sub_80980B4
	b _0808CFB8
	.align 2, 0
_0808CF58: .4byte gFriendAreas
_0808CF5C:
	movs r2, 0
	lsls r4, r7, 3
	add r3, sp, 0x4C
_0808CF62:
	adds r0, r3, r2
	mov r5, r8
	adds r1, r5, r2
	ldrb r1, [r1]
	strb r1, [r0]
	adds r2, 0x1
	cmp r2, 0x9
	ble _0808CF62
_0808CF72:
	ldr r0, _0808CFC8
	ldr r1, [r0]
	adds r0, r4, r7
	lsls r0, 3
	adds r0, r1
	ldrb r0, [r0, 0x16]
	mov r10, r0
	movs r5, 0
	ldr r0, _0808CFCC
	mov r8, r0
	movs r1, 0x1
	mov r9, r1
_0808CF8A:
	movs r0, 0x58
	adds r6, r5, 0
	muls r6, r0
	mov r1, r8
	ldr r0, [r1]
	adds r0, r6, r0
	ldrb r1, [r0]
	mov r0, r9
	ands r0, r1
	cmp r0, 0
	bne _0808CFAE
	adds r0, r5, 0
	bl sub_80923D4
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, r10
	beq _0808CF36
_0808CFAE:
	adds r5, 0x1
	movs r0, 0xCE
	lsls r0, 1
	cmp r5, r0
	ble _0808CF8A
_0808CFB8:
	add sp, 0x6C
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_0808CFC8: .4byte gMonsterParameters
_0808CFCC: .4byte gUnknown_203B45C
	thumb_func_end sub_808CE74

	thumb_func_start sub_808CFD0
sub_808CFD0:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x14
	adds r7, r0, 0
	mov r10, r2
	adds r4, r3, 0
	lsls r1, 16
	asrs r1, 16
	mov r9, r1
	lsls r4, 24
	lsrs r4, 24
	movs r5, 0
	movs r0, 0
	mov r8, r0
	movs r0, 0x1
	movs r6, 0x1
	strh r6, [r7]
	strb r5, [r7, 0x2]
	strb r0, [r7, 0x3]
	mov r0, r9
	bl GetBaseHP
	strh r0, [r7, 0x16]
	mov r0, r9
	movs r1, 0
	bl GetPokemonAttSpatt
	strb r0, [r7, 0x18]
	mov r0, r9
	movs r1, 0x1
	bl GetPokemonAttSpatt
	strb r0, [r7, 0x19]
	mov r0, r9
	movs r1, 0
	bl GetPokemonDefSpdef
	strb r0, [r7, 0x1A]
	mov r0, r9
	movs r1, 0x1
	bl GetPokemonDefSpdef
	strb r0, [r7, 0x1B]
	mov r1, r9
	strh r1, [r7, 0x8]
	adds r0, r7, 0
	adds r0, 0x28
	adds r1, r4, 0
	bl sub_8090B08
	mov r4, r8
	str r4, [r7, 0x1C]
	adds r0, r7, 0
	adds r0, 0x24
	strb r5, [r0]
	strh r6, [r7, 0x14]
	ldr r1, [sp, 0x34]
	ldr r0, [r1]
	str r0, [r7, 0x4]
	strb r5, [r7, 0xC]
	strb r5, [r7, 0x10]
	adds r0, r7, 0
	adds r0, 0x20
	movs r1, 0
	bl sub_808EC94
	ldr r4, [sp, 0x38]
	cmp r4, 0
	beq _0808D08C
	movs r0, 0x4C
	adds r0, r7
	mov r8, r0
	adds r5, r4, 0
	adds r4, r7, 0
	adds r4, 0x2C
	movs r6, 0x3
_0808D06E:
	ldrh r0, [r5]
	cmp r0, 0
	beq _0808D07E
	adds r1, r0, 0
	adds r0, r4, 0
	bl sub_8092AD4
	b _0808D080
_0808D07E:
	strb r0, [r4]
_0808D080:
	adds r5, 0x2
	adds r4, 0x8
	subs r6, 0x1
	cmp r6, 0
	bge _0808D06E
	b _0808D09A
_0808D08C:
	adds r0, r7, 0
	adds r0, 0x2C
	mov r1, r9
	bl sub_808E490
	adds r7, 0x4C
	mov r8, r7
_0808D09A:
	mov r1, r10
	cmp r1, 0
	bne _0808D0B4
	mov r0, sp
	mov r1, r9
	bl CopySpeciesNametoBuffer
	mov r0, r8
	mov r1, sp
	movs r2, 0xA
	bl BoundedCopyStringtoBuffer
	b _0808D0C8
_0808D0B4:
	movs r2, 0
	mov r3, r8
_0808D0B8:
	adds r0, r3, r2
	mov r4, r10
	adds r1, r4, r2
	ldrb r1, [r1]
	strb r1, [r0]
	adds r2, 0x1
	cmp r2, 0x9
	ble _0808D0B8
_0808D0C8:
	add sp, 0x14
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_808CFD0

	thumb_func_start sub_808D0D8
sub_808D0D8:
	push {r4-r7,lr}
	adds r7, r0, 0
	movs r6, 0
	movs r4, 0x1
	strb r4, [r7, 0x3]
	movs r1, 0x8
	ldrsh r0, [r7, r1]
	bl GetBaseHP
	movs r5, 0
	strh r0, [r7, 0x16]
	movs r2, 0x8
	ldrsh r0, [r7, r2]
	movs r1, 0
	bl GetPokemonAttSpatt
	strb r0, [r7, 0x18]
	movs r1, 0x8
	ldrsh r0, [r7, r1]
	movs r1, 0x1
	bl GetPokemonAttSpatt
	strb r0, [r7, 0x19]
	movs r2, 0x8
	ldrsh r0, [r7, r2]
	movs r1, 0
	bl GetPokemonDefSpdef
	strb r0, [r7, 0x1A]
	movs r1, 0x8
	ldrsh r0, [r7, r1]
	movs r1, 0x1
	bl GetPokemonDefSpdef
	strb r0, [r7, 0x1B]
	str r6, [r7, 0x1C]
	adds r0, r7, 0
	adds r0, 0x24
	strb r5, [r0]
	strh r4, [r7, 0x14]
	subs r0, 0x4
	movs r1, 0
	bl sub_808EC94
	adds r0, r7, 0
	adds r0, 0x2C
	movs r2, 0x8
	ldrsh r1, [r7, r2]
	bl sub_808E490
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_808D0D8

	thumb_func_start sub_808D144
sub_808D144:
	push {r4-r7,lr}
	adds r5, r0, 0
	adds r7, r1, 0
	movs r4, 0
	movs r0, 0x1
	strh r0, [r5]
	strb r4, [r5, 0x2]
	ldrh r0, [r7, 0x16]
	strb r0, [r5, 0x3]
	ldrh r0, [r7, 0x14]
	strh r0, [r5, 0x16]
	ldrh r0, [r7, 0x1A]
	strb r0, [r5, 0x18]
	ldrh r0, [r7, 0x1C]
	strb r0, [r5, 0x19]
	ldrh r0, [r7, 0x1E]
	strb r0, [r5, 0x1A]
	ldrh r0, [r7, 0x20]
	strb r0, [r5, 0x1B]
	ldrh r0, [r7, 0x4]
	strh r0, [r5, 0x8]
	adds r0, r5, 0
	adds r0, 0x28
	ldrb r1, [r7, 0x6]
	bl sub_8090B08
	ldr r0, [r7, 0x24]
	str r0, [r5, 0x1C]
	adds r0, r5, 0
	adds r0, 0x24
	strb r4, [r0]
	ldrh r0, [r7, 0x18]
	strh r0, [r5, 0x14]
	ldr r0, [r7, 0x8]
	str r0, [r5, 0x4]
	strb r4, [r5, 0xC]
	strb r4, [r5, 0x10]
	adds r0, r5, 0
	adds r0, 0x20
	movs r1, 0
	bl sub_808EC94
	movs r6, 0
	adds r4, r5, 0
	adds r4, 0x2C
_0808D19E:
	lsls r1, r6, 1
	adds r0, r7, 0
	adds r0, 0xC
	adds r0, r1
	ldrh r1, [r0]
	cmp r1, 0
	beq _0808D1B4
	adds r0, r4, 0
	bl sub_8092AD4
	b _0808D1B6
_0808D1B4:
	strb r1, [r4]
_0808D1B6:
	adds r4, 0x8
	adds r6, 0x1
	cmp r6, 0x3
	ble _0808D19E
	movs r6, 0
	adds r3, r5, 0
	adds r3, 0x4C
	ldr r2, [r7]
_0808D1C6:
	adds r0, r3, r6
	adds r1, r2, r6
	ldrb r1, [r1]
	strb r1, [r0]
	adds r6, 0x1
	cmp r6, 0x9
	ble _0808D1C6
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_808D144

	thumb_func_start sub_808D1DC
sub_808D1DC:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	mov r8, r0
	movs r2, 0x8
	ldrsh r1, [r0, r2]
	ldr r0, _0808D204
	ldr r2, [r0]
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 3
	adds r0, r2
	ldrb r6, [r0, 0x16]
	ldr r0, _0808D208
	ldr r0, [r0]
	adds r0, r6
	ldrb r0, [r0]
	cmp r0, 0
	bne _0808D238
	b _0808D268
	.align 2, 0
_0808D204: .4byte gMonsterParameters
_0808D208: .4byte gFriendAreas
_0808D20C:
	ldr r0, [r7]
	adds r0, r5
	mov r1, r8
	movs r2, 0x58
	bl memcpy
	ldr r1, [r7]
	adds r1, r5
	ldrh r2, [r1]
	ldr r0, _0808D234
	ands r0, r2
	strh r0, [r1]
	mov r1, r8
	movs r2, 0x8
	ldrsh r0, [r1, r2]
	bl sub_80980B4
	ldr r0, [r7]
	adds r0, r5
	b _0808D26A
	.align 2, 0
_0808D234: .4byte 0x0000bfff
_0808D238:
	movs r4, 0
	ldr r7, _0808D274
_0808D23C:
	movs r0, 0x58
	adds r5, r4, 0
	muls r5, r0
	ldr r0, [r7]
	adds r0, r5, r0
	ldrb r1, [r0]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	bne _0808D25E
	adds r0, r4, 0
	bl sub_80923D4
	lsls r0, 24
	lsrs r0, 24
	cmp r0, r6
	beq _0808D20C
_0808D25E:
	adds r4, 0x1
	movs r0, 0xCE
	lsls r0, 1
	cmp r4, r0
	ble _0808D23C
_0808D268:
	movs r0, 0
_0808D26A:
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r1}
	bx r1
	.align 2, 0
_0808D274: .4byte gUnknown_203B45C
	thumb_func_end sub_808D1DC

	thumb_func_start sub_808D278
sub_808D278:
	push {r4-r7,lr}
	lsls r0, 16
	asrs r0, 16
	ldr r1, _0808D29C
	ldr r2, [r1]
	lsls r1, r0, 3
	adds r1, r0
	lsls r1, 3
	adds r1, r2
	ldrb r6, [r1, 0x16]
	ldr r0, _0808D2A0
	ldr r0, [r0]
	adds r0, r6
	ldrb r0, [r0]
	cmp r0, 0
	bne _0808D2AA
	b _0808D2DA
	.align 2, 0
_0808D29C: .4byte gMonsterParameters
_0808D2A0: .4byte gFriendAreas
_0808D2A4:
	ldr r0, [r7]
	adds r0, r5
	b _0808D2DC
_0808D2AA:
	movs r4, 0
	ldr r7, _0808D2E4
_0808D2AE:
	movs r0, 0x58
	adds r5, r4, 0
	muls r5, r0
	ldr r0, [r7]
	adds r0, r5, r0
	ldrb r1, [r0]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	bne _0808D2D0
	adds r0, r4, 0
	bl sub_80923D4
	lsls r0, 24
	lsrs r0, 24
	cmp r0, r6
	beq _0808D2A4
_0808D2D0:
	adds r4, 0x1
	movs r0, 0xCE
	lsls r0, 1
	cmp r4, r0
	ble _0808D2AE
_0808D2DA:
	movs r0, 0
_0808D2DC:
	pop {r4-r7}
	pop {r1}
	bx r1
	.align 2, 0
_0808D2E4: .4byte gUnknown_203B45C
	thumb_func_end sub_808D278

	thumb_func_start sub_808D2E8
sub_808D2E8:
	push {r4-r6,lr}
	sub sp, 0x60
	adds r4, r0, 0
	adds r6, r1, 0
	adds r5, r2, 0
	ldr r0, [sp, 0x70]
	lsls r4, 16
	asrs r4, 16
	lsls r5, 24
	lsrs r5, 24
	str r3, [sp]
	str r0, [sp, 0x4]
	add r0, sp, 0x8
	adds r1, r4, 0
	adds r2, r6, 0
	adds r3, r5, 0
	bl sub_808CFD0
	add r0, sp, 0x8
	bl sub_808D1DC
	add sp, 0x60
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end sub_808D2E8

	thumb_func_start sub_808D31C
sub_808D31C:
	push {lr}
	adds r1, r0, 0
	ldrb r0, [r1, 0x2]
	cmp r0, 0
	bne _0808D338
	movs r2, 0
	ldrb r0, [r1, 0x4]
	cmp r0, 0x41
	bne _0808D330
	movs r2, 0x1
_0808D330:
	adds r0, r2, 0
	cmp r0, 0
	bne _0808D338
	strh r0, [r1]
_0808D338:
	pop {r0}
	bx r0
	thumb_func_end sub_808D31C

	thumb_func_start sub_808D33C
sub_808D33C:
	push {r4,lr}
	movs r3, 0
	ldr r0, _0808D360
	ldr r4, [r0]
_0808D344:
	movs r0, 0x58
	muls r0, r3
	adds r2, r0, r4
	ldrb r1, [r2]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _0808D364
	ldrb r0, [r2, 0x2]
	cmp r0, 0
	beq _0808D364
	adds r0, r2, 0
	b _0808D370
	.align 2, 0
_0808D360: .4byte gUnknown_203B45C
_0808D364:
	adds r3, 0x1
	movs r0, 0xCE
	lsls r0, 1
	cmp r3, r0
	ble _0808D344
	movs r0, 0
_0808D370:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_808D33C

	thumb_func_start sub_808D378
sub_808D378:
	push {r4,lr}
	movs r3, 0
	ldr r0, _0808D3A4
	ldr r4, [r0]
_0808D380:
	movs r0, 0x58
	muls r0, r3
	adds r2, r0, r4
	ldrb r1, [r2]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _0808D3A8
	movs r1, 0
	ldrb r0, [r2, 0x4]
	cmp r0, 0x41
	bne _0808D39A
	movs r1, 0x1
_0808D39A:
	cmp r1, 0
	beq _0808D3A8
	adds r0, r2, 0
	b _0808D3B4
	.align 2, 0
_0808D3A4: .4byte gUnknown_203B45C
_0808D3A8:
	adds r3, 0x1
	movs r0, 0xCE
	lsls r0, 1
	cmp r3, r0
	ble _0808D380
	movs r0, 0
_0808D3B4:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_808D378

	thumb_func_start sub_808D3BC
sub_808D3BC:
	push {r4-r6,lr}
	movs r4, 0
	ldr r0, _0808D3E0
	ldr r2, [r0]
	adds r3, r2, 0
	movs r6, 0x1
	movs r5, 0xCE
	lsls r5, 1
_0808D3CC:
	ldrb r1, [r2]
	adds r0, r6, 0
	ands r0, r1
	cmp r0, 0
	beq _0808D3E4
	ldrb r0, [r2, 0x4]
	cmp r0, 0x40
	bne _0808D3E4
	adds r0, r3, 0
	b _0808D3F0
	.align 2, 0
_0808D3E0: .4byte gUnknown_203B45C
_0808D3E4:
	adds r2, 0x58
	adds r3, 0x58
	adds r4, 0x1
	cmp r4, r5
	ble _0808D3CC
	movs r0, 0
_0808D3F0:
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end sub_808D3BC

	thumb_func_start sub_808D3F8
sub_808D3F8:
	push {r4-r6,lr}
	movs r4, 0
	ldr r0, _0808D41C
	ldr r2, [r0]
	adds r3, r2, 0
	movs r6, 0x1
	movs r5, 0xCE
	lsls r5, 1
_0808D408:
	ldrb r1, [r2]
	adds r0, r6, 0
	ands r0, r1
	cmp r0, 0
	beq _0808D420
	ldrb r0, [r2, 0x4]
	cmp r0, 0x41
	bne _0808D420
	adds r0, r3, 0
	b _0808D42C
	.align 2, 0
_0808D41C: .4byte gUnknown_203B45C
_0808D420:
	adds r2, 0x58
	adds r3, 0x58
	adds r4, 0x1
	cmp r4, r5
	ble _0808D408
	movs r0, 0
_0808D42C:
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end sub_808D3F8

	thumb_func_start sub_808D434
sub_808D434:
	push {r4-r7,lr}
	adds r6, r1, 0
	lsls r0, 16
	asrs r5, r0, 16
	ldr r0, _0808D468
	ldr r2, [r0]
	movs r4, 0
	movs r3, 0
	movs r0, 0x1
	mov r12, r0
	movs r7, 0xCE
	lsls r7, 1
_0808D44C:
	ldrb r1, [r2]
	mov r0, r12
	ands r0, r1
	cmp r0, 0
	beq _0808D46E
	movs r1, 0x8
	ldrsh r0, [r2, r1]
	cmp r0, r5
	bne _0808D46E
	cmp r4, r6
	bne _0808D46C
	adds r0, r2, 0
	b _0808D478
	.align 2, 0
_0808D468: .4byte gUnknown_203B45C
_0808D46C:
	adds r4, 0x1
_0808D46E:
	adds r3, 0x1
	adds r2, 0x58
	cmp r3, r7
	ble _0808D44C
	movs r0, 0
_0808D478:
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_808D434

	thumb_func_start sub_808D480
sub_808D480:
	push {r4,r5,lr}
	ldr r0, _0808D4A8
	ldr r2, [r0]
	movs r4, 0
	movs r5, 0x1
	ldr r3, _0808D4AC
_0808D48C:
	ldrb r1, [r2]
	adds r0, r5, 0
	ands r0, r1
	cmp r0, 0
	beq _0808D498
	adds r4, 0x1
_0808D498:
	subs r3, 0x1
	adds r2, 0x58
	cmp r3, 0
	bne _0808D48C
	adds r0, r4, 0
	pop {r4,r5}
	pop {r1}
	bx r1
	.align 2, 0
_0808D4A8: .4byte gUnknown_203B45C
_0808D4AC: .4byte 0x0000019d
	thumb_func_end sub_808D480

	thumb_func_start sub_808D4B0
sub_808D4B0:
	push {r4-r6,lr}
	ldr r0, _0808D4F8
	ldr r2, [r0]
	movs r5, 0
	movs r4, 0
	ldr r6, _0808D4FC
_0808D4BC:
	ldrh r3, [r2]
	lsrs r0, r3, 1
	movs r1, 0x1
	ands r0, r1
	cmp r0, 0
	beq _0808D4E4
	ldrb r0, [r2, 0x2]
	cmp r0, 0
	bne _0808D4E4
	movs r1, 0
	ldrb r0, [r2, 0x4]
	cmp r0, 0x41
	bne _0808D4D8
	movs r1, 0x1
_0808D4D8:
	cmp r1, 0
	bne _0808D4E4
	movs r5, 0x1
	adds r0, r6, 0
	ands r0, r3
	strh r0, [r2]
_0808D4E4:
	adds r4, 0x1
	adds r2, 0x58
	movs r0, 0xCE
	lsls r0, 1
	cmp r4, r0
	ble _0808D4BC
	adds r0, r5, 0
	pop {r4-r6}
	pop {r1}
	bx r1
	.align 2, 0
_0808D4F8: .4byte gUnknown_203B45C
_0808D4FC: .4byte 0x0000fffd
	thumb_func_end sub_808D4B0

	thumb_func_start sub_808D500
sub_808D500:
	push {r4-r6,lr}
	ldr r0, _0808D53C
	ldr r2, [r0]
	movs r5, 0
	movs r4, 0
	ldr r6, _0808D540
_0808D50C:
	ldrh r3, [r2]
	lsrs r0, r3, 1
	movs r1, 0x1
	ands r0, r1
	cmp r0, 0
	beq _0808D526
	ldrb r0, [r2, 0x2]
	cmp r0, 0
	bne _0808D526
	movs r5, 0x1
	adds r0, r6, 0
	ands r0, r3
	strh r0, [r2]
_0808D526:
	adds r4, 0x1
	adds r2, 0x58
	movs r0, 0xCE
	lsls r0, 1
	cmp r4, r0
	ble _0808D50C
	adds r0, r5, 0
	pop {r4-r6}
	pop {r1}
	bx r1
	.align 2, 0
_0808D53C: .4byte gUnknown_203B45C
_0808D540: .4byte 0x0000fffd
	thumb_func_end sub_808D500

	thumb_func_start sub_808D544
sub_808D544:
	push {r4-r7,lr}
	adds r4, r0, 0
	ldr r0, _0808D57C
	ldr r3, [r0]
	movs r5, 0
	movs r2, 0
	movs r7, 0x1
	movs r6, 0xCE
	lsls r6, 1
	adds r1, r4, 0
_0808D558:
	ldrh r0, [r3]
	lsrs r0, 1
	ands r0, r7
	cmp r0, 0
	beq _0808D56C
	cmp r4, 0
	beq _0808D568
	str r2, [r1]
_0808D568:
	adds r1, 0x4
	adds r5, 0x1
_0808D56C:
	adds r2, 0x1
	adds r3, 0x58
	cmp r2, r6
	ble _0808D558
	adds r0, r5, 0
	pop {r4-r7}
	pop {r1}
	bx r1
	.align 2, 0
_0808D57C: .4byte gUnknown_203B45C
	thumb_func_end sub_808D544

	thumb_func_start sub_808D580
sub_808D580:
	push {r4-r7,lr}
	adds r6, r0, 0
	ldr r0, _0808D5AC
	ldr r2, [r0]
	movs r5, 0
	movs r4, 0
	mov r12, r0
	adds r3, r6, 0
_0808D590:
	ldrb r0, [r2, 0x2]
	cmp r0, 0
	beq _0808D5B0
	ldrb r1, [r2]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _0808D5B0
	cmp r6, 0
	beq _0808D5B0
	str r4, [r3]
	adds r5, 0x1
	b _0808D5BC
	.align 2, 0
_0808D5AC: .4byte gUnknown_203B45C
_0808D5B0:
	adds r4, 0x1
	adds r2, 0x58
	movs r0, 0xCE
	lsls r0, 1
	cmp r4, r0
	ble _0808D590
_0808D5BC:
	mov r0, r12
	ldr r2, [r0]
	movs r4, 0
	lsls r0, r5, 2
	adds r7, r0, r6
_0808D5C6:
	movs r1, 0
	ldrb r0, [r2, 0x4]
	cmp r0, 0x41
	bne _0808D5D0
	movs r1, 0x1
_0808D5D0:
	cmp r1, 0
	beq _0808D5F8
	ldrb r0, [r2, 0x2]
	cmp r0, 0
	bne _0808D5F8
	ldrh r1, [r2]
	lsrs r0, r1, 1
	movs r3, 0x1
	ands r0, r3
	cmp r0, 0
	beq _0808D5F8
	adds r0, r3, 0
	ands r0, r1
	cmp r0, 0
	beq _0808D5F8
	cmp r6, 0
	beq _0808D5F8
	str r4, [r7]
	adds r5, 0x1
	b _0808D604
_0808D5F8:
	adds r4, 0x1
	adds r2, 0x58
	movs r0, 0xCE
	lsls r0, 1
	cmp r4, r0
	ble _0808D5C6
_0808D604:
	mov r0, r12
	ldr r2, [r0]
	movs r4, 0
	movs r3, 0x1
	lsls r0, r5, 2
	adds r7, r0, r6
_0808D610:
	ldrh r1, [r2]
	lsrs r0, r1, 1
	ands r0, r3
	cmp r0, 0
	beq _0808D63E
	adds r0, r3, 0
	ands r0, r1
	cmp r0, 0
	beq _0808D63E
	ldrb r0, [r2, 0x2]
	cmp r0, 0
	bne _0808D63E
	movs r1, 0
	ldrb r0, [r2, 0x4]
	cmp r0, 0x41
	bne _0808D632
	movs r1, 0x1
_0808D632:
	cmp r1, 0
	bne _0808D63E
	cmp r6, 0
	beq _0808D63E
	stm r7!, {r4}
	adds r5, 0x1
_0808D63E:
	adds r4, 0x1
	adds r2, 0x58
	movs r0, 0xCE
	lsls r0, 1
	cmp r4, r0
	ble _0808D610
	adds r0, r5, 0
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_808D580

	thumb_func_start sub_808D654
sub_808D654:
	push {r4-r6,lr}
	adds r5, r0, 0
	ldr r0, _0808D6A0
	ldr r2, [r0]
	movs r6, 0
	movs r4, 0
	adds r3, r5, 0
_0808D662:
	ldrh r0, [r2]
	lsrs r0, 1
	movs r1, 0x1
	ands r0, r1
	cmp r0, 0
	beq _0808D68C
	ldrb r0, [r2, 0x2]
	cmp r0, 0
	bne _0808D68C
	movs r1, 0
	ldrb r0, [r2, 0x4]
	cmp r0, 0x41
	bne _0808D67E
	movs r1, 0x1
_0808D67E:
	cmp r1, 0
	bne _0808D68C
	cmp r5, 0
	beq _0808D688
	str r4, [r3]
_0808D688:
	adds r3, 0x4
	adds r6, 0x1
_0808D68C:
	adds r4, 0x1
	adds r2, 0x58
	movs r0, 0xCE
	lsls r0, 1
	cmp r4, r0
	ble _0808D662
	adds r0, r6, 0
	pop {r4-r6}
	pop {r1}
	bx r1
	.align 2, 0
_0808D6A0: .4byte gUnknown_203B45C
	thumb_func_end sub_808D654

	thumb_func_start sub_808D6A4
sub_808D6A4:
	push {r4-r6,lr}
	adds r5, r0, 0
	ldr r0, _0808D6E4
	ldr r2, [r0]
	movs r6, 0
	movs r4, 0
	adds r3, r5, 0
_0808D6B2:
	ldrh r0, [r2]
	lsrs r0, 1
	movs r1, 0x1
	ands r0, r1
	cmp r0, 0
	beq _0808D6CE
	ldrb r0, [r2, 0x2]
	cmp r0, 0
	bne _0808D6CE
	cmp r5, 0
	beq _0808D6CA
	str r4, [r3]
_0808D6CA:
	adds r3, 0x4
	adds r6, 0x1
_0808D6CE:
	adds r4, 0x1
	adds r2, 0x58
	movs r0, 0xCE
	lsls r0, 1
	cmp r4, r0
	ble _0808D6B2
	adds r0, r6, 0
	pop {r4-r6}
	pop {r1}
	bx r1
	.align 2, 0
_0808D6E4: .4byte gUnknown_203B45C
	thumb_func_end sub_808D6A4

	thumb_func_start sub_808D6E8
sub_808D6E8:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	movs r7, 0
	movs r5, 0
	movs r4, 0
	ldr r0, _0808D740
	mov r8, r0
	movs r6, 0x1
_0808D6FA:
	movs r0, 0x58
	adds r1, r4, 0
	muls r1, r0
	mov r2, r8
	ldr r0, [r2]
	adds r2, r0, r1
	ldrh r1, [r2]
	adds r0, r6, 0
	ands r0, r1
	cmp r0, 0
	beq _0808D728
	lsrs r0, r1, 1
	ands r0, r6
	cmp r0, 0
	beq _0808D728
	movs r1, 0x8
	ldrsh r0, [r2, r1]
	bl GetPokemonSize
	lsls r0, 24
	lsrs r0, 24
	adds r5, r0
	adds r7, 0x1
_0808D728:
	adds r4, 0x1
	movs r0, 0xCE
	lsls r0, 1
	cmp r4, r0
	ble _0808D6FA
	cmp r5, 0x5
	bgt _0808D744
	cmp r7, 0x3
	bgt _0808D744
	movs r0, 0x1
	b _0808D746
	.align 2, 0
_0808D740: .4byte gUnknown_203B45C
_0808D744:
	movs r0, 0
_0808D746:
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_808D6E8

	thumb_func_start sub_808D750
sub_808D750:
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	lsls r0, 16
	asrs r0, 16
	mov r8, r0
	movs r6, 0
	movs r5, 0
	movs r4, 0
	ldr r0, _0808D7C8
	mov r9, r0
	movs r7, 0x1
_0808D76A:
	movs r0, 0x58
	adds r1, r4, 0
	muls r1, r0
	mov r2, r9
	ldr r0, [r2]
	adds r1, r0, r1
	ldrh r2, [r1]
	adds r0, r7, 0
	ands r0, r2
	cmp r0, 0
	beq _0808D798
	lsrs r0, r2, 1
	ands r0, r7
	cmp r0, 0
	beq _0808D798
	movs r2, 0x8
	ldrsh r0, [r1, r2]
	bl GetPokemonSize
	lsls r0, 24
	lsrs r0, 24
	adds r5, r0
	adds r6, 0x1
_0808D798:
	adds r4, 0x1
	movs r0, 0xCE
	lsls r0, 1
	cmp r4, r0
	ble _0808D76A
	cmp r6, 0x3
	bgt _0808D7CC
	ldr r2, _0808D7C8
	movs r0, 0x58
	mov r1, r8
	muls r1, r0
	ldr r0, [r2]
	adds r1, r0, r1
	movs r2, 0x8
	ldrsh r0, [r1, r2]
	bl GetPokemonSize
	lsls r0, 24
	lsrs r0, 24
	adds r5, r0
	cmp r5, 0x6
	bgt _0808D7CC
	movs r0, 0x1
	b _0808D7CE
	.align 2, 0
_0808D7C8: .4byte gUnknown_203B45C
_0808D7CC:
	movs r0, 0
_0808D7CE:
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_808D750

	thumb_func_start sub_808D7DC
sub_808D7DC:
	lsls r0, 16
	asrs r0, 16
	ldr r3, _0808D7FC
	movs r2, 0x58
	muls r2, r0
	ldr r0, [r3]
	adds r0, r2
	adds r2, r0, 0
	adds r2, 0x28
	ldrb r2, [r2]
	strb r2, [r1]
	adds r0, 0x29
	ldrb r0, [r0]
	strb r0, [r1, 0x1]
	bx lr
	.align 2, 0
_0808D7FC: .4byte gUnknown_203B45C
	thumb_func_end sub_808D7DC

	thumb_func_start sub_808D800
sub_808D800:
	lsls r0, 16
	asrs r0, 16
	ldr r3, _0808D820
	movs r2, 0x58
	muls r2, r0
	ldr r0, [r3]
	adds r0, r2
	ldrb r3, [r1]
	adds r2, r0, 0
	adds r2, 0x28
	strb r3, [r2]
	ldrb r1, [r1, 0x1]
	adds r0, 0x29
	strb r1, [r0]
	bx lr
	.align 2, 0
_0808D820: .4byte gUnknown_203B45C
	thumb_func_end sub_808D800

	thumb_func_start sub_808D824
sub_808D824:
	push {r4,lr}
	sub sp, 0x14
	adds r4, r0, 0
	movs r1, 0x8
	ldrsh r0, [r4, r1]
	bl GetMonSpecies
	adds r1, r0, 0
	mov r0, sp
	bl CopyStringtoBuffer
	movs r2, 0
	adds r4, 0x4C
_0808D83E:
	adds r0, r4, r2
	mov r3, sp
	adds r1, r3, r2
	ldrb r0, [r0]
	ldrb r1, [r1]
	cmp r0, r1
	beq _0808D850
	movs r0, 0
	b _0808D85C
_0808D850:
	cmp r0, 0
	beq _0808D85A
	adds r2, 0x1
	cmp r2, 0x9
	ble _0808D83E
_0808D85A:
	movs r0, 0x1
_0808D85C:
	add sp, 0x14
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_808D824

	thumb_func_start sub_808D864
sub_808D864:
	push {r4-r7,lr}
	lsls r0, 16
	asrs r0, 16
	lsls r1, 16
	asrs r1, 16
	ldr r2, _0808D8A0
	movs r3, 0x58
	muls r0, r3
	ldr r2, [r2]
	adds r0, r2, r0
	adds r6, r0, 0
	adds r6, 0x4C
	adds r0, r1, 0
	muls r0, r3
	adds r2, r0
	adds r5, r2, 0
	adds r5, 0x4C
	movs r7, 0
_0808D888:
	ldrb r0, [r6]
	bl ReturnIntFromChar
	adds r4, r0, 0
	ldrb r0, [r5]
	bl ReturnIntFromChar
	cmp r4, r0
	ble _0808D8A4
	movs r0, 0x1
	b _0808D8B4
	.align 2, 0
_0808D8A0: .4byte gUnknown_203B45C
_0808D8A4:
	cmp r4, r0
	blt _0808D8B2
	adds r6, 0x1
	adds r5, 0x1
	adds r7, 0x1
	cmp r7, 0x9
	ble _0808D888
_0808D8B2:
	movs r0, 0
_0808D8B4:
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_808D864


.align 2,0
