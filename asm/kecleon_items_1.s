	#include "asm/constants/gba_constants.inc"
	#include "asm/macros.inc"

	.syntax unified

	.text

	thumb_func_start sub_801A9E0
sub_801A9E0:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0xCC
	ldr r4, _0801AA2C
	ldr r0, [r4]
	adds r0, 0x88
	ldr r0, [r0]
	bl sub_8008C54
	ldr r0, [r4]
	adds r0, 0x88
	ldr r0, [r0]
	bl sub_80073B8
	ldr r4, [r4]
	adds r1, r4, 0
	adds r1, 0x72
	movs r2, 0
	ldrsh r0, [r1, r2]
	lsls r0, 3
	adds r5, r0, 0
	adds r5, 0xA
	movs r3, 0
	ldrsh r1, [r1, r3]
	cmp r1, 0
	bne _0801AA34
	ldr r2, _0801AA30
	adds r0, r4, 0
	adds r0, 0x88
	ldr r3, [r0]
	str r1, [sp]
	adds r0, r5, 0
	movs r1, 0
	bl xxx_call_draw_string
	b _0801AA48
	.align 2, 0
_0801AA2C: .4byte gUnknown_203B224
_0801AA30: .4byte gTeamToolboxA
_0801AA34:
	ldr r2, _0801AA58
	adds r0, r4, 0
	adds r0, 0x88
	ldr r3, [r0]
	movs r0, 0
	str r0, [sp]
	adds r0, r5, 0
	movs r1, 0
	bl xxx_call_draw_string
_0801AA48:
	movs r7, 0
	ldr r1, _0801AA5C
	ldr r0, [r1]
	adds r0, 0x6E
	movs r4, 0
	ldrsh r0, [r0, r4]
	b _0801AD0A
	.align 2, 0
_0801AA58: .4byte gTeamToolboxB
_0801AA5C: .4byte gUnknown_203B224
_0801AA60:
	ldr r2, [r1]
	adds r0, r2, 0
	adds r0, 0x72
	movs r3, 0
	ldrsh r1, [r0, r3]
	subs r0, 0x2
	movs r4, 0
	ldrsh r0, [r0, r4]
	muls r0, r1
	adds r0, r7
	mov r8, r0
	ldr r0, _0801AA9C
	ldr r0, [r0]
	mov r3, r8
	lsls r1, r3, 2
	adds r0, r1
	ldr r0, [r0]
	add r1, sp, 0xC8
	str r0, [r1]
	ldr r0, [r2]
	adds r4, r1, 0
	cmp r0, 0x5
	bls _0801AA90
	b _0801ACC4
_0801AA90:
	lsls r0, 2
	ldr r1, _0801AAA0
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0801AA9C: .4byte gTeamInventory_203B460
_0801AAA0: .4byte _0801AAA4
	.align 2, 0
_0801AAA4:
	.4byte _0801AABC
	.4byte _0801AAE4
	.4byte _0801AAE4
	.4byte _0801AB18
	.4byte _0801AB90
	.4byte _0801AC50
_0801AABC:
	add r0, sp, 0x4
	adds r1, r4, 0
	movs r2, 0
	bl sub_8090E14
	ldr r4, _0801AAE0
	ldr r0, [r4]
	adds r0, 0x54
	adds r1, r7, 0
	bl sub_8013800
	adds r1, r0, 0
	ldr r0, [r4]
	adds r0, 0x88
	ldr r3, [r0]
	movs r0, 0
	str r0, [sp]
	b _0801AC8C
	.align 2, 0
_0801AAE0: .4byte gUnknown_203B224
_0801AAE4:
	add r2, sp, 0x54
	movs r5, 0
	str r5, [sp, 0x54]
	strb r5, [r2, 0x4]
	movs r0, 0x1
	strb r0, [r2, 0x8]
	strb r0, [r4]
	add r1, sp, 0xC8
	add r0, sp, 0x4
	bl sub_8090E14
	ldr r4, _0801AB14
	ldr r0, [r4]
	adds r0, 0x54
	adds r1, r7, 0
	bl sub_8013800
	adds r1, r0, 0
	ldr r0, [r4]
	adds r0, 0x88
	ldr r3, [r0]
	str r5, [sp]
	b _0801AC8C
	.align 2, 0
