	#include "asm/constants/gba_constants.inc"
  	#include "asm/macros.inc"

  	.syntax unified

  	.text

	thumb_func_start sub_803E874
sub_803E874:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x8
	mov r9, r1
	lsls r0, 24
	lsrs r0, 24
	mov r10, r0
	ldr r0, _0803E9A4
	ldr r0, [r0]
	ldr r5, [r0, 0x4]
	ldr r1, _0803E9A8
	ldr r0, _0803E9AC
	ldr r2, [r0]
	ldr r0, _0803E9B0
	ldr r3, [r0]
	movs r0, 0xBE
	lsls r0, 1
	adds r3, r0
	movs r0, 0
	bl SetBGPaletteBufferColorRGB
	adds r5, 0x4
	movs r6, 0x1
	movs r4, 0x9F
_0803E8AA:
	ldr r1, _0803E9AC
	mov r8, r1
	ldr r2, [r1]
	ldr r7, _0803E9B0
	ldr r3, [r7]
	movs r0, 0xBE
	lsls r0, 1
	adds r3, r0
	adds r0, r6, 0
	adds r1, r5, 0
	bl SetBGPaletteBufferColorRGB
	adds r5, 0x4
	adds r6, 0x1
	subs r4, 0x1
	cmp r4, 0
	bne _0803E8AA
	ldr r3, [r7]
	ldr r1, _0803E9B4
	adds r0, r3, r1
	ldrb r0, [r0]
	cmp r0, 0
	beq _0803E8E2
	ldr r2, _0803E9B8
	adds r0, r3, r2
	ldr r0, [r0]
	cmp r0, 0x3
	bne _0803E8FC
_0803E8E2:
	ldr r1, _0803E9BC
	mov r2, r8
	ldr r0, [r2]
	str r0, [sp]
	movs r2, 0xBE
	lsls r2, 1
	adds r0, r3, r2
	str r0, [sp, 0x4]
	movs r0, 0x1
	movs r2, 0xA0
	movs r3, 0x20
	bl sub_8004AF0
_0803E8FC:
	adds r6, 0x20
	ldr r5, _0803E9C0
	movs r4, 0x20
_0803E902:
	ldr r0, _0803E9AC
	ldr r2, [r0]
	ldr r0, _0803E9B0
	ldr r3, [r0]
	movs r0, 0xBE
	lsls r0, 1
	adds r3, r0
	adds r0, r6, 0
	adds r1, r5, 0
	bl SetBGPaletteBufferColorRGB
	adds r5, 0x4
	adds r6, 0x1
	subs r4, 0x1
	cmp r4, 0
	bne _0803E902
	mov r1, r10
	cmp r1, 0
	beq _0803E948
	movs r6, 0xE0
	ldr r0, _0803E9C4
	ldr r0, [r0]
	ldr r5, [r0, 0x4]
	movs r4, 0x10
_0803E932:
	adds r0, r6, 0
	adds r1, r5, 0
	mov r2, r9
	movs r3, 0
	bl SetBGPaletteBufferColorRGB
	adds r5, 0x4
	adds r6, 0x1
	subs r4, 0x1
	cmp r4, 0
	bne _0803E932
_0803E948:
	ldr r1, _0803E9C8
	ldr r4, _0803E9AC
	ldr r2, [r4]
	movs r0, 0xF8
	movs r3, 0
	bl SetBGPaletteBufferColorRGB
	ldr r0, _0803E9B0
	ldr r0, [r0]
	ldr r2, _0803E9CC
	adds r0, r2
	ldr r0, [r0]
	ldr r5, [r0, 0x4]
	movs r6, 0x80
	lsls r6, 1
	adds r7, r4, 0
	movs r4, 0xD0
_0803E96A:
	ldr r2, [r7]
	ldr r0, _0803E9B0
	ldr r3, [r0]
	movs r0, 0xBE
	lsls r0, 1
	adds r3, r0
	adds r0, r6, 0
	adds r1, r5, 0
	bl SetBGPaletteBufferColorRGB
	ldr r2, [r7]
	adds r0, r6, 0
	adds r1, r5, 0
	movs r3, 0
	bl nullsub_4
	adds r5, 0x4
	adds r6, 0x1
	subs r4, 0x1
	cmp r4, 0
	bne _0803E96A
	add sp, 0x8
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_0803E9A4: .4byte gDungeonPaletteFile
_0803E9A8: .4byte gUnknown_80F62AC
_0803E9AC: .4byte gUnknown_202EDC8
_0803E9B0: .4byte gDungeon
_0803E9B4: .4byte 0x00018215
_0803E9B8: .4byte 0x0001c06c
_0803E9BC: .4byte gUnknown_202EE8C
_0803E9C0: .4byte gUnknown_202ECA4
_0803E9C4: .4byte gDungeonNameBannerPalette
_0803E9C8: .4byte gUnknown_202D058
_0803E9CC: .4byte 0x000181e4
	thumb_func_end sub_803E874

	thumb_func_start sub_803E9D0
sub_803E9D0:
	push {r4-r7,lr}
	ldr r0, _0803EA04
	ldr r0, [r0]
	ldr r1, _0803EA08
	adds r0, r1
	ldr r0, [r0]
	ldr r4, [r0, 0x4]
	movs r6, 0x80
	lsls r6, 1
	ldr r7, _0803EA0C
	movs r5, 0xD0
_0803E9E6:
	ldr r2, [r7]
	adds r0, r6, 0
	adds r1, r4, 0
	movs r3, 0
	bl nullsub_4
	adds r4, 0x4
	adds r6, 0x1
	subs r5, 0x1
	cmp r5, 0
	bne _0803E9E6
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_0803EA04: .4byte gDungeon
_0803EA08: .4byte 0x000181e4
_0803EA0C: .4byte gUnknown_202EDC8
	thumb_func_end sub_803E9D0

	thumb_func_start sub_803EA10
sub_803EA10:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0x8
	ldr r0, _0803EACC
	ldr r0, [r0]
	ldr r4, [r0, 0x4]
	ldr r1, _0803EAD0
	ldr r0, _0803EAD4
	ldr r2, [r0]
	ldr r0, _0803EAD8
	ldr r3, [r0]
	movs r0, 0xBE
	lsls r0, 1
	adds r3, r0
	movs r0, 0
	bl SetBGPaletteBufferColorRGB
	adds r4, 0x4
	movs r6, 0x1
	movs r5, 0x9F
_0803EA3A:
	ldr r1, _0803EAD4
	mov r8, r1
	ldr r2, [r1]
	ldr r7, _0803EAD8
	ldr r3, [r7]
	movs r0, 0xBE
	lsls r0, 1
	adds r3, r0
	adds r0, r6, 0
	adds r1, r4, 0
	bl SetBGPaletteBufferColorRGB
	adds r4, 0x4
	adds r6, 0x1
	subs r5, 0x1
	cmp r5, 0
	bne _0803EA3A
	ldr r3, [r7]
	ldr r1, _0803EADC
	adds r0, r3, r1
	ldrb r0, [r0]
	cmp r0, 0
	beq _0803EA72
	ldr r2, _0803EAE0
	adds r0, r3, r2
	ldr r0, [r0]
	cmp r0, 0x3
	bne _0803EA8C
_0803EA72:
	ldr r1, _0803EAE4
	mov r2, r8
	ldr r0, [r2]
	str r0, [sp]
	movs r2, 0xBE
	lsls r2, 1
	adds r0, r3, r2
	str r0, [sp, 0x4]
	movs r0, 0x1
	movs r2, 0xA0
	movs r3, 0x20
	bl sub_8004AF0
_0803EA8C:
	adds r6, 0x20
	ldr r4, _0803EAE8
	movs r5, 0x20
_0803EA92:
	ldr r7, _0803EAD4
	ldr r2, [r7]
	ldr r0, _0803EAD8
	ldr r3, [r0]
	movs r0, 0xBE
	lsls r0, 1
	adds r3, r0
	adds r0, r6, 0
	adds r1, r4, 0
	bl SetBGPaletteBufferColorRGB
	adds r4, 0x4
	adds r6, 0x1
	subs r5, 0x1
	cmp r5, 0
	bne _0803EA92
	ldr r1, _0803EAEC
	ldr r2, [r7]
	movs r0, 0xF8
	movs r3, 0
	bl SetBGPaletteBufferColorRGB
	add sp, 0x8
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_0803EACC: .4byte gDungeonPaletteFile
_0803EAD0: .4byte gUnknown_80F62AC
_0803EAD4: .4byte gUnknown_202EDC8
_0803EAD8: .4byte gDungeon
_0803EADC: .4byte 0x00018215
_0803EAE0: .4byte 0x0001c06c
_0803EAE4: .4byte gUnknown_202EE8C
_0803EAE8: .4byte gUnknown_202ECA4
_0803EAEC: .4byte gUnknown_202D058
	thumb_func_end sub_803EA10

	thumb_func_start sub_803EAF0
sub_803EAF0:
	push {r4,r5,lr}
	adds r4, r0, 0
	adds r5, r1, 0
	ldr r0, _0803EB20
	ldr r0, [r0]
	cmp r4, r0
	bne _0803EB00
	b _0803EC88
_0803EB00:
	cmp r4, 0x5
	bne _0803EB06
	b _0803EC1C
_0803EB06:
	cmp r4, 0x5
	bhi _0803EB2E
	cmp r4, 0x2
	bne _0803EB10
	b _0803EBFC
_0803EB10:
	cmp r4, 0x2
	bhi _0803EB24
	cmp r4, 0
	beq _0803EB70
	cmp r4, 0x1
	beq _0803EB50
	b _0803EC84
	.align 2, 0
_0803EB20: .4byte gUnknown_202EDD0
_0803EB24:
	cmp r4, 0x3
	beq _0803EB98
	cmp r4, 0x4
	beq _0803EBFC
	b _0803EC84
_0803EB2E:
	cmp r4, 0x8
	bne _0803EB34
	b _0803EC34
_0803EB34:
	cmp r4, 0x8
	bhi _0803EB42
	cmp r4, 0x6
	beq _0803EBBC
	cmp r4, 0x7
	beq _0803EBDC
	b _0803EC84
_0803EB42:
	cmp r4, 0xA
	bne _0803EB48
	b _0803EC80
_0803EB48:
	cmp r4, 0xA
	bcs _0803EB4E
	b _0803EC54
_0803EB4E:
	b _0803EC84
_0803EB50:
	ldr r0, _0803EB6C
	ldrb r0, [r0]
	cmp r0, 0
	beq _0803EB5E
	movs r0, 0
	bl sub_8052210
