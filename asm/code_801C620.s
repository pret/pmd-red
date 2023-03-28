	#include "asm/constants/gba_constants.inc"
	#include "asm/macros.inc"

	.syntax unified

	.text

	thumb_func_start sub_801CA08
sub_801CA08:
	push {r4-r6,lr}
	lsls r0, 24
	cmp r0, 0
	bne _0801CA28
	ldr r0, _0801CA20
	ldr r0, [r0]
	ldr r1, _0801CA24
	adds r0, r1
	bl sub_8013660
	movs r0, 0
	b _0801CB1E
	.align 2, 0
_0801CA20: .4byte gUnknown_203B244
_0801CA24: .4byte 0x000004b4
_0801CA28:
	ldr r0, _0801CA44
	ldr r0, [r0]
	ldr r1, _0801CA48
	adds r0, r1
	bl GetKeyPress
	subs r0, 0x1
	cmp r0, 0x5
	bhi _0801CAF2
	lsls r0, 2
	ldr r1, _0801CA4C
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0801CA44: .4byte gUnknown_203B244
_0801CA48: .4byte 0x000004b4
_0801CA4C: .4byte _0801CA50
	.align 2, 0
_0801CA50:
	.4byte _0801CA72
	.4byte _0801CA68
	.4byte _0801CAF2
	.4byte _0801CAE8
	.4byte _0801CA7C
	.4byte _0801CA7C
_0801CA68:
	movs r0, 0x1
	bl PlayMenuSoundEffect
	movs r0, 0x2
	b _0801CB1E
_0801CA72:
	movs r0, 0
	bl PlayMenuSoundEffect
	movs r0, 0x3
	b _0801CB1E
_0801CA7C:
	ldr r0, _0801CAD8
	ldr r0, [r0]
	ldr r0, [r0]
	cmp r0, 0x1
	bne _0801CAF2
	bl sub_801CB24
	lsls r0, 24
	lsrs r5, r0, 24
	adds r0, r5, 0
	bl sub_801CFE0
	movs r6, 0
	cmp r0, 0
	bne _0801CAB0
	bl GetNumberOfFilledInventorySlots
	adds r4, r0, 0
	bl sub_801CFB8
	adds r4, r0
	cmp r4, 0x13
	bgt _0801CAAC
	movs r6, 0x1
_0801CAAC:
	cmp r6, 0
	beq _0801CAE0
_0801CAB0:
	movs r0, 0x6
	bl PlayMenuSoundEffect
	ldr r0, _0801CAD8
	ldr r0, [r0]
	lsls r1, r5, 2
	adds r2, r0, 0
	adds r2, 0xF4
	adds r2, r1
	ldr r1, [r2]
	movs r3, 0x1
	eors r1, r3
	str r1, [r2]
	ldr r1, _0801CADC
	adds r0, r1
	movs r1, 0
	bl sub_80138B8
	b _0801CB18
	.align 2, 0
_0801CAD8: .4byte gUnknown_203B244
_0801CADC: .4byte 0x000004b4
_0801CAE0:
	movs r0, 0x2
	bl PlayMenuSoundEffect
	b _0801CAF2
_0801CAE8:
	movs r0, 0x4
	bl PlayMenuSoundEffect
	movs r0, 0x4
	b _0801CB1E
_0801CAF2:
	ldr r0, _0801CB0C
	ldr r0, [r0]
	ldr r1, _0801CB10
	adds r0, r1
	movs r1, 0x1
	bl sub_80138B8
	lsls r0, 24
	cmp r0, 0
	bne _0801CB14
	movs r0, 0
	b _0801CB1E
	.align 2, 0
_0801CB0C: .4byte gUnknown_203B244
_0801CB10: .4byte 0x000004b4
_0801CB14:
	bl sub_801CC38
_0801CB18:
	bl sub_801CCD8
	movs r0, 0x1
_0801CB1E:
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end sub_801CA08

	thumb_func_start sub_801CB24
sub_801CB24:
	ldr r0, _0801CB50
	ldr r0, [r0]
	ldr r2, _0801CB54
	adds r1, r0, r2
	movs r3, 0
	ldrsh r2, [r1, r3]
	movs r3, 0x9A
	lsls r3, 3
	adds r1, r0, r3
	movs r3, 0
	ldrsh r1, [r1, r3]
	muls r2, r1
	ldr r3, _0801CB58
	adds r1, r0, r3
	movs r3, 0
	ldrsh r1, [r1, r3]
	adds r2, r1
	adds r0, 0x4
	adds r0, r2
	ldrb r0, [r0]
	bx lr
	.align 2, 0
_0801CB50: .4byte gUnknown_203B244
_0801CB54: .4byte 0x000004d2
_0801CB58: .4byte 0x000004cc
	thumb_func_end sub_801CB24

	thumb_func_start sub_801CB5C
sub_801CB5C:
	push {r4,r5,lr}
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	bl ResetUnusedInputStruct
	ldr r5, _0801CBAC
	ldr r0, [r5]
	movs r1, 0x9E
	lsls r1, 3
	adds r0, r1
	movs r1, 0
	movs r2, 0
	bl sub_800641C
	bl sub_801CE58
	adds r2, r0, 0
	ldr r0, [r5]
	ldr r3, _0801CBB0
	adds r1, r0, r3
	strh r2, [r1]
	ldr r1, _0801CBB4
	adds r0, r1
	bl sub_8013984
	bl sub_801CC38
	bl sub_801CCD8
	cmp r4, 0
	beq _0801CBA6
	ldr r0, [r5]
	ldr r3, _0801CBB4
	adds r0, r3
	bl AddMenuCursorSprite