_0801AB14: .4byte gUnknown_203B224
_0801AB18:
	add r2, sp, 0x60
	movs r6, 0
	str r6, [sp, 0x60]
	strb r6, [r2, 0x4]
	movs r0, 0x1
	strb r0, [r2, 0x8]
	strb r0, [r4]
	add r1, sp, 0xC8
	add r0, sp, 0x4
	bl sub_8090E14
	ldr r5, _0801AB60
	ldr r0, [r5]
	mov r4, r8
	lsls r1, r4, 2
	adds r0, 0x4
	adds r0, r1
	ldr r0, [r0]
	cmp r0, 0
	bne _0801AB4E
	mov r0, r8
	bl sub_801ADA0
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0
	beq _0801AB64
_0801AB4E:
	ldr r0, [r5]
	adds r0, 0x54
	adds r1, r7, 0
	bl sub_8013800
	adds r1, r0, 0
	ldr r0, [r5]
	b _0801AC86
	.align 2, 0
_0801AB60: .4byte gUnknown_203B224
_0801AB64:
	ldr r0, _0801AB88
	add r1, sp, 0x4
	movs r2, 0x50
	bl strncpy
	ldr r0, [r5]
	adds r0, 0x54
	adds r1, r7, 0
	bl sub_8013800
	adds r1, r0, 0
	ldr r2, _0801AB8C
	ldr r0, [r5]
	adds r0, 0x88
	ldr r3, [r0]
	str r4, [sp]
	b _0801AC3C
	.align 2, 0
_0801AB88: .4byte gUnknown_202DE58
_0801AB8C: .4byte gUnknown_80DB994
_0801AB90:
	ldrb r0, [r4, 0x2]
	bl CanSellItem
	lsls r0, 24
	lsrs r5, r0, 24
	cmp r5, 0
	beq _0801AC10
	add r2, sp, 0x6C
	movs r1, 0x3
	str r1, [sp, 0x6C]
	movs r6, 0
	strb r6, [r2, 0x4]
	movs r0, 0x58
	strh r0, [r2, 0x6]
	movs r0, 0x1
	strb r0, [r2, 0x8]
	strb r1, [r4]
	add r0, sp, 0x4
	adds r1, r4, 0
	bl sub_8090E14
	adds r0, r4, 0
	bl GetStackSellPrice
	ldr r1, _0801AC00
	ldr r1, [r1]
	movs r2, 0x98
	lsls r2, 2
	adds r1, r2
	ldr r1, [r1]
	adds r0, r1
	ldr r1, _0801AC04
	cmp r0, r1
	ble _0801AC76
	add r5, sp, 0x78
	ldr r1, _0801AC08
	adds r0, r5, 0
	add r2, sp, 0x4
	bl sprintf_2
	ldr r4, _0801AC0C
	ldr r0, [r4]
	adds r0, 0x54
	adds r1, r7, 0
	bl sub_8013800
	adds r1, r0, 0
	ldr r0, [r4]
	adds r0, 0x88
	ldr r3, [r0]
	str r6, [sp]
	movs r0, 0x8
	adds r2, r5, 0
	bl xxx_call_draw_string
	b _0801ACC4
	.align 2, 0
_0801AC00: .4byte gTeamInventory_203B460
_0801AC04: .4byte 0x0001869f
_0801AC08: .4byte gUnknown_80DB9A0
_0801AC0C: .4byte gUnknown_203B224
_0801AC10:
	add r0, sp, 0x4
	adds r1, r4, 0
	movs r2, 0
	bl sub_8090E14
	ldr r0, _0801AC44
	add r1, sp, 0x4
	movs r2, 0x50
	bl strncpy
	ldr r4, _0801AC48
	ldr r0, [r4]
	adds r0, 0x54
	adds r1, r7, 0
	bl sub_8013800
	adds r1, r0, 0
	ldr r2, _0801AC4C
	ldr r0, [r4]
	adds r0, 0x88
	ldr r3, [r0]
	str r5, [sp]
