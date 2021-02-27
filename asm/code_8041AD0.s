	.include "constants/gba_constants.inc"
	.include "asm/macros.inc"

	.syntax unified

	.text

	thumb_func_start sub_804225C
sub_804225C:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0x4
	mov r8, r0
	adds r5, r1, 0
	lsls r2, 24
	lsrs r4, r2, 24
	adds r7, r4, 0
	cmp r4, 0x11
	bne _08042274
	b _08042384
_08042274:
	adds r0, r5, 0
	bl sub_803F428
	lsls r0, 24
	cmp r0, 0
	bne _08042282
	b _08042384
_08042282:
	adds r0, r4, 0
	bl sub_800EF28
	bl sub_800EF64
	movs r0, 0x4
	movs r1, 0x42
	bl sub_803E708
	movs r0, 0
	ldrsh r1, [r5, r0]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 11
	movs r1, 0xC0
	lsls r1, 4
	adds r0, r1
	cmp r0, 0
	bge _080422AA
	adds r0, 0xFF
_080422AA:
	lsls r0, 8
	lsrs r0, 16
	ldr r1, _080422FC
	ldr r2, [sp]
	ands r2, r1
	orrs r2, r0
	str r2, [sp]
	movs r0, 0x2
	ldrsh r1, [r5, r0]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 11
	movs r1, 0x80
	lsls r1, 5
	adds r0, r1
	cmp r0, 0
	bge _080422CE
	adds r0, 0xFF
_080422CE:
	lsls r0, 8
	lsrs r0, 16
	lsls r0, 16
	ldr r1, _08042300
	ands r2, r1
	orrs r2, r0
	str r2, [sp]
	adds r0, r4, 0
	mov r1, sp
	bl sub_800E448
	adds r6, r0, 0
	cmp r4, 0x4
	bne _08042308
	ldr r1, _08042304
	movs r0, 0
	bl sub_80421C0
	movs r0, 0x28
	movs r1, 0x33
	bl sub_803E708
	b _08042360
	.align 2, 0
_080422FC: .4byte 0xffff0000
_08042300: .4byte 0x0000ffff
_08042304: .4byte 0x00000193
_08042308:
	cmp r7, 0x8
	bne _08042358
	mov r0, r8
	ldr r7, [r0, 0x70]
	adds r0, r7, 0
	adds r0, 0x46
	ldrb r4, [r0]
	movs r5, 0
	b _0804231C
_0804231A:
	adds r5, 0x2
_0804231C:
	ldr r0, _08042354
	cmp r5, r0
	bgt _08042346
	subs r4, 0x1
	movs r0, 0x7
	ands r4, r0
	mov r0, r8
	movs r1, 0
	adds r2, r4, 0
	bl sub_806CDD4
	movs r0, 0x2
	movs r1, 0x33
	bl sub_803E708
	adds r0, r6, 0
	bl sub_800E9A8
	lsls r0, 24
	cmp r0, 0
	bne _0804231A
_08042346:
	movs r0, 0x7
	ands r4, r0
	adds r0, r7, 0
	adds r0, 0x46
	strb r4, [r0]
	b _08042360
	.align 2, 0
_08042354: .4byte 0x000003e7
_08042358:
	movs r0, 0x28
	movs r1, 0x33
	bl sub_803E708
_08042360:
	movs r5, 0
	ldr r4, _08042368
	b _0804236E
	.align 2, 0
_08042368: .4byte 0x000003e7
_0804236C:
	adds r5, 0x1
_0804236E:
	cmp r5, r4
	bgt _08042384
	movs r0, 0x42
	bl sub_803E46C
	adds r0, r6, 0
	bl sub_800E9A8
	lsls r0, 24
	cmp r0, 0
	bne _0804236C
_08042384:
	add sp, 0x4
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_804225C

	thumb_func_start sub_8042390
sub_8042390:
	push {r4-r6,lr}
	sub sp, 0x18
	adds r5, r0, 0
	adds r4, r1, 0
	bl sub_8042768
	lsls r0, 24
	cmp r0, 0
	beq _08042454
	ldrb r1, [r4]
	movs r0, 0x8
	ands r0, r1
	movs r6, 0
	cmp r0, 0
	bne _080423B0
	ldrb r6, [r4, 0x2]