_0801CBA6:
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_0801CBAC: .4byte gUnknown_203B244
_0801CBB0: .4byte 0x000004d6
_0801CBB4: .4byte 0x000004b4
	thumb_func_end sub_801CB5C

	thumb_func_start sub_801CBB8
sub_801CBB8:
	push {r4-r6,lr}
	ldr r5, _0801CC1C
	ldr r2, [r5]
	cmp r2, 0
	beq _0801CC16
	ldr r1, _0801CC20
	ldr r0, [r2]
	str r0, [r1]
	ldr r1, _0801CC24
	ldr r3, _0801CC28
	adds r0, r2, r3
	ldrh r0, [r0]
	strh r0, [r1]
	ldr r1, _0801CC2C
	ldr r6, _0801CC30
	adds r0, r2, r6
	ldrh r0, [r0]
	strh r0, [r1]
	movs r1, 0x9D
	lsls r1, 3
	adds r0, r2, r1
	ldr r0, [r0]
	lsls r1, r0, 1
	adds r1, r0
	lsls r1, 3
	adds r1, r2, r1
	movs r4, 0x9E
	lsls r4, 3
	adds r1, r4
	ldr r0, _0801CC34
	ldm r0!, {r2,r3,r6}
	stm r1!, {r2,r3,r6}
	ldm r0!, {r2,r3,r6}
	stm r1!, {r2,r3,r6}
	bl ResetUnusedInputStruct
	ldr r0, [r5]
	adds r0, r4
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	ldr r0, [r5]
	bl MemoryFree
	movs r0, 0
	str r0, [r5]
_0801CC16:
	pop {r4-r6}
	pop {r0}
	bx r0
	.align 2, 0
_0801CC1C: .4byte gUnknown_203B244
_0801CC20: .4byte gUnknown_203B248
_0801CC24: .4byte gUnknown_203B24C
_0801CC28: .4byte 0x000004cc
_0801CC2C: .4byte gUnknown_203B24E
_0801CC30: .4byte 0x000004d2
_0801CC34: .4byte gUnknown_80DBE3C
	thumb_func_end sub_801CBB8

	thumb_func_start sub_801CC38
sub_801CC38:
	push {r4,r5,lr}
	ldr r4, _0801CCC4
	ldr r0, [r4]
	movs r1, 0xAA
	lsls r1, 3
	adds r0, r1
	movs r2, 0
	movs r1, 0x1
	strb r1, [r0]
	ldr r0, [r4]
	ldr r1, _0801CCC8
	adds r0, r1
	strb r2, [r0]
	ldr r0, [r4]
	adds r1, 0x1
	adds r0, r1
	movs r1, 0xC
	strb r1, [r0]
	ldr r0, [r4]
	ldr r1, _0801CCCC
	adds r0, r1
	strb r2, [r0]
	ldr r0, [r4]
	ldr r2, _0801CCD0
	adds r0, r2
	movs r1, 0
	ldrsh r0, [r0, r1]
	movs r1, 0xC
	bl sub_80095E4
	adds r0, 0x2
	lsls r0, 16
	ldr r3, [r4]
	movs r2, 0x9D
	lsls r2, 3
	adds r5, r3, r2
	ldr r2, [r5]
	lsls r1, r2, 1
	adds r1, r2
	lsls r1, 3
	adds r1, r3, r1
	ldr r2, _0801CCD4
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
	movs r0, 0xA0
	lsls r0, 3
	adds r3, r0
	strh r2, [r3]
	bl ResetUnusedInputStruct
	ldr r0, [r4]
	movs r1, 0x9E
	lsls r1, 3
	adds r0, r1
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_0801CCC4: .4byte gUnknown_203B244
_0801CCC8: .4byte 0x00000551
_0801CCCC: .4byte 0x00000553
_0801CCD0: .4byte 0x000004ce
_0801CCD4: .4byte 0x000004fe
	thumb_func_end sub_801CC38

	thumb_func_start sub_801CCD8
sub_801CCD8:
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	sub sp, 0x58
	ldr r4, _0801CE38
	ldr r0, [r4]
	movs r5, 0x9D
	lsls r5, 3
	adds r0, r5
	ldr r0, [r0]
	bl sub_8008C54
	ldr r0, [r4]
	adds r0, r5
	ldr r0, [r0]
	bl sub_80073B8
	ldr r2, _0801CE3C
	ldr r0, [r4]
	adds r0, r5
	ldr r3, [r0]
	movs r0, 0
	str r0, [sp]
	movs r0, 0xA
	movs r1, 0
	bl xxx_call_draw_string
	ldr r3, [r4]
	ldr r1, _0801CE40
	adds r0, r3, r1
	ldrb r0, [r0]
	lsls r0, 3
	adds r0, 0x4
	ldr r2, _0801CE44
	adds r1, r3, r2
	movs r6, 0
	ldrsh r2, [r1, r6]
	adds r2, 0x1
	movs r1, 0x7
	str r1, [sp]
	adds r3, r5
	ldr r1, [r3]
	str r1, [sp, 0x4]
	movs r1, 0
	movs r3, 0x2
	bl sub_8012BC4
	movs r7, 0
	ldr r0, [r4]
	ldr r1, _0801CE48
	adds r0, r1
	movs r2, 0
	ldrsh r0, [r0, r2]
	cmp r7, r0
	bge _0801CE1A
	adds r6, r4, 0
	ldr r3, _0801CE4C
	mov r9, r3
	mov r8, r5