_0801AC3C:
	movs r0, 0x8
	bl xxx_format_and_draw
	b _0801ACC4
	.align 2, 0
_0801AC44: .4byte gUnknown_202DE58
_0801AC48: .4byte gUnknown_203B224
_0801AC4C: .4byte gUnknown_80DB994
_0801AC50:
	add r2, sp, 0x78
	movs r6, 0
	str r6, [sp, 0x78]
	strb r6, [r2, 0x4]
	movs r0, 0x1
	strb r0, [r2, 0x8]
	strb r0, [r4]
	add r4, sp, 0xC8
	add r0, sp, 0x4
	adds r1, r4, 0
	bl sub_8090E14
	ldrb r0, [r4, 0x2]
	bl IsGummiItem
	lsls r0, 24
	lsrs r5, r0, 24
	cmp r5, 0
	beq _0801AC9C
_0801AC76:
	ldr r4, _0801AC98
	ldr r0, [r4]
	adds r0, 0x54
	adds r1, r7, 0
	bl sub_8013800
	adds r1, r0, 0
	ldr r0, [r4]
_0801AC86:
	adds r0, 0x88
	ldr r3, [r0]
	str r6, [sp]
_0801AC8C:
	movs r0, 0x8
	add r2, sp, 0x4
	bl xxx_call_draw_string
	b _0801ACC4
	.align 2, 0
_0801AC98: .4byte gUnknown_203B224
_0801AC9C:
	ldr r0, _0801AD28
	add r1, sp, 0x4
	movs r2, 0x50
	bl strncpy
	ldr r4, _0801AD2C
	ldr r0, [r4]
	adds r0, 0x54
	adds r1, r7, 0
	bl sub_8013800
	adds r1, r0, 0
	ldr r2, _0801AD30
	ldr r0, [r4]
	adds r0, 0x88
	ldr r3, [r0]
	str r5, [sp]
	movs r0, 0x8
	bl xxx_format_and_draw
_0801ACC4:
	mov r0, r8
	bl sub_801AED0
	movs r1, 0x1
	ands r1, r0
	cmp r1, 0
	beq _0801ACFE
	ldr r4, _0801AD2C
	ldr r0, [r4]
	adds r0, 0x54
	adds r1, r7, 0
	bl sub_8013800
	adds r2, r0, 0
	ldr r1, [r4]
	adds r0, r1, 0
	adds r0, 0x88
	ldr r0, [r0]
	adds r1, 0x8C
	ldr r1, [r1]
	movs r4, 0xC
	ldrsh r3, [r1, r4]
	subs r3, 0x2
	lsls r3, 3
	movs r1, 0xA
	str r1, [sp]
	movs r1, 0x8
	bl sub_8007B7C
_0801ACFE:
	adds r7, 0x1
	ldr r1, _0801AD2C
	ldr r0, [r1]
	adds r0, 0x6E
	movs r2, 0
	ldrsh r0, [r0, r2]
_0801AD0A:
	adds r2, r1, 0
	cmp r7, r0
	bge _0801AD12
	b _0801AA60
_0801AD12:
	ldr r0, [r2]
	adds r0, 0x88
	ldr r0, [r0]
	bl sub_80073E0
	add sp, 0xCC
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_0801AD28: .4byte gUnknown_202DE58
_0801AD2C: .4byte gUnknown_203B224
_0801AD30: .4byte gUnknown_80DB994
	thumb_func_end sub_801A9E0

	thumb_func_start sub_801AD34
