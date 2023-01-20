	#include "asm/constants/gba_constants.inc"
	#include "asm/macros.inc"

	.syntax unified

	.text

	thumb_func_start sub_805AAD0
sub_805AAD0:
	push {lr}
	adds r1, r0, 0
	bl FixedDamageStatusTarget
	movs r0, 0x1
	pop {r1}
	bx r1
	thumb_func_end sub_805AAD0

	thumb_func_start sub_805AAE0
sub_805AAE0:
	push {r4-r7,lr}
	sub sp, 0x4
	adds r4, r0, 0
	adds r6, r1, 0
	ldr r0, [r4, 0x70]
	movs r7, 0
	movs r1, 0x9E
	lsls r1, 1
	adds r5, r0, r1
	ldr r0, [r5]
	bl RoundUpFixedPoint
	cmp r0, 0x1
	ble _0805AB20
	ldr r0, _0805AB1C
	ldr r2, [r0]
	adds r0, r4, 0
	adds r1, r6, 0
	movs r3, 0x63
	bl RaiseAttackStageTarget
	mov r0, sp
	movs r1, 0x1
	bl sub_80943A0
	ldr r0, [sp]
	str r0, [r5]
	movs r7, 0x1
	b _0805AB36
	.align 2, 0
_0805AB1C: .4byte gUnknown_8106A4C
_0805AB20:
	ldr r0, _0805AB40
	adds r1, r4, 0
	movs r2, 0
	bl SetMessageArgument
	ldr r0, _0805AB44
	ldr r2, [r0]
	adds r0, r4, 0
	adds r1, r6, 0
	bl sub_80522F4
_0805AB36:
	adds r0, r7, 0
	add sp, 0x4
	pop {r4-r7}
	pop {r1}
	bx r1
	.align 2, 0
_0805AB40: .4byte gAvailablePokemonNames
_0805AB44: .4byte gUnknown_80FC5CC
	thumb_func_end sub_805AAE0

	thumb_func_start sub_805AB48
sub_805AB48:
	push {lr}
	bl LightScreenStatusTarget
	movs r0, 0x1
	pop {r1}
	bx r1
	thumb_func_end sub_805AB48

	thumb_func_start sub_805AB54
sub_805AB54:
	push {r4-r7,lr}
	sub sp, 0x8
	adds r5, r0, 0
	adds r6, r1, 0
	movs r7, 0
	movs r4, 0x80
	lsls r4, 1
	str r3, [sp]
	adds r3, r4, 0
	bl sub_8055640
	cmp r0, 0
	bne _0805AB70
	b _0805AC86
_0805AB70:
	movs r7, 0x1
	ldr r0, _0805ABA8
	movs r1, 0
	ldrsh r2, [r0, r1]
	adds r0, r5, 0
	adds r1, r6, 0
	bl sub_805727C
	lsls r0, 24
	cmp r0, 0
	bne _0805AB88
	b _0805AC86
_0805AB88:
	ldr r1, _0805ABAC
	ldr r0, _0805ABB0
	ldr r0, [r0]
	ldr r2, _0805ABB4
	adds r0, r2
	movs r2, 0
	ldrsh r0, [r0, r2]
	adds r0, r1
	ldrb r0, [r0]
	cmp r0, 0x8
	bhi _0805AC7C
	lsls r0, 2
	ldr r1, _0805ABB8
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0805ABA8: .4byte gUnknown_80F4E06
_0805ABAC: .4byte gUnknown_80F5978
_0805ABB0: .4byte gDungeon
_0805ABB4: .4byte 0x00003a0e
_0805ABB8: .4byte _0805ABBC
	.align 2, 0
_0805ABBC:
	.4byte _0805ABE0
	.4byte _0805ABEC
	.4byte _0805AC08
	.4byte _0805AC16
	.4byte _0805AC34
	.4byte _0805AC50
	.4byte _0805AC64
	.4byte _0805AC70
	.4byte _0805AC7C
_0805ABE0:
	adds r0, r5, 0
	adds r1, r6, 0
	movs r2, 0
	bl PoisonedStatusTarget
	b _0805AC86
_0805ABEC:
	ldr r1, _0805AC04
	adds r0, r6, 0
	movs r2, 0x1
	bl CalculateStatusTurns
	adds r2, r0, 0
	adds r0, r5, 0
	adds r1, r6, 0
	movs r3, 0
	bl sub_8075C58
	b _0805AC86
	.align 2, 0
