	#include "asm/constants/gba_constants.inc"
	#include "asm/macros.inc"

	.syntax unified

	.text



	thumb_func_start sub_8055A00
sub_8055A00:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x34
	adds r5, r0, 0
	mov r9, r1
	str r2, [sp, 0x20]
	str r3, [sp, 0x24]
	ldr r0, [r5, 0x70]
	mov r10, r0
	mov r7, r9
	cmp r7, 0x3
	ble _08055A22
	movs r0, 0
	b _08055DB4
_08055A22:
	movs r0, 0xBC
	lsls r0, 1
	add r0, r10
	movs r1, 0
	movs r2, 0
	strh r2, [r0]
	ldr r0, _08055A4C
	add r0, r10
	strb r1, [r0]
	mov r0, r10
	adds r0, 0xBC
	ldrb r0, [r0]
	cmp r0, 0x1
	bne _08055A58
	ldr r0, _08055A50
	adds r1, r5, 0
	bl SetMessageArgument
	ldr r0, _08055A54
	b _08055A8A
	.align 2, 0
_08055A4C: .4byte 0x00000159
_08055A50: .4byte gAvailablePokemonNames
_08055A54: .4byte gUnknown_80FC714
_08055A58:
	cmp r0, 0x7
	bne _08055A74
	ldr r0, _08055A6C
	adds r1, r5, 0
	movs r2, 0
	bl SetMessageArgument
	ldr r0, _08055A70
	b _08055A8A
	.align 2, 0
_08055A6C: .4byte gAvailablePokemonNames
_08055A70: .4byte gUnknown_80FC718
_08055A74:
	mov r0, r10
	adds r0, 0xAC
	ldrb r0, [r0]
	cmp r0, 0x4
	bne _08055AA0
	ldr r0, _08055A98
	adds r1, r5, 0
	movs r2, 0
	bl SetMessageArgument
	ldr r0, _08055A9C
_08055A8A:
	ldr r1, [r0]
	adds r0, r5, 0
	bl TryDisplayDungeonLoggableMessage
	movs r0, 0
	b _08055DB4
	.align 2, 0
_08055A98: .4byte gAvailablePokemonNames
_08055A9C: .4byte gUnknown_80FC6A8
_08055AA0:
	ldr r0, _08055B24
	strb r1, [r0]
	ldr r0, _08055B28
	str r2, [r0]
	ldr r0, _08055B2C
	strb r1, [r0]
	adds r0, r7, 0x1
	movs r2, 0
	movs r6, 0x3
	movs r1, 0xC0
	lsls r1, 1
	add r1, r10
_08055AB8:
	strh r2, [r1]
	subs r1, 0x2
	subs r6, 0x1
	cmp r6, 0
	bge _08055AB8
	movs r6, 0
	movs r3, 0x1
	adds r7, r0, 0
	cmp r7, 0x3
	bgt _08055B06
	lsls r2, r7, 3
	mov r1, r10
	adds r0, r1, r2
	movs r4, 0x8C
	lsls r4, 1
	adds r0, r4
	ldrb r1, [r0]
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	beq _08055B06
	movs r0, 0x2
	mov r8, r0
	adds r0, r2, r4
	mov r1, r10
	adds r2, r0, r1
_08055AEC:
	adds r6, 0x1
	cmp r6, 0x3
	bgt _08055B06
	adds r3, 0x1
	adds r2, 0x8
	adds r7, 0x1
	cmp r7, 0x3
	bgt _08055B06
	ldrb r1, [r2]
	mov r0, r8
	ands r0, r1
	cmp r0, 0
	bne _08055AEC
_08055B06:
	movs r0, 0
	str r0, [sp, 0x28]
	cmp r3, 0x1
	ble _08055B12
	movs r1, 0x1
	str r1, [sp, 0x28]
_08055B12:
	mov r7, r9
	lsls r0, r7, 3
	movs r1, 0x8C
	lsls r1, 1
	adds r0, r1
	add r0, r10
	mov r8, r0
	b _08055CB4
	.align 2, 0
_08055B24: .4byte gUnknown_202F222
_08055B28: .4byte gUnknown_202F208
_08055B2C: .4byte gUnknown_202F221
_08055B30:
	mov r1, r8
	ldrh r0, [r1, 0x2]
	cmp r0, 0x19
	beq _08055B3C
	cmp r0, 0xE3
	bne _08055B4E
_08055B3C:
	adds r0, r5, 0
	bl IsSleeping
	lsls r0, 24
	cmp r0, 0
	bne _08055B5E
	adds r0, r5, 0
	movs r1, 0x1
	b _08055B52
_08055B4E:
	adds r0, r5, 0
	movs r1, 0
_08055B52:
	bl CannotAttack
	lsls r0, 24
	cmp r0, 0
	beq _08055B5E
	b _08055CCE
_08055B5E:
	ldr r0, _08055B9C
	ldrb r0, [r0]
	cmp r0, 0
	beq _08055B68
	b _08055CCE
_08055B68:
	ldrb r1, [r6]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	bne _08055B74
	b _08055C82
_08055B74:
	movs r2, 0x1
	movs r0, 0
	str r0, [sp, 0x2C]
	adds r0, r5, 0
	adds r1, r6, 0
	str r2, [sp, 0x30]
	bl MoveMatchesChargingStatus
	lsls r0, 24
	lsrs r4, r0, 24
	ldrb r0, [r6, 0x4]
	ldr r2, [sp, 0x30]
	cmp r0, 0
	beq _08055BA0
	cmp r4, 0
	bne _08055BBA
	movs r1, 0x1
	str r1, [sp, 0x2C]
	b _08055BBA
	.align 2, 0
_08055B9C: .4byte gUnknown_202F221
_08055BA0:
	cmp r4, 0
	bne _08055BBA
	ldr r0, _08055C08
	adds r1, r6, 0
	movs r2, 0
	bl sub_80928C0
	ldr r0, _08055C0C
	ldr r1, [r0]
	adds r0, r5, 0
	bl TryDisplayDungeonLoggableMessage
	movs r2, 0
_08055BBA:
	cmp r2, 0
	beq _08055C82
	ldr r0, _08055C10
	ldr r0, [r0]
	mov r9, r0
	ldr r0, _08055C14
	add r0, r10
	strb r4, [r0]
	ldrh r0, [r6, 0x2]
	cmp r0, 0xE5
	bne _08055C20
	ldr r0, [r6]
	ldr r1, [r6, 0x4]
	str r0, [sp, 0x8]
	str r1, [sp, 0xC]
	adds r0, r5, 0
	bl sub_8057144
	lsls r0, 16
	ldr r2, _08055C18
	ldr r1, [sp, 0x8]
	ands r1, r2
	orrs r1, r0
	str r1, [sp, 0x8]
	ldr r0, _08055C08
	add r1, sp, 0x8
	movs r2, 0
	bl sub_80928C0
	ldr r0, _08055C1C
	ldr r1, [r0]
	adds r0, r5, 0
	bl TryDisplayDungeonLoggableMessage
	ldr r0, [sp, 0x28]
	str r0, [sp]
	add r1, sp, 0x8
	str r1, [sp, 0x4]
	b _08055C26
	.align 2, 0
_08055C08: .4byte gFormatItems
_08055C0C: .4byte gUnknown_80F93C8
_08055C10: .4byte gUnknown_202F208
_08055C14: .4byte 0x00000159
_08055C18: .4byte 0x0000ffff
_08055C1C: .4byte gUnknown_80FD2DC
_08055C20:
	ldr r0, [sp, 0x28]
	str r0, [sp]
	str r6, [sp, 0x4]
_08055C26:
	adds r0, r5, 0
	ldr r1, [sp, 0x20]
	ldr r2, [sp, 0x24]
	ldr r3, [sp, 0x54]
	bl sub_8055FA0
	lsls r0, 24
	lsrs r0, 24
	ldr r1, [sp, 0x2C]
	cmp r1, 0
	beq _08055C56
	cmp r0, 0
	beq _08055C56
	ldrb r1, [r6, 0x1]
	movs r0, 0x4
	ands r0, r1
	cmp r0, 0
	beq _08055C50
	movs r0, 0xFB
	ands r0, r1
	b _08055C54
_08055C50:
	movs r0, 0x8
	orrs r0, r1
_08055C54:
	strb r0, [r6, 0x1]
_08055C56:
	ldr r0, _08055C70
	ldr r0, [r0]
	cmp r9, r0
	bne _08055C82
	ldr r0, [sp, 0x24]
	cmp r0, 0
	bne _08055C78
	ldr r0, _08055C74
	ldr r1, [r0]
	adds r0, r5, 0
	bl TryDisplayDungeonLoggableMessage
	b _08055C82
	.align 2, 0
_08055C70: .4byte gUnknown_202F208
_08055C74: .4byte gUnknown_80FC690
_08055C78:
	ldr r0, _08055DC4
	ldr r1, [r0]
	adds r0, r5, 0
	bl TryDisplayDungeonLoggableMessage
_08055C82:
	movs r0, 0x1
	bl sub_804178C
	adds r0, r5, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	beq _08055CCE
	bl sub_8044B28
	lsls r0, 24
	cmp r0, 0
	bne _08055CCE
	movs r1, 0x8
	add r8, r1
	adds r7, 0x1
	cmp r7, 0x3
	bgt _08055CCE
	mov r0, r8
	ldrb r1, [r0]
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	beq _08055CCE
_08055CB4:
	mov r6, r8
	adds r0, r5, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	beq _08055CCE
	bl sub_8044B28
	lsls r0, 24
	cmp r0, 0
	bne _08055CCE
	b _08055B30
