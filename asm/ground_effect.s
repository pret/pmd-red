	#include "asm/constants/gba_constants.inc"
	#include "asm/macros.inc"

	.syntax unified

	.text

	thumb_func_start GroundEffect_CancelBlank
GroundEffect_CancelBlank:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0x8
	ldr r1, _080ACD7C
	movs r0, 0
	bl Log
	movs r6, 0
	ldr r0, _080ACD80
	ldr r4, [r0]
	movs r0, 0x1
	negs r0, r0
	mov r8, r0
	movs r1, 0x92
	lsls r1, 1
	adds r5, r4, r1
	mov r7, sp
_080ACD2C:
	movs r1, 0x6
	ldrsh r0, [r4, r1]
	cmp r0, r8
	beq _080ACD5C
	ldr r0, [r5]
	ldr r1, [r4, 0x14]
	adds r0, r1
	str r0, [sp]
	ldr r0, [r5, 0x4]
	ldr r1, [r4, 0x18]
	adds r0, r1
	str r0, [r7, 0x4]
	movs r1, 0xA2
	lsls r1, 1
	adds r0, r4, r1
	mov r1, sp
	bl IsOnscreen_80A675C
	lsls r0, 24
	cmp r0, 0
	bne _080ACD5C
	adds r0, r6, 0
	bl GroundEffect_Delete
_080ACD5C:
	adds r0, r6, 0x1
	lsls r0, 16
	asrs r6, r0, 16
	movs r0, 0xE2
	lsls r0, 1
	adds r5, r0
	adds r4, r0
	cmp r6, 0xF
	ble _080ACD2C
	add sp, 0x8
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_080ACD7C: .4byte gUnknown_8118658
_080ACD80: .4byte gGroundEffects
	thumb_func_end GroundEffect_CancelBlank

	thumb_func_start sub_80ACD84
sub_80ACD84:
	push {r4-r7,lr}
	lsls r0, 16
	asrs r4, r0, 16
	movs r3, 0
	ldr r0, _080ACDA8
	ldr r1, [r0]
	movs r6, 0xE2
	lsls r6, 1
	movs r2, 0x80
	lsls r2, 9
	adds r5, r2, 0
_080ACD9A:
	movs r7, 0x6
	ldrsh r0, [r1, r7]
	cmp r0, r4
	bne _080ACDAC
	adds r0, r3, 0
	b _080ACDBC
	.align 2, 0
_080ACDA8: .4byte gGroundEffects
_080ACDAC:
	adds r0, r2, 0
	adds r2, r5
	asrs r3, r0, 16
	adds r1, r6
	cmp r3, 0xF
	ble _080ACD9A
	movs r0, 0x1
	negs r0, r0
_080ACDBC:
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_80ACD84

	thumb_func_start GroundEffect_Add
GroundEffect_Add:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x10
	adds r7, r1, 0
	lsls r0, 16
	asrs r6, r0, 16
	lsls r2, 16
	asrs r2, 16
	mov r10, r2
	lsls r3, 24
	asrs r3, 24
	mov r9, r3
	ldrb r0, [r7]
	lsls r0, 2
	ldr r1, _080ACE08
	adds r0, r1
	mov r8, r0
	ldr r3, _080ACE0C
	cmp r6, 0
	bge _080ACE38
	movs r2, 0
	ldr r5, [r3]
	movs r0, 0x6
	ldrsh r1, [r5, r0]
	movs r0, 0x1
	negs r0, r0
	cmp r1, r0
	bne _080ACE10
	movs r6, 0
	b _080ACE38
	.align 2, 0
_080ACE08: .4byte gGroundEffectTypes
_080ACE0C: .4byte gGroundEffects
_080ACE10:
	adds r0, r2, 0x1
	lsls r0, 16
	asrs r2, r0, 16
	movs r1, 0xE2
	lsls r1, 1
	adds r5, r1
	cmp r2, 0xF
	bgt _080ACE2E
	movs r4, 0x6
	ldrsh r1, [r5, r4]
	movs r0, 0x1
	negs r0, r0
	cmp r1, r0
	bne _080ACE10
	adds r6, r2, 0
_080ACE2E:
	cmp r6, 0
	bge _080ACE38
	movs r0, 0x1
	negs r0, r0
	b _080AD062
_080ACE38:
	lsls r0, r6, 3
	subs r0, r6
	lsls r0, 4
	adds r0, r6
	lsls r0, 2
	ldr r1, [r3]
	adds r5, r1, r0
	ldr r1, _080ACE9C
	ldrb r3, [r7]
	mov r2, r8
	movs r4, 0
	ldrsh r0, [r2, r4]
	str r0, [sp]
	mov r0, r10
	str r0, [sp, 0x4]
	mov r2, r9
	str r2, [sp, 0x8]
	movs r0, 0
	adds r2, r6, 0
	bl Log
	movs r2, 0
	movs r3, 0x6
	ldrsh r1, [r5, r3]
	movs r0, 0x1
	negs r0, r0
	cmp r1, r0
	bne _080ACE72
	movs r2, 0x1
_080ACE72:
	str r2, [sp, 0xC]
	strh r6, [r5, 0x4]
	ldrb r0, [r7]
	strh r0, [r5, 0x6]
	mov r4, r10
	strh r4, [r5, 0x8]
	mov r0, r9
	strb r0, [r5, 0xA]
	mov r1, r8
	ldrh r0, [r1]
	subs r0, 0x1
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x4
	bhi _080ACEEC
	lsls r0, 2
	ldr r1, _080ACEA0
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080ACE9C: .4byte gUnknown_8118674
_080ACEA0: .4byte _080ACEA4
	.align 2, 0
