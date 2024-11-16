	#include "asm/constants/gba_constants.inc"
  	#include "asm/macros.inc"

  	.syntax unified

  	.text

	thumb_func_start sub_800F990
sub_800F990:
	push {r4-r7,lr}
	sub sp, 0x8
	adds r6, r0, 0
	ldr r4, _0800FA20
	ldr r0, [r6, 0x8]
	str r0, [r4]
	ldr r1, _0800FA24
	ldr r2, _0800FA28
	adds r0, r2, 0
	strh r0, [r1]
	movs r0, 0
	movs r1, 0x14
	bl sub_80095CC
	movs r0, 0x2
	bl UpdateFadeInTile
	ldr r1, [r4]
	ldr r0, _0800FA2C
	adds r2, r1, r0
	ldr r0, _0800FA30
	str r0, [r2]
	ldrb r0, [r6, 0x5]
	ldr r2, _0800FA34
	adds r1, r2
	movs r5, 0
	strb r0, [r1]
	bl sub_8010DA4
	ldr r0, [r4]
	ldr r2, _0800FA38
	adds r1, r0, r2
	movs r2, 0x1
	negs r2, r2
	str r2, [r1]
	ldr r1, _0800FA3C
	adds r0, r1
	str r2, [r0]
	ldrb r0, [r6, 0x4]
	bl sub_800FC5C
	ldr r0, [r4]
	ldr r2, _0800FA40
	adds r1, r0, r2
	adds r2, 0x4
	adds r0, r2
	ldr r0, [r0]
	str r0, [r1]
	ldr r1, _0800FA44
	movs r0, 0xFF
	strb r0, [r1]
	ldr r0, _0800FA48
	strb r5, [r0]
	bl sub_8011760
	add r7, sp, 0x4
_0800FA00:
	movs r5, 0
	str r5, [sp]
	str r5, [sp, 0x4]
	mov r0, sp
	adds r1, r7, 0
	bl sub_800FAA8
	cmp r0, 0x1
	bne _0800FA4C
	ldr r0, [sp]
	ldr r1, [sp, 0x4]
	movs r2, 0x32
	bl sub_80100C0
	b _0800FA00
	.align 2, 0
_0800FA20: .4byte gUnknown_203B0E4
_0800FA24: .4byte gUnknown_2026E4E
_0800FA28: .4byte 0x00001010
_0800FA2C: .4byte 0x00004014
_0800FA30: .4byte gFriendAreaLocations
_0800FA34: .4byte 0x00004a2c
_0800FA38: .4byte 0x00004a28
_0800FA3C: .4byte 0x00004a1c
_0800FA40: .4byte 0x00004a20
_0800FA44: .4byte gUnknown_202DE18
_0800FA48: .4byte gUnknown_202DE19
_0800FA4C:
	cmp r0, 0x2
	bne _0800FA6C
	bl sub_800FB6C
	lsls r0, 24
	cmp r0, 0
	beq _0800FA00
	ldr r0, [r4]
	ldr r1, _0800FA68
	adds r0, r1
	ldrb r0, [r0]
	strb r0, [r6, 0xC]
	b _0800FA92
	.align 2, 0
_0800FA68: .4byte 0x00004df4
_0800FA6C:
	cmp r0, 0x3
	bne _0800FA00
	ldr r0, [r4]
	ldr r2, _0800FA8C
	adds r1, r0, r2
	adds r2, 0x8
	adds r0, r2
	ldr r1, [r1]
	ldr r0, [r0]
	cmp r1, r0
	beq _0800FA90
	movs r1, 0
	movs r2, 0xA
	bl sub_80100C0
	b _0800FA00
	.align 2, 0
_0800FA8C: .4byte 0x00004a18
_0800FA90:
	strb r5, [r6, 0xC]
_0800FA92:
	bl sub_800FC28
	bl sub_8010EF0
	bl nullsub_16
	add sp, 0x8
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_800F990

	thumb_func_start sub_800FAA8
sub_800FAA8:
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	mov r8, r0
	mov r9, r1
	movs r5, 0
	bl sub_8011300
	bl sub_8011398
_0800FABE:
	bl sub_801169C
	bl sub_8010014
	lsls r0, 24
	lsrs r3, r0, 24
	cmp r3, 0xFF
	beq _0800FB1C
	ldr r6, _0800FB50
	ldr r2, [r6]
	ldr r1, _0800FB54
	adds r0, r2, r1
	ldr r4, [r0]
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 4
	adds r0, r2
	lsls r1, r3, 1
	ldr r7, _0800FB58
	adds r0, r7
	adds r1, r0, r1
	movs r7, 0
	ldrsh r0, [r1, r7]
	cmp r0, 0
	blt _0800FB1C
	adds r1, r0, 0
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 4
	ldr r7, _0800FB5C
	adds r0, r7
	adds r0, r2, r0
	ldrb r0, [r0]
	cmp r0, 0
	beq _0800FB1C
	movs r5, 0x1
	mov r0, r8
	str r1, [r0]
	mov r1, r9
	str r3, [r1]
	ldr r1, [r6]
	ldr r2, _0800FB60
	adds r0, r1, r2
	str r3, [r0]
	ldr r7, _0800FB64
	adds r1, r7
	str r4, [r1]
_0800FB1C:
	ldr r4, _0800FB68
	ldrh r1, [r4, 0x2]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _0800FB2E
	bl PlayAcceptSoundEffect
	movs r5, 0x2
_0800FB2E:
	ldrh r1, [r4, 0x2]
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	beq _0800FB3E
	bl PlayCancelSoundEffect
	movs r5, 0x3
_0800FB3E:
	cmp r5, 0
	beq _0800FABE
	adds r0, r5, 0
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r1}
	bx r1
	.align 2, 0
_0800FB50: .4byte gUnknown_203B0E4
_0800FB54: .4byte 0x00004a18
_0800FB58: .4byte 0x0000401a
_0800FB5C: .4byte 0x00004018
_0800FB60: .4byte 0x00004a28
_0800FB64: .4byte 0x00004a1c
_0800FB68: .4byte gRealInputs
	thumb_func_end sub_800FAA8

	thumb_func_start sub_800FB6C
sub_800FB6C:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	movs r0, 0
	mov r8, r0
	bl sub_8011494
	ldr r7, _0800FBE8
	ldr r6, _0800FBEC
_0800FB7E:
	ldr r5, [r7]
	ldr r1, _0800FBF0
	adds r4, r5, r1
	adds r0, r4, 0
	bl AddMenuCursorSprite
	bl sub_801169C
	ldrh r1, [r6, 0x4]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	beq _0800FBA2
	adds r0, r4, 0
	bl MoveMenuCursorDown
	bl PlayCursorUpDownSoundEffect
_0800FBA2:
	ldrh r1, [r6, 0x4]
	movs r0, 0x40
	ands r0, r1
	cmp r0, 0
	beq _0800FBB6
	adds r0, r4, 0
	bl MoveMenuCursorUp
	bl PlayCursorUpDownSoundEffect
_0800FBB6:
	ldrh r1, [r6, 0x2]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	bne _0800FBCA
	ldr r2, _0800FBF4
	adds r0, r5, r2
	ldrb r0, [r0]
	cmp r0, 0
	beq _0800FC00
_0800FBCA:
	bl PlayAcceptSoundEffect
	ldr r1, [r7]
	movs r3, 0x18
	ldrsh r2, [r4, r3]
	ldr r3, _0800FBF8
	adds r0, r1, r3
	adds r0, r2
	ldrb r0, [r0]
	ldr r2, _0800FBFC
	adds r1, r2
	strb r0, [r1]
	movs r3, 0x1
	mov r8, r3
	b _0800FC16
	.align 2, 0
_0800FBE8: .4byte gUnknown_203B0E4
_0800FBEC: .4byte gRealInputs
_0800FBF0: .4byte 0x00004dfc
_0800FBF4: .4byte 0x00004e25
_0800FBF8: .4byte 0x00004dec
_0800FBFC: .4byte 0x00004df4
_0800FC00:
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	bne _0800FC12
	ldr r1, _0800FC24
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, 0
	beq _0800FB7E
_0800FC12:
	bl PlayCancelSoundEffect
_0800FC16:
	mov r0, r8
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r1}
	bx r1
	.align 2, 0
_0800FC24: .4byte 0x00004e26
	thumb_func_end sub_800FB6C

	thumb_func_start sub_800FC28
sub_800FC28:
	push {r4,r5,lr}
	bl sub_8011168
	bl sub_80117AC
	ldr r5, _0800FC54
	movs r4, 0x3B
_0800FC36:
	ldr r1, [r5]
	ldr r0, _0800FC58
	adds r1, r0
	ldr r0, [r1]
	subs r0, 0x2
	str r0, [r1]
	bl sub_801169C
	subs r4, 0x1
	cmp r4, 0
	bge _0800FC36
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_0800FC54: .4byte gUnknown_203B0E4
_0800FC58: .4byte 0x00004dcc
	thumb_func_end sub_800FC28

	thumb_func_start sub_800FC5C
