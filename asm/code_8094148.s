	.include "constants/gba_constants.inc"
	.include "asm/macros.inc"

	.syntax unified

	.text

	thumb_func_start sub_8094268
sub_8094268:
	push {r4-r6,lr}
	adds r5, r0, 0
	adds r3, r1, 0
	asrs r0, r3, 16
	asrs r1, r2, 16
	adds r0, r1
	lsls r0, 16
	ldr r6, _080942B0
	ands r3, r6
	orrs r3, r0
	adds r2, r3, r2
	lsls r2, 16
	lsrs r2, 16
	ldr r4, _080942B4
	ands r3, r4
	orrs r3, r2
	asrs r1, r3, 16
	ldr r0, _080942B8
	cmp r1, r0
	ble _080942A6
	adds r0, r3, 0x1
	lsls r0, 16
	lsrs r0, 16
	ands r3, r4
	orrs r3, r0
	asrs r0, r3, 16
	ldr r1, _080942BC
	adds r0, r1
	lsls r0, 16
	ands r3, r6
	orrs r3, r0
_080942A6:
	str r3, [r5]
	adds r0, r5, 0
	pop {r4-r6}
	pop {r1}
	bx r1
	.align 2, 0
_080942B0: .4byte 0x0000ffff
_080942B4: .4byte 0xffff0000
_080942B8: .4byte 0x000003e7
_080942BC: .4byte 0xfffffc18
	thumb_func_end sub_8094268

	thumb_func_start sub_80942C0
sub_80942C0:
	push {r4,r5,lr}
	adds r5, r0, 0
	adds r3, r1, 0
	asrs r0, r3, 16
	asrs r1, r2, 16
	subs r0, r1
	lsls r0, 16
	ldr r4, _08094310
	ands r3, r4
	orrs r3, r0
	subs r2, r3, r2
	lsls r2, 16
	lsrs r2, 16
	ldr r1, _08094314
	ands r3, r1
	orrs r3, r2
	cmp r3, 0
	bge _080942FC
	subs r0, r3, 0x1
	lsls r0, 16
	lsrs r0, 16
	ands r3, r1
	orrs r3, r0
	asrs r0, r3, 16
	movs r2, 0xFA
	lsls r2, 2
	adds r0, r2
	lsls r0, 16
	ands r3, r4
	orrs r3, r0
_080942FC:
	lsls r0, r3, 16
	cmp r0, 0
	bge _08094304
	movs r3, 0
_08094304:
	str r3, [r5]
	adds r0, r5, 0
	pop {r4,r5}
	pop {r1}
	bx r1
	.align 2, 0
_08094310: .4byte 0x0000ffff
_08094314: .4byte 0xffff0000
	thumb_func_end sub_80942C0

	thumb_func_start sub_8094318
sub_8094318:
	push {r4,lr}
	adds r4, r0, 0
	adds r3, r1, 0
	lsls r0, r3, 16
	asrs r1, r0, 16
	lsls r0, r2, 16
	asrs r0, 16
	cmp r1, r0
	bgt _08094336
	cmp r1, r0
	blt _0809433A
	asrs r1, r3, 16
	asrs r0, r2, 16
	cmp r1, r0
	ble _0809433A
_08094336:
	str r2, [r4]
	b _0809433C
_0809433A:
	str r3, [r4]
_0809433C:
	adds r0, r4, 0
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_8094318

	thumb_func_start sub_8094344
sub_8094344:
	push {r4,lr}
	adds r4, r0, 0
	adds r3, r1, 0
	lsls r0, r3, 16
	asrs r1, r0, 16
	lsls r0, r2, 16
	asrs r0, 16
	cmp r1, r0
	bgt _08094362
	cmp r1, r0
	blt _08094366
	asrs r1, r3, 16
	asrs r0, r2, 16
	cmp r1, r0
	ble _08094366
_08094362:
	str r3, [r4]
	b _08094368
_08094366:
	str r2, [r4]
_08094368:
	adds r0, r4, 0
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_8094344

	thumb_func_start sub_8094370