_0805AC04: .4byte gUnknown_80F4E74
_0805AC08:
	adds r0, r5, 0
	adds r1, r6, 0
	movs r2, 0x1
	movs r3, 0
	bl LowerMovementSpeedTarget
	b _0805AC86
_0805AC16:
	ldr r0, _0805AC30
	ldr r2, [r0]
	movs r0, 0x1
	str r0, [sp]
	movs r0, 0
	str r0, [sp, 0x4]
	adds r0, r5, 0
	adds r1, r6, 0
	movs r3, 0x1
	bl LowerAttackStageTarget
	b _0805AC86
	.align 2, 0
_0805AC30: .4byte gUnknown_8106A4C
_0805AC34:
	ldr r0, _0805AC4C
	ldr r2, [r0]
	movs r0, 0x1
	str r0, [sp]
	movs r0, 0
	str r0, [sp, 0x4]
	adds r0, r5, 0
	adds r1, r6, 0
	movs r3, 0x1
	bl LowerDefenseStageTarget
	b _0805AC86
	.align 2, 0
_0805AC4C: .4byte gUnknown_8106A4C
_0805AC50:
	ldr r0, _0805AC60
	ldr r2, [r0]
	adds r0, r5, 0
	adds r1, r6, 0
	movs r3, 0
	bl LowerAccuracyStageTarget
	b _0805AC86
	.align 2, 0
_0805AC60: .4byte gUnknown_8106A4C
_0805AC64:
	adds r0, r5, 0
	adds r1, r6, 0
	movs r2, 0
	bl ConfuseStatusTarget
	b _0805AC86
_0805AC70:
	adds r0, r5, 0
	adds r1, r6, 0
	movs r2, 0
	bl CringeStatusTarget
	b _0805AC86
_0805AC7C:
	adds r0, r5, 0
	adds r1, r6, 0
	movs r2, 0
	bl ParalyzeStatusTarget
_0805AC86:
	adds r0, r7, 0
	add sp, 0x8
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_805AB54

	thumb_func_start sub_805AC90
sub_805AC90:
	push {r4-r7,lr}
	sub sp, 0x4
	adds r5, r0, 0
	adds r6, r1, 0
	movs r7, 0
	movs r4, 0x80
	lsls r4, 1
	str r3, [sp]
	adds r3, r4, 0
	bl sub_8055640
	cmp r0, 0
	beq _0805ACCA
	movs r7, 0x1
	ldr r0, _0805ACD4
	movs r1, 0
	ldrsh r2, [r0, r1]
	adds r0, r5, 0
	adds r1, r6, 0
	bl sub_805727C
	lsls r0, 24
	cmp r0, 0
	beq _0805ACCA
	adds r0, r5, 0
	adds r1, r6, 0
	movs r2, 0
	bl ConfuseStatusTarget
_0805ACCA:
	adds r0, r7, 0
	add sp, 0x4
	pop {r4-r7}
	pop {r1}
	bx r1
	.align 2, 0
_0805ACD4: .4byte gUnknown_80F4DFA
	thumb_func_end sub_805AC90

	thumb_func_start sub_805ACD8
sub_805ACD8:
	push {r4-r6,lr}
	adds r5, r0, 0
	adds r6, r1, 0
	ldr r0, _0805AD00
	ldr r4, [r0]
	adds r0, r5, 0
	adds r2, r4, 0
	movs r3, 0x1
	bl RaiseAttackStageTarget
	adds r0, r5, 0
	adds r1, r6, 0
	adds r2, r4, 0
	movs r3, 0x1
	bl RaiseDefenseStageTarget
	movs r0, 0x1
	pop {r4-r6}
	pop {r1}
	bx r1
	.align 2, 0
_0805AD00: .4byte gUnknown_8106A4C
	thumb_func_end sub_805ACD8

	thumb_func_start sub_805AD04
sub_805AD04:
	push {r4,r5,lr}
	sub sp, 0x4
	adds r5, r0, 0
	adds r4, r1, 0
	ldr r1, _0805AD30
	adds r0, r4, 0
	movs r2, 0x1
	bl CalculateStatusTurns
	adds r3, r0, 0
	movs r0, 0x1
	str r0, [sp]
	adds r0, r5, 0
	adds r1, r4, 0
	movs r2, 0x1
	bl PausedStatusTarget
	movs r0, 0x1
	add sp, 0x4
	pop {r4,r5}
	pop {r1}
	bx r1
	.align 2, 0
