        .include "constants/gba_constants.inc"
	.include "asm/macros.inc"

	.syntax unified

	.text

	thumb_func_start sub_803C870
sub_803C870:
	push {r4-r6,lr}
	sub sp, 0x14
	ldr r5, _0803C8A4
	ldr r1, [r5]
	ldr r0, [r1, 0x38]
	adds r0, 0x1
	str r0, [r1, 0x38]
	cmp r0, 0x8
	ble _0803C8B4
	ldr r0, _0803C8A8
	ldr r3, _0803C8AC
	movs r1, 0
	str r1, [sp]
	movs r4, 0x3
	str r4, [sp, 0x4]
	str r1, [sp, 0x8]
	str r1, [sp, 0xC]
	ldr r1, _0803C8B0
	str r1, [sp, 0x10]
	movs r1, 0
	movs r2, 0
	bl sub_8014248
	ldr r0, [r5]
	str r4, [r0, 0x34]
	b _0803C8F8
	.align 2, 0
_0803C8A4: .4byte gUnknown_203B400
_0803C8A8: .4byte gGenderText
_0803C8AC: .4byte gUnknown_80F275C
_0803C8B0: .4byte 0x00000101
_0803C8B4:
	adds r4, r5, 0
_0803C8B6:
	movs r0, 0x37
	bl RandomCapped
	ldr r1, [r4]
	str r0, [r1, 0x3C]
	adds r1, 0x78
	adds r1, r0
	ldrb r0, [r1]
	cmp r0, 0x1
	beq _0803C8B6
	ldr r2, _0803C900
	ldr r1, _0803C904
	ldr r0, [r1]
	ldr r0, [r0, 0x3C]
	adds r0, r2
	ldrb r4, [r0]
	movs r3, 0
	adds r6, r1, 0
	movs r5, 0x1
_0803C8DC:
	adds r0, r3, r2
	ldrb r0, [r0]
	cmp r0, r4
	bne _0803C8EC
	ldr r0, [r1]
	adds r0, 0x78
	adds r0, r3
	strb r5, [r0]
_0803C8EC:
	adds r3, 0x1
	cmp r3, 0x36
	ble _0803C8DC
	ldr r1, [r6]
	movs r0, 0x1
	str r0, [r1, 0x34]
_0803C8F8:
	add sp, 0x14
	pop {r4-r6}
	pop {r0}
	bx r0
	.align 2, 0
_0803C900: .4byte gNatureQuestionTable
_0803C904: .4byte gUnknown_203B400
	thumb_func_end sub_803C870

	thumb_func_start sub_803C908
sub_803C908:
	push {lr}
	bl sub_803CC04
	ldr r0, _0803C91C
	ldr r1, [r0]
	movs r0, 0x2
	str r0, [r1, 0x34]
	pop {r0}
	bx r0
	.align 2, 0
_0803C91C: .4byte gUnknown_203B400
	thumb_func_end sub_803C908

	thumb_func_start sub_803C920
sub_803C920:
	push {r4-r6,lr}
	sub sp, 0x4
	mov r0, sp
	bl sub_80144A4
	cmp r0, 0
	bne _0803C97C
	ldr r3, [sp]
	cmp r3, 0x63
	bne _0803C944
	ldr r0, _0803C940
	ldr r1, [r0]
	movs r0, 0x37
	str r0, [r1, 0x3C]
	movs r0, 0x1
	b _0803C97A
	.align 2, 0
_0803C940: .4byte gUnknown_203B400
_0803C944:
	ldr r1, _0803C984
	ldr r2, _0803C988
	ldr r0, [r2]
	ldr r0, [r0, 0x3C]
	lsls r0, 2
	adds r0, r1
	ldr r0, [r0]
	ldr r4, [r0, 0x8]
	lsls r0, r3, 4
	adds r4, r0
	movs r3, 0
	adds r6, r2, 0
	adds r5, r6, 0
_0803C95E:
	ldr r1, [r5]
	lsls r0, r3, 2
	adds r1, 0x44
	adds r1, r0
	adds r0, r4, r3
	ldrb r2, [r0]
	ldr r0, [r1]
	adds r0, r2
	str r0, [r1]
	adds r3, 0x1
	cmp r3, 0xC
	ble _0803C95E
	ldr r1, [r6]
	movs r0, 0
