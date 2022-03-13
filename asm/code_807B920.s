	#include "asm/constants/gba_constants.inc"
  	#include "asm/macros.inc"

  	.syntax unified

  	.text
  
	thumb_func_start Explore
Explore:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x10
	adds r6, r0, 0
	ldr r7, [r6, 0x70]
	bl GetEntityRoomIndex
	lsls r0, 24
	lsrs r3, r0, 24
	cmp r3, 0xFF
	bne _0807B9DC
	movs r0, 0
	str r0, [sp, 0x4]
	adds r4, r7, 0
	adds r4, 0x46
	ldrb r0, [r4]
	adds r0, 0x4
	mov r8, r0
	movs r0, 0x7
	mov r1, r8
	ands r1, r0
	mov r8, r1
	adds r0, r6, 0
	bl IsAtJunction
	lsls r0, 24
	mov r9, r4
	cmp r0, 0
	beq _0807B96C
	movs r0, 0x8
	bl DungeonRandomCapped
	strb r0, [r4]
	movs r2, 0x1
	str r2, [sp, 0x4]
_0807B96C:
	movs r3, 0
	movs r4, 0x78
	adds r4, r7
	mov r10, r4
	adds r0, r7, 0
	adds r0, 0x88
	str r0, [sp, 0x8]
	adds r7, 0x8A
	ldr r5, _0807B9D4
_0807B97E:
	mov r1, r9
	ldrb r0, [r1]
	ldr r1, [r5]
	adds r4, r0, r1
	movs r0, 0x7
	ands r4, r0
	ldr r2, [sp, 0x4]
	cmp r2, 0
	beq _0807B994
	cmp r4, r8
	beq _0807B9AA
_0807B994:
	adds r0, r6, 0
	adds r1, r4, 0
	mov r2, sp
	str r3, [sp, 0xC]
	bl CanMoveForward
	lsls r0, 24
	ldr r3, [sp, 0xC]
	cmp r0, 0
	beq _0807B9AA
	b _0807BB42
_0807B9AA:
	adds r5, 0x4
	adds r3, 0x1
	cmp r3, 0x7
	ble _0807B97E
	movs r0, 0x8
	bl DungeonRandomCapped
	movs r1, 0x6
	mov r3, r10
	strb r1, [r3]
	ldr r1, _0807B9D8
	lsls r0, 2
	adds r0, r1
	ldrh r1, [r0]
	ldrh r4, [r6, 0x4]
	adds r1, r4
	ldr r2, [sp, 0x8]
	strh r1, [r2]
	ldrh r0, [r0, 0x2]
	b _0807BB5A
	.align 2, 0
_0807B9D4: .4byte gFaceDirectionIncrements
_0807B9D8: .4byte gAdjacentTileOffsets
_0807B9DC:
	ldr r0, _0807BA30
	ldr r2, [r0]
	lsls r1, r3, 1
	ldr r4, _0807BA34
	adds r0, r2, r4
	adds r0, r1
	movs r4, 0
	ldrsh r1, [r0, r4]
	mov r8, r1
	lsls r0, r3, 7
	ldr r1, _0807BA38
	adds r0, r1
	adds r2, r0
	mov r9, r2
	movs r2, 0x8A
	lsls r2, 1
	adds r0, r7, r2
	ldr r0, [r0]
	cmp r0, 0
	beq _0807BA40
	movs r0, 0x8
	bl DungeonRandomCapped
	adds r2, r7, 0
	adds r2, 0x78
	movs r1, 0x6
	strb r1, [r2]
	ldr r1, _0807BA3C
	lsls r0, 2
	adds r0, r1
	ldrh r1, [r0]
	ldrh r3, [r6, 0x4]
	adds r1, r3
	adds r2, 0x10
	strh r1, [r2]
	ldrh r0, [r0, 0x2]
	ldrh r6, [r6, 0x6]
	adds r0, r6
	adds r1, r7, 0
	adds r1, 0x8A
	strh r0, [r1]
	b _0807BB60
	.align 2, 0
_0807BA30: .4byte gDungeonGlobalData
_0807BA34: .4byte 0x00010844
_0807BA38: .4byte 0x00010884
_0807BA3C: .4byte gAdjacentTileOffsets
_0807BA40:
	adds r0, r7, 0
	adds r0, 0x78
	ldrb r1, [r0]
	mov r10, r0
	cmp r1, 0x4
	beq _0807BAA2
	mov r4, r8
	cmp r4, 0
	bne _0807BA84
	movs r0, 0x8
	bl DungeonRandomCapped
	adds r4, r0, 0
	movs r0, 0x6
	mov r1, r10
	strb r0, [r1]
	ldr r0, _0807BA80
	lsls r2, r4, 2
	adds r2, r0
	ldrh r0, [r2]
	ldrh r3, [r6, 0x4]
	adds r0, r3
	adds r1, r7, 0
	adds r1, 0x88
	strh r0, [r1]
	ldrh r0, [r2, 0x2]
	ldrh r6, [r6, 0x6]
	adds r0, r6
	adds r1, 0x2
	strh r0, [r1]
	b _0807BB60
	.align 2, 0
