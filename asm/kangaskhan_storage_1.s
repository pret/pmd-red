	.include "constants/gba_constants.inc"
	.include "asm/macros.inc"

	.syntax unified

	.text

	thumb_func_start sub_80175FC
sub_80175FC:
	push {r4-r7,lr}
	ldr r4, _0801767C
	ldr r0, [r4]
	adds r0, 0x4C
	movs r1, 0
	movs r2, 0xA
	bl MemoryFill16
	ldr r3, [r4]
	movs r2, 0
	ldr r0, _08017680
	ldr r0, [r0]
	str r0, [r3, 0x24]
	movs r0, 0x2
	str r0, [r3, 0x28]
	movs r1, 0x1
	ldr r0, _08017684
	ldr r0, [r0]
	str r0, [r3, 0x2C]
	movs r0, 0x3
	str r0, [r3, 0x30]
	ldr r0, _08017688
	ldr r0, [r0]
	str r0, [r3, 0x34]
	movs r0, 0x6
	str r0, [r3, 0x38]
	ldr r0, _0801768C
	ldr r0, [r0]
	str r0, [r3, 0x3C]
	str r1, [r3, 0x40]
	movs r6, 0x4
	str r2, [r3, 0x44]
	str r1, [r3, 0x48]
	movs r5, 0
	mov r12, r3
	adds r3, 0x28
	mov r2, r12
	adds r2, 0x4C
_08017648:
	ldrh r0, [r2]
	cmp r0, 0
	bne _08017658
	ldr r1, [r3]
	mov r7, r12
	ldr r0, [r7, 0x18]
	cmp r1, r0
	beq _080176B2
_08017658:
	adds r3, 0x8
	adds r2, 0x2
	adds r5, 0x1
	cmp r5, r6
	blt _08017648
	movs r5, 0
	cmp r5, r6
	bge _080176B2
	ldr r1, [r4]
	adds r0, r1, 0
	adds r0, 0x4C
	ldrh r0, [r0]
	cmp r0, 0
	bne _08017690
	ldr r0, [r1, 0x28]
	str r0, [r1, 0x18]
	b _080176B2
	.align 2, 0
_0801767C: .4byte gUnknown_203B208
_08017680: .4byte gUnknown_80D4958
_08017684: .4byte gUnknown_80D4964
_08017688: .4byte gUnknown_80D4970
_0801768C: .4byte gUnknown_80D4934
_08017690:
	adds r5, 0x1
	cmp r5, r6
	bge _080176B2
	ldr r2, [r4]
	lsls r0, r5, 1
	adds r1, r2, 0
	adds r1, 0x4C
	adds r1, r0
	ldrh r0, [r1]
	cmp r0, 0
	bne _08017690
	lsls r0, r5, 3
	adds r1, r2, 0
	adds r1, 0x28
	adds r1, r0
	ldr r0, [r1]
	str r0, [r2, 0x18]
_080176B2:
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_80175FC

	thumb_func_start sub_80176B8
sub_80176B8:
	push {r4-r7,lr}
	ldr r4, _08017724
	ldr r0, [r4]
	adds r0, 0x4C
	movs r1, 0
	movs r2, 0xA
	bl MemoryFill16
	ldr r3, [r4]
	movs r2, 0
	ldr r0, _08017728
	ldr r0, [r0]
	str r0, [r3, 0x24]
	movs r0, 0x2
	str r0, [r3, 0x28]
	movs r1, 0x1
	ldr r0, _0801772C
	ldr r0, [r0]
	str r0, [r3, 0x2C]
	movs r0, 0x6
	str r0, [r3, 0x30]
	movs r6, 0x2
	str r2, [r3, 0x34]
	str r1, [r3, 0x38]
	movs r5, 0
	mov r12, r3
	adds r3, 0x28
	mov r2, r12
	adds r2, 0x4C
_080176F2:
	ldrh r0, [r2]
	cmp r0, 0
	bne _08017702
	ldr r1, [r3]
	mov r7, r12
	ldr r0, [r7, 0x1C]
	cmp r1, r0
	beq _08017752
_08017702:
	adds r3, 0x8
	adds r2, 0x2
	adds r5, 0x1
	cmp r5, r6
	blt _080176F2
	movs r5, 0
	cmp r5, r6
	bge _08017752
	ldr r1, [r4]
	adds r0, r1, 0
	adds r0, 0x4C
	ldrh r0, [r0]
	cmp r0, 0
	bne _08017730
	ldr r0, [r1, 0x28]
	str r0, [r1, 0x1C]
	b _08017752
	.align 2, 0
_08017724: .4byte gUnknown_203B208
_08017728: .4byte gUnknown_80D4958
_0801772C: .4byte gUnknown_80D4970
_08017730:
	adds r5, 0x1
	cmp r5, r6
	bge _08017752
	ldr r2, [r4]
	lsls r0, r5, 1
	adds r1, r2, 0
	adds r1, 0x4C
	adds r1, r0
	ldrh r0, [r1]
	cmp r0, 0
	bne _08017730
	lsls r0, r5, 3
	adds r1, r2, 0
	adds r1, 0x28
	adds r1, r0
	ldr r0, [r1]
	str r0, [r2, 0x1C]
_08017752:
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_80176B8

	thumb_func_start sub_8017758
sub_8017758:
	push {r4-r7,lr}
	ldr r4, _080177C4
	ldr r0, [r4]
	adds r0, 0x4C
	movs r1, 0
	movs r2, 0xA
	bl MemoryFill16
	ldr r3, [r4]
	movs r2, 0
	ldr r0, _080177C8
	ldr r0, [r0]
	str r0, [r3, 0x24]
	movs r0, 0x3
	str r0, [r3, 0x28]
	movs r1, 0x1
	ldr r0, _080177CC
	ldr r0, [r0]
	str r0, [r3, 0x2C]
	movs r0, 0x6
	str r0, [r3, 0x30]
	movs r6, 0x2
	str r2, [r3, 0x34]
	str r1, [r3, 0x38]
	movs r5, 0
	mov r12, r3
	adds r3, 0x28
	mov r2, r12
	adds r2, 0x4C
_08017792:
	ldrh r0, [r2]
	cmp r0, 0
	bne _080177A2
	ldr r1, [r3]
	mov r7, r12
	ldr r0, [r7, 0x20]
	cmp r1, r0
	beq _080177F2
_080177A2:
	adds r3, 0x8
	adds r2, 0x2
	adds r5, 0x1
	cmp r5, r6
	blt _08017792
	movs r5, 0
	cmp r5, r6
	bge _080177F2
	ldr r1, [r4]
	adds r0, r1, 0
	adds r0, 0x4C
	ldrh r0, [r0]
	cmp r0, 0
	bne _080177D0
	ldr r0, [r1, 0x28]
	str r0, [r1, 0x20]
	b _080177F2
	.align 2, 0
_080177C4: .4byte gUnknown_203B208
_080177C8: .4byte gUnknown_80D4964
_080177CC: .4byte gUnknown_80D4970
_080177D0:
	adds r5, 0x1
	cmp r5, r6
	bge _080177F2
	ldr r2, [r4]
	lsls r0, r5, 1
	adds r1, r2, 0
	adds r1, 0x4C
	adds r1, r0
	ldrh r0, [r1]
	cmp r0, 0
	bne _080177D0
	lsls r0, r5, 3
	adds r1, r2, 0
	adds r1, 0x28
	adds r1, r0
	ldr r0, [r1]
	str r0, [r2, 0x20]
_080177F2:
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_8017758

	thumb_func_start sub_80177F8
sub_80177F8:
	ldr r0, _0801781C
	ldr r1, [r0]
	movs r3, 0
	ldr r0, _08017820
	ldr r0, [r0]
	str r0, [r1, 0x24]
	movs r0, 0x4
	str r0, [r1, 0x28]
	movs r2, 0x1
	ldr r0, _08017824
	ldr r0, [r0]
	str r0, [r1, 0x2C]
	movs r0, 0x5
	str r0, [r1, 0x30]
	str r3, [r1, 0x34]
	str r2, [r1, 0x38]
	bx lr
	.align 2, 0
_0801781C: .4byte gUnknown_203B208
_08017820: .4byte gUnknown_80D4920
_08017824: .4byte gUnknown_80D4928
	thumb_func_end sub_80177F8

	thumb_func_start sub_8017828
sub_8017828:
	push {lr}
	sub sp, 0x4
	mov r0, sp
	bl sub_80144A4
	cmp r0, 0
	bne _080178C8
	ldr r1, [sp]
	cmp r1, 0x1
	beq _08017842
	ldr r0, _08017854
	ldr r0, [r0]
	str r1, [r0, 0x18]
_08017842:
	ldr r0, [sp]
	cmp r0, 0x2
	beq _08017862
	cmp r0, 0x2
	bgt _08017858
	cmp r0, 0x1
	beq _080178C2
	b _080178C8
	.align 2, 0