_080ACEA4:
	.4byte _080ACEB8
	.4byte _080ACEEC
	.4byte _080ACEC4
	.4byte _080ACED0
	.4byte _080ACEDC
_080ACEB8:
	movs r2, 0x8E
	lsls r2, 1
	adds r1, r5, r2
	movs r0, 0x81
	lsls r0, 22
	b _080ACEF4
_080ACEC4:
	movs r4, 0x8E
	lsls r4, 1
	adds r1, r5, r4
	movs r0, 0x83
	lsls r0, 18
	b _080ACEF4
_080ACED0:
	movs r0, 0x8E
	lsls r0, 1
	adds r1, r5, r0
	movs r0, 0x88
	lsls r0, 22
	b _080ACEF4
_080ACEDC:
	movs r2, 0x8E
	lsls r2, 1
	adds r1, r5, r2
	ldr r0, _080ACEE8
	b _080ACEF4
	.align 2, 0
_080ACEE8: .4byte 0x22020000
_080ACEEC:
	movs r3, 0x8E
	lsls r3, 1
	adds r1, r5, r3
	ldr r0, _080ACF08
_080ACEF4:
	str r0, [r1]
	mov r4, r8
	ldrb r0, [r4, 0x2]
	cmp r0, 0
	bne _080ACF0C
	ldrb r0, [r7, 0x2]
	lsls r0, 11
	str r0, [r5, 0xC]
	ldrb r0, [r7, 0x3]
	b _080ACF16
	.align 2, 0
_080ACF08: .4byte 0x220c0000
_080ACF0C:
	mov r1, r8
	ldrb r0, [r1, 0x2]
	lsls r0, 11
	str r0, [r5, 0xC]
	ldrb r0, [r1, 0x3]
_080ACF16:
	lsls r0, 11
	str r0, [r5, 0x10]
	ldr r0, [r5, 0xC]
	lsrs r1, r0, 31
	adds r0, r1
	asrs r0, 1
	str r0, [r5, 0x14]
	ldr r0, [r5, 0x10]
	lsrs r1, r0, 31
	adds r0, r1
	asrs r0, 1
	str r0, [r5, 0x18]
	ldrb r0, [r7, 0x1]
	strb r0, [r5, 0x1C]
	adds r2, r7, 0x4
	adds r4, r5, 0
	adds r4, 0x20
	ldrb r1, [r2, 0x2]
	movs r0, 0x4
	ands r0, r1
	cmp r0, 0
	bne _080ACF5A
	ldrb r0, [r7, 0x4]
	lsls r3, r0, 11
	str r3, [r5, 0x20]
	ldrb r1, [r2, 0x2]
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	beq _080ACF5A
	movs r1, 0x80
	lsls r1, 3
	adds r0, r3, r1
	str r0, [r5, 0x20]
_080ACF5A:
	ldrb r1, [r2, 0x3]
	movs r0, 0x4
	ands r0, r1
	cmp r0, 0
	bne _080ACF7C
	ldrb r0, [r2, 0x1]
	lsls r3, r0, 11
	str r3, [r4, 0x4]
	ldrb r1, [r2, 0x3]
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	beq _080ACF7C
	movs r2, 0x80
	lsls r2, 3
	adds r0, r3, r2
	str r0, [r4, 0x4]
_080ACF7C:
	ldr r3, [sp, 0xC]
	cmp r3, 0
	beq _080ACFD2
	ldrb r1, [r5, 0x1C]
	movs r4, 0x90
	lsls r4, 1
	adds r0, r5, r4
	movs r3, 0
	strb r1, [r0]
	movs r0, 0x92
	lsls r0, 1
	adds r2, r5, r0
	ldr r0, [r5, 0x20]
	ldr r1, [r5, 0x14]
	subs r0, r1
	str r0, [r2]
	movs r1, 0x96
	lsls r1, 1
	adds r2, r5, r1
	ldr r0, [r5, 0x20]
	ldr r1, [r5, 0x14]
	adds r0, r1
	str r0, [r2]
	adds r4, 0x8
	adds r2, r5, r4
	ldr r0, [r5, 0x24]
	ldr r1, [r5, 0x18]
	subs r0, r1
	str r0, [r2]
	movs r0, 0x98
	lsls r0, 1
	adds r2, r5, r0
	ldr r0, [r5, 0x24]
	ldr r1, [r5, 0x18]
	adds r0, r1
	str r0, [r2]
	movs r2, 0x9A
	lsls r2, 1
	adds r1, r5, r2
	adds r4, 0x10
	adds r0, r5, r4
	str r3, [r0]
	str r3, [r1]
_080ACFD2:
	adds r0, r5, 0
	adds r0, 0x28
	adds r1, r5, 0
	adds r1, 0x30
	bl GetCurrentDungeonBounds
	ldr r0, [sp, 0xC]
	cmp r0, 0
	beq _080AD01A
	movs r2, 0x9F
	lsls r2, 1
	adds r1, r5, r2
	movs r2, 0
	movs r0, 0x80
	lsls r0, 4
	strh r0, [r1]
	movs r3, 0x9E
	lsls r3, 1
	adds r1, r5, r3
	movs r0, 0x1
	strb r0, [r1]
	movs r4, 0xA0
	lsls r4, 1
	adds r0, r5, r4
	strh r2, [r0]
	movs r1, 0xA2
	lsls r1, 1
	adds r0, r5, r1
	movs r3, 0x6
	ldrsh r2, [r5, r3]
	subs r4, 0x24
	adds r1, r5, r4
	ldr r3, [r1]
	adds r1, r6, 0
	bl sub_80A7688
