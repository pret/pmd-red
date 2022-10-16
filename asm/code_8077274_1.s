	#include "asm/constants/gba_constants.inc"
  	#include "asm/macros.inc"

  	.syntax unified

  	.text

	thumb_func_start sub_807AB38
sub_807AB38:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x1A8
	adds r2, r0, 0
	lsls r1, 24
	lsrs r4, r1, 24
	ldr r0, [r2, 0x70]
	ldrb r0, [r0, 0x6]
	cmp r0, 0
	beq _0807AB54
	b _0807ADA6
_0807AB54:
	adds r0, r2, 0
	str r2, [sp, 0x1A4]
	bl GetMapTileForDungeonEntity_2
	ldrh r1, [r0]
	movs r0, 0x40
	ands r0, r1
	ldr r2, [sp, 0x1A4]
	cmp r0, 0
	bne _0807AB6A
	b _0807ADA6
_0807AB6A:
	ldr r3, _0807AC10
	ldr r0, [r3]
	ldr r5, _0807AC14
	adds r1, r0, r5
	ldrb r0, [r1]
	cmp r0, 0
	beq _0807AB7A
	b _0807ADA6
_0807AB7A:
	movs r0, 0x1
	strb r0, [r1]
	ldr r3, [r3]
	ldr r1, _0807AC18
	adds r0, r3, r1
	ldrb r1, [r0]
	cmp r1, 0xFF
	bne _0807AB8C
	b _0807ADA6
_0807AB8C:
	lsls r0, r1, 3
	subs r0, r1
	lsls r0, 2
	ldr r5, _0807AC1C
	adds r0, r5
	adds r3, r0
	movs r0, 0
	mov r8, r0
	cmp r4, 0
	beq _0807AC20
	movs r1, 0x6
	ldrsh r0, [r2, r1]
	subs r6, r0, 0x4
	adds r0, 0x4
	cmp r6, r0
	ble _0807ABAE
	b _0807ACB4
_0807ABAE:
	movs r4, 0x4
	ldrsh r0, [r2, r4]
	subs r4, r0, 0x4
	adds r0, 0x4
	adds r5, r6, 0x1
	mov r9, r5
	cmp r4, r0
	bgt _0807AC00
	mov r1, r8
	lsls r0, r1, 2
	mov r1, sp
	adds r5, r0, r1
_0807ABC6:
	adds r0, r4, 0
	adds r1, r6, 0
	str r2, [sp, 0x1A4]
	bl GetMapTile_2
	adds r1, r0, 0
	ldr r0, [r1, 0x10]
	ldr r2, [sp, 0x1A4]
	cmp r0, 0
	bne _0807ABF4
	ldrh r1, [r1]
	movs r0, 0x3
	ands r0, r1
	cmp r0, 0x1
	bne _0807ABF4
	mov r0, r8
	cmp r0, 0x63
	bgt _0807ABF4
	strh r4, [r5]
	strh r6, [r5, 0x2]
	adds r5, 0x4
	movs r1, 0x1
	add r8, r1
_0807ABF4:
	adds r4, 0x1
	movs r1, 0x4
	ldrsh r0, [r2, r1]
	adds r0, 0x4
	cmp r4, r0
	ble _0807ABC6
_0807AC00:
	mov r6, r9
	movs r4, 0x6
	ldrsh r0, [r2, r4]
	adds r0, 0x4
	cmp r6, r0
	ble _0807ABAE
	b _0807ACB4
	.align 2, 0
_0807AC10: .4byte gDungeonGlobalData
_0807AC14: .4byte 0x00000671
_0807AC18: .4byte 0x00003a0c
_0807AC1C: .4byte 0x000104c4
_0807AC20:
	movs r5, 0x4
	ldrsh r0, [r2, r5]
	subs r1, r0, 0x4
	movs r5, 0x2
	ldrsh r4, [r3, r5]
	mov r10, r4
	cmp r10, r1
	bge _0807AC32
	mov r10, r1
_0807AC32:
	adds r1, r0, 0x5
	movs r0, 0x6
	ldrsh r7, [r3, r0]
	cmp r7, r1
	ble _0807AC3E
	adds r7, r1, 0
_0807AC3E:
	movs r1, 0x6
	ldrsh r0, [r2, r1]
	subs r2, r0, 0x4
	movs r4, 0x4
	ldrsh r1, [r3, r4]
	cmp r1, r2
	bge _0807AC4E
	adds r1, r2, 0
_0807AC4E:
	adds r0, 0x5
	movs r5, 0x8
	ldrsh r2, [r3, r5]
	cmp r2, r0
	ble _0807AC5A
	adds r2, r0, 0
_0807AC5A:
	adds r6, r1, 0
	cmp r6, r2
	bge _0807ACB4