_0803EB5E:
	bl ResetUnusedInputStruct
	bl sub_803EC94
	movs r0, 0
	movs r1, 0x1
	b _0803EC6E
	.align 2, 0
_0803EB6C: .4byte gUnknown_203B40C
_0803EB70:
	bl sub_803EC94
	movs r0, 0
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	ldr r0, _0803EB94
	ldrb r0, [r0]
	cmp r0, 0
	bne _0803EB88
	b _0803EC84
_0803EB88:
	bl sub_8040A84
	movs r0, 0
	bl sub_8040ABC
	b _0803EC84
	.align 2, 0
_0803EB94: .4byte gUnknown_203B40C
_0803EB98:
	ldr r0, _0803EBB4
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	ldr r0, _0803EBB8
	ldrb r0, [r0]
	cmp r0, 0
	beq _0803EC84
	movs r0, 0x1
	bl sub_8040ABC
	b _0803EC84
	.align 2, 0
_0803EBB4: .4byte gUnknown_80F62B0
_0803EBB8: .4byte gUnknown_203B40C
_0803EBBC:
	ldr r0, _0803EBD4
	ldrb r0, [r0]
	cmp r0, 0
	beq _0803EBCA
	movs r0, 0
	bl sub_8052210
_0803EBCA:
	bl ResetUnusedInputStruct
	ldr r0, _0803EBD8
	movs r1, 0x1
	b _0803EC6E
	.align 2, 0
_0803EBD4: .4byte gUnknown_203B40C
_0803EBD8: .4byte gUnknown_80F6310
_0803EBDC:
	ldr r0, _0803EBF4
	ldrb r0, [r0]
	cmp r0, 0
	beq _0803EBEA
	movs r0, 0
	bl sub_8052210
_0803EBEA:
	bl ResetUnusedInputStruct
	ldr r0, _0803EBF8
	movs r1, 0x1
	b _0803EC6E
	.align 2, 0
_0803EBF4: .4byte gUnknown_203B40C
_0803EBF8: .4byte gUnknown_80F6370
_0803EBFC:
	ldr r0, _0803EC18
	ldrb r0, [r0]
	cmp r0, 0
	beq _0803EC0A
	movs r0, 0
	bl sub_8052210
_0803EC0A:
	bl ResetUnusedInputStruct
	bl sub_803EC94
	movs r0, 0
	movs r1, 0x1
	b _0803EC6E
	.align 2, 0
_0803EC18: .4byte gUnknown_203B40C
_0803EC1C:
	ldr r0, _0803EC30
	ldrb r0, [r0]
	cmp r0, 0
	beq _0803EC2A
	movs r0, 0
	bl sub_8052210
_0803EC2A:
	movs r0, 0
	movs r1, 0x1
	b _0803EC6E
	.align 2, 0
_0803EC30: .4byte gUnknown_203B40C
_0803EC34:
	ldr r0, _0803EC50
	ldrb r0, [r0]
	cmp r0, 0
	beq _0803EC46
	bl sub_8083D44
	movs r0, 0
	bl sub_8052210
_0803EC46:
	movs r0, 0x2
	adds r1, r5, 0
	bl CreateConfirmNameMenu
	b _0803EC84
	.align 2, 0
_0803EC50: .4byte gUnknown_203B40C
_0803EC54:
	ldr r0, _0803EC78
	ldrb r0, [r0]
	cmp r0, 0
	beq _0803EC66
	movs r0, 0
	bl sub_8052210
	bl sub_8083D44
_0803EC66:
	bl ResetUnusedInputStruct
	ldr r0, _0803EC7C
	movs r1, 0
_0803EC6E:
	movs r2, 0x1
	bl sub_800641C
	b _0803EC84
	.align 2, 0
_0803EC78: .4byte gUnknown_203B40C
_0803EC7C: .4byte gUnknown_80F63D0
_0803EC80:
	bl sub_8083D44
_0803EC84:
	ldr r0, _0803EC90
	str r4, [r0]
_0803EC88:
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_0803EC90: .4byte gUnknown_202EDD0
	thumb_func_end sub_803EAF0

	thumb_func_start sub_803EC94
sub_803EC94:
	push {lr}
	ldr r0, _0803ECB0
	movs r1, 0
	strh r1, [r0, 0x1E]
	strh r1, [r0, 0x20]
	strh r1, [r0, 0xC]
	strh r1, [r0, 0xE]
	strh r1, [r0, 0x14]
	adds r0, 0x28
	bl sub_801317C
	pop {r0}
	bx r0
	.align 2, 0
_0803ECB0: .4byte gUnknown_202EE10
	thumb_func_end sub_803EC94

	thumb_func_start sub_803ECB4
sub_803ECB4:
	push {r4,r5,lr}
	adds r5, r0, 0
	lsls r4, r1, 24
	lsrs r4, 24
	ldr r1, _0803ECDC
	movs r0, 0xA
	str r0, [r1]
	movs r0, 0
	bl sub_8052210
	bl ResetUnusedInputStruct
	adds r0, r5, 0
	movs r1, 0x1
	adds r2, r4, 0
	bl sub_800641C
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_0803ECDC: .4byte gUnknown_202EDD0
	thumb_func_end sub_803ECB4

	thumb_func_start sub_803ECE0
sub_803ECE0:
	push {lr}
	ldr r1, _0803ED24
	ldr r0, [r1]
	adds r0, 0x1
	str r0, [r1]
	cmp r0, 0
	bge _0803ECF2
	movs r0, 0
	str r0, [r1]
_0803ECF2:
	ldr r0, [r1]
	cmp r0, 0xB
	ble _0803ECFC
	movs r0, 0
	str r0, [r1]
_0803ECFC:
	ldr r0, _0803ED28
	ldr r2, [r0]
	ldr r0, [r1]
	cmp r0, 0
	bge _0803ED08
	adds r0, 0x3
_0803ED08:
	asrs r1, r0, 2
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 6
	ldr r1, [r2, 0x4]
	adds r1, r0
	movs r2, 0x90
	lsls r2, 2
	ldr r0, _0803ED2C
	bl sub_80098BC
	pop {r0}
	bx r0
	.align 2, 0
_0803ED24: .4byte gUnknown_202EDD8
_0803ED28: .4byte gUnknown_202EC94
_0803ED2C: .4byte 0x06014400
	thumb_func_end sub_803ECE0

	thumb_func_start sub_803ED30
sub_803ED30:
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	adds r5, r0, 0
	adds r7, r1, 0
	mov r9, r3
	lsls r2, 24
	lsrs r2, 24
	mov r8, r2
	cmp r5, 0
	beq _0803EDDA
	ldr r0, _0803EDAC
	ldr r0, [r0]
	ldr r1, _0803EDB0
	adds r0, r1
	ldrb r0, [r0]
	cmp r0, 0
	bne _0803EDDA
	movs r4, 0
	ldr r1, _0803EDB4
	movs r2, 0
	ldrsh r0, [r1, r2]
	cmp r0, 0
	beq _0803ED78
	adds r6, r1, 0
_0803ED64:
	movs r0, 0x29
	bl sub_803E46C
	adds r4, 0x1
	cmp r4, 0x13
	bgt _0803ED78
	movs r1, 0
	ldrsh r0, [r6, r1]
	cmp r0, 0
	bne _0803ED64
_0803ED78:
	adds r0, r5, 0
	mov r1, r8
	bl sub_803EF90
	ldr r3, _0803EDB4
	movs r2, 0
	movs r1, 0x3C
	strh r1, [r3]
	str r7, [r3, 0x4]
	ldrh r1, [r7, 0x26]
	str r1, [r3, 0x8]
	lsls r1, r0, 1
	adds r1, r0
	lsls r1, 8
	negs r1, r1
	str r1, [r3, 0xC]
	str r2, [r3, 0x10]
	mov r2, r9
	cmp r2, 0
	bge _0803EDC8
	ldr r0, _0803EDB8
	cmp r5, r0
	bge _0803EDBC
	movs r0, 0x6
	b _0803EDCA
	.align 2, 0
_0803EDAC: .4byte gDungeon
_0803EDB0: .4byte 0x0001820a
_0803EDB4: .4byte gUnknown_202EDE8
_0803EDB8: .4byte 0xfffffc19
_0803EDBC:
	cmp r5, 0
	blt _0803EDC4
	movs r0, 0xA
	b _0803EDCA
_0803EDC4:
	movs r0, 0x3
	b _0803EDCA
_0803EDC8:
	mov r0, r9
_0803EDCA:
	strh r0, [r3, 0x2]
	ldr r0, _0803EDE8
	ldr r1, _0803EDEC
	ldr r1, [r1]
	adds r1, 0x18
	movs r2, 0x80
	bl sub_80098BC
_0803EDDA:
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_0803EDE8: .4byte 0x060142c0
_0803EDEC: .4byte gDungeon
	thumb_func_end sub_803ED30

	thumb_func_start sub_803EDF0
sub_803EDF0:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	ldr r6, _0803EE18
	movs r1, 0
	ldrsh r0, [r6, r1]
	cmp r0, 0
	bne _0803EE06
	b _0803EF42
_0803EE06:
	ldr r0, [r6, 0x4]
	bl EntityExists
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0
	bne _0803EE1C
	strh r0, [r6]
	b _0803EF42
	.align 2, 0
_0803EE18: .4byte gUnknown_202EDE8
_0803EE1C:
	ldr r1, [r6, 0x4]
	ldr r0, [r6, 0x8]
	ldrh r2, [r1, 0x26]
	cmp r0, r2
	beq _0803EE2C
	movs r0, 0
	strh r0, [r6]
	b _0803EF42
_0803EE2C:
	ldrh r0, [r6]
	subs r0, 0x1
	strh r0, [r6]
	ldr r4, [r6, 0x10]
	adds r3, r4, 0
	subs r3, 0x2E
	str r3, [r6, 0x10]
	ldr r2, [r1, 0x70]
	movs r5, 0xB8
	lsls r5, 1
	adds r0, r2, r5
	movs r1, 0
	ldrsh r0, [r0, r1]
	ldr r1, [r6, 0xC]
	cmp r1, 0
	bge _0803EE4E
	adds r1, 0xFF
_0803EE4E:
	asrs r1, 8
	adds r1, r0, r1
	ldr r0, _0803EF50
	ldr r0, [r0]
	mov r12, r0
	ldr r0, _0803EF54
	add r0, r12
	movs r5, 0
	ldrsh r0, [r0, r5]
	subs r7, r1, r0
	movs r1, 0xB9
	lsls r1, 1
	adds r0, r2, r1
	movs r2, 0
	ldrsh r0, [r0, r2]
	adds r1, r3, 0
	cmp r1, 0
	bge _0803EE76
	adds r1, r4, 0
	adds r1, 0xD1
