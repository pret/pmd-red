	#include "asm/constants/gba_constants.inc"
	#include "asm/macros.inc"

	.syntax unified

	.text

	thumb_func_start sub_8072778
sub_8072778:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0xD0
	mov r9, r1
	lsls r2, 24
	lsrs r2, 24
	str r2, [sp, 0xC4]
	lsls r3, 24
	lsrs r3, 24
	str r3, [sp, 0xC8]
	ldr r0, [r1, 0x70]
	mov r8, r0
	movs r1, 0
	str r1, [sp, 0xCC]
	ldrb r0, [r0, 0x6]
	cmp r0, 0
	beq _080727A8
	movs r2, 0
	str r2, [sp, 0xC8]
	movs r4, 0
	str r4, [sp, 0xC4]
_080727A8:
	mov r0, r8
	movs r2, 0x2
	ldrsh r1, [r0, r2]
	ldrb r2, [r0, 0x9]
	movs r4, 0xC
	ldrsh r3, [r0, r4]
	mov r0, sp
	bl sub_808E0AC
	adds r7, r0, 0
	add r4, sp, 0x20
	movs r1, 0x8C
	lsls r1, 1
	add r1, r8
	adds r0, r4, 0
	bl unk_CopyMoves4To8AndClearFlag2Unk4
	mov r10, r4
	cmp r7, 0
	beq _08072810
	adds r0, r7, 0
	bl DungeonRandInt
	movs r2, 0
	lsls r0, 1
	mov r1, sp
	adds r6, r1, r0
	mov r5, sp
	adds r5, 0x21
	mov r3, r10
_080727E4:
	lsls r0, r2, 3
	add r0, sp
	adds r0, 0x20
	ldrb r1, [r0]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	bne _08072806
	ldrh r1, [r6]
	adds r0, r3, 0
	bl InitPokemonMove
	ldrb r1, [r5]
	movs r0, 0x4
	orrs r0, r1
	strb r0, [r5]
	b _08072810
_08072806:
	adds r5, 0x8
	adds r3, 0x8
	adds r2, 0x1
	cmp r2, 0x7
	ble _080727E4
_08072810:
	movs r5, 0
	movs r4, 0x1
_08072814:
	movs r7, 0
	movs r2, 0
_08072818:
	lsls r0, r2, 3
	add r0, sp
	adds r0, 0x20
	ldrb r1, [r0]
	adds r0, r4, 0
	ands r0, r1
	cmp r0, 0
	beq _0807282A
	adds r7, 0x1
_0807282A:
	adds r2, 0x1
	cmp r2, 0x7
	ble _08072818
	cmp r7, 0x4
	bgt _080728D4
	movs r3, 0
	movs r5, 0
	cmp r3, r7
	bge _0807287C
	movs r4, 0x8C
	lsls r4, 1
	add r4, r8
	mov r6, r10
_08072844:
	lsls r0, r5, 3
	movs r2, 0x8C
	lsls r2, 1
	add r2, r8
	adds r2, r0
	ldr r0, [r6]
	ldr r1, [r6, 0x4]
	str r0, [r2]
	str r1, [r2, 0x4]
	ldrb r1, [r4, 0x1]
	movs r0, 0x4
	ands r0, r1
	cmp r0, 0
	beq _08072872
	movs r0, 0xFB
	ands r0, r1
	strb r0, [r4, 0x1]
	add r0, sp, 0x60
	adds r1, r4, 0
	movs r2, 0
	bl sub_80928C0
	movs r3, 0x1
_08072872:
	adds r4, 0x8
	adds r6, 0x8
	adds r5, 0x1
	cmp r5, r7
	blt _08072844
_0807287C:
	cmp r5, 0x3
	bgt _08072894
	movs r2, 0x8C
	lsls r2, 1
	movs r1, 0
_08072886:
	lsls r0, r5, 3
	add r0, r8
	adds r0, r2
	strb r1, [r0]
	adds r5, 0x1
	cmp r5, 0x3
	ble _08072886
_08072894:
	cmp r3, 0
	beq _08072928
	ldr r2, [sp, 0xC4]
	cmp r2, 0
	beq _08072928
	ldr r0, _080728C8
	mov r1, r8
	movs r2, 0
	bl SetMessageArgument_2
	ldr r0, _080728CC
	add r1, sp, 0x60
	bl strcpy
	mov r0, r9
	movs r1, 0x9C
	lsls r1, 1
	bl sub_80421C0
	ldr r0, _080728D0
	ldr r1, [r0]
	mov r0, r9
	bl sub_80528F4
	b _08072928
	.align 2, 0
_080728C8: .4byte gAvailablePokemonNames
_080728CC: .4byte gFormatItems
_080728D0: .4byte gUnknown_80F9F04
_080728D4:
	mov r1, r8
	ldrb r0, [r1, 0x6]
	cmp r0, 0
	bne _08072918
	ldr r2, [sp, 0xC8]
	cmp r2, 0
	beq _08072918
	ldr r0, [sp, 0xCC]
	cmp r0, 0
	bne _08072902
	ldr r1, [sp, 0xC4]
	cmp r1, 0
	beq _08072902
	movs r0, 0xA
	movs r1, 0x6
	bl sub_803E708
	ldr r0, _08072914
	ldr r1, [r0]
	movs r0, 0
	movs r2, 0x1
	bl DisplayDungeonMessage
_08072902:
	movs r2, 0x1
	str r2, [sp, 0xCC]
	mov r0, r9
	mov r1, r10
	movs r3, 0
	bl sub_8063E70
	b _08072920
	.align 2, 0