_0805AD30: .4byte gUnknown_80F4EE0
	thumb_func_end sub_805AD04

	thumb_func_start sub_805AD34
sub_805AD34:
	push {lr}
	sub sp, 0x8
	ldr r2, _0805AD50
	ldr r2, [r2]
	movs r3, 0x1
	str r3, [sp]
	str r3, [sp, 0x4]
	movs r3, 0x2
	bl LowerAttackStageTarget
	movs r0, 0x1
	add sp, 0x8
	pop {r1}
	bx r1
	.align 2, 0
_0805AD50: .4byte gUnknown_8106A4C
	thumb_func_end sub_805AD34

	thumb_func_start sub_805AD54
sub_805AD54:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x4
	adds r5, r0, 0
	mov r9, r1
	movs r0, 0
	mov r10, r0
	ldr r1, [r5, 0x70]
	mov r8, r1
	ldrb r0, [r1, 0x6]
	cmp r0, 0
	beq _0805AD88
	ldr r0, _0805AD80
	ldr r0, [r0]
	ldr r1, _0805AD84
	adds r7, r0, r1
	movs r0, 0x10
	b _0805AD92
	.align 2, 0
_0805AD80: .4byte gDungeon
_0805AD84: .4byte 0x0001358c
_0805AD88:
	ldr r0, _0805AD98
	ldr r0, [r0]
	ldr r1, _0805AD9C
	adds r7, r0, r1
	movs r0, 0x4
_0805AD92:
	str r0, [sp]
	movs r6, 0
	b _0805AE0E
	.align 2, 0
_0805AD98: .4byte gDungeon
_0805AD9C: .4byte 0x0001357c
_0805ADA0:
	lsls r0, r6, 2
	adds r0, r7
	ldr r4, [r0]
	adds r0, r4, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	beq _0805AE0C
	cmp r5, r4
	beq _0805AE0C
	adds r0, r5, 0
	adds r1, r4, 0
	movs r2, 0
	movs r3, 0
	bl CanTarget
	lsls r0, 24
	cmp r0, 0
	bne _0805AE0C
	ldr r1, [r4, 0x70]
	adds r0, r1, 0
	adds r0, 0xA4
	ldrb r0, [r0]
	cmp r0, 0x1
	beq _0805AE0C
	adds r0, r1, 0
	adds r0, 0x40
	ldrb r0, [r0]
	cmp r0, 0x4A
	beq _0805ADE2
	cmp r0, 0x47
	bne _0805ADE6
_0805ADE2:
	movs r0, 0x1
	b _0805ADE8
_0805ADE6:
	movs r0, 0
_0805ADE8:
	cmp r0, 0
	bne _0805AE0C
	adds r0, r5, 0
	adds r1, r4, 0
	movs r2, 0x2
	mov r3, r9
	adds r3, 0x4
	bl sub_807D148
	movs r0, 0x1
	mov r10, r0
	mov r1, r8
	adds r1, 0xFB
	ldrb r0, [r1]
	cmp r0, 0
	bne _0805AE0C
	mov r0, r10
	strb r0, [r1]
_0805AE0C:
	adds r6, 0x1
_0805AE0E:
	ldr r1, [sp]
	cmp r6, r1
	blt _0805ADA0
	mov r0, r10
	cmp r0, 0
	bne _0805AE26
	ldr r0, _0805AE38
	ldr r2, [r0]
	adds r0, r5, 0
	mov r1, r9
	bl sub_80522F4
_0805AE26:
	mov r0, r10
	add sp, 0x4
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	.align 2, 0
_0805AE38: .4byte gUnknown_81004EC
	thumb_func_end sub_805AD54

	thumb_func_start sub_805AE3C
sub_805AE3C:
	push {r4-r6,lr}
	mov r6, r8
	push {r6}
	sub sp, 0x4
	adds r5, r0, 0
	adds r6, r1, 0
	mov r8, r2
	adds r4, r3, 0
	bl SendThawedMessage
	movs r3, 0x80
	lsls r3, 2
	str r4, [sp]
	adds r0, r5, 0
	adds r1, r6, 0
	mov r2, r8
	bl sub_8055640
	adds r1, r0, 0
	negs r0, r1
	orrs r0, r1
	lsrs r0, 31
	add sp, 0x4
	pop {r3}
	mov r8, r3
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end sub_805AE3C

	thumb_func_start sub_805AE74