_0803EE76:
	asrs r1, 8
	adds r1, r0, r1
	ldr r0, _0803EF58
	add r0, r12
	movs r3, 0
	ldrsh r0, [r0, r3]
	adds r0, 0x18
	subs r2, r1, r0
	movs r0, 0x20
	negs r0, r0
	cmp r7, r0
	blt _0803EF42
	adds r0, 0x18
	cmp r2, r0
	blt _0803EF42
	cmp r7, 0xEF
	bgt _0803EF42
	cmp r2, 0x9F
	bgt _0803EF42
	ldr r1, _0803EF5C
	ands r1, r2
	lsls r1, 4
	ldr r0, _0803EF60
	ldrh r2, [r0, 0x6]
	movs r4, 0xF
	mov r8, r4
	mov r3, r8
	ands r3, r2
	orrs r3, r1
	strh r3, [r0, 0x6]
	ldrh r2, [r0]
	ldr r1, _0803EF64
	ands r1, r2
	ldr r2, _0803EF68
	ands r1, r2
	movs r5, 0x3
	mov r9, r5
	ldr r2, _0803EF6C
	mov r10, r2
	ands r1, r2
	ldr r2, _0803EF70
	ands r1, r2
	ldr r2, _0803EF74
	ands r1, r2
	movs r5, 0x80
	lsls r5, 7
	ldr r4, _0803EF78
	ands r1, r4
	orrs r1, r5
	strh r1, [r0]
	ldr r1, _0803EF7C
	ands r7, r1
	ldrh r2, [r0, 0x2]
	movs r1, 0xFE
	lsls r1, 8
	ands r1, r2
	orrs r1, r7
	ldr r2, _0803EF80
	ands r1, r2
	ands r1, r4
	orrs r1, r5
	strh r1, [r0, 0x2]
	ldr r4, _0803EF84
	ldrh r2, [r0, 0x4]
	movs r1, 0xFC
	lsls r1, 8
	ands r1, r2
	orrs r1, r4
	movs r2, 0
	orrs r1, r2
	strh r1, [r0, 0x4]
	ldr r2, _0803EF88
	add r2, r12
	ldrb r2, [r2]
	mov r4, r9
	ands r2, r4
	lsls r2, 10
	mov r5, r10
	ands r1, r5
	orrs r1, r2
	movs r4, 0x2
	ldrsh r2, [r6, r4]
	mov r5, r8
	ands r2, r5
	lsls r2, 12
	ldr r4, _0803EF5C
	ands r1, r4
	orrs r1, r2
	strh r1, [r0, 0x4]
	ldr r1, _0803EF8C
	ands r3, r1
	subs r1, 0x1
	ands r3, r1
	subs r1, 0x2
	ands r3, r1
	strh r3, [r0, 0x6]
	movs r1, 0x80
	lsls r1, 1
	movs r2, 0
	movs r3, 0
	bl AddSprite
_0803EF42:
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_0803EF50: .4byte gDungeon
_0803EF54: .4byte 0x000181f0
_0803EF58: .4byte 0x000181f2
_0803EF5C: .4byte 0x00000fff
_0803EF60: .4byte gUnknown_202EDDC
_0803EF64: .4byte 0x0000feff
_0803EF68: .4byte 0x0000fdff
_0803EF6C: .4byte 0x0000f3ff
_0803EF70: .4byte 0x0000efff
_0803EF74: .4byte 0x0000dfff
_0803EF78: .4byte 0x00003fff
_0803EF7C: .4byte 0x000001ff
_0803EF80: .4byte 0x0000c1ff
_0803EF84: .4byte 0x00000216
_0803EF88: .4byte 0x00018208
_0803EF8C: .4byte 0x0000fffe
	thumb_func_end sub_803EDF0

	thumb_func_start sub_803EF90
sub_803EF90:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x58
	str r0, [sp, 0x48]
	lsls r1, 24
	lsrs r5, r1, 24
	ldr r0, _0803F060
	ldr r0, [r0]
	adds r0, 0x18
	mov r8, r0
	ldr r0, _0803F064
	ldr r1, [r0]
	ldr r0, [r1, 0x4]
	movs r2, 0x92
	lsls r2, 1
	adds r0, r2
	str r0, [sp, 0x24]
	ldr r0, [r1, 0x4]
	movs r3, 0x82
	lsls r3, 1
	adds r0, r3
	str r0, [sp, 0x28]
	ldr r0, [r1, 0x4]
	adds r0, 0xE4
	str r0, [sp, 0x2C]
	ldr r0, [r1, 0x4]
	adds r0, 0xC4
	str r0, [sp, 0x30]
	ldr r0, [r1, 0x4]
	adds r0, 0xA4
	str r0, [sp, 0x34]
	ldr r0, [r1, 0x4]
	adds r0, 0x84
	str r0, [sp, 0x38]
	ldr r0, [r1, 0x4]
	adds r0, 0x64
	str r0, [sp, 0x3C]
	ldr r0, [r1, 0x4]
	adds r0, 0x44
	str r0, [sp, 0x40]
	ldr r0, [r1, 0x4]
	adds r0, 0x24
	str r0, [sp, 0x44]
	add r4, sp, 0x24
	mov r0, sp
	adds r1, r4, 0
	movs r2, 0x24
	bl memcpy
	movs r1, 0
	movs r6, 0x3
	mov r0, r8
_0803EFFE:
	stm r0!, {r1}
	stm r0!, {r1}
	stm r0!, {r1}
	stm r0!, {r1}
	stm r0!, {r1}
	stm r0!, {r1}
	stm r0!, {r1}
	stm r0!, {r1}
	subs r6, 0x1
	cmp r6, 0
	bge _0803EFFE
	ldr r0, _0803F068
	ldr r1, [sp, 0x48]
	cmp r1, r0
	bne _0803F0A6
	adds r0, r4, 0
	ldr r1, _0803F06C
	ldm r1!, {r2,r3,r5}
	stm r0!, {r2,r3,r5}
	ldr r1, [r1]
	str r1, [r0]
	movs r5, 0
	movs r2, 0
	mov r12, r4
	movs r0, 0x20
	mov r10, r0
_0803F032:
	mov r3, r8
	ldr r0, _0803F064
	ldr r1, [r0]
	lsls r0, r2, 2
	add r0, r12
	ldr r0, [r0]
	lsls r0, 5
	adds r0, 0x4
	ldr r1, [r1, 0x4]
	adds r4, r1, r0
	movs r1, 0x18
	adds r1, r5
	mov r9, r1
	adds r2, 0x1
	str r2, [sp, 0x54]
	mov r2, r10
	subs r7, r2, r5
	movs r6, 0x7
_0803F056:
	cmp r5, 0
	bne _0803F070
	movs r1, 0
	ldr r2, [r4]
	b _0803F07A
	.align 2, 0
_0803F060: .4byte gDungeon
_0803F064: .4byte gUnknown_202EC9C
_0803F068: .4byte 0x0000270f
_0803F06C: .4byte gUnknown_80F6478
_0803F070:
	ldr r0, [r4]
	adds r1, r0, 0
	lsrs r1, r7
	adds r2, r0, 0
	lsls r2, r5
_0803F07A:
	adds r4, 0x4
	ldr r0, [r3]
	orrs r0, r2
	str r0, [r3]
	ldr r0, [r3, 0x20]
	orrs r0, r1
	str r0, [r3, 0x20]
	adds r3, 0x4
	subs r6, 0x1
	cmp r6, 0
	bge _0803F056
	mov r5, r9
	cmp r5, 0x1F
	ble _0803F09C
	subs r5, 0x20
	movs r3, 0x20
	add r8, r3
_0803F09C:
	ldr r2, [sp, 0x54]
	cmp r2, 0x3
	ble _0803F032
	movs r0, 0x4
	b _0803F26A
_0803F0A6:
	ldr r0, _0803F0D8
	ldr r1, [sp, 0x48]
	cmp r1, r0
	ble _0803F0B0
	str r0, [sp, 0x48]
_0803F0B0:
	ldr r0, _0803F0DC
	ldr r2, [sp, 0x48]
	cmp r2, r0
	bge _0803F0BA
	str r0, [sp, 0x48]
_0803F0BA:
	ldr r1, _0803F0E0
	ldr r0, [r1]
	ldr r0, [r0, 0x4]
	movs r3, 0xC2
	lsls r3, 1
	adds r2, r0, r3
	cmp r5, 0
	beq _0803F0F4
	ldr r5, [sp, 0x48]
	cmp r5, 0
	ble _0803F0E4
	movs r1, 0xA2
	lsls r1, 1
	adds r2, r0, r1
	b _0803F0F4
	.align 2, 0
_0803F0D8: .4byte 0x000003e7
_0803F0DC: .4byte 0xfffffc19
_0803F0E0: .4byte gUnknown_202EC9C
_0803F0E4:
	ldr r3, [sp, 0x48]
	cmp r3, 0
	bge _0803F0F4
	movs r5, 0xB2
	lsls r5, 1
	adds r2, r0, r5
	negs r3, r3
	str r3, [sp, 0x48]
_0803F0F4:
	ldm r2!, {r0}
	mov r1, r8
	str r0, [r1]
	ldm r2!, {r0}
	str r0, [r1, 0x4]
	ldm r2!, {r0}
	str r0, [r1, 0x8]
	ldm r2!, {r0}
	str r0, [r1, 0xC]
	ldm r2!, {r0}
	str r0, [r1, 0x10]
	ldm r2!, {r0}
	str r0, [r1, 0x14]
	ldm r2!, {r0}
	str r0, [r1, 0x18]
	ldr r0, [r2]
	str r0, [r1, 0x1C]
	movs r5, 0x18
	movs r2, 0x1
	str r2, [sp, 0x4C]
	movs r3, 0
	str r3, [sp, 0x50]
	movs r2, 0
_0803F122:
	movs r0, 0
	mov r10, r0
	adds r1, r2, 0x1
	str r1, [sp, 0x54]
	lsls r0, r2, 3
	adds r0, r2
	lsls r0, 2
	mov r1, sp
	ldr r2, _0803F15C
	adds r7, r0, r2
_0803F136:
	ldr r0, [r7]
	ldr r3, [sp, 0x48]
	cmp r0, r3
	bgt _0803F1A2
	ldr r4, [r1]
	mov r2, r8
	movs r0, 0x18
	adds r0, r5
	mov r9, r0
	movs r1, 0x20
	subs r1, r5
	mov r12, r1
	movs r6, 0x7