_08017854: .4byte gUnknown_203B208
_08017858:
	cmp r0, 0x3
	beq _0801788E
	cmp r0, 0x6
	beq _080178BA
	b _080178C8
_08017862:
	bl sub_8090A34
	cmp r0, 0
	bne _08017872
	movs r0, 0x5
	bl UpdateKangaskhanStorageState
	b _080178C8
_08017872:
	movs r0, 0
	bl sub_801CF50
	lsls r0, 24
	cmp r0, 0
	beq _08017886
	movs r0, 0x8
	bl UpdateKangaskhanStorageState
	b _080178C8
_08017886:
	movs r0, 0xB
	bl UpdateKangaskhanStorageState
	b _080178C8
_0801788E:
	movs r0, 0x1
	bl sub_801CF14
	lsls r0, 24
	cmp r0, 0
	beq _080178A2
	movs r0, 0x7
	bl UpdateKangaskhanStorageState
	b _080178C8
_080178A2:
	bl sub_8090A34
	cmp r0, 0x13
	ble _080178B2
	movs r0, 0x6
	bl UpdateKangaskhanStorageState
	b _080178C8
_080178B2:
	movs r0, 0x14
	bl UpdateKangaskhanStorageState
	b _080178C8
_080178BA:
	movs r0, 0x2
	bl UpdateKangaskhanStorageState
	b _080178C8
_080178C2:
	movs r0, 0x3
	bl UpdateKangaskhanStorageState
_080178C8:
	add sp, 0x4
	pop {r0}
	bx r0
	thumb_func_end sub_8017828

	thumb_func_start sub_80178D0
sub_80178D0:
	push {r4,lr}
	sub sp, 0x4
	mov r0, sp
	bl sub_80144A4
	cmp r0, 0
	bne _0801791E
	ldr r0, [sp]
	cmp r0, 0x4
	beq _080178F4
	cmp r0, 0x4
	bgt _080178EE
	cmp r0, 0x1
	beq _08017918
	b _0801791E
_080178EE:
	cmp r0, 0x5
	beq _08017918
	b _0801791E
_080178F4:
	ldr r4, _08017914
	ldr r0, [r4]
	adds r0, 0xC
	bl sub_80917B8
	ldr r0, [r4]
	ldr r0, [r0, 0x10]
	bl sub_80911F8
	bl sub_80910B4
	movs r0, 0x13
	bl UpdateKangaskhanStorageState
	b _0801791E
	.align 2, 0
_08017914: .4byte gUnknown_203B208
_08017918:
	movs r0, 0xE
	bl UpdateKangaskhanStorageState
_0801791E:
	add sp, 0x4
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_80178D0

	thumb_func_start sub_8017928
sub_8017928:
	push {lr}
	sub sp, 0x8
	mov r0, sp
	bl sub_80144A4
	cmp r0, 0
	bne _080179A2
	ldr r0, [sp]
	cmp r0, 0x4
	beq _0801794C
	cmp r0, 0x4
	bgt _08017946
	cmp r0, 0x1
	beq _0801799C
	b _080179A2
_08017946:
	cmp r0, 0x5
	beq _0801799C
	b _080179A2
_0801794C:
	ldr r0, _0801798C
	ldr r1, [r0]
	ldr r0, _08017990
	ldr r3, [r0]
	ldrb r0, [r3, 0xE]
	lsls r0, 1
	adds r1, 0x50
	adds r1, r0
	ldrb r2, [r3, 0xD]
	ldrh r0, [r1]
	subs r0, r2
	strh r0, [r1]
	ldrb r2, [r3, 0xE]
	ldr r1, _08017994
	ldr r0, [sp, 0x4]
	ands r0, r1
	orrs r0, r2
	str r0, [sp, 0x4]
	ldrb r1, [r3, 0xD]
	lsls r1, 8
	ldr r2, _08017998
	ands r0, r2
	orrs r0, r1
	str r0, [sp, 0x4]
	add r0, sp, 0x4
	bl sub_8091274
	movs r0, 0x1D
	bl UpdateKangaskhanStorageState
	b _080179A2
	.align 2, 0
_0801798C: .4byte gUnknown_203B460
_08017990: .4byte gUnknown_203B208
_08017994: .4byte 0xffffff00
_08017998: .4byte 0xffff00ff
_0801799C:
	movs r0, 0x17
	bl UpdateKangaskhanStorageState
_080179A2:
	add sp, 0x8
	pop {r0}
	bx r0
	thumb_func_end sub_8017928

	thumb_func_start sub_80179A8
sub_80179A8:
	push {r4-r7,lr}
	sub sp, 0x4
	mov r0, sp
	bl sub_80144A4
	cmp r0, 0
	bne _08017A12
	ldr r0, [sp]
	cmp r0, 0x4
	beq _080179CC
	cmp r0, 0x4
	bgt _080179C6
	cmp r0, 0x1
	beq _08017A0C
	b _08017A12
_080179C6:
	cmp r0, 0x5
	beq _08017A0C
	b _08017A12
_080179CC:
	movs r5, 0
	ldr r6, _08017A08
	movs r7, 0
_080179D2:
	adds r0, r5, 0
	bl sub_801AED0
	cmp r0, 0
	beq _080179F2
	lsls r4, r5, 2
	ldr r0, [r6]
	adds r0, r4
	bl sub_80917B8
	ldr r0, [r6]
	adds r0, r4
	strb r7, [r0, 0x2]
	ldr r0, [r6]
	adds r0, r4
	strb r7, [r0]
_080179F2:
	adds r5, 0x1
	cmp r5, 0x13
	ble _080179D2
	bl sub_80910B4
	bl sub_801AE84
	movs r0, 0x13
	bl UpdateKangaskhanStorageState
	b _08017A12
	.align 2, 0
_08017A08: .4byte gUnknown_203B460
_08017A0C:
	movs r0, 0xE
	bl UpdateKangaskhanStorageState
_08017A12:
	add sp, 0x4
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_80179A8

	thumb_func_start sub_8017A1C
sub_8017A1C:
	push {r4-r6,lr}
	sub sp, 0x8
	mov r0, sp
	bl sub_80144A4
	cmp r0, 0
	bne _08017AEE
	ldr r0, [sp]
	cmp r0, 0x4
	beq _08017A40
	cmp r0, 0x4
	bgt _08017A3A
	cmp r0, 0x1
	beq _08017AE8
	b _08017AEE
_08017A3A:
	cmp r0, 0x5
	beq _08017AE8
	b _08017AEE
_08017A40:
	movs r5, 0
	ldr r6, _08017A88
_08017A44:
	lsls r0, r5, 24
	lsrs r4, r0, 24
	adds r0, r4, 0
	bl sub_801CFE0
	cmp r0, 0
	beq _08017ACE
	ldr r1, _08017A8C
	ldr r0, [sp, 0x4]
	ands r0, r1
	orrs r0, r4
	str r0, [sp, 0x4]
	add r4, sp, 0x4
	ldrb r0, [r4]
	bl sub_8090A60
	lsls r0, 24
	cmp r0, 0
	beq _08017AA2
	ldr r2, _08017A90
	ldr r1, [r2]
	ldrb r0, [r4]
	lsls r0, 1
	adds r1, 0x50
	adds r1, r0
	ldrh r1, [r1]
	cmp r1, 0x63
	bls _08017A94
	ldr r0, [sp, 0x4]
	ands r0, r6
	movs r1, 0xC6
	lsls r1, 7
	b _08017A9C
	.align 2, 0
_08017A88: .4byte 0xffff00ff
_08017A8C: .4byte 0xffffff00
_08017A90: .4byte gUnknown_203B460
_08017A94:
	lsls r1, 24
	lsrs r1, 16
	ldr r0, [sp, 0x4]
	ands r0, r6
_08017A9C:
	orrs r0, r1
	str r0, [sp, 0x4]
	b _08017AB0
_08017AA2:
	ldr r0, [sp, 0x4]
	ands r0, r6
	movs r1, 0x80
	lsls r1, 1
	orrs r0, r1
	str r0, [sp, 0x4]
	ldr r2, _08017AE4
_08017AB0:
	ldr r3, [r2]
	add r0, sp, 0x4
	ldrb r1, [r4]
	lsls r1, 1
	adds r3, 0x50
	adds r3, r1
	ldr r1, [sp, 0x4]
	lsrs r1, 8
	lsls r1, 24
	lsrs r1, 24
	ldrh r2, [r3]
	subs r2, r1
	strh r2, [r3]
	bl sub_8091274
_08017ACE:
	adds r5, 0x1
	cmp r5, 0xEF
	ble _08017A44
	bl sub_80910B4
	bl sub_801CF94
	movs r0, 0x1D
	bl UpdateKangaskhanStorageState
	b _08017AEE
	.align 2, 0
_08017AE4: .4byte gUnknown_203B460
_08017AE8:
	movs r0, 0x17
	bl UpdateKangaskhanStorageState