_0801CD50:
	ldr r1, [r6]
	ldr r4, _0801CE44
	adds r0, r1, r4
	movs r3, 0
	ldrsh r2, [r0, r3]
	subs r4, 0x2
	adds r0, r1, r4
	movs r3, 0
	ldrsh r0, [r0, r3]
	muls r0, r2
	adds r0, r7
	adds r1, 0x4
	adds r1, r0
	ldrb r5, [r1]
	add r0, sp, 0x8
	adds r1, r5, 0
	movs r2, 0
	bl sub_8090DC4
	ldr r0, [r6]
	add r0, r9
	adds r1, r7, 0
	bl sub_8013800
	adds r1, r0, 0
	ldr r0, [r6]
	add r0, r8
	ldr r3, [r0]
	movs r0, 0
	str r0, [sp]
	movs r0, 0x8
	add r2, sp, 0x8
	bl xxx_call_draw_string
	ldr r0, [r6]
	add r0, r9
	adds r1, r7, 0
	bl sub_8013800
	adds r1, r0, 0
	ldr r4, [r6]
	ldr r2, _0801CE50
	adds r0, r4, r2
	ldr r0, [r0]
	movs r3, 0xC
	ldrsh r0, [r0, r3]
	lsls r0, 3
	subs r0, 0x2
	ldr r2, _0801CE54
	ldr r2, [r2]
	lsls r3, r5, 1
	adds r2, 0x50
	adds r2, r3
	ldrh r2, [r2]
	movs r3, 0x5
	str r3, [sp]
	add r4, r8
	ldr r3, [r4]
	str r3, [sp, 0x4]
	movs r3, 0x3
	bl sub_8012BC4
	adds r0, r5, 0
	bl sub_801CFE0
	movs r1, 0x1
	ands r1, r0
	cmp r1, 0
	beq _0801CE0A
	ldr r0, [r6]
	ldr r4, _0801CE4C
	adds r0, r4
	adds r1, r7, 0
	bl sub_8013800
	adds r2, r0, 0
	ldr r1, [r6]
	movs r3, 0x9D
	lsls r3, 3
	adds r0, r1, r3
	ldr r0, [r0]
	adds r4, 0x38
	adds r1, r4
	ldr r1, [r1]
	movs r4, 0xC
	ldrsh r3, [r1, r4]
	subs r3, 0x1
	lsls r3, 3
	movs r1, 0xA
	str r1, [sp]
	movs r1, 0x8
	bl sub_8007B7C
_0801CE0A:
	adds r7, 0x1
	ldr r0, [r6]
	ldr r1, _0801CE48
	adds r0, r1
	movs r2, 0
	ldrsh r0, [r0, r2]
	cmp r7, r0
	blt _0801CD50
_0801CE1A:
	ldr r0, _0801CE38
	ldr r0, [r0]
	movs r3, 0x9D
	lsls r3, 3
	adds r0, r3
	ldr r0, [r0]
	bl sub_80073E0
	add sp, 0x58
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_0801CE38: .4byte gUnknown_203B244
_0801CE3C: .4byte gUnknown_80DBE6C
_0801CE40: .4byte 0x00000552
_0801CE44: .4byte 0x000004d2
_0801CE48: .4byte 0x000004ce
_0801CE4C: .4byte 0x000004b4
_0801CE50: .4byte 0x000004ec
_0801CE54: .4byte gTeamInventory_203B460
	thumb_func_end sub_801CCD8

	thumb_func_start sub_801CE58
sub_801CE58:
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	sub sp, 0x4
	movs r3, 0
	movs r6, 0x1
	ldr r4, _0801CF0C
_0801CE68:
	ldr r0, [r4]
	ldr r0, [r0]
	cmp r0, 0x2
	beq _0801CE92
	ldr r0, _0801CF10
	ldr r0, [r0]
	lsls r1, r6, 1
	adds r0, 0x50
	adds r0, r1
	ldrh r0, [r0]
	cmp r0, 0
	beq _0801CE9C
	lsls r0, r6, 24
	lsrs r0, 24
	str r3, [sp]
	bl IsNotMoneyOrUsedTMItem
	lsls r0, 24
	ldr r3, [sp]
	cmp r0, 0
	beq _0801CE9C
_0801CE92:
	ldr r0, [r4]
	adds r0, 0x4
	adds r0, r3
	strb r6, [r0]
	adds r3, 0x1
_0801CE9C:
	adds r6, 0x1
	cmp r6, 0xEF
	ble _0801CE68
	movs r6, 0
	subs r0, r3, 0x1
	mov r9, r0
	cmp r6, r9
	bge _0801CEFC
_0801CEAC:
	adds r0, r6, 0x1
	mov r8, r0
	mov r5, r8
	cmp r8, r3
	bge _0801CEF6
	ldr r7, _0801CF0C
_0801CEB8:
	ldr r0, [r7]
	adds r0, 0x4
	adds r0, r6
	ldrb r0, [r0]
	str r3, [sp]
	bl GetItemOrder
	adds r4, r0, 0
	ldr r0, [r7]
	adds r0, 0x4
	adds r0, r5
	ldrb r0, [r0]
	bl GetItemOrder
	ldr r3, [sp]
	cmp r4, r0
	ble _0801CEF0
	ldr r0, [r7]
	adds r0, 0x4
	adds r1, r0, r6
	ldrb r2, [r1]
	adds r0, r5
	ldrb r0, [r0]
	strb r0, [r1]
	ldr r0, [r7]
	adds r0, 0x4
	adds r0, r5
	strb r2, [r0]