_08055CCE:
	adds r0, r5, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	beq _08055D54
	movs r6, 0
_08055CDC:
	lsls r0, r6, 1
	movs r1, 0xBD
	lsls r1, 1
	add r1, r10
	adds r1, r0
	ldrh r0, [r1]
	cmp r0, 0
	beq _08055D4E
	add r4, sp, 0x10
	adds r1, r0, 0
	adds r0, r4, 0
	bl sub_8092AA8
	ldrb r1, [r4]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _08055D48
	ldrh r0, [r4, 0x2]
	cmp r0, 0xE5
	bne _08055D36
	ldr r0, [sp, 0x10]
	ldr r1, [sp, 0x14]
	str r0, [sp, 0x18]
	str r1, [sp, 0x1C]
	adds r0, r5, 0
	bl sub_8057144
	lsls r0, 16
	ldr r2, _08055DC8
	ldr r1, [sp, 0x18]
	ands r1, r2
	orrs r1, r0
	str r1, [sp, 0x18]
	add r4, sp, 0x18
	ldr r0, _08055DCC
	adds r1, r4, 0
	movs r2, 0
	bl sub_80928C0
	ldr r0, _08055DD0
	ldr r1, [r0]
	adds r0, r5, 0
	bl TryDisplayDungeonLoggableMessage
_08055D36:
	ldr r1, [sp, 0x28]
	str r1, [sp]
	str r4, [sp, 0x4]
	adds r0, r5, 0
	movs r1, 0
	ldr r2, [sp, 0x24]
	ldr r3, [sp, 0x54]
	bl sub_8055FA0
_08055D48:
	movs r0, 0x1
	bl sub_804178C
_08055D4E:
	adds r6, 0x1
	cmp r6, 0x3
	ble _08055CDC
_08055D54:
	adds r0, r5, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	beq _08055DB2
	adds r0, r5, 0
	bl sub_8071DA4
	adds r0, r5, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	beq _08055DB2
	ldr r1, _08055DD4
	ldrb r0, [r1]
	cmp r0, 0
	beq _08055DB2
	movs r0, 0
	strb r0, [r1]
	adds r0, r5, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	beq _08055DB2
	ldr r4, [r5, 0x70]
	ldr r1, _08055DD8
	adds r0, r5, 0
	movs r2, 0x1
	bl CalculateStatusTurns
	adds r3, r0, 0
	movs r0, 0
	str r0, [sp]
	adds r0, r5, 0
	adds r1, r5, 0
	movs r2, 0x1
	bl PausedStatusTarget
	adds r4, 0xFB
	ldrb r0, [r4]
	cmp r0, 0
	bne _08055DB2
	movs r0, 0x1
	strb r0, [r4]
_08055DB2:
	movs r0, 0x1
_08055DB4:
	add sp, 0x34
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	.align 2, 0
_08055DC4: .4byte gUnknown_80FC6A4
_08055DC8: .4byte 0x0000ffff
_08055DCC: .4byte gFormatItems
_08055DD0: .4byte gUnknown_80FD2DC
_08055DD4: .4byte gUnknown_202F222
_08055DD8: .4byte gUnknown_80F4E70
	thumb_func_end sub_8055A00

	thumb_func_start sub_8055DDC
sub_8055DDC:
	push {r4-r7,lr}
	adds r4, r0, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	bne _08055DEC
	b _08055F62
_08055DEC:
	ldr r6, [r4, 0x70]
	movs r7, 0xBC
	lsls r7, 1
	adds r5, r6, r7
	ldrh r1, [r5]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _08055E10
	ldr r0, _08055F68
	ldr r1, [r0]
	adds r0, r4, 0
	bl TryDisplayDungeonLoggableMessage
	adds r0, r4, 0
	adds r1, r4, 0
	bl ImmobilizedStatusTarget
_08055E10:
	ldrh r1, [r5]
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	beq _08055E2C
	ldr r0, _08055F6C
	ldr r1, [r0]
	adds r0, r4, 0
	bl TryDisplayDungeonLoggableMessage
	adds r0, r4, 0
	adds r1, r4, 0
	bl ImmobilizedStatusTarget
_08055E2C:
	ldrh r1, [r5]
	movs r0, 0x4
	ands r0, r1
	cmp r0, 0
	beq _08055E48
	ldr r0, _08055F70
	ldr r1, [r0]
	adds r0, r4, 0
	bl TryDisplayDungeonLoggableMessage
	adds r0, r4, 0
	adds r1, r4, 0
	bl ImmobilizedStatusTarget
_08055E48:
	ldrh r1, [r5]
	movs r0, 0x8
	ands r0, r1
	cmp r0, 0
	beq _08055E66
	ldr r0, _08055F74
	ldr r1, [r0]
	adds r0, r4, 0
	bl TryDisplayDungeonLoggableMessage
	adds r0, r4, 0
	adds r1, r4, 0
	movs r2, 0x1
	bl ParalyzeStatusTarget
_08055E66:
	ldrh r1, [r5]
	movs r0, 0x10
	ands r0, r1
	cmp r0, 0
	beq _08055E84
	ldr r0, _08055F78
	ldr r1, [r0]
	adds r0, r4, 0
	bl TryDisplayDungeonLoggableMessage
	adds r0, r4, 0
	adds r1, r4, 0
	movs r2, 0x1
	bl ParalyzeStatusTarget
_08055E84:
	ldrh r1, [r5]
	movs r0, 0x20
	ands r0, r1
	cmp r0, 0
	beq _08055EA2
	ldr r0, _08055F7C
	ldr r1, [r0]
	adds r0, r4, 0
	bl TryDisplayDungeonLoggableMessage
	adds r0, r4, 0
	adds r1, r4, 0
	movs r2, 0x1
	bl PoisonedStatusTarget
_08055EA2:
	ldrh r1, [r5]
	movs r0, 0x40
	ands r0, r1
	cmp r0, 0
	beq _08055EC0
	ldr r0, _08055F80
	ldr r1, [r0]
	adds r0, r4, 0
	bl TryDisplayDungeonLoggableMessage
	adds r0, r4, 0
	adds r1, r4, 0
	movs r2, 0x1
	bl PoisonedStatusTarget
_08055EC0:
	ldrh r1, [r5]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	beq _08055EEA
	ldr r0, _08055F84
	ldr r1, [r0]
	adds r0, r4, 0
	bl TryDisplayDungeonLoggableMessage
	ldr r1, _08055F88
	adds r0, r4, 0
	movs r2, 0x1
	bl CalculateStatusTurns
	adds r2, r0, 0
	adds r0, r4, 0
	adds r1, r4, 0
	movs r3, 0x1
	bl sub_8075C58
_08055EEA:
	ldrh r1, [r5]
	movs r0, 0x80
	lsls r0, 1
	ands r0, r1
	cmp r0, 0
	beq _08055F0C
	ldr r0, _08055F8C
	ldr r1, [r0]
	adds r0, r4, 0
	bl TryDisplayDungeonLoggableMessage
	adds r0, r4, 0
	adds r1, r4, 0
	movs r2, 0x1
	movs r3, 0x1
	bl BurnedStatusTarget
_08055F0C:
	ldrh r1, [r5]
	movs r0, 0x80
	lsls r0, 2
	ands r0, r1
	cmp r0, 0
	beq _08055F2C
	ldr r0, _08055F90
	ldr r1, [r0]
	adds r0, r4, 0
	bl TryDisplayDungeonLoggableMessage
	adds r0, r4, 0
	adds r1, r4, 0
	movs r2, 0x1
	bl InfatuateStatusTarget
_08055F2C:
	adds r5, r6, r7
	ldrh r1, [r5]
	movs r0, 0x80
	lsls r0, 3
	ands r0, r1
	cmp r0, 0
	beq _08055F5E
	ldr r0, _08055F94
	adds r1, r4, 0
	movs r2, 0
	bl SetMessageArgument
	ldr r0, _08055F98
	ldr r1, [r0]
	adds r0, r4, 0
	bl TryDisplayDungeonLoggableMessage
	adds r0, r4, 0
	bl sub_80428A0
	ldr r0, _08055F9C
	ldrh r1, [r0]
	adds r0, r6, 0
	adds r0, 0xFA
	strb r1, [r0]
_08055F5E:
	movs r0, 0
	strh r0, [r5]
_08055F62:
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_08055F68: .4byte gUnknown_80FEEA4
_08055F6C: .4byte gUnknown_80FEEC8
_08055F70: .4byte gUnknown_80FEEEC
_08055F74: .4byte gUnknown_80FEF0C
_08055F78: .4byte gUnknown_80FEF30
_08055F7C: .4byte gUnknown_80FEF4C
_08055F80: .4byte gUnknown_80FEF50
_08055F84: .4byte gUnknown_80FEF54
_08055F88: .4byte gUnknown_80F4E74
_08055F8C: .4byte gUnknown_80FEF74
_08055F90: .4byte gUnknown_80FEF98
_08055F94: .4byte gAvailablePokemonNames
_08055F98: .4byte gUnknown_80FEFD0
_08055F9C: .4byte gUnknown_80F5004
	thumb_func_end sub_8055DDC

	thumb_func_start sub_8055FA0