_0803C97A:
	str r0, [r1, 0x34]
_0803C97C:
	add sp, 0x4
	pop {r4-r6}
	pop {r0}
	bx r0
	.align 2, 0
_0803C984: .4byte gPersonalityQuestionPointerTable
_0803C988: .4byte gUnknown_203B400
	thumb_func_end sub_803C920

	thumb_func_start sub_803C98C
sub_803C98C:
	push {lr}
	sub sp, 0x4
	mov r0, sp
	bl sub_80144A4
	cmp r0, 0
	bne _0803C9CA
	ldr r1, [sp]
	cmp r1, 0
	bne _0803C9AC
	ldr r0, _0803C9A8
	ldr r0, [r0]
	adds r0, 0xB0
	b _0803C9B4
	.align 2, 0
_0803C9A8: .4byte gUnknown_203B400
_0803C9AC:
	ldr r0, _0803C9D0
	ldr r0, [r0]
	adds r0, 0xB0
	movs r1, 0x1
_0803C9B4:
	str r1, [r0]
	ldr r0, _0803C9D4
	ldr r0, [r0]
	strb r1, [r0, 0xB]
	movs r0, 0
	bl sub_8099690
	ldr r0, _0803C9D0
	ldr r1, [r0]
	movs r0, 0x4
	str r0, [r1, 0x34]
_0803C9CA:
	add sp, 0x4
	pop {r0}
	bx r0
	.align 2, 0
_0803C9D0: .4byte gUnknown_203B400
_0803C9D4: .4byte gUnknown_203B46C
	thumb_func_end sub_803C98C

	thumb_func_start sub_803C9D8
sub_803C9D8:
	push {r4-r7,lr}
	movs r0, 0xD
	bl RandomCapped
	ldr r2, _0803CA4C
	ldr r1, [r2]
	adds r1, 0x40
	strb r0, [r1]
	ldr r0, [r2]
	adds r0, 0x40
	ldrb r3, [r0]
	adds r7, r2, 0
	movs r5, 0xB
_0803C9F2:
	adds r3, 0x1
	cmp r3, 0xC
	ble _0803C9FA
	movs r3, 0
_0803C9FA:
	ldr r0, [r7]
	lsls r2, r3, 2
	adds r1, r0, 0
	adds r1, 0x44
	adds r2, r1, r2
	adds r4, r0, 0
	adds r4, 0x40
	ldrb r0, [r4]
	lsls r0, 2
	adds r1, r0
	ldr r2, [r2]
	ldr r0, [r1]
	ldr r6, _0803CA4C
	cmp r2, r0
	ble _0803CA1A
	strb r3, [r4]
_0803CA1A:
	subs r5, 0x1
	cmp r5, 0
	bge _0803C9F2
	ldr r3, [r6]
	ldr r2, _0803CA50
	adds r0, r3, 0
	adds r0, 0xB0
	ldr r1, [r0]
	lsls r1, 1
	subs r0, 0x70
	ldrb r0, [r0]
	lsls r0, 2
	adds r1, r0
	adds r1, r2
	ldrh r0, [r1]
	strh r0, [r3, 0x8]
	bl PrintPersonalityTypeDescription
	ldr r1, [r6]
	movs r0, 0x5
	str r0, [r1, 0x34]
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_0803CA4C: .4byte gUnknown_203B400
_0803CA50: .4byte gStarters
	thumb_func_end sub_803C9D8

	thumb_func_start sub_803CA54
sub_803CA54:
	push {lr}
	sub sp, 0x4
	mov r0, sp
	bl sub_80144A4
	cmp r0, 0
	bne _0803CA7A
	ldr r0, _0803CA80
	ldr r3, _0803CA84
	movs r1, 0
	movs r2, 0
	bl sub_80141B4
	bl sub_803CC80
	ldr r0, _0803CA88
	ldr r1, [r0]
	movs r0, 0x6
	str r0, [r1, 0x34]
_0803CA7A:
	add sp, 0x4
	pop {r0}
	bx r0
	.align 2, 0
