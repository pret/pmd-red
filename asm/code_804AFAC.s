	#include "asm/constants/gba_constants.inc"
  	#include "asm/macros.inc"

  	.syntax unified

  	.text
  


	thumb_func_start GenerateSecondaryStructure
GenerateSecondaryStructure:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x8
	adds r7, r0, 0
	movs r0, 0x6
	bl DungeonRandInt
	subs r0, 0x1
	cmp r0, 0x4
	bls _0804F6B0
	b _0804FBD6
_0804F6B0:
	lsls r0, 2
	ldr r1, _0804F6BC
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0804F6BC: .4byte _0804F6C0
	.align 2, 0
_0804F6C0:
	.4byte _0804FB24
	.4byte _0804FA98
	.4byte _0804F9DC
	.4byte _0804F826
	.4byte _0804F6D4
_0804F6D4:
	ldr r1, _0804F70C
	ldr r0, [r1]
	cmp r0, 0
	bne _0804F6DE
	b _0804FBD6
_0804F6DE:
	subs r0, 0x1
	str r0, [r1]
	adds r0, r7, 0
	bl SetSpawnFlag5
	movs r0, 0x2
	bl DungeonRandInt
	cmp r0, 0
	beq _0804F78E
	movs r5, 0
	movs r1, 0
	ldrsh r0, [r7, r1]
	movs r2, 0x4
	ldrsh r1, [r7, r2]
	adds r0, r1
	lsrs r1, r0, 31
	adds r0, r1
	asrs r0, 1
	mov r8, r0
	movs r3, 0x2
	ldrsh r4, [r7, r3]
	b _0804F712
	.align 2, 0
_0804F70C: .4byte gUnknown_202F1C8
_0804F710:
	adds r4, 0x1
_0804F712:
	movs r1, 0x6
	ldrsh r0, [r7, r1]
	cmp r4, r0
	bge _0804F72A
	mov r0, r8
	adds r1, r4, 0
	bl IsNextToHallway
	lsls r0, 24
	cmp r0, 0
	beq _0804F710
	movs r5, 0x1
_0804F72A:
	cmp r5, 0
	beq _0804F730
	b _0804FBD6
_0804F730:
	movs r2, 0x2
	ldrsh r4, [r7, r2]
	movs r3, 0x6
	ldrsh r0, [r7, r3]
	cmp r4, r0
	bge _0804F754
_0804F73C:
	mov r0, r8
	adds r1, r4, 0
	bl GetTileSafe
	movs r1, 0
	bl sub_804F5C4
	adds r4, 0x1
	movs r5, 0x6
	ldrsh r0, [r7, r5]
	cmp r4, r0
	blt _0804F73C
_0804F754:
	movs r0, 0
	ldrsh r5, [r7, r0]
	cmp r5, r8
	blt _0804F75E
	b _0804FBD2
_0804F75E:
	movs r1, 0x2
	ldrsh r4, [r7, r1]
	movs r2, 0x6
	ldrsh r0, [r7, r2]
	adds r6, r5, 0x1
	cmp r4, r0
	bge _0804F786
_0804F76C:
	adds r0, r5, 0
	adds r1, r4, 0
	bl GetTileSafe
	ldrh r2, [r0]
	movs r1, 0x80
	orrs r1, r2
	strh r1, [r0]
	adds r4, 0x1
	movs r3, 0x6
	ldrsh r0, [r7, r3]
	cmp r4, r0
	blt _0804F76C
_0804F786:
	adds r5, r6, 0
	cmp r5, r8
	blt _0804F75E
	b _0804FBD2
_0804F78E:
	movs r5, 0
	movs r4, 0x2
	ldrsh r0, [r7, r4]
	movs r2, 0x6
	ldrsh r1, [r7, r2]
	adds r0, r1
	lsrs r1, r0, 31
	adds r0, r1
	asrs r0, 1
	mov r8, r0
	movs r3, 0
	ldrsh r4, [r7, r3]
	b _0804F7AA
_0804F7A8:
	adds r4, 0x1
_0804F7AA:
	movs r1, 0x4
	ldrsh r0, [r7, r1]
	cmp r4, r0
	bge _0804F7C2
	adds r0, r4, 0
	mov r1, r8
	bl IsNextToHallway
	lsls r0, 24
	cmp r0, 0
	beq _0804F7A8
	movs r5, 0x1
_0804F7C2:
	cmp r5, 0
	beq _0804F7C8
	b _0804FBD6
_0804F7C8:
	movs r2, 0
	ldrsh r4, [r7, r2]
	movs r3, 0x4
	ldrsh r0, [r7, r3]
	cmp r4, r0
	bge _0804F7EC