sub_8055FA0:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x130
	adds r5, r0, 0
	adds r6, r1, 0
	mov r10, r2
	str r3, [sp, 0x120]
	ldr r7, [sp, 0x154]
	movs r0, 0
	mov r8, r0
	str r0, [sp, 0xC]
	movs r0, 0x1
	bl sub_804178C
	ldrh r1, [r7, 0x2]
	movs r0, 0xA5
	lsls r0, 1
	cmp r1, r0
	bne _08056010
	movs r0, 0x69
	bl DungeonRandInt
	ldr r1, _08056004
	str r0, [r1]
	add r4, sp, 0x110
	ldr r1, _08056008
	lsls r0, 3
	adds r0, r1
	ldrh r1, [r0]
	adds r0, r4, 0
	bl InitPokemonMove
	ldrb r1, [r7]
	add r0, sp, 0x110
	strb r1, [r0]
	ldrb r0, [r7, 0x1]
	strb r0, [r4, 0x1]
	ldr r0, _0805600C
	ldr r2, [r0]
	mov r1, r10
	str r1, [sp]
	movs r0, 0x1
	str r0, [sp, 0x4]
	mov r0, r8
	str r0, [sp, 0x8]
	b _08056056
	.align 2, 0
_08056004: .4byte gUnknown_202F228
_08056008: .4byte gUnknown_80F59C8
_0805600C: .4byte gUnknown_80FECBC
_08056010:
	cmp r1, 0x77
	bne _08056068
	ldr r0, _08056108
	ldr r0, [r0]
	ldr r1, _0805610C
	adds r0, r1
	movs r2, 0
	ldrsh r0, [r0, r2]
	cmp r0, 0
	bge _08056026
	movs r0, 0
_08056026:
	cmp r0, 0x4A
	ble _0805602C
	movs r0, 0x4A
_0805602C:
	add r4, sp, 0x118
	ldr r1, _08056110
	lsls r0, 3
	adds r0, r1
	ldrh r1, [r0]
	adds r0, r4, 0
	bl InitPokemonMove
	ldrb r1, [r7]
	add r0, sp, 0x118
	strb r1, [r0]
	ldrb r0, [r7, 0x1]
	strb r0, [r4, 0x1]
	ldr r0, _08056114
	ldr r2, [r0]
	mov r0, r10
	str r0, [sp]
	movs r0, 0x1
	str r0, [sp, 0x4]
	mov r1, r8
	str r1, [sp, 0x8]
_08056056:
	adds r0, r5, 0
	adds r1, r7, 0
	add r3, sp, 0xC
	bl sub_8056468
	movs r0, 0x1
	bl sub_804178C
	adds r7, r4, 0
_08056068:
	movs r2, 0
	str r2, [sp, 0x128]
	adds r0, r5, 0
	adds r1, r7, 0
	movs r2, 0x1
	bl GetMoveTargetAndRangeForPokemon
	movs r4, 0xF0
	adds r1, r4, 0
	ands r1, r0
	cmp r1, 0x50
	bne _08056084
	movs r0, 0xA
	str r0, [sp, 0x128]
_08056084:
	adds r0, r5, 0
	adds r1, r7, 0
	movs r2, 0x1
	bl GetMoveTargetAndRangeForPokemon
	adds r1, r4, 0
	ands r1, r0
	cmp r1, 0x80
	bne _080560CC
	movs r1, 0x1
	str r1, [sp, 0x128]
	ldrh r0, [r7, 0x2]
	cmp r0, 0x97
	bne _080560AE
	adds r0, r5, 0
	bl GetApparentWeather
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	beq _080560CC
_080560AE:
	ldrh r0, [r7, 0x2]
	bl DoesMoveCharge
	lsls r0, 24
	cmp r0, 0
	beq _080560CC
	adds r0, r5, 0
	adds r1, r7, 0
	bl MoveMatchesChargingStatus
	lsls r0, 24
	cmp r0, 0
	bne _080560CC
	movs r2, 0
	str r2, [sp, 0x128]
_080560CC:
	ldr r0, _08056118
	ldr r1, [r5, 0x70]
	movs r2, 0
	bl SetMessageArgument_2
	ldr r0, _0805611C
	adds r1, r7, 0
	movs r2, 0
	bl sub_80928C0
	adds r0, r5, 0
	adds r1, r7, 0
	bl MoveMatchesChargingStatus
	lsls r0, 24
	cmp r0, 0
	beq _08056124
	ldr r0, _08056120
	ldr r0, [r0]
	mov r8, r0
	ldr r0, [r5, 0x70]
	adds r0, 0xFF
	movs r1, 0
	strb r1, [r0]
	adds r0, r5, 0
	adds r1, r7, 0
	movs r2, 0x1
	bl sub_805744C
	b _08056142
	.align 2, 0
_08056108: .4byte gDungeon
_0805610C: .4byte 0x00003a0e
_08056110: .4byte gNaturePowerMoveTable
_08056114: .4byte gUnknown_80FECE0
_08056118: .4byte gAvailablePokemonNames
_0805611C: .4byte gFormatItems
_08056120: .4byte gUnknown_80FC72C
_08056124:
	mov r0, r10
	cmp r0, 0
	bne _08056132
	ldrh r0, [r7, 0x2]
	bl GetMoveUseText
	b _08056136
_08056132:
	ldr r0, _08056194
	ldr r0, [r0]
_08056136:
	mov r8, r0
	adds r0, r5, 0
	adds r1, r7, 0
	movs r2, 0x1
	bl CanMonsterUseMove
_08056142:
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0
	beq _08056156
	cmp r6, 0
	beq _08056156
	adds r0, r5, 0
	adds r1, r7, 0
	bl sub_806ACE8
_08056156:
	ldr r0, [r5, 0x70]
	adds r0, 0xEC
	ldrb r0, [r0]
	cmp r0, 0x1
	bne _080561A0
	ldrh r0, [r7, 0x2]
	bl FailsWhileMuzzled
	lsls r0, 24
	cmp r0, 0
	beq _080561A0
	ldr r0, _08056198
	adds r1, r5, 0
	movs r2, 0
	bl SetMessageArgument
	adds r0, r5, 0
	mov r1, r8
	bl TryDisplayDungeonLoggableMessage
	movs r0, 0xA
	movs r1, 0x3F
	bl sub_803E708
	ldr r0, _0805619C
_08056188:
	ldr r1, [r0]
	adds r0, r5, 0
	bl TryDisplayDungeonLoggableMessage
_08056190:
	movs r0, 0
	b _08056446
	.align 2, 0
_08056194: .4byte gUnknown_80F9158
_08056198: .4byte gAvailablePokemonNames
_0805619C: .4byte gUnknown_80FC710
_080561A0:
	cmp r4, 0
	bne _08056214
	ldr r0, _080561D4
	ldr r1, [r5, 0x70]
	movs r2, 0
	bl SetMessageArgument_2
	mov r1, r10
	cmp r1, 0
	bne _080561E0
	ldr r0, _080561D8
	adds r1, r7, 0
	movs r2, 0
	bl sub_80928C0
	adds r0, r5, 0
	mov r1, r8
	bl TryDisplayDungeonLoggableMessage
	movs r0, 0xA
	movs r1, 0x3F
	bl sub_803E708
	ldr r0, _080561DC
	b _08056188
	.align 2, 0
_080561D4: .4byte gAvailablePokemonNames
_080561D8: .4byte gFormatItems
_080561DC: .4byte gUnknown_80FC6D0
_080561E0:
	ldr r0, _0805620C
	mov r2, r10
	lsls r1, r2, 24
	lsrs r1, 24
	movs r2, 0
	bl BufferItemName
	adds r0, r5, 0
	mov r1, r8
	bl TryDisplayDungeonLoggableMessage
	movs r0, 0xA
	movs r1, 0x3F
	bl sub_803E708
	ldr r0, _08056210
	ldr r1, [r0]
	adds r0, r5, 0
	bl TryDisplayDungeonLoggableMessage
	b _08056190
	.align 2, 0
_0805620C: .4byte gFormatItems
_08056210: .4byte gUnknown_80FC6FC
_08056214:
	ldr r0, _0805625C
	movs r1, 0
	str r1, [r0]
	ldr r0, _08056260
	str r1, [r0]
	ldr r0, _08056264
	str r1, [r0]
	ldr r0, _08056268
	strb r1, [r0]
	ldr r0, _0805626C
	strb r1, [r0]
	ldr r0, _08056270
	strb r1, [r0]
	ldr r0, _08056274
	str r1, [r0]
	ldr r0, _08056278
	strb r1, [r0]
	ldr r0, [sp, 0x150]
	cmp r0, 0
	beq _0805624C
	ldr r0, [r5, 0x70]
	ldr r2, _0805627C
	adds r1, r0, r2
	ldrb r0, [r1]
	cmp r0, 0x3
	bhi _0805624C
	adds r0, 0x1
	strb r0, [r1]
_0805624C:
	adds r0, r7, 0
	bl sub_8057070
	str r0, [sp, 0x124]
	movs r0, 0
	mov r9, r0
	b _080563E4
	.align 2, 0
_0805625C: .4byte gUnknown_202F214
_08056260: .4byte gUnknown_202F20C
_08056264: .4byte gUnknown_202F210
_08056268: .4byte gUnknown_202F218
_0805626C: .4byte gUnknown_202F219
_08056270: .4byte gUnknown_202F21A
_08056274: .4byte gUnknown_202F21C
_08056278: .4byte gUnknown_202F220
_0805627C: .4byte 0x00000153
_08056280:
	adds r0, r5, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	bne _0805628E
	b _08056444
