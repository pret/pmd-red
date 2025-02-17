	#include "asm/constants/gba_constants.inc"
  	#include "asm/macros.inc"

  	.syntax unified

  	.text



	thumb_func_start sub_8067794
sub_8067794:
	push {r4-r7,lr}
	sub sp, 0x40
	adds r7, r1, 0
	ldr r4, [r7, 0x70]
	cmp r7, 0
	bne _080677B4
	ldr r0, _080677B0
	ldr r1, [r0]
	movs r0, 0
	movs r2, 0x1
	bl DisplayDungeonMessage
	b _0806786C
	.align 2, 0
_080677B0: .4byte gCannotFarewell
_080677B4:
	ldr r0, _080677F0
	adds r1, r7, 0
	movs r2, 0
	bl SubstitutePlaceholderStringTags
	ldr r0, _080677F4
	ldr r5, [r0]
	ldr r0, _080677F8
	ldr r6, [r0]
	ldrb r2, [r4, 0xA]
	cmp r2, 0
	blt _08067834
	ldr r1, _080677FC
	movs r0, 0x64
	muls r0, r2
	ldr r2, _08067800
	adds r0, r2
	ldr r1, [r1]
	adds r4, r1, r0
	movs r1, 0xA
	ldrsh r0, [r4, r1]
	bl sub_806A564
	lsls r0, 24
	cmp r0, 0
	beq _0806780C
	ldr r0, _08067804
	ldr r5, [r0]
	ldr r0, _08067808
	b _08067832
	.align 2, 0
_080677F0: .4byte gFormatBuffer_Monsters
_080677F4: .4byte gSayFarewellQ
_080677F8: .4byte gUnknown_80F913C
_080677FC: .4byte gRecruitedPokemonRef
_08067800: .4byte 0x00008df8
_08067804: .4byte gUnknown_80F9114
_08067808: .4byte gMonDisappointedAndLeft
_0806780C:
	movs r2, 0xA
	ldrsh r0, [r4, r2]
	bl sub_806A58C
	lsls r0, 24
	cmp r0, 0
	beq _08067834
	bl IsMakuhitaTrainingMaze
	lsls r0, 24
	cmp r0, 0
	beq _0806782C
	ldr r0, _08067828
	b _0806782E
	.align 2, 0
_08067828: .4byte gSendMonBackQ
_0806782C:
	ldr r0, _08067874
_0806782E:
	ldr r5, [r0]
	ldr r0, _08067878
_08067832:
	ldr r6, [r0]
_08067834:
	movs r0, 0
	adds r1, r5, 0
	movs r2, 0
	bl DisplayDungeonYesNoMessage
	cmp r0, 0x1
	bne _0806786C
	ldr r4, _0806787C
	mov r0, sp
	adds r1, r4, 0
	movs r2, 0x40
	bl strncpy
	ldr r1, _08067880
	adds r0, r7, 0
	movs r2, 0
	bl sub_8068FE0
	adds r0, r4, 0
	mov r1, sp
	movs r2, 0x40
	bl strncpy
	movs r0, 0
	adds r1, r6, 0
	movs r2, 0x1
	bl DisplayDungeonMessage
_0806786C:
	add sp, 0x40
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_08067874: .4byte gSendMonBackWithItemQ
_08067878: .4byte gMonWentBack
_0806787C: .4byte gFormatBuffer_Monsters
_08067880: .4byte 0x0000021d
	thumb_func_end sub_8067794

	thumb_func_start HandleUseMovePlayerAction
HandleUseMovePlayerAction:
	push {r4-r6,lr}
	sub sp, 0x4
	adds r5, r0, 0
	movs r6, 0
	b _0806789A
_0806788E:
	ldr r1, _08067900
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, 0
	bne _080678C6
	adds r6, 0x1
_0806789A:
	adds r0, r5, 0
	movs r1, 0x1
	bl sub_8070828
	cmp r6, r0
	bge _080678C6
	ldr r4, [r5, 0x70]
	adds r0, r4, 0
	adds r0, 0x50
	ldrb r1, [r0]
	movs r0, 0
	str r0, [sp]
	adds r0, r5, 0
	movs r2, 0x1
	movs r3, 0
	bl sub_8055A00
	bl sub_8044B28
	lsls r0, 24
	cmp r0, 0
	beq _0806788E
_080678C6:
	adds r0, r5, 0
	movs r1, 0x1
	bl sub_8057588
	bl sub_8044B28
	lsls r0, 24
	cmp r0, 0
	bne _080678F6
	adds r0, r5, 0
	bl EntityIsValid
	lsls r0, 24
	cmp r0, 0
	beq _080678F0
	ldr r0, [r5, 0x70]
	adds r0, 0x50
	ldrb r1, [r0]
	adds r0, r5, 0
	bl sub_806A9B4
