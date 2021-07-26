	.include "constants/gba_constants.inc"
	.include "asm/macros.inc"

	.syntax unified

	.text

	thumb_func_start sub_80978C8
sub_80978C8:
	push {lr}
	lsls r0, 16
	asrs r0, 16
	bl GetBaseSpeciesNoUnown
	lsls r0, 16
	asrs r3, r0, 16
	ldr r0, _080978FC
	ldr r2, [r0]
	adds r0, r3, 0
	cmp r3, 0
	bge _080978E2
	adds r0, 0x1F
_080978E2:
	asrs r0, 5
	lsls r1, r0, 2
	adds r2, 0x54
	adds r2, r1
	lsls r0, 5
	subs r0, r3, r0
	movs r1, 0x1
	lsls r1, r0
	ldr r0, [r2]
	orrs r0, r1
	str r0, [r2]
	pop {r0}
	bx r0
	.align 2, 0
_080978FC: .4byte gUnknown_203B494
	thumb_func_end sub_80978C8

	thumb_func_start sub_8097900
sub_8097900:
	push {lr}
	lsls r0, 16
	asrs r0, 16
	bl GetBaseSpeciesNoUnown
	lsls r0, 16
	asrs r3, r0, 16
	ldr r0, _08097938
	ldr r2, [r0]
	adds r0, r3, 0
	cmp r3, 0
	bge _0809791A
	adds r0, 0x1F
_0809791A:
	asrs r0, 5
	lsls r1, r0, 2
	adds r2, 0x1C
	adds r2, r1
	lsls r0, 5
	subs r0, r3, r0
	movs r1, 0x1
	lsls r1, r0
	ldr r0, [r2]
	ands r0, r1
	cmp r0, 0
	bne _0809793C
	movs r0, 0
	b _0809793E
	.align 2, 0
_08097938: .4byte gUnknown_203B494
_0809793C:
	movs r0, 0x1
_0809793E:
	pop {r1}
	bx r1
	thumb_func_end sub_8097900

	thumb_func_start sub_8097944
sub_8097944:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x8
	movs r0, 0x1
	str r0, [sp]
	movs r1, 0x1
	str r1, [sp, 0x4]
	movs r0, 0xD
	bl sub_8097710
	lsls r0, 24
	cmp r0, 0
	bne _08097974
	bl HasAllFriendAreas
	lsls r0, 24
	cmp r0, 0
	beq _08097974
	movs r0, 0xD
	bl sub_80976F8
_08097974:
	movs r4, 0
	ldr r0, _08097B5C
	mov r10, r0
	mov r8, r4
_0809797C:
	ldr r1, _08097B60
	ldr r0, [r1]
	mov r1, r8
	adds r2, r1, r0
	ldrb r1, [r2]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _080979F6
	movs r0, 0x8
	ldrsh r3, [r2, r0]
	mov r1, r10
	ldr r2, [r1]
	adds r0, r3, 0
	cmp r3, 0
	bge _0809799E
	adds r0, 0x1F
_0809799E:
	asrs r0, 5
	lsls r1, r0, 2
	adds r2, 0x1C
	adds r2, r1
	lsls r0, 5
	subs r0, r3, r0
	movs r1, 0x1
	lsls r1, r0
	ldr r0, [r2]
	orrs r0, r1
	str r0, [r2]
	ldr r0, _08097B60
	mov r9, r0
	mov r12, r8
	movs r7, 0x1
	movs r6, 0x2C
	movs r5, 0x3
_080979C0:
	mov r1, r9
	ldr r0, [r1]
	add r0, r12
	adds r3, r0, r6
	ldrb r1, [r3]
	adds r0, r7, 0
	ands r0, r1
	cmp r0, 0
	beq _080979EE
	mov r0, r10
	ldr r2, [r0]
	ldrh r3, [r3, 0x2]
	lsrs r0, r3, 5
	lsls r0, 2
	adds r2, 0x8C
	adds r2, r0
	movs r0, 0x1F
	ands r3, r0
	adds r1, r7, 0
	lsls r1, r3
	ldr r0, [r2]
	orrs r0, r1
	str r0, [r2]
_080979EE:
	adds r6, 0x8
	subs r5, 0x1
	cmp r5, 0
	bge _080979C0
_080979F6:
	movs r1, 0x58
	add r8, r1
	adds r4, 0x1
	movs r0, 0xCE
	lsls r0, 1
	cmp r4, r0
	ble _0809797C
	movs r4, 0
	ldr r1, _08097B64