_0804F7D4:
	adds r0, r4, 0
	mov r1, r8
	bl GetTileSafe
	movs r1, 0
	bl sub_804F5C4
	adds r4, 0x1
	movs r5, 0x4
	ldrsh r0, [r7, r5]
	cmp r4, r0
	blt _0804F7D4
_0804F7EC:
	movs r0, 0x2
	ldrsh r5, [r7, r0]
	cmp r5, r8
	blt _0804F7F6
	b _0804FBD2
_0804F7F6:
	movs r1, 0
	ldrsh r4, [r7, r1]
	movs r2, 0x4
	ldrsh r0, [r7, r2]
	adds r6, r5, 0x1
	cmp r4, r0
	bge _0804F81E
_0804F804:
	adds r0, r4, 0
	adds r1, r5, 0
	bl GetTileSafe
	ldrh r2, [r0]
	movs r1, 0x80
	orrs r1, r2
	strh r1, [r0]
	adds r4, 0x1
	movs r3, 0x4
	ldrsh r0, [r7, r3]
	cmp r4, r0
	blt _0804F804
_0804F81E:
	adds r5, r6, 0
	cmp r5, r8
	blt _0804F7F6
	b _0804FBD2
_0804F826:
	movs r4, 0x4
	ldrsh r3, [r7, r4]
	movs r5, 0
	ldrsh r1, [r7, r5]
	subs r0, r3, r1
	cmp r0, 0x5
	bgt _0804F836
	b _0804FBD6
_0804F836:
	movs r0, 0x6
	ldrsh r4, [r7, r0]
	movs r5, 0x2
	ldrsh r2, [r7, r5]
	subs r0, r4, r2
	cmp r0, 0x5
	bgt _0804F846
	b _0804FBD6
_0804F846:
	adds r0, r1, r3
	lsrs r1, r0, 31
	adds r0, r1
	asrs r0, 1
	str r0, [sp]
	adds r0, r2, r4
	lsrs r1, r0, 31
	adds r0, r1
	asrs r0, 1
	str r0, [sp, 0x4]
	ldr r1, _0804F9D8
	ldr r0, [r1]
	cmp r0, 0
	bne _0804F864
	b _0804FBD6
_0804F864:
	subs r0, 0x1
	str r0, [r1]
	adds r0, r7, 0
	bl SetSpawnFlag5
	ldr r5, [sp]
	subs r5, 0x2
	ldr r0, [sp, 0x4]
	subs r0, 0x2
	mov r10, r0
	adds r0, r5, 0
	mov r1, r10
	bl GetTileSafe
	movs r1, 0x4
	bl sub_804F5C4
	ldr r1, [sp]
	subs r1, 0x1
	mov r9, r1
	mov r0, r9
	mov r1, r10
	bl GetTileSafe
	movs r1, 0x4
	bl sub_804F5C4
	ldr r0, [sp]
	mov r1, r10
	bl GetTileSafe
	movs r1, 0x4
	bl sub_804F5C4
	ldr r2, [sp]
	adds r2, 0x1
	mov r8, r2
	mov r0, r8
	mov r1, r10
	bl GetTileSafe
	movs r1, 0x4
	bl sub_804F5C4
	ldr r6, [sp, 0x4]
	subs r6, 0x1
	adds r0, r5, 0
	adds r1, r6, 0
	bl GetTileSafe
	movs r1, 0x4
	bl sub_804F5C4
	adds r0, r5, 0
	ldr r1, [sp, 0x4]
	bl GetTileSafe
	movs r1, 0x4
	bl sub_804F5C4
	ldr r4, [sp, 0x4]
	adds r4, 0x1
	adds r0, r5, 0
	adds r1, r4, 0
	bl GetTileSafe
	movs r1, 0x4
	bl sub_804F5C4
	adds r0, r5, 0
	adds r1, r4, 0
	bl GetTileSafe
	movs r1, 0x4
	bl sub_804F5C4
	mov r0, r9
	adds r1, r4, 0
	bl GetTileSafe
	movs r1, 0x4
	bl sub_804F5C4
	ldr r0, [sp]
	adds r1, r4, 0
	bl GetTileSafe
	movs r1, 0x4
	bl sub_804F5C4
	mov r0, r8
	mov r1, r10
	bl GetTileSafe
	movs r1, 0x4
	bl sub_804F5C4
	mov r0, r8
	adds r1, r6, 0
	bl GetTileSafe
	movs r1, 0x4
	bl sub_804F5C4
	mov r0, r8
	ldr r1, [sp, 0x4]
	bl GetTileSafe
	movs r1, 0x4
	bl sub_804F5C4
	mov r0, r8
	adds r1, r4, 0
	bl GetTileSafe
	movs r1, 0x4
	bl sub_804F5C4
	mov r0, r9
	adds r1, r6, 0
	bl GetTileSafe
	ldrh r2, [r0, 0x4]
	movs r1, 0x4
	orrs r1, r2
	strh r1, [r0, 0x4]
	mov r0, r9
	adds r1, r6, 0
	bl GetTileSafe
	ldrh r1, [r0, 0x4]
	movs r2, 0x40
	orrs r1, r2
	strh r1, [r0, 0x4]
	ldr r0, [sp]
	adds r1, r6, 0
	bl GetTileSafe
	ldrh r1, [r0, 0x4]
	movs r4, 0x2
	orrs r1, r4
	strh r1, [r0, 0x4]
	mov r0, r9
	ldr r1, [sp, 0x4]
	bl GetTileSafe
	ldrh r1, [r0, 0x4]
	orrs r1, r4
	strh r1, [r0, 0x4]
	ldr r0, [sp]
	ldr r1, [sp, 0x4]
	bl GetTileSafe
	ldrh r1, [r0, 0x4]
	orrs r1, r4
	strh r1, [r0, 0x4]
	mov r0, r9
	adds r1, r6, 0
	bl GetTileSafe
	ldrh r1, [r0, 0x4]
	movs r4, 0x10
	orrs r1, r4
	strh r1, [r0, 0x4]
	ldr r0, [sp]
	adds r1, r6, 0
	bl GetTileSafe
	ldrh r1, [r0, 0x4]
	orrs r1, r4
	strh r1, [r0, 0x4]
	mov r0, r9
	ldr r1, [sp, 0x4]
	bl GetTileSafe
	ldrh r1, [r0, 0x4]
	orrs r1, r4
	strh r1, [r0, 0x4]
	ldr r0, [sp]
	ldr r1, [sp, 0x4]
	bl GetTileSafe
	ldrh r1, [r0, 0x4]
	orrs r4, r1
	strh r4, [r0, 0x4]
	b _0804FBD2
	.align 2, 0
