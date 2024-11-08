	#include "asm/constants/gba_constants.inc"
  	#include "asm/macros.inc"

  	.syntax unified

  	.text
  

	thumb_func_start AssignGridCellConnections
AssignGridCellConnections:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x20
	str r0, [sp]
	str r1, [sp, 0x4]
	str r2, [sp, 0x8]
	adds r7, r3, 0
	ldr r6, [sp, 0x40]
	ldr r0, [sp, 0x44]
	ldrb r0, [r0, 0x5]
	str r0, [sp, 0xC]
	movs r0, 0x4
	bl DungeonRandInt
	adds r5, r0, 0
	movs r1, 0
	mov r10, r1
	ldr r2, [sp, 0xC]
	cmp r10, r2
	blt _0804D620
	b _0804D726
_0804D620:
	lsls r4, r6, 5
	mov r9, r4
	lsls r0, r7, 4
	subs r0, r7
	lsls r0, 5
	ldr r1, [sp]
	adds r0, r1
	mov r8, r0
_0804D630:
	movs r0, 0x8
	bl DungeonRandInt
	adds r4, r0, 0
	movs r0, 0x4
	bl DungeonRandInt
	cmp r4, 0x3
	bgt _0804D644
	adds r5, r0, 0
_0804D644:
	mov r4, r10
	adds r4, 0x1
_0804D648:
	movs r1, 0
	movs r0, 0x3
	ands r0, r5
	cmp r0, 0x1
	beq _0804D670
	cmp r0, 0x1
	bgt _0804D65C
	cmp r0, 0
	beq _0804D666
	b _0804D686
_0804D65C:
	cmp r0, 0x2
	beq _0804D676
	cmp r0, 0x3
	beq _0804D67C
	b _0804D686
_0804D666:
	ldr r0, [sp, 0x4]
	subs r0, 0x1
	cmp r7, r0
	blt _0804D68A
	b _0804D684
_0804D670:
	cmp r6, 0
	bgt _0804D68A
	b _0804D684
_0804D676:
	cmp r7, 0
	bgt _0804D68A
	b _0804D684
_0804D67C:
	ldr r0, [sp, 0x8]
	subs r0, 0x1
	cmp r6, r0
	blt _0804D68A
_0804D684:
	adds r5, 0x1
_0804D686:
	cmp r1, 0
	beq _0804D648
_0804D68A:
	movs r1, 0x3
	ands r1, r5
	cmp r1, 0x1
	beq _0804D6C6
	cmp r1, 0x1
	bgt _0804D69C
	cmp r1, 0
	beq _0804D6A6
	b _0804D71E
_0804D69C:
	cmp r1, 0x2
	beq _0804D6E2
	cmp r1, 0x3
	beq _0804D704
	b _0804D71E
_0804D6A6:
	mov r1, r9
	add r1, r8
	movs r0, 0xF0
	lsls r0, 1
	adds r2, r1, r0
	ldrb r0, [r2, 0x8]
	cmp r0, 0
	bne _0804D71E
	movs r0, 0x1
	strb r0, [r1, 0x16]
	strb r0, [r2, 0x15]
	movs r1, 0xF0
	lsls r1, 1
	add r8, r1
	adds r7, 0x1
	b _0804D71E
_0804D6C6:
	mov r2, r9
	add r2, r8
	adds r3, r2, 0
	subs r3, 0x20
	ldrb r0, [r3, 0x8]
	cmp r0, 0
	bne _0804D71E
	strb r1, [r2, 0x13]
	strb r1, [r3, 0x14]
	movs r2, 0x20
	negs r2, r2
	add r9, r2
	subs r6, 0x1
	b _0804D71E
_0804D6E2:
	mov r1, r9
	add r1, r8
	ldr r0, _0804D700
	adds r2, r1, r0
	ldrb r0, [r2, 0x8]
	cmp r0, 0
	bne _0804D71E
	movs r0, 0x1
	strb r0, [r1, 0x15]
	strb r0, [r2, 0x16]
	ldr r1, _0804D700
	add r8, r1
	subs r7, 0x1
	b _0804D71E
	.align 2, 0
_0804D700: .4byte 0xfffffe20
_0804D704:
	mov r1, r9
	add r1, r8
	adds r2, r1, 0
	adds r2, 0x20
	ldrb r0, [r2, 0x8]
	cmp r0, 0
	bne _0804D71E
	movs r0, 0x1
	strb r0, [r1, 0x14]
	strb r0, [r2, 0x13]
	movs r1, 0x20
	add r9, r1
	adds r6, 0x1
_0804D71E:
	mov r10, r4
	ldr r2, [sp, 0xC]
	cmp r10, r2
	blt _0804D630
_0804D726:
	ldr r4, [sp, 0x44]
	ldrb r0, [r4, 0xB]
	cmp r0, 0
	beq _0804D730
	b _0804D8B8
_0804D730:
	movs r0, 0
	mov r9, r0
	movs r7, 0
	ldr r1, [sp, 0x4]
	cmp r9, r1
	blt _0804D73E
	b _0804D8B0
_0804D73E:
	movs r2, 0x1
	mov r8, r2
_0804D742:
	movs r6, 0
	adds r4, r7, 0x1
	str r4, [sp, 0x14]
	ldr r0, [sp, 0x8]
	cmp r6, r0
	blt _0804D750
	b _0804D8A6
_0804D750:
	lsls r1, r7, 4
	str r1, [sp, 0x10]
	subs r0, r1, r7
	lsls r0, 5
	ldr r2, [sp]
	adds r3, r0, r2
_0804D75C:
	lsls r0, r6, 5
	adds r2, r0, r3
	ldrb r1, [r2, 0x8]
	adds r4, r0, 0
	adds r0, r6, 0x1
	str r0, [sp, 0x18]
	cmp r1, 0
	beq _0804D76E
	b _0804D89C
_0804D76E:
	ldrb r0, [r2, 0xA]
	cmp r0, 0
	beq _0804D776
	b _0804D89C
_0804D776:
	ldrb r0, [r2, 0x13]
	negs r1, r0
	orrs r1, r0
	lsrs r1, 31
	ldrb r0, [r2, 0x14]
	cmp r0, 0
	beq _0804D786
	adds r1, 0x1
_0804D786:
	ldrb r0, [r2, 0x15]
	cmp r0, 0
	beq _0804D78E
	adds r1, 0x1
_0804D78E:
	ldrb r0, [r2, 0x16]
	cmp r0, 0
	beq _0804D796
	adds r1, 0x1
_0804D796:
	cmp r1, 0x1
	beq _0804D79C
	b _0804D89C
_0804D79C:
	movs r0, 0x4
	str r3, [sp, 0x1C]
	bl DungeonRandInt
	adds r5, r0, 0
	movs r2, 0
	mov r10, r2
	ldr r1, [sp, 0x10]
	subs r0, r1, r7
	lsls r0, 5
	ldr r1, [sp]
	adds r0, r1
	adds r1, r4, r0
	ldr r3, [sp, 0x1C]
_0804D7B8:
	movs r0, 0x3
	ands r0, r5
	cmp r0, 0x1
	beq _0804D7E0
	cmp r0, 0x1
	bgt _0804D7CA
	cmp r0, 0
	beq _0804D7D4
	b _0804D800
_0804D7CA:
	cmp r0, 0x2
	beq _0804D7E8
	cmp r0, 0x3
	beq _0804D7F0
	b _0804D800
_0804D7D4:
	ldr r0, [sp, 0x4]
	subs r0, 0x1
	cmp r7, r0
	bge _0804D7FE
	ldrb r0, [r1, 0x16]
	b _0804D7FA
_0804D7E0:
	cmp r6, 0
	ble _0804D7FE
	ldrb r0, [r1, 0x13]
	b _0804D7FA
_0804D7E8:
	cmp r7, 0
	ble _0804D7FE
	ldrb r0, [r1, 0x15]
	b _0804D7FA
_0804D7F0:
	ldr r0, [sp, 0x8]
	subs r0, 0x1
	cmp r6, r0
	bge _0804D7FE
	ldrb r0, [r1, 0x14]
_0804D7FA:
	cmp r0, 0
	beq _0804D80E
_0804D7FE:
	adds r5, 0x1
_0804D800:
	mov r0, r10
	cmp r0, 0
	bne _0804D80E
	adds r2, 0x1
	cmp r2, 0x7
	ble _0804D7B8
	b _0804D89C
_0804D80E:
	movs r2, 0x3
	ands r2, r5
	cmp r2, 0x1
	beq _0804D844
	cmp r2, 0x1
	bgt _0804D820
	cmp r2, 0
	beq _0804D82A
	b _0804D89C
_0804D820:
	cmp r2, 0x2
	beq _0804D85C
	cmp r2, 0x3
	beq _0804D880
	b _0804D89C
_0804D82A:
	adds r1, r4, r3
	movs r4, 0xF0
	lsls r4, 1
	adds r2, r1, r4
	ldrb r0, [r2, 0x8]
	cmp r0, 0
	bne _0804D89C
	mov r0, r8
	strb r0, [r1, 0x16]
	strb r0, [r2, 0x15]
	movs r1, 0x1
	mov r9, r1
	b _0804D89C
_0804D844:
	adds r1, r4, r3
	movs r4, 0xF0
	lsls r4, 1
	adds r0, r1, r4
	ldrb r0, [r0, 0x8]
	cmp r0, 0
	bne _0804D89C
	strb r2, [r1, 0x13]
	adds r0, r1, 0
	subs r0, 0x20
	strb r2, [r0, 0x14]
	b _0804D898
_0804D85C:
	adds r1, r4, r3
	movs r2, 0xF0
	lsls r2, 1
	adds r0, r1, r2
	ldrb r0, [r0, 0x8]
	cmp r0, 0
	bne _0804D89C
	mov r4, r8
	strb r4, [r1, 0x15]
	ldr r2, _0804D87C
	adds r0, r1, r2
	strb r4, [r0, 0x16]
	movs r4, 0x1
	mov r9, r4
	b _0804D89C
	.align 2, 0
_0804D87C: .4byte 0xfffffe20
_0804D880:
	adds r1, r4, r3
	movs r2, 0xF0
	lsls r2, 1
	adds r0, r1, r2
	ldrb r0, [r0, 0x8]
	cmp r0, 0
	bne _0804D89C
	mov r4, r8
	strb r4, [r1, 0x14]
	adds r0, r1, 0
	adds r0, 0x20
	strb r4, [r0, 0x13]
_0804D898:
	movs r0, 0x1
	mov r9, r0
_0804D89C:
	ldr r6, [sp, 0x18]
	ldr r1, [sp, 0x8]
	cmp r6, r1
	bge _0804D8A6
	b _0804D75C
_0804D8A6:
	ldr r7, [sp, 0x14]
	ldr r2, [sp, 0x4]
	cmp r7, r2
	bge _0804D8B0
	b _0804D742
_0804D8B0:
	mov r4, r9
	cmp r4, 0
	beq _0804D8B8
	b _0804D730
_0804D8B8:
	add sp, 0x20
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end AssignGridCellConnections

	thumb_func_start CreateGridCellConnections
CreateGridCellConnections:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x58
	str r0, [sp, 0xC]
	str r1, [sp, 0x10]
	str r2, [sp, 0x14]
	str r3, [sp, 0x18]
	ldr r0, [sp, 0x7C]
	lsls r0, 24
	lsrs r0, 24
	str r0, [sp, 0x1C]
	movs r0, 0
	str r0, [sp, 0x20]
	cmp r0, r1
	bge _0804D968
_0804D8EC:
	movs r1, 0
	mov r10, r1
	ldr r2, [sp, 0x20]
	adds r2, 0x1
	str r2, [sp, 0x38]
	ldr r3, [sp, 0x14]
	cmp r10, r3
	bge _0804D95E
	ldr r4, [sp, 0x20]
	lsls r1, r4, 4
	subs r1, r4
	movs r3, 0
	lsls r1, 5
	ldr r0, [sp, 0xC]
	adds r0, 0x8
	adds r1, r0
_0804D90C:
	ldrb r2, [r1]
	cmp r2, 0
	beq _0804D91C
	strb r3, [r1, 0xF]
	strb r3, [r1, 0x10]
	strb r3, [r1, 0x11]
	strb r3, [r1, 0x12]
	b _0804D952
_0804D91C:
	ldr r5, [sp, 0x20]
	cmp r5, 0
	bgt _0804D924
	strb r2, [r1, 0xD]
_0804D924:
	mov r6, r10
	cmp r6, 0
	bgt _0804D92C
	strb r2, [r1, 0xB]
_0804D92C:
	ldr r0, [sp, 0x10]
	subs r0, 0x1
	ldr r7, [sp, 0x20]
	cmp r7, r0
	blt _0804D938
	strb r2, [r1, 0xE]
_0804D938:
	ldr r0, [sp, 0x14]
	subs r0, 0x1
	cmp r10, r0
	blt _0804D942
	strb r2, [r1, 0xC]