_0807BA80: .4byte gAdjacentTileOffsets
_0807BA84:
	movs r5, 0
_0807BA86:
	mov r0, r8
	bl DungeonRandomCapped
	adds r4, r0, 0
	ldr r0, [r6, 0x4]
	lsls r1, r4, 2
	mov r4, r9
	adds r2, r1, r4
	ldr r1, [r2]
	cmp r0, r1
	bne _0807BB18
	adds r5, 0x1
	cmp r5, 0x9
	ble _0807BA86
_0807BAA2:
	movs r1, 0x4
	ldrsh r0, [r6, r1]
	movs r2, 0x6
	ldrsh r1, [r6, r2]
	bl GetMapTile_1
	ldrh r1, [r0]
	movs r0, 0x8
	ands r0, r1
	cmp r0, 0
	beq _0807BB60
	movs r0, 0x8
	bl DungeonRandomCapped
	adds r4, r0, 0
	movs r3, 0
	mov r9, r3
_0807BAC4:
	movs r0, 0x7
	ands r4, r0
	movs r0, 0x4
	ldrsh r2, [r6, r0]
	ldr r0, _0807BB14
	lsls r1, r4, 2
	adds r1, r0
	movs r3, 0
	ldrsh r0, [r1, r3]
	adds r2, r0
	mov r8, r2
	movs r0, 0x6
	ldrsh r2, [r6, r0]
	movs r3, 0x2
	ldrsh r0, [r1, r3]
	adds r5, r2, r0
	mov r0, r8
	adds r1, r5, 0
	bl GetMapTile_1
	ldrb r0, [r0, 0x9]
	cmp r0, 0xFF
	bne _0807BB04
	adds r0, r6, 0
	adds r1, r4, 0
	mov r2, sp
	adds r2, 0x1
	bl CanMoveForward
	lsls r0, 24
	cmp r0, 0
	bne _0807BB2E
_0807BB04:
	movs r0, 0x1
	add r9, r0
	adds r4, 0x1
	mov r1, r9
	cmp r1, 0x7
	ble _0807BAC4
	b _0807BB60
	.align 2, 0
_0807BB14: .4byte gAdjacentTileOffsets
_0807BB18:
	movs r0, 0x4
	mov r3, r10
	strb r0, [r3]
	ldrh r1, [r2]
	adds r0, r7, 0
	adds r0, 0x88
	strh r1, [r0]
	ldrh r1, [r2, 0x2]
	adds r0, 0x2
	strh r1, [r0]
	b _0807BB60
_0807BB2E:
	movs r0, 0x3
	mov r4, r10
	strb r0, [r4]
	adds r0, r7, 0
	adds r0, 0x88
	mov r1, r8
	strh r1, [r0]
	adds r0, 0x2
	strh r5, [r0]
	b _0807BB60
_0807BB42:
	movs r0, 0x3
	mov r2, r10
	strb r0, [r2]
	ldr r0, _0807BB74
	lsls r1, r4, 2
	adds r1, r0
	ldrh r0, [r1]
	ldrh r3, [r6, 0x4]
	adds r0, r3
	ldr r4, [sp, 0x8]
	strh r0, [r4]
	ldrh r0, [r1, 0x2]
_0807BB5A:
	ldrh r6, [r6, 0x6]
	adds r0, r6
	strh r0, [r7]
_0807BB60:
	movs r0, 0x1
	add sp, 0x10
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	.align 2, 0
_0807BB74: .4byte gAdjacentTileOffsets
	thumb_func_end Explore

	thumb_func_start sub_807BB78
sub_807BB78:
	ldr r3, [r0, 0x70]
	adds r1, r3, 0
	adds r1, 0x78
	movs r2, 0
	strb r2, [r1]
	adds r1, 0x10
	ldr r0, [r0, 0x4]
	str r0, [r1]
	adds r0, r3, 0
	adds r0, 0x80
	str r2, [r0]
	subs r0, 0x4
	strh r2, [r0]
	bx lr
	thumb_func_end sub_807BB78

	.align 2, 0