_080678F0:
	adds r0, r5, 0
	bl sub_806A1B0
_080678F6:
	add sp, 0x4
	pop {r4-r6}
	pop {r0}
	bx r0
	.align 2, 0
_08067900: .4byte 0x00000159
	thumb_func_end HandleUseMovePlayerAction

	thumb_func_start sub_8067904
sub_8067904:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x14
	adds r5, r0, 0
	lsls r1, 16
	lsrs r1, 16
	mov r9, r1
	ldr r6, [r5, 0x70]
	ldr r1, _08067940
	movs r0, 0
	str r0, [r1]
	add r0, sp, 0x8
	mov r1, r9
	bl InitPokemonMove
	adds r0, r6, 0
	adds r0, 0xBC
	ldrb r0, [r0]
	cmp r0, 0x1
	bne _0806794C
	ldr r0, _08067944
	adds r1, r5, 0
	movs r2, 0
	bl SubstitutePlaceholderStringTags
	ldr r0, _08067948
	b _08067962
	.align 2, 0
_08067940: .4byte gUnknown_202F208
_08067944: .4byte gFormatBuffer_Monsters
_08067948: .4byte gMonCringing
_0806794C:
	adds r0, r6, 0
	adds r0, 0xAC
	ldrb r0, [r0]
	cmp r0, 0x4
	bne _08067974
	ldr r0, _0806796C
	adds r1, r5, 0
	movs r2, 0
	bl SubstitutePlaceholderStringTags
	ldr r0, _08067970
_08067962:
	ldr r1, [r0]
	adds r0, r5, 0
	bl LogMessageByIdWithPopupCheckUser
	b _08067A56
	.align 2, 0
_0806796C: .4byte gFormatBuffer_Monsters
_08067970: .4byte gMonParalyzed
_08067974:
	movs r0, 0xB0
	lsls r0, 1
	movs r1, 0
	mov r10, r1
	cmp r9, r0
	bne _08067984
	movs r2, 0x1
	mov r10, r2
_08067984:
	movs r0, 0
	mov r8, r0
	movs r7, 0
	add r4, sp, 0x8
	b _080679D2
_0806798E:
	movs r1, 0xBC
	lsls r1, 1
	adds r0, r6, r1
	strh r7, [r0]
	ldrb r0, [r4]
	movs r1, 0x8
	orrs r0, r1
	orrs r0, r7
	movs r1, 0x4
	orrs r0, r1
	strb r0, [r4]
	movs r0, 0xA
	strb r0, [r4, 0x4]
	str r7, [sp]
	str r4, [sp, 0x4]
	adds r0, r5, 0
	mov r1, r10
	movs r2, 0
	movs r3, 0
	bl TryUseChosenMove
	adds r0, r5, 0
	bl EntityIsValid
	lsls r0, 24
	cmp r0, 0
	beq _080679DE
	ldr r2, _08067A68
	adds r0, r6, r2
	ldrb r0, [r0]
	cmp r0, 0
	bne _080679DE
	movs r0, 0x1
	add r8, r0
_080679D2:
	adds r0, r5, 0
	movs r1, 0x1
	bl sub_8070828
	cmp r8, r0
	blt _0806798E
_080679DE:
	adds r0, r5, 0
	bl EntityIsValid
	lsls r0, 24
	cmp r0, 0
	beq _08067A56
	movs r0, 0xB0
	lsls r0, 1
	cmp r9, r0
	bne _08067A04
	ldr r0, _08067A6C
	ldr r0, [r0]
	cmp r0, 0
	bne _08067A04
	ldr r0, _08067A70
	ldr r1, [r0]
	adds r0, r5, 0
	bl LogMessageByIdWithPopupCheckUser
_08067A04:
	ldrb r0, [r6, 0x7]
	cmp r0, 0
	beq _08067A50
	movs r0, 0xB0
	lsls r0, 1
	cmp r9, r0
	beq _08067A50
	ldr r4, _08067A74
	adds r3, r6, 0
	adds r3, 0x46
	ldrb r0, [r3]
	lsls r0, 2
	adds r0, r4
	ldrh r0, [r0]
	ldrh r1, [r5, 0x4]
	adds r0, r1
	lsls r0, 16
	lsrs r0, 16
	ldr r2, _08067A78
	ldr r1, [sp, 0x10]
	ands r1, r2
	orrs r1, r0
	str r1, [sp, 0x10]
	ldrb r0, [r3]
	lsls r0, 2
	adds r0, r4
	ldrh r0, [r0, 0x2]
	ldrh r2, [r5, 0x6]
	adds r0, r2
	lsls r0, 16
	ldr r2, _08067A7C
	ands r1, r2
	orrs r1, r0
	str r1, [sp, 0x10]
	add r0, sp, 0x10
	movs r1, 0x1
	bl sub_807FE44
