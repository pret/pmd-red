        .include "constants/gba_constants.inc"
	.include "asm/macros.inc"

	.syntax unified

	.text	

	thumb_func_start sub_802A50C
sub_802A50C:
	push {r4,r5,lr}
	sub sp, 0x44
	bl sub_80154F0
	adds r4, r0, 0
	add r0, sp, 0x14
	movs r1, 0
	movs r2, 0x30
	bl MemoryFill8
	cmp r4, 0x2
	bne _0802A526
	b _0802A660
_0802A526:
	cmp r4, 0x3
	beq _0802A52C
	b _0802A680
_0802A52C:
	ldr r0, _0802A54C
	ldr r1, [r0]
	adds r1, 0x8
	movs r0, 0x20
	add r2, sp, 0x14
	bl sub_8039068
	subs r0, 0x7
	cmp r0, 0x11
	bls _0802A542
	b _0802A654
_0802A542:
	lsls r0, 2
	ldr r1, _0802A550
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0802A54C: .4byte gUnknown_203B2C4
_0802A550: .4byte _0802A554
	.align 2, 0
_0802A554:
	.4byte _0802A654
	.4byte _0802A654
	.4byte _0802A654
	.4byte _0802A654
	.4byte _0802A5F0
	.4byte _0802A654
	.4byte _0802A654
	.4byte _0802A654
	.4byte _0802A654
	.4byte _0802A654
	.4byte _0802A59C
	.4byte _0802A654
	.4byte _0802A654
	.4byte _0802A5D8
	.4byte _0802A654
	.4byte _0802A654
	.4byte _0802A654
	.4byte _0802A618
_0802A59C:
	ldr r0, _0802A5CC
	ldr r3, _0802A5D0
	movs r2, 0
	str r2, [sp]
	movs r1, 0x4
	str r1, [sp, 0x4]
	str r2, [sp, 0x8]
	ldr r1, _0802A5D4
	ldr r1, [r1]
	movs r2, 0x84
	lsls r2, 3
	adds r1, r2
	str r1, [sp, 0xC]
	movs r1, 0xC
	str r1, [sp, 0x10]
	movs r1, 0
	movs r2, 0x7
	bl sub_8014248
	movs r0, 0x28
	bl sub_802B2BC
	b _0802A654
	.align 2, 0
_0802A5CC: .4byte gUnknown_80DF1C0
_0802A5D0: .4byte gUnknown_80DEE44
_0802A5D4: .4byte gUnknown_203B2C4
_0802A5D8:
	ldr r0, _0802A5E8
	ldr r1, _0802A5EC
	ldr r2, [r1]
	movs r3, 0x84
	lsls r3, 3
	adds r2, r3
	b _0802A5FC
	.align 2, 0
_0802A5E8: .4byte gUnknown_80DF208
_0802A5EC: .4byte gUnknown_203B2C4
_0802A5F0:
	ldr r0, _0802A60C
	ldr r1, _0802A610
	ldr r2, [r1]
	movs r4, 0x84
	lsls r4, 3
	adds r2, r4
_0802A5FC:
	ldr r3, _0802A614
	movs r1, 0
	bl sub_80141B4
	movs r0, 0x1F
	bl sub_802B2BC
	b _0802A654
	.align 2, 0
_0802A60C: .4byte gUnknown_80DF0A0
_0802A610: .4byte gUnknown_203B2C4
_0802A614: .4byte 0x0000010d
_0802A618:
	ldr r1, [sp, 0x24]
	movs r0, 0x4
	bl sub_809539C
	lsls r0, 24
	lsrs r0, 24
	bl sub_8095228
	adds r2, r0, 0
	add r1, sp, 0x14
	ldm r1!, {r3-r5}
	stm r2!, {r3-r5}
	ldm r1!, {r3-r5}
	stm r2!, {r3-r5}
	ldm r1!, {r3-r5}
	stm r2!, {r3-r5}
	ldm r1!, {r3-r5}
	stm r2!, {r3-r5}
	movs r1, 0x6
	strb r1, [r0]
	ldr r0, _0802A65C
	ldr r0, [r0]
	movs r5, 0x86
	lsls r5, 3
	adds r0, r5
	ldr r1, [sp, 0x24]
	str r1, [r0]
	movs r0, 0x21
	bl sub_802B2BC
_0802A654:
	bl sub_80155F0
	b _0802A680
	.align 2, 0
_0802A65C: .4byte gUnknown_203B2C4
_0802A660:
	bl sub_80155F0
	bl ResetUnusedInputStruct
	ldr r0, _0802A688
	ldr r0, [r0]
	movs r1, 0xEF
	lsls r1, 2
	adds r0, r1
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	movs r0, 0x1
	bl sub_802B2BC
_0802A680:
	add sp, 0x44
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_0802A688: .4byte gUnknown_203B2C4
	thumb_func_end sub_802A50C

	thumb_func_start sub_802A68C
sub_802A68C:
	push {lr}
	sub sp, 0x4
	mov r0, sp
	bl sub_80144A4
	cmp r0, 0
	bne _0802A6AE
	bl sub_8012600
	lsls r0, 24
	cmp r0, 0
	bne _0802A6AE
	bl sub_8012750
	movs r0, 0xD
	bl sub_802B2BC
_0802A6AE:
	add sp, 0x4
	pop {r0}
	bx r0
	thumb_func_end sub_802A68C

	thumb_func_start sub_802A6B4
sub_802A6B4:
	push {r4,lr}
	sub sp, 0x4
	mov r0, sp
	bl sub_80144A4
	cmp r0, 0
	bne _0802A6E8
	bl sub_8012600
	lsls r0, 24
	cmp r0, 0
	bne _0802A6E8
	bl sub_8012744
	adds r4, r0, 0
	bl sub_8012750
	cmp r4, 0
	bne _0802A6E2
	movs r0, 0x20
	bl sub_802B2BC
	b _0802A6E8
_0802A6E2:
	movs r0, 0x3
	bl sub_802B2BC
_0802A6E8:
	add sp, 0x4
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_802A6B4

	thumb_func_start sub_802A6F0
sub_802A6F0:
	push {lr}
	sub sp, 0x4
	mov r0, sp
	bl sub_80144A4
	cmp r0, 0
	bne _0802A710
	movs r0, 0x18
	bl sub_802B2BC
	movs r0, 0x1
	bl sub_8011C28
	movs r0, 0
	bl sub_8012574
_0802A710:
	add sp, 0x4
	pop {r0}
	bx r0
	thumb_func_end sub_802A6F0

	thumb_func_start sub_802A718
sub_802A718:
	push {lr}
	sub sp, 0x4
	mov r0, sp
	bl sub_80144A4
	cmp r0, 0
	bne _0802A738
	movs r0, 0x25
	bl sub_802B2BC
	movs r0, 0x1
	bl sub_8011C28
	movs r0, 0
	bl sub_8012574
_0802A738:
	add sp, 0x4
	pop {r0}
	bx r0
	thumb_func_end sub_802A718

	thumb_func_start sub_802A740
sub_802A740:
	push {lr}
	sub sp, 0x4
	mov r0, sp
	bl sub_80144A4
	cmp r0, 0
	bne _0802A754
	movs r0, 0x1E
	bl sub_802B2BC
_0802A754:
	add sp, 0x4
	pop {r0}
	bx r0
	thumb_func_end sub_802A740

	thumb_func_start sub_802A75C
sub_802A75C:
	push {lr}
	sub sp, 0x4
	mov r0, sp
	bl sub_80144A4
	cmp r0, 0
	bne _0802A792
	ldr r0, [sp]
	cmp r0, 0
	beq _0802A78C
	cmp r0, 0x7
	bne _0802A792
	ldr r0, _0802A788
	ldr r0, [r0]
	movs r1, 0xA7
	lsls r1, 3
	adds r0, r1
	ldr r0, [r0]
	movs r0, 0x16
	bl sub_802B2BC
	b _0802A792
	.align 2, 0
_0802A788: .4byte gUnknown_203B2C4
_0802A78C:
	movs r0, 0x1
	bl sub_802B2BC
_0802A792:
	add sp, 0x4
	pop {r0}
	bx r0
	thumb_func_end sub_802A75C

	thumb_func_start sub_802A798
sub_802A798:
	push {r4,r5,lr}
	sub sp, 0x4
	mov r0, sp
	bl sub_80144A4
	cmp r0, 0
	bne _0802A81E
	ldr r0, [sp]
	cmp r0, 0x7
	beq _0802A7BC
	cmp r0, 0x7
	bgt _0802A7B6
	cmp r0, 0
	beq _0802A818
	b _0802A81E
_0802A7B6:
	cmp r0, 0x8
	beq _0802A810
	b _0802A81E
_0802A7BC:
	ldr r4, _0802A800
	ldr r0, [r4]
	movs r1, 0x86
	lsls r1, 2
	adds r0, r1
	ldrb r0, [r0]
	bl sub_8095228
	adds r2, r0, 0
	ldr r1, [r4]
	ldr r3, _0802A804
	adds r0, r1, r3
	ldrb r0, [r0]
	cmp r0, 0
	beq _0802A7E2
	ldr r5, _0802A808
	adds r0, r1, r5
	ldr r0, [r0]
	str r0, [r2, 0x20]
_0802A7E2:
	ldr r0, _0802A80C
	ldr r1, [r0]
	ldr r0, [r4]
	adds r0, r3
	ldrb r0, [r0]
	lsls r0, 1
	adds r1, 0x50
	adds r1, r0
	ldrh r0, [r1]
	subs r0, 0x1
	strh r0, [r1]
	movs r0, 0x29
	bl sub_802B2BC
	b _0802A81E
	.align 2, 0
_0802A800: .4byte gUnknown_203B2C4
_0802A804: .4byte 0x0000041e
_0802A808: .4byte 0x0000041c
_0802A80C: .4byte gUnknown_203B460
_0802A810:
	movs r0, 0xB
	bl sub_802B2BC
	b _0802A81E
_0802A818:
	movs r0, 0x1
	bl sub_802B2BC
_0802A81E:
	add sp, 0x4
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_802A798

	thumb_func_start sub_802A828
sub_802A828:
	push {lr}
	sub sp, 0x4
	mov r0, sp
	bl sub_80144A4
	cmp r0, 0
	bne _0802A848
	movs r0, 0x2A
	bl sub_802B2BC
	movs r0, 0x1
	bl sub_8011C28
	movs r0, 0
	bl sub_8012574
_0802A848:
	add sp, 0x4
	pop {r0}
	bx r0
	thumb_func_end sub_802A828

	thumb_func_start sub_802A850
sub_802A850:
	push {lr}
	sub sp, 0x4
	mov r0, sp
	bl sub_80144A4
	cmp r0, 0
	bne _0802A89A
	bl sub_8012600
	lsls r0, 24
	cmp r0, 0
	bne _0802A89A
	bl sub_8012750
	ldr r0, _0802A884
	ldr r0, [r0]
	ldr r1, _0802A888
	adds r0, r1
	ldr r0, [r0]
	cmp r0, 0x3
	blt _0802A89A
	cmp r0, 0x4
	ble _0802A88C
	cmp r0, 0x5
	beq _0802A894
	b _0802A89A
	.align 2, 0
_0802A884: .4byte gUnknown_203B2C4
_0802A888: .4byte 0x00000534
_0802A88C:
	movs r0, 0x1D
	bl sub_802B2BC
	b _0802A89A
_0802A894:
	movs r0, 0x19
	bl sub_802B2BC
_0802A89A:
	add sp, 0x4
	pop {r0}
	bx r0
	thumb_func_end sub_802A850

	thumb_func_start sub_802A8A0
sub_802A8A0:
	push {lr}
	sub sp, 0x4
	mov r0, sp
	bl sub_80144A4
	cmp r0, 0
	bne _0802A8B4
	movs r0, 0x13
	bl sub_802B2BC
_0802A8B4:
	add sp, 0x4
	pop {r0}
	bx r0
	thumb_func_end sub_802A8A0

	thumb_func_start sub_802A8BC
sub_802A8BC:
	push {lr}
	sub sp, 0x4
	mov r0, sp
	bl sub_80144A4
	cmp r0, 0
	bne _0802A90A
	ldr r0, [sp]
	cmp r0, 0
	beq _0802A904
	cmp r0, 0xA
	bne _0802A90A
	ldr r0, _0802A8EC
	ldr r0, [r0]
	ldr r1, _0802A8F0
	adds r0, r1
	ldr r0, [r0]
	cmp r0, 0x3
	blt _0802A90A
	cmp r0, 0x4
	ble _0802A8F4
	cmp r0, 0x5
	beq _0802A8FC
	b _0802A90A
	.align 2, 0
_0802A8EC: .4byte gUnknown_203B2C4
_0802A8F0: .4byte 0x00000534
_0802A8F4:
	movs r0, 0x1D
	bl sub_802B2BC
	b _0802A90A
_0802A8FC:
	movs r0, 0x19
	bl sub_802B2BC
	b _0802A90A
_0802A904:
	movs r0, 0x1
	bl sub_802B2BC
_0802A90A:
	add sp, 0x4
	pop {r0}
	bx r0
	thumb_func_end sub_802A8BC

	thumb_func_start sub_802A910
sub_802A910:
	push {lr}
	sub sp, 0x4
	mov r0, sp
	bl sub_80144A4
	cmp r0, 0
	bne _0802A986
	ldr r0, [sp]
	cmp r0, 0x9
	beq _0802A934
	cmp r0, 0x9
	bgt _0802A92E
	cmp r0, 0
	beq _0802A980
	b _0802A986
_0802A92E:
	cmp r0, 0xA
	beq _0802A950
	b _0802A986
_0802A934:
	movs r0, 0
	bl sub_801CF14
	lsls r0, 24
	cmp r0, 0
	beq _0802A948
	movs r0, 0xA
	bl sub_802B2BC
	b _0802A986
_0802A948:
	movs r0, 0xB
	bl sub_802B2BC
	b _0802A986
_0802A950:
	ldr r0, _0802A968
	ldr r0, [r0]
	ldr r1, _0802A96C
	adds r0, r1
	ldr r0, [r0]
	cmp r0, 0x3
	blt _0802A986
	cmp r0, 0x4
	ble _0802A970
	cmp r0, 0x5
	beq _0802A978
	b _0802A986
	.align 2, 0
_0802A968: .4byte gUnknown_203B2C4
_0802A96C: .4byte 0x00000534
_0802A970:
	movs r0, 0x1D
	bl sub_802B2BC
	b _0802A986
_0802A978:
	movs r0, 0x19
	bl sub_802B2BC
	b _0802A986
_0802A980:
	movs r0, 0x1
	bl sub_802B2BC
_0802A986:
	add sp, 0x4
	pop {r0}
	bx r0
	thumb_func_end sub_802A910

	thumb_func_start sub_802A98C
sub_802A98C:
	push {lr}
	sub sp, 0x4
	mov r0, sp
	bl sub_80144A4
	cmp r0, 0
	bne _0802A9A0
	movs r0, 0x8
	bl sub_802B2BC
_0802A9A0:
	add sp, 0x4
	pop {r0}
	bx r0
	thumb_func_end sub_802A98C

	thumb_func_start sub_802A9A8
sub_802A9A8:
	push {lr}
	sub sp, 0x4
	mov r0, sp
	bl sub_80144A4
	cmp r0, 0
	bne _0802A9F6
	ldr r0, [sp]
	cmp r0, 0
	beq _0802A9F0
	cmp r0, 0x7
	bne _0802A9F6
	ldr r0, _0802A9D8
	ldr r0, [r0]
	ldr r1, _0802A9DC
	adds r0, r1
	ldr r0, [r0]
	cmp r0, 0x3
	blt _0802A9F6
	cmp r0, 0x4
	ble _0802A9E0
	cmp r0, 0x5
	beq _0802A9E8
	b _0802A9F6
	.align 2, 0
_0802A9D8: .4byte gUnknown_203B2C4
_0802A9DC: .4byte 0x00000534
_0802A9E0:
	movs r0, 0x1D
	bl sub_802B2BC
	b _0802A9F6
_0802A9E8:
	movs r0, 0x19
	bl sub_802B2BC
	b _0802A9F6
_0802A9F0:
	movs r0, 0x1
	bl sub_802B2BC
_0802A9F6:
	add sp, 0x4
	pop {r0}
	bx r0
	thumb_func_end sub_802A9A8

	thumb_func_start sub_802A9FC
sub_802A9FC:
	push {lr}
	sub sp, 0x4
	mov r0, sp
	bl sub_80144A4
	cmp r0, 0
	bne _0802AA22
	ldr r0, [sp]
	cmp r0, 0
	beq _0802AA1C
	cmp r0, 0x7
	bne _0802AA22
	movs r0, 0x26
	bl sub_802B2BC
	b _0802AA22
_0802AA1C:
	movs r0, 0x1
	bl sub_802B2BC
_0802AA22:
	add sp, 0x4
	pop {r0}
	bx r0
	thumb_func_end sub_802A9FC

	thumb_func_start sub_802AA28
sub_802AA28:
	push {lr}
	sub sp, 0x4
	mov r0, sp
	bl sub_80144A4
	cmp r0, 0
	bne _0802AAA6
	ldr r2, [sp]
	cmp r2, 0
	beq _0802AAA0
	cmp r2, 0
	blt _0802AAA6
	cmp r2, 0x5
	bgt _0802AAA6
	cmp r2, 0x3
	blt _0802AAA6
	ldr r0, _0802AA7C
	ldr r0, [r0]
	ldr r3, _0802AA80
	adds r1, r0, r3
	str r2, [r1]
	movs r1, 0xA7
	lsls r1, 3
	adds r0, r1
	ldr r0, [r0]
	cmp r0, 0x1
	bne _0802AA8C
	movs r0, 0x5
	bl sub_80953D4
	lsls r0, 24
	lsrs r0, 24
	bl sub_8095228
	adds r0, 0x22
	ldrb r0, [r0]
	cmp r0, 0
	beq _0802AA84
	movs r0, 0x7
	bl sub_802B2BC
	b _0802AAA6
	.align 2, 0
_0802AA7C: .4byte gUnknown_203B2C4
_0802AA80: .4byte 0x00000534
_0802AA84:
	movs r0, 0x9
	bl sub_802B2BC
	b _0802AAA6
_0802AA8C:
	cmp r2, 0x5
	bne _0802AA98
	movs r0, 0x26
	bl sub_802B2BC
	b _0802AAA6
_0802AA98:
	movs r0, 0x1D
	bl sub_802B2BC
	b _0802AAA6
_0802AAA0:
	movs r0, 0x1
	bl sub_802B2BC
_0802AAA6:
	add sp, 0x4
	pop {r0}
	bx r0
	thumb_func_end sub_802AA28

	thumb_func_start sub_802AAAC
sub_802AAAC:
	push {lr}
	sub sp, 0x4
	mov r0, sp
	bl sub_80144A4
	cmp r0, 0
	bne _0802AAC0
	movs r0, 0x1
	bl sub_802B2BC
_0802AAC0:
	add sp, 0x4
	pop {r0}
	bx r0
	thumb_func_end sub_802AAAC

	thumb_func_start sub_802AAC8
sub_802AAC8:
	push {lr}
	sub sp, 0x4
	mov r0, sp
	bl sub_80144A4
	cmp r0, 0
	bne _0802AADC
	movs r0, 0x3
	bl sub_802B2BC
_0802AADC:
	add sp, 0x4
	pop {r0}
	bx r0
	thumb_func_end sub_802AAC8

	thumb_func_start sub_802AAE4
sub_802AAE4:
	push {lr}
	sub sp, 0x4
	mov r0, sp
	bl sub_80144A4
	cmp r0, 0
	bne _0802AB5A
	ldr r2, [sp]
	cmp r2, 0x1
	beq _0802AB08
	cmp r2, 0x1
	bgt _0802AB02
	cmp r2, 0
	beq _0802AB54
	b _0802AB5A
_0802AB02:
	cmp r2, 0x2
	beq _0802AB38
	b _0802AB5A
_0802AB08:
	ldr r0, _0802AB2C
	ldr r0, [r0]
	movs r1, 0x6
	str r1, [r0, 0x40]
	movs r1, 0xA7
	lsls r1, 3
	adds r0, r1
	str r2, [r0]
	movs r0, 0x5
	bl sub_8095324
	cmp r0, 0
	bne _0802AB30
	movs r0, 0x4
	bl sub_802B2BC
	b _0802AB5A
	.align 2, 0
_0802AB2C: .4byte gUnknown_203B2C4
_0802AB30:
	movs r0, 0xF
	bl sub_802B2BC
	b _0802AB5A
_0802AB38:
	ldr r0, _0802AB50
	ldr r0, [r0]
	movs r1, 0x7
	str r1, [r0, 0x40]
	movs r1, 0xA7
	lsls r1, 3
	adds r0, r1
	str r2, [r0]
	movs r0, 0x6
	bl sub_802B2BC
	b _0802AB5A
	.align 2, 0
_0802AB50: .4byte gUnknown_203B2C4
_0802AB54:
	movs r0, 0x2
	bl sub_802B2BC
_0802AB5A:
	add sp, 0x4
	pop {r0}
	bx r0
	thumb_func_end sub_802AAE4

	thumb_func_start sub_802AB60
sub_802AB60:
	push {lr}
	sub sp, 0x4
	mov r0, sp
	bl sub_80144A4
	cmp r0, 0
	bne _0802AB74
	movs r0, 0x22
	bl sub_802B2BC
_0802AB74:
	add sp, 0x4
	pop {r0}
	bx r0
	thumb_func_end sub_802AB60

	thumb_func_start sub_802AB7C
sub_802AB7C:
	push {lr}
	sub sp, 0x4
	mov r0, sp
	bl sub_80144A4
	cmp r0, 0
	bne _0802AB90
	movs r0, 0x22
	bl sub_802B2BC
_0802AB90:
	add sp, 0x4
	pop {r0}
	bx r0
	thumb_func_end sub_802AB7C

	thumb_func_start sub_802AB98
sub_802AB98:
	push {r4,lr}
	bl sub_802F298
	cmp r0, 0x3
	bne _0802ABE0
	bl sub_802F2C0
	ldr r0, _0802ABE8
	movs r4, 0x98
	lsls r4, 1
	adds r1, r4, 0
	bl sub_808D8E0
	adds r0, r4, 0
	bl GetMonSpecies
	adds r1, r0, 0
	ldr r0, _0802ABEC
	bl strcpy
	ldr r0, _0802ABF0
	ldr r0, [r0]
	movs r1, 0x86
	lsls r1, 3
	adds r0, r1
	ldr r1, [r0]
	movs r0, 0x6
	bl sub_809539C
	lsls r0, 24
	lsrs r0, 24
	bl sub_8095240
	movs r0, 0x24
	bl sub_802B2BC
_0802ABE0:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0802ABE8: .4byte gUnknown_202E5D8
_0802ABEC: .4byte gAvailablePokemonNames
_0802ABF0: .4byte gUnknown_203B2C4
	thumb_func_end sub_802AB98

	thumb_func_start nullsub_131
nullsub_131:
	bx lr
	thumb_func_end nullsub_131

	thumb_func_start sub_802ABF8
sub_802ABF8:
	push {r4-r6,lr}
	sub sp, 0xB8
	ldr r1, _0802AC14
	ldr r0, [r1]
	ldrb r0, [r0]
	adds r6, r1, 0
	cmp r0, 0x2A
	bls _0802AC0A
	b _0802B2AA
_0802AC0A:
	lsls r0, 2
	ldr r1, _0802AC18
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0802AC14: .4byte gUnknown_203B2C4
_0802AC18: .4byte _0802AC1C
	.align 2, 0
_0802AC1C:
	.4byte _0802B1DC
	.4byte _0802B1FC
	.4byte _0802B22C
	.4byte _0802B2AA
	.4byte _0802B1D4
	.4byte _0802ACC8
	.4byte _0802B248
	.4byte _0802B194
	.4byte _0802B1A4
	.4byte _0802B168
	.4byte _0802B138
	.4byte _0802B128
	.4byte _0802B0F0
	.4byte _0802B0AC
	.4byte _0802AD08
	.4byte _0802AD18
	.4byte _0802AD20
	.4byte _0802AD46
	.4byte _0802B2AA
	.4byte _0802AD80
	.4byte _0802ADB0
	.4byte _0802B2AA
	.4byte _0802B07C
	.4byte _0802B094
	.4byte _0802B2AA
	.4byte _0802AF50
	.4byte _0802AF1A
	.4byte _0802AF46
	.4byte _0802B2AA
	.4byte _0802B0A4
	.4byte _0802ADF8
	.4byte _0802B2AA
	.4byte _0802AF70
	.4byte _0802AF78
	.4byte _0802AFAC
	.4byte _0802B2AA
	.4byte _0802AF60
	.4byte _0802B2AA
	.4byte _0802AEEC
	.4byte _0802AEF4
	.4byte _0802B2AA
	.4byte _0802B110
	.4byte _0802B120
_0802ACC8:
	bl sub_808D33C
	adds r1, r0, 0
	adds r1, 0x4C
	add r0, sp, 0x14
	movs r2, 0xA
	bl sub_80922B4
	ldr r5, _0802ACF8
	ldr r0, [r5]
	ldr r4, _0802ACFC
	adds r0, r4
	ldr r1, _0802AD00
	add r2, sp, 0x14
	bl sub_800D158
	ldr r2, [r5]
	adds r4, r2, r4
	movs r0, 0x84
	lsls r0, 3
	adds r2, r0
	ldr r3, _0802AD04
	adds r0, r4, 0
	b _0802B238
	.align 2, 0
_0802ACF8: .4byte gUnknown_203B2C4
_0802ACFC: .4byte 0x00000434
_0802AD00: .4byte gUnknown_80DF250
_0802AD04: .4byte 0x0000010d
_0802AD08:
	ldr r0, _0802AD10
	ldr r3, _0802AD14
	b _0802B1A8
	.align 2, 0
_0802AD10: .4byte gUnknown_80DF304
_0802AD14: .4byte gUnknown_80DEE60
_0802AD18:
	ldr r0, _0802AD1C
	b _0802B22E
	.align 2, 0
_0802AD1C: .4byte gUnknown_80DF330
_0802AD20:
	bl sub_8030894
	cmp r0, 0
	beq _0802AD2A
	b _0802B2AA
_0802AD2A:
	bl ResetUnusedInputStruct
	movs r0, 0
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	movs r0, 0x5
	movs r1, 0
	movs r2, 0
	movs r3, 0x6
	bl sub_80306A8
	b _0802B2AA
_0802AD46:
	ldr r0, [r6]
	movs r4, 0xD7
	lsls r4, 2
	adds r0, r4
	bl sub_8006518
	ldr r1, [r6]
	movs r5, 0x87
	lsls r5, 2
	adds r0, r1, r5
	adds r1, r4
	ldr r3, _0802AD78
	ldr r2, _0802AD7C
	str r2, [sp]
	movs r2, 0x1
	str r2, [sp, 0x4]
	movs r2, 0
	str r2, [sp, 0x8]
	str r2, [sp, 0xC]
	movs r2, 0x3
	bl SetMenuItems
	bl sub_803092C
	b _0802ADE0
	.align 2, 0
_0802AD78: .4byte gUnknown_80DED60
_0802AD7C: .4byte gUnknown_80DED78
_0802AD80:
	bl sub_801D008
	cmp r0, 0
	beq _0802AD8A
	b _0802B2AA
_0802AD8A:
	bl ResetUnusedInputStruct
	movs r0, 0
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	add r2, sp, 0xB4
	ldr r0, _0802ADAC
	str r0, [r2]
	movs r0, 0
	movs r1, 0x1
	movs r3, 0x9
	bl sub_801C8C4
	b _0802B2AA
	.align 2, 0
_0802ADAC: .4byte 0x00020003
_0802ADB0:
	ldr r0, [r6]
	movs r4, 0xD7
	lsls r4, 2
	adds r0, r4
	bl sub_8006518
	ldr r1, [r6]
	movs r5, 0x87
	lsls r5, 2
	adds r0, r1, r5
	adds r1, r4
	ldr r3, _0802ADF0
	ldr r2, _0802ADF4
	str r2, [sp]
	movs r2, 0x1
	str r2, [sp, 0x4]
	movs r2, 0
	str r2, [sp, 0x8]
	str r2, [sp, 0xC]
	movs r2, 0x3
	bl SetMenuItems
	bl sub_801CCD8
_0802ADE0:
	ldr r0, [r6]
	adds r0, r5
	movs r1, 0x3
	movs r2, 0x1
	bl sub_8035CF4
	b _0802B2AA
	.align 2, 0
_0802ADF0: .4byte gUnknown_80DED48
_0802ADF4: .4byte gUnknown_80DED78
_0802ADF8:
	ldr r1, [r6]
	movs r0, 0
	str r0, [r1, 0x44]
	bl sub_8011830
	ldr r0, [r6]
	ldr r0, [r0, 0x40]
	bl sub_8037B28
	ldr r1, [r6]
	str r0, [r1, 0x44]
	cmp r0, 0
	bne _0802AEE6
	ldr r0, [r1, 0x40]
	cmp r0, 0x6
	beq _0802AE1E
	cmp r0, 0x7
	beq _0802AE5C
	b _0802AE8C
_0802AE1E:
	movs r4, 0xDC
	lsls r4, 1
	adds r0, r1, r4
	movs r1, 0
	movs r2, 0x30
	bl MemoryFill8
	ldr r0, [r6]
	movs r5, 0x86
	lsls r5, 2
	adds r0, r5
	ldrb r0, [r0]
	bl sub_8095228
	ldr r1, [r6]
	adds r1, r4
	ldm r0!, {r2,r3,r5}
	stm r1!, {r2,r3,r5}
	ldm r0!, {r2,r3,r5}
	stm r1!, {r2,r3,r5}
	ldm r0!, {r2,r3,r5}
	stm r1!, {r2,r3,r5}
	ldm r0!, {r2,r3,r5}
	stm r1!, {r2,r3,r5}
	ldr r2, [r6]
	ldr r0, [r2, 0x40]
	adds r4, r2, r4
	movs r1, 0xF4
	lsls r1, 1
	adds r2, r1
	b _0802AE82
_0802AE5C:
	movs r4, 0xDC
	lsls r4, 1
	adds r0, r1, r4
	movs r1, 0
	movs r2, 0x30
	bl MemoryFill8
	ldr r0, [r6]
	movs r5, 0xF4
	lsls r5, 1
	adds r0, r5
	movs r1, 0
	movs r2, 0x30
	bl MemoryFill8
	ldr r2, [r6]
	ldr r0, [r2, 0x40]
	adds r4, r2, r4
	adds r2, r5
_0802AE82:
	adds r1, r4, 0
	bl sub_8037D64
	ldr r1, [r6]
	str r0, [r1, 0x44]
_0802AE8C:
	ldr r4, _0802AED0
	ldr r2, [r4]
	ldr r0, [r2, 0x44]
	cmp r0, 0
	bne _0802AEE6
	ldr r0, [r2, 0x40]
	cmp r0, 0x7
	bhi _0802AEE6
	cmp r0, 0x6
	bcc _0802AEE6
	movs r3, 0xDC
	lsls r3, 1
	adds r1, r2, r3
	movs r5, 0xF4
	lsls r5, 1
	adds r2, r5
	bl sub_80381F4
	ldr r1, [r4]
	str r0, [r1, 0x44]
	bl sub_800D588
	lsls r0, 24
	cmp r0, 0
	beq _0802AED4
	ldr r0, [r4]
	movs r2, 0x86
	lsls r2, 3
	adds r1, r0, r2
	movs r3, 0xFC
	lsls r3, 1
	adds r0, r3
	b _0802AEE2
	.align 2, 0
_0802AED0: .4byte gUnknown_203B2C4
_0802AED4:
	ldr r0, [r4]
	movs r5, 0x86
	lsls r5, 3
	adds r1, r0, r5
	movs r2, 0xE4
	lsls r2, 1
	adds r0, r2
_0802AEE2:
	ldr r0, [r0]
	str r0, [r1]
_0802AEE6:
	bl xxx_call_start_bg_music
	b _0802B2AA
_0802AEEC:
	ldr r0, _0802AEF0
	b _0802B22E
	.align 2, 0
_0802AEF0: .4byte gUnknown_80DF380
_0802AEF4:
	ldr r0, [r6]
	movs r5, 0xEF
	lsls r5, 2
	adds r0, r5
	bl sub_8006518
	bl ResetUnusedInputStruct
	movs r0, 0
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	ldr r1, [r6]
	adds r1, 0x8
	movs r0, 0x4
	bl sub_80151C0
	b _0802B2AA
_0802AF1A:
	ldr r0, [r6]
	movs r1, 0xEF
	lsls r1, 2
	adds r0, r1
	bl sub_8006518
	bl ResetUnusedInputStruct
	movs r0, 0
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	ldr r0, [r6]
	movs r2, 0x86
	lsls r2, 2
	adds r0, r2
	ldrb r0, [r0]
	movs r1, 0
	bl sub_8031D70
	b _0802B2AA
_0802AF46:
	ldr r0, _0802AF4C
	b _0802B22E
	.align 2, 0
_0802AF4C: .4byte gUnknown_80DF3B4
_0802AF50:
	ldr r0, _0802AF5C
	ldr r2, [r6]
	movs r5, 0x84
	lsls r5, 3
	adds r2, r5
	b _0802B236
	.align 2, 0
_0802AF5C: .4byte gUnknown_80DF418
_0802AF60:
	ldr r0, _0802AF6C
	ldr r2, [r6]
	movs r1, 0x84
	lsls r1, 3
	adds r2, r1
	b _0802B236
	.align 2, 0
_0802AF6C: .4byte gUnknown_80DF44C
_0802AF70:
	ldr r0, _0802AF74
	b _0802B22E
	.align 2, 0
_0802AF74: .4byte gUnknown_80DF46C
_0802AF78:
	ldr r0, [r6]
	ldr r5, _0802AF90
	adds r0, r5
	ldr r0, [r0]
	cmp r0, 0x4
	bne _0802AF86
	b _0802B2AA
_0802AF86:
	cmp r0, 0x4
	bgt _0802AF94
	cmp r0, 0x3
	beq _0802AF9A
	b _0802B2AA
	.align 2, 0
_0802AF90: .4byte 0x00000534
_0802AF94:
	cmp r0, 0x6
	ble _0802AF9A
	b _0802B2AA
_0802AF9A:
	ldr r0, _0802AFA8
	ldr r2, [r6]
	movs r1, 0x84
	lsls r1, 3
	adds r2, r1
	b _0802B236
	.align 2, 0
_0802AFA8: .4byte gUnknown_80DF4F4
_0802AFAC:
	movs r4, 0x98
	lsls r4, 1
	adds r0, r4, 0
	bl GetMonSpecies
	adds r1, r0, 0
	ldr r5, _0802B00C
	ldr r0, [r5]
	ldr r2, _0802B010
	adds r0, r2
	bl strcpy
	ldr r1, [r5]
	movs r3, 0xAA
	lsls r3, 3
	adds r0, r1, r3
	movs r2, 0
	strh r4, [r0]
	ldr r0, _0802B014
	adds r1, r0
	movs r0, 0x2
	strb r0, [r1]
	ldr r0, [r5]
	adds r3, 0x4
	adds r1, r0, r3
	str r2, [r1]
	movs r1, 0x86
	lsls r1, 3
	adds r0, r1
	ldr r1, [r0]
	movs r0, 0x6
	bl sub_809539C
	lsls r0, 24
	lsrs r0, 24
	bl sub_8095228
	adds r2, r0, 0
	adds r0, 0x22
	ldrb r1, [r0]
	cmp r1, 0
	beq _0802B018
	ldr r0, [r5]
	movs r3, 0xAB
	lsls r3, 3
	adds r0, r3
	b _0802B022
	.align 2, 0
_0802B00C: .4byte gUnknown_203B2C4
_0802B010: .4byte 0x0000053c
_0802B014: .4byte 0x00000552
_0802B018:
	ldr r0, [r5]
	movs r5, 0xAB
	lsls r5, 3
	adds r0, r5
	movs r1, 0
_0802B022:
	strb r1, [r0]
	ldr r4, _0802B068
	ldr r0, [r4]
	ldr r1, _0802B06C
	adds r0, r1
	movs r5, 0
	movs r1, 0x1
	strb r1, [r0]
	adds r0, r2, 0x4
	movs r1, 0
	bl sub_803C200
	ldr r1, [r4]
	movs r3, 0xAC
	lsls r3, 3
	adds r2, r1, r3
	str r0, [r2]
	ldr r0, _0802B070
	adds r1, r0
	strb r5, [r1]
	ldr r0, [r4]
	ldr r1, _0802B074
	adds r0, r1
	strb r5, [r0]
	ldr r0, [r4]
	ldr r2, _0802B078
	adds r0, r2
	strb r5, [r0]
	ldr r0, [r4]
	subs r3, 0x24
	adds r0, r3
	movs r1, 0
	bl sub_802F204
	b _0802B2AA
	.align 2, 0
_0802B068: .4byte gUnknown_203B2C4
_0802B06C: .4byte 0x0000055b
_0802B070: .4byte 0x00000559
_0802B074: .4byte 0x0000055a
_0802B078: .4byte 0x0000055c
_0802B07C:
	movs r0, 0
	bl nullsub_23
	ldr r0, _0802B090
	movs r1, 0
	movs r2, 0
	movs r3, 0
	bl sub_80141B4
	b _0802B2AA
	.align 2, 0
_0802B090: .4byte gUnknown_80DF544
_0802B094:
	ldr r0, _0802B0A0
	ldr r2, [r6]
	movs r5, 0x84
	lsls r5, 3
	adds r2, r5
	b _0802B236
	.align 2, 0
_0802B0A0: .4byte gUnknown_80DF594
_0802B0A4:
	ldr r0, _0802B0A8
	b _0802B1A6
	.align 2, 0
_0802B0A8: .4byte gUnknown_80DF5E4
_0802B0AC:
	bl sub_808D33C
	adds r1, r0, 0
	add r6, sp, 0x64
	adds r1, 0x4C
	adds r0, r6, 0
	movs r2, 0xA
	bl sub_80922B4
	ldr r5, _0802B0E0
	ldr r0, [r5]
	ldr r4, _0802B0E4
	adds r0, r4
	ldr r1, _0802B0E8
	adds r2, r6, 0
	bl sub_800D158
	ldr r2, [r5]
	adds r4, r2, r4
	movs r3, 0x84
	lsls r3, 3
	adds r2, r3
	ldr r3, _0802B0EC
	adds r0, r4, 0
	b _0802B238
	.align 2, 0
_0802B0E0: .4byte gUnknown_203B2C4
_0802B0E4: .4byte 0x00000434
_0802B0E8: .4byte gUnknown_80DF63C
_0802B0EC: .4byte 0x0000010d
_0802B0F0:
	ldr r0, _0802B108
	ldr r3, _0802B10C
	movs r2, 0
	str r2, [sp]
	movs r1, 0x4
	str r1, [sp, 0x4]
	str r2, [sp, 0x8]
	ldr r1, [r6]
	movs r5, 0x84
	lsls r5, 3
	adds r1, r5
	b _0802B1BA
	.align 2, 0
_0802B108: .4byte gUnknown_80DF694
_0802B10C: .4byte gUnknown_80DEEE4
_0802B110:
	ldr r0, _0802B11C
	ldr r2, [r6]
	movs r1, 0x84
	lsls r1, 3
	adds r2, r1
	b _0802B236
	.align 2, 0
_0802B11C: .4byte gUnknown_80DF44C
_0802B120:
	ldr r0, _0802B124
	b _0802B22E
	.align 2, 0
_0802B124: .4byte gUnknown_80DF6F0
_0802B128:
	ldr r0, _0802B134
	ldr r2, [r6]
	movs r5, 0x84
	lsls r5, 3
	adds r2, r5
	b _0802B236
	.align 2, 0
_0802B134: .4byte gUnknown_80DF710
_0802B138:
	ldr r0, _0802B160
	ldr r3, _0802B164
	movs r2, 0
	str r2, [sp]
	movs r1, 0x4
	str r1, [sp, 0x4]
	str r2, [sp, 0x8]
	ldr r1, [r6]
	movs r2, 0x84
	lsls r2, 3
	adds r1, r2
	str r1, [sp, 0xC]
	movs r1, 0xC
	str r1, [sp, 0x10]
	movs r1, 0
	movs r2, 0
	bl sub_8014248
	b _0802B2AA
	.align 2, 0
_0802B160: .4byte gUnknown_80DF73C
_0802B164: .4byte gUnknown_80DEEBC
_0802B168:
	ldr r0, _0802B18C
	ldr r3, _0802B190
	movs r2, 0
	str r2, [sp]
	movs r1, 0x4
	str r1, [sp, 0x4]
	str r2, [sp, 0x8]
	ldr r1, [r6]
	movs r5, 0x84
	lsls r5, 3
	adds r1, r5
	str r1, [sp, 0xC]
	movs r1, 0xC
	str r1, [sp, 0x10]
	movs r1, 0
	bl sub_8014248
	b _0802B2AA
	.align 2, 0
_0802B18C: .4byte gUnknown_80DF77C
_0802B190: .4byte gUnknown_80DEE7C
_0802B194:
	ldr r0, _0802B1A0
	ldr r2, [r6]
	movs r1, 0x84
	lsls r1, 3
	adds r2, r1
	b _0802B236
	.align 2, 0
_0802B1A0: .4byte gUnknown_80DF7D4
_0802B1A4:
	ldr r0, _0802B1CC
_0802B1A6:
	ldr r3, _0802B1D0
_0802B1A8:
	movs r2, 0
	str r2, [sp]
	movs r1, 0x4
	str r1, [sp, 0x4]
	str r2, [sp, 0x8]
	ldr r1, [r6]
	movs r2, 0x84
	lsls r2, 3
	adds r1, r2
_0802B1BA:
	str r1, [sp, 0xC]
	movs r1, 0xC
	str r1, [sp, 0x10]
	movs r1, 0
	movs r2, 0x7
	bl sub_8014248
	b _0802B2AA
	.align 2, 0
_0802B1CC: .4byte gUnknown_80DF870
_0802B1D0: .4byte gUnknown_80DEE44
_0802B1D4:
	ldr r0, _0802B1D8
	b _0802B22E
	.align 2, 0
_0802B1D8: .4byte gUnknown_80DF8B4
_0802B1DC:
	ldr r0, _0802B1F4
	ldr r3, _0802B1F8
	movs r2, 0
	str r2, [sp]
	movs r1, 0x4
	str r1, [sp, 0x4]
	str r2, [sp, 0x8]
	ldr r1, [r6]
	movs r5, 0x84
	lsls r5, 3
	adds r1, r5
	b _0802B212
	.align 2, 0
_0802B1F4: .4byte gUnknown_80DF8EC
_0802B1F8: .4byte gUnknown_80DEDB8
_0802B1FC:
	ldr r0, _0802B224
	ldr r3, _0802B228
	movs r2, 0
	str r2, [sp]
	movs r1, 0x4
	str r1, [sp, 0x4]
	str r2, [sp, 0x8]
	ldr r1, [r6]
	movs r2, 0x84
	lsls r2, 3
	adds r1, r2
_0802B212:
	str r1, [sp, 0xC]
	movs r1, 0xC
	str r1, [sp, 0x10]
	movs r1, 0
	movs r2, 0x1
	bl sub_8014248
	b _0802B2AA
	.align 2, 0
_0802B224: .4byte gUnknown_80DF928
_0802B228: .4byte gUnknown_80DEDB8
_0802B22C:
	ldr r0, _0802B240
_0802B22E:
	ldr r2, [r6]
	movs r3, 0x84
	lsls r3, 3
	adds r2, r3
_0802B236:
	ldr r3, _0802B244
_0802B238:
	movs r1, 0
	bl sub_80141B4
	b _0802B2AA
	.align 2, 0
_0802B240: .4byte gUnknown_80DF94C
_0802B244: .4byte 0x0000010d
_0802B248:
	ldr r4, [r6]
	movs r5, 0xA7
	lsls r5, 3
	adds r0, r4, r5
	ldr r0, [r0]
	cmp r0, 0x1
	beq _0802B25C
	cmp r0, 0x2
	beq _0802B288
	b _0802B2AA
_0802B25C:
	ldr r0, _0802B280
	ldr r3, _0802B284
	movs r2, 0
	str r2, [sp]
	movs r1, 0x4
	str r1, [sp, 0x4]
	str r2, [sp, 0x8]
	movs r2, 0x84
	lsls r2, 3
	adds r1, r4, r2
	str r1, [sp, 0xC]
	movs r1, 0xC
	str r1, [sp, 0x10]
	movs r1, 0
	movs r2, 0x3
	bl sub_8014248
	b _0802B2AA
	.align 2, 0
_0802B280: .4byte gUnknown_80DF96C
_0802B284: .4byte gUnknown_80DEE08
_0802B288:
	ldr r0, _0802B2B4
	ldr r3, _0802B2B8
	movs r2, 0
	str r2, [sp]
	movs r1, 0x4
	str r1, [sp, 0x4]
	str r2, [sp, 0x8]
	movs r5, 0x84
	lsls r5, 3
	adds r1, r4, r5
	str r1, [sp, 0xC]
	movs r1, 0xC
	str r1, [sp, 0x10]
	movs r1, 0
	movs r2, 0x3
	bl sub_8014248
_0802B2AA:
	add sp, 0xB8
	pop {r4-r6}
	pop {r0}
	bx r0
	.align 2, 0
_0802B2B4: .4byte gUnknown_80DF9A4
_0802B2B8: .4byte gUnknown_80DEE08
	thumb_func_end sub_802ABF8

	thumb_func_start sub_802B2BC
sub_802B2BC:
	push {lr}
	ldr r1, _0802B2D0
	ldr r1, [r1]
	strb r0, [r1]
	bl nullsub_131
	bl sub_802ABF8
	pop {r0}
	bx r0
	.align 2, 0
_0802B2D0: .4byte gUnknown_203B2C4
	thumb_func_end sub_802B2BC

	thumb_func_start sub_802B2D4
sub_802B2D4:
	push {r4,r5,lr}
	bl ResetUnusedInputStruct
	movs r0, 0
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	ldr r5, _0802B348
	movs r4, 0xA0
	lsls r4, 1
	adds r0, r4, 0
	movs r1, 0x8
	bl MemoryAlloc
	str r0, [r5]
	movs r1, 0
	adds r2, r4, 0
	bl MemoryFill8
	ldr r1, [r5]
	movs r0, 0xFF
	strb r0, [r1, 0x1]
	ldr r0, _0802B34C
	subs r4, 0x10
	adds r1, r4, 0
	bl sub_808D8E0
	adds r0, r4, 0
	bl GetDialogueSpriteDataPtr
	ldr r1, [r5]
	str r0, [r1, 0x4]
	ldr r0, [r0, 0x4]
	str r0, [r1, 0x8]
	movs r2, 0
	strb r2, [r1, 0x10]
	ldr r0, [r5]
	strb r2, [r0, 0x11]
	ldr r0, [r5]
	strb r2, [r0, 0x12]
	ldr r0, [r5]
	movs r1, 0x2
	strh r1, [r0, 0xC]
	movs r1, 0x8
	strh r1, [r0, 0xE]
	adds r0, 0x1
	bl sub_8099394
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _0802B350
	movs r0, 0
	bl sub_802B548
	movs r0, 0x1
	b _0802B352
	.align 2, 0
_0802B348: .4byte gUnknown_203B2C8
_0802B34C: .4byte gUnknown_202E5D8
_0802B350:
	movs r0, 0
_0802B352:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_802B2D4

	thumb_func_start sub_802B358
sub_802B358:
	push {lr}
	ldr r0, _0802B370
	ldr r0, [r0]
	ldrb r0, [r0]
	cmp r0, 0x5
	bhi _0802B3B2
	lsls r0, 2
	ldr r1, _0802B374
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0802B370: .4byte gUnknown_203B2C8
_0802B374: .4byte _0802B378
	.align 2, 0
_0802B378:
	.4byte _0802B390
	.4byte _0802B396
	.4byte _0802B39C
	.4byte _0802B3A2
	.4byte _0802B3A8
	.4byte _0802B3AE
_0802B390:
	bl sub_802B560
	b _0802B3B2
_0802B396:
	bl sub_802B57C
	b _0802B3B2
_0802B39C:
	bl sub_802B5B8
	b _0802B3B2
_0802B3A2:
	bl sub_802B5FC
	b _0802B3B2
_0802B3A8:
	bl sub_802B624
	b _0802B3B2
_0802B3AE:
	movs r0, 0x3
	b _0802B3B4
_0802B3B2:
	movs r0, 0
_0802B3B4:
	pop {r1}
	bx r1
	thumb_func_end sub_802B358

	thumb_func_start sub_802B3B8
sub_802B3B8:
	push {r4,lr}
	ldr r4, _0802B3D8
	ldr r0, [r4]
	cmp r0, 0
	beq _0802B3D2
	ldr r0, [r0, 0x4]
	bl CloseFile
	ldr r0, [r4]
	bl MemoryFree
	movs r0, 0
	str r0, [r4]
_0802B3D2:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0802B3D8: .4byte gUnknown_203B2C8
	thumb_func_end sub_802B3B8

	thumb_func_start nullsub_132
nullsub_132:
	bx lr
	thumb_func_end nullsub_132

	thumb_func_start sub_802B3E0
sub_802B3E0:
	push {r4-r6,lr}
	mov r6, r9
	mov r5, r8
	push {r5,r6}
	sub sp, 0x28
	ldr r1, _0802B404
	ldr r0, [r1]
	ldrb r0, [r0]
	adds r2, r1, 0
	cmp r0, 0x5
	bls _0802B3F8
	b _0802B532
_0802B3F8:
	lsls r0, 2
	ldr r1, _0802B408
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0802B404: .4byte gUnknown_203B2C8
_0802B408: .4byte _0802B40C
	.align 2, 0
_0802B40C:
	.4byte _0802B424
	.4byte _0802B464
	.4byte _0802B50C
	.4byte _0802B532
	.4byte _0802B524
	.4byte _0802B532
_0802B424:
	movs r0, 0
	bl sub_80023E4
	lsls r0, 24
	cmp r0, 0
	beq _0802B438
	mov r0, sp
	bl sub_80920D8
	b _0802B440
_0802B438:
	ldr r1, _0802B458
	mov r0, sp
	bl strcpy
_0802B440:
	ldr r4, _0802B45C
	ldr r0, [r4]
	adds r0, 0x14
	ldr r1, _0802B460
	mov r2, sp
	bl sub_800D158
	ldr r2, [r4]
	adds r0, r2, 0
	adds r0, 0x14
	b _0802B510
	.align 2, 0
_0802B458: .4byte gUnknown_80DF9F0
_0802B45C: .4byte gUnknown_203B2C8
_0802B460: .4byte gUnknown_80DF9F8
_0802B464:
	movs r6, 0x98
	lsls r6, 1
	adds r0, r6, 0
	bl GetMonSpecies
	adds r1, r0, 0
	ldr r5, _0802B500
	ldr r0, [r5]
	movs r2, 0x8A
	lsls r2, 1
	mov r9, r2
	add r0, r9
	bl strcpy
	ldr r2, [r5]
	movs r3, 0x94
	lsls r3, 1
	adds r0, r2, r3
	movs r1, 0
	mov r8, r1
	movs r1, 0
	strh r6, [r0]
	adds r3, 0x2
	adds r2, r3
	movs r0, 0x2
	strb r0, [r2]
	ldr r0, [r5]
	movs r2, 0x96
	lsls r2, 1
	adds r0, r2
	str r1, [r0]
	bl sub_8097790
	ldr r0, [r5]
	ldrb r0, [r0, 0x1]
	bl sub_8095228
	adds r4, r0, 0
	adds r4, 0x4
	ldr r2, [r5]
	adds r2, r6
	adds r0, r4, 0
	movs r1, 0
	bl sub_803C37C
	adds r0, r4, 0
	movs r1, 0
	bl sub_803C200
	ldr r2, [r5]
	movs r3, 0x9C
	lsls r3, 1
	adds r1, r2, r3
	str r0, [r1]
	ldr r1, _0802B504
	adds r0, r2, r1
	mov r2, r8
	strb r2, [r0]
	ldr r0, [r5]
	subs r3, 0x6
	adds r0, r3
	strb r2, [r0]
	ldr r0, [r5]
	ldr r2, _0802B508
	adds r1, r0, r2
	movs r0, 0xA
	strb r0, [r1]
	ldr r0, [r5]
	adds r3, 0x2
	adds r0, r3
	mov r1, r8
	strb r1, [r0]
	ldr r0, [r5]
	add r0, r9
	movs r1, 0
	bl sub_802F204
	b _0802B532
	.align 2, 0
_0802B500: .4byte gUnknown_203B2C8
_0802B504: .4byte 0x00000131
_0802B508: .4byte 0x00000133
_0802B50C:
	ldr r0, _0802B51C
	ldr r2, [r2]
_0802B510:
	adds r2, 0x4
	ldr r3, _0802B520
	movs r1, 0
	bl sub_80141B4
	b _0802B532
	.align 2, 0
_0802B51C: .4byte gUnknown_80DFAA8
_0802B520: .4byte 0x0000010d
_0802B524:
	ldr r0, _0802B540
	ldr r2, [r2]
	adds r2, 0x4
	ldr r3, _0802B544
	movs r1, 0
	bl sub_80141B4
_0802B532:
	add sp, 0x28
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r6}
	pop {r0}
	bx r0
	.align 2, 0
_0802B540: .4byte gUnknown_80DFB14
_0802B544: .4byte 0x0000010d
	thumb_func_end sub_802B3E0

	thumb_func_start sub_802B548
sub_802B548:
	push {lr}
	ldr r1, _0802B55C
	ldr r1, [r1]
	strb r0, [r1]
	bl nullsub_132
	bl sub_802B3E0
	pop {r0}
	bx r0
	.align 2, 0
_0802B55C: .4byte gUnknown_203B2C8
	thumb_func_end sub_802B548

	thumb_func_start sub_802B560
sub_802B560:
	push {lr}
	sub sp, 0x4
	mov r0, sp
	bl sub_80144A4
	cmp r0, 0
	bne _0802B574
	movs r0, 0x1
	bl sub_802B548
_0802B574:
	add sp, 0x4
	pop {r0}
	bx r0
	thumb_func_end sub_802B560

	thumb_func_start sub_802B57C
sub_802B57C:
	push {r4,lr}
	bl sub_802F298
	cmp r0, 0x3
	bne _0802B5AA
	bl sub_802F2C0
	ldr r0, _0802B5B0
	movs r4, 0x98
	lsls r4, 1
	adds r1, r4, 0
	bl sub_808D8E0
	adds r0, r4, 0
	bl GetMonSpecies
	adds r1, r0, 0
	ldr r0, _0802B5B4
	bl strcpy
	movs r0, 0x2
	bl sub_802B548
_0802B5AA:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0802B5B0: .4byte gUnknown_202E5D8
_0802B5B4: .4byte gAvailablePokemonNames
	thumb_func_end sub_802B57C

	thumb_func_start sub_802B5B8
sub_802B5B8:
	push {r4,lr}
	sub sp, 0x4
	mov r0, sp
	bl sub_80144A4
	cmp r0, 0
	bne _0802B5EE
	bl sub_8011C34
	adds r4, r0, 0
	ldr r0, _0802B5F8
	ldr r0, [r0]
	ldrb r0, [r0, 0x1]
	bl sub_8095228
	movs r1, 0x4
	strb r1, [r0]
	str r4, [r0, 0x28]
	movs r0, 0x3
	bl sub_802B548
	movs r0, 0x1
	bl sub_8011C28
	movs r0, 0
	bl sub_8012574
_0802B5EE:
	add sp, 0x4
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0802B5F8: .4byte gUnknown_203B2C8
	thumb_func_end sub_802B5B8

	thumb_func_start sub_802B5FC
sub_802B5FC:
	push {lr}
	sub sp, 0x4
	mov r0, sp
	bl sub_80144A4
	cmp r0, 0
	bne _0802B61E
	bl sub_8012600
	lsls r0, 24
	cmp r0, 0
	bne _0802B61E
	bl sub_8012750
	movs r0, 0x4
	bl sub_802B548
_0802B61E:
	add sp, 0x4
	pop {r0}
	bx r0
	thumb_func_end sub_802B5FC

	thumb_func_start sub_802B624
sub_802B624:
	push {lr}
	sub sp, 0x4
	mov r0, sp
	bl sub_80144A4
	cmp r0, 0
	bne _0802B638
	movs r0, 0x5
	bl sub_802B548
_0802B638:
	add sp, 0x4
	pop {r0}
	bx r0
	thumb_func_end sub_802B624

	thumb_func_start sub_802B640
sub_802B640:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	adds r6, r0, 0
	adds r4, r1, 0
	mov r8, r2
	bl sub_802B9D8
	lsls r0, 24
	cmp r0, 0
	beq _0802B65A
	movs r0, 0
	b _0802B706
_0802B65A:
	ldr r5, _0802B710
	ldr r0, [r5]
	cmp r0, 0
	bne _0802B66C
	movs r0, 0xD4
	movs r1, 0x8
	bl MemoryAlloc
	str r0, [r5]
_0802B66C:
	ldr r0, [r5]
	str r6, [r0, 0x6C]
	lsls r1, r6, 1
	adds r1, r6
	lsls r1, 3
	adds r1, 0x74
	adds r1, r0, r1
	str r1, [r0, 0x70]
	adds r0, 0x74
	bl sub_8006518
	ldr r1, [r5]
	ldr r2, [r1, 0x6C]
	lsls r0, r2, 1
	adds r0, r2
	lsls r0, 3
	adds r1, r0
	adds r1, 0x74
	ldr r0, _0802B714
	ldm r0!, {r2,r3,r7}
	stm r1!, {r2,r3,r7}
	ldm r0!, {r2,r3,r7}
	stm r1!, {r2,r3,r7}
	cmp r4, 0
	beq _0802B6B0
	ldr r1, [r5]
	ldr r2, [r1, 0x6C]
	lsls r0, r2, 1
	adds r0, r2
	lsls r0, 3
	adds r1, 0x7C
	adds r1, r0
	ldr r0, [r4]
	str r0, [r1]
_0802B6B0:
	ldr r0, [r5]
	ldr r0, [r0, 0x70]
	mov r1, r8
	bl sub_8012D08
	bl ResetUnusedInputStruct
	ldr r0, [r5]
	adds r0, 0x74
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	ldr r4, [r5]
	adds r4, 0x38
	bl sub_802B9A8
	adds r1, r0, 0
	adds r0, r4, 0
	mov r2, r8
	adds r3, r6, 0
	bl sub_8013818
	ldr r2, [r5]
	ldr r0, _0802B718
	ldrh r1, [r0]
	adds r0, r2, 0
	adds r0, 0x50
	strh r1, [r0]
	ldr r0, _0802B71C
	ldrh r0, [r0]
	adds r1, r2, 0
	adds r1, 0x56
	strh r0, [r1]
	adds r0, r2, 0
	adds r0, 0x38
	bl sub_8013984
	bl sub_802B880
	bl sub_802B8D4
	movs r0, 0x1
_0802B706:
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r1}
	bx r1
	.align 2, 0
_0802B710: .4byte gUnknown_203B2CC
_0802B714: .4byte gUnknown_80DFBEC
_0802B718: .4byte gUnknown_203B2D0
_0802B71C: .4byte gUnknown_203B2D2
	thumb_func_end sub_802B640

	thumb_func_start sub_802B720
sub_802B720:
	push {lr}
	lsls r0, 24
	cmp r0, 0
	bne _0802B73C
	ldr r0, _0802B738
	ldr r0, [r0]
	adds r0, 0x38
	bl sub_8013660
	movs r0, 0
	b _0802B7A2
	.align 2, 0
_0802B738: .4byte gUnknown_203B2CC
_0802B73C:
	ldr r0, _0802B754
	ldr r0, [r0]
	adds r0, 0x38
	bl GetKeyPress
	cmp r0, 0x2
	beq _0802B75E
	cmp r0, 0x2
	bgt _0802B758
	cmp r0, 0x1
	beq _0802B768
	b _0802B77C
	.align 2, 0
_0802B754: .4byte gUnknown_203B2CC
_0802B758:
	cmp r0, 0x4
	beq _0802B772
	b _0802B77C
_0802B75E:
	movs r0, 0x1
	bl sub_80119D4
	movs r0, 0x2
	b _0802B7A2
_0802B768:
	movs r0, 0
	bl sub_80119D4
	movs r0, 0x3
	b _0802B7A2
_0802B772:
	movs r0, 0x4
	bl sub_80119D4
	movs r0, 0x4
	b _0802B7A2
_0802B77C:
	ldr r0, _0802B794
	ldr r0, [r0]
	adds r0, 0x38
	movs r1, 0x1
	bl sub_80138B8
	lsls r0, 24
	cmp r0, 0
	bne _0802B798
	movs r0, 0
	b _0802B7A2
	.align 2, 0
_0802B794: .4byte gUnknown_203B2CC
_0802B798:
	bl sub_802B880
	bl sub_802B8D4
	movs r0, 0x1
_0802B7A2:
	pop {r1}
	bx r1
	thumb_func_end sub_802B720

	thumb_func_start sub_802B7A8
sub_802B7A8:
	ldr r0, _0802B7CC
	ldr r2, [r0]
	adds r0, r2, 0
	adds r0, 0x56
	movs r3, 0
	ldrsh r1, [r0, r3]
	subs r0, 0x2
	movs r3, 0
	ldrsh r0, [r0, r3]
	muls r0, r1
	adds r1, r2, 0
	adds r1, 0x50
	movs r3, 0
	ldrsh r1, [r1, r3]
	adds r0, r1
	adds r0, r2, r0
	ldrb r0, [r0]
	bx lr
	.align 2, 0
_0802B7CC: .4byte gUnknown_203B2CC
	thumb_func_end sub_802B7A8

	thumb_func_start sub_802B7D0
sub_802B7D0:
	push {r4,r5,lr}
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	bl ResetUnusedInputStruct
	ldr r5, _0802B818
	ldr r0, [r5]
	adds r0, 0x74
	movs r1, 0
	movs r2, 0
	bl sub_800641C
	bl sub_802B9A8
	adds r1, r0, 0
	ldr r0, [r5]
	adds r2, r0, 0
	adds r2, 0x5A
	strh r1, [r2]
	adds r0, 0x38
	bl sub_8013984
	bl sub_802B880
	bl sub_802B8D4
	cmp r4, 0
	beq _0802B812
	ldr r0, [r5]
	adds r0, 0x38
	bl AddMenuCursorSprite
_0802B812:
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_0802B818: .4byte gUnknown_203B2CC
	thumb_func_end sub_802B7D0

	thumb_func_start sub_802B81C
sub_802B81C:
	push {r4,r5,lr}
	ldr r4, _0802B870
	ldr r2, [r4]
	cmp r2, 0
	beq _0802B86A
	ldr r1, _0802B874
	adds r0, r2, 0
	adds r0, 0x50
	ldrh r0, [r0]
	strh r0, [r1]
	ldr r1, _0802B878
	adds r0, r2, 0
	adds r0, 0x56
	ldrh r0, [r0]
	strh r0, [r1]
	ldr r0, [r2, 0x6C]
	lsls r1, r0, 1
	adds r1, r0
	lsls r1, 3
	adds r1, r2, r1
	adds r1, 0x74
	ldr r0, _0802B87C
	ldm r0!, {r2,r3,r5}
	stm r1!, {r2,r3,r5}
	ldm r0!, {r2,r3,r5}
	stm r1!, {r2,r3,r5}
	bl ResetUnusedInputStruct
	ldr r0, [r4]
	adds r0, 0x74
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	ldr r0, [r4]
	bl MemoryFree
	movs r0, 0
	str r0, [r4]
_0802B86A:
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_0802B870: .4byte gUnknown_203B2CC
_0802B874: .4byte gUnknown_203B2D0
_0802B878: .4byte gUnknown_203B2D2
_0802B87C: .4byte gUnknown_80DFBD0
	thumb_func_end sub_802B81C

	thumb_func_start sub_802B880
sub_802B880:
	push {r4,lr}
	ldr r4, _0802B8D0
	ldr r0, [r4]
	adds r0, 0x52
	movs r1, 0
	ldrsh r0, [r0, r1]
	movs r1, 0xC
	bl sub_80095E4
	adds r0, 0x2
	lsls r0, 16
	ldr r2, [r4]
	ldr r3, [r2, 0x6C]
	lsls r1, r3, 1
	adds r1, r3
	lsls r1, 3
	adds r1, r2, r1
	adds r1, 0x82
	asrs r3, r0, 16
	lsrs r0, 16
	strh r0, [r1]
	ldr r1, [r2, 0x6C]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 3
	adds r2, r0
	adds r3, 0x2
	adds r2, 0x84
	strh r3, [r2]
	bl ResetUnusedInputStruct
	ldr r0, [r4]
	adds r0, 0x74
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0802B8D0: .4byte gUnknown_203B2CC
	thumb_func_end sub_802B880

	thumb_func_start sub_802B8D4
sub_802B8D4:
	push {r4-r7,lr}
	sub sp, 0x8
	ldr r4, _0802B99C
	ldr r0, [r4]
	ldr r0, [r0, 0x6C]
	bl sub_8008C54
	ldr r0, [r4]
	ldr r0, [r0, 0x6C]
	bl sub_80073B8
	ldr r2, _0802B9A0
	ldr r0, [r4]
	ldr r3, [r0, 0x6C]
	movs r0, 0
	str r0, [sp]
	movs r0, 0xA
	movs r1, 0
	bl xxx_call_draw_string
	ldr r0, _0802B9A4
	ldrb r0, [r0, 0x2]
	lsls r0, 3
	adds r0, 0x4
	ldr r3, [r4]
	adds r1, r3, 0
	adds r1, 0x56
	movs r5, 0
	ldrsh r2, [r1, r5]
	adds r2, 0x1
	movs r1, 0x7
	str r1, [sp]
	ldr r1, [r3, 0x6C]
	str r1, [sp, 0x4]
	movs r1, 0
	movs r3, 0x2
	bl sub_8012BC4
	movs r6, 0
	ldr r0, [r4]
	adds r0, 0x52
	movs r1, 0
	ldrsh r0, [r0, r1]
	cmp r6, r0
	bge _0802B98A
	adds r7, r4, 0
_0802B930:
	ldr r0, [r7]
	adds r0, 0x38
	adds r1, r6, 0
	bl sub_8013800
	adds r5, r0, 0
	ldr r1, [r7]
	adds r0, r1, 0
	adds r0, 0x56
	movs r3, 0
	ldrsh r2, [r0, r3]
	subs r0, 0x2
	movs r3, 0
	ldrsh r0, [r0, r3]
	muls r0, r2
	adds r0, r6
	adds r0, r1, r0
	ldrb r4, [r0]
	ldr r3, [r1, 0x6C]
	movs r0, 0xA
	adds r1, r5, 0
	movs r2, 0x6
	bl sub_803B6B0
	bl sub_802BC7C
	adds r0, r4, 0
	bl GetPokemonMailHeadline
	adds r2, r0, 0
	ldr r0, [r7]
	ldr r3, [r0, 0x6C]
	movs r0, 0
	str r0, [sp]
	movs r0, 0x15
	adds r1, r5, 0
	bl sub_8014FF0
	adds r6, 0x1
	ldr r0, [r7]
	adds r0, 0x52
	movs r5, 0
	ldrsh r0, [r0, r5]
	cmp r6, r0
	blt _0802B930
_0802B98A:
	ldr r0, _0802B99C
	ldr r0, [r0]
	ldr r0, [r0, 0x6C]
	bl sub_80073E0
	add sp, 0x8
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_0802B99C: .4byte gUnknown_203B2CC
_0802B9A0: .4byte gUnknown_80DFC04
_0802B9A4: .4byte gUnknown_80DFBE8
	thumb_func_end sub_802B8D4

	thumb_func_start sub_802B9A8
sub_802B9A8:
	push {r4,r5,lr}
	movs r5, 0
	movs r4, 0
_0802B9AE:
	lsls r0, r4, 24
	lsrs r0, 24
	bl sub_8096E14
	lsls r0, 24
	cmp r0, 0
	beq _0802B9C6
	ldr r0, _0802B9D4
	ldr r0, [r0]
	adds r0, r5
	strb r4, [r0]
	adds r5, 0x1
_0802B9C6:
	adds r4, 0x1
	cmp r4, 0x37
	ble _0802B9AE
	adds r0, r5, 0
	pop {r4,r5}
	pop {r1}
	bx r1
	.align 2, 0
_0802B9D4: .4byte gUnknown_203B2CC
	thumb_func_end sub_802B9A8

	thumb_func_start sub_802B9D8
sub_802B9D8:
	push {r4,lr}
	movs r4, 0
_0802B9DC:
	lsls r0, r4, 24
	lsrs r0, 24
	bl sub_8096E14
	lsls r0, 24
	cmp r0, 0
	beq _0802B9EE
	movs r0, 0
	b _0802B9F6
_0802B9EE:
	adds r4, 0x1
	cmp r4, 0x37
	ble _0802B9DC
	movs r0, 0x1
_0802B9F6:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_802B9D8

	thumb_func_start sub_802B9FC
sub_802B9FC:
	push {r4-r7,lr}
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	ldr r5, _0802BA80
	movs r0, 0x94
	movs r1, 0x8
	bl MemoryAlloc
	str r0, [r5]
	movs r6, 0
	strb r4, [r0, 0x4]
	ldr r0, [r5]
	adds r0, 0x88
	bl sub_801317C
	ldr r1, [r5]
	str r6, [r1, 0x24]
	adds r1, 0x28
	ldr r0, _0802BA84
	ldm r0!, {r2-r4}
	stm r1!, {r2-r4}
	ldm r0!, {r2,r3,r7}
	stm r1!, {r2,r3,r7}
	ldr r1, [r5]
	ldr r2, _0802BA88
	adds r1, 0x40
	adds r0, r2, 0
	ldm r0!, {r3,r4,r7}
	stm r1!, {r3,r4,r7}
	ldm r0!, {r3,r4,r7}
	stm r1!, {r3,r4,r7}
	ldr r1, [r5]
	adds r1, 0x58
	adds r0, r2, 0
	ldm r0!, {r3,r4,r7}
	stm r1!, {r3,r4,r7}
	ldm r0!, {r3,r4,r7}
	stm r1!, {r3,r4,r7}
	ldr r0, [r5]
	adds r0, 0x70
	ldm r2!, {r1,r4,r7}
	stm r0!, {r1,r4,r7}
	ldm r2!, {r3,r4,r7}
	stm r0!, {r3,r4,r7}
	bl ResetUnusedInputStruct
	ldr r0, [r5]
	adds r0, 0x28
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	ldr r0, [r5]
	str r6, [r0, 0x8]
	bl sub_802BCC4
	bl sub_802BC7C
	movs r0, 0
	bl sub_802BB14
	movs r0, 0x1
	pop {r4-r7}
	pop {r1}
	bx r1
	.align 2, 0
_0802BA80: .4byte gUnknown_203B2D4
_0802BA84: .4byte gUnknown_80DFC34
_0802BA88: .4byte gUnknown_80DFC18
	thumb_func_end sub_802B9FC

	thumb_func_start sub_802BA8C
sub_802BA8C:
	push {lr}
	ldr r0, _0802BAA4
	ldr r0, [r0]
	ldr r0, [r0]
	cmp r0, 0x1
	beq _0802BAB8
	cmp r0, 0x1
	bgt _0802BAA8
	cmp r0, 0
	beq _0802BAB2
	b _0802BAC2
	.align 2, 0
_0802BAA4: .4byte gUnknown_203B2D4
_0802BAA8:
	cmp r0, 0x2
	beq _0802BAC2
	cmp r0, 0x3
	beq _0802BABE
	b _0802BAC2
_0802BAB2:
	bl sub_802BB98
	b _0802BAC6
_0802BAB8:
	bl sub_802BC08
	b _0802BAC6
_0802BABE:
	movs r0, 0x3
	b _0802BAC8
_0802BAC2:
	movs r0, 0x2
	b _0802BAC8
_0802BAC6:
	movs r0, 0
_0802BAC8:
	pop {r1}
	bx r1
	thumb_func_end sub_802BA8C

	thumb_func_start sub_802BACC
sub_802BACC:
	push {r4,r5,lr}
	ldr r4, _0802BB0C
	ldr r2, [r4]
	cmp r2, 0
	beq _0802BB06
	ldr r0, [r2, 0x24]
	lsls r1, r0, 1
	adds r1, r0
	lsls r1, 3
	adds r1, r2, r1
	adds r1, 0x28
	ldr r0, _0802BB10
	ldm r0!, {r2,r3,r5}
	stm r1!, {r2,r3,r5}
	ldm r0!, {r2,r3,r5}
	stm r1!, {r2,r3,r5}
	bl ResetUnusedInputStruct
	ldr r0, [r4]
	adds r0, 0x28
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	ldr r0, [r4]
	bl MemoryFree
	movs r0, 0
	str r0, [r4]
_0802BB06:
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_0802BB0C: .4byte gUnknown_203B2D4
_0802BB10: .4byte gUnknown_80DFC18
	thumb_func_end sub_802BACC

	thumb_func_start sub_802BB14
sub_802BB14:
	push {lr}
	ldr r1, _0802BB24
	ldr r1, [r1]
	str r0, [r1]
	bl sub_802BB28
	pop {r0}
	bx r0
	.align 2, 0
_0802BB24: .4byte gUnknown_203B2D4
	thumb_func_end sub_802BB14

	thumb_func_start sub_802BB28
sub_802BB28:
	push {r4,r5,lr}
	sub sp, 0x4
	ldr r5, _0802BB94
	ldr r1, [r5]
	ldr r0, [r1]
	cmp r0, 0
	blt _0802BB8C
	cmp r0, 0x1
	bgt _0802BB8C
	ldr r0, [r1, 0x24]
	bl sub_8008C54
	ldr r0, [r5]
	ldr r0, [r0, 0x24]
	bl sub_80073B8
	ldr r0, [r5]
	ldrb r0, [r0, 0x4]
	bl GetPokemonMailHeadline
	adds r2, r0, 0
	ldr r0, [r5]
	ldr r3, [r0, 0x24]
	movs r4, 0
	str r4, [sp]
	movs r0, 0xA
	movs r1, 0
	bl sub_8014FF0
	ldr r3, [r5]
	ldr r1, [r3, 0x8]
	lsls r1, 2
	adds r0, r3, 0
	adds r0, 0x10
	adds r0, r1
	ldr r2, [r0]
	ldr r3, [r3, 0x24]
	str r4, [sp]
	movs r0, 0x6
	movs r1, 0x14
	bl sub_8014FF0
	ldr r0, [r5]
	ldr r0, [r0, 0x24]
	bl sub_80073E0
	ldr r1, [r5]
	ldr r0, [r1, 0x8]
	adds r0, 0x1
	str r0, [r1, 0x8]
_0802BB8C:
	add sp, 0x4
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_0802BB94: .4byte gUnknown_203B2D4
	thumb_func_end sub_802BB28

	thumb_func_start sub_802BB98
sub_802BB98:
	push {r4,lr}
	ldr r0, _0802BBD4
	ldr r2, [r0]
	ldr r1, [r2, 0xC]
	adds r4, r0, 0
	cmp r1, 0
	beq _0802BBBC
	ldr r0, [r2, 0x20]
	movs r1, 0x8
	ands r0, r1
	cmp r0, 0
	beq _0802BBB4
	bl sub_8013E54
_0802BBB4:
	ldr r1, [r4]
	ldr r0, [r1, 0x20]
	adds r0, 0x1
	str r0, [r1, 0x20]
_0802BBBC:
	ldr r1, [r4]
	adds r0, r1, 0
	adds r0, 0x88
	ldr r1, [r1, 0x24]
	bl sub_8012A64
	cmp r0, 0x1
	beq _0802BBD8
	cmp r0, 0x2
	beq _0802BBF6
	b _0802BC02
	.align 2, 0
_0802BBD4: .4byte gUnknown_203B2D4
_0802BBD8:
	movs r0, 0
	bl sub_80119D4
	ldr r0, [r4]
	ldr r0, [r0, 0xC]
	cmp r0, 0
	beq _0802BBEE
	movs r0, 0x1
	bl sub_802BB14
	b _0802BC02
_0802BBEE:
	movs r0, 0x3
	bl sub_802BB14
	b _0802BC02
_0802BBF6:
	movs r0, 0x1
	bl sub_80119D4
	movs r0, 0x2
	bl sub_802BB14
_0802BC02:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_802BB98

	thumb_func_start sub_802BC08
sub_802BC08:
	push {r4,lr}
	ldr r0, _0802BC44
	ldr r3, [r0]
	ldr r2, [r3, 0x8]
	ldr r1, [r3, 0xC]
	adds r4, r0, 0
	cmp r2, r1
	bge _0802BC2E
	ldr r0, [r3, 0x20]
	movs r1, 0x8
	ands r0, r1
	cmp r0, 0
	beq _0802BC26
	bl sub_8013E54
_0802BC26:
	ldr r1, [r4]
	ldr r0, [r1, 0x20]
	adds r0, 0x1
	str r0, [r1, 0x20]
_0802BC2E:
	ldr r1, [r4]
	adds r0, r1, 0
	adds r0, 0x88
	ldr r1, [r1, 0x24]
	bl sub_8012A64
	cmp r0, 0x1
	beq _0802BC48
	cmp r0, 0x2
	beq _0802BC68
	b _0802BC74
	.align 2, 0
_0802BC44: .4byte gUnknown_203B2D4
_0802BC48:
	movs r0, 0
	bl sub_80119D4
	ldr r0, [r4]
	ldr r1, [r0, 0x8]
	ldr r0, [r0, 0xC]
	cmp r1, r0
	bge _0802BC60
	movs r0, 0x1
	bl sub_802BB14
	b _0802BC74
_0802BC60:
	movs r0, 0x3
	bl sub_802BB14
	b _0802BC74
_0802BC68:
	movs r0, 0x1
	bl sub_80119D4
	movs r0, 0x2
	bl sub_802BB14
_0802BC74:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_802BC08

	thumb_func_start sub_802BC7C
sub_802BC7C:
	push {r4,lr}
	ldr r4, _0802BCA4
	bl sub_808D3BC
	adds r1, r0, 0
	adds r0, r4, 0
	bl sub_808DA34
	ldr r0, _0802BCA8
	ldr r0, [r0]
	ldrb r0, [r0, 0xB]
	cmp r0, 0x1
	bne _0802BCB0
	adds r0, r4, 0
	adds r0, 0x50
	ldr r1, _0802BCAC
	bl strcpy
	b _0802BCBA
	.align 2, 0
_0802BCA4: .4byte gAvailablePokemonNames
_0802BCA8: .4byte gUnknown_203B46C
_0802BCAC: .4byte gUnknown_80DFC4C
_0802BCB0:
	adds r0, r4, 0
	adds r0, 0x50
	ldr r1, _0802BCC0
	bl strcpy
_0802BCBA:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0802BCC0: .4byte gUnknown_80DFC50
	thumb_func_end sub_802BC7C

	thumb_func_start sub_802BCC4
sub_802BCC4:
	push {r4,lr}
	ldr r4, _0802BCDC
	ldr r0, [r4]
	ldrb r0, [r0, 0x4]
	bl GetPokemonMailText
	adds r3, r0, 0
	ldr r1, [r4]
	movs r0, 0
	str r0, [r1, 0xC]
	str r3, [r1, 0x10]
	b _0802BD08
	.align 2, 0
_0802BCDC: .4byte gUnknown_203B2D4
_0802BCE0:
	cmp r0, 0x23
	bne _0802BD06
	ldrb r2, [r3, 0x1]
	cmp r2, 0x50
	beq _0802BCF0
	adds r1, r3, 0x2
	cmp r2, 0x70
	bne _0802BD02
_0802BCF0:
	ldr r0, [r4]
	ldr r1, [r0, 0xC]
	adds r1, 0x1
	str r1, [r0, 0xC]
	lsls r1, 2
	adds r0, 0x10
	adds r0, r1
	adds r1, r3, 0x2
	str r1, [r0]
_0802BD02:
	adds r3, r1, 0
	b _0802BD08
_0802BD06:
	adds r3, 0x1
_0802BD08:
	ldrb r0, [r3]
	cmp r0, 0
	bne _0802BCE0
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_802BCC4

	thumb_func_start sub_802BD14
sub_802BD14:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	adds r6, r0, 0
	adds r4, r1, 0
	mov r8, r2
	bl sub_802C0E8
	lsls r0, 24
	cmp r0, 0
	beq _0802BD2E
	movs r0, 0
	b _0802BDD4
_0802BD2E:
	ldr r5, _0802BDE0
	ldr r0, [r5]
	cmp r0, 0
	bne _0802BD40
	movs r0, 0xA4
	movs r1, 0x8
	bl MemoryAlloc
	str r0, [r5]
_0802BD40:
	ldr r0, [r5]
	str r6, [r0, 0x38]
	lsls r1, r6, 1
	adds r1, r6
	lsls r1, 3
	adds r1, 0x40
	adds r1, r0, r1
	str r1, [r0, 0x3C]
	adds r0, 0x40
	bl sub_8006518
	ldr r1, [r5]
	ldr r2, [r1, 0x38]
	lsls r0, r2, 1
	adds r0, r2
	lsls r0, 3
	adds r1, r0
	adds r1, 0x40
	ldr r0, _0802BDE4
	ldm r0!, {r2,r3,r7}
	stm r1!, {r2,r3,r7}
	ldm r0!, {r2,r3,r7}
	stm r1!, {r2,r3,r7}
	ldr r2, [r5]
	ldr r1, [r2, 0x3C]
	adds r0, r2, 0
	adds r0, 0xA0
	str r0, [r1, 0x14]
	cmp r4, 0
	beq _0802BD8E
	ldr r1, [r2, 0x38]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 3
	adds r1, r2, 0
	adds r1, 0x48
	adds r1, r0
	ldr r0, [r4]
	str r0, [r1]
_0802BD8E:
	ldr r0, [r5]
	ldr r0, [r0, 0x3C]
	mov r1, r8
	bl sub_8012D34
	bl ResetUnusedInputStruct
	ldr r0, [r5]
	adds r0, 0x40
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	ldr r4, [r5]
	adds r4, 0x4
	bl sub_802C0B8
	adds r1, r0, 0
	adds r0, r4, 0
	mov r2, r8
	adds r3, r6, 0
	bl sub_8013848
	ldr r0, [r5]
	ldr r1, _0802BDE8
	ldrh r1, [r1]
	strh r1, [r0, 0x1C]
	adds r0, 0x4
	bl sub_8013984
	bl sub_802BF30
	bl CreateMailMenu
	movs r0, 0x1
_0802BDD4:
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r1}
	bx r1
	.align 2, 0
_0802BDE0: .4byte gUnknown_203B2D8
_0802BDE4: .4byte gUnknown_80DFC74
_0802BDE8: .4byte gUnknown_203B2DC
	thumb_func_end sub_802BD14

	thumb_func_start sub_802BDEC
sub_802BDEC:
	push {lr}
	lsls r0, 24
	cmp r0, 0
	bne _0802BE08
	ldr r0, _0802BE04
	ldr r0, [r0]
	adds r0, 0x4
	bl sub_8013660
	movs r0, 0
	b _0802BE6E
	.align 2, 0
_0802BE04: .4byte gUnknown_203B2D8
_0802BE08:
	ldr r0, _0802BE20
	ldr r0, [r0]
	adds r0, 0x4
	bl GetKeyPress
	cmp r0, 0x2
	beq _0802BE2A
	cmp r0, 0x2
	bgt _0802BE24
	cmp r0, 0x1
	beq _0802BE34
	b _0802BE48
	.align 2, 0
_0802BE20: .4byte gUnknown_203B2D8
_0802BE24:
	cmp r0, 0x4
	beq _0802BE3E
	b _0802BE48
_0802BE2A:
	movs r0, 0x1
	bl sub_80119D4
	movs r0, 0x2
	b _0802BE6E
_0802BE34:
	movs r0, 0
	bl sub_80119D4
	movs r0, 0x3
	b _0802BE6E
_0802BE3E:
	movs r0, 0x4
	bl sub_80119D4
	movs r0, 0x4
	b _0802BE6E
_0802BE48:
	ldr r0, _0802BE60
	ldr r0, [r0]
	adds r0, 0x4
	movs r1, 0x1
	bl sub_80138B8
	lsls r0, 24
	cmp r0, 0
	bne _0802BE64
	movs r0, 0
	b _0802BE6E
	.align 2, 0
_0802BE60: .4byte gUnknown_203B2D8
_0802BE64:
	bl sub_802BF30
	bl CreateMailMenu
	movs r0, 0x1
_0802BE6E:
	pop {r1}
	bx r1
	thumb_func_end sub_802BDEC

	thumb_func_start sub_802BE74
sub_802BE74:
	ldr r0, _0802BE90
	ldr r1, [r0]
	movs r0, 0x22
	ldrsh r2, [r1, r0]
	movs r3, 0x20
	ldrsh r0, [r1, r3]
	muls r0, r2
	movs r3, 0x1C
	ldrsh r2, [r1, r3]
	adds r0, r2
	adds r1, r0
	ldrb r0, [r1]
	bx lr
	.align 2, 0
_0802BE90: .4byte gUnknown_203B2D8
	thumb_func_end sub_802BE74

	thumb_func_start sub_802BE94
sub_802BE94:
	push {r4,r5,lr}
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	bl ResetUnusedInputStruct
	ldr r5, _0802BED8
	ldr r0, [r5]
	adds r0, 0x40
	movs r1, 0
	movs r2, 0
	bl sub_800641C
	bl sub_802C0B8
	adds r1, r0, 0
	ldr r0, [r5]
	strh r1, [r0, 0x26]
	adds r0, 0x4
	bl sub_8013984
	bl sub_802BF30
	bl CreateMailMenu
	cmp r4, 0
	beq _0802BED2
	ldr r0, [r5]
	adds r0, 0x4
	bl AddMenuCursorSprite
_0802BED2:
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_0802BED8: .4byte gUnknown_203B2D8
	thumb_func_end sub_802BE94

	thumb_func_start sub_802BEDC
sub_802BEDC:
	push {r4,r5,lr}
	ldr r4, _0802BF24
	ldr r2, [r4]
	cmp r2, 0
	beq _0802BF1C
	ldr r1, _0802BF28
	ldrh r0, [r2, 0x1C]
	strh r0, [r1]
	ldr r0, [r2, 0x38]
	lsls r1, r0, 1
	adds r1, r0
	lsls r1, 3
	adds r1, r2, r1
	adds r1, 0x40
	ldr r0, _0802BF2C
	ldm r0!, {r2,r3,r5}
	stm r1!, {r2,r3,r5}
	ldm r0!, {r2,r3,r5}
	stm r1!, {r2,r3,r5}
	bl ResetUnusedInputStruct
	ldr r0, [r4]
	adds r0, 0x40
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	ldr r0, [r4]
	bl MemoryFree
	movs r0, 0
	str r0, [r4]
_0802BF1C:
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_0802BF24: .4byte gUnknown_203B2D8
_0802BF28: .4byte gUnknown_203B2DC
_0802BF2C: .4byte gUnknown_80DFC5C
	thumb_func_end sub_802BEDC

	thumb_func_start sub_802BF30
sub_802BF30:
	push {r4,lr}
	ldr r4, _0802BF9C
	ldr r0, [r4]
	adds r0, 0xA0
	movs r2, 0
	movs r1, 0x1
	strb r1, [r0]
	ldr r0, [r4]
	adds r0, 0xA1
	strb r2, [r0]
	ldr r0, [r4]
	adds r0, 0xA2
	movs r1, 0xC
	strb r1, [r0]
	ldr r0, [r4]
	adds r0, 0xA3
	strb r2, [r0]
	ldr r0, [r4]
	movs r1, 0x1E
	ldrsh r0, [r0, r1]
	movs r1, 0x18
	bl sub_8009614
	adds r0, 0x2
	lsls r0, 16
	ldr r2, [r4]
	ldr r3, [r2, 0x38]
	lsls r1, r3, 1
	adds r1, r3
	lsls r1, 3
	adds r1, r2, r1
	adds r1, 0x4E
	asrs r3, r0, 16
	lsrs r0, 16
	strh r0, [r1]
	ldr r1, [r2, 0x38]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 3
	adds r2, r0
	adds r3, 0x2
	adds r2, 0x50
	strh r3, [r2]
	bl ResetUnusedInputStruct
	ldr r0, [r4]
	adds r0, 0x40
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0802BF9C: .4byte gUnknown_203B2D8
	thumb_func_end sub_802BF30

	thumb_func_start CreateMailMenu
CreateMailMenu:
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	sub sp, 0xDC
	ldr r4, _0802C060
	ldr r0, [r4]
	ldr r0, [r0, 0x38]
	bl sub_8008C54
	ldr r0, [r4]
	ldr r0, [r0, 0x38]
	bl sub_80073B8
	ldr r1, [r4]
	movs r2, 0x22
	ldrsh r0, [r1, r2]
	lsls r0, 3
	adds r0, 0xA
	ldr r2, _0802C064
	ldr r3, [r1, 0x38]
	movs r1, 0
	str r1, [sp]
	bl xxx_call_draw_string
	movs r6, 0
	ldr r0, [r4]
	movs r3, 0x1E
	ldrsh r0, [r0, r3]
	cmp r6, r0
	bge _0802C09A
	adds r7, r4, 0
	ldr r0, _0802C068
	mov r9, r0
	add r1, sp, 0x5C
	mov r8, r1
_0802BFE8:
	ldr r1, [r7]
	movs r3, 0x22
	ldrsh r2, [r1, r3]
	movs r3, 0x20
	ldrsh r0, [r1, r3]
	muls r0, r2
	adds r0, r6
	adds r1, r0
	ldrb r0, [r1]
	bl sub_8095FE8
	adds r5, r0, 0
	ldr r0, [r7]
	ldr r1, [r0, 0x38]
	str r1, [sp, 0x4]
	adds r0, 0x4
	adds r1, r6, 0
	bl sub_8013800
	str r0, [sp, 0x4C]
	ldrb r0, [r5]
	cmp r0, 0x1
	bne _0802C06C
	ldr r0, [r7]
	adds r0, 0x4
	adds r1, r6, 0
	bl sub_8013800
	adds r4, r0, 0
	ldr r0, [r7]
	ldr r3, [r0, 0x38]
	movs r0, 0xA
	adds r1, r4, 0
	movs r2, 0x6
	bl sub_803B6B0
	bl sub_808D33C
	adds r1, r0, 0
	mov r0, r9
	bl sub_808DA34
	ldrb r0, [r5, 0x5]
	bl GetPokemonMailHeadline
	adds r1, r0, 0
	mov r0, r8
	mov r2, r9
	bl sub_800D158
	ldr r0, [r7]
	ldr r3, [r0, 0x38]
	movs r0, 0
	str r0, [sp]
	movs r0, 0x15
	adds r1, r4, 0
	mov r2, r8
	bl xxx_call_draw_string
	b _0802C08E
	.align 2, 0
_0802C060: .4byte gUnknown_203B2D8
_0802C064: .4byte gMailboxText
_0802C068: .4byte gAvailablePokemonNames
_0802C06C:
	adds r0, r5, 0
	add r1, sp, 0x4
	bl sub_803B35C
	adds r0, r5, 0
	bl sub_80968B0
	lsls r0, 24
	cmp r0, 0
	beq _0802C088
	mov r1, sp
	adds r1, 0x47
	movs r0, 0x2
	strb r0, [r1]
_0802C088:
	add r0, sp, 0x4
	bl sub_803B6D4
_0802C08E:
	adds r6, 0x1
	ldr r0, [r7]
	movs r1, 0x1E
	ldrsh r0, [r0, r1]
	cmp r6, r0
	blt _0802BFE8
_0802C09A:
	ldr r0, _0802C0B4
	ldr r0, [r0]
	ldr r0, [r0, 0x38]
	bl sub_80073E0
	add sp, 0xDC
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_0802C0B4: .4byte gUnknown_203B2D8
	thumb_func_end CreateMailMenu

	thumb_func_start sub_802C0B8
sub_802C0B8:
	push {r4,r5,lr}
	movs r5, 0
	movs r4, 0
_0802C0BE:
	lsls r0, r4, 24
	lsrs r0, 24
	bl sub_8096000
	lsls r0, 24
	cmp r0, 0
	bne _0802C0D6
	ldr r0, _0802C0E4
	ldr r0, [r0]
	adds r0, r5
	strb r4, [r0]
	adds r5, 0x1
_0802C0D6:
	adds r4, 0x1
	cmp r4, 0x3
	ble _0802C0BE
	adds r0, r5, 0
	pop {r4,r5}
	pop {r1}
	bx r1
	.align 2, 0
_0802C0E4: .4byte gUnknown_203B2D8
	thumb_func_end sub_802C0B8

	thumb_func_start sub_802C0E8
sub_802C0E8:
	push {r4,lr}
	movs r4, 0
_0802C0EC:
	lsls r0, r4, 24
	lsrs r0, 24
	bl sub_8096000
	lsls r0, 24
	cmp r0, 0
	bne _0802C0FE
	movs r0, 0
	b _0802C106
_0802C0FE:
	adds r4, 0x1
	cmp r4, 0x3
	ble _0802C0EC
	movs r0, 0x1
_0802C106:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_802C0E8

	thumb_func_start sub_802C10C
sub_802C10C:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	adds r6, r0, 0
	adds r4, r1, 0
	mov r8, r2
	bl sub_802C4A4
	lsls r0, 24
	cmp r0, 0
	beq _0802C126
	movs r0, 0
	b _0802C1CC
_0802C126:
	ldr r5, _0802C1D8
	ldr r0, [r5]
	cmp r0, 0
	bne _0802C138
	movs r0, 0xA8
	movs r1, 0x8
	bl MemoryAlloc
	str r0, [r5]
_0802C138:
	ldr r0, [r5]
	str r6, [r0, 0x3C]
	lsls r1, r6, 1
	adds r1, r6
	lsls r1, 3
	adds r1, 0x44
	adds r1, r0, r1
	str r1, [r0, 0x40]
	adds r0, 0x44
	bl sub_8006518
	ldr r1, [r5]
	ldr r2, [r1, 0x3C]
	lsls r0, r2, 1
	adds r0, r2
	lsls r0, 3
	adds r1, r0
	adds r1, 0x44
	ldr r0, _0802C1DC
	ldm r0!, {r2,r3,r7}
	stm r1!, {r2,r3,r7}
	ldm r0!, {r2,r3,r7}
	stm r1!, {r2,r3,r7}
	ldr r2, [r5]
	ldr r1, [r2, 0x40]
	adds r0, r2, 0
	adds r0, 0xA4
	str r0, [r1, 0x14]
	cmp r4, 0
	beq _0802C186
	ldr r1, [r2, 0x3C]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 3
	adds r1, r2, 0
	adds r1, 0x4C
	adds r1, r0
	ldr r0, [r4]
	str r0, [r1]
_0802C186:
	ldr r0, [r5]
	ldr r0, [r0, 0x40]
	mov r1, r8
	bl sub_8012D34
	bl ResetUnusedInputStruct
	ldr r0, [r5]
	adds r0, 0x44
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	ldr r4, [r5]
	adds r4, 0x8
	bl sub_802C474
	adds r1, r0, 0
	adds r0, r4, 0
	mov r2, r8
	adds r3, r6, 0
	bl sub_8013848
	ldr r0, [r5]
	ldr r1, _0802C1E0
	ldrh r1, [r1]
	strh r1, [r0, 0x20]
	adds r0, 0x8
	bl sub_8013984
	bl sub_802C328
	bl sub_802C39C
	movs r0, 0x1
_0802C1CC:
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r1}
	bx r1
	.align 2, 0
_0802C1D8: .4byte gUnknown_203B2E0
_0802C1DC: .4byte gUnknown_80DFCB4
_0802C1E0: .4byte gUnknown_203B2E4
	thumb_func_end sub_802C10C

	thumb_func_start sub_802C1E4
sub_802C1E4:
	push {lr}
	lsls r0, 24
	cmp r0, 0
	bne _0802C200
	ldr r0, _0802C1FC
	ldr r0, [r0]
	adds r0, 0x8
	bl sub_8013660
	movs r0, 0
	b _0802C266
	.align 2, 0
_0802C1FC: .4byte gUnknown_203B2E0
_0802C200:
	ldr r0, _0802C218
	ldr r0, [r0]
	adds r0, 0x8
	bl GetKeyPress
	cmp r0, 0x2
	beq _0802C222
	cmp r0, 0x2
	bgt _0802C21C
	cmp r0, 0x1
	beq _0802C22C
	b _0802C240
	.align 2, 0
_0802C218: .4byte gUnknown_203B2E0
_0802C21C:
	cmp r0, 0x4
	beq _0802C236
	b _0802C240
_0802C222:
	movs r0, 0x1
	bl sub_80119D4
	movs r0, 0x2
	b _0802C266
_0802C22C:
	movs r0, 0
	bl sub_80119D4
	movs r0, 0x3
	b _0802C266
_0802C236:
	movs r0, 0x4
	bl sub_80119D4
	movs r0, 0x4
	b _0802C266
_0802C240:
	ldr r0, _0802C258
	ldr r0, [r0]
	adds r0, 0x8
	movs r1, 0x1
	bl sub_80138B8
	lsls r0, 24
	cmp r0, 0
	bne _0802C25C
	movs r0, 0
	b _0802C266
	.align 2, 0
_0802C258: .4byte gUnknown_203B2E0
_0802C25C:
	bl sub_802C328
	bl sub_802C39C
	movs r0, 0x1
_0802C266:
	pop {r1}
	bx r1
	thumb_func_end sub_802C1E4

	thumb_func_start sub_802C26C
sub_802C26C:
	ldr r0, _0802C288
	ldr r1, [r0]
	movs r0, 0x26
	ldrsh r2, [r1, r0]
	movs r3, 0x24
	ldrsh r0, [r1, r3]
	muls r0, r2
	movs r3, 0x20
	ldrsh r2, [r1, r3]
	adds r0, r2
	adds r1, r0
	ldrb r0, [r1]
	bx lr
	.align 2, 0
_0802C288: .4byte gUnknown_203B2E0
	thumb_func_end sub_802C26C

	thumb_func_start sub_802C28C
sub_802C28C:
	push {r4,r5,lr}
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	bl ResetUnusedInputStruct
	ldr r5, _0802C2D0
	ldr r0, [r5]
	adds r0, 0x44
	movs r1, 0
	movs r2, 0
	bl sub_800641C
	bl sub_802C474
	adds r1, r0, 0
	ldr r0, [r5]
	strh r1, [r0, 0x2A]
	adds r0, 0x8
	bl sub_8013984
	bl sub_802C328
	bl sub_802C39C
	cmp r4, 0
	beq _0802C2CA
	ldr r0, [r5]
	adds r0, 0x8
	bl AddMenuCursorSprite
_0802C2CA:
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_0802C2D0: .4byte gUnknown_203B2E0
	thumb_func_end sub_802C28C

	thumb_func_start sub_802C2D4
sub_802C2D4:
	push {r4,r5,lr}
	ldr r4, _0802C31C
	ldr r2, [r4]
	cmp r2, 0
	beq _0802C314
	ldr r1, _0802C320
	ldrh r0, [r2, 0x20]
	strh r0, [r1]
	ldr r0, [r2, 0x3C]
	lsls r1, r0, 1
	adds r1, r0
	lsls r1, 3
	adds r1, r2, r1
	adds r1, 0x44
	ldr r0, _0802C324
	ldm r0!, {r2,r3,r5}
	stm r1!, {r2,r3,r5}
	ldm r0!, {r2,r3,r5}
	stm r1!, {r2,r3,r5}
	bl ResetUnusedInputStruct
	ldr r0, [r4]
	adds r0, 0x44
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	ldr r0, [r4]
	bl MemoryFree
	movs r0, 0
	str r0, [r4]
_0802C314:
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_0802C31C: .4byte gUnknown_203B2E0
_0802C320: .4byte gUnknown_203B2E4
_0802C324: .4byte gUnknown_80DFC9C
	thumb_func_end sub_802C2D4

	thumb_func_start sub_802C328
sub_802C328:
	push {r4,lr}
	ldr r4, _0802C398
	ldr r0, [r4]
	ldrh r1, [r0, 0x28]
	adds r0, 0xA4
	movs r2, 0
	strb r1, [r0]
	ldr r0, [r4]
	ldrh r1, [r0, 0x26]
	adds r0, 0xA5
	strb r1, [r0]
	ldr r0, [r4]
	adds r0, 0xA6
	movs r1, 0xC
	strb r1, [r0]
	ldr r0, [r4]
	adds r0, 0xA7
	strb r2, [r0]
	ldr r0, [r4]
	movs r1, 0x22
	ldrsh r0, [r0, r1]
	movs r1, 0x18
	bl sub_8009614
	adds r0, 0x2
	lsls r0, 16
	ldr r2, [r4]
	ldr r3, [r2, 0x3C]
	lsls r1, r3, 1
	adds r1, r3
	lsls r1, 3
	adds r1, r2, r1
	adds r1, 0x52
	asrs r3, r0, 16
	lsrs r0, 16
	strh r0, [r1]
	ldr r1, [r2, 0x3C]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 3
	adds r2, r0
	adds r3, 0x2
	adds r2, 0x54
	strh r3, [r2]
	bl ResetUnusedInputStruct
	ldr r0, [r4]
	adds r0, 0x44
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0802C398: .4byte gUnknown_203B2E0
	thumb_func_end sub_802C328

	thumb_func_start sub_802C39C
sub_802C39C:
	push {r4-r7,lr}
	sub sp, 0x60
	ldr r7, _0802C3F8
	ldr r0, [r7]
	ldr r0, [r0, 0x3C]
	bl sub_8008C54
	ldr r0, [r7]
	ldr r0, [r0, 0x3C]
	bl sub_80073B8
	ldr r0, [r7]
	movs r1, 0x26
	ldrsh r4, [r0, r1]
	lsls r4, 3
	adds r5, r4, 0
	adds r5, 0xA
	ldr r2, _0802C3FC
	ldr r3, [r0, 0x3C]
	movs r0, 0
	str r0, [sp]
	adds r0, r5, 0
	movs r1, 0
	bl xxx_call_draw_string
	adds r4, 0x4
	ldr r1, [r7]
	adds r0, r1, 0
	adds r0, 0xA6
	ldrb r0, [r0]
	lsls r0, 3
	adds r5, r4, r0
	movs r3, 0x26
	ldrsh r2, [r1, r3]
	adds r2, 0x1
	movs r0, 0x7
	str r0, [sp]
	ldr r0, [r1, 0x3C]
	str r0, [sp, 0x4]
	adds r0, r5, 0
	movs r1, 0
	movs r3, 0x2
	bl sub_8012BC4
	movs r6, 0
	b _0802C452
	.align 2, 0
_0802C3F8: .4byte gUnknown_203B2E0
_0802C3FC: .4byte gBulletinBoardText
_0802C400:
	ldr r1, [r7]
	movs r3, 0x26
	ldrsh r2, [r1, r3]
	movs r3, 0x24
	ldrsh r0, [r1, r3]
	muls r0, r2
	adds r0, r6
	adds r1, r0
	ldrb r5, [r1]
	adds r0, r5, 0
	bl sub_8096574
	adds r4, r0, 0
	ldr r0, [r7]
	ldr r1, [r0, 0x3C]
	str r1, [sp, 0x8]
	adds r0, 0x8
	adds r1, r6, 0
	bl sub_8013800
	str r0, [sp, 0x50]
	adds r0, r4, 0
	add r1, sp, 0x8
	bl sub_803B35C
	adds r0, r5, 0
	bl sub_8096574
	bl sub_80968B0
	lsls r0, 24
	cmp r0, 0
	beq _0802C44A
	mov r1, sp
	adds r1, 0x4B
	movs r0, 0x2
	strb r0, [r1]
_0802C44A:
	add r0, sp, 0x8
	bl sub_803B6D4
	adds r6, 0x1
_0802C452:
	ldr r0, [r7]
	movs r1, 0x22
	ldrsh r0, [r0, r1]
	cmp r6, r0
	blt _0802C400
	ldr r0, _0802C470
	ldr r0, [r0]
	ldr r0, [r0, 0x3C]
	bl sub_80073E0
	add sp, 0x60
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_0802C470: .4byte gUnknown_203B2E0
	thumb_func_end sub_802C39C

	thumb_func_start sub_802C474
sub_802C474:
	push {r4,r5,lr}
	movs r5, 0
	movs r4, 0
_0802C47A:
	lsls r0, r4, 24
	lsrs r0, 24
	bl sub_809658C
	lsls r0, 24
	cmp r0, 0
	bne _0802C492
	ldr r0, _0802C4A0
	ldr r0, [r0]
	adds r0, r5
	strb r4, [r0]
	adds r5, 0x1
_0802C492:
	adds r4, 0x1
	cmp r4, 0x7
	ble _0802C47A
	adds r0, r5, 0
	pop {r4,r5}
	pop {r1}
	bx r1
	.align 2, 0
_0802C4A0: .4byte gUnknown_203B2E0
	thumb_func_end sub_802C474

	thumb_func_start sub_802C4A4
sub_802C4A4:
	push {r4,lr}
	movs r4, 0
_0802C4A8:
	lsls r0, r4, 24
	lsrs r0, 24
	bl sub_809658C
	lsls r0, 24
	cmp r0, 0
	bne _0802C4BA
	movs r0, 0
	b _0802C4C2
_0802C4BA:
	adds r4, 0x1
	cmp r4, 0x7
	ble _0802C4A8
	movs r0, 0x1
_0802C4C2:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_802C4A4

	thumb_func_start sub_802C4C8
sub_802C4C8:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	adds r6, r0, 0
	adds r4, r1, 0
	mov r8, r2
	bl sub_802C83C
	lsls r0, 24
	cmp r0, 0
	beq _0802C4E2
	movs r0, 0
	b _0802C580
_0802C4E2:
	ldr r5, _0802C58C
	movs r0, 0xA8
	movs r1, 0x8
	bl MemoryAlloc
	str r0, [r5]
	str r6, [r0, 0x3C]
	lsls r1, r6, 1
	adds r1, r6
	lsls r1, 3
	adds r1, 0x44
	adds r1, r0, r1
	str r1, [r0, 0x40]
	adds r0, 0x44
	bl sub_8006518
	ldr r1, [r5]
	ldr r2, [r1, 0x3C]
	lsls r0, r2, 1
	adds r0, r2
	lsls r0, 3
	adds r1, r0
	adds r1, 0x44
	ldr r0, _0802C590
	ldm r0!, {r2,r3,r7}
	stm r1!, {r2,r3,r7}
	ldm r0!, {r2,r3,r7}
	stm r1!, {r2,r3,r7}
	ldr r2, [r5]
	ldr r1, [r2, 0x40]
	adds r0, r2, 0
	adds r0, 0xA4
	str r0, [r1, 0x14]
	cmp r4, 0
	beq _0802C53A
	ldr r1, [r2, 0x3C]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 3
	adds r1, r2, 0
	adds r1, 0x4C
	adds r1, r0
	ldr r0, [r4]
	str r0, [r1]
_0802C53A:
	ldr r0, [r5]
	ldr r0, [r0, 0x40]
	mov r1, r8
	bl sub_8012D34
	bl ResetUnusedInputStruct
	ldr r0, [r5]
	adds r0, 0x44
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	ldr r4, [r5]
	adds r4, 0x8
	bl sub_802C80C
	adds r1, r0, 0
	adds r0, r4, 0
	mov r2, r8
	adds r3, r6, 0
	bl sub_8013848
	ldr r0, [r5]
	ldr r1, _0802C594
	ldrh r1, [r1]
	strh r1, [r0, 0x20]
	adds r0, 0x8
	bl sub_8013984
	bl sub_802C6DC
	bl sub_802C750
	movs r0, 0x1
_0802C580:
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r1}
	bx r1
	.align 2, 0
_0802C58C: .4byte gUnknown_203B2E8
_0802C590: .4byte gUnknown_80DFCFC
_0802C594: .4byte gUnknown_203B2EC
	thumb_func_end sub_802C4C8

	thumb_func_start sub_802C598
sub_802C598:
	push {lr}
	lsls r0, 24
	cmp r0, 0
	bne _0802C5B4
	ldr r0, _0802C5B0
	ldr r0, [r0]
	adds r0, 0x8
	bl sub_8013660
	movs r0, 0
	b _0802C61A
	.align 2, 0
_0802C5B0: .4byte gUnknown_203B2E8
_0802C5B4:
	ldr r0, _0802C5CC
	ldr r0, [r0]
	adds r0, 0x8
	bl GetKeyPress
	cmp r0, 0x2
	beq _0802C5D6
	cmp r0, 0x2
	bgt _0802C5D0
	cmp r0, 0x1
	beq _0802C5E0
	b _0802C5F4
	.align 2, 0
_0802C5CC: .4byte gUnknown_203B2E8
_0802C5D0:
	cmp r0, 0x4
	beq _0802C5EA
	b _0802C5F4
_0802C5D6:
	movs r0, 0x1
	bl sub_80119D4
	movs r0, 0x2
	b _0802C61A
_0802C5E0:
	movs r0, 0
	bl sub_80119D4
	movs r0, 0x3
	b _0802C61A
_0802C5EA:
	movs r0, 0x4
	bl sub_80119D4
	movs r0, 0x4
	b _0802C61A
_0802C5F4:
	ldr r0, _0802C60C
	ldr r0, [r0]
	adds r0, 0x8
	movs r1, 0x1
	bl sub_80138B8
	lsls r0, 24
	cmp r0, 0
	bne _0802C610
	movs r0, 0
	b _0802C61A
	.align 2, 0
_0802C60C: .4byte gUnknown_203B2E8
_0802C610:
	bl sub_802C6DC
	bl sub_802C750
	movs r0, 0x1
_0802C61A:
	pop {r1}
	bx r1
	thumb_func_end sub_802C598

	thumb_func_start sub_802C620
sub_802C620:
	ldr r0, _0802C63C
	ldr r1, [r0]
	movs r0, 0x26
	ldrsh r2, [r1, r0]
	movs r3, 0x24
	ldrsh r0, [r1, r3]
	muls r0, r2
	movs r3, 0x20
	ldrsh r2, [r1, r3]
	adds r0, r2
	adds r1, r0
	ldrb r0, [r1]
	bx lr
	.align 2, 0
_0802C63C: .4byte gUnknown_203B2E8
	thumb_func_end sub_802C620

	thumb_func_start sub_802C640
sub_802C640:
	push {r4,r5,lr}
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	bl ResetUnusedInputStruct
	ldr r5, _0802C684
	ldr r0, [r5]
	adds r0, 0x44
	movs r1, 0
	movs r2, 0
	bl sub_800641C
	bl sub_802C80C
	adds r1, r0, 0
	ldr r0, [r5]
	strh r1, [r0, 0x2A]
	adds r0, 0x8
	bl sub_8013984
	bl sub_802C6DC
	bl sub_802C750
	cmp r4, 0
	beq _0802C67E
	ldr r0, [r5]
	adds r0, 0x8
	bl AddMenuCursorSprite
_0802C67E:
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_0802C684: .4byte gUnknown_203B2E8
	thumb_func_end sub_802C640

	thumb_func_start sub_802C688
sub_802C688:
	push {r4,r5,lr}
	ldr r4, _0802C6D0
	ldr r2, [r4]
	cmp r2, 0
	beq _0802C6C8
	ldr r1, _0802C6D4
	ldrh r0, [r2, 0x20]
	strh r0, [r1]
	ldr r0, [r2, 0x3C]
	lsls r1, r0, 1
	adds r1, r0
	lsls r1, 3
	adds r1, r2, r1
	adds r1, 0x44
	ldr r0, _0802C6D8
	ldm r0!, {r2,r3,r5}
	stm r1!, {r2,r3,r5}
	ldm r0!, {r2,r3,r5}
	stm r1!, {r2,r3,r5}
	bl ResetUnusedInputStruct
	ldr r0, [r4]
	adds r0, 0x44
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	ldr r0, [r4]
	bl MemoryFree
	movs r0, 0
	str r0, [r4]
_0802C6C8:
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_0802C6D0: .4byte gUnknown_203B2E8
_0802C6D4: .4byte gUnknown_203B2EC
_0802C6D8: .4byte gUnknown_80DFCE4
	thumb_func_end sub_802C688

	thumb_func_start sub_802C6DC
sub_802C6DC:
	push {r4,lr}
	ldr r4, _0802C74C
	ldr r0, [r4]
	ldrh r1, [r0, 0x28]
	adds r0, 0xA4
	movs r2, 0
	strb r1, [r0]
	ldr r0, [r4]
	ldrh r1, [r0, 0x26]
	adds r0, 0xA5
	strb r1, [r0]
	ldr r0, [r4]
	adds r0, 0xA6
	movs r1, 0xC
	strb r1, [r0]
	ldr r0, [r4]
	adds r0, 0xA7
	strb r2, [r0]
	ldr r0, [r4]
	movs r1, 0x22
	ldrsh r0, [r0, r1]
	movs r1, 0x18
	bl sub_8009614
	adds r0, 0x2
	lsls r0, 16
	ldr r2, [r4]
	ldr r3, [r2, 0x3C]
	lsls r1, r3, 1
	adds r1, r3
	lsls r1, 3
	adds r1, r2, r1
	adds r1, 0x52
	asrs r3, r0, 16
	lsrs r0, 16
	strh r0, [r1]
	ldr r1, [r2, 0x3C]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 3
	adds r2, r0
	adds r3, 0x2
	adds r2, 0x54
	strh r3, [r2]
	bl ResetUnusedInputStruct
	ldr r0, [r4]
	adds r0, 0x44
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0802C74C: .4byte gUnknown_203B2E8
	thumb_func_end sub_802C6DC

	thumb_func_start sub_802C750
sub_802C750:
	push {r4-r6,lr}
	sub sp, 0x60
	ldr r6, _0802C7AC
	ldr r0, [r6]
	ldr r0, [r0, 0x3C]
	bl sub_8008C54
	ldr r0, [r6]
	ldr r0, [r0, 0x3C]
	bl sub_80073B8
	ldr r0, [r6]
	movs r1, 0x26
	ldrsh r4, [r0, r1]
	lsls r4, 3
	adds r5, r4, 0
	adds r5, 0xA
	ldr r2, _0802C7B0
	ldr r3, [r0, 0x3C]
	movs r0, 0
	str r0, [sp]
	adds r0, r5, 0
	movs r1, 0
	bl xxx_call_draw_string
	adds r4, 0x4
	ldr r1, [r6]
	adds r0, r1, 0
	adds r0, 0xA6
	ldrb r0, [r0]
	lsls r0, 3
	adds r5, r4, r0
	movs r3, 0x26
	ldrsh r2, [r1, r3]
	adds r2, 0x1
	movs r0, 0x7
	str r0, [sp]
	ldr r0, [r1, 0x3C]
	str r0, [sp, 0x4]
	adds r0, r5, 0
	movs r1, 0
	movs r3, 0x2
	bl sub_8012BC4
	movs r5, 0
	b _0802C7EC
	.align 2, 0
_0802C7AC: .4byte gUnknown_203B2E8
_0802C7B0: .4byte gUnknown_80DFD14
_0802C7B4:
	ldr r1, [r6]
	movs r3, 0x26
	ldrsh r2, [r1, r3]
	movs r3, 0x24
	ldrsh r0, [r1, r3]
	muls r0, r2
	adds r0, r5
	adds r1, r0
	ldrb r0, [r1]
	bl sub_8096AB4
	adds r4, r0, 0
	ldr r0, [r6]
	ldr r1, [r0, 0x3C]
	str r1, [sp, 0x8]
	adds r0, 0x8
	adds r1, r5, 0
	bl sub_8013800
	str r0, [sp, 0x50]
	adds r0, r4, 0
	add r1, sp, 0x8
	bl sub_803B35C
	add r0, sp, 0x8
	bl sub_803B6D4
	adds r5, 0x1
_0802C7EC:
	ldr r0, [r6]
	movs r1, 0x22
	ldrsh r0, [r0, r1]
	cmp r5, r0
	blt _0802C7B4
	ldr r0, _0802C808
	ldr r0, [r0]
	ldr r0, [r0, 0x3C]
	bl sub_80073E0
	add sp, 0x60
	pop {r4-r6}
	pop {r0}
	bx r0
	.align 2, 0
_0802C808: .4byte gUnknown_203B2E8
	thumb_func_end sub_802C750

	thumb_func_start sub_802C80C
sub_802C80C:
	push {r4,r5,lr}
	movs r5, 0
	movs r4, 0
_0802C812:
	lsls r0, r4, 24
	lsrs r0, 24
	bl sub_8096ACC
	lsls r0, 24
	cmp r0, 0
	bne _0802C82A
	ldr r0, _0802C838
	ldr r0, [r0]
	adds r0, r5
	strb r4, [r0]
	adds r5, 0x1
_0802C82A:
	adds r4, 0x1
	cmp r4, 0x7
	ble _0802C812
	adds r0, r5, 0
	pop {r4,r5}
	pop {r1}
	bx r1
	.align 2, 0
_0802C838: .4byte gUnknown_203B2E8
	thumb_func_end sub_802C80C

	thumb_func_start sub_802C83C
sub_802C83C:
	push {r4,lr}
	movs r4, 0
_0802C840:
	lsls r0, r4, 24
	lsrs r0, 24
	bl sub_8096ACC
	lsls r0, 24
	cmp r0, 0
	bne _0802C852
	movs r0, 0
	b _0802C85A
_0802C852:
	adds r4, 0x1
	cmp r4, 0x7
	ble _0802C840
	movs r0, 0x1
_0802C85A:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_802C83C

	thumb_func_start sub_802C860
sub_802C860:
	push {r4-r6,lr}
	adds r6, r0, 0
	bl sub_802C83C
	lsls r0, 24
	lsrs r5, r0, 24
	cmp r5, 0
	bne _0802C890
	ldr r4, _0802C88C
	movs r0, 0xFE
	lsls r0, 1
	movs r1, 0x8
	bl MemoryAlloc
	str r0, [r4]
	str r5, [r0, 0x68]
	str r6, [r0]
	movs r0, 0
	bl sub_802C910
	movs r0, 0x1
	b _0802C892
	.align 2, 0
_0802C88C: .4byte gUnknown_203B2F0
_0802C890:
	movs r0, 0
_0802C892:
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end sub_802C860

	thumb_func_start sub_802C898
sub_802C898:
	push {lr}
	ldr r0, _0802C8B0
	ldr r0, [r0]
	ldr r0, [r0, 0x4]
	cmp r0, 0x5
	bhi _0802C8E8
	lsls r0, 2
	ldr r1, _0802C8B4
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0802C8B0: .4byte gUnknown_203B2F0
_0802C8B4: .4byte _0802C8B8
	.align 2, 0
_0802C8B8:
	.4byte _0802C8D0
	.4byte _0802C8D0
	.4byte _0802C8D6
	.4byte _0802C8DC
	.4byte _0802C8E2
	.4byte _0802C8E8
_0802C8D0:
	bl sub_802CC00
	b _0802C8EC
_0802C8D6:
	bl sub_802CC70
	b _0802C8EC
_0802C8DC:
	bl sub_802CD38
	b _0802C8EC
_0802C8E2:
	bl sub_802CDB8
	b _0802C8EC
_0802C8E8:
	movs r0, 0x3
	b _0802C8EE
_0802C8EC:
	movs r0, 0
_0802C8EE:
	pop {r1}
	bx r1
	thumb_func_end sub_802C898

	thumb_func_start sub_802C8F4
sub_802C8F4:
	push {r4,lr}
	ldr r4, _0802C90C
	ldr r0, [r4]
	cmp r0, 0
	beq _0802C906
	bl MemoryFree
	movs r0, 0
	str r0, [r4]
_0802C906:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0802C90C: .4byte gUnknown_203B2F0
	thumb_func_end sub_802C8F4

	thumb_func_start sub_802C910
sub_802C910:
	push {lr}
	ldr r1, _0802C924
	ldr r1, [r1]
	str r0, [r1, 0x4]
	bl sub_802C928
	bl sub_802C9D8
	pop {r0}
	bx r0
	.align 2, 0
_0802C924: .4byte gUnknown_203B2F0
	thumb_func_end sub_802C910

	thumb_func_start sub_802C928
sub_802C928:
	push {r4-r7,lr}
	ldr r4, _0802C94C
	ldr r0, [r4]
	movs r1, 0xCE
	lsls r1, 1
	adds r0, r1
	bl sub_8006518
	ldr r1, [r4]
	ldr r0, [r1, 0x4]
	cmp r0, 0x2
	beq _0802C954
	cmp r0, 0x3
	beq _0802C980
	movs r2, 0
	ldr r3, _0802C950
	b _0802C998
	.align 2, 0
_0802C94C: .4byte gUnknown_203B2F0
_0802C950: .4byte gUnknown_80DFD28
_0802C954:
	bl sub_802CAA4
	ldr r2, [r4]
	movs r0, 0xE6
	lsls r0, 1
	adds r2, r0
	ldr r1, _0802C97C
	ldm r1!, {r3,r5,r6}
	stm r2!, {r3,r5,r6}
	ldm r1!, {r3,r5,r7}
	stm r2!, {r3,r5,r7}
	ldr r1, [r4]
	adds r0, r1, r0
	movs r6, 0x86
	lsls r6, 1
	adds r1, r6
	bl sub_8012CAC
	b _0802C9B8
	.align 2, 0
_0802C97C: .4byte gUnknown_80DFD40
_0802C980:
	movs r7, 0xF2
	lsls r7, 1
	adds r1, r7
	ldr r0, _0802C994
	ldm r0!, {r2-r4}
	stm r1!, {r2-r4}
	ldm r0!, {r5-r7}
	stm r1!, {r5-r7}
	b _0802C9B8
	.align 2, 0
_0802C994: .4byte gUnknown_80DFD58
_0802C998:
	ldr r0, [r4]
	lsls r1, r2, 1
	adds r1, r2
	lsls r1, 3
	adds r0, r1
	movs r1, 0xCE
	lsls r1, 1
	adds r0, r1
	adds r1, r3, 0
	ldm r1!, {r5-r7}
	stm r0!, {r5-r7}
	ldm r1!, {r5-r7}
	stm r0!, {r5-r7}
	adds r2, 0x1
	cmp r2, 0x3
	ble _0802C998
_0802C9B8:
	bl ResetUnusedInputStruct
	ldr r0, _0802C9D4
	ldr r0, [r0]
	movs r1, 0xCE
	lsls r1, 1
	adds r0, r1
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_0802C9D4: .4byte gUnknown_203B2F0
	thumb_func_end sub_802C928

	thumb_func_start sub_802C9D8
sub_802C9D8:
	push {r4,lr}
	sub sp, 0x8
	ldr r1, _0802C9F4
	ldr r0, [r1]
	ldr r0, [r0, 0x4]
	adds r4, r1, 0
	cmp r0, 0x5
	bhi _0802CA9C
	lsls r0, 2
	ldr r1, _0802C9F8
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0802C9F4: .4byte gUnknown_203B2F0
_0802C9F8: .4byte _0802C9FC
	.align 2, 0
_0802C9FC:
	.4byte _0802CA14
	.4byte _0802CA20
	.4byte _0802CA28
	.4byte _0802CA48
	.4byte _0802CA80
	.4byte _0802CA9C
_0802CA14:
	movs r0, 0
	movs r1, 0
	movs r2, 0x4
	bl sub_802C4C8
	b _0802CA9C
_0802CA20:
	movs r0, 0x1
	bl sub_802C640
	b _0802CA9C
_0802CA28:
	bl sub_802C750
	ldr r0, _0802CA44
	ldr r2, [r0]
	adds r0, r2, 0
	adds r0, 0x6C
	movs r3, 0x86
	lsls r3, 1
	adds r1, r2, r3
	ldr r2, [r2, 0x68]
	str r2, [sp]
	movs r2, 0x2
	b _0802CA6E
	.align 2, 0
_0802CA44: .4byte gUnknown_203B2F0
_0802CA48:
	bl sub_802CBAC
	bl sub_802C750
	ldr r4, _0802CA7C
	ldr r0, [r4]
	adds r0, 0x6C
	movs r1, 0
	bl sub_8012EA4
	ldr r1, [r4]
	adds r0, r1, 0
	adds r0, 0xBC
	movs r2, 0xA6
	lsls r2, 1
	adds r1, r2
	movs r2, 0x6
	str r2, [sp]
	movs r2, 0x3
_0802CA6E:
	str r2, [sp, 0x4]
	movs r2, 0
	movs r3, 0
	bl sub_8012D60
	b _0802CA9C
	.align 2, 0
_0802CA7C: .4byte gUnknown_203B2F0
_0802CA80:
	ldr r0, [r4]
	ldrb r0, [r0, 0xC]
	bl sub_8096AB4
	ldr r1, [r4]
	adds r1, 0x10
	bl sub_803B35C
	ldr r0, [r4]
	movs r1, 0x3
	str r1, [r0, 0x10]
	adds r0, 0x10
	bl sub_802DE84
_0802CA9C:
	add sp, 0x8
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_802C9D8

	thumb_func_start sub_802CAA4
sub_802CAA4:
	push {r4-r7,lr}
	movs r7, 0
	ldr r5, _0802CAC8
	ldr r0, [r5]
	ldrb r0, [r0, 0xC]
	bl sub_8096AB4
	adds r4, r0, 0
	ldr r2, [r5]
	ldr r0, [r2]
	cmp r0, 0
	bne _0802CB26
	ldrb r0, [r4]
	cmp r0, 0x5
	beq _0802CACC
	cmp r0, 0x6
	beq _0802CB10
	b _0802CB26
	.align 2, 0
_0802CAC8: .4byte gUnknown_203B2F0
_0802CACC:
	movs r0, 0x86
	lsls r0, 1
	adds r1, r2, r0
	ldr r0, _0802CAFC
	str r0, [r1]
	adds r0, r4, 0
	bl sub_809693C
	lsls r0, 24
	cmp r0, 0
	bne _0802CAEE
	ldrb r0, [r4, 0x4]
	bl sub_80A2824
	lsls r0, 24
	cmp r0, 0
	bne _0802CB00
_0802CAEE:
	ldr r0, [r5]
	movs r1, 0x88
	lsls r1, 1
	adds r0, r1
	movs r1, 0x1
	negs r1, r1
	b _0802CB0A
	.align 2, 0
_0802CAFC: .4byte gUnknown_80DFD70
_0802CB00:
	ldr r0, [r5]
	movs r1, 0x88
	lsls r1, 1
	adds r0, r1
	movs r1, 0x2
_0802CB0A:
	str r1, [r0]
	adds r7, 0x1
	b _0802CB26
_0802CB10:
	movs r0, 0x86
	lsls r0, 1
	adds r1, r2, r0
	ldr r0, _0802CB9C
	str r0, [r1]
	movs r0, 0x88
	lsls r0, 1
	adds r1, r2, r0
	movs r0, 0x3
	str r0, [r1]
	movs r7, 0x1
_0802CB26:
	ldr r4, _0802CBA0
	ldr r6, [r4]
	lsls r1, r7, 3
	movs r0, 0x86
	lsls r0, 1
	adds r3, r6, r0
	adds r2, r3, r1
	ldr r0, _0802CBA4
	ldr r0, [r0]
	str r0, [r2]
	movs r0, 0x88
	lsls r0, 1
	adds r5, r6, r0
	adds r1, r5, r1
	movs r0, 0x4
	str r0, [r1]
	adds r7, 0x1
	lsls r1, r7, 3
	adds r2, r3, r1
	ldr r0, _0802CBA8
	ldr r0, [r0]
	str r0, [r2]
	adds r1, r5, r1
	movs r0, 0x7
	str r0, [r1]
	adds r7, 0x1
	lsls r1, r7, 3
	adds r3, r1
	movs r0, 0
	str r0, [r3]
	adds r1, r5, r1
	movs r0, 0x1
	str r0, [r1]
	movs r3, 0
	mov r12, r4
	cmp r3, r7
	bge _0802CB8C
	adds r4, r6, 0
	adds r1, r5, 0
	movs r5, 0x1
	negs r5, r5
_0802CB78:
	ldr r2, [r1]
	cmp r2, r5
	beq _0802CB84
	ldr r0, [r4, 0x68]
	cmp r2, r0
	beq _0802CB94
_0802CB84:
	adds r1, 0x8
	adds r3, 0x1
	cmp r3, r7
	blt _0802CB78
_0802CB8C:
	mov r0, r12
	ldr r1, [r0]
	movs r0, 0x7
	str r0, [r1, 0x68]
_0802CB94:
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_0802CB9C: .4byte gUnknown_80DFD7C
_0802CBA0: .4byte gUnknown_203B2F0
_0802CBA4: .4byte gUnknown_80D494C
_0802CBA8: .4byte gUnknown_80D4970
	thumb_func_end sub_802CAA4

	thumb_func_start sub_802CBAC
sub_802CBAC:
	ldr r0, _0802CBF4
	ldr r0, [r0]
	mov r12, r0
	movs r3, 0
	movs r1, 0xA6
	lsls r1, 1
	add r1, r12
	ldr r0, _0802CBF8
	ldr r0, [r0]
	str r0, [r1]
	movs r1, 0xA8
	lsls r1, 1
	add r1, r12
	movs r0, 0x5
	str r0, [r1]
	movs r2, 0x1
	movs r1, 0xAA
	lsls r1, 1
	add r1, r12
	ldr r0, _0802CBFC
	ldr r0, [r0]
	str r0, [r1]
	movs r1, 0xAC
	lsls r1, 1
	add r1, r12
	movs r0, 0x6
	str r0, [r1]
	movs r0, 0xAE
	lsls r0, 1
	add r0, r12
	str r3, [r0]
	movs r0, 0xB0
	lsls r0, 1
	add r0, r12
	str r2, [r0]
	bx lr
	.align 2, 0
_0802CBF4: .4byte gUnknown_203B2F0
_0802CBF8: .4byte gUnknown_80D4920
_0802CBFC: .4byte gUnknown_80D4928
	thumb_func_end sub_802CBAC

	thumb_func_start sub_802CC00
sub_802CC00:
	push {lr}
	movs r0, 0x1
	bl sub_802C598
	cmp r0, 0x4
	bhi _0802CC6A
	lsls r0, 2
	ldr r1, _0802CC18
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0802CC18: .4byte _0802CC1C
	.align 2, 0
_0802CC1C:
	.4byte _0802CC6A
	.4byte _0802CC6A
	.4byte _0802CC60
	.4byte _0802CC30
	.4byte _0802CC48
_0802CC30:
	bl sub_802C620
	ldr r1, _0802CC44
	ldr r1, [r1]
	strb r0, [r1, 0xC]
	movs r0, 0x2
	bl sub_802C910
	b _0802CC6A
	.align 2, 0
_0802CC44: .4byte gUnknown_203B2F0
_0802CC48:
	bl sub_802C620
	ldr r1, _0802CC5C
	ldr r1, [r1]
	strb r0, [r1, 0xC]
	movs r0, 0x4
	bl sub_802C910
	b _0802CC6A
	.align 2, 0
_0802CC5C: .4byte gUnknown_203B2F0
_0802CC60:
	bl sub_802C688
	movs r0, 0x5
	bl sub_802C910
_0802CC6A:
	pop {r0}
	bx r0
	thumb_func_end sub_802CC00

	thumb_func_start sub_802CC70
sub_802CC70:
	push {r4,lr}
	sub sp, 0x4
	movs r0, 0
	str r0, [sp]
	bl sub_802C598
	ldr r4, _0802CCB4
	ldr r0, [r4]
	adds r0, 0x6C
	bl sub_8012FD8
	lsls r0, 24
	cmp r0, 0
	bne _0802CCA0
	ldr r0, [r4]
	adds r0, 0x6C
	mov r1, sp
	bl sub_8013114
	ldr r1, [sp]
	cmp r1, 0x1
	beq _0802CCA0
	ldr r0, [r4]
	str r1, [r0, 0x68]
_0802CCA0:
	ldr r0, [sp]
	subs r0, 0x1
	cmp r0, 0x6
	bhi _0802CD2E
	lsls r0, 2
	ldr r1, _0802CCB8
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0802CCB4: .4byte gUnknown_203B2F0
_0802CCB8: .4byte _0802CCBC
	.align 2, 0
_0802CCBC:
	.4byte _0802CD28
	.4byte _0802CCD8
	.4byte _0802CCF4
	.4byte _0802CD18
	.4byte _0802CD2E
	.4byte _0802CD2E
	.4byte _0802CD20
_0802CCD8:
	ldr r0, _0802CCEC
	bl sub_8011988
	ldr r0, _0802CCF0
	ldr r0, [r0]
	ldrb r0, [r0, 0xC]
	bl sub_8096AB4
	movs r1, 0x6
	b _0802CD06
	.align 2, 0
_0802CCEC: .4byte 0x00000133
_0802CCF0: .4byte gUnknown_203B2F0
_0802CCF4:
	ldr r0, _0802CD10
	bl sub_8011988
	ldr r0, _0802CD14
	ldr r0, [r0]
	ldrb r0, [r0, 0xC]
	bl sub_8096AB4
	movs r1, 0x5
_0802CD06:
	strb r1, [r0]
	movs r0, 0x1
	bl sub_802C910
	b _0802CD2E
	.align 2, 0
_0802CD10: .4byte 0x00000133
_0802CD14: .4byte gUnknown_203B2F0
_0802CD18:
	movs r0, 0x3
	bl sub_802C910
	b _0802CD2E
_0802CD20:
	movs r0, 0x4
	bl sub_802C910
	b _0802CD2E
_0802CD28:
	movs r0, 0x1
	bl sub_802C910
_0802CD2E:
	add sp, 0x4
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_802CC70

	thumb_func_start sub_802CD38
sub_802CD38:
	push {r4,lr}
	sub sp, 0x4
	movs r0, 0
	str r0, [sp]
	bl sub_802C598
	ldr r4, _0802CD78
	ldr r0, [r4]
	adds r0, 0x6C
	bl sub_8012FD8
	ldr r0, [r4]
	adds r0, 0xBC
	bl sub_8012FD8
	lsls r0, 24
	cmp r0, 0
	bne _0802CD66
	ldr r0, [r4]
	adds r0, 0xBC
	mov r1, sp
	bl sub_8013114
_0802CD66:
	ldr r0, [sp]
	cmp r0, 0x5
	beq _0802CD88
	cmp r0, 0x5
	bgt _0802CD7C
	cmp r0, 0x1
	beq _0802CD80
	b _0802CDB0
	.align 2, 0
_0802CD78: .4byte gUnknown_203B2F0
_0802CD7C:
	cmp r0, 0x6
	bne _0802CDB0
_0802CD80:
	movs r0, 0x1
	bl sub_802C910
	b _0802CDB0
_0802CD88:
	ldr r0, [r4]
	ldrb r0, [r0, 0xC]
	bl sub_8096C3C
	bl sub_8096C80
	bl sub_802C83C
	lsls r0, 24
	cmp r0, 0
	beq _0802CDAA
	bl sub_802C688
	movs r0, 0x5
	bl sub_802C910
	b _0802CDB0
_0802CDAA:
	movs r0, 0x1
	bl sub_802C910
_0802CDB0:
	add sp, 0x4
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_802CD38

	thumb_func_start sub_802CDB8
sub_802CDB8:
	push {lr}
	bl sub_802DEE0
	cmp r0, 0x1
	bls _0802CDD0
	cmp r0, 0x3
	bhi _0802CDD0
	bl sub_802DF24
	movs r0, 0x1
	bl sub_802C910
_0802CDD0:
	pop {r0}
	bx r0
	thumb_func_end sub_802CDB8

	thumb_func_start sub_802CDD4
sub_802CDD4:
	push {r4-r6,lr}
	adds r5, r0, 0
	ldr r4, _0802CE54
	ldr r0, [r4]
	cmp r0, 0
	bne _0802CDEA
	movs r0, 0xA0
	movs r1, 0x8
	bl MemoryAlloc
	str r0, [r4]
_0802CDEA:
	ldr r0, [r4]
	str r5, [r0, 0x34]
	lsls r1, r5, 1
	adds r1, r5
	lsls r1, 3
	adds r1, 0x3C
	adds r1, r0, r1
	str r1, [r0, 0x38]
	adds r0, 0x3C
	bl sub_8006518
	ldr r1, [r4]
	ldr r2, [r1, 0x34]
	lsls r0, r2, 1
	adds r0, r2
	lsls r0, 3
	adds r1, r0
	adds r1, 0x3C
	ldr r0, _0802CE58
	ldm r0!, {r2,r3,r6}
	stm r1!, {r2,r3,r6}
	ldm r0!, {r2,r3,r6}
	stm r1!, {r2,r3,r6}
	ldr r1, [r4]
	ldr r0, [r1, 0x38]
	adds r1, 0x9C
	str r1, [r0, 0x14]
	movs r1, 0x4
	bl sub_8012D34
	bl ResetUnusedInputStruct
	ldr r0, [r4]
	adds r0, 0x3C
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	ldr r0, [r4]
	movs r1, 0x5
	movs r2, 0x4
	adds r3, r5, 0
	bl sub_8013848
	bl sub_802CF5C
	bl sub_802CFD0
	movs r0, 0x1
	pop {r4-r6}
	pop {r1}
	bx r1
	.align 2, 0
_0802CE54: .4byte gUnknown_203B2F4
_0802CE58: .4byte gUnknown_80DFDA4
	thumb_func_end sub_802CDD4

	thumb_func_start sub_802CE5C
sub_802CE5C:
	push {r4,lr}
	lsls r0, 24
	cmp r0, 0
	bne _0802CE74
	ldr r0, _0802CE70
	ldr r0, [r0]
	bl sub_8013660
	movs r0, 0
	b _0802CEB4
	.align 2, 0
_0802CE70: .4byte gUnknown_203B2F4
_0802CE74:
	ldr r4, _0802CE90
	ldr r0, [r4]
	bl GetKeyPress
	cmp r0, 0x1
	beq _0802CE94
	cmp r0, 0x2
	bne _0802CE98
	movs r0, 0x1
	bl sub_80119D4
	movs r0, 0x2
	b _0802CEB4
	.align 2, 0
_0802CE90: .4byte gUnknown_203B2F4
_0802CE94:
	movs r0, 0x3
	b _0802CEB4
_0802CE98:
	ldr r0, [r4]
	movs r1, 0x1
	bl sub_80138B8
	lsls r0, 24
	cmp r0, 0
	bne _0802CEAA
	movs r0, 0
	b _0802CEB4
_0802CEAA:
	bl sub_802CF5C
	bl sub_802CFD0
	movs r0, 0x1
_0802CEB4:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_802CE5C

	thumb_func_start sub_802CEBC
sub_802CEBC:
	ldr r0, _0802CED4
	ldr r1, [r0]
	movs r0, 0x1E
	ldrsh r2, [r1, r0]
	movs r3, 0x1C
	ldrsh r0, [r1, r3]
	muls r0, r2
	ldrb r1, [r1, 0x18]
	adds r0, r1
	lsls r0, 24
	lsrs r0, 24
	bx lr
	.align 2, 0
_0802CED4: .4byte gUnknown_203B2F4
	thumb_func_end sub_802CEBC

	thumb_func_start sub_802CED8
sub_802CED8:
	push {r4,r5,lr}
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	bl ResetUnusedInputStruct
	ldr r5, _0802CF10
	ldr r0, [r5]
	adds r0, 0x3C
	movs r1, 0
	movs r2, 0
	bl sub_800641C
	ldr r0, [r5]
	bl sub_8013984
	bl sub_802CF5C
	bl sub_802CFD0
	cmp r4, 0
	beq _0802CF0A
	ldr r0, [r5]
	bl AddMenuCursorSprite
_0802CF0A:
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_0802CF10: .4byte gUnknown_203B2F4
	thumb_func_end sub_802CED8

	thumb_func_start sub_802CF14
sub_802CF14:
	push {r4,r5,lr}
	ldr r4, _0802CF54
	ldr r2, [r4]
	cmp r2, 0
	beq _0802CF4E
	ldr r0, [r2, 0x34]
	lsls r1, r0, 1
	adds r1, r0
	lsls r1, 3
	adds r1, r2, r1
	adds r1, 0x3C
	ldr r0, _0802CF58
	ldm r0!, {r2,r3,r5}
	stm r1!, {r2,r3,r5}
	ldm r0!, {r2,r3,r5}
	stm r1!, {r2,r3,r5}
	bl ResetUnusedInputStruct
	ldr r0, [r4]
	adds r0, 0x3C
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	ldr r0, [r4]
	bl MemoryFree
	movs r0, 0
	str r0, [r4]
_0802CF4E:
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_0802CF54: .4byte gUnknown_203B2F4
_0802CF58: .4byte gUnknown_80DFD8C
	thumb_func_end sub_802CF14

	thumb_func_start sub_802CF5C
sub_802CF5C:
	push {r4,lr}
	ldr r4, _0802CFCC
	ldr r0, [r4]
	ldrh r1, [r0, 0x20]
	adds r0, 0x9C
	movs r2, 0
	strb r1, [r0]
	ldr r0, [r4]
	ldrh r1, [r0, 0x1E]
	adds r0, 0x9D
	strb r1, [r0]
	ldr r0, [r4]
	adds r0, 0x9E
	movs r1, 0xC
	strb r1, [r0]
	ldr r0, [r4]
	adds r0, 0x9F
	strb r2, [r0]
	ldr r0, [r4]
	movs r1, 0x1A
	ldrsh r0, [r0, r1]
	movs r1, 0x18
	bl sub_8009614
	adds r0, 0x2
	lsls r0, 16
	ldr r2, [r4]
	ldr r3, [r2, 0x34]
	lsls r1, r3, 1
	adds r1, r3
	lsls r1, 3
	adds r1, r2, r1
	adds r1, 0x4A
	asrs r3, r0, 16
	lsrs r0, 16
	strh r0, [r1]
	ldr r1, [r2, 0x34]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 3
	adds r2, r0
	adds r3, 0x2
	adds r2, 0x4C
	strh r3, [r2]
	bl ResetUnusedInputStruct
	ldr r0, [r4]
	adds r0, 0x3C
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0802CFCC: .4byte gUnknown_203B2F4
	thumb_func_end sub_802CF5C

	thumb_func_start sub_802CFD0
sub_802CFD0:
	push {r4-r6,lr}
	sub sp, 0x60
	ldr r6, _0802D02C
	ldr r0, [r6]
	ldr r0, [r0, 0x34]
	bl sub_8008C54
	ldr r0, [r6]
	ldr r0, [r0, 0x34]
	bl sub_80073B8
	ldr r0, [r6]
	movs r1, 0x1E
	ldrsh r4, [r0, r1]
	lsls r4, 3
	adds r5, r4, 0
	adds r5, 0xA
	ldr r2, _0802D030
	ldr r3, [r0, 0x34]
	movs r0, 0
	str r0, [sp]
	adds r0, r5, 0
	movs r1, 0
	bl xxx_call_draw_string
	adds r4, 0x4
	ldr r1, [r6]
	adds r0, r1, 0
	adds r0, 0x9E
	ldrb r0, [r0]
	lsls r0, 3
	adds r5, r4, r0
	movs r0, 0x1E
	ldrsh r2, [r1, r0]
	adds r2, 0x1
	movs r0, 0x7
	str r0, [sp]
	ldr r0, [r1, 0x34]
	str r0, [sp, 0x4]
	adds r0, r5, 0
	movs r1, 0
	movs r3, 0x2
	bl sub_8012BC4
	movs r5, 0
	b _0802D076
	.align 2, 0
_0802D02C: .4byte gUnknown_203B2F4
_0802D030: .4byte gUnknown_80DFDBC
_0802D034:
	ldr r0, [r6]
	movs r2, 0x1E
	ldrsh r1, [r0, r2]
	movs r2, 0x1C
	ldrsh r0, [r0, r2]
	muls r0, r1
	adds r0, r5
	lsls r0, 24
	lsrs r0, 24
	bl sub_803B344
	adds r4, r0, 0
	ldr r0, [r6]
	ldr r1, [r0, 0x34]
	str r1, [sp, 0x8]
	adds r1, r5, 0
	bl sub_8013800
	str r0, [sp, 0x50]
	adds r0, r4, 0
	add r1, sp, 0x8
	bl sub_803B35C
	mov r1, sp
	adds r1, 0x4B
	movs r0, 0x1
	strb r0, [r1]
	ldr r0, [r4, 0x14]
	str r0, [sp, 0x54]
	add r0, sp, 0x8
	bl sub_803B6D4
	adds r5, 0x1
_0802D076:
	ldr r0, [r6]
	movs r1, 0x1A
	ldrsh r0, [r0, r1]
	cmp r5, r0
	blt _0802D034
	ldr r0, _0802D094
	ldr r0, [r0]
	ldr r0, [r0, 0x34]
	bl sub_80073E0
	add sp, 0x60
	pop {r4-r6}
	pop {r0}
	bx r0
	.align 2, 0
_0802D094: .4byte gUnknown_203B2F4
	thumb_func_end sub_802CFD0

	thumb_func_start sub_802D098
sub_802D098:
	push {r4-r6,lr}
	adds r4, r0, 0
	ldr r6, _0802D0DC
	movs r0, 0x82
	lsls r0, 2
	movs r1, 0x8
	bl MemoryAlloc
	str r0, [r6]
	movs r5, 0
	str r5, [r0, 0x6C]
	str r5, [r0, 0x70]
	str r5, [r0, 0x74]
	str r4, [r0, 0xC]
	strb r5, [r0, 0x8]
	ldr r0, [r6]
	adds r0, 0xA
	bl sub_8099328
	ldr r1, [r6]
	strb r0, [r1, 0x9]
	bl sub_8011C1C
	cmp r0, 0x2
	beq _0802D0CE
	ldr r0, [r6]
	strb r5, [r0, 0x9]
_0802D0CE:
	movs r0, 0
	bl sub_802D1A0
	movs r0, 0x1
	pop {r4-r6}
	pop {r1}
	bx r1
	.align 2, 0
_0802D0DC: .4byte gUnknown_203B2F8
	thumb_func_end sub_802D098

	thumb_func_start sub_802D0E0
sub_802D0E0:
	push {lr}
	ldr r0, _0802D0F8
	ldr r0, [r0]
	ldr r0, [r0]
	cmp r0, 0x10
	bhi _0802D16C
	lsls r0, 2
	ldr r1, _0802D0FC
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0802D0F8: .4byte gUnknown_203B2F8
_0802D0FC: .4byte _0802D100
	.align 2, 0
_0802D100:
	.4byte _0802D170
	.4byte _0802D144
	.4byte _0802D168
	.4byte _0802D16C
	.4byte _0802D16C
	.4byte _0802D16C
	.4byte _0802D16C
	.4byte _0802D16C
	.4byte _0802D16C
	.4byte _0802D162
	.4byte _0802D16C
	.4byte _0802D14A
	.4byte _0802D14A
	.4byte _0802D150
	.4byte _0802D156
	.4byte _0802D15C
	.4byte _0802D15C
_0802D144:
	bl sub_802D7D0
	b _0802D170
_0802D14A:
	bl sub_802D8CC
	b _0802D170
_0802D150:
	bl sub_802D940
	b _0802D170
_0802D156:
	bl sub_802D9F0
	b _0802D170
_0802D15C:
	bl sub_802DA60
	b _0802D170
_0802D162:
	bl sub_802D82C
	b _0802D170
_0802D168:
	movs r0, 0x3
	b _0802D172
_0802D16C:
	bl sub_802DA84
_0802D170:
	movs r0, 0
_0802D172:
	pop {r1}
	bx r1
	thumb_func_end sub_802D0E0

	thumb_func_start sub_802D178
sub_802D178:
	ldr r0, _0802D180
	ldr r0, [r0]
	ldrb r0, [r0, 0x8]
	bx lr
	.align 2, 0
_0802D180: .4byte gUnknown_203B2F8
	thumb_func_end sub_802D178

	thumb_func_start sub_802D184
sub_802D184:
	push {r4,lr}
	ldr r4, _0802D19C
	ldr r0, [r4]
	cmp r0, 0
	beq _0802D196
	bl MemoryFree
	movs r0, 0
	str r0, [r4]
_0802D196:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0802D19C: .4byte gUnknown_203B2F8
	thumb_func_end sub_802D184

	thumb_func_start sub_802D1A0
sub_802D1A0:
	push {lr}
	ldr r1, _0802D1B4
	ldr r1, [r1]
	str r0, [r1]
	bl sub_802D1B8
	bl sub_802D2A8
	pop {r0}
	bx r0
	.align 2, 0
_0802D1B4: .4byte gUnknown_203B2F8
	thumb_func_end sub_802D1A0

	thumb_func_start sub_802D1B8
sub_802D1B8:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	ldr r4, _0802D1E0
	ldr r0, [r4]
	movs r1, 0xD4
	lsls r1, 1
	adds r0, r1
	bl sub_8006518
	ldr r0, [r4]
	ldr r0, [r0]
	cmp r0, 0xD
	beq _0802D1EA
	cmp r0, 0xD
	bgt _0802D1E4
	cmp r0, 0x2
	beq _0802D27E
	b _0802D254
	.align 2, 0
_0802D1E0: .4byte gUnknown_203B2F8
_0802D1E4:
	cmp r0, 0xE
	beq _0802D21C
	b _0802D254
_0802D1EA:
	bl sub_802D5A4
	ldr r2, [r4]
	movs r0, 0xEC
	lsls r0, 1
	adds r2, r0
	ldr r1, _0802D218
	ldm r1!, {r3,r5,r6}
	stm r2!, {r3,r5,r6}
	ldm r1!, {r3,r5,r7}
	stm r2!, {r3,r5,r7}
	ldr r1, [r4]
	adds r0, r1, r0
	movs r6, 0x8C
	lsls r6, 1
	adds r1, r6
	bl sub_8012CAC
	ldr r0, [r4]
	movs r7, 0xF2
	lsls r7, 1
	b _0802D246
	.align 2, 0
_0802D218: .4byte gUnknown_80DFE04
_0802D21C:
	bl sub_802D63C
	ldr r2, [r4]
	movs r0, 0xF8
	lsls r0, 1
	adds r2, r0
	ldr r1, _0802D250
	ldm r1!, {r3,r5,r6}
	stm r2!, {r3,r5,r6}
	ldm r1!, {r3,r5,r7}
	stm r2!, {r3,r5,r7}
	ldr r1, [r4]
	adds r0, r1, r0
	movs r6, 0xAC
	lsls r6, 1
	adds r1, r6
	bl sub_8012CAC
	ldr r0, [r4]
	movs r7, 0xFE
	lsls r7, 1
_0802D246:
	adds r0, r7
	movs r1, 0x6
	strh r1, [r0]
	b _0802D27E
	.align 2, 0
_0802D250: .4byte gUnknown_80DFE1C
_0802D254:
	ldr r0, _0802D2A0
	mov r12, r0
	movs r1, 0xD4
	lsls r1, 1
	mov r8, r1
	ldr r4, _0802D2A4
	movs r3, 0
	movs r2, 0x3
_0802D264:
	mov r5, r12
	ldr r1, [r5]
	adds r1, r3
	add r1, r8
	adds r0, r4, 0
	ldm r0!, {r5-r7}
	stm r1!, {r5-r7}
	ldm r0!, {r5-r7}
	stm r1!, {r5-r7}
	adds r3, 0x18
	subs r2, 0x1
	cmp r2, 0
	bge _0802D264
_0802D27E:
	bl ResetUnusedInputStruct
	ldr r0, _0802D2A0
	ldr r0, [r0]
	movs r6, 0xD4
	lsls r6, 1
	adds r0, r6
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_0802D2A0: .4byte gUnknown_203B2F8
_0802D2A4: .4byte gUnknown_80DFDD4
	thumb_func_end sub_802D1B8

	thumb_func_start sub_802D2A8
sub_802D2A8:
	push {r4,lr}
	sub sp, 0x14
	ldr r1, _0802D2C4
	ldr r0, [r1]
	ldr r0, [r0]
	adds r4, r1, 0
	cmp r0, 0x10
	bls _0802D2BA
	b _0802D59A
_0802D2BA:
	lsls r0, 2
	ldr r1, _0802D2C8
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0802D2C4: .4byte gUnknown_203B2F8
_0802D2C8: .4byte _0802D2CC
	.align 2, 0
_0802D2CC:
	.4byte _0802D310
	.4byte _0802D398
	.4byte _0802D59A
	.4byte _0802D3B4
	.4byte _0802D3C4
	.4byte _0802D3D4
	.4byte _0802D3E4
	.4byte _0802D3F4
	.4byte _0802D404
	.4byte _0802D498
	.4byte _0802D4C8
	.4byte _0802D4E4
	.4byte _0802D4F0
	.4byte _0802D4F8
	.4byte _0802D524
	.4byte _0802D558
	.4byte _0802D576
_0802D310:
	ldr r0, [r4]
	ldr r0, [r0, 0xC]
	bl sub_80968B0
	lsls r0, 24
	cmp r0, 0
	beq _0802D326
	movs r0, 0x3
	bl sub_802D1A0
	b _0802D59A
_0802D326:
	ldr r0, [r4]
	ldr r0, [r0, 0xC]
	bl sub_8096F50
	lsls r0, 24
	cmp r0, 0
	beq _0802D33C
	movs r0, 0x4
	bl sub_802D1A0
	b _0802D59A
_0802D33C:
	ldr r1, [r4]
	ldr r0, [r1, 0xC]
	ldrb r0, [r0, 0x2]
	cmp r0, 0x4
	bne _0802D36E
	adds r0, r1, 0
	adds r0, 0x10
	bl sub_8096C08
	lsls r0, 24
	cmp r0, 0
	beq _0802D36E
	bl sub_802DAA8
	lsls r0, 24
	cmp r0, 0
	beq _0802D366
	movs r0, 0x9
	bl sub_802D1A0
	b _0802D59A
_0802D366:
	movs r0, 0x5
	bl sub_802D1A0
	b _0802D59A
_0802D36E:
	bl sub_80969AC
	cmp r0, 0x7
	ble _0802D390
	bl sub_802DADC
	lsls r0, 24
	cmp r0, 0
	beq _0802D388
	movs r0, 0xA
	bl sub_802D1A0
	b _0802D59A
_0802D388:
	movs r0, 0x6
	bl sub_802D1A0
	b _0802D59A
_0802D390:
	movs r0, 0x8
	bl sub_802D1A0
	b _0802D59A
_0802D398:
	bl sub_802D73C
	ldr r0, _0802D3AC
	ldr r1, _0802D3B0
	ldr r3, [r1]
	ldr r2, [r3, 0x70]
	movs r1, 0xAC
	lsls r1, 1
	adds r3, r1
	b _0802D4AA
	.align 2, 0
_0802D3AC: .4byte gUnknown_80DFE4C
_0802D3B0: .4byte gUnknown_203B2F8
_0802D3B4:
	ldr r1, [r4]
	movs r0, 0x2
	str r0, [r1, 0x4]
	ldr r0, _0802D3C0
	b _0802D4D0
	.align 2, 0
_0802D3C0: .4byte gUnknown_80DFE9C
_0802D3C4:
	ldr r1, [r4]
	movs r0, 0x2
	str r0, [r1, 0x4]
	ldr r0, _0802D3D0
	b _0802D4D0
	.align 2, 0
_0802D3D0: .4byte gUnknown_80DFED0
_0802D3D4:
	ldr r1, [r4]
	movs r0, 0x2
	str r0, [r1, 0x4]
	ldr r0, _0802D3E0
	b _0802D4D0
	.align 2, 0
_0802D3E0: .4byte gUnknown_80DFF2C
_0802D3E4:
	ldr r1, [r4]
	movs r0, 0x2
	str r0, [r1, 0x4]
	ldr r0, _0802D3F0
	b _0802D4D0
	.align 2, 0
_0802D3F0: .4byte gUnknown_80DFFA4
_0802D3F4:
	ldr r1, [r4]
	movs r0, 0xC
	str r0, [r1, 0x4]
	ldr r0, _0802D400
	b _0802D4D0
	.align 2, 0
_0802D400: .4byte gUnknown_80E0010
_0802D404:
	ldr r4, _0802D45C
	ldr r1, [r4]
	movs r0, 0x1
	strb r0, [r1, 0x8]
	ldr r0, [r4]
	ldr r0, [r0, 0xC]
	bl sub_8096A78
	bl sub_8096C80
	bl sub_8096D24
	ldr r0, [r4]
	ldr r0, [r0, 0xC]
	ldrb r0, [r0, 0x2]
	cmp r0, 0x4
	bne _0802D446
	bl sub_8096DD8
	ldr r1, [r4]
	ldr r1, [r1, 0xC]
	ldr r1, [r1, 0x14]
	movs r2, 0x28
	bl MemoryCopy8
	bl sub_8096DE8
	ldr r1, [r4]
	ldr r1, [r1, 0xC]
	ldr r1, [r1, 0x18]
	movs r2, 0x78
	bl MemoryCopy8
_0802D446:
	ldr r0, [r4]
	ldr r0, [r0, 0xC]
	ldrb r0, [r0, 0x4]
	cmp r0, 0x2C
	beq _0802D46E
	cmp r0, 0x2C
	bgt _0802D460
	cmp r0, 0x2B
	beq _0802D46A
	b _0802D484
	.align 2, 0
_0802D45C: .4byte gUnknown_203B2F8
_0802D460:
	cmp r0, 0x2D
	beq _0802D472
	cmp r0, 0x2E
	beq _0802D47C
	b _0802D484
_0802D46A:
	movs r0, 0x2A
	b _0802D474
_0802D46E:
	movs r0, 0x2B
	b _0802D474
_0802D472:
	movs r0, 0x2C
_0802D474:
	movs r1, 0x1
	bl sub_8097418
	b _0802D484
_0802D47C:
	movs r0, 0x2D
	movs r1, 0x1
	bl sub_8097418
_0802D484:
	ldr r0, _0802D490
	ldr r1, [r0]
	movs r0, 0x2
	str r0, [r1, 0x4]
	ldr r0, _0802D494
	b _0802D4D0
	.align 2, 0
_0802D490: .4byte gUnknown_203B2F8
_0802D494: .4byte gUnknown_80E0074
_0802D498:
	bl sub_802D690
	ldr r0, _0802D4C0
	ldr r1, _0802D4C4
	ldr r3, [r1]
	ldr r2, [r3, 0x74]
	movs r4, 0xAC
	lsls r4, 1
	adds r3, r4
_0802D4AA:
	movs r4, 0
	str r4, [sp]
	movs r1, 0x4
	str r1, [sp, 0x4]
	str r4, [sp, 0x8]
	str r4, [sp, 0xC]
	str r4, [sp, 0x10]
	movs r1, 0
	bl sub_8014248
	b _0802D59A
	.align 2, 0
_0802D4C0: .4byte gUnknown_80E0094
_0802D4C4: .4byte gUnknown_203B2F8
_0802D4C8:
	ldr r1, [r4]
	movs r0, 0xB
	str r0, [r1, 0x4]
	ldr r0, _0802D4DC
_0802D4D0:
	ldr r3, _0802D4E0
	movs r1, 0
	movs r2, 0
	bl sub_80141B4
	b _0802D59A
	.align 2, 0
_0802D4DC: .4byte gUnknown_80E0108
_0802D4E0: .4byte 0x00000101
_0802D4E4:
	movs r0, 0
	movs r1, 0
	movs r2, 0x4
	bl sub_802C4C8
	b _0802D59A
_0802D4F0:
	movs r0, 0x1
	bl sub_802C640
	b _0802D59A
_0802D4F8:
	bl sub_802C750
	ldr r0, _0802D520
	ldr r2, [r0]
	adds r0, r2, 0
	adds r0, 0x78
	movs r3, 0x8C
	lsls r3, 1
	adds r1, r2, r3
	movs r4, 0xCC
	lsls r4, 1
	adds r3, r2, r4
	ldr r2, [r2, 0x6C]
	str r2, [sp]
	movs r2, 0x2
	str r2, [sp, 0x4]
	movs r2, 0
	bl sub_8012D60
	b _0802D59A
	.align 2, 0
_0802D520: .4byte gUnknown_203B2F8
_0802D524:
	bl sub_802C750
	ldr r4, _0802D554
	ldr r0, [r4]
	adds r0, 0x78
	movs r1, 0
	bl sub_8012EA4
	ldr r1, [r4]
	adds r0, r1, 0
	adds r0, 0xC8
	movs r2, 0xAC
	lsls r2, 1
	adds r1, r2
	movs r2, 0x4
	str r2, [sp]
	movs r2, 0x3
	str r2, [sp, 0x4]
	movs r2, 0
	movs r3, 0
	bl sub_8012D60
	b _0802D59A
	.align 2, 0
_0802D554: .4byte gUnknown_203B2F8
_0802D558:
	ldr r0, [r4]
	ldrb r0, [r0, 0x10]
	bl sub_8096AB4
	ldr r1, [r4]
	adds r1, 0x14
	bl sub_803B35C
	ldr r0, [r4]
	movs r1, 0x3
	str r1, [r0, 0x14]
	adds r0, 0x14
	bl sub_802DE84
	b _0802D59A
_0802D576:
	ldr r1, [r4]
	ldr r0, [r1, 0xC]
	adds r1, 0x14
	bl sub_803B35C
	ldr r0, [r4]
	movs r1, 0x3
	str r1, [r0, 0x14]
	adds r0, 0x58
	movs r1, 0
	strb r1, [r0]
	ldr r0, [r4]
	ldr r1, [r0, 0xC]
	ldr r1, [r1, 0x18]
	str r1, [r0, 0x64]
	adds r0, 0x14
	bl sub_802DE84
_0802D59A:
	add sp, 0x14
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_802D2A8

	thumb_func_start sub_802D5A4
sub_802D5A4:
	push {r4-r7,lr}
	ldr r4, _0802D630
	ldr r0, [r4]
	movs r5, 0xCC
	lsls r5, 1
	adds r0, r5
	movs r1, 0
	movs r2, 0x10
	bl MemoryFill16
	ldr r0, [r4]
	mov r12, r0
	movs r3, 0
	movs r1, 0x8C
	lsls r1, 1
	add r1, r12
	ldr r0, _0802D634
	ldr r0, [r0]
	str r0, [r1]
	movs r1, 0x8E
	lsls r1, 1
	add r1, r12
	movs r0, 0x2
	str r0, [r1]
	movs r2, 0x1
	movs r1, 0x90
	lsls r1, 1
	add r1, r12
	ldr r0, _0802D638
	ldr r0, [r0]
	str r0, [r1]
	movs r1, 0x92
	lsls r1, 1
	add r1, r12
	movs r0, 0x5
	str r0, [r1]
	movs r7, 0x2
	movs r0, 0x94
	lsls r0, 1
	add r0, r12
	str r3, [r0]
	movs r0, 0x96
	lsls r0, 1
	add r0, r12
	str r2, [r0]
	movs r6, 0
	movs r3, 0x8E
	lsls r3, 1
	add r3, r12
	mov r0, r12
	adds r2, r0, r5
_0802D60A:
	ldrh r0, [r2]
	cmp r0, 0
	bne _0802D61A
	ldr r1, [r3]
	mov r5, r12
	ldr r0, [r5, 0x6C]
	cmp r1, r0
	beq _0802D62A
_0802D61A:
	adds r3, 0x8
	adds r2, 0x2
	adds r6, 0x1
	cmp r6, r7
	blt _0802D60A
	ldr r1, [r4]
	movs r0, 0x2
	str r0, [r1, 0x6C]
_0802D62A:
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_0802D630: .4byte gUnknown_203B2F8
_0802D634: .4byte gUnknown_80D494C
_0802D638: .4byte gUnknown_80D4970
	thumb_func_end sub_802D5A4

	thumb_func_start sub_802D63C
sub_802D63C:
	ldr r0, _0802D684
	ldr r0, [r0]
	mov r12, r0
	movs r3, 0
	movs r1, 0xAC
	lsls r1, 1
	add r1, r12
	ldr r0, _0802D688
	ldr r0, [r0]
	str r0, [r1]
	movs r1, 0xAE
	lsls r1, 1
	add r1, r12
	movs r0, 0x3
	str r0, [r1]
	movs r2, 0x1
	movs r1, 0xB0
	lsls r1, 1
	add r1, r12
	ldr r0, _0802D68C
	ldr r0, [r0]
	str r0, [r1]
	movs r1, 0xB2
	lsls r1, 1
	add r1, r12
	movs r0, 0x4
	str r0, [r1]
	movs r0, 0xB4
	lsls r0, 1
	add r0, r12
	str r3, [r0]
	movs r0, 0xB6
	lsls r0, 1
	add r0, r12
	str r2, [r0]
	bx lr
	.align 2, 0
_0802D684: .4byte gUnknown_203B2F8
_0802D688: .4byte gUnknown_80D4920
_0802D68C: .4byte gUnknown_80D4928
	thumb_func_end sub_802D63C

	thumb_func_start sub_802D690
sub_802D690:
	push {r4,r5,lr}
	ldr r2, _0802D728
	ldr r0, [r2]
	mov r12, r0
	movs r4, 0
	movs r1, 0xAC
	lsls r1, 1
	add r1, r12
	ldr r0, _0802D72C
	ldr r0, [r0]
	str r0, [r1]
	movs r1, 0xAE
	lsls r1, 1
	add r1, r12
	movs r0, 0x3
	str r0, [r1]
	movs r3, 0x1
	movs r1, 0xB0
	lsls r1, 1
	add r1, r12
	ldr r0, _0802D730
	ldr r0, [r0]
	str r0, [r1]
	movs r1, 0xB2
	lsls r1, 1
	add r1, r12
	movs r0, 0x4
	str r0, [r1]
	movs r1, 0xB4
	lsls r1, 1
	add r1, r12
	ldr r0, _0802D734
	str r0, [r1]
	movs r1, 0xB6
	lsls r1, 1
	add r1, r12
	movs r0, 0x6
	str r0, [r1]
	movs r1, 0xB8
	lsls r1, 1
	add r1, r12
	ldr r0, _0802D738
	str r0, [r1]
	movs r1, 0xBA
	lsls r1, 1
	add r1, r12
	movs r0, 0x7
	str r0, [r1]
	movs r5, 0x4
	movs r0, 0xBC
	lsls r0, 1
	add r0, r12
	str r4, [r0]
	movs r0, 0xBE
	lsls r0, 1
	add r0, r12
	str r3, [r0]
	movs r3, 0
	mov r0, r12
	ldr r4, [r0, 0x74]
	movs r1, 0xAE
	lsls r1, 1
	add r1, r12
_0802D70E:
	ldr r0, [r1]
	cmp r0, r4
	beq _0802D722
	adds r1, 0x8
	adds r3, 0x1
	cmp r3, r5
	blt _0802D70E
	ldr r1, [r2]
	movs r0, 0x4
	str r0, [r1, 0x74]
_0802D722:
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_0802D728: .4byte gUnknown_203B2F8
_0802D72C: .4byte gUnknown_80D4920
_0802D730: .4byte gUnknown_80D4928
_0802D734: .4byte gUnknown_80E014C
_0802D738: .4byte gUnknown_80E0158
	thumb_func_end sub_802D690

	thumb_func_start sub_802D73C
sub_802D73C:
	push {r4,r5,lr}
	ldr r3, _0802D7C0
	ldr r0, [r3]
	mov r12, r0
	movs r4, 0
	movs r1, 0xAC
	lsls r1, 1
	add r1, r12
	ldr r0, _0802D7C4
	ldr r0, [r0]
	str r0, [r1]
	movs r1, 0xAE
	lsls r1, 1
	add r1, r12
	movs r0, 0x3
	str r0, [r1]
	movs r2, 0x1
	movs r1, 0xB0
	lsls r1, 1
	add r1, r12
	ldr r0, _0802D7C8
	ldr r0, [r0]
	str r0, [r1]
	movs r1, 0xB2
	lsls r1, 1
	add r1, r12
	movs r0, 0x4
	str r0, [r1]
	movs r1, 0xB4
	lsls r1, 1
	add r1, r12
	ldr r0, _0802D7CC
	str r0, [r1]
	movs r1, 0xB6
	lsls r1, 1
	add r1, r12
	movs r0, 0x6
	str r0, [r1]
	movs r5, 0x3
	movs r0, 0xB8
	lsls r0, 1
	add r0, r12
	str r4, [r0]
	movs r0, 0xBA
	lsls r0, 1
	add r0, r12
	str r2, [r0]
	movs r2, 0
	mov r0, r12
	ldr r4, [r0, 0x70]
	movs r1, 0xAE
	lsls r1, 1
	add r1, r12
_0802D7A6:
	ldr r0, [r1]
	cmp r0, r4
	beq _0802D7BA
	adds r1, 0x8
	adds r2, 0x1
	cmp r2, r5
	blt _0802D7A6
	ldr r1, [r3]
	movs r0, 0x4
	str r0, [r1, 0x70]
_0802D7BA:
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_0802D7C0: .4byte gUnknown_203B2F8
_0802D7C4: .4byte gUnknown_80D4920
_0802D7C8: .4byte gUnknown_80D4928
_0802D7CC: .4byte gUnknown_80E014C
	thumb_func_end sub_802D73C

	thumb_func_start sub_802D7D0
sub_802D7D0:
	push {lr}
	sub sp, 0x4
	mov r0, sp
	bl sub_80144A4
	cmp r0, 0
	bne _0802D826
	ldr r1, [sp]
	cmp r1, 0x1
	beq _0802D7EA
	ldr r0, _0802D800
	ldr r0, [r0]
	str r1, [r0, 0x70]
_0802D7EA:
	ldr r0, [sp]
	cmp r0, 0x3
	beq _0802D804
	cmp r0, 0x3
	ble _0802D820
	cmp r0, 0x4
	beq _0802D820
	cmp r0, 0x6
	beq _0802D80C
	b _0802D820
	.align 2, 0
_0802D800: .4byte gUnknown_203B2F8
_0802D804:
	movs r0, 0x2
	bl sub_802D1A0
	b _0802D826
_0802D80C:
	ldr r0, _0802D81C
	ldr r1, [r0]
	movs r0, 0x1
	str r0, [r1, 0x4]
	movs r0, 0x10
	bl sub_802D1A0
	b _0802D826
	.align 2, 0
_0802D81C: .4byte gUnknown_203B2F8
_0802D820:
	movs r0, 0
	bl sub_802D1A0
_0802D826:
	add sp, 0x4
	pop {r0}
	bx r0
	thumb_func_end sub_802D7D0

	thumb_func_start sub_802D82C
sub_802D82C:
	push {lr}
	sub sp, 0x4
	mov r0, sp
	bl sub_80144A4
	cmp r0, 0
	bne _0802D8C6
	ldr r1, [sp]
	cmp r1, 0x1
	beq _0802D846
	ldr r0, _0802D858
	ldr r0, [r0]
	str r1, [r0, 0x74]
_0802D846:
	ldr r0, [sp]
	subs r0, 0x1
	cmp r0, 0x6
	bhi _0802D8C0
	lsls r0, 2
	ldr r1, _0802D85C
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0802D858: .4byte gUnknown_203B2F8
_0802D85C: .4byte _0802D860
	.align 2, 0
_0802D860:
	.4byte _0802D8C0
	.4byte _0802D8C0
	.4byte _0802D87C
	.4byte _0802D8C0
	.4byte _0802D8C0
	.4byte _0802D898
	.4byte _0802D8AC
_0802D87C:
	ldr r0, _0802D894
	ldr r0, [r0]
	ldrb r0, [r0, 0x10]
	bl sub_8096C3C
	bl sub_8096C80
	movs r0, 0x8
	bl sub_802D1A0
	b _0802D8C6
	.align 2, 0
_0802D894: .4byte gUnknown_203B2F8
_0802D898:
	ldr r0, _0802D8A8
	ldr r1, [r0]
	movs r0, 0x9
	str r0, [r1, 0x4]
	movs r0, 0x10
	bl sub_802D1A0
	b _0802D8C6
	.align 2, 0
_0802D8A8: .4byte gUnknown_203B2F8
_0802D8AC:
	ldr r0, _0802D8BC
	ldr r1, [r0]
	movs r0, 0x9
	str r0, [r1, 0x4]
	movs r0, 0xF
	bl sub_802D1A0
	b _0802D8C6
	.align 2, 0
_0802D8BC: .4byte gUnknown_203B2F8
_0802D8C0:
	movs r0, 0x1
	bl sub_802D1A0
_0802D8C6:
	add sp, 0x4
	pop {r0}
	bx r0
	thumb_func_end sub_802D82C

	thumb_func_start sub_802D8CC
sub_802D8CC:
	push {lr}
	movs r0, 0x1
	bl sub_802C598
	cmp r0, 0x4
	bhi _0802D93A
	lsls r0, 2
	ldr r1, _0802D8E4
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0802D8E4: .4byte _0802D8E8
	.align 2, 0
_0802D8E8:
	.4byte _0802D93A
	.4byte _0802D93A
	.4byte _0802D930
	.4byte _0802D8FC
	.4byte _0802D914
_0802D8FC:
	bl sub_802C620
	ldr r1, _0802D910
	ldr r1, [r1]
	strb r0, [r1, 0x10]
	movs r0, 0xD
	bl sub_802D1A0
	b _0802D93A
	.align 2, 0
_0802D910: .4byte gUnknown_203B2F8
_0802D914:
	bl sub_802C620
	ldr r2, _0802D92C
	ldr r1, [r2]
	strb r0, [r1, 0x10]
	ldr r1, [r2]
	movs r0, 0xC
	str r0, [r1, 0x4]
	movs r0, 0xF
	bl sub_802D1A0
	b _0802D93A
	.align 2, 0
_0802D92C: .4byte gUnknown_203B2F8
_0802D930:
	bl sub_802C688
	movs r0, 0x1
	bl sub_802D1A0
_0802D93A:
	pop {r0}
	bx r0
	thumb_func_end sub_802D8CC

	thumb_func_start sub_802D940
sub_802D940:
	push {r4,lr}
	sub sp, 0x4
	movs r0, 0
	str r0, [sp]
	bl sub_802C598
	ldr r4, _0802D980
	ldr r0, [r4]
	adds r0, 0x78
	bl sub_8012FD8
	lsls r0, 24
	cmp r0, 0
	bne _0802D970
	ldr r0, [r4]
	adds r0, 0x78
	mov r1, sp
	bl sub_8013114
	ldr r1, [sp]
	cmp r1, 0x1
	beq _0802D970
	ldr r0, [r4]
	str r1, [r0, 0x6C]
_0802D970:
	ldr r0, [sp]
	cmp r0, 0x2
	beq _0802D98A
	cmp r0, 0x2
	bgt _0802D984
	cmp r0, 0x1
	beq _0802D9E0
	b _0802D9E6
	.align 2, 0
_0802D980: .4byte gUnknown_203B2F8
_0802D984:
	cmp r0, 0x5
	beq _0802D9CC
	b _0802D9E6
_0802D98A:
	ldr r0, _0802D9BC
	ldr r3, [r0]
	ldrb r0, [r3, 0x9]
	cmp r0, 0
	beq _0802D9C4
	ldr r2, _0802D9C0
	ldrb r1, [r3, 0x10]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 2
	adds r0, 0xF0
	ldr r1, [r2]
	adds r1, r0
	ldrb r0, [r1]
	cmp r0, 0x5
	bls _0802D9C4
	ldrb r0, [r3, 0xA]
	ldrb r1, [r1, 0x4]
	cmp r0, r1
	bne _0802D9C4
	movs r0, 0x7
	bl sub_802D1A0
	b _0802D9E6
	.align 2, 0
_0802D9BC: .4byte gUnknown_203B2F8
_0802D9C0: .4byte gUnknown_203B490
_0802D9C4:
	movs r0, 0xE
	bl sub_802D1A0
	b _0802D9E6
_0802D9CC:
	ldr r0, _0802D9DC
	ldr r1, [r0]
	movs r0, 0xC
	str r0, [r1, 0x4]
	movs r0, 0xF
	bl sub_802D1A0
	b _0802D9E6
	.align 2, 0
_0802D9DC: .4byte gUnknown_203B2F8
_0802D9E0:
	movs r0, 0xC
	bl sub_802D1A0
_0802D9E6:
	add sp, 0x4
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_802D940

	thumb_func_start sub_802D9F0
sub_802D9F0:
	push {r4,lr}
	sub sp, 0x4
	movs r0, 0
	str r0, [sp]
	bl sub_802C598
	ldr r4, _0802DA30
	ldr r0, [r4]
	adds r0, 0x78
	bl sub_8012FD8
	ldr r0, [r4]
	adds r0, 0xC8
	bl sub_8012FD8
	lsls r0, 24
	cmp r0, 0
	bne _0802DA1E
	ldr r0, [r4]
	adds r0, 0xC8
	mov r1, sp
	bl sub_8013114
_0802DA1E:
	ldr r0, [sp]
	cmp r0, 0x3
	beq _0802DA40
	cmp r0, 0x3
	bgt _0802DA34
	cmp r0, 0x1
	beq _0802DA38
	b _0802DA56
	.align 2, 0
_0802DA30: .4byte gUnknown_203B2F8
_0802DA34:
	cmp r0, 0x4
	bne _0802DA56
_0802DA38:
	movs r0, 0xC
	bl sub_802D1A0
	b _0802DA56
_0802DA40:
	bl sub_802C688
	ldr r0, [r4]
	ldrb r0, [r0, 0x10]
	bl sub_8096C3C
	bl sub_8096C80
	movs r0, 0x8
	bl sub_802D1A0
_0802DA56:
	add sp, 0x4
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_802D9F0

	thumb_func_start sub_802DA60
sub_802DA60:
	push {lr}
	bl sub_802DEE0
	cmp r0, 0x1
	bls _0802DA7C
	cmp r0, 0x3
	bhi _0802DA7C
	bl sub_802DF24
	ldr r0, _0802DA80
	ldr r0, [r0]
	ldr r0, [r0, 0x4]
	bl sub_802D1A0
_0802DA7C:
	pop {r0}
	bx r0
	.align 2, 0
_0802DA80: .4byte gUnknown_203B2F8
	thumb_func_end sub_802DA60

	thumb_func_start sub_802DA84
sub_802DA84:
	push {lr}
	sub sp, 0x4
	mov r0, sp
	bl sub_80144A4
	cmp r0, 0
	bne _0802DA9C
	ldr r0, _0802DAA4
	ldr r0, [r0]
	ldr r0, [r0, 0x4]
	bl sub_802D1A0
_0802DA9C:
	add sp, 0x4
	pop {r0}
	bx r0
	.align 2, 0
_0802DAA4: .4byte gUnknown_203B2F8
	thumb_func_end sub_802DA84

	thumb_func_start sub_802DAA8
sub_802DAA8:
	push {r4,lr}
	ldr r4, _0802DAD0
	ldr r0, [r4]
	ldrb r0, [r0, 0x10]
	bl sub_8096AB4
	adds r1, r0, 0
	ldr r4, [r4]
	ldrb r0, [r4, 0x9]
	cmp r0, 0
	beq _0802DAD4
	ldrb r0, [r1]
	cmp r0, 0x5
	beq _0802DAD4
	ldrb r0, [r4, 0xA]
	ldrb r1, [r1, 0x4]
	cmp r0, r1
	bne _0802DAD4
	movs r0, 0
	b _0802DAD6
	.align 2, 0
_0802DAD0: .4byte gUnknown_203B2F8
_0802DAD4:
	movs r0, 0x1
_0802DAD6:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_802DAA8

	thumb_func_start sub_802DADC
sub_802DADC:
	push {r4,lr}
	ldr r3, _0802DAEC
	ldr r0, [r3]
	ldrb r0, [r0, 0x9]
	cmp r0, 0
	bne _0802DAF0
_0802DAE8:
	movs r0, 0x1
	b _0802DB1C
	.align 2, 0
_0802DAEC: .4byte gUnknown_203B2F8
_0802DAF0:
	ldr r0, _0802DB24
	ldr r0, [r0]
	adds r1, r0, 0
	adds r1, 0xF0
	movs r2, 0
_0802DAFA:
	ldrb r0, [r1]
	cmp r0, 0
	beq _0802DAE8
	cmp r0, 0x5
	beq _0802DAE8
	cmp r0, 0x5
	bls _0802DB12
	ldr r0, [r3]
	ldrb r0, [r0, 0xA]
	ldrb r4, [r1, 0x4]
	cmp r0, r4
	bne _0802DAE8
_0802DB12:
	adds r1, 0x14
	adds r2, 0x1
	cmp r2, 0x7
	ble _0802DAFA
	movs r0, 0
_0802DB1C:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_0802DB24: .4byte gUnknown_203B490
	thumb_func_end sub_802DADC

	thumb_func_start sub_802DB28
sub_802DB28:
	push {r4-r6,lr}
	sub sp, 0x8
	adds r2, r1, 0
	lsls r0, 24
	lsrs r6, r0, 24
	lsls r2, 24
	lsrs r2, 24
	mov r0, sp
	adds r1, r6, 0
	bl sub_8096AF8
	mov r0, sp
	ldrb r0, [r0]
	cmp r0, 0
	bne _0802DB4A
	movs r0, 0
	b _0802DBC6
_0802DB4A:
	bl ResetUnusedInputStruct
	movs r0, 0
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	ldr r4, _0802DBD0
	movs r0, 0xA8
	movs r1, 0x8
	bl MemoryAlloc
	str r0, [r4]
	adds r0, 0x30
	movs r5, 0
	strb r6, [r0]
	adds r0, r6, 0
	bl sub_8096AB4
	ldr r1, [r4]
	str r0, [r1, 0x34]
	bl sub_8096EEC
	ldr r1, [r4]
	ldr r0, [r1, 0x34]
	adds r1, 0x8
	bl sub_803C21C
	ldr r0, [r4]
	ldr r0, [r0, 0x34]
	movs r1, 0xC
	ldrsh r0, [r0, r1]
	bl GetDialogueSpriteDataPtr
	ldr r1, [r4]
	str r0, [r1, 0x38]
	str r5, [r1, 0x3C]
	adds r1, 0x44
	strb r5, [r1]
	ldr r0, [r4]
	adds r0, 0x45
	strb r5, [r0]
	ldr r0, [r4]
	adds r0, 0x46
	strb r5, [r0]
	ldr r2, [r4]
	adds r1, r2, 0
	adds r1, 0x40
	movs r0, 0x2
	strh r0, [r1]
	adds r1, 0x2
	movs r0, 0x8
	strh r0, [r1]
	ldr r0, [r2, 0x38]
	cmp r0, 0
	beq _0802DBBE
	ldr r0, [r0, 0x4]
	str r0, [r2, 0x3C]
_0802DBBE:
	movs r0, 0
	bl sub_802DC28
	movs r0, 0x1
_0802DBC6:
	add sp, 0x8
	pop {r4-r6}
	pop {r1}
	bx r1
	.align 2, 0
_0802DBD0: .4byte gUnknown_203B2FC
	thumb_func_end sub_802DB28

	thumb_func_start sub_802DBD4
sub_802DBD4:
	push {lr}
	ldr r0, _0802DBEC
	ldr r0, [r0]
	ldr r1, [r0]
	cmp r1, 0x6
	beq _0802DBF0
	cmp r1, 0x7
	bne _0802DBF6
	ldr r0, [r0, 0x34]
	strb r1, [r0]
	movs r0, 0x3
	b _0802DBFC
	.align 2, 0
_0802DBEC: .4byte gUnknown_203B2FC
_0802DBF0:
	bl sub_802DE44
	b _0802DBFA
_0802DBF6:
	bl sub_802DE60
_0802DBFA:
	movs r0, 0
_0802DBFC:
	pop {r1}
	bx r1
	thumb_func_end sub_802DBD4

	thumb_func_start sub_802DC00
sub_802DC00:
	push {r4,lr}
	ldr r4, _0802DC24
	ldr r0, [r4]
	cmp r0, 0
	beq _0802DC1E
	ldr r0, [r0, 0x38]
	cmp r0, 0
	beq _0802DC14
	bl CloseFile
_0802DC14:
	ldr r0, [r4]
	bl MemoryFree
	movs r0, 0
	str r0, [r4]
_0802DC1E:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0802DC24: .4byte gUnknown_203B2FC
	thumb_func_end sub_802DC00

	thumb_func_start sub_802DC28
sub_802DC28:
	push {lr}
	ldr r1, _0802DC3C
	ldr r1, [r1]
	str r0, [r1]
	bl sub_802DC40
	bl sub_802DC9C
	pop {r0}
	bx r0
	.align 2, 0
_0802DC3C: .4byte gUnknown_203B2FC
	thumb_func_end sub_802DC28

	thumb_func_start sub_802DC40
sub_802DC40:
	push {r4-r7,lr}
	ldr r4, _0802DC94
	ldr r0, [r4]
	adds r0, 0x48
	bl sub_8006518
	ldr r0, [r4]
	ldr r0, [r0]
	cmp r0, 0
	beq _0802DC58
	cmp r0, 0x7
	bne _0802DC7A
_0802DC58:
	mov r12, r4
	ldr r4, _0802DC98
	movs r3, 0
	movs r2, 0x3
_0802DC60:
	mov r0, r12
	ldr r1, [r0]
	adds r1, r3
	adds r1, 0x48
	adds r0, r4, 0
	ldm r0!, {r5-r7}
	stm r1!, {r5-r7}
	ldm r0!, {r5-r7}
	stm r1!, {r5-r7}
	adds r3, 0x18
	subs r2, 0x1
	cmp r2, 0
	bge _0802DC60
_0802DC7A:
	bl ResetUnusedInputStruct
	ldr r0, _0802DC94
	ldr r0, [r0]
	adds r0, 0x48
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_0802DC94: .4byte gUnknown_203B2FC
_0802DC98: .4byte gUnknown_80E016C
	thumb_func_end sub_802DC40

	thumb_func_start sub_802DC9C
sub_802DC9C:
	push {r4,r5,lr}
	ldr r1, _0802DCB8
	ldr r0, [r1]
	ldr r0, [r0]
	adds r5, r1, 0
	cmp r0, 0x7
	bls _0802DCAC
	b _0802DE3E
_0802DCAC:
	lsls r0, 2
	ldr r1, _0802DCBC
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0802DCB8: .4byte gUnknown_203B2FC
_0802DCBC: .4byte _0802DCC0
	.align 2, 0
_0802DCC0:
	.4byte _0802DCE0
	.4byte _0802DDDC
	.4byte _0802DDE4
	.4byte _0802DDEC
	.4byte _0802DDFC
	.4byte _0802DDF4
	.4byte _0802DE34
	.4byte _0802DE3E
_0802DCE0:
	ldr r0, _0802DD60
	ldr r1, [r5]
	ldr r1, [r1, 0x34]
	movs r2, 0xC
	ldrsh r1, [r1, r2]
	bl sub_808D8E0
	ldr r4, _0802DD64
	ldr r0, [r5]
	ldr r0, [r0, 0x34]
	movs r2, 0xC
	ldrsh r1, [r0, r2]
	adds r0, r4, 0
	bl sub_808D8E0
	ldr r0, [r5]
	ldr r0, [r0, 0x34]
	movs r1, 0xC
	ldrsh r0, [r0, r1]
	bl GetMonSpecies
	adds r1, r0, 0
	ldr r2, _0802DD68
	adds r0, r4, r2
	bl strcpy
	ldr r0, [r5]
	ldr r0, [r0, 0x34]
	movs r1, 0xE
	ldrsh r0, [r0, r1]
	bl GetMonSpecies
	adds r1, r0, 0
	ldr r2, _0802DD6C
	adds r4, r2
	adds r0, r4, 0
	bl strcpy
	ldr r0, [r5]
	ldr r0, [r0, 0x34]
	movs r1, 0xC
	ldrsh r0, [r0, r1]
	bl sub_8098214
	ldr r0, _0802DD70
	ldr r1, [r5]
	ldr r1, [r1, 0x34]
	ldrb r1, [r1, 0x10]
	movs r2, 0
	bl sub_8090DC4
	ldr r1, [r5]
	movs r0, 0x6
	str r0, [r1, 0x4]
	ldr r0, [r1, 0x34]
	ldrb r0, [r0, 0x1]
	cmp r0, 0x4
	bhi _0802DDD4
	lsls r0, 2
	ldr r1, _0802DD74
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0802DD60: .4byte gUnknown_202E5D8
_0802DD64: .4byte gUnknown_202E1C8
_0802DD68: .4byte 0xfffffdd0
_0802DD6C: .4byte 0xfffffe20
_0802DD70: .4byte gUnknown_202DE58
_0802DD74: .4byte _0802DD78
	.align 2, 0
_0802DD78:
	.4byte _0802DDD4
	.4byte _0802DD9C
	.4byte _0802DDB8
	.4byte _0802DD94
	.4byte _0802DD8C
_0802DD8C:
	movs r0, 0x5
	bl sub_802DC28
	b _0802DE3E
_0802DD94:
	movs r0, 0x4
	bl sub_802DC28
	b _0802DE3E
_0802DD9C:
	movs r0, 0x2
	bl sub_802DC28
	ldr r0, _0802DDB4
	ldr r0, [r0]
	ldr r0, [r0, 0x34]
	movs r2, 0xE
	ldrsh r0, [r0, r2]
	bl sub_8098214
	b _0802DE3E
	.align 2, 0
_0802DDB4: .4byte gUnknown_203B2FC
_0802DDB8:
	movs r0, 0x3
	bl sub_802DC28
	ldr r0, _0802DDD0
	ldr r0, [r0]
	ldr r0, [r0, 0x34]
	movs r1, 0xE
	ldrsh r0, [r0, r1]
	bl sub_8098214
	b _0802DE3E
	.align 2, 0
_0802DDD0: .4byte gUnknown_203B2FC
_0802DDD4:
	movs r0, 0x1
	bl sub_802DC28
	b _0802DE3E
_0802DDDC:
	ldr r0, _0802DDE0
	b _0802DE1C
	.align 2, 0
_0802DDE0: .4byte gUnknown_80E0184
_0802DDE4:
	ldr r0, _0802DDE8
	b _0802DE1C
	.align 2, 0
_0802DDE8: .4byte gUnknown_80E01A0
_0802DDEC:
	ldr r0, _0802DDF0
	b _0802DE1C
	.align 2, 0
_0802DDF0: .4byte gUnknown_80E01C4
_0802DDF4:
	ldr r0, _0802DDF8
	b _0802DE1C
	.align 2, 0
_0802DDF8: .4byte gUnknown_80E01F0
_0802DDFC:
	ldr r0, [r5]
	ldr r0, [r0, 0x34]
	ldrb r0, [r0, 0x10]
	bl sub_8091130
	adds r1, r0, 0
	movs r0, 0x1
	negs r0, r0
	cmp r1, r0
	beq _0802DE1A
	adds r0, r1, 0
	bl sub_80911F8
	bl sub_80910B4
_0802DE1A:
	ldr r0, _0802DE2C
_0802DE1C:
	ldr r2, [r5]
	adds r2, 0x38
	ldr r3, _0802DE30
	movs r1, 0
	bl sub_80141B4
	b _0802DE3E
	.align 2, 0
_0802DE2C: .4byte gUnknown_80E0218
_0802DE30: .4byte 0x0000010d
_0802DE34:
	ldr r0, [r5]
	adds r0, 0x8
	movs r1, 0x1
	bl sub_802F204
_0802DE3E:
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_802DC9C

	thumb_func_start sub_802DE44
sub_802DE44:
	push {lr}
	bl sub_802F298
	cmp r0, 0x1
	bls _0802DE5C
	cmp r0, 0x3
	bhi _0802DE5C
	bl sub_802F2C0
	movs r0, 0x7
	bl sub_802DC28
_0802DE5C:
	pop {r0}
	bx r0
	thumb_func_end sub_802DE44

	thumb_func_start sub_802DE60
sub_802DE60:
	push {lr}
	sub sp, 0x4
	mov r0, sp
	bl sub_80144A4
	cmp r0, 0
	bne _0802DE78
	ldr r0, _0802DE80
	ldr r0, [r0]
	ldr r0, [r0, 0x4]
	bl sub_802DC28
_0802DE78:
	add sp, 0x4
	pop {r0}
	bx r0
	.align 2, 0
_0802DE80: .4byte gUnknown_203B2FC
	thumb_func_end sub_802DE60

	thumb_func_start sub_802DE84
sub_802DE84:
	push {r4,r5,lr}
	adds r5, r0, 0
	ldr r4, _0802DED8
	movs r0, 0x7C
	movs r1, 0x8
	bl MemoryAlloc
	str r0, [r4]
	str r5, [r0, 0xC]
	bl sub_801317C
	ldr r0, [r4]
	ldr r1, [r0, 0xC]
	ldr r2, [r1]
	str r2, [r0, 0x10]
	lsls r1, r2, 1
	adds r1, r2
	lsls r1, 3
	adds r1, 0x18
	adds r1, r0, r1
	str r1, [r0, 0x14]
	adds r0, 0x18
	bl sub_8006518
	ldr r1, [r4]
	ldr r2, [r1, 0x10]
	lsls r0, r2, 1
	adds r0, r2
	lsls r0, 3
	adds r1, r0
	adds r1, 0x18
	ldr r0, _0802DEDC
	ldm r0!, {r2-r4}
	stm r1!, {r2-r4}
	ldm r0!, {r2-r4}
	stm r1!, {r2-r4}
	bl sub_802DF14
	movs r0, 0x1
	pop {r4,r5}
	pop {r1}
	bx r1
	.align 2, 0
_0802DED8: .4byte gUnknown_203B300
_0802DEDC: .4byte gUnknown_80E0264
	thumb_func_end sub_802DE84

	thumb_func_start sub_802DEE0
sub_802DEE0:
	push {lr}
	ldr r0, _0802DF00
	ldr r0, [r0]
	ldr r1, [r0, 0x10]
	bl sub_8012A64
	cmp r0, 0x1
	beq _0802DF04
	cmp r0, 0x2
	bne _0802DF0E
	movs r0, 0x1
	bl sub_80119D4
	movs r0, 0x2
	b _0802DF10
	.align 2, 0
_0802DF00: .4byte gUnknown_203B300
_0802DF04:
	movs r0, 0
	bl sub_80119D4
	movs r0, 0x3
	b _0802DF10
_0802DF0E:
	movs r0, 0
_0802DF10:
	pop {r1}
	bx r1
	thumb_func_end sub_802DEE0

	thumb_func_start sub_802DF14
sub_802DF14:
	push {lr}
	bl sub_802DF6C
	bl sub_802DF88
	pop {r0}
	bx r0
	thumb_func_end sub_802DF14

	thumb_func_start sub_802DF24
sub_802DF24:
	push {r4,r5,lr}
	ldr r4, _0802DF64
	ldr r2, [r4]
	cmp r2, 0
	beq _0802DF5E
	ldr r0, [r2, 0x10]
	lsls r1, r0, 1
	adds r1, r0
	lsls r1, 3
	adds r1, r2, r1
	adds r1, 0x18
	ldr r0, _0802DF68
	ldm r0!, {r2,r3,r5}
	stm r1!, {r2,r3,r5}
	ldm r0!, {r2,r3,r5}
	stm r1!, {r2,r3,r5}
	bl ResetUnusedInputStruct
	ldr r0, [r4]
	adds r0, 0x18
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	ldr r0, [r4]
	bl MemoryFree
	movs r0, 0
	str r0, [r4]
_0802DF5E:
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_0802DF64: .4byte gUnknown_203B300
_0802DF68: .4byte gUnknown_80E0248
	thumb_func_end sub_802DF24

	thumb_func_start sub_802DF6C
sub_802DF6C:
	push {lr}
	bl ResetUnusedInputStruct
	ldr r0, _0802DF84
	ldr r0, [r0]
	adds r0, 0x18
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	pop {r0}
	bx r0
	.align 2, 0
_0802DF84: .4byte gUnknown_203B300
	thumb_func_end sub_802DF6C

	thumb_func_start sub_802DF88
sub_802DF88:
	push {r4,lr}
	ldr r4, _0802DFAC
	ldr r0, [r4]
	ldr r0, [r0, 0x10]
	bl sub_80073B8
	ldr r0, [r4]
	ldr r0, [r0, 0xC]
	bl sub_803B98C
	ldr r0, [r4]
	ldr r0, [r0, 0x10]
	bl sub_80073E0
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0802DFAC: .4byte gUnknown_203B300
	thumb_func_end sub_802DF88

	thumb_func_start sub_802DFB0
sub_802DFB0:
	push {r4,lr}
	ldr r4, _0802DFD4
	movs r0, 0xB6
	lsls r0, 1
	movs r1, 0x8
	bl MemoryAlloc
	str r0, [r4]
	movs r1, 0
	str r1, [r0, 0x64]
	str r1, [r0, 0x68]
	movs r0, 0
	bl sub_802E088
	movs r0, 0x1
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_0802DFD4: .4byte gUnknown_203B304
	thumb_func_end sub_802DFB0

	thumb_func_start sub_802DFD8
sub_802DFD8:
	push {lr}
	ldr r0, _0802DFF0
	ldr r0, [r0]
	ldr r0, [r0]
	cmp r0, 0xB
	bhi _0802E060
	lsls r0, 2
	ldr r1, _0802DFF4
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0802DFF0: .4byte gUnknown_203B304
_0802DFF4: .4byte _0802DFF8
	.align 2, 0
_0802DFF8:
	.4byte _0802E028
	.4byte _0802E030
	.4byte _0802E036
	.4byte _0802E060
	.4byte _0802E03C
	.4byte _0802E03C
	.4byte _0802E042
	.4byte _0802E048
	.4byte _0802E04E
	.4byte _0802E054
	.4byte _0802E054
	.4byte _0802E05A
_0802E028:
	movs r0, 0x1
	bl sub_802E088
	b _0802E064
_0802E030:
	bl sub_802E4B0
	b _0802E064
_0802E036:
	bl nullsub_133
	b _0802E064
_0802E03C:
	bl sub_802E578
	b _0802E064
_0802E042:
	bl sub_802E60C
	b _0802E064
_0802E048:
	bl sub_802E73C
	b _0802E064
_0802E04E:
	bl sub_802E758
	b _0802E064
_0802E054:
	bl sub_802E774
	b _0802E064
_0802E05A:
	bl sub_802E7D0
	b _0802E064
_0802E060:
	movs r0, 0x3
	b _0802E066
_0802E064:
	movs r0, 0
_0802E066:
	pop {r1}
	bx r1
	thumb_func_end sub_802DFD8

	thumb_func_start sub_802E06C
sub_802E06C:
	push {r4,lr}
	ldr r4, _0802E084
	ldr r0, [r4]
	cmp r0, 0
	beq _0802E07E
	bl MemoryFree
	movs r0, 0
	str r0, [r4]
_0802E07E:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0802E084: .4byte gUnknown_203B304
	thumb_func_end sub_802E06C

	thumb_func_start sub_802E088
sub_802E088:
	push {lr}
	ldr r1, _0802E09C
	ldr r1, [r1]
	str r0, [r1]
	bl sub_802E0A0
	bl sub_802E1AC
	pop {r0}
	bx r0
	.align 2, 0
_0802E09C: .4byte gUnknown_203B304
	thumb_func_end sub_802E088

	thumb_func_start sub_802E0A0
sub_802E0A0:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	ldr r4, _0802E0C8
	ldr r0, [r4]
	movs r6, 0x86
	lsls r6, 1
	adds r0, r6
	bl sub_8006518
	ldr r0, [r4]
	ldr r5, [r0]
	cmp r5, 0x1
	beq _0802E0D0
	cmp r5, 0x6
	beq _0802E124
	movs r3, 0
	ldr r2, _0802E0CC
	b _0802E168
	.align 2, 0
_0802E0C8: .4byte gUnknown_203B304
_0802E0CC: .4byte gUnknown_80E0284
_0802E0D0:
	mov r12, r6
	ldr r0, _0802E118
	mov r8, r0
	movs r2, 0
	movs r3, 0x3
_0802E0DA:
	ldr r1, [r4]
	adds r1, r2
	add r1, r12
	mov r0, r8
	ldm r0!, {r5-r7}
	stm r1!, {r5-r7}
	ldm r0!, {r5-r7}
	stm r1!, {r5-r7}
	adds r2, 0x18
	subs r3, 0x1
	cmp r3, 0
	bge _0802E0DA
	bl CreateMailboxMenu
	ldr r3, _0802E11C
	ldr r2, [r3]
	movs r0, 0x9E
	lsls r0, 1
	adds r2, r0
	ldr r1, _0802E120
	ldm r1!, {r4-r6}
	stm r2!, {r4-r6}
	ldm r1!, {r4,r5,r7}
	stm r2!, {r4,r5,r7}
	ldr r1, [r3]
	adds r0, r1, r0
	adds r1, 0xBC
	bl sub_8012CAC
	b _0802E188
	.align 2, 0
_0802E118: .4byte gUnknown_80E0284
_0802E11C: .4byte gUnknown_203B304
_0802E120: .4byte gUnknown_80E029C
_0802E124:
	bl CreateMailActionMenu
	ldr r2, [r4]
	movs r0, 0x9E
	lsls r0, 1
	adds r2, r0
	ldr r1, _0802E160
	ldm r1!, {r3,r6,r7}
	stm r2!, {r3,r6,r7}
	ldm r1!, {r3,r6,r7}
	stm r2!, {r3,r6,r7}
	ldr r1, [r4]
	adds r0, r1, r0
	adds r1, 0xBC
	bl sub_8012CAC
	ldr r1, [r4]
	movs r4, 0xA4
	lsls r4, 1
	adds r0, r1, r4
	strh r5, [r0]
	movs r5, 0xAA
	lsls r5, 1
	adds r1, r5
	ldr r0, _0802E164
	ldm r0!, {r2,r6,r7}
	stm r1!, {r2,r6,r7}
	ldm r0!, {r3-r5}
	stm r1!, {r3-r5}
	b _0802E188
	.align 2, 0
_0802E160: .4byte gUnknown_80E02B4
_0802E164: .4byte gUnknown_80E02CC
_0802E168:
	ldr r0, [r4]
	lsls r1, r3, 1
	adds r1, r3
	lsls r1, 3
	adds r0, r1
	movs r6, 0x86
	lsls r6, 1
	adds r0, r6
	adds r1, r2, 0
	ldm r1!, {r5-r7}
	stm r0!, {r5-r7}
	ldm r1!, {r5-r7}
	stm r0!, {r5-r7}
	adds r3, 0x1
	cmp r3, 0x3
	ble _0802E168
_0802E188:
	bl ResetUnusedInputStruct
	ldr r0, _0802E1A8
	ldr r0, [r0]
	movs r7, 0x86
	lsls r7, 1
	adds r0, r7
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_0802E1A8: .4byte gUnknown_203B304
	thumb_func_end sub_802E0A0

	thumb_func_start sub_802E1AC
sub_802E1AC:
	push {r4,lr}
	sub sp, 0x8
	ldr r1, _0802E1C8
	ldr r0, [r1]
	ldr r0, [r0]
	adds r4, r1, 0
	cmp r0, 0xB
	bhi _0802E2AA
	lsls r0, 2
	ldr r1, _0802E1CC
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0802E1C8: .4byte gUnknown_203B304
_0802E1CC: .4byte _0802E1D0
	.align 2, 0
_0802E1D0:
	.4byte _0802E2AA
	.4byte _0802E200
	.4byte _0802E2AA
	.4byte _0802E2AA
	.4byte _0802E21E
	.4byte _0802E22A
	.4byte _0802E232
	.4byte _0802E260
	.4byte _0802E286
	.4byte _0802E28E
	.4byte _0802E29A
	.4byte _0802E2A2
_0802E200:
	ldr r2, [r4]
	adds r0, r2, 0
	adds r0, 0x6C
	adds r1, r2, 0
	adds r1, 0xBC
	adds r3, r2, 0
	adds r3, 0xFC
	ldr r2, [r2, 0x64]
	str r2, [sp]
	movs r2, 0x2
	str r2, [sp, 0x4]
	movs r2, 0
	bl sub_8012D60
	b _0802E2AA
_0802E21E:
	movs r0, 0
	movs r1, 0
	movs r2, 0x4
	bl sub_802BD14
	b _0802E2AA
_0802E22A:
	movs r0, 0x1
	bl sub_802BE94
	b _0802E2AA
_0802E232:
	bl CreateMailMenu
	movs r0, 0x3
	bl CreateMailAcceptedStatusBox
	ldr r0, _0802E25C
	ldr r2, [r0]
	adds r0, r2, 0
	adds r0, 0x6C
	adds r1, r2, 0
	adds r1, 0xBC
	ldr r2, [r2, 0x68]
	str r2, [sp]
	movs r2, 0x2
	str r2, [sp, 0x4]
	movs r2, 0
	movs r3, 0
	bl sub_8012D60
	b _0802E2AA
	.align 2, 0
_0802E25C: .4byte gUnknown_203B304
_0802E260:
	ldr r0, [r4]
	ldrb r0, [r0, 0x8]
	bl sub_8095FE8
	ldr r1, [r4]
	adds r1, 0xC
	bl sub_803B35C
	ldr r0, [r4]
	movs r1, 0x3
	str r1, [r0, 0xC]
	adds r0, 0x50
	movs r1, 0
	strb r1, [r0]
	ldr r0, [r4]
	adds r0, 0xC
	bl sub_802DE84
	b _0802E2AA
_0802E286:
	movs r0, 0
	bl sub_802C860
	b _0802E2AA
_0802E28E:
	movs r0, 0
	movs r1, 0
	movs r2, 0x8
	bl sub_802B640
	b _0802E2AA
_0802E29A:
	movs r0, 0x1
	bl sub_802B7D0
	b _0802E2AA
_0802E2A2:
	ldr r0, [r4]
	ldrb r0, [r0, 0x9]
	bl sub_802B9FC
_0802E2AA:
	add sp, 0x8
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_802E1AC

	thumb_func_start CreateMailboxMenu
CreateMailboxMenu:
	push {r4-r7,lr}
	ldr r4, _0802E380
	ldr r0, [r4]
	adds r0, 0xFC
	movs r1, 0
	movs r2, 0x10
	bl MemoryFill16
	ldr r1, [r4]
	adds r2, r1, 0
	adds r2, 0xBC
	ldr r0, _0802E384
	str r0, [r2]
	adds r1, 0xC0
	movs r0, 0x2
	str r0, [r1]
	bl sub_802C0E8
	lsls r0, 24
	cmp r0, 0
	beq _0802E2E6
	ldr r0, [r4]
	adds r0, 0xFC
	movs r1, 0x1
	strh r1, [r0]
_0802E2E6:
	movs r5, 0x1
	ldr r1, [r4]
	movs r6, 0x1
	adds r2, r1, 0
	adds r2, 0xC4
	ldr r0, _0802E388
	str r0, [r2]
	adds r1, 0xC8
	movs r0, 0x3
	str r0, [r1]
	bl sub_802C83C
	lsls r0, 24
	cmp r0, 0
	beq _0802E30A
	ldr r0, [r4]
	adds r0, 0xFE
	strh r5, [r0]
_0802E30A:
	ldr r1, [r4]
	adds r2, r1, 0
	adds r2, 0xCC
	ldr r0, _0802E38C
	str r0, [r2]
	adds r1, 0xD0
	movs r0, 0x4
	str r0, [r1]
	bl sub_802B9D8
	lsls r0, 24
	cmp r0, 0
	beq _0802E32E
	ldr r0, [r4]
	movs r1, 0x80
	lsls r1, 1
	adds r0, r1
	strh r6, [r0]
_0802E32E:
	movs r5, 0x3
	ldr r2, [r4]
	adds r0, r2, 0
	adds r0, 0xD4
	movs r1, 0
	str r1, [r0]
	adds r0, 0x4
	str r6, [r0]
	movs r3, 0
	adds r6, r4, 0
	mov r12, r2
	mov r4, r12
	adds r4, 0xFC
	adds r2, 0xC0
_0802E34A:
	ldrh r0, [r4]
	cmp r0, 0
	bne _0802E35A
	ldr r1, [r2]
	mov r7, r12
	ldr r0, [r7, 0x64]
	cmp r1, r0
	beq _0802E3B2
_0802E35A:
	adds r4, 0x2
	adds r2, 0x8
	adds r3, 0x1
	cmp r3, r5
	blt _0802E34A
	movs r3, 0
	cmp r3, r5
	bge _0802E3B2
	ldr r1, [r6]
	adds r0, r1, 0
	adds r0, 0xFC
	ldrh r0, [r0]
	cmp r0, 0
	bne _0802E390
	adds r0, r1, 0
	adds r0, 0xC0
	ldr r0, [r0]
	str r0, [r1, 0x64]
	b _0802E3B2
	.align 2, 0
_0802E380: .4byte gUnknown_203B304
_0802E384: .4byte gMailboxCheckMail
_0802E388: .4byte gMailboxJobList
_0802E38C: .4byte gMailboxPKMNNews
_0802E390:
	adds r3, 0x1
	cmp r3, r5
	bge _0802E3B2
	ldr r2, [r6]
	lsls r0, r3, 1
	adds r1, r2, 0
	adds r1, 0xFC
	adds r1, r0
	ldrh r0, [r1]
	cmp r0, 0
	bne _0802E390
	lsls r0, r3, 3
	adds r1, r2, 0
	adds r1, 0xC0
	adds r1, r0
	ldr r0, [r1]
	str r0, [r2, 0x64]
_0802E3B2:
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end CreateMailboxMenu

	thumb_func_start CreateMailActionMenu
CreateMailActionMenu:
	push {r4-r7,lr}
	movs r5, 0
	ldr r4, _0802E3F0
	ldr r0, [r4]
	ldrb r0, [r0, 0x8]
	bl sub_8095FE8
	adds r7, r0, 0
	ldrb r0, [r7]
	cmp r0, 0x1
	bne _0802E3FC
	ldr r2, [r4]
	adds r1, r2, 0
	adds r1, 0xBC
	ldr r0, _0802E3F4
	str r0, [r1]
	adds r1, 0x4
	movs r0, 0x6
	str r0, [r1]
	adds r1, 0x4
	ldr r0, _0802E3F8
	str r0, [r1]
	adds r1, 0x4
	movs r0, 0x7
	str r0, [r1]
	movs r5, 0x2
	b _0802E44A
	.align 2, 0
_0802E3F0: .4byte gUnknown_203B304
_0802E3F4: .4byte gMailActionStore
_0802E3F8: .4byte gMailActionRead
_0802E3FC:
	ldr r1, [r4]
	adds r2, r1, 0
	adds r2, 0xBC
	ldr r0, _0802E494
	ldr r0, [r0]
	str r0, [r2]
	adds r1, 0xC0
	movs r0, 0x5
	str r0, [r1]
	adds r0, r7, 0
	bl sub_80968B0
	lsls r0, 24
	cmp r0, 0
	bne _0802E422
	bl sub_80969AC
	cmp r0, 0x7
	ble _0802E42C
_0802E422:
	ldr r0, [r4]
	adds r0, 0xC0
	movs r1, 0x1
	negs r1, r1
	str r1, [r0]
_0802E42C:
	adds r5, 0x1
	ldr r4, _0802E498
	ldr r2, [r4]
	lsls r3, r5, 3
	adds r0, r2, 0
	adds r0, 0xBC
	adds r0, r3
	ldr r1, _0802E49C
	ldr r1, [r1]
	str r1, [r0]
	adds r2, 0xC0
	adds r2, r3
	movs r0, 0x8
	str r0, [r2]
	adds r5, 0x1
_0802E44A:
	mov r12, r4
	mov r0, r12
	ldr r4, [r0]
	lsls r2, r5, 3
	adds r0, r4, 0
	adds r0, 0xBC
	adds r0, r2
	movs r1, 0
	str r1, [r0]
	adds r1, r4, 0
	adds r1, 0xC0
	adds r2, r1, r2
	movs r0, 0x1
	str r0, [r2]
	movs r3, 0
	cmp r3, r5
	bge _0802E486
	movs r6, 0x1
	negs r6, r6
	adds r2, r1, 0
_0802E472:
	ldr r1, [r2]
	cmp r1, r6
	beq _0802E47E
	ldr r0, [r4, 0x68]
	cmp r1, r0
	beq _0802E4A8
_0802E47E:
	adds r2, 0x8
	adds r3, 0x1
	cmp r3, r5
	blt _0802E472
_0802E486:
	ldrb r0, [r7]
	cmp r0, 0x1
	bne _0802E4A0
	mov r0, r12
	ldr r1, [r0]
	movs r0, 0x7
	b _0802E4A6
	.align 2, 0
_0802E494: .4byte gUnknown_80D4990
_0802E498: .4byte gUnknown_203B304
_0802E49C: .4byte gUnknown_80D4970
_0802E4A0:
	mov r0, r12
	ldr r1, [r0]
	movs r0, 0x8
_0802E4A6:
	str r0, [r1, 0x68]
_0802E4A8:
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end CreateMailActionMenu

	thumb_func_start sub_802E4B0
sub_802E4B0:
	push {r4,lr}
	sub sp, 0x4
	movs r0, 0
	str r0, [sp]
	ldr r4, _0802E4F0
	ldr r0, [r4]
	adds r0, 0x6C
	bl sub_8012FD8
	lsls r0, 24
	cmp r0, 0
	bne _0802E4DC
	ldr r0, [r4]
	adds r0, 0x6C
	mov r1, sp
	bl sub_8013114
	ldr r1, [sp]
	cmp r1, 0x1
	beq _0802E4DC
	ldr r0, [r4]
	str r1, [r0, 0x64]
_0802E4DC:
	ldr r0, [sp]
	subs r0, 0x1
	cmp r0, 0x7
	bhi _0802E56E
	lsls r0, 2
	ldr r1, _0802E4F4
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0802E4F0: .4byte gUnknown_203B304
_0802E4F4: .4byte _0802E4F8
	.align 2, 0
_0802E4F8:
	.4byte _0802E568
	.4byte _0802E518
	.4byte _0802E52A
	.4byte _0802E53C
	.4byte _0802E56E
	.4byte _0802E56E
	.4byte _0802E56E
	.4byte _0802E560
_0802E518:
	bl sub_802C0E8
	lsls r0, 24
	cmp r0, 0
	bne _0802E54E
	movs r0, 0x4
	bl sub_802E088
	b _0802E56E
_0802E52A:
	bl sub_802C83C
	lsls r0, 24
	cmp r0, 0
	bne _0802E54E
	movs r0, 0x8
	bl sub_802E088
	b _0802E56E
_0802E53C:
	bl sub_802B9D8
	lsls r0, 24
	cmp r0, 0
	bne _0802E54E
	movs r0, 0x9
	bl sub_802E088
	b _0802E56E
_0802E54E:
	ldr r0, _0802E55C
	ldr r0, [r0]
	adds r0, 0x6C
	movs r1, 0x1
	bl sub_8012EA4
	b _0802E56E
	.align 2, 0
_0802E55C: .4byte gUnknown_203B304
_0802E560:
	movs r0, 0x2
	bl sub_802E088
	b _0802E56E
_0802E568:
	movs r0, 0x3
	bl sub_802E088
_0802E56E:
	add sp, 0x4
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_802E4B0

	thumb_func_start sub_802E578
sub_802E578:
	push {r4,lr}
	movs r0, 0x1
	bl sub_802BDEC
	cmp r0, 0x4
	bhi _0802E606
	lsls r0, 2
	ldr r1, _0802E590
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0802E590: .4byte _0802E594
	.align 2, 0
_0802E594:
	.4byte _0802E606
	.4byte _0802E606
	.4byte _0802E5FC
	.4byte _0802E5A8
	.4byte _0802E5C0
_0802E5A8:
	bl sub_802BE74
	ldr r1, _0802E5BC
	ldr r1, [r1]
	strb r0, [r1, 0x8]
	movs r0, 0x6
	bl sub_802E088
	b _0802E606
	.align 2, 0
_0802E5BC: .4byte gUnknown_203B304
_0802E5C0:
	bl sub_802BE74
	ldr r4, _0802E5F0
	ldr r1, [r4]
	strb r0, [r1, 0x8]
	ldr r0, [r4]
	ldrb r0, [r0, 0x8]
	bl sub_8095FE8
	adds r2, r0, 0
	ldrb r0, [r2]
	cmp r0, 0x1
	bne _0802E5F4
	ldr r1, [r4]
	ldrb r0, [r2, 0x5]
	strb r0, [r1, 0x9]
	ldr r1, [r4]
	movs r0, 0x5
	str r0, [r1, 0x4]
	movs r0, 0xB
	bl sub_802E088
	b _0802E606
	.align 2, 0
_0802E5F0: .4byte gUnknown_203B304
_0802E5F4:
	movs r0, 0x7
	bl sub_802E088
	b _0802E606
_0802E5FC:
	bl sub_802BEDC
	movs r0, 0x1
	bl sub_802E088
_0802E606:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_802E578

	thumb_func_start sub_802E60C
sub_802E60C:
	push {r4,lr}
	sub sp, 0x4
	movs r0, 0
	str r0, [sp]
	bl sub_802BDEC
	ldr r4, _0802E650
	ldr r0, [r4]
	adds r0, 0x6C
	bl sub_8012FD8
	lsls r0, 24
	cmp r0, 0
	bne _0802E63C
	ldr r0, [r4]
	adds r0, 0x6C
	mov r1, sp
	bl sub_8013114
	ldr r1, [sp]
	cmp r1, 0x1
	beq _0802E63C
	ldr r0, [r4]
	str r1, [r0, 0x68]
_0802E63C:
	ldr r0, [sp]
	subs r0, 0x1
	cmp r0, 0x7
	bhi _0802E732
	lsls r0, 2
	ldr r1, _0802E654
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0802E650: .4byte gUnknown_203B304
_0802E654: .4byte _0802E658
	.align 2, 0
_0802E658:
	.4byte _0802E72C
	.4byte _0802E732
	.4byte _0802E732
	.4byte _0802E732
	.4byte _0802E678
	.4byte _0802E6BC
	.4byte _0802E704
	.4byte _0802E6B4
_0802E678:
	ldr r0, _0802E6AC
	bl sub_8011988
	ldr r4, _0802E6B0
	ldr r0, [r4]
	ldrb r0, [r0, 0x8]
	bl sub_8095FE8
	bl sub_8096A78
	bl sub_8096C80
	bl sub_8096D24
	ldr r0, [r4]
	ldrb r0, [r0, 0x8]
	bl sub_8096040
	bl sub_8096078
	bl sub_802C0E8
	lsls r0, 24
	cmp r0, 0
	bne _0802E6E8
	b _0802E6FC
	.align 2, 0
_0802E6AC: .4byte 0x00000133
_0802E6B0: .4byte gUnknown_203B304
_0802E6B4:
	movs r0, 0x7
	bl sub_802E088
	b _0802E732
_0802E6BC:
	ldr r0, _0802E6F4
	bl sub_8011988
	ldr r4, _0802E6F8
	ldr r0, [r4]
	ldrb r0, [r0, 0x8]
	bl sub_8095FE8
	ldrb r0, [r0, 0x5]
	bl sub_8096DF8
	ldr r0, [r4]
	ldrb r0, [r0, 0x8]
	bl sub_8096040
	bl sub_8096078
	bl sub_802C0E8
	lsls r0, 24
	cmp r0, 0
	beq _0802E6FC
_0802E6E8:
	bl sub_802BEDC
	movs r0, 0x1
	bl sub_802E088
	b _0802E732
	.align 2, 0
_0802E6F4: .4byte 0x00000133
_0802E6F8: .4byte gUnknown_203B304
_0802E6FC:
	movs r0, 0x5
	bl sub_802E088
	b _0802E732
_0802E704:
	movs r0, 0
	bl sub_80119D4
	ldr r4, _0802E728
	ldr r0, [r4]
	ldrb r0, [r0, 0x8]
	bl sub_8095FE8
	ldr r1, [r4]
	ldrb r0, [r0, 0x5]
	strb r0, [r1, 0x9]
	ldr r1, [r4]
	movs r0, 0x5
	str r0, [r1, 0x4]
	movs r0, 0xB
	bl sub_802E088
	b _0802E732
	.align 2, 0
_0802E728: .4byte gUnknown_203B304
_0802E72C:
	movs r0, 0x5
	bl sub_802E088
_0802E732:
	add sp, 0x4
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_802E60C

	thumb_func_start sub_802E73C
sub_802E73C:
	push {lr}
	bl sub_802DEE0
	cmp r0, 0x1
	bls _0802E754
	cmp r0, 0x3
	bhi _0802E754
	bl sub_802DF24
	movs r0, 0x5
	bl sub_802E088
_0802E754:
	pop {r0}
	bx r0
	thumb_func_end sub_802E73C

	thumb_func_start sub_802E758
sub_802E758:
	push {lr}
	bl sub_802C898
	cmp r0, 0x1
	bls _0802E770
	cmp r0, 0x3
	bhi _0802E770
	bl sub_802C8F4
	movs r0, 0x1
	bl sub_802E088
_0802E770:
	pop {r0}
	bx r0
	thumb_func_end sub_802E758

	thumb_func_start sub_802E774
sub_802E774:
	push {lr}
	movs r0, 0x1
	bl sub_802B720
	cmp r0, 0x4
	bhi _0802E7CA
	lsls r0, 2
	ldr r1, _0802E78C
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0802E78C: .4byte _0802E790
	.align 2, 0
_0802E790:
	.4byte _0802E7CA
	.4byte _0802E7CA
	.4byte _0802E7C0
	.4byte _0802E7A4
	.4byte _0802E7A4
_0802E7A4:
	bl sub_802B7A8
	ldr r2, _0802E7BC
	ldr r1, [r2]
	strb r0, [r1, 0x9]
	ldr r1, [r2]
	movs r0, 0xA
	str r0, [r1, 0x4]
	movs r0, 0xB
	bl sub_802E088
	b _0802E7CA
	.align 2, 0
_0802E7BC: .4byte gUnknown_203B304
_0802E7C0:
	bl sub_802B81C
	movs r0, 0x1
	bl sub_802E088
_0802E7CA:
	pop {r0}
	bx r0
	thumb_func_end sub_802E774

	thumb_func_start sub_802E7D0
sub_802E7D0:
	push {lr}
	bl sub_802BA8C
	cmp r0, 0x1
	bls _0802E7EC
	cmp r0, 0x3
	bhi _0802E7EC
	bl sub_802BACC
	ldr r0, _0802E7F0
	ldr r0, [r0]
	ldr r0, [r0, 0x4]
	bl sub_802E088
_0802E7EC:
	pop {r0}
	bx r0
	.align 2, 0
_0802E7F0: .4byte gUnknown_203B304
	thumb_func_end sub_802E7D0

	thumb_func_start nullsub_133
nullsub_133:
	bx lr
	thumb_func_end nullsub_133

	thumb_func_start CreateMailAcceptedStatusBox
CreateMailAcceptedStatusBox:
	push {r4-r6,lr}
	sub sp, 0x8
	adds r4, r0, 0
	bl sub_8008C54
	adds r0, r4, 0
	bl sub_80073B8
	ldr r2, _0802E85C
	movs r6, 0
	str r6, [sp]
	movs r0, 0x3
	movs r1, 0
	adds r3, r4, 0
	bl xxx_call_draw_string
	bl sub_80969AC
	adds r2, r0, 0
	movs r5, 0x7
	str r5, [sp]
	str r4, [sp, 0x4]
	movs r0, 0x12
	movs r1, 0xD
	movs r3, 0x2
	bl sub_8012BC4
	ldr r2, _0802E860
	str r6, [sp]
	movs r0, 0x16
	movs r1, 0xD
	adds r3, r4, 0
	bl xxx_call_draw_string
	str r5, [sp]
	str r4, [sp, 0x4]
	movs r0, 0x23
	movs r1, 0xD
	movs r2, 0x8
	movs r3, 0x2
	bl sub_8012BC4
	adds r0, r4, 0
	bl sub_80073E0
	add sp, 0x8
	pop {r4-r6}
	pop {r0}
	bx r0
	.align 2, 0
_0802E85C: .4byte gMailAccepted
_0802E860: .4byte gUnknown_80E0324
	thumb_func_end CreateMailAcceptedStatusBox

	thumb_func_start sub_802E864
sub_802E864:
	push {r4,lr}
	ldr r4, _0802E88C
	movs r0, 0xB6
	lsls r0, 1
	movs r1, 0x8
	bl MemoryAlloc
	str r0, [r4]
	movs r1, 0
	str r1, [r0, 0x64]
	str r1, [r0, 0x68]
	str r1, [r0, 0x4]
	movs r0, 0
	bl sub_802E934
	movs r0, 0x1
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_0802E88C: .4byte gUnknown_203B308
	thumb_func_end sub_802E864

	thumb_func_start sub_802E890
sub_802E890:
	push {lr}
	ldr r0, _0802E8A8
	ldr r0, [r0]
	ldr r0, [r0]
	cmp r0, 0x8
	bhi _0802E900
	lsls r0, 2
	ldr r1, _0802E8AC
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0802E8A8: .4byte gUnknown_203B308
_0802E8AC: .4byte _0802E8B0
	.align 2, 0
_0802E8B0:
	.4byte _0802E8D4
	.4byte _0802E8DC
	.4byte _0802E8E2
	.4byte _0802E900
	.4byte _0802E8E8
	.4byte _0802E8E8
	.4byte _0802E8EE
	.4byte _0802E8F4
	.4byte _0802E8FA
_0802E8D4:
	movs r0, 0x1
	bl sub_802E934
	b _0802E904
_0802E8DC:
	bl sub_802ECB4
	b _0802E904
_0802E8E2:
	bl nullsub_134
	b _0802E904
_0802E8E8:
	bl sub_802ED4C
	b _0802E904
_0802E8EE:
	bl sub_802EDBC
	b _0802E904
_0802E8F4:
	bl sub_802EEA0
	b _0802E904
_0802E8FA:
	bl sub_802EEBC
	b _0802E904
_0802E900:
	movs r0, 0x3
	b _0802E906
_0802E904:
	movs r0, 0
_0802E906:
	pop {r1}
	bx r1
	thumb_func_end sub_802E890

	thumb_func_start sub_802E90C
sub_802E90C:
	ldr r0, _0802E914
	ldr r0, [r0]
	ldr r0, [r0, 0x4]
	bx lr
	.align 2, 0
_0802E914: .4byte gUnknown_203B308
	thumb_func_end sub_802E90C

	thumb_func_start sub_802E918
sub_802E918:
	push {r4,lr}
	ldr r4, _0802E930
	ldr r0, [r4]
	cmp r0, 0
	beq _0802E92A
	bl MemoryFree
	movs r0, 0
	str r0, [r4]
_0802E92A:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0802E930: .4byte gUnknown_203B308
	thumb_func_end sub_802E918

	thumb_func_start sub_802E934
sub_802E934:
	push {lr}
	ldr r1, _0802E948
	ldr r1, [r1]
	str r0, [r1]
	bl sub_802E94C
	bl sub_802EA58
	pop {r0}
	bx r0
	.align 2, 0
_0802E948: .4byte gUnknown_203B308
	thumb_func_end sub_802E934

	thumb_func_start sub_802E94C
sub_802E94C:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	ldr r4, _0802E974
	ldr r0, [r4]
	movs r6, 0x86
	lsls r6, 1
	adds r0, r6
	bl sub_8006518
	ldr r0, [r4]
	ldr r5, [r0]
	cmp r5, 0x1
	beq _0802E97C
	cmp r5, 0x6
	beq _0802E9D0
	movs r3, 0
	ldr r2, _0802E978
	b _0802EA14
	.align 2, 0
_0802E974: .4byte gUnknown_203B308
_0802E978: .4byte gUnknown_80E0330
_0802E97C:
	mov r12, r6
	ldr r0, _0802E9C4
	mov r8, r0
	movs r2, 0
	movs r3, 0x3
_0802E986:
	ldr r1, [r4]
	adds r1, r2
	add r1, r12
	mov r0, r8
	ldm r0!, {r5-r7}
	stm r1!, {r5-r7}
	ldm r0!, {r5-r7}
	stm r1!, {r5-r7}
	adds r2, 0x18
	subs r3, 0x1
	cmp r3, 0
	bge _0802E986
	bl CreatePelliperBoardMenu
	ldr r3, _0802E9C8
	ldr r2, [r3]
	movs r0, 0x9E
	lsls r0, 1
	adds r2, r0
	ldr r1, _0802E9CC
	ldm r1!, {r4-r6}
	stm r2!, {r4-r6}
	ldm r1!, {r4,r5,r7}
	stm r2!, {r4,r5,r7}
	ldr r1, [r3]
	adds r0, r1, r0
	adds r1, 0xBC
	bl sub_8012CAC
	b _0802EA34
	.align 2, 0
_0802E9C4: .4byte gUnknown_80E0330
_0802E9C8: .4byte gUnknown_203B308
_0802E9CC: .4byte gUnknown_80E0348
_0802E9D0:
	bl sub_802EC10
	ldr r2, [r4]
	movs r0, 0x9E
	lsls r0, 1
	adds r2, r0
	ldr r1, _0802EA0C
	ldm r1!, {r3,r6,r7}
	stm r2!, {r3,r6,r7}
	ldm r1!, {r3,r6,r7}
	stm r2!, {r3,r6,r7}
	ldr r1, [r4]
	adds r0, r1, r0
	adds r1, 0xBC
	bl sub_8012CAC
	ldr r1, [r4]
	movs r4, 0xA4
	lsls r4, 1
	adds r0, r1, r4
	strh r5, [r0]
	movs r5, 0xAA
	lsls r5, 1
	adds r1, r5
	ldr r0, _0802EA10
	ldm r0!, {r2,r6,r7}
	stm r1!, {r2,r6,r7}
	ldm r0!, {r3-r5}
	stm r1!, {r3-r5}
	b _0802EA34
	.align 2, 0
_0802EA0C: .4byte gUnknown_80E0360
_0802EA10: .4byte gUnknown_80E0378
_0802EA14:
	ldr r0, [r4]
	lsls r1, r3, 1
	adds r1, r3
	lsls r1, 3
	adds r0, r1
	movs r6, 0x86
	lsls r6, 1
	adds r0, r6
	adds r1, r2, 0
	ldm r1!, {r5-r7}
	stm r0!, {r5-r7}
	ldm r1!, {r5-r7}
	stm r0!, {r5-r7}
	adds r3, 0x1
	cmp r3, 0x3
	ble _0802EA14
_0802EA34:
	bl ResetUnusedInputStruct
	ldr r0, _0802EA54
	ldr r0, [r0]
	movs r7, 0x86
	lsls r7, 1
	adds r0, r7
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_0802EA54: .4byte gUnknown_203B308
	thumb_func_end sub_802E94C

	thumb_func_start sub_802EA58
sub_802EA58:
	push {r4,lr}
	sub sp, 0x8
	ldr r1, _0802EA74
	ldr r0, [r1]
	ldr r0, [r0]
	adds r4, r1, 0
	cmp r0, 0x8
	bhi _0802EB2C
	lsls r0, 2
	ldr r1, _0802EA78
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0802EA74: .4byte gUnknown_203B308
_0802EA78: .4byte _0802EA7C
	.align 2, 0
_0802EA7C:
	.4byte _0802EB2C
	.4byte _0802EAA0
	.4byte _0802EB2C
	.4byte _0802EB2C
	.4byte _0802EABE
	.4byte _0802EACA
	.4byte _0802EAD2
	.4byte _0802EB00
	.4byte _0802EB26
_0802EAA0:
	ldr r2, [r4]
	adds r0, r2, 0
	adds r0, 0x6C
	adds r1, r2, 0
	adds r1, 0xBC
	adds r3, r2, 0
	adds r3, 0xFC
	ldr r2, [r2, 0x64]
	str r2, [sp]
	movs r2, 0x2
	str r2, [sp, 0x4]
	movs r2, 0
	bl sub_8012D60
	b _0802EB2C
_0802EABE:
	movs r0, 0
	movs r1, 0
	movs r2, 0x4
	bl sub_802C10C
	b _0802EB2C
_0802EACA:
	movs r0, 0x1
	bl sub_802C28C
	b _0802EB2C
_0802EAD2:
	bl sub_802C39C
	movs r0, 0x3
	bl CreatePelliperAcceptedStatusBox
	ldr r0, _0802EAFC
	ldr r2, [r0]
	adds r0, r2, 0
	adds r0, 0x6C
	adds r1, r2, 0
	adds r1, 0xBC
	ldr r2, [r2, 0x68]
	str r2, [sp]
	movs r2, 0x2
	str r2, [sp, 0x4]
	movs r2, 0
	movs r3, 0
	bl sub_8012D60
	b _0802EB2C
	.align 2, 0
_0802EAFC: .4byte gUnknown_203B308
_0802EB00:
	ldr r0, [r4]
	ldrb r0, [r0, 0x8]
	bl sub_8096574
	ldr r1, [r4]
	adds r1, 0xC
	bl sub_803B35C
	ldr r0, [r4]
	movs r1, 0x3
	str r1, [r0, 0xC]
	adds r0, 0x50
	movs r1, 0
	strb r1, [r0]
	ldr r0, [r4]
	adds r0, 0xC
	bl sub_802DE84
	b _0802EB2C
_0802EB26:
	movs r0, 0
	bl sub_802C860
_0802EB2C:
	add sp, 0x8
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_802EA58

	thumb_func_start CreatePelliperBoardMenu
CreatePelliperBoardMenu:
	push {r4-r7,lr}
	ldr r4, _0802EBDC
	ldr r0, [r4]
	adds r0, 0xFC
	movs r1, 0
	movs r2, 0x10
	bl MemoryFill16
	ldr r1, [r4]
	adds r2, r1, 0
	adds r2, 0xBC
	ldr r0, _0802EBE0
	str r0, [r2]
	adds r1, 0xC0
	movs r0, 0x2
	str r0, [r1]
	bl sub_802C4A4
	lsls r0, 24
	cmp r0, 0
	beq _0802EB66
	ldr r0, [r4]
	adds r0, 0xFC
	movs r1, 0x1
	strh r1, [r0]
_0802EB66:
	movs r5, 0x1
	ldr r1, [r4]
	adds r2, r1, 0
	adds r2, 0xC4
	ldr r0, _0802EBE4
	str r0, [r2]
	adds r1, 0xC8
	movs r0, 0x3
	str r0, [r1]
	bl sub_802C83C
	lsls r0, 24
	cmp r0, 0
	beq _0802EB88
	ldr r0, [r4]
	adds r0, 0xFE
	strh r5, [r0]
_0802EB88:
	movs r5, 0x2
	ldr r2, [r4]
	adds r1, r2, 0
	adds r1, 0xCC
	movs r0, 0
	str r0, [r1]
	adds r1, 0x4
	movs r0, 0x1
	str r0, [r1]
	movs r3, 0
	adds r6, r4, 0
	mov r12, r2
	mov r4, r12
	adds r4, 0xFC
	adds r2, 0xC0
_0802EBA6:
	ldrh r0, [r4]
	cmp r0, 0
	bne _0802EBB6
	ldr r1, [r2]
	mov r7, r12
	ldr r0, [r7, 0x64]
	cmp r1, r0
	beq _0802EC0A
_0802EBB6:
	adds r4, 0x2
	adds r2, 0x8
	adds r3, 0x1
	cmp r3, r5
	blt _0802EBA6
	movs r3, 0
	cmp r3, r5
	bge _0802EC0A
	ldr r1, [r6]
	adds r0, r1, 0
	adds r0, 0xFC
	ldrh r0, [r0]
	cmp r0, 0
	bne _0802EBE8
	adds r0, r1, 0
	adds r0, 0xC0
	ldr r0, [r0]
	str r0, [r1, 0x64]
	b _0802EC0A
	.align 2, 0
_0802EBDC: .4byte gUnknown_203B308
_0802EBE0: .4byte gPelliperBoard_BulletinBoard
_0802EBE4: .4byte gPelliperBoard_JobList
_0802EBE8:
	adds r3, 0x1
	cmp r3, r5
	bge _0802EC0A
	ldr r2, [r6]
	lsls r0, r3, 1
	adds r1, r2, 0
	adds r1, 0xFC
	adds r1, r0
	ldrh r0, [r1]
	cmp r0, 0
	bne _0802EBE8
	lsls r0, r3, 3
	adds r1, r2, 0
	adds r1, 0xC0
	adds r1, r0
	ldr r0, [r1]
	str r0, [r2, 0x64]
_0802EC0A:
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end CreatePelliperBoardMenu

	thumb_func_start sub_802EC10
sub_802EC10:
	push {r4-r7,lr}
	movs r6, 0
	ldr r4, _0802ECA8
	ldr r2, [r4]
	adds r1, r2, 0
	adds r1, 0xBC
	ldr r0, _0802ECAC
	ldr r0, [r0]
	str r0, [r1]
	adds r1, 0x4
	movs r0, 0x4
	str r0, [r1]
	ldrb r0, [r2, 0x8]
	bl sub_8096574
	bl sub_80968B0
	lsls r0, 24
	cmp r0, 0
	bne _0802EC40
	bl sub_80969AC
	cmp r0, 0x7
	ble _0802EC4A
_0802EC40:
	ldr r0, [r4]
	adds r0, 0xC0
	movs r1, 0x1
	negs r1, r1
	str r1, [r0]
_0802EC4A:
	adds r6, 0x1
	ldr r4, _0802ECA8
	ldr r5, [r4]
	lsls r1, r6, 3
	adds r2, r5, 0
	adds r2, 0xBC
	adds r3, r2, r1
	ldr r0, _0802ECB0
	ldr r0, [r0]
	str r0, [r3]
	adds r3, r5, 0
	adds r3, 0xC0
	adds r1, r3, r1
	movs r0, 0x5
	str r0, [r1]
	adds r6, 0x1
	lsls r1, r6, 3
	adds r2, r1
	movs r0, 0
	str r0, [r2]
	adds r1, r3, r1
	movs r0, 0x1
	str r0, [r1]
	movs r2, 0
	adds r7, r4, 0
	cmp r2, r6
	bge _0802EC9C
	adds r4, r5, 0
	movs r5, 0x1
	negs r5, r5
	adds r1, r3, 0
_0802EC88:
	ldr r3, [r1]
	cmp r3, r5
	beq _0802EC94
	ldr r0, [r4, 0x68]
	cmp r3, r0
	beq _0802ECA2
_0802EC94:
	adds r1, 0x8
	adds r2, 0x1
	cmp r2, r6
	blt _0802EC88
_0802EC9C:
	ldr r1, [r7]
	movs r0, 0x5
	str r0, [r1, 0x68]
_0802ECA2:
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_0802ECA8: .4byte gUnknown_203B308
_0802ECAC: .4byte gUnknown_80D4990
_0802ECB0: .4byte gUnknown_80D4970
	thumb_func_end sub_802EC10

	thumb_func_start sub_802ECB4
sub_802ECB4:
	push {r4,lr}
	sub sp, 0x4
	movs r0, 0
	str r0, [sp]
	ldr r4, _0802ECF0
	ldr r0, [r4]
	adds r0, 0x6C
	bl sub_8012FD8
	lsls r0, 24
	cmp r0, 0
	bne _0802ECE0
	ldr r0, [r4]
	adds r0, 0x6C
	mov r1, sp
	bl sub_8013114
	ldr r1, [sp]
	cmp r1, 0x1
	beq _0802ECE0
	ldr r0, [r4]
	str r1, [r0, 0x64]
_0802ECE0:
	ldr r0, [sp]
	cmp r0, 0x2
	beq _0802ECFE
	cmp r0, 0x2
	bgt _0802ECF4
	cmp r0, 0x1
	beq _0802ED3C
	b _0802ED42
	.align 2, 0
_0802ECF0: .4byte gUnknown_203B308
_0802ECF4:
	cmp r0, 0x3
	beq _0802ED10
	cmp r0, 0x5
	beq _0802ED34
	b _0802ED42
_0802ECFE:
	bl sub_802C4A4
	lsls r0, 24
	cmp r0, 0
	bne _0802ED22
	movs r0, 0x4
	bl sub_802E934
	b _0802ED42
_0802ED10:
	bl sub_802C83C
	lsls r0, 24
	cmp r0, 0
	bne _0802ED22
	movs r0, 0x8
	bl sub_802E934
	b _0802ED42
_0802ED22:
	ldr r0, _0802ED30
	ldr r0, [r0]
	adds r0, 0x6C
	movs r1, 0x1
	bl sub_8012EA4
	b _0802ED42
	.align 2, 0
_0802ED30: .4byte gUnknown_203B308
_0802ED34:
	movs r0, 0x2
	bl sub_802E934
	b _0802ED42
_0802ED3C:
	movs r0, 0x3
	bl sub_802E934
_0802ED42:
	add sp, 0x4
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_802ECB4

	thumb_func_start sub_802ED4C
sub_802ED4C:
	push {lr}
	movs r0, 0x1
	bl sub_802C1E4
	cmp r0, 0x4
	bhi _0802EDB6
	lsls r0, 2
	ldr r1, _0802ED64
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0802ED64: .4byte _0802ED68
	.align 2, 0
_0802ED68:
	.4byte _0802EDB6
	.4byte _0802EDB6
	.4byte _0802EDAC
	.4byte _0802ED7C
	.4byte _0802ED94
_0802ED7C:
	bl sub_802C26C
	ldr r1, _0802ED90
	ldr r1, [r1]
	strb r0, [r1, 0x8]
	movs r0, 0x6
	bl sub_802E934
	b _0802EDB6
	.align 2, 0
_0802ED90: .4byte gUnknown_203B308
_0802ED94:
	bl sub_802C26C
	ldr r1, _0802EDA8
	ldr r1, [r1]
	strb r0, [r1, 0x8]
	movs r0, 0x7
	bl sub_802E934
	b _0802EDB6
	.align 2, 0
_0802EDA8: .4byte gUnknown_203B308
_0802EDAC:
	bl sub_802C2D4
	movs r0, 0x1
	bl sub_802E934
_0802EDB6:
	pop {r0}
	bx r0
	thumb_func_end sub_802ED4C

	thumb_func_start sub_802EDBC
sub_802EDBC:
	push {r4,lr}
	sub sp, 0x4
	movs r0, 0
	str r0, [sp]
	bl sub_802C1E4
	ldr r4, _0802EDFC
	ldr r0, [r4]
	adds r0, 0x6C
	bl sub_8012FD8
	lsls r0, 24
	cmp r0, 0
	bne _0802EDEC
	ldr r0, [r4]
	adds r0, 0x6C
	mov r1, sp
	bl sub_8013114
	ldr r1, [sp]
	cmp r1, 0x1
	beq _0802EDEC
	ldr r0, [r4]
	str r1, [r0, 0x68]
_0802EDEC:
	ldr r0, [sp]
	cmp r0, 0x4
	beq _0802EE06
	cmp r0, 0x4
	bgt _0802EE00
	cmp r0, 0x1
	beq _0802EE90
	b _0802EE96
	.align 2, 0
_0802EDFC: .4byte gUnknown_203B308
_0802EE00:
	cmp r0, 0x5
	beq _0802EE88
	b _0802EE96
_0802EE06:
	ldr r0, _0802EE28
	bl sub_8011988
	ldr r4, _0802EE2C
	ldr r0, [r4]
	ldrb r0, [r0, 0x8]
	bl sub_8096574
	ldrb r1, [r0]
	cmp r1, 0x3
	beq _0802EE3C
	cmp r1, 0x3
	bgt _0802EE30
	cmp r1, 0x2
	beq _0802EE36
	b _0802EE5E
	.align 2, 0
_0802EE28: .4byte 0x00000133
_0802EE2C: .4byte gUnknown_203B308
_0802EE30:
	cmp r1, 0x4
	beq _0802EE42
	b _0802EE5E
_0802EE36:
	ldr r0, [r4]
	movs r1, 0x1
	b _0802EE46
_0802EE3C:
	ldr r0, [r4]
	movs r1, 0x2
	b _0802EE46
_0802EE42:
	ldr r0, [r4]
	movs r1, 0x3
_0802EE46:
	str r1, [r0, 0x4]
	ldrb r0, [r0, 0x8]
	bl sub_80965B8
	bl sub_80965F4
	bl sub_802C2D4
	movs r0, 0x3
	bl sub_802E934
	b _0802EE96
_0802EE5E:
	bl sub_8096A78
	bl sub_8096C80
	bl sub_8096D24
	bl sub_802C4A4
	lsls r0, 24
	cmp r0, 0
	beq _0802EE80
	bl sub_802C2D4
	movs r0, 0x1
	bl sub_802E934
	b _0802EE96
_0802EE80:
	movs r0, 0x5
	bl sub_802E934
	b _0802EE96
_0802EE88:
	movs r0, 0x7
	bl sub_802E934
	b _0802EE96
_0802EE90:
	movs r0, 0x5
	bl sub_802E934
_0802EE96:
	add sp, 0x4
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_802EDBC

	thumb_func_start sub_802EEA0
sub_802EEA0:
	push {lr}
	bl sub_802DEE0
	cmp r0, 0x1
	bls _0802EEB8
	cmp r0, 0x3
	bhi _0802EEB8
	bl sub_802DF24
	movs r0, 0x5
	bl sub_802E934
_0802EEB8:
	pop {r0}
	bx r0
	thumb_func_end sub_802EEA0

	thumb_func_start sub_802EEBC
sub_802EEBC:
	push {lr}
	bl sub_802C898
	cmp r0, 0x1
	bls _0802EED4
	cmp r0, 0x3
	bhi _0802EED4
	bl sub_802C8F4
	movs r0, 0x1
	bl sub_802E934
_0802EED4:
	pop {r0}
	bx r0
	thumb_func_end sub_802EEBC

	thumb_func_start nullsub_134
nullsub_134:
	bx lr
	thumb_func_end nullsub_134

	thumb_func_start CreatePelliperAccepedStatusBox
CreatePelliperAcceptedStatusBox:
	push {r4-r6,lr}
	sub sp, 0x8
	adds r4, r0, 0
	bl sub_8008C54
	adds r0, r4, 0
	bl sub_80073B8
	ldr r2, _0802EF40
	movs r6, 0
	str r6, [sp]
	movs r0, 0x3
	movs r1, 0
	adds r3, r4, 0
	bl xxx_call_draw_string
	bl sub_80969AC
	adds r2, r0, 0
	movs r5, 0x7
	str r5, [sp]
	str r4, [sp, 0x4]
	movs r0, 0x12
	movs r1, 0xD
	movs r3, 0x2
	bl sub_8012BC4
	ldr r2, _0802EF44
	str r6, [sp]
	movs r0, 0x16
	movs r1, 0xD
	adds r3, r4, 0
	bl xxx_call_draw_string
	str r5, [sp]
	str r4, [sp, 0x4]
	movs r0, 0x23
	movs r1, 0xD
	movs r2, 0x8
	movs r3, 0x2
	bl sub_8012BC4
	adds r0, r4, 0
	bl sub_80073E0
	add sp, 0x8
	pop {r4-r6}
	pop {r0}
	bx r0
	.align 2, 0
_0802EF40: .4byte gUnknown_80E03AC
_0802EF44: .4byte gUnknown_80E03B8
	thumb_func_end CreatePelliperAcceptedStatusBox

	thumb_func_start sub_802EF48
sub_802EF48:
	push {r4,lr}
	ldr r4, _0802EF68
	movs r0, 0xA8
	lsls r0, 1
	movs r1, 0x8
	bl MemoryAlloc
	str r0, [r4]
	movs r0, 0
	bl sub_802EFEC
	movs r0, 0x1
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_0802EF68: .4byte gUnknown_203B30C
	thumb_func_end sub_802EF48

	thumb_func_start sub_802EF6C
sub_802EF6C:
	push {lr}
	ldr r0, _0802EF84
	ldr r0, [r0]
	ldr r0, [r0]
	cmp r0, 0x5
	bhi _0802EFBA
	lsls r0, 2
	ldr r1, _0802EF88
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0802EF84: .4byte gUnknown_203B30C
_0802EF88: .4byte _0802EF8C
	.align 2, 0
_0802EF8C:
	.4byte _0802EFA4
	.4byte _0802EFA4
	.4byte _0802EFAA
	.4byte _0802EFB0
	.4byte _0802EFB6
	.4byte _0802EFBA
_0802EFA4:
	bl sub_802F148
	b _0802EFBE
_0802EFAA:
	bl sub_802F184
	b _0802EFBE
_0802EFB0:
	bl sub_802F1E8
	b _0802EFBE
_0802EFB6:
	movs r0, 0x3
	b _0802EFC0
_0802EFBA:
	movs r0, 0x2
	b _0802EFC0
_0802EFBE:
	movs r0, 0
_0802EFC0:
	pop {r1}
	bx r1
	thumb_func_end sub_802EF6C

	thumb_func_start sub_802EFC4
sub_802EFC4:
	ldr r0, _0802EFCC
	ldr r0, [r0]
	ldrb r0, [r0, 0x4]
	bx lr
	.align 2, 0
_0802EFCC: .4byte gUnknown_203B30C
	thumb_func_end sub_802EFC4

	thumb_func_start sub_802EFD0
sub_802EFD0:
	push {r4,lr}
	ldr r4, _0802EFE8
	ldr r0, [r4]
	cmp r0, 0
	beq _0802EFE2
	bl MemoryFree
	movs r0, 0
	str r0, [r4]
_0802EFE2:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0802EFE8: .4byte gUnknown_203B30C
	thumb_func_end sub_802EFD0

	thumb_func_start sub_802EFEC
sub_802EFEC:
	push {lr}
	ldr r1, _0802F000
	ldr r1, [r1]
	str r0, [r1]
	bl sub_802F004
	bl sub_802F088
	pop {r0}
	bx r0
	.align 2, 0
_0802F000: .4byte gUnknown_203B30C
	thumb_func_end sub_802EFEC

	thumb_func_start sub_802F004
sub_802F004:
	push {r4-r7,lr}
	ldr r4, _0802F03C
	ldr r0, [r4]
	adds r0, 0xF0
	bl sub_8006518
	ldr r0, [r4]
	ldr r0, [r0]
	cmp r0, 0x2
	bne _0802F044
	bl sub_802F108
	ldr r2, [r4]
	movs r0, 0x90
	lsls r0, 1
	adds r2, r0
	ldr r1, _0802F040
	ldm r1!, {r3,r5,r6}
	stm r2!, {r3,r5,r6}
	ldm r1!, {r3,r5,r7}
	stm r2!, {r3,r5,r7}
	ldr r1, [r4]
	adds r0, r1, r0
	adds r1, 0xB0
	bl sub_8012CAC
	b _0802F066
	.align 2, 0
_0802F03C: .4byte gUnknown_203B30C
_0802F040: .4byte gUnknown_80E03F4
_0802F044:
	mov r12, r4
	ldr r4, _0802F080
	movs r2, 0
	movs r3, 0x3
_0802F04C:
	mov r6, r12
	ldr r1, [r6]
	adds r1, r2
	adds r1, 0xF0
	adds r0, r4, 0
	ldm r0!, {r5-r7}
	stm r1!, {r5-r7}
	ldm r0!, {r5-r7}
	stm r1!, {r5-r7}
	adds r2, 0x18
	subs r3, 0x1
	cmp r3, 0
	bge _0802F04C
_0802F066:
	bl ResetUnusedInputStruct
	ldr r0, _0802F084
	ldr r0, [r0]
	adds r0, 0xF0
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_0802F080: .4byte gUnknown_80E03C4
_0802F084: .4byte gUnknown_203B30C
	thumb_func_end sub_802F004

	thumb_func_start sub_802F088
sub_802F088:
	push {r4-r6,lr}
	sub sp, 0x8
	ldr r6, _0802F0A0
	ldr r0, [r6]
	ldr r5, [r0]
	cmp r5, 0x1
	beq _0802F0B6
	cmp r5, 0x1
	bgt _0802F0A4
	cmp r5, 0
	beq _0802F0AE
	b _0802F100
	.align 2, 0
_0802F0A0: .4byte gUnknown_203B30C
_0802F0A4:
	cmp r5, 0x2
	beq _0802F0BE
	cmp r5, 0x3
	beq _0802F0DA
	b _0802F100
_0802F0AE:
	movs r0, 0
	bl sub_802CDD4
	b _0802F100
_0802F0B6:
	movs r0, 0x1
	bl sub_802CED8
	b _0802F100
_0802F0BE:
	bl sub_802CFD0
	ldr r1, [r6]
	adds r0, r1, 0
	adds r0, 0x60
	adds r1, 0xB0
	movs r2, 0x3
	str r2, [sp]
	str r5, [sp, 0x4]
	movs r2, 0
	movs r3, 0
	bl sub_8012D60
	b _0802F100
_0802F0DA:
	ldrb r0, [r0, 0x4]
	bl sub_803B344
	adds r4, r0, 0
	ldr r1, [r6]
	adds r1, 0x8
	bl sub_803B35C
	ldr r0, [r6]
	str r5, [r0, 0x8]
	adds r0, 0x4C
	movs r1, 0
	strb r1, [r0]
	ldr r0, [r6]
	ldr r1, [r4, 0x18]
	str r1, [r0, 0x58]
	adds r0, 0x8
	bl sub_802DE84
_0802F100:
	add sp, 0x8
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end sub_802F088

	thumb_func_start sub_802F108
sub_802F108:
	ldr r0, _0802F13C
	ldr r0, [r0]
	mov r12, r0
	movs r3, 0
	mov r1, r12
	adds r1, 0xB0
	ldr r0, _0802F140
	str r0, [r1]
	adds r1, 0x4
	movs r0, 0x2
	str r0, [r1]
	movs r2, 0x1
	adds r1, 0x4
	ldr r0, _0802F144
	ldr r0, [r0]
	str r0, [r1]
	adds r1, 0x4
	movs r0, 0x3
	str r0, [r1]
	mov r0, r12
	adds r0, 0xC0
	str r3, [r0]
	adds r0, 0x4
	str r2, [r0]
	bx lr
	.align 2, 0
_0802F13C: .4byte gUnknown_203B30C
_0802F140: .4byte gUnknown_80E040C
_0802F144: .4byte gUnknown_80D4970
	thumb_func_end sub_802F108

	thumb_func_start sub_802F148
sub_802F148:
	push {lr}
	movs r0, 0x1
	bl sub_802CE5C
	cmp r0, 0x2
	beq _0802F174
	cmp r0, 0x2
	bcc _0802F17E
	cmp r0, 0x3
	bne _0802F17E
	bl sub_802CEBC
	ldr r1, _0802F170
	ldr r1, [r1]
	strb r0, [r1, 0x4]
	movs r0, 0x2
	bl sub_802EFEC
	b _0802F17E
	.align 2, 0
_0802F170: .4byte gUnknown_203B30C
_0802F174:
	bl sub_802CF14
	movs r0, 0x5
	bl sub_802EFEC
_0802F17E:
	pop {r0}
	bx r0
	thumb_func_end sub_802F148

	thumb_func_start sub_802F184
sub_802F184:
	push {r4,lr}
	sub sp, 0x4
	movs r0, 0
	str r0, [sp]
	bl sub_802CE5C
	ldr r4, _0802F1BC
	ldr r0, [r4]
	adds r0, 0x60
	bl sub_8012FD8
	lsls r0, 24
	cmp r0, 0
	bne _0802F1AA
	ldr r0, [r4]
	adds r0, 0x60
	mov r1, sp
	bl sub_8013114
_0802F1AA:
	ldr r0, [sp]
	cmp r0, 0x2
	beq _0802F1C6
	cmp r0, 0x2
	bgt _0802F1C0
	cmp r0, 0x1
	beq _0802F1DA
	b _0802F1E0
	.align 2, 0
_0802F1BC: .4byte gUnknown_203B30C
_0802F1C0:
	cmp r0, 0x3
	beq _0802F1D2
	b _0802F1E0
_0802F1C6:
	bl sub_802CF14
	movs r0, 0x4
	bl sub_802EFEC
	b _0802F1E0
_0802F1D2:
	movs r0, 0x3
	bl sub_802EFEC
	b _0802F1E0
_0802F1DA:
	movs r0, 0x1
	bl sub_802EFEC
_0802F1E0:
	add sp, 0x4
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_802F184

	thumb_func_start sub_802F1E8
sub_802F1E8:
	push {lr}
	bl sub_802DEE0
	cmp r0, 0x1
	bls _0802F200
	cmp r0, 0x3
	bhi _0802F200
	bl sub_802DF24
	movs r0, 0x1
	bl sub_802EFEC
_0802F200:
	pop {r0}
	bx r0
	thumb_func_end sub_802F1E8

	thumb_func_start sub_802F204
sub_802F204:
	push {r4-r6,lr}
	adds r6, r0, 0
	lsls r4, r1, 24
	lsrs r4, 24
	bl ResetUnusedInputStruct
	movs r0, 0
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	ldr r5, _0802F28C
	movs r0, 0x84
	movs r1, 0x8
	bl MemoryAlloc
	str r0, [r5]
	str r6, [r0, 0x10]
	movs r6, 0
	str r6, [r0, 0xC]
	strb r4, [r0, 0x8]
	ldr r1, [r5]
	ldr r0, _0802F290
	ldr r1, [r1, 0x10]
	bl strcpy
	ldr r4, _0802F294
	bl sub_808D33C
	adds r1, r0, 0
	adds r0, r4, 0
	bl sub_808DA34
	ldr r0, [r5]
	ldr r0, [r0, 0x10]
	movs r1, 0x14
	ldrsh r0, [r0, r1]
	bl GetDialogueSpriteDataPtr
	ldr r1, [r5]
	str r0, [r1, 0x14]
	str r6, [r1, 0x18]
	adds r1, 0x20
	strb r6, [r1]
	ldr r0, [r5]
	adds r0, 0x21
	strb r6, [r0]
	ldr r0, [r5]
	adds r0, 0x22
	strb r6, [r0]
	ldr r5, [r5]
	movs r0, 0x2
	strh r0, [r5, 0x1C]
	movs r0, 0x8
	strh r0, [r5, 0x1E]
	ldr r0, [r5, 0x14]
	cmp r0, 0
	beq _0802F27C
	ldr r0, [r0, 0x4]
	str r0, [r5, 0x18]
_0802F27C:
	movs r0, 0
	bl sub_802F2E8
	movs r0, 0x1
	pop {r4-r6}
	pop {r1}
	bx r1
	.align 2, 0
_0802F28C: .4byte gUnknown_203B310
_0802F290: .4byte gUnknown_202E5D8
_0802F294: .4byte gAvailablePokemonNames
	thumb_func_end sub_802F204

	thumb_func_start sub_802F298
sub_802F298:
	push {lr}
	ldr r0, _0802F2AC
	ldr r0, [r0]
	ldr r0, [r0]
	cmp r0, 0x5
	beq _0802F2B0
	cmp r0, 0x9
	bne _0802F2B6
	movs r0, 0x3
	b _0802F2BC
	.align 2, 0
_0802F2AC: .4byte gUnknown_203B310
_0802F2B0:
	bl sub_802F6FC
	b _0802F2BA
_0802F2B6:
	bl sub_802F718
_0802F2BA:
	movs r0, 0
_0802F2BC:
	pop {r1}
	bx r1
	thumb_func_end sub_802F298

	thumb_func_start sub_802F2C0
sub_802F2C0:
	push {r4,lr}
	ldr r4, _0802F2E4
	ldr r0, [r4]
	cmp r0, 0
	beq _0802F2DE
	ldr r0, [r0, 0x14]
	cmp r0, 0
	beq _0802F2D4
	bl CloseFile
_0802F2D4:
	ldr r0, [r4]
	bl MemoryFree
	movs r0, 0
	str r0, [r4]
_0802F2DE:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0802F2E4: .4byte gUnknown_203B310
	thumb_func_end sub_802F2C0

	thumb_func_start sub_802F2E8
sub_802F2E8:
	push {lr}
	ldr r1, _0802F2FC
	ldr r1, [r1]
	str r0, [r1]
	bl sub_802F300
	bl sub_802F358
	pop {r0}
	bx r0
	.align 2, 0
_0802F2FC: .4byte gUnknown_203B310
	thumb_func_end sub_802F2E8

	thumb_func_start sub_802F300
sub_802F300:
	push {r4-r7,lr}
	ldr r4, _0802F350
	ldr r1, [r4]
	ldr r0, [r1]
	cmp r0, 0
	bne _0802F348
	adds r0, r1, 0
	adds r0, 0x24
	bl sub_8006518
	mov r12, r4
	ldr r4, _0802F354
	movs r3, 0
	movs r2, 0x3
_0802F31C:
	mov r0, r12
	ldr r1, [r0]
	adds r1, r3
	adds r1, 0x24
	adds r0, r4, 0
	ldm r0!, {r5-r7}
	stm r1!, {r5-r7}
	ldm r0!, {r5-r7}
	stm r1!, {r5-r7}
	adds r3, 0x18
	subs r2, 0x1
	cmp r2, 0
	bge _0802F31C
	bl ResetUnusedInputStruct
	ldr r0, _0802F350
	ldr r0, [r0]
	adds r0, 0x24
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
_0802F348:
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_0802F350: .4byte gUnknown_203B310
_0802F354: .4byte gUnknown_80E041C
	thumb_func_end sub_802F300

	thumb_func_start sub_802F358
sub_802F358:
	push {r4-r6,lr}
	sub sp, 0x10
	ldr r1, _0802F374
	ldr r0, [r1]
	ldr r0, [r0]
	adds r6, r1, 0
	cmp r0, 0x9
	bls _0802F36A
	b _0802F6E4
_0802F36A:
	lsls r0, 2
	ldr r1, _0802F378
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0802F374: .4byte gUnknown_203B310
_0802F378: .4byte _0802F37C
	.align 2, 0
_0802F37C:
	.4byte _0802F3A4
	.4byte _0802F3E8
	.4byte _0802F444
	.4byte _0802F494
	.4byte _0802F524
	.4byte _0802F5CC
	.4byte _0802F614
	.4byte _0802F630
	.4byte _0802F6A4
	.4byte _0802F6E4
_0802F3A4:
	ldr r2, [r6]
	ldr r0, [r2, 0x10]
	ldr r1, [r0, 0x18]
	cmp r1, 0
	bne _0802F3B6
	movs r0, 0x2
	bl sub_802F2E8
	b _0802F6E4
_0802F3B6:
	ldr r0, _0802F3D4
	str r1, [r0]
	ldrb r0, [r2, 0x8]
	cmp r0, 0
	beq _0802F3E0
	ldr r0, _0802F3D8
	adds r2, 0x14
	ldr r3, _0802F3DC
	movs r1, 0
	bl sub_80141B4
	ldr r1, [r6]
	movs r0, 0x1
	str r0, [r1, 0x4]
	b _0802F6E4
	.align 2, 0
_0802F3D4: .4byte gUnknown_202DE30
_0802F3D8: .4byte gUnknown_80E0434
_0802F3DC: .4byte 0x0000010d
_0802F3E0:
	movs r0, 0x1
	bl sub_802F2E8
	b _0802F6E4
_0802F3E8:
	movs r0, 0xCB
	bl sub_8011988
	ldr r0, _0802F414
	ldr r0, [r0]
	ldr r0, [r0, 0x10]
	ldr r0, [r0, 0x18]
	bl sub_80913A0
	movs r0, 0
	bl sub_808D544
	cmp r0, 0x1
	bgt _0802F420
	ldr r0, _0802F418
	ldr r3, _0802F41C
	movs r1, 0
	movs r2, 0
	bl sub_80141B4
	b _0802F42C
	.align 2, 0
_0802F414: .4byte gUnknown_203B310
_0802F418: .4byte gUnknown_80E045C
_0802F41C: .4byte 0x00000101
_0802F420:
	ldr r0, _0802F438
	ldr r3, _0802F43C
	movs r1, 0
	movs r2, 0
	bl sub_80141B4
_0802F42C:
	ldr r0, _0802F440
	ldr r1, [r0]
	movs r0, 0x2
	str r0, [r1, 0x4]
	b _0802F6E4
	.align 2, 0
_0802F438: .4byte gUnknown_80E0484
_0802F43C: .4byte 0x00000101
_0802F440: .4byte gUnknown_203B310
_0802F444:
	ldr r0, [r6]
	ldr r0, [r0, 0x10]
	adds r1, r0, 0
	adds r1, 0x20
	ldrb r0, [r1]
	cmp r0, 0
	bne _0802F45A
	movs r0, 0x4
	bl sub_802F2E8
	b _0802F6E4
_0802F45A:
	ldr r0, _0802F480
	ldrb r1, [r1]
	movs r2, 0
	bl sub_8092578
	ldr r2, [r6]
	ldrb r0, [r2, 0x8]
	cmp r0, 0
	beq _0802F48C
	ldr r0, _0802F484
	adds r2, 0x14
	ldr r3, _0802F488
	movs r1, 0
	bl sub_80141B4
	ldr r1, [r6]
	movs r0, 0x3
	str r0, [r1, 0x4]
	b _0802F6E4
	.align 2, 0
_0802F480: .4byte gUnknown_202E628
_0802F484: .4byte gUnknown_80E04B4
_0802F488: .4byte 0x0000010d
_0802F48C:
	movs r0, 0x3
	bl sub_802F2E8
	b _0802F6E4
_0802F494:
	ldr r4, _0802F4B4
	ldr r0, [r4]
	ldr r0, [r0, 0x10]
	adds r0, 0x20
	ldrb r0, [r0]
	bl GetFriendAreaStatus
	lsls r0, 24
	cmp r0, 0
	beq _0802F4BC
	movs r0, 0xFA
	lsls r0, 2
	bl sub_80913A0
	ldr r0, _0802F4B8
	b _0802F4DA
	.align 2, 0
_0802F4B4: .4byte gUnknown_203B310
_0802F4B8: .4byte gUnknown_80E04F4
_0802F4BC:
	movs r0, 0
	bl sub_808D544
	cmp r0, 0x1
	bgt _0802F4F0
	ldr r0, [r4]
	ldr r0, [r0, 0x10]
	adds r0, 0x20
	ldrb r0, [r0]
	bl UnlockFriendArea
	movs r0, 0xCE
	bl sub_8011988
	ldr r0, _0802F4E8
_0802F4DA:
	ldr r3, _0802F4EC
	movs r1, 0
	movs r2, 0
	bl sub_80141B4
	b _0802F50E
	.align 2, 0
_0802F4E8: .4byte gUnknown_80E05C0
_0802F4EC: .4byte 0x00000101
_0802F4F0:
	ldr r0, [r4]
	ldr r0, [r0, 0x10]
	adds r0, 0x20
	ldrb r0, [r0]
	bl UnlockFriendArea
	movs r0, 0xCE
	bl sub_8011988
	ldr r0, _0802F518
	ldr r3, _0802F51C
	movs r1, 0
	movs r2, 0
	bl sub_80141B4
_0802F50E:
	ldr r0, _0802F520
	ldr r1, [r0]
	movs r0, 0x4
	str r0, [r1, 0x4]
	b _0802F6E4
	.align 2, 0
_0802F518: .4byte gUnknown_80E05FC
_0802F51C: .4byte 0x00000101
_0802F520: .4byte gUnknown_203B310
_0802F524:
	ldr r0, [r6]
	ldr r0, [r0, 0x10]
	ldrb r2, [r0, 0x1C]
	cmp r2, 0
	beq _0802F628
	ldr r0, [r0, 0x18]
	cmp r0, 0
	bne _0802F620
	lsls r2, 16
	ldr r1, _0802F564
	ldr r0, [sp, 0xC]
	ands r0, r1
	orrs r0, r2
	str r0, [sp, 0xC]
	lsrs r0, 16
	lsls r0, 24
	lsrs r0, 24
	bl sub_8090A60
	lsls r0, 24
	cmp r0, 0
	beq _0802F56C
	ldr r0, [r6]
	ldr r0, [r0, 0x10]
	ldrb r1, [r0, 0x1F]
	lsls r1, 8
	ldr r2, _0802F568
	ldr r0, [sp, 0xC]
	ands r0, r2
	orrs r0, r1
	b _0802F572
	.align 2, 0
_0802F564: .4byte 0xff00ffff
_0802F568: .4byte 0xffff00ff
_0802F56C:
	ldr r1, _0802F5B4
	ldr r0, [sp, 0xC]
	ands r0, r1
_0802F572:
	str r0, [sp, 0xC]
	ldr r1, _0802F5B8
	ldr r0, [sp, 0xC]
	ands r0, r1
	movs r2, 0x1
	orrs r0, r2
	str r0, [sp, 0xC]
	movs r1, 0
	str r1, [sp]
	mov r0, sp
	strb r1, [r0, 0x4]
	strb r2, [r0, 0x8]
	ldr r0, _0802F5BC
	add r1, sp, 0xC
	mov r2, sp
	bl sub_8090E14
	ldr r4, _0802F5C0
	ldr r2, [r4]
	ldrb r0, [r2, 0x8]
	cmp r0, 0
	beq _0802F620
	ldr r0, _0802F5C4
	adds r2, 0x14
	ldr r3, _0802F5C8
	movs r1, 0
	bl sub_80141B4
	ldr r1, [r4]
	movs r0, 0x5
	str r0, [r1, 0x4]
	b _0802F6E4
	.align 2, 0
_0802F5B4: .4byte 0xffff00ff
_0802F5B8: .4byte 0xffffff00
_0802F5BC: .4byte gUnknown_202DEA8
_0802F5C0: .4byte gUnknown_203B310
_0802F5C4: .4byte gUnknown_80E0640
_0802F5C8: .4byte 0x0000010d
_0802F5CC:
	ldr r0, [r6]
	ldr r2, [r0, 0x10]
	adds r1, r2, 0
	adds r1, 0x1C
	ldr r3, [r0, 0xC]
	adds r1, r3
	ldrb r0, [r1]
	cmp r0, 0
	bne _0802F5E6
	movs r0, 0x6
	bl sub_802F2E8
	b _0802F6E4
_0802F5E6:
	cmp r3, 0
	bne _0802F5FC
	ldr r0, [r2, 0x18]
	cmp r0, 0
	bne _0802F5FC
	ldrb r1, [r2, 0x1C]
	ldrb r2, [r2, 0x1F]
	movs r0, 0
	bl sub_801B60C
	b _0802F6E4
_0802F5FC:
	ldr r1, [r6]
	ldr r2, [r1, 0x10]
	adds r0, r2, 0
	adds r0, 0x1C
	ldr r1, [r1, 0xC]
	adds r0, r1
	ldrb r1, [r0]
	ldrb r2, [r2, 0x1F]
	movs r0, 0x1
	bl sub_801B60C
	b _0802F6E4
_0802F614:
	ldr r1, [r6]
	ldr r0, [r1, 0xC]
	adds r0, 0x1
	str r0, [r1, 0xC]
	cmp r0, 0x2
	bgt _0802F628
_0802F620:
	movs r0, 0x5
	bl sub_802F2E8
	b _0802F6E4
_0802F628:
	movs r0, 0x7
	bl sub_802F2E8
	b _0802F6E4
_0802F630:
	adds r5, r6, 0
	ldr r0, [r5]
	ldr r0, [r0, 0x10]
	ldr r0, [r0, 0x24]
	cmp r0, 0
	bne _0802F644
	movs r0, 0x9
	bl sub_802F2E8
	b _0802F6E4
_0802F644:
	bl sub_8092178
	ldr r1, [r5]
	strb r0, [r1, 0x9]
	ldr r0, [r5]
	ldr r0, [r0, 0x10]
	ldr r0, [r0, 0x24]
	bl sub_8092158
	movs r0, 0xCB
	bl sub_8011988
	ldr r4, [r5]
	bl sub_8092178
	ldrb r1, [r4, 0x9]
	lsls r0, 24
	lsrs r0, 24
	cmp r1, r0
	beq _0802F672
	ldr r1, [r5]
	movs r0, 0x8
	b _0802F676
_0802F672:
	ldr r1, [r6]
	movs r0, 0x9
_0802F676:
	str r0, [r1, 0x4]
	ldr r1, _0802F694
	ldr r0, _0802F698
	ldr r0, [r0]
	ldr r0, [r0, 0x10]
	ldr r0, [r0, 0x24]
	str r0, [r1]
	ldr r0, _0802F69C
	ldr r3, _0802F6A0
	movs r1, 0
	movs r2, 0
	bl sub_80141B4
	b _0802F6E4
	.align 2, 0
_0802F694: .4byte gUnknown_202DE30
_0802F698: .4byte gUnknown_203B310
_0802F69C: .4byte gUnknown_80E0670
_0802F6A0: .4byte 0x00000101
_0802F6A4:
	movs r0, 0xC9
	bl sub_8011988
	ldr r0, _0802F6EC
	ldr r1, [r0]
	movs r0, 0x9
	str r0, [r1, 0x4]
	ldrb r0, [r1, 0x9]
	bl sub_80921A8
	adds r1, r0, 0
	ldr r4, _0802F6F0
	adds r0, r4, 0
	bl strcpy
	bl sub_8092178
	lsls r0, 24
	lsrs r0, 24
	bl sub_80921A8
	adds r1, r0, 0
	adds r4, 0x50
	adds r0, r4, 0
	bl strcpy
	ldr r0, _0802F6F4
	ldr r3, _0802F6F8
	movs r1, 0
	movs r2, 0
	bl sub_80141B4
_0802F6E4:
	add sp, 0x10
	pop {r4-r6}
	pop {r0}
	bx r0
	.align 2, 0
_0802F6EC: .4byte gUnknown_203B310
_0802F6F0: .4byte gUnknown_202E038
_0802F6F4: .4byte gUnknown_80E06A8
_0802F6F8: .4byte 0x00000101
	thumb_func_end sub_802F358

	thumb_func_start sub_802F6FC
sub_802F6FC:
	push {lr}
	bl sub_801B6AC
	cmp r0, 0x1
	bls _0802F714
	cmp r0, 0x3
	bhi _0802F714
	bl sub_801B72C
	movs r0, 0x6
	bl sub_802F2E8
_0802F714:
	pop {r0}
	bx r0
	thumb_func_end sub_802F6FC

	thumb_func_start sub_802F718
sub_802F718:
	push {lr}
	sub sp, 0x4
	mov r0, sp
	bl sub_80144A4
	cmp r0, 0
	bne _0802F730
	ldr r0, _0802F738
	ldr r0, [r0]
	ldr r0, [r0, 0x4]
	bl sub_802F2E8
_0802F730:
	add sp, 0x4
	pop {r0}
	bx r0
	.align 2, 0
_0802F738: .4byte gUnknown_203B310
	thumb_func_end sub_802F718

	thumb_func_start sub_802F73C
sub_802F73C:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	adds r5, r0, 0
	adds r7, r1, 0
	mov r8, r2
	lsls r3, 24
	lsrs r6, r3, 24
	bl sub_802FCF0
	lsls r0, 24
	cmp r0, 0
	beq _0802F75A
	movs r0, 0
	b _0802F836
_0802F75A:
	ldr r4, _0802F7AC
	ldr r0, [r4]
	cmp r0, 0
	bne _0802F76E
	movs r0, 0xAE
	lsls r0, 1
	movs r1, 0x8
	bl MemoryAlloc
	str r0, [r4]
_0802F76E:
	ldr r0, [r4]
	adds r0, 0xB8
	strb r6, [r0]
	ldr r0, [r4]
	adds r1, r0, 0
	adds r1, 0xF0
	str r5, [r1]
	adds r2, r0, 0
	adds r2, 0xF4
	lsls r1, r5, 1
	adds r1, r5
	lsls r1, 3
	adds r1, 0xF8
	adds r1, r0, r1
	str r1, [r2]
	adds r0, 0xF8
	bl sub_8006518
	cmp r6, 0
	beq _0802F7B4
	ldr r1, [r4]
	adds r0, r1, 0
	adds r0, 0xF0
	ldr r2, [r0]
	lsls r0, r2, 1
	adds r0, r2
	lsls r0, 3
	adds r1, r0
	adds r1, 0xF8
	ldr r0, _0802F7B0
	b _0802F7C8
	.align 2, 0
_0802F7AC: .4byte gUnknown_203B314
_0802F7B0: .4byte gUnknown_80E072C
_0802F7B4:
	ldr r1, [r4]
	adds r0, r1, 0
	adds r0, 0xF0
	ldr r2, [r0]
	lsls r0, r2, 1
	adds r0, r2
	lsls r0, 3
	adds r1, r0
	adds r1, 0xF8
	ldr r0, _0802F840
_0802F7C8:
	ldm r0!, {r2-r4}
	stm r1!, {r2-r4}
	ldm r0!, {r2-r4}
	stm r1!, {r2-r4}
	ldr r4, _0802F844
	ldr r2, [r4]
	adds r0, r2, 0
	adds r0, 0xF4
	ldr r1, [r0]
	movs r3, 0xAC
	lsls r3, 1
	adds r0, r2, r3
	str r0, [r1, 0x14]
	cmp r7, 0
	beq _0802F7FC
	adds r0, r2, 0
	adds r0, 0xF0
	ldr r1, [r0]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 3
	subs r3, 0x58
	adds r1, r2, r3
	adds r1, r0
	ldr r0, [r7]
	str r0, [r1]
_0802F7FC:
	ldr r0, [r4]
	adds r0, 0xF4
	ldr r0, [r0]
	mov r1, r8
	bl sub_8012D08
	bl ResetUnusedInputStruct
	ldr r0, [r4]
	adds r0, 0xF8
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	ldr r4, [r4]
	adds r4, 0xBC
	bl sub_802FBF4
	adds r1, r0, 0
	adds r0, r4, 0
	mov r2, r8
	adds r3, r5, 0
	bl sub_8013818
	bl sub_802F9C0
	bl sub_802FA50
	movs r0, 0x1
_0802F836:
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r1}
	bx r1
	.align 2, 0
_0802F840: .4byte gUnknown_80E0714
_0802F844: .4byte gUnknown_203B314
	thumb_func_end sub_802F73C

	thumb_func_start sub_802F848
sub_802F848:
	push {r4,r5,lr}
	lsls r0, 16
	asrs r4, r0, 16
	movs r3, 0
	ldr r1, _0802F858
	ldr r0, [r1]
	b _0802F884
	.align 2, 0
_0802F858: .4byte gUnknown_203B314
_0802F85C:
	ldr r2, [r1]
	lsls r0, r3, 1
	adds r0, r2, r0
	movs r5, 0
	ldrsh r0, [r0, r5]
	cmp r0, r4
	bne _0802F880
	adds r0, r2, 0
	adds r0, 0xBC
	adds r1, r3, 0
	bl sub_8013878
	bl sub_802F9C0
	bl sub_802FA50
	movs r0, 0x1
	b _0802F89A
_0802F880:
	adds r3, 0x1
	adds r0, r2, 0
_0802F884:
	adds r0, 0xDE
	movs r2, 0
	ldrsh r0, [r0, r2]
	cmp r3, r0
	blt _0802F85C
	ldr r0, [r1]
	adds r0, 0xBC
	movs r1, 0
	bl sub_8013878
	movs r0, 0
_0802F89A:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_802F848

	thumb_func_start sub_802F8A0
sub_802F8A0:
	push {r4,lr}
	lsls r0, 24
	cmp r0, 0
	bne _0802F8BC
	ldr r0, _0802F8B8
	ldr r0, [r0]
	adds r0, 0xBC
	bl sub_8013660
	movs r0, 0
	b _0802F904
	.align 2, 0
_0802F8B8: .4byte gUnknown_203B314
_0802F8BC:
	ldr r4, _0802F8D8
	ldr r0, [r4]
	adds r0, 0xBC
	bl GetKeyPress
	cmp r0, 0x1
	beq _0802F8DC
	cmp r0, 0x2
	bne _0802F8E6
	movs r0, 0x1
	bl sub_80119D4
	movs r0, 0x2
	b _0802F904
	.align 2, 0
_0802F8D8: .4byte gUnknown_203B314
_0802F8DC:
	movs r0, 0
	bl sub_80119D4
	movs r0, 0x3
	b _0802F904
_0802F8E6:
	ldr r0, [r4]
	adds r0, 0xBC
	movs r1, 0x1
	bl sub_80138B8
	lsls r0, 24
	cmp r0, 0
	bne _0802F8FA
	movs r0, 0
	b _0802F904
_0802F8FA:
	bl sub_802F9C0
	bl sub_802FA50
	movs r0, 0x1
_0802F904:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_802F8A0

	thumb_func_start sub_802F90C
sub_802F90C:
	ldr r0, _0802F934
	ldr r2, [r0]
	adds r0, r2, 0
	adds r0, 0xDA
	movs r3, 0
	ldrsh r1, [r0, r3]
	subs r0, 0x2
	movs r3, 0
	ldrsh r0, [r0, r3]
	muls r0, r1
	adds r1, r2, 0
	adds r1, 0xD4
	movs r3, 0
	ldrsh r1, [r1, r3]
	adds r0, r1
	lsls r0, 1
	adds r0, r2, r0
	movs r1, 0
	ldrsh r0, [r0, r1]
	bx lr
	.align 2, 0
_0802F934: .4byte gUnknown_203B314
	thumb_func_end sub_802F90C

	thumb_func_start sub_802F938
sub_802F938:
	push {r4,r5,lr}
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	bl sub_802FBF4
	adds r1, r0, 0
	ldr r5, _0802F970
	ldr r0, [r5]
	adds r2, r0, 0
	adds r2, 0xDE
	strh r1, [r2]
	adds r0, 0xBC
	bl sub_8013984
	bl sub_802F9C0
	bl sub_802FA50
	cmp r4, 0
	beq _0802F96A
	ldr r0, [r5]
	adds r0, 0xBC
	bl AddMenuCursorSprite
_0802F96A:
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_0802F970: .4byte gUnknown_203B314
	thumb_func_end sub_802F938

	thumb_func_start sub_802F974
sub_802F974:
	push {r4,r5,lr}
	ldr r4, _0802F9B8
	ldr r2, [r4]
	cmp r2, 0
	beq _0802F9B2
	adds r0, r2, 0
	adds r0, 0xF0
	ldr r0, [r0]
	lsls r1, r0, 1
	adds r1, r0
	lsls r1, 3
	adds r1, r2, r1
	adds r1, 0xF8
	ldr r0, _0802F9BC
	ldm r0!, {r2,r3,r5}
	stm r1!, {r2,r3,r5}
	ldm r0!, {r2,r3,r5}
	stm r1!, {r2,r3,r5}
	bl ResetUnusedInputStruct
	ldr r0, [r4]
	adds r0, 0xF8
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	ldr r0, [r4]
	bl MemoryFree
	movs r0, 0
	str r0, [r4]
_0802F9B2:
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_0802F9B8: .4byte gUnknown_203B314
_0802F9BC: .4byte gUnknown_80E06FC
	thumb_func_end sub_802F974

	thumb_func_start sub_802F9C0
sub_802F9C0:
	push {r4,r5,lr}
	ldr r4, _0802FA44
	ldr r0, [r4]
	movs r1, 0xAC
	lsls r1, 1
	adds r0, r1
	movs r2, 0
	movs r1, 0x1
	strb r1, [r0]
	ldr r0, [r4]
	ldr r3, _0802FA48
	adds r0, r3
	strb r2, [r0]
	ldr r0, [r4]
	adds r3, 0x1
	adds r1, r0, r3
	movs r0, 0x8
	strb r0, [r1]
	ldr r0, [r4]
	ldr r1, _0802FA4C
	adds r0, r1
	strb r2, [r0]
	ldr r0, [r4]
	adds r0, 0xD6
	movs r2, 0
	ldrsh r0, [r0, r2]
	movs r1, 0xC
	bl sub_80095E4
	adds r0, 0x2
	lsls r0, 16
	ldr r3, [r4]
	adds r5, r3, 0
	adds r5, 0xF0
	ldr r2, [r5]
	lsls r1, r2, 1
	adds r1, r2
	lsls r1, 3
	adds r1, r3, r1
	movs r2, 0x83
	lsls r2, 1
	adds r1, r2
	asrs r2, r0, 16
	lsrs r0, 16
	strh r0, [r1]
	ldr r1, [r5]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 3
	adds r3, r0
	adds r2, 0x2
	movs r0, 0x84
	lsls r0, 1
	adds r3, r0
	strh r2, [r3]
	bl ResetUnusedInputStruct
	ldr r0, [r4]
	adds r0, 0xF8
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_0802FA44: .4byte gUnknown_203B314
_0802FA48: .4byte 0x00000159
_0802FA4C: .4byte 0x0000015b
	thumb_func_end sub_802F9C0

	thumb_func_start sub_802FA50
sub_802FA50:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0x8
	ldr r4, _0802FB1C
	ldr r0, [r4]
	adds r0, 0xF0
	ldr r0, [r0]
	bl sub_8008C54
	ldr r0, [r4]
	adds r0, 0xF0
	ldr r0, [r0]
	bl sub_80073B8
	ldr r2, _0802FB20
	ldr r0, [r4]
	adds r0, 0xF0
	ldr r3, [r0]
	movs r0, 0
	str r0, [sp]
	movs r0, 0xA
	movs r1, 0
	bl xxx_call_draw_string
	ldr r3, [r4]
	movs r1, 0xAD
	lsls r1, 1
	adds r0, r3, r1
	ldrb r0, [r0]
	lsls r0, 3
	adds r0, 0x4
	adds r1, r3, 0
	adds r1, 0xDA
	movs r5, 0
	ldrsh r2, [r1, r5]
	adds r2, 0x1
	movs r1, 0x7
	str r1, [sp]
	adds r1, r3, 0
	adds r1, 0xF0
	ldr r1, [r1]
	str r1, [sp, 0x4]
	movs r1, 0
	movs r3, 0x2
	bl sub_8012BC4
	ldr r1, [r4]
	adds r0, r1, 0
	adds r0, 0xB8
	ldrb r0, [r0]
	cmp r0, 0
	beq _0802FB78
	movs r6, 0
	adds r0, r1, 0
	adds r0, 0xD6
	movs r1, 0
	ldrsh r0, [r0, r1]
	cmp r6, r0
	blt _0802FACA
	b _0802FBD6
_0802FACA:
	mov r8, r4
_0802FACC:
	mov r2, r8
	ldr r0, [r2]
	adds r0, 0xBC
	adds r1, r6, 0
	bl sub_8013800
	adds r5, r0, 0
	mov r3, r8
	ldr r2, [r3]
	adds r0, r2, 0
	adds r0, 0xDA
	movs r3, 0
	ldrsh r1, [r0, r3]
	subs r0, 0x2
	movs r3, 0
	ldrsh r0, [r0, r3]
	muls r0, r1
	adds r1, r0, r6
	lsls r0, r1, 1
	adds r0, r2, r0
	movs r3, 0
	ldrsh r7, [r0, r3]
	adds r0, r2, 0
	adds r0, 0x5C
	adds r0, r1
	ldrb r4, [r0]
	cmp r4, 0
	beq _0802FB28
	adds r0, r2, 0
	adds r0, 0xF0
	ldr r3, [r0]
	movs r0, 0
	str r0, [sp]
	movs r0, 0xA
	adds r1, r5, 0
	ldr r2, _0802FB24
	bl xxx_call_draw_string
	b _0802FB46
	.align 2, 0
_0802FB1C: .4byte gUnknown_203B314
_0802FB20: .4byte gUnknown_80E0744
_0802FB24: .4byte gUnknown_80E0750
_0802FB28:
	adds r0, r2, 0
	adds r0, 0x8A
	adds r0, r1
	ldrb r0, [r0]
	cmp r0, 0
	beq _0802FB46
	adds r0, r2, 0
	adds r0, 0xF0
	ldr r3, [r0]
	str r4, [sp]
	movs r0, 0xA
	adds r1, r5, 0
	ldr r2, _0802FB74
	bl xxx_call_draw_string
_0802FB46:
	adds r0, r7, 0
	bl sub_80974A0
	adds r2, r0, 0
	mov r1, r8
	ldr r0, [r1]
	adds r0, 0xF0
	ldr r3, [r0]
	movs r0, 0
	str r0, [sp]
	movs r0, 0x18
	adds r1, r5, 0
	bl xxx_call_draw_string
	adds r6, 0x1
	mov r2, r8
	ldr r0, [r2]
	adds r0, 0xD6
	movs r3, 0
	ldrsh r0, [r0, r3]
	cmp r6, r0
	blt _0802FACC
	b _0802FBD6
	.align 2, 0
_0802FB74: .4byte gUnknown_80E0754
_0802FB78:
	movs r6, 0
	adds r0, r1, 0
	adds r0, 0xD6
	movs r5, 0
	ldrsh r0, [r0, r5]
	cmp r6, r0
	bge _0802FBD6
	adds r5, r4, 0
_0802FB88:
	ldr r0, [r5]
	adds r0, 0xBC
	adds r1, r6, 0
	bl sub_8013800
	adds r4, r0, 0
	ldr r1, [r5]
	adds r0, r1, 0
	adds r0, 0xDA
	movs r3, 0
	ldrsh r2, [r0, r3]
	subs r0, 0x2
	movs r3, 0
	ldrsh r0, [r0, r3]
	muls r0, r2
	adds r0, r6
	lsls r0, 1
	adds r1, r0
	movs r2, 0
	ldrsh r0, [r1, r2]
	bl sub_80974A0
	adds r2, r0, 0
	ldr r0, [r5]
	adds r0, 0xF0
	ldr r3, [r0]
	movs r0, 0
	str r0, [sp]
	movs r0, 0x8
	adds r1, r4, 0
	bl xxx_call_draw_string
	adds r6, 0x1
	ldr r0, [r5]
	adds r0, 0xD6
	movs r3, 0
	ldrsh r0, [r0, r3]
	cmp r6, r0
	blt _0802FB88
_0802FBD6:
	ldr r0, _0802FBF0
	ldr r0, [r0]
	adds r0, 0xF0
	ldr r0, [r0]
	bl sub_80073E0
	add sp, 0x8
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_0802FBF0: .4byte gUnknown_203B314
	thumb_func_end sub_802FA50

	thumb_func_start sub_802FBF4
sub_802FBF4:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x4
	movs r0, 0
	mov r8, r0
	movs r1, 0
	str r1, [sp]
_0802FC08:
	ldr r1, [sp]
	lsls r0, r1, 16
	asrs r4, r0, 16
	mov r10, r4
	adds r0, r4, 0
	bl sub_80A27CC
	lsls r0, 24
	cmp r0, 0
	beq _0802FCCE
	cmp r4, 0x13
	beq _0802FCCE
	cmp r4, 0x1D
	beq _0802FCCE
	ldr r7, _0802FC88
	ldr r1, [r7]
	mov r0, r8
	lsls r6, r0, 1
	adds r0, r1, r6
	strh r4, [r0]
	adds r1, 0x5C
	add r1, r8
	movs r0, 0
	strb r0, [r1]
	ldr r0, [r7]
	adds r0, 0x8A
	add r0, r8
	movs r1, 0
	strb r1, [r0]
	ldr r0, [r7]
	adds r0, 0xB8
	ldrb r0, [r0]
	cmp r0, 0
	beq _0802FCCA
	cmp r4, 0xD
	beq _0802FCCA
	adds r0, r4, 0
	bl sub_80A270C
	lsls r0, 24
	lsrs r0, 24
	mov r9, r0
	movs r5, 0
	cmp r4, 0x1E
	bgt _0802FCA8
	adds r0, r4, 0
	bl sub_8097384
	lsls r0, 24
	cmp r0, 0
	bne _0802FCA6
	cmp r4, 0x6
	bne _0802FC8C
	movs r0, 0x13
	bl sub_8097384
	lsls r0, 24
	cmp r0, 0
	beq _0802FCA8
	ldr r0, [r7]
	adds r0, r6
	movs r1, 0x13
	b _0802FCA4
	.align 2, 0
_0802FC88: .4byte gUnknown_203B314
_0802FC8C:
	mov r0, r10
	cmp r0, 0xA
	bne _0802FCA8
	movs r0, 0x1D
	bl sub_8097384
	lsls r0, 24
	cmp r0, 0
	beq _0802FCA8
	ldr r0, [r7]
	adds r0, r6
	movs r1, 0x1D
_0802FCA4:
	strh r1, [r0]
_0802FCA6:
	movs r5, 0x1
_0802FCA8:
	ldr r4, _0802FCEC
	ldr r0, [r4]
	adds r0, 0x5C
	add r0, r8
	strb r5, [r0]
	cmp r5, 0
	bne _0802FCCA
	mov r0, r9
	bl sub_80969D0
	cmp r0, 0
	ble _0802FCCA
	ldr r0, [r4]
	adds r0, 0x8A
	add r0, r8
	movs r1, 0x1
	strb r1, [r0]
_0802FCCA:
	movs r1, 0x1
	add r8, r1
_0802FCCE:
	ldr r0, [sp]
	adds r0, 0x1
	str r0, [sp]
	cmp r0, 0x2D
	ble _0802FC08
	mov r0, r8
	add sp, 0x4
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	.align 2, 0
_0802FCEC: .4byte gUnknown_203B314
	thumb_func_end sub_802FBF4

	thumb_func_start sub_802FCF0
sub_802FCF0:
	push {r4,lr}
	movs r4, 0
_0802FCF4:
	lsls r0, r4, 16
	asrs r0, 16
	bl sub_80A27CC
	lsls r0, 24
	cmp r0, 0
	beq _0802FD06
	movs r0, 0
	b _0802FD0E
_0802FD06:
	adds r4, 0x1
	cmp r4, 0x2D
	ble _0802FCF4
	movs r0, 0x1
_0802FD0E:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_802FCF0

	thumb_func_start sub_802FD14
sub_802FD14:
	push {r4-r6,lr}
	adds r5, r0, 0
	bl ResetUnusedInputStruct
	movs r0, 0
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	ldr r4, _0802FD48
	movs r0, 0xCC
	movs r1, 0x8
	bl MemoryAlloc
	str r0, [r4]
	ldr r1, _0802FD4C
	strh r1, [r0, 0x10]
	str r5, [r0]
	cmp r5, 0x7
	bhi _0802FDC0
	lsls r0, r5, 2
	ldr r1, _0802FD50
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0802FD48: .4byte gUnknown_203B318
_0802FD4C: .4byte 0x0000ffff
_0802FD50: .4byte _0802FD54
	.align 2, 0
_0802FD54:
	.4byte _0802FD74
	.4byte _0802FD84
	.4byte _0802FD94
	.4byte _0802FDA4
	.4byte _0802FDB4
	.4byte _0802FDB8
	.4byte _0802FDBC
	.4byte _0802FDC0
_0802FD74:
	movs r6, 0
	ldr r1, _0802FD80
	ldr r0, [r1]
	str r6, [r0, 0x4]
	b _0802FDCC
	.align 2, 0
_0802FD80: .4byte gUnknown_203B318
_0802FD84:
	movs r6, 0x7
	ldr r2, _0802FD90
	ldr r1, [r2]
	movs r0, 0
	b _0802FDC8
	.align 2, 0
_0802FD90: .4byte gUnknown_203B318
_0802FD94:
	movs r6, 0x6
	ldr r2, _0802FDA0
	ldr r1, [r2]
	movs r0, 0
	b _0802FDC8
	.align 2, 0
_0802FDA0: .4byte gUnknown_203B318
_0802FDA4:
	movs r6, 0x8
	ldr r2, _0802FDB0
	ldr r1, [r2]
	movs r0, 0
	b _0802FDC8
	.align 2, 0
_0802FDB0: .4byte gUnknown_203B318
_0802FDB4:
	movs r6, 0
	b _0802FDC2
_0802FDB8:
	movs r6, 0x7
	b _0802FDC2
_0802FDBC:
	movs r6, 0x6
	b _0802FDC2
_0802FDC0:
	movs r6, 0x8
_0802FDC2:
	ldr r2, _0802FDD8
	ldr r1, [r2]
	movs r0, 0x1
_0802FDC8:
	str r0, [r1, 0x4]
	adds r1, r2, 0
_0802FDCC:
	ldr r1, [r1]
	ldr r0, [r1, 0x4]
	cmp r0, 0x1
	bne _0802FDDC
	movs r0, 0
	b _0802FDE0
	.align 2, 0
_0802FDD8: .4byte gUnknown_203B318
_0802FDDC:
	adds r0, r1, 0
	adds r0, 0x58
_0802FDE0:
	str r0, [r1, 0x68]
	ldr r0, _0802FE48
	ldr r5, _0802FE4C
	adds r1, r5, 0
	bl sub_808D8E0
	ldr r4, _0802FE50
	adds r0, r4, 0
	adds r1, r5, 0
	bl sub_808D8E0
	adds r0, r5, 0
	bl GetMonSpecies
	adds r1, r0, 0
	subs r4, 0x50
	adds r0, r4, 0
	bl strcpy
	adds r0, r5, 0
	bl GetDialogueSpriteDataPtr
	ldr r3, _0802FE54
	ldr r1, [r3]
	str r0, [r1, 0x58]
	ldr r0, [r0, 0x4]
	str r0, [r1, 0x5C]
	adds r1, 0x64
	movs r2, 0
	strb r2, [r1]
	ldr r0, [r3]
	adds r0, 0x65
	strb r2, [r0]
	ldr r0, [r3]
	adds r0, 0x66
	strb r2, [r0]
	ldr r1, [r3]
	adds r2, r1, 0
	adds r2, 0x60
	movs r0, 0x2
	strh r0, [r2]
	adds r1, 0x62
	movs r0, 0x8
	strh r0, [r1]
	adds r0, r6, 0
	bl sub_802FF04
	movs r0, 0x1
	pop {r4-r6}
	pop {r1}
	bx r1
	.align 2, 0
_0802FE48: .4byte gUnknown_202E5D8
_0802FE4C: .4byte 0x00000141
_0802FE50: .4byte gUnknown_202E1C8
_0802FE54: .4byte gUnknown_203B318
	thumb_func_end sub_802FD14

	thumb_func_start sub_802FE58
sub_802FE58:
	push {lr}
	ldr r0, _0802FE70
	ldr r0, [r0]
	ldr r0, [r0, 0x8]
	cmp r0, 0xD
	bhi _0802FEC6
	lsls r0, 2
	ldr r1, _0802FE74
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0802FE70: .4byte gUnknown_203B318
_0802FE74: .4byte _0802FE78
	.align 2, 0
_0802FE78:
	.4byte _0802FEB0
	.4byte _0802FEB0
	.4byte _0802FEC6
	.4byte _0802FEC6
	.4byte _0802FEB6
	.4byte _0802FEC6
	.4byte _0802FEC6
	.4byte _0802FEC6
	.4byte _0802FEC6
	.4byte _0802FEC6
	.4byte _0802FEC6
	.4byte _0802FEBC
	.4byte _0802FEC6
	.4byte _0802FEC2
_0802FEB0:
	bl sub_8030208
	b _0802FECA
_0802FEB6:
	bl sub_8030258
	b _0802FECA
_0802FEBC:
	bl sub_80302A8
	b _0802FECA
_0802FEC2:
	movs r0, 0x3
	b _0802FECC
_0802FEC6:
	bl sub_80302C4
_0802FECA:
	movs r0, 0
_0802FECC:
	pop {r1}
	bx r1
	thumb_func_end sub_802FE58

	thumb_func_start sub_802FED0
sub_802FED0:
	ldr r0, _0802FEDC
	ldr r0, [r0]
	movs r1, 0x10
	ldrsh r0, [r0, r1]
	bx lr
	.align 2, 0
_0802FEDC: .4byte gUnknown_203B318
	thumb_func_end sub_802FED0

	thumb_func_start sub_802FEE0
sub_802FEE0:
	push {r4,lr}
	ldr r4, _0802FF00
	ldr r0, [r4]
	cmp r0, 0
	beq _0802FEFA
	ldr r0, [r0, 0x58]
	bl CloseFile
	ldr r0, [r4]
	bl MemoryFree
	movs r0, 0
	str r0, [r4]
_0802FEFA:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0802FF00: .4byte gUnknown_203B318
	thumb_func_end sub_802FEE0

	thumb_func_start sub_802FF04
sub_802FF04:
	push {lr}
	ldr r1, _0802FF18
	ldr r1, [r1]
	str r0, [r1, 0x8]
	bl sub_802FF1C
	bl sub_802FF88
	pop {r0}
	bx r0
	.align 2, 0
_0802FF18: .4byte gUnknown_203B318
	thumb_func_end sub_802FF04

	thumb_func_start sub_802FF1C
sub_802FF1C:
	push {r4-r7,lr}
	ldr r4, _0802FF3C
	ldr r0, [r4]
	adds r0, 0x6C
	bl sub_8006518
	ldr r0, [r4]
	ldr r0, [r0, 0x8]
	cmp r0, 0x4
	beq _0802FF44
	cmp r0, 0x4
	bgt _0802FF40
	cmp r0, 0
	beq _0802FF44
	b _0802FF68
	.align 2, 0
_0802FF3C: .4byte gUnknown_203B318
_0802FF40:
	cmp r0, 0xD
	bne _0802FF68
_0802FF44:
	ldr r0, _0802FF80
	mov r12, r0
	ldr r4, _0802FF84
	movs r3, 0
	movs r2, 0x3
_0802FF4E:
	mov r5, r12
	ldr r1, [r5]
	adds r1, r3
	adds r1, 0x6C
	adds r0, r4, 0
	ldm r0!, {r5-r7}
	stm r1!, {r5-r7}
	ldm r0!, {r5-r7}
	stm r1!, {r5-r7}
	adds r3, 0x18
	subs r2, 0x1
	cmp r2, 0
	bge _0802FF4E
_0802FF68:
	bl ResetUnusedInputStruct
	ldr r0, _0802FF80
	ldr r0, [r0]
	adds r0, 0x6C
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_0802FF80: .4byte gUnknown_203B318
_0802FF84: .4byte gUnknown_80E0760
	thumb_func_end sub_802FF1C

	thumb_func_start sub_802FF88
sub_802FF88:
	push {r4,r5,lr}
	sub sp, 0x18
	ldr r1, _0802FFA4
	ldr r0, [r1]
	ldr r0, [r0, 0x8]
	adds r5, r1, 0
	cmp r0, 0xD
	bls _0802FF9A
	b _080301A0
_0802FF9A:
	lsls r0, 2
	ldr r1, _0802FFA8
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0802FFA4: .4byte gUnknown_203B318
_0802FFA8: .4byte _0802FFAC
	.align 2, 0
_0802FFAC:
	.4byte _0802FFE4
	.4byte _08030000
	.4byte _08030038
	.4byte _08030050
	.4byte _08030068
	.4byte _08030074
	.4byte _080300DC
	.4byte _080300C4
	.4byte _080300F4
	.4byte _0803010C
	.4byte _08030148
	.4byte _08030174
	.4byte _08030180
	.4byte _080301A0
_0802FFE4:
	bl sub_80301B0
	ldr r2, _0802FFF8
	ldr r0, _0802FFFC
	ldr r5, [r0]
	ldr r1, [r5, 0x4]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 3
	b _0803000E
	.align 2, 0
_0802FFF8: .4byte gMakuhitaDialogue
_0802FFFC: .4byte gUnknown_203B318
_08030000:
	ldr r2, _08030034
	ldr r5, [r5]
	ldr r1, [r5, 0x4]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 3
	adds r2, 0x4
_0803000E:
	adds r0, r2
	ldr r0, [r0]
	ldr r2, [r5, 0x14]
	adds r3, r5, 0
	adds r3, 0x18
	movs r4, 0
	str r4, [sp]
	movs r1, 0x4
	str r1, [sp, 0x4]
	str r4, [sp, 0x8]
	ldr r1, [r5, 0x68]
	str r1, [sp, 0xC]
	movs r1, 0xC
	str r1, [sp, 0x10]
	movs r1, 0
	bl sub_8014248
	b _080301A0
	.align 2, 0
_08030034: .4byte gMakuhitaDialogue
_08030038:
	ldr r3, [r5]
	movs r0, 0xD
	str r0, [r3, 0xC]
	ldr r2, _0803004C
	ldr r1, [r3, 0x4]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 3
	adds r2, 0x8
	b _0803015A
	.align 2, 0
_0803004C: .4byte gMakuhitaDialogue
_08030050:
	ldr r3, [r5]
	movs r0, 0x4
	str r0, [r3, 0xC]
	ldr r2, _08030064
	ldr r1, [r3, 0x4]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 3
	adds r2, 0xC
	b _0803015A
	.align 2, 0
_08030064: .4byte gMakuhitaDialogue
_08030068:
	movs r0, 0x3
	movs r1, 0
	movs r2, 0xA
	bl sub_80302E8
	b _080301A0
_08030074:
	ldr r1, [r5]
	movs r0, 0xD
	str r0, [r1, 0xC]
	movs r2, 0x10
	ldrsh r0, [r1, r2]
	bl sub_80A2740
	lsls r0, 24
	lsrs r0, 24
	ldr r2, _080300B4
	ldr r1, [sp, 0x14]
	ands r1, r2
	orrs r1, r0
	ldr r0, _080300B8
	ands r1, r0
	movs r0, 0x80
	lsls r0, 1
	orrs r1, r0
	str r1, [sp, 0x14]
	ldr r0, _080300BC
	add r1, sp, 0x14
	bl sub_8090208
	ldr r2, _080300C0
	ldr r3, [r5]
	ldr r1, [r3, 0x4]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 3
	adds r2, 0x10
	b _0803015A
	.align 2, 0
_080300B4: .4byte 0xffffff00
_080300B8: .4byte 0xffff00ff
_080300BC: .4byte gAvailablePokemonNames
_080300C0: .4byte gMakuhitaDialogue
_080300C4:
	ldr r3, [r5]
	movs r0, 0xD
	str r0, [r3, 0xC]
	ldr r2, _080300D8
	ldr r1, [r3, 0x4]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 3
	adds r2, 0x18
	b _0803015A
	.align 2, 0
_080300D8: .4byte gMakuhitaDialogue
_080300DC:
	ldr r3, [r5]
	movs r0, 0xD
	str r0, [r3, 0xC]
	ldr r2, _080300F0
	ldr r1, [r3, 0x4]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 3
	adds r2, 0x14
	b _0803015A
	.align 2, 0
_080300F0: .4byte gMakuhitaDialogue
_080300F4:
	ldr r3, [r5]
	movs r0, 0x9
	str r0, [r3, 0xC]
	ldr r2, _08030108
	ldr r1, [r3, 0x4]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 3
	adds r2, 0x1C
	b _0803015A
	.align 2, 0
_08030108: .4byte gMakuhitaDialogue
_0803010C:
	ldr r4, _08030138
	bl sub_808D33C
	adds r1, r0, 0
	adds r0, r4, 0
	movs r2, 0x6
	bl sub_808D9AC
	ldr r0, _0803013C
	ldr r1, [r0]
	movs r0, 0xB
	str r0, [r1, 0xC]
	movs r0, 0xCB
	bl sub_8011988
	ldr r0, _08030140
	ldr r3, _08030144
	movs r1, 0
	movs r2, 0
	bl sub_80141B4
	b _080301A0
	.align 2, 0
_08030138: .4byte gPlayerName
_0803013C: .4byte gUnknown_203B318
_08030140: .4byte gUnknown_80E0778
_08030144: .4byte 0x00000101
_08030148:
	ldr r3, [r5]
	movs r0, 0xD
	str r0, [r3, 0xC]
	ldr r2, _0803016C
	ldr r1, [r3, 0x4]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 3
	adds r2, 0x20
_0803015A:
	adds r0, r2
	ldr r0, [r0]
	ldr r2, [r3, 0x68]
	ldr r3, _08030170
	movs r1, 0
	bl sub_80141B4
	b _080301A0
	.align 2, 0
_0803016C: .4byte gMakuhitaDialogue
_08030170: .4byte 0x0000010d
_08030174:
	movs r0, 0x1
	movs r1, 0x49
	movs r2, 0x1
	bl sub_801B60C
	b _080301A0
_08030180:
	ldr r3, [r5]
	movs r0, 0x1
	str r0, [r3, 0xC]
	ldr r2, _080301A8
	ldr r1, [r3, 0x4]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 3
	adds r2, 0x24
	adds r0, r2
	ldr r0, [r0]
	ldr r2, [r3, 0x68]
	ldr r3, _080301AC
	movs r1, 0
	bl sub_80141B4
_080301A0:
	add sp, 0x18
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_080301A8: .4byte gMakuhitaDialogue
_080301AC: .4byte 0x0000010d
	thumb_func_end sub_802FF88

	thumb_func_start sub_80301B0
sub_80301B0:
	push {r4,lr}
	ldr r4, _080301F8
	ldr r1, [r4]
	movs r2, 0x2
	str r2, [r1, 0x14]
	ldr r0, _080301FC
	str r0, [r1, 0x18]
	str r2, [r1, 0x1C]
	bl sub_80306A4
	lsls r0, 24
	cmp r0, 0
	beq _080301D6
	ldr r0, [r4]
	movs r1, 0x1
	negs r1, r1
	str r1, [r0, 0x1C]
	movs r1, 0x1
	str r1, [r0, 0x14]
_080301D6:
	ldr r1, [r4]
	movs r2, 0x1
	ldr r0, _08030200
	ldr r0, [r0]
	str r0, [r1, 0x20]
	movs r0, 0x3
	str r0, [r1, 0x24]
	ldr r0, _08030204
	ldr r0, [r0]
	str r0, [r1, 0x28]
	str r2, [r1, 0x2C]
	movs r0, 0
	str r0, [r1, 0x30]
	str r2, [r1, 0x34]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080301F8: .4byte gUnknown_203B318
_080301FC: .4byte gUnknown_80E07D8
_08030200: .4byte gUnknown_80D4970
_08030204: .4byte gUnknown_80D4934
	thumb_func_end sub_80301B0

	thumb_func_start sub_8030208
sub_8030208:
	push {lr}
	sub sp, 0x4
	mov r0, sp
	bl sub_80144A4
	cmp r0, 0
	bne _08030250
	ldr r0, _08030230
	ldr r1, [r0]
	ldr r0, [sp]
	str r0, [r1, 0x14]
	ldr r0, [sp]
	cmp r0, 0x2
	beq _0803023A
	cmp r0, 0x2
	bgt _08030234
	cmp r0, 0x1
	beq _0803024A
	b _08030250
	.align 2, 0
_08030230: .4byte gUnknown_203B318
_08030234:
	cmp r0, 0x3
	beq _08030242
	b _08030250
_0803023A:
	movs r0, 0x3
	bl sub_802FF04
	b _08030250
_08030242:
	movs r0, 0xC
	bl sub_802FF04
	b _08030250
_0803024A:
	movs r0, 0x2
	bl sub_802FF04
_08030250:
	add sp, 0x4
	pop {r0}
	bx r0
	thumb_func_end sub_8030208

	thumb_func_start sub_8030258
sub_8030258:
	push {lr}
	movs r0, 0x1
	bl sub_80303AC
	cmp r0, 0x2
	beq _08030288
	cmp r0, 0x2
	bcc _0803029A
	cmp r0, 0x3
	bne _0803029A
	bl sub_8030418
	ldr r1, _08030284
	ldr r1, [r1]
	strh r0, [r1, 0x10]
	bl sub_8030480
	movs r0, 0x5
	bl sub_802FF04
	b _0803029A
	.align 2, 0
_08030284: .4byte gUnknown_203B318
_08030288:
	bl sub_8030480
	ldr r0, _080302A0
	ldr r1, [r0]
	ldr r0, _080302A4
	strh r0, [r1, 0x10]
	movs r0, 0x1
	bl sub_802FF04
_0803029A:
	pop {r0}
	bx r0
	.align 2, 0
_080302A0: .4byte gUnknown_203B318
_080302A4: .4byte 0x0000ffff
	thumb_func_end sub_8030258

	thumb_func_start sub_80302A8
sub_80302A8:
	push {lr}
	bl sub_801B6AC
	cmp r0, 0x1
	bls _080302C0
	cmp r0, 0x3
	bhi _080302C0
	bl sub_801B72C
	movs r0, 0xA
	bl sub_802FF04
_080302C0:
	pop {r0}
	bx r0
	thumb_func_end sub_80302A8

	thumb_func_start sub_80302C4
sub_80302C4:
	push {lr}
	sub sp, 0x4
	mov r0, sp
	bl sub_80144A4
	cmp r0, 0
	bne _080302DC
	ldr r0, _080302E4
	ldr r0, [r0]
	ldr r0, [r0, 0xC]
	bl sub_802FF04
_080302DC:
	add sp, 0x4
	pop {r0}
	bx r0
	.align 2, 0
_080302E4: .4byte gUnknown_203B318
	thumb_func_end sub_80302C4

	thumb_func_start sub_80302E8
sub_80302E8:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	adds r5, r0, 0
	adds r6, r1, 0
	mov r8, r2
	bl sub_80306A4
	lsls r0, 24
	cmp r0, 0
	beq _08030302
	movs r0, 0
	b _0803039A
_08030302:
	ldr r4, _080303A4
	ldr r0, [r4]
	cmp r0, 0
	bne _08030314
	movs r0, 0xD0
	movs r1, 0x8
	bl MemoryAlloc
	str r0, [r4]
_08030314:
	ldr r0, [r4]
	str r5, [r0, 0x64]
	lsls r1, r5, 1
	adds r1, r5
	lsls r1, 3
	adds r1, 0x6C
	adds r1, r0, r1
	str r1, [r0, 0x68]
	adds r0, 0x6C
	bl sub_8006518
	ldr r1, [r4]
	ldr r2, [r1, 0x64]
	lsls r0, r2, 1
	adds r0, r2
	lsls r0, 3
	adds r1, r0
	adds r1, 0x6C
	ldr r0, _080303A8
	ldm r0!, {r2,r3,r7}
	stm r1!, {r2,r3,r7}
	ldm r0!, {r2,r3,r7}
	stm r1!, {r2,r3,r7}
	ldr r2, [r4]
	ldr r1, [r2, 0x68]
	adds r0, r2, 0
	adds r0, 0xCC
	str r0, [r1, 0x14]
	cmp r6, 0
	beq _08030362
	ldr r1, [r2, 0x64]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 3
	adds r1, r2, 0
	adds r1, 0x74
	adds r1, r0
	ldr r0, [r6]
	str r0, [r1]
_08030362:
	ldr r0, [r4]
	ldr r0, [r0, 0x68]
	mov r1, r8
	bl sub_8012D08
	bl ResetUnusedInputStruct
	ldr r0, [r4]
	adds r0, 0x6C
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	ldr r4, [r4]
	adds r4, 0x30
	bl sub_8030668
	adds r1, r0, 0
	adds r0, r4, 0
	mov r2, r8
	adds r3, r5, 0
	bl sub_8013818
	bl sub_80304C8
	bl sub_803053C
	movs r0, 0x1
_0803039A:
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r1}
	bx r1
	.align 2, 0
_080303A4: .4byte gUnknown_203B31C
_080303A8: .4byte gUnknown_80E0804
	thumb_func_end sub_80302E8

	thumb_func_start sub_80303AC
sub_80303AC:
	push {r4,lr}
	lsls r0, 24
	cmp r0, 0
	bne _080303C8
	ldr r0, _080303C4
	ldr r0, [r0]
	adds r0, 0x30
	bl sub_8013660
	movs r0, 0
	b _08030410
	.align 2, 0
_080303C4: .4byte gUnknown_203B31C
_080303C8:
	ldr r4, _080303E4
	ldr r0, [r4]
	adds r0, 0x30
	bl GetKeyPress
	cmp r0, 0x1
	beq _080303E8
	cmp r0, 0x2
	bne _080303F2
	movs r0, 0x1
	bl sub_80119D4
	movs r0, 0x2
	b _08030410
	.align 2, 0
_080303E4: .4byte gUnknown_203B31C
_080303E8:
	movs r0, 0
	bl sub_80119D4
	movs r0, 0x3
	b _08030410
_080303F2:
	ldr r0, [r4]
	adds r0, 0x30
	movs r1, 0x1
	bl sub_80138B8
	lsls r0, 24
	cmp r0, 0
	bne _08030406
	movs r0, 0
	b _08030410
_08030406:
	bl sub_80304C8
	bl sub_803053C
	movs r0, 0x1
_08030410:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_80303AC

	thumb_func_start sub_8030418
sub_8030418:
	ldr r0, _08030440
	ldr r2, [r0]
	adds r0, r2, 0
	adds r0, 0x4E
	movs r3, 0
	ldrsh r1, [r0, r3]
	subs r0, 0x2
	movs r3, 0
	ldrsh r0, [r0, r3]
	muls r0, r1
	adds r1, r2, 0
	adds r1, 0x48
	movs r3, 0
	ldrsh r1, [r1, r3]
	adds r0, r1
	lsls r0, 1
	adds r0, r2, r0
	movs r1, 0
	ldrsh r0, [r0, r1]
	bx lr
	.align 2, 0
_08030440: .4byte gUnknown_203B31C
	thumb_func_end sub_8030418

	thumb_func_start sub_8030444
sub_8030444:
	push {r4,r5,lr}
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	bl sub_8030668
	adds r1, r0, 0
	ldr r5, _0803047C
	ldr r0, [r5]
	adds r2, r0, 0
	adds r2, 0x52
	strh r1, [r2]
	adds r0, 0x30
	bl sub_8013984
	bl sub_80304C8
	bl sub_803053C
	cmp r4, 0
	beq _08030476
	ldr r0, [r5]
	adds r0, 0x30
	bl AddMenuCursorSprite
_08030476:
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_0803047C: .4byte gUnknown_203B31C
	thumb_func_end sub_8030444

	thumb_func_start sub_8030480
sub_8030480:
	push {r4,r5,lr}
	ldr r4, _080304C0
	ldr r2, [r4]
	cmp r2, 0
	beq _080304BA
	ldr r0, [r2, 0x64]
	lsls r1, r0, 1
	adds r1, r0
	lsls r1, 3
	adds r1, r2, r1
	adds r1, 0x6C
	ldr r0, _080304C4
	ldm r0!, {r2,r3,r5}
	stm r1!, {r2,r3,r5}
	ldm r0!, {r2,r3,r5}
	stm r1!, {r2,r3,r5}
	bl ResetUnusedInputStruct
	ldr r0, [r4]
	adds r0, 0x6C
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	ldr r0, [r4]
	bl MemoryFree
	movs r0, 0
	str r0, [r4]
_080304BA:
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_080304C0: .4byte gUnknown_203B31C
_080304C4: .4byte gUnknown_80E07EC
	thumb_func_end sub_8030480

	thumb_func_start sub_80304C8
sub_80304C8:
	push {r4,lr}
	ldr r4, _08030538
	ldr r0, [r4]
	adds r0, 0xCC
	movs r2, 0
	movs r1, 0x1
	strb r1, [r0]
	ldr r0, [r4]
	adds r0, 0xCD
	strb r2, [r0]
	ldr r0, [r4]
	adds r0, 0xCE
	movs r1, 0x8
	strb r1, [r0]
	ldr r0, [r4]
	adds r0, 0xCF
	strb r2, [r0]
	ldr r0, [r4]
	adds r0, 0x4A
	movs r1, 0
	ldrsh r0, [r0, r1]
	movs r1, 0xC
	bl sub_80095E4
	adds r0, 0x2
	lsls r0, 16
	ldr r2, [r4]
	ldr r3, [r2, 0x64]
	lsls r1, r3, 1
	adds r1, r3
	lsls r1, 3
	adds r1, r2, r1
	adds r1, 0x7A
	asrs r3, r0, 16
	lsrs r0, 16
	strh r0, [r1]
	ldr r1, [r2, 0x64]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 3
	adds r2, r0
	adds r3, 0x2
	adds r2, 0x7C
	strh r3, [r2]
	bl ResetUnusedInputStruct
	ldr r0, [r4]
	adds r0, 0x6C
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08030538: .4byte gUnknown_203B31C
	thumb_func_end sub_80304C8

	thumb_func_start sub_803053C
sub_803053C:
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	sub sp, 0x108
	ldr r4, _08030658
	ldr r0, [r4]
	ldr r0, [r0, 0x64]
	bl sub_8008C54
	ldr r0, [r4]
	ldr r0, [r0, 0x64]
	bl sub_80073B8
	ldr r2, _0803065C
	ldr r0, [r4]
	ldr r3, [r0, 0x64]
	movs r0, 0
	str r0, [sp]
	movs r0, 0xA
	movs r1, 0
	bl xxx_call_draw_string
	ldr r3, [r4]
	adds r0, r3, 0
	adds r0, 0xCE
	ldrb r0, [r0]
	lsls r0, 3
	adds r0, 0x4
	adds r1, r3, 0
	adds r1, 0x4E
	movs r5, 0
	ldrsh r2, [r1, r5]
	adds r2, 0x1
	movs r1, 0x7
	str r1, [sp]
	ldr r1, [r3, 0x64]
	str r1, [sp, 0x4]
	movs r1, 0
	movs r3, 0x2
	bl sub_8012BC4
	movs r0, 0
	mov r9, r0
	ldr r0, [r4]
	adds r0, 0x4A
	movs r1, 0
	ldrsh r0, [r0, r1]
	cmp r9, r0
	bge _0803063E
	mov r8, r4
_080305A2:
	mov r3, r8
	ldr r1, [r3]
	adds r0, r1, 0
	adds r0, 0x4E
	movs r5, 0
	ldrsh r2, [r0, r5]
	subs r0, 0x2
	movs r3, 0
	ldrsh r0, [r0, r3]
	muls r0, r2
	add r0, r9
	lsls r0, 1
	adds r1, r0
	movs r5, 0
	ldrsh r4, [r1, r5]
	adds r0, r4, 0
	bl sub_80A2740
	lsls r0, 24
	lsrs r7, r0, 24
	adds r0, r4, 0
	bl sub_80A2668
	adds r4, r0, 0
	lsls r4, 16
	asrs r4, 16
	mov r1, r8
	ldr r0, [r1]
	adds r0, 0x30
	mov r1, r9
	bl sub_8013800
	adds r6, r0, 0
	movs r5, 0x7
	adds r0, r4, 0
	bl sub_809758C
	lsls r0, 24
	cmp r0, 0
	beq _08030608
	mov r3, r8
	ldr r0, [r3]
	ldr r3, [r0, 0x64]
	movs r0, 0
	str r0, [sp]
	movs r0, 0x8
	adds r1, r6, 0
	ldr r2, _08030660
	bl xxx_call_draw_string
	movs r5, 0x4
_08030608:
	adds r0, r7, 0
	bl GetDungeonName1
	adds r3, r0, 0
	add r0, sp, 0x8
	ldr r1, _08030664
	adds r2, r5, 0
	bl sub_800D158
	mov r5, r8
	ldr r0, [r5]
	ldr r3, [r0, 0x64]
	movs r0, 0
	str r0, [sp]
	movs r0, 0x10
	adds r1, r6, 0
	add r2, sp, 0x8
	bl xxx_call_draw_string
	movs r0, 0x1
	add r9, r0
	ldr r0, [r5]
	adds r0, 0x4A
	movs r1, 0
	ldrsh r0, [r0, r1]
	cmp r9, r0
	blt _080305A2
_0803063E:
	ldr r0, _08030658
	ldr r0, [r0]
	ldr r0, [r0, 0x64]
	bl sub_80073E0
	add sp, 0x108
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_08030658: .4byte gUnknown_203B31C
_0803065C: .4byte gUnknown_80E081C
_08030660: .4byte gUnknown_80E0824
_08030664: .4byte gUnknown_80E0828
	thumb_func_end sub_803053C

	thumb_func_start sub_8030668
sub_8030668:
	push {r4-r6,lr}
	movs r6, 0
	movs r5, 0
_0803066E:
	lsls r0, r5, 16
	asrs r4, r0, 16
	adds r0, r4, 0
	bl sub_8097504
	lsls r0, 24
	cmp r0, 0
	beq _08030690
	adds r0, r4, 0
	bl sub_80A26CC
	ldr r1, _080306A0
	ldr r1, [r1]
	lsls r2, r6, 1
	adds r1, r2
	strh r0, [r1]
	adds r6, 0x1
_08030690:
	adds r5, 0x1
	cmp r5, 0x16
	ble _0803066E
	adds r0, r6, 0
	pop {r4-r6}
	pop {r1}
	bx r1
	.align 2, 0
_080306A0: .4byte gUnknown_203B31C
	thumb_func_end sub_8030668

	thumb_func_start sub_80306A4
sub_80306A4:
	movs r0, 0
	bx lr
	thumb_func_end sub_80306A4

	thumb_func_start sub_80306A8
sub_80306A8:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	adds r4, r0, 0
	adds r5, r1, 0
	adds r7, r2, 0
	mov r8, r3
	bl sub_8030C20
	lsls r0, 24
	cmp r0, 0
	beq _080306C4
	movs r0, 0
	b _08030756
_080306C4:
	ldr r6, _08030760
	movs r0, 0xC4
	movs r1, 0x8
	bl MemoryAlloc
	str r0, [r6]
	str r4, [r0, 0x20]
	str r5, [r0, 0x58]
	lsls r1, r5, 1
	adds r1, r5
	lsls r1, 3
	adds r1, 0x60
	adds r1, r0, r1
	str r1, [r0, 0x5C]
	adds r0, 0x60
	bl sub_8006518
	ldr r1, [r6]
	ldr r2, [r1, 0x58]
	lsls r0, r2, 1
	adds r0, r2
	lsls r0, 3
	adds r1, r0
	adds r1, 0x60
	ldr r0, _08030764
	ldm r0!, {r2-r4}
	stm r1!, {r2-r4}
	ldm r0!, {r2-r4}
	stm r1!, {r2-r4}
	ldr r2, [r6]
	ldr r1, [r2, 0x5C]
	adds r0, r2, 0
	adds r0, 0xC0
	str r0, [r1, 0x14]
	cmp r7, 0
	beq _0803071E
	ldr r1, [r2, 0x58]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 3
	adds r1, r2, 0
	adds r1, 0x68
	adds r1, r0
	ldr r0, [r7]
	str r0, [r1]
_0803071E:
	ldr r0, [r6]
	ldr r0, [r0, 0x5C]
	mov r1, r8
	bl sub_8012D08
	bl ResetUnusedInputStruct
	ldr r0, [r6]
	adds r0, 0x60
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	ldr r4, [r6]
	adds r4, 0x24
	bl sub_8030A74
	adds r1, r0, 0
	adds r0, r4, 0
	mov r2, r8
	adds r3, r5, 0
	bl sub_8013818
	bl sub_80308A0
	bl sub_803092C
	movs r0, 0x1
_08030756:
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r1}
	bx r1
	.align 2, 0
_08030760: .4byte gUnknown_203B320
_08030764: .4byte gUnknown_80E0854
	thumb_func_end sub_80306A8

	thumb_func_start sub_8030768
sub_8030768:
	push {lr}
	lsls r0, 24
	cmp r0, 0
	bne _08030784
	ldr r0, _08030780
	ldr r0, [r0]
	adds r0, 0x24
	bl sub_8013660
	movs r0, 0
	b _080307E6
	.align 2, 0
_08030780: .4byte gUnknown_203B320
_08030784:
	ldr r0, _0803079C
	ldr r0, [r0]
	adds r0, 0x24
	bl GetKeyPress
	cmp r0, 0x2
	beq _080307AE
	cmp r0, 0x2
	bgt _080307A0
	cmp r0, 0x1
	beq _080307B8
	b _080307C2
	.align 2, 0
_0803079C: .4byte gUnknown_203B320
_080307A0:
	cmp r0, 0x4
	bne _080307C2
	movs r0, 0x4
	bl sub_80119D4
	movs r0, 0x4
	b _080307E6
_080307AE:
	movs r0, 0x1
	bl sub_80119D4
	movs r0, 0x2
	b _080307E6
_080307B8:
	movs r0, 0
	bl sub_80119D4
	movs r0, 0x3
	b _080307E6
_080307C2:
	ldr r0, _080307D8
	ldr r0, [r0]
	adds r0, 0x24
	movs r1, 0x1
	bl sub_80138B8
	lsls r0, 24
	cmp r0, 0
	bne _080307DC
	movs r0, 0
	b _080307E6
	.align 2, 0
_080307D8: .4byte gUnknown_203B320
_080307DC:
	bl sub_80308A0
	bl sub_803092C
	movs r0, 0x1
_080307E6:
	pop {r1}
	bx r1
	thumb_func_end sub_8030768

	thumb_func_start sub_80307EC
sub_80307EC:
	ldr r0, _0803080C
	ldr r2, [r0]
	adds r0, r2, 0
	adds r0, 0x42
	movs r3, 0
	ldrsh r1, [r0, r3]
	subs r0, 0x2
	movs r3, 0
	ldrsh r0, [r0, r3]
	muls r0, r1
	movs r3, 0x3C
	ldrsh r1, [r2, r3]
	adds r0, r1
	adds r2, r0
	ldrb r0, [r2]
	bx lr
	.align 2, 0
_0803080C: .4byte gUnknown_203B320
	thumb_func_end sub_80307EC

	thumb_func_start sub_8030810
sub_8030810:
	push {r4,r5,lr}
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	bl sub_8030A74
	adds r1, r0, 0
	ldr r5, _08030848
	ldr r0, [r5]
	adds r2, r0, 0
	adds r2, 0x46
	strh r1, [r2]
	adds r0, 0x24
	bl sub_8013984
	bl sub_80308A0
	bl sub_803092C
	cmp r4, 0
	beq _08030842
	ldr r0, [r5]
	adds r0, 0x24
	bl AddMenuCursorSprite
_08030842:
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_08030848: .4byte gUnknown_203B320
	thumb_func_end sub_8030810

	thumb_func_start sub_803084C
sub_803084C:
	push {r4,r5,lr}
	ldr r4, _0803088C
	ldr r2, [r4]
	cmp r2, 0
	beq _08030886
	ldr r0, [r2, 0x58]
	lsls r1, r0, 1
	adds r1, r0
	lsls r1, 3
	adds r1, r2, r1
	adds r1, 0x60
	ldr r0, _08030890
	ldm r0!, {r2,r3,r5}
	stm r1!, {r2,r3,r5}
	ldm r0!, {r2,r3,r5}
	stm r1!, {r2,r3,r5}
	bl ResetUnusedInputStruct
	ldr r0, [r4]
	adds r0, 0x60
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	ldr r0, [r4]
	bl MemoryFree
	movs r0, 0
	str r0, [r4]
_08030886:
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_0803088C: .4byte gUnknown_203B320
_08030890: .4byte gUnknown_80E083C
	thumb_func_end sub_803084C

	thumb_func_start sub_8030894
sub_8030894:
	ldr r0, _0803089C
	ldr r0, [r0]
	bx lr
	.align 2, 0
_0803089C: .4byte gUnknown_203B320
	thumb_func_end sub_8030894

	thumb_func_start sub_80308A0
sub_80308A0:
	push {r4,lr}
	ldr r4, _08030928
	ldr r0, [r4]
	adds r1, r0, 0
	adds r1, 0x44
	ldrh r1, [r1]
	adds r0, 0xC0
	movs r2, 0
	strb r1, [r0]
	ldr r0, [r4]
	adds r1, r0, 0
	adds r1, 0x42
	ldrh r1, [r1]
	adds r0, 0xC1
	strb r1, [r0]
	ldr r0, [r4]
	adds r0, 0xC2
	movs r1, 0xC
	strb r1, [r0]
	ldr r0, [r4]
	adds r0, 0xC3
	strb r2, [r0]
	bl ResetUnusedInputStruct
	ldr r0, [r4]
	adds r0, 0x60
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	ldr r0, [r4]
	movs r1, 0x3E
	ldrsh r0, [r0, r1]
	movs r1, 0xC
	bl sub_80095E4
	adds r0, 0x2
	lsls r0, 16
	ldr r2, [r4]
	ldr r3, [r2, 0x58]
	lsls r1, r3, 1
	adds r1, r3
	lsls r1, 3
	adds r1, r2, r1
	adds r1, 0x6E
	asrs r3, r0, 16
	lsrs r0, 16
	strh r0, [r1]
	ldr r1, [r2, 0x58]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 3
	adds r2, r0
	adds r3, 0x2
	adds r2, 0x70
	strh r3, [r2]
	bl ResetUnusedInputStruct
	ldr r0, [r4]
	adds r0, 0x60
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08030928: .4byte gUnknown_203B320
	thumb_func_end sub_80308A0

	thumb_func_start sub_803092C
sub_803092C:
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	sub sp, 0x60
	ldr r7, _08030A24
	ldr r0, [r7]
	ldr r0, [r0, 0x58]
	bl sub_8008C54
	ldr r0, [r7]
	ldr r0, [r0, 0x58]
	bl sub_80073B8
	ldr r1, [r7]
	adds r0, r1, 0
	adds r0, 0x42
	movs r2, 0
	ldrsh r4, [r0, r2]
	lsls r4, 3
	adds r5, r4, 0
	adds r5, 0xA
	ldr r2, _08030A28
	ldr r0, [r1, 0x20]
	lsls r0, 2
	adds r0, r2
	ldr r2, [r0]
	ldr r3, [r1, 0x58]
	movs r0, 0
	str r0, [sp]
	adds r0, r5, 0
	movs r1, 0
	bl xxx_call_draw_string
	adds r4, 0x4
	ldr r3, [r7]
	adds r0, r3, 0
	adds r0, 0xC2
	ldrb r0, [r0]
	lsls r0, 3
	adds r5, r4, r0
	adds r0, r3, 0
	adds r0, 0x42
	movs r1, 0
	ldrsh r2, [r0, r1]
	adds r2, 0x1
	movs r0, 0x7
	str r0, [sp]
	ldr r0, [r3, 0x58]
	str r0, [sp, 0x4]
	adds r0, r5, 0
	movs r1, 0
	movs r3, 0x1
	bl sub_8012BC4
	movs r6, 0
	ldr r0, [r7]
	movs r2, 0x3E
	ldrsh r0, [r0, r2]
	cmp r6, r0
	bge _08030A56
	mov r9, r7
	mov r8, r6
	add r7, sp, 0x8
	mov r5, sp
	adds r5, 0x4B
_080309B0:
	mov r3, r9
	ldr r1, [r3]
	adds r0, r1, 0
	adds r0, 0x42
	movs r3, 0
	ldrsh r2, [r0, r3]
	subs r0, 0x2
	movs r3, 0
	ldrsh r0, [r0, r3]
	muls r0, r2
	adds r0, r6
	adds r1, r0
	ldrb r0, [r1]
	bl sub_8095228
	adds r4, r0, 0
	mov r1, r9
	ldr r0, [r1]
	ldr r1, [r0, 0x58]
	str r1, [sp, 0x8]
	adds r0, 0x24
	adds r1, r6, 0
	bl sub_8013800
	str r0, [sp, 0x50]
	add r1, sp, 0x48
	movs r0, 0x7
	strb r0, [r1]
	mov r0, sp
	adds r0, 0x4A
	mov r2, r8
	strb r2, [r0]
	add r0, sp, 0x4C
	strb r2, [r0]
	adds r0, r4, 0x4
	str r0, [sp, 0x10]
	adds r0, 0x10
	str r0, [sp, 0x14]
	ldrh r0, [r4, 0xC]
	strh r0, [r7, 0x10]
	ldrh r0, [r4, 0xC]
	strh r0, [r7, 0x12]
	strb r2, [r7, 0x14]
	subs r1, 0x12
	movs r0, 0x5
	strb r0, [r1]
	ldrb r0, [r4]
	cmp r0, 0x4
	beq _08030A32
	cmp r0, 0x4
	bgt _08030A2C
	cmp r0, 0x2
	bgt _08030A3E
	cmp r0, 0x1
	blt _08030A3E
	movs r0, 0x1
	strb r0, [r5]
	b _08030A42
	.align 2, 0
_08030A24: .4byte gUnknown_203B320
_08030A28: .4byte gUnknown_80E086C
_08030A2C:
	cmp r0, 0x5
	beq _08030A38
	b _08030A3E
_08030A32:
	movs r0, 0x3
	strb r0, [r5]
	b _08030A42
_08030A38:
	movs r0, 0x4
	strb r0, [r5]
	b _08030A42
_08030A3E:
	mov r3, r8
	strb r3, [r5]
_08030A42:
	add r0, sp, 0x8
	bl sub_803B6D4
	adds r6, 0x1
	mov r1, r9
	ldr r0, [r1]
	movs r2, 0x3E
	ldrsh r0, [r0, r2]
	cmp r6, r0
	blt _080309B0
_08030A56:
	ldr r0, _08030A70
	ldr r0, [r0]
	ldr r0, [r0, 0x58]
	bl sub_80073E0
	add sp, 0x60
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_08030A70: .4byte gUnknown_203B320
	thumb_func_end sub_803092C

	thumb_func_start sub_8030A74
sub_8030A74:
	push {r4,r5,lr}
	movs r2, 0
	ldr r0, _08030A90
	ldr r0, [r0]
	ldr r0, [r0, 0x20]
	cmp r0, 0x7
	bls _08030A84
	b _08030C0E
_08030A84:
	lsls r0, 2
	ldr r1, _08030A94
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08030A90: .4byte gUnknown_203B320
_08030A94: .4byte _08030A98
	.align 2, 0
_08030A98:
	.4byte _08030AB8
	.4byte _08030B10
	.4byte _08030B3C
	.4byte _08030B94
	.4byte _08030B68
	.4byte _08030BC0
	.4byte _08030AE4
	.4byte _08030BEC
_08030AB8:
	movs r1, 0
	ldr r5, _08030ADC
	ldr r4, _08030AE0
	movs r3, 0
_08030AC0:
	ldr r0, [r5]
	adds r0, r3
	ldrb r0, [r0]
	cmp r0, 0
	beq _08030AD2
	ldr r0, [r4]
	adds r0, r2
	strb r1, [r0]
	adds r2, 0x1
_08030AD2:
	adds r3, 0x30
	adds r1, 0x1
	cmp r1, 0x1F
	ble _08030AC0
	b _08030C0E
	.align 2, 0
_08030ADC: .4byte gUnknown_203B480
_08030AE0: .4byte gUnknown_203B320
_08030AE4:
	movs r1, 0
	ldr r5, _08030B08
	ldr r4, _08030B0C
	movs r3, 0
_08030AEC:
	ldr r0, [r5]
	adds r0, r3
	ldrb r0, [r0]
	cmp r0, 0x6
	bne _08030AFE
	ldr r0, [r4]
	adds r0, r2
	strb r1, [r0]
	adds r2, 0x1
_08030AFE:
	adds r3, 0x30
	adds r1, 0x1
	cmp r1, 0x1F
	ble _08030AEC
	b _08030C0E
	.align 2, 0
_08030B08: .4byte gUnknown_203B480
_08030B0C: .4byte gUnknown_203B320
_08030B10:
	movs r1, 0
	ldr r5, _08030B34
	ldr r4, _08030B38
	movs r3, 0
_08030B18:
	ldr r0, [r5]
	adds r0, r3
	ldrb r0, [r0]
	cmp r0, 0x1
	bne _08030B2A
	ldr r0, [r4]
	adds r0, r2
	strb r1, [r0]
	adds r2, 0x1
_08030B2A:
	adds r3, 0x30
	adds r1, 0x1
	cmp r1, 0x1F
	ble _08030B18
	b _08030C0E
	.align 2, 0
_08030B34: .4byte gUnknown_203B480
_08030B38: .4byte gUnknown_203B320
_08030B3C:
	movs r1, 0
	ldr r5, _08030B60
	ldr r4, _08030B64
	movs r3, 0
_08030B44:
	ldr r0, [r5]
	adds r0, r3
	ldrb r0, [r0]
	cmp r0, 0x2
	bne _08030B56
	ldr r0, [r4]
	adds r0, r2
	strb r1, [r0]
	adds r2, 0x1
_08030B56:
	adds r3, 0x30
	adds r1, 0x1
	cmp r1, 0x1F
	ble _08030B44
	b _08030C0E
	.align 2, 0
_08030B60: .4byte gUnknown_203B480
_08030B64: .4byte gUnknown_203B320
_08030B68:
	movs r1, 0
	ldr r5, _08030B8C
	ldr r4, _08030B90
	movs r3, 0
_08030B70:
	ldr r0, [r5]
	adds r0, r3
	ldrb r0, [r0]
	cmp r0, 0x4
	bne _08030B82
	ldr r0, [r4]
	adds r0, r2
	strb r1, [r0]
	adds r2, 0x1
_08030B82:
	adds r3, 0x30
	adds r1, 0x1
	cmp r1, 0x1F
	ble _08030B70
	b _08030C0E
	.align 2, 0
_08030B8C: .4byte gUnknown_203B480
_08030B90: .4byte gUnknown_203B320
_08030B94:
	movs r1, 0
	ldr r5, _08030BB8
	ldr r4, _08030BBC
	movs r3, 0
_08030B9C:
	ldr r0, [r5]
	adds r0, r3
	ldrb r0, [r0]
	cmp r0, 0x3
	bne _08030BAE
	ldr r0, [r4]
	adds r0, r2
	strb r1, [r0]
	adds r2, 0x1
_08030BAE:
	adds r3, 0x30
	adds r1, 0x1
	cmp r1, 0x1F
	ble _08030B9C
	b _08030C0E
	.align 2, 0
_08030BB8: .4byte gUnknown_203B480
_08030BBC: .4byte gUnknown_203B320
_08030BC0:
	movs r1, 0
	ldr r5, _08030BE4
	ldr r4, _08030BE8
	movs r3, 0
_08030BC8:
	ldr r0, [r5]
	adds r0, r3
	ldrb r0, [r0]
	cmp r0, 0x5
	bne _08030BDA
	ldr r0, [r4]
	adds r0, r2
	strb r1, [r0]
	adds r2, 0x1
_08030BDA:
	adds r3, 0x30
	adds r1, 0x1
	cmp r1, 0x1F
	ble _08030BC8
	b _08030C0E
	.align 2, 0
_08030BE4: .4byte gUnknown_203B480
_08030BE8: .4byte gUnknown_203B320
_08030BEC:
	movs r1, 0
	ldr r5, _08030C18
	ldr r4, _08030C1C
	movs r3, 0
_08030BF4:
	ldr r0, [r5]
	adds r0, r3
	ldrb r0, [r0]
	cmp r0, 0x7
	bne _08030C06
	ldr r0, [r4]
	adds r0, r2
	strb r1, [r0]
	adds r2, 0x1
_08030C06:
	adds r3, 0x30
	adds r1, 0x1
	cmp r1, 0x1F
	ble _08030BF4
_08030C0E:
	adds r0, r2, 0
	pop {r4,r5}
	pop {r1}
	bx r1
	.align 2, 0
_08030C18: .4byte gUnknown_203B480
_08030C1C: .4byte gUnknown_203B320
	thumb_func_end sub_8030A74

	thumb_func_start sub_8030C20
sub_8030C20:
	push {lr}
	cmp r0, 0x7
	bls _08030C28
	b _08030D34
_08030C28:
	lsls r0, 2
	ldr r1, _08030C34
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08030C34: .4byte _08030C38
	.align 2, 0
_08030C38:
	.4byte _08030C58
	.4byte _08030C90
	.4byte _08030CAC
	.4byte _08030CE4
	.4byte _08030CC8
	.4byte _08030D00
	.4byte _08030C74
	.4byte _08030D20
_08030C58:
	movs r1, 0
	ldr r0, _08030C70
	ldr r2, [r0]
_08030C5E:
	ldrb r0, [r2]
	cmp r0, 0
	bne _08030D1C
	adds r2, 0x30
	adds r1, 0x1
	cmp r1, 0x1F
	ble _08030C5E
	b _08030D34
	.align 2, 0
_08030C70: .4byte gUnknown_203B480
_08030C74:
	movs r1, 0
	ldr r0, _08030C8C
	ldr r2, [r0]
_08030C7A:
	ldrb r0, [r2]
	cmp r0, 0x6
	beq _08030D1C
	adds r2, 0x30
	adds r1, 0x1
	cmp r1, 0x1F
	ble _08030C7A
	b _08030D34
	.align 2, 0
_08030C8C: .4byte gUnknown_203B480
_08030C90:
	movs r1, 0
	ldr r0, _08030CA8
	ldr r2, [r0]
_08030C96:
	ldrb r0, [r2]
	cmp r0, 0x1
	beq _08030D1C
	adds r2, 0x30
	adds r1, 0x1
	cmp r1, 0x1F
	ble _08030C96
	b _08030D34
	.align 2, 0
_08030CA8: .4byte gUnknown_203B480
_08030CAC:
	movs r1, 0
	ldr r0, _08030CC4
	ldr r2, [r0]
_08030CB2:
	ldrb r0, [r2]
	cmp r0, 0x2
	beq _08030D1C
	adds r2, 0x30
	adds r1, 0x1
	cmp r1, 0x1F
	ble _08030CB2
	b _08030D34
	.align 2, 0
_08030CC4: .4byte gUnknown_203B480
_08030CC8:
	movs r1, 0
	ldr r0, _08030CE0
	ldr r2, [r0]
_08030CCE:
	ldrb r0, [r2]
	cmp r0, 0x4
	beq _08030D1C
	adds r2, 0x30
	adds r1, 0x1
	cmp r1, 0x1F
	ble _08030CCE
	b _08030D34
	.align 2, 0
_08030CE0: .4byte gUnknown_203B480
_08030CE4:
	movs r1, 0
	ldr r0, _08030CFC
	ldr r2, [r0]
_08030CEA:
	ldrb r0, [r2]
	cmp r0, 0x3
	beq _08030D1C
	adds r2, 0x30
	adds r1, 0x1
	cmp r1, 0x1F
	ble _08030CEA
	b _08030D34
	.align 2, 0
_08030CFC: .4byte gUnknown_203B480
_08030D00:
	movs r1, 0
	ldr r0, _08030D18
	ldr r2, [r0]
_08030D06:
	ldrb r0, [r2]
	cmp r0, 0x5
	beq _08030D1C
	adds r2, 0x30
	adds r1, 0x1
	cmp r1, 0x1F
	ble _08030D06
	b _08030D34
	.align 2, 0
_08030D18: .4byte gUnknown_203B480
_08030D1C:
	movs r0, 0
	b _08030D36
_08030D20:
	movs r1, 0
	ldr r0, _08030D3C
	ldr r2, [r0]
_08030D26:
	ldrb r0, [r2]
	cmp r0, 0x7
	beq _08030D1C
	adds r2, 0x30
	adds r1, 0x1
	cmp r1, 0x1F
	ble _08030D26
_08030D34:
	movs r0, 0x1
_08030D36:
	pop {r1}
	bx r1
	.align 2, 0
_08030D3C: .4byte gUnknown_203B480
	thumb_func_end sub_8030C20

	thumb_func_start sub_8030D40
sub_8030D40:
	push {r4-r6,lr}
	adds r4, r0, 0
	adds r5, r1, 0
	lsls r4, 24
	lsrs r4, 24
	ldr r6, _08030D98
	movs r0, 0x78
	movs r1, 0x8
	bl MemoryAlloc
	str r0, [r6]
	strb r4, [r0, 0xC]
	ldr r0, [r6]
	bl sub_801317C
	ldr r0, [r6]
	str r5, [r0, 0x10]
	lsls r1, r5, 1
	adds r1, r5
	lsls r1, 3
	adds r1, 0x18
	adds r1, r0, r1
	str r1, [r0, 0x14]
	adds r0, 0x18
	bl sub_8006518
	ldr r1, [r6]
	ldr r2, [r1, 0x10]
	lsls r0, r2, 1
	adds r0, r2
	lsls r0, 3
	adds r1, r0
	adds r1, 0x18
	ldr r0, _08030D9C
	ldm r0!, {r2-r4}
	stm r1!, {r2-r4}
	ldm r0!, {r2-r4}
	stm r1!, {r2-r4}
	bl sub_8030DD4
	movs r0, 0x1
	pop {r4-r6}
	pop {r1}
	bx r1
	.align 2, 0
_08030D98: .4byte gUnknown_203B324
_08030D9C: .4byte gUnknown_80E091C
	thumb_func_end sub_8030D40

	thumb_func_start sub_8030DA0
sub_8030DA0:
	push {lr}
	ldr r0, _08030DC0
	ldr r0, [r0]
	ldr r1, [r0, 0x10]
	bl sub_8012A64
	cmp r0, 0x1
	beq _08030DC4
	cmp r0, 0x2
	bne _08030DCE
	movs r0, 0x1
	bl sub_80119D4
	movs r0, 0x2
	b _08030DD0
	.align 2, 0
_08030DC0: .4byte gUnknown_203B324
_08030DC4:
	movs r0, 0
	bl sub_80119D4
	movs r0, 0x3
	b _08030DD0
_08030DCE:
	movs r0, 0
_08030DD0:
	pop {r1}
	bx r1
	thumb_func_end sub_8030DA0

	thumb_func_start sub_8030DD4
sub_8030DD4:
	push {lr}
	bl sub_8030E2C
	bl sub_8030E48
	pop {r0}
	bx r0
	thumb_func_end sub_8030DD4

	thumb_func_start sub_8030DE4
sub_8030DE4:
	push {r4,r5,lr}
	ldr r4, _08030E24
	ldr r2, [r4]
	cmp r2, 0
	beq _08030E1E
	ldr r0, [r2, 0x10]
	lsls r1, r0, 1
	adds r1, r0
	lsls r1, 3
	adds r1, r2, r1
	adds r1, 0x18
	ldr r0, _08030E28
	ldm r0!, {r2,r3,r5}
	stm r1!, {r2,r3,r5}
	ldm r0!, {r2,r3,r5}
	stm r1!, {r2,r3,r5}
	bl ResetUnusedInputStruct
	ldr r0, [r4]
	adds r0, 0x18
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	ldr r0, [r4]
	bl MemoryFree
	movs r0, 0
	str r0, [r4]
_08030E1E:
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_08030E24: .4byte gUnknown_203B324
_08030E28: .4byte gUnknown_80E0900
	thumb_func_end sub_8030DE4

	thumb_func_start sub_8030E2C
sub_8030E2C:
	push {lr}
	bl ResetUnusedInputStruct
	ldr r0, _08030E44
	ldr r0, [r0]
	adds r0, 0x18
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	pop {r0}
	bx r0
	.align 2, 0
_08030E44: .4byte gUnknown_203B324
	thumb_func_end sub_8030E2C

	thumb_func_start sub_8030E48
sub_8030E48:
	push {r4-r6,lr}
	mov r6, r8
	push {r6}
	sub sp, 0x15C
	ldr r3, _08030EA8
	ldr r4, _08030EAC
	ldr r2, [r4]
	ldrb r1, [r2, 0xC]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 4
	ldr r1, [r3]
	adds r5, r1, r0
	ldr r0, [r2, 0x10]
	bl sub_80073B8
	ldr r0, [r4]
	ldr r0, [r0, 0x10]
	str r0, [sp, 0x4]
	add r1, sp, 0x44
	movs r2, 0
	movs r0, 0x7
	strb r0, [r1]
	mov r0, sp
	adds r0, 0x46
	strb r2, [r0]
	add r0, sp, 0x48
	strb r2, [r0]
	adds r0, r5, 0x4
	str r0, [sp, 0xC]
	adds r0, 0x10
	str r0, [sp, 0x10]
	add r1, sp, 0x4
	ldrh r0, [r5, 0xC]
	strh r0, [r1, 0x10]
	ldrh r0, [r5, 0xC]
	strh r0, [r1, 0x12]
	adds r0, r1, 0
	strb r2, [r0, 0x14]
	adds r2, r5, 0
	adds r2, 0x22
	ldrb r0, [r2]
	cmp r0, 0
	bne _08030EB0
	adds r1, 0x2E
	movs r0, 0x5
	strb r0, [r1]
	b _08030EBE
	.align 2, 0
_08030EA8: .4byte gUnknown_203B480
_08030EAC: .4byte gUnknown_203B324
_08030EB0:
	mov r1, sp
	adds r1, 0x32
	movs r0, 0x2
	strb r0, [r1]
	ldrb r1, [r2]
	add r0, sp, 0x38
	strb r1, [r0]
_08030EBE:
	ldrb r0, [r5]
	cmp r0, 0x2
	beq _08030ED2
	cmp r0, 0x2
	ble _08030EE2
	cmp r0, 0x4
	beq _08030ED2
	cmp r0, 0x5
	beq _08030EDA
	b _08030EE2
_08030ED2:
	mov r1, sp
	adds r1, 0x45
	movs r0, 0xA
	b _08030EE8
_08030EDA:
	mov r1, sp
	adds r1, 0x45
	movs r0, 0xB
	b _08030EE8
_08030EE2:
	mov r1, sp
	adds r1, 0x45
	movs r0, 0x9
_08030EE8:
	strb r0, [r1]
	add r0, sp, 0x4
	bl sub_803B98C
	ldrh r0, [r5, 0x10]
	ldr r1, _08030F48
	bl __umodsi3
	adds r4, r0, 0
	lsls r4, 16
	lsrs r4, 16
	ldr r2, _08030F4C
	ldr r5, _08030F50
	ldr r0, [r5]
	ldr r3, [r0, 0x10]
	movs r0, 0
	mov r8, r0
	str r0, [sp]
	movs r0, 0xA
	movs r1, 0x68
	bl xxx_call_draw_string
	add r6, sp, 0x5C
	ldr r1, _08030F54
	adds r0, r6, 0
	adds r2, r4, 0
	bl sub_800D158
	ldr r0, [r5]
	ldr r3, [r0, 0x10]
	mov r0, r8
	str r0, [sp]
	movs r0, 0x44
	movs r1, 0x68
	adds r2, r6, 0
	bl xxx_call_draw_string
	ldr r0, [r5]
	ldr r0, [r0, 0x10]
	bl sub_80073E0
	add sp, 0x15C
	pop {r3}
	mov r8, r3
	pop {r4-r6}
	pop {r0}
	bx r0
	.align 2, 0
_08030F48: .4byte 0x00002710
_08030F4C: .4byte gUnknown_80E0934
_08030F50: .4byte gUnknown_203B324
_08030F54: .4byte gUnknown_80E0938
	thumb_func_end sub_8030E48

	thumb_func_start sub_8030F58
sub_8030F58:
	push {r4-r6,lr}
	adds r6, r0, 0
	bl ResetUnusedInputStruct
	movs r0, 0
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	ldr r5, _08030FF4
	ldr r0, [r5]
	cmp r0, 0
	bne _08030F88
	movs r4, 0x8E
	lsls r4, 1
	adds r0, r4, 0
	movs r1, 0x8
	bl MemoryAlloc
	str r0, [r5]
	movs r1, 0
	adds r2, r4, 0
	bl MemoryFill8
_08030F88:
	ldr r0, [r5]
	movs r1, 0x8C
	lsls r1, 1
	adds r0, r1
	str r6, [r0]
	movs r0, 0x98
	lsls r0, 1
	bl GetDialogueSpriteDataPtr
	ldr r2, [r5]
	movs r4, 0x84
	lsls r4, 1
	adds r1, r2, r4
	str r0, [r1]
	movs r3, 0x86
	lsls r3, 1
	adds r1, r2, r3
	ldr r0, [r0, 0x4]
	str r0, [r1]
	movs r0, 0x8A
	lsls r0, 1
	adds r2, r0
	movs r1, 0
	strb r1, [r2]
	ldr r0, [r5]
	ldr r2, _08030FF8
	adds r0, r2
	strb r1, [r0]
	ldr r0, [r5]
	adds r3, 0xA
	adds r0, r3
	strb r1, [r0]
	ldr r2, [r5]
	movs r0, 0x88
	lsls r0, 1
	adds r1, r2, r0
	movs r0, 0x2
	strh r0, [r1]
	subs r3, 0x4
	adds r1, r2, r3
	movs r0, 0x8
	strh r0, [r1]
	adds r0, r6, 0
	bl sub_8030C20
	lsls r0, 24
	lsrs r1, r0, 24
	cmp r1, 0
	beq _08031038
	cmp r6, 0x2
	beq _08030FFC
	cmp r6, 0x4
	beq _08031014
	b _08031022
	.align 2, 0
_08030FF4: .4byte gUnknown_203B328
_08030FF8: .4byte 0x00000115
_08030FFC:
	ldr r0, _0803100C
	ldr r2, [r5]
	adds r2, r4
	ldr r3, _08031010
	movs r1, 0
	bl sub_80141B4
	b _08031022
	.align 2, 0
_0803100C: .4byte gUnknown_80E09D8
_08031010: .4byte 0x00000101
_08031014:
	ldr r0, _0803102C
	ldr r2, [r5]
	adds r2, r4
	ldr r3, _08031030
	movs r1, 0
	bl sub_80141B4
_08031022:
	ldr r0, _08031034
	ldr r1, [r0]
	movs r0, 0x5
	str r0, [r1]
	b _08031048
	.align 2, 0
_0803102C: .4byte gUnknown_80E0A0C
_08031030: .4byte 0x00000101
_08031034: .4byte gUnknown_203B328
_08031038:
	ldr r0, [r5]
	str r1, [r0]
	adds r0, r6, 0
	movs r1, 0
	movs r2, 0
	movs r3, 0x8
	bl sub_80306A8
_08031048:
	movs r0, 0x1
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end sub_8030F58

	thumb_func_start sub_8031050
sub_8031050:
	push {lr}
	ldr r1, _08031068
	ldr r0, [r1]
	ldr r0, [r0]
	adds r2, r1, 0
	cmp r0, 0x6
	bhi _080310AC
	lsls r0, 2
	ldr r1, _0803106C
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08031068: .4byte gUnknown_203B328
_0803106C: .4byte _08031070
	.align 2, 0
_08031070:
	.4byte _0803108C
	.4byte _08031092
	.4byte _08031098
	.4byte _08031098
	.4byte _080310A2
	.4byte _080310A8
	.4byte _080310A8
_0803108C:
	bl sub_8031300
	b _080310AC
_08031092:
	bl sub_803136C
	b _080310AC
_08031098:
	ldr r0, [r2]
	ldr r0, [r0]
	bl sub_80313D8
	b _080310AC
_080310A2:
	bl sub_8031498
	b _080310AC
_080310A8:
	movs r0, 0x3
	b _080310AE
_080310AC:
	movs r0, 0
_080310AE:
	pop {r1}
	bx r1
	thumb_func_end sub_8031050

	thumb_func_start sub_80310B4
sub_80310B4:
	push {r4,lr}
	bl sub_803084C
	ldr r4, _080310E0
	ldr r0, [r4]
	cmp r0, 0
	beq _080310D8
	movs r1, 0x84
	lsls r1, 1
	adds r0, r1
	ldr r0, [r0]
	bl CloseFile
	ldr r0, [r4]
	bl MemoryFree
	movs r0, 0
	str r0, [r4]
_080310D8:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080310E0: .4byte gUnknown_203B328
	thumb_func_end sub_80310B4

	thumb_func_start sub_80310E4
sub_80310E4:
	push {lr}
	ldr r1, _080310F8
	ldr r1, [r1]
	str r0, [r1]
	bl sub_80310FC
	bl sub_8031258
	pop {r0}
	bx r0
	.align 2, 0
_080310F8: .4byte gUnknown_203B328
	thumb_func_end sub_80310E4

	thumb_func_start sub_80310FC
sub_80310FC:
	push {r4-r6,lr}
	ldr r4, _0803111C
	ldr r0, [r4]
	adds r0, 0xA8
	bl sub_8006518
	ldr r0, [r4]
	ldr r0, [r0]
	cmp r0, 0x6
	bls _08031112
	b _0803122C
_08031112:
	lsls r0, 2
	ldr r1, _08031120
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0803111C: .4byte gUnknown_203B328
_08031120: .4byte _08031124
	.align 2, 0
_08031124:
	.4byte _08031140
	.4byte _08031178
	.4byte _080311C0
	.4byte _080311C0
	.4byte _080311E8
	.4byte _0803122C
	.4byte _0803122C
_08031140:
	ldr r3, _08031170
	ldr r1, [r3]
	ldr r2, _08031174
	adds r1, 0xC0
	adds r0, r2, 0
	ldm r0!, {r4-r6}
	stm r1!, {r4-r6}
	ldm r0!, {r4-r6}
	stm r1!, {r4-r6}
	ldr r1, [r3]
	adds r1, 0xD8
	adds r0, r2, 0
	ldm r0!, {r4-r6}
	stm r1!, {r4-r6}
	ldm r0!, {r4-r6}
	stm r1!, {r4-r6}
	ldr r0, [r3]
	adds r0, 0xF0
	ldm r2!, {r1,r3,r4}
	stm r0!, {r1,r3,r4}
	ldm r2!, {r1,r5,r6}
	stm r0!, {r1,r5,r6}
	b _0803123A
	.align 2, 0
_08031170: .4byte gUnknown_203B328
_08031174: .4byte gUnknown_80E0990
_08031178:
	ldr r3, _080311B0
	ldr r1, [r3]
	adds r1, 0xC0
	ldr r0, _080311B4
	ldm r0!, {r2,r4,r5}
	stm r1!, {r2,r4,r5}
	ldm r0!, {r2,r4,r6}
	stm r1!, {r2,r4,r6}
	ldr r1, [r3]
	ldr r2, _080311B8
	adds r1, 0xD8
	adds r0, r2, 0
	ldm r0!, {r4-r6}
	stm r1!, {r4-r6}
	ldm r0!, {r4-r6}
	stm r1!, {r4-r6}
	ldr r0, [r3]
	adds r0, 0xF0
	ldm r2!, {r1,r5,r6}
	stm r0!, {r1,r5,r6}
	ldm r2!, {r4-r6}
	stm r0!, {r4-r6}
	ldr r0, [r3]
	adds r0, 0xC0
	ldr r1, _080311BC
	bl sub_8012CAC
	b _0803123A
	.align 2, 0
_080311B0: .4byte gUnknown_203B328
_080311B4: .4byte gUnknown_80E09A8
_080311B8: .4byte gUnknown_80E0990
_080311BC: .4byte gUnknown_80E0968
_080311C0:
	ldr r2, _080311DC
	ldr r1, [r2]
	adds r1, 0xD8
	ldr r0, _080311E0
	ldm r0!, {r3-r5}
	stm r1!, {r3-r5}
	ldm r0!, {r3,r4,r6}
	stm r1!, {r3,r4,r6}
	ldr r0, [r2]
	adds r0, 0xD8
	ldr r1, _080311E4
	bl sub_8012CAC
	b _0803123A
	.align 2, 0
_080311DC: .4byte gUnknown_203B328
_080311E0: .4byte gUnknown_80E09C0
_080311E4: .4byte gUnknown_80E0948
_080311E8:
	ldr r3, _08031224
	ldr r1, [r3]
	ldr r2, _08031228
	adds r1, 0xA8
	adds r0, r2, 0
	ldm r0!, {r4-r6}
	stm r1!, {r4-r6}
	ldm r0!, {r4-r6}
	stm r1!, {r4-r6}
	ldr r1, [r3]
	adds r1, 0xC0
	adds r0, r2, 0
	ldm r0!, {r4-r6}
	stm r1!, {r4-r6}
	ldm r0!, {r4-r6}
	stm r1!, {r4-r6}
	ldr r1, [r3]
	adds r1, 0xD8
	adds r0, r2, 0
	ldm r0!, {r4-r6}
	stm r1!, {r4-r6}
	ldm r0!, {r4-r6}
	stm r1!, {r4-r6}
	ldr r0, [r3]
	adds r0, 0xF0
	ldm r2!, {r1,r5,r6}
	stm r0!, {r1,r5,r6}
	ldm r2!, {r3-r5}
	stm r0!, {r3-r5}
	b _0803123A
	.align 2, 0
_08031224: .4byte gUnknown_203B328
_08031228: .4byte gUnknown_80E0990
_0803122C:
	bl ResetUnusedInputStruct
	movs r0, 0
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
_0803123A:
	bl ResetUnusedInputStruct
	ldr r0, _08031254
	ldr r0, [r0]
	adds r0, 0xA8
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	pop {r4-r6}
	pop {r0}
	bx r0
	.align 2, 0
_08031254: .4byte gUnknown_203B328
	thumb_func_end sub_80310FC

	thumb_func_start sub_8031258
sub_8031258:
	push {r4,lr}
	sub sp, 0x8
	ldr r1, _08031274
	ldr r0, [r1]
	ldr r0, [r0]
	adds r2, r1, 0
	cmp r0, 0x6
	bhi _080312F6
	lsls r0, 2
	ldr r1, _08031278
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08031274: .4byte gUnknown_203B328
_08031278: .4byte _0803127C
	.align 2, 0
_0803127C:
	.4byte _08031298
	.4byte _080312A0
	.4byte _080312BC
	.4byte _080312BC
	.4byte _080312EC
	.4byte _080312F6
	.4byte _080312F6
_08031298:
	movs r0, 0x1
	bl sub_8030810
	b _080312F6
_080312A0:
	bl sub_803092C
	ldr r0, _080312B4
	ldr r0, [r0]
	adds r0, 0x8
	ldr r1, _080312B8
	movs r2, 0x4
	str r2, [sp]
	movs r2, 0x1
	b _080312D8
	.align 2, 0
_080312B4: .4byte gUnknown_203B328
_080312B8: .4byte gUnknown_80E0968
_080312BC:
	bl sub_803092C
	ldr r4, _080312E4
	ldr r0, [r4]
	adds r0, 0x8
	movs r1, 0
	bl sub_8012EA4
	ldr r0, [r4]
	adds r0, 0x58
	ldr r1, _080312E8
	movs r2, 0x3
	str r2, [sp]
	movs r2, 0x2
_080312D8:
	str r2, [sp, 0x4]
	movs r2, 0
	movs r3, 0
	bl sub_8012D60
	b _080312F6
	.align 2, 0
_080312E4: .4byte gUnknown_203B328
_080312E8: .4byte gUnknown_80E0948
_080312EC:
	ldr r0, [r2]
	ldrb r0, [r0, 0x4]
	movs r1, 0x3
	bl sub_8030D40
_080312F6:
	add sp, 0x8
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_8031258

	thumb_func_start sub_8031300
sub_8031300:
	push {lr}
	movs r0, 0x1
	bl sub_8030768
	cmp r0, 0x4
	bhi _08031366
	lsls r0, 2
	ldr r1, _08031318
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08031318: .4byte _0803131C
	.align 2, 0
_0803131C:
	.4byte _08031366
	.4byte _08031366
	.4byte _08031360
	.4byte _08031330
	.4byte _08031348
_08031330:
	bl sub_80307EC
	ldr r1, _08031344
	ldr r1, [r1]
	strb r0, [r1, 0x4]
	movs r0, 0x1
	bl sub_80310E4
	b _08031366
	.align 2, 0
_08031344: .4byte gUnknown_203B328
_08031348:
	bl sub_80307EC
	ldr r1, _0803135C
	ldr r1, [r1]
	strb r0, [r1, 0x4]
	movs r0, 0x4
	bl sub_80310E4
	b _08031366
	.align 2, 0
_0803135C: .4byte gUnknown_203B328
_08031360:
	movs r0, 0x6
	bl sub_80310E4
_08031366:
	pop {r0}
	bx r0
	thumb_func_end sub_8031300

	thumb_func_start sub_803136C
sub_803136C:
	push {r4,lr}
	sub sp, 0x4
	movs r0, 0
	str r0, [sp]
	bl sub_8030768
	ldr r4, _080313A4
	ldr r0, [r4]
	adds r0, 0x8
	bl sub_8012FD8
	lsls r0, 24
	cmp r0, 0
	bne _08031392
	ldr r0, [r4]
	adds r0, 0x8
	mov r1, sp
	bl sub_8013114
_08031392:
	ldr r0, [sp]
	cmp r0, 0x4
	beq _080313C2
	cmp r0, 0x4
	bgt _080313A8
	cmp r0, 0x1
	beq _080313B2
	b _080313D0
	.align 2, 0
_080313A4: .4byte gUnknown_203B328
_080313A8:
	cmp r0, 0x5
	beq _080313CA
	cmp r0, 0x6
	beq _080313BA
	b _080313D0
_080313B2:
	movs r0, 0
	bl sub_80310E4
	b _080313D0
_080313BA:
	movs r0, 0x3
	bl sub_80310E4
	b _080313D0
_080313C2:
	movs r0, 0x2
	bl sub_80310E4
	b _080313D0
_080313CA:
	movs r0, 0x4
	bl sub_80310E4
_080313D0:
	add sp, 0x4
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_803136C

	thumb_func_start sub_80313D8
sub_80313D8:
	push {r4,r5,lr}
	sub sp, 0x4
	adds r5, r0, 0
	movs r0, 0
	str r0, [sp]
	bl sub_8030768
	ldr r4, _08031418
	ldr r0, [r4]
	adds r0, 0x8
	bl sub_8012FD8
	ldr r0, [r4]
	adds r0, 0x58
	bl sub_8012FD8
	lsls r0, 24
	cmp r0, 0
	bne _08031408
	ldr r0, [r4]
	adds r0, 0x58
	mov r1, sp
	bl sub_8013114
_08031408:
	ldr r0, [sp]
	cmp r0, 0x2
	beq _08031428
	cmp r0, 0x2
	bgt _0803141C
	cmp r0, 0x1
	beq _08031420
	b _0803148E
	.align 2, 0
_08031418: .4byte gUnknown_203B328
_0803141C:
	cmp r0, 0x3
	bne _0803148E
_08031420:
	movs r0, 0
	bl sub_80310E4
	b _0803148E
_08031428:
	cmp r5, 0x2
	beq _08031432
	cmp r5, 0x3
	beq _0803143C
	b _0803145A
_08031432:
	ldr r0, [r4]
	ldrb r0, [r0, 0x4]
	bl sub_8095240
	b _0803145A
_0803143C:
	ldr r4, _08031480
	movs r3, 0
	movs r1, 0
	movs r2, 0x1F
_08031444:
	ldr r0, [r4]
	adds r0, r1
	strb r3, [r0]
	ldr r0, [r4]
	adds r0, r1
	adds r0, 0x22
	strb r3, [r0]
	adds r1, 0x30
	subs r2, 0x1
	cmp r2, 0
	bge _08031444
_0803145A:
	ldr r0, _08031484
	ldr r0, [r0]
	movs r1, 0x8C
	lsls r1, 1
	adds r0, r1
	ldr r0, [r0]
	cmp r0, 0x2
	beq _0803146E
	cmp r0, 0x4
	bne _0803148E
_0803146E:
	bl sub_8030C20
	lsls r0, 24
	cmp r0, 0
	beq _08031488
	movs r0, 0x5
	bl sub_80310E4
	b _0803148E
	.align 2, 0
_08031480: .4byte gUnknown_203B480
_08031484: .4byte gUnknown_203B328
_08031488:
	movs r0, 0
	bl sub_80310E4
_0803148E:
	add sp, 0x4
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_80313D8

	thumb_func_start sub_8031498
sub_8031498:
	push {lr}
	bl sub_8030DA0
	cmp r0, 0x1
	bls _080314B0
	cmp r0, 0x3
	bhi _080314B0
	bl sub_8030DE4
	movs r0, 0
	bl sub_80310E4
_080314B0:
	pop {r0}
	bx r0
	thumb_func_end sub_8031498

	thumb_func_start sub_80314B4
sub_80314B4:
	push {r4-r6,lr}
	lsls r0, 16
	asrs r5, r0, 16
	bl ResetUnusedInputStruct
	movs r0, 0
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	ldr r6, _08031534
	movs r0, 0x18
	movs r1, 0x8
	bl MemoryAlloc
	str r0, [r6]
	ldr r0, _08031538
	adds r1, r5, 0
	bl sub_808D8E0
	adds r0, r5, 0
	bl GetMonSpecies
	adds r1, r0, 0
	ldr r0, _0803153C
	bl strcpy
	ldr r0, [r6]
	movs r4, 0
	str r4, [r0, 0x8]
	str r4, [r0, 0xC]
	cmp r5, 0
	beq _0803151E
	adds r0, r5, 0
	bl GetDialogueSpriteDataPtr
	ldr r1, [r6]
	str r0, [r1, 0x8]
	strb r4, [r1, 0x14]
	ldr r0, [r6]
	strb r4, [r0, 0x15]
	ldr r0, [r6]
	strb r4, [r0, 0x16]
	ldr r1, [r6]
	movs r0, 0x2
	strh r0, [r1, 0x10]
	movs r0, 0x8
	strh r0, [r1, 0x12]
	ldr r0, [r1, 0x8]
	cmp r0, 0
	beq _0803151E
	ldr r0, [r0, 0x4]
	str r0, [r1, 0xC]
_0803151E:
	ldr r0, _08031534
	ldr r1, [r0]
	movs r0, 0
	str r0, [r1, 0x4]
	movs r0, 0x1
	bl sub_80317C0
	movs r0, 0x1
	pop {r4-r6}
	pop {r1}
	bx r1
	.align 2, 0
_08031534: .4byte gUnknown_203B32C
_08031538: .4byte gUnknown_202E5D8
_0803153C: .4byte gAvailablePokemonNames
	thumb_func_end sub_80314B4

	thumb_func_start sub_8031540
sub_8031540:
	push {lr}
	ldr r0, _08031558
	ldr r0, [r0]
	ldrb r0, [r0]
	cmp r0, 0x9
	bhi _080315BA
	lsls r0, 2
	ldr r1, _0803155C
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08031558: .4byte gUnknown_203B32C
_0803155C: .4byte _08031560
	.align 2, 0
_08031560:
	.4byte _080315AC
	.4byte _08031588
	.4byte _08031588
	.4byte _0803158E
	.4byte _08031594
	.4byte _0803159A
	.4byte _080315A0
	.4byte _080315A6
	.4byte _080315B0
	.4byte _080315B6
_08031588:
	bl sub_80317D8
	b _080315BA
_0803158E:
	bl sub_8031848
	b _080315BA
_08031594:
	bl sub_8031864
	b _080315BA
_0803159A:
	bl sub_80318D0
	b _080315BA
_080315A0:
	bl sub_80318EC
	b _080315BA
_080315A6:
	bl sub_803192C
	b _080315BA
_080315AC:
	movs r0, 0x3
	b _080315BC
_080315B0:
	bl sub_8031948
	b _080315BA
_080315B6:
	bl sub_8031988
_080315BA:
	movs r0, 0
_080315BC:
	pop {r1}
	bx r1
	thumb_func_end sub_8031540

	thumb_func_start sub_80315C0
sub_80315C0:
	push {r4,lr}
	ldr r4, _080315E4
	ldr r0, [r4]
	cmp r0, 0
	beq _080315DE
	ldr r0, [r0, 0x8]
	cmp r0, 0
	beq _080315D4
	bl CloseFile
_080315D4:
	ldr r0, [r4]
	bl MemoryFree
	movs r0, 0
	str r0, [r4]
_080315DE:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080315E4: .4byte gUnknown_203B32C
	thumb_func_end sub_80315C0

	thumb_func_start nullsub_39
nullsub_39:
	bx lr
	thumb_func_end nullsub_39

	thumb_func_start sub_80315EC
sub_80315EC:
	push {r4,r5,lr}
	sub sp, 0x14
	movs r5, 0
	ldr r0, _08031618
	ldr r2, [r0]
	ldr r1, [r2, 0x8]
	adds r3, r0, 0
	cmp r1, 0
	beq _08031602
	adds r5, r2, 0
	adds r5, 0x8
_08031602:
	ldrb r0, [r2]
	subs r0, 0x1
	cmp r0, 0x8
	bls _0803160C
	b _080317B0
_0803160C:
	lsls r0, 2
	ldr r1, _0803161C
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08031618: .4byte gUnknown_203B32C
_0803161C: .4byte _08031620
	.align 2, 0
_08031620:
	.4byte _08031700
	.4byte _08031714
	.4byte _08031728
	.4byte _08031758
	.4byte _08031780
	.4byte _08031694
	.4byte _080316A8
	.4byte _08031644
	.4byte _08031658
_08031644:
	ldr r0, _08031650
	ldr r1, [r3]
	ldr r2, [r1, 0x4]
	ldr r3, _08031654
	b _08031760
	.align 2, 0
_08031650: .4byte gUnknown_80E0C4C
_08031654: .4byte gUnknown_80E0BD4
_08031658:
	ldr r0, [r3]
	ldr r0, [r0, 0x4]
	cmp r0, 0x10
	beq _0803167C
	cmp r0, 0x10
	bgt _0803166A
	cmp r0, 0xF
	beq _08031674
	b _080317B0
_0803166A:
	cmp r0, 0x11
	beq _08031684
	cmp r0, 0x12
	beq _0803168C
	b _080317B0
_08031674:
	ldr r0, _08031678
	b _08031790
	.align 2, 0
_08031678: .4byte gUnknown_80E0C70
_0803167C:
	ldr r0, _08031680
	b _08031790
	.align 2, 0
_08031680: .4byte gUnknown_80E0DD0
_08031684:
	ldr r0, _08031688
	b _08031790
	.align 2, 0
_08031688: .4byte gUnknown_80E0ED8
_0803168C:
	ldr r0, _08031690
	b _08031790
	.align 2, 0
_08031690: .4byte gUnknown_80E10C8
_08031694:
	ldr r0, _080316A0
	ldr r1, [r3]
	ldr r2, [r1, 0x4]
	ldr r3, _080316A4
	b _08031760
	.align 2, 0
_080316A0: .4byte gUnknown_80E0C4C
_080316A4: .4byte gUnknown_80E0B3C
_080316A8:
	ldr r0, [r3]
	ldr r0, [r0, 0x4]
	subs r0, 0xA
	cmp r0, 0x4
	bls _080316B4
	b _080317B0
_080316B4:
	lsls r0, 2
	ldr r1, _080316C0
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080316C0: .4byte _080316C4
	.align 2, 0
_080316C4:
	.4byte _080316D8
	.4byte _080316E0
	.4byte _080316F0
	.4byte _080316E8
	.4byte _080316F8
_080316D8:
	ldr r0, _080316DC
	b _08031790
	.align 2, 0
_080316DC: .4byte gUnknown_80E120C
_080316E0:
	ldr r0, _080316E4
	b _08031790
	.align 2, 0
_080316E4: .4byte gUnknown_80E136C
_080316E8:
	ldr r0, _080316EC
	b _08031790
	.align 2, 0
_080316EC: .4byte gUnknown_80E1420
_080316F0:
	ldr r0, _080316F4
	b _08031790
	.align 2, 0
_080316F4: .4byte gUnknown_80E157C
_080316F8:
	ldr r0, _080316FC
	b _08031790
	.align 2, 0
_080316FC: .4byte gUnknown_80E169C
_08031700:
	ldr r0, _0803170C
	ldr r1, [r3]
	ldr r2, [r1, 0x4]
	ldr r3, _08031710
	b _08031760
	.align 2, 0
_0803170C: .4byte gUnknown_80E17C8
_08031710: .4byte gUnknown_80E0A48
_08031714:
	ldr r0, _08031720
	ldr r1, [r3]
	ldr r2, [r1, 0x4]
	ldr r3, _08031724
	b _08031760
	.align 2, 0
_08031720: .4byte gUnknown_80E183C
_08031724: .4byte gUnknown_80E0A48
_08031728:
	ldr r0, [r3]
	ldr r0, [r0, 0x4]
	cmp r0, 0x1
	beq _08031748
	cmp r0, 0x1
	bgt _0803173A
	cmp r0, 0
	beq _08031740
	b _080317B0
_0803173A:
	cmp r0, 0x2
	beq _08031750
	b _080317B0
_08031740:
	ldr r0, _08031744
	b _08031790
	.align 2, 0
_08031744: .4byte gUnknown_80E1868
_08031748:
	ldr r0, _0803174C
	b _08031790
	.align 2, 0
_0803174C: .4byte gUnknown_80E1A30
_08031750:
	ldr r0, _08031754
	b _08031790
	.align 2, 0
_08031754: .4byte gUnknown_80E1AD8
_08031758:
	ldr r0, _08031778
	ldr r1, [r3]
	ldr r2, [r1, 0x4]
	ldr r3, _0803177C
_08031760:
	movs r4, 0
	str r4, [sp]
	movs r1, 0x4
	str r1, [sp, 0x4]
	str r4, [sp, 0x8]
	str r5, [sp, 0xC]
	movs r1, 0xC
	str r1, [sp, 0x10]
	movs r1, 0
	bl sub_8014248
	b _080317B0
	.align 2, 0
_08031778: .4byte gUnknown_80E0C4C
_0803177C: .4byte gUnknown_80E0ABC
_08031780:
	ldr r0, [r3]
	ldr r0, [r0, 0x4]
	cmp r0, 0x6
	beq _0803178E
	cmp r0, 0x9
	beq _080317A4
	b _080317B0
_0803178E:
	ldr r0, _0803179C
_08031790:
	ldr r3, _080317A0
	movs r1, 0
	adds r2, r5, 0
	bl sub_80141B4
	b _080317B0
	.align 2, 0
_0803179C: .4byte gUnknown_80E1B88
_080317A0: .4byte 0x0000010d
_080317A4:
	ldr r0, _080317B8
	ldr r3, _080317BC
	movs r1, 0
	adds r2, r5, 0
	bl sub_80141B4
_080317B0:
	add sp, 0x14
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_080317B8: .4byte gUnknown_80E1D84
_080317BC: .4byte 0x0000010d
	thumb_func_end sub_80315EC

	thumb_func_start sub_80317C0
sub_80317C0:
	push {lr}
	ldr r1, _080317D4
	ldr r1, [r1]
	strb r0, [r1]
	bl nullsub_39
	bl sub_80315EC
	pop {r0}
	bx r0
	.align 2, 0
_080317D4: .4byte gUnknown_203B32C
	thumb_func_end sub_80317C0

	thumb_func_start sub_80317D8
sub_80317D8:
	push {lr}
	sub sp, 0x4
	mov r0, sp
	bl sub_80144A4
	cmp r0, 0
	bne _0803183C
	ldr r2, [sp]
	cmp r2, 0x5
	bhi _0803183C
	lsls r0, r2, 2
	ldr r1, _080317F8
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080317F8: .4byte _080317FC
	.align 2, 0
_080317FC:
	.4byte _08031830
	.4byte _08031830
	.4byte _08031830
	.4byte _0803181C
	.4byte _08031814
	.4byte _08031814
_08031814:
	movs r0, 0
	bl sub_80317C0
	b _0803183C
_0803181C:
	ldr r0, _0803182C
	ldr r0, [r0]
	str r2, [r0, 0x4]
	movs r0, 0x4
	bl sub_80317C0
	b _0803183C
	.align 2, 0
_0803182C: .4byte gUnknown_203B32C
_08031830:
	ldr r0, _08031844
	ldr r0, [r0]
	str r2, [r0, 0x4]
	movs r0, 0x3
	bl sub_80317C0
_0803183C:
	add sp, 0x4
	pop {r0}
	bx r0
	.align 2, 0
_08031844: .4byte gUnknown_203B32C
	thumb_func_end sub_80317D8

	thumb_func_start sub_8031848
sub_8031848:
	push {lr}
	sub sp, 0x4
	mov r0, sp
	bl sub_80144A4
	cmp r0, 0
	bne _0803185C
	movs r0, 0x2
	bl sub_80317C0
_0803185C:
	add sp, 0x4
	pop {r0}
	bx r0
	thumb_func_end sub_8031848

	thumb_func_start sub_8031864
sub_8031864:
	push {lr}
	sub sp, 0x4
	mov r0, sp
	bl sub_80144A4
	cmp r0, 0
	bne _080318C4
	ldr r0, [sp]
	subs r1, r0, 0x5
	adds r2, r0, 0
	cmp r1, 0x4
	bhi _080318C4
	lsls r0, r1, 2
	ldr r1, _08031888
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08031888: .4byte _0803188C
	.align 2, 0
_0803188C:
	.4byte _080318A0
	.4byte _080318B8
	.4byte _080318A8
	.4byte _080318B0
	.4byte _080318B8
_080318A0:
	movs r0, 0x2
	bl sub_80317C0
	b _080318C4
_080318A8:
	movs r0, 0x6
	bl sub_80317C0
	b _080318C4
_080318B0:
	movs r0, 0x8
	bl sub_80317C0
	b _080318C4
_080318B8:
	ldr r0, _080318CC
	ldr r0, [r0]
	str r2, [r0, 0x4]
	movs r0, 0x5
	bl sub_80317C0
_080318C4:
	add sp, 0x4
	pop {r0}
	bx r0
	.align 2, 0
_080318CC: .4byte gUnknown_203B32C
	thumb_func_end sub_8031864

	thumb_func_start sub_80318D0
sub_80318D0:
	push {lr}
	sub sp, 0x4
	mov r0, sp
	bl sub_80144A4
	cmp r0, 0
	bne _080318E4
	movs r0, 0x4
	bl sub_80317C0
_080318E4:
	add sp, 0x4
	pop {r0}
	bx r0
	thumb_func_end sub_80318D0

	thumb_func_start sub_80318EC
sub_80318EC:
	push {lr}
	sub sp, 0x4
	mov r0, sp
	bl sub_80144A4
	cmp r0, 0
	bne _08031920
	ldr r1, [sp]
	cmp r1, 0x5
	bne _08031908
	movs r0, 0x4
	bl sub_80317C0
	b _08031920
_08031908:
	cmp r1, 0x5
	blt _08031920
	cmp r1, 0xE
	bgt _08031920
	cmp r1, 0xA
	blt _08031920
	ldr r0, _08031928
	ldr r0, [r0]
	str r1, [r0, 0x4]
	movs r0, 0x7
	bl sub_80317C0
_08031920:
	add sp, 0x4
	pop {r0}
	bx r0
	.align 2, 0
_08031928: .4byte gUnknown_203B32C
	thumb_func_end sub_80318EC

	thumb_func_start sub_803192C
sub_803192C:
	push {lr}
	sub sp, 0x4
	mov r0, sp
	bl sub_80144A4
	cmp r0, 0
	bne _08031940
	movs r0, 0x6
	bl sub_80317C0
_08031940:
	add sp, 0x4
	pop {r0}
	bx r0
	thumb_func_end sub_803192C

	thumb_func_start sub_8031948
sub_8031948:
	push {lr}
	sub sp, 0x4
	mov r0, sp
	bl sub_80144A4
	cmp r0, 0
	bne _0803197C
	ldr r1, [sp]
	cmp r1, 0x5
	bne _08031964
	movs r0, 0x4
	bl sub_80317C0
	b _0803197C
_08031964:
	cmp r1, 0x5
	blt _0803197C
	cmp r1, 0x12
	bgt _0803197C
	cmp r1, 0xF
	blt _0803197C
	ldr r0, _08031984
	ldr r0, [r0]
	str r1, [r0, 0x4]
	movs r0, 0x9
	bl sub_80317C0
_0803197C:
	add sp, 0x4
	pop {r0}
	bx r0
	.align 2, 0
_08031984: .4byte gUnknown_203B32C
	thumb_func_end sub_8031948

	thumb_func_start sub_8031988
sub_8031988:
	push {lr}
	sub sp, 0x4
	mov r0, sp
	bl sub_80144A4
	cmp r0, 0
	bne _0803199C
	movs r0, 0x8
	bl sub_80317C0
_0803199C:
	add sp, 0x4
	pop {r0}
	bx r0
	thumb_func_end sub_8031988

	thumb_func_start sub_80319A4
sub_80319A4:
	push {r4-r6,lr}
	mov r6, r8
	push {r6}
	adds r4, r0, 0
	adds r5, r1, 0
	mov r8, r2
	lsls r4, 24
	lsrs r4, 24
	lsls r5, 24
	lsrs r5, 24
	ldr r6, _080319F4
	movs r0, 0x78
	movs r1, 0x8
	bl MemoryAlloc
	str r0, [r6]
	strb r4, [r0, 0xC]
	ldr r0, [r6]
	strb r5, [r0, 0xD]
	ldr r0, [r6]
	bl sub_801317C
	ldr r1, [r6]
	mov r0, r8
	str r0, [r1, 0x10]
	lsls r0, 1
	add r0, r8
	lsls r0, 3
	adds r0, 0x18
	adds r0, r1, r0
	str r0, [r1, 0x14]
	bl sub_8031A2C
	movs r0, 0x1
	pop {r3}
	mov r8, r3
	pop {r4-r6}
	pop {r1}
	bx r1
	.align 2, 0
_080319F4: .4byte gUnknown_203B330
	thumb_func_end sub_80319A4

	thumb_func_start sub_80319F8
sub_80319F8:
	push {lr}
	ldr r0, _08031A18
	ldr r0, [r0]
	ldr r1, [r0, 0x10]
	bl sub_8012A64
	cmp r0, 0x1
	beq _08031A1C
	cmp r0, 0x2
	bne _08031A26
	movs r0, 0x1
	bl sub_80119D4
	movs r0, 0x2
	b _08031A28
	.align 2, 0
_08031A18: .4byte gUnknown_203B330
_08031A1C:
	movs r0, 0
	bl sub_80119D4
	movs r0, 0x3
	b _08031A28
_08031A26:
	movs r0, 0
_08031A28:
	pop {r1}
	bx r1
	thumb_func_end sub_80319F8

	thumb_func_start sub_8031A2C
sub_8031A2C:
	push {lr}
	bl sub_8031A84
	bl sub_8031AE8
	pop {r0}
	bx r0
	thumb_func_end sub_8031A2C

	thumb_func_start sub_8031A3C
sub_8031A3C:
	push {r4,r5,lr}
	ldr r4, _08031A7C
	ldr r2, [r4]
	cmp r2, 0
	beq _08031A76
	ldr r0, [r2, 0x10]
	lsls r1, r0, 1
	adds r1, r0
	lsls r1, 3
	adds r1, r2, r1
	adds r1, 0x18
	ldr r0, _08031A80
	ldm r0!, {r2,r3,r5}
	stm r1!, {r2,r3,r5}
	ldm r0!, {r2,r3,r5}
	stm r1!, {r2,r3,r5}
	bl ResetUnusedInputStruct
	ldr r0, [r4]
	adds r0, 0x18
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	ldr r0, [r4]
	bl MemoryFree
	movs r0, 0
	str r0, [r4]
_08031A76:
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_08031A7C: .4byte gUnknown_203B330
_08031A80: .4byte gUnknown_80E1EFC
	thumb_func_end sub_8031A3C

	thumb_func_start sub_8031A84
sub_8031A84:
	push {r4,r5,lr}
	ldr r4, _08031AE0
	ldr r0, [r4]
	adds r0, 0x18
	bl sub_8006518
	ldr r1, [r4]
	ldr r2, [r1, 0x10]
	lsls r0, r2, 1
	adds r0, r2
	lsls r0, 3
	adds r1, r0
	adds r1, 0x18
	ldr r0, _08031AE4
	ldm r0!, {r2,r3,r5}
	stm r1!, {r2,r3,r5}
	ldm r0!, {r2,r3,r5}
	stm r1!, {r2,r3,r5}
	ldr r1, [r4]
	ldrb r0, [r1, 0xC]
	cmp r0, 0x2
	bne _08031AC6
	ldrb r0, [r1, 0xD]
	bl sub_80969D0
	adds r1, r0, 0
	cmp r1, 0
	bne _08031ABE
	movs r1, 0x1
_08031ABE:
	ldr r0, [r4]
	ldr r0, [r0, 0x14]
	bl sub_8012D08
_08031AC6:
	bl ResetUnusedInputStruct
	ldr r0, _08031AE0
	ldr r0, [r0]
	adds r0, 0x18
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_08031AE0: .4byte gUnknown_203B330
_08031AE4: .4byte gUnknown_80E1F18
	thumb_func_end sub_8031A84

	thumb_func_start sub_8031AE8
sub_8031AE8:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0xDC
	ldr r7, _08031B24
	ldr r0, [r7]
	ldr r0, [r0, 0x10]
	bl sub_80073B8
	ldr r2, _08031B28
	ldr r0, [r7]
	ldr r3, [r0, 0x10]
	movs r6, 0
	str r6, [sp]
	movs r0, 0xA
	movs r1, 0
	bl xxx_call_draw_string
	ldr r1, [r7]
	ldrb r0, [r1, 0xC]
	cmp r0, 0x1
	beq _08031B2C
	cmp r0, 0x1
	bgt _08031B1E
	b _08031CD4
_08031B1E:
	cmp r0, 0x2
	beq _08031B94
	b _08031CD4
	.align 2, 0
_08031B24: .4byte gUnknown_203B330
_08031B28: .4byte gUnknown_80E1F30
_08031B2C:
	add r4, sp, 0x68
	adds r0, r4, 0
	bl sub_8099394
	ldrb r0, [r4]
	bl sub_8095228
	adds r5, r0, 0
	ldr r0, [r7]
	ldr r3, [r0, 0x10]
	movs r0, 0xA
	movs r1, 0x10
	movs r2, 0x3
	bl sub_803B6B0
	ldr r1, _08031B8C
	ldrb r2, [r5, 0x5]
	add r0, sp, 0x4
	bl sub_800D158
	ldr r0, [r7]
	ldr r3, [r0, 0x10]
	str r6, [sp]
	movs r0, 0x15
	movs r1, 0x10
	add r2, sp, 0x4
	bl xxx_call_draw_string
	ldr r4, _08031B90
	movs r1, 0xC
	ldrsh r0, [r5, r1]
	bl GetMonSpecies
	adds r2, r0, 0
	add r0, sp, 0x4
	adds r1, r4, 0
	bl sub_800D158
	ldr r0, [r7]
	ldr r3, [r0, 0x10]
	str r6, [sp]
	movs r0, 0x28
	movs r1, 0x10
	add r2, sp, 0x4
	bl xxx_call_draw_string
	b _08031D4E
	.align 2, 0
_08031B8C: .4byte gUnknown_80E1F3C
_08031B90: .4byte gUnknown_80E1F40
_08031B94:
	ldrb r0, [r1, 0xD]
	bl sub_80969D0
	adds r1, r0, 0
	cmp r1, 0
	bne _08031BB0
	ldr r2, _08031BAC
	ldr r0, [r7]
	ldr r3, [r0, 0x10]
	str r1, [sp]
	b _08031D2C
	.align 2, 0
_08031BAC: .4byte gUnknown_80E1F54
_08031BB0:
	movs r6, 0x10
	movs r2, 0
	mov r10, r2
	mov r8, r2
	ldr r0, _08031C28
	mov r9, r0
	mov r1, sp
	adds r1, 0x6C
	str r1, [sp, 0xD8]
_08031BC2:
	mov r2, r10
	lsls r0, r2, 24
	lsrs r0, 24
	bl sub_8096AB4
	adds r4, r0, 0
	ldr r1, [r7]
	ldrb r0, [r4, 0x4]
	ldrb r2, [r1, 0xD]
	cmp r0, r2
	bne _08031CC2
	ldrb r0, [r4]
	cmp r0, 0
	beq _08031CC2
	cmp r0, 0x5
	beq _08031CC2
	cmp r0, 0x7
	beq _08031CC2
	ldr r3, [r1, 0x10]
	movs r0, 0xA
	adds r1, r6, 0
	movs r2, 0x3
	bl sub_803B6B0
	ldrb r0, [r4, 0x1]
	add r5, sp, 0x6C
	cmp r0, 0x3
	beq _08031C16
	ldrb r2, [r4, 0x5]
	ldr r0, [sp, 0xD8]
	ldr r1, _08031C2C
	bl sub_800D158
	ldr r0, [r7]
	ldr r3, [r0, 0x10]
	mov r0, r8
	str r0, [sp]
	movs r0, 0x15
	adds r1, r6, 0
	ldr r2, [sp, 0xD8]
	bl xxx_call_draw_string
_08031C16:
	ldrb r0, [r4, 0x1]
	cmp r0, 0x3
	beq _08031C58
	cmp r0, 0x3
	bgt _08031C30
	cmp r0, 0x2
	beq _08031C70
	b _08031C9C
	.align 2, 0
_08031C28: .4byte gUnknown_202DE58
_08031C2C: .4byte gUnknown_80E1F3C
_08031C30:
	cmp r0, 0x4
	bne _08031C9C
	ldrb r1, [r4, 0x10]
	mov r0, r9
	movs r2, 0
	bl sub_8090DC4
	adds r0, r5, 0
	ldr r1, _08031C54
	mov r2, r9
	bl sub_800D158
	ldr r0, [r7]
	ldr r3, [r0, 0x10]
	mov r1, r8
	str r1, [sp]
	b _08031C8A
	.align 2, 0
_08031C54: .4byte gUnknown_80E1F60
_08031C58:
	ldrb r1, [r4, 0x10]
	mov r0, r9
	movs r2, 0
	bl sub_8090DC4
	adds r0, r5, 0
	ldr r1, _08031C6C
	mov r2, r9
	b _08031C7E
	.align 2, 0
_08031C6C: .4byte gUnknown_80E1F70
_08031C70:
	movs r1, 0xE
	ldrsh r0, [r4, r1]
	bl GetMonSpecies
	adds r2, r0, 0
	adds r0, r5, 0
	ldr r1, _08031C98
_08031C7E:
	bl sub_800D158
	ldr r0, [r7]
	ldr r3, [r0, 0x10]
	mov r2, r8
	str r2, [sp]
_08031C8A:
	movs r0, 0x28
	adds r1, r6, 0
	adds r2, r5, 0
	bl xxx_call_draw_string
	b _08031CC0
	.align 2, 0
_08031C98: .4byte gUnknown_80E1F80
_08031C9C:
	movs r1, 0xE
	ldrsh r0, [r4, r1]
	bl GetMonSpecies
	adds r2, r0, 0
	adds r0, r5, 0
	ldr r1, _08031CD0
	bl sub_800D158
	ldr r0, [r7]
	ldr r3, [r0, 0x10]
	mov r2, r8
	str r2, [sp]
	movs r0, 0x28
	adds r1, r6, 0
	adds r2, r5, 0
	bl xxx_call_draw_string
_08031CC0:
	adds r6, 0xC
_08031CC2:
	movs r0, 0x1
	add r10, r0
	mov r1, r10
	cmp r1, 0x7
	bgt _08031CCE
	b _08031BC2
_08031CCE:
	b _08031D4E
	.align 2, 0
_08031CD0: .4byte gUnknown_80E1F40
_08031CD4:
	add r0, sp, 0xD0
	mov r4, sp
	adds r4, 0xD2
	adds r1, r4, 0
	bl sub_80992E0
	lsls r0, 24
	lsrs r5, r0, 24
	cmp r5, 0
	beq _08031D04
	movs r2, 0
	ldrsh r0, [r4, r2]
	bl sub_80974C4
	adds r2, r0, 0
	ldr r0, _08031D00
	ldr r0, [r0]
	ldr r3, [r0, 0x10]
	movs r0, 0
	str r0, [sp]
	b _08031D2C
	.align 2, 0
_08031D00: .4byte gUnknown_203B330
_08031D04:
	add r4, sp, 0xD4
	adds r0, r4, 0
	bl sub_8099360
	lsls r0, 24
	lsrs r1, r0, 24
	cmp r1, 0
	beq _08031D3C
	ldrb r0, [r4]
	bl sub_80A2688
	lsls r0, 16
	asrs r0, 16
	bl sub_80975DC
	adds r2, r0, 0
	ldr r0, _08031D38
	ldr r0, [r0]
	ldr r3, [r0, 0x10]
	str r5, [sp]
_08031D2C:
	movs r0, 0xA
	movs r1, 0x10
	bl xxx_call_draw_string
	b _08031D4E
	.align 2, 0
_08031D38: .4byte gUnknown_203B330
_08031D3C:
	ldr r2, _08031D68
	ldr r0, _08031D6C
	ldr r0, [r0]
	ldr r3, [r0, 0x10]
	str r1, [sp]
	movs r0, 0xA
	movs r1, 0x10
	bl xxx_call_draw_string
_08031D4E:
	ldr r0, _08031D6C
	ldr r0, [r0]
	ldr r0, [r0, 0x10]
	bl sub_80073E0
	add sp, 0xDC
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_08031D68: .4byte gUnknown_80E1F94
_08031D6C: .4byte gUnknown_203B330
	thumb_func_end sub_8031AE8

	thumb_func_start sub_8031D70
sub_8031D70:
	push {r4-r6,lr}
	adds r6, r0, 0
	adds r4, r1, 0
	ldr r5, _08031DC4
	movs r0, 0x7C
	movs r1, 0x8
	bl MemoryAlloc
	str r0, [r5]
	stm r0!, {r6}
	bl sub_801317C
	ldr r0, [r5]
	str r4, [r0, 0x10]
	lsls r1, r4, 1
	adds r1, r4
	lsls r1, 3
	adds r1, 0x18
	adds r1, r0, r1
	str r1, [r0, 0x14]
	adds r0, 0x18
	bl sub_8006518
	ldr r1, [r5]
	ldr r2, [r1, 0x10]
	lsls r0, r2, 1
	adds r0, r2
	lsls r0, 3
	adds r1, r0
	adds r1, 0x18
	ldr r0, _08031DC8
	ldm r0!, {r2-r4}
	stm r1!, {r2-r4}
	ldm r0!, {r2-r4}
	stm r1!, {r2-r4}
	bl sub_8031E00
	movs r0, 0x1
	pop {r4-r6}
	pop {r1}
	bx r1
	.align 2, 0
_08031DC4: .4byte gUnknown_203B334
_08031DC8: .4byte gUnknown_80E1FC4
	thumb_func_end sub_8031D70

	thumb_func_start sub_8031DCC
sub_8031DCC:
	push {lr}
	ldr r0, _08031DEC
	ldr r1, [r0]
	adds r0, r1, 0x4
	ldr r1, [r1, 0x10]
	bl sub_8012A64
	cmp r0, 0x1
	beq _08031DF0
	cmp r0, 0x2
	bne _08031DFA
	movs r0, 0x1
	bl sub_80119D4
	movs r0, 0x2
	b _08031DFC
	.align 2, 0
_08031DEC: .4byte gUnknown_203B334
_08031DF0:
	movs r0, 0
	bl sub_80119D4
	movs r0, 0x3
	b _08031DFC
_08031DFA:
	movs r0, 0
_08031DFC:
	pop {r1}
	bx r1
	thumb_func_end sub_8031DCC

	thumb_func_start sub_8031E00
sub_8031E00:
	push {lr}
	bl sub_8031E58
	bl sub_8031E74
	pop {r0}
	bx r0
	thumb_func_end sub_8031E00

	thumb_func_start sub_8031E10
sub_8031E10:
	push {r4,r5,lr}
	ldr r4, _08031E50
	ldr r2, [r4]
	cmp r2, 0
	beq _08031E4A
	ldr r0, [r2, 0x10]
	lsls r1, r0, 1
	adds r1, r0
	lsls r1, 3
	adds r1, r2, r1
	adds r1, 0x18
	ldr r0, _08031E54
	ldm r0!, {r2,r3,r5}
	stm r1!, {r2,r3,r5}
	ldm r0!, {r2,r3,r5}
	stm r1!, {r2,r3,r5}
	bl ResetUnusedInputStruct
	ldr r0, [r4]
	adds r0, 0x18
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	ldr r0, [r4]
	bl MemoryFree
	movs r0, 0
	str r0, [r4]
_08031E4A:
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_08031E50: .4byte gUnknown_203B334
_08031E54: .4byte gUnknown_80E1FA8
	thumb_func_end sub_8031E10

	thumb_func_start sub_8031E58
sub_8031E58:
	push {lr}
	bl ResetUnusedInputStruct
	ldr r0, _08031E70
	ldr r0, [r0]
	adds r0, 0x18
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	pop {r0}
	bx r0
	.align 2, 0
_08031E70: .4byte gUnknown_203B334
	thumb_func_end sub_8031E58

	thumb_func_start sub_8031E74
sub_8031E74:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0x3C
	ldr r3, _08031EC0
	ldr r5, _08031EC4
	ldr r2, [r5]
	ldr r1, [r2]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 4
	ldr r4, [r3]
	adds r4, r0
	ldr r0, [r2, 0x10]
	bl sub_80073B8
	ldr r2, _08031EC8
	ldr r0, [r5]
	ldr r3, [r0, 0x10]
	movs r0, 0
	str r0, [sp]
	movs r0, 0x14
	movs r1, 0
	bl xxx_call_draw_string
	add r0, sp, 0x4
	adds r1, r4, 0
	bl sub_803D2C0
	movs r7, 0
	mov r8, r5
_08031EB2:
	cmp r7, 0x4
	ble _08031ED0
	cmp r7, 0xC
	bgt _08031ECC
	movs r6, 0x6
	movs r5, 0x16
	b _08031F00
	.align 2, 0
_08031EC0: .4byte gUnknown_203B480
_08031EC4: .4byte gUnknown_203B334
_08031EC8: .4byte gUnknown_80E1FDC
_08031ECC:
	cmp r7, 0x11
	bgt _08031ED6
_08031ED0:
	movs r6, 0x7
	movs r5, 0x15
	b _08031F00
_08031ED6:
	cmp r7, 0x16
	ble _08031EE8
	cmp r7, 0x1E
	bgt _08031EE4
	movs r6, 0x6
	movs r5, 0x25
	b _08031F00
_08031EE4:
	cmp r7, 0x23
	bgt _08031EEE
_08031EE8:
	movs r6, 0x7
	movs r5, 0x24
	b _08031F00
_08031EEE:
	cmp r7, 0x28
	ble _08031EFC
	cmp r7, 0x30
	bgt _08031EFC
	movs r6, 0x6
	movs r5, 0x34
	b _08031F00
_08031EFC:
	movs r6, 0x7
	movs r5, 0x33
_08031F00:
	adds r0, r7, 0
	movs r1, 0x12
	bl __modsi3
	movs r1, 0xB
	adds r4, r0, 0
	muls r4, r1
	adds r4, 0x6
	mov r0, sp
	adds r0, r7
	adds r0, 0x4
	ldrb r2, [r0]
	mov r1, r8
	ldr r0, [r1]
	ldr r0, [r0, 0x10]
	str r0, [sp]
	adds r0, r4, 0
	adds r1, r5, 0
	adds r3, r6, 0
	bl sub_8012C60
	mov r1, r8
	ldr r0, [r1]
	ldr r0, [r0, 0x10]
	adds r2, r5, 0
	adds r2, 0xA
	movs r1, 0x5
	str r1, [sp]
	adds r1, r4, 0
	movs r3, 0xA
	bl sub_80078A4
	adds r7, 0x1
	cmp r7, 0x35
	ble _08031EB2
	ldr r0, _08031F5C
	ldr r0, [r0]
	ldr r0, [r0, 0x10]
	bl sub_80073E0
	add sp, 0x3C
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_08031F5C: .4byte gUnknown_203B334
	thumb_func_end sub_8031E74

	thumb_func_start CreateAdventureLogScreen
CreateAdventureLogScreen:
	push {r4-r6,lr}
	adds r5, r0, 0
	ldr r4, _08031FD0
	movs r0, 0xA0
	movs r1, 0x8
	bl MemoryAlloc
	str r0, [r4]
	str r5, [r0, 0x34]
	lsls r1, r5, 1
	adds r1, r5
	lsls r1, 3
	adds r1, 0x3C
	adds r1, r0, r1
	str r1, [r0, 0x38]
	adds r0, 0x3C
	bl sub_8006518
	ldr r1, [r4]
	ldr r2, [r1, 0x34]
	lsls r0, r2, 1
	adds r0, r2
	lsls r0, 3
	adds r1, r0
	adds r1, 0x3C
	ldr r0, _08031FD4
	ldm r0!, {r2,r3,r6}
	stm r1!, {r2,r3,r6}
	ldm r0!, {r2,r3,r6}
	stm r1!, {r2,r3,r6}
	ldr r0, [r4]
	ldr r1, [r0, 0x38]
	adds r0, 0x9C
	str r0, [r1, 0x14]
	bl ResetUnusedInputStruct
	ldr r0, [r4]
	adds r0, 0x3C
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	ldr r0, [r4]
	movs r1, 0x20
	movs r2, 0x8
	adds r3, r5, 0
	bl sub_8013818
	bl sub_8032084
	bl DisplayAdventureLog
	movs r0, 0x1
	pop {r4-r6}
	pop {r1}
	bx r1
	.align 2, 0
_08031FD0: .4byte gUnknown_203B338
_08031FD4: .4byte gUnknown_80E2008
	thumb_func_end CreateAdventureLogScreen

	thumb_func_start sub_8031FD8
sub_8031FD8:
	push {r4,lr}
	lsls r0, 24
	cmp r0, 0
	bne _08031FF0
	ldr r0, _08031FEC
	ldr r0, [r0]
	bl sub_8013660
	movs r0, 0
	b _08032034
	.align 2, 0
_08031FEC: .4byte gUnknown_203B338
_08031FF0:
	ldr r4, _0803200C
	ldr r0, [r4]
	bl GetKeyPress
	cmp r0, 0x1
	beq _08032010
	cmp r0, 0x2
	bne _0803201A
	movs r0, 0x1
	bl sub_80119D4
	movs r0, 0x2
	b _08032034
	.align 2, 0
_0803200C: .4byte gUnknown_203B338
_08032010:
	movs r0, 0
	bl sub_80119D4
	movs r0, 0x3
	b _08032034
_0803201A:
	ldr r0, [r4]
	bl sub_8013938
	lsls r0, 24
	cmp r0, 0
	bne _0803202A
	movs r0, 0
	b _08032034
_0803202A:
	bl sub_8032084
	bl DisplayAdventureLog
	movs r0, 0x1
_08032034:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_8031FD8

	thumb_func_start sub_803203C
sub_803203C:
	push {r4,r5,lr}
	ldr r4, _0803207C
	ldr r2, [r4]
	cmp r2, 0
	beq _08032076
	ldr r0, [r2, 0x34]
	lsls r1, r0, 1
	adds r1, r0
	lsls r1, 3
	adds r1, r2, r1
	adds r1, 0x3C
	ldr r0, _08032080
	ldm r0!, {r2,r3,r5}
	stm r1!, {r2,r3,r5}
	ldm r0!, {r2,r3,r5}
	stm r1!, {r2,r3,r5}
	bl ResetUnusedInputStruct
	ldr r0, [r4]
	adds r0, 0x3C
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	ldr r0, [r4]
	bl MemoryFree
	movs r0, 0
	str r0, [r4]
_08032076:
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_0803207C: .4byte gUnknown_203B338
_08032080: .4byte gUnknown_80E1FF0
	thumb_func_end sub_803203C

	thumb_func_start sub_8032084
sub_8032084:
	push {r4,lr}
	ldr r4, _080320F4
	ldr r0, [r4]
	ldrh r1, [r0, 0x20]
	adds r0, 0x9C
	movs r2, 0
	strb r1, [r0]
	ldr r0, [r4]
	ldrh r1, [r0, 0x1E]
	adds r0, 0x9D
	strb r1, [r0]
	ldr r0, [r4]
	adds r0, 0x9E
	movs r1, 0xB
	strb r1, [r0]
	ldr r0, [r4]
	adds r0, 0x9F
	strb r2, [r0]
	ldr r0, [r4]
	movs r1, 0x1A
	ldrsh r0, [r0, r1]
	movs r1, 0xC
	bl sub_80095E4
	adds r0, 0x2
	lsls r0, 16
	ldr r2, [r4]
	ldr r3, [r2, 0x34]
	lsls r1, r3, 1
	adds r1, r3
	lsls r1, 3
	adds r1, r2, r1
	adds r1, 0x4A
	asrs r3, r0, 16
	lsrs r0, 16
	strh r0, [r1]
	ldr r1, [r2, 0x34]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 3
	adds r2, r0
	adds r3, 0x2
	adds r2, 0x4C
	strh r3, [r2]
	bl ResetUnusedInputStruct
	ldr r0, [r4]
	adds r0, 0x3C
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080320F4: .4byte gUnknown_203B338
	thumb_func_end sub_8032084

	thumb_func_start DisplayAdventureLog
DisplayAdventureLog:
	push {r4-r7,lr}
	sub sp, 0x8
	ldr r5, _08032158
	ldr r0, [r5]
	ldr r0, [r0, 0x34]
	bl sub_8008C54
	ldr r0, [r5]
	ldr r0, [r0, 0x34]
	bl sub_80073B8
	ldr r0, [r5]
	movs r1, 0x1E
	ldrsh r4, [r0, r1]
	lsls r4, 3
	adds r6, r4, 0
	adds r6, 0xA
	ldr r2, _0803215C
	ldr r3, [r0, 0x34]
	movs r0, 0
	str r0, [sp]
	adds r0, r6, 0
	movs r1, 0
	bl xxx_call_draw_string
	adds r4, 0x4
	ldr r1, [r5]
	adds r0, r1, 0
	adds r0, 0x9E
	ldrb r0, [r0]
	lsls r0, 3
	adds r6, r4, r0
	movs r0, 0x1E
	ldrsh r2, [r1, r0]
	adds r2, 0x1
	movs r0, 0x7
	str r0, [sp]
	ldr r0, [r1, 0x34]
	str r0, [sp, 0x4]
	adds r0, r6, 0
	movs r1, 0
	movs r3, 0x1
	bl sub_8012BC4
	movs r7, 0
	ldr r0, [r5]
	b _0803223A
	.align 2, 0
_08032158: .4byte gUnknown_203B338
_0803215C: .4byte gUnknown_80E2020
_08032160:
	ldr r5, _08032194
	ldr r0, [r5]
	movs r2, 0x1E
	ldrsh r1, [r0, r2]
	movs r2, 0x1C
	ldrsh r0, [r0, r2]
	muls r0, r1
	adds r0, r7
	lsls r0, 24
	lsrs r6, r0, 24
	adds r0, r6, 0
	bl sub_8097710
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0
	beq _0803221C
	subs r0, r6, 0x7
	cmp r0, 0x5
	bhi _080321EC
	lsls r0, 2
	ldr r1, _08032198
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08032194: .4byte gUnknown_203B338
_08032198: .4byte _0803219C
	.align 2, 0
_0803219C:
	.4byte _080321BA
	.4byte _080321C6
	.4byte _080321D4
	.4byte _080321E0
	.4byte _080321C0
	.4byte _080321B4
_080321B4:
	bl sub_80978B8
	b _080321E4
_080321BA:
	bl sub_8097880
	b _080321E4
_080321C0:
	bl sub_8097838
	b _080321E4
_080321C6:
	bl sub_80977B8
	ldr r1, _080321D0
	b _080321EA
	.align 2, 0
_080321D0: .4byte gUnknown_202DE30
_080321D4:
	bl sub_80977F8
	ldr r1, _080321DC
	b _080321EA
	.align 2, 0
_080321DC: .4byte gUnknown_202DE30
_080321E0:
	bl sub_8097870
_080321E4:
	ldr r1, _08032214
	lsls r0, 16
	asrs r0, 16
_080321EA:
	str r0, [r1]
_080321EC:
	ldr r4, _08032218
	ldr r0, [r4]
	adds r1, r7, 0
	bl sub_8013800
	adds r5, r0, 0
	adds r0, r6, 0
	bl GetAdventureLogLine
	adds r2, r0, 0
	ldr r0, [r4]
	ldr r3, [r0, 0x34]
	movs r0, 0
	str r0, [sp]
	movs r0, 0x8
	adds r1, r5, 0
	bl sub_8014FF0
	b _08032234
	.align 2, 0
_08032214: .4byte gUnknown_202DE30
_08032218: .4byte gUnknown_203B338
_0803221C:
	ldr r0, [r5]
	adds r1, r7, 0
	bl sub_8013800
	adds r1, r0, 0
	ldr r2, _08032254
	ldr r0, [r5]
	ldr r3, [r0, 0x34]
	str r4, [sp]
	movs r0, 0x8
	bl xxx_call_draw_string
_08032234:
	adds r7, 0x1
	ldr r0, _08032258
	ldr r0, [r0]
_0803223A:
	movs r1, 0x1A
	ldrsh r0, [r0, r1]
	cmp r7, r0
	blt _08032160
	ldr r0, _08032258
	ldr r0, [r0]
	ldr r0, [r0, 0x34]
	bl sub_80073E0
	add sp, 0x8
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_08032254: .4byte gUnknown_80E2030
_08032258: .4byte gUnknown_203B338
	thumb_func_end DisplayAdventureLog

	thumb_func_start sub_803225C
sub_803225C:
	push {r4,r5,lr}
	bl ResetUnusedInputStruct
	movs r0, 0
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	ldr r5, _08032300
	movs r4, 0xAD
	lsls r4, 3
	adds r0, r4, 0
	movs r1, 0x8
	bl MemoryAlloc
	str r0, [r5]
	movs r1, 0
	adds r2, r4, 0
	bl MemoryFill8
	ldr r1, [r5]
	movs r0, 0xA6
	lsls r0, 3
	adds r2, r1, r0
	movs r0, 0
	str r0, [r2]
	movs r2, 0x86
	lsls r2, 2
	adds r1, r2
	movs r0, 0xFF
	strb r0, [r1]
	ldr r0, [r5]
	movs r1, 0xA7
	lsls r1, 3
	adds r0, r1
	ldr r1, _08032304
	strh r1, [r0]
	ldr r0, _08032308
	movs r4, 0x98
	lsls r4, 1
	adds r1, r4, 0
	bl sub_808D8E0
	adds r0, r4, 0
	bl GetMonSpecies
	adds r1, r0, 0
	ldr r0, _0803230C
	bl strcpy
	movs r1, 0
	movs r2, 0
	adds r4, r5, 0
_080322C6:
	ldr r0, [r5]
	adds r0, 0x8
	adds r0, r1
	strb r2, [r0]
	adds r1, 0x1
	cmp r1, 0x35
	ble _080322C6
	ldr r1, [r4]
	movs r0, 0x7E
	str r0, [r1, 0x4]
	bl sub_8039880
	ldr r1, [r4]
	ldr r2, _08032310
	adds r1, r2
	strb r0, [r1]
	ldr r0, [r4]
	adds r2, r0, r2
	ldrb r1, [r2]
	ldr r2, _08032314
	adds r0, r2
	strb r1, [r0]
	movs r0, 0
	bl sub_80338C4
	movs r0, 0x1
	pop {r4,r5}
	pop {r1}
	bx r1
	.align 2, 0
_08032300: .4byte gUnknown_203B33C
_08032304: .4byte 0x0000ffff
_08032308: .4byte gUnknown_202E5D8
_0803230C: .4byte gAvailablePokemonNames
_08032310: .4byte 0x0000052c
_08032314: .4byte 0x0000052d
	thumb_func_end sub_803225C

	thumb_func_start sub_8032318
sub_8032318:
	push {lr}
	ldr r0, _08032330
	ldr r0, [r0]
	ldr r0, [r0]
	cmp r0, 0x7D
	bls _08032326
	b _080327DC
_08032326:
	lsls r0, 2
	ldr r1, _08032334
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08032330: .4byte gUnknown_203B33C
_08032334: .4byte _08032338
	.align 2, 0
_08032338:
	.4byte _080326A6
	.4byte _080326A6
	.4byte _080326AC
	.4byte _0803255A
	.4byte _0803255A
	.4byte _0803266C
	.4byte _08032672
	.4byte _08032678
	.4byte _0803267E
	.4byte _08032684
	.4byte _0803268A
	.4byte _08032690
	.4byte _08032690
	.4byte _08032698
	.4byte _080326A0
	.4byte _080327CE
	.4byte _080327CE
	.4byte _0803262C
	.4byte _08032634
	.4byte _0803263A
	.4byte _08032640
	.4byte _08032646
	.4byte _0803264C
	.4byte _08032652
	.4byte _08032764
	.4byte _08032658
	.4byte _08032660
	.4byte _08032666
	.4byte _08032612
	.4byte _08032626
	.4byte _0803261A
	.4byte _08032620
	.4byte _0803260C
	.4byte _080325CE
	.4byte _080327CE
	.4byte _080325C6
	.4byte _080325BA
	.4byte _080325A0
	.4byte _080325A8
	.4byte _080325AE
	.4byte _080325B4
	.4byte _080325C0
	.4byte _0803258C
	.4byte _0803259A
	.4byte _08032594
	.4byte _0803257E
	.4byte _08032586
	.4byte _08032764
	.4byte _080327CE
	.4byte _080325D4
	.4byte _080325DC
	.4byte _080325E2
	.4byte _080325E8
	.4byte _080325EE
	.4byte _080327DC
	.4byte _080325FA
	.4byte _080325F4
	.4byte _08032600
	.4byte _08032606
	.4byte _08032764
	.4byte _080327CE
	.4byte _08032560
	.4byte _08032566
	.4byte _0803256C
	.4byte _08032572
	.4byte _08032578
	.4byte _08032764
	.4byte _08032658
	.4byte _080327CE
	.4byte _080327CE
	.4byte _08032794
	.4byte _0803279C
	.4byte _080327A2
	.4byte _080327A8
	.4byte _080327AE
	.4byte _080327B4
	.4byte _080327BA
	.4byte _080327C0
	.4byte _080327C0
	.4byte _080327C8
	.4byte _08032722
	.4byte _080327D6
	.4byte _0803278E
	.4byte _08032780
	.4byte _08032788
	.4byte _0803277A
	.4byte _08032774
	.4byte _0803276C
	.4byte _08032752
	.4byte _08032764
	.4byte _080326BC
	.4byte _080326C2
	.4byte _080326D6
	.4byte _080326CA
	.4byte _080326D0
	.4byte _080326DC
	.4byte _080326E2
	.4byte _080326E8
	.4byte _08032730
	.4byte _08032744
	.4byte _0803273E
	.4byte _08032738
	.4byte _080326F4
	.4byte _080326FC
	.4byte _080326EE
	.4byte _0803274C
	.4byte _080326B0
	.4byte _080326B6
	.4byte _08032764
	.4byte _08032722
	.4byte _0803272A
	.4byte _08032744
	.4byte _0803271C
	.4byte _08032716
	.4byte _08032708
	.4byte _08032710
	.4byte _08032702
	.4byte _08032758
	.4byte _0803275E
	.4byte _08032764
	.4byte _08032530
	.4byte _08032536
	.4byte _0803253E
	.4byte _08032544
	.4byte _0803254C
	.4byte _08032552
_08032530:
	bl sub_8035300
	b _080327DC
_08032536:
	movs r0, 0x78
	bl sub_8035404
	b _080327DC
_0803253E:
	bl sub_8035374
	b _080327DC
_08032544:
	movs r0, 0x7A
	bl sub_8035404
	b _080327DC
_0803254C:
	bl sub_80353BC
	b _080327DC
_08032552:
	movs r0, 0x7C
	bl sub_8035404
	b _080327DC
_0803255A:
	bl sub_8033A2C
	b _080327DC
_08032560:
	bl sub_803477C
	b _080327DC
_08032566:
	bl sub_80347AC
	b _080327DC
_0803256C:
	bl sub_80347C8
	b _080327DC
_08032572:
	bl sub_80347E4
	b _080327DC
_08032578:
	bl sub_8034804
	b _080327DC
_0803257E:
	movs r0, 0x2E
	bl sub_8035404
	b _080327DC
_08032586:
	bl sub_80344C0
	b _080327DC
_0803258C:
	movs r0, 0xD
	bl sub_8035404
	b _080327DC
_08032594:
	bl sub_8034478
	b _080327DC
_0803259A:
	bl sub_80344A0
	b _080327DC
_080325A0:
	movs r0, 0x26
	bl sub_8035404
	b _080327DC
_080325A8:
	bl sub_803418C
	b _080327DC
_080325AE:
	bl sub_8034254
	b _080327DC
_080325B4:
	bl sub_8034310
	b _080327DC
_080325BA:
	bl sub_8034378
	b _080327DC
_080325C0:
	bl sub_80343C4
	b _080327DC
_080325C6:
	movs r0, 0x21
	bl sub_8035404
	b _080327DC
_080325CE:
	bl sub_8034404
	b _080327DC
_080325D4:
	movs r0, 0x32
	bl sub_8035404
	b _080327DC
_080325DC:
	bl sub_8034500
	b _080327DC
_080325E2:
	bl sub_8034590
	b _080327DC
_080325E8:
	bl sub_803464C
	b _080327DC
_080325EE:
	bl sub_80346A8
	b _080327DC
_080325F4:
	bl sub_80346D8
	b _080327DC
_080325FA:
	bl sub_8034700
	b _080327DC
_08032600:
	bl sub_8034720
	b _080327DC
_08032606:
	bl sub_803473C
	b _080327DC
_0803260C:
	bl sub_8033FB4
	b _080327DC
_08032612:
	movs r0, 0x1D
	bl sub_8035404
	b _080327DC
_0803261A:
	bl sub_8034074
	b _080327DC
_08032620:
	bl sub_8034130
	b _080327DC
_08032626:
	bl sub_8033FE4
	b _080327DC
_0803262C:
	movs r0, 0x12
	bl sub_8035404
	b _080327DC
_08032634:
	bl nullsub_42
	b _080327DC
_0803263A:
	bl nullsub_43
	b _080327DC
_08032640:
	bl nullsub_44
	b _080327DC
_08032646:
	bl nullsub_45
	b _080327DC
_0803264C:
	bl sub_8033D74
	b _080327DC
_08032652:
	bl sub_8033D94
	b _080327DC
_08032658:
	movs r0, 0x1A
	bl sub_8035404
	b _080327DC
_08032660:
	bl sub_8033DBC
	b _080327DC
_08032666:
	bl sub_8033F64
	b _080327DC
_0803266C:
	bl sub_8033C54
	b _080327DC
_08032672:
	bl nullsub_41
	b _080327DC
_08032678:
	bl sub_8033CAC
	b _080327DC
_0803267E:
	bl sub_8033D48
	b _080327DC
_08032684:
	bl sub_8035424
	b _080327DC
_0803268A:
	bl nullsub_50
	b _080327DC
_08032690:
	movs r0, 0x6
	bl sub_8035404
	b _080327DC
_08032698:
	movs r0, 0x7
	bl sub_8035404
	b _080327DC
_080326A0:
	bl sub_8033B8C
	b _080327DC
_080326A6:
	bl sub_80339C8
	b _080327DC
_080326AC:
	movs r0, 0x3
	b _080327DE
_080326B0:
	bl sub_80348C4
	b _080327DC
_080326B6:
	bl sub_803482C
	b _080327DC
_080326BC:
	bl sub_80349B0
	b _080327DC
_080326C2:
	movs r0, 0x5C
	bl sub_8035404
	b _080327DC
_080326CA:
	bl sub_8034A70
	b _080327DC
_080326D0:
	bl sub_8034B2C
	b _080327DC
_080326D6:
	bl sub_80349E0
	b _080327DC
_080326DC:
	bl sub_8034B88
	b _080327DC
_080326E2:
	bl sub_8034C98
	b _080327DC
_080326E8:
	bl sub_8034C38
	b _080327DC
_080326EE:
	bl sub_8034D54
	b _080327DC
_080326F4:
	movs r0, 0x67
	bl sub_8035404
	b _080327DC
_080326FC:
	bl sub_8034970
	b _080327DC
_08032702:
	bl sub_80351E0
	b _080327DC
_08032708:
	movs r0, 0x73
	bl sub_8035404
	b _080327DC
_08032710:
	bl sub_8034D74
	b _080327DC
_08032716:
	bl sub_8034EF0
	b _080327DC
_0803271C:
	bl sub_8034F38
	b _080327DC
_08032722:
	movs r0, 0x6E
	bl sub_8035404
	b _080327DC
_0803272A:
	bl sub_80352A4
	b _080327DC
_08032730:
	movs r0, 0x6A
	bl sub_8035404
	b _080327DC
_08032738:
	bl sub_8034EC8
	b _080327DC
_0803273E:
	bl sub_8034F18
	b _080327DC
_08032744:
	movs r0, 0x62
	bl sub_8035404
	b _080327DC
_0803274C:
	bl sub_8034F58
	b _080327DC
_08032752:
	bl sub_8034F88
	b _080327DC
_08032758:
	bl sub_8035018
	b _080327DC
_0803275E:
	bl sub_8035038
	b _080327DC
_08032764:
	movs r0, 0x2
	bl sub_8035404
	b _080327DC
_0803276C:
	movs r0, 0x5F
	bl sub_8035404
	b _080327DC
_08032774:
	bl sub_8035094
	b _080327DC
_0803277A:
	bl sub_80350F4
	b _080327DC
_08032780:
	movs r0, 0x54
	bl sub_8035404
	b _080327DC
_08032788:
	bl sub_803517C
	b _080327DC
_0803278E:
	bl sub_8035210
	b _080327DC
_08032794:
	movs r0, 0x47
	bl sub_8035404
	b _080327DC
_0803279C:
	bl nullsub_46
	b _080327DC
_080327A2:
	bl nullsub_47
	b _080327DC
_080327A8:
	bl nullsub_48
	b _080327DC
_080327AE:
	bl nullsub_49
	b _080327DC
_080327B4:
	bl sub_8035430
	b _080327DC
_080327BA:
	bl nullsub_51
	b _080327DC
_080327C0:
	movs r0, 0x4F
	bl sub_8035404
	b _080327DC
_080327C8:
	bl sub_8034848
	b _080327DC
_080327CE:
	movs r0, 0x1
	bl sub_8035404
	b _080327DC
_080327D6:
	movs r0, 0x1
	bl sub_8035404
_080327DC:
	movs r0, 0
_080327DE:
	pop {r1}
	bx r1
	thumb_func_end sub_8032318

	thumb_func_start sub_80327E4
sub_80327E4:
	push {r4,lr}
	ldr r4, _08032820
	ldr r0, [r4]
	cmp r0, 0
	beq _0803281A
	bl MemoryFree
	movs r0, 0
	str r0, [r4]
	bl sub_803084C
	bl sub_8031E10
	bl sub_8023C60
	bl sub_80155F0
	bl sub_801CBB8
	bl sub_802F2C0
	bl sub_8030DE4
	bl sub_802453C
	bl sub_801B450
_0803281A:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08032820: .4byte gUnknown_203B33C
	thumb_func_end sub_80327E4

	thumb_func_start nullsub_40
nullsub_40:
	bx lr
	thumb_func_end nullsub_40

	thumb_func_start sub_8032828
sub_8032828:
	push {r4-r6,lr}
	sub sp, 0x68
	ldr r1, _08032848
	ldr r0, [r1]
	ldr r0, [r0]
	adds r6, r1, 0
	cmp r0, 0x7D
	bls _0803283C
	bl _080338B4
_0803283C:
	lsls r0, 2
	ldr r1, _0803284C
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08032848: .4byte gUnknown_203B33C
_0803284C: .4byte _08032850
	.align 2, 0
_08032850:
	.4byte _08032A48
	.4byte _08032AD0
	.4byte _080338B4
	.4byte _08032B80
	.4byte _08032BC4
	.4byte _08032FD0
	.4byte _080338B4
	.4byte _08032FF0
	.4byte _080338B4
	.4byte _080338B4
	.4byte _08032FD8
	.4byte _08032FE0
	.4byte _08032FE8
	.4byte _0803356C
	.4byte _08032C50
	.4byte _08033200
	.4byte _080331CC
	.4byte _080331D4
	.4byte _080331DC
	.4byte _080336B2
	.4byte _080338B4
	.4byte _080331F8
	.4byte _08033208
	.4byte _080338B4
	.4byte _08033234
	.4byte _0803323C
	.4byte _08033244
	.4byte _080338B4
	.4byte _08032F8C
	.4byte _08032F98
	.4byte _080336B2
	.4byte _080338B4
	.4byte _08032FB6
	.4byte _08032EB8
	.4byte _08032FC4
	.4byte _08032EAC
	.4byte _08032F54
	.4byte _08032EE0
	.4byte _08032EEC
	.4byte _08032F16
	.4byte _080338B4
	.4byte _08032F7C
	.4byte _08032E60
	.4byte _08032E6C
	.4byte _08032EA0
	.4byte _08032E48
	.4byte _0803341C
	.4byte _08032E54
	.4byte _08032D84
	.4byte _08032D90
	.4byte _08032D9C
	.4byte _080336B2
	.4byte _080338B4
	.4byte _08032DBC
	.4byte _080338B4
	.4byte _08032DCC
	.4byte _08032E00
	.4byte _08032E3C
	.4byte _08032E0C
	.4byte _08032E30
	.4byte _08032D04
	.4byte _08032D10
	.4byte _08032D2C
	.4byte _08032D38
	.4byte _08032D44
	.4byte _080338B4
	.4byte _08032D78
	.4byte _08032D20
	.4byte _08033720
	.4byte _08033728
	.4byte _08033684
	.4byte _0803368C
	.4byte _080336B2
	.4byte _080338B4
	.4byte _080336F8
	.4byte _080338B4
	.4byte _08032FD8
	.4byte _08032FE0
	.4byte _08032FE8
	.4byte _080338B4
	.4byte _08033468
	.4byte _08033730
	.4byte _08033738
	.4byte _0803366C
	.4byte _08033674
	.4byte _08033644
	.4byte _0803361C
	.4byte _08033614
	.4byte _080335F4
	.4byte _080335C0
	.4byte _0803324E
	.4byte _0803325C
	.4byte _0803368C
	.4byte _08033264
	.4byte _080338B4
	.4byte _08033288
	.4byte _080332B8
	.4byte _080338B4
	.4byte _0803356C
	.4byte _080335B0
	.4byte _08033584
	.4byte _080338B4
	.4byte _08033412
	.4byte _0803341C
	.4byte _08033448
	.4byte _080335B8
	.4byte _080332F4
	.4byte _080338B4
	.4byte _08033460
	.4byte _08033470
	.4byte _0803349C
	.4byte _08033450
	.4byte _08033458
	.4byte _080338B4
	.4byte _080333E4
	.4byte _080333EC
	.4byte _080338B4
	.4byte _08033604
	.4byte _0803360C
	.4byte _080338B4
	.4byte _0803384C
	.4byte _0803387C
	.4byte _080337D4
	.4byte _080337F0
	.4byte _08033770
	.4byte _0803378C
_08032A48:
	movs r0, 0x1
	bl sub_8095324
	cmp r0, 0
	bne _08032A9C
	movs r0, 0x5
	bl sub_8095324
	adds r4, r0, 0
	cmp r4, 0
	bne _08032A9C
	ldr r0, _08032A7C
	ldr r0, [r0]
	ldr r1, _08032A80
	adds r0, r1
	ldrb r2, [r0]
	cmp r2, 0
	beq _08032A8C
	ldr r0, _08032A84
	ldr r3, _08032A88
	str r4, [sp]
	movs r1, 0x4
	str r1, [sp, 0x4]
	str r4, [sp, 0x8]
	str r4, [sp, 0xC]
	b _08032B66
	.align 2, 0
_08032A7C: .4byte gUnknown_203B33C
_08032A80: .4byte 0x0000052c
_08032A84: .4byte gUnknown_80E25F4
_08032A88: .4byte gUnknown_80E2108
_08032A8C:
	ldr r0, _08032A94
	ldr r3, _08032A98
	b _08032B5C
	.align 2, 0
_08032A94: .4byte gUnknown_80E25F4
_08032A98: .4byte gUnknown_80E20B8
_08032A9C:
	ldr r0, _08032AC0
	ldr r0, [r0]
	ldr r2, _08032AC4
	adds r0, r2
	ldrb r2, [r0]
	cmp r2, 0
	beq _08032B58
	ldr r0, _08032AC8
	ldr r3, _08032ACC
	movs r2, 0
	str r2, [sp]
	movs r1, 0x4
	str r1, [sp, 0x4]
	str r2, [sp, 0x8]
	str r2, [sp, 0xC]
	bl _08033864
	.align 2, 0
_08032AC0: .4byte gUnknown_203B33C
_08032AC4: .4byte 0x0000052c
_08032AC8: .4byte gUnknown_80E25F4
_08032ACC: .4byte gUnknown_80E20E0
_08032AD0:
	movs r0, 0x1
	bl sub_8095324
	cmp r0, 0
	bne _08032B24
	movs r0, 0x5
	bl sub_8095324
	adds r4, r0, 0
	cmp r4, 0
	bne _08032B24
	ldr r0, _08032B04
	ldr r0, [r0]
	ldr r3, _08032B08
	adds r0, r3
	ldrb r2, [r0]
	cmp r2, 0
	beq _08032B14
	ldr r0, _08032B0C
	ldr r3, _08032B10
	str r4, [sp]
	movs r1, 0x4
	str r1, [sp, 0x4]
	str r4, [sp, 0x8]
	str r4, [sp, 0xC]
	b _08032B66
	.align 2, 0
_08032B04: .4byte gUnknown_203B33C
_08032B08: .4byte 0x0000052c
_08032B0C: .4byte gUnknown_80E25F4
_08032B10: .4byte gUnknown_80E2108
_08032B14:
	ldr r0, _08032B1C
	ldr r3, _08032B20
	b _08032B5C
	.align 2, 0
_08032B1C: .4byte gUnknown_80E25F4
_08032B20: .4byte gUnknown_80E20B8
_08032B24:
	ldr r0, _08032B48
	ldr r0, [r0]
	ldr r4, _08032B4C
	adds r0, r4
	ldrb r2, [r0]
	cmp r2, 0
	beq _08032B58
	ldr r0, _08032B50
	ldr r3, _08032B54
	movs r2, 0
	str r2, [sp]
	movs r1, 0x4
	str r1, [sp, 0x4]
	str r2, [sp, 0x8]
	str r2, [sp, 0xC]
	bl _08033864
	.align 2, 0
_08032B48: .4byte gUnknown_203B33C
_08032B4C: .4byte 0x0000052c
_08032B50: .4byte gUnknown_80E25F4
_08032B54: .4byte gUnknown_80E20E0
_08032B58:
	ldr r0, _08032B78
	ldr r3, _08032B7C
_08032B5C:
	str r2, [sp]
	movs r1, 0x4
	str r1, [sp, 0x4]
	str r2, [sp, 0x8]
	str r2, [sp, 0xC]
_08032B66:
	adds r1, 0xFD
	str r1, [sp, 0x10]
	movs r1, 0
	movs r2, 0
	bl sub_8014248
	bl _080338B4
	.align 2, 0
_08032B78: .4byte gUnknown_80E25F4
_08032B7C: .4byte gUnknown_80E2068
_08032B80:
	movs r0, 0x4
	bl sub_8095324
	adds r2, r0, 0
	cmp r2, 0
	beq _08032B9C
	ldr r0, _08032B94
	ldr r3, _08032B98
	movs r2, 0
	b _08032BA0
	.align 2, 0
_08032B94: .4byte gUnknown_80E25F4
_08032B98: .4byte gUnknown_80E2130
_08032B9C:
	ldr r0, _08032BBC
	ldr r3, _08032BC0
_08032BA0:
	str r2, [sp]
	movs r1, 0x4
	str r1, [sp, 0x4]
	str r2, [sp, 0x8]
	str r2, [sp, 0xC]
	adds r1, 0xFD
	str r1, [sp, 0x10]
	movs r1, 0
	movs r2, 0x3
	bl sub_8014248
	bl _080338B4
	.align 2, 0
_08032BBC: .4byte gUnknown_80E25F4
_08032BC0: .4byte gUnknown_80E2190
_08032BC4:
	movs r0, 0x1
	bl sub_8095324
	adds r4, r0, 0
	cmp r4, 0
	bne _08032C0C
	movs r0, 0x5
	bl sub_8095324
	cmp r0, 0
	bne _08032BF4
	ldr r0, _08032BEC
	ldr r3, _08032BF0
	str r4, [sp]
	movs r1, 0x4
	str r1, [sp, 0x4]
	str r4, [sp, 0x8]
	str r4, [sp, 0xC]
	b _08032C38
	.align 2, 0
_08032BEC: .4byte gUnknown_80E25F4
_08032BF0: .4byte gUnknown_80E2268
_08032BF4:
	ldr r0, _08032C04
	ldr r3, _08032C08
	str r4, [sp]
	movs r1, 0x4
	str r1, [sp, 0x4]
	str r4, [sp, 0x8]
	str r4, [sp, 0xC]
	b _08032C38
	.align 2, 0
_08032C04: .4byte gUnknown_80E25F4
_08032C08: .4byte gUnknown_80E2218
_08032C0C:
	movs r0, 0x5
	bl sub_8095324
	adds r2, r0, 0
	cmp r2, 0
	bne _08032C28
	ldr r0, _08032C20
	ldr r3, _08032C24
	b _08032C2E
	.align 2, 0
_08032C20: .4byte gUnknown_80E25F4
_08032C24: .4byte gUnknown_80E2240
_08032C28:
	ldr r0, _08032C48
	ldr r3, _08032C4C
	movs r2, 0
_08032C2E:
	str r2, [sp]
	movs r1, 0x4
	str r1, [sp, 0x4]
	str r2, [sp, 0x8]
	str r2, [sp, 0xC]
_08032C38:
	adds r1, 0xFD
	str r1, [sp, 0x10]
	movs r1, 0
	movs r2, 0x11
	bl sub_8014248
	bl _080338B4
	.align 2, 0
_08032C48: .4byte gUnknown_80E25F4
_08032C4C: .4byte gUnknown_80E21B8
_08032C50:
	ldr r0, [r6]
	movs r5, 0xA5
	lsls r5, 3
	adds r0, r5
	ldr r0, [r0]
	subs r0, 0x3
	cmp r0, 0x11
	bls _08032C64
	bl _080338B4
_08032C64:
	lsls r0, 2
	ldr r1, _08032C70
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08032C70: .4byte _08032C74
	.align 2, 0
_08032C74:
	.4byte _08032CC8
	.4byte _08032CD4
	.4byte _080338B4
	.4byte _080338B4
	.4byte _080338B4
	.4byte _080338B4
	.4byte _080338B4
	.4byte _080338B4
	.4byte _080338B4
	.4byte _080338B4
	.4byte _080338B4
	.4byte _080338B4
	.4byte _080338B4
	.4byte _080338B4
	.4byte _08032CBC
	.4byte _08032CE0
	.4byte _08032CEC
	.4byte _08032CF8
_08032CBC:
	ldr r0, _08032CC4
	bl _0803374A
	.align 2, 0
_08032CC4: .4byte gUnknown_80E2610
_08032CC8:
	ldr r0, _08032CD0
	bl _0803374A
	.align 2, 0
_08032CD0: .4byte gUnknown_80E2640
_08032CD4:
	ldr r0, _08032CDC
	bl _0803374A
	.align 2, 0
_08032CDC: .4byte gUnknown_80E2680
_08032CE0:
	ldr r0, _08032CE8
	bl _0803374A
	.align 2, 0
_08032CE8: .4byte gUnknown_80E26B0
_08032CEC:
	ldr r0, _08032CF4
	bl _0803374A
	.align 2, 0
_08032CF4: .4byte gUnknown_80E26F0
_08032CF8:
	ldr r0, _08032D00
	bl _0803374A
	.align 2, 0
_08032D00: .4byte gUnknown_80E2728
_08032D04:
	ldr r0, _08032D0C
	bl _0803388E
	.align 2, 0
_08032D0C: .4byte gUnknown_80E276C
_08032D10:
	ldr r0, _08032D18
	ldr r3, _08032D1C
	bl _080336FC
	.align 2, 0
_08032D18: .4byte gUnknown_80E27A4
_08032D1C: .4byte gUnknown_80E2458
_08032D20:
	ldr r0, _08032D28
	bl _0803388E
	.align 2, 0
_08032D28: .4byte gUnknown_80E2814
_08032D2C:
	ldr r0, _08032D34
	bl _0803388E
	.align 2, 0
_08032D34: .4byte gUnknown_80E2840
_08032D38:
	ldr r0, _08032D40
	bl _0803388E
	.align 2, 0
_08032D40: .4byte gUnknown_80E2874
_08032D44:
	ldr r0, [r6]
	ldr r1, _08032D60
	adds r0, r1
	ldr r0, [r0]
	cmp r0, 0xC
	bne _08032D54
	bl _080338B4
_08032D54:
	cmp r0, 0xC
	bhi _08032D64
	cmp r0, 0xB
	beq _08032D6C
	bl _080338B4
	.align 2, 0
_08032D60: .4byte 0x00000524
_08032D64:
	cmp r0, 0xE
	bls _08032D6C
	bl _080338B4
_08032D6C:
	ldr r0, _08032D74
	bl _0803388E
	.align 2, 0
_08032D74: .4byte gUnknown_80E2898
_08032D78:
	ldr r0, _08032D80
	bl _0803388E
	.align 2, 0
_08032D80: .4byte gUnknown_80E28D8
_08032D84:
	ldr r0, _08032D8C
	bl _0803388E
	.align 2, 0
_08032D8C: .4byte gUnknown_80E2904
_08032D90:
	ldr r0, _08032D98
	bl _0803388E
	.align 2, 0
_08032D98: .4byte gUnknown_80E296C
_08032D9C:
	bl sub_8030894
	cmp r0, 0
	beq _08032DA8
	bl _080338B4
_08032DA8:
	bl ResetUnusedInputStruct
	movs r0, 0
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	movs r0, 0x1
	bl _080336A6
_08032DBC:
	ldr r0, _08032DC4
	ldr r3, _08032DC8
	bl _080336FC
	.align 2, 0
_08032DC4: .4byte gUnknown_80E29A0
_08032DC8: .4byte gUnknown_80E22B4
_08032DCC:
	ldr r0, [r6]
	ldr r2, _08032DE8
	adds r0, r2
	ldr r0, [r0]
	cmp r0, 0xC
	bne _08032DDC
	bl _080338B4
_08032DDC:
	cmp r0, 0xC
	bhi _08032DEC
	cmp r0, 0xB
	beq _08032DF4
	bl _080338B4
	.align 2, 0
_08032DE8: .4byte 0x00000524
_08032DEC:
	cmp r0, 0xE
	bls _08032DF4
	bl _080338B4
_08032DF4:
	ldr r0, _08032DFC
	bl _0803388E
	.align 2, 0
_08032DFC: .4byte gUnknown_80E29D0
_08032E00:
	ldr r0, _08032E08
	bl _0803388E
	.align 2, 0
_08032E08: .4byte gUnknown_80E2A0C
_08032E0C:
	ldr r0, [r6]
	movs r3, 0xEF
	lsls r3, 2
	adds r0, r3
	bl sub_8006518
	bl ResetUnusedInputStruct
	movs r0, 0
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	ldr r0, [r6]
	movs r4, 0x86
	lsls r4, 2
	adds r0, r4
	b _0803343E
_08032E30:
	ldr r0, _08032E38
	bl _0803388E
	.align 2, 0
_08032E38: .4byte gUnknown_80E2A1C
_08032E3C:
	ldr r0, _08032E44
	bl _0803388E
	.align 2, 0
_08032E44: .4byte gUnknown_80E2A5C
_08032E48:
	ldr r0, _08032E50
	bl _0803388E
	.align 2, 0
_08032E50: .4byte gUnknown_80E2A80
_08032E54:
	ldr r0, _08032E5C
	bl _0803388E
	.align 2, 0
_08032E5C: .4byte gUnknown_80E2AA8
_08032E60:
	ldr r0, _08032E68
	bl _0803388E
	.align 2, 0
_08032E68: .4byte gUnknown_80E2AE4
_08032E6C:
	ldr r0, [r6]
	ldr r2, _08032E88
	adds r0, r2
	ldr r0, [r0]
	cmp r0, 0xC
	bne _08032E7C
	bl _080338B4
_08032E7C:
	cmp r0, 0xC
	bhi _08032E8C
	cmp r0, 0xB
	beq _08032E94
	bl _080338B4
	.align 2, 0
_08032E88: .4byte 0x00000524
_08032E8C:
	cmp r0, 0xE
	bls _08032E94
	bl _080338B4
_08032E94:
	ldr r0, _08032E9C
	bl _0803388E
	.align 2, 0
_08032E9C: .4byte gUnknown_80E2B54
_08032EA0:
	ldr r0, _08032EA8
	bl _0803388E
	.align 2, 0
_08032EA8: .4byte gUnknown_80E2A0C
_08032EAC:
	ldr r0, _08032EB4
	bl _0803388E
	.align 2, 0
_08032EB4: .4byte gUnknown_80E2B90
_08032EB8:
	ldr r0, _08032ED8
	ldr r3, _08032EDC
	movs r2, 0
	str r2, [sp]
	movs r1, 0x4
	str r1, [sp, 0x4]
	str r2, [sp, 0x8]
	str r2, [sp, 0xC]
	adds r1, 0xFD
	str r1, [sp, 0x10]
	movs r1, 0
	movs r2, 0xF
	bl sub_8014248
	bl _080338B4
	.align 2, 0
_08032ED8: .4byte gUnknown_80E2BE0
_08032EDC: .4byte gUnknown_80E23A8
_08032EE0:
	ldr r0, _08032EE8
	bl _0803388E
	.align 2, 0
_08032EE8: .4byte gUnknown_80E2C48
_08032EEC:
	bl sub_8023CE8
	cmp r0, 0
	beq _08032EF8
	bl sub_8023C60
_08032EF8:
	bl ResetUnusedInputStruct
	movs r0, 0
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	movs r0, 0x3
	movs r1, 0
	movs r2, 0
	movs r3, 0x9
	bl sub_8023868
	bl _080338B4
_08032F16:
	ldr r0, [r6]
	movs r4, 0xD7
	lsls r4, 2
	adds r0, r4
	bl sub_8006518
	ldr r1, [r6]
	movs r5, 0x87
	lsls r5, 2
	adds r0, r1, r5
	adds r1, r4
	ldr r3, _08032F4C
	ldr r2, _08032F50
	str r2, [sp]
	movs r2, 0x1
	str r2, [sp, 0x4]
	movs r2, 0
	str r2, [sp, 0x8]
	str r2, [sp, 0xC]
	movs r2, 0x3
	bl SetMenuItems
	bl sub_8023DA4
	bl _080336E2
	.align 2, 0
_08032F4C: .4byte gUnknown_80E2334
_08032F50: .4byte gUnknown_80E234C
_08032F54:
	ldr r0, _08032F74
	ldr r3, _08032F78
	movs r2, 0
	str r2, [sp]
	movs r1, 0x4
	str r1, [sp, 0x4]
	str r2, [sp, 0x8]
	str r2, [sp, 0xC]
	adds r1, 0xFD
	str r1, [sp, 0x10]
	movs r1, 0
	movs r2, 0x10
	bl sub_8014248
	bl _080338B4
	.align 2, 0
_08032F74: .4byte gUnknown_80E2C94
_08032F78: .4byte gUnknown_80E22F0
_08032F7C:
	ldr r0, _08032F84
	ldr r3, _08032F88
	bl _080336FC
	.align 2, 0
_08032F84: .4byte gUnknown_80E2CD4
_08032F88: .4byte gUnknown_80E22D0
_08032F8C:
	ldr r0, _08032F94
	bl _0803388E
	.align 2, 0
_08032F94: .4byte gUnknown_80E2CE8
_08032F98:
	bl sub_8030894
	cmp r0, 0
	beq _08032FA4
	bl _080338B4
_08032FA4:
	bl ResetUnusedInputStruct
	movs r0, 0
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	movs r0, 0x4
	b _080336A6
_08032FB6:
	ldr r0, _08032FBC
	ldr r3, _08032FC0
	b _080336FC
	.align 2, 0
_08032FBC: .4byte gUnknown_80E2D30
_08032FC0: .4byte gUnknown_80E22B4
_08032FC4:
	ldr r0, _08032FCC
	bl _0803388E
	.align 2, 0
_08032FCC: .4byte gUnknown_80E2D60
_08032FD0:
	ldr r0, _08032FD4
	b _080336FA
	.align 2, 0
_08032FD4: .4byte gUnknown_80E2D7C
_08032FD8:
	ldr r0, _08032FDC
	b _080336FA
	.align 2, 0
_08032FDC: .4byte gUnknown_80E2E20
_08032FE0:
	ldr r0, _08032FE4
	b _08033574
	.align 2, 0
_08032FE4: .4byte gUnknown_80E2E54
_08032FE8:
	ldr r0, _08032FEC
	b _08033574
	.align 2, 0
_08032FEC: .4byte gUnknown_80E2EB4
_08032FF0:
	ldr r1, [r6]
	movs r0, 0
	str r0, [r1, 0x44]
	bl sub_8011830
	ldr r0, [r6]
	ldr r0, [r0, 0x40]
	bl sub_8037B28
	adds r4, r0, 0
	ldr r0, [r6]
	str r4, [r0, 0x44]
	cmp r4, 0
	beq _0803300E
	b _080333DE
_0803300E:
	ldr r1, [r0, 0x40]
	cmp r1, 0x3
	beq _08033028
	cmp r1, 0x3
	bhi _0803301E
	cmp r1, 0x2
	beq _0803304A
	b _0803313C
_0803301E:
	cmp r1, 0x4
	beq _080330B4
	cmp r1, 0x5
	beq _0803308E
	b _0803313C
_08033028:
	adds r0, 0x48
	movs r1, 0
	movs r2, 0x30
	bl MemoryFill8
	ldr r0, [r6]
	adds r0, 0x78
	movs r1, 0
	movs r2, 0x30
	bl MemoryFill8
	ldr r2, [r6]
	ldr r0, [r2, 0x40]
	adds r1, r2, 0
	adds r1, 0x48
	adds r2, 0x78
	b _08033134
_0803304A:
	adds r0, 0x48
	movs r1, 0
	movs r2, 0x30
	bl MemoryFill8
	ldr r0, [r6]
	adds r0, 0x78
	movs r1, 0
	movs r2, 0x30
	bl MemoryFill8
	ldr r0, [r6]
	movs r3, 0x86
	lsls r3, 2
	adds r0, r3
	ldrb r0, [r0]
	bl sub_8095228
	ldr r1, [r6]
	adds r1, 0x48
	ldm r0!, {r2,r4,r5}
	stm r1!, {r2,r4,r5}
	ldm r0!, {r3-r5}
	stm r1!, {r3-r5}
	ldm r0!, {r2-r4}
	stm r1!, {r2-r4}
	ldm r0!, {r2,r3,r5}
	stm r1!, {r2,r3,r5}
	ldr r2, [r6]
	ldr r0, [r2, 0x40]
	adds r1, r2, 0
	adds r1, 0x48
	adds r2, 0x78
	b _08033134
_0803308E:
	adds r0, 0xA8
	movs r1, 0
	movs r2, 0x88
	bl MemoryFill8
	ldr r0, [r6]
	movs r4, 0x98
	lsls r4, 1
	adds r0, r4
	movs r1, 0
	movs r2, 0x88
	bl MemoryFill8
	ldr r2, [r6]
	ldr r0, [r2, 0x40]
	adds r1, r2, 0
	adds r1, 0xA8
	adds r2, r4
	b _08033134
_080330B4:
	adds r0, 0xA8
	movs r1, 0
	movs r2, 0x88
	bl MemoryFill8
	ldr r0, [r6]
	movs r5, 0x98
	lsls r5, 1
	adds r0, r5
	movs r1, 0
	movs r2, 0x88
	bl MemoryFill8
	ldr r1, [r6]
	adds r0, r1, 0
	adds r0, 0xE0
	strh r4, [r0]
	movs r2, 0xB4
	lsls r2, 1
	adds r0, r1, r2
	strh r4, [r0]
	movs r3, 0x86
	lsls r3, 2
	adds r0, r1, r3
	ldrb r0, [r0]
	bl sub_8095228
	ldr r1, [r6]
	adds r1, 0xA8
	ldm r0!, {r2-r4}
	stm r1!, {r2-r4}
	ldm r0!, {r2-r4}
	stm r1!, {r2-r4}
	ldm r0!, {r2-r4}
	stm r1!, {r2-r4}
	ldm r0!, {r2-r4}
	stm r1!, {r2-r4}
	ldr r2, [r6]
	movs r4, 0xA7
	lsls r4, 3
	adds r3, r2, r4
	movs r0, 0
	ldrsh r1, [r3, r0]
	movs r0, 0x1
	negs r0, r0
	cmp r1, r0
	beq _0803312A
	adds r0, r2, 0
	adds r0, 0xD8
	ldr r1, _08033188
	ldr r1, [r1]
	movs r2, 0
	ldrsh r3, [r3, r2]
	movs r2, 0x58
	muls r2, r3
	adds r1, r2
	movs r2, 0x58
	bl memcpy
_0803312A:
	ldr r2, [r6]
	ldr r0, [r2, 0x40]
	adds r1, r2, 0
	adds r1, 0xA8
	adds r2, r5
_08033134:
	bl sub_8037D64
	ldr r1, [r6]
	str r0, [r1, 0x44]
_0803313C:
	ldr r4, _0803318C
	ldr r2, [r4]
	ldr r0, [r2, 0x44]
	cmp r0, 0
	beq _08033148
	b _080333DE
_08033148:
	ldr r0, [r2, 0x40]
	cmp r0, 0x2
	bcs _08033150
	b _080333DE
_08033150:
	cmp r0, 0x3
	bls _08033190
	cmp r0, 0x5
	bls _0803315A
	b _080333DE
_0803315A:
	adds r1, r2, 0
	adds r1, 0xA8
	movs r3, 0x98
	lsls r3, 1
	adds r2, r3
	bl sub_80381F4
	ldr r1, [r4]
	str r0, [r1, 0x44]
	bl sub_800D588
	lsls r0, 24
	cmp r0, 0
	beq _080331C0
	ldr r0, [r4]
	movs r4, 0x84
	lsls r4, 3
	adds r1, r0, r4
	movs r5, 0xA0
	lsls r5, 1
	adds r0, r5
	b _080333DA
	.align 2, 0
_08033188: .4byte gUnknown_203B45C
_0803318C: .4byte gUnknown_203B33C
_08033190:
	adds r1, r2, 0
	adds r1, 0x48
	adds r2, 0x78
	bl sub_80381F4
	ldr r1, [r4]
	str r0, [r1, 0x44]
	bl sub_800D588
	lsls r0, 24
	cmp r0, 0
	beq _080331B4
	ldr r0, [r4]
	movs r2, 0x84
	lsls r2, 3
	adds r1, r0, r2
	adds r0, 0x88
	b _080333DA
_080331B4:
	ldr r0, [r4]
	movs r3, 0x84
	lsls r3, 3
	adds r1, r0, r3
	ldr r0, [r0, 0x58]
	b _080333DC
_080331C0:
	ldr r0, [r4]
	movs r4, 0x84
	lsls r4, 3
	adds r1, r0, r4
	adds r0, 0xB8
	b _080333DA
_080331CC:
	ldr r0, _080331D0
	b _0803388E
	.align 2, 0
_080331D0: .4byte gUnknown_80E2F14
_080331D4:
	ldr r0, _080331D8
	b _0803388E
	.align 2, 0
_080331D8: .4byte gUnknown_80E2F44
_080331DC:
	bl sub_8030894
	cmp r0, 0
	beq _080331E6
	b _080338B4
_080331E6:
	bl ResetUnusedInputStruct
	movs r0, 0
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	movs r0, 0x1
	b _080336A6
_080331F8:
	ldr r0, _080331FC
	b _080336FA
	.align 2, 0
_080331FC: .4byte gUnknown_80E2F78
_08033200:
	ldr r0, _08033204
	b _0803388E
	.align 2, 0
_08033204: .4byte gUnknown_80E2FA0
_08033208:
	ldr r0, [r6]
	ldr r5, _08033220
	adds r0, r5
	ldr r0, [r0]
	cmp r0, 0xC
	bne _08033216
	b _080338B4
_08033216:
	cmp r0, 0xC
	bhi _08033224
	cmp r0, 0xB
	beq _0803322A
	b _080338B4
	.align 2, 0
_08033220: .4byte 0x00000524
_08033224:
	cmp r0, 0xE
	bls _0803322A
	b _080338B4
_0803322A:
	ldr r0, _08033230
	b _0803388E
	.align 2, 0
_08033230: .4byte gUnknown_80E2FEC
_08033234:
	ldr r0, _08033238
	b _0803388E
	.align 2, 0
_08033238: .4byte gUnknown_80E3030
_0803323C:
	ldr r0, _08033240
	b _0803388E
	.align 2, 0
_08033240: .4byte gUnknown_80E3078
_08033244:
	ldr r0, [r6]
	movs r1, 0xEF
	lsls r1, 2
	adds r0, r1
	b _080333F4
_0803324E:
	ldr r0, _08033254
	ldr r3, _08033258
	b _080336FC
	.align 2, 0
_08033254: .4byte gUnknown_80E30A4
_08033258: .4byte gUnknown_80E2458
_0803325C:
	ldr r0, _08033260
	b _0803388E
	.align 2, 0
_08033260: .4byte gUnknown_80E30D0
_08033264:
	ldr r0, [r6]
	movs r4, 0xD7
	lsls r4, 2
	adds r0, r4
	bl sub_8006518
	ldr r1, [r6]
	movs r5, 0x87
	lsls r5, 2
	adds r0, r1, r5
	adds r1, r4
	ldr r3, _08033280
	ldr r2, _08033284
	b _080336CC
	.align 2, 0
_08033280: .4byte gUnknown_80E231C
_08033284: .4byte gUnknown_80E2408
_08033288:
	bl sub_801D008
	cmp r0, 0
	beq _08033292
	b _080338B4
_08033292:
	bl ResetUnusedInputStruct
	movs r0, 0
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	ldr r0, _080332B4
	str r0, [sp, 0x64]
	add r2, sp, 0x64
	movs r0, 0
	movs r1, 0x1
	movs r3, 0x9
	bl sub_801C8C4
	b _080338B4
	.align 2, 0
_080332B4: .4byte 0x00020003
_080332B8:
	ldr r0, [r6]
	movs r4, 0xD7
	lsls r4, 2
	adds r0, r4
	bl sub_8006518
	ldr r1, [r6]
	movs r5, 0x87
	lsls r5, 2
	adds r0, r1, r5
	adds r1, r4
	ldr r3, _080332EC
	ldr r2, _080332F0
	str r2, [sp]
	movs r2, 0x1
	str r2, [sp, 0x4]
	movs r2, 0
	str r2, [sp, 0x8]
	str r2, [sp, 0xC]
	movs r2, 0x3
	bl SetMenuItems
	bl sub_801CCD8
	b _080336E2
	.align 2, 0
_080332EC: .4byte gUnknown_80E23F0
_080332F0: .4byte gUnknown_80E2408
_080332F4:
	ldr r1, [r6]
	movs r0, 0
	str r0, [r1, 0x44]
	bl sub_8011830
	ldr r0, [r6]
	ldr r0, [r0, 0x40]
	bl sub_8037B28
	ldr r1, [r6]
	str r0, [r1, 0x44]
	cmp r0, 0
	bne _080333DE
	ldr r0, [r1, 0x40]
	cmp r0, 0x6
	beq _0803331A
	cmp r0, 0x7
	beq _08033358
	b _08033388
_0803331A:
	movs r4, 0xDC
	lsls r4, 1
	adds r0, r1, r4
	movs r1, 0
	movs r2, 0x30
	bl MemoryFill8
	ldr r0, [r6]
	movs r2, 0x86
	lsls r2, 2
	adds r0, r2
	ldrb r0, [r0]
	bl sub_8095228
	ldr r1, [r6]
	adds r1, r4
	ldm r0!, {r2,r3,r5}
	stm r1!, {r2,r3,r5}
	ldm r0!, {r2,r3,r5}
	stm r1!, {r2,r3,r5}
	ldm r0!, {r2,r3,r5}
	stm r1!, {r2,r3,r5}
	ldm r0!, {r2,r3,r5}
	stm r1!, {r2,r3,r5}
	ldr r2, [r6]
	ldr r0, [r2, 0x40]
	adds r4, r2, r4
	movs r3, 0xF4
	lsls r3, 1
	adds r2, r3
	b _0803337E
_08033358:
	movs r4, 0xDC
	lsls r4, 1
	adds r0, r1, r4
	movs r1, 0
	movs r2, 0x30
	bl MemoryFill8
	ldr r0, [r6]
	movs r5, 0xF4
	lsls r5, 1
	adds r0, r5
	movs r1, 0
	movs r2, 0x30
	bl MemoryFill8
	ldr r2, [r6]
	ldr r0, [r2, 0x40]
	adds r4, r2, r4
	adds r2, r5
_0803337E:
	adds r1, r4, 0
	bl sub_8037D64
	ldr r1, [r6]
	str r0, [r1, 0x44]
_08033388:
	ldr r4, _080333C8
	ldr r2, [r4]
	ldr r0, [r2, 0x44]
	cmp r0, 0
	bne _080333DE
	ldr r0, [r2, 0x40]
	cmp r0, 0x7
	bhi _080333DE
	cmp r0, 0x6
	bcc _080333DE
	movs r5, 0xDC
	lsls r5, 1
	adds r1, r2, r5
	movs r3, 0xF4
	lsls r3, 1
	adds r2, r3
	bl sub_80381F4
	ldr r1, [r4]
	str r0, [r1, 0x44]
	bl sub_800D588
	lsls r0, 24
	cmp r0, 0
	beq _080333CC
	ldr r0, [r4]
	movs r4, 0x84
	lsls r4, 3
	adds r1, r0, r4
	adds r5, 0x40
	adds r0, r5
	b _080333DA
	.align 2, 0
_080333C8: .4byte gUnknown_203B33C
_080333CC:
	ldr r0, [r4]
	movs r2, 0x84
	lsls r2, 3
	adds r1, r0, r2
	movs r3, 0xE4
	lsls r3, 1
	adds r0, r3
_080333DA:
	ldr r0, [r0]
_080333DC:
	str r0, [r1]
_080333DE:
	bl xxx_call_start_bg_music
	b _080338B4
_080333E4:
	ldr r0, _080333E8
	b _0803388E
	.align 2, 0
_080333E8: .4byte gUnknown_80E311C
_080333EC:
	ldr r0, [r6]
	movs r4, 0xEF
	lsls r4, 2
	adds r0, r4
_080333F4:
	bl sub_8006518
	bl ResetUnusedInputStruct
	movs r0, 0
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	ldr r1, [r6]
	adds r1, 0x8
	movs r0, 0x4
	bl sub_80151C0
	b _080338B4
_08033412:
	ldr r0, _08033418
	b _0803388E
	.align 2, 0
_08033418: .4byte gUnknown_80E314C
_0803341C:
	ldr r0, [r6]
	movs r5, 0xEF
	lsls r5, 2
	adds r0, r5
	bl sub_8006518
	bl ResetUnusedInputStruct
	movs r0, 0
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	ldr r0, [r6]
	movs r1, 0x86
	lsls r1, 2
	adds r0, r1
_0803343E:
	ldrb r0, [r0]
	movs r1, 0
	bl sub_8031D70
	b _080338B4
_08033448:
	ldr r0, _0803344C
	b _0803388E
	.align 2, 0
_0803344C: .4byte gUnknown_80E317C
_08033450:
	ldr r0, _08033454
	b _0803388E
	.align 2, 0
_08033454: .4byte gUnknown_80E319C
_08033458:
	ldr r0, _0803345C
	b _0803388E
	.align 2, 0
_0803345C: .4byte gUnknown_80E317C
_08033460:
	ldr r0, _08033464
	b _0803388E
	.align 2, 0
_08033464: .4byte gUnknown_80E31D8
_08033468:
	ldr r0, _0803346C
	b _0803388E
	.align 2, 0
_0803346C: .4byte gUnknown_80E31FC
_08033470:
	ldr r0, [r6]
	ldr r2, _08033488
	adds r0, r2
	ldr r0, [r0]
	cmp r0, 0xC
	bne _0803347E
	b _080338B4
_0803347E:
	cmp r0, 0xC
	bhi _0803348C
	cmp r0, 0xB
	beq _08033492
	b _080338B4
	.align 2, 0
_08033488: .4byte 0x00000524
_0803348C:
	cmp r0, 0xE
	bls _08033492
	b _080338B4
_08033492:
	ldr r0, _08033498
	b _0803388E
	.align 2, 0
_08033498: .4byte gUnknown_80E3220
_0803349C:
	movs r0, 0x98
	lsls r0, 1
	bl GetMonSpecies
	adds r1, r0, 0
	ldr r4, _080334F8
	ldr r0, [r4]
	ldr r3, _080334FC
	adds r0, r3
	bl strcpy
	ldr r1, [r4]
	movs r5, 0xAA
	lsls r5, 3
	adds r0, r1, r5
	movs r2, 0
	strh r2, [r0]
	ldr r0, _08033500
	adds r1, r0
	movs r0, 0x2
	strb r0, [r1]
	ldr r0, [r4]
	ldr r3, _08033504
	adds r1, r0, r3
	str r2, [r1]
	movs r5, 0x84
	lsls r5, 3
	adds r0, r5
	ldr r1, [r0]
	movs r0, 0x6
	bl sub_809539C
	lsls r0, 24
	lsrs r0, 24
	bl sub_8095228
	adds r2, r0, 0
	adds r0, 0x22
	ldrb r1, [r0]
	cmp r1, 0
	beq _08033508
	ldr r0, [r4]
	movs r3, 0xAB
	lsls r3, 3
	adds r0, r3
	b _08033512
	.align 2, 0
_080334F8: .4byte gUnknown_203B33C
_080334FC: .4byte 0x0000053c
_08033500: .4byte 0x00000552
_08033504: .4byte 0x00000554
_08033508:
	ldr r0, [r4]
	movs r4, 0xAB
	lsls r4, 3
	adds r0, r4
	movs r1, 0
_08033512:
	strb r1, [r0]
	ldr r4, _08033558
	ldr r0, [r4]
	ldr r5, _0803355C
	adds r0, r5
	movs r5, 0
	movs r1, 0x1
	strb r1, [r0]
	adds r0, r2, 0x4
	movs r1, 0
	bl sub_803C200
	ldr r1, [r4]
	movs r3, 0xAC
	lsls r3, 3
	adds r2, r1, r3
	str r0, [r2]
	ldr r0, _08033560
	adds r1, r0
	strb r5, [r1]
	ldr r0, [r4]
	ldr r1, _08033564
	adds r0, r1
	strb r5, [r0]
	ldr r0, [r4]
	ldr r2, _08033568
	adds r0, r2
	strb r5, [r0]
	ldr r0, [r4]
	subs r3, 0x24
	adds r0, r3
	movs r1, 0
	bl sub_802F204
	b _080338B4
	.align 2, 0
_08033558: .4byte gUnknown_203B33C
_0803355C: .4byte 0x0000055b
_08033560: .4byte 0x00000559
_08033564: .4byte 0x0000055a
_08033568: .4byte 0x0000055c
_0803356C:
	movs r0, 0
	bl nullsub_23
	ldr r0, _08033580
_08033574:
	movs r1, 0
	movs r2, 0
	movs r3, 0
	bl sub_80141B4
	b _080338B4
	.align 2, 0
_08033580: .4byte gUnknown_80E2DD0
_08033584:
	ldr r0, [r6]
	ldr r4, _0803359C
	adds r0, r4
	ldr r0, [r0]
	cmp r0, 0xC
	bne _08033592
	b _080338B4
_08033592:
	cmp r0, 0xC
	bhi _080335A0
	cmp r0, 0xB
	beq _080335A6
	b _080338B4
	.align 2, 0
_0803359C: .4byte 0x00000524
_080335A0:
	cmp r0, 0xE
	bls _080335A6
	b _080338B4
_080335A6:
	ldr r0, _080335AC
	b _0803388E
	.align 2, 0
_080335AC: .4byte gUnknown_80E3248
_080335B0:
	ldr r0, _080335B4
	b _0803388E
	.align 2, 0
_080335B4: .4byte gUnknown_80E3288
_080335B8:
	ldr r0, _080335BC
	b _080336FA
	.align 2, 0
_080335BC: .4byte gUnknown_80E2D7C
_080335C0:
	bl sub_808D33C
	adds r1, r0, 0
	adds r1, 0x4C
	add r0, sp, 0x14
	movs r2, 0xA
	bl sub_80922B4
	ldr r5, _080335E8
	ldr r0, [r5]
	ldr r4, _080335EC
	adds r0, r4
	ldr r1, _080335F0
	add r2, sp, 0x14
	bl sub_800D158
	ldr r0, [r5]
	adds r0, r4
	b _0803388E
	.align 2, 0
_080335E8: .4byte gUnknown_203B33C
_080335EC: .4byte 0x00000424
_080335F0: .4byte gUnknown_80E32C4
_080335F4:
	ldr r0, _080335FC
	ldr r3, _08033600
	b _080336FC
	.align 2, 0
_080335FC: .4byte gUnknown_80E331C
_08033600: .4byte gUnknown_80E24D8
_08033604:
	ldr r0, _08033608
	b _0803388E
	.align 2, 0
_08033608: .4byte gUnknown_80E317C
_0803360C:
	ldr r0, _08033610
	b _0803388E
	.align 2, 0
_08033610: .4byte gUnknown_80E2A0C
_08033614:
	ldr r0, _08033618
	b _0803388E
	.align 2, 0
_08033618: .4byte gUnknown_80E3378
_0803361C:
	ldr r0, _0803363C
	ldr r3, _08033640
	movs r2, 0
	str r2, [sp]
	movs r1, 0x4
	str r1, [sp, 0x4]
	str r2, [sp, 0x8]
	str r2, [sp, 0xC]
	adds r1, 0xFD
	str r1, [sp, 0x10]
	movs r1, 0
	movs r2, 0x16
	bl sub_8014248
	b _080338B4
	.align 2, 0
_0803363C: .4byte gUnknown_80E339C
_08033640: .4byte gUnknown_80E24B0
_08033644:
	ldr r0, _08033664
	ldr r3, _08033668
	movs r2, 0
	str r2, [sp]
	movs r1, 0x4
	str r1, [sp, 0x4]
	str r2, [sp, 0x8]
	str r2, [sp, 0xC]
	adds r1, 0xFD
	str r1, [sp, 0x10]
	movs r1, 0
	movs r2, 0x15
	bl sub_8014248
	b _080338B4
	.align 2, 0
_08033664: .4byte gUnknown_80E33D8
_08033668: .4byte gUnknown_80E2470
_0803366C:
	ldr r0, _08033670
	b _0803388E
	.align 2, 0
_08033670: .4byte gUnknown_80E3430
_08033674:
	ldr r0, _0803367C
	ldr r3, _08033680
	b _080336FC
	.align 2, 0
_0803367C: .4byte gUnknown_80E34B0
_08033680: .4byte gUnknown_80E2440
_08033684:
	ldr r0, _08033688
	b _0803388E
	.align 2, 0
_08033688: .4byte gUnknown_80E34F0
_0803368C:
	bl sub_8030894
	cmp r0, 0
	beq _08033696
	b _080338B4
_08033696:
	bl ResetUnusedInputStruct
	movs r0, 0
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	movs r0, 0x5
_080336A6:
	movs r1, 0
	movs r2, 0
	movs r3, 0x6
	bl sub_80306A8
	b _080338B4
_080336B2:
	ldr r0, [r6]
	movs r4, 0xD7
	lsls r4, 2
	adds r0, r4
	bl sub_8006518
	ldr r1, [r6]
	movs r5, 0x87
	lsls r5, 2
	adds r0, r1, r5
	adds r1, r4
	ldr r3, _080336F0
	ldr r2, _080336F4
_080336CC:
	str r2, [sp]
	movs r2, 0x1
	str r2, [sp, 0x4]
	movs r2, 0
	str r2, [sp, 0x8]
	str r2, [sp, 0xC]
	movs r2, 0x3
	bl SetMenuItems
	bl sub_803092C
_080336E2:
	ldr r0, [r6]
	adds r0, r5
	movs r1, 0x3
	movs r2, 0x1
	bl sub_8035CF4
	b _080338B4
	.align 2, 0
_080336F0: .4byte gUnknown_80E231C
_080336F4: .4byte gUnknown_80E234C
_080336F8:
	ldr r0, _08033718
_080336FA:
	ldr r3, _0803371C
_080336FC:
	movs r2, 0
	str r2, [sp]
	movs r1, 0x4
	str r1, [sp, 0x4]
	str r2, [sp, 0x8]
	str r2, [sp, 0xC]
	adds r1, 0xFD
	str r1, [sp, 0x10]
	movs r1, 0
	movs r2, 0x6
	bl sub_8014248
	b _080338B4
	.align 2, 0
_08033718: .4byte gUnknown_80E352C
_0803371C: .4byte gUnknown_80E2290
_08033720:
	ldr r0, _08033724
	b _0803388E
	.align 2, 0
_08033724: .4byte gUnknown_80E355C
_08033728:
	ldr r0, _0803372C
	b _0803388E
	.align 2, 0
_0803372C: .4byte gUnknown_80E35AC
_08033730:
	ldr r0, _08033734
	b _0803388E
	.align 2, 0
_08033734: .4byte gUnknown_80E35E8
_08033738:
	ldr r0, [r6]
	ldr r0, [r0, 0x40]
	cmp r0, 0x6
	bne _08033748
	ldr r0, _08033744
	b _0803374A
	.align 2, 0
_08033744: .4byte gUnknown_80E360C
_08033748:
	ldr r0, _08033768
_0803374A:
	ldr r3, _0803376C
	movs r2, 0
	str r2, [sp]
	movs r1, 0x4
	str r1, [sp, 0x4]
	str r2, [sp, 0x8]
	str r2, [sp, 0xC]
	adds r1, 0xFD
	str r1, [sp, 0x10]
	movs r1, 0
	movs r2, 0xB
	bl sub_8014248
	b _080338B4
	.align 2, 0
_08033768: .4byte gUnknown_80E3644
_0803376C: .4byte gUnknown_80E236C
_08033770:
	ldr r0, _08033780
	ldr r1, [r6]
	ldr r5, _08033784
	adds r1, r5
	ldr r2, [r1]
	ldr r3, _08033788
	b _08033858
	.align 2, 0
_08033780: .4byte gUnknown_80E367C
_08033784: .4byte 0x00000564
_08033788: .4byte gUnknown_80E25B4
_0803378C:
	ldr r0, [r6]
	ldr r1, _080337A4
	adds r0, r1
	ldr r0, [r0]
	cmp r0, 0x24
	beq _080337BC
	cmp r0, 0x24
	bgt _080337A8
	cmp r0, 0x23
	beq _080337B2
	b _080338B4
	.align 2, 0
_080337A4: .4byte 0x00000564
_080337A8:
	cmp r0, 0x25
	beq _080337C4
	cmp r0, 0x26
	beq _080337CC
	b _080338B4
_080337B2:
	ldr r0, _080337B8
	b _0803388E
	.align 2, 0
_080337B8: .4byte gUnknown_80E3690
_080337BC:
	ldr r0, _080337C0
	b _0803388E
	.align 2, 0
_080337C0: .4byte gUnknown_80E3818
_080337C4:
	ldr r0, _080337C8
	b _0803388E
	.align 2, 0
_080337C8: .4byte gUnknown_80E3998
_080337CC:
	ldr r0, _080337D0
	b _0803388E
	.align 2, 0
_080337D0: .4byte gUnknown_80E3B1C
_080337D4:
	ldr r0, _080337E4
	ldr r1, [r6]
	ldr r2, _080337E8
	adds r1, r2
	ldr r2, [r1]
	ldr r3, _080337EC
	b _08033858
	.align 2, 0
_080337E4: .4byte gUnknown_80E367C
_080337E8: .4byte 0x00000564
_080337EC: .4byte gUnknown_80E2554
_080337F0:
	ldr r0, [r6]
	ldr r3, _08033808
	adds r0, r3
	ldr r0, [r0]
	subs r0, 0x1E
	cmp r0, 0x4
	bhi _080338B4
	lsls r0, 2
	ldr r1, _0803380C
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08033808: .4byte 0x00000564
_0803380C: .4byte _08033810
	.align 2, 0
_08033810:
	.4byte _08033824
	.4byte _0803382C
	.4byte _0803383C
	.4byte _08033834
	.4byte _08033844
_08033824:
	ldr r0, _08033828
	b _0803388E
	.align 2, 0
_08033828: .4byte gUnknown_80E3BF8
_0803382C:
	ldr r0, _08033830
	b _0803388E
	.align 2, 0
_08033830: .4byte gUnknown_80E3DE4
_08033834:
	ldr r0, _08033838
	b _0803388E
	.align 2, 0
_08033838: .4byte gUnknown_80E3E98
_0803383C:
	ldr r0, _08033840
	b _0803388E
	.align 2, 0
_08033840: .4byte gUnknown_80E4014
_08033844:
	ldr r0, _08033848
	b _0803388E
	.align 2, 0
_08033848: .4byte gUnknown_80E4130
_0803384C:
	ldr r0, _08033870
	ldr r1, [r6]
	ldr r4, _08033874
	adds r1, r4
	ldr r2, [r1]
	ldr r3, _08033878
_08033858:
	movs r4, 0
	str r4, [sp]
	movs r1, 0x4
	str r1, [sp, 0x4]
	str r4, [sp, 0x8]
	str r4, [sp, 0xC]
_08033864:
	adds r1, 0xFD
	str r1, [sp, 0x10]
	movs r1, 0
	bl sub_8014248
	b _080338B4
	.align 2, 0
_08033870: .4byte gUnknown_80E367C
_08033874: .4byte 0x00000564
_08033878: .4byte gUnknown_80E24F8
_0803387C:
	ldr r0, [r6]
	ldr r5, _0803389C
	adds r0, r5
	ldr r0, [r0]
	cmp r0, 0x1A
	beq _080338A8
	cmp r0, 0x1D
	bne _080338B4
	ldr r0, _080338A0
_0803388E:
	ldr r3, _080338A4
	movs r1, 0
	movs r2, 0
	bl sub_80141B4
	b _080338B4
	.align 2, 0
_0803389C: .4byte 0x00000564
_080338A0: .4byte gUnknown_80E41DC
_080338A4: .4byte 0x00000101
_080338A8:
	ldr r0, _080338BC
	ldr r3, _080338C0
	movs r1, 0
	movs r2, 0
	bl sub_80141B4
_080338B4:
	add sp, 0x68
	pop {r4-r6}
	pop {r0}
	bx r0
	.align 2, 0
_080338BC: .4byte gUnknown_80E4314
_080338C0: .4byte 0x00000101
	thumb_func_end sub_8032828

	thumb_func_start sub_80338C4
sub_80338C4:
	push {lr}
	ldr r1, _080338D8
	ldr r1, [r1]
	str r0, [r1]
	bl nullsub_40
	bl sub_8032828
	pop {r0}
	bx r0
	.align 2, 0
_080338D8: .4byte gUnknown_203B33C
	thumb_func_end sub_80338C4

	thumb_func_start sub_80338DC
sub_80338DC:
	push {lr}
	cmp r0, 0x10
	bls _080338E4
	b _080339BC
_080338E4:
	lsls r0, 2
	ldr r1, _080338F0
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080338F0: .4byte _080338F4
	.align 2, 0
_080338F4:
	.4byte _080339BC
	.4byte _08033998
	.4byte _08033940
	.4byte _08033938
	.4byte _08033948
	.4byte _08033998
	.4byte _08033950
	.4byte _08033958
	.4byte _08033960
	.4byte _08033968
	.4byte _08033970
	.4byte _08033978
	.4byte _08033980
	.4byte _08033990
	.4byte _08033998
	.4byte _080339B0
	.4byte _08033988
_08033938:
	ldr r0, _0803393C
	b _0803399A
	.align 2, 0
_0803393C: .4byte gUnknown_80E44A4
_08033940:
	ldr r0, _08033944
	b _0803399A
	.align 2, 0
_08033944: .4byte gUnknown_80E4500
_08033948:
	ldr r0, _0803394C
	b _0803399A
	.align 2, 0
_0803394C: .4byte gUnknown_80E4550
_08033950:
	ldr r0, _08033954
	b _0803399A
	.align 2, 0
_08033954: .4byte gUnknown_80E45B4
_08033958:
	ldr r0, _0803395C
	b _0803399A
	.align 2, 0
_0803395C: .4byte gUnknown_80E460C
_08033960:
	ldr r0, _08033964
	b _0803399A
	.align 2, 0
_08033964: .4byte gUnknown_80E4650
_08033968:
	ldr r0, _0803396C
	b _0803399A
	.align 2, 0
_0803396C: .4byte gUnknown_80E468C
_08033970:
	ldr r0, _08033974
	b _0803399A
	.align 2, 0
_08033974: .4byte gUnknown_80E46C8
_08033978:
	ldr r0, _0803397C
	b _0803399A
	.align 2, 0
_0803397C: .4byte gUnknown_80E4704
_08033980:
	ldr r0, _08033984
	b _0803399A
	.align 2, 0
_08033984: .4byte gUnknown_80E4744
_08033988:
	ldr r0, _0803398C
	b _0803399A
	.align 2, 0
_0803398C: .4byte gUnknown_80E4788
_08033990:
	ldr r0, _08033994
	b _0803399A
	.align 2, 0
_08033994: .4byte gUnknown_80E47D8
_08033998:
	ldr r0, _080339A8
_0803399A:
	ldr r3, _080339AC
	movs r1, 0
	movs r2, 0
	bl sub_80141B4
	b _080339BC
	.align 2, 0
_080339A8: .4byte gUnknown_80E4480
_080339AC: .4byte 0x00000101
_080339B0:
	ldr r0, _080339C0
	ldr r3, _080339C4
	movs r1, 0
	movs r2, 0
	bl sub_80141B4
_080339BC:
	pop {r0}
	bx r0
	.align 2, 0
_080339C0: .4byte gUnknown_80E482C
_080339C4: .4byte 0x00000101
	thumb_func_end sub_80338DC

	thumb_func_start sub_80339C8
sub_80339C8:
	push {lr}
	sub sp, 0x4
	mov r0, sp
	bl sub_80144A4
	cmp r0, 0
	bne _08033A24
	ldr r0, _080339F4
	ldr r0, [r0]
	movs r1, 0xA7
	lsls r1, 3
	adds r0, r1
	ldr r1, _080339F8
	strh r1, [r0]
	ldr r0, [sp]
	cmp r0, 0x1
	beq _08033A0E
	cmp r0, 0x1
	bgt _080339FC
	cmp r0, 0
	beq _08033A06
	b _08033A24
	.align 2, 0
_080339F4: .4byte gUnknown_203B33C
_080339F8: .4byte 0x0000ffff
_080339FC:
	cmp r0, 0x8
	beq _08033A1E
	cmp r0, 0x17
	beq _08033A16
	b _08033A24
_08033A06:
	movs r0, 0x3
	bl sub_80338C4
	b _08033A24
_08033A0E:
	movs r0, 0x4
	bl sub_80338C4
	b _08033A24
_08033A16:
	movs r0, 0x78
	bl sub_80338C4
	b _08033A24
_08033A1E:
	movs r0, 0x2
	bl sub_80338C4
_08033A24:
	add sp, 0x4
	pop {r0}
	bx r0
	thumb_func_end sub_80339C8

	thumb_func_start sub_8033A2C
sub_8033A2C:
	push {lr}
	sub sp, 0x4
	mov r0, sp
	bl sub_80144A4
	cmp r0, 0
	beq _08033A3C
	b _08033B86
_08033A3C:
	ldr r2, _08033A58
	ldr r1, [r2]
	movs r0, 0x8
	str r0, [r1, 0x40]
	ldr r0, [sp]
	subs r0, 0x3
	cmp r0, 0x11
	bls _08033A4E
	b _08033B86
_08033A4E:
	lsls r0, 2
	ldr r1, _08033A5C
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08033A58: .4byte gUnknown_203B33C
_08033A5C: .4byte _08033A60
	.align 2, 0
_08033A60:
	.4byte _08033ACA
	.4byte _08033AEC
	.4byte _08033B86
	.4byte _08033B86
	.4byte _08033B86
	.4byte _08033B80
	.4byte _08033B86
	.4byte _08033B86
	.4byte _08033B86
	.4byte _08033B86
	.4byte _08033B86
	.4byte _08033B86
	.4byte _08033B86
	.4byte _08033B86
	.4byte _08033AA8
	.4byte _08033B14
	.4byte _08033B3E
	.4byte _08033B68
_08033AA8:
	ldr r0, [r2]
	movs r1, 0x2
	str r1, [r0, 0x40]
	movs r1, 0xA5
	lsls r1, 3
	adds r0, r1
	movs r1, 0x11
	str r1, [r0]
	movs r0, 0x1
	bl sub_8095324
	cmp r0, 0
	beq _08033B0C
	movs r0, 0x31
	bl sub_80338C4
	b _08033B86
_08033ACA:
	ldr r0, [r2]
	movs r1, 0x3
	str r1, [r0, 0x40]
	movs r2, 0xA5
	lsls r2, 3
	adds r0, r2
	str r1, [r0]
	bl sub_8095190
	movs r1, 0x1
	negs r1, r1
	cmp r0, r1
	bne _08033B36
	movs r0, 0xF
	bl sub_80338C4
	b _08033B86
_08033AEC:
	ldr r0, [r2]
	movs r1, 0x4
	str r1, [r0, 0x40]
	movs r2, 0xA5
	lsls r2, 3
	adds r0, r2
	str r1, [r0]
	movs r0, 0x4
	bl sub_8095324
	cmp r0, 0
	beq _08033B0C
	movs r0, 0x1C
	bl sub_80338C4
	b _08033B86
_08033B0C:
	movs r0, 0x22
	bl sub_80338C4
	b _08033B86
_08033B14:
	ldr r0, [r2]
	movs r1, 0x5
	str r1, [r0, 0x40]
	movs r1, 0xA5
	lsls r1, 3
	adds r0, r1
	movs r1, 0x12
	str r1, [r0]
	movs r0, 0x5
	bl sub_8095324
	cmp r0, 0
	beq _08033B36
	movs r0, 0x3D
	bl sub_80338C4
	b _08033B86
_08033B36:
	movs r0, 0xE
	bl sub_80338C4
	b _08033B86
_08033B3E:
	ldr r0, [r2]
	movs r1, 0x6
	str r1, [r0, 0x40]
	movs r2, 0xA5
	lsls r2, 3
	adds r0, r2
	movs r1, 0x13
	str r1, [r0]
	movs r0, 0x5
	bl sub_8095324
	cmp r0, 0
	bne _08033B60
	movs r0, 0x51
	bl sub_80338C4
	b _08033B86
_08033B60:
	movs r0, 0x5B
	bl sub_80338C4
	b _08033B86
_08033B68:
	ldr r0, [r2]
	movs r1, 0x7
	str r1, [r0, 0x40]
	movs r1, 0xA5
	lsls r1, 3
	adds r0, r1
	movs r1, 0x14
	str r1, [r0]
	movs r0, 0x52
	bl sub_80338C4
	b _08033B86
_08033B80:
	movs r0, 0x1
	bl sub_80338C4
_08033B86:
	add sp, 0x4
	pop {r0}
	bx r0
	thumb_func_end sub_8033A2C

	thumb_func_start sub_8033B8C
sub_8033B8C:
	push {lr}
	sub sp, 0x4
	mov r0, sp
	bl sub_80144A4
	cmp r0, 0
	bne _08033C4C
	ldr r2, [sp]
	cmp r2, 0xC
	bgt _08033BAA
	cmp r2, 0xB
	bge _08033BB0
	cmp r2, 0x8
	beq _08033C46
	b _08033C4C
_08033BAA:
	cmp r2, 0xD
	beq _08033BF4
	b _08033C4C
_08033BB0:
	ldr r0, _08033BD4
	ldr r0, [r0]
	ldr r1, _08033BD8
	adds r2, r0, r1
	movs r1, 0xB
	str r1, [r2]
	movs r3, 0xA5
	lsls r3, 3
	adds r0, r3
	ldr r0, [r0]
	cmp r0, 0x4
	beq _08033BEC
	cmp r0, 0x4
	bhi _08033BDC
	cmp r0, 0x3
	beq _08033BE4
	b _08033C4C
	.align 2, 0
_08033BD4: .4byte gUnknown_203B33C
_08033BD8: .4byte 0x00000524
_08033BDC:
	cmp r0, 0x12
	bhi _08033C4C
	cmp r0, 0x11
	bcc _08033C4C
_08033BE4:
	movs r0, 0x5
	bl sub_80338C4
	b _08033C4C
_08033BEC:
	movs r0, 0x23
	bl sub_80338C4
	b _08033C4C
_08033BF4:
	ldr r0, _08033C14
	ldr r0, [r0]
	ldr r3, _08033C18
	adds r1, r0, r3
	str r2, [r1]
	movs r1, 0xA5
	lsls r1, 3
	adds r0, r1
	ldr r0, [r0]
	cmp r0, 0x4
	beq _08033C3E
	cmp r0, 0x4
	bhi _08033C1C
	cmp r0, 0x3
	beq _08033C26
	b _08033C4C
	.align 2, 0
_08033C14: .4byte gUnknown_203B33C
_08033C18: .4byte 0x00000524
_08033C1C:
	cmp r0, 0x11
	beq _08033C2E
	cmp r0, 0x12
	beq _08033C36
	b _08033C4C
_08033C26:
	movs r0, 0x19
	bl sub_80338C4
	b _08033C4C
_08033C2E:
	movs r0, 0x39
	bl sub_80338C4
	b _08033C4C
_08033C36:
	movs r0, 0x43
	bl sub_80338C4
	b _08033C4C
_08033C3E:
	movs r0, 0x2D
	bl sub_80338C4
	b _08033C4C
_08033C46:
	movs r0, 0x1
	bl sub_80338C4
_08033C4C:
	add sp, 0x4
	pop {r0}
	bx r0
	thumb_func_end sub_8033B8C

	thumb_func_start sub_8033C54
sub_8033C54:
	push {lr}
	sub sp, 0x4
	mov r0, sp
	bl sub_80144A4
	cmp r0, 0
	bne _08033CA2
	ldr r0, [sp]
	cmp r0, 0x6
	beq _08033C6E
	cmp r0, 0x8
	beq _08033C9C
	b _08033CA2
_08033C6E:
	ldr r0, _08033C88
	ldr r0, [r0]
	movs r1, 0xA5
	lsls r1, 3
	adds r0, r1
	ldr r0, [r0]
	cmp r0, 0x4
	beq _08033C94
	cmp r0, 0x4
	bhi _08033C8C
	cmp r0, 0x3
	beq _08033C94
	b _08033CA2
	.align 2, 0
_08033C88: .4byte gUnknown_203B33C
_08033C8C:
	cmp r0, 0x11
	beq _08033C94
	cmp r0, 0x12
	bne _08033CA2
_08033C94:
	movs r0, 0xD
	bl sub_80338C4
	b _08033CA2
_08033C9C:
	movs r0, 0x1
	bl sub_80338C4
_08033CA2:
	add sp, 0x4
	pop {r0}
	bx r0
	thumb_func_end sub_8033C54

	thumb_func_start nullsub_41
nullsub_41:
	bx lr
	thumb_func_end nullsub_41

	thumb_func_start sub_8033CAC
sub_8033CAC:
	push {r4,lr}
	sub sp, 0x4
	mov r0, sp
	bl sub_80144A4
	cmp r0, 0
	bne _08033D40
	ldr r4, _08033CDC
	ldr r1, [r4]
	ldr r0, [r1, 0x44]
	cmp r0, 0
	bne _08033D36
	movs r2, 0xA5
	lsls r2, 3
	adds r0, r1, r2
	ldr r0, [r0]
	cmp r0, 0x4
	beq _08033D2E
	cmp r0, 0x4
	bhi _08033CE0
	cmp r0, 0x3
	beq _08033CEA
	b _08033D40
	.align 2, 0
_08033CDC: .4byte gUnknown_203B33C
_08033CE0:
	cmp r0, 0x11
	beq _08033CF2
	cmp r0, 0x12
	beq _08033CFA
	b _08033D40
_08033CEA:
	movs r0, 0x16
	bl sub_80338C4
	b _08033D40
_08033CF2:
	movs r0, 0x37
	bl sub_80338C4
	b _08033D40
_08033CFA:
	bl sub_800D588
	lsls r0, 24
	cmp r0, 0
	beq _08033D12
	ldr r0, [r4]
	movs r1, 0xB4
	lsls r1, 1
	adds r0, r1
	movs r2, 0
	ldrsh r0, [r0, r2]
	b _08033D1A
_08033D12:
	ldr r0, [r4]
	adds r0, 0xE0
	movs r1, 0
	ldrsh r0, [r0, r1]
_08033D1A:
	cmp r0, 0
	beq _08033D26
	movs r0, 0x3F
	bl sub_80338C4
	b _08033D40
_08033D26:
	movs r0, 0x40
	bl sub_80338C4
	b _08033D40
_08033D2E:
	movs r0, 0x2B
	bl sub_80338C4
	b _08033D40
_08033D36:
	bl sub_80338DC
	movs r0, 0x8
	bl sub_80338C4
_08033D40:
	add sp, 0x4
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_8033CAC

	thumb_func_start sub_8033D48
sub_8033D48:
	push {lr}
	sub sp, 0x4
	mov r0, sp
	bl sub_80144A4
	cmp r0, 0
	bne _08033D5C
	movs r0, 0x1
	bl sub_80338C4
_08033D5C:
	add sp, 0x4
	pop {r0}
	bx r0
	thumb_func_end sub_8033D48

	thumb_func_start nullsub_42
nullsub_42:
	bx lr
	thumb_func_end nullsub_42

	thumb_func_start nullsub_43
nullsub_43:
	bx lr
	thumb_func_end nullsub_43

	thumb_func_start nullsub_44
nullsub_44:
	bx lr
	thumb_func_end nullsub_44

	thumb_func_start nullsub_45
nullsub_45:
	bx lr
	thumb_func_end nullsub_45

	thumb_func_start sub_8033D74
sub_8033D74:
	push {lr}
	sub sp, 0x4
	mov r0, sp
	bl sub_80144A4
	cmp r0, 0
	bne _08033D8E
	movs r0, 0x17
	bl sub_80338C4
	movs r0, 0
	bl sub_8012574
_08033D8E:
	add sp, 0x4
	pop {r0}
	bx r0
	thumb_func_end sub_8033D74

	thumb_func_start sub_8033D94
sub_8033D94:
	push {lr}
	sub sp, 0x4
	mov r0, sp
	bl sub_80144A4
	cmp r0, 0
	bne _08033DB6
	bl sub_8012600
	lsls r0, 24
	cmp r0, 0
	bne _08033DB6
	bl sub_8012750
	movs r0, 0x18
	bl sub_80338C4
_08033DB6:
	add sp, 0x4
	pop {r0}
	bx r0
	thumb_func_end sub_8033D94

	thumb_func_start sub_8033DBC
sub_8033DBC:
	push {r4,lr}
	sub sp, 0x44
	bl sub_80154F0
	adds r4, r0, 0
	add r0, sp, 0x14
	movs r1, 0
	movs r2, 0x30
	bl MemoryFill8
	cmp r4, 0x2
	bne _08033DD6
	b _08033F38
_08033DD6:
	cmp r4, 0x3
	beq _08033DDC
	b _08033F58
_08033DDC:
	ldr r2, _08033DF4
	ldr r1, _08033DF8
	ldr r0, [r1]
	movs r3, 0xA5
	lsls r3, 3
	adds r0, r3
	ldr r0, [r0]
	cmp r0, 0x3
	beq _08033DFC
	cmp r0, 0x12
	beq _08033E00
	b _08033E02
	.align 2, 0
_08033DF4: .4byte 0x0000ffdc
_08033DF8: .4byte gUnknown_203B33C
_08033DFC:
	movs r2, 0x1C
	b _08033E02
_08033E00:
	movs r2, 0x1E
_08033E02:
	ldr r1, [r1]
	adds r1, 0x8
	adds r0, r2, 0
	add r2, sp, 0x14
	bl sub_8039068
	subs r0, 0x7
	cmp r0, 0x11
	bls _08033E16
	b _08033F2E
_08033E16:
	lsls r0, 2
	ldr r1, _08033E20
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08033E20: .4byte _08033E24
	.align 2, 0
_08033E24:
	.4byte _08033EA0
	.4byte _08033F2E
	.4byte _08033EE0
	.4byte _08033F2E
	.4byte _08033F2E
	.4byte _08033F2E
	.4byte _08033F2E
	.4byte _08033F2E
	.4byte _08033F2E
	.4byte _08033F2E
	.4byte _08033E6C
	.4byte _08033E98
	.4byte _08033ED8
	.4byte _08033F2E
	.4byte _08033F2E
	.4byte _08033EA8
	.4byte _08033EFC
	.4byte _08033F2E
_08033E6C:
	ldr r0, _08033E90
	ldr r3, _08033E94
	movs r2, 0
	str r2, [sp]
	movs r1, 0x4
	str r1, [sp, 0x4]
	str r2, [sp, 0x8]
	str r2, [sp, 0xC]
	adds r1, 0xFD
	str r1, [sp, 0x10]
	movs r1, 0
	movs r2, 0x6
	bl sub_8014248
	movs r0, 0x1B
	bl sub_80338C4
	b _08033F2E
	.align 2, 0
_08033E90: .4byte gUnknown_80E48A8
_08033E94: .4byte gUnknown_80E2290
_08033E98:
	ldr r0, _08033E9C
	b _08033EE2
	.align 2, 0
_08033E9C: .4byte gUnknown_80E48E8
_08033EA0:
	ldr r0, _08033EA4
	b _08033EE2
	.align 2, 0
_08033EA4: .4byte gUnknown_80E460C
_08033EA8:
	ldr r0, [sp, 0x24]
	bl sub_8095274
	add r1, sp, 0x14
	movs r0, 0x2
	strb r0, [r1]
	adds r0, r1, 0
	bl sub_80951BC
	ldr r0, _08033ED0
	ldr r3, _08033ED4
	movs r1, 0
	movs r2, 0
	bl sub_80141B4
	movs r0, 0x16
	bl sub_80338C4
	b _08033F2E
	.align 2, 0
_08033ED0: .4byte gUnknown_80E4928
_08033ED4: .4byte 0x00000101
_08033ED8:
	ldr r0, _08033EDC
	b _08033EE2
	.align 2, 0
_08033EDC: .4byte gUnknown_80E4964
_08033EE0:
	ldr r0, _08033EF4
_08033EE2:
	ldr r3, _08033EF8
	movs r1, 0
	movs r2, 0
	bl sub_80141B4
	movs r0, 0x8
	bl sub_80338C4
	b _08033F2E
	.align 2, 0
_08033EF4: .4byte gUnknown_80E499C
_08033EF8: .4byte 0x00000101
_08033EFC:
	add r1, sp, 0x14
	movs r0, 0x5
	strb r0, [r1]
	adds r0, r1, 0
	bl sub_80951FC
	ldr r1, [sp, 0x24]
	movs r0, 0x1
	bl sub_809539C
	lsls r0, 24
	lsrs r0, 24
	bl sub_8095228
	movs r1, 0x7
	strb r1, [r0]
	ldr r0, _08033F34
	ldr r0, [r0]
	movs r1, 0
	movs r2, 0x5C
	bl MemoryFill8
	movs r0, 0x40
	bl sub_80338C4
_08033F2E:
	bl sub_80155F0
	b _08033F58
	.align 2, 0
_08033F34: .4byte gUnknown_203B484
_08033F38:
	bl sub_80155F0
	bl ResetUnusedInputStruct
	ldr r0, _08033F60
	ldr r0, [r0]
	movs r1, 0xEF
	lsls r1, 2
	adds r0, r1
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	movs r0, 0x1
	bl sub_80338C4
_08033F58:
	add sp, 0x44
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08033F60: .4byte gUnknown_203B33C
	thumb_func_end sub_8033DBC

	thumb_func_start sub_8033F64
sub_8033F64:
	push {lr}
	sub sp, 0x4
	mov r0, sp
	bl sub_80144A4
	cmp r0, 0
	bne _08033FAE
	ldr r0, [sp]
	cmp r0, 0x6
	beq _08033F7E
	cmp r0, 0x8
	beq _08033FA8
	b _08033FAE
_08033F7E:
	ldr r0, _08033F94
	ldr r0, [r0]
	movs r1, 0xA5
	lsls r1, 3
	adds r0, r1
	ldr r0, [r0]
	cmp r0, 0x3
	beq _08033F98
	cmp r0, 0x12
	beq _08033FA0
	b _08033FAE
	.align 2, 0
_08033F94: .4byte gUnknown_203B33C
_08033F98:
	movs r0, 0x19
	bl sub_80338C4
	b _08033FAE
_08033FA0:
	movs r0, 0x43
	bl sub_80338C4
	b _08033FAE
_08033FA8:
	movs r0, 0x1
	bl sub_80338C4
_08033FAE:
	add sp, 0x4
	pop {r0}
	bx r0
	thumb_func_end sub_8033F64

	thumb_func_start sub_8033FB4
sub_8033FB4:
	push {lr}
	sub sp, 0x4
	mov r0, sp
	bl sub_80144A4
	cmp r0, 0
	bne _08033FDE
	ldr r0, [sp]
	cmp r0, 0x6
	bne _08033FD0
	movs r0, 0xE
	bl sub_80338C4
	b _08033FDE
_08033FD0:
	cmp r0, 0x6
	blt _08033FDE
	cmp r0, 0x8
	bgt _08033FDE
	movs r0, 0x1
	bl sub_80338C4
_08033FDE:
	add sp, 0x4
	pop {r0}
	bx r0
	thumb_func_end sub_8033FB4

	thumb_func_start sub_8033FE4
sub_8033FE4:
	push {r4,r5,lr}
	movs r0, 0x1
	bl sub_8030768
	cmp r0, 0x3
	beq _0803400C
	cmp r0, 0x3
	bhi _08033FFA
	cmp r0, 0x2
	beq _08034000
	b _0803406A
_08033FFA:
	cmp r0, 0x4
	beq _08034028
	b _0803406A
_08034000:
	bl sub_803084C
	movs r0, 0x1
	bl sub_80338C4
	b _0803406A
_0803400C:
	bl sub_80307EC
	ldr r1, _08034024
	ldr r1, [r1]
	movs r2, 0x86
	lsls r2, 2
	adds r1, r2
	strb r0, [r1]
	movs r0, 0x1E
	bl sub_80338C4
	b _0803406A
	.align 2, 0
_08034024: .4byte gUnknown_203B33C
_08034028:
	ldr r4, _08034070
	ldr r1, [r4]
	movs r0, 0x1D
	str r0, [r1, 0x4]
	bl sub_80307EC
	ldr r1, [r4]
	movs r5, 0x86
	lsls r5, 2
	adds r1, r5
	strb r0, [r1]
	ldr r0, [r4]
	movs r1, 0xEF
	lsls r1, 2
	adds r0, r1
	bl sub_8006518
	bl ResetUnusedInputStruct
	movs r0, 0
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	ldr r0, [r4]
	adds r0, r5
	ldrb r0, [r0]
	movs r1, 0
	bl sub_8030D40
	movs r0, 0x1F
	bl sub_80338C4
_0803406A:
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_08034070: .4byte gUnknown_203B33C
	thumb_func_end sub_8033FE4

	thumb_func_start sub_8034074
sub_8034074:
	push {r4,lr}
	sub sp, 0x4
	movs r0, 0x1
	negs r0, r0
	str r0, [sp]
	movs r0, 0
	bl sub_8030768
	ldr r4, _080340B8
	ldr r0, [r4]
	movs r1, 0xC3
	lsls r1, 2
	adds r0, r1
	bl sub_8012FD8
	lsls r0, 24
	cmp r0, 0
	bne _080340A6
	ldr r0, [r4]
	movs r1, 0xC3
	lsls r1, 2
	adds r0, r1
	mov r1, sp
	bl sub_8013114
_080340A6:
	ldr r0, [sp]
	cmp r0, 0x8
	beq _08034108
	cmp r0, 0x8
	bgt _080340BC
	cmp r0, 0x5
	beq _08034108
	b _08034124
	.align 2, 0
_080340B8: .4byte gUnknown_203B33C
_080340BC:
	cmp r0, 0x9
	beq _080340C6
	cmp r0, 0xA
	beq _080340D2
	b _08034124
_080340C6:
	bl sub_803084C
	movs r0, 0x20
	bl sub_80338C4
	b _08034124
_080340D2:
	ldr r0, [r4]
	movs r1, 0x7E
	str r1, [r0, 0x4]
	movs r1, 0xEF
	lsls r1, 2
	adds r0, r1
	bl sub_8006518
	bl ResetUnusedInputStruct
	movs r0, 0
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	ldr r0, [r4]
	movs r1, 0x86
	lsls r1, 2
	adds r0, r1
	ldrb r0, [r0]
	movs r1, 0
	bl sub_8030D40
	movs r0, 0x1F
	bl sub_80338C4
	b _08034124
_08034108:
	ldr r0, _0803412C
	ldr r0, [r0]
	movs r1, 0xD7
	lsls r1, 2
	adds r0, r1
	movs r1, 0x2
	bl sub_8035CC0
	movs r0, 0x1
	bl sub_8030810
	movs r0, 0x1D
	bl sub_80338C4
_08034124:
	add sp, 0x4
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0803412C: .4byte gUnknown_203B33C
	thumb_func_end sub_8034074

	thumb_func_start sub_8034130
sub_8034130:
	push {r4,lr}
	bl sub_8030DA0
	cmp r0, 0x3
	bhi _08034184
	cmp r0, 0x2
	bcc _08034184
	bl sub_8030DE4
	bl ResetUnusedInputStruct
	ldr r4, _0803417C
	ldr r0, [r4]
	movs r1, 0xEF
	lsls r1, 2
	adds r0, r1
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	bl sub_803092C
	ldr r4, [r4]
	ldr r0, [r4, 0x4]
	cmp r0, 0x7E
	bne _08034180
	movs r1, 0x87
	lsls r1, 2
	adds r0, r4, r1
	movs r1, 0x3
	movs r2, 0x1
	bl sub_8035CF4
	movs r0, 0x1E
	bl sub_80338C4
	b _08034184
	.align 2, 0
_0803417C: .4byte gUnknown_203B33C
_08034180:
	bl sub_80338C4
_08034184:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_8034130

	thumb_func_start sub_803418C
sub_803418C:
	push {r4,r5,lr}
	movs r0, 0x1
	bl sub_8023A94
	cmp r0, 0x3
	beq _080341D0
	cmp r0, 0x3
	bhi _080341A2
	cmp r0, 0x2
	beq _080341A8
	b _08034248
_080341A2:
	cmp r0, 0x4
	beq _08034204
	b _08034248
_080341A8:
	bl sub_8023C60
	movs r0, 0x1
	bl sub_80338C4
	bl sub_8035D1C
	ldr r0, _080341C8
	ldr r0, [r0]
	movs r1, 0xA7
	lsls r1, 3
	adds r0, r1
	ldr r1, _080341CC
	strh r1, [r0]
	b _08034248
	.align 2, 0
_080341C8: .4byte gUnknown_203B33C
_080341CC: .4byte 0x0000ffff
_080341D0:
	bl sub_8023B44
	ldr r1, _080341F4
	ldr r1, [r1]
	movs r3, 0xA7
	lsls r3, 3
	adds r2, r1, r3
	strh r0, [r2]
	ldr r0, _080341F8
	adds r1, r0
	ldr r0, [r1]
	cmp r0, 0xE
	bne _080341FC
	movs r0, 0x9
	bl sub_80338C4
	b _08034248
	.align 2, 0
_080341F4: .4byte gUnknown_203B33C
_080341F8: .4byte 0x00000524
_080341FC:
	movs r0, 0x27
	bl sub_80338C4
	b _08034248
_08034204:
	ldr r4, _08034250
	ldr r1, [r4]
	movs r0, 0x26
	str r0, [r1, 0x4]
	bl sub_8023B44
	adds r2, r0, 0
	ldr r0, [r4]
	movs r5, 0xA7
	lsls r5, 3
	adds r1, r0, r5
	strh r2, [r1]
	movs r1, 0xEF
	lsls r1, 2
	adds r0, r1
	bl sub_8006518
	bl ResetUnusedInputStruct
	movs r0, 0
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	ldr r0, [r4]
	adds r0, r5
	movs r3, 0
	ldrsh r0, [r0, r3]
	movs r1, 0
	bl sub_8024458
	movs r0, 0x28
	bl sub_80338C4
_08034248:
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_08034250: .4byte gUnknown_203B33C
	thumb_func_end sub_803418C

	thumb_func_start sub_8034254
sub_8034254:
	push {r4,lr}
	sub sp, 0x4
	movs r0, 0x1
	negs r0, r0
	str r0, [sp]
	movs r0, 0
	bl sub_8023A94
	ldr r4, _08034298
	ldr r0, [r4]
	movs r1, 0xC3
	lsls r1, 2
	adds r0, r1
	bl sub_8012FD8
	lsls r0, 24
	cmp r0, 0
	bne _08034286
	ldr r0, [r4]
	movs r1, 0xC3
	lsls r1, 2
	adds r0, r1
	mov r1, sp
	bl sub_8013114
_08034286:
	ldr r0, [sp]
	cmp r0, 0x8
	beq _080342EA
	cmp r0, 0x8
	bgt _0803429C
	cmp r0, 0x5
	beq _080342EA
	b _08034304
	.align 2, 0
_08034298: .4byte gUnknown_203B33C
_0803429C:
	cmp r0, 0x9
	beq _080342A6
	cmp r0, 0xA
	beq _080342B2
	b _08034304
_080342A6:
	bl sub_8023C60
	movs r0, 0x29
	bl sub_80338C4
	b _08034304
_080342B2:
	ldr r0, [r4]
	movs r1, 0x7E
	str r1, [r0, 0x4]
	movs r1, 0xEF
	lsls r1, 2
	adds r0, r1
	bl sub_8006518
	bl ResetUnusedInputStruct
	movs r0, 0
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	ldr r0, [r4]
	movs r1, 0xA7
	lsls r1, 3
	adds r0, r1
	movs r1, 0
	ldrsh r0, [r0, r1]
	movs r1, 0
	bl sub_8024458
	movs r0, 0x28
	bl sub_80338C4
	b _08034304
_080342EA:
	ldr r0, _0803430C
	ldr r0, [r0]
	movs r1, 0xD7
	lsls r1, 2
	adds r0, r1
	movs r1, 0x3
	bl sub_8035CC0
	bl sub_8023DA4
	movs r0, 0x26
	bl sub_80338C4
_08034304:
	add sp, 0x4
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0803430C: .4byte gUnknown_203B33C
	thumb_func_end sub_8034254

	thumb_func_start sub_8034310
sub_8034310:
	push {r4,lr}
	bl sub_80244E4
	cmp r0, 0x1
	bne _08034320
	bl sub_802452C
	b _08034370
_08034320:
	cmp r0, 0x1
	bcc _08034370
	cmp r0, 0x3
	bhi _08034370
	bl sub_802453C
	bl ResetUnusedInputStruct
	ldr r4, _08034368
	ldr r0, [r4]
	movs r1, 0xEF
	lsls r1, 2
	adds r0, r1
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	movs r0, 0x1
	bl sub_8023B7C
	ldr r4, [r4]
	ldr r0, [r4, 0x4]
	cmp r0, 0x7E
	bne _0803436C
	movs r1, 0x87
	lsls r1, 2
	adds r0, r4, r1
	movs r1, 0x3
	movs r2, 0x1
	bl sub_8035CF4
	movs r0, 0x27
	bl sub_80338C4
	b _08034370
	.align 2, 0
_08034368: .4byte gUnknown_203B33C
_0803436C:
	bl sub_80338C4
_08034370:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_8034310

	thumb_func_start sub_8034378
sub_8034378:
	push {lr}
	sub sp, 0x4
	mov r0, sp
	bl sub_80144A4
	cmp r0, 0
	bne _080343BE
	ldr r0, [sp]
	cmp r0, 0x8
	beq _080343B8
	cmp r0, 0x10
	bne _080343BE
	ldr r0, _080343A8
	ldr r0, [r0]
	ldr r1, _080343AC
	adds r0, r1
	ldr r0, [r0]
	cmp r0, 0xE
	bne _080343B0
	movs r0, 0x9
	bl sub_80338C4
	b _080343BE
	.align 2, 0
_080343A8: .4byte gUnknown_203B33C
_080343AC: .4byte 0x00000524
_080343B0:
	movs r0, 0x5
	bl sub_80338C4
	b _080343BE
_080343B8:
	movs r0, 0x1
	bl sub_80338C4
_080343BE:
	add sp, 0x4
	pop {r0}
	bx r0
	thumb_func_end sub_8034378

	thumb_func_start sub_80343C4
sub_80343C4:
	push {lr}
	sub sp, 0x4
	mov r0, sp
	bl sub_80144A4
	cmp r0, 0
	bne _080343FE
	ldr r0, [sp]
	cmp r0, 0x7
	beq _080343F0
	cmp r0, 0x7
	bgt _080343E2
	cmp r0, 0x6
	beq _080343E8
	b _080343FE
_080343E2:
	cmp r0, 0x8
	beq _080343F8
	b _080343FE
_080343E8:
	movs r0, 0x5
	bl sub_80338C4
	b _080343FE
_080343F0:
	movs r0, 0x25
	bl sub_80338C4
	b _080343FE
_080343F8:
	movs r0, 0x1
	bl sub_80338C4
_080343FE:
	add sp, 0x4
	pop {r0}
	bx r0
	thumb_func_end sub_80343C4

	thumb_func_start sub_8034404
sub_8034404:
	push {lr}
	sub sp, 0x4
	mov r0, sp
	bl sub_80144A4
	cmp r0, 0
	bne _08034472
	ldr r0, [sp]
	cmp r0, 0xF
	beq _08034428
	cmp r0, 0xF
	bgt _08034422
	cmp r0, 0x8
	beq _0803446C
	b _08034472
_08034422:
	cmp r0, 0x10
	beq _08034444
	b _08034472
_08034428:
	movs r0, 0x3
	bl sub_8024108
	lsls r0, 24
	cmp r0, 0
	beq _0803443C
	movs r0, 0x24
	bl sub_80338C4
	b _08034472
_0803443C:
	movs r0, 0x25
	bl sub_80338C4
	b _08034472
_08034444:
	ldr r0, _0803445C
	ldr r0, [r0]
	ldr r1, _08034460
	adds r0, r1
	ldr r0, [r0]
	cmp r0, 0xE
	bne _08034464
	movs r0, 0x9
	bl sub_80338C4
	b _08034472
	.align 2, 0
_0803445C: .4byte gUnknown_203B33C
_08034460: .4byte 0x00000524
_08034464:
	movs r0, 0x5
	bl sub_80338C4
	b _08034472
_0803446C:
	movs r0, 0x1
	bl sub_80338C4
_08034472:
	add sp, 0x4
	pop {r0}
	bx r0
	thumb_func_end sub_8034404

	thumb_func_start sub_8034478
sub_8034478:
	push {lr}
	sub sp, 0x4
	mov r0, sp
	bl sub_80144A4
	cmp r0, 0
	bne _0803449A
	bl sub_8012600
	lsls r0, 24
	cmp r0, 0
	bne _0803449A
	bl sub_8012750
	movs r0, 0x2
	bl sub_80338C4
_0803449A:
	add sp, 0x4
	pop {r0}
	bx r0
	thumb_func_end sub_8034478

	thumb_func_start sub_80344A0
sub_80344A0:
	push {lr}
	sub sp, 0x4
	mov r0, sp
	bl sub_80144A4
	cmp r0, 0
	bne _080344BA
	movs r0, 0x2C
	bl sub_80338C4
	movs r0, 0
	bl sub_8012574
_080344BA:
	add sp, 0x4
	pop {r0}
	bx r0
	thumb_func_end sub_80344A0

	thumb_func_start sub_80344C0
sub_80344C0:
	push {lr}
	bl sub_8031DCC
	cmp r0, 0x1
	beq _080344F8
	cmp r0, 0x1
	bcc _080344FC
	cmp r0, 0x3
	bhi _080344FC
	bl sub_8031E10
	bl ResetUnusedInputStruct
	ldr r0, _080344F4
	ldr r0, [r0]
	movs r1, 0xEF
	lsls r1, 2
	adds r0, r1
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	movs r0, 0x2F
	bl sub_80338C4
	b _080344FC
	.align 2, 0
_080344F4: .4byte gUnknown_203B33C
_080344F8:
	bl sub_8031E00
_080344FC:
	pop {r0}
	bx r0
	thumb_func_end sub_80344C0

	thumb_func_start sub_8034500
sub_8034500:
	push {r4,r5,lr}
	movs r0, 0x1
	bl sub_8030768
	cmp r0, 0x3
	beq _08034528
	cmp r0, 0x3
	bhi _08034516
	cmp r0, 0x2
	beq _0803451C
	b _08034586
_08034516:
	cmp r0, 0x4
	beq _08034544
	b _08034586
_0803451C:
	bl sub_803084C
	movs r0, 0x1
	bl sub_80338C4
	b _08034586
_08034528:
	bl sub_80307EC
	ldr r1, _08034540
	ldr r1, [r1]
	movs r2, 0x86
	lsls r2, 2
	adds r1, r2
	strb r0, [r1]
	movs r0, 0x33
	bl sub_80338C4
	b _08034586
	.align 2, 0
_08034540: .4byte gUnknown_203B33C
_08034544:
	ldr r4, _0803458C
	ldr r1, [r4]
	movs r0, 0x32
	str r0, [r1, 0x4]
	bl sub_80307EC
	ldr r1, [r4]
	movs r5, 0x86
	lsls r5, 2
	adds r1, r5
	strb r0, [r1]
	ldr r0, [r4]
	movs r1, 0xEF
	lsls r1, 2
	adds r0, r1
	bl sub_8006518
	bl ResetUnusedInputStruct
	movs r0, 0
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	ldr r0, [r4]
	adds r0, r5
	ldrb r0, [r0]
	movs r1, 0
	bl sub_8030D40
	movs r0, 0x34
	bl sub_80338C4
_08034586:
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_0803458C: .4byte gUnknown_203B33C
	thumb_func_end sub_8034500

	thumb_func_start sub_8034590
sub_8034590:
	push {r4,lr}
	sub sp, 0x4
	movs r0, 0x1
	negs r0, r0
	str r0, [sp]
	movs r0, 0
	bl sub_8030768
	ldr r4, _080345D4
	ldr r0, [r4]
	movs r1, 0xC3
	lsls r1, 2
	adds r0, r1
	bl sub_8012FD8
	lsls r0, 24
	cmp r0, 0
	bne _080345C2
	ldr r0, [r4]
	movs r1, 0xC3
	lsls r1, 2
	adds r0, r1
	mov r1, sp
	bl sub_8013114
_080345C2:
	ldr r0, [sp]
	cmp r0, 0x8
	beq _08034624
	cmp r0, 0x8
	bgt _080345D8
	cmp r0, 0x5
	beq _08034624
	b _08034640
	.align 2, 0
_080345D4: .4byte gUnknown_203B33C
_080345D8:
	cmp r0, 0x9
	beq _080345E2
	cmp r0, 0xA
	beq _080345EE
	b _08034640
_080345E2:
	bl sub_803084C
	movs r0, 0x35
	bl sub_80338C4
	b _08034640
_080345EE:
	ldr r0, [r4]
	movs r1, 0x7E
	str r1, [r0, 0x4]
	movs r1, 0xEF
	lsls r1, 2
	adds r0, r1
	bl sub_8006518
	bl ResetUnusedInputStruct
	movs r0, 0
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	ldr r0, [r4]
	movs r1, 0x86
	lsls r1, 2
	adds r0, r1
	ldrb r0, [r0]
	movs r1, 0
	bl sub_8030D40
	movs r0, 0x34
	bl sub_80338C4
	b _08034640
_08034624:
	ldr r0, _08034648
	ldr r0, [r0]
	movs r1, 0xD7
	lsls r1, 2
	adds r0, r1
	movs r1, 0x2
	bl sub_8035CC0
	movs r0, 0x1
	bl sub_8030810
	movs r0, 0x32
	bl sub_80338C4
_08034640:
	add sp, 0x4
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08034648: .4byte gUnknown_203B33C
	thumb_func_end sub_8034590

	thumb_func_start sub_803464C
sub_803464C:
	push {r4,lr}
	bl sub_8030DA0
	cmp r0, 0x3
	bhi _080346A0
	cmp r0, 0x2
	bcc _080346A0
	bl sub_8030DE4
	bl ResetUnusedInputStruct
	ldr r4, _08034698
	ldr r0, [r4]
	movs r1, 0xEF
	lsls r1, 2
	adds r0, r1
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	bl sub_803092C
	ldr r4, [r4]
	ldr r0, [r4, 0x4]
	cmp r0, 0x7E
	bne _0803469C
	movs r1, 0x87
	lsls r1, 2
	adds r0, r4, r1
	movs r1, 0x3
	movs r2, 0x1
	bl sub_8035CF4
	movs r0, 0x33
	bl sub_80338C4
	b _080346A0
	.align 2, 0
_08034698: .4byte gUnknown_203B33C
_0803469C:
	bl sub_80338C4
_080346A0:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_803464C

	thumb_func_start sub_80346A8
sub_80346A8:
	push {lr}
	sub sp, 0x4
	mov r0, sp
	bl sub_80144A4
	cmp r0, 0
	bne _080346D2
	ldr r0, [sp]
	cmp r0, 0x6
	bne _080346C4
	movs r0, 0xE
	bl sub_80338C4
	b _080346D2
_080346C4:
	cmp r0, 0x6
	blt _080346D2
	cmp r0, 0x8
	bgt _080346D2
	movs r0, 0x1
	bl sub_80338C4
_080346D2:
	add sp, 0x4
	pop {r0}
	bx r0
	thumb_func_end sub_80346A8

	thumb_func_start sub_80346D8
sub_80346D8:
	push {lr}
	sub sp, 0x4
	mov r0, sp
	bl sub_80144A4
	cmp r0, 0
	bne _080346FA
	bl sub_8012600
	lsls r0, 24
	cmp r0, 0
	bne _080346FA
	bl sub_8012750
	movs r0, 0x2
	bl sub_80338C4
_080346FA:
	add sp, 0x4
	pop {r0}
	bx r0
	thumb_func_end sub_80346D8

	thumb_func_start sub_8034700
sub_8034700:
	push {lr}
	sub sp, 0x4
	mov r0, sp
	bl sub_80144A4
	cmp r0, 0
	bne _0803471A
	movs r0, 0x38
	bl sub_80338C4
	movs r0, 0
	bl sub_8012574
_0803471A:
	add sp, 0x4
	pop {r0}
	bx r0
	thumb_func_end sub_8034700

	thumb_func_start sub_8034720
sub_8034720:
	push {lr}
	sub sp, 0x4
	mov r0, sp
	bl sub_80144A4
	cmp r0, 0
	bne _08034734
	movs r0, 0x3A
	bl sub_80338C4
_08034734:
	add sp, 0x4
	pop {r0}
	bx r0
	thumb_func_end sub_8034720

	thumb_func_start sub_803473C
sub_803473C:
	push {lr}
	bl sub_8031DCC
	cmp r0, 0x1
	beq _08034774
	cmp r0, 0x1
	bcc _08034778
	cmp r0, 0x3
	bhi _08034778
	bl sub_8031E10
	bl ResetUnusedInputStruct
	ldr r0, _08034770
	ldr r0, [r0]
	movs r1, 0xEF
	lsls r1, 2
	adds r0, r1
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	movs r0, 0x3B
	bl sub_80338C4
	b _08034778
	.align 2, 0
_08034770: .4byte gUnknown_203B33C
_08034774:
	bl sub_8031E00
_08034778:
	pop {r0}
	bx r0
	thumb_func_end sub_803473C

	thumb_func_start sub_803477C
sub_803477C:
	push {lr}
	sub sp, 0x4
	mov r0, sp
	bl sub_80144A4
	cmp r0, 0
	bne _080347A6
	ldr r0, [sp]
	cmp r0, 0x6
	bne _08034798
	movs r0, 0xE
	bl sub_80338C4
	b _080347A6
_08034798:
	cmp r0, 0x6
	blt _080347A6
	cmp r0, 0x8
	bgt _080347A6
	movs r0, 0x1
	bl sub_80338C4
_080347A6:
	add sp, 0x4
	pop {r0}
	bx r0
	thumb_func_end sub_803477C

	thumb_func_start sub_80347AC
sub_80347AC:
	push {lr}
	sub sp, 0x4
	mov r0, sp
	bl sub_80144A4
	cmp r0, 0
	bne _080347C0
	movs r0, 0xD
	bl sub_80338C4
_080347C0:
	add sp, 0x4
	pop {r0}
	bx r0
	thumb_func_end sub_80347AC

	thumb_func_start sub_80347C8
sub_80347C8:
	push {lr}
	sub sp, 0x4
	mov r0, sp
	bl sub_80144A4
	cmp r0, 0
	bne _080347DC
	movs r0, 0x40
	bl sub_80338C4
_080347DC:
	add sp, 0x4
	pop {r0}
	bx r0
	thumb_func_end sub_80347C8

	thumb_func_start sub_80347E4
sub_80347E4:
	push {lr}
	sub sp, 0x4
	mov r0, sp
	bl sub_80144A4
	cmp r0, 0
	bne _080347FE
	movs r0, 0x41
	bl sub_80338C4
	movs r0, 0
	bl sub_8012574
_080347FE:
	add sp, 0x4
	pop {r0}
	bx r0
	thumb_func_end sub_80347E4

	thumb_func_start sub_8034804
sub_8034804:
	push {lr}
	sub sp, 0x4
	mov r0, sp
	bl sub_80144A4
	cmp r0, 0
	bne _08034826
	bl sub_8012600
	lsls r0, 24
	cmp r0, 0
	bne _08034826
	bl sub_8012750
	movs r0, 0x42
	bl sub_80338C4
_08034826:
	add sp, 0x4
	pop {r0}
	bx r0
	thumb_func_end sub_8034804

	thumb_func_start sub_803482C
sub_803482C:
	push {lr}
	sub sp, 0x4
	mov r0, sp
	bl sub_80144A4
	cmp r0, 0
	bne _08034840
	movs r0, 0x1
	bl sub_80338C4
_08034840:
	add sp, 0x4
	pop {r0}
	bx r0
	thumb_func_end sub_803482C

	thumb_func_start sub_8034848
sub_8034848:
	push {r4-r6,lr}
	sub sp, 0x4
	mov r0, sp
	bl sub_80144A4
	adds r6, r0, 0
	cmp r6, 0
	bne _080348BA
	ldr r4, _0803489C
	ldr r0, [r4]
	ldr r5, _080348A0
	adds r0, r5
	movs r1, 0
	movs r2, 0x4
	bl MemoryFill8
	ldr r0, [r4]
	ldr r1, _080348A4
	adds r0, r1
	strb r6, [r0]
	ldr r0, [r4]
	subs r1, 0x1
	adds r0, r1
	movs r1, 0x1
	strb r1, [r0]
	ldr r0, [r4]
	adds r0, r5
	strb r6, [r0]
	ldr r4, [r4]
	ldr r0, [r4, 0x44]
	cmp r0, 0
	bne _080348B0
	ldr r4, [r4, 0x40]
	cmp r4, 0x6
	beq _080348A8
	cmp r4, 0x7
	bne _080348BA
	movs r0, 0x6D
	bl sub_80338C4
	b _080348BA
	.align 2, 0
_0803489C: .4byte gUnknown_203B33C
_080348A0: .4byte 0x0000041c
_080348A4: .4byte 0x0000041e
_080348A8:
	movs r0, 0x50
	bl sub_80338C4
	b _080348BA
_080348B0:
	bl sub_80338DC
	movs r0, 0x6B
	bl sub_80338C4
_080348BA:
	add sp, 0x4
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end sub_8034848

	thumb_func_start sub_80348C4
sub_80348C4:
	push {r4-r6,lr}
	sub sp, 0x4
	mov r0, sp
	bl sub_80144A4
	adds r6, r0, 0
	cmp r6, 0
	bne _08034968
	ldr r4, _08034910
	ldr r0, [r4]
	ldr r5, _08034914
	adds r0, r5
	movs r1, 0
	movs r2, 0x4
	bl MemoryFill8
	ldr r0, [r4]
	ldr r1, _08034918
	adds r0, r1
	strb r6, [r0]
	ldr r0, [r4]
	subs r1, 0x1
	adds r0, r1
	movs r1, 0x1
	strb r1, [r0]
	ldr r0, [r4]
	adds r0, r5
	strb r6, [r0]
	ldr r0, [r4]
	ldr r1, [r0, 0x44]
	cmp r1, 0
	bne _0803495C
	ldr r1, [r0, 0x40]
	cmp r1, 0x6
	beq _0803491C
	cmp r1, 0x7
	beq _08034954
	b _08034968
	.align 2, 0
_08034910: .4byte gUnknown_203B33C
_08034914: .4byte 0x0000041c
_08034918: .4byte 0x0000041e
_0803491C:
	ldr r1, _08034930
	adds r0, r1
	ldr r0, [r0]
	cmp r0, 0xC
	beq _08034944
	cmp r0, 0xC
	bhi _08034934
	cmp r0, 0xB
	beq _08034938
	b _08034944
	.align 2, 0
_08034930: .4byte 0x00000524
_08034934:
	cmp r0, 0xE
	bhi _08034944
_08034938:
	ldr r0, _0803494C
	ldr r3, _08034950
	movs r1, 0
	movs r2, 0
	bl sub_80141B4
_08034944:
	movs r0, 0x77
	bl sub_80338C4
	b _08034968
	.align 2, 0
_0803494C: .4byte gUnknown_80E31FC
_08034950: .4byte 0x00000101
_08034954:
	movs r0, 0x6D
	bl sub_80338C4
	b _08034968
_0803495C:
	adds r0, r1, 0
	bl sub_80338DC
	movs r0, 0x6B
	bl sub_80338C4
_08034968:
	add sp, 0x4
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end sub_80348C4

	thumb_func_start sub_8034970
sub_8034970:
	push {lr}
	bl sub_8031DCC
	cmp r0, 0x1
	beq _080349A8
	cmp r0, 0x1
	bcc _080349AC
	cmp r0, 0x3
	bhi _080349AC
	bl sub_8031E10
	bl ResetUnusedInputStruct
	ldr r0, _080349A4
	ldr r0, [r0]
	movs r1, 0xEF
	lsls r1, 2
	adds r0, r1
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	movs r0, 0x68
	bl sub_80338C4
	b _080349AC
	.align 2, 0
_080349A4: .4byte gUnknown_203B33C
_080349A8:
	bl sub_8031E00
_080349AC:
	pop {r0}
	bx r0
	thumb_func_end sub_8034970

	thumb_func_start sub_80349B0
sub_80349B0:
	push {lr}
	sub sp, 0x4
	mov r0, sp
	bl sub_80144A4
	cmp r0, 0
	bne _080349DA
	ldr r0, [sp]
	cmp r0, 0x6
	bne _080349CC
	movs r0, 0x52
	bl sub_80338C4
	b _080349DA
_080349CC:
	cmp r0, 0x6
	blt _080349DA
	cmp r0, 0x8
	bgt _080349DA
	movs r0, 0x1
	bl sub_80338C4
_080349DA:
	add sp, 0x4
	pop {r0}
	bx r0
	thumb_func_end sub_80349B0

	thumb_func_start sub_80349E0
sub_80349E0:
	push {r4,r5,lr}
	movs r0, 0x1
	bl sub_8030768
	cmp r0, 0x3
	beq _08034A08
	cmp r0, 0x3
	bhi _080349F6
	cmp r0, 0x2
	beq _080349FC
	b _08034A66
_080349F6:
	cmp r0, 0x4
	beq _08034A24
	b _08034A66
_080349FC:
	bl sub_803084C
	movs r0, 0x1
	bl sub_80338C4
	b _08034A66
_08034A08:
	bl sub_80307EC
	ldr r1, _08034A20
	ldr r1, [r1]
	movs r2, 0x86
	lsls r2, 2
	adds r1, r2
	strb r0, [r1]
	movs r0, 0x5D
	bl sub_80338C4
	b _08034A66
	.align 2, 0
_08034A20: .4byte gUnknown_203B33C
_08034A24:
	ldr r4, _08034A6C
	ldr r1, [r4]
	movs r0, 0x5C
	str r0, [r1, 0x4]
	bl sub_80307EC
	ldr r1, [r4]
	movs r5, 0x86
	lsls r5, 2
	adds r1, r5
	strb r0, [r1]
	ldr r0, [r4]
	movs r1, 0xEF
	lsls r1, 2
	adds r0, r1
	bl sub_8006518
	bl ResetUnusedInputStruct
	movs r0, 0
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	ldr r0, [r4]
	adds r0, r5
	ldrb r0, [r0]
	movs r1, 0
	bl sub_8030D40
	movs r0, 0x5E
	bl sub_80338C4
_08034A66:
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_08034A6C: .4byte gUnknown_203B33C
	thumb_func_end sub_80349E0

	thumb_func_start sub_8034A70
sub_8034A70:
	push {r4,lr}
	sub sp, 0x4
	movs r0, 0x1
	negs r0, r0
	str r0, [sp]
	movs r0, 0
	bl sub_8030768
	ldr r4, _08034AB4
	ldr r0, [r4]
	movs r1, 0xC3
	lsls r1, 2
	adds r0, r1
	bl sub_8012FD8
	lsls r0, 24
	cmp r0, 0
	bne _08034AA2
	ldr r0, [r4]
	movs r1, 0xC3
	lsls r1, 2
	adds r0, r1
	mov r1, sp
	bl sub_8013114
_08034AA2:
	ldr r0, [sp]
	cmp r0, 0x8
	beq _08034B04
	cmp r0, 0x8
	bgt _08034AB8
	cmp r0, 0x5
	beq _08034B04
	b _08034B20
	.align 2, 0
_08034AB4: .4byte gUnknown_203B33C
_08034AB8:
	cmp r0, 0x9
	beq _08034AC2
	cmp r0, 0xA
	beq _08034ACE
	b _08034B20
_08034AC2:
	bl sub_803084C
	movs r0, 0x5A
	bl sub_80338C4
	b _08034B20
_08034ACE:
	ldr r0, [r4]
	movs r1, 0x7E
	str r1, [r0, 0x4]
	movs r1, 0xEF
	lsls r1, 2
	adds r0, r1
	bl sub_8006518
	bl ResetUnusedInputStruct
	movs r0, 0
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	ldr r0, [r4]
	movs r1, 0x86
	lsls r1, 2
	adds r0, r1
	ldrb r0, [r0]
	movs r1, 0
	bl sub_8030D40
	movs r0, 0x5E
	bl sub_80338C4
	b _08034B20
_08034B04:
	ldr r0, _08034B28
	ldr r0, [r0]
	movs r1, 0xD7
	lsls r1, 2
	adds r0, r1
	movs r1, 0x2
	bl sub_8035CC0
	movs r0, 0x1
	bl sub_8030810
	movs r0, 0x5C
	bl sub_80338C4
_08034B20:
	add sp, 0x4
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08034B28: .4byte gUnknown_203B33C
	thumb_func_end sub_8034A70

	thumb_func_start sub_8034B2C
sub_8034B2C:
	push {r4,lr}
	bl sub_8030DA0
	cmp r0, 0x3
	bhi _08034B80
	cmp r0, 0x2
	bcc _08034B80
	bl sub_8030DE4
	bl ResetUnusedInputStruct
	ldr r4, _08034B78
	ldr r0, [r4]
	movs r1, 0xEF
	lsls r1, 2
	adds r0, r1
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	bl sub_803092C
	ldr r4, [r4]
	ldr r0, [r4, 0x4]
	cmp r0, 0x7E
	bne _08034B7C
	movs r1, 0x87
	lsls r1, 2
	adds r0, r4, r1
	movs r1, 0x3
	movs r2, 0x1
	bl sub_8035CF4
	movs r0, 0x5D
	bl sub_80338C4
	b _08034B80
	.align 2, 0
_08034B78: .4byte gUnknown_203B33C
_08034B7C:
	bl sub_80338C4
_08034B80:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_8034B2C

	thumb_func_start sub_8034B88
sub_8034B88:
	push {r4-r6,lr}
	ldr r4, _08034BBC
	ldr r0, [r4]
	ldr r5, _08034BC0
	adds r0, r5
	movs r2, 0
	strb r2, [r0]
	ldr r0, [r4]
	ldr r1, _08034BC4
	adds r0, r1
	movs r1, 0x1
	strb r1, [r0]
	ldr r0, [r4]
	ldr r6, _08034BC8
	adds r0, r6
	strb r2, [r0]
	movs r0, 0x1
	bl sub_801CA08
	cmp r0, 0x3
	beq _08034BDE
	cmp r0, 0x3
	bhi _08034BCC
	cmp r0, 0x2
	beq _08034BD2
	b _08034C30
	.align 2, 0
_08034BBC: .4byte gUnknown_203B33C
_08034BC0: .4byte 0x0000041e
_08034BC4: .4byte 0x0000041d
_08034BC8: .4byte 0x0000041c
_08034BCC:
	cmp r0, 0x4
	beq _08034BF8
	b _08034C30
_08034BD2:
	bl sub_801CBB8
	movs r0, 0x1
	bl sub_80338C4
	b _08034C30
_08034BDE:
	bl sub_801CB24
	ldr r1, [r4]
	ldr r2, _08034BF4
	adds r1, r2
	strb r0, [r1]
	movs r0, 0x60
	bl sub_80338C4
	b _08034C30
	.align 2, 0
_08034BF4: .4byte 0x0000041e
_08034BF8:
	ldr r1, [r4]
	movs r0, 0x5F
	str r0, [r1, 0x4]
	bl sub_801CB24
	ldr r1, [r4]
	adds r1, r5
	strb r0, [r1]
	ldr r0, [r4]
	movs r1, 0xEF
	lsls r1, 2
	adds r0, r1
	bl sub_8006518
	bl ResetUnusedInputStruct
	movs r0, 0
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	ldr r0, [r4]
	adds r0, r6
	bl sub_801B3C0
	movs r0, 0x61
	bl sub_80338C4
_08034C30:
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end sub_8034B88

	thumb_func_start sub_8034C38
sub_8034C38:
	push {r4,lr}
	bl sub_801B410
	cmp r0, 0x1
	beq _08034C90
	cmp r0, 0x1
	bcc _08034C90
	cmp r0, 0x3
	bhi _08034C90
	bl sub_801B450
	bl ResetUnusedInputStruct
	ldr r4, _08034C88
	ldr r0, [r4]
	movs r1, 0xEF
	lsls r1, 2
	adds r0, r1
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	movs r0, 0x1
	bl sub_801CB5C
	ldr r4, [r4]
	ldr r0, [r4, 0x4]
	cmp r0, 0x7E
	bne _08034C8C
	movs r1, 0x87
	lsls r1, 2
	adds r0, r4, r1
	movs r1, 0x3
	movs r2, 0x1
	bl sub_8035CF4
	movs r0, 0x60
	bl sub_80338C4
	b _08034C90
	.align 2, 0
_08034C88: .4byte gUnknown_203B33C
_08034C8C:
	bl sub_80338C4
_08034C90:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_8034C38

	thumb_func_start sub_8034C98
sub_8034C98:
	push {r4,lr}
	sub sp, 0x4
	movs r0, 0x1
	negs r0, r0
	str r0, [sp]
	movs r0, 0
	bl sub_801CA08
	ldr r4, _08034CDC
	ldr r0, [r4]
	movs r1, 0xC3
	lsls r1, 2
	adds r0, r1
	bl sub_8012FD8
	lsls r0, 24
	cmp r0, 0
	bne _08034CCA
	ldr r0, [r4]
	movs r1, 0xC3
	lsls r1, 2
	adds r0, r1
	mov r1, sp
	bl sub_8013114
_08034CCA:
	ldr r0, [sp]
	cmp r0, 0x8
	beq _08034D2C
	cmp r0, 0x8
	bgt _08034CE0
	cmp r0, 0x5
	beq _08034D2C
	b _08034D48
	.align 2, 0
_08034CDC: .4byte gUnknown_203B33C
_08034CE0:
	cmp r0, 0x9
	beq _08034CEA
	cmp r0, 0xA
	beq _08034CF6
	b _08034D48
_08034CEA:
	bl sub_801CBB8
	movs r0, 0x58
	bl sub_80338C4
	b _08034D48
_08034CF6:
	ldr r0, [r4]
	movs r1, 0x7E
	str r1, [r0, 0x4]
	movs r1, 0xEF
	lsls r1, 2
	adds r0, r1
	bl sub_8006518
	bl ResetUnusedInputStruct
	movs r0, 0
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	ldr r0, [r4]
	ldr r1, _08034D28
	adds r0, r1
	bl sub_801B3C0
	movs r0, 0x61
	bl sub_80338C4
	b _08034D48
	.align 2, 0
_08034D28: .4byte 0x0000041c
_08034D2C:
	ldr r0, _08034D50
	ldr r0, [r0]
	movs r1, 0xD7
	lsls r1, 2
	adds r0, r1
	movs r1, 0x3
	bl sub_8035CC0
	movs r0, 0x1
	bl sub_801CB5C
	movs r0, 0x5F
	bl sub_80338C4
_08034D48:
	add sp, 0x4
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08034D50: .4byte gUnknown_203B33C
	thumb_func_end sub_8034C98

	thumb_func_start sub_8034D54
sub_8034D54:
	push {lr}
	sub sp, 0x4
	mov r0, sp
	bl sub_80144A4
	cmp r0, 0
	bne _08034D6E
	movs r0, 0x65
	bl sub_80338C4
	movs r0, 0
	bl sub_8012574
_08034D6E:
	add sp, 0x4
	pop {r0}
	bx r0
	thumb_func_end sub_8034D54

	thumb_func_start sub_8034D74
sub_8034D74:
	push {r4,r5,lr}
	sub sp, 0x44
	bl sub_80154F0
	adds r4, r0, 0
	add r0, sp, 0x14
	movs r1, 0
	movs r2, 0x30
	bl MemoryFill8
	cmp r4, 0x2
	bne _08034D8E
	b _08034E9C
_08034D8E:
	cmp r4, 0x3
	beq _08034D94
	b _08034EBC
_08034D94:
	ldr r0, _08034DB4
	ldr r1, [r0]
	adds r1, 0x8
	movs r0, 0x20
	add r2, sp, 0x14
	bl sub_8039068
	subs r0, 0x7
	cmp r0, 0x11
	bhi _08034E90
	lsls r0, 2
	ldr r1, _08034DB8
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08034DB4: .4byte gUnknown_203B33C
_08034DB8: .4byte _08034DBC
	.align 2, 0
_08034DBC:
	.4byte _08034E90
	.4byte _08034E90
	.4byte _08034E90
	.4byte _08034E90
	.4byte _08034E38
	.4byte _08034E90
	.4byte _08034E90
	.4byte _08034E90
	.4byte _08034E90
	.4byte _08034E90
	.4byte _08034E04
	.4byte _08034E90
	.4byte _08034E90
	.4byte _08034E30
	.4byte _08034E90
	.4byte _08034E90
	.4byte _08034E90
	.4byte _08034E54
_08034E04:
	ldr r0, _08034E28
	ldr r3, _08034E2C
	movs r2, 0
	str r2, [sp]
	movs r1, 0x4
	str r1, [sp, 0x4]
	str r2, [sp, 0x8]
	str r2, [sp, 0xC]
	adds r1, 0xFD
	str r1, [sp, 0x10]
	movs r1, 0
	movs r2, 0x6
	bl sub_8014248
	movs r0, 0x74
	bl sub_80338C4
	b _08034E90
	.align 2, 0
_08034E28: .4byte gUnknown_80E48A8
_08034E2C: .4byte gUnknown_80E2440
_08034E30:
	ldr r0, _08034E34
	b _08034E3A
	.align 2, 0
_08034E34: .4byte gUnknown_80E49C4
_08034E38:
	ldr r0, _08034E4C
_08034E3A:
	ldr r3, _08034E50
	movs r1, 0
	movs r2, 0
	bl sub_80141B4
	movs r0, 0x6B
	bl sub_80338C4
	b _08034E90
	.align 2, 0
_08034E4C: .4byte gUnknown_80E4704
_08034E50: .4byte 0x00000101
_08034E54:
	ldr r1, [sp, 0x24]
	movs r0, 0x4
	bl sub_809539C
	lsls r0, 24
	lsrs r0, 24
	bl sub_8095228
	adds r2, r0, 0
	add r1, sp, 0x14
	ldm r1!, {r3-r5}
	stm r2!, {r3-r5}
	ldm r1!, {r3-r5}
	stm r2!, {r3-r5}
	ldm r1!, {r3-r5}
	stm r2!, {r3-r5}
	ldm r1!, {r3-r5}
	stm r2!, {r3-r5}
	movs r1, 0x6
	strb r1, [r0]
	ldr r0, _08034E98
	ldr r0, [r0]
	movs r1, 0x84
	lsls r1, 3
	adds r0, r1
	ldr r1, [sp, 0x24]
	str r1, [r0]
	movs r0, 0x6D
	bl sub_80338C4
_08034E90:
	bl sub_80155F0
	b _08034EBC
	.align 2, 0
_08034E98: .4byte gUnknown_203B33C
_08034E9C:
	bl sub_80155F0
	bl ResetUnusedInputStruct
	ldr r0, _08034EC4
	ldr r0, [r0]
	movs r3, 0xEF
	lsls r3, 2
	adds r0, r3
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	movs r0, 0x1
	bl sub_80338C4
_08034EBC:
	add sp, 0x44
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_08034EC4: .4byte gUnknown_203B33C
	thumb_func_end sub_8034D74

	thumb_func_start sub_8034EC8
sub_8034EC8:
	push {lr}
	sub sp, 0x4
	mov r0, sp
	bl sub_80144A4
	cmp r0, 0
	bne _08034EEA
	bl sub_8012600
	lsls r0, 24
	cmp r0, 0
	bne _08034EEA
	bl sub_8012750
	movs r0, 0x2
	bl sub_80338C4
_08034EEA:
	add sp, 0x4
	pop {r0}
	bx r0
	thumb_func_end sub_8034EC8

	thumb_func_start sub_8034EF0
sub_8034EF0:
	push {lr}
	sub sp, 0x4
	mov r0, sp
	bl sub_80144A4
	cmp r0, 0
	bne _08034F12
	bl sub_8012600
	lsls r0, 24
	cmp r0, 0
	bne _08034F12
	bl sub_8012750
	movs r0, 0x2
	bl sub_80338C4
_08034F12:
	add sp, 0x4
	pop {r0}
	bx r0
	thumb_func_end sub_8034EF0

	thumb_func_start sub_8034F18
sub_8034F18:
	push {lr}
	sub sp, 0x4
	mov r0, sp
	bl sub_80144A4
	cmp r0, 0
	bne _08034F32
	movs r0, 0x65
	bl sub_80338C4
	movs r0, 0
	bl sub_8012574
_08034F32:
	add sp, 0x4
	pop {r0}
	bx r0
	thumb_func_end sub_8034F18

	thumb_func_start sub_8034F38
sub_8034F38:
	push {lr}
	sub sp, 0x4
	mov r0, sp
	bl sub_80144A4
	cmp r0, 0
	bne _08034F52
	movs r0, 0x71
	bl sub_80338C4
	movs r0, 0
	bl sub_8012574
_08034F52:
	add sp, 0x4
	pop {r0}
	bx r0
	thumb_func_end sub_8034F38

	thumb_func_start sub_8034F58
sub_8034F58:
	push {lr}
	sub sp, 0x4
	mov r0, sp
	bl sub_80144A4
	cmp r0, 0
	bne _08034F80
	ldr r0, [sp]
	cmp r0, 0x6
	beq _08034F72
	cmp r0, 0x8
	beq _08034F7A
	b _08034F80
_08034F72:
	movs r0, 0x62
	bl sub_80338C4
	b _08034F80
_08034F7A:
	movs r0, 0x1
	bl sub_80338C4
_08034F80:
	add sp, 0x4
	pop {r0}
	bx r0
	thumb_func_end sub_8034F58

	thumb_func_start sub_8034F88
sub_8034F88:
	push {r4,r5,lr}
	sub sp, 0x4
	mov r0, sp
	bl sub_80144A4
	cmp r0, 0
	bne _0803500E
	ldr r0, [sp]
	cmp r0, 0x7
	beq _08035000
	cmp r0, 0x7
	bgt _08034FA6
	cmp r0, 0x6
	beq _08034FAC
	b _0803500E
_08034FA6:
	cmp r0, 0x8
	beq _08035008
	b _0803500E
_08034FAC:
	ldr r4, _08034FF0
	ldr r0, [r4]
	movs r1, 0x86
	lsls r1, 2
	adds r0, r1
	ldrb r0, [r0]
	bl sub_8095228
	adds r2, r0, 0
	ldr r1, [r4]
	ldr r3, _08034FF4
	adds r0, r1, r3
	ldrb r0, [r0]
	cmp r0, 0
	beq _08034FD2
	ldr r5, _08034FF8
	adds r0, r1, r5
	ldr r0, [r0]
	str r0, [r2, 0x20]
_08034FD2:
	ldr r0, _08034FFC
	ldr r1, [r0]
	ldr r0, [r4]
	adds r0, r3
	ldrb r0, [r0]
	lsls r0, 1
	adds r1, 0x50
	adds r1, r0
	ldrh r0, [r1]
	subs r0, 0x1
	strh r0, [r1]
	movs r0, 0x75
	bl sub_80338C4
	b _0803500E
	.align 2, 0
_08034FF0: .4byte gUnknown_203B33C
_08034FF4: .4byte 0x0000041e
_08034FF8: .4byte 0x0000041c
_08034FFC: .4byte gUnknown_203B460
_08035000:
	movs r0, 0x57
	bl sub_80338C4
	b _0803500E
_08035008:
	movs r0, 0x1
	bl sub_80338C4
_0803500E:
	add sp, 0x4
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_8034F88

	thumb_func_start sub_8035018
sub_8035018:
	push {lr}
	sub sp, 0x4
	mov r0, sp
	bl sub_80144A4
	cmp r0, 0
	bne _08035032
	movs r0, 0x76
	bl sub_80338C4
	movs r0, 0
	bl sub_8012574
_08035032:
	add sp, 0x4
	pop {r0}
	bx r0
	thumb_func_end sub_8035018

	thumb_func_start sub_8035038
sub_8035038:
	push {lr}
	sub sp, 0x4
	mov r0, sp
	bl sub_80144A4
	cmp r0, 0
	bne _0803508E
	bl sub_8012600
	lsls r0, 24
	cmp r0, 0
	bne _0803508E
	bl sub_8012750
	ldr r0, _0803506C
	ldr r0, [r0]
	ldr r1, _08035070
	adds r0, r1
	ldr r0, [r0]
	cmp r0, 0xD
	beq _08035080
	cmp r0, 0xD
	bls _08035074
	cmp r0, 0xE
	beq _08035088
	b _0803508E
	.align 2, 0
_0803506C: .4byte gUnknown_203B33C
_08035070: .4byte 0x00000524
_08035074:
	cmp r0, 0xB
	bcc _0803508E
	movs r0, 0x69
	bl sub_80338C4
	b _0803508E
_08035080:
	movs r0, 0x66
	bl sub_80338C4
	b _0803508E
_08035088:
	movs r0, 0x4B
	bl sub_80338C4
_0803508E:
	add sp, 0x4
	pop {r0}
	bx r0
	thumb_func_end sub_8035038

	thumb_func_start sub_8035094
sub_8035094:
	push {lr}
	sub sp, 0x4
	mov r0, sp
	bl sub_80144A4
	cmp r0, 0
	bne _080350EE
	ldr r0, [sp]
	cmp r0, 0x8
	beq _080350E8
	cmp r0, 0x16
	bne _080350EE
	ldr r0, _080350C4
	ldr r0, [r0]
	ldr r1, _080350C8
	adds r0, r1
	ldr r0, [r0]
	cmp r0, 0xD
	beq _080350D8
	cmp r0, 0xD
	bls _080350CC
	cmp r0, 0xE
	beq _080350E0
	b _080350EE
	.align 2, 0
_080350C4: .4byte gUnknown_203B33C
_080350C8: .4byte 0x00000524
_080350CC:
	cmp r0, 0xB
	bcc _080350EE
	movs r0, 0x69
	bl sub_80338C4
	b _080350EE
_080350D8:
	movs r0, 0x66
	bl sub_80338C4
	b _080350EE
_080350E0:
	movs r0, 0x4B
	bl sub_80338C4
	b _080350EE
_080350E8:
	movs r0, 0x1
	bl sub_80338C4
_080350EE:
	add sp, 0x4
	pop {r0}
	bx r0
	thumb_func_end sub_8035094

	thumb_func_start sub_80350F4
sub_80350F4:
	push {lr}
	sub sp, 0x4
	mov r0, sp
	bl sub_80144A4
	cmp r0, 0
	bne _08035176
	ldr r0, [sp]
	cmp r0, 0x15
	beq _08035118
	cmp r0, 0x15
	bgt _08035112
	cmp r0, 0x8
	beq _08035170
	b _08035176
_08035112:
	cmp r0, 0x16
	beq _08035134
	b _08035176
_08035118:
	movs r0, 0
	bl sub_801CF14
	lsls r0, 24
	cmp r0, 0
	beq _0803512C
	movs r0, 0x56
	bl sub_80338C4
	b _08035176
_0803512C:
	movs r0, 0x57
	bl sub_80338C4
	b _08035176
_08035134:
	ldr r0, _0803514C
	ldr r0, [r0]
	ldr r1, _08035150
	adds r0, r1
	ldr r0, [r0]
	cmp r0, 0xD
	beq _08035160
	cmp r0, 0xD
	bls _08035154
	cmp r0, 0xE
	beq _08035168
	b _08035176
	.align 2, 0
_0803514C: .4byte gUnknown_203B33C
_08035150: .4byte 0x00000524
_08035154:
	cmp r0, 0xB
	bcc _08035176
	movs r0, 0x69
	bl sub_80338C4
	b _08035176
_08035160:
	movs r0, 0x66
	bl sub_80338C4
	b _08035176
_08035168:
	movs r0, 0x4B
	bl sub_80338C4
	b _08035176
_08035170:
	movs r0, 0x1
	bl sub_80338C4
_08035176:
	add sp, 0x4
	pop {r0}
	bx r0
	thumb_func_end sub_80350F4

	thumb_func_start sub_803517C
sub_803517C:
	push {lr}
	sub sp, 0x4
	mov r0, sp
	bl sub_80144A4
	cmp r0, 0
	bne _080351DA
	ldr r0, [sp]
	cmp r0, 0x6
	beq _08035196
	cmp r0, 0x8
	beq _080351D4
	b _080351DA
_08035196:
	ldr r0, _080351B0
	ldr r0, [r0]
	ldr r1, _080351B4
	adds r0, r1
	ldr r0, [r0]
	cmp r0, 0xD
	beq _080351C4
	cmp r0, 0xD
	bls _080351B8
	cmp r0, 0xE
	beq _080351CC
	b _080351DA
	.align 2, 0
_080351B0: .4byte gUnknown_203B33C
_080351B4: .4byte 0x00000524
_080351B8:
	cmp r0, 0xB
	bcc _080351DA
	movs r0, 0x69
	bl sub_80338C4
	b _080351DA
_080351C4:
	movs r0, 0x66
	bl sub_80338C4
	b _080351DA
_080351CC:
	movs r0, 0x4B
	bl sub_80338C4
	b _080351DA
_080351D4:
	movs r0, 0x1
	bl sub_80338C4
_080351DA:
	add sp, 0x4
	pop {r0}
	bx r0
	thumb_func_end sub_803517C

	thumb_func_start sub_80351E0
sub_80351E0:
	push {lr}
	sub sp, 0x4
	mov r0, sp
	bl sub_80144A4
	cmp r0, 0
	bne _08035208
	ldr r0, [sp]
	cmp r0, 0x6
	beq _080351FA
	cmp r0, 0x8
	beq _08035202
	b _08035208
_080351FA:
	movs r0, 0x72
	bl sub_80338C4
	b _08035208
_08035202:
	movs r0, 0x1
	bl sub_80338C4
_08035208:
	add sp, 0x4
	pop {r0}
	bx r0
	thumb_func_end sub_80351E0

	thumb_func_start sub_8035210
sub_8035210:
	push {lr}
	sub sp, 0x4
	mov r0, sp
	bl sub_80144A4
	cmp r0, 0
	bne _0803528C
	ldr r0, _08035238
	ldr r2, [r0]
	ldr r1, _0803523C
	adds r0, r2, r1
	ldr r1, [sp]
	str r1, [r0]
	cmp r1, 0xD
	bgt _0803528C
	cmp r1, 0xB
	bge _08035240
	cmp r1, 0x8
	beq _08035286
	b _0803528C
	.align 2, 0
_08035238: .4byte gUnknown_203B33C
_0803523C: .4byte 0x00000524
_08035240:
	movs r3, 0xA5
	lsls r3, 3
	adds r0, r2, r3
	ldr r0, [r0]
	cmp r0, 0x13
	bne _08035272
	movs r0, 0x5
	bl sub_80953D4
	lsls r0, 24
	lsrs r0, 24
	bl sub_8095228
	adds r0, 0x22
	ldrb r0, [r0]
	cmp r0, 0
	beq _0803526A
	movs r0, 0x53
	bl sub_80338C4
	b _0803528C
_0803526A:
	movs r0, 0x55
	bl sub_80338C4
	b _0803528C
_08035272:
	cmp r1, 0xD
	beq _0803527E
	movs r0, 0x69
	bl sub_80338C4
	b _0803528C
_0803527E:
	movs r0, 0x72
	bl sub_80338C4
	b _0803528C
_08035286:
	movs r0, 0x1
	bl sub_80338C4
_0803528C:
	add sp, 0x4
	pop {r0}
	bx r0
	thumb_func_end sub_8035210

	thumb_func_start nullsub_46
nullsub_46:
	bx lr
	thumb_func_end nullsub_46

	thumb_func_start nullsub_47
nullsub_47:
	bx lr
	thumb_func_end nullsub_47

	thumb_func_start nullsub_48
nullsub_48:
	bx lr
	thumb_func_end nullsub_48

	thumb_func_start nullsub_49
nullsub_49:
	bx lr
	thumb_func_end nullsub_49

	thumb_func_start sub_80352A4
sub_80352A4:
	push {r4,lr}
	bl sub_802F298
	cmp r0, 0x3
	bne _080352EC
	bl sub_802F2C0
	ldr r0, _080352F4
	movs r4, 0x98
	lsls r4, 1
	adds r1, r4, 0
	bl sub_808D8E0
	adds r0, r4, 0
	bl GetMonSpecies
	adds r1, r0, 0
	ldr r0, _080352F8
	bl strcpy
	ldr r0, _080352FC
	ldr r0, [r0]
	movs r1, 0x84
	lsls r1, 3
	adds r0, r1
	ldr r1, [r0]
	movs r0, 0x6
	bl sub_809539C
	lsls r0, 24
	lsrs r0, 24
	bl sub_8095240
	movs r0, 0x70
	bl sub_80338C4
_080352EC:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080352F4: .4byte gUnknown_202E5D8
_080352F8: .4byte gAvailablePokemonNames
_080352FC: .4byte gUnknown_203B33C
	thumb_func_end sub_80352A4

	thumb_func_start sub_8035300
sub_8035300:
	push {lr}
	sub sp, 0x4
	mov r0, sp
	bl sub_80144A4
	cmp r0, 0
	bne _08035364
	ldr r0, [sp]
	adds r1, r0, 0
	subs r1, 0x19
	adds r2, r0, 0
	cmp r1, 0x4
	bhi _08035364
	lsls r0, r1, 2
	ldr r1, _08035324
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08035324: .4byte _08035328
	.align 2, 0
_08035328:
	.4byte _0803533C
	.4byte _08035354
	.4byte _08035344
	.4byte _0803534C
	.4byte _08035354
_0803533C:
	movs r0, 0x1
	bl sub_80338C4
	b _08035364
_08035344:
	movs r0, 0x7A
	bl sub_80338C4
	b _08035364
_0803534C:
	movs r0, 0x7C
	bl sub_80338C4
	b _08035364
_08035354:
	ldr r0, _0803536C
	ldr r0, [r0]
	ldr r1, _08035370
	adds r0, r1
	str r2, [r0]
	movs r0, 0x79
	bl sub_80338C4
_08035364:
	add sp, 0x4
	pop {r0}
	bx r0
	.align 2, 0
_0803536C: .4byte gUnknown_203B33C
_08035370: .4byte 0x00000564
	thumb_func_end sub_8035300

        .align 2,0