_0801CEF0:
	adds r5, 0x1
	cmp r5, r3
	blt _0801CEB8
_0801CEF6:
	mov r6, r8
	cmp r6, r9
	blt _0801CEAC
_0801CEFC:
	adds r0, r3, 0
	add sp, 0x4
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r1}
	bx r1
	.align 2, 0
_0801CF0C: .4byte gUnknown_203B244
_0801CF10: .4byte gTeamInventory_203B460
	thumb_func_end sub_801CE58

	thumb_func_start sub_801CF14
sub_801CF14:
	push {r4,lr}
	cmp r0, 0x2
	bne _0801CF1E
_0801CF1A:
	movs r0, 0
	b _0801CF46
_0801CF1E:
	movs r4, 0x1
_0801CF20:
	ldr r0, _0801CF4C
	ldr r0, [r0]
	lsls r1, r4, 1
	adds r0, 0x50
	adds r0, r1
	ldrh r0, [r0]
	cmp r0, 0
	beq _0801CF3E
	lsls r0, r4, 24
	lsrs r0, 24
	bl IsNotMoneyOrUsedTMItem
	lsls r0, 24
	cmp r0, 0
	bne _0801CF1A
_0801CF3E:
	adds r4, 0x1
	cmp r4, 0xEF
	ble _0801CF20
	movs r0, 0x1
_0801CF46:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_0801CF4C: .4byte gTeamInventory_203B460
	thumb_func_end sub_801CF14

	thumb_func_start sub_801CF50
sub_801CF50:
	push {r4,r5,lr}
	cmp r0, 0x2
	bne _0801CF5A
_0801CF56:
	movs r0, 0
	b _0801CF84
_0801CF5A:
	movs r4, 0x1
	ldr r5, _0801CF8C
_0801CF5E:
	lsls r0, r4, 24
	lsrs r0, 24
	bl IsNotMoneyOrUsedTMItem
	lsls r0, 24
	cmp r0, 0
	beq _0801CF7C
	ldr r0, _0801CF90
	ldr r0, [r0]
	lsls r1, r4, 1
	adds r0, 0x50
	adds r0, r1
	ldrh r0, [r0]
	cmp r0, r5
	bls _0801CF56
_0801CF7C:
	adds r4, 0x1
	cmp r4, 0xEF
	ble _0801CF5E
	movs r0, 0x1
_0801CF84:
	pop {r4,r5}
	pop {r1}
	bx r1
	.align 2, 0
_0801CF8C: .4byte 0x000003e6
_0801CF90: .4byte gTeamInventory_203B460
	thumb_func_end sub_801CF50

	thumb_func_start sub_801CF94
sub_801CF94:
	push {r4,lr}
	movs r2, 0
	ldr r4, _0801CFB4
	movs r3, 0
_0801CF9C:
	ldr r0, [r4]
	lsls r1, r2, 2
	adds r0, 0xF4
	adds r0, r1
	str r3, [r0]
	adds r2, 0x1
	cmp r2, 0xEF
	ble _0801CF9C
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0801CFB4: .4byte gUnknown_203B244
	thumb_func_end sub_801CF94

	thumb_func_start sub_801CFB8
sub_801CFB8:
	push {lr}
	movs r3, 0
	ldr r0, _0801CFDC
	ldr r0, [r0]
	adds r1, r0, 0
	adds r1, 0xF4
	movs r2, 0xEF
_0801CFC6:
	ldr r0, [r1]
	cmp r0, 0
	beq _0801CFCE
	adds r3, 0x1
_0801CFCE:
	adds r1, 0x4
	subs r2, 0x1
	cmp r2, 0
	bge _0801CFC6
	adds r0, r3, 0
	pop {r1}
	bx r1
	.align 2, 0
_0801CFDC: .4byte gUnknown_203B244
	thumb_func_end sub_801CFB8

	thumb_func_start sub_801CFE0
sub_801CFE0:
	lsls r0, 24
	ldr r1, _0801CFF0
	ldr r1, [r1]
	lsrs r0, 22
	adds r1, 0xF4
	adds r1, r0
	ldr r0, [r1]
	bx lr
	.align 2, 0
_0801CFF0: .4byte gUnknown_203B244
	thumb_func_end sub_801CFE0

	thumb_func_start sub_801CFF4
sub_801CFF4:
	lsls r0, 24
	ldr r2, _0801D004
	ldr r2, [r2]
	lsrs r0, 22
	adds r2, 0xF4
	adds r2, r0
	str r1, [r2]
	bx lr
	.align 2, 0
_0801D004: .4byte gUnknown_203B244
	thumb_func_end sub_801CFF4

	thumb_func_start sub_801D008
sub_801D008:
	ldr r0, _0801D010
	ldr r0, [r0]
	bx lr
	.align 2, 0
_0801D010: .4byte gUnknown_203B244
	thumb_func_end sub_801D008

	thumb_func_start sub_801D014