_08067A50:
	adds r0, r5, 0
	bl sub_8071DA4
_08067A56:
	add sp, 0x14
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_08067A68: .4byte 0x00000159
_08067A6C: .4byte gUnknown_202F208
_08067A70: .4byte gUnknown_80FC690
_08067A74: .4byte gAdjacentTileOffsets
_08067A78: .4byte 0xffff0000
_08067A7C: .4byte 0x0000ffff
	thumb_func_end sub_8067904

	thumb_func_start sub_8067A80
sub_8067A80:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x6C
	str r1, [sp, 0x68]
	mov r8, r2
	mov r9, r3
	lsls r0, 24
	lsrs r0, 24
	str r0, [sp, 0x64]
	ldr r1, _08067AC8
	add r0, sp, 0x4
	movs r2, 0x60
	bl memcpy
	ldr r1, _08067ACC
	movs r0, 0
	str r0, [r1]
	mov r10, r0
	cmp r10, r8
	blt _08067AB0
	b _08067ED8
_08067AB0:
	ldr r5, _08067AD0
	mov r4, r9
	mov r3, r8
_08067AB6:
	ldm r4!, {r2}
	ldrh r1, [r2]
	adds r0, r5, 0
	ands r0, r1
	strh r0, [r2]
	subs r3, 0x1
	cmp r3, 0
	bne _08067AB6
	b _08067ED8
	.align 2, 0
_08067AC8: .4byte gUnknown_8106DC8
_08067ACC: .4byte gUnknown_202F30C
_08067AD0: .4byte 0x00007fff
_08067AD4:
	movs r7, 0
	ldr r1, _08067B98
	movs r0, 0x1
	strb r0, [r1]
	strb r7, [r1, 0x1]
	movs r0, 0xE
	strb r0, [r1, 0x2]
	strb r7, [r1, 0x3]
	add r0, sp, 0x4
	movs r1, 0x1
	bl sub_803ECB4
	ldr r5, _08067B9C
	ldr r2, [r5]
	ldr r0, [sp, 0x68]
	str r0, [sp]
	ldr r0, [sp, 0x64]
	mov r1, r9
	mov r3, r8
	bl sub_8067F00
	ldr r4, _08067BA0
	mov r0, r8
	cmp r0, 0x8
	ble _08067B08
	movs r0, 0x8
_08067B08:
	strh r0, [r4, 0x1A]
	mov r1, r10
	strh r1, [r4, 0x18]
	movs r0, 0x8
	strh r0, [r4, 0x1C]
	strh r7, [r4, 0x1E]
	strh r7, [r4, 0x20]
	strh r7, [r4, 0x4]
	movs r0, 0x12
	strh r0, [r4, 0x6]
	strh r7, [r4, 0xC]
	strh r7, [r4, 0xE]
	strh r7, [r4, 0x14]
	str r7, [r4]
	adds r0, r4, 0
	adds r0, 0x28
	bl sub_801317C
	adds r0, r4, 0
	movs r1, 0
	bl sub_80137B0
	adds r6, r5, 0
_08067B36:
	ldr r0, _08067BA0
	bl AddMenuCursorSprite
	movs r5, 0
	movs r7, 0
	ldr r0, [r6]
	mov r2, r8
	subs r0, r2, r0
	cmp r0, 0x8
	ble _08067B50
	movs r5, 0x1
	bl sub_80684C4
_08067B50:
	ldr r0, [r6]
	cmp r0, 0
	beq _08067B5C
	movs r7, 0x1
	bl sub_8068344
_08067B5C:
	movs r0, 0
	ldr r1, _08067BA4
	bl sub_8014140
	adds r4, r0, 0
	movs r0, 0x37
	bl sub_803E46C
	cmp r4, 0x2
	bne _08067BAC
	cmp r5, 0
	beq _08067BAC
	ldr r0, [r6]
	mov r3, r8
	subs r0, r3, r0
	cmp r0, 0x8
	ble _08067BF0
	ldr r5, _08067BA8
	movs r4, 0x5
_08067B82:
	ldr r1, [r5]
	movs r0, 0
	bl _call_via_r1
	movs r0, 0x37
	bl sub_803E46C
	subs r4, 0x1
	cmp r4, 0
	bge _08067B82
	b _08067BEA
	.align 2, 0
_08067B98: .4byte gUnknown_202F308
_08067B9C: .4byte gUnknown_202F30C
_08067BA0: .4byte gUnknown_202EE10
_08067BA4: .4byte gUnknown_8106DA4
_08067BA8: .4byte gIwramTextFunc1
_08067BAC:
	ldr r0, _08067BF8
	ldrh r1, [r0, 0x4]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	beq _08067C0C
	movs r0, 0x1
	bl sub_8083CE0
	ldr r1, _08067BFC
	movs r2, 0x18
	ldrsh r0, [r1, r2]
	cmp r0, 0x7
	bne _08067C04
	ldr r0, [r6]
	mov r3, r8
	subs r0, r3, r0
	cmp r0, 0x8
	ble _08067BF0
	ldr r5, _08067C00
	movs r4, 0x5