_080AD01A:
	adds r4, r5, 0
	adds r4, 0x38
	ldr r1, _080AD074
	mov r0, r9
	str r0, [sp]
	adds r0, r4, 0
	adds r2, r5, 0
	mov r3, r10
	bl InitActionWithParams
	ldr r2, [r7, 0x8]
	cmp r2, 0
	bne _080AD04C
	mov r1, r8
	movs r3, 0
	ldrsh r0, [r1, r3]
	cmp r0, 0x1
	bne _080AD048
	ldr r0, _080AD078
	movs r1, 0xB0
	lsls r1, 2
	adds r0, r1
	ldr r2, [r0]
_080AD048:
	cmp r2, 0
	beq _080AD060
_080AD04C:
	adds r0, r4, 0
	movs r1, 0
	bl SetPredefinedScript
	ldr r3, _080AD07C
	adds r0, r4, 0
	movs r1, 0
	movs r2, 0
	bl ExecutePredefinedScript
_080AD060:
	adds r0, r6, 0
_080AD062:
	add sp, 0x10
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	.align 2, 0
_080AD074: .4byte gGroundEffectCallbacks
_080AD078: .4byte gFunctionScriptTable
_080AD07C: .4byte gUnknown_81186CC
	thumb_func_end GroundEffect_Add

	thumb_func_start GroundEffect_Delete
GroundEffect_Delete:
	push {r4,lr}
	adds r2, r0, 0
	lsls r2, 16
	asrs r2, 16
	ldr r1, _080AD0BC
	lsls r0, r2, 3
	subs r0, r2
	lsls r0, 4
	adds r0, r2
	lsls r0, 2
	ldr r1, [r1]
	adds r4, r1, r0
	ldr r1, _080AD0C0
	movs r0, 0
	bl Log
	movs r1, 0xA2
	lsls r1, 1
	adds r0, r4, r1
	bl sub_80A7714
	adds r0, r4, 0
	adds r0, 0x38
	bl InitAction2
	ldr r0, _080AD0C4
	strh r0, [r4, 0x6]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080AD0BC: .4byte gGroundEffects
_080AD0C0: .4byte gUnknown_81186D8
_080AD0C4: .4byte 0x0000ffff
	thumb_func_end GroundEffect_Delete

	thumb_func_start sub_80AD0C8
sub_80AD0C8:
	push {lr}
	adds r3, r1, 0
	lsls r0, 16
	asrs r0, 16
	ldr r2, _080AD108
	lsls r1, r0, 3
	subs r1, r0
	lsls r1, 4
	adds r1, r0
	lsls r1, 2
	ldr r0, [r2]
	adds r2, r0, r1
	movs r0, 0x6
	ldrsh r1, [r2, r0]
	movs r0, 0x1
	negs r0, r0
	cmp r1, r0
	beq _080AD102
	movs r1, 0x8E
	lsls r1, 1
	adds r0, r2, r1
	ldr r1, [r0]
	orrs r1, r3
	str r1, [r0]
	movs r3, 0xA2
	lsls r3, 1
	adds r0, r2, r3
	bl sub_80A6688
_080AD102:
	pop {r0}
	bx r0
	.align 2, 0
_080AD108: .4byte gGroundEffects
	thumb_func_end sub_80AD0C8

	thumb_func_start sub_80AD10C
sub_80AD10C:
	push {r4,lr}
	adds r4, r1, 0
	lsls r0, 16
	asrs r0, 16
	ldr r2, _080AD150
	lsls r1, r0, 3
	subs r1, r0
	lsls r1, 4
	adds r1, r0
	lsls r1, 2
	ldr r0, [r2]
	adds r3, r0, r1
	movs r0, 0x6
	ldrsh r1, [r3, r0]
	movs r0, 0x1
	negs r0, r0
	cmp r1, r0
	beq _080AD14A
	movs r0, 0x8E
	lsls r0, 1
	adds r2, r3, r0
	ldr r0, _080AD154
	eors r0, r4
	ldr r1, [r2]
	ands r1, r0
	str r1, [r2]
	movs r2, 0xA2
	lsls r2, 1
	adds r0, r3, r2
	bl sub_80A6688
_080AD14A:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080AD150: .4byte gGroundEffects
_080AD154: .4byte 0x337fffff
	thumb_func_end sub_80AD10C

	thumb_func_start sub_80AD158
sub_80AD158:
	push {lr}
	lsls r0, 16
	asrs r0, 16
	ldr r2, _080AD180
	lsls r1, r0, 3
	subs r1, r0
	lsls r1, 4
	adds r1, r0
	lsls r1, 2
	ldr r0, [r2]
	adds r2, r0, r1
	movs r0, 0x6
	ldrsh r1, [r2, r0]
	movs r0, 0x1
	negs r0, r0
	cmp r1, r0
	bne _080AD184
	movs r0, 0
	b _080AD188
	.align 2, 0
_080AD180: .4byte gGroundEffects
_080AD184:
	adds r0, r2, 0
	adds r0, 0x38
_080AD188:
	pop {r1}
	bx r1
	thumb_func_end sub_80AD158

	thumb_func_start sub_80AD18C
