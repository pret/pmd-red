	.include "constants/gba_constants.inc"
	.include "asm/macros.inc"

	.syntax unified

	.text

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
_0801868C: .4byte gTeamInventory_203B460
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
_080186BC: .4byte gTeamInventory_203B460
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
_080186E4: .4byte gTeamInventory_203B460
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
_08018774: .4byte gTeamInventory_203B460
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
_080187DC: .4byte gTeamInventory_203B460
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
_080188E4: .4byte gTeamInventory_203B460
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
	bl IsNotMoneyOrUsedTMItem
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
_08018A9C: .4byte gTeamInventory_203B460
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

        .align 2,0