_08067BD6:
	ldr r1, [r5]
	movs r0, 0
	bl _call_via_r1
	movs r0, 0x37
	bl sub_803E46C
	subs r4, 0x1
	cmp r4, 0
	bge _08067BD6
_08067BEA:
	ldr r0, [r6]
	adds r0, 0x1
	str r0, [r6]
_08067BF0:
	movs r7, 0
	movs r0, 0x7
	mov r10, r0
	b _08067CF6
	.align 2, 0
_08067BF8: .4byte gRealInputs
_08067BFC: .4byte gUnknown_202EE10
_08067C00: .4byte gIwramTextFunc1
_08067C04:
	adds r0, r1, 0
	movs r1, 0
	bl sub_80136E0
_08067C0C:
	cmp r4, 0x1
	bne _08067C44
	cmp r7, 0
	beq _08067C44
	ldr r0, [r6]
	cmp r0, 0
	beq _08067C38
	ldr r5, _08067C40
	movs r4, 0x5
_08067C1E:
	ldr r1, [r5]
	movs r0, 0
	bl _call_via_r1
	movs r0, 0x37
	bl sub_803E46C
	subs r4, 0x1
	cmp r4, 0
	bge _08067C1E
	ldr r0, [r6]
	subs r0, 0x1
	str r0, [r6]
_08067C38:
	movs r7, 0
	movs r1, 0
	mov r10, r1
	b _08067CF6
	.align 2, 0
_08067C40: .4byte gIwramTextFunc2
_08067C44:
	ldr r0, _08067C8C
	ldrh r1, [r0, 0x4]
	movs r0, 0x40
	ands r0, r1
	cmp r0, 0
	beq _08067CA0
	movs r0, 0x1
	bl sub_8083CE0
	ldr r1, _08067C90
	movs r2, 0x18
	ldrsh r0, [r1, r2]
	cmp r0, 0
	bne _08067C98
	ldr r0, [r6]
	cmp r0, 0
	beq _08067C84
	ldr r5, _08067C94
	movs r4, 0x5
_08067C6A:
	ldr r1, [r5]
	movs r0, 0
	bl _call_via_r1
	movs r0, 0x37
	bl sub_803E46C
	subs r4, 0x1
	cmp r4, 0
	bge _08067C6A
	ldr r0, [r6]
	subs r0, 0x1
	str r0, [r6]
_08067C84:
	movs r7, 0
	movs r3, 0
	mov r10, r3
	b _08067CF6
	.align 2, 0
_08067C8C: .4byte gRealInputs
_08067C90: .4byte gUnknown_202EE10
_08067C94: .4byte gIwramTextFunc2
_08067C98:
	adds r0, r1, 0
	movs r1, 0
	bl sub_8013744
_08067CA0:
	bl sub_80048C8
	lsls r0, 24
	cmp r0, 0
	beq _08067CAC
	b _08067B36
_08067CAC:
	ldr r0, _08067CD4
	ldrh r1, [r0, 0x2]
	movs r0, 0x8
	ands r0, r1
	cmp r0, 0
	bne _08067D40
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	bne _08067CCC
	ldr r2, _08067CD8
	adds r0, r2, 0
	adds r0, 0x29
	ldrb r0, [r0]
	cmp r0, 0
	beq _08067CDC
_08067CCC:
	bl sub_8083D08
	movs r7, 0x1
	b _08067CF6
	.align 2, 0
_08067CD4: .4byte gRealInputs
_08067CD8: .4byte gUnknown_202EE10
_08067CDC:
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	bne _08067CF0
	adds r0, r2, 0
	adds r0, 0x2A
	ldrb r0, [r0]
	cmp r0, 0
	bne _08067CF0
	b _08067B36
_08067CF0:
	bl sub_8083D30
	movs r7, 0x2
_08067CF6:
	ldr r4, _08067D34
	adds r0, r4, 0
	bl AddMenuCursorSprite
	movs r0, 0x37
	bl sub_803E46C
	cmp r7, 0
	bne _08067D0A
	b _08067AD4
_08067D0A:
	cmp r7, 0x2
	bne _08067D48
	movs r1, 0x18
	ldrsh r0, [r4, r1]
	mov r10, r0
	ldr r0, _08067D38
	ldr r0, [r0]
	ldr r2, [sp, 0x68]
	cmp r0, r2
	bge _08067D20
	b _08067AD4
_08067D20:
	ldr r0, _08067D3C
	ldr r1, [r0]
	movs r0, 0
	movs r2, 0x1
	bl DisplayDungeonYesNoMessage
	cmp r0, 0x1
	bne _08067D32
	b _08067ED8
