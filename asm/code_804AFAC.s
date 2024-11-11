	#include "asm/constants/gba_constants.inc"
  	#include "asm/macros.inc"

  	.syntax unified

  	.text
  
	thumb_func_start GenerateMazeRoom
GenerateMazeRoom:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x104
	str r0, [sp, 0x100]
	mov r10, r1
	mov r9, r2
	adds r4, r3, 0
	ldr r0, _0804F244
	ldr r5, [r0]
	cmp r4, 0
	bne _0804F0EE
	b _0804F266
_0804F0EE:
	movs r0, 0x64
	bl DungeonRandInt
	cmp r4, r0
	bgt _0804F0FA
	b _0804F266
_0804F0FA:
	ldr r1, _0804F248
	adds r0, r5, r1
	movs r3, 0
	ldrsh r0, [r0, r3]
	cmp r0, 0
	blt _0804F108
	b _0804F266
_0804F108:
	movs r5, 0
	movs r6, 0
	cmp r6, r10
	bge _0804F184
_0804F110:
	adds r7, r6, 0x1
	mov r4, r9
	cmp r4, 0
	ble _0804F17E
	lsls r0, r6, 4
	subs r0, r6
	lsls r0, 5
	ldr r6, [sp, 0x100]
	adds r2, r0, r6
_0804F122:
	ldrb r0, [r2, 0x8]
	cmp r0, 0
	bne _0804F176
	ldrb r0, [r2, 0x11]
	cmp r0, 0
	bne _0804F176
	ldrb r0, [r2, 0xB]
	cmp r0, 0
	beq _0804F176
	ldrb r0, [r2, 0xA]
	cmp r0, 0
	beq _0804F176
	ldrb r0, [r2, 0xC]
	cmp r0, 0
	bne _0804F176
	ldrb r0, [r2, 0xF]
	cmp r0, 0
	bne _0804F176
	ldrb r0, [r2, 0xE]
	cmp r0, 0
	bne _0804F176
	ldrb r0, [r2, 0x9]
	cmp r0, 0
	bne _0804F176
	movs r1, 0x4
	ldrsh r0, [r2, r1]
	movs r3, 0
	ldrsh r1, [r2, r3]
	subs r0, r1
	movs r3, 0x1
	ands r0, r3
	cmp r0, 0
	beq _0804F176
	movs r6, 0x6
	ldrsh r0, [r2, r6]
	movs r6, 0x2
	ldrsh r1, [r2, r6]
	subs r0, r1
	ands r0, r3
	cmp r0, 0
	beq _0804F176
	adds r5, 0x1
_0804F176:
	adds r2, 0x20
	subs r4, 0x1
	cmp r4, 0
	bne _0804F122
_0804F17E:
	adds r6, r7, 0
	cmp r6, r10
	blt _0804F110
_0804F184:
	cmp r5, 0
	beq _0804F266
	movs r1, 0
	mov r0, sp
	adds r0, 0xFF
_0804F18E:
	strb r1, [r0]
	subs r0, 0x1
	cmp r0, sp
	bge _0804F18E
	mov r1, sp
	movs r0, 0x1
	strb r0, [r1]
	movs r7, 0x3F
	mov r8, r7
_0804F1A0:
	adds r0, r5, 0
	bl DungeonRandInt
	adds r4, r0, 0
	adds r0, r5, 0
	bl DungeonRandInt
	mov r1, sp
	adds r2, r1, r4
	ldrb r3, [r2]
	adds r1, r0
	ldrb r0, [r1]
	strb r0, [r2]
	strb r3, [r1]
	movs r3, 0x1
	negs r3, r3
	add r8, r3
	mov r4, r8
	cmp r4, 0
	bge _0804F1A0
	movs r6, 0
	mov r8, r6
	cmp r6, r10
	bge _0804F266
	ldr r7, [sp, 0x100]
	mov r12, r7
_0804F1D4:
	movs r4, 0
	cmp r4, r9
	bge _0804F25A
	mov r2, r12
	mov r5, r12