_08017AEE:
	add sp, 0x8
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end sub_8017A1C

	thumb_func_start sub_8017AF8
sub_8017AF8:
	push {lr}
	movs r0, 0x1
	bl sub_801A6E8
	cmp r0, 0x3
	beq _08017B14
	cmp r0, 0x3
	bhi _08017B0E
	cmp r0, 0x2
	beq _08017B78
	b _08017B82
_08017B0E:
	cmp r0, 0x4
	beq _08017B50
	b _08017B82
_08017B14:
	bl sub_801AEA8
	cmp r0, 0
	beq _08017B2A
	movs r0, 0
	bl sub_8099690
	movs r0, 0x12
	bl UpdateKangaskhanStorageState
	b _08017B82
_08017B2A:
	bl sub_801A8AC
	ldr r1, _08017B48
	ldr r2, [r1]
	str r0, [r2, 0x10]
	ldr r1, _08017B4C
	ldr r1, [r1]
	lsls r0, 2
	adds r1, r0
	ldr r0, [r1]
	str r0, [r2, 0xC]
	movs r0, 0xF
	bl UpdateKangaskhanStorageState
	b _08017B82
	.align 2, 0
_08017B48: .4byte gUnknown_203B208
_08017B4C: .4byte gUnknown_203B460
_08017B50:
	bl sub_801A8AC
	ldr r1, _08017B70
	ldr r2, [r1]
	str r0, [r2, 0x10]
	ldr r1, _08017B74
	ldr r1, [r1]
	lsls r0, 2
	adds r1, r0
	ldr r0, [r1]
	str r0, [r2, 0xC]
	movs r0, 0x10
	bl UpdateKangaskhanStorageState
	b _08017B82
	.align 2, 0
_08017B70: .4byte gUnknown_203B208
_08017B74: .4byte gUnknown_203B460
_08017B78:
	bl sub_801A928
	movs r0, 0x1
	bl UpdateKangaskhanStorageState
_08017B82:
	pop {r0}
	bx r0
	thumb_func_end sub_8017AF8

	thumb_func_start sub_8017B88
sub_8017B88:
	push {r4,lr}
	movs r0, 0x1
	bl sub_801CA08
	cmp r0, 0x2
	beq _08017C10
	cmp r0, 0x2
	bhi _08017B9E
	cmp r0, 0x1
	beq _08017C1C
	b _08017C22
_08017B9E:
	cmp r0, 0x3
	beq _08017BA8
	cmp r0, 0x4
	beq _08017BE4
	b _08017C22
_08017BA8:
	bl sub_801CFB8
	cmp r0, 0
	beq _08017BB8
	movs r0, 0x1C
	bl UpdateKangaskhanStorageState
	b _08017C22
_08017BB8:
	bl sub_801CB24
	ldr r4, _08017BE0
	ldr r1, [r4]
	strb r0, [r1, 0x14]
	ldr r1, [r4]
	adds r0, r1, 0
	adds r0, 0xC
	ldrb r1, [r1, 0x14]
	movs r2, 0
	bl sub_8090A8C
	ldr r1, [r4]
	movs r0, 0x1
	strb r0, [r1, 0xD]
	movs r0, 0x19
	bl UpdateKangaskhanStorageState
	b _08017C22
	.align 2, 0
_08017BE0: .4byte gUnknown_203B208
_08017BE4:
	bl sub_801CB24
	ldr r4, _08017C0C
	ldr r1, [r4]
	strb r0, [r1, 0x14]
	ldr r1, [r4]
	adds r0, r1, 0
	adds r0, 0xC
	ldrb r1, [r1, 0x14]
	movs r2, 0
	bl sub_8090A8C
	ldr r1, [r4]
	movs r0, 0x1
	strb r0, [r1, 0xD]
	movs r0, 0x1A
	bl UpdateKangaskhanStorageState
	b _08017C22
	.align 2, 0
_08017C0C: .4byte gUnknown_203B208
_08017C10:
	bl sub_801CBB8
	movs r0, 0x1
	bl UpdateKangaskhanStorageState
	b _08017C22
_08017C1C:
	movs r0, 0
	bl sub_801AD34
_08017C22:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_8017B88

	thumb_func_start sub_8017C28
sub_8017C28:
	push {r4,lr}
	movs r0, 0
	bl sub_801CA08
	ldr r4, _08017C54
	ldr r0, [r4]
	adds r0, 0x58
	bl sub_8012FD8
	ldr r0, [r4]
	adds r0, 0xA8
	bl sub_8013BBC
	cmp r0, 0x1
	beq _08017C58
	cmp r0, 0x1
	bcc _08017C76
	cmp r0, 0x2
	beq _08017C70
	cmp r0, 0x3
	beq _08017C5E
	b _08017C76
	.align 2, 0
_08017C54: .4byte gUnknown_203B208
_08017C58:
	bl sub_8017598
	b _08017C76
_08017C5E:
	ldr r0, [r4]
	adds r1, r0, 0
	adds r1, 0xA8
	ldr r1, [r1]
	strb r1, [r0, 0xD]
	movs r0, 0x1B
	bl UpdateKangaskhanStorageState
	b _08017C76
_08017C70:
	movs r0, 0x17
	bl UpdateKangaskhanStorageState
_08017C76:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_8017C28

	thumb_func_start sub_8017C7C
sub_8017C7C:
	push {r4,lr}
	sub sp, 0x4
	movs r0, 0
	str r0, [sp]
	bl sub_801A6E8
	ldr r4, _08017CBC
	ldr r0, [r4]
	adds r0, 0x58
	bl sub_8012FD8
	lsls r0, 24
	cmp r0, 0
	bne _08017CAC
	ldr r0, [r4]
	adds r0, 0x58
	mov r1, sp
	bl sub_8013114
	ldr r1, [sp]
	cmp r1, 0x1
	beq _08017CAC
	ldr r0, [r4]
	str r1, [r0, 0x1C]
_08017CAC:
	ldr r0, [sp]
	cmp r0, 0x2
	beq _08017CC6
	cmp r0, 0x2
	bgt _08017CC0
	cmp r0, 0x1
	beq _08017D14
	b _08017D1A
	.align 2, 0
_08017CBC: .4byte gUnknown_203B208
_08017CC0:
	cmp r0, 0x6
	beq _08017D06
	b _08017D1A
_08017CC6:
	movs r0, 0
	bl sub_8099690
	ldr r4, _08017CE4
	ldr r0, [r4]
	ldrb r0, [r0, 0xE]
	bl sub_8091524
	lsls r0, 24
	cmp r0, 0
	bne _08017CE8
	movs r0, 0x9
	bl UpdateKangaskhanStorageState
	b _08017D1A
	.align 2, 0
_08017CE4: .4byte gUnknown_203B208
_08017CE8:
	ldr r0, [r4]
	ldr r0, [r0, 0x10]
	bl sub_801ADA0
	lsls r0, 24
	cmp r0, 0
	bne _08017CFE
	movs r0, 0xA
	bl UpdateKangaskhanStorageState
	b _08017D1A
_08017CFE:
	movs r0, 0x11
	bl UpdateKangaskhanStorageState
	b _08017D1A
_08017D06:
	movs r0, 0
	bl sub_8099690
	movs r0, 0x10
	bl UpdateKangaskhanStorageState
	b _08017D1A
_08017D14:
	movs r0, 0xE
	bl UpdateKangaskhanStorageState
_08017D1A:
	add sp, 0x4
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_8017C7C

	thumb_func_start sub_8017D24
sub_8017D24:
	push {r4,lr}
	sub sp, 0x4
	movs r0, 0
	str r0, [sp]
	bl sub_801CA08
	ldr r4, _08017D64
	ldr r0, [r4]
	adds r0, 0x58
	bl sub_8012FD8
	lsls r0, 24
	cmp r0, 0
	bne _08017D54
	ldr r0, [r4]
	adds r0, 0x58
	mov r1, sp
	bl sub_8013114
	ldr r1, [sp]
	cmp r1, 0x1
	beq _08017D54
	ldr r0, [r4]
	str r1, [r0, 0x20]
_08017D54:
	ldr r0, [sp]
	cmp r0, 0x3
	beq _08017D6E
	cmp r0, 0x3
	bgt _08017D68
	cmp r0, 0x1
	beq _08017DB0
	b _08017DB6
	.align 2, 0
_08017D64: .4byte gUnknown_203B208
_08017D68:
	cmp r0, 0x6
	beq _08017DA8
	b _08017DB6
_08017D6E:
	bl sub_8090A34
	cmp r0, 0x13
	ble _08017D82
	bl sub_801CBB8
	movs r0, 0x6
	bl UpdateKangaskhanStorageState
	b _08017DB6
_08017D82:
	ldr r0, _08017D9C
	ldr r0, [r0]
	ldrb r0, [r0, 0xE]
	bl sub_8090A60
	lsls r0, 24
	cmp r0, 0
	beq _08017DA0
	movs r0, 0x18
	bl UpdateKangaskhanStorageState
	b _08017DB6
	.align 2, 0