_08097A08:
	cmp r4, 0
	bne _08097A0E
	b _08097B80
_08097A0E:
	ldr r0, _08097B68
	cmp r4, r0
	bne _08097A16
	b _08097B80
_08097A16:
	adds r0, 0x1
	cmp r4, r0
	bne _08097A1E
	b _08097B80
_08097A1E:
	adds r0, 0x1
	cmp r4, r0
	bne _08097A26
	b _08097B80
_08097A26:
	adds r0, 0x26
	cmp r4, r0
	bne _08097A2E
	b _08097B80
_08097A2E:
	adds r0, 0x1
	cmp r4, r0
	bne _08097A36
	b _08097B80
_08097A36:
	adds r0, 0x1
	cmp r4, r0
	bne _08097A3E
	b _08097B80
_08097A3E:
	adds r0, 0x1
	cmp r4, r0
	bne _08097A46
	b _08097B80
_08097A46:
	adds r0, 0x1
	cmp r4, r0
	bne _08097A4E
	b _08097B80
_08097A4E:
	adds r0, 0x1
	cmp r4, r0
	bne _08097A56
	b _08097B80
_08097A56:
	cmp r4, r1
	bne _08097A5C
	b _08097B80
_08097A5C:
	ldr r0, _08097B5C
	ldr r5, [r0]
	adds r0, r4, 0
	cmp r4, 0
	bge _08097A68
	adds r0, 0x1F
_08097A68:
	asrs r0, 5
	lsls r3, r0, 2
	adds r1, r5, 0
	adds r1, 0x54
	adds r1, r3
	lsls r0, 5
	subs r0, r4, r0
	movs r2, 0x1
	lsls r2, r0
	ldr r0, [r1]
	ands r0, r2
	cmp r0, 0
	bne _08097A86
	movs r0, 0
	str r0, [sp, 0x4]
_08097A86:
	adds r0, r5, 0
	adds r0, 0x1C
	adds r0, r3
	ldr r0, [r0]
	ands r0, r2
	cmp r0, 0
	beq _08097B7C
	cmp r4, 0x92
	bne _08097A9E
	movs r0, 0x10
	bl sub_80976F8
_08097A9E:
	cmp r4, 0x91
	bne _08097AA8
	movs r0, 0x11
	bl sub_80976F8
_08097AA8:
	cmp r4, 0x90
	bne _08097AB2
	movs r0, 0x12
	bl sub_80976F8
_08097AB2:
	movs r0, 0xCF
	lsls r0, 1
	cmp r4, r0
	bne _08097AC0
	movs r0, 0x13
	bl sub_80976F8
_08097AC0:
	ldr r0, _08097B6C
	cmp r4, r0
	bne _08097ACC
	movs r0, 0x14
	bl sub_80976F8
_08097ACC:
	movs r0, 0x86
	lsls r0, 1
	cmp r4, r0
	bne _08097ADA
	movs r0, 0x15
	bl sub_80976F8
_08097ADA:
	movs r0, 0x87
	lsls r0, 1
	cmp r4, r0
	bne _08097AE8
	movs r0, 0x16
	bl sub_80976F8
_08097AE8:
	ldr r0, _08097B70
	cmp r4, r0
	bne _08097AF4
	movs r0, 0x17
	bl sub_80976F8
_08097AF4:
	movs r0, 0xCD
	lsls r0, 1
	cmp r4, r0
	bne _08097B02
	movs r0, 0x18
	bl sub_80976F8
_08097B02:
	ldr r0, _08097B74
	cmp r4, r0
	bne _08097B0E
	movs r0, 0x19
	bl sub_80976F8
_08097B0E:
	movs r0, 0xCE
	lsls r0, 1
	cmp r4, r0
	bne _08097B1C
	movs r0, 0x1A
	bl sub_80976F8
_08097B1C:
	movs r0, 0x89
	lsls r0, 1
	cmp r4, r0
	bne _08097B2A
	movs r0, 0x1B
	bl sub_80976F8
_08097B2A:
	movs r0, 0x8A
	lsls r0, 1
	cmp r4, r0
	bne _08097B38
	movs r0, 0x1C
	bl sub_80976F8
_08097B38:
	cmp r4, 0x97
	bne _08097B42
	movs r0, 0x1D
	bl sub_80976F8
_08097B42:
	cmp r4, 0x96
	bne _08097B4C
	movs r0, 0x1E
	bl sub_80976F8