sub_8094370:
	push {r4,r5,lr}
	adds r5, r0, 0
	lsls r1, 16
	lsls r2, 16
	ldr r4, _08094398
	lsrs r3, r1, 16
	orrs r3, r2
	asrs r2, 16
	ldr r1, _0809439C
	asrs r0, r1, 16
	cmp r2, r0
	ble _0809438C
	ands r3, r4
	orrs r3, r1
_0809438C:
	str r3, [r5]
	adds r0, r5, 0
	pop {r4,r5}
	pop {r1}
	bx r1
	.align 2, 0
_08094398: .4byte 0x0000ffff
_0809439C: .4byte 0x03e70000
	thumb_func_end sub_8094370

	thumb_func_start sub_80943A0
sub_80943A0:
	lsls r1, 16
	lsrs r2, r1, 16
	str r2, [r0]
	bx lr
	thumb_func_end sub_80943A0

	thumb_func_start sub_80943A8
sub_80943A8:
	push {r4,r5,lr}
	ldr r3, [r1, 0x4]
	lsrs r2, r3, 16
	ldr r1, _080943D4
	ands r5, r1
	orrs r5, r2
	ldr r4, _080943D8
	adds r2, r4, 0
	ands r2, r3
	lsls r1, r2, 5
	subs r1, r2
	lsls r1, 2
	adds r1, r2
	lsls r1, 3
	lsrs r1, 16
	lsls r1, 16
	ands r5, r4
	orrs r5, r1
	str r5, [r0]
	pop {r4,r5}
	pop {r1}
	bx r1
	.align 2, 0
_080943D4: .4byte 0xffff0000
_080943D8: .4byte 0x0000ffff
	thumb_func_end sub_80943A8

	thumb_func_start sub_80943DC
sub_80943DC:
	push {r4-r6,lr}
	mov r6, r8
	push {r6}
	mov r8, r0
	adds r4, r1, 0
	lsls r1, r4, 16
	asrs r1, 16
	lsls r0, r1, 5
	subs r0, r1
	lsls r0, 2
	adds r0, r1
	lsls r0, 3
	asrs r1, r4, 16
	adds r0, r1
	lsls r3, r2, 16
	asrs r3, 16
	lsls r1, r3, 5
	subs r1, r3
	lsls r1, 2
	adds r1, r3
	lsls r1, 3
	asrs r2, 16
	adds r1, r2
	muls r0, r1
	movs r5, 0xFA
	lsls r5, 2
	adds r1, r5, 0
	bl __divsi3
	adds r6, r0, 0
	adds r1, r5, 0
	bl __divsi3
	lsls r0, 16
	lsrs r0, 16
	ldr r1, _08094448
	ands r4, r1
	orrs r4, r0
	adds r0, r6, 0
	adds r1, r5, 0
	bl __modsi3
	lsls r0, 16
	ldr r1, _0809444C
	ands r1, r4
	orrs r0, r1
	mov r1, r8
	str r0, [r1]
	mov r0, r8
	pop {r3}
	mov r8, r3
	pop {r4-r6}
	pop {r1}
	bx r1
	.align 2, 0
_08094448: .4byte 0xffff0000
_0809444C: .4byte 0x0000ffff
	thumb_func_end sub_80943DC

	thumb_func_start GetBellyRoundedUp
GetBellyRoundedUp:
	push {lr}
	adds r1, r0, 0
	lsls r0, r1, 16
	asrs r2, r0, 16
	cmp r2, 0
	bne _0809446A
	asrs r0, r1, 16
	cmp r0, 0
	bne _08094466
	movs r0, 0
	b _08094476
_08094466:
	movs r0, 0x1
	b _08094476
_0809446A:
	asrs r0, r1, 16
	cmp r0, 0
	bne _08094474
	adds r0, r2, 0
	b _08094476
_08094474:
	adds r0, r2, 0x1
_08094476:
	pop {r1}
	bx r1
	thumb_func_end GetBellyRoundedUp

	thumb_func_start sub_809447C