_0803F150:
	cmp r5, 0
	bne _0803F160
	movs r3, 0
	ldr r1, [r4]
	b _0803F16C
	.align 2, 0
_0803F15C: .4byte gUnknown_80F6430
_0803F160:
	ldr r0, [r4]
	adds r3, r0, 0
	mov r1, r12
	lsrs r3, r1
	adds r1, r0, 0
	lsls r1, r5
_0803F16C:
	adds r4, 0x4
	ldr r0, [r2]
	orrs r0, r1
	str r0, [r2]
	ldr r0, [r2, 0x20]
	orrs r0, r3
	str r0, [r2, 0x20]
	adds r2, 0x4
	movs r3, 0x1
	str r3, [sp, 0x50]
	subs r6, 0x1
	cmp r6, 0
	bge _0803F150
	mov r5, r9
	cmp r5, 0x1F
	ble _0803F192
	subs r5, 0x20
	movs r0, 0x20
	add r8, r0
_0803F192:
	ldr r0, [r7]
	ldr r1, [sp, 0x48]
	subs r1, r0
	str r1, [sp, 0x48]
	ldr r2, [sp, 0x4C]
	adds r2, 0x1
	str r2, [sp, 0x4C]
	b _0803F1B0
_0803F1A2:
	adds r1, 0x4
	adds r7, 0x4
	movs r3, 0x1
	add r10, r3
	mov r0, r10
	cmp r0, 0x8
	ble _0803F136
_0803F1B0:
	mov r1, r10
	cmp r1, 0x9
	bne _0803F212
	ldr r2, [sp, 0x50]
	cmp r2, 0
	beq _0803F212
	ldr r3, _0803F1DC
	ldr r0, [r3]
	ldr r0, [r0, 0x4]
	adds r4, r0, 0x4
	mov r2, r8
	movs r0, 0x18
	adds r0, r5
	mov r9, r0
	movs r1, 0x20
	subs r7, r1, r5
	movs r6, 0x7
_0803F1D2:
	cmp r5, 0
	bne _0803F1E0
	movs r3, 0
	ldr r1, [r4]
	b _0803F1EA
	.align 2, 0
_0803F1DC: .4byte gUnknown_202EC9C
_0803F1E0:
	ldr r0, [r4]
	adds r3, r0, 0
	lsrs r3, r7
	adds r1, r0, 0
	lsls r1, r5
_0803F1EA:
	adds r4, 0x4
	ldr r0, [r2]
	orrs r0, r1
	str r0, [r2]
	ldr r0, [r2, 0x20]
	orrs r0, r3
	str r0, [r2, 0x20]
	adds r2, 0x4
	subs r6, 0x1
	cmp r6, 0
	bge _0803F1D2
	mov r5, r9
	cmp r5, 0x1F
	ble _0803F20C
	subs r5, 0x20
	movs r2, 0x20
	add r8, r2
_0803F20C:
	ldr r3, [sp, 0x4C]
	adds r3, 0x1
	str r3, [sp, 0x4C]
_0803F212:
	ldr r2, [sp, 0x54]
	cmp r2, 0x1
	ble _0803F122
	ldr r0, _0803F240
	ldr r1, [r0]
	ldr r2, [sp, 0x48]
	lsls r0, r2, 5
	adds r0, 0x4
	ldr r1, [r1, 0x4]
	adds r1, r0
	mov r3, r8
	ldr r0, [sp, 0x4C]
	adds r0, 0x1
	mov r8, r0
	movs r0, 0x20
	subs r7, r0, r5
	movs r6, 0x7
_0803F234:
	cmp r5, 0
	bne _0803F244
	movs r4, 0
	ldr r2, [r1]
	b _0803F24E
	.align 2, 0
_0803F240: .4byte gUnknown_202EC9C
_0803F244:
	ldr r0, [r1]
	adds r4, r0, 0
	lsrs r4, r7
	adds r2, r0, 0
	lsls r2, r5
_0803F24E:
	adds r1, 0x4
	ldr r0, [r3]
	orrs r0, r2
	str r0, [r3]
	ldr r0, [r3, 0x20]
	orrs r0, r4
	str r0, [r3, 0x20]
	adds r3, 0x4
	subs r6, 0x1
	cmp r6, 0
	bge _0803F234
	mov r1, r8
	str r1, [sp, 0x4C]
	adds r0, r1, 0
_0803F26A:
	add sp, 0x58
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_803EF90

	thumb_func_start sub_803F27C
sub_803F27C:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	lsls r0, 24
	lsrs r0, 24
	adds r7, r0, 0
	ldr r0, _0803F360
	mov r8, r0
	ldr r4, [r0]
	ldr r2, _0803F364
	adds r1, r4, r2
	movs r2, 0
	movs r3, 0
	strh r3, [r1, 0x8]
	strh r3, [r1, 0xA]
	strh r3, [r1]
	strh r3, [r1, 0x2]
	strh r3, [r1, 0xC]
	strh r3, [r1, 0xE]
	strh r3, [r1, 0x4]
	strh r3, [r1, 0x6]
	str r3, [r1, 0x14]
	ldr r5, _0803F368
	adds r0, r4, r5
	strb r2, [r0]
	ldr r6, _0803F36C
	adds r0, r4, r6
	movs r5, 0x1
	strb r5, [r0]
	adds r6, 0x1
	adds r0, r4, r6
	strb r5, [r0]
	adds r6, 0x1
	adds r0, r4, r6
	strb r2, [r0]
	str r3, [r1, 0x18]
	str r3, [r1, 0x1C]
	cmp r7, 0
	bne _0803F2FA
	subs r6, 0xF
	adds r0, r4, r6
	strb r2, [r0]
	adds r6, 0x6
	adds r0, r4, r6
	strb r2, [r0]
	subs r6, 0x1
	adds r0, r4, r6
	strb r2, [r0]
	subs r6, 0x2
	adds r0, r4, r6
	strb r2, [r0]
	adds r6, 0x4
	adds r0, r4, r6
	strb r2, [r0]
	subs r6, 0x3
	adds r0, r4, r6
	strb r2, [r0]
	subs r6, 0x3
	adds r0, r4, r6
	strb r2, [r0]
	adds r6, 0x1
	adds r0, r4, r6
	strb r2, [r0]
_0803F2FA:
	str r3, [r1, 0x10]
	ldr r1, _0803F370
	adds r0, r4, r1
	movs r6, 0x3
	strb r6, [r0]
	adds r1, 0x12
	adds r0, r4, r1
	strb r2, [r0]
	subs r1, 0x8
	adds r0, r4, r1
	strb r2, [r0]
	adds r1, 0x9
	adds r0, r4, r1
	strb r2, [r0]
	adds r1, 0x1
	adds r0, r4, r1
	strb r2, [r0]
	subs r1, 0x8
	adds r0, r4, r1
	strb r2, [r0]
	ldr r2, _0803F374
	adds r0, r4, r2
	strb r5, [r0]
	bl sub_803F38C
	ldr r1, _0803F378
	ldr r0, _0803F37C
	str r0, [r1]
	cmp r7, 0
	bne _0803F354
	mov r1, r8
	ldr r0, [r1]
	ldr r2, _0803F380
	adds r0, r2
	ldrb r1, [r0]
	adds r0, r6, 0
	ands r0, r1
	ldr r6, _0803F384
	adds r1, r4, r6
	strb r0, [r1]
	cmp r0, 0
	bne _0803F354
	ldr r1, _0803F388
	adds r0, r4, r1
	strb r5, [r0]
_0803F354:
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_0803F360: .4byte gDungeon
_0803F364: .4byte 0x000181e8
_0803F368: .4byte 0x00018216
_0803F36C: .4byte 0x00018217
_0803F370: .4byte 0x00018208
_0803F374: .4byte 0x00018215
_0803F378: .4byte gUnknown_202EDFC
_0803F37C: .4byte 0x0000ffff
_0803F380: .4byte 0x0001c58a
_0803F384: .4byte 0x00018209
_0803F388: .4byte 0x0001820c
	thumb_func_end sub_803F27C

	thumb_func_start sub_803F38C
sub_803F38C:
	push {r4-r6,lr}
	mov r6, r8
	push {r6}
	ldr r0, _0803F410
	ldr r1, [r0]
	ldr r0, _0803F414
	adds r2, r1, r0
	ldr r0, _0803F418
	strh r0, [r2, 0x3A]
	movs r0, 0x1
	negs r0, r0
	strh r0, [r2, 0x3C]
	strh r0, [r2, 0x3E]
	ldr r0, _0803F41C
	adds r1, r0
	movs r0, 0x1
	negs r0, r0
	strh r0, [r1]
	strh r0, [r2, 0x36]
	strh r0, [r2, 0x38]
	ldr r0, _0803F420
	ldr r0, [r0]
	ldrb r0, [r0, 0xB]
	negs r4, r0
	orrs r4, r0
	asrs r4, 31
	movs r0, 0x80
	lsls r0, 1
	ands r4, r0
	ldr r5, _0803F424
	adds r0, r4, r5
	mov r8, r0
	movs r0, 0xFD
	mov r1, r8
	bl SetBGPaletteBufferColorArray
	adds r6, r5, 0x4
	adds r6, r4, r6
	movs r0, 0xFE
	adds r1, r6, 0
	bl SetBGPaletteBufferColorArray
	adds r5, 0x8
	adds r4, r5
	movs r0, 0xFF
	adds r1, r4, 0
	bl SetBGPaletteBufferColorArray
	movs r0, 0xFD
	mov r1, r8
	bl nullsub_5
	movs r0, 0xFE
	adds r1, r6, 0
	bl nullsub_5
	movs r0, 0xFF
	adds r1, r4, 0
	bl nullsub_5
	pop {r3}
	mov r8, r3
	pop {r4-r6}
	pop {r0}
	bx r0
	.align 2, 0
_0803F410: .4byte gDungeon
_0803F414: .4byte 0x000181e8
_0803F418: .4byte 0x0000ffff
_0803F41C: .4byte 0x00018228
_0803F420: .4byte gGameOptionsRef
_0803F424: .4byte gUnknown_202D06C
	thumb_func_end sub_803F38C

	thumb_func_start sub_803F428
sub_803F428:
	push {r4-r6,lr}
	adds r4, r0, 0
	ldr r0, _0803F484
	ldr r3, [r0]
	ldr r0, _0803F488
	adds r2, r3, r0
	ldr r5, [r2, 0x10]
	movs r6, 0
	ldrsh r1, [r2, r6]
	movs r6, 0
	ldrsh r0, [r4, r6]
	subs r1, r0
	cmp r1, 0
	bge _0803F446
	negs r1, r1