sub_801AD34:
	push {r4-r6,lr}
	sub sp, 0x8
	adds r4, r0, 0
	bl sub_8008C54
	adds r0, r4, 0
	bl sub_80073B8
	ldr r2, _0801AD98
	movs r6, 0
	str r6, [sp]
	movs r0, 0x6
	movs r1, 0
	adds r3, r4, 0
	bl xxx_call_draw_string
	bl GetNumberOfFilledInventorySlots
	adds r2, r0, 0
	movs r5, 0x7
	str r5, [sp]
	str r4, [sp, 0x4]
	movs r0, 0x12
	movs r1, 0xD
	movs r3, 0x2
	bl sub_8012BC4
	ldr r2, _0801AD9C
	str r6, [sp]
	movs r0, 0x16
	movs r1, 0xD
	adds r3, r4, 0
	bl xxx_call_draw_string
	str r5, [sp]
	str r4, [sp, 0x4]
	movs r0, 0x2B
	movs r1, 0xD
	movs r2, 0x14
	movs r3, 0x2
	bl sub_8012BC4
	adds r0, r4, 0
	bl sub_80073E0
	add sp, 0x8
	pop {r4-r6}
	pop {r0}
	bx r0
	.align 2, 0
_0801AD98: .4byte gUnknown_80DB9A8
_0801AD9C: .4byte gUnknown_80DB9B0
	thumb_func_end sub_801AD34

	thumb_func_start sub_801ADA0
sub_801ADA0:
	push {r4-r6,lr}
	ldr r5, _0801ADEC
	ldr r1, [r5]
	lsls r0, 2
	adds r1, r0
	ldr r6, [r1]
	lsls r4, r6, 8
	lsrs r0, r4, 24
	bl IsNotMoneyOrUsedTMItem
	lsls r0, 24
	cmp r0, 0
	beq _0801AE12
	lsrs r0, r4, 24
	bl IsThrowableItem
	lsls r0, 24
	cmp r0, 0
	beq _0801ADF4
	lsrs r0, r4, 24
	bl sub_801AE24
	ldr r2, [r5]
	lsrs r1, r4, 24
	lsls r1, 1
	adds r2, 0x50
	adds r2, r1
	lsls r0, 16
	lsrs r0, 16
	ldrh r2, [r2]
	adds r0, r2
	lsrs r1, r6, 8
	lsls r1, 24
	lsrs r1, 24
	adds r0, r1
	ldr r1, _0801ADF0
	b _0801AE0E
	.align 2, 0
_0801ADEC: .4byte gTeamInventory_203B460
_0801ADF0: .4byte 0x000003e7
_0801ADF4:
	lsrs r0, r4, 24
	bl sub_801AE24
	ldr r2, [r5]
	lsrs r1, r4, 24
	lsls r1, 1
	adds r2, 0x50
	adds r2, r1
	lsls r0, 16
	lsrs r0, 16
	ldrh r2, [r2]
	adds r0, r2
	ldr r1, _0801AE18
_0801AE0E:
	cmp r0, r1
	ble _0801AE1C
_0801AE12:
	movs r0, 0
	b _0801AE1E
	.align 2, 0
_0801AE18: .4byte 0x000003e6
_0801AE1C:
	movs r0, 0x1
_0801AE1E:
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end sub_801ADA0

	thumb_func_start sub_801AE24
sub_801AE24:
	push {r4-r7,lr}
	adds r7, r0, 0
	movs r5, 0
	movs r6, 0
	b _0801AE74
_0801AE2E:
	ldr r0, _0801AE64
	ldr r0, [r0]
	lsls r1, r6, 2
	adds r0, 0x4
	adds r0, r1
	ldr r0, [r0]
	cmp r0, 0
	beq _0801AE72
	ldr r0, _0801AE68
	ldr r0, [r0]
	adds r0, r1
	ldr r4, [r0]
	lsls r1, r4, 8
	lsrs r0, r1, 24
	cmp r0, r7
	bne _0801AE72
	bl IsThrowableItem
	lsls r0, 24
	cmp r0, 0
	beq _0801AE6C
	lsrs r0, r4, 8
	lsls r0, 24
	lsrs r0, 24
	adds r0, r5, r0
	b _0801AE6E
	.align 2, 0
_0801AE64: .4byte gUnknown_203B224
_0801AE68: .4byte gTeamInventory_203B460
_0801AE6C:
	adds r0, r5, 0x1
_0801AE6E:
	lsls r0, 16
	lsrs r5, r0, 16
_0801AE72:
	adds r6, 0x1
_0801AE74:
	bl GetNumberOfFilledInventorySlots
	cmp r6, r0
	blt _0801AE2E
	adds r0, r5, 0
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_801AE24

	thumb_func_start sub_801AE84