_0803CA80: .4byte gStarterReveal
_0803CA84: .4byte 0x00000101
_0803CA88: .4byte gUnknown_203B400
	thumb_func_end sub_803CA54

	thumb_func_start sub_803CA8C
sub_803CA8C:
	push {lr}
	sub sp, 0x4
	mov r0, sp
	bl sub_80144A4
	cmp r0, 0
	bne _0803CAA2
	ldr r0, _0803CAA8
	ldr r1, [r0]
	movs r0, 0x7
	str r0, [r1, 0x34]
_0803CAA2:
	add sp, 0x4
	pop {r0}
	bx r0
	.align 2, 0
_0803CAA8: .4byte gUnknown_203B400
	thumb_func_end sub_803CA8C

	thumb_func_start sub_803CAAC
sub_803CAAC:
	push {lr}
	ldr r0, _0803CAC8
	ldr r3, _0803CACC
	movs r1, 0
	movs r2, 0
	bl sub_80141B4
	ldr r0, _0803CAD0
	ldr r1, [r0]
	movs r0, 0x8
	str r0, [r1, 0x34]
	pop {r0}
	bx r0
	.align 2, 0
_0803CAC8: .4byte gUnknown_80F27DC
_0803CACC: .4byte 0x00000301
_0803CAD0: .4byte gUnknown_203B400
	thumb_func_end sub_803CAAC

	thumb_func_start sub_803CAD4
sub_803CAD4:
	push {lr}
	sub sp, 0x4
	mov r0, sp
	bl sub_80144A4
	cmp r0, 0
	bne _0803CAEA
	ldr r0, _0803CAF0
	ldr r1, [r0]
	movs r0, 0x9
	str r0, [r1, 0x34]
_0803CAEA:
	add sp, 0x4
	pop {r0}
	bx r0
	.align 2, 0
_0803CAF0: .4byte gUnknown_203B400
	thumb_func_end sub_803CAD4

	thumb_func_start sub_803CAF4
sub_803CAF4:
	push {r4,lr}
	ldr r4, _0803CB10
	ldr r0, [r4]
	movs r1, 0x8
	ldrsh r0, [r0, r1]
	bl sub_803CD08
	ldr r1, [r4]
	movs r0, 0xA
	str r0, [r1, 0x34]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0803CB10: .4byte gUnknown_203B400
	thumb_func_end sub_803CAF4

	thumb_func_start sub_803CB14
sub_803CB14:
	push {r4,r5,lr}
	bl sub_803CDC0
	lsls r0, 16
	lsrs r5, r0, 16
	ldr r0, _0803CB4C
	cmp r5, r0
	beq _0803CB46
	subs r0, 0x1
	cmp r5, r0
	beq _0803CB46
	bl sub_803CE6C
	ldr r4, _0803CB50
	ldr r0, [r4]
	strh r5, [r0, 0xA]
	ldr r0, _0803CB54
	ldr r3, _0803CB58
	movs r1, 0
	movs r2, 0
	bl sub_80141B4
	ldr r1, [r4]
	movs r0, 0xB
	str r0, [r1, 0x34]
_0803CB46:
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_0803CB4C: .4byte 0x0000ffff
_0803CB50: .4byte gUnknown_203B400
_0803CB54: .4byte gUnknown_80F286C
_0803CB58: .4byte 0x00000301
	thumb_func_end sub_803CB14

	thumb_func_start sub_803CB5C
sub_803CB5C:
	push {lr}
	sub sp, 0x4
	mov r0, sp
	bl sub_80144A4
	cmp r0, 0
	bne _0803CB72
	ldr r0, _0803CB78
	ldr r1, [r0]
	movs r0, 0xC
	str r0, [r1, 0x34]
_0803CB72:
	add sp, 0x4
	pop {r0}
	bx r0
	.align 2, 0
_0803CB78: .4byte gUnknown_203B400
	thumb_func_end sub_803CB5C

	thumb_func_start sub_803CB7C