_08017D9C: .4byte gUnknown_203B208
_08017DA0:
	movs r0, 0x1B
	bl UpdateKangaskhanStorageState
	b _08017DB6
_08017DA8:
	movs r0, 0x1A
	bl UpdateKangaskhanStorageState
	b _08017DB6
_08017DB0:
	movs r0, 0x17
	bl UpdateKangaskhanStorageState
_08017DB6:
	add sp, 0x4
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_8017D24

	thumb_func_start sub_8017DC0
sub_8017DC0:
	push {lr}
	bl sub_801B410
	cmp r0, 0x1
	bls _08017DD8
	cmp r0, 0x3
	bhi _08017DD8
	bl sub_801B450
	movs r0, 0xE
	bl UpdateKangaskhanStorageState
_08017DD8:
	pop {r0}
	bx r0
	thumb_func_end sub_8017DC0

	thumb_func_start sub_8017DDC
sub_8017DDC:
	push {lr}
	bl sub_801B410
	cmp r0, 0x1
	bls _08017DF4
	cmp r0, 0x3
	bhi _08017DF4
	bl sub_801B450
	movs r0, 0x17
	bl UpdateKangaskhanStorageState
_08017DF4:
	pop {r0}
	bx r0
	thumb_func_end sub_8017DDC

	thumb_func_start sub_8017DF8
sub_8017DF8:
	push {lr}
	sub sp, 0x4
	mov r0, sp
	bl sub_80144A4
	cmp r0, 0
	bne _08017E10
	ldr r0, _08017E18
	ldr r0, [r0]
	ldr r0, [r0, 0x8]
	bl UpdateKangaskhanStorageState
_08017E10:
	add sp, 0x4
	pop {r0}
	bx r0
	.align 2, 0
_08017E18: .4byte gUnknown_203B208
	thumb_func_end sub_8017DF8

	thumb_func_start sub_8017E1C
sub_8017E1C:
	push {r4,lr}
	bl ResetUnusedInputStruct
	movs r0, 0
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	ldr r4, _08017E50
	movs r0, 0xA8
	lsls r0, 1
	movs r1, 0x8
	bl MemoryAlloc
	str r0, [r4]
	movs r1, 0
	str r1, [r0, 0x14]
	str r1, [r0, 0x18]
	str r1, [r0, 0x1C]
	movs r0, 0
	bl sub_8017F10
	movs r0, 0x1
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_08017E50: .4byte gUnknown_203B20C
	thumb_func_end sub_8017E1C

	thumb_func_start sub_8017E54
sub_8017E54:
	push {lr}
	ldr r0, _08017E6C
	ldr r0, [r0]
	ldr r0, [r0]
	cmp r0, 0xE
	bhi _08017EEC
	lsls r0, 2
	ldr r1, _08017E70
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08017E6C: .4byte gUnknown_203B20C
_08017E70: .4byte _08017E74
	.align 2, 0
_08017E74:
	.4byte _08017EB0
	.4byte _08017EB8
	.4byte _08017EEC
	.4byte _08017EE8
	.4byte _08017EBE
	.4byte _08017EBE
	.4byte _08017EC4
	.4byte _08017ECA
	.4byte _08017EEC
	.4byte _08017EEC
	.4byte _08017ED0
	.4byte _08017ED0
	.4byte _08017ED6
	.4byte _08017EDC
	.4byte _08017EE2
_08017EB0:
	movs r0, 0x1
	bl sub_8017F10
	b _08017EEC
_08017EB8:
	bl sub_8018588
	b _08017EEC
_08017EBE:
	bl sub_8018620
	b _08017EEC
_08017EC4:
	bl sub_8018904
	b _08017EEC
_08017ECA:
	bl sub_8018AC8
	b _08017EEC
_08017ED0:
	bl sub_80186F8
	b _08017EEC
_08017ED6:
	bl sub_8018854
	b _08017EEC
_08017EDC:
	bl sub_80189C8
	b _08017EEC
_08017EE2:
	bl sub_8018AE4
	b _08017EEC
_08017EE8:
	movs r0, 0x3
	b _08017EEE
_08017EEC:
	movs r0, 0
_08017EEE:
	pop {r1}
	bx r1
	thumb_func_end sub_8017E54

	thumb_func_start sub_8017EF4
sub_8017EF4:
	push {r4,lr}
	ldr r4, _08017F0C
	ldr r0, [r4]
	cmp r0, 0
	beq _08017F06
	bl MemoryFree
	movs r0, 0
	str r0, [r4]
_08017F06:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08017F0C: .4byte gUnknown_203B20C
	thumb_func_end sub_8017EF4

	thumb_func_start sub_8017F10
sub_8017F10:
	push {lr}
	ldr r1, _08017F24
	ldr r1, [r1]
	str r0, [r1]
	bl sub_8017F28
	bl sub_8018100
	pop {r0}
	bx r0
	.align 2, 0
_08017F24: .4byte gUnknown_203B20C
	thumb_func_end sub_8017F10

	thumb_func_start sub_8017F28
sub_8017F28:
	push {r4-r7,lr}
	ldr r4, _08017F48
	ldr r0, [r4]
	adds r0, 0xF0
	bl sub_8006518
	ldr r0, [r4]
	ldr r0, [r0]
	cmp r0, 0xD
	bls _08017F3E
	b _080180BC
_08017F3E:
	lsls r0, 2
	ldr r1, _08017F4C
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08017F48: .4byte gUnknown_203B20C
_08017F4C: .4byte _08017F50
	.align 2, 0
_08017F50:
	.4byte _080180BC
	.4byte _08017F88
	.4byte _080180BC
	.4byte _080180BC
	.4byte _08017FE8
	.4byte _08017FE8
	.4byte _0801809C
	.4byte _080180BC
	.4byte _080180BC
	.4byte _080180BC
	.4byte _08018034
	.4byte _08018034
	.4byte _08018084
	.4byte _0801809C
_08017F88:
	ldr r4, _08017FDC
	ldr r1, [r4]
	ldr r2, _08017FE0
	adds r1, 0xF0
	adds r0, r2, 0
	ldm r0!, {r3,r5,r6}
	stm r1!, {r3,r5,r6}
	ldm r0!, {r3,r5,r7}
	stm r1!, {r3,r5,r7}
	ldr r1, [r4]
	movs r6, 0x84
	lsls r6, 1
	adds r1, r6
	adds r0, r2, 0
	ldm r0!, {r3,r5,r7}
	stm r1!, {r3,r5,r7}
	ldm r0!, {r3,r6,r7}
	stm r1!, {r3,r6,r7}
	ldr r0, [r4]
	adds r0, 0xF0
	ldm r2!, {r5-r7}
	stm r0!, {r5-r7}
	ldm r2!, {r1,r3,r5}
	stm r0!, {r1,r3,r5}
	bl sub_80182E4
	ldr r2, [r4]
	movs r0, 0x90
	lsls r0, 1
	adds r2, r0
	ldr r1, _08017FE4
	ldm r1!, {r3,r6,r7}
	stm r2!, {r3,r6,r7}
	ldm r1!, {r5-r7}
	stm r2!, {r5-r7}
	ldr r1, [r4]
	adds r0, r1, r0
	adds r1, 0x20
	bl sub_8012CAC
	b _080180E0
	.align 2, 0
_08017FDC: .4byte gUnknown_203B20C
_08017FE0: .4byte gUnknown_80DB7B8
_08017FE4: .4byte gUnknown_80DB7D0
_08017FE8:
	ldr r3, _0801802C
	ldr r1, [r3]
	ldr r2, _08018030
	adds r1, 0xF0
	adds r0, r2, 0
	ldm r0!, {r4-r6}
	stm r1!, {r4-r6}
	ldm r0!, {r4,r5,r7}
	stm r1!, {r4,r5,r7}
	ldr r1, [r3]
	movs r6, 0x84
	lsls r6, 1
	adds r1, r6
	adds r0, r2, 0
	ldm r0!, {r4,r5,r7}
	stm r1!, {r4,r5,r7}
	ldm r0!, {r4,r6,r7}
	stm r1!, {r4,r6,r7}
	ldr r1, [r3]
	movs r5, 0x90
	lsls r5, 1
	adds r1, r5
	adds r0, r2, 0
	ldm r0!, {r4,r6,r7}
	stm r1!, {r4,r6,r7}
	ldm r0!, {r5-r7}
	stm r1!, {r5-r7}
	ldr r0, [r3]
	adds r0, 0xF0
	ldm r2!, {r1,r3,r4}
	stm r0!, {r1,r3,r4}
	ldm r2!, {r5-r7}
	stm r0!, {r5-r7}
	b _080180E0
	.align 2, 0