sub_800FC5C:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x40
	lsls r0, 24
	lsrs r0, 24
	str r0, [sp, 0x14]
	movs r0, 0
	str r0, [sp, 0x18]
	mov r8, r0
	ldr r1, _0800FD1C
	mov r9, r1
	ldr r2, _0800FD20
	str r2, [sp, 0x38]
_0800FC7C:
	movs r7, 0
	movs r3, 0
	mov r10, r3
	mov r4, r9
	ldr r0, [r4]
	ldr r1, [sp, 0x38]
	adds r6, r0, r1
	ldr r2, _0800FD24
	adds r0, r2
	mov r3, r8
	lsls r1, r3, 5
	ldr r0, [r0]
	adds r2, r0, r1
	adds r1, r6, 0x2
	movs r5, 0x7
_0800FC9A:
	ldrh r0, [r1]
	ldr r4, _0800FD28
	orrs r0, r4
	strh r0, [r1]
	adds r1, 0x2
	subs r5, 0x1
	cmp r5, 0
	bge _0800FC9A
	movs r5, 0
	adds r1, r2, 0
	adds r1, 0x8
_0800FCB0:
	adds r4, r1, r5
	ldrb r0, [r4]
	str r1, [sp, 0x3C]
	bl sub_800FFE8
	lsls r0, 24
	ldr r1, [sp, 0x3C]
	cmp r0, 0
	beq _0800FCE4
	ldrb r0, [r4]
	ldr r7, [sp, 0x14]
	cmp r0, r7
	bne _0800FCCE
	mov r2, r8
	str r2, [sp, 0x18]
_0800FCCE:
	cmp r0, 0
	bne _0800FCE2
	mov r3, r9
	ldr r0, [r3]
	ldr r4, _0800FD2C
	adds r0, r4
	mov r7, r8
	str r7, [r0]
	movs r0, 0x1
	mov r10, r0
_0800FCE2:
	movs r7, 0x1
_0800FCE4:
	adds r5, 0x1
	cmp r5, 0x7
	ble _0800FCB0
	cmp r7, 0
	beq _0800FD30
	movs r5, 0
	movs r4, 0x1
	strb r4, [r6]
	adds r3, r6, 0
	adds r3, 0x14
	mov r1, r9
	ldr r0, [r1]
	ldr r1, [r0, 0x8]
	movs r2, 0x1
	mov r7, r10
	cmp r7, 0
	beq _0800FD08
	movs r2, 0xC
_0800FD08:
	movs r0, 0x40
	str r0, [sp]
	str r5, [sp, 0x4]
	str r4, [sp, 0x8]
	adds r0, r3, 0
	movs r3, 0
	bl AxResInitFile
	b _0800FD32
	.align 2, 0
_0800FD1C: .4byte gUnknown_203B0E4
_0800FD20: .4byte 0x00004018
_0800FD24: .4byte 0x00004014
_0800FD28: .4byte 0x0000ffff
_0800FD2C: .4byte 0x00004a24
_0800FD30:
	strb r7, [r6]
_0800FD32:
	ldr r0, [sp, 0x38]
	adds r0, 0x50
	str r0, [sp, 0x38]
	movs r1, 0x1
	add r8, r1
	mov r2, r8
	cmp r2, 0x1F
	ble _0800FC7C
	movs r3, 0
	mov r8, r3
	ldr r4, [sp, 0x18]
	lsls r4, 5
	str r4, [sp, 0x34]
_0800FD4C:
	mov r7, r8
	lsls r0, r7, 2
	add r0, r8
	lsls r0, 4
	ldr r1, _0800FEDC
	adds r0, r1
	ldr r2, _0800FEE0
	ldr r1, [r2]
	adds r3, r1, r0
	ldr r4, _0800FEE4
	adds r1, r4
	lsls r2, r7, 5
	ldr r0, [r1]
	adds r0, r2
	str r0, [sp, 0x1C]
	ldrb r0, [r3]
	adds r7, 0x1
	str r7, [sp, 0x28]
	cmp r0, 0
	bne _0800FD76
	b _0800FF56
_0800FD76:
	movs r5, 0
	adds r3, 0x2
	mov r10, r3
	ldr r4, [sp, 0x1C]
	adds r4, 0x10
	ldr r6, _0800FEE0
_0800FD82:
	lsls r0, r5, 1
	mov r1, r10
	adds r2, r1, r0
	ldr r1, _0800FEE8
	strh r1, [r2]
	adds r1, r4, r0
	ldrh r3, [r1]
	movs r7, 0
	ldrsh r0, [r1, r7]
	cmp r0, 0
	blt _0800FDB0
	adds r1, r0, 0
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 4
	ldr r1, _0800FEDC
	adds r0, r1
	ldr r1, [r6]
	adds r1, r0
	ldrb r0, [r1]
	cmp r0, 0
	beq _0800FDB0
	strh r3, [r2]
_0800FDB0:
	adds r5, 0x1
	cmp r5, 0x7
	ble _0800FD82
	ldr r3, _0800FEE0
	ldr r2, [r3]
	ldr r4, _0800FEEC
	adds r0, r2, r4
	ldr r1, [r0]
	ldr r7, _0800FEF0
	adds r0, r2, r7
	ldr r3, [r0]
	cmp r1, 0
	blt _0800FDEC
	cmp r3, 0
	blt _0800FDEC
	lsls r0, r3, 2
	adds r0, r3
	lsls r0, 4
	ldr r4, _0800FEDC
	adds r0, r4
	adds r0, r2, r0
	ldrb r0, [r0]
	cmp r0, 0
	beq _0800FDEC
	adds r1, 0x4
	movs r0, 0x7
	ands r1, r0
	lsls r0, r1, 1
	add r0, r10
	strh r3, [r0]
_0800FDEC:
	movs r5, 0
_0800FDEE:
	movs r7, 0x1
	negs r7, r7
	str r7, [sp, 0x20]
	ldr r0, _0800FEF4
	str r0, [sp, 0x24]
	lsls r0, r5, 1
	mov r2, r10
	adds r1, r2, r0
	movs r3, 0
	ldrsh r1, [r1, r3]
	str r0, [sp, 0x30]
	adds r4, r5, 0x1
	str r4, [sp, 0x2C]
	cmp r1, 0
	blt _0800FE0E
	b _0800FF4E
_0800FE0E:
	movs r6, 0
_0800FE10:
	lsls r0, r6, 2
	adds r0, r6
	lsls r0, 4
	ldr r7, _0800FEDC
	adds r0, r7
	ldr r2, _0800FEE0
	ldr r1, [r2]
	adds r3, r1, r0
	ldr r4, _0800FEE4
	adds r1, r4
	lsls r2, r6, 5
	ldr r0, [r1]
	adds r2, r0, r2
	adds r7, r6, 0x1
	mov r9, r7
	cmp r6, r8
	bne _0800FE34
	b _0800FF3A
_0800FE34:
	ldrb r0, [r3]
	cmp r0, 0
	bne _0800FE3C
	b _0800FF3A
_0800FE3C:
	movs r1, 0x4
	ldrsh r0, [r2, r1]
	ldr r3, [sp, 0x1C]
	movs r4, 0x4
	ldrsh r1, [r3, r4]
	subs r0, r1
	lsls r0, 8
	str r0, [sp, 0xC]
	movs r7, 0x6
	ldrsh r0, [r2, r7]
	movs r2, 0x6
	ldrsh r1, [r3, r2]
	subs r0, r1
	lsls r0, 8
	str r0, [sp, 0x10]
	add r0, sp, 0xC
	bl Atan2_4096
	adds r2, r0, 0
	ldr r0, [sp, 0xC]
	cmp r0, 0
	bge _0800FE6A
	adds r0, 0x3
_0800FE6A:
	asrs r1, r0, 2
	str r1, [sp, 0xC]
	ldr r0, [sp, 0x10]
	cmp r0, 0
	bge _0800FE76
	adds r0, 0x3
_0800FE76:
	asrs r0, 2
	str r0, [sp, 0x10]
	cmp r1, 0
	bge _0800FE80
	adds r1, 0xFF
_0800FE80:
	asrs r1, 8
	str r1, [sp, 0xC]
	cmp r0, 0
	bge _0800FE8A
	adds r0, 0xFF
_0800FE8A:
	asrs r0, 8
	str r0, [sp, 0x10]
	cmp r1, 0
	bne _0800FE96
	movs r0, 0x1
	str r0, [sp, 0xC]
_0800FE96:
	ldr r0, [sp, 0x10]
	cmp r0, 0
	bne _0800FEA0
	movs r0, 0x1
	str r0, [sp, 0x10]
_0800FEA0:
	movs r7, 0
	cmp r5, 0x2
	bne _0800FF04
	ldr r1, _0800FEF8
	ldr r4, _0800FEFC
	movs r3, 0x8
	cmp r2, r1
	ble _0800FEB8
	ldr r0, _0800FF00
_0800FEB2:
	adds r2, r0
	cmp r2, r1
	bgt _0800FEB2