sub_803CB7C:
	push {r4,r5,lr}
	ldr r4, _0803CBAC
	ldr r0, [r4]
	adds r5, r0, 0
	adds r5, 0x20
	movs r1, 0xA
	ldrsh r0, [r0, r1]
	bl sub_808D994
	adds r1, r0, 0
	adds r0, r5, 0
	bl sub_80922F4
	ldr r1, [r4]
	adds r1, 0x20
	movs r0, 0x3
	bl sub_801602C
	ldr r1, [r4]
	movs r0, 0xD
	str r0, [r1, 0x34]
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_0803CBAC: .4byte gUnknown_203B400
	thumb_func_end sub_803CB7C

	thumb_func_start sub_803CBB0
sub_803CBB0:
	push {lr}
	bl sub_8016080
	cmp r0, 0
	beq _0803CBD2
	bl sub_80160D8
	ldr r0, _0803CBD8
	ldr r3, _0803CBDC
	movs r1, 0
	movs r2, 0
	bl sub_80141B4
	ldr r0, _0803CBE0
	ldr r1, [r0]
	movs r0, 0xE
	str r0, [r1, 0x34]
_0803CBD2:
	pop {r0}
	bx r0
	.align 2, 0
_0803CBD8: .4byte gUnknown_80F2898
_0803CBDC: .4byte 0x00000301
_0803CBE0: .4byte gUnknown_203B400
	thumb_func_end sub_803CBB0

	thumb_func_start sub_803CBE4
sub_803CBE4:
	push {lr}
	sub sp, 0x4
	mov r0, sp
	bl sub_80144A4
	cmp r0, 0
	bne _0803CBFA
	ldr r0, _0803CC00
	ldr r1, [r0]
	movs r0, 0xF
	str r0, [r1, 0x34]
_0803CBFA:
	add sp, 0x4
	pop {r0}
	bx r0
	.align 2, 0
_0803CC00: .4byte gUnknown_203B400
	thumb_func_end sub_803CBE4

	thumb_func_start sub_803CC04
sub_803CC04:
	push {lr}
	sub sp, 0x14
	ldr r1, _0803CC38
	ldr r0, _0803CC3C
	ldr r0, [r0]
	ldr r0, [r0, 0x3C]
	lsls r0, 2
	adds r0, r1
	ldr r1, [r0]
	ldr r0, [r1]
	ldr r3, [r1, 0x4]
	movs r2, 0
	str r2, [sp]
	movs r1, 0x3
	str r1, [sp, 0x4]
	str r2, [sp, 0x8]
	str r2, [sp, 0xC]
	adds r1, 0xFE
	str r1, [sp, 0x10]
	movs r1, 0
	bl sub_8014248
	add sp, 0x14
	pop {r0}
	bx r0
	.align 2, 0
_0803CC38: .4byte gPersonalityQuestionPointerTable
_0803CC3C: .4byte gUnknown_203B400
	thumb_func_end sub_803CC04

	thumb_func_start PrintPersonalityTypeDescription
PrintPersonalityTypeDescription:
	push {r4,lr}
	ldr r0, _0803CC70
	ldr r4, _0803CC74
	ldr r1, [r4]
	movs r2, 0x8
	ldrsh r1, [r1, r2]
	bl sub_808D8BC
	ldr r1, _0803CC78
	ldr r0, [r4]
	adds r0, 0x40
	ldrb r0, [r0]
	lsls r0, 2
	adds r0, r1
	ldr r0, [r0]
	ldr r3, _0803CC7C
	movs r1, 0
	movs r2, 0
	bl sub_80141B4
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0803CC70: .4byte gUnknown_202DF98
_0803CC74: .4byte gUnknown_203B400
_0803CC78: .4byte gPersonalityTypeDescriptionTable
_0803CC7C: .4byte 0x00000101
	thumb_func_end PrintPersonalityTypeDescription

	thumb_func_start sub_803CC80
sub_803CC80:
	push {r4-r7,lr}
	sub sp, 0x60
	ldr r0, _0803CD00
	ldr r0, [r0]
	movs r1, 0x8
	ldrsh r4, [r0, r1]
	mov r0, sp
	bl sub_8006518
	add r1, sp, 0x18
	ldr r0, _0803CD04
	ldm r0!, {r2,r3,r5}
	stm r1!, {r2,r3,r5}
	ldm r0!, {r2,r3,r5}
	stm r1!, {r2,r3,r5}
	bl ResetUnusedInputStruct
	mov r0, sp
	movs r1, 0x1
	movs r2, 0
	bl sub_800641C
	movs r0, 0x1
	bl sub_8008C54
	movs r0, 0x1
	bl sub_80073B8
	adds r0, r4, 0
	bl GetDialogueSpriteDataPtr
	adds r5, r0, 0
	ldr r0, [r5, 0x4]
	ldr r6, [r0, 0xC]
	movs r4, 0
	movs r7, 0x8