_08067D32:
	b _08067AD4
	.align 2, 0
_08067D34: .4byte gUnknown_202EE10
_08067D38: .4byte gUnknown_202F310
_08067D3C: .4byte gUnknown_80FDFB8
_08067D40:
	bl sub_8083D1C
	movs r7, 0x3
	b _08067CF6
_08067D48:
	cmp r7, 0x3
	bne _08067D64
	movs r0, 0x18
	ldrsh r3, [r4, r0]
	mov r10, r3
	ldr r0, _08067D60
	ldr r0, [r0]
	add r0, r10
	lsls r0, 2
	add r0, r9
	b _08067ED0
	.align 2, 0
_08067D60: .4byte gUnknown_202F30C
_08067D64:
	movs r2, 0x18
	ldrsh r1, [r4, r2]
	mov r10, r1
	ldr r0, _08067DAC
	ldr r0, [r0]
	adds r4, r0, r1
	ldr r1, _08067DB0
	movs r0, 0
	str r0, [r1]
	movs r0, 0x29
	movs r1, 0
	bl sub_8044F5C
	movs r0, 0x2A
	movs r1, 0
	bl sub_8044F5C
	movs r0, 0x40
	movs r1, 0
	bl sub_8044F5C
	lsls r0, r4, 2
	add r0, r9
	ldr r0, [r0]
	ldrh r0, [r0]
	movs r3, 0x80
	lsls r3, 8
	adds r1, r3, 0
	ands r0, r1
	cmp r0, 0
	beq _08067DBC
	movs r0, 0x29
	bl sub_8044FF0
	b _08067DC2
	.align 2, 0
_08067DAC: .4byte gUnknown_202F30C
_08067DB0: .4byte gUnknown_202EE6C
_08067DB4:
	bl sub_8083D08
	movs r7, 0x1
	b _08067E6E
_08067DBC:
	movs r0, 0x2A
	bl sub_8044FF0
_08067DC2:
	lsls r0, r4, 2
	mov r2, r9
	adds r1, r0, r2
	ldr r2, [r1]
	ldrb r1, [r2, 0x2]
	adds r6, r0, 0
	cmp r1, 0
	bne _08067DDC
	ldrb r1, [r2, 0x4]
	cmp r1, 0x40
	beq _08067DDC
	cmp r1, 0x41
	bne _08067DE2
_08067DDC:
	movs r0, 0x29
	bl sub_8044FF0
_08067DE2:
	bl sub_8045064
	add r0, sp, 0x4
	movs r1, 0x15
	bl sub_805FC30
	ldr r4, _08067EA0
	ldr r5, _08067EA4
	adds r7, r4, 0
	adds r7, 0x2A
_08067DF6:
	adds r0, r4, 0
	bl AddMenuCursorSprite
	movs r0, 0x37
	bl sub_803E46C
	ldrh r1, [r5, 0x4]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	beq _08067E1A
	movs r0, 0x1
	bl sub_8083CE0
	adds r0, r4, 0
	movs r1, 0x1
	bl sub_80136E0
_08067E1A:
	ldrh r1, [r5, 0x4]
	movs r0, 0x40
	ands r0, r1
	cmp r0, 0
	beq _08067E32
	movs r0, 0x1
	bl sub_8083CE0
	adds r0, r4, 0
	movs r1, 0x1
	bl sub_8013744
_08067E32:
	ldrh r1, [r5, 0x2]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	bne _08067E46
	adds r0, r4, 0
	adds r0, 0x29
	ldrb r0, [r0]
	cmp r0, 0
	beq _08067E58
_08067E46:
	movs r3, 0x18
	ldrsh r0, [r4, r3]
	bl sub_8044F3C
	lsls r0, 24
	cmp r0, 0
	bne _08067DB4
	bl sub_8083D30
_08067E58:
	ldrh r1, [r5, 0x2]
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	bne _08067E68
	ldrb r0, [r7]
	cmp r0, 0
	beq _08067DF6
_08067E68:
	bl sub_8083D30
	movs r7, 0
_08067E6E:
	ldr r4, _08067EA0
	adds r0, r4, 0
	bl AddMenuCursorSprite
	movs r0, 0x37
	bl sub_803E46C
	cmp r7, 0
	bne _08067E82
	b _08067AD4
_08067E82:
	movs r1, 0x18
	ldrsh r0, [r4, r1]
	cmp r0, 0
	bne _08067EA8
	mov r2, r9
	adds r0, r6, r2
	ldr r1, [r0]
	ldrh r2, [r1]
	movs r3, 0x80
	lsls r3, 8
	adds r0, r3, 0
	orrs r0, r2
	strh r0, [r1]
	b _08067EBC
	.align 2, 0