sub_801D014:
	push {r4,r5,lr}
	adds r5, r0, 0
	bl ResetUnusedInputStruct
	movs r0, 0
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	ldr r4, _0801D054
	movs r0, 0x8C
	lsls r0, 1
	movs r1, 0x8
	bl MemoryAlloc
	adds r2, r0, 0
	str r2, [r4]
	ldr r0, _0801D058
	ldr r0, [r0]
	str r0, [r2, 0x14]
	str r5, [r2]
	cmp r5, 0
	beq _0801D088
	movs r3, 0
	ldr r0, _0801D05C
	ldr r1, [r0]
	adds r4, r0, 0
	cmp r5, r1
	bne _0801D060
	strh r3, [r2, 0x4]
	b _0801D08C
	.align 2, 0
_0801D054: .4byte gUnknown_203B250
_0801D058: .4byte gUnknown_203B254
_0801D05C: .4byte gRecruitedPokemonRef
_0801D060:
	adds r3, 0x1
	movs r0, 0xCE
	lsls r0, 1
	cmp r3, r0
	bgt _0801D08C
	ldr r0, _0801D084
	ldr r2, [r0]
	lsls r0, r3, 16
	asrs r0, 16
	movs r1, 0x58
	muls r1, r0
	ldr r0, [r4]
	adds r0, r1
	ldr r1, [r2]
	cmp r1, r0
	bne _0801D060
	strh r3, [r2, 0x4]
	b _0801D08C
	.align 2, 0
_0801D084: .4byte gUnknown_203B250
_0801D088:
	ldr r0, _0801D0C4
	strh r0, [r2, 0x4]
_0801D08C:
	bl sub_80A5728
	lsls r0, 16
	asrs r0, 16
	bl sub_8002658
	ldr r4, _0801D0C8
	ldr r1, [r4]
	movs r5, 0
	strb r0, [r1, 0x6]
	ldr r0, [r4]
	strb r5, [r0, 0x8]
	ldr r0, [r4]
	strb r5, [r0, 0x9]
	bl GetPlayerPokemonStruct
	ldr r1, [r4]
	str r0, [r1, 0xC]
	strb r5, [r1, 0x7]
	ldr r0, [r4]
	ldr r0, [r0]
	cmp r0, 0
	beq _0801D0CC
	movs r0, 0x5
	bl sub_801D208
	b _0801D0D2
	.align 2, 0
_0801D0C4: .4byte 0x0000019d
_0801D0C8: .4byte gUnknown_203B250
_0801D0CC:
	movs r0, 0
	bl sub_801D208
_0801D0D2:
	movs r0, 0x1
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_801D014

	thumb_func_start sub_801D0DC
sub_801D0DC:
	push {lr}
	ldr r0, _0801D0F4
	ldr r0, [r0]
	ldr r0, [r0, 0x10]
	cmp r0, 0xC
	bhi _0801D16C
	lsls r0, 2
	ldr r1, _0801D0F8
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0801D0F4: .4byte gUnknown_203B250
_0801D0F8: .4byte _0801D0FC
	.align 2, 0
_0801D0FC:
	.4byte _0801D130
	.4byte _0801D130
	.4byte _0801D16C
	.4byte _0801D136
	.4byte _0801D13C
	.4byte _0801D142
	.4byte _0801D148
	.4byte _0801D148
	.4byte _0801D14E
	.4byte _0801D154
	.4byte _0801D15A
	.4byte _0801D160
	.4byte _0801D166
_0801D130:
	bl sub_801D680
	b _0801D170
_0801D136:
	bl sub_801D760
	b _0801D170
_0801D13C:
	bl sub_801D77C
	b _0801D170
_0801D142:
	bl sub_801D798
	b _0801D170
_0801D148:
	bl sub_801D7CC
	b _0801D170
_0801D14E:
	bl sub_801D808
	b _0801D170
_0801D154:
	bl sub_801D824
	b _0801D170
_0801D15A:
	bl sub_801D840
	b _0801D170
_0801D160:
	bl sub_801D85C
	b _0801D170
_0801D166:
	bl sub_801D878
	b _0801D170
_0801D16C:
	movs r0, 0x3
	b _0801D172
_0801D170:
	movs r0, 0
_0801D172:
	pop {r1}
	bx r1
	thumb_func_end sub_801D0DC

	thumb_func_start sub_801D178
sub_801D178:
	push {r4,lr}
	ldr r0, _0801D188
	ldr r4, [r0]
	ldrb r0, [r4, 0x9]
	cmp r0, 0
	beq _0801D18C
	movs r0, 0x2
	b _0801D1CC
	.align 2, 0
_0801D188: .4byte gUnknown_203B250
_0801D18C:
	ldrb r0, [r4, 0x7]
	cmp r0, 0
	beq _0801D196
	movs r0, 0x3
	b _0801D1CC
_0801D196:
	ldrb r0, [r4, 0x8]
	cmp r0, 0
	beq _0801D1A0
	movs r0, 0x1
	b _0801D1CC
_0801D1A0:
	bl GetPlayerPokemonStruct
	ldr r1, [r4, 0xC]
	cmp r1, r0
	bne _0801D1C6
	movs r0, 0x7
	bl sub_80A7AE8
	lsls r0, 16
	cmp r0, 0
	blt _0801D1CA
	bl sub_808D3F8
	ldrh r0, [r0]
	lsrs r0, 1
	movs r1, 0x1
	ands r0, r1
	cmp r0, 0
	bne _0801D1CA
_0801D1C6:
	movs r0, 0x4
	b _0801D1CC
_0801D1CA:
	movs r0, 0
_0801D1CC:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_801D178

	thumb_func_start sub_801D1D4
sub_801D1D4:
	ldr r0, _0801D1DC
	ldr r0, [r0]
	ldrb r0, [r0, 0x7]
	bx lr
	.align 2, 0