_0804D942:
	ldrb r0, [r1, 0xB]
	strb r0, [r1, 0xF]
	ldrb r0, [r1, 0xC]
	strb r0, [r1, 0x10]
	ldrb r0, [r1, 0xD]
	strb r0, [r1, 0x11]
	ldrb r0, [r1, 0xE]
	strb r0, [r1, 0x12]
_0804D952:
	adds r1, 0x20
	movs r0, 0x1
	add r10, r0
	ldr r2, [sp, 0x14]
	cmp r10, r2
	blt _0804D90C
_0804D95E:
	ldr r3, [sp, 0x38]
	str r3, [sp, 0x20]
	ldr r4, [sp, 0x10]
	cmp r3, r4
	blt _0804D8EC
_0804D968:
	movs r5, 0
	str r5, [sp, 0x20]
	ldr r6, [sp, 0x10]
	cmp r5, r6
	blt _0804D974
	b _0804DBC6
_0804D974:
	movs r7, 0
	mov r10, r7
	ldr r0, [sp, 0x20]
	adds r0, 0x1
	str r0, [sp, 0x38]
	ldr r1, [sp, 0x14]
	cmp r10, r1
	blt _0804D986
	b _0804DBBA
_0804D986:
	ldr r2, [sp, 0x20]
	lsls r2, 4
	str r2, [sp, 0x40]
	ldr r3, [sp, 0x20]
	subs r1, r2, r3
	lsls r1, 5
	movs r4, 0
	str r4, [sp, 0x48]
	ldr r5, [sp, 0xC]
	movs r6, 0xF0
	lsls r6, 1
	adds r0, r5, r6
	adds r0, r1
	mov r8, r0
	adds r5, r1, r5
	ldr r7, [sp, 0xC]
	ldr r2, _0804DA0C
	adds r0, r7, r2
	adds r7, r1, r0
	ldr r3, [sp, 0x78]
	str r3, [sp, 0x4C]
	ldr r0, [sp, 0xC]
	adds r0, 0x20
	adds r0, r1, r0
	str r0, [sp, 0x50]
	ldr r0, [sp, 0xC]
	subs r0, 0x20
	adds r6, r1, r0
	ldr r4, [sp, 0x20]
	lsls r0, r4, 2
	ldr r1, [sp, 0x18]
	adds r0, r1
	str r0, [sp, 0x24]
_0804D9C8:
	ldr r2, [sp, 0x20]
	lsls r0, r2, 4
	subs r0, r2
	lsls r0, 5
	ldr r3, [sp, 0xC]
	adds r0, r3
	ldr r1, [sp, 0x48]
	adds r4, r1, r0
	ldrb r0, [r4, 0x8]
	cmp r0, 0
	beq _0804D9E0
	b _0804DB92
_0804D9E0:
	ldrb r0, [r4, 0xA]
	cmp r0, 0
	beq _0804DA10
	movs r2, 0
	ldrsh r0, [r4, r2]
	adds r0, 0x1
	movs r3, 0x4
	ldrsh r1, [r4, r3]
	subs r1, 0x1
	bl DungeonRandRange
	mov r9, r0
	movs r1, 0x2
	ldrsh r0, [r4, r1]
	adds r0, 0x1
	movs r2, 0x6
	ldrsh r1, [r4, r2]
	subs r1, 0x1
	bl DungeonRandRange
	adds r4, r0, 0
	b _0804DA1A
	.align 2, 0
_0804DA0C: .4byte 0xfffffe20
_0804DA10:
	movs r0, 0
	ldrsh r3, [r4, r0]
	mov r9, r3
	movs r1, 0x2
	ldrsh r4, [r4, r1]
_0804DA1A:
	ldrb r0, [r5, 0x17]
	cmp r0, 0
	beq _0804DA74
	ldrb r0, [r6, 0x8]
	cmp r0, 0
	bne _0804DA68
	ldrb r0, [r6, 0xA]
	cmp r0, 0
	beq _0804DA40
	movs r2, 0
	ldrsh r0, [r6, r2]
	adds r0, 0x1
	movs r3, 0x4
	ldrsh r1, [r6, r3]
	subs r1, 0x1
	bl DungeonRandRange
	adds r2, r0, 0
	b _0804DA44
_0804DA40:
	movs r0, 0
	ldrsh r2, [r6, r0]
_0804DA44:
	movs r3, 0x2
	ldrsh r1, [r5, r3]
	movs r0, 0x6
	ldrsh r3, [r6, r0]
	subs r3, 0x1
	mov r12, r3
	movs r3, 0x1
	str r3, [sp]
	ldr r3, [sp, 0x24]
	ldr r0, [r3]
	str r0, [sp, 0x4]
	ldr r3, [sp, 0x4C]
	ldr r0, [r3]
	str r0, [sp, 0x8]
	mov r0, r9
	mov r3, r12
	bl sub_804E328
_0804DA68:
	movs r0, 0
	strb r0, [r5, 0x17]
	strb r0, [r6, 0x18]
	movs r1, 0x1
	strb r1, [r5, 0xB]
	strb r1, [r6, 0xB]
_0804DA74:
	ldrb r0, [r5, 0x18]
	cmp r0, 0
	beq _0804DAD4
	ldr r2, [sp, 0x50]
	ldrb r0, [r2, 0x8]
	cmp r0, 0
	bne _0804DAC6
	ldrb r0, [r2, 0xA]
	cmp r0, 0
	beq _0804DA9C
	movs r3, 0x20
	ldrsh r0, [r5, r3]
	adds r0, 0x1
	movs r2, 0x24
	ldrsh r1, [r5, r2]
	subs r1, 0x1
	bl DungeonRandRange
	adds r2, r0, 0
	b _0804DAA0
_0804DA9C:
	movs r3, 0x20
	ldrsh r2, [r5, r3]
_0804DAA0:
	movs r0, 0x6
	ldrsh r1, [r5, r0]
	subs r1, 0x1
	movs r0, 0x22
	ldrsh r3, [r5, r0]
	mov r12, r3
	movs r3, 0x1
	str r3, [sp]
	ldr r3, [sp, 0x24]
	ldr r0, [r3]
	str r0, [sp, 0x4]
	ldr r3, [sp, 0x4C]
	ldr r0, [r3, 0x4]
	subs r0, 0x1
	str r0, [sp, 0x8]
	mov r0, r9
	mov r3, r12
	bl sub_804E328
_0804DAC6:
	movs r0, 0
	strb r0, [r5, 0x18]
	ldr r1, [sp, 0x50]
	strb r0, [r1, 0x17]
	movs r2, 0x1
	strb r2, [r5, 0xB]
	strb r2, [r1, 0xB]
_0804DAD4:
	ldrb r0, [r5, 0x19]
	cmp r0, 0
	beq _0804DB2E
	ldrb r0, [r7, 0x8]
	cmp r0, 0
	bne _0804DB22
	ldrb r0, [r7, 0xA]
	cmp r0, 0
	beq _0804DAFA
	movs r3, 0x2
	ldrsh r0, [r7, r3]
	adds r0, 0x1
	movs r2, 0x6
	ldrsh r1, [r7, r2]
	subs r1, 0x1
	bl DungeonRandRange
	adds r3, r0, 0
	b _0804DAFE
_0804DAFA:
	movs r0, 0x2
	ldrsh r3, [r7, r0]
_0804DAFE:
	movs r1, 0
	ldrsh r0, [r5, r1]
	movs r1, 0
	ldrsh r2, [r7, r1]
	subs r2, 0x1
	mov r9, r2
	movs r2, 0
	str r2, [sp]
	ldr r2, [sp, 0x24]
	ldr r1, [r2]
	str r1, [sp, 0x4]
	ldr r2, [sp, 0x4C]
	ldr r1, [r2]
	str r1, [sp, 0x8]
	adds r1, r4, 0
	mov r2, r9
	bl sub_804E328
_0804DB22:
	movs r3, 0
	strb r3, [r5, 0x19]
	strb r3, [r7, 0x1A]
	movs r0, 0x1
	strb r0, [r5, 0xB]
	strb r0, [r7, 0xB]
_0804DB2E:
	ldrb r0, [r5, 0x1A]
	cmp r0, 0
	beq _0804DB92
	mov r1, r8
	ldrb r0, [r1, 0x8]
	cmp r0, 0
	bne _0804DB84
	ldrb r0, [r1, 0xA]
	cmp r0, 0
	beq _0804DB56
	movs r2, 0x2
	ldrsh r0, [r1, r2]
	adds r0, 0x1
	movs r3, 0x6
	ldrsh r1, [r1, r3]
	subs r1, 0x1
	bl DungeonRandRange
	adds r3, r0, 0
	b _0804DB5C
_0804DB56:
	mov r0, r8
	movs r1, 0x2
	ldrsh r3, [r0, r1]
_0804DB5C:
	movs r2, 0x4
	ldrsh r0, [r5, r2]
	subs r0, 0x1
	mov r1, r8
	movs r2, 0
	ldrsh r1, [r1, r2]
	mov r9, r1
	movs r1, 0
	str r1, [sp]
	ldr r2, [sp, 0x24]
	ldr r1, [r2, 0x4]
	subs r1, 0x1
	str r1, [sp, 0x4]
	ldr r2, [sp, 0x4C]
	ldr r1, [r2]
	str r1, [sp, 0x8]
	adds r1, r4, 0
	mov r2, r9
	bl sub_804E328
_0804DB84:
	movs r3, 0
	strb r3, [r5, 0x1A]
	mov r4, r8
	strb r3, [r4, 0x19]
	movs r0, 0x1
	strb r0, [r5, 0xB]
	strb r0, [r4, 0xB]
_0804DB92:
	ldr r1, [sp, 0x48]
	adds r1, 0x20
	str r1, [sp, 0x48]
	movs r2, 0x20
	add r8, r2
	adds r5, 0x20
	adds r7, 0x20
	ldr r3, [sp, 0x4C]
	adds r3, 0x4
	str r3, [sp, 0x4C]
	ldr r4, [sp, 0x50]
	adds r4, 0x20
	str r4, [sp, 0x50]
	adds r6, 0x20
	movs r0, 0x1
	add r10, r0
	ldr r1, [sp, 0x14]
	cmp r10, r1
	bge _0804DBBA
	b _0804D9C8
_0804DBBA:
	ldr r2, [sp, 0x38]
	str r2, [sp, 0x20]
	ldr r3, [sp, 0x10]
	cmp r2, r3
	bge _0804DBC6
	b _0804D974
_0804DBC6:
	ldr r4, [sp, 0x1C]
	cmp r4, 0
	beq _0804DBCE
	b _0804E026
_0804DBCE:
	movs r5, 0
	str r5, [sp, 0x20]
	ldr r6, [sp, 0x10]
	cmp r5, r6
	blt _0804DBDA
	b _0804E026
_0804DBDA:
	movs r7, 0
	mov r10, r7
	ldr r0, [sp, 0x20]
	adds r0, 0x1
	str r0, [sp, 0x38]
	ldr r1, [sp, 0x14]
	cmp r10, r1
	blt _0804DBEC
	b _0804E018
_0804DBEC:
	movs r0, 0x64
	bl DungeonRandInt
	mov r2, r10
	adds r2, 0x1
	str r2, [sp, 0x3C]
	cmp r0, 0x4
	ble _0804DBFE
	b _0804E00C
_0804DBFE:
	mov r3, r10
	lsls r1, r3, 5
	ldr r4, [sp, 0x20]
	lsls r2, r4, 4
	subs r0, r2, r4
	lsls r0, 5
	ldr r5, [sp, 0xC]
	adds r0, r5
	adds r4, r1, r0
	ldrb r0, [r4, 0x8]
	str r1, [sp, 0x44]
	str r2, [sp, 0x40]
	cmp r0, 0
	beq _0804DC1C
	b _0804E00C
_0804DC1C:
	ldrb r0, [r4, 0xB]
	cmp r0, 0
	bne _0804DC24
	b _0804E00C
_0804DC24:
	ldrb r0, [r4, 0x12]
	cmp r0, 0
	beq _0804DC2C
	b _0804E00C
_0804DC2C:
	ldrb r0, [r4, 0x9]
	cmp r0, 0
	beq _0804DC34
	b _0804E00C
_0804DC34:
	ldrb r0, [r4, 0xA]
	cmp r0, 0
	bne _0804DC3C
	b _0804E00C
_0804DC3C:
	movs r0, 0x4
	bl DungeonRandInt
	cmp r0, 0x1
	bne _0804DC48
	b _0804DD50
_0804DC48:
	cmp r0, 0x1
	bgt _0804DC52
	cmp r0, 0
	beq _0804DC60
	b _0804E00C
_0804DC52:
	cmp r0, 0x2
	bne _0804DC58
	b _0804DE3C
_0804DC58:
	cmp r0, 0x3
	bne _0804DC5E
	b _0804DF30
_0804DC5E:
	b _0804E00C
_0804DC60:
	ldr r6, [sp, 0x20]
	cmp r6, 0
	bgt _0804DC68
	b _0804E00C
_0804DC68:
	ldr r7, _0804DD48
	adds r2, r4, r7
	ldrb r0, [r2, 0xB]
	cmp r0, 0
	bne _0804DC74
	b _0804E00C