_0800FEB8:
	cmp r2, 0
	bge _0800FEC6
	movs r0, 0x80
	lsls r0, 5
_0800FEC0:
	adds r2, r0
	cmp r2, 0
	blt _0800FEC0
_0800FEC6:
	adds r1, r3, r4
	movs r3, 0
	ldrsh r0, [r1, r3]
	cmp r0, r2
	blt _0800FF20
	movs r4, 0x2
	ldrsh r0, [r1, r4]
	cmp r0, r2
	ble _0800FF1C
	b _0800FF20
	.align 2, 0
_0800FEDC: .4byte 0x00004018
_0800FEE0: .4byte gUnknown_203B0E4
_0800FEE4: .4byte 0x00004014
_0800FEE8: .4byte 0x0000ffff
_0800FEEC: .4byte 0x00004a28
_0800FEF0: .4byte 0x00004a1c
_0800FEF4: .4byte 0x000f423f
_0800FEF8: .4byte 0x00000fff
_0800FEFC: .4byte gUnknown_80D3EBC
_0800FF00: .4byte 0xfffff000
_0800FF04:
	ldr r0, _0800FFC8
	lsls r1, r5, 2
	adds r1, r0
	movs r3, 0
	ldrsh r0, [r1, r3]
	cmp r0, r2
	bgt _0800FF1C
	movs r4, 0x2
	ldrsh r0, [r1, r4]
	cmp r0, r2
	ble _0800FF1C
	movs r7, 0x1
_0800FF1C:
	cmp r7, 0
	beq _0800FF3A
_0800FF20:
	ldr r0, [sp, 0xC]
	adds r1, r0, 0
	muls r1, r0
	ldr r0, [sp, 0x10]
	adds r7, r0, 0
	muls r7, r0
	adds r0, r7, 0
	adds r1, r0
	ldr r0, [sp, 0x24]
	cmp r0, r1
	ble _0800FF3A
	str r1, [sp, 0x24]
	str r6, [sp, 0x20]
_0800FF3A:
	mov r6, r9
	cmp r6, 0x1F
	bgt _0800FF42
	b _0800FE10
_0800FF42:
	ldr r1, [sp, 0x20]
	cmp r1, 0
	blt _0800FF4E
	ldr r0, [sp, 0x30]
	add r0, r10
	strh r1, [r0]
_0800FF4E:
	ldr r5, [sp, 0x2C]
	cmp r5, 0x7
	bgt _0800FF56
	b _0800FDEE
_0800FF56:
	ldr r3, [sp, 0x28]
	mov r8, r3
	cmp r3, 0x1F
	bgt _0800FF60
	b _0800FD4C
_0800FF60:
	ldr r4, _0800FFCC
	ldr r1, [r4]
	ldr r7, _0800FFD0
	adds r0, r1, r7
	ldr r1, [r1, 0xC]
	movs r2, 0
	str r2, [sp]
	str r2, [sp, 0x4]
	movs r2, 0x1
	str r2, [sp, 0x8]
	movs r2, 0
	movs r3, 0
	bl AxResInitFile
	ldr r2, [r4]
	ldr r1, _0800FFD4
	adds r0, r2, r1
	ldr r3, [sp, 0x18]
	str r3, [r0]
	ldr r4, _0800FFD8
	adds r1, r2, r4
	ldr r7, _0800FFDC
	adds r0, r2, r7
	ldr r0, [r0]
	ldr r3, [sp, 0x34]
	adds r0, r3, r0
	ldr r0, [r0, 0x4]
	str r0, [r1]
	ldrh r0, [r1]
	subs r0, 0x78
	subs r4, 0x4
	adds r1, r2, r4
	strh r0, [r1]
	ldr r7, _0800FFE0
	adds r0, r2, r7
	ldrh r0, [r0]
	subs r0, 0x50
	ldr r1, _0800FFE4
	adds r2, r1
	strh r0, [r2]
	bl sub_8011240
	bl sub_80110B0
	add sp, 0x40
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_0800FFC8: .4byte gUnknown_80D3EBC
_0800FFCC: .4byte gUnknown_203B0E4
_0800FFD0: .4byte 0x00004c10
_0800FFD4: .4byte 0x00004a18
_0800FFD8: .4byte 0x00004dd8
_0800FFDC: .4byte 0x00004014
_0800FFE0: .4byte 0x00004dda
_0800FFE4: .4byte 0x00004dd6
	thumb_func_end sub_800FC5C

	thumb_func_start sub_800FFE8
sub_800FFE8:
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	adds r1, r0, 0
	cmp r0, 0x39
	bhi _08010004
	cmp r0, 0
	beq _0801000C
	ldr r0, _08010008
	ldr r0, [r0]
	adds r0, r1
	ldrb r0, [r0]
	cmp r0, 0
	bne _0801000C
_08010004:
	movs r0, 0
	b _0801000E
	.align 2, 0
_08010008: .4byte gFriendAreas
_0801000C:
	movs r0, 0x1
_0801000E:
	pop {r1}
	bx r1
	thumb_func_end sub_800FFE8

	thumb_func_start sub_8010014
sub_8010014:
	push {r4,r5,lr}
	sub sp, 0x20
	ldr r1, _08010094
	mov r0, sp
	movs r2, 0x10
	bl memcpy
	add r4, sp, 0x10
	ldr r1, _08010098
	adds r0, r4, 0
	movs r2, 0x10
	bl memcpy
	movs r2, 0
	ldr r0, _0801009C
	ldrh r3, [r0]
	movs r0, 0x80
	lsls r0, 1
	ands r0, r3
	mov r5, sp
	cmp r0, 0
	beq _08010042
	adds r5, r4, 0
_08010042:
	adds r1, r3, 0
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	beq _0801004E
	movs r2, 0x1
_0801004E:
	movs r0, 0x10
	ands r0, r1
	cmp r0, 0
	beq _0801005A
	movs r0, 0x2
	orrs r2, r0
_0801005A:
	movs r0, 0x40
	ands r0, r1
	cmp r0, 0
	beq _08010066
	movs r0, 0x4
	orrs r2, r0
_08010066:
	movs r0, 0x20
	ands r0, r3
	cmp r0, 0
	beq _08010072
	movs r0, 0x8
	orrs r2, r0
_08010072:
	ldr r3, _080100A0
	adds r2, r5, r2
	ldrb r1, [r2]
	ldrb r0, [r3]
	cmp r0, r1
	bne _080100A8
	ldr r1, _080100A4
	ldrb r0, [r1]
	adds r0, 0x1
	strb r0, [r1]
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x2
	bls _080100B0
	ldrb r0, [r2]
	b _080100B2
	.align 2, 0
_08010094: .4byte gUnknown_80D3EDC
_08010098: .4byte gUnknown_80D3EEC
_0801009C: .4byte gRealInputs
_080100A0: .4byte gUnknown_202DE18
_080100A4: .4byte gUnknown_202DE19
_080100A8:
	strb r1, [r3]
	ldr r1, _080100BC
	movs r0, 0
	strb r0, [r1]
_080100B0:
	movs r0, 0xFF
_080100B2:
	add sp, 0x20
	pop {r4,r5}
	pop {r1}
	bx r1
	.align 2, 0
_080100BC: .4byte gUnknown_202DE19
	thumb_func_end sub_8010014

	thumb_func_start sub_80100C0
sub_80100C0:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x18
	str r0, [sp, 0xC]
	mov r8, r2
	ldr r4, _080101E0
	ldr r2, [r4]
	ldr r3, _080101E4
	adds r0, r2, r3
	ldr r2, [r2, 0xC]
	movs r3, 0x7
	ands r3, r1
	movs r1, 0
	str r1, [sp]
	str r1, [sp, 0x4]
	movs r1, 0x1
	str r1, [sp, 0x8]
	adds r1, r2, 0
	movs r2, 0
	bl AxResInitFile
	bl sub_8011168
	ldr r0, [r4]
	ldr r2, _080101E8
	adds r1, r0, r2
	ldr r1, [r1]
	ldr r3, _080101EC
	adds r0, r3
	ldr r2, [r0]
	lsls r1, 5
	adds r1, r2
	ldr r1, [r1, 0x4]
	mov r9, r1
	ldr r1, [sp, 0xC]
	lsls r0, r1, 5
	adds r0, r2
	ldr r0, [r0, 0x4]
	str r0, [sp, 0x10]
	bl PlayCursorUpDownSoundEffect
	movs r7, 0
	cmp r7, r8
	bge _0801018A
	ldr r2, [sp, 0x10]
	lsls r1, r2, 16
	asrs r1, 16
	mov r3, r9
	lsls r0, r3, 16
	asrs r0, 16
	subs r1, r0
	str r1, [sp, 0x14]
	movs r0, 0
	mov r10, r0
_08010132:
	ldr r0, _080101E0
	ldr r6, [r0]
	lsls r5, r7, 8
	mov r0, r10
	mov r1, r8
	bl __divsi3
	cmp r0, 0
	bge _08010146
	adds r0, 0xFF