_08072914: .4byte gUnknown_80F9FA4
_08072918:
	mov r0, r9
	mov r1, r10
	bl sub_8072B24
_08072920:
	adds r5, 0x1
	cmp r5, 0x1D
	bgt _08072928
	b _08072814
_08072928:
	add sp, 0xD0
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_8072778

	thumb_func_start sub_8072938
sub_8072938:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0xA4
	mov r9, r0
	lsls r1, 16
	lsrs r5, r1, 16
	ldr r0, [r0, 0x70]
	mov r8, r0
	movs r1, 0
	mov r10, r1
	movs r1, 0x8C
	lsls r1, 1
	add r1, r8
	mov r0, sp
	bl unk_CopyMoves4To8AndClearFlag2Unk4
	movs r3, 0
	mov r4, sp
	mov r2, sp
_08072964:
	ldrb r1, [r4]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	bne _08072980
	adds r0, r2, 0
	adds r1, r5, 0
	bl InitPokemonMove
	ldrb r1, [r4, 0x1]
	movs r0, 0x4
	orrs r0, r1
	strb r0, [r4, 0x1]
	b _0807298A
_08072980:
	adds r4, 0x8
	adds r2, 0x8
	adds r3, 0x1
	cmp r3, 0x7
	ble _08072964
_0807298A:
	movs r4, 0
	movs r5, 0x1
_0807298E:
	movs r7, 0
	mov r2, sp
	movs r3, 0x7
_08072994:
	ldrb r1, [r2]
	adds r0, r5, 0
	ands r0, r1
	cmp r0, 0
	beq _080729A0
	adds r7, 0x1
_080729A0:
	adds r2, 0x8
	subs r3, 0x1
	cmp r3, 0
	bge _08072994
	cmp r7, 0x4
	bgt _08072A50
	movs r5, 0
	cmp r5, r7
	bge _080729F4
	movs r4, 0x8C
	lsls r4, 1
	add r4, r8
	mov r6, sp
_080729BA:
	lsls r0, r5, 3
	movs r2, 0x8C
	lsls r2, 1
	add r2, r8
	adds r2, r0
	ldr r0, [r6]
	ldr r1, [r6, 0x4]
	str r0, [r2]
	str r1, [r2, 0x4]
	ldrb r1, [r4, 0x1]
	movs r0, 0x4
	ands r0, r1
	cmp r0, 0
	beq _080729EA
	movs r0, 0xFB
	ands r0, r1
	strb r0, [r4, 0x1]
	add r0, sp, 0x40
	adds r1, r4, 0
	movs r2, 0
	bl sub_80928C0
	movs r0, 0x1
	mov r10, r0
_080729EA:
	adds r4, 0x8
	adds r6, 0x8
	adds r5, 0x1
	cmp r5, r7
	blt _080729BA
_080729F4:
	cmp r5, 0x3
	bgt _08072A0C
	movs r2, 0x8C
	lsls r2, 1
	movs r1, 0
_080729FE:
	lsls r0, r5, 3
	add r0, r8
	adds r0, r2
	strb r1, [r0]
	adds r5, 0x1
	cmp r5, 0x3
	ble _080729FE
_08072A0C:
	mov r1, r10
	cmp r1, 0
	beq _08072A92
	mov r1, r8
	ldrb r0, [r1, 0x6]
	cmp r0, 0
	bne _08072A8C
	ldr r0, _08072A44
	mov r1, r9
	movs r2, 0
	bl SetMessageArgument
	ldr r0, _08072A48
	add r1, sp, 0x40
	bl strcpy
	mov r0, r9
	movs r1, 0x9C
	lsls r1, 1
	bl sub_80421C0
	ldr r0, _08072A4C
	ldr r1, [r0]
	mov r0, r9
	bl sub_80528F4
	b _08072A8C
	.align 2, 0
_08072A44: .4byte gAvailablePokemonNames
_08072A48: .4byte gFormatItems
_08072A4C: .4byte gUnknown_80F9F04
_08072A50:
	movs r0, 0
	mov r10, r0
	mov r1, r8
	ldrb r0, [r1, 0x6]
	cmp r0, 0
	bne _08072A84
	ldr r0, _08072A80
	ldr r1, [r0]
	movs r0, 0
	movs r2, 0x1
	bl DisplayDungeonMessage
	mov r0, r9
	mov r1, sp
	movs r2, 0x1
	movs r3, 0x1
	bl sub_8063E70
	lsls r0, 24
	cmp r0, 0
	bne _08072A84
	movs r0, 0
	b _08072AB0
	.align 2, 0
_08072A80: .4byte gUnknown_80FDF40
_08072A84:
	adds r4, 0x1
	cmp r4, 0x1D
	bgt _08072A8C
	b _0807298E
_08072A8C:
	mov r0, r10
	cmp r0, 0
	bne _08072AAE
_08072A92:
	mov r1, r8
	ldrb r0, [r1, 0x6]
	cmp r0, 0
	bne _08072AAE
	ldr r0, _08072AC0
	mov r1, r9
	movs r2, 0
	bl SetMessageArgument
	ldr r0, _08072AC4
	ldr r1, [r0]
	mov r0, r9
	bl sub_80528F4
_08072AAE:
	movs r0, 0x1
_08072AB0:
	add sp, 0xA4
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	.align 2, 0
_08072AC0: .4byte gAvailablePokemonNames
_08072AC4: .4byte gUnknown_80F9F2C
	thumb_func_end sub_8072938

	.align 2, 0