_0804F9D8: .4byte gUnknown_202F1C8
_0804F9DC:
	movs r4, 0x4
	ldrsh r3, [r7, r4]
	movs r5, 0
	ldrsh r2, [r7, r5]
	subs r0, r3, r2
	cmp r0, 0x4
	bgt _0804F9EC
	b _0804FBD6
_0804F9EC:
	movs r1, 0x6
	ldrsh r0, [r7, r1]
	movs r4, 0x2
	ldrsh r1, [r7, r4]
	subs r0, r1
	cmp r0, 0x4
	bgt _0804F9FC
	b _0804FBD6
_0804F9FC:
	adds r0, r2, 0x2
	subs r1, r3, 0x3
	bl DungeonRandRange
	adds r4, r0, 0
	movs r5, 0x2
	ldrsh r0, [r7, r5]
	adds r0, 0x2
	movs r2, 0x6
	ldrsh r1, [r7, r2]
	subs r1, 0x3
	bl DungeonRandRange
	mov r10, r0
	movs r3, 0
	ldrsh r0, [r7, r3]
	adds r0, 0x2
	movs r5, 0x4
	ldrsh r1, [r7, r5]
	subs r1, 0x3
	bl DungeonRandRange
	mov r9, r0
	movs r1, 0x2
	ldrsh r0, [r7, r1]
	adds r0, 0x2
	movs r2, 0x6
	ldrsh r1, [r7, r2]
	subs r1, 0x3
	bl DungeonRandRange
	adds r6, r0, 0
	ldr r1, _0804FA94
	ldr r0, [r1]
	cmp r0, 0
	bne _0804FA46
	b _0804FBD6
_0804FA46:
	subs r0, 0x1
	str r0, [r1]
	adds r0, r7, 0
	bl SetSpawnFlag5
	cmp r4, r9
	ble _0804FA5A
	adds r0, r4, 0
	mov r4, r9
	mov r9, r0
_0804FA5A:
	cmp r10, r6
	ble _0804FA64
	mov r0, r10
	mov r10, r6
	adds r6, r0, 0
_0804FA64:
	adds r5, r4, 0
	cmp r5, r9
	ble _0804FA6C
	b _0804FBD2
_0804FA6C:
	mov r4, r10
	adds r3, r5, 0x1
	mov r8, r3
	cmp r4, r6
	bgt _0804FA8A
_0804FA76:
	adds r0, r5, 0
	adds r1, r4, 0
	bl GetTileSafe
	movs r1, 0
	bl sub_804F5C4
	adds r4, 0x1
	cmp r4, r6
	ble _0804FA76