_0805628E:
	bl sub_8044B28
	lsls r0, 24
	cmp r0, 0
	beq _0805629A
	b _08056444
_0805629A:
	ldr r4, [r5, 0x70]
	ldr r0, [sp, 0x120]
	cmp r0, 0
	bne _080562AC
	ldrh r0, [r7, 0x2]
	cmp r0, 0x19
	beq _080562AC
	cmp r0, 0xE3
	bne _080562BE
_080562AC:
	adds r0, r5, 0
	bl IsSleeping
	lsls r0, 24
	cmp r0, 0
	bne _080562CE
	adds r0, r5, 0
	movs r1, 0x1
	b _080562C2
_080562BE:
	adds r0, r5, 0
	movs r1, 0
_080562C2:
	bl CannotAttack
	lsls r0, 24
	cmp r0, 0
	beq _080562CE
	b _08056400
_080562CE:
	movs r1, 0xA5
	lsls r1, 1
	adds r0, r4, r1
	movs r6, 0
	strb r6, [r0]
	ldrh r0, [r7, 0x2]
	cmp r0, 0x9
	bne _080562F4
	ldr r4, [r5, 0x70]
	movs r0, 0x8
	bl DungeonRandInt
	adds r4, 0x46
	strb r0, [r4]
	adds r0, r5, 0
	bl TargetTileInFront
	movs r2, 0
	str r2, [sp, 0x12C]
_080562F4:
	ldr r0, _080563A0
	str r6, [r0]
	str r6, [sp, 0xC]
	ldr r0, [sp, 0x128]
	cmp r0, 0x1
	bhi _08056324
	add r0, sp, 0xC
	adds r1, r5, 0
	adds r2, r7, 0
	bl sub_8056CE8
	add r0, sp, 0xC
	adds r1, r5, 0
	bl sub_80574C4
	mov r1, r9
	cmp r1, 0
	beq _08056324
	ldr r2, [sp, 0x12C]
	cmp r2, 0
	beq _08056324
	ldr r0, [sp, 0xC]
	cmp r0, 0
	beq _08056400
_08056324:
	mov r0, r10
	str r0, [sp]
	movs r0, 0
	mov r1, r9
	cmp r1, 0
	bne _08056332
	movs r0, 0x1
_08056332:
	str r0, [sp, 0x4]
	ldr r2, [sp, 0x128]
	str r2, [sp, 0x8]
	adds r0, r5, 0
	adds r1, r7, 0
	mov r2, r8
	add r3, sp, 0xC
	bl sub_8056468
	lsls r0, 24
	lsrs r4, r0, 24
	movs r0, 0
	mov r8, r0
	ldr r0, _080563A0
	ldr r0, [r0]
	cmp r0, 0
	beq _08056358
	bl sub_806A1E8
_08056358:
	ldr r1, [r5, 0x70]
	adds r0, r1, 0
	adds r0, 0xBC
	ldrb r0, [r0]
	cmp r0, 0x2
	beq _0805637C
	cmp r0, 0x4
	beq _0805637C
	movs r2, 0xB6
	lsls r2, 1
	adds r0, r1, r2
	mov r2, r8
	strh r2, [r0]
	movs r2, 0xB7
	lsls r2, 1
	adds r0, r1, r2
	mov r1, r8
	strh r1, [r0]
_0805637C:
	ldr r1, _080563A4
	ldr r0, [r1]
	adds r0, 0x1
	str r0, [r1]
	ldr r2, [sp, 0x128]
	cmp r2, 0
	beq _080563A8
	mov r0, r10
	str r0, [sp]
	ldr r1, [sp, 0x150]
	str r1, [sp, 0x4]
	adds r0, r5, 0
	adds r1, r7, 0
	adds r3, r4, 0
	bl sub_80566F8
	b _080563B8
	.align 2, 0
_080563A0: .4byte gUnknown_203B438
_080563A4: .4byte gUnknown_202F214
_080563A8:
	ldr r2, [sp, 0x150]
	str r2, [sp]
	add r0, sp, 0xC
	adds r1, r5, 0
	adds r2, r7, 0
	mov r3, r10
	bl sub_8053704
_080563B8:
	adds r0, r5, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	beq _08056400
	adds r0, r5, 0
	bl sub_806CF18
	ldr r0, [r5, 0x70]
	movs r2, 0xA5
	lsls r2, 1
	adds r1, r0, r2
	ldrb r0, [r1]
	cmp r0, 0
	bne _080563E0
	strb r0, [r1]
	adds r0, r5, 0
	bl sub_8079764
_080563E0:
	movs r0, 0x1
	add r9, r0
_080563E4:
	ldr r1, [sp, 0x124]
	cmp r9, r1
	bge _08056400
	movs r2, 0x1
	str r2, [sp, 0x12C]
	ldr r0, _08056458
	ldrb r0, [r0]
	cmp r0, 0
	bne _08056400
	ldr r0, _0805645C
	ldrb r0, [r0]
	cmp r0, 0
	bne _08056400
	b _08056280
_08056400:
	ldr r0, _08056460
	ldrb r0, [r0]
	cmp r0, 0
	beq _08056418
	adds r0, r5, 0
	adds r1, r5, 0
	bl SendImmobilizeEndMessage
	adds r0, r5, 0
	adds r1, r5, 0
	bl SendLinkedEndMessage
_08056418:
	ldr r0, _08056464
	ldrb r0, [r0]
	cmp r0, 0
	beq _08056444
	adds r0, r5, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	beq _08056444
	ldr r4, [r5, 0x70]
	adds r0, r5, 0
	adds r1, r5, 0
	movs r2, 0
	bl ConfuseStatusTarget
	adds r4, 0xFB
	ldrb r0, [r4]
	cmp r0, 0
	bne _08056444
	movs r0, 0x1
	strb r0, [r4]
_08056444:
	movs r0, 0x1
_08056446:
	add sp, 0x130
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	.align 2, 0
_08056458: .4byte gUnknown_202F220
_0805645C: .4byte gUnknown_202F221
_08056460: .4byte gUnknown_202F21A
_08056464: .4byte gUnknown_202F219
	thumb_func_end sub_8055FA0

	thumb_func_start sub_8056468
sub_8056468:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x4
	adds r6, r0, 0
	mov r8, r1
	mov r9, r2
	adds r4, r3, 0
	ldr r0, [sp, 0x28]
	lsls r0, 24
	lsrs r0, 24
	str r0, [sp]
	movs r0, 0
	mov r10, r0
	adds r0, r6, 0
	bl sub_8045888
	lsls r0, 24
	lsrs r0, 24
	negs r1, r0
	orrs r1, r0
	lsrs r7, r1, 31
	mov r2, r9
	cmp r2, 0
	beq _08056518
	movs r5, 0
	b _080564A6
_080564A2:
	adds r4, 0x4
	adds r5, 0x1
_080564A6:
	cmp r5, 0x40
	bgt _080564BC
	ldr r0, [r4]
	cmp r0, 0
	beq _080564BC
	bl sub_8045888
	lsls r0, 24
	cmp r0, 0
	beq _080564A2
	movs r7, 0x1
_080564BC:
	cmp r7, 0
	beq _080564F2
	ldr r0, _080564DC
	ldr r1, [r6, 0x70]
	movs r2, 0
	bl SetMessageArgument_2
	ldr r0, [sp, 0x24]
	cmp r0, 0
	bne _080564E4
	ldr r0, _080564E0
	mov r1, r8
	movs r2, 0
	bl sub_80928C0
	b _080564F2
	.align 2, 0
_080564DC: .4byte gAvailablePokemonNames
_080564E0: .4byte gFormatItems
_080564E4:
	ldr r0, _08056508
	ldr r2, [sp, 0x24]
	lsls r1, r2, 24
	lsrs r1, 24
	movs r2, 0
	bl BufferItemName
_080564F2:
	mov r0, r8
	ldrh r1, [r0, 0x2]
	ldr r0, _0805650C
	cmp r1, r0
	beq _08056510
	adds r0, r6, 0
	mov r1, r9
	bl DisplayDungeonLoggableMessageTrue
	b _08056518
	.align 2, 0
_08056508: .4byte gFormatItems
_0805650C: .4byte 0x00000163
_08056510:
	adds r0, r6, 0
	mov r1, r9
	bl DisplayDungeonLoggableMessageFalse
_08056518:
	cmp r7, 0
	beq _08056544
	ldr r2, [sp]
	cmp r2, 0
	beq _0805652A
	adds r0, r6, 0
	mov r1, r8
	movs r2, 0x1
	b _08056530
_0805652A:
	adds r0, r6, 0
	mov r1, r8
	movs r2, 0
_08056530:
	bl sub_8040BB0
	lsls r0, 24
	lsrs r0, 24
	mov r10, r0
	adds r0, r6, 0
	mov r1, r8
	bl sub_8040DA0
	b _08056550
_08056544:
	ldr r0, [r6, 0x70]
	adds r0, 0x46
	ldrb r1, [r0]
	adds r0, r6, 0
	bl sub_806CE68
_08056550:
	mov r0, r10
	add sp, 0x4
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_8056468

	thumb_func_start sub_8056564