_0803CCC8:
	adds r0, r4, 0
	adds r0, 0xE0
	ldr r1, [r5, 0x4]
	adds r1, r7
	lsls r2, r4, 2
	ldr r1, [r1]
	adds r1, r2
	bl SetBGPaletteBufferColorArray
	adds r4, 0x1
	cmp r4, 0xF
	ble _0803CCC8
	movs r0, 0x1
	adds r1, r6, 0
	movs r2, 0xE
	bl sub_800836C
	adds r0, r5, 0
	bl CloseFile
	movs r0, 0x1
	bl sub_80073E0
	add sp, 0x60
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_0803CD00: .4byte gUnknown_203B400
_0803CD04: .4byte gUnknown_80F4244
	thumb_func_end sub_803CC80

	thumb_func_start sub_803CD08
sub_803CD08:
	push {r4-r7,lr}
	adds r4, r0, 0
	lsls r4, 16
	asrs r4, 16
	bl sub_803CEAC
	ldr r5, _0803CDB0
	ldr r0, [r5]
	movs r3, 0
	movs r1, 0
	strh r4, [r0]
	str r1, [r0, 0x4C]
	adds r1, r0, 0
	adds r1, 0x54
	str r1, [r0, 0x50]
	ldr r0, _0803CDB4
	ldm r0!, {r2,r4,r6}
	stm r1!, {r2,r4,r6}
	ldm r0!, {r2,r4,r7}
	stm r1!, {r2,r4,r7}
	ldr r1, [r5]
	adds r1, 0x6C
	ldr r0, _0803CDB8
	ldm r0!, {r2,r6,r7}
	stm r1!, {r2,r6,r7}
	ldm r0!, {r4,r6,r7}
	stm r1!, {r4,r6,r7}
	ldr r1, [r5]
	ldr r2, _0803CDBC
	adds r1, 0x84
	adds r0, r2, 0
	ldm r0!, {r4,r6,r7}
	stm r1!, {r4,r6,r7}
	ldm r0!, {r4,r6,r7}
	stm r1!, {r4,r6,r7}
	ldr r0, [r5]
	adds r0, 0x9C
	ldm r2!, {r1,r4,r6}
	stm r0!, {r1,r4,r6}
	ldm r2!, {r1,r4,r7}
	stm r0!, {r1,r4,r7}
	ldr r0, [r5]
	ldr r1, [r0, 0x50]
	adds r0, 0xB4
	str r0, [r1, 0x14]
	movs r1, 0x1
	strb r1, [r0]
	ldr r0, [r5]
	adds r0, 0xB5
	strb r3, [r0]
	ldr r0, [r5]
	adds r0, 0xB6
	movs r1, 0x6
	strb r1, [r0]
	ldr r0, [r5]
	adds r0, 0xB7
	strb r3, [r0]
	bl ResetUnusedInputStruct
	ldr r0, [r5]
	adds r0, 0x54
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	ldr r4, [r5]
	adds r4, 0x18
	bl GetValidPartners
	adds r1, r0, 0
	ldr r0, [r5]
	ldr r3, [r0, 0x4C]
	adds r0, r4, 0
	movs r2, 0xA
	bl sub_8013818
	bl sub_803CEF0
	bl sub_803CFC0
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_0803CDB0: .4byte gUnknown_203B404
_0803CDB4: .4byte gUnknown_80F4290
_0803CDB8: .4byte gUnknown_80F42A8
_0803CDBC: .4byte gUnknown_80F4278
	thumb_func_end sub_803CD08

	thumb_func_start sub_803CDC0