_080423B0:
	adds r0, r6, 0
	movs r1, 0
	bl sub_800EF40
	bl sub_800EF64
	movs r0, 0x4
	movs r1, 0x42
	bl sub_803E708
	ldr r0, [r5, 0xC]
	cmp r0, 0
	bge _080423CC
	adds r0, 0xFF
_080423CC:
	lsls r0, 8
	lsrs r0, 16
	ldr r1, _08042428
	ldr r2, [sp, 0x14]
	ands r2, r1
	orrs r2, r0
	str r2, [sp, 0x14]
	ldr r0, [r5, 0x10]
	cmp r0, 0
	bge _080423E2
	adds r0, 0xFF
_080423E2:
	lsls r0, 8
	lsrs r0, 16
	lsls r0, 16
	ldr r4, _0804242C
	ands r4, r2
	orrs r4, r0
	str r4, [sp, 0x14]
	asrs r4, 16
	ldr r0, _08042430
	ldr r0, [r0]
	ldr r1, _08042434
	adds r0, r1
	movs r1, 0
	ldrsh r0, [r0, r1]
	subs r4, r0
	lsrs r0, r4, 31
	adds r4, r0
	asrs r4, 1
	adds r4, 0x1
	adds r1, r5, 0
	adds r1, 0x28
	add r0, sp, 0x4
	bl sub_8005700
	add r1, sp, 0x14
	str r4, [sp]
	adds r0, r6, 0
	add r2, sp, 0x4
	movs r3, 0
	bl sub_800E49C
	adds r5, r0, 0
	movs r4, 0
	ldr r6, _08042438
	b _0804243E
	.align 2, 0
_08042428: .4byte 0xffff0000
_0804242C: .4byte 0x0000ffff
_08042430: .4byte gUnknown_203B418
_08042434: .4byte 0x000181f2
_08042438: .4byte 0x000003e7
_0804243C:
	adds r4, 0x1
_0804243E:
	cmp r4, r6
	bgt _08042454
	movs r0, 0x42
	bl sub_803E46C
	adds r0, r5, 0
	bl sub_800E9A8
	lsls r0, 24
	cmp r0, 0
	bne _0804243C
_08042454:
	add sp, 0x18
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end sub_8042390

	thumb_func_start sub_804245C
sub_804245C:
	push {r4-r6,lr}
	sub sp, 0x18
	adds r5, r0, 0
	adds r4, r1, 0
	bl sub_8042768
	lsls r0, 24
	cmp r0, 0
	beq _08042518
	ldrb r1, [r4]
	movs r0, 0x8
	ands r0, r1
	movs r6, 0
	cmp r0, 0
	bne _0804247C
	ldrb r6, [r4, 0x2]
_0804247C:
	bl sub_800EF64
	movs r0, 0x4
	movs r1, 0x42
	bl sub_803E708
	ldr r0, [r5, 0xC]
	cmp r0, 0
	bge _08042490
	adds r0, 0xFF
_08042490:
	lsls r0, 8
	lsrs r0, 16
	ldr r1, _080424EC
	ldr r2, [sp, 0x14]
	ands r2, r1
	orrs r2, r0
	str r2, [sp, 0x14]
	ldr r0, [r5, 0x10]
	cmp r0, 0
	bge _080424A6
	adds r0, 0xFF
_080424A6:
	lsls r0, 8
	lsrs r0, 16
	lsls r0, 16
	ldr r4, _080424F0
	ands r4, r2
	orrs r4, r0
	str r4, [sp, 0x14]
	asrs r4, 16
	ldr r0, _080424F4
	ldr r0, [r0]
	ldr r1, _080424F8
	adds r0, r1
	movs r1, 0
	ldrsh r0, [r0, r1]
	subs r4, r0
	lsrs r0, r4, 31
	adds r4, r0
	asrs r4, 1
	adds r4, 0x1
	adds r1, r5, 0
	adds r1, 0x28
	add r0, sp, 0x4
	bl sub_8005700
	add r1, sp, 0x14
	str r4, [sp]
	adds r0, r6, 0
	add r2, sp, 0x4
	movs r3, 0x1
	bl sub_800E49C
	adds r5, r0, 0
	movs r4, 0
	ldr r6, _080424FC
	b _08042502
	.align 2, 0