_08010146:
	asrs r0, 8
	add r0, r9
	ldr r2, _080101F0
	adds r1, r6, r2
	strh r0, [r1]
	ldr r3, [sp, 0x10]
	asrs r0, r3, 16
	mov r1, r9
	asrs r4, r1, 16
	subs r0, r4
	muls r0, r5
	mov r1, r8
	bl __divsi3
	cmp r0, 0
	bge _08010168
	adds r0, 0xFF
_08010168:
	asrs r0, 8
	adds r0, r4
	ldr r2, _080101F4
	adds r1, r6, r2
	strh r0, [r1]
	bl sub_8011240
	bl sub_80110B0
	bl sub_801169C
	ldr r3, [sp, 0x14]
	lsls r0, r3, 8
	add r10, r0
	adds r7, 0x1
	cmp r7, r8
	blt _08010132
_0801018A:
	ldr r4, _080101E0
	ldr r0, [r4]
	ldr r2, _080101E8
	adds r1, r0, r2
	ldr r3, [sp, 0xC]
	str r3, [r1]
	ldr r1, _080101F0
	adds r2, r0, r1
	ldr r3, _080101EC
	adds r0, r3
	ldr r1, [r0]
	ldr r3, [sp, 0xC]
	lsls r0, r3, 5
	adds r0, r1
	ldr r0, [r0, 0x4]
	str r0, [r2]
	bl sub_8011240
	bl sub_80110B0
	bl sub_801169C
	ldr r1, [r4]
	ldr r2, _080101E4
	adds r0, r1, r2
	ldr r1, [r1, 0xC]
	movs r2, 0
	str r2, [sp]
	str r2, [sp, 0x4]
	movs r2, 0x1
	str r2, [sp, 0x8]
	movs r2, 0
	movs r3, 0
	bl AxResInitFile
	add sp, 0x18
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_080101E0: .4byte gUnknown_203B0E4
_080101E4: .4byte 0x00004c10
_080101E8: .4byte 0x00004a18
_080101EC: .4byte 0x00004014
_080101F0: .4byte 0x00004dd8
_080101F4: .4byte 0x00004dda
	thumb_func_end sub_80100C0

	thumb_func_start sub_80101F8
sub_80101F8:
	push {lr}
	adds r3, r0, 0
	lsls r1, 24
	lsrs r1, 24
	cmp r1, 0
	bne _08010218
	ldr r0, _08010214
	adds r2, r3, 0
	adds r2, 0x50
	adds r1, r3, 0
	movs r3, 0
	bl FormatString
	b _08010220
	.align 2, 0
_08010214: .4byte gUnknown_80D3EFC
_08010218:
	adds r0, r3, 0
	movs r2, 0
	bl WriteFriendAreaName
_08010220:
	pop {r0}
	bx r0
	thumb_func_end sub_80101F8

	thumb_func_start sub_8010224
sub_8010224:
	push {r4-r7,lr}
	lsls r0, 24
	lsrs r6, r0, 24
	movs r7, 0
	ldr r0, _08010248
	adds r4, r0, 0x4
	adds r5, r0, 0
	adds r5, 0x8
_08010234:
	movs r2, 0
	adds r3, r5, 0
_08010238:
	adds r0, r3, r2
	ldrb r0, [r0]
	cmp r0, r6
	bne _0801024C
	ldrh r0, [r4]
	strh r0, [r1]
	ldrh r0, [r4, 0x2]
	b _08010260
	.align 2, 0
_08010248: .4byte gFriendAreaLocations
_0801024C:
	adds r2, 0x1
	cmp r2, 0x7
	ble _08010238
	adds r4, 0x20
	adds r5, 0x20
	adds r7, 0x1
	cmp r7, 0x1F
	ble _08010234
	movs r0, 0
	strh r0, [r1]
_08010260:
	strh r0, [r1, 0x2]
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_8010224

	thumb_func_start sub_8010268
sub_8010268:
	push {r4-r6,lr}
	ldr r4, _080102D4
	add sp, r4
	adds r5, r0, 0
	ldr r1, _080102D8
	adds r0, 0xB0
	ldr r0, [r0]
	str r0, [r1]
	ldr r1, _080102DC
	ldr r2, _080102E0
	adds r0, r2, 0
	strh r0, [r1]
	movs r0, 0
	movs r1, 0x14
	bl sub_80095CC
	movs r0, 0x2
	bl UpdateFadeInTile
	bl sub_801059C
	adds r0, r5, 0x4
	bl sub_8010494
	bl sub_801178C
	movs r4, 0x3B
_0801029E:
	bl sub_8010960
	subs r4, 0x1
	cmp r4, 0
	bge _0801029E
	ldrb r0, [r5, 0x4]
	ldrb r1, [r5, 0x8]
	bl sub_8010344
	adds r0, r5, 0
	adds r0, 0x8
	bl sub_8010B74
	adds r6, r5, 0
	adds r6, 0x70
	movs r4, 0x3B
_080102BE:
	bl sub_8010960
	subs r4, 0x1
	cmp r4, 0
	bge _080102BE
	ldrb r0, [r5, 0x14]
	cmp r0, 0
	beq _080102E4
	movs r0, 0x20
	ldrsh r1, [r5, r0]
	b _080102E6
	.align 2, 0
_080102D4: .4byte 0xfffffc14
_080102D8: .4byte gUnknown_203B0E8
_080102DC: .4byte gUnknown_2026E4E
_080102E0: .4byte 0x00000a06
_080102E4:
	movs r1, 0
_080102E6:
	ldrb r0, [r5, 0x8]
	ldrb r3, [r6]
	movs r4, 0
	str r4, [sp]
	add r2, sp, 0x4
	bl sub_809034C
	cmp r0, 0
	beq _0801031C
	cmp r0, 0x1
	bne _0801030A
	add r0, sp, 0x4
	bl sub_8010C10
	adds r0, r5, 0
	adds r0, 0xB4
	strb r4, [r0]
	b _0801032C
_0801030A:
	cmp r0, 0x2
	bne _0801032C
	add r0, sp, 0x4
	bl sub_8010C58
	lsls r0, 24
	lsrs r1, r0, 24
	cmp r1, 0
	beq _08010326
_0801031C:
	adds r1, r5, 0
	adds r1, 0xB4
	movs r0, 0x1
	strb r0, [r1]
	b _0801032C
_08010326:
	adds r0, r5, 0
	adds r0, 0xB4
	strb r1, [r0]
_0801032C:
	bl sub_801091C
	bl sub_801073C
	bl nullsub_16
	movs r3, 0xFB
	lsls r3, 2
	add sp, r3
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end sub_8010268

	thumb_func_start sub_8010344
sub_8010344:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x1C
	lsls r0, 24
	lsls r1, 24
	ldr r2, _08010470
	lsrs r0, 22
	adds r0, r2
	lsrs r1, 22
	adds r1, r2
	ldr r2, [r1]
	str r2, [sp, 0x14]
	movs r3, 0
	ldrsh r5, [r1, r3]
	ldr r1, [r0]
	mov r9, r1
	movs r2, 0
	ldrsh r6, [r0, r2]
	subs r2, r5, r6
	cmp r2, 0
	bge _08010376
	negs r2, r2
_08010376:
	ldr r3, [sp, 0x14]
	asrs r0, r3, 16
	mov r3, r9
	asrs r1, r3, 16
	subs r4, r0, r1
	adds r3, r4, 0
	str r0, [sp, 0x18]
	mov r8, r1
	cmp r4, 0
	bge _0801038C
	negs r4, r4
_0801038C:
	cmp r4, r2
	bge _08010392
	adds r4, r2, 0
_08010392:
	lsrs r0, r4, 31
	adds r0, r4, r0
	asrs r4, r0, 1
	subs r0, r6, r5
	str r0, [sp, 0xC]
	str r3, [sp, 0x10]
	add r0, sp, 0xC
	bl Atan2_4096
	ldr r1, _08010474
	adds r3, r0, r1
	cmp r3, 0
	bge _080103B0
	ldr r2, _08010478
	adds r3, r0, r2
_080103B0:
	asrs r3, 9
	movs r0, 0x7
	ands r3, r0
	ldr r0, _0801047C
	ldr r1, [r0]
	ldr r2, _08010480
	adds r0, r1, r2
	ldr r2, _08010484
	adds r1, r2
	ldr r1, [r1]
	movs r2, 0
	str r2, [sp]
	str r2, [sp, 0x4]
	movs r2, 0x1
	str r2, [sp, 0x8]
	movs r2, 0
	bl AxResInitFile
	movs r7, 0
	cmp r7, r4
	bge _08010448
	mov r10, r5
_080103DC:
	ldr r0, _0801047C
	ldr r6, [r0]
	mov r3, r9
	lsls r0, r3, 16
	asrs r0, 16
	mov r1, r10
	subs r0, r1, r0
	lsls r5, r7, 8
	muls r0, r5
	adds r1, r4, 0
	bl __divsi3
	cmp r0, 0
	bge _080103FA
	adds r0, 0xFF