_0803F446:
	cmp r1, 0x6
	bgt _0803F498
	movs r0, 0x2
	ldrsh r1, [r2, r0]
	movs r6, 0x2
	ldrsh r0, [r4, r6]
	subs r1, r0
	cmp r1, 0
	bge _0803F45A
	negs r1, r1
_0803F45A:
	cmp r1, 0x5
	bgt _0803F498
	ldr r1, _0803F48C
	adds r0, r3, r1
	ldrb r0, [r0]
	cmp r0, 0
	bne _0803F494
	ldr r6, _0803F490
	adds r0, r3, r6
	ldrb r0, [r0]
	cmp r0, 0
	bne _0803F494
	cmp r5, 0
	beq _0803F494
	adds r0, r2, 0
	adds r1, r4, 0
	bl IsPositionActuallyInSight
	lsls r0, 24
	lsrs r0, 24
	b _0803F49A
	.align 2, 0
_0803F484: .4byte gDungeon
_0803F488: .4byte 0x000181e8
_0803F48C: .4byte 0x0001820b
_0803F490: .4byte 0x0001820c
_0803F494:
	movs r0, 0x1
	b _0803F49A
_0803F498:
	movs r0, 0
_0803F49A:
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end sub_803F428

	thumb_func_start sub_803F4A0
sub_803F4A0:
	push {lr}
	adds r2, r0, 0
	ldr r0, _0803F4B8
	ldr r1, [r0]
	ldr r3, _0803F4BC
	adds r0, r1, r3
	str r2, [r0, 0x10]
	cmp r2, 0
	bne _0803F4C0
	adds r3, 0x2E
	b _0803F4CA
	.align 2, 0
_0803F4B8: .4byte gDungeon
_0803F4BC: .4byte 0x000181e8
_0803F4C0:
	ldr r0, [r2, 0x70]
	ldrb r2, [r0, 0x7]
	cmp r2, 0
	bne _0803F4D4
	ldr r3, _0803F4D0
_0803F4CA:
	adds r0, r1, r3
	strb r2, [r0]
	b _0803F4DC
	.align 2, 0
_0803F4D0: .4byte 0x00018216
_0803F4D4:
	ldr r0, _0803F4FC
	adds r1, r0
	movs r0, 0x1
	strb r0, [r1]
_0803F4DC:
	movs r0, 0
	bl sub_803F580
	bl sub_803F38C
	ldr r0, _0803F500
	ldr r0, [r0]
	ldr r1, _0803F504
	adds r0, r1
	ldrb r0, [r0]
	cmp r0, 0
	bne _0803F4F8
	bl sub_806CD90
_0803F4F8:
	pop {r0}
	bx r0
	.align 2, 0
_0803F4FC: .4byte 0x00018216
_0803F500: .4byte gDungeon
_0803F504: .4byte 0x0001356c
	thumb_func_end sub_803F4A0

	thumb_func_start sub_803F508
sub_803F508:
	push {r4,r5,lr}
	adds r3, r0, 0
	ldr r0, _0803F520
	ldr r1, [r0]
	ldr r0, _0803F524
	adds r4, r1, r0
	cmp r3, 0
	bne _0803F52C
	ldr r2, _0803F528
	adds r0, r1, r2
	strb r3, [r0]
	b _0803F548
	.align 2, 0
_0803F520: .4byte gDungeon
_0803F524: .4byte 0x000181e8
_0803F528: .4byte 0x00018216
_0803F52C:
	ldr r0, [r3, 0x70]
	ldrb r2, [r0, 0x7]
	cmp r2, 0
	bne _0803F540
	ldr r5, _0803F53C
	adds r0, r1, r5
	strb r2, [r0]
	b _0803F548
	.align 2, 0
_0803F53C: .4byte 0x00018216
_0803F540:
	ldr r0, _0803F574
	adds r1, r0
	movs r0, 0x1
	strb r0, [r1]
_0803F548:
	str r3, [r4, 0x10]
	movs r0, 0
	bl sub_803F580
	bl sub_803F38C
	ldr r0, _0803F578
	ldr r0, [r0]
	ldr r1, _0803F57C
	adds r0, r1
	ldrb r0, [r0]
	cmp r0, 0
	bne _0803F566
	bl sub_806CD90
_0803F566:
	bl sub_8049ED4
	bl sub_8040A84
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_0803F574: .4byte 0x00018216
_0803F578: .4byte gDungeon
_0803F57C: .4byte 0x0001356c
	thumb_func_end sub_803F508

	thumb_func_start sub_803F580
sub_803F580:
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	lsls r0, 24
	lsrs r0, 24
	mov r9, r0
	ldr r0, _0803F600
	ldr r4, [r0]
	ldr r0, _0803F604
	adds r5, r4, r0
	ldr r6, [r5, 0x10]
	cmp r6, 0
	bne _0803F59E
	b _0803F7A0
_0803F59E:
	adds r0, r6, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	bne _0803F5AC
	b _0803F7A0
_0803F5AC:
	ldr r7, [r6, 0x70]
	ldr r0, [r5, 0x8]
	str r0, [r5, 0xC]
	ldr r0, [r5]
	str r0, [r5, 0x4]
	ldrh r0, [r6, 0x4]
	strh r0, [r5]
	ldrh r0, [r6, 0x6]
	strh r0, [r5, 0x2]
	ldr r0, [r6, 0xC]
	cmp r0, 0
	bge _0803F5C6
	adds r0, 0xFF
_0803F5C6:
	asrs r0, 8
	subs r0, 0x78
	strh r0, [r5, 0x8]
	ldr r0, [r6, 0x10]
	cmp r0, 0
	bge _0803F5D4
	adds r0, 0xFF
_0803F5D4:
	asrs r0, 8
	subs r0, 0x60
	strh r0, [r5, 0xA]
	adds r0, r6, 0
	movs r1, 0x11
	bl HasHeldItem
	lsls r0, 24
	cmp r0, 0
	beq _0803F610
	ldrb r0, [r7, 0x7]
	cmp r0, 0
	beq _0803F610
	ldr r1, _0803F608
	adds r0, r4, r1
	movs r1, 0x1
	strb r1, [r0]
	ldr r2, _0803F60C
	adds r0, r4, r2
	strb r1, [r0]
	b _0803F626
	.align 2, 0
_0803F600: .4byte gDungeon
_0803F604: .4byte 0x000181e8
_0803F608: .4byte 0x0001820d
_0803F60C: .4byte 0x0001820e
_0803F610:
	adds r0, r7, 0
	adds r0, 0xF0
	ldrb r0, [r0]
	adds r1, r5, 0
	adds r1, 0x25
	strb r0, [r1]
	adds r0, r7, 0
	adds r0, 0xF1
	ldrb r0, [r0]
	adds r1, 0x1
	strb r0, [r1]
_0803F626:
	adds r0, r7, 0
	adds r0, 0xF2
	ldrb r0, [r0]
	adds r1, r5, 0
	adds r1, 0x29
	strb r0, [r1]
	subs r1, 0x7
	ldrb r0, [r1]
	mov r8, r0
	adds r0, r5, 0
	adds r0, 0x2C
	ldrb r2, [r0]
	adds r4, r1, 0
	cmp r2, 0
	bne _0803F670
	adds r0, r7, 0
	adds r0, 0xE8
	ldrb r1, [r0]
	adds r7, r0, 0
	cmp r1, 0x1
	bne _0803F656
	strb r1, [r4]
	movs r1, 0xE
	b _0803F65A
_0803F656:
	strb r2, [r4]
	movs r1, 0
_0803F65A:
	ldr r2, _0803F66C
	ldr r0, [r2]
	cmp r0, r1
	beq _0803F678
	str r1, [r2]
	adds r0, r1, 0
	bl SetBGOBJEnableFlags
	b _0803F678
	.align 2, 0
_0803F66C: .4byte gUnknown_202EDFC
_0803F670:
	ldr r1, _0803F698
	ldr r0, _0803F69C
	str r0, [r1]
	adds r7, 0xE8
_0803F678:
	ldrb r4, [r4]
	cmp r8, r4
	beq _0803F684
	movs r0, 0
	bl sub_8041888
_0803F684:
	adds r0, r5, 0
	adds r0, 0x28
	ldrb r1, [r0]
	mov r8, r1
	ldrb r1, [r7]
	adds r2, r0, 0
	cmp r1, 0x2
	bne _0803F6A0
	movs r0, 0x1
	b _0803F6A2
	.align 2, 0
_0803F698: .4byte gUnknown_202EDFC
_0803F69C: .4byte 0x0000ffff
_0803F6A0:
	movs r0, 0
_0803F6A2:
	strb r0, [r2]
	ldrb r2, [r2]
	cmp r8, r2
	beq _0803F6B4
	bl sub_806CC70
	movs r0, 0
	bl sub_8041888
_0803F6B4:
	adds r4, r5, 0
	adds r4, 0x27
	ldrb r2, [r4]
	mov r8, r2
	adds r0, r6, 0
	bl CanSeeInvisibleMonsters
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0
	beq _0803F6CC
	movs r0, 0x1
_0803F6CC:
	strb r0, [r4]
	ldrb r4, [r4]
	cmp r8, r4
	beq _0803F6E2
	bl sub_8049ED4
	bl sub_8040A84
	movs r0, 0
	bl sub_8041888
_0803F6E2:
	mov r0, r9
	cmp r0, 0
	beq _0803F76A
	adds r0, r5, 0
	adds r0, 0x2B
	ldrb r1, [r0]
	adds r4, r0, 0
	cmp r1, 0
	bne _0803F76A
	movs r2, 0xC
	ldrsh r1, [r5, r2]
	movs r2, 0x8
	ldrsh r0, [r5, r2]
	subs r1, r0
	cmp r1, 0
	bge _0803F704
	negs r1, r1
_0803F704:
	cmp r1, 0x7
	bgt _0803F71C
	movs r0, 0xE
	ldrsh r1, [r5, r0]
	movs r2, 0xA
	ldrsh r0, [r5, r2]
	subs r1, r0
	cmp r1, 0
	bge _0803F718
	negs r1, r1
_0803F718:
	cmp r1, 0x7
	ble _0803F726
_0803F71C:
	bl sub_8049ED4
	movs r0, 0x1
	strb r0, [r4]
	b _0803F76A
_0803F726:
	movs r0, 0xC
	ldrsh r1, [r5, r0]
	movs r2, 0x8
	ldrsh r0, [r5, r2]
	cmp r1, r0
	bge _0803F73C
	movs r0, 0xF0
	movs r1, 0
	bl sub_804A1F0
	b _0803F748
_0803F73C:
	cmp r1, r0
	ble _0803F748
	movs r0, 0
	movs r1, 0
	bl sub_804A1F0