_0807AC60:
	mov r4, r10
	adds r0, r6, 0x1
	mov r9, r0
	cmp r4, r7
	bge _0807ACAE
	mov r1, r8
	lsls r0, r1, 2
	mov r1, sp
	adds r5, r0, r1
_0807AC72:
	adds r0, r4, 0
	adds r1, r6, 0
	str r2, [sp, 0x1A4]
	bl GetMapTile_2
	adds r1, r0, 0
	ldr r0, [r1, 0x10]
	ldr r2, [sp, 0x1A4]
	cmp r0, 0
	bne _0807ACA8
	ldrh r1, [r1]
	movs r0, 0x3
	ands r0, r1
	cmp r0, 0x1
	bne _0807ACA8
	movs r0, 0x40
	ands r0, r1
	cmp r0, 0
	beq _0807ACA8
	mov r0, r8
	cmp r0, 0x63
	bgt _0807ACA8
	strh r4, [r5]
	strh r6, [r5, 0x2]
	adds r5, 0x4
	movs r1, 0x1
	add r8, r1
_0807ACA8:
	adds r4, 0x1
	cmp r4, r7
	blt _0807AC72
_0807ACAE:
	mov r6, r9
	cmp r6, r2
	blt _0807AC60
_0807ACB4:
	ldr r0, _0807AD74
	movs r2, 0
	ldrsh r0, [r0, r2]
	ldr r1, _0807AD78
	movs r4, 0
	ldrsh r1, [r1, r4]
	bl DungeonRandomRange
	adds r7, r0, 0
	cmp r7, r8
	blt _0807ACCC
	mov r7, r8
_0807ACCC:
	movs r6, 0
	cmp r6, r7
	bge _0807ADA0
	mov r10, r6
_0807ACD4:
	mov r0, r8
	bl DungeonRandomCapped
	adds r2, r0, 0
	movs r3, 0
	cmp r3, r8
	bge _0807AD0C
	lsls r0, r2, 2
	mov r5, sp
	adds r1, r5, r0
	movs r4, 0
	ldrsh r1, [r1, r4]
	adds r5, r0, 0
	cmp r1, 0
	bne _0807AD1C
_0807ACF2:
	adds r2, 0x1
	cmp r2, r8
	blt _0807ACFA
	movs r2, 0
_0807ACFA:
	adds r3, 0x1
	cmp r3, r8
	bge _0807AD0C
	lsls r0, r2, 2
	add r0, sp
	movs r5, 0
	ldrsh r0, [r0, r5]
	cmp r0, 0
	beq _0807ACF2
_0807AD0C:
	lsls r0, r2, 2
	mov r2, sp
	adds r1, r2, r0
	movs r4, 0
	ldrsh r1, [r1, r4]
	adds r5, r0, 0
	cmp r1, 0
	beq _0807ADA0
_0807AD1C:
	movs r0, 0x1
	bl sub_803D970
	add r4, sp, 0x190
	movs r1, 0
	strh r0, [r4]
	mov r0, r10
	strh r0, [r4, 0x8]
	strb r1, [r4, 0x2]
	mov r1, r10
	str r1, [r4, 0x4]
	movs r0, 0x1
	strb r0, [r4, 0x10]
	mov r2, sp
	adds r1, r2, r5
	ldrh r0, [r1]
	strh r0, [r4, 0xC]
	ldrh r0, [r1, 0x2]
	strh r0, [r4, 0xE]
	movs r5, 0
	ldrsh r0, [r4, r5]
	movs r1, 0x1
	bl sub_806AA0C
	lsls r0, 24
	adds r6, 0x1
	mov r9, r6
	cmp r0, 0
	beq _0807AD9A
	adds r0, r4, 0
	movs r1, 0
	bl sub_806B7F8
	adds r4, r0, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	beq _0807AD9A
	movs r0, 0xC8
	lsls r0, 8
	str r0, [r4, 0x1C]
	movs r5, 0
	b _0807AD84
	.align 2, 0
_0807AD74: .4byte gUnknown_80F4DA2
_0807AD78: .4byte gUnknown_80F4DA4
_0807AD7C:
	movs r0, 0x57
	bl sub_803E46C
	adds r5, 0x1
_0807AD84:
	cmp r5, 0x63
	bgt _0807AD96
	ldr r0, [r4, 0x1C]
	movs r1, 0xAA
	bl sub_8009DA4
	str r0, [r4, 0x1C]
	cmp r0, 0xFF
	bgt _0807AD7C
_0807AD96:
	mov r0, r10
	str r0, [r4, 0x1C]
_0807AD9A:
	mov r6, r9
	cmp r6, r7
	blt _0807ACD4
_0807ADA0:
	movs r0, 0x1
	bl sub_804178C
_0807ADA6:
	add sp, 0x1A8
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_807AB38

        .align 2,0