sub_80AD18C:
	push {r4,lr}
	adds r4, r1, 0
	lsls r0, 16
	asrs r0, 16
	lsls r2, 16
	asrs r3, r2, 16
	ldr r2, _080AD1B8
	lsls r1, r0, 3
	subs r1, r0
	lsls r1, 4
	adds r1, r0
	lsls r1, 2
	ldr r0, [r2]
	adds r2, r0, r1
	movs r0, 0x6
	ldrsh r1, [r2, r0]
	movs r0, 0x1
	negs r0, r0
	cmp r1, r0
	bne _080AD1BC
	movs r0, 0
	b _080AD1CC
	.align 2, 0
_080AD1B8: .4byte gGroundEffects
_080AD1BC:
	adds r0, r2, 0
	adds r0, 0x38
	adds r1, r4, 0
	adds r2, r3, 0
	bl GetPredefinedScript
	lsls r0, 24
	lsrs r0, 24
_080AD1CC:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_80AD18C

	thumb_func_start GroundEffect_ExecuteScript
GroundEffect_ExecuteScript:
	push {r4-r6,lr}
	adds r3, r0, 0
	adds r5, r1, 0
	adds r6, r2, 0
	lsls r3, 16
	asrs r3, 16
	ldr r1, _080AD20C
	lsls r0, r3, 3
	subs r0, r3
	lsls r0, 4
	adds r0, r3
	lsls r0, 2
	ldr r1, [r1]
	adds r4, r1, r0
	ldr r1, _080AD210
	movs r0, 0
	adds r2, r3, 0
	bl Log
	movs r0, 0x6
	ldrsh r1, [r4, r0]
	movs r0, 0x1
	negs r0, r0
	cmp r1, r0
	bne _080AD214
	movs r0, 0
	b _080AD22C
	.align 2, 0
_080AD20C: .4byte gGroundEffects
_080AD210: .4byte gUnknown_81186F4
_080AD214:
	adds r0, r4, 0
	adds r0, 0x38
	ldr r3, _080AD234
	adds r1, r5, 0
	adds r2, r6, 0
	bl GroundScript_ExecutePP
	movs r0, 0x9E
	lsls r0, 1
	adds r1, r4, r0
	movs r0, 0x1
	strb r0, [r1]
_080AD22C:
	pop {r4-r6}
	pop {r1}
	bx r1
	.align 2, 0
_080AD234: .4byte gUnknown_811872C
	thumb_func_end GroundEffect_ExecuteScript

	thumb_func_start GroundEffectsNotifyAll
GroundEffectsNotifyAll:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	lsls r0, 16
	asrs r7, r0, 16
	ldr r0, _080AD28C
	ldr r4, [r0]
	movs r5, 0
	movs r0, 0x1
	negs r0, r0
	mov r8, r0
	movs r6, 0x80
	lsls r6, 9
_080AD252:
	movs r1, 0x6
	ldrsh r0, [r4, r1]
	cmp r0, r8
	beq _080AD26A
	adds r0, r4, 0
	adds r0, 0x38
	adds r1, r7, 0
	bl GroundScriptNotify
	orrs r5, r0
	lsls r0, r5, 24
	lsrs r5, r0, 24
_080AD26A:
	adds r0, r6, 0
	movs r1, 0x80
	lsls r1, 9
	adds r6, r1
	asrs r0, 16
	movs r1, 0xE2
	lsls r1, 1
	adds r4, r1
	cmp r0, 0xF
	ble _080AD252
	adds r0, r5, 0
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r1}
	bx r1
	.align 2, 0
_080AD28C: .4byte gGroundEffects
	thumb_func_end GroundEffectsNotifyAll

	thumb_func_start GroundEffectsCancelAll
GroundEffectsCancelAll:
	push {r4-r7,lr}
	ldr r0, _080AD2D4
	ldr r4, [r0]
	movs r5, 0
	movs r7, 0x1
	negs r7, r7
	movs r6, 0x80
	lsls r6, 9
_080AD2A0:
	movs r1, 0x6
	ldrsh r0, [r4, r1]
	cmp r0, r7
	beq _080AD2B6
	adds r0, r4, 0
	adds r0, 0x38
	bl GroundScript_Cancel
	orrs r5, r0
	lsls r0, r5, 24
	lsrs r5, r0, 24
_080AD2B6:
	adds r0, r6, 0
	movs r1, 0x80
	lsls r1, 9
	adds r6, r1
	asrs r0, 16
	movs r1, 0xE2
	lsls r1, 1
	adds r4, r1
	cmp r0, 0xF
	ble _080AD2A0
	adds r0, r5, 0
	pop {r4-r7}
	pop {r1}
	bx r1
	.align 2, 0
_080AD2D4: .4byte gGroundEffects
	thumb_func_end GroundEffectsCancelAll

	thumb_func_start sub_80AD2D8
sub_80AD2D8:
	lsls r0, 16
	asrs r0, 16
	ldr r2, _080AD2F4
	lsls r1, r0, 3
	subs r1, r0
	lsls r1, 4
	adds r1, r0
	lsls r1, 2
	ldr r0, [r2]
	adds r0, r1
	movs r1, 0x6
	ldrsh r0, [r0, r1]
	bx lr
	.align 2, 0
_080AD2F4: .4byte gGroundEffects
	thumb_func_end sub_80AD2D8

	thumb_func_start sub_80AD2F8