_08067EA0: .4byte gUnknown_202EE10
_08067EA4: .4byte gRealInputs
_08067EA8:
	cmp r0, 0x1
	bne _08067ECC
	mov r1, r9
	adds r0, r6, r1
	ldr r2, [r0]
	ldrh r0, [r2]
	ldr r3, _08067EC8
	adds r1, r3, 0
	ands r0, r1
	strh r0, [r2]
_08067EBC:
	mov r0, r8
	mov r1, r9
	bl sub_8068310
	b _08067AD4
	.align 2, 0
_08067EC8: .4byte 0x00007fff
_08067ECC:
	mov r1, r9
	adds r0, r6, r1
_08067ED0:
	ldr r0, [r0]
	bl sub_806806C
	b _08067AD4
_08067ED8:
	mov r0, r8
	mov r1, r9
	bl sub_8068310
	ldr r0, _08067EFC
	ldr r0, [r0]
	ldr r2, [sp, 0x68]
	cmp r0, r2
	bge _08067EEC
	b _08067AD4
_08067EEC:
	add sp, 0x6C
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_08067EFC: .4byte gUnknown_202F310
	thumb_func_end sub_8067A80

	thumb_func_start sub_8067F00
sub_8067F00:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x8
	adds r4, r0, 0
	mov r9, r1
	str r3, [sp, 0x4]
	lsls r4, 24
	lsrs r4, 24
	subs r7, r2, 0x1
	movs r0, 0x16
	mov r8, r0
	movs r0, 0
	bl sub_80073B8
	ldr r0, _08067F44
	adds r1, r4, 0
	movs r2, 0
	bl WriteFriendAreaName
	ldr r2, _08067F48
	movs r0, 0
	str r0, [sp]
	movs r0, 0xC
	movs r1, 0
	movs r3, 0
	bl PrintFormattedStringOnWindow
	movs r1, 0
	mov r10, r1
	b _08067FF6
	.align 2, 0
_08067F44: .4byte gFormatBuffer_Monsters
_08067F48: .4byte gUnknown_8106E28
_08067F4C:
	ldr r4, _08067F8C
	lsls r6, r7, 2
	mov r0, r9
	adds r5, r6, r0
	ldr r1, [r5]
	adds r0, r4, 0
	movs r2, 0
	bl PrintColoredPokeNameToBuffer
	adds r4, 0x50
	ldr r0, [r5]
	movs r2, 0x8
	ldrsh r1, [r0, r2]
	adds r0, r4, 0
	bl sub_808D930
	ldr r1, _08067F90
	adds r0, r7, 0x1
	str r0, [r1]
	ldr r0, [r5]
	ldrh r1, [r0]
	movs r0, 0x80
	lsls r0, 8
	ands r0, r1
	cmp r0, 0
	beq _08067F9C
	ldr r0, _08067F94
	ldr r1, _08067F98
	bl strcpy
	b _08067FA4
	.align 2, 0
_08067F8C: .4byte gFormatBuffer_Monsters
_08067F90: .4byte gFormatArgs
_08067F94: .4byte gFormatBuffer_Items
_08067F98: .4byte gUnknown_8106E2C
_08067F9C:
	ldr r0, _08067FCC
	ldr r1, _08067FD0
	bl strcpy
_08067FA4:
	mov r1, r9
	adds r0, r6, r1
	ldr r0, [r0]
	ldrh r1, [r0]
	movs r0, 0x80
	lsls r0, 7
	ands r0, r1
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0
	beq _08067FD8
	ldr r2, _08067FD4
	movs r0, 0
	str r0, [sp]
	movs r0, 0x7
	mov r1, r8
	movs r3, 0
	bl PrintFormattedStringOnWindow
	b _08067FE6
	.align 2, 0
_08067FCC: .4byte gFormatBuffer_Items
_08067FD0: .4byte gUnknown_8106E30
_08067FD4: .4byte gUnknown_8106E34
_08067FD8:
	ldr r2, _08068028
	str r0, [sp]
	movs r0, 0x7
	mov r1, r8
	movs r3, 0
	bl PrintFormattedStringOnWindow
_08067FE6:
	movs r2, 0x1
	add r10, r2
	movs r0, 0xC
	add r8, r0
	adds r7, 0x1
	mov r1, r10
	cmp r1, 0x9
	bgt _08068000
_08067FF6:
	cmp r7, 0
	blt _08067FE6
	ldr r2, [sp, 0x4]
	cmp r7, r2
	blt _08067F4C
_08068000:
	movs r0, 0
	bl sub_80073E0
	movs r0, 0x1
	bl sub_80073B8
	ldr r0, _0806802C
	ldr r0, [r0]
	ldr r1, [sp, 0x28]
	cmp r0, r1
	blt _08068034
	ldr r2, _08068030
	movs r0, 0
	str r0, [sp]
	movs r0, 0x8
	movs r1, 0x2
	movs r3, 0x1
	bl PrintFormattedStringOnWindow
	b _0806804C
	.align 2, 0