_08097B4C:
	ldr r0, _08097B78
	cmp r4, r0
	bne _08097B80
	movs r0, 0x1F
	bl sub_80976F8
	b _08097B80
	.align 2, 0
_08097B5C: .4byte gUnknown_203B494
_08097B60: .4byte gRecruitedPokemonRef
_08097B64: .4byte 0x000001a7
_08097B68: .4byte 0x00000179
_08097B6C: .4byte 0x0000010d
_08097B70: .4byte 0x00000113
_08097B74: .4byte 0x0000019b
_08097B78: .4byte 0x0000019d
_08097B7C:
	movs r1, 0
	str r1, [sp]
_08097B80:
	adds r4, 0x1
	ldr r1, _08097C0C
	cmp r4, r1
	bgt _08097B8A
	b _08097A08
_08097B8A:
	ldr r0, [sp]
	cmp r0, 0
	beq _08097B96
	movs r0, 0xF
	bl sub_80976F8
_08097B96:
	ldr r1, [sp, 0x4]
	cmp r1, 0
	beq _08097BA2
	movs r0, 0xE
	bl sub_80976F8
_08097BA2:
	movs r3, 0
	movs r4, 0
_08097BA6:
	cmp r4, 0
	beq _08097BE2
	ldr r0, _08097C10
	cmp r4, r0
	beq _08097BE2
	adds r0, 0x1
	cmp r4, r0
	beq _08097BE2
	adds r0, 0x1
	cmp r4, r0
	beq _08097BE2
	ldr r0, _08097C14
	ldr r2, [r0]
	adds r0, r4, 0
	cmp r4, 0
	bge _08097BC8
	adds r0, 0x1F
_08097BC8:
	asrs r0, 5
	lsls r1, r0, 2
	adds r2, 0x8C
	adds r2, r1
	lsls r0, 5
	subs r0, r4, r0
	movs r1, 0x1
	lsls r1, r0
	ldr r0, [r2]
	ands r0, r1
	cmp r0, 0
	beq _08097BE2
	adds r3, 0x1
_08097BE2:
	adds r4, 0x1
	movs r0, 0xCE
	lsls r0, 1
	cmp r4, r0
	ble _08097BA6
	cmp r3, 0
	beq _08097BFC
	ldr r0, _08097C14
	ldr r0, [r0]
	strh r3, [r0, 0x18]
	movs r0, 0x7
	bl sub_80976F8
_08097BFC:
	add sp, 0x8
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_08097C0C: .4byte 0x000001a7
_08097C10: .4byte 0x00000163
_08097C14: .4byte gUnknown_203B494
	thumb_func_end sub_8097944

	thumb_func_start sub_8097C18
sub_8097C18:
	push {r4-r6,lr}
	adds r5, r0, 0
	bl sub_8097944
	ldr r4, _08097CBC
	ldr r1, [r4]
	adds r1, 0x4
	adds r0, r5, 0
	movs r2, 0x11
	bl sub_809488C
	ldr r1, [r4]
	adds r1, 0x8
	adds r0, r5, 0
	movs r2, 0x11
	bl sub_809488C
	ldr r1, [r4]
	adds r1, 0xC
	adds r0, r5, 0
	movs r2, 0x11
	bl sub_809488C
	ldr r1, [r4]
	adds r0, r5, 0
	movs r2, 0x20
	bl sub_809488C
	ldr r1, [r4]
	adds r1, 0x14
	adds r0, r5, 0
	movs r2, 0xE
	bl sub_809488C
	ldr r1, [r4]
	adds r1, 0x16
	adds r0, r5, 0
	movs r2, 0xE
	bl sub_809488C
	ldr r1, [r4]
	adds r1, 0x18
	adds r0, r5, 0
	movs r2, 0x9
	bl sub_809488C
	ldr r1, [r4]
	adds r1, 0xC0
	adds r0, r5, 0
	movs r2, 0x11
	bl sub_809488C
	ldr r1, [r4]
	adds r1, 0x1C
	movs r6, 0xE0
	lsls r6, 1
	adds r0, r5, 0
	adds r2, r6, 0
	bl sub_809488C
	ldr r1, [r4]
	adds r1, 0x54
	adds r0, r5, 0
	adds r2, r6, 0
	bl sub_809488C
	ldr r1, [r4]
	adds r1, 0x8C
	movs r2, 0xD0
	lsls r2, 1
	adds r0, r5, 0
	bl sub_809488C
	ldr r1, [r4]
	adds r1, 0x10
	adds r0, r5, 0
	bl sub_80902F4
	pop {r4-r6}
	pop {r0}
	bx r0
	.align 2, 0