_080103FA:
	asrs r0, 8
	add r0, r9
	ldr r2, _08010488
	adds r1, r6, r2
	strh r0, [r1]
	ldr r3, [sp, 0x18]
	mov r1, r8
	subs r0, r3, r1
	muls r0, r5
	adds r1, r4, 0
	bl __divsi3
	cmp r0, 0
	bge _08010418
	adds r0, 0xFF
_08010418:
	asrs r0, 8
	add r0, r8
	ldr r2, _0801048C
	adds r1, r6, r2
	strh r0, [r1]
	bl sub_8010798
	bl sub_8010858
	bl sub_8010960
	ldr r0, _08010490
	ldrh r1, [r0, 0x2]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	bne _08010448
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	bne _08010448
	adds r7, 0x1
	cmp r7, r4
	blt _080103DC
_08010448:
	ldr r0, _0801047C
	ldr r0, [r0]
	ldr r3, _08010488
	adds r0, r3
	ldr r1, [sp, 0x14]
	str r1, [r0]
	bl sub_8010798
	bl sub_8010858
	bl sub_8010960
	add sp, 0x1C
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_08010470: .4byte gDungeonCoordinates
_08010474: .4byte 0xfffffc00
_08010478: .4byte 0xfffffdff
_0801047C: .4byte gUnknown_203B0E8
_08010480: .4byte 0x00005114
_08010484: .4byte 0x0000110c
_08010488: .4byte 0x000052dc
_0801048C: .4byte 0x000052de
_08010490: .4byte gRealInputs
	thumb_func_end sub_8010344

	thumb_func_start sub_8010494
sub_8010494:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0xC
	mov r9, r0
	movs r5, 0
	ldr r0, _080104C0
	mov r10, r0
	mov r8, r5
_080104AA:
	mov r1, r10
	ldr r0, [r1]
	mov r3, r8
	adds r4, r0, r3
	cmp r5, 0x3E
	bgt _080104C4
	mov r0, r9
	adds r0, 0x6D
	adds r0, r5
	ldrb r0, [r0]
	b _080104C6
	.align 2, 0
_080104C0: .4byte gUnknown_203B0E8
_080104C4:
	movs r0, 0x1
_080104C6:
	cmp r0, 0
	beq _0801050C
	movs r7, 0
	movs r6, 0x1
	strb r6, [r4]
	adds r3, r4, 0
	adds r3, 0x8
	mov r1, r10
	ldr r0, [r1]
	ldr r1, _08010504
	adds r0, r1
	ldr r1, [r0]
	movs r2, 0x1
	cmp r5, 0x3F
	bne _080104E6
	movs r2, 0xC
_080104E6:
	movs r0, 0x40
	str r0, [sp]
	str r7, [sp, 0x4]
	str r6, [sp, 0x8]
	adds r0, r3, 0
	movs r3, 0
	bl AxResInitFile
	ldr r1, _08010508
	lsls r0, r5, 2
	adds r0, r1
	ldr r0, [r0]
	str r0, [r4, 0x4]
	b _0801050E
	.align 2, 0
_08010504: .4byte 0x00001108
_08010508: .4byte gDungeonCoordinates
_0801050C:
	strb r0, [r4]
_0801050E:
	movs r3, 0x44
	add r8, r3
	adds r5, 0x1
	cmp r5, 0x3F
	ble _080104AA
	movs r2, 0
	ldr r4, _0801057C
	ldr r1, [r4]
	ldr r3, _08010580
	adds r0, r1, r3
	ldr r3, _08010584
	adds r1, r3
	ldr r1, [r1]
	str r2, [sp]
	str r2, [sp, 0x4]
	movs r2, 0x1
	str r2, [sp, 0x8]
	movs r2, 0
	movs r3, 0
	bl AxResInitFile
	ldr r2, [r4]
	ldr r4, _08010588
	adds r3, r2, r4
	ldr r1, _0801058C
	mov r4, r9
	ldrb r0, [r4]
	lsls r0, 2
	adds r0, r1
	ldr r0, [r0]
	str r0, [r3]
	ldrh r0, [r3]
	subs r0, 0x78
	ldr r3, _08010590
	adds r1, r2, r3
	strh r0, [r1]
	ldr r4, _08010594
	adds r0, r2, r4
	ldrh r0, [r0]
	subs r0, 0x50
	ldr r1, _08010598
	adds r2, r1
	strh r0, [r2]
	bl sub_8010798
	bl sub_8010858
	add sp, 0xC
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_0801057C: .4byte gUnknown_203B0E8
_08010580: .4byte 0x00005114
_08010584: .4byte 0x0000110c
_08010588: .4byte 0x000052dc
_0801058C: .4byte gDungeonCoordinates
_08010590: .4byte 0x000052d8
_08010594: .4byte 0x000052de
_08010598: .4byte 0x000052da
	thumb_func_end sub_8010494

	thumb_func_start sub_801059C
sub_801059C:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x14
	bl GetPlayerPokemonStruct
	adds r7, r0, 0
	ldr r6, _080106E4
	ldr r0, [r6]
	ldr r5, _080106E8
	adds r1, r5, 0
	bl OpenFileAndGetFileDataPtr
	str r0, [sp, 0xC]
	ldr r0, [r6, 0x4]
	adds r1, r5, 0
	bl OpenFileAndGetFileDataPtr
	str r0, [sp, 0x10]
	ldr r1, _080106EC
	movs r0, 0x8
	ldrsh r2, [r7, r0]
	mov r0, sp
	bl sprintf
	ldr r1, _080106F0
	mov r8, r1
	mov r0, sp
	bl OpenFileAndGetFileDataPtr
	ldr r4, _080106F4
	ldr r1, [r4]
	ldr r2, _080106F8
	adds r1, r2
	str r0, [r1]
	ldr r0, _080106FC
	adds r1, r5, 0
	bl OpenFileAndGetFileDataPtr
	ldr r1, [r4]
	ldr r3, _08010700
	mov r9, r3
	add r1, r9
	str r0, [r1]
	ldr r0, [r6, 0x8]
	adds r1, r5, 0
	bl OpenFileAndGetFileDataPtr
	ldr r1, [r4]
	ldr r2, _08010704
	mov r10, r2
	add r1, r10
	str r0, [r1]
	ldr r0, _08010708
	mov r1, r8
	bl OpenFileAndGetFileDataPtr
	ldr r1, [r4]
	ldr r3, _0801070C
	adds r1, r3
	str r0, [r1]
	ldr r0, [r6, 0xC]
	adds r1, r5, 0
	bl OpenFileAndGetFileDataPtr
	ldr r1, [r4]
	movs r2, 0x88
	lsls r2, 5
	adds r1, r2
	str r0, [r1]
	movs r3, 0x8
	ldrsh r0, [r7, r3]
	movs r1, 0
	bl GetPokemonOverworldPalette
	ldr r1, [r4]
	ldr r3, _08010710
	adds r2, r1, r3
	lsls r0, 24
	lsrs r0, 24
	str r0, [r2]
	add r1, r9
	ldr r0, [r1]
	movs r1, 0x40
	movs r2, 0x1F
	movs r3, 0
	bl sub_8005610
	ldr r0, _08010714
	movs r1, 0
	ldr r2, [sp, 0xC]
	bl DecompressATGlobalFile
	ldr r1, [r4]
	ldr r2, _08010718
	adds r0, r1, r2
	add r1, r10
	ldr r1, [r1]
	movs r2, 0x10
	bl sub_8004AA4
	movs r1, 0x80
	lsls r1, 7
	ldr r0, [r4]
	ldr r3, _0801071C
	adds r0, r3
	ldr r2, [sp, 0x10]
	bl DecompressATFile
	ldr r1, [r4]
	ldr r2, _08010720
	adds r0, r1, r2
	movs r2, 0
	str r2, [r0]
	ldr r3, _08010724
	adds r0, r1, r3
	strh r2, [r0]
	ldr r0, _08010728
	adds r1, r0
	strh r2, [r1]
	movs r3, 0
	ldr r1, _0801072C
	mov r9, r1
	mov r8, r4
	ldr r7, _08010730
	ldr r2, _08010734
	adds r4, r2, 0
	ldr r6, _08010738
	movs r5, 0