sub_809447C:
	push {r4,r5,lr}
	adds r5, r0, 0
	adds r4, r1, 0
	movs r2, 0x10
	bl RestoreIntegerBits
	adds r4, 0x2
	adds r0, r5, 0
	adds r1, r4, 0
	movs r2, 0x10
	bl RestoreIntegerBits
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_809447C

	thumb_func_start sub_809449C
sub_809449C:
	push {r4,r5,lr}
	adds r5, r0, 0
	adds r4, r1, 0
	movs r2, 0x10
	bl SaveIntegerBits
	adds r4, 0x2
	adds r0, r5, 0
	adds r1, r4, 0
	movs r2, 0x10
	bl SaveIntegerBits
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_809449C

	thumb_func_start sub_80944BC
sub_80944BC:
	push {r4,lr}
	sub sp, 0x8
	adds r4, r1, 0
	lsls r0, 16
	asrs r1, r0, 16
	ldr r0, _080944F4
	cmp r1, r0
	bgt _08094500
	lsls r1, 16
	lsrs r1, 16
	mov r0, sp
	bl sub_8092AA8
	ldr r0, _080944F8
	mov r1, sp
	movs r2, 0
	bl sub_80928C0
	ldr r0, _080944FC
	ldr r0, [r0]
	adds r2, r4, 0
	adds r2, 0xC8
	adds r1, r4, 0
	movs r3, 0
	bl xxx_format_string
	b _08094516
	.align 2, 0
_080944F4: .4byte 0x000001f3
_080944F8: .4byte gUnknown_202DE58
_080944FC: .4byte gUnknown_811383C
_08094500:
	ldr r0, _08094520
	ldr r2, _08094524
	adds r1, r2
	lsls r1, 3
	adds r0, 0x4
	adds r1, r0
	ldr r1, [r1]
	adds r0, r4, 0
	movs r2, 0xC8
	bl strncpy
_08094516:
	add sp, 0x8
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08094520: .4byte gUnknown_8113080
_08094524: .4byte 0xfffffe0c
	thumb_func_end sub_80944BC

	thumb_func_start sub_8094528
sub_8094528:
	push {lr}
	lsls r0, 16
	asrs r1, r0, 16
	ldr r0, _08094544
	cmp r1, r0
	ble _08094550
	ldr r0, _08094548
	ldr r2, _0809454C
	adds r1, r2
	lsls r1, 3
	adds r1, r0
	ldrb r0, [r1]
	b _08094552
	.align 2, 0
_08094544: .4byte 0x000001f3
_08094548: .4byte gUnknown_8113080
_0809454C: .4byte 0xfffffe0c
_08094550:
	movs r0, 0x1
_08094552:
	pop {r1}
	bx r1
	thumb_func_end sub_8094528

	thumb_func_start sub_8094558
sub_8094558:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0xCC
	adds r7, r0, 0
	adds r4, r1, 0
	adds r6, r2, 0
	bl sub_80073B8
	movs r5, 0
	str r5, [sp]
	movs r0, 0x10
	movs r1, 0
	adds r2, r4, 0
	adds r3, r7, 0
	bl xxx_format_and_draw
	ldr r4, _080945D0
	adds r1, r6, 0
	adds r1, 0x18
	adds r0, r4, 0
	bl sub_8090208
	ldr r0, _080945D4
	ldr r2, [r0]
	str r5, [sp]
	movs r0, 0x4
	movs r1, 0x10
	adds r3, r7, 0
	bl xxx_format_and_draw
	movs r5, 0x1A
	adds r0, r4, 0
	adds r1, r6, 0
	movs r2, 0xA
	bl sub_80922B4
	adds r4, 0x50
	adds r1, r6, 0
	adds r1, 0xA
	adds r0, r4, 0
	movs r2, 0xA
	bl sub_80922B4
	movs r1, 0x14
	ldrsh r0, [r6, r1]
	bl sub_8094528
	lsls r0, 24
	cmp r0, 0
	beq _080945DC
	ldr r0, _080945D8
	ldr r0, [r0]
	add r2, sp, 0xCC
	add r1, sp, 0x4
	movs r3, 0
	bl xxx_format_string
	b _080945EA
	.align 2, 0