sub_8056564:
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	sub sp, 0x18
	adds r6, r0, 0
	adds r5, r1, 0
	adds r7, r2, 0
	adds r4, r3, 0
	ldr r0, [r6, 0x70]
	mov r8, r0
	ldr r0, _08056680
	ldr r0, [r0]
	ldr r1, _08056684
	adds r0, r1
	ldrb r0, [r0]
	mov r9, r0
	cmp r0, 0
	beq _0805658C
	b _080566E4
_0805658C:
	mov r2, r8
	movs r1, 0x4
	ldrsh r0, [r2, r1]
	bl GetBodySize
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x3
	bls _080565A4
	cmp r4, 0x1
	bne _080565A4
	b _080566E4
_080565A4:
	ldrh r4, [r7, 0x2]
	adds r0, r6, 0
	bl GetApparentWeather
	adds r1, r0, 0
	lsls r1, 24
	lsrs r1, 24
	adds r0, r4, 0
	movs r2, 0x1
	bl sub_80412E0
	lsls r0, 16
	lsrs r0, 16
	bl sub_800ECB8
	movs r2, 0x6
	ldrsh r4, [r0, r2]
	movs r1, 0
	ldrsh r0, [r5, r1]
	lsls r1, r0, 1
	adds r1, r0
	lsls r1, 11
	movs r0, 0x2
	ldrsh r2, [r5, r0]
	lsls r0, r2, 1
	adds r0, r2
	lsls r0, 11
	movs r2, 0x80
	lsls r2, 5
	adds r3, r0, r2
	movs r2, 0xC0
	lsls r2, 4
	adds r0, r1, r2
	cmp r0, 0
	bge _080565EC
	adds r0, 0xFF
_080565EC:
	lsls r0, 8
	lsrs r0, 16
	ldr r1, _08056688
	ldr r2, [sp, 0x14]
	ands r2, r1
	orrs r2, r0
	str r2, [sp, 0x14]
	adds r0, r3, 0
	cmp r0, 0
	bge _08056602
	adds r0, 0xFF
_08056602:
	lsls r0, 8
	lsrs r0, 16
	lsls r0, 16
	ldr r1, _0805668C
	ands r2, r1
	orrs r2, r0
	str r2, [sp, 0x14]
	cmp r4, 0
	beq _080566E4
	ldrh r4, [r7, 0x2]
	adds r0, r6, 0
	bl GetApparentWeather
	adds r1, r0, 0
	lsls r1, 24
	lsrs r1, 24
	adds r0, r4, 0
	movs r2, 0x1
	bl sub_80412E0
	lsls r0, 16
	lsrs r0, 16
	bl sub_800EF10
	bl sub_800EF64
	movs r0, 0x5E
	bl sub_803E46C
	mov r0, r8
	movs r1, 0x4
	ldrsh r5, [r0, r1]
	ldrh r4, [r7, 0x2]
	adds r0, r6, 0
	bl GetApparentWeather
	adds r1, r0, 0
	lsls r1, 24
	lsrs r1, 24
	adds r0, r4, 0
	movs r2, 0x1
	bl sub_80412E0
	adds r1, r0, 0
	lsls r1, 16
	lsrs r1, 16
	adds r0, r5, 0
	bl sub_800E710
	adds r2, r0, 0
	movs r0, 0x1
	negs r0, r0
	cmp r2, r0
	beq _08056690
	add r0, sp, 0x8
	adds r1, r6, 0
	adds r1, 0x28
	lsls r2, 24
	lsrs r2, 24
	bl sub_800569C
	b _08056694
	.align 2, 0
_08056680: .4byte gDungeon
_08056684: .4byte 0x0001820a
_08056688: .4byte 0xffff0000
_0805668C: .4byte 0x0000ffff
_08056690:
	mov r2, r9
	str r2, [sp, 0x8]
_08056694:
	ldrh r4, [r7, 0x2]
	adds r0, r6, 0
	bl GetApparentWeather
	adds r1, r0, 0
	lsls r1, 24
	lsrs r1, 24
	adds r0, r4, 0
	movs r2, 0x1
	bl sub_80412E0
	mov r1, sp
	strh r0, [r1]
	mov r2, r8
	ldrh r0, [r2, 0x4]
	strh r0, [r1, 0x2]
	ldr r0, [r6, 0xC]
	cmp r0, 0
	bge _080566BC
	adds r0, 0xFF
_080566BC:
	asrs r0, 8
	strh r0, [r1, 0x4]
	mov r1, sp
	ldr r0, [r6, 0x10]
	cmp r0, 0
	bge _080566CA
	adds r0, 0xFF
_080566CA:
	asrs r0, 8
	strh r0, [r1, 0x6]
	mov r0, r8
	adds r0, 0x46
	ldrb r0, [r0]
	str r0, [sp, 0xC]
	movs r0, 0
	str r0, [sp, 0x10]
	add r1, sp, 0x14
	mov r0, sp
	bl sub_800E308
	b _080566E8
_080566E4:
	movs r0, 0x1
	negs r0, r0
_080566E8:
	add sp, 0x18
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_8056564

	thumb_func_start sub_80566F8
sub_80566F8:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x54
	mov r10, r0
	str r1, [sp, 0x1C]
	str r2, [sp, 0x20]
	lsls r3, 24
	lsrs r3, 24
	str r3, [sp, 0x24]
	movs r0, 0
	str r0, [sp, 0x34]
	movs r7, 0
	mov r1, r10
	ldr r6, [r1, 0x70]
	ldr r2, [sp, 0x1C]
	ldrh r0, [r2, 0x2]
	bl sub_800ED20
	movs r1, 0x2
	str r1, [sp, 0x44]
	cmp r0, 0x1
	beq _08056736
	movs r2, 0x6
	str r2, [sp, 0x44]
	cmp r0, 0x2
	bne _08056736
	movs r0, 0x3
	str r0, [sp, 0x44]
_08056736:
	mov r1, r10
	ldrh r0, [r1, 0x6]
	lsls r0, 16
	ldrh r3, [r1, 0x4]
	orrs r3, r0
	str r3, [sp, 0xC]
	ldr r1, _08056814
	adds r2, r6, 0
	adds r2, 0x46
	ldrb r0, [r2]
	lsls r0, 2
	adds r0, r1
	movs r1, 0
	ldrsh r6, [r0, r1]
	str r6, [sp, 0x28]
	movs r1, 0x2
	ldrsh r6, [r0, r1]
	str r6, [sp, 0x2C]
	movs r6, 0
	str r6, [sp, 0x30]
	mov r8, r2
	ldr r0, [sp, 0x20]
	cmp r6, r0
	bge _080567EC
	add r0, sp, 0xC
	movs r2, 0
	ldrsh r1, [r0, r2]
	cmp r1, 0
	blt _080567EC
	asrs r0, r3, 16
	cmp r0, 0
	blt _080567EC
	cmp r1, 0x37
	bgt _080567EC
	cmp r0, 0x1F
	bgt _080567EC
	add r6, sp, 0xC
_08056780:
	ldrh r0, [r6]
	ldr r1, [sp, 0x28]
	adds r0, r1
	lsls r0, 16
	lsrs r0, 16
	ldr r2, _08056818
	ands r2, r3
	orrs r2, r0
	asrs r0, r2, 16
	ldr r1, [sp, 0x2C]
	adds r0, r1
	lsls r0, 16
	ldr r1, _0805681C
	ands r1, r2
	orrs r1, r0
	str r1, [sp, 0xC]
	adds r7, 0x1
	movs r2, 0
	ldrsh r0, [r6, r2]
	asrs r1, 16
	bl GetTile
	adds r2, r0, 0
	ldrh r1, [r2]
	movs r0, 0x3
	ands r0, r1
	cmp r0, 0
	beq _080567EC
	ldr r0, [r2, 0x10]
	cmp r0, 0
	beq _080567C6
	bl GetEntityType
	cmp r0, 0x1
	beq _080567EC
_080567C6:
	ldr r0, [sp, 0x30]
	adds r0, 0x1
	str r0, [sp, 0x30]
	ldr r1, [sp, 0x20]
	cmp r0, r1
	bge _080567EC
	movs r0, 0
	ldrsh r2, [r6, r0]
	cmp r2, 0
	blt _080567EC
	ldr r0, [sp, 0xC]
	asrs r1, r0, 16
	adds r3, r0, 0
	cmp r1, 0
	blt _080567EC
	cmp r2, 0x37
	bgt _080567EC
	cmp r1, 0x1F
	ble _08056780
_080567EC:
	ldr r2, [sp, 0x1C]
	ldrh r1, [r2, 0x2]
	mov r0, r10
	bl sub_805755C
	lsls r0, 24
	cmp r0, 0
	beq _08056820
	mov r0, r10
	ldr r1, [sp, 0x1C]
	bl MoveMatchesChargingStatus
	lsls r0, 24
	cmp r0, 0
	bne _08056820
	movs r6, 0x1
	negs r6, r6
	str r6, [sp, 0x40]
	b _0805682E
	.align 2, 0
_08056814: .4byte gAdjacentTileOffsets
_08056818: .4byte 0xffff0000
_0805681C: .4byte 0x0000ffff
_08056820:
	mov r0, r10
	add r1, sp, 0xC
	ldr r2, [sp, 0x1C]
	ldr r3, [sp, 0x20]
	bl sub_8056564
	str r0, [sp, 0x40]