_080106A2:
	mov r0, r8
	ldr r2, [r0]
	lsls r0, r3, 1
	adds r1, r2, r7
	adds r1, r0
	ldrh r0, [r1]
	orrs r0, r4
	strh r0, [r1]
	adds r2, r6
	adds r2, r3
	strb r5, [r2]
	adds r3, 0x1
	cmp r3, r9
	ble _080106A2
	ldr r0, [sp, 0xC]
	bl CloseFile
	ldr r0, [sp, 0x10]
	bl CloseFile
	movs r0, 0
	movs r1, 0x1
	movs r2, 0x1
	bl xxx_call_save_unk_text_struct_800641C
	add sp, 0x14
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_080106E4: .4byte gUnknown_80D4014
_080106E8: .4byte gTitleMenuFileArchive
_080106EC: .4byte gUnknown_80D405C
_080106F0: .4byte gMonsterFileArchive
_080106F4: .4byte gUnknown_203B0E8
_080106F8: .4byte 0x0000110c
_080106FC: .4byte gUnknown_80D4064
_08010700: .4byte 0x00001108
_08010704: .4byte 0x00001110
_08010708: .4byte gUnknown_80D406C
_0801070C: .4byte 0x00001104
_08010710: .4byte 0x000052d4
_08010714: .4byte 0x06008000
_08010718: .4byte 0x00005150
_0801071C: .4byte 0x00001114
_08010720: .4byte 0x000052d0
_08010724: .4byte 0x000052d8
_08010728: .4byte 0x000052da
_0801072C: .4byte 0x000005db
_08010730: .4byte 0x000052e0
_08010734: .4byte 0x0000ffff
_08010738: .4byte 0x00005e98
	thumb_func_end sub_801059C

	thumb_func_start sub_801073C
sub_801073C:
	push {r4,lr}
	ldr r4, _08010784
	ldr r0, [r4]
	ldr r1, _08010788
	adds r0, r1
	ldr r0, [r0]
	bl CloseFile
	ldr r0, [r4]
	ldr r1, _0801078C
	adds r0, r1
	ldr r0, [r0]
	bl CloseFile
	ldr r0, [r4]
	ldr r1, _08010790
	adds r0, r1
	ldr r0, [r0]
	bl CloseFile
	ldr r0, [r4]
	movs r1, 0x88
	lsls r1, 5
	adds r0, r1
	ldr r0, [r0]
	bl CloseFile
	ldr r0, [r4]
	ldr r1, _08010794
	adds r0, r1
	ldr r0, [r0]
	bl CloseFile
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08010784: .4byte gUnknown_203B0E8
_08010788: .4byte 0x00001110
_0801078C: .4byte 0x0000110c
_08010790: .4byte 0x00001108
_08010794: .4byte 0x00001104
	thumb_func_end sub_801073C

	thumb_func_start sub_8010798
sub_8010798:
	push {r4-r6,lr}
	ldr r2, _080107BC
	ldr r0, [r2]
	ldr r1, _080107C0
	adds r3, r0, r1
	movs r4, 0
	ldrsh r1, [r3, r4]
	ldr r5, _080107C4
	adds r4, r0, r5
	movs r6, 0
	ldrsh r0, [r4, r6]
	subs r1, r0
	adds r5, r2, 0
	cmp r1, 0x2F
	bgt _080107C8
	ldrh r0, [r3]
	subs r0, 0x30
	b _080107D0
	.align 2, 0
_080107BC: .4byte gUnknown_203B0E8
_080107C0: .4byte 0x000052dc
_080107C4: .4byte 0x000052d8
_080107C8:
	cmp r1, 0xC0
	ble _080107D2
	ldrh r0, [r3]
	subs r0, 0xC0
_080107D0:
	strh r0, [r4]
_080107D2:
	ldr r0, [r5]
	ldr r1, _080107F0
	adds r3, r0, r1
	movs r2, 0
	ldrsh r1, [r3, r2]
	ldr r4, _080107F4
	adds r2, r0, r4
	movs r6, 0
	ldrsh r0, [r2, r6]
	subs r1, r0
	cmp r1, 0x2F
	bgt _080107F8
	ldrh r0, [r3]
	subs r0, 0x30
	b _08010800
	.align 2, 0
_080107F0: .4byte 0x000052de
_080107F4: .4byte 0x000052da
_080107F8:
	cmp r1, 0x70
	ble _08010802
	ldrh r0, [r3]
	subs r0, 0x70
_08010800:
	strh r0, [r2]
_08010802:
	adds r3, r5, 0
	ldr r0, [r3]
	ldr r4, _08010850
	adds r1, r0, r4
	movs r2, 0
	ldrsh r0, [r1, r2]
	cmp r0, 0
	bge _08010816
	movs r0, 0
	strh r0, [r1]
_08010816:
	ldr r0, [r3]
	ldr r2, _08010854
	adds r1, r0, r2
	movs r6, 0
	ldrsh r0, [r1, r6]
	cmp r0, 0
	bge _08010828
	movs r0, 0
	strh r0, [r1]
_08010828:
	ldr r0, [r3]
	adds r1, r0, r4
	movs r3, 0
	ldrsh r0, [r1, r3]
	cmp r0, 0xEF
	ble _08010838
	movs r0, 0xF0
	strh r0, [r1]
_08010838:
	ldr r0, [r5]
	adds r2, r0, r2
	movs r4, 0
	ldrsh r0, [r2, r4]
	cmp r0, 0x9F
	ble _08010848
	movs r0, 0xA0
	strh r0, [r2]
_08010848:
	pop {r4-r6}
	pop {r0}
	bx r0
	.align 2, 0
_08010850: .4byte 0x000052d8
_08010854: .4byte 0x000052da
	thumb_func_end sub_8010798

	thumb_func_start sub_8010858
sub_8010858:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x4
	ldr r0, _080108FC
	ldr r1, [r0]
	ldr r2, _08010900
	adds r1, r2
	ldrh r1, [r1]
	lsls r1, 16
	asrs r6, r1, 19
	adds r2, r6, 0
	movs r3, 0
	mov r10, r0
	movs r0, 0x1F
	mov r9, r0
_0801087C:
	mov r1, r10
	ldr r0, [r1]
	ldr r1, _08010904
	adds r0, r1
	ldrh r0, [r0]
	lsls r0, 16
	asrs r4, r0, 19
	lsls r1, r2, 7
	adds r2, 0x1
	mov r12, r2
	adds r3, 0x1
	mov r8, r3
	movs r7, 0x1E
	lsls r0, r4, 1
	adds r5, r0, r1
_0801089A:
	mov r2, r9
	ands r4, r2
	ands r6, r2
	lsls r2, r4, 1
	lsls r0, r6, 6
	adds r2, r0
	ldr r3, _08010908
	adds r3, r2, r3
	str r3, [sp]
	mov r0, r10
	ldr r1, [r0]
	ldr r3, _0801090C
	adds r0, r1, r3
	adds r0, r5
	ldrh r0, [r0]
	ldr r3, [sp]
	strh r0, [r3]
	ldr r0, _08010910
	adds r2, r0
	ldr r3, _08010914
	adds r1, r3
	adds r1, r5
	ldrh r0, [r1]
	strh r0, [r2]
	adds r5, 0x2
	adds r4, 0x1
	subs r7, 0x1
	cmp r7, 0
	bge _0801089A
	mov r2, r12
	adds r6, 0x1
	mov r3, r8
	cmp r3, 0x14
	ble _0801087C
	movs r0, 0x2
	bl sub_80098F8
	movs r0, 0x3
	bl sub_80098F8
	add sp, 0x4
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_080108FC: .4byte gUnknown_203B0E8
_08010900: .4byte 0x000052da
_08010904: .4byte 0x000052d8
_08010908: .4byte gFontTiles_202C038
_0801090C: .4byte 0x00003114
_08010910: .4byte gFontTilesExtra_202C838
_08010914: .4byte 0x00001114
	thumb_func_end sub_8010858

	thumb_func_start nullsub_24
nullsub_24:
	bx lr
	thumb_func_end nullsub_24

	thumb_func_start sub_801091C
sub_801091C:
	push {r4,r5,lr}
	bl sub_8010950
	bl sub_80117C4
	ldr r5, _08010948
	movs r4, 0x3B
_0801092A:
	ldr r1, [r5]
	ldr r0, _0801094C
	adds r1, r0
	ldr r0, [r1]
	subs r0, 0x2
	str r0, [r1]
	bl sub_8010960
	subs r4, 0x1
	cmp r4, 0
	bge _0801092A
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_08010948: .4byte gUnknown_203B0E8
_0801094C: .4byte 0x000052d0
	thumb_func_end sub_801091C

	thumb_func_start sub_8010950
sub_8010950:
	push {lr}
	movs r0, 0
	movs r1, 0x1
	movs r2, 0x1
	bl xxx_call_save_unk_text_struct_800641C
	pop {r0}
	bx r0
	thumb_func_end sub_8010950

	thumb_func_start sub_8010960
sub_8010960:
	push {r4-r6,lr}
	ldr r6, _080109EC
	ldr r1, [r6]
	ldr r4, _080109F0
	adds r0, r1, r4
	movs r2, 0
	ldrsh r0, [r0, r2]
	ldr r5, _080109F4
	adds r1, r5
	movs r2, 0
	ldrsh r1, [r1, r2]
	bl SetBG2RegOffsets
	ldr r1, [r6]
	adds r4, r1, r4
	movs r2, 0
	ldrsh r0, [r4, r2]
	adds r1, r5
	movs r2, 0
	ldrsh r1, [r1, r2]
	bl SetBG3RegOffsets
	movs r0, 0x1
	bl sub_8010A88
	bl sub_8010A00
	movs r0, 0
	movs r1, 0
	bl sub_8005838
	ldr r0, _080109F8
	ldr r0, [r0]
	ldrb r0, [r0, 0xA]
	bl nullsub_8
	bl sub_8005180
	bl sub_80060EC
	ldr r0, _080109FC
	ldr r0, [r0]
	bl IncrementPlayTime
	bl sub_800CB20
	bl LoadBufferedInputs
	bl CopySpritesToOam
	bl sub_8005304
	bl TransferBGPaletteBuffer
	bl xxx_call_update_bg_vram
	bl nullsub_24
	bl sub_8009908
	bl xxx_call_update_bg_sound_input
	bl sub_8011860
	movs r0, 0
	bl ResetSprites
	pop {r4-r6}
	pop {r0}
	bx r0
	.align 2, 0
