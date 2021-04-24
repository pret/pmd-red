        .include "constants/gba_constants.inc"
	.include "asm/macros.inc"

	.syntax unified

	.text	

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
	bl CopyYellowSpeciesNametoBuffer
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

        .align 2,0