_0801802C: .4byte gUnknown_203B20C
_08018030: .4byte gUnknown_80DB7B8
_08018034:
	ldr r3, _08018078
	ldr r1, [r3]
	ldr r2, _0801807C
	adds r1, 0xF0
	adds r0, r2, 0
	ldm r0!, {r4-r6}
	stm r1!, {r4-r6}
	ldm r0!, {r4,r5,r7}
	stm r1!, {r4,r5,r7}
	ldr r1, [r3]
	movs r6, 0x84
	lsls r6, 1
	adds r1, r6
	adds r0, r2, 0
	ldm r0!, {r4,r5,r7}
	stm r1!, {r4,r5,r7}
	ldm r0!, {r4,r6,r7}
	stm r1!, {r4,r6,r7}
	ldr r0, [r3]
	movs r5, 0x90
	lsls r5, 1
	adds r0, r5
	ldm r2!, {r1,r6,r7}
	stm r0!, {r1,r6,r7}
	ldm r2!, {r4-r6}
	stm r0!, {r4-r6}
	ldr r1, [r3]
	adds r1, 0xF0
	ldr r0, _08018080
	ldm r0!, {r2,r3,r7}
	stm r1!, {r2,r3,r7}
	ldm r0!, {r4-r6}
	stm r1!, {r4-r6}
	b _080180E0
	.align 2, 0
_08018078: .4byte gUnknown_203B20C
_0801807C: .4byte gUnknown_80DB7B8
_08018080: .4byte gUnknown_80DB800
_08018084:
	ldr r0, _08018094
	ldr r1, [r0]
	movs r7, 0x84
	lsls r7, 1
	adds r1, r7
	ldr r0, _08018098
	b _080180A8
	.align 2, 0
_08018094: .4byte gUnknown_203B20C
_08018098: .4byte gUnknown_80DB818
_0801809C:
	ldr r0, _080180B4
	ldr r1, [r0]
	movs r0, 0x90
	lsls r0, 1
	adds r1, r0
	ldr r0, _080180B8
_080180A8:
	ldm r0!, {r2-r4}
	stm r1!, {r2-r4}
	ldm r0!, {r5-r7}
	stm r1!, {r5-r7}
	b _080180E0
	.align 2, 0
_080180B4: .4byte gUnknown_203B20C
_080180B8: .4byte gUnknown_80DB7E8
_080180BC:
	ldr r0, _080180F8
	mov r12, r0
	ldr r4, _080180FC
	movs r3, 0
	movs r2, 0x3
_080180C6:
	mov r5, r12
	ldr r1, [r5]
	adds r1, r3
	adds r1, 0xF0
	adds r0, r4, 0
	ldm r0!, {r5-r7}
	stm r1!, {r5-r7}
	ldm r0!, {r5-r7}
	stm r1!, {r5-r7}
	adds r3, 0x18
	subs r2, 0x1
	cmp r2, 0
	bge _080180C6
_080180E0:
	bl ResetUnusedInputStruct
	ldr r0, _080180F8
	ldr r0, [r0]
	adds r0, 0xF0
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_080180F8: .4byte gUnknown_203B20C
_080180FC: .4byte gUnknown_80DB7B8
	thumb_func_end sub_8017F28

	thumb_func_start sub_8018100
sub_8018100:
	push {r4,lr}
	sub sp, 0x8
	ldr r1, _0801811C
	ldr r0, [r1]
	ldr r0, [r0]
	adds r4, r1, 0
	cmp r0, 0xE
	bls _08018112
	b _08018278
_08018112:
	lsls r0, 2
	ldr r1, _08018120
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0801811C: .4byte gUnknown_203B20C
_08018120: .4byte _08018124
	.align 2, 0
_08018124:
	.4byte _08018278
	.4byte _08018160
	.4byte _08018278
	.4byte _08018278
	.4byte _08018172
	.4byte _08018180
	.4byte _08018188
	.4byte _080181A8
	.4byte _08018278
	.4byte _08018278
	.4byte _080181B2
	.4byte _080181C0
	.4byte _080181CE
	.4byte _0801823C
	.4byte _08018270
_08018160:
	ldr r2, [r4]
	adds r0, r2, 0
	adds r0, 0x70
	adds r1, r2, 0
	adds r1, 0x20
	adds r3, r2, 0
	adds r3, 0x60
	ldr r2, [r2, 0x14]
	b _0801825C
_08018172:
	movs r0, 0x3
	movs r1, 0x3
	movs r2, 0
	movs r3, 0xA
	bl sub_801A5D8
	b _08018278
_08018180:
	movs r0, 0x1
	bl sub_801A8D0
	b _08018278
_08018188:
	bl sub_801A9E0
	bl sub_801841C
	ldr r0, _080181A4
	ldr r2, [r0]
	adds r0, r2, 0
	adds r0, 0x70
	adds r1, r2, 0
	adds r1, 0x20
	adds r3, r2, 0
	adds r3, 0x60
	ldr r2, [r2, 0x18]
	b _0801825C
	.align 2, 0
_080181A4: .4byte gUnknown_203B20C
_080181A8:
	ldr r0, [r4]
	adds r0, 0x8
	bl sub_801B3C0
	b _08018278
_080181B2:
	movs r0, 0x1
	movs r1, 0x3
	movs r2, 0
	movs r3, 0xA
	bl sub_801C8C4
	b _080181C6
_080181C0:
	movs r0, 0x1
	bl sub_801CB5C
_080181C6:
	movs r0, 0
	bl sub_801AD34
	b _08018278
_080181CE:
	ldr r2, [r4]
	adds r1, r2, 0
	adds r1, 0xD0
	movs r0, 0x2
	str r0, [r1]
	subs r1, 0x8
	movs r0, 0x1
	str r0, [r1]
	ldr r0, _080181F8
	ldr r1, [r0]
	ldrb r0, [r2, 0xA]
	lsls r0, 1
	adds r1, 0x50
	adds r3, r1, r0
	ldrh r0, [r3]
	cmp r0, 0x63
	bls _080181FC
	adds r1, r2, 0
	adds r1, 0xCC
	movs r0, 0x63
	b _08018202
	.align 2, 0
_080181F8: .4byte gUnknown_203B460
_080181FC:
	adds r1, r2, 0
	adds r1, 0xCC
	ldrh r0, [r3]
_08018202:
	str r0, [r1]
	ldr r2, [r4]
	adds r1, r2, 0
	adds r1, 0xC4
	adds r0, r2, 0
	adds r0, 0xCC
	ldr r0, [r0]
	str r0, [r1]
	adds r1, 0x10
	movs r0, 0x1
	str r0, [r1]
	adds r1, 0x4
	movs r3, 0x84
	lsls r3, 1
	adds r0, r2, r3
	str r0, [r1]
	adds r1, 0x4
	movs r0, 0x28
	str r0, [r1]
	adds r1, 0x4
	movs r0, 0x12
	str r0, [r1]
	adds r0, r2, 0
	adds r0, 0xC0
	bl sub_8013AA0
	bl sub_8018280
	b _08018278
_0801823C:
	bl sub_801CCD8
	movs r0, 0
	bl sub_801AD34
	bl sub_80184D4
	ldr r0, _0801826C
	ldr r2, [r0]
	adds r0, r2, 0
	adds r0, 0x70
	adds r1, r2, 0
	adds r1, 0x20
	adds r3, r2, 0
	adds r3, 0x60
	ldr r2, [r2, 0x1C]
_0801825C:
	str r2, [sp]
	movs r2, 0x2
	str r2, [sp, 0x4]
	movs r2, 0
	bl sub_8012D60
	b _08018278
	.align 2, 0
_0801826C: .4byte gUnknown_203B20C
_08018270:
	ldr r0, [r4]
	adds r0, 0x8
	bl sub_801B3C0
_08018278:
	add sp, 0x8
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_8018100

	thumb_func_start sub_8018280
sub_8018280:
	push {r4,lr}
	sub sp, 0x4
	ldr r4, _080182DC
	ldr r0, [r4]
	adds r0, 0xD4
	ldr r0, [r0]
	bl sub_8008C54
	ldr r0, [r4]
	adds r0, 0xD4
	ldr r0, [r0]
	bl sub_80073B8
	ldr r2, _080182E0
	ldr r0, [r4]
	adds r0, 0xD4
	ldr r3, [r0]
	movs r0, 0
	str r0, [sp]
	movs r0, 0x4
	movs r1, 0
	bl xxx_call_draw_string
	ldr r0, [r4]
	adds r0, 0xC0
	bl sub_8013C68
	ldr r0, [r4]
	adds r0, 0xD4
	ldr r0, [r0]
	bl sub_80073E0
	bl sub_801CCD8
	movs r0, 0
	bl sub_801AD34
	ldr r0, [r4]
	adds r0, 0x70
	movs r1, 0
	bl sub_8012EA4
	add sp, 0x4
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080182DC: .4byte gUnknown_203B20C
_080182E0: .4byte gUnknown_80DB830
	thumb_func_end sub_8018280

	thumb_func_start sub_80182E4