_08097CBC: .4byte gUnknown_203B494
	thumb_func_end sub_8097C18

	thumb_func_start sub_8097CC0
sub_8097CC0:
	push {r4-r6,lr}
	adds r5, r0, 0
	ldr r4, _08097D5C
	ldr r1, [r4]
	adds r1, 0x4
	movs r2, 0x11
	bl sub_8094924
	ldr r1, [r4]
	adds r1, 0x8
	adds r0, r5, 0
	movs r2, 0x11
	bl sub_8094924
	ldr r1, [r4]
	adds r1, 0xC
	adds r0, r5, 0
	movs r2, 0x11
	bl sub_8094924
	ldr r1, [r4]
	adds r0, r5, 0
	movs r2, 0x20
	bl sub_8094924
	ldr r1, [r4]
	adds r1, 0x14
	adds r0, r5, 0
	movs r2, 0xE
	bl sub_8094924
	ldr r1, [r4]
	adds r1, 0x16
	adds r0, r5, 0
	movs r2, 0xE
	bl sub_8094924
	ldr r1, [r4]
	adds r1, 0x18
	adds r0, r5, 0
	movs r2, 0x9
	bl sub_8094924
	ldr r1, [r4]
	adds r1, 0xC0
	adds r0, r5, 0
	movs r2, 0x11
	bl sub_8094924
	ldr r1, [r4]
	adds r1, 0x1C
	movs r6, 0xE0
	lsls r6, 1
	adds r0, r5, 0
	adds r2, r6, 0
	bl sub_8094924
	ldr r1, [r4]
	adds r1, 0x54
	adds r0, r5, 0
	adds r2, r6, 0
	bl sub_8094924
	ldr r1, [r4]
	adds r1, 0x8C
	movs r2, 0xD0
	lsls r2, 1
	adds r0, r5, 0
	bl sub_8094924
	ldr r1, [r4]
	adds r1, 0x10
	adds r0, r5, 0
	bl sub_8090314
	pop {r4-r6}
	pop {r0}
	bx r0
	.align 2, 0
_08097D5C: .4byte gUnknown_203B494
	thumb_func_end sub_8097CC0

	thumb_func_start sub_8097D60
sub_8097D60:
	push {lr}
	sub sp, 0x10
	adds r3, r0, 0
	adds r2, r1, 0
	mov r0, sp
	adds r1, r3, 0
	bl sub_809486C
	mov r0, sp
	bl WriteGameOptions
	mov r0, sp
	bl WritePlayTime
	mov r0, sp
	bl sub_8097C18
	mov r0, sp
	bl WriteExclusivePokemon
	mov r0, sp
	bl nullsub_102
	ldr r0, [sp, 0x8]
	add sp, 0x10
	pop {r1}
	bx r1
	thumb_func_end sub_8097D60

	thumb_func_start sub_8097D98
sub_8097D98:
	push {lr}
	sub sp, 0x10
	adds r3, r0, 0
	adds r2, r1, 0
	mov r0, sp
	adds r1, r3, 0
	bl sub_809485C
	mov r0, sp
	bl ReadGameOptions
	mov r0, sp
	bl ReadPlayTime
	mov r0, sp
	bl sub_8097CC0
	mov r0, sp
	bl ReadExclusivePokemon
	mov r0, sp
	bl nullsub_102
	ldr r0, [sp, 0x8]
	add sp, 0x10
	pop {r1}
	bx r1
	thumb_func_end sub_8097D98

	thumb_func_start sub_8097DD0
sub_8097DD0:
	push {lr}
	adds r2, r0, 0
	adds r3, r1, 0
	ldr r1, [r2]
	ldr r0, [r3]
	cmp r1, r0
	bne _08097DEA
	ldr r1, [r2, 0x4]
	ldr r0, [r3, 0x4]
	cmp r1, r0
	bne _08097DEA
	movs r0, 0x1
	b _08097DEC
_08097DEA:
	movs r0, 0
_08097DEC:
	pop {r1}
	bx r1
	thumb_func_end sub_8097DD0

	thumb_func_start sub_8097DF0
sub_8097DF0:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x1F8
	mov r8, r0
	str r1, [sp, 0x1F0]
	movs r0, 0
	mov r9, r0
	movs r7, 0
	ldr r1, _08097E3C
	ldr r0, [r1]
	cmp r0, 0
	beq _08097E6E