_08068028: .4byte gUnknown_8106E48
_0806802C: .4byte gUnknown_202F310
_08068030: .4byte gUnknown_8106E5C
_08068034:
	ldr r1, _08068064
	ldr r2, [sp, 0x28]
	subs r0, r2, r0
	str r0, [r1]
	ldr r2, _08068068
	movs r0, 0
	str r0, [sp]
	movs r0, 0x8
	movs r1, 0x2
	movs r3, 0x1
	bl PrintFormattedStringOnWindow
_0806804C:
	movs r0, 0x1
	bl sub_80073E0
	add sp, 0x8
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_08068064: .4byte gFormatArgs
_08068068: .4byte gUnknown_8106E6C
	thumb_func_end sub_8067F00

	thumb_func_start sub_806806C
sub_806806C:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x110
	str r0, [sp, 0x108]
	add r4, sp, 0x98
	adds r0, r4, 0
	movs r1, 0
	movs r2, 0x60
	bl memset
	movs r0, 0x6
	str r0, [r4, 0x4]
	movs r1, 0x2
	strh r1, [r4, 0x8]
	strh r1, [r4, 0xA]
	movs r2, 0x12
	strh r2, [r4, 0xC]
	movs r0, 0xE
	strh r0, [r4, 0xE]
	strh r2, [r4, 0x10]
	strh r1, [r4, 0x12]
	ldr r0, _080681B4
	str r0, [r4, 0x14]
	movs r0, 0x3
	str r0, [r4, 0x1C]
	str r0, [r4, 0x34]
	str r0, [r4, 0x4C]
	movs r7, 0
	add r1, sp, 0x44
	strh r7, [r1]
	mov r0, sp
	adds r0, 0x5A
	strh r7, [r0]
	ldr r0, _080681B8
	strh r7, [r0, 0x18]
	mov r9, r1
	adds r1, 0xB4
	str r1, [sp, 0x10C]
	add r2, sp, 0x68
	mov r10, r2
	adds r6, r0, 0
_080680C4:
	movs r3, 0
	mov r8, r3
	add r1, sp, 0xF8
	ldr r0, _080681BC
	ldm r0!, {r2-r4}
	stm r1!, {r2-r4}
	ldr r0, [r0]
	str r0, [r1]
	ldr r1, _080681B4
	movs r2, 0x4
	strb r2, [r1]
	strb r7, [r1, 0x1]
	movs r0, 0xA
	strb r0, [r1, 0x2]
	mov r4, r8
	strb r4, [r1, 0x3]
	strh r7, [r6, 0x1E]
	strh r2, [r6, 0x20]
	mov r0, r8
	strh r0, [r6, 0x1A]
	strh r0, [r6, 0x18]
	strh r0, [r6, 0x1C]
	strh r0, [r6, 0x4]
	movs r0, 0x10
	strh r0, [r6, 0x6]
	mov r1, r8
	strh r1, [r6, 0x14]
	mov r2, r8
	str r2, [r6]
	adds r0, r6, 0
	adds r0, 0x28
	bl sub_801317C
	add r0, sp, 0x98
	movs r1, 0x1
	bl sub_803ECB4
	ldr r0, _080681C0
	ldr r0, [r0]
	ldr r3, _080681C4
	adds r0, r3
	ldrb r2, [r0]
	add r0, sp, 0x4
	ldr r1, [sp, 0x108]
	bl sub_808FF20
	lsls r4, r7, 2
	mov r0, sp
	adds r0, r4
	adds r0, 0xF8
	ldr r0, [r0]
	mov r1, r8
	str r1, [sp]
	adds r1, r7, 0
	add r2, sp, 0x4
	mov r3, r10
	bl CreatePokemonInfoTabScreen
	ldr r1, _080681C8
	movs r2, 0
	ldrsh r0, [r1, r2]
	adds r0, 0xF
	lsls r0, 3
	strh r0, [r6, 0xC]
	movs r3, 0x2
	ldrsh r0, [r1, r3]
	adds r0, 0x1
	lsls r0, 3
	subs r0, 0x2
	strh r0, [r6, 0xE]
_08068150:
	ldr r0, _080681B8
	bl AddMenuCursorSprite
	ldr r1, [sp, 0x10C]
	adds r0, r1, r4
	ldr r0, [r0]
	cmp r0, 0x4
	bne _0806817A
	mov r2, r10
	ldrb r0, [r2, 0x8]
	cmp r0, 0
	beq _0806816C
	bl sub_80684C4
_0806816C:
	mov r3, r9
	movs r1, 0
	ldrsh r0, [r3, r1]
	cmp r0, 0
	beq _0806817A
	bl sub_8068344