_0805682E:
	mov r0, r10
	ldrh r1, [r0, 0x4]
	add r0, sp, 0xC
	strh r1, [r0]
	mov r2, r10
	ldrh r1, [r2, 0x6]
	strh r1, [r0, 0x2]
	ldr r1, _08056874
	mov r6, r8
	ldrb r0, [r6]
	lsls r0, 2
	adds r0, r1
	movs r2, 0
	ldrsh r1, [r0, r2]
	str r1, [sp, 0x28]
	movs r1, 0x2
	ldrsh r6, [r0, r1]
	str r6, [sp, 0x2C]
	movs r0, 0x18
	ldr r1, [sp, 0x44]
	bl __divsi3
	adds r1, r7, 0
	muls r1, r0
	ldr r2, [sp, 0x20]
	cmp r2, 0x1
	ble _08056878
	adds r6, r1, 0
	adds r6, 0x8
	str r6, [sp, 0x38]
	cmp r6, 0x3F
	ble _0805687C
	movs r0, 0x40
	str r0, [sp, 0x38]
	b _0805687C
	.align 2, 0
_08056874: .4byte gAdjacentTileOffsets
_08056878:
	movs r2, 0x20
	str r2, [sp, 0x38]
_0805687C:
	movs r6, 0
	mov r9, r6
	movs r0, 0x80
	lsls r0, 12
	bl __divsi3
	str r0, [sp, 0x48]
	ldr r1, _0805696C
	mov r2, r8
	ldrb r0, [r2]
	lsls r0, 2
	adds r0, r1
	ldr r0, [r0]
	str r0, [sp, 0x3C]
	ldr r0, _08056970
	ldr r0, [r0]
	ldr r6, _08056974
	adds r0, r6
	movs r1, 0x1
	strb r1, [r0]
	movs r0, 0
	str r0, [sp, 0x30]
	ldr r1, [sp, 0x20]
	cmp r0, r1
	blt _080568B0
	b _08056AB6
_080568B0:
	add r0, sp, 0xC
	movs r2, 0
	ldrsh r1, [r0, r2]
	cmp r1, 0
	bge _080568BC
	b _08056AB6
_080568BC:
	ldrh r0, [r0, 0x2]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0
	bge _080568C8
	b _08056AB6
_080568C8:
	cmp r1, 0x37
	ble _080568CE
	b _08056AB6
_080568CE:
	cmp r0, 0x1F
	ble _080568D4
	b _08056AB6
_080568D4:
	add r7, sp, 0xC
_080568D6:
	ldr r6, [sp, 0xC]
	ldrh r0, [r7]
	ldr r1, [sp, 0x28]
	adds r0, r1
	strh r0, [r7]
	ldrh r0, [r7, 0x2]
	ldr r2, [sp, 0x2C]
	adds r0, r2
	strh r0, [r7, 0x2]
	add r0, sp, 0xC
	bl sub_803F428
	lsls r0, 24
	cmp r0, 0
	bne _080568F6
	b _08056A00
_080568F6:
	ldr r0, _08056970
	ldr r0, [r0]
	ldr r1, _08056978
	adds r0, r1
	ldrb r0, [r0]
	cmp r0, 0
	beq _08056906
	b _08056A00
_08056906:
	lsls r1, r6, 16
	asrs r1, 16
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 11
	movs r2, 0xC0
	lsls r2, 4
	adds r4, r0, r2
	asrs r1, r6, 16
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 11
	movs r6, 0x80
	lsls r6, 5
	adds r5, r0, r6
	ldr r1, [sp, 0x28]
	lsls r0, r1, 8
	ldr r6, [sp, 0x44]
	adds r2, r6, 0
	muls r2, r0
	str r2, [sp, 0x4C]
	ldr r1, [sp, 0x2C]
	lsls r0, r1, 8
	adds r2, r6, 0
	muls r2, r0
	str r2, [sp, 0x50]
	movs r6, 0
	movs r0, 0x18
	ldr r1, [sp, 0x44]
	bl __divsi3
	mov r8, r0
	cmp r6, r8
	bge _08056A0E
_0805694A:
	ldr r0, [sp, 0x40]
	cmp r0, 0
	blt _080569D4
	ldr r1, [sp, 0x24]
	cmp r1, 0
	beq _0805697C
	mov r0, r9
	cmp r0, 0
	bge _0805695E
	adds r0, 0xFF
_0805695E:
	asrs r0, 8
	bl sin_abs_4096
	ldr r2, [sp, 0x38]
	adds r3, r0, 0
	muls r3, r2
	b _0805697E
	.align 2, 0
_0805696C: .4byte gUnknown_81069D4
_08056970: .4byte gDungeon
_08056974: .4byte 0x0001c05e
_08056978: .4byte 0x0001820a
_0805697C:
	movs r3, 0
_0805697E:
	adds r0, r4, 0
	cmp r4, 0
	bge _08056986
	adds r0, 0xFF
_08056986:
	lsls r0, 8
	lsrs r0, 16
	ldr r1, _080569F0
	ldr r2, [sp, 0x10]
	ands r2, r1
	orrs r2, r0
	str r2, [sp, 0x10]
	subs r0, r5, r3
	cmp r0, 0
	bge _0805699C
	adds r0, 0xFF
_0805699C:
	lsls r0, 8
	lsrs r0, 16
	lsls r0, 16
	ldr r1, _080569F4
	ands r2, r1
	orrs r2, r0
	str r2, [sp, 0x10]
	adds r2, r5, 0
	cmp r2, 0
	bge _080569B2
	adds r2, 0xFF
_080569B2:
	asrs r2, 8
	ldr r0, _080569F8
	ldr r0, [r0]
	ldr r1, _080569FC
	adds r0, r1
	movs r1, 0
	ldrsh r0, [r0, r1]
	subs r2, r0
	lsrs r0, r2, 31
	adds r2, r0
	asrs r2, 1
	ldr r0, [sp, 0x3C]
	adds r2, r0
	ldr r0, [sp, 0x40]
	add r1, sp, 0x10
	bl sub_800E3AC
_080569D4:
	movs r0, 0x30
	bl sub_803E46C
	ldr r1, [sp, 0x4C]
	adds r4, r1
	ldr r2, [sp, 0x50]
	adds r5, r2
	ldr r0, [sp, 0x48]
	add r9, r0
	adds r6, 0x1
	cmp r6, r8
	blt _0805694A
	b _08056A0E
	.align 2, 0
_080569F0: .4byte 0xffff0000
_080569F4: .4byte 0x0000ffff
_080569F8: .4byte gDungeon
_080569FC: .4byte 0x000181f2
_08056A00:
	movs r0, 0x18
	ldr r1, [sp, 0x44]
	bl __divsi3
	ldr r1, [sp, 0x48]
	muls r0, r1
	add r9, r0
_08056A0E:
	movs r2, 0
	ldrsh r0, [r7, r2]
	movs r6, 0x2
	ldrsh r1, [r7, r6]
	bl GetTile
	adds r6, r0, 0
	ldrh r1, [r6]
	movs r0, 0x3
	ands r0, r1
	cmp r0, 0
	beq _08056AB6
	ldr r0, [r6, 0x10]
	cmp r0, 0
	beq _08056A8E
	bl GetEntityType
	cmp r0, 0x1
	bne _08056A8E
	ldr r0, [r6, 0x10]
	ldr r1, [sp, 0x1C]
	bl sub_80571F0
	lsls r0, 24
	cmp r0, 0
	bne _08056A8E
	ldr r0, [sp, 0x34]
	cmp r0, 0
	bgt _08056AB6
	movs r4, 0
	mov r2, r10
	ldr r1, [r2, 0x70]
	adds r0, r1, 0
	adds r0, 0xBC
	ldrb r2, [r0]
	cmp r2, 0x2
	beq _08056A64
	adds r0, 0x2C
	ldrb r0, [r0]
	cmp r0, 0x1
	beq _08056A64
	cmp r2, 0x4
	bne _08056A66
_08056A64:
	movs r4, 0x1
_08056A66:
	mov r0, r10
	ldr r1, [sp, 0x1C]
	movs r2, 0
	bl GetMoveTargetAndRangeForPokemon
	adds r2, r0, 0
	lsls r2, 16
	asrs r2, 16
	ldr r0, [r6, 0x10]
	str r0, [sp]
	ldr r6, [sp, 0x1C]
	str r6, [sp, 0x4]
	str r4, [sp, 0x8]
	ldr r0, [sp, 0x34]
	add r1, sp, 0x14
	mov r3, r10
	bl sub_8056F80
	str r0, [sp, 0x34]
	b _08056AB6
_08056A8E:
	ldr r0, [sp, 0x30]
	adds r0, 0x1
	str r0, [sp, 0x30]
	ldr r1, [sp, 0x20]
	cmp r0, r1
	bge _08056AB6
	movs r2, 0
	ldrsh r1, [r7, r2]
	cmp r1, 0
	blt _08056AB6
	ldrh r0, [r7, 0x2]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0
	blt _08056AB6
	cmp r1, 0x37
	bgt _08056AB6
	cmp r0, 0x1F
	bgt _08056AB6
	b _080568D6
_08056AB6:
	ldr r6, [sp, 0x40]
	cmp r6, 0
	blt _08056AC2
	adds r0, r6, 0
	bl sub_800DC14
