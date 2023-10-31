        #include "asm/constants/gba_constants.inc"
        #include "asm/macros.inc"

        .syntax unified

        .text

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
_0808D274: .4byte gRecruitedPokemonRef
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
_0808D2E4: .4byte gRecruitedPokemonRef
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

	thumb_func_start GetPlayerPokemonStruct
GetPlayerPokemonStruct:
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
_0808D360: .4byte gRecruitedPokemonRef
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
	thumb_func_end GetPlayerPokemonStruct

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
_0808D3A4: .4byte gRecruitedPokemonRef
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
_0808D3E0: .4byte gRecruitedPokemonRef
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
_0808D41C: .4byte gRecruitedPokemonRef
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
_0808D468: .4byte gRecruitedPokemonRef
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
_0808D4A8: .4byte gRecruitedPokemonRef
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
_0808D4F8: .4byte gRecruitedPokemonRef
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
_0808D53C: .4byte gRecruitedPokemonRef
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
_0808D57C: .4byte gRecruitedPokemonRef
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
_0808D5AC: .4byte gRecruitedPokemonRef
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

    .align 2,0
