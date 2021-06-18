	.include "constants/gba_constants.inc"
	.include "asm/macros.inc"

	.syntax unified

	.text

	thumb_func_start sub_801B178
sub_801B178:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	movs r5, 0
	ldr r1, _0801B1F4
	ldr r0, [r1]
	ldr r0, [r0, 0x4C]
	cmp r5, r0
	bge _0801B1D2
	ldr r0, _0801B1F8
	mov r8, r0
	adds r7, r1, 0
	movs r6, 0
_0801B192:
	ldr r4, _0801B1FC
	adds r4, r6, r4
	ldr r0, [r7]
	lsls r1, r5, 1
	adds r0, 0x50
	adds r0, r1
	movs r2, 0
	ldrsh r1, [r0, r2]
	movs r0, 0x58
	muls r0, r1
	mov r2, r8
	ldr r1, [r2]
	adds r1, r0
	adds r0, r4, 0
	bl sub_808DA34
	ldr r2, [r7]
	lsls r1, r5, 3
	adds r0, r2, 0
	adds r0, 0x64
	adds r0, r1
	str r4, [r0]
	adds r0, r2, 0
	adds r0, 0x68
	adds r0, r1
	adds r1, r5, 0x4
	str r1, [r0]
	adds r6, 0x50
	adds r5, 0x1
	ldr r0, [r2, 0x4C]
	cmp r5, r0
	blt _0801B192
_0801B1D2:
	ldr r0, _0801B1F4
	ldr r2, [r0]
	lsls r3, r5, 3
	adds r0, r2, 0
	adds r0, 0x64
	adds r0, r3
	movs r1, 0
	str r1, [r0]
	adds r2, 0x68
	adds r2, r3
	movs r0, 0x1
	str r0, [r2]
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_0801B1F4: .4byte gUnknown_203B22C
_0801B1F8: .4byte gRecruitedPokemonRef
_0801B1FC: .4byte gAvailablePokemonNames
	thumb_func_end sub_801B178

	thumb_func_start sub_801B200
sub_801B200:
	push {r4-r6,lr}
	sub sp, 0x4
	mov r0, sp
	bl sub_80144A4
	cmp r0, 0
	bne _0801B2A4
	ldr r5, _0801B228
	ldr r3, [r5]
	ldr r0, [sp]
	str r0, [r3, 0x60]
	ldr r1, [sp]
	cmp r1, 0
	beq _0801B2A4
	cmp r1, 0x1
	bne _0801B22C
	movs r0, 0x4
	bl sub_801B064
	b _0801B2A4
	.align 2, 0
_0801B228: .4byte gUnknown_203B22C
_0801B22C:
	subs r1, 0x4
	lsls r1, 1
	adds r0, r3, 0
	adds r0, 0x50
	adds r0, r1
	ldrh r0, [r0]
	adds r1, r3, 0
	adds r1, 0x58
	strh r0, [r1]
	ldr r2, _0801B26C
	movs r0, 0
	ldrsh r1, [r1, r0]
	movs r0, 0x58
	muls r0, r1
	ldr r1, [r2]
	adds r1, r0
	str r1, [r3, 0x5C]
	ldr r0, _0801B270
	bl sub_808DA34
	ldr r1, [r5]
	adds r0, r1, 0
	adds r0, 0xC
	ldr r1, [r1, 0x5C]
	adds r1, 0x2C
	bl sub_809401C
	movs r4, 0
	adds r6, r5, 0
	movs r5, 0xC
	b _0801B278
	.align 2, 0
_0801B26C: .4byte gRecruitedPokemonRef
_0801B270: .4byte gUnknown_202E218
_0801B274:
	adds r5, 0x8
	adds r4, 0x1
_0801B278:
	cmp r4, 0x7
	bgt _0801B292
	ldr r3, [r6]
	adds r2, r3, r5
	ldrb r1, [r2]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	bne _0801B274
	ldrh r1, [r3, 0xA]
	adds r0, r2, 0
	bl sub_8092AD4
_0801B292:
	cmp r4, 0x3
	ble _0801B29E
	movs r0, 0x1
	bl sub_801B064
	b _0801B2A4