_080109EC: .4byte gUnknown_203B0E8
_080109F0: .4byte 0x000052d8
_080109F4: .4byte 0x000052da
_080109F8: .4byte gGameOptionsRef
_080109FC: .4byte gPlayTimeRef
	thumb_func_end sub_8010960

	thumb_func_start sub_8010A00
sub_8010A00:
	push {r4-r6,lr}
	movs r3, 0
	ldr r6, _08010A7C
	ldr r0, [r6]
	ldr r2, _08010A80
	adds r1, r0, r2
	ldr r2, [r1]
	cmp r2, 0x1E
	bgt _08010A74
	movs r3, 0x88
	lsls r3, 5
	adds r0, r3
	ldr r0, [r0]
	ldr r5, [r0, 0x4]
	adds r0, r2, 0x1
	str r0, [r1]
	cmp r0, 0x1E
	ble _08010A28
	movs r0, 0x1F
	str r0, [r1]
_08010A28:
	movs r4, 0
_08010A2A:
	ldr r0, [r6]
	ldr r1, _08010A80
	adds r0, r1
	ldr r2, [r0]
	adds r0, r4, 0
	adds r1, r5, 0
	movs r3, 0
	bl SetBGPaletteBufferColorRGB
	adds r5, 0x4
	adds r4, 0x1
	cmp r4, 0xDF
	ble _08010A2A
	ldr r0, _08010A7C
	ldr r0, [r0]
	ldr r2, _08010A84
	adds r0, r2
	ldr r0, [r0]
	ldr r5, [r0, 0x4]
	movs r4, 0
_08010A52:
	movs r3, 0x80
	lsls r3, 1
	adds r0, r4, r3
	ldr r1, _08010A7C
	ldr r1, [r1]
	ldr r2, _08010A80
	adds r1, r2
	ldr r2, [r1]
	adds r1, r5, 0
	movs r3, 0
	bl SetBGPaletteBufferColorRGB
	adds r5, 0x4
	adds r4, 0x1
	cmp r4, 0xEF
	ble _08010A52
	movs r3, 0x1
_08010A74:
	adds r0, r3, 0
	pop {r4-r6}
	pop {r1}
	bx r1
	.align 2, 0
_08010A7C: .4byte gUnknown_203B0E8
_08010A80: .4byte 0x000052d0
_08010A84: .4byte 0x00001104
	thumb_func_end sub_8010A00

	thumb_func_start sub_8010A88
sub_8010A88:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x14
	lsls r0, 24
	lsrs r0, 24
	mov r9, r0
	add r0, sp, 0x8
	bl sub_8004E8C
	add r1, sp, 0x8
	ldr r0, _08010B58
	strh r0, [r1, 0x4]
	movs r0, 0x80
	lsls r0, 4
	strh r0, [r1, 0xA]
	ldr r6, _08010B5C
	ldr r0, [r6]
	ldr r2, _08010B60
	adds r1, r0, r2
	ldr r5, [r1]
	ldr r3, _08010B64
	adds r0, r3
	bl RunAxAnimationFrame
	mov r0, r9
	cmp r0, 0
	beq _08010AF6
	ldr r4, [r6]
	ldr r1, _08010B64
	adds r0, r4, r1
	ldr r2, _08010B68
	adds r1, r4, r2
	movs r3, 0
	ldrsh r1, [r1, r3]
	lsls r2, r5, 16
	asrs r2, 16
	subs r1, r2
	ldr r3, _08010B6C
	adds r2, r4, r3
	movs r3, 0
	ldrsh r2, [r2, r3]
	asrs r3, r5, 16
	subs r2, r3
	ldr r3, _08010B70
	adds r4, r3
	ldr r3, [r4]
	str r3, [sp]
	add r3, sp, 0x8
	str r3, [sp, 0x4]
	movs r3, 0x3
	bl DoAxFrame_800558C
_08010AF6:
	lsls r0, r5, 16
	asrs r0, 16
	mov r10, r0
	movs r7, 0
	asrs r5, 16
	mov r8, r5
	movs r6, 0x3F
_08010B04:
	ldr r1, _08010B5C
	ldr r0, [r1]
	adds r4, r0, r7
	ldrb r0, [r4]
	cmp r0, 0
	beq _08010B40
	adds r5, r4, 0
	adds r5, 0x8
	adds r0, r5, 0
	bl RunAxAnimationFrame
	mov r2, r9
	cmp r2, 0
	beq _08010B40
	movs r3, 0x4
	ldrsh r1, [r4, r3]
	mov r0, r10
	subs r1, r0
	movs r3, 0x6
	ldrsh r2, [r4, r3]
	mov r0, r8
	subs r2, r0
	movs r0, 0
	str r0, [sp]
	add r3, sp, 0x8
	str r3, [sp, 0x4]
	adds r0, r5, 0
	movs r3, 0x1
	bl DoAxFrame_800558C
_08010B40:
	adds r7, 0x44
	subs r6, 0x1
	cmp r6, 0
	bge _08010B04
	add sp, 0x14
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_08010B58: .4byte 0x0000f3ff
_08010B5C: .4byte gUnknown_203B0E8
_08010B60: .4byte 0x000052d8
_08010B64: .4byte 0x00005114
_08010B68: .4byte 0x000052dc
_08010B6C: .4byte 0x000052de
_08010B70: .4byte 0x000052d4
	thumb_func_end sub_8010A88

	thumb_func_start sub_8010B74
sub_8010B74:
	push {r4,r5,lr}
	sub sp, 0x64
	adds r5, r0, 0
	add r4, sp, 0x4
	adds r0, r4, 0
	movs r1, 0
	movs r2, 0x60
	bl memset
	movs r2, 0x3
	str r2, [sp, 0x8]
	movs r0, 0xC
	strh r0, [r4, 0x8]
	movs r1, 0x2
	strh r1, [r4, 0xA]
	movs r0, 0x10
	strh r0, [r4, 0xC]
	strh r1, [r4, 0xE]
	strh r1, [r4, 0x10]
	str r2, [sp, 0x20]
	str r2, [sp, 0x38]
	str r2, [sp, 0x50]
	ldr r0, _08010BC0
	ldr r0, [r0]
	ldr r2, _08010BC4
	adds r1, r0, r2
	movs r2, 0
	ldrsh r1, [r1, r2]
	ldr r2, _08010BC8
	adds r0, r2
	movs r2, 0
	ldrsh r0, [r0, r2]
	subs r1, r0
	cmp r1, 0x50
	bgt _08010BCC
	add r1, sp, 0x4
	movs r0, 0x11
	b _08010BD0
	.align 2, 0
_08010BC0: .4byte gUnknown_203B0E8
_08010BC4: .4byte 0x000052de
_08010BC8: .4byte 0x000052da
_08010BCC:
	add r1, sp, 0x4
	movs r0, 0x1
_08010BD0:
	strh r0, [r1, 0xA]
	add r0, sp, 0x4
	movs r1, 0x1
	movs r2, 0x1
	bl xxx_call_save_unk_text_struct_800641C
	movs r0, 0
	bl sub_80073B8
	ldr r0, _08010C08
	adds r1, r5, 0
	bl CopyDungeonName1toBuffer
	ldr r2, _08010C0C
	movs r0, 0
	str r0, [sp]
	movs r0, 0xC
	movs r1, 0x2
	movs r3, 0
	bl PrintFormattedStringOnWindow
	movs r0, 0
	bl sub_80073E0
	add sp, 0x64
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_08010C08: .4byte gFormatBuffer_Monsters
_08010C0C: .4byte gUnknown_80D4074
	thumb_func_end sub_8010B74

	thumb_func_start sub_8010C10
sub_8010C10:
	push {r4,lr}
	sub sp, 0x18
	movs r2, 0
	str r2, [sp]
	movs r1, 0x3
	str r1, [sp, 0x4]
	str r2, [sp, 0x8]
	str r2, [sp, 0xC]
	ldr r1, _08010C54
	str r1, [sp, 0x10]
	movs r1, 0
	movs r3, 0
	bl CreateMenuDialogueBoxAndPortrait
_08010C2C:
	bl DrawDialogueBoxString
	bl sub_8010960
	add r0, sp, 0x14
	bl sub_80144A4
	cmp r0, 0
	bne _08010C2C
	movs r4, 0x9