_080945D0: .4byte gAvailablePokemonNames
_080945D4: .4byte gUnknown_8113850
_080945D8: .4byte gUnknown_8113868
_080945DC:
	ldr r0, _0809465C
	ldr r0, [r0]
	add r2, sp, 0xCC
	add r1, sp, 0x4
	movs r3, 0
	bl xxx_format_string
_080945EA:
	add r0, sp, 0x4
	bl sub_8008ED0
	movs r4, 0xB0
	subs r0, r4, r0
	lsrs r1, r0, 31
	adds r0, r1
	asrs r0, 1
	movs r1, 0
	mov r8, r1
	str r1, [sp]
	adds r1, r5, 0
	add r2, sp, 0x4
	adds r3, r7, 0
	bl xxx_format_and_draw
	adds r5, 0xA
	movs r1, 0x14
	ldrsh r0, [r6, r1]
	add r1, sp, 0x4
	bl sub_80944BC
	add r0, sp, 0x4
	bl sub_8008ED0
	subs r4, r0
	lsrs r0, r4, 31
	adds r4, r0
	asrs r0, r4, 1
	mov r1, r8
	str r1, [sp]
	adds r1, r5, 0
	add r2, sp, 0x4
	adds r3, r7, 0
	bl xxx_format_and_draw
	adds r5, 0x10
	ldr r1, _08094660
	ldr r0, [r6, 0x20]
	str r0, [r1]
	adds r0, r6, 0
	adds r0, 0x2A
	ldrb r0, [r0]
	str r0, [r1, 0x4]
	cmp r0, 0x63
	ble _08094668
	ldr r0, _08094664
	ldr r2, [r0]
	mov r0, r8
	str r0, [sp]
	movs r0, 0x4
	adds r1, r5, 0
	adds r3, r7, 0
	bl xxx_format_and_draw
	b _0809467A
	.align 2, 0
_0809465C: .4byte gUnknown_8113870
_08094660: .4byte gUnknown_202DE30
_08094664: .4byte gUnknown_81138C0
_08094668:
	ldr r0, _080946CC
	ldr r2, [r0]
	mov r1, r8
	str r1, [sp]
	movs r0, 0x4
	adds r1, r5, 0
	adds r3, r7, 0
	bl xxx_format_and_draw
_0809467A:
	adds r5, 0xA
	ldr r4, _080946D0
	movs r1, 0x24
	ldrsh r0, [r6, r1]
	str r0, [r4]
	ldr r0, _080946D4
	ldr r2, [r0]
	movs r0, 0
	mov r8, r0
	str r0, [sp]
	movs r0, 0x4
	adds r1, r5, 0
	adds r3, r7, 0
	bl xxx_format_and_draw
	adds r5, 0xA
	adds r0, r6, 0
	adds r0, 0x26
	ldrb r2, [r0]
	str r2, [r4]
	adds r0, 0x2
	ldrb r0, [r0]
	str r0, [r4, 0x4]
	adds r0, r6, 0
	adds r0, 0x2B
	ldrb r1, [r0]
	cmp r1, 0
	beq _080946DC
	adds r0, r1, 0
	adds r0, r2, r0
	str r0, [r4]
	ldr r0, _080946D8
	ldr r2, [r0]
	mov r1, r8
	str r1, [sp]
	movs r0, 0x4
	adds r1, r5, 0
	adds r3, r7, 0
	bl xxx_format_and_draw
	b _080946EC
	.align 2, 0
_080946CC: .4byte gUnknown_8113898
_080946D0: .4byte gUnknown_202DE30
_080946D4: .4byte gUnknown_81138D0
_080946D8: .4byte gUnknown_8113950
_080946DC:
	ldr r0, _08094714
	ldr r2, [r0]
	str r1, [sp]
	movs r0, 0x4
	adds r1, r5, 0
	adds r3, r7, 0
	bl xxx_format_and_draw