_08097E0E:
	movs r4, 0
	lsls r5, r7, 3
	lsls r1, r7, 2
	mov r10, r1
	adds r6, r7, 0x1
	ldr r2, _08097E3C
	adds r3, r5, r2
	add r1, sp, 0x18C
_08097E1E:
	ldr r0, [r3]
	adds r0, r4
	ldrb r2, [r0]
	cmp r2, 0x23
	bne _08097E40
	ldrb r0, [r0, 0x1]
	cmp r0, 0x72
	bne _08097E40
	strb r2, [r1]
	adds r1, 0x1
	strb r0, [r1]
	adds r1, 0x1
	movs r0, 0
	strb r0, [r1]
	b _08097E50
	.align 2, 0
_08097E3C: .4byte gStatusDescriptions
_08097E40:
	ldr r0, [r3]
	adds r0, r4
	ldrb r0, [r0]
	strb r0, [r1]
	adds r1, 0x1
	adds r4, 0x1
	cmp r4, 0x63
	ble _08097E1E
_08097E50:
	add r0, sp, 0x18C
	bl strlen
	mov r1, sp
	add r1, r10
	str r0, [r1]
	adds r7, r6, 0
	cmp r6, 0x62
	bgt _08097E6E
	lsls r0, r6, 3
	ldr r1, _08097EB4
	adds r0, r1
	ldr r0, [r0]
	cmp r0, 0
	bne _08097E0E
_08097E6E:
	mov r2, r8
	ldrb r0, [r2]
	cmp r0, 0
	beq _08097F2C
	ldr r3, _08097EB4
_08097E78:
	cmp r0, 0x23
	bne _08097F08
	movs r7, 0
	adds r1, r3, 0
	ldr r0, [r1]
	cmp r0, 0
	beq _08097F20
	mov r2, r9
	lsls r0, r2, 2
	ldr r2, [sp, 0x1F0]
	adds r0, r2
	mov r10, r0
_08097E90:
	lsls r4, r7, 3
	adds r0, r4, r1
	ldr r0, [r0]
	lsls r1, r7, 2
	add r1, sp
	ldr r2, [r1]
	mov r1, r8
	str r3, [sp, 0x1F4]
	bl sub_800B2D4
	lsls r0, 24
	adds r5, r4, 0
	adds r6, r7, 0x1
	ldr r3, [sp, 0x1F4]
	cmp r0, 0
	bne _08097EF0
	movs r4, 0
	b _08097EBA
	.align 2, 0
_08097EB4: .4byte gStatusDescriptions
_08097EB8:
	adds r4, 0x1
_08097EBA:
	cmp r4, r9
	bge _08097ED6
	adds r0, r5, r3
	lsls r1, r4, 2
	ldr r2, [sp, 0x1F0]
	adds r1, r2
	ldr r1, [r1]
	str r3, [sp, 0x1F4]
	bl sub_8097DD0
	lsls r0, 24
	ldr r3, [sp, 0x1F4]
	cmp r0, 0
	beq _08097EB8
_08097ED6:
	cmp r4, r9
	bne _08097EF0
	mov r0, r9
	cmp r0, 0x3
	bgt _08097EF0
	adds r0, r5, r3
	mov r1, r10
	adds r1, 0x4
	mov r10, r1
	subs r1, 0x4
	stm r1!, {r0}
	movs r2, 0x1
	add r9, r2
_08097EF0:
	adds r7, r6, 0
	cmp r6, 0x62
	bgt _08097F20
	ldr r1, _08097F04
	lsls r0, r6, 3
	adds r0, r1
	ldr r0, [r0]
	cmp r0, 0
	bne _08097E90
	b _08097F20
	.align 2, 0
_08097F04: .4byte gStatusDescriptions
_08097F08:
	mov r0, r8
	ldrb r1, [r0]
	adds r0, r1, 0
	adds r0, 0x7F
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x3
	bls _08097F1C
	cmp r1, 0x87
	bne _08097F20
_08097F1C:
	movs r1, 0x1
	add r8, r1
_08097F20:
	movs r2, 0x1
	add r8, r2
	mov r1, r8
	ldrb r0, [r1]
	cmp r0, 0
	bne _08097E78
_08097F2C:
	mov r0, r9
	add sp, 0x1F8
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_8097DF0

        .align 2,0