sub_80AD2F8:
	lsls r0, 16
	asrs r0, 16
	ldr r3, _080AD31C
	lsls r2, r0, 3
	subs r2, r0
	lsls r2, 4
	adds r2, r0
	lsls r2, 2
	ldr r0, [r3]
	adds r0, r2
	movs r3, 0x8E
	lsls r3, 1
	adds r2, r0, r3
	ldr r2, [r2]
	str r2, [r1]
	movs r1, 0x6
	ldrsh r0, [r0, r1]
	bx lr
	.align 2, 0
_080AD31C: .4byte gGroundEffects
	thumb_func_end sub_80AD2F8

	thumb_func_start sub_80AD320
sub_80AD320:
	push {lr}
	adds r3, r1, 0
	lsls r0, 16
	asrs r0, 16
	ldr r2, _080AD34C
	lsls r1, r0, 3
	subs r1, r0
	lsls r1, 4
	adds r1, r0
	lsls r1, 2
	ldr r0, [r2]
	adds r2, r0, r1
	movs r0, 0x6
	ldrsh r1, [r2, r0]
	movs r0, 0x1
	negs r0, r0
	cmp r1, r0
	bne _080AD350
	movs r0, 0
	str r0, [r3]
	str r0, [r3, 0x4]
	b _080AD358
	.align 2, 0
_080AD34C: .4byte gGroundEffects
_080AD350:
	ldr r0, [r2, 0xC]
	ldr r1, [r2, 0x10]
	str r0, [r3]
	str r1, [r3, 0x4]
_080AD358:
	movs r1, 0x6
	ldrsh r0, [r2, r1]
	pop {r1}
	bx r1
	thumb_func_end sub_80AD320

	thumb_func_start sub_80AD360
sub_80AD360:
	push {lr}
	adds r3, r1, 0
	lsls r0, 16
	asrs r0, 16
	ldr r2, _080AD38C
	lsls r1, r0, 3
	subs r1, r0
	lsls r1, 4
	adds r1, r0
	lsls r1, 2
	ldr r0, [r2]
	adds r2, r0, r1
	movs r0, 0x6
	ldrsh r1, [r2, r0]
	movs r0, 0x1
	negs r0, r0
	cmp r1, r0
	bne _080AD390
	movs r0, 0
	str r0, [r3]
	b _080AD3AA
	.align 2, 0
_080AD38C: .4byte gGroundEffects
_080AD390:
	movs r1, 0x92
	lsls r1, 1
	adds r0, r2, r1
	ldr r0, [r0]
	ldr r1, [r2, 0x14]
	adds r0, r1
	str r0, [r3]
	movs r1, 0x94
	lsls r1, 1
	adds r0, r2, r1
	ldr r0, [r0]
	ldr r1, [r2, 0x18]
	adds r0, r1
_080AD3AA:
	str r0, [r3, 0x4]
	movs r1, 0x6
	ldrsh r0, [r2, r1]
	pop {r1}
	bx r1
	thumb_func_end sub_80AD360

	thumb_func_start sub_80AD3B4
sub_80AD3B4:
	push {r4,lr}
	lsls r0, 16
	asrs r0, 16
	ldr r3, _080AD3DC
	lsls r2, r0, 3
	subs r2, r0
	lsls r2, 4
	adds r2, r0
	lsls r2, 2
	ldr r4, [r3]
	adds r4, r2
	adds r0, r4, 0
	bl sub_80AD3E0
	movs r1, 0x6
	ldrsh r0, [r4, r1]
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_080AD3DC: .4byte gGroundEffects
	thumb_func_end sub_80AD3B4

	thumb_func_start sub_80AD3E0
sub_80AD3E0:
	push {r4-r7,lr}
	mov r12, r0
	ldr r3, [r1]
	ldr r2, [r0, 0x14]
	subs r6, r3, r2
	ldr r1, [r1, 0x4]
	ldr r0, [r0, 0x18]
	subs r7, r1, r0
	adds r4, r3, r2
	adds r5, r1, r0
	mov r1, r12
	ldr r0, [r1, 0x28]
	cmp r6, r0
	blt _080AD40E
	ldr r0, [r1, 0x30]
	cmp r4, r0
	bge _080AD40E
	ldr r0, [r1, 0x2C]
	cmp r7, r0
	blt _080AD40E
	ldr r0, [r1, 0x34]
	cmp r5, r0
	blt _080AD412
_080AD40E:
	movs r0, 0x1
	b _080AD428
_080AD412:
	movs r0, 0x92
	lsls r0, 1
	add r0, r12
	str r6, [r0]
	str r7, [r0, 0x4]
	movs r0, 0x96
	lsls r0, 1
	add r0, r12
	str r4, [r0]
	str r5, [r0, 0x4]
	movs r0, 0
_080AD428:
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_80AD3E0

	thumb_func_start sub_80AD430
sub_80AD430:
	push {r4-r6,lr}
	mov r12, r0
	movs r0, 0x92
	lsls r0, 1
	add r0, r12
	ldr r0, [r0]
	ldr r2, [r1]
	adds r5, r0, r2
	movs r0, 0x94
	lsls r0, 1
	add r0, r12
	ldr r0, [r0]
	ldr r1, [r1, 0x4]
	adds r6, r0, r1
	movs r0, 0x96
	lsls r0, 1
	add r0, r12
	ldr r0, [r0]
	adds r3, r0, r2
	movs r0, 0x98
	lsls r0, 1
	add r0, r12
	ldr r0, [r0]
	adds r4, r0, r1
	mov r0, r12
	ldr r1, [r0, 0x28]
	cmp r5, r1
	bge _080AD470
	adds r5, r1, 0
	ldr r0, [r0, 0xC]
	adds r3, r1, r0
	b _080AD47E