_0801D1DC: .4byte gUnknown_203B250
	thumb_func_end sub_801D1D4

	thumb_func_start sub_801D1E0
sub_801D1E0:
	push {r4,lr}
	ldr r4, _0801D200
	ldr r2, [r4]
	cmp r2, 0
	beq _0801D1FA
	ldr r0, _0801D204
	ldr r1, [r2, 0x14]
	str r1, [r0]
	adds r0, r2, 0
	bl MemoryFree
	movs r0, 0
	str r0, [r4]
_0801D1FA:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0801D200: .4byte gUnknown_203B250
_0801D204: .4byte gUnknown_203B254
	thumb_func_end sub_801D1E0

	thumb_func_start sub_801D208
sub_801D208:
	push {lr}
	ldr r1, _0801D21C
	ldr r1, [r1]
	str r0, [r1, 0x10]
	bl sub_801D220
	bl sub_801D3A8
	pop {r0}
	bx r0
	.align 2, 0
_0801D21C: .4byte gUnknown_203B250
	thumb_func_end sub_801D208

	thumb_func_start sub_801D220
sub_801D220:
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	ldr r4, _0801D248
	ldr r0, [r4]
	adds r0, 0xB8
	bl sub_8006518
	ldr r0, [r4]
	ldr r0, [r0, 0x10]
	cmp r0, 0
	beq _0801D250
	cmp r0, 0x1
	beq _0801D2C0
	movs r2, 0
	adds r7, r4, 0
	ldr r3, _0801D24C
	b _0801D368
	.align 2, 0
_0801D248: .4byte gUnknown_203B250
_0801D24C: .4byte gUnknown_80DBE7C
_0801D250:
	bl sub_801D4C0
	ldr r0, [r4]
	ldr r0, [r0]
	cmp r0, 0
	beq _0801D290
	adds r7, r4, 0
	ldr r0, _0801D288
	mov r9, r0
	mov r12, r7
	ldr r2, _0801D28C
	mov r8, r2
	movs r3, 0
	movs r2, 0x3
_0801D26C:
	mov r4, r12
	ldr r1, [r4]
	adds r1, r3
	adds r1, 0xB8
	mov r0, r8
	ldm r0!, {r4-r6}
	stm r1!, {r4-r6}
	ldm r0!, {r4-r6}
	stm r1!, {r4-r6}
	adds r3, 0x18
	subs r2, 0x1
	cmp r2, 0
	bge _0801D26C
	b _0801D2F6
	.align 2, 0
_0801D288: .4byte gUnknown_80DBE98
_0801D28C: .4byte gUnknown_80DBE7C
_0801D290:
	adds r7, r4, 0
	mov r8, r7
	ldr r6, _0801D2BC
	mov r9, r6
	movs r3, 0
	movs r2, 0x3
_0801D29C:
	mov r0, r8
	ldr r1, [r0]
	adds r1, r3
	adds r1, 0xB8
	mov r0, r9
	ldm r0!, {r4-r6}
	stm r1!, {r4-r6}
	ldm r0!, {r4-r6}
	stm r1!, {r4-r6}
	movs r0, 0x18
	add r9, r0
	adds r3, 0x18
	subs r2, 0x1
	cmp r2, 0
	bge _0801D29C
	b _0801D34E
	.align 2, 0
_0801D2BC: .4byte gUnknown_80DBEB0
_0801D2C0:
	bl sub_801D4C0
	ldr r0, [r4]
	ldr r0, [r0]
	cmp r0, 0
	beq _0801D324
	adds r7, r4, 0
	ldr r2, _0801D31C
	mov r9, r2
	mov r8, r7
	ldr r3, _0801D320
	mov r12, r3
	movs r3, 0
	movs r2, 0x3
_0801D2DC:
	mov r4, r8
	ldr r1, [r4]
	adds r1, r3
	adds r1, 0xB8
	mov r0, r12
	ldm r0!, {r4-r6}
	stm r1!, {r4-r6}
	ldm r0!, {r4-r6}
	stm r1!, {r4-r6}
	adds r3, 0x18
	subs r2, 0x1
	cmp r2, 0
	bge _0801D2DC
_0801D2F6:
	ldr r1, [r7]
	adds r1, 0xB8
	mov r0, r9
	ldm r0!, {r2,r5,r6}
	stm r1!, {r2,r5,r6}
	ldm r0!, {r3-r5}
	stm r1!, {r3-r5}
	ldr r1, [r7]
	adds r0, r1, 0
	adds r0, 0xB8
	adds r1, 0x68
	bl sub_8012CAC
	ldr r0, [r7]
	adds r0, 0xC4
	movs r1, 0x9
	strh r1, [r0]
	b _0801D384
	.align 2, 0
_0801D31C: .4byte gUnknown_80DBE98
_0801D320: .4byte gUnknown_80DBE7C
_0801D324:
	adds r7, r4, 0
	mov r8, r7
	ldr r6, _0801D364
	mov r9, r6
	movs r3, 0
	movs r2, 0x3
_0801D330:
	mov r0, r8
	ldr r1, [r0]
	adds r1, r3
	adds r1, 0xB8
	mov r0, r9
	ldm r0!, {r4-r6}
	stm r1!, {r4-r6}
	ldm r0!, {r4-r6}
	stm r1!, {r4-r6}
	movs r0, 0x18
	add r9, r0
	adds r3, 0x18
	subs r2, 0x1
	cmp r2, 0
	bge _0801D330