_080424EC: .4byte 0xffff0000
_080424F0: .4byte 0x0000ffff
_080424F4: .4byte gUnknown_203B418
_080424F8: .4byte 0x000181f2
_080424FC: .4byte 0x000003e7
_08042500:
	adds r4, 0x1
_08042502:
	cmp r4, r6
	bgt _08042518
	movs r0, 0x42
	bl sub_803E46C
	adds r0, r5, 0
	bl sub_800E9A8
	lsls r0, 24
	cmp r0, 0
	bne _08042500
_08042518:
	add sp, 0x18
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end sub_804245C

	thumb_func_start sub_8042520
sub_8042520:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x3C
	adds r4, r0, 0
	bl sub_8045888
	lsls r0, 24
	cmp r0, 0
	bne _0804253A
	b _08042664
_0804253A:
	ldr r0, [r4, 0x70]
	adds r0, 0x46
	ldrb r5, [r0]
	ldr r0, [r4, 0xC]
	cmp r0, 0
	bge _08042548
	adds r0, 0xFF
_08042548:
	lsls r0, 8
	lsrs r0, 16
	ldr r1, _0804264C
	ldr r2, [sp, 0x2C]
	ands r2, r1
	orrs r2, r0
	str r2, [sp, 0x2C]
	ldr r0, [r4, 0x10]
	cmp r0, 0
	bge _0804255E
	adds r0, 0xFF
_0804255E:
	lsls r0, 8
	lsrs r0, 16
	lsls r0, 16
	ldr r1, _08042650
	ands r1, r2
	orrs r1, r0
	str r1, [sp, 0x2C]
	asrs r1, 16
	ldr r0, _08042654
	ldr r0, [r0]
	ldr r2, _08042658
	adds r0, r2
	movs r2, 0
	ldrsh r0, [r0, r2]
	subs r1, r0
	lsrs r0, r1, 31
	adds r1, r0
	asrs r7, r1, 1
	ldr r0, _0804265C
	str r0, [sp, 0x4]
	movs r2, 0
	str r2, [sp, 0x8]
	str r5, [sp, 0xC]
	add r1, sp, 0x4
	add r4, sp, 0x2C
	ldrh r0, [r4]
	strh r0, [r1, 0xC]
	ldr r0, [sp, 0x2C]
	asrs r0, 16
	strh r0, [r1, 0xE]
	adds r0, r1, 0
	strh r2, [r0, 0x10]
	strh r2, [r0, 0x12]
	movs r0, 0x1
	negs r0, r0
	str r0, [sp, 0x18]
	str r7, [sp, 0x1C]
	add r0, sp, 0x20
	bl sub_8004E8C
	add r0, sp, 0x4
	movs r1, 0
	bl sub_8041764
	adds r6, r0, 0
	mov r10, r4
	lsls r1, r5, 2
	mov r0, sp
	adds r0, 0x30
	str r0, [sp, 0x38]
	ldr r0, _08042660
	adds r5, r1, r0
	movs r1, 0x5
	mov r8, r1
	mov r9, r10
_080425CC:
	movs r0, 0
	str r0, [sp]
	adds r0, r6, 0
	adds r1, r4, 0
	movs r2, 0
	adds r3, r7, 0
	bl sub_800E8AC
	movs r0, 0x42
	bl sub_803E46C
	movs r2, 0
	ldrsh r0, [r5, r2]
	lsls r0, 2
	mov r1, r9
	ldrh r1, [r1]
	adds r0, r1
	mov r2, r9
	strh r0, [r2]
	movs r0, 0x2
	ldrsh r1, [r5, r0]
	lsls r1, 2
	ldrh r0, [r4, 0x2]
	adds r0, r1
	strh r0, [r4, 0x2]
	movs r2, 0x2
	ldrsh r1, [r4, r2]
	ldr r0, _08042654
	ldr r0, [r0]
	ldr r2, _08042658
	adds r0, r2
	movs r2, 0
	ldrsh r0, [r0, r2]
	subs r1, r0
	lsrs r0, r1, 31
	adds r1, r0
	asrs r7, r1, 1
	movs r0, 0x1
	negs r0, r0
	add r8, r0
	mov r1, r8
	cmp r1, 0
	bge _080425CC
	bl sub_800DBBC
	mov r2, r10
	movs r1, 0
	ldrsh r0, [r2, r1]
	lsls r0, 8
	str r0, [sp, 0x30]
	add r0, sp, 0x2C
	movs r2, 0x2
	ldrsh r0, [r0, r2]
	lsls r0, 8
	ldr r1, [sp, 0x38]
	str r0, [r1, 0x4]
	movs r1, 0xD0
	lsls r1, 1
	ldr r0, [sp, 0x38]
	movs r2, 0x1
	bl sub_80416E0
	adds r6, r0, 0
	b _08042668
	.align 2, 0