sub_80182E4:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	movs r0, 0
	mov r8, r0
	ldr r4, _080183DC
	ldr r0, [r4]
	adds r0, 0x60
	movs r1, 0
	movs r2, 0x10
	bl MemoryFill16
	ldr r1, [r4]
	ldr r0, _080183E0
	ldr r0, [r0]
	str r0, [r1, 0x20]
	movs r0, 0x2
	str r0, [r1, 0x24]
	bl sub_8090A34
	cmp r0, 0
	beq _0801831C
	movs r0, 0
	bl sub_801CF50
	lsls r0, 24
	cmp r0, 0
	beq _08018324
_0801831C:
	ldr r0, [r4]
	adds r0, 0x60
	movs r1, 0x1
	strh r1, [r0]
_08018324:
	movs r1, 0x1
	add r8, r1
	ldr r4, _080183DC
	ldr r2, [r4]
	mov r0, r8
	lsls r3, r0, 3
	adds r0, r2, 0
	adds r0, 0x20
	adds r0, r3
	ldr r1, _080183E4
	ldr r1, [r1]
	str r1, [r0]
	adds r2, 0x24
	adds r2, r3
	movs r0, 0x3
	str r0, [r2]
	movs r0, 0x1
	bl sub_801CF14
	lsls r0, 24
	cmp r0, 0
	bne _08018358
	bl sub_8090A34
	cmp r0, 0x13
	ble _08018366
_08018358:
	ldr r0, [r4]
	mov r2, r8
	lsls r1, r2, 1
	adds r0, 0x60
	adds r0, r1
	movs r1, 0x1
	strh r1, [r0]
_08018366:
	movs r0, 0x1
	add r8, r0
	ldr r4, _080183DC
	ldr r7, [r4]
	mov r2, r8
	lsls r1, r2, 3
	adds r2, r7, 0
	adds r2, 0x20
	adds r3, r2, r1
	ldr r0, _080183E8
	ldr r0, [r0]
	str r0, [r3]
	adds r6, r7, 0
	adds r6, 0x24
	adds r1, r6, r1
	movs r3, 0x1
	str r3, [r1]
	add r8, r3
	mov r1, r8
	lsls r0, r1, 3
	adds r2, r0
	movs r1, 0
	str r1, [r2]
	adds r0, r6, r0
	str r3, [r0]
	movs r5, 0
	mov r12, r4
	cmp r5, r8
	bge _080183C0
	adds r4, r7, 0
	adds r2, r4, 0
	adds r2, 0x60
	adds r3, r6, 0
_080183A8:
	ldrh r0, [r2]
	cmp r0, 0
	bne _080183B6
	ldr r1, [r3]
	ldr r0, [r4, 0x14]
	cmp r1, r0
	beq _08018410
_080183B6:
	adds r2, 0x2
	adds r3, 0x8
	adds r5, 0x1
	cmp r5, r8
	blt _080183A8
_080183C0:
	movs r5, 0
	cmp r5, r8
	bge _08018410
	mov r2, r12
	ldr r1, [r2]
	adds r0, r1, 0
	adds r0, 0x60
	ldrh r0, [r0]
	cmp r0, 0
	bne _080183EC
	ldr r0, [r1, 0x24]
	str r0, [r1, 0x14]
	b _08018410
	.align 2, 0
_080183DC: .4byte gUnknown_203B20C
_080183E0: .4byte gUnknown_80D4958
_080183E4: .4byte gUnknown_80D4964
_080183E8: .4byte gUnknown_80D4934
_080183EC:
	adds r5, 0x1
	cmp r5, r8
	bge _08018410
	mov r0, r12
	ldr r2, [r0]
	lsls r0, r5, 1
	adds r1, r2, 0
	adds r1, 0x60
	adds r1, r0
	ldrh r0, [r1]
	cmp r0, 0
	bne _080183EC
	lsls r0, r5, 3
	adds r1, r2, 0
	adds r1, 0x24
	adds r1, r0
	ldr r0, [r1]
	str r0, [r2, 0x14]
_08018410:
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_80182E4

	thumb_func_start sub_801841C
sub_801841C:
	push {r4-r7,lr}
	ldr r4, _080184A0
	ldr r0, [r4]
	adds r0, 0x60
	movs r1, 0
	movs r2, 0x10
	bl MemoryFill16
	ldr r1, [r4]
	ldr r0, _080184A4
	ldr r0, [r0]
	str r0, [r1, 0x20]
	movs r0, 0x2
	str r0, [r1, 0x24]
	ldr r0, [r1, 0xC]
	bl sub_801ADA0
	lsls r0, 24
	cmp r0, 0
	bne _0801844C
	ldr r0, [r4]
	adds r0, 0x60
	movs r1, 0x1
	strh r1, [r0]
_0801844C:
	ldr r2, [r4]
	movs r1, 0x1
	ldr r0, _080184A8
	ldr r0, [r0]
	str r0, [r2, 0x28]
	movs r0, 0x4
	str r0, [r2, 0x2C]
	movs r5, 0x2
	movs r0, 0
	str r0, [r2, 0x30]
	str r1, [r2, 0x34]
	movs r3, 0
	adds r6, r4, 0
	mov r12, r2
	mov r4, r12
	adds r4, 0x60
	adds r2, 0x24
_0801846E:
	ldrh r0, [r4]
	cmp r0, 0
	bne _0801847E
	ldr r1, [r2]
	mov r7, r12
	ldr r0, [r7, 0x18]
	cmp r1, r0
	beq _080184CE
_0801847E:
	adds r4, 0x2
	adds r2, 0x8
	adds r3, 0x1
	cmp r3, r5
	blt _0801846E
	movs r3, 0
	cmp r3, r5
	bge _080184CE
	ldr r1, [r6]
	adds r0, r1, 0
	adds r0, 0x60
	ldrh r0, [r0]
	cmp r0, 0
	bne _080184AC
	ldr r0, [r1, 0x24]
	str r0, [r1, 0x18]
	b _080184CE
	.align 2, 0
_080184A0: .4byte gUnknown_203B20C
_080184A4: .4byte gUnknown_80D4958
_080184A8: .4byte gUnknown_80D4970
_080184AC:
	adds r3, 0x1
	cmp r3, r5
	bge _080184CE
	ldr r2, [r6]
	lsls r0, r3, 1
	adds r1, r2, 0
	adds r1, 0x60
	adds r1, r0
	ldrh r0, [r1]
	cmp r0, 0
	bne _080184AC
	lsls r0, r3, 3
	adds r1, r2, 0
	adds r1, 0x24
	adds r1, r0
	ldr r0, [r1]
	str r0, [r2, 0x18]
_080184CE:
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_801841C

	thumb_func_start sub_80184D4
sub_80184D4:
	push {r4-r7,lr}
	ldr r4, _08018554
	ldr r0, [r4]
	adds r0, 0x60
	movs r1, 0
	movs r2, 0x10
	bl MemoryFill16
	ldr r1, [r4]
	ldr r0, _08018558
	ldr r0, [r0]
	str r0, [r1, 0x20]
	movs r0, 0x3
	str r0, [r1, 0x24]
	bl sub_8090A34
	cmp r0, 0x13
	ble _08018500
	ldr r0, [r4]
	adds r0, 0x60
	movs r1, 0x1
	strh r1, [r0]
_08018500:
	ldr r2, [r4]
	movs r1, 0x1
	ldr r0, _0801855C
	ldr r0, [r0]
	str r0, [r2, 0x28]
	movs r0, 0x4
	str r0, [r2, 0x2C]
	movs r5, 0x2
	movs r0, 0
	str r0, [r2, 0x30]
	str r1, [r2, 0x34]
	movs r3, 0
	adds r6, r4, 0
	mov r12, r2
	mov r4, r12
	adds r4, 0x60
	adds r2, 0x24
_08018522:
	ldrh r0, [r4]
	cmp r0, 0
	bne _08018532
	ldr r1, [r2]
	mov r7, r12
	ldr r0, [r7, 0x1C]
	cmp r1, r0
	beq _08018582
_08018532:
	adds r4, 0x2
	adds r2, 0x8
	adds r3, 0x1
	cmp r3, r5
	blt _08018522
	movs r3, 0
	cmp r3, r5
	bge _08018582
	ldr r1, [r6]
	adds r0, r1, 0
	adds r0, 0x60
	ldrh r0, [r0]
	cmp r0, 0
	bne _08018560
	ldr r0, [r1, 0x24]
	str r0, [r1, 0x1C]
	b _08018582
	.align 2, 0
_08018554: .4byte gUnknown_203B20C
_08018558: .4byte gUnknown_80D4964
_0801855C: .4byte gUnknown_80D4970
_08018560:
	adds r3, 0x1
	cmp r3, r5
	bge _08018582
	ldr r2, [r6]
	lsls r0, r3, 1
	adds r1, r2, 0
	adds r1, 0x60
	adds r1, r0
	ldrh r0, [r1]
	cmp r0, 0
	bne _08018560
	lsls r0, r3, 3
	adds r1, r2, 0
	adds r1, 0x24
	adds r1, r0
	ldr r0, [r1]
	str r0, [r2, 0x1C]