_080AD470:
	mov r2, r12
	ldr r1, [r2, 0x30]
	cmp r3, r1
	blt _080AD47E
	ldr r0, [r2, 0xC]
	subs r5, r1, r0
	adds r3, r1, 0
_080AD47E:
	mov r0, r12
	ldr r1, [r0, 0x2C]
	cmp r6, r1
	bge _080AD48E
	adds r6, r1, 0
	ldr r0, [r0, 0x10]
	adds r4, r1, r0
	b _080AD49C
_080AD48E:
	mov r2, r12
	ldr r1, [r2, 0x34]
	cmp r4, r1
	blt _080AD49C
	ldr r0, [r2, 0x10]
	subs r6, r1, r0
	adds r4, r1, 0
_080AD49C:
	movs r0, 0x92
	lsls r0, 1
	add r0, r12
	str r5, [r0]
	str r6, [r0, 0x4]
	movs r0, 0x96
	lsls r0, 1
	add r0, r12
	str r3, [r0]
	str r4, [r0, 0x4]
	movs r0, 0
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end sub_80AD430

	thumb_func_start CallbackEffectGetIndex
CallbackEffectGetIndex:
	movs r1, 0x4
	ldrsh r0, [r0, r1]
	bx lr
	thumb_func_end CallbackEffectGetIndex

	thumb_func_start CallbackEffectGetSize
CallbackEffectGetSize:
	ldr r2, [r0, 0xC]
	ldr r3, [r0, 0x10]
	str r2, [r1]
	str r3, [r1, 0x4]
	bx lr
	thumb_func_end CallbackEffectGetSize

	thumb_func_start CallbackEffectSetHitboxPos
CallbackEffectSetHitboxPos:
	push {r4,lr}
	adds r3, r0, 0
	adds r4, r1, 0
	cmp r4, 0
	beq _080AD50C
	movs r0, 0x92
	lsls r0, 1
	adds r2, r3, r0
	ldr r1, [r4]
	ldr r0, [r3, 0x14]
	subs r0, r1, r0
	str r0, [r2]
	movs r0, 0x96
	lsls r0, 1
	adds r2, r3, r0
	ldr r0, [r3, 0x14]
	adds r1, r0
	str r1, [r2]
	movs r0, 0x94
	lsls r0, 1
	adds r2, r3, r0
	ldr r1, [r4, 0x4]
	ldr r0, [r3, 0x18]
	subs r0, r1, r0
	str r0, [r2]
	movs r0, 0x98
	lsls r0, 1
	adds r2, r3, r0
	ldr r0, [r3, 0x18]
	adds r1, r0
	str r1, [r2]
	b _080AD572
_080AD50C:
	movs r0, 0x92
	lsls r0, 1
	adds r2, r3, r0
	ldr r0, [r3, 0x20]
	ldr r1, [r3, 0x14]
	subs r0, r1
	str r0, [r2]
	movs r0, 0x96
	lsls r0, 1
	adds r2, r3, r0
	ldr r0, [r3, 0x20]
	ldr r1, [r3, 0x14]
	adds r0, r1
	str r0, [r2]
	movs r0, 0x94
	lsls r0, 1
	adds r2, r3, r0
	ldr r0, [r3, 0x24]
	ldr r1, [r3, 0x18]
	subs r0, r1
	str r0, [r2]
	movs r0, 0x98
	lsls r0, 1
	adds r2, r3, r0
	ldr r0, [r3, 0x24]
	ldr r1, [r3, 0x18]
	adds r0, r1
	str r0, [r2]
	movs r2, 0x9A
	lsls r2, 1
	adds r1, r3, r2
	adds r2, 0x4
	adds r0, r3, r2
	str r4, [r0]
	str r4, [r1]
	movs r0, 0x90
	lsls r0, 1
	adds r2, r3, r0
	movs r1, 0
	ldrsb r1, [r2, r1]
	movs r0, 0x1C
	ldrsb r0, [r3, r0]
	cmp r1, r0
	beq _080AD56E
	movs r0, 0x9E
	lsls r0, 1
	adds r1, r3, r0
	movs r0, 0x1
	strb r0, [r1]
_080AD56E:
	ldrb r0, [r3, 0x1C]
	strb r0, [r2]
_080AD572:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end CallbackEffectSetHitboxPos

	thumb_func_start CallbackEffectSetPositionBounds
CallbackEffectSetPositionBounds:
	push {r4,lr}
	ldr r3, [r1]
	ldr r4, [r1, 0x4]
	str r3, [r0, 0x28]
	str r4, [r0, 0x2C]
	ldr r1, [r2]
	ldr r2, [r2, 0x4]
	str r1, [r0, 0x30]
	str r2, [r0, 0x34]
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end CallbackEffectSetPositionBounds

	thumb_func_start CallbackEffectGetHitboxCenter
CallbackEffectGetHitboxCenter:
	adds r3, r0, 0
	movs r2, 0x92
	lsls r2, 1
	adds r0, r3, r2
	ldr r0, [r0]
	ldr r2, [r3, 0x14]
	adds r0, r2
	str r0, [r1]
	movs r2, 0x94
	lsls r2, 1
	adds r0, r3, r2
	ldr r0, [r0]
	ldr r2, [r3, 0x18]
	adds r0, r2
	str r0, [r1, 0x4]
	bx lr
	thumb_func_end CallbackEffectGetHitboxCenter

	thumb_func_start CallbackEffectMoveReal