_0803F748:
	movs r0, 0xE
	ldrsh r1, [r5, r0]
	movs r2, 0xA
	ldrsh r0, [r5, r2]
	cmp r1, r0
	bge _0803F75E
	movs r0, 0
	movs r1, 0xA0
	bl sub_804A49C
	b _0803F76A
_0803F75E:
	cmp r1, r0
	ble _0803F76A
	movs r0, 0
	movs r1, 0
	bl sub_804A49C
_0803F76A:
	ldr r1, [r5]
	ldr r0, [r5, 0x4]
	cmp r1, r0
	beq _0803F7A0
	movs r5, 0
_0803F774:
	ldr r0, _0803F7B4
	ldr r0, [r0]
	lsls r1, r5, 2
	ldr r2, _0803F7B8
	adds r0, r2
	adds r0, r1
	ldr r4, [r0]
	adds r0, r4, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	beq _0803F79A
	movs r1, 0x4
	ldrsh r0, [r4, r1]
	movs r2, 0x6
	ldrsh r1, [r4, r2]
	bl sub_80402AC
_0803F79A:
	adds r5, 0x1
	cmp r5, 0x13
	ble _0803F774
_0803F7A0:
	bl sub_80400D4
	bl sub_803F7BC
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_0803F7B4: .4byte gDungeon
_0803F7B8: .4byte 0x000135cc
	thumb_func_end sub_803F580

	thumb_func_start sub_803F7BC
sub_803F7BC:
	push {r4-r6,lr}
	sub sp, 0x10
	ldr r6, _0803F800
	ldr r4, [r6]
	ldr r0, _0803F804
	adds r5, r4, r0
	movs r1, 0
	ldrsh r0, [r5, r1]
	movs r2, 0x2
	ldrsh r1, [r5, r2]
	bl GetTile
	ldrb r1, [r0, 0x9]
	ldr r2, _0803F808
	adds r0, r4, r2
	ldrb r0, [r0]
	cmp r0, 0
	bne _0803F7F4
	adds r2, 0x1
	adds r0, r4, r2
	ldrb r0, [r0]
	cmp r0, 0
	bne _0803F7F4
	adds r2, 0xB
	adds r0, r4, r2
	ldrb r0, [r0]
	cmp r0, 0
	beq _0803F80C
_0803F7F4:
	movs r0, 0
	movs r1, 0
	bl sub_8005838
	b _0803F86A
	.align 2, 0
_0803F800: .4byte gDungeon
_0803F804: .4byte 0x000181e8
_0803F808: .4byte 0x0001820b
_0803F80C:
	cmp r1, 0xFF
	bne _0803F82C
	ldr r1, _0803F828
	adds r0, r4, r1
	ldrb r0, [r0]
	movs r1, 0x2
	cmp r0, 0x2
	bne _0803F81E
	movs r1, 0x1
_0803F81E:
	movs r0, 0
	bl sub_8005838
	b _0803F86A
	.align 2, 0
_0803F828: .4byte 0x00018209
_0803F82C:
	lsls r0, r1, 3
	subs r0, r1
	lsls r0, 2
	ldr r2, _0803F874
	adds r0, r2
	ldr r2, [r6]
	adds r2, r0
	movs r0, 0x8
	ldrsh r1, [r5, r0]
	ldr r0, [r2, 0xC]
	subs r0, r1
	str r0, [sp]
	movs r0, 0xA
	ldrsh r1, [r5, r0]
	ldr r0, [r2, 0x10]
	subs r0, r1
	str r0, [sp, 0x4]
	movs r0, 0x8
	ldrsh r1, [r5, r0]
	ldr r0, [r2, 0x14]
	subs r0, r1
	str r0, [sp, 0x8]
	movs r0, 0xA
	ldrsh r1, [r5, r0]
	ldr r0, [r2, 0x18]
	subs r0, r1
	str r0, [sp, 0xC]
	mov r0, sp
	movs r1, 0x3
	bl sub_8005838
_0803F86A:
	add sp, 0x10
	pop {r4-r6}
	pop {r0}
	bx r0
	.align 2, 0
_0803F874: .4byte 0x000104c4
	thumb_func_end sub_803F7BC

	thumb_func_start sub_803F878
sub_803F878:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	adds r2, r0, 0
	adds r6, r1, 0
	ldr r0, _0803F92C
	ldr r7, [r0]
	ldr r0, _0803F930
	adds r5, r7, r0
	ldr r0, [r5, 0x8]
	str r0, [r5, 0xC]
	ldr r0, [r5]
	str r0, [r5, 0x4]
	adds r0, r2, 0
	cmp r2, 0
	bge _0803F89A
	adds r0, 0xFF
_0803F89A:
	asrs r0, 8
	subs r0, 0x78
	movs r1, 0
	mov r8, r1
	strh r0, [r5, 0x8]
	adds r0, r6, 0
	cmp r6, 0
	bge _0803F8AC
	adds r0, 0xFF
_0803F8AC:
	asrs r0, 8
	subs r0, 0x60
	strh r0, [r5, 0xA]
	movs r4, 0xC0
	lsls r4, 5
	adds r0, r2, 0
	adds r1, r4, 0
	bl __divsi3
	strh r0, [r5]
	adds r0, r6, 0
	adds r1, r4, 0
	bl __divsi3
	strh r0, [r5, 0x2]
	ldr r2, _0803F934
	adds r0, r7, r2
	mov r1, r8
	strb r1, [r0]
	adds r2, 0x1
	adds r0, r7, r2
	strb r1, [r0]
	ldr r1, _0803F938
	adds r0, r7, r1
	mov r2, r8
	strb r2, [r0]
	adds r1, 0x5
	adds r0, r7, r1
	strb r2, [r0]
	ldr r1, _0803F93C
	ldr r0, [r1]
	cmp r0, 0
	beq _0803F8F6
	movs r0, 0
	str r0, [r1]
	bl SetBGOBJEnableFlags
_0803F8F6:
	movs r2, 0xC
	ldrsh r1, [r5, r2]
	movs r2, 0x8
	ldrsh r0, [r5, r2]
	subs r1, r0
	cmp r1, 0
	bge _0803F906
	negs r1, r1
_0803F906:
	cmp r1, 0x7
	bgt _0803F91E
	movs r0, 0xE
	ldrsh r1, [r5, r0]
	movs r2, 0xA
	ldrsh r0, [r5, r2]
	subs r1, r0
	cmp r1, 0
	bge _0803F91A
	negs r1, r1
_0803F91A:
	cmp r1, 0x7
	ble _0803F940
_0803F91E:
	bl sub_8049ED4
	adds r1, r5, 0
	adds r1, 0x2B
	movs r0, 0x1
	strb r0, [r1]
	b _0803F984
	.align 2, 0
_0803F92C: .4byte gDungeon
_0803F930: .4byte 0x000181e8
_0803F934: .4byte 0x0001820d
_0803F938: .4byte 0x00018211
_0803F93C: .4byte gUnknown_202EDFC
_0803F940:
	movs r0, 0xC
	ldrsh r1, [r5, r0]
	movs r2, 0x8
	ldrsh r0, [r5, r2]
	cmp r1, r0
	bge _0803F956
	movs r0, 0xF0
	movs r1, 0
	bl sub_804A1F0
	b _0803F962
_0803F956:
	cmp r1, r0
	ble _0803F962
	movs r0, 0
	movs r1, 0
	bl sub_804A1F0
_0803F962:
	movs r0, 0xE
	ldrsh r1, [r5, r0]
	movs r2, 0xA
	ldrsh r0, [r5, r2]
	cmp r1, r0
	bge _0803F978
	movs r0, 0
	movs r1, 0xA0
	bl sub_804A49C
	b _0803F984
_0803F978:
	cmp r1, r0
	ble _0803F984
	movs r0, 0
	movs r1, 0
	bl sub_804A49C
_0803F984:
	bl sub_803F7BC
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_803F878

	thumb_func_start GetCameraXPos
GetCameraXPos:
	ldr r0, _0803F9A8
	ldr r0, [r0]
	ldr r1, _0803F9AC
	adds r0, r1
	movs r1, 0x8
	ldrsh r0, [r0, r1]
	adds r0, 0x78
	lsls r0, 8
	bx lr
	.align 2, 0
_0803F9A8: .4byte gDungeon
_0803F9AC: .4byte 0x000181e8
	thumb_func_end GetCameraXPos

	thumb_func_start GetCameraYPos
GetCameraYPos:
	ldr r0, _0803F9C4
	ldr r0, [r0]
	ldr r1, _0803F9C8
	adds r0, r1
	movs r1, 0xA
	ldrsh r0, [r0, r1]
	adds r0, 0x60
	lsls r0, 8
	bx lr
	.align 2, 0
_0803F9C4: .4byte gDungeon
_0803F9C8: .4byte 0x000181e8
	thumb_func_end GetCameraYPos

	thumb_func_start sub_803F9CC
sub_803F9CC:
	push {r4,r5,lr}
	ldr r0, _0803FA24
	ldr r1, [r0]
	ldr r2, _0803FA28
	adds r0, r1, r2
	ldr r4, [r0]
	movs r5, 0
	ldr r2, _0803FA2C
	adds r0, r1, r2
	ldrb r0, [r0]
	cmp r0, 0
	bne _0803FA0C
	ldr r2, _0803FA30
	adds r0, r1, r2
	ldrb r0, [r0]
	cmp r0, 0
	bne _0803FA0C
	bl sub_800EC74
	lsls r0, 24
	cmp r0, 0
	bne _0803FA0C
	cmp r4, 0
	beq _0803FA08
	adds r0, r4, 0
	bl GetEntityType
	cmp r0, 0x1
	bne _0803FA08
	movs r5, 0x1
_0803FA08:
	cmp r5, 0
	bne _0803FA38
_0803FA0C:
	ldr r0, _0803FA34
	movs r2, 0
	adds r0, 0x2
	movs r1, 0x1C
_0803FA14:
	strh r2, [r0]
	adds r0, 0x2
	subs r1, 0x1
	cmp r1, 0
	bge _0803FA14
	bl sub_803F38C
	b _0803FA3C
	.align 2, 0
_0803FA24: .4byte gDungeon
_0803FA28: .4byte 0x000181f8
_0803FA2C: .4byte 0x0001356c
_0803FA30: .4byte 0x00018218
_0803FA34: .4byte gUnknown_202B038
_0803FA38:
	bl sub_803FB74
_0803FA3C:
	ldr r1, _0803FA48
	movs r0, 0x1
	strb r0, [r1]
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_0803FA48: .4byte gUnknown_20274A5
	thumb_func_end sub_803F9CC

	thumb_func_start sub_803FA4C