_0804DC74:
	ldrb r0, [r2, 0x8]
	cmp r0, 0
	beq _0804DC7C
	b _0804E00C
_0804DC7C:
	ldrb r0, [r2, 0xA]
	cmp r0, 0
	bne _0804DC84
	b _0804E00C
_0804DC84:
	ldrb r0, [r2, 0x9]
	cmp r0, 0
	beq _0804DC8C
	b _0804E00C
_0804DC8C:
	ldrb r0, [r2, 0x12]
	cmp r0, 0
	beq _0804DC94
	b _0804E00C
_0804DC94:
	movs r1, 0
	ldrsh r0, [r2, r1]
	str r0, [sp, 0x28]
	ldrh r3, [r4, 0x2]
	movs r5, 0x2
	ldrsh r1, [r4, r5]
	ldrh r5, [r2, 0x2]
	movs r6, 0x2
	ldrsh r0, [r2, r6]
	cmp r1, r0
	ble _0804DCAC
	adds r3, r5, 0
_0804DCAC:
	lsls r0, r3, 16
	asrs r0, 16
	mov r9, r0
	movs r0, 0x4
	ldrsh r7, [r4, r0]
	mov r10, r7
	ldrh r3, [r4, 0x6]
	movs r5, 0x6
	ldrsh r1, [r4, r5]
	ldrh r5, [r2, 0x6]
	movs r6, 0x6
	ldrsh r0, [r2, r6]
	cmp r1, r0
	bge _0804DCCA
	adds r3, r5, 0
_0804DCCA:
	lsls r0, r3, 16
	asrs r7, r0, 16
	movs r1, 0
	ldrsh r0, [r4, r1]
	movs r2, 0x2
	ldrsh r1, [r4, r2]
	bl GetTile
	ldrb r0, [r0, 0x9]
	mov r8, r0
	ldr r5, [sp, 0x28]
	cmp r5, r10
	bge _0804DD16
_0804DCE4:
	mov r4, r9
	adds r6, r5, 0x1
	cmp r9, r7
	bge _0804DD10
	ldr r0, _0804DD4C
	adds r3, r0, 0
_0804DCF0:
	adds r0, r5, 0
	adds r1, r4, 0
	str r3, [sp, 0x54]
	bl GetTileSafe
	ldrh r1, [r0]
	ldr r3, [sp, 0x54]
	ands r1, r3
	movs r2, 0x1
	orrs r1, r2
	strh r1, [r0]
	mov r1, r8
	strb r1, [r0, 0x9]
	adds r4, 0x1
	cmp r4, r7
	blt _0804DCF0
_0804DD10:
	adds r5, r6, 0
	cmp r5, r10
	blt _0804DCE4
_0804DD16:
	ldr r2, [sp, 0x40]
	ldr r3, [sp, 0x20]
	subs r0, r2, r3
	lsls r0, 5
	ldr r4, [sp, 0xC]
	adds r0, r4
	ldr r5, [sp, 0x44]
	adds r0, r5, r0
	ldr r6, _0804DD48
	adds r3, r0, r6
	mov r1, sp
	ldrh r1, [r1, 0x28]
	strh r1, [r3]
	mov r2, r10
	strh r2, [r3, 0x4]
	mov r4, r9
	strh r4, [r3, 0x2]
	strh r7, [r3, 0x6]
	movs r5, 0x1
	strb r5, [r0, 0x12]
	strb r5, [r3, 0x12]
	movs r6, 0
	strb r6, [r0, 0xB]
	strb r5, [r0, 0x11]
	b _0804E00C
	.align 2, 0
_0804DD48: .4byte 0xfffffe20
_0804DD4C: .4byte 0x0000fffc
_0804DD50:
	mov r7, r10
	cmp r7, 0
	bgt _0804DD58
	b _0804E00C
_0804DD58:
	adds r2, r4, 0
	subs r2, 0x20
	ldrb r0, [r2, 0xB]
	cmp r0, 0
	bne _0804DD64
	b _0804E00C
_0804DD64:
	ldrb r0, [r2, 0x8]
	cmp r0, 0
	beq _0804DD6C
	b _0804E00C
_0804DD6C:
	ldrb r0, [r2, 0xA]
	cmp r0, 0
	bne _0804DD74
	b _0804E00C
_0804DD74:
	ldrb r0, [r2, 0x9]
	cmp r0, 0
	beq _0804DD7C
	b _0804E00C
_0804DD7C:
	ldrb r0, [r2, 0x12]
	cmp r0, 0
	beq _0804DD84
	b _0804E00C
_0804DD84:
	ldrh r3, [r4]
	movs r0, 0
	ldrsh r1, [r4, r0]
	ldrh r5, [r2]
	movs r6, 0
	ldrsh r0, [r2, r6]
	cmp r1, r0
	ble _0804DD96
	adds r3, r5, 0
_0804DD96:
	lsls r0, r3, 16
	asrs r0, 16
	str r0, [sp, 0x2C]
	movs r0, 0x2
	ldrsh r7, [r2, r0]
	mov r10, r7
	ldrh r3, [r4, 0x4]
	movs r5, 0x4
	ldrsh r1, [r4, r5]
	ldrh r5, [r2, 0x4]
	movs r6, 0x4
	ldrsh r0, [r2, r6]
	cmp r1, r0
	bge _0804DDB4
	adds r3, r5, 0
_0804DDB4:
	lsls r0, r3, 16
	asrs r0, 16
	mov r8, r0
	movs r0, 0x6
	ldrsh r7, [r4, r0]
	movs r1, 0
	ldrsh r0, [r4, r1]
	movs r2, 0x2
	ldrsh r1, [r4, r2]
	bl GetTile
	ldrb r0, [r0, 0x9]
	mov r9, r0
	ldr r5, [sp, 0x2C]
	cmp r5, r8
	bge _0804DE06
_0804DDD4:
	mov r4, r10
	adds r6, r5, 0x1
	cmp r10, r7
	bge _0804DE00
	ldr r0, _0804DE38
	adds r3, r0, 0
_0804DDE0:
	adds r0, r5, 0
	adds r1, r4, 0
	str r3, [sp, 0x54]
	bl GetTileSafe
	ldrh r1, [r0]
	ldr r3, [sp, 0x54]
	ands r1, r3
	movs r2, 0x1
	orrs r1, r2
	strh r1, [r0]
	mov r1, r9
	strb r1, [r0, 0x9]
	adds r4, 0x1
	cmp r4, r7
	blt _0804DDE0
_0804DE00:
	adds r5, r6, 0
	cmp r5, r8
	blt _0804DDD4
_0804DE06:
	ldr r2, [sp, 0x40]
	ldr r3, [sp, 0x20]
	subs r0, r2, r3
	lsls r0, 5
	ldr r4, [sp, 0xC]
	adds r0, r4
	ldr r5, [sp, 0x44]
	adds r0, r5, r0
	adds r3, r0, 0
	subs r3, 0x20
	mov r6, sp
	ldrh r6, [r6, 0x2C]
	strh r6, [r3]
	mov r1, r8
	strh r1, [r3, 0x4]
	mov r2, r10
	strh r2, [r3, 0x2]
	strh r7, [r3, 0x6]
	movs r4, 0x1
	strb r4, [r0, 0x12]
	strb r4, [r3, 0x12]
	movs r5, 0
	strb r5, [r0, 0xB]
	strb r4, [r0, 0x11]
	b _0804E00C
	.align 2, 0
_0804DE38: .4byte 0x0000fffc
_0804DE3C:
	ldr r0, [sp, 0x10]
	subs r0, 0x2
	ldr r6, [sp, 0x20]
	cmp r6, r0
	ble _0804DE48
	b _0804E00C
_0804DE48:
	movs r7, 0xF0
	lsls r7, 1
	adds r2, r4, r7
	ldrb r0, [r2, 0xB]
	cmp r0, 0
	bne _0804DE56
	b _0804E00C
_0804DE56:
	ldrb r0, [r2, 0x8]
	cmp r0, 0
	beq _0804DE5E
	b _0804E00C
_0804DE5E:
	ldrb r0, [r2, 0xA]
	cmp r0, 0
	bne _0804DE66
	b _0804E00C
_0804DE66:
	ldrb r0, [r2, 0x9]
	cmp r0, 0
	beq _0804DE6E
	b _0804E00C
_0804DE6E:
	ldrb r0, [r2, 0x12]
	cmp r0, 0
	beq _0804DE76
	b _0804E00C
_0804DE76:
	movs r1, 0
	ldrsh r0, [r4, r1]
	str r0, [sp, 0x30]
	ldrh r3, [r2, 0x2]
	movs r5, 0x2
	ldrsh r1, [r2, r5]
	ldrh r5, [r4, 0x2]
	movs r6, 0x2
	ldrsh r0, [r4, r6]
	cmp r1, r0
	ble _0804DE8E
	adds r3, r5, 0
_0804DE8E:
	lsls r0, r3, 16
	asrs r0, 16
	mov r9, r0
	movs r0, 0x4
	ldrsh r7, [r2, r0]
	mov r10, r7
	ldrh r3, [r2, 0x6]
	movs r5, 0x6
	ldrsh r1, [r2, r5]
	ldrh r2, [r4, 0x6]
	movs r6, 0x6
	ldrsh r0, [r4, r6]
	cmp r1, r0
	bge _0804DEAC
	adds r3, r2, 0
_0804DEAC:
	lsls r0, r3, 16
	asrs r7, r0, 16
	movs r0, 0x2
	ldrsh r1, [r4, r0]
	ldr r0, [sp, 0x30]
	bl GetTile
	ldrb r0, [r0, 0x9]
	mov r8, r0
	ldr r5, [sp, 0x30]
	cmp r5, r10
	bge _0804DEF6
_0804DEC4:
	mov r4, r9
	adds r6, r5, 0x1
	cmp r9, r7
	bge _0804DEF0
	ldr r1, _0804DF2C
	adds r3, r1, 0
_0804DED0:
	adds r0, r5, 0
	adds r1, r4, 0
	str r3, [sp, 0x54]
	bl GetTileSafe
	ldrh r1, [r0]
	ldr r3, [sp, 0x54]
	ands r1, r3
	movs r2, 0x1
	orrs r1, r2
	strh r1, [r0]
	mov r2, r8
	strb r2, [r0, 0x9]
	adds r4, 0x1
	cmp r4, r7
	blt _0804DED0
_0804DEF0:
	adds r5, r6, 0
	cmp r5, r10
	blt _0804DEC4
_0804DEF6:
	ldr r3, [sp, 0x40]
	ldr r4, [sp, 0x20]
	subs r0, r3, r4
	lsls r0, 5
	ldr r5, [sp, 0xC]
	adds r0, r5
	ldr r6, [sp, 0x44]
	adds r0, r6, r0
	mov r1, sp
	ldrh r1, [r1, 0x30]
	strh r1, [r0]
	mov r2, r10
	strh r2, [r0, 0x4]
	mov r3, r9
	strh r3, [r0, 0x2]
	strh r7, [r0, 0x6]
	movs r4, 0xF0
	lsls r4, 1
	adds r1, r0, r4
	movs r5, 0x1
	strb r5, [r1, 0x12]
	strb r5, [r0, 0x12]
	movs r6, 0
	strb r6, [r1, 0xB]
	strb r5, [r1, 0x11]
	b _0804E00C
	.align 2, 0
_0804DF2C: .4byte 0x0000fffc
_0804DF30:
	ldr r0, [sp, 0x14]
	subs r0, 0x2
	cmp r10, r0
	bgt _0804E00C
	adds r3, r4, 0
	adds r3, 0x20
	ldrb r0, [r3, 0xB]
	cmp r0, 0
	beq _0804E00C
	ldrb r0, [r3, 0x8]
	cmp r0, 0
	bne _0804E00C
	ldrb r0, [r3, 0xA]
	cmp r0, 0
	beq _0804E00C
	ldrb r0, [r3, 0x9]
	cmp r0, 0
	bne _0804E00C
	ldrb r0, [r3, 0x12]
	cmp r0, 0
	bne _0804E00C
	ldrh r2, [r4, 0x20]
	movs r7, 0x20
	ldrsh r1, [r4, r7]
	ldrh r5, [r4]
	movs r6, 0
	ldrsh r0, [r4, r6]
	cmp r1, r0
	ble _0804DF6C
	adds r2, r5, 0
_0804DF6C:
	lsls r0, r2, 16
	asrs r0, 16
	str r0, [sp, 0x34]
	movs r7, 0x2
	ldrsh r6, [r4, r7]
	ldrh r2, [r3, 0x4]
	movs r0, 0x4
	ldrsh r1, [r3, r0]
	ldrh r5, [r4, 0x4]
	movs r7, 0x4
	ldrsh r0, [r4, r7]
	cmp r1, r0
	bge _0804DF88
	adds r2, r5, 0
