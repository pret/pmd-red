	#include "asm/constants/gba_constants.inc"
  	#include "asm/macros.inc"

  	.syntax unified

  	.text
  
	thumb_func_start WeightMove
WeightMove:
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	adds r5, r0, 0
	mov r8, r2
	lsls r1, 16
	asrs r1, 16
	lsls r3, 24
	lsrs r3, 24
	mov r9, r3
	movs r6, 0x1
	ldr r4, [r2, 0x70]
	adds r7, r4, 0
	ldrb r0, [r4, 0x6]
	cmp r0, 0
	beq _0807C7D6
	movs r0, 0xF
	ands r0, r1
	cmp r0, 0
	beq _0807C7DA
_0807C7D6:
	movs r0, 0x1
	b _0807C848
_0807C7DA:
	adds r0, r5, 0
	movs r1, 0x9
	bl HasIQSkill
	lsls r0, 24
	cmp r0, 0
	beq _0807C804
	ldr r0, _0807C7FC
	ldr r0, [r0]
	movs r2, 0x2
	ldrsh r1, [r4, r2]
	ldr r2, _0807C800
	adds r0, r2
	adds r0, r1
	ldrb r6, [r0]
	b _0807C846
	.align 2, 0
_0807C7FC: .4byte gDungeonGlobalData
_0807C800: .4byte 0x0000363c
_0807C804:
	adds r0, r5, 0
	movs r1, 0xA
	bl HasIQSkill
	lsls r0, 24
	cmp r0, 0
	beq _0807C828
	ldrb r1, [r7, 0xE]
	movs r2, 0xC
	negs r2, r2
	adds r0, r2, 0
	subs r0, r1
	lsls r0, 24
	lsrs r6, r0, 24
	cmp r6, 0
	bne _0807C846
	movs r6, 0x1
	b _0807C846
_0807C828:
	adds r0, r5, 0
	movs r1, 0xB
	bl HasIQSkill
	lsls r0, 24
	cmp r0, 0
	beq _0807C846
	adds r0, r5, 0
	mov r1, r8
	mov r2, r9
	bl WeightWeakTypePicker
	adds r0, 0x1
	lsls r0, 24
	lsrs r6, r0, 24
_0807C846:
	adds r0, r6, 0
_0807C848:
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end WeightMove

	thumb_func_start TargetRegularAttack
TargetRegularAttack:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x50
	adds r7, r0, 0
	str r1, [sp, 0x40]
	lsls r2, 24
	lsrs r2, 24
	str r2, [sp, 0x44]
	ldr r0, [r7, 0x70]
	movs r1, 0
	mov r8, r1
	adds r1, r0, 0
	adds r1, 0x46
	ldrb r6, [r1]
	adds r0, 0xE8
	ldrb r0, [r0]
	movs r3, 0x8
	mov r10, r3
	cmp r0, 0x1
	bne _0807C886
	movs r0, 0x1
	mov r10, r0
_0807C886:
	movs r4, 0
	adds r0, r7, 0
	movs r1, 0x9
	bl HasIQSkill
	lsls r0, 24
	cmp r0, 0
	bne _0807C8A4
	adds r0, r7, 0
	movs r1, 0xA
	bl HasIQSkill
	lsls r0, 24
	cmp r0, 0
	beq _0807C8A6
_0807C8A4:
	movs r4, 0x1
_0807C8A6:
	str r4, [sp, 0x48]
	adds r0, r7, 0
	movs r1, 0x8
	bl HasIQSkill
	lsls r0, 24
	lsrs r0, 24
	str r0, [sp, 0x4C]
	movs r1, 0
	mov r9, r1
	cmp r9, r10
	bge _0807C952