_08018582:
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_80184D4

	thumb_func_start sub_8018588
sub_8018588:
	push {r4,lr}
	sub sp, 0x4
	movs r0, 0
	str r0, [sp]
	ldr r4, _080185C4
	ldr r0, [r4]
	adds r0, 0x70
	bl sub_8012FD8
	lsls r0, 24
	cmp r0, 0
	bne _080185B4
	ldr r0, [r4]
	adds r0, 0x70
	mov r1, sp
	bl sub_8013114
	ldr r1, [sp]
	cmp r1, 0x1
	beq _080185B4
	ldr r0, [r4]
	str r1, [r0, 0x14]
_080185B4:
	ldr r0, [sp]
	cmp r0, 0x2
	beq _080185CE
	cmp r0, 0x2
	bgt _080185C8
	cmp r0, 0x1
	beq _08018610
	b _08018616
	.align 2, 0
_080185C4: .4byte gUnknown_203B20C
_080185C8:
	cmp r0, 0x3
	beq _080185EA
	b _08018616
_080185CE:
	bl sub_8090A34
	cmp r0, 0
	beq _080185F6
	movs r0, 0
	bl sub_801CF50
	lsls r0, 24
	cmp r0, 0
	bne _080185F6
	movs r0, 0x4
	bl sub_8017F10
	b _08018616
_080185EA:
	movs r0, 0x1
	bl sub_801CF14
	lsls r0, 24
	cmp r0, 0
	beq _08018608
_080185F6:
	ldr r0, _08018604
	ldr r0, [r0]
	adds r0, 0x70
	movs r1, 0x1
	bl sub_8012EA4
	b _08018616
	.align 2, 0
_08018604: .4byte gUnknown_203B20C
_08018608:
	movs r0, 0xA
	bl sub_8017F10
	b _08018616
_08018610:
	movs r0, 0x3
	bl sub_8017F10
_08018616:
	add sp, 0x4
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_8018588

	thumb_func_start sub_8018620
sub_8018620:
	push {r4-r7,lr}
	movs r0, 0x1
	bl sub_801A6E8
	cmp r0, 0x3
	beq _0801863C
	cmp r0, 0x3
	bhi _08018636
	cmp r0, 0x2
	beq _080186E8
	b _080186F2
_08018636:
	cmp r0, 0x4
	beq _080186C0
	b _080186F2
_0801863C:
	bl sub_801AEA8
	cmp r0, 0
	beq _08018698
	movs r5, 0
	ldr r6, _0801868C
	movs r7, 0
_0801864A:
	adds r0, r5, 0
	bl sub_801AED0
	cmp r0, 0
	beq _0801866A
	lsls r4, r5, 2
	ldr r0, [r6]
	adds r0, r4
	bl sub_80917B8
	ldr r0, [r6]
	adds r0, r4
	strb r7, [r0, 0x2]
	ldr r0, [r6]
	adds r0, r4
	strb r7, [r0]
_0801866A:
	adds r5, 0x1
	cmp r5, 0x13
	ble _0801864A
	bl sub_80910B4
	bl sub_801AE84
	bl sub_8090A34
	cmp r0, 0
	bne _08018690
	bl sub_801A928
	movs r0, 0x1
	bl sub_8017F10
	b _080186F2
	.align 2, 0
_0801868C: .4byte gUnknown_203B460
_08018690:
	movs r0, 0x5
	bl sub_8017F10
	b _080186F2
_08018698:
	bl sub_801A8AC
	ldr r1, _080186B8
	ldr r2, [r1]
	str r0, [r2, 0xC]
	ldr r1, _080186BC
	ldr r1, [r1]
	lsls r0, 2
	adds r1, r0
	ldr r0, [r1]
	str r0, [r2, 0x8]
	movs r0, 0x6
	bl sub_8017F10
	b _080186F2
	.align 2, 0
_080186B8: .4byte gUnknown_203B20C
_080186BC: .4byte gUnknown_203B460
_080186C0:
	bl sub_801A8AC
	ldr r1, _080186E0
	ldr r2, [r1]
	str r0, [r2, 0xC]
	ldr r1, _080186E4
	ldr r1, [r1]
	lsls r0, 2
	adds r1, r0
	ldr r0, [r1]
	str r0, [r2, 0x8]
	movs r0, 0x7
	bl sub_8017F10
	b _080186F2
	.align 2, 0
_080186E0: .4byte gUnknown_203B20C
_080186E4: .4byte gUnknown_203B460
_080186E8:
	bl sub_801A928
	movs r0, 0x1
	bl sub_8017F10
_080186F2:
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_8018620

	thumb_func_start sub_80186F8
sub_80186F8:
	push {r4-r7,lr}
	sub sp, 0x4
	movs r0, 0x1
	bl sub_801CA08
	cmp r0, 0x2
	bne _08018708
	b _08018838
_08018708:
	cmp r0, 0x2
	bhi _08018714
	cmp r0, 0x1
	bne _08018712
	b _08018844
_08018712:
	b _0801884A
_08018714:
	cmp r0, 0x3
	beq _0801871E
	cmp r0, 0x4
	beq _0801880C
	b _0801884A
_0801871E:
	bl sub_801CFB8
	cmp r0, 0
	beq _080187E0
	movs r6, 0
	mov r5, sp
	ldr r7, _0801876C
_0801872C:
	lsls r0, r6, 24
	lsrs r4, r0, 24
	adds r0, r4, 0
	bl sub_801CFE0
	cmp r0, 0
	beq _080187B2
	ldr r1, _08018770
	ldr r0, [sp]
	ands r0, r1
	orrs r0, r4
	str r0, [sp]
	ldrb r0, [r5]
	bl sub_8090A60
	lsls r0, 24
	cmp r0, 0
	beq _08018786
	ldr r2, _08018774
	ldr r1, [r2]
	ldrb r0, [r5]
	lsls r0, 1
	adds r1, 0x50
	adds r1, r0
	ldrh r1, [r1]
	cmp r1, 0x63
	bls _08018778
	ldr r0, [sp]
	ands r0, r7
	movs r1, 0xC6
	lsls r1, 7
	b _08018780
	.align 2, 0
_0801876C: .4byte 0xffff00ff
_08018770: .4byte 0xffffff00
_08018774: .4byte gUnknown_203B460
_08018778:
	lsls r1, 24
	lsrs r1, 16
	ldr r0, [sp]
	ands r0, r7
_08018780:
	orrs r0, r1
	str r0, [sp]
	b _08018794
_08018786:
	ldr r0, [sp]
	ands r0, r7
	movs r1, 0x80
	lsls r1, 1
	orrs r0, r1
	str r0, [sp]
	ldr r2, _080187DC
_08018794:
	ldr r2, [r2]
	ldrb r0, [r5]
	lsls r0, 1
	adds r2, 0x50
	adds r2, r0
	ldr r0, [sp]
	lsrs r0, 8
	lsls r0, 24
	lsrs r0, 24
	ldrh r1, [r2]
	subs r1, r0
	strh r1, [r2]
	mov r0, sp
	bl sub_8091274
_080187B2:
	adds r6, 0x1
	cmp r6, 0xEF
	ble _0801872C
	bl sub_80910B4
	bl sub_801CF94
	movs r0, 0x1
	bl sub_801CF14
	lsls r0, 24
	cmp r0, 0
	bne _08018838
	bl sub_8090A34
	cmp r0, 0x13
	bgt _08018838
	movs r0, 0xB
	bl sub_8017F10
	b _0801884A
	.align 2, 0
_080187DC: .4byte gUnknown_203B460
_080187E0:
	bl sub_801CB24
	ldr r4, _08018808
	ldr r1, [r4]
	strb r0, [r1, 0x10]
	ldr r1, [r4]
	adds r0, r1, 0
	adds r0, 0x8
	ldrb r1, [r1, 0x10]
	movs r2, 0
	bl sub_8090A8C
	ldr r1, [r4]
	movs r0, 0x1
	strb r0, [r1, 0x9]
	movs r0, 0xD
	bl sub_8017F10
	b _0801884A
	.align 2, 0
_08018808: .4byte gUnknown_203B20C
_0801880C:
	bl sub_801CB24
	ldr r4, _08018834
	ldr r1, [r4]
	strb r0, [r1, 0x10]
	ldr r1, [r4]
	adds r0, r1, 0
	adds r0, 0x8
	ldrb r1, [r1, 0x10]
	movs r2, 0
	bl sub_8090A8C
	ldr r1, [r4]
	movs r0, 0x1
	strb r0, [r1, 0x9]
	movs r0, 0xE
	bl sub_8017F10
	b _0801884A
	.align 2, 0
_08018834: .4byte gUnknown_203B20C
_08018838:
	bl sub_801CBB8
	movs r0, 0x1
	bl sub_8017F10
	b _0801884A