_0804DF88:
	lsls r0, r2, 16
	asrs r0, 16
	mov r8, r0
	movs r0, 0x6
	ldrsh r3, [r3, r0]
	movs r1, 0
	ldrsh r0, [r4, r1]
	adds r1, r6, 0
	str r3, [sp, 0x54]
	bl GetTile
	ldrb r0, [r0, 0x9]
	mov r10, r0
	ldr r5, [sp, 0x34]
	ldr r3, [sp, 0x54]
	cmp r5, r8
	bge _0804DFDE
_0804DFAA:
	adds r4, r6, 0
	adds r7, r5, 0x1
	cmp r6, r3
	bge _0804DFD8
	ldr r2, _0804E038
	mov r9, r2
_0804DFB6:
	adds r0, r5, 0
	adds r1, r4, 0
	str r3, [sp, 0x54]
	bl GetTileSafe
	ldrh r1, [r0]
	mov r2, r9
	ands r1, r2
	movs r2, 0x1
	orrs r1, r2
	strh r1, [r0]
	mov r1, r10
	strb r1, [r0, 0x9]
	adds r4, 0x1
	ldr r3, [sp, 0x54]
	cmp r4, r3
	blt _0804DFB6
_0804DFD8:
	adds r5, r7, 0
	cmp r5, r8
	blt _0804DFAA
_0804DFDE:
	ldr r2, [sp, 0x40]
	ldr r4, [sp, 0x20]
	subs r0, r2, r4
	lsls r0, 5
	ldr r5, [sp, 0xC]
	adds r0, r5
	ldr r7, [sp, 0x44]
	adds r0, r7, r0
	mov r1, sp
	ldrh r1, [r1, 0x34]
	strh r1, [r0]
	mov r2, r8
	strh r2, [r0, 0x4]
	strh r6, [r0, 0x2]
	strh r3, [r0, 0x6]
	adds r1, r0, 0
	adds r1, 0x20
	movs r3, 0x1
	strb r3, [r1, 0x12]
	strb r3, [r0, 0x12]
	movs r4, 0
	strb r4, [r1, 0xB]
	strb r3, [r1, 0x11]
_0804E00C:
	ldr r5, [sp, 0x3C]
	mov r10, r5
	ldr r6, [sp, 0x14]
	cmp r10, r6
	bge _0804E018
	b _0804DBEC
_0804E018:
	ldr r7, [sp, 0x38]
	str r7, [sp, 0x20]
	adds r0, r7, 0
	ldr r1, [sp, 0x10]
	cmp r0, r1
	bge _0804E026
	b _0804DBDA
_0804E026:
	add sp, 0x58
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_0804E038: .4byte 0x0000fffc
	thumb_func_end CreateGridCellConnections

	thumb_func_start GenerateRoomImperfections
GenerateRoomImperfections:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x44
	str r0, [sp]
	str r1, [sp, 0x4]
	str r2, [sp, 0x8]
	movs r0, 0
	str r0, [sp, 0xC]
	cmp r0, r1
	blt _0804E058
	b _0804E318
_0804E058:
	movs r2, 0
	ldr r1, [sp, 0xC]
	adds r1, 0x1
	str r1, [sp, 0x28]
	ldr r3, [sp, 0x8]
	cmp r2, r3
	blt _0804E068
	b _0804E30C
_0804E068:
	ldr r4, [sp, 0xC]
	lsls r4, 4
	str r4, [sp, 0x14]
	ldr r6, [sp, 0xC]
	subs r0, r4, r6
	lsls r0, 5
	ldr r1, [sp]
	adds r0, r1
	str r0, [sp, 0x18]
_0804E07A:
	lsls r0, r2, 5
	ldr r3, [sp, 0x18]
	adds r4, r0, r3
	ldrb r1, [r4, 0x8]
	str r0, [sp, 0x34]
	adds r2, 0x1
	str r2, [sp, 0x2C]
	cmp r1, 0
	beq _0804E08E
	b _0804E302
_0804E08E:
	ldrb r0, [r4, 0x11]
	cmp r0, 0
	beq _0804E096
	b _0804E302
_0804E096:
	ldrb r0, [r4, 0x12]
	cmp r0, 0
	beq _0804E09E
	b _0804E302
_0804E09E:
	ldrb r0, [r4, 0xB]
	cmp r0, 0
	bne _0804E0A6
	b _0804E302
_0804E0A6:
	ldrb r0, [r4, 0xA]
	cmp r0, 0
	bne _0804E0AE
	b _0804E302
_0804E0AE:
	ldrb r0, [r4, 0x9]
	cmp r0, 0
	beq _0804E0B6
	b _0804E302
_0804E0B6:
	ldrb r0, [r4, 0x10]
	cmp r0, 0
	beq _0804E0BE
	b _0804E302
_0804E0BE:
	ldrb r0, [r4, 0x1C]
	cmp r0, 0
	bne _0804E0C6
	b _0804E302
_0804E0C6:
	movs r0, 0x64
	bl DungeonRandInt
	cmp r0, 0x3B
	bgt _0804E0D2
	b _0804E302
_0804E0D2:
	movs r6, 0x4
	ldrsh r2, [r4, r6]
	movs r1, 0
	ldrsh r0, [r4, r1]
	subs r2, r0
	movs r3, 0x6
	ldrsh r0, [r4, r3]
	movs r6, 0x2
	ldrsh r1, [r4, r6]
	subs r0, r1
	adds r2, r0
	str r2, [sp, 0x10]
	adds r0, r2, 0
	cmp r2, 0
	bge _0804E0F2
	adds r0, 0x3
_0804E0F2:
	asrs r0, 2
	str r0, [sp, 0x10]
	cmp r0, 0
	bne _0804E0FE
	movs r0, 0x1
	str r0, [sp, 0x10]
_0804E0FE:
	movs r1, 0
	ldr r2, [sp, 0x10]
	cmp r1, r2
	blt _0804E108
	b _0804E302
_0804E108:
	ldr r3, [sp, 0x14]
	ldr r4, [sp, 0xC]
	subs r0, r3, r4
	lsls r0, 5
	ldr r6, [sp]
	adds r0, r6
	ldr r2, [sp, 0x34]
	adds r0, r2, r0
	str r0, [sp, 0x20]
_0804E11A:
	movs r4, 0
	adds r1, 0x1
	str r1, [sp, 0x30]
_0804E120:
	movs r0, 0x4
	bl DungeonRandInt
	str r0, [sp, 0x1C]
	cmp r0, 0x1
	beq _0804E14A
	cmp r0, 0x1
	ble _0804E138
	cmp r0, 0x2
	beq _0804E168
	cmp r0, 0x3
	beq _0804E182
_0804E138:
	ldr r3, [sp, 0x20]
	movs r6, 0
	ldrsh r7, [r3, r6]
	movs r1, 0x2
	ldrsh r0, [r3, r1]
	mov r8, r0
	cmp r4, 0
	bne _0804E19C
	b _0804E15C
_0804E14A:
	ldr r2, [sp, 0x20]
	movs r3, 0x4
	ldrsh r0, [r2, r3]
	subs r7, r0, 0x1
	movs r0, 0x2
	ldrsh r6, [r2, r0]
	mov r8, r6
	cmp r4, 0
	beq _0804E162
_0804E15C:
	movs r3, 0
	movs r2, 0x1
	b _0804E1A0
_0804E162:
	movs r3, 0x1
	negs r3, r3
	b _0804E19E
_0804E168:
	ldr r1, [sp, 0x20]
	movs r2, 0x4
	ldrsh r0, [r1, r2]
	subs r7, r0, 0x1
	movs r3, 0x6
	ldrsh r0, [r1, r3]
	subs r0, 0x1
	mov r8, r0
	cmp r4, 0
	beq _0804E194
	movs r3, 0x1
	negs r3, r3
	b _0804E19E
_0804E182:
	ldr r6, [sp, 0x20]
	movs r0, 0
	ldrsh r7, [r6, r0]
	movs r1, 0x6
	ldrsh r0, [r6, r1]
	subs r0, 0x1
	mov r8, r0
	cmp r4, 0
	beq _0804E19C
_0804E194:
	movs r3, 0
	movs r2, 0x1
	negs r2, r2
	b _0804E1A0
_0804E19C:
	movs r3, 0x1
_0804E19E:
	movs r2, 0
_0804E1A0:
	movs r6, 0
	mov r9, r6
	ldr r5, [sp, 0x34]
	ldr r0, [sp, 0x14]
	str r0, [sp, 0x40]
	ldr r6, [sp, 0x18]
	adds r1, r5, r6
	movs r6, 0
	ldrsh r0, [r1, r6]
	mov r10, r0
	adds r4, 0x1
	str r4, [sp, 0x24]
	cmp r7, r10
	bge _0804E1BE
	b _0804E2F0
_0804E1BE:
	movs r4, 0x4
	ldrsh r0, [r1, r4]
	cmp r7, r0
	blt _0804E1C8
	b _0804E2F0
_0804E1C8:
	ldr r6, [sp, 0x40]
	ldr r1, [sp, 0xC]
	subs r0, r6, r1
	lsls r0, 5
	ldr r4, [sp]
	adds r0, r4
	adds r4, r5, r0
	movs r6, 0x2
	ldrsh r0, [r4, r6]
	cmp r8, r0
	bge _0804E1E0
	b _0804E2F0
_0804E1E0:
	movs r1, 0x6
	ldrsh r0, [r4, r1]
	cmp r8, r0
	blt _0804E1EA
	b _0804E2F0
_0804E1EA:
	adds r0, r7, 0
	mov r1, r8
	str r2, [sp, 0x38]
	str r3, [sp, 0x3C]
	bl GetTile
	ldrh r1, [r0]
	movs r0, 0x3
	ands r0, r1
	ldr r2, [sp, 0x38]
	ldr r3, [sp, 0x3C]
	cmp r0, 0x1
	bne _0804E2D0
	movs r6, 0
_0804E206:
	ldr r1, _0804E228
	lsls r0, r6, 2
	adds r0, r1
	movs r2, 0
	ldrsh r1, [r0, r2]
	adds r1, r7
	mov r10, r1
	movs r3, 0x2
	ldrsh r0, [r0, r3]
	add r0, r8
	mov r9, r0
	movs r3, 0
	movs r5, 0x1
	negs r5, r5
_0804E222:
	movs r4, 0x1
	negs r4, r4
	b _0804E22E
	.align 2, 0
_0804E228: .4byte gAdjacentTileOffsets
_0804E22C:
	adds r4, 0x1
_0804E22E:
	cmp r4, 0x1
	bgt _0804E25A
	mov r1, r10
	adds r0, r1, r4
	mov r2, r9
	adds r1, r2, r5
	str r3, [sp, 0x3C]
	bl GetTile
	adds r2, r0, 0
	ldrh r1, [r2]
	movs r0, 0x3
	ands r0, r1
	ldr r3, [sp, 0x3C]
	cmp r0, 0x1
	bne _0804E22C
	ldrb r0, [r2, 0x9]
	cmp r0, 0xFF
	bne _0804E256
	movs r3, 0x1
_0804E256:
	cmp r3, 0
	beq _0804E22C
_0804E25A:
	cmp r3, 0
	bne _0804E26A
	adds r5, 0x1
	cmp r5, 0x1
	ble _0804E222
	adds r6, 0x1
	cmp r6, 0x7
	ble _0804E206
_0804E26A:
	cmp r6, 0x8
	bne _0804E2F0
	movs r6, 0
	ldr r3, [sp, 0x1C]
	lsls r1, r3, 3
	ldr r0, _0804E2C4
	adds r4, r1, r0
_0804E278:
	ldr r0, _0804E2C8
	lsls r1, r6, 2
	adds r1, r0
	movs r2, 0
	ldrsh r0, [r1, r2]
	movs r3, 0x2
	ldrsh r1, [r1, r3]
	adds r0, r7, r0
	add r1, r8
	bl GetTile
	ldrh r1, [r0]
	movs r0, 0x3
	ands r0, r1
	movs r1, 0
	cmp r0, 0x1
	bne _0804E29C
	movs r1, 0x1
_0804E29C:
	ldrb r0, [r4]
	cmp r0, r1
	bne _0804E2AA
	adds r4, 0x2
	adds r6, 0x2
	cmp r6, 0x7
	ble _0804E278
_0804E2AA:
	cmp r6, 0x8
	bne _0804E2F0
	adds r0, r7, 0
	mov r1, r8
	bl GetTileSafe
	ldrh r2, [r0]
	ldr r4, _0804E2CC
	adds r1, r4, 0
	ands r2, r1
	strh r2, [r0]
	b _0804E2F0
	.align 2, 0
_0804E2C4: .4byte gUnknown_80F6DD5
_0804E2C8: .4byte gAdjacentTileOffsets
_0804E2CC: .4byte 0x0000fffc
_0804E2D0:
	adds r7, r3
	add r8, r2
	movs r6, 0x1
	add r9, r6
	mov r0, r9
	cmp r0, 0x9
	bgt _0804E2F0
	movs r1, 0
	ldrsh r0, [r4, r1]
	cmp r7, r0
	blt _0804E2F0
	movs r6, 0x4
	ldrsh r0, [r4, r6]
	cmp r7, r0
	bge _0804E2F0
	b _0804E1C8