_08010C40:
	bl sub_8010960
	subs r4, 0x1
	cmp r4, 0
	bge _08010C40
	add sp, 0x18
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08010C54: .4byte 0x00000301
	thumb_func_end sub_8010C10

	thumb_func_start sub_8010C58
sub_8010C58:
	push {r4-r6,lr}
	sub sp, 0x38
	adds r5, r0, 0
	movs r2, 0
	ldrb r0, [r5]
	ldr r3, _08010D70
	add r6, sp, 0x2C
	cmp r0, 0
	beq _08010C7C
	adds r1, r5, 0
_08010C6C:
	ldrb r0, [r1]
	cmp r0, 0xA
	bne _08010C74
	adds r2, 0xC
_08010C74:
	adds r1, 0x1
	ldrb r0, [r1]
	cmp r0, 0
	bne _08010C6C
_08010C7C:
	adds r2, 0xB
	adds r0, r2, 0
	cmp r2, 0
	bge _08010C86
	adds r0, r2, 0x7
_08010C86:
	asrs r2, r0, 3
	movs r0, 0x13
	subs r0, r2
	movs r4, 0
	strh r0, [r3, 0xA]
	strh r2, [r3, 0x10]
	strh r2, [r3, 0xE]
	movs r0, 0xE
	subs r0, r2
	strh r0, [r3, 0x22]
	adds r0, r3, 0
	movs r1, 0x1
	movs r2, 0x1
	bl xxx_call_save_unk_text_struct_800641C
	movs r0, 0
	bl sub_80073B8
	str r4, [sp]
	movs r0, 0x4
	movs r1, 0
	adds r2, r5, 0
	movs r3, 0
	bl PrintFormattedStringOnWindow
	movs r0, 0
	bl sub_80073E0
	movs r0, 0x1
	bl sub_80073B8
	ldr r2, _08010D74
	str r4, [sp]
	movs r0, 0xA
	movs r1, 0
	movs r3, 0x1
	bl PrintFormattedStringOnWindow
	ldr r2, _08010D78
	str r4, [sp]
	movs r0, 0xA
	movs r1, 0xC
	movs r3, 0x1
	bl PrintFormattedStringOnWindow
	movs r0, 0x1
	bl sub_80073E0
	add r0, sp, 0x4
	movs r2, 0x1
	strh r2, [r0, 0x18]
	movs r1, 0x2
	strh r1, [r0, 0x1A]
	strh r1, [r0, 0x1C]
	strh r4, [r0, 0x1E]
	strh r4, [r0, 0x20]
	strh r4, [r0, 0x4]
	strh r4, [r0, 0x6]
	str r2, [sp, 0x4]
	strh r4, [r0, 0xC]
	strh r4, [r0, 0xE]
	strh r4, [r0, 0x14]
	strh r4, [r0, 0x16]
	movs r1, 0x8
	strh r1, [r0, 0x8]
	strh r1, [r0, 0xA]
	movs r1, 0x18
	bl sub_80137B0
	adds r0, r6, 0
	bl sub_801317C
	ldr r4, _08010D7C
_08010D18:
	add r0, sp, 0x4
	bl AddMenuCursorSprite
	bl sub_8010960
	ldrh r1, [r4, 0x4]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	beq _08010D36
	add r0, sp, 0x4
	bl MoveMenuCursorDown
	bl PlayCursorUpDownSoundEffect
_08010D36:
	ldrh r1, [r4, 0x4]
	movs r0, 0x40
	ands r0, r1
	cmp r0, 0
	beq _08010D4A
	add r0, sp, 0x4
	bl MoveMenuCursorUp
	bl PlayCursorUpDownSoundEffect
_08010D4A:
	ldrh r1, [r4, 0x2]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	bne _08010D5E
	mov r0, sp
	adds r0, 0x2D
	ldrb r0, [r0]
	cmp r0, 0
	beq _08010D18
_08010D5E:
	bl PlayAcceptSoundEffect
	add r0, sp, 0x4
	movs r1, 0x18
	ldrsh r0, [r0, r1]
	cmp r0, 0
	beq _08010D80
	movs r0, 0
	b _08010D82
	.align 2, 0
_08010D70: .4byte gUnknown_203B0EC
_08010D74: .4byte gUnknown_80D407C
_08010D78: .4byte gUnknown_80D4080
_08010D7C: .4byte gRealInputs
_08010D80:
	movs r0, 0x1
_08010D82:
	add sp, 0x38
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end sub_8010C58

	thumb_func_start sub_8010D8C
sub_8010D8C:
	lsls r0, 24
	ldr r2, _08010DA0
	lsrs r0, 22
	adds r0, r2
	ldrh r2, [r0]
	strh r2, [r1]
	ldrh r0, [r0, 0x2]
	strh r0, [r1, 0x2]
	bx lr
	.align 2, 0
_08010DA0: .4byte gDungeonCoordinates
	thumb_func_end sub_8010D8C

	thumb_func_start sub_8010DA4
sub_8010DA4:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0xC
	bl GetPlayerPokemonStruct
	mov r9, r0
	ldr r6, _08010EBC
	ldr r0, [r6]
	ldr r5, _08010EC0
	adds r1, r5, 0
	bl OpenFileAndGetFileDataPtr
	mov r10, r0
	ldr r0, [r6, 0x4]
	adds r1, r5, 0
	bl OpenFileAndGetFileDataPtr
	adds r7, r0, 0
	ldr r1, _08010EC4
	mov r0, r9
	movs r3, 0x8
	ldrsh r2, [r0, r3]
	mov r0, sp
	bl sprintf
	ldr r0, _08010EC8
	mov r8, r0
	mov r0, sp
	mov r1, r8
	bl OpenFileAndGetFileDataPtr
	ldr r4, _08010ECC
	ldr r1, [r4]
	str r0, [r1, 0xC]
	ldr r0, _08010ED0
	adds r1, r5, 0
	bl OpenFileAndGetFileDataPtr
	ldr r1, [r4]
	str r0, [r1, 0x8]
	ldr r0, [r6, 0x8]
	adds r1, r5, 0
	bl OpenFileAndGetFileDataPtr
	ldr r1, [r4]
	str r0, [r1, 0x10]
	ldr r0, _08010ED4
	mov r1, r8
	bl OpenFileAndGetFileDataPtr
	ldr r1, [r4]
	str r0, [r1, 0x4]
	ldr r0, [r6, 0xC]
	adds r1, r5, 0
	bl OpenFileAndGetFileDataPtr
	ldr r1, [r4]
	str r0, [r1]
	mov r1, r9
	movs r2, 0x8
	ldrsh r0, [r1, r2]
	movs r1, 0
	bl GetPokemonOverworldPalette
	ldr r2, [r4]
	ldr r3, _08010ED8
	adds r1, r2, r3
	lsls r0, 24
	lsrs r0, 24
	str r0, [r1]
	ldr r0, [r2, 0x8]
	movs r1, 0x40
	movs r2, 0x1F
	movs r3, 0
	bl sub_8005610
	ldr r0, _08010EDC
	movs r1, 0
	mov r2, r10
	bl DecompressATGlobalFile
	ldr r1, [r4]
	ldr r2, _08010EE0
	adds r0, r1, r2
	ldr r1, [r1, 0x10]
	movs r2, 0x10
	bl sub_8004AA4
	movs r1, 0x80
	lsls r1, 7
	ldr r0, [r4]
	adds r0, 0x14
	adds r2, r7, 0
	bl DecompressATFile
	ldr r1, [r4]
	ldr r3, _08010EE4
	adds r0, r1, r3
	movs r2, 0
	str r2, [r0]
	adds r3, 0x8
	adds r0, r1, r3
	strh r2, [r0]
	ldr r0, _08010EE8
	adds r1, r0
	strh r2, [r1]
	ldr r5, _08010EEC
	movs r3, 0
	movs r1, 0x7
_08010E84:
	ldr r0, [r4]
	adds r0, r2, r0
	adds r0, r5
	strh r3, [r0]
	adds r2, 0x3C
	subs r1, 0x1
	cmp r1, 0
	bge _08010E84
	mov r0, r10
	bl CloseFile
	adds r0, r7, 0
	bl CloseFile
	movs r0, 0
	movs r1, 0x1
	movs r2, 0x1
	bl xxx_call_save_unk_text_struct_800641C
	add sp, 0xC
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_08010EBC: .4byte gUnknown_80D408C
_08010EC0: .4byte gTitleMenuFileArchive
_08010EC4: .4byte gUnknown_80D40E4
_08010EC8: .4byte gMonsterFileArchive
_08010ECC: .4byte gUnknown_203B0E4
_08010ED0: .4byte gUnknown_80D40EC
_08010ED4: .4byte gUnknown_80D40F4
_08010ED8: .4byte 0x00004dd0
_08010EDC: .4byte 0x06008000
_08010EE0: .4byte 0x00004c4c
_08010EE4: .4byte 0x00004dcc
_08010EE8: .4byte 0x00004dd6
_08010EEC: .4byte 0x00004a30
	thumb_func_end sub_8010DA4

        .align 2,0