_0804FA8A:
	mov r5, r8
	cmp r5, r9
	ble _0804FA6C
	b _0804FBD2
	.align 2, 0
_0804FA94: .4byte gUnknown_202F1C8
_0804FA98:
	movs r4, 0x4
	ldrsh r0, [r7, r4]
	movs r5, 0
	ldrsh r1, [r7, r5]
	subs r0, r1
	movs r2, 0x1
	ands r0, r2
	cmp r0, 0
	bne _0804FAAC
	b _0804FBD6
_0804FAAC:
	movs r1, 0x6
	ldrsh r0, [r7, r1]
	movs r3, 0x2
	ldrsh r1, [r7, r3]
	subs r0, r1
	ands r0, r2
	cmp r0, 0
	bne _0804FABE
	b _0804FBD6
_0804FABE:
	ldr r1, _0804FB20
	ldr r0, [r1]
	cmp r0, 0
	bne _0804FAC8
	b _0804FBD6
_0804FAC8:
	subs r0, 0x1
	str r0, [r1]
	adds r0, r7, 0
	bl SetSpawnFlag5
	movs r6, 0x3F
_0804FAD4:
	movs r4, 0x4
	ldrsh r0, [r7, r4]
	movs r5, 0
	ldrsh r1, [r7, r5]
	subs r0, r1
	bl DungeonRandInt
	adds r4, r0, 0
	movs r1, 0x6
	ldrsh r0, [r7, r1]
	movs r2, 0x2
	ldrsh r1, [r7, r2]
	subs r0, r1
	bl DungeonRandInt
	adds r2, r0, 0
	adds r0, r4, r2
	movs r5, 0x1
	ands r0, r5
	cmp r0, 0
	beq _0804FB14
	movs r3, 0
	ldrsh r0, [r7, r3]
	adds r0, r4
	movs r4, 0x2
	ldrsh r1, [r7, r4]
	adds r1, r2
	bl GetTileSafe
	movs r1, 0
	bl sub_804F5C4
_0804FB14:
	subs r6, 0x1
	cmp r6, 0
	bge _0804FAD4
	strb r5, [r7, 0x9]
	b _0804FBD6
	.align 2, 0
_0804FB20: .4byte gUnknown_202F1C8
_0804FB24:
	ldr r1, _0804FBC0
	ldr r0, [r1]
	cmp r0, 0
	beq _0804FBD6
	subs r0, 0x1
	str r0, [r1]
	movs r5, 0x4
	ldrsh r3, [r7, r5]
	movs r0, 0
	ldrsh r2, [r7, r0]
	subs r6, r3, r2
	movs r4, 0x1
	adds r0, r6, 0
	ands r0, r4
	cmp r0, 0
	beq _0804FB54
	movs r1, 0x6
	ldrsh r0, [r7, r1]
	movs r5, 0x2
	ldrsh r1, [r7, r5]
	subs r0, r1
	ands r0, r4
	cmp r0, 0
	bne _0804FBC4
_0804FB54:
	adds r0, r2, r3
	lsrs r1, r0, 31
	adds r0, r1
	asrs r5, r0, 1
	movs r0, 0x2
	ldrsh r3, [r7, r0]
	movs r1, 0x6
	ldrsh r2, [r7, r1]
	adds r0, r3, r2
	lsrs r1, r0, 31
	adds r0, r1
	asrs r4, r0, 1
	cmp r6, 0x4
	ble _0804FBAE
	subs r0, r2, r3
	cmp r0, 0x4
	ble _0804FBAE
	adds r0, r5, 0x1
	adds r1, r4, 0
	bl GetTileSafe
	movs r1, 0
	bl sub_804F5C4
	adds r1, r4, 0x1
	adds r0, r5, 0
	bl GetTileSafe
	movs r1, 0
	bl sub_804F5C4
	subs r0, r5, 0x1
	adds r1, r4, 0
	bl GetTileSafe
	movs r1, 0
	bl sub_804F5C4
	subs r1, r4, 0x1
	adds r0, r5, 0
	bl GetTileSafe
	movs r1, 0
	bl sub_804F5C4
_0804FBAE:
	adds r0, r5, 0
	adds r1, r4, 0
	bl GetTileSafe
	movs r1, 0
	bl sub_804F5C4
	b _0804FBD2
	.align 2, 0
_0804FBC0: .4byte gUnknown_202F1C8
_0804FBC4:
	adds r0, r7, 0
	bl SetSpawnFlag5
	adds r0, r7, 0
	movs r1, 0x1
	bl GenerateMaze
_0804FBD2:
	movs r0, 0x1
	strb r0, [r7, 0x9]
_0804FBD6:
	add sp, 0x8
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end GenerateSecondaryStructure

        .align 2,0