_0804F1DE:
	ldrb r0, [r2, 0x8]
	cmp r0, 0
	bne _0804F250
	ldrb r0, [r2, 0x11]
	cmp r0, 0
	bne _0804F250
	ldrb r0, [r2, 0xB]
	cmp r0, 0
	beq _0804F250
	ldrb r0, [r2, 0xA]
	cmp r0, 0
	beq _0804F250
	ldrb r0, [r2, 0xC]
	cmp r0, 0
	bne _0804F250
	ldrb r0, [r2, 0xF]
	cmp r0, 0
	bne _0804F250
	ldrb r0, [r2, 0xE]
	cmp r0, 0
	bne _0804F250
	ldrb r0, [r2, 0x9]
	cmp r0, 0
	bne _0804F250
	movs r1, 0x4
	ldrsh r0, [r2, r1]
	movs r3, 0
	ldrsh r1, [r2, r3]
	subs r0, r1
	movs r3, 0x1
	ands r0, r3
	cmp r0, 0
	beq _0804F250
	movs r7, 0x6
	ldrsh r0, [r2, r7]
	movs r7, 0x2
	ldrsh r1, [r2, r7]
	subs r0, r1
	ands r0, r3
	cmp r0, 0
	beq _0804F250
	mov r0, sp
	add r0, r8
	ldrb r0, [r0]
	cmp r0, 0
	beq _0804F24C
	adds r0, r5, 0
	movs r1, 0
	bl sub_804F278
	b _0804F266
	.align 2, 0
_0804F244: .4byte gDungeon
_0804F248: .4byte 0x00003a16
_0804F24C:
	movs r0, 0x1
	add r8, r0
_0804F250:
	adds r2, 0x20
	adds r5, 0x20
	adds r4, 0x1
	cmp r4, r9
	blt _0804F1DE
_0804F25A:
	movs r1, 0xF0
	lsls r1, 1
	add r12, r1
	adds r6, 0x1
	cmp r6, r10
	blt _0804F1D4
_0804F266:
	add sp, 0x104
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end GenerateMazeRoom

	thumb_func_start sub_804F278
sub_804F278:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x10
	adds r4, r0, 0
	lsls r1, 24
	lsrs r1, 24
	mov r8, r1
	ldr r1, _0804F2B0
	movs r0, 0x1
	strb r0, [r1]
	movs r0, 0x1
	strb r0, [r4, 0x10]
	movs r1, 0
	ldrsh r0, [r4, r1]
	movs r2, 0x2
	ldrsh r1, [r4, r2]
	bl GetTile
	ldrb r0, [r0, 0x9]
	mov r9, r0
	movs r5, 0
	ldrsh r0, [r4, r5]
	adds r6, r0, 0x1
	b _0804F2F0
	.align 2, 0
_0804F2B0: .4byte gUnknown_202F1AC
_0804F2B4:
	movs r2, 0x2
	ldrsh r1, [r4, r2]
	subs r1, 0x1
	adds r0, r6, 0
	bl GetTile
	ldrh r1, [r0]
	movs r0, 0x3
	ands r0, r1
	cmp r0, 0x1
	beq _0804F2EE
	movs r5, 0x2
	ldrsh r3, [r4, r5]
	subs r1, r3, 0x1
	movs r0, 0
	ldrsh r2, [r4, r0]
	movs r5, 0x4
	ldrsh r0, [r4, r5]
	str r0, [sp]
	movs r5, 0x6
	ldrsh r0, [r4, r5]
	str r0, [sp, 0x4]
	mov r0, r8
	str r0, [sp, 0x8]
	mov r5, r9
	str r5, [sp, 0xC]
	adds r0, r6, 0
	bl sub_804F494
_0804F2EE:
	adds r6, 0x2
_0804F2F0:
	movs r1, 0x4
	ldrsh r0, [r4, r1]
	subs r0, 0x1
	cmp r6, r0
	blt _0804F2B4
	movs r2, 0x2
	ldrsh r0, [r4, r2]
	adds r5, r0, 0x1
	movs r6, 0x6
	ldrsh r0, [r4, r6]
	b _0804F342