sub_805AE74:
	push {r4-r7,lr}
	sub sp, 0x8
	adds r5, r0, 0
	adds r6, r1, 0
	movs r7, 0
	movs r4, 0x80
	lsls r4, 1
	str r3, [sp]
	adds r3, r4, 0
	bl sub_8055640
	cmp r0, 0
	beq _0805AEB8
	movs r7, 0x1
	ldr r0, _0805AEC4
	movs r1, 0
	ldrsh r2, [r0, r1]
	adds r0, r5, 0
	adds r1, r6, 0
	bl sub_805727C
	lsls r0, 24
	cmp r0, 0
	beq _0805AEB8
	ldr r0, _0805AEC8
	ldr r2, [r0]
	str r7, [sp]
	movs r0, 0
	str r0, [sp, 0x4]
	adds r0, r5, 0
	adds r1, r6, 0
	movs r3, 0x1
	bl LowerDefenseStageTarget
_0805AEB8:
	adds r0, r7, 0
	add sp, 0x8
	pop {r4-r7}
	pop {r1}
	bx r1
	.align 2, 0
_0805AEC4: .4byte gUnknown_80F4DDA
_0805AEC8: .4byte gUnknown_8106A4C
	thumb_func_end sub_805AE74

	thumb_func_start sub_805AECC
sub_805AECC:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0x4
	adds r6, r0, 0
	adds r7, r1, 0
	adds r5, r2, 0
	adds r4, r3, 0
	movs r0, 0
	mov r8, r0
	adds r0, r6, 0
	bl SendThawedMessage
	movs r3, 0x80
	lsls r3, 1
	str r4, [sp]
	adds r0, r6, 0
	adds r1, r7, 0
	adds r2, r5, 0
	bl sub_8055640
	cmp r0, 0
	beq _0805AF1E
	movs r1, 0x1
	mov r8, r1
	ldr r0, _0805AF2C
	movs r1, 0
	ldrsh r2, [r0, r1]
	adds r0, r6, 0
	adds r1, r7, 0
	bl sub_805727C
	lsls r0, 24
	cmp r0, 0
	beq _0805AF1E
	adds r0, r6, 0
	adds r1, r7, 0
	movs r2, 0
	movs r3, 0
	bl BurnedStatusTarget
_0805AF1E:
	mov r0, r8
	add sp, 0x4
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r1}
	bx r1
	.align 2, 0
_0805AF2C: .4byte gUnknown_80F4DFE
	thumb_func_end sub_805AECC

	thumb_func_start sub_805AF30
sub_805AF30:
	push {r4-r7,lr}
	sub sp, 0x4
	adds r7, r0, 0
	adds r5, r1, 0
	adds r6, r2, 0
	adds r4, r3, 0
	movs r0, 0x64
	bl DungeonRandInt
	adds r1, r0, 0
	cmp r0, 0x9
	bgt _0805AF54
	str r4, [sp]
	adds r0, r7, 0
	adds r1, r5, 0
	adds r2, r6, 0
	movs r3, 0x78
	b _0805AF92
_0805AF54:
	cmp r0, 0x1D
	bgt _0805AF78
	ldr r0, [r5, 0x70]
	movs r1, 0x10
	ldrsh r2, [r0, r1]
	cmp r2, 0
	bge _0805AF64
	adds r2, 0x3
_0805AF64:
	asrs r2, 2
	movs r0, 0x1
	str r0, [sp]
	adds r0, r7, 0
	adds r1, r5, 0
	movs r3, 0
	bl HealTargetHP
	movs r0, 0x1
	b _0805AF9C
_0805AF78:
	cmp r1, 0x3B
	bgt _0805AF88
	str r4, [sp]
	adds r0, r7, 0
	adds r1, r5, 0
	adds r2, r6, 0
	movs r3, 0x50
	b _0805AF92
_0805AF88:
	str r4, [sp]
	adds r0, r7, 0
	adds r1, r5, 0
	adds r2, r6, 0
	movs r3, 0x28
_0805AF92:
	bl sub_8055864
	negs r1, r0
	orrs r1, r0
	lsrs r0, r1, 31
_0805AF9C:
	add sp, 0x4
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_805AF30

        .align 2,0