_0804264C: .4byte 0xffff0000
_08042650: .4byte 0x0000ffff
_08042654: .4byte gUnknown_203B418
_08042658: .4byte 0x000181f2
_0804265C: .4byte 0x00000165
_08042660: .4byte gUnknown_80F4448
_08042664:
	movs r6, 0x1
	negs r6, r6
_08042668:
	adds r0, r6, 0
	add sp, 0x3C
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_8042520

	thumb_func_start sub_804267C
sub_804267C:
	push {r4,lr}
	ldr r4, _080426B8
	bl sub_8043D10
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0
	beq _08042694
	cmp r0, 0
	blt _08042694
	cmp r0, 0x2
	ble _080426AC
_08042694:
	ldr r0, _080426BC
	ldr r0, [r0]
	ldr r1, _080426C0
	adds r0, r1
	ldrb r0, [r0]
	bl GetStairDirection
	lsls r0, 24
	ldr r4, _080426C4
	cmp r0, 0
	beq _080426AC
	subs r4, 0x1
_080426AC:
	adds r0, r4, 0
	bl sub_8083E38
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080426B8: .4byte 0x000003e5
_080426BC: .4byte gUnknown_203B418
_080426C0: .4byte 0x00000644
_080426C4: .4byte 0x00000155
	thumb_func_end sub_804267C

	thumb_func_start sub_80426C8
sub_80426C8:
	push {r4,r5,lr}
	adds r5, r0, 0
	adds r4, r1, 0
	cmp r4, 0x3
	bne _080426D8
	movs r0, 0
	bl sub_8083E88
_080426D8:
	cmp r5, 0x4
	beq _080426F0
	ldr r0, _080426EC
	lsls r1, r4, 1
	adds r1, r0
	ldrh r0, [r1]
	bl sub_8083E38
	b _080426FC
	.align 2, 0
_080426EC: .4byte gUnknown_80F67DC
_080426F0:
	ldr r0, _08042708
	lsls r1, r4, 1
	adds r1, r0
	ldrh r0, [r1]
	bl sub_8083E38
_080426FC:
	adds r0, r5, 0
	adds r1, r4, 0
	movs r2, 0x80
	bl sub_8042B34
	b _08042712
	.align 2, 0
_08042708: .4byte gUnknown_80F67E4
_0804270C:
	movs r0, 0x46
	bl sub_803E46C
_08042712:
	bl sub_8042CC0
	lsls r0, 24
	cmp r0, 0
	bne _0804270C
	bl sub_8042D7C
	bl sub_8040238
	movs r0, 0x1
	bl sub_8052210
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_80426C8

	thumb_func_start sub_8042730
sub_8042730:
	push {r4,r5,lr}
	adds r4, r0, 0
	movs r1, 0x8
	movs r2, 0x8
	bl sub_806CDD4
	movs r5, 0
	b _08042742
_08042740:
	adds r5, 0x1
_08042742:
	cmp r5, 0x63
	bgt _08042760
	movs r0, 0x51
	bl sub_803E46C
	ldr r0, [r4, 0x40]
	movs r1, 0x3
	ands r0, r1
	cmp r0, 0
	bne _08042760
	adds r0, r4, 0
	adds r0, 0x6B
	ldrb r0, [r0]
	cmp r0, 0x8
	beq _08042740
_08042760:
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_8042730

	thumb_func_start sub_8042768