_0801D34E:
	ldr r1, [r7]
	adds r0, r1, 0
	adds r0, 0xB8
	adds r1, 0x68
	bl sub_8012CAC
	ldr r0, [r7]
	adds r0, 0xC4
	movs r1, 0x8
	strh r1, [r0]
	b _0801D384
	.align 2, 0
_0801D364: .4byte gUnknown_80DBEB0
_0801D368:
	ldr r0, [r7]
	lsls r1, r2, 1
	adds r1, r2
	lsls r1, 3
	adds r0, r1
	adds r0, 0xB8
	adds r1, r3, 0
	ldm r1!, {r4-r6}
	stm r0!, {r4-r6}
	ldm r1!, {r4-r6}
	stm r0!, {r4-r6}
	adds r2, 0x1
	cmp r2, 0x3
	ble _0801D368
_0801D384:
	bl ResetUnusedInputStruct
	ldr r0, _0801D3A4
	ldr r0, [r0]
	adds r0, 0xB8
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_0801D3A4: .4byte gUnknown_203B250
	thumb_func_end sub_801D220

	thumb_func_start sub_801D3A8
sub_801D3A8:
	push {r4-r6,lr}
	sub sp, 0x8
	ldr r1, _0801D3C4
	ldr r0, [r1]
	ldr r0, [r0, 0x10]
	adds r6, r1, 0
	cmp r0, 0xC
	bls _0801D3BA
	b _0801D4B6
_0801D3BA:
	lsls r0, 2
	ldr r1, _0801D3C8
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0801D3C4: .4byte gUnknown_203B250
_0801D3C8: .4byte _0801D3CC
	.align 2, 0
_0801D3CC:
	.4byte _0801D400
	.4byte _0801D400
	.4byte _0801D4B6
	.4byte _0801D458
	.4byte _0801D462
	.4byte _0801D468
	.4byte _0801D472
	.4byte _0801D47A
	.4byte _0801D482
	.4byte _0801D490
	.4byte _0801D49C
	.4byte _0801D4AA
	.4byte _0801D4B2
_0801D400:
	ldr r0, [r6]
	ldr r5, [r0]
	cmp r5, 0
	beq _0801D438
	ldr r4, _0801D434
	adds r0, r4, 0
	adds r1, r5, 0
	movs r2, 0x7
	bl PrintColoredPokeNameToBuffer
	ldr r2, [r6]
	str r4, [r2, 0x18]
	adds r0, r2, 0
	adds r0, 0x18
	adds r1, r2, 0
	adds r1, 0x68
	adds r3, r2, 0
	adds r3, 0xA8
	ldr r2, [r2, 0x14]
	str r2, [sp]
	movs r2, 0
	str r2, [sp, 0x4]
	bl sub_8012D60
	b _0801D4B6
	.align 2, 0
_0801D434: .4byte gAvailablePokemonNames
_0801D438:
	bl sub_801D894
	ldr r2, [r6]
	adds r0, r2, 0
	adds r0, 0x18
	adds r1, r2, 0
	adds r1, 0x68
	adds r3, r2, 0
	adds r3, 0xA8
	ldr r2, [r2, 0x14]
	str r2, [sp]
	str r5, [sp, 0x4]
	movs r2, 0
	bl sub_8012D60
	b _0801D4B6
_0801D458:
	ldr r0, [r6]
	ldr r0, [r0]
	bl sub_80227B8
	b _0801D4B6
_0801D462:
	bl sub_8027074
	b _0801D4B6
_0801D468:
	ldr r0, [r6]
	ldr r0, [r0]
	bl sub_8025EF4
	b _0801D4B6
_0801D472:
	movs r0, 0
	bl sub_80252F0
	b _0801D4B6
_0801D47A:
	movs r0, 0x1
	bl sub_80252F0
	b _0801D4B6
_0801D482:
	ldr r0, [r6]
	movs r1, 0x4
	ldrsh r0, [r0, r1]
	movs r1, 0x2
	bl sub_8024458
	b _0801D4B6
_0801D490:
	ldr r0, [r6]
	movs r1, 0x4
	ldrsh r0, [r0, r1]
	bl sub_801BEEC
	b _0801D4B6
_0801D49C:
	ldr r0, [r6]
	ldrb r0, [r0, 0x6]
	movs r1, 0x1
	movs r2, 0x2
	bl sub_8021774
	b _0801D4B6
_0801D4AA:
	movs r0, 0
	bl InitializeJobListMenu
	b _0801D4B6
_0801D4B2:
	bl sub_801DCC4
_0801D4B6:
	add sp, 0x8
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end sub_801D3A8

	thumb_func_start sub_801D4C0
sub_801D4C0:
	push {r4-r7,lr}
	movs r6, 0
	ldr r4, _0801D554
	ldr r0, [r4]
	adds r0, 0xA8
	movs r1, 0
	movs r2, 0x10
	bl MemoryFill16
	ldr r0, [r4]
	ldrb r0, [r0, 0x6]
	cmp r0, 0
	bne _0801D568
	bl sub_8096E2C
	lsls r0, 24
	cmp r0, 0
	beq _0801D534
	ldr r1, [r4]
	movs r0, 0x2
	str r0, [r1, 0x6C]
	ldr r0, _0801D558
	str r0, [r1, 0x68]
	bl GetNumberOfFilledInventorySlots
	cmp r0, 0
	bne _0801D4FE
	ldr r0, [r4]
	adds r0, 0xA8
	movs r1, 0x1
	strh r1, [r0]