_0801B29E:
	movs r0, 0x2
	bl sub_801B064
_0801B2A4:
	add sp, 0x4
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end sub_801B200

	thumb_func_start sub_801B2AC
sub_801B2AC:
	push {lr}
	bl sub_801E8C0
	cmp r0, 0x2
	beq _0801B2CA
	cmp r0, 0x2
	bcc _0801B2D4
	cmp r0, 0x3
	bne _0801B2D4
	bl sub_801E93C
	movs r0, 0x2
	bl sub_801B064
	b _0801B2D4
_0801B2CA:
	bl sub_801E93C
	movs r0, 0
	bl sub_801B064
_0801B2D4:
	pop {r0}
	bx r0
	thumb_func_end sub_801B2AC

	thumb_func_start sub_801B2D8
sub_801B2D8:
	push {lr}
	sub sp, 0x4
	mov r0, sp
	bl sub_80144A4
	cmp r0, 0
	bne _0801B2EC
	movs r0, 0x4
	bl sub_801B064
_0801B2EC:
	add sp, 0x4
	pop {r0}
	bx r0
	thumb_func_end sub_801B2D8

	thumb_func_start sub_801B2F4
sub_801B2F4:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0x10
	mov r0, sp
	bl sub_808D580
	adds r6, r0, 0
	ldr r2, _0801B36C
	ldr r1, [r2]
	movs r0, 0
	str r0, [r1, 0x4C]
	movs r5, 0
	cmp r5, r6
	bge _0801B35A
	ldr r0, _0801B370
	mov r8, r0
	adds r7, r2, 0
	mov r4, sp
_0801B31A:
	ldr r1, [r4]
	movs r0, 0x58
	muls r0, r1
	mov r2, r8
	ldr r1, [r2]
	adds r1, r0
	ldr r0, [r7]
	ldrh r0, [r0, 0xA]
	movs r2, 0x8
	ldrsh r1, [r1, r2]
	bl sub_808E190
	lsls r0, 24
	cmp r0, 0
	beq _0801B352
	ldr r2, [r7]
	ldr r0, [r2, 0x4C]
	lsls r0, 1
	adds r1, r2, 0
	adds r1, 0x50
	adds r1, r0
	ldr r0, [r4]
	strh r0, [r1]
	ldr r0, [r2, 0x4C]
	cmp r0, 0x3
	bgt _0801B35A
	adds r0, 0x1
	str r0, [r2, 0x4C]
_0801B352:
	adds r4, 0x4
	adds r5, 0x1
	cmp r5, r6
	blt _0801B31A
_0801B35A:
	ldr r0, _0801B36C
	ldr r0, [r0]
	ldr r0, [r0, 0x4C]
	add sp, 0x10
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r1}
	bx r1
	.align 2, 0
_0801B36C: .4byte gUnknown_203B22C
_0801B370: .4byte gRecruitedPokemonRef
	thumb_func_end sub_801B2F4

	thumb_func_start sub_801B374
sub_801B374:
	push {r4-r6,lr}
	lsls r0, 24
	lsrs r0, 24
	ldr r1, _0801B3A8
	ldr r4, [r1]
	bl GetItemMove
	lsls r0, 16
	lsrs r6, r0, 16
	movs r5, 0
_0801B388:
	ldrh r0, [r4]
	lsrs r0, 1
	movs r1, 0x1
	ands r0, r1
	cmp r0, 0
	beq _0801B3AC
	movs r0, 0x8
	ldrsh r1, [r4, r0]
	adds r0, r6, 0
	bl sub_808E190
	lsls r0, 24
	cmp r0, 0
	beq _0801B3AC
	movs r0, 0
	b _0801B3BA
	.align 2, 0
_0801B3A8: .4byte gRecruitedPokemonRef
_0801B3AC:
	adds r5, 0x1
	adds r4, 0x58
	movs r0, 0xCE
	lsls r0, 1
	cmp r5, r0
	ble _0801B388
	movs r0, 0x1
_0801B3BA:
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end sub_801B374

        .align 2,0