sub_803CDC0:
	push {r4,r5,lr}
	ldr r4, _0803CDF0
	ldr r1, [r4]
	movs r0, 0x30
	ldrsh r5, [r1, r0]
	movs r0, 0
	strb r0, [r1, 0x16]
	ldr r0, [r4]
	adds r0, 0x18
	bl GetKeyPress
	cmp r0, 0x1
	bne _0803CDF4
	movs r0, 0
	bl sub_80119D4
	ldr r0, [r4]
	movs r2, 0x30
	ldrsh r1, [r0, r2]
	lsls r1, 1
	adds r0, 0x2
	adds r0, r1
	ldrh r0, [r0]
	b _0803CE2A
	.align 2, 0
_0803CDF0: .4byte gUnknown_203B404
_0803CDF4:
	ldr r0, [r4]
	adds r0, 0x18
	movs r1, 0x1
	bl sub_80138B8
	lsls r0, 24
	cmp r0, 0
	beq _0803CE08
	bl sub_803CEF0
_0803CE08:
	ldr r0, [r4]
	movs r1, 0x30
	ldrsh r0, [r0, r1]
	cmp r5, r0
	beq _0803CE16
	bl sub_803CFC0
_0803CE16:
	ldr r0, [r4]
	ldrb r0, [r0, 0x16]
	cmp r0, 0
	bne _0803CE28
	ldr r0, _0803CE24
	b _0803CE2A
	.align 2, 0
_0803CE24: .4byte 0x0000ffff
_0803CE28:
	ldr r0, _0803CE30
_0803CE2A:
	pop {r4,r5}
	pop {r1}
	bx r1
	.align 2, 0
_0803CE30: .4byte 0x0000fffe
	thumb_func_end sub_803CDC0

	thumb_func_start sub_803CE34
sub_803CE34:
	push {r4,r5,lr}
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	bl GetValidPartners
	adds r1, r0, 0
	ldr r5, _0803CE68
	ldr r0, [r5]
	strh r1, [r0, 0x3A]
	adds r0, 0x18
	bl sub_8013984
	bl sub_803CEF0
	bl sub_803CFC0
	cmp r4, 0
	beq _0803CE62
	ldr r0, [r5]
	adds r0, 0x18
	bl AddMenuCursorSprite
_0803CE62:
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_0803CE68: .4byte gUnknown_203B404
	thumb_func_end sub_803CE34

	thumb_func_start sub_803CE6C
sub_803CE6C:
	push {r4,r5,lr}
	ldr r4, _0803CEA4
	ldr r1, [r4]
	ldr r2, [r1, 0x4C]
	lsls r0, r2, 1
	adds r0, r2
	lsls r0, 3
	adds r1, r0
	adds r1, 0x54
	ldr r0, _0803CEA8
	ldm r0!, {r2,r3,r5}
	stm r1!, {r2,r3,r5}
	ldm r0!, {r2,r3,r5}
	stm r1!, {r2,r3,r5}
	bl ResetUnusedInputStruct
	ldr r0, [r4]
	adds r0, 0x54
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	bl sub_803CECC
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_0803CEA4: .4byte gUnknown_203B404
_0803CEA8: .4byte gUnknown_80F4278
	thumb_func_end sub_803CE6C

	thumb_func_start sub_803CEAC
sub_803CEAC:
	push {r4,lr}
	ldr r4, _0803CEC4
	movs r0, 0xB8
	movs r1, 0x8
	bl MemoryAlloc
	str r0, [r4]
	bl nullsub_135
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0803CEC4: .4byte gUnknown_203B404
	thumb_func_end sub_803CEAC

	thumb_func_start nullsub_135
nullsub_135:
	bx lr
	thumb_func_end nullsub_135

	thumb_func_start sub_803CECC
sub_803CECC:
	push {r4,lr}
	ldr r4, _0803CEEC
	ldr r0, [r4]
	cmp r0, 0
	beq _0803CEE4
	bl nullsub_135
	ldr r0, [r4]
	bl MemoryFree
	movs r0, 0
	str r0, [r4]
_0803CEE4:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0803CEEC: .4byte gUnknown_203B404
	thumb_func_end sub_803CECC

	thumb_func_start sub_803CEF0