_0804E2F0:
	ldr r4, [sp, 0x24]
	cmp r4, 0x1
	bgt _0804E2F8
	b _0804E120
_0804E2F8:
	ldr r1, [sp, 0x30]
	ldr r0, [sp, 0x10]
	cmp r1, r0
	bge _0804E302
	b _0804E11A
_0804E302:
	ldr r2, [sp, 0x2C]
	ldr r1, [sp, 0x8]
	cmp r2, r1
	bge _0804E30C
	b _0804E07A
_0804E30C:
	ldr r2, [sp, 0x28]
	str r2, [sp, 0xC]
	ldr r3, [sp, 0x4]
	cmp r2, r3
	bge _0804E318
	b _0804E058
_0804E318:
	add sp, 0x44
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end GenerateRoomImperfections

	thumb_func_start sub_804E328
sub_804E328:
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
	ldr r0, [sp, 0x28]
	lsls r0, 24
	mov r10, r5
	mov r9, r4
	ldr r1, [sp, 0x2C]
	mov r8, r1
	ldr r7, [sp, 0x30]
	cmp r0, 0
	bne _0804E350
	b _0804E470
_0804E350:
	movs r6, 0
_0804E352:
	cmp r4, r7
	beq _0804E3A8
	adds r0, r6, 0
	adds r6, 0x1
	cmp r0, 0x37
	ble _0804E360
	b _0804E57E
_0804E360:
	adds r0, r5, 0
	adds r1, r4, 0
	bl GetTile
	ldrh r1, [r0]
	movs r0, 0x3
	ands r0, r1
	cmp r0, 0x1
	beq _0804E390
	adds r0, r5, 0
	adds r1, r4, 0
	bl GetTileSafe
	ldrh r2, [r0]
	ldr r3, _0804E38C
	adds r1, r3, 0
	ands r2, r1
	movs r1, 0x1
	orrs r2, r1
	strh r2, [r0]
	b _0804E39C
	.align 2, 0
_0804E38C: .4byte 0x0000fffc
_0804E390:
	cmp r5, r10
	beq _0804E396
	b _0804E57E
_0804E396:
	cmp r4, r9
	beq _0804E39C
	b _0804E57E
_0804E39C:
	cmp r4, r7
	bge _0804E3A4
	adds r4, 0x1
	b _0804E352
_0804E3A4:
	subs r4, 0x1
	b _0804E352
_0804E3A8:
	movs r6, 0
	ldr r0, [sp]
	cmp r5, r0
	beq _0804E40A
	movs r7, 0
_0804E3B2:
	adds r0, r6, 0
	adds r6, 0x1
	cmp r0, 0x37
	ble _0804E3BC
	b _0804E57E
_0804E3BC:
	adds r0, r5, 0
	adds r1, r4, 0
	bl GetTile
	ldrh r1, [r0]
	movs r0, 0x3
	ands r0, r1
	cmp r0, 0x1
	beq _0804E3EC
	adds r0, r5, 0
	adds r1, r4, 0
	bl GetTileSafe
	ldrh r2, [r0]
	ldr r3, _0804E3E8
	adds r1, r3, 0
	ands r2, r1
	movs r1, 0x1
	orrs r2, r1
	strh r2, [r0]
	b _0804E3F8
	.align 2, 0
_0804E3E8: .4byte 0x0000fffc
_0804E3EC:
	cmp r5, r10
	beq _0804E3F2
	b _0804E57E
_0804E3F2:
	cmp r4, r9
	beq _0804E3F8
	b _0804E57E
_0804E3F8:
	ldr r0, [sp]
	cmp r5, r0
	bge _0804E402
	adds r5, 0x1
	b _0804E404
_0804E402:
	subs r5, 0x1
_0804E404:
	ldr r1, [sp]
	cmp r5, r1
	bne _0804E3B2
_0804E40A:
	movs r6, 0
	ldr r3, [sp, 0x4]
	cmp r4, r3
	bne _0804E414
	b _0804E57E
_0804E414:
	movs r7, 0
_0804E416:
	adds r0, r6, 0
	adds r6, 0x1
	cmp r0, 0x37
	ble _0804E420
	b _0804E57E
_0804E420:
	adds r0, r5, 0
	adds r1, r4, 0
	bl GetTile
	ldrh r1, [r0]
	movs r0, 0x3
	ands r0, r1
	cmp r0, 0x1
	beq _0804E450
	adds r0, r5, 0
	adds r1, r4, 0
	bl GetTileSafe
	ldrh r2, [r0]
	ldr r3, _0804E44C
	adds r1, r3, 0
	ands r2, r1
	movs r1, 0x1
	orrs r2, r1
	strh r2, [r0]
	b _0804E45C
	.align 2, 0
_0804E44C: .4byte 0x0000fffc
_0804E450:
	cmp r5, r10
	beq _0804E456
	b _0804E57E
_0804E456:
	cmp r4, r9
	beq _0804E45C
	b _0804E57E
_0804E45C:
	ldr r0, [sp, 0x4]
	cmp r4, r0
	bge _0804E466
	adds r4, 0x1
	b _0804E468
_0804E466:
	subs r4, 0x1
_0804E468:
	ldr r1, [sp, 0x4]
	cmp r4, r1
	bne _0804E416
	b _0804E57E
_0804E470:
	movs r6, 0
	cmp r5, r8
	beq _0804E4C6
	movs r7, 0
_0804E478:
	adds r0, r6, 0
	adds r6, 0x1
	cmp r0, 0x37
	ble _0804E482
	b _0804E57E
_0804E482:
	adds r0, r5, 0
	adds r1, r4, 0
	bl GetTile
	ldrh r1, [r0]
	movs r0, 0x3
	ands r0, r1
	cmp r0, 0x1
	beq _0804E4B0
	adds r0, r5, 0
	adds r1, r4, 0
	bl GetTileSafe
	ldrh r2, [r0]
	ldr r3, _0804E4AC
	adds r1, r3, 0
	ands r2, r1
	movs r1, 0x1
	orrs r2, r1
	strh r2, [r0]
	b _0804E4B8
	.align 2, 0
_0804E4AC: .4byte 0x0000fffc
_0804E4B0:
	cmp r5, r10
	bne _0804E57E
	cmp r4, r9
	bne _0804E57E
_0804E4B8:
	cmp r5, r8
	bge _0804E4C0
	adds r5, 0x1
	b _0804E4C2
_0804E4C0:
	subs r5, 0x1
_0804E4C2:
	cmp r5, r8
	bne _0804E478
_0804E4C6:
	movs r6, 0
	ldr r0, [sp, 0x4]
	cmp r4, r0
	beq _0804E522
	movs r7, 0
_0804E4D0:
	adds r0, r6, 0
	adds r6, 0x1
	cmp r0, 0x37
	bgt _0804E57E
	adds r0, r5, 0
	adds r1, r4, 0
	bl GetTile
	ldrh r1, [r0]
	movs r0, 0x3
	ands r0, r1
	cmp r0, 0x1
	beq _0804E508
	adds r0, r5, 0
	adds r1, r4, 0
	bl GetTileSafe
	ldrh r2, [r0]
	ldr r3, _0804E504
	adds r1, r3, 0
	ands r2, r1
	movs r1, 0x1
	orrs r2, r1
	strh r2, [r0]
	b _0804E510
	.align 2, 0
_0804E504: .4byte 0x0000fffc
_0804E508:
	cmp r5, r10
	bne _0804E57E
	cmp r4, r9
	bne _0804E57E
_0804E510:
	ldr r0, [sp, 0x4]
	cmp r4, r0
	bge _0804E51A
	adds r4, 0x1
	b _0804E51C
_0804E51A:
	subs r4, 0x1
_0804E51C:
	ldr r1, [sp, 0x4]
	cmp r4, r1
	bne _0804E4D0
_0804E522:
	movs r6, 0
	ldr r3, [sp]
	cmp r5, r3
	beq _0804E57E
	movs r7, 0
_0804E52C:
	adds r0, r6, 0
	adds r6, 0x1
	cmp r0, 0x37
	bgt _0804E57E
	adds r0, r5, 0
	adds r1, r4, 0
	bl GetTile
	ldrh r1, [r0]
	movs r0, 0x3
	ands r0, r1
	cmp r0, 0x1
	beq _0804E564
	adds r0, r5, 0
	adds r1, r4, 0
	bl GetTileSafe
	ldrh r2, [r0]
	ldr r3, _0804E560
	adds r1, r3, 0
	ands r2, r1
	movs r1, 0x1
	orrs r2, r1
	strh r2, [r0]
	b _0804E56C
	.align 2, 0
_0804E560: .4byte 0x0000fffc
_0804E564:
	cmp r5, r10
	bne _0804E57E
	cmp r4, r9
	bne _0804E57E
_0804E56C:
	ldr r0, [sp]
	cmp r5, r0
	bge _0804E576
	adds r5, 0x1
	b _0804E578
_0804E576:
	subs r5, 0x1
_0804E578:
	ldr r1, [sp]
	cmp r5, r1
	bne _0804E52C
_0804E57E:
	add sp, 0x8
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_804E328

	thumb_func_start EnsureConnectedGrid
EnsureConnectedGrid:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x40
	str r0, [sp, 0xC]
	str r1, [sp, 0x10]
	str r2, [sp, 0x14]
	str r3, [sp, 0x18]
	movs r0, 0
	str r0, [sp, 0x1C]
	cmp r0, r1
	blt _0804E5AE
	b _0804E8AA
_0804E5AE:
	movs r1, 0x1
	mov r10, r1
_0804E5B2:
	movs r2, 0
	str r2, [sp, 0x20]
	ldr r3, [sp, 0x1C]
	adds r3, 0x1
	str r3, [sp, 0x2C]
	ldr r4, [sp, 0x14]
	cmp r2, r4
	blt _0804E5C4
	b _0804E89E
_0804E5C4:
	ldr r5, [sp, 0x1C]
	lsls r5, 4
	ldr r6, [sp, 0x1C]
	subs r1, r5, r6
	lsls r1, 5
	ldr r2, [sp, 0xC]
	movs r3, 0xF0
	lsls r3, 1
	adds r0, r2, r3
	adds r0, r1
	mov r8, r0
	adds r6, r1, r2
	ldr r4, _0804E6A4
	adds r0, r2, r4
	adds r7, r1, r0
	adds r0, r2, 0
	adds r0, 0x20
	adds r0, r1
	mov r9, r0
	ldr r5, [sp, 0x60]
	str r5, [sp, 0x34]
	adds r0, r2, 0
	subs r0, 0x20
	adds r1, r0
	str r1, [sp, 0x38]
	movs r0, 0
	str r0, [sp, 0x3C]
	ldr r1, [sp, 0x1C]
	lsls r0, r1, 2
	ldr r2, [sp, 0x18]
	adds r0, r2
	str r0, [sp, 0x28]
_0804E604:
	ldr r3, [sp, 0x1C]
	lsls r0, r3, 4
	subs r0, r3
	lsls r0, 5
	ldr r4, [sp, 0xC]
	adds r0, r4
	ldr r5, [sp, 0x3C]
	adds r4, r5, r0
	ldrb r0, [r4, 0x8]
	cmp r0, 0
	beq _0804E61C
	b _0804E874
_0804E61C:
	ldrb r0, [r4, 0x11]
	cmp r0, 0
	beq _0804E624
	b _0804E874
_0804E624:
	ldrb r0, [r4, 0xB]
	cmp r0, 0
	beq _0804E62C
	b _0804E874
_0804E62C:
	ldrb r0, [r4, 0xA]
	cmp r0, 0
	bne _0804E634
	b _0804E848
_0804E634:
	ldrb r0, [r4, 0x9]
	cmp r0, 0
	beq _0804E63C
	b _0804E848
_0804E63C:
	movs r1, 0
	ldrsh r0, [r4, r1]
	adds r0, 0x1
	movs r2, 0x4
	ldrsh r1, [r4, r2]
	subs r1, 0x1
	bl DungeonRandRange
	str r0, [sp, 0x24]
	movs r3, 0x2
	ldrsh r0, [r4, r3]
	adds r0, 0x1
	movs r5, 0x6
	ldrsh r1, [r4, r5]
	subs r1, 0x1
	bl DungeonRandRange
	adds r5, r0, 0
	ldr r0, [sp, 0x20]
	cmp r0, 0
	ble _0804E6DC
	subs r4, 0x20
	ldrb r0, [r4, 0x8]
	cmp r0, 0
	bne _0804E6DC
	ldrb r0, [r4, 0x12]
	cmp r0, 0
	bne _0804E6DC
	ldrb r0, [r4, 0xB]
	cmp r0, 0
	beq _0804E6DC
	ldrb r0, [r4, 0xA]
	cmp r0, 0
	beq _0804E6A8
	movs r1, 0
	ldrsh r0, [r4, r1]
	adds r0, 0x1
	movs r2, 0x4
	ldrsh r1, [r4, r2]
	subs r1, 0x1
	bl DungeonRandRange
	adds r5, r0, 0
	movs r3, 0x2
	ldrsh r0, [r4, r3]
	adds r0, 0x1
	movs r2, 0x6
	ldrsh r1, [r4, r2]
	subs r1, 0x1
	bl DungeonRandRange
	b _0804E6AC
	.align 2, 0