_0801D4FE:
	ldr r1, [r4]
	ldr r0, _0801D55C
	str r0, [r1, 0x70]
	movs r0, 0x4
	str r0, [r1, 0x74]
	movs r6, 0x2
	movs r0, 0x2
	bl sub_80023E4
	lsls r0, 24
	cmp r0, 0
	beq _0801D534
	ldr r1, [r4]
	ldr r0, _0801D560
	str r0, [r1, 0x78]
	movs r0, 0x9
	str r0, [r1, 0x7C]
	bl HasNoAcceptedJobs
	lsls r0, 24
	cmp r0, 0
	beq _0801D532
	ldr r0, [r4]
	adds r0, 0xAC
	movs r1, 0x1
	strh r1, [r0]
_0801D532:
	movs r6, 0x3
_0801D534:
	ldr r4, _0801D554
	ldr r2, [r4]
	lsls r3, r6, 3
	adds r0, r2, 0
	adds r0, 0x68
	adds r0, r3
	ldr r1, _0801D564
	str r1, [r0]
	adds r2, 0x6C
	adds r2, r3
	movs r0, 0xB
	str r0, [r2]
	adds r6, 0x1
	adds r7, r4, 0
	b _0801D5E6
	.align 2, 0
_0801D554: .4byte gUnknown_203B250
_0801D558: .4byte gMenuItems
_0801D55C: .4byte gMenuTeam
_0801D560: .4byte gMenuJobList
_0801D564: .4byte gMenuOthers
_0801D568:
	ldr r0, _0801D63C
	ldr r1, _0801D640
	bl strcpy
	bl sub_8096E2C
	lsls r0, 24
	cmp r0, 0
	beq _0801D5B6
	ldr r1, [r4]
	ldr r0, _0801D644
	ldr r0, [r0]
	str r0, [r1, 0x68]
	movs r0, 0x5
	str r0, [r1, 0x6C]
	movs r0, 0x4
	bl sub_8024108
	lsls r0, 24
	cmp r0, 0
	beq _0801D59A
	ldr r0, [r4]
	adds r0, 0xA8
	movs r1, 0x1
	strh r1, [r0]
_0801D59A:
	movs r6, 0x1
	ldr r1, [r4]
	movs r0, 0x2
	str r0, [r1, 0x74]
	ldr r0, _0801D648
	str r0, [r1, 0x70]
	bl GetNumberOfFilledInventorySlots
	cmp r0, 0
	bne _0801D5B4
	ldr r0, [r4]
	adds r0, 0xAA
	strh r6, [r0]
_0801D5B4:
	movs r6, 0x2
_0801D5B6:
	ldr r5, _0801D64C
	ldr r1, [r5]
	lsls r2, r6, 3
	adds r3, r1, 0
	adds r3, 0x68
	adds r4, r3, r2
	ldr r0, _0801D650
	ldr r0, [r0]
	str r0, [r4]
	adds r1, 0x6C
	adds r2, r1, r2
	movs r0, 0x8
	str r0, [r2]
	adds r6, 0x1
	lsls r2, r6, 3
	adds r3, r2
	ldr r0, _0801D654
	ldr r0, [r0]
	str r0, [r3]
	adds r1, r2
	movs r0, 0xA
	str r0, [r1]
	adds r6, 0x1
	adds r7, r5, 0
_0801D5E6:
	ldr r4, [r7]
	lsls r2, r6, 3
	adds r0, r4, 0
	adds r0, 0x68
	adds r0, r2
	movs r1, 0
	str r1, [r0]
	adds r1, r4, 0
	adds r1, 0x6C
	adds r2, r1, r2
	movs r0, 0x1
	str r0, [r2]
	movs r3, 0
	cmp r3, r6
	bge _0801D622
	adds r5, r4, 0
	adds r4, 0xA8
	adds r2, r1, 0
_0801D60A:
	ldrh r0, [r4]
	cmp r0, 0
	bne _0801D618
	ldr r1, [r2]
	ldr r0, [r5, 0x14]
	cmp r1, r0
	beq _0801D67A
_0801D618:
	adds r4, 0x2
	adds r2, 0x8
	adds r3, 0x1
	cmp r3, r6
	blt _0801D60A
_0801D622:
	movs r3, 0
	cmp r3, r6
	bge _0801D67A
	ldr r1, [r7]
	adds r0, r1, 0
	adds r0, 0xA8
	ldrh r0, [r0]
	cmp r0, 0
	bne _0801D658
	ldr r0, [r1, 0x6C]
	str r0, [r1, 0x14]
	b _0801D67A
	.align 2, 0
_0801D63C: .4byte gAvailablePokemonNames
_0801D640: .4byte gUnknown_80DBF34
_0801D644: .4byte gUnknown_80D49A8
_0801D648: .4byte gMenuItems
_0801D64C: .4byte gUnknown_203B250
_0801D650: .4byte gUnknown_80D4970
_0801D654: .4byte gUnknown_80D49B4
_0801D658:
	adds r3, 0x1
	cmp r3, r6
	bge _0801D67A
	ldr r2, [r7]
	lsls r0, r3, 1
	adds r1, r2, 0
	adds r1, 0xA8
	adds r1, r0
	ldrh r0, [r1]
	cmp r0, 0
	bne _0801D658
	lsls r0, r3, 3
	adds r1, r2, 0
	adds r1, 0x6C
	adds r1, r0
	ldr r0, [r1]
	str r0, [r2, 0x14]
_0801D67A:
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_801D4C0

        .align 2,0