_08018844:
	movs r0, 0
	bl sub_801AD34
_0801884A:
	add sp, 0x4
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_80186F8

	thumb_func_start sub_8018854
sub_8018854:
	push {r4,lr}
	sub sp, 0x4
	movs r0, 0
	bl sub_801CA08
	ldr r4, _080188E0
	ldr r0, [r4]
	adds r0, 0x70
	bl sub_8012FD8
	ldr r0, [r4]
	adds r0, 0xC0
	bl sub_8013BBC
	cmp r0, 0x1
	beq _080188F8
	cmp r0, 0x1
	bcc _080188FC
	cmp r0, 0x2
	beq _080188F0
	cmp r0, 0x3
	bne _080188FC
	ldr r1, [r4]
	adds r0, r1, 0
	adds r0, 0xC0
	ldr r0, [r0]
	strb r0, [r1, 0x9]
	ldr r0, _080188E4
	ldr r1, [r0]
	ldr r3, [r4]
	ldrb r0, [r3, 0xA]
	lsls r0, 1
	adds r1, 0x50
	adds r1, r0
	ldrb r2, [r3, 0x9]
	ldrh r0, [r1]
	subs r0, r2
	strh r0, [r1]
	ldrb r2, [r3, 0xA]
	ldr r1, _080188E8
	ldr r0, [sp]
	ands r0, r1
	orrs r0, r2
	str r0, [sp]
	ldrb r1, [r3, 0x9]
	lsls r1, 8
	ldr r2, _080188EC
	ands r0, r2
	orrs r0, r1
	str r0, [sp]
	mov r0, sp
	bl sub_8091274
	movs r0, 0x1
	bl sub_801CF14
	lsls r0, 24
	cmp r0, 0
	bne _080188D2
	bl sub_8090A34
	cmp r0, 0x13
	ble _080188F0
_080188D2:
	bl sub_801CBB8
	movs r0, 0x1
	bl sub_8017F10
	b _080188FC
	.align 2, 0
_080188E0: .4byte gUnknown_203B20C
_080188E4: .4byte gUnknown_203B460
_080188E8: .4byte 0xffffff00
_080188EC: .4byte 0xffff00ff
_080188F0:
	movs r0, 0xB
	bl sub_8017F10
	b _080188FC
_080188F8:
	bl sub_8018280
_080188FC:
	add sp, 0x4
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_8018854

	thumb_func_start sub_8018904
sub_8018904:
	push {r4,lr}
	sub sp, 0x4
	movs r0, 0
	str r0, [sp]
	bl sub_801A6E8
	ldr r4, _08018944
	ldr r0, [r4]
	adds r0, 0x70
	bl sub_8012FD8
	lsls r0, 24
	cmp r0, 0
	bne _08018934
	ldr r0, [r4]
	adds r0, 0x70
	mov r1, sp
	bl sub_8013114
	ldr r1, [sp]
	cmp r1, 0x1
	beq _08018934
	ldr r0, [r4]
	str r1, [r0, 0x18]
_08018934:
	ldr r0, [sp]
	cmp r0, 0x2
	beq _0801894E
	cmp r0, 0x2
	bgt _08018948
	cmp r0, 0x1
	beq _080189BA
	b _080189C0
	.align 2, 0
_08018944: .4byte gUnknown_203B20C
_08018948:
	cmp r0, 0x4
	beq _080189AC
	b _080189C0
_0801894E:
	ldr r4, _08018978
	ldr r0, [r4]
	ldrb r0, [r0, 0xA]
	bl sub_8091524
	lsls r0, 24
	cmp r0, 0
	beq _0801896C
	ldr r0, [r4]
	ldr r0, [r0, 0xC]
	bl sub_801ADA0
	lsls r0, 24
	cmp r0, 0
	bne _0801897C
_0801896C:
	ldr r0, [r4]
	adds r0, 0x70
	movs r1, 0x1
	bl sub_8012EA4
	b _080189C0
	.align 2, 0
_08018978: .4byte gUnknown_203B20C
_0801897C:
	ldr r0, [r4]
	adds r0, 0x8
	bl sub_80917B8
	ldr r0, [r4]
	ldr r0, [r0, 0xC]
	bl sub_80911F8
	bl sub_80910B4
	bl sub_8090A34
	cmp r0, 0
	bne _080189A4
	bl sub_801A928
	movs r0, 0x1
	bl sub_8017F10
	b _080189C0
_080189A4:
	movs r0, 0x5
	bl sub_8017F10
	b _080189C0
_080189AC:
	movs r0, 0
	bl sub_8099690
	movs r0, 0x7
	bl sub_8017F10
	b _080189C0
_080189BA:
	movs r0, 0x5
	bl sub_8017F10
_080189C0:
	add sp, 0x4
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_8018904

	thumb_func_start sub_80189C8
sub_80189C8:
	push {r4,lr}
	sub sp, 0x8
	movs r0, 0
	str r0, [sp]
	bl sub_801CA08
	ldr r4, _08018A08
	ldr r0, [r4]
	adds r0, 0x70
	bl sub_8012FD8
	lsls r0, 24
	cmp r0, 0
	bne _080189F8
	ldr r0, [r4]
	adds r0, 0x70
	mov r1, sp
	bl sub_8013114
	ldr r1, [sp]
	cmp r1, 0x1
	beq _080189F8
	ldr r0, [r4]
	str r1, [r0, 0x1C]
_080189F8:
	ldr r0, [sp]
	cmp r0, 0x3
	beq _08018A12
	cmp r0, 0x3
	bgt _08018A0C
	cmp r0, 0x1
	beq _08018AB8
	b _08018ABE
	.align 2, 0
_08018A08: .4byte gUnknown_203B20C
_08018A0C:
	cmp r0, 0x4
	beq _08018AB0
	b _08018ABE
_08018A12:
	bl sub_8090A34
	cmp r0, 0x13
	ble _08018A2C
	ldr r0, _08018A28
	ldr r0, [r0]
	adds r0, 0x70
	movs r1, 0x1
	bl sub_8012EA4
	b _08018ABE
	.align 2, 0
_08018A28: .4byte gUnknown_203B20C
_08018A2C:
	ldr r4, _08018A44
	ldr r0, [r4]
	ldrb r0, [r0, 0xA]
	bl sub_8090A60
	lsls r0, 24
	cmp r0, 0
	beq _08018A48
	movs r0, 0xC
	bl sub_8017F10
	b _08018ABE
	.align 2, 0
_08018A44: .4byte gUnknown_203B20C
_08018A48:
	ldr r0, _08018A9C
	ldr r1, [r0]
	ldr r3, [r4]
	ldrb r0, [r3, 0xA]
	lsls r0, 1
	adds r1, 0x50
	adds r1, r0
	ldrb r2, [r3, 0x9]
	ldrh r0, [r1]
	subs r0, r2
	strh r0, [r1]
	ldrb r2, [r3, 0xA]
	ldr r1, _08018AA0
	ldr r0, [sp, 0x4]
	ands r0, r1
	orrs r0, r2
	str r0, [sp, 0x4]
	ldrb r1, [r3, 0x9]
	lsls r1, 8
	ldr r2, _08018AA4
	ands r0, r2
	orrs r0, r1
	str r0, [sp, 0x4]
	add r0, sp, 0x4
	bl sub_8091274
	movs r0, 0x1
	bl sub_801CF14
	lsls r0, 24
	cmp r0, 0
	bne _08018A90
	bl sub_8090A34
	cmp r0, 0x13
	ble _08018AA8
_08018A90:
	bl sub_801CBB8
	movs r0, 0x1
	bl sub_8017F10
	b _08018ABE
	.align 2, 0
_08018A9C: .4byte gUnknown_203B460
_08018AA0: .4byte 0xffffff00
_08018AA4: .4byte 0xffff00ff
_08018AA8:
	movs r0, 0xB
	bl sub_8017F10
	b _08018ABE
_08018AB0:
	movs r0, 0xE
	bl sub_8017F10
	b _08018ABE
_08018AB8:
	movs r0, 0xB
	bl sub_8017F10
_08018ABE:
	add sp, 0x8
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_80189C8

	thumb_func_start sub_8018AC8
sub_8018AC8:
	push {lr}
	bl sub_801B410
	cmp r0, 0x1
	bls _08018AE0
	cmp r0, 0x3
	bhi _08018AE0
	bl sub_801B450
	movs r0, 0x5
	bl sub_8017F10
_08018AE0:
	pop {r0}
	bx r0
	thumb_func_end sub_8018AC8

	thumb_func_start sub_8018AE4
sub_8018AE4:
	push {lr}
	bl sub_801B410
	cmp r0, 0x1
	bls _08018AFC
	cmp r0, 0x3
	bhi _08018AFC
	bl sub_801B450
	movs r0, 0xB
	bl sub_8017F10
_08018AFC:
	pop {r0}
	bx r0
	thumb_func_end sub_8018AE4

        .align 2,0
