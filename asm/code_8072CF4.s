	#include "asm/constants/gba_constants.inc"
  	#include "asm/macros.inc"

  	.syntax unified

  	.text

	thumb_func_start sub_80732F0
sub_80732F0:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x14
	movs r4, 0
_080732FE:
	movs r5, 0
	ldr r0, _0807335C
	ldr r0, [r0]
	lsls r1, r4, 2
	ldr r2, _08073360
	adds r0, r2
	adds r0, r1
	ldr r0, [r0]
	mov r8, r0
	bl EntityIsValid
	lsls r0, 24
	adds r4, 0x1
	str r4, [sp, 0x10]
	cmp r0, 0
	bne _08073320
	b _08073472
_08073320:
	mov r0, r8
	ldr r7, [r0, 0x70]
	movs r1, 0xB2
	lsls r1, 1
	adds r4, r7, r1
	ldrb r0, [r4]
	cmp r0, 0xFF
	bne _08073332
	b _08073472
_08073332:
	adds r2, r0, 0
	mov r9, r2
	mov r0, r8
	movs r1, 0x1
	bl CannotAttack
	lsls r0, 24
	cmp r0, 0
	bne _0807336E
	mov r0, r8
	bl IsSleeping
	lsls r0, 24
	cmp r0, 0
	bne _08073364
	ldrb r0, [r4]
	movs r2, 0xFF
	orrs r0, r2
	strb r0, [r4]
	b _08073472
	.align 2, 0
_0807335C: .4byte gDungeon
_08073360: .4byte 0x000135cc
_08073364:
	adds r0, r7, 0
	adds r0, 0xEC
	ldrb r0, [r0]
	cmp r0, 0x1
	bne _08073378
_0807336E:
	ldrb r0, [r4]
	movs r1, 0xFF
	orrs r0, r1
	strb r0, [r4]
	b _08073472
_08073378:
	movs r0, 0x4
	bl DungeonRandInt
	adds r3, r0, 0
	movs r4, 0
_08073382:
	lsls r0, r3, 3
	movs r2, 0x8C
	lsls r2, 1
	adds r0, r2
	adds r2, r7, r0
	ldrb r1, [r2]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _08073448
	ldr r0, [r2]
	ldr r1, [r2, 0x4]
	str r0, [sp, 0x8]
	str r1, [sp, 0xC]
	ldr r1, [sp, 0x8]
	lsrs r0, r1, 16
	cmp r0, 0x8A
	beq _08073448
	adds r1, r0, 0
	ldr r0, _08073434
	cmp r1, r0
	beq _08073448
	movs r6, 0
	movs r0, 0x46
	adds r0, r7
	mov r10, r0
	movs r1, 0x8C
	lsls r1, 1
	adds r4, r7, r1
_080733BC:
	lsls r0, r6, 3
	movs r2, 0x8C
	lsls r2, 1
	adds r0, r2
	adds r5, r7, r0
	ldrb r1, [r4]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _080733F4
	ldrb r0, [r7, 0x7]
	cmp r0, 0
	bne _080733DE
	movs r0, 0x4
	ands r0, r1
	cmp r0, 0
	beq _080733F4
_080733DE:
	ldrh r0, [r4, 0x2]
	cmp r0, 0xE3
	bne _080733F4
	mov r0, r8
	adds r1, r5, 0
	movs r2, 0x1
	bl CanMonsterUseMove
	lsls r0, 24
	cmp r0, 0
	bne _08073440
_080733F4:
	adds r4, 0x8
	adds r6, 0x1
	cmp r6, 0x3
	ble _080733BC
_080733FC:
	ldr r0, _08073438
	mov r1, r8
	movs r2, 0
	bl SubstitutePlaceholderStringTags
	ldr r0, _0807343C
	ldr r1, [r0]
	mov r0, r8
	bl LogMessageByIdWithPopupCheckUser
	movs r0, 0x7
	mov r1, r9
	ands r1, r0
	movs r0, 0
	mov r2, r10
	strb r1, [r2]
	str r0, [sp]
	add r0, sp, 0x8
	str r0, [sp, 0x4]
	mov r0, r8
	movs r1, 0
	movs r2, 0
	movs r3, 0x1
	bl TryUseChosenMove
	movs r5, 0x1
	b _08073456
	.align 2, 0
_08073434: .4byte 0x00000147
_08073438: .4byte gFormatBuffer_Monsters
_0807343C: .4byte gUnknown_80FCF38
_08073440:
	adds r0, r5, 0x4
	bl sub_80838EC
	b _080733FC
_08073448:
	adds r3, 0x1
	cmp r3, 0x4
	bne _08073450
	movs r3, 0
_08073450:
	adds r4, 0x1
	cmp r4, 0x3
	ble _08073382
_08073456:
	movs r2, 0xB2
	lsls r2, 1
	adds r1, r7, r2
	ldrb r0, [r1]
	movs r2, 0xFF
	orrs r0, r2
	strb r0, [r1]
	cmp r5, 0
	beq _08073472
	mov r0, r8
	movs r1, 0xB8
	lsls r1, 2
	bl sub_80421C0
_08073472:
	ldr r4, [sp, 0x10]
	cmp r4, 0x13
	bgt _0807347A
	b _080732FE
_0807347A:
	add sp, 0x14
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_80732F0

	.align 2, 0
