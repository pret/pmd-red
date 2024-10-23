	#include "asm/constants/gba_constants.inc"
	#include "asm/macros.inc"

	.syntax unified

	.text

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