_0804F306:
	movs r1, 0x4
	ldrsh r0, [r4, r1]
	adds r1, r5, 0
	bl GetTile
	ldrh r1, [r0]
	movs r0, 0x3
	ands r0, r1
	cmp r0, 0x1
	beq _0804F33C
	movs r2, 0x4
	ldrsh r0, [r4, r2]
	movs r6, 0
	ldrsh r2, [r4, r6]
	movs r1, 0x2
	ldrsh r3, [r4, r1]
	str r0, [sp]
	movs r6, 0x6
	ldrsh r1, [r4, r6]
	str r1, [sp, 0x4]
	mov r1, r8
	str r1, [sp, 0x8]
	mov r6, r9
	str r6, [sp, 0xC]
	adds r1, r5, 0
	bl sub_804F494
_0804F33C:
	adds r5, 0x2
	movs r1, 0x6
	ldrsh r0, [r4, r1]
_0804F342:
	subs r0, 0x1
	cmp r5, r0
	blt _0804F306
	movs r2, 0
	ldrsh r0, [r4, r2]
	adds r6, r0, 0x1
	movs r5, 0x4
	ldrsh r0, [r4, r5]
	b _0804F392
_0804F354:
	movs r0, 0x6
	ldrsh r1, [r4, r0]
	adds r0, r6, 0
	bl GetTile
	ldrh r1, [r0]
	movs r0, 0x3
	ands r0, r1
	cmp r0, 0x1
	beq _0804F38C
	movs r2, 0x6
	ldrsh r1, [r4, r2]
	movs r5, 0
	ldrsh r2, [r4, r5]
	movs r0, 0x2
	ldrsh r3, [r4, r0]
	movs r5, 0x4
	ldrsh r0, [r4, r5]
	str r0, [sp]
	adds r0, r1, 0
	str r0, [sp, 0x4]
	mov r0, r8
	str r0, [sp, 0x8]
	mov r5, r9
	str r5, [sp, 0xC]
	adds r0, r6, 0
	bl sub_804F494
_0804F38C:
	adds r6, 0x2
	movs r1, 0x4
	ldrsh r0, [r4, r1]
_0804F392:
	subs r0, 0x1
	cmp r6, r0
	blt _0804F354
	movs r2, 0x2
	ldrsh r0, [r4, r2]
	adds r5, r0, 0x1
	movs r6, 0x6
	ldrsh r0, [r4, r6]
	b _0804F3E4
_0804F3A4:
	movs r1, 0
	ldrsh r0, [r4, r1]
	subs r0, 0x1
	adds r1, r5, 0
	bl GetTile
	ldrh r1, [r0]
	movs r0, 0x3
	ands r0, r1
	cmp r0, 0x1
	beq _0804F3DE
	movs r6, 0
	ldrsh r2, [r4, r6]
	subs r0, r2, 0x1
	movs r1, 0x2
	ldrsh r3, [r4, r1]
	movs r6, 0x4
	ldrsh r1, [r4, r6]
	str r1, [sp]
	movs r6, 0x6
	ldrsh r1, [r4, r6]
	str r1, [sp, 0x4]
	mov r1, r8
	str r1, [sp, 0x8]
	mov r6, r9
	str r6, [sp, 0xC]
	adds r1, r5, 0
	bl sub_804F494
_0804F3DE:
	adds r5, 0x2
	movs r1, 0x6
	ldrsh r0, [r4, r1]
_0804F3E4:
	subs r0, 0x1
	cmp r5, r0
	blt _0804F3A4
	movs r2, 0
	ldrsh r0, [r4, r2]
	adds r6, r0, 0x3
	b _0804F478
_0804F3F2:
	movs r1, 0x2
	ldrsh r0, [r4, r1]
	adds r5, r0, 0x3
	movs r2, 0x6
	ldrsh r0, [r4, r2]
	subs r0, 0x3
	adds r1, r6, 0x2
	mov r10, r1
	cmp r5, r0
	bge _0804F476
	ldr r2, _0804F434
	adds r7, r2, 0
_0804F40A:
	adds r0, r6, 0
	adds r1, r5, 0
	bl GetTile
	ldrh r1, [r0]
	movs r0, 0x3
	ands r0, r1
	cmp r0, 0x1
	bne _0804F46A
	mov r0, r8
	cmp r0, 0
	beq _0804F438
	subs r0, r6, 0x1
	adds r1, r5, 0
	bl GetTileSafe
	ldrh r1, [r0]
	ands r1, r7
	movs r2, 0x2
	orrs r1, r2
	b _0804F444
	.align 2, 0