_0804E6A4: .4byte 0xfffffe20
_0804E6A8:
	movs r3, 0
	ldrsh r5, [r4, r3]
_0804E6AC:
	movs r4, 0x2
	ldrsh r1, [r6, r4]
	ldr r0, [sp, 0x38]
	movs r2, 0x6
	ldrsh r3, [r0, r2]
	subs r3, 0x1
	mov r4, r10
	str r4, [sp]
	ldr r2, [sp, 0x28]
	ldr r0, [r2]
	str r0, [sp, 0x4]
	ldr r4, [sp, 0x34]
	ldr r0, [r4]
	str r0, [sp, 0x8]
	ldr r0, [sp, 0x24]
	adds r2, r5, 0
	bl sub_804E328
	mov r5, r10
	strb r5, [r6, 0xB]
	strb r5, [r6, 0x13]
	ldr r0, [sp, 0x38]
	strb r5, [r0, 0x14]
	b _0804E874
_0804E6DC:
	ldr r0, [sp, 0x14]
	subs r0, 0x1
	ldr r1, [sp, 0x20]
	cmp r1, r0
	bge _0804E758
	mov r2, r9
	ldrb r0, [r2, 0x8]
	cmp r0, 0
	bne _0804E758
	ldrb r0, [r2, 0x12]
	cmp r0, 0
	bne _0804E758
	ldrb r0, [r2, 0xB]
	cmp r0, 0
	beq _0804E758
	ldrb r0, [r2, 0xA]
	cmp r0, 0
	beq _0804E724
	movs r3, 0x20
	ldrsh r0, [r6, r3]
	adds r0, 0x1
	movs r4, 0x24
	ldrsh r1, [r6, r4]
	subs r1, 0x1
	bl DungeonRandRange
	adds r5, r0, 0
	movs r1, 0x22
	ldrsh r0, [r6, r1]
	adds r0, 0x1
	movs r2, 0x26
	ldrsh r1, [r6, r2]
	subs r1, 0x1
	bl DungeonRandRange
	b _0804E728
_0804E724:
	movs r3, 0x20
	ldrsh r5, [r6, r3]
_0804E728:
	movs r4, 0x6
	ldrsh r1, [r6, r4]
	subs r1, 0x1
	movs r0, 0x22
	ldrsh r3, [r6, r0]
	mov r2, r10
	str r2, [sp]
	ldr r4, [sp, 0x28]
	ldr r0, [r4]
	str r0, [sp, 0x4]
	ldr r2, [sp, 0x34]
	ldr r0, [r2, 0x4]
	subs r0, 0x1
	str r0, [sp, 0x8]
	ldr r0, [sp, 0x24]
	adds r2, r5, 0
	bl sub_804E328
	mov r3, r10
	strb r3, [r6, 0xB]
	strb r3, [r6, 0x14]
	mov r4, r9
	strb r3, [r4, 0x13]
	b _0804E874
_0804E758:
	ldr r0, [sp, 0x1C]
	cmp r0, 0
	ble _0804E7C8
	ldrb r0, [r7, 0x8]
	cmp r0, 0
	bne _0804E7C8
	ldrb r0, [r7, 0x12]
	cmp r0, 0
	bne _0804E7C8
	ldrb r0, [r7, 0xB]
	cmp r0, 0
	beq _0804E7C8
	ldrb r0, [r7, 0xA]
	cmp r0, 0
	beq _0804E79A
	movs r1, 0
	ldrsh r0, [r7, r1]
	adds r0, 0x1
	movs r2, 0x4
	ldrsh r1, [r7, r2]
	subs r1, 0x1
	bl DungeonRandRange
	movs r3, 0x2
	ldrsh r0, [r7, r3]
	adds r0, 0x1
	movs r4, 0x6
	ldrsh r1, [r7, r4]
	subs r1, 0x1
	bl DungeonRandRange
	adds r3, r0, 0
	b _0804E79E
_0804E79A:
	movs r0, 0x2
	ldrsh r3, [r7, r0]
_0804E79E:
	movs r1, 0
	ldrsh r0, [r6, r1]
	movs r4, 0
	ldrsh r2, [r7, r4]
	subs r2, 0x1
	movs r1, 0
	str r1, [sp]
	ldr r4, [sp, 0x28]
	ldr r1, [r4]
	str r1, [sp, 0x4]
	ldr r4, [sp, 0x34]
	ldr r1, [r4]
	str r1, [sp, 0x8]
	adds r1, r5, 0
	bl sub_804E328
	mov r5, r10
	strb r5, [r6, 0xB]
	strb r5, [r6, 0x15]
	strb r5, [r7, 0x16]
	b _0804E874
_0804E7C8:
	ldr r0, [sp, 0x10]
	subs r0, 0x1
	ldr r1, [sp, 0x1C]
	cmp r1, r0
	bge _0804E874
	mov r2, r8
	ldrb r0, [r2, 0x8]
	cmp r0, 0
	bne _0804E874
	ldrb r0, [r2, 0x12]
	cmp r0, 0
	bne _0804E874
	ldrb r0, [r2, 0xB]
	cmp r0, 0
	beq _0804E874
	ldrb r0, [r2, 0xA]
	cmp r0, 0
	beq _0804E812
	movs r3, 0
	ldrsh r0, [r2, r3]
	adds r0, 0x1
	movs r4, 0x4
	ldrsh r1, [r2, r4]
	subs r1, 0x1
	bl DungeonRandRange
	mov r1, r8
	movs r2, 0x2
	ldrsh r0, [r1, r2]
	adds r0, 0x1
	movs r3, 0x6
	ldrsh r1, [r1, r3]
	subs r1, 0x1
	bl DungeonRandRange
	adds r3, r0, 0
	b _0804E818
_0804E812:
	mov r4, r8
	movs r0, 0x2
	ldrsh r3, [r4, r0]
_0804E818:
	movs r1, 0x4
	ldrsh r0, [r6, r1]
	subs r0, 0x1
	mov r4, r8
	movs r1, 0
	ldrsh r2, [r4, r1]
	movs r1, 0
	str r1, [sp]
	ldr r4, [sp, 0x28]
	ldr r1, [r4, 0x4]
	subs r1, 0x1
	str r1, [sp, 0x4]
	ldr r4, [sp, 0x34]
	ldr r1, [r4]
	str r1, [sp, 0x8]
	adds r1, r5, 0
	bl sub_804E328
	mov r5, r10
	strb r5, [r6, 0xB]
	strb r5, [r6, 0x16]
	mov r0, r8
	strb r5, [r0, 0x15]
	b _0804E874
_0804E848:
	movs r1, 0
	ldrsh r0, [r6, r1]
	movs r2, 0x2
	ldrsh r1, [r6, r2]
	bl GetTileSafe
	ldrh r1, [r0]
	ldr r3, _0804E99C
	adds r2, r3, 0
	ands r1, r2
	strh r1, [r0]
	ldrh r1, [r0, 0x4]
	ldr r4, _0804E9A0
	adds r2, r4, 0
	ands r1, r2
	ldr r5, _0804E9A4
	adds r2, r5, 0
	ands r1, r2
	subs r3, 0x1
	adds r2, r3, 0
	ands r1, r2
	strh r1, [r0, 0x4]
_0804E874:
	movs r4, 0x20
	add r8, r4
	adds r6, 0x20
	adds r7, 0x20
	add r9, r4
	ldr r5, [sp, 0x34]
	adds r5, 0x4
	str r5, [sp, 0x34]
	ldr r0, [sp, 0x38]
	adds r0, 0x20
	str r0, [sp, 0x38]
	ldr r1, [sp, 0x3C]
	adds r1, 0x20
	str r1, [sp, 0x3C]
	ldr r2, [sp, 0x20]
	adds r2, 0x1
	str r2, [sp, 0x20]
	ldr r3, [sp, 0x14]
	cmp r2, r3
	bge _0804E89E
	b _0804E604
_0804E89E:
	ldr r4, [sp, 0x2C]
	str r4, [sp, 0x1C]
	ldr r5, [sp, 0x10]
	cmp r4, r5
	bge _0804E8AA
	b _0804E5B2
_0804E8AA:
	movs r6, 0
	str r6, [sp, 0x1C]
	ldr r0, [sp, 0x10]
	cmp r6, r0
	bge _0804E98A
_0804E8B4:
	movs r1, 0
	str r1, [sp, 0x20]
	ldr r2, [sp, 0x1C]
	adds r2, 0x1
	str r2, [sp, 0x2C]
	ldr r3, [sp, 0x14]
	cmp r1, r3
	bge _0804E980
	ldr r4, [sp, 0x1C]
	lsls r4, 4
	mov r9, r4
_0804E8CA:
	ldr r5, [sp, 0x20]
	lsls r2, r5, 5
	ldr r6, [sp, 0x1C]
	lsls r3, r6, 4
	subs r0, r3, r6
	lsls r0, 5
	ldr r1, [sp, 0xC]
	adds r4, r0, r1
	adds r1, r2, r4
	ldrb r0, [r1, 0x8]
	mov r8, r2
	adds r5, 0x1
	str r5, [sp, 0x30]
	cmp r0, 0
	bne _0804E976
	ldrb r0, [r1, 0x11]
	cmp r0, 0
	bne _0804E976
	ldrb r0, [r1, 0xB]
	cmp r0, 0
	bne _0804E976
	ldrb r0, [r1, 0xF]
	cmp r0, 0
	bne _0804E976
	movs r6, 0
	ldrsh r5, [r1, r6]
	movs r6, 0x4
	ldrsh r0, [r1, r6]
	cmp r5, r0
	bge _0804E976
	mov r10, r4
_0804E908:
	ldr r1, [sp, 0x1C]
	subs r0, r3, r1
	lsls r0, 5
	ldr r3, [sp, 0xC]
	adds r0, r3
	adds r0, r2, r0
	movs r6, 0x2
	ldrsh r4, [r0, r6]
	movs r1, 0x6
	ldrsh r0, [r0, r1]
	adds r7, r5, 0x1
	cmp r4, r0
	bge _0804E95C
	mov r6, r8
	add r6, r10
_0804E926:
	adds r0, r5, 0
	adds r1, r4, 0
	bl GetTileSafe
	ldrh r2, [r0]
	ldr r3, _0804E99C
	adds r1, r3, 0
	ands r2, r1
	strh r2, [r0]
	ldrh r2, [r0, 0x4]
	adds r3, 0x1
	adds r1, r3, 0
	ands r2, r1
	adds r3, 0x1
	adds r1, r3, 0
	ands r2, r1
	subs r3, 0x3
	adds r1, r3, 0
	ands r2, r1
	strh r2, [r0, 0x4]
	movs r1, 0xFF
	strb r1, [r0, 0x9]
	adds r4, 0x1
	movs r1, 0x6
	ldrsh r0, [r6, r1]
	cmp r4, r0
	blt _0804E926
_0804E95C:
	adds r5, r7, 0
	mov r2, r8
	mov r3, r9
	ldr r4, [sp, 0x1C]
	subs r0, r3, r4
	lsls r0, 5
	ldr r6, [sp, 0xC]
	adds r0, r6
	adds r0, r2, r0
	movs r1, 0x4
	ldrsh r0, [r0, r1]
	cmp r5, r0
	blt _0804E908
_0804E976:
	ldr r2, [sp, 0x30]
	str r2, [sp, 0x20]
	ldr r3, [sp, 0x14]
	cmp r2, r3
	blt _0804E8CA
_0804E980:
	ldr r4, [sp, 0x2C]
	str r4, [sp, 0x1C]
	ldr r5, [sp, 0x10]
	cmp r4, r5
	blt _0804E8B4
_0804E98A:
	add sp, 0x40
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_0804E99C: .4byte 0x0000fffc
_0804E9A0: .4byte 0x0000fffe
_0804E9A4: .4byte 0x0000fffd
	thumb_func_end EnsureConnectedGrid

	thumb_func_start sub_804E9A8
sub_804E9A8:
	push {r4,r5,lr}
	adds r4, r0, 0
	lsls r1, 24
	lsls r2, 24
	lsrs r2, 24
	ldrh r0, [r4]
	ldr r5, _0804E9D8
	adds r3, r5, 0
	ands r3, r0
	strh r3, [r4]
	cmp r1, 0
	beq _0804E9D0
	ldrb r0, [r4, 0x9]
	cmp r0, r2
	bne _0804E9D0
	adds r0, r3, 0
	ands r0, r5
	movs r1, 0x2
	orrs r0, r1
	strh r0, [r4]
_0804E9D0:
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_0804E9D8: .4byte 0x0000fffc
	thumb_func_end sub_804E9A8

	thumb_func_start sub_804E9DC
sub_804E9DC:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	movs r5, 0
	movs r0, 0x3
	mov r8, r0
	movs r7, 0x8
	ldr r3, _0804EAF0
	mov r9, r3