CallbackEffectMoveReal:
	push {lr}
	bl sub_80AD3E0
	pop {r1}
	bx r1
	thumb_func_end CallbackEffectMoveReal

	thumb_func_start CallbackEffectGetPosHeightAndUnk
CallbackEffectGetPosHeightAndUnk:
	push {r4,lr}
	adds r3, r0, 0
	movs r4, 0x9A
	lsls r4, 1
	adds r0, r3, r4
	ldr r0, [r0]
	str r0, [r1]
	movs r1, 0x9C
	lsls r1, 1
	adds r0, r3, r1
	ldr r0, [r0]
	str r0, [r2]
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end CallbackEffectGetPosHeightAndUnk

	thumb_func_start CallbackEffectSetPosHeight
CallbackEffectSetPosHeight:
	movs r2, 0x9A
	lsls r2, 1
	adds r0, r2
	str r1, [r0]
	bx lr
	thumb_func_end CallbackEffectSetPosHeight

	thumb_func_start CallbackEffectGetDirection
CallbackEffectGetDirection:
	movs r2, 0x90
	lsls r2, 1
	adds r0, r2
	ldrb r0, [r0]
	strb r0, [r1]
	bx lr
	thumb_func_end CallbackEffectGetDirection

	thumb_func_start CallbackEffectSetDirection
CallbackEffectSetDirection:
	push {lr}
	adds r2, r0, 0
	lsls r1, 24
	asrs r1, 24
	movs r0, 0x1
	negs r0, r0
	cmp r1, r0
	beq _080AD60C
	movs r3, 0x90
	lsls r3, 1
	adds r0, r2, r3
	strb r1, [r0]
_080AD60C:
	pop {r0}
	bx r0
	thumb_func_end CallbackEffectSetDirection

	thumb_func_start CallbackEffectSetEventIndex
CallbackEffectSetEventIndex:
	push {r4,r5,lr}
	lsls r1, 16
	adds r3, r0, 0
	movs r0, 0xFF
	lsls r0, 16
	ands r0, r1
	lsrs r0, 16
	cmp r0, 0
	beq _080AD630
	ldr r1, _080AD62C
	lsls r0, 1
	adds r0, r1
	b _080AD636
	.align 2, 0
_080AD62C: .4byte gUnknown_81185F2
_080AD630:
	movs r5, 0x9F
	lsls r5, 1
	adds r0, r3, r5
_080AD636:
	movs r1, 0
	ldrsh r2, [r0, r1]
	movs r5, 0x9F
	lsls r5, 1
	adds r1, r3, r5
	ldrh r4, [r1]
	movs r5, 0
	ldrsh r0, [r1, r5]
	cmp r0, r2
	beq _080AD654
	strh r2, [r1]
	movs r0, 0x9E
	lsls r0, 1
	adds r1, r3, r0
	b _080AD664
_080AD654:
	movs r0, 0x80
	lsls r0, 5
	ands r0, r4
	cmp r0, 0
	beq _080AD668
	movs r5, 0x9E
	lsls r5, 1
	adds r1, r3, r5
_080AD664:
	movs r0, 0x1
	strb r0, [r1]
_080AD668:
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end CallbackEffectSetEventIndex

	thumb_func_start CallbackEffectSetUnk_80AD670
CallbackEffectSetUnk_80AD670:
	push {lr}
	lsls r1, 16
	asrs r1, 16
	adds r2, r1, 0
	cmp r1, 0
	bne _080AD682
	movs r1, 0xE0
	lsls r1, 1
	adds r2, r1, 0
_080AD682:
	movs r1, 0xA0
	lsls r1, 1
	adds r0, r1
	strh r2, [r0]
	pop {r0}
	bx r0
	thumb_func_end CallbackEffectSetUnk_80AD670

	thumb_func_start CallbackEffectSpriteRelatedCheck_80AD690
CallbackEffectSpriteRelatedCheck_80AD690:
	push {lr}
	adds r1, r0, 0
	movs r2, 0x9E
	lsls r2, 1
	adds r0, r1, r2
	ldrb r0, [r0]
	cmp r0, 0
	bne _080AD6AE
	adds r2, 0x8
	adds r0, r1, r2
	bl sub_80A66F8
	lsls r0, 24
	lsrs r0, 24
	b _080AD6B0
_080AD6AE:
	movs r0, 0x1
_080AD6B0:
	pop {r1}
	bx r1
	thumb_func_end CallbackEffectSpriteRelatedCheck_80AD690

	thumb_func_start CallbackEffectSpriteRelated_80AD6B4
CallbackEffectSpriteRelated_80AD6B4:
	push {lr}
	adds r1, r0, 0
	movs r2, 0xA0
	lsls r2, 1
	adds r0, r1, r2
	movs r2, 0
	ldrsh r0, [r0, r2]
	cmp r0, 0
	bne _080AD6D6
	movs r2, 0xA2
	lsls r2, 1
	adds r0, r1, r2
	bl sub_80A671C
	lsls r0, 24
	lsrs r0, 24
	b _080AD6D8
_080AD6D6:
	movs r0, 0x1
_080AD6D8:
	pop {r1}
	bx r1
	thumb_func_end CallbackEffectSpriteRelated_80AD6B4

	thumb_func_start CallbackEffectGetFlags