sub_8042768:
	push {lr}
	adds r1, r0, 0
	adds r0, 0x20
	ldrb r0, [r0]
	cmp r0, 0
	bne _08042778
_08042774:
	movs r0, 0
	b _080427A6
_08042778:
	ldr r0, _08042794
	ldr r2, [r0]
	ldr r3, _08042798
	adds r0, r2, r3
	ldrb r0, [r0]
	cmp r0, 0
	beq _0804279C
	subs r3, 0x12
	adds r0, r2, r3
	ldr r0, [r0]
	cmp r0, r1
	bne _08042774
	movs r0, 0x1
	b _080427A6
	.align 2, 0
_08042794: .4byte gUnknown_203B418
_08042798: .4byte 0x0001820a
_0804279C:
	adds r0, r1, 0
	bl sub_8045888
	lsls r0, 24
	lsrs r0, 24
_080427A6:
	pop {r1}
	bx r1
	thumb_func_end sub_8042768

	thumb_func_start sub_80427AC
sub_80427AC:
	push {r4-r6,lr}
	movs r6, 0
_080427B0:
	ldr r0, _08042808
	ldr r0, [r0]
	lsls r1, r6, 2
	ldr r2, _0804280C
	adds r0, r2
	adds r0, r1
	ldr r4, [r0]
	adds r0, r4, 0
	bl sub_80450E0
	lsls r0, 24
	cmp r0, 0
	beq _080427FA
	ldr r5, [r4, 0x70]
	adds r1, r5, 0
	adds r1, 0xF3
	ldrb r0, [r1]
	cmp r0, 0
	beq _080427FA
	movs r0, 0
	strb r0, [r1]
	adds r0, r4, 0
	bl sub_80429A0
	ldrb r0, [r5, 0x6]
	cmp r0, 0
	bne _080427FA
	ldr r0, _08042810
	adds r1, r4, 0
	movs r2, 0
	bl sub_8045B94
	ldr r0, _08042814
	ldr r1, [r0]
	adds r0, r4, 0
	bl sub_805239C
_080427FA:
	adds r6, 0x1
	cmp r6, 0x13
	ble _080427B0
	pop {r4-r6}
	pop {r0}
	bx r0
	.align 2, 0
_08042808: .4byte gUnknown_203B418
_0804280C: .4byte 0x000135cc
_08042810: .4byte gAvailablePokemonNames
_08042814: .4byte gPtrFeralFoundItemMessage
	thumb_func_end sub_80427AC

	thumb_func_start sub_8042818
sub_8042818:
	push {r4-r7,lr}
	lsls r0, 24
	lsrs r5, r0, 24
	lsls r1, 24
	lsrs r7, r1, 24
	ldr r0, _08042874
	ldr r0, [r0]
	ldr r1, _08042878
	adds r0, r1
	ldr r4, [r0]
	cmp r4, 0
	bne _08042836
	bl sub_8083600
	adds r4, r0, 0
_08042836:
	ldr r1, _0804287C
	lsls r0, r5, 1
	adds r2, r0, r1
	ldrh r1, [r2]
	ldr r0, _08042880
	cmp r1, r0
	beq _0804284A
	adds r0, r4, 0
	bl sub_80421C0
_0804284A:
	ldr r0, _08042884
	lsls r1, r5, 2
	adds r0, r1, r0
	ldr r5, [r0]
	adds r6, r1, 0
	cmp r5, 0
	blt _08042896
	cmp r7, 0
	beq _08042888
	bl sub_80441BC
	lsls r0, 24
	cmp r0, 0
	bne _08042888
	adds r0, r4, 0
	adds r1, r5, 0
	movs r2, 0
	bl sub_804151C
	b _08042896
	.align 2, 0
_08042874: .4byte gUnknown_203B418
_08042878: .4byte 0x000181f8
_0804287C: .4byte gUnknown_80F682C
_08042880: .4byte 0x000003e5
_08042884: .4byte gUnknown_80F67EC
_08042888:
	ldr r0, _0804289C
	adds r0, r6, r0
	ldr r1, [r0]
	adds r0, r4, 0
	movs r2, 0
	bl sub_804151C
_08042896:
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_0804289C: .4byte gUnknown_80F680C
	thumb_func_end sub_8042818

        .align 2,0