sub_803FA4C:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x28
	adds r4, r0, 0
	mov r8, r1
	lsls r2, 24
	lsrs r2, 24
	mov r12, r2
	ldr r0, _0803FB4C
	ldr r3, [r0]
	ldr r0, _0803FB50
	adds r0, r3, r0
	str r0, [sp, 0x24]
	ldr r7, _0803FB54
	mov r1, sp
	ldr r0, _0803FB58
	ldm r0!, {r2,r5,r6}
	stm r1!, {r2,r5,r6}
	ldm r0!, {r2,r5,r6}
	stm r1!, {r2,r5,r6}
	ldm r0!, {r2,r5,r6}
	stm r1!, {r2,r5,r6}
	ldr r0, _0803FB5C
	mov r10, r0
	ldr r1, _0803FB60
	mov r9, r1
	ldr r2, [sp, 0x24]
	movs r5, 0x3E
	ldrsh r0, [r2, r5]
	cmp r4, r0
	bne _0803FA9C
	ldr r6, _0803FB64
	adds r0, r3, r6
	movs r1, 0
	ldrsh r0, [r0, r1]
	cmp r8, r0
	beq _0803FB3A
_0803FA9C:
	mov r2, r12
	cmp r2, 0
	bne _0803FAA6
	ldr r5, _0803FB68
	mov r9, r5
_0803FAA6:
	ldr r6, [sp, 0x24]
	strh r4, [r6, 0x3E]
	ldr r1, _0803FB64
	adds r0, r3, r1
	mov r2, r8
	strh r2, [r0]
	mov r5, r8
	cmp r5, 0x5F
	ble _0803FAC8
	movs r5, 0x60
	lsls r0, r4, 1
	adds r0, r4
	lsls r0, 5
	mov r1, r8
	bl __divsi3
	adds r4, r0, 0
_0803FAC8:
	movs r3, 0
	mov r8, r3
	movs r6, 0x58
	mov r12, r6
_0803FAD0:
	ldr r6, _0803FB6C
	adds r2, r4, 0
	adds r0, r5, 0
	cmp r4, 0x7
	ble _0803FADC
	movs r2, 0x8
_0803FADC:
	cmp r5, 0x7
	ble _0803FAE2
	movs r0, 0x8
_0803FAE2:
	lsls r0, 2
	mov r3, sp
	adds r1, r3, r0
	lsls r0, r2, 2
	add r0, sp
	ldr r2, [r0]
	ldr r3, [r1]
	adds r1, r3, 0
	bics r1, r2
	mov r0, r10
	ands r1, r0
	mov r0, r9
	ands r0, r2
	orrs r0, r1
	ands r6, r3
	mov r1, r8
	stm r7!, {r1}
	stm r7!, {r6}
	stm r7!, {r0}
	stm r7!, {r0}
	stm r7!, {r0}
	stm r7!, {r0}
	stm r7!, {r6}
	stm r7!, {r1}
	subs r4, 0x8
	subs r5, 0x8
	cmp r4, 0
	bge _0803FB1C
	movs r4, 0
_0803FB1C:
	cmp r5, 0
	bge _0803FB22
	movs r5, 0
_0803FB22:
	movs r2, 0x8
	negs r2, r2
	add r12, r2
	mov r3, r12
	cmp r3, 0
	bge _0803FAD0
	ldr r0, _0803FB70
	movs r2, 0xC0
	lsls r2, 1
	ldr r1, _0803FB54
	bl sub_80098BC
_0803FB3A:
	add sp, 0x28
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_0803FB4C: .4byte gDungeon
_0803FB50: .4byte 0x000181e8
_0803FB54: .4byte gUnknown_3001018
_0803FB58: .4byte gUnknown_80F6490
_0803FB5C: .4byte 0x22222222
_0803FB60: .4byte 0x44444444
_0803FB64: .4byte 0x00018228
_0803FB68: .4byte 0x55555555
_0803FB6C: .4byte 0x77777777
_0803FB70: .4byte 0x06005980
	thumb_func_end sub_803FA4C

	thumb_func_start sub_803FB74
sub_803FB74:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x4
	ldr r0, _0803FBE8
	ldr r0, [r0]
	ldr r1, _0803FBEC
	adds r7, r0, r1
	movs r4, 0
	movs r2, 0
	str r2, [sp]
	ldr r0, [r7, 0x10]
	ldr r0, [r0, 0x70]
	movs r1, 0xE
	ldrsh r3, [r0, r1]
	mov r9, r3
	movs r3, 0x10
	ldrsh r2, [r0, r3]
	mov r8, r2
	ldrb r1, [r0, 0x9]
	mov r10, r1
	movs r2, 0xE
	ldrsh r1, [r0, r2]
	cmp r1, 0
	ble _0803FBBA
	mov r0, r8
	cmp r0, 0
	bge _0803FBB2
	adds r0, 0x3
_0803FBB2:
	asrs r0, 2
	cmp r1, r0
	bgt _0803FBBA
	movs r4, 0x1
_0803FBBA:
	ldr r0, [r7, 0x10]
	ldr r0, [r0, 0x70]
	movs r3, 0x9E
	lsls r3, 1
	adds r0, r3
	ldr r0, [r0]
	bl FixedPointToInt
	cmp r0, 0
	bne _0803FBD2
	movs r0, 0x1
	str r0, [sp]
_0803FBD2:
	cmp r4, 0
	beq _0803FBF4
	ldr r0, _0803FBF0
	ldr r0, [r0]
	movs r1, 0x10
	ands r0, r1
	cmp r0, 0
	beq _0803FBF4
	movs r5, 0x20
	movs r6, 0x20
	b _0803FBF8
	.align 2, 0
_0803FBE8: .4byte gDungeon
_0803FBEC: .4byte 0x000181e8
_0803FBF0: .4byte gUnknown_202EDCC
_0803FBF4:
	movs r5, 0
	movs r6, 0
_0803FBF8:
	ldr r1, [sp]
	cmp r1, 0
	beq _0803FC0E
	ldr r0, _0803FC20
	ldr r0, [r0]
	movs r1, 0x10
	ands r0, r1
	cmp r0, 0
	beq _0803FC0E
	movs r5, 0x30
	movs r6, 0x30
_0803FC0E:
	cmp r5, 0
	bne _0803FC30
	adds r0, r7, 0
	adds r0, 0x2A
	ldrb r0, [r0]
	cmp r0, 0
	beq _0803FC24
	movs r5, 0x60
	b _0803FC30
	.align 2, 0
_0803FC20: .4byte gUnknown_202EDCC
_0803FC24:
	ldr r0, _0803FCE4
	ldr r0, [r0]
	ldrb r0, [r0, 0xB]
	cmp r0, 0
	beq _0803FC30
	movs r5, 0x40
_0803FC30:
	cmp r6, 0
	bne _0803FC40
	ldr r0, _0803FCE4
	ldr r0, [r0]
	ldrb r0, [r0, 0xB]
	cmp r0, 0
	beq _0803FC40
	movs r6, 0x40
_0803FC40:
	movs r2, 0x36
	ldrsh r0, [r7, r2]
	cmp r0, r5
	beq _0803FC78
	strh r5, [r7, 0x36]
	lsls r5, 2
	ldr r4, _0803FCE8
	adds r1, r5, r4
	movs r0, 0xFC
	bl SetBGPaletteBufferColorArray
	adds r1, r4, 0x4
	adds r1, r5, r1
	movs r0, 0xFD
	bl SetBGPaletteBufferColorArray
	adds r1, r4, 0
	adds r1, 0x8
	adds r1, r5, r1
	movs r0, 0xFE
	bl SetBGPaletteBufferColorArray
	adds r4, 0xC
	adds r5, r4
	movs r0, 0xFF
	adds r1, r5, 0
	bl SetBGPaletteBufferColorArray
_0803FC78:
	movs r3, 0x38
	ldrsh r0, [r7, r3]
	cmp r0, r6
	beq _0803FCB0
	strh r6, [r7, 0x38]
	lsls r5, r6, 2
	ldr r4, _0803FCE8
	adds r1, r5, r4
	movs r0, 0xFC
	bl nullsub_5
	adds r1, r4, 0x4
	adds r1, r5, r1
	movs r0, 0xFD
	bl nullsub_5
	adds r1, r4, 0
	adds r1, 0x8
	adds r1, r5, r1
	movs r0, 0xFE
	bl nullsub_5
	adds r4, 0xC
	adds r5, r4
	movs r0, 0xFF
	adds r1, r5, 0
	bl nullsub_5
_0803FCB0:
	ldr r5, _0803FCEC
	ldr r0, _0803FCF0
	ldr r2, [r0]
	ldr r0, _0803FCF4
	adds r1, r2, r0
	movs r3, 0x14
	ldrsh r0, [r2, r3]
	ldrb r1, [r1]
	adds r6, r0, r1
	movs r1, 0x3A
	ldrsh r0, [r7, r1]
	adds r4, r7, 0
	adds r4, 0x2E
	cmp r0, r6
	beq _0803FD3E
	strh r6, [r7, 0x3A]
	ldr r3, _0803FCF8
	adds r0, r2, r3
	ldrb r0, [r0]
	bl IsStairDirectionUp
	lsls r0, 24
	cmp r0, 0
	beq _0803FCFC
	movs r0, 0
	b _0803FD00
	.align 2, 0
_0803FCE4: .4byte gGameOptionsRef
_0803FCE8: .4byte gUnknown_202D068
_0803FCEC: .4byte gUnknown_202B038
_0803FCF0: .4byte gDungeon
_0803FCF4: .4byte 0x00000645
_0803FCF8: .4byte 0x00000644
_0803FCFC:
	ldr r1, _0803FD20
	adds r0, r1, 0
_0803FD00:
	strh r0, [r5, 0x2]
	cmp r6, 0x9
	bgt _0803FD28
	adds r1, r5, 0x4
	adds r4, r7, 0
	adds r4, 0x2E
	ldrb r2, [r4]
	adds r0, r6, 0
	movs r3, 0x1
	bl sub_803FE30
	ldr r2, _0803FD24
	adds r0, r2, 0
	strh r0, [r5, 0x6]
	b _0803FD3E
	.align 2, 0
_0803FD20: .4byte 0x0000f2be
_0803FD24: .4byte 0x0000f2b8
_0803FD28:
	adds r1, r5, 0x4
	adds r4, r7, 0
	adds r4, 0x2E
	ldrb r2, [r4]
	adds r0, r6, 0
	movs r3, 0
	bl sub_803FE30
	ldr r3, _0803FE10
	adds r0, r3, 0
	strh r0, [r5, 0x8]