_0806817A:
	movs r0, 0
	ldr r1, _080681CC
	bl sub_8014140
	adds r5, r0, 0
	movs r0, 0x1C
	bl sub_803E46C
	ldr r3, _080681D0
	ldrh r1, [r3, 0x2]
	movs r0, 0x10
	ands r0, r1
	cmp r0, 0
	bne _080681A2
	ldr r2, _080681B8
	adds r0, r2, 0
	adds r0, 0x2B
	ldrb r0, [r0]
	cmp r0, 0
	beq _080681D4
_080681A2:
	movs r0, 0
	bl sub_8083CE0
	adds r7, 0x1
	cmp r7, 0x4
	beq _080681B0
	b _080682E8
_080681B0:
	movs r7, 0
	b _080682E8
	.align 2, 0
_080681B4: .4byte gUnknown_202F308
_080681B8: .4byte gUnknown_202EE10
_080681BC: .4byte gUnknown_8106E80
_080681C0: .4byte gDungeon
_080681C4: .4byte 0x0000065a
_080681C8: .4byte gUnknown_2027370
_080681CC: .4byte gUnknown_8106DA4
_080681D0: .4byte gRealInputs
_080681D4:
	movs r0, 0x20
	ands r0, r1
	cmp r0, 0
	bne _080681E6
	adds r0, r2, 0
	adds r0, 0x2C
	ldrb r0, [r0]
	cmp r0, 0
	beq _080681FA
_080681E6:
	movs r0, 0
	bl sub_8083CE0
	subs r7, 0x1
	movs r0, 0x1
	negs r0, r0
	cmp r7, r0
	bne _080682E8
	movs r7, 0x3
	b _080682E8
_080681FA:
	ldr r2, [sp, 0x10C]
	adds r0, r2, r4
	ldr r0, [r0]
	cmp r0, 0x4
	bne _08068294
	ldrh r1, [r3, 0x4]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	bne _08068212
	cmp r5, 0x2
	bne _08068248
_08068212:
	mov r3, r10
	ldrb r0, [r3, 0x8]
	cmp r0, 0
	beq _08068248
	movs r0, 0
	bl sub_8083CE0
	ldr r5, _08068244
	movs r4, 0x5
_08068224:
	ldr r1, [r5]
	movs r0, 0
	bl _call_via_r1
	movs r0, 0x1C
	bl sub_803E46C
	subs r4, 0x1
	cmp r4, 0
	bge _08068224
	mov r4, r9
	ldrh r0, [r4]
	adds r0, 0x1
	strh r0, [r4]
	b _080682E8
	.align 2, 0
_08068244: .4byte gIwramTextFunc1
_08068248:
	ldr r0, _0806828C
	ldrh r1, [r0, 0x4]
	movs r0, 0x40
	ands r0, r1
	cmp r0, 0
	bne _08068258
	cmp r5, 0x1
	bne _08068294
_08068258:
	mov r1, r9
	movs r2, 0
	ldrsh r0, [r1, r2]
	cmp r0, 0
	beq _08068294
	movs r0, 0
	bl sub_8083CE0
	ldr r5, _08068290
	movs r4, 0x5
_0806826C:
	ldr r1, [r5]
	movs r0, 0
	bl _call_via_r1
	movs r0, 0x1C
	bl sub_803E46C
	subs r4, 0x1
	cmp r4, 0
	bge _0806826C
	mov r3, r9
	ldrh r0, [r3]
	subs r0, 0x1
	strh r0, [r3]
	b _080682E8
	.align 2, 0
_0806828C: .4byte gRealInputs
_08068290: .4byte gIwramTextFunc2
_08068294:
	bl sub_80048C8
	lsls r0, 24
	cmp r0, 0
	beq _080682A0
	b _08068150
_080682A0:
	ldr r0, _080682C4
	ldrh r1, [r0, 0x2]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	bne _080682B8
	ldr r2, _080682C8
	adds r0, r2, 0
	adds r0, 0x29
	ldrb r0, [r0]
	cmp r0, 0
	beq _080682CC
_080682B8:
	bl sub_8083D08
	movs r4, 0x1
	mov r8, r4
	b _080682E8
	.align 2, 0
_080682C4: .4byte gRealInputs
_080682C8: .4byte gUnknown_202EE10
_080682CC:
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	bne _080682E0
	adds r0, r2, 0
	adds r0, 0x2A
	ldrb r0, [r0]
	cmp r0, 0
	bne _080682E0
	b _08068150
_080682E0:
	bl sub_8083D30
	movs r0, 0x1
	mov r8, r0
_080682E8:
	movs r0, 0x37
	bl sub_803E46C
	mov r1, r8
	cmp r1, 0
	bne _080682F6
	b _080680C4
_080682F6:
	movs r0, 0
	movs r1, 0
	bl sub_803EAF0
	add sp, 0x110
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_806806C

    .align 2,0