_08056AC2:
	movs r0, 0x1
	bl sub_804178C
	ldr r0, _08056AF4
	ldr r0, [r0]
	ldr r1, _08056AF8
	adds r0, r1
	movs r2, 0
	strb r2, [r0]
	ldr r6, [sp, 0x34]
	cmp r6, 0
	ble _08056AFC
	lsls r1, r6, 2
	add r0, sp, 0x14
	adds r1, r0
	str r2, [r1]
	ldr r1, [sp, 0x78]
	str r1, [sp]
	mov r1, r10
	ldr r2, [sp, 0x1C]
	ldr r3, [sp, 0x74]
	bl sub_8053704
	b _08056B22
	.align 2, 0
_08056AF4: .4byte gDungeon
_08056AF8: .4byte 0x0001c05e
_08056AFC:
	ldr r0, [sp, 0x20]
	cmp r0, 0x1
	bne _08056B22
	add r0, sp, 0xC
	bl sub_803F428
	lsls r0, 24
	cmp r0, 0
	beq _08056B22
	movs r0, 0x1
	movs r1, 0x4A
	bl sub_803E708
	mov r0, r10
	movs r1, 0
	ldr r2, [sp, 0x1C]
	add r3, sp, 0xC
	bl sub_8041168
_08056B22:
	add sp, 0x54
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_80566F8

	thumb_func_start sub_8056B34
sub_8056B34:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x4
	adds r7, r0, 0
	adds r6, r1, 0
	mov r8, r2
	adds r1, r3, 0
	ldr r4, [sp, 0x24]
	lsls r4, 24
	lsrs r4, 24
	mov r0, r8
	bl GetMoveAccuracyOrAIChance
	adds r5, r0, 0
	movs r0, 0x64
	bl DungeonRandInt
	str r0, [sp]
	ldr r0, [r7, 0x70]
	mov r9, r0
	ldr r1, [r6, 0x70]
	mov r10, r1
	cmp r4, 0
	beq _08056B70
	cmp r7, r6
	bne _08056B70
	b _08056CD4
_08056B70:
	mov r0, r8
	ldrh r1, [r0, 0x2]
	ldr r0, _08056CC4
	cmp r1, r0
	bne _08056B8A
	adds r0, r7, 0
	movs r1, 0x4
	bl IQSkillIsEnabled
	lsls r0, 24
	cmp r0, 0
	beq _08056B8A
	b _08056CD4
_08056B8A:
	mov r0, r9
	adds r0, 0xDC
	ldrb r0, [r0]
	cmp r0, 0x1
	bne _08056B96
	b _08056CD4
_08056B96:
	cmp r0, 0x2
	bne _08056B9C
	b _08056CBE
_08056B9C:
	cmp r5, 0x64
	ble _08056BA2
	b _08056CD4
_08056BA2:
	adds r0, r6, 0
	movs r1, 0x23
	bl HasHeldItem
	lsls r0, 24
	cmp r0, 0
	beq _08056BB6
	ldr r0, _08056CC8
	ldr r0, [r0]
	subs r5, r0
_08056BB6:
	adds r0, r6, 0
	movs r1, 0x5
	bl IQSkillIsEnabled
	lsls r0, 24
	cmp r0, 0
	beq _08056BCA
	ldr r0, _08056CCC
	ldr r0, [r0]
	subs r5, r0
_08056BCA:
	mov r1, r9
	movs r0, 0x24
	ldrsh r4, [r1, r0]
	adds r0, r7, 0
	movs r1, 0x33
	bl HasAbility
	lsls r0, 24
	cmp r0, 0
	beq _08056BE0
	adds r4, 0x2
_08056BE0:
	mov r1, r8
	ldrh r0, [r1, 0x2]
	cmp r0, 0x40
	bne _08056BFC
	adds r0, r7, 0
	bl GetApparentWeather
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x4
	beq _08056CD4
	cmp r0, 0x1
	bne _08056BFC
	subs r4, 0x2
_08056BFC:
	cmp r4, 0
	bge _08056C02
	movs r4, 0
_08056C02:
	cmp r4, 0x14
	ble _08056C08
	movs r4, 0x14
_08056C08:
	ldr r1, _08056CD0
	lsls r0, r4, 2
	adds r0, r1
	ldr r0, [r0]
	cmp r0, 0
	bge _08056C16
	movs r0, 0
_08056C16:
	movs r1, 0xC8
	lsls r1, 7
	cmp r0, r1
	ble _08056C20
	adds r0, r1, 0
_08056C20:
	muls r5, r0
	adds r0, r5, 0
	cmp r5, 0
	bge _08056C2A
	adds r0, 0xFF
_08056C2A:
	asrs r5, r0, 8
	mov r0, r10
	movs r1, 0x26
	ldrsh r4, [r0, r1]
	adds r0, 0xF5
	ldrb r0, [r0]
	cmp r0, 0
	beq _08056C3C
	movs r4, 0xA
_08056C3C:
	adds r0, r6, 0
	bl GetApparentWeather
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x2
	bne _08056C5A
	adds r0, r6, 0
	movs r1, 0x1D
	bl HasAbility
	lsls r0, 24
	cmp r0, 0
	beq _08056C5A
	adds r4, 0x2
_08056C5A:
	adds r0, r7, 0
	movs r1, 0x30
	bl HasAbility
	lsls r0, 24
	cmp r0, 0
	beq _08056C86
	mov r0, r8
	bl GetMoveType
	lsls r0, 24
	lsrs r0, 24
	bl IsTypePhysical
	movs r1, 0
	lsls r0, 24
	cmp r0, 0
	bne _08056C80
	movs r1, 0x1
_08056C80:
	cmp r1, 0
	bne _08056C86
	adds r4, 0x2
_08056C86:
	cmp r4, 0
	bge _08056C8C
	movs r4, 0
_08056C8C:
	cmp r4, 0x14
	ble _08056C92
	movs r4, 0x14
_08056C92:
	ldr r0, _08056CD0
	lsls r1, r4, 2
	adds r0, 0x54
	adds r1, r0
	ldr r0, [r1]
	cmp r0, 0
	bge _08056CA2
	movs r0, 0
_08056CA2:
	movs r1, 0xC8
	lsls r1, 7
	cmp r0, r1
	ble _08056CAC
	adds r0, r1, 0
_08056CAC:
	muls r5, r0
	adds r0, r5, 0
	cmp r5, 0
	bge _08056CB6
	adds r0, 0xFF
_08056CB6:
	asrs r5, r0, 8
	ldr r0, [sp]
	cmp r0, r5
	blt _08056CD4
_08056CBE:
	movs r0, 0
	b _08056CD6
	.align 2, 0
_08056CC4: .4byte 0x00000163
_08056CC8: .4byte gUnknown_80F519C
_08056CCC: .4byte gUnknown_80F51A0
_08056CD0: .4byte gUnknown_80F50F4
_08056CD4:
	movs r0, 0x1
_08056CD6:
	add sp, 0x4
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_8056B34

	thumb_func_start sub_8056CE8
sub_8056CE8:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x18
	str r0, [sp, 0x10]
	adds r5, r1, 0
	mov r8, r2
	movs r0, 0
	mov r9, r0
	movs r3, 0
	ldr r1, [r5, 0x70]
	adds r0, r1, 0
	adds r0, 0xBC
	ldrb r2, [r0]
	cmp r2, 0x2
	beq _08056D18
	adds r0, 0x2C
	ldrb r0, [r0]
	cmp r0, 0x1
	beq _08056D18
	cmp r2, 0x4
	bne _08056D1A
_08056D18:
	movs r3, 0x1
_08056D1A:
	mov r10, r3
	movs r1, 0
	ldr r0, [r5, 0x70]
	adds r0, 0xBC
	ldrb r0, [r0]
	cmp r0, 0x2
	beq _08056D2C
	cmp r0, 0x4
	bne _08056D2E
_08056D2C:
	movs r1, 0x1
_08056D2E:
	str r1, [sp, 0x14]
	adds r0, r5, 0
	movs r1, 0x7
	bl IQSkillIsEnabled
	lsls r0, 24
	cmp r0, 0
	beq _08056D44
	movs r1, 0
	str r1, [sp, 0x14]
	mov r10, r1
_08056D44:
	adds r0, r5, 0
	mov r1, r8
	movs r2, 0
	bl GetMoveTargetAndRangeForPokemon
	lsls r0, 16
	asrs r7, r0, 16
	movs r0, 0xF
	ands r0, r7
	cmp r0, 0x4
	bne _08056D86
	adds r0, r5, 0
	mov r1, r8
	bl MoveMatchesChargingStatus
	lsls r0, 24
	lsrs r4, r0, 24
	mov r2, r8
	ldrh r0, [r2, 0x2]
	cmp r0, 0x97
	bne _08056D7E
	adds r0, r5, 0
	bl GetApparentWeather
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _08056D7E
	movs r4, 0x1
_08056D7E:
	movs r7, 0x73
	cmp r4, 0
	beq _08056D86
	movs r7, 0
_08056D86:
	movs r1, 0xF0
	ands r1, r7
	cmp r1, 0
	bne _08056DA6
	adds r0, r5, 0
	bl sub_80696A8
	cmp r0, 0
	bne _08056D9A
	b _08056F64
_08056D9A:
	str r0, [sp]
	mov r0, r8
	str r0, [sp, 0x4]
	mov r1, r10
	str r1, [sp, 0x8]
	b _08056F56
_08056DA6:
	cmp r1, 0x10
	beq _08056DAE
	cmp r1, 0x20
	bne _08056E34