_0803FD3E:
	movs r1, 0x3C
	ldrsh r0, [r7, r1]
	cmp r0, r10
	beq _0803FD64
	mov r2, r10
	strh r2, [r7, 0x3C]
	ldr r3, _0803FE14
	adds r0, r3, 0
	strh r0, [r5, 0xA]
	ldr r1, _0803FE18
	adds r0, r1, 0
	strh r0, [r5, 0xC]
	adds r1, r5, 0
	adds r1, 0xE
	ldrb r2, [r4]
	mov r0, r10
	movs r3, 0
	bl sub_803FE30
_0803FD64:
	movs r2, 0x3E
	ldrsh r0, [r7, r2]
	cmp r0, r9
	beq _0803FD84
	ldr r3, _0803FE1C
	adds r0, r3, 0
	strh r0, [r5, 0x12]
	ldr r1, _0803FE20
	adds r0, r1, 0
	strh r0, [r5, 0x14]
	adds r1, r5, 0
	adds r1, 0x16
	ldrb r2, [r4]
	mov r0, r9
	bl sub_803FF18
_0803FD84:
	adds r6, r7, 0
	adds r6, 0x40
	movs r2, 0
	ldrsh r0, [r6, r2]
	cmp r0, r8
	beq _0803FDA2
	ldr r3, _0803FE24
	adds r0, r3, 0
	strh r0, [r5, 0x1C]
	adds r1, r5, 0
	adds r1, 0x1E
	ldrb r2, [r4]
	mov r0, r8
	bl sub_803FF18
_0803FDA2:
	ldrb r2, [r4]
	mov r0, r9
	mov r1, r8
	bl sub_803FA4C
	mov r0, r8
	strh r0, [r6]
	mov r1, r9
	strh r1, [r7, 0x3E]
	mov r0, r8
	cmp r0, 0
	bge _0803FDBC
	adds r0, 0x7
_0803FDBC:
	asrs r1, r0, 3
	adds r4, r7, 0
	adds r4, 0x42
	strh r1, [r4]
	movs r0, 0x7
	mov r2, r8
	ands r2, r0
	cmp r2, 0
	beq _0803FDD2
	adds r0, r1, 0x1
	strh r0, [r4]
_0803FDD2:
	movs r3, 0
	ldrsh r0, [r4, r3]
	cmp r0, 0xB
	ble _0803FDDE
	movs r0, 0xC
	strh r0, [r4]
_0803FDDE:
	movs r1, 0
	ldr r0, _0803FE28
	movs r2, 0xB3
	lsls r2, 2
	adds r4, r2, 0
	ldr r2, _0803FE2C
	adds r3, r2, 0
	adds r2, r0, 0
	adds r2, 0x24
_0803FDF0:
	adds r0, r1, r4
	orrs r0, r3
	strh r0, [r2]
	adds r2, 0x2
	adds r1, 0x1
	cmp r1, 0xB
	ble _0803FDF0
	add sp, 0x4
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_0803FE10: .4byte 0x0000f2b8
_0803FE14: .4byte 0x0000f2b9
_0803FE18: .4byte 0x0000f2ba
_0803FE1C: .4byte 0x0000f2bb
_0803FE20: .4byte 0x0000f2bc
_0803FE24: .4byte 0x0000f2bd
_0803FE28: .4byte gUnknown_202B038
_0803FE2C: .4byte 0xfffff000
	thumb_func_end sub_803FB74

	thumb_func_start sub_803FE30
sub_803FE30:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	adds r5, r0, 0
	adds r4, r1, 0
	lsls r2, 24
	lsrs r2, 24
	adds r1, r2, 0
	lsls r3, 24
	lsrs r3, 24
	mov r12, r3
	movs r0, 0
	cmp r2, 0
	bne _0803FE4E
	movs r0, 0x37
_0803FE4E:
	cmp r5, 0x64
	ble _0803FE70
	cmp r2, 0
	beq _0803FE60
	ldr r1, _0803FE5C
	adds r0, r1, 0
	b _0803FE64
	.align 2, 0
_0803FE5C: .4byte 0x0000f291
_0803FE60:
	ldr r2, _0803FE6C
	adds r0, r2, 0
_0803FE64:
	strh r0, [r4]
	strh r0, [r4, 0x2]
	b _0803FF00
	.align 2, 0
_0803FE6C: .4byte 0x0000f2c8
_0803FE70:
	cmp r5, 0x64
	bne _0803FEBC
	ldr r1, _0803FE84
	adds r0, r1, 0
	strh r0, [r4]
	ldr r2, _0803FE88
	adds r0, r2, 0
	strh r0, [r4, 0x2]
	b _0803FF00
	.align 2, 0
_0803FE84: .4byte 0x0000f294
_0803FE88: .4byte 0x0000f295
_0803FE8C:
	ldr r1, _0803FEB4
	lsls r0, r6, 3
	adds r0, r6
	adds r0, r2
	lsls r0, 1
	adds r0, r1
	ldrh r0, [r0]
	strh r0, [r4]
	subs r0, r5, r3
	adds r0, r7
	movs r1, 0x96
	lsls r1, 2
	adds r0, r1
	ldr r2, _0803FEB8
	adds r1, r2, 0
	orrs r0, r1
	mov r1, r8
	strh r0, [r1]
	b _0803FF00
	.align 2, 0
_0803FEB4: .4byte gUnknown_80F64D8
_0803FEB8: .4byte 0xfffff000
_0803FEBC:
	adds r2, r4, 0x2
	mov r8, r2
	adds r7, r0, 0
	adds r7, 0x30
	cmp r5, 0x9
	ble _0803FEE2
	movs r6, 0
	cmp r1, 0
	bne _0803FED0
	movs r6, 0x1
_0803FED0:
	movs r2, 0
	ldr r0, _0803FF0C
_0803FED4:
	ldr r3, [r0]
	cmp r3, r5
	ble _0803FE8C
	adds r0, 0x4
	adds r2, 0x1
	cmp r2, 0x8
	ble _0803FED4
_0803FEE2:
	mov r0, r12
	cmp r0, 0
	bne _0803FEF0
	ldr r1, _0803FF10
	adds r0, r1, 0
	strh r0, [r4]
	adds r4, 0x2
_0803FEF0:
	adds r0, r5, r7
	movs r2, 0x96
	lsls r2, 2
	adds r0, r2
	ldr r2, _0803FF14
	adds r1, r2, 0
	orrs r0, r1
	strh r0, [r4]
_0803FF00:
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_0803FF0C: .4byte gUnknown_80F64B4
_0803FF10: .4byte 0x0000f278
_0803FF14: .4byte 0xfffff000
	thumb_func_end sub_803FE30

	thumb_func_start sub_803FF18
sub_803FF18:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	adds r5, r0, 0
	adds r3, r1, 0
	lsls r2, 24
	lsrs r2, 24
	movs r6, 0
	cmp r2, 0
	bne _0803FF2E
	movs r6, 0x1
_0803FF2E:
	movs r1, 0
	cmp r2, 0
	bne _0803FF36
	movs r1, 0x37
_0803FF36:
	ldr r0, _0803FF54
	cmp r5, r0
	ble _0803FF7C
	ldr r0, _0803FF58
	lsls r1, r6, 3
	adds r1, r6
	lsls r1, 1
	adds r1, r0
	ldrh r0, [r1]
	strh r0, [r3]
	adds r3, 0x2
	strh r0, [r3]
	strh r0, [r3, 0x2]
	b _0804001A
	.align 2, 0
_0803FF54: .4byte 0x000003e7
_0803FF58: .4byte gUnknown_80F6544
_0803FF5C:
	ldr r1, _0803FF78
	lsls r0, r6, 3
	adds r0, r6
	adds r0, r4
	lsls r0, 1
	adds r0, r1
	ldrh r0, [r0]
	strh r0, [r3]
	adds r3, 0x2
	subs r5, r2
	mov r1, r8
	lsls r0, r1, 24
	lsrs r7, r0, 24
	b _0803FF98
	.align 2, 0
_0803FF78: .4byte gUnknown_80F6544
_0803FF7C:
	movs r7, 0x20
	movs r4, 0
	adds r1, 0x30
	mov r8, r1
	ldr r2, _0803FFC0
	mov r12, r2
	ldr r0, _0803FFC4
_0803FF8A:
	ldr r2, [r0]
	cmp r2, r5
	ble _0803FF5C
	adds r0, 0x4
	adds r4, 0x1
	cmp r4, 0x8
	ble _0803FF8A
_0803FF98:
	cmp r4, 0x9
	bne _0803FFAC
	movs r1, 0x96
	lsls r1, 2
	adds r0, r7, r1
	ldr r2, _0803FFC8
	adds r1, r2, 0
	orrs r0, r1
	strh r0, [r3]
	adds r3, 0x2
_0803FFAC:
	movs r4, 0
	mov r0, r12
	ldr r2, [r0]
	cmp r2, r5
	bgt _0803FFD0
	ldr r0, _0803FFCC
	lsls r1, r6, 3
	adds r1, r6
	b _0803FFE8
	.align 2, 0
_0803FFC0: .4byte gUnknown_80F6520
_0803FFC4: .4byte gUnknown_80F64FC
_0803FFC8: .4byte 0xfffff000
_0803FFCC: .4byte gUnknown_80F6544
_0803FFD0:
	adds r4, 0x1
	cmp r4, 0x8
	bgt _0803FFF4
	lsls r0, r4, 2
	add r0, r12
	ldr r2, [r0]
	cmp r2, r5
	bgt _0803FFD0
	ldr r0, _08040024
	lsls r1, r6, 3
	adds r1, r6
	adds r1, r4
_0803FFE8:
	lsls r1, 1
	adds r1, r0
	ldrh r0, [r1]
	strh r0, [r3]
	adds r3, 0x2
	subs r5, r2
_0803FFF4:
	cmp r4, 0x9
	bne _08040008
	movs r1, 0x96
	lsls r1, 2
	adds r0, r7, r1
	ldr r2, _08040028
	adds r1, r2, 0
	orrs r0, r1
	strh r0, [r3]
	adds r3, 0x2
_08040008:
	mov r1, r8
	adds r0, r5, r1
	movs r2, 0x96
	lsls r2, 2
	adds r0, r2
	ldr r2, _08040028
	adds r1, r2, 0
	orrs r0, r1
	strh r0, [r3]
_0804001A:
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_08040024: .4byte gUnknown_80F6544
_08040028: .4byte 0xfffff000
	thumb_func_end sub_803FF18

        .align 2,0 @ Don't pad with nop