CallbackEffectGetFlags:
	movs r2, 0x8E
	lsls r2, 1
	adds r0, r2
	ldr r0, [r0]
	str r0, [r1]
	bx lr
	thumb_func_end CallbackEffectGetFlags

	thumb_func_start CallbackEffectSetFlags
CallbackEffectSetFlags:
	push {lr}
	movs r2, 0x4
	ldrsh r0, [r0, r2]
	bl sub_80AD0C8
	pop {r0}
	bx r0
	thumb_func_end CallbackEffectSetFlags

	thumb_func_start CallbackEffectClearFlags
CallbackEffectClearFlags:
	push {lr}
	movs r2, 0x4
	ldrsh r0, [r0, r2]
	bl sub_80AD10C
	pop {r0}
	bx r0
	thumb_func_end CallbackEffectClearFlags

	thumb_func_start CallbackEffectMoveRelative
CallbackEffectMoveRelative:
	push {lr}
	bl sub_80AD430
	pop {r1}
	bx r1
	thumb_func_end CallbackEffectMoveRelative

	thumb_func_start GroundEffect_Action
GroundEffect_Action:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	ldr r0, _080AD754
	ldr r5, [r0]
	movs r7, 0
	movs r0, 0x1
	negs r0, r0
	mov r8, r0
	movs r1, 0x9E
	lsls r1, 1
	adds r6, r5, r1
_080AD72C:
	movs r3, 0x6
	ldrsh r0, [r5, r3]
	cmp r0, r8
	beq _080AD78A
	adds r4, r5, 0
	adds r4, 0x38
	adds r0, r4, 0
	ldr r1, _080AD758
	bl HandleAction
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0
	beq _080AD75C
	cmp r0, 0x4
	bne _080AD768
	adds r0, r7, 0
	bl GroundEffect_Delete
	b _080AD78A
	.align 2, 0
_080AD754: .4byte gGroundEffects
_080AD758: .4byte gUnknown_811874C
_080AD75C:
	adds r0, r4, 0
	movs r1, 0
	movs r2, 0x1
	ldr r3, _080AD7A8
	bl ExecutePredefinedScript
_080AD768:
	ldrb r0, [r6]
	cmp r0, 0
	beq _080AD78A
	movs r0, 0
	strb r0, [r6]
	movs r1, 0xA2
	lsls r1, 1
	adds r0, r5, r1
	ldrh r2, [r6, 0x2]
	movs r3, 0xF8
	lsls r3, 5
	adds r1, r3, 0
	ands r1, r2
	lsls r2, 24
	asrs r2, 24
	bl sub_80A6EFC
_080AD78A:
	adds r0, r7, 0x1
	lsls r0, 16
	asrs r7, r0, 16
	movs r0, 0xE2
	lsls r0, 1
	adds r6, r0
	adds r5, r0
	cmp r7, 0xF
	ble _080AD72C
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_080AD7A8: .4byte gUnknown_8118758
	thumb_func_end GroundEffect_Action

	thumb_func_start sub_80AD7AC
sub_80AD7AC:
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	sub sp, 0x8
	ldr r0, _080AD864
	ldr r6, [r0]
	movs r0, 0
	mov r8, r0
	movs r1, 0x1
	negs r1, r1
	mov r9, r1
	movs r2, 0x90
	lsls r2, 1
	adds r4, r6, r2
_080AD7CA:
	movs r0, 0x6
	ldrsh r1, [r6, r0]
	mov r2, r9
	lsls r0, r2, 16
	asrs r0, 16
	cmp r1, r0
	beq _080AD83C
	ldr r0, [r4, 0x4]
	ldr r1, [r6, 0x14]
	adds r0, r1
	str r0, [sp]
	ldr r0, [r4, 0x8]
	ldr r1, [r6, 0x18]
	adds r0, r1
	str r0, [sp, 0x4]
	ldr r1, [r4, 0x14]
	ldr r0, [r4, 0x18]
	adds r7, r1, r0
	movs r0, 0xA2
	lsls r0, 1
	adds r5, r6, r0
	adds r0, r5, 0
	bl sub_80A66D4
	lsls r0, 24
	cmp r0, 0
	beq _080AD818
	movs r0, 0
	strb r0, [r4, 0x1C]
	ldrh r2, [r4, 0x1E]
	movs r0, 0xF8
	lsls r0, 5
	adds r1, r0, 0
	ands r1, r2
	lsls r2, 24
	asrs r2, 24
	adds r0, r5, 0
	bl sub_80A6EFC
_080AD818:
	movs r1, 0x20
	ldrsh r0, [r4, r1]
	cmp r0, 0
	beq _080AD832
	adds r1, r0, 0
	movs r2, 0
	ldrsb r2, [r4, r2]
	adds r0, r5, 0
	movs r3, 0
	bl sub_80A7040
	movs r0, 0
	strh r0, [r4, 0x20]
_080AD832:
	adds r0, r5, 0
	mov r1, sp
	adds r2, r7, 0
	bl sub_80A7720
_080AD83C:
	mov r0, r8
	adds r0, 0x1
	lsls r0, 16
	asrs r0, 16
	mov r8, r0
	movs r0, 0xE2
	lsls r0, 1
	adds r4, r0
	adds r6, r0
	mov r1, r8
	cmp r1, 0xF
	ble _080AD7CA
	add sp, 0x8
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_080AD864: .4byte gGroundEffects
	thumb_func_end sub_80AD7AC

        .align 2,0