_0804E9F2:
	movs r4, 0
	adds r6, r5, 0x1
	mov r10, r6
_0804E9F8:
	adds r0, r5, 0
	adds r1, r4, 0
	bl GetTile
	ldrh r1, [r0]
	mov r0, r8
	ands r0, r1
	adds r6, r4, 0x1
	cmp r0, 0x1
	beq _0804EA0E
	b _0804EB0E
_0804EA0E:
	adds r0, r5, 0
	adds r1, r4, 0
	bl GetTile
	ldrb r0, [r0, 0x9]
	cmp r0, 0xFF
	bne _0804EAF4
	cmp r5, 0
	ble _0804EA4E
	subs r0, r5, 0x1
	adds r1, r4, 0
	bl GetTileSafe
	adds r2, r0, 0
	ldrb r0, [r2, 0x9]
	cmp r0, 0xFF
	beq _0804EA4E
	ldrh r0, [r2]
	adds r1, r0, 0
	orrs r1, r7
	movs r3, 0
	strh r1, [r2]
	adds r0, r1, 0
	mov r6, r8
	ands r0, r6
	cmp r0, 0x2
	bne _0804EA4E
	mov r0, r9
	ands r1, r0
	movs r0, 0x1
	orrs r1, r0
	strh r1, [r2]
_0804EA4E:
	cmp r4, 0
	ble _0804EA82
	subs r1, r4, 0x1
	adds r0, r5, 0
	bl GetTileSafe
	adds r2, r0, 0
	ldrb r0, [r2, 0x9]
	cmp r0, 0xFF
	beq _0804EA82
	ldrh r0, [r2]
	adds r1, r0, 0
	orrs r1, r7
	movs r3, 0
	orrs r1, r7
	strh r1, [r2]
	adds r0, r1, 0
	mov r6, r8
	ands r0, r6
	cmp r0, 0x2
	bne _0804EA82
	mov r0, r9
	ands r1, r0
	movs r0, 0x1
	orrs r1, r0
	strh r1, [r2]
_0804EA82:
	adds r6, r4, 0x1
	cmp r4, 0x1E
	bgt _0804EABA
	adds r0, r5, 0
	adds r1, r6, 0
	bl GetTileSafe
	adds r2, r0, 0
	ldrb r0, [r2, 0x9]
	cmp r0, 0xFF
	beq _0804EABA
	ldrh r0, [r2]
	adds r1, r0, 0
	orrs r1, r7
	movs r3, 0
	mov r12, r3
	orrs r1, r7
	strh r1, [r2]
	adds r0, r1, 0
	mov r3, r8
	ands r0, r3
	cmp r0, 0x2
	bne _0804EABA
	mov r0, r9
	ands r1, r0
	movs r0, 0x1
	orrs r1, r0
	strh r1, [r2]
_0804EABA:
	cmp r5, 0x36
	bgt _0804EB0E
	mov r0, r10
	adds r1, r4, 0
	bl GetTileSafe
	adds r2, r0, 0
	ldrb r0, [r2, 0x9]
	cmp r0, 0xFF
	beq _0804EB0E
	ldrh r0, [r2]
	adds r1, r0, 0
	orrs r1, r7
	movs r3, 0
	orrs r1, r7
	strh r1, [r2]
	adds r0, r1, 0
	mov r4, r8
	ands r0, r4
	cmp r0, 0x2
	bne _0804EB0E
	mov r0, r9
	ands r1, r0
	movs r0, 0x1
	orrs r1, r0
	strh r1, [r2]
	b _0804EB0E
	.align 2, 0
_0804EAF0: .4byte 0x0000fffc
_0804EAF4:
	adds r0, r5, 0
	adds r1, r4, 0
	bl GetTile
	ldrb r0, [r0, 0x9]
	cmp r0, 0xFE
	bne _0804EB0E
	adds r0, r5, 0
	adds r1, r4, 0
	bl GetTileSafe
	movs r1, 0xFF
	strb r1, [r0, 0x9]
_0804EB0E:
	adds r4, r6, 0
	cmp r4, 0x1F
	bgt _0804EB16
	b _0804E9F8
_0804EB16:
	mov r5, r10
	cmp r5, 0x37
	bgt _0804EB1E
	b _0804E9F2
_0804EB1E:
	bl sub_804EB30
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_804E9DC

	thumb_func_start sub_804EB30
sub_804EB30:
	push {r4-r7,lr}
	ldr r0, _0804EBB4
	ldr r6, [r0]
	movs r2, 0
	movs r1, 0x1F
	ldr r3, _0804EBB8
	adds r0, r6, r3
_0804EB3E:
	strh r2, [r0]
	subs r0, 0x2
	subs r1, 0x1
	cmp r1, 0
	bge _0804EB3E
	movs r5, 0
_0804EB4A:
	movs r4, 0
	adds r7, r5, 0x1
_0804EB4E:
	adds r0, r5, 0
	adds r1, r4, 0
	bl GetTile
	ldrh r1, [r0]
	movs r0, 0x8
	ands r0, r1
	cmp r0, 0
	beq _0804EBA2
	adds r0, r5, 0
	adds r1, r4, 0
	bl GetTile
	ldrb r3, [r0, 0x9]
	cmp r3, 0x1F
	bhi _0804EBA2
	lsls r0, r3, 1
	ldr r2, _0804EBBC
	adds r1, r6, r2
	adds r2, r1, r0
	movs r1, 0
	ldrsh r0, [r2, r1]
	cmp r0, 0x1F
	bgt _0804EBA2
	lsls r0, 2
	lsls r1, r3, 7
	adds r0, r1
	adds r0, r6, r0
	ldr r3, _0804EBC0
	adds r0, r3
	strh r5, [r0]
	movs r3, 0
	ldrsh r0, [r2, r3]
	lsls r0, 2
	adds r0, r1
	adds r0, r6, r0
	ldr r1, _0804EBC4
	adds r0, r1
	strh r4, [r0]
	ldrh r0, [r2]
	adds r0, 0x1
	strh r0, [r2]
_0804EBA2:
	adds r4, 0x1
	cmp r4, 0x1F
	ble _0804EB4E
	adds r5, r7, 0
	cmp r5, 0x37
	ble _0804EB4A
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_0804EBB4: .4byte gDungeon
_0804EBB8: .4byte 0x00010882
_0804EBBC: .4byte 0x00010844
_0804EBC0: .4byte 0x00010884
_0804EBC4: .4byte 0x00010886
	thumb_func_end sub_804EB30

	thumb_func_start GenerateKecleonShop
GenerateKecleonShop:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x58
	str r0, [sp, 0x40]
	str r1, [sp, 0x44]
	mov r10, r2
	adds r4, r3, 0
	ldr r0, _0804EE90
	ldr r0, [r0]
	mov r8, r0
	ldr r1, _0804EE94
	ldr r0, _0804EE98
	strh r0, [r1]
	movs r0, 0x1
	negs r0, r0
	strh r0, [r1, 0x2]
	ldr r0, _0804EE9C
	ldrb r0, [r0]
	cmp r0, 0
	beq _0804EBF8
	b _0804EED4
_0804EBF8:
	bl sub_8043D10
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x2
	bne _0804EC06
	b _0804EED4
_0804EC06:
	cmp r4, 0
	bne _0804EC0C
	b _0804EED4
_0804EC0C:
	movs r0, 0x64
	bl DungeonRandInt
	cmp r4, r0
	bgt _0804EC18
	b _0804EED4
_0804EC18:
	movs r5, 0
	add r7, sp, 0x20
	adds r1, r7, 0
	mov r0, sp
_0804EC20:
	strh r5, [r0]
	strh r5, [r1]
	adds r1, 0x2
	adds r0, 0x2
	adds r5, 0x1
	cmp r5, 0xE
	ble _0804EC20
	movs r5, 0xC7
_0804EC30:
	movs r0, 0xF
	bl DungeonRandInt
	adds r4, r0, 0
	movs r0, 0xF
	bl DungeonRandInt
	lsls r4, 1
	mov r1, sp
	adds r2, r1, r4
	movs r4, 0
	ldrsh r3, [r2, r4]
	lsls r0, 1
	adds r1, r0
	ldrh r0, [r1]
	strh r0, [r2]
	strh r3, [r1]
	subs r5, 0x1
	cmp r5, 0
	bge _0804EC30
	adds r6, r7, 0
	movs r5, 0xC7
_0804EC5C:
	movs r0, 0xF
	bl DungeonRandInt
	adds r4, r0, 0
	movs r0, 0xF
	bl DungeonRandInt
	lsls r4, 1
	adds r4, r6, r4
	movs r1, 0
	ldrsh r2, [r4, r1]
	lsls r0, 1
	adds r0, r6, r0
	ldrh r1, [r0]
	strh r1, [r4]
	strh r2, [r0]
	subs r5, 0x1
	cmp r5, 0
	bge _0804EC5C
	movs r5, 0
_0804EC84:
	lsls r0, r5, 1
	add r0, sp
	movs r3, 0
	ldrsh r2, [r0, r3]
	mov r9, r2
	ldr r4, [sp, 0x44]
	cmp r9, r4
	blt _0804EC96
	b _0804EECC
_0804EC96:
	movs r4, 0
_0804EC98:
	lsls r0, r4, 1
	adds r0, r7, r0
	movs r2, 0
	ldrsh r1, [r0, r2]
	cmp r1, r10
	blt _0804ECA6
	b _0804EEC4
_0804ECA6:
	lsls r1, 5
	mov r3, r9
	lsls r2, r3, 4
	subs r0, r2, r3
	lsls r0, 5
	ldr r3, [sp, 0x40]
	adds r0, r3
	adds r3, r1, r0
	ldrb r0, [r3, 0x8]
	str r1, [sp, 0x4C]
	str r2, [sp, 0x48]
	cmp r0, 0
	beq _0804ECC2
	b _0804EEC4
_0804ECC2:
	ldrb r0, [r3, 0x11]
	cmp r0, 0
	beq _0804ECCA
	b _0804EEC4
_0804ECCA:
	ldrb r0, [r3, 0x12]
	cmp r0, 0
	beq _0804ECD2
	b _0804EEC4
_0804ECD2:
	ldrb r0, [r3, 0xB]
	cmp r0, 0
	bne _0804ECDA
	b _0804EEC4
_0804ECDA:
	ldrb r0, [r3, 0xA]
	cmp r0, 0
	bne _0804ECE2
	b _0804EEC4
_0804ECE2:
	ldrb r0, [r3, 0x9]
	cmp r0, 0
	beq _0804ECEA
	b _0804EEC4
_0804ECEA:
	ldrb r0, [r3, 0x10]
	cmp r0, 0
	beq _0804ECF2
	b _0804EEC4
_0804ECF2:
	ldrb r0, [r3, 0x1D]
	cmp r0, 0
	beq _0804ECFA
	b _0804EEC4
_0804ECFA:
	movs r0, 0x4
	ldrsh r1, [r3, r0]
	movs r2, 0
	ldrsh r0, [r3, r2]
	subs r1, r0
	cmp r1, 0
	bge _0804ED0A
	negs r1, r1
_0804ED0A:
	cmp r1, 0x4
	bgt _0804ED10
	b _0804EEC4
_0804ED10:
	movs r0, 0x6
	ldrsh r1, [r3, r0]
	movs r2, 0x2
	ldrsh r0, [r3, r2]
	subs r1, r0
	cmp r1, 0
	bge _0804ED20
	negs r1, r1
_0804ED20:
	cmp r1, 0x3
	bgt _0804ED26
	b _0804EEC4
_0804ED26:
	ldr r1, _0804EEA0
	movs r0, 0x1
	strb r0, [r1]
	movs r0, 0x1
	strb r0, [r3, 0xC]
	ldr r2, _0804EEA4
	movs r4, 0
	ldrsh r0, [r3, r4]
	adds r0, 0x1
	str r0, [r2]
	movs r7, 0x4
	ldrsh r0, [r3, r7]
	subs r0, 0x1
	str r0, [r2, 0x8]
	movs r0, 0x2
	ldrsh r1, [r3, r0]
	adds r1, 0x1
	str r1, [r2, 0x4]
	movs r4, 0x6
	ldrsh r3, [r3, r4]
	subs r0, r3, 0x1
	str r0, [r2, 0xC]
	subs r0, r1
	mov r10, r2
	cmp r0, 0x2
	bgt _0804ED5C
	str r3, [r2, 0xC]
_0804ED5C:
	ldr r0, _0804EEA8
	add r0, r8
	ldr r1, _0804EEAC
	str r1, [r0]
	ldr r0, _0804EEB0
	add r0, r8
	str r1, [r0]
	ldr r0, _0804EEB4
	add r0, r8
	ldr r1, _0804EEB8
	str r1, [r0]
	ldr r0, _0804EEBC
	add r0, r8
	str r1, [r0]
	mov r7, r10
	ldr r5, [r7]
	ldr r0, [r7, 0x8]
	cmp r5, r0
	bge _0804EDFA
	mov r3, r10