sub_803CEF0:
	push {r4-r6,lr}
	sub sp, 0x4
	ldr r6, _0803CF60
	ldr r0, [r6]
	movs r1, 0x32
	ldrsh r0, [r0, r1]
	movs r1, 0xC
	bl sub_80095E4
	adds r0, 0x2
	lsls r0, 16
	ldr r2, [r6]
	ldr r3, [r2, 0x4C]
	lsls r1, r3, 1
	adds r1, r3
	lsls r1, 3
	adds r1, r2, r1
	adds r1, 0x62
	movs r4, 0
	asrs r3, r0, 16
	lsrs r0, 16
	strh r0, [r1]
	ldr r1, [r2, 0x4C]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 3
	adds r2, r0
	adds r3, 0x2
	adds r2, 0x64
	strh r3, [r2]
	bl ResetUnusedInputStruct
	ldr r0, [r6]
	adds r0, 0x54
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	ldr r0, [r6]
	ldr r0, [r0, 0x4C]
	bl sub_8008C54
	ldr r0, [r6]
	ldr r0, [r0, 0x4C]
	bl sub_80073B8
	ldr r2, _0803CF64
	ldr r0, [r6]
	ldr r3, [r0, 0x4C]
	str r4, [sp]
	movs r0, 0xC
	movs r1, 0
	bl xxx_call_draw_string
	movs r5, 0
	b _0803CF98
	.align 2, 0
_0803CF60: .4byte gUnknown_203B404
_0803CF64: .4byte gUnknown_80F42C0
_0803CF68:
	ldr r0, [r6]
	adds r0, 0x18
	adds r1, r5, 0
	bl sub_8013800
	adds r4, r0, 0
	ldr r0, [r6]
	lsls r1, r5, 1
	adds r0, 0x2
	adds r0, r1
	movs r1, 0
	ldrsh r0, [r0, r1]
	bl sub_808D994
	adds r2, r0, 0
	ldr r0, [r6]
	ldr r3, [r0, 0x4C]
	movs r0, 0
	str r0, [sp]
	movs r0, 0x8
	adds r1, r4, 0
	bl xxx_call_draw_string
	adds r5, 0x1
_0803CF98:
	ldr r0, [r6]
	movs r1, 0x32
	ldrsh r0, [r0, r1]
	cmp r5, r0
	blt _0803CF68
	ldr r4, _0803CFBC
	ldr r0, [r4]
	ldr r0, [r0, 0x4C]
	bl sub_80073E0
	ldr r1, [r4]
	movs r0, 0x1
	strb r0, [r1, 0x16]
	add sp, 0x4
	pop {r4-r6}
	pop {r0}
	bx r0
	.align 2, 0
_0803CFBC: .4byte gUnknown_203B404
	thumb_func_end sub_803CEF0

	thumb_func_start sub_803CFC0
sub_803CFC0:
	push {r4-r7,lr}
	ldr r0, _0803D02C
	ldr r0, [r0]
	movs r2, 0x30
	ldrsh r1, [r0, r2]
	lsls r1, 1
	adds r0, 0x2
	adds r0, r1
	movs r1, 0
	ldrsh r4, [r0, r1]
	movs r0, 0x1
	bl sub_8008C54
	movs r0, 0x1
	bl sub_80073B8
	adds r0, r4, 0
	bl GetDialogueSpriteDataPtr
	adds r5, r0, 0
	ldr r0, [r5, 0x4]
	ldr r6, [r0, 0x4]
	movs r4, 0
	movs r7, 0
_0803CFF0:
	adds r0, r4, 0
	adds r0, 0xE0
	ldr r1, [r5, 0x4]
	adds r1, r7
	lsls r2, r4, 2
	ldr r1, [r1]
	adds r1, r2
	bl SetBGPaletteBufferColorArray
	adds r4, 0x1
	cmp r4, 0xF
	ble _0803CFF0
	movs r0, 0x1
	adds r1, r6, 0
	movs r2, 0xE
	bl sub_800836C
	adds r0, r5, 0
	bl CloseFile
	movs r0, 0x1
	bl sub_80073E0
	ldr r0, _0803D02C
	ldr r1, [r0]
	movs r0, 0x1
	strb r0, [r1, 0x16]
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_0803D02C: .4byte gUnknown_203B404
	thumb_func_end sub_803CFC0

        .align 2,0