_0804F434: .4byte 0x0000fffc
_0804F438:
	subs r0, r6, 0x1
	adds r1, r5, 0
	bl GetTileSafe
	ldrh r1, [r0]
	ands r1, r7
_0804F444:
	strh r1, [r0]
	movs r1, 0
	ldrsh r2, [r4, r1]
	movs r0, 0x2
	ldrsh r3, [r4, r0]
	movs r1, 0x4
	ldrsh r0, [r4, r1]
	str r0, [sp]
	movs r1, 0x6
	ldrsh r0, [r4, r1]
	str r0, [sp, 0x4]
	mov r0, r8
	str r0, [sp, 0x8]
	mov r1, r9
	str r1, [sp, 0xC]
	adds r0, r6, 0
	adds r1, r5, 0
	bl sub_804F494
_0804F46A:
	adds r5, 0x2
	movs r2, 0x6
	ldrsh r0, [r4, r2]
	subs r0, 0x3
	cmp r5, r0
	blt _0804F40A
_0804F476:
	mov r6, r10
_0804F478:
	movs r5, 0x4
	ldrsh r0, [r4, r5]
	subs r0, 0x3
	cmp r6, r0
	blt _0804F3F2
	add sp, 0x10
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_804F278

	thumb_func_start sub_804F494
sub_804F494:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x8
	adds r5, r0, 0
	adds r4, r1, 0
	str r2, [sp]
	str r3, [sp, 0x4]
	ldr r0, [sp, 0x30]
	ldr r1, [sp, 0x34]
	lsls r0, 24
	lsrs r0, 24
	mov r9, r0
	lsls r1, 24
	mov r8, r1
	movs r0, 0x3
	mov r10, r0
_0804F4BA:
	movs r0, 0x4
	bl DungeonRandInt
	adds r6, r0, 0
	movs r7, 0
	adds r0, r5, 0
	adds r1, r4, 0
	bl GetTileSafe
	mov r1, r9
	mov r3, r8
	lsrs r2, r3, 24
	bl SetTerrainObstacleChecked
_0804F4D6:
	adds r0, r6, 0
	mov r1, r10
	ands r0, r1
	cmp r0, 0x1
	beq _0804F4F6
	cmp r0, 0x1
	bgt _0804F4EA
	cmp r0, 0
	beq _0804F4F0
	b _0804F506
_0804F4EA:
	cmp r0, 0x2
	beq _0804F4FE
	b _0804F506
_0804F4F0:
	movs r0, 0x2
	movs r1, 0
	b _0804F50A
_0804F4F6:
	movs r0, 0
	movs r1, 0x2
	negs r1, r1
	b _0804F50A
_0804F4FE:
	movs r0, 0x2
	negs r0, r0
	movs r1, 0
	b _0804F50A
_0804F506:
	movs r0, 0
	movs r1, 0x2
_0804F50A:
	adds r0, r5, r0
	ldr r2, [sp]
	cmp r2, r0
	bgt _0804F534
	ldr r3, [sp, 0x28]
	cmp r3, r0
	ble _0804F534
	adds r1, r4, r1
	ldr r2, [sp, 0x4]
	cmp r2, r1
	bgt _0804F534
	ldr r3, [sp, 0x2C]
	cmp r3, r1
	ble _0804F534
	bl GetTile
	ldrh r1, [r0]
	mov r0, r10
	ands r0, r1
	cmp r0, 0x1
	beq _0804F53E
_0804F534:
	adds r6, 0x1
	adds r7, 0x1
	cmp r7, 0x3
	bgt _0804F5B2
	b _0804F4D6
_0804F53E:
	mov r0, r10
	ands r0, r6
	cmp r0, 0x1
	beq _0804F570
	cmp r0, 0x1
	bgt _0804F550
	cmp r0, 0
	beq _0804F55A
	b _0804F4BA
_0804F550:
	cmp r0, 0x2
	beq _0804F586
	cmp r0, 0x3
	beq _0804F59C
	b _0804F4BA
_0804F55A:
	adds r0, r5, 0x1
	adds r1, r4, 0
	bl GetTileSafe
	mov r1, r9
	mov r3, r8
	lsrs r2, r3, 24
	bl SetTerrainObstacleChecked
	adds r5, 0x2
	b _0804F4BA