_0807C8BE:
	movs r0, 0x7
	ands r6, r0
	movs r3, 0x4
	ldrsh r0, [r7, r3]
	ldr r1, _0807C95C
	lsls r2, r6, 2
	adds r2, r1
	movs r3, 0
	ldrsh r1, [r2, r3]
	adds r0, r1
	movs r3, 0x6
	ldrsh r1, [r7, r3]
	movs r3, 0x2
	ldrsh r2, [r2, r3]
	adds r1, r2
	bl GetMapTile_1
	ldr r5, [r0, 0x10]
	cmp r5, 0
	beq _0807C948
	adds r0, r5, 0
	bl GetEntityType
	cmp r0, 0x1
	bne _0807C948
	adds r0, r7, 0
	adds r1, r6, 0
	bl CanAttackInFront
	lsls r0, 24
	cmp r0, 0
	beq _0807C948
	adds r0, r7, 0
	adds r1, r5, 0
	movs r2, 0
	ldr r3, [sp, 0x44]
	bl CanTarget
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _0807C948
	ldr r0, [sp, 0x4C]
	cmp r0, 0
	beq _0807C922
	ldr r0, [r5, 0x70]
	adds r0, 0xB0
	ldrb r0, [r0]
	cmp r0, 0x1
	beq _0807C948
_0807C922:
	mov r1, r8
	lsls r4, r1, 2
	mov r3, sp
	adds r0, r3, r4
	str r6, [r0]
	adds r0, r7, 0
	movs r1, 0
	adds r2, r5, 0
	movs r3, 0
	bl WeightMove
	add r1, sp, 0x20
	adds r1, r4
	str r0, [r1]
	ldr r0, [sp, 0x48]
	cmp r0, 0
	beq _0807C960
	movs r1, 0x1
	add r8, r1
_0807C948:
	movs r3, 0x1
	add r9, r3
	adds r6, 0x1
	cmp r9, r10
	blt _0807C8BE
_0807C952:
	mov r0, r8
	cmp r0, 0
	bne _0807C966
	movs r0, 0
	b _0807C9E8
	.align 2, 0
_0807C95C: .4byte gAdjacentTileOffsets
_0807C960:
	ldr r1, [sp, 0x40]
	str r6, [r1]
	b _0807C9E6
_0807C966:
	movs r4, 0
	movs r3, 0
	mov r0, r8
	cmp r0, 0
	ble _0807C984
	add r1, sp, 0x20
	mov r2, r8
_0807C974:
	ldr r0, [r1]
	cmp r3, r0
	bge _0807C97C
	adds r3, r0, 0
_0807C97C:
	adds r1, 0x4
	subs r2, 0x1
	cmp r2, 0
	bne _0807C974
_0807C984:
	mov r1, r8
	cmp r1, 0
	ble _0807C9A0
	movs r5, 0
	add r1, sp, 0x20
	mov r2, r8
_0807C990:
	ldr r0, [r1]
	cmp r3, r0
	beq _0807C998
	str r5, [r1]
_0807C998:
	adds r1, 0x4
	subs r2, 0x1
	cmp r2, 0
	bne _0807C990
_0807C9A0:
	mov r3, r8
	cmp r3, 0
	ble _0807C9B4
	add r1, sp, 0x20
	mov r2, r8
_0807C9AA:
	ldm r1!, {r0}
	adds r4, r0
	subs r2, 0x1
	cmp r2, 0
	bne _0807C9AA
_0807C9B4:
	adds r0, r4, 0
	bl DungeonRandomCapped
	adds r1, r0, 0
	movs r2, 0
	cmp r2, r8
	bge _0807C9DC
	ldr r0, [sp, 0x20]
	subs r1, r0
	cmp r1, 0
	blt _0807C9DC
	add r3, sp, 0x20
_0807C9CC:
	adds r3, 0x4
	adds r2, 0x1
	cmp r2, r8
	bge _0807C9DC
	ldr r0, [r3]
	subs r1, r0
	cmp r1, 0
	bge _0807C9CC
_0807C9DC:
	lsls r0, r2, 2
	add r0, sp
	ldr r0, [r0]
	ldr r1, [sp, 0x40]
	str r0, [r1]
_0807C9E6:
	movs r0, 0x1
_0807C9E8:
	add sp, 0x50
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end TargetRegularAttack

	.align 2, 0