sub_801AE84:
	push {r4,lr}
	movs r2, 0
	ldr r4, _0801AEA4
	movs r3, 0
_0801AE8C:
	ldr r0, [r4]
	lsls r1, r2, 2
	adds r0, 0x4
	adds r0, r1
	str r3, [r0]
	adds r2, 0x1
	cmp r2, 0x13
	ble _0801AE8C
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0801AEA4: .4byte gUnknown_203B224
	thumb_func_end sub_801AE84

	thumb_func_start sub_801AEA8
sub_801AEA8:
	push {lr}
	movs r3, 0
	ldr r0, _0801AECC
	ldr r0, [r0]
	adds r1, r0, 0x4
	movs r2, 0x13
_0801AEB4:
	ldr r0, [r1]
	cmp r0, 0
	beq _0801AEBC
	adds r3, 0x1
_0801AEBC:
	adds r1, 0x4
	subs r2, 0x1
	cmp r2, 0
	bge _0801AEB4
	adds r0, r3, 0
	pop {r1}
	bx r1
	.align 2, 0
_0801AECC: .4byte gUnknown_203B224
	thumb_func_end sub_801AEA8

	thumb_func_start sub_801AED0
sub_801AED0:
	ldr r1, _0801AEE0
	ldr r1, [r1]
	lsls r0, 2
	adds r1, 0x4
	adds r1, r0
	ldr r0, [r1]
	bx lr
	.align 2, 0
_0801AEE0: .4byte gUnknown_203B224
	thumb_func_end sub_801AED0

	thumb_func_start sub_801AEE4
sub_801AEE4:
	ldr r2, _0801AEF4
	ldr r2, [r2]
	lsls r0, 2
	adds r2, 0x4
	adds r2, r0
	str r1, [r2]
	bx lr
	.align 2, 0
_0801AEF4: .4byte gUnknown_203B224
	thumb_func_end sub_801AEE4

	thumb_func_start sub_801AEF8
sub_801AEF8:
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	sub sp, 0x4
	movs r0, 0
	mov r9, r0
	b _0801AF78
_0801AF08:
	movs r1, 0x1
	add r1, r9
	mov r8, r1
	mov r7, r8
	b _0801AF6E
_0801AF12:
	ldr r2, _0801AF90
	ldr r0, [r2]
	mov r1, r9
	lsls r6, r1, 2
	adds r0, r6
	ldrb r0, [r0, 0x2]
	str r2, [sp]
	bl GetItemOrder
	adds r4, r0, 0
	ldr r2, [sp]
	ldr r0, [r2]
	lsls r5, r7, 2
	adds r0, r5
	ldrb r0, [r0, 0x2]
	bl GetItemOrder
	ldr r2, [sp]
	cmp r4, r0
	bgt _0801AF4C
	cmp r4, r0
	bne _0801AF6C
	ldr r0, [r2]
	adds r1, r0, r6
	adds r0, r5
	ldrb r1, [r1, 0x1]
	ldrb r0, [r0, 0x1]
	cmp r1, r0
	bcs _0801AF6C
_0801AF4C:
	ldr r0, [r2]
	adds r2, r0, r6
	ldr r3, [r2]
	adds r0, r5
	ldr r1, [r0]
	str r1, [r2]
	str r3, [r0]
	ldr r0, _0801AF94
	ldr r0, [r0]
	adds r0, 0x4
	adds r2, r0, r6
	ldr r3, [r2]
	adds r0, r5
	ldr r1, [r0]
	str r1, [r2]
	str r3, [r0]
_0801AF6C:
	adds r7, 0x1
_0801AF6E:
	bl GetNumberOfFilledInventorySlots
	cmp r7, r0
	blt _0801AF12
	mov r9, r8
_0801AF78:
	bl GetNumberOfFilledInventorySlots
	subs r0, 0x1
	cmp r9, r0
	blt _0801AF08
	add sp, 0x4
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_0801AF90: .4byte gTeamInventory_203B460
_0801AF94: .4byte gUnknown_203B224
	thumb_func_end sub_801AEF8

        .align 2,0