_0804F570:
	subs r1, r4, 0x1
	adds r0, r5, 0
	bl GetTileSafe
	mov r1, r9
	mov r3, r8
	lsrs r2, r3, 24
	bl SetTerrainObstacleChecked
	subs r4, 0x2
	b _0804F4BA
_0804F586:
	subs r0, r5, 0x1
	adds r1, r4, 0
	bl GetTileSafe
	mov r1, r9
	mov r3, r8
	lsrs r2, r3, 24
	bl SetTerrainObstacleChecked
	subs r5, 0x2
	b _0804F4BA
_0804F59C:
	adds r1, r4, 0x1
	adds r0, r5, 0
	bl GetTileSafe
	mov r1, r9
	mov r3, r8
	lsrs r2, r3, 24
	bl SetTerrainObstacleChecked
	adds r4, 0x2
	b _0804F4BA
_0804F5B2:
	add sp, 0x8
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_804F494

	thumb_func_start sub_804F5C4
sub_804F5C4:
	ldrh r3, [r0]
	ldr r2, _0804F5D4
	ands r2, r3
	movs r3, 0x2
	orrs r2, r3
	orrs r2, r1
	strh r2, [r0]
	bx lr
	.align 2, 0
_0804F5D4: .4byte 0x0000fffc
	thumb_func_end sub_804F5C4

	thumb_func_start sub_804F5D8
sub_804F5D8:
	push {r4-r7,lr}
	adds r5, r0, 0
	movs r0, 0
	ldrsh r6, [r5, r0]
	b _0804F60C
_0804F5E2:
	movs r0, 0x2
	ldrsh r4, [r5, r0]
	movs r1, 0x6
	ldrsh r0, [r5, r1]
	adds r7, r6, 0x1
	cmp r4, r0
	bge _0804F60A
_0804F5F0:
	adds r0, r6, 0
	adds r1, r4, 0
	bl GetTileSafe
	ldrh r2, [r0, 0x4]
	movs r1, 0x20
	orrs r1, r2
	strh r1, [r0, 0x4]
	adds r4, 0x1
	movs r1, 0x6
	ldrsh r0, [r5, r1]
	cmp r4, r0
	blt _0804F5F0
_0804F60A:
	adds r6, r7, 0
_0804F60C:
	movs r1, 0x4
	ldrsh r0, [r5, r1]
	cmp r6, r0
	blt _0804F5E2
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_804F5D8

	thumb_func_start sub_804F61C
sub_804F61C:
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	mov r9, r0
	mov r8, r1
	movs r7, 0x1
	negs r7, r7
	b _0804F67A
_0804F62E:
	movs r5, 0x1
	negs r5, r5
	b _0804F666
_0804F634:
	cmp r7, 0
	beq _0804F63C
	cmp r5, 0
	bne _0804F660
_0804F63C:
	adds r0, r6, 0
	adds r1, r4, 0
	bl GetTile
	ldrh r1, [r0]
	movs r0, 0x3
	ands r0, r1
	cmp r0, 0x1
	bne _0804F660
	adds r0, r6, 0
	adds r1, r4, 0
	bl GetTile
	ldrb r0, [r0, 0x9]
	cmp r0, 0xFF
	bne _0804F660
	movs r0, 0x1
	b _0804F686
_0804F660:
	adds r5, 0x1
	cmp r5, 0x1
	bgt _0804F672
_0804F666:
	mov r0, r8
	adds r4, r0, r5
	cmp r4, 0
	blt _0804F660
	cmp r4, 0x1F
	ble _0804F634
_0804F672:
	adds r7, 0x1
	cmp r7, 0x1
	bgt _0804F684
	mov r0, r9
_0804F67A:
	adds r6, r0, r7
	cmp r6, 0
	blt _0804F672
	cmp r6, 0x37
	ble _0804F62E
_0804F684:
	movs r0, 0
_0804F686:
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_804F61C

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
	bl sub_804F5D8
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
	bl sub_804F61C
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
	bl sub_804F61C
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
	bl sub_804F5D8
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
	bl sub_804F5D8
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
	bl sub_804F5D8
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
	bl sub_804F5D8
	adds r0, r7, 0
	movs r1, 0x1
	bl sub_804F278
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