_080946EC:
	adds r0, r6, 0
	adds r0, 0x2D
	ldrb r1, [r0]
	cmp r1, 0
	beq _08094720
	ldr r2, _08094718
	ldr r0, [r2, 0x4]
	adds r0, r1
	str r0, [r2, 0x4]
	ldr r0, _0809471C
	ldr r2, [r0]
	movs r0, 0
	str r0, [sp]
	movs r0, 0x4
	adds r1, r5, 0
	adds r3, r7, 0
	bl xxx_format_and_draw
	b _08094730
	.align 2, 0
_08094714: .4byte gUnknown_81138E4
_08094718: .4byte gUnknown_202DE30
_0809471C: .4byte gUnknown_8113974
_08094720:
	ldr r0, _08094768
	ldr r2, [r0]
	str r1, [sp]
	movs r0, 0x4
	adds r1, r5, 0
	adds r3, r7, 0
	bl xxx_format_and_draw
_08094730:
	adds r5, 0xA
	ldr r2, _0809476C
	adds r0, r6, 0
	adds r0, 0x27
	ldrb r3, [r0]
	str r3, [r2]
	adds r0, 0x2
	ldrb r0, [r0]
	str r0, [r2, 0x4]
	adds r0, r6, 0
	adds r0, 0x2C
	ldrb r1, [r0]
	cmp r1, 0
	beq _08094774
	adds r0, r1, 0
	adds r0, r3, r0
	str r0, [r2]
	ldr r0, _08094770
	ldr r2, [r0]
	movs r0, 0
	str r0, [sp]
	movs r0, 0x4
	adds r1, r5, 0
	adds r3, r7, 0
	bl xxx_format_and_draw
	b _08094784
	.align 2, 0
_08094768: .4byte gUnknown_8113900
_0809476C: .4byte gUnknown_202DE30
_08094770: .4byte gUnknown_8113990
_08094774:
	ldr r0, _080947AC
	ldr r2, [r0]
	str r1, [sp]
	movs r0, 0x4
	adds r1, r5, 0
	adds r3, r7, 0
	bl xxx_format_and_draw
_08094784:
	adds r0, r6, 0
	adds r0, 0x2E
	ldrb r1, [r0]
	cmp r1, 0
	beq _080947B8
	ldr r2, _080947B0
	ldr r0, [r2, 0x4]
	adds r0, r1
	str r0, [r2, 0x4]
	ldr r0, _080947B4
	ldr r2, [r0]
	movs r0, 0
	str r0, [sp]
	movs r0, 0x4
	adds r1, r5, 0
	adds r3, r7, 0
	bl xxx_format_and_draw
	b _080947C8
	.align 2, 0
_080947AC: .4byte gUnknown_8113918
_080947B0: .4byte gUnknown_202DE30
_080947B4: .4byte gUnknown_81139B4
_080947B8:
	ldr r0, _080947E4
	ldr r2, [r0]
	str r1, [sp]
	movs r0, 0x4
	adds r1, r5, 0
	adds r3, r7, 0
	bl xxx_format_and_draw
_080947C8:
	adds r5, 0x10
	adds r2, r6, 0
	adds r2, 0x1C
	ldrb r1, [r6, 0x1C]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _080947EC
	ldr r0, _080947E8
	adds r1, r2, 0
	movs r2, 0
	bl sub_8090E14
	b _080947F6
	.align 2, 0
_080947E4: .4byte gUnknown_8113934
_080947E8: .4byte gUnknown_202DE58
_080947EC:
	ldr r0, _0809481C
	ldr r1, _08094820
	ldr r1, [r1]
	bl strcpy
_080947F6:
	ldr r0, _08094824
	ldr r2, [r0]
	movs r0, 0
	str r0, [sp]
	movs r0, 0x4
	adds r1, r5, 0
	adds r3, r7, 0
	bl xxx_format_and_draw
	adds r0, r7, 0
	bl sub_80073E0
	add sp, 0xCC
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_0809481C: .4byte gUnknown_202DE58
_08094820: .4byte gUnknown_81139B8
_08094824: .4byte gUnknown_81139CC
	thumb_func_end sub_8094558

        .align 2,0