_0804ED84:
	ldr r4, [r3, 0x4]
	ldr r0, [r3, 0xC]
	adds r1, r5, 0x1
	str r1, [sp, 0x54]
	cmp r4, r0
	bge _0804EDF0
	ldr r6, _0804EEA8
	add r6, r8
	ldr r2, _0804EEA4
	mov r10, r2
_0804ED98:
	adds r0, r5, 0
	adds r1, r4, 0
	str r3, [sp, 0x50]
	bl GetTileSafe
	ldrh r2, [r0]
	movs r1, 0x20
	orrs r1, r2
	strh r1, [r0]
	ldrh r2, [r0, 0x4]
	ldr r7, _0804EEC0
	adds r1, r7, 0
	ands r2, r1
	adds r7, 0x7
	adds r1, r7, 0
	ands r2, r1
	strh r2, [r0, 0x4]
	ldr r0, [r6]
	ldr r3, [sp, 0x50]
	cmp r0, r5
	ble _0804EDC4
	str r5, [r6]
_0804EDC4:
	ldr r1, _0804EEB0
	add r1, r8
	ldr r0, [r1]
	cmp r0, r4
	ble _0804EDD0
	str r4, [r1]
_0804EDD0:
	ldr r1, _0804EEB4
	add r1, r8
	ldr r0, [r1]
	cmp r0, r5
	bge _0804EDDC
	str r5, [r1]
_0804EDDC:
	ldr r1, _0804EEBC
	add r1, r8
	ldr r0, [r1]
	cmp r0, r4
	bge _0804EDE8
	str r4, [r1]
_0804EDE8:
	adds r4, 0x1
	ldr r0, [r3, 0xC]
	cmp r4, r0
	blt _0804ED98
_0804EDF0:
	ldr r5, [sp, 0x54]
	mov r1, r10
	ldr r0, [r1, 0x8]
	cmp r5, r0
	blt _0804ED84
_0804EDFA:
	ldr r3, [sp, 0x4C]
	ldr r2, [sp, 0x48]
	mov r4, r9
	subs r0, r2, r4
	lsls r0, 5
	ldr r7, [sp, 0x40]
	adds r1, r0, r7
	adds r0, r3, r1
	movs r4, 0
	ldrsh r5, [r0, r4]
	movs r7, 0x4
	ldrsh r0, [r0, r7]
	cmp r5, r0
	bge _0804EE6C
	mov r8, r1
_0804EE18:
	mov r1, r9
	subs r0, r2, r1
	lsls r0, 5
	ldr r2, [sp, 0x40]
	adds r0, r2
	adds r0, r3, r0
	movs r3, 0x2
	ldrsh r4, [r0, r3]
	movs r7, 0x6
	ldrsh r0, [r0, r7]
	adds r1, r5, 0x1
	str r1, [sp, 0x54]
	cmp r4, r0
	bge _0804EE52
	ldr r6, [sp, 0x4C]
	add r6, r8
_0804EE38:
	adds r0, r5, 0
	adds r1, r4, 0
	bl GetTileSafe
	ldrh r2, [r0, 0x4]
	movs r1, 0x10
	orrs r1, r2
	strh r1, [r0, 0x4]
	adds r4, 0x1
	movs r2, 0x6
	ldrsh r0, [r6, r2]
	cmp r4, r0
	blt _0804EE38
_0804EE52:
	ldr r5, [sp, 0x54]
	ldr r3, [sp, 0x4C]
	ldr r2, [sp, 0x48]
	mov r4, r9
	subs r0, r2, r4
	lsls r0, 5
	ldr r7, [sp, 0x40]
	adds r0, r7
	adds r0, r3, r0
	movs r1, 0x4
	ldrsh r0, [r0, r1]
	cmp r5, r0
	blt _0804EE18
_0804EE6C:
	ldr r2, _0804EEA4
	ldr r0, [r2]
	ldr r1, [r2, 0x8]
	adds r0, r1
	lsrs r1, r0, 31
	adds r0, r1
	asrs r5, r0, 1
	ldr r0, [r2, 0x4]
	ldr r1, [r2, 0xC]
	adds r0, r1
	lsrs r1, r0, 31
	adds r0, r1
	asrs r4, r0, 1
	ldr r0, _0804EE94
	strh r5, [r0]
	strh r4, [r0, 0x2]
	b _0804EED4
	.align 2, 0
_0804EE90: .4byte gDungeon
_0804EE94: .4byte gUnknown_202F1D8
_0804EE98: .4byte 0x0000ffff
_0804EE9C: .4byte gUnknown_202F1AB
_0804EEA0: .4byte gUnknown_202F1AA
_0804EEA4: .4byte gUnknown_202F1B8
_0804EEA8: .4byte 0x0000e240
_0804EEAC: .4byte 0x0000270f
_0804EEB0: .4byte 0x0000e244
_0804EEB4: .4byte 0x0000e248
_0804EEB8: .4byte 0xffffd8f1
_0804EEBC: .4byte 0x0000e24c
_0804EEC0: .4byte 0x0000fff7
_0804EEC4:
	adds r4, 0x1
	cmp r4, 0xE
	bgt _0804EECC
	b _0804EC98
_0804EECC:
	adds r5, 0x1
	cmp r5, 0xE
	bgt _0804EED4
	b _0804EC84
_0804EED4:
	add sp, 0x58
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end GenerateKecleonShop

	thumb_func_start GenerateMonsterHouse
GenerateMonsterHouse:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x108
	str r0, [sp, 0x100]
	mov r8, r1
	adds r7, r2, 0
	adds r4, r3, 0
	ldr r5, _0804F094
	ldr r0, [r5]
	str r0, [sp, 0x104]
	cmp r4, 0
	bne _0804EF04
	b _0804F0C0
_0804EF04:
	movs r0, 0x64
	bl DungeonRandInt
	cmp r4, r0
	bgt _0804EF10
	b _0804F0C0
_0804EF10:
	ldr r0, _0804F098
	ldrb r0, [r0]
	cmp r0, 0
	beq _0804EF1A
	b _0804F0C0
_0804EF1A:
	ldr r0, [r5]
	movs r1, 0xD1
	lsls r1, 3
	adds r0, r1
	movs r2, 0
	ldrsh r0, [r0, r2]
	cmp r0, 0
	beq _0804EF2C
	b _0804F0C0
_0804EF2C:
	bl sub_8043D10
	lsls r0, 24
	cmp r0, 0
	beq _0804EF38
	b _0804F0C0
_0804EF38:
	movs r6, 0
	movs r1, 0
	cmp r1, r8
	bge _0804EF94
_0804EF40:
	adds r2, r1, 0x1
	cmp r7, 0
	ble _0804EF8E
	lsls r0, r1, 4
	subs r0, r1
	lsls r0, 5
	ldr r1, [sp, 0x100]
	adds r1, 0x8
	adds r1, r0, r1
	adds r3, r7, 0
_0804EF54:
	ldrb r0, [r1]
	cmp r0, 0
	bne _0804EF86
	ldrb r0, [r1, 0x9]
	cmp r0, 0
	bne _0804EF86
	ldrb r0, [r1, 0x3]
	cmp r0, 0
	beq _0804EF86
	ldrb r0, [r1, 0x2]
	cmp r0, 0
	beq _0804EF86
	ldrb r0, [r1, 0x4]
	cmp r0, 0
	bne _0804EF86
	ldrb r0, [r1, 0x7]
	cmp r0, 0
	bne _0804EF86
	ldrb r0, [r1, 0x8]
	cmp r0, 0
	bne _0804EF86
	ldrb r0, [r1, 0x1]
	cmp r0, 0
	bne _0804EF86
	adds r6, 0x1
_0804EF86:
	adds r1, 0x20
	subs r3, 0x1
	cmp r3, 0
	bne _0804EF54
_0804EF8E:
	adds r1, r2, 0
	cmp r1, r8
	blt _0804EF40
_0804EF94:
	cmp r6, 0
	bne _0804EF9A
	b _0804F0C0
_0804EF9A:
	movs r1, 0
	mov r0, sp
	adds r0, 0xFF
_0804EFA0:
	strb r1, [r0]
	subs r0, 0x1
	cmp r0, sp
	bge _0804EFA0
	mov r1, sp
	movs r0, 0x1
	strb r0, [r1]
	movs r5, 0x3F
_0804EFB0:
	adds r0, r6, 0
	bl DungeonRandInt
	adds r4, r0, 0
	adds r0, r6, 0
	bl DungeonRandInt
	mov r3, sp
	adds r2, r3, r4
	ldrb r3, [r2]
	mov r4, sp
	adds r1, r4, r0
	ldrb r0, [r1]
	strb r0, [r2]
	strb r3, [r1]
	subs r5, 0x1
	cmp r5, 0
	bge _0804EFB0
	movs r5, 0
	movs r1, 0
	cmp r1, r8
	bge _0804F0C0
	ldr r6, [sp, 0x100]
	mov r9, r6
	movs r4, 0
_0804EFE2:
	movs r3, 0
	cmp r3, r7
	bge _0804F0B2
	mov r10, r3
	lsls r0, r4, 5
	ldr r6, [sp, 0x100]
	adds r2, r0, r6
_0804EFF0:
	ldrb r0, [r2, 0x8]
	cmp r0, 0
	bne _0804F0A6
	ldrb r0, [r2, 0x11]
	cmp r0, 0
	bne _0804F0A6
	ldrb r0, [r2, 0xB]
	cmp r0, 0
	beq _0804F0A6
	ldrb r0, [r2, 0xA]
	cmp r0, 0
	beq _0804F0A6
	ldrb r0, [r2, 0xC]
	cmp r0, 0
	bne _0804F0A6
	ldrb r0, [r2, 0xF]
	cmp r0, 0
	bne _0804F0A6
	ldrb r0, [r2, 0x10]
	cmp r0, 0
	bne _0804F0A6
	ldrb r0, [r2, 0x9]
	cmp r0, 0
	bne _0804F0A6
	mov r6, sp
	adds r0, r6, r5
	ldrb r0, [r0]
	cmp r0, 0
	beq _0804F0A4
	ldr r1, _0804F09C
	movs r0, 0x1
	strb r0, [r1]
	movs r0, 0x1
	strb r0, [r2, 0xE]
	movs r0, 0
	ldrsh r5, [r2, r0]
	movs r1, 0x4
	ldrsh r0, [r2, r1]
	cmp r5, r0
	bge _0804F0C0
	mov r2, r10
	add r2, r9
	mov r8, r2
_0804F046:
	mov r1, r10
	add r1, r9
	movs r3, 0x2
	ldrsh r4, [r1, r3]
	movs r6, 0x6
	ldrsh r0, [r1, r6]
	adds r7, r5, 0x1
	cmp r4, r0
	bge _0804F086
	adds r6, r1, 0
_0804F05A:
	adds r0, r5, 0
	adds r1, r4, 0
	bl GetTileSafe
	ldrh r2, [r0]
	movs r1, 0x40
	orrs r1, r2
	strh r1, [r0]
	adds r0, r5, 0
	adds r1, r4, 0
	bl GetTile
	ldrb r1, [r0, 0x9]
	ldr r2, [sp, 0x104]
	ldr r3, _0804F0A0
	adds r0, r2, r3
	strb r1, [r0]
	adds r4, 0x1
	movs r1, 0x6
	ldrsh r0, [r6, r1]
	cmp r4, r0
	blt _0804F05A
_0804F086:
	adds r5, r7, 0
	mov r2, r8
	movs r3, 0x4
	ldrsh r0, [r2, r3]
	cmp r5, r0
	blt _0804F046
	b _0804F0C0
	.align 2, 0
_0804F094: .4byte gDungeon
_0804F098: .4byte gUnknown_202F1AA
_0804F09C: .4byte gUnknown_202F1AB
_0804F0A0: .4byte 0x00003a0c
_0804F0A4:
	adds r5, 0x1
_0804F0A6:
	movs r6, 0x20
	add r10, r6
	adds r2, 0x20
	adds r3, 0x1
	cmp r3, r7
	blt _0804EFF0
_0804F0B2:
	movs r0, 0xF0
	lsls r0, 1
	add r9, r0
	adds r4, 0xF
	adds r1, 0x1
	cmp r1, r8
	blt _0804EFE2
_0804F0C0:
	add sp, 0x108
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end GenerateMonsterHouse

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
	bl sub_804E9A8
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
	bl sub_804E9A8
	adds r5, 0x2
	b _0804F4BA
_0804F570:
	subs r1, r4, 0x1
	adds r0, r5, 0
	bl GetTileSafe
	mov r1, r9
	mov r3, r8
	lsrs r2, r3, 24
	bl sub_804E9A8
	subs r4, 0x2
	b _0804F4BA
_0804F586:
	subs r0, r5, 0x1
	adds r1, r4, 0
	bl GetTileSafe
	mov r1, r9
	mov r3, r8
	lsrs r2, r3, 24
	bl sub_804E9A8
	subs r5, 0x2
	b _0804F4BA
_0804F59C:
	adds r1, r4, 0x1
	adds r0, r5, 0
	bl GetTileSafe
	mov r1, r9
	mov r3, r8
	lsrs r2, r3, 24
	bl sub_804E9A8
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