_08056DAE:
	ldr r0, [r5, 0x70]
	cmp r1, 0x20
	bne _08056DBC
	adds r0, 0x46
	ldrb r4, [r0]
	movs r0, 0x8
	b _08056DCA
_08056DBC:
	adds r0, 0x46
	ldrb r0, [r0]
	subs r4, r0, 0x1
	movs r0, 0x3
	cmp r0, 0
	bne _08056DCA
	b _08056F64
_08056DCA:
	adds r6, r0, 0
_08056DCC:
	movs r0, 0x7
	ands r4, r0
	ldr r0, _08056E28
	lsls r3, r4, 2
	adds r3, r0
	ldrh r0, [r3]
	ldrh r2, [r5, 0x4]
	adds r0, r2
	lsls r0, 16
	lsrs r0, 16
	ldr r2, _08056E2C
	ldr r1, [sp, 0xC]
	ands r1, r2
	orrs r1, r0
	str r1, [sp, 0xC]
	ldrh r2, [r3, 0x2]
	ldrh r0, [r5, 0x6]
	adds r2, r0
	lsls r2, 16
	ldr r0, _08056E30
	ands r1, r0
	orrs r1, r2
	str r1, [sp, 0xC]
	add r0, sp, 0xC
	bl sub_804AD0C
	cmp r0, 0
	beq _08056E1C
	str r0, [sp]
	mov r1, r8
	str r1, [sp, 0x4]
	mov r2, r10
	str r2, [sp, 0x8]
	mov r0, r9
	ldr r1, [sp, 0x10]
	adds r2, r7, 0
	adds r3, r5, 0
	bl sub_8056F80
	mov r9, r0
_08056E1C:
	subs r6, 0x1
	adds r4, 0x1
	cmp r6, 0
	bne _08056DCC
	b _08056F64
	.align 2, 0
_08056E28: .4byte gAdjacentTileOffsets
_08056E2C: .4byte 0xffff0000
_08056E30: .4byte 0x0000ffff
_08056E34:
	cmp r1, 0x30
	bne _08056E9C
	movs r6, 0
_08056E3A:
	ldr r0, _08056E74
	ldr r0, [r0]
	lsls r1, r6, 2
	ldr r2, _08056E78
	adds r0, r2
	adds r0, r1
	ldr r4, [r0]
	adds r0, r4, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	beq _08056E94
	adds r0, r5, 0
	adds r1, r4, 0
	bl sub_8045A70
	lsls r0, 24
	cmp r0, 0
	beq _08056E94
	cmp r4, r5
	bne _08056E7C
	str r5, [sp]
	mov r0, r8
	str r0, [sp, 0x4]
	ldr r1, [sp, 0x14]
	str r1, [sp, 0x8]
	b _08056E86
	.align 2, 0
_08056E74: .4byte gDungeon
_08056E78: .4byte 0x000135cc
_08056E7C:
	str r4, [sp]
	mov r2, r8
	str r2, [sp, 0x4]
	mov r0, r10
	str r0, [sp, 0x8]
_08056E86:
	mov r0, r9
	ldr r1, [sp, 0x10]
	adds r2, r7, 0
	adds r3, r5, 0
	bl sub_8056F80
	mov r9, r0
_08056E94:
	adds r6, 0x1
	cmp r6, 0x13
	ble _08056E3A
	b _08056F64
_08056E9C:
	cmp r1, 0x40
	bne _08056EEA
	movs r4, 0
	adds r0, r5, 0
	bl sub_80696FC
	cmp r0, 0
	beq _08056ED0
	mov r4, r9
	str r0, [sp]
	mov r1, r8
	str r1, [sp, 0x4]
	mov r2, r10
	str r2, [sp, 0x8]
	adds r0, r4, 0
	ldr r1, [sp, 0x10]
	adds r2, r7, 0
	adds r3, r5, 0
	bl sub_8056F80
	mov r9, r0
	mov r1, r9
	eors r1, r4
	negs r0, r1
	orrs r0, r1
	lsrs r4, r0, 31
_08056ED0:
	cmp r4, 0
	bne _08056F64
	adds r0, r5, 0
	bl sub_806977C
	cmp r0, 0
	beq _08056F64
	str r0, [sp]
	mov r0, r8
	str r0, [sp, 0x4]
	mov r1, r10
	str r1, [sp, 0x8]
	b _08056F56
_08056EEA:
	cmp r1, 0x50
	beq _08056F64
	cmp r1, 0x80
	bne _08056F00
	adds r0, r5, 0
	bl sub_80696FC
	cmp r0, 0
	beq _08056F64
	str r0, [sp]
	b _08056F4E
_08056F00:
	cmp r1, 0x60
	bne _08056F48
	movs r6, 0
_08056F06:
	ldr r0, _08056F40
	ldr r0, [r0]
	lsls r1, r6, 2
	ldr r2, _08056F44
	adds r0, r2
	adds r0, r1
	ldr r4, [r0]
	adds r0, r4, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	beq _08056F38
	str r4, [sp]
	mov r0, r8
	str r0, [sp, 0x4]
	mov r1, r10
	str r1, [sp, 0x8]
	mov r0, r9
	ldr r1, [sp, 0x10]
	adds r2, r7, 0
	adds r3, r5, 0
	bl sub_8056F80
	mov r9, r0
_08056F38:
	adds r6, 0x1
	cmp r6, 0x13
	ble _08056F06
	b _08056F64
	.align 2, 0
_08056F40: .4byte gDungeon
_08056F44: .4byte 0x000135cc
_08056F48:
	cmp r1, 0x70
	bne _08056F64
	str r5, [sp]
_08056F4E:
	mov r2, r8
	str r2, [sp, 0x4]
	mov r0, r10
	str r0, [sp, 0x8]
_08056F56:
	mov r0, r9
	ldr r1, [sp, 0x10]
	adds r2, r7, 0
	adds r3, r5, 0
	bl sub_8056F80
	mov r9, r0
_08056F64:
	mov r1, r9
	lsls r0, r1, 2
	ldr r2, [sp, 0x10]
	adds r0, r2
	movs r1, 0
	str r1, [r0]
	add sp, 0x18
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_8056CE8

	thumb_func_start sub_8056F80
sub_8056F80:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	adds r5, r0, 0
	mov r8, r1
	adds r4, r3, 0
	ldr r7, [sp, 0x18]
	ldr r0, [sp, 0x20]
	lsls r2, 16
	asrs r2, 16
	lsls r0, 24
	lsrs r0, 24
	mov r12, r0
	movs r6, 0
	ldr r1, [r7, 0x70]
	ldr r3, [sp, 0x1C]
	ldrh r0, [r3, 0x2]
	cmp r0, 0xFC
	bne _08056FAA
	cmp r4, r7
	beq _08057060
_08056FAA:
	ldrb r0, [r1, 0x8]
	cmp r0, 0x1
	beq _08057060
	adds r0, r1, 0
	adds r0, 0xA4
	ldrb r0, [r0]
	cmp r0, 0x4
	beq _08057060
	cmp r0, 0x1
	beq _08057060
	mov r0, r12
	cmp r0, 0
	bne _0805702C
	movs r0, 0xF
	ands r0, r2
	cmp r0, 0
	beq _08056FD0
	cmp r0, 0x4
	bne _08056FE6
_08056FD0:
	adds r0, r4, 0
	adds r1, r7, 0
	movs r2, 0x1
	movs r3, 0
	bl GetTreatmentBetweenMonsters
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _0805702E
	b _0805702C
_08056FE6:
	cmp r0, 0x1
	bne _08056FFE
	adds r0, r4, 0
	adds r1, r7, 0
	movs r2, 0x1
	movs r3, 0
	bl GetTreatmentBetweenMonsters
	lsls r0, 24
	cmp r0, 0
	bne _0805702E
	b _0805702C
_08056FFE:
	cmp r0, 0x2
	beq _0805702C
	cmp r0, 0x5
	bne _0805700C
	cmp r4, r7
	beq _0805702E
	b _0805702C
_0805700C:
	cmp r0, 0x6
	bne _08057028
	adds r0, r4, 0
	adds r1, r7, 0
	movs r2, 0x1
	movs r3, 0
	bl GetTreatmentBetweenMonsters
	lsls r0, 24
	cmp r0, 0
	bne _0805702E
	cmp r4, r7
	beq _0805702E
	b _0805702C
_08057028:
	cmp r0, 0x3
	bne _0805702E
_0805702C:
	movs r6, 0x1
_0805702E:
	adds r0, r7, 0
	ldr r1, [sp, 0x1C]
	bl sub_80571F0
	lsls r0, 24
	cmp r0, 0
	beq _0805703E
	movs r6, 0
_0805703E:
	cmp r6, 0
	beq _08057060
	cmp r5, 0x3F
	bgt _08057060
	lsls r0, r5, 2
	add r0, r8
	str r7, [r0]
	ldr r0, [r7, 0x70]
	ldrb r0, [r0, 0x6]
	cmp r0, 0
	bne _0805705E
	ldr r1, _0805706C
	ldr r0, [r1]
	cmp r0, 0
	bne _0805705E
	str r7, [r1]
_0805705E:
	adds r5, 0x1
_08057060:
	adds r0, r5, 0
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r1}
	bx r1
	.align 2, 0
_0805706C: .4byte gUnknown_203B438
	thumb_func_end sub_8056F80

	.align 2, 0
